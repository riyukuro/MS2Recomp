using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;

// Text edits inside a Scaleform movie (.gfx, an SWF with a CFX/GFX signature; CFX/CWS bodies are zlib-compressed
// from byte 8). Two kinds of text are edited:
//   - the initial text of a DefineEditText (tag 37), by its character id;
//   - strings of the constant pool of a DoABC / DoABCDefine tag (82 / 72), by the hash of the original string.
// The movie is parsed into its tags (DefineSprite, tag 39, nests tags); a rebuilt tag keeps its header form (long
// headers stay long), other tags are copied byte for byte, and the file length in the header is rewritten.
sealed class Gfx {
    readonly byte[] sig;           // signature + version (4 bytes)
    readonly byte[] head;          // the uncompressed bytes from 8 to the first tag (frame rect, rate, count)
    readonly List<Tag> tags;
    readonly byte[] tail;          // bytes after the top-level End tag (past the header length): copied as is

    sealed class Tag {
        public int Code;
        public bool Long;
        public byte[] Body;
        public List<Tag> Kids;     // DefineSprite: nested tags after the 4-byte id + frame count
    }

    public static string Hash(string s) =>
        Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(s))).Substring(0, 16).ToLowerInvariant();

    public Gfx(byte[] file) {
        if (file.Length < 8) throw new InvalidDataException("not a gfx/swf file");
        var s = Encoding.ASCII.GetString(file, 0, 3);
        if (s != "CFX" && s != "GFX" && s != "CWS" && s != "FWS") throw new InvalidDataException($"signature {s}");
        sig = file[..4];
        byte[] body;
        if (s[0] == 'C') {
            using var z = new ZLibStream(new MemoryStream(file, 8, file.Length - 8), CompressionMode.Decompress);
            using var m = new MemoryStream();
            z.CopyTo(m);
            body = m.ToArray();
        } else body = file[8..];
        int nbits = body[0] >> 3;
        int p = (5 + 4 * nbits + 7) / 8 + 4;
        head = body[..p];
        tags = ReadTags(body, p, body.Length);
        int used = p;
        foreach (var t in tags) used += (t.Long || t.Body.Length >= 0x3f ? 6 : 2) + t.Body.Length;
        tail = body[Math.Min(used, body.Length)..];
    }

    static List<Tag> ReadTags(byte[] b, int p, int end) {
        var list = new List<Tag>();
        while (p + 2 <= end) {
            int cl = BitConverter.ToUInt16(b, p); p += 2;
            int code = cl >> 6, n = cl & 0x3f;
            bool lng = n == 0x3f;
            if (lng) { n = BitConverter.ToInt32(b, p); p += 4; }
            var t = new Tag { Code = code, Long = lng, Body = b[p..(p + n)] };
            if (code == 39) t.Kids = ReadTags(t.Body, 4, n);
            list.Add(t);
            p += n;
            if (code == 0) break;
        }
        return list;
    }

    static void WriteTags(List<Tag> list, MemoryStream o) {
        foreach (var t in list) {
            var body = t.Body;
            if (t.Kids != null) {
                using var m = new MemoryStream();
                m.Write(t.Body, 0, 4);
                WriteTags(t.Kids, m);
                body = m.ToArray();
            }
            if (t.Long || body.Length >= 0x3f) {
                o.Write(BitConverter.GetBytes((ushort)((t.Code << 6) | 0x3f)));
                o.Write(BitConverter.GetBytes(body.Length));
            } else o.Write(BitConverter.GetBytes((ushort)((t.Code << 6) | body.Length)));
            o.Write(body);
        }
    }

    public byte[] Bytes() {
        using var m = new MemoryStream();
        m.Write(head);
        WriteTags(tags, m);
        var body = m.ToArray();
        using var o = new MemoryStream();
        o.Write(sig);
        o.Write(BitConverter.GetBytes(8 + body.Length));
        if (sig[0] == (byte)'C') {
            using var z = new ZLibStream(o, CompressionLevel.Optimal, leaveOpen: true);
            z.Write(body); z.Write(tail);
        } else { o.Write(body); o.Write(tail); }
        return o.ToArray();
    }

    static IEnumerable<Tag> All(List<Tag> list) {
        foreach (var t in list) {
            yield return t;
            if (t.Kids != null) foreach (var k in All(t.Kids)) yield return k;
        }
    }

    // ---- DefineEditText ----

    // the offset and end (after the 0) of the initial text in a DefineEditText body, or (-1, -1) without one
    static (int, int, int) EditText(byte[] b) {
        int id = BitConverter.ToUInt16(b, 0);
        int nbits = b[2] >> 3;
        int p = 2 + (5 + 4 * nbits + 7) / 8;
        byte f1 = b[p], f2 = b[p + 1];
        p += 2;
        bool hasText = (f1 & 0x80) != 0, hasColor = (f1 & 4) != 0, hasMax = (f1 & 2) != 0, hasFont = (f1 & 1) != 0;
        bool hasFontClass = (f2 & 0x80) != 0, hasLayout = (f2 & 0x20) != 0;
        if (hasFont) p += 2;
        if (hasFontClass) p = Array.IndexOf(b, (byte)0, p) + 1;
        if (hasFont || hasFontClass) p += 2;
        if (hasColor) p += 4;
        if (hasMax) p += 2;
        if (hasLayout) p += 9;
        p = Array.IndexOf(b, (byte)0, p) + 1;   // variable name
        if (!hasText) return (id, -1, -1);
        return (id, p, Array.IndexOf(b, (byte)0, p) + 1);
    }

    static string CString(byte[] b, int st, int end) => Encoding.UTF8.GetString(b, st, end - st - 1);

    static byte[] Splice(byte[] b, int st, int end, byte[] mid) {
        var r = new byte[b.Length - (end - st) + mid.Length];
        Buffer.BlockCopy(b, 0, r, 0, st);
        Buffer.BlockCopy(mid, 0, r, st, mid.Length);
        Buffer.BlockCopy(b, end, r, st + mid.Length, b.Length - end);
        return r;
    }

    static byte[] Z(string s) => Encoding.UTF8.GetBytes(s + "\0");

    // set the initial text of the edit texts with character id <id>; the number set
    public int SetText(int id, string value) {
        int n = 0;
        foreach (var t in All(tags).Where(t => t.Code == 37)) {
            var (cid, st, end) = EditText(t.Body);
            if (cid != id) continue;
            if (st < 0) throw new InvalidDataException($"edit text {id} has no initial text");
            t.Body = Splice(t.Body, st, end, Z(value));
            n++;
        }
        return n;
    }

    // ---- DoABC constant pool ----

    static (int, int) U30(byte[] b, int p) {
        int v = 0, sh = 0;
        while (true) {
            byte x = b[p++];
            v |= (x & 0x7f) << sh;
            sh += 7;
            if ((x & 0x80) == 0) return (v, p);
        }
    }

    static void PutU30(MemoryStream m, int v) {
        do {
            byte x = (byte)(v & 0x7f);
            v >>= 7;
            if (v != 0) x |= 0x80;
            m.WriteByte(x);
        } while (v != 0);
    }

    // the abc data start of a DoABC body, and the string pool: its start, its strings, its end
    static (int, List<string>, int) Pool(byte[] b, int code) {
        int p = 0;
        if (code == 82) p = Array.IndexOf(b, (byte)0, 4) + 1;   // flags, name
        p += 4;                                                  // minor, major version
        for (int k = 0; k < 2; k++) {                            // int, uint pools
            var (cnt, q) = U30(b, p); p = q;
            for (int i = 1; i < cnt; i++) (_, p) = U30(b, p);
        }
        var (dc, r) = U30(b, p); p = r + 8 * Math.Max(0, dc - 1);   // double pool
        int start = p;
        var (sc, s) = U30(b, p); p = s;
        var list = new List<string>();
        for (int i = 1; i < sc; i++) {
            var (len, q) = U30(b, p);
            list.Add(Encoding.UTF8.GetString(b, q, len));
            p = q + len;
        }
        return (start, list, p);
    }

    // replace every pool string and edit-text initial text whose hash the table has; the number replaced
    public int ApplyTable(Dictionary<string, string> table) {
        int n = 0;
        foreach (var t in All(tags)) {
            if (t.Code == 37) {
                var (_, st, end) = EditText(t.Body);
                if (st < 0) continue;
                if (table.TryGetValue(Hash(CString(t.Body, st, end)), out var v)) {
                    t.Body = Splice(t.Body, st, end, Z(v));
                    n++;
                }
            } else if (t.Code == 82 || t.Code == 72) {
                var (start, list, end) = Pool(t.Body, t.Code);
                int hit = 0;
                for (int i = 0; i < list.Count; i++)
                    if (table.TryGetValue(Hash(list[i]), out var v)) { list[i] = v; hit++; }
                if (hit == 0) continue;
                using var m = new MemoryStream();
                PutU30(m, list.Count + 1);
                foreach (var s in list) {
                    var u = Encoding.UTF8.GetBytes(s);
                    PutU30(m, u.Length);
                    m.Write(u);
                }
                t.Body = Splice(t.Body, start, end, m.ToArray());
                n += hit;
            }
        }
        return n;
    }

    // the edit-text initial texts (id, text) and pool strings, for the selftest and for writing patches
    public List<(int, string)> Texts() =>
        All(tags).Where(t => t.Code == 37).Select(t => (t, EditText(t.Body)))
            .Where(x => x.Item2.Item2 >= 0)
            .Select(x => (x.Item2.Item1, CString(x.t.Body, x.Item2.Item2, x.Item2.Item3))).ToList();

    public List<string> Strings() =>
        All(tags).Where(t => t.Code == 82 || t.Code == 72).SelectMany(t => Pool(t.Body, t.Code).Item2).ToList();

    // ---- selftest ----

    // a small movie: an edit text (id 1) at the top, a sprite holding edit text 2, and a DoABC with a pool
    static byte[] Sample(bool compressed) {
        using var m = new MemoryStream();
        m.Write(new byte[] { 0x00, 0x00, 0x19, 0x01, 0x00 });    // rect with 0-bit fields, rate, count
        void Tag(MemoryStream o, int code, byte[] body) {
            if (body.Length >= 0x3f) {
                o.Write(BitConverter.GetBytes((ushort)((code << 6) | 0x3f)));
                o.Write(BitConverter.GetBytes(body.Length));
            }
            else o.Write(BitConverter.GetBytes((ushort)((code << 6) | body.Length)));
            o.Write(body);
        }
        byte[] Edit(int id, string text) {
            using var e = new MemoryStream();
            e.Write(BitConverter.GetBytes((ushort)id));
            e.WriteByte(0x00);                                    // rect, 0-bit fields
            e.WriteByte(0x80); e.WriteByte(0x80);                 // HasText; HasFontClass
            e.Write(Z("$Font")); e.Write(BitConverter.GetBytes((ushort)300));
            e.Write(Z(""));                                       // variable name
            e.Write(Z(text));
            return e.ToArray();
        }
        Tag(m, 37, Edit(1, "top"));
        using (var s = new MemoryStream()) {
            s.Write(BitConverter.GetBytes((ushort)9)); s.Write(BitConverter.GetBytes((ushort)1));
            Tag(s, 37, Edit(2, "inner"));
            Tag(s, 0, Array.Empty<byte>());
            Tag(m, 39, s.ToArray());
        }
        using (var a = new MemoryStream()) {
            a.Write(BitConverter.GetBytes(1)); a.Write(Z("abc"));
            a.Write(new byte[] { 16, 0, 46, 0 });                 // minor 16, major 46
            a.Write(new byte[] { 2, 5 });                         // int pool: 1 int (5)
            a.Write(new byte[] { 1 });                            // uint pool: empty
            a.Write(new byte[] { 2 }); a.Write(BitConverter.GetBytes(1.5));
            using var p = new MemoryStream();
            PutU30(p, 4);
            foreach (var s in new[] { "alpha", "beta", "top" }) {
                var u = Encoding.UTF8.GetBytes(s); PutU30(p, u.Length); p.Write(u);
            }
            a.Write(p.ToArray());
            a.Write(new byte[] { 0xAB, 0xCD });                   // the rest of the abc data, copied as is
            Tag(m, 82, a.ToArray());
        }
        Tag(m, 1, Array.Empty<byte>());
        Tag(m, 0, Array.Empty<byte>());
        var body = m.ToArray();
        using var o = new MemoryStream();
        o.Write(Encoding.ASCII.GetBytes(compressed ? "CFX" : "GFX")); o.WriteByte(10);
        o.Write(BitConverter.GetBytes(8 + body.Length));
        if (compressed) using (var z = new ZLibStream(o, CompressionLevel.Optimal, leaveOpen: true)) z.Write(body);
        else o.Write(body);
        return o.ToArray();
    }

    public static List<string> SelfTest() {
        var fails = new List<string>();
        void Check(string what, string got, string want) {
            if (got != want) fails.Add($"gfx {what}: got {got}, want {want}");
        }
        foreach (bool z in new[] { true, false }) {
            var orig = Sample(z);
            var g = new Gfx(orig);
            bool same = Convert.ToHexString(g.Bytes()) == Convert.ToHexString(orig);
            Check($"roundtrip z={z}", same || z ? "ok" : "diff", "ok");
            Check($"texts z={z}", string.Join(",", g.Texts()), "(1, top),(2, inner)");
            Check($"strings z={z}", string.Join(",", g.Strings()), "alpha,beta,top");
            Check("set inner", g.SetText(2, new string('x', 80)).ToString(), "1");   // the sprite grows past 63 bytes
            var table = new Dictionary<string, string> { [Hash("beta")] = "BETA longer", [Hash("top")] = "TOP" };
            Check("table", g.ApplyTable(table).ToString(), "3");                    // pool beta, top + edit text 1
            var back = new Gfx(g.Bytes());
            Check($"reread texts z={z}", string.Join(",", back.Texts()), $"(1, TOP),(2, {new string('x', 80)})");
            Check($"reread strings z={z}", string.Join(",", back.Strings()), "alpha,BETA longer,TOP");
            var b = back.Bytes();
            Check($"length z={z}", BitConverter.ToInt32(b, 4).ToString(), (8 + new Gfx(b).BodyLength()).ToString());
            Check("missing id", g.SetText(7, "y").ToString(), "0");
        }
        var want = Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes("top")))[..16].ToLowerInvariant();
        Check("hash", Hash("top"), want);
        return fails;
    }

    int BodyLength() {
        using var m = new MemoryStream();
        m.Write(head);
        WriteTags(tags, m);
        return (int)m.Length;
    }
}
