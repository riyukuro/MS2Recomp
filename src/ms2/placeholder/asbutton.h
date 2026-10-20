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
    ASButton(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422cdde0
    virtual ~ASButton();                                            // 0 0x1422ce470
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
};
MS2_CHECK_SIZE(ASButton, 0x88);

class ASCheckBox : public ASButton
{
public:
    ASCheckBox(const Scaleform::GFx::Value& v, int nMovieId);      // 0x1422ceac0
    virtual ~ASCheckBox();                                          // 0 0x1422ceb40
};
MS2_CHECK_SIZE(ASCheckBox, 0x88);
