// gfxsysalloc.h - PLACEHOLDER for GFxSysAlloc (RTTI .?AVGFxSysAlloc@@, vftable 0x143116a90): the game's Scaleform system
// allocator. NOT an original header. A Scaleform::SysAllocMalloc (SDK, HeapMH) whose Alloc / Free / Realloc keep the
// running total of aligned bytes in DAT_143b0d788 (read by ms2visualtrackermanager.cpp) and throw std::bad_alloc when
// _aligned_malloc fails. Slots: 0 ??_G 0x1422eae60, 1/2 the SDK's initHeapEngine / shutdownHeapEngine, 3 Alloc 0x1422eac00,
// 4 Free 0x1422eadf0, 5 Realloc 0x1422eaca0.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"
#include "Kernel/HeapMH/HeapMH_SysAllocMalloc.h"

extern int DAT_143b0d788;               // GFx system allocation total (bytes)

class GFxSysAlloc : public Scaleform::SysAllocMalloc
{
public:
    GFxSysAlloc();                                                              // 0x1422eab90
    virtual ~GFxSysAlloc();                                                     // 0x1422eabd0
    virtual void* Alloc(Scaleform::UPInt size, Scaleform::UPInt align);
    virtual void Free(void* ptr, Scaleform::UPInt size, Scaleform::UPInt align);
    virtual void* Realloc(void* oldPtr, Scaleform::UPInt oldSize, Scaleform::UPInt newSize, Scaleform::UPInt align);
};
MS2_CHECK_SIZE(GFxSysAlloc, 0x10);
