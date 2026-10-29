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
struct Unk_DbEfdPt2 { float x, y; };                                            // efd::Point2
struct Unk_DbPt2 : Unk_DbEfdPt2                                                 // NiPoint2
{
    Unk_DbPt2();                                                                // 0x140c90180
    Unk_DbPt2(const Unk_DbEfdPt2& kRhs);                                        // 0x140db9c80
};
struct Unk_DbVec3 { float x, y, z; };
struct Unk_DbEfdPt3 { Unk_DbEfdPt3() {} float x, y, z; };                       // efd::Point3
struct Unk_DbPt3 : Unk_DbEfdPt3                                                 // NiPoint3
{
    Unk_DbPt3();                                                                // 0x1405522f0
    Unk_DbPt3(const Unk_DbEfdPt3& kRhs);                                        // 0x14027dcf0
};
struct Unk_DbInt4
{
    int a, b, c, d;
    Unk_DbInt4() {}
    Unk_DbInt4(int a_, int b_, int c_, int d_);                                 // 0x140db9c30
};
struct Unk_DbFloat4                                                             // NiRect<float>
{
    float x, y, z, w;
    Unk_DbFloat4(float fX, float fY, float fZ, float fW);                       // 0x14097eac0
};

// ---- exe callees ----
int FUN_14028c3e0(const CStringA& kText, CAtlArray<CStringA>& arrOut, const char* pszDelim, int nMax);
CStringA& FUN_140164930(CAtlArray<CStringA>& arr, size_t i);
int FUN_140718170(const CStringA& kText);                                       // parses an int
float FUN_140718450(const CStringA& kText);                                     // parses a float
CStringA FUN_14028ef00(Unk_DbVec3 kVec);                                             // Point3 formatter
CStringW FUN_14028efb0(Unk_DbVec3 kVec);                                             // Point3 formatter (wide)
extern unsigned long long* FUN_14029dcd0();                                     // CRT scanf options
extern Unk_DbEfdPt2 DAT_143b02320;                                                 // default Point2
extern Unk_DbEfdPt3 DAT_143b01a60;                                                // default Point3
extern const char DAT_142e36e3c[];                                              // token delimiter (",")
extern const char DAT_142e36e40[];                                              // token delimiter (",")

int FUN_140db9ca0(const char* pszBuf, size_t nCount, const char* pszFormat, ...);

// @0x140db9610
Unk_DbPt2 FUN_140db9610(const CStringA& kText)
{
    Unk_DbPt2 kPt;
    int nParsed = FUN_140db9ca0((const char*)kText, 0x80, "%f, %f", &kPt.x, &kPt.y);
    if (nParsed != 2)
        return Unk_DbPt2(DAT_143b02320);
    return kPt;
}

// @0x140db96a0
Unk_DbPt3 FUN_140db96a0(const CStringA& kText)
{
    Unk_DbPt3 kVec;
    int nParsed = FUN_140db9ca0((const char*)kText, 0x80, "%f, %f, %f", &kVec.x, &kVec.y, &kVec.z);
    if (nParsed != 3)
        return Unk_DbPt3(DAT_143b01a60);
    return kVec;
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
    Unk_DbFloat4 kRes(0, 0, 0, 0);
    CAtlArray<CStringA> arrParts;
    if (FUN_14028c3e0(kText, arrParts, DAT_142e36e40, 4) == 0)
        return Unk_DbFloat4(0, 0, 0, 0);
    kRes.x = FUN_140718450(FUN_140164930(arrParts, 0));
    kRes.y = FUN_140718450(FUN_140164930(arrParts, 1));
    kRes.z = FUN_140718450(FUN_140164930(arrParts, 2));
    kRes.w = FUN_140718450(FUN_140164930(arrParts, 3));
    return kRes;
}

// @0x140db99f0
CStringA FUN_140db99f0(const Unk_DbEfdPt3& kVec)
{
    CStringA kText;
    kText.Format("%f, %f, %f", (double)kVec.x, (double)kVec.y, (double)kVec.z);
    return kText;
}

// @0x140db9aa0
CStringA FUN_140db9aa0(const Unk_DbFloat4& kVec)
{
    CStringA kText;
    kText.Format("%f, %f, %f, %f", (double)kVec.x, (double)kVec.y, (double)kVec.z, (double)kVec.w);
    return kText;
}

// @0x140db9b70
CStringA FUN_140db9b70(Unk_DbVec3 kVec)
{
    return FUN_14028ef00(kVec);
}

// @0x140db9bd0
CStringW FUN_140db9bd0(Unk_DbVec3 kVec)
{
    return FUN_14028efb0(kVec);
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
Unk_DbPt2::Unk_DbPt2(const Unk_DbEfdPt2& kRhs)
{
    *static_cast<Unk_DbEfdPt2*>(this) = kRhs;
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
