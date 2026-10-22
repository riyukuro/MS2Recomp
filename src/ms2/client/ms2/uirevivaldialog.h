// uirevivaldialog.h - UIRevivalDialog (RTTI .?AVUIRevivalDialog@@, 0x1b8 bytes, UI id 0x4e38 "RevivalDialog"): the
// death dialog with the two revival buttons (btn1: revive with merat / on the spot, btn2: with meso) and the
// "return to the town" box. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\uirevivaldialog.cpp` (0x141aba6a0-0x141abe1d0 .text$mn, dir client\ms2). File name assumed (the class name; the
// exe has no assert path for it). FUN_<va> are non-virtual members; the m_<off> member names are invented.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Primary vftable + IMessageListener-in-UIRevivalDialog at +0x18.
// Overridden slots: 0, 1 (class name), 13, 22 (OnLoadComplete), 28, 43, 48 (0x4e38), 67, 72, IMessageListener 0.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"

class CMsgBoxData;
class Unk_RevCheck;
class Unk_RevFieldRef;

// A throttle with a 64-bit millisecond tick (ctor 0x140517b00).
class Unk_RevTick
{
public:
    Unk_RevTick();                                                  // 0x140517b00
    int FUN_140268870(unsigned ms);                                 // true once the interval elapsed
private:
    unsigned __int64 m_tick;
};
MS2_CHECK_SIZE(Unk_RevTick, 8);

class UIRevivalDialog : public UIDialog
{
public:
    UIRevivalDialog();                                              // 0x141aba6a0
    virtual ~UIRevivalDialog();                                     //  0 0x141aba7b0 (??_G 0x141abdf20)
    virtual CString GetTypeName();                                      //  1 0x141aba800
    virtual int vfunc_13();                                         // 13 0x141ababd0
    virtual void OnLoadComplete();                                  // 22 0x141aba850
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141abac00
    virtual void vfunc_43();                                        // 43 0x141abab30
    virtual int vfunc_48() { return 0x4e38; }                       // 48 (COMDAT 0x141abdf60)
    virtual void vfunc_67();                                        // 67 0x141aba8c0
    virtual void vfunc_72();                                        // 72 0x141abace0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x141aba920

    bool SendRevivalMode1(int nResult, const CMsgBoxData& box);        // revive box answer (merat)
    void FUN_141abad30(int nButton);                                // "onRevival": dispatch the clicked button
    bool SendRevivalMode0(int nResult, const CMsgBoxData& box);        // town box answer
    void FUN_141abae20();                                           // "setData": the death message
    void FUN_141abb420();                                           // set up the button labels
    void FUN_141abb600();                                           // btn1 clicked: revive here / leave the field
    void FUN_141abbb20();                                           // btn1 clicked: merat revival
    void FUN_141abc080();                                           // btn2 clicked: meso revival
    bool FUN_141abc740();                                           // feature 0x5d.. (china flavour)
    int FUN_141abc770();                                            // the field's value (unused here)
    int FUN_141abc7f0();                                            // the meso revival is the player's only choice
    bool FUN_141abc930();                                           // the merat button is usable
    int FUN_141abc9d0();                                            // the coupon is checked and on
    bool FUN_141abcad0(__int64 nCost);                              // nCost <= the free revival limit
    bool FUN_141abcb10(__int64 nCost);                              // the player can pay nCost
    void FUN_141abcb90();                                           // m_1b4 = the payment kind
    void FUN_141abcc50();                                           // refresh the labels and the coupon
    void FUN_141abccb0();                                           // refresh the merat button
    void FUN_141abd290();                                           // refresh the meso button
    void FUN_141abd640();                                           // the coupon check box state
    CStringW FUN_141abd790();                                       // the first button label
    int FUN_141abdab0(Unk_RevFieldRef spField);                     // the revival is allowed in this field
    MS2Ptr<Unk_RevCheck> FUN_140e52670(const CString& strName);     // check box child lookup (UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                                      // +0x178 -1
    MS2Ptr<CMsgBoxData> m_180;                                      // +0x180 the open message box
    __int64 m_190;                                                  // +0x190 -1; the cost shown on the merat button
    __int64 m_198;                                                  // +0x198 the cost shown on the meso button
    int m_1a0;                                                      // +0x1a0
    int m_1a4;                                                      // +0x1a4
    Unk_RevTick m_1a8;                                              // +0x1a8 the refresh throttle
    int m_1b0;                                                      // +0x1b0 1: the first button leaves the field
    int m_1b4;                                                      // +0x1b4 payment kind: 0 none, 1 merat, 2 meso
};
MS2_CHECK_SIZE(UIRevivalDialog, 0x1b8);
MS2_CHECK_OFFSET(UIRevivalDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIRevivalDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIRevivalDialog, m_190, 0x190);
MS2_CHECK_OFFSET(UIRevivalDialog, m_1a8, 0x1a8);
MS2_CHECK_OFFSET(UIRevivalDialog, m_1b4, 0x1b4);
