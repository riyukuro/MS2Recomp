// uiitemmultiopenboxdialog.h - UIItemMultiOpenBoxDialog (RTTI .?AVUIItemMultiOpenBoxDialog@@, 0x1a0 bytes, UIModalDialog,
// UI id 0x4f88, swf "ItemMultiOpenBoxDialog"): the modal dialog that opens several item boxes in a row. It shows the item
// ("setItem", "m_count" = opened / total), counts the boxes down as the server answers, and sends packet 0x1a (box id,
// slot, remaining count, key) when the open timer expires. Owning unit: ?\uiitemmultiopenboxdialog.cpp
// (0x140c3f350-0x140c3ff80). Header name assumed from the unit path; member names are inferred.
// vftable: IMessageListener part at +0x18 as in UIModalDialog.
#pragma once
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/gfxvalue.h"

class UIItemMultiOpenBoxDialog : public UIModalDialog
{
public:
    UIItemMultiOpenBoxDialog();                                 // 0x140c3f350
    virtual ~UIItemMultiOpenBoxDialog();                        //  0 0x140c3f410 (??_G 0x140c3fde0)
    virtual CString GetTypeName();                                  //  1 0x140c3f470 "ItemMultiOpenBoxDialog"
    virtual void vfunc_15();                                    // 15 0x140c3f8a0 send the open request once the timer ran out
    virtual void OnLoadComplete();                              // 22 0x140c3f600 show the item
    virtual void vfunc_26();                                    // 26 0x140c3f5e0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c3f810 "OnCancel"
    virtual int vfunc_48() { return 0x4f88; }                   // 48 0x140c3fe20
    virtual int vfunc_65();                                     // 65 0x140c3f5b0 Open (UIDialog::vfunc_65)
    virtual void vfunc_67();                                    // 67 0x140c3f4c0 Close

    void FUN_140c3f9d0(int nBoxId, int nSlot, CStringW strKey, int nCount);   // set the box to open and the count
    void FUN_140c3fa80(int nOpened, int nResult);               // an answer of the server: count down, report errors
    void FUN_140c3fca0();                                       // refresh the "m_count" text
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // 0x140bb4cf0 text field child lookup (a UIDialog member)

private:
    int m_180;                  // +0x180 item box id
    int m_184;                  // +0x184 slot (sent as a short)
    CStringW m_188;             // +0x188 key
    int m_190;                  // +0x190 total count
    int m_194;                  // +0x194 remaining count
    int m_198;                  // +0x198 send deadline (client ms clock; 0 = none)
    unsigned m_19c;             // +0x19c (left alone by this dialog; its own flag word, see FUN_140c3fe30)
};
MS2_CHECK_SIZE(UIItemMultiOpenBoxDialog, 0x1a0);
