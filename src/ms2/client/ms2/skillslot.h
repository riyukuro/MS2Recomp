// skillslot.h - SkillSlot / SkillSlotBag: the skill (and item skill) slots of the quick slot bars and the skill window.
// The slot holds the skill id, or an item id + uid for an item shortcut, and a table of the key bindings of its slot
// index. The bag builds one slot per index of the saved quick slot entries. Owning unit: ?\skillslot.cpp
// (0x14175c840-0x14176f2a0, .text$di 0x140100bf0-0x140101560). Header name assumed from the unit path; member names are
// invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/commonfiles/skilloverlapcompare.h"

class CItem;

// the value traits of the key table take the value by reference (the exe's SetAt/RBInsert pass a pointer)
struct Unk_SkillSlotValueTraits : ATL::CElementTraits<int> { typedef const int& INARGTYPE; };

// 0x150 bytes. vftable (26 slots, ??_G 0x141762550 sized delete 0x150), ITooltip @+0x78.
class SkillSlot : public MS2DragSlot
{
public:
    SkillSlot(const CString& strName, int nIndex, int nSkillId, int nItemId, __int64 nItemUid);   // 0x14175c840
    virtual ~SkillSlot();                               // 0x1417623e0

    // slots 2-4: GetClassDesc 0x141762740, TypeCast 0x141763350 / 0x1417633a0; ms_ClassInfo 0x143ae97f0,
    // SetupClassInfo 0x1417632f0 (parent MS2DragSlot, id 0x6200025).
    EE_DECLARE_CLASS1(SkillSlot, 0x06200025, MS2DragSlot);
public:
    virtual void vfunc_6(void* p);                      // 6  0x14175ca40 push the key, index and count into the tooltip list
    virtual int vfunc_8(void* p);                       // 8  0x14175e9e0 build the slot into p
    virtual void vfunc_9();                             // 9  0x14175dec0 bind the slot's AS functions
    virtual int vfunc_11();                             // 11 0x14175d3f0 clear the slot
    virtual int vfunc_13();                             // 13 0x14175cdd0 use the slot (left click)
    virtual int vfunc_14();                             // 14 0x14175d260
    virtual int vfunc_17();                             // 17 0x14175d2b0 drop the dragged slot here
    virtual int vfunc_18(void* p);                      // 18 0x14175d530 a slot was dropped on it
    virtual int vfunc_20();                             // 20 0x14175ddc0 button down
    virtual int vfunc_21();                             // 21 0x14175de40 button up
    virtual CStringW vfunc_22();                   // 22 0x14175f080 tooltip text of the string table entry 0x759
    virtual void vfunc_23(void* p);                     // 23 0x14175f0c0 start the icon tween
    virtual void vfunc_24(void* p);                     // 24 0x14175f180 stop the icon tween
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x14175fbf0 the item of the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x14175e3c0 build the tooltip into p

    int GetSkillId();                                // the skill id
    void SetSkillId(int nSkillId);
    __int64 GetItemUid();                            // the item uid
    void SetItemUid(__int64 nItemUid);
    int GetItemId();                                // the item id
    void SetItemId(int nItemId);
    int FUN_14175cc60();                                // 0
    void FUN_14175cc70();                               // refresh the key bindings of the three keys
    int IsFixed();                                // the slot is fixed
    void SetFixed(int bFixed);
    void FUN_14175e310(int nFlags);                     // a slot of the bag: refresh the cooldown
    void FUN_14175e350(int nFlags);
    void FUN_14175f200();                               // stop the icon tween
    void FUN_14175f280(unsigned nFlags);                // refresh the state, the count and the recharge
    void FUN_14175f510();                               // refresh the state and the icon
    CStringW FUN_14175fe60();                           // the text of the key binding
    bool FUN_141760190();                               // the item is a skill scroll
    unsigned FUN_141760220(int n);                      // the item count
    int FUN_1417603f0();                                // the recharge count left
    int FUN_1417604f0();                                // the recharge max count
    int FUN_141760590();                                // the item's data field a
    int FUN_141760610();                                // the item's data field b
    CString FUN_141760690();                            // the icon path
    CString FUN_1417607f0(int* pSkillId);               // the icon path of a skill
    CStringW FUN_141760920();                           // the shortcut key text (wide, see the .cpp)
    int FUN_141760980(int nMode);                       // the key code bound to the slot
    __int64 FUN_141760a10();                            // the bind key of the slot index
    float FUN_141760a30();                              // the cooldown total
    float FUN_141760b90();                              // the cooldown left
    int FUN_141760c00();                                // the slot is disabled
    int FUN_141761530(MS2Ptr<SkillData>* pOut);                      // the replacing skill (combo / change)
    bool FUN_141761900();
    int FUN_141761990();                                // the slot is fixed or bound
    int FUN_1417619d0();                                // the slot index has a key binding
    int FUN_141761a10();                                // the skill (or item) is in the active set
    CStringW FUN_141761c30();                           // the name of the key binding
    int FUN_141761d90();                                // the effective skill id

public:
    MS2_LAYOUT_FRIEND;
    int m_nDisabled;                                    // +0x90
    int m_nItemCount;                                   // +0x94
    int m_nRecharge;                                    // +0x98
    bool m_bUsable;                                     // +0x9c
    bool m_bCooling;                                    // +0x9d
    CString m_strIcon;                                  // +0xa0
    int m_nSkillId;                                     // +0xa8
    __int64 m_nItemUid;                                 // +0xb0
    int m_nItemId;                                      // +0xb8
    int m_bFixed;                                       // +0xbc
    ATL::CRBMap<unsigned, int, ATL::CElementTraits<unsigned>, Unk_SkillSlotValueTraits> m_kKeys;                      // +0xc0 slot index -> key code
    MS2Ptr<AScript> m_spRoot;                           // +0xf0
    MS2Ptr<AScript> m_spUpdate;                         // +0x100
    MS2Ptr<AScript> m_spClear;                          // +0x110
    MS2Ptr<AScript> m_spSet;                            // +0x120
    MS2Ptr<AScript> m_spRecharge;                       // +0x130
    MS2Ptr<AScript> m_spTween;                          // +0x140
};
MS2_CHECK_SIZE(SkillSlot, 0x150);
MS2_CHECK_OFFSET(SkillSlot, m_nSkillId, 0xa8);
MS2_CHECK_OFFSET(SkillSlot, m_kKeys, 0xc0);
MS2_CHECK_OFFSET(SkillSlot, m_spTween, 0x140);

// 0x90 bytes. vftable (16 slots, ??_G 0x141763d10 sized delete 0x90), UIUGCEventListener @+0x88 (vfunc_o88).
class SkillSlotBag : public DragSlotBag, public UIUGCEventListener
{
public:
    explicit SkillSlotBag(const CString& strName);      // 0x1417634f0
    virtual ~SkillSlotBag();                            // 0x1417635a0

    // slots 2-4: GetClassDesc 0x141763d70, TypeCast 0x141763de0 / 0x141763e30; ms_ClassInfo 0x143ae9d10,
    // SetupClassInfo 0x141763d80 (parent DragSlotBag, id 0x620002a).
    EE_DECLARE_CLASS1(SkillSlotBag, 0x0620002A, DragSlotBag);
public:
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x1417639b0 new SkillSlot for the quick slot entry at nIndex
    virtual void vfunc_ugc_2(void* pUid, CString str);  // UGC slot 2 0x1417638f0 use the slot of an item uid

    void FUN_141763640(int nFlags);                     // refresh every slot
    SkillSlot* FUN_141763710(int nItemId);              // the slot of an item id
    SkillSlot* FUN_141763800(__int64 nItemUid);         // the slot of an item uid
    void FUN_141763b00(int nFlags);                     // refresh the cooldown of every slot
    void FUN_141763bd0(int nSkillId, int nFlags);       // refresh the cooldown of the slots of a skill
};
MS2_CHECK_SIZE(SkillSlotBag, 0x90);
