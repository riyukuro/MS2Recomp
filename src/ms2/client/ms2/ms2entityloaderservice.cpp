// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2EntityLoaderService + std::_Tree helpers for
// efd::map<BlockIdentification, WorldLoadedInfoPtr> lookups.
// MS2-UNIT: ?\ms2entityloaderservice.cpp
// MS2-RANGE: 0x1414b3ee0-0x1414b4a90 .text$mn
// MS2-FUNCTIONAL: the BlockIdentification key compare (0x1414b4480) is the engine's inline operator<; the exe loads
// this between computing and passing &other.m_blockAsset to AssetID ==/<, ours passes it first (arg-move order only).
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2entityloaderservice.h"

typedef unsigned long long u64;

// ---- out-of-unit callees ----
void* FUN_1413f9810();class WorldService   // C3: member view for the former free stand-ins
{
public:
    void FUN_141bd7d10();
    static class WorldService* GetInstance();
};
void FUN_14015b310(void* p, u64 sz);
void FUN_14114e860(void* list, void* it);   void* FUN_1411524b0(void* list, void* it);
bool FUN_140a16b10(void* a, void* b);   void* FUN_140a16d80(void* it);   void FUN_140a17010(void* it);   void FUN_1411cb170(void* dst, void* v);

// std::_Tree node: left/parent/right links, colour, nil flag; the key starts at +0x20.
struct Unk_ELSNode {
    Unk_ELSNode* m_left;
    Unk_ELSNode* m_parent;
    Unk_ELSNode* m_right;
    char m_color;
    char m_isnil;
};
MS2_CHECK_OFFSET(Unk_ELSNode, m_isnil, 0x19);
struct Unk_ELSIt { Unk_ELSNode* m_ptr; };

// ---- in-unit helpers (forward) ----
void* FUN_1414b4910(void* tree, void* out, void* key);
void* FUN_1414b48b0(void* tree, void* out) noexcept;
bool FUN_1414b43d0(void* a, void* b);
bool FUN_1414b4620(char* p);
void* FUN_1414b4410(void* it);
void* FUN_1414b4430(void* p);
void* FUN_1414b4a70(void* p);

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1414b3ee0
MS2EntityLoaderService::MS2EntityLoaderService()
{
    m_bLoading = false;
}
#endif

// @0x1414b3f20
MS2EntityLoaderService::~MS2EntityLoaderService()
{
}

// Access view: FUN_1414b4030 calls the protected EntityLoaderService::GetRequestID, so it is a static member here.
struct ELSAccess : egf::EntityLoaderService
{
    static bool FUN_1414b4030(egf::EntityLoaderService* svc, const egf::BlockIdentification* blk, void* outList);
};

// @0x1414b3f50
bool FUN_1414b3f50(MS2EntityLoaderService* svc, const egf::BlockIdentification& key, unsigned* outA, int* outB)
{
    Unk_ELSIt it;
    FUN_1414b4910((char*)svc + 0x80, &it, (void*)&key);
    Unk_ELSIt e;
    if (FUN_1414b43d0(&it, FUN_1414b48b0((char*)svc + 0x80, &e))) {
        char* info = (char*)FUN_1414b4430((char*)FUN_1414b4410(&it) + 0x38);
        unsigned a = *(unsigned*)(info + 8);
        unsigned b = (unsigned)(u64)FUN_1414b4a70(info + 0x28);
        if (b > 0) {
            *outA = a;
            *outB = b;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

// @0x1414b4030
bool ELSAccess::FUN_1414b4030(egf::EntityLoaderService* svc, const egf::BlockIdentification* blk, void* outList)
{
    egf::BlockIdentification req = static_cast<ELSAccess*>(svc)->GetRequestID(*blk);
    Unk_ELSIt it;
    FUN_1414b4910((char*)svc + 0x80, &it, &req);
    Unk_ELSIt e;
    if (FUN_1414b43d0(&it, FUN_1414b48b0((char*)svc + 0x80, &e))) {
        char* info = (char*)FUN_1414b4430((char*)FUN_1414b4410(&it) + 0x38);
        Unk_ELSIt it2, e2;
        for (FUN_14114e860(info + 0x18, &it2); FUN_140a16b10(&it2, FUN_1411524b0(info + 0x18, &e2)); FUN_140a17010(&it2))
            FUN_1411cb170(outList, FUN_140a16d80(&it2));
        return true;
    }
    return false;
}

// @0x1414b41a0
efd::AsyncResult MS2EntityLoaderService::OnTick()
{
    if (m_bLoading) {
        if (!FUN_1414b4620((char*)FUN_1413f9810())) {
            ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd7d10();
            m_bLoading = false;
        }
    }
    return egf::EntityLoaderService::OnTick();
}


// ---- tree helpers (std::_Tree<map<BlockIdentification,...>> internals; every one returns what it forwards) ----
void* FUN_1414b4200(void* p);
void* FUN_1414b4790(void* t);
void* FUN_1414b4760(void* t);
void* FUN_1414b4860(void* t, void* n);
bool FUN_1414b4720(void* t, void* a, void* b);
void* FUN_1414b4840(void* t);
void* FUN_1414b4820(void* t);
void* FUN_1414b42c0(void* p);
void* FUN_1414b4310(void* a, void* b, void* c);
void* FUN_1414b42d0(void* a, void* b, void* c);
void* FUN_1414b4350(void* a, void* b, void* c);
void* FUN_1414b4460(void* it);
void* FUN_1414b4a50(void* p);
void* FUN_1414b49f0(void* t, void* out, void* key);
bool FUN_1414b44f0(void* self, void* a, void* b);

// @0x1414b4200
void* FUN_1414b4200(void* p) { return p; }

// @0x1414b4210  lower-bound walk (head node = *FUN_1414b4790(tree))
Unk_ELSNode* FUN_1414b4210(void* tree, void* key)
{
    Unk_ELSNode* best = *(Unk_ELSNode**)FUN_1414b4790(tree);
    Unk_ELSNode* cur = best->m_parent;
    while (!cur->m_isnil) {
        if (FUN_1414b4720(tree, FUN_1414b4860(tree, cur), key)) {
            cur = cur->m_right;
        } else {
            best = cur;
            cur = cur->m_left;
        }
    }
    return best;
}

// @0x1414b42b0
void* FUN_1414b42b0(void* p) { return p; }
// @0x1414b42c0
void* FUN_1414b42c0(void* p) { return p; }
// @0x1414b42d0
void* FUN_1414b42d0(void* a, void* b, void* c) { FUN_1414b4350(a, b, c); return a; }
// @0x1414b4310
void* FUN_1414b4310(void* a, void* b, void* c) { FUN_1414b42d0(a, b, c); return a; }
// @0x1414b4350
void* FUN_1414b4350(void* a, void* b, void* c) { *(void**)a = b; ((std::_Iterator_base0*)(void*)(a))->_Adopt((void const*)(c)); return a; }
// @0x1414b4390
bool FUN_1414b4390(long long* a, long long* b) { return *a == *b; }
// @0x1414b43d0
bool FUN_1414b43d0(void* a, void* b) { return !FUN_1414b4390((long long*)a, (long long*)b); }
// @0x1414b4410
void* FUN_1414b4410(void* it) { return FUN_1414b4a50(FUN_1414b4460(it)); }
// @0x1414b4430
void* FUN_1414b4430(void* p) { return *(void**)p; }
// @0x1414b4440
char* FUN_1414b4440(long long* p) { return (char*)*p + 0x20; }
// @0x1414b4460
void* FUN_1414b4460(void* it) { return FUN_1414b4440((long long*)it); }

// @0x1414b4480  egf::BlockIdentification::operator< (BlockIdentification.inl), emitted as this map's key compare
struct Unk_ELSKey : egf::BlockIdentification {
    bool FUN_1414b4480(const egf::BlockIdentification& other) const;
};
bool Unk_ELSKey::FUN_1414b4480(const egf::BlockIdentification& other) const
{
    if (m_blockAsset == other.m_blockAsset)
        return m_instance < other.m_instance;
    return m_blockAsset < other.m_blockAsset;
}
// @0x1414b44f0
bool FUN_1414b44f0(void* self, void* a, void* b) { return ((Unk_ELSKey*)a)->FUN_1414b4480(*(egf::BlockIdentification*)b); }

// @0x1414b4520
// (scalar deleting destructor of MS2EntityLoaderService is compiler-generated)

// View of the object FUN_1413f9810 returns: a busy flag at +0x80.
struct Unk_1414b4620 {
    char m_0[0x80];
    bool m_80;
};
// @0x1414b4620
bool FUN_1414b4620(char* p) { return ((Unk_1414b4620*)p)->m_80; }
// @0x1414b4720
bool FUN_1414b4720(void* tree, void* a, void* b) { return FUN_1414b44f0(FUN_1414b4840(tree), a, b); }

void* FUN_1414b47e0(void* p);  void* FUN_1414b4800(void* p);  void* FUN_1414b47f0(void* p);  void* FUN_1414b4810(void* p);
void* FUN_1414b47c0(void* p);  void* FUN_1414b47d0(void* p);  void* FUN_1414b4890(void* t, void* p);
// The tree's first member (offset 0) is what the accessor chain is handed.
struct Unk_ELSTree { void* m_0; };
// @0x1414b4760
void* FUN_1414b4760(void* t) { return FUN_1414b4800(FUN_1414b47e0(&((Unk_ELSTree*)t)->m_0)); }
// @0x1414b4790
void* FUN_1414b4790(void* t) { return FUN_1414b4810(FUN_1414b47f0(&((Unk_ELSTree*)t)->m_0)); }
// @0x1414b47c0
void* FUN_1414b47c0(void* p) { return p; }
// @0x1414b47d0
void* FUN_1414b47d0(void* p) { return p; }
// @0x1414b47e0
void* FUN_1414b47e0(void* p) { return p; }
// @0x1414b47f0
void* FUN_1414b47f0(void* p) { return p; }
// @0x1414b4800
void* FUN_1414b4800(void* p) { return p; }
// @0x1414b4810
void* FUN_1414b4810(void* p) { return p; }
// @0x1414b4820
void* FUN_1414b4820(void* p) { return FUN_1414b47c0(&((Unk_ELSTree*)p)->m_0); }
// @0x1414b4840
void* FUN_1414b4840(void* p) { return FUN_1414b47d0(&((Unk_ELSTree*)p)->m_0); }
// @0x1414b4860
void* FUN_1414b4860(void* t, void* n) { return FUN_1414b4890(t, (char*)n + 0x20); }
// @0x1414b4890
void* FUN_1414b4890(void* t, void* p) { return FUN_1414b4200(p); }

// @0x1414b48b0
void* FUN_1414b48b0(void* tree, void* out) noexcept
{
    void** head = (void**)FUN_1414b4760(tree);
    FUN_1414b4310(out, *head, FUN_1414b42c0(head));
    return out;
}

// @0x1414b4910
void* FUN_1414b4910(void* tree, void* out, void* key)
{
    Unk_ELSIt lb;
    FUN_1414b49f0(tree, &lb, key);
    Unk_ELSIt e, e2, copy;
    Unk_ELSIt* r = (FUN_1414b4390((long long*)&lb, (long long*)FUN_1414b48b0(tree, &e))
                    || FUN_1414b44f0(FUN_1414b4820(tree), key, FUN_1414b4860(tree, lb.m_ptr)))
                       ? (Unk_ELSIt*)FUN_1414b48b0(tree, &e2)
                       : &(copy = lb);
    *(Unk_ELSIt*)out = *r;
    return out;
}

// @0x1414b49f0
void* FUN_1414b49f0(void* tree, void* out, void* key)
{
    FUN_1414b4310(out, FUN_1414b4210(tree, key), FUN_1414b42c0(FUN_1414b4760(tree)));
    return out;
}

// @0x1414b4a50
void* FUN_1414b4a50(void* p) { return FUN_1414b42b0(p); }
// @0x1414b4a70
void* FUN_1414b4a70(void* p) { return *(void**)((char*)((void*)&((std::_Tree_comp_alloc<std::_Tset_traits<egf::EntityID, std::less<egf::EntityID>, efd::CustomAllocator<egf::EntityID>, 0>>*)(void*)(p))->_Get_data()) + 8); }
