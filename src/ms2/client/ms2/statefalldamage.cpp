// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateFallDamage, the actor state after taking fall damage:
// plays the hurt animation and returns to idle when it ends. See statefalldamage.h.
// MS2-UNIT: ?\statefalldamage.cpp
// MS2-RANGE: 0x1417c7be0-0x1417c8240 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statefalldamage.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <NiActorManager.h>

#include "statefalldamage.h"

#include "ms2/client/ms2/statefall.h"               // the shared animation-prefix callees
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The actor's buff set: the fall-damage knock-back direction.
class Unk_FallDmgBuff { public: efd::Point3 FUN_1416836d0(); };

// PCBase vtable view: slot 22 takes the point by value (the exe copies it to a 16-aligned temp)
class Unk_FallDmgSlots
{
public:
#define MS2_FD_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_FD_SLOTS(0, 1, 2, 3, 4) MS2_FD_SLOTS(5, 6, 7, 8, 9) MS2_FD_SLOTS(10, 11, 12, 13, 14) MS2_FD_SLOTS(15, 16, 17, 18, 19)
#undef MS2_FD_SLOTS
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kPos);                                // 22 0x14123c3a0
};

// @0x1417c7be0
StateFallDamage::StateFallDamage(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417c7c50
StateFallDamage::~StateFallDamage()
{
}

// @0x1417c7c90
void StateFallDamage::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_strAnim = m_pOwner->vfunc_123(0x3f);
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        CString strRec;
        bool bHasRec = !FUN_1416561a0(pPC)->FUN_1411eabd0().IsEmpty();
        if (bHasRec)
            strRec = FUN_1416561a0(pPC)->FUN_1411eabd0();
        if (!strRec.IsEmpty())
        {
            efd::utf8string kAnim((const char*)FUN_14038f6d0(strRec, m_strAnim.c_str()));
            if (FUN_141b6f910()->FUN_140999490(m_pOwner->FUN_14123c460(), kAnim) != NiActorManager::INVALID_SEQUENCE_ID)
                m_strAnim = kAnim;
        }
    }
    m_pOwner->FUN_14166dd20(m_strAnim, m_pOwner->FUN_1416713c0(), false, false);
}

// @0x1417c7f30
// MS2-FUNCTIONAL: the exe passes the entity key return slot through a pointer temp (lea rax,[k]; mov [p],rax; mov rdx,[p])
void StateFallDamage::vfunc_5(int n)
{
    FUN_141b6f910()->FUN_1409fad80(m_pOwner->FUN_14123c460(), false);
    m_strAnim = "";
    State::vfunc_5(n);
}

// @0x1417c7fb0
void StateFallDamage::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    efd::Point3 kMove = efd::Point3::ZERO;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417c8030
void StateFallDamage::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (m_pOwner->vfunc_63() == 0)
        return;
    Unk_FallDmgBuff* pBuff = (Unk_FallDmgBuff*)m_pOwner->FUN_14166d240();
    reinterpret_cast<Unk_FallDmgSlots*>(m_pOwner)->vfunc_22(pBuff->FUN_1416836d0());
    if (m_pOwner->FUN_1416749c0())
        m_pOwner->vfunc_59(2, 0, 0, 0);
    else
        FUN_1417b9460();
}

// @0x1417c8150
void StateFallDamage::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_pOwner->FUN_14166de90(0x3f, eSequenceID))
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417c81c0
void StateFallDamage::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
}

// @0x1417c8230
int StateFallDamage::vfunc_1()
{
    return 0x1f;
}
