// tabcontentspetevolution.h - the pet evolution tab of the pet system dialog: TabContentsPetEvolution (RTTI
// .?AVTabContentsPetEvolution@@, 0xc8 bytes, base PetSystemTabContents) and its three section helpers PetEvolutionPetCard,
// PetEvolutionPetIngredient and PetEvolutionPetEnchant (base PetEvolutionBase, a CPtred holding the section's AS clip).
// Owning unit: client\ms2\tabcontentspetevolution.cpp (0x140ac7740-0x140aced60). Header name assumed from the unit path (w47).
// The member names are invented; the FUN_ names are the exe addresses of the non-virtual functions.
#pragma once
#include <atlcoll.h>
#include <utility>

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/petsystemtabcontents.h"

class TabContentsPetEvolution;

// One section of the evolution page (card / ingredient / enchant). The slot numbers follow the exe vftable 0x142dd3d38.
class PetEvolutionBase : public CPtred
{
public:
    PetEvolutionBase();                                 // 0x140acd600 (inline)
    virtual ~PetEvolutionBase();                        //  0 0x140acd7d0 (inline, ??_G 0x140acda50)
    virtual void vfunc_1();                             //  1 0x140ac7740 calls vfunc_2
    virtual void vfunc_2() {}                           //  2 0x140ace4c0 release the section's item bag
    virtual void vfunc_3() {}                           //  3 0x140acdf80 refresh the section's state
    virtual void vfunc_4() {}                           //  4 0x140acddc0 rebuild the section's bag
    virtual void vfunc_5(int nTab) {}                   //  5 0x140ace4e0 react to the tab changing
    void FUN_140ace8a0(MS2Ptr<ASUIComponent> ui);       // m_ui = ui (the argument is destroyed by the callee)

    MS2Ptr<ASUIComponent> m_ui;                         // +0x18
};
MS2_CHECK_SIZE(PetEvolutionBase, 0x28);

class PetEvolutionPetCard : public PetEvolutionBase
{
public:
    PetEvolutionPetCard(TabContentsPetEvolution* pOwner);   // 0x140ac7770
    virtual ~PetEvolutionPetCard();                     //  0 0x140acd810 (inline, ??_G 0x140acda90)
    virtual void vfunc_2();                             //  2 0x140ac77e0
    virtual void vfunc_4();                             //  4 0x140ac7810
    virtual void vfunc_5(int nTab);                     //  5 0x140ac7a10

    CString m_strBag;                                   // +0x28 item bag registry name
    TabContentsPetEvolution* m_pOwner;                  // +0x30
};
MS2_CHECK_SIZE(PetEvolutionPetCard, 0x38);

class PetEvolutionPetIngredient : public PetEvolutionBase
{
public:
    PetEvolutionPetIngredient(TabContentsPetEvolution* pOwner);   // 0x140ac7a60
    virtual ~PetEvolutionPetIngredient();               //  0 0x140acd890 (inline, ??_G 0x140acdb10)
    virtual void vfunc_2();                             //  2 0x140ac7ad0
    virtual void vfunc_4();                             //  4 0x140ac7b00
    virtual void vfunc_5(int nTab);                     //  5 0x140ac7d00

    CString m_strBag;                                   // +0x28
    TabContentsPetEvolution* m_pOwner;                  // +0x30
};
MS2_CHECK_SIZE(PetEvolutionPetIngredient, 0x38);

class PetEvolutionPetEnchant : public PetEvolutionBase
{
public:
    PetEvolutionPetEnchant(TabContentsPetEvolution* pOwner);      // 0x140ac7d90
    virtual ~PetEvolutionPetEnchant();                  //  0 0x140acd840 (inline, ??_G 0x140acdad0)
    virtual void vfunc_2();                             //  2 0x140ac7e30
    virtual void vfunc_3();                             //  3 0x140ac7e80 submit button, debug buttons, point bar
    virtual void vfunc_4();                             //  4 0x140ac8530
    virtual void vfunc_5(int nTab);                     //  5 0x140ac88d0

    CString m_strBag;                                   // +0x28 "PetEvolutionPetEnchantBag" (the selected ingredients)
    CString m_strTarget;                                // +0x30 "...Target" (the pet card)
    CString m_strResult;                                // +0x38 "...Result"
    TabContentsPetEvolution* m_pOwner;                  // +0x40

    void FUN_140ac8a00();                               // the pet card was selected
    void FUN_140ac9140();                               // an ingredient was selected
    void FUN_140ac9520();                               // the evolution succeeded
    void FUN_140ac9a60();                               // the evolution point went up
    void FUN_140ac9e20(ASObj& obj);                     // preview item of the evolved pet
};
MS2_CHECK_SIZE(PetEvolutionPetEnchant, 0x48);

class TabContentsPetEvolution : public PetSystemTabContents
{
public:
    typedef std::pair<unsigned __int64, int> IdCount;   // item uid and how many of it are selected

    TabContentsPetEvolution();                          // 0x140aca490
    virtual ~TabContentsPetEvolution();                 //  0 0x140acd8c0 (inline, ??_G 0x140acdb90)
    virtual void vfunc_1();                             //  1 0x140aca700 close the sections, drop the UI
    virtual void vfunc_2(int nTab);                     //  2 0x140aca8f0
    virtual void vfunc_3(MS2Ptr<ASUIComponent> ui);     //  3 0x140acaa50 attach the page's UI
    virtual void vfunc_4();                             //  4 0x140aca7e0 reset the selection
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 6 0x140acabf0
    virtual int vfunc_8();                              //  8 0x140acae80 (4)

    unsigned __int64 GetUidPet();                   // the pet's item uid
    void FUN_140acaec0(ATL::CAtlArray<unsigned __int64>& out);   // copy of m_petCards
    void FUN_140acaef0(ATL::CAtlArray<IdCount>& out);   // copy of m_pool
    void FUN_140acaf20(ATL::CAtlArray<IdCount>& out);   // copy of m_selected
    void OnPetEnchant(int bUsePoint);                  // send the evolution request
    void FUN_140acb560(unsigned nPoint);                // debug: /petevolutionpoint
    int FUN_140acb6f0();                                // number of selected ingredients (an empty count is 1)
    void SetState(int nState);
    int GetState();
    void FUN_140acb850();                               // rebuild the pet card list from the inventory
    void FUN_140acba80();                               // rebuild the ingredient pool
    void FUN_140acbd40();                               // drop the selected ingredients
    void FUN_140acbd70(int nIndex);                     // a pet card was clicked
    void FUN_140acbe00(int nIndex);                     // an ingredient in the pool was clicked
    void FUN_140acc1d0(int nIndex);                     // an ingredient in the enchant bag was clicked
    int FUN_140acc280(ATL::CAtlArray<IdCount>& arr, unsigned __int64 id);   // index of id, -1 when absent
    unsigned __int64 FUN_140acc300(ATL::CAtlArray<IdCount>& arr, int nIndex);   // uid at nIndex, 0 when out of range
    int FUN_140acc380(int nIndex);                      // selected -> pool
    int FUN_140acc4e0(unsigned __int64 id);             // pool -> selected
    int FUN_140acc650(unsigned __int64 id);             // how many of id can still be added
    IdCount FUN_140acc7d0(unsigned __int64 id);         // (id, 1)

    int m_nState;                                       // +0x18
    unsigned __int64 m_uidPet;                          // +0x20
    ATL::CAtlArray<unsigned __int64> m_petCards;        // +0x28
    ATL::CAtlArray<IdCount> m_pool;                     // +0x48
    ATL::CAtlArray<IdCount> m_selected;                 // +0x68
    ATL::CAtlList<MS2Ptr<PetEvolutionBase> > m_parts;   // +0x88
    MS2Ptr<ASUIComponent> m_ui;                         // +0xb8
};
MS2_CHECK_SIZE(TabContentsPetEvolution, 0xc8);
