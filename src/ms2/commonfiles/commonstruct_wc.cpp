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
int XmlQuery(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873890
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/commonstruct_wb.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/probability.h"
#include "ms2/placeholder/itemremakeoption.h"
#include <list>
#include <map>
#include <vector>
CString Unk_CopyString(const CString& str);   // C3: was FUN_14015efc0 (achievedata.cpp)

// The STL instances the folded COMDATs are named after in the exe (C3: the calls go to their members).
class Unk_XmlNode;
typedef MS2Ptr<CIngredientInfo> PIng;
typedef MS2Ptr<Probability::LogContext> PLog;
typedef std::vector<__int64> VI64;
typedef std::vector<ItemEntity> VItem;
typedef std::vector<CString> VStr;
typedef std::vector<PIng> VIng;
typedef std::vector<PLog> VLog;
typedef std::vector<MS2Ptr<CPtred>> VPtred;
typedef std::vector<Unk_RemakeLockOpt> VRemake;
typedef std::vector<Unk_XmlNode*> VXml;
typedef std::list<MS2Ptr<CUserChangeableItemHistory>> LHist;
typedef std::_List_node<MS2Ptr<CUserChangeableItemHistory>, void*> NodeHist;
typedef std::map<int, int> MapII;
typedef std::_Tree_node<std::pair<const int, int>, void*> NodeII;
typedef std::map<std::pair<unsigned, int>, int> MapPUI;
typedef std::_Tree_node<std::pair<const std::pair<unsigned, int>, int>, void*> NodePUI;

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
    char m_color;
    char m_isNil;
    char m_1a[2];
    Unk_TreeValue m_value;
};
MS2_CHECK_OFFSET(Unk_140277000, m_color, 0x18);
MS2_CHECK_OFFSET(Unk_140277000, m_isNil, 0x19);
MS2_CHECK_OFFSET(Unk_140277000, m_value, 0x1c);

// Same wide log helper as commonstruct.cpp (unit-local there); this slice holds the const wchar_t* instance at 0x140274ea0.
class Unk_CommonLog : public CLogString {
public:
    template<class T> void Log(unsigned __int64 a,unsigned __int64 b,int flags,const wchar_t* format,const T& value) {
        fmt::internal::Value values[]={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(value)};
        FUN_1406535b0(a,b,flags,format,fmt::ArgList(fmt::internal::make_type(value),values));
    }
};

// _Compressed_pair(_One_then_variadic_args_t) view: the allocator base is initialized first, then _Myval2 at offset 0.
struct Unk_WcSelf { i64 m_0; };
// @0x140274970
void FUN_140274970(Unk_CwObj* owner)
{
    CStringW text = reinterpret_cast<DamageCalculatorInfo*>(owner)->ToString();
    FUN_1412751b0(text, 0x14);
}
// @0x1402749c0
i64 FUN_1402749c0(i64 p, Unk_StlTag) { FUN_14027d550((void*)p); FUN_14027cf10((Unk_Z16*)&((Unk_WcSelf*)p)->m_0); return p; }
// @0x1402749f0
i64 FUN_1402749f0(i64 p, char) { FUN_14027d560((void*)p); FUN_14027d0b0((Unk_Z16*)&((Unk_WcSelf*)p)->m_0); return p; }
// @0x140274a20
i64 FUN_140274a20(i64 p, Unk_StlTag) { FUN_14027d570((void*)p); FUN_14027d410((Unk_Z24*)&((Unk_WcSelf*)p)->m_0); return p; }
// @0x140274a50
i64 FUN_140274a50(i64 p, Unk_StlTag) { FUN_14027d580((void*)p); FUN_14027d450((i64)&((Unk_WcSelf*)p)->m_0); return p; }
// @0x140274a80
i64 FUN_140274a80(i64 p, Unk_StlTag) { FUN_14027d590((void*)p); FUN_14027d490((i64)&((Unk_WcSelf*)p)->m_0); return p; }
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140274ab0 ; unique
template std::_Vector_alloc<std::_Vec_base_types<PIng, std::allocator<PIng>>>::_Vector_alloc();   // emits the _Compressed_pair ctor COMDAT pinned above (an explicit instantiation of it ICEs cl 19.16)
// @0x140274ae0
i64 FUN_140274ae0(i64 p, Unk_StlTag) { FUN_14027d5b0((void*)p); FUN_14027d510((Unk_Z24*)&((Unk_WcSelf*)p)->m_0); return p; }
// pair<unsigned,unsigned> built piecewise (key from the tuple, value zero-initialized).
struct Unk_PairU32 { unsigned first; unsigned second; };
// pair<iterator, bool>: the iterator is a one-pointer struct, copied whole.
struct Unk_WcIt { i64 node; };
struct Unk_PairI64B { Unk_WcIt first; char second; };
// @0x140274b10
i64* FUN_140274b10(i64* out, i64 a, i64 b)
{
    ((Unk_PairI64B*)out)->first = *(Unk_WcIt*)FUN_14027c1b0(a);
    ((Unk_PairI64B*)out)->second = *FUN_140162f70(b);
    return out;
}
// @0x140274b60
i64 FUN_140274b60(i64 out, Unk_StlTag, i64 a, i64 b)
{
    FUN_14027c1c0(a);
    FUN_1402749f0((i64)&((Unk_WcSelf*)out)->m_0, *(char*)&reinterpret_cast<std::_Zero_then_variadic_args_t&>(std::forward<std::_Zero_then_variadic_args_t>(*reinterpret_cast<std::_Zero_then_variadic_args_t*>(b))));
    return out;
}
// @0x140274bb0
i64 FUN_140274bb0(i64 out, Unk_StlTag, i64 a, i64 b)
{
    Unk_StlTag seq1, seq2;
    FUN_140274d60((i64*)out, a, b, seq2, seq1);
    return out;
}
// @0x140274c00
i64 FUN_140274c00(i64 out, i64 a) noexcept
{
    Unk_StlTag tag = {};
    FUN_140274cb0(out, tag, a);
    return out;
}
// @0x140274c50
Unk_WcPtrPair* Unk_WcPtrPair::FUN_140274c50(i64 a) { m_0 = FUN_14027c1f0(a); return this; }
// @0x140274c80
i64* FUN_140274c80(i64* out, i64 a) { *out = FUN_14027c360(a); return out; }
// @0x140274cb0
i64 FUN_140274cb0(i64 out, Unk_StlTag, i64 a)
{
    std::_Exact_args_t tag = {};
    reinterpret_cast<std::tuple<>*>(out)->std::tuple<>::tuple(tag);   // 0x14015e600: tuple<>::tuple<_Exact_args_t, 0>
    ((Unk_WcPtrPair*)&((Unk_WcSelf*)out)->m_0)->FUN_140274c50(FUN_14027c1f0(a));
    return out;
}
// @0x140274d10
i64* FUN_140274d10(i64* out, i64 a, i64 b)
{
    ((Unk_PairI64B*)out)->first = *(Unk_WcIt*)FUN_14027c220(a);
    ((Unk_PairI64B*)out)->second = *FUN_140162f70(b);
    return out;
}
// @0x140274d60
i64* FUN_140274d60(i64* out, i64 a, i64, Unk_StlTag, Unk_StlTag)
{
    ((Unk_PairU32*)out)->first = *(unsigned*)FUN_14027c270((i64*)FUN_14027c410(a));
    ((Unk_PairU32*)out)->second = 0;
    return out;
}
// pointer + function pointer pair (the second half is the deleter/compare callback).
struct Unk_WcPtrFn { void* ptr; void* fn; };
// @0x140274db0
void** FUN_140274db0(void** out, void* value)
{
    ((Unk_WcPtrFn*)out)->ptr = value;
    ((Unk_WcPtrFn*)out)->fn = (void*)&FUN_14027c110;
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
    ((Unk_PairU32*)out)->first = ((Unk_PairU32*)src)->first;
    ((Unk_PairU32*)out)->second = ((Unk_PairU32*)src)->second;
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
        reinterpret_cast<ATL::CAtlArray<unsigned>*>(ids)->Add(FUN_140274f40(token));
        token = text.Tokenize(delims, pos);
    }
}
// @0x140275080
void FUN_140275080(CString& text, void* out, const char* delims)
{
    int pos = 0;
    CString token = text.Tokenize(delims, pos);
    while (!token.IsEmpty()) {
        reinterpret_cast<VStr*>(out)->push_back(Unk_CopyString(token));
        token = text.Tokenize(delims, pos);
    }
}
// @0x140275180
void FUN_140275180(CStringW& text, void* out, const wchar_t* delims)
{
    int pos = 0;
    CStringW token = text.Tokenize(delims, pos);
    while (!token.IsEmpty()) {
        reinterpret_cast<VStr*>(out)->push_back(FUN_140274f70(token));
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
    int result = XmlQuery((class TiXmlElement*)(node), name, value);
    if (result != 0)
        return result;
    *out = value;
    return result;
}
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
// MS2-PIN: ??$_Get_unwrapped@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@@std@@$0A@@std@@YAPEAV?$MS2Ptr@VCIngredientInfo@@@@AEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@@0@@Z 0x140278760 ; unique
// 0x140276880 is TPtrValue<CUserLimitGroup::HistoryList>::Allocate, instantiated at the end of this file.
// @0x1402768f0
void FUN_1402768f0(i64, i64, Unk_StlTag) {}
// @0x140276900
void FUN_140276900(i64, i64, Unk_StlTag) {}
// @0x140276910
__if_exists (std::_Adl_verify_range1) { template void std::_Adl_verify_range1<VIng::iterator, VIng::iterator>(const VIng::iterator&, const VIng::iterator&, std::false_type); }
// @0x140276920
void FUN_140276920(i64 a, i64 b) { Unk_StlTag tag = {}; FUN_1402768f0(a, b, tag); }
// @0x140276960
void FUN_140276960(i64 a, i64 b) { Unk_StlTag tag = {}; FUN_140276900(a, b, tag); }
// @0x1402769a0
template void std::_Adl_verify_range<VIng::iterator, VIng::iterator>(const VIng::iterator&, const VIng::iterator&);
// @0x1402769e0
void FUN_1402769e0(i64* p, i64 n, Unk_StlTag) { *p += n * 8; }
// @0x140276a10
void FUN_140276a10(i64* p, i64 n, Unk_StlTag) { *p += n * 0x10; }
// @0x140276a40
template void std::_Advance1<LHist::iterator, __int64>(LHist::iterator&, __int64, std::bidirectional_iterator_tag);
//
//
//
//
//
//
// vector::_Assign_range(first, last, forward_iterator_tag) for 8- and 16-byte elements.
// @0x140276aa0
void FUN_140276aa0(i64 vec, i64 first, i64 last, Unk_StlTag)
{
    u64 newsize = std::_Convert_size<unsigned __int64>(FUN_14027bc40(first, last));
    reinterpret_cast<VXml*>(vec)->_Orphan_all();
    u64 oldsize = reinterpret_cast<VI64*>(vec)->size();
    u64 oldcapacity = reinterpret_cast<VI64*>(vec)->capacity();
    if (newsize > oldcapacity) {
        if (newsize > reinterpret_cast<VI64*>(vec)->max_size())
            FUN_140289ea0();
        u64 newcapacity = FUN_140286ec0(vec, newsize);
        if ((i64)reinterpret_cast<VRemake*>(vec)->_Myfirst() != 0) {
            FUN_1402875b0(vec, *(i64*)&reinterpret_cast<VRemake*>(vec)->_Myfirst(), *(i64*)&reinterpret_cast<VI64*>(vec)->_Mylast());
            reinterpret_cast<std::allocator<__int64>*>(&reinterpret_cast<VRemake*>(vec)->_Getal())->deallocate((__int64*)reinterpret_cast<VRemake*>(vec)->_Myfirst(), oldcapacity);
        }
        FUN_140286a60(vec, newcapacity);
        *(i64*)&reinterpret_cast<VI64*>(vec)->_Mylast() = FUN_14027a8c0(vec, first, last, *(i64*)&reinterpret_cast<VRemake*>(vec)->_Myfirst());
    } else if (newsize > oldsize) {
        i64 mid = FUN_14027c420(first, oldsize);
        FUN_140277230(first, mid, *(i64*)&reinterpret_cast<VRemake*>(vec)->_Myfirst());
        *(i64*)&reinterpret_cast<VI64*>(vec)->_Mylast() = FUN_14027a8c0(vec, mid, last, *(i64*)&reinterpret_cast<VI64*>(vec)->_Mylast());
    } else {
        i64 newlast = (i64)reinterpret_cast<VRemake*>(vec)->_Myfirst() + newsize * 8;
        FUN_140277230(first, last, *(i64*)&reinterpret_cast<VRemake*>(vec)->_Myfirst());
        FUN_1402875b0(vec, newlast, *(i64*)&reinterpret_cast<VI64*>(vec)->_Mylast());
        *(i64*)&reinterpret_cast<VI64*>(vec)->_Mylast() = newlast;
    }
}
// @0x140276d40
void FUN_140276d40(i64 vec, i64 first, i64 last, Unk_StlTag)
{
    u64 newsize = std::_Convert_size<unsigned __int64>(FUN_14027bca0(first, last));
    reinterpret_cast<VI64*>(vec)->_Orphan_all();
    u64 oldsize = reinterpret_cast<VLog*>(vec)->size();
    u64 oldcapacity = reinterpret_cast<VLog*>(vec)->capacity();
    if (newsize > oldcapacity) {
        if (newsize > reinterpret_cast<VLog*>(vec)->max_size())
            FUN_140289f20();
        u64 newcapacity = FUN_140287100(vec, newsize);
        if ((i64)reinterpret_cast<VLog*>(vec)->_Myfirst() != 0) {
            FUN_1402876b0(vec, *(i64*)&reinterpret_cast<VLog*>(vec)->_Myfirst(), *(i64*)&reinterpret_cast<VLog*>(vec)->_Mylast());
            reinterpret_cast<VLog*>(vec)->_Getal().deallocate((PLog*)reinterpret_cast<VLog*>(vec)->_Myfirst(), oldcapacity);
        }
        FUN_140286b50(vec, newcapacity);
        *(i64*)&reinterpret_cast<VLog*>(vec)->_Mylast() = FUN_14027a940(vec, first, last, *(i64*)&reinterpret_cast<VLog*>(vec)->_Myfirst());
    } else if (newsize > oldsize) {
        i64 mid = FUN_14027c450(first, oldsize);
        FUN_140277280(first, mid, *(i64*)&reinterpret_cast<VLog*>(vec)->_Myfirst());
        *(i64*)&reinterpret_cast<VLog*>(vec)->_Mylast() = FUN_14027a940(vec, mid, last, *(i64*)&reinterpret_cast<VLog*>(vec)->_Mylast());
    } else {
        i64 newlast = (i64)reinterpret_cast<VLog*>(vec)->_Myfirst() + newsize * 0x10;
        FUN_140277280(first, last, *(i64*)&reinterpret_cast<VLog*>(vec)->_Myfirst());
        FUN_1402876b0(vec, newlast, *(i64*)&reinterpret_cast<VLog*>(vec)->_Mylast());
        *(i64*)&reinterpret_cast<VLog*>(vec)->_Mylast() = newlast;
    }
}
// @0x140276fe0
i64 FUN_140276fe0(i64, i64 b, i64) { return b; }
// _Buynode with try/catch(...) cleanup as in the exe
// @0x140277000
i64 FUN_140277000(i64 list, i64 a, i64 b, i64 c)
{
    Unk_140277000* node = (Unk_140277000*)reinterpret_cast<MapII*>(list)->_Buynode0();
    node->m_color = 0;
    node->m_isNil = 0;
    try {
        FUN_14027b790((i64)&reinterpret_cast<MapII*>(list)->_Getal(), (i64)std::addressof(*reinterpret_cast<std::pair<const int, int>*>(&node->m_value)), (i64)&std::forward<const std::piecewise_construct_t&>(*reinterpret_cast<const std::piecewise_construct_t*>(a)), (i64)&reinterpret_cast<std::tuple<const int&>&>(std::forward<std::tuple<const int&>>(*reinterpret_cast<std::tuple<const int&>*>(b))), (i64)&reinterpret_cast<std::tuple<>&>(std::forward<std::tuple<>>(*reinterpret_cast<std::tuple<>*>(c))));
    } catch (...) {
        reinterpret_cast<MapPUI*>(list)->_Freeheadnode((NodePUI*)node);
        throw;
    }
    return (i64)node;
}
// std::_List_node: next, prev, value.
struct Unk_ListNode { i64 m_next; i64 m_prev; i64 m_value; };
// _Buynode with try/catch(...) cleanup as in the exe
// @0x1402770d0
i64 FUN_1402770d0(i64 list, i64 a, i64 b, i64 c)
{
    Unk_ListNode* node = (Unk_ListNode*)reinterpret_cast<LHist*>(list)->_Buynode0((NodeHist*)a, (NodeHist*)b);
    i64 al = (i64)&reinterpret_cast<LHist*>(list)->_Getal();
    try {
        FUN_14027bac0(al, (i64)std::addressof(*reinterpret_cast<MS2Ptr<CUserChangeableItemHistory>*>(&node->m_value)), (i64)&reinterpret_cast<const MS2Ptr<CUserChangeableItemHistory>&>(std::forward<const MS2Ptr<CUserChangeableItemHistory>&>(*reinterpret_cast<const MS2Ptr<CUserChangeableItemHistory>*>(c))));
    } catch (...) {
        reinterpret_cast<std::allocator<NodeHist>*>(al)->deallocate((NodeHist*)node, 1);
        throw;
    }
    return (i64)node;
}
// @0x140277160
i64 FUN_140277160(i64 p) { return p; }
// @0x140277170
i64 FUN_140277170(i64 first, i64 last, i64 dest, Unk_StlTag)
{
    for (; first != last; dest += 8, first += 8)
        FUN_140274e70((unsigned*)dest, (unsigned*)first);
    return dest;
}
// @0x1402771d0
i64 FUN_1402771d0(i64 first, i64 last, i64 dest, Unk_StlTag)
{
    for (; first != last; dest += 0x10, first += 0x10)
        reinterpret_cast<PLog*>(dest)->operator=(*reinterpret_cast<PLog*>(first));
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
        FUN_14027bb90(al, (Unk_VDtor*)FUN_14027a990(first));
    }
}
// @0x140277350
void FUN_140277350(i64 first, i64 last, i64 al, Unk_StlTag)
{
    for (; first != last; first += 8) {
        FUN_14027bbc0(al, FUN_14027a9a0(first));
    }
}
// @0x1402773b0
void FUN_1402773b0(i64 first, i64 last, i64 al, Unk_StlTag)
{
    for (; first != last; first += 0x10) {
        FUN_14027bbe0(al, FUN_14027a9b0(first));
    }
}
// @0x140277410
void FUN_140277410(i64 first, i64 last, i64 al, Unk_StlTag)
{
    for (; first != last; first += 0x10) {
        FUN_14027bc20(al, FUN_14027a9c0(first));
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
template std::_Iter_diff_t<PIng*> std::_Distance1<PIng*>(PIng*, PIng*, std::random_access_iterator_tag);
// @0x140277660
i64 FUN_140277660(i64 a, i64 b, Unk_StlTag) { return (b - a) >> 4; }
// _Construct_at_end style element constructors: *(self+8) = write cursor, *(self+0x10) = allocator
// @0x140277690
void FUN_140277690(i64 self, i64 v)
{
    FUN_14027b840(((Unk_140277690*)self)->m_alloc, FUN_14027a980(((Unk_140277690*)self)->m_cursor), FUN_14027c170(v));
    ((Unk_140277690*)self)->m_cursor = ((Unk_140277690*)self)->m_cursor + 8;
}
// @0x1402776f0
void FUN_1402776f0(i64 self, i64 v)
{
    FUN_14027b890(((Unk_140277690*)self)->m_alloc, FUN_14027a990(((Unk_140277690*)self)->m_cursor), FUN_14027c180(v));
    ((Unk_140277690*)self)->m_cursor = ((Unk_140277690*)self)->m_cursor + 0x30;
}
// @0x140277750
void FUN_140277750(i64 self, i64 v)
{
    FUN_14027b930(((Unk_140277690*)self)->m_alloc, FUN_14027a9a0(((Unk_140277690*)self)->m_cursor), (i64)&std::forward<CString&>(*reinterpret_cast<CString*>(v)));
    ((Unk_140277690*)self)->m_cursor = ((Unk_140277690*)self)->m_cursor + 8;
}
// @0x1402777b0
void FUN_1402777b0(i64 self, i64 v)
{
    FUN_14027b9d0(((Unk_140277690*)self)->m_alloc, FUN_14027a9b0(((Unk_140277690*)self)->m_cursor), FUN_14027c190(v));
    ((Unk_140277690*)self)->m_cursor = ((Unk_140277690*)self)->m_cursor + 0x10;
}
// @0x140277810
void FUN_140277810(i64 self, i64 v)
{
    FUN_14027bb10(((Unk_140277690*)self)->m_alloc, FUN_14027a9c0(((Unk_140277690*)self)->m_cursor), FUN_14027c1a0(v));
    ((Unk_140277690*)self)->m_cursor = ((Unk_140277690*)self)->m_cursor + 0x10;
}
// @0x140277870
void FUN_140277870(i64 self, i64 v)
{
    FUN_14027b8e0(((Unk_140277690*)self)->m_alloc, FUN_14027a990(((Unk_140277690*)self)->m_cursor), FUN_14027c200(v));
    ((Unk_140277690*)self)->m_cursor = ((Unk_140277690*)self)->m_cursor + 0x30;
}
// @0x1402778d0
void FUN_1402778d0(i64 self, i64 v)
{
    FUN_14027b980(((Unk_140277690*)self)->m_alloc, FUN_14027a9a0(((Unk_140277690*)self)->m_cursor), (i64)&reinterpret_cast<CString&>(std::forward<CString>(*reinterpret_cast<CString*>(v))));
    ((Unk_140277690*)self)->m_cursor = ((Unk_140277690*)self)->m_cursor + 8;
}
// @0x140277930
void FUN_140277930(i64 self, i64 v)
{
    FUN_14027ba70(((Unk_140277690*)self)->m_alloc, FUN_14027a9b0(((Unk_140277690*)self)->m_cursor), FUN_14027c210(v));
    ((Unk_140277690*)self)->m_cursor = ((Unk_140277690*)self)->m_cursor + 0x10;
}
// emplace_back with the capacity checks done: construct at _Mylast and bump it
// @0x140277990
void FUN_140277990(i64 vec, i64 v)
{
    FUN_14027ba20((i64)&reinterpret_cast<VIng*>(vec)->_Getal(), FUN_14027a9b0(*(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast()), FUN_14027c1d0(v));
    FUN_140288d20(vec, *(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast(), *(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast());
    i64 result = *(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast();
    *(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast() += 0x10;
}
// @0x140277a50
void FUN_140277a50(i64 vec, i64 v)
{
    FUN_14027b8e0((i64)&reinterpret_cast<VItem*>(vec)->_Getal(), FUN_14027a990(*(i64*)&reinterpret_cast<VItem*>(vec)->_Mylast()), FUN_14027c200(v));
    FUN_140288d00(vec, *(i64*)&reinterpret_cast<VItem*>(vec)->_Mylast(), *(i64*)&reinterpret_cast<VItem*>(vec)->_Mylast());
    i64 result = *(i64*)&reinterpret_cast<VItem*>(vec)->_Mylast();
    *(i64*)&reinterpret_cast<VItem*>(vec)->_Mylast() += 0x30;
}
// @0x140277b10
void FUN_140277b10(i64 vec, i64 v)
{
    FUN_14027b980((i64)&reinterpret_cast<VStr*>(vec)->_Getal(), FUN_14027a9a0(*(i64*)&reinterpret_cast<VStr*>(vec)->_Mylast()), (i64)&reinterpret_cast<CString&>(std::forward<CString>(*reinterpret_cast<CString*>(v))));
    FUN_140288d10(vec, *(i64*)&reinterpret_cast<VStr*>(vec)->_Mylast(), *(i64*)&reinterpret_cast<VStr*>(vec)->_Mylast());
    i64 result = *(i64*)&reinterpret_cast<VStr*>(vec)->_Mylast();
    *(i64*)&reinterpret_cast<VStr*>(vec)->_Mylast() += 8;
}
// @0x140277bd0
void FUN_140277bd0(i64 vec, i64 v)
{
    FUN_14027ba70((i64)&reinterpret_cast<VIng*>(vec)->_Getal(), FUN_14027a9b0(*(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast()), FUN_14027c210(v));
    FUN_140288d20(vec, *(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast(), *(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast());
    i64 result = *(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast();
    *(i64*)&reinterpret_cast<VIng*>(vec)->_Mylast() += 0x10;
}
// _Emplace_reallocate: grow, construct the new element at the insertion point, move the two halves, swap buffers
// vector::_Emplace_reallocate (VS2017 15.8 shape, try/catch(...) cleanup as in the exe)
// @0x140277c90
template PIng* VIng::_Emplace_reallocate<const PIng&>(PIng*, const PIng&);






























// vector::_Emplace_reallocate (VS2017 15.8 shape, try/catch(...) cleanup as in the exe)
// @0x140277ee0
i64 FUN_140277ee0(i64 vec, i64 where, i64 v)
{
    i64 off = (where - *(i64*)&reinterpret_cast<VItem*>(vec)->_Myfirst()) / 0x30;
    i64 al = (i64)&reinterpret_cast<VItem*>(vec)->_Getal();
    i64 oldsize = reinterpret_cast<VItem*>(vec)->size();
    if (oldsize == reinterpret_cast<VItem*>(vec)->max_size())
        FUN_140289ec0();
    i64 newsize = oldsize + 1;
    u64 newcap = FUN_140286f50(vec, newsize);
    i64 newvec = (i64)reinterpret_cast<std::allocator<ItemEntity>*>(al)->allocate(newcap);
    i64 constructed_last = newvec + off * 0x30 + 0x30;
    i64 constructed_first = constructed_last;
    try {

        FUN_14027b8e0(al, FUN_14027a990(newvec + off * 0x30), (i64)&reinterpret_cast<ItemEntity&>(std::forward<ItemEntity>(*reinterpret_cast<ItemEntity*>(v))));
        constructed_first = newvec + off * 0x30;
        if (where == *(i64*)&reinterpret_cast<VItem*>(vec)->_Mylast()) {
            FUN_140289c00(vec, *(i64*)&reinterpret_cast<VItem*>(vec)->_Myfirst(), *(i64*)&reinterpret_cast<VItem*>(vec)->_Mylast(), newvec);
        } else {
            FUN_140289a80(vec, *(i64*)&reinterpret_cast<VItem*>(vec)->_Myfirst(), where, newvec);
            constructed_first = newvec;
            FUN_140289a80(vec, where, *(i64*)&reinterpret_cast<VItem*>(vec)->_Mylast(), newvec + off * 0x30 + 0x30);
        }
    } catch (...) {
        FUN_1402875f0(vec, constructed_first, constructed_last);
        reinterpret_cast<std::allocator<ItemEntity>*>(al)->deallocate((ItemEntity*)newvec, newcap);
        throw;
    }
    FUN_140287190(vec, newvec, newsize, newcap);
    return off * 0x30 + *(i64*)&reinterpret_cast<VItem*>(vec)->_Myfirst();
}
// vector::_Emplace_reallocate (VS2017 15.8 shape, try/catch(...) cleanup as in the exe)
// @0x140278130
i64 FUN_140278130(i64 vec, i64 where, i64 v)
{
    i64 off = (where - *(i64*)&reinterpret_cast<VStr*>(vec)->_Myfirst()) >> 3;
    i64 al = (i64)&reinterpret_cast<VStr*>(vec)->_Getal();
    i64 oldsize = reinterpret_cast<VStr*>(vec)->size();
    if (oldsize == reinterpret_cast<VStr*>(vec)->max_size())
        FUN_140289ee0();
    i64 newsize = oldsize + 1;
    u64 newcap = FUN_140286fe0(vec, newsize);
    i64 newvec = (i64)reinterpret_cast<std::allocator<CString>*>(al)->allocate(newcap);
    i64 constructed_last = newvec + off * 8 + 8;
    i64 constructed_first = constructed_last;
    try {

        FUN_14027b980(al, FUN_14027a9a0(newvec + off * 8), (i64)&reinterpret_cast<CString&>(std::forward<CString>(*reinterpret_cast<CString*>(v))));
        constructed_first = newvec + off * 8;
        if (where == *(i64*)&reinterpret_cast<VStr*>(vec)->_Mylast()) {
            FUN_140289c60(vec, *(i64*)&reinterpret_cast<VStr*>(vec)->_Myfirst(), *(i64*)&reinterpret_cast<VStr*>(vec)->_Mylast(), newvec);
        } else {
            FUN_140289ac0(vec, *(i64*)&reinterpret_cast<VStr*>(vec)->_Myfirst(), where, newvec);
            constructed_first = newvec;
            FUN_140289ac0(vec, where, *(i64*)&reinterpret_cast<VStr*>(vec)->_Mylast(), newvec + off * 8 + 8);
        }
    } catch (...) {
        FUN_140287630(vec, constructed_first, constructed_last);
        reinterpret_cast<std::allocator<CString>*>(al)->deallocate((CString*)newvec, newcap);
        throw;
    }
    FUN_1402872a0(vec, newvec, newsize, newcap);
    return (i64)reinterpret_cast<VStr*>(vec)->_Myfirst() + off * 8;
}
// vector::_Emplace_reallocate (VS2017 15.8 shape, try/catch(...) cleanup as in the exe)
// @0x140278370
template PIng* VIng::_Emplace_reallocate<PIng>(PIng*, PIng&&);






























// node free: destroy the two (three) pointer members, then deallocate the node
// @0x1402785c0
void FUN_1402785c0(i64, i64 node) noexcept
{
    i64 al;
    FUN_14027bb60(&al, FUN_14027b520((i64)&((Unk_WcSelf*)node)->m_0));
    FUN_14027bb60(&al, FUN_14027b520(node + 8));
    std::_Default_allocator_traits<std::allocator<NodeHist>>::deallocate(*reinterpret_cast<std::allocator<NodeHist>*>(&al), (NodeHist*)node, 1);
}
// @0x140278630
void FUN_140278630(i64, i64 node) noexcept
{
    i64 al;
    FUN_14027bb70(&al, FUN_14027b530((i64)&((Unk_WcSelf*)node)->m_0));
    FUN_14027bb70(&al, FUN_14027b530(node + 8));
    FUN_14027bb70(&al, FUN_14027b530(node + 0x10));
    std::_Default_allocator_traits<std::allocator<NodeII>>::deallocate(*reinterpret_cast<std::allocator<NodeII>*>(&al), (NodeII*)node, 1);
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
template auto std::_Get_unwrapped<VIng::iterator, 0>(const VIng::iterator&);
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
    i64 head = list;
    i64* where = *(i64**)(head + 8);
    i64 node = FUN_1402770d0(al, head, (i64)where, FUN_14027c1e0(v));
    reinterpret_cast<LHist*>(al)->_Incsize(1);
    *(i64*)(head + 8) = node;
    *where = node;
}
#include "ms2/placeholder/tptrvalue.h"
class CUserLimitHistory;
template TPtredDummy<ATL::CAtlList<MS2Ptr<CUserLimitHistory> > >* TPtrValue<ATL::CAtlList<MS2Ptr<CUserLimitHistory> > >::Allocate(void*);
// The exe's RTTI names this class TPtredDummy<CAtlList<TPtr<CUserLimitHistory>>>, so the vftable is pinned.
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@6B@ 0x142d15c08
// MS2-PIN: ?Allocate@?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@PEAX@Z 0x140276880
