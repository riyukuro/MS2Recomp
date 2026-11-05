// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The 12-byte three-int value (see unit_140267ba0.cpp and
// unit_140267e40.cpp): its sum, per-slot add / get, and the conversion from and to an int array. Names invented.
// MS2-UNIT: unit_140267c10
// MS2-RANGE: 0x140267c10-0x140267e40 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140267c10.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"

// An int array (a CAtlArray<int>-shaped object: data, size, capacity, grow-by).
struct Unk_IntArr { void* m_p; unsigned __int64 m_n; unsigned __int64 m_max; int m_nGrow; };
void FUN_1402237c0(struct Unk_LevelArray*);   // C3: was FUN_1402237c0

class Unk_IntTriple;
// (Get() calls Sum() directly: Get returns int, so the sum is not widened.)

class Unk_IntTriple
{
public:
    int Sum();                                              // 0x140267c10
    void Add(int nIndex, int nValue);                       // 0x140267c70
    void ReadArray(Unk_IntArr* pArr);                       // 0x140267d00
    int Get(int nIndex);                                    // 0x140267d70 (3: the sum)
    void WriteArray(Unk_IntArr* pArr);                      // 0x140267dc0
    int m_v[3];
};
MS2_CHECK_SIZE(Unk_IntTriple, 0xc);

// @0x140267c10
int Unk_IntTriple::Sum()
{
    int nSum = 0;
    for (int i = 0; i < 3; ++i) {
        nSum = nSum + m_v[i];
    }
    return nSum;
}

// @0x140267c70
void Unk_IntTriple::Add(int nIndex, int nValue)
{
    if (nIndex < 0 || nIndex >= 3)
        return;
    m_v[nIndex] = m_v[nIndex] + nValue;
}

// @0x140267d00
void Unk_IntTriple::ReadArray(Unk_IntArr* pArr)
{
    if (reinterpret_cast<ATL::CAtlArray<int>*>(pArr)->GetCount() != 3)
        return;
    for (int i = 0; i < 3; ++i) {
        m_v[i] = (*reinterpret_cast<ATL::CAtlArray<int>*>(pArr))[i];
    }
}

// @0x140267d70
int Unk_IntTriple::Get(int nIndex)
{
    if (nIndex < 0 || 3 < nIndex)
        return 0;
    if (nIndex == 3)
        return Sum();
    return m_v[nIndex];
}

// @0x140267dc0
void Unk_IntTriple::WriteArray(Unk_IntArr* pArr)
{
    FUN_1402237c0((struct Unk_LevelArray*)(pArr));
    reinterpret_cast<ATL::CAtlArray<int>*>(pArr)->SetCount(3, -1);
    for (int i = 0; i < 3; ++i) {
        (*reinterpret_cast<ATL::CAtlArray<int>*>(pArr))[i] = m_v[i];
    }
}
