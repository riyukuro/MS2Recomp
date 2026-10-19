#pragma once
#include "ms2/placeholder/cthread.h"
// Stack startup handshake passed to the worker virtual; caller waits for ready
// before returning and the worker acknowledges its local copy via FUN_1401d42d0.
class Unk_140659080 {
public:
    void FUN_1401d42d0();
    int FUN_140659080(int nResult);                         // the thread failed to start (itemloadinfo.cpp)
    CThread* owner;
    void* user;
    DWORD flags;
    HANDLE ready;
    HANDLE resume;
    DWORD error;
};
MS2_CHECK_SIZE(Unk_140659080,0x30);
MS2_CHECK_OFFSET(Unk_140659080,ready,0x18);
MS2_CHECK_OFFSET(Unk_140659080,error,0x28);
