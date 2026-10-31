#!/usr/bin/env python3
"""Extract MapleStory2.exe's resources as an .rc script plus one file per resource, for a plain Visual Studio build.

    python tools/extract_resources.py [path/to/MapleStory2.exe] [--out resources] [--any-exe]
    python tools/extract_resources.py --compile [--out resources]        rc.exe -> resources/MapleStory2.res
    python tools/extract_resources.py --compare a.res b.res               entry by entry: type, name, language, data

Default exe: $MS2_EXE, else "Game Versions/KMS2_DEV/x64/MapleStory2.exe" (tools/ms2paths.py); it must be the KMS2_DEV
build (SHA-256 of tools/check_exe.py, TimeDateStamp 0x62568C46) unless --any-exe. The output dir (default resources/ in
the checkout) is gitignored: the files are Nexon's, never commit or publish them.

  icons          RT_GROUP_ICON + its RT_ICON images -> a real .ico (`<id> ICON "x.ico"`; rc numbers the images itself)
  cursors        RT_GROUP_CURSOR + RT_CURSOR -> a real .cur (`<id> CURSOR "x.cur"`)
  bitmaps        a .bmp with its BITMAPFILEHEADER (`<id> BITMAP "x.bmp"`; rc strips the header again)
  manifest       `1 24 "x.manifest"`
  anything else  raw bytes, numeric type (`<id> <type> "x.bin"`): dialogs, string tables, menus, version info, ...
Each entry is preceded by its LANGUAGE. --compile runs the 14.16 toolchain's rc.exe (msvc-wine wrapper on Linux, the
vcvars rc on Windows); the result matches tools/fullexe/rsrc.py's exe.res entry for entry (--compare)."""
import argparse, hashlib, os, struct, subprocess, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import ms2paths  # noqa: E402

WANT_SHA = "1a3009453a6e7bc6c93c87c1dac139b440df74419c8320262721399f2f91d660"   # tools/check_exe.py
WANT_STAMP = 0x62568C46
RT = {1: "CURSOR", 2: "BITMAP", 3: "ICON", 4: "MENU", 5: "DIALOG", 6: "STRING", 7: "FONTDIR", 8: "FONT",
      9: "ACCELERATOR", 10: "RCDATA", 11: "MESSAGETABLE", 12: "GROUP_CURSOR", 14: "GROUP_ICON", 16: "VERSION",
      17: "DLGINCLUDE", 19: "PLUGPLAY", 20: "VXD", 21: "ANICURSOR", 22: "ANIICON", 23: "HTML", 24: "MANIFEST", 240: "DLGINIT"}


def resources(path):
    """[(type, name, lang, data)] in the exe's directory order; type/name are int ids or str names."""
    import pefile
    pe = pefile.PE(path, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_RESOURCE"]])
    out = []
    for t in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for nm in t.directory.entries:
            for lg in nm.directory.entries:
                d = lg.data.struct
                out.append((str(t.name) if t.name is not None else t.id, str(nm.name) if nm.name is not None else nm.id,
                            lg.id, pe.get_data(d.OffsetToData, d.Size)))
    return pe, out


def check(path, any_exe):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for blk in iter(lambda: f.read(1 << 20), b""):
            h.update(blk)
    with open(path, "rb") as f:
        mz = f.read(0x40)
        f.seek(struct.unpack_from("<I", mz, 0x3C)[0] + 8)
        stamp = struct.unpack("<I", f.read(4))[0]
    if h.hexdigest() != WANT_SHA or stamp != WANT_STAMP:
        msg = "extract_resources: %s is not the KMS2_DEV exe (sha256 %s, TimeDateStamp 0x%08X; want 0x%08X)" % (
            path, h.hexdigest(), stamp, WANT_STAMP)
        if not any_exe:
            sys.exit(msg + "; --any-exe extracts it anyway")
        print(msg + " (--any-exe: extracting anyway)", file=sys.stderr)


def rcname(x):
    if isinstance(x, int):
        return str(x)
    if all(c.isalnum() or c == "_" for c in x) and not x[0].isdigit():
        return x
    return '"%s"' % x.replace('"', '""')


def fname(x):
    return str(x) if isinstance(x, int) else "".join(c if c.isalnum() or c in "_-" else "_" for c in x)


def group_file(grp, images, cursor):
    """.ico/.cur from a GRPICONDIR/GRPCURSORDIR and its images: entries keep their order and fields; the file entry
    replaces the 2-byte image id with a 4-byte offset (cursors: the hotspot moves from the image into planes/bitcount)."""
    _, typ, n = struct.unpack_from("<HHH", grp, 0)
    ents, blobs = [], []
    for i in range(n):
        e = grp[6 + 14 * i:6 + 14 * (i + 1)]
        nid = struct.unpack_from("<H", e, 12)[0]
        img = images[nid]
        if cursor:
            w, h = struct.unpack_from("<HH", e, 0)
            hx, hy = struct.unpack_from("<HH", img, 0)
            img = img[4:]
            ent = struct.pack("<BBBBHH", w & 0xFF, (h // 2) & 0xFF, 0, 0, hx, hy)
        else:
            ent = e[:8]
        ents.append(ent)
        blobs.append(img)
    off = 6 + 16 * n
    out = bytearray(struct.pack("<HHH", 0, typ, n))
    for ent, img in zip(ents, blobs):
        out += ent + struct.pack("<II", len(img), off)
        off += len(img)
    for img in blobs:
        out += img
    return bytes(out)


def bmp_file(dib):
    size, = struct.unpack_from("<I", dib, 0)
    if size == 12:
        bits, used, comp = struct.unpack_from("<H", dib, 10)[0], 0, 0
        pal = 3
    else:
        bits, comp = struct.unpack_from("<HI", dib, 14)
        used = struct.unpack_from("<I", dib, 32)[0]
        pal = 4
    ncol = used or (1 << bits if bits <= 8 else 0)
    off = 14 + size + ncol * pal + (12 if size == 40 and comp == 3 else 0)
    return struct.pack("<2sIHHI", b"BM", 14 + len(dib), 0, 0, off) + dib


def rcstr(s):
    """an .rc string literal; control characters as \\x escapes of an L"" string"""
    body = s.replace("\\", "\\\\").replace('"', '""')
    if any(ord(c) < 32 or ord(c) == 0x7F for c in s):
        return 'L"%s"' % "".join("\\x%04X" % ord(c) if ord(c) < 32 or ord(c) == 0x7F else c for c in body)
    return '"%s"' % body


def _sz(b, q):
    """sz_Or_Ord at q -> (str | int, next offset)"""
    if struct.unpack_from("<H", b, q)[0] == 0xFFFF:
        return struct.unpack_from("<H", b, q + 2)[0], q + 4
    e = q
    while struct.unpack_from("<H", b, e)[0]:
        e += 2
    return b[q:e].decode("utf-16-le"), e + 2


MENU_OPTS = ((0x8, "CHECKED"), (0x1, "GRAYED"), (0x4000, "HELP"), (0x2, "INACTIVE"), (0x20, "MENUBARBREAK"),
             (0x40, "MENUBREAK"))


def menu_rc(name, b):
    """MENU text of a version-0 menu template, or None (MENUEX, unknown flags: kept raw)."""
    if struct.unpack_from("<HH", b, 0) != (0, 0):
        return None
    out = ["%s MENU" % name, "BEGIN"]
    q = 4

    def level(q, ind):
        while True:
            fl, = struct.unpack_from("<H", b, q)
            q += 2
            if fl & ~(0x10 | 0x80 | sum(f for f, _ in MENU_OPTS)):
                raise ValueError("menu flags 0x%x" % fl)
            iid = None
            if not fl & 0x10:
                iid, = struct.unpack_from("<H", b, q)
                q += 2
            e = q
            while struct.unpack_from("<H", b, e)[0]:
                e += 2
            text = b[q:e].decode("utf-16-le")
            q = e + 2
            opts = "".join(", " + k for f, k in MENU_OPTS if fl & f)
            if fl & 0x10:
                out.append("%sPOPUP %s%s" % (ind, rcstr(text), opts))
                out.append(ind + "BEGIN")
                q = level(q, ind + "    ")
                out.append(ind + "END")
            elif iid == 0 and not text and not fl & ~0x80:
                out.append(ind + "MENUITEM SEPARATOR")
            else:
                out.append("%sMENUITEM %s, %d%s" % (ind, rcstr(text), iid, opts))
            if fl & 0x80:
                return q
    try:
        q = level(q, "    ")
    except (ValueError, struct.error):
        return None
    if q != len(b):
        return None
    out.append("END")
    return out


CLASSES = {0x80: "Button", 0x81: "Edit", 0x82: "Static", 0x83: "ListBox", 0x84: "ScrollBar", 0x85: "ComboBox"}
VISCHILD = 0x50000000     # rc ORs WS_CHILD | WS_VISIBLE into every CONTROL style


def dialog_rc(name, b):
    """DIALOGEX text of an extended dialog template, or None (DIALOG, control data, ordinal titles: kept raw)."""
    try:
        if struct.unpack_from("<HH", b, 0) != (1, 0xFFFF):
            return None
        hid, exs, sty, n, x, y, cx, cy = struct.unpack_from("<IIIHhhhh", b, 4)
        menu, q = _sz(b, 26)
        cls, q = _sz(b, q)
        title, q = _sz(b, q)
        if not isinstance(title, str):
            return None
        out = ["%s DIALOGEX %d, %d, %d, %d%s" % (name, x, y, cx, cy, ", %d" % hid if hid else "")]
        out.append("STYLE 0x%08X" % sty)
        if exs:
            out.append("EXSTYLE 0x%08X" % exs)
        if title:
            out.append("CAPTION " + rcstr(title))
        if menu:
            out.append("MENU " + (str(menu) if isinstance(menu, int) else menu))
        if cls:
            out.append("CLASS " + (str(cls) if isinstance(cls, int) else rcstr(cls)))
        if sty & 0x40:
            pt, wt, it, cs = struct.unpack_from("<HHBB", b, q)
            face, q = _sz(b, q + 6)
            out.append("FONT %d, %s, %d, %d, 0x%X" % (pt, rcstr(face), wt, it, cs))
        out.append("BEGIN")
        for _ in range(n):
            q += -q % 4
            h, e, s, x, y, cx, cy, iid = struct.unpack_from("<IIIhhhhi", b, q)
            k, q = _sz(b, q + 24)
            t, q = _sz(b, q)
            extra, = struct.unpack_from("<H", b, q)
            q += 2
            if extra or not isinstance(t, str) or (isinstance(k, int) and k not in CLASSES):
                return None
            style = "0x%08X" % s if s & VISCHILD == VISCHILD else "0x%08X | NOT 0x%08X" % (s, VISCHILD & ~s)
            tail = (", 0x%08X" % e if e or h else "") + (", %d" % h if h else "")
            out.append("    CONTROL %s, %d, %s, %s, %d, %d, %d, %d%s" % (
                rcstr(t), iid, rcstr(CLASSES[k] if isinstance(k, int) else k), style, x, y, cx, cy, tail))
        if q != len(b) and b[q:].strip(b"\0"):
            return None
        out.append("END")
        return out
    except struct.error:
        return None


def version_rc(name, b):
    """VERSIONINFO text, or None."""
    def node(q):
        ln, vl, ty = struct.unpack_from("<HHH", b, q)
        key, p = _sz(b, q + 6)
        p += -(p - q) % 4
        val = b[p:p + (vl * 2 if ty == 1 else vl)]
        p += len(val)
        kids = []
        while True:
            p += -(p - q) % 4
            if p >= q + ln:
                break
            k, p = node(p)
            kids.append(k)
        return (key, ty, val, kids), q + ln
    try:
        (key, ty, ffi, kids), end = node(0)
        if key != "VS_VERSION_INFO" or len(ffi) != 52 or end != len(b):
            return None
        f = struct.unpack("<13I", ffi)
        if f[0] != 0xFEEF04BD or f[1] != 0x10000 or f[11] or f[12]:
            return None
        out = ["%s VERSIONINFO" % name,
               "FILEVERSION %d,%d,%d,%d" % (f[2] >> 16, f[2] & 0xFFFF, f[3] >> 16, f[3] & 0xFFFF),
               "PRODUCTVERSION %d,%d,%d,%d" % (f[4] >> 16, f[4] & 0xFFFF, f[5] >> 16, f[5] & 0xFFFF),
               "FILEFLAGSMASK 0x%XL" % f[6], "FILEFLAGS 0x%XL" % f[7], "FILEOS 0x%XL" % f[8],
               "FILETYPE 0x%XL" % f[9], "FILESUBTYPE 0x%XL" % f[10], "BEGIN"]

        def emit(n, ind):
            key, ty, val, kids = n
            if kids:
                if val:
                    raise ValueError
                out.append("%sBLOCK %s" % (ind, rcstr(key)))
                out.append(ind + "BEGIN")
                for k in kids:
                    emit(k, ind + "    ")
                out.append(ind + "END")
            elif ty == 1:
                s = val.decode("utf-16-le")
                if not s.endswith("\0") or "\0" in s[:-1]:
                    raise ValueError
                out.append("%sVALUE %s, %s" % (ind, rcstr(key), rcstr(s[:-1])))
            else:
                if len(val) % 2:
                    raise ValueError
                ws = struct.unpack("<%dH" % (len(val) // 2), val)
                out.append("%sVALUE %s, %s" % (ind, rcstr(key), ", ".join("0x%X" % w for w in ws)))
        for k in kids:
            emit(k, "    ")
        out.append("END")
        return out
    except (ValueError, struct.error, UnicodeDecodeError):
        return None


TEXT = {4: menu_rc, 5: dialog_rc, 16: version_rc}


def extract(exe, out):
    pe, res = resources(exe)
    os.makedirs(out, exist_ok=True)
    images = {}
    for t, n, lg, d in res:
        if t in (1, 3):
            images[(t, n, lg)] = d
    lines = ["// MapleStory2.exe resources, extracted by tools/extract_resources.py from the user's own exe.",
             "// Nexon's data: never commit or publish this directory.", ""]
    files = texts = 0
    for t, n, lg, d in res:
        if t in (1, 3):
            continue    # images: inside their group's .ico/.cur
        lines.append("LANGUAGE 0x%02X, 0x%02X" % (lg & 0x3FF, lg >> 10))
        stem = "%s_%s_%d" % (fname(RT.get(t, t)).lower(), fname(n), lg)
        if t in TEXT:
            text = TEXT[t](rcname(n), d)
            if text is None:
                # rc has no raw-file form for a predefined MENU/DIALOG/VERSIONINFO: such an entry needs the text form
                sys.exit("extract_resources: %s %s (lang %d): no exact .rc text form for this template" % (RT[t], n, lg))
            lines += text + [""]
            texts += 1
            continue
        if t in (12, 14):
            cursor = t == 12
            img = {k[1]: v for k, v in images.items() if k[0] == (1 if cursor else 3) and k[2] == lg}
            body, kw, ext = group_file(d, img, cursor), ("CURSOR" if cursor else "ICON"), (".cur" if cursor else ".ico")
        elif t == 2:
            body, kw, ext = bmp_file(d), "BITMAP", ".bmp"
        elif t == 24:
            body, kw, ext = d, "24", ".manifest"
        else:
            body, kw, ext = d, rcname(t), ".bin"
        with open(os.path.join(out, stem + ext), "wb") as f:
            f.write(body)
        files += 1
        lines.append('%s %s "%s"' % (rcname(n), kw, stem + ext))
        lines.append("")
    # UTF-16 (BOM) so the Korean captions and menu texts need no code page
    with open(os.path.join(out, "MapleStory2.rc"), "w", newline="\r\n", encoding="utf-16") as f:
        f.write("\n".join(lines))
    with open(os.path.join(out, ".gitignore"), "w") as f:
        f.write("# Nexon's resources extracted from the user's exe: never commit\n*\n")
    print("%s: %d resources -> %d files + %d text templates in MapleStory2.rc" % (out, len(res), files, texts))


def read_res(path):
    """[(type, name, lang, data)] of a 32-bit .res file, without the leading empty entry."""
    b = open(path, "rb").read()
    out, p = [], 0

    def sz(q):
        if struct.unpack_from("<H", b, q)[0] == 0xFFFF:
            return struct.unpack_from("<H", b, q + 2)[0], q + 4
        e = q
        while struct.unpack_from("<H", b, e)[0]:
            e += 2
        return b[q:e].decode("utf-16-le"), e + 2
    while p + 8 <= len(b):
        dsize, hsize = struct.unpack_from("<II", b, p)
        t, q = sz(p + 8)
        n, q = sz(q)
        q += -(q - p) % 4
        lang = struct.unpack_from("<H", b, q + 6)[0]
        data = b[p + hsize:p + hsize + dsize]
        if not (t == 0 and n == 0 and dsize == 0):
            out.append((t, n, lang, data))
        p += hsize + dsize
        p += -p % 4
    return out


def compare(a, b):
    ra, rb = read_res(a), read_res(b)
    ka = {(t, n, lg): d for t, n, lg, d in ra}
    kb = {(t, n, lg): d for t, n, lg, d in rb}
    bad = 0
    for k in sorted(set(ka) | set(kb), key=str):
        if k not in ka or k not in kb:
            print("ONLY in %s: type %s name %s lang %d" % (a if k in ka else b, *k)); bad += 1
        elif ka[k] != kb[k]:
            print("DIFF type %s name %s lang %d: %d vs %d bytes" % (*k, len(ka[k]), len(kb[k]))); bad += 1
    print("%s vs %s: %d / %d entries, %d differ" % (a, b, len(ka), len(kb), bad))
    return 1 if bad or len(ra) != len(ka) or len(rb) != len(kb) else 0


def compile_rc(out):
    """rc.exe from the 14.16 toolchain (Linux: the msvc-wine rc wrapper; Windows: rc on the vcvars PATH)."""
    env = ms2paths.toolchain_env()
    if ms2paths.is_nt():
        path = next((v for k, v in env.items() if k.upper() == "PATH"), "")
        import shutil
        rc = shutil.which("rc", path=path) or "rc"
    else:
        rc = os.path.join(ms2paths.THIRD_PARTY, "msvc", "bin", "x64", "rc")
    r = subprocess.run([rc, "/nologo", "/fo", "MapleStory2.res", "MapleStory2.rc"], cwd=out, env=env)
    if r.returncode:
        sys.exit("extract_resources: rc failed (%d)" % r.returncode)
    print(os.path.join(out, "MapleStory2.res"))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("exe", nargs="?", default=ms2paths.EXE)
    ap.add_argument("--out", default=os.path.join(ms2paths.ROOT, "resources"))
    ap.add_argument("--any-exe", action="store_true", help="extract from an exe that is not the KMS2_DEV build")
    ap.add_argument("--compile", action="store_true", help="run rc.exe on <out>/MapleStory2.rc")
    ap.add_argument("--compare", nargs=2, metavar="RES", help="compare two .res files entry by entry")
    a = ap.parse_args()
    if a.compare:
        return compare(*a.compare)
    if a.compile:
        return compile_rc(a.out)
    if not os.path.isfile(a.exe):
        sys.exit("extract_resources: not found: %s (set MS2_EXE or pass the path)" % a.exe)
    check(a.exe, a.any_exe)
    extract(a.exe, a.out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
