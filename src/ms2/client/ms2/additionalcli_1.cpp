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
#include "ms2/client/ms2/uishieldbar.h"
#include "ms2/unnamed/unit_140ba2180.h"
#include "ms2/placeholder/skilldatatablecli.h"
#include "ms2/placeholder/stancetable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2recover.h"

CLogString* GetLogString();   // the game log (0x140166440)

class NoticeMessage   // C3: unit-local view (ctor 0x140a52ef0, dtor 0x1405a89e0, 0x70 bytes)
{
public:
    NoticeMessage();
    ~NoticeMessage();
    void SetActor(int nActor);   // 0x140a53190
    void SetLookupId(int nId);   // 0x140a531b0
    void* m_storage[14];
};

class Unk_WsC_GameObj : public GameObject {};
// The shield bar entity behind PCBase vfunc_81 (UIShieldBar::Entity, uishieldbar.h).
class Unk_PCBaseComp_a68 : public CPtred
{
public:
    // C3: the value update is the real UIShieldBar::Entity::FUN_140e85fc0 (0x140e85fc0)
};

int GetServerTick();   // C3: was GetServerTick
bool IsUpperTargetId(int nObjectId);                          // 0x140930110 the object is the local player
UIMainPlayerInfo* FindMainPlayerInfo(int nClass);                // 0x140931900 the main player info dialog
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
        MS2Ptr<UIObject> p = CUIService::GetInstance()->FindObject(nId);
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
bool AdditionalCli::CloneFrom(int nOwner, MS2Ptr<AdditionalCli> spSrc)
{
    if (spSrc == 0)
        return false;
    *this = *spSrc;
    if (spSrc->GetOwner() && spSrc->GetOwner()->GetObjectId() == m_nCasterId)
        m_nCasterId = nOwner;
    m_pOwner = static_cast<PCBase*>(static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd1200(nOwner)));
    m_nKeepEffect = 0;
    if (IsValid())
        RestartKeepEffect();
    return true;
}

// @0x14096bd30
void AdditionalCli::InitLocal(PCBase* pOwner, int nId, unsigned short nLevel, int n44)
{
    m_pOwner = pOwner;
    m_nKey = 1;
    m_nId = nId;
    m_nLevel = nLevel;
    m_b44 = n44;
    m_spLevel = SkillDataTableCli::GetInstance()->FUN_140aafef0(m_nId, m_nLevel);
    if (IsValid())
        RestartKeepEffect();
}

// @0x14096be10
void AdditionalCli::FUN_14096be10(PCBase* pOwner, const Unk_AdditionalOwner& owner, CInPacket& packet)
{
    m_pOwner = pOwner;
    SetOwnerInfo(owner);
    Unk_AdditionalState state;
    state.Decode(packet);
    ApplyState(state);
    Unk_AdditionalValue value;
    value.Decode(packet);
    SetShieldValue(value);
    SetShieldMax(value);
    m_spLevel = SkillDataTableCli::GetInstance()->FUN_140aafef0(m_nId, m_nLevel);
}

// @0x14096bf40
void AdditionalCli::DecodeModifyPacket(PCBase* pOwner, unsigned nFlags, const Unk_AdditionalOwner& owner, CInPacket& packet)
{
    if (pOwner == 0)
    {
        Unk_AcLog(GetLogString(), 0, 0, 0x134,
                  L"CAdditionalEffect::DecodeModifyPacket pcBase NULL AdditionalEffect ID : {0}, Level{1}", m_nId,
                  m_nLevel);
        return;
    }
    m_pOwner = pOwner;
    SetOwnerInfo(owner);
    if (nFlags & 1)
    {
        int bEnabled = m_bEnabled;
        Unk_AdditionalState state;
        state.Decode(packet);
        MS2Ptr<AdditionalLevelData> spLevel = SkillDataTableCli::GetInstance()->FUN_140aafef0(state.m_n8, state.m_nC);
        if (spLevel == 0)
        {
            // The exe's state record holds the id / level as unsigned / unsigned short (one log instantiation).
            Unk_AcLog(GetLogString(), 0, 0, 0x134,
                      L"CAdditionalEffect::DecodeModifyPacket NotFound AdditionalEffect ID : {0}, Level{1}",
                      reinterpret_cast<const unsigned&>(state.m_n8),
                      reinterpret_cast<const unsigned short&>(state.m_nC));
            return;
        }
        m_spLevel = spLevel;
        bool bCountChanged = m_nOverlapCount != state.m_n10;
        bool bTimeChanged = m_nEndTick != state.m_n4;
        ApplyState(state);
        bool bMe = IsUpperTargetId(m_nCasterId);
        if (bMe)
        {
            if (bTimeChanged)
                UpdateStanceBarTime();
            if (bCountChanged)
                UpdateStanceBarLevel();
        }
        if (bEnabled != m_bEnabled)
        {
            if (m_spLevel->IsKeepCondition99())
            {
                if (bEnabled)
                    StopEffects(m_nCasterId);
                else
                    RestartKeepEffect();
            }
        }
        else if (bCountChanged && m_spLevel->HasOverlapKeepEffect())
        {
            PlayOverlapEffects();
            return;
        }
    }
    if (nFlags & 2)
    {
        Unk_AdditionalValue value;
        value.Decode(packet);
        SetShieldValue(value);
        UpdateShieldBar();
    }
}

// @0x14096c2a0
void AdditionalCli::SetOwnerInfo(const Unk_AdditionalOwner& owner)
{
    m_nKey = owner.m_n4;
    m_nCasterId = owner.m_n8;
}

// @0x14096c2e0
void AdditionalCli::ApplyState(const Unk_AdditionalState& state)
{
    m_nStartTick = state.m_n0;
    m_nEndTick = state.m_n4;
    m_nId = state.m_n8;
    m_nLevel = state.m_nC;
    m_nOverlapCount = state.m_n10;
    m_bEnabled = state.m_n14;
}

// @0x14096c360
void AdditionalCli::SetShieldValue(const Unk_AdditionalValue& value)
{
    m_nShieldValue = value.m_n0;
}

// @0x14096c390
void AdditionalCli::SetShieldMax(const Unk_AdditionalValue& value)
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
    info.m_b = std::min<unsigned long>(GetRemainTicks(), info.m_a);
    UIStanceBar* pBar = Unk_AcFindUI<UIStanceBar>((eUIClassID)20378);
    if (pBar)
        pBar->StartStance(&info);
}

// @0x14096c4c0
void AdditionalCli::FUN_14096c4c0()
{
    if (!m_bEnabled && m_spLevel->IsKeepCondition99())
        return;
    if (!m_b40)
        PlayStartEffect();
}

// @0x14096c520
void AdditionalCli::Update()
{
    FUN_14096db40();
    if (!m_bEnabled && m_spLevel->IsKeepCondition99())
        return;
    if (m_pOwner->IsBattleRiding() && !m_spLevel->m_bAllowBattleRidingState)
    {
        if (m_bSuspended)
            return;
        m_bSuspended = 1;
        StopEffects(m_nCasterId);
        UpdateBuffUI();
        return;
    }
    if (m_bSuspended)
    {
        m_bSuspended = 0;
        UpdateBuffUI();
        RestartKeepEffect();
    }
    if (!m_nKeepEffect)
    {
        if (m_spLevel->HasOverlapKeepEffect())
            PlayOverlapEffects();
        else
            PlayKeepEffect();
    }
}

// @0x14096c650
void AdditionalCli::StopEffects(int nCaster)
{
    RemoveKeepEffect();
    PlayStopEffect(nCaster);
    bool bMe = IsUpperTargetId(m_nCasterId);
    if (bMe && m_spLevel->GetParent()->GetFlag48())
    {
        UIStanceBar* pBar = Unk_AcFindUI<UIStanceBar>((eUIClassID)20378);
        if (pBar)
            pBar->StopStance();
    }
}

// @0x14096c6f0
int AdditionalCli::IsValid()
{
    if (!m_pOwner)
        return 0;
    if (m_spLevel == 0)
        return 0;
    return 1;
}

// @0x14096c740
void AdditionalCli::RestartKeepEffect()
{
    if (m_spLevel->HasOverlapKeepEffect())
    {
        PlayOverlapEffects();
    }
    else
    {
        RemoveKeepEffect();
        PlayKeepEffect();
    }
}

// @0x14096c7a0
void AdditionalCli::PlayKeepEffect()
{
    if (IsPortraitOwner())
        return;
    if (m_spLevel->m_motion.m_strKeepEffect.IsEmpty())
        return;
    NoticeMessage kTarget;   // C3: was Unk_EffectTarget
    ((Unk_EffectTarget&)(kTarget)).m_strName = m_spLevel->m_motion.m_strKeepEffect;
    ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->GetObjectId());
    ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
    ((Unk_EffectTarget&)(kTarget)).m_b30 = true;
    ((Unk_EffectTarget&)(kTarget)).m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
    kTarget.SetLookupId(m_nCasterId);
    m_nKeepEffect = CEffectService::GetInstance()->FUN_1411a49c0(((Unk_EffectTarget&)(kTarget)));
}

// @0x14096c8e0
void AdditionalCli::PlayOverlapStartEffect()
{
    if (IsPortraitOwner())
        return;
    unsigned nCount = m_nOverlapCount;
    AdditionalLevelData::OverlapKeepEffectProperty& effect = m_spLevel->m_motion.m_overlapKeepEffect;
    std::map<unsigned, CString>::const_iterator it = effect.m_mapStart.find(nCount);
    if (it != effect.m_mapStart.end())
    {
        NoticeMessage kTarget;   // C3: was Unk_EffectTarget
        ((Unk_EffectTarget&)(kTarget)).m_strName = it->second;
        ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->GetObjectId());
        ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        ((Unk_EffectTarget&)(kTarget)).m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        kTarget.SetLookupId(m_nCasterId);
        CEffectService::GetInstance()->InsertEffect(((Unk_EffectTarget&)(kTarget)));
    }
}

// @0x14096ca50
void AdditionalCli::PlayOverlapEffects()
{
    PlayOverlapStartEffect();
    FUN_14096ca80();
}

// @0x14096ca80
void AdditionalCli::FUN_14096ca80()
{
    if (IsPortraitOwner())
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
        PlayOverlapEndEffect(std::max<unsigned>(1, nCount - 1));
    }
    std::map<unsigned, CString, std::greater<unsigned> >::iterator it = effect.m_mapKeep.upper_bound(nCount + 1);
    if (it != effect.m_mapKeep.end())
    {
        NoticeMessage kTarget;   // C3: was Unk_EffectTarget
        ((Unk_EffectTarget&)(kTarget)).m_strName = it->second;
        ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->GetObjectId());
        ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        ((Unk_EffectTarget&)(kTarget)).m_b30 = true;
        ((Unk_EffectTarget&)(kTarget)).m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        kTarget.SetLookupId(m_nCasterId);
        m_nKeepEffect = CEffectService::GetInstance()->FUN_1411a49c0(((Unk_EffectTarget&)(kTarget)));
    }
}

// @0x14096ccc0
void AdditionalCli::PlayOverlapEndEffect(int nCount)
{
    if (IsPortraitOwner())
        return;
    if (nCount == 0)
        nCount = m_nOverlapCount;
    AdditionalLevelData::OverlapKeepEffectProperty& effect = m_spLevel->m_motion.m_overlapKeepEffect;
    std::map<unsigned, CString, std::greater<unsigned> >::iterator it = effect.m_mapEnd.upper_bound(nCount + 1);
    if (it != effect.m_mapEnd.end())
    {
        NoticeMessage kTarget;   // C3: was Unk_EffectTarget
        ((Unk_EffectTarget&)(kTarget)).m_strName = it->second;
        ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->GetObjectId());
        ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        ((Unk_EffectTarget&)(kTarget)).m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        kTarget.SetLookupId(m_nCasterId);
        CEffectService::GetInstance()->InsertEffect(((Unk_EffectTarget&)(kTarget)));
    }
}

// @0x14096ce50
void AdditionalCli::RemoveKeepEffect()
{
    if (!m_nKeepEffect)
        return;
    CEffectService::GetInstance()->FUN_1411a6060(m_nKeepEffect);
    m_nKeepEffect = 0;
    if (m_spLevel->HasOverlapKeepEffect())
        PlayOverlapEndEffect(0);
}

// @0x14096cec0
void AdditionalCli::PlayInvokeEffect()
{
    if (!m_bEnabled && m_spLevel->IsKeepCondition99())
        return;
    if (!m_spLevel->m_motion.m_strInvokeEffect.IsEmpty())
    {
        Unk_WsC_GameObj* pCaster = WorldService::GetInstance()->FUN_141bd1200(m_nCasterId);
        if (pCaster != 0 && pCaster->vfunc_25() != 0)
            return;
        NoticeMessage kTarget;   // C3: was Unk_EffectTarget
        ((Unk_EffectTarget&)(kTarget)).m_strName = m_spLevel->m_motion.m_strInvokeEffect;
        ((Unk_EffectTarget&)(kTarget)).m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->GetObjectId());
        ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        kTarget.SetLookupId(m_nCasterId);
        CEffectService::GetInstance()->InsertEffect(((Unk_EffectTarget&)(kTarget)));
    }
}

// @0x14096d050
int AdditionalCli::FUN_14096d050()
{
    if (m_spLevel == 0)
        return 0;
    if (m_bEnabled)
        return 1;
    return GetRemainTicks() > 0;
}

// @0x14096d0c0
void AdditionalCli::UpdateStanceBarTime()
{
    if (!m_spLevel->GetParent()->GetFlag48())
        return;
    UIStanceBar* pBar = Unk_AcFindUI<UIStanceBar>((eUIClassID)20378);
    if (pBar)
        pBar->UpdateTime(GetRemainTicks());
}

// @0x14096d130
void AdditionalCli::UpdateStanceBarLevel()
{
    if (!m_spLevel->GetParent()->GetFlag49())
        return;
    MS2Ptr<StanceData> spStance = TSingleton<StanceTable>::GetInstance()->HitCountStance(GetId());
    if (spStance == 0)
        return;
    MS2Ptr<StanceLevelData> spLevel = spStance->LevelData(m_nOverlapCount);
    if (spLevel == 0)
        return;
    UIStanceBar* pBar = Unk_AcFindUI<UIStanceBar>((eUIClassID)20378);
    if (pBar)
        pBar->UpdateStep(spLevel->m_nLevel);
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
unsigned AdditionalCli::GetId()
{
    return m_nId;
}

// @0x14096d2c0
unsigned short AdditionalCli::GetLevel()
{
    return m_nLevel;
}

// @0x14096d2e0
unsigned AdditionalCli::GetRemainTicks()
{
    if (m_nEndTick == 0)
        return 0;
    if (m_nEndTick < GetServerTick())
        return 0;
    return m_nEndTick - GetServerTick();
}

// @0x14096d330
unsigned AdditionalCli::FUN_14096d330()
{
    return m_nEndTick - m_nStartTick;
}

// @0x14096d350
int AdditionalCli::GetSortOrder()
{
    if (m_spLevel == 0)
        return 0;
    int nOrder = 0;
    if (m_spLevel->m_ui.m_nPriority != 0)
        nOrder += 20;
    else if (m_spLevel->IsKeepCondition99())
        nOrder += 10;
    if (m_nCasterId == m_pOwner->GetObjectId())
        nOrder += 2;
    else if (IsUpperTargetId(m_nCasterId))
        nOrder += 1;
    return nOrder;
}

// @0x14096d430
void AdditionalCli::UpdateBuffUI()
{
    bool bMe = IsUpperTargetId(m_nCasterId);
    if (m_spLevel->m_ui.FUN_1401927c0(bMe))
    {
        if (efd::DynamicCast<MyPC>(m_pOwner))
        {
            UIMainPlayerInfo* pInfo = FindMainPlayerInfo(20063);
            if (pInfo)
                pInfo->UpdateBuffEffect(MS2Ptr<AdditionalCli>(this));
        }
        else if (CNpc* pNpc = efd::DynamicCast<CNpc>(m_pOwner))
        {
            if (((class CNpc*)(class PCBase*)(pNpc))->IsBoss())
            {
                UIUpperHpBar* pBar = Unk_AcFindUI<UIUpperHpBar>((eUIClassID)20029);
                if (pBar)
                    pBar->UpdateBuff(MS2Ptr<AdditionalCli>(this));
            }
            UINpcDuelHPBarDialog* pDuel = Unk_AcFindUI<UINpcDuelHPBarDialog>((eUIClassID)20322);
            if (pDuel)
                pDuel->UpdateBuffEffect(MS2Ptr<AdditionalCli>(this));
        }
    }
}

// @0x14096d5c0
void AdditionalCli::UpdateShieldBar()
{
    if (!GetOwner())
        return;
    if (m_spLevel == 0)
        return;
    if (m_spLevel->m_shield.m_fHpByTargetMaxHP > 0.0f || m_spLevel->m_shield.m_nHpValue > 0)
    {
        MS2Ptr<Unk_PCBaseComp_a68> spBar = GetOwner()->vfunc_81();
        if (spBar.get())
            reinterpret_cast<UIShieldBar::Entity*>(spBar.operator->())->FUN_140e85fc0(m_nShieldValue, m_nShieldMax);
    }
}

// @0x14096d6b0
bool AdditionalCli::FUN_14096d6b0()
{
    if (m_spLevel == 0 || !m_pOwner)
        return false;
    if (!m_bEnabled && m_spLevel->IsKeepCondition99())
        return false;
    if (m_pOwner->GetObjectId() != m_nCasterId)
        return false;
    if (m_spLevel->m_motion.m_strKeepEffect.IsEmpty())
        return false;
    if (m_spLevel->m_fCoolDownTime > 0.0f || m_spLevel->m_nDurationTick > 0)
        return false;
    return true;
}

// @0x14096d7a0
bool AdditionalCli::IsActive()
{
    if (m_bSuspended == 1)
        return false;
    if (m_spLevel->IsKeepCondition99())
        return m_bEnabled != 0;
    return true;
}

// @0x14096d810
AdditionalLevelData* AdditionalCli::GetLevelData()
{
    return m_spLevel.get();
}

// @0x14096d840
void AdditionalCli::PlayStartEffect()
{
    if (IsPortraitOwner())
        return;
    if (m_spLevel->m_motion.m_strStartEffect.IsEmpty())
        return;
    if (FUN_141b6efc0(m_pOwner->GetEntity()))
    {
        Unk_WsC_GameObj* pCaster = WorldService::GetInstance()->FUN_141bd1200(m_nCasterId);
        if (pCaster != 0 && pCaster->vfunc_25() != 0)
            return;
        NoticeMessage kTarget;   // C3: was Unk_EffectTarget
        ((Unk_EffectTarget&)(kTarget)).m_strName = m_spLevel->m_motion.m_strStartEffect;
        ((Unk_EffectTarget&)(kTarget)).m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
        ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->GetObjectId());
        ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nCasterId);
        kTarget.SetLookupId(m_nCasterId);
        CEffectService::GetInstance()->InsertEffect(((Unk_EffectTarget&)(kTarget)));
    }
}

// @0x14096d9d0
void AdditionalCli::PlayStopEffect(int nCaster)
{
    if (IsPortraitOwner())
        return;
    if (m_spLevel->m_motion.m_strStopEffect.IsEmpty())
        return;
    NoticeMessage kTarget;   // C3: was Unk_EffectTarget
    ((Unk_EffectTarget&)(kTarget)).m_strName = m_spLevel->m_motion.m_strStopEffect;
    ((Unk_EffectTarget&)(kTarget)).m_b31 = m_spLevel->m_motion.m_bIgnoreOptimalHideStartEffect;
    ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->GetObjectId());
    ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd19d0(nCaster);
    kTarget.SetLookupId(nCaster);
    CEffectService::GetInstance()->InsertEffect(((Unk_EffectTarget&)(kTarget)));
}

// @0x14096db00
int AdditionalCli::IsPortraitOwner()
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
    if (pMyPC->GetCurStateId() != 16)
    {
        m_bEnabled = 0;
    }
    else
    {
        unsigned nSkill = pMyPC->GetCurrentSkillId();
        bool bFound = m_spLevel->m_setUsedSkillIDs.find(nSkill) != m_spLevel->m_setUsedSkillIDs.end();
        if (!bFound)
            m_bEnabled = 0;
    }
    if (m_bEnabled == 0 && m_spLevel->IsKeepCondition99())
        StopEffects(m_nCasterId);
}

// @0x14096dcb0
AdditionalCustomCli::AdditionalCustomCli(PCBase* pOwner, int nKey, int nId, unsigned nEndTick, unsigned nCount)
{
    m_pOwner = pOwner;
    m_nKey = nKey;
    m_nCasterId = pOwner->GetObjectId();
    m_nStartTick = GetServerTick();
    m_nEndTick = nEndTick;
    m_nOverlapCount = nCount;
    m_spLevel = SkillDataTableCli::GetInstance()->FUN_140aafef0(nId, 1);
    if (m_spLevel.get())
        m_nOverlapCount = m_spLevel->m_nMaxBuffCount < nCount ? m_spLevel->m_nMaxBuffCount : nCount;
}
