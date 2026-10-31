// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateWeddingEmotionData (the payload of the
// wedding-emotion state, 0x38) and StateWeddingEmotion (actor state type 0x47, 0x70): the payload mirrors itself
// into / out of the state-sync record, and the state plays either the payload's single animation or an entry of the
// wedding-emotion table row's animation list. Also holds this unit's MS2Ptr<T> instantiation copies (the exe emits
// them in the first obj that used them) and the unit's unreferenced CRT memmove_s copy.
// MS2-UNIT: ?\stateweddingemotiondata.cpp
// MS2-RANGE: 0x140ac6400-0x140ac7740 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateweddingemotiondata.cpp"
// The exe's memmove call is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <new>
#include <string.h>
#include <efd/utf8string.h>

#include "ms2/placeholder/stateweddingemotion.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/fittingdollpc.h"

class MyPC;

// ---- callees outside this unit ----

// The wedding-emotion table singleton (0x143ab26c8) and its row lookup, both owned by ?\weddingemotiontable.cpp.
class Unk_SingletonObj
{
public:
    MS2Ptr<WeddingEmotionData> FUN_140903740(int nKey);     // 0x140903740
};
Unk_SingletonObj* FUN_140ac74e0();                          // 0x140ac74e0 (defined below)
extern Unk_SingletonObj* DAT_143ab26c8;                     // 0x143ab26c8

// MyPC / PCBase helpers (free-function form: `this` is the first argument).
unsigned FUN_140869420();                                   // 0x140869420 client time in ms

// ---- StateWeddingEmotionData ----

// @0x140ac6400
StateWeddingEmotionData::StateWeddingEmotionData() : m_b18(0), m_n28(0), m_b2c(0), m_b2d(0), m_n30(0)
{
    m_strAnim.Empty();
}

// @0x140ac6490
StateWeddingEmotionData::~StateWeddingEmotionData()
{
}

// The dynamic_cast views: the exe casts StateSyncObject -> StateSyncObjectWeddingEmotion (RTTI names are compared, so
// casting to the Unk_ stand-ins always gave NULL).
class StateSyncObject { public: virtual ~StateSyncObject(); };
class StateSyncObjectWeddingEmotion : public StateSyncObject {};

// Mirrors the payload into the wedding-emotion part of the sync record: +0xb8/+0xb9 are the two flags, +0xbc the
// duration in seconds, then either the animation name or the emotion id + repeat flag.
// @0x140ac64d0
void StateWeddingEmotionData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    Unk_SyncWeddingEmotion* pSync = reinterpret_cast<Unk_SyncWeddingEmotion*>(dynamic_cast<StateSyncObjectWeddingEmotion*>(reinterpret_cast<StateSyncObject*>(p)));
    pSync->m_bB8 = m_b18;
    pSync->m_bB9 = m_b2c;
    if (pSync->m_bB9 != 0)
        pSync->m_nBC = (int)(__int64)((float)m_n30 / 1000.0f);
    if (m_b18 != 0)
    {
        pSync->m_nC0 = m_n28;
        pSync->m_bC4 = m_b2d;
    }
    else
    {
        pSync->m_strAnim = m_strAnim;
    }
}

// Reads the wedding-emotion fields back out of the sync record (the reverse of vfunc_1).
// @0x140ac65d0
void StateWeddingEmotionData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    Unk_SyncWeddingEmotion* pSync = reinterpret_cast<Unk_SyncWeddingEmotion*>(dynamic_cast<StateSyncObjectWeddingEmotion*>(reinterpret_cast<StateSyncObject*>(p)));
    m_b18 = pSync->m_bB8;
    m_b2c = pSync->m_bB9;
    if (m_b2c != 0)
        m_n30 = pSync->m_nBC * 1000;
    if (m_b18 != 0)
    {
        m_n28 = pSync->m_nC0;
        m_b2d = pSync->m_bC4;
    }
    else
    {
        m_strAnim = p->m_strAnim;
    }
}

// ---- StateWeddingEmotion ----

// @0x140ac66c0
StateWeddingEmotion::StateWeddingEmotion(PCBase* pOwner)
    : State(pOwner), m_spData(new StateWeddingEmotionData), m_n50(0), m_n68(0)
{
}

// @0x140ac6790
StateWeddingEmotion::~StateWeddingEmotion()
{
}

// Starts the state: adopts the payload, applies the animation speed / emotion, then plays either the row's animation
// at index 0 or the payload's own animation. Leaves the state (slot 59 -> state 1) when the payload is missing.
// @0x140ac67e0
void StateWeddingEmotion::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    MS2Ptr<StateWeddingEmotionData> spData = dynamic_cast<StateWeddingEmotionData*>(pData);
    if (spData == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    m_spData = spData;
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0 && m_spData.get()->m_b2d == 0 && ((void*)(reinterpret_cast<PC*>(pPC)->FUN_14165f100())) != 0)
        reinterpret_cast<PC*>(pPC)->SendRequestCube();
    m_n50 = FUN_140869420();
    if (m_spData.get()->m_b18 != 0)
    {
        m_spEmotion = FUN_140ac74e0()->FUN_140903740(m_spData.get()->m_n28);
        if (m_spEmotion != 0)
        {
            if (m_spEmotion->m_names.FUN_14028b4c0() != 0)
            {
                m_n68 = 0;
                efd::utf8string kAnim((const char*)*m_spEmotion->m_names.FUN_14027f1c0(m_n68));
                m_pOwner->FUN_14166dd20(kAnim, m_pOwner->FUN_1416713c0(), false, false);
                return;
            }
        }
    }
    else if (!m_spData.get()->m_strAnim.IsEmpty())
    {
        efd::utf8string kAnim((const char*)m_spData.get()->m_strAnim);
        m_pOwner->FUN_14166dd20(kAnim, m_pOwner->FUN_1416713c0(), false, false);
        return;
    }
    m_pOwner->vfunc_59(1, 0, 0, 0);
}

// Resets the owner's animation and re-enters this state with the given sub id.
// @0x140ac6bc0
void StateWeddingEmotion::vfunc_7(int n)
{
    if (FUN_1417b8370() != 0)
    {
        FUN_1417b8370()->vfunc_23(0);
        FUN_1417b8370()->vfunc_59(n, 0, 0, 0);
    }
}

// @0x140ac6c40
void StateWeddingEmotion::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
}

// @0x140ac6c70
void StateWeddingEmotion::vfunc_5(int n)
{
    State::vfunc_5(n);
}

// @0x140ac6ca0
void StateWeddingEmotion::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
}

// @0x140ac6ce0
void StateWeddingEmotion::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
}

// End of one animation: repeat (slot 59 -> state 1) once the duration is up, otherwise play the next entry of the
// row's animation list, or replay the single animation of a looping payload.
// @0x140ac6d10
void StateWeddingEmotion::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (m_spData.get()->m_b2c != 0)
    {
        if (m_n50 + m_spData.get()->m_n30 < FUN_140869420())
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
            return;
        }
    }
    if (m_spData.get()->m_b18 != 0)
    {
        if (m_spEmotion == 0 || m_spEmotion->m_names.FUN_14028b4c0() == 0)
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
            return;
        }
        unsigned nNext = (unsigned)((m_n68 + 1) % m_spEmotion->m_names.FUN_14028b4c0());
        if (m_spData.get()->m_b2c == 0 && nNext <= m_n68)
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
            return;
        }
        m_n68 = nNext;
        efd::utf8string kAnim((const char*)*m_spEmotion->m_names.FUN_14027f1c0(m_n68));
        m_pOwner->FUN_14166dd20(kAnim, 1.0f, true, true);
        return;
    }
    if (m_spData.get()->m_b2c != 0)
    {
        efd::utf8string kAnim((const char*)m_spData.get()->m_strAnim);
        m_pOwner->FUN_14166dd20(kAnim, 1.0f, true, false);
        return;
    }
    m_pOwner->vfunc_59(1, 0, 0, 0);
}

// Compares the payload against a wedding-emotion sync record: 1 = a different animation is wanted (the state should be
// re-entered), 0 = nothing to do.
// @0x140ac7090
int StateWeddingEmotion::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    Unk_SyncWeddingEmotion* pSync = reinterpret_cast<Unk_SyncWeddingEmotion*>(dynamic_cast<StateSyncObjectWeddingEmotion*>(reinterpret_cast<StateSyncObject*>((Unk_StateArg22*)p)));
    if (pSync == 0)
        return 0;
    if (m_spData == 0)
        return 0;
    if (m_spData.get()->m_b18 != pSync->m_bB8)
        return 1;
    if (m_spData.get()->m_b18 != 0)
    {
        if (m_spData.get()->m_n28 != pSync->m_nC0)
            return 1;
    }
    else
    {
        if (m_spData.get()->m_strAnim.Compare((const char*)pSync->m_strAnim) != 0)
            return 1;
    }
    return 0;
}

// @0x140ac7460
MS2Ptr<StateData> StateWeddingEmotion::vfunc_27()
{
    return MS2Ptr<StateData>(new StateWeddingEmotionData);
}

// @0x140ac74e0
Unk_SingletonObj* FUN_140ac74e0()
{
    return DAT_143ab26c8;
}

// @0x140ac7500
int StateWeddingEmotion::vfunc_1()
{
    return 0x47;
}

// The UCRT's `static __inline memmove_s` of this TU (unreferenced copy, kept alive by the pointer below).
#pragma function(memcpy, memset)
// @0x140ac7620
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
