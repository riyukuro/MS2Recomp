// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxService, the efd system service that owns the game's
// Scaleform integration. Declared in src/ms2/placeholder/gfxservice.h.
// MS2-UNIT: ?\gfxservice.cpp
// MS2-RANGE: 0x1422e9a40-0x1422eab90 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// COMDAT tail (0x1422ea2f0-): SingletonClass<GFxService>'s ctor/dtor, SingletonClass<UniqueSwfIDCreator>'s dtor, the
// implicit ~UniqueSwfIDCreator, the ??_G of GFxAtlasCache / GFxService / UniqueSwfIDCreator, the SingletonClass<T>
// CreateInstance / DestroyInstance of the five UI singletons, GFxAtlasCache's GetInstance and the EE_DECLARE_CLASS1 /
// EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT members.
// MS2-PIN: ??_GGFxService@@UEAAPEAXI@Z 0x1422ea450
#include "ms2/placeholder/ms2stdafx.h"

#include <efd/IConfigManager.h>
#include <efd/IServiceDetailRegister.h>
#include <efd/MessageService.h>
#include <ecr/RenderService.h>
#include <ecr/RenderSurface.h>
#include <NiRenderTargetGroup.h>
#include <NiDX9Renderer.h>

#include "ms2/placeholder/gfxservice.h"
#include "ms2/placeholder/gfxsysalloc.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/uniqueswfidcreator.h"
#include "ms2/gfxui/uialignwidget.h"
#include "ms2/gfxui/gfxatlascache.h"
#include "ms2/commonfiles/logstring.h"
#include "hook/ms2hook.h"

void FUN_1411ab770(efd::IDependencyRegistrar* pRegistrar, int nFlags);   // AddDependency<ecr::RenderService> (0x07002001)
void FUN_1410db4c0(efd::IDependencyRegistrar* pRegistrar, int nFlags);   // AddDependency<0x07000003>
void* FUN_14127bf80(void* pFramework);                          // its render service (null if none)
ecr::RenderSurface* FUN_140af7da0(ecr::RenderService* pService);  // the service's default surface
int FUN_14151e740();                                            // GFx allocator bytes in use
void FUN_1422d9020(int n);
CLogString* FUN_140166440();

extern char DAT_143b059e8;                                      // the entity app framework
extern const efd::Category DAT_143b0d778;                       // the category GFxService subscribes to
extern void (*DAT_143b0d368)();                                 // called on shutdown when set

// The unit's log call (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0; same COMDAT as optimizer.cpp's).
template <class T> inline void Unk_OptLog(CLogString* log, int level, int category, const wchar_t* format, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}

// ms_ClassInfo's initializer lives in unit_14013acc0.cpp's .text$di range; this reference emits the SetupClassInfo
// inline here, where the exe has it (0x1422eaa90).
static efd::ClassInfo::CLASSINFO_FUNC s_pfnSetupClassInfo = &GFxService::SetupClassInfo;

// @0x1422e9a40
GFxService::GFxService()
    : m_pSysAlloc(NULL)
{
    m_pSysAlloc = new GFxSysAlloc;
    Scaleform::GFx::System::Init(m_pSysAlloc);
    GFxManager::CreateInstance();
    UniqueSwfIDCreator::CreateInstance();
    UIAlignWidgetManager::CreateInstance();
    UISwfEntityManager::CreateInstance();
    GFxAtlasCache::CreateInstance();
    UIAlignWidgetManager::GetInstance()->FUN_1422e6960();
}

// @0x1422e9b40
GFxService::~GFxService()
{
    GFxAtlasCache::DestroyInstance();
    UISwfEntityManager::DestroyInstance();
    UIAlignWidgetManager::DestroyInstance();
    UniqueSwfIDCreator::DestroyInstance();
    GFxManager::DestroyInstance();
    Scaleform::GFx::System::Destroy();
    if (m_pSysAlloc)
    {
        delete m_pSysAlloc;
        m_pSysAlloc = NULL;
    }
}

// @0x1422e9c20
const char* GFxService::GetDisplayName() const
{
    return "GFxService";
}
MS2_REPLACE_METHOD(0x1422E9C20, GFxService, GetDisplayName, 13, 0xA7E85B1C);

// @0x1422e9c40
void GFxService::vfunc_16()
{
    if (GFxManager::GetInstance())
        GFxManager::GetInstance()->FUN_1422ae590();
    if (UISwfEntityManager::GetInstance())
        UISwfEntityManager::GetInstance()->vfunc_4();
}
MS2_REPLACE_METHOD(0x1422E9C40, GFxService, vfunc_16, 73, 0x437B21B6);

// @0x1422e9c90
bool GFxService::vfunc_17()
{
    void* pService = FUN_14127bf80(&DAT_143b059e8);
    if (pService != 0)
    {
        NiRenderTargetGroup* pTarget = FUN_140af7da0((ecr::RenderService*)pService)->GetRenderTargetGroup();
        if (pTarget != 0)
            GFxManager::GetInstance()->FUN_1422adb80(pTarget->GetWidth(0), pTarget->GetHeight(0));
    }
    if (GFxManager::GetInstance())
    {
        if (!GFxManager::GetInstance()->FUN_1422ae690())
            return false;
    }
    if (UISwfEntityManager::GetInstance())
    {
        if (!UISwfEntityManager::GetInstance()->vfunc_5())
            return false;
    }
    s_nCaptureBlock = 0;
    return true;
}
MS2_REPLACE_METHOD(0x1422E9C90, GFxService, vfunc_17, 250, 0xCD8D17D3);

// @0x1422e9d90
int GFxService::vfunc_18(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (GFxManager::GetInstance())
        return GFxManager::GetInstance()->FUN_1422b0a70(hWnd, uMsg, wParam, lParam);
    return 0;
}
MS2_REPLACE_METHOD(0x1422E9D90, GFxService, vfunc_18, 81, 0xFDD3A342);

// @0x1422e9df0
int GFxService::vfunc_19(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (GFxManager::GetInstance())
        return GFxManager::GetInstance()->FUN_1422b0bc0(hWnd, uMsg, wParam, lParam);
    return 0;
}
MS2_REPLACE_METHOD(0x1422E9DF0, GFxService, vfunc_19, 81, 0x819939CB);

// @0x1422e9e50
int GFxService::FUN_1422e9e50()
{
    if (m_pSysAlloc)
        return FUN_14151e740();
    return 0;
}
MS2_REPLACE_METHOD(0x1422E9E50, GFxService, FUN_1422e9e50, 35, 0x1F721578);

// @0x1422e9e80
efd::SyncResult GFxService::OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar)
{
    FUN_1411ab770(pDependencyRegistrar, 1);
    pDependencyRegistrar->AddDependency<efd::IConfigManager>(1);
    FUN_1410db4c0(pDependencyRegistrar, 1);
    return efd::SyncResult_Success;
}
MS2_REPLACE_METHOD_VIA(0x1422E9E80, GFxService, efd::ISystemService, OnPreInit, 69, 0xDDBBB9D3);

// @0x1422e9ed0
efd::AsyncResult GFxService::OnInit()
{
    efd::MessageService* pMessageService = m_pServiceManager->GetSystemServiceAs<efd::MessageService>();
    if (pMessageService)
    {
        pMessageService->Unsubscribe(this, DAT_143b0d778);
        pMessageService->Subscribe(this, DAT_143b0d778);
    }
    ecr::RenderService* pRenderService = m_pServiceManager->GetSystemServiceAs<ecr::RenderService>();
    if (pRenderService)
    {
        HWND hWnd = FUN_140af7da0(pRenderService)->GetWindowRef();
        if (!GFxManager::GetInstance()->FUN_1422ad620(hWnd, NiRenderer::GetRenderer()))
        {
            MessageBoxA(NULL, "Scaleform Initialize Failed", "Scaleform Initialize Failed", MB_OK);
            return efd::AsyncResult_Failure;
        }
    }
    NiDX9Renderer* pRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pRenderer)
    {
        pRenderer->AddResetNotificationFunc(FUN_1422ea110, this);
        pRenderer->AddLostDeviceNotificationFunc(FUN_1422ea1f0, this);
    }
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD_VIA(0x1422E9ED0, GFxService, efd::ISystemService, OnInit, 315, 0x44CF2CE6);

// @0x1422ea020
efd::AsyncResult GFxService::OnTick()
{
    if (GFxManager::GetInstance())
        GFxManager::GetInstance()->FUN_1422ae180();
    if (UISwfEntityManager::GetInstance())
    {
        UISwfEntityManager::GetInstance()->FUN_1422d1c20();
        UISwfEntityManager::GetInstance()->FUN_1422d2020();
    }
    return efd::AsyncResult_Pending;
}
MS2_REPLACE_METHOD_VIA(0x1422EA020, GFxService, efd::ISystemService, OnTick, 78, 0xBE4AA9B0);

// @0x1422ea080
efd::AsyncResult GFxService::OnShutdown()
{
    NiDX9Renderer* pRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pRenderer)
    {
        pRenderer->RemoveResetNotificationFunc(FUN_1422ea110);
        pRenderer->RemoveLostDeviceNotificationFunc(FUN_1422ea1f0);
    }
    if (DAT_143b0d368)
        DAT_143b0d368();
    UISwfEntityManager::GetInstance()->FUN_1422d1ba0();
    GFxManager::GetInstance()->FUN_1422ae360();
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD_VIA(0x1422EA080, GFxService, efd::ISystemService, OnShutdown, 128, 0x280C3BCA);

// @0x1422ea110
bool GFxService::FUN_1422ea110(bool bBeforeReset, void* pvData)
{
    GFxService* pService = (GFxService*)pvData;
    if (pService)
    {
        if (bBeforeReset)
        {
            if (FUN_140166440() != 0)
            {
                DWORD dwTick = GetTickCount();
                Unk_OptLog(FUN_140166440(), 0xc, 0x1a, L"GFxService::OnLostRenderDevice[{0}]", dwTick);
            }
            pService->vfunc_16();
        }
        else
        {
            if (FUN_140166440() != 0)
            {
                DWORD dwTick = GetTickCount();
                Unk_OptLog(FUN_140166440(), 0xc, 0x1a, L"GFxService::OnRestoreRenderDevice[{0}]", dwTick);
            }
            return pService->vfunc_17();
        }
    }
    return true;
}
MS2_REPLACE(0x1422EA110, GFxService::FUN_1422ea110, 215, 0xE00B53F1);

// @0x1422ea1f0
bool GFxService::FUN_1422ea1f0(void* pvData)
{
    s_nCaptureBlock = 1;
    return true;
}
MS2_REPLACE(0x1422EA1F0, GFxService::FUN_1422ea1f0, 18, 0xC9D17E2C);

// @0x1422ea210
void GFxService::FUN_1422ea210(int nCaptureBlock)
{
    s_nCaptureBlock = nCaptureBlock;
}
MS2_REPLACE(0x1422EA210, GFxService::FUN_1422ea210, 15, 0x2808E696);

// @0x1422ea230
void GFxService::FUN_1422ea230(CString strFont)
{
    m_strFont = strFont;
}
MS2_REPLACE_METHOD(0x1422EA230, GFxService, FUN_1422ea230, 63, 0xB0476F43);

// @0x1422ea280
void GFxService::FUN_1422ea280(bool b)
{
    FUN_1422d9020(0);
}
MS2_REPLACE_METHOD(0x1422EA280, GFxService, FUN_1422ea280, 25, 0x285AC38D);

// @0x1422ea2a0
bool GFxService::FUN_1422ea2a0()
{
    return m_strFont.CompareNoCase("CN") == 0;
}
MS2_REPLACE_METHOD(0x1422EA2A0, GFxService, FUN_1422ea2a0, 66, 0x937B78E3);
