// tabcontentspetcompose.h - the pet compose tab of the pet system dialog: TabContentsPetCompose (RTTI
// .?AVTabContentsPetCompose@@, 0xf0 bytes, base PetSystemTabContents) and its three section helpers PetComposePetCard,
// PetComposePetIngredient and PetComposePetEnchant (base PetComposeBase, a CPtred holding the section's AS clip).
// Owning unit: client\ms2\tabcontentspetcompose.cpp (0x140cb1d90-0x140cb87d0). Header name assumed from the unit path (w342).
// Sibling of tabcontentspetevolution.h: the same section structure. The member names are invented; the FUN_ names are the
// exe addresses of the non-virtual functions.
#pragma once
#include <atlcoll.h>
#include <utility>

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/petsystemtabcontents.h"

class TabContentsPetCompose;

// One section of the compose page (card / ingredient / enchant). The slot numbers follow the exe vftable of PetComposeBase.
class PetComposeBase : public CPtred
{
public:
    PetComposeBase();                                   // 0x140cb6c60
    virtual ~PetComposeBase();                          //  0 0x140cb6db0 (??_G 0x140cb6ff0)
    virtual void vfunc_1();                             //  1 0x140cb1d90 calls vfunc_2
    virtual void vfunc_2() {}                           //  2 0x140cb7d80 release the section's item bag
    virtual void vfunc_3() {}                           //  3 0x140cb71c0 refresh the section's state
    virtual void vfunc_4() {}                           //  4 0x140cb71b0 rebuild the section's bag
    virtual void vfunc_5(int nTab) {}                   //  5 0x140cb80e0 react to the tab changing
    void FUN_140cb8490(MS2Ptr<ASUIComponent> ui);       // m_ui = ui (the argument is destroyed by the callee)

    MS2Ptr<ASUIComponent> m_ui;                         // +0x18
};
MS2_CHECK_SIZE(PetComposeBase, 0x28);

class PetComposePetCard : public PetComposeBase
{
public:
    PetComposePetCard(TabContentsPetCompose* pOwner);   // 0x140cb1dc0
    virtual ~PetComposePetCard();                       //  0 0x140cb6df0 (??_G 0x140cb7030)
    virtual void vfunc_2();                             //  2 0x140cb1e30
    virtual void vfunc_4();                             //  4 0x140cb1e60
    virtual void vfunc_5(int nTab);                     //  5 0x140cb2060

    CString m_strBag;                                   // +0x28 item bag registry name
    TabContentsPetCompose* m_pOwner;                    // +0x30
};
MS2_CHECK_SIZE(PetComposePetCard, 0x38);

class PetComposePetIngredient : public PetComposeBase
{
public:
    PetComposePetIngredient(TabContentsPetCompose* pOwner);   // 0x140cb20b0
    virtual ~PetComposePetIngredient();                 //  0 0x140cb6e60 (??_G 0x140cb70b0)
    virtual void vfunc_2();                             //  2 0x140cb2120
    virtual void vfunc_4();                             //  4 0x140cb2150
    virtual void vfunc_5(int nTab);                     //  5 0x140cb2350

    CString m_strBag;                                   // +0x28
    TabContentsPetCompose* m_pOwner;                    // +0x30
};
MS2_CHECK_SIZE(PetComposePetIngredient, 0x38);

class PetComposePetEnchant : public PetComposeBase
{
public:
    PetComposePetEnchant(TabContentsPetCompose* pOwner);          // 0x140cb23a0
    virtual ~PetComposePetEnchant();                    //  0 0x140cb6e20 (??_G 0x140cb7070)
    virtual void vfunc_2();                             //  2 0x140cb2430
    virtual void vfunc_3();                             //  3 0x140cb2470 submit button, point bar
    virtual void vfunc_4();                             //  4 0x140cb2b20
    virtual void vfunc_5(int nTab);                     //  5 0x140cb2ee0

    CString m_strBag;                                   // +0x28 "PetComposePetEnchantBag" (the selected ingredients)
    CString m_strTarget;                                // +0x30 "...Target" (the pet card)
    TabContentsPetCompose* m_pOwner;                    // +0x38

    void FUN_140cb2fb0();                               // the pet card was selected
    void FUN_140cb34b0();                               // an ingredient was selected
    void FUN_140cb3a30();                               // the compose succeeded
};
MS2_CHECK_SIZE(PetComposePetEnchant, 0x40);

class TabContentsPetCompose : public PetSystemTabContents
{
public:
    typedef std::pair<unsigned __int64, int> IdCount;   // item uid and how many of it are selected

    TabContentsPetCompose();                            // 0x140cb3db0
    virtual ~TabContentsPetCompose();                   //  0 0x140cb6e90 (??_G 0x140cb70f0)
    virtual void vfunc_1();                             //  1 0x140cb4050 close the sections, drop the UI
    virtual void vfunc_2(int nTab);                     //  2 0x140cb4290
    virtual void vfunc_3(MS2Ptr<ASUIComponent> ui);     //  3 0x140cb43f0 attach the page's UI
    virtual void vfunc_4();                             //  4 0x140cb4150 reset the selection
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 6 0x140cb4590
    virtual int vfunc_8();                              //  8 0x140cb4790 (1)

    unsigned __int64 FUN_140cb47b0();                   // the pet's item uid
    void FUN_140cb47d0(ATL::CAtlArray<unsigned __int64>& out);   // copy of m_petCards
    void FUN_140cb4800(ATL::CAtlArray<unsigned __int64>& out);   // copy of m_candidates
    void FUN_140cb4830(ATL::CAtlArray<IdCount>& out);   // copy of m_pool
    void FUN_140cb4860(ATL::CAtlArray<IdCount>& out);   // copy of m_selected
    void FUN_140cb48a0(int bUsePoint);                  // send the compose request
    void FUN_140cb4ed0(__int64* pBase, __int64* pBonus);   // exp gain of the selected ingredients (base, event bonus)
    void FUN_140cb5300(unsigned short* pClass, __int64* pExp);   // the pet class and exp after the compose
    void FUN_140cb5600();                               // rebuild the pet card and candidate lists from the inventory
    void FUN_140cb5970();                               // rebuild the ingredient pool
    void FUN_140cb5bd0();                               // drop the selected ingredients
    void FUN_140cb5c00(int nIndex);                     // a pet card was clicked
    void FUN_140cb5c90(int nIndex);                     // an ingredient in the pool was clicked
    void FUN_140cb5fd0(int nIndex);                     // an ingredient in the enchant bag was clicked
    int FUN_140cb6080(ATL::CAtlArray<IdCount>& arr, unsigned __int64 id);   // index of id, -1 when absent
    unsigned __int64 FUN_140cb6100(ATL::CAtlArray<IdCount>& arr, int nIndex);   // uid at nIndex, 0 when out of range
    int FUN_140cb6180(int nIndex);                      // selected -> pool
    int FUN_140cb62e0(unsigned __int64 id);             // pool -> selected
    int FUN_140cb6450(unsigned __int64 id);             // how many of id can still be added

    unsigned __int64 m_uidPet;                          // +0x18
    ATL::CAtlArray<unsigned __int64> m_petCards;        // +0x20
    ATL::CAtlArray<unsigned __int64> m_candidates;      // +0x40
    ATL::CAtlArray<IdCount> m_pool;                     // +0x60
    ATL::CAtlArray<IdCount> m_selected;                 // +0x80
    ATL::CAtlList<MS2Ptr<PetComposeBase> > m_parts;     // +0xa0
    __int64 m_nGainBase;                                // +0xd0
    __int64 m_nGainBonus;                               // +0xd8
    MS2Ptr<ASUIComponent> m_ui;                         // +0xe0
};
MS2_CHECK_SIZE(TabContentsPetCompose, 0xf0);
