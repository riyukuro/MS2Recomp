// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMainSystem: the game's main efd system service (frame
// counter, game clock scale, server tick / time bases, the manager singletons and the main click render step).
// MS2-UNIT: ?\mainsystem.cpp
// MS2-RANGE: 0x1400f7980-0x1400f7b70 .text$di
// MS2-RANGE: 0x141472ba0-0x1414762e0 .text$mn
// MS2-PIN: ??_7CMainSystem@@6B?$TSingleton@VCMainSystem@@@@@ 0x142f17ae8
// MS2-PIN: ??_7CMainSystem@@6BISystemService@efd@@@ 0x142f17af8
// MS2-PIN: ??1NiClickRenderStep@@UEAA@XZ 0x141474db0
// MS2-PIN: ??0NiRenderClick@@QEAA@XZ 0x141474960
// MS2-PIN: ??1NiDefaultClickRenderStep@@UEAA@XZ 0x141474dd0
// MS2-PIN: ??1NiRenderStep@@UEAA@XZ 0x141474e50
// MS2-FUNCTIONAL 0x141474960: NiRenderClick() calls NiColorA(float x4); the exe NiColorA ctor is the efd::ColorA forwarder 0x14097f1d0, our Gamebryo NiColorA has no ColorA base so its body (direct stores) binds efd::ColorA 0x14097f050 (afterimageitem.cpp) - same effect
// MS2-PIN: ??4?$SmartPointer@VEntityManager@egf@@@efd@@QEAAAEAV01@PEAVEntityManager@egf@@@Z 0x141474ed0
// MS2-PIN: ??4?$SmartPointer@VNiRenderClick@@@efd@@QEAAAEAV01@PEAVNiRenderClick@@@Z 0x141474fc0
// MS2-PIN: ??4?$SmartPointer@VNiRenderView@@@efd@@QEAAAEAV01@PEAVNiRenderView@@@Z 0x1414750a0
// MS2-PIN: ?AddHead@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderStep@@@efd@@@@QEAAXAEBV?$SmartPointer@VNiRenderStep@@@efd@@@Z 0x141475540
// MS2-PIN: ?AddNodeHead@?$NiTListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderStep@@@efd@@@@IEAAXPEAV?$NiTListItem@V?$SmartPointer@VNiRenderStep@@@efd@@@@@Z 0x141475590
// MS2-PIN: ?DeleteItem@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderClick@@@efd@@@@MEAAXPEAV?$NiTListItem@V?$SmartPointer@VNiRenderClick@@@efd@@@@@Z 0x141475a70
// MS2-PIN: ?DeleteItem@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderView@@@efd@@@@MEAAXPEAV?$NiTListItem@V?$SmartPointer@VNiRenderView@@@efd@@@@@Z 0x141475ab0
// MS2-PIN: ?PrependRenderStep@NiRenderFrame@@QEAAXPEAVNiRenderStep@@@Z 0x141475e10
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\mainsystem.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cmainsystem.h"
#include <intrin.h>
#include <efd/ServiceManager.h>
#include <efd/MessageService.h>
#include <efd/IConfigSection.h>
#include <ecrInput/InputService.h>
#include <egf/Scheduler.h>
#include <egf/EntityManager.h>
#include <egf/GameTimeClock.h>
#include <egf/egfClassIDs.h>
#include <ecr/RenderService.h>
#include <ecr/RenderSurface.h>
#include <ecr/LightService.h>
#include <NiRenderFrame.h>
#include <NiDefaultClickRenderStep.h>
#include <NiViewRenderClick.h>
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/ms2scenegraphservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The manager singletons CMainSystem creates (only the extents are modelled).
class CEmotionManager : public TSingleton<CEmotionManager>
{
public:
    CEmotionManager();                                  // 0x1411bf010
    virtual ~CEmotionManager();
private:
    char m_pad[0x2c0 - 0x8];
};
class CGroundEffectDataManager : public TSingleton<CGroundEffectDataManager>
{
public:
    CGroundEffectDataManager();                         // 0x141376f00
    virtual ~CGroundEffectDataManager();
private:
    char m_pad[0x38 - 0x8];
};
class CInputKeyHandler : public TSingleton<CInputKeyHandler>
{
public:
    CInputKeyHandler();                                 // 0x14116d540
    virtual ~CInputKeyHandler();
private:
    char m_pad[0x10 - 0x8];
};
class CInstrumentManager : public TSingleton<CInstrumentManager>
{
public:
    CInstrumentManager();                               // 0x140d05be0
    virtual ~CInstrumentManager();
private:
    char m_pad[0x6c0 - 0x8];
};
class CPhysXHelper : public TSingleton<CPhysXHelper>
{
public:
    CPhysXHelper();                                     // 0x141689180
    virtual ~CPhysXHelper();
private:
    char m_pad[0x28 - 0x8];
};
class CSkillCollisionManager : public TSingleton<CSkillCollisionManager>
{
public:
    CSkillCollisionManager();                           // 0x141754490
    virtual ~CSkillCollisionManager();
private:
    char m_pad[0x80 - 0x8];
};

// Unrecovered helpers.
class Unk_140d86260 { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
                      virtual void vfunc_4(); virtual void vfunc_5(); };
Unk_140d86260* FUN_140d86260();
void* FUN_1404f4540();
void FUN_140791ac0(void* p);
class Unk_1409a8b10;
Unk_1409a8b10* FUN_1409a8b10();
void* FUN_1409a8ac0(void* p);
class Unk_GraphicsOptions                               // FUN_1409a8ac0's result
{
public:
    int GetFrameLimit() { return m_iFrameLimit; }
private:
    __int64 m_00, m_08, m_10, m_18;
    int m_iFrameLimit;                                  // +0x20
};
void FUN_141610410(int nFrameLimit);
class Unk_MsWorld { public: int FUN_141bd1a10(GameObject* pObject); };
Unk_MsWorld* FUN_1403ed2d0();
int FUN_14028d260(float fTime);
CStringW FUN_14016a730(const char* psz, int nCodePage);
#ifdef __clang__
CString FUN_14038f6d0(const CString& str1, const char* psz2);      // the exe's ATL::operator+ copies (the hook build
CString FUN_1401d2b10(const CString& str1, const CString& str2);   // would import MFC CopyChars)
#endif
ecr::SceneGraphService* FUN_140ad4ba0();
void* FUN_1413f9810();

// @0x1400f7980
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CMainSystem);
// @0x1400f79a0
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400f7a60
static CString s_strSkill = "skill";
// @0x1400f7a90
static CString s_strStun = "stun";
// @0x1400f7ac0
static const efd::Category s_catEntityChannel(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);
// @0x1400f7af0
static const efd::Category s_catAnimationChannel(efd::UniversalID::ECU_Any, 0xfff, 0x07001008);
// @0x1400f7b20
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);

static int s_143add400[8] = {0x032fd758, 0x00263000, 0x00263104, 0x032fdb20, 0x00263110, 0x002631a6, 0x032fd370, 0x002631b0};

// @0x141472bc0
int FUN_141472bc0()
{
    return CMainSystem::GetInstance()->FUN_141473390();
}

// @0x141472be0
CMainSystem::CMainSystem()
    : m_dwStartTick(0), m_tLocalTimeBase(0), m_dwMainThreadId(0)
{
    m_pLightService = 0;
    m_pRenderService = 0;
    m_pClickRenderStep = 0;
    m_pScheduler = 0;
    ResetFps();
    m_dDeltaTime = 0;
    m_i88 = 0;
    m_dwLocalTickBase = GetTickCountMs2();
    m_iServerTick = 0;
    m_iServerTickBase = 0;
    m_i74 = 0;
    m_i78 = 0;
    m_i7c = 0;
    __time64_t t;
    time(&t);
    m_tServerTimeBase = t;
    m_tLocalTimeBase = t;
    m_fTimeScale = 1.0f;
    FUN_141473730(true);
    StartTimer();
}

// @0x141472dd0
CMainSystem::~CMainSystem()
{
    FUN_141473730(false);
}

// @0x141472e90
const char* CMainSystem::GetDisplayName() const
{
    return "MainSystem";
}

// @0x141472eb0
void CMainSystem::FUN_141472eb0(efd::IConfigManagerPtr spConfig)
{
    if (spConfig)
    {
        const efd::ISection* pSection = spConfig->GetConfiguration()->FindSection("Data");
        if (pSection)
            m_strDataPath = pSection->FindValue("Path").c_str();
    }
}

// @0x141472fe0
void CMainSystem::ResetFps()
{
    m_dLastTime = 0;
    m_dFpsTime = 0;
    m_fFps = 0;
    m_uiFrames = 0;
}

// @0x141473020
void CMainSystem::FUN_141473020(bool bActive)
{
    ecr::RenderSurface* pSurface = m_pRenderService->GetActiveRenderSurface();
    NiRenderStep* pStep = pSurface->GetRenderStep();
    pStep->SetActive(bActive);
    m_pClickRenderStep->SetActive(bActive == false);
}

// @0x1414730a0
void CMainSystem::SetTimeScale(float fScale)
{
    egf::GameTimeClock* pClock = (egf::GameTimeClock*)m_pServiceManager->GetClock(efd::kCLASSID_GameTimeClock);
    if (pClock)
        pClock->SetTimeScale(fScale);
}

// @0x1414730f0
float CMainSystem::GetTimeScale()
{
    return m_fTimeScale;
}

// @0x141473110
void CMainSystem::IncreaseTimeScale()
{
    if (m_fTimeScale < 1.0f)
    {
        m_fTimeScale += 0.1f;
        SetTimeScale(m_fTimeScale);
    }
}

// @0x141473170
void CMainSystem::DecreaseTimeScale()
{
    if (m_fTimeScale > 0.0f)
    {
        m_fTimeScale -= 0.1f;
        SetTimeScale(m_fTimeScale);
    }
}

// @0x1414731d0
void CMainSystem::ResetTimeScale()
{
    m_fTimeScale = 1.0f;
    SetTimeScale(m_fTimeScale);
}

// @0x141473210
float CMainSystem::GetFps()
{
    return m_fFps;
}

// @0x141473230
float CMainSystem::GetLastGameTimeDelta()
{
    return (float)m_pScheduler->GetLastGameTimeDelta();
}

// @0x141473260
double CMainSystem::GetDeltaTime()
{
    return m_dDeltaTime;
}

// @0x141473280
double CMainSystem::FUN_141473280()
{
    return m_pServiceManager->GetTime(efd::kCLASSID_GameTimeClock);
}

// @0x1414732b0
DWORD CMainSystem::FUN_1414732b0(GameObject* pObject)
{
    int nKind = FUN_1403ed2d0()->FUN_141bd1a10(pObject);
    return FUN_1414732f0(nKind);
}

// @0x1414732f0
DWORD CMainSystem::FUN_1414732f0(int nKind)
{
    if (nKind == 0)
        return (DWORD)FUN_141473280();
    BOOL bServerTick = FALSE;
    switch (nKind)
    {
    case 1:
    case 3:
    case 5:
        bServerTick = FALSE;
        break;
    case 6:
        bServerTick = TRUE;
        break;
    }
    if (bServerTick)
        return FUN_141473390();
    return FUN_14028d260((float)FUN_141473280());
}

// @0x141473390
int CMainSystem::FUN_141473390()
{
    DWORD dwTick = GetTickCountMs2();
    if (dwTick < m_dwLocalTickBase)
    {
        m_dwLocalTickBase = dwTick;
        return m_iServerTick;
    }
    m_iServerTick = dwTick - m_dwLocalTickBase + m_iServerTickBase;
    return m_iServerTick;
}

// @0x141473410
int CMainSystem::FUN_141473410(DWORD dwTick)
{
    m_iServerTick = dwTick - m_dwLocalTickBase + m_iServerTickBase;
    return m_iServerTick;
}

// @0x141473460
int CMainSystem::FUN_141473460()
{
    return m_i74;
}

// @0x141473480
int CMainSystem::FUN_141473480()
{
    return m_i78;
}

// @0x1414734a0
int CMainSystem::FUN_1414734a0()
{
    return m_i7c;
}

// @0x1414734c0
void CMainSystem::FUN_1414734c0(int nServerTick, int n78, int n7c, int n74)
{
    m_dwLocalTickBase = GetTickCountMs2();
    m_iServerTickBase = nServerTick;
    m_i78 = n78;
    m_i7c = n7c;
    m_i74 = n74;
}

// @0x141473530
void CMainSystem::FUN_141473530(__time64_t t)
{
    m_tA0 = t;
}

// @0x141473560
__int64 CMainSystem::FUN_141473560()
{
    if (m_tA0 == 0)
        return 0;
    __time64_t tNow = FUN_141473640();
    __time64_t tDayEnd = GetNextDayStart(m_tA0);
    if (tDayEnd < tNow)
        return 0;
    return PositiveDifference(m_tA0, tNow);
}

// @0x1414735e0
void CMainSystem::StartTimer()
{
    m_dwStartTick = GetTickCountMs2();
}

// @0x141473610
int CMainSystem::GetElapsedTime()
{
    return GetTickCountMs2() - m_dwStartTick;
}

// @0x141473640
__time64_t CMainSystem::FUN_141473640()
{
    __time64_t t;
    time(&t);
    return t - m_tLocalTimeBase + m_tServerTimeBase;
}

// @0x141473690
void CMainSystem::FUN_141473690(__time64_t tServer)
{
    __time64_t t;
    time(&t);
    m_tServerTimeBase = tServer;
    m_tLocalTimeBase = t;
}

// @0x1414736e0
CString CMainSystem::FUN_1414736e0()
{
    return m_strDataPath;
}

// @0x141473730
void CMainSystem::FUN_141473730(bool bDisable)
{
    if (bDisable)
    {
        STICKYKEYS sk;
        sk.cbSize = sizeof(STICKYKEYS);
        SystemParametersInfoA(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &sk, 0);
        m_dwStickyKeysFlags = sk.dwFlags;
        sk.dwFlags &= ~(SKF_HOTKEYACTIVE | SKF_AVAILABLE);
        SystemParametersInfoA(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), &sk, 0);
    }
    else
    {
        STICKYKEYS sk = {sizeof(STICKYKEYS), m_dwStickyKeysFlags};
        SystemParametersInfoA(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), &sk, 0);
    }
}

// MS2-FUNCTIONAL: FUN_1414f1ef0 takes the id by value in the exe (declared const& by its owning unit)
// @0x1414737d0
void CMainSystem::FUN_1414737d0(egf::Entity* pEntity)
{
    if (pEntity)
    {
        static_cast<MS2SceneGraphService*>(FUN_140ad4ba0())->FUN_1414f1ef0(egf::EntityID(pEntity->GetEntityID()));
        ((egf::Scheduler*)FUN_1413f9810())->DestroyEntity(egf::EntityID(pEntity->GetEntityID()));
    }
}

// MS2-FUNCTIONAL: FUN_1414f1ef0 takes the id by value in the exe (declared const& by its owning unit)
// @0x141473870
void CMainSystem::FUN_141473870(egf::EntityID id)
{
    static_cast<MS2SceneGraphService*>(FUN_140ad4ba0())->FUN_1414f1ef0(egf::EntityID(id));
    ((egf::Scheduler*)FUN_1413f9810())->DestroyEntity(egf::EntityID(id));
}

// @0x1414738f0
int CMainSystem::FUN_1414738f0(int nIndex)
{
    if (nIndex >= 8)
        return 0;
    return s_143add400[nIndex];
}

// @0x141473920
void CMainSystem::FUN_141473920(DWORD dwThreadId)
{
    m_dwMainThreadId = dwThreadId;
}

// @0x141473940
bool CMainSystem::FUN_141473940()
{
    DWORD dwId = GetCurrentThreadId();
    return m_dwMainThreadId == dwId;
}

// The MSDN __cpuid sample, cut down to the vendor and brand strings.
// @0x141473990
CStringW CMainSystem::FUN_141473990()
{
    int CPUInfo[4] = {0};
    char CPUString[0x20] = {0};
    __cpuid(CPUInfo, 0);
    *((int*)CPUString) = CPUInfo[1];
    *((int*)(CPUString + 4)) = CPUInfo[3];
    *((int*)(CPUString + 8)) = CPUInfo[2];
    CString strVendor(CPUString);

    char CPUBrandString[0x40];
    __cpuid(CPUInfo, 0x80000000);
    int nExIds = CPUInfo[0];
    memset(CPUBrandString, 0, sizeof(CPUBrandString));
    for (int i = 0x80000000; i < nExIds; ++i)
    {
        __cpuid(CPUInfo, i);
        if (i == 0x80000002)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000003)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000004)
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }
    CString strBrand(CPUBrandString);
#ifdef __clang__
    return FUN_14016a730(FUN_1401d2b10(FUN_14038f6d0(strVendor, " / "), strBrand), 0);
#else
    return FUN_14016a730(strVendor + " / " + strBrand, 0);
#endif
}

// @0x141473c20
efd::SyncResult CMainSystem::OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar)
{
    pDependencyRegistrar->AddDependency<egf::Scheduler>(1);
    pDependencyRegistrar->AddDependency<ecr::LightService>(1);
    pDependencyRegistrar->AddDependency<ecr::RenderService>(1);
    pDependencyRegistrar->AddDependency<efd::MessageService>(1);
    pDependencyRegistrar->AddDependency<ecrInput::InputService>(1);
    pDependencyRegistrar->AddDependency<egf::EntityManager>(1);
    return efd::SyncResult_Success;
}

// @0x141473ca0
efd::AsyncResult CMainSystem::OnInit()
{
    m_pScheduler = m_pServiceManager->GetSystemServiceAs<egf::Scheduler>();
    m_pLightService = m_pServiceManager->GetSystemServiceAs<ecr::LightService>();
    m_pRenderService = m_pServiceManager->GetSystemServiceAs<ecr::RenderService>();
    m_spMessageService = m_pServiceManager->GetSystemServiceAs<efd::MessageService>();
    m_spEntityManager = m_pServiceManager->GetSystemServiceAs<egf::EntityManager>();
    ecr::RenderSurface* pSurface = m_pRenderService->GetActiveRenderSurface();
    if (pSurface == 0)
        return efd::AsyncResult_Pending;

    TSingleton<CPhysXHelper>::CreateInstance();
    TSingleton<CEmotionManager>::CreateInstance();
    TSingleton<CInputKeyHandler>::CreateInstance();
    TSingleton<CSkillCollisionManager>::CreateInstance();
    TSingleton<CGroundEffectDataManager>::CreateInstance();
    TSingleton<CInstrumentManager>::CreateInstance();
    FUN_141474490();

    m_kCategory = m_spMessageService->GetGloballyUniqueCategory();
    m_spMessageService->Subscribe(this, s_catEntityChannel, 0, false);
    m_spMessageService->Subscribe(this, m_kCategory, 0, false);
    m_spMessageService->Subscribe(this, m_spEntityManager->GetEntityLoadCategory(), 0, false);
    m_spMessageService->Subscribe(this, s_catAnimationChannel, 0, false);
    return efd::AsyncResult_Complete;
}

// @0x141474080
efd::AsyncResult CMainSystem::OnTick()
{
    FUN_141474450();
    double dNow = m_pServiceManager->GetServiceManagerTime();
    if (m_dLastTime > 0.0)
    {
        m_dDeltaTime = dNow - m_dLastTime;
        m_dFpsTime += m_dDeltaTime;
        m_uiFrames++;
        if (m_dFpsTime > 1.0)
        {
            m_fFps = (float)(m_uiFrames / m_dFpsTime);
            m_dFpsTime = 0;
            m_uiFrames = 0;
        }
    }
    else
    {
        m_dFpsTime = 0;
        m_uiFrames = 0;
    }
    m_dLastTime = dNow;
    if (FUN_140d86260())
        FUN_140d86260()->vfunc_5();
    if (FUN_1404f4540())
        FUN_140791ac0(FUN_1404f4540());
    return efd::AsyncResult_Pending;
}

// @0x1414741e0
efd::AsyncResult CMainSystem::OnShutdown()
{
    TSingleton<CEmotionManager>::DestroyInstance();
    TSingleton<CInputKeyHandler>::DestroyInstance();
    TSingleton<CSkillCollisionManager>::DestroyInstance();
    TSingleton<CGroundEffectDataManager>::DestroyInstance();
    if (m_spMessageService)
    {
        m_spMessageService->Unsubscribe(this, s_catEntityChannel, false);
        m_spMessageService->Unsubscribe(this, m_kCategory, false);
        m_spMessageService->Unsubscribe(this, m_spEntityManager->GetEntityLoadCategory(), false);
        m_spMessageService->Unsubscribe(this, s_catAnimationChannel, false);
    }
    return efd::AsyncResult_Complete;
}

// @0x141474450
void CMainSystem::FUN_141474450()
{
    int nLimit = static_cast<Unk_GraphicsOptions*>(FUN_1409a8ac0(FUN_1409a8b10()))->GetFrameLimit();
    FUN_141610410(nLimit);
}

// @0x141474490
void CMainSystem::FUN_141474490()
{
    ecr::RenderSurface* pSurface = m_pRenderService->GetActiveRenderSurface();
    NiRenderFrame* pFrame = pSurface->GetRenderFrame();
    m_pClickRenderStep = NiNew NiDefaultClickRenderStep();
    pFrame->PrependRenderStep(m_pClickRenderStep);
    NiViewRenderClick* pClick = NiNew NiViewRenderClick;
    m_pClickRenderStep->AppendRenderClick(pClick);
    pClick->SetClearAllBuffers(true);
    m_pClickRenderStep->SetActive(false);
}

MS2_EMIT_CRT_MEMMOVE_S();
