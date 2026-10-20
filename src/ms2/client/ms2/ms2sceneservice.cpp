// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2SceneService: egfPhysX::SceneService plus Simulate timing
// statistics and the two cached scenes (default and item) that the world service callbacks pause and resume.
// MS2-UNIT: client\ms2\ms2sceneservice.cpp
// MS2-RANGE: 0x1400f94b0-0x1400f94e0 .text$di
// MS2-RANGE: 0x1415033a0-0x141507ff0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$SmartPointer@VSceneMessage@egfPhysX@@@efd@@QEBAPEAVSceneMessage@egfPhysX@@XZ 0x1415066c0 ; order
// MS2-PIN: ?GetClassDesc@SceneMessage@egfPhysX@@UEBAPEBVClassInfo@efd@@XZ 0x141506d10 ; unique
// MS2-PIN: ?GetClassID@?$MessageWrapper@VSceneMessage@egfPhysX@@$0CACE@@efd@@UEBAIXZ 0x141506d30 ; unique
// MS2-PIN: ?TypeCast@SceneMessage@egfPhysX@@UEBA_NIPEAPEAX@Z 0x141506ea0 ; unique
// MS2-PIN: ?TypeCast@SceneMessage@egfPhysX@@UEBA_NIPEAPEBX@Z 0x141506ef0 ; unique
// MS2-PIN: ?TypeCast@SceneService@egfPhysX@@UEBA_NIPEAPEAX@Z 0x141506f40 ; order
// MS2-PIN: ?TypeCast@SceneService@egfPhysX@@UEBA_NIPEAPEBX@Z 0x141506f90 ; order
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@U?$_List_node@PEAVPhysXSceneData@egfPhysX@@PEAX@std@@@efd@@V?$_List_val@U?$_List_simple_types@PEAVPhysXSceneData@egfPhysX@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@U?$_List_node@PEAVPhysXSceneData@egfPhysX@@PEAX@std@@@efd@@XZ 0x141507290 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_List_node@PEAVPhysXSceneData@egfPhysX@@PEAX@std@@@efd@@V?$_List_val@U?$_List_simple_types@PEAVPhysXSceneData@egfPhysX@@@std@@@std@@$00@std@@QEBAAEBV?$_List_val@U?$_List_simple_types@PEAVPhysXSceneData@egfPhysX@@@std@@@2@XZ 0x1415072f0 ; unique
// MS2-PIN: ??_7MS2SceneService@@6BSceneService@egfPhysX@@@ 0x142f26d80 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2sceneservice.cpp"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2sceneservice.h"
#include "entityworldmanager.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include <egfPhysX/PhysXSceneData.h>
#include <egfPhysX/SceneMessage.h>
#include <efd/ILogger.h>
#include <efd/MessageService.h>

class WorldService;
WorldService* FUN_1403ed2d0();
void FUN_141bbae40(WorldService*, IWorldServiceCallback*);
EntityWorldManager* FUN_1409670f0();
efd::utf8string FUN_1414d7990(const efd::utf8string& kName);
// The scene-name decorator cell set by MS2PropService::OnPreInit.
extern efd::utf8string (*DAT_143b05980)(const efd::utf8string&);
// @0x141506d00
inline efd::utf8string (*GetSceneNameDecorator())(const efd::utf8string&) { return DAT_143b05980; }

// @0x141506c50
inline efd::TimeType ClockNow(efd::HighPrecisionClock* pClock) { return pClock->efd::HighPrecisionClock::GetCurrentTime(); }

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1415033a0
MS2SceneService::MS2SceneService()
    : egfPhysX::SceneService(true)
    , m_clock(0)
    , m_simulateTotal(0.0f)
    , m_simulateCount(0)
{
    for (int i = 0; i < 2; ++i)
        m_pScenes[i] = 0;
}
#endif

// @0x141503470
MS2SceneService::~MS2SceneService()
{
}

// @0x1415034c0
efd::AsyncResult MS2SceneService::OnInit()
{
    (&m_clock)->Update(0);
    FUN_141bbae40(FUN_1403ed2d0(), this);
    return egfPhysX::SceneService::OnInit();
}
MS2_REPLACE_METHOD(0x1415034C0, MS2SceneService, OnInit, 112, 0xBCB98835);

// @0x141503540
void MS2SceneService::Simulate(const efd::Bool forceSim)
{
    efd::TimeType tStart = ClockNow(&m_clock);
    egfPhysX::SceneService::Simulate(forceSim);
    m_simulateTotal += ClockNow(&m_clock) - tStart;
    m_simulateCount = m_simulateCount + 1;
}
MS2_REPLACE_METHOD(0x141503540, MS2SceneService, Simulate, 143, 0x7215FA59);

// @0x1415035e0
efd::AsyncResult MS2SceneService::OnShutdown()
{
    return egfPhysX::SceneService::OnShutdown();
}
MS2_REPLACE_METHOD(0x1415035E0, MS2SceneService, OnShutdown, 24, 0xAC54B4C8);

// @0x141503600
efd::Bool MS2SceneService::AddScene(const efd::utf8string& sceneName, egfPhysX::PhysXSceneData* pSceneData)
{
    if (!pSceneData->GetPhysXScene())
    {
        EE_LOG_AT(efd::kPhysicsSystem, efd::ILogger::kERR2, ("PhysXSceneService::AddScene Scene %s has no NxScene", sceneName.c_str()), MS2_THIS_FILE, 0x2c);
        return false;
    }

    egfPhysX::PhysXSceneData* pExistingSceneData = GetSceneData(sceneName);
    if (pExistingSceneData)
    {
        EE_LOG_AT(efd::kPhysicsSystem, efd::ILogger::kERR2, ("PhysXSceneService::AddScene Scene %s has already been added. Removing the existing scene with that name.", sceneName.c_str()), MS2_THIS_FILE, 0x38);
        RemoveScene(sceneName);
    }

    m_scenes[sceneName] = pSceneData;

    egfPhysX::SceneMessagePtr pAddMsg = EE_NEW egfPhysX::SceneAddedMessage();
    pAddMsg->SetSceneName(sceneName);
    pAddMsg->SetScene(pSceneData->GetPhysXScene());
    m_spMessageService->SendImmediate(pAddMsg, egfPhysX::kCAT_egfPhysXMessage);

    if (sceneName.find("PhysXDefaultSceneName") != efd::utf8string::npos)
    {
        m_pScenes[0] = pSceneData;
    }
    else if (sceneName.find("PhysXItemSceneName") != efd::utf8string::npos)
    {
        m_pScenes[1] = pSceneData;
    }
    return true;
}
MS2_REPLACE_METHOD(0x141503600, MS2SceneService, AddScene, 1125, 0x223AE094);

// @0x141503a70
efd::Bool MS2SceneService::RemoveScene(const efd::utf8string& sceneName)
{
    egfPhysX::PhysXSceneData* pExistingScene = GetSceneData(sceneName);
    if (!pExistingScene)
        return false;

    FetchResults(true);
    SendRemoveMessages(sceneName, pExistingScene, true);

    m_sceneUpdates.remove(pExistingScene);

    efd::utf8string key("PhysXDefaultSceneName");
    efd::utf8string (*pfnDecorate)(const efd::utf8string&) = GetSceneNameDecorator();
    if (pfnDecorate)
    {
        efd::utf8string kBase("PhysXDefaultSceneName");
        key = pfnDecorate(kBase);
    }
    if (key == sceneName)
    {
        m_pScenes[0] = 0;
    }
    else
    {
        key = "PhysXItemSceneName";
        if (pfnDecorate)
        {
            efd::utf8string kBase("PhysXItemSceneName");
            key = pfnDecorate(kBase);
        }
        if (key == sceneName)
            m_pScenes[1] = 0;
    }
    return true;
}
MS2_REPLACE_METHOD(0x141503A70, MS2SceneService, RemoveScene, 582, 0xCB7E85F8);

// @0x141503cc0
NxScene* MS2SceneService::GetCachedNxScene(int index) const
{
    if (m_pScenes[index] == 0)
        return 0;
    return m_pScenes[index]->GetPhysXScene();
}
MS2_REPLACE_METHOD(0x141503CC0, MS2SceneService, GetCachedNxScene, 66, 0x9A1AAE67);

// @0x141503d10
void MS2SceneService::PauseSessionScenes(unsigned session)
{
    efd::utf8string key(efd::Formatted, "%08d_%s", session, "PhysXDefaultSceneName");
    SceneMap::iterator it = m_scenes.find(key);
    if (it != m_scenes.end())
    {
        it->second->SetSimActive(false);
        it->second->StopSimulating();
    }
    key = efd::utf8string(efd::Formatted, "%08d_%s", session, "PhysXItemSceneName");
    it = m_scenes.find(key);
    if (it != m_scenes.end())
    {
        it->second->SetSimActive(false);
        it->second->StopSimulating();
    }
}
MS2_REPLACE_METHOD(0x141503D10, MS2SceneService, PauseSessionScenes, 474, 0x2729B68C);

// @0x141503ef0
void MS2SceneService::CacheNamedScenes()
{
    efd::utf8string name("PhysXDefaultSceneName");
    name = FUN_1414d7990(name);
    if (m_scenes.find(name) != m_scenes.end())
        m_pScenes[0] = m_scenes[name];
    name = "PhysXItemSceneName";
    name = FUN_1414d7990(name);
    if (m_scenes.find(name) != m_scenes.end())
        m_pScenes[1] = m_scenes[name];
}
MS2_REPLACE_METHOD(0x141503EF0, MS2SceneService, CacheNamedScenes, 498, 0xFD8E8776);

// @0x1415040f0
float MS2SceneService::TakeAverageSimulateTime()
{
    if (m_simulateCount != 0)
    {
        float fAverage = m_simulateTotal / (float)m_simulateCount;
        m_simulateTotal = 0.0f;
        m_simulateCount = 0;
        return fAverage;
    }
    return 0.0f;
}
MS2_REPLACE_METHOD(0x1415040F0, MS2SceneService, TakeAverageSimulateTime, 126, 0x282B5EDA);

// @0x141504180
void MS2SceneService::ResetSimulateStats()
{
    m_simulateTotal = 0.0f;
    m_simulateCount = 0;
}
MS2_REPLACE_METHOD(0x141504180, MS2SceneService, ResetSimulateStats, 38, 0xA515A3AD);

// @0x1415041b0
void MS2SceneService::vfunc_3(int)
{
    if (m_pScenes[0] != 0)
    {
        m_pScenes[0]->SetSimActive(false);
        m_pScenes[0]->StopSimulating();
    }
    if (m_pScenes[1] != 0)
    {
        m_pScenes[1]->SetSimActive(false);
        m_pScenes[1]->StopSimulating();
    }
}
MS2_REPLACE_METHOD_VIA(0x1415041B0, MS2SceneService, IWorldServiceCallback, vfunc_3, 202, 0xB6F65B10);

// @0x141504280
void MS2SceneService::vfunc_1(int)
{
    if (m_pScenes[0] != 0)
    {
        m_pScenes[0]->SetSimActive(true);
        m_pScenes[0]->StartSimulating(0);
    }
    if (m_pScenes[1] != 0)
    {
        m_pScenes[1]->SetSimActive(true);
        m_pScenes[1]->StartSimulating(0);
    }
}
MS2_REPLACE_METHOD_VIA(0x141504280, MS2SceneService, IWorldServiceCallback, vfunc_1, 230, 0x945C7F3A);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb3210-0x142cb3230 .text$yd
