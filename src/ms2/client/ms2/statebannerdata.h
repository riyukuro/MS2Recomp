// statebannerdata.h - StateBannerData (the banner state's payload, 0x20, banner id at +0x18) and StateBanner (actor
// state type 0x3b, 0x50): the payload mirrors its banner id into / out of the state-sync record's animation string,
// and the state attaches the payload to the owner and pushes / clears the owner's banner.
// MS2-UNIT: ?\statebannerdata.cpp
// MS2-RANGE: 0x140b7edf0-0x140b7fa70 .text$mn
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/state.h"

class PCBase;
class Unk_StateDataArg;   // StateData slots 1/2 argument (the sync record's animation string is at +0x70)

// 0x18 + banner id. The exe's dtor body is a bare StateData::~StateData (no vptr store), so it stays implicit:
// MS2-PIN: ??1StateBannerData@@UEAA@XZ 0x140b7f4a0
class StateBannerData : public StateData
{
public:
    StateBannerData();                                 // @0x140b7edf0
    StateBannerData(int nBanner);                      // @0x140b7ee30
    virtual void vfunc_1(Unk_StateDataArg* p);         // 1 @0x140b7ee80
    virtual void vfunc_2(Unk_StateDataArg* p);         // 2 @0x140b7ef00
    int m_nBanner;                                     // +0x18
};
MS2_CHECK_SIZE(StateBannerData, 0x20);
MS2_CHECK_OFFSET(StateBannerData, m_nBanner, 0x18);

// 0x40 + the payload handle (deleting dtor 0x140b7f5d0).
class StateBanner : public State
{
public:
    StateBanner(PCBase* pOwner);                       // @0x140b7ef50
    virtual ~StateBanner();                            // @0x140b7efb0
    virtual int vfunc_1();                             // 1  @0x140b7f690: 0x3b
    virtual void vfunc_2(int n);                       // 2  @0x140b7eff0
    virtual void vfunc_3(double fTime);                // 3  @0x140b7f1b0
    virtual void vfunc_4(StateData* pData);            // 4  @0x140b7f080
    virtual void vfunc_5(int n);                       // 5  @0x140b7f150
    virtual void vfunc_6();                            // 6  @0x140b7f2c0
    virtual void vfunc_8(double fTime);                // 8  @0x140b7f230 (empty)
    virtual void vfunc_9(double fTime);                // 9  @0x140b7f250
    virtual MS2Ptr<StateData> vfunc_27();              // 27 @0x140b7f610: a new StateBannerData
    void PlayBannerAnimation(int n);                         // @0x140b7f320 (enter / leave the banner anim)
    int GetBannerId();                               // @0x140b7f3b0: the payload's banner id, 0 without one
    MS2Ptr<StateBannerData> m_spBannerData;            // +0x40
};
MS2_CHECK_SIZE(StateBanner, 0x50);
MS2_CHECK_OFFSET(StateBanner, m_spBannerData, 0x40);
