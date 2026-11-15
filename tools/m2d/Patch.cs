using System.Security.Cryptography;
using System.Text;
using System.Xml.Linq;
using Maple2.File.IO;

// m2d patch: apply text patch files to a KMS2 client's data, taking copied rows from the packs you have.
//
//   m2d patch <KMS2 Data dir> [--gms <GMS Data dir>] <patch files...> --out <dir> [--repack]
//   m2d hash <archive.m2d> <entry...>                  the pin of each entry, for writing a patch
//
// Without --repack the patched files are written as loose files under --out, laid out as a Data directory
// (<out>/Xml/itemdata/209.xml): the client reads loose files before its packs, so --out can be the client's Data
// directory itself. With --repack, --out gets patched copies of the touched packs (<out>/Xml.m2d + .m2h) instead.
// The original packs are only read.
//
// Patch file: one op per line ('\' at the end of a line continues it); '#' starts a comment line. Paths are
// <pack>/<entry> relative to the Data directory (Xml/itemdata/506.xml = entry itemdata/506.xml of Data/Xml.m2d).
// A source is kms:<path> or gms:<path>. A pin is the first 16 hex digits of the SHA-256 of the entry's bytes;
// every entry a patch reads must be pinned, and the patch stops with a message when the pack you have holds
// different bytes.
//
//   patch <name>                          the patch's name (first op)
//   made-for <text>                       which client data the patch was made for (shown on a mismatch)
//   need <source> <pin>                   pin an entry read by copy-row / copy-attr / copy-item
//   file <path> <source> <pin>            start editing <path>, based on the source entry (the entry is pinned)
//   file <path> new                       start a file the KMS2 pack lacks (an empty <ms2> root)
//   set <sel> <attr> "<value>"            set an attribute of every matched element
//   unset <sel> <attr>                    remove an attribute of every matched element
//   row <sel> [after <step>] <element>    replace the matched element, or add it (after the last sibling matching
//                                         <step>, or at the end of the parent)
//   remove <sel>                          remove the matched elements
//   copy-row <sel> <source> [after <step>]   the element at <sel> in the source entry, replacing or added
//   copy-attr <sel> <attr> <source>       the attribute's value from the element at <sel> in the source entry
//   copy-item <id>                        the global client's item/<d>/<dd>/<id>.xml as a KMS2 itemdata row:
//                                         its environments, without feature switch and empty locale, with
//                                         option constant copied to property rank (where KMS2 reads the grade)
//
// A selector is steps joined by '/': tag[attr=value][attr=value]. The first step matches at any depth, the
// others match children. A step without a predicate matches every element of that tag. Values are plain text,
// quoted with "..." (\" and \\ escapes); an <element> is written as XML.
static class Patch {
    sealed class Step {
        public string Tag;
        public List<(string, string)> Preds = new();
        public bool Match(XElement e) =>
            e.Name.LocalName == Tag && Preds.All(p => (string)e.Attribute(p.Item1) == p.Item2);
        public override string ToString() => Tag + string.Concat(Preds.Select(p => $"[{p.Item1}={p.Item2}]"));
    }

    sealed class Doc { public XDocument X; public string Decl; public bool Bom; public string Source; }

    sealed class PatchError : Exception { public PatchError(string m) : base(m) { } }

    sealed class Packs {
        readonly Dictionary<string, M2dReader> open = new(StringComparer.OrdinalIgnoreCase);
        readonly string kmsDir, gmsDir;
        public Packs(string kms, string gms) { kmsDir = kms; gmsDir = gms; }
        public string KmsPack(string pack) => Path.Combine(kmsDir, pack + ".m2d");
        M2dReader Reader(string side, string pack) {
            string dir = side == "kms" ? kmsDir : gmsDir;
            if (dir == null) throw new PatchError($"the patch reads {side}:{pack}/..., give --gms <GMS Data dir>");
            string file = Path.Combine(dir, pack + ".m2d");
            if (!open.TryGetValue(side + ":" + pack, out var r)) {
                if (!File.Exists(file)) throw new PatchError($"no pack {file}");
                r = new M2dReader(file);
                open[side + ":" + pack] = r;
            }
            return r;
        }
        public byte[] Get(string side, string path) {
            var (pack, entry) = Split(path);
            var r = Reader(side, pack);
            var e = r.Files.FirstOrDefault(f => string.Equals(f.Name, entry, StringComparison.OrdinalIgnoreCase));
            return e == null ? null : r.GetBytes(e);
        }
    }

    public static string Pin(byte[] b) =>
        Convert.ToHexString(SHA256.HashData(b)).Substring(0, 16).ToLowerInvariant();

    static (string, string) Split(string path) {
        int i = path.IndexOf('/');
        if (i <= 0) throw new PatchError($"path {path}: expected <pack>/<entry>");
        return (path[..i], path[(i + 1)..]);
    }

    public static int Hash(string[] a) {
        if (a.Length < 3) { Console.Error.WriteLine("usage: m2d hash <archive.m2d> <entry...>"); return 2; }
        using var r = new M2dReader(a[1]);
        int rc = 0;
        foreach (var name in a.Skip(2)) {
            var e = r.Files.FirstOrDefault(f => string.Equals(f.Name, name, StringComparison.OrdinalIgnoreCase));
            if (e == null) { Console.WriteLine($"{name} -"); rc = 1; continue; }
            Console.WriteLine($"{name} {Pin(r.GetBytes(e))}");
        }
        return rc;
    }

    public static int Run(string[] a) {
        string kms = null, gms = null, outDir = null;
        bool repack = false;
        var files = new List<string>();
        for (int i = 1; i < a.Length; i++) {
            if (a[i] == "--gms" && i + 1 < a.Length) gms = a[++i];
            else if (a[i] == "--out" && i + 1 < a.Length) outDir = a[++i];
            else if (a[i] == "--repack") repack = true;
            else if (kms == null) kms = a[i];
            else files.Add(a[i]);
        }
        if (kms == null || outDir == null || files.Count == 0) {
            Console.Error.WriteLine(
                "usage: m2d patch <KMS2 Data dir> [--gms <GMS Data dir>] <patch files...> --out <dir> [--repack]");
            return 2;
        }
        var packs = new Packs(kms, gms);
        var docs = new Dictionary<string, Doc>(StringComparer.OrdinalIgnoreCase);
        var order = new List<string>();
        try {
            foreach (var f in files) Apply(f, packs, docs, order);
            if (repack) WritePacks(packs, kms, outDir, docs, order);
            else foreach (var p in order) {
                var path = Path.Combine(outDir, p.Replace('/', Path.DirectorySeparatorChar));
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllBytes(path, Serialize(docs[p]));
                Console.WriteLine($"wrote {path}");
            }
        } catch (PatchError e) {
            Console.Error.WriteLine("m2d patch: " + e.Message);
            return 1;
        }
        return 0;
    }

    static void Apply(string file, Packs packs, Dictionary<string, Doc> docs, List<string> order) {
        var pins = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
        string name = Path.GetFileName(file), madeFor = "(not stated)";
        Doc cur = null;
        int n = 0, first = 0, changed = 0;
        string pending = null;
        foreach (var raw in File.ReadLines(file)) {
            n++;
            var line = raw.Trim();
            if (pending == null && (line.Length == 0 || line[0] == '#')) continue;
            if (pending == null) first = n;
            if (line.EndsWith('\\')) { pending = (pending ?? "") + line[..^1].TrimEnd() + " "; continue; }
            if (pending != null) { line = pending + line; pending = null; }
            string where = $"{name}:{first}";
            var t = new Tokens(line, where);
            string op = t.Word();

            // the bytes of a pinned source entry; stops on a missing entry or other bytes
            byte[] Source(string src) {
                int c = src.IndexOf(':');
                if (c < 0 || (src[..c] != "kms" && src[..c] != "gms"))
                    throw new PatchError($"{where}: source {src}: expected kms:<path> or gms:<path>");
                if (!pins.TryGetValue(src, out var pin))
                    throw new PatchError($"{where}: {src} is not pinned (add: need {src} <pin>)");
                var b = packs.Get(src[..c], src[(c + 1)..]);
                if (b == null)
                    throw new PatchError($"{name}: {src} is not in your pack; the patch was made for: {madeFor}");
                var got = Pin(b);
                if (got != pin)
                    throw new PatchError($"{name}: {src} differs from the data the patch was made for (pin {got}, "
                        + $"expected {pin}; made for: {madeFor}). Stopped, nothing written.");
                return b;
            }
            Doc Cur() => cur ?? throw new PatchError($"{where}: no file op before {op}");
            XElement Single(Doc from, List<Step> sel, string src) {
                var hits = Find(from.X.Root, sel, where, false).ToList();
                if (hits.Count != 1)
                    throw new PatchError($"{where}: {src} has {hits.Count} elements at {Show(sel)}, expected 1");
                return hits[0];
            }

            switch (op) {
                case "patch": name = t.Rest(); break;
                case "made-for": madeFor = t.Rest(); break;
                case "need": {
                    var src = t.Word();
                    pins[src] = t.Word().ToLowerInvariant();
                    Source(src);
                    break;
                }
                case "file": {
                    var path = t.Word();
                    Split(path);
                    var src = t.Word();
                    Doc d;
                    if (src == "new") {
                        if (packs.Get("kms", path) != null)
                            throw new PatchError($"{where}: your KMS2 pack has {path}; the patch was made for a pack "
                                + $"without it ({madeFor})");
                        d = new Doc {
                            X = new XDocument(new XElement("ms2", new XText("\n"))),
                            Decl = "<?xml version=\"1.0\" encoding=\"utf-8\"?>", Source = "new",
                        };
                    } else {
                        pins[src] = t.Word().ToLowerInvariant();
                        d = Load(Source(src), src);
                    }
                    if (docs.TryGetValue(path, out var have)) cur = have;   // an earlier patch file started it
                    else { cur = d; docs[path] = d; order.Add(path); }
                    break;
                }
                case "set": {
                    var sel = Sel(t.Word(), where);
                    var attr = t.Word();
                    var v = t.Value();
                    foreach (var e in Find(Cur().X.Root, sel, where, true)) {
                        e.SetAttributeValue(attr, v);
                        changed++;
                    }
                    break;
                }
                case "unset": {
                    var sel = Sel(t.Word(), where);
                    var attr = t.Word();
                    foreach (var e in Find(Cur().X.Root, sel, where, false))
                        if (e.Attribute(attr) != null) { e.Attribute(attr).Remove(); changed++; }
                    break;
                }
                case "remove": {
                    var sel = Sel(t.Word(), where);
                    foreach (var e in Find(Cur().X.Root, sel, where, false).ToList()) {
                        RemoveWithIndent(e);
                        changed++;
                    }
                    break;
                }
                case "row": {
                    var sel = Sel(t.Word(), where);
                    var after = t.After(where);
                    XElement e;
                    try { e = XElement.Parse(t.Rest()); }
                    catch (Exception ex) { throw new PatchError($"{where}: bad element: {ex.Message}"); }
                    Put(Cur().X.Root, sel, after, e, where);
                    changed++;
                    break;
                }
                case "copy-row": {
                    var sel = Sel(t.Word(), where);
                    var src = t.Word();
                    var after = t.After(where);
                    var row = Single(Load(Source(src), src), sel, src);
                    Put(Cur().X.Root, sel, after, new XElement(row), where);
                    changed++;
                    break;
                }
                case "copy-attr": {
                    var sel = Sel(t.Word(), where);
                    var attr = t.Word();
                    var src = t.Word();
                    var value = (string)Single(Load(Source(src), src), sel, src).Attribute(attr)
                        ?? throw new PatchError($"{where}: {src} has no {attr} at {Show(sel)}");
                    foreach (var e in Find(Cur().X.Root, sel, where, true)) {
                        e.SetAttributeValue(attr, value);
                        changed++;
                    }
                    break;
                }
                case "copy-item": {
                    var id = t.Word();
                    if (id.Length < 4 || !id.All(char.IsDigit)) throw new PatchError($"{where}: item id {id}");
                    var src = $"gms:Xml/item/{id[0]}/{id.Substring(1, 2)}/{id}.xml";
                    if (!pins.ContainsKey(src))
                        throw new PatchError($"{where}: {src} is not pinned (add: need {src} <pin>)");
                    var row = ItemRow(id, Load(Source(src), src).X, where);
                    Put(Cur().X.Root, Sel($"item[id={id}]", where), null, row, where);
                    changed++;
                    break;
                }
                default: throw new PatchError($"{where}: unknown op {op}");
            }
            t.End();
        }
        if (pending != null) throw new PatchError($"{name}:{first}: the last line ends with '\\'");
        Console.WriteLine($"{name}: {changed} changes");
    }

    // A global client's item file as a KMS2 itemdata row.
    static XElement ItemRow(string id, XDocument src, string where) {
        var envs = src.Root.Elements("environment").ToList();
        if (envs.Count == 0) throw new PatchError($"{where}: item {id} has no environment");
        var row = new XElement("item", new XAttribute("id", id));
        foreach (var env in envs) {
            var e = new XElement(env);
            e.Attribute("feature")?.Remove();
            if ((string)e.Attribute("locale") == "") e.Attribute("locale").Remove();
            var constant = e.Descendants("option").Select(o => (string)o.Attribute("constant"))
                .FirstOrDefault(c => !string.IsNullOrEmpty(c) && c.All(char.IsDigit));
            var prop = e.Descendants("property").FirstOrDefault();
            if (constant != null && prop != null && prop.Attribute("rank") == null) {
                var attrs = prop.Attributes().ToList();
                prop.RemoveAttributes();
                prop.Add(new XAttribute("rank", constant));
                prop.Add(attrs);
            }
            row.Add(e);
        }
        return row;
    }

    // ---- selectors ----

    static string Show(List<Step> sel) => string.Join("/", sel);

    static List<Step> Sel(string text, string where) {
        var steps = new List<Step>();
        foreach (var part in text.Split('/')) {
            var s = new Step();
            int b = part.IndexOf('[');
            s.Tag = b < 0 ? part : part[..b];
            if (s.Tag.Length == 0) throw new PatchError($"{where}: selector {text}");
            var rest = b < 0 ? "" : part[b..];
            while (rest.Length > 0) {
                int close = rest.IndexOf(']'), eq = rest.IndexOf('=');
                if (rest[0] != '[' || close < 0 || eq < 0 || eq > close)
                    throw new PatchError($"{where}: selector {text}");
                s.Preds.Add((rest[1..eq], rest[(eq + 1)..close]));
                rest = rest[(close + 1)..];
            }
            steps.Add(s);
        }
        return steps;
    }

    static IEnumerable<XElement> Find(XElement root, List<Step> sel, string where, bool needOne) {
        IEnumerable<XElement> cur = root.Descendants().Where(sel[0].Match);
        foreach (var s in sel.Skip(1)) cur = cur.SelectMany(e => e.Elements()).Where(s.Match);
        var list = cur.ToList();
        if (needOne && list.Count == 0) throw new PatchError($"{where}: no element at {Show(sel)}");
        return list;
    }

    // Replace the element at sel, or add it: under the parent selector, else under the parent of the elements of
    // that tag, else under the root; after the last sibling matching <after>, else at the end.
    static void Put(XElement root, List<Step> sel, Step after, XElement e, string where) {
        var hits = Find(root, sel, where, false).ToList();
        if (hits.Count > 1) throw new PatchError($"{where}: {hits.Count} elements at {Show(sel)}, expected at most 1");
        if (hits.Count == 1) {
            Indent(e, Depth(hits[0]));
            hits[0].ReplaceWith(e);
            return;
        }
        XElement parent;
        if (sel.Count > 1) {
            var ps = Find(root, sel.Take(sel.Count - 1).ToList(), where, true).ToList();
            if (ps.Count != 1) throw new PatchError($"{where}: {ps.Count} parents for {Show(sel)}");
            parent = ps[0];
        } else parent = root.Descendants(sel[0].Tag).FirstOrDefault()?.Parent ?? root;
        int depth = Depth(parent) + 1;
        Indent(e, depth);
        var pad = "\n" + new string('\t', depth);
        var anchor = after == null ? parent.Elements().LastOrDefault() : parent.Elements().LastOrDefault(after.Match);
        if (after != null && anchor == null) throw new PatchError($"{where}: no sibling {after} to add after");
        if (anchor != null) anchor.AddAfterSelf(new XText(pad), e);
        else {
            foreach (var w in parent.Nodes().OfType<XText>().ToList()) w.Remove();
            parent.Add(new XText(pad), e, new XText("\n" + new string('\t', depth - 1)));
        }
    }

    static void RemoveWithIndent(XElement e) {
        if (e.PreviousNode is XText w && string.IsNullOrWhiteSpace(w.Value)) w.Remove();
        e.Remove();
    }

    static int Depth(XElement e) {
        int d = 0;
        for (var p = e.Parent; p != null; p = p.Parent) d++;
        return d;
    }

    // Lay out an added element as the KMS2 files are: one tab per level, children on their own lines.
    static void Indent(XElement e, int depth) {
        foreach (var w in e.Nodes().OfType<XText>().Where(x => string.IsNullOrWhiteSpace(x.Value)).ToList()) w.Remove();
        var kids = e.Elements().ToList();
        if (kids.Count == 0) return;
        foreach (var k in kids) {
            k.AddBeforeSelf(new XText("\n" + new string('\t', depth + 1)));
            Indent(k, depth + 1);
        }
        e.Add(new XText("\n" + new string('\t', depth)));
    }

    // ---- files ----

    static Doc Load(byte[] b, string what) {
        bool bom = b.Length >= 3 && b[0] == 0xEF && b[1] == 0xBB && b[2] == 0xBF;
        var text = Encoding.UTF8.GetString(b, bom ? 3 : 0, b.Length - (bom ? 3 : 0));
        string decl = null;
        if (text.StartsWith("<?xml")) decl = text[..(text.IndexOf("?>") + 2)];
        try {
            var x = XDocument.Parse(text, LoadOptions.PreserveWhitespace);
            return new Doc { X = x, Decl = decl, Bom = bom, Source = what };
        } catch (Exception ex) { throw new PatchError($"{what}: not XML: {ex.Message}"); }
    }

    static byte[] Serialize(Doc d) {
        var sb = new StringBuilder();
        if (d.Decl != null) sb.Append(d.Decl);
        foreach (var node in d.X.Nodes()) {
            // whitespace between the declaration, comments and the root is kept as the file had it
            if (node is XText w) { sb.Append(w.Value); continue; }
            if (sb.Length > 0 && sb[^1] != '\n') sb.Append('\n');
            sb.Append(node.ToString(SaveOptions.DisableFormatting));
        }
        if (d.Source == "new") sb.Append('\n');
        var body = Encoding.UTF8.GetBytes(sb.ToString());
        return d.Bom ? new byte[] { 0xEF, 0xBB, 0xBF }.Concat(body).ToArray() : body;
    }

    static void WritePacks(Packs packs, string kms, string outDir, Dictionary<string, Doc> docs, List<string> order) {
        if (Path.GetFullPath(outDir).TrimEnd('/', '\\') == Path.GetFullPath(kms).TrimEnd('/', '\\'))
            throw new PatchError("--repack --out is the KMS2 Data directory; give another directory "
                + "(the original packs are never written)");
        Directory.CreateDirectory(outDir);
        foreach (var group in order.GroupBy(p => Split(p).Item1, StringComparer.OrdinalIgnoreCase)) {
            var files = new Dictionary<string, byte[]>(StringComparer.OrdinalIgnoreCase);
            foreach (var p in group) files[Split(p).Item2] = Serialize(docs[p]);
            Repack.Build(packs.KmsPack(group.Key), Path.Combine(outDir, group.Key + ".m2d"), files,
                add: true, lowerNew: true);
        }
    }

    // ---- line tokens ----

    sealed class Tokens {
        readonly string s, where;
        int i;
        public Tokens(string line, string w) { s = line; where = w; }
        void Skip() { while (i < s.Length && (s[i] == ' ' || s[i] == '\t')) i++; }
        public string Word() {
            Skip();
            int st = i;
            while (i < s.Length && s[i] != ' ' && s[i] != '\t') i++;
            if (st == i) throw new PatchError($"{where}: missing argument");
            return s[st..i];
        }
        public string Rest() {
            Skip();
            var r = s[i..].Trim();
            i = s.Length;
            if (r.Length == 0) throw new PatchError($"{where}: missing argument");
            return r;
        }
        public string Value() {
            Skip();
            if (i >= s.Length || s[i] != '"') throw new PatchError($"{where}: expected a \"quoted\" value");
            var sb = new StringBuilder();
            i++;
            while (true) {
                if (i >= s.Length) throw new PatchError($"{where}: unterminated value");
                char c = s[i++];
                if (c == '"') break;
                if (c == '\\' && i < s.Length) c = s[i++];
                sb.Append(c);
            }
            return sb.ToString();
        }
        public Step After(string w) {
            Skip();
            if (!s[i..].StartsWith("after ")) return null;
            i += 6;
            return Sel(Word(), w).Single();
        }
        public void End() {
            Skip();
            if (i < s.Length) throw new PatchError($"{where}: extra text: {s[i..]}");
        }
    }
}
