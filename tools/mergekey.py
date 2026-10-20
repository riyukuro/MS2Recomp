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
    """what a game unit's match result depends on besides its obj and its symbol-table rows (rows_stamp)"""
    if "game" not in _memo:
        files, es = _common()
        files += [os.path.join(ROOT, "tools", "progress.py")]
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


_tables = {}


def _table(path):
    """name (bytes) -> raw row of a symbol table (rows keyed by their mangled name)"""
    if path not in _tables:
        t = {}
        try:
            with open(path, "rb") as f:
                for line in f:
                    if line.startswith(b"#") or not line.strip():
                        continue
                    t[line.split(b"\t", 1)[0]] = line
        except OSError:
            pass
        _tables[path] = (t, [r for n, r in t.items() if len(n) <= 8])
    return _tables[path]


def obj_names(obj):
    """every symbol name of a COFF object longer than 8 bytes (its string table)"""
    import struct
    with open(obj, "rb") as f:
        d = f.read()
    if d[:4] == b"\0\0\xff\xff":
        symoff, nsyms = struct.unpack_from("<II", d, 48)
        recsz = 20
    else:
        symoff, nsyms = struct.unpack_from("<II", d, 8)
        recsz = 18
    return set(d[symoff + nsyms * recsz + 4:].split(b"\0"))


def rows_stamp(obj, table):
    """digest of the rows of a symbol table that a unit's match can read: every lookup is by a name of the unit's obj
    (relocation targets, pairs), plus the fixed CPtred names of bytematch and all names of at most 8 bytes (kept
    inline in the symbol records, not in the string table). Rows of other names never change the result, so an edit
    of symbols-manual.tsv / a new symbols.tsv re-matches only the units whose own names it touches."""
    t, short = _table(table)
    names = obj_names(obj) | {b"?ReleasePtred@CPtred@@SAHPEAV1@@Z", b"?AddRefPtred@CPtred@@SAXPEAV1@@Z", b"?DeletePtred@CPtred@@SAXPEAV1@@Z"}
    rows = sorted([t[n] for n in names if n in t] + short)
    return hashlib.sha1(b"".join(rows)).hexdigest()[:16]
