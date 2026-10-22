// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiselectitemboxdialog.h (name assumed:
// the exe has no __FILE__ string for this unit).
//
// UISelectItemBoxDialog ("SelectItemBoxDialog", UI type 0x4eff, RTTI .?AVUISelectItemBoxDialog@@, 0x278 bytes): the
// window that opens a "select box" item: the player ticks up to m_nSelectCount of the box's reward items and confirms
// ("select_item_box_function" with the chosen indices, comma separated). The rewards come from the drop table
// (individualDropBoxId of the item) and are bound to item slots through two ItemSlotBinders.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/itemslotbinder.h"

// ---- the movie's controls (unit-local placeholders; the wrapper classes are unrecovered) ----
// A button of the movie.
class Unk_SibButton : public AScript
{
public:
    void FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, int n);   // click handler
    void FUN_1422cdfb0(const CStringW& strLabel);
    void FUN_1422c1fe0(bool bEnable);
};

// The list of selectable items.
class Unk_SibList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50(const Scaleform::GFx::Value& data);           // slot 25 of the vftable (+0xc8): set the data provider
    void FUN_1422cfa30(ATL::CAtlArray<unsigned>& out);                  // the selected indices
    unsigned FUN_1422cf920();                                           // the selection count
    void FUN_1422de0e0(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, int n);   // change handler
    Scaleform::GFx::Value FUN_140e262c0(const char* szMethod, const wchar_t* sz);
};

// A slot / text of the movie.
class Unk_SibSlot : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(bool bVisible);
};
class Unk_SibText : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(bool bVisible);
    void FUN_1422c4cd0(const CStringW& strText);
};


// The polymorphic reward entries of a drop table and their vector (ctor 0x1405a1910, dtor 0x1405a1a40; shared with
// UIItemPetBoxDialog's unit-local copy of this declaration).
class Unk_PetBoxDrop
{
public:
    virtual unsigned vfunc_0();
    virtual int vfunc_1();
    virtual unsigned vfunc_2();
};
class Unk_PetBoxDropVec
{
public:
    Unk_PetBoxDropVec();                    // 0x1405a1910
    ~Unk_PetBoxDropVec();                   // 0x1405a1a40
    size_t FUN_140314170();
    Unk_PetBoxDrop* FUN_140c461b0(size_t);
    void FUN_140313cd0(Unk_PetBoxDrop*);
    void FUN_140f9b7d0();                   // clear (this unit's copy of the glue)
    void* m_begin; void* m_end; void* m_cap;
};
MS2_CHECK_SIZE(Unk_PetBoxDropVec, 24);

class UISelectItemBoxDialog : public UIDialog
{
public:
    UISelectItemBoxDialog();                                            // 0x140f99280
    virtual ~UISelectItemBoxDialog();                                   //  0 0x140f99420 (??_G 0x140f9b740)
    virtual CString vfunc_1();                                          //  1 0x140f99500 "SelectItemBoxDialog"
    virtual void OnLoadComplete();                                      // 22 0x140f99550
    virtual void vfunc_26();                                            // 26 0x140f9a140 reset
    virtual int vfunc_48() { return 0x4eff; }                           // 48 0x140f9b780 UI type id

    void SetItemUid(unsigned __int64 uItemUid);                      // the box item to open
    void FUN_140f9a230(const Scaleform::GFx::FunctionHandler::Params& params);   // "m_okButton" clicked: send the choice
    void FUN_140f9a5f0(const Scaleform::GFx::FunctionHandler::Params& params);   // list selection changed
    void FUN_140f9a700();                                               // refresh the slots, counters and the ok label

    MS2Ptr<Unk_SibButton> FUN_140bc6d10(const CString& strName, MS2Ptr<Unk_SibButton>* pOut);   // bind children
    MS2Ptr<Unk_SibList> FUN_140e8d030(const CString& strName, MS2Ptr<Unk_SibList>* pOut);
    MS2Ptr<Unk_SibSlot> FUN_140c57ce0(const CString& strName, MS2Ptr<Unk_SibSlot>* pOut);
    MS2Ptr<Unk_SibText> FUN_140e48d80(const CString& strName, MS2Ptr<Unk_SibText>* pOut);

protected:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_uItemUid;                                        // +0x178
    MS2Ptr<Unk_SibButton> m_okButton;                                   // +0x180
    MS2Ptr<Unk_SibList> m_selectItemList;                               // +0x190
    std::vector<MS2Ptr<Unk_SibSlot> > m_selectedSlots;                  // +0x1a0 six "m_selectedSlot<n>"
    MS2Ptr<Unk_SibText> m_selectedCount;                                // +0x1b8
    MS2Ptr<Unk_SibText> m_selectNotice;                                 // +0x1c8
    Unk_PetBoxDropVec m_rewards;                                        // +0x1d8 the box's reward entries
    unsigned m_nSelectCount;                                            // +0x1f0 how many the player may take
    ItemSlotBinder m_binder;                                            // +0x1f8 "SelectItemBoxDialog"
    ItemSlotBinder m_binderSel;                                         // +0x238 "SelectItemBoxDialog_Sel"
};
MS2_CHECK_SIZE(UISelectItemBoxDialog, 0x278);
