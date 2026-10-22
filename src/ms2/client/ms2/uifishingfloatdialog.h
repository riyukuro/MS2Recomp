// uifishingfloatdialog.h - UIFishingFloatDialog (RTTI .?AVUIFishingFloatDialog@@, 0x190 bytes: UIDialog 0x178 + two
// ints + the three sound handles), the float of the fishing minigame ("FishingFloatDialog", UI type 0x4ee7). It shows
// the key hint, the size and the rank of the fish, plays the bite / red / blue sound loops and rumbles the pad.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\uifishingfloatdialog.cpp` (0x140f43df0-
// 0x140f447d0 .text$mn + two static CStrings in .text$di). Header/unit name assumed (the class name; the exe has no
// assert path for it).
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Primary vftable plus the IMessageListener-in-UIxxx one at +0x18.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class Unk_FishPacket;

class UIFishingFloatDialog : public UIDialog
{
public:
    UIFishingFloatDialog();                                         // 0x140f43df0
    virtual ~UIFishingFloatDialog() = default;                      //  0 0x140f44760 (??_G 0x140f44780)
    virtual CString GetTypeName();                                      //  1 0x140f43ea0 "FishingFloatDialog"
    virtual int vfunc_13();                                         // 13 0x140f44180 fish-up key handling
    virtual void vfunc_15();                                        // 15 0x140f43ef0 (empty)
    virtual void OnLoadComplete();                                  // 22 0x140f43f20 push the texts, start the first sound
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x140f44280 float touch / in / out callbacks
    virtual void vfunc_43();                                        // 43 0x140f43f00
    virtual void vfunc_67();                                        // 67 0x140f44120 close: stop the sounds and the rumble
    virtual int vfunc_48();                                         // 48 0x140f447c0 UI type id

    void FUN_140f443d0(MS2Ptr<Unk_FishPacket> spInfo);              // remember the fish size and rank
    int FUN_140f44490();                                            // the movie's "getResult"
    void FUN_140f44520(int nSound);                                 // start sound loop 0..2
    void FUN_140f44650(int nSound);                                 // stop sound loop 0..2

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                          // +0x178 fish size
    int m_17c;                          // +0x17c fish rank
    int m_180[3];                       // +0x180 handles of the sound loops (0 = not playing)
    int m_pad_18c;
};
MS2_CHECK_SIZE(UIFishingFloatDialog, 0x190);
MS2_CHECK_OFFSET(UIFishingFloatDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIFishingFloatDialog, m_180, 0x180);
