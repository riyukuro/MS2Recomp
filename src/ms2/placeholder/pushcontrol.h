// pushcontrol.h - CPushControl (RTTI .?AVCPushControl@@, derives CHitControl : CPtred, 0x48 bytes): the knock-back mover
// each PCBase owns at +0x690. NOT an original header. Owning unit: ?\hitcontrol.cpp (0x1413fca60..), whose members are
// only declared here. The fields are the ones the reset (0x1413fcf90) and PCBase::vfunc_107 (knock-back start) touch.
// Slots: 0 scalar deleting dtor, 1 per-frame update (pushes the given actor, returns whether it moved).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/hitcontrol.h"
#include <efd/Point3.h>

class GameObject;
class IDistanceCalculator;

class CPushControl : public CHitControl
{
public:
    CPushControl();                                                 // 0x1413fca60
    virtual ~CPushControl();                                        // 0x1413fcad0
    virtual bool vfunc_1(GameObject* pActor, double dTime);         // 0x1413fcb30
    float Update(double dTime);                              // advance the push clock, returns this frame's distance
    void Reset();                                           // reset (stopped, no distance calculator)
    void SetCurve(int nCurve);                                 // set the distance calculator (FUN_14028e960)
public:
    efd::Point3 m_kDir;                                             // +0x18 push direction (ZERO: not pushing)
    float m_fSpeed;                                                 // +0x24
    float m_f28;                                                    // +0x28
    float m_f2c;                                                    // +0x2c elapsed
    int m_b30;                                                      // +0x30
    int m_n34;                                                      // +0x34
    bool m_b38;                                                     // +0x38
    int m_nPriority;                                                // +0x3c a weaker push cannot interrupt this one
    IDistanceCalculator* m_pCalc;                                   // +0x40 (deleted by the reset)
};
MS2_CHECK_OFFSET(CPushControl, m_kDir, 0x18);
MS2_CHECK_OFFSET(CPushControl, m_nPriority, 0x3c);
MS2_CHECK_SIZE(CPushControl, 0x48);
