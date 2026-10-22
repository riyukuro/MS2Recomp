// autofindtaxistation.h - CAutoFindTaxiStation (RTTI .?AVCAutoFindTaxiStation@@): the "auto find taxi station" helper.
// While active it moves the camera towards the taxi station found through the world service and sends a 0x48 packet.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); unit `?\autofindtaxistation.cpp`
// (0x1409f11a0-0x1409f2670). Header name assumed; member names are invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

// size 0x18: TSingleton<> (vftable only) then four int flags.
class CAutoFindTaxiStation : public TSingleton<CAutoFindTaxiStation>
{
public:
    CAutoFindTaxiStation();                     // 0x1409f11a0
    virtual ~CAutoFindTaxiStation();            // 0x1409f1210

    void FUN_1409f1240();                       // request / schedule the search (called from FUN_1409f1cb0)
    void FUN_1409f1450();                       // search timer callback: start the camera flight
    void SendRequestTaxiMode5();                       // send the 0x48/5 packet and arm the 5 s timeout
    void FUN_1409f1970();                       // arm the 1500 ms step
    void FUN_1409f1a00();                       // timeout: mark done and reset
    void FUN_1409f1a70();                       // cancel / reset the state
    void FUN_1409f1af0();                       // second camera step
    int FUN_1409f1cb0();                       // per-frame update; true if it consumed the request
    void FUN_1409f1de0();                       // clear all four flags
    void FUN_1409f1e20();                       // m_nPaused = 1
    void FUN_1409f1e40();                       // m_nPaused = 0
    int FUN_141278a40() const { return m_nActive; }   // inline getter (COMDAT 0x141278a40, unit_141274d10)

    int m_nActive;                              // +0x08
    int m_nDone;                                // +0x0c
    int m_nPaused;                              // +0x10
    int m_nPending;                             // +0x14
};
MS2_CHECK_SIZE(CAutoFindTaxiStation, 0x18);
MS2_CHECK_OFFSET(CAutoFindTaxiStation, m_nActive, 0x08);
MS2_CHECK_OFFSET(CAutoFindTaxiStation, m_nPending, 0x14);
