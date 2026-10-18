"""Unit tests for the native-Windows code paths of the gate tools (tools/ms2paths.py, check_toolchain.py, check_exe.py,
unit_check.py, check-include-case.py). They run on any host: the nt branches are forced by patching ms2paths.is_nt and by
faking the Windows-only pieces (msvcrt, vcvarsall.bat output). What cannot be faked (a real cl.exe / vcvarsall.bat run) is
listed in work/pub4/report.md.

    python -m unittest discover -s tools/tests -v
"""
import builtins
import hashlib
import importlib.util
import os
import sys
import tempfile
import types
import unittest
from unittest import mock

TOOLS = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, TOOLS)
import ms2paths  # noqa: E402
import check_exe  # noqa: E402
import check_toolchain  # noqa: E402

FAKE_SET = "\r\n".join([
    "Path=C:\\VS\\VC\\Tools\\MSVC\\14.16.27023\\bin\\Hostx64\\x64;C:\\Windows",
    "INCLUDE=C:\\VS\\VC\\Tools\\MSVC\\14.16.27023\\include",
    "LIB=C:\\VS\\VC\\Tools\\MSVC\\14.16.27023\\lib\\x64",
    "VCToolsInstallDir=C:\\VS\\VC\\Tools\\MSVC\\14.16.27023\\",
    "WindowsSdkDir=C:\\Program Files (x86)\\Windows Kits\\10\\",
    "WindowsSDKVersion=10.0.19041.0\\",
    "=C:=C:\\work",
])


class FakeNt(unittest.TestCase):
    def setUp(self):
        ms2paths._nt_env = None
        self.p = [mock.patch.object(ms2paths, "is_nt", lambda: True),
                  mock.patch.object(ms2paths, "find_vcvars", lambda: "C:\\VS\\VC\\Auxiliary\\Build\\vcvarsall.bat"),
                  mock.patch.dict(os.environ, {"PATH": "/usr/bin", "INCLUDE": "", "LIB": ""})]
        for x in self.p:
            x.start()

    def tearDown(self):
        for x in self.p:
            x.stop()
        ms2paths._nt_env = None

    def fake_run(self, calls):
        def run(cmd, **kw):
            calls.append(cmd)
            return types.SimpleNamespace(stdout=FAKE_SET, stderr="", returncode=0)
        return mock.patch.object(ms2paths.subprocess, "run", run)

    def test_parse_set_output_skips_drive_cwd_entries(self):
        env = ms2paths.parse_set_output(FAKE_SET)
        self.assertEqual(env["INCLUDE"], "C:\\VS\\VC\\Tools\\MSVC\\14.16.27023\\include")
        self.assertNotIn("=C:", env)
        self.assertEqual(len(env), 6)

    def test_toolchain_env_runs_vcvars_once_and_replaces_path_case_insensitively(self):
        calls = []
        with self.fake_run(calls):
            e1 = ms2paths.toolchain_env({"PATH": "/x", "FOO": "1"})
            e2 = ms2paths.toolchain_env({"PATH": "/y"})
        self.assertEqual(len(calls), 1)
        cmd = calls[0][-1]
        self.assertIn("vcvarsall.bat", cmd)
        self.assertIn("x64 -vcvars_ver=14.16 10.0.19041.0", cmd)
        self.assertEqual([k for k in e1 if k.upper() == "PATH"], ["Path"])      # not duplicated
        self.assertTrue(e1["Path"].startswith("C:\\VS"))
        self.assertEqual(e1["FOO"], "1")
        self.assertIn("INCLUDE", e2)

    def test_prepared_environment_is_used_as_is(self):
        with mock.patch.dict(os.environ, {"INCLUDE": "a", "LIB": "b"}), \
                mock.patch.object(ms2paths.shutil, "which", lambda *a, **k: "C:\\cl.exe"):
            calls = []
            with self.fake_run(calls):
                ms2paths.toolchain_env()
            self.assertEqual(calls, [])

    def test_toolset_and_sdk_dirs_come_from_the_vcvars_environment(self):
        with self.fake_run([]):
            env = ms2paths.toolchain_env()
            self.assertEqual(ms2paths.msvc_tools_dir(env), "C:\\VS\\VC\\Tools\\MSVC\\14.16.27023")
            sdk = ms2paths.winsdk_include(env)
        self.assertTrue(sdk.replace("\\", "/").endswith("Windows Kits/10//Include/10.0.19041.0") or sdk.endswith("Include\\10.0.19041.0"), sdk)

    def test_find_cl_honours_ms2_cl(self):
        with mock.patch.dict(os.environ, {"MS2_CL": "D:\\cl.exe"}):
            self.assertEqual(ms2paths.find_cl(), "D:\\cl.exe")

    def test_python_exe_and_text_defaults_dont_crash(self):
        self.assertTrue(ms2paths.python_exe())

    def test_link_or_copy_falls_back_to_copy_when_symlinks_are_refused(self):
        with tempfile.TemporaryDirectory() as d:
            src, dst = os.path.join(d, "a.h"), os.path.join(d, "b.h")
            open(src, "wb").write(b"x")
            with mock.patch.object(ms2paths.os, "symlink", side_effect=OSError("privilege")):
                ms2paths.link_or_copy(src, dst)
            self.assertFalse(os.path.islink(dst))
            self.assertEqual(open(dst, "rb").read(), b"x")

    def test_cl_cmdline_moves_long_command_lines_into_a_response_file(self):
        short = ["cl", "/c", "a.cpp"]
        self.assertEqual(ms2paths.cl_cmdline(short), short)
        long = ["cl"] + ["/I" + "x" * 90 + str(i) for i in range(400)] + ["a b.cpp"]
        out = ms2paths.cl_cmdline(long)
        self.assertEqual(out[0], "cl")
        self.assertEqual(len(out), 2)
        body = open(out[1][1:]).read().splitlines()
        self.assertEqual(len(body), 401)
        self.assertEqual(body[-1], '"a b.cpp"')
        os.remove(out[1][1:])

    def test_host_path_keeps_drive_paths(self):
        with mock.patch.object(ms2paths.os.path, "normpath", lambda p: p):
            self.assertEqual(ms2paths.host_path("  C:\\a\\b.h \n"), "C:\\a\\b.h")

    def test_under_is_case_insensitive_only_where_the_filesystem_is(self):
        self.assertTrue(ms2paths.under("/a/b/c", "/a/b"))
        self.assertFalse(ms2paths.under("/a/x/c", "/a/b"))

    def test_windows_file_lock_uses_msvcrt_and_releases(self):
        calls = []
        fake = types.SimpleNamespace(LK_NBLCK=2, LK_UNLCK=0, locking=lambda fd, mode, n: calls.append((mode, n)))
        # first attempt fails (lock held elsewhere), second succeeds
        state = {"n": 0}

        def locking(fd, mode, n):
            calls.append((mode, n))
            if mode == 2 and state["n"] == 0:
                state["n"] = 1
                raise OSError("locked")
        fake.locking = locking
        with tempfile.TemporaryDirectory() as d, mock.patch.dict(sys.modules, {"msvcrt": fake}), \
                mock.patch("time.sleep", lambda s: None):
            with ms2paths.file_lock(os.path.join(d, "sub", "q.lock")):
                self.assertTrue(os.path.exists(os.path.join(d, "sub", "q.lock")))
        self.assertEqual(calls, [(2, 1), (2, 1), (0, 1)])

    def test_windows_file_lock_releases_on_exception(self):
        calls = []
        fake = types.SimpleNamespace(LK_NBLCK=2, LK_UNLCK=0, locking=lambda fd, mode, n: calls.append(mode))
        with tempfile.TemporaryDirectory() as d, mock.patch.dict(sys.modules, {"msvcrt": fake}):
            with self.assertRaises(RuntimeError):
                with ms2paths.file_lock(os.path.join(d, "q.lock")):
                    raise RuntimeError("boom")
        self.assertEqual(calls, [2, 0])


class TextDefaults(unittest.TestCase):
    def test_text_mode_is_utf8_and_lf_after_install(self):
        real = builtins.open
        try:
            ms2paths.install_text_defaults()
            ms2paths.install_text_defaults()        # idempotent
            with tempfile.TemporaryDirectory() as d:
                p = os.path.join(d, "t.tsv")
                with open(p, "w") as f:
                    f.write("a\u00e9\nb\n")
                self.assertEqual(real(p, "rb").read(), "a\u00e9\nb\n".encode("utf-8"))
                real(p, "wb").write(b"x\r\ny\r\n")
                self.assertEqual(open(p).read(), "x\ny\n")
        finally:
            builtins.open = real


class LinuxUnchanged(unittest.TestCase):
    @unittest.skipIf(os.name == "nt", "posix behaviour")
    def test_posix_environment_and_paths(self):
        env = ms2paths.toolchain_env({"A": "1"})
        self.assertEqual(env["WINEDEBUG"], "-all")
        self.assertEqual(env["WINEPREFIX"], ms2paths.WINEPREFIX)
        self.assertEqual(ms2paths.find_cl(), ms2paths.CL)
        self.assertEqual(ms2paths.host_path("Z:\\home\\x\\a.h"), "~/a.h")
        cmd = ["cl"] + ["x" * 1000] * 50
        self.assertIs(ms2paths.cl_cmdline(cmd), cmd)
        with tempfile.TemporaryDirectory() as d, ms2paths.file_lock(os.path.join(d, "l")):
            pass


class CheckToolchain(unittest.TestCase):
    def test_tree_digest_ignores_symlinks_and_case_duplicates(self):
        with tempfile.TemporaryDirectory() as d:
            os.makedirs(os.path.join(d, "a"))
            open(os.path.join(d, "a", "X.h"), "w").write("1")
            n0, h0 = check_toolchain.tree_digest(d)
            if hasattr(os, "symlink"):
                os.symlink(os.path.join(d, "a", "X.h"), os.path.join(d, "a", "x.h"))
            self.assertEqual(check_toolchain.tree_digest(d), (n0, h0))
            open(os.path.join(d, "a", "X.h"), "w").write("2")
            self.assertNotEqual(check_toolchain.tree_digest(d)[1], h0)

    def test_ci_path(self):
        with tempfile.TemporaryDirectory() as d:
            os.makedirs(os.path.join(d, "Um"))
            open(os.path.join(d, "Um", "WinNT.h"), "w").write("x")
            self.assertTrue(os.path.isfile(check_toolchain.ci_path(d, "um/winnt.h")))

    def test_compare_reports_differences_and_skips_quick_rows(self):
        want = {("file", "vc", "a"): "1", ("tree", "vc", "include"): "2 x", ("version", "cl"): "19.16.27054"}
        got = {("file", "vc", "a"): "9", ("version", "cl"): "19.16.27054"}
        bad = check_toolchain.compare(want, got)
        self.assertEqual(len(bad), 1)
        self.assertIn("got 9, want 1", bad[0])

    def test_manifest_has_the_compiler_binaries_and_versions(self):
        want = check_toolchain.read_manifest()
        for f in ("cl.exe", "c1.dll", "c1xx.dll", "c2.dll", "link.exe"):
            self.assertIn(("file", "vc", "bin/Hostx64/x64/" + f), want)
            self.assertEqual(len(want[("file", "vc", "bin/Hostx64/x64/" + f)]), 64)
        self.assertEqual(want[("version", "cl")], "19.16.27054")
        self.assertFalse([k for k, v in want.items() if v == "MISSING"])


class CheckExe(unittest.TestCase):
    def test_mismatch_and_missing(self):
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "x.exe")
            open(p, "wb").write(b"not the exe")
            with mock.patch("sys.stderr"):
                self.assertEqual(check_exe.main(["check_exe", p]), 1)
                self.assertEqual(check_exe.main(["check_exe", os.path.join(d, "nope")]), 2)
            with mock.patch.object(check_exe, "WANT", hashlib.sha256(b"not the exe").hexdigest()):
                self.assertEqual(check_exe.main(["check_exe", p]), 0)


class IncludeCase(unittest.TestCase):
    def test_scanner_flags_case_and_backslash(self):
        spec = importlib.util.spec_from_file_location("cic", os.path.join(TOOLS, "check-include-case.py"))
        cic = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(cic)
        with tempfile.TemporaryDirectory() as d:
            os.makedirs(os.path.join(d, "Sub"))
            open(os.path.join(d, "Sub", "Real.h"), "w").write("")
            self.assertEqual(cic.resolve(d, "Sub/Real.h"), (True, "Sub/Real.h"))
            self.assertEqual(cic.resolve(d, "sub\\real.h"), (False, "Sub/Real.h"))
            self.assertEqual(cic.resolve(d, "Sub/Missing.h"), (None, None))


class UnitCheck(unittest.TestCase):
    def test_find_units_matches_path_or_unit_name_like_progress_py(self):
        import unit_check
        got = unit_check.find_units(["uiloginnotice"])
        self.assertEqual(got, ["client/ms2/uiloginnotice.cpp"])
        self.assertEqual(unit_check.find_units(["no-such-unit-zzz"]), [])

    def test_windows_branch_builds_native_cmake_command(self):
        import unit_check
        seen = []

        def fake_call(cmd, **kw):
            seen.append(cmd)
            return 0
        with tempfile.TemporaryDirectory() as d, mock.patch.object(unit_check, "NT", True), \
                mock.patch.object(unit_check, "R", d), \
                mock.patch.object(ms2paths, "toolchain_env", lambda base=None: {"PATH": "x"}), \
                mock.patch.object(ms2paths, "winsdk_include", lambda env=None: "SDKINC"), \
                mock.patch.object(ms2paths, "python_exe", lambda: "py"), \
                mock.patch.object(unit_check, "find_units", lambda s: ["a/b.cpp"]), \
                mock.patch.object(unit_check, "has_external_thunk", lambda o: False), \
                mock.patch.object(unit_check.subprocess, "call", fake_call), \
                mock.patch.dict(os.environ, {"MS2_AGENT": "t"}):
            os.makedirs(os.path.join(d, "progress"))
            os.makedirs(os.path.join(d, "build", "progress-t"))
            with open(os.path.join(d, "progress", "symbols.tsv"), "w"):
                pass
            os.makedirs(os.path.join(d, "build", "hook-msvc-t"))
            os.makedirs(os.path.join(d, "build", "hook-clang-t"))
            self.assertEqual(unit_check.main(["--functional", "b"]), 0)
        cm = [c for c in seen if c and c[0] == "cmake"]
        self.assertEqual(len(cm), 2)
        self.assertTrue([a for a in cm[0] if a.startswith("-DCMAKE_TOOLCHAIN_FILE=")][0].endswith("toolchain-msvc1416-native.cmake"))
        self.assertIn("-DMS2_WINSDK_INCLUDE=SDKINC", cm[0])
        self.assertIn("-DMS2_GAME_FILTER=src/ms2/a/b.cpp;hook/difftest/b_difftest", cm[0])
        self.assertNotIn("nice", [c[0] for c in seen])
        self.assertTrue(any(c[0] == "ninja" for c in seen))
        self.assertEqual(seen[0][:2], ["py", os.path.join(d, "tools", "progress.py")])


if __name__ == "__main__":
    unittest.main()
