// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2EntityLoaderService + std::_Tree helpers for
// efd::map<BlockIdentification, WorldLoadedInfoPtr> lookups.
// MS2-UNIT: ?\ms2entityloaderservice.cpp
// MS2-RANGE: 0x1414b3ee0-0x1414b4a90 .text$mn
// MS2-FUNCTIONAL: the tree/iterator helpers are written as opaque pointer-level free functions bound by FUN_ name
// (the engine's own instantiations for the same map type live elsewhere and would collide as templates).
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2entityloaderservice.h"
#include <new>

typedef unsigned long long u64;

// ---- out-of-unit callees ----
void* FUN_1413f9810();   void* FUN_1403ed2d0();   void FUN_141bd7d10(void* p);
void FUN_14016ad80(void* dst, void* src);
char FUN_1413e9750(void* a, void* b);   char FUN_1413eb2e0(void* a, void* b);
void FUN_14015b310(void* p, u64 sz);
void* FUN_141142f20(void* p);
void FUN_1411d6860(void* blockId);   void FUN_14114e860(void* list, void* it);   void* FUN_1411524b0(void* list, void* it);
char FUN_140a16b10(void* a, void* b);   void* FUN_140a16d80(void* it);   void FUN_140a17010(void* it);   void FUN_1411cb170(void* dst, void* v);

// ---- in-unit helpers (forward) ----
void* FUN_1414b4910(void* tree, void* out, void* key);
void* FUN_1414b48b0(void* tree, void* out);
bool FUN_1414b43d0(void* a, void* b);
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

struct ELSAccess : egf::EntityLoaderService
{
    static egf::BlockIdentification Req(const egf::EntityLoaderService* s, const egf::BlockIdentification& b)
    {
        return (static_cast<const ELSAccess*>(s)->*(&ELSAccess::GetRequestID))(b);
    }
};

// @0x1414b3f50
u64 FUN_1414b3f50(char* svc, void* key, unsigned* outA, int* outB)
{
    char it[8];
    char endIt[16];
    FUN_1414b4910(svc + 0x80, it, key);
    void* e = FUN_1414b48b0(svc + 0x80, endIt);
    if (!FUN_1414b43d0(it, e))
        return 0;
    char* node = (char*)FUN_1414b4410(it);
    char* info = (char*)FUN_1414b4430(node + 0x38);
    unsigned a = *(unsigned*)(info + 8);
    int b = (int)(long long)FUN_1414b4a70(info + 0x28);
    if (b == 0)
        return 0;
    *outA = a;
    *outB = b;
    return 1;
}

// @0x1414b4030
char FUN_1414b4030(egf::EntityLoaderService* svc, const egf::BlockIdentification* blk, void* outList)
{
    char it[8], it2[8], endIt[8], endIt2[8];
    char reqbuf[sizeof(egf::BlockIdentification)];
    egf::BlockIdentification& req = *new (reqbuf) egf::BlockIdentification(ELSAccess::Req(svc, *blk));
    FUN_1414b4910((char*)svc + 0x80, it, &req);
    void* e = FUN_1414b48b0((char*)svc + 0x80, endIt);
    if (!FUN_1414b43d0(it, e)) {
        FUN_1411d6860(&req);
        return 0;
    }
    char* node = (char*)FUN_1414b4410(it);
    char* info = (char*)FUN_1414b4430(node + 0x38);
    FUN_14114e860(info + 0x18, it2);
    for (;;) {
        void* e2 = FUN_1411524b0(info + 0x18, endIt2);
        if (!FUN_140a16b10(it2, e2))
            break;
        FUN_1411cb170(outList, FUN_140a16d80(it2));
        FUN_140a17010(it2);
    }
    FUN_1411d6860(&req);
    return 1;
}

// @0x1414b41a0
efd::AsyncResult MS2EntityLoaderService::OnTick()
{
    if (m_bLoading) {
        if (!*((char*)FUN_1413f9810() + 0x80)) {
            FUN_141bd7d10(FUN_1403ed2d0());
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
void* FUN_1414b4720(void* t, void* a, void* b);
void* FUN_1414b4840(void* t);
void* FUN_1414b4820(void* t);
void* FUN_1414b42c0(void* p);
void* FUN_1414b4310(void* a, void* b, void* c);
void* FUN_1414b42d0(void* a, void* b, void* c);
void* FUN_1414b4350(void* a, void* b, void* c);
void* FUN_1414b4460(void* it);
void* FUN_1414b4a50(void* p);
void* FUN_1414b49f0(void* t, void* out, void* key);
u64 FUN_1414b4480(char* a, char* b);
void* FUN_1414b44f0(void* self, void* a, void* b);

// @0x1414b4200
void* FUN_1414b4200(void* p) { return p; }

// @0x1414b4210  lower-bound walk (head node = *FUN_1414b4790(tree))
void** FUN_1414b4210(void* tree, void* key)
{
    void** head = (void**)*(void***)FUN_1414b4790(tree);
    void** best = head;
    void** cur = (void**)head[1];
    while (*((char*)cur + 0x19) == 0) {
        void* nk = FUN_1414b4860(tree, cur);
        if (!FUN_1414b4720(tree, nk, key)) {
            best = cur;
            cur = (void**)cur[0];
        } else {
            cur = (void**)cur[2];
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
void* FUN_1414b4350(void* a, void* b, void* c) { *(void**)a = b; FUN_14016ad80(a, c); return a; }
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

// BlockIdentification key: comparison id at +0x30.
struct Unk_1414b4480 {
    char m_0[0x30];
    unsigned m_30;
};
MS2_CHECK_OFFSET(Unk_1414b4480, m_30, 0x30);

// @0x1414b4480  BlockIdentification less-than
u64 FUN_1414b4480(char* a, char* b)
{
    if (!FUN_1413e9750(a, b))
        return FUN_1413eb2e0(a, b);
    return ((Unk_1414b4480*)a)->m_30 < ((Unk_1414b4480*)b)->m_30;
}
// @0x1414b44f0
void* FUN_1414b44f0(void* self, void* a, void* b) { return (void*)FUN_1414b4480((char*)a, (char*)b); }

// @0x1414b4520
// (scalar deleting destructor of MS2EntityLoaderService is compiler-generated)

// @0x1414b4620
char FUN_1414b4620(char* p) { return p[0x80]; }
// @0x1414b4720
void* FUN_1414b4720(void* tree, void* a, void* b) { return FUN_1414b44f0(FUN_1414b4840(tree), a, b); }

void* FUN_1414b47e0(void* p);  void* FUN_1414b4800(void* p);  void* FUN_1414b47f0(void* p);  void* FUN_1414b4810(void* p);
void* FUN_1414b47c0(void* p);  void* FUN_1414b47d0(void* p);  void* FUN_1414b4890(void* t, void* p);
// @0x1414b4760
void* FUN_1414b4760(void* t) { return FUN_1414b4800(FUN_1414b47e0(t)); }
// @0x1414b4790
void* FUN_1414b4790(void* t) { return FUN_1414b4810(FUN_1414b47f0(t)); }
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
void* FUN_1414b4820(void* p) { return FUN_1414b47c0(p); }
// @0x1414b4840
void* FUN_1414b4840(void* p) { return FUN_1414b47d0(p); }
// @0x1414b4860
void* FUN_1414b4860(void* t, void* n) { return FUN_1414b4890(t, (char*)n + 0x20); }
// @0x1414b4890
void* FUN_1414b4890(void* t, void* p) { return FUN_1414b4200(p); }

// @0x1414b48b0
void* FUN_1414b48b0(void* tree, void* out)
{
    void** head = (void**)FUN_1414b4760(tree);
    void* r = FUN_1414b42c0(head);
    FUN_1414b4310(out, *head, r);
    return out;
}

// @0x1414b4910
void* FUN_1414b4910(void* tree, void* out, void* key)
{
    char lb[8], endIt[8], endIt2[24];
    void* res;
    void* fb[2];
    FUN_1414b49f0(tree, lb, key);
    void* e = FUN_1414b48b0(tree, endIt);
    if (!FUN_1414b4390((long long*)lb, (long long*)e)) {
        void* nk = FUN_1414b4860(tree, *(void**)lb);
        FUN_1414b4820(tree);
        if (!FUN_1414b44f0(0, key, nk)) {
            res = fb;
            goto done;
        }
    }
    res = FUN_1414b48b0(tree, endIt2);
done:
    *(void**)out = *(void**)res;
    return out;
}

// @0x1414b49f0
void* FUN_1414b49f0(void* tree, void* out, void* key)
{
    void* h = FUN_1414b4760(tree);
    h = FUN_1414b42c0(h);
    void* lb = FUN_1414b4210(tree, key);
    FUN_1414b4310(out, lb, h);
    return out;
}

// @0x1414b4a50
void* FUN_1414b4a50(void* p) { return FUN_1414b42b0(p); }
// @0x1414b4a70
void* FUN_1414b4a70(void* p) { return *(void**)((char*)FUN_141142f20(p) + 8); }
