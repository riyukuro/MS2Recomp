// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Enum helpers that follow commonenum.cpp: the feature-gated level / grade
// tables (level <-> bitmask, grade and event names), small int enum maps, a shared-memory mapping wrapper and the CAtlArray glue
// of a 4-byte enum array. File and function names are invented (no __FILE__ string in the range).
// MS2-UNIT: unit_1402226b0
// MS2-RANGE: 0x1400b53d0-0x1400b54f0 .text$di
// MS2-RANGE: 0x1402226b0-0x140223c60 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_1402226b0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <windows.h>
#include <errno.h>

static CString s_marketSortNames[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CString s_emptyNarrow;
static CStringW s_emptyWide;

// ---- unit-local placeholders (names invented) --------------------------------------------------------------------------
// One entry of the level array (an int; its own type so the array instantiations are not shared with CAtlArray<int>).
enum Unk_LevelEntry { Unk_LevelEntry_None = 0 };

// An int array of unrecovered class: CAtlArray layout (data, count, allocated, grow-by); its Add / SetCount live elsewhere.
struct Unk_LevelArray
{
    void* m_pData;
    size_t m_nSize;
    size_t m_nMaxSize;
    int m_nGrowBy;
    int m_pad_1c;
    void FUN_1401854f0(int nLevel);                     // Add
};

// A handle to a state record (0x10 bytes; unrecovered class, passed by value so the callee runs its destructor): +8 holds the record.
struct Unk_StateHandle
{
    void* m_pad_00;
    void* m_pRecord;                                    // +0x08
    ~Unk_StateHandle();                                 // 0x1401b50d0
    bool FUN_1401b5240(void* pCmp) const;               // the record equals pCmp
    void* FUN_1401b52a0() const;                        // the record
};
void* FUN_140166410();                                  // the feature settings
bool FUN_14036d570(void* pFeatures, int nFeature);      // the feature is switched on
bool FUN_14053cf90(void* pRecord);
bool FUN_14053d600(void* pRecord);
bool FUN_14053d5c0(void* pRecord);
bool FUN_14053d2f0(void* pRecord);                      // the record has work pending
void FUN_1401b6710(Unk_LevelArray* p, size_t nCount, int nGrowBy);   // SetCount

extern const int DAT_142cf60e0[12];                     // the level-limit ids

// 0x30 bytes: a named file mapping and its view.
struct Unk_SharedMemory
{
    HANDLE m_hMap;                                      // +0x00
    char m_szName[32];                                  // +0x08
    void* m_pView;                                      // +0x28
    Unk_SharedMemory(const char* pszName, DWORD nSize); // 0x140223990
    void FUN_140223a90();                               // closes the view and the mapping
    char FUN_140223b00() const;
};

// @0x1402226b0
// The level limit is available on this server (feature-gated at 1, 90, 100, 110).
bool FUN_1402226b0(int nLevel)
{
    switch (nLevel) {
    case 1:
        return FUN_14036d570(FUN_140166410(), 0xe7);
    case 10: case 20: case 30: case 40: case 50: case 60: case 70: case 80:
        return true;
    case 90:
        return FUN_14036d570(FUN_140166410(), 8);
    case 100:
        return FUN_14036d570(FUN_140166410(), 0x12);
    case 110:
        return FUN_14036d570(FUN_140166410(), 0x25);
    }
    return false;
}

// @0x1402227e0
// The level as a bit of the level mask (200 or bAll: every bit).
int FUN_1402227e0(int nLevel, int bAll)
{
    if (nLevel == 200 || bAll != 0)
        return 0xfff;
    switch (nLevel) {
    case 1: return 1;
    case 10: return 2;
    case 20: return 4;
    case 30: return 8;
    case 40: return 0x10;
    case 50: return 0x20;
    case 60: return 0x40;
    case 70: return 0x80;
    case 80: return 0x100;
    case 90: return 0x200;
    case 100: return 0x400;
    case 110: return 0x800;
    default: return 0;
    }
}

// @0x140222940
// The level of a bit of the level mask.
int FUN_140222940(int nBit)
{
    switch (nBit) {
    case 1: return 1;
    case 2: return 10;
    case 4: return 20;
    case 8: return 30;
    case 0x10: return 40;
    case 0x20: return 50;
    case 0x40: return 60;
    case 0x80: return 70;
    case 0x100: return 80;
    case 0x200: return 90;
    case 0x400: return 100;
    case 0x800: return 110;
    default: return 1;
    }
}

bool FUN_140223750(Unk_LevelArray* p);
void FUN_1402237c0(Unk_LevelArray* p);

// @0x140222a70
// Fills pLevels with the level of every bit set in the mask; true when any.
bool FUN_140222a70(unsigned nMask, Unk_LevelArray* pLevels)
{
    FUN_1402237c0(pLevels);
    int nMax = 12;
    for (int i = 0; i < nMax; i++) {
        unsigned nBit = 1 << i;
        if ((nMask & nBit) != 0)
            pLevels->FUN_1401854f0(FUN_140222940(nBit));
    }
    return !FUN_140223750(pLevels);
}

// @0x140222b30
int FUN_140222b30(int n, int bAll)
{
    if (n == 2 || bAll != 0)
        return 3;
    switch (n) {
    case 0: return 1;
    case 1: return 2;
    }
    return 0;
}

// @0x140222b90
int FUN_140222b90(int n)
{
    if (n == 3)
        return 2;
    switch (n) {
    case 1: return 0;
    case 2: return 1;
    }
    return 3;
}

// @0x140222be0
// Refills the array with the available level limits.
void FUN_140222be0(ATL::CAtlArray<Unk_LevelEntry>& aLevels)
{
    aLevels.RemoveAll();
    for (size_t i = 0; i < 12; i++) {
        Unk_LevelEntry e = (Unk_LevelEntry)DAT_142cf60e0[i];
        if (!FUN_1402226b0((int)e))
            continue;
        aLevels.Add(e);
    }
}

// @0x140222c60
bool FUN_140222c60(unsigned n)
{
    switch (n) {
    case 0x1e: case 0x1f: case 0x20: case 0x21: case 0x22:
    case 0x28: case 0x29:
    case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38:
        return true;
    default:
        return false;
    }
}

// @0x140222ce0
// The state code of a record (0 none, 8, 1 work pending, 2, 4, else 0xf).
unsigned FUN_140222ce0(Unk_StateHandle h)
{
    if (h.FUN_1401b5240(0))
        return 0;
    if (FUN_14053cf90(h.FUN_1401b52a0()))
        return 8;
    if (FUN_14053d2f0(h.FUN_1401b52a0()))
        return 1;
    if (FUN_14053d600(h.FUN_1401b52a0()))
        return 2;
    if (FUN_14053d5c0(h.FUN_1401b52a0()))
        return 4;
    return 0xf;
}

// @0x140222e10
// The grade slot is available (feature-gated).
bool FUN_140222e10(int n)
{
    switch (n) {
    case 1: case 3: case 4:
        return true;
    case 5: return FUN_14036d570(FUN_140166410(), 0x67);
    case 6: return FUN_14036d570(FUN_140166410(), 0x68);
    case 2: return FUN_14036d570(FUN_140166410(), 0x66);
    case 7: return FUN_14036d570(FUN_140166410(), 0x69);
    case 8: return FUN_14036d570(FUN_140166410(), 0x6a);
    case 9: return FUN_14036d570(FUN_140166410(), 0x9d);
    case 10: return FUN_14036d570(FUN_140166410(), 0x6b);
    case 11: return FUN_14036d570(FUN_140166410(), 0x6c);
    case 12: return FUN_14036d570(FUN_140166410(), 0x6d);
    }
    return false;
}

// @0x140222f50
int FUN_140222f50()
{
    return 0xc;
}

// @0x140222f60
int FUN_140222f60(int n)
{
    switch (n) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    }
    return 6;
}

// @0x140222fb0
int FUN_140222fb0(int n)
{
    if (n > 2)
        return 0;
    if (n == 2)
        return 3;
    if (n == 1)
        return 2;
    return 1;
}

// @0x140222ff0
int FUN_140222ff0(const int* p)
{
    switch (*p) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 3;
    }
    return 0;
}

// @0x140223040
// The English name of an item grade.
CString FUN_140223040(int nGrade)
{
    if (nGrade == 1)
        return CString("Normal");
    if (nGrade == 2)
        return CString("Rare");
    if (nGrade == 3)
        return CString("Elite");
    if (nGrade == 4)
        return CString("Excellent");
    if (nGrade == 5)
        return CString("Legendary");
    if (nGrade == 6)
        return CString("Artifact");
    return CString("Unknown");
}

// @0x140223190
// The name of a user command kind.
CString FUN_140223190(int nKind)
{
    switch (nKind) {
    case 0: return CString("jump");
    case 1: return CString("climb");
    case 2: return CString("skill");
    case 3: return CString("playInstrument");
    case 4: return CString("potion");
    case 5: return CString("ride_ground");
    case 6: return CString("ride_air");
    case 7: return CString("pet_summon");
    case 8: return CString("revival_here");
    default: return CString("unknown");
    }
}

// @0x140223380
// The name of a match result.
CString FUN_140223380(int nResult)
{
    switch (nResult) {
    case 0: return CString("draw");
    case 1: return CString("win");
    case 2: return CString("lose");
    }
    return CString("none");
}

// @0x140223750
bool FUN_140223750(Unk_LevelArray* p)
{
    return p->m_nSize == 0;
}

// @0x1402237c0
void FUN_1402237c0(Unk_LevelArray* p)
{
    FUN_1401b6710(p, 0, -1);
}

// @0x140223990
Unk_SharedMemory::Unk_SharedMemory(const char* pszName, DWORD nSize)
{
    memset(m_szName, 0, sizeof(m_szName));
    m_pView = 0;
    memcpy(m_szName, pszName, strlen(pszName));
    m_hMap = CreateFileMappingA(INVALID_HANDLE_VALUE, 0, PAGE_READWRITE, 0, nSize, pszName);
    if (m_hMap != 0)
        m_pView = MapViewOfFile(m_hMap, FILE_MAP_WRITE, 0, 0, 0);
}

// @0x140223a90
void Unk_SharedMemory::FUN_140223a90()
{
    if (m_pView != 0)
        UnmapViewOfFile(m_pView);
    m_pView = 0;
    if (m_hMap != 0)
        CloseHandle(m_hMap);
    m_hMap = 0;
}

// @0x140223b00
char Unk_SharedMemory::FUN_140223b00() const
{
    int bOk;
    if (m_pView != 0 && m_pView != 0)
        bOk = 1;
    else
        bOk = 0;
    return bOk;
}

// @0x140223b40
// memcpy_s (the CRT's _VALIDATE_RETURN_ERRCODE form).
#define MS2_VALIDATE_ERRCODE(expr, err) { int nExprVal = !!(expr); if (!nExprVal) { *_errno() = err; _invalid_parameter_noinfo(); return err; } }
int FUN_140223b40(void* pDst, size_t nDstSize, const void* pSrc, size_t nCount)
{
    if (nCount == 0)
        return 0;
    MS2_VALIDATE_ERRCODE(pDst != 0, EINVAL);
    MS2_VALIDATE_ERRCODE(pSrc != 0, EINVAL);
    MS2_VALIDATE_ERRCODE(nDstSize >= nCount, ERANGE);
    memmove(pDst, pSrc, nCount);
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9a340-0x142c9a3b0 .text$yd
