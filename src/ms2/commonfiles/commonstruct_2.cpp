// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 2 of commonstruct.cpp: the COMDAT tail 0x14027b180-0x14027f2d0
// (STL/ATL/fmt template instances of the element types used by commonstruct.cpp, loose-typed like the other slices).
// MS2-UNIT: commonfiles\commonstruct.cpp#2
// MS2-RANGE: 0x14027b180-0x14027f2d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/commonstruct_wb.h"
#include "ms2/commonfiles/commonstruct_backout.h"
#include "ms2/placeholder/billboardinfo.h"
#include "ms2/placeholder/cclienthardwareinfo.h"
#include <new>
#include <sstream>

typedef __int64 i64;
typedef unsigned __int64 u64;
struct Unk_StlTag {};

// ---- callees outside this part (exe-bound by name) ----
struct Unk_Q8 { i64 v; };
struct Unk_PairMember { char c; };
struct Unk_PairHolder { Unk_PairMember pair; };
Unk_Q8* FUN_14027d650(Unk_Q8*, Unk_Q8*);
Unk_Q8* FUN_140163dc0(Unk_Q8*, Unk_Q8*);
i64 FUN_140278730(i64); i64 FUN_140278740(i64);
i64 FUN_1402787a0(i64, i64); i64 FUN_1402787b0(i64, i64);
i64 FUN_140278920(i64*, i64*); i64 FUN_140278950(i64*, i64*);
char FUN_14027a640(i64*, i64*); char FUN_14027a670(i64*, i64*);
char* FUN_140177620(char*, char*);
void FUN_14027a6e0(i64*, i64); void FUN_14027a700(i64*, i64);
i64 FUN_140277870(void*, i64); i64 FUN_1402778d0(void*, i64); i64 FUN_140277930(void*, i64);
i64 FUN_1402890b0(void*); i64 FUN_1402890d0(void*); i64 FUN_1402890f0(void*);
void FUN_1402774c0(i64, i64, i64); void FUN_140277470(i64, i64, i64);
void FUN_140277510(i64, i64, i64); void FUN_140277560(i64, i64, i64); void FUN_1402775b0(i64, i64, i64);

i64 FUN_14027c3e0(i64); i64 FUN_14027c3f0(i64); i64 FUN_14027c400(i64);
i64 FUN_14027b440(i64, i64, i64, i64, char, char);
i64 FUN_14027b3b0(i64, i64, i64, i64, char, char);

// @0x14027b180
// std::_Uninitialized_copy(first, last, dest, al)
i64 FUN_14027b180(i64 first, i64 last, i64 dest, i64 al)
{
    i64 f = FUN_140278730(first);
    i64 l = FUN_140278730(last);
    i64 d = FUN_1402787a0(dest, FUN_140278920(&f, &l));
    char tag1;
    char pad;
    char* p = &tag1;
    char t = FUN_14027a640(&f, &d);
    FUN_14027a6e0(&dest, FUN_14027b3b0(f, l, d, al, t, *FUN_140177620(p, &pad)));
    return dest;
}

// @0x14027b250
// std::_Uninitialized_copy(first, last, dest, al)
i64 FUN_14027b250(i64 first, i64 last, i64 dest, i64 al)
{
    i64 f = FUN_140278740(first);
    i64 l = FUN_140278740(last);
    i64 d = FUN_1402787b0(dest, FUN_140278950(&f, &l));
    char tag1;
    char pad;
    char* p = &tag1;
    char t = FUN_14027a670(&f, &d);
    FUN_14027a700(&dest, FUN_14027b440(f, l, d, al, t, *FUN_140177620(p, &pad)));
    return dest;
}

i64 FUN_140277870(void*, i64);
i64 FUN_1402769e0(i64*, i64, Unk_StlTag);
i64 FUN_140276a10(i64*, i64, Unk_StlTag);
i64 FUN_140276a40(i64, i64, Unk_StlTag);
i64 FUN_140276920(i64*, i64*); i64 FUN_140276960(i64*, i64*);
i64 FUN_140276aa0(i64, i64, i64, Unk_StlTag); i64 FUN_140276d40(i64, i64, i64, Unk_StlTag);
i64 FUN_140278710(i64); i64 FUN_140278750(i64);

// @0x14027b320
i64 FUN_14027b320(i64 first, i64 last, i64 dest, i64 al)
{
    Unk_BackoutB bo(dest, al);
    for (; first != last; first += 0x30)
        FUN_140277870(&bo, FUN_14027c3e0(first));
    return FUN_1402890b0(&bo);
}
// @0x14027b3b0
i64 FUN_14027b3b0(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutC bo(dest, al);
    for (; first != last; first += 8)
        FUN_1402778d0(&bo, FUN_14027c3f0(first));
    return FUN_1402890d0(&bo);
}
// @0x14027b440
i64 FUN_14027b440(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutD bo(dest, al);
    for (; first != last; first += 0x10)
        FUN_140277930(&bo, FUN_14027c400(first));
    return FUN_1402890f0(&bo);
}
// @0x14027b4d0
i64 FUN_14027b4d0(i64 p) { return p; }
// @0x14027b4e0
i64 FUN_14027b4e0(i64 p) { return p; }
// @0x14027b4f0
i64 FUN_14027b4f0(i64 p) { return p; }
// @0x14027b500
i64 FUN_14027b500(i64 p) { return p; }
// @0x14027b510
i64 FUN_14027b510(i64 p) { return p; }
// @0x14027b520
i64 FUN_14027b520(i64 p) { return p; }
// @0x14027b530
i64 FUN_14027b530(i64 p) { return p; }
// @0x14027b540
i64 FUN_14027b540(i64 p) { return p; }
// @0x14027b550
i64 FUN_14027b550(i64 p) { return p; }
// @0x14027b560
i64 FUN_14027b560(i64 p) { return p; }
// @0x14027b570
i64 FUN_14027b570(i64 p) { return p; }
// @0x14027b580
i64 FUN_14027b580(i64 p) { return p; }
// @0x14027b590
i64 FUN_14027b590(i64 p) { return p; }
// @0x14027b5a0
i64 FUN_14027b5a0(i64* p, i64 n) { Unk_StlTag t; return FUN_1402769e0(p, n, t); }
// @0x14027b5d0
i64 FUN_14027b5d0(i64* p, i64 n) { Unk_StlTag t; return FUN_140276a10(p, n, t); }
// @0x14027b600
i64 FUN_14027b600(i64 p, i64 n) { Unk_StlTag t; return FUN_140276a40(p, n, t); }
// @0x14027b630
i64 FUN_14027b630(i64 a, i64 b, i64 c)
{
    Unk_StlTag t;
    FUN_140276920(&b, &c);
    return FUN_140276aa0(a, FUN_140278710(b), FUN_140278710(c), t);
}
// @0x14027b690
i64 FUN_14027b690(i64 a, i64 b, i64 c)
{
    Unk_StlTag t;
    FUN_140276960(&b, &c);
    return FUN_140276d40(a, FUN_140278750(b), FUN_140278750(c), t);
}

// ---- element construct/destroy helpers (std::allocator_traits<>::construct/destroy of the element types) ----
struct Unk_P8 { i64 v; };
struct Unk_Ref16 { void* m_unknown; void* m_p; };
struct Unk_Tup8 { i64 v; };
i64 FUN_14027c140(i64); i64 FUN_14027c150(i64); i64 FUN_14027c170(i64); i64 FUN_14027c180(i64); i64 FUN_14027c200(i64);
i64 FUN_14027c190(i64); i64 FUN_14027c1d0(i64); i64 FUN_14027c210(i64); i64 FUN_14027c1e0(i64); i64 FUN_14027c1a0(i64);
i64 FUN_14027c230(i64); i64 FUN_14027c1f0(i64);
i64 FUN_140180940(i64); i64 FUN_140180c50(i64);
i64 FUN_140162f40(i64); i64 FUN_140162ef0(i64);

Unk_Q8* FUN_14027d650(Unk_Q8*, Unk_Q8*);
void FUN_140274bb0(void*, char, i64, i64);
Unk_Ref16* FUN_14027c980(Unk_Ref16*, Unk_Ref16*);
Unk_Ref16* FUN_14027ccb0(Unk_Ref16*, Unk_Ref16*);
Unk_Ref16* FUN_14027c9b0(Unk_Ref16*, Unk_Ref16*);
Unk_Ref16* FUN_14027cc30(Unk_Ref16*, Unk_Ref16*);

// @0x14027b6f0
void FUN_14027b6f0(i64 al, i64 where, i64 src) { ::new((void*)where) i64(*(i64*)FUN_14027c140(src)); }
// @0x14027b740
void FUN_14027b740(i64 al, i64 where, i64 src) { ::new((void*)where) i64(*(i64*)FUN_14027c150(src)); }
// MS2-FUNCTIONAL: pair<const unsigned,int> piecewise construct; the exe is one new-expression calling the pair ctor 0x140274bb0 with by-value tuple temporaries (frame slots differ; 0x140274bb0 is a free function in commonstruct_wc)
// @0x14027b790
void FUN_14027b790(i64 al, i64 where, i64 a2, i64 b2, i64 c2)
{
    Unk_P8* mem = (Unk_P8*)operator new(8, (void*)where);
    Unk_Q8 first, second;
    Unk_Q8* p28 = &first;
    Unk_Q8* p30 = &second;
    FUN_140274bb0(mem, *(char*)FUN_140162ef0(a2), (i64)FUN_14027d650(p30, (Unk_Q8*)FUN_14027c230(b2)),
                  (i64)FUN_140163dc0(p28, (Unk_Q8*)FUN_140162f40(c2)));
}
// @0x14027b840
void FUN_14027b840(i64 al, i64 where, i64 src) { ::new((void*)where) Unk_P8(*(Unk_P8*)FUN_14027c170(src)); }
// @0x14027b890
void FUN_14027b890(i64 al, i64 where, i64 src) { ::new((void*)where) ItemEntity(*(ItemEntity*)FUN_14027c180(src)); }
// @0x14027b8e0
void FUN_14027b8e0(i64 al, i64 where, i64 src) { ::new((void*)where) ItemEntity((ItemEntity&&)*(ItemEntity*)FUN_14027c200(src)); }
// @0x14027b930
void FUN_14027b930(i64 al, i64 where, i64 src) { ::new((void*)where) CString(*(CString*)FUN_140180940(src)); }
// @0x14027b980
void FUN_14027b980(i64 al, i64 where, i64 src) { ::new((void*)where) CString(*(CString*)FUN_140180c50(src)); }
// @0x14027b9d0
void FUN_14027b9d0(i64 al, i64 where, i64 src) { FUN_14027c9b0(::new((void*)where) Unk_Ref16, (Unk_Ref16*)FUN_14027c190(src)); }
// @0x14027ba20
void FUN_14027ba20(i64 al, i64 where, i64 src) { FUN_14027c9b0(::new((void*)where) Unk_Ref16, (Unk_Ref16*)FUN_14027c1d0(src)); }
// @0x14027ba70
void FUN_14027ba70(i64 al, i64 where, i64 src) { FUN_14027c980(::new((void*)where) Unk_Ref16, (Unk_Ref16*)FUN_14027c210(src)); }
// @0x14027bac0
void FUN_14027bac0(i64 al, i64 where, i64 src) { FUN_14027cc30(::new((void*)where) Unk_Ref16, (Unk_Ref16*)FUN_14027c1e0(src)); }
// @0x14027bb10
void FUN_14027bb10(i64 al, i64 where, i64 src) { FUN_14027ccb0(::new((void*)where) Unk_Ref16, (Unk_Ref16*)FUN_14027c1a0(src)); }
// @0x14027bb60
void FUN_14027bb60(i64*, i64) {}
// @0x14027bb70
void FUN_14027bb70(i64*, i64) {}
// @0x14027bb80
void FUN_14027bb80(i64*, i64) {}

// virtual-destructor element destroy (slot 0 = scalar deleting dtor, called with flag 0)
struct Unk_VDtor { virtual ~Unk_VDtor(); };
void FUN_140164fb0(i64, int); void FUN_14027f8b0(i64, int); void FUN_14027f8f0(i64, int); void FUN_14027f930(i64, int);
// @0x14027bb90
void FUN_14027bb90(i64 al, Unk_VDtor* p) { p->~Unk_VDtor(); }
// @0x14027bbc0
void FUN_14027bbc0(i64 al, i64 p) { FUN_140164fb0(p, 0); }
// @0x14027bbe0
void FUN_14027bbe0(i64 al, i64 p) { FUN_14027f8b0(p, 0); }
// @0x14027bc00
void FUN_14027bc00(i64 al, i64 p) { FUN_14027f8f0(p, 0); }
// @0x14027bc20
void FUN_14027bc20(i64 al, i64 p) { FUN_14027f930(p, 0); }

i64 FUN_140277600(i64, i64, Unk_StlTag); i64 FUN_140277630(i64, i64, Unk_StlTag); i64 FUN_140277660(i64, i64, Unk_StlTag);
// @0x14027bc40
i64 FUN_14027bc40(i64 first, i64 last) { Unk_StlTag t; return FUN_140277600(first, last, t); }
// @0x14027bc70
i64 FUN_14027bc70(i64 first, i64 last) { Unk_StlTag t; return FUN_140277630(first, last, t); }
// @0x14027bca0
i64 FUN_14027bca0(i64 first, i64 last) { Unk_StlTag t; return FUN_140277660(first, last, t); }

// vector::push_back(const T&) bodies: construct at end when it has room, otherwise reallocate
bool FUN_140288510(i64); bool FUN_140288470(i64); bool FUN_1402884c0(i64);
void FUN_140277990(i64, i64); void FUN_140277a50(i64, i64); void FUN_140277b10(i64, i64); void FUN_140277bd0(i64, i64);
i64* FUN_140288ba0(i64); i64* FUN_140288b20(i64); i64* FUN_140288b60(i64);
i64 FUN_140277c90(i64, i64, i64); i64 FUN_140277ee0(i64, i64, i64); i64 FUN_140278130(i64, i64, i64); i64 FUN_140278370(i64, i64, i64);
// @0x14027bcd0
void FUN_14027bcd0(i64 vec, i64 val)
{
    if (FUN_140288510(vec)) {
        FUN_140277990(vec, FUN_14027c1d0(val));
    } else {
        i64 r = FUN_140277c90(vec, *FUN_140288ba0(vec), FUN_14027c1d0(val));
    }
}
// @0x14027bd40
void FUN_14027bd40(i64 vec, i64 val)
{
    if (FUN_140288470(vec)) {
        FUN_140277a50(vec, FUN_14027c200(val));
    } else {
        i64 r = FUN_140277ee0(vec, *FUN_140288b20(vec), FUN_14027c200(val));
    }
}
// @0x14027bdb0
void FUN_14027bdb0(i64 vec, i64 val)
{
    if (FUN_1402884c0(vec)) {
        FUN_140277b10(vec, FUN_140180c50(val));
    } else {
        i64 r = FUN_140278130(vec, *FUN_140288b60(vec), FUN_140180c50(val));
    }
}
// @0x14027be20
void FUN_14027be20(i64 vec, i64 val)
{
    if (FUN_140288510(vec)) {
        FUN_140277bd0(vec, FUN_14027c210(val));
    } else {
        i64 r = FUN_140278370(vec, *FUN_140288ba0(vec), FUN_14027c210(val));
    }
}

// _Tree::emplace_hint(where, piecewise_construct, tuple<K&&>, tuple<>)
i64 FUN_140277000(i64, i64, i64, i64); void FUN_140278d90(i64, i64, i64, i64, i64);
// @0x14027be90
i64 FUN_14027be90(i64 tree, i64 out, i64 where, i64 piecewise, i64 keytuple, i64 valtuple)
{
    i64 node = FUN_140277000(tree, FUN_140162ef0(piecewise), FUN_14027c230(keytuple), FUN_140162f40(valtuple));
    FUN_140278d90(tree, out, where, node + 0x1c, node);
    return out;
}

// std::find_if over a vector<Unk_IngRef> with a by-value predicate argument
i64 FUN_1402769a0(i64*, i64*); i64 FUN_140278760(i64*); void FUN_14027a740(i64*, i64*);
bool FUN_14026b560(int*, Unk_Ref16*);
// @0x14027bf30
i64* FUN_14027bf30(i64* out, i64 first, i64 last, int key)
{
    FUN_1402769a0(&first, &last);
    i64 f = FUN_140278760(&first);
    i64 l = FUN_140278760(&last);
    for (; f != l; f += 0x10) {
        Unk_Ref16 slot;
        Unk_Ref16* tmp = &slot;
        Unk_Ref16* copy = FUN_14027c9b0(tmp, (Unk_Ref16*)f);
        if (FUN_14026b560(&key, copy))
            break;
    }
    FUN_14027a740(&first, &f);
    *out = first;
    return out;
}

// fmt::internal::MakeValue<BasicFormatter<wchar_t>>(const int&): the generic ostream-formatted argument (type 0xa)
struct Unk_FmtVal { i64 w0, w1; int type; };
struct Unk_Str16 { i64 w0, w1; };
Unk_Str16* FUN_140182090(Unk_Str16*, const std::wstring&);
i64 FUN_1402da110(i64, i64*, Unk_FmtVal*);
// @0x14027bff0
// MS2-FUNCTIONAL: uses the standard wostringstream/wstring; the exe calls its own out-of-line stream ctor/dtor and str() instances
void FUN_14027bff0(i64 ctx, i64* out, int* value)
{
    Unk_FmtVal v;
    Unk_FmtVal* pv = &v;
    if (0 == 1) {
        std::wostringstream oss;
        oss << *value;
        std::wstring text = oss.str();
        Unk_Str16 packed;
        *(Unk_Str16*)pv = *FUN_140182090(&packed, text);
        v.type = 10;
    } else {
        *(int*)pv = *value;
        v.type = 1;
    }
    *out = FUN_1402da110(ctx, out, &v);
}
// @0x14027c110
void FUN_14027c110(i64 ctx, i64 value, i64* out) { FUN_14027bff0(ctx, out, (int*)value); }

// pass-through helpers (std::forward / std::move / addressof of one element type each)
// @0x14027c140
i64 FUN_14027c140(i64 p) { return p; }
// @0x14027c150
i64 FUN_14027c150(i64 p) { return p; }
// @0x14027c160
i64 FUN_14027c160(i64 p) { return p; }
// @0x14027c170
i64 FUN_14027c170(i64 p) { return p; }
// @0x14027c180
i64 FUN_14027c180(i64 p) { return p; }
// @0x14027c190
i64 FUN_14027c190(i64 p) { return p; }
// @0x14027c1a0
i64 FUN_14027c1a0(i64 p) { return p; }
// @0x14027c1b0
i64 FUN_14027c1b0(i64 p) { return p; }
// @0x14027c1c0
i64 FUN_14027c1c0(i64 p) { return p; }
// @0x14027c1d0
i64 FUN_14027c1d0(i64 p) { return p; }
// @0x14027c1e0
i64 FUN_14027c1e0(i64 p) { return p; }
// @0x14027c1f0
i64 FUN_14027c1f0(i64 p) { return p; }
// @0x14027c200
i64 FUN_14027c200(i64 p) { return p; }
// @0x14027c210
i64 FUN_14027c210(i64 p) { return p; }
// @0x14027c220
i64 FUN_14027c220(i64 p) { return p; }
// @0x14027c230
i64 FUN_14027c230(i64 p) { return p; }

void FUN_140274c00(i64, i64);
// @0x14027c240
i64 FUN_14027c240(i64 a, i64 b) { FUN_140274c00(a, FUN_14027c1f0(b)); return a; }
// @0x14027c270
i64 FUN_14027c270(i64* p) { return FUN_14027c1f0(*p); }

// vector<Unk_IngRef>::insert(where, first, last)
i64 FUN_140288a40(i64); void FUN_140279de0(i64, i64, i64, i64, Unk_StlTag); void FUN_140288770(i64, i64, i64);
// @0x14027c290
i64 FUN_14027c290(i64 self, i64 out, i64 where, i64 first, i64 last)
{
    Unk_StlTag t;
    FUN_1402769a0(&first, &last);
    i64 idx = (where - *(i64*)FUN_140288a40(self)) >> 4;
    FUN_140279de0(self, where, FUN_140278760(&first), FUN_140278760(&last), t);
    FUN_140288770(self, out, idx);
    return out;
}

// fmt::internal::make_type<T>(const T&) instances: forward to the per-type MakeValue::type()
u64 FUN_14020c270(i64); u64 FUN_14028b580(float); u64 FUN_14028b590(i64); u64 FUN_14028b5a0(bool);
// @0x14027c340
u64 FUN_14027c340(i64 p) { return FUN_14020c270(p); }
// @0x14027c360
u64 FUN_14027c360(i64 p) { return FUN_14028b580(*(float*)p); }
// @0x14027c380
u64 FUN_14027c500(i64);
u64 FUN_14027c380(i64 p) { return FUN_14027c500(p); }
// @0x14027c3a0
u64 FUN_14027c3a0(i64 p) { return FUN_14028b590(*(i64*)p); }
// @0x14027c3c0
u64 FUN_14027c3c0(i64 p) { return FUN_14028b5a0(*(bool*)p); }
// @0x14027c3e0
i64 FUN_14027c3e0(i64 p) { return p; }
// @0x14027c3f0
i64 FUN_14027c3f0(i64 p) { return p; }
// @0x14027c400
i64 FUN_14027c400(i64 p) { return p; }
// @0x14027c410
i64 FUN_14027c410(i64 p) { return p; }

// @0x14027c420
i64 FUN_14027c420(i64 it, i64 n) { FUN_14027b5a0(&it, n); return it; }
// @0x14027c450
i64 FUN_14027c450(i64 it, i64 n) { FUN_14027b5d0(&it, n); return it; }
// @0x14027c480
i64* FUN_14027c480(i64* out, i64 it, i64 n) { FUN_14027b600((i64)&it, n); *out = it; return out; }
void FUN_14027a770(i64, i64, i64);
// @0x14027c4c0
i64 FUN_14027c4c0(i64 a, i64 b, i64 c) { FUN_14027a770(a, b, c); return b; }
// @0x14027c500
u64 FUN_14027c500(i64) { return 13; }

// ATL::CAtlArray<T*>::CAtlArray(), ATL::CAtlList<T>::CAtlList(UINT nBlockSize)
struct Unk_Arr { void* data; u64 size; u64 capacity; int growBy; };
struct Unk_List { void* head; void* tail; void* free; void* blocks; u64 count; int blockSize; };
// @0x14027c510
Unk_Arr* FUN_14027c510(Unk_Arr* a) { a->data = 0; a->size = 0; a->capacity = 0; a->growBy = 0; return a; }
// @0x14027c550
Unk_Arr* FUN_14027c550(Unk_Arr* a) { a->data = 0; a->size = 0; a->capacity = 0; a->growBy = 0; return a; }
// @0x14027c590
Unk_List* FUN_14027c590(Unk_List* l, int blockSize) { l->head = 0; l->tail = 0; l->free = 0; l->blocks = 0; l->count = 0; l->blockSize = blockSize; return l; }
// @0x14027c5f0
Unk_List* FUN_14027c5f0(Unk_List* l, int blockSize) noexcept { l->head = 0; l->tail = 0; l->free = 0; l->blocks = 0; l->count = 0; l->blockSize = blockSize; return l; }
// @0x14027c650
Unk_List* FUN_14027c650(Unk_List* l, int blockSize) noexcept { l->head = 0; l->tail = 0; l->free = 0; l->blocks = 0; l->count = 0; l->blockSize = blockSize; return l; }

// ---- 0x48-byte effect/particle-like record ctors ----
struct Unk_Rec48 {
    void* a; void* b; int n; float x, y, z; u64 id; void* c; int d; int e; void* f; void* g;
};
MS2_CHECK_SIZE(Unk_Rec48, 0x48);
void FUN_140285f70(Unk_Rec48*, float, float, float, bool);
void FUN_140286020(Unk_Rec48*, float, float, float, bool);
// @0x14027c6b0
Unk_Rec48* FUN_14027c6b0(Unk_Rec48* t, int n, float x, float y, float z, int e)
{
    t->a = 0; t->b = 0; t->n = n; t->x = x; t->y = y; t->z = z;
    t->id = 0xFFFFFFFF; t->c = 0; t->d = 0; t->e = e; t->f = 0; t->g = 0;
    FUN_140285f70(t, x, y, z, false);
    return t;
}
// @0x14027c7a0
Unk_Rec48* FUN_14027c7a0(Unk_Rec48* t, int n, float x, float y, float z, int e)
{
    t->a = 0; t->b = 0; t->n = n; t->x = x; t->y = y; t->z = z;
    t->id = 0xFFFFFFFF; t->c = 0; t->d = 0; t->e = e; t->f = 0; t->g = 0;
    FUN_140286020(t, x, y, z, false);
    return t;
}

struct Unk_Mv30 { void* a; void* b; void* c; void* d; void* e; void* f; };
Unk_Mv30* FUN_14027c8c0(Unk_Mv30*, void*);
// @0x14027c890
Unk_Mv30* FUN_14027c890(Unk_Mv30* t, void* v) { FUN_14027c8c0(t, v); return t; }
// @0x14027c8c0
Unk_Mv30* FUN_14027c8c0(Unk_Mv30* t, void* v) { t->a = 0; t->b = 0; t->c = 0; t->d = 0; t->e = v; t->f = 0; return t; }
// @0x14027c920
double* FUN_14027c920(double* t, float v) { *t = v; return t; }
// @0x14027c940
i64* FUN_14027c940(i64* t, i64 v) { *t = v; return t; }
// @0x14027c960
int* FUN_14027c960(int* t, bool v) { *t = v; return t; }

// ---- Unk_Ref16 (refcounted pointer wrapper: {vptr-ish, p}) ctors; the addref helpers are the exe's per-type AddRef ----
void FUN_1402864c0(Unk_Ref16*); void FUN_1402864f0(Unk_Ref16*); void FUN_140286520(Unk_Ref16*);
void FUN_140286550(Unk_Ref16*); void FUN_1402865b0(Unk_Ref16*); void FUN_1402865e0(Unk_Ref16*);
void FUN_140286610(Unk_Ref16*); void FUN_140286640(Unk_Ref16*); void FUN_140286670(Unk_Ref16*);
// @0x14027c980
Unk_Ref16* FUN_14027c980(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; o->m_p = 0; return t; }
// @0x14027c9b0
Unk_Ref16* FUN_14027c9b0(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; FUN_1402864c0(t); return t; }
// @0x14027c9f0
Unk_Ref16* FUN_14027c9f0(Unk_Ref16* t, int) { t->m_p = 0; return t; }
// @0x14027ca10
Unk_Ref16* FUN_14027ca10(Unk_Ref16* t, void* p) { t->m_p = p; FUN_1402864c0(t); return t; }
// @0x14027ca40
Unk_Ref16* FUN_14027ca40(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; FUN_1402864f0(t); return t; }
// @0x14027ca80
Unk_Ref16* FUN_14027ca80(Unk_Ref16* t, int) { t->m_p = 0; return t; }
// @0x14027caa0
Unk_Ref16* FUN_14027caa0(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; FUN_140286520(t); return t; }
struct Unk_RefT : Unk_Ref16 { Unk_RefT(void* p); ~Unk_RefT(); };
// @0x14027cae0
Unk_RefT::Unk_RefT(void* p) { m_p = p; FUN_140286550(this); }
// @0x14027cb10
Unk_Ref16* FUN_14027cb10(Unk_Ref16* t) { t->m_p = 0; return t; }
// @0x14027cb30
Unk_Ref16* FUN_14027cb30(Unk_Ref16* t, int) { t->m_p = 0; return t; }
// @0x14027cb50
Unk_Ref16* FUN_14027cb50(Unk_Ref16* t) { t->m_p = 0; return t; }
// @0x14027cb70
Unk_Ref16* FUN_14027cb70(Unk_Ref16* t, int) { t->m_p = 0; return t; }
// @0x14027cb90
Unk_Ref16* FUN_14027cb90(Unk_Ref16* t, int) { t->m_p = 0; return t; }
// @0x14027cbb0
Unk_Ref16* FUN_14027cbb0(Unk_Ref16* t, void* p) { t->m_p = p; FUN_1402865b0(t); return t; }
// @0x14027cbe0
Unk_Ref16* FUN_14027cbe0(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; o->m_p = 0; return t; }
// @0x14027cc10
Unk_Ref16* FUN_14027cc10(Unk_Ref16* t, void*) { t->m_p = 0; return t; }
// @0x14027cc30
Unk_Ref16* FUN_14027cc30(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; FUN_1402865e0(t); return t; }
// @0x14027cc70
Unk_Ref16* FUN_14027cc70(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; FUN_140286610(t); return t; }
// @0x14027ccb0
Unk_Ref16* FUN_14027ccb0(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; FUN_140286640(t); return t; }
// @0x14027ccf0
Unk_Ref16* FUN_14027ccf0(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; o->m_p = 0; return t; }
// @0x14027cd20
Unk_Ref16* FUN_14027cd20(Unk_Ref16* t, void* p) { t->m_p = p; FUN_140286670(t); return t; }

// ---- TPtredDummy<CAtlList<TPtr<CUserLimitHistory>>>-style box: CPtred base, the list at +0x18 ----
#include "ms2/placeholder/cptred.h"
struct Unk_ListBox : CPtred {
    Unk_List value;
    Unk_ListBox();
};
// MS2-PIN: ??_7Unk_ListBox@@6B@ 0x142d15c08
// @0x14027cd50
Unk_ListBox::Unk_ListBox() { FUN_14027c5f0(&value, 10); }

// ---- std::_Compressed_pair / _Uninitialized_backout ctor glue ----
// the exe's functions that call a member-subobject ctor at +0 (address of the first member is computed into rax first)
void FUN_1402749c0(Unk_PairMember*, Unk_StlTag);
i64 FUN_140286c40(void*);
i64* FUN_140288ac0(void*);
void FUN_14016ad80(void*, i64);
void FUN_140274b60(Unk_PairMember*, Unk_StlTag, i64, char*);
void FUN_140287520(void*);
Unk_PairHolder* FUN_14027cda0(Unk_PairHolder*);
// @0x14027cda0
Unk_PairHolder* FUN_14027cda0(Unk_PairHolder* t)
{
    FUN_1402749c0(&t->pair, Unk_StlTag());
    i64 r = FUN_140286c40(t);
    *FUN_140288ac0(t) = r;
    return t;
}
// @0x14027cdf0
Unk_PairHolder* FUN_14027cdf0(Unk_PairHolder* t) { FUN_14027cda0(t); return t; }
void* FUN_14027ce90(void*, i64, i64);
// @0x14027ce10
void* FUN_14027ce10(void* t, i64 a, i64 b) { FUN_14027ce90(t, a, b); return t; }
// @0x14027ce50
void* FUN_14027ce50(void* t, i64 a, i64 b) { FUN_14027ce10(t, a, b); return t; }
// @0x14027ce90
void* FUN_14027ce90(void* t, i64 a, i64 b) { *(i64*)t = a; FUN_14016ad80(t, b); return t; }
// @0x14027ced0
void* FUN_14027ced0(void* t, i64 a, i64 b) { FUN_14027ce90(t, a, b); return t; }
struct Unk_Z16 { i64 a, b; };
// @0x14027cf10
Unk_Z16* FUN_14027cf10(Unk_Z16* t) { t->a = 0; t->b = 0; return t; }
Unk_PairHolder* FUN_14027cf70(Unk_PairHolder*, i64);
// @0x14027cf40
Unk_PairHolder* FUN_14027cf40(Unk_PairHolder* t, i64 p) { FUN_14027cf70(t, p); return t; }
// @0x14027cf70
Unk_PairHolder* FUN_14027cf70(Unk_PairHolder* t, i64 p) { char loc; FUN_140274b60(&t->pair, Unk_StlTag(), p, &loc); FUN_140287520(t); return t; }
void* FUN_14027d050(void*, i64, i64);
void* FUN_14027cfb0(void*, i64, i64);
// @0x14027cfb0
void* FUN_14027cfb0(void* t, i64 a, i64 b) { FUN_14027d050(t, a, b); return t; }
void* FUN_14027d090(void*);
// @0x14027cff0
void* FUN_14027cff0(void* t) { FUN_14027d090(t); return t; }
// @0x14027d010
void* FUN_14027d010(void* t, i64 a, i64 b) { FUN_14027cfb0(t, a, b); return t; }
// @0x14027d050
void* FUN_14027d050(void* t, i64 a, i64 b) { *(i64*)t = a; FUN_14016ad80(t, b); return t; }
// @0x14027d090
void* FUN_14027d090(void* t) { *(i64*)t = 0; return t; }
// @0x14027d0b0
Unk_Z16* FUN_14027d0b0(Unk_Z16* t) { t->a = 0; t->b = 0; return t; }
// @0x14027d0e0
Unk_BackoutA::Unk_BackoutA(i64 d, i64 a) { first = d; last = d; al = a; }
// @0x14027d120
Unk_BackoutB::Unk_BackoutB(i64 d, i64 a) { first = d; last = d; al = a; }
// @0x14027d160
Unk_BackoutC::Unk_BackoutC(i64 d, i64 a) { first = d; last = d; al = a; }
// @0x14027d1a0
Unk_BackoutD::Unk_BackoutD(i64 d, i64 a) { first = d; last = d; al = a; }
// @0x14027d1e0
Unk_BackoutE::Unk_BackoutE(i64 d, i64 a) { first = d; last = d; al = a; }

void FUN_140274a20(Unk_PairMember*, Unk_StlTag); void FUN_140274a50(Unk_PairMember*, Unk_StlTag); void FUN_140274a80(Unk_PairMember*, Unk_StlTag);
void FUN_140274ab0(Unk_PairMember*, Unk_StlTag); void FUN_140274ae0(Unk_PairMember*, Unk_StlTag);
// @0x14027d220
Unk_PairHolder* FUN_14027d220(Unk_PairHolder* t) { FUN_140274a20(&t->pair, Unk_StlTag()); return t; }
// @0x14027d250
Unk_PairHolder* FUN_14027d250(Unk_PairHolder* t) { FUN_140274a50(&t->pair, Unk_StlTag()); return t; }
// @0x14027d280
Unk_PairHolder* FUN_14027d280(Unk_PairHolder* t) { FUN_140274a80(&t->pair, Unk_StlTag()); return t; }
// @0x14027d2b0
Unk_PairHolder* FUN_14027d2b0(Unk_PairHolder* t) { FUN_140274ab0(&t->pair, Unk_StlTag()); return t; }
// @0x14027d2e0
Unk_PairHolder* FUN_14027d2e0(Unk_PairHolder* t) { FUN_140274ae0(&t->pair, Unk_StlTag()); return t; }
// @0x14027d310
void* FUN_14027d310(void* t, i64 a, i64 b) { *(i64*)t = a; FUN_14016ad80(t, b); return t; }
// @0x14027d350
void* FUN_14027d350(void* t, i64 a, i64 b) { *(i64*)t = a; FUN_14016ad80(t, b); return t; }
// @0x14027d390
void* FUN_14027d390(void* t, i64 a, i64 b) { FUN_14027d310(t, a, b); return t; }
// @0x14027d3d0
void* FUN_14027d3d0(void* t, i64 a, i64 b) { FUN_14027d350(t, a, b); return t; }
struct Unk_Z24 { i64 a, b, c; };
// @0x14027d410
Unk_Z24* FUN_14027d410(Unk_Z24* t) { t->a = 0; t->b = 0; t->c = 0; return t; }
// @0x14027d450
Unk_Z24* FUN_14027d450(Unk_Z24* t) { t->a = 0; t->b = 0; t->c = 0; return t; }
// @0x14027d490
Unk_Z24* FUN_14027d490(Unk_Z24* t) { t->a = 0; t->b = 0; t->c = 0; return t; }
// @0x14027d4d0
Unk_Z24* FUN_14027d4d0(Unk_Z24* t) { t->a = 0; t->b = 0; t->c = 0; return t; }
// @0x14027d510
Unk_Z24* FUN_14027d510(Unk_Z24* t) { t->a = 0; t->b = 0; t->c = 0; return t; }
// @0x14027d550
void* FUN_14027d550(void* t) { return t; }
// @0x14027d560
void* FUN_14027d560(void* t) { return t; }
// @0x14027d570
void* FUN_14027d570(void* t) { return t; }
// @0x14027d580
void* FUN_14027d580(void* t) { return t; }
// @0x14027d590
void* FUN_14027d590(void* t) { return t; }
// @0x14027d5a0
void* FUN_14027d5a0(void* t) { return t; }
// @0x14027d5b0
void* FUN_14027d5b0(void* t) { return t; }
// @0x14027d5c0
Unk_CommonBytes4* FUN_14027d5c0(Unk_CommonBytes4* t) noexcept { memset(&t->raw, 0, sizeof(t->raw)); return t; }
// @0x14027d5e0
Unk_PairHolder* FUN_14027d5e0(Unk_PairHolder* t) { FUN_14027cdf0(t); return t; }
// @0x14027d600
Unk_PairHolder* FUN_14027d600(Unk_PairHolder* t) { char loc; FUN_14027cf40(t, (i64)&loc); return t; }
// @0x14027d630
i64* FUN_14027d630(i64* t, i64 v) { *t = v; return t; }
// @0x14027d650
Unk_Q8* FUN_14027d650(Unk_Q8* t, Unk_Q8* p) { FUN_140163dc0(t, p); *t = *p; return t; }
// @0x14027d690
Unk_PairHolder* FUN_14027d690(Unk_PairHolder* t) noexcept { FUN_14027d220(t); return t; }
// @0x14027d6c0
Unk_PairHolder* FUN_14027d6c0(Unk_PairHolder* t) noexcept { FUN_14027d250(t); return t; }
// @0x14027d6f0
Unk_PairHolder* FUN_14027d6f0(Unk_PairHolder* t) noexcept { FUN_14027d280(t); return t; }
// @0x14027d720
Unk_PairHolder* FUN_14027d720(Unk_PairHolder* t) noexcept { FUN_14027d2b0(t); return t; }
// @0x14027d750
Unk_PairHolder* FUN_14027d750(Unk_PairHolder* t) noexcept { FUN_14027d2e0(t); return t; }

// ---- small value types: ctors / copy ctors (all inline COMDATs of the element types in the exe) ----
struct CAdditionalEvent;
struct Unk_ListB : Unk_List { ~Unk_ListB() throw(); };
// ATL::CAtlList dtors: RemoveAll(), then the (empty) ATLASSERT do-while
void FUN_140284b30(void*); void FUN_140284c10(void*);
struct Unk_ListA : Unk_List { ~Unk_ListA() throw(); };
// @0x14027de70
Unk_ListA::~Unk_ListA() throw() { FUN_140284b30(this); do {} while (0); }
// @0x14027de90
Unk_ListB::~Unk_ListB() throw() { FUN_140284c10(this); do {} while (0); }

struct CAdditionalEvent : CPtred {
    Unk_ListB events;
    CAdditionalEvent();
    // @0x14027e590
    virtual ~CAdditionalEvent() = default;
};
// @0x14027d780
CAdditionalEvent::CAdditionalEvent() { FUN_14027c650(&events, 10); }
void Unk_AnchorAdditionalEvent(CAdditionalEvent* p) { p->CAdditionalEvent::~CAdditionalEvent(); }

// @0x14027d7d0
CIngredientInfo::CIngredientInfo(int a, int b, int c) : m_a(a), m_b(c), m_c(b) {}
// @0x14027d830
CIngredientInfo::CIngredientInfo() : m_a(0), m_b(0), m_c(0) {}

struct Unk_S0 { int a, b; i64 c; Unk_S0(); Unk_S0(int, int, i64); };
// @0x14027d900
Unk_S0::Unk_S0(int a_, int b_, i64 c_) : a(a_), b(b_), c(c_) {}
// @0x14027d940
Unk_S0::Unk_S0() : a(0), b(0), c(0) {}
struct Unk_S0Holder { Unk_S0 s; i64 x; Unk_S0Holder(); Unk_S0Holder(int, int, i64, i64); };
// @0x14027d880
Unk_S0Holder::Unk_S0Holder(int a, int b, i64 c, i64 x_) : s(a, b, c), x(x_) {}
// @0x14027d8d0
Unk_S0Holder::Unk_S0Holder() : s(), x(0) {}

struct Unk_InnerA { void* p; };
struct Unk_InnerB { void* p; };
Unk_InnerA* FUN_14020a440(Unk_InnerA*, const Unk_InnerA*);
Unk_InnerB* FUN_14020a470(Unk_InnerB*, const Unk_InnerB*);
struct Unk_RecA { int v; Unk_InnerA in; Unk_RecA(const Unk_RecA&); };
struct Unk_RecB { int v; Unk_InnerB in; Unk_RecB(const Unk_RecB&); };
// @0x14027dd20
Unk_RecA::Unk_RecA(const Unk_RecA& o) : v(o.v) { FUN_14020a440(&in, &o.in); }
// @0x14027dd60
Unk_RecB::Unk_RecB(const Unk_RecB& o) : v(o.v) { FUN_14020a470(&in, &o.in); }
struct Unk_Holder10 { i64 pad0, pad1; Unk_RecB rec; Unk_Holder10(const Unk_RecB& r); };
// @0x14027d970
Unk_Holder10::Unk_Holder10(const Unk_RecB& r) : rec(r) {}
struct Unk_Holder10R { i64 pad0, pad1; Unk_Ref16 r; };
// @0x14027d9a0
Unk_Holder10R* FUN_14027d9a0(Unk_Holder10R* t, Unk_Ref16* p) { FUN_14027cc70(&t->r, p); return t; }
struct Unk_IntHolder { int v; int pad[3]; int x; };
// @0x14027d9d0
Unk_IntHolder* FUN_14027d9d0(Unk_IntHolder* t, const int* p) { t->x = *p; return t; }
struct Unk_IntBox { int v; };
// @0x14027dac0
Unk_IntBox* FUN_14027dac0(Unk_IntBox* t, int a) { t->v = a; return t; }
// @0x14027dae0
Unk_IntBox* FUN_14027dae0(Unk_IntBox* t, int a) { t->v = a; return t; }
// @0x14027d9f0
Unk_IntHolder* FUN_14027d9f0(Unk_IntHolder* t, int a, int b) { FUN_14027dac0((Unk_IntBox*)t, a); t->x = b; return t; }
// @0x14027da30
Unk_IntHolder* FUN_14027da30(Unk_IntHolder* t, int a, int b) { FUN_14027dae0((Unk_IntBox*)t, a); t->x = b; return t; }
struct Unk_RefRec { i64 a; Unk_Ref16 r; int flag; int pad1c; i64 pad20, pad28, tail; };
// @0x14027db00
Unk_RefRec* FUN_14027db00(Unk_RefRec* t, i64 a, Unk_Ref16* b) { t->a = a; FUN_14027ca40(&t->r, b); return t; }
// @0x14027da70
Unk_RefRec* FUN_14027da70(Unk_RefRec* t, i64 a, Unk_Ref16* b) { FUN_14027db00(t, a, b); t->flag = 1; t->tail = 0; return t; }
struct Unk_V3 { float x, y, z; };
// @0x14027db40
Unk_V3* FUN_14027db40(Unk_V3* t, float x, float y, float z) { t->x = x; t->y = y; t->z = z; return t; }
// @0x14027dda0
Unk_V3* FUN_14027dda0(Unk_V3* t, float x, float y, float z) { t->x = x; t->y = y; t->z = z; return t; }
struct Unk_Z16i { int a, b, c, d; };
// @0x14027dcb0
Unk_Z16i* FUN_14027dcb0(Unk_Z16i* t) { t->a = 0; t->b = 0; t->c = 0; t->d = 0; return t; }
// @0x14027dcf0
Unk_V3* FUN_14027dcf0(Unk_V3* t, const Unk_V3* o) { *t = *o; return t; }

// ATL::CAtlArray dtors: if (m_pData) { CallDestructors(m_pData, m_nSize); free(m_pData); }
void FUN_140280970(void*, u64); void FUN_1402809b0(void*, u64);
struct Unk_AtlArrP { void* data; u64 size; u64 cap; int grow; ~Unk_AtlArrP() throw(); };
struct Unk_AtlArrL { void* data; u64 size; u64 cap; int grow; ~Unk_AtlArrL() throw(); };
// @0x14027ddf0
Unk_AtlArrP::~Unk_AtlArrP() throw() { if (data) { FUN_140280970(data, size); ::free(data); } }
// @0x14027de30
Unk_AtlArrL::~Unk_AtlArrL() throw() { if (data) { FUN_1402809b0(data, size); ::free(data); } }

// ---- ItemAble / ItemEntity inline COMDATs of the exe ----
// MS2-PIN: ??0ItemAble@@QEAA@AEBU0@@Z 0x14027db90
// MS2-PIN: ??0ItemEntity@@QEAA@$$QEAU0@@Z 0x14027dbd0
// ItemAble's own default ctor (0x14027dbb0): only the vptr store. ItemAble is abstract, so a unit-local twin with the
// same four pure slots carries it; its vftable is the exe's ItemAble vftable.
// MS2-PIN: ??_7Unk_ItemAbleTwin@@6B@ 0x142cef880
struct Unk_ItemAbleTwin {
    Unk_ItemAbleTwin();
    virtual unsigned int vfunc_o18_0() = 0;
    virtual int vfunc_o18_1() = 0;
    virtual unsigned int vfunc_o18_2() = 0;
    virtual bool vfunc_o18_3() = 0;
};
// @0x14027dbb0
Unk_ItemAbleTwin::Unk_ItemAbleTwin() {}

// ---- smart-pointer / container dtors: noexcept single-call bodies (the -2 unwind slot + nop is the noexcept frame) ----
i64 FUN_140288dd0(void*); i64 FUN_140288e10(void*); i64 FUN_140288e50(void*); i64 FUN_140288e90(void*); i64 FUN_140288ed0(void*);
i64 FUN_140288f10(void*); i64 FUN_140288f50(void*); i64 FUN_140288f90(void*); i64 FUN_140288fd0(void*); i64 FUN_140289010(void*);
i64 FUN_140289050(void*); i64 FUN_140289670(void*); i64 FUN_140289740(void*); i64 FUN_140289810(void*); i64 FUN_1402898e0(void*);
i64 FUN_1402899b0(void*); i64 FUN_140284cf0(void*); i64 FUN_140284e00(void*); i64 FUN_140289650(void*); i64 FUN_1402895f0(void*);
void FUN_140287d90(void*, i64); void FUN_140287dc0(void*, i64); i64* FUN_140287eb0(void*);
i64 FUN_140284f10(void*);
// @0x14027df70
Unk_IngRef::~Unk_IngRef() { FUN_140288dd0(this); }
// @0x14027e060
Unk_HistRef::~Unk_HistRef() { FUN_140288f10(this); }
// @0x14027e0c0
Unk_ProdRef::~Unk_ProdRef() { FUN_140288f90(this); }
// @0x14027e150
Unk_ShopLifeRef::~Unk_ShopLifeRef() { FUN_140289050(this); }
// @0x14027dfa0
void FUN_14027dfa0(void* t) noexcept { FUN_140288e10(t); }
// @0x14027dfd0
void FUN_14027dfd0(void* t) noexcept { FUN_140288e50(t); }
// @0x14027e000
Unk_RefT::~Unk_RefT() { FUN_140288e90(this); }
// @0x14027e030
void FUN_14027e030(void* t) noexcept { FUN_140288ed0(t); }
// @0x14027e090
void FUN_14027e090(void* t) noexcept { FUN_140288f50(t); }
// @0x14027e0f0
void FUN_14027e0f0(void* t) noexcept { FUN_140288fd0(t); }
// @0x14027e120
void FUN_14027e120(void* t) noexcept { FUN_140289010(t); }
// @0x14027e3f0
void FUN_14027e3f0(void* t) noexcept { FUN_140289670(t); }
// @0x14027e4b0
void FUN_14027e4b0(void* t) noexcept { FUN_1402899b0(t); }
// @0x14027deb0
void FUN_14027deb0(void* t) { try { FUN_140284cf0(t); } catch (...) {} }
// @0x14027dee0
void FUN_14027dee0(void* t) { try { FUN_140284e00(t); } catch (...) {} }
// @0x14027e420
Unk_ItemVec::~Unk_ItemVec() noexcept { FUN_140289740(this); }
// @0x14027e450
Unk_StrVec::~Unk_StrVec() { FUN_140289810(this); }
// @0x14027e480
Unk_IngVec::~Unk_IngVec() { FUN_1402898e0(this); }

// a list/map header (std::list<Unk_HistRef> / std::map<unsigned,int>): _Tidy = clear + free the sentinel node
// @0x14027e1b0
void FUN_14027e1b0(Unk_HistList* t) noexcept { FUN_140287d90(t, *FUN_140288ac0(t)); }
// @0x14027e1e0
void FUN_14027e1e0(Unk_HistList* t) { FUN_14027e1b0(t); }
// @0x14027e3a0
Unk_HistList::~Unk_HistList() { FUN_140289650(this); FUN_14027e1e0(this); }
// @0x14027e230
void FUN_14027e230(Unk_RewardMap* t) noexcept { FUN_140287dc0(t, *FUN_140287eb0(t)); }
// @0x14027e200
void FUN_14027e200(Unk_RewardMap* t) noexcept { FUN_1402895f0(t); FUN_14027e230(t); }
// @0x14027e3d0
Unk_RewardMap::~Unk_RewardMap() { FUN_14027e200(this); }

// std::_Uninitialized_backout dtors: destroy [first,last)
// @0x14027e260
Unk_BackoutA::~Unk_BackoutA() { FUN_140277470(first, last, al); }
// @0x14027e2a0
Unk_BackoutB::~Unk_BackoutB() { FUN_1402774c0(first, last, al); }
// @0x14027e2e0
Unk_BackoutC::~Unk_BackoutC() { FUN_140277510(first, last, al); }
// @0x14027e320
Unk_BackoutD::~Unk_BackoutD() { FUN_140277560(first, last, al); }
// @0x14027e360
Unk_BackoutE::~Unk_BackoutE() { FUN_1402775b0(first, last, al); }

// ---- refcounted-pointer assignment: AddRef(src), Release(this), copy ----
void FUN_140286580(Unk_Ref16*);
// @0x14027e950
Unk_Ref16* FUN_14027e950(Unk_Ref16* t, Unk_Ref16* o) { FUN_1402864c0(o); FUN_140288dd0(t); t->m_p = o->m_p; return t; }
// @0x14027e990
Unk_Ref16* FUN_14027e990(Unk_Ref16* t, Unk_Ref16* o) { FUN_1402864f0(o); FUN_140288e10(t); t->m_p = o->m_p; return t; }
// @0x14027ea40
Unk_Ref16* FUN_14027ea40(Unk_Ref16* t, Unk_Ref16* o) { FUN_140286580(o); FUN_140288ed0(t); t->m_p = o->m_p; return t; }
// @0x14027ea80
Unk_Ref16* FUN_14027ea80(Unk_Ref16* t, int) { FUN_140288ed0(t); return t; }
// @0x14027eab0
Unk_Ref16* FUN_14027eab0(Unk_Ref16* t, Unk_Ref16* o) { FUN_1402865e0(o); FUN_140288f10(t); t->m_p = o->m_p; return t; }
// @0x14027eaf0
Unk_Ref16* FUN_14027eaf0(Unk_Ref16* t, Unk_Ref16* o) { FUN_140286640(o); FUN_140289010(t); t->m_p = o->m_p; return t; }
// operator=(T*): swap with a temporary
// @0x14027e9d0
Unk_Ref16* FUN_14027e9d0(Unk_Ref16* t, void* p)
{
    Unk_RefT tmp(p);
    void* old = t->m_p;
    t->m_p = tmp.m_p;
    tmp.m_p = old;
    return t;
}

// ---- remaining class dtors, wrappers, comparisons and array accessors ----
struct Unk_A28 { i64 pad[5]; void* p28; };
// @0x14027df30
void FUN_14027df30(Unk_A28* t) { FUN_140284f10(t); if (t->p28) ::free(t->p28); }
// @0x14027df10
void FUN_14027df10(Unk_A28* t) { FUN_14027df30(t); }
// @0x14027e180
void FUN_14027e180(Unk_ListBox* p) { reinterpret_cast<Unk_ListA*>(&p->value)->Unk_ListA::~Unk_ListA(); p->CPtred::~CPtred(); }

// defaulted dtors of headers without the member layout public: emitted by an anchor, paired by pin
// MS2-PIN: ??1BillBoardInfo@@UEAA@XZ 0x14027e530
// MS2-PIN: ??1CClientHardwareInfo@@UEAA@XZ 0x14027e5c0
void Unk_AnchorDtors(BillBoardInfo* b, CClientHardwareInfo* h) { b->BillBoardInfo::~BillBoardInfo(); h->CClientHardwareInfo::~CClientHardwareInfo(); }

// dtors of classes whose headers are not part of this unit: member dtors, then CPtred::~CPtred
struct Unk_DtW30 : CPtred { i64 pad[3]; CStringW s; };
struct Unk_DtA30 : CPtred { i64 pad[3]; CString s; };
// @0x14027e4e0
void FUN_14027e4e0(Unk_DtW30* t) { t->s.CStringW::~CStringW(); t->CPtred::~CPtred(); }
// @0x14027e890
void FUN_14027e890(Unk_DtA30* t) { t->s.CString::~CString(); t->CPtred::~CPtred(); }
// @0x14027e510
void FUN_14027e510(CPtred* t) { t->CPtred::~CPtred(); }
// @0x14027e600
void FUN_14027e600(CPtred* t) { t->CPtred::~CPtred(); }
// @0x14027e670
void FUN_14027e670(CPtred* t) { t->CPtred::~CPtred(); }
// @0x14027e800
void FUN_14027e800(CPtred* t) { t->CPtred::~CPtred(); }
// @0x14027e870
void FUN_14027e870(CPtred* t) { t->CPtred::~CPtred(); }
// The CPtred-derived dtors below are implicit (the exe stores no vptr). This slice owns their VAs but not the
// ctors, so odr-use them here to make cl emit the COMDATs; the helper itself is never called.
void MS2_EmitImplicitDtors_commonstruct2(CUserChangeableItemHistory* p0, ChangeableProductInfo* p1, HomeBlockInfo* p2, ItemDropItemLife* p3, NpcShopItemLife* p4)
{
    p0->CUserChangeableItemHistory::~CUserChangeableItemHistory();
    p1->ChangeableProductInfo::~ChangeableProductInfo();
    p2->HomeBlockInfo::~HomeBlockInfo();
    p3->ItemDropItemLife::~ItemDropItemLife();
    p4->NpcShopItemLife::~NpcShopItemLife();
}
// MS2-PIN: ??1CUserChangeableItemHistory@@UEAA@XZ 0x14027e7a0
// MS2-PIN: ??1ChangeableProductInfo@@UEAA@XZ 0x14027e7e0
// MS2-PIN: ??1HomeBlockInfo@@UEAA@XZ 0x14027e820
// MS2-PIN: ??1ItemDropItemLife@@UEAA@XZ 0x14027e8c0
// MS2-PIN: ??1NpcShopItemLife@@UEAA@XZ 0x14027e8e0
struct Unk_DtArr38 : CPtred { i64 pad[4]; i64 arr[1]; };
void FUN_1401b7d00(void*);
// @0x14027e640
void FUN_14027e640(Unk_DtArr38* t) { FUN_1401b7d00(&t->arr); t->CPtred::~CPtred(); }
struct Unk_DtArr20 : CPtred { i64 pad; Unk_AtlArrP arr; };
// @0x14027e920
void FUN_14027e920(Unk_DtArr20* t) { t->arr.Unk_AtlArrP::~Unk_AtlArrP(); t->CPtred::~CPtred(); }
struct Unk_DtSk28 : CPtred { i64 pad[1]; CStringW s; char cfg[8]; };
void FUN_140183b40(void*);
// @0x14027e720
void FUN_14027e720(Unk_DtSk28* t) { FUN_14027deb0(&t->cfg); t->s.CStringW::~CStringW(); t->CPtred::~CPtred(); }
struct Unk_DtSk20 : CPtred { CStringW s; char cfg[8]; };
// @0x14027e760
void FUN_14027e760(Unk_DtSk20* t) { FUN_140183b40(&t->cfg); t->s.CStringW::~CStringW(); t->CPtred::~CPtred(); }

struct Unk_At8 { void* pad; char m[8]; };
struct Unk_At10 { void* pad[2]; Unk_At8 m; };
void FUN_14020a5b0(void*);
// @0x14027e900
void FUN_14027e900(Unk_At8* t) { FUN_14020a5b0(&t->m); }
// @0x14027e690
void FUN_14027e690(Unk_At10* t) { FUN_14027e900(&t->m); }
// @0x14027e6b0
void FUN_14027e6b0(Unk_At10* t) { FUN_14027e090(&t->m); }
// @0x14027e6d0
void FUN_14027e6d0(void*) {}
// @0x14027e700
void FUN_14027e700(Unk_At8* t) { FUN_14027dfa0(&t->m); }
// @0x14027e6e0
void FUN_14027e6e0(Unk_At8* t) { FUN_14027e700(t); }

// range copy helpers
struct Unk_False { static const bool value = false; };
i64 FUN_140288a00(i64);
void FUN_140287550(i64, i64); void FUN_140287580(i64, i64);
i64* FUN_140288b00(i64); i64* FUN_1402889a0(i64); i64* FUN_140288c00(i64); i64* FUN_140288aa0(i64);
i64 FUN_140288310(i64); i64 FUN_140288410(i64);
// @0x14027eb30
i64 FUN_14027eb30(i64 t, i64 o)
{
    if (t != FUN_14027b500(o)) {
        if (Unk_False::value) FUN_140289670((void*)t);
        FUN_140287550(t, FUN_140288310(o));
        FUN_14027b630(t, *FUN_1402889a0(o), *FUN_140288b00(o));
    }
    return t;
}
// @0x14027ebb0
i64 FUN_14027ebb0(i64 t, i64 o)
{
    if (t != FUN_14027b510(o)) {
        if (Unk_False::value) FUN_1402899b0((void*)t);
        FUN_140287580(t, FUN_140288410(o));
        FUN_14027b690(t, *FUN_140288aa0(o), *FUN_140288c00(o));
    }
    return t;
}

// pointer-holder comparisons
// @0x14027ec30
bool FUN_14027ec30(Unk_Ref16* t) { return !t->m_p; }
// @0x14027eca0
bool FUN_14027eca0(Unk_Ref16* t, void* p) { return t->m_p == p; }
// @0x14027ece0
bool FUN_14027ece0(Unk_Ref16* t, void* p) { return t->m_p == p; }
// @0x14027ed60
bool FUN_14027ed60(Unk_Ref16* t, void* p) { return t->m_p == p; }
// @0x14027ec60
bool Unk_IngRef::operator==(CIngredientInfo* p) const { return m_p == p; }
// @0x14027ed20
bool Unk_HistRef::operator==(CUserChangeableItemHistory* p) const { return m_p == p; }
// @0x14027eda0
bool FUN_14027eda0(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x14027ede0
bool FUN_14027ede0(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x14027ee20
bool FUN_14027ee20(Unk_It* a, Unk_It* b) { return a->p == b->p; }
void FUN_140287500(Unk_It*, Unk_It*); void FUN_140287510(Unk_It*, Unk_It*);
// @0x14027ee60
bool FUN_14027ee60(Unk_It* a, Unk_It* b) { FUN_140287500(a, b); return a->p == b->p; }
// @0x14027eeb0
bool FUN_14027eeb0(Unk_It* a, Unk_It* b) { FUN_140287510(a, b); return a->p == b->p; }
// @0x14027ef00
bool FUN_14027ef00(Unk_It* a, Unk_It* b) { return !FUN_14027eda0(a, b); }
// @0x14027ef40
bool FUN_14027ef40(Unk_It* a, Unk_It* b) { return !FUN_14027ede0(a, b); }
// @0x14027ef80
bool FUN_14027ef80(Unk_It* a, Unk_It* b) { return !FUN_14027ee20(a, b); }
// @0x14027efc0
bool FUN_14027efc0(Unk_It* a, Unk_It* b) { return !FUN_14027ee60(a, b); }
// @0x14027f000
bool FUN_14027f000(Unk_It* a, Unk_It* b) { return !FUN_14027eeb0(a, b); }

// ATL::CAtlArray::operator[] with the E_INVALIDARG bounds check
void FUN_140159b70(long);
struct Unk_E16 { i64 a, b; };
struct Unk_E24 { i64 a, b, c; };
struct Unk_Arr16 { Unk_E16* data; u64 size; };
struct Unk_Arr24 { Unk_E24* data; u64 size; };
// @0x14027f040
Unk_E16* FUN_14027f040(Unk_Arr16* t, u64 i) { if (i >= t->size) FUN_140159b70(0x80070057); return &t->data[i]; }
// @0x14027f080
Unk_E16* FUN_14027f080(Unk_Arr16* t, u64 i) { if (i >= t->size) FUN_140159b70(0x80070057); return &t->data[i]; }
// @0x14027f100
Unk_E16* FUN_14027f100(Unk_Arr16* t, u64 i) { if (i >= t->size) FUN_140159b70(0x80070057); return &t->data[i]; }
// @0x14027f140
Unk_E16* FUN_14027f140(Unk_Arr16* t, u64 i) { if (i >= t->size) FUN_140159b70(0x80070057); return &t->data[i]; }
// @0x14027f0c0
Unk_E24* FUN_14027f0c0(Unk_Arr24* t, u64 i) { if (i >= t->size) FUN_140159b70(0x80070057); return &t->data[i]; }

struct Unk_UIPair { unsigned first; int second; };
Unk_UIPair* FUN_14027f370(i64);
// @0x14027f180
int& Unk_RewardMap::FUN_14027f180(unsigned& key)
{
    i64 loc;
    return FUN_14027f370(FUN_14027c4c0((i64)this, (i64)&loc, (i64)&key))->second;
}
// @0x14027f1c0
CString* Unk_StrVec::FUN_14027f1c0(size_t i) { return (CString*)*(i64*)FUN_140288a00((i64)this) + i; }
i64* FUN_140288a60(i64);
// @0x14027f1f0
Unk_IngRef* Unk_IngVec::FUN_14027f1f0(size_t i) { return (Unk_IngRef*)*(i64*)FUN_140288a40((i64)this) + i; }
// @0x14027f220
Unk_IngRef* Unk_IngVec::FUN_14027f220(size_t i) { return (Unk_IngRef*)*FUN_140288a60((i64)this) + i; }
// @0x14027f250
CIngredientInfo* Unk_IngRef::FUN_14027f250() const { return m_p; }
// @0x14027f260
void* FUN_14027f260(Unk_Ref16* t) { return t->m_p; }
// @0x14027f270
void* FUN_14027f270(Unk_Ref16* t) { return t->m_p; }
// @0x14027f2c0
CIngredientInfo* Unk_IngRef::operator->() const { return m_p; }
// @0x14027f280
Unk_List* FUN_14027f280(Unk_ListBox* t) { return !t ? 0 : &t->value; }
// @0x14027e7c0
void FUN_14027e7c0(CPtred* t) { t->CPtred::~CPtred(); }
