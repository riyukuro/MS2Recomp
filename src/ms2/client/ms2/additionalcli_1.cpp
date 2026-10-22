// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). AdditionalCli (additionalcli.h): the client record of one
// additional effect on an actor - packet decode, the start / keep / overlap / stop / invoke effects it plays, the
// stance bar, the buff strips and the shield bar - and AdditionalCustomCli, plus this part's COMDATs. The second part
// of the unit (the actor's buff list at PCBase+0x748) is additionalcli_2.cpp.
// MS2-UNIT: ?\additionalcli.cpp#1
// MS2-RANGE: 0x14096bae0-0x14096ee00 .text$mn
// MS2-PIN: ??_GAdditionalCli@@UEAAPEAXI@Z 0x14096e8e0
// MS2-PIN: ??_GAdditionalCustomCli@@UEAAPEAXI@Z 0x14096e920
// MS2-PIN: ??1AdditionalCustomCli@@UEAA@XZ 0x14096e600
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\additionalcli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include <efd/IBase.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/additionalcli.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/portraitpc.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/aseffect.h"
#include "ms2/client/ms2/uimainplayerinfo.h"
#include "ms2/client/ms2/uiupperhpbar.h"
#include "ms2/client/ms2/uinpcduelhpbardialog.h"
#include "ms2/unnamed/unit_140ba2180.h"
#include "ms2/placeholder/skilldatatablecli.h"
#include "ms2/placeholder/stancetable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2recover.h"

class Unk_WsC_GameObj : public GameObject {};
// The buff icon record of UINpcDuelHPBarDialog (an AdditionalCli; uinpcduelhpbardialog.cpp).
class Unk_NdBuff : public CPtred {};
// The shield bar entity behind PCBase vfunc_81 (UIShieldBar::Entity, uishieldbar.h).
class Unk_PCBaseComp_a68 : public CPtred
{
public:
    void FUN_140e85fc0(__int64 nCur, __int64 nMax);         // 0x140e85fc0 new value pair; hide when empty
};

unsigned FUN_141472bc0();                                   // 0x141472bc0 the current tick (ms)
bool FUN_140930110(int nObjectId);                          // 0x140930110 the object is the local player
UIMainPlayerInfo* FUN_140931900(int nClass);                // 0x140931900 the main player info dialog
int FUN_141092ff0(PCBase* pNpc);                            // 0x141092ff0 the npc shows an upper hp bar
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);            // 0x141b6efc0 the scene node of an entity

// The stance bar argument (UIStanceBar::FUN_140ba2390); the exe zero-initializes it.
struct Unk_AcStanceInfo : public Unk_StanceInfo
{
    // @0x14096e550
    Unk_AcStanceInfo() { m_a = 0; m_b = 0; }
};

// The unit's two-argument log call (FMT_VARIADIC instantiation over CLogString::FUN_1406535b0).
template <class T, class U>
void Unk_AcLog(CLogString* log, unsigned __int64 a, unsigned __int64 b, int category, const wchar_t* format,
               const T& first, const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406535b0(a, b, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// A UI object by class id, cast to its class.
template <class T> T* Unk_AcFindUI(eUIClassID nId)
{
    if (CUIService::GetInstance())
    {
        MS2Ptr<UIObject> p = CUIService::GetInstance()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// @0x14096bae0
AdditionalCli::AdditionalCli()
    : m_nCasterId(0), m_nStartTick(0), m_nEndTick(0), m_nOverlapCount(1), m_bEnabled(1), m_bSuspended(0),
      m_nShieldValue(0), m_b40(0), m_b44(0), m_nKey(0), m_pOwner(0), m_nId(0), m_nLevel(0), m_nKeepEffect(0),
      m_spLevel(0)
{
}

// @0x14096bbe0
AdditionalCli::~AdditionalCli()
{
}

// @0x14096bc20
bool AdditionalCli::FUN_14096bc20(int nOwner, MS2Ptr<AdditionalCli> spSrc)
{
    if (spSrc == 0)
        return false;
    *this = *spSrc;
    if (spSrc->GetOwner() && spSrc->GetOwner()->FUN_14123c580() == m_nCasterId)
        m_nCasterId = nOwner;
    m_pOwner = static_cast<PCBase*>(static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd1200(nOwner)));
    m_nKeepEffect = 0;
    if (FUN_14096c6f0())
        FUN_14096c740();
    return true;
}

// @0x14096bd30
void AdditionalCli::FUN_14096bd30(PCBase* pOwner, int nId, unsigned short nLevel, int n44)
{
    m_pOwner = pOwner;
    m_nKey = 1;
    m_nId = nId;
    m_nLevel = nLevel;
    m_b44 = n44;
    m_spLevel = SkillDataTableCli::GetInstance()->FUN_140aafef0(m_nId, m_nLevel);
    if (FUN_14096c6f0())
        FUN_14096c740();
}

// @0x14096be10
void AdditionalCli::FUN_14096be10(PCBase* pOwner, const Unk_AdditionalOwner& owner, CInPacket& packet)
{
    m_pOwner = pOwner;
    FUN_14096c2a0(owner);
    Unk_AdditionalState state;
    state.Decode(packet);
    FUN_14096c2e0(state);
    Unk_AdditionalValue value;
    value.Decode(packet);
    FUN_14096c360(value);
    FUN_14096c390(value);
    m_spLevel = SkillDataTableCli::GetInstance()->FUN_140aafef0(m_nId, m_nLevel);
}

// @0x14096bf40
void AdditionalCli::FUN_14096bf40(PCBase* pOwner, unsigned nFlags, const Unk_AdditionalOwner& owner, CInPacket& packet)
{
    if (pOwner == 0)
    {
        Unk_AcLog(TSingleton<CLogString>::GetInstance(), 0, 0, 0x134,
                  L"CAdditionalEffect::DecodeModifyPacket pcBase NULL AdditionalEffect ID : {0}, Level{1}", m_nId,
                  m_nLevel);
        return;
    }
    m_pOwner = pOwner;
    FUN_14096c2a0(owner);
    if (nFlags & 1)
    {
        int bEnabled = m_bEnabled;
        Unk_AdditionalState state;
        state.Decode(packet);
        MS2Ptr<AdditionalLevelData> spLevel = SkillDataTableCli::GetInstance()->FUN_140aafef0(state.m_n8, state.m_nC);
        if (spLevel == 0)
        {
            // The exe's state record holds the id / level as unsigned / unsigned short (one log instantiation).
            Unk_AcLog(TSingleton<CLogString>::GetInstance(), 0, 0, 0x134,
                      L"CAdditionalEffect::DecodeModifyPacket NotFound AdditionalEffect ID : {0}, Level{1}",
                      reinterpret_cast<const unsigned&>(state.m_n8),
                      reinterpret_cast<const unsigned short&>(state.m_nC));
            return;
        }
        m_spLevel = spLevel;
        bool bCountChanged = m_nOverlapCount != state.m_n10;
        bool bTimeChanged = m_nEndTick != state.m_n4;
        FUN_14096c2e0(state);
        bool bMe = FUN_140930110(m_nCasterId);
        if (bMe)
        {
            if (bTimeChanged)
                FUN_14096d0c0();
            if (bCountChanged)
                FUN_14096d130();
        }
        if (bEnabled != m_bEnabled)
        {
            if (m_spLevel->IsKeepCondition99())
            {
                if (bEnabled)
                    FUN_14096c650(m_nCasterId);
                else
                    FUN_14096c740();
            }
        }
        else if (bCountChanged && m_spLevel->HasOverlapKeepEffect())
        {
            FUN_14096ca50();
            return;
        }
    }
    if (nFlags & 2)
    {
        Unk_AdditionalValue value;
        value.Decode(packet);
        FUN_14096c360(value);
        FUN_14096d5c0();
    }
}

// @0x14096c2a0
void AdditionalCli::FUN_14096c2a0(const Unk_AdditionalOwner& owner)
{
    m_nKey = owner.m_n4;
    m_nCasterId = owner.m_n8;
}

// @0x14096c2e0
void AdditionalCli::FUN_14096c2e0(const Unk_AdditionalState& state)
{
    m_nStartTick = state.m_n0;
    m_nEndTick = state.m_n4;
    m_nId = state.m_n8;
    m_nLevel = state.m_nC;
    m_nOverlapCount = state.m_n10;
    m_bEnabled = state.m_n14;
}

// @0x14096c360
void AdditionalCli::FUN_14096c360(const Unk_AdditionalValue& value)
{
    m_nShieldValue = value.m_n0;
}

// @0x14096c390
void AdditionalCli::FUN_14096c390(const Unk_AdditionalValue& value)
{
    m_nShieldMax = value.m_n0;
}

// @0x14096c3c0
void AdditionalCli::FUN_14096c3c0(CStringW str, int n)
{
}

// @0x14096c3f0
void AdditionalCli::FUN_14096c3f0()
{
    if (m_spLevel == 0)
        return;
    if (!m_spLevel->GetParent()->GetFlag48())
        return;
    Unk_AcStanceInfo info;
    info.m_a = m_spLevel->m_nDurationTick;
    info.m_b = std::min<unsigned long>(FUN_14096d2e0(), info.m_a);
    UIStanceBar* pBar = Unk_AcFindUI<UIStanceBar>((eUIClassID)20378);
    if (pBar)
        pBar->FUN_140ba2390(&info);
}

// @0x14096c4c0
void AdditionalCli::FUN_14096c4c0()
{
    if (!m_bEnabled && m_spLevel->IsKeepCondition99())
        return;
    if (!m_b40)
        FUN_14096d840();
}

// @0x14096c520
void AdditionalCli::FUN_14096c520()
{
    FUN_14096db40();
    if (!m_bEnabled && m_spLevel->IsKeepCondition99())
        return;
    if (m_pOwner->FUN_141676500() && !m_spLevel->m_bAllowBattleRidingState)
    {
        if (m_bSuspended)
            return;
        m_bSuspended = 1;
        FUN_14096c650(m_nCasterId);
        FUN_14096d430();
        return;
    }
    if (m_bSuspended)
    {
        m_bSuspended = 0;
        FUN_14096d430();
        FUN_14096c740();
    }
    if (!m_nKeepEffect)
    {
        if (m_spLevel->HasOverlapKeepEffect())
            FUN_14096ca50();
        else
            FUN_14096c7a0();
    }
}

// @0x14096c650
void AdditionalCli::FUN_14096c650(int nCaster)
{
    FUN_14096ce50();
    FUN_14096d9d0(nCaster);
    bool bMe = FUN_140930110(m_nCasterId);
    if (bMe && m_spLevel->GetParent()->GetFlag48())
    {
        UIStanceBar* pBar = Unk_AcFindUI<UIStanceBar>((eUIClassID)20378);
        if (pBar)
            pBar->FUN_140ba2400();
    }
}

// @0x14096c6f0
int AdditionalCli::FUN_14096c6f0()
{
    if (!m_pOwner)
        return 0;
    if (m_spLevel == 0)
        return 0;
    return 1;
}

// @0x14096c740
void AdditionalCli::FUN_14096c740()
{
    if (m_spLevel->HasOverlapKeepEffect())
    {
        FUN_14096ca50();
    }
    else
    {
        FUN_14096ce50();
        FUN_14096c7a0();
    }
}

// @0x14096c7a0
void AdditionalCli::FUN_14096c7a0()
{
    if (FUN_14096db00())
        return;
    if (m_spLevel->m_motion.m_strKeepEffect.IsEmpty())
        return;
    Unk_EffectTarget kTarget;
    kTarget.m_strName = m_spLevel->m_motion.m_strKeepEffect;
    kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
    kTarget.m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
    kTarget.m_b30 = true;
    kTarget.m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
    kTarget.FUN_140a531b0(m_nCasterId);
    m_nKeepEffect = CEffectService::GetInstance()->FUN_1411a49c0(kTarget);
}

// @0x14096c8e0
void AdditionalCli::FUN_14096c8e0()
{
    if (FUN_14096db00())
        return;
    unsigned nCount = m_nOverlapCount;
    AdditionalLevelData::OverlapKeepEffectProperty& effect = m_spLevel->m_motion.m_overlapKeepEffect;
    std::map<unsigned, CString>::const_iterator it = effect.m_mapStart.find(nCount);
    if (it != effect.m_mapStart.end())
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = it->second;
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        kTarget.m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        kTarget.m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        kTarget.FUN_140a531b0(m_nCasterId);
        CEffectService::GetInstance()->FUN_1411a4a00(kTarget);
    }
}

// @0x14096ca50
void AdditionalCli::FUN_14096ca50()
{
    FUN_14096c8e0();
    FUN_14096ca80();
}

// @0x14096ca80
void AdditionalCli::FUN_14096ca80()
{
    if (FUN_14096db00())
        return;
    unsigned nCount = m_nOverlapCount;
    AdditionalLevelData::OverlapKeepEffectProperty& effect = m_spLevel->m_motion.m_overlapKeepEffect;
    if (m_nKeepEffect)
    {
        std::map<unsigned, CString, std::greater<unsigned> >::iterator itKeep = effect.m_mapKeep.find(nCount);
        if (itKeep == effect.m_mapKeep.end())
            return;
        CEffectService::GetInstance()->FUN_1411a6060(m_nKeepEffect);
        m_nKeepEffect = 0;
        FUN_14096ccc0(std::max<unsigned>(1, nCount - 1));
    }
    std::map<unsigned, CString, std::greater<unsigned> >::iterator it = effect.m_mapKeep.upper_bound(nCount + 1);
    if (it != effect.m_mapKeep.end())
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = it->second;
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        kTarget.m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        kTarget.m_b30 = true;
        kTarget.m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        kTarget.FUN_140a531b0(m_nCasterId);
        m_nKeepEffect = CEffectService::GetInstance()->FUN_1411a49c0(kTarget);
    }
}

// @0x14096ccc0
void AdditionalCli::FUN_14096ccc0(int nCount)
{
    if (FUN_14096db00())
        return;
    if (nCount == 0)
        nCount = m_nOverlapCount;
    AdditionalLevelData::OverlapKeepEffectProperty& effect = m_spLevel->m_motion.m_overlapKeepEffect;
    std::map<unsigned, CString, std::greater<unsigned> >::iterator it = effect.m_mapEnd.upper_bound(nCount + 1);
    if (it != effect.m_mapEnd.end())
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = it->second;
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        kTarget.m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        kTarget.m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        kTarget.FUN_140a531b0(m_nCasterId);
        CEffectService::GetInstance()->FUN_1411a4a00(kTarget);
    }
}

// @0x14096ce50
void AdditionalCli::FUN_14096ce50()
{
    if (!m_nKeepEffect)
        return;
    CEffectService::GetInstance()->FUN_1411a6060(m_nKeepEffect);
    m_nKeepEffect = 0;
    if (m_spLevel->HasOverlapKeepEffect())
        FUN_14096ccc0(0);
}

// @0x14096cec0
void AdditionalCli::FUN_14096cec0()
{
    if (!m_bEnabled && m_spLevel->IsKeepCondition99())
        return;
    if (!m_spLevel->m_motion.m_strInvokeEffect.IsEmpty())
    {
        Unk_WsC_GameObj* pCaster = WorldService::GetInstance()->FUN_141bd1200(m_nCasterId);
        if (pCaster != 0 && pCaster->vfunc_25() != 0)
            return;
        Unk_EffectTarget kTarget;
        kTarget.m_strName = m_spLevel->m_motion.m_strInvokeEffect;
        kTarget.m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        kTarget.m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        kTarget.FUN_140a531b0(m_nCasterId);
        CEffectService::GetInstance()->FUN_1411a4a00(kTarget);
    }
}

// @0x14096d050
int AdditionalCli::FUN_14096d050()
{
    if (m_spLevel == 0)
        return 0;
    if (m_bEnabled)
        return 1;
    return FUN_14096d2e0() > 0;
}

// @0x14096d0c0
void AdditionalCli::FUN_14096d0c0()
{
    if (!m_spLevel->GetParent()->GetFlag48())
        return;
    UIStanceBar* pBar = Unk_AcFindUI<UIStanceBar>((eUIClassID)20378);
    if (pBar)
        pBar->FUN_140ba2420(FUN_14096d2e0());
}

// @0x14096d130
void AdditionalCli::FUN_14096d130()
{
    if (!m_spLevel->GetParent()->GetFlag49())
        return;
    MS2Ptr<StanceData> spStance = TSingleton<StanceTable>::GetInstance()->HitCountStance(FUN_14096d2a0());
    if (spStance == 0)
        return;
    MS2Ptr<StanceLevelData> spLevel = spStance->LevelData(m_nOverlapCount);
    if (spLevel == 0)
        return;
    UIStanceBar* pBar = Unk_AcFindUI<UIStanceBar>((eUIClassID)20378);
    if (pBar)
        pBar->FUN_140ba2490(spLevel->m_nLevel);
}

// @0x14096d260
int AdditionalCli::GetKey()
{
    return m_nKey;
}

// @0x14096d280
PCBase* AdditionalCli::GetOwner()
{
    return m_pOwner;
}

// @0x14096d2a0
unsigned AdditionalCli::FUN_14096d2a0()
{
    return m_nId;
}

// @0x14096d2c0
unsigned short AdditionalCli::GetLevel()
{
    return m_nLevel;
}

// @0x14096d2e0
unsigned AdditionalCli::FUN_14096d2e0()
{
    if (m_nEndTick == 0)
        return 0;
    if (m_nEndTick < FUN_141472bc0())
        return 0;
    return m_nEndTick - FUN_141472bc0();
}

// @0x14096d330
unsigned AdditionalCli::FUN_14096d330()
{
    return m_nEndTick - m_nStartTick;
}

// @0x14096d350
int AdditionalCli::FUN_14096d350()
{
    if (m_spLevel == 0)
        return 0;
    int nOrder = 0;
    if (m_spLevel->m_ui.m_nPriority != 0)
        nOrder += 20;
    else if (m_spLevel->IsKeepCondition99())
        nOrder += 10;
    if (m_nCasterId == m_pOwner->FUN_14123c580())
        nOrder += 2;
    else if (FUN_140930110(m_nCasterId))
        nOrder += 1;
    return nOrder;
}

// @0x14096d430
void AdditionalCli::FUN_14096d430()
{
    bool bMe = FUN_140930110(m_nCasterId);
    if (m_spLevel->m_ui.FUN_1401927c0(bMe))
    {
        if (efd::DynamicCast<MyPC>(m_pOwner))
        {
            UIMainPlayerInfo* pInfo = FUN_140931900(20063);
            if (pInfo)
                pInfo->FUN_1419f10b0(MS2Ptr<Unk_AsBuff>(reinterpret_cast<Unk_AsBuff*>(this)));
        }
        else if (CNpc* pNpc = efd::DynamicCast<CNpc>(m_pOwner))
        {
            if (FUN_141092ff0(pNpc))
            {
                UIUpperHpBar* pBar = Unk_AcFindUI<UIUpperHpBar>((eUIClassID)20029);
                if (pBar)
                    pBar->FUN_141b4cfd0(Unk_UpperPtr<Unk_UpperBuff>(reinterpret_cast<Unk_UpperBuff*>(this)));
            }
            UINpcDuelHPBarDialog* pDuel = Unk_AcFindUI<UINpcDuelHPBarDialog>((eUIClassID)20322);
            if (pDuel)
                pDuel->FUN_140e6c540(MS2Ptr<Unk_NdBuff>(reinterpret_cast<Unk_NdBuff*>(this)));
        }
    }
}

// @0x14096d5c0
void AdditionalCli::FUN_14096d5c0()
{
    if (!GetOwner())
        return;
    if (m_spLevel == 0)
        return;
    if (m_spLevel->m_shield.m_fHpByTargetMaxHP > 0.0f || m_spLevel->m_shield.m_nHpValue > 0)
    {
        MS2Ptr<Unk_PCBaseComp_a68> spBar = GetOwner()->vfunc_81();
        if (spBar.get())
            spBar->FUN_140e85fc0(m_nShieldValue, m_nShieldMax);
    }
}

// @0x14096d6b0
bool AdditionalCli::FUN_14096d6b0()
{
    if (m_spLevel == 0 || !m_pOwner)
        return false;
    if (!m_bEnabled && m_spLevel->IsKeepCondition99())
        return false;
    if (m_pOwner->FUN_14123c580() != m_nCasterId)
        return false;
    if (m_spLevel->m_motion.m_strKeepEffect.IsEmpty())
        return false;
    if (m_spLevel->m_fCoolDownTime > 0.0f || m_spLevel->m_nDurationTick > 0)
        return false;
    return true;
}

// @0x14096d7a0
bool AdditionalCli::FUN_14096d7a0()
{
    if (m_bSuspended == 1)
        return false;
    if (m_spLevel->IsKeepCondition99())
        return m_bEnabled != 0;
    return true;
}

// @0x14096d810
AdditionalLevelData* AdditionalCli::FUN_14096d810()
{
    return m_spLevel.get();
}

// @0x14096d840
void AdditionalCli::FUN_14096d840()
{
    if (FUN_14096db00())
        return;
    if (m_spLevel->m_motion.m_strStartEffect.IsEmpty())
        return;
    if (FUN_141b6efc0(m_pOwner->FUN_14123c410()))
    {
        Unk_WsC_GameObj* pCaster = WorldService::GetInstance()->FUN_141bd1200(m_nCasterId);
        if (pCaster != 0 && pCaster->vfunc_25() != 0)
            return;
        Unk_EffectTarget kTarget;
        kTarget.m_strName = m_spLevel->m_motion.m_strStartEffect;
        kTarget.m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        kTarget.m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        kTarget.FUN_140a531b0(m_nCasterId);
        CEffectService::GetInstance()->FUN_1411a4a00(kTarget);
    }
}

// @0x14096d9d0
void AdditionalCli::FUN_14096d9d0(int nCaster)
{
    if (FUN_14096db00())
        return;
    if (m_spLevel->m_motion.m_strStopEffect.IsEmpty())
        return;
    Unk_EffectTarget kTarget;
    kTarget.m_strName = m_spLevel->m_motion.m_strStopEffect;
    kTarget.m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
    kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
    kTarget.m_nKind = WorldService::GetInstance()->FUN_141bd19d0(nCaster);
    kTarget.FUN_140a531b0(nCaster);
    CEffectService::GetInstance()->FUN_1411a4a00(kTarget);
}

// @0x14096db00
int AdditionalCli::FUN_14096db00()
{
    return efd::DynamicCast<PortraitPC>(m_pOwner) ? 1 : 0;
}

// @0x14096db40
void AdditionalCli::FUN_14096db40()
{
    if (!m_bEnabled)
        return;
    if (!m_spLevel->m_bImmediateActiveRequireSkill)
        return;
    MyPC* pMyPC = efd::DynamicCast<MyPC>(m_pOwner);
    if (!pMyPC)
        return;
    if (m_spLevel->m_setUsedSkillIDs.empty())
        return;
    if (pMyPC->FUN_14166c930() != 16)
    {
        m_bEnabled = 0;
    }
    else
    {
        unsigned nSkill = pMyPC->FUN_141673ef0();
        bool bFound = m_spLevel->m_setUsedSkillIDs.find(nSkill) != m_spLevel->m_setUsedSkillIDs.end();
        if (!bFound)
            m_bEnabled = 0;
    }
    if (m_bEnabled == 0 && m_spLevel->IsKeepCondition99())
        FUN_14096c650(m_nCasterId);
}

// @0x14096dcb0
AdditionalCustomCli::AdditionalCustomCli(PCBase* pOwner, int nKey, int nId, unsigned nEndTick, unsigned nCount)
{
    m_pOwner = pOwner;
    m_nKey = nKey;
    m_nCasterId = pOwner->FUN_14123c580();
    m_nStartTick = FUN_141472bc0();
    m_nEndTick = nEndTick;
    m_nOverlapCount = nCount;
    m_spLevel = SkillDataTableCli::GetInstance()->FUN_140aafef0(nId, 1);
    if (m_spLevel.get())
        m_nOverlapCount = m_spLevel->m_nMaxBuffCount < nCount ? m_spLevel->m_nMaxBuffCount : nCount;
}
