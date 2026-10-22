// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See rideeinterpolator.h.
// MS2-UNIT: ?\rideeinterpolator.cpp
// MS2-RANGE: 0x1400e3e80-0x1400e3eb0 .text$di
// MS2-RANGE: 0x141020350-0x141020bd0 .text$mn
// MS2-PIN: ??_GRideeInterpolator@@UEAAPEAXI@Z 0x141020b60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\rideeinterpolator.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "rideeinterpolator.h"

#include <NiAVObject.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (all unit-local views) ----
class Unk_RiMain { };
class Unk_RiObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual bool vfunc_5(int nId, __int64* pOut); };
Unk_RiMain* FUN_1403ed2d0();                                    // the game object manager singleton
__int64 FUN_141bd1200(Unk_RiMain* p, int nObjectId);            // find the object by id
__int64 FUN_141020ad0(__int64 pObject);                         // the rider's body component (vfunc 5, id 0x6200013)

RideeInterpolator::RideeInterpolator()
    : NiTransformInterpolator()
{
    m_nObjectId = 0;
    m_bAlwaysUpdate = true;
}

RideeInterpolator::RideeInterpolator(NiTransformData* pData)
    : NiTransformInterpolator(pData)
{
    m_nObjectId = 0;
    m_bAlwaysUpdate = true;
}

RideeInterpolator::~RideeInterpolator()
{
}

// @0x141020430
// MS2-FUNCTIONAL: the node-transform composition (0x1c0 bytes of NiTransform math through out-of-unit helpers) is reduced to the early-out chain
bool RideeInterpolator::Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue)
{
    if (m_nObjectId == 0)
        return false;
    __int64 pObject = FUN_141bd1200(FUN_1403ed2d0(), m_nObjectId);
    __int64 pBody = FUN_141020ad0(pObject);
    if (pBody == 0)
        return false;
    m_fLastTime = fTime;
    return true;
}

// @0x141020a70
void RideeInterpolator::SetObjectId(int nObjectId)
{
    m_nObjectId = nObjectId;
}

// @0x141020a90
bool RideeInterpolator::AlwaysUpdate() const
{
    return m_bAlwaysUpdate;
}

// @0x141020ad0
__int64 FUN_141020ad0(__int64 pObject)
{
    __int64 pRes = 0;
    Unk_RiObj* p = (Unk_RiObj*)pObject;
    if (p == 0 || !p->vfunc_5(0x6200013, &pRes))
        pRes = 0;
    return pRes;
}

const NiRTTI RideeInterpolator::ms_RTTI("RideeInterpolator", &NiTransformInterpolator::ms_RTTI);   // @0x1400e3e80

// @0x141020b20
bool FUN_141020b20(__int64* pLhs, __int64 nRhs)
{
    return *pLhs == nRhs;
}
