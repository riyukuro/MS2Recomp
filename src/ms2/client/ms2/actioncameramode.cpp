// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CActionCameraMode: see actioncameramode.h. The obj also
// owns the inline helpers of CameraMgr / Camera it uses and the first instance of MS2's Entity::SetPropertyValue<float>
// with its property-cache map glue (efd::map<unsigned, Unk_PropertyCacheEntry>, placeholder/propertycache.h).
// MS2-UNIT: ?\actioncameramode.cpp
// MS2-RANGE: 0x140944f30-0x140948420 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\actioncameramode.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "actioncameramode.h"
#include "camera.h"
#include "ms2/placeholder/propertycache.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

Unk_CameraSetting* FUN_140947880(CCameraMode* p);

// @0x140944f30
CActionCameraMode::CActionCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CCameraMode(pOwner, pPrev)
{
}

// @0x140944fb0
CActionCameraMode::~CActionCameraMode()
{
}

// @0x140944fe0
void CActionCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    CameraMgr::GetInstance()->FUN_140947860(0);
    m_fTime = 0;
}
MS2_REPLACE_METHOD(0x140944FE0, CActionCameraMode, vfunc_6, 60, 0xCB942A8A);

// @0x140945030
void CActionCameraMode::vfunc_7()
{
    CCameraMode::vfunc_7();
    CameraMgr::GetInstance()->FUN_140947860(1);
}
MS2_REPLACE_METHOD(0x140945030, CActionCameraMode, vfunc_7, 42, 0x1C606877);

// @0x140945060
// Plays the camera effect nif: the "Camera01" node gives the look-at point and the angles, the FOV interpolator the
// distance; at the end of the animation the camera flies back to the previous mode's setting (or keeps this one).
void CActionCameraMode::vfunc_8(double fTime)
{
    Unk_CameraEffectState* pEffect = CameraMgr::GetInstance()->FUN_1409478a0();
    m_fTime += (float)fTime;
    double fNow = m_fTime;
    if (pEffect->m_fMaxTime <= fNow)
        fNow = pEffect->m_fMaxTime;
    if (pEffect->m_spCameraNode)
    {
        pEffect->m_spCameraNode->Update((float)fNow, true);
        NiPoint3 kLook = pEffect->m_spCameraNode->GetWorldTransform().m_Translate;
        Unk_StreamPoint ptLook = *(const Unk_StreamPoint*)&kLook;
        vfunc_3(ptLook);
        Unk_StreamPoint ptRot = g_143b01a60;
        pEffect->m_pCamera->GetWorldTransform().m_Rotate.ToEulerAnglesXYZ(ptRot.x, ptRot.y, ptRot.z);
        ptRot.x = -(ptRot.x * 180.0f / 3.1415927f);
        ptRot.y = -(ptRot.y * 180.0f / 3.1415927f);
        ptRot.z = -(ptRot.z * 180.0f / 3.1415927f);
        vfunc_4(ptRot);
        if (pEffect->m_spFOV)
            m_pOwner->FUN_140947940(static_cast<Unk_FOVInterpolator*>(pEffect->m_spFOV.operator->())->FUN_141c2f230() * 180.0f / 3.1415927f);
    }
    BOOL bEnd = pEffect->m_fMaxTime <= fNow;
    if (bEnd)
    {
        m_pOwner->FUN_140947940(pEffect->m_fFOV);
        if (pEffect->m_24 != 0)
        {
            CameraMgr::GetInstance()->FUN_140aed720(m_setting);
            CameraMgr::GetInstance()->FUN_140947980(4);
        }
        else
        {
            if (pEffect->m_20 != 0.0f)
            {
                Unk_CameraFlyBy kFlyBy;
                kFlyBy.m_nKind = 0;
                kFlyBy.m_fDuration = pEffect->m_20;
                kFlyBy.m_from = m_setting;
                kFlyBy.m_to = *FUN_140947880(CameraMgr::GetInstance()->FUN_140af24f0());
                CameraMgr::GetInstance()->FUN_140aed580(&kFlyBy, 1, 1.0f);
            }
            CameraMgr::GetInstance()->FUN_140947980(2);
        }
        CameraMgr::GetInstance()->FUN_140af1a90();
    }
}
MS2_REPLACE_METHOD(0x140945060, CActionCameraMode, vfunc_8, 993, 0xFE4B151C);

// @0x140945450
void CActionCameraMode::vfunc_9()
{
}
MS2_REPLACE_METHOD(0x140945450, CActionCameraMode, vfunc_9, 6, 0xA9AF6E37);

// @0x140945460
int CActionCameraMode::vfunc_28()
{
    return 0;
}
MS2_REPLACE_METHOD(0x140945460, CActionCameraMode, vfunc_28, 8, 0x7F371472);

// @0x140945470
Unk_StreamPoint CActionCameraMode::vfunc_26()
{
    NiNode* pNode = CameraMgr::GetInstance()->FUN_1409478a0()->m_spCameraNode;
    return pNode ? *(const Unk_StreamPoint*)&static_cast<const NiPoint3&>(NiPoint3(pNode->GetWorldTranslate()))
                 : Unk_StreamPoint(0, 0, 0);
}
MS2_REPLACE_METHOD(0x140945470, CActionCameraMode, vfunc_26, 186, 0xDDB40B2A);

// ---- MS2's Entity::SetPropertyValue<float> (first instantiated by Camera::FUN_140947940) ----
template egf::PropertyResult Unk_CachedEntity::SetPropertyValue<float>(egf::PropertyID propID, const float& data);

// ---- inline helpers of the camera classes (COMDATs of this obj) ----
// @0x140947880
// CCameraMode's setting accessor (a free function in camera.cpp / localtargetcameramode.cpp / triggerservice.cpp).
Unk_CameraSetting* FUN_140947880(CCameraMode* p)
{
    return &p->m_setting;
}

// @0x140947440
Unk_CameraFlyBy::Unk_CameraFlyBy()
{
}

// @0x1409478c0
CameraMgr* TSingleton<CameraMgr>::GetInstance()
{
    return s_instance;
}

// @0x140947940
void Unk_CameraOwner::FUN_140947940(float f)
{
    if (m_10)
        m_10->FUN_1409457c0(0x88b558f6, f);
}

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x1400bf250-0x1400bf390 .text$di
// MS2-RANGE: 0x142c9d2f0-0x142c9d360 .text$yd
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill("skill");
static CString s_strStun("stun");
// The fourth initializer (0x1400bf370) is egf::kENTITY_INVALID of <egf/EntityID.h> (EntityID ctor 0x1401cd100), pinned below.
// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400bf370
