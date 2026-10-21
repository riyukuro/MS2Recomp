// tabcontentspetinfo.h - the pet info tab of the pet system dialog: TabContentsPetInfo (RTTI .?AVTabContentsPetInfo@@, 0x60
// bytes, base PetSystemTabContents) and its five page parts PetInfoStat / PetInfoSkill / PetInfoBasic / PetInfoInventory /
// PetInfoPreview (base PetInfoBase, a CPtred holding the pet number and the part's AS clip). The nested EquipSlot /
// EquipSlotBag are the pet's equip slot (not the global equip window's EquipSlot of equipslot.h; do not include both).
// Owning unit: ?\tabcontentspetinfo.cpp (0x140cb87d0-0x140cbf600, .text$di 0x1400cfde0). Header name assumed from the unit
// path (the old index called it petinfobasic.cpp). The member names are invented; the FUN_ names are exe addresses.
#pragma once
#include <atlcoll.h>

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/petsystemtabcontents.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/client/ms2/uiskillpreviewdialog.h"      // IUIAvatarEventListener, Unk_SkillPreviewPtr

class UIAvatarPet;
class Unk_StatList;
class CMsgBoxData;

// One part of the page (stat / skill / basic / inventory / preview). The slot numbers follow the exe vftable 0x142e19748.
class PetInfoBase : public CPtred
{
public:
    PetInfoBase(int nPet);                              // 0x140cbe650 (inline)
    virtual ~PetInfoBase();                             //  0 0x140cbe740 (inline, ??_G 0x140cbea60)
    virtual void vfunc_1() {}                           //  1 0x140cbeff0
    virtual void vfunc_2() {}                           //  2 0x140cbf020 release what the part registered
    virtual void vfunc_3() {}                           //  3 0x140cbecb0 refresh the part
    virtual void vfunc_4() {}                           //  4 0x140cbeca0 rebuild the part
    virtual void vfunc_5(int nTab) {}                   //  5 0x140cbf060 react to the tab changing
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs) { return 0; }   // 6 0x140cbf000
    virtual void vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4);   // 7 0x140cbf030 (a2 by value, destroyed)

    int m_nPet;                                         // +0x18 0 = the own pet, else the other player's pet
    MS2Ptr<ASUIComponent> m_ui;                         // +0x20
};
MS2_CHECK_SIZE(PetInfoBase, 0x30);
MS2_CHECK_OFFSET(PetInfoBase, m_ui, 0x20);

class PetInfoStat : public PetInfoBase
{
public:
    PetInfoStat(int nPet);                              // 0x140cbb7d0
    virtual ~PetInfoStat();                           //  0 0x140cbe830 (inline, ??_G 0x140cbeba0)
    virtual void vfunc_3();                             //  3 0x140cbb810 option description of the pet item
    virtual void vfunc_5(int nTab);                     //  5 0x140cbba70
};
MS2_CHECK_SIZE(PetInfoStat, 0x30);

class PetInfoSkill : public PetInfoBase
{
public:
    PetInfoSkill(int nPet);                             // 0x140cbada0
    virtual ~PetInfoSkill();                          //  0 0x140cbe810 (inline, ??_G 0x140cbeb60)
    virtual void vfunc_3();                             //  3 0x140cbade0
    virtual void vfunc_5(int nTab);                     //  5 0x140cbafa0
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 6 0x140cbafe0

    void FUN_140cbb060(MS2Ptr<Unk_StatList> list);     // fill the scrolling list with the pet's skills
    void FUN_140cbb720();                               // open the auto use option dialog
    void FUN_140cbb750();                               // open the auto pick option dialog
};
MS2_CHECK_SIZE(PetInfoSkill, 0x30);

class PetInfoBasic : public PetInfoBase
{
public:
    PetInfoBasic(int nPet);                             // 0x140cb87d0
    virtual ~PetInfoBasic();                          //  0 0x140cbe780 (inline, ??_G 0x140cbeaa0)
    virtual void vfunc_2();                             //  2 0x140cb8850 release the item bag
    virtual void vfunc_3();                             //  3 0x140cb8880 name, exp bar, slot, grade
    virtual void vfunc_4();                             //  4 0x140cb9240 clear and register the equip bag
    virtual void vfunc_5(int nTab);                     //  5 0x140cb9790
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 6 0x140cb9870

    void FUN_140cb9900();                               // the rename button was clicked
    bool FUN_140cb9ba0(int nResult, const CMsgBoxData& box);   // the new name was entered
    bool FUN_140cba0f0(int nResult, const CMsgBoxData& box);   // the rename was confirmed: send it
    int FUN_140cba1f0();                                // the slot background frame (1 when the pet is not out)
    int FUN_140cba220();                                // the rename button frame

    CString m_strBag;                                   // +0x30 item bag registry name
};
MS2_CHECK_SIZE(PetInfoBasic, 0x38);

class PetInfoInventory : public PetInfoBase
{
public:
    PetInfoInventory(int nPet);                         // 0x140cba250
    virtual ~PetInfoInventory();                      //  0 0x140cbe7b0 (inline, ??_G 0x140cbeae0)
    virtual void vfunc_2();                             //  2 0x140cba2b0
    virtual void vfunc_3();                             //  3 0x140cba2e0
    virtual void vfunc_4();                             //  4 0x140cbaa00
    virtual void vfunc_5(int nTab);                     //  5 0x140cbabc0

    CString m_strBag;                                   // +0x30 item bag registry name
};
MS2_CHECK_SIZE(PetInfoInventory, 0x38);

class PetInfoPreview : public PetInfoBase, public IUIAvatarEventListener
{
public:
    PetInfoPreview(int nPet);                           // 0x140cbbab0
    virtual ~PetInfoPreview();                        //  0 0x140cbe7e0 (inline, ??_G 0x140cbeb20)
    virtual void vfunc_2();                             //  2 0x140cbbb30
    virtual void vfunc_3();                             //  3 0x140cbbb70 show the pet in the preview
    virtual void vfunc_4();                             //  4 0x140cbbe20
    virtual void vfunc_5(int nTab);                     //  5 0x140cbbf00
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 6 0x140cbbf70
    virtual void vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4);   // 7 0x140cbc010
    virtual int vfunc_o178_1(void* pAvatar);            // IUIAvatarEventListener slot 1, 0x140cbc2b0

    void FUN_140cbc2f0();                               // load the render target
    void FUN_140cbc3b0();                               // unload the render target

    MS2Ptr<UIAvatarPet> m_avatar;                                // +0x38
};
MS2_CHECK_SIZE(PetInfoPreview, 0x48);
MS2_CHECK_OFFSET(PetInfoPreview, m_avatar, 0x38);

class TabContentsPetInfo : public PetSystemTabContents
{
public:
    // The pet's equip slot (one worn pet item) and its bag.
    class EquipSlot : public MS2DragSlot
    {
    public:
        EquipSlot(const CString& strName, int nIndex, int nPet);   // 0x140cbc470
        virtual ~EquipSlot();                           //  0 0x140cbc4e0 (??_G 0x140cbe9a0)

        // slots 2-4: GetClassDesc 0x140cbeda0, TypeCast 0x140cbf250 / 0x140cbf2a0; ms_ClassInfo 0x143abfc70,
        // SetupClassInfo 0x140cbf190 (parent MS2DragSlot, id 0x6200075).
        EE_DECLARE_CLASS1(EquipSlot, 0x06200075, MS2DragSlot);
    public:
        virtual int vfunc_8(void* p);                   // 8  0x140cbc960 build the slot into p
        virtual int vfunc_13();                         // 13 0x140cbc520 open the item
        virtual int vfunc_14();                         // 14 0x140cbc5f0 open the item
        virtual int vfunc_18(void* p);                  // 18 0x140cbc6c0 something was dropped on the slot
        virtual MS2Ptr<CItem> vfunc_25();               // 25 0x140cbcab0 the pet item
        virtual int vfunc_0(void* p);                   // ITooltip 0x140cbc7d0 build the tooltip into p

        __int64 FUN_140cbcb00();                        // the pet item's uid, 0 when there is none

    public:
        MS2_LAYOUT_FRIEND;
        int m_nPet;                                     // +0x90
    };

    class EquipSlotBag : public DragSlotBag
    {
    public:
        EquipSlotBag(const CString& strName, int nPet);     // 0x140cbcca0
        virtual ~EquipSlotBag();                        //  0 0x140cbccf0 (??_G 0x140cbea00)

        // slots 2-4: GetClassDesc 0x140cbedb0, TypeCast 0x140cbf2f0 / 0x140cbf340; ms_ClassInfo 0x143ac0080,
        // SetupClassInfo 0x140cbf1f0 (parent DragSlotBag, id 0x6200076).
        EE_DECLARE_CLASS1(EquipSlotBag, 0x06200076, DragSlotBag);
    public:
        virtual CString vfunc_15(int nIndex);           // 15 0x140cbcd20 "<name>.EQUIP<index>"
        virtual DragSlot* vfunc_16(int nIndex);         // 16 0x140cbcde0 new EquipSlot

    public:
        MS2_LAYOUT_FRIEND;
        int m_nPet;                                     // +0x88
    };

    TabContentsPetInfo(int nPet);                       // 0x140cbcea0
    virtual ~TabContentsPetInfo();                      //  0 0x140cbe850 (inline, ??_G 0x140cbebe0)
    virtual void vfunc_1();                             //  1 0x140cbd1e0 close the parts, drop the UI
    virtual void vfunc_2(int nTab);                     //  2 0x140cbd390
    virtual void vfunc_3(MS2Ptr<ASUIComponent> ui);     //  3 0x140cbd490 attach the page's UI
    virtual void vfunc_4();                             //  4 0x140cbd2c0
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 6 0x140cbd610
    virtual void vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4);   // 7 0x140cbd720
    virtual int vfunc_8();                              //  8 0x140cbd860 (0)

    void FUN_140cbd870();                               // tell the page whether the pet is out ("summon")

    int m_nPet;                                         // +0x18
    ATL::CAtlList<MS2Ptr<PetInfoBase> > m_parts;        // +0x20 (0x30): block size 10
    MS2Ptr<ASUIComponent> m_ui;                         // +0x50
};
MS2_CHECK_SIZE(TabContentsPetInfo, 0x60);
MS2_CHECK_OFFSET(TabContentsPetInfo, m_parts, 0x20);
MS2_CHECK_OFFSET(TabContentsPetInfo, m_ui, 0x50);
