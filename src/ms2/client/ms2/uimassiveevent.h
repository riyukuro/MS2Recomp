// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uimassiveevent.h (name assumed: the
// class name; the exe has no assert path for it).
//
// UIMassiveEvent (RTTI .?AVUIMassiveEvent@@, 0xb0 bytes) is the HUD popup of the "massive event" (UI type 0x4e4c): a
// message panel with a count-down ("m_counter" clip with a "time" child). Layout: UIHeadUpDisplay (0x70) + the
// UIStatusEventListener subobject at +0x70 + the count-down state and the two clips.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class ASMovieClip;
class CInPacket;

class UIMassiveEvent : public UIHeadUpDisplay, public UIStatusEventListener
{
public:
    UIMassiveEvent();                                               // 0x1419f55d0 (m_2c = 0x1e)
    virtual ~UIMassiveEvent();                                      //  0 0x1419f56b0 (??_G 0x1419f6f20)
    virtual CString GetTypeName();                                      //  1 0x1419f5740 "MassiveEvent"
    virtual void vfunc_2();                                         //  2 0x1419f5790 show unless the cinematic gate is on
    virtual void vfunc_3();                                         //  3 0x1419f57d0 hide
    virtual void vfunc_15();                                        // 15 0x1419f5a30 tick the count-down
    virtual void OnLoadComplete();                                  // 22 0x1419f5800 bind the clips
    virtual void vfunc_26();                                        // 26 0x1419f5a60 drop the clips
    virtual void vfunc_43();                                        // 43 0x1419f5920 scale the movie
    virtual int vfunc_48() { return 0x4e4c; }                       // 48 0x1419f6f60 UI type id

    void FUN_1419f5ab0();                                           // clear the stage
    void FUN_1419f5ae0(int nSeconds);                               // start the count-down
    void FUN_1419f5b30();                                           // show the remaining seconds
    void FUN_1419f5c80();                                           // play the count sound
    void FUN_1419f5dd0();                                           // count-down step
    void FUN_1419f5e90(CInPacket* pPacket);                         // the server's massive-event packet
    void FUN_1419f5fc0(CInPacket* pPacket);                         // sub 0: set the stage
    void FUN_1419f60a0(CInPacket* pPacket);                         // sub 7: event-introduce round
    void FUN_1419f6180(CInPacket* pPacket);                         // sub 3: message type 6
    void FUN_1419f6240(CInPacket* pPacket);                         // sub 1: message with a step number
    void FUN_1419f63d0(CInPacket* pPacket);                         // sub 4: string-id message with a step number
    void FUN_1419f6520(CInPacket* pPacket);                         // sub 5: message type 2
    void FUN_1419f65e0(CInPacket* pPacket);                         // sub 6: message type 1
    void FUN_1419f66a0(CInPacket* pPacket);                         // sub 2: message with a given type
    void FUN_1419f6790(CInPacket* pPacket);                         // sub 8: fixed message
    void FUN_1419f6810(int nSubType, CStringW& strText, int nDuration);   // show a message and play its sound
    void FUN_1419f6a70(int nSubType, CStringW strText, int nDuration);    // push a message panel
    void FUN_1419f6bc0(CStringW strText, int nStep, int nDuration, int nType);   // push a step message
    void FUN_1419f6df0(int nStage, int nA, int nB, int nC);         // set the stage
    void FUN_1419f6eb0();                                           // hide the panel

private:
    MS2_LAYOUT_FRIEND;
    unsigned int m_nRemain;                                         // +0x78 seconds left (0 = not counting)
    int m_nType;                                                    // +0x7c message type (1, 2)
    int m_80;                                                       // +0x80
    unsigned int m_nDeadline;                                       // +0x84 clock value (ms) at which the count ends
    MS2Ptr<ASMovieClip> m_spCounter;                                // +0x88 "m_counter"
    MS2Ptr<ASMovieClip> m_spTime;                                   // +0x98 "m_counter.time"
    unsigned char m_bStage;                                         // +0xa8
};
MS2_CHECK_SIZE(UIMassiveEvent, 0xb0);
MS2_CHECK_OFFSET(UIMassiveEvent, m_nRemain, 0x78);
MS2_CHECK_OFFSET(UIMassiveEvent, m_nDeadline, 0x84);
MS2_CHECK_OFFSET(UIMassiveEvent, m_spCounter, 0x88);
MS2_CHECK_OFFSET(UIMassiveEvent, m_spTime, 0x98);
MS2_CHECK_OFFSET(UIMassiveEvent, m_bStage, 0xa8);
