// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: small text <-> vector helpers ("x, y" Point2,
// "x, y, z" Point3, "a,b,c,d" int4 / float4 parsers, float vector formatters) with the CRT _snscanf instantiation and the
// per-TU memmove_s copy.
// MS2-UNIT: unit_140db9610
// MS2-RANGE: 0x140db9610-0x140db9e30 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140db9610.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <stdarg.h>
#include <stdio.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local vector types (names invented) ----
struct Unk_DbPt2
{
    float x, y;
    Unk_DbPt2() {}
    Unk_DbPt2(const Unk_DbPt2& kRhs);                                           // 0x140db9c80
};
struct Unk_DbVec3 { float x, y, z; };
struct Unk_DbInt4
{
    int a, b, c, d;
    Unk_DbInt4() {}
    Unk_DbInt4(int a_, int b_, int c_, int d_);                                 // 0x140db9c30
};
struct Unk_DbFloat4 { float x, y, z, w; };

// ---- exe callees ----
void FUN_140c90180(Unk_DbPt2* pThis);                                           // Point2 default ctor
void FUN_1405522f0(Unk_DbVec3* pThis);                                          // Point3 default ctor
Unk_DbVec3 FUN_14027dcf0(Unk_DbVec3 kVec);                                      // Point3 copy
void FUN_14097eac0(Unk_DbFloat4* pThis, float fX, float fY, float fZ, float fW);    // float4 ctor
int FUN_14028c3e0(const CStringA& kText, CAtlArray<CStringA>& arrOut, const char* pszDelim, int nMax);
CStringA& FUN_140164930(CAtlArray<CStringA>& arr, size_t i);
int FUN_140718170(const CStringA& kText);                                       // parses an int
float FUN_140718450(const CStringA& kText);                                     // parses a float
CStringA FUN_14028ef00(Unk_DbVec3 kVec, void* p3, void* p4, int nZero);         // Point3 formatter
CStringW FUN_14028efb0(Unk_DbVec3 kVec, void* p3, void* p4, int nZero);         // Point3 formatter (wide)
extern unsigned long long* FUN_14029dcd0();                                     // CRT scanf options
extern Unk_DbPt2 DAT_143b02320;                                                 // default Point2
extern Unk_DbVec3 DAT_143b01a60;                                                // default Point3
extern const char DAT_142e36e3c[];                                              // token delimiter (",")
extern const char DAT_142e36e40[];                                              // token delimiter (",")

int FUN_140db9ca0(const char* pszBuf, size_t nCount, const char* pszFormat, ...);

// @0x140db9610
Unk_DbPt2 FUN_140db9610(const CStringA& kText)
{
    Unk_DbPt2 kPt;
    FUN_140c90180(&kPt);
    int nParsed = FUN_140db9ca0((const char*)kText, 0x80, "%f, %f", &kPt.x, &kPt.y);
    if (nParsed == 2)
        return kPt;
    return Unk_DbPt2(DAT_143b02320);
}

// @0x140db96a0
Unk_DbVec3 FUN_140db96a0(const CStringA& kText)
{
    Unk_DbVec3 kVec;
    FUN_1405522f0(&kVec);
    int nParsed = FUN_140db9ca0((const char*)kText, 0x80, "%f, %f, %f", &kVec.x, &kVec.y, &kVec.z);
    if (nParsed == 3)
        return kVec;
    return FUN_14027dcf0(DAT_143b01a60);
}

// @0x140db9760
Unk_DbInt4 FUN_140db9760(const CStringA& kText)
{
    Unk_DbInt4 kRes(0, 0, 0, 0);
    CAtlArray<CStringA> arrParts;
    if (FUN_14028c3e0(kText, arrParts, DAT_142e36e3c, 4) == 0)
        return Unk_DbInt4(0, 0, 0, 0);
    kRes.a = FUN_140718170(FUN_140164930(arrParts, 0));
    kRes.b = FUN_140718170(FUN_140164930(arrParts, 1));
    kRes.c = FUN_140718170(FUN_140164930(arrParts, 2));
    kRes.d = FUN_140718170(FUN_140164930(arrParts, 3));
    return kRes;
}

// @0x140db98a0
Unk_DbFloat4 FUN_140db98a0(const CStringA& kText)
{
    Unk_DbFloat4 kRes;
    FUN_14097eac0(&kRes, 0, 0, 0, 0);
    CAtlArray<CStringA> arrParts;
    if (FUN_14028c3e0(kText, arrParts, DAT_142e36e40, 4) == 0)
    {
        Unk_DbFloat4 kZero;
        FUN_14097eac0(&kZero, 0, 0, 0, 0);
        return kZero;
    }
    kRes.x = FUN_140718450(FUN_140164930(arrParts, 0));
    kRes.y = FUN_140718450(FUN_140164930(arrParts, 1));
    kRes.z = FUN_140718450(FUN_140164930(arrParts, 2));
    kRes.w = FUN_140718450(FUN_140164930(arrParts, 3));
    return kRes;
}

// @0x140db99f0
CStringA FUN_140db99f0(const float* pVec)
{
    CStringA kText;
    kText.Format("%f, %f, %f", (double)pVec[0], (double)pVec[1], (double)pVec[2]);
    return kText;
}

// @0x140db9aa0
CStringA FUN_140db9aa0(const float* pVec)
{
    CStringA kText;
    kText.Format("%f, %f, %f, %f", (double)pVec[0], (double)pVec[1], (double)pVec[2], (double)pVec[3]);
    return kText;
}

// @0x140db9b70
CStringA FUN_140db9b70(Unk_DbVec3 kVec, void* p3, void* p4)
{
    return FUN_14028ef00(kVec, p3, p4, 0);
}

// @0x140db9bd0
CStringW FUN_140db9bd0(Unk_DbVec3 kVec, void* p3, void* p4)
{
    return FUN_14028efb0(kVec, p3, p4, 0);
}

// @0x140db9c30
Unk_DbInt4::Unk_DbInt4(int a_, int b_, int c_, int d_)
{
    a = a_;
    b = b_;
    c = c_;
    d = d_;
}

// @0x140db9c80
Unk_DbPt2::Unk_DbPt2(const Unk_DbPt2& kRhs)
{
    *this = kRhs;
}

// @0x140db9ca0
int FUN_140db9ca0(const char* pszBuf, size_t nCount, const char* pszFormat, ...)
{
    va_list args;
    va_start(args, pszFormat);
    int nRes = __stdio_common_vsscanf(*FUN_14029dcd0() | 1, pszBuf, nCount, pszFormat, 0, args);
    va_end(args);
    return nRes;
}

// @0x140db9d10
MS2_EMIT_CRT_MEMMOVE_S();
