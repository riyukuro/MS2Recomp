// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateFloat, the actor state that keeps an actor floating
// on a fluid surface: the band index comes from the surface height, the vertical velocity of the actor's physics body
// is damped towards the band and integrated into a clamped per-frame z step handed to PCBase slot 68. See statefloat.h.
// MS2-UNIT: ?\statefloat.cpp
// MS2-RANGE: 0x1417c8240-0x1417c8900 .text$mn
// MS2-PIN: ??_GStateFloat@@UEAAPEAXI@Z 0x1417c88b0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statefloat.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "statefloat.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The player's movement controller (PCBase +0x6d8, unit_141682f80): the direction of the forced/knock-back move.
class Unk_FloatMove
{
public:
    Vector3 FUN_141683900();                                       // 0x141683900 the current move direction
};

float FUN_1410a7600(PCBase* p);                                           // 0x1410a7600 vertical velocity (PCBase +0xbf0)
void FUN_1410a77e0(PCBase* p, float f);                                   // 0x1410a77e0 store the vertical velocity
bool FUN_14028d470(float a, float b);                                     // 0x14028d470 approx equal
float FUN_14029d430(float fX, float fY);                                  // 0x14029d430 fmodf
float FUN_14029d220(float fValue);                                        // 0x14029d220 fabsf
const float& FUN_1409ffe80(const float& a, const float& b);               // 0x1409ffe80 min
const float& FUN_140805fc0(const float& a, const float& b);               // 0x140805fc0 max

// PCBase seen with Vector3 points: slots 22 and 68 take the point by value (the exe copies it to a 16-aligned temp),
// and the local -> world dir transform takes / returns it by value too.
class Unk_FloatOwner
{
public:
#define MS2_SF_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_SF_SLOTS(0, 1, 2, 3, 4) MS2_SF_SLOTS(5, 6, 7, 8, 9) MS2_SF_SLOTS(10, 11, 12, 13, 14) MS2_SF_SLOTS(15, 16, 17, 18, 19)
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(Vector3 kPos);                                   // 22 0x14123c3a0
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_SF_SLOTS(25, 26, 27, 28, 29) MS2_SF_SLOTS(30, 31, 32, 33, 34) MS2_SF_SLOTS(35, 36, 37, 38, 39)
    MS2_SF_SLOTS(40, 41, 42, 43, 44) MS2_SF_SLOTS(45, 46, 47, 48, 49) MS2_SF_SLOTS(50, 51, 52, 53, 54)
    MS2_SF_SLOTS(55, 56, 57, 58, 59) MS2_SF_SLOTS(60, 61, 62, 63, 64)
#undef MS2_SF_SLOTS
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
    virtual bool vfunc_68(Vector3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
    Vector3 FUN_141674b60(efd::Point3 kDir);                                // 0x141674b60 local dir -> world dir
};

// @0x1417c8240
StateFloat::StateFloat(PCBase* pOwner) : State(pOwner)
{
    m_nBand = 0;
    m_bBandChanged = false;
}

// @0x1417c82a0
StateFloat::~StateFloat()
{
}

// @0x1417c82d0
void StateFloat::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    FUN_1417c8560();
}
MS2_REPLACE_METHOD(0x1417C82D0, StateFloat, vfunc_4, 44, 0x79D77923);

// @0x1417c8310
void StateFloat::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->vfunc_63() == 0)
        return;
    Vector3* pVel = reinterpret_cast<Vector3*>(m_pOwner->FUN_141671920());
    Vector3 kWorld = reinterpret_cast<Unk_FloatOwner*>(m_pOwner)->FUN_141674b60(m_pOwner->FUN_14123c360());
    Vector3 kSpeed = kWorld.FUN_14097fc90(pVel->z);
    Vector3 kStep = kSpeed.FUN_14097fc90((float)fTime);
    kStep = FUN_1417c85d0(kStep, fTime);
    reinterpret_cast<Unk_FloatOwner*>(m_pOwner)->vfunc_68(kStep, fTime, 0, 0, 1);
}
MS2_REPLACE_METHOD(0x1417C8310, StateFloat, vfunc_3, 410, 0x5EB73EE0);

// @0x1417c84b0
void StateFloat::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (m_pOwner->vfunc_63() == 0)
        return;
    Unk_FloatMove* pMove = static_cast<Unk_FloatMove*>(m_pOwner->FUN_14166d240());
    Vector3 kDir = pMove->FUN_141683900();
    reinterpret_cast<Unk_FloatOwner*>(m_pOwner)->vfunc_22(kDir);
}
MS2_REPLACE_METHOD(0x1417C84B0, StateFloat, vfunc_8, 162, 0xDBB0643A);

// @0x1417c8560
void StateFloat::FUN_1417c8560()
{
    if (m_pOwner != 0)
    {
        m_nBand = (int)((m_pOwner->vfunc_18().z - 200.0f) / 150.0f);
    }
    m_bBandChanged = false;
}
MS2_REPLACE_METHOD(0x1417C8560, StateFloat, FUN_1417c8560, 100, 0xC818D17A);

// @0x1417c85d0
Vector3 StateFloat::FUN_1417c85d0(Vector3 kMove, double fTime)
{
    if (m_pOwner == 0)
        return kMove;
    float fVel = FUN_1410a7600(m_pOwner);
    if (FUN_14028d470(fVel, 0))
        return kMove;
    int nBand = (int)((m_pOwner->vfunc_18().z - 200.0f) / 150.0f);
    if (m_nBand != nBand)
        m_bBandChanged = true;
    if (m_pOwner->FUN_141671b20() != 0)
    {
        float fLo = 50.0f;
        float fHi = 100.0f;
        float fMod = FUN_14029d430(m_pOwner->vfunc_18().z - 200.0f, 150.0f);
        if (FUN_14029d220(fMod) > fLo && FUN_14029d220(fMod) < fHi && m_bBandChanged)
        {
            fVel = 0.0f;
            FUN_1417c8560();
        }
    }
    else
    {
        fVel = fVel * 0.9f;
    }
    if (fVel > 0.0f)
    {
        float fMax = 0.5f;
        float fDelta = (float)((double)fVel * fTime);
        kMove.z = kMove.z + FUN_1409ffe80(fDelta, fMax);
    }
    else if (fVel < 0.0f)
    {
        float fMin = -0.5f;
        float fDelta = (float)((double)fVel * fTime);
        kMove.z = kMove.z + FUN_140805fc0(fDelta, fMin);
    }
    FUN_1410a77e0(m_pOwner, fVel);
    return kMove;
}
MS2_REPLACE_METHOD(0x1417C85D0, StateFloat, FUN_1417c85d0, 734, 0x741C31B6);

// @0x1417c88f0
int StateFloat::vfunc_1() { return 0x24; }
MS2_REPLACE_METHOD(0x1417C88F0, StateFloat, vfunc_1, 11, 0xDADF9E9F);
