// ms2.h - the application shell of the client.
// CGameApp (RTTI name; the MFC application object `theApp`) starts the process in InitInstance: the single-instance
// check, the crash handler, every TSingleton manager and data table, the client window and finally the MS2 service.
// MS2 (RTTI name, efd system service, class id 0x06100001, display name "MapleStory2") owns the efd::ServiceManager:
// it brings up PhysX, registers every Gamebryo / game service with its tick priority, sets up logging and runs the
// Win32 message loop that ticks the service manager until the window closes. EngineLog (RTTI name) is the rotating
// "ms2log/MS2Log<n>.txt" engine log file.
// Member and helper names are invented from their use.
// Owning unit: ?\ms2.cpp (.text$mn 0x141489aa0-0x14149fd50, .text$di 0x1400f82a0-0x1400f8710).
#pragma once
#include <afxwin.h>
#include <efd/ISystemService.h>
#include <efd/SmartPointer.h>
#include <efd/utf8string.h>
#include <efd/Color.h>
#include <efd/ServiceManager.h>
#include <efd/FileDestination.h>
#include <efd/DebugOutDestination.h>
#include <NiColor.h>
#include <NiMaterial.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/clockcriticalsection.h"

namespace efdPhysX { class PhysXSDKManager; }
class MS2PhysXAllocator;
class CPhysXError;
class CMS2DefaultSurfaceCreator;

class MS2;
class MS2 : public efd::ISystemService, public TSingleton<MS2>
{
    EE_DECLARE_CLASS1(MS2, 0x06100001, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    MS2();                                                          // 0x141489aa0
    virtual ~MS2();                                                 // 0x141489c40

    // Brings up PhysX and the services, runs the message loop and shuts everything down again.
    bool Run(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);       // 0x141489d10
    void Quit();                                                    // 0x141489f20 leaves the message loop
    void Tick();                                                    // 0x141489f40 one service manager frame
    unsigned int GetLastTickTime();                                 // 0x141489fb0
    MS2PhysXAllocator* GetPhysXAllocator();                         // 0x141489fd0
    void SetBackgroundColor(NiColorA kColor);                       // 0x141489ff0 of the active surface's scene click
    NiColorA GetBackgroundColor();                                  // 0x14148a050
    const char* GetLogFileName();                                   // 0x14148a0f0
    static void SetWorkingDirectory(bool bParent);                  // 0x14148a120 the exe's folder (or its parent)
    void Precache();                                                // 0x14148a260 "urn:Precache" scene graphs / KFMs / models
    void RegisterUIScenes();                                        // 0x14148a530
    void MessageLoop();                                             // 0x14148a820
    void PrepareShaderCache();                                      // 0x14148a9a0 Config/ShaderVer.xml, Data/Shaders/Current
    void SetCrashOnShutdown();                                      // 0x14148b090
    void Shutdown();                                                // 0x14148b0b0
    static bool OnLostDevice(void* pvData);                         // 0x14148b340 renderer lost-device callback
    bool RegisterServices(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow); // 0x14148b370
    efd::Logger* CreateLogger();                                    // 0x14148e860
    void RemoveLogDestinations();                                   // 0x14148ec40

    virtual const char* GetDisplayName() const;                     // 0x14148ed20
    virtual efd::ClassID GetClassID() const;                        // 0x14148ed40
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar);       // 0x14148ed60
    virtual efd::AsyncResult OnInit();                              // 0x14148ee00
    virtual efd::AsyncResult OnTick();                              // 0x14148f180
    virtual efd::AsyncResult OnShutdown();                          // 0x14148f1c0

    efd::SmartPointer<efd::ServiceManager> m_spServiceManager;      // +0x28
    efd::SmartPointer<efd::FileDestination> m_spFileDest;           // +0x30 "MapleStory2_<pid>.log"
    efd::SmartPointer<efd::DebugOutDestination> m_spDebugOutDest;   // +0x38
    efdPhysX::PhysXSDKManager* m_pPhysXManager;                     // +0x40
    MS2PhysXAllocator* m_pPhysXAllocator;                           // +0x48
    CPhysXError* m_pPhysXOutput;                                    // +0x50
    int m_bQuit;                                                    // +0x58
    efd::utf8string m_strLogFile;                                   // +0x60
    efd::SmartPointer<NiMaterial> m_spDirShadowMaterial;            // +0x80 the shadow write materials
    efd::SmartPointer<NiMaterial> m_spPointShadowMaterial;          // +0x88
    efd::SmartPointer<NiMaterial> m_spSpotShadowMaterial;           // +0x90
    CMS2DefaultSurfaceCreator* m_pSurfaceCreator;                   // +0x98
    unsigned int m_uiLastTickTime;                                  // +0xa0
    int m_bCrashOnShutdown;                                         // +0xa4
};
MS2_CHECK_SIZE(MS2, 0xa8);
MS2_CHECK_OFFSET(MS2, m_spServiceManager, 0x28);
MS2_CHECK_OFFSET(MS2, m_strLogFile, 0x60);
MS2_CHECK_OFFSET(MS2, m_pSurfaceCreator, 0x98);
MS2_CHECK_OFFSET(MS2, m_bCrashOnShutdown, 0xa4);

// The start-up step profiler of CGameApp ("Loading"): logs the time between named steps. Owning unit unit_1402e1070 /
// unit_1402e12c0 (not recovered); only the members CGameApp calls are declared.
// The lock is a member, not a base: the exe's ctor/dtor store no vftable of their own.
class Unk_StepProfiler
{
public:
    explicit Unk_StepProfiler(CString strName);                     // 0x1402e11c0 (by value: the ctor destroys it)
    ~Unk_StepProfiler();                                            // 0x1402e1260
    // FUN_1402e12c0 (starts the next step, logs the previous one) is Unk_PerfLog's (unit_1402e12c0)

    CLockCriticalSection m_lock;                                    // +0x00
    CString m_strName;                                              // +0x30
    CString m_strStep;                                              // +0x38
    unsigned int m_uiStepStart;                                     // +0x40
    unsigned int m_uiStart;                                         // +0x44
    int m_nStep;                                                    // +0x48
    void* m_pListener;                                              // +0x50
};
MS2_CHECK_SIZE(Unk_StepProfiler, 0x58);

class CGameApp : public CWinApp
{
public:
    CGameApp();                                                     // 0x14148f2d0
    virtual BOOL InitInstance();                                    // 0x14148f360
    virtual int ExitInstance();                                     // 0x141491d00

    int m_nExitCode;                                                // +0x178
    Unk_StepProfiler m_profiler;                                    // +0x180
};
MS2_CHECK_SIZE(CGameApp, 0x1d8);
MS2_CHECK_OFFSET(CGameApp, m_nExitCode, 0x178);
MS2_CHECK_OFFSET(CGameApp, m_profiler, 0x180);

extern CGameApp theApp;

// The engine log file. Created by CGameApp::InitInstance; the file name is picked once (the first free or the oldest
// of ms2log/MS2Log0..9.txt) and every write re-opens it.
class EngineLog : public TSingleton<EngineLog>
{
public:
    EngineLog();                                                    // 0x141491d70
    virtual ~EngineLog();                                           // 0x1414921b0
    static void Write(efd::UInt16 uiModule, efd::UInt8 uiLevel, const char* pszMessage);       // 0x141492230
};
MS2_CHECK_SIZE(EngineLog, 8);
