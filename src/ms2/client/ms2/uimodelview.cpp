// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIModelView: the avatar preview view of the UI. See uimodelview.h.
// MS2-UNIT: ?\uimodelview.cpp
// MS2-RANGE: 0x140e66920-0x140e694a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??4?$SmartPointer@VNiDirectionalLight@@@efd@@QEAAAEAV01@PEAVNiDirectionalLight@@@Z 0x140e68e20 ; unique
// MS2-PIN: ??A?$CAtlArray@PEAVNiNode@@V?$CElementTraits@PEAVNiNode@@@ATL@@@ATL@@QEBAAEBQEAVNiNode@@_K@Z 0x140e691b0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7UIModelView@@6BIRenderServiceDelegate@ecr@@@ 0x142e51330
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimodelview.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimodelview.h"
#include "gameobject.h"
#include "fielddatacli.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <NiQuaternion.h>
#include <NiColor.h>
#include <NiAmbientLight.h>
#include <NiDirectionalLight.h>
#include <NiFrustum.h>
#include <math.h>
#include <algorithm>

// ---- out-of-unit callees (bound to the exe by name) ----
// The world manager (singleton FUN_1403ed2d0).
class Unk_UmvWorld
{
public:
    GameObject* FUN_141bd1180(int nId);                         // 0x141bd1180 NULL when the id is free
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                      // 0x141bd30a0 the current field data
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    static class WorldService* GetInstance();
};

class Unk_UmvClock;
class CMainSystem   // C3: member view for the former free stand-ins
{
public:
    double FUN_141473280();
    double GetDeltaTime();
};
void FUN_14107b010();                                           // refreshes the sun direction constants
void FUN_14107b050(const NiPoint3& kDirection);                 // sets the sun direction constants
void FUN_1418bf270(float* pAngle);                              // wraps an angle (degrees)
void FUN_141568a10(NiNode* pRoot);
void FUN_1415687f0(class NiAVObject*);   // C3: was FUN_1415687f0
void FUN_141568880(class NiAVObject*);   // C3: was FUN_141568880
class Unk_UmvEffectMgr;
class Unk_AeFeatureMgr   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AeFeatureMgr* FUN_1409a8b20();
};
class PostProcessingService   // C3: member view for the former free stand-ins
{
public:
    void FUN_1416aac60(class NiAVObject*);
};
extern efd::Point3 DAT_143b01a60;                               // zero
float FUN_140bf4fd0(float f);                                   // the float ceil overload (out of line in the exe)
NiPoint3& FUN_14097faa0(NiPoint3* pDst, NiPoint3&& kSrc);       // NiPoint3 move assignment (out of line in the exe)
// The exe's NiPoint3 copies and assignments are out-of-line calls; this view of a NiPoint3 member declares them.
struct Unk_MvPoint3
{
    float x, y, z;
    Unk_MvPoint3(const efd::Point3& pt);                        // 0x14027dcf0
    Unk_MvPoint3& operator=(Unk_MvPoint3&& pt);                 // 0x14097faa0
};
NiPoint3& FUN_14097fad0(NiPoint3* pDst, const NiPoint3& kSrc);  // NiPoint3 copy assignment (out of line in the exe)
extern efd::Point3 DAT_143a08cf8;                                // (0, 0, 1)
void FUN_140e68a40(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const float* pA, const float* pB, const float* pC);
void FUN_140e69060(NiQuaternion* pQuat, float fX, float fY, float fZ);
void FUN_140e69330(float fAngle, float* pSin, float* pCos);
float FUN_1409f25a0(float fAngle);                              // sin
float FUN_1409f2310(float fAngle);                              // cos

// @0x140e66920
UIModelView::~UIModelView()
{
    vfunc_10(0);
}

// @0x140e66980
UIRenderView* FUN_140e66980(int nWidth, int nHeight, GameObject* pObject, float fLightDimmer)
{
    return EE_NEW UIModelView(nWidth, nHeight, pObject, fLightDimmer);
}

// @0x140e66a30
void UIModelView::vfunc_2()
{
    if (m_spCamera)
    {
        FUN_140e685d0();
        FUN_14107b050(m_spCamera->GetWorldDirection());
        FUN_141ab7b80(0);
    }
}

// @0x140e66aa0
void UIModelView::vfunc_3()
{
    UIRenderView::vfunc_3();
    FUN_14107b010();
    MS2Ptr<CFieldDataCli> spField = ((class Unk_UmvWorld*)WorldService::GetInstance())->FUN_141bd30a0();
    if (spField)
        FUN_141ab7b80(spField->m_bFog);
}

// @0x140e66b20
void UIModelView::vfunc_5(float)
{
    if (m_spCamera && m_nZoomState == 0)
    {
        m_nZoomState = 1;
        m_kZoomStart = m_spCamera->GetTranslate();
    }
}

// @0x140e66bb0
void UIModelView::vfunc_6(float)
{
    if (m_spCamera && m_nZoomState == 0)
    {
        m_nZoomState = 2;
        m_kZoomStart = m_spCamera->GetTranslate();
    }
}

// @0x140e66c40
void UIModelView::vfunc_7(float fX, float fY, float fZ)
{
    if (m_nZoomState != 0)
        m_nZoomState = 0;
    float fScale = 0.1f;
    NiPoint3 kAngle(fX * fScale, fY * fScale, fZ * fScale);
    kAngle += m_kRotation;
    NiMatrix3 kRotate;
    kRotate.MakeIdentity();
    FUN_1418bf270(&kAngle.x);
    FUN_1418bf270(&kAngle.y);
    FUN_1418bf270(&kAngle.z);
    m_kRotation = kAngle;
    NiQuaternion kQuat;
    FUN_140e69060(&kQuat, (kAngle.x * 3.1415927f) / 180.0f, (kAngle.y * 3.1415927f) / 180.0f, (kAngle.z * 3.1415927f) / 180.0f);
    kQuat.ToRotation(kRotate);
    NiPoint3 kPos(kRotate * (m_kBackupTranslate - m_kBackupCenter) + m_kBackupCenter);
    NiPoint3 kUp(kRotate * m_kBackupUp);
    m_spCamera->SetTranslate(kPos);
    m_spCamera->Update((float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
    m_spCamera->LookAtWorldPoint(m_kCamera.m_kTarget, kUp);
    m_spCamera->Update((float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
}

// @0x140e66fa0
// MS2-FUNCTIONAL: in the exe only the new position (a local NiPoint3 without a ctor) is computed inside the if;
// SetTranslate(kNew) and Update run after it unconditionally (0x140e67131), so when the camera is already past the
// limit the exe moves it to an uninitialised stack point. Here the camera is left in place instead.
void UIModelView::vfunc_8(float fDist)
{
    if (m_nZoomState != 0)
        m_nZoomState = 0;
    fDist = (std::min)(m_kCamera.m_fMinDistance, fDist);   // sic: the exe takes min here (0x1409ffe80), not max
    if ((m_kCamera.m_kPosition - m_spCamera->GetTranslate()).Length() < fDist)
    {
        NiPoint3 kDir = -m_spCamera->GetWorldDirection();
        m_spCamera->SetTranslate(NiPoint3(m_kCamera.m_kPosition + kDir * fDist));
        m_spCamera->Update((float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
    }
}

// @0x140e67140
// MS2-FUNCTIONAL: in the exe only the new position (a local NiPoint3 without a ctor) is computed inside the if;
// SetTranslate(kNew) and Update run after it unconditionally (0x140e67131), so when the camera is already past the
// limit the exe moves it to an uninitialised stack point. Here the camera is left in place instead.
void UIModelView::vfunc_9(float fDist)
{
    if (m_nZoomState != 0)
        m_nZoomState = 0;
    fDist = (std::max)(m_kCamera.m_fMaxDistance, fDist);   // sic: the exe takes max here (0x140805fc0), not min
    if (fDist < (m_kCamera.m_kPosition - m_spCamera->GetTranslate()).Length())
    {
        NiPoint3 kDir = -m_spCamera->GetWorldDirection();
        m_spCamera->SetTranslate(NiPoint3(m_kCamera.m_kPosition + kDir * fDist));
        m_spCamera->Update((float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
    }
}

// @0x140e672e0
void UIModelView::vfunc_10(int nObjectId)
{
    if (nObjectId != m_nObjectId)
    {
        if (m_spClick)
            m_spClick->vfunc_14();
    }
    UIRenderView::vfunc_10(nObjectId);
}

// @0x140e67350
void UIModelView::vfunc_12(const ATL::CAtlArray<NiNode*>& arrNodes, NiNodePtr spRoot)
{
    if (!m_spClick)
        return;
    m_spClick->vfunc_14();
    FUN_141568a10(m_spEffectRoot);
    if (arrNodes.GetCount() < 1)
        return;
    if (spRoot)
        m_spEffectRoot->AttachChild(spRoot, false);
    m_spEffectRoot->DetachEffect(m_spDirLight);
    m_spEffectRoot->DetachEffect(m_spAmbientLight);
    m_spEffectRoot->AttachEffect(m_spDirLight);
    m_spEffectRoot->AttachEffect(m_spAmbientLight);
    m_spEffectRoot->UpdateEffects();
    m_spClick->vfunc_12(m_spEffectRoot);
    unsigned int nCount = (unsigned int)arrNodes.GetCount();
    for (unsigned int i = 0; i < nCount; ++i)
    {
        NiNode* pNode = arrNodes[i];
        if (pNode != 0)
        {
            FUN_1415687f0((class NiAVObject*)(pNode));
            FUN_141568880((class NiAVObject*)(pNode));
            pNode->DetachEffect(m_spDirLight);
            pNode->DetachEffect(m_spAmbientLight);
            pNode->AttachEffect(m_spDirLight);
            pNode->AttachEffect(m_spAmbientLight);
            pNode->UpdateEffects();
            m_spClick->vfunc_12(pNode);
            ((class PostProcessingService*)(class Unk_UmvEffectMgr*)(((class Unk_UmvEffectMgr*)Unk_AeFeatureMgr::FUN_1409a8b20())))->FUN_1416aac60((class NiAVObject*)(pNode));
        }
    }
}

// @0x140e67710
int UIModelView::vfunc_13(const Unk_ModelViewCamera& kCamera)
{
    if (!m_spCamera)
        vfunc_15();
    m_kCamera = kCamera;
    const NiPoint3& kTarget = m_kCamera.m_kTarget;
    const NiPoint3& kPos = m_kCamera.m_kPosition;
    m_spCamera->SetTranslate(kPos);
    m_spCamera->Update((float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
    m_spCamera->LookAtWorldPoint(kTarget, DAT_143a08cf8);
    m_spCamera->Update((float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
    float fDist = (kTarget - kPos).Length();
    float fMin = m_kCamera.m_fMinDistance;
    float fMax = m_kCamera.m_fMaxDistance;
    fMin = fMin > fDist ? fMin : fDist;
    fMax = fMax < fDist ? fMax : fDist;
    NiPoint3 kDir = -m_spCamera->GetWorldDirection();
    m_nZoomState = 0;
    reinterpret_cast<Unk_MvPoint3&>(m_kZoomStart) = DAT_143b01a60;
    reinterpret_cast<Unk_MvPoint3&>(m_kNearPosition) = kTarget + kDir * fMin;
    reinterpret_cast<Unk_MvPoint3&>(m_kFarPosition) = kTarget + kDir * fMax;
    m_kCamera.m_fMinDistance = fMin;
    m_kCamera.m_fMaxDistance = fMax;
    m_kCamera.m_nSteps = m_kCamera.m_nSteps < 1 ? 1 : m_kCamera.m_nSteps;
    m_kCamera.m_fStep = (fMin - fMax) / (float)m_kCamera.m_nSteps;
    int nDone = m_kCamera.m_nStepsDone < m_kCamera.m_nSteps ? m_kCamera.m_nStepsDone : m_kCamera.m_nSteps;
    if (nDone > 0)
    {
        NiPoint3 kNewPos = kPos;
        float fOffset = m_kCamera.m_fStep * (float)nDone;
        kNewPos += kDir * fOffset;
        m_spCamera->SetTranslate(kNewPos);
        m_spCamera->Update((float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
    }
    return 1;
}

// @0x140e67c20
void UIModelView::vfunc_17(const NiPoint3& kPivot)
{
    if (m_spCamera == 0)
        return;
    reinterpret_cast<Unk_MvPoint3&>(m_kRotation) = DAT_143b01a60;
    const NiPoint3& kTranslate = m_spCamera->GetTranslate();
    reinterpret_cast<Unk_MvPoint3&>(m_kBackupTranslate) = kTranslate;
    FUN_14097fad0(&m_kBackupCenter, kPivot);
    FUN_14097faa0(&m_kBackupUp, m_spCamera->GetWorldUpVector());
    FUN_140e68a40(CLogString::GetInstance(), 0xc, 0x13, L"UIModelView::m_backupTranslate: {0}, {1}, {2}",
                  &m_kBackupTranslate.x, &m_kBackupTranslate.y, &m_kBackupTranslate.z);
    FUN_140e68a40(CLogString::GetInstance(), 0xc, 0x13, L"UIModelView::m_backupCenter: {0}, {1}, {2}",
                  &m_kBackupCenter.x, &m_kBackupCenter.y, &m_kBackupCenter.z);
}

// @0x140e67e30
UIModelView::UIModelView(unsigned int uiWidth, unsigned int uiHeight, GameObject* pObject, float fLightDimmer)
    : UIRenderView(uiWidth, uiHeight, pObject, fLightDimmer), m_kFarPosition(DAT_143b01a60), m_kNearPosition(DAT_143b01a60),
      m_nZoomState(0), m_kZoomStart(DAT_143b01a60), m_kBackupTranslate(DAT_143b01a60), m_kRotation(DAT_143b01a60),
      m_kBackupCenter(DAT_143b01a60), m_kBackupUp(DAT_143a08cf8)
{
}

// @0x140e67f80
int UIModelView::vfunc_14()
{
    m_spDirLight = EE_NEW NiDirectionalLight();
    m_spDirLight->SetDimmer(m_fLightDimmer);
    m_spDirLight->SetAmbientColor(NiColor(0.0f, 0.0f, 0.0f));
    m_spDirLight->SetDiffuseColor(NiColor(1.0f, 1.0f, 1.0f));
    m_spDirLight->SetSpecularColor(NiColor(1.0f, 1.0f, 1.0f));
    NiMatrix3 kRotX;
    NiMatrix3 kRotY;
    NiMatrix3 kRotZ;
    float fAngleX = 11.5f;
    float fAngleY = 68.9f;
    float fAngleZ = 180.0f;
    kRotX.MakeXRotation((fAngleX * 3.1415927f) / 180.0f);
    kRotY.MakeYRotation((fAngleY * 3.1415927f) / 180.0f);
    kRotZ.MakeZRotation((fAngleZ * 3.1415927f) / 180.0f);
    m_spDirLight->SetRotate(kRotX * kRotY * kRotZ);
    m_spDirLight->Update((float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
    m_spAmbientLight = EE_NEW NiAmbientLight();
    m_spAmbientLight->SetDimmer(m_fLightDimmer);
    m_spAmbientLight->SetAmbientColor(NiColor(1.0f, 1.0f, 1.0f));
    m_spAmbientLight->SetDiffuseColor(NiColor(0.0f, 0.0f, 0.0f));
    m_spAmbientLight->SetSpecularColor(NiColor(0.0f, 0.0f, 0.0f));
    return 1;
}

// @0x140e68420
int UIModelView::vfunc_15()
{
    float fMax = (float)(m_uiWidth > m_uiHeight ? m_uiWidth : m_uiHeight);
    float fHalfWidth = ((float)m_uiWidth / fMax) * 0.5f;
    float fHalfHeight = ((float)m_uiHeight / fMax) * 0.5f;
    m_spCamera = EE_NEW NiCamera();
    m_spCamera->SetViewFrustum(NiFrustum(-fHalfWidth, fHalfWidth, fHalfHeight, -fHalfHeight, 10.0f, 100000.0f, false));
    return 1;
}

// @0x140e685d0
void UIModelView::FUN_140e685d0()
{
    if ((unsigned int)m_nObjectId > 0)
    {
        GameObject* pObject = ((class Unk_UmvWorld*)WorldService::GetInstance())->FUN_141bd1180(m_nObjectId);
        if (pObject != 0)
        {
            if (m_nZoomState != 0)
            {
                NiPoint3 kTarget = m_kCamera.m_kTarget;
                NiPoint3 kPos = m_spCamera->GetTranslate();
                float fDist = (kTarget - kPos).Length();
                float fDelta = (float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->GetDeltaTime();
                NiPoint3 kDir = -m_spCamera->GetWorldDirection();
                if (m_nZoomState == 1)
                {
                    if (fDist > m_kCamera.m_fMaxDistance)
                    {
                        float fMove = -FUN_140bf4fd0((fDist < m_kCamera.m_fSpeed ? fDist : m_kCamera.m_fSpeed) * fDelta);
                        kPos += kDir * fMove;
                        fDist = (kTarget - kPos).Length();
                        if (fDist <= m_kCamera.m_fMaxDistance)
                        {
                            FUN_14097fad0(&kPos, m_kFarPosition);
                            m_nZoomState = 0;
                        }
                    }
                    else
                    {
                        FUN_14097fad0(&kPos, m_kFarPosition);
                        m_nZoomState = 0;
                    }
                }
                else if (m_nZoomState == 2)
                {
                    if (fDist < m_kCamera.m_fMinDistance)
                    {
                        float fMove = FUN_140bf4fd0((fDist < m_kCamera.m_fSpeed ? fDist : m_kCamera.m_fSpeed) * fDelta);
                        kPos += kDir * fMove;
                        fDist = (kTarget - kPos).Length();
                        if (fDist >= m_kCamera.m_fMinDistance)
                        {
                            FUN_14097fad0(&kPos, m_kNearPosition);
                            m_nZoomState = 0;
                        }
                    }
                    else
                    {
                        FUN_14097fad0(&kPos, m_kNearPosition);
                        m_nZoomState = 0;
                    }
                }
                if (m_nZoomState != 0 && (m_kZoomStart - kPos).Length() >= m_kCamera.m_fStep)
                    m_nZoomState = 0;
                m_spCamera->SetTranslate(kPos);
                m_spCamera->Update((float)((class CMainSystem*)(class Unk_UmvClock*)(((class Unk_UmvClock*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
            }
        }
    }
}

// @0x140e68a40
void FUN_140e68a40(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const float* pA, const float* pB, const float* pC)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(*pA),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(*pB),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(*pC)};
    pLog->FUN_1406530d0(nLevel, nCategory, szFormat, fmt::ArgList(fmt::internal::make_type(*pA, *pB, *pC), args));
}

// @0x140e69060
void FUN_140e69060(NiQuaternion* pQuat, float fX, float fY, float fZ)
{
    float fSinX, fCosX, fSinY, fCosY, fSinZ, fCosZ;
    FUN_140e69330(fX * 0.5f, &fSinX, &fCosX);
    FUN_140e69330(fY * 0.5f, &fSinY, &fCosY);
    FUN_140e69330(fZ * 0.5f, &fSinZ, &fCosZ);
    pQuat->m_fW = fCosZ * fCosY * fCosX + fSinZ * fSinY * fSinX;
    pQuat->m_fX = fCosZ * fCosY * fSinX - fSinZ * fSinY * fCosX;
    pQuat->m_fY = fCosZ * fSinY * fCosX + fSinZ * fCosY * fSinX;
    pQuat->m_fZ = -fCosZ * fSinY * fSinX + fSinZ * fCosY * fCosX;
}

// @0x140e69330
void FUN_140e69330(float fAngle, float* pSin, float* pCos)
{
    *pSin = FUN_1409f25a0(fAngle);
    *pCos = FUN_1409f2310(fAngle);
}

// the UCRT memmove_s this TU emits
// @0x140e69380
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
