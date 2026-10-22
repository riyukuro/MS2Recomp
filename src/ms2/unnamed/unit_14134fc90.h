// UIHouseDemolishDialog (RTTI .?AVUIHouseDemolishDialog@@, 0x188 bytes, UI id 0x4ea1, swf "HouseDemolishDialog"): the small
// panel of the cube build mode that shows how many buildings the player owns and the limit ("m_textField" / "m_textKey");
// the cube map information service shows and hides it (FUN_1413503b0 / FUN_141350440). Unit name assumed (the exe has no
// path for it). Member names inferred. w276.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ascript.h"

class NotifyObject;
class ASTextField;

// A throttle with a 64-bit millisecond tick (ctor 0x140517b00).
class Unk_DemolishTick {
public:
    Unk_DemolishTick();                     // 0x140517b00
    int FUN_140268870(unsigned ms);         // true once the interval elapsed
    void FUN_140268840();                   // reset
private:
    unsigned __int64 m_tick;
};
MS2_CHECK_SIZE(Unk_DemolishTick, 8);

class UIHouseDemolishDialog : public UIDialog
{
public:
    UIHouseDemolishDialog();                                    // 0x14134fc90
    virtual ~UIHouseDemolishDialog();                           //  0 0x14134fd40 (??_G 0x141350b70)
    virtual CString GetTypeName();                                  //  1 0x14134fd80 "HouseDemolishDialog"
    virtual void vfunc_15();                                    // 15 0x141350320 refresh after 300 ms when dirty
    virtual void OnLoadComplete();                              // 22 0x1413500a0
    virtual void vfunc_26();                                    // 26 0x14134fe70
    virtual void vfunc_43();                                    // 43 0x141350260
    virtual int vfunc_48() { return 0x4ea1; }                   // 48 (COMDAT 0x141350bb0)
    virtual void vfunc_67();                                    // 67 0x141350080
    virtual int vfunc_84();                                     // 84 0x14134fdd0 true when the dialog may be shown

    void Show();                                                // 0x1413503b0 FUN_1413503b0
    void Hide();                                                // 0x141350440 FUN_141350440
    void Refresh(const unsigned* pnFlags);                      // 0x141350490 1 = count text, 2 = title text
    void AddDirty(const unsigned* pnFlags);                     // 0x141350740
    void OnNotifyChangeGameOptionInput(NotifyObject* pNotify);  // 0x141350770
    void OnNotifyChangeUIBuildingCount(NotifyObject* pNotify);  // 0x141350810
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // text field child lookup (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    bool m_bShown;                                              // +0x178
    bool m_bRefreshed;                                          // +0x179 Refresh ran once
    unsigned m_nDirty;                                          // +0x17c pending Refresh flags
    Unk_DemolishTick m_tick;                                    // +0x180
};
MS2_CHECK_SIZE(UIHouseDemolishDialog, 0x188);
MS2_CHECK_OFFSET(UIHouseDemolishDialog, m_bShown, 0x178);
MS2_CHECK_OFFSET(UIHouseDemolishDialog, m_nDirty, 0x17c);
MS2_CHECK_OFFSET(UIHouseDemolishDialog, m_tick, 0x180);
