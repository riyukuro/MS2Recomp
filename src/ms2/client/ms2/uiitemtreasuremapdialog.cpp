// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemTreasureMapDialog: appraise a treasure map; see
// uiitemtreasuremapdialog.h. w420.
// MS2-UNIT: ?\uiitemtreasuremapdialog.cpp
// MS2-RANGE: 0x140c54ee0-0x140c581a0 .text$mn
// MS2-RANGE: 0x1400cd9a0-0x1400cdba0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemtreasuremapdialog.cpp"    // assumed

#define MS2_ASUICOMPONENT_SLOTS   // ASTileList slot 24 (validateNow)
#include "ms2/placeholder/ms2stdafx.h"

#include "uiitemtreasuremapdialog.h"

// The first static of the unit is the AS member name of the shown item; the header statics follow it.
static CString s_strItemName = "itemName";
#include "ms2/placeholder/header_statics_a.h"
static CString s_sndStamp = "AttendGift_Stamp";
static CString s_sndChoice = "Enchant_ItemChoice";

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/astilelist.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uitalkcinematic.h"

#define MS2_ASCRIPT_INL_ASSERT(line, expression) \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\ascript.inl", (unsigned)(line)), 0))

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject {};
#include "ms2/placeholder/asbutton.h"   // C3: the button view is ASButton (was the stand-in Unk_140acd6e0)


// A dialog's position record (the maid dialog's, UI type 0x4e40).
class UITalkCinematic* FindTalkCinematic(int);   // C3: was FindTalkCinematic


// Movie helpers: set a member of the movie root to a visibility / enable flag / text.
void SetChildVisible(const Scaleform::GFx::Value& root, CString strName, int bOn);
void SetChildEnabled(const Scaleform::GFx::Value& root, CString strName, unsigned bEnable);
void SetChildHtmlText(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void SetButtonText(const Scaleform::GFx::Value& root, CString strName, CStringW strText);

void DestroyItemSlotBag(const CString& strBag);                                  // drop an item bag
void CreateItemSlotBag(const CString& strBag, int nSlots, void* pItems, MS2Ptr<CItem> (*pfnGetItem)(void*, int), int n1, int n2);   // C3: itemservice.cpp's definition (0x14141f770)
MS2Ptr<CItem> GetItemFromArray(void* pItems, int nIndex);   // C3: itemservice.cpp's definition (0x141420330)
void DestroyItemInfoSlot(const CString& strBindID);                               // release the item bound to the name
void CreateItemInfoSlot(const CString& strBindID, MS2Ptr<CItem> spItem, int n1, int n2, int n3);   // bind an item to the name
int PlaySystemSound(const CString& strName, const CString& strArg);          // play a system sound
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_140710590(COutPacket& packet);                                     // send
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
CStringW FUN_1409404f0(__int64 nValue);                                     // money text
extern __int64 DAT_143ab2898;                                               // the player's meso
extern Unk_Inventory g_143ab2a90;

#include "ms2/placeholder/gfxvalue.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/ascorelist.h"   // C3: ASCoreList::SetSelectedIndex

// ---- AScript::FUN_140c57d70 ----

// @0x140c57d70
template<class T> MS2Ptr<T> AScript::FUN_140c57d70(const CString& strName, MS2Ptr<T>& outChild)
{
    MS2_ASCRIPT_INL_ASSERT(0xd5, outChild == NULL);
    outChild = FUN_140accef0<T>(strName);
    return outChild;
}

// ---- UIItemTreasureMapDialog ----

// @0x140c54ee0
UIItemTreasureMapDialog::UIItemTreasureMapDialog()
    : m_nState(0), m_nCost(-1), m_spTarget(0)
{
    m_2c = 0xc;
    m_strBag = StringFormat<CString>("{0}.Target", GetTypeName());
    m_strBind = StringFormat<CString>("{0}.Select", GetTypeName());
    m_nTargetUid = 0;
    m_bFree = false;
    ClearChildren();
}

// @0x140c55140
UIItemTreasureMapDialog::~UIItemTreasureMapDialog()
{
}

// @0x140c55210
CString UIItemTreasureMapDialog::GetTypeName()
{
    return "ItemTreasureMapDialog";
}

// Placed beside the maid dialog's reference point when that is open, else at the origin.
// @0x140c55260
void UIItemTreasureMapDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    UITalkCinematic* pRef;
    if (pDialog != 0 && (pRef = ((class UITalkCinematic*)FindTalkCinematic(0x4e40))) != 0)
    {
        int nX = pRef->GetLowerCutGlobalY();
        int nY = pRef->GetIllustGlobalX() - 0x50;
        if (nX != -1 && nY != -1)
        {
            pDialog->vfunc_2(5, nY, (nX - pDialog->GetHeightCeil()) + 0x46);
            return;
        }
    }
    ASDialog* pDefault = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDefault != 0)
        pDefault->vfunc_2(1, 0, 0);
}

// @0x140c553a0
void UIItemTreasureMapDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140c57ce0("m_board", m_board);
    MS2Ptr<ASMovieClip> spTargetItems = GetChild<ASMovieClip>("m_targetItems");
    if (spTargetItems.get() != 0)
        spTargetItems->FUN_140c57d70("m_itemBag", m_itemBag);
    ShowSelectPage();
    if (m_itemBag.get() != 0)
        m_itemBag->AddListIndexChangeHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemTreasureMapDialog::SendTreasureMapMode2), 0);
    if (m_board.get() != 0)
    {
        m_submit = m_board->FUN_140acce30<ASButton>("m_submit");
        if (m_submit.get() != 0)
            reinterpret_cast<ASMovieClip*>(m_submit.operator->())->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemTreasureMapDialog::OnSubmitClick), (void*)0);
        CStringW strDesc = GetStringCommonByKey(L"s_item_treasure_map_appraise_desc");
        if (m_bFree != 0)
            strDesc = GetStringCommonByKey(L"s_item_treasure_map_free_appraise_desc");
        SetChildHtmlText((*m_board).FUN_1422bb890(), "m_desc", CStringW(strDesc));
    }
}

// @0x140c558a0
void UIItemTreasureMapDialog::vfunc_67()
{
    DestroyItemSlotBag(m_strBag);
    DestroyItemInfoSlot(m_strBind);
    m_nState = 0;
    m_spTarget = 0;
    m_items.RemoveAll();
    ClearChildren();
    m_nTargetUid = 0;
    m_bFree = false;
    UIDialog::vfunc_67();
}

// @0x140c55950
int UIItemTreasureMapDialog::vfunc_13()
{
    return 0;
}

// The server's packets (0xf5): sub 2 = the cost of the picked map, sub 3 = the appraised item / the end of the appraise.
// @0x140c55960
void UIItemTreasureMapDialog::vfunc_79(void* p)
{
#define TM_PKT static_cast<CInPacket*>(p)
    UIDialog::vfunc_79(p);
    if (TM_PKT->GetOpcode() == 0xf5)
    {
        if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0)
            return;
        int nSub = TM_PKT->ReadUInt8();
        if (nSub == 2)
        {
            __int64 nUid = TM_PKT->ReadInt64();
            __int64 nCost = TM_PKT->ReadInt64();
            OnAppraiseCost(nUid, nCost);
        }
        else if (nSub == 3)
        {
            bool bOk = TM_PKT->ReadBool();
            if (bOk)
            {
                int nItemId = TM_PKT->ReadInt32();
                int nRank = TM_PKT->ReadInt32();
                ShowAppraisedItem(nItemId, nRank);
            }
            else
            {
                m_nState = 2;
                ReturnToSelectPage();
            }
        }
    }
#undef TM_PKT
}

// The "free" parameter of the dialog.
// @0x140c55b50
void UIItemTreasureMapDialog::FUN_140c55b50(const CString& strParam)
{
    if (strParam.CompareNoCase("free") == 0)
        m_bFree = true;
    else
        m_bFree = false;
}

// The item bag was clicked: select the map.
// @0x140c55ba0
void UIItemTreasureMapDialog::SendTreasureMapMode2(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_itemBag == 0)
        return;
    if (m_nState != 0)
        return;
    size_t nIndex = m_itemBag->GetSelectedIndex();
    if (nIndex < 0 || nIndex >= (int)m_items.GetCount())
        return;
    MS2Ptr<CItem> spItem = m_items.GetAt(nIndex);
    if (spItem == 0)
        return;
    __int64 nUid = spItem->GetItemUid();
    COutPacket pkt(static_cast<int>(SendOp::TreasureMap), 0);
    pkt.WriteUInt8(2);
    pkt.WriteInt64(nUid);
    pkt.WriteBool(m_bFree);
    FUN_140710590(pkt);
}

// The m_submit button.
// @0x140c55d20
void UIItemTreasureMapDialog::OnSubmitClick(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_nState == 1)
        return;
    if (m_nState == 0)
        StartAppraise();
    else if (m_nState == 2)
    {
        ReturnToSelectPage();
        if (m_nTargetUid > 0)
        {
            MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(m_nTargetUid);
            if (spItem.get() != 0)
            {
                if ((unsigned int)spItem->vfunc_4() > 0)
                {
                    COutPacket pkt(static_cast<int>(SendOp::TreasureMap), 0);
                    pkt.WriteUInt8(2);
                    pkt.WriteInt64(m_nTargetUid);
                    pkt.WriteBool(m_bFree);
                    FUN_140710590(pkt);
                }
            }
            m_nTargetUid = 0;
        }
    }
}

// The select page: no map picked, the submit button asks for an appraise.
// @0x140c55ea0
void UIItemTreasureMapDialog::ShowSelectPage()
{
    if (m_board == 0)
        return;
    m_nCost = 0;
    RefreshTreasureMapBag();
    SetButtonText((*m_board).FUN_1422bb890(), "m_submit", GetStringCommonByKey(L"s_item_treasure_map_button_appraise"));
    SetChildEnabled((*m_board).FUN_1422bb890(), "m_submit", 0);
    SetChildVisible((*m_board).FUN_1422bb890(), "m_desc1", 0);
    SetChildVisible((*m_board).FUN_1422bb890(), "m_desc2", 0);
}

// Collects the treasure maps of the inventory and hands them to the item bag.
// @0x140c560f0
void UIItemTreasureMapDialog::RefreshTreasureMapBag()
{
    m_items.RemoveAll();
    ATL::CAtlArray<unsigned __int64> uids;
    g_143ab2a90.GetItemUidsInCategory(7, uids);
    for (unsigned i = 0; i < uids.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(uids[i]);
        if (spItem == 0)
            continue;
        if (!IsTreasureMap(MS2Ptr<CItem>(spItem)))
            continue;
        m_items.Add(spItem);
    }
    DestroyItemSlotBag(m_strBag);
    MS2Ptr<CItem> (*pfnGetItem)(void*, int) = GetItemFromArray;
    CreateItemSlotBag(m_strBag, (unsigned)m_items.GetCount(), (void*)&m_items, pfnGetItem, 0x415, 8);
    if (m_itemBag.get() != 0)
    {
        m_itemBag->SetSelectedIndex(-1);
        m_itemBag->FUN_1422dd1d0();
        m_itemBag->SetStringMember("bagId", m_strBag);
        m_itemBag->vfunc_24(true);
    }
}

// Start the appraise of the picked map.
// @0x140c563d0
void UIItemTreasureMapDialog::StartAppraise()
{
    if (m_nState != 0)
        return;
    if (m_spTarget == 0)
        return;
    if (m_board == 0)
        return;
    if (DAT_143ab2898 < m_nCost)
        FUN_141275260(0x34, 1, 1);
    else
    {
        CStringW strArg;
        if (m_bFree != 0)
            strArg = L"free";
        if (g_143ab2a90.FUN_140a63880(m_spTarget.get(), strArg) == 0)
            return;
        m_nState = 1;
        m_nTargetUid = m_spTarget->GetItemUid();
        m_spTarget = 0;
        SetChildVisible((*m_board).FUN_1422bb890(), "m_desc1", 0);
        SetChildVisible((*m_board).FUN_1422bb890(), "m_desc2", 0);
        SetChildEnabled((*m_board).FUN_1422bb890(), "m_submit", 0);
    }
}

// Back to the select page.
// @0x140c56670
void UIItemTreasureMapDialog::ReturnToSelectPage()
{
    if (m_nState != 2)
        return;
    if (m_board == 0)
        return;
    m_nState = 0;
    m_spTarget = 0;
    DestroyItemInfoSlot(m_strBind);
    MS2Ptr<ASUIComponent> spSlot = m_board->FUN_140accfb0<ASUIComponent>("m_slot");
    if (spSlot.get() != 0)
    {
        ASObj obj(2);
        obj.SetStringMember("binding", m_strBind);
        spSlot->Invoke("setData", obj.GetValue());
        SetChildVisible((*spSlot).FUN_1422bb890(), "eff1", 1);
        SetChildVisible((*spSlot).FUN_1422bb890(), "eff2", 1);
    }
    m_board->vfunc_13("wait");
    SetChildVisible((*m_board).FUN_1422bb890(), "m_desc1", 0);
    SetChildVisible((*m_board).FUN_1422bb890(), "m_desc2", 0);
    ShowSelectPage();
}

// The server's cost of the picked map: show the map and the cost.
// @0x140c56a50
void UIItemTreasureMapDialog::OnAppraiseCost(__int64 nUid, __int64 nCost)
{
    if (m_nState != 0)
        return;
    if (m_board == 0)
        return;
    m_nCost = nCost;
    MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(nUid);
    if (spItem == 0)
        return;
    if (IsTreasureMap(MS2Ptr<CItem>(spItem)) == 0)
        return;
    m_spTarget = spItem;
    DestroyItemInfoSlot(m_strBind);
    CreateItemInfoSlot(m_strBind, MS2Ptr<CItem>(m_spTarget), 0, 0x415, 8);
    MS2Ptr<ASUIComponent> spSlot = m_board->FUN_140accfb0<ASUIComponent>("m_slot");
    if (spSlot.get() != 0)
    {
        ASObj obj(2);
        obj.SetWStringMember((const char*)s_strItemName, m_spTarget->FUN_140528160());
        obj.SetStringMember("binding", m_strBind);
        spSlot->Invoke("setData", obj.GetValue());
        SetChildVisible((*spSlot).FUN_1422bb890(), "eff1", 1);
        SetChildVisible((*spSlot).FUN_1422bb890(), "eff2", 1);
    }
    CStringW strCost = FUN_14028dfa0<CStringW>(CStringW(L"s_item_treasure_map_appraise_cost"), FUN_1409404f0(m_nCost));
    if (nCost < 0)
    {
        strCost = GetStringCommonByKey(L"s_item_treasure_map_cant_appraise");
        SetChildEnabled((*m_board).FUN_1422bb890(), "m_submit", 0);
    }
    else
        SetChildEnabled((*m_board).FUN_1422bb890(), "m_submit", 1);
    SetChildVisible((*m_board).FUN_1422bb890(), "m_desc1", 1);
    SetChildHtmlText((*m_board).FUN_1422bb890(), "m_desc1", m_spTarget->FUN_140528160());
    SetChildVisible((*m_board).FUN_1422bb890(), "m_desc2", 1);
    SetChildHtmlText((*m_board).FUN_1422bb890(), "m_desc2", CStringW(strCost));
    PlaySystemSound(s_sndChoice, "");
}

// The appraised item: show it and the back button.
// @0x140c57300
void UIItemTreasureMapDialog::ShowAppraisedItem(int nItemId, int nRank)
{
    if (m_board == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(nItemId, nRank, 0) != 0)
    {
        DestroyItemInfoSlot(m_strBind);
        CreateItemInfoSlot(m_strBind, MS2Ptr<CItem>(spItem), 0, 0x415, 0x800);
        MS2Ptr<ASUIComponent> spSlot = m_board->FUN_140accfb0<ASUIComponent>("m_slot");
        if (spSlot.get() != 0)
        {
            ASObj obj(2);
            obj.SetWStringMember((const char*)s_strItemName, spItem->FUN_140528160());
            obj.SetStringMember("binding", m_strBind);
            spSlot->Invoke("setData", obj.GetValue());
            SetChildVisible((*spSlot).FUN_1422bb890(), "eff1", 0);
            SetChildVisible((*spSlot).FUN_1422bb890(), "eff2", 0);
        }
    }
    m_board->vfunc_13("appraise");
    MS2Ptr<ASMovieClip> spEff = m_board->FUN_1409b4560("m_eff1");
    if (spEff.get() != 0)
        spEff->vfunc_12(1);
    SetChildVisible((*m_board).FUN_1422bb890(), "m_desc1", 1);
    SetChildHtmlText((*m_board).FUN_1422bb890(), "m_desc1", spItem->FUN_140528160());
    SetChildEnabled((*m_board).FUN_1422bb890(), "m_submit", 1);
    SetButtonText((*m_board).FUN_1422bb890(), "m_submit", GetStringCommonByKey(L"s_item_treasure_map_button_back"));
    PlaySystemSound(s_sndStamp, "");
    RefreshTreasureMapBag();
    m_nState = 2;
}

// Is the item a treasure map?
// @0x140c57a70
bool UIItemTreasureMapDialog::IsTreasureMap(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return false;
    if (spItem->GetData() == 0)
        return false;
    if (reinterpret_cast<CItemData*>(spItem->GetData())->function.name != L"TreasureMap")
        return false;
    return true;
}

// @0x140c57b50
void UIItemTreasureMapDialog::ClearChildren()
{
    m_board = 0;
    m_submit = 0;
    m_itemBag = 0;
}

// @0x140c57ce0
MS2Ptr<ASMovieClip> UIItemTreasureMapDialog::FUN_140c57ce0(const CString& strName, MS2Ptr<ASMovieClip>& out)
{
    out = GetChild<ASMovieClip>(strName);
    return out;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca2f10-0x142ca3000 .text$yd
