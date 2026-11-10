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
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/probability.h"
#include "ms2/commonfiles/clientreconnectionstructs.h"
#include "ms2/commonfiles/commonpricerecord.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/packetlogqueue.h"
#include "ms2/fmt/format.h"
#include <list>
#include <map>
#include <set>
#include <tuple>
#include <vector>
#include "ms2/placeholder/ms2svrptr.h"   // C3 #10: MS2SvrPtr<CPtred> (was Unk_ShopLifeRef)
// The STL/ATL instances the folded COMDATs are named after in the exe (C3: the calls go to their members).
enum Unk_LimitValue : int;
enum Unk_AdditionalEventValue : int;
class CUserLimitHistory; class AdditionalEffectEventCtx; class CItemOption;
typedef MS2Ptr<CIngredientInfo> PIng;
typedef MS2Ptr<Probability::LogContext> PLog;
typedef std::vector<__int64> VI64;
typedef std::vector<ItemEntity> VItem;
typedef std::vector<CString> VStr;
typedef std::vector<PIng> VIng;
typedef std::vector<PLog> VLog;
typedef std::vector<MS2Ptr<CPtred>> VPtred;
typedef std::list<MS2Ptr<CUserChangeableItemHistory>> LHist;
typedef std::_List_node<MS2Ptr<CUserChangeableItemHistory>, void*> NodeHist;
typedef std::map<int, int> MapII;
typedef std::set<unsigned> SetU;
typedef ATL::CAtlArray<__int64> ArrI64;
typedef Unk_PktPtr<COutPacket> PktOut;

typedef __int64 i64;
typedef unsigned __int64 u64;
struct Unk_StlTag {};

// ---- callees outside this part (exe-bound by name) ----
struct Unk_Q8 { i64 v; };
struct Unk_PairMember { char c; };
struct Unk_PairHolder { Unk_PairMember pair; };
Unk_Q8* FUN_14027d650(Unk_Q8*, Unk_Q8*);
// (0x140163dc0 is std::tuple<>::tuple(const tuple&), called directly)
i64 FUN_140278730(i64); i64 FUN_140278740(i64);
i64 FUN_1402787a0(i64, i64); i64 FUN_1402787b0(i64, i64);
i64 FUN_140278920(i64*, i64*); i64 FUN_140278950(i64*, i64*);
char FUN_14027a640(i64*, i64*); char FUN_14027a670(i64*, i64*);
#ifdef MS2_HOOK_DLL
char* FUN_140177620(char*, char*);
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" char* __identifier("??$?0U?$integral_constant@_N$00@std@@@_Unused_parameter@std@@QEAA@$$QEAU?$integral_constant@_N$00@1@@Z")(char*, char*);
#define FUN_140177620 __identifier("??$?0U?$integral_constant@_N$00@std@@@_Unused_parameter@std@@QEAA@$$QEAU?$integral_constant@_N$00@1@@Z")
#endif
void FUN_14027a6e0(i64*, i64); void FUN_14027a700(i64*, i64);
void FUN_140277870(i64, i64); void FUN_1402778d0(i64, i64); void FUN_140277930(i64, i64);
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
// std::_Uninitialized_move<PIng*, PIng*, allocator<PIng>>, called by vector<PIng>::_Umove 0x140289b00
template PIng* std::_Uninitialized_move<PIng*, PIng*, std::allocator<PIng>>(PIng*, PIng*, PIng*, std::allocator<PIng>&);
// MS2-PIN: ??$_Uninitialized_move@PEAV?$MS2Ptr@VCIngredientInfo@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCIngredientInfo@@@@PEAV1@00AEAV?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@0@@Z 0x14027b250 ; unique











void FUN_140277870(i64, i64);
void FUN_1402769e0(i64*, i64, Unk_StlTag);
void FUN_140276a10(i64*, i64, Unk_StlTag);
// (0x140276a40 = std::_Advance1<LHist::iterator>, commonstruct_wc)
void FUN_140276920(i64, i64); void FUN_140276960(i64, i64);
#include "ms2/placeholder/citemremakeoptionpacket.h"   // Unk_RemakeLockOpt: 0x14027b630 is vector<Unk_RemakeLockOpt>::assign
i64 FUN_140278710(i64); i64 FUN_140278750(i64);

// @0x14027b320
i64 FUN_14027b320(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutB bo(dest, al);
    for (; first != last; first += 0x30)
        FUN_140277870((i64)&bo, FUN_14027c3e0(first));
    return (i64)reinterpret_cast<std::_Uninitialized_backout_al<ItemEntity*, std::allocator<ItemEntity>>*>(&bo)->_Release();
}
// @0x14027b3b0
i64 FUN_14027b3b0(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutC bo(dest, al);
    for (; first != last; first += 8)
        FUN_1402778d0((i64)&bo, FUN_14027c3f0(first));
    return (i64)reinterpret_cast<std::_Uninitialized_backout_al<PIng*, std::allocator<PIng>>*>(&bo)->_Release();
}
// @0x14027b440
i64 FUN_14027b440(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutD bo(dest, al);
    for (; first != last; first += 0x10)
        FUN_140277930((i64)&bo, FUN_14027c400(first));
    return (i64)reinterpret_cast<std::_Uninitialized_backout_al<MS2Ptr<CPtred>*, std::allocator<MS2Ptr<CPtred>>>*>(&bo)->_Release();
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
void FUN_14027b5a0(i64* p, i64 n) { Unk_StlTag t; FUN_1402769e0(p, n, t); }
// @0x14027b5d0
void FUN_14027b5d0(i64* p, i64 n) { Unk_StlTag t; FUN_140276a10(p, n, t); }
// @0x14027b600
template void std::advance<LHist::iterator, __int64>(LHist::iterator&, __int64);
// @0x14027b630
typedef std::vector<Unk_RemakeLockOpt> VRemake;
template void VRemake::assign(Unk_RemakeLockOpt*, Unk_RemakeLockOpt*);
//
//
//
//
// @0x14027b690
template void VLog::assign(PLog*, PLog*);
//
//
//
//
//

// ---- element construct/destroy helpers (std::allocator_traits<>::construct/destroy of the element types) ----
struct Unk_P8 { i64 v; };
struct Unk_Ref16 { void* m_unknown; void* m_p; };
struct Unk_Tup8 { i64 v; };
i64 FUN_14027c140(i64); i64 FUN_14027c150(i64); i64 FUN_14027c170(i64); i64 FUN_14027c180(i64); i64 FUN_14027c200(i64);
i64 FUN_14027c190(i64); i64 FUN_14027c1d0(i64); i64 FUN_14027c210(i64); i64 FUN_14027c1e0(i64); i64 FUN_14027c1a0(i64);
i64 FUN_14027c230(i64); i64 FUN_14027c1f0(i64);

Unk_Q8* FUN_14027d650(Unk_Q8*, Unk_Q8*);
i64 FUN_140274bb0(i64, Unk_StlTag, i64, i64);
Unk_Ref16* FUN_14027c980(Unk_Ref16*, Unk_Ref16*);


// (0x14027cc30 is Unk_HistRef::Unk_HistRef(const Unk_HistRef&))

// @0x14027b6f0
void FUN_14027b6f0(i64 al, i64 where, i64 src) { ::new((void*)where) i64(*(i64*)FUN_14027c140(src)); }
// @0x14027b740
void FUN_14027b740(i64 al, i64 where, i64 src) { ::new((void*)where) i64(*(i64*)FUN_14027c150(src)); }
// pair<const unsigned,int> piecewise construct: the empty tuple temporary and the key slot; 0x140274bb0 is a free function in commonstruct_wc.
// @0x14027b790
void FUN_14027b790(i64 al, i64 where, i64 a2, i64 b2, i64 c2)
{
    Unk_P8* mem = (Unk_P8*)operator new(8, (void*)where);
    struct { } first; Unk_Q8 second;
    Unk_Q8* p28 = (Unk_Q8*)&first;
    Unk_Q8* p30 = &second;
    reinterpret_cast<void (*)(void*, char, i64, i64)>(&FUN_140274bb0)(mem, *(char*)(i64)&std::forward<const std::piecewise_construct_t&>(*(const std::piecewise_construct_t*)a2), (i64)FUN_14027d650(p30, (Unk_Q8*)FUN_14027c230(b2)),
#ifdef __clang__   // clang types an explicit ctor call as void; same call, then the slot
                  (reinterpret_cast<std::tuple<>*>(p28)->std::tuple<>::tuple(reinterpret_cast<std::tuple<>&>(std::forward<std::tuple<>>(*(std::tuple<>*)c2))), (i64)p28));
#else   // cl: the explicit ctor call yields the object at rax (0x140163dc0 is std::tuple<>::tuple(const tuple&))
                  (i64)&reinterpret_cast<std::tuple<>*>(p28)->std::tuple<>::tuple(reinterpret_cast<std::tuple<>&>(std::forward<std::tuple<>>(*(std::tuple<>*)c2))));
#endif
}
// @0x14027b840
void FUN_14027b840(i64 al, i64 where, i64 src) { ::new((void*)where) Unk_P8(*(Unk_P8*)FUN_14027c170(src)); }
// @0x14027b890
void FUN_14027b890(i64 al, i64 where, i64 src) { ::new((void*)where) ItemEntity(*(ItemEntity*)FUN_14027c180(src)); }
// @0x14027b8e0
void FUN_14027b8e0(i64 al, i64 where, i64 src) { ::new((void*)where) ItemEntity((ItemEntity&&)*(ItemEntity*)FUN_14027c200(src)); }
// @0x14027b930
void FUN_14027b930(i64 al, i64 where, i64 src) { ::new((void*)where) CString(*(CString*)(i64)&std::forward<CStringA&>(*(CStringA*)src)); }
// @0x14027b980
void FUN_14027b980(i64 al, i64 where, i64 src) { ::new((void*)where) CString(*(CString*)(i64)&reinterpret_cast<CStringA&>(std::forward<CStringA>(*(CStringA*)src))); }
// @0x14027b9d0
void FUN_14027b9d0(i64 al, i64 where, i64 src) { ((PIng*)::new((void*)where) Unk_Ref16)->PIng::MS2Ptr(*(PIng*)FUN_14027c190(src)); }
// @0x14027ba20
void FUN_14027ba20(i64 al, i64 where, i64 src) { ((PIng*)::new((void*)where) Unk_Ref16)->PIng::MS2Ptr(*(PIng*)FUN_14027c1d0(src)); }
// @0x14027ba70
void FUN_14027ba70(i64 al, i64 where, i64 src) { FUN_14027c980(::new((void*)where) Unk_Ref16, (Unk_Ref16*)FUN_14027c210(src)); }
// @0x14027bac0
void FUN_14027bac0(i64 al, i64 where, i64 src) { reinterpret_cast<Unk_HistRef*>(::new((void*)where) Unk_Ref16)->Unk_HistRef::Unk_HistRef(*(Unk_HistRef*)FUN_14027c1e0(src)); }
// @0x14027bb10
void FUN_14027bb10(i64 al, i64 where, i64 src) { ((PLog*)::new((void*)where) Unk_Ref16)->PLog::MS2Ptr(*(PLog*)FUN_14027c1a0(src)); }
// @0x14027bb60
void FUN_14027bb60(i64*, i64) {}
// @0x14027bb70
void FUN_14027bb70(i64*, i64) {}
// @0x14027bb80
void FUN_14027bb80(i64*, i64) {}

// virtual-destructor element destroy (slot 0 = scalar deleting dtor, called with flag 0)
struct Unk_VDtor { virtual ~Unk_VDtor(); };
// @0x14027bb90
void FUN_14027bb90(i64 al, Unk_VDtor* p) { p->~Unk_VDtor(); }
// @0x14027bbc0
void FUN_14027bbc0(i64 al, i64 p) { reinterpret_cast<CStringA*>(p)->~CStringT(); }
// @0x14027bbe0
void FUN_14027bbe0(i64 al, i64 p) { reinterpret_cast<PIng*>(p)->~PIng(); }
// @0x14027bc00
void FUN_14027bc00(i64 al, i64 p) { reinterpret_cast<MS2Ptr<CPtred>*>(p)->~MS2Ptr(); }
// @0x14027bc20
void FUN_14027bc20(i64 al, i64 p) { reinterpret_cast<MS2Ptr<CUserChangeableItemHistory>*>(p)->~MS2Ptr(); }

i64 FUN_140277600(i64, i64, Unk_StlTag); i64 FUN_140277630(i64, i64, Unk_StlTag); i64 FUN_140277660(i64, i64, Unk_StlTag);
// @0x14027bc40
i64 FUN_14027bc40(i64 first, i64 last) { Unk_StlTag t; return FUN_140277600(first, last, t); }
// @0x14027bc70
template std::_Iter_diff_t<PIng*> std::distance<PIng*>(PIng*, PIng*);
// @0x14027bca0
i64 FUN_14027bca0(i64 first, i64 last) { Unk_StlTag t; return FUN_140277660(first, last, t); }

// vector::push_back(const T&) bodies: construct at end when it has room, otherwise reallocate
//
//
//
// @0x14027bcd0
template decltype(auto) VIng::emplace_back<const PIng&>(const PIng&);   // vector<MS2Ptr<CIngredientInfo>>::emplace_back (was FUN_14027bcd0)
//
//
//
// @0x14027bd40
template decltype(auto) VItem::emplace_back<ItemEntity>(ItemEntity&&);   // vector<ItemEntity>::emplace_back (was FUN_14027bd40)
//
//
//
//
//
//
//
// @0x14027bdb0
template decltype(auto) VStr::emplace_back<CString>(CString&&);   // vector<CString>::emplace_back (was FUN_14027bdb0)
//
//
//
//
//
//
//
// @0x14027be20
template decltype(auto) VIng::emplace_back<PIng>(PIng&&);   // vector<MS2Ptr<CIngredientInfo>>::emplace_back (was FUN_14027be20)
//
//
//
//
//
//
//

// _Tree::emplace_hint(where, piecewise_construct, tuple<K&&>, tuple<>)
i64 FUN_140277000(i64, i64, i64, i64); struct Unk_TIter; struct Unk_TNode; Unk_TIter* InsertHint(void*, Unk_TIter*, Unk_TIter, i64, Unk_TNode*);
// @0x14027be90
i64 EmplaceHint(i64 tree, i64 out, i64 where, i64 piecewise, i64 keytuple, i64 valtuple)
{
    i64 node = FUN_140277000(tree, (i64)&std::forward<const std::piecewise_construct_t&>(*(const std::piecewise_construct_t*)piecewise), FUN_14027c230(keytuple), (i64)&reinterpret_cast<std::tuple<>&>(std::forward<std::tuple<>>(*(std::tuple<>*)valtuple)));
    reinterpret_cast<void (*)(i64, i64, i64, i64, i64)>(&InsertHint)(tree, out, where, node + 0x1c, node);
    return out;
}

// std::find_if over a vector<Unk_IngRef> with a by-value predicate argument
/* FUN_1402769a0 = std::_Adl_verify_range, FUN_140278760 = std::_Get_unwrapped */ void SeekTo(i64, i64*);
// @0x14027bf30
VIng::iterator FUN_14027bf30(VIng::iterator first, VIng::iterator last, int key)
{
    std::_Adl_verify_range(first, last);
    i64 f = (i64)std::_Get_unwrapped(first);
    i64 l = (i64)std::_Get_unwrapped(last);
    for (; f != l; f += 0x10) {



        if (reinterpret_cast<bool (*)(int*, PIng)>(&FUN_14026b560)(&key, *(PIng*)f))
            break;
    }
    SeekTo((i64)&first, &f);
    return first;
    //
}

// fmt::internal::MakeValue<BasicFormatter<wchar_t>>(const int&): the generic ostream-formatted argument (type 0xa)
struct Unk_FmtVal : fmt::internal::Value { int type; };
// C3: the 16-byte argument value is built by fmt::internal::MakeValue<BasicFormatter<wchar_t>>(const std::wstring&)
// (0x140182090, ms2/fmt/format.h)
// @0x14027bff0
// fmt: an int writes the argument directly; the disabled path formats through a wide stream.
void FUN_14027bff0(i64 ctx, i64* out, int* value)
{
    Unk_FmtVal v;
    Unk_FmtVal* pv = &v;
    if (!(0 == 1)) {
        v.int_value = *value;
        v.type = 1;
    } else {
        std::wostringstream oss;
        oss << *value;
        std::wstring text = oss.str();
        //
        *(fmt::internal::Value*)pv = fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(text);
        v.type = 10;
    }
    *out = (i64)reinterpret_cast<fmt::BasicFormatter<wchar_t>*>(ctx)->format(*(const wchar_t**)out, *(const fmt::internal::Arg*)&v);
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

__int64 FUN_140274c00(__int64, __int64);   // C3: was FUN_140274c00
// @0x14027c240
i64 FUN_14027c240(i64 a, i64 b) { FUN_140274c00(a, FUN_14027c1f0(b)); return a; }
// @0x14027c270
i64 FUN_14027c270(i64* p) { return FUN_14027c1f0(*p); }

// vector<Unk_IngRef>::insert(where, first, last)
// MS2-PIN: ??$distance@PEAV?$MS2Ptr@VCIngredientInfo@@@@@std@@YA_JPEAV?$MS2Ptr@VCIngredientInfo@@@@0@Z 0x14027bc70 ; unique
// @0x14027c290
template VIng::iterator VIng::insert<VIng::iterator, void>(VIng::const_iterator, VIng::iterator, VIng::iterator);









// fmt::internal::make_type<T>(const T&) instances: forward to the per-type MakeValue::type()
// @0x14027c340
u64 FUN_14027c340(i64 p) { return fmt::internal::MakeValue<fmt::BasicFormatter<char>>::type((const wchar_t*)p); }
// @0x14027c360
u64 FUN_14027c360(i64 p) { return fmt::internal::MakeValue<fmt::BasicFormatter<char>>::type(*(float*)p); }
// @0x14027c380
u64 FUN_14027c500(i64);
u64 FUN_14027c380(i64 p) { return FUN_14027c500(p); }
// @0x14027c3a0
u64 FUN_14027c3a0(i64 p) { return fmt::internal::MakeValue<fmt::BasicFormatter<char>>::type(*(i64*)p); }
// @0x14027c3c0
u64 FUN_14027c3c0(i64 p) { return fmt::internal::MakeValue<fmt::BasicFormatter<char>>::type(*(bool*)p); }
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
template LHist::iterator std::next<LHist::iterator>(LHist::iterator, __int64);
struct Unk_TIterBool; Unk_TIterBool* TryEmplace(void*, Unk_TIterBool*, i64);
// @0x14027c4c0
i64 FUN_14027c4c0(i64 a, i64 b, i64 c) { reinterpret_cast<void (*)(i64, i64, i64)>(&TryEmplace)(a, b, c); return b; }
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
// @0x14027c6b0
Unk_Rec48* FUN_14027c6b0(Unk_Rec48* t, int n, float x, float y, float z, int e)
{
    t->a = 0; t->b = 0; t->n = n; t->x = x; t->y = y; t->z = z;
    t->id = 0xFFFFFFFF; t->c = 0; t->d = 0; t->e = e; t->f = 0; t->g = 0;
    ((ATL::CAtlMap<int, int, ATL::CElementTraits<int>, ATL::CElementTraits<int>>*)(struct Unk_Rec48*)(t))->SetOptimalLoad(x, y, z, false);
    return t;
}
// @0x14027c7a0
Unk_Rec48* FUN_14027c7a0(Unk_Rec48* t, int n, float x, float y, float z, int e)
{
    t->a = 0; t->b = 0; t->n = n; t->x = x; t->y = y; t->z = z;
    t->id = 0xFFFFFFFF; t->c = 0; t->d = 0; t->e = e; t->f = 0; t->g = 0;
    reinterpret_cast<ATL::CAtlMap<int, Unk_LimitValue>*>(t)->SetOptimalLoad(x, y, z, false);
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
// (the copies of the real types are explicit instantiations: MS2Ptr<T>/TPtrValue<T> copy ctors, AddRef in the body)
void FUN_140286550(Unk_Ref16*); class CUgcItemLook;
void FUN_140286670(Unk_Ref16*);
// @0x14027c980
Unk_Ref16* FUN_14027c980(Unk_Ref16* t, Unk_Ref16* o) { t->m_p = o->m_p; o->m_p = 0; return t; }
// @0x14027c9b0
template MS2Ptr<CIngredientInfo>::MS2Ptr(const MS2Ptr<CIngredientInfo>&);
// @0x14027c9f0
template MS2Ptr<CIngredientInfo>::MS2Ptr(int);
// @0x14027ca10
template MS2Ptr<CIngredientInfo>::MS2Ptr(CIngredientInfo*);
// @0x14027ca40
template TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>::TPtrValue(const TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>&);
// @0x14027ca80
Unk_Ref16* FUN_14027ca80(Unk_Ref16* t, int) { t->m_p = 0; return t; }
// @0x14027caa0
template MS2Ptr<AdditionalEffectEventCtx>::MS2Ptr(const MS2Ptr<AdditionalEffectEventCtx>&);
class CAdditionalEvent; typedef MS2Ptr<CAdditionalEvent> Unk_RefT;   // C3: was a Unk_Ref16 view
// @0x14027cae0
template MS2Ptr<CAdditionalEvent>::MS2Ptr(CAdditionalEvent*);
// @0x14027cb10
template MS2Ptr<CAdditionalEvent>::MS2Ptr();
// @0x14027cb30
Unk_Ref16* FUN_14027cb30(Unk_Ref16* t, int) { t->m_p = 0; return t; }
// @0x14027cb50
Unk_Ref16* FUN_14027cb50(Unk_Ref16* t) { t->m_p = 0; return t; }
// @0x14027cb70
Unk_Ref16* FUN_14027cb70(Unk_Ref16* t, int) { t->m_p = 0; return t; }
// @0x14027cb90
template MS2Ptr<CUgcItemLook>::MS2Ptr(int);
// @0x14027cbb0
template MS2Ptr<CUgcItemLook>::MS2Ptr(CUgcItemLook*);
// @0x14027cbe0
Unk_HistRef::Unk_HistRef(Unk_HistRef&& o) { m_p = o.m_p; o.m_p = 0; }   // was the free FUN_14027cbe0(Unk_Ref16*, Unk_Ref16*)
// @0x14027cc10
Unk_HistRef::Unk_HistRef(decltype(nullptr)) { m_p = 0; }   // was the free FUN_14027cc10(Unk_Ref16*, void*), aliased from this name
// @0x14027cc30
Unk_HistRef::Unk_HistRef(const Unk_HistRef& o) { m_p = o.m_p; reinterpret_cast<const MS2Ptr<CPtred>*>(this)->AddRef(); }   // was the free FUN_14027cc30(Unk_Ref16*, Unk_Ref16*)
// @0x14027cc70
template MS2Ptr<CUserLimitHistory>::MS2Ptr(const MS2Ptr<CUserLimitHistory>&);
// @0x14027ccb0
template PLog::MS2Ptr(const PLog&);
// @0x14027ccf0
template MS2SvrPtr<CPtred>::MS2SvrPtr(MS2SvrPtr<CPtred>&&);
// @0x14027cd20
template MS2SvrPtr<CPtred>::MS2SvrPtr(CPtred*);

// ---- TPtredDummy<CAtlList<TPtr<CUserLimitHistory>>>-style box: CPtred base, the list at +0x18 ----
#include "ms2/placeholder/ms2ptr_impl.h"
struct Unk_ListBox : CPtred {
    Unk_List value;
    Unk_ListBox();
};
// MS2-PIN: ??_7Unk_ListBox@@6B@ 0x142d15c08
// @0x14027cd50
Unk_ListBox::Unk_ListBox() { FUN_14027c5f0(&value, 10); }

// ---- std::_Compressed_pair / _Uninitialized_backout ctor glue ----
// the exe's functions that call a member-subobject ctor at +0 (address of the first member is computed into rax first)
i64 FUN_1402749c0(i64, Unk_StlTag);
i64 FUN_140274b60(i64, Unk_StlTag, i64, i64);
Unk_PairHolder* FUN_14027cda0(Unk_PairHolder*);
// @0x14027cda0
Unk_PairHolder* FUN_14027cda0(Unk_PairHolder* t)
{
    FUN_1402749c0((i64)&t->pair, Unk_StlTag());
    i64 r = (i64)reinterpret_cast<LHist*>(t)->_Buyheadnode();
    *(i64*)&reinterpret_cast<LHist*>(t)->_Myhead() = r;
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
void* FUN_14027ce90(void* t, i64 a, i64 b) { *(i64*)t = a; reinterpret_cast<std::_Iterator_base0*>(t)->_Adopt((const void*)b); return t; }
// @0x14027ced0
void* FUN_14027ced0(void* t, i64 a, i64 b) { FUN_14027ce90(t, a, b); return t; }
struct Unk_Z16 { i64 a, b; };
// @0x14027cf10
Unk_Z16* FUN_14027cf10(Unk_Z16* t) { t->a = 0; t->b = 0; return t; }
Unk_PairHolder* FUN_14027cf70(Unk_PairHolder*, i64);
// @0x14027cf40
Unk_PairHolder* FUN_14027cf40(Unk_PairHolder* t, i64 p) { FUN_14027cf70(t, p); return t; }
// @0x14027cf70
Unk_PairHolder* FUN_14027cf70(Unk_PairHolder* t, i64 p) { char loc; FUN_140274b60((i64)&t->pair, Unk_StlTag(), p, (i64)&loc); reinterpret_cast<MapII*>(t)->_Construct(); return t; }
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
void* FUN_14027d050(void* t, i64 a, i64 b) { *(i64*)t = a; reinterpret_cast<std::_Iterator_base0*>(t)->_Adopt((const void*)b); return t; }
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

i64 FUN_140274a20(i64, Unk_StlTag); i64 FUN_140274a50(i64, Unk_StlTag); i64 FUN_140274a80(i64, Unk_StlTag);
i64 FUN_140274ab0(i64, Unk_StlTag); i64 FUN_140274ae0(i64, Unk_StlTag);
// @0x14027d220
Unk_PairHolder* FUN_14027d220(Unk_PairHolder* t) { FUN_140274a20((i64)&t->pair, Unk_StlTag()); return t; }
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@@std@@QEAA@XZ 0x14027d250 ; unique
template std::_Vector_alloc<std::_Vec_base_types<ItemEntity, std::allocator<ItemEntity>>>::_Vector_alloc();   // C3: was FUN_14027d250 -> FUN_140274a50
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEAA@XZ 0x14027d280 ; unique
template std::_Vector_alloc<std::_Vec_base_types<CString, std::allocator<CString>>>::_Vector_alloc();   // C3: was FUN_14027d280 -> FUN_140274a80
// @0x14027d2b0
template std::_Vector_alloc<std::_Vec_base_types<PIng, std::allocator<PIng>>>::_Vector_alloc();
// @0x14027d2e0
Unk_PairHolder* FUN_14027d2e0(Unk_PairHolder* t) { FUN_140274ae0((i64)&t->pair, Unk_StlTag()); return t; }
// @0x14027d310
void* FUN_14027d310(void* t, i64 a, i64 b) { *(i64*)t = a; reinterpret_cast<std::_Iterator_base0*>(t)->_Adopt((const void*)b); return t; }
// @0x14027d350
void* FUN_14027d350(void* t, i64 a, i64 b) { *(i64*)t = a; reinterpret_cast<std::_Iterator_base0*>(t)->_Adopt((const void*)b); return t; }
// @0x14027d390
void* FUN_14027d390(void* t, i64 a, i64 b) { FUN_14027d310(t, a, b); return t; }
// @0x14027d3d0
void* FUN_14027d3d0(void* t, i64 a, i64 b) { FUN_14027d350(t, a, b); return t; }
struct Unk_Z24 { i64 a, b, c; };
// @0x14027d410
Unk_Z24* FUN_14027d410(Unk_Z24* t) { t->a = 0; t->b = 0; t->c = 0; return t; }
// @0x14027d450
template std::_Vector_val<std::_Simple_types<ItemEntity>>::_Vector_val();   // C3: was FUN_14027d450
// @0x14027d490
template std::_Vector_val<std::_Simple_types<CString>>::_Vector_val();   // C3: was FUN_14027d490
// @0x14027d4d0
template std::_Vector_val<std::_Simple_types<PIng>>::_Vector_val();
// @0x14027d510
Unk_Z24* FUN_14027d510(Unk_Z24* t) { t->a = 0; t->b = 0; t->c = 0; return t; }
// @0x14027d550
void* FUN_14027d550(void* t) { return t; }
// @0x14027d560
void* FUN_14027d560(void* t) { return t; }
// @0x14027d570
void* FUN_14027d570(void* t) { return t; }
// @0x14027d580
template std::allocator<ItemEntity>::allocator() noexcept;   // C3: was FUN_14027d580
// @0x14027d590
template std::allocator<CString>::allocator() noexcept;   // C3: was FUN_14027d590
// @0x14027d5a0
template std::allocator<PIng>::allocator() noexcept;
// @0x14027d5b0
void* FUN_14027d5b0(void* t) { return t; }
// @0x14027d5c0
Unk_CommonBytes4* FUN_14027d5c0(Unk_CommonBytes4* t) noexcept { memset(&t->raw, 0, sizeof(t->raw)); return t; }
// @0x14027d5e0
Unk_HistList::Unk_HistList() { FUN_14027cdf0(reinterpret_cast<Unk_PairHolder*>(this)); }   // the std::list ctor; was the free FUN_14027d5e0(Unk_PairHolder*), aliased from this name
// @0x14027d600
Unk_RewardMap::Unk_RewardMap() { char loc; FUN_14027cf40(reinterpret_cast<Unk_PairHolder*>(this), (i64)&loc); }   // the std::map ctor; was the free FUN_14027d600(Unk_PairHolder*), aliased from this name
// @0x14027d630
template std::reverse_iterator<VItem::iterator>::reverse_iterator(VItem::iterator);
// @0x14027d650
Unk_Q8* FUN_14027d650(Unk_Q8* t, Unk_Q8* p) { reinterpret_cast<std::tuple<>*>(t)->std::tuple<>::tuple(*reinterpret_cast<std::tuple<>*>(p)); *t = *p; return t; }
// @0x14027d690
Unk_PairHolder* FUN_14027d690(Unk_PairHolder* t) noexcept { FUN_14027d220(t); return t; }
// MS2-PIN: ??0?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEAA@XZ 0x14027d6c0 ; unique
template VItem::vector() noexcept;   // C3: was FUN_14027d6c0
// MS2-PIN: ??0?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAA@XZ 0x14027d6f0 ; unique
template VStr::vector() noexcept;   // C3: was FUN_14027d6f0 (also ??0Unk_StrVec)
// @0x14027d720
template VIng::vector() noexcept;
// @0x14027d750
Unk_PairHolder* FUN_14027d750(Unk_PairHolder* t) noexcept { FUN_14027d2e0(t); return t; }

// ---- small value types: ctors / copy ctors (all inline COMDATs of the element types in the exe) ----
class CAdditionalEvent;
struct Unk_ListB : Unk_List { ~Unk_ListB() throw(); };
// ATL::CAtlList dtors: RemoveAll(), then the (empty) ATLASSERT do-while
struct Unk_ListA : Unk_List { ~Unk_ListA() throw(); };
// @0x14027de70
Unk_ListA::~Unk_ListA() throw() { reinterpret_cast<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>*>(this)->RemoveAll(); do {} while (0); }
// @0x14027de90
Unk_ListB::~Unk_ListB() throw() { reinterpret_cast<ATL::CAtlList<Unk_AdditionalEventValue>*>(this)->RemoveAll(); do {} while (0); }

class CAdditionalEvent : public CPtred { public:
    Unk_ListB events;
    CAdditionalEvent();
    // @0x14027e590
    virtual ~CAdditionalEvent() = default;
};
// @0x14027d780
inline CAdditionalEvent::CAdditionalEvent() { FUN_14027c650(&events, 10); }  // inline: unit_140267670's new T() emits the implicit copy
void Unk_AnchorAdditionalEvent(CAdditionalEvent* p) { p->CAdditionalEvent::~CAdditionalEvent(); new (p) CAdditionalEvent; }

// @0x14027d7d0
CIngredientInfo::CIngredientInfo(int a, int b, int c) : m_a(a), m_b(c), m_c(b) {}
// @0x14027d830
CIngredientInfo::CIngredientInfo() : m_a(0), m_b(0), m_c(0) {}

// @0x14027d900
Unk_CommonPrice::Unk_CommonPrice(int type, int subType, __int64 amount) : m_type(type), m_subType(subType), m_amount(amount) {}
// @0x14027d940
Unk_CommonPrice::Unk_CommonPrice() : m_type(0), m_subType(0), m_amount(0) {}
// @0x14027d880
Unk_CommonPriceRecord::Unk_CommonPriceRecord(int type, int subType, __int64 amount, __int64 usedTime) : m_price(type, subType, amount), m_usedTime(usedTime) {}
// @0x14027d8d0
Unk_CommonPriceRecord::Unk_CommonPriceRecord() : m_usedTime(0) {}

struct Unk_InnerA { void* p; };
struct Unk_InnerB { void* p; };
//
//
struct Unk_RecA { int v; Unk_InnerA in; Unk_RecA(const Unk_RecA&); };
struct Unk_RecB { int v; Unk_InnerB in; Unk_RecB(const Unk_RecB&); };
// @0x14027dd20
Unk_RecA::Unk_RecA(const Unk_RecA& o) : v(o.v) { reinterpret_cast<COutPacketPtr*>(&in)->COutPacketPtr::Unk_PktPtr(static_cast<COutPacketPtr&&>(*reinterpret_cast<COutPacketPtr*>(const_cast<Unk_InnerA*>(&o.in)))); }
// @0x14027dd60
Unk_RecB::Unk_RecB(const Unk_RecB& o) : v(o.v) { reinterpret_cast<COutPacketPtr*>(&in)->COutPacketPtr::Unk_PktPtr(*reinterpret_cast<const COutPacketPtr*>(&o.in)); }
struct Unk_Holder10 { i64 pad0, pad1; Unk_RecB rec; Unk_Holder10(const Unk_RecB& r); };
// @0x14027d970
Unk_Holder10::Unk_Holder10(const Unk_RecB& r) : rec(r) {}
struct Unk_Holder10R { i64 pad0, pad1; Unk_Ref16 r; };
// @0x14027d9a0
Unk_Holder10R* FUN_14027d9a0(Unk_Holder10R* t, Unk_Ref16* p) { reinterpret_cast<MS2Ptr<CUserLimitHistory>*>(&t->r)->MS2Ptr<CUserLimitHistory>::MS2Ptr(*(MS2Ptr<CUserLimitHistory>*)p); return t; }
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
Unk_RefRec* FUN_14027db00(Unk_RefRec* t, i64 a, Unk_Ref16* b) { t->a = a; reinterpret_cast<TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>*>(&t->r)->TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>::TPtrValue(*(TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>*)b); return t; }
// @0x14027da70
Unk_RefRec* FUN_14027da70(Unk_RefRec* t, i64 a, Unk_Ref16* b) { FUN_14027db00(t, a, b); t->flag = 1; t->tail = 0; return t; }
struct Unk_V3 { float x, y, z; };
// @0x14027db40
Unk_V3* FUN_14027db40(Unk_V3* t, float x, float y, float z) { t->x = x; t->y = y; t->z = z; return t; }
// @0x14027dda0
Unk_V3* FUN_14027dda0(Unk_V3* t, float x, float y, float z) { t->x = x; t->y = y; t->z = z; return t; }
struct Unk_Z16i { int a, b, c, d; }; struct Unk_QuestMaskRange : Unk_Z16i { Unk_QuestMaskRange(); };
// @0x14027dcb0
Unk_QuestMaskRange::Unk_QuestMaskRange() { a = 0; b = 0; c = 0; d = 0; }
// @0x14027dcf0
Unk_V3* FUN_14027dcf0(Unk_V3* t, const Unk_V3* o) { *t = *o; return t; }

// ATL::CAtlArray dtors (the ATL header body), emitted by FUN_14027e920 and MS2_EmitImplicitDtors_commonstruct2 below
// MS2-PIN: ??1?$CAtlArray@UUnk_Z16i@@V?$CElementTraits@UUnk_Z16i@@@ATL@@@ATL@@QEAA@XZ 0x14027ddf0
// MS2-PIN: ??1?$CAtlArray@UUnk_CommonPacketLogEntry@@V?$CElementTraits@UUnk_CommonPacketLogEntry@@@ATL@@@ATL@@QEAA@XZ 0x14027de30

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
i64 FUN_140288e10(void*); i64 FUN_140288e50(void*); i64 FUN_140288e90(void*); i64 FUN_140288ed0(void*);
i64 FUN_140288f50(void*); i64 FUN_140288fd0(void*); i64 FUN_140289010(void*);
i64 FUN_140289050(void*); struct Unk_CsI64Vec { void Tidy(); }; i64 FUN_140289810(void*); i64 FUN_1402898e0(void*);
i64 FUN_1402899b0(void*); i64 FUN_140289650(void*); i64 FUN_1402895f0(void*);
void FUN_140287dc0(void*, i64);
// MS2-PIN: ??1?$MS2Ptr@VCIngredientInfo@@@@QEAA@XZ 0x14027df70
template MS2Ptr<CIngredientInfo>::~MS2Ptr();
// @0x14027e060
Unk_HistRef::~Unk_HistRef() { reinterpret_cast<MS2Ptr<CUserChangeableItemHistory>*>(this)->Release(); }
// @0x14027e0c0
Unk_ProdRef::~Unk_ProdRef() { reinterpret_cast<MS2Ptr<ChangeableProductInfo>*>(this)->Release(); }
// @0x14027e150
template MS2SvrPtr<CPtred>::~MS2SvrPtr();
// @0x14027dfa0
template TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>::~TPtrValue();   // was FUN_14027dfa0 calling FUN_140288e10 (the private Release)
// @0x14027dfd0
template MS2Ptr<AdditionalEffectEventCtx>::~MS2Ptr();
// @0x14027e000
template MS2Ptr<CAdditionalEvent>::~MS2Ptr();
// @0x14027e030
template MS2Ptr<CItemOption>::~MS2Ptr();   // C3: was FUN_14027e030 calling FUN_140288ed0 (Release)
// @0x14027e090
template MS2Ptr<CUserLimitHistory>::~MS2Ptr();   // was FUN_14027e090 calling FUN_140288f50 (the private Release)
// @0x14027e0f0
class InvokeEffectOption; template MS2Ptr<InvokeEffectOption>::~MS2Ptr();   // C3: was FUN_14027e0f0 calling FUN_140288fd0
// @0x14027e120
template PLog::~MS2Ptr();   // C3: was FUN_14027e120 calling FUN_140289010
// @0x14027e3f0
void FUN_14027e3f0(void* t) noexcept { reinterpret_cast<Unk_CsI64Vec*>(t)->Tidy(); }
// @0x14027e4b0
template VLog::~vector();   // C3: was FUN_14027e4b0 calling FUN_1402899b0 (_Tidy, ICF with vector<MS2Ptr<CPtred>>)
// @0x14027deb0
void FUN_14027deb0(void* t) { try { reinterpret_cast<ATL::CAtlMap<unsigned, unsigned>*>(t)->RemoveAll(); } catch (...) {} }
// @0x14027dee0
void FUN_14027dee0(void* t) { try { reinterpret_cast<ATL::CAtlMap<int, Unk_LimitValue>*>(t)->RemoveAll(); } catch (...) {} }
// @0x14027e420
template VItem::~vector();
// @0x14027e450
template VStr::~vector();   // C3: was ~Unk_StrVec calling FUN_140289810 (_Tidy)
// @0x14027e480
template VIng::~vector();

// a list/map header (std::list<Unk_HistRef> / std::map<unsigned,int>): _Tidy = clear + free the sentinel node
// @0x14027e1b0
void FreeHeadNode(Unk_HistList* t) noexcept { reinterpret_cast<LHist*>(t)->_Freeheadnode((NodeHist*)*(i64*)&reinterpret_cast<LHist*>(t)->_Myhead()); }
// @0x14027e1e0
void FUN_14027e1e0(Unk_HistList* t) { FreeHeadNode(t); }
// @0x14027e3a0
Unk_HistList::~Unk_HistList() { reinterpret_cast<LHist*>(this)->_Tidy(); FUN_14027e1e0(this); }
// @0x14027e230
// (the real ~_Tree_comp_alloc, instantiated by ~_Tree below; was the hand FUN_14027e230 calling FUN_140287dc0)
// @0x14027e200
typedef std::_Tree<std::_Tmap_traits<int, int, std::less<int>, std::allocator<std::pair<const int, int> >, false> > TreeII; template TreeII::~_Tree();   // C3: was FUN_14027e200 calling FUN_1402895f0 (_Tidy) + FUN_14027e230
// @0x14027e3d0
Unk_RewardMap::~Unk_RewardMap() { reinterpret_cast<TreeII*>(this)->TreeII::~_Tree(); }

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
// (the MS2Ptr<T>/TPtrValue<T> ones are explicit instantiations of operator=)
// @0x14027e950
template PIng& PIng::operator=(const PIng&);
// @0x14027e990
template TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>& TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>::operator=(const TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>&);
// @0x14027ea40
template MS2Ptr<CItemOption>& MS2Ptr<CItemOption>::operator=(const MS2Ptr<CItemOption>&);
// @0x14027ea80
template MS2Ptr<CItemOption>& MS2Ptr<CItemOption>::operator=(int);   // C3: was FUN_14027ea80 calling FUN_140288ed0
// @0x14027eab0
Unk_HistRef& Unk_HistRef::Assign(Unk_HistRef& o) { reinterpret_cast<const MS2Ptr<CPtred>*>(&o)->AddRef(); reinterpret_cast<MS2Ptr<CUserChangeableItemHistory>*>(this)->Release(); m_p = o.m_p; return *this; }   // was the free Assign(Unk_Ref16*, Unk_Ref16*)
// @0x14027eaf0
template PLog& PLog::operator=(const PLog&);
// operator=(T*): swap with a temporary
// @0x14027e9d0
template MS2Ptr<CAdditionalEvent>& MS2Ptr<CAdditionalEvent>::AssignRaw(CAdditionalEvent*);
//
//
//
//
//
//
//

// ---- remaining class dtors, wrappers, comparisons and array accessors ----
struct Unk_A28 { i64 pad[5]; void* p28; };
// @0x14027df30
void FUN_14027df30(Unk_A28* t) { reinterpret_cast<ATL::CRBTree<unsigned __int64, TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>>*>(t)->RemoveAll(); if (t->p28) ::free(t->p28); }
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
#include "ms2/placeholder/itemcustom.h"   // ItemCustom: its implicit dtor 0x14027e890 is emitted below
// @0x14027e4e0
void FUN_14027e4e0(Unk_DtW30* t) { t->s.CStringW::~CStringW(); t->CPtred::~CPtred(); }
// 0x14027e890 = ItemCustom::~ItemCustom, implicit (no vptr store); MS2_EmitImplicitDtors_commonstruct2 odr-uses it
// MS2-PIN: ??1ItemCustom@@UEAA@XZ 0x14027e890
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
void MS2_EmitImplicitDtors_commonstruct2(CUserChangeableItemHistory* p0, ChangeableProductInfo* p1, HomeBlockInfo* p2, ItemDropItemLife* p3, NpcShopItemLife* p4,
    ATL::CAtlArray<Unk_CommonPacketLogEntry>* p5, ItemCustom* p6)
{
    p5->ATL::CAtlArray<Unk_CommonPacketLogEntry>::~CAtlArray();
    p0->CUserChangeableItemHistory::~CUserChangeableItemHistory();
    p1->ChangeableProductInfo::~ChangeableProductInfo();
    p2->HomeBlockInfo::~HomeBlockInfo();
    p3->ItemDropItemLife::~ItemDropItemLife();
    p4->NpcShopItemLife::~NpcShopItemLife(); p6->ItemCustom::~ItemCustom();
}
// MS2-PIN: ??1CUserChangeableItemHistory@@UEAA@XZ 0x14027e7a0
// MS2-PIN: ??1ChangeableProductInfo@@UEAA@XZ 0x14027e7e0
// MS2-PIN: ??1HomeBlockInfo@@UEAA@XZ 0x14027e820
// MS2-PIN: ??1ItemDropItemLife@@UEAA@XZ 0x14027e8c0
// MS2-PIN: ??1NpcShopItemLife@@UEAA@XZ 0x14027e8e0
struct Unk_DtArr38 : CPtred { i64 pad[4]; i64 arr[1]; };
// @0x14027e640
void FUN_14027e640(Unk_DtArr38* t) { reinterpret_cast<ArrI64*>(&t->arr)->ArrI64::~ArrI64(); t->CPtred::~CPtred(); }
struct Unk_DtArr20 : CPtred { i64 pad; ATL::CAtlArray<Unk_Z16i> arr; };
// @0x14027e920
void FUN_14027e920(Unk_DtArr20* t) { t->arr.ATL::CAtlArray<Unk_Z16i>::~CAtlArray(); t->CPtred::~CPtred(); }
struct Unk_DtSk28 : CPtred { i64 pad[1]; CStringW s; char cfg[8]; };
// @0x14027e720
void FUN_14027e720(Unk_DtSk28* t) { FUN_14027deb0(&t->cfg); t->s.CStringW::~CStringW(); t->CPtred::~CPtred(); }
struct Unk_DtSk20 : CPtred { CStringW s; char cfg[8]; };
// @0x14027e760
void FUN_14027e760(Unk_DtSk20* t) { reinterpret_cast<SetU*>(&t->cfg)->SetU::~SetU(); t->s.CStringW::~CStringW(); t->CPtred::~CPtred(); }

struct Unk_At8 { void* pad; char m[8]; };
struct Unk_At10 { void* pad[2]; Unk_At8 m; };
// @0x14027e900
void FUN_14027e900(Unk_At8* t) { reinterpret_cast<PktOut*>(&t->m)->PktOut::~PktOut(); }
// @0x14027e690
void FUN_14027e690(Unk_At10* t) { FUN_14027e900(&t->m); }
// @0x14027e6b0
void FUN_14027e6b0(Unk_At10* t) { reinterpret_cast<MS2Ptr<CUserLimitHistory>*>(&t->m)->MS2Ptr<CUserLimitHistory>::~MS2Ptr(); }
// @0x14027e6d0
void FUN_14027e6d0(void*) {}
// @0x14027e700
void FUN_14027e700(Unk_At8* t) { reinterpret_cast<TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>*>(&t->m)->TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory>>>::~TPtrValue(); }
// @0x14027e6e0
void FUN_14027e6e0(Unk_At8* t) { FUN_14027e700(t); }

// range copy helpers
struct Unk_False { static const bool value = false; };
void FUN_140287550(i64, i64); void FUN_140287580(i64, i64);
// @0x14027eb30
i64 FUN_14027eb30(i64 t, i64 o)
{
    if (t != FUN_14027b500(o)) {
        if (Unk_False::value) reinterpret_cast<Unk_CsI64Vec*>(t)->Tidy();
        FUN_140287550(t, (i64)&reinterpret_cast<const VI64*>(o)->_Getal());
        reinterpret_cast<VRemake*>(t)->assign(*(Unk_RemakeLockOpt**)&reinterpret_cast<const VI64*>(o)->_Myfirst(), *(Unk_RemakeLockOpt**)&reinterpret_cast<const VI64*>(o)->_Mylast());
    }
    return t;
}
// @0x14027ebb0
template VLog& VLog::operator=(const VLog&);   // C3: was the hand FUN_14027ebb0 (dead _Tidy via FUN_1402899b0,
// addressof via FUN_14027b510, _Copy_alloc via FUN_140287580)
//
//
//
//
//
//
//

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
template bool MS2Ptr<CIngredientInfo>::operator==(CIngredientInfo*) const;
// @0x14027ed20
bool Unk_HistRef::operator==(CUserChangeableItemHistory* p) const { return m_p == p; }
// @0x14027eda0
template bool LHist::const_iterator::operator==(const LHist::const_iterator&) const;
// @0x14027ede0
template bool LHist::_Unchecked_const_iterator::operator==(const LHist::_Unchecked_const_iterator&) const;
// @0x14027ee20
template bool MapII::const_iterator::operator==(const MapII::const_iterator&) const;
// @0x14027ee60
template bool VItem::const_iterator::operator==(const VItem::const_iterator&) const;
// @0x14027eeb0
template bool VIng::const_iterator::operator==(const VIng::const_iterator&) const;
// @0x14027ef00
template bool LHist::const_iterator::operator!=(const LHist::const_iterator&) const;
// @0x14027ef40
template bool LHist::_Unchecked_const_iterator::operator!=(const LHist::_Unchecked_const_iterator&) const;
// @0x14027ef80
template bool MapII::const_iterator::operator!=(const MapII::const_iterator&) const;
// @0x14027efc0
template bool VItem::const_iterator::operator!=(const VItem::const_iterator&) const;
// @0x14027f000
template bool VIng::const_iterator::operator!=(const VIng::const_iterator&) const;

// ATL::CAtlArray::operator[] with the E_INVALIDARG bounds check
struct Unk_E16 { i64 a, b; };
struct Unk_E24 { i64 a, b, c; };
struct Unk_Arr16 { Unk_E16* data; u64 size; };
struct Unk_Arr24 { Unk_E24* data; u64 size; };
// @0x14027f040
Unk_E16* FUN_14027f040(Unk_Arr16* t, u64 i) { if (i >= t->size) ATL::AtlThrowImpl(0x80070057); return &t->data[i]; }
// @0x14027f080
Unk_E16* FUN_14027f080(Unk_Arr16* t, u64 i) { if (i >= t->size) ATL::AtlThrowImpl(0x80070057); return &t->data[i]; }
// @0x14027f100
Unk_E16* FUN_14027f100(Unk_Arr16* t, u64 i) { if (i >= t->size) ATL::AtlThrowImpl(0x80070057); return &t->data[i]; }
// @0x14027f140
Unk_E16* FUN_14027f140(Unk_Arr16* t, u64 i) { if (i >= t->size) ATL::AtlThrowImpl(0x80070057); return &t->data[i]; }
// @0x14027f0c0
Unk_E24* FUN_14027f0c0(Unk_Arr24* t, u64 i) { if (i >= t->size) ATL::AtlThrowImpl(0x80070057); return &t->data[i]; }

struct Unk_UIPair { unsigned first; int second; };
// @0x14027f180
int& Unk_RewardMap::FUN_14027f180(unsigned& key)
{
    i64 loc;
    return reinterpret_cast<MapII::iterator*>(FUN_14027c4c0((i64)this, (i64)&loc, (i64)&key))->operator->()->second;
}
// @0x14027f1c0
CString* Unk_StrVec::GetAt(size_t i) { return (CString*)*(i64*)(i64)&reinterpret_cast<VStr*>((i64)this)->_Myfirst() + i; }
// @0x14027f1f0
template PIng& VIng::operator[](size_t);
// @0x14027f220
template const PIng& VIng::operator[](size_t) const;
// @0x14027f250
template CIngredientInfo* MS2Ptr<CIngredientInfo>::get() const;
// @0x14027f260
void* FUN_14027f260(Unk_Ref16* t) { return t->m_p; }
// @0x14027f270
void* FUN_14027f270(Unk_Ref16* t) { return t->m_p; }
// @0x14027f2c0
template CIngredientInfo* MS2Ptr<CIngredientInfo>::operator->() const;
// @0x14027f280
Unk_List* FUN_14027f280(Unk_ListBox* t) { return !t ? 0 : &t->value; }
// @0x14027e7c0
void FUN_14027e7c0(CPtred* t) { t->CPtred::~CPtred(); }
// MS2-PIN: ??0?$MS2Ptr@VAdditionalEffectEventCtx@@@@QEAA@AEBV0@@Z 0x14027caa0
// MS2-PIN: ??0?$MS2Ptr@VLogContext@Probability@@@@QEAA@AEBV0@@Z 0x14027ccb0
// MS2-PIN: ??4?$MS2Ptr@VCIngredientInfo@@@@QEAAAEAV0@AEBV0@@Z 0x14027e950
// MS2-PIN: ??1?$MS2Ptr@VAdditionalEffectEventCtx@@@@QEAA@XZ 0x14027dfd0
