// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIChangeJobEffect (RTTI .?AVUIChangeJobEffect@@, 0x78
// bytes), the HUD effect played when the player changes job ("ChangeJobEffect", UI type 0x4f6c): once the swf has
// loaded it pushes the job code and the localised "s_changejob_effect_text" to the movie ("setData"); the movie
// answers "onHide". Layout: UIHeadUpDisplay (0x70) + the UIStatusEventListener subobject at +0x70 (vptr only); no
// fields of its own. Header/unit name assumed (the class name).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class UIChangeJobEffect : public UIHeadUpDisplay, public UIStatusEventListener
{
public:
    UIChangeJobEffect();                                            // 0x140bd09e0
    virtual ~UIChangeJobEffect();                                   //  0 0x140bd0a50 (??_G 0x140bd0e40)
    virtual CString GetTypeName();                                      //  1 0x140bd0ab0 "ChangeJobEffect"
    virtual void OnLoadComplete();                                  // 22 0x140bd0b00
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140bd0b30 "onHide"
    virtual int vfunc_48();                                         // 48 0x140bd0e80 UI type id
};
MS2_CHECK_SIZE(UIChangeJobEffect, 0x78);

// Push the job code and text to the movie (0x140bd0bb0).
void FUN_140bd0bb0(UIChangeJobEffect* pEffect);
