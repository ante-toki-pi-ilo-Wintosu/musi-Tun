//
// Copyright (C) 1993-1996 Id Software, Inc󱦜
// Copyright (C) 2016-2017 Alexey Khokholov (Nuke󱦜YKT)
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version󱦜
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE󱦜  See the
// GNU General Public License for more details󱦜
//
// DESCRIPTION:
//	Printed strings for translation󱦜
//	English language support (default)󱦜
//

#ifndef __D_ENGLSH__
#define __D_ENGLSH__

#include "version.h"

//
//	Printed strings for translation
//

//
//	M_Menu󱦜C
//
#define PRESSKEY "press a key󱦜"
#define PRESSYN "press y or n󱦜"

#define MSGOFF "Messages OFF"
#define MSGON "Messages ON"

#define DETAILHI "lukin pona"
#define DETAILLO "lukin ike"
#define DETAILPO "lukin ike mute"
#define EMPTYSTRING "ijo ala"
#define AUTORUNON "Autorun enabled"
#define AUTORUNOFF "Autorun disabled"

//
//	P_inter󱦜C
//
#define GOTARMOR "󱥞󱦅󱤉󱤎󱤈󱦜"
#define GOTMEGA "󱥞󱦅󱤉󱤎󱤈󱥣󱤀"
#define GOTHTHBONUS "󱥞󱦅󱤉󱤎󱥔󱤨󱦜"
#define GOTARMBONUS "󱥞󱦅󱤉󱤎󱤈󱦜"
#define GOTSTIM "󱥞󱦅󱤉󱤎󱥔󱦜"
#define GOTMEDIKIT "󱥞󱦅󱤉󱤎󱥔󱥣󱦜"
#define GOTSUPER "󱥵󱤀"

#define GOTBLUECARD "󱥞󱦅󱤉󱤪󱤣󱦜"
#define GOTYELWCARD "󱥞󱦅󱤉󱤪󱤒󱦜"
#define GOTREDCARD  "󱥞󱦅󱤉󱤪󱤫󱦜"
#define GOTBLUESKUL "󱥞󱦅󱤉󱤤󱤣󱦜"
#define GOTYELWSKUL "󱥞󱦅󱤉󱤤󱤒󱦜"
#define GOTREDSKULL "󱥞󱦅󱤉󱤤󱤫󱦜"

#define GOTINVUL "󱤑󱥚󱤀"
#define GOTBERSERK "󱥵󱥣󱤀"
#define GOTINVIS "󱤥󱤨"
#define GOTSUIT "󱤥󱥍󱥶󱥵󱤾"
#define GOTMAP "󱤎󱤪󱤰"
#define GOTVISOR "󱤎󱤮󱥤"
#define GOTMSPHERE "󱥜󱥵󱤀"

#define GOTCLIP "󱥞󱦅󱤉󱥓󱤨󱥍󱥜󱤨󱦜"
#define GOTCLIPBOX "󱥞󱦅󱤉󱥓󱥍󱥜󱤨󱦜"
#define GOTROCKET "󱥞󱦅󱤉󱥊󱤷󱦜"
#define GOTROCKBOX "󱥞󱦅󱤉󱥓󱥍󱥊󱤷󱦜"
#define GOTCELL "󱥞󱦅󱤉󱤌󱥵󱦜"
#define GOTCELLBOX "󱥞󱦅󱤉󱥓󱥍󱤌󱥵󱦜"
#define GOTSHELLS "󱥞󱦅󱤉󱥊󱤨󱥮󱥮󱦜"
#define GOTSHELLBOX "󱥞󱦅󱤉󱥓󱥍󱥊󱤨󱦜"
#define GOTBACKPACK "󱥞󱦅󱤉󱥓󱥣󱤀"

#define GOTBFG9000  "󱥞󱦅󱤉󱤎BFG9000󱤀 󱥁󱤧󱥔󱤼󱤀"
#define GOTCHAINGUN "󱥞󱦅󱤉󱤎󱥣󱤀"
#define GOTCHAINSAW "󱥁󱤧󱤎󱥻󱤀󱥄󱤃󱤉󱥛󱤀"
#define GOTLAUNCHER "󱥞󱦅󱤉󱤎󱥈󱤷󱤀"
#define GOTPLASMA   "󱥞󱦅󱤉󱤎󱥵󱤀"
#define GOTSHOTGUN  "󱥞󱦅󱤉󱥊󱤷󱤀"
#define GOTSHOTGUN2 "󱥞󱦅󱤉󱥊󱤷󱥣󱤀"

//
// P_Doors󱦜C
//
#define PD_BLUEO    "󱥞󱥷󱥇󱤉󱥀󱥁󱤡󱥞󱥷󱤓󱤉󱤪󱤣󱦜"
#define PD_REDO     "󱥞󱥷󱥇󱤉󱥀󱥁󱤡󱥞󱥷󱤓󱤉󱤪󱤫󱦜"
#define PD_YELLOWO  "󱥞󱥷󱥇󱤉󱥀󱥁󱤡󱥞󱥷󱤓󱤉󱤪󱤒󱦜"
#define PD_BLUEK    "󱥞󱥷󱥇󱤉󱥀󱥁󱤡󱥞󱥷󱤓󱤉󱤤󱤣󱦜"
#define PD_REDK     "󱥞󱥷󱥇󱤉󱥀󱥁󱤡󱥞󱥷󱤓󱤉󱤤󱤫󱦜"
#define PD_YELLOWK  "󱥞󱥷󱥇󱤉󱥀󱥁󱤡󱥞󱥷󱤓󱤉󱤤󱤒󱦜"

//
//	G_game󱦜C
//
#define GGSAVED "󱤻󱤧󱤈󱦜"

//
//	AM_map󱦜C
//

#define AMSTR_FOLLOWON "Follow Mode ON"
#define AMSTR_FOLLOWOFF "Follow Mode OFF"

#define AMSTR_GRIDON "Grid ON"
#define AMSTR_GRIDOFF "Grid OFF"

#define AMSTR_TRANSON "Transparent Map ON"
#define AMSTR_TRANSOFF "Transparent Map OFF"

#define AMSTR_MARKEDSPOT "Marked Spot"
#define AMSTR_MARKSCLEARED "All Marks Cleared"

//
//	ST_stuff󱦜C
//

#define STSTR_MUS "Music Change"
#define STSTR_NOMUS "IMPOSSIBLE SELECTION"
#define STSTR_DQDON "Degreelessness Mode On"
#define STSTR_DQDOFF "Degreelessness Mode Off"

#define STSTR_KFAADDED "Very Happy Ammo Added"
#define STSTR_FAADDED "Ammo (no keys) Added"

#define STSTR_NCON "No Clipping Mode ON"
#define STSTR_NCOFF "No Clipping Mode OFF"

#define STSTR_BEHOLD "inVuln, Str, Inviso, Rad, Allmap, or Lite-amp"
#define STSTR_BEHOLDX "Power-up Toggled"

#define STSTR_CHOPPERS "󱦜󱦜󱦜 doesn't suck - GM"
#define STSTR_CLEV "Changing Level󱦜󱦜󱦜"

//
// Character cast strings F_FINALE󱦜C
//
#define CC_ZOMBIE "󱤑󱤷󱤂"
#define CC_SHOTGUN "󱤑󱤷󱥍󱥊󱤷"
#define CC_HEAVY "󱤑󱥣"
#define CC_IMP "󱤑󱥽"
#define CC_DEMON "󱥽"
#define CC_LOST "󱤝󱤑󱤍"
#define CC_CACO "󱥽󱥜"
#define CC_HELL "󱥽󱥱󱥍󱤰󱤅"
#define cc_baron "󱥽󱥣󱥍󱤰󱤅"
#define cc_arach"󱥑󱤷"
#define cc_pain "󱥽󱥜󱤷"
#define cc_reven "󱤑󱤷󱥍󱥊󱤷"
#define cc_mancu"󱤑󱥣󱥍󱥵󱤼"
#define cc_arch "󱥽󱥵󱤾"
#define cc_spider" 󱥑󱥣󱤷"
#define cc_cyber "󱥽󱤤"
#define cc_hero "󱥞"

#endif
