// statecashcalldata.h - StateCashCall (actor state type 0x2a: the player calls an air taxi / helicopter / bank with a cash
// item; a casting bar runs, the vehicle effect is spawned at the player, then the request is sent) and its payload
// StateCashCallData (call type, item uid, price). m_n10 is the phase (0x6b calling, 0x6c / 0x6d / 0x6e later phases);
// m_nElapsed counts up to m_nEnd. NOT an original header (name assumed from the unit ?\statecashcalldata.cpp,
// 0x1410229d0-0x141024250 .text$mn). Names invented from use. w276.
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>

namespace efd { class utf8string; }
class PCBase;

// 0x30.
class StateCashCallData : public StateData
{
public:
    StateCashCallData();                                    // 0x1410229d0
    StateCashCallData(int nCallType, __int64 nItemUid, int nPrice);   // 0x141022a30
    // 0  ~StateCashCallData 0x141023f00 (??_G 0x141024060) is implicit
    virtual void vfunc_1(Unk_StateDataArg* p);              // 1  0x141022aa0 (writes the call type as text)
    virtual void vfunc_2(Unk_StateDataArg* p);              // 2  0x141022b20 (reads it back)

    int m_nCallType;                                        // +0x18 1 meso air taxi, 2/3 cash air taxi, 4/5/6 helicopters, bank
    int m_pad_1c;
    __int64 m_nItemUid;                                     // +0x20 the cash item (0: none)
    unsigned int m_nPrice;                                  // +0x28 (formatted as unsigned)
    int m_pad_2c;
};
MS2_CHECK_SIZE(StateCashCallData, 0x30);
MS2_CHECK_OFFSET(StateCashCallData, m_nCallType, 0x18);
MS2_CHECK_OFFSET(StateCashCallData, m_nItemUid, 0x20);
MS2_CHECK_OFFSET(StateCashCallData, m_nPrice, 0x28);

// 0x60.
class StateCashCall : public State
{
public:
    StateCashCall(PCBase* pOwner);                          // 0x141022b70
    virtual ~StateCashCall();                               // 0  0x141022c00 (??_G 0x141024020)
    virtual int vfunc_1();                                  // 1  0x141024130: 0x2a
    virtual void vfunc_3(double fTime);                     // 3  0x141023110
    virtual void vfunc_4(StateData* pData);                 // 4  0x141022c50 (enter)
    virtual void vfunc_5(int n);                            // 5  0x141022f60 (leave)
    virtual void vfunc_6();                                 // 6  0x141023330
    virtual void vfunc_7(int n);                            // 7  0x141022ee0
    virtual void vfunc_8(double fTime);                     // 8  0x141023230
    virtual int vfunc_20();                                 // 20 0x141024120: 1
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1410240a0: a new StateCashCallData

    int GetCallType();                                      // 0x141023380 the call type of the payload, 0 without one
    void OnCastEnd(double fTime);                                       // 0x1410233d0 phase 0x6b over: spawn the vehicle
    void OnArrived(double fTime);                                       // 0x1410234d0 phase 0x6c over
    void OnLeave(double fTime);                                         // 0x141023560 phase 0x6d over
    void SendRequest();                                     // 0x141023650 send / apply the call
    void SetPhase(int nPhase, int nAdd);                    // 0x141023890 next phase, lengthen the state
    void SpawnEffect(const CString& strEffect);             // 0x1410238d0 spawn the vehicle effect next to the player
    efd::utf8string GetEffectName();                        // 0x141023b50
    int GetDuration();                                      // 0x141023c20
    CStringW GetCastText();                                 // 0x141023ce0
    CString GetStationName();                               // 0x141023d50

    unsigned int m_nStart;                                  // +0x40 clock at enter
    unsigned int m_nElapsed;                                // +0x44
    unsigned int m_nEnd;                                    // +0x48
    int m_bSent;                                            // +0x4c the request was sent
    MS2Ptr<StateCashCallData> m_spCash;                     // +0x50
};
MS2_CHECK_SIZE(StateCashCall, 0x60);
MS2_CHECK_OFFSET(StateCashCall, m_nStart, 0x40);
MS2_CHECK_OFFSET(StateCashCall, m_bSent, 0x4c);
MS2_CHECK_OFFSET(StateCashCall, m_spCash, 0x50);
