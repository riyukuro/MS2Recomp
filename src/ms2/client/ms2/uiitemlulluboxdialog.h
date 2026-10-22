// Recovered Lullu box dialog (opens one or ten Lullu boxes with a key, or the simple variant; shows the obtained items in the
// box's result slots). Unk_ names are local reconstruction names.
#pragma once
#include <set>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/commonstruct_wa.h"
class CMsgBoxData;
class ASMovieClip;
class ASTextField;
class ASData;
class Unk_LulluBoxButton;
class Unk_LulluBoxCheck;
// Orders the sets of special items (the comparator is the ItemEntity ordering of commonfiles\commonstruct).
struct Unk_LulluBoxLess
{
    bool operator()(const ItemEntity& a, const ItemEntity& b) const { return FUN_14026aeb0(a, b); }
};
class UIItemLulluBoxDialog : public UIDialog
{
public:
    UIItemLulluBoxDialog();
    virtual ~UIItemLulluBoxDialog();
    virtual CString vfunc_1();
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void OnLoadComplete();
    virtual void vfunc_79(void*);
    virtual void vfunc_45(Scaleform::GFx::Value*, const CString&, ASData*);
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    // @0x140ea04b0
    virtual int vfunc_48() { return 20267; }
    void FUN_140e9c0d0();
    void FUN_140e9c150(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140e9c1e0(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140e9c210(const Scaleform::GFx::FunctionHandler::Params&);
    void SetBoxItemId(int);
    bool FUN_140e9c260(int, const CMsgBoxData&);
    bool FUN_140e9c2a0(int, const CMsgBoxData&);
    void FUN_140e9c340();
    void FUN_140e9c3e0();
    void FUN_140e9c550();
    void FUN_140e9cde0(int);
    bool FUN_140e9d1e0(const ItemEntity&);
    bool FUN_140e9d2b0();
    void FUN_140e9dc30();
    int FUN_140e9e8f0();
    void FUN_140e9ece0();
    void FUN_140e9f540();
    void FUN_140e9f870(const CStringW&, int);
    MS2Ptr<ASTextField> FUN_140e48d80(const CString&, MS2Ptr<ASTextField>&);
    MS2Ptr<Unk_LulluBoxCheck> FUN_140e52700(const CString&, MS2Ptr<Unk_LulluBoxCheck>&);
    MS2Ptr<Unk_LulluBoxButton> FUN_140bc6d10(const CString&, MS2Ptr<Unk_LulluBoxButton>&);
    MS2Ptr<ASMovieClip> FUN_140c57ce0(const CString&, MS2Ptr<ASMovieClip>&);
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString&);
private:
    MS2_LAYOUT_FRIEND;
    int m_boxItemId;                            // +0x178 item id of the box that is being opened
    CString m_bagId;                            // +0x180 "bagId" of the key items (ItemLullu_...)
    Unk_ItemVec m_result;                       // +0x188 the obtained items (std::vector<ItemEntity>)
    Unk_StrVec m_slotBinds;                     // +0x1a0 the "binding" strings handed to the AS slots
    std::set<ItemEntity, Unk_LulluBoxLess> m_special1;  // +0x1b8 drops of the box that are special
    std::set<ItemEntity, Unk_LulluBoxLess> m_special2;  // +0x1c8 items of the second set (flag read from the packet)
    bool m_multi;                               // +0x1d8 ten at a time
    bool m_sent;                                // +0x1d9 the open request was sent
    bool m_simple;                              // +0x1da the "OpenItemBoxLulluSimple" variant
    MS2Ptr<ASTextField> m_title;                // +0x1e0
    MS2Ptr<Unk_LulluBoxButton> m_singleOpen;    // +0x1f0
    MS2Ptr<Unk_LulluBoxButton> m_multiOpen;     // +0x200
    MS2Ptr<Unk_LulluBoxButton> m_itemBreak;     // +0x210
    MS2Ptr<Unk_LulluBoxButton> m_styleShop;     // +0x220
    MS2Ptr<Unk_LulluBoxCheck> m_skipEffect;     // +0x230
    MS2Ptr<Unk_LulluBoxCheck> m_autoPay;        // +0x240
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
