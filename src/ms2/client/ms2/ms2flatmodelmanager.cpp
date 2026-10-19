// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2FlatModelManager + helpers walking FlatModelManager's
// flat-model-by-id map.
// MS2-UNIT: ?\ms2flatmodelmanager.cpp
// MS2-RANGE: 0x140d86560-0x140d878b0 .text$mn
// MS2-FUNCTIONAL: std::_Tree iterator helpers for the id->model map are opaque pointer-level free functions bound by
// FUN_ name (the engine's own instantiations of the same map type live elsewhere); the removal list is a real CAtlList.
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2flatmodelmanager.h"
#include <atlcoll.h>
#include <egf/FlatModelFactory.h>
#include <egf/Scheduler.h>
#include <egf/ISchedulerScripting.h>
#include <efd/AssetFactoryManager.h>
#include <efd/utf8string.h>

typedef unsigned long long u64;

// ---- out-of-unit callees ----
void* FUN_14214a770(void* sched, int behaviorType);
void* FUN_14208a860(u64 size, unsigned hint);
unsigned* FUN_140876480(void* out, int v);
void* FUN_140998330(void* sm);
void FUN_1409989e0(void* utf8, const char* s);
void FUN_1408a8900(void* utf8);
void FUN_14016ad80(void* dst, void* src);
void* FUN_1401cd130(void* a, void* b);
void FUN_140d852c0(void* lock);   void FUN_140d86210(void* lock);
void FUN_140159b70(long hr);
void FUN_14015b310(void* p, u64 sz);

// ---- in-unit helper prototypes ----
void* FUN_140d86bb0(void* sm);   void* FUN_140d86bf0(void* sm);   void* FUN_140d86b10(void* p);
void* FUN_140d87890(void* tree);
void* FUN_140d877a0(void* tree, void* out);   void* FUN_140d87810(void* tree, void* out);
bool FUN_140d86e40(void* a, void* b);   bool FUN_140d86e00(long long* a, long long* b);
void* FUN_140d86ea0(void* it);   void* FUN_140d86e80(void* p);   unsigned FUN_140d86e90(unsigned* p);
void* FUN_140d86f20(void* it);   void* FUN_140d86f00(void* it);   long long* FUN_140d86f40(long long* it);
void* FUN_140d87770(void* p);
unsigned FUN_140d873f0(void* model);
void* FUN_140d876c0(void* t);   void* FUN_140d876f0(void* t);
void* FUN_140d87720(void* p);   void* FUN_140d87730(void* p);   void* FUN_140d87740(void* p);   void* FUN_140d87750(void* p);
void* FUN_140d86c30(void* p);   void* FUN_140d86c40(void* p);   u64 FUN_140d87760(u64* p);
void* FUN_140d86cf0(void* a, void* b, void* c);   void* FUN_140d86cb0(void* a, void* b, void* c);   void* FUN_140d86d30(void* a, void* b, void* c);
void* FUN_140d86ec0(long long* p);   void* FUN_140d86ee0(void* p);   void* FUN_140d87870(void* p);

typedef CAtlList<const egf::FlatModel*> FlatModelList;

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x140d86560
MS2FlatModelManager::MS2FlatModelManager()
{
}
#endif

// @0x140d865a0
MS2FlatModelManager::~MS2FlatModelManager()
{
}

// @0x140d865d0
efd::AsyncResult MS2FlatModelManager::OnInit()
{
    egf::Scheduler* sched = (egf::Scheduler*)FUN_140d86bf0(m_pServiceManager);
    if (!m_asset_lookup_in_progress) {
        efd::AssetFactoryManager* afm = (efd::AssetFactoryManager*)FUN_140d86bb0(m_pServiceManager);
        if (afm) {
            egf::IScriptFactory* scriptFactory = 0;
            if (sched) {
                egf::ISchedulerScripting* rt = sched->GetScriptingRuntime(6u);
                if (rt) {
                    efd::Category cat = rt->GetAssetLoadCategory();
                    scriptFactory = (egf::IScriptFactory*)FUN_140d86b10(afm->GetAssetFactory(cat));
                }
            }
            char hintBuf[8];
            unsigned hint = *FUN_140876480(hintBuf, 0);
            void* mem = FUN_14208a860(0x70, hint);
            m_pFlatModelFactory = mem
                ? new (mem) egf::FlatModelFactory((efd::AssetFactoryManager*)FUN_140d86bb0(m_pServiceManager), this, scriptFactory)
                : 0;
            efd::Category cb = m_callback;
            afm->RegisterAssetFactory(cb, (efd::IAssetFactory*)m_pFlatModelFactory);
        }
    }
    void** locator = (void**)FUN_140998330(m_pServiceManager);
    if (!locator) {
        m_asset_lookup_complete = true;
    } else {
        if (!m_asset_lookup_in_progress) {
            if (sched)
                sched->PauseScheduler(true);
            char urn[32];
            FUN_1409989e0(urn, "urn:emergent-flat-model");
            efd::Category cb = m_callback;
            char ok = ((char(*)(void*, void*, efd::Category, int))((void**)*locator)[0x88 / 8])(locator, urn, cb, 1);
            FUN_1408a8900(urn);
            if (!ok)
                m_asset_lookup_complete = true;
            else
                m_asset_lookup_in_progress = true;
        }
        if (!m_asset_lookup_complete)
            return efd::AsyncResult_Pending;
    }
    return efd::AsyncResult_Complete;
}

// @0x140d868f0
unsigned FUN_140d868f0(char* p)
{
    FUN_140d852c0(p + 0x108);
    unsigned r = (unsigned)(u64)FUN_140d87890(p + 0x48);
    FUN_140d86210(p + 0x108);
    return r;
}

// @0x140d86950  remove every non-built-in model whose refcount < 3
void FUN_140d86950(egf::FlatModelManager* mgr)
{
    char* p = (char*)mgr;
    FlatModelList list(10);
    char it[8], endIt[16];
    FUN_140d852c0(p + 0x108);
    FUN_140d877a0(p + 0x48, it);
    for (;;) {
        void* e = FUN_140d87810(p + 0x48, endIt);
        if (!FUN_140d86e40(it, e))
            break;
        char* node = (char*)FUN_140d86ea0(it);
        char* model = (char*)FUN_140d86e80(node + 8);
        if (FUN_140d873f0(model) < 3 && *(model + 200) == 0)
            list.AddTail((const egf::FlatModel*)model);
        FUN_140d86f20(it);
    }
    if (!list.IsEmpty()) {
        POSITION pos = list.GetHeadPosition();
        while (pos) {
            const egf::FlatModel* m = list.GetAt(pos);
            mgr->RemoveModel((egf::FlatModel*)m);
            list.GetNext(pos);
        }
    }
    FUN_140d86210(p + 0x108);
}

// ---- GetSystemServiceAs<T> style lookups: service = sm->vfunc14(classId), then TypeCast(classId) ----
typedef void* (*SvcFind)(void*, unsigned);
typedef char (*SvcCast)(void*, unsigned, void**);

// @0x140d86ac0
void* FUN_140d86ac0(void** p)
{
    void* out = 0;
    if (!p || !((SvcCast)((void**)*p)[5])(p, 0x7000022, &out))
        out = 0;
    return out;
}
// @0x140d86b10
void* FUN_140d86b10(void* pv)
{
    void** p = (void**)pv;
    void* out = 0;
    if (!p || !((SvcCast)((void**)*p)[5])(p, 0xe0010024, &out))
        out = 0;
    return out;
}
// @0x140d86b60
void* FUN_140d86b60(void** p)
{
    void* out = 0;
    if (!p || !((SvcCast)((void**)*p)[5])(p, 0x7001002, &out))
        out = 0;
    return out;
}
// @0x140d86bb0
void* FUN_140d86bb0(void* sm)
{
    void* s = ((SvcFind)((void**)*(void***)sm)[14])(sm, 0x7000022);
    return FUN_140d86ac0((void**)s);
}
// @0x140d86bf0
void* FUN_140d86bf0(void* sm)
{
    void* s = ((SvcFind)((void**)*(void***)sm)[14])(sm, 0x7001002);
    return FUN_140d86b60((void**)s);
}

// @0x140d86c30
void* FUN_140d86c30(void* p) { return p; }
// @0x140d86c40
void* FUN_140d86c40(void* p) { return p; }

// @0x140d86cb0
void* FUN_140d86cb0(void* a, void* b, void* c) { FUN_140d86d30(a, b, c); return a; }
// @0x140d86cf0
void* FUN_140d86cf0(void* a, void* b, void* c) { FUN_140d86cb0(a, b, c); return a; }
// @0x140d86d30
void* FUN_140d86d30(void* a, void* b, void* c) { *(void**)a = b; FUN_14016ad80(a, c); return a; }

// @0x140d86e00
bool FUN_140d86e00(long long* a, long long* b) { return *a == *b; }
// @0x140d86e40
bool FUN_140d86e40(void* a, void* b) { return !FUN_140d86e00((long long*)a, (long long*)b); }
// @0x140d86da0
void* FUN_140d86da0(void* a, void* b) { FUN_1401cd130(a, b); return a; }
// @0x140d86df0
void FUN_140d86df0() {}
// @0x140d873f0
unsigned FUN_140d873f0(void* model) { return FUN_140d86e90((unsigned*)((char*)model + 8)); }
// @0x140d86e80
void* FUN_140d86e80(void* p) { return *(void**)p; }
// @0x140d86e90
unsigned FUN_140d86e90(unsigned* p) { return *p; }
// @0x140d86ea0
void* FUN_140d86ea0(void* it) { return FUN_140d87870(FUN_140d86ee0(it)); }
// @0x140d86ec0
void* FUN_140d86ec0(long long* p) { return (char*)*p + 0x20; }
// @0x140d86ee0
void* FUN_140d86ee0(void* it) { return FUN_140d86ec0((long long*)it); }
// @0x140d86f00
void* FUN_140d86f00(void* it) { FUN_140d86f40((long long*)it); return it; }
// @0x140d86f20
void* FUN_140d86f20(void* it) { FUN_140d86f00(it); return it; }

// @0x140d86f40  std::_Tree_const_iterator::operator++
long long* FUN_140d86f40(long long* it)
{
    long long* node = (long long*)*it;
    if (*((char*)((long long*)node)[2] + 0x19) == 0) {
        *it = (long long)FUN_140d87770((void*)node[2]);
    } else {
        long long parent;
        while (parent = ((long long*)*it)[1], *((char*)parent + 0x19) == 0 && *it == ((long long*)parent)[2])
            *it = parent;
        *it = parent;
    }
    return it;
}

// @0x140d86fd0  scalar deleting destructor of the (empty) list-node type
void* FUN_140d86fd0(void* p, unsigned flags)
{
    if (flags & 1)
        operator delete(p);
    return p;
}

// @0x140d87360 -- 0x140d87480 CAtlList<const FlatModel*> instances are compiler-generated from FlatModelList above.

// @0x140d87720
void* FUN_140d87720(void* p) { return p; }
// @0x140d87730
void* FUN_140d87730(void* p) { return p; }
// @0x140d87740
void* FUN_140d87740(void* p) { return p; }
// @0x140d87750
void* FUN_140d87750(void* p) { return p; }
// @0x140d876c0
void* FUN_140d876c0(void* t) { return FUN_140d87740(FUN_140d87720(t)); }
// @0x140d876f0
void* FUN_140d876f0(void* t) { return FUN_140d87750(FUN_140d87730(t)); }
// @0x140d87760
u64 FUN_140d87760(u64* p) { return *p; }

// @0x140d87770  leftmost node of a subtree
void* FUN_140d87770(void* p)
{
    long long* n = (long long*)p;
    for (; *((char*)*n + 0x19) == 0; n = (long long*)*n) {
    }
    return n;
}

// @0x140d877a0  begin()
void* FUN_140d877a0(void* tree, void* out)
{
    void* h = FUN_140d876c0(tree);
    void* r = FUN_140d86c40(h);
    u64* hp = (u64*)FUN_140d87760((u64*)h);
    FUN_140d86cf0(out, (void*)*hp, r);
    return out;
}

// @0x140d87810  end()
void* FUN_140d87810(void* tree, void* out)
{
    u64* hp = (u64*)FUN_140d876c0(tree);
    void* r = FUN_140d86c40(hp);
    FUN_140d86cf0(out, (void*)*hp, r);
    return out;
}

// @0x140d87870
void* FUN_140d87870(void* p) { return FUN_140d86c30(p); }
// @0x140d87890  tree size
void* FUN_140d87890(void* tree) { return *(void**)((char*)FUN_140d876f0(tree) + 8); }
