"""Where the gate tools find the files that are not in the repository. Every default is the in-tree location used by
the maintainer's checkout; an external checkout points the environment variables at its own copies:

  MS2_EXE          the original x64 MapleStory2.exe (KMS2_DEV build; tools/check-exe.sh verifies it)
  MS2_MAP_DIR      functions.tsv, units.tsv (exe-derived function/unit map; default work/map, else the published data/map)
  MS2_CLASSES_DIR  rtti_classes.tsv, rtti_vftables.tsv (tools/rtti_scan.py <exe> <dir>)
  MS2_THIRD_PARTY  MSVC 14.16 + Windows SDK (msvc-wine layout: bin/x64/cl, VC/, Windows Kits/), dxsdk/, physx*/
  MS2_ENGINE_DIR   Gamebryo 3.2.0.661 + engine patches (the directory that holds gamebryo/; stock source + engine-patches/, see CONTRIBUTING.md)
  MS2_WINEPREFIX   Wine prefix for the MSVC toolchain (MS2_MSVC_WINEPREFIX also accepted)
  MS2_SCALEFORM_SDK  Scaleform GFx 4.1.x SDK headers (the Scaleform/ directory)
Native Windows (no Wine; CONTRIBUTING.md "Windows"): the real VS2017 v141 cl.exe is used instead of the Wine wrappers.
  MS2_CL           full path of the 14.16 cl.exe (default: cl on PATH, else found through vswhere / the default install dirs)
  MS2_VCVARS       full path of vcvarsall.bat (default: found through vswhere / the default install dirs)
  MS2_VCVARS_VER   -vcvars_ver argument, default 14.16;  MS2_WINSDK_VER   SDK version argument, default 10.0.19041.0
Everything else a Windows contributor needs (compiler environment, paths of the MSVC/SDK trees, a lock, a symlink with a
copy fallback, the venv python) is a function here, so the gate tools contain no os.name checks of their own.
"""
import contextlib
import glob
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def _env(name, default):
    return os.environ.get(name) or default


EXE = _env("MS2_EXE", os.path.join(ROOT, "Game Versions", "KMS2_DEV", "x64", "MapleStory2.exe"))
# work/map is the maintainer's live copy; data/map is the published snapshot (tools/publish-github.sh syncs it)
_WORK_MAP = os.path.join(ROOT, "work", "map")
MAP_DIR = _env("MS2_MAP_DIR", _WORK_MAP if os.path.exists(os.path.join(_WORK_MAP, "functions.tsv")) else os.path.join(ROOT, "data", "map"))
CLASSES_DIR = _env("MS2_CLASSES_DIR", os.path.join(ROOT, "work", "classes"))
THIRD_PARTY = _env("MS2_THIRD_PARTY", os.path.join(ROOT, "third_party"))
ENGINE_DIR = _env("MS2_ENGINE_DIR", os.path.join(ROOT, "engine"))
WINEPREFIX = _env("MS2_WINEPREFIX", _env("MS2_MSVC_WINEPREFIX", os.path.join(ROOT, "work", "wineprefix-msvc")))
SCALEFORM_SDK = os.path.join(ROOT, "work", "scaleform", "4.1.19", "Scaleform")   # MS2_SCALEFORM_SDK read by progress.py
FUNCTIONS_TSV = os.path.join(MAP_DIR, "functions.tsv")
UNITS_TSV = os.path.join(MAP_DIR, "units.tsv")
RTTI_CLASSES = os.path.join(CLASSES_DIR, "rtti_classes.tsv")
RTTI_VFTABLES = os.path.join(CLASSES_DIR, "rtti_vftables.tsv")
CL = os.path.join(THIRD_PARTY, "msvc", "bin", "x64", "cl")

# ---------------------------------------------------------------------------------------------------------------------
# Host abstraction. On Linux every value below is exactly what the tools used before (msvc-wine layout under THIRD_PARTY,
# Wine environment variables); on native Windows (os.name == "nt") they come from the VS2017 v141 install.
# ---------------------------------------------------------------------------------------------------------------------
TOOLSET = "14.16.27023"
WINSDK_VERSION = "10.0.19041.0"


def is_nt():
    return os.name == "nt"


def _vs_installs():
    """Visual Studio installation roots, newest first (vswhere, then the default directories)."""
    out = []
    pf86 = os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)")
    vswhere = os.path.join(pf86, "Microsoft Visual Studio", "Installer", "vswhere.exe")
    if os.path.exists(vswhere):
        try:
            r = subprocess.run([vswhere, "-all", "-products", "*", "-property", "installationPath"],
                               capture_output=True, text=True)
            out += [l.strip() for l in r.stdout.splitlines() if l.strip()]
        except OSError:
            pass
    for pf in {os.environ.get("ProgramFiles", r"C:\Program Files"), pf86}:
        for ver in ("2017", "2019", "2022"):
            for ed in ("BuildTools", "Community", "Professional", "Enterprise"):
                out.append(os.path.join(pf, "Microsoft Visual Studio", ver, ed))
    seen, res = set(), []
    for d in out:
        if d.lower() not in seen and os.path.isdir(d):
            seen.add(d.lower())
            res.append(d)
    return res


def find_vcvars():
    """vcvarsall.bat of an install that has the 14.16 toolset (MS2_VCVARS overrides). None when there is none."""
    if os.environ.get("MS2_VCVARS"):
        return os.environ["MS2_VCVARS"]
    for d in _vs_installs():
        bat = os.path.join(d, "VC", "Auxiliary", "Build", "vcvarsall.bat")
        if os.path.exists(bat) and glob.glob(os.path.join(d, "VC", "Tools", "MSVC", "14.16.*")):
            return bat
    return None


def parse_set_output(text):
    """`cmd /c "... && set"` output -> dict (the variable names keep the case cmd printed)."""
    env = {}
    for line in text.splitlines():
        if "=" in line and not line.startswith("="):
            k, v = line.split("=", 1)
            env[k] = v
    return env


_nt_env = None


def toolchain_env(base=None):
    """Environment for cl/link/cmake/ninja/clang-cl subprocesses. Linux: `base` (default os.environ) plus the Wine prefix and
    WINEDEBUG=-all, exactly as the tools set them before. Native Windows: `base` overlaid with the vcvarsall.bat environment
    (x64, -vcvars_ver=14.16, SDK 10.0.19041.0) unless INCLUDE/LIB are already set (a Developer Command Prompt)."""
    global _nt_env
    env = dict(os.environ if base is None else base)
    if not is_nt():
        env.update(WINEPREFIX=WINEPREFIX, WINEDEBUG="-all")
        return env
    if _nt_env is None:
        if os.environ.get("INCLUDE") and os.environ.get("LIB") and shutil.which("cl", path=os.environ.get("PATH")):
            _nt_env = {}
        else:
            bat = find_vcvars()
            if not bat:
                sys.exit("ms2paths: no Visual Studio with the 14.16 (v141) toolset found; install it (CONTRIBUTING.md, Windows) "
                         "or run from a vcvars64 prompt, or set MS2_VCVARS")
            args = ["x64", "-vcvars_ver=" + os.environ.get("MS2_VCVARS_VER", "14.16")]
            if os.environ.get("MS2_WINSDK_VER", WINSDK_VERSION):
                args.append(os.environ.get("MS2_WINSDK_VER", WINSDK_VERSION))
            cmd = 'call "%s" %s >nul && set' % (bat, " ".join(args))
            r = subprocess.run(["cmd", "/d", "/c", cmd], capture_output=True, text=True, encoding="mbcs", errors="replace")
            _nt_env = parse_set_output(r.stdout)
            if "INCLUDE" not in {k.upper() for k in _nt_env}:
                sys.exit("ms2paths: vcvarsall.bat failed:\n" + r.stdout[-800:] + r.stderr[-800:])
    # Windows environment names are case-insensitive: replace, never duplicate (Path vs PATH)
    for k, v in _nt_env.items():
        for old in [o for o in env if o.upper() == k.upper()]:
            del env[old]
        env[k] = v
    return env


def find_cl(env=None):
    """Path of the cl the gates run. Linux: the msvc-wine cl under THIRD_PARTY (CL above). Native Windows: MS2_CL, else the cl on
    the toolchain_env() PATH."""
    if not is_nt():
        return CL
    if os.environ.get("MS2_CL"):
        return os.environ["MS2_CL"]
    env = env or toolchain_env()
    path = next((v for k, v in env.items() if k.upper() == "PATH"), "")
    return shutil.which("cl", path=path) or "cl"


def msvc_tools_dir(env=None):
    """VC/Tools/MSVC/<ver> of the 14.16 toolset (headers include/, atlmfc/include, atlmfc/lib/x64, lib/x64 below it)."""
    if not is_nt():
        return os.path.join(THIRD_PARTY, "msvc", "VC", "Tools", "MSVC", TOOLSET)
    env = env or toolchain_env()
    d = next((v for k, v in env.items() if k.upper() == "VCTOOLSINSTALLDIR"), "")
    if d:
        return d.rstrip("\\/")
    return ""


def winsdk_include(env=None):
    """Windows Kits/10/Include/<ver> directory."""
    if not is_nt():
        return os.path.join(THIRD_PARTY, "msvc", "Windows Kits", "10", "Include", WINSDK_VERSION)
    env = env or toolchain_env()
    e = {k.upper(): v for k, v in env.items()}
    root = e.get("WINDOWSSDKDIR") or os.path.join(os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)"),
                                                  "Windows Kits", "10")
    ver = (e.get("WINDOWSSDKVERSION") or WINSDK_VERSION + "\\").strip("\\/")
    return os.path.join(root, "Include", ver)


def python_exe():
    """The interpreter the build steps (cmake custom commands, subprocess scripts) use: the checkout's .venv, else this one."""
    for rel in (("bin", "python"), ("Scripts", "python.exe")):
        p = os.path.join(ROOT, ".venv", *rel)
        if os.path.exists(p):
            return p
    return sys.executable


@contextlib.contextmanager
def file_lock(path):
    """Exclusive inter-process lock on `path` (created if missing), held for the with-block. flock on POSIX, msvcrt on Windows."""
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    if not is_nt():
        import fcntl
        with open(path, "w") as lk:
            fcntl.flock(lk, fcntl.LOCK_EX)
            yield lk
        return
    import msvcrt
    import time
    with open(path, "a+b") as lk:
        while True:
            try:
                lk.seek(0)
                msvcrt.locking(lk.fileno(), msvcrt.LK_NBLCK, 1)
                break
            except OSError:
                time.sleep(0.05)
        try:
            yield lk
        finally:
            lk.seek(0)
            msvcrt.locking(lk.fileno(), msvcrt.LK_UNLCK, 1)


def link_or_copy(src, dst):
    """Symlink dst -> src; where symlinks are not allowed (Windows without privilege / developer mode) copy the file."""
    try:
        os.symlink(src, dst)
    except OSError:
        if not is_nt():
            raise
        shutil.copyfile(src, dst)


def host_path(p):
    """Path as printed by cl /showIncludes -> normalized host path (before any case repair). Wine reports z:\\... paths
    (lowercased in CodeView); native Windows reports drive paths as cl was given them."""
    import re
    p = p.strip()
    if not is_nt():
        if re.match(r"^[zZ]:", p):
            p = p[2:]
        p = p.replace("\\", "/")
    return os.path.normpath(p)


def under(path, top):
    """path is inside directory `top` (string prefix test; case-insensitive on Windows)."""
    return os.path.normcase(path).startswith(os.path.normcase(top))


def cl_cmdline(cmd):
    """cl command list; on Windows a command line over the CreateProcess limit moves the flags into an @response file."""
    if not is_nt() or sum(len(a) + 1 for a in cmd) < 30000:
        return cmd
    import hashlib
    import tempfile
    body = "\n".join('"%s"' % a.replace('"', '\\"') for a in cmd[1:])
    rsp = os.path.join(tempfile.gettempdir(), "ms2cl-%s.rsp" % hashlib.md5(body.encode()).hexdigest()[:12])
    with open(rsp, "w") as f:
        f.write(body)
    return [cmd[0], "@" + rsp]


def undname(text):
    """llvm-undname over `text` (one mangled name per line) -> its stdout with '\n' line ends. Pipes are binary so that Windows does
    not turn the '\n' separators into '\r\n' (llvm-undname would keep the '\r' in the name)."""
    p = subprocess.run(["llvm-undname"], input=text.encode("latin-1"), capture_output=True)
    return p.stdout.decode("latin-1").replace("\r\n", "\n")


def install_text_defaults():
    """Native Windows: make text-mode open() behave as on Linux (UTF-8, '\\n' written as '\\n'), so the TSV/JSON the gates read
    and write are byte-identical to the Linux ones instead of cp1252 / CRLF. Idempotent; a no-op elsewhere."""
    import builtins
    if getattr(builtins.open, "_ms2_text_defaults", False):
        return
    real = builtins.open

    def ms2_open(file, mode="r", buffering=-1, encoding=None, errors=None, newline=None, *a, **k):
        if "b" not in mode:
            encoding = encoding or "utf-8"
            if newline is None and any(c in mode for c in "wax+"):
                newline = "\n"
        return real(file, mode, buffering, encoding, errors, newline, *a, **k)
    ms2_open._ms2_text_defaults = True
    builtins.open = ms2_open


if is_nt():
    install_text_defaults()


def _main(argv):
    """python tools/ms2paths.py show | shell | run <command...>: print the resolved toolchain, open a shell in it, or run one command
    in it (native Windows: the vcvars environment, so cmake/ninja/clang-cl find the 14.16 toolset without a Developer prompt)."""
    cmd = argv[0] if argv else "show"
    if cmd == "show":
        env = toolchain_env()
        print("host        %s" % ("native Windows" if is_nt() else "Linux (Wine)"))
        print("cl          %s" % find_cl(env))
        print("toolset     %s" % msvc_tools_dir(env))
        print("sdk include %s" % winsdk_include(env))
        print("python      %s" % python_exe())
        for k in ("EXE", "MAP_DIR", "CLASSES_DIR", "THIRD_PARTY", "ENGINE_DIR"):
            print("%-11s %s" % (k.lower(), globals()[k]))
        return 0
    if cmd == "shell":
        sh = [os.environ.get("COMSPEC", "cmd"), "/k"] if is_nt() else [os.environ.get("SHELL", "sh")]
        return subprocess.call(sh, env=toolchain_env())
    if cmd == "run" and len(argv) > 1:
        return subprocess.call(argv[1:], env=toolchain_env())
    print(_main.__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(_main(sys.argv[1:]))
