// Recovered Lullu box dialog (opens one or ten Lullu boxes with a key, or the simple variant; shows the obtained items in the
// box's result slots). Unk_ names are local reconstruction names.
#pragma once
#include <set>
#include <vector>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/itementityless.h"
class CMsgBoxData;
class ASMovieClip;
class ASTextField;
class ASData;
class ASButton;
class ASCheckBox;
class UIItemLulluBoxDialog : public UIDialog
{
public:
    UIItemLulluBoxDialog();
    virtual ~UIItemLulluBoxDialog();
    virtual CString GetTypeName();
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void OnLoadComplete();
    virtual void vfunc_79(void*);
    virtual void vfunc_45(Scaleform::GFx::Value*, const CString&, ASData*);
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    // @0x140ea04b0
    virtual int vfunc_48() { return 20267; }
    void ReleaseSlotBinds();
    void OnSelectMode(const Scaleform::GFx::FunctionHandler::Params&);
    void OnOpenItemBreak(const Scaleform::GFx::FunctionHandler::Params&);
    void OnOpenStyleShop(const Scaleform::GFx::FunctionHandler::Params&);
    void SetBoxItemId(int);
    bool FUN_140e9c260(int, const CMsgBoxData&);
    bool FUN_140e9c2a0(int, const CMsgBoxData&);
    void UpdateTitle();
    void UpdateAutoPay();
    void InitSimpleBox();
    void FUN_140e9cde0(int);
    bool IsSpecialItem(const ItemEntity&);
    bool FUN_140e9d2b0();
    void FUN_140e9dc30();
    int FUN_140e9e8f0();
    void FUN_140e9ece0();
    void SendOpenBox();
    void FUN_140e9f870(const CStringW&, unsigned);
    // 0x140e48d80 = UISwfEntity::GetChildInto<ASTextField> (uiswfentity.h)
    // C3: FUN_140e52700 (bind a check box) is UIItemPetBoxDialog's (uiitempetboxdialog.h), called through a view in the .cpp
private:
    MS2_LAYOUT_FRIEND;
    int m_boxItemId;                            // +0x178 item id of the box that is being opened
    CString m_bagId;                            // +0x180 "bagId" of the key items (ItemLullu_...)
    std::vector<ItemEntity> m_result;           // +0x188 the obtained items
    std::vector<CString> m_slotBinds;            // +0x1a0 the "binding" strings handed to the AS slots
    std::set<ItemEntity, Unk_GachaLess> m_special1;  // +0x1b8 drops of the box that are special
    std::set<ItemEntity, Unk_GachaLess> m_special2;  // +0x1c8 items of the second set (flag read from the packet)
    bool m_multi;                               // +0x1d8 ten at a time
    bool m_sent;                                // +0x1d9 the open request was sent
    bool m_simple;                              // +0x1da the "OpenItemBoxLulluSimple" variant
    MS2Ptr<ASTextField> m_title;                // +0x1e0
    MS2Ptr<ASButton> m_singleOpen;            // +0x1f0
    MS2Ptr<ASButton> m_multiOpen;             // +0x200
    MS2Ptr<ASButton> m_itemBreak;             // +0x210
    MS2Ptr<ASButton> m_styleShop;             // +0x220
    MS2Ptr<ASCheckBox> m_skipEffect;     // +0x230
    MS2Ptr<ASCheckBox> m_autoPay;        // +0x240
    MS2Ptr<ASMovieClip> m_itemBox;              // +0x250
    MS2Ptr<ASMovieClip> m_resultItem;           // +0x260
};
MS2_CHECK_SIZE(UIItemLulluBoxDialog, 0x270);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_boxItemId, 0x178);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_bagId, 0x180);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_result, 0x188);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_slotBinds, 0x1a0);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_special1, 0x1b8);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_special2, 0x1c8);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_multi, 0x1d8);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_title, 0x1e0);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_singleOpen, 0x1f0);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_skipEffect, 0x230);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_itemBox, 0x250);
MS2_CHECK_OFFSET(UIItemLulluBoxDialog, m_resultItem, 0x260);
