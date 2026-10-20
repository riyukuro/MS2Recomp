// asbutton.h - PLACEHOLDER for ASButton (RTTI .?AVASButton@@, vftable 0x1432cee40) and ASCheckBox (RTTI .?AVASCheckBox@@,
// an ASButton, vftable 0x1432cf090): the ActionScript button / check box wrappers. NOT an original header. Both reuse the
// ASUIComponent slots 1-24 and add no virtuals; the exe allocates 0x88 bytes for either (0x140acc910, 0x140a57df0).
// Older units carry unit-local views of the same objects (Unk_140acd6e0, Unk_GpCheck, ...). Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/delegate.h"

class ASButton : public ASUIComponent
{
public:
    ASButton();                                                     // 0x1422cdda0 (a fresh button: ASUIComponent(2))
    ASButton(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422cdde0
    virtual ~ASButton();                                            // 0 0x1422cde30 (scalar deleting 0x1422ce470)
    // ASUIComponent's own slots (0x1422c7260 / 0x1422c7ec0-0x1422c80c0: invalidate(...), validateNow), redeclared here
    // because asuicomponent.h does not list them yet (astextinput.h declares slot 24 as vfunc_24(int)).
    virtual void vfunc_3(int nVisible);                             // 3 0x1422c7260
    virtual void vfunc_16();                                        // 16 0x1422c7ec0 invalidate()
    virtual void vfunc_17();                                        // 17 0x1422c7f00 invalidate("size")
    virtual void vfunc_18();                                        // 18 0x1422c7f40 invalidate("data")
    virtual void vfunc_19();                                        // 19 0x1422c7f80 invalidate("state")
    virtual void vfunc_20();                                        // 20 0x1422c7fc0 invalidate("settings")
    virtual void vfunc_21();                                        // 21 0x1422c8000 invalidate("renderers")
    virtual void vfunc_22();                                        // 22 0x1422c8040 invalidate("scrollBar")
    virtual void vfunc_23();                                        // 23 0x1422c8080 invalidate("selectedIndex")
    virtual void vfunc_24(bool bInvalidate);                        // 24 0x1422c80c0 validateNow (invalidate() first if set)
    // Registers the click callback; nUser comes back in Params (homed as a qword by the callee).
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onClick, int nUser);
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onClick, void* pUser);   // same callee, a pointer-sized user value (uidungeonroomdialog sub tabs)
    void FUN_1422ce1f0(int nMode);                                  // the button mode (uidungeonroomdialog: 2)
    void FUN_1422ce090(int bSelected);                              // set "selected"
    bool FUN_1422ce0e0();                                           // "selected"
    void FUN_1422cdf20(bool bVisible);                              // show the label (uidungeonsearchsettingdialog)
    void FUN_1422cdfb0(const CStringW& strText);                    // set the label text
    MS2Ptr<class ASTextField> FUN_1422ce400();                     // the label text field (uiclosetdialog.cpp)
    void FUN_1422cdf50(const CString& strLabel);                    // set the label from a "$key" text (uidungeonroomdialog)
    // Registers the click callback with a pointer-sized user value (Params::pUserData).
    void FUN_1422ce320(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onClick, void* pUser);
    // recovered with ?\asbutton.cpp (src/ms2/gfxui/asbutton.cpp): the remaining AS member accessors
    void FUN_1422cde60(int bAutoRepeat);                            // set "autoRepeat"
    int FUN_1422cdeb0();                                            // "autoRepeat" (as an int)
    CString FUN_1422ce000();                                        // the "label" text
    void FUN_1422ce140(int bToggle);                                // set "toggle"
    bool FUN_1422ce190();                                           // "toggle"
    // remove the "buttonClick" / "select" listener registered by FUN_1422ce240 / FUN_1422ce320
    void FUN_1422ce2c0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onClick);
    void FUN_1422ce3a0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onSelect);
};
MS2_CHECK_SIZE(ASButton, 0x88);

class ASCheckBox : public ASButton
{
public:
    ASCheckBox(const Scaleform::GFx::Value& v, int nMovieId);      // 0x1422ceac0
    virtual ~ASCheckBox();                                          // 0 0x1422ceb40
};
MS2_CHECK_SIZE(ASCheckBox, 0x88);
