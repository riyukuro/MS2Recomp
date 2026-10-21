// CThread: RTTI and deleting destructor establish the 0x18-byte worker base.
#pragma once
#include <windows.h>
#include "ms2/ms2layout.h"
class Unk_140659080;
class CThread {
public:
    CThread();
    virtual ~CThread();
    virtual unsigned int vfunc_1(void*, Unk_140659080&);    // 0x1401d4030 (base: signals ready, returns 0)
    int FUN_1401d3510(DWORD timeout);
    // gamesocket.cpp worker management (non-virtual).
    int FUN_141215220(void*,void*,int,int,void*);
    HANDLE FUN_14126a990() const;
    // Typed start path recovered in the file preload object.
    int Start(void* user,int priority,int suspended,unsigned stackSize,LPSECURITY_ATTRIBUTES attributes);
    DWORD GetThreadId() const;
    int WaitForExit(DWORD timeout);
    void FUN_1401d2fa0();
private:
    DWORD m_threadId;
    HANDLE m_thread;
};
MS2_CHECK_SIZE(CThread,0x18);
