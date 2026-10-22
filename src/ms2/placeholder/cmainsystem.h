// cmainsystem.h - PLACEHOLDER for CMainSystem (RTTI .?AVCMainSystem@@, 0xd0 bytes). NOT an original header.
// Bases: TSingleton<CMainSystem> at +0x0, efd::ISystemService at +0x8. The game's main efd system service (class id
// 0x06100006, display name "MainSystem"): MS2::RegisterServices creates it first, hands it the main thread id and the
// config manager (it reads the data path into +0xa8). It creates the game's manager singletons once a render surface
// exists, owns the main click render step, counts frames per second and keeps the server tick / server time bases.
// Owning unit ?\mainsystem.cpp; member names invented from their use.
#pragma once

#include <time.h>
#include <efd/ISystemService.h>
#include <efd/IConfigManager.h>
#include <efd/ReferenceCounting.h>
#include <efd/SmartPointer.h>
#include <efd/Category.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

namespace efd { class MessageService; }
namespace egf { class Scheduler; class EntityManager; class Entity; class EntityID; }
namespace ecr { class LightService; class RenderService; }
class NiDefaultClickRenderStep;
class GameObject;

class CMainSystem : public TSingleton<CMainSystem>, public efd::ISystemService
{
    EE_DECLARE_CLASS1(CMainSystem, 0x06100006, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CMainSystem();                                                  // 0x141472be0
    virtual ~CMainSystem();                                         // 0x141472dd0
    virtual const char* GetDisplayName() const;                     // 0x141472e90
    void FUN_141472eb0(efd::IConfigManagerPtr spConfig);            // reads [Data] Path into m_strDataPath
    void ResetFps();                                                // 0x141472fe0
    void FUN_141473020(bool bActive);                               // surface render step on, own click step off (or back)
    void SetTimeScale(float fScale);                                // 0x1414730a0 the game clock's time scale
    float GetTimeScale();                                           // 0x1414730f0
    void IncreaseTimeScale();                                       // 0x141473110 +0.1 up to 1.0
    void DecreaseTimeScale();                                       // 0x141473170 -0.1 down to 0
    void ResetTimeScale();                                          // 0x1414731d0
    float GetFps();                                                 // 0x141473210
    float GetLastGameTimeDelta();                                   // 0x141473230
    double GetDeltaTime();                                          // 0x141473260
    double FUN_141473280();                                         // the game clock's current time
    DWORD FUN_1414732b0(GameObject* pObject);                       // FUN_1414732f0 of the object's time kind
    DWORD FUN_1414732f0(int nKind);                                 // game time, server tick (kind 6) or a converted time
    int FUN_141473390();                                            // the server tick (re-based when the tick count wraps)
    int FUN_141473410(DWORD dwTick);                                // the server tick at a local tick
    int FUN_141473460();                                            // +0x74
    int FUN_141473480();                                            // +0x78
    int FUN_1414734a0();                                            // +0x7c
    void FUN_1414734c0(int nServerTick, int n78, int n7c, int n74); // sets the server tick base
    void FUN_141473530(__time64_t t);                               // +0xa0
    __int64 FUN_141473560();                                        // seconds until +0xa0 (0 after its day ended)
    void StartTimer();                                              // 0x1414735e0
    int GetElapsedTime();                                           // 0x141473610 ms since StartTimer
    __time64_t FUN_141473640();                                     // the server time now
    void FUN_141473690(__time64_t tServer);                         // sets the server time base
    CString GetDataPath();                                        // m_strDataPath (+0xa8)
    void FUN_141473730(bool bDisable);                              // sticky-keys hotkey off (saves the flags) / restore
    static void FUN_1414737d0(egf::Entity* pEntity);                // drops the entity's scene-graph override and destroys it
    static void FUN_141473870(egf::EntityID id);                    // same for an entity id
    static int FUN_1414738f0(int nIndex);                           // s_143add400[nIndex] (8 entries)
    void SetMainThreadId(DWORD dwThreadId);                           // +0xb0
    bool FUN_141473940();                                           // called on the main thread
    CStringW FUN_141473990();                                       // "<cpu vendor> / <cpu brand>"
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar);    // 0x141473c20
    virtual efd::AsyncResult OnInit();                              // 0x141473ca0
    virtual efd::AsyncResult OnTick();                              // 0x141474080
    virtual efd::AsyncResult OnShutdown();                          // 0x1414741e0
    void FUN_141474450();                                           // applies the graphics option's frame limit
    void FUN_141474490();                                           // builds the main click render step
private:
    MS2_LAYOUT_FRIEND;
    egf::Scheduler* m_pScheduler;                                   // +0x28
    ecr::LightService* m_pLightService;                             // +0x30
    ecr::RenderService* m_pRenderService;                           // +0x38
    NiDefaultClickRenderStep* m_pClickRenderStep;                   // +0x40
    DWORD m_dwStickyKeysFlags;                                      // +0x48
    float m_fTimeScale;                                             // +0x4c
    double m_dFpsTime;                                              // +0x50
    double m_dLastTime;                                             // +0x58
    double m_dDeltaTime;                                            // +0x60
    unsigned int m_uiFrames;                                        // +0x68
    float m_fFps;                                                   // +0x6c
    int m_iServerTickBase;                                          // +0x70
    int m_i74;                                                      // +0x74
    int m_i78;                                                      // +0x78
    int m_i7c;                                                      // +0x7c
    DWORD m_dwLocalTickBase;                                        // +0x80
    int m_iServerTick;                                              // +0x84
    int m_i88;                                                      // +0x88
    DWORD m_dwStartTick;                                            // +0x8c
    __time64_t m_tServerTimeBase;                                   // +0x90
    __time64_t m_tLocalTimeBase;                                    // +0x98
    __time64_t m_tA0;                                               // +0xa0
    CString m_strDataPath;                                          // +0xa8
    DWORD m_dwMainThreadId;                                         // +0xb0
    efd::SmartPointer<egf::EntityManager> m_spEntityManager;        // +0xb8
    efd::SmartPointer<efd::MessageService> m_spMessageService;      // +0xc0
    efd::Category m_kCategory;                                      // +0xc8 globally unique, subscribed in OnInit
};
MS2_CHECK_SIZE(CMainSystem, 0xd0);
MS2_CHECK_OFFSET(CMainSystem, m_pScheduler, 0x28);
MS2_CHECK_OFFSET(CMainSystem, m_strDataPath, 0xa8);
MS2_CHECK_OFFSET(CMainSystem, m_kCategory, 0xc8);
