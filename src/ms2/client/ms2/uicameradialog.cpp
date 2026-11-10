// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICameraDialog: see uicameradialog.h.
// MS2-UNIT: ?\uicameradialog.cpp
// MS2-RANGE: 0x141031f80-0x141033200 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicameradialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uicameradialog.h"

#include "cameramode.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/astextinput.h"
#include <NiCamera.h>
#include <errno.h>
#include <string.h>

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The camera manager's current-mode holder (+0x118 of the manager singleton).
struct Unk_CdModeRef
{
    void* m_pad_00;
    CCameraMode* m_p;
};
struct Unk_CdView                                               // the part of the camera manager used here
{
    char m_pad_00[0x118];
    Unk_CdModeRef m_mode;                                       // +0x118 current camera mode
};
MS2_CHECK_OFFSET(Unk_CdView, m_mode, 0x118);

// The text input of the dialog; the handle is a 16-byte MS2Ptr whose get / -> / release live in the unit that owns the
// shared instance.
class Unk_CdInput : public ASDisplayObject
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
    virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool b);
};

MS2Ptr<AScript> FUN_1409e7dc0(int nMovieId, const Scaleform::GFx::Value& v);

class CStateService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1417e2610();
};
class CameraMgr   // C3: member view for the former free stand-ins
{
public:
    int FUN_140a18070();
    void FUN_140af9b40(float);
    void FUN_140aec8a0(bool bKeep);   // C3: was FUN_140aec8a0
    CCameraMode* GetTargetMode();     // C3: was Unk_CameraManager::GetTargetMode
    float FUN_140ad4b40();            // C3: was Unk_CameraManager::FUN_140ad4b40
    float FUN_140b67d10();            // C3: was Unk_CameraManager::FUN_140b67d10
};
template <class T> class TSingleton;
template <> class TSingleton<CameraMgr> { public: static CameraMgr* GetInstance(); };         // 0x1409478c0, as in camera.h
template <> class TSingleton<CStateService> { public: static CStateService* GetInstance(); };  // 0x140aa6d30, as in statemanager.h
float FUN_1409f2430(CameraMgr* pCam);                   // distance
void FUN_140ad4ff0(CameraMgr* pCam, float fValue);      // field of view
void FUN_140b6bd30(void*);   // C3: was FUN_140b6bd30
float FUN_140bf4fd0(float f);                                   // ceilf
void* FUN_1413f9950();   // C3: was FUN_1413f9950


// The manager's accessors defined in this unit (the first two are also declared, with void*, by unit_141274d10).
int FUN_141032bb0(ASObj* pObj);
void FUN_141032d40(CCameraMode* pMode, float* pA, float* pB);
float FUN_141032d80(void* pCam);
float FUN_141032df0(void* pCam);
float FUN_141032e60(void* pCam);
void FUN_141032ed0(void* pCam, float f);
void FUN_141032f30(void* pCam, float f);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141031f80
UICameraDialog::UICameraDialog()
{
    m_40 = 1;
}

// @0x141031fd0
UICameraDialog::~UICameraDialog()
{
}

// @0x141032010
CString UICameraDialog::GetTypeName()
{
    return "CameraDialog";
}

// @0x141032060
void UICameraDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj obj(2);
    FUN_141032bb0(&obj);
    m_30->Invoke("initData", obj.FUN_1422bb870());
}

// @0x141032120
int UICameraDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onChangeSliderFOV", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_1410326e0(data);
        return 1;
    }
    else if (_stricmp("onClickReset", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_141032780(data);
        return 1;
    }
    else if (_stricmp("onClickApplyMinDistance", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_141032a90(data);
        return 1;
    }
    else if (_stricmp("onClickApplyMaxDistance", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_141032970(data);
        return 1;
    }
    else if (_stricmp("onClickApplyNearFar", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_1410328d0(data);
        return 1;
    }
    return 0;
}

// @0x1410323f0
void UICameraDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (vfunc_55() != 0)
        return;
    {
        if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() != 0) {
            {
                CString strName("m_distance");
                FUN_141032560(strName, FUN_1409f2430(TSingleton<CameraMgr>::GetInstance()));
            }
            {
                CString strName("m_hAngle");
                FUN_141032560(strName, FUN_141032d80(TSingleton<CameraMgr>::GetInstance()));
            }
            {
                CString strName("m_vAngle");
                FUN_141032560(strName, FUN_141032e60(TSingleton<CameraMgr>::GetInstance()));
            }
            float fOffset;
            FUN_141032d40(TSingleton<CameraMgr>::GetInstance()->GetTargetMode(), &fOffset, &fOffset);
            {
                CString strName("m_heightOffset");
                FUN_141032560(strName, fOffset);
            }
        }
    }
}

// @0x141032560
void UICameraDialog::FUN_141032560(const CString& strName, float f)
{
    if (MS2Ptr<ASTextField> spText = GetChild<ASTextField>(strName)) {
        CString str;
        str.Format("%.1f", (double)f);
        spText->SetTextA(str);
    }
}

// @0x141032610
void UICameraDialog::FUN_141032610(const CString& strName, float f)
{
    MS2Ptr<ASTextInput> spInput = GetChild<ASTextInput>(strName);
    if (spInput) {
        CString str;
        str.Format("%.1f", (double)f);
        spInput->SetTextA(str);
        Unk_CdInput* pInput = reinterpret_cast<Unk_CdInput*>(spInput.operator->());
        pInput->vfunc_24(true);
    }
}

// @0x1410326e0
void UICameraDialog::FUN_1410326e0(ASData& data)
{
    if (TSingleton<CStateService>::GetInstance()->FUN_1417e2610() == 0x620000d)
        return;
    float fRaw = data.PopFloat();
    float fFov = fRaw;
    fFov = FUN_140bf4fd0(fFov);
    if (fFov <= 0.0f)
        fFov = 1.0f;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() == 0)
        return;
    FUN_140ad4ff0((TSingleton<CameraMgr>::GetInstance()), fFov);
}

// @0x141032780
void UICameraDialog::FUN_141032780(ASData& data)
{
    Scaleform::GFx::Value vRoot = data.PopValue();
    MS2Ptr<AScript> spRoot = FUN_1409e7dc0(m_28, vRoot);
    if (((MS2Ptr<AScript>*)(void*)(&spRoot))->IsNull())
        return;
    if (TSingleton<CStateService>::GetInstance()->FUN_1417e2610() == 0x620000d)
        return;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() == 0)
        return;
    TSingleton<CameraMgr>::GetInstance()->FUN_140aec8a0(false);
    FUN_140b6bd30((void*)(TSingleton<CameraMgr>::GetInstance()));
    FUN_141032bb0(static_cast<ASObj*>(spRoot.get()));
    float fZoom = WorldService::GetInstance()->FUN_141bcfc50();
    static_cast<ASObj*>(spRoot.operator->())->SetMemberFloat("fov", fZoom);
}

// @0x1410328d0
void UICameraDialog::FUN_1410328d0(ASData& data)
{
    float fNear = data.PopFloat();
    float fFar = data.PopFloat();
    NiCamera* pCamera = ((class NiCamera*)FUN_1413f9950());
    if (pCamera != 0) {
        NiFrustum kFrustum = pCamera->GetViewFrustum();
        kFrustum.m_fNear = fNear;
        kFrustum.m_fFar = fFar;
        pCamera->SetViewFrustum(kFrustum);
    }
}

// @0x141032970
void UICameraDialog::FUN_141032970(ASData& data)
{
    if (TSingleton<CStateService>::GetInstance()->FUN_1417e2610() == 0x620000d)
        return;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() != 0) {
        float fMax = data.PopFloat();
        fMax = FUN_141032df0(TSingleton<CameraMgr>::GetInstance()) > fMax ? FUN_141032df0(TSingleton<CameraMgr>::GetInstance()) : fMax;
        CString strName = data.FUN_1422b8d30();
        if (!strName.IsEmpty())
            FUN_141032610(strName, fMax);
        TSingleton<CameraMgr>::GetInstance()->FUN_140af9b40(fMax);
        FUN_141032ed0((TSingleton<CameraMgr>::GetInstance()), fMax);
        FUN_140b6bd30((void*)(TSingleton<CameraMgr>::GetInstance()));
    }
}

// @0x141032a90
void UICameraDialog::FUN_141032a90(ASData& data)
{
    if (TSingleton<CStateService>::GetInstance()->FUN_1417e2610() == 0x620000d)
        return;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() != 0) {
        float fMin = data.PopFloat();
        fMin = TSingleton<CameraMgr>::GetInstance()->FUN_140b67d10() < fMin ? TSingleton<CameraMgr>::GetInstance()->FUN_140b67d10() : fMin;
        CString strName = data.FUN_1422b8d30();
        if (!strName.IsEmpty())
            FUN_141032610(strName, fMin);
        FUN_141032f30((TSingleton<CameraMgr>::GetInstance()), fMin);
        FUN_141032ed0((TSingleton<CameraMgr>::GetInstance()), fMin);
        FUN_140b6bd30((void*)(TSingleton<CameraMgr>::GetInstance()));
    }
}

// @0x141032bb0
int FUN_141032bb0(ASObj* pObj)
{
    float fFov = 1.0f;
    float fMax = 0.0f;
    float fMin = 0.0f;
    float fNear = 0.0f;
    float fFar = 0.0f;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() != 0) {
            fFov = TSingleton<CameraMgr>::GetInstance()->FUN_140ad4b40();
            fMax = TSingleton<CameraMgr>::GetInstance()->FUN_140b67d10();
            fMin = FUN_141032df0(TSingleton<CameraMgr>::GetInstance());
            NiCamera* pCamera = ((class NiCamera*)FUN_1413f9950());
            if (pCamera != 0) {
                const NiFrustum& kFrustum = pCamera->GetViewFrustum();
                fNear = kFrustum.m_fNear;
                fFar = kFrustum.m_fFar;
            }
    }
    pObj->SetMemberFloat("fov", fFov);
    pObj->SetMemberFloat("maxDistance", fMax);
    pObj->SetMemberFloat("minDistance", fMin);
    pObj->SetMemberFloat("near", fNear);
    pObj->SetMemberFloat("far", fFar);
    return 1;
}

// @0x141032d40
void FUN_141032d40(CCameraMode* pMode, float* pA, float* pB)
{
    *pA = pMode->m_60;
    *pB = pMode->m_64;
}

// @0x141032d80
float FUN_141032d80(void* pCam)
{
    if (reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode).get() != 0)
        return reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode)->vfunc_23() * 180.0f / 3.1415927f;
    return 0.0f;
}

// @0x141032df0
float FUN_141032df0(void* pCam)
{
    if (reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode).get() != 0)
        return reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode)->vfunc_15();
    return 0.0f;
}

// @0x141032e60
float FUN_141032e60(void* pCam)
{
    if (reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode).get() != 0)
        return reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode)->vfunc_22() * 180.0f / 3.1415927f;
    return 0.0f;
}

// @0x141032ed0
void FUN_141032ed0(void* pCam, float f)
{
    if (reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode).get() != 0)
        reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode)->vfunc_20(f);
}

// @0x141032f30
void FUN_141032f30(void* pCam, float f)
{
    if (reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode).get() != 0)
        reinterpret_cast<MS2Ptr<CCameraMode>&>(((Unk_CdView*)pCam)->m_mode)->vfunc_14(f);
}

// @0x141032e50
int UICameraDialog::vfunc_48()
{
    return 0x4eb6;
}

// The UCRT's header-inline memcpy_s of this TU (0x141032f90), kept alive through ATL::Checked.
// @0x141032f90
#pragma function(memset, memcpy)
static __inline errno_t ms2_cd_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnCdMemcpyS)(void*, size_t, const void*, size_t) = &ms2_cd_memcpy_s;

MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x141032010, UICameraDialog, GetTypeName, 61, 0x4CF0D4E6);
MS2_REPLACE_METHOD(0x141032060, UICameraDialog, OnLoadComplete, 186, 0x7D704146);
MS2_REPLACE_METHOD(0x141032120, UICameraDialog, vfunc_28, 689, 0x5F6A272A);
MS2_REPLACE_METHOD(0x1410323F0, UICameraDialog, vfunc_72, 351, 0x34E2F5B0);
MS2_REPLACE_METHOD(0x141032560, UICameraDialog, FUN_141032560, 160, 0xC59F8B1E);
MS2_REPLACE_METHOD(0x141032610, UICameraDialog, FUN_141032610, 196, 0xAD37A14A);
MS2_REPLACE_METHOD(0x1410326E0, UICameraDialog, FUN_1410326e0, 153, 0xDF0D88BB);
MS2_REPLACE_METHOD(0x141032780, UICameraDialog, FUN_141032780, 315, 0x04F91510);
MS2_REPLACE_METHOD(0x1410328D0, UICameraDialog, FUN_1410328d0, 140, 0xE63D9F60);
MS2_REPLACE_METHOD(0x141032970, UICameraDialog, FUN_141032970, 273, 0x176E6778);
MS2_REPLACE_METHOD(0x141032A90, UICameraDialog, FUN_141032a90, 273, 0x3476B551);
MS2_REPLACE_METHOD(0x141032E50, UICameraDialog, vfunc_48, 11, 0x5EDFFB5F);
MS2_REPLACE(0x141032BB0, FUN_141032bb0, 323, 0xDAD2A6DA);
MS2_REPLACE(0x141032D40, FUN_141032d40, 54, 0x57A21861);
MS2_REPLACE(0x141032D80, FUN_141032d80, 102, 0xA877E9EA);
MS2_REPLACE(0x141032DF0, FUN_141032df0, 83, 0x09D49DA9);
MS2_REPLACE(0x141032E60, FUN_141032e60, 102, 0x72E131EF);
MS2_REPLACE(0x141032ED0, FUN_141032ed0, 93, 0x528F96DB);
MS2_REPLACE(0x141032F30, FUN_141032f30, 90, 0x4E410C02);
