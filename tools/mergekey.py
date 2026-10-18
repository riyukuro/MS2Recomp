"""Content stamps for the persistent merge tree (tools/merge.sh). Opt-in: progress.py / gbprogress.py add these to their
per-unit match cache keys only when MS2_MERGE_INCR=1, so worker (agent/report) caches keep their old keys.

The obj-mtime key of a cached match result misses everything a match reads besides the obj: the hand-written symbol table
(merge mode), the symbol tables the engine stage resolves relocations through, the exe function/unit/RTTI maps and the
matcher's own code. A change in any of them re-matches (not recompiles) the affected stage.
"""
import hashlib
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
_memo = {}


def _hash(paths, extra=""):
    h = hashlib.sha1(extra.encode())
    for p in paths:
        h.update(os.path.basename(p).encode())
        try:
            with open(p, "rb") as f:
                h.update(f.read())
        except OSError:
            h.update(b"-")
    return h.hexdigest()[:16]


def _common():
    import ms2paths
    exe = ms2paths.EXE
    try:
        st = os.stat(exe)
        es = f"{st.st_size}:{int(st.st_mtime)}"
    except OSError:
        es = "-"
    return [os.path.join(ROOT, "tools", n) for n in ("bytematch.py", "ms2paths.py")] + \
        [ms2paths.FUNCTIONS_TSV, ms2paths.UNITS_TSV, ms2paths.RTTI_CLASSES, ms2paths.RTTI_VFTABLES], es


def game_stamp():
    """what a game unit's match result depends on besides its obj (merge mode: symbols-manual.tsv is the symbol table)"""
    if "game" not in _memo:
        files, es = _common()
        files += [os.path.join(ROOT, "tools", "progress.py"), os.path.join(ROOT, "progress", "symbols-manual.tsv")]
        env = "".join(f"{k}={os.environ.get(k, '')};" for k in ("MS2_NO_ICF_FOLD", "MS2_NO_MULTICOPY", "MS2_GUESS_LOOKALIKES"))
        _memo["game"] = _hash(files, es + env)
    return _memo["game"]


def engine_stamp():
    """what an engine TU's match result depends on besides its obj: the symbol tables gbprogress._init reads, as of now
    (progress.py has already written the merge's symbols.tsv when the engine stage runs)"""
    if "engine" not in _memo:
        files, es = _common()
        files += [os.path.join(ROOT, "tools", n) for n in ("gbprogress.py", "gbtree.py")]
        files += [os.path.join(ROOT, "progress", n) for n in ("symbols-manual.tsv", "symbols.tsv", "symbols-engine.tsv")]
        _memo["engine"] = _hash(files, es)
    return _memo["engine"]
