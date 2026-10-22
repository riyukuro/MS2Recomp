// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIStanceBar.
// MS2-UNIT: unit_140ba2180
// MS2-RANGE: 0x140ba2180-0x140ba2a80 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_140ba2180.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The null test of m_30 is a COMDAT of this unit (specialization declared before its first use, for clang-cl).
template <> inline bool MS2Ptr<AScript>::operator==(AScript* p) const;

int FUN_141277f50();
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);     // Value = n (UInt)
void FUN_1422bcd40(Scaleform::GFx::Value* pValue, unsigned long n);    // Value = n (UInt)

// @0x140ba2180
UIStanceBar::UIStanceBar()
{
    m_80 = 1;
    m_84 = false;
    m_58 = 0;
    m_2c = 0x1f;
    m_28 = FUN_141277f50();
}

// @0x140ba2220
UIStanceBar::~UIStanceBar()
{
    FUN_140ba26b0();
}

// @0x140ba2290
CString UIStanceBar::GetTypeName()
{
    return "StanceBar";
}
MS2_REPLACE_METHOD(0x140BA2290, UIStanceBar, GetTypeName, 61, 0xA79D7FB8);

// @0x140ba22e0
void UIStanceBar::vfunc_3()
{
    FUN_140ba26b0();
    m_84 = false;
    m_80 = 1;
    UIHeadUpDisplay::vfunc_3();
}
MS2_REPLACE_METHOD(0x140BA22E0, UIStanceBar, vfunc_3, 61, 0x97817F08);

// @0x140ba2330
int UIStanceBar::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140BA2330, UIStanceBar, vfunc_28, 67, 0xB3B95419);

// @0x140ba2380
void UIStanceBar::vfunc_15()
{
}
MS2_REPLACE_METHOD(0x140BA2380, UIStanceBar, vfunc_15, 6, 0xA9AF6E37);

// @0x140ba2390
void UIStanceBar::FUN_140ba2390(const Unk_StanceInfo* pInfo)
{
    FUN_140ba2520(pInfo);
}
MS2_REPLACE_METHOD(0x140BA2390, UIStanceBar, FUN_140ba2390, 34, 0xE319DB36);

// @0x140ba23c0
void UIStanceBar::FUN_140ba23c0(const Unk_StanceInfo* pInfo)
{
    FUN_140ba2400();
    FUN_140ba2520(pInfo);
}
MS2_REPLACE_METHOD(0x140BA23C0, UIStanceBar, FUN_140ba23c0, 44, 0x1DFB2EF1);

// @0x140ba2400
void UIStanceBar::FUN_140ba2400()
{
    FUN_140ba25c0();
}
MS2_REPLACE_METHOD(0x140BA2400, UIStanceBar, FUN_140ba2400, 24, 0xF925C20E);

// @0x140ba2420
void UIStanceBar::FUN_140ba2420(unsigned long nTime)
{
    if (m_30 == 0)
        return;
    m_30->Invoke("updateTime", nTime);
}
MS2_REPLACE_METHOD(0x140BA2420, UIStanceBar, FUN_140ba2420, 98, 0x22931AE7);

// @0x140ba2490
void UIStanceBar::FUN_140ba2490(int nStep)
{
    if (m_30 == 0)
        return;
    if (m_80 == nStep)
        return;
    m_80 = nStep;
    m_30->Invoke("updateStep", (unsigned int)nStep);
}
MS2_REPLACE_METHOD(0x140BA2490, UIStanceBar, FUN_140ba2490, 132, 0xB3D22CD9);

// @0x140ba2520
void UIStanceBar::FUN_140ba2520(const Unk_StanceInfo* pInfo)
{
    m_84 = false;
    m_80 = 1;
    if (m_30 == 0)
        return;
    m_30->Invoke("startStance", pInfo->m_b, pInfo->m_a);
}
MS2_REPLACE_METHOD(0x140BA2520, UIStanceBar, FUN_140ba2520, 141, 0x1BDBBEE3);

// @0x140ba25c0
void UIStanceBar::FUN_140ba25c0()
{
    FUN_140ba25f0();
    FUN_140ba2670();
}
MS2_REPLACE_METHOD(0x140BA25C0, UIStanceBar, FUN_140ba25c0, 34, 0x1FFC55D5);

// @0x140ba25f0
void UIStanceBar::FUN_140ba25f0()
{
    if ((m_30.get() ? true : false) && m_84 == false)
        m_30->Invoke("stopStance");
}
MS2_REPLACE_METHOD(0x140BA25F0, UIStanceBar, FUN_140ba25f0, 120, 0x8A05DEAD);

// @0x140ba2670
void UIStanceBar::FUN_140ba2670()
{
    m_84 = true;
    m_80 = 1;
    FUN_140ba26b0();
}
MS2_REPLACE_METHOD(0x140BA2670, UIStanceBar, FUN_140ba2670, 51, 0x416A8653);

// @0x140ba26c0
void UIStanceBar::FUN_140ba26c0()
{
}

// @0x140ba26d0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, unsigned int a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ba2770
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, unsigned long a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcd40(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ba2810
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, unsigned long a1, unsigned long a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcd40(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd40(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ba28d0
template <> inline bool MS2Ptr<AScript>::operator==(AScript* p) const
{
    return m_p == p;
}

MS2_EMIT_CRT_MEMMOVE_S();
