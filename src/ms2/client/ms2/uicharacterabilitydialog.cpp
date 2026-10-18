// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICharacterAbilityDialog and CCharacterAbilityManager: see
// uicharacterabilitydialog.h.
// MS2-UNIT: ?\uicharacterabilitydialog.cpp
// MS2-RANGE: 0x140f29a20-0x140f2e3c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlList@V?$MS2Ptr@VUnk_CaAbilityRow@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_CaAbilityRow@@@@@ATL@@@ATL@@QEAA@I@Z 0x140f2c7e0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VUnk_CaAbilityRow@@@@QEBA_NPEAVUnk_CaAbilityRow@@@Z 0x140f2cbf0 ; unique
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
#include "ms2/client/ms2/uigamemenudialog.h"
#include "ms2/ms2format.h"

#include "ms2/placeholder/header_statics_a.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

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
Unk_CaConfig* FUN_1401d3200();
int* FUN_1401d7c10(Unk_CaIntSlot* pSlot);
__int64* FUN_1402c05b0(Unk_CaIntSlot* pSlot);
extern __int64 DAT_143ab2898;                           // the meso of the player
extern void* DAT_143aca188;                             // the manager
extern void* DAT_143aac648;                             // the ability table

// The quest state (holder + 0x10) and the quest rows.
class Unk_CaQuestState { public: int FUN_140745590(int nQuest); };
class Unk_CaQuestHolder { public: char m_pad_0[0x10]; Unk_CaQuestState m_state; };
Unk_CaQuestHolder* FUN_140764020();
struct Unk_CaQuestRow { char m_pad_0[0x10]; int m_nType; char m_pad_14[0x14]; int m_28; char m_pad_2c[0x2c]; unsigned short m_58; };
class Unk_CaQuestRef
{
public:
    ~Unk_CaQuestRef();                                  // 0x14064d3e0
    bool FUN_140747650(int n);                          // a quest exists / is done
    Unk_CaQuestRow* FUN_14064d520() const;
    void* m_pad_00;
    void* m_p;
};
Unk_CaQuestRef FUN_14074bc40(int nQuest);
CStringW FUN_1416e4df0(int nQuest);                     // the quest name
CStringW FUN_1416e7fb0(int n);

class Unk_CaStrings { public: CStringW FUN_141811980(int, int); };
Unk_CaStrings* FUN_1401a9d70();
CStringW FUN_14028de60(int nStringId);
CStringW FUN_14028b8e0(const CStringW& str);
CStringW FUN_14028dee0(int nStringId, const fmt::ArgList& args);
CStringW FUN_1409e9bc0(int nStringId, const int& nA, const unsigned& nB);
CStringW FUN_14093fd30(int nStringId, const int* pDays, const __int64* pMeso);
CStringW FUN_14086aec0(ATL::CTimeSpan span, int nA, int nB, bool bDays, bool bHours);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_14151f200();
__time64_t FUN_140869440();

// The skill table: the row of a skill id.
struct Unk_CaSkillRow { char m_pad_00[0xc0]; CString m_strIcon; };
class Unk_CaSkillRef
{
public:
    ~Unk_CaSkillRef();                                  // 0x1401836a0
    bool FUN_14096e7e0(int n) const;                    // the skill is missing
    Unk_CaSkillRow* FUN_140184880() const;
    void* FUN_140184830() const;
    void* m_pad_00;
    void* m_p;
};
class Unk_CaSkillTable { public: Unk_CaSkillRef FUN_140aafef0(int nSkillId, unsigned short nLevel); };
Unk_CaSkillTable* FUN_1401958b0();

// The level rules.
int FUN_1401e0800(unsigned short nLevel);
unsigned FUN_1401e0790(unsigned short nLevel, int nPoints);

class Unk_CaUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_CaUIManager* FUN_1403ed2b0();
void* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(void* pWorld);
UIGameMenuDialog* FUN_140938b90(int nId);

class Unk_CaNotices { public: void FUN_140da4e40(CStringW, Delegate<void(NotifyObject*)>); };
Unk_CaNotices* FUN_140939a10();

// 0x141746230: the level change notification (as in scenestategame.cpp).
class NotifyChangeMyLevel : public NotifyObject
{
public:
    NotifyChangeMyLevel(unsigned short nLevel, unsigned short nOldLevel) : m_nLevel(nLevel), m_nOldLevel(nOldLevel) {}
    virtual ~NotifyChangeMyLevel() = default;
    virtual CStringW vfunc_1();
    unsigned short m_nLevel;                                // +0x18
    unsigned short m_nOldLevel;                             // +0x1a
};
MS2_CHECK_SIZE(NotifyChangeMyLevel, 0x20);

MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, IMessageListener* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_140d73aa0(CStringW text, int nType, IMessageListener* pListener, CStringW tag);
void FUN_141a024a0(CMsgBoxData* pBox, int n);
void FUN_141a01700(CMsgBoxData* pBox, int nStringId, int nA, int nB);
void FUN_140710590(COutPacket& packet);

AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// The singletons.
CCharacterAbilityManager* FUN_140f2d240();
Unk_CaTable* FUN_140f2d250();

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
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
Scaleform::GFx::Value FUN_140f2c5d0(AScript* pDlg, const char* szMethod, int n, ASArray& arr)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcd10(args.FUN_1409b1f70(0), n);
    FUN_1422bce40(args.FUN_1409b1f70(1), arr);
    return pDlg->FUN_1422bb8f0(szMethod, args);
}

// @0x140f2c690
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
Scaleform::GFx::Value FUN_140f2c690(AScript* pDlg, const char* szMethod, int n, CStringW str)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcd10(args.FUN_1409b1f70(0), n);
    FUN_1422bcea0(args.FUN_1409b1f70(1), (const wchar_t*)str);
    return pDlg->FUN_1422bb8f0(szMethod, args);
}

// @0x140f2d240
CCharacterAbilityManager* FUN_140f2d240()
{
    return (CCharacterAbilityManager*)DAT_143aca188;
}

// @0x140f2d250
Unk_CaTable* FUN_140f2d250()
{
    return (Unk_CaTable*)DAT_143aac648;
}

// @0x140f2c530
UICharacterAbilityDialog* FUN_140f2c530(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
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
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void CCharacterAbilityManager::FUN_140f29ad0(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        FUN_140f29b70(packet);
        break;
    case 1:
        FUN_140f29de0();
        break;
    case 2:
        FUN_140f29cc0(packet);
        break;
    }
}

// @0x140f29b70
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void CCharacterAbilityManager::FUN_140f29b70(CInPacket& packet)
{
    m_abilities.RemoveAll();
    int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < nCount; i++)
        m_abilities.AddTail(static_cast<CInputStream&>(packet).vfunc_o8_3());
    m_nResetTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
    m_nPoints = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (UICharacterAbilityDialog* pDlg = FUN_140f2c530(0x4f0c))
        pDlg->FUN_140f2b0f0();
    if (UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28))
        pMenu->FUN_141938850();
}

// @0x140f29cc0
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void CCharacterAbilityManager::FUN_140f29cc0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    MS2Ptr<Unk_CaAbilityRow> ref = FUN_140f2d250()->FUN_1401e0670(nId);
    if (!(ref == NULL))
    {
        m_abilities.AddTail(nId);
        if (UICharacterAbilityDialog* pDlg = FUN_140f2c530(0x4f0c))
            pDlg->FUN_140f2b110(ref);
        if (UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28))
            pMenu->FUN_141938850();
    }
}

// @0x140f29de0
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void CCharacterAbilityManager::FUN_140f29de0()
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
    PCBase* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == NULL)
        return 0;
    return FUN_1401e0790((unsigned short)pPc->vfunc_78(), m_nPoints);
}

// @0x140f29ea0
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
ATL::CTimeSpan CCharacterAbilityManager::FUN_140f29ea0()
{
    if (m_nResetTime == 0)
        return ATL::CTimeSpan(0);
    CMsTime tReset(m_nResetTime);
    CMsTime tNow(FUN_140869440());
    ATL::CTimeSpan elapsed = tNow - tReset;
    ATL::CTimeSpan cooldown((unsigned)(*FUN_1401d7c10(&FUN_1401d3200()->m_cooldown) * 0x3c));
    if (elapsed.GetTotalMinutes() < cooldown.GetTotalMinutes())
        return cooldown - elapsed;
    return ATL::CTimeSpan(0);
}

// @0x140f29f90
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
int CCharacterAbilityManager::FUN_140f29f90(MS2Ptr<Unk_CaAbilityRow> ref)
{
    if (FUN_140f29e00() == 0)
        return 0;
    PCBase* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == NULL)
        return 0;
    if ((short)ref->m_nRequireLevel == (short)pPc->vfunc_78() && FUN_140f2a0b0(ref->m_nId) == 0)
        return 1;
    return 0;
}

// @0x140f2a0b0
int CCharacterAbilityManager::FUN_140f2a0b0(int nId)
{
    return m_abilities.Find(nId) != 0;
}

// @0x140f2a100
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
int CCharacterAbilityManager::FUN_140f2a100(int nId)
{
    MS2Ptr<Unk_CaAbilityRow> ref = FUN_140f2d250()->FUN_1401e0670(nId);
    if (ref == NULL)
        return 1;
    PCBase* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == NULL)
        return 1;
    if ((unsigned short)pPc->vfunc_78() < ref->m_nRequireLevel)
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
    m_timer.FUN_140268840();
    m_bBuilt = 0;
}

// @0x140f2a2f0
UICharacterAbilityDialog::~UICharacterAbilityDialog()
{
}

// @0x140f2a330
CString UICharacterAbilityDialog::vfunc_1()
{
    return CString("CharacterAbilityDialog");
}

// @0x140f2a380
int UICharacterAbilityDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeMyLevel", Delegate<void(NotifyObject*)>(this, &UICharacterAbilityDialog::FUN_140f2b000));
    return 1;
}

// @0x140f2a480
void UICharacterAbilityDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140f2a4a0
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void UICharacterAbilityDialog::vfunc_72()
{
    if (vfunc_55() != 1 && m_bBuilt != 0 && m_timer.FUN_140268870(1000) != 0)
        FUN_140f2b850();
}

// @0x140f2a510
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void UICharacterAbilityDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0(CString("m_close"));
    m_bBuilt = 0;
    FUN_140f2ba20();
    PCBase* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc != NULL)
    {
        if (FUN_1401e0800((unsigned short)pPc->vfunc_78()) != 0
            && FUN_140764020()->m_state.FUN_140745590(*FUN_1401d7c10(&FUN_1401d3200()->m_quest)) != 0)
        {
            UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28);
            if (pMenu)
                pMenu->FUN_141938ae0(0x4f0c, 0);
            FUN_140f2b1e0();
        }
    }
}

// @0x140f2a620
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
int UICharacterAbilityDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    PCBase* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == NULL)
        return 0;
    if (_stricmp(szMethod, "onAddButton") == 0)
    {
        if (FUN_140f2d240()->FUN_140f29e00() == 0)
        {
            FUN_140d73aa0(FUN_14028de60(0xc57), 0, 0, CStringW(L""));
            return 1;
        }
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nId = data.FUN_1422b8b10();
            if (FUN_140f2d240()->FUN_140f2a0b0(nId))
                return 1;
            MS2Ptr<Unk_CaAbilityRow> ref = FUN_140f2d250()->FUN_1401e0670(nId);
            if ((unsigned short)pPc->vfunc_78() < ref->m_nRequireLevel)
                return 1;
            COutPacket packet(0x89, 0);
            packet.vfunc_o10_1(2);
            packet.vfunc_o10_3(nId);
            FUN_140710590(packet);
        }
    }
    else if (_stricmp(szMethod, "onResetButton") == 0)
    {
        if (!(FUN_140f2d240()->FUN_140f29ea0() > ATL::CTimeSpan(0)))
        {
            ATL::CTimeSpan cooldown((unsigned)(*FUN_1401d7c10(&FUN_1401d3200()->m_cooldown) * 0x3c));
            int nDays = (int)cooldown.GetDays();
            CStringW strText = FUN_14093fd30(0xc5b, &nDays, FUN_1402c05b0(&FUN_1401d3200()->m_meso));
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, CStringW(strText), static_cast<IMessageListener*>(this), CStringW(L"OnMesoReset"));
            if (box.get())
            {
                FUN_141a024a0(box.operator->(), 0);
                FUN_141a01700(box.operator->(), 0xc5c, 0x476, 0);
                FUN_140d73c60(box);
                return 1;
            }
        }
        else
        {
            FUN_140d73aa0(FUN_14028de60(0xc5d), 0, 0, CStringW(L""));
        }
    }
    return 0;
}

// @0x140f2abb0
void UICharacterAbilityDialog::vfunc_15()
{
}

// @0x140f2abc0
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void UICharacterAbilityDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    PCBase* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == NULL)
        return;
    CString strKind = pArgs->FUN_1422b8d30();
    if (strKind == "ability")
    {
        MS2Ptr<Unk_CaAbilityRow> ref = FUN_140f2d250()->FUN_1401e0670(pArgs->FUN_1422b8b10());
        if (ref == NULL)
            return;
        Unk_CaSkillRef skill = FUN_1401958b0()->FUN_140aafef0(ref->m_nSkillId, ref->m_nSkillLevel);
        if (skill.FUN_14096e7e0(0))
            return;
        ASTooltip tip(*pRetVal, 2);
        tip.FUN_1409e2750(skill.FUN_140184830(), 5, 0);
    }
    else if (strKind == "CategoryIcon")
    {
        MS2Ptr<Unk_CaCategoryRow> cat = FUN_140f2d250()->FUN_1401e0560(pArgs->FUN_1422b8b10());
        if (cat == NULL)
            return;
        ASTooltip tip(*pRetVal, 2);
        tip.FUN_1409e26b0(cat->m_strTooltip);
    }
}

// @0x140f2ae70
int UICharacterAbilityDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (!pMsg->FUN_1422e4520() && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (strTag.Find(L"OnMesoReset", 0) == 0 && nResult == 0)
        {
            if (DAT_143ab2898 < *FUN_1402c05b0(&FUN_1401d3200()->m_meso))
            {
                FUN_141275260(0xc58, 1, 1);
                return 1;
            }
            COutPacket packet(0x89, 0);
            packet.vfunc_o10_1(1);
            FUN_140710590(packet);
        }
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x140f2b000
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void UICharacterAbilityDialog::FUN_140f2b000(NotifyObject* pNotify)
{
    NotifyChangeMyLevel* p = dynamic_cast<NotifyChangeMyLevel*>(pNotify);
    if (p && FUN_1401e0800(p->m_nLevel) != 0
        && FUN_140764020()->m_state.FUN_140745590(*FUN_1401d7c10(&FUN_1401d3200()->m_quest)) != 0)
    {
        FUN_140f2bee0(p->m_nLevel);
        if (!(m_30 == NULL) && vfunc_55() == 0)
            FUN_140f2b1e0();
    }
}

// @0x140f2b0f0
void UICharacterAbilityDialog::FUN_140f2b0f0()
{
    FUN_140f2b1e0();
}

// @0x140f2b110
void UICharacterAbilityDialog::FUN_140f2b110(MS2Ptr<Unk_CaAbilityRow> ref)
{
    if (m_30.get())
        FUN_1409ee290(&m_30)->Invoke("LearnAbility", ref->m_nCategory, ref->m_nSkillId);
    FUN_140f2b760();
}

// @0x140f2b1e0
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void UICharacterAbilityDialog::FUN_140f2b1e0()
{
    if (!(m_30 == NULL))
    {
        ATL::CAtlList<MS2Ptr<Unk_CaCategoryRow> > cats(10);
        FUN_140f2d250()->FUN_1401e0350(&cats);
        if (!cats.IsEmpty())
        {
            for (POSITION pos = cats.GetHeadPosition(); pos != NULL; cats.GetNext(pos))
            {
                MS2Ptr<Unk_CaCategoryRow> cat = cats.GetAt(pos);
                FUN_140f2c690(FUN_1409ee290(&m_30), "buildCategory", cat->m_nId, CStringW(cat->m_strName));
                if (!cat->m_abilities.FUN_1401e2540())
                {
                    ATL::CRBMap<unsigned short, MS2Ptr<Unk_CaAbilityRow> > byLevel(10);
                    for (POSITION p = cat->m_abilities.FUN_1401e2140(); p != NULL; cat->m_abilities.FUN_1401e1ec0(p))
                    {
                        MS2Ptr<Unk_CaAbilityRow> a = cat->m_abilities.FUN_1401e2220(p);
                        byLevel.SetAt(a->m_nRequireLevel, a);
                    }
                    ASArray arr(2);
                    for (POSITION p = byLevel.GetHeadPosition(); p != NULL; byLevel.GetNext(p))
                    {
                        MS2Ptr<Unk_CaAbilityRow> a = byLevel.GetValueAt(p);
                        Unk_CaSkillRef skill = FUN_1401958b0()->FUN_140aafef0(a->m_nSkillId, a->m_nSkillLevel);
                        if (!skill.FUN_14096e7e0(0))
                        {
                            ASObj item(2);
                            item.FUN_1409c0d20("id", a->m_nId);
                            item.FUN_1407cba60("iconPath", CString(skill.FUN_140184880()->m_strIcon));
                            item.FUN_1409c48f0("requireLevel", a->m_nRequireLevel);
                            item.FUN_1407cb9c0("disableAbility", FUN_140f2d240()->FUN_140f2a100(a->m_nId));
                            item.FUN_1407cb9c0("learnAbility", FUN_140f2d240()->FUN_140f2a0b0(a->m_nId));
                            item.FUN_1407cbbe0("newAbility", false);
                            arr.FUN_1422bbf00(item);
                        }
                    }
                    FUN_140f2c5d0(FUN_1409ee290(&m_30), "buildAbility", cat->m_nId, arr);
                }
            }
            FUN_140f2b760();
            FUN_140f2b850();
            m_bBuilt = 1;
        }
    }
}

// @0x140f2b760
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void UICharacterAbilityDialog::FUN_140f2b760()
{
    if (!(m_30 == NULL))
    {
        unsigned nTotal = FUN_140f2d240()->FUN_140f29e40();
        int nRemain = FUN_140f2d240()->FUN_140f29e00();
        CStringW strText = FUN_1409e9bc0(0xc5a, nRemain, nTotal);
        FUN_1409ee290(&m_30)->Invoke("SetPointInfoText", CStringW(strText));
    }
}

// @0x140f2b850
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void UICharacterAbilityDialog::FUN_140f2b850()
{
    if (!(m_30 == NULL))
    {
        CStringW strRemain;
        ATL::CTimeSpan remain = FUN_140f2d240()->FUN_140f29ea0();
        bool bCooling = remain > ATL::CTimeSpan(0);
        if (bCooling)
        {
            LONGLONG nHours = remain.GetHours();
            LONGLONG nDays = remain.GetDays();
            strRemain = FUN_14086aec0(remain, 1, 1, nDays == 0, nHours == 0);
        }
        int nIntermediate = FUN_140f2d240()->FUN_140f2a210();
        FUN_1409ee290(&m_30)->Invoke("SetRemainCoolButton", bCooling, CStringW(strRemain), nIntermediate);
    }
}

// @0x140f2ba20
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void UICharacterAbilityDialog::FUN_140f2ba20()
{
    if (!(m_30 == NULL))
    {
        int nQuest = *FUN_1401d7c10(&FUN_1401d3200()->m_quest);
        Unk_CaQuestRef quest = FUN_14074bc40(nQuest);
        if (!quest.FUN_140747650(0))
        {
            CStringW strUnlock = FUN_1401a9d70()->FUN_141811980(0x50, nQuest);
            if (strUnlock.GetLength() == 0)
            {
                switch (quest.FUN_14064d520()->m_nType)
                {
                case 0:
                    strUnlock = FUN_14028de60(0x5dd);
                    break;
                case 1:
                    strUnlock = FUN_14028de60(0x5de);
                    break;
                case 2:
                    strUnlock = FUN_14028de60(0x5df);
                    break;
                case 6:
                    strUnlock = FUN_14028b8e0(CStringW(L"s_quest_guild_quest"));
                    break;
                case 8:
                    strUnlock = FUN_14028b8e0(CStringW(L"s_quest_field_quest"));
                    break;
                case 9:
                    strUnlock = FUN_14028b8e0(CStringW(L"s_quest_alliance_quest"));
                    break;
                }
            }
            CStringW strText = FUN_140f2c170(0xc60, FUN_1416e4df0(nQuest), quest.FUN_14064d520()->m_58, strUnlock, FUN_1416e7fb0(quest.FUN_14064d520()->m_28));
            FUN_1409ee290(&m_30)->Invoke("SetDisabledText", CStringW(strText));
        }
    }
}

// @0x140f2bee0
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
void UICharacterAbilityDialog::FUN_140f2bee0(unsigned short nLevel)
{
    ATL::CAtlList<MS2Ptr<Unk_CaAbilityRow> > abilities(10);
    FUN_140f2d250()->FUN_1401e0450(&abilities);
    bool bNew = false;
    for (POSITION pos = abilities.GetHeadPosition(); pos != NULL; abilities.GetNext(pos))
    {
        MS2Ptr<Unk_CaAbilityRow> a = abilities.GetAt(pos);
        if (a->m_nRequireLevel == nLevel && !FUN_140f2d240()->FUN_140f2a0b0(a->m_nId))
        {
            bNew = true;
            break;
        }
    }
    UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28);
    if (pMenu)
        pMenu->FUN_141938ae0(0x4f0c, bNew);
}

// The CRT's header-inline memcpy_s of this TU (0x140f2e3b0), kept alive through the pointer below.
// @0x140f2e3b0
// MS2-FUNCTIONAL: residual diff (MS2Ptr/CTimeSpan temporaries and EH funclet order)
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
