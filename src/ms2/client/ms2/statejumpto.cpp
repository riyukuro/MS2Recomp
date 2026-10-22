// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateJumpTo, the actor state of a scripted jump to a target
// position (a ballistic arc, then the landing state). See statejumpto.h.
// MS2-UNIT: ?\statejumpto.cpp
// MS2-RANGE: 0x1417d6c00-0x1417d79e0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statejumpto.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/MemHint.h>

#include "statejumpto.h"

#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/arccontroller.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

class Unk_JtAnimService { public: int FUN_140b7f6a0(const egf::EntityID& kId); };    // sequence id of the model
Unk_JtAnimService* FUN_141b6f910();

// The temporary returned by vfunc_18 viewed as the 12-byte point of the arc API (cl takes the address of the temporary;
// clang-cl refuses, so it goes through a helper there).
#ifdef __clang__
static Unk_StreamPoint& Unk_JtPoint(const NiPoint3& kPt) { return *const_cast<Unk_StreamPoint*>(reinterpret_cast<const Unk_StreamPoint*>(&kPt)); }
#define MS2_JT_POINT(expr) Unk_JtPoint(expr)
#else
#define MS2_JT_POINT(expr) (*reinterpret_cast<Unk_StreamPoint*>(&(expr)))
#endif

// @0x1417d6c00
StateJumpTo::StateJumpTo(PCBase* pOwner) : State(pOwner), m_spArc(0)
{
    m_n14 = 0;
    m_spArc = 0;
    m_n48 = 0;
    m_nRiseAnim = 4;
    m_nFallAnim = 2;
}

// @0x1417d6cb0
StateJumpTo::~StateJumpTo()
{
}

// @0x1417d6d00
void StateJumpTo::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n10 = 0x28;
    m_n48 = 0;
    m_spArc = new (efd::MemHint(efd::MemHint::NONE)) CArcController;
    int cStarted = 0;
    m_spJump.AssignRaw(dynamic_cast<StateJumpToData*>(pData));
    if (m_spJump.get() != 0)
    {
        int cFlag = m_spJump->m_b2c;
        cStarted = m_spArc->FUN_1409ab1b0(MS2_JT_POINT(m_pOwner->vfunc_18()),
                                          *reinterpret_cast<Unk_StreamPoint*>(&m_spJump->m_pos), m_spJump->m_f24, m_spJump->m_fGravity);
        if (cFlag != 0)
        {
            m_nRiseAnim = 0x2a;
            m_nFallAnim = 0x2b;
        }
        else
        {
            m_nRiseAnim = 4;
            m_nFallAnim = 2;
        }
    }
    if (cStarted == 0)
        m_n10 = 0x29;
}

// MS2-FUNCTIONAL: the exe passes the rotation local to FUN_14166d970 by address (no by-value copy); pcbase.h declares it by value
// @0x1417d6f80
void StateJumpTo::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_spArc = 0;
    if (m_spJump.get() != 0)
    {
        if (m_spJump->m_n34 != 0)
        {
            efd::Point3 kRot = m_pOwner->vfunc_20();
            kRot.z = m_spJump->m_f38;
            m_pOwner->FUN_14166d970(kRot);
        }
        m_pOwner->vfunc_19(m_spJump->m_pos);
    }
}

// @0x1417d7090
void StateJumpTo::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_n10 == 0x29)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_spArc->FUN_1409ab3b0((float)fTime);
        Unk_StreamPoint kPos = m_spArc->GetPosition();
        m_pOwner->vfunc_19(*reinterpret_cast<efd::Point3*>(&kPos));
        if ((m_spJump.get() != 0 ? true : false) && m_spJump->m_n34 != 0)
        {
            m_pOwner->FUN_14166d8b0(m_spJump->m_f38);
            m_pOwner->FUN_14166d630((float)fTime);
        }
    }
}

// @0x1417d7230
void StateJumpTo::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    int nSeq = FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460());
    if (m_n10 == 0x28)
    {
        if (m_spArc->IsRising() != 0 && m_n48 == 0)
        {
            if (m_pOwner->FUN_14166de90(m_nRiseAnim, nSeq) == 0)
                m_pOwner->FUN_14166dda0(m_nRiseAnim);
        }
        else if (m_spArc->FUN_1409ab370() == 0 && m_n48 != 0)
        {
            if (m_pOwner->FUN_14166de90(m_nFallAnim, nSeq) == 0)
                m_pOwner->FUN_14166dda0(m_nFallAnim);
        }
        else if (m_spArc->FUN_1409ab370() != 0)
        {
            MS2Ptr<StateLandData> spLand(new StateLandData);
            spLand->m_str = "Jump_Land_A";
            m_pOwner->vfunc_59(4, spLand.get(), 0, 0);
        }
    }
}

// @0x1417d74a0
void StateJumpTo::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_pOwner->FUN_14166de90(m_nRiseAnim, eSequenceID))
        m_n48 = 1;
}

// @0x1417d77b0
int StateJumpTo::vfunc_1()
{
    return 7;
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x1417D7090, StateJumpTo, vfunc_3, 406, 0xA805C1A1);
MS2_REPLACE_METHOD(0x1417D6D00, StateJumpTo, vfunc_4, 632, 0x30A174FF);
MS2_REPLACE_METHOD(0x1417D6F80, StateJumpTo, vfunc_5, 251, 0x92B76401);
MS2_REPLACE_METHOD(0x1417D7230, StateJumpTo, vfunc_9, 614, 0xDEAB2E69);
MS2_REPLACE_METHOD(0x1417D74A0, StateJumpTo, EndOfSequence, 75, 0x7E404584);
