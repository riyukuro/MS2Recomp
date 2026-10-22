// uiweddingaffinitydialog.h - UIWeddingAffinityDialog (RTTI .?AVUIWeddingAffinityDialog@@, 0x178 bytes, UIDialog, UI id
// 0x4f95, swf "WeddingAffinityDialog"): shows the couple's affinity experience history ("setHistory"): one line with the
// per-day base experience, then "[date] text" lines for every recorded affinity event. Owning unit:
// ?\uiweddingaffinitydialog.cpp. Header name assumed from the unit path. No members of its own.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIWeddingAffinityDialog : public UIDialog
{
public:
    UIWeddingAffinityDialog();                                  // 0x140fc2090
    virtual ~UIWeddingAffinityDialog();                         //  0 0x140fc2110 (??_G 0x140fc2ae0)
    virtual CString GetTypeName();                                  //  1 0x140fc2150 "WeddingAffinityDialog"
    virtual void OnLoadComplete();                              // 22 0x140fc21e0 build the history text
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fc2510
    virtual int vfunc_48() { return 0x4f95; }                   // 48 0x140fc2b20
    virtual int vfunc_65();                                     // 65 0x140fc21a0
    virtual void vfunc_67();                                    // 67 0x140fc21c0
};
MS2_CHECK_SIZE(UIWeddingAffinityDialog, 0x178);
