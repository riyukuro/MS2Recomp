// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The collect-item-group event window
// (UICollectItemGroupEventDialog, "CollectItemGroupEventDialog"). See uicollectitemgroupeventdialog.h.
// No __FILE__ in the range: the unit name is guessed (alphabetical between uiclosetdialog and uicommunitypopup; the TU
// follows uiclosetdialog.cpp after a mid-range memmove_s and repeats the shared header statics).
// MS2-UNIT: ?\uicollectitemgroupeventdialog.cpp
// MS2-RANGE: 0x140be6eb0-0x140be99c0 .text$mn
// MS2-RANGE: 0x1400cae10-0x1400cb070 .text$di
// MS2-RANGE: 0x142ca1d60-0x142ca1e40 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicollectitemgroupeventdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uicollectitemgroupeventdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cserverstring.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/inventoryitemkey.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/commonfiles/gameeventuservalue.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics of the unit's headers (the same set uiclosetdialog.cpp and its neighbours repeat) ----

static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strSortTypeNamesLike2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of unrecovered callees ----

// The item event source the dialog listens to (a TSingleton; see uiitemeventlistener.h).
class Unk_CigItemEvents;
Unk_CigItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_CigItemEvents*, UIItemEventListener*);              // add a listener
void FUN_1419caeb0(Unk_CigItemEvents*, UIItemEventListener*);              // remove it

// The game event hub: handlers per user value type.
class Unk_CigEventHub
{
public:
    void FUN_140da5430(int nType, Delegate<void(GameEventVariable*)> handler);   // register
    void FUN_140da5490(int nType, Delegate<void(GameEventVariable*)> handler);   // unregister
};
Unk_CigEventHub* FUN_140933220();

// The condition panel clip: its "m_slot" item slot child (COMDAT of uibingoeventdialog.cpp).
class Unk_CigClip : public ASMovieClip
{
public:
    MS2Ptr<ASItemSlot> FUN_140bb4ba0(const CString& strName);
};

// The worn equipment of the player (PC::FUN_1416561a0) and the worn gems (PC::FUN_14165f460).
struct Unk_CigEquipSet : public Unk_PCEquipSet
{
    int FUN_1411e0c30(int nItemId);                                         // 1: an item with this id is worn
};
class Unk_MyPCEquip : public PCGemEquip {};

void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int nVisible);   // show/hide a named child
void* FUN_140bb9630(int n);                                                // int -> delegate user data
int FUN_140bb9640(void* p);                                                // delegate user data -> int
CStringW FUN_140b8e910(const CMsTime& time);                               // the date text of a time
CStringW FUN_1409eaa20(CStringW strKey, const CStringW& a1, const CStringW& a2, const CStringW& a3);   // formatted string table text
bool FUN_1407105c0(COutPacket* packet, int key, int delay);                // send (rate limited)
__int64 FUN_140718320(const CStringW& value);                              // _wtoi64
void FUN_140429690(Unk_GameEventLockedValue<0x40>* pValue, std::vector<MS2Ptr<CollectItemGroupContext> >& contexts);   // CGameEventValueCollectItemGroup::GetAll
extern Unk_Inventory DAT_143ab2a90;

// @0x140be9030
template <> inline __int64 GameEventVariable::GetValue<__int64>(const __int64& nDefault)
{
    CMsTime now(GetServerTime());
    if (m_time <= now)
        return nDefault;
    return FUN_140718320(m_value);
}

// @0x140be6eb0
UICollectItemGroupEventDialog::UICollectItemGroupEventDialog()
{
    FUN_141924170(1);
    m_selected = -1;
}

// @0x140be6fe0
UICollectItemGroupEventDialog::~UICollectItemGroupEventDialog()
{
}

// @0x140be70e0
CString UICollectItemGroupEventDialog::vfunc_1()
{
    return "CollectItemGroupEventDialog";
}
MS2_REPLACE_METHOD(0x140BE70E0, UICollectItemGroupEventDialog, vfunc_1, 61, 0x8B9212AF);

// @0x140be7130
void UICollectItemGroupEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_closeButton");
    FUN_141925fa0("m_dragBar");
    m_selected = -1;
    for (int i = 0; i < 3; ++i)
    {
        CString strName = StringFormat("m_eventButton{0}", i);
        m_eventButtons[i] = GetChild<ASButton>(strName);
        m_eventButtons[i]->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UICollectItemGroupEventDialog::OnEventButton), FUN_140bb9630(i));
    }
    m_conditionItem = GetChild<ASMovieClip>("m_conditionItem");
    m_rewardPanel = GetChild<ASMovieClip>("m_rewardPanel");
    m_recieveItemButton = GetChild<ASButton>("m_recieveItemButton");
    m_recieveItemButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UICollectItemGroupEventDialog::OnReceive), 0);
    m_conditionItem->vfunc_4(false);
    RefreshEvents();
    SelectEvent(0);
    FUN_140933220()->FUN_140da5430(0x898, Delegate<void(GameEventVariable*)>(this, &UICollectItemGroupEventDialog::OnGameEvent));
    FUN_1419cae20(FUN_140a6a840(), this);
}
MS2_REPLACE_METHOD(0x140BE7130, UICollectItemGroupEventDialog, OnLoadComplete, 1413, 0xAF19A091);

// @0x140be76c0
void UICollectItemGroupEventDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_contexts.clear();
    m_slots.clear();
    for (int i = 0; i < 3; ++i)
        m_eventButtons[i] = 0;
    m_conditionItem = 0;
    m_rewardPanel = 0;
    m_recieveItemButton = 0;
    FUN_1419caeb0(FUN_140a6a840(), this);
    FUN_140933220()->FUN_140da5490(0x898, Delegate<void(GameEventVariable*)>(this, &UICollectItemGroupEventDialog::OnGameEvent));
}
MS2_REPLACE_METHOD(0x140BE76C0, UICollectItemGroupEventDialog, vfunc_26, 410, 0x0B19841C);

// @0x140be7860
void UICollectItemGroupEventDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140BE7860, UICollectItemGroupEventDialog, vfunc_67, 24, 0xE28CF352);

// @0x140be7880
void UICollectItemGroupEventDialog::RefreshEvents()
{
    m_contexts.clear();
    FUN_140429690(CGameEventValueManager::GetInstance()->GetCollectItemGroup(), m_contexts);
    for (size_t i = 0; i < 3; ++i)
    {
        if (m_contexts.size() > i)
        {
            MS2Ptr<CollectItemGroupContext> spContext = m_contexts[i];
            if (spContext == 0)
                continue;
            CMsTime beginTime(spContext->m_beginTime);
            CMsTime endTime(spContext->m_endTime);
            CStringW strBegin = FUN_140b8e910(beginTime);
            CStringW strEnd = FUN_140b8e910(endTime);
            CStringW strName = CServerString::GetInstance()->GetGameEvent()->GetString(spContext->m_name);
            m_eventButtons[i]->vfunc_4(true);
            m_eventButtons[i]->FUN_1422cdfb0(FUN_1409eaa20(L"s_attendGift_title_name", strBegin, strEnd, strName));
        }
        else
        {
            m_eventButtons[i]->vfunc_4(false);
        }
    }
}
MS2_REPLACE_METHOD(0x140BE7880, UICollectItemGroupEventDialog, RefreshEvents, 723, 0xDEBA9AE8);

// @0x140be7b60
void UICollectItemGroupEventDialog::Refresh()
{
    if (m_conditionItem == 0)
        return;
    if (m_selected >= (int)m_contexts.size())
        return;
    m_conditionItem->vfunc_4(false);
    MS2Ptr<CollectItemGroupContext> spContext = m_contexts[m_selected];
    if (spContext == 0)
        return;
    m_slots.clear();
    HideItemPanels();
    __int64 nReceived = g_gameEventUserValue.GetValue(0x898, spContext->m_eventId, (__int64)0);
    bool bReceived = nReceived > 0;
    size_t nCount = spContext->m_conditions.size();
    if (nCount > 5 || nCount < 2)
        return;
    CString strPanel = StringFormat("item_panel{0}", nCount);
    MS2Ptr<ASMovieClip> spPanel = m_conditionItem->FUN_1409b4560(strPanel);
    if (spPanel == 0)
        return;
    m_conditionItem->vfunc_4(true);
    spPanel->vfunc_4(true);
    for (size_t i = 0; i < nCount; ++i)
    {
        ItemEntity& item = spContext->m_conditions[i];
        bool bHave = HasItem(item.vfunc_o18_0(), item.vfunc_o18_1(), item.vfunc_o18_2());
        CString strName = StringFormat("m_slotMovie{0}", i);
        MS2Ptr<ASMovieClip> spSlotMovie = spPanel->FUN_1409b4560(strName);
        if (spSlotMovie == 0)
            continue;
        if (bHave && !bReceived)
            spSlotMovie->vfunc_15("checking");
        else
            spSlotMovie->vfunc_15("normal");
        FUN_140cff840((*spSlotMovie).FUN_1422bb890(), "m_recivedMovie", bReceived);
        MS2Ptr<ASItemSlot> spSlot = static_cast<Unk_CigClip*>(spSlotMovie.operator->())->FUN_140bb4ba0("m_slot");
        if (spSlot == 0)
            continue;
        m_slots.push_back(spSlot);
        spSlot->FUN_1409ba5d0(item.vfunc_o18_0(), item.vfunc_o18_1(), item.vfunc_o18_2());
    }
    MS2Ptr<ASItemSlot> spReward = static_cast<Unk_CigClip*>(m_rewardPanel.operator->())->FUN_140bb4ba0("m_slot");
    if (spReward.get() != 0)
    {
        m_slots.push_back(spReward);
        spReward->FUN_1409ba5d0(spContext->m_result.vfunc_o18_0(), spContext->m_result.vfunc_o18_1(), spContext->m_result.vfunc_o18_2());
    }
    bool bComplete = IsComplete(m_selected);
    if (bComplete && !bReceived)
        m_rewardPanel->vfunc_15("checking");
    else
        m_rewardPanel->vfunc_15("normal");
    FUN_140cff840((*m_rewardPanel).FUN_1422bb890(), "m_recivedMovie", bReceived);
    bool bEnable = bComplete && !bReceived;
    MS2Ptr<ASMovieClip> spEffect = m_rewardPanel->FUN_1409b4560("m_effect");
    if (spEffect.get() != 0)
        spEffect->vfunc_4(bEnable);
    m_recieveItemButton->FUN_1422c1fe0(bEnable);
}
MS2_REPLACE_METHOD(0x140BE7B60, UICollectItemGroupEventDialog, Refresh, 2683, 0xE0B5572C);

// @0x140be85f0
void UICollectItemGroupEventDialog::SelectEvent(int nIndex)
{
    if (nIndex >= (int)m_contexts.size())
        return;
    m_selected = nIndex;
    for (int i = 0; i < 3; ++i)
    {
        bool bSelected = m_selected == i ? TRUE : FALSE;
        m_eventButtons[i]->FUN_1422ce090(bSelected);
    }
    Refresh();
}
MS2_REPLACE_METHOD(0x140BE85F0, UICollectItemGroupEventDialog, SelectEvent, 196, 0xC43F2BD9);

// @0x140be86c0
bool UICollectItemGroupEventDialog::HasItem(int nItemId, int nRarity, int nCount)
{
    Unk_InventoryItemKey key;
    key.m_id = nItemId;
    key.m_rarity = nRarity;
    int nHave = DAT_143ab2a90.FUN_140a5eda0(&key.m_id);
    if (nHave < nCount)
    {
        bool bWorn = false;
        if (nCount == 1)
        {
            PC* pPlayer = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
            if (pPlayer != 0)
            {
                if (static_cast<Unk_CigEquipSet*>(pPlayer->FUN_1416561a0())->FUN_1411e0c30(nItemId) == 1 || pPlayer->FUN_14165f460()->FUN_141270290(nItemId) == true)
                    bWorn = true;
            }
        }
        if (!bWorn)
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140BE86C0, UICollectItemGroupEventDialog, HasItem, 200, 0xAC1797EA);

// @0x140be8790
bool UICollectItemGroupEventDialog::IsComplete(int nIndex)
{
    if (nIndex >= (int)m_contexts.size())
        return false;
    MS2Ptr<CollectItemGroupContext> spContext = m_contexts[nIndex];
    if (spContext == 0)
        return false;
    std::map<std::pair<unsigned, int>, unsigned>::iterator it = spContext->m_conditionKeys.begin();
    std::map<std::pair<unsigned, int>, unsigned>::iterator itEnd = spContext->m_conditionKeys.end();
    for (; it != itEnd; ++it)
    {
        unsigned nItemId = it->first.first;
        int nRarity = it->first.second;
        unsigned nAmount = it->second;
        if (!HasItem(nItemId, nRarity, nAmount))
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140BE8790, UICollectItemGroupEventDialog, IsComplete, 358, 0xB53B2675);

// @0x140be8900
void UICollectItemGroupEventDialog::HideItemPanels()
{
    if (m_conditionItem == 0)
        return;
    for (int i = 2; i <= 5; ++i)
    {
        CString strName = StringFormat("item_panel{0}", i);
        FUN_140cff840((*m_conditionItem).FUN_1422bb890(), strName, 0);
    }
}
MS2_REPLACE_METHOD(0x140BE8900, UICollectItemGroupEventDialog, HideItemPanels, 208, 0xDAA951E0);

// @0x140be89e0
void UICollectItemGroupEventDialog::vfunc_2(void* pItem)
{
    if (m_30 == 0)
        return;
    Refresh();
}
MS2_REPLACE_METHOD_VIA(0x140BE89E0, UICollectItemGroupEventDialog, UIItemEventListener, vfunc_2, 68, 0xA312622A);

// @0x140be8a30
void UICollectItemGroupEventDialog::vfunc_3(void* pItem, bool bRemoved)
{
    if (m_30 == 0)
        return;
    Refresh();
}
MS2_REPLACE_METHOD_VIA(0x140BE8A30, UICollectItemGroupEventDialog, UIItemEventListener, vfunc_3, 73, 0x5ED2CDB1);

// @0x140be8a80
void UICollectItemGroupEventDialog::vfunc_4(void* pItem, int n)
{
    if (m_30 == 0)
        return;
    Refresh();
}
MS2_REPLACE_METHOD_VIA(0x140BE8A80, UICollectItemGroupEventDialog, UIItemEventListener, vfunc_4, 73, 0x7C5F2C40);

// @0x140be8ad0
void UICollectItemGroupEventDialog::vfunc_30(void* pItem)
{
    if (m_30 == 0)
        return;
    Refresh();
}
MS2_REPLACE_METHOD_VIA(0x140BE8AD0, UICollectItemGroupEventDialog, UIItemEventListener, vfunc_30, 68, 0xF06D45E4);

// @0x140be8b20
void UICollectItemGroupEventDialog::OnGameEvent(GameEventVariable* pVariable)
{
    if (m_30 == 0)
        return;
    Refresh();
}
MS2_REPLACE_METHOD(0x140BE8B20, UICollectItemGroupEventDialog, OnGameEvent, 57, 0xB1F75E52);

// @0x140be8b60
void UICollectItemGroupEventDialog::OnEventButton(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nIndex = FUN_140bb9640(params.pUserData);
    SelectEvent(nIndex);
}
MS2_REPLACE_METHOD(0x140BE8B60, UICollectItemGroupEventDialog, OnEventButton, 51, 0xAEF86B47);

// @0x140be8ba0
void UICollectItemGroupEventDialog::OnReceive(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_selected >= (int)m_contexts.size())
        return;
    MS2Ptr<CollectItemGroupContext> spContext = m_contexts[m_selected];
    if (spContext == 0)
        return;
    if (!IsComplete(m_selected))
        return;
    COutPacket packet(0x97, 0);
    packet.Encode1(0x13);
    packet.Encode4(spContext->m_eventId);
    FUN_1407105c0(&packet, 0x13, 1000);
}
MS2_REPLACE_METHOD(0x140BE8BA0, UICollectItemGroupEventDialog, OnReceive, 300, 0x13C24159);
