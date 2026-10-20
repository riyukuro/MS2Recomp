// cguidecondition.h - PLACEHOLDER for the guide-quest condition classes (RTTI .?AVCGuideCondition@@ and subclasses): the
// ClassObject-derived predicates the CGuideManager evaluates (a name factory per class, an XML loader in vfunc_2,
// the check in vfunc_3). The base lives in ?\guideentity.cpp (ctor 0x1413a54e0, dtor 0x1413a5540, vftable 0x142f05b80,
// slots 2..8 at 0x1413a5670..0x1413a5810, helper 0x1413a5600 / 0x1413a5820); the subclasses are spread over
// unit_1413a8370 / unit_1413a9a50 / unit_1413a9df0 (ctors 0x1413b2b30.., vftables, deleting dtors). NOT an original
// header; member names invented from their use. Append new subclasses here (layout proven from their ctors / operator new).
#pragma once
#include "ms2/ms2format.h"

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/nipoint3.h"

class Unk_140165cf0;
class Unk_GcCondList;

// 0x28. m_n18 is the condition kind (the subclass ctor/loader sets it), m_b1c negates the check, m_n20 is the XML "value".
class CGuideCondition : public ClassObject
{
public:
    CGuideCondition();                                      // 0x1413a54e0
    virtual ~CGuideCondition();                             // 0 0x1413a5540
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a5670: "value" / negate attributes
    virtual int vfunc_3();                                  // 3 0x1413a56d0: 0
    virtual void vfunc_4();                                 // 4 0x1413a56e0
    virtual void vfunc_5();                                 // 5 0x1413a56f0: logs "Nothing TestCase"
    virtual bool vfunc_6(Unk_GcCondList* pFailed);          // 6 0x1413a5740: false (AllOf collects the failed conditions)
    virtual CStringW vfunc_7();                       // 7 0x1413a5760: description
    virtual int vfunc_8();                                  // 8 0x1413a5810: 0

    int FUN_1413a5600(bool bResult);
    int FUN_1413a55a0(int nResult);                         // 0x1413a55a0 like FUN_1413a5600 for an int result (negated when m_b1c)
    CStringW FUN_1413a5820();                                // 0x1413a5820    // 0x1413a5820 the base description text                        // 0x1413a5600 applies m_b1c (negation) to a check result

    int m_n18;                                              // +0x18
    bool m_b1c;                                             // +0x1c
    int m_n20;                                              // +0x20
};
MS2_CHECK_SIZE(CGuideCondition, 0x28);

// 0x30. Passes while the current map id equals m_n20 or lies in [m_nRangeBeg, m_nRangeEnd].
class CGuideConditionFieldId : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a9bc0
    CGuideConditionFieldId();                               // 0x1413b2cf0
    virtual CStringW vfunc_1();                             // 1 0x1413a9c20
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a9c70
    virtual int vfunc_3();                                  // 3 0x1413a9d40
    virtual CStringW vfunc_7();                             // 7 0x1413a9df0
    virtual int vfunc_8();                                  // 8 0x1413a9ec0

    int m_nRangeBeg;                                        // +0x28
    int m_nRangeEnd;                                        // +0x2c
};
MS2_CHECK_SIZE(CGuideConditionFieldId, 0x30);

// 0x38. Counts the inventory items of one type (m_nItemType) against [m_nMin, m_nMax] (-1 = unbounded).
class CGuideConditionCountItem : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a9610
    CGuideConditionCountItem();                             // 0x1413b2b60
    virtual CStringW vfunc_1();                             // 1 0x1413a9670
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a96c0: itemType / minValue / maxValue
    virtual int vfunc_3();                                  // 3 0x1413a9770
    virtual CStringW vfunc_7();                             // 7 0x1413a9820
    virtual int vfunc_8();                                  // 8 0x1413a98f0: 0

    int m_nItemType;                                        // +0x28
    int m_nMin;                                             // +0x2c
    int m_nMax;                                             // +0x30
    int m_pad_34;
};
MS2_CHECK_SIZE(CGuideConditionCountItem, 0x38);

// 0x38. CountItem over the placeable (indoor-install) items of the cube tab.
class CGuideConditionCountInDoorInstallItem : public CGuideConditionCountItem
{
public:
    static ClassObject* CreateObject();                     // 0x1413a9900
    CGuideConditionCountInDoorInstallItem();                // 0x1413b2b30
    virtual CStringW vfunc_1();                             // 1 0x1413a9960
    virtual int vfunc_3();                                  // 3 0x1413a99b0
    virtual void vfunc_5();                                 // 5 0x1413a9a50

    int FUN_1413a9ac0();                                    // 0x1413a9ac0 the number of placeable items in the inventory tab 4
};
MS2_CHECK_SIZE(CGuideConditionCountInDoorInstallItem, 0x38);

// 0x30. Passes after the key/condition m_n20 has been held for m_nTick ms (0 = immediately).
class CGuideConditionInput : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a6580
    CGuideConditionInput();                                 // 0x1413a6630
    virtual CStringW vfunc_1();                             // 1 0x1413a65e0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a6670
    virtual int vfunc_3();                                  // 3 0x1413a66c0
    virtual void vfunc_4();                                 // 4 0x1413a67d0
    virtual CStringW vfunc_7();                       // 7 0x1413a6800

    unsigned m_nTick;                                           // +0x28
    int m_nDeadline;                                        // +0x2c
};
MS2_CHECK_SIZE(CGuideConditionInput, 0x30);

// 0x28. Passes when any of the key bindings of action m_n20 is pressed.
class CGuideConditionActionInput : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a68b0
    CGuideConditionActionInput();
    virtual CStringW vfunc_1();                             // 1 0x1413a6910
    virtual int vfunc_3();                                  // 3 0x1413a6960
};
MS2_CHECK_SIZE(CGuideConditionActionInput, 0x28);

// 0x28. Passes while a field object of type 6 exists.
class CGuideConditionReturnPortal : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a6bc0
    CGuideConditionReturnPortal();
    virtual CStringW vfunc_1();                             // 1 0x1413a6c20
    virtual int vfunc_3();                                  // 3 0x1413a6c70
};
MS2_CHECK_SIZE(CGuideConditionReturnPortal, 0x28);

// 0x28. Passes while a field portal contains the local player's position.
class CGuideConditionPortalEnable : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a6ca0
    CGuideConditionPortalEnable();
    virtual CStringW vfunc_1();                             // 1 0x1413a6d00
    virtual int vfunc_3();                                  // 3 0x1413a6d50
};
MS2_CHECK_SIZE(CGuideConditionPortalEnable, 0x28);

// 0x38. Passes once the local player has walked m_n20 units (the summed distance between successive checks).
class CGuideConditionMovement : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a76f0
    CGuideConditionMovement();                              // 0x1413a77a0
    virtual CStringW vfunc_1();                             // 1 0x1413a7750
    virtual int vfunc_3();                                  // 3 0x1413a7820
    virtual void vfunc_4();                                 // 4 0x1413a7950

    Unk_StreamPoint m_vLastPos;                             // +0x28 the player position at the previous check
    float m_fMoved;                                         // +0x34 the distance walked so far
};
MS2_CHECK_SIZE(CGuideConditionMovement, 0x38);

// 0x28. Passes while the inventory dialog shows the tab m_n20.
class CGuideConditionInventoryTab : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a79a0
    CGuideConditionInventoryTab();
    virtual CStringW vfunc_1();                             // 1 0x1413a7a00
    virtual int vfunc_3();                                  // 3 0x1413a7a50
};
MS2_CHECK_SIZE(CGuideConditionInventoryTab, 0x28);

// 0x28. Passes while the game scene (id 0x620001d) is the current one.
class CGuideConditionGameScene : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7ad0
    CGuideConditionGameScene();
    virtual CStringW vfunc_1();                             // 1 0x1413a7b30
    virtual int vfunc_3();                                  // 3 0x1413a7b80
};
MS2_CHECK_SIZE(CGuideConditionGameScene, 0x28);

// 0x30. Passes once m_n20 ms have elapsed since the first check, or when the UI is idle and the key-binding query 0x493e2 holds.
class CGuideConditionNext : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7bc0
    CGuideConditionNext();                                  // 0x1413a7c70
    virtual CStringW vfunc_1();                             // 1 0x1413a7c20
    virtual int vfunc_3();                                  // 3 0x1413a7cb0
    virtual void vfunc_4();                                 // 4 0x1413a7d40

    unsigned m_nStart;                                      // +0x28 the clock at the first check (0 = not started)
    int m_pad_2c;
};
MS2_CHECK_SIZE(CGuideConditionNext, 0x30);

// 0x28. Passes while the quest m_n20 is satisfied (all objectives done).
class CGuideConditionQuestSatisfied : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7d70
    CGuideConditionQuestSatisfied();                        // 0x1413b3310
    virtual CStringW vfunc_1();                             // 1 0x1413a7dd0
    virtual int vfunc_3();                                  // 3 0x1413a7e20
};
MS2_CHECK_SIZE(CGuideConditionQuestSatisfied, 0x28);

// 0x28. Passes while the quest m_n20 is complete.
class CGuideConditionQuestComplete : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7e60
    CGuideConditionQuestComplete();                         // 0x1413b32b0
    virtual CStringW vfunc_1();                             // 1 0x1413a7ec0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a7f10
    virtual int vfunc_3();                                  // 3 0x1413a7f50
    virtual int vfunc_8();                                  // 8 0x1413a7f90
};
MS2_CHECK_SIZE(CGuideConditionQuestComplete, 0x28);

// 0x28. Passes while the quest m_n20 is in progress.
class CGuideConditionQuestProgress : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7fc0
    CGuideConditionQuestProgress();                         // 0x1413b32e0
    virtual CStringW vfunc_1();                             // 1 0x1413a8020
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a8070
    virtual int vfunc_3();                                  // 3 0x1413a80b0
    virtual int vfunc_8();                                  // 8 0x1413a80f0
};
MS2_CHECK_SIZE(CGuideConditionQuestProgress, 0x28);

// 0x28. Passes while the local player is dead.
class CGuideConditionDead : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a8120
    CGuideConditionDead();                                  // 0x1413b2bc0
    virtual CStringW vfunc_1();                             // 1 0x1413a8180
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a81d0
    virtual int vfunc_3();                                  // 3 0x1413a8210
    virtual int vfunc_8();                                  // 8 0x1413a8260
};
MS2_CHECK_SIZE(CGuideConditionDead, 0x28);

// 0x28. Passes while the local player is in construct (cube build) mode.
class CGuideConditionConstructMode : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a8270
    CGuideConditionConstructMode();                         // 0x1413b2a70
    virtual CStringW vfunc_1();                             // 1 0x1413a82d0
    virtual int vfunc_3();                                  // 3 0x1413a8320
};
MS2_CHECK_SIZE(CGuideConditionConstructMode, 0x28);

// 0x60. Passes while the dialog (by id m_nDialogID, else by name m_strDialog) is open (m_nIsOpen = 1) or closed (0), every
// "control" child is visible and, when m_nSubIndex >= 0, the dialog shows that sub page.
class CGuideConditionDialog : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a6010
    CGuideConditionDialog();                                // 0x1413a60c0
    virtual ~CGuideConditionDialog();                       // 0 0x1413b4700
    virtual CStringW vfunc_1();                             // 1 0x1413a6070
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a6480: dialogName / dialogID / isOpen / subIndex / control
    virtual int vfunc_3();                                  // 3 0x1413a6140
    virtual CStringW vfunc_7();                             // 7 0x1413a6300
    virtual int vfunc_8();                                  // 8 0x1413a6430

    int m_nIsOpen;                                          // +0x28 "isOpen" (1)
    unsigned m_nDialogID;                                   // +0x2c "dialogID"
    CStringA m_strDialog;                                   // +0x30 "dialogName"
    int m_nSubIndex;                                        // +0x38 "subIndex" (-1)
    int m_pad_3c;
    ATL::CAtlArray<CString> m_arrControl;                   // +0x40 "control": the child names that must be visible
};
MS2_CHECK_SIZE(CGuideConditionDialog, 0x60);

// 16 bytes. One "cube" child of a Position condition: a point and the radius around it.
struct Unk_GuideCube : Unk_StreamPoint
{
    Unk_GuideCube() {}                                      // 0x1413b3580 (the exe leaves fRange unset)
    float fRange;
};
MS2_CHECK_SIZE(Unk_GuideCube, 0x10);

// 0x48. Passes while the local player (or its cube-craft position) is within the range of one of the cubes.
class CGuideConditionPosition : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a6e30
    CGuideConditionPosition();                              // 0x1413a6ee0
    virtual CStringW vfunc_1();                             // 1 0x1413a6e90
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a6f30: the "cube" children (pos="x,y,z" range=75)
    virtual int vfunc_3();                                  // 3 0x1413a70e0
    virtual CStringW vfunc_7();                             // 7 0x1413a7220

    ATL::CAtlArray<Unk_GuideCube> m_arrCube;                // +0x28
};
MS2_CHECK_SIZE(CGuideConditionPosition, 0x48);

// 0x28. Passes while the local player's action id equals m_n20.
class CGuideConditionState : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a73a0
    CGuideConditionState();
    virtual CStringW vfunc_1();                             // 1 0x1413a7400
    virtual int vfunc_3();                                  // 3 0x1413a7450
};
MS2_CHECK_SIZE(CGuideConditionState, 0x28);

// 0x28. Passes while the interactable object next to the local player is usable (all of its use checks hold).
class CGuideConditionInteractable : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a74c0
    CGuideConditionInteractable();
    virtual CStringW vfunc_1();                             // 1 0x1413a7520
    virtual int vfunc_3();                                  // 3 0x1413a7570
};
MS2_CHECK_SIZE(CGuideConditionInteractable, 0x28);

// 0x30. Passes while the skill m_n20 is (isEquip = 1) or is not (0) on a skill slot.
class CGuideConditionEquipSkill : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a8370
    CGuideConditionEquipSkill();                            // 0x1413a8420
    virtual CStringW vfunc_1();                             // 1 0x1413a83d0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a8460: "isEquip"
    virtual int vfunc_3();                                  // 3 0x1413a84b0
    virtual CStringW vfunc_7();                             // 7 0x1413a8530

    int m_nIsEquip;                                         // +0x28
    int m_pad_2c;
};
MS2_CHECK_SIZE(CGuideConditionEquipSkill, 0x30);

// 0x28. Passes while the local player has the cube-construct permission.
class CGuideConditionConstructable : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a85f0
    CGuideConditionConstructable();                         // 0x1413b2ad0
    virtual CStringW vfunc_1();                             // 1 0x1413a8650
    virtual int vfunc_3();                                  // 3 0x1413a86a0
};
MS2_CHECK_SIZE(CGuideConditionConstructable, 0x28);

// 0x28. Passes while the local player stands in their own home.
class CGuideConditionIsMyHome : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a86f0
    CGuideConditionIsMyHome();                              // 0x1413b2f00
    virtual CStringW vfunc_1();                             // 1 0x1413a8750
    virtual int vfunc_3();                                  // 3 0x1413a87a0
};
MS2_CHECK_SIZE(CGuideConditionIsMyHome, 0x28);

// 0x28. Passes while the achievement dialog (ui 0x4e73) shows the tab m_n20.
class CGuideConditionAchieveTab : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a87d0
    CGuideConditionAchieveTab();                            // 0x1413b2930
    virtual CStringW vfunc_1();                             // 1 0x1413a8830
    virtual int vfunc_3();                                  // 3 0x1413a8880
};
MS2_CHECK_SIZE(CGuideConditionAchieveTab, 0x28);

// 0x48. Passes while the equip slot (m_nSlotType, m_strSlotName) holds an item with the id m_nItemID (0 = any) or an id in
// [m_nItemRangeBegin, m_nItemRangeLast] (0 = unbounded).
class CGuideConditionEquipItem : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a8900
    CGuideConditionEquipItem();                             // 0x1413b2c20
    virtual CStringW vfunc_1();                             // 1 0x1413a8960
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a89b0: slotType / slotName / itemID / itemRangeBeginID / itemRangeLastID
    virtual int vfunc_3();                                  // 3 0x1413a8aa0
    virtual CStringW vfunc_7();                             // 7 0x1413a8da0

    unsigned m_nSlotType;                                   // +0x28
    int m_pad_2c;
    CStringA m_strSlotName;                                 // +0x30
    unsigned m_nItemID;                                     // +0x38
    unsigned m_nItemRangeBegin;                             // +0x3c
    unsigned m_nItemRangeLast;                              // +0x40
    int m_pad_44;
};
MS2_CHECK_SIZE(CGuideConditionEquipItem, 0x48);

// 0x28. Passes while the ugc management dialog (ui 0x4ec5) is open on its first page.
class CGuideConditionUgcManagementTab : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a8eb0
    CGuideConditionUgcManagementTab();                      // 0x1413b3520
    virtual CStringW vfunc_1();                             // 1 0x1413a8f10
    virtual int vfunc_3();                                  // 3 0x1413a8f60
};
MS2_CHECK_SIZE(CGuideConditionUgcManagementTab, 0x28);

// 0x30. Passes while the inventory holds a ugc design item (of the type m_nItemType, 0 = any).
class CGuideConditionDesignItem : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a8fc0
    CGuideConditionDesignItem();                            // 0x1413b2bf0
    virtual CStringW vfunc_1();                             // 1 0x1413a9020
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a9070: "itemType"
    virtual int vfunc_3();                                  // 3 0x1413a90d0
    virtual CStringW vfunc_7();                             // 7 0x1413a9260
    virtual int vfunc_8();                                  // 8 0x1413a9310: 0

    int m_nItemType;                                        // +0x28
    int m_pad_2c;
};
MS2_CHECK_SIZE(CGuideConditionDesignItem, 0x30);

// 0x38. Passes while the inventory has the item m_nItemId, an item of the type m_nItemType and one of the icon type m_nIconType.
class CGuideConditionExistItem : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a9320
    CGuideConditionExistItem();                             // 0x1413b2c60
    virtual CStringW vfunc_1();                             // 1 0x1413a9380
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a93d0: itemId / itemType / iconType
    virtual int vfunc_3();                                  // 3 0x1413a9480
    virtual CStringW vfunc_7();                             // 7 0x1413a9540

    int m_nItemId;                                          // +0x28
    int m_nItemType;                                        // +0x2c
    int m_nIconType;                                        // +0x30
    int m_pad_34;
};
MS2_CHECK_SIZE(CGuideConditionExistItem, 0x38);

// ---- helper values of the conditions below (layouts proven from the XML readers and the condition checks) ----------------

// The conditions of a nested condition (AnyOne / AllOf): the smart pointers hold the condition built by 0x1413a52c0.
// A refcounted condition handle: the exe's MS2Ptr<CGuideCondition> (16 bytes, pointer at +8; get 0x141387b90,
// operator-> 0x141387bb0, AddRef 0x141388ed0). A real RAII value: `return ref;` is the move ctor.
class Unk_GcCondRef
{
public:
    Unk_GcCondRef();                                        // 0x1413a4750 null
    explicit Unk_GcCondRef(CGuideCondition* pCond);         // 0x1413b28b0 holds a new pointer (AddRef)
    Unk_GcCondRef(Unk_GcCondRef&& rhs);                     // 0x1413b2880 move: takes the pointer of rhs
    ~Unk_GcCondRef();                                       // 0x141387660 release (MS2Ptr<CGuideCondition> dtor)
    CGuideCondition* FUN_141387bb0();                       // the held condition
    CGuideCondition* FUN_141387b90();                       // get(): the held pointer (tested for null)
    void FUN_141388ed0();                                   // creates the refcount block
    void* m_pRc;
    CGuideCondition* m_p;
};
MS2_CHECK_SIZE(Unk_GcCondRef, 0x10);
// The same 16 bytes as a trivial element (the CAtlArray glue of the condition lists moves them as raw handles).
struct Unk_GcCondRefRaw { void* m_pRc; CGuideCondition* m_p; };

class Unk_GcCondList
{
public:
    unsigned __int64 FUN_1413886d0();                             // count
    Unk_GcCondRef& FUN_141387b40(size_t nIdx);              // the nth
    void FUN_141388460(const Unk_GcCondRef& ref);           // append
    CAtlArray<void*> m_arr;
};
MS2_CHECK_SIZE(Unk_GcCondList, 0x20);

// A set-flag + value optional (the flag is the first byte).
struct Unk_GcOptInt
{
    Unk_GcOptInt() : m_bSet(false) {}
    Unk_GcOptInt& operator=(const int& nValue);             // 0x1413b4010 (Nullable<int>::operator=(value))
    bool m_bSet; int m_nValue;
};
MS2_CHECK_SIZE(Unk_GcOptInt, 8);
struct Unk_GcOptVec3
{
    Unk_GcOptVec3() : m_bSet(false) {}
    Unk_GcOptVec3& operator=(const Unk_StreamPoint& pt);    // 0x1413b4040 (Nullable<Point3>::operator=(value))
    Unk_StreamPoint& GetValue();                            // 0x1413b4180 (asserts m_isValueSet)
    const Unk_StreamPoint& GetValue() const;                // 0x1413b4140
    bool m_bSet; float m_x; float m_y; float m_z;
};
MS2_CHECK_SIZE(Unk_GcOptVec3, 0x10);
struct Unk_GcOptBool
{
    Unk_GcOptBool() : m_bSet(false) {}
    Unk_GcOptBool& operator=(const bool& bValue);           // 0x1413b4080 (Nullable<bool>::operator=(value))
    bool& GetValue();                                       // 0x1413b41c0 (asserts m_isValueSet)
    bool m_bSet; bool m_bValue;
};
MS2_CHECK_SIZE(Unk_GcOptBool, 2);

// A calendar time (the ServerTime target / now).
class Unk_GcTime
{
public:
    Unk_GcTime();                                                   // 0x1406c4730 (calls 0x1406c5270(this, 0, 0))
    Unk_GcTime& FUN_1406c47a0(unsigned __int64 nTime);              // from the epoch seconds
    Unk_GcTime& FUN_1406c47d0(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec);
    Unk_GcTime& FUN_1406c4930(const Unk_GcTime& rhs);               // operator=
    bool FUN_1406c4cc0(const Unk_GcTime& now) const;                // passed
    unsigned __int64 FUN_140282020() const;                         // the epoch seconds
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_GcTime, 0x10);

// 0x28. Passes while the local player is on the continent m_n20 (the continent code of the current map).
class CGuideConditionContinentCode : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a9f10
    CGuideConditionContinentCode();                         // ctor (out of range)
    virtual CStringW vfunc_1();                             // 1 0x1413a9f70
    virtual int vfunc_3();                                  // 3 0x1413a9fc0
};
MS2_CHECK_SIZE(CGuideConditionContinentCode, 0x28);

// 0x48. Passes while one of the nested <condition> elements passes.
class CGuideConditionAnyOne : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413aa070
    CGuideConditionAnyOne();
    virtual CStringW vfunc_1();                             // 1 0x1413aa0d0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413aa120: the nested conditions
    virtual int vfunc_3();                                  // 3 0x1413aa1d0
    virtual void vfunc_4();                                 // 4 0x1413aa250

    Unk_GcCondList m_conds;                                 // +0x28
};
MS2_CHECK_SIZE(CGuideConditionAnyOne, 0x48);

// 0x48. Passes while all of the nested <condition> elements pass.
class CGuideConditionAllOf : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413aa2e0
    CGuideConditionAllOf();
    virtual CStringW vfunc_1();                             // 1 0x1413aa340
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413aa390
    virtual int vfunc_3();                                  // 3 0x1413aa500
    virtual bool vfunc_6(Unk_GcCondList* pFailed);          // 6 0x1413aa440: true; appends the failing conditions

    Unk_GcCondList m_conds;                                 // +0x28
};
MS2_CHECK_SIZE(CGuideConditionAllOf, 0x48);

// 0x30. Passes while the trophy of the achievement type m_type exists.
class CGuideConditionAchieveExistTrophy : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413aa580
    CGuideConditionAchieveExistTrophy();
    virtual CStringW vfunc_1();                             // 1 0x1413aa5e0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413aa630: achieveType
    virtual int vfunc_3();                                  // 3 0x1413aa680
    virtual CStringW vfunc_7();                             // 7 0x1413aa6c0

    Unk_GcOptInt m_type;                                    // +0x28
};
MS2_CHECK_SIZE(CGuideConditionAchieveExistTrophy, 0x30);

// 0x30. Passes while the guide m_nGuideId is open.
class CGuideConditionGuideOpen : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413aa7e0
    CGuideConditionGuideOpen();
    virtual CStringW vfunc_1();                             // 1 0x1413aa840
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413aa890: id (kind 13)
    virtual int vfunc_3();                                  // 3 0x1413aa8f0
    virtual CStringW vfunc_7();                             // 7 0x1413aa990
    virtual int vfunc_8();                                  // 8 0x1413aaa40: 0

    int m_nGuideId;                                         // +0x28
};
MS2_CHECK_SIZE(CGuideConditionGuideOpen, 0x30);

// 0x30. Passes while the guide m_nGuideId is cleared.
class CGuideConditionGuideClear : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413aaa50
    CGuideConditionGuideClear();
    virtual CStringW vfunc_1();                             // 1 0x1413aaab0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413aab00: id (kind 2)
    virtual int vfunc_3();                                  // 3 0x1413aab60
    virtual CStringW vfunc_7();                             // 7 0x1413aaba0
    virtual int vfunc_8();                                  // 8 0x1413aac50

    int m_nGuideId;                                         // +0x28
};
MS2_CHECK_SIZE(CGuideConditionGuideClear, 0x30);

// 0x30. Passes while the key / skill slot m_nSlotIndex holds the skill m_nSkillId.
class CGuideConditionExistShortcut : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413aac80
    CGuideConditionExistShortcut();
    virtual CStringW vfunc_1();                             // 1 0x1413aace0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413aad30: slotIndex / skillID
    virtual int vfunc_3();                                  // 3 0x1413aadb0
    virtual CStringW vfunc_7();                             // 7 0x1413aae10

    int m_nSlotIndex;                                       // +0x28
    int m_nSkillId;                                         // +0x2c
};
MS2_CHECK_SIZE(CGuideConditionExistShortcut, 0x30);

// 0x28. Passes while the ugc market has money to collect.
class CGuideConditionUgcCollectMoney : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413aaed0
    CGuideConditionUgcCollectMoney();
    virtual CStringW vfunc_1();                             // 1 0x1413aaf30
    virtual int vfunc_3();                                  // 3 0x1413aaf80
};
MS2_CHECK_SIZE(CGuideConditionUgcCollectMoney, 0x28);

// 0x28. Passes while the party dialog allows the observe mode.
class CGuideConditionCanObserveMode : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413aafc0
    CGuideConditionCanObserveMode();
    virtual CStringW vfunc_1();                             // 1 0x1413ab020
    virtual int vfunc_3();                                  // 3 0x1413ab070
};
MS2_CHECK_SIZE(CGuideConditionCanObserveMode, 0x28);

// 0x28. Passes while the player level is at least m_n20.
class CGuideConditionMyPlayerLevel : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ab0e0
    CGuideConditionMyPlayerLevel();
    virtual CStringW vfunc_1();                             // 1 0x1413ab140
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413ab190: kind 4
    virtual int vfunc_3();                                  // 3 0x1413ab1d0
    virtual int vfunc_8();                                  // 8 0x1413ab240: 0
};
MS2_CHECK_SIZE(CGuideConditionMyPlayerLevel, 0x28);

// 0x28. Passes while the player holds at least m_n20 money.
class CGuideConditionMoney : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ab250
    CGuideConditionMoney();
    virtual CStringW vfunc_1();                             // 1 0x1413ab2b0
    virtual int vfunc_3();                                  // 3 0x1413ab300
};
MS2_CHECK_SIZE(CGuideConditionMoney, 0x28);

// 0x40. Passes while the home holds the cube m_nItemId (0 = any) and its count lies within [m_min, m_max].
class CGuideConditionPlaceUgcCube : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ab350
    CGuideConditionPlaceUgcCube();
    virtual CStringW vfunc_1();                             // 1 0x1413ab3b0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413ab400: itemId / minCount / maxCount
    virtual int vfunc_3();                                  // 3 0x1413ab490
    virtual CStringW vfunc_7();                             // 7 0x1413ab5b0

    int m_nItemId;                                          // +0x28
    Unk_GcOptInt m_min;                                     // +0x2c
    Unk_GcOptInt m_max;                                     // +0x34
};
MS2_CHECK_SIZE(CGuideConditionPlaceUgcCube, 0x40);

// 0x40. Passes while a cube stands at m_pos in the home (and its attachable state is m_attachable).
class CGuideConditionPlaceUgcCubeItem : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ab750
    CGuideConditionPlaceUgcCubeItem();
    virtual CStringW vfunc_1();                             // 1 0x1413ab7b0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413ab800: pos / isAttachable
    virtual int vfunc_3();                                  // 3 0x1413ab870
    virtual CStringW vfunc_7();                             // 7 0x1413ab9e0

    Unk_GcOptVec3 m_pos;                                    // +0x28
    Unk_GcOptBool m_attachable;                             // +0x38
};
MS2_CHECK_SIZE(CGuideConditionPlaceUgcCubeItem, 0x40);

// 0x30. Passes while the home holds a cube of the icon type m_nIconType.
class CGuideConditionPlaceUgcCubeByIconType : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413abb80
    CGuideConditionPlaceUgcCubeByIconType();
    virtual CStringW vfunc_1();                             // 1 0x1413abbe0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413abc30: iconType
    virtual int vfunc_3();                                  // 3 0x1413abc90
    virtual CStringW vfunc_7();                             // 7 0x1413abce0

    int m_nIconType;                                        // +0x28
};
MS2_CHECK_SIZE(CGuideConditionPlaceUgcCubeByIconType, 0x30);

// 0x38. Passes while the interact object m_nInteractId is within m_fDistance of the player and in the state m_nState.
class CGuideConditionInteractObject : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413abd90
    CGuideConditionInteractObject();
    virtual CStringW vfunc_1();                             // 1 0x1413abdf0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413abe40: interactId / distance / state
    virtual int vfunc_3();                                  // 3 0x1413abec0
    virtual CStringW vfunc_7();                             // 7 0x1413ac050

    int m_nInteractId;                                      // +0x28
    float m_fDistance;                                      // +0x2c
    int m_nState;                                           // +0x30
};
MS2_CHECK_SIZE(CGuideConditionInteractObject, 0x38);

// 0x30. Passes while the last closed text tip (ui 0x4e53) is the entity m_nEntityId.
class CGuideConditionLastClosedTextTip : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ac120
    CGuideConditionLastClosedTextTip();
    virtual CStringW vfunc_1();                             // 1 0x1413ac180
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413ac1d0: entityId (throws on 0)
    virtual int vfunc_3();                                  // 3 0x1413ac290
    virtual CStringW vfunc_7();                             // 7 0x1413ac2f0

    int m_nEntityId;                                        // +0x28
};
MS2_CHECK_SIZE(CGuideConditionLastClosedTextTip, 0x30);

// 0x30. Always passes (the slot flags only describe which cube slot is meant).
class CGuideConditionConstructSlot : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ac3a0
    CGuideConditionConstructSlot();
    virtual CStringW vfunc_1();                             // 1 0x1413ac400
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413ac450: slotIdx / isIndoor / isOutdoor
    virtual int vfunc_3();                                  // 3 0x1413ac4f0: 1
    virtual void vfunc_5();                                 // 5 0x1413ac510
    virtual CStringW vfunc_7();                             // 7 0x1413ac520

    int m_nSlotIdx;                                         // +0x28
    bool m_bIndoor;                                         // +0x2c
    bool m_bOutdoor;                                        // +0x2d
};
MS2_CHECK_SIZE(CGuideConditionConstructSlot, 0x30);

// 0x28. Passes while the player owns a title.
class CGuideConditionTitle : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ac5f0
    CGuideConditionTitle();
    virtual CStringW vfunc_1();                             // 1 0x1413ac650
    virtual int vfunc_3();                                  // 3 0x1413ac6a0
    virtual void vfunc_5();                                 // 5 0x1413ac700: logs the title count
};
MS2_CHECK_SIZE(CGuideConditionTitle, 0x28);

// 0x38. Passes once the server time has reached m_time.
class CGuideConditionServerTime : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ac790
    CGuideConditionServerTime();
    virtual CStringW vfunc_1();                             // 1 0x1413ac7f0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413ac840: dateTime
    virtual int vfunc_3();                                  // 3 0x1413ac890
    virtual void vfunc_5();                                 // 5 0x1413ac8e0: logs the times
    virtual CStringW vfunc_7();                             // 7 0x1413acbe0

    Unk_GcTime m_time;                                      // +0x28
};
MS2_CHECK_SIZE(CGuideConditionServerTime, 0x38);

// 0x28. Passes while the player has learned a manufacture recipe.
class CGuideConditionHasManufacture : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413acd60
    CGuideConditionHasManufacture();
    virtual CStringW vfunc_1();                             // 1 0x1413acdc0
    virtual int vfunc_3();                                  // 3 0x1413ace10
};
MS2_CHECK_SIZE(CGuideConditionHasManufacture, 0x28);

// 0x30. Passes while the player holds more money of the type m_nMoneyType (0 meso, 1 merat, 2 karma, 3 honor, 4 lu, ...) than
// the XML "value".
class CGuideConditionHasMoney : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ace40
    CGuideConditionHasMoney();
    virtual CStringW vfunc_1();                             // 1 0x1413acea0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413acef0: moneyType
    virtual int vfunc_3();                                  // 3 0x1413ad020
    virtual CStringW vfunc_7();                             // 7 0x1413ad250

    int m_nMoneyType;                                       // +0x28
    int m_pad_2c;
};
MS2_CHECK_SIZE(CGuideConditionHasMoney, 0x30);

// ---- ctor-only subclasses (the methods are recovered with their own parts of unit_1413a9df0) ---------------------------

// 0x28.
class CGuideConditionBattleState : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413adb00
    CGuideConditionBattleState();// 0x1413b2a10
    virtual CStringW vfunc_1();                             // 1 0x1413adb60
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413adbb0
    virtual int vfunc_3();                                  // 3 0x1413adbf0
    virtual int vfunc_8();                                  // 8 0x1413adc50
};
MS2_CHECK_SIZE(CGuideConditionBattleState, 0x28);

// 0x28.
class CGuideConditionCubeHolderSelectItem : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ae730
    CGuideConditionCubeHolderSelectItem();// 0x1413b2b90
    virtual CStringW vfunc_1();                             // 1 0x1413ae790
    virtual int vfunc_3();                                  // 3 0x1413ae7e0
};
MS2_CHECK_SIZE(CGuideConditionCubeHolderSelectItem, 0x28);

// 0x28.
class CGuideConditionFalse : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a58e0
    CGuideConditionFalse();// 0x1413b2cc0
    virtual CStringW vfunc_1();                             // 1 0x1413a5940
    virtual int vfunc_3();                                  // 3 0x1413a5990
};
MS2_CHECK_SIZE(CGuideConditionFalse, 0x28);

// 0x28.
class CGuideConditionGuildPvpPeriod : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ad3b0
    CGuideConditionGuildPvpPeriod();// 0x1413b2db0
    virtual CStringW vfunc_1();                             // 1 0x1413ad410
    virtual int vfunc_3();                                  // 3 0x1413ad460
};
MS2_CHECK_SIZE(CGuideConditionGuildPvpPeriod, 0x28);

// 0x28.
class CGuideConditionHasStatPoint : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ae840
    CGuideConditionHasStatPoint();// 0x1413b2e40
    virtual CStringW vfunc_1();                             // 1 0x1413ae8a0
    virtual int vfunc_3();                                  // 3 0x1413ae8f0
};
MS2_CHECK_SIZE(CGuideConditionHasStatPoint, 0x28);

// 0x28.
class CGuideConditionJobCode : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ad7e0
    CGuideConditionJobCode();// 0x1413b2f30
    virtual CStringW vfunc_1();                             // 1 0x1413ad840
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413ad890
    virtual int vfunc_3();                                  // 3 0x1413ad8d0
    virtual int vfunc_8();                                  // 8 0x1413ad940
};
MS2_CHECK_SIZE(CGuideConditionJobCode, 0x28);

// 0x28.
class CGuideConditionJoinGuild : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413add70
    CGuideConditionJoinGuild();// 0x1413b2f60
    virtual CStringW vfunc_1();                             // 1 0x1413addd0
    virtual int vfunc_3();                                  // 3 0x1413ade20
};
MS2_CHECK_SIZE(CGuideConditionJoinGuild, 0x28);

// 0x28.
class CGuideConditionMasteryMainTabIndex : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ae1d0
    CGuideConditionMasteryMainTabIndex();// 0x1413b2fc0
    virtual CStringW vfunc_1();                             // 1 0x1413ae230
    virtual int vfunc_3();                                  // 3 0x1413ae280
};
MS2_CHECK_SIZE(CGuideConditionMasteryMainTabIndex, 0x28);

// 0x28.
class CGuideConditionMasterySubTabIndex : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ae2e0
    CGuideConditionMasterySubTabIndex();// 0x1413b2ff0
    virtual CStringW vfunc_1();                             // 1 0x1413ae340
    virtual int vfunc_3();                                  // 3 0x1413ae390
};
MS2_CHECK_SIZE(CGuideConditionMasterySubTabIndex, 0x28);

// 0x30.
class CGuideConditionMentoringPage : public CGuideCondition
{
public:
    CGuideConditionMentoringPage();// 0x1413b3020
    virtual CStringW vfunc_1();                             // 1 0x1413ae9f0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413aea40
    virtual int vfunc_3();                                  // 3 0x1413aea80
    virtual CStringW vfunc_7();                             // 7 0x1413aebb0

    CStringA m_strPageName;                                 // +0x28
};
MS2_CHECK_SIZE(CGuideConditionMentoringPage, 0x30);

// 0x30.
class CGuideConditionMenuExpand : public CGuideCondition
{
public:
    CGuideConditionMenuExpand();// 0x1413b3060
    virtual CStringW vfunc_1();                             // 1 0x1413adeb0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413adf00
    virtual int vfunc_3();                                  // 3 0x1413adf50
    virtual CStringW vfunc_7();                             // 7 0x1413adfd0

    CStringA m_strMenuName;                                 // +0x28
};
MS2_CHECK_SIZE(CGuideConditionMenuExpand, 0x30);

// 0x28.
class CGuideConditionPlayingInstrument : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ae600
    CGuideConditionPlayingInstrument();// 0x1413b3250
    virtual CStringW vfunc_1();                             // 1 0x1413ae660
    virtual int vfunc_3();                                  // 3 0x1413ae6b0
};
MS2_CHECK_SIZE(CGuideConditionPlayingInstrument, 0x28);

// 0x28.
class CGuideConditionPlayInstrumentHasSelectItem : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ae500
    CGuideConditionPlayInstrumentHasSelectItem();// 0x1413b31f0
    virtual CStringW vfunc_1();                             // 1 0x1413ae560
    virtual int vfunc_3();                                  // 3 0x1413ae5b0
};
MS2_CHECK_SIZE(CGuideConditionPlayInstrumentHasSelectItem, 0x28);

// 0x28.
class CGuideConditionPlayInstrumentTabIndex : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ae3f0
    CGuideConditionPlayInstrumentTabIndex();// 0x1413b3220
    virtual CStringW vfunc_1();                             // 1 0x1413ae450
    virtual int vfunc_3();                                  // 3 0x1413ae4a0
};
MS2_CHECK_SIZE(CGuideConditionPlayInstrumentTabIndex, 0x28);

// 0x28.
class CGuideConditionRealEstateExpireDays : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ad4c0
    CGuideConditionRealEstateExpireDays();// 0x1413b3340
    virtual CStringW vfunc_1();                             // 1 0x1413ad520
    virtual int vfunc_3();                                  // 3 0x1413ad570
};
MS2_CHECK_SIZE(CGuideConditionRealEstateExpireDays, 0x28);

// 0x28.
class CGuideConditionSelectItemEnchant : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ae0c0
    CGuideConditionSelectItemEnchant();// 0x1413b33a0
    virtual CStringW vfunc_1();                             // 1 0x1413ae120
    virtual int vfunc_3();                                  // 3 0x1413ae170
};
MS2_CHECK_SIZE(CGuideConditionSelectItemEnchant, 0x28);

// 0x48.
class CGuideConditionSubJobCode : public CGuideCondition
{
public:
    CGuideConditionSubJobCode();// 0x1413b3450
    virtual CStringW vfunc_1();                             // 1 0x1413ad9b0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413ada00
    virtual int vfunc_3();                                  // 3 0x1413ada50

    CAtlArray<int> m_subJobCodes;                           // +0x28
};
MS2_CHECK_SIZE(CGuideConditionSubJobCode, 0x48);

// 0x28.
class CGuideConditionSummonPet : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413adc60
    CGuideConditionSummonPet();// 0x1413b3490
    virtual CStringW vfunc_1();                             // 1 0x1413adcc0
    virtual int vfunc_3();                                  // 3 0x1413add10
};
MS2_CHECK_SIZE(CGuideConditionSummonPet, 0x28);

// 0x28.
class CGuideConditionUgcProductExpireDays : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413ad660
    CGuideConditionUgcProductExpireDays();// 0x1413b3550
    virtual CStringW vfunc_1();                             // 1 0x1413ad6c0
    virtual int vfunc_3();                                  // 3 0x1413ad710
};
MS2_CHECK_SIZE(CGuideConditionUgcProductExpireDays, 0x28);

// ---- classes whose constructor is inline in the method range of unit_1413a9df0#2 --------------------------------------------

// 0x50. Passes when the last button of the path m_children inside the dialog m_strDialog is selected.
class CGuideConditionButtonSelected : public CGuideCondition
{
public:
    CGuideConditionButtonSelected();                        // 0x1413aed50
    virtual CStringW vfunc_1();                             // 1 0x1413aed00
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413af0c0: dialogName / childName (rejects "not")
    virtual int vfunc_3();                                  // 3 0x1413aedb0
    virtual CStringW vfunc_7();                             // 7 0x1413af190

    CStringA m_strDialog;                                   // +0x28
    CAtlArray<CString> m_children;                          // +0x30
};
MS2_CHECK_SIZE(CGuideConditionButtonSelected, 0x50);

// 0x40. Passes while a contract button (dialog id or name, child path) is on screen and the server time is within 7 days of the expiry.
class CGuideConditionContract : public CGuideCondition
{
public:
    CGuideConditionContract();                              // 0x1413af330
    virtual CStringW vfunc_1();                             // 1 0x1413af2e0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413af560: dialogID / childName / dialogName
    virtual int vfunc_3();                                  // 3 0x1413af3b0
    virtual CStringW vfunc_7();                             // 7 0x1413af5e0

    unsigned m_nDialogId;                                   // +0x28
    int m_pad_2c;
    CStringA m_strChild;                                    // +0x30
    CStringA m_strDialog;                                   // +0x38
};
MS2_CHECK_SIZE(CGuideConditionContract, 0x40);

// 0x30. Passes while the home mode equals m_nMode.
class CGuideConditionHomeMode : public CGuideCondition
{
public:
    CGuideConditionHomeMode();                              // 0x1413af7f0
    virtual CStringW vfunc_1();                             // 1 0x1413af7a0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413af880
    virtual int vfunc_3();                                  // 3 0x1413af830
    virtual CStringW vfunc_7();                             // 7 0x1413af8d0

    int m_nMode;                                            // +0x28
    int m_pad_2c;
};
MS2_CHECK_SIZE(CGuideConditionHomeMode, 0x30);

// 0x28. Passes when the entered dungeon (value) is in the state 0 or 1.
class CGuideConditionEnterDungeon : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413af980
    CGuideConditionEnterDungeon();                          // 0x1413afa30
    virtual CStringW vfunc_1();                             // 1 0x1413af9e0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413afa70
    virtual int vfunc_3();                                  // 3 0x1413afab0
    virtual int vfunc_8();                                  // 8 0x1413afb10
};
MS2_CHECK_SIZE(CGuideConditionEnterDungeon, 0x28);

// 0x28. Passes when the chat emoticon dialog is open.
class CGuideConditionChatEmoticon : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413afb20
    CGuideConditionChatEmoticon();                          // 0x1413afbd0
    virtual CStringW vfunc_1();                             // 1 0x1413afb80
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413afc10
    virtual int vfunc_3();                                  // 3 0x1413afc50
    virtual int vfunc_8();                                  // 8 0x1413afca0
};
MS2_CHECK_SIZE(CGuideConditionChatEmoticon, 0x28);

// 0x48. Fires once its trigger condition holds (ctor and methods are in the guide entity unit at 0x1413a5a00).
class CGuideConditionTrigger : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a59a0
    CGuideConditionTrigger();                               // 0x1413a5a50
    virtual CStringW vfunc_1();                             // 1 0x1413a5a00
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a5ad0
    virtual int vfunc_3();                                  // 3 0x1413a5bb0
    virtual CStringW vfunc_7();                             // 7 0x1413a5c80

    int m_n28;                                              // +0x28
    Unk_GcOptInt m_a;                                       // +0x2c
    Unk_GcOptInt m_b;                                       // +0x34
    int m_n3c;                                              // +0x3c
    int m_n40;                                              // +0x40
    int m_pad_44;
};
MS2_CHECK_SIZE(CGuideConditionTrigger, 0x48);

// 0x30. Passes after m_n28 has elapsed (ctor and methods are in the guide entity unit at 0x1413a5ef0).
class CGuideConditionTimeout : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a5e90
    CGuideConditionTimeout();                               // 0x1413a5f40
    virtual CStringW vfunc_1();                             // 1 0x1413a5ef0
    virtual int vfunc_3();                                  // 3 0x1413a5f80
    virtual void vfunc_4();                                 // 4 0x1413a5fe0

    int m_n28;                                              // +0x28
    int m_pad_2c;
};
MS2_CHECK_SIZE(CGuideConditionTimeout, 0x30);

// ---- StringFormat instances of the guide-condition TU (defined in unit_1413a9df0#6) ------------------------------------------
// The enum arguments take the formatter's custom-argument path (fmt::internal::MakeValue<enum> + format_arg<enum>); the
// conditions keep them in int members, so the wrappers reinterpret the member reference.
enum Unk_GcEnum1 : int {};          // formatted by 0x1413b13d0 (no caller in this TU)
enum Unk_GcModeId : int {};         // CGuideConditionHomeMode::m_nMode
enum Unk_GcAchieveType : int {};    // the trophy achievement type
enum Unk_GcIconType : int {};       // cube / item icon type
enum Unk_GcItemType : int {};       // inventory item type
template <class E> inline const E& GcEnum(const int& n) { return reinterpret_cast<const E&>(n); }
#define GC_ENUM(E, n) reinterpret_cast<const E&>(n)
// Out-of-line copies (explicit instantiations in unit_1413a9df0#6).
extern template CStringW StringFormat<Unk_GcEnum1>(const wchar_t*, const Unk_GcEnum1&);
extern template CStringW StringFormat<int, unsigned, unsigned>(const wchar_t*, const int&, const unsigned&, const unsigned&);
extern template CStringW StringFormat<int, float, int>(const wchar_t*, const int&, const float&, const int&);
extern template CStringW StringFormat<int, bool, bool>(const wchar_t*, const int&, const bool&, const bool&);
extern template CStringW StringFormat<Unk_GcModeId>(const wchar_t*, const Unk_GcModeId&);
extern template CStringW StringFormat<Unk_GcAchieveType>(const wchar_t*, const Unk_GcAchieveType&);
extern template CStringW StringFormat<Unk_GcItemType>(const wchar_t*, const Unk_GcItemType&);
extern template CStringW StringFormat<unsigned, Unk_GcItemType, Unk_GcIconType>(const wchar_t*, const unsigned&, const Unk_GcItemType&, const Unk_GcIconType&);
extern template CStringW StringFormat<Unk_GcItemType, int, int>(const wchar_t*, const Unk_GcItemType&, const int&, const int&);
