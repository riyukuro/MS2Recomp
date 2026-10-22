// tabcontentspetremakeoption.h - the pet option remake tab of the pet system dialog: TabContentsPetRemakeOption (RTTI
// .?AVTabContentsPetRemakeOption@@, 0xe8 bytes, base PetSystemTabContents, vftable 0x142de9b78) and its three section
// helpers PetRemakeOptionPetCard, PetRemakeOptionPetIngredient and PetRemakeOptionBoard (base PetRemakeOptionBase, a
// CPtred holding the section's AS clip; vftables 0x142de9a58..0x142de9b30, 8 slots).
// Owning unit: ?\tabcontentspetremakeoption.cpp (0x140b914f0-0x140b9b470). Header name assumed from the unit path (w475).
// Sibling of tabcontentspetcompose.h / tabcontentspetevolution.h. Member names are invented; the FUN_ names are the exe
// addresses of the non-virtual functions. Sizes from the operator new of the ctor 0x140b94400 (0x38 / 0x38 / 0x58).
#pragma once
#include <atlcoll.h>
#include <algorithm>
#include <utility>

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/petsystemtabcontents.h"

class ASData;
class CInPacket;
class CMsgBoxData;
class TabContentsPetRemakeOption;

// One section of the remake page (card / ingredient / board). Every slot of the base is an empty inline body.
class PetRemakeOptionBase : public CPtred
{
public:
    PetRemakeOptionBase();                              // 0x140b9a490 (inline)
    virtual ~PetRemakeOptionBase();                     //  0 0x140b9a5d0 (inline, ??_G 0x140b9a8f0)
    virtual void vfunc_1() {}                           //  1 0x140b9ae50 close the section
    virtual void vfunc_2() {}                           //  2 0x140b9ae60 release the section's item bag
    virtual void vfunc_3() {}                           //  3 0x140b9aac0 refresh the section's state
    virtual void vfunc_4() {}                           //  4 0x140b9aab0 rebuild the section's bag
    virtual void vfunc_5(int nEvent) {}                 //  5 0x140b9aea0 react to a page event
    virtual void vfunc_6(MS2Ptr<CItem> cur, MS2Ptr<CItem> next) {}   //  6 0x140b9ae70 a remake result (both by value)
    virtual void vfunc_7(int nSelect) {}                //  7 0x140b9ae40 the result was applied
    void FUN_140b9b080(MS2Ptr<ASUIComponent> ui);       // m_ui = ui (the argument is destroyed by the callee)

    MS2Ptr<ASUIComponent> m_ui;                         // +0x18
};
MS2_CHECK_SIZE(PetRemakeOptionBase, 0x28);

class PetRemakeOptionPetCard : public PetRemakeOptionBase
{
public:
    PetRemakeOptionPetCard(TabContentsPetRemakeOption* pOwner);   // 0x140b914f0
    virtual ~PetRemakeOptionPetCard();                  //  0 0x140b9a650 (inline, ??_G 0x140b9a970)
    virtual void vfunc_2();                             //  2 0x140b91550
    virtual void vfunc_4();                             //  4 0x140b91590
    virtual void vfunc_5(int nEvent);                   //  5 0x140b917f0

    CString m_strBag;                                   // +0x28 item bag registry name ("PetRemakeOptionPetCard")
    TabContentsPetRemakeOption* m_pOwner;               // +0x30
};
MS2_CHECK_SIZE(PetRemakeOptionPetCard, 0x38);

class PetRemakeOptionPetIngredient : public PetRemakeOptionBase
{
public:
    PetRemakeOptionPetIngredient(TabContentsPetRemakeOption* pOwner);   // 0x140b91840
    virtual ~PetRemakeOptionPetIngredient();            //  0 0x140b9a680 (inline, ??_G 0x140b9a9b0)
    virtual void vfunc_2();                             //  2 0x140b918b0
    virtual void vfunc_4();                             //  4 0x140b918e0
    virtual void vfunc_5(int nEvent);                   //  5 0x140b91b60

    CString m_strBag;                                   // +0x28 "PetRemakeOptionPetIngredient"
    TabContentsPetRemakeOption* m_pOwner;               // +0x30
};
MS2_CHECK_SIZE(PetRemakeOptionPetIngredient, 0x38);

class PetRemakeOptionBoard : public PetRemakeOptionBase
{
public:
    PetRemakeOptionBoard(TabContentsPetRemakeOption* pOwner);   // 0x140b91bb0
    virtual ~PetRemakeOptionBoard();                    //  0 0x140b9a610 (inline, ??_G 0x140b9a930)
    virtual void vfunc_1();                             //  1 0x140b92d90 (empty)
    virtual void vfunc_2();                             //  2 0x140b91c20
    virtual void vfunc_3();                             //  3 0x140b91cd0 submit / debug buttons
    virtual void vfunc_4();                             //  4 0x140b920b0
    virtual void vfunc_5(int nEvent);                   //  5 0x140b92210
    virtual void vfunc_6(MS2Ptr<CItem> cur, MS2Ptr<CItem> next);   //  6 0x140b92270 show the remake result
    virtual void vfunc_7(int nSelect);                  //  7 0x140b92740 the selected option was applied

    void FUN_140b92da0();                               // the pet card was selected
    void FUN_140b93460();                               // an ingredient was selected
    int FUN_140b937c0(ASObj& obj, MS2Ptr<CItem> item);  // fill the ingredient list; 1 when everything is there
    CString FUN_140b94260(CItem* pItem, CString strKey, ATL::CAtlArray<CString>& names);   // bind an item to a slot
    int FUN_140b94340(MS2Ptr<CItem> item);              // how many of the item the inventory holds
    CString FUN_140b9ad20() { return m_strBag; }        // 0x140b9ad20 (inline) copy of m_strBag

    CString m_strBag;                                   // +0x28 "PetRemakeOptionBoardTarget"
    ATL::CAtlArray<CString> m_names;                    // +0x30 the ingredient slot names
    TabContentsPetRemakeOption* m_pOwner;               // +0x50
};
MS2_CHECK_SIZE(PetRemakeOptionBoard, 0x58);

class TabContentsPetRemakeOption : public PetSystemTabContents
{
public:
    typedef std::pair<unsigned __int64, int> IdCount;   // item uid and how many of it the inventory holds

    TabContentsPetRemakeOption();                       // 0x140b94400
    virtual ~TabContentsPetRemakeOption();              //  0 0x140b9a6b0 (inline, ??_G 0x140b9a9f0)
    virtual void vfunc_1();                             //  1 0x140b94710 close the sections, drop the UI
    virtual void vfunc_2(int nEvent);                   //  2 0x140b94980
    virtual void vfunc_3(MS2Ptr<ASUIComponent> ui);     //  3 0x140b94aa0 attach the page's UI
    virtual void vfunc_4();                             //  4 0x140b94860 reset the selection
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 6 0x140b94c90
    virtual int vfunc_8();                              //  8 0x140b94fa0 (3)
    virtual void vfunc_9(void* pPacket);                //  9 0x140b94fc0 a 0x75 (item remake option) packet
    virtual void vfunc_10(void* pItem, bool b);         // 10 0x140b950b0 an item changed

    unsigned __int64 FUN_140b95140();                   // m_uidPet
    unsigned __int64 FUN_140b95160();                   // m_uidIngredient
    MS2Ptr<CItem> FUN_140b95180();                      // copy of m_pet
    MS2Ptr<CItem> FUN_140b951d0();                      // copy of m_petNext
    void FUN_140b95220(ATL::CAtlArray<unsigned __int64>& out);   // copy of m_petCards
    void FUN_140b95250(ATL::CAtlArray<IdCount>& out);   // copy of m_ingredients
    void FUN_140b95280(int bUsePoint);                  // ask for / send the remake request
    void SendChangeAttributesMode7();                               // debug: remake on the server
    void FUN_140b95db0(ASData* pData);                  // debug: compare enchant
    void FUN_140b95f90();                               // send the remake request
    bool FUN_140b964c0(int nResult, const CMsgBoxData& box);   // "have no lock" confirmation
    bool FUN_140b964f0(int nResult, const CMsgBoxData& box);   // "lock option" confirmation
    void FUN_140b96520(int nState);                     // m_nState = nState, refresh the ingredient bag
    void FUN_140b96560();                               // enable / disable the ingredient bag by state
    int FUN_140b967a0();                                // m_nState
    void FUN_140b967c0(int bEnable);                    // enable the pet system dialog's tabs
    void FUN_140b96800(MS2Ptr<CItem> cur, MS2Ptr<CItem> next);   // hand a remake result to the sections
    void FUN_140b96960(MS2Ptr<CItem> item);             // the remade item was applied
    void FUN_140b96b60(ATL::CAtlArray<int>& out);       // the locked option indices of the board
    void FUN_140b96ca0();                               // rebuild the pet card list from the inventory
    void FUN_140b96e60();                               // rebuild the ingredient list
    void FUN_140b97170(int nIndex);                     // a pet card was clicked
    void FUN_140b972f0(int nIndex);                     // an ingredient was clicked
    void FUN_140b973b0(ASData* pData);                  // GetEnableLockOption
    void FUN_140b97870(ASData* pData);                  // OnClickApply
    void FUN_140b979c0();                               // OnClickRetry
    int FUN_140b97b00(ATL::CAtlArray<unsigned __int64>& arr, unsigned __int64 id);   // arr holds id
    unsigned __int64 FUN_140b97b70(ATL::CAtlArray<unsigned __int64>& arr, int nIndex);   // uid at nIndex, 0 when out of range
    void FUN_140b97bf0(ATL::CAtlArray<unsigned __int64>& arr, unsigned __int64 id);   // remove id from arr
    void FUN_140b97c90(CInPacket* pPacket);             // 6: the remake result
    void FUN_140b98430(CInPacket* pPacket);             // 1: preview of the remade item
    void FUN_140b98520(CInPacket* pPacket);             // 2: the remade item was applied
    void FUN_140b98610(CInPacket* pPacket);             // 5: an error
    void FUN_140b988d0(unsigned __int64 uidIngredient); // the remade item arrived
    void FUN_140b98ad0(int nItemId);                    // "the previous option item does not exist"
    int FUN_140b9ad70() { return m_nIngredientIndex; }  // 0x140b9ad70 (inline)

    unsigned __int64 m_uidPet;                          // +0x18 the selected pet card
    unsigned __int64 m_uidIngredient;                   // +0x20 the selected ingredient
    MS2Ptr<CItem> m_pet;                                // +0x28 the pet card item
    MS2Ptr<CItem> m_petNext;                            // +0x38 the remade copy
    int m_nPetIndex;                                    // +0x48 index of the pet card in m_petCards
    int m_nIngredientIndex;                             // +0x4c (-1)
    ATL::CAtlArray<unsigned __int64> m_petCards;        // +0x50
    ATL::CAtlArray<IdCount> m_ingredients;              // +0x70
    ATL::CAtlList<MS2Ptr<PetRemakeOptionBase> > m_parts;   // +0x90
    int m_nState;                                       // +0xc0
    MS2Ptr<PetRemakeOptionBoard> m_board;               // +0xc8
    MS2Ptr<ASUIComponent> m_ui;                         // +0xd8
};
MS2_CHECK_SIZE(TabContentsPetRemakeOption, 0xe8);
MS2_CHECK_OFFSET(TabContentsPetRemakeOption, m_petCards, 0x50);
MS2_CHECK_OFFSET(TabContentsPetRemakeOption, m_nState, 0xc0);
