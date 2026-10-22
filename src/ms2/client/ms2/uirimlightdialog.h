// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
//
// UIRimLightDialog: a debug dialog ("RimLightDialog", Debug_UI swf, UI type 0x4eae) with sliders for the character
// light angle, the shadow parameters and the subsurface-scattering colour. RTTI .?AVUIRimLightDialog@@, 0x178 bytes
// (no own members), vftables 0x142f5bd38 (84 slots) and 0x142f5bfe0 (IMessageListener at +0x18).
// Names: virtuals are Ghidra's vfunc_<slot> where the base does so; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASData;

class UIRimLightDialog : public UIDialog
{
public:
    UIRimLightDialog();                                                                             // 0x141709320
    virtual ~UIRimLightDialog();                                                                    //  0 0x141709370
    virtual CString GetTypeName();                                                                      //  1 0x1417093b0
    virtual void OnLoadComplete();                                                                  // 22 0x141709400
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x1417095d0
    virtual int vfunc_48() { return 0x4eae; }                                                       // 48 (COMDAT 0x141709960)

    void FUN_1417097a0(ASData& data);   // "onChangeSliderLightAngle": yaw (+90 in the UI), pitch
    void FUN_141709800(ASData& data);   // "onChangeSliderShadow": four shadow parameters
    void FUN_141709870(ASData& data);   // "onChangeSliderSSS": r, g, b, power
};
MS2_CHECK_SIZE(UIRimLightDialog, 0x178);
