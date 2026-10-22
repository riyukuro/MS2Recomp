// uientereventfielddialog.h - UIEnterEventFieldDialog (RTTI .?AVUIEnterEventFieldDialog@@, 0x188 bytes, UI id 0x4f00): the
// "enter the event field" button that shows while the player is outside the event map; its "onEnterEventField" swf
// callback asks for a confirmation and sends packet 0x85. Header name assumed from the unit path
// (?\uientereventfielddialog.cpp, 0x140f3fb10-0x140f40ce0). Names invented from the callers. w276.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ascript.h"

class NotifyObject;
class CMsgBoxData;

// A millisecond throttle (ctor 0x140517b00; two dwords at an odd 4-byte offset).
class Unk_EnterTick {
public:
    Unk_EnterTick();                        // 0x140517b00
    int FUN_140268870(unsigned ms);         // true once the interval elapsed
    void FUN_140268840();                   // reset
private:
    unsigned m_a;
    unsigned m_b;
};
MS2_CHECK_SIZE(Unk_EnterTick, 8);

class UIEnterEventFieldDialog : public UIDialog
{
public:
    UIEnterEventFieldDialog();                                  // 0x140f3fb10
    virtual ~UIEnterEventFieldDialog();                         //  0 0x140f3fba0 (??_G 0x140f40a20)
    virtual CString GetTypeName();                                  //  1 0x140f3fbe0 "EnterEventFieldDialog"
    virtual void OnLoadComplete();                              // 22 0x140f3fc80
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140f3fd90
    virtual void vfunc_43();                                    // 43 0x140f3ffb0 keep the button next to the HUD minimap
    virtual int vfunc_48() { return 0x4f00; }                   // 48 (COMDAT 0x140f40a60)
    virtual int vfunc_65();                                     // 65 0x140f3fc50
    virtual void vfunc_67();                                    // 67 0x140f3fc30
    virtual void vfunc_72();                                    // 72 0x140f402a0 refresh every second

    void SetFieldId(int nFieldId);                              // 0x140f40320
    bool OnEnterConfirm(int nResult, const CMsgBoxData& data);  // 0x140f40340 sends packet 0x85 on "yes"
    void OnNotifyGameStart(NotifyObject* pNotify);              // 0x140f403a0 re-place the button
    void UpdateVisible();                                       // 0x140f403d0 show unless on the event field / a tutorial map

private:
    MS2_LAYOUT_FRIEND;
    int m_nFieldId;                                             // +0x178 the event field id
    Unk_EnterTick m_tick;                                       // +0x17c
};
MS2_CHECK_SIZE(UIEnterEventFieldDialog, 0x188);
MS2_CHECK_OFFSET(UIEnterEventFieldDialog, m_nFieldId, 0x178);
MS2_CHECK_OFFSET(UIEnterEventFieldDialog, m_tick, 0x17c);
