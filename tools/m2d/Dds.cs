using System.IO.Compression;

// Pixel edits inside an uncompressed 32-bit DDS texture (a Scaleform atlas, Resource/Gfx/<locale>/*_i<n>.dds).
// Only the form the UI atlases use is read: DDPF_RGB with alpha, 32 bits, 8-bit channel masks (BGRA or RGBA
// order), any pitch, no mip levels past the first. A blit writes the given RGBA pixels into a rectangle of the top
// level; every other byte of the file (header, padding, pixels outside the rectangle) is kept as it was, so an
// untouched texture writes back byte-identical. Compressed (DXT) or mip-mapped textures are refused.
sealed class Dds {
    readonly byte[] b;
    readonly int width, height, pitch, data;
    readonly int[] shift = new int[4];     // byte of R, G, B, A within a little-endian pixel

    public Dds(byte[] bytes) {
        if (bytes.Length < 128 || bytes[0] != 'D' || bytes[1] != 'D' || bytes[2] != 'S' || bytes[3] != ' ')
            throw new InvalidDataException("not a DDS file");
        b = (byte[])bytes.Clone();
        int I(int o) => BitConverter.ToInt32(b, o);
        height = I(12); width = I(16);
        int mips = I(28), pfFlags = I(80), bits = I(88);
        if ((pfFlags & 0x4) != 0) throw new InvalidDataException("compressed DDS (FourCC) is not supported");
        if ((pfFlags & 0x40) == 0 || (pfFlags & 0x1) == 0 || bits != 32)
            throw new InvalidDataException("only 32-bit RGB DDS with alpha is supported");
        if (mips > 1) throw new InvalidDataException("mip-mapped DDS is not supported");
        if (I(84) != 0 || (I(76) != 32)) throw new InvalidDataException("unexpected DDS pixel format");
        if ((I(8) & 0x8) != 0 && I(20) >= width * 4) pitch = I(20); else pitch = width * 4;
        data = 128;
        if ((long)data + (long)pitch * height > b.Length)
            throw new InvalidDataException("DDS is shorter than its pixels");
        for (int c = 0; c < 4; c++) {
            uint mask = (uint)I(92 + 4 * c);
            int s = System.Numerics.BitOperations.TrailingZeroCount(mask);
            if (mask == 0 || s % 8 != 0 || mask >> s != 0xff)
                throw new InvalidDataException("DDS channel masks are not 8-bit");
            shift[c] = s / 8;
        }
    }

    public int Width => width;
    public int Height => height;
    public byte[] Bytes() => (byte[])b.Clone();

    // writes w x h RGBA pixels (row by row) at (x, y)
    public void Blit(int x, int y, int w, int h, byte[] rgba) {
        if (x < 0 || y < 0 || w <= 0 || h <= 0 || x + w > width || y + h > height)
            throw new ArgumentException($"blit {w}x{h} at {x},{y} is outside the {width}x{height} texture");
        if (rgba.Length != w * h * 4) throw new ArgumentException("blit: pixel data is not w*h*4 bytes");
        for (int r = 0; r < h; r++)
            for (int c = 0; c < w; c++) {
                int o = data + (y + r) * pitch + (x + c) * 4, s = (r * w + c) * 4;
                for (int k = 0; k < 4; k++) b[o + shift[k]] = rgba[s + k];
            }
    }

    // the RGBA pixels of a rectangle (for checks)
    public byte[] Read(int x, int y, int w, int h) {
        var o = new byte[w * h * 4];
        for (int r = 0; r < h; r++)
            for (int c = 0; c < w; c++)
                for (int k = 0; k < 4; k++)
                    o[(r * w + c) * 4 + k] = b[data + (y + r) * pitch + (x + c) * 4 + shift[k]];
        return o;
    }

    // ---- a minimal PNG reader for the patch's own pixels: 8-bit RGBA or RGB, not interlaced ----
    public static (int w, int h, byte[] rgba) ReadPng(byte[] png) {
        byte[] sig = { 0x89, (byte)'P', (byte)'N', (byte)'G', 0x0d, 0x0a, 0x1a, 0x0a };
        if (png.Length < 33 || !png.AsSpan(0, 8).SequenceEqual(sig)) throw new InvalidDataException("not a PNG");
        int w = 0, h = 0, type = -1, p = 8;
        using var idat = new MemoryStream();
        int Be(int o) => (png[o] << 24) | (png[o + 1] << 16) | (png[o + 2] << 8) | png[o + 3];
        while (p + 8 <= png.Length) {
            int len = Be(p); string kind = System.Text.Encoding.ASCII.GetString(png, p + 4, 4);
            if (len < 0 || p + 12 + len > png.Length) throw new InvalidDataException("PNG chunk past the end");
            if (kind == "IHDR") {
                w = Be(p + 8); h = Be(p + 12);
                int depth = png[p + 16]; type = png[p + 17];
                if (depth != 8 || (type != 6 && type != 2) || png[p + 20] != 0)
                    throw new InvalidDataException("PNG must be 8-bit RGBA or RGB, not interlaced");
            } else if (kind == "IDAT") idat.Write(png, p + 8, len);
            else if (kind == "IEND") break;
            p += 12 + len;
        }
        if (w <= 0 || h <= 0) throw new InvalidDataException("PNG has no IHDR");
        int bpp = type == 6 ? 4 : 3, stride = w * bpp;
        idat.Position = 0;
        using var z = new ZLibStream(idat, CompressionMode.Decompress);
        var raw = new byte[(stride + 1) * h];
        int got = 0;
        while (got < raw.Length) { int k = z.Read(raw, got, raw.Length - got); if (k == 0) break; got += k; }
        if (got != raw.Length) throw new InvalidDataException("PNG pixel data is short");
        var cur = new byte[stride]; var prev = new byte[stride];
        var rgba = new byte[w * h * 4];
        for (int r = 0; r < h; r++) {
            int f = raw[r * (stride + 1)];
            Array.Copy(raw, r * (stride + 1) + 1, cur, 0, stride);
            for (int i = 0; i < stride; i++) {
                int a = i >= bpp ? cur[i - bpp] : 0, up = prev[i], ul = i >= bpp ? prev[i - bpp] : 0;
                cur[i] = f switch {
                    0 => cur[i],
                    1 => (byte)(cur[i] + a),
                    2 => (byte)(cur[i] + up),
                    3 => (byte)(cur[i] + (a + up) / 2),
                    4 => (byte)(cur[i] + Paeth(a, up, ul)),
                    _ => throw new InvalidDataException($"PNG filter {f}"),
                };
            }
            for (int c = 0; c < w; c++) {
                for (int k = 0; k < 3; k++) rgba[(r * w + c) * 4 + k] = cur[c * bpp + k];
                rgba[(r * w + c) * 4 + 3] = bpp == 4 ? cur[c * bpp + 3] : (byte)255;
            }
            (prev, cur) = (cur, prev);
        }
        return (w, h, rgba);
    }

    static int Paeth(int a, int b, int c) {
        int p = a + b - c, pa = Math.Abs(p - a), pb = Math.Abs(p - b), pc = Math.Abs(p - c);
        return pa <= pb && pa <= pc ? a : pb <= pc ? b : c;
    }

    // ---- selftest ----

    // a 6x5 BGRA texture with a pitch of 6*4 and distinct pixel values
    static byte[] Sample(bool rgbaOrder) {
        var d = new byte[128 + 6 * 5 * 4];
        void P(int o, int v) => BitConverter.GetBytes(v).CopyTo(d, o);
        "DDS "u8.ToArray().CopyTo(d, 0);
        P(4, 124); P(8, 0x100f); P(12, 5); P(16, 6); P(20, 24); P(76, 32); P(80, 0x41); P(88, 32);
        if (rgbaOrder) { P(92, 0xff); P(96, 0xff00); P(100, 0xff0000); }
        else { P(92, 0xff0000); P(96, 0xff00); P(100, 0xff); }
        P(104, unchecked((int)0xff000000)); P(108, 0x1000);
        for (int i = 128; i < d.Length; i++) d[i] = (byte)(i * 7);
        return d;
    }

    // a PNG of the given RGBA pixels with each row's filter byte (stored zlib; CRCs are not checked by ReadPng)
    static byte[] Png(int w, int h, byte[] rgba, int[] filters) {
        var raw = new MemoryStream();
        var prev = new byte[w * 4];
        for (int r = 0; r < h; r++) {
            var row = rgba.AsSpan(r * w * 4, w * 4).ToArray();
            raw.WriteByte((byte)filters[r]);
            for (int i = 0; i < row.Length; i++) {
                int a = i >= 4 ? row[i - 4] : 0, up = prev[i], ul = i >= 4 ? prev[i - 4] : 0;
                int pred = filters[r] switch { 1 => a, 2 => up, 3 => (a + up) / 2, 4 => Paeth(a, up, ul), _ => 0 };
                raw.WriteByte((byte)(row[i] - pred));
            }
            prev = row;
        }
        var z = new MemoryStream();
        using (var zs = new ZLibStream(z, CompressionLevel.Optimal, true)) zs.Write(raw.ToArray());
        var o = new MemoryStream();
        o.Write(new byte[] { 0x89, (byte)'P', (byte)'N', (byte)'G', 0x0d, 0x0a, 0x1a, 0x0a });
        void Chunk(string kind, byte[] body) {
            o.Write(new[] { (byte)(body.Length >> 24), (byte)(body.Length >> 16), (byte)(body.Length >> 8),
                (byte)body.Length });
            o.Write(System.Text.Encoding.ASCII.GetBytes(kind)); o.Write(body); o.Write(new byte[4]);
        }
        Chunk("IHDR", new byte[] { 0, 0, 0, (byte)w, 0, 0, 0, (byte)h, 8, 6, 0, 0, 0 });
        Chunk("IDAT", z.ToArray()); Chunk("IEND", Array.Empty<byte>());
        return o.ToArray();
    }

    public static List<string> SelfTest() {
        var fails = new List<string>();
        void Check(string what, string got, string want) {
            if (got != want) fails.Add($"dds {what}: got {got}, want {want}");
        }
        foreach (bool order in new[] { false, true }) {
            var orig = Sample(order);
            var d = new Dds(orig);
            bool same = Convert.ToHexString(d.Bytes()) == Convert.ToHexString(orig);
            Check($"roundtrip rgba={order}", same ? "ok" : "diff", "ok");
            var pix = new byte[2 * 3 * 4];
            for (int i = 0; i < pix.Length; i++) pix[i] = (byte)(200 + i);
            d.Blit(3, 1, 2, 3, pix);
            Check($"blit read rgba={order}", Convert.ToHexString(d.Read(3, 1, 2, 3)), Convert.ToHexString(pix));
            var after = d.Bytes(); int outside = 0;
            for (int i = 0; i < orig.Length; i++) {
                int px = i < 128 ? -1 : (i - 128) % 24 / 4, py = i < 128 ? -1 : (i - 128) / 24;
                bool inRect = px >= 3 && px < 5 && py >= 1 && py < 4;
                if (!inRect && after[i] != orig[i]) outside++;
            }
            Check($"outside kept rgba={order}", outside.ToString(), "0");
            int bOff = 128 + 1 * 24 + 3 * 4;   // first blitted pixel: R lands at the R mask's byte
            Check($"channel order rgba={order}", after[bOff + (order ? 0 : 2)].ToString(), "200");
        }
        var src = new byte[3 * 2 * 4];
        for (int i = 0; i < src.Length; i++) src[i] = (byte)(i * 37 + 5);
        foreach (int f in new[] { 0, 1, 2, 3, 4 }) {
            var (w, h, rgba) = ReadPng(Png(3, 2, src, new[] { f, f }));
            Check($"png filter {f}", $"{w}x{h} {Convert.ToHexString(rgba)}", $"3x2 {Convert.ToHexString(src)}");
        }
        try {
            new Dds(Sample(false).Select((x, i) => i == 84 ? (byte)'D' : x).ToArray());
            Check("fourcc", "read", "refused");
        }
        catch (InvalidDataException) { }
        try { new Dds(Sample(false)).Blit(5, 4, 2, 2, new byte[16]); Check("bounds", "written", "refused"); }
        catch (ArgumentException) { }
        return fails;
    }
}
