"""Build a 240x135 boot splash for the base's display: 1-3 round portraits side by side.

Usage:
  uvx --with pillow python make_splash.py OUT.png PHOTO:CX,CY,R [PHOTO:CX,CY,R ...] [--label "Text"]

  PHOTO   any image Pillow can read (jpg/png/webp)
  CX,CY,R circle to crop from the photo, in photo pixels (centre and radius), e.g. around a cat's face
  --label optional caption under the portraits (shrinks them a bit)
  --cutout no circle: show the crop as is, e.g. for artwork with the background removed
  --strip-bg remove a light, neutral background (white or a baked-in "transparency" checkerboard):
           flood-filled from the top edge, so it stops at the subject's outline and keeps white fur

Without photos it draws a generic splash (scale icon + "Feniska Base"). Point the ESPHome
substitution splash_file at the result (keep personal photos in a git-ignored *.local.png).
"""
import sys
from PIL import Image, ImageDraw, ImageFont

W, H = 240, 135
BG, RING, TEXT = (12, 14, 18), (230, 230, 230), (235, 235, 235)


def font(size):
    for name in ("DejaVuSans-Bold.ttf", "Arial Bold.ttf", "/System/Library/Fonts/Supplemental/Arial Bold.ttf",
                 "/System/Library/Fonts/Helvetica.ttc"):
        try:
            return ImageFont.truetype(name, size)
        except OSError:
            pass
    return ImageFont.load_default()


def strip_background(img):
    """Replace the light, low-saturation background connected to the top edge with BG."""
    work = img.resize((512, round(512 * img.height / img.width)), Image.BOX)
    w, h = work.size
    px = work.load()

    def bg_like(p):
        return min(p) > 185 and max(p) - min(p) < 20

    seen = bytearray(w * h)
    stack = [(x, 0) for x in range(w) if bg_like(px[x, 0])]
    while stack:
        x, y = stack.pop()
        i = y * w + x
        if seen[i] or not bg_like(px[x, y]):
            continue
        seen[i] = 1
        px[x, y] = BG
        for nx, ny in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
            if 0 <= nx < w and 0 <= ny < h and not seen[ny * w + nx]:
                stack.append((nx, ny))
    return work


def cutout(path, cx, cy, r, d, strip):
    src = Image.open(path).convert("RGB")
    crop = src.crop((cx - r, cy - r, cx + r, cy + r))
    if strip:
        crop = strip_background(crop)
    return crop.resize((d, d), Image.BOX)  # BOX keeps pixel art blocky


def portrait(path, cx, cy, r, d, strip=False):
    src = Image.open(path).convert("RGB")
    crop = src.crop((cx - r, cy - r, cx + r, cy + r))
    if strip:
        crop = strip_background(crop)
    crop = crop.resize((d * 4, d * 4), Image.LANCZOS)
    mask = Image.new("L", crop.size, 0)
    ImageDraw.Draw(mask).ellipse((0, 0, crop.size[0] - 1, crop.size[1] - 1), fill=255)
    tile = Image.new("RGB", crop.size, BG)
    tile.paste(crop, (0, 0), mask)
    ring = ImageDraw.Draw(tile)
    ring.ellipse((0, 0, crop.size[0] - 1, crop.size[1] - 1), outline=RING, width=8)
    return tile.resize((d, d), Image.LANCZOS)  # 4x supersampling for smooth edges


def main(argv):
    if not argv:
        sys.exit(__doc__)
    out, rest, label = argv[0], argv[1:], None
    if "--label" in rest:
        i = rest.index("--label"); label = rest[i + 1]; rest = rest[:i] + rest[i + 2:]
    is_cutout, strip = "--cutout" in rest, "--strip-bg" in rest
    rest = [a for a in rest if a not in ("--cutout", "--strip-bg")]
    img = Image.new("RGB", (W, H), BG)
    draw = ImageDraw.Draw(img)
    if not rest:  # generic splash
        draw.rounded_rectangle((70, 20, 170, 80), radius=12, outline=RING, width=3)
        draw.line((95, 62, 145, 62), fill=RING, width=3)
        draw.arc((100, 30, 140, 70), 200, 340, fill=RING, width=3)
        draw.line((120, 50, 132, 38), fill=RING, width=3)
        f = font(20); t = label or "Feniska Base"
        draw.text(((W - draw.textlength(t, font=f)) / 2, 95), t, font=f, fill=TEXT)
    else:
        n = len(rest)
        d = min(118 if not label else 100, (W - 10 * (n + 1)) // n)
        gap = (W - n * d) / (n + 1)
        top = (H - d) // 2 if not label else 6
        for k, spec in enumerate(rest):
            path, nums = spec.rsplit(":", 1)
            cx, cy, r = (int(v) for v in nums.split(","))
            tile = cutout(path, cx, cy, r, d, strip) if is_cutout else portrait(path, cx, cy, r, d, strip)
            img.paste(tile, (round(gap + k * (d + gap)), top))
        if label:
            f = font(18)
            draw.text(((W - draw.textlength(label, font=f)) / 2, top + d + 5), label, font=f, fill=TEXT)
    img.save(out)
    print(f"wrote {out} ({W}x{H})")


main(sys.argv[1:])
