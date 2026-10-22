// uihomeinsideoptiondialog.h - UIHomeInsideOptionDialog (RTTI .?AVUIHomeInsideOptionDialog@@, 0x178 bytes = UIDialog, UI id 0x4f7a,
// swf "HomeInsideOptionDialog"): the home interior option: three combo boxes (background, light, camera) filled from
// UgcHomeOptionData; "OnApply" asks for a confirmation, the confirmation sends the three selections (opcode 0x37). Owning unit:
// ?\uihomeinsideoptiondialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CMsgBoxData;

class UIHomeInsideOptionDialog : public UIDialog
{
public:
    UIHomeInsideOptionDialog();                                 // 0x140c27340
    virtual ~UIHomeInsideOptionDialog();                        //  0 0x140c273b0 (??_G 0x140c28820)
    virtual CString GetTypeName();                                  //  1 0x140c273f0 "HomeInsideOptionDialog"
    virtual void OnLoadComplete();                              // 22 0x140c27440
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c27af0
    virtual int vfunc_48() { return 0x4f7a; }                   // 48 0x140c28980

    bool FUN_140c27fd0(int nResult, const CMsgBoxData& box);    // 0x140c27fd0 confirm box answered: apply
    bool FUN_140c28000(int nResult, const CMsgBoxData& box);    // 0x140c28000 confirm box answered: apply and close
    void FUN_140c280d0();                                       // 0x140c280d0 send the three selections
    template <class T> MS2Ptr<T> FUN_140c28560(const CString& strName);   // 0x140c28560 bind a child of the movie
    MS2Ptr<class Unk_HioButton> FUN_140bb4b10(const CString& strName);   // 0x140bb4b10 bind a button child
};
MS2_CHECK_SIZE(UIHomeInsideOptionDialog, 0x178);
