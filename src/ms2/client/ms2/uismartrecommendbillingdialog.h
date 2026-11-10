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
#include "ms2/placeholder/csmartrecommendshoptable.h"

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

    void SetItem(MS2Ptr<CRecommendItem> item);                  // 0x14134cf50 show this offer
    void FUN_14134cfa0();                                       // 0x14134cfa0 fill the movie

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CRecommendItem> m_item;                                    // +0x178
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

    void SetRecommendItem(int nRecommendId);                       // 0x14134dc50 pick the offer by id
    void FUN_14134dcc0();                                       // 0x14134dcc0 fill the movie

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CRecommendItem> m_item;                                    // +0x178
    CString m_strBagKey;                                        // +0x188
    unsigned m_nCloseTick;                                      // +0x190 service tick to close at, 0 = none
};
MS2_CHECK_SIZE(UISmartRecommendNotifyDialog, 0x198);
MS2_CHECK_OFFSET(UISmartRecommendNotifyDialog, m_nCloseTick, 0x190);
