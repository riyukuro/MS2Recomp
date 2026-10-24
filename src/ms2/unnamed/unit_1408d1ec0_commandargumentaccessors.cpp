// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unk_CommandArgs / ItemFunctionArgs: the argument block of a
// chat command (usercommandcli.cpp) / item function call (itemfunction.cpp) - 0x70 bytes holding the raw text, the
// whitespace-split words and the int key/value table. This unit is its accessor set: the table lookup pair (an
// anonymous bool + int wrapper) plus the six typed word accessors, which read word `nIndex` through the CRT's
// string-to-number conversions (_wtoi / _wtol / _wtoi64) and fall back to a caller-supplied default when the index is
// past the end of the word list. The exe folds the (int, int) ItemFunctionArgs::FUN_1408d1fd0 copy into the
// (unsigned, int) Unk_CommandArgs one (0x1408d1fd0 carries both names).
// MS2-UNIT: unit_1408d1ec0
// MS2-RANGE: 0x1408d1ec0-0x1408d2280 .text$mn
// MS2-PIN: ?FUN_1408d1ec0@Unk_CommandArgs@@QEAA_NHPEAH@Z 0x1408d1ec0
// MS2-PIN: ?FUN_1408d1f10@Unk_CommandArgs@@QEAAHHH@Z 0x1408d1f10
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <stdlib.h>

#include "ms2/ms2recover.h"

// The command / item function argument block. `words` (+0x08) and `values` (+0x28) are proven by every accessor below;
// the word accessors call the *const* CAtlArray::GetAt (0x140164970, the exe's non-const copy at 0x140159a00 is not
// used here) and the table lookup is CAtlMap::Lookup (0x140361ab0).
struct Unk_CommandArgs
{
    CStringW text;                                  // +0x00 the raw argument text
    ATL::CAtlArray<CStringW> words;                 // +0x08 the whitespace-split arguments
    ATL::CAtlMap<int, int> values;                  // +0x28 the int key/value table

    bool FUN_1408d1ec0(int nKey, int* pnValue);                 // +0x1408d1ec0 lookup with an out value
    int FUN_1408d1f10(int nKey, int nDefault);                  // +0x1408d1f10 lookup with a default
    int FUN_1408d1f60(unsigned nIndex, int nDefault);           // word n as int (_wtoi)
    int FUN_1408d1fd0(unsigned nIndex, int nDefault);           // word n as int (_wtol)
    __int64 FUN_1408d2040(unsigned nIndex, __int64 nDefault);   // word n as __int64 (_wtoi64)
    unsigned FUN_1408d20b0(unsigned nIndex, unsigned nDefault); // word n > 0 as int
    bool FUN_1408d2140(unsigned nIndex, bool bDefault);         // word n > 0 as bool
    CStringW FUN_1408d21c0(int nIndex, CStringW strDefault);    // word n as string
};
MS2_CHECK_SIZE(Unk_CommandArgs, 0x70);
MS2_CHECK_OFFSET(Unk_CommandArgs, words, 0x08);
MS2_CHECK_OFFSET(Unk_CommandArgs, values, 0x28);

// @0x1408d1ec0
bool Unk_CommandArgs::FUN_1408d1ec0(int nKey, int* pnValue)
{
    if (values.Lookup(nKey, *pnValue))
        return true;
    return false;
}

// @0x1408d1f10
int Unk_CommandArgs::FUN_1408d1f10(int nKey, int nDefault)
{
    int nValue = 0;
    if (FUN_1408d1ec0(nKey, &nValue))
        return nValue;
    return nDefault;
}

// The exe reads the word list through its const accessors, hence the casts (a reference cast emits no code).
// @0x1408d1f60
int Unk_CommandArgs::FUN_1408d1f60(unsigned nIndex, int nDefault)
{
    if (nIndex >= ((const ATL::CAtlArray<CStringW>&)words).GetCount())
        return nDefault;
    return _wtoi(((const ATL::CAtlArray<CStringW>&)words).GetAt(nIndex));
}

// @0x1408d1fd0
int Unk_CommandArgs::FUN_1408d1fd0(unsigned nIndex, int nDefault)
{
    if (nIndex >= ((const ATL::CAtlArray<CStringW>&)words).GetCount())
        return nDefault;
    return _wtol(((const ATL::CAtlArray<CStringW>&)words).GetAt(nIndex));
}

// @0x1408d2040
__int64 Unk_CommandArgs::FUN_1408d2040(unsigned nIndex, __int64 nDefault)
{
    if (nIndex >= ((const ATL::CAtlArray<CStringW>&)words).GetCount())
        return nDefault;
    return _wtoi64(((const ATL::CAtlArray<CStringW>&)words).GetAt(nIndex));
}

// @0x1408d20b0
unsigned Unk_CommandArgs::FUN_1408d20b0(unsigned nIndex, unsigned nDefault)
{
    if (nIndex >= ((const ATL::CAtlArray<CStringW>&)words).GetCount())
        return nDefault;
    return _wtoi(((const ATL::CAtlArray<CStringW>&)words).GetAt(nIndex)) > 0;
}

// @0x1408d2140
bool Unk_CommandArgs::FUN_1408d2140(unsigned nIndex, bool bDefault)
{
    if (nIndex >= ((const ATL::CAtlArray<CStringW>&)words).GetCount())
        return bDefault;
    // The exe materialises the result in a 1-byte temp (a bare `return a > 0;` writes a 4-byte one).
    bool bValue;
    if (_wtoi(((const ATL::CAtlArray<CStringW>&)words).GetAt(nIndex)) > 0)
        bValue = true;
    else
        bValue = false;
    return bValue;
}

// @0x1408d21c0
CStringW Unk_CommandArgs::FUN_1408d21c0(int nIndex, CStringW strDefault)
{
    if ((unsigned)nIndex >= ((const ATL::CAtlArray<CStringW>&)words).GetCount())
        return strDefault;
    return ((const ATL::CAtlArray<CStringW>&)words).GetAt((unsigned)nIndex);
}
