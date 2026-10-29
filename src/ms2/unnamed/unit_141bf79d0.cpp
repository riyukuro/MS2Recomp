// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_141bf79d0: the out-of-line glue of a
// family of small associative-container wrappers. Seven "find-or-insert" forwards (an 8-byte scratch is filled in
// place by the container's insert 0x141beef50..0x141bef0d0, then a per-type node accessor 0x141bf7dd0..0x141bf7ed0
// maps the returned node to its payload at +8), three bounds-checked element accessors, and ~45 trivial field
// accessors: `return *p` / `return p[8]` / `return p[0x10]` / `return p[0x20]` readers plus the void wrappers that
// forward to them (the wrapper's rax carries the reader's result through). All names invented from shape.
// MS2-UNIT: unit_141bf79d0
// MS2-RANGE: 0x141bf79d0-0x141bf81a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

typedef __int64 i64;
typedef unsigned __int64 u64;

// ---- the container / container-map callees (defined outside this unit) ----
void* FUN_141beef50(void* pMap, void* pKeyBuf, void* pKey);   // insert, returns the node
void* FUN_141beef90(void* pMap, void* pKeyBuf, void* pKey);
void* FUN_141beefd0(void* pMap, void* pKeyBuf, void* pKey);
void* FUN_141bef010(void* pMap, void* pKeyBuf, void* pKey);
void* FUN_141bef050(void* pMap, void* pKeyBuf, void* pKey);
void* FUN_141bef090(void* pMap, void* pKeyBuf, void* pKey);
void* FUN_141bef0d0(void* pMap, void* pKeyBuf, void* pKey);
void* FUN_1403b8210(void* pKey);                               // key normalisation

void* FUN_141c28870(void* pMap);                               // the map's backing array
void* FUN_141c288b0(void* pMap);
void* FUN_1413f4420(void* pMap);

// The nine per-type node accessors' callees (payload pointer derived from the node).
void* FUN_141c2e990(void* pNode);
void* FUN_141c2e9b0(void* pNode);
void* FUN_141c2e9d0(void* pNode);
void* FUN_141c2e9f0(void* pNode);
void* FUN_141c2ea10(void* pNode);
void* FUN_141c2ea30(void* pNode);
void* FUN_141c2ea50(void* pNode);
void* FUN_141c2ea70(void* pNode);
void* FUN_141c2ea90(void* pNode);

// ---- forward declarations of this unit's later helpers ----
void* FUN_141bf7dd0(void* pNode);
void* FUN_141bf7df0(void* pNode);
void* FUN_141bf7e10(void* pNode);
void* FUN_141bf7e90(void* pNode);
void* FUN_141bf7eb0(void* pNode);
void* FUN_141bf7ed0(void* pNode);
u64 FUN_141bf7f00(u64* p);
u64 FUN_141bf7f60(u64* p);
u64 FUN_141bf7f80(u64* p);
u64 FUN_141bf7fa0(u64* p);
u64 FUN_141bf7fc0(u64* p);
u64 FUN_141bf7fe0(u64* p);
u64 FUN_141bf8000(u64* p);
u64 FUN_141bf8020(u64* p);
u64 FUN_141bf8040(u64* p);
u64 FUN_141bf8060(u64* p);
u64 FUN_141bf8080(void* p);
u64 FUN_141bf80a0(void* p);
u64 FUN_141bf80c0(void* p);
u64 FUN_141bf80e0(void* p);
u64 FUN_141bf8100(void* p);
u64 FUN_141bf8120(void* p);
u64 FUN_141bf8140(void* p);
u64 FUN_141bf8160(void* p);
u64 FUN_141bf8180(void* p);

// ---------------------------------------------------------------------------
// find-or-insert forwards: insert fills a 16-byte pair<iterator, bool> scratch in place, the node accessor
// turns the node into its payload pointer, and the payload's first field is at +8.
// ---------------------------------------------------------------------------

// pair<iterator, bool> of the insert: the node at +0, the inserted flag at +8
struct Unk_InsertPair { void* m_node; bool m_bInserted; };

// @0x141bf79d0
u64 FUN_141bf79d0(void* pMap, void* pKey)
{
    Unk_InsertPair keybuf;
    return (u64)FUN_141bf7dd0(FUN_141beef50(pMap, &keybuf, pKey)) + 8;
}

// @0x141bf7a10
u64 FUN_141bf7a10(void* pMap, void* pKey)
{
    Unk_InsertPair keybuf;
    return (u64)FUN_141bf7df0(FUN_141beef90(pMap, &keybuf, pKey)) + 8;
}

// @0x141bf7a50
u64 FUN_141bf7a50(void* pMap, void* pKey)
{
    Unk_InsertPair keybuf;
    return (u64)FUN_141bf7e10(FUN_141beefd0(pMap, &keybuf, pKey)) + 8;
}

// @0x141bf7a90
u64 FUN_141bf7a90(void* pMap, void* pKey)
{
    Unk_InsertPair keybuf;
    return (u64)FUN_141bf7e90(FUN_141bef010(pMap, &keybuf, pKey)) + 8;
}

// @0x141bf7ad0
u64 FUN_141bf7ad0(void* pMap, void* pKey)
{
    Unk_InsertPair keybuf;
    return (u64)FUN_141bf7eb0(FUN_141bef050(pMap, &keybuf, pKey)) + 8;
}

// @0x141bf7b10
u64 FUN_141bf7b10(void* pMap, void* pKey)
{
    Unk_InsertPair keybuf;
    return (u64)FUN_141bf7ed0(FUN_141bef090(pMap, &keybuf, FUN_1403b8210(pKey))) + 8;
}

// @0x141bf7b50
u64 FUN_141bf7b50(void* pMap, void* pKey)
{
    Unk_InsertPair keybuf;
    return (u64)FUN_141bf7ed0(FUN_141bef0d0(pMap, &keybuf, pKey)) + 8;
}

// ---------------------------------------------------------------------------
// bounds-checked element accessors over the map's backing array
// ---------------------------------------------------------------------------

// @0x141bf7b90
u64 FUN_141bf7b90(void* pMap, u64 i)
{
    return *(u64*)FUN_141c28870(pMap) + i * 0x10;
}

// @0x141bf7bc0
u64 FUN_141bf7bc0(void* pMap, u64 i)
{
    return *(u64*)FUN_141c288b0(pMap) + i * 0x18;
}

// @0x141bf7bf0
u64* FUN_141bf7bf0(void* pMap, u64 i)
{
    return *(u64**)FUN_1413f4420(pMap) + i;
}

// ---------------------------------------------------------------------------
// first-field readers (`return *p`)
// ---------------------------------------------------------------------------

// @0x141bf7c20
u64 FUN_141bf7c20(u64* p) { return *p; }

// @0x141bf7c30
u64 FUN_141bf7c30(u64* p) { return *p; }

// @0x141bf7c40
u64 FUN_141bf7c40(u64* p) { return *p; }

// @0x141bf7c50
u64 FUN_141bf7c50(u64* p) { return *p; }

// @0x141bf7c60
u64 FUN_141bf7c60(u64* p) { return *p; }

// @0x141bf7c70
u64 FUN_141bf7c70(u64* p) { return *p; }

// @0x141bf7c80
u64 FUN_141bf7c80(u64* p) { return *p; }

// ---------------------------------------------------------------------------
// second-field readers (`return p[1]`)
// ---------------------------------------------------------------------------

// @0x141bf7c90
u64 FUN_141bf7c90(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7ca0
u64 FUN_141bf7ca0(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7cb0
u64 FUN_141bf7cb0(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7cc0
u64 FUN_141bf7cc0(void* p) { return *(u64*)((char*)p + 8); }

// The payload pointer of a node (or null), the node's payload sitting at +0x18.
// @0x141bf7cd0
u64 FUN_141bf7cd0(void* pNode)
{
    u64 p;
    if (pNode == 0)
        p = 0;
    else
        p = (u64)pNode + 0x18;
    return p;
}

// ---------------------------------------------------------------------------
// more first-field readers
// ---------------------------------------------------------------------------

// @0x141bf7d10
u64 FUN_141bf7d10(u64* p) { return *p; }

// @0x141bf7d20
u64 FUN_141bf7d20(u64* p) { return *p; }

// @0x141bf7d30
u64 FUN_141bf7d30(u64* p) { return *p; }

// @0x141bf7d40
u64 FUN_141bf7d40(u64* p) { return *p; }

// @0x141bf7d50
u64 FUN_141bf7d50(u64* p) { return *p; }

// ---------------------------------------------------------------------------
// more second-field readers
// ---------------------------------------------------------------------------

// @0x141bf7d60
u64 FUN_141bf7d60(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7d70
u64 FUN_141bf7d70(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7d80
u64 FUN_141bf7d80(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7d90
u64 FUN_141bf7d90(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7da0
u64 FUN_141bf7da0(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7db0
u64 FUN_141bf7db0(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7dc0
u64 FUN_141bf7dc0(void* p) { return *(u64*)((char*)p + 8); }

// ---------------------------------------------------------------------------
// per-type node -> payload forwards
// ---------------------------------------------------------------------------

// @0x141bf7dd0
void* FUN_141bf7dd0(void* pNode) { return FUN_141c2e990((void*)FUN_141bf8080(pNode)); }

// @0x141bf7df0
void* FUN_141bf7df0(void* pNode) { return FUN_141c2e9b0((void*)FUN_141bf80a0(pNode)); }

// @0x141bf7e10
void* FUN_141bf7e10(void* pNode) { return FUN_141c2e9d0((void*)FUN_141bf80c0(pNode)); }

// @0x141bf7e30
void* FUN_141bf7e30(void* pNode) { return FUN_141c2e9f0((void*)FUN_141bf80e0(pNode)); }

// @0x141bf7e50
void* FUN_141bf7e50(void* pNode) { return FUN_141c2ea10((void*)FUN_141bf8100(pNode)); }

// @0x141bf7e70
void* FUN_141bf7e70(void* pNode) { return FUN_141c2ea30((void*)FUN_141bf8120(pNode)); }

// @0x141bf7e90
void* FUN_141bf7e90(void* pNode) { return FUN_141c2ea50((void*)FUN_141bf8140(pNode)); }

// @0x141bf7eb0
void* FUN_141bf7eb0(void* pNode) { return FUN_141c2ea70((void*)FUN_141bf8160(pNode)); }

// @0x141bf7ed0
void* FUN_141bf7ed0(void* pNode) { return FUN_141c2ea90((void*)FUN_141bf8180(pNode)); }

// ---------------------------------------------------------------------------
// field-offset readers
// ---------------------------------------------------------------------------

// @0x141bf7ef0
u64 FUN_141bf7ef0(void* p) { return *(u64*)((char*)p + 8); }

// @0x141bf7f00
u64 FUN_141bf7f00(u64* p) { return *p + 0x10; }

// @0x141bf7f20
u64 FUN_141bf7f20(void* p) { return FUN_141bf7f00((u64*)p); }

// @0x141bf7f40
u64 FUN_141bf7f40(u64* p) { return *p + 0x20; }

// @0x141bf7f60
u64 FUN_141bf7f60(u64* p) { return *p + 0x20; }

// @0x141bf7f80
u64 FUN_141bf7f80(u64* p) { return *p + 0x20; }

// @0x141bf7fa0
u64 FUN_141bf7fa0(u64* p) { return *p + 0x20; }

// @0x141bf7fc0
u64 FUN_141bf7fc0(u64* p) { return *p + 0x20; }

// @0x141bf7fe0
u64 FUN_141bf7fe0(u64* p) { return *p + 0x20; }

// @0x141bf8000
u64 FUN_141bf8000(u64* p) { return *p + 0x20; }

// @0x141bf8020
u64 FUN_141bf8020(u64* p) { return *p + 0x20; }

// @0x141bf8040
u64 FUN_141bf8040(u64* p) { return *p + 0x20; }

// @0x141bf8060
u64 FUN_141bf8060(u64* p) { return *p + 0x20; }

// @0x141bf8080
u64 FUN_141bf8080(void* p) { return FUN_141bf7f60((u64*)p); }

// @0x141bf80a0
u64 FUN_141bf80a0(void* p) { return FUN_141bf7f80((u64*)p); }

// @0x141bf80c0
u64 FUN_141bf80c0(void* p) { return FUN_141bf7fa0((u64*)p); }

// @0x141bf80e0
u64 FUN_141bf80e0(void* p) { return FUN_141bf7fc0((u64*)p); }

// @0x141bf8100
u64 FUN_141bf8100(void* p) { return FUN_141bf7fe0((u64*)p); }

// @0x141bf8120
u64 FUN_141bf8120(void* p) { return FUN_141bf8000((u64*)p); }

// @0x141bf8140
u64 FUN_141bf8140(void* p) { return FUN_141bf8020((u64*)p); }

// @0x141bf8160
u64 FUN_141bf8160(void* p) { return FUN_141bf8040((u64*)p); }

// @0x141bf8180
u64 FUN_141bf8180(void* p) { return FUN_141bf8060((u64*)p); }
