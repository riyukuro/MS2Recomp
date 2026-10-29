// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 5 of unit_1413a9df0: the tail template glue of the
// CGuideCondition* range (16-byte element array, Checked::memmove_s, the small member getters). The scalar deleting
// destructors in front of it (0x1413b4200-0x1413b54f0) are emitted by the units that own the vftables.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_1413a9df0#5
// MS2-RANGE: 0x1413b5500-0x1413b5a10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?CallDestructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x1413b55b0 ; unique
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x1413b55f0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <atlcoll.h>

#include "ms2/placeholder/cguidecondition.h"


struct Unk_GcElem16 { void* m_p0; void* m_p1; };

size_t Unk_GcAnchorArray(ATL::CAtlArray<Unk_GcElem16>& arr, const Unk_GcElem16& elem)
{
    return arr.Add(elem);
}

// @0x1413b5600
int Unk_GcState28(char* p)
{
    return *reinterpret_cast<int*>(p + 0x28);
}

// @0x1413b5610
int Unk_GcState178(char* p)
{
    return *reinterpret_cast<int*>(p + 0x178);
}

// @0x1413b5850
void Unk_GcClear0(char* p)
{
    *p = 0;
}

// @0x1413b5860
void Unk_GcClear1(char* p)
{
    *p = 0;
}

// @0x1413b5870
bool Unk_GcVec3IsNull(const Unk_GcOptVec3* pOpt)
{
    return pOpt->m_bSet == false;
}

// @0x1413b58a0
bool Unk_GcIntIsNull(const Unk_GcOptInt* pOpt)
{
    return pOpt->m_bSet == false;
}

// @0x1413b58d0
bool Unk_GcVec3HasValue(const Unk_GcOptVec3* pOpt)
{
    return pOpt->m_bSet;
}

// @0x1413b58e0
bool Unk_GcBoolHasValue(const Unk_GcOptBool* pOpt)
{
    return pOpt->m_bSet;
}

// The pointer array's destructor loop (0x1413b55b0) is a COMDAT of the array.
void Unk_GcAnchorPtrArray(ATL::CAtlArray<void*>& arr)
{
    arr.RemoveAll();
}

bool FUN_140311670(void* p);

// @0x1413b57d0
bool Unk_GcNoPoint(char* p)
{
    return FUN_140311670(p + 0x178) == 0;
}
