// statefloat.h - StateFloat: the actor state that keeps an actor floating on the water surface (or in a fluid): the
// "band" index is derived from the surface height (z - 200) / 150, the vertical velocity from the physics body is
// damped each frame and the resulting z offset is clamped, then handed to the actor's move (PCBase slot 68).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\statefloat.cpp`
// (0x1417c8240-0x1417c8900 .text$mn, dir client\ms2). Header name assumed; member names invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"          // State / StateData
#include "ms2/placeholder/nipoint3.h"       // Vector3 (efd::Point3 / NiPoint3)

class PCBase;

// 0x48. The base State is 0x40; the two extra members drive the surface band.
class StateFloat : public State
{
public:
    StateFloat(PCBase* pOwner);                                                         // 0x1417c8240
    ~StateFloat();                                                                      // 0x1417c82a0
    int vfunc_1();                                                                      // 0x1417c88f0: 0x24
    void vfunc_3(double fTime);                                                         // 0x1417c8310
    void vfunc_4(StateData* pData);                                                     // 0x1417c82d0
    void vfunc_8(double fTime);                                                         // 0x1417c84b0

    void FUN_1417c8560();                                                               // 0x1417c8560 band = (surface z - 200) / 150
    Vector3* FUN_1417c85d0(Vector3* pOut, const Vector3& kIn,
        double fTime);                                                                  // 0x1417c85d0 damp + clamp the step

    int m_nBand;                        // +0x40 surface band the actor is in
    bool m_bBandChanged;                // +0x44 the band changed since the last check
};
MS2_CHECK_SIZE(StateFloat, 0x48);
