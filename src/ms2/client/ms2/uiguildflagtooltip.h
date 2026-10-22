// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiguildflagtooltip.h (name assumed:
// the class name; the exe has no assert path for it).
//
// UIGuildFlagTooltip is the tooltip over an image display object (guild flag / ranking portrait, UI type 0x4ea8):
// ShowTooltip(name) looks the interact object up by name and shows its caption with the guild trophy score
// ("showPvp"), the builder ranking ("showBuilder") or plain ("show"), depending on the image type; the per-frame update
// hides it again once the object leaves the screen. RTTI .?AVUIGuildFlagTooltip@@, 0x80 bytes (UIHeadUpDisplay 0x70 +
// shown flag + object name), vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class UIGuildFlagTooltip : public UIHeadUpDisplay
{
public:
    UIGuildFlagTooltip();                                       // 0x1412c3e60
    virtual CString GetTypeName();                                  //  1 0x1412c3ee0
    virtual void vfunc_3();                                     //  3 0x1412c3f30 (hide: forgets the object)
    virtual void vfunc_15();                                    // 15 0x1412c3f70 per-frame update
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x1412c3fc0
    virtual void vfunc_41(const Scaleform::GFx::Value& root);   // 41 0x1412c4660 movie loaded: m_30 = new ASGameEntity
    // @0x1412c4ba0
    virtual int vfunc_48() { return 0x4ea8; }                   // 48
    // The destructor is implicit (0x1412c4b30: ~CString(m_78), ~UIHeadUpDisplay), ??_G 0x1412c4b60.

    void FUN_1412c4050(const CString& strName);                 // show the tooltip of the named interact object
    void FUN_1412c45a0();                                       // hide the tooltip movie
    bool FUN_1412c46d0();                                       // move the movie over the object; false = off screen

private:
    MS2_LAYOUT_FRIEND;
    char m_70;                                                  // +0x70 the tooltip is shown
    CString m_78;                                               // +0x78 name of the interact object
};
MS2_CHECK_SIZE(UIGuildFlagTooltip, 0x80);
MS2_CHECK_OFFSET(UIGuildFlagTooltip, m_70, 0x70);
MS2_CHECK_OFFSET(UIGuildFlagTooltip, m_78, 0x78);
