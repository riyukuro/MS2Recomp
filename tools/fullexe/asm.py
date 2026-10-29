#!/usr/bin/env python3
"""Bring-your-own asm objs of the full-exe link: CryptoPP 5.6.2's x64 MASM sources (third_party/src/cryptopp562), with
ml64 under wine -> <OUT>/asm/*.obj (link.py takes every obj there).
  x64dll.asm   Baseline_Add/Sub, GCM_AuthenticateBlocks_2K/64K, Rijndael_Enc_AdvancedProcessBlocks, X86_SHA256_HashBlocks
  x64masm.asm  Salsa20_OperateKeystream, Panama_SSE2_Pull; Sosemanuk_OperateKeystream is left out (the exe has no
               sosemanuk.cpp, so nothing defines its s_sosemanukMulTables)
asm/ksamd64.inc stands in for the WDK include (the four prologue macros the sources use).
asm/hookglue.asm -> <OUT>/asm/hookglue.lib: the no-op ms2::hook::Register the game objs' MS2_REPLACE statics call, as a
lib member so the links without shim_runtime.obj resolve it and the closed link keeps that obj's copy."""
import os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, OUT, wine  # noqa: E402
import ms2paths  # noqa: E402

SRC = os.path.join(ms2paths.THIRD_PARTY, "src", "cryptopp562")
INC = os.path.join(os.path.dirname(os.path.abspath(__file__)), "asm")
UNITS = {"x64dll": (), "x64masm": ("Sosemanuk_OperateKeystream",)}


def prep(src, dst, drop):
    """src without the PROCs named in drop and the EXTERNs only they used"""
    lines = open(src, encoding="latin-1").read().split("\n")
    out, i = [], 0
    while i < len(lines):
        m = re.match(r"^\s*(\w+)\s+PROC\b", lines[i], re.I)
        if m and m.group(1) in drop:
            while not re.match(r"^\s*%s\s+ENDP\b" % m.group(1), lines[i], re.I):
                i += 1
        else:
            out.append(lines[i])
        i += 1
    text = "\n".join(out)
    out = [l for l in out if not (re.match(r"EXTERN(DEF)?\s", l) and text.count(l.split()[1].split(":")[0]) == 1)]
    open(dst, "w", encoding="latin-1").write("\n".join(out))


def main():
    d = os.path.join(OUT, "asm")
    os.makedirs(d, exist_ok=True)
    env = dict(os.environ, WINEPREFIX=ms2paths.WINEPREFIX, WINEDEBUG="-all")
    rc = 0
    for u, drop in UNITS.items():
        a = os.path.join(d, u + ".asm")
        prep(os.path.join(SRC, u + ".asm"), a, set(drop))
        r = subprocess.run([os.path.join(ms2paths.THIRD_PARTY, "msvc", "bin", "x64", "ml64"), "/nologo", "/c",
                            "/I", wine(INC), "/Fo" + wine(os.path.join(d, u + ".obj")), wine(a)],
                           env=env, cwd=ROOT, capture_output=True, text=True)
        print(u, "rc=%d" % r.returncode, (r.stdout + r.stderr).strip().splitlines()[-1:] if r.returncode else "")
        rc |= r.returncode
    tool = os.path.join(ms2paths.THIRD_PARTY, "msvc", "bin", "x64")
    g = os.path.join(d, "glue")
    os.makedirs(g, exist_ok=True)
    r = subprocess.run([os.path.join(tool, "ml64"), "/nologo", "/c", "/Fo" + wine(os.path.join(g, "hookglue.obj")),
                        wine(os.path.join(INC, "hookglue.asm"))], env=env, cwd=ROOT, capture_output=True, text=True)
    if not r.returncode:
        r = subprocess.run([os.path.join(tool, "lib"), "/nologo", "/machine:x64", "/out:" + wine(os.path.join(d, "hookglue.lib")),
                            wine(os.path.join(g, "hookglue.obj"))], env=env, cwd=ROOT, capture_output=True, text=True)
    print("hookglue", "rc=%d" % r.returncode, (r.stdout + r.stderr).strip().splitlines()[-1:] if r.returncode else "")
    rc |= r.returncode
    return rc


if __name__ == "__main__":
    sys.exit(main())
