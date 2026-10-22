// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition classes Movement, InventoryTab and GameScene
// (factories, names, checks). See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a76f0
// MS2-RANGE: 0x1413a76f0-0x1413a7bc0 .text$mn
// MS2-RANGE: 0x1400f36a0-0x1400f36f0 .text$di
// MS2-RANGE: 0x1400f3a10-0x1400f3a60 .text$di
// MS2-RANGE: 0x1413b4e40-0x1413b4e80 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The local player: only the position getter (slot 18) is used here.
class Unk_GcPC
{
public:
    virtual void Unk_Slot0(); virtual void Unk_Slot1(); virtual void Unk_Slot2(); virtual void Unk_Slot3();
    virtual void Unk_Slot4(); virtual void Unk_Slot5(); virtual void Unk_Slot6(); virtual void Unk_Slot7();
    virtual void Unk_Slot8(); virtual void Unk_Slot9(); virtual void Unk_Slot10(); virtual void Unk_Slot11();
    virtual void Unk_Slot12(); virtual void Unk_Slot13(); virtual void Unk_Slot14(); virtual void Unk_Slot15();
    virtual void Unk_Slot16(); virtual void Unk_Slot17();
    virtual Vector3 vfunc_18();                     // 0x90 the position
};

// The world manager (FUN_1403ed2d0).
class Unk_GcWorld
{
public:
    Unk_GcPC* FUN_141bd0cc0();                              // the local player
};
Unk_GcWorld* FUN_1403ed2d0();

// The inventory dialog (id 0x4e2d); vfunc_55 is UIDialog's "closed" test.
class Unk_TabInventory : public UIDialog
{
public:
    int FUN_141999de0();                                    // the selected tab
};
Unk_TabInventory* FUN_1405344f0(int nId);

void* FUN_1408e57f0();
int FUN_1422b9e00(void* p);                                 // the current scene id

extern Vector3 DAT_143b01a60;                       // the zero point

#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGameScene(L"CGuideConditionGameScene", CGuideConditionGameScene::CreateObject);     // .text$di 0x1400f36a0
static ClassObjectRegistrar s_regInventoryTab(L"CGuideConditionInventoryTab", CGuideConditionInventoryTab::CreateObject);   // .text$di 0x1400f3a10
#endif

// ---- CGuideConditionMovement ------------------------------------------------------------------------------------------------

// @0x1413a76f0
ClassObject* CGuideConditionMovement::CreateObject()
{
    return new CGuideConditionMovement;
}

// @0x1413a7750
CStringW CGuideConditionMovement::GetTypeName()
{
    return L"CGuideConditionMovement";
}
MS2_REPLACE_METHOD(0x1413A7750, CGuideConditionMovement, GetTypeName, 61, 0x03B2B466);

// @0x1413a77a0
CGuideConditionMovement::CGuideConditionMovement()
{
    m_fMoved = 0;
    m_vLastPos = DAT_143b01a60;
}

// @0x1413a7820
int CGuideConditionMovement::vfunc_3()
{
    Unk_GcPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (m_vLastPos.FUN_140552690(DAT_143b01a60))
        m_vLastPos = pPC->vfunc_18();
    m_fMoved += m_vLastPos.FUN_140965c40(pPC->vfunc_18()).FUN_140967ac0();
    m_vLastPos = pPC->vfunc_18();
    bool bDone;
    if ((float)m_n20 <= m_fMoved)
        bDone = true;
    else
        bDone = false;
    return FUN_1413a5600(bDone);
}
MS2_REPLACE_METHOD(0x1413A7820, CGuideConditionMovement, vfunc_3, 289, 0x92925FED);

// @0x1413a7950
void CGuideConditionMovement::vfunc_4()
{
    CGuideCondition::vfunc_4();
    m_vLastPos = DAT_143b01a60;
    m_fMoved = 0;
}
MS2_REPLACE_METHOD(0x1413A7950, CGuideConditionMovement, vfunc_4, 61, 0x5AEA556C);

// ---- CGuideConditionInventoryTab --------------------------------------------------------------------------------------------

// @0x1413a79a0
ClassObject* CGuideConditionInventoryTab::CreateObject()
{
    return new CGuideConditionInventoryTab;
}

// @0x1413a7a00
CStringW CGuideConditionInventoryTab::GetTypeName()
{
    return L"CGuideConditionInventoryTab";
}
MS2_REPLACE_METHOD(0x1413A7A00, CGuideConditionInventoryTab, GetTypeName, 61, 0x68191F36);

// @0x1413a7a50
int CGuideConditionInventoryTab::vfunc_3()
{
    Unk_TabInventory* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0 && pInv->vfunc_55() == 0)
        return FUN_1413a5600(m_n20 == pInv->FUN_141999de0());
    return 0;
}
MS2_REPLACE_METHOD(0x1413A7A50, CGuideConditionInventoryTab, vfunc_3, 111, 0xD63E69C8);

// ---- CGuideConditionGameScene -----------------------------------------------------------------------------------------------

// @0x1413a7ad0
ClassObject* CGuideConditionGameScene::CreateObject()
{
    return new CGuideConditionGameScene;
}

// @0x1413a7b30
CStringW CGuideConditionGameScene::GetTypeName()
{
    return L"CGuideConditionGameScene";
}
MS2_REPLACE_METHOD(0x1413A7B30, CGuideConditionGameScene, GetTypeName, 61, 0xCE0AB459);

// @0x1413a7b80
int CGuideConditionGameScene::vfunc_3()
{
    return FUN_1422b9e00(FUN_1408e57f0()) == 0x620001d;
}
MS2_REPLACE_METHOD(0x1413A7B80, CGuideConditionGameScene, vfunc_3, 56, 0xA135E761);
