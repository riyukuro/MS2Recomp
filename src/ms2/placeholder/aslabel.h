// aslabel.h - PLACEHOLDER for ASLabel (RTTI .?AVASLabel@@): the C++ wrapper of a GFx label component (a text clip
// created from a linkage name). NOT an original header. The exe allocates 0x88 bytes (0x1412a9644, uidungeonroomdialog:
// `new ASLabel("UIDungeonRoomLimitLabel", 2)`), so it adds no members to ASUIComponent. Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class ASLabel : public ASUIComponent
{
public:
    ASLabel(const Scaleform::GFx::Value& v, int nMovieId);         // 0x1422e4900
    ASLabel(CString strLinkage, int nMovieId);                      // 0x1422e4950 (the callee destroys the name)
    virtual ~ASLabel();                                             // 0 0x1422e49d0 (scalar deleting 0x1422e4f90)
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
    // recovered with ?\aslabel.cpp (src/ms2/gfxui/aslabel.cpp): the AS Label members
    void FUN_1422e4a00(const CString& strText);                     // set "text"
    void FUN_1422e4a50(const CStringW& strText);                    // set "text" (uiotherpetsystemdialog.cpp "m_title")
    CStringW FUN_1422e4aa0();                                       // "text"
    void FUN_1422e4b30(const CString& strText);                     // set "htmlText"
    void FUN_1422e4b80(const CStringW& strText);                    // set "htmlText"
    CStringW FUN_1422e4bd0();                                       // "htmlText"
    void FUN_1422e4c60(const CString& strAutoSize);                 // set "autoSize" ("none", ...)
    CString FUN_1422e4cb0();                                        // "autoSize"
    void FUN_1422e4d40(const CString& strText);                     // appendText
    void FUN_1422e4d90(const CStringW& strText);                    // appendText
    void FUN_1422e4de0(const CString& strHtml);                     // appendHtml
    void FUN_1422e4e30(const CStringW& strHtml);                    // appendHtml
    MS2Ptr<class ASTextField> FUN_1422e4e80();                     // the label's "textField"
    void FUN_1422e4ef0(int nBegin, int nEnd);                       // focus the label and select the text range
    void FUN_1422c6eb0();                                           // ASDisplayObject: remove from the parent clip
};
MS2_CHECK_SIZE(ASLabel, 0x88);
