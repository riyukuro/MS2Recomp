// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicameradialog.h (name assumed: the
// class name; the exe has no assert path for it).
//
// UICameraDialog is the camera tuning window ("CameraDialog", UI type 0x4eb6): sliders and inputs for the field of
// view, the minimum / maximum zoom distance and the near / far clip planes of the scene camera ("onChangeSliderFOV",
// "onClickReset", "onClickApplyMinDistance", "onClickApplyMaxDistance", "onClickApplyNearFar"). vfunc_72 refreshes
// the readouts (distance, angles, height offset). RTTI .?AVUICameraDialog@@, 0x178 bytes (no members of its own),
// vftables 0x142ea0e98 (84 slots) and 0x142ea1140 (IMessageListener at +0x18).
// Names: virtuals are Ghidra's vfunc_<slot> where the base does so; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASData;
class ASTextField;
class Unk_CdInput;
struct Unk_CdInputRef { void* m_0; void* m_8; };               // the layout of an MS2Ptr

class UICameraDialog : public UIDialog
{
public:
    UICameraDialog();                                           // 0x141031f80
    virtual ~UICameraDialog();                                  //  0 0x141031fd0 (??_G 0x141032d00)
    virtual CString GetTypeName();                                  //  1 0x141032010
    virtual void OnLoadComplete();                              // 22 0x141032060 initData from the camera
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x141032120
    virtual int vfunc_48();                                     // 48 0x141032e50
    virtual void vfunc_72();                                    // 72 0x1410323f0 refresh the readouts

    void FUN_141032560(const CString& strName, float f);        // show f in the text field strName
    void FUN_141032610(const CString& strName, float f);        // show f in the input strName
    void FUN_1410326e0(ASData& data);                           // "onChangeSliderFOV"
    void FUN_141032780(ASData& data);                           // "onClickReset"
    void FUN_1410328d0(ASData& data);                           // "onClickApplyNearFar"
    void FUN_141032970(ASData& data);                           // "onClickApplyMaxDistance"
    void FUN_141032a90(ASData& data);                           // "onClickApplyMinDistance"

    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // 0x140bb4cf0 text field child lookup (a UIDialog member)
    Unk_CdInputRef FUN_140e35bd0(const CString& strName);       // 0x140e35bd0 input child lookup (a shared GetChild instance)
};
MS2_CHECK_SIZE(UICameraDialog, 0x178);
