// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Nexon Analytics (NxLog, "NexonAnalytics64.dll") client
// wrapper of nxa.cpp: the GetProcAddress table of the DLL's exports, the Unk_NexonAnalytics calls into it, and the
// nxa:: tagged value (Unk_NxValue) with its pooled array/object storage and the malloc-backed default allocator.
// The unit is /Od debug code. Only the functions the rest of the game reaches are recovered; the other exports'
// wrappers in the range stay unrecovered. Names of the value internals are invented from their use.
// MS2-UNIT: unit_14092cb30
// MS2-RANGE: 0x14092cb30-0x14092f420 .text$mn
// MS2-PIN: memmove_s 0x14092f2d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\nxa.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/ms2clientplatformbase.h"
#include "ms2/ms2recover.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <new>
#include <stdarg.h>

// This TU's own copies of the UCRT wide stdio inlines (the exe keeps them apart from textlogfile's).
// @0x14092f210
static int ms2_vfwprintf_l_nxa(FILE* pStream, const wchar_t* pszFormat, _locale_t hLocale, va_list args)
{
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, pStream, pszFormat, hLocale, args);
}

// @0x14092f260
static int ms2_fwprintf_nxa(FILE* pStream, const wchar_t* pszFormat, ...)
{
    int nResult;
    va_list args;
    va_start(args, pszFormat);
    nResult = ms2_vfwprintf_l_nxa(pStream, pszFormat, NULL, args);
    va_end(args);
    return nResult;
}

namespace nxa {

// vftable 0x142daadc0: Alloc, Free.
class MemoryAllocator
{
public:
    virtual void* Alloc(size_t nSize) = 0;
    virtual void Free(void* p) = 0;
};

// vftable 0x142daadd8: Alloc, Free, the scalar deleting dtor.
class DefaultMemoryAllocator : public MemoryAllocator
{
public:
    // @0x14092e330
    DefaultMemoryAllocator() {}
    // @0x14092e420
    virtual ~DefaultMemoryAllocator() {}
    // @0x14092e6f0
    virtual void* Alloc(size_t nSize) { return malloc(nSize); }
    // @0x14092ee20
    virtual void Free(void* p) { free(p); }
};

} // namespace nxa

// The process-wide default allocator (0x143ab26d8, guard 0x143ab26e0).
// @0x14092ed70
static nxa::MemoryAllocator* FUN_14092ed70()
{
    static nxa::DefaultMemoryAllocator s_kAllocator;
    return &s_kAllocator;
}

// The current allocator (0x143ab26e8, guard 0x143ab26f0); a non-null argument replaces it.
// @0x14092ecb0
static nxa::MemoryAllocator* FUN_14092ecb0(nxa::MemoryAllocator* pAllocator)
{
    static nxa::MemoryAllocator* s_pAllocator = FUN_14092ed70();
    if (pAllocator != NULL && pAllocator != s_pAllocator)
        s_pAllocator = pAllocator;
    return s_pAllocator;
}

// A size-class free-list pool: +0 the chunk list, +8 the bucket array (one free list per size class), +0x10 its size.
struct Unk_NxPool
{
    void** m_pChunks;
    void** m_ppFree;
    unsigned m_nFree;
    unsigned m_n14;
    unsigned m_n18;
    unsigned m_n1c;
};

// @0x14092f0d0
static void FUN_14092f0d0(Unk_NxPool* pPool)
{
    void** p = pPool->m_pChunks;
    while (p != NULL) {
        void** pNext = (void**)*p;
        FUN_14092ecb0(NULL)->Free(p);
        p = pNext;
    }
    pPool->m_pChunks = NULL;
    if (pPool->m_ppFree != NULL) {
        FUN_14092ecb0(NULL)->Free(pPool->m_ppFree);
        pPool->m_ppFree = NULL;
    }
    pPool->m_n14 = 0;
    pPool->m_n18 = 0;
    pPool->m_n1c = 0;
}

// @0x14092e4b0
static void FUN_14092e4b0(Unk_NxPool* pPool) noexcept { FUN_14092f0d0(pPool); }

// The pool's scalar deleting dtor.
// @0x14092e630
static Unk_NxPool* FUN_14092e630(Unk_NxPool* pPool, unsigned nFlags)
{
    FUN_14092e4b0(pPool);
    if (nFlags & 1)
        operator delete(pPool, 0x20);
    return pPool;
}

// Returns a block to the free list of its size class (the 16-byte header before it: +0 the link, +8 the class).
struct Unk_NxBlockHeader
{
    void* m_pNext;
    size_t m_nClass;
};

// @0x14092ee40
static void FUN_14092ee40(Unk_NxPool* pPool, void* p)
{
    if (p == NULL)
        return;
    Unk_NxBlockHeader* pHeader = (Unk_NxBlockHeader*)((unsigned char*)p - 0x10);
    size_t nClass = pHeader->m_nClass;
    if (pPool->m_nFree <= nClass) {
        size_t nCount = nClass + 1;
        nCount = nCount < 0x40 ? 0x40 : (nCount + 7) / 8 * 8;
        void** ppNew = (void**)FUN_14092ecb0(NULL)->Alloc(nCount * 8);
        void** ppTail;
        if (pPool->m_ppFree != NULL) {
            memcpy(ppNew, pPool->m_ppFree, (size_t)pPool->m_nFree * 8);
            ppTail = ppNew + pPool->m_nFree;
            FUN_14092ecb0(NULL)->Free(pPool->m_ppFree);
        } else {
            ppTail = ppNew;
        }
        memset(ppTail, 0, (nCount - pPool->m_nFree) * 8);
        pPool->m_ppFree = ppNew;
        pPool->m_nFree = (unsigned)nCount;
    }
    pHeader->m_pNext = pPool->m_ppFree[nClass];
    pPool->m_ppFree[nClass] = pHeader;
}

// The raw view of the 0x38-byte tagged value: +0 kind, +2 flags (low nibble: string mode; 0x10 inline, 0x20 heap),
// +4 heap capacity, +8 an owned pool, +0x10 the payload.
struct Unk_NxRaw
{
    unsigned short m_nKind;
    unsigned short m_nFlags;
    unsigned m_nSize;
    Unk_NxPool* m_pPool;
    unsigned char m_abPayload[0x28];
};

static void FUN_14092eb30(Unk_NxRaw* pValue);

// @0x14092e6b0
static Unk_NxRaw* FUN_14092e6b0(Unk_NxRaw* pValue, unsigned nFlags);

// An array block: +8 the next block, +0x10 the element count, the 0x38-byte elements from +0x18.
struct Unk_NxArrayBlock
{
    void* m_p0;
    Unk_NxArrayBlock* m_pNext;
    unsigned m_nCount;
    unsigned m_n14;
    Unk_NxRaw m_akElem[1];
};

// @0x14092f1a0
static void FUN_14092f1a0(void* pArray, Unk_NxArrayBlock* pBlock)
{
    Unk_NxRaw* pElem = pBlock->m_akElem;
    int i = (int)pBlock->m_nCount;
    while (--i >= 0) {
        FUN_14092e6b0(pElem, 0);
        ++pElem;
    }
    pBlock->m_nCount = 0;
}

// The array payload (kind 7): +0 its pool, +8 the block list (link at +8), +0x22 set when it owns the pool.
struct Unk_NxArray
{
    Unk_NxPool* m_pPool;
    Unk_NxArrayBlock* m_pBlocks;
    __int64 m_n10;
    unsigned m_n18;
    unsigned m_n1c;
    unsigned short m_n20;
    unsigned short m_bOwnPool;
    unsigned m_n24;
};

// @0x14092f020
static void FUN_14092f020(Unk_NxArray* pArray)
{
    if (pArray->m_pBlocks == NULL)
        return;
    Unk_NxArrayBlock* p = pArray->m_pBlocks;
    while (p != NULL) {
        Unk_NxArrayBlock* pNext = p->m_pNext;
        FUN_14092f1a0(pArray, p);
        FUN_14092ee40(pArray->m_pPool, p);
        p = pNext;
    }
    pArray->m_n10 = 0;
    pArray->m_pBlocks = NULL;
    pArray->m_n18 = 0;
    pArray->m_n1c = 0;
}

// @0x14092e440
static void FUN_14092e440(Unk_NxArray* pArray) noexcept
{
    FUN_14092f020(pArray);
    if (pArray->m_bOwnPool) {
        FUN_14092e630(pArray->m_pPool, 0);
        FUN_14092ecb0(NULL)->Free(pArray->m_pPool);
    }
}

// @0x14092e5f0
static Unk_NxArray* FUN_14092e5f0(Unk_NxArray* pArray, unsigned nFlags)
{
    FUN_14092e440(pArray);
    if (nFlags & 1)
        operator delete(pArray, 0x28);
    return pArray;
}

// The object payload (kind 8): +0 its pool, +8 64 hash buckets (node: +0 link, +8 key, +0x40 value), +0x14 the
// member count, +0x18 set when it owns the pool.
struct Unk_NxMember
{
    Unk_NxMember* m_pNext;
    Unk_NxRaw m_kName;
    Unk_NxRaw m_kValue;
};

struct Unk_NxObject
{
    Unk_NxPool* m_pPool;
    Unk_NxMember** m_ppBuckets;
    unsigned m_n10;
    unsigned m_nCount;
    unsigned short m_bOwnPool;
};

// @0x14092ea50
static void FUN_14092ea50(Unk_NxObject* pObject)
{
    if (pObject->m_nCount == 0)
        return;
    for (size_t i = 0; i < 0x40; ++i) {
        Unk_NxMember* p = pObject->m_ppBuckets[i];
        while (p != NULL) {
            Unk_NxMember* pNext = p->m_pNext;
            FUN_14092e6b0(&p->m_kName, 0);
            FUN_14092e6b0(&p->m_kValue, 0);
            FUN_14092ee40(pObject->m_pPool, p);
            p = pNext;
        }
    }
    memset(pObject->m_ppBuckets, 0, 0x200);
    pObject->m_nCount = 0;
}

// @0x14092e4e0
static void FUN_14092e4e0(Unk_NxObject* pObject) noexcept
{
    FUN_14092ea50(pObject);
    FUN_14092ee40(pObject->m_pPool, pObject->m_ppBuckets);
    if (pObject->m_bOwnPool) {
        FUN_14092e630(pObject->m_pPool, 0);
        FUN_14092ecb0(NULL)->Free(pObject->m_pPool);
    }
}

// @0x14092e670
static Unk_NxObject* FUN_14092e670(Unk_NxObject* pObject, unsigned nFlags)
{
    FUN_14092e4e0(pObject);
    if (nFlags & 1)
        operator delete(pObject, 0x20);
    return pObject;
}

// Frees the value's own pool.
// @0x14092ec50
static void FUN_14092ec50(Unk_NxRaw* pValue)
{
    if (pValue->m_pPool == NULL)
        return;
    FUN_14092e630(pValue->m_pPool, 0);
    FUN_14092ecb0(NULL)->Free(pValue->m_pPool);
    pValue->m_pPool = NULL;
}

// Frees a heap string payload.
// @0x14092e950
static void FUN_14092e950(Unk_NxRaw* pValue)
{
    FUN_14092ecb0(NULL)->Free(*(void**)pValue->m_abPayload);
    pValue->m_nSize = 0;
}

// Resets the value to kind 0, releasing what it owns.
// @0x14092eb30
static void FUN_14092eb30(Unk_NxRaw* pValue)
{
    switch (pValue->m_nKind) {
    case 0:
        FUN_14092ec50(pValue);
        return;
    case 5:
    case 6:
        switch (pValue->m_nFlags & 0xf0) {
        case 0x20:
            FUN_14092e950(pValue);
            break;
        }
        break;
    case 7:
        switch (pValue->m_nFlags & 0xf) {
        case 2:
            FUN_14092e5f0((Unk_NxArray*)pValue->m_abPayload, 0);
            break;
        }
        break;
    case 8:
        switch (pValue->m_nFlags & 0xf) {
        case 2:
            FUN_14092e670((Unk_NxObject*)pValue->m_abPayload, 0);
            break;
        }
        break;
    }
    pValue->m_nFlags = 0;
    pValue->m_nKind = 0;
    pValue->m_nSize = 0;
    FUN_14092ec50(pValue);
    memset(pValue->m_abPayload, 0, sizeof(pValue->m_abPayload));
}

// The value dtor (Unk_NxNumber's dtor 0x140c772f0 calls it).
// @0x14092e580
void FUN_14092e580(void* p) noexcept { FUN_14092eb30((Unk_NxRaw*)p); }

// @0x14092e6b0
static Unk_NxRaw* FUN_14092e6b0(Unk_NxRaw* pValue, unsigned nFlags)
{
    FUN_14092e580(pValue);
    if (nFlags & 1)
        operator delete(pValue, 0x38);
    return pValue;
}

// Sets the kind, resetting the value first when it changes.
// @0x14092ea10
void FUN_14092ea10(void* p, int nKind)
{
    if (((Unk_NxRaw*)p)->m_nKind != nKind) {
        FUN_14092eb30((Unk_NxRaw*)p);
        ((Unk_NxRaw*)p)->m_nKind = (unsigned short)nKind;
    }
}

// Allocates a heap string buffer of nSize bytes.
// @0x14092e7e0
static void* FUN_14092e7e0(Unk_NxRaw* pValue, size_t nSize)
{
    void* p = FUN_14092ecb0(NULL)->Alloc(nSize);
    if (p != NULL) {
        new (pValue->m_abPayload) void*(p);
        pValue->m_nSize = (unsigned)nSize;
    }
    return p;
}

// Copies nSize bytes of string (inline up to 0x28 bytes, else on the heap).
// @0x14092e860
static void FUN_14092e860(Unk_NxRaw* pValue, const char* psz, size_t nSize)
{
    void* pDst;
    switch (pValue->m_nFlags & 0xf0) {
    case 0x20:
        if (nSize <= pValue->m_nSize) {
            pDst = *(void**)pValue->m_abPayload;
        } else {
            FUN_14092e950(pValue);
            pDst = FUN_14092e7e0(pValue, nSize);
            if (pDst == NULL)
                return;
        }
        break;
    default:
        if (nSize <= 0x28) {
            pDst = pValue->m_abPayload;
            pValue->m_nFlags = 0x13;
        } else {
            pDst = FUN_14092e7e0(pValue, nSize);
            if (pDst == NULL)
                return;
            pValue->m_nFlags = 0x23;
        }
        break;
    }
    memcpy(pDst, psz, nSize);
}

// Refers to a caller-owned string (mode 0x40 or 0x30).
// @0x14092e990
static void FUN_14092e990(Unk_NxRaw* pValue, const char* psz, int nMode)
{
    switch (pValue->m_nFlags & 0xf0) {
    case 0x20:
        FUN_14092e950(pValue);
        break;
    }
    pValue->m_nFlags = (unsigned short)(nMode | 3);
    new (pValue->m_abPayload) const char*(psz);
}

// @0x14092e710
void Unk_NxString::Set(const char* psz, int nMode)
{
    if (psz == NULL) {
        FUN_14092eb30((Unk_NxRaw*)this);
        return;
    }
    FUN_14092ea10((Unk_NxRaw*)this, 5);
    switch (nMode & 0xf) {
    case 1:
        FUN_14092e990((Unk_NxRaw*)this, psz, 0x40);
        break;
    case 2:
        FUN_14092e990((Unk_NxRaw*)this, psz, 0x30);
        break;
    default:
        FUN_14092e860((Unk_NxRaw*)this, psz, strlen(psz) + 1);
        break;
    }
}

// @0x14092e560
Unk_NxString::~Unk_NxString() { FUN_14092e580(this); }

// @0x14092e3c0
static Unk_NxString* FUN_14092e3c0(Unk_NxString* pString, const char* psz, int nMode)
{
    pString->m_nKind = 0;
    pString->m_nFlags = 0;
    pString->m_nSize = 0;
    pString->m_n8 = 0;
    pString->Set(psz, nMode);
    return pString;
}

// @0x14092e380
Unk_NxString::Unk_NxString(const char* psz, int nMode)
{
    FUN_14092e3c0(this, psz, nMode);
}

// @0x14092ed50
static const char* FUN_14092ed50() { return "NXA_20200917"; }

// @0x14092ed60
static const char* FUN_14092ed60() { return "NXA_20200917"; }

// ---- the DLL exports (0x143ab26f8..0x143ab2810) ----

// The DLL's exports, one global each (0x143ab26f8..0x143ab2810).
static FARPROC s_pfn_presetWorkingDirectory;
static FARPROC s_pfn_presetNxLogVersion;
static FARPROC s_pfn_presetBaseClassVersion;
static FARPROC s_pfn_presetConfigServerAddress;
static FARPROC s_pfn_presetLogServerAddress;
static FARPROC s_pfn_presetBackupFileLimit;
static FARPROC s_pfn_presetSystemInfoLogOff;
static FARPROC s_pfn_initializeClientModuleEx;
static FARPROC s_pfn_finalizeModule;
static FARPROC s_pfn_updateUser;
static FARPROC s_pfn_setUserExtraInfo;
static FARPROC s_pfn_enqueueStageLog;
static FARPROC s_pfn_enqueueErrorLog;
static FARPROC s_pfn_enqueueLogOnlyOnce;
static FARPROC s_pfn_enqueueNxLog;
static FARPROC s_pfn_enqueueLog;
static FARPROC s_pfn_enqueueJsonLog;
static FARPROC s_pfn_enqueueDevLog;
static FARPROC s_pfn_enqueueSystemInfoLog;
static FARPROC s_pfn_assignInfoUser;
static FARPROC s_pfn_getCommonFieldA;
static FARPROC s_pfn_getCommonFieldW;
static FARPROC s_pfn_getAccountNoA;
static FARPROC s_pfn_getAccountNoW;
static FARPROC s_pfn_getSessionIdA;
static FARPROC s_pfn_getSessionIdW;
static FARPROC s_pfn_getMachineIdA;
static FARPROC s_pfn_getMachineIdW;
static FARPROC s_pfn_getLastError;
static FARPROC s_pfn_setDevLogLevel;
static FARPROC s_pfn_setActiveInputLog;
static FARPROC s_pfn_inputProc;
static FARPROC s_pfn_setInputLogLevel;
static FARPROC s_pfn_enqueueInputAction;
static FARPROC s_pfn_registerKeymapInfo;
static FARPROC s_pfn_getPoolAllocator;

typedef bool (*PFN_NxaPresetString)(const Unk_NxString*);
typedef void (*PFN_NxaPresetBaseClassVersion)(const Unk_NxString*, const Unk_NxString*);
typedef bool (*PFN_NxaInitializeClientModuleEx)(const Unk_NxEvent*, const Unk_NxString*, const Unk_NxNumber*);
typedef void (*PFN_NxaFinalizeModule)(bool);
typedef bool (*PFN_NxaEnqueueLog)(int, const Unk_NxString*);

// @0x14092edf0
bool FUN_14092edf0(HMODULE* ppModule) { return *ppModule != NULL; }

// Forgets the module and every export.
// @0x14092e190
static void FUN_14092e190(HMODULE* ppModule)
{
    *ppModule = NULL;
    s_pfn_presetWorkingDirectory = NULL;
    s_pfn_presetNxLogVersion = NULL;
    s_pfn_presetBaseClassVersion = NULL;
    s_pfn_presetConfigServerAddress = NULL;
    s_pfn_presetLogServerAddress = NULL;
    s_pfn_presetBackupFileLimit = NULL;
    s_pfn_presetSystemInfoLogOff = NULL;
    s_pfn_initializeClientModuleEx = NULL;
    s_pfn_finalizeModule = NULL;
    s_pfn_updateUser = NULL;
    s_pfn_setUserExtraInfo = NULL;
    s_pfn_enqueueStageLog = NULL;
    s_pfn_enqueueErrorLog = NULL;
    s_pfn_enqueueLogOnlyOnce = NULL;
    s_pfn_enqueueNxLog = NULL;
    s_pfn_enqueueLog = NULL;
    s_pfn_enqueueJsonLog = NULL;
    s_pfn_enqueueDevLog = NULL;
    s_pfn_enqueueSystemInfoLog = NULL;
    s_pfn_assignInfoUser = NULL;
    s_pfn_getCommonFieldA = NULL;
    s_pfn_getCommonFieldW = NULL;
    s_pfn_getAccountNoA = NULL;
    s_pfn_getAccountNoW = NULL;
    s_pfn_getSessionIdA = NULL;
    s_pfn_getSessionIdW = NULL;
    s_pfn_getMachineIdA = NULL;
    s_pfn_getMachineIdW = NULL;
    s_pfn_getLastError = NULL;
    s_pfn_setDevLogLevel = NULL;
    s_pfn_setActiveInputLog = NULL;
    s_pfn_inputProc = NULL;
    s_pfn_setInputLogLevel = NULL;
    s_pfn_enqueueInputAction = NULL;
    s_pfn_registerKeymapInfo = NULL;
    s_pfn_getPoolAllocator = NULL;
}

// Resolves the DLL's exports group by group; on a missing one prints the group's message and forgets them all.
// @0x14092d8f0
bool FUN_14092d8f0(HMODULE* ppModule)
{
    do
    {
        s_pfn_presetWorkingDirectory = GetProcAddress(*ppModule, "presetWorkingDirectory");
        s_pfn_presetNxLogVersion = GetProcAddress(*ppModule, "presetNxLogVersion");
        s_pfn_presetBaseClassVersion = GetProcAddress(*ppModule, "presetBaseClassVersion");
        s_pfn_presetConfigServerAddress = GetProcAddress(*ppModule, "presetConfigServerAddress");
        s_pfn_presetLogServerAddress = GetProcAddress(*ppModule, "presetLogServerAddress");
        s_pfn_presetBackupFileLimit = GetProcAddress(*ppModule, "presetBackupFileLimit");
        s_pfn_presetSystemInfoLogOff = GetProcAddress(*ppModule, "presetSystemInfoLogOff");
        if (s_pfn_presetWorkingDirectory == NULL || s_pfn_presetNxLogVersion == NULL || s_pfn_presetBaseClassVersion == NULL || s_pfn_presetConfigServerAddress == NULL || s_pfn_presetLogServerAddress == NULL || s_pfn_presetBackupFileLimit == NULL || s_pfn_presetSystemInfoLogOff == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad presetWorkingDirectory(), presetNxLogVersion(), presetBaseClassVersion(), "
                "presetConfigServerAddress(), presetLogServerAddress(), presetBackupFileLimit(), presetSystemInfoLogOff() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        s_pfn_initializeClientModuleEx = GetProcAddress(*ppModule, "initializeClientModuleEx");
        s_pfn_finalizeModule = GetProcAddress(*ppModule, "finalizeModule");
        if (s_pfn_initializeClientModuleEx == NULL || s_pfn_finalizeModule == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad initializeClientModuleEx(), finalizeModule() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        s_pfn_updateUser = GetProcAddress(*ppModule, "updateUser");
        s_pfn_setUserExtraInfo = GetProcAddress(*ppModule, "setUserExtraInfo");
        if (s_pfn_updateUser == NULL || s_pfn_setUserExtraInfo == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad updateUser(), setUserExtraInfo() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        s_pfn_enqueueStageLog = GetProcAddress(*ppModule, "enqueueStageLog");
        s_pfn_enqueueErrorLog = GetProcAddress(*ppModule, "enqueueErrorLog");
        s_pfn_enqueueLogOnlyOnce = GetProcAddress(*ppModule, "enqueueLogOnlyOnce");
        if (s_pfn_enqueueStageLog == NULL || s_pfn_enqueueErrorLog == NULL || s_pfn_enqueueLogOnlyOnce == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad enqueueStageLog(), enqueueErrorLog(), enqueueLogOnlyOnce() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        s_pfn_enqueueNxLog = GetProcAddress(*ppModule, "enqueueNxLog");
        s_pfn_enqueueLog = GetProcAddress(*ppModule, "enqueueLog");
        if (s_pfn_enqueueNxLog == NULL || s_pfn_enqueueLog == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad enqueueNxLog(), enqueueLog() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        s_pfn_enqueueJsonLog = GetProcAddress(*ppModule, "enqueueJsonLog");
        s_pfn_enqueueDevLog = GetProcAddress(*ppModule, "enqueueDevLog");
        s_pfn_enqueueSystemInfoLog = GetProcAddress(*ppModule, "enqueueSystemInfoLog");
        s_pfn_assignInfoUser = GetProcAddress(*ppModule, "assignInfoUser");
        if (s_pfn_enqueueJsonLog == NULL || s_pfn_enqueueDevLog == NULL || s_pfn_enqueueSystemInfoLog == NULL || s_pfn_assignInfoUser == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad enqueueJsonLog(), enqueueDevLog(), enqueueSystemInfoLog(), assignInfoUser() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        s_pfn_getCommonFieldA = GetProcAddress(*ppModule, "getCommonFieldA");
        s_pfn_getCommonFieldW = GetProcAddress(*ppModule, "getCommonFieldW");
        s_pfn_getAccountNoA = GetProcAddress(*ppModule, "getAccountNoA");
        s_pfn_getAccountNoW = GetProcAddress(*ppModule, "getAccountNoW");
        s_pfn_getSessionIdA = GetProcAddress(*ppModule, "getSessionIdA");
        s_pfn_getSessionIdW = GetProcAddress(*ppModule, "getSessionIdW");
        s_pfn_getMachineIdA = GetProcAddress(*ppModule, "getMachineIdA");
        s_pfn_getMachineIdW = GetProcAddress(*ppModule, "getMachineIdW");
        s_pfn_getLastError = GetProcAddress(*ppModule, "getLastError");
        if (s_pfn_getCommonFieldA == NULL || s_pfn_getCommonFieldW == NULL || s_pfn_getAccountNoA == NULL || s_pfn_getAccountNoW == NULL || s_pfn_getSessionIdA == NULL || s_pfn_getSessionIdW == NULL || s_pfn_getMachineIdA == NULL || s_pfn_getMachineIdW == NULL || s_pfn_getLastError == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad getCommonFieldA(), getCommonFieldW(), getAccountNoA(), getAccountNoW(), "
                "getSessionIdA(), getSessionIdW(), getMachineIdA(), getMachineIdW(), getLastError() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        s_pfn_setDevLogLevel = GetProcAddress(*ppModule, "setDevLogLevel");
        if (s_pfn_setDevLogLevel == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad setDevLogLevel() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        s_pfn_setActiveInputLog = GetProcAddress(*ppModule, "setActiveInputLog");
        s_pfn_inputProc = GetProcAddress(*ppModule, "inputProc");
        s_pfn_setInputLogLevel = GetProcAddress(*ppModule, "setInputLogLevel");
        s_pfn_enqueueInputAction = GetProcAddress(*ppModule, "enqueueInputAction");
        s_pfn_registerKeymapInfo = GetProcAddress(*ppModule, "registerKeymapInfo");
        if (s_pfn_setActiveInputLog == NULL || s_pfn_inputProc == NULL || s_pfn_setInputLogLevel == NULL || s_pfn_enqueueInputAction == NULL || s_pfn_registerKeymapInfo == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad setActiveInputLog(), userInputProc(), setInputLogLevel(), "
                "enqueueInputAction(), registerKeymapInfo() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        s_pfn_getPoolAllocator = GetProcAddress(*ppModule, "getPoolAllocator");
        if (s_pfn_getPoolAllocator == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xbf\xa1\xbc\xad getPoolAllocator() "
                "\xc7\xd4\xbc\xf6\xb8\xa6 \xc3\xa3\xc0\xbb \xbc\xf6\xb0\xa1 \xbe\xf8\xbd\xc0\xb4\xcf\xb4\xd9.");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        return true;
    } while (0);
    FUN_14092e190(ppModule);
    return false;
}

// @0x14092cbf0
void Unk_NexonAnalytics::FUN_14092cbf0()
{
    if (!FUN_14092edf0((HMODULE*)this))
        return;
    ((PFN_NxaFinalizeModule)s_pfn_finalizeModule)(true);
    if (!FreeLibrary(*(HMODULE*)this))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
        fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xc0\xbb \xbe\xf0\xb7\xce\xb5\xe5\xc7\xcf\xc1\xf6 "
                "\xb8\xf8\xc7\xdf\xbd\xc0\xb4\xcf\xb4\xd9. - error-code=%lu", GetLastError());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        if (!UnmapViewOfFile(*(HMODULE*)this))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            fprintf(stdout, "Couldn't unmap the file! - error-code=%lu", GetLastError());
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
    }
    FUN_14092e190((HMODULE*)this);
}

// @0x14092ce80
bool Unk_NexonAnalytics::FUN_14092ce80(const Unk_NxString* pVersion, const Unk_NxString* pHost)
{
    if (!FUN_14092edf0((HMODULE*)this))
        return false;
    return ((PFN_NxaPresetString)s_pfn_presetNxLogVersion)(pVersion)
        && ((PFN_NxaPresetString)s_pfn_presetLogServerAddress)(pHost);
}

// @0x14092cf80
bool Unk_NexonAnalytics::FUN_14092cf80(const Unk_NxEvent* pEvent, const Unk_NxString* pHost,
                                       const Unk_NxNumber* pService)
{
    if (!FUN_14092edf0((HMODULE*)this))
        return false;
    {
        Unk_NxString kClass(FUN_14092ed50(), 3);
        Unk_NxString kBase(FUN_14092ed60(), 3);
        ((PFN_NxaPresetBaseClassVersion)s_pfn_presetBaseClassVersion)(&kBase, &kClass);
    }
    return ((PFN_NxaInitializeClientModuleEx)s_pfn_initializeClientModuleEx)(pEvent, pHost, pService);
}

// @0x14092d070
void Unk_NexonAnalytics::FUN_14092d070(bool bFlush)
{
    if (!FUN_14092edf0((HMODULE*)this))
        return;
    ((PFN_NxaFinalizeModule)s_pfn_finalizeModule)(bFlush);
}

// @0x14092d150
static bool FUN_14092d150(HMODULE* ppModule, int nCode, const Unk_NxString* pLog)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return ((PFN_NxaEnqueueLog)s_pfn_enqueueStageLog)(nCode, pLog);
}

// @0x14092d1a0
static bool FUN_14092d1a0(HMODULE* ppModule, int nCode, const Unk_NxString* pLog)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return ((PFN_NxaEnqueueLog)s_pfn_enqueueErrorLog)(nCode, pLog);
}

// @0x14092d1f0
bool Unk_NexonAnalytics::FUN_14092d1f0(int nCode, const CStringA& strLog)
{
    Unk_NxString kLog((const char*)strLog, 3);
    return FUN_14092d150((HMODULE*)this, nCode, &kLog);
}

// @0x14092d280
bool Unk_NexonAnalytics::FUN_14092d280(int nCode, const CStringA& strLog)
{
    Unk_NxString kLog((const char*)strLog, 3);
    return FUN_14092d1a0((HMODULE*)this, nCode, &kLog);
}

// ---- the other export wrappers (the game calls none of them) ----

// Loads the DLL and resolves its exports.
// @0x14092cb30
bool FUN_14092cb30(HMODULE* ppModule, LPCWSTR pszPath)
{
    if (FUN_14092edf0(ppModule))
        return true;
    *ppModule = LoadLibraryW(pszPath);
    if (*ppModule == NULL) {
        DWORD dwError = GetLastError();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
        ms2_fwprintf_nxa(stdout, L"DLL \xd30c\xc77c\xc744 \xb85c\xb4dc\xd558\xc9c0 \xbabb\xd588\xc2b5\xb2c8\xb2e4. "
                L"- module-path=\"%ls\", error-code=%lu", pszPath, dwError);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return false;
    }
    return FUN_14092d8f0(ppModule);
}

#define NXA_CALL(type, slot) ((type)s_pfn_##slot)

// @0x14092cd10
void FUN_14092cd10(HMODULE* ppModule, const Unk_NxString* pDir)
{
    if (!FUN_14092edf0(ppModule))
        return;
    NXA_CALL(void (*)(const Unk_NxString*), presetWorkingDirectory)(pDir);
}

// @0x14092cd50
bool FUN_14092cd50(HMODULE* ppModule, const Unk_NxString* pVersion)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(PFN_NxaPresetString, presetNxLogVersion)(pVersion);
}

// @0x14092cd90
bool FUN_14092cd90(HMODULE* ppModule, const Unk_NxString* pHost)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(PFN_NxaPresetString, presetConfigServerAddress)(pHost);
}

// @0x14092cdd0
bool FUN_14092cdd0(HMODULE* ppModule, const Unk_NxString* pHost)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(PFN_NxaPresetString, presetLogServerAddress)(pHost);
}

// @0x14092ce10
void FUN_14092ce10(HMODULE* ppModule, const Unk_NxNumber* pLimit)
{
    if (!FUN_14092edf0(ppModule))
        return;
    NXA_CALL(void (*)(const Unk_NxNumber*), presetBackupFileLimit)(pLimit);
}

// @0x14092ce50
void FUN_14092ce50(HMODULE* ppModule)
{
    if (!FUN_14092edf0(ppModule))
        return;
    NXA_CALL(void (*)(), presetSystemInfoLogOff)();
}

// FUN_14092cf80 with an empty host.
// @0x14092cef0
bool FUN_14092cef0(Unk_NexonAnalytics* pAnalytics, const Unk_NxEvent* pEvent, const Unk_NxNumber* pService)
{
    Unk_NxString kHost(NULL, 3);
    return pAnalytics->FUN_14092cf80(pEvent, &kHost, pService);
}

// @0x14092d0b0
bool FUN_14092d0b0(HMODULE* ppModule, const void* p1, const void* p2)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(bool (*)(const void*, const void*), updateUser)(p1, p2);
}

// @0x14092d100
bool FUN_14092d100(HMODULE* ppModule, const void* p1, const void* p2, const void* p3)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(bool (*)(const void*, const void*, const void*), setUserExtraInfo)(p1, p2, p3);
}

// @0x14092d310
bool FUN_14092d310(HMODULE* ppModule, const void* p1, const void* p2)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(bool (*)(const void*, const void*), enqueueLogOnlyOnce)(p1, p2);
}

// @0x14092d360
bool FUN_14092d360(HMODULE* ppModule, const void* p)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(bool (*)(const void*), enqueueNxLog)(p);
}

// @0x14092d3a0
bool FUN_14092d3a0(HMODULE* ppModule, const void* p1, const void* p2)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(bool (*)(const void*, const void*), enqueueLog)(p1, p2);
}

// @0x14092d3f0
bool FUN_14092d3f0(HMODULE* ppModule, const void* p)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(bool (*)(const void*), enqueueJsonLog)(p);
}

// @0x14092d430
bool FUN_14092d430(HMODULE* ppModule, int nLevel, const void* p)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(bool (*)(int, const void*), enqueueDevLog)(nLevel, p);
}

// @0x14092d480
bool FUN_14092d480(HMODULE* ppModule, const void* p)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(bool (*)(const void*), enqueueSystemInfoLog)(p);
}

// @0x14092d4c0
bool FUN_14092d4c0(HMODULE* ppModule, const void* p1, const void* p2)
{
    if (!FUN_14092edf0(ppModule))
        return false;
    return NXA_CALL(bool (*)(const void*, const void*), assignInfoUser)(p1, p2);
}

// @0x14092d510
const char* FUN_14092d510(HMODULE* ppModule, const char* pszField)
{
    if (!FUN_14092edf0(ppModule))
        return NULL;
    return NXA_CALL(const char* (*)(const char*), getCommonFieldA)(pszField);
}

// @0x14092d550
const wchar_t* FUN_14092d550(HMODULE* ppModule, const wchar_t* pszField)
{
    if (!FUN_14092edf0(ppModule))
        return NULL;
    return NXA_CALL(const wchar_t* (*)(const wchar_t*), getCommonFieldW)(pszField);
}

// @0x14092d590
const char* FUN_14092d590(HMODULE* ppModule)
{
    if (!FUN_14092edf0(ppModule))
        return NULL;
    return NXA_CALL(const char* (*)(), getAccountNoA)();
}

// @0x14092d5c0
const wchar_t* FUN_14092d5c0(HMODULE* ppModule)
{
    if (!FUN_14092edf0(ppModule))
        return NULL;
    return NXA_CALL(const wchar_t* (*)(), getAccountNoW)();
}

// @0x14092d5f0
const char* FUN_14092d5f0(HMODULE* ppModule)
{
    if (!FUN_14092edf0(ppModule))
        return NULL;
    return NXA_CALL(const char* (*)(), getSessionIdA)();
}

// @0x14092d620
const wchar_t* FUN_14092d620(HMODULE* ppModule)
{
    if (!FUN_14092edf0(ppModule))
        return NULL;
    return NXA_CALL(const wchar_t* (*)(), getSessionIdW)();
}

// @0x14092d650
const char* FUN_14092d650(HMODULE* ppModule)
{
    if (!FUN_14092edf0(ppModule))
        return NULL;
    return NXA_CALL(const char* (*)(), getMachineIdA)();
}

// @0x14092d680
const wchar_t* FUN_14092d680(HMODULE* ppModule)
{
    if (!FUN_14092edf0(ppModule))
        return NULL;
    return NXA_CALL(const wchar_t* (*)(), getMachineIdW)();
}

// 1001 when the DLL is not loaded, 0 when it has no getLastError.
// @0x14092d6b0
int FUN_14092d6b0(HMODULE* ppModule)
{
    if (!FUN_14092edf0(ppModule))
        return 0x3e9;
    int nError;
    if (s_pfn_getLastError != NULL)
        nError = NXA_CALL(int (*)(), getLastError)();
    else
        nError = 0;
    return nError;
}

// @0x14092d700
void FUN_14092d700(HMODULE* ppModule, int nLevel)
{
    if (!FUN_14092edf0(ppModule))
        return;
    NXA_CALL(void (*)(int), setDevLogLevel)(nLevel);
}

// @0x14092d740
void FUN_14092d740(HMODULE* ppModule, bool bActive)
{
    if (!FUN_14092edf0(ppModule))
        return;
    NXA_CALL(void (*)(bool), setActiveInputLog)(bActive);
}

// @0x14092d780
void FUN_14092d780(HMODULE* ppModule, HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (!FUN_14092edf0(ppModule))
        return;
    NXA_CALL(void (*)(HWND, UINT, WPARAM, LPARAM), inputProc)(hWnd, uMsg, wParam, lParam);
}

// @0x14092d7d0
void FUN_14092d7d0(HMODULE* ppModule, unsigned short nLevel)
{
    if (!FUN_14092edf0(ppModule))
        return;
    NXA_CALL(void (*)(unsigned short), setInputLogLevel)(nLevel);
}

// @0x14092d810
void FUN_14092d810(HMODULE* ppModule, const void* p1, const void* p2)
{
    if (!FUN_14092edf0(ppModule))
        return;
    NXA_CALL(void (*)(const void*, const void*), enqueueInputAction)(p1, p2);
}

// @0x14092d860
void FUN_14092d860(HMODULE* ppModule, const void* p1, int n1, int n2, const void* p2)
{
    if (!FUN_14092edf0(ppModule))
        return;
    NXA_CALL(void (*)(const void*, int, int, const void*), registerKeymapInfo)(p1, n1, n2, p2);
}

// Makes the DLL's pool allocator the current one.
// @0x14092d8b0
void FUN_14092d8b0(HMODULE* ppModule)
{
    if (!FUN_14092edf0(ppModule))
        return;
    FUN_14092ecb0(NXA_CALL(nxa::MemoryAllocator* (*)(), getPoolAllocator)());
}

// An empty function of one int (ICF-shared with the crash reporter's caller).
// @0x14092f2c0
void FUN_14092f2c0(int) {}

// @0x14092f3f0
void* FUN_14092f3f0(void* p) { return p; }

// @0x14092f410
void FUN_14092f410(void*) {}

MS2_EMIT_CRT_MEMMOVE_S();
