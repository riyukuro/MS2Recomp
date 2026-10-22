// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See flybycameramode.h.
// MS2-UNIT: ?\flybycameramode.cpp
// MS2-RANGE: 0x14121f110-0x1412208a0 .text$mn
// MS2-PIN: ??_7?$TInterpolator@UUnk_CameraSetting@@@@6B@ 0x142ec3870
// MS2-PIN: ??_7?$TLinearInterpolator@UUnk_CameraSetting@@@@6B@ 0x142ec3898
// MS2-PIN: ??_7?$TLogInterpolator@UUnk_CameraSetting@@@@6B@ 0x142ec38c0
// MS2-PIN: ??_7?$TExpInterpolator@UUnk_CameraSetting@@@@6B@ 0x142ec38e8
// MS2-PIN: ?IsNull@?$TFunctor@UUnk_CameraSetting@@V?$ParamList@UUnk_CameraSetting@@VEmptyParam@@@@@@QEBA_NXZ 0x141220120
// MS2-PIN: ?Clear@?$TFunctor@UUnk_CameraSetting@@V?$ParamList@UUnk_CameraSetting@@VEmptyParam@@@@@@QEAAXXZ 0x141220220
// MS2-PIN: ?Invoke@?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVCFlyByCameraMode@@P82@EAAXXZ@@UEAAXXZ 0x14121fec0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$TLinearInterpolator@UUnk_CameraSetting@@@@UEAA@XZ 0x14121fe60 ; prop
// MS2-PIN: ??1?$TLogInterpolator@UUnk_CameraSetting@@@@UEAA@XZ 0x14121fe90 ; prop
// MS2-PIN: ??_G?$TLinearInterpolator@UUnk_CameraSetting@@@@UEAAPEAXI@Z 0x141220010 ; prop
// MS2-PIN: ??_G?$TLogInterpolator@UUnk_CameraSetting@@@@UEAAPEAXI@Z 0x141220050 ; prop
// MS2-PIN: ?vfunc_3@?$TInterpolator@UUnk_CameraSetting@@@@UEAAXXZ 0x141220150 ; unique
// MS2-PIN: ?vfunc_1@?$TExpInterpolator@UUnk_CameraSetting@@@@UEAAXXZ 0x1412201b0 ; unique
// MS2-PIN: ?vfunc_1@?$TLinearInterpolator@UUnk_CameraSetting@@@@UEAAXXZ 0x1412201d0 ; unique
// MS2-PIN: ?vfunc_1@?$TLogInterpolator@UUnk_CameraSetting@@@@UEAAXXZ 0x1412201f0 ; unique
// MS2-PIN: ?vfunc_2@?$TExpInterpolator@UUnk_CameraSetting@@@@UEAA?AUUnk_CameraSetting@@M@Z 0x141220290 ; unique
// MS2-PIN: ?vfunc_2@?$TLinearInterpolator@UUnk_CameraSetting@@@@UEAA?AUUnk_CameraSetting@@M@Z 0x141220440 ; unique
// MS2-PIN: ?vfunc_2@?$TLogInterpolator@UUnk_CameraSetting@@@@UEAA?AUUnk_CameraSetting@@M@Z 0x1412205d0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\flybycameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "flybycameramode.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern Vector3 DAT_143a08cd8;
extern const Vector3 g_143a08cf8;       // NiPoint3::UNIT_Z
float FUN_141b6fdb0(float f, int n);            // ease curve (n = exponent)
void FUN_140947860(Unk_CameraManager* pMgr, int n);
void FUN_140947980(Unk_CameraManager* pMgr, int n);
void FUN_140aed720(Unk_CameraManager* pMgr, Unk_CameraSetting* pSetting);
void FUN_140af99d0(CCameraMode* pMode, float f);        // m_setting.m_4 = f (+ owner property)
void FUN_140af9950(CCameraMode* pMode, float f);        // m_setting.m_8 = f (+ owner property)

// @0x1412201a0
Unk_FlyByCameraData* Unk_CameraManager::FUN_1412201a0()
{
    return (Unk_FlyByCameraData*)((char*)this + 0x34);
}

// @0x14121f110
CFlyByCameraMode::CFlyByCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev, int nMode)
    : CCameraMode(pOwner, pPrev)
{
    m_nMode = nMode;
    m_7c = 0.0f;
    m_pInterp = 0;
}

// @0x14121f1c0
CFlyByCameraMode::~CFlyByCameraMode()
{
    if (m_pInterp != 0)
    {
        delete m_pInterp;
        m_pInterp = 0;
    }
}

// @0x14121f260
void CFlyByCameraMode::vfunc_8(double fTime)
{
    Unk_CameraSetting data = m_pInterp->vfunc_2((float)fTime);
    m_fElapsed += (float)fTime;
    float fRatio = m_fElapsed / m_fDuration;
    if (1.0f < fRatio)
        fRatio = 1.0f;
    Unk_FlyByCameraData* pFly = Unk_CameraManager::FUN_1409478c0()->FUN_1412201a0();
    Vector3 ptRot = CCameraMode::FUN_140afdec0(fRatio, pFly->m_from.m_18, pFly->m_to.m_18);
    vfunc_11(data.m_0);
    ::FUN_140af99d0(this, data.m_4);
    ::FUN_140af9950(this, data.m_8);
    vfunc_4(ptRot);
    vfunc_3(data.m_c);
    vfunc_5(data.m_24);
}
MS2_REPLACE_METHOD(0x14121F260, CFlyByCameraMode, vfunc_8, 452, 0x486B6F05);

// @0x14121f430
void CFlyByCameraMode::vfunc_9()
{
}
MS2_REPLACE_METHOD(0x14121F430, CFlyByCameraMode, vfunc_9, 6, 0xA9AF6E37);

// @0x14121f440
void CFlyByCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    if (m_pInterp != 0)
    {
        delete m_pInterp;
        m_pInterp = 0;
    }
    FUN_140947860(Unk_CameraManager::FUN_1409478c0(), 0);
    Unk_FlyByCameraData* pFly = Unk_CameraManager::FUN_1409478c0()->FUN_1412201a0();
    switch (pFly->m_nKind)
    {
    case 1:
        m_pInterp = new TLinearInterpolator<Unk_CameraSetting>(pFly->m_fDuration, pFly->m_from, pFly->m_to);
        m_fElapsed = 0;
        m_fDuration = pFly->m_fDuration;
        break;
    case 2:
        m_pInterp = new TLogInterpolator<Unk_CameraSetting>(pFly->m_fDuration, pFly->m_from, pFly->m_to);
        m_fElapsed = 0;
        m_fDuration = pFly->m_fDuration;
        break;
    case 3:
        m_pInterp = new TExpInterpolator<Unk_CameraSetting>(pFly->m_fDuration, pFly->m_from, pFly->m_to);
        m_fElapsed = 0;
        m_fDuration = pFly->m_fDuration;
        break;
    default:
        m_pInterp = new TLinearInterpolator<Unk_CameraSetting>(pFly->m_fDuration, pFly->m_from, pFly->m_to);
        m_fElapsed = 0;
        m_fDuration = pFly->m_fDuration;
        break;
    }
    if (m_pInterp != 0)
    {
        m_pInterp->vfunc_1();
        CFlyByCameraMode* pThis = this;
        m_pInterp->SetCallback(pThis, &CFlyByCameraMode::FUN_14121f9f0);
    }
}

// @0x14121f850
void CFlyByCameraMode::vfunc_7()
{
    CCameraMode::vfunc_7();
    FUN_140947860(Unk_CameraManager::FUN_1409478c0(), m_nMode != 5);
    if (m_pInterp != 0)
    {
        delete m_pInterp;
        m_pInterp = 0;
    }
}
MS2_REPLACE_METHOD(0x14121F850, CFlyByCameraMode, vfunc_7, 172, 0x7400C59E);

// @0x14121f910
Vector3 CFlyByCameraMode::FUN_14121f910(const Vector3& a, const Vector3& b, const Vector3& c)
{
    Vector3 ptMid = a.FUN_14097fd50(b).FUN_14097fc90(0.5f);
    Vector3 ptDiff = c.FUN_140965c40(a);
    Vector3 ptUp = g_143a08cf8.FUN_14097fd50(DAT_143a08cd8);
    ptMid.FUN_140a4e560(FUN_1409ab5c0(ptDiff.FUN_140967ac0() * 0.5f, ptUp));
    return ptMid;
}
MS2_REPLACE_METHOD(0x14121F910, CFlyByCameraMode, FUN_14121f910, 210, 0x5B2C953F);

// @0x14121f9f0
void CFlyByCameraMode::FUN_14121f9f0()
{
    FUN_140aed720(Unk_CameraManager::FUN_1409478c0(), &m_setting);
    FUN_140947980(Unk_CameraManager::FUN_1409478c0(), m_nMode);
}
MS2_REPLACE_METHOD(0x14121F9F0, CFlyByCameraMode, FUN_14121f9f0, 70, 0xD29377B0);

// ---- COMDATs: TInterpolator<CameraData> family ----

template<class T> TInterpolator<T>::TInterpolator(float fDuration, const T& from, const T& to)
    : m_fDuration(fDuration), m_from(from), m_to(to)
{
}

template<class T> TInterpolator<T>::~TInterpolator()
{
}

template<class T> void TInterpolator<T>::vfunc_3()
{
    if (!m_onComplete.IsNull())
        m_onComplete();
}

template<class T> TLinearInterpolator<T>::TLinearInterpolator(float fDuration, const T& from, const T& to)
    : TInterpolator<T>(fDuration, from, to)
{
    m_fElapsed = 0;
}

template<class T> TLinearInterpolator<T>::~TLinearInterpolator()
{
}

template<class T> void TLinearInterpolator<T>::vfunc_1()
{
    m_fElapsed = 0;
}

template<class T> T TLinearInterpolator<T>::vfunc_2(float fDelta)
{
    m_fElapsed += fDelta;
    float fT = m_fElapsed / this->m_fDuration;
    if (fT > 1.0f)
    {
        this->vfunc_3();
        return this->m_to;
    }
    if (!this->m_modifier.IsNull())
        this->m_to = this->m_modifier(this->m_to);
    return this->m_from.FUN_140ae7e80(1.0f - fT).FUN_140ae81c0(this->m_to.FUN_140ae7e80(fT));
}

template<class T> TLogInterpolator<T>::TLogInterpolator(float fDuration, const T& from, const T& to)
    : TInterpolator<T>(fDuration, from, to)
{
}

template<class T> TLogInterpolator<T>::~TLogInterpolator()
{
}

template<class T> void TLogInterpolator<T>::vfunc_1()
{
    m_fElapsed = 0;
}

template<class T> T TLogInterpolator<T>::vfunc_2(float fDelta)
{
    m_fElapsed += fDelta;
    float fT = m_fElapsed / this->m_fDuration;
    fT = FUN_141b6fdb0(fT, 2);
    if (fT > 1.0f)
    {
        this->vfunc_3();
        return this->m_to;
    }
    if (!this->m_modifier.IsNull())
        this->m_to = this->m_modifier(this->m_to);
    return this->m_from.FUN_140ae7e80(1.0f - fT).FUN_140ae81c0(this->m_to.FUN_140ae7e80(fT));
}

template<class T> TExpInterpolator<T>::TExpInterpolator(float fDuration, const T& from, const T& to)
    : TInterpolator<T>(fDuration, from, to)
{
}

template<class T> TExpInterpolator<T>::~TExpInterpolator()
{
}

template<class T> void TExpInterpolator<T>::vfunc_1()
{
    m_fElapsed = 0;
}

template<class T> T TExpInterpolator<T>::vfunc_2(float fDelta)
{
    m_fElapsed += fDelta;
    float fT = m_fElapsed / this->m_fDuration;
    fT = FUN_141b6fdb0(fT, 3);
    if (fT > 1.0f)
    {
        this->vfunc_3();
        return this->m_to;
    }
    if (!this->m_modifier.IsNull())
        this->m_to = this->m_modifier(this->m_to);
    return this->m_from.FUN_140ae7e80(1.0f - fT).FUN_140ae81c0(this->m_to.FUN_140ae7e80(fT));
}

// explicit instantiation of the classes in the order the exe emitted them
template class TExpInterpolator<Unk_CameraSetting>;
template class TLinearInterpolator<Unk_CameraSetting>;
template class TLogInterpolator<Unk_CameraSetting>;

MS2_EMIT_CRT_MEMMOVE_S();
