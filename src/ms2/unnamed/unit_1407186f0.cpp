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
#include "hook/ms2hook.h"

// ---- unrecovered neighbours -------------------------------------------------------------------------------------
typedef unsigned char Unk_Bytes;                 // opaque
void* FUN_1402bcfa0(void* out, unsigned long v);        // Unk_Hex32::Unk_Hex32(ulong)
void* FUN_1402bd000(void* out, int v);                  // Unk_Fixed32::Unk_Fixed32(int)
int FUN_14028d260(float v);                             // float -> fixed
void* FUN_1402bcfe0(void* arr);                         // Unk_IntList::Unk_IntList()
void FUN_1402be360(void* arr);                          // Unk_IntList::~Unk_IntList()
void FUN_1402be530(void* dst, void* src);               // Unk_IntList assign
void FUN_14015f050(const CString* s, void* out, const char* sep);   // split into CAtlArray<CString>
void* FUN_140163230(void* arr);                         // CAtlArray<CString>::CAtlArray
void FUN_1401641d0(void* arr);                          // CAtlArray<CString>::~CAtlArray
unsigned __int64 FUN_1401662c0(void* arr);              // GetCount
const int* FUN_1402fbd20(const int* a, const int* b);   // std::min<int>
CString* FUN_140164930(void* arr, __int64 i);           // operator[]
void* FUN_1406c4730(void* out);                         // Unk_DateTime default
void* FUN_1406c47d0(void* out, int y, int m, int d, int h, int mi, int s);   // CMsTime(y,m,d,h,mi,s) (6 ints; no DST arg, sb2)
void* FUN_140182ea0(void* s);   void FUN_140183b60(void* s);   void FUN_140178270(const CString* in, void* tmp, const char* sep);
void* FUN_140182ed0(void* s);   void FUN_140183b90(void* s);   void FUN_1401783d0(const CString* in, void* tmp, const char* sep);
void FUN_1402929a0(const CString* in, void* tmp, const char* sep);
void* FUN_14016a600(void* out, const wchar_t* s, int);
void* FUN_14016a730(void* out, const char* s, int);
void* FUN_14050dba0(void* dst, void* alloc);
void* FUN_14018c480(void* str);
void* FUN_14018cff0(void* v); void* FUN_14018d190(void* v); void* FUN_14018ce70(void* v);
void FUN_1403b9f30(void* dst, void* src);
void* FUN_14018bdd0(void* v);
char FUN_1402c12b0(void* arr, unsigned __int64 n);
void FUN_140159b70(long hr);
void* FUN_140159860(unsigned __int64 n, void* p);

// ---- in this unit (declarations for forward use) -------------------------------------------------------------------
void* FUN_14071a200(void* p);
void* FUN_14071a210(void* p);
void FUN_14071a3f0(void* dst, void* src, char tag);
void FUN_14071a4d0(void* dst, void* src);
void* FUN_14071a2c0(void* p);
void* FUN_14071a2e0(void* p);
void* FUN_14071a300(void* dst, void* src);
unsigned __int64 FUN_14071a340(void* arr, int v);
int FUN_140719c00(const CString* s);
void FUN_140719c30(const CString* s, void* arr, const char* sep);
void FUN_140719c60(const CString* s, void* arr, const char* sep);
void* FUN_140718920(void* out, const CString* s);
void* FUN_140718cd0(void* out, const CString* s);
void* FUN_14071a240(void* dst, void* src);

// @0x1407186f0
void* FUN_1407186f0(void* ret, const CString* s) {
    Unk_Bytes tmp[0x28];
    FUN_1402bcfe0(tmp);
    FUN_140719c30(s, tmp, ",");
    FUN_14071a300(ret, tmp);
    FUN_1402be360(tmp);
    return ret;
}

// @0x140718770
void* FUN_140718770(void* ret, const CStringA& s) {
    unsigned tmp;
    FUN_1402bcfa0(&tmp, strtoul((const char*)s, 0, 16));
    *(unsigned*)ret = tmp;
    return ret;
}
// @0x1407187d0
void* FUN_1407187d0(void* ret, const CStringW& s) {
    unsigned tmp;
    FUN_1402bcfa0(&tmp, wcstoul((const wchar_t*)s, 0, 16));
    *(unsigned*)ret = tmp;
    return ret;
}
// @0x140718830
void* FUN_140718830(void* ret, const CStringA& s) {
    unsigned tmp;
    FUN_1402bd000(&tmp, FUN_14028d260((float)atof((const char*)s)));
    *(unsigned*)ret = tmp;
    return ret;
}
// @0x140718890
void* FUN_140718890(void* ret, const CStringW& s) {
    unsigned tmp;
    FUN_1402bd000(&tmp, FUN_14028d260((float)_wtof((const wchar_t*)s)));
    *(unsigned*)ret = tmp;
    return ret;
}
// @0x1407188f0
void* FUN_1407188f0(void* ret, const CString* s) { FUN_14071a2c0(ret); return ret; }
// @0x140718920
void* FUN_140718920(void* ret, const CString* s) { FUN_1406c4730(ret); return ret; }

// Parses "Y-M-D-h-m-s"; falls back to the default (zero) value if any field is out of range.
// @0x140718950
void* FUN_140718950(void* ret, const CString* s) {
    Unk_Bytes parts[0x20];
    FUN_140163230(parts);
    FUN_14015f050(s, parts, "-");
    int six = 6;
    int vals[6] = {0, 0, 0, 0, 0, 0};
    int cnt = (int)FUN_1401662c0(parts);
    int n = *FUN_1402fbd20(&six, &cnt);
    for (int i = 0; i < n; ++i)
        vals[i] = atoi(*FUN_140164930(parts, i));
    if (vals[0] < 1900 || vals[1] < 1 || vals[1] > 12 || vals[2] < 1 || vals[2] > 31 || vals[3] < 0 || vals[3] > 23 ||
        vals[4] < 0 || vals[4] > 59 || vals[5] < 0 || vals[5] > 59)
        FUN_140718920(ret, s);
    else
        FUN_1406c47d0(ret, vals[0], vals[1], vals[2], vals[3], vals[4], vals[5]);
    FUN_1401641d0(parts);
    return ret;
}
// @0x140718cd0
void* FUN_140718cd0(void* ret, const CString* s) { FUN_14071a2e0(ret); return ret; }

// Parses "D-h-m-s" into a CTimeSpan.
// @0x140718d00
ATL::CTimeSpan* FUN_140718d00(ATL::CTimeSpan* ret, const CString* s) {
    Unk_Bytes parts[0x20];
    FUN_140163230(parts);
    FUN_14015f050(s, parts, "-");
    int six = 6;
    int vals[6] = {0, 0, 0, 0, 0, 0};
    int cnt = (int)FUN_1401662c0(parts);
    int n = *FUN_1402fbd20(&six, &cnt);
    for (int i = 0; i < n; ++i)
        vals[i] = atoi(*FUN_140164930(parts, i));
    if (vals[2] < 0 || vals[2] > 31 || vals[3] < 0 || vals[3] > 23 || vals[4] < 0 || vals[4] > 59 || vals[5] < 0 || vals[5] > 59)
        FUN_140718cd0(ret, s);
    else
        new (ret) ATL::CTimeSpan(vals[2], vals[3], vals[4], vals[5]);
    FUN_1401641d0(parts);
    return ret;
}

// @0x140718f90
void* FUN_140718f90(void* ret, const CString* s) {
    Unk_Bytes tmp[0x28];
    FUN_140182ea0(tmp);
    FUN_140178270(s, tmp, ",");
    FUN_14071a240(ret, tmp);
    FUN_140183b60(tmp);
    return ret;
}
// @0x140719010
void* FUN_140719010(void* ret, const CString* s) {
    Unk_Bytes tmp[0x28];
    FUN_140182ed0(tmp);
    FUN_1401783d0(s, tmp, ",");
    FUN_14071a240(ret, tmp);
    FUN_140183b90(tmp);
    return ret;
}
// @0x140719090
void* FUN_140719090(void* ret, const CString* s) {
    Unk_Bytes tmp[0x28];
    FUN_140182ed0(tmp);
    FUN_1402929a0(s, tmp, ",");
    FUN_14071a240(ret, tmp);
    FUN_140183b90(tmp);
    return ret;
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
void* FUN_140719460(void* ret, const CStringW& s) { FUN_14016a600(ret, (const wchar_t*)s, 0); return ret; }
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
void* FUN_1407198b0(void* ret, const CStringA& s) { FUN_14016a730(ret, (const char*)s, 0); return ret; }
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
CStringW FUN_140719ba0(const float* v) { return StringFormat(L"{0},{1},{2}", v[0], v[1], v[2]); }

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
        FUN_14071a340(arr, FUN_140719c00(&tok));
        tok = const_cast<CString*>(s)->Tokenize(sep, pos);
    }
}

// @0x14071a1e0 ... small helpers
// @0x14071a200
void* FUN_14071a200(void* p) { return p; }
// @0x14071a210
void* FUN_14071a210(void* p) { return p; }
// vector(vector&&): allocator copy, then steal the three pointers
// @0x14071a240
void* FUN_14071a240(void* dst, void* src) {
    void* al = FUN_14071a200(FUN_14018c480(src));
    FUN_14050dba0(dst, al);
    char tag = 0;
    FUN_14071a3f0(dst, FUN_14071a210(src), tag);
    return dst;
}
// @0x14071a2c0
void* FUN_14071a2c0(void* p) { *(__int64*)p = 0; return p; }
// @0x14071a2e0
void* FUN_14071a2e0(void* p) { *(__int64*)p = 0; return p; }
// @0x14071a300
void* FUN_14071a300(void* dst, void* src) {
    new (dst) ATL::CAtlArray<void*>();
    FUN_1402be530(dst, src);
    return dst;
}
struct Unk_IntAtlArray { int* m_pData; unsigned __int64 m_nSize; unsigned __int64 m_nMaxSize; };
// CAtlArray<int>::Add
// @0x14071a340
unsigned __int64 FUN_14071a340(void* arr, int v) {
    unsigned __int64 idx = ((Unk_IntAtlArray*)arr)->m_nSize;
    if (idx >= ((Unk_IntAtlArray*)arr)->m_nMaxSize) {
        unsigned char bSuccess = FUN_1402c12b0(arr, idx + 1);
        if (!bSuccess)
            FUN_140159b70(0x8007000e);
    }
    int* slot = (int*)FUN_140159860(4, ((Unk_IntAtlArray*)arr)->m_pData + idx);
    *slot = v;
    ((Unk_IntAtlArray*)arr)->m_nSize++;
    return idx;
}
// vector move: takes the three pointers of src
// @0x14071a3f0
void FUN_14071a3f0(void* dst, void* src, char tag) {
    FUN_14071a4d0(dst, src);
    *(void**)FUN_14018cff0(dst) = *(void**)FUN_14018cff0(src);
    *(void**)FUN_14018d190(dst) = *(void**)FUN_14018d190(src);
    *(void**)FUN_14018ce70(dst) = *(void**)FUN_14018ce70(src);
    *(void**)FUN_14018cff0(src) = 0;
    *(void**)FUN_14018d190(src) = 0;
    *(void**)FUN_14018ce70(src) = 0;
}
// @0x14071a4d0
void FUN_14071a4d0(void* dst, void* src) {
    FUN_1403b9f30(FUN_14018bdd0(dst), FUN_14018bdd0(src));
}
// @0x14071a520
CString FUN_14071a520(const CStringA& name) {
    CString s;
    s.Format("%s/%s.tok", "./Data/Resource/PrecomputedTerrain", (const char*)name);
    return s;
}
