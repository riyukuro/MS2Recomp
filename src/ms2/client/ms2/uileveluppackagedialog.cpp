// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UILevelUpPackageDialog (the level-up package window). See
// uileveluppackagedialog.h. w406.
// MS2-UNIT: ?\uileveluppackagedialog.cpp
// MS2-RANGE: 0x140ea44b0-0x140ea60c0 .text$mn
// MS2-RANGE: 0x1400dbc00-0x1400dbd70 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uileveluppackagedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uileveluppackagedialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>
#include <string.h>
#include "ms2/commonfiles/itemdroptable.h"   // C3: TSingleton<> needs the class
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/commonfiles/gamerule.h"

// ---- unit-local views of exe types ----

// The movie root: Invoke("setPC", level) (defined by this unit).
class Unk_LgRoot : public AScript
{
public:
    Scaleform::GFx::Value FUN_140ea5e70(const char* szMethod, unsigned short a1);
};
#define LG_ROOT(p) static_cast<Unk_LgRoot*>((p).operator->())

// The game menu dialog (UI type 0x4e28): the dirty flag at +0x1a0 (defined by this unit).
class Unk_SSGDlg4e28 : public UIDialog
{
public:
    void MarkDirty();
private:
    char m_pad_178[0x1a0 - 0x178];
    int m_nDirty;
};
class UIGameMenuDialog* FindGameMenuDialog(int);   // C3: was FindGameMenuDialog

// the local player (PCBase; vfunc_78 is the level)
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* GetLocalPlayer();
    static class WorldService* GetInstance();
};

// listener registries
UIQuestEventDispatcher* GetQuestEventDispatcher();
class UIStatusEventDispatcher;

// items bound to the slots of the rewards
void DestroyItemInfoSlot(const CString& strBindID);
void CreateItemInfoSlot(const CString& strName, MS2Ptr<CItem> pItem, int a1, int a2, int a3);

// quests: the ids of the package quests come from the game rule table
void* GetGameRule();
void* FUN_140764020();   // C3: was FUN_140764020
MS2Ptr<CQuestData> GetQuestData(int nQuestId);
int FUN_14074b030(CQuestData* pData);                           // the quest id
#define LgQuestLevel(pData) ((unsigned short)(pData)->m_conditions[0]->m_target.GetFirstValue())

// strings and packets
void FUN_140710590(COutPacket& packet);

// the item and its drop box
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// the root of the movie

// ---- UILevelUpPackageDialog ----

// @0x140ea44b0
UILevelUpPackageDialog::UILevelUpPackageDialog() : m_1a8(GetTypeName())
{
    SetTweenEnabled(1);
}

// @0x140ea45b0
UILevelUpPackageDialog::~UILevelUpPackageDialog() {}

// @0x140ea4660
CString UILevelUpPackageDialog::GetTypeName() { return "LevelUpPackageDialog"; }

// @0x140ea46b0
int UILevelUpPackageDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    GetQuestEventDispatcher()->AddListener(this);
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}

// @0x140ea4750
void UILevelUpPackageDialog::vfunc_67()
{
    for (size_t i = 0; i < m_188.GetCount(); i++)
        DestroyItemInfoSlot(m_188.GetAt(i));
    GetQuestEventDispatcher()->RemoveListener(this);
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    UIDialog::vfunc_67();
}

// @0x140ea4830
void UILevelUpPackageDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    void* pPlayer = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (pPlayer == 0)
        return;
    FUN_140ea4d00();
    FUN_140ea4f10(FUN_140ea5d10());
}

// @0x140ea4890
int UILevelUpPackageDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onReceiveItem") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nItemId = data.PopUInt();
            SendQuest(nItemId);
        }
    }
    else if (_stricmp(szMethod, "onLevelSelect") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned short nLevel = (unsigned short)data.PopInt();
            FUN_140ea4f10(nLevel);
        }
    }
    return 0;
}

// @0x140ea49e0 level changed
void UILevelUpPackageDialog::vfunc_oa0_9(unsigned short nLevel)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    LG_ROOT(m_30)->FUN_140ea5e70("setPC", nLevel);
    FUN_140ea4d00();
}

// @0x140ea4a60 a quest was updated
void UILevelUpPackageDialog::vfunc_o178_10(void* pQuestRaw)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    MS2Ptr<CQuestData> spData = static_cast<CQuest*>(pQuestRaw)->GetData();
    if (spData->m_350.m_value != 1)
        return;
    FUN_140ea4d00();
    if (HasOpenPackageQuest() == 0) {
        vfunc_67();
        if (Unk_SSGDlg4e28* pMenu = ((class Unk_SSGDlg4e28*)FindGameMenuDialog(0x4e28)))
            pMenu->MarkDirty();
    }
}

// @0x140ea4b70
int UILevelUpPackageDialog::HasOpenPackageQuest()
{
    ATL::CAtlArray<unsigned> ids;
    ((CGameRule*)GetGameRule())->GetLevelUpPackageIds(ids);
    if (ids.GetCount() == 0)
        return 0;
    BOOL bAllIdle = TRUE;
    for (size_t i = 0; i < ids.GetCount(); i++) {
        MS2Ptr<CQuest> spQuest = ((class CQuestManager*)FUN_140764020())->vfunc_o10_3(ids[i]);
        if (spQuest.IsNull())
            return 0;
        if (spQuest->IsActive() != 0)
            bAllIdle = FALSE;
    }
    if (bAllIdle)
        return 0;
    return 1;
}

// @0x140ea4d00
void UILevelUpPackageDialog::FUN_140ea4d00()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    ATL::CAtlArray<unsigned> ids;
    ((CGameRule*)GetGameRule())->GetLevelUpPackageIds(ids);
    for (size_t i = 0; i < ids.GetCount(); i++) {
        MS2Ptr<CQuestData> spData = GetQuestData(ids[i]);
        if (spData == 0)
            continue;
        if (spData->m_conditions.GetCount() > 0) {
            ASObj obj(2);
            FUN_140ea5460(obj, FUN_14074b030(spData.get()));
            m_30->Invoke("addLevelGuide", obj);
        }
    }
    PCBase* pPlayer = (PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (pPlayer == 0)
        return;
    LG_ROOT(m_30)->FUN_140ea5e70("setPC", pPlayer->vfunc_78());
}

// @0x140ea4f10
void UILevelUpPackageDialog::FUN_140ea4f10(unsigned short nLevel)
{
    m_1a8.FUN_140d43990();
    unsigned nItemId = GetRewardItemId(nLevel);
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem.get() != 0) {
        unsigned nArgs = spItem->function.parameter.GetArgCount();
        if (nArgs < 1)
            return;
        int nBoxId = spItem->function.parameter.FUN_1408d1fd0(nArgs - 1, 0);
        std::vector<ItemDropResult> drops;
        TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nBoxId, drops);
        ASObj obj(2);
        obj.FUN_140e846b0("count", drops.size());
        obj.SetWStringMember("text", FUN_14028dfa0<unsigned short>(CStringW(L"s_quest_scroll_package_title"), reinterpret_cast<const unsigned short&>(nLevel)));
        for (unsigned __int64 i = 0; i < drops.size(); i++) {
            CString strSlot = m_1a8.FUN_140d43510(static_cast<ItemAble*>(&drops[i]));
            obj.SetStringMember(StringFormat<unsigned __int64>("slot{0}", i), strSlot);
        }
        m_30->Invoke("setRewardSlot", obj);
    }
    else {
        ASObj obj(2);
        obj.SetIntMember("count", 0);
        obj.FUN_1409c0e60("text", L"");
        m_30->Invoke("setRewardSlot", obj);
    }
}

// @0x140ea52d0
void UILevelUpPackageDialog::SendQuest(int nQuest)
{
    MS2Ptr<CQuest> spQuest = ((class CQuestManager*)FUN_140764020())->vfunc_o10_3(nQuest);
    if (spQuest.IsNull())
        return;
    if (spQuest->IsComplete() == 0)
        return;
    MS2Ptr<CQuestData> spData = spQuest->GetData();
    if (!spData)
        return;
    void* pPlayer = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (pPlayer == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Quest), 0);
    packet.WriteUInt8(0x1b);
    packet.WriteInt32(nQuest);
    FUN_140710590(packet);
}

// @0x140ea5460
void UILevelUpPackageDialog::FUN_140ea5460(ASObj& rObj, int nQuest)
{
    MS2Ptr<CQuestData> spData = GetQuestData(nQuest);
    if (!spData)
        return;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    MS2Ptr<CQuest> spQuest = ((class CQuestManager*)FUN_140764020())->vfunc_o10_3(nQuest);
    CString strState;
    if ((bool)spQuest.get() && spQuest->IsComplete() != 0)
        strState = "active";
    else if ((bool)spQuest.get() && spQuest->IsRewarded() != 0)
        strState = "inactive";
    else
        strState = "lock";
    if (spData->m_conditions.GetCount() == 0)
        return;
    short nLevel = (short)LgQuestLevel(spData.get());
    CStringW strLevel = FUN_14028dfa0<unsigned short>(CStringW(L"s_recommend_contents_level"), reinterpret_cast<const unsigned short&>(nLevel));
    rObj.SetMemberUInt("id", FUN_14074b030(spData.get()));
    rObj.SetStringMember("state", strState);
    rObj.FUN_1409c48f0("level", nLevel);
    rObj.SetWStringMember("levelStr", strLevel);
    FUN_140ea57d0(rObj, FUN_14074b030(spData.get()));
}

// @0x140ea57d0
void UILevelUpPackageDialog::FUN_140ea57d0(ASObj& rObj, int nQuest)
{
    MS2Ptr<CQuestData> spData = GetQuestData(nQuest);
    if (!spData)
        return;
    void* pPlayer = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (pPlayer == 0)
        return;
    CQuestData::QuestRewardItem* pReward = 0;
    for (size_t i = 0; i < spData->m_complete.m_choiceRewards.GetCount(); i++) {
        const CQuestData::QuestRewardItem& reward = spData->m_complete.m_choiceRewards[i];
        if (reward.m_itemId != 0) {
            pReward = &spData->m_complete.m_choiceRewards[i];
            break;
        }
    }
    if (pReward == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem);
    if (spItem->FUN_14052b130(pReward->m_itemId, pReward->m_count, 0) == 0)
        return;
    spItem->SetCountClamped(pReward->m_job);
    int nSlotFlags = 0x415;
    CString strBindID;
    strBindID.Format("%s.%d", (LPCSTR)GetTypeName(), m_188.GetCount() + 1);
    CreateItemInfoSlot(strBindID, spItem, 0, nSlotFlags, 0x800);
    rObj.SetStringMember("binding", strBindID);
    m_188.Add(strBindID);
}

// @0x140ea5b50
unsigned UILevelUpPackageDialog::GetRewardItemId(unsigned short nLevel)
{
    void* pPlayer = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (pPlayer == 0)
        return 0;
    ATL::CAtlArray<unsigned> ids;
    ((CGameRule*)GetGameRule())->GetLevelUpPackageIds(ids);
    for (size_t i = 0; i < ids.GetCount(); i++) {
        MS2Ptr<CQuestData> spData = GetQuestData(ids[i]);
        unsigned short nQuestLevel = LgQuestLevel(spData.get());
        if (nQuestLevel == nLevel) {
            for (size_t j = 0; j < spData->m_complete.m_choiceRewards.GetCount(); j++) {
                const auto& reward = spData->m_complete.m_choiceRewards[j];
                if (reward.m_itemId != 0)
                    return reward.m_itemId;
            }
        }
    }
    return 0;
}

// @0x140ea5d10
unsigned short UILevelUpPackageDialog::FUN_140ea5d10()
{
    PCBase* pPlayer = (PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (pPlayer == 0)
        return 0;
    ATL::CAtlArray<unsigned> ids;
    ((CGameRule*)GetGameRule())->GetLevelUpPackageIds(ids);
    unsigned short nPlayerLevel = pPlayer->vfunc_78();
    unsigned short nBest = 0;
    for (size_t i = 0; i < ids.GetCount(); i++) {
        MS2Ptr<CQuestData> spData = GetQuestData(ids[i]);
        unsigned short nQuestLevel = LgQuestLevel(spData.get());
        if (nPlayerLevel < nQuestLevel)
            continue;
        if (nQuestLevel > nBest)
            nBest = nQuestLevel;
    }
    return nBest;
}

// @0x140ea5e70
Scaleform::GFx::Value Unk_LgRoot::FUN_140ea5e70(const char* szMethod, unsigned short a1)
{
    ASArgList args;
    args.resize(1);
    FUN_1422bccb0(&args[0], a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ea5f80
void Unk_SSGDlg4e28::MarkDirty() { m_nDirty = 1; }

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca7ff0-0x142ca8080 .text$yd
