// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiugcmodelhousedialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIUGCModelHouseDialog is the model house picker ("UGCModelHouseDialog", UI type 0x4f3f): "OnHomeConcept" applies the
// chosen concept to the player's home, directly when no plot is set (m_nPlot == 0), otherwise through a request packet
// (0x37, sub-op 2). RTTI .?AVUIUGCModelHouseDialog@@, 0x180 bytes (UIDialog 0x178 + the plot), vftables at +0 and
// +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIUGCModelHouseDialog : public UIDialog
{
public:
    UIUGCModelHouseDialog();                                    // 0x140faf390
    // The destructor is implicit (0x140faf410: just ~UIDialog), ??_G 0x140faf6d0.
    virtual CString GetTypeName();                                  //  1 0x140faf450
    virtual void vfunc_67();                                    // 67 0x140faf4a0 (Close: also forgets the plot)
    virtual void OnLoadComplete();                              // 22 0x140faf4d0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140faf4f0
    virtual int vfunc_48();                                     // 48 0x140faf710

public:
    int m_nPlot;                                                // +0x178 the plot the concept is applied to (0 = none)
};
MS2_CHECK_SIZE(UIUGCModelHouseDialog, 0x180);
MS2_CHECK_OFFSET(UIUGCModelHouseDialog, m_nPlot, 0x178);

// Set the plot (0x140faf6b0).
void FUN_140faf6b0(UIUGCModelHouseDialog* pDialog, int nPlot);
