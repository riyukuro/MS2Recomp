// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). EquipSlot and EquipSlotBag (the equipment window's slots).
// MS2-UNIT: ?\equipslot.cpp
// MS2-RANGE: 0x14120c0e0-0x14120f7c0 .text$mn
// MS2-RANGE: 0x1400e8e70-0x1400e9020 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400e8f50 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400e8f80 ; probe
// MS2-PIN: ?GetNode@?$CAtlMap@HW4Unk_InventoryEquipSlot@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14120ea00 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7EquipSlot@@6BBindData@NotifyContext@@@ 0x142ec1568 ; hand: primary vftable
// MS2-PIN: ??$format_arg@DW4Unk_InventoryEquipSlot@@@fmt@@YAXAEAV?$BasicFormatter@D@0@AEAPEBDAEBW4Unk_InventoryEquipSlot@@@Z 0x14120e4a0 ; hand: FormatCustomArg call site
// MS2-PIN: ?GetClassDesc@EquipSlot@@UEBAPEBVClassInfo@efd@@XZ 0x14120d6b0 ; hand
// MS2-PIN: ?GetClassDesc@EquipSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x14120e9d0 ; hand
// MS2-PIN: ?TypeCast@EquipSlot@@UEBA_NIPEAPEAX@Z 0x14120d720 ; hand
// MS2-PIN: ?TypeCast@EquipSlot@@UEBA_NIPEAPEBX@Z 0x14120d770 ; hand
// MS2-PIN: ?TypeCast@EquipSlotBag@@UEBA_NIPEAPEAX@Z 0x14120f640 ; hand
// MS2-PIN: ?TypeCast@EquipSlotBag@@UEBA_NIPEAPEBX@Z 0x14120f690 ; hand
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\equipslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "equipslot.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/pcinfo.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/commonfiles/itemdata.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_EqEquipSet
{
public:
    char FUN_1411ea770();
};
class Unk_EqPlayer
{
public:
    Unk_EqEquipSet* FUN_1416561a0();
};
class Unk_EqWorld
{
public:
    Unk_EqPlayer* FUN_141bd0cc0();
    void FUN_1411a5110(CString strCategory, CString strName, CString strExtra, int nKind, void* pXform, float fVolume,
        int nOwner);                                    // play a sound event
};
Unk_EqWorld* FUN_1403ed2d0();
Unk_EqWorld* FUN_1403ed280();                           // the sound service

class Unk_ItemEquipData : public CItemData { };         // CItem::FUN_140527840's record

extern Unk_Inventory DAT_143ab2a90;

void FUN_141275260(int nStringId, int nA, int nB);      // notice by string id
void FUN_140d73bc0(int nStringId, int nType, void* p, CStringW strTag);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
CStringW GetStringCommonByKey(const CStringW& strKey);         // string table lookup by key
CStringW GetStringCommon(int nStringId);                  // a string table text
CString FUN_1405451e0(int nType);                       // the name of an equip slot type
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);               // item link / popup for the item
void* FUN_140a50b50(DragSlot* pSlot);                   // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                 // its item uid
int FUN_141421230(MS2Ptr<CItem> spFrom, MS2Ptr<CItem> spTo, MS2Ptr<PCInfo> spPC);   // may the worn items be swapped
bool FUN_1409b0350(Scaleform::GFx::Value* pValue);
void FUN_1401fb9a0(unsigned char* payload, COutputStream& stream);
void FUN_140710590(COutPacket& packet);                 // send the packet

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);

// The equip request payload of the equip packet 0x16.
struct Unk_EquipReq
{
    __int64 m_nItemUid;
    int m_nSlot;
    Unk_EquipReq()                                      // 0x14120d5b0
    {
        m_nItemUid = 0;
        m_nSlot = 0;
    }
};

// The ids of the two entries of the EquipSlot / EquipSlotBag SetupClassInfo.
EE_IMPLEMENT_CONCRETE_CLASS_INFO(EquipSlot);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

EE_IMPLEMENT_CONCRETE_CLASS_INFO(EquipSlotBag);

EquipSlot* FUN_14120d560(NotifyContext::BindData* p);
EquipSlotBag* FUN_14120e140(NotifyContext::BindData* p);
void FUN_14120d7c0(const CString& strName, MS2Ptr<PCInfo> spPC, int nKind, int nUnk);
void FUN_14120d8e0(const CString& strName);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

// @0x14120c0e0
EquipSlot::EquipSlot(const CString& strName, int nIndex, MS2Ptr<PCInfo> spPC, int nSlot, int nKind, int nUnk)
    : MS2DragSlot(strName, nIndex), m_spPC(spPC)
{
    m_nKind = nKind;
    m_nUnkA4 = nUnk;
    m_nSlot = nSlot;
    SetEnabled(true);
}

// @0x14120c1b0
int EquipSlot::vfunc_13()
{
    return 0;
}

// @0x14120c1c0
int EquipSlot::vfunc_14()
{
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        DAT_143ab2a90.FUN_140a62920(((CItem*)spItem)->FUN_140526a50());
    return 1;
}

// @0x14120c240
int EquipSlot::vfunc_15()
{
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
    {
        if (FUN_14120d1f0() != 0)
            FUN_140d2cfc0(spItem);
        else
            FUN_141275260(0xa5, 1, 1);
    }
    return DragSlot::vfunc_15();
}

// @0x14120c2f0
int EquipSlot::vfunc_17()
{
    return vfunc_10();
}

// MS2-FUNCTIONAL: the exe puts the equip-swap branch last and keeps different frame temps (frame 0x138 vs 0x148)
// @0x14120c320
int EquipSlot::vfunc_18(void* p)
{
    DragSlot* pDrag = static_cast<DragSlot*>(p);
    void* pItemSlot = FUN_140a50b50(pDrag);
    if (pItemSlot != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_141405a10(pItemSlot));
        if (spItem.get() != 0)
        {
            if (FUN_14120d2e0(spItem.get()) != 0)
                DAT_143ab2a90.FUN_140a62270(spItem.get(), m_nSlot, m_nKind, 0);
        }
    }
    else
    {
        EquipSlot* pFrom = FUN_14120d560(pDrag);
        if (pFrom != 0)
        {
            MS2Ptr<CItem> spFrom = pFrom->vfunc_25();
            MS2Ptr<CItem> spThis = vfunc_25();
            if (FUN_141421230(spFrom, spThis, m_spPC) != 0)
            {
                Unk_EquipReq req;
                req.m_nItemUid = ((CItem*)spFrom)->FUN_140526a50();
                req.m_nSlot = m_nSlot;
                COutPacket packet(static_cast<int>(SendOp::ItemEquip), 0);
                packet.WriteUInt8(2);
                FUN_1401fb9a0((unsigned char*)&req, packet);
                FUN_140710590(packet);
            }
        }
    }
    return pDrag->vfunc_10();
}

// @0x14120c5e0
int EquipSlot::vfunc_20()
{
    DragSlot::vfunc_20();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            ((CItem*)spItem)->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    return 1;
}

// @0x14120c750
int EquipSlot::vfunc_21()
{
    DragSlot::vfunc_21();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            ((CItem*)spItem)->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    return 1;
}

// MS2-FUNCTIONAL: success/failure return temps sit in different frame slots
// @0x14120c8c0 (ITooltip::vfunc_0)
int EquipSlot::vfunc_0(void* p)
{
    if (m_spPC == 0)
        return 0;
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = FUN_14120ce90(m_nKind);
    int nFlags = 0x100;
    if (m_spPC->FUN_140dba1c0() != 0)
        nFlags = 0x200;
    ASTooltip tip(pPlayer, nFlags, 2);
    if (tip.FUN_1409e0d40(spItem.get()) == 0)
        return 0;
    tip.FUN_1409c69b0(vfunc_22());
    if (IsEnabled() == true)
        tip.FUN_1409db7b0(spItem);
    *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
    return 1;
}

// MS2-FUNCTIONAL: the exe tests the ASSlot fill with a trailing else block; frame temps differ
// @0x14120cae0
int EquipSlot::vfunc_8(void* p)
{
    if (m_spPC == 0)
        return 0;
    Unk_EqPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem == 0)
        return 0;
    int nFlags = 0x49;
    int bPc = FUN_14120d1f0();
    if (bPc != 0)
        nFlags |= 4;
    ASSlot slot(2);
    if (slot.FUN_1409c41f0(spItem.get(), pPlayer, m_nSlot, nFlags) == 0)
        return 0;
    if (m_nSlot == 4)
    {
        if (((CItem*)spItem)->FUN_140527840()->FUN_14053d460() != false)
        {
            slot.FUN_1409c2090(1);
            goto LAB_gray_done;
        }
    }
    if (m_nSlot == 9)
    {
        if (((CItem*)spItem)->FUN_140527840()->FUN_14053d2b0() != false)
            slot.FUN_1409c2090(1);
    }
LAB_gray_done:
    if (bPc != 0 && m_nKind == 2)
    {
        if (pPlayer->FUN_1416561a0()->FUN_1411ea770() == '\0')
            slot.FUN_1409c2710(1);
    }
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    return 1;
}

// @0x14120cd40
void EquipSlot::vfunc_9()
{
    if (FUN_1409b0350(&m_value18) == 0)
    {
        ASObj obj(m_value18, 2);
        if (obj.FUN_1422ba9a0() == 0)
            obj.FUN_1407cba60("m_strSlotType", FUN_1405451e0(m_nSlot));
    }
}

// @0x14120ce00
MS2Ptr<CItem> EquipSlot::vfunc_25()
{
    if (m_spPC == 0)
        return MS2Ptr<CItem>(0);
    return FUN_14120ce90(m_nKind);
}

// MS2-FUNCTIONAL: return/copy temps of the MS2Ptr<CItem> shape differ
// @0x14120ce90
MS2Ptr<CItem> EquipSlot::FUN_14120ce90(int nKind)
{
    if (m_spPC == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CItem> spItem = m_spPC->FUN_140dba8b0(nKind, (Unk_InventoryEquipSlot)m_nSlot);
    if (spItem.get() == 0)
    {
        if (m_nSlot == 4)
        {
            spItem = m_spPC->FUN_140dba8b0(nKind, (Unk_InventoryEquipSlot)5);
            if (spItem.get() != 0)
            {
                if (((CItem*)spItem)->FUN_140527840()->FUN_14053d460() != false)
                    return spItem;
            }
        }
        else if (m_nSlot == 9)
        {
            spItem = m_spPC->FUN_140dba8b0(nKind, (Unk_InventoryEquipSlot)8);
            if (spItem.get() != 0)
            {
                if (((CItem*)spItem)->FUN_140527840()->FUN_14053d2b0() != false)
                    return spItem;
            }
        }
        return MS2Ptr<CItem>(0);
    }
    return spItem;
}

// @0x14120d190
int EquipSlot::GetKind()
{
    return m_nKind;
}

// @0x14120d1b0
CStringW EquipSlot::vfunc_22()
{
    return GetStringCommon(0x752);
}

// @0x14120d1f0
int EquipSlot::FUN_14120d1f0()
{
    if (m_spPC == 0)
        return 0;
    if (m_spPC->FUN_140dba1c0() != 0)
        return 1;
    return 0;
}

// @0x14120d250
int EquipSlot::FUN_14120d250(CItem* pItem)
{
    if (FUN_14120d510(pItem) == 0)
        return 0;
    if (pItem->FUN_140527840()->FUN_14053e130() != false)
    {
        FUN_140d73bc0(0xd7, 0, 0, CStringW(L""));
        return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: CStringW notice temps: exe frame is 0x10 smaller (maxState 2)
// @0x14120d2e0
int EquipSlot::FUN_14120d2e0(CItem* pItem)
{
    if (FUN_14120d1f0() == 0)
        return 0;
    bool bFlag = false;
    if (m_nKind == 1 || m_nKind == 2)
        bFlag = true;
    if (bFlag && pItem->FUN_1405258b0() == 0)
    {
        if (m_nKind == 2)
            FUN_140d73aa0(GetStringCommonByKey(CStringW(L"s_item_err_Invalid_slot_codi")), 0, 0, CStringW(L""));
        else
            FUN_140d73bc0(0xd3, 0, 0, CStringW(L""));
        return 0;
    }
    if (pItem->FUN_140527840()->FUN_14053eba0()->FUN_14054b450(m_nSlot) == false)
    {
        FUN_140d73bc0(0xd3, 0, 0, CStringW(L""));
        return 0;
    }
    if (DAT_143ab2a90.FUN_140a63950(pItem, m_nSlot, m_nKind) == 0)
        return 0;
    return 1;
}

// @0x14120d510
int EquipSlot::FUN_14120d510(CItem* pItem)
{
    if (FUN_14120d1f0() == 0)
        return 0;
    if (DAT_143ab2a90.FUN_140a655b0(pItem) == 0)
        return 0;
    return 1;
}

// @0x14120d560
EquipSlot* FUN_14120d560(NotifyContext::BindData* p)
{
    EquipSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x620002b, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x14120d7c0
void FUN_14120d7c0(const CString& strName, MS2Ptr<PCInfo> spPC, int nKind, int nUnk)
{
    EquipSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) EquipSlotBag(strName, spPC, nKind, nUnk);
    if (pBag)
    {
        int nCount = pBag->FUN_14120e090();
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x14120d8e0
void FUN_14120d8e0(const CString& strName)
{
    EquipSlotBag* pBag = FUN_14120e140(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x14120d930
EquipSlotBag::EquipSlotBag(const CString& strName, MS2Ptr<PCInfo> spPC, int nKind, int nUnk)
    : DragSlotBag(strName), m_spPC(spPC), m_nKind(nKind), m_nUnk9C(nUnk)
{
    if (nKind == 1 || nKind == 2)
    {
        m_mapSlot.SetAt(0, (Unk_InventoryEquipSlot)6);
        m_mapSlot.SetAt(1, (Unk_InventoryEquipSlot)0xe);
        m_mapSlot.SetAt(2, (Unk_InventoryEquipSlot)0xd);
        m_mapSlot.SetAt(3, (Unk_InventoryEquipSlot)0xc);
        m_mapSlot.SetAt(4, (Unk_InventoryEquipSlot)8);
        m_mapSlot.SetAt(5, (Unk_InventoryEquipSlot)10);
        m_mapSlot.SetAt(6, (Unk_InventoryEquipSlot)9);
        m_mapSlot.SetAt(7, (Unk_InventoryEquipSlot)0x10);
        m_mapSlot.SetAt(8, (Unk_InventoryEquipSlot)7);
        m_mapSlot.SetAt(9, (Unk_InventoryEquipSlot)0xb);
        m_mapSlot.SetAt(10, (Unk_InventoryEquipSlot)5);
        m_mapSlot.SetAt(11, (Unk_InventoryEquipSlot)4);
    }
    else
    {
        m_mapSlot.SetAt(0, (Unk_InventoryEquipSlot)6);
        m_mapSlot.SetAt(1, (Unk_InventoryEquipSlot)0xe);
        m_mapSlot.SetAt(2, (Unk_InventoryEquipSlot)0xf);
        m_mapSlot.SetAt(3, (Unk_InventoryEquipSlot)0x11);
        m_mapSlot.SetAt(4, (Unk_InventoryEquipSlot)8);
        m_mapSlot.SetAt(5, (Unk_InventoryEquipSlot)10);
        m_mapSlot.SetAt(6, (Unk_InventoryEquipSlot)9);
        m_mapSlot.SetAt(7, (Unk_InventoryEquipSlot)0x10);
        m_mapSlot.SetAt(8, (Unk_InventoryEquipSlot)7);
        m_mapSlot.SetAt(9, (Unk_InventoryEquipSlot)0xb);
        m_mapSlot.SetAt(10, (Unk_InventoryEquipSlot)5);
        m_mapSlot.SetAt(11, (Unk_InventoryEquipSlot)4);
    }
}

// @0x14120de20
EquipSlotBag::~EquipSlotBag()
{
}

// @0x14120de80
CString EquipSlotBag::vfunc_15(int nIndex)
{
    Unk_InventoryEquipSlot nSlot = FUN_14120e0c0(nIndex);
    CString str = StringFormat("{0}.{1}", FUN_1422c89f0(), nSlot);
    return str;
}

// @0x14120df40
DragSlot* EquipSlotBag::vfunc_16(int nIndex)
{
    CString strName = vfunc_15(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) EquipSlot(strName, nIndex, m_spPC, FUN_14120e0c0(nIndex), m_nKind, m_nUnk9C);
}

// @0x14120e090
int EquipSlotBag::FUN_14120e090()
{
    return (int)m_mapSlot.GetCount();
}

// @0x14120e0c0
Unk_InventoryEquipSlot EquipSlotBag::FUN_14120e0c0(int nIndex)
{
    ATL::CAtlMap<int, Unk_InventoryEquipSlot>* pMap = &m_mapSlot;
    Unk_InventoryEquipSlot nSlot;
    if (pMap->Lookup(nIndex, nSlot))
        return nSlot;
    return (Unk_InventoryEquipSlot)0;
}

// @0x14120e140
EquipSlotBag* FUN_14120e140(NotifyContext::BindData* p)
{
    EquipSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x620002c, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cad6f0-0x142cad780 .text$yd
