// uiarcadetexteffectdialog.h - UIArcadeTextEffectDialog (RTTI .?AVUIArcadeTextEffectDialog@@, 0x180 bytes:
// UIDialog + the combo text), the arcade minigame's centre text ("ArcadeTextEffectDialog", UI type 0x4f82).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\uiarcadetexteffectdialog.cpp`
// (0x140ba7d90-0x140ba8280 .text$mn, dir client\ms2). Header/unit name assumed; the class has no __FILE__ string.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) -> UIObject -> UISwfEntity -> CPtred, IMessageListener. Primary
// vftable 0x142dec3e8 (84 slots), IMessageListener-in-UIArcadeTextEffectDialog 0x142dec690. Overridden slots: 1
// (class name), 22 (OnLoadComplete: show a text that is still pending), 43 (centre the movie root), 48 (UI type
// 0x4f82).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class CInPacket;

class UIArcadeTextEffectDialog : public UIDialog
{
public:
    UIArcadeTextEffectDialog();                                      // 0x140ba7d90
    virtual ~UIArcadeTextEffectDialog();                             //  0 0x140ba7e20 (??_G 0x140ba8230)
    virtual CString GetTypeName();                                       //  1 0x140ba7e80: "ArcadeTextEffectDialog"
    virtual void OnLoadComplete();                                   // 22 0x140ba7fa0 (show a pending text)
    virtual void vfunc_43();                                         // 43 0x140ba7ed0 (centre the movie root)
    virtual int vfunc_48();                                          // 48 0x140ba8270: 0x4f82
    void FUN_140ba7fe0(int nMode, CInPacket& packet);                // 0x140ba7fe0 mode 8: the combo text
    void FUN_140ba8160();                                            // 0x140ba8160 send m_strText to the swf
private:
    MS2_LAYOUT_FRIEND;
    CStringW m_strText;             // +0x178 the text the swf shows (empty hides it)
};
MS2_CHECK_SIZE(UIArcadeTextEffectDialog, 0x180);
MS2_CHECK_OFFSET(UIArcadeTextEffectDialog, m_strText, 0x178);
