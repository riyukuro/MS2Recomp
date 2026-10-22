// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemTreasureMapDialog: appraise a treasure map; see
// uiitemtreasuremapdialog.h. w420.
// MS2-UNIT: ?\uiitemtreasuremapdialog.cpp
// MS2-RANGE: 0x140c54ee0-0x140c581a0 .text$mn
// MS2-RANGE: 0x1400cd9a0-0x1400cdba0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemtreasuremapdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiitemtreasuremapdialog.h"

// The first static of the unit is the AS member name of the shown item; the header statics follow it.
static CString s_strItemName = "itemName";
#include "ms2/placeholder/header_statics_a.h"
static CString s_sndStamp = "AttendGift_Stamp";
static CString s_sndChoice = "Enchant_ItemChoice";

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
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

#define MS2_ASCRIPT_INL_ASSERT(line, expression) \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\ascript.inl", (unsigned)(line)), 0))

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject {};
class Unk_140acd6e0 : public ASDisplayObject {};                            // the button wrapper

// The item list control of the movie.
class Unk_TmBag : public ASMovieClip
{
public:
    Unk_TmBag(const Scaleform::GFx::Value& v, int nMovieId);                // 0x1422cf330
#define TM_V(n) virtual void vfunc_##n();
    TM_V(16) TM_V(17) TM_V(18) TM_V(19) TM_V(20) TM_V(21) TM_V(22) TM_V(23)
#undef TM_V
    virtual void vfunc_24(int bRefresh);                                    // 24 (+0xc0) refresh
    void FUN_1407cba60(const char* szName, CString str);                    // set the bag id
    void FUN_1422dcca0(int nIndex);                                         // select an entry (-1: none)
    int FUN_1422dccd0();                                                    // the selected entry
    void FUN_1422dd1d0();                                                   // clear
    void FUN_1422dce60(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onClick, int n);   // set the select handler
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_TmBag, 0x88);

// A dialog's position record (the maid dialog's, UI type 0x4e40).
class Unk_TmRefPos { public: int FUN_141b1d3d0(); int FUN_141b1d460(); };
Unk_TmRefPos* FUN_140a7b2b0(int nId);

bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);                      // has the AS object been released

// Movie helpers: set a member of the movie root to a visibility / enable flag / text.
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int bOn);
void FUN_140cff950(const Scaleform::GFx::Value& root, CString strName, int bEnable);
void FUN_140cff1b0(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void FUN_140cff4e0(const Scaleform::GFx::Value& root, CString strName, CStringW strText);

CString FUN_140540050(const char* szFormat, const CString& strArg);         // StringFormat with one string
void FUN_14141f970(const CString& strBag);                                  // drop an item bag
void FUN_14141f770(const CString& strBag, unsigned int nCount, const ATL::CAtlArray<MS2Ptr<CItem> >& items,
                   MS2Ptr<CItem>(*pfnGetItem)(const ATL::CAtlArray<MS2Ptr<CItem> >&, int), int n1, int n2);
MS2Ptr<CItem> FUN_141420330(const ATL::CAtlArray<MS2Ptr<CItem> >& items, int nIndex);
void FUN_141415600(const CString& strBindID);                               // release the item bound to the name
void FUN_141415450(const CString& strBindID, MS2Ptr<CItem> spItem, int n1, int n2, int n3);   // bind an item to the name
void FUN_141276180(const CString& strName, const CString& strArg);          // play a system sound
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_140710590(COutPacket& packet);                                     // send
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
CStringW FUN_1409404f0(__int64 nValue);                                     // money text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
extern __int64 DAT_143ab2898;                                               // the player's meso
extern Unk_Inventory DAT_143ab2a90;

#include "ms2/placeholder/gfxvalue.h"

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
    m_strBag = FUN_140540050("{0}.Target", GetTypeName());
    m_strBind = FUN_140540050("{0}.Select", GetTypeName());
    m_nTargetUid = 0;
    m_bFree = false;
    FUN_140c57b50();
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
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    Unk_TmRefPos* pRef;
    if (pDialog != 0 && (pRef = FUN_140a7b2b0(0x4e40)) != 0)
    {
        int nX = pRef->FUN_141b1d3d0();
        int nY = pRef->FUN_141b1d460();
        if (nX != -1 && nY - 0x50 != -1)
        {
            pDialog->vfunc_2(5, nY - 0x50, (nX - pDialog->FUN_1422c13b0()) + 0x46);
            return;
        }
    }
    pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(1, 0, 0);
}

// @0x140c553a0
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140c57ce0("m_board", m_board);
    MS2Ptr<ASMovieClip> spTargetItems = FUN_140ba7930("m_targetItems");
    if (spTargetItems.get() != 0)
        spTargetItems->FUN_140c57d70("m_itemBag", m_itemBag);
    FUN_140c55ea0();
    if (m_itemBag.get() != 0)
        m_itemBag->FUN_1422dce60(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemTreasureMapDialog::SendTreasureMapMode2), 0);
    if (m_board.get() != 0)
    {
        m_submit = m_board->FUN_140acce30<Unk_140acd6e0>("m_submit");
        if (m_submit.get() != 0)
            m_submit->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemTreasureMapDialog::FUN_140c55d20), 0);
        CStringW strDesc = GetStringCommonByKey(CStringW(L"s_item_treasure_map_appraise_desc"));
        if (m_bFree != 0)
            strDesc = GetStringCommonByKey(CStringW(L"s_item_treasure_map_free_appraise_desc"));
        FUN_140cff1b0((*m_board).FUN_1422bb890(), "m_desc", CStringW(strDesc));
    }
}

// @0x140c558a0
void UIItemTreasureMapDialog::vfunc_67()
{
    FUN_14141f970(m_strBag);
    FUN_141415600(m_strBind);
    m_nState = 0;
    m_spTarget = 0;
    m_items.RemoveAll();
    FUN_140c57b50();
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
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::vfunc_79(void* p)
{
#define TM_PKT static_cast<CInPacket*>(p)
    UIDialog::vfunc_79(p);
    if (TM_PKT->FUN_14070fe80() == 0xf5 && FUN_140ba28d0(&m_30, 0) == 0)
    {
        unsigned char nSub = TM_PKT->vfunc_o8_1();
        if (nSub == 2)
        {
            __int64 nUid = TM_PKT->vfunc_o8_4();
            __int64 nCost = TM_PKT->vfunc_o8_4();
            FUN_140c56a50(nUid, nCost);
        }
        else if (nSub == 3)
        {
            if (TM_PKT->vfunc_o8_0() == false)
            {
                m_nState = 2;
                FUN_140c56670();
            }
            else
            {
                int nItemId = TM_PKT->vfunc_o8_3();
                int nRank = TM_PKT->vfunc_o8_3();
                FUN_140c57300(nItemId, nRank);
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
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::SendTreasureMapMode2(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (!(m_itemBag == 0) && m_nState == 0)
    {
        int nIndex = m_itemBag->FUN_1422dccd0();
        int nCount = (int)m_items.GetCount();
        if ((unsigned __int64)(__int64)nIndex < (unsigned __int64)(__int64)nCount)
        {
            MS2Ptr<CItem> spItem = m_items.GetAt(nIndex);
            if (!(spItem == 0))
            {
                __int64 nUid = spItem->FUN_140526a50();
                COutPacket pkt(0x9f, 0);
                pkt.vfunc_o10_1(2);
                pkt.vfunc_o10_4(nUid);
                pkt.vfunc_o10_0(m_bFree);
                FUN_140710590(pkt);
            }
        }
    }
}

// The m_submit button.
// @0x140c55d20
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::FUN_140c55d20(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_nState != 1)
    {
        if (m_nState == 0)
            FUN_140c563d0();
        else if (m_nState == 2)
        {
            FUN_140c56670();
            if (m_nTargetUid != 0)
            {
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nTargetUid);
                if (spItem.get() != 0)
                {
                    if (spItem->vfunc_4() != 0)
                    {
                        COutPacket pkt(0x9f, 0);
                        pkt.vfunc_o10_1(2);
                        pkt.vfunc_o10_4(m_nTargetUid);
                        pkt.vfunc_o10_0(m_bFree);
                        FUN_140710590(pkt);
                    }
                }
                m_nTargetUid = 0;
            }
        }
    }
}

// The select page: no map picked, the submit button asks for an appraise.
// @0x140c55ea0
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::FUN_140c55ea0()
{
    if (!(m_board == 0))
    {
        m_nCost = 0;
        FUN_140c560f0();
        FUN_140cff4e0((*m_board).FUN_1422bb890(), "m_submit", GetStringCommonByKey(CStringW(L"s_item_treasure_map_button_appraise")));
        FUN_140cff950((*m_board).FUN_1422bb890(), "m_submit", 0);
        FUN_140cff840((*m_board).FUN_1422bb890(), "m_desc1", 0);
        FUN_140cff840((*m_board).FUN_1422bb890(), "m_desc2", 0);
    }
}

// Collects the treasure maps of the inventory and hands them to the item bag.
// @0x140c560f0
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::FUN_140c560f0()
{
    m_items.RemoveAll();
    ATL::CAtlArray<unsigned __int64> uids;
    DAT_143ab2a90.FUN_140a609a0(7, uids);
    for (unsigned i = 0; i < uids.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(uids[i]);
        if (!(spItem == 0))
        {
            if (FUN_140c57a70(MS2Ptr<CItem>(spItem)) != 0)
                m_items.Add(spItem);
        }
    }
    FUN_14141f970(m_strBag);
    MS2Ptr<CItem> (*pfnGetItem)(const ATL::CAtlArray<MS2Ptr<CItem> >&, int) = FUN_141420330;
    FUN_14141f770(m_strBag, (unsigned)m_items.GetCount(), m_items, pfnGetItem, 0x415, 8);
    if (m_itemBag.get() != 0)
    {
        m_itemBag->FUN_1422dcca0(-1);
        m_itemBag->FUN_1422dd1d0();
        m_itemBag->FUN_1407cba60("bagId", m_strBag);
        m_itemBag->vfunc_24(1);
    }
}

// Start the appraise of the picked map.
// @0x140c563d0
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::FUN_140c563d0()
{
    if (m_nState == 0 && !(m_spTarget == 0) && !(m_board == 0))
    {
        if (DAT_143ab2898 < m_nCost)
            FUN_141275260(0x34, 1, 1);
        else
        {
            CStringW strArg;
            if (m_bFree != 0)
                strArg = L"free";
            if (DAT_143ab2a90.FUN_140a63880(m_spTarget.get(), strArg) != 0)
            {
                m_nState = 1;
                m_nTargetUid = m_spTarget->FUN_140526a50();
                m_spTarget = 0;
                FUN_140cff840((*m_board).FUN_1422bb890(), "m_desc1", 0);
                FUN_140cff840((*m_board).FUN_1422bb890(), "m_desc2", 0);
                FUN_140cff950((*m_board).FUN_1422bb890(), "m_submit", 0);
            }
        }
    }
}

// Back to the select page.
// @0x140c56670
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::FUN_140c56670()
{
    if (m_nState == 2 && !(m_board == 0))
    {
        m_nState = 0;
        m_spTarget = 0;
        FUN_141415600(m_strBind);
        MS2Ptr<ASUIComponent> spSlot = m_board->FUN_140accfb0<ASUIComponent>("m_slot");
        if (spSlot.get() != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cba60("binding", m_strBind);
            spSlot->Invoke("setData", obj.FUN_1422bb870());
            FUN_140cff840((*spSlot).FUN_1422bb890(), "eff1", 1);
            FUN_140cff840((*spSlot).FUN_1422bb890(), "eff2", 1);
        }
        m_board->vfunc_13("wait");
        FUN_140cff840((*m_board).FUN_1422bb890(), "m_desc1", 0);
        FUN_140cff840((*m_board).FUN_1422bb890(), "m_desc2", 0);
        FUN_140c55ea0();
    }
}

// The server's cost of the picked map: show the map and the cost.
// @0x140c56a50
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::FUN_140c56a50(__int64 nUid, __int64 nCost)
{
    if (m_nState == 0 && !(m_board == 0))
    {
        m_nCost = nCost;
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (!(spItem == 0))
        {
            if (FUN_140c57a70(MS2Ptr<CItem>(spItem)) != 0)
            {
                m_spTarget = spItem;
                FUN_141415600(m_strBind);
                FUN_141415450(m_strBind, MS2Ptr<CItem>(m_spTarget), 0, 0x415, 8);
                MS2Ptr<ASUIComponent> spSlot = m_board->FUN_140accfb0<ASUIComponent>("m_slot");
                if (spSlot.get() != 0)
                {
                    ASObj obj(2);
                    obj.FUN_1407cbb20((const char*)s_strItemName, m_spTarget->FUN_140528160());
                    obj.FUN_1407cba60("binding", m_strBind);
                    spSlot->Invoke("setData", obj.FUN_1422bb870());
                    FUN_140cff840((*spSlot).FUN_1422bb890(), "eff1", 1);
                    FUN_140cff840((*spSlot).FUN_1422bb890(), "eff2", 1);
                }
                CStringW strCost = FUN_1405c2690(CStringW(L"s_item_treasure_map_appraise_cost"), FUN_1409404f0(m_nCost));
                if (nCost < 0)
                {
                    strCost = GetStringCommonByKey(CStringW(L"s_item_treasure_map_cant_appraise"));
                    FUN_140cff950((*m_board).FUN_1422bb890(), "m_submit", 0);
                }
                else
                    FUN_140cff950((*m_board).FUN_1422bb890(), "m_submit", 1);
                FUN_140cff840((*m_board).FUN_1422bb890(), "m_desc1", 1);
                FUN_140cff1b0((*m_board).FUN_1422bb890(), "m_desc1", m_spTarget->FUN_140528160());
                FUN_140cff840((*m_board).FUN_1422bb890(), "m_desc2", 1);
                FUN_140cff1b0((*m_board).FUN_1422bb890(), "m_desc2", CStringW(strCost));
                FUN_141276180(s_sndChoice, CString(""));
            }
        }
    }
}

// The appraised item: show it and the back button.
// @0x140c57300
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
void UIItemTreasureMapDialog::FUN_140c57300(int nItemId, int nRank)
{
    if (!(m_board == 0))
    {
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(nItemId, nRank, 0) != 0)
        {
            FUN_141415600(m_strBind);
            FUN_141415450(m_strBind, MS2Ptr<CItem>(spItem), 0, 0x415, 0x800);
            MS2Ptr<ASUIComponent> spSlot = m_board->FUN_140accfb0<ASUIComponent>("m_slot");
            if (spSlot.get() != 0)
            {
                ASObj obj(2);
                obj.FUN_1407cbb20((const char*)s_strItemName, spItem->FUN_140528160());
                obj.FUN_1407cba60("binding", m_strBind);
                spSlot->Invoke("setData", obj.FUN_1422bb870());
                FUN_140cff840((*spSlot).FUN_1422bb890(), "eff1", 0);
                FUN_140cff840((*spSlot).FUN_1422bb890(), "eff2", 0);
            }
        }
        m_board->vfunc_13("appraise");
        MS2Ptr<ASMovieClip> spEff = m_board->FUN_1409b4560("m_eff1");
        if (spEff.get() != 0)
            spEff->vfunc_12(1);
        FUN_140cff840((*m_board).FUN_1422bb890(), "m_desc1", 1);
        FUN_140cff1b0((*m_board).FUN_1422bb890(), "m_desc1", spItem->FUN_140528160());
        FUN_140cff950((*m_board).FUN_1422bb890(), "m_submit", 1);
        FUN_140cff4e0((*m_board).FUN_1422bb890(), "m_submit", GetStringCommonByKey(CStringW(L"s_item_treasure_map_button_back")));
        FUN_141276180(s_sndStamp, CString(""));
        FUN_140c560f0();
        m_nState = 2;
    }
}

// Is the item a treasure map?
// @0x140c57a70
// MS2-FUNCTIONAL: frame slot order / MS2Ptr temporaries differ from the exe
bool UIItemTreasureMapDialog::FUN_140c57a70(MS2Ptr<CItem> spItem)
{
    if (!(spItem == 0))
    {
        if (spItem->FUN_140527840() == 0)
            return false;
        CItemData* pData = reinterpret_cast<CItemData*>(spItem->FUN_140527840());
        if (pData->function.name != L"TreasureMap")
            return false;
        return true;
    }
    return false;
}

// @0x140c57b50
void UIItemTreasureMapDialog::FUN_140c57b50()
{
    m_board = 0;
    m_submit = 0;
    m_itemBag = 0;
}

// @0x140c57ce0
MS2Ptr<ASMovieClip> UIItemTreasureMapDialog::FUN_140c57ce0(const CString& strName, MS2Ptr<ASMovieClip>& out)
{
    out = FUN_140ba7930(strName);
    return out;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca2f10-0x142ca3000 .text$yd
