// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A string that is split into parts at construction (a name
// plus a delimiter list), with an int-to-int map beside it. Unit and member names are invented from use.
// MS2-UNIT: unit_1408d1c50
// MS2-RANGE: 0x1408d1c50-0x1408d1ec0 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// A CAtlArray<CStringW> (data, size, capacity, grow-by; ctor 0x140163270).
struct Unk_SsParts { void* m_p; unsigned __int64 m_n; unsigned __int64 m_max; int m_nGrow; };
Unk_SsParts* FUN_140163270(Unk_SsParts* pArr);
// A CAtlMap<int, int> (ctor 0x140163400 with the ATL defaults: 17 bins, load 0.75/0.25/2.25, block size 10).
struct Unk_SsMap { char m_data[0x50]; };
Unk_SsMap* FUN_140163400(Unk_SsMap* pMap, unsigned nBins, float fOptimal, float fLow, float fHigh, unsigned nBlock);
void FUN_14016a050(Unk_SsMap* pMap, int nKey, int nValue);
// Splits the string at the delimiters into the array (CStringW::Tokenize loop).
void FUN_14025a680(CStringW& strSource, Unk_SsParts* pOut, const wchar_t* pszDelims);

class Unk_SplitStr
{
public:
    Unk_SplitStr(CStringW strName, CStringW strDelims);                         // 0x1408d1c50
    void FUN_1408d1d80(CStringW strName, CStringW strDelims);                   // sets the name and splits it
    void FUN_1408d1e00(CStringW strName, CStringW strDelims);                   // the same body as 0x1408d1d80
    void FUN_1408d1e80(int nKey, int nValue);                                   // map insert

    CStringW m_strName;             // +0x00
    Unk_SsParts m_parts;            // +0x08
    Unk_SsMap m_map;                // +0x28
};

// @0x1408d1c50
// MS2-FUNCTIONAL: the exe members (CAtlArray, CAtlMap) have destructors, so two more unwind states; behaviour-equivalent
Unk_SplitStr::Unk_SplitStr(CStringW strName, CStringW strDelims)
    : m_strName(strName)
{
    FUN_140163270(&m_parts);
    FUN_140163400(&m_map, 0x11, 0.75f, 0.25f, 2.25f, 10);
    FUN_1408d1e00(CStringW(strName), CStringW(strDelims));
}

// @0x1408d1d80
void Unk_SplitStr::FUN_1408d1d80(CStringW strName, CStringW strDelims)
{
    m_strName = strName;
    FUN_14025a680(strName, &m_parts, strDelims);
}

// @0x1408d1e00
void Unk_SplitStr::FUN_1408d1e00(CStringW strName, CStringW strDelims)
{
    m_strName = strName;
    FUN_14025a680(strName, &m_parts, strDelims);
}

// @0x1408d1e80
void Unk_SplitStr::FUN_1408d1e80(int nKey, int nValue)
{
    FUN_14016a050(&m_map, nKey, nValue);
}
MS2_REPLACE_METHOD(0x1408D1E80, Unk_SplitStr, FUN_1408d1e80, 49, 0x1F2F4EBD);
