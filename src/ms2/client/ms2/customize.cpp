// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Customize: the preview / commit / restore controller of the
// beauty shop, dye and hair dialogs, with its nested BeautyShopContext, EditItems, CloneItems and Equipment (see
// customize.h). Names are invented (the third-party v2525 draft of this TU, work/ext/v2525/.../tu/140ccab40.cpp, was the
// hint); the shared header statics (tag strings, header_statics_a.h) are this TU's dynamic initializers.
// MS2-UNIT: ?\customize.cpp
// MS2-RANGE: 0x1400d0080-0x1400d00b0 .text$di
// MS2-RANGE: 0x1400d02f0-0x1400d04f0 .text$di
// MS2-RANGE: 0x140ccac60-0x140cd73b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\customize.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/customize.h"

// The equipment tag strings (a shared header's statics). Only the initializers inside this unit's ranges are defined:
// Cap (0x1400d0050) and Default..Slot (0x1400d00b0..) are attributed to ?\tabcontentspetinfo.cpp and unit_1400d00b0.
static CString s_strCustomize = "Customize";
static CString s_strUndo = "Undo";
static CString s_strVIP = "VIP";
static CString s_strWillUpdatePos = "WillUpdatePos";
#include "ms2/placeholder/header_statics_a.h"

#include <NiSmartPointer.h>
#include "ms2/client/ms2/uibeautyshopstyledialog.h"     // IItemCustomizeEventListener
#include "ms2/client/ms2/uicameraeditdialog.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/itemcustomizecontroller_1.h"
#include "ms2/client/ms2/itemmorphcontroller.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citemextradata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/itemdata.h"                    // ItemColorEx, ItemModelHead
#include "ms2/commonfiles/item.h"                        // Unk_UserProxyItemData (CItemExtraData)
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// CItem::FUN_140527840's record is the item's CItemData (citem.h names it Unk_ItemEquipData).
class Unk_ItemEquipData : public CItemData {};
// CEquipItem::FUN_1411dc7f0's record is the item's CItemData too.
struct Unk_EquipItemData : public CItemData {};
// CItemData::FUN_14053ec70 returns the <customize> block of the model data (citemdata.h declares it void).
class Unk_CustomizeItemData : public CItemData
{
public:
    ItemModelHead* FUN_14053ec70();
};

// The world (FUN_1403ed2d0): the player of an object id.
class Unk_CustomizeWorld
{
public:
    PC* FUN_141bd1290(int nObjectId);
};
Unk_CustomizeWorld* FUN_1403ed2d0();
int FUN_14123c580(PCBase* pPc);                                     // the object id of a player
CUIService* FUN_1403ed2b0();

// The item event hub the Customize registers with (uiitemenchantdialog.h).
class Unk_CustomizeItemEvents;
Unk_CustomizeItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_CustomizeItemEvents* pHub, UIItemEventListener* pListener);     // register
void FUN_1419caeb0(Unk_CustomizeItemEvents* pHub, UIItemEventListener* pListener);     // unregister

// The palette table (FUN_140281980).
class Unk_CustomizeColorTable
{
public:
    MS2Ptr<ItemColorEx> FUN_1405587f0(int nPalette, int nIndex);
};
Unk_CustomizeColorTable* FUN_140281980();
MS2Ptr<ItemColorEx> FUN_140f022f0(int nPalette, unsigned nIndex);   // a colour of a palette (uibeautyshopstyledialog.cpp)
int FUN_140f02bc0();                                                // the hair palette id

// The avatar colour / equip helpers (unit_14142xxxx).
void FUN_140f014b0(ATL::CAtlList<MS2Ptr<CEquipItem> >& out, Unk_PCEquipSet* pSet);     // the worn items
int FUN_141420f10(CItemData* pData, PC* pPc);                      // the equip slot of an item for the player
MS2Ptr<CEquipItem> FUN_1414211a0(int nSlot, PC* pPc);              // the worn item of a slot
int FUN_141421690(CItem* pItem);                                    // the item is a real (owned) one
int FUN_141423650(const int* pnColor, int nSlot, PC* pPc);          // set a body colour
int FUN_1414239e0(int* pnColor, int nSlot, PC* pPc);                // get a body colour
int FUN_141423760(const ItemColorEx& kColor, PC* pPc);              // dye the body
int FUN_141423cf0(__int64 nUid, const ItemColorEx& kColor, PC* pPc, int n);    // dye a worn item
int FUN_141423fb0(__int64 nUid, const int* pnColor, int nSlot, PC* pPc, int n);
void FUN_141424230(__int64 nUid, PC* pPc);                          // undo the dye of a worn item
int FUN_141424760(MS2Ptr<CItem> spItem, int* pnColor, int nSlot, PC* pPc);
NiPointer<CItemCustomizeController> FUN_1414131e0(MS2Ptr<CEquipItem> spEquip, PC* pPc, IItemCustomizeEventListener* pListener);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                       // CItemData of an item id
__int64 FUN_14028d0e0();                                            // a new uid
extern Unk_StreamPoint DAT_143b01a60;                               // efd::Point3::ZERO

// The part handle FUN_140cd1a30 returns (the callers declare their own view of it).
class Unk_BSPartHandle : public NiPointer<CItemCustomizeController>
{
public:
    Unk_BSPartHandle(const NiPointer<CItemCustomizeController>& sp) : NiPointer<CItemCustomizeController>(sp) {}
};

// @0x140ccac60 a copy of the item that keeps its +0x24 variant
MS2Ptr<CItem> FUN_140ccac60(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CItem> spCopy = spItem->FUN_140524250();
    if (spCopy.get()) {
        int nVariant = spItem->FUN_14052a150();
        if (nVariant >= 0)
            spCopy->FUN_14052a130(nVariant);
    }
    return spCopy;
}

// @0x140cd4650
inline MS2Ptr<CItem> FUN_140cd4650(MS2Ptr<CItem> spItem)
{
    MS2Ptr<CItem> spCopy = FUN_140ccac60(spItem);
    return spCopy;
}

// @0x140cd4310 the appearance of two items is the same
inline int FUN_140cd4310(MS2Ptr<CItem> spA, MS2Ptr<CItem> spB)
{
    if (spA == 0 || spB == 0 || spA->FUN_140527870() == 0 || spB->FUN_140527870() == 0)
        return 0;
    if (spA->FUN_1405276c0() != spB->FUN_1405276c0())
        return 0;
    CItemExtraData* pB = static_cast<CItemExtraData*>(static_cast<CPtred*>(spB->FUN_140527870()));
    CItemExtraData* pA = static_cast<CItemExtraData*>(static_cast<CPtred*>(spA->FUN_140527870()));
    return pA->vfunc_1(pB);
}

// @0x140cd4460
inline int FUN_140cd4460(MS2Ptr<CItem> spA, MS2Ptr<CItem> spB)
{
    if (spA == 0 || spB == 0 || spA->FUN_140527870() == 0 || spB->FUN_140527870() == 0)
        return 0;
    CItemExtraData* pB = static_cast<CItemExtraData*>(static_cast<CPtred*>(spB->FUN_140527870()));
    CItemExtraData* pA = static_cast<CItemExtraData*>(static_cast<CPtred*>(spA->FUN_140527870()));
    return pA->vfunc_2(pB);
}

// @0x140cd4560 the colours of two items are the same
inline int FUN_140cd4560(MS2Ptr<CItem> spA, MS2Ptr<CItem> spB)
{
    if (spA == 0 || spB == 0 || spA->FUN_140527870() == 0 || spB->FUN_140527870() == 0)
        return 0;
    CItemExtraData* pB = static_cast<CItemExtraData*>(static_cast<CPtred*>(spB->FUN_140527870()));
    return static_cast<CItemExtraData*>(static_cast<CPtred*>(spA->FUN_140527870()))->FUN_140599830(pB);
}

// @0x140cd3e30
inline int FUN_140cd3e30() { return 2; }
// @0x140cd3e40
inline int FUN_140cd3e40() { return 2; }

// @0x140cd3e50 takes the preview (not owned) items off
inline void FUN_140cd3e50(PC* pPc)
{
    if (pPc == 0)
        return;
    ATL::CAtlList<MS2Ptr<CEquipItem> > lstEquips;
    pPc->FUN_1416561a0()->FUN_1411e22c0(lstEquips, FUN_140cd3e30());
    for (POSITION pos = lstEquips.GetHeadPosition(); pos != 0; lstEquips.GetNext(pos)) {
        MS2Ptr<CEquipItem> spEquip = lstEquips.GetAt(pos);
        if (spEquip == 0)
            continue;
        MS2Ptr<CItem> spItem = spEquip->GetItem();
        if (spItem == 0)
            continue;
        if (FUN_141421690(spItem.get()) == 0)
            pPc->vfunc_128(spItem.get(), 1);
    }
}

// @0x140cd3fe0 tags the preview items "Undo" (bRemove: untags them)
inline void FUN_140cd3fe0(PC* pPc, int bRemove)
{
    if (pPc == 0)
        return;
    ATL::CAtlList<MS2Ptr<CEquipItem> > lstEquips;
    pPc->FUN_1416561a0()->FUN_1411e22c0(lstEquips, FUN_140cd3e30());
    for (POSITION pos = lstEquips.GetHeadPosition(); pos != 0; lstEquips.GetNext(pos)) {
        MS2Ptr<CEquipItem> spEquip = lstEquips.GetAt(pos);
        if (spEquip == 0)
            continue;
        MS2Ptr<CItem> spItem = spEquip->GetItem();
        if (spItem == 0)
            continue;
        if (FUN_141421690(spItem.get()) == 0) {
            if (bRemove != 0) {
                spEquip->FUN_1411dcf10(s_strUndo);
            } else {
                spEquip->FUN_1411dce60(s_strUndo);
                spEquip->FUN_1411dd280();
            }
        }
    }
}

// @0x140cd4190 takes every preview item off
inline void FUN_140cd4190(PC* pPc)
{
    if (pPc == 0)
        return;
    ATL::CAtlList<MS2Ptr<CEquipItem> > lstEquips;
    FUN_140f014b0(lstEquips, pPc->FUN_1416561a0());
    for (POSITION pos = lstEquips.GetHeadPosition(); pos != 0; lstEquips.GetNext(pos)) {
        MS2Ptr<CEquipItem> spEquip = lstEquips.GetAt(pos);
        if (spEquip == 0)
            continue;
        MS2Ptr<CItem> spItem = spEquip->GetItem();
        if (spItem == 0)
            continue;
        if (FUN_141421690(spItem.get()) == 0)
            pPc->vfunc_128(spItem.get(), 1);
    }
}

// @0x140cd46e0 marks a preview item
inline bool FUN_140cd46e0(MS2Ptr<CItem> spItem, bool bPreview)
{
    if (spItem == 0)
        return false;
    if (bPreview && FUN_141421690(spItem.get()) == 0) {
        spItem->FUN_14052a130(FUN_140cd3e40());
        spItem->FUN_14052a210(1);
        spItem->FUN_14052b630();
    }
    return true;
}

// @0x140cd47b0 the camera dialog
inline UICameraEditDialog* FUN_140cd47b0(eUIClassID nClass)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObject.get())
            return dynamic_cast<UICameraEditDialog*>(spObject.operator->());
    }
    return 0;
}

// @0x140cd5fd0 (itemcustomizecontroller_1.h: the inline first emitted here)
inline int CItemCustomizeController::GetDragging()
{
    return m_bDragging;
}

// ---- Customize::BeautyShopContext ----

// @0x140ccad60
Customize::BeautyShopContext::BeautyShopContext(int nEventId, __int64 n) : m_18(nEventId), m_20(n)
{
}

// ---- Customize::EditItems ----

// @0x140ccadc0
Customize::EditItems::EditItems(int nObjectId, Customize* pOwner)
    : m_nObjectId(nObjectId), m_spItem(0), m_spData(0), m_spController(0), m_pOwner(pOwner)
{
    m_pListener = m_pOwner ? m_pOwner->GetListener() : 0;
}

// @0x140ccaea0
Customize::EditItems::~EditItems()
{
    m_nObjectId = 0;
    m_spItem = 0;
    m_spData = 0;
    if (m_spController) {
        m_spController->Close();
        m_spController = 0;
    }
    m_pListener = 0;
}

// @0x140ccafa0
unsigned Customize::EditItems::GetItemId()
{
    if (m_spItem.get())
        return m_spItem->FUN_1405276c0();
    if (m_spData.get())
        return m_spData->FUN_14053c510();
    return 0;
}
MS2_REPLACE_METHOD(0x140CCAFA0, Customize::EditItems, GetItemId, 114, 0x582343C9);

// @0x140ccb020
unsigned __int64 Customize::EditItems::GetItemUid()
{
    if (m_spItem.get())
        return m_spItem->FUN_140526a50();
    return 0;
}
MS2_REPLACE_METHOD(0x140CCB020, Customize::EditItems, GetItemUid, 65, 0xB2B8DCEC);

// @0x140ccb070
MS2Ptr<CItem> Customize::EditItems::GetItem()
{
    return m_spItem;
}
MS2_REPLACE_METHOD(0x140CCB070, Customize::EditItems, GetItem, 65, 0xC47C7900);

// @0x140ccb0c0
unsigned Customize::EditItems::GetFlags()
{
    unsigned nFlags = 0;
    if (m_spData == 0)
        return nFlags;
    if (static_cast<Unk_CustomizeItemData*>(m_spData.operator->())->FUN_14053ec70()->FUN_140547130()) {
        CItemMorphController* pMorph = NiDynamicCast(CItemMorphController, m_spController);
        if (pMorph)
            nFlags |= 2;
        else
            nFlags |= 1;
    }
    if (static_cast<Unk_CustomizeItemData*>(m_spData.operator->())->FUN_14053ec70()->FUN_140547150())
        nFlags |= 4;
    if (static_cast<Unk_CustomizeItemData*>(m_spData.operator->())->FUN_14053ec70()->FUN_140547170())
        nFlags |= 8;
    return nFlags;
}

// @0x140ccb1e0
NiPointer<CItemCustomizeController> Customize::EditItems::GetController()
{
    return m_spController;
}
MS2_REPLACE_METHOD(0x140CCB1E0, Customize::EditItems, GetController, 65, 0x3E32AD95);

// @0x140ccb230
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::EditItems::Update()
{
    if (!(FUN_1403ed2b0()->FUN_141adbd10() == 0 && m_spController))
        return;
    int bDragging = 0;
    UICameraEditDialog* pCamera = FUN_140cd47b0(eUI_4ef2);
    if (pCamera)
        bDragging = pCamera->IsDragging();
    if (bDragging == 0) {
        efd::Point3 kHit = reinterpret_cast<efd::Point3&>(DAT_143b01a60);
        int bPick = m_spController->IsPickable(&kHit);
        m_spController->vfunc_38(bPick, kHit);
    }
    m_spController->vfunc_4();
}

// @0x140ccb340
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::EditItems::Select(MS2Ptr<CEquipItem> spEquip)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    if (m_spController) {
        m_spController->Close();
        m_spController = 0;
    }
    if (spEquip.get() && spEquip->GetItem().get()) {
        m_spItem = FUN_140cd4650(spEquip->GetItem());
        m_spData = static_cast<CItemData*>(m_spItem->FUN_140527840());
        m_spController = FUN_1414131e0(spEquip, pPc, m_pListener);
    }
}

// @0x140ccb5f0
void Customize::EditItems::SelectSlot(Unk_InventoryEquipSlot eSlot)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655e10(eSlot);
    Select(spEquip);
}
MS2_REPLACE_METHOD(0x140CCB5F0, Customize::EditItems, SelectSlot, 129, 0x6694C063);

// @0x140ccb680
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::EditItems::SelectId(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    if (spData->FUN_14053cf00()) {
        if (m_spController) {
            m_spController->Close();
            m_spController = 0;
        }
        m_spItem = 0;
        m_spData = spData;
        m_spController = 0;
    } else {
        PC* pPc = GetPC();
        if (pPc == 0)
            return;
        SelectSlot(static_cast<Unk_InventoryEquipSlot>(FUN_141420f10(spData.get(), pPc)));
    }
}

// @0x140ccb7d0
void Customize::EditItems::SelectUid(__int64 nUid)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655c30(nUid);
    Select(spEquip);
}
MS2_REPLACE_METHOD(0x140CCB7D0, Customize::EditItems, SelectUid, 130, 0x43251E96);

// @0x140ccb860
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
int Customize::EditItems::GetDragging()
{
    if (GetPC() == 0)
        return 0;
    if (m_spController)
        return m_spController->GetDragging();
    return 0;
}
MS2_REPLACE_METHOD(0x140CCB860, Customize::EditItems, GetDragging, 92, 0xA06624A9);

// @0x140ccb8d0
int Customize::EditItems::ApplyColor(int nIndex, int n)
{
    if (m_spData == 0 || nIndex < 0)
        return 0;
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    int nPalette = m_spData->FUN_14053e260();
    if (m_pOwner && m_pOwner->GetPalette() > 0)
        nPalette = m_pOwner->GetPalette();
    MS2Ptr<ItemColorEx> spColor = FUN_140f022f0(nPalette, nIndex);
    if (spColor == 0)
        return 0;
    if (m_spData->FUN_14053cf00())
        return FUN_141423760(*spColor, pPc);
    return FUN_141423cf0(GetItemUid(), *spColor, pPc, n);
}
MS2_REPLACE_METHOD(0x140CCB8D0, Customize::EditItems, ApplyColor, 392, 0x58D78622);

// @0x140ccba60
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
int Customize::EditItems::ApplyPalette(int nPalette, int nIndex, int n)
{
    if (m_spData == 0 || nPalette == 0)
        return 0;
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    if (m_pOwner && m_pOwner->GetPalette() > 0 && nPalette != FUN_140f02bc0())
        nPalette = m_pOwner->GetPalette();
    MS2Ptr<ItemColorEx> spColor = FUN_140281980()->FUN_1405587f0(nPalette, nIndex);
    if (spColor == 0)
        return 0;
    if (m_spData->FUN_14053cf00())
        return FUN_141423760(*spColor, pPc);
    return FUN_141423cf0(GetItemUid(), *spColor, pPc, n);
}

// @0x140ccbc00
int Customize::EditItems::SetColors(const int& nColor, int nSlot, int n)
{
    if (m_spData == 0)
        return 0;
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    if (m_spData->FUN_14053cf00())
        return FUN_141423650(&nColor, nSlot, pPc);
    return FUN_141423fb0(GetItemUid(), &nColor, nSlot, pPc, n);
}
MS2_REPLACE_METHOD(0x140CCBC00, Customize::EditItems, SetColors, 180, 0x155EB85E);

// @0x140ccbcc0
int Customize::EditItems::GetColors(int* pnColor, int nSlot)
{
    if (m_spData == 0)
        return 0;
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    if (m_spData->FUN_14053cf00())
        return FUN_1414239e0(pnColor, nSlot, pPc);
    return FUN_141424760(m_spItem, pnColor, nSlot, pPc);
}
MS2_REPLACE_METHOD(0x140CCBCC0, Customize::EditItems, GetColors, 199, 0x8E4E989E);

// @0x140ccbd90
PC* Customize::EditItems::GetPC()
{
    if (static_cast<unsigned>(m_nObjectId) > 0)
        return FUN_1403ed2d0()->FUN_141bd1290(m_nObjectId);
    return 0;
}
MS2_REPLACE_METHOD(0x140CCBD90, Customize::EditItems, GetPC, 50, 0x78C562D6);

// ---- Customize::CloneItems ----

// @0x140ccbdd0
Customize::CloneItems::CloneItems(int nObjectId, Customize* pOwner) : m_nObjectId(nObjectId), m_pOwner(pOwner)
{
    m_pListener = m_pOwner ? m_pOwner->GetListener() : 0;
    Init();
}

// @0x140ccbf00
Customize::CloneItems::~CloneItems()
{
    m_nObjectId = 0;
    m_mapItems.RemoveAll();
}

// @0x140ccbf80
void Customize::CloneItems::Collect(ItemMap& added, ItemMap& modified, ItemMap& removed)
{
    GetAdded(added);
    GetModified(modified);
    GetRemoved(removed);
}
MS2_REPLACE_METHOD(0x140CCBF80, Customize::CloneItems, Collect, 74, 0xA09D76DD);

// @0x140ccbfd0 puts the worn items back (the slots in the list keep the "Customize" tag)
void Customize::CloneItems::Restore(ATL::CAtlList<Unk_InventoryEquipSlot>& slots)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    FUN_140cd3fe0(pPc, 0);
    FUN_140cd4190(pPc);
    for (POSITION pos = m_mapItems.GetStartPosition(); pos != 0;) {
        MS2Ptr<CItem> spItem = m_mapItems.GetNextValue(pos);
        if (spItem == 0)
            continue;
        pPc->vfunc_127(spItem.get(), 1);
        if (!slots.IsEmpty()) {
            Unk_InventoryEquipSlot eSlot = static_cast<Unk_InventoryEquipSlot>(pPc->FUN_1416569b0(spItem.get()));
            if (slots.Find(eSlot)) {
                MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655e10(eSlot);
                if (spEquip.get()) {
                    spEquip->FUN_1411dce60(s_strCustomize);
                    spEquip->FUN_1411dd280();
                }
            }
        }
    }
    m_mapItems.RemoveAll();
    FUN_141423650(&m_anColor[0], 0, pPc);
    FUN_141423650(&m_anColor[1], 1, pPc);
    FUN_140cd3fe0(pPc, 1);
}

// @0x140ccc1f0
void Customize::CloneItems::CollectUid(__int64 nUid, ItemMap& added, ItemMap& modified, ItemMap& removed)
{
    GetAddedUid(added, nUid);
    GetModifiedUid(modified, nUid);
    GetRemovedUid(removed, nUid);
}
MS2_REPLACE_METHOD(0x140CCC1F0, Customize::CloneItems, CollectUid, 89, 0xE89F8525);

// @0x140ccc250
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::CloneItems::RestoreUid(__int64 nUid)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    for (POSITION pos = m_mapItems.GetStartPosition(); pos != 0;) {
        MS2Ptr<CItem> spItem = m_mapItems.GetNextValue(pos);
        if (spItem.get() && spItem->FUN_140526a50() == nUid) {
            pPc->vfunc_127(FUN_140cd4650(spItem).get(), 1);
            return;
        }
    }
    MS2Ptr<CItem> spItem = pPc->FUN_141655b80(nUid);
    if (!(spItem.get() && spItem->FUN_140527840()))
        return;
    if (!spItem->FUN_140527840()->FUN_14053cf00())
        pPc->vfunc_128(spItem.get(), 1);
}

// @0x140ccc470
void Customize::CloneItems::CollectSlot(Unk_InventoryEquipSlot eSlot, ItemMap& added, ItemMap& modified, ItemMap& removed)
{
    GetAddedSlot(added, eSlot);
    GetModifiedSlot(modified, eSlot);
}
MS2_REPLACE_METHOD(0x140CCC470, Customize::CloneItems, CollectSlot, 68, 0x3B299A96);

// @0x140ccc4c0
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::CloneItems::RestoreSlot(Unk_InventoryEquipSlot eSlot)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    if (eSlot == 0) {
        FUN_141423650(&m_anColor[0], 0, pPc);
        FUN_141423650(&m_anColor[1], 1, pPc);
        return;
    }
    for (POSITION pos = m_mapItems.GetStartPosition(); pos != 0;) {
        MS2Ptr<CItem> spItem = m_mapItems.GetNextValue(pos);
        if (pPc->FUN_1416569b0(spItem.get()) == eSlot) {
            pPc->vfunc_127(FUN_140cd4650(spItem).get(), 1);
            return;
        }
    }
    MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655e10(eSlot);
    if (spEquip.get() && spEquip->GetItem().get() && spEquip->GetItem()->FUN_140527840())
        pPc->vfunc_128(spEquip->GetItem().get(), 1);
}

// @0x140ccc860 previews an item on the slot; the paired slots (8/9 top and bottom, 4/5) follow a two-slot item
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::CloneItems::Apply(MS2Ptr<CItem> spItem, Unk_InventoryEquipSlot eSlot)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    Unk_InventoryEquipSlot eOrigSlot = eSlot;
    MS2Ptr<CItem> spOld(0);
    bool bHasOld = m_mapSlots.Lookup(eOrigSlot, spOld);
    bool bNewTwoSlot = false;
    if (spItem.get() && spItem->FUN_140527840()) {
        MS2Ptr<CItemData> spData(spItem->FUN_140527840());
        bNewTwoSlot = spData->FUN_14053d2b0() || spData->FUN_14053d460();
    }
    Unk_InventoryEquipSlot ePairSlot = Unk_InventoryEquipSlotNone;
    MS2Ptr<CItem> spPair(0);
    if (eSlot == 9 || eSlot == 8)
        ePairSlot = static_cast<Unk_InventoryEquipSlot>(eSlot == 9 ? 8 : 9);
    else if (eSlot == 4 || eSlot == 5)
        ePairSlot = static_cast<Unk_InventoryEquipSlot>(eSlot == 4 ? 5 : 4);
    ATL::CAtlArray<MS2Ptr<CItem> > aItems;
    if (bNewTwoSlot && ePairSlot != 0) {
        aItems.Add(MS2Ptr<CItem>(0));
        bHasOld = m_mapSlots.Lookup(ePairSlot, spOld);
    }
    if (bHasOld)
        aItems.Add(spOld);
    bool bOldTwoSlot = false;
    MS2Ptr<CItemData> spOldData(bHasOld ? static_cast<CItemData*>(spOld->FUN_140527840()) : 0);
    if (bHasOld && (spOldData->FUN_14053d2b0() || spOldData->FUN_14053d460()))
        bOldTwoSlot = true;
    if (!bOldTwoSlot && ePairSlot != 0 && eOrigSlot != ePairSlot && m_mapSlots.Lookup(ePairSlot, spPair)) {
        if (spOld.get() != spPair.get())
            aItems.Add(spPair);
    }
    size_t nCount = aItems.GetCount();
    for (size_t i = 0; i < nCount; ++i) {
        MS2Ptr<CItem> spCur = aItems[i];
        if (spCur == 0 || spCur->FUN_140527840() == 0)
            continue;
        bool bEquip = i == 0;
        MS2Ptr<CItemData> spData(spCur->FUN_140527840());
        Unk_InventoryEquipSlot eOther = Unk_InventoryEquipSlotNone;
        if (spData->FUN_14053d2b0())
            eOther = static_cast<Unk_InventoryEquipSlot>(eOrigSlot == 9 ? 8 : 9);
        else if (spData->FUN_14053d460())
            eOther = static_cast<Unk_InventoryEquipSlot>(eOrigSlot == 4 ? 5 : 4);
        else if (!bEquip)
            bEquip = bNewTwoSlot;
        if (eOther != 0) {
            MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655e10(eOther);
            bool bWorn = spEquip.get() && spEquip->GetItem().get();
            if (bWorn) {
                MS2Ptr<CItem> spOther(0);
                if (m_mapSlots.Lookup(eOther, spOther)) {
                    bEquip = spOther->FUN_140526a50() == spEquip->GetItem()->FUN_140526a50();
                } else {
                    CItemData* pData = static_cast<CItemData*>(spEquip->FUN_1411dc7f0());
                    if (pData)
                        bEquip = pData->FUN_14053d460() || pData->FUN_14053d2b0();
                }
            } else {
                bEquip = true;
            }
        } else {
            MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655c30(spCur->FUN_140526a50());
            if (spEquip.get() && spEquip->FUN_1411dc820() == spCur->FUN_1405276c0())
                bEquip = false;
        }
        if (bEquip)
            pPc->vfunc_127(FUN_140cd4650(spCur).get(), 1);
    }
}

// @0x140ccd210
int Customize::CloneItems::IsColorChanged()
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    int anColor[3];
    FUN_1414239e0(&anColor[0], 0, pPc);
    FUN_1414239e0(&anColor[1], 1, pPc);
    if (m_anColor[0] != anColor[0])
        return 1;
    if (m_anColor[1] != anColor[1])
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140CCD210, Customize::CloneItems, IsColorChanged, 221, 0x08C4B90A);

// @0x140ccd300
int Customize::CloneItems::IsAddedUid(__int64 nUid)
{
    ItemMap items;
    if (GetAdded(items)) {
        for (POSITION pos = items.GetStartPosition(); pos != 0;) {
            MS2Ptr<CItem> spItem = items.GetNextValue(pos);
            if (spItem == 0)
                continue;
            if (spItem->FUN_140526a50() == nUid)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCD300, Customize::CloneItems, IsAddedUid, 301, 0x13158B91);

// @0x140ccd440
int Customize::CloneItems::IsModifiedUid(__int64 nUid)
{
    ItemMap items;
    if (GetModified(items)) {
        for (POSITION pos = items.GetStartPosition(); pos != 0;) {
            MS2Ptr<CItem> spItem = items.GetNextValue(pos);
            if (spItem == 0)
                continue;
            if (spItem->FUN_140526a50() == nUid)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCD440, Customize::CloneItems, IsModifiedUid, 301, 0x0E90CAE9);

// @0x140ccd580
int Customize::CloneItems::IsRemovedUid(__int64 nUid)
{
    ItemMap items;
    if (GetRemoved(items)) {
        for (POSITION pos = items.GetStartPosition(); pos != 0;) {
            MS2Ptr<CItem> spItem = items.GetNextValue(pos);
            if (spItem == 0)
                continue;
            if (spItem->FUN_140526a50() == nUid)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCD580, Customize::CloneItems, IsRemovedUid, 301, 0x97A82653);

// @0x140ccd6c0 the worn item equals its clone (pnFlags: 1 colour, 2 appearance differ)
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
bool Customize::CloneItems::IsSameUid(__int64 nUid, unsigned* pnFlags)
{
    *pnFlags = 0;
    PC* pPc = GetPC();
    if (pPc == 0)
        return false;
    MS2Ptr<CItem> spCur = pPc->FUN_141655b80(nUid);
    if (spCur.get() && spCur->FUN_140527840()) {
        for (POSITION pos = m_mapItems.GetStartPosition(); pos != 0;) {
            MS2Ptr<CItem> spItem = m_mapItems.GetNextValue(pos);
            if (spItem == 0)
                continue;
            if (spCur->FUN_1405276c0() != spItem->FUN_1405276c0())
                continue;
            if (spCur->FUN_140526c30() != spItem->FUN_140526c30())
                continue;
            if (FUN_140cd4560(spItem, spCur) == 0)
                *pnFlags |= 1;
            if (FUN_140cd4460(spItem, spCur) == 0)
                *pnFlags |= 2;
            return *pnFlags == 0;
        }
    }
    if (IsColorChanged()) {
        *pnFlags = 1;
        return false;
    }
    return false;
}

// @0x140ccda10
int Customize::CloneItems::IsAddedSlot(Unk_InventoryEquipSlot eSlot)
{
    ItemMap items;
    if (GetAdded(items)) {
        for (POSITION pos = items.GetStartPosition(); pos != 0;) {
            MS2Ptr<CItem> spItem = items.GetNextValue(pos);
            if (spItem == 0)
                continue;
            if (spItem->FUN_140527a20() == eSlot)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCDA10, Customize::CloneItems, IsAddedSlot, 299, 0xB6918594);

// @0x140ccdb50
int Customize::CloneItems::IsModifiedSlot(Unk_InventoryEquipSlot eSlot)
{
    ItemMap items;
    if (GetModified(items)) {
        for (POSITION pos = items.GetStartPosition(); pos != 0;) {
            MS2Ptr<CItem> spItem = items.GetNextValue(pos);
            if (spItem == 0)
                continue;
            if (spItem->FUN_140527a20() == eSlot)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCDB50, Customize::CloneItems, IsModifiedSlot, 299, 0x36CF6E36);

// @0x140ccdc90 the worn items that are not in the clone
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
int Customize::CloneItems::GetAdded(ItemMap& out)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    ATL::CAtlList<MS2Ptr<CEquipItem> > lstEquips;
    FUN_140f014b0(lstEquips, pPc->FUN_1416561a0());
    for (POSITION pos = lstEquips.GetHeadPosition(); pos != 0; lstEquips.GetNext(pos)) {
        MS2Ptr<CEquipItem> spEquip = lstEquips.GetAt(pos);
        if (spEquip == 0)
            continue;
        MS2Ptr<CItem> spItem = spEquip->GetItem();
        if (spItem == 0)
            continue;
        MS2Ptr<CItem> spClone(0);
        if (!m_mapItems.Lookup(spItem->FUN_140526a50(), spClone))
            out.SetAt(spItem->FUN_140526a50(), FUN_140cd4650(spItem));
    }
    return out.GetCount() > 0;
}
MS2_REPLACE_METHOD(0x140CCDC90, Customize::CloneItems, GetAdded, 558, 0xBBBDECE1);

// @0x140ccded0 the worn items that differ from their clone
int Customize::CloneItems::GetModified(ItemMap& out)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    for (POSITION pos = m_mapItems.GetStartPosition(); pos != 0;) {
        MS2Ptr<CItem> spItem = m_mapItems.GetNextValue(pos);
        if (spItem == 0)
            continue;
        MS2Ptr<CItem> spCur = pPc->FUN_141655b80(spItem->FUN_140526a50());
        if (spCur == 0)
            continue;
        if (FUN_140cd4310(spItem, spCur))
            continue;
        out.SetAt(spCur->FUN_140526a50(), spCur);
    }
    return out.GetCount() > 0;
}
MS2_REPLACE_METHOD(0x140CCDED0, Customize::CloneItems, GetModified, 486, 0xE07C47F4);

// @0x140cce0c0 the clones whose item is gone
int Customize::CloneItems::GetRemoved(ItemMap& out)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    for (POSITION pos = m_mapItems.GetStartPosition(); pos != 0;) {
        MS2Ptr<CItem> spItem = m_mapItems.GetNextValue(pos);
        if (spItem == 0)
            continue;
        MS2Ptr<CItem> spCur = pPc->FUN_141655b80(spItem->FUN_140526a50());
        if (spCur == 0)
            out.SetAt(spItem->FUN_140526a50(), spItem);
    }
    return out.GetCount() > 0;
}
MS2_REPLACE_METHOD(0x140CCE0C0, Customize::CloneItems, GetRemoved, 315, 0x016A8354);

// @0x140cce210
int Customize::CloneItems::GetAddedUid(ItemMap& out, __int64 nUid)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    if (IsAddedUid(nUid)) {
        MS2Ptr<CItem> spItem = pPc->FUN_141655b80(nUid);
        if (spItem == 0)
            return 0;
        out.SetAt(spItem->FUN_140526a50(), spItem);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCE210, Customize::CloneItems, GetAddedUid, 208, 0xA576C2D2);

// @0x140cce2f0
int Customize::CloneItems::GetModifiedUid(ItemMap& out, __int64 nUid)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    if (IsModifiedUid(nUid)) {
        MS2Ptr<CItem> spItem = pPc->FUN_141655b80(nUid);
        if (spItem == 0)
            return 0;
        out.SetAt(spItem->FUN_140526a50(), spItem);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCE2F0, Customize::CloneItems, GetModifiedUid, 208, 0x17BECCB1);

// @0x140cce3d0
int Customize::CloneItems::GetRemovedUid(ItemMap& out, __int64 nUid)
{
    if (IsRemovedUid(nUid)) {
        MS2Ptr<CItem> spItem(0);
        if (m_mapItems.Lookup(nUid, spItem)) {
            out.SetAt(spItem->FUN_140526a50(), spItem);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCE3D0, Customize::CloneItems, GetRemovedUid, 171, 0xDDCC92AE);

// @0x140cce490
int Customize::CloneItems::GetAddedSlot(ItemMap& out, Unk_InventoryEquipSlot eSlot)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    if (IsAddedSlot(eSlot)) {
        MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655e10(eSlot);
        if (spEquip == 0 || spEquip->GetItem() == 0)
            return 0;
        MS2Ptr<CItem> spItem = spEquip->GetItem();
        out.SetAt(spItem->FUN_140526a50(), spItem);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCE490, Customize::CloneItems, GetAddedSlot, 405, 0x541ADC8A);

// @0x140cce630
int Customize::CloneItems::GetModifiedSlot(ItemMap& out, Unk_InventoryEquipSlot eSlot)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    if (IsModifiedSlot(eSlot)) {
        MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655e10(eSlot);
        if (spEquip == 0 || spEquip->GetItem() == 0)
            return 0;
        MS2Ptr<CItem> spItem = spEquip->GetItem();
        out.SetAt(spItem->FUN_140526a50(), spItem);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CCE630, Customize::CloneItems, GetModifiedSlot, 405, 0xD6806D54);

// @0x140cce7d0 a preview item of the id (a copy of the worn one when the player wears it)
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
MS2Ptr<CItem> Customize::CloneItems::CreateItem(int nItemId)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CItem> spItem(0);
    for (POSITION pos = m_mapItems.GetStartPosition(); pos != 0; m_mapItems.GetNext(pos)) {
        MS2Ptr<CItem> spClone = m_mapItems.GetValueAt(pos);
        if (spClone == 0)
            continue;
        if (spClone->FUN_1405276c0() == nItemId)
            return FUN_140cd4650(spClone);
    }
    if (spItem == 0) {
        spItem.AssignRaw(new CItem());
        if (spItem.get() && spItem->FUN_140523c40(nItemId, 1, 0))
            spItem->FUN_140526c10(FUN_141420f10(spData.get(), pPc));
    }
    if (spItem.get()) {
        spItem->FUN_140526a70(FUN_14028d0e0());
        spItem->FUN_140526b30(FUN_14123c580(pPc));
        if (m_pOwner)
            FUN_140cd46e0(spItem, m_pOwner->IsPreview());
    }
    return spItem;
}

// @0x140ccebc0
unsigned Customize::CloneItems::GetChangeFlags(__int64 nUid)
{
    unsigned nFlags = 0;
    PC* pPc = GetPC();
    if (pPc == 0)
        return nFlags;
    MS2Ptr<CItem> spCur = pPc->FUN_141655b80(nUid);
    if (spCur.get()) {
        MS2Ptr<CItem> spItem(0);
        if (m_mapItems.Lookup(nUid, spItem)) {
            if (FUN_140cd4560(spItem, spCur) == 0)
                nFlags |= 1;
            if (FUN_140cd4460(spItem, spCur) == 0)
                nFlags |= 2;
            return nFlags;
        }
    }
    if (IsColorChanged())
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140CCEBC0, Customize::CloneItems, GetChangeFlags, 530, 0xEEF67479);

// @0x140ccede0 the item's extra data changed: copy it into the clone
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::CloneItems::UpdateItem(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || spItem->FUN_140527870() == 0)
        return;
    MS2Ptr<CItem> spClone(0);
    if (m_mapItems.Lookup(spItem->FUN_140526a50(), spClone) && spClone.get() && spClone->FUN_140527870())
        static_cast<CItemExtraData*>(static_cast<CPtred*>(spClone->FUN_140527870()))->vfunc_3(
            static_cast<CItemExtraData*>(static_cast<CPtred*>(spItem->FUN_140527870())));
}

// @0x140ccef20
void Customize::CloneItems::SaveColors()
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    for (int i = 0; i < 3; ++i)
        FUN_1414239e0(&m_anColor[i], i, pPc);
}
MS2_REPLACE_METHOD(0x140CCEF20, Customize::CloneItems, SaveColors, 103, 0x637BC31D);

// @0x140ccef90
PC* Customize::CloneItems::GetPC()
{
    if (static_cast<unsigned>(m_nObjectId) > 0)
        return FUN_1403ed2d0()->FUN_141bd1290(m_nObjectId);
    return 0;
}
MS2_REPLACE_METHOD(0x140CCEF90, Customize::CloneItems, GetPC, 50, 0xF183C92F);

// @0x140ccefd0
void Customize::CloneItems::ClearSlots()
{
    if (!m_mapSlots.IsEmpty())
        m_mapSlots.RemoveAll();
}
MS2_REPLACE_METHOD(0x140CCEFD0, Customize::CloneItems, ClearSlots, 55, 0x1E07D9B6);

// @0x140ccf010 copies the worn items
int Customize::CloneItems::Init()
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return 0;
    m_mapItems.RemoveAll();
    m_mapSlots.RemoveAll();
    SaveColors();
    ATL::CAtlList<MS2Ptr<CEquipItem> > lstEquips;
    FUN_140f014b0(lstEquips, pPc->FUN_1416561a0());
    for (POSITION pos = lstEquips.GetHeadPosition(); pos != 0; lstEquips.GetNext(pos)) {
        MS2Ptr<CEquipItem> spEquip = lstEquips.GetAt(pos);
        if (spEquip == 0)
            continue;
        MS2Ptr<CItem> spItem = spEquip->GetItem();
        if (spItem == 0)
            continue;
        MS2Ptr<CItem> spClone = FUN_140cd4650(spItem);
        if (spClone == 0)
            continue;
        m_mapItems.SetAt(spItem->FUN_140526a50(), spClone);
        Unk_InventoryEquipSlot eSlot = static_cast<Unk_InventoryEquipSlot>(spClone->FUN_140526c30());
        if (m_mapSlots.Lookup(eSlot) == 0)
            m_mapSlots.SetAt(eSlot, spClone);
    }
    if (m_mapItems.IsEmpty())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140CCF010, Customize::CloneItems, Init, 692, 0x6087A53F);

// ---- Customize::Equipment ----

// @0x140ccf2d0
Customize::Equipment::Equipment(int nObjectId, Customize* pOwner) : m_nObjectId(nObjectId), m_pOwner(pOwner)
{
    m_pListener = m_pOwner ? m_pOwner->GetListener() : 0;
    m_spEdit.AssignRaw(new EditItems(nObjectId, pOwner));
    m_spClone.AssignRaw(new CloneItems(nObjectId, pOwner));
}

// @0x140ccf450
Customize::Equipment::~Equipment()
{
    m_nObjectId = 0;
    m_spEdit = 0;
    m_spClone = 0;
    m_pListener = 0;
    m_pOwner = 0;
}

// @0x140ccf500
MS2Ptr<Customize::EditItems> Customize::Equipment::GetEditItems()
{
    return m_spEdit;
}
MS2_REPLACE_METHOD(0x140CCF500, Customize::Equipment, GetEditItems, 65, 0xFDEC90EB);

// @0x140ccf550
MS2Ptr<Customize::CloneItems> Customize::Equipment::GetCloneItems()
{
    return m_spClone;
}
MS2_REPLACE_METHOD(0x140CCF550, Customize::Equipment, GetCloneItems, 65, 0x021657FB);

// @0x140ccf5a0 sends every change
void Customize::Equipment::CommitAll()
{
    if (m_spClone == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    int bColor = m_spClone->IsColorChanged();
    ItemMap added;
    ItemMap modified;
    ItemMap removed;
    m_spClone->Collect(added, modified, removed);
    int nObjectId = FUN_14123c580(pPc);
    m_spEdit.AssignRaw(new EditItems(nObjectId, m_pOwner));
    if (bColor)
        SendColors();
    SendAddedMap(added);
    SendModifiedMap(modified);
}

// @0x140ccf7e0 drops the preview
void Customize::Equipment::RestoreAll(ATL::CAtlList<Unk_InventoryEquipSlot>& slots)
{
    if (m_spClone.get())
        m_spClone->Restore(slots);
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    int nObjectId = FUN_14123c580(pPc);
    m_spEdit.AssignRaw(new EditItems(nObjectId, m_pOwner));
    m_spClone.AssignRaw(new CloneItems(nObjectId, m_pOwner));
}

// @0x140ccf940
void Customize::Equipment::CommitUid(__int64 nUid)
{
    if (m_spClone == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    int bColor = m_spClone->IsColorChanged();
    ItemMap added;
    ItemMap modified;
    ItemMap removed;
    m_spClone->CollectUid(nUid, added, modified, removed);
    int nObjectId = FUN_14123c580(pPc);
    m_spEdit.AssignRaw(new EditItems(nObjectId, m_pOwner));
    if (bColor)
        SendColors();
    SendRemovedMap(removed);
    SendAddedMap(added);
    SendModifiedMap(modified);
}

// @0x140ccfba0
void Customize::Equipment::RestoreUid(__int64 nUid)
{
    if (m_spClone == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    int nObjectId = FUN_14123c580(pPc);
    m_spEdit.AssignRaw(new EditItems(nObjectId, m_pOwner));
    m_spClone->RestoreUid(nUid);
}

// @0x140ccfc90
void Customize::Equipment::CommitSlot(Unk_InventoryEquipSlot eSlot)
{
    if (m_spClone == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    int bColor = m_spClone->IsColorChanged();
    ItemMap added;
    ItemMap modified;
    ItemMap removed;
    m_spClone->CollectSlot(eSlot, added, modified, removed);
    int nObjectId = FUN_14123c580(pPc);
    m_spEdit.AssignRaw(new EditItems(nObjectId, m_pOwner));
    if (bColor)
        SendColors();
    SendAddedMap(added);
    SendModifiedMap(modified);
}

// @0x140ccfee0
void Customize::Equipment::RestoreSlot(Unk_InventoryEquipSlot eSlot)
{
    if (m_spClone == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    int nObjectId = FUN_14123c580(pPc);
    m_spEdit.AssignRaw(new EditItems(nObjectId, m_pOwner));
    m_spClone->RestoreSlot(eSlot);
}

// @0x140ccffd0 the modified (dyed) worn item of the uid
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::Equipment::GetModified(__int64 nUid, MS2Ptr<CItem>& spOut)
{
    if (m_spClone == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    ItemMap added;
    ItemMap modified;
    ItemMap removed;
    m_spClone->CollectUid(nUid, added, modified, removed);
    int nObjectId = FUN_14123c580(pPc);
    m_spEdit.AssignRaw(new EditItems(nObjectId, m_pOwner));
    if (modified.IsEmpty())
        return;
    spOut = 0;
    modified.Lookup(nUid, spOut);
}

// @0x140cd0270
void Customize::Equipment::Apply(MS2Ptr<CItem> spItem, Unk_InventoryEquipSlot eSlot)
{
    if (m_spClone == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    int nObjectId = FUN_14123c580(pPc);
    m_spEdit.AssignRaw(new EditItems(nObjectId, m_pOwner));
    m_spClone->Apply(spItem, eSlot);
}

// @0x140cd03d0
void Customize::Equipment::Equip(CItem* pItem)
{
    if (pItem == 0)
        return;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    if (m_pOwner)
        FUN_140cd46e0(MS2Ptr<CItem>(pItem), m_pOwner->IsPreview());
    pPc->vfunc_127(pItem, 1);
}
MS2_REPLACE_METHOD(0x140CD03D0, Customize::Equipment, Equip, 277, 0xAE0BCC66);

// @0x140cd04f0
void Customize::Equipment::EquipId(int nItemId)
{
    if (m_spClone == 0)
        return;
    MS2Ptr<CItem> spItem = m_spClone->CreateItem(nItemId);
    if (spItem == 0)
        return;
    Equip(spItem.get());
}

// @0x140cd05a0
void Customize::Equipment::ClearPreview()
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    FUN_140cd3e50(pPc);
    m_spClone->ClearSlots();
}
MS2_REPLACE_METHOD(0x140CD05A0, Customize::Equipment, ClearPreview, 74, 0x7B355A4F);

// @0x140cd05f0
void Customize::Equipment::Unequip(CItem* pItem)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    pPc->vfunc_128(pItem, 1);
}
MS2_REPLACE_METHOD(0x140CD05F0, Customize::Equipment, Unequip, 74, 0x15D5B3E2);

// @0x140cd0640
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::Equipment::UnequipId(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = FUN_1414211a0(FUN_141420f10(spData.get(), pPc), pPc);
    if (spEquip == 0)
        return;
    MS2Ptr<CItem> spItem = spEquip->GetItem();
    if (spItem == 0)
        return;
    pPc->vfunc_128(spItem.get(), 1);
}
MS2_REPLACE_METHOD(0x140CD0640, Customize::Equipment, UnequipId, 368, 0xFEE51F6F);

// @0x140cd07c0
void Customize::Equipment::UnequipUid(__int64 nUid)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655c30(nUid);
    if (spEquip == 0)
        return;
    MS2Ptr<CItem> spItem = spEquip->GetItem();
    if (spItem == 0)
        return;
    pPc->vfunc_128(spItem.get(), 1);
}
MS2_REPLACE_METHOD(0x140CD07C0, Customize::Equipment, UnequipUid, 247, 0xD6C92C26);

// @0x140cd08c0
void Customize::Equipment::ShowSlot(Unk_InventoryEquipSlot eSlot)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655e10(eSlot);
    if (spEquip == 0)
        return;
    spEquip->FUN_1411dcf10(s_strCustomize);
    pPc->FUN_1416561a0()->FUN_1411e75f0();
    pPc->FUN_1416561a0()->FUN_1411e5c10();
}

// @0x140cd0980
void Customize::Equipment::HideSlot(Unk_InventoryEquipSlot eSlot)
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = pPc->FUN_141655e10(eSlot);
    if (spEquip == 0)
        return;
    spEquip->FUN_1411dce60(s_strCustomize);
    pPc->FUN_1416561a0()->FUN_1411e75f0();
    if (eSlot == 6)
        pPc->FUN_1416561a0()->FUN_1411e6ab0();
}

// @0x140cd0a40
void Customize::Equipment::ResetEdit()
{
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    int nObjectId = FUN_14123c580(pPc);
    m_spEdit.AssignRaw(new EditItems(nObjectId, m_pOwner));
}

// @0x140cd0af0
PC* Customize::Equipment::GetPC()
{
    if (static_cast<unsigned>(m_nObjectId) > 0)
        return FUN_1403ed2d0()->FUN_141bd1290(m_nObjectId);
    return 0;
}
MS2_REPLACE_METHOD(0x140CD0AF0, Customize::Equipment, GetPC, 50, 0x900515B6);

// @0x140cd0b30
void Customize::Equipment::SendColors()
{
    if (m_pListener == 0)
        return;
    if (m_pListener->IsSendEnabled() == 0)
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    int anColor[3];
    FUN_1414239e0(&anColor[0], 0, pPc);
    FUN_1414239e0(&anColor[1], 1, pPc);
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.vfunc_o10_1(6);
    packet.vfunc_o10_1(m_pListener->GetShopId());
    packet.vfunc_o10_3(anColor[0]);
    packet.vfunc_o10_3(anColor[1]);
    packet.vfunc_o10_1(m_pListener->UseFreeTry());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140CD0B30, Customize::Equipment, SendColors, 353, 0x736A2DBB);

// @0x140cd0ca0
void Customize::Equipment::SendAdded(MS2Ptr<CItem> spItem)
{
    if (m_pListener == 0)
        return;
    if (m_pListener->IsSendEnabled() == 0)
        return;
    if (spItem == 0)
        return;
    __int64 nContext = 0;
    if (m_pOwner) {
        MS2Ptr<BeautyShopContext> spContext = m_pOwner->FUN_140cd3940();
        if (spContext.get())
            nContext = spContext->m_20;
    }
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.vfunc_o10_1(3);
    packet.vfunc_o10_1(m_pListener->GetShopId());
    packet.vfunc_o10_1(m_pListener->UseFreeTry());
    packet.vfunc_o10_3(spItem->FUN_1405276c0());
    packet.vfunc_o10_4(nContext);
    spItem->FUN_140525590(reinterpret_cast<__int64>(&packet));     // writes the item's extra data (citem.h types it __int64)
    FUN_140710590(packet);
    ResetCapPosition(spItem);
}
MS2_REPLACE_METHOD(0x140CD0CA0, Customize::Equipment, SendAdded, 494, 0x40A82DD1);

// @0x140cd0ea0
void Customize::Equipment::SendModified(MS2Ptr<CItem> spItem)
{
    if (m_pListener == 0)
        return;
    if (m_pListener->IsSendEnabled() == 0)
        return;
    if (spItem == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.vfunc_o10_1(5);
    packet.vfunc_o10_1(m_pListener->GetShopId());
    packet.vfunc_o10_1(m_pListener->UseFreeTry());
    packet.vfunc_o10_4(spItem->FUN_140526a50());
    spItem->FUN_140525590(reinterpret_cast<__int64>(&packet));
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140CD0EA0, Customize::Equipment, SendModified, 293, 0x39533252);

// @0x140cd0fd0
void Customize::Equipment::SendRemoved(MS2Ptr<CItem> spItem)
{
    if (m_pListener == 0)
        return;
    if (m_pListener->IsSendEnabled() == 0)
        return;
    if (spItem == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.vfunc_o10_1(4);
    packet.vfunc_o10_4(spItem->FUN_140526a50());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140CD0FD0, Customize::Equipment, SendRemoved, 210, 0x4531DD36);

// @0x140cd10b0
void Customize::Equipment::SendAddedMap(ItemMap& items)
{
    for (POSITION pos = items.GetStartPosition(); pos != 0;) {
        MS2Ptr<CItem> spItem = items.GetNextValue(pos);
        if (spItem == 0)
            continue;
        SendAdded(spItem);
    }
}
MS2_REPLACE_METHOD(0x140CD10B0, Customize::Equipment, SendAddedMap, 169, 0x5DCA0763);

// @0x140cd1160
void Customize::Equipment::SendModifiedMap(ItemMap& items)
{
    for (POSITION pos = items.GetStartPosition(); pos != 0;) {
        MS2Ptr<CItem> spItem = items.GetNextValue(pos);
        if (spItem == 0)
            continue;
        SendModified(spItem);
    }
}
MS2_REPLACE_METHOD(0x140CD1160, Customize::Equipment, SendModifiedMap, 169, 0x4B3D3162);

// @0x140cd1210
void Customize::Equipment::SendRemovedMap(ItemMap& items)
{
    for (POSITION pos = items.GetStartPosition(); pos != 0;) {
        MS2Ptr<CItem> spItem = items.GetNextValue(pos);
        if (spItem == 0)
            continue;
        SendRemoved(spItem);
    }
}
MS2_REPLACE_METHOD(0x140CD1210, Customize::Equipment, SendRemovedMap, 169, 0xC6795B7E);

// @0x140cd12c0 a hair bought with the cap on: the cap's attach points go back to the default
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::Equipment::ResetCapPosition(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || spItem->FUN_140527840() == 0)
        return;
    if (!spItem->FUN_140527840()->FUN_14053cfd0())
        return;
    PC* pPc = GetPC();
    if (pPc == 0)
        return;
    MS2Ptr<CEquipItem> spCap = pPc->FUN_1416561a0()->FUN_1411e1860(6, 6, 0);
    if (spCap == 0)
        return;
    CItemData* pData = static_cast<CItemData*>(spCap->FUN_1411dc7f0());
    if (pData == 0)
        return;
    if (!static_cast<Unk_CustomizeItemData*>(pData)->FUN_14053ec70()->FUN_1405471b0())
        return;
    CCapExtraData* pExtra = static_cast<CCapExtraData*>(static_cast<CPtred*>(spCap->GetItem()->FUN_140527870()));
    if (pExtra == 0)
        return;
    pExtra->m_aPt[3] = DAT_143b01a60;
    pExtra->m_aPt[2] = DAT_143b01a60;
    SendModified(spCap->GetItem());
}

// ---- Customize ----

// @0x140cd1570
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
Customize::Customize(int nObjectId, IItemCustomizeEventListener* pListener, int bPreview)
    : m_pListener(pListener), m_bPreview(bPreview != 0), m_nPalette(0)
{
    m_nObjectId = nObjectId;
    m_spEquipment.AssignRaw(new Equipment(nObjectId, this));
    FUN_1419cae20(FUN_140a6a840(), this);
}

// @0x140cd16e0
Customize::~Customize()
{
    m_nObjectId = 0;
    m_spEquipment = 0;
    m_pListener = 0;
    FUN_1419caeb0(FUN_140a6a840(), this);
}

// @0x140cd17e0
int Customize::FUN_140cd17e0()
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    return spEdit->GetItemId();
}
MS2_REPLACE_METHOD(0x140CD17E0, Customize, FUN_140cd17e0, 163, 0x20A6083D);

// @0x140cd1890
MS2Ptr<CItem> Customize::FUN_140cd1890()
{
    if (m_spEquipment == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return MS2Ptr<CItem>(0);
    return spEdit->GetItem();
}
MS2_REPLACE_METHOD(0x140CD1890, Customize, FUN_140cd1890, 234, 0x518BBC9E);

// @0x140cd1980
__int64 Customize::FUN_140cd1980()
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    return spEdit->GetItemUid();
}
MS2_REPLACE_METHOD(0x140CD1980, Customize, FUN_140cd1980, 167, 0x316B7350);

// @0x140cd1a30
// MS2-FUNCTIONAL: returns the callers' Unk_BSPartHandle view of NiPointer<CItemCustomizeController> (its copy ctor)
Unk_BSPartHandle Customize::FUN_140cd1a30()
{
    if (m_spEquipment == 0)
        return Unk_BSPartHandle(NiPointer<CItemCustomizeController>(0));
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return Unk_BSPartHandle(NiPointer<CItemCustomizeController>(0));
    return Unk_BSPartHandle(spEdit->GetController());
}

// @0x140cd1b20
unsigned Customize::FUN_140cd1b20()
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    return spEdit->GetFlags();
}
MS2_REPLACE_METHOD(0x140CD1B20, Customize, FUN_140cd1b20, 163, 0xD44E6561);

// @0x140cd1bd0
IItemCustomizeEventListener* Customize::GetListener()
{
    return m_pListener;
}
MS2_REPLACE_METHOD(0x140CD1BD0, Customize, GetListener, 15, 0x7BFFD3E9);

// @0x140cd1bf0
void Customize::FUN_140cd1bf0()
{
    if (m_spEquipment == 0)
        return;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return;
    spEdit->Update();
}
MS2_REPLACE_METHOD(0x140CD1BF0, Customize, FUN_140cd1bf0, 142, 0x8CAD08D5);

// @0x140cd1c90
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
bool Customize::FUN_140cd1c90(CItem* pItem)
{
    if (m_spEquipment == 0 || pItem == 0 || pItem->FUN_140527840() == 0)
        return false;
    PC* pPc = FUN_140cd3df0();
    if (pPc) {
        if (!pItem->FUN_140527840()->FUN_14053c940(pPc->FUN_141658e60()))
            return false;
    }
    m_spEquipment->Equip(pItem);
    return true;
}
MS2_REPLACE_METHOD(0x140CD1C90, Customize, FUN_140cd1c90, 173, 0x8E5B3BC6);

// @0x140cd1d50
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
bool Customize::FUN_140cd1d50(int nItemId)
{
    if (m_spEquipment == 0)
        return false;
    PC* pPc = FUN_140cd3df0();
    if (pPc) {
        MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
        if (spData == 0)
            return false;
        if (spData->FUN_14053cf00())
            return false;
        if (!spData->FUN_14053c940(pPc->FUN_141658e60()))
            return false;
    }
    m_spEquipment->EquipId(nItemId);
    return true;
}

// @0x140cd1e80
void Customize::FUN_140cd1e80()
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->ClearPreview();
}
MS2_REPLACE_METHOD(0x140CD1E80, Customize, FUN_140cd1e80, 67, 0x10719BB5);

// @0x140cd1ed0
void Customize::FUN_140cd1ed0(CItem* pItem)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->Unequip(pItem);
}
MS2_REPLACE_METHOD(0x140CD1ED0, Customize, FUN_140cd1ed0, 77, 0x39D579D5);

// @0x140cd1f30
void Customize::FUN_140cd1f30(int nItemId)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->UnequipId(nItemId);
}
MS2_REPLACE_METHOD(0x140CD1F30, Customize, FUN_140cd1f30, 75, 0xA8080D76);

// @0x140cd1f90
void Customize::FUN_140cd1f90(__int64 nUid)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->UnequipUid(nUid);
}
MS2_REPLACE_METHOD(0x140CD1F90, Customize, FUN_140cd1f90, 77, 0x52D9372F);

// @0x140cd1ff0
void Customize::FUN_140cd1ff0()
{
    if (m_spEquipment == 0)
        return;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return;
    int nItemId = spEdit->GetItemId();
    m_spEquipment->CommitAll();
    FUN_140cd3a70();
    FUN_140cd2660(nItemId);
}

// @0x140cd20c0
void Customize::FUN_140cd20c0()
{
    if (m_spEquipment == 0)
        return;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return;
    int nItemId = spEdit->GetItemId();
    m_spEquipment->RestoreAll(m_lstHiddenSlots);
    FUN_140cd3a70();
    FUN_140cd2660(nItemId);
}

// @0x140cd21a0
void Customize::FUN_140cd21a0(__int64 nUid)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->CommitUid(nUid);
    FUN_140cd3a70();
    FUN_140cd2700(nUid);
}

// @0x140cd2210
void Customize::FUN_140cd2210(__int64 nUid)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->RestoreUid(nUid);
    FUN_140cd3a70();
    FUN_140cd2700(nUid);
}

// @0x140cd2280
void Customize::FUN_140cd2280(int nSlot)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->CommitSlot(static_cast<Unk_InventoryEquipSlot>(nSlot));
    FUN_140cd3a70();
    FUN_140cd25c0(nSlot);
}

// @0x140cd22f0
void Customize::FUN_140cd22f0(int nSlot)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->RestoreSlot(static_cast<Unk_InventoryEquipSlot>(nSlot));
    FUN_140cd3a70();
    FUN_140cd25c0(nSlot);
}

// @0x140cd2360
void Customize::FUN_140cd2360(__int64 nUid, MS2Ptr<CItem>& spOut)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->GetModified(nUid, spOut);
    FUN_140cd3a70();
    FUN_140cd2700(nUid);
}

// @0x140cd23e0
void Customize::FUN_140cd23e0(MS2Ptr<CItem> spItem, int nSlot)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->Apply(spItem, static_cast<Unk_InventoryEquipSlot>(nSlot));
    FUN_140cd3a70();
    FUN_140cd25c0(nSlot);
}

// @0x140cd24a0
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::FUN_140cd24a0(int nSlot)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->ShowSlot(static_cast<Unk_InventoryEquipSlot>(nSlot));
    POSITION pos = m_lstHiddenSlots.Find(static_cast<Unk_InventoryEquipSlot>(nSlot));
    if (pos)
        m_lstHiddenSlots.RemoveAt(pos);
}

// @0x140cd2530
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::FUN_140cd2530(int nSlot)
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->HideSlot(static_cast<Unk_InventoryEquipSlot>(nSlot));
    POSITION pos = m_lstHiddenSlots.Find(static_cast<Unk_InventoryEquipSlot>(nSlot));
    if (pos == 0)
        m_lstHiddenSlots.AddTail(static_cast<Unk_InventoryEquipSlot>(nSlot));
}

// @0x140cd25c0
void Customize::FUN_140cd25c0(int nSlot)
{
    if (m_spEquipment == 0)
        return;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return;
    spEdit->SelectSlot(static_cast<Unk_InventoryEquipSlot>(nSlot));
}
MS2_REPLACE_METHOD(0x140CD25C0, Customize, FUN_140cd25c0, 150, 0x4BA30437);

// @0x140cd2660
void Customize::FUN_140cd2660(int nItemId)
{
    if (m_spEquipment == 0)
        return;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return;
    spEdit->SelectId(nItemId);
}
MS2_REPLACE_METHOD(0x140CD2660, Customize, FUN_140cd2660, 150, 0x2A135BD2);

// @0x140cd2700
void Customize::FUN_140cd2700(__int64 nUid)
{
    if (m_spEquipment == 0)
        return;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return;
    spEdit->SelectUid(nUid);
}
MS2_REPLACE_METHOD(0x140CD2700, Customize, FUN_140cd2700, 152, 0x81E9CD15);

// @0x140cd27a0
void Customize::FUN_140cd27a0()
{
    if (m_spEquipment == 0)
        return;
    m_spEquipment->ResetEdit();
}

// @0x140cd27f0
int Customize::FUN_140cd27f0()
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    return spEdit->GetDragging();
}
MS2_REPLACE_METHOD(0x140CD27F0, Customize, FUN_140cd27f0, 163, 0xBC58C82F);

// @0x140cd28a0
int Customize::FUN_140cd28a0()
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return 0;
    __int64 nUid = spEdit->GetItemUid();
    if (spClone->IsAddedUid(nUid))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140CD28A0, Customize, FUN_140cd28a0, 336, 0xE5853838);

// @0x140cd2a00
int Customize::FUN_140cd2a00()
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return 0;
    __int64 nUid = spEdit->GetItemUid();
    if (spClone->IsColorChanged())
        return 1;
    if (spClone->IsModifiedUid(nUid))
        return 1;
    if (spClone->IsAddedUid(nUid))
        return 1;
    if (spClone->IsRemovedUid(nUid))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140CD2A00, Customize, FUN_140cd2a00, 535, 0x6C7A1AD1);

// @0x140cd2c20
int Customize::FUN_140cd2c20()
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return 0;
    __int64 nUid = spEdit->GetItemUid();
    if (spClone->IsColorChanged())
        return 1;
    if (spClone->IsModifiedUid(nUid))
        return 1;
    if (spClone->IsAddedUid(nUid)) {
        unsigned nFlags = 0;
        if (spClone->IsSameUid(nUid, &nFlags) == true)
            return 0;
        return 1;
    }
    if (spClone->IsRemovedUid(nUid))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140CD2C20, Customize, FUN_140cd2c20, 623, 0x02724285);

// @0x140cd2ea0
int Customize::FUN_140cd2ea0()
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return 0;
    __int64 nUid = spEdit->GetItemUid();
    if (spClone->GetChangeFlags(nUid) & 1)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140CD2EA0, Customize, FUN_140cd2ea0, 339, 0x97CC4F2C);

// @0x140cd3000
int Customize::FUN_140cd3000()
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return 0;
    __int64 nUid = spEdit->GetItemUid();
    if (spClone->GetChangeFlags(nUid) & 2)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140CD3000, Customize, FUN_140cd3000, 339, 0x5B75FB50);

// @0x140cd3160
int Customize::FUN_140cd3160(int nIndex, int n)
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    return spEdit->ApplyColor(nIndex, n);
}
MS2_REPLACE_METHOD(0x140CD3160, Customize, FUN_140cd3160, 181, 0xF6DBB63E);

// @0x140cd3220
int Customize::FUN_140cd3220(int nPalette, int nColor, int n)
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    return spEdit->ApplyPalette(nPalette, nColor, n);
}
MS2_REPLACE_METHOD(0x140CD3220, Customize, FUN_140cd3220, 191, 0x1DDB03AE);

// @0x140cd32f0
int Customize::FUN_140cd32f0(const int& nPalette, int nColor, int n)
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    return spEdit->SetColors(nPalette, nColor, n);
}
MS2_REPLACE_METHOD(0x140CD32F0, Customize, FUN_140cd32f0, 193, 0xF366EAE5);

// @0x140cd33c0
int Customize::FUN_140cd33c0(int* pnColor, int nSlot)
{
    if (m_spEquipment == 0)
        return 0;
    MS2Ptr<EditItems> spEdit = m_spEquipment->GetEditItems();
    if (spEdit == 0)
        return 0;
    return spEdit->GetColors(pnColor, nSlot);
}
MS2_REPLACE_METHOD(0x140CD33C0, Customize, FUN_140cd33c0, 183, 0x3E0EE1BE);

// @0x140cd3480
// MS2-FUNCTIONAL: written from the decompile; temp slots / branch layout differ (permuter lane)
void Customize::FUN_140cd3480(int bApply, int nPalette)
{
    PC* pPc = FUN_140cd3df0();
    if (pPc == 0)
        return;
    if (bApply == 0) {
        ItemMap items;
        m_spEquipment->GetCloneItems()->GetAdded(items);
        if (!items.IsEmpty()) {
            for (POSITION pos = items.GetStartPosition(); pos != 0; items.GetNext(pos))
                FUN_141424230(items.GetKeyAt(pos), pPc);
        }
    } else if (nPalette != 0) {
        MS2Ptr<ItemColorEx> spColor = FUN_140281980()->FUN_1405587f0(nPalette, 0);
        if (spColor.get()) {
            ItemMap items;
            m_spEquipment->GetCloneItems()->GetAdded(items);
            if (!items.IsEmpty()) {
                for (POSITION pos = items.GetStartPosition(); pos != 0; items.GetNext(pos))
                    FUN_141423cf0(items.GetKeyAt(pos), *spColor, pPc, 0);
            }
        }
    }
}

// @0x140cd3750
void Customize::FUN_140cd3750(ItemMap& out)
{
    out.RemoveAll();
    if (m_spEquipment == 0)
        return;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return;
    spClone->GetAdded(out);
}
MS2_REPLACE_METHOD(0x140CD3750, Customize, FUN_140cd3750, 162, 0x0EACAFFA);

// @0x140cd3800
bool Customize::IsPreview()
{
    return m_bPreview;
}
MS2_REPLACE_METHOD(0x140CD3800, Customize, IsPreview, 15, 0x232B835D);

// @0x140cd3820
void Customize::FUN_140cd3820()
{
    if (m_spEquipment == 0)
        return;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return;
    FUN_140cd3990();
}

// @0x140cd38b0
unsigned Customize::GetPalette()
{
    return m_nPalette;
}
MS2_REPLACE_METHOD(0x140CD38B0, Customize, GetPalette, 14, 0x99EEE733);

// @0x140cd38d0
void Customize::SetPalette(int nPalette)
{
    m_nPalette = nPalette;
}
MS2_REPLACE_METHOD(0x140CD38D0, Customize, SetPalette, 22, 0xFE13C11F);

// @0x140cd38f0
void Customize::FUN_140cd38f0(MS2Ptr<BeautyShopContext> spContext)
{
    m_spContext = spContext;
}
MS2_REPLACE_METHOD(0x140CD38F0, Customize, FUN_140cd38f0, 61, 0x72888723);

// @0x140cd3940
MS2Ptr<Customize::BeautyShopContext> Customize::FUN_140cd3940()
{
    return m_spContext;
}
MS2_REPLACE_METHOD(0x140CD3940, Customize, FUN_140cd3940, 65, 0xC5BCF492);

// @0x140cd3990
void Customize::FUN_140cd3990()
{
    if (m_spEquipment == 0)
        return;
    PC* pPc = FUN_140cd3df0();
    if (pPc == 0)
        return;
    int nItemId = FUN_140cd17e0();
    int nObjectId = FUN_14123c580(pPc);
    m_spEquipment.AssignRaw(new Equipment(nObjectId, this));
    FUN_140cd2660(nItemId);
}

// @0x140cd3a70
void Customize::FUN_140cd3a70()
{
    for (POSITION pos = m_lstHiddenSlots.GetHeadPosition(); pos != 0;) {
        Unk_InventoryEquipSlot eSlot = m_lstHiddenSlots.GetNext(pos);
        m_spEquipment->HideSlot(eSlot);
    }
}

// @0x140cd3ae0
void Customize::vfunc_21(void* p)
{
    if (p == 0)
        return;
    if (m_pListener == 0)
        return;
    if (m_spEquipment == 0)
        return;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return;
    FUN_140cd3990();
}

// @0x140cd3ba0
void Customize::vfunc_22(void* p)
{
    if (p == 0)
        return;
    if (m_pListener == 0)
        return;
    if (m_spEquipment == 0)
        return;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return;
    FUN_140cd3990();
}

// @0x140cd3c60
void Customize::vfunc_24(void* p)
{
    if (m_pListener == 0)
        return;
    if (m_spEquipment == 0)
        return;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return;
    spClone->UpdateItem(MS2Ptr<CItem>(static_cast<CItem*>(p)));
}
MS2_REPLACE_METHOD(0x140CD3C60, Customize, vfunc_24, 213, 0x3D2EAFD0);

// @0x140cd3d40
void Customize::vfunc_25(void* p)
{
    if (m_pListener == 0)
        return;
    if (m_spEquipment == 0)
        return;
    MS2Ptr<CloneItems> spClone = m_spEquipment->GetCloneItems();
    if (spClone == 0)
        return;
    spClone->SaveColors();
}
MS2_REPLACE_METHOD(0x140CD3D40, Customize, vfunc_25, 161, 0x36B7DD73);

// @0x140cd3df0
PC* Customize::FUN_140cd3df0()
{
    if (static_cast<unsigned>(m_nObjectId) > 0)
        return FUN_1403ed2d0()->FUN_141bd1290(m_nObjectId);
    return 0;
}
MS2_REPLACE_METHOD(0x140CD3DF0, Customize, FUN_140cd3df0, 50, 0x4666D5B3);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca3ef0-0x142ca3f10 .text$yd
// MS2-RANGE: 0x142ca4090-0x142ca4180 .text$yd
