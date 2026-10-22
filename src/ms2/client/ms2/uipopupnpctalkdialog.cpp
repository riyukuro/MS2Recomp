// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPopupNpcTalkDialog: see uipopupnpctalkdialog.h.
// MS2-UNIT: ?\uipopupnpctalkdialog.cpp
// MS2-RANGE: 0x140e76460-0x140e78150 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipopupnpctalkdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uipopupnpctalkdialog.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/placeholder/cinematiccontent.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>

MS2_EMIT_CRT_MEMMOVE_S();

// ---- out-of-unit callees (names describe uses) ----
class Unk_PnContent;
struct Unk_PnContentPtr
{
    Unk_PnContent* FUN_14078f3d0() const;                       // operator->
    void* FUN_140e78000() const { return m_p; }                 // 0x140e78000 the raw pointer (this unit)
    void* m_00;
    void* m_p;
};
class Unk_PnContentArray
{
public:
    int FUN_14078fae0() const;                                  // GetCount
    const Unk_PnContentPtr& FUN_14078f350(__int64 i) const;     // GetAt
};
class Unk_PnTalkScript
{
public:
    char m_pad[0x68];
    Unk_PnContentArray m_contents;                              // +0x68
};
class Unk_PnContent
{
public:
    char m_pad[0x18];
    CStringW m_strText;                                         // +0x18
};
class Unk_PnWorld { public: void* FUN_141bd0cc0(); };
Unk_PnWorld* FUN_1403ed2d0();
unsigned FUN_141bd3060(Unk_PnWorld* pWorld);                    // the map id
class Unk_PnQuestTable { public: void FUN_14074d360(unsigned nMap, ATL::CAtlArray<unsigned>& rOut); };
Unk_PnQuestTable* FUN_1407476c0();
class Unk_PnGame { public: bool FUN_14036d570(int nId); };
Unk_PnGame* FUN_140166410();
class Unk_PnUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int nType); };
Unk_PnUIMgr* FUN_1403ed2b0();
CQuestManager* FUN_140764020();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
Unk_PnScriptPtr FUN_1408564b0(int nQuestId, int n);
NotifySystem* FUN_140939a10();
UIQuestEventDispatcher* FUN_140bfc4b0();
CStringW FUN_1401aa6a0(int nId);                                // npc name
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);
class Unk_PnKeyTable { public: CStringW FUN_14142d220(int n); CStringW FUN_14142d760(int nId, int n); };
Unk_PnKeyTable* FUN_1409331f0();
class Unk_PnTextFilter { public: void FUN_1416fb300(CStringW& str); };
Unk_PnTextFilter* FUN_1403b4750();
class Unk_PnButton : public ASDisplayObject { public: void FUN_1422cdfb0(const CStringW& strText); };
class Unk_PnRoot : public AScript { public:
    Scaleform::GFx::Value FUN_1409b46e0(const char* szMethod, CString strArg);
    Scaleform::GFx::Value FUN_140acd130(const char* szMethod, CStringW strArg);
};
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
class Unk_PnActor { public: void vfunc_4(int, int, int); };
UIFameContentsNotify* FUN_140e77d80(int nType);
void FUN_140710590(COutPacket& rPacket);
int FUN_1418dd0d0();
CInputKeyHandler* FUN_14025e7c0();
int FUN_140408410(ATL::CAtlArray<unsigned>* pArr, const unsigned* pn);   // index of the value (-1 when absent)

// @0x140e76460
UIPopupNpcTalkDialog::UIPopupNpcTalkDialog()
{
    FUN_141924170(1);
    m_180 = 0;
    m_188.FUN_140e77f50(0);
    m_184 = 0;
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    FUN_140939a10()->RegisterNotify(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UIPopupNpcTalkDialog::FUN_140e770a0));
    FUN_140939a10()->RegisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UIPopupNpcTalkDialog::FUN_140e771b0));
}

// @0x140e76770
UIPopupNpcTalkDialog::~UIPopupNpcTalkDialog()
{
    FUN_140bfc4b0()->FUN_141aa8850(this);
    FUN_140939a10()->UnregisterNotify(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UIPopupNpcTalkDialog::FUN_140e770a0));
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UIPopupNpcTalkDialog::FUN_140e771b0));
}

// @0x140e769d0
CString UIPopupNpcTalkDialog::GetTypeName() { return "PopupNpcTalkDialog"; }

// @0x140e76a20
int UIPopupNpcTalkDialog::vfunc_65() { if (!UIDialog::vfunc_65()) return 0; return 1; }

// @0x140e76a50
void UIPopupNpcTalkDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_184 = 0;
    m_180 = 0;
    m_188.FUN_140e77f50(0);
}

// @0x140e76ab0
void UIPopupNpcTalkDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (FUN_140e77330() == 0)
        vfunc_67();
}

// @0x140e76af0
int UIPopupNpcTalkDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onClickNext", szMethod) == 0)
    {
        m_180++;
        int nState = FUN_140e77330();
        if (nState != 1)
        {
            if (nState == 2)
            {
                if (FUN_140764020()->FUN_1407456d0(m_184) != 0)
                {
                    COutPacket packet(0x29, 0);
                    packet.Encode1(4);
                    packet.Encode4(m_184);
                    packet.Encode4(0);
                    packet.Encode4(0);
                    FUN_140710590(packet);
                }
                else
                {
                    UIFameContentsNotify* pFame = FUN_140e77d80(0x4f5a);
                    if (pFame != 0)
                        pFame->FUN_141ac25b0(m_184);
                }
            }
            vfunc_67();
        }
        return 1;
    }
    else if (_stricmp("onClickEnd", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    return 0;
}

// @0x140e76cd0
void UIPopupNpcTalkDialog::vfunc_o178_1(void* pQuest)
{
    if (pQuest == 0)
        return;
    if (((CQuest*)pQuest)->GetQuestType() != 8)
        return;
    if (FUN_140e77b80(((CQuest*)pQuest)->FUN_140bfc580()) == 0)
        return;
    FUN_140e771e0(((CQuest*)pQuest)->FUN_140bfc580());
}

// @0x140e76d50
void UIPopupNpcTalkDialog::vfunc_o178_3(void* pQuest)
{
    if (pQuest == 0)
        return;
    if (((CQuest*)pQuest)->FUN_140d738d0() == 0)
        return;
    FUN_140e771e0(((CQuest*)pQuest)->FUN_140bfc580());
}

// @0x140e76db0
void UIPopupNpcTalkDialog::vfunc_43()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_1409ee290(&m_30)));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(2, 0, FUN_1418dd0d0() * -1);
}

// @0x140e76e70
int UIPopupNpcTalkDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    if (vfunc_56() != 0)
        return 0;
    if (FUN_14025e7c0()->FUN_14116d840())
    {
        if (FUN_140764020()->FUN_1407456d0(m_184) == 0)
        {
            UIFameContentsNotify* pFame = FUN_140e77d80(0x4f5a);
            if (pFame != 0)
                pFame->FUN_141ac25b0(m_184);
        }
        vfunc_69();
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x493e2, 0, 0))
    {
        m_180++;
        int nState = FUN_140e77330();
        if (nState != 1 && nState == 2)
        {
            if (FUN_140764020()->FUN_1407456d0(m_184) != 0)
            {
                COutPacket packet(0x29, 0);
                packet.Encode1(4);
                packet.Encode4(m_184);
                packet.Encode4(0);
                packet.Encode4(0);
                FUN_140710590(packet);
            }
            else
            {
                UIFameContentsNotify* pFame = FUN_140e77d80(0x4f5a);
                if (pFame != 0)
                    pFame->FUN_141ac25b0(m_184);
            }
            vfunc_67();
        }
    }
    return 0;
}

// @0x140e770a0
void UIPopupNpcTalkDialog::FUN_140e770a0(NotifyObject*)
{
    ATL::CAtlArray<unsigned> quests;
    FUN_1407476c0()->FUN_14074d360(FUN_141bd3060(FUN_1403ed2d0()), quests);
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        unsigned nQuest = quests[i];
        if (FUN_140764020()->FUN_140745630(nQuest) == 0)
            continue;
        if (m_198.Lookup(nQuest) != 0)
            continue;
        m_198.SetAt(nQuest, 1);
        FUN_140e771e0(nQuest);
        break;
    }
}

// @0x140e771b0
void UIPopupNpcTalkDialog::FUN_140e771b0(NotifyObject*) { FUN_140e77300(); }

// MS2-FUNCTIONAL: the exe stores the first step value before the quest call (a constant-store sequence no source form reproduced).
// @0x140e771e0
void UIPopupNpcTalkDialog::FUN_140e771e0(int nQuest)
{
    if (!FUN_140166410()->FUN_14036d570(0x95))
        return;
    int nStep = 100;
    if (FUN_140764020()->FUN_1407456d0(nQuest) != 0)
        nStep = 300;
    else
        nStep = 100;
    m_188 = FUN_1408564b0(nQuest, nStep);
    if (m_188.IsNull())
        return;
    m_184 = nQuest;
    m_180 = 0;
    if (m_30.IsNull())
        FUN_141924680();
    else
        FUN_140e77330();
}

// @0x140e77300
void UIPopupNpcTalkDialog::FUN_140e77300() { m_198.RemoveAll(); }

// MS2-FUNCTIONAL: behaviour-equivalent; the exe's MS2Ptr/script temporaries use a larger frame (0x268 vs 0x218) and the child lookups are spelled differently.
// @0x140e77330
int UIPopupNpcTalkDialog::FUN_140e77330()
{
    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(m_184);
    if (spQuest.IsNull())
        return 0;
    if (m_188.IsNull())
        return 0;
    if (m_180 >= m_188.FUN_14085a610()->m_contents.FUN_14078fae0())
        return 2;
    int nDone = FUN_140764020()->FUN_1407456d0(m_184);
    CCinematicContent* pCin = dynamic_cast<CCinematicContent*>((CScriptContent*)m_188.FUN_14085a610()->m_contents.FUN_14078f350(m_180).FUN_140e78000());
    if (pCin != 0)
        static_cast<Unk_PnRoot*>(FUN_1409ee290(&m_30))->FUN_1409b46e0("setPortrait", pCin->m_speakerIllust);
    CStringW strNpc;
    if (nDone == 0)
        strNpc = FUN_1401aa6a0(spQuest->m_2e8);
    else
        strNpc = FUN_1401aa6a0(spQuest->m_2ec);
    static_cast<Unk_PnRoot*>(FUN_1409ee290(&m_30))->FUN_140acd130("setNpc", strNpc);
    MS2Ptr<ASTextField> spScript = FUN_140bb4cf0("m_script");
    if (spScript.get() != 0)
    {
        CStringW strText = m_188.FUN_14085a610()->m_contents.FUN_14078f350(m_180).FUN_14078f3d0()->m_strText;
        FUN_1403b4750()->FUN_1416fb300(strText);
        spScript->FUN_1422c4f00(strText);
    }
    bool bLast = m_180 == m_188.FUN_14085a610()->m_contents.FUN_14078fae0() - 1;
    MS2Ptr<Unk_PnButton> spEnd = FUN_140bb4b10("m_end");
    if (spEnd.get() != 0)
    {
        if (bLast)
            spEnd->vfunc_3(0);
        else
        {
            CStringW strEnd = FUN_1405c2690(CStringW(L"s_field_quest_talk_end"), FUN_1409331f0()->FUN_14142d220(1));
            spEnd->FUN_1422cdfb0(strEnd);
            spEnd->vfunc_3(1);
        }
    }
    MS2Ptr<Unk_PnButton> spNext = FUN_140bb4b10("m_next");
    if (spNext.get() != 0)
    {
        CStringW strKey(L"s_field_quest_talk_next");
        if (bLast)
        {
            if (FUN_140764020()->FUN_1407456d0(m_184) == 0)
                strKey = L"s_field_quest_talk_ok";
            else
                strKey = L"s_field_quest_talk_complete";
        }
        CStringW strNext = FUN_1405c2690(CStringW(strKey), FUN_1409331f0()->FUN_14142d760(0x493e2, 0));
        spNext->FUN_1422cdfb0(strNext);
    }
    return 1;
}

// @0x140e77b80
int UIPopupNpcTalkDialog::FUN_140e77b80(int nQuest)
{
    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuest);
    if (spQuest.IsNull())
        return 0;
    unsigned nMap = FUN_141bd3060(FUN_1403ed2d0());
    if (FUN_140408410(&spQuest->m_fields, &nMap) == -1)
        return 0;
    return 1;
}

// @0x140e77d80
UIFameContentsNotify* FUN_140e77d80(int nType)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> ui = FUN_1403ed2b0()->FUN_141adcea0(nType);
        if (ui.get())
            return dynamic_cast<UIFameContentsNotify*>((UIObject*)ui);
    }
    return 0;
}

// @0x140e77f50
Unk_PnScriptPtr& Unk_PnScriptPtr::FUN_140e77f50(int)
{
    FUN_140790930();
    return *this;
}
