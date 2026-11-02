// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A string that is split into parts at construction (a name
// plus a delimiter list), with an int-to-int map beside it. Unit and member names are invented from use.
// MS2-UNIT: unit_1408d1c50
// MS2-RANGE: 0x1408d1c50-0x1408d1ec0 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <atlcoll.h>

// Splits the string at the delimiters into the array (CStringW::Tokenize loop).
void FUN_14025a680(CStringW& strSource, ATL::CAtlArray<CStringW>& out, const wchar_t* pszDelims);

class Unk_SplitStr
{
public:
    Unk_SplitStr(CStringW strName, CStringW strDelims);                         // 0x1408d1c50
    void FUN_1408d1d80(CStringW strName, CStringW strDelims);                   // sets the name and splits it
    void FUN_1408d1e00(CStringW strName, CStringW strDelims);                   // the same body as 0x1408d1d80
    void FUN_1408d1e80(int nKey, int nValue);                                   // map insert

    CStringW m_strName;             // +0x00
    ATL::CAtlArray<CStringW> m_parts;   // +0x08
    ATL::CAtlMap<unsigned int, int> m_map;  // +0x28
};

// @0x1408d1c50
Unk_SplitStr::Unk_SplitStr(CStringW strName, CStringW strDelims)
    : m_strName(strName)
{
    FUN_1408d1e00(CStringW(strName), CStringW(strDelims));
}

// @0x1408d1d80
void Unk_SplitStr::FUN_1408d1d80(CStringW strName, CStringW strDelims)
{
    m_strName = strName;
    FUN_14025a680(strName, m_parts, strDelims);
}

// @0x1408d1e00
void Unk_SplitStr::FUN_1408d1e00(CStringW strName, CStringW strDelims)
{
    m_strName = strName;
    FUN_14025a680(strName, m_parts, strDelims);
}

// @0x1408d1e80
void Unk_SplitStr::FUN_1408d1e80(int nKey, int nValue)
{
    m_map.SetAt(nKey, nValue);
}
MS2_REPLACE_METHOD(0x1408D1E80, Unk_SplitStr, FUN_1408d1e80, 49, 0x1F2F4EBD);
