// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PetSlot and PetSlotBag: the slots of the pet inventory window.
// See petslot.h. Member and local names are invented from the use.
// MS2-UNIT: ?\petslot.cpp
// MS2-RANGE: 0x140dbad20-0x140dbcbc0 .text$mn
// MS2-RANGE: 0x1400d4fa0-0x1400d5270 .text$di
// MS2-PIN: ??_7PetSlot@@6BBindData@NotifyContext@@@ 0x142e373a0 ; hand: primary vftable
// MS2-PIN: ??_7PetSlot@@6B@ 0x142e37488 ; hand: UIQuestEventListener vftable
// MS2-PIN: ?TypeCast@PetSlot@@UEBA_NIPEAPEAX@Z 0x140dbc2d0 ; hand
// MS2-PIN: ?TypeCast@PetSlot@@UEBA_NIPEAPEBX@Z 0x140dbc320 ; hand
// MS2-PIN: ?TypeCast@PetSlotBag@@UEBA_NIPEAPEAX@Z 0x140dbcb20 ; hand
// MS2-PIN: ?TypeCast@PetSlotBag@@UEBA_NIPEAPEBX@Z 0x140dbcb70 ; hand
// MS2-PIN: ?GetClassDesc@PetSlot@@UEBAPEBVClassInfo@efd@@XZ 0x140dbc190 ; hand
// MS2-PIN: ?GetClassDesc@PetSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x140dbcab0 ; hand
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\petslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "petslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_ItemEquipData : public CItemData { };          // CItem::FUN_140527840's record

extern Unk_Inventory DAT_143ab2a90;                       // the player's inventory
CPetManager* FUN_140535320();                             // CPetManager::GetInstance

// The local player and its views.
class Unk_PsSkills
{
public:
    float FUN_141765fe0(int nSkillId, int n);             // the cooldown left of nSkillId
};
class Unk_PsPlayer
{
public:
    Unk_PsSkills* FUN_141523bc0();                        // the skill system
    MS2Ptr<CItem> FUN_14152e2f0(MS2Ptr<CItem> spItem);    // the worn item spItem would replace
};
class Unk_PsWorld
{
public:
    Unk_PsPlayer* FUN_141bd0cc0();                        // the local player
};
Unk_PsWorld* FUN_1403ed2d0();

// The equip view of the player's slot (an opaque 16-byte handle).
struct Unk_PsHandle { void* m_a; void* m_b; };
MS2_CHECK_SIZE(Unk_PsHandle, 0x10);
void FUN_141655e10(Unk_PsPlayer* pPlayer, Unk_PsHandle* pOut, int nSlot);   // the equip handle of a slot
void* FUN_1405a8e70(Unk_PsHandle* pHandle);               // handle.get
void* FUN_1405a8ed0(Unk_PsHandle* pHandle);               // handle.get (the equip item)
MS2Ptr<CItem>* FUN_1411dc7a0(void* pEquip, MS2Ptr<CItem>* pOut);   // the item of an equip, returns pOut
void FUN_1405a85f0(Unk_PsHandle* pHandle);                // release
class Unk_PsUi { public: int FUN_141adcb40(); };          // 0: the compare view is off
Unk_PsUi* FUN_1403ed2b0();

char FUN_140534e50(MS2Ptr<CItem>* pItem);                 // the item is expired / unusable

// A dialog of the dialog registry.
class Unk_PsPetDialog : public UIDialog
{
public:
    void FUN_140e74640(int nPage);                        // select a page
};
Unk_PsPetDialog* FUN_140b99ba0(int nId);
class Unk_PsPane
{
public:
    int FUN_141924630();                                  // is floating
    void FUN_140f4fc40(int nItemId);
};
Unk_PsPane* FUN_140cbe1c0(int nId);

// The quest event dispatcher the slot registers with.
class Unk_PsQuestEvents
{
public:
    void FUN_141aa87c0(UIQuestEventListener*);
    void FUN_141aa8850(UIQuestEventListener*);
};
Unk_PsQuestEvents* FUN_140bfc4b0();
// The item event hub the bag registers with.
struct Unk_PsItemEvents;
Unk_PsItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_PsItemEvents*, UIItemEventListener*);
void FUN_1419caeb0(Unk_PsItemEvents*, UIItemEventListener*);

// The singleton that decides whether an item may be handled.
class Unk_PsItemRules
{
public:
    int FUN_1416ce170(MS2Ptr<CItem> spItem);
};
Unk_PsItemRules* FUN_140764020();

void FUN_140d73bc0(int nTable, int nId, void* pListener, CStringW strExtra);
void FUN_141276180(const CString& strA, const CString& strB);
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);                 // item link / popup for the item
void* FUN_140a50b50(DragSlot* pSlot);                     // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                   // its item uid
void FUN_141404930(__int64 nUid);
void FUN_140165270(void* pArr, const CString& str);       // append a string to the slot's data array
void FUN_141404ce0(int nType, void* pArr, Scaleform::GFx::Value* pValue);
void FUN_1414050c0(int nType, void* pArr, Scaleform::GFx::Value* pValue);
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);
unsigned FUN_140720ca0(void* pArr);                       // GetCount
MS2Ptr<CItem>* FUN_140c3c720(void* pArr, unsigned nIndex);   // element access

// The pet inventory entry points that are free functions in the exe (the item handle is passed by pointer in rcx).
void FUN_140c887b0(MS2Ptr<CItem> spItem, int nSlot);      // take an item out of the pet inventory
void FUN_140c88c30(MS2Ptr<CItem> spItem, int nSlot);      // put an item into the pet inventory

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

PetSlot* FUN_140dbc0d0(DragSlot* p);
PetSlotBag* FUN_140dbc9f0(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(PetSlot);

static CString s_strOnCooldownEnd = "onCooldownEnd";

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

static CString s_strChangeDagger = "Change_Dagger";

EE_IMPLEMENT_CONCRETE_CLASS_INFO(PetSlotBag);

// The second copy of the header statics (a second header of the unit defines the same ones).
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x140dbad20
PetSlot::PetSlot(const CString& strName, int nIndex, unsigned __int64 nPetItemUid)
    : MS2DragSlot(strName, nIndex), m_nPetItemUid(nPetItemUid)
{
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    FUN_140a7bd80(true);
}

// @0x140dbae00
PetSlot::~PetSlot()
{
    FUN_140bfc4b0()->FUN_141aa8850(this);
}

// @0x140dbaeb0
float PetSlot::FUN_140dbaeb0()
{
    Unk_PsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    int nType = FUN_140dbaf10();
    return pPlayer->FUN_141523bc0()->FUN_141765fe0(nType, 0);
}

// @0x140dbaf10
int PetSlot::FUN_140dbaf10()
{
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(FUN_140dbb060());
    int nType;
    if (spItem.get() == 0)
        nType = 0;
    else
        nType = spItem->FUN_140527840()->FUN_14053dc20();
    return nType;
}

// @0x140dbafc0
int PetSlot::FUN_140dbafc0()
{
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(FUN_140dbb060());
    if (spItem)
        return spItem->FUN_1405276c0();
    return 0;
}

// @0x140dbb060
unsigned __int64 PetSlot::FUN_140dbb060()
{
    return m_nPetItemUid;
}

// @0x140dbb080
void PetSlot::FUN_140dbb080(unsigned __int64 nUid)
{
    m_nPetItemUid = nUid;
}

// @0x140dbb0b0
void PetSlot::vfunc_6(void* p)
{
    CString str;
    str.Format("%d", FUN_140dbb060());
    FUN_140165270(p, str);
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(FUN_140dbb060());
    if (spItem.get() != 0)
    {
        if (spItem->FUN_140527840()->FUN_14053c5c0() == 2)
        {
            str.Format("%d", (unsigned __int64)(unsigned)spItem->FUN_1405276c0());
            FUN_140165270(p, str);
        }
    }
}

// @0x140dbb1d0
int PetSlot::vfunc_11()
{
    if (FUN_1409b4d40(m_value18))
        m_value18.Invoke((const char*)s_strOnCooldownEnd, 0);
    m_nPetItemUid = 0;
    return DragSlot::vfunc_11();
}

// @0x140dbb240
int PetSlot::vfunc_13()
{
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(FUN_140dbb060());
    if (spItem.get() != 0)
    {
        if (spItem->FUN_140527840()->FUN_14053d150())
        {
            FUN_140d73bc0(0xc14, 0, 0, CStringW(L""));
            return 1;
        }
    }
    return 0;
}

// @0x140dbb340
int PetSlot::vfunc_14()
{
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(FUN_140dbb060());
    if (!(spItem == 0))
    {
        Unk_PsPane* pPane = FUN_140cbe1c0(0x4ef4);
        if (pPane == 0 || pPane->FUN_141924630() == 0)
        {
            int nTab = DAT_143ab2a90.FUN_140a617f0(spItem);
            int nCount = spItem->FUN_140526c50();
            int nSlot = DAT_143ab2a90.FUN_140a612b0(nTab, spItem, nCount);
            FUN_140c88c30(spItem, nSlot);
        }
        else
        {
            pPane->FUN_140f4fc40(FUN_140dbafc0());
        }
        return 1;
    }
    return 0;
}

// @0x140dbb4f0
int PetSlot::vfunc_15()
{
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(m_nPetItemUid);
    if (spItem.get() != 0)
        FUN_140d2cfc0(spItem);
    return DragSlot::vfunc_15();
}

// @0x140dbb590
int PetSlot::vfunc_17()
{
    vfunc_12();
    return 1;
}

// @0x140dbb5c0
int PetSlot::vfunc_18(void* p)
{
    DragSlot* pDrag = static_cast<DragSlot*>(p);
    Unk_PsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return pDrag->vfunc_10();
    MS2Ptr<CItem> spPet = DAT_143ab2a90.FUN_140a5d680(FUN_140535320()->FUN_140c8b2e0());
    if (!(spPet == 0))
    {
        PetSlot* pFrom = FUN_140dbc0d0(pDrag);
        if (pFrom == 0)
        {
            void* pItemSlot = FUN_140a50b50(pDrag);
            if (pItemSlot != 0)
            {
                __int64 nUid = FUN_141405a10(pItemSlot);
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
                if (spItem.get() != 0)
                    FUN_140c887b0(spItem, m_nIndex);
                FUN_141404930(nUid);
            }
            return pDrag->vfunc_10();
        }
        __int64 nUid = pFrom->FUN_140dbb060();
        FUN_140535320()->FUN_140c8b410()->FUN_140c88160(nUid, m_nIndex);
        FUN_141404930(nUid);
        return pDrag->vfunc_10();
    }
    return pDrag->vfunc_10();
}

// @0x140dbb7e0
MS2Ptr<CItem> PetSlot::vfunc_25()
{
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(m_nPetItemUid);
    return spItem;
}

// MS2-FUNCTIONAL: the frame layout of the many temporaries differs
// @0x140dbb860 (ITooltip::vfunc_0)
int PetSlot::vfunc_0(void* p)
{
    Unk_PsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(m_nPetItemUid);
    if (FUN_140534e50(&spItem) != 0)
        return 0;
    MS2Ptr<CItem> spWorn = pPlayer->FUN_14152e2f0(spItem);
    if (spWorn.get() != 0)
    {
        if (spWorn->FUN_140526a50() == spItem->FUN_140526a50())
            return 0;
    }
    ASTooltip tip(pPlayer, 0x80, 2);
    if (tip.FUN_1409e13a0(spWorn.get(), spItem.get()) == 0)
        return 0;
    CStringW strName = vfunc_22();
    if (strName.GetLength() == 0)
        tip.FUN_1409c6a20(CStringW(L""), CStringW(L""));
    else
        tip.FUN_1409c6a20(CStringW(L""), strName);
    if (FUN_1403ed2b0()->FUN_141adcb40() != 0 && spItem->FUN_140527840()->FUN_14053d510())
    {
        Unk_PsHandle handle;
        FUN_141655e10(pPlayer, &handle, 4);
        bool bSame = false;
        bool bTemp = false;
        MS2Ptr<CItem> spEquipItem;
        if (FUN_1405a8e70(&handle) != 0)
        {
            MS2Ptr<CItem>* pEquipItem = FUN_1411dc7a0(FUN_1405a8ed0(&handle), &spEquipItem);
            bTemp = true;
            bSame = (*pEquipItem == spWorn.get());
        }
        if (bTemp)
            spEquipItem = 0;
        if (bSame)
            FUN_141276180(s_strChangeDagger, CString(""));
        FUN_1405a85f0(&handle);
    }
    if (FUN_140a7bd60() == true)
        tip.FUN_1409db930(MS2Ptr<CItem>(0), spItem);
    *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
    return 1;
}

// @0x140dbbda0
int PetSlot::vfunc_8(void* p)
{
    Unk_PsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(m_nPetItemUid);
    if (!(spItem == 0))
    {
        ASSlot slot(2);
        if (slot.FUN_1409c3860(spItem.get(), pPlayer, 0x1c01f) == 0)
            return 0;
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140dbbee0
void PetSlot::vfunc_23(void* p)
{
    FUN_141404ce0(FUN_140dbaf10(), p, &m_value18);
}

// @0x140dbbf30
void PetSlot::vfunc_24(void* p)
{
    FUN_1414050c0(FUN_140dbaf10(), p, &m_value18);
}

// @0x140dbbf80
void PetSlot::vfunc_o178_2(void*)
{
    FUN_140dbc010();
}

// @0x140dbbfb0
void PetSlot::vfunc_o178_1(void*)
{
    FUN_140dbc010();
}

// @0x140dbbfe0
void PetSlot::vfunc_o178_5(void*)
{
    FUN_140dbc010();
}

// @0x140dbc010
void PetSlot::FUN_140dbc010()
{
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(m_nPetItemUid);
    if (!(spItem == 0))
    {
        if (FUN_140764020()->FUN_1416ce170(spItem) != 0)
            vfunc_10();
    }
}

// @0x140dbc0d0
PetSlot* FUN_140dbc0d0(DragSlot* p)
{
    PetSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200067, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x140dbc370
void FUN_140dbc370(const CString& strName, int nCount)
{
    PetSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) PetSlotBag(strName);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140dbc420
void FUN_140dbc420(const CString& strName)
{
    PetSlotBag* pBag = FUN_140dbc9f0(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140dbc470
PetSlotBag::PetSlotBag(const CString& strName)
    : DragSlotBag(strName)
{
    FUN_1419cae20(FUN_140a6a840(), this);
}

// @0x140dbc520
PetSlotBag::~PetSlotBag()
{
    FUN_1419caeb0(FUN_140a6a840(), this);
}

// @0x140dbc5c0
int PetSlotBag::vfunc_il1()
{
    Unk_PsPetDialog* pDlg = FUN_140b99ba0(0x4f38);
    if (pDlg != 0 && pDlg->vfunc_55() == 0)
        return 1;
    return 0;
}

// @0x140dbc610
void PetSlotBag::vfunc_il6(void* p)
{
    CItem* pItem = static_cast<CItem*>(p);
    DragSlot* pSlot = FUN_1422cd070(pItem->FUN_140526b50());
    PetSlot* pPetSlot = FUN_140dbc0d0(pSlot);
    if (pPetSlot != 0)
    {
        pPetSlot->FUN_140dbb080(pItem->FUN_140526a50());
        pPetSlot->vfunc_10();
    }
    Unk_PsPetDialog* pDlg = FUN_140b99ba0(0x4f38);
    if (pDlg != 0)
        pDlg->FUN_140e74640(3);
}

// @0x140dbc6b0
void PetSlotBag::vfunc_il7(void* p)
{
    CItem* pItem = static_cast<CItem*>(p);
    DragSlot* pSlot = FUN_1422cd070(pItem->FUN_140526b50());
    if (pSlot != 0)
        pSlot->vfunc_11();
    Unk_PsPetDialog* pDlg = FUN_140b99ba0(0x4f38);
    if (pDlg != 0)
        pDlg->FUN_140e74640(4);
}

// @0x140dbc730
void PetSlotBag::vfunc_il8(void* p)
{
    CItem* pItem = static_cast<CItem*>(p);
    DragSlot* pSlot = FUN_1422cd070(pItem->FUN_140526b50());
    PetSlot* pPetSlot = FUN_140dbc0d0(pSlot);
    if (pPetSlot != 0)
    {
        pPetSlot->FUN_140dbb080(pItem->FUN_140526a50());
        pPetSlot->vfunc_10();
    }
    Unk_PsPetDialog* pDlg = FUN_140b99ba0(0x4f38);
    if (pDlg != 0)
        pDlg->FUN_140e74640(5);
}

// @0x140dbc7d0
DragSlot* PetSlotBag::vfunc_16(int nIndex)
{
    CString strName = DragSlotBag::vfunc_15(nIndex);
    unsigned __int64 nUid = FUN_140dbc8b0(nIndex);
    PetSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) PetSlot(strName, nIndex, nUid);
    return pSlot;
}

// @0x140dbc8b0
unsigned __int64 PetSlotBag::FUN_140dbc8b0(int nIndex)
{
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    FUN_140535320()->FUN_140c8b410()->FUN_140c87ef0(items);
    for (unsigned i = 0; i < items.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = items[i];
        if (spItem.get() != 0)
        {
            if (spItem->FUN_140526b50() == nIndex)
                return spItem->FUN_140526a50();
        }
    }
    return 0;
}

// @0x140dbc9f0
PetSlotBag* FUN_140dbc9f0(NotifyContext::BindData* p)
{
    PetSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200066, (void**)&pBag))
        return pBag;
    else
        return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca56f0-0x142ca57f0 .text$yd
