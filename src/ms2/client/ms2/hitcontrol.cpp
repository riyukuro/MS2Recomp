// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CHitControl / CPushControl: the knock-back mover of a PCBase.
// MS2-UNIT: ?\hitcontrol.cpp
// MS2-RANGE: 0x1413fc9d0-0x1413fd240 .text$mn
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\hitcontrol.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "hitcontrol.h"
#include "ms2/placeholder/pushcontrol.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Easing distance calculator interface (same shape as in commonutil.cpp); the push owns one (plain operator delete).
class IDistanceCalculator
{
public:
    virtual float vfunc_0(float fDelta, float fTime, float fDuration, float fDistance) = 0;
};

IDistanceCalculator* FUN_14028e960(int nType);                      // commonutil: calculator for a curve kind
bool FUN_14028d470(float a, float b);                               // approx equal
PCBase* FUN_14096e110(PCBase* pObject);                         // cast to the mount/npc-side class (null if none)
PCBase* FUN_140974230(PCBase* pObject);                         // cast to the player class
CPhysXHelper* FUN_1409f7ca0();

// @0x1413fc9d0
CHitControl::CHitControl()
{
}

// @0x1413fca10
CHitControl::~CHitControl()
{
}

// @0x1413fca40
bool CHitControl::vfunc_1(GameObject* pActor, double dTime)
{
    return false;
}
MS2_REPLACE_METHOD(0x1413FCA40, CHitControl, vfunc_1, 19, 0x1FFCE454);

// @0x1413fca60
CPushControl::CPushControl()
{
    m_pCalc = 0;
    FUN_1413fcf90();
}

// @0x1413fcad0
CPushControl::~CPushControl()
{
    if (m_pCalc != 0)
        delete m_pCalc;
}

// @0x1413fcb30
// MS2-FUNCTIONAL: the by-value copy of the push direction for FUN_1416725c0 is built after fDist * 100 in the exe (copy first here)
bool CPushControl::vfunc_1(GameObject* pActor, double dTime)
{
    if (m_kDir == efd::Point3::ZERO)
        return false;
    float fDist = FUN_1413fce30(dTime);
    if (FUN_14028d470(fDist, 0)) {
        if (m_b38)
            static_cast<PCBase*>(pActor)->vfunc_59(1, 0, 0, 0);
        FUN_1413fcf90();
        return false;
    }
    float fUp = 0.0f;
    if (m_b30 != 0) {
        NiPoint3 kPos = pActor->vfunc_18();
        efd::Point3 kHit = efd::Point3::ZERO;
        // CPhysXHelper takes the same 12-byte point as its placeholder Vector3
        if (FUN_1409f7ca0()->FUN_14168a310(reinterpret_cast<const Vector3&>(kPos),
                                           reinterpret_cast<Vector3&>(kHit), 0, 0, 0, 0) != 0) {
            kHit.z = kHit.z + 1.0f;
            if (kPos.z > kHit.z)
                fUp = -(kPos.z - kHit.z);
        }
    }
    efd::Point3 kDir = m_kDir;
    int nStep = static_cast<PCBase*>(pActor)->FUN_1416725c0(reinterpret_cast<NiPoint3&>(kDir), fDist * 100.0f, 150.0f, fUp);
    if (nStep == 0 ||
        static_cast<PCBase*>(pActor)->FUN_14166c980() == 0x20 || m_n34 != 0) {
        efd::Point3 kMove = m_kDir * fDist;
        int nFlags = 0;
        if (FUN_14096e110(static_cast<PCBase*>(pActor)) != 0)
            nFlags = 4;
        else if (FUN_140974230(static_cast<PCBase*>(pActor)) != 0)
            nFlags = 0x10;
        static_cast<PCBase*>(pActor)->vfunc_106(kMove, dTime, nFlags);
    } else {
        if (m_b38)
            static_cast<PCBase*>(pActor)->vfunc_59(1, 0, 0, 0);
        FUN_1413fcf90();
    }
    return true;
}
MS2_REPLACE_METHOD(0x1413FCB30, CPushControl, vfunc_1, 750, 0x21EB2633);

// @0x1413fce30
float CPushControl::FUN_1413fce30(double dTime)
{
    if (m_pCalc == 0)
        return 0.0f;
    float fResult = 0.0f;
    if (0.0f < m_f28 && m_f2c < m_f28) {
        float fDelta = (float)dTime;
        if (m_f28 < m_f2c + fDelta)
            fDelta = m_f28 - m_f2c;
        m_f2c = m_f2c + fDelta;
        if (m_f2c > m_f28)
            m_f2c = m_f28;
        if (m_f2c < fDelta)
            fDelta = m_f2c;
        fResult = m_pCalc->vfunc_0(fDelta, m_f2c, m_f28, m_fSpeed);
    }
    return fResult;
}
MS2_REPLACE_METHOD(0x1413FCE30, CPushControl, FUN_1413fce30, 334, 0x7C4BB9BE);

// @0x1413fcf90
void CPushControl::FUN_1413fcf90()
{
    m_kDir = efd::Point3::ZERO;
    m_fSpeed = 0;
    m_f28 = 0;
    m_f2c = 0;
    m_b38 = false;
    m_b30 = 0;
    m_n34 = 0;
    m_nPriority = 0;
    if (m_pCalc != 0)
        delete m_pCalc;
    m_pCalc = 0;
}
MS2_REPLACE_METHOD(0x1413FCF90, CPushControl, FUN_1413fcf90, 176, 0xD7B94FB0);

// @0x1413fd050
void CPushControl::FUN_1413fd050(int nCurve)
{
    if (m_pCalc != 0)
        delete m_pCalc;
    m_pCalc = FUN_14028e960(nCurve);
}
MS2_REPLACE_METHOD(0x1413FD050, CPushControl, FUN_1413fd050, 77, 0x85826F75);

// @0x1413fd120
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
