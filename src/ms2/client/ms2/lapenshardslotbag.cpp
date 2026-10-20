// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). LapenshardSlotBag (the lapenshard system window's item bag and
// the quick bar's six equip slots).
// MS2-UNIT: ?\lapenshardslotbag.cpp
// MS2-RANGE: 0x140a702f0-0x140a71e70 .text$mn
// MS2-RANGE: 0x1400c4760-0x1400c4a80 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@IMMMI@Z 0x140a70bc0 ; unique
// MS2-PIN: ??0CNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@HI@Z 0x140a70cb0 ; unique
// MS2-PIN: ??1?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@XZ 0x140a70d10 ; unique
// MS2-PIN: ?CreateNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@HII@Z 0x140a70e80 ; unique
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x140a70f00 ; unique
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x140a70f20 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x140a70f40 ; unique
// MS2-PIN: ?FreePlexes@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXXZ 0x140a71030 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBAIXZ 0x140a710a0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140a710b0 ; unique
// MS2-PIN: ?InitHashTable@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA_NI_N@Z 0x140a711a0 ; unique
// MS2-PIN: ?IsLocked@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBA_NXZ 0x140a712c0 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBA_NHAEAH@Z 0x140a712f0 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@HII@Z 0x140a71350 ; unique
// MS2-PIN: ?PickSize@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBAI_K@Z 0x140a71560 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXI@Z 0x140a71650 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x140a71880 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140a71990 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140a71a80 ; unique
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXMMM_N@Z 0x140a71be0 ; unique
// MS2-PIN: ?TypeCast@LapenshardSlotBag@@UEBA_NIPEAPEAX@Z 0x140a71cf0 ; unique
// MS2-PIN: ?TypeCast@LapenshardSlotBag@@UEBA_NIPEAPEBX@Z 0x140a71d40 ; unique
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXXZ 0x140a71d90 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\lapenshardslotbag.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "lapenshardslotbag.h"
#include "lapenshardslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);
LapenshardSlot* FUN_140a6fef0(DragSlot* p);                 // the slot as a LapenshardSlot (lapenshardslot.cpp)

LapenshardSlotBag* FUN_140a70b70(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(LapenshardSlotBag);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

// The same statics once more, from a second include of the shared header; a null handle sits between "stun" and the map.
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_Handle1401cd100 s_handle2(0);
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

// @0x140a702f0
// MS2-FUNCTIONAL: the exe copies the new bag pointer and loads the vptr into a frame slot before the vfunc_10 call; no source form found
void FUN_140a702f0(const CString& strName, const ATL::CAtlArray<MS2Ptr<CItem> >& items, int nKind)
{
    LapenshardSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) LapenshardSlotBag(strName, items, nKind);
    if (pBag)
    {
        int nCount = pBag->FUN_140a70a30();
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140a703d0
// MS2-FUNCTIONAL: same vptr-in-frame-slot call shape as FUN_140a702f0
LapenshardSlotBag* FUN_140a703d0(const CString& strName)
{
    LapenshardSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) LapenshardSlotBag(strName);
    if (pBag)
    {
        int nCount = pBag->FUN_140a70a30();
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
    return pBag;
}

// @0x140a704a0
void FUN_140a704a0(const CString& strName)
{
    LapenshardSlotBag* pBag = FUN_140a70b70(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140a704f0
LapenshardSlotBag::LapenshardSlotBag(const CString& strName, const ATL::CAtlArray<MS2Ptr<CItem> >& items, int nKind)
    : DragSlotBag(strName), m_equipSlots(17, 0.75f, 0.25f, 2.25f, 10), m_bEquipMode(0), m_nKind(nKind)
{
    m_items.Copy(items);
}

// @0x140a705d0
LapenshardSlotBag::LapenshardSlotBag(const CString& strName)
    : DragSlotBag(strName), m_equipSlots(17, 0.75f, 0.25f, 2.25f, 10), m_bEquipMode(1), m_nKind(1)
{
    for (unsigned i = 1; i < 7; i++)
    {
        Unk_LapenEquipSlot slot = (Unk_LapenEquipSlot)i;
        m_equipSlots.SetAt(i - 1, slot);
    }
}

// @0x140a706d0
LapenshardSlotBag::~LapenshardSlotBag()
{
}

// @0x140a70730
CString LapenshardSlotBag::vfunc_15(int nIndex)
{
    CString str;
    str.Format("%s.%d", (const char*)FUN_1422c89f0(), (unsigned)nIndex);
    return str;
}

// @0x140a707f0
// MS2-FUNCTIONAL: local/temporary order of the two slot constructions differs from the exe
DragSlot* LapenshardSlotBag::vfunc_16(int nIndex)
{
    CString strName = vfunc_15(nIndex);
    if (m_bEquipMode != 0)
    {
        int nSlot = FUN_140a70b20(nIndex);
        return new (efd::MemHint(efd::MemHint::NONE)) LapenshardSlot(strName, nIndex, MS2Ptr<CItem>(0), nSlot, m_nKind);
    }
    return new (efd::MemHint(efd::MemHint::NONE)) LapenshardSlot(strName, nIndex, MS2Ptr<CItem>(m_items[nIndex]), 0, m_nKind);
}

// @0x140a70a30
int LapenshardSlotBag::FUN_140a70a30()
{
    if (m_bEquipMode != 0)
        return (int)m_equipSlots.GetCount();
    return (int)m_items.GetCount();
}

// @0x140a70a80
void LapenshardSlotBag::vfunc_13(int nIndex)
{
    LapenshardSlot* pSlot = FUN_140a6fef0(FUN_1422cd070(nIndex));
    if (pSlot != 0)
        pSlot->vfunc_11();
}

// @0x140a70ad0
void LapenshardSlotBag::vfunc_14(int nIndex)
{
    LapenshardSlot* pSlot = FUN_140a6fef0(FUN_1422cd070(nIndex));
    if (pSlot != 0)
        pSlot->vfunc_10();
}

// @0x140a70b20
int LapenshardSlotBag::FUN_140a70b20(int nIndex)
{
    Unk_LapenEquipSlot slot = kLapenEquipSlotNone;
    if (m_equipSlots.Lookup(nIndex, slot))
        return slot;
    return kLapenEquipSlotNone;
}

// @0x140a70b70
LapenshardSlotBag* FUN_140a70b70(NotifyContext::BindData* p)
{
    LapenshardSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200084, (void**)&pBag))
        return pBag;
    else
        return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9f7c0-0x142c9f8e0 .text$yd
