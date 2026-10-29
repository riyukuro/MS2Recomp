#!/usr/bin/env python3
"""Machine-wide counting semaphore for the memory-heavy steps (progress.py gates, DLL links, merge).

N slot files work/locks/heavy.1..N (N = MS2_HEAVY_SLOTS, default 5), each flock()ed; the kernel drops the lock when the holder
dies. The fds are close-on-exec, so no child (wineserver!) can keep a slot after its holder exits.

    heavy_lock.py [--all | --all-but N] [--client] [--quiet] -- <cmd> [args...]   run cmd holding one slot (--all: every slot, exclusive; --all-but N: all but N)
                                                          --client: also hold work/locks/client.lock (exclusive, one game client
                                                          at a time machine-wide), taken BEFORE the heavy slot so a queued client
                                                          run never sits on a slot; MS2_CLIENT_HELD=1 is exported to children
    from heavy_lock import heavy                          `with heavy(): ...` (no-op if MS2_HEAVY_HELD is set; the holder
                                                          exports MS2_HEAVY_HELD=1 to its children so they never re-acquire)

Measured (2026-10-19, tools/rss_peak.py): one progress.py gate ~0.5 GB, one unit-check DLL phase ~0.5 GB python/clang-cl plus
~1 GB of wine link.exe/wineserver outside the process tree; merge -j8 ~10+ GB. 5 slots (2026-10-22: 31 GB box, ~1.5 GB per gate, CPU is the real limit) keep gates under ~8 GB; a merge takes all but one (merge.sh, MS2_MERGE_LEAVE).
"""
import contextlib
import errno
import fcntl
import os
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def _lock_dir():
    """the machine-wide lock directory: MS2_LOCK_DIR (or the older MS2_HEAVY_DIR), else the main checkout's work/locks,
    found from a git worktree's common dir or by walking up from a clone placed under the main checkout, else this tree's
    own work/locks. Worktrees and clones must share one set of client/heavy locks or two clients can share a lane."""
    d = os.environ.get("MS2_LOCK_DIR") or os.environ.get("MS2_HEAVY_DIR")
    if d:
        return d
    try:
        g = os.path.join(ROOT, ".git")
        if os.path.isfile(g):       # worktree: "gitdir: <main>/.git/worktrees/<name>"
            with open(g) as f:
                gd = f.read().strip().split(":", 1)[1].strip()
            main = os.path.dirname(os.path.dirname(os.path.dirname(os.path.normpath(os.path.join(ROOT, gd)))))
            if os.path.isdir(os.path.join(main, "work", "locks")):
                return os.path.join(main, "work", "locks")
    except (OSError, IndexError):
        pass
    p = os.path.dirname(ROOT)
    while p != os.path.dirname(p):  # clone under <main>/work/...
        if os.path.isdir(os.path.join(p, "work", "locks")) and os.path.isdir(os.path.join(p, ".git")):
            return os.path.join(p, "work", "locks")
        p = os.path.dirname(p)
    return os.path.join(ROOT, "work", "locks")


DIR = _lock_dir()


def nslots():
    try:
        return max(1, int(os.environ.get("MS2_HEAVY_SLOTS", "5")))
    except ValueError:
        return 3


def cpu_budget():
    """CPU workers a heavy-slot holder may use: max(2, cpus * held // slots), held = MS2_HEAVY_SLOTS_HELD (exported by
    heavy(), default 1), so a merge holding all-but-one slots is not clamped to a single gate's share; MS2_JOBS_CAP overrides."""
    try:
        cap = int(os.environ.get("MS2_JOBS_CAP", "0"))
    except ValueError:
        cap = 0
    try:
        held = max(1, int(os.environ.get("MS2_HEAVY_SLOTS_HELD", "1")))
    except ValueError:
        held = 1
    return cap if cap > 0 else max(2, (os.cpu_count() or 4) * min(held, nslots()) // nslots())


def clamp_jobs(requested, flag="-j"):
    """min(requested, cpu_budget()); prints one stderr line when it clamps"""
    b = cpu_budget()
    if requested > b:
        print("jobs: %s %d clamped to %d (MS2_JOBS_CAP)" % (flag, requested, b), file=sys.stderr, flush=True)
        return b
    return requested


def _open(i):
    return os.open(os.path.join(DIR, "heavy.%d" % i), os.O_RDWR | os.O_CREAT, 0o666)   # O_CLOEXEC is the python default


def _pending_fd():
    return os.open(os.path.join(DIR, "heavy.pending"), os.O_RDWR | os.O_CREAT, 0o666)


def _no_multi_waiter():
    """fairness: a multi-slot waiter (acquire_all) holds heavy.pending exclusively until it has all its slots; single-slot
    takers only proceed while they can take it shared, so they queue behind the waiter instead of starving it"""
    fd = _pending_fd()
    try:
        fcntl.flock(fd, fcntl.LOCK_SH | fcntl.LOCK_NB)
        return True
    except OSError as e:
        if e.errno not in (errno.EWOULDBLOCK, errno.EAGAIN):
            raise
        return False
    finally:
        os.close(fd)


def _notice(quiet):
    if not quiet:
        print("waiting for heavy slot (%s) ..." % os.environ.get("MS2_AGENT", "?"), flush=True)


def acquire_one(quiet=False):
    os.makedirs(DIR, exist_ok=True)
    n, said = nslots(), False
    while True:
        for i in (range(1, n + 1) if _no_multi_waiter() else ()):
            fd = _open(i)
            try:
                fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
                return [fd]
            except OSError:
                os.close(fd)
        if not said:
            _notice(quiet)
            said = True
        time.sleep(2)


def acquire_all(quiet=False, leave=0):
    """slots in ascending order, blocking: two exclusive holders cannot deadlock, shared takers just see slots busy.
    leave=N keeps the top N slots free so worker gates are never starved by a merge (at least one slot is always taken).
    While waiting it holds heavy.pending exclusively, so new single-slot takers wait instead of refilling freed slots
    (multi-slot waiters queue on heavy.pending among themselves)"""
    os.makedirs(DIR, exist_ok=True)
    pend = _pending_fd()
    try:
        fcntl.flock(pend, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except OSError:
        _notice(quiet)
        quiet = True
        fcntl.flock(pend, fcntl.LOCK_EX)
    fds = []
    try:
        for i in range(1, max(1, nslots() - leave) + 1):
            fd = _open(i)
            try:
                fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
            except OSError:
                _notice(quiet)
                quiet = True
                fcntl.flock(fd, fcntl.LOCK_EX)
            fds.append(fd)
    except BaseException:
        for fd in fds:
            os.close(fd)
        raise
    finally:
        os.close(pend)
    return fds


def acquire_client(quiet=False):
    """the client-run lock (wine/Xvfb game launches); blocking. One per lane: client.lock, or client<N>.lock with FULLEXE_LANE=N"""
    os.makedirs(DIR, exist_ok=True)
    lane = os.environ.get("FULLEXE_LANE", "")     # opt-in second client lane: FULLEXE_LANE=2 -> client2.lock (default: client.lock)
    fd = os.open(os.path.join(DIR, "client%s.lock" % (lane if lane not in ("", "1") else "")), os.O_RDWR | os.O_CREAT, 0o666)
    try:
        fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except OSError:
        if not quiet:
            print("waiting for client lock (%s) ..." % os.environ.get("MS2_AGENT", "?"), flush=True)
        fcntl.flock(fd, fcntl.LOCK_EX)
    return fd


@contextlib.contextmanager
def client_lock(quiet=False):
    """`with client_lock(): ...`; no-op if MS2_CLIENT_HELD is set (independent of MS2_HEAVY_HELD)"""
    if os.environ.get("MS2_CLIENT_HELD"):
        yield
        return
    fd = acquire_client(quiet)
    os.environ["MS2_CLIENT_HELD"] = "1"
    try:
        yield
    finally:
        os.environ.pop("MS2_CLIENT_HELD", None)
        os.close(fd)


@contextlib.contextmanager
def heavy(exclusive=False, quiet=False, leave=0):
    if os.environ.get("MS2_HEAVY_HELD"):
        yield
        return
    fds = acquire_all(quiet, leave) if exclusive else acquire_one(quiet)
    os.environ["MS2_HEAVY_HELD"] = "1"
    os.environ["MS2_HEAVY_SLOTS_HELD"] = str(len(fds))
    try:
        yield
    finally:
        os.environ.pop("MS2_HEAVY_HELD", None)
        os.environ.pop("MS2_HEAVY_SLOTS_HELD", None)
        for fd in fds:
            os.close(fd)


def main(a):
    excl = quiet = client = False
    leave = 0
    while a and a[0] in ("--all", "--all-but", "--quiet", "--client"):
        if a[0] == "--all-but":      # --all-but N: every slot except the top N (merge: gates keep running)
            excl, leave, a = True, int(a[1]), a[1:]
        elif a[0] == "--client":
            client = True
        else:
            excl, quiet = excl or a[0] == "--all", quiet or a[0] == "--quiet"
        a = a[1:]
    if a[:1] == ["--"]:
        a = a[1:]
    if not a:
        print(__doc__)
        return 2
    with client_lock(quiet) if client else contextlib.nullcontext():
        with heavy(excl, quiet, leave):
            return subprocess.call(a)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
