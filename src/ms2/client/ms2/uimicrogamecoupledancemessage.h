// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Names of fields are invented.
// See uiheadupdisplay.h (base UIHeadUpDisplay): the couple-dance microgame's message pop-up, a HUD leaf whose
// ActionScript movie shows the microgame's start/result messages ("showMessage" / "showStageMessage").
#pragma once
#include "ms2/placeholder/uiheadupdisplay.h"

class UIMicroGameCoupleDanceMessage : public UIHeadUpDisplay {
public:
    UIMicroGameCoupleDanceMessage();                                                                        // @0x140e65990
    virtual ~UIMicroGameCoupleDanceMessage();                                                               // @0x140e659f0
    virtual CString GetTypeName();                                                                              // @0x140e65a30 "MicroGameCoupleDanceMessage"
    virtual void vfunc_2();                                                                                 // @0x140e65a80 show
    virtual void vfunc_3();                                                                                 // @0x140e65ac0 hide
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);      // @0x140e65bb0
    virtual void vfunc_43();                                                                                // @0x140e65b00 size the movie to the stage
    // @0x140e65f10
    virtual int vfunc_48() { return 0x4f72; }
    void FUN_140e65c00(CStringW strMessage, int nTime);                                                     // @0x140e65c00
    void FUN_140e65ce0(int nType, CStringW strMessage, int nTime);                                          // @0x140e65ce0
};
