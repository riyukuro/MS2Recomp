// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxSysAlloc, the Scaleform system allocator of the GFx UI
// library.
// MS2-UNIT: ?\gfxsysalloc.cpp
// MS2-RANGE: 0x1422eab90-0x1422eaea0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/gfxsysalloc.h. Every allocation adds its aligned size to DAT_143b0d788.
#include "ms2/placeholder/ms2stdafx.h"

#include <intrin.h>
#include <malloc.h>
#include <new>

#include "ms2/placeholder/gfxsysalloc.h"

#include "hook/ms2hook.h"

using Scaleform::UPInt;

// @0x1422eab90
GFxSysAlloc::GFxSysAlloc()
{
}

// @0x1422eabd0
GFxSysAlloc::~GFxSysAlloc()
{
}

// @0x1422eac00
void* GFxSysAlloc::Alloc(UPInt size, UPInt align)
{
    UPInt a = align;
    UPInt nAligned = (size + a - 1) & ~(a - 1);
    _InterlockedExchangeAdd((volatile long*)&DAT_143b0d788, (long)nAligned);
    void* p = _aligned_malloc(size, align);
    if (p == NULL)
        throw std::bad_alloc();
    return p;
}

#pragma function(memcpy)             // the exe calls the CRT memcpy (no inline rep movsb)

// @0x1422eaca0
void* GFxSysAlloc::Realloc(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align)
{
    UPInt a = align;
    UPInt nOld = (oldSize + a - 1) & ~(a - 1);
    UPInt nNew = (newSize + a - 1) & ~(a - 1);
    _InterlockedExchangeAdd((volatile long*)&DAT_143b0d788, (long)(nNew - nOld));
    if (newSize == oldSize)
        return oldPtr;
    void* p = _aligned_malloc(newSize, align);
    if (p != NULL) {
        memcpy(p, oldPtr, oldSize < newSize ? oldSize : newSize);
        _aligned_free(oldPtr);
    }
    else {
        throw std::bad_alloc();
    }
    return p;
}

// @0x1422eadf0
void GFxSysAlloc::Free(void* ptr, UPInt size, UPInt align)
{
    UPInt a = align;
    UPInt nAligned = (size + a - 1) & ~(a - 1);
    _InterlockedExchangeAdd((volatile long*)&DAT_143b0d788, (long)-(Scaleform::SPInt)nAligned);
    _aligned_free(ptr);
}

// MS2-PIN: ??_GGFxSysAlloc@@UEAAPEAXI@Z 0x1422eae60
