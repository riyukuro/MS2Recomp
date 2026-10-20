// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Slice C of commonstruct.cpp#1: XML-field/wire helpers, wide/narrow
// token splitters, fmt StringFormat instances, and the std::vector/list/allocator COMDATs of the neighbouring slices' element types.
// MS2-UNIT: commonfiles\commonstruct.cpp#1.wc
// MS2-RANGE: 0x140274970-0x140278a30 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "commonstruct_wc.h"
#include "ms2/ms2recover.h"
#include <intrin.h>
#include "ms2/commonfiles/logstring.h"

// Slice-C functions are written as plain functions with loose (i64/pointer) types; the element types of the STL instances
// they come from are not recovered (8-byte pair, 16-byte and 0x30-byte records of the neighbouring slices).
enum Unk_WcEnum { Unk_WcEnum_0 };

// Constructor cursor of the _Construct_at_end style helpers: _Mylast write cursor at +8, allocator pointer at +0x10.
struct Unk_140277690 {
    i64 m_0;
    i64 m_cursor;
    i64 m_alloc;
};
MS2_CHECK_SIZE(Unk_140277690, 0x18);
MS2_CHECK_OFFSET(Unk_140277690, m_cursor, 8);
MS2_CHECK_OFFSET(Unk_140277690, m_alloc, 0x10);

// std::list node header: flag bytes at +0x18/+0x19, value storage at +0x1c.
struct Unk_140277000 {
    i64 m_next;
    i64 m_prev;
    char m_10[8];
    char m_isNil;
    char m_19;
    char m_1a[2];
    char m_value[1];
};
MS2_CHECK_OFFSET(Unk_140277000, m_isNil, 0x18);
MS2_CHECK_OFFSET(Unk_140277000, m_19, 0x19);
MS2_CHECK_OFFSET(Unk_140277000, m_value, 0x1c);

// Same wide log helper as commonstruct.cpp (unit-local there); this slice holds the const wchar_t* instance at 0x140274ea0.
class Unk_CommonLog : public CLogString {
public:
    template<class T> void Log(unsigned __int64 a,unsigned __int64 b,int flags,const wchar_t* format,const T& value) {
        fmt::internal::Value values[]={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(value)};
        FUN_1406535b0(a,b,flags,format,fmt::ArgList(fmt::internal::make_type(value),values));
    }
};

// @0x140274970
void FUN_140274970(Unk_CwObj* owner)
{
    CStringW text = owner->FUN_1402728f0();
    FUN_1412751b0(text, 0x14);
}
// @0x1402749c0
i64 FUN_1402749c0(i64 p) { FUN_14027d550(p); FUN_14027cf10(p); return p; }
// @0x1402749f0
i64 FUN_1402749f0(i64 p, char) { FUN_14027d560(p); FUN_14027d0b0(p); return p; }
// @0x140274a20
i64 FUN_140274a20(i64 p) { FUN_14027d570(p); FUN_14027d410(p); return p; }
// @0x140274a50
i64 FUN_140274a50(i64 p) { FUN_14027d580(p); FUN_14027d450(p); return p; }
// @0x140274a80
i64 FUN_140274a80(i64 p) { FUN_14027d590(p); FUN_14027d490(p); return p; }
// @0x140274ab0
i64 FUN_140274ab0(i64 p) { FUN_14027d5a0(p); FUN_14027d4d0(p); return p; }
// @0x140274ae0
i64 FUN_140274ae0(i64 p) { FUN_14027d5b0(p); FUN_14027d510(p); return p; }
// @0x140274b10
i64* FUN_140274b10(i64* out, i64 a, i64 b)
{
    i64* first = FUN_14027c1b0(a);
    *out = *first;
    char* second = FUN_140162f70(b);
    *(char*)(out + 1) = *second;
    return out;
}
// @0x140274b60
i64 FUN_140274b60(i64 out, i64 unused, i64 a, i64 b)
{
    FUN_14027c1c0(a);
    char* flag = FUN_140162f10(b);
    FUN_1402749f0(out, *flag);
    return out;
}
// @0x140274bb0
i64 FUN_140274bb0(i64 out, i64 unused, i64 a, i64 b)
{
    FUN_140274d60((i64*)out, a);
    return out;
}
// @0x140274c00
i64 FUN_140274c00(i64 out, i64 a)
{
    Unk_StlTag tag = {};
    FUN_140274cb0(out, tag, a);
    return out;
}
// @0x140274c50
i64* FUN_140274c50(i64* out, i64 a) { *out = FUN_14027c1f0(a); return out; }
// @0x140274c80
i64* FUN_140274c80(i64* out, i64 a) { *out = FUN_14027c360(a); return out; }
// @0x140274cb0
i64 FUN_140274cb0(i64 out, Unk_StlTag, i64 a)
{
    Unk_StlTag tag = {};
    FUN_14015e600(out, tag);
    u64 v = FUN_14027c1f0(a);
    FUN_140274c50((i64*)out, v);
    return out;
}
// @0x140274d10
i64* FUN_140274d10(i64* out, i64 a, i64 b)
{
    i64* first = FUN_14027c220(a);
    *out = *first;
    char* second = FUN_140162f70(b);
    *(char*)(out + 1) = *second;
    return out;
}
// @0x140274d60
i64* FUN_140274d60(i64* out, i64 a)
{
    i64 ref = FUN_14027c410(a);
    unsigned* value = FUN_14027c270(ref);
    *(unsigned*)out = *value;
    ((unsigned*)out)[1] = 0;
    return out;
}
// @0x140274db0
void** FUN_140274db0(void** out, void* value)
{
    out[0] = value;
    out[1] = (void*)&FUN_14027c110;
    return out;
}
// @0x140274de0
i64* FUN_140274de0(i64* out, i64 a) { *out = FUN_14027c380(a); return out; }
// @0x140274e10
i64* FUN_140274e10(i64* out, i64 a) { *out = FUN_14027c3a0(a); return out; }
// @0x140274e40
i64* FUN_140274e40(i64* out, i64 a) { *out = FUN_14027c3c0(a); return out; }
// @0x140274e70
unsigned* FUN_140274e70(unsigned* out, unsigned* src)
{
    out[0] = src[0];
    out[1] = src[1];
    return out;
}
// @0x140274ea0
// MS2-FUNCTIONAL: string-literal length N of wchar_t[N] unknown (8 assumed; bytes do not depend on it)
template void Unk_CommonLog::Log<wchar_t[8]>(unsigned __int64,unsigned __int64,int,const wchar_t*,const wchar_t (&)[8]);
// @0x140274f40
int FUN_140274f40(CStringW& text) { return _wtoi((const wchar_t*)text); }
// @0x140274f70
CString FUN_140274f70(CStringW& text) { return FUN_14016a600((const wchar_t*)text, 0); }
// @0x140274fc0
void FUN_140274fc0(CStringW& text, void* ids, const wchar_t* delims)
{
    int pos = 0;
    CStringW token = text.Tokenize(delims, pos);
    while (!token.IsEmpty()) {
        FUN_1401855a0(ids, FUN_140274f40(token));
        token = text.Tokenize(delims, pos);
    }
}
// @0x140275080
void FUN_140275080(CString& text, void* out, const char* delims)
{
    int pos = 0;
    CString token = text.Tokenize(delims, pos);
    while (!token.IsEmpty()) {
        FUN_14028b2d0(out, FUN_14015efc0(token));
        token = text.Tokenize(delims, pos);
    }
}
// @0x140275180
void FUN_140275180(CStringW& text, void* out, const wchar_t* delims)
{
    int pos = 0;
    CStringW token = text.Tokenize(delims, pos);
    while (!token.IsEmpty()) {
        FUN_14028b2d0(out, FUN_140274f70(token));
        token = text.Tokenize(delims, pos);
    }
}

// The seven wide "{0} {1}" formatter instances (CStringW first argument, second argument of the listed type).
// @0x140275280
template CStringW StringFormat<CStringW, unsigned short>(const wchar_t*, const CStringW&, const unsigned short&);
// @0x140275590
template CStringW StringFormat<CStringW, int>(const wchar_t*, const CStringW&, const int&);
// @0x1402758a0
template CStringW StringFormat<CStringW, unsigned>(const wchar_t*, const CStringW&, const unsigned&);
// @0x140275bb0
template CStringW StringFormat<CStringW, float>(const wchar_t*, const CStringW&, const float&);
// @0x140275ec0
template CStringW StringFormat<CStringW, Unk_WcEnum>(const wchar_t*, const CStringW&, const Unk_WcEnum&);
// @0x1402761d0
template CStringW StringFormat<CStringW, __int64>(const wchar_t*, const CStringW&, const __int64&);
// @0x1402764e0
template CStringW StringFormat<CStringW, bool>(const wchar_t*, const CStringW&, const bool&);

// @0x1402767f0
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
int FUN_1402767f0(void* node, const char* name, unsigned* out)
{
    if (FALSE) {
        MS2_ASSERT_AT(0xe7, FALSE);
        return 2;
    }
    int value = 0;
    int result = FUN_140873890(node, name, value);
    if (result != 0)
        return result;
    *out = value;
    return result;
}
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"

// @0x140276880
// TPtredDummy<CAtlList<TPtr<CUserLimitHistory>>>::New: operator new(0x48), zero fill, constructor 0x14027cd50.
i64 FUN_140276880()
{
    void* mem = operator new(0x48);
    i64 result;
    if (mem != 0) {
        __stosb((unsigned char*)mem, 0, 0x48);
        result = FUN_14027cd50((i64)mem);
    } else {
        result = 0;
    }
    return result;
}
// @0x1402768f0
void FUN_1402768f0(i64, i64, Unk_StlTag) {}
// @0x140276900
void FUN_140276900(i64, i64, Unk_StlTag) {}
// @0x140276910
void FUN_140276910(i64, i64, Unk_StlTag) {}
// @0x140276920
void FUN_140276920(i64 a, i64 b) { Unk_StlTag tag = {}; FUN_1402768f0(a, b, tag); }
// @0x140276960
void FUN_140276960(i64 a, i64 b) { Unk_StlTag tag = {}; FUN_140276900(a, b, tag); }
// @0x1402769a0
void FUN_1402769a0(i64 a, i64 b) { Unk_StlTag tag = {}; FUN_140276910(a, b, tag); }
// @0x1402769e0
i64 FUN_1402769e0(i64* p, i64 n, Unk_StlTag) { return *p + n * 8; }
// @0x140276a10
i64 FUN_140276a10(i64* p, i64 n, Unk_StlTag) { return n * 0x10 + *p; }
// @0x140276a40
void FUN_140276a40(i64 it, i64 n, Unk_StlTag)
{
    for (; 0 < n; n = n - 1)
        FUN_14027f550(it);
    for (; n < 0; n = n + 1)
        FUN_14027f700(it);
}
// @0x140276aa0
void FUN_140276aa0(i64 vec, i64 first, i64 last)
{
    i64 range = FUN_14027bc40(first, last);
    u64 count = FUN_1401a4580(range);
    FUN_140288c60(vec);
    u64 size = FUN_14028b430(vec);
    u64 capacity = FUN_14028a2c0(vec);
    if (capacity < count) {
        size = FUN_14028b090(vec);
        if (size < count)
            FUN_140289ea0();
        i64 grown = FUN_140286ec0(vec, count);
        i64* myfirst = FUN_140288980(vec);
        if (*myfirst != 0) {
            i64* mylast = FUN_140288ae0(vec);
            i64* myfirst2 = FUN_140288980(vec);
            FUN_1402875b0(vec, *myfirst2, *mylast);
            i64* myfirst3 = FUN_140288980(vec);
            i64 al = FUN_1402882f0(vec);
            FUN_14028a7d0(al, *myfirst3, capacity);
        }
        FUN_140286a60(vec, grown);
        i64* myfirst4 = FUN_140288980(vec);
        i64 end = FUN_14027a8c0(vec, first, last, *myfirst4);
        i64* mylast2 = FUN_140288ae0(vec);
        *mylast2 = end;
    } else if (size < count) {
        i64 mid = FUN_14027c420(first, size);
        i64* myfirst5 = FUN_140288980(vec);
        FUN_140277230(first, mid, *myfirst5);
        i64* mylast3 = FUN_140288ae0(vec);
        i64 end = FUN_14027a8c0(vec, mid, last, *mylast3);
        i64* mylast4 = FUN_140288ae0(vec);
        *mylast4 = end;
    } else {
        i64* myfirst6 = FUN_140288980(vec);
        i64 newlast = *myfirst6 + count * 8;
        i64* myfirst7 = FUN_140288980(vec);
        FUN_140277230(first, last, *myfirst7);
        i64* mylast5 = FUN_140288ae0(vec);
        FUN_1402875b0(vec, newlast, *mylast5);
        i64* mylast6 = FUN_140288ae0(vec);
        *mylast6 = newlast;
    }
}
// @0x140276d40
void FUN_140276d40(i64 vec, i64 first, i64 last)
{
    i64 range = FUN_14027bca0(first, last);
    u64 count = FUN_1401a4580(range);
    FUN_140288ce0(vec);
    u64 size = FUN_14028b540(vec);
    u64 capacity = FUN_14028a3d0(vec);
    if (capacity < count) {
        size = FUN_14028b1d0(vec);
        if (size < count)
            FUN_140289f20();
        i64 grown = FUN_140287100(vec, count);
        i64* myfirst = FUN_140288a80(vec);
        if (*myfirst != 0) {
            i64* mylast = FUN_140288be0(vec);
            i64* myfirst2 = FUN_140288a80(vec);
            FUN_1402876b0(vec, *myfirst2, *mylast);
            i64* myfirst3 = FUN_140288a80(vec);
            i64 al = FUN_1402883f0(vec);
            FUN_14028a890(al, *myfirst3, capacity);
        }
        FUN_140286b50(vec, grown);
        i64* myfirst4 = FUN_140288a80(vec);
        i64 end = FUN_14027a940(vec, first, last, *myfirst4);
        i64* mylast2 = FUN_140288be0(vec);
        *mylast2 = end;
    } else if (size < count) {
        i64 mid = FUN_14027c450(first, size);
        i64* myfirst5 = FUN_140288a80(vec);
        FUN_140277280(first, mid, *myfirst5);
        i64* mylast3 = FUN_140288be0(vec);
        i64 end = FUN_14027a940(vec, mid, last, *mylast3);
        i64* mylast4 = FUN_140288be0(vec);
        *mylast4 = end;
    } else {
        i64* myfirst6 = FUN_140288a80(vec);
        i64 newlast = count * 0x10 + *myfirst6;
        i64* myfirst7 = FUN_140288a80(vec);
        FUN_140277280(first, last, *myfirst7);
        i64* mylast5 = FUN_140288be0(vec);
        FUN_1402876b0(vec, newlast, *mylast5);
        i64* mylast6 = FUN_140288be0(vec);
        *mylast6 = newlast;
    }
}
// @0x140276fe0
i64 FUN_140276fe0(i64, i64 b, i64) { return b; }
// MS2-FUNCTIONAL: std::_Tree::_Buynode written over raw i64 node handles (element type unrecovered); the exe EH try/catch frame and temps differ
// @0x140277000
i64 FUN_140277000(i64 list, i64 a, i64 b, i64 c)
{
    i64 node = FUN_140286de0(list);
    Unk_140277000* n = (Unk_140277000*)node;
    n->m_isNil = 0;
    n->m_19 = 0;
    i64 c2 = FUN_140162f40(c);
    i64 b2 = FUN_14027c230(b);
    i64 a2 = FUN_140162ef0(a);
    i64 dest = FUN_14027b540((i64)n->m_value);
    i64 al = FUN_140288290(list);
    FUN_14027b790(al, dest, a2, b2, c2);
    return node;
}
// @0x1402770d0
i64 FUN_1402770d0(i64 list, i64 a, i64 b, i64 c)
{
    i64 node = FUN_140286d20(list, a, b);
    i64 al = FUN_140288250(list);
    i64 v = FUN_14027c1e0(c);
    i64 dest = FUN_14027b550(node + 0x10);
    FUN_14027bac0(al, dest, v);
    return node;
}
// @0x140277160
i64 FUN_140277160(i64 p) { return p; }
// @0x140277170
i64 FUN_140277170(i64 first, i64 last, i64 dest, Unk_StlTag)
{
    for (; first != last; first += 8) {
        FUN_140274e70((unsigned*)dest, (unsigned*)first);
        dest += 8;
    }
    return dest;
}
// @0x1402771d0
i64 FUN_1402771d0(i64 first, i64 last, i64 dest, Unk_StlTag)
{
    for (; first != last; first += 0x10) {
        FUN_14027eaf0(dest, first);
        dest += 0x10;
    }
    return dest;
}
// @0x140277230
void FUN_140277230(i64 first, i64 last, i64 dest)
{
    char tag = FUN_14027a520(&first, &dest);
    FUN_140277170(first, last, dest, *(Unk_StlTag*)&tag);
}
// @0x140277280
void FUN_140277280(i64 first, i64 last, i64 dest)
{
    char tag = FUN_14027a5e0(&first, &dest);
    FUN_1402771d0(first, last, dest, *(Unk_StlTag*)&tag);
}
// @0x1402772d0
void FUN_1402772d0(i64, i64, i64, Unk_StlTag) {}
// @0x1402772f0
void FUN_1402772f0(i64 first, i64 last, i64 al, Unk_StlTag)
{
    for (; first != last; first += 0x30) {
        i64 p = FUN_14027a990(first);
        FUN_14027bb90(al, p);
    }
}
// @0x140277350
void FUN_140277350(i64 first, i64 last, i64 al, Unk_StlTag)
{
    for (; first != last; first += 8) {
        i64 p = FUN_14027a9a0(first);
        FUN_14027bbc0(al, p);
    }
}
// @0x1402773b0
void FUN_1402773b0(i64 first, i64 last, i64 al, Unk_StlTag)
{
    for (; first != last; first += 0x10) {
        i64 p = FUN_14027a9b0(first);
        FUN_14027bbe0(al, p);
    }
}
// @0x140277410
void FUN_140277410(i64 first, i64 last, i64 al, Unk_StlTag)
{
    for (; first != last; first += 0x10) {
        i64 p = FUN_14027a9c0(first);
        FUN_14027bc20(al, p);
    }
}
// @0x140277470
void FUN_140277470(i64 a, i64 b, i64 c) { Unk_StlTag tag = {}; FUN_1402772d0(a, b, c, tag); }
// @0x1402774c0
void FUN_1402774c0(i64 a, i64 b, i64 c) { Unk_StlTag tag = {}; FUN_1402772f0(a, b, c, tag); }
// @0x140277510
void FUN_140277510(i64 a, i64 b, i64 c) { Unk_StlTag tag = {}; FUN_140277350(a, b, c, tag); }
// @0x140277560
void FUN_140277560(i64 a, i64 b, i64 c) { Unk_StlTag tag = {}; FUN_1402773b0(a, b, c, tag); }
// @0x1402775b0
void FUN_1402775b0(i64 a, i64 b, i64 c) { Unk_StlTag tag = {}; FUN_140277410(a, b, c, tag); }
// @0x140277600
i64 FUN_140277600(i64 a, i64 b, Unk_StlTag) { return (b - a) >> 3; }
// @0x140277630
i64 FUN_140277630(i64 a, i64 b, Unk_StlTag) { return (b - a) >> 4; }
// @0x140277660
i64 FUN_140277660(i64 a, i64 b, Unk_StlTag) { return (b - a) >> 4; }
// _Construct_at_end style element constructors: *(self+8) = write cursor, *(self+0x10) = allocator
// @0x140277690
void FUN_140277690(i64 self, i64 v)
{
    Unk_140277690* c = (Unk_140277690*)self;
    i64 a = FUN_14027c170(v);
    i64 p = FUN_14027a980(c->m_cursor);
    FUN_14027b840(c->m_alloc, p, a);
    c->m_cursor = c->m_cursor + 8;
}
// @0x1402776f0
void FUN_1402776f0(i64 self, i64 v)
{
    Unk_140277690* c = (Unk_140277690*)self;
    i64 a = FUN_14027c180(v);
    i64 p = FUN_14027a990(c->m_cursor);
    FUN_14027b890(c->m_alloc, p, a);
    c->m_cursor = c->m_cursor + 0x30;
}
// @0x140277750
void FUN_140277750(i64 self, i64 v)
{
    Unk_140277690* c = (Unk_140277690*)self;
    i64 a = FUN_140180940(v);
    i64 p = FUN_14027a9a0(c->m_cursor);
    FUN_14027b930(c->m_alloc, p, a);
    c->m_cursor = c->m_cursor + 8;
}
// @0x1402777b0
void FUN_1402777b0(i64 self, i64 v)
{
    Unk_140277690* c = (Unk_140277690*)self;
    i64 a = FUN_14027c190(v);
    i64 p = FUN_14027a9b0(c->m_cursor);
    FUN_14027b9d0(c->m_alloc, p, a);
    c->m_cursor = c->m_cursor + 0x10;
}
// @0x140277810
void FUN_140277810(i64 self, i64 v)
{
    Unk_140277690* c = (Unk_140277690*)self;
    i64 a = FUN_14027c1a0(v);
    i64 p = FUN_14027a9c0(c->m_cursor);
    FUN_14027bb10(c->m_alloc, p, a);
    c->m_cursor = c->m_cursor + 0x10;
}
// @0x140277870
void FUN_140277870(i64 self, i64 v)
{
    Unk_140277690* c = (Unk_140277690*)self;
    i64 a = FUN_14027c200(v);
    i64 p = FUN_14027a990(c->m_cursor);
    FUN_14027b8e0(c->m_alloc, p, a);
    c->m_cursor = c->m_cursor + 0x30;
}
// @0x1402778d0
void FUN_1402778d0(i64 self, i64 v)
{
    Unk_140277690* c = (Unk_140277690*)self;
    i64 a = FUN_140180c50(v);
    i64 p = FUN_14027a9a0(c->m_cursor);
    FUN_14027b980(c->m_alloc, p, a);
    c->m_cursor = c->m_cursor + 8;
}
// @0x140277930
void FUN_140277930(i64 self, i64 v)
{
    Unk_140277690* c = (Unk_140277690*)self;
    i64 a = FUN_14027c210(v);
    i64 p = FUN_14027a9b0(c->m_cursor);
    FUN_14027ba70(c->m_alloc, p, a);
    c->m_cursor = c->m_cursor + 0x10;
}
// emplace_back with the capacity checks done: construct at _Mylast and bump it
// @0x140277990
void FUN_140277990(i64 vec, i64 v)
{
    i64 a = FUN_14027c1d0(v);
    i64* mylast = FUN_140288ba0(vec);
    i64 p = FUN_14027a9b0(*mylast);
    i64 al = FUN_1402883b0(vec);
    FUN_14027ba20(al, p, a);
    i64* mylast2 = FUN_140288ba0(vec);
    i64* mylast3 = FUN_140288ba0(vec);
    FUN_140288d20(vec, *mylast3, *mylast2);
    FUN_140288ba0(vec);
    i64* mylast4 = FUN_140288ba0(vec);
    *mylast4 = *mylast4 + 0x10;
}
// @0x140277a50
void FUN_140277a50(i64 vec, i64 v)
{
    i64 a = FUN_14027c200(v);
    i64* mylast = FUN_140288b20(vec);
    i64 p = FUN_14027a990(*mylast);
    i64 al = FUN_140288330(vec);
    FUN_14027b8e0(al, p, a);
    i64* mylast2 = FUN_140288b20(vec);
    i64* mylast3 = FUN_140288b20(vec);
    FUN_140288d00(vec, *mylast3, *mylast2);
    FUN_140288b20(vec);
    i64* mylast4 = FUN_140288b20(vec);
    *mylast4 = *mylast4 + 0x30;
}
// @0x140277b10
void FUN_140277b10(i64 vec, i64 v)
{
    i64 a = FUN_140180c50(v);
    i64* mylast = FUN_140288b60(vec);
    i64 p = FUN_14027a9a0(*mylast);
    i64 al = FUN_140288370(vec);
    FUN_14027b980(al, p, a);
    i64* mylast2 = FUN_140288b60(vec);
    i64* mylast3 = FUN_140288b60(vec);
    FUN_140288d10(vec, *mylast3, *mylast2);
    FUN_140288b60(vec);
    i64* mylast4 = FUN_140288b60(vec);
    *mylast4 = *mylast4 + 8;
}
// @0x140277bd0
void FUN_140277bd0(i64 vec, i64 v)
{
    i64 a = FUN_14027c210(v);
    i64* mylast = FUN_140288ba0(vec);
    i64 p = FUN_14027a9b0(*mylast);
    i64 al = FUN_1402883b0(vec);
    FUN_14027ba70(al, p, a);
    i64* mylast2 = FUN_140288ba0(vec);
    i64* mylast3 = FUN_140288ba0(vec);
    FUN_140288d20(vec, *mylast3, *mylast2);
    FUN_140288ba0(vec);
    i64* mylast4 = FUN_140288ba0(vec);
    *mylast4 = *mylast4 + 0x10;
}
// _Emplace_reallocate: grow, construct the new element at the insertion point, move the two halves, swap buffers
// MS2-FUNCTIONAL: vector::_Emplace_reallocate (16-byte elements) over raw i64 handles; the exe try/catch frame differs (element type unrecovered)
// @0x140277c90
i64 FUN_140277c90(i64 vec, i64 where, i64 v)
{
    i64* myfirst = FUN_140288a40(vec);
    i64 off = (where - *myfirst) >> 4;
    i64 al = FUN_1402883b0(vec);
    i64 size = FUN_14028b500(vec);
    i64 maxsize = FUN_14028b180(vec);
    if (size == maxsize)
        FUN_140289f00();
    u64 newcap = FUN_140287070(vec, size + 1);
    i64 newvec = FUN_14028a050(al, newcap);
    i64 slot = FUN_14027a9b0(newvec + off * 0x10);
    i64 a = FUN_14027c1d0(v);
    FUN_14027ba20(al, slot, a);
    i64 slotp = newvec + off * 0x10;
    i64* mylast = FUN_140288ba0(vec);
    if (where == *mylast) {
        i64* mylast2 = FUN_140288ba0(vec);
        i64* myfirst2 = FUN_140288a40(vec);
        FUN_140289cc0(vec, *myfirst2, *mylast2, newvec);
    } else {
        i64* myfirst3 = FUN_140288a40(vec);
        FUN_140289b00(vec, *myfirst3, where, newvec, newvec, off, slotp);
        slotp = newvec + off * 0x10 + 0x10;
        i64 base = newvec;
        i64* mylast3 = FUN_140288ba0(vec);
        FUN_140289b00(vec, where, *mylast3, slotp, newvec, off, base);
    }
    FUN_1402873b0(vec, newvec, size + 1, newcap);
    i64* myfirst4 = FUN_140288a40(vec);
    return off * 0x10 + *myfirst4;
}
// MS2-FUNCTIONAL: vector::_Emplace_reallocate (0x30-byte elements) over raw i64 handles; the exe try/catch frame differs (element type unrecovered)
// @0x140277ee0
i64 FUN_140277ee0(i64 vec, i64 where, i64 v)
{
    i64* myfirst = FUN_1402889c0(vec);
    i64 off = (where - *myfirst) / 0x30;
    i64 al = FUN_140288330(vec);
    i64 size = FUN_14028b470(vec);
    i64 maxsize = FUN_14028b0e0(vec);
    if (size == maxsize)
        FUN_140289ec0();
    u64 newcap = FUN_140286f50(vec, size + 1);
    i64 newvec = FUN_140289ff0(al, newcap);
    i64 slot = FUN_14027a990(newvec + off * 0x30);
    i64 a = FUN_14027c200(v);
    FUN_14027b8e0(al, slot, a);
    i64 slotp = newvec + off * 0x30;
    i64* mylast = FUN_140288b20(vec);
    if (where == *mylast) {
        i64* mylast2 = FUN_140288b20(vec);
        i64* myfirst2 = FUN_1402889c0(vec);
        FUN_140289c00(vec, *myfirst2, *mylast2, newvec);
    } else {
        i64* myfirst3 = FUN_1402889c0(vec);
        FUN_140289a80(vec, *myfirst3, where, newvec, newvec, off, slotp);
        slotp = newvec + off * 0x30 + 0x30;
        i64 base = newvec;
        i64* mylast3 = FUN_140288b20(vec);
        FUN_140289a80(vec, where, *mylast3, slotp, newvec, off, base);
    }
    FUN_140287190(vec, newvec, size + 1, newcap);
    i64* myfirst4 = FUN_1402889c0(vec);
    return off * 0x30 + *myfirst4;
}
// MS2-FUNCTIONAL: vector::_Emplace_reallocate (8-byte elements) over raw i64 handles; the exe try/catch frame differs (element type unrecovered)
// @0x140278130
i64 FUN_140278130(i64 vec, i64 where, i64 v)
{
    i64* myfirst = FUN_140288a00(vec);
    i64 off = (where - *myfirst) >> 3;
    i64 al = FUN_140288370(vec);
    i64 size = FUN_14028b4c0(vec);
    i64 maxsize = FUN_14028b130(vec);
    if (size == maxsize)
        FUN_140289ee0();
    u64 newcap = FUN_140286fe0(vec, size + 1);
    i64 newvec = FUN_14028a020(al, newcap);
    i64 slot = FUN_14027a9a0(newvec + off * 8);
    i64 a = FUN_140180c50(v);
    FUN_14027b980(al, slot, a);
    i64 slotp = newvec + off * 8;
    i64* mylast = FUN_140288b60(vec);
    if (where == *mylast) {
        i64* mylast2 = FUN_140288b60(vec);
        i64* myfirst2 = FUN_140288a00(vec);
        FUN_140289c60(vec, *myfirst2, *mylast2, newvec);
    } else {
        i64* myfirst3 = FUN_140288a00(vec);
        FUN_140289ac0(vec, *myfirst3, where, newvec, newvec, off, slotp);
        slotp = newvec + 8;
        i64 offbytes = off * 8;
        i64 base = newvec;
        i64* mylast3 = FUN_140288b60(vec);
        FUN_140289ac0(vec, where, *mylast3, slotp + offbytes, newvec, off, base);
    }
    FUN_1402872a0(vec, newvec, size + 1, newcap);
    i64* myfirst4 = FUN_140288a00(vec);
    return *myfirst4 + off * 8;
}
// MS2-FUNCTIONAL: vector::_Emplace_reallocate (16-byte elements) over raw i64 handles; the exe try/catch frame differs (element type unrecovered)
// @0x140278370
i64 FUN_140278370(i64 vec, i64 where, i64 v)
{
    i64* myfirst = FUN_140288a40(vec);
    i64 off = (where - *myfirst) >> 4;
    i64 al = FUN_1402883b0(vec);
    i64 size = FUN_14028b500(vec);
    i64 maxsize = FUN_14028b180(vec);
    if (size == maxsize)
        FUN_140289f00();
    u64 newcap = FUN_140287070(vec, size + 1);
    i64 newvec = FUN_14028a050(al, newcap);
    i64 slot = FUN_14027a9b0(newvec + off * 0x10);
    i64 a = FUN_14027c210(v);
    FUN_14027ba70(al, slot, a);
    i64 slotp = newvec + off * 0x10;
    i64* mylast = FUN_140288ba0(vec);
    if (where == *mylast) {
        i64* mylast2 = FUN_140288ba0(vec);
        i64* myfirst2 = FUN_140288a40(vec);
        FUN_140289cc0(vec, *myfirst2, *mylast2, newvec);
    } else {
        i64* myfirst3 = FUN_140288a40(vec);
        FUN_140289b00(vec, *myfirst3, where, newvec, newvec, off, slotp);
        slotp = newvec + off * 0x10 + 0x10;
        i64 base = newvec;
        i64* mylast3 = FUN_140288ba0(vec);
        FUN_140289b00(vec, where, *mylast3, slotp, newvec, off, base);
    }
    FUN_1402873b0(vec, newvec, size + 1, newcap);
    i64* myfirst4 = FUN_140288a40(vec);
    return off * 0x10 + *myfirst4;
}
// node free: destroy the two (three) pointer members, then deallocate the node
// @0x1402785c0
void FUN_1402785c0(i64, i64 node)
{
    i64 al;
    i64 p = FUN_14027b520(node);
    FUN_14027bb60(&al, p);
    p = FUN_14027b520(node + 8);
    FUN_14027bb60(&al, p);
    FUN_14028a710(&al, node, 1);
}
// @0x140278630
void FUN_140278630(i64, i64 node)
{
    i64 al;
    i64 p = FUN_14027b530(node);
    FUN_14027bb70(&al, p);
    p = FUN_14027b530(node + 8);
    FUN_14027bb70(&al, p);
    p = FUN_14027b530(node + 0x10);
    FUN_14027bb70(&al, p);
    FUN_14028a740(&al, node, 1);
}
// @0x1402786c0
u64 FUN_1402786c0(u64 count)
{
    const u64 limit = 0x1fffffffffffffffULL;
    u64 bytes = count << 3;
    if (limit < count)
        bytes = (u64)-1;
    return bytes;
}
// @0x140278710
i64 FUN_140278710(i64 p) { return p; }
// @0x140278720
i64 FUN_140278720(i64 p) { return p; }
// @0x140278730
i64 FUN_140278730(i64 p) { return p; }
// @0x140278740
i64 FUN_140278740(i64 p) { return p; }
// @0x140278750
i64 FUN_140278750(i64 p) { return p; }
// @0x140278760
void FUN_140278760(i64 p) { FUN_140289e90(p); }
// @0x140278780
i64 FUN_140278780(i64 p, i64) { return p; }
// @0x140278790
i64 FUN_140278790(i64 p, i64) { return p; }
// @0x1402787a0
i64 FUN_1402787a0(i64 p, i64) { return p; }
// @0x1402787b0
i64 FUN_1402787b0(i64 p, i64) { return p; }
// @0x1402787c0
i64 FUN_1402787c0(i64 p, i64) { return p; }
// @0x1402787d0
i64 FUN_1402787d0(i64* a, i64* b, Unk_StlTag) { return (*b - *a) >> 3; }
// @0x140278800
i64 FUN_140278800(i64* a, i64* b, Unk_StlTag) { return (*b - *a) / 0x30; }
// @0x140278830
i64 FUN_140278830(i64* a, i64* b, Unk_StlTag) { return (*b - *a) >> 3; }
// @0x140278860
i64 FUN_140278860(i64* a, i64* b, Unk_StlTag) { return (*b - *a) >> 4; }
// @0x140278890
i64 FUN_140278890(i64* a, i64* b, Unk_StlTag) { return (*b - *a) >> 4; }
// @0x1402788c0
i64 FUN_1402788c0(i64* a, i64* b) { Unk_StlTag tag; return FUN_1402787d0(a, b, tag); }
// @0x1402788f0
i64 FUN_1402788f0(i64* a, i64* b) { Unk_StlTag tag; return FUN_140278800(a, b, tag); }
// @0x140278920
i64 FUN_140278920(i64* a, i64* b) { Unk_StlTag tag; return FUN_140278830(a, b, tag); }
// @0x140278950
i64 FUN_140278950(i64* a, i64* b) { Unk_StlTag tag; return FUN_140278860(a, b, tag); }
// @0x140278980
i64 FUN_140278980(i64* a, i64* b) { Unk_StlTag tag; return FUN_140278890(a, b, tag); }
// @0x1402789b0
void FUN_1402789b0(i64 al, i64 list, i64 v)
{
    i64* where = *(i64**)(list + 8);
    i64 a = FUN_14027c1e0(v);
    i64 node = FUN_1402770d0(al, list, (i64)where, a);
    FUN_140288560(al, 1);
    *(i64*)(list + 8) = node;
    *where = node;
}
