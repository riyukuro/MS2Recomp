// CLockCriticalSection (RTTI name) and the scoped lock helper the game wraps around it. PLACEHOLDER: layout from
// the ctor/dtor of CStopWatchEx (commonfiles\timeutil.cpp) and buddymanager.h (which keeps its own identical copy).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
class CLockCriticalSection {
public:
    CLockCriticalSection(); virtual ~CLockCriticalSection(); virtual void vfunc_1(); virtual void vfunc_2();
    CRITICAL_SECTION section;
};
MS2_CHECK_SIZE(CLockCriticalSection,0x30);
// Scoped guard: `if (Unk_LockGuard guard = lock) {} else { ... }` (0x140163940 ctor, 0x140164a80 operator int, 0x1401643b0 dtor).
class Unk_LockGuard { public: Unk_LockGuard(CLockCriticalSection&); ~Unk_LockGuard(); operator int(); private: void* p; };
MS2_CHECK_SIZE(Unk_LockGuard,8);
// Scoped lock taking the section and a mode (always 1 so far): ctor 0x1401b4ec0 (by reference; 0x140203610 takes the
// pointer), dtor 0x1401b5120. Many units keep their own copy under an Unk_ name (Unk_FieldLock, Unk_PetLock, ...).
class Unk_CriticalSectionLock { public: Unk_CriticalSectionLock(CLockCriticalSection&, int); Unk_CriticalSectionLock(CLockCriticalSection*, int); ~Unk_CriticalSectionLock(); private: CLockCriticalSection* m_p; };
MS2_CHECK_SIZE(Unk_CriticalSectionLock,8);
