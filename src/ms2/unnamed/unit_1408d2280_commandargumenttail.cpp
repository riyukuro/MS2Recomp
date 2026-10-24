// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Tail of the Unk_CommandArgs accessor set (see
// unit_1408d1ec0.cpp): the word-as-double / word-as-float readers (_wtof), the raw-text copy getter, the word count and
// this TU's copy of the CRT memmove_s.
// MS2-UNIT: unit_1408d2280
// MS2-RANGE: 0x1408d2280-0x1408d24c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <stdlib.h>

#include "ms2/ms2recover.h"

// Same argument block as unit_1408d1ec0.cpp (+0x00 raw text, +0x08 word list); the int table at +0x28 is not touched here.
struct Unk_CommandArgs
{
    CStringW text;                                  // +0x00 the raw argument text
    ATL::CAtlArray<CStringW> words;                 // +0x08 the whitespace-split arguments
    ATL::CAtlMap<int, int> values;                  // +0x28 the int key/value table

    float FUN_1408d2280(unsigned nIndex, float fDefault);       // word n as float
    double FUN_1408d22c0(unsigned nIndex, double dDefault);     // word n as double (_wtof)
    CStringW FUN_1408d2330();                                   // copy of the raw text
    unsigned FUN_1408d2380();                                   // the argument count
};
MS2_CHECK_SIZE(Unk_CommandArgs, 0x70);

// @0x1408d2280
float Unk_CommandArgs::FUN_1408d2280(unsigned nIndex, float fDefault)
{
    return (float)FUN_1408d22c0(nIndex, fDefault);
}

// @0x1408d22c0
double Unk_CommandArgs::FUN_1408d22c0(unsigned nIndex, double dDefault)
{
    if (nIndex >= ((const ATL::CAtlArray<CStringW>&)words).GetCount())
        return dDefault;
    return _wtof(((const ATL::CAtlArray<CStringW>&)words).GetAt(nIndex));
}

// @0x1408d2330
CStringW Unk_CommandArgs::FUN_1408d2330()
{
    return text;
}

// @0x1408d2380
unsigned Unk_CommandArgs::FUN_1408d2380()
{
    return (unsigned)words.GetCount();
}

// @0x1408d23a0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
