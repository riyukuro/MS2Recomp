// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The global critical section at 0x143aab3b0 and the dynamic
// initializer the compiler emits for it (.text$di 0x1400b21a0: construct the lock, register its atexit destructor).
// MS2-UNIT: unit_1400b21a0
// MS2-RANGE: 0x1400b21a0-0x1400b21d0 .text$di
// MS2-PIN: ??__EDAT_143aab3b0@@YAXXZ 0x1400b21a0 ; generated initializer of the global lock
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_1400b21a0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#ifndef MS2_HOOK_DLL
CLockCriticalSection DAT_143aab3b0;                         // the global lock
#else
extern CLockCriticalSection DAT_143aab3b0;
#endif
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c99fa0-0x142c99fc0 .text$yd
