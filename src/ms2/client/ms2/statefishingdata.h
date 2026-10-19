// statefishingdata.h - StateFishing (type 0x2d: the player sits with a fishing rod; sub states 0x75 cast, 0x76 wait,
// 0x77 bite, 0x78 reel in, 0x79 end; gosubstate.h), its payload StateFishingData (the rod id) and StateFishingFloat
// (type 0x2e: the float / bobber of the guide object; sub states 0x7a idle, 0x7b fishing, 0x7c end). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\statefishingdata.cpp` (0x140dda280-0x140ddcf00 .text$mn,
// 0x1400d5fd0 .text$di for the global strings, dir client\ms2). Header name assumed; member names invented from their
// use. Derives State / StateData (ms2/placeholder/state.h).
// MS2-GUESS-LOOKALIKES
#pragma once
#include <afx.h>
#include <efd/SmartPointer.h>
#include <NiNode.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/timer.h"

class CItem;
class PCBase;

// A cell of the fishing grid (3 ints); FUN_1408a1430 builds it from a point, FUN_1408a03c0 hashes it.
struct Unk_FsCell
{
    int x, y, z;
};
MS2_CHECK_SIZE(Unk_FsCell, 12);

// 0x20. The rod id. The exe's dtor body is a bare StateData::~StateData (no vptr store), so it stays implicit:
// MS2-PIN: ??1StateFishingData@@UEAA@XZ 0x140ddc9e0
class StateFishingData : public StateData
{
public:
    StateFishingData();                                         // 0x140dda280
    StateFishingData(int nRod);                                 // 0x140dda2c0
    virtual void vfunc_1(Unk_StateDataArg* p);                  // 1 0x140dda310 (rod id as text into the state-sync record)
    virtual void vfunc_2(Unk_StateDataArg* p);                  // 2 0x140dda390 (rod id from the record)

    int m_nRod;                                                 // +0x18
};
MS2_CHECK_SIZE(StateFishingData, 0x20);
MS2_CHECK_OFFSET(StateFishingData, m_nRod, 0x18);

// 0xb8. m_n10 is the sub state (0x75..0x79). m_spEffect is the lure / chair effect model attached to the owner,
// m_spItem the rod item that is put into the owner's hand, m_timer the bite timer (wait sub state), m_nA8 whether the
// guide object was already placed, m_nAC which of the two bore animations plays, m_nB0 the owner's slot 25 value
// (visibility), m_nEffect the id of the chair effect.
class StateFishing : public State
{
public:
    StateFishing(PCBase* pOwner);                           // 0x140dda3e0
    virtual ~StateFishing();                                // 0x140dda4f0 (??_G 0x140ddcb10)
    virtual int vfunc_1();                                  // 1  0x140ddcc60: 0x2d
    virtual void vfunc_3(double fTime);                     // 3  0x140dda950
    virtual void vfunc_4(StateData* pData);                 // 4  0x140dda570 (enter)
    virtual void vfunc_5(int n);                            // 5  0x140dda770 (leave)
    virtual void vfunc_6();                                 // 6  0x140ddb580
    virtual void vfunc_8(double fTime);                     // 8  0x140ddaf00
    virtual void vfunc_9(double fTime);                     // 9  0x140ddb010 (plays the animation of the sub state)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140ddac60
    virtual int vfunc_19();                                 // 19 0x140ddcc80: 0
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);         // 22 0x140ddb4e0
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140ddcbd0: an empty StateFishingData

    int FUN_140ddb5d0();                                    // the rod id of the data (0 without data)
    int FUN_140ddb620();                                    // the rod id of the worn fishing gem, else of the data
    void FUN_140ddb740(int nRod);                           // puts the rod into the hand and starts the chair effect

    MS2Ptr<StateFishingData> m_spFishingData;               // +0x40
    efd::SmartPointer<NiNode> m_spEffect;                   // +0x50
    int m_nRod;                                             // +0x58
    MS2Ptr<CItem> m_spItem;                                 // +0x60
    Timer m_timer;                                          // +0x70
    int m_nA8;                                              // +0xa8
    int m_nAC;                                              // +0xac
    int m_nB0;                                              // +0xb0
    int m_nEffect;                                          // +0xb4
};
MS2_CHECK_SIZE(StateFishing, 0xb8);
MS2_CHECK_OFFSET(StateFishing, m_spFishingData, 0x40);
MS2_CHECK_OFFSET(StateFishing, m_spEffect, 0x50);
MS2_CHECK_OFFSET(StateFishing, m_nRod, 0x58);
MS2_CHECK_OFFSET(StateFishing, m_spItem, 0x60);
MS2_CHECK_OFFSET(StateFishing, m_timer, 0x70);
MS2_CHECK_OFFSET(StateFishing, m_nEffect, 0xb4);

// 0x40. The float of the fishing guide object: follows the thrown position inside a 150 x 150 box.
class StateFishingFloat : public State
{
public:
    StateFishingFloat(PCBase* pOwner);                      // 0x140ddbf50
    virtual ~StateFishingFloat();                           // 0x140ddbf90 (??_G 0x140ddcb90)
    virtual int vfunc_1();                                  // 1  0x140ddcc70: 0x2e
    virtual void vfunc_3(double fTime);                     // 3  0x140ddbff0
    virtual void vfunc_4(StateData* pData);                 // 4  0x140ddbfc0
    virtual void vfunc_5(int n);                            // 5  0x140ddbfe0 (empty)
    virtual void vfunc_8(double fTime);                     // 8  0x140ddc180
    virtual void vfunc_9(double fTime);                     // 9  0x140ddc240

    Unk_FsCell FUN_140ddc3c0(Unk_StreamPoint kPoint);       // the grid cell of a point, shifted to the corner of its quadrant
    bool FUN_140ddc4b0(Unk_StreamPoint kStep);              // the owner may move by this step (ray cast to the water)
};
MS2_CHECK_SIZE(StateFishingFloat, 0x40);
