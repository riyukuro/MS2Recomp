// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISelectSuperWorldChatDialog, the picker of the super world
// chat / wedding chat item: see uisidepopuptalk.h. Second of the three TUs of ?\uisidepopuptalk.cpp (its own file name
// is unknown).
// MS2-UNIT: ?\uisidepopuptalk.cpp#2
// MS2-RANGE: 0x1400dae40-0x1400dafe0 .text$di
// MS2-RANGE: 0x140e8bcb0-0x140e8d770 .text$mn
// MS2-RANGE: 0x142ca7b10-0x142ca7bc0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiselectsuperworldchatdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uisidepopuptalk.h"

#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asmultiselecttilecachelist.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the unit's header statics: header_statics_a.h above, then a key controller ------------------------------------------
static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

extern Unk_Inventory DAT_143ab2a90;                         // the player's inventory
CItemData* FUN_140527840(CItem* pItem);                     // the item's data record
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, UIDialog* pDialog);   // the common dialog AS calls

// A list control wrapping a movie child (the GetChild back end of this unit's instance).
template <class T> MS2Ptr<T> Unk_SptASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// @0x140e8bcb0
UISelectSuperWorldChatDialog::UISelectSuperWorldChatDialog()
    : m_binder("SelectSuperWorldChatDialog")
{
    FUN_141924170(1);
    FUN_140d432d0(&m_binder, 0x411);
}

// @0x140e8bde0
UISelectSuperWorldChatDialog::~UISelectSuperWorldChatDialog()
{
}

// @0x140e8be80
CString UISelectSuperWorldChatDialog::GetTypeName()
{
    return "SelectSuperWorldChatDialog";
}
MS2_REPLACE_METHOD(0x140E8BE80, UISelectSuperWorldChatDialog, GetTypeName, 61, 0xBE9BE37B);

// @0x140e8bed0
void UISelectSuperWorldChatDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_binder.FUN_140d43990();
    m_okButton = 0;
    m_closeButton = 0;
    m_list = 0;
}
MS2_REPLACE_METHOD(0x140E8BED0, UISelectSuperWorldChatDialog, vfunc_26, 106, 0xBEDEA49E);

// @0x140e8bf40
void UISelectSuperWorldChatDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    PC* pPlayer = static_cast<PC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    FUN_141925ec0("m_close");
    FUN_140e8d030("m_selectItemList", m_list);
    if (FUN_140bc6d10("m_okButton", m_okButton).get())
        m_okButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UISelectSuperWorldChatDialog::FUN_140e8c790), 0);
    if (FUN_140bc6d10("m_close", m_closeButton).get())
        m_closeButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UISelectSuperWorldChatDialog::FUN_140e8c8e0), 0);
    m_slotItems.RemoveAll();
    m_binder.FUN_140d43990();

    ATL::CAtlArray<MS2Ptr<CItem> > aItems;
    FUN_140e8ca10(aItems);
    FUN_140e8cb80(aItems);
    unsigned nMinSlots = 0x12;
    unsigned nCount = (unsigned)aItems.GetCount();
    unsigned nSlots = (std::max)(nCount, nMinSlots);
    ASDataProvider list(2);
    for (size_t i = 0; i < nSlots; i++)
    {
        if (i >= aItems.GetCount())
        {
            list.FUN_1422bc050(ASObj(2).FUN_1422bb890());
            continue;
        }
        MS2Ptr<CItem> spItem = aItems[i];
        if (spItem == 0)
            continue;
        int nItemId = spItem->FUN_1405276c0();
        int nRarity = spItem->FUN_140526bd0();
        int nAmount = DAT_143ab2a90.FUN_140a5f180(nItemId, nRarity);
        CString strBind = m_binder.FUN_140d43310(nItemId, nRarity, nAmount);
        if (strBind.IsEmpty())
            continue;
        ASObj entry(2);
        entry.FUN_1407cba60("bindID", strBind);
        if (nItemId == pPlayer->FUN_1416639e0())
            entry.FUN_1407cbbe0("select", true);
        list.FUN_1422bc050(entry.FUN_1422bb890());
        m_slotItems.SetAt((unsigned)i, nItemId);
    }
    m_list->Invoke("resetRenderer");
    m_list->vfunc_25(list.FUN_1422bb870());
    m_list->vfunc_24(true);
}

// @0x140e8c720
int UISelectSuperWorldChatDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140E8C720, UISelectSuperWorldChatDialog, vfunc_28, 101, 0xBE7298CF);

// @0x140e8c790
void UISelectSuperWorldChatDialog::FUN_140e8c790(const Scaleform::GFx::FunctionHandler::Params& params)
{
    ATL::CAtlArray<unsigned> aSelected;
    m_list->FUN_1422cfa30(aSelected);
    if (aSelected.GetCount() > 0)
    {
        unsigned nItemId = 0;
        if (m_slotItems.Lookup(aSelected[0], nItemId))
        {
            COutPacket packet(0xa7);
            packet.Encode1(0);
            packet.Encode4(nItemId);
            FUN_140710590(packet);
        }
    }
    else
    {
        COutPacket packet(0xa7);
        packet.Encode1(1);
        FUN_140710590(packet);
    }
    vfunc_67();
}
MS2_REPLACE_METHOD(0x140E8C790, UISelectSuperWorldChatDialog, FUN_140e8c790, 317, 0xDB510E28);

// @0x140e8c8e0
void UISelectSuperWorldChatDialog::FUN_140e8c8e0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    ATL::CAtlArray<unsigned> aSelected;
    m_list->FUN_1422cfa30(aSelected);
    if (aSelected.GetCount() > 0)
    {
        unsigned nItemId = 0;
        if (m_slotItems.Lookup(aSelected[0], nItemId))
        {
            COutPacket packet(0xa7);
            packet.Encode1(0);
            packet.Encode4(nItemId);
            FUN_140710590(packet);
        }
    }
    else
    {
        COutPacket packet(0xa7);
        packet.Encode1(1);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x140E8C8E0, UISelectSuperWorldChatDialog, FUN_140e8c8e0, 292, 0x9AA48589);

// @0x140e8ca10
void UISelectSuperWorldChatDialog::FUN_140e8ca10(ATL::CAtlArray<MS2Ptr<CItem> >& aOut)
{
    ATL::CAtlArray<MS2Ptr<CItem> > aItems;
    DAT_143ab2a90.FUN_140a60880(7, aItems);
    for (size_t i = 0; i < aItems.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = aItems[i];
        if (spItem == 0)
            continue;
        MS2Ptr<CItemData> spData(FUN_140527840(spItem.operator->()));
        if (spData == 0)
            continue;
        if (spData->function.name != L"SuperWorldChat")
            continue;
        aOut.Add(spItem);
    }
}
MS2_REPLACE_METHOD(0x140E8CA10, UISelectSuperWorldChatDialog, FUN_140e8ca10, 362, 0x7D369B5E);

// @0x140e8cb80
void UISelectSuperWorldChatDialog::FUN_140e8cb80(ATL::CAtlArray<MS2Ptr<CItem> >& aOut)
{
    ATL::CAtlArray<MS2Ptr<CItem> > aItems;
    DAT_143ab2a90.FUN_140a60880(7, aItems);
    for (size_t i = 0; i < aItems.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = aItems[i];
        if (spItem == 0)
            continue;
        MS2Ptr<CItemData> spData(FUN_140527840(spItem.operator->()));
        if (spData == 0)
            continue;
        if (spData->function.name != L"WeddingChat")
            continue;
        aOut.Add(spItem);
    }
}
MS2_REPLACE_METHOD(0x140E8CB80, UISelectSuperWorldChatDialog, FUN_140e8cb80, 362, 0x8CEE4E13);

// ---- the GetChild<ASMultiSelectTileCacheList> chain (template COMDATs of this TU) ------------------------------------

// @0x140e8cee0
template <class T> MS2Ptr<T> AScript::FUN_140e159f0(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return Unk_SptASCreate<T>(m_nMovieId, v);
    return MS2Ptr<T>(0);
}

// @0x140e8cfa0
template <class T> MS2Ptr<T> UISwfEntity::GetChild(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<T>(0);
    return m_30->FUN_140e159f0<T>(strName);
}

// @0x140e8d030
MS2Ptr<ASMultiSelectTileCacheList> UISelectSuperWorldChatDialog::FUN_140e8d030(const CString& strName, MS2Ptr<ASMultiSelectTileCacheList>& out)
{
    out = GetChild<ASMultiSelectTileCacheList>(strName);
    return out;
}
MS2_REPLACE_METHOD(0x140E8D030, UISelectSuperWorldChatDialog, FUN_140e8d030, 138, 0x1C80DD72);
