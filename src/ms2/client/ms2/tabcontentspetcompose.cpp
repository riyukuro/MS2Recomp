// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Pet compose tab of the pet system dialog (sibling of
// tabcontentspetevolution.cpp: the same three sections, here with an experience bar instead of an evolution point bar).
// MS2-UNIT: ?\tabcontentspetcompose.cpp
// MS2-RANGE: 0x140cb1d90-0x140cb87d0 .text$mn
// MS2-RANGE: 0x1400cfbb0-0x1400cfde0 .text$di
// MS2-PIN: ??$FUN_14028dfa0@_J_J@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEB_J1@Z 0x140cb6660 ; the string-key formatter for two __int64 (wcformat.h)
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlList@V?$MS2Ptr@VPetComposeBase@@@@V?$CElementTraits@V?$MS2Ptr@VPetComposeBase@@@@@ATL@@@ATL@@QEAA@I@Z 0x140cb6a50 ; unique
// MS2-PIN: ??0?$CRBMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@_K@Z 0x140cb6ab0 ; unique
// MS2-PIN: ??0?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@IEAA@_K@Z 0x140cb6ae0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VPetComposeBase@@@@QEAA@PEAVPetComposeBase@@@Z 0x140cb6b80 ; unique
// MS2-PIN: ??0CNode@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@_KH@Z 0x140cb6be0 ; unique
// MS2-PIN: ??0CPair@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@IEAA@_KH@Z 0x140cb6c30 ; unique
// MS2-PIN: ?vfunc_4@PetComposeBase@@UEAAXXZ 0x140cb71b0 ; unique
// MS2-PIN: ?Find@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@_K@Z 0x140cb71d0 ; unique
// MS2-PIN: ?GetAt@?$CAtlList@V?$MS2Ptr@VPetComposeBase@@@@V?$CElementTraits@V?$MS2Ptr@VPetComposeBase@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VPetComposeBase@@@@PEAU__POSITION@@@Z 0x140cb73d0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CAtlList@V?$MS2Ptr@VPetComposeBase@@@@V?$CElementTraits@V?$MS2Ptr@VPetComposeBase@@@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x140cb7530 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x140cb7540 ; unique
// MS2-PIN: ?GetKeyAt@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEBAAEB_KPEAU__POSITION@@@Z 0x140cb7560 ; unique
// MS2-PIN: ?GetNext@?$CAtlList@V?$MS2Ptr@VPetComposeBase@@@@V?$CElementTraits@V?$MS2Ptr@VPetComposeBase@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VPetComposeBase@@@@AEAPEAU__POSITION@@@Z 0x140cb75c0 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140cb7640 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAAEAHPEAU__POSITION@@@Z 0x140cb7680 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_KH@Z 0x140cb76e0 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140cb7820 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEBA_N_KAEAH@Z 0x140cb7930 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140cb7980 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_KH@Z 0x140cb7b20 ; unique
// MS2-PIN: ?vfunc_2@PetComposeBase@@UEAAXXZ 0x140cb7d80 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140cb7d90 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@IEAAPEAVCNode@12@_KH@Z 0x140cb7e60 ; unique
// MS2-PIN: ?vfunc_5@PetComposeBase@@UEAAXH@Z 0x140cb80e0 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140cb82b0 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAPEAU__POSITION@@_KH@Z 0x140cb83c0 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x140cb8420 ; unique
// MS2-PINS-END tplpin
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\tabcontentspetcompose.cpp"
#define MS2_ASUICOMPONENT_SLOTS   // ASTileList::vfunc_24 (validateNow)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astilelist.h"

#include "tabcontentspetcompose.h"

#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cgamerule.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/cpetdatatable.h"   // C3: CPetData / CPetDataTable (the pet row)

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/luautil.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/exptable.h"
#include "ms2/commonfiles/contentshutdown.h"  // C3: CContentShutdown::Get
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get

// MS2Ptr<ASUIComponent>: the exe shares every member except these four, which are COMDATs of the evolution unit.
template <> MS2Ptr<ASUIComponent>::MS2Ptr(MS2Ptr<ASUIComponent>&& o);                 // 0x140acd480
template <> MS2Ptr<ASUIComponent>::MS2Ptr(int nNull);                                   // 0x140acd4b0
template <> MS2Ptr<ASUIComponent>::MS2Ptr(ASUIComponent* p);                            // 0x140acd4d0
template <> bool MS2Ptr<ASUIComponent>::operator==(ASUIComponent* p) const;             // 0x140acd940
extern template class MS2Ptr<ASUIComponent>;
extern template class MS2Ptr<ASMovieClip>;
extern template class MS2Ptr<CItem>;
extern template class MS2Ptr<CItemData>;

// ---- statics of the unit's header (the .di of this unit constructs them in this order) ----
static CString s_itemLevel("itemLevel");
static CString s_itemName("itemName");
static CString s_meso("meso");
static CStringW s_composeBindPet(L"composeBindPet");
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

struct Unk_RegMarker {};
#ifndef MS2_HOOK_DLL
#include "ms2/placeholder/unk_1402a9d70.h"

// the exe calls _abs64 out of line through the ucrt import (not the /Oi intrinsic)
#pragma function(_abs64)
static Unk_1402a9d70 s_marker(17, 0.75f, 0.25f, 2.25f, 10);   // atexit thunk FUN_142ca3da0
#endif

// ---- unit-local placeholders (the names of the classes shared with tabcontentspetevolution.cpp must stay identical:
// the ASButton / ASTileList members it instantiates are the ones this unit calls) ----

// A Scaleform value seen through its "is this an object" test (the exe calls one shared function on it).
class Unk_PetValueView { public: bool FUN_1409b4d40() const; };


// The pet row is CPetData (cpetdatatable.h); m_nType (+0x18) is zero for plain items.
extern template class MS2Ptr<CPetData>;

// CItem::FUN_140527840's record (as commonfiles\item.cpp): the item data, of which this unit reads the type and the
// function arguments (+0x2b0, the arguments of the item's <function>).
class Unk_ItemEquipData : public CItemData {};
struct Unk_CommandArgs                                                  // C3: member view (usercommandcli.h)
{
    unsigned FUN_1408d2380();                                           // the argument count
    int FUN_1408d1fd0(unsigned nIndex, int nDefault);                   // the nIndex-th argument as a number
};
class Unk_ComposeItemView : public CPtred
{
public:
    unsigned char m_pad_18[0x298];
    Unk_CommandArgs m_args;                                             // +0x2b0
};

// The local player: slot 77 is the name; FUN_141663a20 is a counter the compose bonus is derived from.
class Unk_PetPlayer
{
public:
#define PP_V(n) virtual void vfunc_##n();
    PP_V(0) PP_V(1) PP_V(2) PP_V(3) PP_V(4) PP_V(5) PP_V(6) PP_V(7) PP_V(8) PP_V(9)
    PP_V(10) PP_V(11) PP_V(12) PP_V(13) PP_V(14) PP_V(15) PP_V(16) PP_V(17) PP_V(18) PP_V(19)
    PP_V(20) PP_V(21) PP_V(22) PP_V(23) PP_V(24) PP_V(25) PP_V(26) PP_V(27) PP_V(28) PP_V(29)
    PP_V(30) PP_V(31) PP_V(32) PP_V(33) PP_V(34) PP_V(35) PP_V(36) PP_V(37) PP_V(38) PP_V(39)
    PP_V(40) PP_V(41) PP_V(42) PP_V(43) PP_V(44) PP_V(45) PP_V(46) PP_V(47) PP_V(48) PP_V(49)
    PP_V(50) PP_V(51) PP_V(52) PP_V(53) PP_V(54) PP_V(55) PP_V(56) PP_V(57) PP_V(58) PP_V(59)
    PP_V(60) PP_V(61) PP_V(62) PP_V(63) PP_V(64) PP_V(65) PP_V(66) PP_V(67) PP_V(68) PP_V(69)
    PP_V(70) PP_V(71) PP_V(72) PP_V(73) PP_V(74) PP_V(75) PP_V(76)
#undef PP_V
    virtual CStringW vfunc_77();                                        // character name
};
class PC { public: int FUN_141663a20(); };   // C3: member view (fittingdollpc.h), how many pet composes the player did
class Unk_PetPlayerMgr { public: Unk_PetPlayer* FUN_141bd0cc0(); };

// Exp table of the pets (the exp a class needs for the next one).
void* FUN_1404a1bb0();

// Recipe table (the compose exp and cost of an ingredient).
class Unk_PetRecipe : public CLua
{
};
class Unk_BmPriceMgr* FUN_1401c0db0();   // C3: was FUN_1401c0db0
void* FUN_1401c0d90();   // C3: was FUN_1401c0d90

// Feature flags (slot 0x37 turns the compose off).
class Unk_PetFlag { public: int FUN_1402c4c90(int nFlag); };
class Unk_PetFlags { public: void* p0; Unk_PetFlag flags; };
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0

// Client configuration: the pet class that may be composed sits at +0x84c0, the compose bonus limit at +0x8d18.
class Unk_PetUIntSlot { public: };
class Unk_PetConfig
{
public:
    unsigned char m_pad[0x84c0];
    Unk_PetUIntSlot m_petClass;
    unsigned char m_pad_84c4[0x8d18 - 0x84c0 - sizeof(Unk_PetUIntSlot)];
    Unk_PetUIntSlot m_bonusLimit;
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

// The item picked in the inventory dialog.
class Unk_BreakSelected;
class CPetManager   // C3: member view (cpetmanager.h redefines Unk_PetFlags)
{
public:
    __int64 GetSummonUid();   // 0x140c8b2e0
};
Unk_BreakSelected* FUN_140535320();                      // C3: the real function (0x140535320, itembreakmanager.cpp): the CPetManager singleton

// CItem accessors the exe calls as free functions.
                    // item name (CItem member: this=rcx, hidden return=rdx)
__int64 GetServerTime();                                                // server time

// Message box (same entry points as inventory.cpp).
class CMsgBoxData;
extern template class MS2Ptr<CMsgBoxData>;                              // the message box type is defined in another unit
MS2Ptr<CMsgBoxData> FUN_140d73d20(int, CStringW, void*, CStringW);
class CMsgBoxData   // C3: member view for the former free stand-ins
{
public:
    void FUN_141a01600(__int64);
    void SetButtonLabelIds(int, int, int);
    void FUN_141a01ee0(MS2Ptr<CItem> spItem, const CStringW& strName, int nA, int nB, int nC, int nD, int nE);   // item entry
};
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);

// Item bag registry (the section's bag ids).
void FUN_140b77500(const CString& strBag);                                      // release a card bag
void FUN_140b773a0(const CString& strBag, const ATL::CAtlArray<unsigned __int64>& ids);
void FUN_140b77e50(const CString& strBag);                                      // release an ingredient bag
void FUN_140b77cf0(const CString& strBag, const ATL::CAtlArray<TabContentsPetCompose::IdCount>& items);

// UI helpers.
int FUN_141276180(const CString& strSound, const CString& strArg);     // play a UI sound
void FUN_1412752d0(const CStringW& strMsg, int nType);                  // chat/system notice
void FUN_141275260(int nMsgId, int a1, int a2);

// String helpers.
CStringW FUN_1409404f0(__int64 n);                                      // number with separators
template <class A> CStringW FormatStringId(int nId, const A& a);
CStringW BlockFormat(int, const fmt::ArgList&);   // C3: BlockFormat<int> (0x1408116a0)
FMT_VARIADIC_W(CStringW, BlockFormat, int)
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);   // string table text, formatted
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

void FUN_140710590(COutPacket& pkt);                                    // send

// The Value setter the (int64, int64) Invoke helper uses.
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);

extern Unk_Inventory g_143ab2a90;
typedef MS2Ptr<CItem> ItemPtr;
typedef TabContentsPetCompose::IdCount IdCount;

// ---- glue: AS child control binding (the specializations and the Value helpers are COMDATs of the evolution unit) ----

template <> MS2Ptr<ASButton> AScript::FUN_140acce30<ASButton>(const CString& strName);       // 0x140acce30
template <> MS2Ptr<ASTileList> AScript::FUN_140accef0<ASTileList>(const CString& strName);     // 0x140accef0
template <> MS2Ptr<ASUIComponent> AScript::FUN_140accfb0<ASUIComponent>(const CString& strName);        // 0x140accfb0

// @0x140cb6990
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, __int64 a1, __int64 a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- PetComposeBase ----

// @0x140cb6c60
inline PetComposeBase::PetComposeBase()
{
}

// @0x140cb6db0
inline PetComposeBase::~PetComposeBase()
{
}

// @0x140cb8490
inline void PetComposeBase::FUN_140cb8490(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
}

// @0x140cb65d0
IdCount FUN_140cb65d0(unsigned __int64 id)
{
    int nOne = 1;
    return IdCount(id, nOne);
}

// 0x140cb6610 is this unit's copy of the forwarding constructor std::pair<unsigned __int64, int>::pair<unsigned __int64&, int&>
// (IdCount(id, nCount) in FUN_140cb5970).
// MS2-PIN: ??$?0AEA_KAEAH$0A@@?$pair@_KH@std@@QEAA@AEA_KAEAH@Z 0x140cb6610

// @0x140cb1d90
void PetComposeBase::vfunc_1()
{
    vfunc_2();
}

// ---- PetComposePetCard ----

// @0x140cb1dc0
PetComposePetCard::PetComposePetCard(TabContentsPetCompose* pOwner)
    : m_strBag("PetComposePetCard")
{
    m_pOwner = pOwner;
}

// @0x140cb1e30
void PetComposePetCard::vfunc_2()
{
    FUN_140b77500(m_strBag);
}

// @0x140cb1e60
void PetComposePetCard::vfunc_4()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> card = m_ui->FUN_140accfb0<ASUIComponent>("m_petCard");
    if (card == 0)
        return;
    if (MS2Ptr<ASTileList> bag = card->FUN_140accef0<ASTileList>("m_itemBag"))
    {
        ATL::CAtlArray<unsigned __int64> ids;
        m_pOwner->FUN_140cb47d0(ids);
        FUN_140b77500(m_strBag);
        FUN_140b773a0(m_strBag, ids);
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(true);
    }
}

// @0x140cb2060
void PetComposePetCard::vfunc_5(int nTab)
{
    switch (nTab)
    {
    case 1:
    case 2:
    case 0xc:
        vfunc_4();
        break;
    }
}

// ---- PetComposePetIngredient ----

// @0x140cb20b0
PetComposePetIngredient::PetComposePetIngredient(TabContentsPetCompose* pOwner)
    : m_strBag("PetComposePetIngredient")
{
    m_pOwner = pOwner;
}

// @0x140cb2120
void PetComposePetIngredient::vfunc_2()
{
    FUN_140b77e50(m_strBag);
}

// @0x140cb2150
void PetComposePetIngredient::vfunc_4()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ingredient = m_ui->FUN_140accfb0<ASUIComponent>("m_petIngredient");
    if (ingredient == 0)
        return;
    if (MS2Ptr<ASTileList> bag = ingredient->FUN_140accef0<ASTileList>("m_itemBag"))
    {
        ATL::CAtlArray<IdCount> items;
        m_pOwner->FUN_140cb4830(items);
        FUN_140b77e50(m_strBag);
        FUN_140b77cf0(m_strBag, items);
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(true);
    }
}

// @0x140cb2350
void PetComposePetIngredient::vfunc_5(int nTab)
{
    switch (nTab)
    {
    case 1:
    case 2:
    case 10:
    case 11:
    case 0xc:
        vfunc_4();
        break;
    }
}

// ---- PetComposePetEnchant ----

// @0x140cb23a0
PetComposePetEnchant::PetComposePetEnchant(TabContentsPetCompose* pOwner)
    : m_strBag("PetComposePetEnchantBag"), m_strTarget("PetComposePetEnchantTarget")
{
    m_pOwner = pOwner;
}

// @0x140cb2430
void PetComposePetEnchant::vfunc_2()
{
    FUN_140b77e50(m_strBag);
    FUN_140b77500(m_strTarget);
}

// @0x140cb2470
void PetComposePetEnchant::vfunc_3()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>("m_petEnchant");
    if (ench == 0)
        return;
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(m_pOwner->GetUidPet());
    if (pet == 0)
        return;
    __int64 nExp = ((class CItem*)(class CItem*)(pet))->FUN_140528b90();
    unsigned short nPetClass = ((class CItem*)(class CItem*)(pet))->FUN_140528c20();
    {
        if (MS2Ptr<ASButton> submit = ench->FUN_140acce30<ASButton>("m_submit"))
        {
            ATL::CAtlArray<IdCount> selected;
            m_pOwner->FUN_140cb4860(selected);
            if (nPetClass < *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_petClass)->Get() && selected.GetCount() > 0)
                submit->FUN_1422c1fe0(1);
            else
                submit->FUN_1422c1fe0(0);
        }
    }
    if (MS2Ptr<ASUIComponent> bar = ench->FUN_140accfb0<ASUIComponent>("m_expBar"))
    {
        m_pOwner->FUN_140cb5300(&nPetClass, &nExp);
        if (nPetClass < *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_petClass)->Get())
        {
            __int64 nNeed = ((CExpTable*)FUN_1404a1bb0())->GetPetExp(nPetClass, pet->GetRarity(), reinterpret_cast<CItem*>(pet.get())->FUN_1405282d0());
            CStringW strLevel;
            strLevel.Format(L"%s", (LPCWSTR)FUN_14028dfa0<unsigned short>(CStringW(L"s_word_petlevel"), nPetClass));
            CStringW strCount;
            strCount.Format(L"%s", (LPCWSTR)FUN_14028dfa0<CStringW, CStringW>(CStringW(L"s_common_cur_max_ingredient"), FUN_1409404f0(nExp), FUN_1409404f0(nNeed)));
            CStringW strText;
            strText.Format(L"%s (%s)", (LPCWSTR)strLevel, (LPCWSTR)strCount);
            bar->Invoke("setText", CStringW(strText));
            bar->Invoke("setPercentTween", nExp, nNeed);
        }
        else
        {
            bar->Invoke("setMax");
        }
    }
}

// @0x140cb2b20
void PetComposePetEnchant::vfunc_4()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>("m_petEnchant");
    if (ench == 0)
        return;
    if (MS2Ptr<ASTileList> bag = ench->FUN_140accef0<ASTileList>("m_itemBag"))
    {
        ATL::CAtlArray<IdCount> items;
        m_pOwner->FUN_140cb4860(items);
        FUN_140b77e50(m_strBag);
        FUN_140b77cf0(m_strBag, items);
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(true);
    }
    if (MS2Ptr<ASButton> submit = ench->FUN_140acce30<ASButton>("m_submit"))
        submit->FUN_1422c1fe0(0);
    ASObj obj(2);
    obj.FUN_1409c0dc0("sale", "");
    obj.FUN_1407cbb20(s_meso, BlockFormat<int>(0x986, 0));
    ench->FUN_140acd1f0("selectPetIngredient", AScript(obj));
}

// @0x140cb2ee0
void PetComposePetEnchant::vfunc_5(int nTab)
{
    switch (nTab)
    {
    case 1:
    case 2:
    case 10:
        vfunc_4();
        vfunc_3();
        FUN_140cb2fb0();
        break;
    case 0xb:
        vfunc_4();
        vfunc_3();
        FUN_140cb34b0();
        break;
    case 0xc:
        vfunc_4();
        vfunc_3();
        FUN_140cb3a30();
        break;
    }
}

#ifndef MS2_HOOK_DLL
// @0x140cb2fb0
void PetComposePetEnchant::FUN_140cb2fb0()
{
    Unk_PetPlayer* player = ((Unk_PetPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (player == 0)
        return;
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>("m_petEnchant");
    if (ench == 0)
        return;
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(m_pOwner->GetUidPet());
    if (pet == 0)
        return;
    ATL::CAtlArray<unsigned __int64> ids;
    ids.Add(m_pOwner->GetUidPet());
    FUN_140b77500(m_strBag);
    FUN_140b773a0(m_strTarget, ids);
    int nBonus = (int)*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_bonusLimit)->Get() - reinterpret_cast<PC*>(player)->FUN_141663a20() < 0
        ? 0 : (int)*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_bonusLimit)->Get() - reinterpret_cast<PC*>(player)->FUN_141663a20();
    ASObj obj(2);
    obj.FUN_1407cbb20(s_itemName, reinterpret_cast<CItem*>(pet.get())->FUN_140527b10());
    obj.FUN_1409c48f0(s_itemLevel, ((class CItem*)(class CItem*)(pet))->FUN_140528c20());
    obj.FUN_1409c0dc0("sale", "");
    obj.FUN_1407cbb20("bonus", FUN_14028dfa0<int>(CStringW(L"s_pet_compose_exp_bonus"), nBonus));
    obj.FUN_1407cbb20(s_meso, BlockFormat<int>(0x986, 0));
    obj.FUN_1409c1180("petExp", ((class CItem*)(class CItem*)(pet))->FUN_140528b90());
    obj.FUN_1407cba60("bagId", m_strTarget);
    ench->FUN_140acd1f0("selectPetCard", AScript(obj));
    FUN_141276180("pet_Button_Click", "");
}
#endif

// @0x140cb34b0
void PetComposePetEnchant::FUN_140cb34b0()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>("m_petEnchant");
    if (ench == 0)
        return;
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(m_pOwner->GetUidPet());
    if (pet == 0)
        return;
    ATL::CAtlArray<IdCount> selected;
    m_pOwner->FUN_140cb4860(selected);
    __int64 nTotal = 0;
    for (unsigned i = 0; i < selected.GetCount(); i++)
    {
        IdCount& entry = selected[i];
        unsigned __int64 id = entry.first;
        unsigned nCount = entry.second;
        ItemPtr item = g_143ab2a90.FUN_140a5d680(id);
        if (item == 0)
            continue;
        __int64 nCost = 0;
        if (((class CItem*)(class CItem*)(item))->IsPetItem())
        {
            __int64 nExp = ((class CItem*)(class CItem*)(item))->FUN_140528b90();
            nCost = ((class Unk_PetRecipe*)FUN_1401c0db0())->CalcPetEnchantCost(pet->GetRarity(), item->GetRarity(), ((class CItem*)(class CItem*)(item))->FUN_140528c20(), nExp);
        }
        else
        {
            nCost = ((class Unk_PetRecipe*)FUN_1401c0db0())->CalcPetEnchantBookCost(pet->GetRarity());
        }
        nTotal += ((class CGameRule*)FUN_1401c0d90())->ApplyPetComposeSale(nCost) * nCount;
    }
    ASObj obj(2);
    unsigned nSale = (unsigned)((float)(((class CGameRule*)FUN_1401c0d90())->GetPetComposeSaleRate() / 100) + 0.5f);
    if (nSale > 0)
        obj.FUN_1407cbb20("sale", FUN_14028dfa0<unsigned int>(CStringW(L"s_pet_compose_cost_sale"), nSale));
    obj.FUN_1407cbb20(s_meso, FormatStringId<CStringW>(0x986, FUN_1409404f0(nTotal)));
    ench->FUN_140acd1f0("selectPetIngredient", AScript(obj));
    FUN_141276180("pet_Button_Click", "");
}

// @0x140cb3a30
void PetComposePetEnchant::FUN_140cb3a30()
{
    Unk_PetPlayer* player = ((Unk_PetPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (player == 0)
        return;
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>("m_petEnchant");
    if (ench == 0)
        return;
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(m_pOwner->GetUidPet());
    if (pet == 0)
        return;
    int nBonus = (int)*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_bonusLimit)->Get() - reinterpret_cast<PC*>(player)->FUN_141663a20() < 0
        ? 0 : (int)*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_bonusLimit)->Get() - reinterpret_cast<PC*>(player)->FUN_141663a20();
    ASObj obj(2);
    obj.FUN_1407cbb20("bonus", FUN_14028dfa0<int>(CStringW(L"s_pet_compose_exp_bonus"), nBonus));
    obj.FUN_1407cbb20("successMsg", FUN_14028dfa0(CStringW(L"s_pet_compose_compose_success"), m_pOwner->m_nGainBase, m_pOwner->m_nGainBonus));
    ench->FUN_140acd1f0("selectPetEnchant", AScript(obj));
}

// ---- TabContentsPetCompose ----

// @0x140cb3db0
TabContentsPetCompose::TabContentsPetCompose()
    : PetSystemTabContents(), m_uidPet(0), m_parts(10), m_nGainBase(0), m_nGainBonus(0), m_ui(0)
{
    m_parts.AddTail(new PetComposePetCard(this));
    m_parts.AddTail(new PetComposePetIngredient(this));
    m_parts.AddTail(new PetComposePetEnchant(this));
}

// @0x140cb4050
void TabContentsPetCompose::vfunc_1()
{
    for (POSITION pos = m_parts.GetHeadPosition(); pos != 0; m_parts.GetNext(pos))
    {
        MS2Ptr<PetComposeBase> p = m_parts.GetAt(pos);
        if (p == 0)
            continue;
        ((PetComposeBase*)p)->vfunc_1();
    }
    m_ui = 0;
    m_nGainBase = 0;
    m_nGainBonus = 0;
}

// @0x140cb4150
void TabContentsPetCompose::vfunc_4()
{
    m_nGainBase = 0;
    m_nGainBonus = 0;
    m_uidPet = 0;
    m_petCards.RemoveAll();
    m_candidates.RemoveAll();
    m_pool.RemoveAll();
    m_selected.RemoveAll();
    for (POSITION pos = m_parts.GetHeadPosition(); pos != 0; m_parts.GetNext(pos))
    {
        MS2Ptr<PetComposeBase> p = m_parts.GetAt(pos);
        if (p == 0)
            continue;
        ((PetComposeBase*)p)->vfunc_2();
    }
}

// @0x140cb4290
void TabContentsPetCompose::vfunc_2(int nTab)
{
    if (m_ui == 0)
        return;
    switch (nTab)
    {
    case 1:
    case 2:
        FUN_140cb5600();
        FUN_140cb5970();
        FUN_140cb5bd0();
        break;
    case 0xc:
        FUN_140cb5600();
        FUN_140cb5970();
        FUN_140cb5bd0();
        break;
    }
    for (POSITION pos = m_parts.GetHeadPosition(); pos != 0; m_parts.GetNext(pos))
    {
        MS2Ptr<PetComposeBase> p = m_parts.GetAt(pos);
        if (p == 0)
            continue;
        ((PetComposeBase*)p)->vfunc_5(nTab);
    }
}

// @0x140cb43f0
void TabContentsPetCompose::vfunc_3(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
    FUN_140cb5600();
    FUN_140cb5970();
    FUN_140cb5bd0();
    for (POSITION pos = m_parts.GetHeadPosition(); pos != 0; m_parts.GetNext(pos))
    {
        MS2Ptr<PetComposeBase> p = m_parts.GetAt(pos);
        if (p == 0)
            continue;
        ((PetComposeBase*)p)->FUN_140cb8490(ui);
        ((PetComposeBase*)p)->vfunc_4();
        ((PetComposeBase*)p)->vfunc_3();
    }
}

// @0x140cb4590
int TabContentsPetCompose::vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (_stricmp("OnSelectPetCard", szEvent) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopInt();
            FUN_140cb5c00(nIndex);
        }
        return 1;
    }
    else if (_stricmp("OnSelectPetIngredient", szEvent) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopInt();
            FUN_140cb5c90(nIndex);
        }
        return 1;
    }
    else if (_stricmp("OnSelectPetEnchant", szEvent) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopInt();
            FUN_140cb5fd0(nIndex);
        }
        return 1;
    }
    else if (_stricmp("OnPetEnchant", szEvent) == 0)
    {
        FUN_140cb48a0(0);
        return 1;
    }
    return 0;
}

// @0x140cb4790
int TabContentsPetCompose::vfunc_8()
{
    return 1;
}

// @0x140cb47b0
unsigned __int64 TabContentsPetCompose::GetUidPet()
{
    return m_uidPet;
}

// @0x140cb47d0
void TabContentsPetCompose::FUN_140cb47d0(ATL::CAtlArray<unsigned __int64>& out)
{
    out.Copy(m_petCards);
}

// @0x140cb4800
void TabContentsPetCompose::FUN_140cb4800(ATL::CAtlArray<unsigned __int64>& out)
{
    out.Copy(m_candidates);
}

// @0x140cb4830
void TabContentsPetCompose::FUN_140cb4830(ATL::CAtlArray<IdCount>& out)
{
    out.Copy(m_pool);
}

// @0x140cb4860
void TabContentsPetCompose::FUN_140cb4860(ATL::CAtlArray<IdCount>& out)
{
    out.Copy(m_selected);
}

// @0x140cb48a0
void TabContentsPetCompose::FUN_140cb48a0(int bUsePoint)
{
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    if (m_selected.IsEmpty())
        return;
    Unk_PetPlayer* player = ((Unk_PetPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (player == 0)
        return;
    if (reinterpret_cast<CContentShutdown&>(((class Unk_PetFlags*)FUN_14025e7b0())->flags).Get((CContentShutdown::Content)(0x37)) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
    }
    else
    {
        if (bUsePoint == 0)
        {
            if (((class CItemTransfer*)((class CItem*)(class CItem*)(pet))->FUN_140527930())->HasBindingRule() != 0 && ((class CItemTransfer*)((class CItem*)(class CItem*)(pet))->FUN_140527930())->HasBinding() == 0)
            {
                CStringW strMsg = FUN_14028dfa0<CStringW>(L"s_msg_transfer_bind_pet_compose", player->vfunc_77());
                MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x11, strMsg, 0, s_composeBindPet);
                if (box.get() != 0)
                {
                    ((class CMsgBoxData*)(class CMsgBoxData*)(box.operator->()))->FUN_141a01600(pet->GetItemUid());
                    box.operator->()->FUN_141a01ee0(ItemPtr(pet), reinterpret_cast<CItem*>(pet.get())->FUN_140527b10(), 1, 0, -1, -1, 1);
                    ((class CMsgBoxData*)(class CMsgBoxData*)(box.operator->()))->SetButtonLabelIds(0x477, 0x478, 0);
                    FUN_140d73c60(box);
                    return;
                }
            }
        }
        ATL::CRBMap<unsigned __int64, int> counts(10);
        for (size_t i = 0; i < m_selected.GetCount(); i++)
        {
            IdCount& entry = m_selected[i];
            unsigned __int64 id = entry.first;
            int nCount = entry.second;
            int nSum = 0;
            counts.Lookup(id, nSum);
            nSum += nCount;
            counts.SetAt(id, nSum);
        }
        COutPacket pkt(static_cast<int>(SendOp::RequestPet), 0);
        pkt.Encode1(0xc);
        pkt.Encode8(m_uidPet);
        pkt.Encode2((short)counts.GetCount());
        for (POSITION pos = counts.GetHeadPosition(); pos != 0; counts.GetNext(pos))
        {
            pkt.Encode8(counts.GetKeyAt(pos));
            pkt.Encode4(counts.GetValueAt(pos));
        }
        FUN_140710590(pkt);
        FUN_140cb4ed0(&m_nGainBase, &m_nGainBonus);
    }
}

// @0x140cb4ed0
void TabContentsPetCompose::FUN_140cb4ed0(__int64* pBase, __int64* pBonus)
{
    Unk_PetPlayer* player = ((Unk_PetPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (player == 0)
        return;
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(GetUidPet());
    if (pet == 0)
        return;
    *pBase = 0;
    *pBonus = 0;
    ATL::CAtlArray<IdCount> selected;
    FUN_140cb4860(selected);
    int nCounter = reinterpret_cast<PC*>(player)->FUN_141663a20();
    unsigned nLimit = *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_bonusLimit)->Get();
    for (size_t i = 0; i < selected.GetCount(); i++)
    {
        IdCount& entry = selected[i];
        unsigned __int64 id = entry.first;
        unsigned nCount = entry.second;
        ItemPtr item = g_143ab2a90.FUN_140a5d680(id);
        if (item == 0)
            continue;
        MS2Ptr<CItemData> data(item->FUN_140527840());
        if (data == 0)
            continue;
        unsigned __int64 nBase = 0;
        __int64 nBonus = 0;
        if (((class CItem*)(class CItem*)(item))->IsPetItem())
        {
            int nCount2 = nCounter;
            ((class Unk_PetRecipe*)FUN_1401c0db0())->CalcPetEnchantExp(pet->GetRarity(), item->GetRarity(), ((class CItem*)(class CItem*)(item))->FUN_140528c20(), ((class CItem*)(class CItem*)(item))->FUN_140528b90(), nCount2, nLimit,
                ((class CItem*)(class CItem*)(item))->FUN_1405282d0(), (__int64*)&nBase, &nBonus);
            nCounter = nCounter + 1;
        }
        else
        {
            if (data->GetStringTag() == 0xd8)
            {
                if (reinterpret_cast<Unk_ComposeItemView*>(data.operator->())->m_args.FUN_1408d2380() > 0)
                    nBase = (unsigned)reinterpret_cast<Unk_ComposeItemView*>(data.operator->())->m_args.FUN_1408d1fd0(0, 0);
            }
        }
        *pBase = nBase * nCount + *pBase;
        *pBonus = nBonus * nCount + *pBonus;
    }
}

// @0x140cb5300
void TabContentsPetCompose::FUN_140cb5300(unsigned short* pClass, __int64* pExp)
{
    Unk_PetPlayer* player = ((Unk_PetPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (player == 0)
        return;
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(GetUidPet());
    if (pet == 0)
        return;
    int bLevelUp = 0;
    unsigned short nClass = ((class CItem*)(class CItem*)(pet))->FUN_140528c20();
    __int64 nExp = ((class CItem*)(class CItem*)(pet))->FUN_140528b90();
    int nRank = pet->GetRarity();
    if (!(nClass < *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_petClass)->Get()))
        return;
    __int64 nBase = 0;
    __int64 nBonus = 0;
    FUN_140cb4ed0(&nBase, &nBonus);
    __int64 nGain = nBase + nBonus;
    if (nGain < 0 && nExp <= _abs64(nGain))
        nExp = 0;
    else
        nExp = nExp + nGain;
    __int64 nNeed = ((CExpTable*)FUN_1404a1bb0())->GetPetExp(nClass, nRank, reinterpret_cast<CItem*>(pet.get())->FUN_1405282d0());
    unsigned short nUp = 0;
    while (nNeed <= nExp)
    {
        nExp = nExp - nNeed;
        nUp++;
        nNeed = ((CExpTable*)FUN_1404a1bb0())->GetPetExp(nClass + nUp, nRank, reinterpret_cast<CItem*>(pet.get())->FUN_1405282d0());
    }
    bLevelUp = nUp > 0;
    if (bLevelUp)
    {
        nClass += nUp;
        if (nClass >= *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_petClass)->Get())
        {
            nClass = (unsigned short)*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_petClass)->Get();
            nExp = 0;
        }
    }
    *pExp = nExp;
    *pClass = nClass;
}

// @0x140cb5600
void TabContentsPetCompose::FUN_140cb5600()
{
    m_petCards.RemoveAll();
    m_candidates.RemoveAll();
    m_pool.RemoveAll();
    m_selected.RemoveAll();
    ATL::CAtlArray<unsigned __int64> pets;
    g_143ab2a90.FUN_140a609a0(9, pets);
    for (unsigned i = 0; i < pets.GetCount(); i++)
    {
        ItemPtr item = g_143ab2a90.FUN_140a5d680(pets[i]);
        if (item == 0)
            continue;
        MS2Ptr<CPetData> row = TSingleton<CPetDataTable>::GetInstance()->Find(((class CItemData*)(class Unk_ItemEquipData*)(item->FUN_140527840()))->GetPetId());
        if (row == 0)
            continue;
        if (row->m_nType == 0)
            continue;
        m_petCards.Add(item->GetItemUid());
    }
    ATL::CAtlArray<unsigned __int64> others;
    g_143ab2a90.FUN_140a609a0(3, others);
    for (unsigned i = 0; i < others.GetCount(); i++)
    {
        ItemPtr item = g_143ab2a90.FUN_140a5d680(others[i]);
        if (item == 0)
            continue;
        MS2Ptr<CItemData> data(item->FUN_140527840());
        if (data == 0)
            continue;
        if (data->GetStringTag() != 0xd8)
            continue;
        m_candidates.Add(item->GetItemUid());
    }
}

// @0x140cb5970
void TabContentsPetCompose::FUN_140cb5970()
{
    m_pool.RemoveAll();
    m_selected.RemoveAll();
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    for (unsigned i = 0; i < m_petCards.GetCount(); i++)
    {
        unsigned __int64 id = m_petCards[i];
        if (reinterpret_cast<CPetManager*>(FUN_140535320())->GetSummonUid() == id)
            continue;
        if (m_uidPet == id)
            continue;
        m_pool.Add(FUN_140cb65d0(id));
    }
    for (unsigned i = 0; i < m_candidates.GetCount(); i++)
    {
        unsigned __int64 id = m_candidates[i];
        if (reinterpret_cast<CPetManager*>(FUN_140535320())->GetSummonUid() == id)
            continue;
        if (m_uidPet == id)
            continue;
        ItemPtr item = g_143ab2a90.FUN_140a5d680(id);
        if (item == 0)
            continue;
        int nCount = FUN_140cb6450(id);
        m_pool.Add(IdCount(id, nCount));
    }
}

// @0x140cb5bd0
void TabContentsPetCompose::FUN_140cb5bd0()
{
    m_selected.RemoveAll();
}

// @0x140cb5c00
void TabContentsPetCompose::FUN_140cb5c00(int nIndex)
{
    if (nIndex < 0 || nIndex >= (int)m_petCards.GetCount())
        return;
    m_uidPet = m_petCards[nIndex];
    FUN_140cb5970();
    FUN_140cb5bd0();
    vfunc_2(10);
}

// @0x140cb5c90
void TabContentsPetCompose::FUN_140cb5c90(int nIndex)
{
    if (nIndex < 0 || nIndex >= (int)m_pool.GetCount())
        return;
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    __int64 nExp = ((class CItem*)(class CItem*)(pet))->FUN_140528b90();
    unsigned short nPetClass = ((class CItem*)(class CItem*)(pet))->FUN_140528c20();
    FUN_140cb5300(&nPetClass, &nExp);
    IdCount& entry = m_pool[nIndex];
    unsigned __int64 id = entry.first;
    ItemPtr item = g_143ab2a90.FUN_140a5d680(id);
    if (item == 0)
        return;
    __int64 nPrice = ((class CItem*)(class CItem*)(item))->FUN_140528e00();
    if (((class CItem*)(class CItem*)(item))->FUN_140528c60() != 0)
    {
        FUN_1412752d0(L"s_err_cannot_compose_petitem_hasitem", 1);
    }
    else if (((class CItem*)(class CItem*)(item))->FUN_140528ca0() == 0 && nPrice > GetServerTime())
    {
        FUN_1412752d0(L"s_itemlock_invalid_petcompose", 1);
    }
    else if (((class CItem*)(class CItem*)(item))->FUN_140528ca0() == 1)
    {
        FUN_1412752d0(L"s_itemlock_invalid_petcompose", 1);
    }
    else
    {
        if (nPetClass < *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PetConfig*)FUN_1401d3200())->m_petClass)->Get())
        {
            const int nMax = 12;
            if (m_selected.GetCount() >= nMax)
                return;
            if (FUN_140cb62e0(id) != 0)
                vfunc_2(0xb);
        }
        else
        {
            FUN_1412752d0(L"s_pet_not_enchant", 1);
        }
    }
}

// @0x140cb5fd0
void TabContentsPetCompose::FUN_140cb5fd0(int nIndex)
{
    if (nIndex < 0 || nIndex >= (int)m_selected.GetCount())
        return;
    ItemPtr pet = g_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    FUN_140cb6180(nIndex);
    vfunc_2(0xb);
}

// @0x140cb6080
int TabContentsPetCompose::FUN_140cb6080(ATL::CAtlArray<IdCount>& arr, unsigned __int64 id)
{
    for (size_t i = 0; i < arr.GetCount(); i++)
    {
        IdCount& entry = arr[i];
        if (id == entry.first)
            return (int)i;
    }
    return -1;
}

// @0x140cb6100
unsigned __int64 TabContentsPetCompose::FUN_140cb6100(ATL::CAtlArray<IdCount>& arr, int nIndex)
{
    if (nIndex < 0)
        return 0;
    for (size_t i = 0; i < arr.GetCount(); i++)
    {
        if (i == (size_t)nIndex)
        {
            IdCount& entry = arr[i];
            return entry.first;
        }
    }
    return 0;
}

// @0x140cb6180
int TabContentsPetCompose::FUN_140cb6180(int nIndex)
{
    const unsigned __int64 id = FUN_140cb6100(m_selected, nIndex);
    ItemPtr item = g_143ab2a90.FUN_140a5d680(id);
    if (item.get() != 0)
    {
        m_selected.RemoveAt(nIndex, 1);
        int nPos = FUN_140cb6080(m_pool, id);
        if (nPos > -1)
        {
            IdCount& e = m_pool[nPos];
            e.second++;
        }
        else
        {
            int nOne = 1;
            m_pool.Add(IdCount(id, nOne));
        }
        return 1;
    }
    return 0;
}

// @0x140cb62e0
int TabContentsPetCompose::FUN_140cb62e0(unsigned __int64 id)
{
    int nPos = FUN_140cb6080(m_pool, id);
    if (nPos < 0)
        return 0;
    unsigned nAvail = FUN_140cb6450(id);
    if (nAvail < 1)
        return 0;
    IdCount& entry = m_pool[nPos];
    int& nCount = entry.second;
    nCount--;
    if (nCount == 0)
        m_pool.RemoveAt(nPos, 1);
    ItemPtr item = g_143ab2a90.FUN_140a5d680(id);
    if (item.get())
    {
        m_selected.Add(FUN_140cb65d0(id));
        return 1;
    }
    return 0;
}

// @0x140cb6450
int TabContentsPetCompose::FUN_140cb6450(unsigned __int64 id)
{
    ItemPtr item = g_143ab2a90.FUN_140a5d680(id);
    if (item == 0)
        return 0;
    unsigned nHave = g_143ab2a90.FUN_140a5f060(item->GetItemUid());
    if (nHave == 0)
        return 0;
    int nUsed = 0;
    for (unsigned i = 0; i < m_selected.GetCount(); i++)
    {
        IdCount& e = m_selected[i];
        if (e.first == id)
            nUsed += e.second;
    }
    if (nHave > (unsigned)nUsed)
        return nHave - nUsed;
    return 0;
}

// @0x140cb86b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca3cb0-0x142ca3da0 .text$yd
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca3da0-0x142ca3dc0 .text$yd
