// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uibeautylistdialog.h (name assumed: the
// class name; the exe has no assert path for it).
//
// UIBeautyListDialog (RTTI .?AVUIBeautyListDialog@@, UI type 0x4efe, swf "BeautyListDialog") is the beauty salon menu.
// The movie reports the picked service ("onClickHair" / "onClickColoring" / "onClickFace" = beauty type 1 / 5 / 3);
// the client then either asks the server to open it (opcode 0x23, sub 10) or, away from the salon maps, first shows the
// "go to map" warning whose answer sends the same packet. No fields of its own.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class CMsgBoxData;

class UIBeautyListDialog : public UIDialog
{
public:
    UIBeautyListDialog();                                       // 0x140f004b0 (FUN_141924170(1))
    virtual ~UIBeautyListDialog();                              //  0 0x140f00510 (??_G 0x140f00dc0)
    virtual CString vfunc_1();                                  //  1 0x140f00550 "BeautyListDialog"
    virtual void OnLoadComplete();                              // 22 0x140f005f0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140f00730
    virtual int vfunc_48() { return 0x4efe; }                   // 48 0x140f00e00
    virtual int vfunc_65();                                     // 65 0x140f005a0 (UIDialog::vfunc_65() != 0)
    virtual void vfunc_67();                                    // 67 0x140f005d0

    bool SendBeautyMode10(int nResult, const CMsgBoxData& box);    // the warning was answered: send the open packet
    int FUN_140f006b0(int nMapId);                              // nMapId is one of the three salon maps
};
MS2_CHECK_SIZE(UIBeautyListDialog, 0x178);
