// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uimessageboxdata.h (name assumed: the
// .cpp's __FILE__ string is in the exe, the header's is not).
//
// CMsgBoxData (RTTI .?AVCMsgBoxData@@, 0x2a0 bytes, CPtred, one vftable slot): the data record of a message box (type,
// texts, buttons, timer, text input, item bags, check boxes, the extra GFx value map). CMsgBoxDataItem (0x50): one item
// bag entry. The ctor/dtor of CMsgBoxData sit in uimessagebox.cpp's range; this header only carries the layout and the
// members of uimessageboxdata.cpp. Names: FUN_<va> are non-virtual members; fields are m_<offset>-style names where the
// meaning is unknown.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include <map>

#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxvalue.h"

class ASObj;
class CItem;
class CMsgBoxData;
class ASDialog;
class IMessageListener;
class UIMessageBox;

// The remembered modaless box position (top left corner) and stage size, and whether a position was saved. The one
// instance (0x143af3df8) belongs to uimessagebox.cpp's static initializers; its ctor sits in this unit.
struct Unk_MsgPoint2
{
    float x;
    float y;
};
class Unk_MessageBoxStatic
{
public:
    Unk_MessageBoxStatic();                                         // 0x141a07570

    Unk_MsgPoint2 m_pos;                                            // +0x00
    Unk_MsgPoint2 m_stage;                                          // +0x08
    int m_bSaved;                                                   // +0x10
};
MS2_CHECK_OFFSET(Unk_MessageBoxStatic, m_bSaved, 0x10);

// One item entry of a message box item bag.
class CMsgBoxDataItem : public CPtred
{
public:
    CMsgBoxDataItem();                                              // 0x141a064e0
    virtual ~CMsgBoxDataItem();                                     // 0x141a06590 (??_G 0x141a07ce0)
    void FUN_141a06630(const CStringW& strName, bool bColor, int nColor);   // set the name (optionally coloured)

    int m_nCount;                                                   // +0x18 -1 ("itemCount")
    int m_nMax;                                                     // +0x1c -1
    int m_nPrice;                                                   // +0x20 -1
    int m_nUnitCount;                                               // +0x24 1
    CStringW m_strName;                                             // +0x28
    MS2Ptr<CItem> m_spItem;                                         // +0x30
    CString m_strBindId;                                            // +0x40 item slot bind id
    int m_48;                                                       // +0x48 0
};
MS2_CHECK_SIZE(CMsgBoxDataItem, 0x50);
MS2_CHECK_OFFSET(CMsgBoxDataItem, m_strName, 0x28);
MS2_CHECK_OFFSET(CMsgBoxDataItem, m_strBindId, 0x40);

// +0xa0: countdown / pressed-button record (0x58 bytes).
struct Unk_MsgBoxTimer
{
    Unk_MsgBoxTimer();                                              // 0x141a075f0
    ~Unk_MsgBoxTimer();                                             // 0x141a07810

    int m_nSec;                                                     // +0x00 seconds left (-1: none)
    int m_nMs;                                                      // +0x04
    int m_nShowFormat;                                              // +0x08 non-zero: send the "timer" text
    CStringW m_strFormat;                                           // +0x10
    int m_nButton;                                                  // +0x18 the pressed button
    int m_nArmed;                                                   // +0x1c -1 until the timer is armed
    Timer m_timer;                                                  // +0x20
};
MS2_CHECK_SIZE(Unk_MsgBoxTimer, 0x58);

// +0xf8: the buff shown by the buffNotify box types (ctor 0x140fa7be0 and dtor 0x140fa7d10 are outside this unit).
struct Unk_MsgBoxBuff
{
    Unk_MsgBoxBuff();
    ~Unk_MsgBoxBuff();

    int m_nId;                                                      // +0x00
    short m_nLevel;                                                 // +0x04
    CStringW m_strDesc;                                             // +0x08
    CStringW m_strExtra;                                            // +0x10
};
MS2_CHECK_SIZE(Unk_MsgBoxBuff, 0x18);

// +0x110: the text input settings (0x30 bytes).
struct Unk_MsgBoxInput
{
    Unk_MsgBoxInput();                                              // 0x141a074d0
    ~Unk_MsgBoxInput();                                             // 0x141a07790

    int m_nType;                                                    // +0x00 text type (FUN_141a06e80)
    int m_nMaxChars;                                                // +0x04 20
    int m_nMaxLine;                                                 // +0x08
    CStringW m_strDefault;                                          // +0x10
    int m_nShowLimit;                                               // +0x18
    CStringW m_strMaxLineMsg;                                       // +0x20
    CStringW m_strCountMsg;                                         // +0x28
};
MS2_CHECK_SIZE(Unk_MsgBoxInput, 0x30);

// +0x140: the two check boxes (0x18 bytes).
struct Unk_MsgBoxChecks
{
    Unk_MsgBoxChecks();                                             // 0x141a07430
    ~Unk_MsgBoxChecks();                                            // 0x141a07730

    CStringW m_strLabel0;                                           // +0x00
    CStringW m_strLabel1;                                           // +0x08
    bool m_bEnabled0;                                               // +0x10
    bool m_bEnabled1;                                               // +0x11
    bool m_bSelected0;                                              // +0x12
    bool m_bSelected1;                                              // +0x13
    bool m_bMust;                                                   // +0x14
};
MS2_CHECK_SIZE(Unk_MsgBoxChecks, 0x18);

// +0x158: the drop-down list entries (0x38 bytes).
struct Unk_MsgBoxChoices
{
    Unk_MsgBoxChoices();                                            // 0x141a07490
    ~Unk_MsgBoxChoices();                                           // 0x141a07760

    CStringW m_strDefault;                                          // +0x00
    ATL::CAtlList<CStringW> m_list;                                 // +0x08
};
MS2_CHECK_SIZE(Unk_MsgBoxChoices, 0x38);

// +0x190: the required items and their item slot bind ids (0x40 bytes).
struct Unk_MsgBoxItems
{
    Unk_MsgBoxItems();                                              // 0x141a075b0
    ~Unk_MsgBoxItems();                                             // 0x141a077e0

    ATL::CAtlArray<ItemEntity> m_items;                             // +0x00
    ATL::CAtlArray<CString> m_binds;                                // +0x20
};
MS2_CHECK_SIZE(Unk_MsgBoxItems, 0x40);

class CMsgBoxData : public CPtred
{
public:
    CMsgBoxData(int nType);                                         // 0x141a00db0 (uimessagebox.cpp's range)
    virtual ~CMsgBoxData();                                         // 0x141a01170 (??_G 0x141a07ca0)

    int FUN_141a034d0(ASObj& obj);                                  // fill the AS object the movie shows
    int FUN_141a04900();                                            // countdown still running (or none)
    int FUN_141a049a0() const;                                      // has a countdown
    int FUN_141a049d0() const;                                      // the countdown is over
    bool FUN_141a04a30();                                           // arm the movie when it has a priority object
    const Unk_MsgBoxTimer& FUN_141a04a80() const;                   // the pressed-button record
    bool FUN_141a04aa0();                                           // check box 0 state
    bool FUN_141a04c20();                                           // check box 1 state
    CStringW FUN_141a04da0();                                 // the text input's text
    void FUN_141a050b0();                                           // set the layout and the sound event
    void FUN_141a051e0(ASObj& obj);                                 // type specific members
    void FUN_141a05380(ASObj& obj);                                 // profile_ok
    void FUN_141a05470(ASObj& obj);                                 // groupEdit
    void FUN_141a05540(ASObj& obj);                                 // groupList
    void FUN_141a056f0(ASObj& obj);                                 // terms
    void FUN_141a05730(ASObj& obj);                                 // market_retract
    void FUN_141a05770(ASObj& obj);                                 // buffNotify
    void FUN_141a058c0(ASObj& obj);                                 // ugcterms
    void FUN_141a05930(ASObj& obj);                                 // itemlock_confirm
    void FUN_141a05bd0(ASObj& obj);                                 // itemCrafting
    void FUN_141a05f30(ASObj& obj);                                 // clubbuff
    void FUN_141a06250(ASObj& obj);                                 // input_reset
    void FUN_141a063e0(ASObj& obj);                                 // input_multi
    bool FUN_141a07140(unsigned int nIndex, CString& strOut) const; // the nIndex-th argument as a string
    bool FUN_141a071e0(unsigned int nIndex, bool& bOut) const;      // the nIndex-th argument as a bool

    // 0x141a01800 / 0x141a014d0 / 0x141a01480 / 0x141a03070 live in uimessagebox.cpp's range.
    void FUN_141a01800(int n);
    bool FUN_141a01480();
    bool FUN_141a014d0(int n, Scaleform::GFx::Value* pMovie);
    bool FUN_141a03070() const;
    int FUN_141a02e50(int nIndex, int nDefault) const;              // the nIndex-th argument as an int
    CStringW FUN_141a02fd0(int nIndex, CStringW strDefault) const;  // the nIndex-th argument as a string
    CStringW FUN_141a02d50() const;                                 // the +0x218 string (the text input's text)
    void FUN_141a01690(const CStringW& strBtn0, const CStringW& strBtn1, const CStringW& strBtn2);   // button texts
    void FUN_141a01d30(int nMode, const CStringW& strDefault, unsigned int nMax, int a4, int a5);    // text input setup
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb); // result callback
    void FUN_141a01600(__int64 n);                                  // uiugccubepalettedialog.cpp: the item uid
    void FUN_141a01620(int n);                                      // petmanager.cpp: the inventory slot argument
    void FUN_141a01ca0(int nButton, int nTime, const CStringW& strText);   // guildmanager.cpp: the auto-decline countdown
    void FUN_141a02460(int n);
    void FUN_141a02480(int n);
    void FUN_141a024a0(int n);
    void FUN_141a024c0();                                           // m_20f = true
    void FUN_141a02730(bool b);
    void FUN_141a02770(int nWidth, int nHeight);
    void FUN_141a01ee0(MS2Ptr<CItem> spItem, const CStringW& strName, int nA, int nB, int nC, int nD, int nE);   // item entry
    void FUN_141a01700(int nA, int nB, int nC);
    void FUN_141a01c70(const CStringW& str);
    void FUN_141a02670(bool b);
    void FUN_141a024e0(CStringW str, int n);
    void FUN_141a02560(CStringW str, int n);                        // the second choice text (skill window reset)
    void FUN_141a026f0(int n);                                      // choice mode (skill window reset)
    void FUN_140533ff0(int n);                                      // appends an int argument (COMDAT outside this class' range)
    void FUN_1405340b0(__int64 n);                                  // appends an __int64 argument (scenestategame.cpp, w97)
    void FUN_140534050(int n);                                      // appends an unsigned argument (Append<unsigned>; actionkeyobject.cpp)
    void FUN_141a02860(void* p);                                    // unit_140dfef30: the listener of the box (leaveInField)
    void FUN_140e01830(__int64 n);                                  // appends an __int64 argument as text (unit_140dfef30)
    void FUN_140b76940(CStringW str);                               // appends a string argument (the callee destroys it)

    // Accessors uimessagebox.cpp calls (0x141a01570-0x141a03470 and outside COMDATs).
    void FUN_141a01570(const CStringW& strMsg);                     // set the message text
    void FUN_141a01660(const CStringW& strTag);                     // set the tag (the micro game request boxes)
    void FUN_141a01540(const CStringW& strTag);                     // set the tag (uirevivaldialog.cpp)
    void FUN_141a015d0(const CStringW& str);                        // quest dispatch box: the sender name argument
    void FUN_141a02810(CStringW strTag);                            // the clicked tag (OnClick)
    const CString& FUN_141a02be0() const;                           // the sound event name
    __int64 FUN_141a02c00() const;                                  // the item uid
    __int64 FUN_141a02c20() const;                                  // the first __int64 argument (item uid of the remake)
    bool FUN_141a02e10(int nIndex, bool bDefault) const;            // the nIndex-th argument as a bool
    int FUN_141a02c40() const;                                      // keep the box open after the result
    int FUN_141a02c60() const;                                      // the storage slot
    int FUN_141a02c80() const;                                      // the inventory slot argument (set by FUN_141a01620)
    int FUN_141a02ca0() const;                                      // the box id
    IMessageListener* FUN_141a02cc0() const;                        // the listener
    const CStringW& FUN_141a02ce0() const;                          // the tag
    CStringW FUN_141a02b90() const;                                 // copy of the tag (messageboxqueue.cpp)
    const Delegate<bool(int, const CMsgBoxData&)>& FUN_141a02da0() const;  // the result callback
    CString FUN_141a02dc0() const;                                  // the hyper link url
    unsigned int FUN_141a02e90(int nIndex, unsigned int nDefault) const;    // the nIndex-th argument as an unsigned
    __int64 FUN_141a02ed0(int nIndex, int nDefault) const;          // the nIndex-th argument as an __int64
    __int64 FUN_141a02f10(int nIndex, __int64 nDefault) const;      // the nIndex-th argument as an __int64
    bool FUN_141a03050() const;
    bool FUN_141a03090() const;                                     // the enter key presses the default button
    bool FUN_141a030b0() const;                                     // a type with a default button
    bool FUN_141a03100() const;                                     // the escape key closes the box
    void FUN_141a03130(UIMessageBox* pBox, int nSec);               // OnChangeTime
    void FUN_141a03390(UIMessageBox* pBox);                         // OnPopupTimerComplete
    void FUN_141a03470();                                           // before closing
    static void FUN_141a04f80(MS2Ptr<ASDialog> spBox);              // remember the modaless box position
    bool FUN_140961900(unsigned int nIndex, int& nOut) const;       // the nIndex-th argument (COMDATs outside the range)
    bool FUN_140b19130(unsigned int nIndex, __int64& nOut) const;
    bool FUN_140b76a70(unsigned int nIndex, CStringW& strOut) const;
    bool FUN_140be25f0(unsigned int nIndex, int& nOut) const;
    bool FUN_140e01c50(unsigned int nIndex, __int64& nOut) const;
    // 0x141a00450 below: inline COMDAT, defined in uimessagebox.cpp
    bool FUN_141a00450(unsigned int nIndex, int& nOut) const;

    void* m_18;                                                     // +0x18 0
    int m_nType;                                                    // +0x20
    int m_24;                                                       // +0x24 -1
    unsigned int m_nId;                                             // +0x28
    void* m_30;                                                     // +0x30 0
    CStringW m_str38;                                               // +0x38
    CStringW m_strTitle;                                            // +0x40 "title"
    CStringW m_strMsg;                                              // +0x48 "msg"
    CStringW m_strMsg2;                                             // +0x50 "msg2"
    CStringW m_strExtra;                                            // +0x58 "extra"
    CStringW m_strBtn0;                                             // +0x60
    CStringW m_strBtn1;                                             // +0x68
    CStringW m_strBtn2;                                             // +0x70
    CStringW m_strStrike;                                           // +0x78
    MS2Ptr<CMsgBoxDataItem> m_spItem;                               // +0x80
    MS2Ptr<CMsgBoxDataItem> m_spItem2;                              // +0x90
    Unk_MsgBoxTimer m_timer;                                        // +0xa0
    Unk_MsgBoxBuff m_buff;                                          // +0xf8
    Unk_MsgBoxInput m_input;                                        // +0x110
    Unk_MsgBoxChecks m_checks;                                      // +0x140
    Unk_MsgBoxChoices m_choices;                                    // +0x158
    Unk_MsgBoxItems m_reqItems;                                     // +0x190
    int m_nWidth;                                                   // +0x1d0
    int m_nHeight;                                                  // +0x1d4
    CStringW m_strCharName;                                         // +0x1d8
    CStringW m_strCharDetail;                                       // +0x1e0
    CStringW m_strProfile;                                          // +0x1e8
    CStringW m_strLinkTitle;                                        // +0x1f0
    CString m_strLinkUrl;                                           // +0x1f8
    bool m_bAgreement;                                              // +0x200
    int m_nRetraction;                                              // +0x204
    unsigned int m_nFlags;                                          // +0x208
    bool m_20c;                                                     // +0x20c
    bool m_bModaless;                                               // +0x20d
    bool m_20e;                                                     // +0x20e
    bool m_20f;                                                     // +0x20f
    CString m_strSound;                                             // +0x210 sound event name
    CStringW m_str218;                                              // +0x218
    Delegate<bool(int, const CMsgBoxData&)> m_callback;             // +0x220
    ATL::CAtlArray<CStringW> m_args;                                // +0x228
    Scaleform::GFx::Value m_movie;                                  // +0x248
    CString m_strAlign[4];                                          // +0x268 left, center, right, justify
    int m_nAlign;                                                   // +0x288 4: none
    std::map<CString, Scaleform::GFx::Value> m_values;              // +0x290
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);
MS2_CHECK_OFFSET(CMsgBoxData, m_nType, 0x20);
MS2_CHECK_OFFSET(CMsgBoxData, m_spItem, 0x80);
MS2_CHECK_OFFSET(CMsgBoxData, m_timer, 0xa0);
MS2_CHECK_OFFSET(CMsgBoxData, m_buff, 0xf8);
MS2_CHECK_OFFSET(CMsgBoxData, m_input, 0x110);
MS2_CHECK_OFFSET(CMsgBoxData, m_checks, 0x140);
MS2_CHECK_OFFSET(CMsgBoxData, m_choices, 0x158);
MS2_CHECK_OFFSET(CMsgBoxData, m_reqItems, 0x190);
MS2_CHECK_OFFSET(CMsgBoxData, m_nFlags, 0x208);
MS2_CHECK_OFFSET(CMsgBoxData, m_strSound, 0x210);
MS2_CHECK_OFFSET(CMsgBoxData, m_callback, 0x220);
MS2_CHECK_OFFSET(CMsgBoxData, m_args, 0x228);
MS2_CHECK_OFFSET(CMsgBoxData, m_movie, 0x248);
MS2_CHECK_OFFSET(CMsgBoxData, m_strAlign, 0x268);
MS2_CHECK_OFFSET(CMsgBoxData, m_values, 0x290);
