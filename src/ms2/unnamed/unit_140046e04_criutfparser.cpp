// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CRI Middleware UTF table reader (statically linked vendor code):
// table open/parse, big-endian header readers, value printer and value comparison. Names are invented from use.
// MS2-UNIT: unit_140046e04
// MS2-TOOLSET: vc9
// MS2-RANGE: 0x140046e04-0x140047430 .text$mn
#define MS2_THIS_FILE ""
#include <stdlib.h>
#include <string.h>
#pragma function(memset, memcpy, strcmp)
#pragma optimize("s", on)
#define MS2_CHECK_SIZE(T, n) typedef char T##_size_check[sizeof(T) == (n) ? 1 : -1]

// ---- unit-local types and unrecovered callees ----------------------------------------------------------------------------
struct Unk_CriUtfColumn                                         // 0x30 bytes
{
    unsigned type;                                              // +0x00 (low nibble = value type)
    unsigned pad_04[3];
    unsigned char kind;                                         // +0x10
    unsigned char flag;                                         // +0x11 (nonzero: column stores a per-row value)
    unsigned short rowOffset;                                   // +0x12
    unsigned pad_14[7];
};
MS2_CHECK_SIZE(Unk_CriUtfColumn, 0x30);

struct Unk_CriUtfHeader                                         // big-endian header decoded by FUN_1400471c8
{
    char b0;
    char b1;
    unsigned short w2;
    unsigned d4;
    unsigned d8;
    unsigned dc;
    unsigned short w10;
    unsigned short w12;
    unsigned d14;
};
MS2_CHECK_SIZE(Unk_CriUtfHeader, 0x18);

struct Unk_CriUtfInit                                           // 24-byte block copied from the caller
{
    unsigned long long q0;
    unsigned long long q1;
    unsigned long long q2;
};

struct Unk_CriUtfTable
{
    void* self;                                                 // +0x00 -> m_init
    Unk_CriUtfInit m_init;                                      // +0x08
    unsigned m_flags;                                           // +0x20
    unsigned m_pad24;
    unsigned char* m_base;                                      // +0x28
    unsigned m_size;                                            // +0x30
    unsigned m_pad34;
    unsigned char* m_p38;                                       // +0x38
    unsigned char* m_p40;                                       // +0x40
    unsigned char* m_p48;                                       // +0x48
    unsigned char* m_p50;                                       // +0x50
    unsigned short m_columnCount;                               // +0x58
    unsigned short m_w5a;                                       // +0x5a
    unsigned m_d5c;                                             // +0x5c
    Unk_CriUtfColumn* m_columns;                                // +0x60
    struct { unsigned key; unsigned pad; void* value; } m_slots[4]; // +0x68
    void* m_ctx;                                                // +0xa8
    void* m_p0b0;                                               // +0xb0
};
MS2_CHECK_SIZE(Unk_CriUtfTable, 0xb8);

struct Unk_CriUtfValue
{
    unsigned char type;                                         // +0x00
    unsigned char pad_01[7];
    union
    {
        unsigned char u8;
        char s8;
        unsigned short u16;
        short s16;
        unsigned u32;
        int s32;
        long long s64;
        float f32;
        double f64;
        const char* str;
        unsigned long long q;
        struct { unsigned short lo; unsigned short hi; } w;
    } v;                                                        // +0x08
    union
    {
        unsigned long long q;
        struct { unsigned d; unsigned short w14; unsigned short w16; };
    } v2;                                                       // +0x10
};

extern const unsigned DAT_143a48708[13];                        // value size by type
extern const char* DAT_143ba9d50;                               // version banner pointer

int FUN_140038ddc(int level, const char* msg);
int FUN_140038e24(int level, const char* code, int err);
unsigned FUN_14003afb0(Unk_CriUtfTable* table, const unsigned char* src, Unk_CriUtfColumn* column);
int FUN_140ccaae0(const char* fmt, ...);
unsigned FUN_140047158(unsigned type);
unsigned FUN_140047170(const unsigned char* src, unsigned* out);
unsigned FUN_1400471c8(const unsigned char* src, Unk_CriUtfHeader* out);

// @0x140046e04
// MS2-FUNCTIONAL: exe keeps head[] in the table home slot, reloads data from its stack slot and m_columns after the inner loop; register allocation differs
Unk_CriUtfTable* FUN_140046e04(Unk_CriUtfTable* table, void* ctx, void* unused, Unk_CriUtfColumn* columns, void* p5,
                               const unsigned char* data, unsigned size, const Unk_CriUtfInit* init, unsigned flags)
{
    unsigned head[2];
    DAT_143ba9d50 = "\nCRI UTF Retriever/PCx64 Ver.1.00.02 Build:Jan 13 2012 19:02:05\n";
    memset(table, 0, sizeof(Unk_CriUtfTable));
    table->m_p0b0 = p5;
    table->m_ctx = ctx;
    table->m_init = *init;
    table->self = &table->m_init;
    table->m_flags = flags;
    unsigned n = FUN_140047170(data, head);
    data = data + n;
    if (head[0] != 0x40555446)
    {
        FUN_140038ddc(0, "E06100301:Invalid IFF header (mismatched four_cc).");
        return 0;
    }
    if ((unsigned long long)head[1] + 8 > (unsigned long long)size)
    {
        FUN_140038ddc(0, "E06100311:Size error.");
        return 0;
    }
    table->m_size = head[1];
    table->m_base = (unsigned char*)data;
    Unk_CriUtfHeader hdr;
    n = FUN_1400471c8(data, &hdr);
    unsigned char* base = table->m_base;
    table->m_p40 = base + hdr.d8;
    data = data + n;
    table->m_p38 = base + hdr.d4;
    table->m_p48 = base + hdr.w2;
    table->m_columns = columns;
    table->m_columnCount = hdr.w10;
    table->m_p50 = base + hdr.dc + hdr.d4;
    table->m_w5a = hdr.w12;
    table->m_d5c = hdr.d14;
    if (columns == 0)
    {
        FUN_140038e24(0, "E06100302", -3);
        return 0;
    }
    for (unsigned i = 0; i < table->m_columnCount; ++i)
    {
        n = FUN_14003afb0(table, data, &table->m_columns[i]);
        data = data + n;
        unsigned sum = 0;
        Unk_CriUtfColumn* c = table->m_columns;
        for (unsigned j = 0; j < i; ++j, ++c)
        {
            if (c->flag != 0)
                sum += FUN_140047158(c->type);
        }
        table->m_columns[i].rowOffset = (unsigned short)sum;
    }
    for (int k = 0; k < 4; ++k)
    {
        table->m_slots[k].key = 0xffffffff;
        table->m_slots[k].value = 0;
    }
    return table;
}

// @0x14004702c
void FUN_14004702c(int type, const Unk_CriUtfValue* value)
{
    switch (type)
    {
    case 0:
        FUN_140ccaae0("%d", (unsigned)value->v.u8);
        break;
    case 1:
        FUN_140ccaae0("%d", (int)value->v.s8);
        break;
    case 2:
        FUN_140ccaae0("%d", (unsigned)value->v.u16);
        break;
    case 3:
        FUN_140ccaae0("%d", (int)value->v.s16);
        break;
    case 4:
        FUN_140ccaae0("%d", value->v.u32);
        break;
    case 5:
        FUN_140ccaae0("%d", value->v.u32);
        break;
    case 6:
        FUN_140ccaae0("%lld", value->v.s64);
        break;
    case 7:
        FUN_140ccaae0("%lld", value->v.s64);
        break;
    case 8:
        FUN_140ccaae0("%f", (double)value->v.f32);
        break;
    case 9:
        FUN_140ccaae0("%lf", value->v.f64);
        break;
    case 10:
        FUN_140ccaae0("%s", value->v.str);
        break;
    case 11:
        FUN_140ccaae0("%08x:%08x", value->v.u32, value->v2.d);
        break;
    case 12:
        FUN_140ccaae0("%08x-%04x-%04x-%04x-%04x%08x", (unsigned)(value->v.q >> 32), value->v.w.hi, value->v.w.lo,
                      value->v2.w16, value->v2.w14, value->v2.d);
        break;
    default:
        FUN_140ccaae0("%s", "<NOT DEFINED>");
        break;
    }
}

// @0x140047158
__declspec(noinline) inline unsigned FUN_140047158(unsigned type)
{
    if ((int)type >= 13)
        return 0;
    return DAT_143a48708[type];
}

// @0x140047170
unsigned FUN_140047170(const unsigned char* src, unsigned* out)
{
    out[0] = (src[0] << 24) | (src[1] << 16) | (src[2] << 8) | src[3];
    out[1] = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
    return 8;
}

// @0x1400471c8
unsigned FUN_1400471c8(const unsigned char* src, Unk_CriUtfHeader* out)
{
    out->b0 = ((const char*)src)[0];
    out->b1 = ((const char*)src)[1];
    out->w2 = (unsigned short)((unsigned short)src[2] << 8) | src[3];
    out->d4 = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
    out->d8 = (src[8] << 24) | (src[9] << 16) | (src[10] << 8) | src[11];
    out->dc = (src[12] << 24) | (src[13] << 16) | (src[14] << 8) | src[15];
    out->w10 = (unsigned short)((unsigned short)src[16] << 8) | src[17];
    out->w12 = (unsigned short)((unsigned short)src[18] << 8) | src[19];
    out->d14 = (src[20] << 24) | (src[21] << 16) | (src[22] << 8) | src[23];
    return 0x18;
}

// @0x1400472c0
unsigned FUN_1400472c0(const unsigned char* base, unsigned size)
{
    if (size < 0x1a)
        return 0;
    return (base[0x18] << 8) | base[0x19];
}

// @0x14004730c
int FUN_14004730c(const Unk_CriUtfValue* a, const Unk_CriUtfValue* b)
{
    unsigned char t = a->type;
    if (t != b->type)
        return 0;
    switch ((int)t)
    {
    case 0:
        if (a->v.u8 != b->v.u8)
            return 0;
        break;
    case 1:
        if (a->v.u8 != b->v.u8)
            return 0;
        break;
    case 2:
        if (a->v.s16 != b->v.s16)
            return 0;
        break;
    case 3:
        if (a->v.s16 != b->v.s16)
            return 0;
        break;
    case 4:
        if (a->v.s32 != b->v.s32)
            return 0;
        break;
    case 5:
        if (a->v.s32 != b->v.s32)
            return 0;
        break;
    case 6:
        if (a->v.q != b->v.q)
            return 0;
        break;
    case 7:
        if (a->v.q != b->v.q)
            return 0;
        break;
    case 8:
        if (a->v.f32 != b->v.f32)
            return 0;
        break;
    case 9:
        if (a->v.f64 != b->v.f64)
            return 0;
        break;
    case 10:
    {
        const char* s = a->v.str;
        if (s == 0 || b->v.str == 0)
        {
            if (s != b->v.str)
                return 0;
        }
        else if (strcmp(s, b->v.str) != 0)
        {
            return 0;
        }
        break;
    }
    case 11:
        if (a->v.q != b->v.q)
            return 0;
        if (a->v2.d != b->v2.d)
            return 0;
        break;
    case 12:
        if (a->v.q != b->v.q)
            return 0;
        if (a->v2.q != b->v2.q)
            return 0;
        break;
    }
    return 1;
}

// The M2V decoder's version entry (LAB_140047420, the first slot of unit_140047430's FUN_1400478a0 table).
// MS2-FUNCTIONAL: the version text is a literal here, not the exe's .rdata copy.
// @0x140047420
const char* FUN_140047420(void)
{
    return "\nCRI M2V/PCx64 Ver.2.076 Build:Jan 13 2012 18:29:31\n";
}

// ---- hooks ----
