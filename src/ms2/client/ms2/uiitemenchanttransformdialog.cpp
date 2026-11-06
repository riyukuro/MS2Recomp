// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemEnchantTransformDialog: see
// uiitemenchanttransformdialog.h.
// MS2-UNIT: ?\uiitemenchanttransformdialog.cpp
// MS2-RANGE: 0x140c3cc10-0x140c3f350 .text$mn
// MS2-RANGE: 0x1400cd100-0x1400cd360 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemenchanttransformdialog.cpp"    // assumed
#define MS2_ASUICOMPONENT_SLOTS   // ASTileList::vfunc_24 (validateNow)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astilelist.h"

#include "uiitemenchanttransformdialog.h"

#include <vector>

#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// The statics of this TU: the item-name key, then the shared header's, then a second copy of the sort names.
static CString s_strItemName = "itemName";
#include "ms2/placeholder/header_statics_a.h"
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uitalkcinematic.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/commonfiles/itemenchanttransformtable.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/commonfiles/contentshutdown.h"  // C3: CContentShutdown::Get
#include "ms2/placeholder/ascorelist.h"   // C3: ASCoreList::SetSelectedIndex
#include "ms2/placeholder/asbutton.h"   // C3: ASButton / ASMovieClip / ASDisplayObject members

// ---- unit-local placeholders (unrecovered helpers) ----

// The message box record (MS2Ptr<CMsgBoxData> members are bound to the exe copies in symbols.tsv).
class CMsgBoxData : public CPtred
{
public:
    int FUN_141a02e50(int a, int b) const;
    void FUN_141a01600(__int64 n);
    void FUN_141a01ee0(MS2Ptr<CItem> item, const CStringW& name, int a, int b, int c, int d, int e);
    void SetButtonLabelIds(int a, int b, int c);
    void SetCallback(Delegate<bool(int, const CMsgBoxData&)> cb);
    template <class T> void Append(T v);                            // Append<int> 0x140533ff0 (inline COMDAT)
};
extern template class MS2Ptr<CMsgBoxData>;
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

// A button of the movie (the label and the enabled flag).


template <> MS2Ptr<ASUIComponent> UISwfEntity::GetChild<ASUIComponent>(const CString& strName);   // 0x140c02990, template COMDAT of another unit

// The player's item inventory (global object).
class Unk_TfInventory : public Unk_Inventory { };
extern Unk_Inventory g_143ab2a90;   // C3: was DAT_143ab2a90

class UITalkCinematic* FUN_140a7b2b0(int);   // C3: was FUN_140a7b2b0

// The ASDialog the movie root is cast to.
class ASDialog : public AScript
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2(int a, int b, int c);
};

class Unk_14025e7b0 { public: int FUN_1402c4c90(int nFlag); };
class Unk_TfBanConfig { public: char m_pad_00[8]; Unk_14025e7b0 m_8; };
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0
void FUN_141275260(int nId, int a, int b);                          // pop the system message nId
void FUN_140710590(COutPacket& pkt);                                // send
extern __int64 DAT_143ab2898;                                       // the player's mesos

typedef MS2Ptr<CItem> (*Unk_TfGetItemFn)(void* pItems, int nIndex);
void FUN_14141f970(const CString& strBag);                          // unbind a bag
void FUN_14141f770(const CString& strBag, int nSlots, void* pItems, MS2Ptr<CItem> (*pfnGetItem)(void*, int), int n1, int n2);   // C3: itemservice.cpp's definition (0x14141f770)
MS2Ptr<CItem> FUN_141420330(void* pItems, int nIndex);   // C3: itemservice.cpp's definition (0x141420330)
void FUN_141415600(const CString& strSlot);                         // unbind a slot
void FUN_141415450(const CString& strSlot, MS2Ptr<CItem> item, int a, int nIcon, int nFlags);
CStringW GetStringCommonByKey(const CStringW& strKey);                     // localized text
CStringW FUN_1409404f0(__int64 n);                                  // number text
void FUN_1409e4950(MS2Ptr<CItem> item, CStringW& strOption, bool* pHighSa);   // the item's option text

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140c3cc10
UIItemEnchantTransformDialog::UIItemEnchantTransformDialog()
    : m_state(0)
    , m_selected(0)
{
    m_2c = 0xc;
    m_strTargetBag = StringFormat<CString>("{0}.Target", GetTypeName());
    m_strSelectBag = StringFormat<CString>("{0}.Select", GetTypeName());
    m_strOutputBag = StringFormat<CString>("{0}.Output", GetTypeName());
}

// @0x140c3ced0
UIItemEnchantTransformDialog::~UIItemEnchantTransformDialog()
{
}

// @0x140c3cfa0
CString UIItemEnchantTransformDialog::GetTypeName()
{
    return "ItemEnchantTransformDialog";
}

// @0x140c3cff0
int UIItemEnchantTransformDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140c3d020
void UIItemEnchantTransformDialog::vfunc_43()
{
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog != 0) {
        UITalkCinematic* inv = ((class UITalkCinematic*)FUN_140a7b2b0(0x4e40));
        if (inv != 0) {
            int x = inv->GetLowerCutGlobalY();
            int y = inv->GetIllustGlobalX() - 0x50;
            if (x != -1 && y != -1) {
                dialog->vfunc_2(5, y, x - reinterpret_cast<ASDisplayObject*>(dialog)->GetHeightCeil());
                return;
            }
        }
    }
    ASDialog* dialog2 = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog2 != 0)
        dialog2->vfunc_2(1, 0, 0);
}

// @0x140c3d150
void UIItemEnchantTransformDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_state = 0;
    FUN_140c3d420();
}

// @0x140c3d190
void UIItemEnchantTransformDialog::vfunc_67()
{
    FUN_14141f970(m_strTargetBag);
    FUN_141415600(m_strSelectBag);
    for (unsigned i = 0; i < m_outputNames.GetCount(); ++i)
        FUN_141415600(m_outputNames[i]);
    m_selected = 0;
    m_outputs.RemoveAll();
    m_targets.RemoveAll();
    m_outputNames.RemoveAll();
    UIDialog::vfunc_67();
}

// @0x140c3d280
int UIItemEnchantTransformDialog::vfunc_13()
{
    return 0;
}

// @0x140c3d290
int UIItemEnchantTransformDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnSelectTargetItem", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nIndex = data.PopInt();
            FUN_140c3d960(nIndex);
        }
        return 1;
    } else if (_stricmp("OnSubmitTransform", szMethod) == 0) {
        OnSubmitTransform();
        return 1;
    } else if (_stricmp("OnSubmitRetry", szMethod) == 0) {
        OnSubmitRetry();
        return 1;
    }
    return 0;
}

// @0x140c3d3d0
void UIItemEnchantTransformDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    if (((CInPacket*)pPacket)->FUN_14070fe80() == 0x104)
        FUN_140c3ead0();
}

// @0x140c3d420
void UIItemEnchantTransformDialog::FUN_140c3d420()
{
    FUN_140c3d5a0();
    MS2Ptr<ASUIComponent> board = GetChild<ASUIComponent>("m_board");
    if (board == 0)
        return;
    if (MS2Ptr<ASButton> submit = board->FUN_140acce30<ASButton>("m_submit")) {
        reinterpret_cast<ASButton*>(submit.operator->())->FUN_1422cdfb0(GetStringCommonByKey(L"s_item_enchant_transform_submit"));
        reinterpret_cast<ASMovieClip*>(submit.operator->())->FUN_1422c1fe0(false);
    }
}

// @0x140c3d5a0
void UIItemEnchantTransformDialog::FUN_140c3d5a0()
{
    m_targets.RemoveAll();
    ATL::CAtlArray<unsigned __int64> uids;
    ((Unk_TfInventory*)&g_143ab2a90)->FUN_140a609a0(0, uids);
    for (unsigned i = 0; i < uids.GetCount(); ++i) {
        MS2Ptr<CItem> item = ((Unk_TfInventory*)&g_143ab2a90)->FUN_140a5d680(uids[i]);
        if (item == 0)
            continue;
        if (CItemEnchantTransformTable::FUN_140592110(item) == 0)
            continue;
        m_targets.Add(item);
    }
    FUN_14141f970(m_strTargetBag);
    Unk_TfGetItemFn pfnGetItem = FUN_141420330;
    FUN_14141f770(m_strTargetBag, (unsigned)m_targets.GetCount(), (void*)&m_targets, pfnGetItem, 0x415, 8);
    MS2Ptr<ASUIComponent> board = GetChild<ASUIComponent>("m_targetItems");
    if (board == 0)
        return;
    if (MS2Ptr<ASTileList> bag = board->FUN_140accef0<ASTileList>("m_itemBag")) {
        reinterpret_cast<ASCoreList*>(bag.operator->())->SetSelectedIndex(-1);
        bag->FUN_1422dd1d0();
        bag->FUN_1407cba60("bagId", m_strTargetBag);
        bag->vfunc_24(true);
    }
    board->vfunc_24(true);
}

// @0x140c3d960
void UIItemEnchantTransformDialog::FUN_140c3d960(int nIndex)
{
    if (m_state != 0 && m_state != 1)
        return;
    if (nIndex < 0 || nIndex >= (int)m_targets.GetCount())
        return;
    MS2Ptr<CItem> item = m_targets[nIndex];
    if (CItemEnchantTransformTable::FUN_140592110(item) == 0)
        return;
    CStringW strOption;
    bool bHighSa = false;
    FUN_1409e4950(item, strOption, &bHighSa);
    if (item->GetRarity() >= 5 && bHighSa == 1) {
        CStringW strAsk = GetStringCommonByKey(L"s_item_enchant_transform_ask_high_sa_option_item");
        CStringW strMsg;
        strMsg.Append(strOption);
        strMsg.Append(L"\n");
        strMsg.Append(strAsk);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x11, CStringW(strMsg), 0, CStringW(L""));
        if (box.get() != 0) {
            box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantTransformDialog::FUN_140c3eda0));
            box->FUN_141a01600(item->GetItemUid());
            box->FUN_141a01ee0(item, item->FUN_140527b10(), 1, 0, -1, -1, 1);
            box->SetButtonLabelIds(0x475, 0x476, 0);
            box->Append<int>(nIndex);
            FUN_140d73c60(box);
        }
    } else {
        FUN_140c3de50(nIndex);
    }
}

// MS2-FUNCTIONAL: MS2Ptr temp / copy order and frame size differ (large function)
// @0x140c3de50
void UIItemEnchantTransformDialog::FUN_140c3de50(int nIndex)
{
    if (m_state != 0 && m_state != 1)
        return;
    if (nIndex < 0 || nIndex >= (int)m_targets.GetCount())
        return;
    MS2Ptr<CItem> item = m_targets[nIndex];
    if (CItemEnchantTransformTable::FUN_140592110(item) == 0)
        return;
    CEnchantTransformDataPtr row = TSingleton<CItemEnchantTransformTable>::GetInstance()->FindByItem(item);
    if (row == 0)
        return;
    MS2Ptr<ASUIComponent> board = GetChild<ASUIComponent>("m_board");
    if (board == 0)
        return;
    m_selected = item;
    m_state = 1;
    FUN_141415600(m_strSelectBag);
    FUN_141415450(m_strSelectBag, m_selected, 0, 0x415, 8);
    ASObj obj(2);
    obj.FUN_1407cbb20(s_strItemName, m_selected->FUN_140528160());
    obj.FUN_1407cba60("binding", m_strSelectBag);
    CStringW strFee = FUN_14028dfa0<CStringW>(L"s_item_enchant_transform_fee", FUN_1409404f0(row->m_nNeedMeso));
    obj.FUN_1407cbb20("transformFee", strFee);
    m_outputs.RemoveAll();
    for (unsigned i = 0; i < m_outputNames.GetCount(); ++i)
        FUN_141415600(m_outputNames[i]);
    m_outputNames.RemoveAll();
    ASArray outputs(2);
    for (unsigned i = 0; i < row->m_arrOutputId.GetCount(); ++i) {
        int nId = row->m_arrOutputId[i];
        int nRank = row->m_arrOutputRank[i];
        int nCount = row->m_arrOutputCount[i];
        MS2Ptr<CItem> out(new CItem());
        if (out->FUN_14052b130(nId, nRank, 0) != 0) {
            out->FUN_14052b340(nCount);
            m_outputs.Add(out);
        }
        CString strName = Unk_SocketFormat("{0}.{1}", m_strOutputBag, i);
        FUN_141415600(strName);
        FUN_141415450(strName, out, 0, 0x415, 0x800);
        m_outputNames.Add(strName);
        ASObj entry(2);
        entry.FUN_1407cba60("binding", strName);
        entry.FUN_1407cbb20(s_strItemName, out->FUN_140528160());
        outputs.PushObj(entry);
    }
    ((ASObj*)&(obj))->FUN_140c16160("outputItems", ASArray(outputs));
    if (MS2Ptr<ASButton> submit = board->FUN_140acce30<ASButton>("m_submit"))
        reinterpret_cast<ASMovieClip*>(submit.operator->())->FUN_1422c1fe0(true);
    board->Invoke("selectItem", obj.FUN_1422bb870());
}

// @0x140c3e820
void UIItemEnchantTransformDialog::OnSubmitTransform()
{
    if (reinterpret_cast<CContentShutdown&>(((class Unk_TfBanConfig*)FUN_14025e7b0())->m_8).Get((CContentShutdown::Content)(0x54)) != 0)
        FUN_141275260(0x2f7, 1, 1);
    if (m_state != 1)
        return;
    if (m_selected == 0)
        return;
    CEnchantTransformDataPtr row = TSingleton<CItemEnchantTransformTable>::GetInstance()->FindByItem(m_selected);
    if (row == 0)
        return;
    if (DAT_143ab2898 < row->m_nNeedMeso) {
        FUN_141275260(0x34, 1, 1);
        return;
    }
    COutPacket pkt(static_cast<int>(SendOp::TransferEnchant), 0);
    pkt.Encode8(m_selected->GetItemUid());
    FUN_140710590(pkt);
    MS2Ptr<ASUIComponent> board = GetChild<ASUIComponent>("m_board");
    if (board == 0)
        return;
    if (MS2Ptr<ASButton> submit = board->FUN_140acce30<ASButton>("m_submit"))
        reinterpret_cast<ASMovieClip*>(submit.operator->())->FUN_1422c1fe0(false);
}

// @0x140c3ead0
void UIItemEnchantTransformDialog::FUN_140c3ead0()
{
    if (m_state != 1)
        return;
    MS2Ptr<ASUIComponent> board = GetChild<ASUIComponent>("m_board");
    if (board == 0)
        return;
    if (MS2Ptr<ASButton> submit = board->FUN_140acce30<ASButton>("m_submit")) {
        reinterpret_cast<ASButton*>(submit.operator->())->FUN_1422cdfb0(GetStringCommonByKey(L"s_item_enchant_transform_retry"));
        reinterpret_cast<ASMovieClip*>(submit.operator->())->FUN_1422c1fe0(true);
    }
    FUN_140c3d5a0();
    board->Invoke("onTransformResult");
    m_state = 2;
}

// @0x140c3ecb0
void UIItemEnchantTransformDialog::OnSubmitRetry()
{
    m_state = 0;
    m_selected = 0;
    m_outputs.RemoveAll();
    FUN_140c3d420();
    MS2Ptr<ASUIComponent> board = GetChild<ASUIComponent>("m_board");
    if (board == 0)
        return;
    board->Invoke("onRetry");
}

// @0x140c3eda0
bool UIItemEnchantTransformDialog::FUN_140c3eda0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0) {
        int nSlot = box.FUN_141a02e50(0, 0);
        FUN_140c3de50(nSlot);
    }
    else
        OnSubmitRetry();
    return true;
}
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca2b90-0x142ca2c70 .text$yd
