#!/usr/bin/env python3
"""One full-exe MSVC link of the planned objs (order.tsv, plan.py) as a single heavy-lock job.
    link.py [--snapshot | --refresh] [--alias] [--order] [--shim] [--before FILE] [--force-multiple] [--max-held N]
  --snapshot   copy the planned objs to <OUT>/obj first (a stable snapshot while merges rebuild the tree; ~14 GB) and
               regenerate defsyms.tsv from it
  --refresh    re-copy only the snapshot objs whose planned obj differs by content (stale copies), then defsyms.tsv
  --alias      append alias.rsp (/alternatename lines of alias.py) and datapair-alias.rsp (datapair.py, names alias.rsp
               lacks), minus the stale lines aliasaudit.py finds
  --order      link with /ORDER:@order.txt (order.py)
  --shim       a closed link: <OUT>/shim/{stubs,shim_runtime}.obj (shim.py) + exe.res (rsrc.py), the Windows SDK um libs
               after the generated import libs, /entry:ms2_fullexe_entry (boot milestones), no /force:unresolved
  --before     static-init order fixes: lines `<unit A>\t<unit B>[\t# why]` move A's obj just before B's (objs' .CRT$XCU
               entries run in command-line order; for a cross-TU dependency the exe resolves by its own obj order)
  --force-multiple  link with /force:multiple (a duplicate definition keeps the first instead of failing: LNK2005);
               off by default since TAG 17, whose links had no duplicate
  Always: the asm objs and libs of asm.py (<OUT>/asm/*.obj, *.lib: hookglue.lib's ms2::hook::Register) and the SDK
  data libs (dinput8; the DirectX SDK's dxguid).
  --max-held   wait until at most N heavy slots are held before taking one (default 3: leave the gates a free slot)
Outputs: <OUT>/link<TAG>.rsp, link<TAG>.log, fullexe<TAG>.exe/.map (TAG: FULLEXE_TAG)."""
import argparse, collections, os, shutil, subprocess, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, OUT, TREE, copy_new, tagged, wine  # noqa: E402
import ms2paths  # noqa: E402

# DirectX SDK / Gamebryo renderer libs the objs name by #pragma comment(lib): supplied via --libpath or not needed here
NODEFAULT = ("D3DX9.lib", "D3DX10.lib", "D3DX11.lib", "D3DCompiler.lib", "NiDX9Renderer.lib")
# Windows SDK libs for what the generated import libs lack (exports the exe never imported)
SDK_LIBS = ("kernel32", "user32", "ws2_32", "shlwapi", "oleaut32", "shell32", "dsound")
# static data the objs need in every link: dinput8's c_dfDI* data formats; the DirectX SDK's dxguid (a superset of the
# Windows SDK one: the D3DX IIDs, IID_ID3DXEffect ...)
SDK_UM = os.path.join(ms2paths.THIRD_PARTY, "msvc", "Windows Kits", "10", "Lib", ms2paths.WINSDK_VERSION, "um", "x64")
LEGACY_STDIO = os.path.join(ms2paths.THIRD_PARTY, "msvc", "VC", "Tools", "MSVC", ms2paths.TOOLSET, "lib", "x64", "legacy_stdio_definitions.lib")
DATA_LIBS = (os.path.join(SDK_UM, "dinput8.lib"), os.path.join(ms2paths.THIRD_PARTY, "dxsdk", "DXSDK", "Lib", "x64", "dxguid.lib"))


def toolset_objs(objs):
    """the planned objs another toolset built (`// MS2-TOOLSET:`): tools/progress.py's .deps beside them starts with the key"""
    out = []
    for o in objs:
        try:
            with open(o[:-4] + ".deps", "rb") as f:
                if f.read(32).startswith(b'{"flags": " toolset='):
                    out.append(o)
        except OSError:
            pass
    return out


def held():
    t = subprocess.run(["lslocks", "-o", "PATH"], capture_output=True, text=True).stdout
    return sum(1 for l in t.splitlines() if "work/locks/heavy." in l)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--snapshot", action="store_true")
    ap.add_argument("--refresh", action="store_true")
    ap.add_argument("--alias", action="store_true")
    ap.add_argument("--order", action="store_true")
    ap.add_argument("--shim", action="store_true")
    ap.add_argument("--before")
    ap.add_argument("--force-multiple", action="store_true")
    ap.add_argument("--max-held", type=int, default=3)
    a = ap.parse_args()
    rows = [l.rstrip("\n").split("\t") for l in open(os.path.join(OUT, "order.tsv")) if l[0] != "#"]
    rules = [p for l in open(a.before) if len(p := l.split("#")[0].rstrip().split("\t")) >= 2] if a.before else []

    def before(items, unit):
        for x, y, *_ in rules:
            rest = [r for r in items if unit(r) != x]
            i = next((i for i, r in enumerate(rest) if unit(r) == y), None)
            if i is not None:       # a unit missing from the link: the rule does not apply
                items = rest[:i] + [r for r in items if unit(r) == x] + rest[i:]
        return items
    name2unit = collections.Counter(os.path.basename(r[3]) for r in rows)
    name2unit = {os.path.basename(r[3]): r[2] for r in rows if name2unit[os.path.basename(r[3])] == 1}
    rows = before(rows, lambda r: r[2])
    objs = [r[3] for r in rows]
    snap = os.path.join(OUT, "obj")
    if a.snapshot:
        shutil.rmtree(snap, ignore_errors=True)
        os.makedirs(snap)
        for i, o in enumerate(objs, 1):
            copy_new(o if os.path.isabs(o) else os.path.join(ROOT, o), os.path.join(snap, "%05d_%s" % (i, os.path.basename(o))))
        # defsyms.tsv (alias.py, classify.py, datapair.py) must describe this snapshot, not the one before it
        subprocess.run([sys.executable, "-P", os.path.join(os.path.dirname(os.path.abspath(__file__)), "defsyms.py")],
                       check=True, stdout=subprocess.DEVNULL)
    elif a.refresh:
        # re-copy the snapshot files whose planned obj differs in content (a stale copy: later links reuse the snapshot
        # without looking at its source); a plan that no longer matches the snapshot's numbering needs --snapshot
        if not os.path.isdir(snap):
            sys.exit(f"--refresh: no snapshot at {snap} (use --snapshot)")
        changed = 0
        for i, o in enumerate(objs, 1):
            src, dst = o if os.path.isabs(o) else os.path.join(ROOT, o), os.path.join(snap, "%05d_%s" % (i, os.path.basename(o)))
            if not os.path.exists(dst):
                sys.exit(f"--refresh: {os.path.basename(dst)} is not in the snapshot: order.tsv no longer matches it (use --snapshot)")
            if os.path.getsize(src) != os.path.getsize(dst) or open(src, "rb").read() != open(dst, "rb").read():
                copy_new(src, dst)
                changed += 1
        print(f"--refresh: {changed} of {len(objs)} snapshot obj(s) re-copied")
        if changed:
            subprocess.run([sys.executable, "-P", os.path.join(os.path.dirname(os.path.abspath(__file__)), "defsyms.py")],
                           check=True, stdout=subprocess.DEVNULL)
    if os.path.isdir(snap):
        # the snapshot keeps the obj order of the link that made it (and any obj placed in it by hand): apply the
        # --before moves to its files as well, or a snapshot made without them links the static initializers in plan
        # order (link 13s: 9 of 36 moves were lost)
        files = sorted(f for f in os.listdir(snap) if f.endswith(".obj"))
        objs = [os.path.join(snap, f) for f in before(files, lambda f: name2unit.get(f.split("_", 1)[1]))]
    rsp = ["/nologo /machine:x64 /subsystem:windows,6.0 /base:0x140000000 /dynamicbase:no "
           + ("/entry:ms2_fullexe_entry /manifest:no" if a.shim else "/entry:WinMainCRTStartup"),
           ("/force:multiple " if a.force_multiple else "") + ("" if a.shim else "/force:unresolved ") + "/opt:ref /opt:icf /debug:none " + " ".join("/nodefaultlib:" + l for l in NODEFAULT),
           '/out:"%s" /map:"%s"' % (wine(tagged("fullexe.exe")), wine(tagged("fullexe.map"))),
           '/libpath:"%s"' % wine(os.path.join(TREE, "build", "hook-msvc", "dxsdk-lib"))]
    imp = os.path.join(OUT, "implib")
    # import libs older than implibs.py (its EXTRA list grew) would leave those imports unresolved: rebuild them
    libs = [os.path.join(imp, f) for f in os.listdir(imp) if f.endswith(".lib")] if os.path.isdir(imp) else []
    gen = os.path.join(os.path.dirname(os.path.abspath(__file__)), "implibs.py")
    if not libs or min(map(os.path.getmtime, libs)) < os.path.getmtime(gen):
        print("implib: stale or missing, rerunning implibs.py --lib")
        subprocess.run([sys.executable, gen, "--lib"], check=True, stdout=subprocess.DEVNULL)
    rsp += ['"%s"' % wine(os.path.join(imp, f)) for f in sorted(os.listdir(imp)) if f.endswith(".lib")]
    rsp += ['"%s"' % wine(os.path.join(SDK_UM, l + ".lib")) for l in (SDK_LIBS if a.shim else ())]
    rsp += ['"%s"' % wine(l) for l in DATA_LIBS]
    # vc9 objs call the VS2008 CRT's printf family (_vsnprintf ...), which the UCRT keeps only in legacy_stdio_definitions;
    # a default build has no such obj and links exactly as before
    ts = toolset_objs([r[3] if os.path.isabs(r[3]) else os.path.join(ROOT, r[3]) for r in rows])
    if ts:
        print("link: %d toolset obj(s) (%s): + legacy_stdio_definitions.lib" % (len(ts), ", ".join(os.path.basename(o) for o in ts)))
        rsp.append('"%s"' % wine(LEGACY_STDIO))
    rsp += ['"%s"' % wine(o) for o in objs]
    asm = os.path.join(OUT, "asm")      # asm.py
    rsp += ['"%s"' % wine(os.path.join(asm, f)) for f in sorted(os.listdir(asm)) if f.endswith((".obj", ".lib"))] if os.path.isdir(asm) else []
    if a.shim:
        rsp += ['"%s"' % wine(os.path.join(OUT, "shim", f)) for f in ("shim_runtime.obj", "stubs.obj", "exe.res")]
    if a.alias:
        # aliasaudit.py: lines carried over from older runs whose target is gone or sits at another VA are dropped
        # (aliasdrop<TAG>.tsv), so a stale line cannot link an old definition
        import aliasaudit
        al = open(os.path.join(OUT, "alias.rsp"), encoding="latin1").read().splitlines()
        # datapair.py's data aliases (vftables, CryptoPP singleton statics alias.py cannot pair) for names alias.rsp lacks
        dp = os.path.join(OUT, "datapair-alias.rsp")
        if os.path.exists(dp):
            have = {m.group(1) for l in al if (m := aliasaudit.LINE.search(l))}
            al += [l for l in open(dp, encoding="latin1").read().splitlines() if (m := aliasaudit.LINE.search(l)) and m.group(1) not in have]
        kept, dropped = aliasaudit.audit(al)
        aliasaudit.write_report(dropped, tagged("aliasdrop.tsv"))
        if dropped:
            print("alias: %d stale lines dropped -> %s" % (len(dropped), tagged("aliasdrop.tsv")))
        rsp += kept
    if a.order:
        rsp.append('"/order:@%s"' % wine(os.path.join(OUT, "order.txt")))
    open(tagged("link.rsp"), "w").write("\n".join(rsp) + "\n")
    # under an outer heavy_lock (MS2_HEAVY_HELD) our own slot would count against --max-held and the inner
    # heavy_lock is a no-op anyway: link in the held slot
    while not os.environ.get("MS2_HEAVY_HELD") and held() > a.max_held:
        time.sleep(2)
    env = dict(os.environ, WINEPREFIX=ms2paths.WINEPREFIX, WINEDEBUG="-all")
    t0 = time.time()
    with open(tagged("link.log"), "w") as log:
        rc = subprocess.call([sys.executable, "-P", os.path.join(ROOT, "tools", "heavy_lock.py"), "--",
                              os.path.join(ms2paths.THIRD_PARTY, "msvc", "bin", "x64", "link"), "@" + wine(tagged("link.rsp"))],
                             stdout=log, stderr=subprocess.STDOUT, cwd=ROOT, env=env)
    print("link%s rc=%d %.0fs" % (os.environ.get("FULLEXE_TAG", ""), rc, time.time() - t0))
    return rc


if __name__ == "__main__":
    sys.exit(main())
