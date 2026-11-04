#!/usr/bin/env python3
# Writes standin.ico, the stand-in's icon 2000 (16x16 and 32x32, 32 bpp). The image is drawn here, not taken from
# anywhere: a slate rounded square with an amber "MS2". rc.exe takes an ICON only from a file, so the .ico is
# committed (publish-github.sh lets cmake/fullexe-plain/standin/standin.ico through its resource-file check).
#   python3 cmake/fullexe-plain/standin/mkicon.py      (rewrites standin.ico next to this script)
import os
import struct

# 32x32: 5x5 glyphs at two pixels per cell, 26x10 in all, which centres exactly in 32.
GLYPHS32 = [["#...#",          # M
             "##.##",
             "#.#.#",
             "#...#",
             "#...#"],
            ["###",            # S
             "#..",
             "###",
             "..#",
             "###"],
            ["###",            # 2
             "..#",
             "###",
             "#..",
             "###"]]
# 16x16: an odd width or height cannot centre in 16, so the M is 6 wide and the glyphs 6 tall (14x6 in all, the
# whole inside of the outline).
GLYPHS16 = [["#....#",         # M
             "##..##",
             "#.##.#",
             "#....#",
             "#....#",
             "#....#"],
            ["###",            # S
             "#..",
             "###",
             "..#",
             "..#",
             "###"],
            ["###",            # 2
             "..#",
             "###",
             "#..",
             "#..",
             "###"]]
BG, FG, EDGE = (0x52, 0x44, 0x3a), (0x24, 0xa8, 0xf5), (0x36, 0x2c, 0x25)   # BGR


def text_mask(n):
    """The set of (x, y) covered by "MS2", centred: GLYPHS16 one pixel per cell, GLYPHS32 two."""
    glyphs, cell = (GLYPHS16, 1) if n == 16 else (GLYPHS32, 2)
    w = (sum(len(g[0]) for g in glyphs) + len(glyphs) - 1) * cell
    h = len(glyphs[0]) * cell
    x0, y0 = (n - w) // 2, (n - h) // 2
    on = set()
    for g in glyphs:
        for gy, row in enumerate(g):
            for gx, ch in enumerate(row):
                if ch == "#":
                    on.update((x0 + gx * cell + i, y0 + gy * cell + j) for i in range(cell) for j in range(cell))
        x0 += (len(g[0]) + 1) * cell
    return on


def inside(n, x, y):
    """Whether (x, y) is in the rounded square, corner radius n / 4."""
    if not (0 <= x < n and 0 <= y < n):
        return False
    rad = n // 4
    dx = max(rad - x, x - (n - 1 - rad), 0)
    dy = max(rad - y, y - (n - 1 - rad), 0)
    return (dx * dx + dy * dy) ** 0.5 <= rad


def pixels(n):
    """BGRA rows: the square with a one-pixel EDGE outline (any pixel with a 4-neighbour outside), BG inside."""
    text = text_mask(n)
    rows = []
    for y in range(n):
        row = []
        for x in range(n):
            if not inside(n, x, y):
                row.append((0, 0, 0, 0))
                continue
            edge = any(not inside(n, x + dx, y + dy) for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)))
            c = FG if (x, y) in text else EDGE if edge else BG
            row.append(c + (255,))
        rows.append(row)
    return rows


def icon(n):
    px = pixels(n)
    hdr = struct.pack("<IiiHHIIiiII", 40, n, 2 * n, 1, 32, 0, 0, 0, 0, 0, 0)
    xor = b"".join(bytes(p) for row in reversed(px) for p in row)     # bottom-up BGRA
    stride = (n + 31) // 32 * 4
    mask = b""
    for row in reversed(px):
        bits = 0
        for x, p in enumerate(row):
            if p[3] == 0:
                bits |= 1 << (stride * 8 - 1 - x)
        mask += bits.to_bytes(stride, "big")
    return hdr + xor + mask


def main():
    imgs = [icon(n) for n in (16, 32)]
    ico = struct.pack("<HHH", 0, 1, len(imgs))
    off = 6 + 16 * len(imgs)
    for n, d in zip((16, 32), imgs):
        ico += struct.pack("<BBBBHHII", n, n, 0, 0, 1, 32, len(d), off)
        off += len(d)
    p = os.path.join(os.path.dirname(os.path.abspath(__file__)), "standin.ico")
    with open(p, "wb") as f:
        f.write(ico + b"".join(imgs))
    print(p)


if __name__ == "__main__":
    main()
