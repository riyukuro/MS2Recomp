// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemCustomizeController factory and controller registry
// (second TU of ?\itemcustomizecontroller.cpp#1's queue row; the row's range only covered the base class TU).
// MS2-UNIT: ?\itemcustomizecontroller.cpp#1b
// MS2-RANGE: 0x1414131e0-0x141414d60 .text$mn
// MS2-RANGE: 0x1400f5e00-0x1400f5fd0 .text$di
// MS2-RANGE: 0x142cb1c80-0x142cb1d50 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemcustomizecontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemcustomizecontroller_1.h"
#include "itemmorphcontroller.h"
#include "gameobject.h"
#include "itempickinghelper.h"
#include "ms2/placeholder/cmakeupcontroller.h"
#include "ms2/placeholder/ccaprotationcontroller.h"
#include "ms2/placeholder/cponytailcontroller.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>
#include <efd/SmartPointer.h>
#include <efd/MemoryDefines.h>
#include <NiString.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/citemdata.h"

// ---- out-of-unit callees ----

// The item data the controller type is chosen from (commonfiles\itemdata.cpp).
struct Unk_FactoryItemFlags : public ItemModelHead { };          // the item data has a cap rotation
struct Unk_FactoryItem : public CItemData
{
    Unk_FactoryItemFlags* FUN_14053ec70();
};

// The equipped item a controller edits (CPtred, held in MS2Ptr; ?\equipitem.cpp). Only the members this unit calls.
class CEquipItem : public CPtred
{
public:
    Unk_FactoryItem* FUN_1411dc7f0();                           // the item
    int FUN_1411dc670();                                        // item is a hat (hides hair)
    void FUN_1411dcc80(CAtlArray<MS2Ptr<Unk_PickTarget> >& aParts);   // the item's model parts
    void FUN_1411dca30(int nSlot, CAtlArray<CString>& aParts);  // attach part names of an equip slot
    MS2Ptr<Unk_PickTarget> FUN_1411dc950(const CString& strPart);   // the model of one part
};

// The local player (a world actor). FUN_141655e10 is its equipment lookup (slot -> item).
struct Unk_FactoryPlayer : public PC
{
};
struct Unk_FactoryWorld { Unk_FactoryPlayer* FUN_141bd0cc0(); };    // the local player
struct Unk_FactoryApp { int FUN_141adbd10(); };

// Scene-graph node the player's attach list holds (RTTI NiNode); FUN_141b71d10 toggles its highlight shader.
struct Unk_FactoryNodeName { Unk_FactoryNodeName(const Unk_FactoryNodeName& k); long long m_a, m_b; };
extern Unk_FactoryNodeName DAT_143a09680;
struct Unk_FactoryNode { void FUN_141b71d10(bool bOn, const Unk_FactoryNodeName& kName); };
extern char DAT_143afa4d8;                                      // NiNode::ms_RTTI
Unk_FactoryNode* FUN_14098d8d0(char* pRtti, NiAVObject* pObj);  // checked cast

// ---- the controller registry (statics defined in this TU) ----
typedef efd::SmartPointer<CItemCustomizeController> ControllerPtr;
#ifndef MS2_HOOK_DLL
// @0x1400f5e00
static CAtlList<ControllerPtr> s_listControllers(10);                // all open controllers (hair first)
// @0x1400f5e30
static ControllerPtr s_spCurrent(0);                                 // the controller being dragged
#else
extern CAtlList<ControllerPtr> s_listControllers;                    // the exe's list (DAT_143adad08, symbols-manual)
extern ControllerPtr s_spCurrent;                                    // the exe's current controller (DAT_143adacb8)
#endif
#include "ms2/placeholder/header_statics_a.h"

void FUN_1414140e0(ControllerPtr spController);
void FUN_141414250(bool bOn);

// @0x1414131e0
// Creates, initializes and registers the controller for one equipped item (NULL when the item can't be customized).
ControllerPtr FUN_1414131e0(MS2Ptr<CEquipItem> spItem, Unk_FactoryPlayer* pPlayer, Unk_ItemCustomizeListener* pListener)
{
    if (spItem.IsNull())
        return ControllerPtr(0);
    if (pPlayer == 0)
        return ControllerPtr(0);
    ControllerPtr spController(0);
    if (spItem->FUN_1411dc7f0()->FUN_14053d070())
    {
        spController = new (efd::MemHint(efd::MemHint::NONE)) CMakeupController;
        spController->Initialize(3);
    }
    else
    {
        if (spItem->FUN_1411dc7f0()->FUN_14053cfd0())
        {
            MS2Ptr<CEquipItem> spCap = pPlayer->FUN_141655e10(6);
            bool bHasCap;
            if (spCap.get() != 0)
                bHasCap = true;
            else
                bHasCap = false;
            if (bHasCap)
            {
                if (spCap->FUN_1411dc670() != 0)
                    return ControllerPtr(0);
            }
            MS2Ptr<CEquipItem> spHair = pPlayer->FUN_141655e10(1);
            if (spHair == 0)
                return ControllerPtr(0);
            CAtlArray<CString> aHairParts;
            spHair->FUN_1411dca30(1, aHairParts);
            size_t nParts = aHairParts.GetCount();
            if (nParts <= 0)
                return ControllerPtr(0);
            size_t iLast = nParts - 1;
            MS2Ptr<Unk_PickTarget> spPart = spHair->FUN_1411dc950(aHairParts.GetAt(iLast));
            if (spPart == 0)
                return ControllerPtr(0);
            if (spPart->FUN_141200ab0()->m_nKind != 0)
            {
                CItemMorphController* pMorph = new (efd::MemHint(efd::MemHint::NONE)) CItemMorphController;
                if (pMorph->Initialize(1) == 0)
                {
                    delete pMorph;
                    return ControllerPtr(0);
                }
                if (pMorph->HasMorphController() != 0)
                {
                    spController = pMorph;
                    pMorph = 0;
                }
                else
                {
                    delete pMorph;
                }
            }
            else
            {
                spController = new (efd::MemHint(efd::MemHint::NONE)) CPonyTailController;
                if (spController->Initialize(1) == 0)
                    return ControllerPtr(0);
            }
        }
        else
        {
            if (spItem->FUN_1411dc7f0()->FUN_14053c620() == 0xd)
            {
                CAtlArray<MS2Ptr<Unk_PickTarget> > aParts;
                spItem->FUN_1411dcc80(aParts);
                CItemMorphController* pMorph = new (efd::MemHint(efd::MemHint::NONE)) CItemMorphController;
                if (pMorph->Initialize(6) == 0)
                {
                    delete pMorph;
                    return ControllerPtr(0);
                }
                if (pMorph->HasMorphController() != 0)
                {
                    spController = pMorph;
                }
                else
                {
                    delete pMorph;
                    spController = 0;
                }
                if (spItem->FUN_1411dc7f0()->FUN_14053ec70()->FUN_140547150())
                {
                    spController = new (efd::MemHint(efd::MemHint::NONE)) CCapRotationController;
                    if (spController->Initialize(6) == 0)
                        return ControllerPtr(0);
                }
            }
        }
    }
    if (spController)
    {
        if (spController->IsInteractive() == 0)
            spController = 0;
        if (spController)
        {
            spController->SetListener(pListener);
            FUN_1414140e0(ControllerPtr(spController));
        }
    }
    return spController;
}

// @0x141413d80
// Per-frame update of all open controllers: the dragged one (or the first hit by the cursor) gets the input.
void FUN_141413d80()
{
    if (!s_listControllers.IsEmpty())
    {
        bool bDragging = false;
        if (reinterpret_cast<Unk_FactoryApp*>(TSingleton<CUIService>::GetInstance())->FUN_141adbd10() == 0 || s_spCurrent)
        {
            int bHit = 0;
            efd::Point3 kPos;
            for (POSITION pos = s_listControllers.GetHeadPosition(); pos != 0; s_listControllers.GetNext(pos))
            {
                ControllerPtr sp(s_listControllers.GetAt(pos));
                if (sp)
                {
                    if (bHit == 0)
                    {
                        if (s_spCurrent == 0)
                            bHit = sp->IsPickable(&kPos);
                        else
                            bHit = (s_spCurrent == sp);
                        sp->vfunc_38(bHit, kPos);
                        if (bHit != 0)
                        {
                            NiString kSlot(sp->GetSlot());
                            bDragging = kSlot != "FD";
                        }
                    }
                    else
                    {
                        sp->vfunc_38(0, kPos);
                    }
                    bDragging = bDragging || sp->GetDragging();
                    sp->vfunc_4();
                    if (sp->IsDragging2() || sp->IsDragging1())
                    {
                        s_spCurrent = sp;
                    }
                    else if (s_spCurrent == sp)
                    {
                        s_spCurrent = 0;
                    }
                }
            }
        }
        FUN_141414250(bDragging);
    }
    else
    {
        s_spCurrent = 0;
    }
}

// @0x141414050
// True while any open controller is being dragged.
int FUN_141414050()
{
    if (!s_listControllers.IsEmpty())
    {
        for (POSITION pos = s_listControllers.GetHeadPosition(); pos != 0; s_listControllers.GetNext(pos))
        {
            CItemCustomizeController* pController = s_listControllers.GetAt(pos);
            if (pController != 0 && pController->GetDragging() != 0)
                return 1;
        }
    }
    return 0;
}

// @0x1414140e0
// Registers a controller: the hair controller ("HR") goes first, the others last.
void FUN_1414140e0(ControllerPtr spController)
{
    bool bHair;
    {
        NiString kSlot(spController->GetSlot());
        bHair = kSlot == "HR";
    }
    if (bHair)
        s_listControllers.AddHead(spController);
    else
        s_listControllers.AddTail(spController);
}

// @0x141414180
// Unregisters a closed controller.
void FUN_141414180(ControllerPtr spController)
{
    if (!s_listControllers.IsEmpty())
    {
        POSITION pos = s_listControllers.Find(spController);
        if (pos != 0)
            s_listControllers.RemoveAt(pos);
    }
    if (s_spCurrent == spController)
        s_spCurrent = 0;
}

// @0x141414220
void FUN_141414220()
{
    s_listControllers.RemoveAll();
    s_spCurrent = 0;
}

// @0x141414250
// Switches the highlight of every attached node of the local player.
void FUN_141414250(bool bOn)
{
    Unk_FactoryPlayer* pPlayer = reinterpret_cast<Unk_FactoryWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        efd::list<NiAVObject*> listNodes;
        pPlayer->vfunc_44(&listNodes);
        for (efd::list<NiAVObject*>::iterator it = listNodes.begin(); it != listNodes.end(); ++it)
        {
            Unk_FactoryNode* pNode = FUN_14098d8d0(&DAT_143afa4d8, *it);
            if (pNode == 0)
                continue;
            Unk_FactoryNodeName kName(DAT_143a09680);
            pNode->FUN_141b71d10(bOn, kName);
        }
    }
}

// @0x141414760
int CItemCustomizeController::IsInteractive() const
{
    int bResult;
    if (m_bUseButton1 == 0 && m_bUseButton2 == 0 && m_bEnabled == 0)
        bResult = 0;
    else
        bResult = 1;
    return bResult;
}

MS2_EMIT_CRT_MEMMOVE_S();  // CRT memmove_s copy at the tail of the TU
