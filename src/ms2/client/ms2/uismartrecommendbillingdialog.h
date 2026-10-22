// uismartrecommendbillingdialog.h - UISmartRecommendBillingDialog (RTTI .?AVUISmartRecommendBillingDialog@@, 0x190 bytes, UI id
// 0x4e9f) and UISmartRecommendNotifyDialog (RTTI .?AVUISmartRecommendNotifyDialog@@, 0x198 bytes, UI id 0x4e9e): the smart
// recommend ("smart pick") item offer. The notify toast shows the offered item (movie method "Open") and closes itself after a
// delay; its "OnBuy" opens the billing dialog, which asks for the confirmation and the payment ("OnConfirm" sends opcode 100).
// Owning unit: ?\uismartrecommendbillingdialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

// The recommended item record (CRecommendItem, unit_140815690: RTTI-named, not recovered yet). Only the fields this unit reads.
class Unk_RecommendItem : public CPtred
{
public:
    unsigned m_nId;                         // +0x18 the recommend id (sent in the purchase packet)
    int m_nItemId;                          // +0x1c
    int m_nRarity;                          // +0x20
    int m_nAmount;                          // +0x24
    CStringW m_strDesc;                     // +0x28
    CStringW m_strName;                     // +0x30
    CStringW m_strTitle;                    // +0x38
    int m_nTime;                            // +0x40
    int m_pad_44;
    __int64 m_nPrice;                       // +0x48 meso price, 0 = paid in items
    int m_nPayItemId;                       // +0x50
    int m_nPayRarity;                       // +0x54
    unsigned m_nPayCount;                   // +0x58
};
MS2_CHECK_OFFSET(Unk_RecommendItem, m_nId, 0x18);
MS2_CHECK_OFFSET(Unk_RecommendItem, m_nPrice, 0x48);
MS2_CHECK_OFFSET(Unk_RecommendItem, m_nPayCount, 0x58);

// The 16-byte intrusive handle to a Unk_RecommendItem (pointer at +8). Out-of-line members live in unit_140815690.
class Unk_RecommendPtr
{
public:
    Unk_RecommendPtr();                                         // 0x1408162d0
    ~Unk_RecommendPtr();                                        // 0x140816530
    // @0x14134e360
    Unk_RecommendPtr(const Unk_RecommendPtr& o)
    {
        m_p = o.m_p;
        FUN_1408177b0();
    }
    Unk_RecommendPtr& operator=(const Unk_RecommendPtr& o);     // 0x140816660
    Unk_RecommendItem* operator->() const;                      // 0x140816710
    void FUN_1408177b0();                                       // add a reference
    // @0x14134d6c0
    Unk_RecommendPtr* FUN_14134d6c0(int)
    {
        FUN_1408178b0();
        return this;
    }
    // @0x14134d6f0
    bool FUN_14134d6f0() const { return m_p == 0; }
    // @0x14134e3e0
    Unk_RecommendItem* get() const { return m_p; }
    void FUN_1408178b0();                                       // release and clear
private:
    void* m_unk_00;
    Unk_RecommendItem* m_p;                                     // +8
};
MS2_CHECK_SIZE(Unk_RecommendPtr, 0x10);

class Unk_RecommendCache;

class UISmartRecommendBillingDialog : public UIDialog
{
public:
    UISmartRecommendBillingDialog();                            // 0x14134c9d0
    // dtor 0x14134d680 (??_G 0x14134d720) is implicit: the exe copy stores no vptr
    virtual CString GetTypeName();                                  //  1 0x14134ca70 "SmartRecommendBillingDialog"
    virtual void OnLoadInit();                                  // 20 0x14134cb30
    virtual int vfunc_13();                                     // 13 0x14134ccd0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14134cd00
    virtual void vfunc_43();                                    // 43 0x14134cb60
    virtual int vfunc_48() { return 0x4e9f; }                   // 48 0x14134d760
    virtual int vfunc_65();                                     // 65 0x14134cac0
    virtual void vfunc_67();                                    // 67 0x14134caf0
    virtual void vfunc_79(void* p);                             // 79 0x14134cbd0 packet 0xa0: the offer was accepted

    void SetItem(Unk_RecommendPtr item);                  // 0x14134cf50 show this offer
    void FUN_14134cfa0();                                       // 0x14134cfa0 fill the movie

private:
    MS2_LAYOUT_FRIEND;
    Unk_RecommendPtr m_item;                                    // +0x178
    CString m_strBagKey;                                        // +0x188 the item preview key (dialog name)
};
MS2_CHECK_SIZE(UISmartRecommendBillingDialog, 0x190);
MS2_CHECK_OFFSET(UISmartRecommendBillingDialog, m_item, 0x178);
MS2_CHECK_OFFSET(UISmartRecommendBillingDialog, m_strBagKey, 0x188);

class UISmartRecommendNotifyDialog : public UIDialog
{
public:
    UISmartRecommendNotifyDialog();                             // 0x14134d770
    // dtor 0x14134e3a0 (??_G 0x14134e3f0) is implicit: the exe copy stores no vptr
    virtual CString GetTypeName();                                  //  1 0x14134d830 "SmartRecommendNotifyDialog"
    virtual void OnLoadInit();                                  // 20 0x14134d8f0
    virtual int vfunc_13();                                     // 13 0x14134d9a0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14134d9d0
    virtual void vfunc_43();                                    // 43 0x14134d920
    virtual int vfunc_48() { return 0x4e9e; }                   // 48 0x14134e440
    virtual int vfunc_65();                                     // 65 0x14134d880
    virtual void vfunc_67();                                    // 67 0x14134d8b0
    virtual void vfunc_72();                                    // 72 0x14134db90 close after the delay

    void FUN_14134dc50(int nRecommendId);                       // 0x14134dc50 pick the offer by id
    void FUN_14134dcc0();                                       // 0x14134dcc0 fill the movie

private:
    MS2_LAYOUT_FRIEND;
    Unk_RecommendPtr m_item;                                    // +0x178
    CString m_strBagKey;                                        // +0x188
    unsigned m_nCloseTick;                                      // +0x190 service tick to close at, 0 = none
};
MS2_CHECK_SIZE(UISmartRecommendNotifyDialog, 0x198);
MS2_CHECK_OFFSET(UISmartRecommendNotifyDialog, m_nCloseTick, 0x190);
