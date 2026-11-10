// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPopupNpcTalkDialog: see uipopupnpctalkdialog.h.
// MS2-UNIT: ?\uipopupnpctalkdialog.cpp
// MS2-RANGE: 0x140e76460-0x140e78150 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??4?$Unk_ScriptPtr@VCTalkScript@@@@QEAAAEAV0@H@Z 0x140e77f50 ; unique
// MS2-PINS-END tplpin
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
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include <stdlib.h>
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422cdfb0

template <> MS2Ptr<ASButton> UISwfEntity::GetChild<ASButton>(const CString& strName);   // 0x140bb4b10, owned by uiinventorydialog

MS2_EMIT_CRT_MEMMOVE_S();

// ---- out-of-unit callees (names describe uses) ----
struct Unk_PnContentPtr
{
    void* FUN_140e78000() const { return m_p; }                 // 0x140e78000 the raw pointer (this unit)
    void* m_00;
    void* m_p;
};
typedef ATL::CAtlArray<Unk_TalkContentPtr<CScriptContent>> Unk_PnContentArray;
class Unk_PnTalkScript                                         // CTalkScript (talkscript.h; its scriptcontent.h clashes with cinematiccontent.h)
{
public:
    char m_pad[0x68];
    Unk_PnContentArray m_contents;                              // +0x68
};
class Unk_PnWorld { public: void* FUN_141bd0cc0(); };
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class Unk_PnUIMgr { public: };
void* FUN_140764020();   // C3: was FUN_140764020
MS2Ptr<CQuestData> GetQuestData(int nQuestId);
Unk_ScriptPtr<CTalkScript> FindQuestTalk(int nQuestId, int n);
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
UIQuestEventDispatcher* FUN_140bfc4b0();
CStringW FUN_1401aa6a0(int nId);                                // npc name
class Unk_PnRoot : public AScript {};
class Unk_PnActor { public: void vfunc_4(int, int, int); };
UIFameContentsNotify* FindFameContentsNotify(int nType);
void FUN_140710590(COutPacket& rPacket);
int FUN_1418dd0d0();
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>& rArray, const T& value);   // index of the value (-1 when absent, 0x140408410)

// @0x140e76460
UIPopupNpcTalkDialog::UIPopupNpcTalkDialog()
{
    SetTweenEnabled(1);
    m_180 = 0;
    m_188 = 0;
    m_184 = 0;
    FUN_140bfc4b0()->AddListener(this);
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UIPopupNpcTalkDialog::FUN_140e770a0));
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UIPopupNpcTalkDialog::FUN_140e771b0));
}

// @0x140e76770
UIPopupNpcTalkDialog::~UIPopupNpcTalkDialog()
{
    FUN_140bfc4b0()->RemoveListener(this);
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UIPopupNpcTalkDialog::FUN_140e770a0));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UIPopupNpcTalkDialog::FUN_140e771b0));
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
    m_188 = 0;
}

// @0x140e76ab0
void UIPopupNpcTalkDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (ShowCurrentLine() == 0)
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
        int nState = ShowCurrentLine();
        if (nState != 1)
        {
            if (nState == 2)
            {
                if (((class CQuestManager*)FUN_140764020())->IsQuestComplete(m_184) != 0)
                {
                    COutPacket packet(static_cast<int>(SendOp::Quest), 0);
                    packet.Encode1(4);
                    packet.Encode4(m_184);
                    packet.Encode4(0);
                    packet.Encode4(0);
                    FUN_140710590(packet);
                }
                else
                {
                    UIFameContentsNotify* pFame = FindFameContentsNotify(0x4f5a);
                    if (pFame != 0)
                        pFame->QueueOpeningBanner(m_184);
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
    if (FUN_140e77b80(((CQuest*)pQuest)->GetQuestId()) == 0)
        return;
    StartQuestTalk(((CQuest*)pQuest)->GetQuestId());
}

// @0x140e76d50
void UIPopupNpcTalkDialog::vfunc_o178_3(void* pQuest)
{
    if (pQuest == 0)
        return;
    if (((CQuest*)pQuest)->FUN_140d738d0() == 0)
        return;
    StartQuestTalk(((CQuest*)pQuest)->GetQuestId());
}

// @0x140e76db0
void UIPopupNpcTalkDialog::vfunc_43()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(((MS2Ptr<AScript>*)(&m_30))->operator->()));
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
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d840())
    {
        if (((class CQuestManager*)FUN_140764020())->IsQuestComplete(m_184) == 0)
        {
            UIFameContentsNotify* pFame = FindFameContentsNotify(0x4f5a);
            if (pFame != 0)
                pFame->QueueOpeningBanner(m_184);
        }
        vfunc_69();
    }
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x493e2, 0, 0))
    {
        m_180++;
        int nState = ShowCurrentLine();
        if (nState != 1 && nState == 2)
        {
            if (((class CQuestManager*)FUN_140764020())->IsQuestComplete(m_184) != 0)
            {
                COutPacket packet(static_cast<int>(SendOp::Quest), 0);
                packet.Encode1(4);
                packet.Encode4(m_184);
                packet.Encode4(0);
                packet.Encode4(0);
                FUN_140710590(packet);
            }
            else
            {
                UIFameContentsNotify* pFame = FindFameContentsNotify(0x4f5a);
                if (pFame != 0)
                    pFame->QueueOpeningBanner(m_184);
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
    TSingleton<QuestDataTable>::GetInstance()->FUN_14074d360(((class WorldService*)(class Unk_PnWorld*)(reinterpret_cast<Unk_PnWorld*>(WorldService::GetInstance())))->FUN_141bd3060(), quests);
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        unsigned nQuest = quests[i];
        if (((class CQuestManager*)FUN_140764020())->IsQuestActive(nQuest) == 0)
            continue;
        if (m_198.Lookup(nQuest) != 0)
            continue;
        m_198.SetAt(nQuest, 1);
        StartQuestTalk(nQuest);
        break;
    }
}

// @0x140e771b0
void UIPopupNpcTalkDialog::FUN_140e771b0(NotifyObject*) { ClearOpenedQuests(); }

// @0x140e771e0
void UIPopupNpcTalkDialog::StartQuestTalk(int nQuest)
{
    if (!((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0x95))
        return;
    int nStep = 0;
    if (((class CQuestManager*)FUN_140764020())->IsQuestComplete(nQuest) != 0)
        nStep = 300;
    else
        nStep = 100;
    m_188 = FindQuestTalk(nQuest, nStep);
    if (m_188.IsNull())
        return;
    m_184 = nQuest;
    m_180 = 0;
    if (m_30.IsNull())
        FUN_141924680();
    else
        ShowCurrentLine();
}

// @0x140e77300
void UIPopupNpcTalkDialog::ClearOpenedQuests() { m_198.RemoveAll(); }

// @0x140e77330
int UIPopupNpcTalkDialog::ShowCurrentLine()
{
    MS2Ptr<CQuestData> spQuest = GetQuestData(m_184);
    if (spQuest.IsNull())
        return 0;
    if (m_188.IsNull())
        return 0;
    if (m_180 >= (int)((Unk_PnTalkScript*)m_188.operator->())->m_contents.GetCount())
        return 2;
    int nDone = ((class CQuestManager*)FUN_140764020())->IsQuestComplete(m_184);
    CCinematicContent* pCin = dynamic_cast<CCinematicContent*>((CScriptContent*)reinterpret_cast<const Unk_PnContentPtr&>(((Unk_PnTalkScript*)m_188.operator->())->m_contents[m_180]).FUN_140e78000());
    if (pCin != 0)
        static_cast<Unk_PnRoot*>(((MS2Ptr<AScript>*)(&m_30))->operator->())->Invoke("setPortrait", pCin->m_speakerIllust);
    CStringW strNpc;
    if (nDone != 0)
        strNpc = FUN_1401aa6a0(spQuest->m_2ec);
    else
        strNpc = FUN_1401aa6a0(spQuest->m_2e8);
    static_cast<Unk_PnRoot*>(((MS2Ptr<AScript>*)(&m_30))->operator->())->Invoke("setNpc", strNpc);
    if (MS2Ptr<ASTextField> spScript = GetChild<ASTextField>("m_script"))
    {
        CStringW strText = ((Unk_PnTalkScript*)m_188.operator->())->m_contents[m_180]->m_name;
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectAndValueWords(strText);
        spScript->SetTextHTMLW(strText);
    }
    BOOL bLast = m_180 == (int)(((Unk_PnTalkScript*)m_188.operator->())->m_contents.GetCount() - 1);
    if (MS2Ptr<ASButton> spEnd = GetChild<ASButton>("m_end"))
    {
        if (!bLast)
        {
            CStringW strEnd = FUN_14028dfa0<CStringW>(L"s_field_quest_talk_end", TSingleton<CKeyTable>::GetInstance()->GetKeyName(1));
            spEnd->FUN_1422cdfb0(strEnd);
            spEnd->vfunc_3(1);
        }
        else
            spEnd->vfunc_3(0);
    }
    if (MS2Ptr<ASButton> spNext = GetChild<ASButton>("m_next"))
    {
        CStringW strKey(L"s_field_quest_talk_next");
        if (bLast)
        {
            if (((class CQuestManager*)FUN_140764020())->IsQuestComplete(m_184) != 0)
                strKey = L"s_field_quest_talk_complete";
            else
                strKey = L"s_field_quest_talk_ok";
        }
        CStringW strNext = FUN_14028dfa0<CStringW>(strKey, TSingleton<CKeyTable>::GetInstance()->GetActionKeyName(0x493e2, 0));
        spNext->FUN_1422cdfb0(strNext);
    }
    return 1;
}

// @0x140e77b80
int UIPopupNpcTalkDialog::FUN_140e77b80(int nQuest)
{
    MS2Ptr<CQuestData> spQuest = GetQuestData(nQuest);
    if (spQuest.IsNull())
        return 0;
    unsigned nMap = ((class WorldService*)(class Unk_PnWorld*)(reinterpret_cast<Unk_PnWorld*>(WorldService::GetInstance())))->FUN_141bd3060();
    if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(spQuest->m_fields), reinterpret_cast<const int&>(nMap)) == -1)
        return 0;
    return 1;
}

// @0x140e77d80
UIFameContentsNotify* FindFameContentsNotify(int nType)
{
    if (reinterpret_cast<Unk_PnUIMgr*>(TSingleton<CUIService>::GetInstance()))
    {
        MS2Ptr<UIObject> ui = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nType);
        if (ui.get())
            return dynamic_cast<UIFameContentsNotify*>((UIObject*)ui);
    }
    return 0;
}

