// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIActionTooltip: see uiactiontooltip.h.
// MS2-UNIT: ?\uiactiontooltip.cpp
// MS2-RANGE: 0x1418b1520-0x1418b25f0 .text$mn
// MS2-PIN: ??_GUIActionTooltip@@UEAAPEAXI@Z 0x1418b2480
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiactiontooltip.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uiactiontooltip.h"

#include "worldservice.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "mypc.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <NiPoint2.h>

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

// This assignment COMDAT belongs to the earlier unit at 0x140ba7780.
template <> template <>
MS2Ptr<AScript>& MS2Ptr<AScript>::operator=<ASGameEntity>(const MS2Ptr<ASGameEntity>&);

MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);    // new ASGameEntity(v, n)

// The client's world service and the local player (worldservice.h spells the player as void*).
WorldService* FUN_1403ed2d0();
Unk_ActionKeyManager* FUN_140a7b810(MyPC* pPlayer);                    // MyPC's action key table
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);           // case-insensitive equal
bool FUN_14034eee0(const CStringW& str, const wchar_t* psz);           // operator!=

// The ui manager (FUN_1403ed2b0) and the dialogue singleton.
class Unk_AtUIMgr { public: int FUN_141adc940(int nUiId); };           // the ui is open
Unk_AtUIMgr* FUN_1403ed2b0();
void* FUN_140967100();
int FUN_141b21220(void* pTalkManager);                                 // a dialogue is open

// The sound/guide manager (FUN_140a94350): slot 7 plays a sound, slot 8 stops it.
class Unk_AtSound
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(int, int);
    virtual void vfunc_8(int);
};
Unk_AtSound* FUN_140a94350();

// The key hint table (FUN_1409331f0) and the options flag behind FUN_1409a8b10.
class Unk_AtHintTable { public: CStringW FUN_14142d760(int nId, int nFlag); };
Unk_AtHintTable* FUN_1409331f0();
void* FUN_1409a8b10();
const char* FUN_140a58500(void* p);
unsigned int FUN_141277f40();                                          // next UI layer

// The client constants singleton: two values at +0xc768 / +0xc7c0 give the screen origin.
class Unk_AtConst { public: int FUN_14025a620(); void* m_unknown; };
class Unk_AtConstants
{
public:
    char m_pad_0[0xc768];
    Unk_AtConst m_c768;
    char m_pad_c778[0x48];
    Unk_AtConst m_c7c0;
};
Unk_AtConstants* FUN_1401d3200();

// The target point accessors (a "valid" flag then the point, see Unk_AkoTarget).
int FUN_1413b58d0(Unk_AkoTarget* p);                                   // has a point
int FUN_1413b5870(Unk_AkoTarget* p);                                   // has no point
Vector3* FUN_1413b4140(Unk_AkoTarget* p);
Vector3* FUN_1413b4180(Unk_AkoTarget* p);
void FUN_140d00fb0(Vector3 ptWorld, NiPoint2* pScreen);        // project a world point to the screen
float FUN_1408f2120(const float& v, float fLo, float fHi);             // clamp

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1418b1520
UIActionTooltip::UIActionTooltip()
    : m_pAction(0)
{
    m_58 = 0;
    m_2c = 9;
    m_28 = FUN_141277f40();
}

// @0x1418b15e0
CString UIActionTooltip::GetTypeName()
{
    return "ActionTooltip";
}

// @0x1418b1630
void UIActionTooltip::vfunc_15()
{
    if (FUN_1418b2140() != 0)
        FUN_1418b1e60();
    else if (m_pAction != 0)
        FUN_1418b1ef0();
    else
    {
        if (FUN_1418b23a0() != 0x1e)
            FUN_1418b1ab0();
    }
}

// @0x1418b1690
void UIActionTooltip::vfunc_43()
{
}

// @0x1418b16a0
void UIActionTooltip::vfunc_2()
{
    UIHeadUpDisplay::vfunc_2();
}

// @0x1418b16c0
void UIActionTooltip::vfunc_3()
{
    FUN_1418b1e60();
    UIHeadUpDisplay::vfunc_3();
}

// MS2-FUNCTIONAL: temporary-lifetime / EH layout of the || condition differs
// @0x1418b16f0
void UIActionTooltip::FUN_1418b16f0()
{
    if (FUN_1418b23a0() == 0x1e || FUN_1403b3c40(FUN_1418b1a20(), L""))
        FUN_1418b1e60();
    else if (FUN_1418b2140() == 0)
        FUN_1418b1ab0();
    else
        FUN_1418b1e60();
}

// @0x1418b17d0
ActionKeyObject* UIActionTooltip::GetAction()
{
    return m_pAction;
}

// @0x1418b17f0
CStringW UIActionTooltip::GetTitle()
{
    return m_strTitle;
}

// @0x1418b1840
CStringW UIActionTooltip::GetText()
{
    return m_strText;
}

// @0x1418b1890
void UIActionTooltip::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x1418b1900
ActionKeyObject* UIActionTooltip::FUN_1418b1900()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    return FUN_140a7b810(pPlayer)->FUN_140953550();
}

// @0x1418b1950
int UIActionTooltip::FUN_1418b1950()
{
    int nId;
    if (FUN_1418b23a0() == 0x1d)
        nId = 0x493e3;
    else
        nId = 0x493e2;
    return nId;
}

// MS2-FUNCTIONAL: temporary and return-slot layout differs
// @0x1418b1990
CStringW UIActionTooltip::FUN_1418b1990()
{
    int nFlag;
    if (*FUN_140a58500(FUN_1409a8b10()) == 0)
        nFlag = 0;
    else
        nFlag = 2;
    int nId = FUN_1418b1950();
    return FUN_1409331f0()->FUN_14142d760(nId, nFlag);
}

// @0x1418b1a20
CStringW UIActionTooltip::FUN_1418b1a20()
{
    ActionKeyObject* pAction = FUN_1418b1900();
    if (pAction == 0)
        return CStringW(L"");
    return pAction->vfunc_6();
}

// MS2-FUNCTIONAL: EH state / temporary layout differs
// @0x1418b1ab0
void UIActionTooltip::FUN_1418b1ab0()
{
    if (m_30.get() == 0)
        return;
    ActionKeyObject* pAction = FUN_1418b1900();
    if (pAction != 0 && FUN_14034eee0(pAction->vfunc_6(), L""))
    {
        m_pAction = pAction;
        m_strTitle = pAction->vfunc_7();
        m_strText = pAction->vfunc_6();
        m_kTarget = pAction->vfunc_12();
        if (FUN_1413b58d0(&m_kTarget))
            FUN_1413b4140(&m_kTarget)->z += 75.0f;
        FUN_1418b1ef0();
        m_30->FUN_1412e80d0("show", FUN_1418b1990(), pAction->vfunc_6(), pAction->vfunc_8());
        FUN_140a94350()->vfunc_7(FUN_1418b1950(), 0);
    }
}

// @0x1418b1e60
void UIActionTooltip::FUN_1418b1e60()
{
    if (m_pAction == 0)
        return;
    if (m_30.get() != 0)
    {
        m_pAction = 0;
        m_30->Invoke("hide");
    }
    FUN_140a94350()->vfunc_8(0);
}

// MS2-FUNCTIONAL: float temporaries and struct-copy layout differ
// @0x1418b1ef0
void UIActionTooltip::FUN_1418b1ef0()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(m_30.get()));
    if (spEntity.get() != 0)
    {
        if (FUN_1413b5870(&m_kTarget) == 0)
        {
            NiPoint2 kScreen;
            FUN_140d00fb0(*FUN_1413b4180(&m_kTarget), &kScreen);
            int nWidth = spEntity->FUN_1422c1500();
            float fX = FUN_1408f2120(kScreen.x, 0, (float)(nWidth - spEntity->FUN_1422c1340()));
            int nHeight = spEntity->FUN_1422c1530();
            float fY = FUN_1408f2120(kScreen.y, 0, (float)(nHeight - spEntity->FUN_1422c13b0()));
            spEntity->FUN_1422c00f0(fX, fY);
        }
        else
        {
            int nX = FUN_1401d3200()->m_c768.FUN_14025a620();
            int nY = FUN_1401d3200()->m_c7c0.FUN_14025a620();
            int nCenterX = (int)((float)spEntity->FUN_1422c1500() * 0.5f + (float)nX);
            int nCenterY = (int)((float)spEntity->FUN_1422c1530() * 0.5f + (float)nY);
            spEntity->FUN_1422bffe0(nCenterX, nCenterY);
        }
    }
}

// MS2-FUNCTIONAL: switch lowering and repeated player lookups differ
// @0x1418b2140
int UIActionTooltip::FUN_1418b2140()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 1;
    if (FUN_140a7b810(pPlayer)->IsEnabled() == 0)
        return 1;
    switch (FUN_1418b23a0())
    {
    case 4:
    case 0x11:
    case 0x12:
        pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pPlayer == 0)
            return 1;
        return pPlayer->FUN_14166c930() == 0x19;
    default:
        return 0;
    case 0xe:
        return FUN_1403ed2b0()->FUN_141adc940(0x4e77) == 0;
    case 0x10:
        return FUN_1403ed2b0()->FUN_141adc940(0x4e56) == 0;
    case 0x13:
        return FUN_1403ed2b0()->FUN_141adc940(0x4ebd) == 0;
    case 0x14:
    case 0x16:
        return FUN_141b21220(FUN_140967100());
    case 0x1a:
        pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pPlayer == 0)
            return 1;
        return pPlayer->FUN_14166c930() == 0x3d;
    case 0x1c:
        pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pPlayer == 0)
            return 1;
        return pPlayer->FUN_14166c930() == 0x3e;
    }
}

// @0x1418b23a0
int UIActionTooltip::FUN_1418b23a0()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0x1e;
    return FUN_140a7b810(pPlayer)->GetCur();
}

// MS2-FUNCTIONAL: the exe dtor does not reset the vftables (source spelling unknown)
// @0x1418b23f0
UIActionTooltip::~UIActionTooltip()
{
}

MS2_EMIT_CRT_MEMMOVE_S();
