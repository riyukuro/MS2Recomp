// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GemSlot and GemSlotBag (the gem page's slots).
// MS2-UNIT: ?\gemslot.cpp
// MS2-RANGE: 0x14126d170-0x14126fcd0 .text$mn
// MS2-RANGE: 0x1400eaed0-0x1400eb080 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400eafb0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400eafe0 ; probe
// MS2-PIN: ??0?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@IMMMI@Z 0x14126e9f0 ; unique
// MS2-PIN: ??0CNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@HI@Z 0x14126eae0 ; unique
// MS2-PIN: ??1?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@XZ 0x14126eb40 ; unique
// MS2-PIN: ??_GGemSlotBag@@UEAAPEAXI@Z 0x14126eb70 ; unique
// MS2-PIN: ?CreateNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@HII@Z 0x14126ebd0 ; unique
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x14126ec50 ; unique
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x14126ec70 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x14126ec90 ; unique
// MS2-PIN: ?FreePlexes@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXXZ 0x14126ed80 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBAIXZ 0x14126edf0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14126ee00 ; unique
// MS2-PIN: ?InitHashTable@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA_NI_N@Z 0x14126eef0 ; unique
// MS2-PIN: ?IsLocked@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBA_NXZ 0x14126f010 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBA_NHAEAH@Z 0x14126f040 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@HII@Z 0x14126f0a0 ; unique
// MS2-PIN: ?PickSize@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBAI_K@Z 0x14126f2b0 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXI@Z 0x14126f3a0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x14126f5d0 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXPEAU__POSITION@@@Z 0x14126f6e0 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@0@Z 0x14126f7d0 ; unique
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXMMM_N@Z 0x14126f930 ; unique
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXXZ 0x14126fae0 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@IEAA@H@Z 0x14126eb20 ; hand
// MS2-PIN: ?GetCount@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBA_KXZ 0x14126ede0 ; hand
// MS2-PIN: ?SetAt@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAPEAU__POSITION@@HH@Z 0x14126f890 ; hand
// MS2-PINS-END tplpin
// MS2-PIN: ??_7GemSlot@@6BBindData@NotifyContext@@@ 0x142ecd568 ; hand: primary vftable
// MS2-PIN: ?GetClassDesc@GemSlot@@UEBAPEBVClassInfo@efd@@XZ 0x14126e1e0 ; hand
// MS2-PIN: ?GetClassDesc@GemSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x14126edd0 ; hand
// MS2-PIN: ?TypeCast@GemSlot@@UEBA_NIPEAPEAX@Z 0x14126e250 ; hand
// MS2-PIN: ?TypeCast@GemSlot@@UEBA_NIPEAPEBX@Z 0x14126e2a0 ; hand
// MS2-PIN: ?TypeCast@GemSlotBag@@UEBA_NIPEAPEAX@Z 0x14126fa40 ; hand
// MS2-PIN: ?TypeCast@GemSlotBag@@UEBA_NIPEAPEBX@Z 0x14126fa90 ; hand
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gemslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gemslot.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/pcinfo.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/commonfiles/itemdata.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_GmActor
{
public:
    PCGemEquip* FUN_14165f460();                        // the gem equipment
};
class Unk_GmWorld
{
public:
    Unk_GmActor* FUN_141bd0cc0();                       // the local player's actor
    void FUN_1411a5110(CString strCategory, CString strName, CString strExtra, int nKind, void* pXform, float fVolume,
        int nOwner);                                    // play a sound event
};
Unk_GmWorld* FUN_1403ed2d0();
Unk_GmWorld* FUN_1403ed280();                           // the sound service

class Unk_ItemEquipData : public CItemData { };         // CItem::FUN_140527840's record

extern Unk_Inventory DAT_143ab2a90;

bool FUN_140222e10(int nGemType);                       // the gem type is valid
CString FUN_140219b10(int nGemType);                    // the name of a gem type
void* FUN_140a50b50(DragSlot* pSlot);                   // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                 // its item uid
bool FUN_1409b0350(Scaleform::GFx::Value* pValue);
bool FUN_141271f90(MS2Ptr<CItem> spItem);               // take the gem item off (packet 0x47)
bool FUN_141271960(MS2Ptr<CItem> spItem, int nSlot, int nFlag);   // put the gem item on (packet 0x47)

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(GemSlot);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

EE_IMPLEMENT_CONCRETE_CLASS_INFO(GemSlotBag);

GemSlotBag* FUN_14126e9a0(NotifyContext::BindData* p);

// @0x14126d170
GemSlot::GemSlot(const CString& strName, MS2Ptr<PCInfo> spPC, int nIndex, int nGemType)
    : MS2DragSlot(strName, nIndex), m_spPC(spPC)
{
    m_nGemType = nGemType;
}

// @0x14126d210
int GemSlot::vfunc_17()
{
    return vfunc_10();
}

// @0x14126d240
int GemSlot::vfunc_18(void* p)
{
    if (bool(m_spPC != 0))
    {
        if (m_spPC->FUN_140dba1c0() != 0)
        {
            Unk_GmActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pActor == 0)
                return 0;
            void* pItemSlot = FUN_140a50b50(static_cast<DragSlot*>(p));
            if (pItemSlot != 0)
            {
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_141405a10(pItemSlot));
                if (FUN_14126d880(spItem.get()) != 0)
                {
                    int nType = spItem->FUN_140527900()->vfunc_1();
                    if (nType == m_nGemType)
                    {
                        int nSlot = -1;
                        MS2Ptr<CItem> spWorn = pActor->FUN_14165f460()->FUN_141270140(nType);
                        if (spWorn.get() != 0)
                            nSlot = spWorn->FUN_140526b50();
                        FUN_141271960(spItem, nSlot, 0);
                    }
                }
            }
        }
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x14126d430
int GemSlot::vfunc_14()
{
    if (bool(m_spPC != 0))
    {
        if (m_spPC->FUN_140dba1c0() != 0)
        {
            MS2Ptr<CItem> spItem = vfunc_25();
            if (spItem.get() != 0)
                FUN_141271f90(spItem);
        }
    }
    return 1;
}

// @0x14126d500
int GemSlot::vfunc_20()
{
    DragSlot::vfunc_20();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            ((CItem*)spItem)->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    return 1;
}

// @0x14126d670
int GemSlot::vfunc_21()
{
    DragSlot::vfunc_21();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            ((CItem*)spItem)->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    return 1;
}

// @0x14126d7e0
MS2Ptr<CItem> GemSlot::vfunc_25()
{
    if (m_spPC == 0)
        return MS2Ptr<CItem>(0);
    return m_spPC->FUN_140dba560(m_nGemType);
}

// @0x14126d880
int GemSlot::FUN_14126d880(CItem* pItem)
{
    if (m_spPC == 0)
        return 0;
    Unk_GmActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pActor == 0)
        return 0;
    if (pItem == 0)
        return 0;
    if (pItem->FUN_140527840()->FUN_14053c5c0() != 7)
        return 0;
    if (m_spPC->FUN_140dba1c0() == 0)
        return 0;
    return 1;
}

// @0x14126d930
int GemSlot::GetGemType()
{
    return m_nGemType;
}

// @0x14126d950
int GemSlot::FUN_14126d950()
{
    if (m_spPC == 0)
        return 0;
    if (m_spPC->FUN_140dba1c0() != 0)
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: the exe keeps two more ASTooltip/MS2Ptr temps alive (EH maxState 8 vs 6, frame 0xb8)
// @0x14126d9b0 (ITooltip::vfunc_0)
int GemSlot::vfunc_0(void* p)
{
    if (m_spPC == 0)
        return 0;
    Unk_GmActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pActor == 0)
        return 0;
    if (FUN_140222e10(m_nGemType) == false)
        return 0;
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() == 0)
    {
        ASTooltip tip(2);
        tip.FUN_1409e26b0(StringFormat(L"$s_tooltip_myinfo_gem_{0}", FUN_140219b10(m_nGemType)));
        tip.FUN_1409c6dc0(3);
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    int nFlags = 0x100;
    if (m_spPC->FUN_140dba1c0() != 0)
        nFlags = 0x200;
    ASTooltip tip(pActor, nFlags, 2);
    if (tip.FUN_1409e0d40(spItem.get()) == 0)
        return 0;
    tip.FUN_1409c69b0(vfunc_22());
    *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
    return 1;
}

// MS2-FUNCTIONAL: the exe keeps different MS2Ptr temps for the item tests; frame and EH states differ
// @0x14126dd30
int GemSlot::vfunc_8(void* p)
{
    if (m_spPC == 0)
        return 0;
    Unk_GmActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pActor == 0)
        return 0;
    MS2Ptr<CItem> spItem = vfunc_25();
    bool bValid = FUN_140222e10(m_nGemType);
    if (bValid != false && spItem.get() != 0)
        return 0;
    int nFlags = 0x49;
    if (FUN_14126d950() != 0)
        nFlags = 0x4d;
    ASSlot slot(2);
    slot.FUN_1407cbbe0("lock", bValid == false);
    if (spItem.get() != 0)
    {
        if (spItem->FUN_140527900() != 0)
        {
            if (slot.FUN_1409c3860(vfunc_25().get(), pActor, nFlags) != 0)
            {
                if (m_spPC->FUN_140dba1c0() == 0)
                    slot.FUN_1407cbbe0("config", false);
                else
                    slot.FUN_1407cbbe0("config", ((CItem*)vfunc_25())->FUN_140527840()->FUN_14053c5e0() == 1);
                slot.FUN_1407cb9c0("gemSystem", spItem->FUN_140527900()->vfunc_1());
            }
        }
    }
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    return 1;
}

// @0x14126e080
void GemSlot::vfunc_9()
{
    if (FUN_1409b0350(&m_value18) == 0)
    {
        ASObj obj(m_value18, 2);
        if (obj.FUN_1422ba9a0() == 0)
            obj.FUN_1407cba60("m_strSlotType", FUN_140219b10(m_nGemType));
    }
}

// @0x14126e2f0
void FUN_14126e2f0(const CString& strName, MS2Ptr<PCInfo> spPC)
{
    GemSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) GemSlotBag(strName, spPC);
    if (pBag)
    {
        int nCount = pBag->FUN_14126e930();
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x14126e3f0
void FUN_14126e3f0(const CString& strName)
{
    GemSlotBag* pBag = FUN_14126e9a0(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// MS2-FUNCTIONAL: SetAt call order/temps differ from the exe frame
// @0x14126e440
GemSlotBag::GemSlotBag(const CString& strName, MS2Ptr<PCInfo> spPC)
    : DragSlotBag(strName), m_spPC(spPC)
{
    m_mapSlot.SetAt(0, 1);
    m_mapSlot.SetAt(1, 5);
    m_mapSlot.SetAt(2, 3);
    m_mapSlot.SetAt(3, 2);
    m_mapSlot.SetAt(4, 4);
    m_mapSlot.SetAt(5, 6);
    m_mapSlot.SetAt(6, 9);
    m_mapSlot.SetAt(7, 8);
    m_mapSlot.SetAt(8, 7);
    m_mapSlot.SetAt(9, 10);
    m_mapSlot.SetAt(10, 11);
    m_mapSlot.SetAt(11, 12);
}

// @0x14126e6f0
GemSlotBag::~GemSlotBag()
{
}

// @0x14126e750
CString GemSlotBag::vfunc_15(int nIndex)
{
    CString str;
    str.Format("%s.%d", (const char*)FUN_1422c89f0(), nIndex);
    return str;
}

// @0x14126e810
DragSlot* GemSlotBag::vfunc_16(int nIndex)
{
    CString strName = vfunc_15(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) GemSlot(strName, m_spPC, nIndex, FUN_14126e960(nIndex));
}

// @0x14126e930
int GemSlotBag::FUN_14126e930()
{
    return (int)m_mapSlot.GetCount();
}

// @0x14126e960
int GemSlotBag::FUN_14126e960(int nIndex)
{
    int nType;
    if (m_mapSlot.Lookup(nIndex, nType))
        return nType;
    return 0;
}

// @0x14126e9a0
GemSlotBag* FUN_14126e9a0(NotifyContext::BindData* p)
{
    GemSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200054, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cae2b0-0x142cae340 .text$yd
