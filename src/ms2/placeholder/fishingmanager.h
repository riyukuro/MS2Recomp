// fishingmanager.h - CFishingManager (RTTI .?AVCFishingManager@@: TSingleton<CFishingManager> +0,
// ICastingEventListener +8; 0x1c0 bytes; ctor 0x140cd9400, dtor 0x140cd96c0, s_instance 0x143ab3848), its fish record
// CFish (RTTI, 0x30) and the catch statistics of a session. Owning unit: ?\fishingmanager.cpp (0x140cd7e40-0x140ce27f0).
// Header name assumed (kept under placeholder/ because three units already include it); member names are invented from
// their use (w475: layout from the ctor/dtor and the packet handler 0x140cd9840).
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/icastingeventlistener.h"
#include "ms2/placeholder/intervaltimer.h"

#include <efd/Point3.h>

class CInPacket;
class CFishCube;
class CItem;
class NotifyObject;

// A fish of the current spot as the server sends it (packet 0x73 modes 7 / 8): RTTI CFish, vftable 0x142e1eb50 (the
// scalar deleting dtor only). Ctor 0x140cdf440 / dtor 0x140cdf750 are inline COMDATs of this unit.
class CFish : public CPtred
{
public:
    CFish() { FUN_140cdfd70(); }                            // 0x140cdf440
    void FUN_140cdfd70();                                   // zero the fields
    void FUN_1403b0bf0(CInPacket* pPacket);                 // read id and the three values (?\fishcube.cpp)
    unsigned m_nId;                                         // +0x18 fish id (the map key)
    int m_n1c;                                              // +0x1c
    int m_n20;                                              // +0x20
    unsigned m_nSize;                                       // +0x24 the caught size
    int m_n28;                                              // +0x28
    int m_bNew;                                             // +0x2c first catch of this fish
};
MS2_CHECK_SIZE(CFish, 0x30);

// The catch statistics of a session (dumped by the GM command into .\log\client\fishRecord_HHMM.txt).
struct Unk_FishRecord
{
    Unk_FishRecord() : m_bOff(1), m_nTry(0), m_nSuccess(0) {}   // 0x140cdf490
    void FUN_140cd8e70(unsigned nFishId, int bSuccess);    // count a cast
    void FUN_140cd8f10();                                   // reset
    CString FUN_140cd8f60();                                // write the log file, its name
    int m_bOff;                                             // +0x00 recording is off
    int m_nTry;                                             // +0x04
    int m_nSuccess;                                         // +0x08
    ATL::CAtlMap<unsigned, int> m_counts;                   // +0x10 catches per fish id
};
MS2_CHECK_SIZE(Unk_FishRecord, 0x58);

class CFishingManager : public TSingleton<CFishingManager>, public ICastingEventListener
{
public:
    CFishingManager();                                      // 0x140cd9400
    virtual ~CFishingManager();                             // 0x140cd96c0
    void OnCastingFinished() override;                      // 0x140cdab60

    void FUN_140cd9840(CInPacket* pPacket);                 // packet 0x73
    void SendFishingMode10();                                   // stop auto fishing
    void FUN_140cdac20();                                   // the player moved
    void FUN_140cdac50();                                   // the cast was thrown
    void FUN_140cdacb0(NotifyObject* pNotify);              // "NotifyChangeBuff"
    void FUN_140cdadb0(MS2Ptr<CItem> rod);                  // use a rod
    void FUN_140cdae30(MS2Ptr<CItem> rod);                  // start fishing with a rod
    void SendFishingMode1();                                   // leaves the casting
    int FUN_140cdb110(const efd::Point3& kPos);                 // a fishing spot is in front of the point
    void SendFishingMode9();                                   // leave the fishing spot (packet 0x73 mode 9)
    int FUN_140cdb250();                                    // start fishing at the current spot
    void FUN_140cdb450();                                   // per frame
    MS2Ptr<CFish> FUN_140cdba00(unsigned nFishId);          // a fish of the spot
    void FUN_140cdba90(ATL::CAtlArray<MS2Ptr<CFish> >& out);   // all fishes of the spot
    MS2Ptr<CFishCube> FUN_140cdbb10(unsigned nCell);        // the fishing cube of a grid cell
    int FUN_140cdbb90();                                    // no catch is pending
    int FUN_140cdbbd0(MS2Ptr<CItem> rod);                   // the player may use the rod
    int FUN_140cdbdd0();                                    // m_nAutoCount
    void FUN_140cdbdf0(int nCount);                         // set m_nAutoCount, refresh the dialog
    void FUN_140cdbe40(int nBait);                          // m_nBaitId = nBait
    int FUN_140cdbe60();                                    // m_nBaitId
    int FUN_140cdbe80();                                    // the auto-fishing buff of the bait
    CStringW FUN_140cdc000(unsigned nSpotId);               // the spot's habitat / mastery text
    int FUN_140cdc280(unsigned nFishId);                    // the size grade of a caught fish
    int FUN_140cdc380(unsigned nFishId);                    // the fish (or its companion) was caught before
    int FUN_140cdc520();                                    // water is in front of the player
    int FUN_140cdc810();                                    // the player state allows fishing
    unsigned FUN_140cdc950();                               // the grid cell of the fishing line
    void FUN_140cdc9d0(int nState, int nGuideState);        // set the player and guide states
    void FUN_140cdcaa0(MS2Ptr<CFishCube> cube);             // mark a fishing cube
    void FUN_140cdcc70();                                   // splash at the line
    void FUN_140cdcde0();                                   // drop the cube marks
    void FUN_140cdce70(MS2Ptr<CItem> rod);                  // fishing started
    void FUN_140cdd030();                                   // fishing stopped
    void FUN_140cdd1f0();                                   // a fish bites
    void FUN_140cdd540(unsigned nFishId, unsigned nSize, int bSuccess);   // the catch result
    int FUN_140cdd7b0();                                    // the spot in front of the player is water
    CStringW FUN_140cddc70(const ATL::CAtlArray<CString>& texts);   // a random text of a constants list
    int FUN_140ce0cb0() { return m_bAutoFishing; }          // 0x140ce0cb0
    int FUN_140954150() { return m_bFishing; }              // @0x140954150 (actionkeyobject.cpp)

    int m_bFishing;                                         // +0x10 the player is in fishing mode
    ATL::CAtlArray<unsigned> m_marks;                       // +0x18 the cube mark effects
    ATL::CAtlMap<unsigned, MS2Ptr<CFishCube> > m_cubes;     // +0x38 the fishing cubes by grid cell
    ATL::CAtlMap<unsigned, MS2Ptr<CFish> > m_fishes;        // +0x80 the fishes of the spot by id
    int m_bAutoFishing;                                     // +0xc8
    int m_bGreat;                                           // +0xcc the bite is a great one
    unsigned m_nBiteEnd;                                    // +0xd0 the bite window ends (server time)
    unsigned m_nReelSound;                                  // +0xd4 the reel sound effect
    Timer m_resultTimer;                                    // +0xd8
    Timer m_startTimer;                                     // +0x110
    unsigned __int64 m_uidRod;                              // +0x148
    int m_nAutoCount;                                       // +0x150
    int m_nBaitId;                                          // +0x154
    Unk_IntervalTimer m_tick;                               // +0x158
    Unk_FishRecord m_record;                                // +0x160
    int m_bCountdown;                                       // +0x1b8 show the remaining bite time
};
MS2_CHECK_OFFSET(CFishingManager, m_bFishing, 0x10);
MS2_CHECK_OFFSET(CFishingManager, m_cubes, 0x38);
MS2_CHECK_OFFSET(CFishingManager, m_bAutoFishing, 0xc8);
MS2_CHECK_OFFSET(CFishingManager, m_resultTimer, 0xd8);
MS2_CHECK_OFFSET(CFishingManager, m_uidRod, 0x148);
MS2_CHECK_OFFSET(CFishingManager, m_record, 0x160);
MS2_CHECK_SIZE(CFishingManager, 0x1c0);
