// uiarcadelifebar.h - UIArcadeLifeBar (RTTI .?AVUIArcadeLifeBar@@, 0x190 bytes: UIDialog + the life state), the arcade
// minigame's life counter ("ArcadeLifeBar", UI type 0x4efc). Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `?\uiarcadelifebar.cpp` (0x140ef4f10-0x140ef5640 .text$mn, dir client\ms2). Header/unit
// name assumed; the class has no __FILE__ string.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Primary vftable plus the IMessageListener-in-UIArcadeLifeBar one
// at +0x18. Overridden slots: 1 (class name), 22 (OnLoadComplete: send a pending "init"), 43 (position the movie
// root), 48 (UI type 0x4efc).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

#include <NiPoint2.h>

class CInPacket;

class UIArcadeLifeBar : public UIDialog
{
public:
    UIArcadeLifeBar();                                               // 0x140ef4f10
    virtual ~UIArcadeLifeBar();                                      //  0 0x140ef4ff0 (??_G 0x140ef54d0)
    virtual CString GetTypeName();                                       //  1 0x140ef5030: "ArcadeLifeBar"
    virtual void OnLoadComplete();                                   // 22 0x140ef5160
    virtual void vfunc_43();                                         // 43 0x140ef5080 (position the movie root)
    virtual int vfunc_48();                                          // 48 0x140ef5510: 0x4efc
    void FUN_140ef51e0(int nMode, CInPacket& packet);                // 0x140ef51e0 mode 5: all three values, 6: life only
    void FUN_140ef5320(int nLife, int nMaxLife);                     // 0x140ef5320
    void FUN_140ef5370(int nInit, int nLife, int nMaxLife);          // 0x140ef5370
    void FUN_140ef53f0(int nX, int nY);                              // 0x140ef53f0 the movie root position
    void FUN_140ef5430();                                            // 0x140ef5430 send "setlife"
private:
    MS2_LAYOUT_FRIEND;
    int m_nInit;                    // +0x178 value for the swf's "init" (sent when the movie finishes loading)
    int m_nLife;                    // +0x17c
    int m_nMaxLife;                 // +0x180
    NiPoint2 m_pos;                 // +0x184 position of the movie root
};
MS2_CHECK_SIZE(UIArcadeLifeBar, 0x190);
MS2_CHECK_OFFSET(UIArcadeLifeBar, m_nInit, 0x178);
MS2_CHECK_OFFSET(UIArcadeLifeBar, m_pos, 0x184);
