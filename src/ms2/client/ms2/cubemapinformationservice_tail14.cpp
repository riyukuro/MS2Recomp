// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService COMDAT tail slice 0x14112cdec-
// 0x14112fa90 (queue unit_14112cdec): the scalar deleting destructors of the service, its message handlers and its
// map record types, the three CAtlArray<16-byte handle> instantiations of the service (Add / GrowBuffer / SetCount /
// element ctor + dtor loops), the CCubeMotionManager and async-queue singletons, the EE class glue of the service and
// of its messages (TypeCast, GetClassDesc, ref counts, SetupClassInfo) and the two HandleMessage templates.
// Written as plain functions with explicit @VA tags: the service's vftable is owned by cubemapinformationservice_3.cpp
// (ctor there), so none of these COMDATs can be reached by instantiating the classes in this file.
// Not an original file.
// MS2-UNIT: unit_14112cdec
// MS2-RANGE: 0x14112cdec-0x14112fa90 .text$mn
// MS2-PIN: ??0Unk_CMISQueue@@QEAA@XZ 0x14111e640
// MS2-PIN: ??0Unk_CMISQueueBase@@QEAA@XZ 0x1411225a0
// MS2-PIN: ??0Unk_CMISQueueMember@@QEAA@XZ 0x140ae79e0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>
#include <efd/MemObject.h>
#include <efd/MemHint.h>
#include <efd/utf8string.h>
#include <efd/IMessage.h>
#include <egf/EntityChangeMessage.h>
#include "ms2/client/ms2/cubemotionmanager.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include <efd/MessageService.h>
#include <ecr/CoreRuntimeMessages.h>

typedef unsigned __int64 u64;

__declspec(noreturn) void FUN_140159b70(long hr);              // ATL::AtlThrowImpl
void* FUN_140159860(u64 nSize, void* pWhere);                  // placement operator new
void FUN_14015b310(void* p, u64 nSize);                        // sized global delete

// ---- scalar deleting destructors ---------------------------------------------------------------------------------
// of the record / handle types (59 bytes: dtor, then operator delete when bit 0 of the flags is set)
void FUN_1411237f0(void* p);
void FUN_1409648f0(void* p);
void FUN_140fac610(void* p);
void FUN_140fac640(void* p);
void FUN_1411238b0(void* p);
void FUN_141125910(void* p);
void FUN_141125930(void* p);
void FUN_141125950(void* p);
void FUN_141125970(void* p);
void FUN_141125990(void* p);
void FUN_1411259b0(void* p);
void FUN_1411259d0(void* p);
void FUN_1411259f0(void* p);
void FUN_141125a10(void* p);
void FUN_141125a30(void* p);
void FUN_141125a50(void* p);
void FUN_141125a70(void* p);
void FUN_141125a90(void* p);
void FUN_141125ab0(void* p);
void FUN_141125ad0(void* p);
void FUN_141125af0(void* p);
void FUN_141125b10(void* p);
void FUN_141125b30(void* p);
void FUN_141125b50(void* p);
void FUN_141125e20(void* p);
void FUN_141125e50(void* p);
void FUN_1410b6990(void* p);
void FUN_141125fa0(void* p);
void FUN_141125fc0(void* p);
void FUN_141125fe0(void* p);
void FUN_141126060(void* p);
void FUN_1411236c0(void* p);
void FUN_1411236e0(void* p);
void FUN_141123700(void* p);
void FUN_141123740(void* p);
void FUN_141123720(void* p);
void FUN_1410b7240(void* p);
void FUN_141125ee0(void* p);
void FUN_141125f70(void* p);
void FUN_141126010(void* p);
void FUN_141126030(void* p);

// @0x14112cdec
// secondary-vftable thunk (this - 0x18 = the service) of the service's deleting destructor
void* FUN_14112d5e0(void* p, unsigned f);
// MS2-FUNCTIONAL: exe is `sub rcx,0x18; jmp` (this-adjusting thunk)
void* FUN_14112cdec(void* pSecondary, unsigned f)
{
    return FUN_14112d5e0((char*)pSecondary - 0x18, f);
}

// @0x14112ce00 .. @0x14112d8c0: scalar deleting destructors (flags bit 0 = delete, bit 2 = sized global delete for the
// efd::MemObject types)
// @0x14112ce00 MessageHandlerImpl<CMIS, EntityChangeMessage>
void* FUN_14112ce00(void* p, unsigned f)
{
    FUN_1411236c0(p);
    if (f & 1)
        operator delete(p, 0x28);
    return p;
}

// @0x14112ce40 MessageHandlerImpl<CMIS, SceneGraphAddedMessage>
void* FUN_14112ce40(void* p, unsigned f)
{
    FUN_1411236e0(p);
    if (f & 1)
        operator delete(p, 0x28);
    return p;
}

// @0x14112ce80 MessageSubclassHandler<CMIS, EntityChangeMessage, EntityChangeMessage>
void* FUN_14112ce80(void* p, unsigned f)
{
    FUN_141123700(p);
    if (f & 1)
        operator delete(p, 0x28);
    return p;
}

// @0x14112cec0 MessageWrapper<EntityChangeMessage, 8253>
void* FUN_14112cec0(void* p, unsigned f)
{
    FUN_141123720(p);
    if (f & 1) {
        if ((f & 4) == 0)
            efd::MemObject::operator delete(p, 0x20);
        else
            FUN_14015b310(p, 0x20);
    }
    return p;
}

// @0x14112cf20 MessageWrapperSubclassHandler<CMIS, EntityChangeMessage, EntityChangeMessage, 8253>
void* FUN_14112cf20(void* p, unsigned f)
{
    FUN_141123740(p);
    if (f & 1)
        operator delete(p, 0x28);
    return p;
}

// @0x14112cf60 .. @0x14112d520: the handle / node record types of the service's containers
// @0x14112cf60
void* FUN_14112cf60(void* p, unsigned f)
{
    FUN_1411237f0(p);
    if (f & 1)
        operator delete(p, 0x10);
    return p;
}

// @0x14112cfa0
void* FUN_14112cfa0(void* p, unsigned f)
{
    FUN_1409648f0(p);
    if (f & 1)
        operator delete(p, 0x10);
    return p;
}

// @0x14112cfe0
void* FUN_14112cfe0(void* p, unsigned f)
{
    FUN_140fac610(p);
    if (f & 1)
        operator delete(p, 0x10);
    return p;
}

// @0x14112d020
void* FUN_14112d020(void* p, unsigned f)
{
    FUN_140fac640(p);
    if (f & 1)
        operator delete(p, 0x10);
    return p;
}

// @0x14112d060 TSingleton<CubeMapInformationService>
void* FUN_14112d060(void* p, unsigned f)
{
    FUN_1411238b0(p);
    if (f & 1)
        operator delete(p, 8);
    return p;
}

// @0x14112d0a0
void* FUN_14112d0a0(void* p, unsigned f)
{
    FUN_141125910(p);
    if (f & 1)
        operator delete(p, 0x58);
    return p;
}

// @0x14112d0e0
void* FUN_14112d0e0(void* p, unsigned f)
{
    FUN_141125930(p);
    if (f & 1)
        operator delete(p, 0x40);
    return p;
}

// @0x14112d120
void* FUN_14112d120(void* p, unsigned f)
{
    FUN_141125950(p);
    if (f & 1)
        operator delete(p, 0x10);
    return p;
}

// @0x14112d160
void* FUN_14112d160(void* p, unsigned f)
{
    FUN_141125970(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d1a0
void* FUN_14112d1a0(void* p, unsigned f)
{
    FUN_141125990(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d1e0
void* FUN_14112d1e0(void* p, unsigned f)
{
    FUN_1411259b0(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d220
void* FUN_14112d220(void* p, unsigned f)
{
    FUN_1411259d0(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d260
void* FUN_14112d260(void* p, unsigned f)
{
    FUN_1411259f0(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d2a0
void* FUN_14112d2a0(void* p, unsigned f)
{
    FUN_141125a10(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d2e0
void* FUN_14112d2e0(void* p, unsigned f)
{
    FUN_141125a30(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d320
void* FUN_14112d320(void* p, unsigned f)
{
    FUN_141125a50(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d360
void* FUN_14112d360(void* p, unsigned f)
{
    FUN_141125a70(p);
    if (f & 1)
        operator delete(p, 0x20);
    return p;
}

// @0x14112d3a0
void* FUN_14112d3a0(void* p, unsigned f)
{
    FUN_141125a90(p);
    if (f & 1)
        operator delete(p, 0x50);
    return p;
}

// @0x14112d3e0
void* FUN_14112d3e0(void* p, unsigned f)
{
    FUN_141125ab0(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d420
void* FUN_14112d420(void* p, unsigned f)
{
    FUN_141125ad0(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d460
void* FUN_14112d460(void* p, unsigned f)
{
    FUN_141125af0(p);
    if (f & 1)
        operator delete(p, 0x10);
    return p;
}

// @0x14112d4a0
void* FUN_14112d4a0(void* p, unsigned f)
{
    FUN_141125b10(p);
    if (f & 1)
        operator delete(p, 0x10);
    return p;
}

// @0x14112d4e0
void* FUN_14112d4e0(void* p, unsigned f)
{
    FUN_141125b30(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d520
void* FUN_14112d520(void* p, unsigned f)
{
    FUN_141125b50(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d560 AutomaticCreateCubeInfo
void* FUN_14112d560(void* p, unsigned f)
{
    FUN_141125e20(p);
    if (f & 1)
        operator delete(p, 0x50);
    return p;
}

// @0x14112d5a0 efd::BaseMessageHandler
void* FUN_14112d5a0(void* p, unsigned f)
{
    FUN_141125e50(p);
    if (f & 1)
        operator delete(p, 0x18);
    return p;
}

// @0x14112d5e0 CubeMapInformationService
void* FUN_14112d5e0(void* p, unsigned f)
{
    FUN_1410b7240(p);
    if (f & 1) {
        if ((f & 4) == 0)
            efd::MemObject::operator delete(p, 0x4a8);
        else
            FUN_14015b310(p, 0x4a8);
    }
    return p;
}

// @0x14112d640 egf::EntityChangeMessage
void* FUN_14112d640(void* p, unsigned f)
{
    FUN_141125ee0(p);
    if (f & 1) {
        if ((f & 4) == 0)
            efd::MemObject::operator delete(p, 0x20);
        else
            FUN_14015b310(p, 0x20);
    }
    return p;
}

// @0x14112d6a0 FittingDollData
void* FUN_14112d6a0(void* p, unsigned f)
{
    FUN_1410b6990(p);
    if (f & 1)
        operator delete(p, 0x70);
    return p;
}

// @0x14112d6e0 efd::ISystemService
void* FUN_14112d6e0(void* p, unsigned f)
{
    FUN_141125f70(p);
    if (f & 1) {
        if ((f & 4) == 0)
            efd::MemObject::operator delete(p, 0x18);
        else
            FUN_14015b310(p, 0x18);
    }
    return p;
}

// @0x14112d740 NotifyChangeUIBuildingCount
void* FUN_14112d740(void* p, unsigned f)
{
    FUN_141125fa0(p);
    if (f & 1)
        operator delete(p, 0x20);
    return p;
}

// @0x14112d780 SaleStateData
void* FUN_14112d780(void* p, unsigned f)
{
    FUN_141125fc0(p);
    if (f & 1)
        operator delete(p, 0x28);
    return p;
}

// @0x14112d7c0 SalesInfo
void* FUN_14112d7c0(void* p, unsigned f)
{
    FUN_141125fe0(p);
    if (f & 1)
        operator delete(p, 0x38);
    return p;
}

// @0x14112d800 ecr::SceneGraphAddedMessage
void* FUN_14112d800(void* p, unsigned f)
{
    FUN_141126010(p);
    if (f & 1) {
        if ((f & 4) == 0)
            efd::MemObject::operator delete(p, 0x28);
        else
            FUN_14015b310(p, 0x28);
    }
    return p;
}

// @0x14112d860 ecr::SceneGraphMessage
void* FUN_14112d860(void* p, unsigned f)
{
    FUN_141126030(p);
    if (f & 1) {
        if ((f & 4) == 0)
            efd::MemObject::operator delete(p, 0x28);
        else
            FUN_14015b310(p, 0x28);
    }
    return p;
}

// @0x14112d8c0 SetItemEffectInfo
void* FUN_14112d8c0(void* p, unsigned f)
{
    FUN_141126060(p);
    if (f & 1)
        operator delete(p, 0x28);
    return p;
}

// ---- the service's three CAtlArray<16-byte handle> instantiations (ATL's own Add / GrowBuffer / SetCount) --------
// The element is a 16-byte payload handle (unused qword, then the pointer): arrays A (add/grow/dtor only), B and C
// (the service's two blueprint / design handle arrays, in cubemapinformationservice_3.cpp: Unk_CMISHandle3a8 / 388).
struct Unk_CMISHandle16 { char m_b[16]; };
struct Unk_CMISArr16
{
    Unk_CMISHandle16* m_pData;
    u64 m_nSize;
    u64 m_nMaxSize;
    int m_nGrowBy;
};

void FUN_140884f70(void* pDst, const void* pSrc);              // copy ctor of the element of array A
void FUN_140fac570(void* pDst, const void* pSrc);              // copy ctor of the element of array B
void FUN_140fac5b0(void* pDst, const void* pSrc);              // copy ctor of the element of array C
void* FUN_14111ea80(void* p);                                  // default ctor of B's element
void* FUN_14111ead0(void* p);                                  // default ctor of C's element

void* FUN_14112cfa0(void* p, unsigned f);
void* FUN_14112cfe0(void* p, unsigned f);
void* FUN_14112d020(void* p, unsigned f);
bool FUN_14112e310(Unk_CMISArr16* a, u64 nNewSize);
bool FUN_14112e4b0(Unk_CMISArr16* a, u64 nNewSize);
bool FUN_14112e650(Unk_CMISArr16* a, u64 nNewSize);
void FUN_14112f1a0(void* pDst, const void* pSrc, __int64 n);
void FUN_14112f1e0(void* pDst, const void* pSrc, __int64 n);
void FUN_14112f220(void* pDst, const void* pSrc, __int64 n);
void FUN_14112db10(Unk_CMISHandle16* p, u64 n);
void FUN_14112db90(Unk_CMISHandle16* p, u64 n);
void FUN_14112dc70(Unk_CMISHandle16* p, u64 n);
void FUN_14112dcd0(Unk_CMISHandle16* p, u64 n);

// @0x14112d900 Add (array A)
u64 FUN_14112d900(Unk_CMISArr16* a, const void* pElem)
{
    u64 iElement = a->m_nSize;
    if (iElement >= a->m_nMaxSize) {
        bool bOk = FUN_14112e310(a, iElement + 1);
        if (!bOk)
            FUN_140159b70(0x8007000e);
    }
    void* p = FUN_140159860(0x10, a->m_pData + iElement);
    FUN_140884f70(p, pElem);
    a->m_nSize++;
    return iElement;
}

// @0x14112d9b0 Add (array B)
u64 FUN_14112d9b0(Unk_CMISArr16* a, const void* pElem)
{
    u64 iElement = a->m_nSize;
    if (iElement >= a->m_nMaxSize) {
        bool bOk = FUN_14112e4b0(a, iElement + 1);
        if (!bOk)
            FUN_140159b70(0x8007000e);
    }
    void* p = FUN_140159860(0x10, a->m_pData + iElement);
    FUN_140fac570(p, pElem);
    a->m_nSize++;
    return iElement;
}

// @0x14112da60 Add (array C)
u64 FUN_14112da60(Unk_CMISArr16* a, const void* pElem)
{
    u64 iElement = a->m_nSize;
    if (iElement >= a->m_nMaxSize) {
        bool bOk = FUN_14112e650(a, iElement + 1);
        if (!bOk)
            FUN_140159b70(0x8007000e);
    }
    void* p = FUN_140159860(0x10, a->m_pData + iElement);
    FUN_140fac5b0(p, pElem);
    a->m_nSize++;
    return iElement;
}

// @0x14112db10 CallConstructors (array B)
// MS2-FUNCTIONAL: ATL CallConstructors; exe spills the placement-new result and has an EH unwind funclet
void FUN_14112db10(Unk_CMISHandle16* pElements, u64 nElements)
{
    u64 iElement = 0;
    try {
        for (; iElement < nElements; iElement++) {
            void* p = FUN_140159860(0x10, pElements + iElement);
            FUN_14111ea80(p);
        }
    } catch (...) {
        while (iElement > 0) {
            iElement--;
            FUN_14112cfe0(pElements + iElement, 0);
        }
        throw;
    }
}

// @0x14112db90 CallConstructors (array C)
// MS2-FUNCTIONAL: ATL CallConstructors; exe spills the placement-new result and has an EH unwind funclet
void FUN_14112db90(Unk_CMISHandle16* pElements, u64 nElements)
{
    u64 iElement = 0;
    try {
        for (; iElement < nElements; iElement++) {
            void* p = FUN_140159860(0x10, pElements + iElement);
            FUN_14111ead0(p);
        }
    } catch (...) {
        while (iElement > 0) {
            iElement--;
            FUN_14112d020(pElements + iElement, 0);
        }
        throw;
    }
}

// @0x14112dc10 CallDestructors (array A)
void FUN_14112dc10(Unk_CMISHandle16* pElements, u64 nElements)
{
    for (u64 i = 0; i < nElements; i++)
        FUN_14112cfa0(pElements + i, 0);
}

// @0x14112dc70 CallDestructors (array B)
void FUN_14112dc70(Unk_CMISHandle16* pElements, u64 nElements)
{
    for (u64 i = 0; i < nElements; i++)
        FUN_14112cfe0(pElements + i, 0);
}

// @0x14112dcd0 CallDestructors (array C)
void FUN_14112dcd0(Unk_CMISHandle16* pElements, u64 nElements)
{
    for (u64 i = 0; i < nElements; i++)
        FUN_14112d020(pElements + i, 0);
}

// @0x14112dfe0 operator[] (array B)
Unk_CMISHandle16* FUN_14112dfe0(Unk_CMISArr16* a, u64 iElement)
{
    if (iElement >= a->m_nSize)
        FUN_140159b70(0x80070057);
    return a->m_pData + iElement;
}

// @0x14112e020 operator[] (array C)
Unk_CMISHandle16* FUN_14112e020(Unk_CMISArr16* a, u64 iElement)
{
    if (iElement >= a->m_nSize)
        FUN_140159b70(0x80070057);
    return a->m_pData + iElement;
}

// @0x14112e310 GrowBuffer (array A)
bool FUN_14112e310(Unk_CMISArr16* a, u64 nNewSize)
{
    if (nNewSize > a->m_nMaxSize) {
        if (a->m_pData == 0) {
            u64 nAllocSize = u64(a->m_nGrowBy) > nNewSize ? u64(a->m_nGrowBy) : nNewSize;
            a->m_pData = static_cast<Unk_CMISHandle16*>(calloc(nAllocSize, sizeof(Unk_CMISHandle16)));
            if (a->m_pData == 0)
                return false;
            a->m_nMaxSize = nAllocSize;
        } else {
            u64 nGrowBy = a->m_nGrowBy;
            if (nGrowBy == 0) {
                nGrowBy = a->m_nMaxSize / 2;
                if ((nNewSize - a->m_nMaxSize) > nGrowBy)
                    nGrowBy = nNewSize - a->m_nMaxSize;
            }
            u64 nNewMax;
            if (nNewSize < (a->m_nMaxSize + nGrowBy))
                nNewMax = a->m_nMaxSize + nGrowBy;
            else
                nNewMax = nNewSize;
            Unk_CMISHandle16* pNewData = static_cast<Unk_CMISHandle16*>(calloc(nNewMax, sizeof(Unk_CMISHandle16)));
            if (pNewData == 0)
                return false;
            FUN_14112f1a0(pNewData, a->m_pData, a->m_nSize);
            free(a->m_pData);
            a->m_pData = pNewData;
            a->m_nMaxSize = nNewMax;
        }
    }
    return true;
}

// @0x14112e4b0 GrowBuffer (array B)
bool FUN_14112e4b0(Unk_CMISArr16* a, u64 nNewSize)
{
    if (nNewSize > a->m_nMaxSize) {
        if (a->m_pData == 0) {
            u64 nAllocSize = u64(a->m_nGrowBy) > nNewSize ? u64(a->m_nGrowBy) : nNewSize;
            a->m_pData = static_cast<Unk_CMISHandle16*>(calloc(nAllocSize, sizeof(Unk_CMISHandle16)));
            if (a->m_pData == 0)
                return false;
            a->m_nMaxSize = nAllocSize;
        } else {
            u64 nGrowBy = a->m_nGrowBy;
            if (nGrowBy == 0) {
                nGrowBy = a->m_nMaxSize / 2;
                if ((nNewSize - a->m_nMaxSize) > nGrowBy)
                    nGrowBy = nNewSize - a->m_nMaxSize;
            }
            u64 nNewMax;
            if (nNewSize < (a->m_nMaxSize + nGrowBy))
                nNewMax = a->m_nMaxSize + nGrowBy;
            else
                nNewMax = nNewSize;
            Unk_CMISHandle16* pNewData = static_cast<Unk_CMISHandle16*>(calloc(nNewMax, sizeof(Unk_CMISHandle16)));
            if (pNewData == 0)
                return false;
            FUN_14112f1e0(pNewData, a->m_pData, a->m_nSize);
            free(a->m_pData);
            a->m_pData = pNewData;
            a->m_nMaxSize = nNewMax;
        }
    }
    return true;
}

// @0x14112e650 GrowBuffer (array C)
bool FUN_14112e650(Unk_CMISArr16* a, u64 nNewSize)
{
    if (nNewSize > a->m_nMaxSize) {
        if (a->m_pData == 0) {
            u64 nAllocSize = u64(a->m_nGrowBy) > nNewSize ? u64(a->m_nGrowBy) : nNewSize;
            a->m_pData = static_cast<Unk_CMISHandle16*>(calloc(nAllocSize, sizeof(Unk_CMISHandle16)));
            if (a->m_pData == 0)
                return false;
            a->m_nMaxSize = nAllocSize;
        } else {
            u64 nGrowBy = a->m_nGrowBy;
            if (nGrowBy == 0) {
                nGrowBy = a->m_nMaxSize / 2;
                if ((nNewSize - a->m_nMaxSize) > nGrowBy)
                    nGrowBy = nNewSize - a->m_nMaxSize;
            }
            u64 nNewMax;
            if (nNewSize < (a->m_nMaxSize + nGrowBy))
                nNewMax = a->m_nMaxSize + nGrowBy;
            else
                nNewMax = nNewSize;
            Unk_CMISHandle16* pNewData = static_cast<Unk_CMISHandle16*>(calloc(nNewMax, sizeof(Unk_CMISHandle16)));
            if (pNewData == 0)
                return false;
            FUN_14112f220(pNewData, a->m_pData, a->m_nSize);
            free(a->m_pData);
            a->m_pData = pNewData;
            a->m_nMaxSize = nNewMax;
        }
    }
    return true;
}

// @0x14112f1a0 RelocateElements (array A): memmove_s of n 16-byte elements
void FUN_14112f1a0(void* pDst, const void* pSrc, __int64 n)
{
    ATL::Checked::memmove_s(pDst, n * sizeof(Unk_CMISHandle16), pSrc, n * sizeof(Unk_CMISHandle16));
}

// @0x14112f1e0 (array B)
void FUN_14112f1e0(void* pDst, const void* pSrc, __int64 n)
{
    ATL::Checked::memmove_s(pDst, n * sizeof(Unk_CMISHandle16), pSrc, n * sizeof(Unk_CMISHandle16));
}

// @0x14112f220 (array C)
void FUN_14112f220(void* pDst, const void* pSrc, __int64 n)
{
    ATL::Checked::memmove_s(pDst, n * sizeof(Unk_CMISHandle16), pSrc, n * sizeof(Unk_CMISHandle16));
}

bool FUN_14112f2f0(Unk_CMISArr16* a, u64 nNewSize, int nGrowBy);
bool FUN_14112f480(Unk_CMISArr16* a, u64 nNewSize, int nGrowBy);

// @0x14112f260 RemoveAll (array B)
void FUN_14112f260(Unk_CMISArr16* a)
{
    FUN_14112f2f0(a, 0, -1);
}

// @0x14112f280 RemoveAll (array C)
void FUN_14112f280(Unk_CMISArr16* a)
{
    FUN_14112f480(a, 0, -1);
}

// @0x14112f2f0 SetCount (array B)
bool FUN_14112f2f0(Unk_CMISArr16* a, u64 nNewSize, int nGrowBy)
{
    if (nGrowBy != -1)
        a->m_nGrowBy = nGrowBy;
    if (nNewSize == 0) {
        if (a->m_pData != 0) {
            FUN_14112dc70(a->m_pData, a->m_nSize);
            free(a->m_pData);
            a->m_pData = 0;
        }
        a->m_nSize = 0;
        a->m_nMaxSize = 0;
    } else if (nNewSize <= a->m_nMaxSize) {
        if (nNewSize > a->m_nSize) {
            FUN_14112db10(a->m_pData + a->m_nSize, nNewSize - a->m_nSize);
        } else if (a->m_nSize > nNewSize) {
            FUN_14112dc70(a->m_pData + nNewSize, a->m_nSize - nNewSize);
        }
        a->m_nSize = nNewSize;
    } else {
        bool bSuccess = FUN_14112e4b0(a, nNewSize);
        if (!bSuccess)
            return false;
        FUN_14112db10(a->m_pData + a->m_nSize, nNewSize - a->m_nSize);
        a->m_nSize = nNewSize;
    }
    return true;
}

// @0x14112f480 SetCount (array C)
bool FUN_14112f480(Unk_CMISArr16* a, u64 nNewSize, int nGrowBy)
{
    if (nGrowBy != -1)
        a->m_nGrowBy = nGrowBy;
    if (nNewSize == 0) {
        if (a->m_pData != 0) {
            FUN_14112dcd0(a->m_pData, a->m_nSize);
            free(a->m_pData);
            a->m_pData = 0;
        }
        a->m_nSize = 0;
        a->m_nMaxSize = 0;
    } else if (nNewSize <= a->m_nMaxSize) {
        if (nNewSize > a->m_nSize) {
            FUN_14112db90(a->m_pData + a->m_nSize, nNewSize - a->m_nSize);
        } else if (a->m_nSize > nNewSize) {
            FUN_14112dcd0(a->m_pData + nNewSize, a->m_nSize - nNewSize);
        }
        a->m_nSize = nNewSize;
    } else {
        bool bSuccess = FUN_14112e650(a, nNewSize);
        if (!bSuccess)
            return false;
        FUN_14112db90(a->m_pData + a->m_nSize, nNewSize - a->m_nSize);
        a->m_nSize = nNewSize;
    }
    return true;
}

// ---- small glue: ref counts, class descs, type casts, accessors, message-factory registration ------------------------
extern char DAT_143acf950;      // CubeMapInformationService class desc
extern char DAT_143b05e50;      // EntityChangeMessage class desc
extern char DAT_1439ff650;      // SceneGraphAddedMessage class desc
extern char DAT_1439ff240;      // SceneGraphMessage class desc
extern int DAT_143ae2b3c;
extern CCubeMotionManager* DAT_143acf6c8;
extern void* DAT_143b023e0;

int FUN_1409f2d80(void* pCount);
void FUN_1409f2d50(void* pCount);
void FUN_1409f2d60(void* pCount);
void* FUN_1409f31d0(void* pDesc, unsigned nId, void* pThis);
void FUN_1409f2e10(void* pInfo, const char* pszName, unsigned nId, void* pCtx, void* pDesc);
void FUN_1409f30f0(void* pInfo, void* pCtx);
void FUN_1408a9090(void* p);
__int64 FUN_1408a9080(void* p);
void* FUN_141128450(void* p);
void FUN_14211f220(void* p);
void FUN_1409a1a90();
u64 FUN_140c20b50(void* a, u64 b);
u64 FUN_1410dc0d0();
u64 FUN_1410dc0e0();
void FUN_1410dc0f0(void* p);
CCubeMotionManager* FUN_1410af790();
void* FUN_1410dbe40(void*);
void* FUN_1410dbee0(void*);

struct Unk_CMISBits { u64 m_nLow : 27; u64 m_nMid : 32; u64 m_nHigh : 5; };

struct Unk_CMISGlue
{
    u64 Zero0(void*); u64 Zero1(void*); void* Desc0(); void* Desc1(); void* Desc2(); void* Desc3(); u64 ClassId(); int Global();
};

struct Unk_CMISVDel0 { virtual ~Unk_CMISVDel0(); };
struct Unk_CMISVDel8
{
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual ~Unk_CMISVDel8();
};

// @0x14112ddb0 CubeMapInformationService::DecRefCount
void FUN_14112ddb0(char* pThis)
{
    if (FUN_1409f2d80(pThis + 0x20) == 0)
        (**reinterpret_cast<void (***)(void*)>(pThis))(pThis);
}

// @0x14112ddf0 DecRefCount of a ref-counted object whose count follows the vftable pointer
void FUN_14112ddf0(char* pThis)
{
    if (FUN_1409f2d80(pThis + 8) == 0)
        (**reinterpret_cast<void (***)(void*)>(pThis))(pThis);
}

// @0x14112de30
void FUN_14112de30(Unk_CMISVDel8* p) { delete p; }
// @0x14112de80
void FUN_14112de80(Unk_CMISVDel8* p) { delete p; }

// @0x14112ded0 destroy the service singleton
void FUN_14112ded0()
{
    if (DAT_143acf6c8 != 0) {
        delete FUN_1410af790();
        DAT_143acf6c8 = 0;
    }
}

// @0x14112dfd0
u64 Unk_CMISGlue::Zero0(void*) { return 0; }

// @0x14112e060
void* Unk_CMISGlue::Desc0() { return &DAT_143acf950; }
// @0x14112e070
void* Unk_CMISGlue::Desc1() { return &DAT_143b05e50; }
// @0x14112e080
void* Unk_CMISGlue::Desc2() { return &DAT_1439ff650; }
// @0x14112e090
void* Unk_CMISGlue::Desc3() { return &DAT_1439ff240; }

// @0x14112e0a0 MessageWrapper<EntityChangeMessage, 8253>::GetClassID
u64 Unk_CMISGlue::ClassId() { return 0x203d; }

// @0x14112e0b0
u64 FUN_14112e0b0(char* p) { return *reinterpret_cast<u64*>(p + 8); }
// @0x14112e0c0
unsigned FUN_14112e0c0(char* p) { return *reinterpret_cast<unsigned*>(p + 0xc); }
// @0x14112e0d0
void FUN_14112e0d0(char* p) { FUN_1408a9090(p + 0x18); }
// @0x14112e0f0
u64 FUN_14112e0f0(char* p) { return *reinterpret_cast<u64*>(p + 0x18); }
// @0x14112e100
unsigned FUN_14112e100(char* p) { return *reinterpret_cast<unsigned*>(p + 0x20); }
// @0x14112e110
unsigned FUN_14112e110(char* p) { return *reinterpret_cast<unsigned*>(p + 0x40); }

// @0x14112e120
void FUN_14112e120(char* p)
{
    if (FUN_1408a9080(p + 0x48))
        FUN_14211f220(FUN_141128450(p + 0x48));
    else
        FUN_1409a1a90();
}

// @0x14112e170 exchange
u64 FUN_14112e170(void* a, u64* pSlot)
{
    u64 old = *pSlot;
    *pSlot = FUN_140c20b50(a, old);
    return old;
}

// @0x14112e250 CubeMapInformationService::GetRefCount
void FUN_14112e250(char* pThis) { FUN_1409f2d50(pThis + 0x20); }
// @0x14112e270
void FUN_14112e270(char* pThis) { FUN_1409f2d50(pThis + 8); }
// @0x14112e290
unsigned FUN_14112e290(char* p) { return *reinterpret_cast<unsigned*>(p + 0x38); }
// @0x14112e2a0
u64 FUN_14112e2a0() { return 0x4e88; }

// @0x14112e2b0 ATLENSURE(p) then &p->m_member
char* FUN_14112e2b0(void*, char* p)
{
    do {
        int cond = !!(p != 0);
        do { } while (0);
        if (!cond)
            FUN_140159b70(0x80004005);
    } while (0);
    return p + 8;
}

// @0x14112f070 CubeMapInformationService::IncRefCount
void FUN_14112f070(char* pThis) { FUN_1409f2d60(pThis + 0x20); }
// @0x14112f090
void FUN_14112f090(char* pThis) { FUN_1409f2d60(pThis + 8); }
// @0x14112f0b0
int Unk_CMISGlue::Global() { return DAT_143ae2b3c; }

// @0x14112f0c0 MessageHandlerImpl<CMIS, EntityChangeMessage>::RegisterMessageFactory
void FUN_14112f0c0(char* pThis, char* pReg)
{
    (*reinterpret_cast<void (**)(void*, unsigned, void*)>(*reinterpret_cast<char**>(pReg) + 0x10))(pReg, *reinterpret_cast<unsigned*>(pThis + 0x10), FUN_1410dbe40);
}
// @0x14112f100 MessageHandlerImpl<CMIS, SceneGraphAddedMessage>::RegisterMessageFactory
void FUN_14112f100(char* pThis, char* pReg)
{
    (*reinterpret_cast<void (**)(void*, unsigned, void*)>(*reinterpret_cast<char**>(pReg) + 0x10))(pReg, *reinterpret_cast<unsigned*>(pThis + 0x10), FUN_1410dbee0);
}
// @0x14112f140 MessageSubclassHandler<...>::RegisterMessageFactory
void FUN_14112f140(char* pThis, char* pReg)
{
    (*reinterpret_cast<void (**)(void*, unsigned, void*)>(*reinterpret_cast<char**>(pReg) + 0x10))(pReg, *reinterpret_cast<unsigned*>(pThis + 0x10), FUN_1410dbe40);
}
// @0x14112f180 MessageWrapperSubclassHandler<...>::RegisterMessageFactory
void FUN_14112f180(void*, void* pReg) { FUN_1410dc0f0(pReg); }

// @0x14112f2a0 set the low 27 bits
bool FUN_14112f2a0(Unk_CMISBits* p, u64 v)
{
    if (v > FUN_1410dc0e0())
        return false;
    p->m_nLow = v;
    return true;
}
// @0x14112f610
void FUN_14112f610(char* p, u64 v) { *reinterpret_cast<u64*>(p + 0x18) = v; }
// @0x14112f630
void FUN_14112f630(char* p, unsigned v) { *reinterpret_cast<unsigned*>(p + 0x20) = v; }
// @0x14112f650 set bits 27..58
bool FUN_14112f650(Unk_CMISBits* p, unsigned v)
{
    if (v > unsigned(FUN_1410dc0d0()))
        return false;
    p->m_nMid = v;
    return true;
}

// @0x14112f6b0 CubeMapInformationService::SetupClassInfo
// MS2-FUNCTIONAL: the exe passes the context through a base-offset adjustment (8 - 8) that has no source form yet
void FUN_14112f710(void* pInfo, void* pCtx);
void FUN_14112f6b0(void* pInfo, void* pCtx)
{
    FUN_1409f2e10(pInfo, "CubeMapInformationService", 0x6100017, pCtx, &DAT_143acf950);
    FUN_14112f710(pInfo, pCtx);
}
// @0x14112f710 ISystemService::SetupClassInfo
// MS2-FUNCTIONAL: same base-offset adjustment as FUN_14112f6b0
void FUN_14112f710(void* pInfo, void* pCtx)
{
    FUN_1409f2e10(pInfo, "ISystemService", 0x7000001, pCtx, 0);
    FUN_1409f30f0(pInfo, pCtx);
}
// @0x14112f770
u64 Unk_CMISGlue::Zero1(void*) { return 0; }

// ---- TypeCast of the service and its messages (identical bodies, one per vftable) ---------------------------------
#define CMIS_TYPECAST(va, desc) \
    bool FUN_##va(void* pThis, unsigned nId, void** ppOut) \
    { \
        *ppOut = FUN_1409f31d0(&desc, nId, pThis); \
        if (*ppOut != 0) \
            return true; \
        return false; \
    }
// @0x14112f810
CMIS_TYPECAST(14112f810, DAT_143acf950)
// @0x14112f860
CMIS_TYPECAST(14112f860, DAT_143acf950)
// @0x14112f8b0
CMIS_TYPECAST(14112f8b0, DAT_143b05e50)
// @0x14112f900
CMIS_TYPECAST(14112f900, DAT_143b05e50)
// @0x14112f950
CMIS_TYPECAST(14112f950, DAT_1439ff650)
// @0x14112f9a0
CMIS_TYPECAST(14112f9a0, DAT_1439ff650)
// @0x14112f9f0
CMIS_TYPECAST(14112f9f0, DAT_1439ff240)
// @0x14112fa40
CMIS_TYPECAST(14112fa40, DAT_1439ff240)

// @0x14112dd30 CCubeMotionManager::GetInstance (creates the manager on first use)
// MS2-FUNCTIONAL: exe builds this through the TSingleton<T>::GetInstance template with a result temp and a different EH layout
CCubeMotionManager* FUN_14112dd30()
{
    if (DAT_143acf6c8 == 0)
        return new CCubeMotionManager;
    return FUN_1410af790();
}

// the lazily created async send queue: a 0x18-byte object whose implicit ctor runs a base ctor and a member ctor
struct Unk_CMISQueueBase : efd::MemObject
{
    Unk_CMISQueueBase();                                        // 0x1411225a0
    u64 m_n0, m_n8;
};
struct Unk_CMISQueueMember { Unk_CMISQueueMember(); };          // 0x140ae79e0
struct Unk_CMISQueue : Unk_CMISQueueBase
{
    Unk_CMISQueueMember m_mem;                                  // +0x10
};

// @0x14112e1b0
void* FUN_14112e1b0()
{
    if (DAT_143b023e0 == 0)
        DAT_143b023e0 = new (efd::MemHint(efd::MemHint::NONE)) Unk_CMISQueue();
    return DAT_143b023e0;
}

// @0x14112df30 MessageWrapper<EntityChangeMessage, 8253>::FactoryMsg
template efd::IMessagePtr efd::MessageWrapper<egf::EntityChangeMessage, 8253>::FactoryMsg();

// @0x14112f780 formats a message category for the delivery log
// MS2-FUNCTIONAL: exe keeps the temporary string under an explicit EH state flag (local-variable layout differs)
u64 FUN_140affe60(void* pCategory);
void* FUN_1409a0f10(void* pOut, const efd::utf8string& kSrc);
void* FUN_14112f780(void* pCategory, void* pOut)
{
    FUN_1409a0f10(pOut, efd::utf8string(efd::Formatted, "Category(0x%016llX)", FUN_140affe60(pCategory)));
    return pOut;
}

// the service's message handlers (the exe's static objects live in .text$di; constructed here only to instantiate the templates)
void Unk_CMISHandlerAnchor14()
{
    efd::MessageWrapperSubclassHandler<CubeMapInformationService, egf::EntityChangeMessage, egf::EntityChangeMessage, 8253>
        h1(&CubeMapInformationService::FUN_1410cef70);
    efd::MessageHandlerImpl<CubeMapInformationService, ecr::SceneGraphAddedMessage>
        h2(reinterpret_cast<void (CubeMapInformationService::*)(const ecr::SceneGraphAddedMessage*, efd::Category)>(
            &CubeMapInformationService::FUN_1410cf130));
}
