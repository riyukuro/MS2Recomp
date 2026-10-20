// asdropdownmenu.h - PLACEHOLDER for ASDropdownMenu (RTTI .?AVASDropdownMenu@@, base ASButton, 0x88 bytes, vftable
// 0x143113d70: the dtor and slot 23 are overridden): the CLIK DropdownMenu wrapper. NOT an original header; the code is
// ?\asdropdownmenu.cpp (src/ms2/gfxui/asdropdownmenu.cpp, 0x1422df570-0x1422e07c0). Older units (gameoption.cpp,
// uimessenger.cpp, uiclosetdialog.cpp) carry unit-local copies with the same method names. The rows of the
// "dataProvider" array are AS objects; the select / remove helpers look a row up by one of its members.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asobj.h"

class ASDropdownMenu : public ASButton
{
public:
    ASDropdownMenu(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1422df570
    virtual ~ASDropdownMenu();                                      // 0 0x1422df5c0 (scalar deleting 0x1422e0780)
    virtual void vfunc_23();                                        // 23 0x1422dfb50 invalidateSelectedIndex()
    void FUN_1422df5f0(unsigned nRows);                             // set "menuRowCount"
    unsigned FUN_1422df620();                                       // "menuRowCount"
    void FUN_1422df690(int nIndex);                                 // set "selectedIndex"
    int FUN_1422df6c0();                                            // "selectedIndex"
    void FUN_1422df720(const Scaleform::GFx::Value& v);             // set "dataProvider"
    MS2Ptr<ASDataProvider> FUN_1422df770();                         // "dataProvider"
    void FUN_1422df7e0(const CStringW& strField);                   // set "labelField"
    CStringW FUN_1422df830();                                       // "labelField"
    void FUN_1422df8c0(const CStringW& strScrollBar);               // set "scrollBar"
    CStringW FUN_1422df910();                                       // "scrollBar"
    void FUN_1422df9a0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);   // add the "listIndexChange" listener
    void FUN_1422dfa20(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);                // remove it
    void FUN_1422dfa80(const CStringW& strTitle);                   // set "title"
    void FUN_1422dfad0();                                           // open()
    void FUN_1422dfb10();                                           // close()
    unsigned FUN_1422dfb90();                                       // the row count (0 without a data provider)
    void FUN_1422dfc10();                                           // remove every row
    void FUN_1422dfc70(const ASObj& row);                           // add a row
    void FUN_1422dfce0(const CStringW& strLabel);                   // add a row { label: strLabel }
    void FUN_1422dfda0(const CStringW& strLabel);                   // select the row labelled strLabel
    CStringW FUN_1422dfe00();                                       // the selected row's "label" ("" if none)
    void FUN_1422e0040(const CString& strField, int nValue);        // select the first row whose strField is nValue (*)
    void FUN_1422e01a0(const CString& strField, unsigned nValue);   // the same with an unsigned (*)
    void FUN_1422e0300(const CString& strField, const CStringW& strValue);   // select the first row whose strField is strValue
    void FUN_1422e0510(int nIndex);                                 // remove the row at nIndex
    void FUN_1422e0580(const CStringW& strLabel);                   // remove the first row labelled strLabel
    // (*) only string members are compared, as numbers (GetInt / GetUInt on a string value): what the exe does.

private:
    // AScript's child-object getter template (0x1422de460 for T = ASDataProvider), used by FUN_1422df770 only
    MS2Ptr<ASDataProvider> FUN_1422de460(const CString& strName);
};
MS2_CHECK_SIZE(ASDropdownMenu, 0x88);
