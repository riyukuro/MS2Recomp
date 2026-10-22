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
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>
#include <string.h>

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
    void FUN_140ea5f80();
private:
    char m_pad_178[0x1a0 - 0x178];
    int m_nDirty;
};
Unk_SSGDlg4e28* FUN_140938b90(int nId);

// the local player: slot 78 is the level
void* FUN_1403ed2d0();                                          // the world service
void* FUN_141bd0cc0(void* pWorld);                              // its local player
typedef unsigned short (*Unk_LgLevelFn)(void*);
#define Unk_LgActorLevel(pActor) reinterpret_cast<Unk_LgLevelFn>((*reinterpret_cast<void***>(pActor))[78])(pActor)

// listener registries
UIQuestEventDispatcher* FUN_140bfc4b0();
class Unk_LgStatusMgr { public: void FUN_141b0cd00(UIStatusEventListener*); void FUN_141b0cd90(UIStatusEventListener*); };
Unk_LgStatusMgr* FUN_140aa6d40();

// items bound to the slots of the rewards
void FUN_141415600(const CString& strBindID);
void FUN_141415450(const CString& strName, MS2Ptr<CItem> pItem, int a1, int a2, int a3);

// quests: the ids of the package quests come from the game rule table
class Unk_LvpGameRule { public: void FUN_14047c870(ATL::CAtlArray<unsigned>& rIds); };
Unk_LvpGameRule* FUN_1401c0d90();
CQuestManager* FUN_140764020();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
int FUN_14074b030(CQuestData* pData);                           // the quest id
#define LgQuestLevel(pData) ((unsigned short)(pData)->m_conditions[0]->m_target.GetFirstValue())

// strings and packets
CStringW FUN_1409e8820(CStringW strKey, const short& a1);
CString FUN_1401d9af0(const char* pszFormat, const unsigned __int64& nArg);     // StringFormat, one numeric argument
void FUN_140710590(COutPacket& packet);

// the item and its drop box
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
class Unk_PetBoxDrop
{
public:
    virtual unsigned vfunc_0();
    virtual int vfunc_1();
    virtual unsigned vfunc_2();
};
class Unk_PetBoxDropVec
{
public:
    Unk_PetBoxDropVec();                    // 0x1405a1910
    ~Unk_PetBoxDropVec();                   // 0x1405a1a40
    size_t FUN_140314170();
    Unk_PetBoxDrop* FUN_140c461b0(size_t);
    void* m_begin; void* m_end; void* m_cap;
};
MS2_CHECK_SIZE(Unk_PetBoxDropVec, 24);
class Unk_PetBoxDropTable { public: void FUN_1402ea4c0(int, Unk_PetBoxDropVec&); };
Unk_PetBoxDropTable* FUN_1405a1fd0();

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// the root of the movie
bool FUN_140a467d0(const MS2Ptr<AScript>* pAS);

// ---- UILevelUpPackageDialog ----

// @0x140ea44b0
UILevelUpPackageDialog::UILevelUpPackageDialog() : m_1a8(GetTypeName())
{
    FUN_141924170(1);
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
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}

// @0x140ea4750
void UILevelUpPackageDialog::vfunc_67()
{
    for (size_t i = 0; i < m_188.GetCount(); i++)
        FUN_141415600(m_188.GetAt(i));
    FUN_140bfc4b0()->FUN_141aa8850(this);
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    UIDialog::vfunc_67();
}

// @0x140ea4830
void UILevelUpPackageDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0) {
        FUN_140ea4d00();
        FUN_140ea4f10(FUN_140ea5d10());
    }
}

// @0x140ea4890
int UILevelUpPackageDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onReceiveItem") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            SendQuest(data.FUN_1422b8b10());
    }
    else if (_stricmp(szMethod, "onLevelSelect") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140ea4f10((unsigned short)data.FUN_1422b8a10());
    }
    return 0;
}

// @0x140ea49e0 level changed
void UILevelUpPackageDialog::vfunc_oa0_9(unsigned short nLevel)
{
    if (FUN_140a467d0(&m_30))
        return;
    LG_ROOT(m_30)->FUN_140ea5e70("setPC", nLevel);
    FUN_140ea4d00();
}

// @0x140ea4a60 a quest was updated
void UILevelUpPackageDialog::vfunc_o178_10(void* pQuestRaw)
{
    if (FUN_140a467d0(&m_30))
        return;
    CQuest* pQuest = static_cast<CQuest*>(pQuestRaw);
    MS2Ptr<CQuestData> spData = pQuest->GetData();
    if (spData->m_350.m_value == 1) {
        FUN_140ea4d00();
        if (FUN_140ea4b70() == 0) {
            vfunc_67();
            if (Unk_SSGDlg4e28* pMenu = FUN_140938b90(0x4e28))
                pMenu->FUN_140ea5f80();
        }
    }
}

// @0x140ea4b70
int UILevelUpPackageDialog::FUN_140ea4b70()
{
    ATL::CAtlArray<unsigned> ids;
    FUN_1401c0d90()->FUN_14047c870(ids);
    if (ids.GetCount() == 0)
        return 0;
    bool bAllIdle = true;
    for (size_t i = 0; i < ids.GetCount(); i++) {
        Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(ids[i]);
        if (spQuest.IsNull())
            return 0;
        if (spQuest->IsActive() != 0)
            bAllIdle = false;
    }
    if (bAllIdle)
        return 0;
    return 1;
}

// @0x140ea4d00
void UILevelUpPackageDialog::FUN_140ea4d00()
{
    if (FUN_140a467d0(&m_30))
        return;
    ATL::CAtlArray<unsigned> ids;
    FUN_1401c0d90()->FUN_14047c870(ids);
    for (size_t i = 0; i < ids.GetCount(); i++) {
        MS2Ptr<CQuestData> spData = FUN_14074bc40(ids[i]);
        if (spData == 0)
            continue;
        if (spData->m_conditions.GetCount() != 0) {
            ASObj obj(2);
            FUN_140ea5460(obj, FUN_14074b030(spData.get()));
            m_30->Invoke("addLevelGuide", obj);
        }
    }
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0)
        LG_ROOT(m_30)->FUN_140ea5e70("setPC", Unk_LgActorLevel(pPlayer));
}

// @0x140ea4f10
void UILevelUpPackageDialog::FUN_140ea4f10(unsigned short nLevel)
{
    m_1a8.FUN_140d43990();
    unsigned nItemId = FUN_140ea5b50(nLevel);
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem.get() == 0) {
        ASObj obj(2);
        obj.FUN_1407cb9c0("count", 0);
        obj.FUN_1409c0e60("text", L"");
        m_30->Invoke("setRewardSlot", obj);
    }
    else {
        int nArgs = spItem->function.parameter.FUN_1408d2380();
        if (nArgs == 0)
            return;
        nArgs = nArgs - 1;
        int nBoxId = spItem->function.parameter.FUN_1408d1fd0(nArgs, 0);
        Unk_PetBoxDropVec drops;
        FUN_1405a1fd0()->FUN_1402ea4c0(nBoxId, drops);
        ASObj obj(2);
        obj.FUN_140e846b0("count", drops.FUN_140314170());
        obj.FUN_1407cbb20("text", FUN_1409e8820(CStringW(L"s_quest_scroll_package_title"), (short&)nLevel));
        for (unsigned __int64 i = 0; i < drops.FUN_140314170(); i++) {
            CString strSlot = m_1a8.FUN_140d43510(drops.FUN_140c461b0(i));
            obj.FUN_1407cba60(FUN_1401d9af0("slot{0}", i), strSlot);
        }
        m_30->Invoke("setRewardSlot", obj);
    }
}

// @0x140ea52d0
void UILevelUpPackageDialog::SendQuest(int nQuest)
{
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuest);
    if (spQuest.IsNull())
        return;
    if (spQuest->IsComplete() == 0)
        return;
    MS2Ptr<CQuestData> spData = spQuest->GetData();
    if (spData.get() == 0)
        return;
    if (FUN_141bd0cc0(FUN_1403ed2d0()) == 0)
        return;
    COutPacket packet(0x29, 0);
    packet.vfunc_o10_1(0x1b);
    packet.vfunc_o10_3(nQuest);
    FUN_140710590(packet);
}

// @0x140ea5460
void UILevelUpPackageDialog::FUN_140ea5460(ASObj& rObj, int nQuest)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
    if (spData.get() == 0)
        return;
    if (FUN_140a467d0(&m_30))
        return;
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuest);
    CString strState;
    if (spQuest.get() != 0 && spQuest->IsComplete() != 0)
        strState = "active";
    else if (spQuest.get() != 0 && spQuest->IsRewarded() != 0)
        strState = "inactive";
    else
        strState = "lock";
    if (spData->m_conditions.GetCount() == 0)
        return;
    short nLevel = (short)LgQuestLevel(spData.get());
    CStringW strLevel = FUN_1409e8820(CStringW(L"s_recommend_contents_level"), nLevel);
    rObj.FUN_1409c0d20("id", FUN_14074b030(spData.get()));
    rObj.FUN_1407cba60("state", strState);
    rObj.FUN_1409c48f0("level", nLevel);
    rObj.FUN_1407cbb20("levelStr", strLevel);
    FUN_140ea57d0(rObj, FUN_14074b030(spData.get()));
}

// @0x140ea57d0
void UILevelUpPackageDialog::FUN_140ea57d0(ASObj& rObj, int nQuest)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
    if (spData.get() == 0)
        return;
    if (FUN_141bd0cc0(FUN_1403ed2d0()) == 0)
        return;
    CQuestData::QuestRewardItem* pReward = 0;
    for (size_t i = 0; i < spData->m_complete.m_choiceRewards.GetCount(); i++) {
        if (spData->m_complete.m_choiceRewards[i].m_itemId != 0) {
            pReward = &spData->m_complete.m_choiceRewards[i];
            break;
        }
    }
    if (pReward == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem);
    if (spItem->FUN_14052b130(pReward->m_itemId, pReward->m_count, 0) == 0)
        return;
    spItem->FUN_140526c70(pReward->m_job);
    CString strBindID;
    strBindID.Format("%s.%d", (LPCSTR)GetTypeName(), m_188.GetCount() + 1);
    FUN_141415450(strBindID, spItem, 0, 0x415, 0x800);
    rObj.FUN_1407cba60("binding", strBindID);
    m_188.Add(strBindID);
}

// @0x140ea5b50
unsigned UILevelUpPackageDialog::FUN_140ea5b50(unsigned short nLevel)
{
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0) {
        ATL::CAtlArray<unsigned> ids;
        FUN_1401c0d90()->FUN_14047c870(ids);
        for (size_t i = 0; i < ids.GetCount(); i++) {
            MS2Ptr<CQuestData> spData = FUN_14074bc40(ids[i]);
            if ((short)LgQuestLevel(spData.get()) == (short)nLevel) {
                for (size_t j = 0; j < spData->m_complete.m_choiceRewards.GetCount(); j++) {
                    if (spData->m_complete.m_choiceRewards[j].m_itemId != 0)
                        return spData->m_complete.m_choiceRewards[j].m_itemId;
                }
            }
        }
    }
    return 0;
}

// @0x140ea5d10
unsigned short UILevelUpPackageDialog::FUN_140ea5d10()
{
    unsigned short nBest = 0;
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0) {
        ATL::CAtlArray<unsigned> ids;
        FUN_1401c0d90()->FUN_14047c870(ids);
        unsigned short nPlayerLevel = Unk_LgActorLevel(pPlayer);
        for (size_t i = 0; i < ids.GetCount(); i++) {
            MS2Ptr<CQuestData> spData = FUN_14074bc40(ids[i]);
            unsigned short nQuestLevel = LgQuestLevel(spData.get());
            if (nPlayerLevel >= nQuestLevel) {
                if (nBest < nQuestLevel)
                    nBest = nQuestLevel;
            }
        }
    }
    return nBest;
}

// @0x140ea5e70
Scaleform::GFx::Value Unk_LgRoot::FUN_140ea5e70(const char* szMethod, unsigned short a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ea5f80
void Unk_SSGDlg4e28::FUN_140ea5f80() { m_nDirty = 1; }

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca7ff0-0x142ca8080 .text$yd
