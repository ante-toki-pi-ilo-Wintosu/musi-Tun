import os
from PIL import Image, ImageDraw, ImageFont
from fontTools.ttLib import TTFont

# settings
FONT_PATH = "./fairfax/Fairfax.ttf"
OUTPUT_DIR = "./OUTPUT"
FONT_SIZE = 12
IMAGE_SIZE = (14, 14)
START_CODE = 0xF1900
END_CODE = 0xF19FF

def create_gradient_char(draw, char, font, pos):
    mask = Image.new('L', IMAGE_SIZE, 0)
    mask_draw = ImageDraw.Draw(mask)
    mask_draw.text(pos, char, font=font, fill=255)

    for y in range(IMAGE_SIZE[1]):
        color_val = int(255 - (y * (155 / IMAGE_SIZE[1])))
        color = (color_val, 0, 0)

        for x in range(IMAGE_SIZE[0]):
            if mask.getpixel((x, y)) > 0:
                draw.point((x, y), fill=color)

def process_font():
    if not os.path.exists(OUTPUT_DIR):
        os.makedirs(OUTPUT_DIR)

    try:
        font = ImageFont.truetype(FONT_PATH, FONT_SIZE)
    except IOError:
        print(f"Error: Could not find font at {FONT_PATH}")
        return

    print(f"Exporting characters to {OUTPUT_DIR}...")

    for i in range(256):
        current_code = START_CODE + i
        char = chr(current_code)
        
        img = Image.new('RGBA', IMAGE_SIZE, (0, 0, 0, 0))
        draw = ImageDraw.Draw(img)
        draw.text((1, 1), char, font=font, fill=(0, 0, 0, 255))
        create_gradient_char(draw, char, font, (0, 0))

        file_name = f"SP{i:03d}.png"
        img.save(os.path.join(OUTPUT_DIR, file_name))

    print("Success! All characters exported.")

if __name__ == "__main__":
    process_font()