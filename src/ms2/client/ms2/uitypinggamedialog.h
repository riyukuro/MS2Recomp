// uitypinggamedialog.h - UITypingGameDialog (RTTI .?AVUITypingGameDialog@@, 0x200 bytes, UI id 0x4f89 "TypingGameDialog"): the key
// sequence mini game. The server-less game draws a random sequence of arrow-key digits (0..9), shows it through the movie's
// "setData", then checks every key press of the player against it ("successKeyInput" / "failKeyInput") before the countdown
// (a TriggerTimerDialog, UI id 0x4e95) runs out; the result goes to the server (opcode 0x2f). Recovered from MapleStory2.exe
// KMS2_DEV x64 (2022-04-13); the unit is `?\uitypinggamedialog.cpp` (0x1400dce30 .text$di, 0x140ee52f0-0x140ee7610 .text$mn,
// dir client\ms2). File name assumed (the class name). FUN_<va> are non-virtual members; the m_<off> names are invented.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Primary vftable plus the IMessageListener-in-UIxxx one at +0x18.
// Overridden slots: 0, 1 (class name), 13, 22 (OnLoadComplete), 28, 48 (0x4f89), 65, 67, 72; new slot 84.
#pragma once

#include <afx.h>
#include <utility>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/timer.h"

class UITypingGameDialog : public UIDialog
{
public:
    UITypingGameDialog();                                           // 0x140ee52f0
    virtual ~UITypingGameDialog();                                  //  0 0x140ee56b0 (??_G 0x140ee6c70)
    virtual CString GetTypeName();                                      //  1 0x140ee5730 "TypingGameDialog"
    virtual int vfunc_13();                                         // 13 0x140ee5780
    virtual void OnLoadComplete();                                  // 22 0x140ee58b0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ee5960
    virtual int vfunc_48() { return 0x4f89; }                       // 48 (COMDAT 0x140ee6cb0)
    virtual int vfunc_65();                                         // 65 0x140ee57f0
    virtual void vfunc_67();                                        // 67 0x140ee5880
    virtual void vfunc_72();                                        // 72 0x140ee5900
    virtual void vfunc_84();                                        // 84 0x140ee5850

    void FUN_140ee57b0(int nCount, int nLimitMs);                   // set the sequence length and the time limit
    void FUN_140ee5a20();                                           // draw a new sequence and show it ("setData")
    void OnShowNumberComplete();                                           // "OnShowNumberComplete": start the countdown
    void FUN_140ee5c10();                                           // check the key presses of this frame
    void FUN_140ee5fc0(bool bOn);                                   // the key hook modifier
    bool FUN_140ee5ff0(unsigned nDigit);                            // one of the two keys of the digit is pressed
    void SuccessGameProgress();                                           // report success to the server, close
    void FailGameProgress();                                           // report failure to the server, close
    void FUN_140ee6190(unsigned nLimitMs);                               // start / stop the countdown dialog
    void FUN_140ee6240();                                           // close the countdown dialog

private:
    MS2_LAYOUT_FRIEND;
    int m_nCount;                                                   // +0x178 4; the sequence length
    int m_nLimitMs;                                                 // +0x17c 10000; the time limit
    std::vector<std::pair<int, int> > m_keys;                       // +0x180 digit -> its two keys (10 entries)
    unsigned m_nKeyCount;                                           // +0x198 m_keys.size()
    std::vector<unsigned> m_answer;                                 // +0x1a0 the drawn sequence
    unsigned m_nIndex;                                              // +0x1b8 the next key to enter
    Timer m_timer;                                                  // +0x1c0 the time limit
    bool m_bPlaying;                                                // +0x1f8
};
MS2_CHECK_SIZE(UITypingGameDialog, 0x200);
MS2_CHECK_OFFSET(UITypingGameDialog, m_keys, 0x180);
MS2_CHECK_OFFSET(UITypingGameDialog, m_answer, 0x1a0);
MS2_CHECK_OFFSET(UITypingGameDialog, m_timer, 0x1c0);
MS2_CHECK_OFFSET(UITypingGameDialog, m_bPlaying, 0x1f8);
