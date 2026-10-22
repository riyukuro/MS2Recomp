// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uidialogcenterdialog.h (name assumed:
// the exe has no __FILE__ string for this unit).
//
// UIDialogCenterDialog ("DialogCenterDialog", UI type 0x4ea9, 0x240 bytes): the debug "center" menu. OnLoadComplete
// builds a grid of buttons (column / row -> a "UIDialogCenterDialog_btn" clip) whose labels are "$s_debug_ui_center_menu_*"
// keys; a button either opens the dialog stored in its "dialogID" member (FUN_141295930) or runs a delegate (the trigger
// debug window, the blueprint dialog, the wedding hall reservation ...). Packet 0x87 kind 10 tells a trigger debug
// window (by lower-cased xml path) which dialog id to show.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/client/ms2/uidialog.h"

class Unk_140acd6e0;
class TriggerDebugDialog;

class UIDialogCenterDialog : public UIDialog
{
public:
    UIDialogCenterDialog();                             // 0x141294100
    virtual ~UIDialogCenterDialog();                    //  0 0x141294200 (??_G 0x1412972d0)
    virtual CString vfunc_1();                          //  1 0x141294290 "DialogCenterDialog"
    virtual void OnLoadComplete();                      // 22 0x1412942e0
    virtual void vfunc_26();                            // 26 0x141295730 release the buttons
    virtual int vfunc_48() { return 0x4ea9; }           // 48 0x1412976f0 UI type id
    virtual void vfunc_79(void* p);                     // 79 0x141295770 packet 0x87

    void FUN_141295930(const Scaleform::GFx::FunctionHandler::Params& params);  // a button: open its "dialogID" dialog
    void FUN_141295a70(const Scaleform::GFx::FunctionHandler::Params& params);  // menu: visual tracker
    void FUN_141295ad0(const Scaleform::GFx::FunctionHandler::Params& params);  // menu: log dialog
    void FUN_141295b00(const Scaleform::GFx::FunctionHandler::Params& params);  // menu: create blueprint
    void FUN_141295b30(const Scaleform::GFx::FunctionHandler::Params& params);  // menu: wedding hall reservation
    void FUN_141295bb0(const Scaleform::GFx::FunctionHandler::Params& params);  // menu: wedding hall change
    void FUN_141295c30(const Scaleform::GFx::FunctionHandler::Params& params);  // menu: wedding hall cancel
    void FUN_141295cb0(const Scaleform::GFx::FunctionHandler::Params& params);  // menu: trigger debug (pick an xml)
    CString FUN_1412965f0(CString strInitialDir, const char* pszFilter);   // GetOpenFileName in a directory
    void SendSetDebugModeMode9(CString strPath);                // close the trigger debug window of a path
    MS2Ptr<Unk_140acd6e0> FUN_141296150(int nRow, int nColumn, CStringW strLabel);   // create the button of a grid cell
    void FUN_141296370(int nRow, int nColumn, CString strKey, int nDialogId);        // a button that opens a dialog
    void FUN_141296500(int nRow, int nColumn, CString strKey, Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb);   // a button with a callback

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<Unk_140acd6e0> > m_buttons;   // +0x178
    ATL::CAtlMap<CString, unsigned __int64> m_map;      // +0x198
    CLockCriticalSection m_lock;                        // +0x1e0
    ATL::CRBMap<CString, MS2Ptr<TriggerDebugDialog>, ATL::CStringElementTraitsI<CString> > m_triggers;   // +0x210 lower-cased xml path -> window
};
MS2_CHECK_SIZE(UIDialogCenterDialog, 0x240);
