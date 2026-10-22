// uiheadupdisplay.h - PLACEHOLDER for UIHeadUpDisplay (RTTI .?AVUIHeadUpDisplay@@, 0x70 bytes), the base of ~35 HUD
// objects (UIMessageBox, UIUpperHpBar, UIMicroGame*, ...). NOT an original header. Base UIObject (uiobject.h).
// Primary vftable 0x142faffc0 (52 slots, no new ones), IMessageListener-in-UIHeadUpDisplay 0x142fb0168 (OnMessage
// not overridden). Ctor 0x141986b50, dtor 0x141986bc0 (??_G 0x141986d40). Its unit is ?\uiheadupdisplay.cpp
// (0x141986b50-0x141991700, 392 functions).
//
// Ownership: wave-1 foundation (docs/RECOVERY.md section 12): the slot list and layout are complete; unit agents
// may only append non-virtual member declarations to the marked section.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiobject.h"

class UIHeadUpDisplay : public UIObject
{
public:
    UIHeadUpDisplay();                                                      // 0x141986b50 (m_2c = 8)
    virtual ~UIHeadUpDisplay();                                             //  0 0x141986bc0 (??_G 0x141986d40)
    virtual CString GetTypeName();                                              //  1 0x141986c00 "HeadUpDisplay"
    virtual void vfunc_2();                                                 //  2 0x141986cc0 show: m_68 = 1; FUN_1422dbf00(m_2c, m_44, 0)
    virtual void vfunc_3();                                                 //  3 0x141986d00 hide: m_68 = 0; FUN_1422dc080()
    virtual void vfunc_41(const Scaleform::GFx::Value& root);               // 41 0x141986c50 m_30 = AS object of root (type m_28)
    virtual int vfunc_48() { return 0x4e67; }                               // 48 0x141986d80 (inline: emitted after ??_G)
    // ---- agents: append non-virtual UIHeadUpDisplay members below this line (sorted by address) ----
    int FUN_141986d30();                                                    // m_68 (shown)

protected:
    MS2_LAYOUT_FRIEND;
    int m_68;                           // +0x68 shown (vfunc_2 / vfunc_3)
};
MS2_CHECK_SIZE(UIHeadUpDisplay, 0x70);
MS2_CHECK_OFFSET(UIHeadUpDisplay, m_68, 0x68);
