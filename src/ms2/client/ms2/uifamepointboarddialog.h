// uifamepointboarddialog.h - UIFamePointBoardDialog (RTTI .?AVUIFamePointBoardDialog@@, 0x178 bytes, UIDialog, UI id
// 0x4f54, swf "FamePointBoardDialog"): the fame point board. One tab per fame alliance ("m_tab"); the selected
// alliance's name, grade, fame points and its log (the fame log lines with their date) are sent to the movie with
// "setData". Owning unit: ?\uifamepointboarddialog.cpp (0x140c15460-0x140c165e0, dir client\ms2); header name
// assumed from the unit path.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"

class Unk_FpTab;

class UIFamePointBoardDialog : public UIDialog
{
public:
    UIFamePointBoardDialog();                                   // 0x140c15460
    virtual ~UIFamePointBoardDialog();                          //  0 0x140c154d0 (??_G 0x140c16210)
    virtual CString GetTypeName();                                  //  1 0x140c15510 "FamePointBoardDialog"
    virtual void OnLoadComplete();                              // 22 0x140c15580 build the tabs
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140c155b0 onChangeTab
    virtual int vfunc_48() { return 0x4f54; }                   // 48 0x140c16310
    virtual void vfunc_67();                                    // 67 0x140c15560

    int FUN_140c156d0();                                        // any alliance of the table is open to the player
    void FUN_140c15780();                                       // rebuild the tabs
    void FUN_140c15a10(int nAlliance);                          // send the alliance's data to the movie

    MS2Ptr<Unk_FpTab> FUN_140c02870(const CString& strName);    // bind the tab strip
};
MS2_CHECK_SIZE(UIFamePointBoardDialog, 0x178);
