//
// Copyright (C) 1993-1996 Id Software, Inc.
// Copyright (C) 2016-2017 Alexey Khokholov (Nuke.YKT)
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:  heads-up text and input code
//

#include <string.h>
#include <stdio.h>

#include <stdint.h>
#include <stddef.h>

static uint32_t utf8_peek(const unsigned char *p, size_t *len)
{
    uint32_t cp;
    size_t l, j;

    if (*p < 0x80) { cp = *p; l = 1; }
    else if ((*p & 0xE0) == 0xC0) { cp = *p & 0x1F; l = 2; }
    else if ((*p & 0xF0) == 0xE0) { cp = *p & 0x0F; l = 3; }
    else if ((*p & 0xF8) == 0xF0) { cp = *p & 0x07; l = 4; }
    else { *len = 1; return 0; }

    for (j = 1; j < l; j++) {
        if ((p[j] & 0xC0) != 0x80) { *len = 1; return 0; }
        cp = (cp << 6) | (p[j] & 0x3F);
    }

    *len = l;
    return cp;
}


#include "std_func.h"

#include "doomdef.h"

#include "v_video.h"

#include "hu_lib.h"
#include "r_local.h"
#include "r_draw.h"

#include "doomstat.h"

#include "options.h"
#include "hu_stuff.h"

// boolean : whether the screen is always erased
#define noterased viewwindowx

extern byte automapactive; // in AM_map.c

void HUlib_clearTextLine(hu_textline_t *t)
{
    t->len = 0;
    t->l[0] = 0;
    t->needsupdate = true;
}

void HUlib_initTextLine(hu_textline_t *t,
                        int x,
                        int y,
                        patch_t **f,
                        int sc)
{
    t->x = x;
    t->y = y;
    t->f = f;
    t->sc = sc;
    HUlib_clearTextLine(t);
}

void HUlib_addCharToTextLine(hu_textline_t *t, char ch)
{

    if (t->len == HU_MAXLINELENGTH)
        return;
    else
    {
        t->l[t->len++] = ch;
        t->l[t->len] = 0;
        t->needsupdate = 4;
        return;
    }
}

void HUlib_drawTextLine(hu_textline_t *l)
{
    int i = 0;
    int w;
    int x;
    uint32_t c;
    const unsigned char *p = (const unsigned char *)l->l;

#if defined(MODE_T4025) || defined(MODE_T4050)
    x = l->x / 8;
    while (*p && i < l->len)
    {
        size_t len;
        uint32_t cp = utf8_peek(p, &len);

        if (cp >= 0xF1900 && cp < 0xF19FF)
            c = HU_FONTSIZE + (cp % 256);
        else
            c = toupper(cp);

        V_WriteCharDirect(x, l->y / 8, c);
        x++;
        p += len;
        i++;
    }
#endif

#if defined(MODE_T8025) || defined(MODE_MDA) || defined(MODE_COLOR_MDA)
    x = l->x / 4;
    while (*p && i < l->len)
    {
        size_t len;
        uint32_t cp = utf8_peek(p, &len);

        if (cp >= 0xF1900 && cp < 0xF19FF)
            c = HU_FONTSIZE + (cp % 256);
        else
            c = toupper(cp);

        V_WriteCharDirect(x, l->y / 8, c);
        x++;
        p += len;
        i++;
    }
#endif

#if defined(MODE_T8043)
    x = l->x / 4;
    while (*p && i < l->len)
    {
        size_t len;
        uint32_t cp = utf8_peek(p, &len);

        if (cp >= 0xF1900 && cp < 0xF19FF)
            c = HU_FONTSIZE + (cp % 256);
        else
            c = toupper(cp);

        V_WriteCharDirect(x, l->y / 4, c);
        x++;
        p += len;
        i++;
    }
#endif

#if defined(MODE_T8050)
    x = l->x / 4;
    while (*p && i < l->len)
    {
        size_t len;
        uint32_t cp = utf8_peek(p, &len);

        if (cp >= 0xF1900 && cp < 0xF19FF)
            c = HU_FONTSIZE + (cp % 256);
        else
            c = toupper(cp);

        V_WriteCharDirect(x, l->y / 4, c);
        x++;
        p += len;
        i++;
    }
#endif

#if defined(MODE_X) || defined(MODE_Y) || defined(MODE_Y_HALF) || defined(USE_BACKBUFFER) || defined(MODE_VBE2_DIRECT)
    x = l->x;
    while (*p && i < l->len)
    {
        size_t len;
        uint32_t cp = utf8_peek(p, &len);

        if (cp >= 0xF1900 && cp < 0xF19FF)
            c = HU_FONTSIZE + (cp % 256);
        else
            c = toupper(cp) - l->sc;

        if (c >= 0 && c < TOTAL_FNTSZ)
        {
            w = l->f[c]->width;
            if (x + w > SCREENWIDTH)
                break;

            V_DrawPatchDirect(x, l->y, l->f[c]);
            x += w;
        }
        else
        {
            x += 4;
            if (x >= SCREENWIDTH)
                break;
        }

        p += len;
        i++;
    }
#endif
}


// sorta called by HU_Erase and just better darn get things straight
void HUlib_eraseTextLine(hu_textline_t *l)
{
    int lh;
    int y;
    int yoffset;

    // Only erases when NOT in automap and the screen is reduced,
    // and the text must either need updating or refreshing
    // (because of a recent change back from the automap)

#if defined(MODE_X) || defined(MODE_Y) || defined(MODE_Y_HALF) || defined(USE_BACKBUFFER) || defined(MODE_VBE2_DIRECT)

#ifdef SUPPORTS_HERCULES_AUTOMAP
    if ((!automapactive || (automapactive && HERCmap)) && viewwindowx && l->needsupdate)
#else
    if (!automapactive && viewwindowx && l->needsupdate)
#endif
    {
        // The text coordinates are in scaled pixels, so we need to
        // scale them back to normal pixels for the erase.
        lh = l->f[0]->height;
        for (y = l->y * PIXEL_SCALING, yoffset = MulScreenWidth(y); y < (l->y + lh) * PIXEL_SCALING; y++, yoffset += SCREENWIDTH)
        {
            if (y < viewwindowy || y >= (viewwindowy + viewheight)) {
                R_VideoErase(yoffset, SCREENWIDTH); // erase entire line
            }
            else
            {
                R_VideoErase(yoffset, viewwindowx);                           // erase left border
                R_VideoErase(yoffset + viewwindowx + viewwidth, viewwindowx); // erase right border
            }
        }

#if defined(USE_BACKBUFFER)
        updatestate |= I_MESSAGES;
#endif
    }
#endif

    l->needsupdate -= l->needsupdate != 0;
}

void HUlib_initSText(hu_stext_t *s,
                     int x,
                     int y,
                     int h,
                     patch_t **font,
                     int startchar,
                     byte *on)
{

    int i;

    s->h = h;
    s->on = on;
    s->laston = true;
    s->cl = 0;
    for (i = 0; i < h; i++)
        HUlib_initTextLine(&s->l[i],
                           x, y - i * (font[0]->height + 1),
                           font, startchar);
}

void HUlib_addLineToSText(hu_stext_t *s)
{

    int i;

    // add a clear line
    if (++s->cl == s->h)
        s->cl = 0;
    HUlib_clearTextLine(&s->l[s->cl]);

    // everything needs updating
    for (i = 0; i < s->h; i++)
        s->l[i].needsupdate = 4;
}

void HUlib_addMessageToSText(hu_stext_t *s,
                             char *prefix,
                             char *msg)
{
    HUlib_addLineToSText(s);
    if (prefix)
        while (*prefix)
            HUlib_addCharToTextLine(&s->l[s->cl], *(prefix++));

    while (*msg)
        HUlib_addCharToTextLine(&s->l[s->cl], *(msg++));
}

void HUlib_drawSText(hu_stext_t *s)
{
    int i, idx;
    hu_textline_t *l;

    if (!*s->on)
        return; // if not on, don't draw

    // draw everything
    for (i = 0; i < s->h; i++)
    {
        idx = s->cl - i;
        if (idx < 0)
            idx += s->h; // handle queue of lines

        l = &s->l[idx];

        // need a decision made here on whether to skip the draw
        HUlib_drawTextLine(l); // no cursor, please
    }

#if defined(USE_BACKBUFFER)
    updatestate |= I_MESSAGES;
#endif
}

void HUlib_eraseSText(hu_stext_t *s)
{

    int i;

    for (i = 0; i < s->h; i++)
    {
        if (s->laston && !*s->on)
            s->l[i].needsupdate = 4;
        HUlib_eraseTextLine(&s->l[i]);
    }
    s->laston = *s->on;
}
