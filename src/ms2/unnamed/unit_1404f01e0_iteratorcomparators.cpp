// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_1404f01e0: eleven STL node-pointer
// iterator equality comparators (the iterator stand-in's first 8 bytes are the node pointer), ten of their negations,
// and two ATL::CAtlArray<T>::operator[] bounds-checked accessors over 16-byte elements. All names invented from use.
// MS2-UNIT: unit_1404f01e0
// MS2-RANGE: 0x1404f01e0-0x1404f07a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

typedef __int64 i64;
typedef unsigned __int64 u64;

// The iterator stand-in: only the node pointer (first 8 bytes) is compared.
struct Unk_It { void* p; };

// --- iterator equality (a->p == b->p) ---
// @0x1404f01e0
bool FUN_1404f01e0(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f0220
bool FUN_1404f0220(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f0260
bool FUN_1404f0260(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f02a0
bool FUN_1404f02a0(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f02e0
bool FUN_1404f02e0(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f0320
bool FUN_1404f0320(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f0360
bool FUN_1404f0360(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f03a0
bool FUN_1404f03a0(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f03e0
bool FUN_1404f03e0(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f0420
bool FUN_1404f0420(Unk_It* a, Unk_It* b) { return a->p == b->p; }
// @0x1404f0460
bool FUN_1404f0460(Unk_It* a, Unk_It* b) { return a->p == b->p; }

// --- their negations ---
// @0x1404f04a0
bool FUN_1404f04a0(Unk_It* a, Unk_It* b) { return !FUN_1404f01e0(a, b); }
// @0x1404f04e0
bool FUN_1404f04e0(Unk_It* a, Unk_It* b) { return !FUN_1404f0220(a, b); }
// @0x1404f0520
bool FUN_1404f0520(Unk_It* a, Unk_It* b) { return !FUN_1404f0260(a, b); }
// @0x1404f0560
bool FUN_1404f0560(Unk_It* a, Unk_It* b) { return !FUN_1404f02a0(a, b); }
// @0x1404f05a0
bool FUN_1404f05a0(Unk_It* a, Unk_It* b) { return !FUN_1404f02e0(a, b); }
// @0x1404f05e0
bool FUN_1404f05e0(Unk_It* a, Unk_It* b) { return !FUN_1404f0320(a, b); }
// @0x1404f0620
bool FUN_1404f0620(Unk_It* a, Unk_It* b) { return !FUN_1404f0360(a, b); }
// @0x1404f0660
bool FUN_1404f0660(Unk_It* a, Unk_It* b) { return !FUN_1404f03a0(a, b); }
// @0x1404f06a0
bool FUN_1404f06a0(Unk_It* a, Unk_It* b) { return !FUN_1404f03e0(a, b); }
// @0x1404f06e0
bool FUN_1404f06e0(Unk_It* a, Unk_It* b) { return !FUN_1404f0420(a, b); }

// ATL::CAtlArray::operator[] with the E_INVALIDARG bounds check
void FUN_140159b70(long);
struct Unk_E16 { i64 a, b; };
struct Unk_Arr16 { Unk_E16* data; u64 size; };
// @0x1404f0720
Unk_E16* FUN_1404f0720(Unk_Arr16* t, u64 i) { if (i >= t->size) FUN_140159b70(0x80070057); return &t->data[i]; }
// @0x1404f0760
Unk_E16* FUN_1404f0760(Unk_Arr16* t, u64 i) { if (i >= t->size) FUN_140159b70(0x80070057); return &t->data[i]; }
