// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\ms2meshcullingprocess.cpp
// MS2-RANGE: 0x1400d3ca0-0x1400d3cd0 .text$di
// MS2-RANGE: 0x140d96010-0x140d966b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2meshcullingprocess.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2meshcullingprocess.h"
#include "hook/ms2hook.h"

// Unrecovered callees (real types unknown).
const NiFrustum* FUN_1409a8de0(const NiCamera* cam);
void FUN_140980460(void* obj);          // add-reference
struct Unk_MCPPtr { Unk_MCPPtr(MS2MeshCullingProcess* p); ~Unk_MCPPtr(); MS2MeshCullingProcess* m_p; };
void* FUN_140d96650(void* list);
void** FUN_140d96660(void* list, void** it);
unsigned int FUN_140d96630(NiAVObject* obj);
struct Unk_AVCull { void Cull(NiCullingProcess* p); };    // NiAVObject::Cull (0x141d14dd0)

#ifdef __clang__
// MS2: clang folds the RTTI initializer into a constant ADDR64 against an exe global, which the DLL post-link check
// rejects; reading a mutable zero forces run-time initialization (MSVC build unaffected).
static volatile unsigned __int64 s_msZero;
static const NiRTTI* msBaseRTTI() { return (const NiRTTI*)((unsigned __int64)&NiCullingProcess::ms_RTTI + s_msZero); }
const NiRTTI MS2MeshCullingProcess::ms_RTTI("MS2MeshCullingProcess", msBaseRTTI());
#else
// @0x1400d3ca0
const NiRTTI MS2MeshCullingProcess::ms_RTTI("MS2MeshCullingProcess", &NiCullingProcess::ms_RTTI);
#endif

// @0x140d96010
MS2MeshCullingProcess::MS2MeshCullingProcess(NiVisibleArray* pkVisibleSet, NiSPWorkflowManager* pkWorkflowManager)
    : NiCullingProcess(pkVisibleSet, pkWorkflowManager)
{
    m_ownsWorkflow = false;
    if (pkWorkflowManager == 0) {
        m_ownsWorkflow = true;
        m_pkWorkflowManager = new (efd::MemHint(efd::MemHint::NONE)) NiSPWorkflowManager(0x40, NiStreamProcessor::MEDIUM, 3);
    }
}

// @0x140d96100
MS2MeshCullingProcess::~MS2MeshCullingProcess()
{
    if (m_ownsWorkflow) {
        delete m_pkWorkflowManager;
        m_pkWorkflowManager = 0;
    }
}

// @0x140d96190
NiSPWorkflowManager* FUN_140d96190(MS2MeshCullingProcess* p)
{
    return p->m_pkWorkflowManager;
}

// Not in the hook DLL: none of this class is hooked, so DLL-built objects would carry the DLL vtable and ms_RTTI;
// MS2::RegisterServices (hooked) stores the culling factory, which must hand out exe objects (fx6).
#ifndef MS2_HOOK_DLL
// @0x140d961b0
MS2MeshCullingProcess* FUN_140d961b0()
{
    return new (efd::MemHint(efd::MemHint::NONE)) MS2MeshCullingProcess(0, 0);
}

// @0x140d96230
Unk_MCPPtr FUN_140d96230(NiVisibleArray* a, NiSPWorkflowManager* b)
{
    return Unk_MCPPtr(new (efd::MemHint(efd::MemHint::NONE)) MS2MeshCullingProcess(a, b));
}
#endif

// @0x140d962e0
MS2MeshCullingProcess::MS2MeshCullingProcess(NiVisibleArray* pkVisibleSet, NiSPWorkflowManager* pkWorkflowManager, bool bUseVirtualAppend)
    : NiCullingProcess(pkVisibleSet, pkWorkflowManager, bUseVirtualAppend)
{
    m_ownsWorkflow = false;
    if (pkWorkflowManager == 0) {
        m_ownsWorkflow = true;
        m_pkWorkflowManager = new (efd::MemHint(efd::MemHint::NONE)) NiSPWorkflowManager(0x40, NiStreamProcessor::MEDIUM, 3);
    }
}

// @0x140d963d0
void MS2MeshCullingProcess::Process(const NiCamera* pkCamera, NiAVObject* pkScene, NiVisibleArray* pkVisibleSet)
{
    NiCullingProcess::Process(pkCamera, pkScene, pkVisibleSet);
}

// @0x140d96410
void MS2MeshCullingProcess::Process(const NiCamera* pkCamera, NiTPointerList<NiAVObject*>* pkSceneList, NiVisibleArray* pkVisibleSet)
{
    if (pkCamera == 0 || pkSceneList == 0)
        return;
    m_pkCamera = pkCamera;
    SetFrustum(*FUN_1409a8de0(m_pkCamera));
    NiVisibleArray* pkSaved = 0;
    if (pkVisibleSet != 0) {
        pkSaved = m_pkVisibleSet;
        m_pkVisibleSet = pkVisibleSet;
    }
    if (m_pkVisibleSet != 0) {
        void* it = FUN_140d96650(pkSceneList);
        while (it != 0) {
            NiAVObject* obj = *(NiAVObject**)FUN_140d96660(pkSceneList, &it);
            if (obj != 0 && (FUN_140d96630(obj) & 2) == 0)
                ((Unk_AVCull*)obj)->Cull(this);
        }
    }
    if (pkVisibleSet != 0)
        m_pkVisibleSet = pkSaved;
    m_pkCamera = 0;
    m_pkLODCamera = 0;
}

// @0x140d96540
void MS2MeshCullingProcess::PreProcess()
{
}

// @0x140d96550
void MS2MeshCullingProcess::PostProcess()
{
    m_pkWorkflowManager->FlushTaskGroup(0x8030, 0x8000);
}

// @0x140d96580
Unk_MCPPtr::Unk_MCPPtr(MS2MeshCullingProcess* p)
{
    m_p = p;
    if (m_p != 0)
        FUN_140980460(m_p);
}

// @0x140d96630
unsigned int FUN_140d96630(NiAVObject* obj)
{
    return *(unsigned int*)((char*)obj + 0xe0);
}

// @0x140d96650
void* FUN_140d96650(void* list)
{
    return *(void**)((char*)list + 8);
}

// @0x140d96660
void** FUN_140d96660(void* list, void** it)
{
    void** r = (void**)((char*)*it + 0x10);
    *it = *(void**)*it;
    return r;
}

// @0x140d966a0
const NiRTTI* MS2MeshCullingProcess::GetRTTI() const
{
    return &ms_RTTI;
}
