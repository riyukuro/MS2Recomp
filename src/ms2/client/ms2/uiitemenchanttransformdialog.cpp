// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemEnchantTransformDialog: see
// uiitemenchanttransformdialog.h.
// MS2-UNIT: ?\uiitemenchanttransformdialog.cpp
// MS2-RANGE: 0x140c3cc10-0x140c3f350 .text$mn
// MS2-RANGE: 0x1400cd100-0x1400cd360 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemenchanttransformdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

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

// ---- unit-local placeholders (unrecovered helpers) ----

// The message box record (MS2Ptr<CMsgBoxData> members are bound to the exe copies in symbols.tsv).
class CMsgBoxData : public CPtred
{
public:
    int FUN_141a02e50(int a, int b) const;
    void FUN_141a01600(__int64 n);
    void FUN_141a01ee0(MS2Ptr<CItem> item, const CStringW& name, int a, int b, int c, int d, bool e);
    void FUN_141a01700(int a, int b, int c);
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb);
    void FUN_140533ff0(int n);
};
extern template class MS2Ptr<CMsgBoxData>;
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

// A button of the movie (the label and the enabled flag).
class Unk_TfButton : public AScript
{
public:
    void FUN_1422cdfb0(const CStringW& strLabel);       // set the label
    void FUN_1422c1fe0(bool bEnable);                   // enable / disable
};

// The item bag control of the movie.
class Unk_TfBag : public AScript
{
public:
    void FUN_1422dcca0(int n);
    void FUN_1422dd1d0();                               // clear
    void FUN_1407cba60(const char* szName, CString str);
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
};

// The movie's board (the root child of the dialog).
class Unk_TfBoard : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
};

// A row of the item enchant transform table: the fee and the output items (id, rank, count) of one input item.
class Unk_TransformRow : public CPtred
{
public:
    __int64 m_nFee;                                     // +0x18
    char m_pad_20[0x20];
    ATL::CAtlArray<int> m_ids;                          // +0x20
    ATL::CAtlArray<int> m_ranks;                        // +0x40
    ATL::CAtlArray<int> m_counts;                       // +0x60
};

// The transform table singleton.
class Unk_TransformTable
{
public:
    MS2Ptr<Unk_TransformRow> FUN_1405924d0(MS2Ptr<CItem> item);     // the row of an item (NULL: not transformable)
};
Unk_TransformTable* FUN_1405934c0();
int FUN_140592110(MS2Ptr<CItem> item);                              // the item can be transformed

// The player's item inventory (global object).
class Unk_TfInventory
{
public:
    void FUN_140a609a0(int nTab, ATL::CAtlArray<unsigned __int64>& uids);
    MS2Ptr<CItem> FUN_140a5d680(unsigned __int64 uid);
};
extern int DAT_143ab2a90;

class Unk_EnInvDialog
{
public:
    int FUN_141b1d3d0();
    int FUN_141b1d460();
};
Unk_EnInvDialog* FUN_140a7b2b0(int id);

// The ASDialog the movie root is cast to.
class ASDialog : public AScript
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2(int a, int b, int c);
    int FUN_1422c13b0();
};

class Unk_14025e7b0 { public: int FUN_1402c4c90(int nFlag); };
class Unk_TfBanConfig { public: char m_pad_00[8]; Unk_14025e7b0 m_8; };
Unk_TfBanConfig* FUN_14025e7b0();
void FUN_141275260(int nId, int a, int b);                          // pop the system message nId
void FUN_140710590(COutPacket& pkt);                                // send
extern __int64 DAT_143ab2898;                                       // the player's mesos

typedef MS2Ptr<CItem> (*Unk_TfGetItemFn)(void* pItems, int nIndex);
void FUN_14141f970(const CString& strBag);                          // unbind a bag
void FUN_14141f770(const CString& strBag, int nCount, void* pItems, Unk_TfGetItemFn pfn, int nIcon, int nFlags);
MS2Ptr<CItem> FUN_141420330(void* pItems, int nIndex);
void FUN_141415600(const CString& strSlot);                         // unbind a slot
void FUN_141415450(const CString& strSlot, MS2Ptr<CItem> item, int a, int nIcon, int nFlags);
CStringW FUN_14028b8e0(const CStringW& strKey);                     // localized text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_1409404f0(__int64 n);                                  // number text
CString FUN_140540050(const char* szFormat, const CString& strArg);
void FUN_140c16160(ASObj& obj, const char* szName, ASArray arr);
void FUN_1409e4950(MS2Ptr<CItem> item, CStringW& strOption, char* pHighSa);   // the item's option text

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140c3cc10
UIItemEnchantTransformDialog::UIItemEnchantTransformDialog()
    : m_state(0)
    , m_selected(0)
{
    m_2c = 0xc;
    m_strTargetBag = FUN_140540050("{0}.Target", vfunc_1());
    m_strSelectBag = FUN_140540050("{0}.Select", vfunc_1());
    m_strOutputBag = FUN_140540050("{0}.Output", vfunc_1());
}

// @0x140c3ced0
UIItemEnchantTransformDialog::~UIItemEnchantTransformDialog()
{
}

// @0x140c3cfa0
CString UIItemEnchantTransformDialog::vfunc_1()
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

// MS2-FUNCTIONAL: stack frame 0x10 larger in the exe (extra pointer temps), no source form found
// @0x140c3d020
void UIItemEnchantTransformDialog::vfunc_43()
{
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog != 0) {
        Unk_EnInvDialog* inv = FUN_140a7b2b0(0x4e40);
        if (inv != 0) {
            int x = inv->FUN_141b1d3d0();
            int y = inv->FUN_141b1d460() - 0x50;
            if (x != -1 && y != -1) {
                dialog->vfunc_2(5, y, x - dialog->FUN_1422c13b0());
                return;
            }
        }
    }
    dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog != 0)
        dialog->vfunc_2(1, 0, 0);
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
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nIndex = data.FUN_1422b8a10();
            FUN_140c3d960(nIndex);
        }
        return 1;
    } else if (_stricmp("OnSubmitTransform", szMethod) == 0) {
        FUN_140c3e820();
        return 1;
    } else if (_stricmp("OnSubmitRetry", szMethod) == 0) {
        FUN_140c3ecb0();
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

// MS2-FUNCTIONAL: one pointer temp fewer in the exe frame around the child-binding references
// @0x140c3d420
void UIItemEnchantTransformDialog::FUN_140c3d420()
{
    FUN_140c3d5a0();
    MS2Ptr<Unk_TfBoard> board = FUN_140c02990("m_board");
    if (board == 0)
        return;
    const MS2Ptr<Unk_TfButton>& submit = ((Unk_TfBoard*)board)->FUN_140acce30<Unk_TfButton>("m_submit");
    if (submit.get() != 0) {
        submit->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_item_enchant_transform_submit")));
        submit->FUN_1422c1fe0(false);
    }
}

// MS2-FUNCTIONAL: exe frame 0x20 larger (extra temps around the MS2Ptr item copies), loop shape differs
// @0x140c3d5a0
void UIItemEnchantTransformDialog::FUN_140c3d5a0()
{
    m_targets.RemoveAll();
    ATL::CAtlArray<unsigned __int64> uids;
    ((Unk_TfInventory*)&DAT_143ab2a90)->FUN_140a609a0(0, uids);
    for (unsigned i = 0; i < uids.GetCount(); ++i) {
        MS2Ptr<CItem> item = ((Unk_TfInventory*)&DAT_143ab2a90)->FUN_140a5d680(uids[i]);
        if (item == 0)
            continue;
        if (FUN_140592110(item) == 0)
            continue;
        m_targets.Add(item);
    }
    FUN_14141f970(m_strTargetBag);
    Unk_TfGetItemFn pfnGetItem = FUN_141420330;
    void* pItems = &m_targets;
    FUN_14141f770(m_strTargetBag, (int)m_targets.GetCount(), pItems, pfnGetItem, 0x415, 8);
    MS2Ptr<Unk_TfBoard> board = FUN_140c02990("m_targetItems");
    if (board == 0)
        return;
    const MS2Ptr<Unk_TfBag>& bag = ((Unk_TfBoard*)board)->FUN_140accef0<Unk_TfBag>("m_itemBag");
    if (bag.get() != 0) {
        bag->FUN_1422dcca0(-1);
        bag->FUN_1422dd1d0();
        bag->FUN_1407cba60("bagId", m_strTargetBag);
        bag->vfunc_24(true);
    }
    ((Unk_TfBoard*)board)->vfunc_24(true);
}

// MS2-FUNCTIONAL: MS2Ptr temp / copy order and frame size differ
// @0x140c3d960
void UIItemEnchantTransformDialog::FUN_140c3d960(int nIndex)
{
    if (m_state != 0 && m_state != 1)
        return;
    if (nIndex < 0 || nIndex >= (int)m_targets.GetCount())
        return;
    MS2Ptr<CItem> item = m_targets[nIndex];
    if (FUN_140592110(item) == 0)
        return;
    CStringW strOption;
    char bHighSa = 0;
    FUN_1409e4950(item, strOption, &bHighSa);
    if (item->FUN_140526bd0() < 5 || bHighSa != 1) {
        FUN_140c3de50(nIndex);
    } else {
        CStringW strAsk = FUN_14028b8e0(CStringW(L"s_item_enchant_transform_ask_high_sa_option_item"));
        CStringW strMsg;
        strMsg += strOption;
        strMsg += L"\n";
        strMsg += strAsk;
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x11, CStringW(strMsg), 0, CStringW(L""));
        if (box.get() != 0) {
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantTransformDialog::FUN_140c3eda0));
            box->FUN_141a01600(item->FUN_140526a50());
            box->FUN_141a01ee0(item, item->FUN_140527b10(), 1, 0, -1, -1, true);
            box->FUN_141a01700(0x475, 0x476, 0);
            box->FUN_140533ff0(nIndex);
            FUN_140d73c60(box);
        }
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
    if (FUN_140592110(item) == 0)
        return;
    MS2Ptr<Unk_TransformRow> row = FUN_1405934c0()->FUN_1405924d0(item);
    if (row == 0)
        return;
    MS2Ptr<Unk_TfBoard> board = FUN_140c02990("m_board");
    if (board == 0)
        return;
    m_selected = item;
    m_state = 1;
    FUN_141415600(m_strSelectBag);
    FUN_141415450(m_strSelectBag, m_selected, 0, 0x415, 8);
    ASObj obj(2);
    obj.FUN_1407cbb20(s_strItemName, m_selected->FUN_140528160());
    obj.FUN_1407cba60("binding", m_strSelectBag);
    obj.FUN_1407cbb20("transformFee", FUN_1405c2690(CStringW(L"s_item_enchant_transform_fee"), FUN_1409404f0(row->m_nFee)));
    m_outputs.RemoveAll();
    for (unsigned i = 0; i < m_outputNames.GetCount(); ++i)
        FUN_141415600(m_outputNames[i]);
    m_outputNames.RemoveAll();
    ASArray outputs(2);
    for (unsigned i = 0; i < row->m_ids.GetCount(); ++i) {
        int nId = row->m_ids[i];
        int nRank = row->m_ranks[i];
        int nCount = row->m_counts[i];
        MS2Ptr<CItem> out(new CItem());
        if (out->FUN_14052b130(nId, nRank, 0) != 0) {
            out->FUN_14052b340(nCount);
            m_outputs.Add(out);
        }
        CString strName = StringFormat("{0}.{1}", m_strOutputBag, i);
        FUN_141415600(strName);
        FUN_141415450(strName, out, 0, 0x415, 0x800);
        m_outputNames.Add(strName);
        ASObj entry(2);
        entry.FUN_1407cba60("binding", strName);
        entry.FUN_1407cbb20(s_strItemName, out->FUN_140528160());
        outputs.FUN_1422bbf00(entry);
    }
    FUN_140c16160(obj, "outputItems", ASArray(outputs));
    const MS2Ptr<Unk_TfButton>& submit = ((Unk_TfBoard*)board)->FUN_140acce30<Unk_TfButton>("m_submit");
    if (submit.get() != 0)
        submit->FUN_1422c1fe0(true);
    ((Unk_TfBoard*)board)->Invoke("selectItem", obj.FUN_1422bb870());
}

// MS2-FUNCTIONAL: MS2Ptr temp / copy order and frame size differ
// @0x140c3e820
void UIItemEnchantTransformDialog::FUN_140c3e820()
{
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(0x54) != 0)
        FUN_141275260(0x2f7, 1, 1);
    if (m_state != 1 || !(m_selected == 0))
        return;
    MS2Ptr<Unk_TransformRow> row = FUN_1405934c0()->FUN_1405924d0(m_selected);
    if (row == 0)
        return;
    if (DAT_143ab2898 < row->m_nFee) {
        FUN_141275260(0x34, 1, 1);
        return;
    }
    COutPacket pkt(0x77, 0);
    pkt.Encode8(m_selected->FUN_140526a50());
    FUN_140710590(pkt);
    MS2Ptr<Unk_TfBoard> board = FUN_140c02990("m_board");
    if (board == 0)
        return;
    const MS2Ptr<Unk_TfButton>& submit = ((Unk_TfBoard*)board)->FUN_140acce30<Unk_TfButton>("m_submit");
    if (submit.get() != 0)
        submit->FUN_1422c1fe0(false);
}

// MS2-FUNCTIONAL: one pointer temp fewer in the exe frame around the child-binding references
// @0x140c3ead0
void UIItemEnchantTransformDialog::FUN_140c3ead0()
{
    if (m_state != 1)
        return;
    MS2Ptr<Unk_TfBoard> board = FUN_140c02990("m_board");
    if (board == 0)
        return;
    const MS2Ptr<Unk_TfButton>& submit = ((Unk_TfBoard*)board)->FUN_140acce30<Unk_TfButton>("m_submit");
    if (submit.get() != 0) {
        submit->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_item_enchant_transform_retry")));
        submit->FUN_1422c1fe0(true);
    }
    FUN_140c3d5a0();
    ((Unk_TfBoard*)board)->Invoke("onTransformResult");
    m_state = 2;
}

// @0x140c3ecb0
void UIItemEnchantTransformDialog::FUN_140c3ecb0()
{
    m_state = 0;
    m_selected = 0;
    m_outputs.RemoveAll();
    FUN_140c3d420();
    MS2Ptr<Unk_TfBoard> board = FUN_140c02990("m_board");
    if (board == 0)
        return;
    ((Unk_TfBoard*)board)->Invoke("onRetry");
}

// @0x140c3eda0
bool UIItemEnchantTransformDialog::FUN_140c3eda0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0) {
        int nSlot = box.FUN_141a02e50(0, 0);
        FUN_140c3de50(nSlot);
    }
    else
        FUN_140c3ecb0();
    return true;
}
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca2b90-0x142ca2c70 .text$yd
