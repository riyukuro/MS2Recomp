// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uismartpush.h (name assumed: the
// class name; the exe has no assert path for it).
//
// UISmartPush ("SmartPush", UI type 0x4ef7, RTTI .?AVUISmartPush@@, 0x70 bytes = UIHeadUpDisplay, no members) is the
// HUD strip of smart push suggestions: the manager adds a push (FUN_140fa3e20: id, text, icon, flags, active movie and
// event popup) and removes it again (FUN_140fa40c0) through the movie's "addPush" / "removePush".
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class CSmartPush;

class UISmartPush : public UIHeadUpDisplay
{
public:
    UISmartPush();                                              // 0x140fa3b10 (m_2c = 0xd)
    virtual ~UISmartPush();                                     //  0 0x140fa3b60 (??_G 0x140fa4130)
    virtual CString GetTypeName();                                  //  1 0x140fa3ba0 "SmartPush"
    virtual void vfunc_2();                                     //  2 0x140fa3dd0 show (the base's)
    virtual void vfunc_3();                                     //  3 0x140fa3df0 hide, tell the manager
    virtual void OnLoadComplete();                              // 22 0x140fa3bf0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fa3d00 "onSmartPush"
    virtual void vfunc_43();                                    // 43 0x140fa3c40 place the strip
    virtual int vfunc_48();                                     // 48 0x140fa4170 UI type id

    int FUN_140fa3e20(CSmartPush* pPush);                       // add a push to the movie (1 = added, 0 = movie not ready)
    int FUN_140fa40c0(int nId);                                 // remove a push from the movie
};
MS2_CHECK_SIZE(UISmartPush, 0x70);
