// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uibossrewardpreviewdialog.h (name assumed
// from the unit path: the .cpp's __FILE__ string is not in the exe for this unit).
//
// UIBossRewardPreviewDialog ("BossRewardPreviewDialog", UI type id 0x4efb, RTTI .?AVUIBossRewardPreviewDialog@@, 0x1c8
// bytes): the reward list of a boss npc on the world map search. FUN_140f25ad0 picks the npc (kind 4 / 6 with a reward
// row), FUN_140f25bf0 fills the title ("m_title") and builds the item bag (SlotBag, 0x12 slots named after the dialog),
// the exp / meso rows are bound in OnLoadComplete. Slot (0xa0, id 0x620006d) shows one item, SlotBag (0xb0, id 0x620006e)
// builds the reward items of the npc (the "rewardId" bag name goes to the movie).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are invented.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class ASMovieClip;
class ASTextField;
class CItem;

class UIBossRewardPreviewDialog : public UIDialog
{
public:
    // 0xa0 bytes. vftable (26 slots, ??_G 0x140f26530 sized delete 0xa0), ITooltip @+0x78. Shows one item (m_spItem).
    class Slot : public MS2DragSlot
    {
    public:
        Slot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem);     // 0x140f24e40
        virtual ~Slot();                                // 0x140f26450

        // slots 2-4: GetClassDesc 0x140f26630, TypeCast 0x140f26730 / 0x140f26780; ms_ClassInfo 0x143ac9880,
        // SetupClassInfo 0x140f26670 (parent MS2DragSlot, id 0x620006d).
        EE_DECLARE_CLASS1(Slot, 0x0620006D, MS2DragSlot);
    public:
        virtual int vfunc_8(void* p);                   // 8  0x140f24fd0 build the item slot into p
        virtual int vfunc_0(void* p);                   // ITooltip 0x140f24ed0 build the tooltip into p

        MS2_LAYOUT_FRIEND;
        MS2Ptr<CItem> m_spItem;                         // +0x90
    };

    // 0xb0 bytes. vftable (16 slots, ??_G 0x140f26590 sized delete 0xb0).
    class SlotBag : public DragSlotBag
    {
    public:
        SlotBag(const CString& strName, int nNpcId);    // 0x140f251c0
        virtual ~SlotBag();                             // 0x140f26480

        // slots 2-4: GetClassDesc 0x140f26640, TypeCast 0x140f267d0 / 0x140f26820; ms_ClassInfo 0x143ac9c90,
        // SetupClassInfo 0x140f266d0 (parent DragSlotBag, id 0x620006e).
        EE_DECLARE_CLASS1(SlotBag, 0x0620006E, DragSlotBag);
    public:
        virtual DragSlot* vfunc_16(int nIndex);         // 16 0x140f25240 new Slot holding the item at nIndex

        void FUN_140f25400();                           // fill m_items with the reward items of the npc

        MS2_LAYOUT_FRIEND;
        int m_nNpcId;                                   // +0x88
        int m_pad_8c;
        ATL::CAtlArray<MS2Ptr<CItem> > m_items;         // +0x90 the reward items
    };

    UIBossRewardPreviewDialog();                                    // 0x140f255e0
    virtual ~UIBossRewardPreviewDialog();                           //  0 0x140f264b0 (??_G 0x140f265f0)
    virtual CString GetTypeName();                                      //  1 0x140f256b0 "BossRewardPreviewDialog"
    virtual void OnLoadComplete();                                  // 22 0x140f257a0 bind the title / exp / meso rows
    virtual int vfunc_48() { return 0x4efb; }                       // 48 0x140f26660
    virtual void vfunc_67();                                        // 67 0x140f25700 close: drop the bag

    int FUN_140f25ad0(int nNpcId);                                  // 0x140f25ad0 show the npc's rewards; 1 = it has some
    void FUN_140f25bf0();                                           // 0x140f25bf0 refresh the title and the bag
    template <class T> MS2Ptr<T> FUN_140e48d80(const CString& strName, MS2Ptr<T>& out);   // 0x140e48d80 bind a child

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASTextField> m_spExp;                                    // +0x178 "m_exp"
    MS2Ptr<ASTextField> m_spMeso;                                   // +0x188 "m_meso"
    MS2Ptr<ASTextField> m_spTitle;                                  // +0x198 "m_title"
    MS2Ptr<ASMovieClip> m_spMesoIcon;                               // +0x1a8 "m_mesoIcon"
    int m_nNpcId;                                                   // +0x1b8 the shown npc
    int m_pad_1bc;
    CString m_strBag;                                               // +0x1c0 name of the bag control (the class name)
};
MS2_CHECK_SIZE(UIBossRewardPreviewDialog, 0x1c8);
MS2_CHECK_SIZE(UIBossRewardPreviewDialog::Slot, 0xa0);
MS2_CHECK_SIZE(UIBossRewardPreviewDialog::SlotBag, 0xb0);
