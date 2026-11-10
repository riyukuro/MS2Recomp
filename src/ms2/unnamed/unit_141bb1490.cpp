// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Four pooled-object construction pairs: for each of four
// pointer-wrapped types, the factory (allocator New + in-place constructor, sharing the runtime's refcount-1 helper) and
// the initializer that releases the object's previous +0x8 instance and stores the fresh one. The owned types, their
// allocators and the per-type release helpers live in other units; only the pointer view used here is recovered.
// File and function names are invented.
// MS2-UNIT: unit_141bb1490
// MS2-RANGE: 0x141bb1490-0x141bb15d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/uiworldmap.h"   // C3: the factories' record types
#include "ms2/placeholder/ascript.h"   // C3: MS2Ptr<T> (friend Unk_MS2PtrAccess)
// The runtime's refcount-1 helper, the four types' pooled allocator+constructor and their release helpers (other units).
class CPtred* InitRefCount(class CPtred*);   // C3: was InitRefCount
UIWorldMap::AddtionalInfo* FUN_141b9d8e0(void* pTag);   // C3: returns the record
UIWorldMap::FieldSearchInfo* FUN_141b9d950(void* pTag);   // C3: returns the record
UIWorldMap::IconInfo* FUN_141b9d9c0(void* pTag);   // C3: returns the record
UIWorldMap::MapTile* FUN_141b9da20(void* pTag);   // C3: returns the record
struct Unk_MS2PtrAccess { static void FUN_141bb1490(MS2Ptr<UIWorldMap::AddtionalInfo>& sp);   // C3: MS2Ptr<T> friend (ascript.h): Release, then a new pooled T
    static void FUN_141bb14c0(MS2Ptr<UIWorldMap::FieldSearchInfo>& sp);   // C3: MS2Ptr<T> friend (ascript.h): Release, then a new pooled T
    static void FUN_141bb14f0(MS2Ptr<UIWorldMap::IconInfo>& sp);   // C3: MS2Ptr<T> friend (ascript.h): Release, then a new pooled T
    static void FUN_141bb1520(MS2Ptr<UIWorldMap::MapTile>& sp); };   // C3: MS2Ptr<T> friend (ascript.h): Release, then a new pooled T

// The four factories below (defined after the initializers, in exe order).
void* FUN_141bb1550(void*);
void* FUN_141bb1570(void*);
void* FUN_141bb1590(void*);
void* FUN_141bb15b0(void*);

// The owner is the MS2Ptr<T> itself (m_p at +0x8); the Release helpers 0x141b6c060/0a0/0e0, 0x140cb18e0 are MS2Ptr<T>::Release.
//
//
//
//
//

// @0x141bb1490
void Unk_MS2PtrAccess::FUN_141bb1490(MS2Ptr<UIWorldMap::AddtionalInfo>& sp)
{
    sp.Release();
    sp.m_p = static_cast<UIWorldMap::AddtionalInfo*>(FUN_141bb1550(0));
}

// @0x141bb14c0
void Unk_MS2PtrAccess::FUN_141bb14c0(MS2Ptr<UIWorldMap::FieldSearchInfo>& sp)
{
    sp.Release();
    sp.m_p = static_cast<UIWorldMap::FieldSearchInfo*>(FUN_141bb1570(0));
}

// @0x141bb14f0
void Unk_MS2PtrAccess::FUN_141bb14f0(MS2Ptr<UIWorldMap::IconInfo>& sp)
{
    sp.Release();
    sp.m_p = static_cast<UIWorldMap::IconInfo*>(FUN_141bb1590(0));
}

// @0x141bb1520
void Unk_MS2PtrAccess::FUN_141bb1520(MS2Ptr<UIWorldMap::MapTile>& sp)
{
    sp.Release();
    sp.m_p = static_cast<UIWorldMap::MapTile*>(FUN_141bb15b0(0));
}

// @0x141bb1550
void* FUN_141bb1550(void*)
{
    return ((void*)InitRefCount((class CPtred*)(FUN_141b9d8e0(0))));
}

// @0x141bb1570
void* FUN_141bb1570(void*)
{
    return ((void*)InitRefCount((class CPtred*)(FUN_141b9d950(0))));
}

// @0x141bb1590
void* FUN_141bb1590(void*)
{
    return ((void*)InitRefCount((class CPtred*)(FUN_141b9d9c0(0))));
}

// @0x141bb15b0
void* FUN_141bb15b0(void*)
{
    return ((void*)InitRefCount((class CPtred*)(FUN_141b9da20(0))));
}
