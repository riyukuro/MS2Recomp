// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uitextpreviewdialog.h (name assumed: the
// class name; the exe has no assert path for it).
//
// UITextPreviewDialog is a preview window for localized text ("TextPreviewDialog", UI type 0x4eb7): two text inputs
// ("m_input1", "m_input2") and a button bar ("m_buttonBar"). "ReplaceReserveWord" runs the text it is given through the
// reserved-word filters and hands the result back to the movie; "OnDescriptionCheck" sends the main / tooltip
// description of every item of a table to the movie ("descriptionCheck"). RTTI .?AVUITextPreviewDialog@@, 0x1a8 bytes,
// vftables 0x142ef2e40 (84 slots) and 0x142ef30e8 (IMessageListener at +0x18).
// Names: virtuals are Ghidra's vfunc_<slot> where the base does so; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class Unk_TpInput;
class Unk_TpBar;

class UITextPreviewDialog : public UIDialog
{
public:
    UITextPreviewDialog();                                      // 0x141350cf0
    virtual ~UITextPreviewDialog();                             //  0 0x141351740 (??_G 0x141351850)
    virtual CString GetTypeName();                                  //  1 0x141350d90
    virtual void OnLoadComplete();                              // 22 0x141350de0 bind the controls
    virtual void vfunc_26();                                    // 26 0x141350f60 release the controls
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x1413511b0
    virtual int vfunc_48();                                     // 48 0x141351890
    virtual void vfunc_67();                                    // 67 0x141351190

    void FUN_141350fc0(unsigned int nIndex);                    // select button nIndex of the bar
    void FUN_141351050(CStringW strText);                       // set the text of input 1
    void FUN_1413510f0(CStringW strText);                       // set the text of input 2
    void OnDescriptionCheck();                                       // "OnDescriptionCheck"

    MS2Ptr<Unk_TpInput> FUN_140c26f60(const CString& strName);  // 0x140c26f60 input child lookup (a UIDialog member)
    MS2Ptr<Unk_TpBar> FUN_140c02870(const CString& strName);    // 0x140c02870 button bar child lookup

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_TpInput> m_178;                                  // +0x178 "m_input1"
    MS2Ptr<Unk_TpInput> m_188;                                  // +0x188 "m_input2"
    MS2Ptr<Unk_TpBar> m_198;                                    // +0x198 "m_buttonBar"
};
MS2_CHECK_SIZE(UITextPreviewDialog, 0x1a8);
MS2_CHECK_OFFSET(UITextPreviewDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UITextPreviewDialog, m_198, 0x198);
