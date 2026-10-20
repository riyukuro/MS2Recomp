// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateStun, the actor state of a stunned actor: per phase it
// plays a lie-down / lie-keep / stand-up / snare / vomit / frozen / stuck animation, picked from one of three name
// tables (a random "A" or "B" lie set, or the plain "Stun_A" set). See statestun.h.
// MS2-UNIT: ?\statestun.cpp
// MS2-RANGE: 0x1417f67b0-0x1417f7550 .text$mn
// MS2-RANGE: 0x140104310-0x140104390 .text$di
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statestun.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <efd/Point3.h>
#include <efd/utf8string.h>

#include "statestun.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// ---- unit statics (.text$di): the shared sort-name / skill / stun / condition header statics, here only the last two ----

static bool s_bStunDummy;
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of the exe objects and unrecovered callees ----

void FUN_14123d7a0(PCBase* pOwner, CString strName, int bOn);   // 0x14123d7a0 switches a named input mode

// The actor's buffs (PCBase::FUN_1416749a0).
class Unk_PCBaseBuffs
{
public:
    int FUN_1409709b0();                                   // 0x1409709b0 the buffs forbid the stun animation
    CString FUN_1409716a0();                               // 0x1409716a0 the custom stun animation name
};

// The animation names per phase index (FUN_1417f7140), the lie sets "A" and "B" and the plain set.
static const char* s_szStunAnimsA[10] = { "Down_A", "Down_Idle_A", "Stnd_Up_A", "Snare_A", "Vomit_A", "Down_C", "Down_Idle_C", "Stnd_Up_C", "StunFrozen_A", "Stuck_A" };
static const char* s_szStunAnimsB[10] = { "Down_B", "Down_Idle_B", "Stnd_Up_B", "Snare_A", "Vomit_A", "Down_C", "Down_Idle_C", "Stnd_Up_C", "StunFrozen_A", "Stuck_A" };
static const char* s_szStunAnimsPlain[10] = { "Stun_A", "Stun_A", "Stun_A", "Stun_A", "Stun_A", "Stun_A", "Stun_A", "Stun_A", "Stun_A", "Stun_A" };

// @0x1417f67b0
StateStun::StateStun(PCBase* pOwner) : State(pOwner)
{
    m_nKind = 0;
    m_n14 = 0;
    m_pAnims = 0;
    FUN_1417f72f0(s_bStunDummy);
    FUN_1417f72f0(s_bStunDummy);
    FUN_1417f72f0(s_bStunDummy);
}

// @0x1417f6840
StateStun::~StateStun()
{
}

// @0x1417f6870
// MS2-FUNCTIONAL: the exe builds the animation name as a named local next to a temporary CString (no ctor-result copy);
// every spelling tried (temp, named, const-ref) differs by a few stack moves and 13 bytes of frame
void StateStun::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    MS2Ptr<StateStunData> spData(dynamic_cast<StateStunData*>(pData));
    if (spData != 0)
        m_nKind = spData->m_n18;
    switch (m_n10)
    {
    case 0x40:
        m_pAnims = s_szStunAnimsPlain;
        break;
    case 0x41:
    case 0x46:
        m_pAnims = 0;
        break;
    default:
        if (rand() % 2 != 0)
            m_pAnims = s_szStunAnimsA;
        else
            m_pAnims = s_szStunAnimsB;
        break;
    }
    if (m_n10 == 0x41)
    {
        FUN_14123d7a0(m_pOwner, s_strStun, 1);
    }
    else if (m_n10 == 0x46)
    {
        const CString& strAnim = m_pOwner->FUN_1416749a0()->FUN_1409716a0();
        efd::utf8string kName((LPCSTR)strAnim);
        m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
    }
    else if (m_pAnims != 0)
    {
        efd::utf8string kName(m_pAnims[FUN_1417f7140()]);
        m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
    }
    m_pOwner->FUN_14166ef10(CString("Stun"), 1, 0, false);
}

// @0x1417f6b70
void StateStun::vfunc_5(int n)
{
    FUN_14123d7a0(m_pOwner, s_strStun, 0);
    State::vfunc_5(n);
}

// @0x1417f6bd0
// MS2-FUNCTIONAL: the exe's frame has one more unused 8-byte slot before the zero direction (all else identical)
void StateStun::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    efd::Point3 kDir = efd::Point3::ZERO;
    m_pOwner->vfunc_68(&kDir, fTime, 0, 0, 0);
    if (m_pOwner->FUN_1416749a0()->FUN_1409709b0() != 0)
        return;
    switch (m_n10)
    {
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
        m_pOwner->vfunc_59(1, 0, 0, 0);
        break;
    case 0x41:
        FUN_14123d7a0(m_pOwner, s_strStun, 0);
        m_pOwner->vfunc_59(1, 0, 0, 0);
        break;
    default:
        if (m_n10 != 0x3f)
        {
            m_n10 = 0x3f;
            if (m_pAnims == 0)
            {
                if (rand() % 2 != 0)
                    m_pAnims = s_szStunAnimsA;
                else
                    m_pAnims = s_szStunAnimsB;
            }
            efd::utf8string kName(m_pAnims[FUN_1417f7140()]);
            m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
        }
        break;
    }
}

// @0x1417f6e60
// MS2-FUNCTIONAL: case 0x46 keeps the returned name CString in an extra stack slot in the exe (same as vfunc_4)
void StateStun::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    switch (m_n10)
    {
    case 0x3f:
    case 0x42:
    case 0x43:
        m_pOwner->vfunc_59(1, 0, 0, 0);
        break;
    case 0x3d:
        m_n10 = 0x3e;
    case 0x44:
    case 0x45:
        {
            if (m_pAnims == 0)
            {
                if (rand() % 2 != 0)
                    m_pAnims = s_szStunAnimsA;
                else
                    m_pAnims = s_szStunAnimsB;
            }
            efd::utf8string kName(m_pAnims[FUN_1417f7140()]);
            m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
        }
        break;
    case 0x46:
        {
            const CString& strAnim = m_pOwner->FUN_1416749a0()->FUN_1409716a0();
            efd::utf8string kName((LPCSTR)strAnim);
            m_pOwner->FUN_14166dd20(kName, 1.0f, true, false);
        }
        break;
    }
}

// @0x1417f70a0
void StateStun::vfunc_8(double fTime)
{
}

// @0x1417f70c0
void StateStun::vfunc_2(int n)
{
    if (m_n10 == n)
        return;
    if (m_n10 == 0x41)
        FUN_14123d7a0(m_pOwner, s_strStun, 0);
    State::vfunc_2(n);
}

// @0x1417f7140
int StateStun::FUN_1417f7140()
{
    int nIndex = 0;
    if (m_n10 == 0x3d)
    {
        if (m_nKind == 6)
            nIndex = 5;
    }
    else if (m_n10 == 0x3e)
    {
        if (m_nKind == 6)
            nIndex = 6;
        else
            nIndex = 1;
    }
    else if (m_n10 == 0x3f)
    {
        if (m_nKind == 6)
            nIndex = 7;
        else
            nIndex = 2;
    }
    else if (m_n10 == 0x42)
        nIndex = 3;
    else if (m_n10 == 0x43)
        nIndex = 4;
    else if (m_n10 == 0x44)
        nIndex = 8;
    else if (m_n10 == 0x45)
        nIndex = 9;
    if (nIndex >= 10)
        nIndex = 0;
    return nIndex;
}

// @0x1417f7430 (the UCRT's memcpy_s, as an ordinary function)
#pragma function(memcpy)
int FUN_1417f7430(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
#pragma intrinsic(memcpy)
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb7f50-0x142cb7f90 .text$yd
