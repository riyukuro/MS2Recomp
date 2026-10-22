// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uitoplayernotify.h (name assumed:
// the class name; the exe has no assert path for it).
//
// UITopLayerNotify is the top layer message banner ("TopLayerNotify", UI type 0x4ef5): ShowMessage pushes
// "showMessage"(text, type) to the movie, or remembers the text until the movie is loaded; "onHideMessage" hides it.
// RTTI .?AVUITopLayerNotify@@, 0x80 bytes (UIHeadUpDisplay 0x70 + the pending text and type), vftables at +0 and +0x18
// (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class UITopLayerNotify : public UIHeadUpDisplay
{
public:
    UITopLayerNotify();                                         // 0x140fa8640
    virtual ~UITopLayerNotify();                                //  0 0x140fa86c0 (??_G 0x140fa8b50)
    virtual CString GetTypeName();                                  //  1 0x140fa8710
    virtual void vfunc_2();                                     //  2 0x140fa8760
    virtual void vfunc_3();                                     //  3 0x140fa8780 (hide: forgets the pending text)
    virtual void OnLoadComplete();                              // 22 0x140fa87c0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140fa88f0
    virtual void vfunc_43();                                    // 43 0x140fa8820
    virtual int vfunc_48() { return 0x4ef5; }                   // 48 0x140fa8b90

    void FUN_140fa8970(const CStringW& strText, int nType);     // show the message (now, or once the movie is loaded)

private:
    MS2_LAYOUT_FRIEND;
    CStringW m_70;                                              // +0x70 pending text
    int m_78;                                                   // +0x78 pending type
};
MS2_CHECK_SIZE(UITopLayerNotify, 0x80);
MS2_CHECK_OFFSET(UITopLayerNotify, m_70, 0x70);
MS2_CHECK_OFFSET(UITopLayerNotify, m_78, 0x78);
