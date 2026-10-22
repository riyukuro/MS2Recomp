// uiobservedialog.h - UIObserveDialog (RTTI .?AVUIObserveDialog@@, 0x188 bytes: UIDialog + the observed player's name),
// the observer-mode HUD ("ObserveDialog", UI type 0x4e8a). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13);
// the unit is `?\uiobservedialog.cpp` (0x141a732e0-0x141a738f0 .text$mn, dir client\ms2). Header/unit name assumed.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Primary vftable plus the IMessageListener-in-UIObserveDialog one at
// +0x18. Overridden slots: 1 (class name), 20 (OnLoadInit), 22 (OnLoadComplete), 13, 28, 48 (UI type 0x4e8a), 67.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIObserveDialog : public UIDialog
{
public:
    UIObserveDialog();                                               // 0x141a732e0
    virtual ~UIObserveDialog() = default;                                   //  0 0x141a73750 (??_G 0x141a73780)
    virtual CString GetTypeName();                                       //  1 0x141a73360: "ObserveDialog"
    virtual int vfunc_13();                                          // 13 0x141a734d0
    virtual void OnLoadInit();                                       // 20 0x141a733b0
    virtual void OnLoadComplete();                                   // 22 0x141a733e0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                     // 28 0x141a73540
    virtual int vfunc_48();                                          // 48 0x141a737c0: 0x4e8a
    virtual void vfunc_67();                                         // 67 0x141a73580
    void FUN_141a735c0();                                            // 0x141a735c0 empty
    void FUN_141a735d0(CStringW strName);                            // 0x141a735d0 the observed player's name (by value: destroyed here)
    void FUN_141a736c0(bool bCenterCamera);                          // 0x141a736c0 clear the name, swf "SetCenterCamera"
private:
    MS2_LAYOUT_FRIEND;
    CStringW m_strName;             // +0x178 observed player's name
    bool m_bCenterCamera;           // +0x180
};
MS2_CHECK_SIZE(UIObserveDialog, 0x188);
MS2_CHECK_OFFSET(UIObserveDialog, m_strName, 0x178);
MS2_CHECK_OFFSET(UIObserveDialog, m_bCenterCamera, 0x180);
