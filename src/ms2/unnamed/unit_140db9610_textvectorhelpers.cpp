// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: small text <-> vector helpers ("x, y" Point2,
// "x, y, z" Point3, "a,b,c,d" int4 / float4 parsers, float vector formatters) with the CRT _snscanf instantiation and the
// per-TU memmove_s copy.
// MS2-UNIT: unit_140db9610
// MS2-RANGE: 0x140db9610-0x140db9e30 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140db9610.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point2.h>
#include <efd/Point3.h>
#include <NiPoint3.h>
#include <NiColor.h>
#include <NiPoint2.h>   // C3: NiPoint2() 0x140c90180, NiPoint2(const efd::Point2&) 0x140db9c80
#include <NiRect.h>     // C3: NiRect<float>(float, float, float, float) 0x14097eac0
#include <atlcoll.h>
#include <stdarg.h>
#include <stdio.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local vector types (names invented) ----
struct Unk_DbEfdPt2 { float x, y; };                                            // efd::Point2
//
//
//
struct Unk_DbVec3 { float x, y, z; };
struct Unk_DbEfdPt3 { Unk_DbEfdPt3() {} float x, y, z; };                       // efd::Point3
struct Unk_DbInt4
{
    int a, b, c, d;
    Unk_DbInt4() {}
    Unk_DbInt4(int a_, int b_, int c_, int d_);                                 // 0x140db9c30
};
//
//
//
//
//

// ---- exe callees ----
int FUN_14028c3e0(const CStringA& kText, CAtlArray<CStringA>& arrOut, const char* pszDelim, int nMax);
int FUN_140718170(const CStringA& kText);                                       // parses an int
float FUN_140718450(const CStringA& kText);                                     // parses a float
CStringA FUN_14028ef00(efd::Point3 kVec);                                            // Point3 formatter
CStringW FUN_14028efb0(efd::Point3 kPoint);                                               // Point3 formatter (wide)
#define DAT_143b02320 (*(const Unk_DbEfdPt2*)&efd::Point2::ZERO)    // C3: was extern Unk_DbEfdPt2 DAT_143b02320
extern const char DAT_142e36e3c[];                                              // token delimiter (",")
extern const char DAT_142e36e40[];                                              // token delimiter (",")

int FUN_140db9ca0(const char* pszBuf, size_t nCount, const char* pszFormat, ...);

// @0x140db9610
NiPoint2 FUN_140db9610(const CStringA& kText)
{
    NiPoint2 kPt;
    int nParsed = FUN_140db9ca0((const char*)kText, 0x80, "%f, %f", &kPt.x, &kPt.y);
    if (nParsed != 2)
        return NiPoint2(efd::Point2::ZERO);
    return kPt;
}

// @0x140db96a0
NiPoint3 FUN_140db96a0(const CStringA& kText)
{
    NiPoint3 kVec;
    int nParsed = FUN_140db9ca0((const char*)kText, 0x80, "%f, %f, %f", &kVec.x, &kVec.y, &kVec.z);
    if (nParsed != 3)
        return NiPoint3(efd::Point3::ZERO);
    return kVec;
}

// @0x140db9760
Unk_DbInt4 FUN_140db9760(const CStringA& kText)
{
    Unk_DbInt4 kRes(0, 0, 0, 0);
    CAtlArray<CStringA> arrParts;
    if (FUN_14028c3e0(kText, arrParts, DAT_142e36e3c, 4) == 0)
        return Unk_DbInt4(0, 0, 0, 0);
    kRes.a = FUN_140718170(arrParts[0]);
    kRes.b = FUN_140718170(arrParts[1]);
    kRes.c = FUN_140718170(arrParts[2]);
    kRes.d = FUN_140718170(arrParts[3]);
    return kRes;
}

// @0x140db98a0
NiRect<float> FUN_140db98a0(const CStringA& kText)
{
    NiRect<float> kRes(0, 0, 0, 0);
    CAtlArray<CStringA> arrParts;
    if (FUN_14028c3e0(kText, arrParts, DAT_142e36e40, 4) == 0)
        return NiRect<float>(0, 0, 0, 0);
    kRes.m_left = FUN_140718450(arrParts[0]);
    kRes.m_right = FUN_140718450(arrParts[1]);
    kRes.m_top = FUN_140718450(arrParts[2]);
    kRes.m_bottom = FUN_140718450(arrParts[3]);
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
CStringA FUN_140db9aa0(NiColorA kColor)
{
    CStringA kText;
    kText.Format("%f, %f, %f, %f", (double)kColor.r, (double)kColor.g, (double)kColor.b, (double)kColor.a);
    return kText;
}

// @0x140db9b70
CStringA FUN_140db9b70(Unk_DbVec3 kVec)
{
    return FUN_14028ef00(*(efd::Point3*)&kVec);
}

// @0x140db9bd0
CStringW FUN_140db9bd0(Unk_DbVec3 kVec)
{
    return FUN_14028efb0(*(efd::Point3*)&kVec);
}

// @0x140db9c30
Unk_DbInt4::Unk_DbInt4(int a_, int b_, int c_, int d_)
{
    a = a_;
    b = b_;
    c = c_;
    d = d_;
}

// 0x140db9c80 is the SDK inline NiPoint2(const efd::Point2&), emitted by FUN_140db9610 above
//
//
//
//

// @0x140db9ca0
int FUN_140db9ca0(const char* pszBuf, size_t nCount, const char* pszFormat, ...)
{
    va_list args;
    va_start(args, pszFormat);
    int nRes = __stdio_common_vsscanf(*__local_stdio_scanf_options() | 1, pszBuf, nCount, pszFormat, 0, args);
    va_end(args);
    return nRes;
}

// @0x140db9d10
MS2_EMIT_CRT_MEMMOVE_S();
