// uibuildbtnguide.h - UIBuildBtnGuide (RTTI .?AVUIBuildBtnGuide@@, 0x78 bytes): the key-guide animation next to the build
// (UGC) buttons. Recovered with ?\uibuildbtnguide.cpp (header name assumed).
#pragma once

#include "ms2/placeholder/uiheadupdisplay.h"

class UIBuildBtnGuide : public UIHeadUpDisplay
{
public:
    UIBuildBtnGuide();                                                          // 0x1418dcba0
    virtual ~UIBuildBtnGuide();                                                 // 0x1418dcc00, ??_G 0x1418dcf20
    virtual CString GetTypeName();                                                  //  1 0x1418dcc40
    virtual void vfunc_8(int nVisible);                                         //  8 0x1418dcdb0
    virtual void OnLoadComplete();                                              // 22 0x1418dcc90
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                // 28 0x1418dcd60
    virtual void vfunc_43();                                                    // 43 0x1418dccc0
    virtual int vfunc_48() { return 0x4e7f; }                                   // 48 (COMDAT 0x1418dcf60)

    void FUN_1418dcde0(int nGuide);                                             // show the guide of a key (0 hides)

private:
    int m_70;                                                                   // +0x70 the guide currently shown
};
MS2_CHECK_SIZE(UIBuildBtnGuide, 0x78);
