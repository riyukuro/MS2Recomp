// uidebuggingdialog.h - UIDebuggingDialog (RTTI .?AVUIDebuggingDialog@@, 0x1d0 bytes, UI type 0x4eb0, swf
// "DebuggingDialog"): the NPC inspector of the debug client. "onClickChooseNPC" arms a 500 ms pick timer; while it runs,
// the mouse move handler (vfunc_33) casts a ray from the cursor, tests every npc of the map with the mesh UV picker and
// remembers the hit npc (m_nTargetId) with a marker effect (m_nMarkerId); the per-frame update (vfunc_72) shows the npc's
// name, state, animation and move speed in the dialog's text fields. Owning unit: ?\uidebuggingdialog.cpp. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the header name is assumed from the unit path, member names are invented.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/itempickinghelper.h"   // Unk_UVPickerPtr

class ASTextField;

class UIDebuggingDialog : public UIDialog
{
public:
    UIDebuggingDialog();                                        // 0x141284e00
    virtual ~UIDebuggingDialog();                               //  0 0x141284ea0 (??_G 0x1412862a0)
    virtual CString vfunc_1();                                  //  1 0x141284f30 "DebuggingDialog"
    virtual void OnLoadComplete();                              // 22 0x141284f80
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1412850c0
    virtual void vfunc_33(void* p, float fX, float fY);         // 33 0x141285130 mouse move: pick the npc under the cursor
    virtual int vfunc_48() { return 0x4eb0; }                   // 48 0x1412862e0
    virtual void vfunc_67();                                    // 67 0x141285690
    virtual void vfunc_72();                                    // 72 0x1412856d0 per-frame update

    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // 0x140bb4cf0 text field child lookup (a UIDialog member)
    void FUN_141286050(const CString& strName, const CStringW& strText);   // 0x141286050 set a text field
    void FUN_1412860c0();                                       // 0x1412860c0 forget the target and drop its marker effect
    void OnClickChooseNPC();                                       // 0x141286130 arm the pick timer (500 ms)
private:
    MS2_LAYOUT_FRIEND;
    int m_bPicking;                                             // +0x178 waiting for a click on an npc
    Timer m_timer;                                              // +0x180
    int m_nTargetId;                                            // +0x1b8 object id of the picked npc
    int m_nMarkerId;                                            // +0x1bc id of its marker effect
    Unk_UVPickerPtr m_spPicker;                                 // +0x1c0 the UV picker (created on load)
    int m_bClear;                                               // +0x1c8 the text fields are empty
};
MS2_CHECK_SIZE(UIDebuggingDialog, 0x1d0);
MS2_CHECK_OFFSET(UIDebuggingDialog, m_timer, 0x180);
MS2_CHECK_OFFSET(UIDebuggingDialog, m_nTargetId, 0x1b8);
MS2_CHECK_OFFSET(UIDebuggingDialog, m_spPicker, 0x1c0);
MS2_CHECK_OFFSET(UIDebuggingDialog, m_bClear, 0x1c8);
