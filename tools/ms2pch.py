"""Opt-in precompiled header for the cl 19.16 game compiles (MS2_PCH=1).  See NOTES.md "build speed (bs1)".

The PCH holds only src/ms2/placeholder/ms2stdafx.h (afx.h + afxwin.h, ~60% of a small unit's c1xx time).  Units are
compiled with `/Yu /FI` so no source is edited.  Caveats (why it is opt-in): the PCH translation unit owns
header-defined globals (ATL _AtlComModule & co) and the anonymous-namespace hash (?A0x...) changes, so the unit .obj
loses the header-only COMDATs that the exe's unit ranges may include.  Units whose text before the stdafx include
is anything but `#define MS2_THIS_FILE` are compiled without the PCH.
"""
import hashlib
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ms2paths  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HDR = "ms2/placeholder/ms2stdafx.h"
DIR = os.path.join(ROOT, "build", "pch")
_ok = {}


def enabled():
    return os.environ.get("MS2_PCH") == "1"


def eligible(text):
    """True when the stdafx include is the first thing in the source (only comments / MS2_THIS_FILE before it)."""
    for line in text.splitlines():
        s = line.strip()
        if not s or s.startswith("//"):
            continue
        if re.match(r'#\s*define\s+MS2_THIS_FILE\b', s):
            continue
        return bool(re.match(r'#\s*include\s*"' + re.escape(HDR) + '"', s))
    return False


def args(flags, text, cl, env):
    """extra cl args for a unit whose source is `text` ([] = compile normally)"""
    if not enabled() or not eligible(text):
        return []
    key = hashlib.md5(" ".join(flags).encode()).hexdigest()[:10]
    pch = os.path.join(DIR, "ms2-%s.pch" % key)
    hdr = os.path.join(ROOT, "src", HDR)
    stamp = pch + ".ok"
    if _ok.get(pch) is None:
        os.makedirs(DIR, exist_ok=True)
        with ms2paths.file_lock(pch + ".lock"):
            if not (os.path.exists(stamp) and os.path.getmtime(stamp) >= os.path.getmtime(hdr)):
                stub = os.path.join(DIR, "ms2pch-%s.cpp" % key)
                open(stub, "w").write('#include "ms2pch.h"\n')
                open(os.path.join(DIR, "ms2pch.h"), "w").write('#include "%s"\n' % HDR)
                r = subprocess.run([cl] + flags + ["/I" + DIR, "/Yc" + "ms2pch.h", "/Fp" + pch,
                                                   "/Fo" + os.path.join(DIR, "ms2pch-%s.obj" % key), stub],
                                   capture_output=True, text=True, env=env, encoding="latin1", cwd=DIR)
                if r.returncode != 0 or not os.path.exists(pch):
                    return []
                open(stamp, "w").close()
        _ok[pch] = True
    return ["/I" + DIR, "/Yu" + "ms2pch.h", "/FIms2pch.h", "/Fp" + pch]
