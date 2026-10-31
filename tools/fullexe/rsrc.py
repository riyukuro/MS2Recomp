#!/usr/bin/env python3
"""The exe's resources (.rsrc: icons, dialogs, version, string tables, RT_MANIFEST) as a .res for the full-exe link.
    rsrc.py [--res <file.res>]
Writes <OUT>/shim/exe.res (a 32-bit .res file, read from the exe's resource tree; exe data: stays in work/). The link
takes it as an input with /manifest:no, since the manifest is resource 24/1 inside it. --res takes a compiled .res instead
(tools/extract_resources.py --compile: rc.exe on the extracted MapleStory2.rc; same entries) and copies it there."""
import os, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import OUT, EXE  # noqa: E402
import pefile  # noqa: E402


def name_or_id(e):
    if e.name is not None:
        return str(e.name).upper().encode("utf-16-le") + b"\0\0"
    return struct.pack("<HH", 0xFFFF, e.id)


def entry(typ, name, lang, data):
    hdr = typ + name
    if len(hdr) % 4:
        hdr += b"\0\0"
    hdr += struct.pack("<IHHII", 0, 0x1030, lang, 0, 0)      # DataVersion, MemoryFlags (moveable|pure|discardable), lang
    out = struct.pack("<II", len(data), 8 + len(hdr)) + hdr + data
    return out + b"\0" * (-len(out) % 4)


def main():
    if len(sys.argv) > 2 and sys.argv[1] == "--res":
        os.makedirs(os.path.join(OUT, "shim"), exist_ok=True)
        path = os.path.join(OUT, "shim", "exe.res")
        data = open(sys.argv[2], "rb").read()
        if data[:16] != struct.pack("<IIHHHH", 0, 32, 0xFFFF, 0, 0xFFFF, 0):    # the empty entry every .res starts with
            sys.exit("rsrc: %s is not a 32-bit .res file" % sys.argv[2])
        open(path, "wb").write(data)
        print("%s: copied from %s, %d bytes" % (path, sys.argv[2], len(data)))
        return
    pe = pefile.PE(EXE, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_RESOURCE"]])
    res = bytearray(entry(struct.pack("<HH", 0xFFFF, 0), struct.pack("<HH", 0xFFFF, 0), 0, b""))
    n = 0
    for t in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for nm in t.directory.entries:
            for lg in nm.directory.entries:
                d = lg.data.struct
                res += entry(name_or_id(t), name_or_id(nm), lg.id, pe.get_data(d.OffsetToData, d.Size))
                n += 1
    os.makedirs(os.path.join(OUT, "shim"), exist_ok=True)
    path = os.path.join(OUT, "shim", "exe.res")
    open(path, "wb").write(res)
    print("%s: %d resources, %d bytes" % (path, n, len(res)))


if __name__ == "__main__":
    main()
