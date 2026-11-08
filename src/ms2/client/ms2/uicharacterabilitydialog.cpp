// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICharacterAbilityDialog and CCharacterAbilityManager: see
// uicharacterabilitydialog.h.
// MS2-UNIT: ?\uicharacterabilitydialog.cpp
// MS2-RANGE: 0x140f29a20-0x140f2e3c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlList@V?$MS2Ptr@VCCharacterAbility@@@@V?$CElementTraits@V?$MS2Ptr@VCCharacterAbility@@@@@ATL@@@ATL@@QEAA@I@Z 0x140f2c7e0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VCCharacterAbility@@@@QEBA_NPEAVCCharacterAbility@@@Z 0x140f2cbf0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicharacterabilitydialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uicharacterabilitydialog.h"

#include <stdlib.h>
#include <typeinfo>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/ccharacterabilitymanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/client/ms2/uigamemenudialog.h"
#include "ms2/ms2format.h"

#include "ms2/placeholder/header_statics_a.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // C3: AdditionalLevelData
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Init, Check
#include "ms2/commonfiles/characterability.h"
#include "ms2/placeholder/cquestmanagercommon.h"

// ---- unit-local views of unrecovered callees -------------------------------------------------------------------------

class CMsgBoxData;

// The constants block: the slots read by the ability dialog.
struct Unk_CaIntSlot { char m_pad[8]; };
class Unk_CaConfig
{
public:
    char m_pad_0[0x6cb8];
    Unk_CaIntSlot m_cooldown;                           // +0x6cb8 the reset cooldown in hours
    char m_pad_6d10[0x6d10 - 0x6cb8 - sizeof(Unk_CaIntSlot)];
    Unk_CaIntSlot m_meso;                               // +0x6d10 the reset price
    char m_pad_6d68[0x6dd0 - 0x6d10 - sizeof(Unk_CaIntSlot)];
    Unk_CaIntSlot m_quest;                              // +0x6dd0 the quest that opens the dialog
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
extern __int64 DAT_143ab2898;                           // the meso of the player
class CCharacterAbilityManager;
class CCharacterAbilityTable;

// The quest state (holder + 0x10) and the quest rows.
class Unk_CaQuestState { public: int FUN_140745590(int nQuest); };
class Unk_CaQuestHolder { public: char m_pad_0[0x10]; Unk_CaQuestState m_state; };
void* FUN_140764020();   // C3: was FUN_140764020
struct Unk_CaQuestRow { char m_pad_0[0x1c]; int m_nType; char m_pad_20[8]; int m_28; char m_pad_2c[0x2c]; unsigned short m_58; };
MS2_CHECK_OFFSET(Unk_CaQuestRow, m_nType, 0x1c);   // the exe reads it through 0x14074b050 ([rcx+0x1c])
MS2_CHECK_OFFSET(Unk_CaQuestRow, m_28, 0x28);
MS2_CHECK_OFFSET(Unk_CaQuestRow, m_58, 0x58);
MS2Ptr<CQuestData> FUN_14074bc40(int nQuest);
int FUN_14074b050(CQuestData* pQuest);                  // the quest type
CStringW FUN_1416e4df0(int nQuest);                     // the quest name
CStringW FUN_1416e7fb0(int n);

CStringW GetStringCommon(int nStringId);
CStringW GetStringCommonByKey(const CStringW& str);
CStringW FUN_14028dee0(int nStringId, const fmt::ArgList& args);
template <class A, class B> CStringW BlockFormat(int nStringId, const A& a, const B& b);
template <class A, class B> CStringW FormatStringId(int nId, const A& a, const B& b);
CStringW FormatTimeSpan(ATL::CTimeSpan span, bool bA, bool bB, bool bDays, bool bHours);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_14151f200();
__time64_t GetServerTime();

// The level rules.
int FUN_1401e0800(unsigned short nLevel);
int FUN_1401e0790(unsigned short, int);   // C3: was FUN_1401e0790

class Unk_CaUIManager { public: };
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
UIGameMenuDialog* FUN_140938b90(int nId);

class Unk_SingletonObj* FUN_140939a10();   // C3: the notify-system getter, the definer's return type

// 0x141746230: the level change notification (as in scenestategame.cpp).
class NotifyChangeMyLevel : public NotifyObject
{
public:
    NotifyChangeMyLevel(unsigned short nLevel, unsigned short nOldLevel) : m_nLevel(nLevel), m_nOldLevel(nOldLevel) {}
    virtual ~NotifyChangeMyLevel() = default;
    virtual CStringW GetTypeName();
    unsigned short m_nLevel;                                // +0x18
    unsigned short m_nOldLevel;                             // +0x1a
};
MS2_CHECK_SIZE(NotifyChangeMyLevel, 0x20);

MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_140d73aa0(CStringW text, int nType, void* pListener, CStringW tag);
void FUN_140710590(COutPacket& packet);

void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// The singletons.
CCharacterAbilityManager* FUN_140f2d240();
CCharacterAbilityTable* FUN_140f2d250();

// ---- the formatter of the pending-quest text (one template instance) -------------------------------------------------

template <class A, class B, class C, class D> CStringW FUN_140f2c170(int nStringId, const A& a, const B& b, const C& c, const D& d)
{
    const fmt::internal::ArgArray<4>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(c),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(d)};
    return FUN_14028dee0(nStringId, fmt::ArgList(fmt::internal::make_type(a, b, c, d), args));
}

// ---- the Invoke forms of the ability movie -----------------------------------------------------------------------------

// @0x140f2c5d0
Scaleform::GFx::Value AScript::FUN_140f2c5d0(const char* szMethod, int n, ASArray& arr)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bcd10(&args[0], n);
    FUN_1422bce40(&args[1], arr);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f2c690
Scaleform::GFx::Value AScript::FUN_140f2c690(const char* szMethod, int n, CStringW str)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bcd10(&args[0], n);
    FUN_1422bcea0(&args[1], (const wchar_t*)str);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f2d240
CCharacterAbilityManager* FUN_140f2d240()
{
    return (CCharacterAbilityManager*)reinterpret_cast<void*>(TSingleton<CCharacterAbilityManager>::s_instance);
}

// @0x140f2d250
CCharacterAbilityTable* FUN_140f2d250()
{
    return TSingleton<CCharacterAbilityTable>::s_instance;
}

// @0x140f2c530
UICharacterAbilityDialog* FUN_140f2c530(int nId)
{
    if (reinterpret_cast<Unk_CaUIManager*>(TSingleton<CUIService>::GetInstance()))
    {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<UICharacterAbilityDialog*>((UIObject*)p);
    }
    return 0;
}

// ---- CCharacterAbilityManager ------------------------------------------------------------------------------------------

// @0x140f29a20
CCharacterAbilityManager::CCharacterAbilityManager()
    : m_abilities(10)
{
    m_nResetTime = 0;
    m_nPoints = 0;
}

// @0x140f29a90
CCharacterAbilityManager::~CCharacterAbilityManager()
{
}

// @0x140f29ad0
void CCharacterAbilityManager::OnCharacterAbility(CInPacket& packet)
{
    int nMode = packet.ReadUInt8();
    switch (nMode)
    {
    case 0:
        FUN_140f29b70(packet);
        break;
    case 2:
        FUN_140f29cc0(packet);
        break;
    case 1:
        FUN_140f29de0(packet);
        break;
    }
}

// @0x140f29b70
void CCharacterAbilityManager::FUN_140f29b70(CInPacket& packet)
{
    m_abilities.RemoveAll();
    unsigned nCount = packet.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        int nId = packet.ReadInt32();
        m_abilities.AddTail(nId);
    }
    m_nResetTime = packet.ReadInt64();
    m_nPoints = packet.ReadInt32();
    if (UICharacterAbilityDialog* pDlg = FUN_140f2c530(0x4f0c))
        pDlg->FUN_140f2b0f0();
    if (UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28))
        pMenu->FUN_141938850();
}

// @0x140f29cc0
void CCharacterAbilityManager::FUN_140f29cc0(CInPacket& packet)
{
    int nId = packet.ReadInt32();
    MS2Ptr<CCharacterAbility> ref = FUN_140f2d250()->FUN_1401e0670(nId);
    if (ref == NULL)
        return;
    m_abilities.AddTail(nId);
    if (UICharacterAbilityDialog* pDlg = FUN_140f2c530(0x4f0c))
        pDlg->FUN_140f2b110(ref);
    if (UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28))
        pMenu->FUN_141938850();
}

// @0x140f29de0
void CCharacterAbilityManager::FUN_140f29de0(CInPacket& packet)
{
}

// @0x140f29e00
int CCharacterAbilityManager::FUN_140f29e00()
{
    return (int)(FUN_140f29e40() - m_abilities.GetCount());
}

// @0x140f29e40
unsigned CCharacterAbilityManager::FUN_140f29e40()
{
    PCBase* pPc = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPc == NULL)
        return 0;
    return FUN_1401e0790((unsigned short)pPc->vfunc_78(), m_nPoints);
}

// @0x140f29ea0
ATL::CTimeSpan CCharacterAbilityManager::FUN_140f29ea0()
{
    if (m_nResetTime == 0)
        return ATL::CTimeSpan(0);
    CMsTime tReset(m_nResetTime);
    CMsTime tNow(GetServerTime());
    ATL::CTimeSpan elapsed = tNow - tReset;
    ATL::CTimeSpan cooldown((unsigned)(*reinterpret_cast<int*>(reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_CaConfig*)GetClientConstants())->m_cooldown)->Get()) * 0x3c));
    if (elapsed.GetTotalMinutes() >= cooldown.GetTotalMinutes())
        return ATL::CTimeSpan(0);
    return cooldown - elapsed;
}

// @0x140f29f90
int CCharacterAbilityManager::FUN_140f29f90(MS2Ptr<CCharacterAbility> ref)
{
    if (FUN_140f29e00() == 0)
        return 0;
    PCBase* pPc = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPc == NULL)
        return 0;
    if (ref->m_nRequireLevel != (unsigned short)pPc->vfunc_78())
        return 0;
    if (FUN_140f2a0b0(ref->m_nId) != 0)
        return 0;
    return 1;
}

// @0x140f2a0b0
int CCharacterAbilityManager::FUN_140f2a0b0(int nId)
{
    return m_abilities.Find(nId) != 0;
}

// @0x140f2a100
int CCharacterAbilityManager::FUN_140f2a100(int nId)
{
    MS2Ptr<CCharacterAbility> ref = FUN_140f2d250()->FUN_1401e0670(nId);
    if (ref == NULL)
        return 1;
    PCBase* pPc = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPc == NULL)
        return 1;
    if (ref->m_nRequireLevel > (unsigned short)pPc->vfunc_78())
        return 1;
    return 0;
}

// @0x140f2a210
int CCharacterAbilityManager::FUN_140f2a210()
{
    return !m_abilities.IsEmpty();
}

// ---- UICharacterAbilityDialog ------------------------------------------------------------------------------------------

// @0x140f2a260
UICharacterAbilityDialog::UICharacterAbilityDialog()
{
    FUN_141924170(1);
    m_timer.Init();
    m_bBuilt = 0;
}

// @0x140f2a2f0
UICharacterAbilityDialog::~UICharacterAbilityDialog()
{
}

// @0x140f2a330
CString UICharacterAbilityDialog::GetTypeName()
{
    return CString("CharacterAbilityDialog");
}

// @0x140f2a380
int UICharacterAbilityDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    reinterpret_cast<NotifySystem*>(FUN_140939a10())->RegisterNotify(L"NotifyChangeMyLevel", Delegate<void(NotifyObject*)>(this, &UICharacterAbilityDialog::FUN_140f2b000));
    return 1;
}

// @0x140f2a480
void UICharacterAbilityDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140f2a4a0
void UICharacterAbilityDialog::vfunc_72()
{
    if (vfunc_55() == 1)
        return;
    if (m_bBuilt == 0)
        return;
    if (m_timer.Check(1000) == 0)
        return;
    FUN_140f2b850();
}

// @0x140f2a510
void UICharacterAbilityDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0(CString("m_close"));
    m_bBuilt = 0;
    FUN_140f2ba20();
    PCBase* pPc = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPc == NULL)
        return;
    if (FUN_1401e0800((unsigned short)pPc->vfunc_78()) == 0)
        return;
    if (reinterpret_cast<CQuestManagerCommon*>(&((class Unk_CaQuestHolder*)FUN_140764020())->m_state)->FUN_140745590(*reinterpret_cast<int*>(reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_CaConfig*)GetClientConstants())->m_quest)->Get())) == 0)
        return;
    UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28);
    if (pMenu)
        pMenu->FUN_141938ae0(0x4f0c, 0);
    FUN_140f2b1e0();
}

// @0x140f2a620
int UICharacterAbilityDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    PCBase* pPc = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPc == NULL)
        return 0;
    if (_stricmp(szMethod, "onAddButton") == 0)
    {
        if (FUN_140f2d240()->FUN_140f29e00() == 0)
        {
            FUN_140d73aa0(GetStringCommon(0xc57), 0, 0, CStringW(L""));
            return 1;
        }
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            int nId = data.PopUInt();
            if (FUN_140f2d240()->FUN_140f2a0b0(nId))
                return 1;
            MS2Ptr<CCharacterAbility> ref = FUN_140f2d250()->FUN_1401e0670(nId);
            if (ref->m_nRequireLevel > (unsigned short)pPc->vfunc_78())
                return 1;
            COutPacket packet(static_cast<int>(SendOp::CharacterAbility), 0);
            packet.WriteUInt8(2);
            packet.WriteInt32(nId);
            FUN_140710590(packet);
        }
    }
    else if (_stricmp(szMethod, "onResetButton") == 0)
    {
        if (FUN_140f2d240()->FUN_140f29ea0() > 0)
        {
            FUN_140d73aa0(GetStringCommon(0xc5d), 0, 0, CStringW(L""));
        }
        else
        {
            ATL::CTimeSpan cooldown((unsigned)(*reinterpret_cast<int*>(reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_CaConfig*)GetClientConstants())->m_cooldown)->Get()) * 0x3c));
            __int64 nDays = cooldown.GetDays();
            CStringW strText = FormatStringId<__int64, __int64>(0xc5b, nDays, *reinterpret_cast<Common::Constants::Value<__int64>*>(&((class Unk_CaConfig*)GetClientConstants())->m_meso)->Get());
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, CStringW(strText), static_cast<IMessageListener*>(this), CStringW(L"OnMesoReset"));
            if (box.get())
            {
                ((class CMsgBoxData*)(class CMsgBoxData*)(box.operator->()))->FUN_141a024a0(0);
                ((class CMsgBoxData*)(class CMsgBoxData*)(box.operator->()))->SetButtonLabelIds(0xc5c, 0x476, 0);
                FUN_140d73c60(box);
                return 1;
            }
        }
    }
    return 0;
}

// @0x140f2abb0
void UICharacterAbilityDialog::vfunc_15()
{
}

// @0x140f2abc0
void UICharacterAbilityDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    PCBase* pPc = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPc == NULL)
        return;
    CString strKind = pArgs->FUN_1422b8d30();
    if (strKind == "ability")
    {
        int nId = pArgs->PopUInt();
        MS2Ptr<CCharacterAbility> ref = FUN_140f2d250()->FUN_1401e0670(nId);
        if (ref == NULL)
            return;
        MS2Ptr<AdditionalLevelData> skill = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(ref->m_nAdditionalEffectId, ref->m_nAdditionalEffectLevel);
        if (skill == 0)
            return;
        ASTooltip tip(*pRetVal, 2);
        tip.FUN_1409e2750(skill.get(), 5, 0);
    }
    else if (strKind == "CategoryIcon")
    {
        int nId = pArgs->PopUInt();
        MS2Ptr<CCharacterAbilityCategory> cat = FUN_140f2d250()->FUN_1401e0560(nId);
        if (cat == NULL)
            return;
        ASTooltip tip(*pRetVal, 2);
        tip.ApplyTextTooltip(cat->m_strTooltip);
    }
}

// @0x140f2ae70
int UICharacterAbilityDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (!pMsg->FUN_1422e4520() && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nResult = pMsg->PopInt();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (strTag.Find(L"OnMesoReset", 0) == 0 && nResult == 0)
        {
            if (DAT_143ab2898 < *reinterpret_cast<Common::Constants::Value<__int64>*>(&((class Unk_CaConfig*)GetClientConstants())->m_meso)->Get())
            {
                FUN_141275260(0xc58, 1, 1);
                return 1;
            }
            COutPacket packet(static_cast<int>(SendOp::CharacterAbility), 0);
            packet.WriteUInt8(1);
            FUN_140710590(packet);
        }
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x140f2b000
void UICharacterAbilityDialog::FUN_140f2b000(NotifyObject* pNotify)
{
    NotifyChangeMyLevel* p = dynamic_cast<NotifyChangeMyLevel*>(pNotify);
    if (p == NULL)
        return;
    if (FUN_1401e0800(p->m_nLevel) == 0)
        return;
    if (reinterpret_cast<CQuestManagerCommon*>(&((class Unk_CaQuestHolder*)FUN_140764020())->m_state)->FUN_140745590(*reinterpret_cast<int*>(reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_CaConfig*)GetClientConstants())->m_quest)->Get())) == 0)
        return;
    FUN_140f2bee0(p->m_nLevel);
    if (m_30 == NULL)
        return;
    if (vfunc_55() != 0)
        return;
    FUN_140f2b1e0();
}

// @0x140f2b0f0
void UICharacterAbilityDialog::FUN_140f2b0f0()
{
    FUN_140f2b1e0();
}

// @0x140f2b110
void UICharacterAbilityDialog::FUN_140f2b110(MS2Ptr<CCharacterAbility> ref)
{
    if (m_30.get())
        m_30->Invoke("LearnAbility", (int)ref->m_nCategoryId, (int)ref->m_nAdditionalEffectId);
    FUN_140f2b760();
}

// @0x140f2b1e0
void UICharacterAbilityDialog::FUN_140f2b1e0()
{
    if (m_30 == NULL)
        return;
    ATL::CAtlList<MS2Ptr<CCharacterAbilityCategory> > cats(10);
    FUN_140f2d250()->FUN_1401e0350(&cats);
    if (cats.IsEmpty())
        return;
    for (POSITION pos = cats.GetHeadPosition(); pos != NULL; cats.GetNext(pos))
    {
        MS2Ptr<CCharacterAbilityCategory> cat = cats.GetAt(pos);
        m_30->FUN_140f2c690("buildCategory", cat->m_nId, CStringW(cat->m_strName));
        ATL::CAtlMap<unsigned int, MS2Ptr<CCharacterAbility> >& abilities = cat->m_abilities;
        if (abilities.IsEmpty())
            continue;
        ATL::CRBMap<unsigned short, MS2Ptr<CCharacterAbility> > byLevel(10);
        for (POSITION p = abilities.GetStartPosition(); p != NULL; abilities.GetNext(p))
        {
            MS2Ptr<CCharacterAbility> a = abilities.GetValueAt(p);
            byLevel.SetAt(a->m_nRequireLevel, a);
        }
        ASArray arr(2);
        for (POSITION p = byLevel.GetHeadPosition(); p != NULL; byLevel.GetNext(p))
        {
            MS2Ptr<CCharacterAbility> a = byLevel.GetValueAt(p);
            MS2Ptr<AdditionalLevelData> skill = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(a->m_nAdditionalEffectId, a->m_nAdditionalEffectLevel);
            if (skill == 0)
                continue;
            ASObj item(2);
            item.FUN_1409c0d20("id", a->m_nId);
            item.FUN_1407cba60("iconPath", CString(skill->m_ui.m_strIcon));
            item.FUN_1409c48f0("requireLevel", a->m_nRequireLevel);
            item.FUN_1407cb9c0("disableAbility", FUN_140f2d240()->FUN_140f2a100(a->m_nId));
            item.FUN_1407cb9c0("learnAbility", FUN_140f2d240()->FUN_140f2a0b0(a->m_nId));
            item.FUN_1407cbbe0("newAbility", false);
            arr.PushObj(item);
        }
        m_30->FUN_140f2c5d0("buildAbility", cat->m_nId, arr);
    }
    FUN_140f2b760();
    FUN_140f2b850();
    m_bBuilt = 1;
}

// @0x140f2b760
void UICharacterAbilityDialog::FUN_140f2b760()
{
    if (m_30 == NULL)
        return;
    unsigned nTotal = FUN_140f2d240()->FUN_140f29e40();
    int nRemain = FUN_140f2d240()->FUN_140f29e00();
    CStringW strText = BlockFormat<unsigned, unsigned>(0xc5a, reinterpret_cast<const unsigned&>(nRemain), nTotal);
    m_30->Invoke("SetPointInfoText", CStringW(strText));
}

// @0x140f2b850
void UICharacterAbilityDialog::FUN_140f2b850()
{
    if (m_30 == NULL)
        return;
    int bCooling = 0;
    CStringW strRemain;
    ATL::CTimeSpan remain = FUN_140f2d240()->FUN_140f29ea0();
    if (remain > 0)
    {
        bCooling = 1;
        strRemain = FormatTimeSpan(remain, true, true, remain.GetDays() == 0, remain.GetHours() == 0);
    }
    int nIntermediate = FUN_140f2d240()->FUN_140f2a210();
    m_30->Invoke("SetRemainCoolButton", bCooling, CStringW(strRemain), nIntermediate);
}

// @0x140f2ba20
void UICharacterAbilityDialog::FUN_140f2ba20()
{
    if (m_30 == NULL)
        return;
    int nQuest = *reinterpret_cast<int*>(reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_CaConfig*)GetClientConstants())->m_quest)->Get());
    MS2Ptr<CQuestData> quest = FUN_14074bc40(nQuest);
    if (quest == 0)
        return;
    CStringW strUnlock = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x50, nQuest);
    if (strUnlock.GetLength() == 0)
    {
        switch (FUN_14074b050(quest.operator->()))
        {
        case 0:
            strUnlock = GetStringCommon(0x5dd);
            break;
        case 1:
            strUnlock = GetStringCommon(0x5de);
            break;
        case 2:
            strUnlock = GetStringCommon(0x5df);
            break;
        case 6:
            strUnlock = GetStringCommonByKey(L"s_quest_guild_quest");
            break;
        case 8:
            strUnlock = GetStringCommonByKey(L"s_quest_field_quest");
            break;
        case 9:
            strUnlock = GetStringCommonByKey(L"s_quest_alliance_quest");
            break;
        }
    }
    CStringW strText = FUN_140f2c170(0xc60, FUN_1416e4df0(nQuest), reinterpret_cast<Unk_CaQuestRow*>(quest.operator->())->m_58, strUnlock, FUN_1416e7fb0(reinterpret_cast<Unk_CaQuestRow*>(quest.operator->())->m_28));
    m_30->Invoke("SetDisabledText", CStringW(strText));
}

// @0x140f2bee0
void UICharacterAbilityDialog::FUN_140f2bee0(unsigned short nLevel)
{
    ATL::CAtlList<MS2Ptr<CCharacterAbility> > abilities(10);
    FUN_140f2d250()->FUN_1401e0450(&abilities);
    int bNew = 0;
    for (POSITION pos = abilities.GetHeadPosition(); pos != NULL; abilities.GetNext(pos))
    {
        MS2Ptr<CCharacterAbility> a = abilities.GetAt(pos);
        if (a->m_nRequireLevel == nLevel && !FUN_140f2d240()->FUN_140f2a0b0(a->m_nId))
        {
            bNew = 1;
            break;
        }
    }
    UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28);
    if (pMenu)
        pMenu->FUN_141938ae0(0x4f0c, bNew ? 1 : 0);
}

// The CRT's header-inline memcpy_s of this TU (0x140f2e3b0), kept alive through the pointer below.
// @0x140f2e3b0
#pragma function(memcpy)
static __inline errno_t ms2_ca_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnCaMemcpyS)(void*, size_t, const void*, size_t) = &ms2_ca_memcpy_s;
// MS2-PIN: ??1CAtlStringMgr@ATL@@UEAA@XZ 0x140f2b1d0 ; byte-identical look-alike, keep the copy with this unit
