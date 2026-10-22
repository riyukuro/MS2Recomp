// uidebugpacketdialog.h - UIDebugPacketDialog (RTTI .?AVUIDebugPacketDialog@@, 0x380 bytes, UI type 0x4ecc, swf
// "DebugPacketDialog"): the GM packet tester. The swf has a fixed packet (id, loop count, loop delay, five typed
// parameters: none / 1 / 2 / 4 / 8 byte / string) that the "execute" button builds and sends, and a random mode (packet
// id range, random payload length, count, delay). Two check boxes toggle the "/PacketCounter" chat command and the
// "/CloseFromPacket" chat command. The sending runs from the per-frame slot 72. Recovered from MapleStory2.exe KMS2_DEV
// x64 (2022-04-13); the unit is `?\uidebugpacketdialog.cpp` (dir client\ms2). Header name and member names assumed.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uidialog.h"

class ASMovieClip;
class ASTextField;
class Unk_DpButton;
class Unk_DpInput;
class Unk_DpCombo;
class Unk_DpCheck;

// The random packet id range (min, max): Get() returns a random id in the range.
struct Unk_DpRange
{
    Unk_DpRange();                                              // 0x1405c38a0
    void FUN_1405c6380(int nMin, int nMax);                     // set the range
    int FUN_141291f20();                                        // 0x141291f20 a random value of the range
    int m_nMin;
    int m_nMax;
};
MS2_CHECK_SIZE(Unk_DpRange, 8);

class UIDebugPacketDialog : public UIDialog
{
public:
    UIDebugPacketDialog();                                      // 0x14128f8f0
    virtual ~UIDebugPacketDialog();                             //  0 0x141291cd0 (??_G 0x141291ee0)
    virtual CString GetTypeName();                                  //  1 0x14128fb80
    virtual void OnLoadInit();                                  // 20 0x14128fbd0
    virtual void vfunc_26();                                    // 26 0x141290c90
    virtual void OnLoadComplete();                              // 22 0x141290d80
    virtual int vfunc_48() { return 0x4ecc; }                   // 48 (COMDAT 0x141291f70)
    virtual void vfunc_72();                                    // 72 0x141290e20 send the queued packets

    void OnExecute(const Scaleform::GFx::FunctionHandler::Params& rParams);         // 0x1412911e0
    void OnExecuteRandom(const Scaleform::GFx::FunctionHandler::Params& rParams);   // 0x141291210
    void OnPacketCount(const Scaleform::GFx::FunctionHandler::Params& rParams);     // 0x141291240
    void OnCloseFromPacket(const Scaleform::GFx::FunctionHandler::Params& rParams); // 0x141291340
    void OnDoubleClick(const Scaleform::GFx::FunctionHandler::Params& rParams);     // 0x141291440
    int FUN_141291470();                                        // 0x141291470 read the fixed packet and arm the loop
    bool FUN_141291850();                                       // 0x141291850 read the random mode and arm it
    MS2Ptr<Unk_DpButton> FUN_140bb4b10(const CString& strName);     // 0x140bb4b10 bind a button child (a UIDialog member)
    MS2Ptr<Unk_DpInput> FUN_140e35bd0(const CString& strName);      // 0x140e35bd0 text input child lookup
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);      // 0x140ba7930 bind a movie clip child
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);      // 0x140bb4cf0 text field child lookup
    MS2Ptr<Unk_DpCheck> FUN_140e52670(const CString& strName);      // 0x140e52670 check box child lookup

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_DpButton> m_178;                                 // +0x178 (never bound)
    MS2Ptr<Unk_DpButton> m_execute;                             // +0x188 "m_execute"
    MS2Ptr<Unk_DpInput> m_id;                                   // +0x198 "m_id"
    MS2Ptr<Unk_DpInput> m_loopCount;                            // +0x1a8 "m_loopCount"
    MS2Ptr<Unk_DpInput> m_loopDelay;                            // +0x1b8 "m_loopDelay"
    MS2Ptr<Unk_DpInput> m_value[5];                             // +0x1c8 "m_param<n>.m_value"
    MS2Ptr<Unk_DpCombo> m_type[5];                              // +0x218 "m_param<n>.m_type"
    MS2Ptr<ASMovieClip> m_movie;                                // +0x268 (double click)
    COutPacket m_packet;                                        // +0x278 the fixed packet
    int m_nRemain;                                              // +0x2b0 sends left
    int m_nDelay;                                               // +0x2b4
    unsigned int m_nNext;                                       // +0x2b8 time of the next send
    int m_nId;                                                  // +0x2bc packet id
    MS2Ptr<Unk_DpButton> m_executeRandom;                       // +0x2c0 "m_executeRandom"
    MS2Ptr<Unk_DpInput> m_randomStart;                          // +0x2d0 "m_randomStart"
    MS2Ptr<Unk_DpInput> m_randomEnd;                            // +0x2e0 "m_randomEnd"
    MS2Ptr<Unk_DpInput> m_randomLoopCount;                      // +0x2f0 "m_randomLoopCount"
    MS2Ptr<Unk_DpInput> m_randomLoopDelay;                      // +0x300 "m_randomLoopDelay"
    MS2Ptr<Unk_DpInput> m_randomLoopLength;                     // +0x310 "m_randomLoopLength"
    MS2Ptr<ASTextField> m_randomRemain;                         // +0x320 "m_randomRemain"
    MS2Ptr<Unk_DpCheck> m_ignoreAdminPacket;                    // +0x330 "m_ignoreAdminPacket"
    MS2Ptr<Unk_DpButton> m_usePacketCount;                      // +0x340 "m_usePacketCount"
    MS2Ptr<Unk_DpButton> m_usePostClose;                        // +0x350 "m_usePostClose"
    Unk_DpRange m_range;                                        // +0x360 random packet ids
    int m_nRandomRemain;                                        // +0x368
    int m_nRandomLength;                                        // +0x36c
    int m_nRandomDelay;                                         // +0x370
    unsigned int m_nRandomNext;                                 // +0x374
    bool m_bPacketCounter;                                      // +0x378
    bool m_bCloseFromPacket;                                    // +0x379
};
MS2_CHECK_SIZE(UIDebugPacketDialog, 0x380);
MS2_CHECK_OFFSET(UIDebugPacketDialog, m_packet, 0x278);
MS2_CHECK_OFFSET(UIDebugPacketDialog, m_executeRandom, 0x2c0);
MS2_CHECK_OFFSET(UIDebugPacketDialog, m_range, 0x360);
