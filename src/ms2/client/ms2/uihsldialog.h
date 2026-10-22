// uihsldialog.h - UIHSLDialog (RTTI .?AVUIHSLDialog@@, 0x188 bytes): the debug HSL colour picker. Three sliders set the
// hue/saturation/lightness bytes, each change is pushed to the renderer's colour. Recovered with ?\uihsldialog.cpp
// (header name assumed).
#pragma once

#include "ms2/client/ms2/uidialog.h"

class UIHSLDialog : public UIDialog
{
public:
    UIHSLDialog();                                                              // 0x1412c9860
    virtual ~UIHSLDialog();                                                     // 0x1412c98e0, ??_G 0x1412c9d00
    virtual CString GetTypeName();                                                  //  1 0x1412c9920
    virtual void OnLoadComplete();                                              // 22 0x1412c9970
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                // 28 0x1412c9a40
    virtual int vfunc_48() { return 0x4eab; }                                   // 48 (COMDAT 0x1412c9d40)

    int m_nHue;                                                                 // +0x178 slider value 0..255
    int m_nSaturation;                                                          // +0x17c
    int m_nLightness;                                                           // +0x180
};
MS2_CHECK_SIZE(UIHSLDialog, 0x188);
