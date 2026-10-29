// statetaxicalldata.h - StateTaxiCall (actor state type 0x25: the player calls a taxi, it drives up, the player gets in
// and is driven away) and its payload StateTaxiCallData (the taxi id the state is synced with). m_n10 is the phase
// (0x65 calling, 0x66 arrived, 0x67 / 0x68 waiting, 0x69 leaving, 0x6a done); m_nElapsed counts up to m_nEnd. NOT an
// original header (name assumed from the unit ?\statetaxicalldata.cpp, 0x1417fcf30-0x1417fe410 .text$mn).
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>

// 0x20.
class StateTaxiCallData : public StateData
{
public:
    StateTaxiCallData();                                    // 0x1417fcf30
    StateTaxiCallData(int nTaxiId);                         // 0x1417fcf70
    // virtual ~StateTaxiCallData();                        // 0  0x1417fe0f0 (implicit; ??_G 0x1417fe220)
    virtual void vfunc_1(Unk_StateDataArg* p);              // 1  0x1417fcfc0 (writes the id as text)
    virtual void vfunc_2(Unk_StateDataArg* p);              // 2  0x1417fd040 (reads it back)

    int m_nTaxiId;                                          // +0x18
};
MS2_CHECK_SIZE(StateTaxiCallData, 0x20);
MS2_CHECK_OFFSET(StateTaxiCallData, m_nTaxiId, 0x18);

// The taxi request packet record (8 bytes).
struct Unk_TaxiReq
{
    Unk_TaxiReq() { m_nTaxiId = 0; m_nCost = 0; }           // 0x1417fe090
    int m_nTaxiId;
    int m_nCost;
};

// 0x80.
class StateTaxiCall : public State
{
public:
    StateTaxiCall(PCBase* pOwner);                          // 0x1417fd090
    virtual ~StateTaxiCall();                               // 0  0x1417fd150 (??_G 0x1417fe1e0)
    virtual int vfunc_1();                                  // 1  0x1417fe2f0: 0x25
    virtual void vfunc_3(double fTime);                     // 3  0x1417fd690
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417fd1d0 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417fd600 (leave)
    virtual void vfunc_6();                                 // 6  0x1417fdae0
    virtual void vfunc_7(int n);                            // 7  0x1417fd5b0
    virtual void vfunc_8(double fTime);                     // 8  0x1417fd9e0
    virtual int vfunc_20();                                 // 20 0x1417fe2e0: 1
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1417fe260: a new StateTaxiCallData

    int FUN_1417fdb70();                                    // the taxi id of the payload, 0 without one
    void FUN_1417fdbc0(int nState, int nAdd);               // next phase, lengthen the state
    void FUN_1417fdc00(const CString& strEffect);           // spawn the taxi effect next to the player

    unsigned int m_nStart;                                  // +0x40 clock at enter
    unsigned int m_nElapsed;                                // +0x44
    unsigned int m_nEnd;                                    // +0x48
    CString m_strCall;                                      // +0x50 effect of the call phase
    CString m_strArrive;                                    // +0x58
    CString m_strLeave;                                     // +0x60
    bool m_bSurprise;                                       // +0x68 plays "suprise_A" on arrival
    MS2Ptr<StateTaxiCallData> m_spData;                     // +0x70
};
MS2_CHECK_SIZE(StateTaxiCall, 0x80);
MS2_CHECK_OFFSET(StateTaxiCall, m_nStart, 0x40);
MS2_CHECK_OFFSET(StateTaxiCall, m_strCall, 0x50);
MS2_CHECK_OFFSET(StateTaxiCall, m_bSurprise, 0x68);
MS2_CHECK_OFFSET(StateTaxiCall, m_spData, 0x70);
