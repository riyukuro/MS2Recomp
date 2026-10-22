// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiscenelogo.h (name assumed).
//
// UISceneLogo ("SceneLogo", RTTI .?AVUISceneLogo@@, 0xa8 bytes): the first scene (id 0x620000b): the logo / intro movie
// screen shown at start-up. It has no fields of its own. Names: virtuals are Ghidra's vfunc_<slot>.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uiscenemodeselect.h"            // UISceneEntity

class UISceneLogo : public UISceneEntity
{
public:
    UISceneLogo();                                              // 0x141ad03f0 (m_6c = 0x620000b)
    virtual ~UISceneLogo();                                     //  0 0x141ad0440 (??_G 0x141ad0610)
    virtual CString GetTypeName();                                  //  1 0x141ad0480 "SceneLogo"
    virtual void OnLoadComplete();                              // 22 0x141ad0510 start the intro movie and the first-run services
    virtual void vfunc_48(int n);                               // 48 0x141ad04d0 show
};
MS2_CHECK_SIZE(UISceneLogo, 0xa8);
