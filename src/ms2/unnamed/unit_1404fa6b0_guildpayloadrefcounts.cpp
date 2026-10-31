// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_1404fa6b0: the reference-count
// instantiation tail of the intrusive guild-payload pointer (a 16-byte handle whose payload lives at +8).
// For each of the sixteen payload types the compiler emitted three out-of-line members: the public AddRef
// (null-guarded forward into the per-type AddRefImpl), that AddRefImpl (forwarding the payload into the
// per-type Reference) and Reference itself (the payload's AddRef slot 0x14015b020). One extra Reference is
// emitted for the season data handle. Emission order is by member kind, so the three blocks are contiguous.
// MS2-UNIT: unit_1404fa6b0
// MS2-RANGE: 0x1404fa6b0-0x1404faed0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

// the payload handle's AddRef slot, shared by every instantiation
class CPtred   // C3: member view for the former free stand-ins
{
public:
    static void AddRefPtred(class CPtred*);
};

void FUN_1404fabd0(void* pHandle, void* pUnused);
void FUN_1404fac00(void* pHandle, void* pUnused);
void FUN_1404fac30(void* pHandle, void* pUnused);
void FUN_1404fac60(void* pHandle, void* pUnused);
void FUN_1404fac90(void* pHandle, void* pUnused);
void FUN_1404facc0(void* pHandle, void* pUnused);
void FUN_1404facf0(void* pHandle, void* pUnused);
void FUN_1404fad20(void* pHandle, void* pUnused);
void FUN_1404fad50(void* pHandle, void* pUnused);
void FUN_1404fad80(void* pHandle, void* pUnused);
void FUN_1404fadb0(void* pHandle, void* pUnused);
void FUN_1404fade0(void* pHandle, void* pUnused);
void FUN_1404fae10(void* pHandle, void* pUnused);
void FUN_1404fae40(void* pHandle, void* pUnused);
void FUN_1404fae70(void* pHandle, void* pUnused);
void FUN_1404faea0(void* pHandle, void* pUnused);
void FUN_1404fa9b0(void* pPayload);
void FUN_1404fa9d0(void* pPayload);
void FUN_1404fa9f0(void* pPayload);
void FUN_1404faa10(void* pPayload);
void FUN_1404faa30(void* pPayload);
void FUN_1404faa50(void* pPayload);
void FUN_1404faa70(void* pPayload);
void FUN_1404faa90(void* pPayload);
void FUN_1404faab0(void* pPayload);
void FUN_1404faad0(void* pPayload);
void FUN_1404faaf0(void* pPayload);
void FUN_1404fab10(void* pPayload);
void FUN_1404fab30(void* pPayload);
void FUN_1404fab50(void* pPayload);
void FUN_1404fab70(void* pPayload);
void FUN_1404fab90(void* pPayload);
void FUN_1404fabb0(void* pPayload);

// @0x1404fa6b0
void FUN_1404fa6b0(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fabd0(pHandle, 0);
}

// @0x1404fa6e0
void FUN_1404fa6e0(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fac00(pHandle, 0);
}

// @0x1404fa710
void FUN_1404fa710(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fac30(pHandle, 0);
}

// @0x1404fa740
void FUN_1404fa740(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fac60(pHandle, 0);
}

// @0x1404fa770
void FUN_1404fa770(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fac90(pHandle, 0);
}

// @0x1404fa7a0
void FUN_1404fa7a0(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404facc0(pHandle, 0);
}

// @0x1404fa7d0
void FUN_1404fa7d0(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404facf0(pHandle, 0);
}

// @0x1404fa800
void FUN_1404fa800(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fad20(pHandle, 0);
}

// @0x1404fa830
void FUN_1404fa830(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fad50(pHandle, 0);
}

// @0x1404fa860
void FUN_1404fa860(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fad80(pHandle, 0);
}

// @0x1404fa890
void FUN_1404fa890(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fadb0(pHandle, 0);
}

// @0x1404fa8c0
void FUN_1404fa8c0(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fade0(pHandle, 0);
}

// @0x1404fa8f0
void FUN_1404fa8f0(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fae10(pHandle, 0);
}

// @0x1404fa920
void FUN_1404fa920(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fae40(pHandle, 0);
}

// @0x1404fa950
void FUN_1404fa950(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404fae70(pHandle, 0);
}

// @0x1404fa980
void FUN_1404fa980(void* pHandle)
{
    if (*(void**)((char*)pHandle + 8) != 0)
        FUN_1404faea0(pHandle, 0);
}

// @0x1404fa9b0
void FUN_1404fa9b0(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404fa9d0
void FUN_1404fa9d0(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404fa9f0
void FUN_1404fa9f0(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404faa10
void FUN_1404faa10(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404faa30
void FUN_1404faa30(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404faa50
void FUN_1404faa50(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404faa70
void FUN_1404faa70(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404faa90
void FUN_1404faa90(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404faab0
void FUN_1404faab0(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404faad0
void FUN_1404faad0(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404faaf0
void FUN_1404faaf0(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404fab10
void FUN_1404fab10(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404fab30
void FUN_1404fab30(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404fab50
void FUN_1404fab50(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404fab70
void FUN_1404fab70(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404fab90
void FUN_1404fab90(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404fabb0
void FUN_1404fabb0(void* pPayload)
{
    CPtred::AddRefPtred((class CPtred*)(pPayload));
}

// @0x1404fabd0
void FUN_1404fabd0(void* pHandle, void* pUnused)
{
    FUN_1404fa9b0(*(void**)((char*)pHandle + 8));
}

// @0x1404fac00
void FUN_1404fac00(void* pHandle, void* pUnused)
{
    FUN_1404fa9d0(*(void**)((char*)pHandle + 8));
}

// @0x1404fac30
void FUN_1404fac30(void* pHandle, void* pUnused)
{
    FUN_1404fa9f0(*(void**)((char*)pHandle + 8));
}

// @0x1404fac60
void FUN_1404fac60(void* pHandle, void* pUnused)
{
    FUN_1404faa10(*(void**)((char*)pHandle + 8));
}

// @0x1404fac90
void FUN_1404fac90(void* pHandle, void* pUnused)
{
    FUN_1404faa30(*(void**)((char*)pHandle + 8));
}

// @0x1404facc0
void FUN_1404facc0(void* pHandle, void* pUnused)
{
    FUN_1404faa50(*(void**)((char*)pHandle + 8));
}

// @0x1404facf0
void FUN_1404facf0(void* pHandle, void* pUnused)
{
    FUN_1404faa70(*(void**)((char*)pHandle + 8));
}

// @0x1404fad20
void FUN_1404fad20(void* pHandle, void* pUnused)
{
    FUN_1404faa90(*(void**)((char*)pHandle + 8));
}

// @0x1404fad50
void FUN_1404fad50(void* pHandle, void* pUnused)
{
    FUN_1404faab0(*(void**)((char*)pHandle + 8));
}

// @0x1404fad80
void FUN_1404fad80(void* pHandle, void* pUnused)
{
    FUN_1404faad0(*(void**)((char*)pHandle + 8));
}

// @0x1404fadb0
void FUN_1404fadb0(void* pHandle, void* pUnused)
{
    FUN_1404faaf0(*(void**)((char*)pHandle + 8));
}

// @0x1404fade0
void FUN_1404fade0(void* pHandle, void* pUnused)
{
    FUN_1404fab10(*(void**)((char*)pHandle + 8));
}

// @0x1404fae10
void FUN_1404fae10(void* pHandle, void* pUnused)
{
    FUN_1404fab30(*(void**)((char*)pHandle + 8));
}

// @0x1404fae40
void FUN_1404fae40(void* pHandle, void* pUnused)
{
    FUN_1404fab50(*(void**)((char*)pHandle + 8));
}

// @0x1404fae70
void FUN_1404fae70(void* pHandle, void* pUnused)
{
    FUN_1404fab70(*(void**)((char*)pHandle + 8));
}

// @0x1404faea0
void FUN_1404faea0(void* pHandle, void* pUnused)
{
    FUN_1404fab90(*(void**)((char*)pHandle + 8));
}
