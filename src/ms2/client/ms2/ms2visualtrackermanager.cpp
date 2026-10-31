// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2VisualTrackerManager: the game's in-game performance overlay
// (subclass of the engine's egmVisualTracker::VisualTrackerService), plus the ServiceUpdate<T> graph callbacks it uses.
// MS2-UNIT: ?\ms2visualtrackermanager.cpp
// MS2-RANGE: 0x1400f9900-0x1400f9ac0 .text$di
// MS2-RANGE: 0x141515740-0x14151f150 .text$mn
// MS2-RANGE: 0x142cb3350-0x142cb3400 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$ServiceUpdate@VCEffectService@@@@QEAA@XZ 0x14151db90 ; prop
// MS2-PIN: ??0?$ServiceUpdate@VGFxService@@@@QEAA@XZ 0x14151dbc0 ; prop
// MS2-PIN: ??0?$ServiceUpdate@VPropService@ecrPhysX@@@@QEAA@XZ 0x14151dbf0 ; prop
// MS2-PIN: ??0?$ServiceUpdate@VSceneService@egfPhysX@@@@QEAA@XZ 0x14151dc20 ; prop
// MS2-PIN: ??0?$ServiceUpdate@VWorldService@@@@QEAA@XZ 0x14151dc50 ; prop
// MS2-PIN: ?DecRefCount@VisualTrackerService@egmVisualTracker@@UEBAXXZ 0x14151e650 ; unique
// MS2-PIN: ?DeleteThis@VisualTrackerService@egmVisualTracker@@MEBAXXZ 0x14151e690 ; unique
// MS2-PIN: ?FUN_14151e770@Unk_VtmCaches@@QEAAIXZ 0x14151e770 ; unique
// MS2-PIN: ?FUN_14151e790@Unk_VtmCaches@@QEAAIXZ 0x14151e790 ; unique
// MS2-PIN: ?FUN_14151e7c0@Unk_VtmNifCount@@QEAA_KXZ 0x14151e7c0 ; prop
// MS2-PIN: ?TypeCast@VisualTrackerService@egmVisualTracker@@UEBA_NIPEAPEAX@Z 0x14151ea70 ; unique
// MS2-PIN: ?TypeCast@VisualTrackerService@egmVisualTracker@@UEBA_NIPEAPEBX@Z 0x14151eac0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$ServiceUpdate@VCEffectService@@@@UEAA@XZ 0x14151de30 ; hand: linker order by mangled name
// MS2-PIN: ??1?$ServiceUpdate@VGFxService@@@@UEAA@XZ 0x14151de50 ; hand: linker order by mangled name
// MS2-PIN: ??1?$ServiceUpdate@VPropService@ecrPhysX@@@@UEAA@XZ 0x14151de70 ; hand: linker order by mangled name
// MS2-PIN: ??1?$ServiceUpdate@VSceneService@egfPhysX@@@@UEAA@XZ 0x14151de90 ; hand: linker order by mangled name
// MS2-PIN: ??1?$ServiceUpdate@VWorldService@@@@UEAA@XZ 0x14151deb0 ; hand: linker order by mangled name
// MS2-PIN: ??_G?$ServiceUpdate@VCEffectService@@@@UEAAPEAXI@Z 0x14151e270 ; hand: linker order by mangled name
// MS2-PIN: ??_G?$ServiceUpdate@VGFxService@@@@UEAAPEAXI@Z 0x14151e2d0 ; hand: linker order by mangled name
// MS2-PIN: ??_G?$ServiceUpdate@VPropService@ecrPhysX@@@@UEAAPEAXI@Z 0x14151e330 ; hand: linker order by mangled name
// MS2-PIN: ??_G?$ServiceUpdate@VSceneService@egfPhysX@@@@UEAAPEAXI@Z 0x14151e390 ; hand: linker order by mangled name
// MS2-PIN: ??_G?$ServiceUpdate@VWorldService@@@@UEAAPEAXI@Z 0x14151e3f0 ; hand: linker order by mangled name
// MS2-PIN: ??B?$SmartPointer@UUnk_VtmMovieView@@@efd@@QEBAPEAUUnk_VtmMovieView@@XZ 0x14151e150 ; hand: OnTick view test
// MS2-PIN: ??B?$SmartPointer@VCDrawDebugString@@@efd@@QEBAPEAVCDrawDebugString@@XZ 0x14151e160 ; hand: AddDebugString
// MS2-PIN: ??C?$SmartPointer@UUnk_VtmMovieView@@@efd@@QEBAPEAUUnk_VtmMovieView@@XZ 0x14151e170 ; hand: OnTick view call
// MS2-PIN: ??C?$SmartPointer@UUnk_VtmObjectTable@@@efd@@QEBAPEAUUnk_VtmObjectTable@@XZ 0x14151e180 ; hand: OnTick object table
// MS2-PIN: ??C?$SmartPointer@VCDrawDebugString@@@efd@@QEBAPEAVCDrawDebugString@@XZ 0x14151e190 ; hand: AddDebugString calls it
// MS2-PIN: ?GetClassDesc@VisualTrackerService@egmVisualTracker@@UEBAPEBVClassInfo@efd@@XZ 0x14151e7b0 ; hand
// MS2-PIN: ??_7MS2VisualTrackerManager@@6BISystemService@efd@@@ 0x142f28318
// MS2-PIN: ??_7MS2VisualTrackerManager@@6BIRenderServiceDelegate@ecr@@@ 0x142f283b0
// MS2-PIN: ??_7MS2VisualTrackerManager@@6B@ 0x142f28408
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2visualtrackermanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "ms2visualtrackermanager.h"
#include "ms2/unnamed/unit_1414bc310.h"
#include <atlcomcli.h>
#include <d3d9.h>
#include <list>
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxPhysics.h>
#pragma pop_macro("max")
#pragma pop_macro("min")
#include <efd/IConfigManager.h>
#include <efd/ServiceManager.h>
#include <ecr/RenderService.h>
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/gpumanager.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/networkservice.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/placeholder/hardwareinstancingservice.h"
#include <efd/MessageService.h>
#include <egf/FlatModelManager.h>
#include <NiCommonGraphCallbackObjects.h>
#pragma comment(lib, "advapi32.lib")

// The unit's statics: the shared header statics (with the tracker channel and a handle between "stun" and the condition).
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/ms2visualtrackermanager_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/client/ms2/ms2animationservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/ms2scenegraphservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/camera.h"
#undef MS2_STATICS_A_BEFORE_CONDITION


// ---- ServiceUpdate<T>: graph callbacks that plot a service's last tick time ----
class CEffectService;
class GFxService;
class WorldService;
namespace ecrPhysX { class PropService; }
namespace egfPhysX { class SceneService; }
efd::ServiceManager* FUN_1413f9850();                       // the game's service manager

template <class T> struct Unk_ServiceTickId;
template <> struct Unk_ServiceTickId<CEffectService> { enum { ID = 0x610000c }; };
template <> struct Unk_ServiceTickId<GFxService> { enum { ID = 0x6202711 }; };
template <> struct Unk_ServiceTickId<ecrPhysX::PropService> { enum { ID = 0x7002020 }; };
template <> struct Unk_ServiceTickId<egfPhysX::SceneService> { enum { ID = 0x7001008 }; };
template <> struct Unk_ServiceTickId<WorldService> { enum { ID = 0x6100002 }; };

template <class T>
class ServiceUpdate : public NiVisualTracker::GraphCallbackObject
{
public:
    virtual float TakeSample(float)
    {
        double dTime = FUN_1413f9850()->GetServiceLastTickTime(Unk_ServiceTickId<T>::ID);
        return (float)dTime;
    }
};

// ---- unit-local views of out-of-unit objects (bound to the exe by FUN_ name) ----
// Virtual interface stubs: the slots in front of the one that is called ("MS2: slot N" comments at the call sites).
struct Unk_VtmSlots8 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); };
struct Unk_VtmSlots16 : Unk_VtmSlots8 { virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); };
struct Unk_VtmSlots24 : Unk_VtmSlots16 { virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); };
struct Unk_VtmSlots32 : Unk_VtmSlots24 { virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); };
struct Unk_VtmSlots40 : Unk_VtmSlots32 { virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); };
struct Unk_VtmSlots48 : Unk_VtmSlots40 { virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); };
struct Unk_VtmSlots56 : Unk_VtmSlots48 { virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); };
struct Unk_VtmSlots64 : Unk_VtmSlots56 { virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); };
struct Unk_VtmSlots72 : Unk_VtmSlots64 { virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71(); };
struct Unk_VtmSlots80 : Unk_VtmSlots72 { virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77(); virtual void vfunc_78(); virtual void vfunc_79(); };
struct Unk_VtmSlots88 : Unk_VtmSlots80 { virtual void vfunc_80(); virtual void vfunc_81(); virtual void vfunc_82(); virtual void vfunc_83(); virtual void vfunc_84(); virtual void vfunc_85(); virtual void vfunc_86(); virtual void vfunc_87(); };

struct Unk_VtmCount { void* m_pHead; unsigned __int64 m_nSize; unsigned __int64 FUN_14151e8e0() { return m_nSize; } };   // the exe's list header: head pointer, element count
struct Unk_VtmObjectTable { char m_pad[0x10]; Unk_VtmCount m_items; unsigned __int64 FUN_14151e8c0() { return m_items.FUN_14151e8e0(); } };  // +0x10: the list whose size is shown
struct Unk_VtmMovieStats { char m_pad[0x20]; efd::SmartPointer<Unk_VtmObjectTable> m_spObjects; };   // +0x20: the object table
struct Unk_VtmMovieView : Unk_VtmSlots48 { virtual void vfunc_48(); virtual Unk_VtmMovieStats* vfunc_49(); };   // MS2: slot 49
struct Unk_VtmMovie { char m_pad[0x18]; efd::SmartPointer<Unk_VtmMovieView> m_spView; };       // FUN_1422bb8b0(i): UI layer i
struct Unk_VtmMover : Unk_VtmSlots88 { virtual void vfunc_88(); virtual void vfunc_89(); virtual void vfunc_90(); virtual void vfunc_91();
    virtual void vfunc_92(); virtual void vfunc_93(); virtual void vfunc_94(); virtual float GetSpeed(); };       // MS2: slot 95
struct Unk_VtmActor : Unk_VtmSlots16 { virtual void vfunc_16(); virtual void vfunc_17(); virtual void GetPosition(NiPoint3* pOut); };   // MS2: slot 18
class Unk_PhysXSceneHandle { public: char m_pad[0x70]; NxScene* m_pScene; };    // FUN_1416892a0(i): completes the forward declaration in physxhelper.h
struct Unk_PoolEntry
{
    __int64 FUN_14151e640() { return m_nCount; }
    __int64 FUN_14151e880() { return m_nSize; }
    char m_pad0[8]; __int64 m_nCount; char m_pad1[0x18]; __int64 m_nSize; char m_pad2[0x40];
};
MS2_CHECK_SIZE(Unk_PoolEntry, 0x70);
struct Unk_SmallObjectAllocator
{
    unsigned __int64 FUN_14151e7f0();                       // bytes in use over the 256 size classes
    char m_pad[0x10];
    Unk_PoolEntry m_entries[256];
};


struct Unk_SmallObjectAllocatorRef { Unk_SmallObjectAllocator* m_p; };    // passed by value (8-byte copy)

// ---- the nif/texture cache statistics object (FUN_140a0afd0) ----
struct Unk_VtmNifCount { char m_pad[8]; unsigned __int64 m_nCount; unsigned __int64 FUN_14151e7c0() { return m_nCount; } };
struct Unk_VtmTexCount { char m_pad[8]; unsigned __int64 m_nCount; unsigned __int64 FUN_14151e7d0() { return m_nCount; } };
struct Unk_VtmCaches
{
    unsigned FUN_14151e770() { return (unsigned)m_nifs.FUN_14151e7c0(); }
    unsigned FUN_14151e790() { return (unsigned)m_textures.FUN_14151e7d0(); }

    char m_pad0[0x28];
    Unk_VtmNifCount m_nifs;                     // +0x28
    char m_pad1[0x20];
    Unk_VtmTexCount m_textures;                 // +0x58
    char m_pad2[0x70];
    int m_nNifNotCache;                         // +0xd8 the debug counters: nif then texture
    int m_nNifForceKeep;
    int m_nNifMySkill;
    int m_nNifOtherSkill;
    int m_nNifNpc;
    int m_nNifDependTime;
    int m_nTexNotCache;                         // +0xf0
    int m_nTexForceKeep;
    int m_nTexMySkill;
    int m_nTexOtherSkill;
    int m_nTexNpc;
    int m_nTexDependTime;                       // +0x104
};
MS2_CHECK_OFFSET(Unk_VtmCaches, m_nNifNotCache, 0xd8);
MS2_CHECK_OFFSET(Unk_VtmCaches, m_nTexDependTime, 0x104);


// ---- unit-local views of the managers the overlay reads (all bound to the exe by their FUN_ names) ----
class Unk_VtmSession : public WorldService                                                         // the game session (entity/model counters)
{
public:
    unsigned FUN_141bc1640();
    unsigned FUN_141bd86a0();
    unsigned FUN_141bd86c0();
};
CEffectService* FUN_1403ed280();
class Unk_VtmWorldCounts { public: unsigned FUN_1411d0ab0(); unsigned FUN_1411d0af0(); };   // EntityWorldManager block/game-object entity counts, read 32-bit
class Unk_VtmSystem                                                          // memory/system statistics
{
public:
    unsigned FUN_14161bdc0();                                               // page file (MB)
    unsigned FUN_14161be50();                                               // private usage (MB)
    unsigned __int64 FUN_141245b10();                                       // physical memory (MB)
};
Unk_VtmSystem* FUN_1409f7c90();
MS2SceneGraphService* FUN_1413f98b0();
MS2AnimationService* FUN_1413f9b10();
Unk_VtmCaches* FUN_140a0afd0();
class Unk_VtmCameraMgr : public CameraMgr { public: GameObject* FUN_140a38d60(); };
Unk_VtmMover* FUN_1409ffd30(GameObject* pTarget);
class Unk_VtmAnimSvc { public: efd::utf8string FUN_141206030(const egf::EntityID& kKey); };
Unk_VtmAnimSvc* FUN_141b6f910();
Unk_VtmMovie* FUN_1422bb8b0(int nLayer);
CString FUN_141277f60(unsigned nLayer);                                      // name of UI layer nLayer
GPUManager* FUN_141245b20();
__int64 FUN_141245aa0(GPUManager*);
CNetworkService* FUN_140714f90();
CPhysXHelper* FUN_1409f7ca0();
extern char DAT_143b059e8;                                                  // the game framework (service lookup cell)
HardwareInstancingService* FUN_14098c5b0(char*);
unsigned FUN_1413d7eb0(HardwareInstancingService*);
int FUN_1413d7e30(HardwareInstancingService*);
egf::FlatModelManager* FUN_1414f3e00(void* pHandle);
void* FUN_1411d14b0(efd::ServiceManager* pManager);
unsigned FUN_140d868f0(egf::FlatModelManager*);
efd::MessageService* FUN_1411d1530(efd::ServiceManager* pManager);
ecr::RenderService* FUN_1411d15b0(efd::ServiceManager* pManager);
efd::IConfigManager* FUN_1414ef160(efd::ServiceManager* pManager);
int FUN_140392040(char* pBuffer, size_t nSize, const char* pszFormat, ...);
extern unsigned __int64 DAT_143ae0bd0;                                      // PhysX memory in use (bytes)
extern IDirect3D9* DAT_143d6ea00;                                           // the D3D9 object
extern int DAT_143b0d788;                                                   // GFx system allocation (bytes)


// ---- small helpers that the exe keeps as separate functions ----
// @0x14151e7e0
IDirect3D9* GetIDirect3D9() { return DAT_143d6ea00; }
// @0x14151e740
int FUN_14151e740() { return DAT_143b0d788; }
// @0x14151e750: the allocator behind the memory manager
Unk_SmallObjectAllocator* FUN_14151e750()
{
    Unk_SmallObjectAllocator* pAlloc = *reinterpret_cast<Unk_SmallObjectAllocator**>(&efd::MemManager::Get());
    return pAlloc;
}  // MS2: reads MemManager::m_pkAllocator
// @0x14151e8f0
int FUN_14151e8f0(GPUManager* pGpu) { return pGpu->m_30; }
// @0x14151e890
NxScene* FUN_14151e890(Unk_PhysXSceneHandle* pHandle) { return pHandle->m_pScene; }

// @0x14151e7f0: bytes held by the 256 small-object size classes
unsigned __int64 FUN_14151e7f0(Unk_SmallObjectAllocatorRef kAlloc)
{
    unsigned __int64 nTotal = 0;
    for (unsigned i = 0; i < 256; ++i)
        nTotal += kAlloc.m_p->m_entries[i].FUN_14151e640() * kAlloc.m_p->m_entries[i].FUN_14151e880();
    return nTotal;
}

// ---- the page of the entity chart (a dead copy of the engine's Entities page) ----
// @0x14151d0d0
void FUN_14151d0d0(egmVisualTracker::VisualTrackerService* pService)
{
    const float fBorderX = 0.05f;
    const float fBorderY = 0.025f;
    NiRect<float> kEntityRect(-4000.0f, 4000.0f, 4000.0f, -4000.0f);
    pService->AddPage("Entities");
    pService->AddChart("Entities", kEntityRect, NiRect<float>(fBorderX, 1.0f - fBorderX, fBorderY, 1.0f - fBorderY), 0.1f, 0, true);
    pService->AddLegend("Actors", efd::Color(0.0f, 0.0f, 1.0f), egmVisualTracker::VisualTrackerService::SGS_stick_man);
    pService->AddLegend("Triggers", efd::Color(0.0f, 1.0f, 0.0f), egmVisualTracker::VisualTrackerService::SGS_circle_large_hollow);
    pService->AddLegend("Camera", efd::Color(1.0f, 1.0f, 1.0f), egmVisualTracker::VisualTrackerService::SGS_camera);
    pService->AddLegend("Lights", efd::Color(1.0f, 1.0f, 0.0f), egmVisualTracker::VisualTrackerService::SGS_lightbulb);
    pService->AddLegend("Active", efd::Color(1.0f, 0.0f, 0.0f), egmVisualTracker::VisualTrackerService::SGS_square);
    pService->AddLegend("Static", efd::Color(0.5f, 0.5f, 0.5f), egmVisualTracker::VisualTrackerService::SGS_square_small);
}

// ---- the singleton base ----
TSingleton<MS2VisualTrackerManager>::TSingleton() { s_instance = static_cast<MS2VisualTrackerManager*>(this); }      // 0x14151dd80
MS2VisualTrackerManager* TSingleton<MS2VisualTrackerManager>::s_instance = 0;                                         // 0x143ae0f40

// ---- construction / destruction ----
// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x141515740
MS2VisualTrackerManager::MS2VisualTrackerManager()
    : m_nPage(0), m_idDebugStringPage(0), m_idSystemPage(0), m_idDebuggingPage(0), m_idPhysXPage(0), m_fGpuMemoryMB(0.0f),
      m_pPerformanceChart(0), m_pTimeChart(0), m_pPacketChart(0)
{
}
#endif

// @0x141515e80
MS2VisualTrackerManager::~MS2VisualTrackerManager()
{
}

// @0x141516490
efd::AsyncResult MS2VisualTrackerManager::OnInit()
{
    efd::MessageService* pMessageService = FUN_1411d1530(m_pServiceManager);
    pMessageService->Subscribe(this, s_visualTrackerCategory);
    m_pRenderService = FUN_1411d15b0(m_pServiceManager);
    m_pRenderService->AddDelegate(this);
    AddSurface(m_pRenderService->GetActiveRenderSurface());
    CreateVisualTrackers();
    return efd::AsyncResult_Complete;
}

// @0x141517ea0
void MS2VisualTrackerManager::ToggleShowTrackers()
{
    ++m_nPage;
    if ((unsigned)m_nPage > (unsigned)m_pages.size())
        m_nPage = 0;
    if (m_nPage == 0)
    {
        SetShowTrackers(false);
    }
    else
    {
        SetShowTrackers(true);
        SelectPage(m_nPage - 1);
    }
}

// @0x141517f40
efd::AsyncResult MS2VisualTrackerManager::OnShutdown()
{
    m_pPerformanceChart = 0;
    m_pTimeChart = 0;
    m_pPacketChart = 0;
    // The exe releases the lines one by one in this order (the kept order matters only to the byte match).
    m_spFps = 0; m_spFrameTime = 0; m_spVisObjects = 0; m_spInstancingGroup = 0; m_spEffectCount = 0;
    m_spInfiniteEffectCount = 0; m_spActorCount = 0; m_spAssetCount = 0; m_spKfmCacheCount = 0; m_spNifCount = 0;
    m_spTextureCount = 0; m_spNpcCount = 0; m_spVertices = 0; m_spTriangles = 0; m_spEntityCount = 0;
    m_spPageFile = 0; m_spSmallObject = 0; m_spPrivateUsage = 0; m_spGfxSysAlloc = 0; m_spBlockEntityCount = 0;
    m_spGameObjectEntityCount = 0; m_spSceneGraphCacheCount = 0; m_spUseInstancing = 0; m_spPos = 0; m_spSpeed = 0;
    m_spAnim = 0; m_spOsName = 0; m_spMemory = 0; m_spInstancingGrid = 0; m_spCpuName = 0; m_spGpuName = 0;
    m_spGpuCore = 0; m_spGpuMemory = 0; m_spGpuAllocMemory = 0; m_spLoadedMap = 0; m_spEffectOid = 0;
    m_spNifNotCache = 0; m_spNifForceKeep = 0; m_spNifMySkill = 0; m_spNifOtherSkill = 0; m_spNifNpc = 0;
    m_spNifDependTime = 0; m_spTexNotCache = 0; m_spTexForceKeep = 0; m_spTexMySkill = 0; m_spTexOtherSkill = 0;
    m_spTexNpc = 0; m_spTexDependTime = 0; m_spPhysXMem = 0; m_spPx0AwakeGroups = 0; m_spPx0Actors = 0;
    m_spPx0DynamicActors = 0; m_spPx0DynamicShapes = 0; m_spPx0Joints = 0; m_spPx0Contacts = 0; m_spPx0Pairs = 0;
    m_spPx0AxisConstraints = 0; m_spPx0SolverBodies = 0; m_spPx0StaticShapes = 0; m_spPx1AwakeGroups = 0;
    m_spPx1Actors = 0; m_spPx1DynamicActors = 0; m_spPx1DynamicShapes = 0; m_spPx1Joints = 0; m_spPx1Contacts = 0;
    m_spPx1Pairs = 0; m_spPx1AxisConstraints = 0; m_spPx1SolverBodies = 0; m_spPx1StaticShapes = 0;
    m_spFlatModelCount = 0;
    for (unsigned i = 0; i < 7; ++i)
        m_spSortLabel[i] = 0;
    return VisualTrackerService::OnShutdown();
}

// ---- the per-tick refresh of the lines of the selected page ----
// @0x141516580
efd::AsyncResult MS2VisualTrackerManager::OnTick()
{
    if (!m_showTrackers)
        return efd::AsyncResult_Pending;

    bool bForce = false;
    if (m_nPage == 1)
    {
        m_spFps->FUN_14118bb40(FUN_14086d260()->FUN_141473210(), bForce, 0);
        if (FUN_14086d260()->FUN_141473210() != 0.0f)
        {
            m_spFrameTime->FUN_14118bb40(1000.0f / FUN_14086d260()->FUN_141473210(), bForce, 0);
        }
        m_spVisObjects->FUN_14118b820(m_numObjectsDrawn, bForce, 0);

        efd::SmartPointer<HardwareInstancingService> spInstancing(FUN_14098c5b0(&DAT_143b059e8));
        if ((HardwareInstancingService*)spInstancing != 0)
        {
            m_spInstancingGroup->FUN_14118b9b0(FUN_1413d7eb0(spInstancing.operator->()), bForce, 0);
            m_spInstancingGrid->FUN_14118b820(FUN_1413d7e30(spInstancing.operator->()), bForce, 0);
            m_spUseInstancing->FUN_14118bc70(reinterpret_cast<Unk_VtmSession*>(WorldService::GetInstance())->FUN_141bc7420(), bForce, 0);
        }
        m_spEffectCount->FUN_14118b9b0(FUN_1403ed280()->FUN_1411a85a0(), bForce, 0);
        m_spInfiniteEffectCount->FUN_14118b9b0(FUN_1403ed280()->FUN_1411a85c0(), bForce, 0);
        m_spNpcCount->FUN_14118b9b0(reinterpret_cast<Unk_VtmSession*>(WorldService::GetInstance())->FUN_141bc1640(), bForce, 0);
        m_spVertices->FUN_14118b9b0(reinterpret_cast<Unk_VtmSession*>(WorldService::GetInstance())->FUN_141bd86a0(), bForce, 0);
        m_spTriangles->FUN_14118b9b0(reinterpret_cast<Unk_VtmSession*>(WorldService::GetInstance())->FUN_141bd86c0(), bForce, 0);
        m_spBlockEntityCount->FUN_14118b9b0(reinterpret_cast<Unk_VtmWorldCounts*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411d0ab0(), bForce, 0);
        m_spGameObjectEntityCount->FUN_14118b9b0(reinterpret_cast<Unk_VtmWorldCounts*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411d0af0(), bForce, 0);
        m_spEntityCount->FUN_14118b9b0(TSingleton<EntityWorldManager>::GetInstance()->FUN_1411d0b30(), bForce, 0);
        m_spLoadedMap->FUN_14118b9b0(TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cfbe0(), bForce, 0);

        // Number of objects held by the GFx movie of each UI layer.
        for (unsigned nLayer = 0; nLayer < 7; ++nLayer)
        {
            Unk_VtmMovie* pMovie = FUN_1422bb8b0(nLayer);
            if (pMovie != 0)
            {
                if ((Unk_VtmMovieView*)pMovie->m_spView != 0 ? true : false)
                {
                    Unk_VtmMovieStats* pStats = pMovie->m_spView->vfunc_49();       // MS2: slot 49
                    if (pStats != 0)
                    {
                        m_spSortLabel[nLayer]->FUN_14118b9b0((unsigned)pStats->m_spObjects->FUN_14151e8c0(), bForce, 0);
                    }
                }
            }
        }

        // Position, animation and speed of the camera target.
        if (reinterpret_cast<Unk_VtmCameraMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140a18070() != 0)
        {
            GameObject* pTarget = reinterpret_cast<Unk_VtmCameraMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140a38d60();
            Unk_VtmMover* pMover = FUN_1409ffd30(pTarget);
            if (pTarget != 0)
            {
                NiPoint3 kPos = pTarget->vfunc_18();
                m_spPos->FUN_14118bdc0(kPos, bForce);
                unsigned __int64 nKey;      // the egf::EntityID 0x14123c460 fills (no constructor runs on it)
                efd::utf8string strAnim = FUN_141b6f910()->FUN_141206030(pTarget->FUN_14123c460(reinterpret_cast<egf::EntityID&>(nKey)));
                m_spAnim->FUN_14118bee0(strAnim, bForce);
            }
            if (pMover != 0)
                m_spSpeed->FUN_14118bb40(pMover->GetSpeed(), bForce, 0);
            else
                m_spSpeed->FUN_14118b820(0, bForce, 0);
        }

        m_spEffectOid->FUN_14118b9b0(FUN_1403ed280()->FUN_1411b1bd0(), bForce, 0);
        egf::FlatModelManager* pFlatModels = FUN_1414f3e00(FUN_1411d14b0(m_pServiceManager));
        if (pFlatModels != 0)
            m_spFlatModelCount->FUN_14118b820(FUN_140d868f0(pFlatModels), bForce, 0);
    }

    if (m_nPage == 2)
    {
        unsigned nMb = FUN_1409f7c90()->FUN_14161bdc0();
        m_spPageFile->FUN_14118b9b0(nMb, bForce, 0);
        nMb = FUN_1409f7c90()->FUN_14161be50();
        m_spPrivateUsage->FUN_14118b9b0(nMb, bForce, 0);
        efd::MemManager::Get();
        Unk_SmallObjectAllocator* pAlloc = FUN_14151e750();
        if (pAlloc != 0)
        {
            unsigned nKb = (unsigned)(FUN_14151e7f0(Unk_SmallObjectAllocatorRef{ pAlloc }) / 0x400);
            int nSysAllocMb = FUN_14151e740() / 0x100000;
            m_spSmallObject->FUN_14118b9b0(nKb, bForce, 0);
            m_spGfxSysAlloc->FUN_14118b820(nSysAllocMb, bForce, 0);
        }
        MS2SceneGraphService* pSceneGraphs = FUN_1413f98b0();
        if (pSceneGraphs != 0)
            m_spSceneGraphCacheCount->FUN_14118b9b0(pSceneGraphs->FUN_1414f3660(), bForce, 0);
        MS2AnimationService* pAssets = FUN_1413f9b10();
        if (pAssets != 0)
        {
            m_spAssetCount->FUN_14118b9b0(pAssets->GetAssetCount(), bForce, 0);
            m_spActorCount->FUN_14118b9b0(pAssets->GetActorCount(), bForce, 0);
            m_spKfmCacheCount->FUN_14118b9b0(pAssets->GetKFMCacheCount(), bForce, 0);
        }
        m_spNifCount->FUN_14118b9b0(FUN_140a0afd0()->FUN_14151e770(), bForce, 0);
        m_spTextureCount->FUN_14118b9b0(FUN_140a0afd0()->FUN_14151e790(), bForce, 0);

        unsigned nGpuTotalMb = FUN_141245b20()->FUN_141375c90();
        unsigned nGpuUsedMb = FUN_141245b20()->FUN_141375c80();
        int nGpuCore = FUN_14151e8f0(FUN_141245b20());
        int nGpuPercent = FUN_141245b20()->FUN_141375ca0();
        m_spGpuCore->FUN_14118b820(nGpuCore, true, "%");
        float fRatio = (float)nGpuPercent * 0.01f;
        m_fGpuMemoryMB = fRatio * (float)nGpuTotalMb;
        char acText[64];
        FUN_140392040(acText, 0x40, "%% %0.f(MB)", (double)m_fGpuMemoryMB);
        m_spGpuMemory->FUN_14118b820(nGpuPercent, bForce, acText);
        FUN_140392040(acText, 0x40, "/%u(MB)", nGpuTotalMb);
        m_spGpuAllocMemory->FUN_14118b9b0(nGpuUsedMb, bForce, acText);
        unsigned nPhysXKb = (unsigned)(DAT_143ae0bd0 / 0x400);
        m_spPhysXMem->FUN_14118b9b0(nPhysXKb, bForce, 0);
        FUN_140714f90()->FUN_1415392e0();
    }

    if (m_nPage == 3)
    {
        if (reinterpret_cast<Unk_VtmSession*>(WorldService::GetInstance())->FUN_141bcfbd0() != 0)
        {
            Unk_PhysXSceneHandle* pHandle = FUN_1409f7ca0()->FUN_1416892a0(0);
            if (pHandle != 0)
            {
                FUN_1409f7ca0()->FUN_14168a540(0);
                NxScene* pScene = FUN_14151e890(pHandle);
                if (pScene != 0)
                {
                    CString strMax;
                    NxSceneStats kStats;
                    pScene->getStats(kStats);
                    strMax.Format("/%d", kStats.maxDynamicActorsInAwakeGroups);
                    m_spPx0AwakeGroups->FUN_14118b9b0(kStats.numDynamicActorsInAwakeGroups, bForce, (const char*)strMax);
                    // the scene-0 actor count goes to scene 1's line (original bug; m_spPx0Actors is never updated)
                    strMax.Format("/%d", kStats.maxActors);
                    m_spPx1Actors->FUN_14118b9b0(kStats.numActors, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxDynamicActors);
                    m_spPx0DynamicActors->FUN_14118b9b0(kStats.numDynamicActors, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxDynamicShapes);
                    m_spPx0DynamicShapes->FUN_14118b9b0(kStats.numDynamicShapes, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxJoints);
                    m_spPx0Joints->FUN_14118b9b0(kStats.numJoints, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxContacts);
                    m_spPx0Contacts->FUN_14118b9b0(kStats.numContacts, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxPairs);
                    m_spPx0Pairs->FUN_14118b9b0(kStats.numPairs, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxAxisConstraints);
                    m_spPx0AxisConstraints->FUN_14118b9b0(kStats.numAxisConstraints, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxSolverBodies);
                    m_spPx0SolverBodies->FUN_14118b9b0(kStats.numSolverBodies, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxStaticShapes);
                    m_spPx0StaticShapes->FUN_14118b9b0(kStats.numStaticShapes, bForce, (const char*)strMax);
                }
                FUN_1409f7ca0()->FUN_14168a570();
            }
            pHandle = FUN_1409f7ca0()->FUN_1416892a0(1);
            if (pHandle != 0)
            {
                FUN_1409f7ca0()->FUN_14168a540(0);
                NxScene* pScene = FUN_14151e890(pHandle);
                if (pScene != 0)
                {
                    CString strMax;
                    NxSceneStats kStats;
                    pScene->getStats(kStats);
                    strMax.Format("/%d", kStats.maxDynamicActorsInAwakeGroups);
                    m_spPx1AwakeGroups->FUN_14118b9b0(kStats.numDynamicActorsInAwakeGroups, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxActors);
                    m_spPx1Actors->FUN_14118b9b0(kStats.numActors, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxDynamicActors);
                    m_spPx1DynamicActors->FUN_14118b9b0(kStats.numDynamicActors, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxDynamicShapes);
                    m_spPx1DynamicShapes->FUN_14118b9b0(kStats.numDynamicShapes, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxJoints);
                    m_spPx1Joints->FUN_14118b9b0(kStats.numJoints, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxContacts);
                    m_spPx1Contacts->FUN_14118b9b0(kStats.numContacts, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxPairs);
                    m_spPx1Pairs->FUN_14118b9b0(kStats.numPairs, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxAxisConstraints);
                    m_spPx1AxisConstraints->FUN_14118b9b0(kStats.numAxisConstraints, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxSolverBodies);
                    m_spPx1SolverBodies->FUN_14118b9b0(kStats.numSolverBodies, bForce, (const char*)strMax);
                    strMax.Format("/%d", kStats.maxStaticShapes);
                    m_spPx1StaticShapes->FUN_14118b9b0(kStats.numStaticShapes, bForce, (const char*)strMax);
                }
                FUN_1409f7ca0()->FUN_14168a570();
            }
        }
    }

    if (m_nPage == 4)
    {
        m_spNifNotCache->FUN_14118b9b0(FUN_140a0afd0()->m_nNifNotCache, bForce, 0);
        m_spNifForceKeep->FUN_14118b9b0(FUN_140a0afd0()->m_nNifForceKeep, bForce, 0);
        m_spNifMySkill->FUN_14118b9b0(FUN_140a0afd0()->m_nNifMySkill, bForce, 0);
        m_spNifOtherSkill->FUN_14118b9b0(FUN_140a0afd0()->m_nNifOtherSkill, bForce, 0);
        m_spNifNpc->FUN_14118b9b0(FUN_140a0afd0()->m_nNifNpc, bForce, 0);
        m_spNifDependTime->FUN_14118b9b0(FUN_140a0afd0()->m_nNifDependTime, bForce, 0);
        m_spTexNotCache->FUN_14118b9b0(FUN_140a0afd0()->m_nTexNotCache, bForce, 0);
        m_spTexForceKeep->FUN_14118b9b0(FUN_140a0afd0()->m_nTexForceKeep, bForce, 0);
        m_spTexMySkill->FUN_14118b9b0(FUN_140a0afd0()->m_nTexMySkill, bForce, 0);
        m_spTexOtherSkill->FUN_14118b9b0(FUN_140a0afd0()->m_nTexOtherSkill, bForce, 0);
        m_spTexNpc->FUN_14118b9b0(FUN_140a0afd0()->m_nTexNpc, bForce, 0);
        m_spTexDependTime->FUN_14118b9b0(FUN_140a0afd0()->m_nTexDependTime, bForce, 0);
    }

    return VisualTrackerService::OnTick();
}

// ---- building the overlay ----
// @0x14151cf50: one debug text line on the given page
CDrawDebugStringPtr MS2VisualTrackerManager::AddDebugString(unsigned page, const char* pszLabel, int x, int y, NiColorA color)
{
    CDrawDebugStringPtr spLine = NiNew CDrawDebugString("DebugFont", color);
    // MS2: the exe's render click list holds NiVisualTracker pointers and the debug string rides in it
    // (CDrawDebugString derives from NiVisualTrackerBase here).
    {
        efd::SmartPointer<NiVisualTracker> spTracker(reinterpret_cast<NiVisualTracker*>((CDrawDebugString*)spLine));
        m_pages[page]->GetVisualTrackers().AddTail(spTracker);
    }
    spLine->FUN_14118bf80(pszLabel, x, y);
    return spLine;
}

// @0x14151d350: the [VisualTracker] maximum values of the charts
void MS2VisualTrackerManager::LoadConfig()
{
    efd::IConfigManager* pConfigManager = FUN_1414ef160(m_pServiceManager);
    if (pConfigManager)
    {
        const efd::ISection* pSection = pConfigManager->GetConfiguration();
        if (pSection)
        {
            pSection = pSection->FindSection("VisualTracker");
            efd::utf8string value;
            if (pSection)
            {
                if (pSection->FindValue("PerfMaxValue", value))
                    efd::ParseHelper<efd::Float32>::FromString(value, m_performanceMax);
                if (pSection->FindValue("TimingMaxValue", value))
                    efd::ParseHelper<efd::Float32>::FromString(value, m_timeMax);
                if (pSection->FindValue("MemMaxValue", value))
                    efd::ParseHelper<efd::Float32>::FromString(value, m_memoryMax);
            }
        }
    }
}

// @0x14151d570: like VisualTrackerService::AddChart, but hands back the tracker
egmVisualTracker::VisualTrackerService::VisualTracker* MS2VisualTrackerManager::AddChartPage(const char* pszName,
    NiRect<float> kDataRange, NiRect<float> kWindowRect, efd::TimeType fRate, unsigned nDecimals, bool bUpdateOnlyWhenVisible)
{
    if (m_pages.size() < m_curPageIndex)
        return 0;
    VisualTracker* pTracker = NiNew VisualTracker(pszName, kDataRange, kWindowRect, fRate, nDecimals, bUpdateOnlyWhenVisible);
    pTracker->SetShow(false);
    m_pages[m_curPageIndex]->GetVisualTrackers().AddTail(pTracker);
    return pTracker;
}

// @0x141518590 (vfunc_17): builds the four pages and three charts of the overlay.
bool MS2VisualTrackerManager::CreateVisualTrackers()
{
    LoadConfig();

    NiColor blue(0.0f, 0.0f, 1.0f);
    NiColor yellow(1.0f, 1.0f, 0.0f);
    NiColor red(1.0f, 0.0f, 0.0f);
    NiColor lightBlue(0.5f, 0.5f, 1.0f);
    NiColor lightYellow(1.0f, 1.0f, 0.5f);
    NiColor lightRed(1.0f, 0.5f, 0.5f);

    // --- page 0: DebugString ---
    m_idDebugStringPage = AddPage("DebugString");
    m_spFps = AddDebugString(m_idDebugStringPage, "FPS:", 10, 20, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spFrameTime = AddDebugString(m_idDebugStringPage, "Time(ms):", 150, 20, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spEffectCount = AddDebugString(m_idDebugStringPage, "Effect Count:", 350, 20, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spInfiniteEffectCount = AddDebugString(m_idDebugStringPage, "Infinite effect Count: ", 690, 20, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spEntityCount = AddDebugString(m_idDebugStringPage, "Entity Count:", 10, 40, NiColorA(0.0f, 0.0f, 8.0f, 1.0f));
    m_spBlockEntityCount = AddDebugString(m_idDebugStringPage, "BlockEntity Count:", 350, 40, NiColorA(0.0f, 0.0f, 8.0f, 1.0f));
    m_spGameObjectEntityCount = AddDebugString(m_idDebugStringPage, "GameObjectEntity Count:", 690, 40, NiColorA(0.0f, 0.0f, 8.0f, 1.0f));
    m_spUseInstancing = AddDebugString(m_idDebugStringPage, "Use Instancing:", 350, 60, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spInstancingGroup = AddDebugString(m_idDebugStringPage, "Instancing Group:", 690, 60, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spInstancingGrid = AddDebugString(m_idDebugStringPage, "Instancing Gride:", 1030, 60, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spVisObjects = AddDebugString(m_idDebugStringPage, "VisObjects:", 10, 80, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    m_spVertices = AddDebugString(m_idDebugStringPage, "Vertices:", 350, 80, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    m_spTriangles = AddDebugString(m_idDebugStringPage, "Triangles:", 690, 80, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    m_spNpcCount = AddDebugString(m_idDebugStringPage, "Npc Count:", 10, 100, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spLoadedMap = AddDebugString(m_idDebugStringPage, "Loaded Map:", 350, 100, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spPos = AddDebugString(m_idDebugStringPage, "Pos:", 690, 100, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    m_spSpeed = AddDebugString(m_idDebugStringPage, "Speed:", 1030, 100, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spAnim = AddDebugString(m_idDebugStringPage, "Anim:", 690, 120, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    int y = 120;
    for (unsigned i = 0; i < 7; ++i)
    {
        CString strLabel;
        strLabel.Format("%s:", (const char*)FUN_141277f60(i));
        m_spSortLabel[i] = AddDebugString(m_idDebugStringPage, strLabel, 10, y, NiColorA(1.0f, 0.0f, 0.0f, 1.0f));
        y += 20;
    }
    m_spFlatModelCount = AddDebugString(m_idDebugStringPage, "FlatModelCount:", 350, 120, NiColorA(1.0f, 0.0f, 0.0f, 1.0f));
    m_spEffectOid = AddDebugString(m_idDebugStringPage, "EffectOID:", 1030, 120, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));

    // --- charts (on the DebugString page) ---
    const float fBorderX = 0.05f;
    const float fGap = 0.025f;
    const float fHeight = 0.25f;
    const float fWidth = 0.9f;
    NiRect<float> windowRect1(0.0f, 0.0f, 0.0f, 0.0f);
    windowRect1.m_left = fBorderX;
    windowRect1.m_right = windowRect1.m_left + fWidth;
    windowRect1.m_top = 0.15f;
    windowRect1.m_bottom = windowRect1.m_top + fHeight;
    NiRect<float> windowRect2(0.0f, 0.0f, 0.0f, 0.0f);
    windowRect2.m_left = fBorderX;
    windowRect2.m_right = windowRect2.m_left + fWidth;
    windowRect2.m_top = windowRect1.m_bottom + fGap;
    windowRect2.m_bottom = windowRect2.m_top + fHeight;

    m_pPerformanceChart = AddChartPage("Performance", NiRect<float>(0.0f, 100.0f, m_performanceMax, 0.0f), windowRect1, 0.1f, 0, true);
    m_pPerformanceChart->AddGraph("Frame-Rate", NiNew FrameRateUpdate(&m_frameRate), red, true);
    m_pPerformanceChart->AddGraph("Vis Objects", NiNew GenericUnsignedIntUpdate(1.0f, &m_numObjectsDrawn), yellow, true);
    m_pPerformanceChart->AddGraph("GPU Memory(MB)", NiNew GenericFloatUpdate(1.0f, &m_fGpuMemoryMB), NiColor(0.5f, 1.0f, 0.5f), true);

    m_pTimeChart = AddChartPage("Time (ms)", NiRect<float>(0.0f, 100.0f, m_timeMax, 0.0f), windowRect2, 0.1f, 0, true);
    m_pTimeChart->AddGraph("Frame Time", NiNew GenericFloatUpdate(0.001f, &m_frameTime), red, true);
    m_pTimeChart->AddGraph("Simulate", NiNew FrameEventUpdate(), NiColor(1.0f, 1.0f, 0.0f), true);
    m_pTimeChart->AddGraph("world", NiNew ServiceUpdate<WorldService>, NiColor(0.0f, 1.0f, 1.0f), true);
    m_pTimeChart->AddGraph("effect", NiNew ServiceUpdate<CEffectService>, NiColor(1.0f, 0.5f, 0.5f), true);
    m_pTimeChart->AddGraph("gfx", NiNew ServiceUpdate<GFxService>, NiColor(0.5f, 0.5f, 1.0f), true);
    m_pTimeChart->AddGraph("Prop", NiNew ServiceUpdate<ecrPhysX::PropService>, NiColor(0.7f, 0.7f, 0.7f), true);
    m_pTimeChart->AddGraph("Scene", NiNew ServiceUpdate<egfPhysX::SceneService>, NiColor(0.5f, 0.0f, 1.0f), true);

    // --- page 1: System ---
    m_idSystemPage = AddPage("System");
    m_spOsName = AddDebugString(m_idSystemPage, TSingleton<COSInfo>::GetInstance()->GetFullName(), 10, 20, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    {
        char szText[128];
        unsigned __int64 nVideoMem = FUN_1409f7c90()->FUN_141245b10();
        float fGB = (float)nVideoMem / 1024.0f;
        FUN_140392040(szText, 128, "%.1fGB", (double)fGB);
        m_spMemory = AddDebugString(m_idSystemPage, szText, 670, 20, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));

        DWORD cb = 128;
        HKEY hKey;
        RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Hardware\\Description\\System\\CentralProcessor\\0", 0, KEY_QUERY_VALUE, &hKey);
        RegQueryValueExA(hKey, "ProcessorNameString", NULL, NULL, (LPBYTE)szText, &cb);
        m_spCpuName = AddDebugString(m_idSystemPage, szText, 300, 20, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    }
    if (GetIDirect3D9())
    {
        D3DADAPTER_IDENTIFIER9 kIdent;
        GetIDirect3D9()->GetAdapterIdentifier(0, 0, &kIdent);
        CString strGpu(kIdent.Description);
        if (FUN_141245aa0(FUN_141245b20()) != 0)
            strGpu.Format("%s [bw:%d]", kIdent.Description, FUN_141245aa0(FUN_141245b20()));
        m_spGpuName = AddDebugString(m_idSystemPage, strGpu, 780, 20, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    }
    m_spPageFile = AddDebugString(m_idSystemPage, "PageFile(MB):", 10, 40, NiColorA(0.0f, 0.0f, 8.0f, 1.0f));
    m_spSmallObject = AddDebugString(m_idSystemPage, "SmallObject(KB):", 350, 40, NiColorA(0.7f, 0.7f, 0.7f, 1.0f));
    m_spGfxSysAlloc = AddDebugString(m_idSystemPage, "GFX SysAlloc(MB):", 690, 40, NiColorA(0.7f, 0.7f, 0.7f, 1.0f));
    m_spNifCount = AddDebugString(m_idSystemPage, "Nif Count:", 10, 60, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    m_spTextureCount = AddDebugString(m_idSystemPage, "Texture Count:", 350, 60, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    m_spSceneGraphCacheCount = AddDebugString(m_idSystemPage, "SceneGraph Cache Count:", 690, 60, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    m_spActorCount = AddDebugString(m_idSystemPage, "Actor Count:", 10, 80, NiColorA(0.7f, 0.7f, 0.7f, 1.0f));
    m_spAssetCount = AddDebugString(m_idSystemPage, "Asset Count:", 350, 80, NiColorA(0.7f, 0.7f, 0.7f, 1.0f));
    m_spKfmCacheCount = AddDebugString(m_idSystemPage, "KFMCache Count:", 690, 80, NiColorA(0.7f, 0.7f, 0.7f, 1.0f));
    m_spGpuCore = AddDebugString(m_idSystemPage, "GPU Core:", 10, 100, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spGpuMemory = AddDebugString(m_idSystemPage, "GPU Memory:", 350, 100, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spGpuAllocMemory = AddDebugString(m_idSystemPage, "GPU Alloc Memory:", 690, 100, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spPhysXMem = AddDebugString(m_idSystemPage, "PhysX Mem(KB):", 10, 120, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spPrivateUsage = AddDebugString(m_idSystemPage, "PrivateUsage(MB):", 350, 120, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));

    const float fMaxTraffic = 10000.0f;
    m_pPacketChart = AddChartPage("Packet Traffic", NiRect<float>(0.0f, 100.0f, fMaxTraffic, 0.0f),
        NiRect<float>(0.05f, 0.95f, 0.25f, 0.6f), 0.1f, 0, true);
    float* pfRecvSize = (float*)FUN_140714f90()->FUN_141539330();
    float* pfSendSize = (float*)FUN_140714f90()->FUN_141539380();
    m_pPacketChart->AddGraph("RecvSize", NiNew GenericFloatUpdate(1.0f, pfRecvSize), yellow, true);
    m_pPacketChart->AddGraph("SendSize", NiNew GenericFloatUpdate(1.0f, pfSendSize), red, true);

    // --- page 2: PhysX ---
    m_idPhysXPage = AddPage("PhysX");
    m_spPx0AwakeGroups = AddDebugString(m_idPhysXPage, "NumAwakeGroups:", 10, 20, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx0Actors = AddDebugString(m_idPhysXPage, "NumActors:", 10, 40, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx0DynamicActors = AddDebugString(m_idPhysXPage, "NumDynamicActors:", 10, 60, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx0DynamicShapes = AddDebugString(m_idPhysXPage, "NumDynamicShapes:", 10, 80, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx0Joints = AddDebugString(m_idPhysXPage, "NumJoints:", 10, 100, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx0Contacts = AddDebugString(m_idPhysXPage, "NumContacts:", 10, 120, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx0Pairs = AddDebugString(m_idPhysXPage, "NumPairs:", 10, 140, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx0AxisConstraints = AddDebugString(m_idPhysXPage, "NumAxisConstraints:", 10, 160, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx0SolverBodies = AddDebugString(m_idPhysXPage, "NumSolverBodies:", 10, 180, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx0StaticShapes = AddDebugString(m_idPhysXPage, "NumStaticShapes:", 10, 200, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1AwakeGroups = AddDebugString(m_idPhysXPage, "NumAwakeGroups:", 350, 20, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1Actors = AddDebugString(m_idPhysXPage, "NumActors:", 350, 40, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1DynamicActors = AddDebugString(m_idPhysXPage, "NumDynamicActors:", 350, 60, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1DynamicShapes = AddDebugString(m_idPhysXPage, "NumDynamicShapes:", 350, 80, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1Joints = AddDebugString(m_idPhysXPage, "NumJoints:", 350, 100, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1Contacts = AddDebugString(m_idPhysXPage, "NumContacts:", 350, 120, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1Pairs = AddDebugString(m_idPhysXPage, "NumPairs:", 350, 140, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1AxisConstraints = AddDebugString(m_idPhysXPage, "NumAxisConstraints:", 350, 160, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1SolverBodies = AddDebugString(m_idPhysXPage, "NumSolverBodies:", 350, 180, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));
    m_spPx1StaticShapes = AddDebugString(m_idPhysXPage, "NumStaticShapes:", 350, 200, NiColorA(1.0f, 1.0f, 1.0f, 1.0f));

    // --- page 3: Debugging ---
    m_idDebuggingPage = AddPage("Debugging");
    m_spNifNotCache = AddDebugString(m_idDebuggingPage, "Nif NotCacheCount:", 10, 20, NiColorA(0.7f, 0.7f, 0.7f, 1.0f));
    m_spNifForceKeep = AddDebugString(m_idDebuggingPage, "Nif ForceKeepCount:", 10, 40, NiColorA(0.0f, 0.0f, 8.0f, 1.0f));
    m_spNifMySkill = AddDebugString(m_idDebuggingPage, "Nif NifMySkillCount:", 10, 60, NiColorA(0.0f, 0.0f, 8.0f, 1.0f));
    m_spNifOtherSkill = AddDebugString(m_idDebuggingPage, "Nif OtherSkillCount:", 10, 80, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spNifNpc = AddDebugString(m_idDebuggingPage, "Nif NPCCount:", 10, 100, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spNifDependTime = AddDebugString(m_idDebuggingPage, "Nif DependTimeCount:", 10, 120, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    m_spTexNotCache = AddDebugString(m_idDebuggingPage, "Texture NotCacheCount:", 350, 20, NiColorA(0.7f, 0.7f, 0.7f, 1.0f));
    m_spTexForceKeep = AddDebugString(m_idDebuggingPage, "Texture ForceKeepCount:", 350, 40, NiColorA(0.0f, 0.0f, 8.0f, 1.0f));
    m_spTexMySkill = AddDebugString(m_idDebuggingPage, "Texture MySkillCount:", 350, 60, NiColorA(0.0f, 0.0f, 8.0f, 1.0f));
    m_spTexOtherSkill = AddDebugString(m_idDebuggingPage, "Texture OtherSkillCount:", 350, 80, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spTexNpc = AddDebugString(m_idDebuggingPage, "Texture NPCCount:", 350, 100, NiColorA(0.9f, 0.9f, 0.9f, 1.0f));
    m_spTexDependTime = AddDebugString(m_idDebuggingPage, "Texture DependTimeCount:", 350, 120, NiColorA(0.8f, 0.0f, 0.0f, 1.0f));
    return true;
}
