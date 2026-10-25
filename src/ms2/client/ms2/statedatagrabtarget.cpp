// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateDataGrabTarget (the grab state's payload) and
// StateGrabTarget (actor state type 0x2b): the owner is pinned to a named node of the grabbing actor every tick, and
// released (state 5) when the grabber or the node is gone. See statedatagrabtarget.h.
// MS2-UNIT: ?\statedatagrabtarget.cpp
// MS2-RANGE: 0x141024250-0x141024dc0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statedatagrabtarget.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <NiAVObject.h>

#include "ms2/client/ms2/statedatagrabtarget.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

class Unk_StateDataArg
{
public:
    char m_pad_00[0x64];
    int m_n64;                              // +0x64
    char m_pad_68[0x70 - 0x68];
    CString m_str70;                        // +0x70
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_n64, 0x64);
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

class Unk_StateArg22 : public CPtred { public: char m_pad_18[0xb8 - 0x18]; };   // the sync record, a by-value MS2Ptr argument
class GameObjectControllerHitReport { public: void FUN_140cfaf30(); };   // clear the entity and the hit flag
class Unk_GtBody                                                         // the actor's physics body
{
public:
    void FUN_141240730();                                                // drop the stood-on entity
    GameObjectControllerHitReport* FUN_141240f20();
    void FUN_141241070();                                                // start falling
};
Unk_GtBody* FUN_14166d220(PCBase* pOwner);
class Unk_SSGWorld { public: PCBase* FUN_141bd1200(int nId); };          // the field's actor by id
Unk_SSGWorld* FUN_1403ed2d0();
int FUN_1409709b0(void* pBuffs);                                         // 0x1409709b0 the actor's buffs forbid a grab
void* FUN_14165f100(MyPC* pPC);                                          // 0x14165f100 the playing emotion
void FUN_14165f170(MyPC* pPC);                                           // 0x14165f170 stop it
void FUN_140ad0c10(efd::Point3* pAngles, float fScale);                    // 0x140ad0c10 scale the angles (radians -> degrees)

// ---- StateDataGrabTarget ----

// @0x141024250
StateDataGrabTarget::StateDataGrabTarget() : m_nTarget(0)
{
}

// @0x1410242a0
void StateDataGrabTarget::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_n64 = m_nTarget;
    p->m_str70 = m_strNode;
}

// @0x141024300
void StateDataGrabTarget::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nTarget = p->m_n64;
    m_strNode = p->m_str70;
}

// ---- StateGrabTarget ----

// @0x141024360
StateGrabTarget::StateGrabTarget(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1410243f0
StateGrabTarget::~StateGrabTarget()
{
}

// @0x141024430
void StateGrabTarget::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spGrab.AssignRaw(dynamic_cast<StateDataGrabTarget*>(pData));
    if (m_spGrab == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        FUN_14166d220(m_pOwner)->FUN_141240730();
        m_pOwner->vfunc_31(false);
        MyPC* pPC = FUN_1417b84b0();
        if (pPC != 0)
        {
            if (FUN_14165f100(pPC) != 0)
                FUN_14165f170(pPC);
        }
        m_kPos = m_pOwner->vfunc_18();
        m_kDir = m_pOwner->vfunc_20();
        FUN_14166d220(m_pOwner)->FUN_141240f20()->FUN_140cfaf30();
        FUN_14166d220(m_pOwner)->FUN_141241070();
    }
}

// @0x1410245e0
void StateGrabTarget::vfunc_5(int n)
{
    State::vfunc_5(n);
    FUN_14166d220(m_pOwner)->FUN_141240730();
    m_pOwner->vfunc_31(true);
    m_pOwner->vfunc_21(m_kDir);
}

// MS2-FUNCTIONAL: 26 bytes longer than the exe (branch layout around the nested guards / EH state boundaries)
// @0x141024680
void StateGrabTarget::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_spGrab == 0)
        return;
    StateDataGrabTarget* pData = m_spGrab.get();
    PCBase* pGrabber = FUN_1403ed2d0()->FUN_141bd1200(pData->m_nTarget);
    if (pGrabber != 0)
    {
        int nDead = pGrabber->FUN_14166ce30();
        if (nDead == 0)
        {
            int nBlocked = FUN_1409709b0(pGrabber->FUN_1416749a0());
            if (nBlocked == 0)
            {
                efd::SmartPointer<NiAVObject> spNode(0);
                spNode = pGrabber->FUN_1416758a0(m_spGrab.get()->m_strNode);
                if (spNode)
                {
                    efd::Point3 kAngles;
                    if (spNode->GetWorldRotate().ToEulerAnglesXYZ(kAngles.x, kAngles.y, kAngles.z))
                    {
                        FUN_140ad0c10(&kAngles, -57.2957764f);
                        m_pOwner->vfunc_21(kAngles);
                    }
                    efd::Point3 kPos = spNode->GetWorldTranslate();
                    m_pOwner->vfunc_19(kPos);
                    m_pOwner->FUN_14166dda0(0x28);
                }
                return;
            }
        }
    }
    m_pOwner->vfunc_59(5, 0, 0, 0);
}

// @0x141024940
void StateGrabTarget::vfunc_8(double fTime)
{
}

// @0x141024960
MS2Ptr<StateData> StateGrabTarget::vfunc_27()
{
    return MS2Ptr<StateData>(new StateDataGrabTarget());
}

// @0x1410249f0
int StateGrabTarget::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    return 1;
}

// @0x141024a20
int StateGrabTarget::vfunc_17()
{
    return 0;
}

// @0x141024a30
int StateGrabTarget::FUN_141024a30(int nTarget)
{
    if (m_spGrab == 0)
        return 0;
    if (m_spGrab.get()->m_nTarget != nTarget)
        return 0;
    return 1;
}

// @0x141024c80
int StateGrabTarget::vfunc_1()
{
    return 0x2b;
}
