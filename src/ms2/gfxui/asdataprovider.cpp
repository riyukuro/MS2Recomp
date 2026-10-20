// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASDataProvider, the C++ wrapper of a CLIK
// scaleform.clik.data.DataProvider (the data of the list components). Declared in placeholder/asobj.h.
// MS2-UNIT: ?\asdataprovider.cpp
// MS2-RANGE: 0x1422deec0-0x1422df570 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asevent.h"
#include "hook/ms2hook.h"

using Scaleform::GFx::Value;

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);            // the GFx movie of a movie id (null if not loaded)

// @0x1422deec0
ASDataProvider::ASDataProvider(int nMovieId)
    : ASArray(nMovieId)
{
    m_value.SetNull();
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie)
        pMovie->CreateObject(&m_value, "scaleform.clik.data.DataProvider", 0, 0);
}

// @0x1422def60
ASDataProvider::ASDataProvider(MS2Ptr<ASArray> spArr, int nMovieId)
    : ASArray(nMovieId)
{
    m_value.SetNull();
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie)
        pMovie->CreateObject(&m_value, "scaleform.clik.data.DataProvider", &spArr->FUN_1422bb870(), 1);
}

// @0x1422df020
ASDataProvider::ASDataProvider(Value& v, int nMovieId)
    : ASArray(v, nMovieId)
{
}

// @0x1422df070
ASDataProvider::~ASDataProvider()
{
}

// @0x1422df0a0
void ASDataProvider::FUN_1422df0a0()
{
    Invoke("cleanUp");
}

// @0x1422df0e0
void ASDataProvider::FUN_1422df0e0(unsigned int nIndex)
{
    Invoke("invalidate", nIndex);
}

// @0x1422df120
void ASDataProvider::FUN_1422df120()
{
    FUN_1422df0a0();
}

// @0x1422df140
AScript ASDataProvider::FUN_1422df140(unsigned nIndex)
{
    Value vItem = Invoke("requestItemAt", nIndex);
    return AScript(vItem, 2);
}

// @0x1422df1c0
void ASDataProvider::FUN_1422df1c0(const CString& strType, const Value& listener, int bUseCapture, int nPriority,
                                   int bUseWeakReference)
{
    Invoke("addEventListener", strType, listener, bUseCapture != 0, (float)nPriority, bUseWeakReference != 0);
}

// @0x1422df2e0
void ASDataProvider::FUN_1422df2e0(const CString& strType, const Value& listener, int bUseCapture)
{
    Invoke("removeEventListener", strType, listener, bUseCapture != 0);
}

// @0x1422df3c0
int ASDataProvider::FUN_1422df3c0(const CString& strType)
{
    return Invoke("hasEventListener", strType).GetBool();
}

// @0x1422df460
int ASDataProvider::FUN_1422df460(const CString& strType)
{
    return Invoke("willTrigger", strType).GetBool();
}

// @0x1422df500
int ASDataProvider::FUN_1422df500(const ASEvent& ev)
{
    return Invoke("dispatchEvent", ev).GetBool();
}

MS2_REPLACE_METHOD(0x1422DF0A0, ASDataProvider, FUN_1422df0a0, 46, 0x069C2862);
MS2_REPLACE_METHOD(0x1422DF0E0, ASDataProvider, FUN_1422df0e0, 55, 0xC931B1E6);
MS2_REPLACE_METHOD(0x1422DF120, ASDataProvider, FUN_1422df120, 24, 0xF2B3A7E6);
MS2_REPLACE_METHOD(0x1422DF140, ASDataProvider, FUN_1422df140, 116, 0x763C1F1C);
MS2_REPLACE_METHOD(0x1422DF1C0, ASDataProvider, FUN_1422df1c0, 269, 0xB7A43C7D);
MS2_REPLACE_METHOD(0x1422DF2E0, ASDataProvider, FUN_1422df2e0, 205, 0x9E62B1BD);
MS2_REPLACE_METHOD(0x1422DF3C0, ASDataProvider, FUN_1422df3c0, 144, 0x206A513A);
MS2_REPLACE_METHOD(0x1422DF460, ASDataProvider, FUN_1422df460, 144, 0x176B18DB);
MS2_REPLACE_METHOD(0x1422DF500, ASDataProvider, FUN_1422df500, 101, 0x4781D10C);
