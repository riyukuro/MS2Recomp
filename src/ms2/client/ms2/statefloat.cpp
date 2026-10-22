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
// MS2-FUNCTIONAL: the surface/move transform path (FUN_141674b60 + the velocity scale) places its temporaries differently
void StateFloat::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->vfunc_63() != 0)
    {
        float* pfVel = m_pOwner->FUN_141671920();
        NiPoint3 kSurface = m_pOwner->FUN_14123c360();
        Vector3 kLocal = *reinterpret_cast<const Vector3*>(&kSurface);
        efd::Point3 kDir = *reinterpret_cast<const efd::Point3*>(&kLocal);
        efd::Point3 kWorld = m_pOwner->FUN_141674b60(kDir);
        Vector3 kSpeed = reinterpret_cast<const Vector3&>(kWorld).FUN_14097fc90(pfVel[2]);
        Vector3 kStep = kSpeed.FUN_14097fc90((float)fTime);
        Vector3* pStep = FUN_1417c85d0(&kStep, kStep, fTime);
        kStep = *pStep;
        m_pOwner->vfunc_68(&kStep, fTime, 0, 0, 1);
    }
}
MS2_REPLACE_METHOD(0x1417C8310, StateFloat, vfunc_3, 410, 0x5EB73EE0);

// @0x1417c84b0
// MS2-FUNCTIONAL: stack-slot/temporary placement of the Vector3 copies differs
void StateFloat::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (m_pOwner->vfunc_63() != 0)
    {
        Unk_FloatMove* pMove = static_cast<Unk_FloatMove*>(m_pOwner->FUN_14166d240());
        Vector3 kDir = pMove->FUN_141683900();
        Vector3 kArg = kDir;
        m_pOwner->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
    }
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
// MS2-FUNCTIONAL: the damping chain keeps the min/max helper results in extra stack slots the exe reuses
Vector3* StateFloat::FUN_1417c85d0(Vector3* pOut, const Vector3& kIn, double fTime)
{
    if (m_pOwner == 0)
    {
        *pOut = kIn;
    }
    else
    {
        float fVel = FUN_1410a7600(m_pOwner);
        if (!FUN_14028d470(fVel, 0))
        {
            NiPoint3 kPos = m_pOwner->vfunc_18();
            if (m_nBand != (int)((kPos.z - 200.0f) / 150.0f))
                m_bBandChanged = true;
            if (m_pOwner->FUN_141671b20() == 0)
            {
                fVel = fVel * 0.9f;
            }
            else
            {
                NiPoint3 kSurface = m_pOwner->vfunc_18();
                float fBand = FUN_14029d220(FUN_14029d430(kSurface.z - 200.0f, 150.0f));
                float fBand2 = FUN_14029d220(FUN_14029d430(kSurface.z - 200.0f, 150.0f));
                if (50.0f < fBand && fBand2 < 100.0f && m_bBandChanged)
                {
                    fVel = 0.0f;
                    FUN_1417c8560();
                }
            }
            if (fVel <= 0.0f)
            {
                if (fVel < 0.0f)
                {
                    float fMin = -0.5f;
                    float fDelta = (float)((double)fVel * fTime);
                    const float& fClamped = FUN_140805fc0(fDelta, fMin);
                    pOut->z = pOut->z + fClamped;
                }
            }
            else
            {
                float fMax = 0.5f;
                float fDelta = (float)((double)fVel * fTime);
                const float& fClamped = FUN_1409ffe80(fDelta, fMax);
                pOut->z = pOut->z + fClamped;
            }
            FUN_1410a77e0(m_pOwner, fVel);
            *pOut = kIn;
        }
        else
        {
            *pOut = kIn;
        }
    }
    return pOut;
}
MS2_REPLACE_METHOD(0x1417C85D0, StateFloat, FUN_1417c85d0, 734, 0x741C31B6);

// @0x1417c88f0
int StateFloat::vfunc_1() { return 0x24; }
MS2_REPLACE_METHOD(0x1417C88F0, StateFloat, vfunc_1, 11, 0xDADF9E9F);
