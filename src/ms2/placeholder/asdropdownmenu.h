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
    void SetMenuRowCount(unsigned nRows);                             // set "menuRowCount"
    unsigned GetMenuRowCount();                                       // "menuRowCount"
    void SetSelectedIndex(int nIndex);                                 // set "selectedIndex"
    int GetSelectedIndex();                                            // "selectedIndex"
    void SetDataProvider(const Scaleform::GFx::Value& v);             // set "dataProvider"
    MS2Ptr<ASDataProvider> GetDataProvider();                         // "dataProvider"
    void SetLabelField(const CStringW& strField);                   // set "labelField"
    CStringW GetLabelField();                                       // "labelField"
    void SetScrollBar(const CStringW& strScrollBar);               // set "scrollBar"
    CStringW GetScrollBar();                                       // "scrollBar"
    void AddListIndexChangeHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);   // add the "listIndexChange" listener
    void RemoveListIndexChangeHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);                // remove it
    void SetTitle(const CStringW& strTitle);                   // set "title"
    void Open();                                           // open()
    void Close();                                           // close()
    unsigned GetItemCount();                                       // the row count (0 without a data provider)
    void ClearItems();                                           // remove every row
    void AddItemRow(const ASObj& row);                           // add a row
    void AddItemLabel(const CStringW& strLabel);                   // add a row { label: strLabel }
    void SelectItemByLabel(const CStringW& strLabel);                   // select the row labelled strLabel
    CStringW FUN_1422dfe00();                                       // the selected row's "label" ("" if none)
    void SelectByIntField(const CString& strField, int nValue);        // select the first row whose strField is nValue (*)
    void SelectByUIntField(const CString& strField, unsigned nValue);   // the same with an unsigned (*)
    void FUN_1422e0300(const CString& strField, const CStringW& strValue);   // select the first row whose strField is strValue
    void FUN_1422e0510(int nIndex);                                 // remove the row at nIndex
    void FUN_1422e0580(const CStringW& strLabel);                   // remove the first row labelled strLabel
    // (*) only string members are compared, as numbers (GetInt / GetUInt on a string value): what the exe does.
};
MS2_CHECK_SIZE(ASDropdownMenu, 0x88);
