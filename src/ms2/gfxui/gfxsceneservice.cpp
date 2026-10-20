// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxSceneService, the efd system service that switches the
// UI scenes. Declared in src/ms2/placeholder/gfxservice.h.
// MS2-UNIT: ?\gfxsceneservice.cpp
// MS2-RANGE: 0x1422b9cd0-0x1422ba6e0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// COMDAT tail: AddDependency<efd::IConfigManager>, SingletonClass<GFxSceneService>'s ctor/dtor, the implicit dtor and
// the EE_DECLARE_CLASS1 / EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT members.
// MS2-PIN: ??_GGFxSceneService@@UEAAPEAXI@Z 0x1422ba4a0
#include "ms2/placeholder/ms2stdafx.h"

#include <efd/IConfigManager.h>
#include <efd/IServiceDetailRegister.h>

#include "ms2/placeholder/gfxservice.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/gfxui/uisceneentity.h"
#include "hook/ms2hook.h"

void FUN_1411ab770(efd::IDependencyRegistrar* pRegistrar, int nFlags);   // AddDependency<ecr::RenderService> (0x07002001)
void FUN_1410db4c0(efd::IDependencyRegistrar* pRegistrar, int nFlags);   // AddDependency<0x07000003>

// ms_ClassInfo's initializer lives in unit_14013acc0.cpp's .text$di range; this reference emits the SetupClassInfo
// inline here, where the exe has it (0x1422ba5e0).
static efd::ClassInfo::CLASSINFO_FUNC s_pfnSetupClassInfo = &GFxSceneService::SetupClassInfo;

// @0x1422b9cd0
GFxSceneService::GFxSceneService()
    : m_nPrevSceneId(0), m_nSceneId(0), m_nPrevSubSceneId(0), m_nSubSceneId(0), m_pSubScene(NULL), m_pScene(NULL)
{
}

// @0x1422b9d80
const char* GFxSceneService::GetDisplayName() const
{
    return "GFxSceneService";
}
MS2_REPLACE_METHOD(0x1422B9D80, GFxSceneService, GetDisplayName, 13, 0xAEFBC23C);

// @0x1422b9da0
int GFxSceneService::FUN_1422b9da0()
{
    return m_nPrevSceneId;
}
MS2_REPLACE_METHOD(0x1422B9DA0, GFxSceneService, FUN_1422b9da0, 14, 0xA25B27BF);

// @0x1422b9dc0
int GFxSceneService::FUN_1422b9dc0()
{
    return m_nSceneId;
}
MS2_REPLACE_METHOD(0x1422B9DC0, GFxSceneService, FUN_1422b9dc0, 14, 0xBA6447E3);

// @0x1422b9de0
int GFxSceneService::FUN_1422b9de0()
{
    return m_nPrevSubSceneId;
}
MS2_REPLACE_METHOD(0x1422B9DE0, GFxSceneService, FUN_1422b9de0, 14, 0xD26D6807);

// @0x1422b9e00
int GFxSceneService::FUN_1422b9e00()
{
    return m_nSubSceneId;
}
MS2_REPLACE_METHOD(0x1422B9E00, GFxSceneService, FUN_1422b9e00, 14, 0x6A78E4AB);

// @0x1422b9e20
UISceneEntity* GFxSceneService::FUN_1422b9e20(int nSceneId)
{
    return static_cast<UISceneEntity*>(FUN_140b632f0()->FUN_1422d40b0(nSceneId));
}
MS2_REPLACE_METHOD(0x1422B9E20, GFxSceneService, FUN_1422b9e20, 35, 0xAE615F19);

// @0x1422b9e50
UISceneEntity* GFxSceneService::FUN_1422b9e50()
{
    if (m_pSubScene == NULL)
        return m_pScene;
    return m_pSubScene;
}
MS2_REPLACE_METHOD(0x1422B9E50, GFxSceneService, FUN_1422b9e50, 38, 0x08895A49);

// @0x1422b9e80
UISceneEntity* GFxSceneService::FUN_1422b9e80()
{
    return m_pScene;
}
MS2_REPLACE_METHOD(0x1422B9E80, GFxSceneService, FUN_1422b9e80, 15, 0x7BFFD3E9);

// @0x1422b9ea0
int GFxSceneService::FUN_1422b9ea0()
{
    switch (FUN_1422b9e00())
    {
    case 0x6200041:
    case 0x620007f:
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422B9EA0, GFxSceneService, FUN_1422b9ea0, 59, 0x728E7F5C);

// @0x1422b9ef0
int GFxSceneService::FUN_1422b9ef0(int nSceneId)
{
    if (nSceneId != 0 && nSceneId == m_nSceneId)
        return 0;
    m_nPrevSceneId = m_nSceneId;
    UISceneEntity* pPrev = FUN_1422b9e20(m_nPrevSceneId);
    if (pPrev != NULL)
    {
        FUN_1422b9fd0(0);
        pPrev->vfunc_49(nSceneId);
    }
    m_nSceneId = nSceneId;
    UISceneEntity* pNext = FUN_1422b9e20(nSceneId);
    m_pScene = pNext;
    if (pNext != NULL)
        pNext->vfunc_48(m_nPrevSceneId);
    return 1;
}
MS2_REPLACE_METHOD(0x1422B9EF0, GFxSceneService, FUN_1422b9ef0, 213, 0x56705A53);

// @0x1422b9fd0
int GFxSceneService::FUN_1422b9fd0(int nSubSceneId)
{
    if (nSubSceneId != 0 && nSubSceneId == m_nSubSceneId)
        return 0;
    UISceneEntity* pScene = m_pScene;
    if (pScene == NULL)
        return 0;
    m_nPrevSceneId = m_nSceneId;
    m_nPrevSubSceneId = m_nSubSceneId;
    UISceneEntity* pPrev = pScene->FUN_1422e7a70(m_nPrevSubSceneId);
    if (pPrev != NULL)
        pPrev->vfunc_49(nSubSceneId);
    m_nSubSceneId = nSubSceneId;
    UISceneEntity* pNext = pScene->FUN_1422e7a70(nSubSceneId);
    m_pSubScene = pNext;
    if (pNext != NULL)
        pNext->vfunc_48(m_nPrevSubSceneId);
    return 1;
}
MS2_REPLACE_METHOD(0x1422B9FD0, GFxSceneService, FUN_1422b9fd0, 246, 0x2C38FE01);

// @0x1422ba0d0
void GFxSceneService::FUN_1422ba0d0()
{
    if (m_pScene != NULL)
        m_pScene->vfunc_52();
}
MS2_REPLACE_METHOD(0x1422BA0D0, GFxSceneService, FUN_1422ba0d0, 53, 0x650A4ECA);

// @0x1422ba110
void GFxSceneService::FUN_1422ba110()
{
    if (m_pScene != NULL)
        m_pScene->vfunc_58();
}
MS2_REPLACE_METHOD(0x1422BA110, GFxSceneService, FUN_1422ba110, 53, 0xA8F8667A);

// @0x1422ba150
void GFxSceneService::FUN_1422ba150()
{
    if (m_pScene != NULL)
        m_pScene->vfunc_53();
}
MS2_REPLACE_METHOD(0x1422BA150, GFxSceneService, FUN_1422ba150, 53, 0x53A95302);

// @0x1422ba190
void GFxSceneService::FUN_1422ba190()
{
    if (m_pScene != NULL)
        m_pScene->vfunc_54();
}
MS2_REPLACE_METHOD(0x1422BA190, GFxSceneService, FUN_1422ba190, 53, 0x2B29CA5A);

// @0x1422ba1d0
void GFxSceneService::FUN_1422ba1d0()
{
    if (m_pScene != NULL)
        m_pScene->vfunc_55();
}
MS2_REPLACE_METHOD(0x1422BA1D0, GFxSceneService, FUN_1422ba1d0, 53, 0x59095C92);

// @0x1422ba210
void GFxSceneService::FUN_1422ba210()
{
    if (m_pScene != NULL)
        m_pScene->vfunc_56();
}
MS2_REPLACE_METHOD(0x1422BA210, GFxSceneService, FUN_1422ba210, 53, 0xD1130F6A);

// @0x1422ba250
void GFxSceneService::FUN_1422ba250()
{
    if (m_pScene != NULL)
        m_pScene->vfunc_57();
}
MS2_REPLACE_METHOD(0x1422BA250, GFxSceneService, FUN_1422ba250, 53, 0x0D0C5022);

// @0x1422ba290
void GFxSceneService::FUN_1422ba290(void* p, int a, int b)
{
    if (m_pScene != NULL)
        m_pScene->vfunc_59(p, a, b);
}
MS2_REPLACE_METHOD(0x1422BA290, GFxSceneService, FUN_1422ba290, 83, 0xF2598165);

// @0x1422ba2f0
efd::SyncResult GFxSceneService::OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar)
{
    FUN_1411ab770(pDependencyRegistrar, 1);
    pDependencyRegistrar->AddDependency<efd::IConfigManager>(1);
    FUN_1410db4c0(pDependencyRegistrar, 1);
    return efd::SyncResult_Success;
}
MS2_REPLACE_METHOD_VIA(0x1422BA2F0, GFxSceneService, efd::ISystemService, OnPreInit, 69, 0x525A65C5);

// @0x1422ba340
efd::AsyncResult GFxSceneService::OnInit()
{
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD_VIA(0x1422BA340, GFxSceneService, efd::ISystemService, OnInit, 11, 0x620C90F9);

// @0x1422ba360
efd::AsyncResult GFxSceneService::OnTick()
{
    return efd::AsyncResult_Pending;
}
MS2_REPLACE_METHOD_VIA(0x1422BA360, GFxSceneService, efd::ISystemService, OnTick, 11, 0x30025ED0);

// @0x1422ba380
efd::AsyncResult GFxSceneService::OnShutdown()
{
    m_nPrevSceneId = 0;
    m_nSceneId = 0;
    m_nPrevSubSceneId = 0;
    m_nSubSceneId = 0;
    m_pSubScene = NULL;
    m_pScene = NULL;
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD_VIA(0x1422BA380, GFxSceneService, efd::ISystemService, OnShutdown, 85, 0x8B7B2011);
