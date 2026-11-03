// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The deliberate-crash test: FUN_140cca840(n) triggers one of
// 14 kinds of failure (null write, terminate, pure virtual call, stack overflow, SEH / C++ / MFC exceptions) so the crash
// reporter can be exercised. Name assumed (the exe has no __FILE__ for this unit); Crash::CBase / CDerived are RTTI names.
// MS2-UNIT: ?\crash.cpp
// MS2-RANGE: 0x140cca840-0x140ccac60 .text$mn
// MS2-PIN: ??1CDerived@Crash@@QEAA@XZ 0x140ccaab0 ; implicit dtor
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\crash.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <stdio.h>
#include <exception>
#include <new>
#include <windows.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/ms2.h"

namespace Crash
{
// A base class whose destructor calls a pure virtual through a stored pointer (a "pure virtual function call" crash).
class CBase
{
public:
    CBase(CBase* pSelf);                                        // 0x140ccaa40
    ~CBase();                                                   // 0x140ccaa00
    virtual void vfunc_0() = 0;
private:
    CBase* m_pSelf;                                             // +0x08
};

class CDerived : public CBase
{
public:
    CDerived();                                                 // 0x140ccaa70
    virtual void vfunc_0();                                     // 0x140ccaad0 empty
};
}

void* FUN_140aae430();

// @0x140cca840
void FUN_140cca840(int nType);

// @0x140cca9d0
int FUN_140cca9d0()
{
    char* pBuffer = new char[0x7ffffffc];
    FUN_140cca9d0();
    return 0;
}

// @0x140ccaa00
Crash::CBase::~CBase()
{
    m_pSelf->vfunc_0();
}

// @0x140ccaa40
Crash::CBase::CBase(CBase* pSelf) : m_pSelf(pSelf)
{
}

// @0x140ccaa70
Crash::CDerived::CDerived() : CBase(this)
{
}

// @0x140ccaad0
void Crash::CDerived::vfunc_0()
{
}

// @0x140ccaae0: the CRT's inline printf
// MS2_EMIT: printf is inline in the UCRT header, the unit's copy sits here
int FUN_140ccaae0(const char* pszFormat, ...)
{
    int nResult;
    va_list args;
    va_start(args, pszFormat);
    nResult = _vfprintf_l(stdout, pszFormat, NULL, args);
    va_end(args);
    return nResult;
}

// @0x140ccab40
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// @0x140cca840
void FUN_140cca840(int nType)
{
    switch (nType)
    {
    case 0:
    {
        int* pNull = 0;
        *pNull = 0;
        break;
    }
    case 1:
        std::terminate();
        break;
    case 2:
        unexpected();
        break;
    case 3:
    {
        Crash::CDerived derived;
    }
        break;
    case 4:
    {
        const char* psz = 0;
        FUN_140ccaae0(psz);
        break;
    }
    case 5:
        FUN_140cca9d0();
        break;
    case 6:
        ATL::AtlThrowImpl(0x8007000e);
        break;
    case 7:
        RaiseException(0x7b, 1, 0, 0);
        break;
    case 8:
        throw 0xd;
        break;
    case 9:
        AfxThrowFileException(1, -1, 0);
        break;
    case 10:
        AfxThrowMemoryException();
        break;
    case 11:
        throw std::exception();
        break;
    case 12:
        throw std::bad_alloc();
        break;
    case 13:
        reinterpret_cast<MS2*>(FUN_140aae430())->SetCrashOnShutdown();
        break;
    }
}
