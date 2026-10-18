#!/usr/bin/env python3
"""Emit SDK-free patches for engine/gamebryo (stock import commit -> HEAD).

For every modified file an ed-style script (diff -e semantics: line-number
commands carrying only OUR inserted text, never removed or context SDK lines)
goes to engine-patches/<path>.ed; added files become a single `0a` script.
Lines that are >=80% identical to the SDK line they replace are emitted as
column-addressed token substitutions (`N@COL s "old" "new"`) instead of whole
lines, so they carry only the changed tokens.  engine-patches/manifest.tsv
lists path, sha256(stock), sha256(result), kind.

Script format (bytes decoded as latin-1 only inside JSON strings):
  N a / N,M c / N,M d   text lines follow for a/c, terminated by a "." line
                        (lines starting with "." are dot-stuffed with one more ".")
  N@COL s "old" "new"   in 1-based line N, at 0-based byte COL, replace old by new
Line numbers refer to the stock file; commands run in descending order.
File model: data.split(b"\\n") (last element is the text after the final newline).

Policy file (tools/engine-patches-policy.txt), one entry per line, `#` comments:
  withhold-file <path>        added file that must not ship (kind=withheld)
  keep <path>:<newline>       force the literal line (ours dominates) at that result line
  withhold <path>:<newline>   force token-substitution form at that result line
"""
import argparse, difflib, hashlib, json, os, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
STOCK = "2634c347"
SUB = "engine/gamebryo"
THRESH = 0.8
MIN_SDK_CHARS = 25   # shorter shared text is boilerplate: keep the literal line


def git(*a, text=False):
    r = subprocess.run(["git", "-C", str(ROOT), *a], stdout=subprocess.PIPE, check=True)
    return r.stdout.decode() if text else r.stdout


def sha(b):
    return hashlib.sha256(b).hexdigest()


def load_policy(p):
    pol = {"withhold-file": set(), "keep": set(), "withhold": set()}
    if p.exists():
        for ln in p.read_text().splitlines():
            ln = ln.split("#", 1)[0].strip()
            if ln:
                k, v = ln.split(None, 1)
                pol[k].add(v.strip())
    return pol


def diff_hunks(old, new):
    """Normal-format diff of two line lists -> [(kind, o1, o2, n1, n2)] 1-based inclusive."""
    with tempfile.TemporaryDirectory() as d:
        fa, fb = os.path.join(d, "a"), os.path.join(d, "b")
        for f, ls in ((fa, old), (fb, new)):
            with open(f, "wb") as fh:
                fh.write(b"\n".join(ls) + b"\n")
        r = subprocess.run(["/usr/bin/diff", "--minimal", fa, fb], stdout=subprocess.PIPE)
    hunks = []
    for ln in r.stdout.decode("latin-1").splitlines():
        if not ln or ln[0] in "<>-\\":
            continue
        for k in "acd":
            if k in ln:
                l, rr = ln.split(k)
                break
        def rng(s):
            if "," in s:
                a, b = s.split(",")
                return int(a), int(b)
            return int(s), int(s)
        o1, o2 = rng(l)
        n1, n2 = rng(rr)
        hunks.append((k, o1, o2, n1, n2))
    return hunks


def token_subs(o, n):
    """Char-level opcodes -> [(col, old, new)] (columns in o)."""
    sm = difflib.SequenceMatcher(None, o, n, autojunk=False)
    return [(i1, o[i1:i2], n[j1:j2]) for t, i1, i2, j1, j2 in sm.get_opcodes() if t != "equal"]


def make_ops(path, old, new, pol, stats):
    """Return ops: ('a',after,[lines]) ('c',s,e,[lines]) ('d',s,e) ('s',line,col,old,new)."""
    ops = []
    for k, o1, o2, n1, n2 in diff_hunks(old, new):
        if k == "d":
            ops.append(("d", o1, o2))
        elif k == "a":
            ops.append(("a", o1, new[n1 - 1:n2]))
        else:
            olds, news = old[o1 - 1:o2], new[n1 - 1:n2]
            pend = []   # literal run (start_old, [lines])
            def flush():
                nonlocal pend
                if pend:
                    s, ls = pend[0], pend[1]
                    ops.append(("c", s, s + len(ls) - 1, ls))
                    pend = []
            if len(olds) == len(news):
                for i, (a, b) in enumerate(zip(olds, news)):
                    key = f"{path}:{n1 + i}"
                    sa, sb = a.decode("latin-1"), b.decode("latin-1")
                    sm = difflib.SequenceMatcher(None, sa, sb, autojunk=False)
                    ratio = sm.ratio()
                    shared = sum(m.size for m in sm.get_matching_blocks())
                    close = ratio >= THRESH
                    if close:
                        verdict = "withhold" if shared >= MIN_SDK_CHARS else "keep"
                        if key in pol["keep"]:
                            verdict = "keep"
                        if key in pol["withhold"]:
                            verdict = "withhold"
                        stats.append((key, ratio, shared, verdict, sa, sb))
                    else:
                        verdict = "keep"
                    if verdict == "withhold":
                        flush()
                        for col, so, sn in token_subs(sa, sb):
                            ops.append(("s", o1 + i, col, so, sn))
                    else:
                        if not pend:
                            pend = [o1 + i, []]
                        pend[1].append(b)
                flush()
            else:
                ops.append(("c", o1, o2, news))
    return ops


def opkey(op):
    if op[0] == "s":
        return (op[1], op[2])
    return (op[2] if op[0] != "a" else op[1], 10**9)


def emit(ops):
    out = []
    for op in sorted(ops, key=opkey, reverse=True):
        t = op[0]
        if t == "s":
            _, ln, col, so, sn = op
            out.append(f'{ln}@{col}s {json.dumps(so)} {json.dumps(sn)}'.encode("ascii"))
            continue
        if t == "a":
            out.append(f"{op[1]}a".encode())
            lines = op[2]
        elif t == "c":
            out.append((f"{op[1]}c" if op[1] == op[2] else f"{op[1]},{op[2]}c").encode())
            lines = op[3]
        else:
            out.append((f"{op[1]}d" if op[1] == op[2] else f"{op[1]},{op[2]}d").encode())
            continue
        for ln in lines:
            out.append(b"." + ln if ln.startswith(b".") else ln)
        out.append(b".")
    return b"\n".join(out) + (b"\n" if out else b"")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(ROOT / "engine-patches"))
    ap.add_argument("--policy", default=str(ROOT / "tools/engine-patches-policy.txt"))
    ap.add_argument("--review", help="write the similarity list (tsv) here")
    a = ap.parse_args()
    out = Path(a.out)
    pol = load_policy(Path(a.policy))
    names = git("diff", "--name-status", "-z", STOCK, "HEAD", "--", SUB).decode("latin-1").split("\0")
    ents = [(names[i], names[i + 1]) for i in range(0, len(names) - 1, 2)]
    man, stats, nlines, withheld_tok = [], [], 0, 0
    import shutil
    if out.exists():
        shutil.rmtree(out)
    for st, p in sorted(ents, key=lambda e: e[1]):
        rel = p[len(SUB) + 1:]
        new = git("show", f"HEAD:{p}")
        if st == "A":
            if rel in pol["withhold-file"] or p in pol["withhold-file"]:
                man.append((rel, "-", sha(new), "withheld"))
                continue
            script = emit([("a", 0, new.split(b"\n"))])
            man.append((rel, "-", sha(new), "added"))
        elif st == "M":
            old = git("show", f"{STOCK}:{p}")
            fs = []
            ops = make_ops(rel, old.split(b"\n"), new.split(b"\n"), pol, fs)
            stats += fs
            script = emit(ops)
            man.append((rel, sha(old), sha(new), "modified"))
        else:
            sys.exit(f"unsupported status {st} {p}")
        d = out / (rel + ".ed")
        d.parent.mkdir(parents=True, exist_ok=True)
        d.write_bytes(script)
        nlines += script.count(b"\n")
    with open(out / "manifest.tsv", "w") as f:
        f.write("path\tstock_sha256\tresult_sha256\tkind\n")
        for m in man:
            f.write("\t".join(m) + "\n")
    wh = sum(1 for s in stats if s[3] == "withhold")
    if a.review:
        with open(a.review, "w") as f:
            f.write("key\tratio\tshared\tverdict\tsdk\tours\n")
            for s in stats:
                f.write("\t".join([s[0], f"{s[1]:.2f}", str(s[2]), s[3], s[4].strip(), s[5].strip()]) + "\n")
    kinds = {}
    for m in man:
        kinds[m[3]] = kinds.get(m[3], 0) + 1
    print(f"files={len(man)} kinds={kinds} ed_lines={nlines} close_lines={len(stats)} withheld_token_lines={wh}")


if __name__ == "__main__":
    main()
