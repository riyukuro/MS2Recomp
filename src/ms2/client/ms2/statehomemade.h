// statehomemade.h - the housing homemade-cube (cooking / crafting cube) harvest state StateHomemade (type 0x37) of a player:
// walks to the nearest usable CHomemadeCubeObject, shows the casting bar and tells the server which cubes were harvested.
// NOT an original header (name assumed from the unit client\ms2\statehomemade.cpp). Derives State (ms2/placeholder/state.h).
#pragma once
#include <vector>

#include <efd/utf8string.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/icastingeventlistener.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>

class CHomemadeCubeObject;
class StateHomemadeData;
struct Unk_HmCastInfo;      // casting bar request (0x38)

// 0x78. The player's homemade-cube interaction. m_n10 is the sub state (0x8f start, 0x90 / 0x91 breed end, 0x92 harvesting).
// The ICastingEventListener at +0x40 is the casting bar's callback.
class StateHomemade : public State, public ICastingEventListener
{
public:
    StateHomemade(PCBase* pOwner);                          // 0x140ca4360
    virtual ~StateHomemade();                               // 0x140ca4400 (??_G 0x140ca6490)
    virtual int vfunc_1();                                  // 1  0x140ca65d0: 0x37
    virtual void vfunc_3(double fTime);                     // 3  0x140ca49d0
    virtual void vfunc_4(StateData* pData);                 // 4  0x140ca4460
    virtual void vfunc_5(int n);                            // 5  0x140ca4930
    virtual void vfunc_7(int n);                            // 7  0x140ca48c0
    virtual void vfunc_8(double fTime);                     // 8  0x140ca4ad0
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140ca4d50
    virtual bool vfunc_25(int n, void* p);                  // 25 0x140ca4de0: false
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140ca64d0: an empty StateHomemadeData
    virtual void OnCastingFinished();                       // listener 0  0x140ca4d30: m_n48 = 1

    int FUN_140ca4e00();                                    // the harvest duration, scaled by the cursor manager
    efd::utf8string FUN_140ca4e50();                        // the action animation of m_n10
    void FUN_140ca4f30(Unk_HmCastInfo* pInfo);              // fill the casting bar request
    int FUN_140ca4fd0(int nMode);                           // a homemade cube is in reach
    void SendFunctionCubeMode4();                                   // send the cubes in reach (kind 4)
    void SendFunctionCubeMode5();                                   // send the cubes that may be used (kind 5)

    int m_n48;                                              // +0x48 casting finished
    MS2Ptr<StateHomemadeData> m_spHarvest;                  // +0x50 the data of the running harvest
    std::vector<MS2Ptr<CHomemadeCubeObject> > m_aCubes;     // +0x60 homemade cubes in reach
};
MS2_CHECK_SIZE(StateHomemade, 0x78);
MS2_CHECK_OFFSET(StateHomemade, m_n48, 0x48);
MS2_CHECK_OFFSET(StateHomemade, m_spHarvest, 0x50);
MS2_CHECK_OFFSET(StateHomemade, m_aCubes, 0x60);
