// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISelectItemBoxDialog: see uiselectitemboxdialog.h.
// MS2-UNIT: ?\uiselectitemboxdialog.cpp
// MS2-RANGE: 0x140f99280-0x140f9b9c0 .text$mn
// MS2-RANGE: 0x1400e13b0-0x1400e1660 .text$di
// MS2-PIN: ??$FUN_14028dfa0@_KI@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEB_KAEBI@Z 0x140f9ae60
// MS2-PIN: ?clear@?$vector@VItemDropResult@@V?$allocator@VItemDropResult@@@std@@@std@@QEAAXXZ 0x140f9b7d0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiselectitemboxdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uiselectitemboxdialog.h"

#include <algorithm>
#include <vector>

#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/usercommandcli.h"
#include "ms2/placeholder/cxmldata.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/asmultiselecttilecachelist.h"
#include "ms2/placeholder/asdisplayobject.h"

#include "ms2/placeholder/header_statics_a.h"
// The statics of this TU after the shared header's: the sort names of a second header, skill/stun, then an anonymous
// handle static at 0x143acbc50.
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); void* m_p; };     // ctor 0x1401cd100 (C3: the name other units use)
static Unk_BuddyHandle s_dat_143acbc50(NULL);                                       // @0x1400e1640
class UISelectSuperWorldChatDialog { public: MS2Ptr<ASMultiSelectTileCacheList> FUN_140e8d030(const CString& strName, MS2Ptr<ASMultiSelectTileCacheList>& out); };   // C3: the tile-list binder (0x140e8d030, uisidepopuptalk_2.cpp)
#include "ms2/placeholder/asevent.h"   // C3: ASListEvent (dtor 0x140f83bb0)
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/bigdatalogsystem.h"
#include "ms2/placeholder/fittingdollpc.h"
// C3: Unk_140acd6e0 (the button view) is ASButton itself.
class UICashAttendDialog { public: template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out); };   // C3: the child binder (0x140bc6d10, uicashattenddialog.cpp)
class UIItemTreasureMapDialog { public: MS2Ptr<ASMovieClip> FUN_140c57ce0(const CString& strName, MS2Ptr<ASMovieClip>& out); };   // bind a child

// ---- unit-local placeholders (unrecovered helpers) ----

// The list event handed to the change handler (ctor 0x1422e2740, dtor 0x140f83bb0) and the row's button wrapper
// (ctor 0x1422cdde0 shared with tabcontentspetevolution.cpp, dtor 0x1422cde30).
// The clicked row is an ASButton (asbutton.h, 0x88; ctor 0x1422cdde0, FUN_1422ce090 sets "selected").

// The item record's properties (+0x320) and argument table (+0x2b0).
class Unk_SibProps { };                    // a CXmlData
class Unk_SibArgs { };                     // an ItemFunctionArgs
class Unk_SibItemData
{
public:
    char m_pad_0[0x2b0];
    Unk_SibArgs m_args;                     // +0x2b0
    char m_pad_2b1[0x320 - 0x2b0 - 1];
    Unk_SibProps m_props;                   // +0x320
};

// The player's item inventory (global object) and the callbacks.
extern Unk_Inventory g_143ab2a90;

// The drop query is the 0x38-byte ItemDropContext (itemdroptable.h, ctor 0x1402e9180).

class Unk_SibPlayer : public PC { };               // the local player
class Unk_SibPlayers { public: Unk_SibPlayer* FUN_141bd0cc0(); };
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    static class WorldService* GetInstance();
};


// string-table text with arguments (the shared FUN_14028dfa0 back end and its instances)
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_14028dfa0(const CStringW& strKey, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
void FUN_1412752d0(const CStringW& strMessage, int n);                  // pop a notice
int FUN_141276180(const CString& strCommand, const CString& strArg);
CString FUN_140b62550(unsigned nIndex);                                 // the index text
CString FUN_14016a600(const wchar_t* psz, int n);                       // wide -> narrow
void OpenItemBoxContents(CItem* pItem, CStringW strArgs);               // unit_140d1ae30 @0x140d1d3f0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140f99280
UISelectItemBoxDialog::UISelectItemBoxDialog()
    : m_uItemUid(0)
    , m_nSelectCount(0)
    , m_binder("SelectItemBoxDialog")
    , m_binderSel("SelectItemBoxDialog_Sel")
{
    FUN_141924170(1);
    FUN_140d432d0(&m_binder, 0x411);
    FUN_140d432d0(&m_binderSel, 0x411);
}

// @0x140f99420
UISelectItemBoxDialog::~UISelectItemBoxDialog()
{
}

// @0x140f99500
CString UISelectItemBoxDialog::GetTypeName()
{
    return "SelectItemBoxDialog";
}

// @0x140f99550
void UISelectItemBoxDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_close");
    MS2Ptr<CItem> item = g_143ab2a90.FUN_140a5d680(m_uItemUid);
    if (item == 0)
        return;
    {
        ASButton* ok = reinterpret_cast<ASButton*>(reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<ASButton>("m_okButton", reinterpret_cast<MS2Ptr<ASButton>&>(m_okButton)).get());
        if (ok != 0) {
            m_okButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UISelectItemBoxDialog::FUN_140f9a230), (void*)0);
        }
    }
    {
        ASMultiSelectTileCacheList* list = reinterpret_cast<UISelectSuperWorldChatDialog*>(this)->FUN_140e8d030("m_selectItemList", m_selectItemList).get();
        if (list != 0) {
            reinterpret_cast<ASCoreList*>(m_selectItemList.operator->())->FUN_1422de0e0(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UISelectItemBoxDialog::FUN_140f9a5f0), (void*)0);
        }
    }
    m_selectedSlots.clear();
    m_selectedSlots.resize(6);
    for (unsigned i = 0; i < 6; ++i)
        reinterpret_cast<UIItemTreasureMapDialog*>(this)->FUN_140c57ce0(StringFormat("m_selectedSlot{0}", i), reinterpret_cast<MS2Ptr<ASMovieClip>&>(m_selectedSlots[i]));
    FUN_140e48d80("m_selectedCount", &m_selectedCount);
    FUN_140e48d80("m_selectNotice", &m_selectNotice);
    int nDropBoxId = 0;
    if (((class CXmlData*)&(reinterpret_cast<Unk_SibItemData*>(item->FUN_140527840())->m_props))->FUN_14092c5c0()) {
        m_nSelectCount = reinterpret_cast<ItemFunctionArgs*>(&reinterpret_cast<Unk_SibItemData*>(item->FUN_140527840())->m_args)->FUN_1408d1fd0(0, 0);
        nDropBoxId = reinterpret_cast<ItemFunctionArgs*>(&reinterpret_cast<Unk_SibItemData*>(item->FUN_140527840())->m_args)->FUN_1408d1fd0(1, 0);
    } else {
        int nDefault = 0;
        m_nSelectCount = reinterpret_cast<CXmlData*>(&reinterpret_cast<Unk_SibItemData*>(item->FUN_140527840())->m_props)->GetInt(L"selectCount", nDefault);
        int nDefault2 = 0;
        nDropBoxId = reinterpret_cast<CXmlData*>(&reinterpret_cast<Unk_SibItemData*>(item->FUN_140527840())->m_props)->GetInt(L"individualDropBoxId", nDefault2);
    }
    if (nDropBoxId == 0 || m_nSelectCount == 0)
        return;
    Unk_SibPlayer* pPlayer = ((Unk_SibPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    ItemDropContext params;
    params.m_job = pPlayer->FUN_141654700();
    params.m_gender = ((class PC*)(class Unk_SibPlayer*)(pPlayer))->FUN_141658e60();
    m_rewards.clear();
    TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nDropBoxId, params, m_rewards, false);
    m_binder.FUN_140d43990();
    unsigned nMinRows = 0x12;                                    // the list always shows at least 18 rows; the rest are empty entries
    unsigned nSize = (unsigned)m_rewards.size();
    unsigned nCount = (std::max)(nSize, nMinRows);
    ASDataProvider list(2);
    for (unsigned i = 0; i < nCount; ++i) {
        if (i >= m_rewards.size()) {
            list.PushValue(ASObj(2).FUN_1422bb890());
            continue;
        }
        CString strBind = m_binder.FUN_140d43510(static_cast<ItemAble*>(&m_rewards[i]));
        if (!strBind.IsEmpty()) {
            ASObj entry(2);
            entry.FUN_1407cba60("bindID", strBind);
            list.PushValue(entry.FUN_1422bb890());
        }
    }
    m_selectItemList->Invoke("resetRenderer");
    m_selectItemList->vfunc_25(list.FUN_1422bb870());
    m_selectItemList->vfunc_24(true);
    int nNext = reinterpret_cast<ItemFunctionArgs*>(&reinterpret_cast<Unk_SibItemData*>(item->FUN_140527840())->m_args)->FUN_1408d1fd0(4, 1);
    int nHave = g_143ab2a90.FUN_140a5f180(item->FUN_1405276c0(), 0);
    if (nNext == 1 && 1 < nHave)
        m_okButton->FUN_1422cdfb0(GetStringCommonByKey(L"s_selectItemBox_select_next"));
    else
        m_okButton->FUN_1422cdfb0(GetStringCommonByKey(L"s_selectItemBox_select_ok"));
    FUN_140f9a700();
}

// @0x140f9a140
void UISelectItemBoxDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_binder.FUN_140d43990();
    m_binderSel.FUN_140d43990();
    m_okButton = 0;
    m_selectItemList = 0;
    m_selectedSlots.clear();
    m_selectedCount = 0;
    m_selectNotice = 0;
    m_rewards.clear();
}

// @0x140f9a200
void UISelectItemBoxDialog::SetItemUid(unsigned __int64 uItemUid)
{
    m_uItemUid = uItemUid;
}

// @0x140f9a230
void UISelectItemBoxDialog::FUN_140f9a230(const Scaleform::GFx::FunctionHandler::Params& params)
{
    MS2Ptr<CItem> item = g_143ab2a90.FUN_140a5d680(m_uItemUid);
    if (item == 0)
        return;
    ATL::CAtlArray<unsigned> selected;
    m_selectItemList->FUN_1422cfa30(selected);
    if (selected.GetCount() != m_nSelectCount)
        return;
    CStringW strIndices;
    for (unsigned i = 0; i < selected.GetCount(); ++i) {
        if (selected[i] < 0 || selected[i] >= m_rewards.size()) {
            FUN_1412752d0(L"s_selectItemBox_select_wrong", 1);
            return;
        }
        strIndices += FUN_140b62550(selected[i]);
        if (i < selected.GetCount() - 1U)
            strIndices += L",";
    }
    ((class CBigDataLogSystem*)TSingleton<CBigDataLogSystem>::GetInstance())->SendLog("select_item_box_function", FUN_14016a600(strIndices, 0));
    OpenItemBoxContents(static_cast<CItem*>(((void*)((MS2Ptr<CItem>*)&(item))->get())), CStringW(strIndices));
    vfunc_67();
    FUN_141276180("select_confirm", "");
}

// @0x140f9a5f0
void UISelectItemBoxDialog::FUN_140f9a5f0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nSelected = m_selectItemList->FUN_1422cf920();
    if (nSelected > m_nSelectCount) {
        ASListEvent evt(params);
        Scaleform::GFx::Value value = evt.FUN_1422e27d0();
        ASButton row(value, 2);
        row.FUN_1422ce090(0);
        FUN_1412752d0(L"s_selectItemBox_cant_select_more", 1);
    } else {
        FUN_140f9a700();
    }
}

// @0x140f9a700
void UISelectItemBoxDialog::FUN_140f9a700()
{
    MS2Ptr<CItem> item = g_143ab2a90.FUN_140a5d680(m_uItemUid);
    if (item == 0)
        return;
    ATL::CAtlArray<unsigned> selected;
    m_selectItemList->FUN_1422cfa30(selected);
    if (selected.IsEmpty()) {
        m_selectedCount->vfunc_3(false);
        for (unsigned i = 0; i < m_selectedSlots.size(); ++i)
            ((Unk_SibSlot*)m_selectedSlots[i])->vfunc_3(false);
        m_selectNotice->vfunc_3(true);
        m_selectNotice->SetTextW(FUN_14028dfa0(CStringW(L"s_selectItemBox_select_notice"), m_nSelectCount));
    } else {
        m_selectNotice->vfunc_3(false);
        m_selectedCount->vfunc_3(true);
        size_t nCount = selected.GetCount();
        m_selectedCount->SetTextW(FUN_14028dfa0(CStringW(L"s_selectItemBox_select_itemCount"), nCount, m_nSelectCount));
        m_binderSel.FUN_140d43990();
        for (unsigned i = 0; i < m_selectedSlots.size(); ++i) {
            if (i >= selected.GetCount()) {
                ((Unk_SibSlot*)m_selectedSlots[i])->FUN_140e262c0("setData", "");
                ((Unk_SibSlot*)m_selectedSlots[i])->vfunc_3(false);
                continue;
            }
            unsigned nIdx = selected[i];
            if (nIdx >= m_rewards.size())
                continue;
            ((Unk_SibSlot*)m_selectedSlots[i])->vfunc_3(true);
            ((Unk_SibSlot*)m_selectedSlots[i])->Invoke("setData", m_binderSel.FUN_140d43510(static_cast<ItemAble*>(&m_rewards[nIdx])));
        }
    }
    reinterpret_cast<ASMovieClip*>(m_okButton.operator->())->FUN_1422c1fe0(selected.GetCount() == m_nSelectCount);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caa320-0x142caa420 .text$yd
