// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). String conversion helpers: text <-> number / date / vector parsing and formatting (templates).
// MS2-UNIT: unit_1407186f0
// MS2-RANGE: 0x1407186f0-0x14071a5b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_1407186f0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <atltime.h>
#include "ms2/ms2layout.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/xmlattr.h"
#include <algorithm>
#include "hook/ms2hook.h"

// ---- unrecovered neighbours -------------------------------------------------------------------------------------
__int64 FUN_14028d260(float v);                             // float -> fixed
void Unk_SplitA(CStringA&, ATL::CAtlArray<CStringA>*, const char*);   // C3: the achievedata def at 0x14015f050
void* FUN_140163230(void* arr);                         // CAtlArray<CString>::CAtlArray
void FUN_1401641d0(void* arr);                          // CAtlArray<CString>::~CAtlArray
void* FUN_1406c4730(void* out);                         // Unk_DateTime default
void* FUN_1406c47d0(void* out, int y, int m, int d, int h, int mi, int s);   // CMsTime(y,m,d,h,mi,s) (6 ints; no DST arg, sb2)
void FUN_1402929a0(const CStringW& str, std::vector<int>& rOut, const wchar_t* pszSep);   // wide (commonutil.cpp)
CStringA FUN_14016a600(const wchar_t* s, int nCodePage);
CStringW FUN_14016a730(const char* s, int nCodePage);
// (FUN_1402c12b0 was the private CAtlArray<DWORD>::GrowBuffer; the real Add below calls it)
void FUN_140159b70(long hr);
void* FUN_140159860(unsigned __int64 n, void* p);

// ---- in this unit (declarations for forward use) -------------------------------------------------------------------
void* FUN_14071a2c0(void* p);
void* FUN_14071a2e0(void* p);
// (0x14071a340 is the real CAtlArray<DWORD>::Add, pinned at the end)
int FUN_140719c00(const CString* s);
void FUN_140719c30(const CString* s, void* arr, const char* sep);
void FUN_140719c60(const CString* s, void* arr, const char* sep);
CMsTime FUN_140718920(const CString& s);
ATL::CTimeSpan FUN_140718cd0(const CString& s);

// @0x1407186f0
MS2Colors ParseColors(const CString& s) {
    MS2Colors colors;
    FUN_140719c30(&s, &colors, ",");
    return colors;
}

// @0x140718770
Unk_ConstColor ParseHexColor(const CStringA& s) {
    Unk_ConstColor tmp(strtoul((const char*)s, 0, 16));
    //
    //
    return tmp;
}
// @0x1407187d0
void* FUN_1407187d0(void* ret, const CStringW& s) {
    unsigned tmp;
    reinterpret_cast<Unk_ConstColor*>(&tmp)->Unk_ConstColor::Unk_ConstColor(wcstoul((const wchar_t*)s, 0, 16));
    *(unsigned*)ret = tmp;
    return ret;
}
// @0x140718830
void* ParseTick(void* ret, const CStringA& s) {
    unsigned tmp;
    reinterpret_cast<MS2Tick*>(&tmp)->MS2Tick::MS2Tick((unsigned)FUN_14028d260((float)atof((const char*)s)));
    *(unsigned*)ret = tmp;
    return ret;
}
// @0x140718890
void* FUN_140718890(void* ret, const CStringW& s) {
    unsigned tmp;
    reinterpret_cast<MS2Tick*>(&tmp)->MS2Tick::MS2Tick((unsigned)FUN_14028d260((float)_wtof((const wchar_t*)s)));
    *(unsigned*)ret = tmp;
    return ret;
}
// @0x1407188f0
void* FUN_1407188f0(void* ret, const CString* s) { FUN_14071a2c0(ret); return ret; }
// @0x140718920
CMsTime FUN_140718920(const CString& s) { return CMsTime(); }

// Parses "Y-M-D-h-m-s"; falls back to the default (zero) value if any field is out of range.
// @0x140718950
CMsTime FUN_140718950(const CString& s) {
    CAtlArray<CString> parts;
    Unk_SplitA(*const_cast<CStringA*>(&s), (ATL::CAtlArray<CStringA>*)(&parts), "-");
    int six = 6;
    int vals[6] = {0};
    int cnt = (int)((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)(void*)(&parts))->GetCount();
    int n = (std::min<int>)(six, cnt);
    for (int i = 0; i < n; ++i)
        vals[i] = atoi(parts[i]);
    if (vals[0] < 1900)
        return FUN_140718920(s);
    if (vals[1] < 1 || vals[1] > 12)
        return FUN_140718920(s);
    if (vals[2] < 1 || vals[2] > 31)
        return FUN_140718920(s);
    if (vals[3] < 0 || vals[3] > 23)
        return FUN_140718920(s);
    if (vals[4] < 0 || vals[4] > 59)
        return FUN_140718920(s);
    if (vals[5] < 0 || vals[5] > 59)
        return FUN_140718920(s);
    return CMsTime(vals[0], vals[1], vals[2], vals[3], vals[4], vals[5]);
}
// @0x140718cd0
ATL::CTimeSpan FUN_140718cd0(const CString& s) { return ATL::CTimeSpan(); }

// Parses "D-h-m-s" into a CTimeSpan.
// @0x140718d00
ATL::CTimeSpan ParseTimeSpan(const CString& s) {
    CAtlArray<CString> parts;
    Unk_SplitA(*const_cast<CStringA*>(&s), (ATL::CAtlArray<CStringA>*)(&parts), "-");
    int six = 6;
    int vals[6] = {};
    int cnt = (int)((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)(void*)(&parts))->GetCount();
    int n = (std::min<int>)(six, cnt);
    for (int i = 0; i < n; ++i)
        vals[i] = atoi(parts[i]);
    if (vals[2] < 0 || vals[2] > 31)
        return FUN_140718cd0(s);
    if (vals[3] < 0 || vals[3] > 23)
        return FUN_140718cd0(s);
    if (vals[4] < 0 || vals[4] > 59)
        return FUN_140718cd0(s);
    if (vals[5] < 0 || vals[5] > 59)
        return FUN_140718cd0(s);
    return ATL::CTimeSpan(vals[2], vals[3], vals[4], vals[5]);
}

// @0x140718f90
std::vector<int> ParseIntList(const CString& s) {
    std::vector<int> v;
    XmlSplit(s, v, ",");
    return v;
}
// @0x140719010
std::vector<unsigned int> ParseUIntList(const CString& s) {
    std::vector<unsigned int> v;
    XmlSplitImpl<unsigned>(s, v, ",");
    return v;
}
// The exe parses into a std::vector<unsigned int> and returns it through the move ctor the linker folded with
// vector<int>'s (0x14071a240); astooltip declares it as returning std::vector<int>.
// @0x140719090
std::vector<int> FUN_140719090(const CStringW& s) {
    std::vector<unsigned int> v;
    FUN_1402929a0(s, reinterpret_cast<std::vector<int>&>(v), L",");
    return reinterpret_cast<std::vector<int>&&>(v);
}

// ---- number / bool / float -> text (narrow) -------------------------------------------------------------------------
// @0x140719110
CString FUN_140719110(unsigned v) { CString s; s.Format("%u", v); return s; }
// @0x140719190
CString FUN_140719190(int v) { CString s; s.Format("%d", v); return s; }
// @0x140719210
CString FUN_140719210(long v) { CString s; s.Format("%ld", v); return s; }
// @0x140719290
CString FUN_140719290(bool v) { const char* t; if (v) t = "True"; else t = "False"; return CString(t); }
// @0x140719300
CString FUN_140719300(float v) { CString s; s.Format("%f", (double)v); return s; }
// @0x140719390
CString FUN_140719390(double v) { CString s; s.Format("%lf", v); return s; }
// @0x140719410
CString FUN_140719410(const CString& v) { return v; }
// @0x140719460
CStringA FUN_140719460(const CStringW& s) { return FUN_14016a600(s, 0); }
// @0x1407194b0
CString FUN_1407194b0(__int64 v) { CString s; s.Format("%I64d", v); return s; }
// @0x140719530
CString FUN_140719530(unsigned __int64 v) { CString s; s.Format("%I64u", v); return s; }

// ---- number / bool / float -> text (wide) --------------------------------------------------------------------------
// @0x1407195b0
CStringW FUN_1407195b0(unsigned v) { CStringW s; s.Format(L"%u", v); return s; }
// @0x140719630
CStringW FUN_140719630(int v) { CStringW s; s.Format(L"%d", v); return s; }
// @0x1407196b0
CStringW FUN_1407196b0(long v) { CStringW s; s.Format(L"%ld", v); return s; }
// @0x140719730
CStringW FUN_140719730(bool v) { const wchar_t* t; if (v) t = L"True"; else t = L"False"; return CStringW(t); }
// @0x1407197a0
CStringW FUN_1407197a0(float v) { CStringW s; s.Format(L"%f", (double)v); return s; }
// @0x140719830
CStringW FUN_140719830(double v) { CStringW s; s.Format(L"%lf", v); return s; }
// @0x1407198b0
CStringW FUN_1407198b0(const CStringA& s) { return FUN_14016a730(s, 0); }
// @0x140719900
CStringW FUN_140719900(CStringW v) { return v; }
// @0x140719960
CStringW FUN_140719960(const wchar_t* v) { return CStringW(v); }
// @0x1407199b0
CStringW FUN_1407199b0(const wchar_t* v) { return CStringW(v); }
// @0x140719a00
CStringW FUN_140719a00(__int64 v) { CStringW s; s.Format(L"%I64d", v); return s; }
// @0x140719a80
CStringW FUN_140719a80(unsigned __int64 v) { CStringW s; s.Format(L"%I64u", v); return s; }

// ---- fmt-based "{0}" / "{0},{1},{2}" ---------------------------------------------------------------------------------
// @0x140719b00
CStringW FUN_140719b00(unsigned short v) { return StringFormat(L"{0}", v); }
// @0x140719b50
CStringW FUN_140719b50(short v) { return StringFormat(L"{0}", v); }
// @0x140719ba0
CStringW FUN_140719ba0(const float* v) { return StringFormat(L"{0},{1},{2}", *v, *(v + 1), *(v + 2)); }

// ---- text -> vector parsing -------------------------------------------------------------------------------------------
// @0x140719c00
int FUN_140719c00(const CString* s) { return (int)strtol((const char*)*s, 0, 16); }
// @0x140719c30
void FUN_140719c30(const CString* s, void* arr, const char* sep) { FUN_140719c60(s, arr, sep); }
// @0x140719c60
void FUN_140719c60(const CString* s, void* arr, const char* sep) {
    int pos = 0;
    CString tok = const_cast<CString*>(s)->Tokenize(sep, pos);
    while (!tok.IsEmpty()) {
        reinterpret_cast<ATL::CAtlArray<DWORD>*>(arr)->Add(FUN_140719c00(&tok));
        tok = const_cast<CString*>(s)->Tokenize(sep, pos);
    }
}

// @0x14071a1e0 ... small helpers
// std::vector<int>(vector&&) and its helpers, emitted by ParseIntList's return.
// MS2-PIN: ??$move@AEAV?$allocator@H@std@@@std@@YA$$QEAV?$allocator@H@0@AEAV10@@Z 0x14071a200 ; sfb: std::move<allocator<int>&>
// MS2-PIN: ??$move@AEAV?$vector@HV?$allocator@H@std@@@std@@@std@@YA$$QEAV?$vector@HV?$allocator@H@std@@@0@AEAV10@@Z 0x14071a210 ; sfb: std::move<vector<int>&>
// MS2-PIN: ??0?$vector@HV?$allocator@H@std@@@std@@QEAA@$$QEAV01@@Z 0x14071a240 ; sfb: vector<int>(vector&&)
// @0x14071a2c0
void* FUN_14071a2c0(void* p) { *(__int64*)p = 0; return p; }
// @0x14071a2e0
void* FUN_14071a2e0(void* p) { *(__int64*)p = 0; return p; }
// @0x14071a300 MS2Colors(MS2Colors&&) (inline in clientconstants.h)
// CAtlArray<DWORD>::Add (0x14071a340) is the ATL body now; the Unk_IntAtlArray view and the
// FUN_14071a340 stand-in over the FUN_1402c12b0 GrowBuffer wrapper are gone.
//
//
//
//
//
//
//
//
//
//
//
//
//
// MS2-PIN: ?_Move_from@?$vector@HV?$allocator@H@std@@@std@@AEAAX$$QEAV12@U?$integral_constant@_N$00@2@@Z 0x14071a3f0 ; sfb: vector<int>::_Move_from
// MS2-PIN: ?_Swap_all@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAXAEAV12@@Z 0x14071a4d0 ; sfb: _Vector_alloc<int>::_Swap_all
// @0x14071a520
CString GetPrecomputedTerrainPath(const CStringA& name) {
    CString s;
    s.Format("%s/%s.tok", "./Data/Resource/PrecomputedTerrain", (const char*)name);
    return s;
}
// MS2-PIN: ?Add@?$CAtlArray@KV?$CElementTraits@K@ATL@@@ATL@@QEAA_KK@Z 0x14071a340 ; the real CAtlArray<DWORD>::Add (was the FUN_14071a340 stand-in over the FUN_1402c12b0 GrowBuffer wrapper)
