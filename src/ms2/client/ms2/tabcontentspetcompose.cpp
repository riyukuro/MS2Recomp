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
#include "ms2/placeholder/ms2stdafx.h"

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

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

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
static Unk_1402a9d70 s_marker(17, 0.75f, 0.25f, 2.25f, 10);   // atexit thunk FUN_142ca3da0
#endif

// ---- unit-local placeholders (the names of the classes shared with tabcontentspetevolution.cpp must stay identical:
// the Unk_PetButton / Unk_PetItemBag members it instantiates are the ones this unit calls) ----

// A Scaleform value seen through its "is this an object" test (the exe calls one shared function on it).
class Unk_PetValueView { public: bool FUN_1409b4d40() const; };

// A pet menu button (m_submit, ...): a movie clip with a frame setter.
class Unk_PetButton : public ASMovieClip
{
public:
    Unk_PetButton(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422cdde0
    void FUN_1422c1fe0(unsigned int nFrame);                            // go to the state frame
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_PetButton, 0x88);

// The item bag control inside a section clip.
class Unk_PetItemBag : public ASMovieClip
{
public:
    Unk_PetItemBag(const Scaleform::GFx::Value& v, int nMovieId);       // 0x1422cf330
#define PB_V(n) virtual void vfunc_##n();
    PB_V(16) PB_V(17) PB_V(18) PB_V(19) PB_V(20) PB_V(21) PB_V(22) PB_V(23)
#undef PB_V
    virtual void vfunc_24(int nShow);                                   // 24 (+0xc0) refresh
    void FUN_1407cba60(const char* szName, CString str);                // set the bag id
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_PetItemBag, 0x88);

// A record of the equip data table; the int at +0x18 is zero for plain items.
class Unk_PetRow : public CPtred
{
public:
    int m_nFlag;                                                        // +0x18
};
extern template class MS2Ptr<Unk_PetRow>;
class Unk_PetRowTable { public: MS2Ptr<Unk_PetRow> FUN_1407290f0(int nKey); };
Unk_PetRowTable* FUN_14052d210();
int FUN_14053dc60(Unk_ItemEquipData* pData);                            // key of the equip data

// CItem::FUN_140527840's record (as commonfiles\item.cpp): the item data, of which this unit reads the type and the
// function arguments (+0x2b0, the arguments of the item's <function>).
class Unk_ItemEquipData : public CItemData {};
class Unk_ComposeArgs
{
public:
    unsigned FUN_1408d2380();                                           // the argument count
    int FUN_1408d1fd0(int nIndex, int nDefault);                        // the nIndex-th argument as a number
};
class Unk_ComposeItemView : public CPtred
{
public:
    unsigned char m_pad_18[0x298];
    Unk_ComposeArgs m_args;                                             // +0x2b0
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
    int FUN_141663a20();                                                // how many pet composes the player did
};
class Unk_PetPlayerMgr { public: Unk_PetPlayer* FUN_141bd0cc0(); };
Unk_PetPlayerMgr* FUN_1403ed2d0();

// Exp table of the pets (the exp a class needs for the next one).
class Unk_PetTable { public: __int64 FUN_140353930(unsigned short nPetClass, int nRank, unsigned short nItemClass); };
Unk_PetTable* FUN_1404a1bb0();

// Recipe table (the compose exp and cost of an ingredient).
class Unk_PetRecipe
{
public:
    __int64 FUN_1406790e0(int nRank);                                   // cost of a plain ingredient
    __int64 FUN_140679260(int nPetRank, int nItemRank, unsigned short nPetClass, __int64 nExp);   // cost of a pet ingredient
    void FUN_140678e80(int nPetRank, int nItemRank, unsigned short nPetClass, __int64 nExp, int nCount, unsigned nMax,
                       unsigned short nItemClass, __int64* pBase, __int64* pBonus);   // exp of a pet ingredient
};
Unk_PetRecipe* FUN_1401c0db0();
CGameRule* FUN_1401c0d90();                                             // TSingleton<CGameRule>::GetInstance

// Feature flags (slot 0x37 turns the compose off).
class Unk_PetFlag { public: int FUN_1402c4c90(int nFlag); };
class Unk_PetFlags { public: void* p0; Unk_PetFlag flags; };
Unk_PetFlags* FUN_14025e7b0();

// Client configuration: the pet class that may be composed sits at +0x84c0, the compose bonus limit at +0x8d18.
class Unk_PetUIntSlot { public: unsigned* FUN_1401d7c10(); };
class Unk_PetConfig
{
public:
    unsigned char m_pad[0x84c0];
    Unk_PetUIntSlot m_petClass;
    unsigned char m_pad_84c4[0x8d18 - 0x84c0 - sizeof(Unk_PetUIntSlot)];
    Unk_PetUIntSlot m_bonusLimit;
};
Unk_PetConfig* FUN_1401d3200();
unsigned* FUN_1401d7c10(Unk_PetUIntSlot* pSlot);

// The item picked in the inventory dialog.
class Unk_PetSelected { public: __int64 FUN_140c8b2e0(); };
Unk_PetSelected* FUN_140535320();

// The bind state of an item.
class Unk_PetBind { public: int FUN_140635100(); int FUN_140635120(); };

// CItem accessors the exe calls as free functions.
unsigned short FUN_1405282d0(CItem* pItem);                             // item class
unsigned short FUN_140528c20(CItem* pItem);                             // pet class
__int64 FUN_140528b90(CItem* pItem);                                    // pet exp
Unk_PetBind* FUN_140527930(CItem* pItem);
struct Unk_PeItemView { CStringW FUN_140527b10(); };                    // item name (CItem member: this=rcx, hidden return=rdx)
__int64 FUN_140528e00(CItem* pItem);                                    // item price
int FUN_140528c60(CItem* pItem);
int FUN_140528ca0(CItem* pItem);                                        // item lock state
int FUN_140525640(CItem* pItem);                                        // is a pet
__int64 FUN_140869440();                                                // server time

// Message box (same entry points as inventory.cpp).
class CMsgBoxData;
extern template class MS2Ptr<CMsgBoxData>;                              // the message box type is defined in another unit
MS2Ptr<CMsgBoxData> FUN_140d73d20(int, CStringW, void*, CStringW);
void FUN_141a01600(CMsgBoxData*, __int64);
void FUN_141a01ee0(CMsgBoxData*, MS2Ptr<CItem>, const CStringW&, int, int, int, int, int);
void FUN_141a01700(CMsgBoxData*, int, int, int);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);

// Item bag registry (the section's bag ids).
void FUN_140b77500(CString* pBag);                                      // release a card bag
void FUN_140b773a0(CString* pBag, ATL::CAtlArray<unsigned __int64>& ids);
void FUN_140b77e50(CString* pBag);                                      // release an ingredient bag
void FUN_140b77cf0(CString* pBag, ATL::CAtlArray<TabContentsPetCompose::IdCount>& items);

// UI helpers.
void FUN_141276180(const CString& strSound, const CString& strArg);     // play a UI sound
void FUN_1412752d0(const CStringW& strMsg, int nType);                  // chat/system notice
void FUN_141275260(int nMsgId, int a1, int a2);

// String helpers.
CStringW FUN_140938ae0(CStringW fmt, const int& a);
CStringW FUN_14062b4f0(CStringW fmt, const int* pn);
CStringW FUN_1409e8820(CStringW fmt, const unsigned short& n);
CStringW FUN_1408f71a0(CStringW fmt, const CStringW& a, const CStringW& b);
CStringW FUN_1409404f0(__int64 n);                                      // number with separators
CStringW FUN_14052bd00(int nStringId, const CStringW& str);
CStringW FUN_1408116a0(int nStringId, const int& n);
CStringW FUN_1405c2690(CStringW fmt, const CStringW& arg);
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);   // string table text, formatted
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

void FUN_140710590(COutPacket& pkt);                                    // send

// The Value setter the (int64, int64) Invoke helper uses.
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);

extern Unk_Inventory DAT_143ab2a90;
typedef MS2Ptr<CItem> ItemPtr;
typedef TabContentsPetCompose::IdCount IdCount;

// ---- glue: AS child control binding (the specializations and the Value helpers are COMDATs of the evolution unit) ----

template <> MS2Ptr<Unk_PetButton> AScript::FUN_140acce30<Unk_PetButton>(const CString& strName);       // 0x140acce30
template <> MS2Ptr<Unk_PetItemBag> AScript::FUN_140accef0<Unk_PetItemBag>(const CString& strName);     // 0x140accef0
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

// @0x140cb6df0
inline PetComposePetCard::~PetComposePetCard() = default;

// @0x140cb6e20
inline PetComposePetEnchant::~PetComposePetEnchant()
{
}

// @0x140cb6e60
inline PetComposePetIngredient::~PetComposePetIngredient()
{
}

// @0x140cb6e90
inline TabContentsPetCompose::~TabContentsPetCompose()
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

// @0x140cb6610
IdCount FUN_140cb6610(unsigned __int64& id, int& n)
{
    return std::make_pair(id, n);
}

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
    FUN_140b77500(&m_strBag);
}

// @0x140cb1e60
void PetComposePetCard::vfunc_4()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> card = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petCard"));
    if (card == 0)
        return;
    MS2Ptr<Unk_PetItemBag> bag = card->FUN_140accef0<Unk_PetItemBag>(CString("m_itemBag"));
    if (bag.get() == 0)
        return;
    ATL::CAtlArray<unsigned __int64> ids;
    m_pOwner->FUN_140cb47d0(ids);
    FUN_140b77500(&m_strBag);
    FUN_140b773a0(&m_strBag, ids);
    bag->FUN_1407cba60("bagId", m_strBag);
    bag->vfunc_24(1);
}

// @0x140cb2060
void PetComposePetCard::vfunc_5(int nTab)
{
    if (0 < nTab && (nTab < 3 || nTab == 0xc))
        vfunc_4();
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
    FUN_140b77e50(&m_strBag);
}

// @0x140cb2150
void PetComposePetIngredient::vfunc_4()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ingredient = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petIngredient"));
    if (ingredient == 0)
        return;
    MS2Ptr<Unk_PetItemBag> bag = ingredient->FUN_140accef0<Unk_PetItemBag>(CString("m_itemBag"));
    if (bag.get() == 0)
        return;
    ATL::CAtlArray<IdCount> items;
    m_pOwner->FUN_140cb4830(items);
    FUN_140b77e50(&m_strBag);
    FUN_140b77cf0(&m_strBag, items);
    bag->FUN_1407cba60("bagId", m_strBag);
    bag->vfunc_24(1);
}

// @0x140cb2350
void PetComposePetIngredient::vfunc_5(int nTab)
{
    if (0 < nTab && (nTab < 3 || (9 < nTab && nTab < 0xd)))
        vfunc_4();
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
    FUN_140b77e50(&m_strBag);
    FUN_140b77500(&m_strTarget);
}

// @0x140cb2470
void PetComposePetEnchant::vfunc_3()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140cb47b0());
    if (pet == 0)
        return;
    __int64 nExp = FUN_140528b90(pet);
    unsigned short nPetClass = FUN_140528c20(pet);
    {
        if (MS2Ptr<Unk_PetButton> submit = ench->FUN_140acce30<Unk_PetButton>(CString("m_submit")))
        {
            ATL::CAtlArray<IdCount> selected;
            m_pOwner->FUN_140cb4860(selected);
            unsigned nClass = nPetClass;
            if (nClass < *FUN_1401d7c10(&FUN_1401d3200()->m_petClass) && selected.GetCount() != 0)
                submit->FUN_1422c1fe0(1);
            else
                submit->FUN_1422c1fe0(0);
        }
    }
    if (MS2Ptr<ASUIComponent> bar = ench->FUN_140accfb0<ASUIComponent>(CString("m_expBar")))
    {
        m_pOwner->FUN_140cb5300(&nPetClass, &nExp);
        unsigned nClass = nPetClass;
        if (nClass < *FUN_1401d7c10(&FUN_1401d3200()->m_petClass))
        {
            unsigned short nItemClass = FUN_1405282d0(pet);
            int nRank = pet->FUN_140526bd0();
            __int64 nNeed = FUN_1404a1bb0()->FUN_140353930(nPetClass, nRank, nItemClass);
            CStringW strLevel;
            strLevel.Format(L"%s", (LPCWSTR)FUN_1409e8820(CStringW(L"s_word_petlevel"), nPetClass));
            CStringW strCount;
            strCount.Format(L"%s", (LPCWSTR)FUN_1408f71a0(CStringW(L"s_common_cur_max_ingredient"), FUN_1409404f0(nExp), FUN_1409404f0(nNeed)));
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
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    {
        MS2Ptr<Unk_PetItemBag> bag = ench->FUN_140accef0<Unk_PetItemBag>(CString("m_itemBag"));
        if (bag.get() != 0)
        {
            ATL::CAtlArray<IdCount> items;
            m_pOwner->FUN_140cb4860(items);
            FUN_140b77e50(&m_strBag);
            FUN_140b77cf0(&m_strBag, items);
            bag->FUN_1407cba60("bagId", m_strBag);
            bag->vfunc_24(1);
        }
    }
    {
        MS2Ptr<Unk_PetButton> submit = ench->FUN_140acce30<Unk_PetButton>(CString("m_submit"));
        if (submit.get() != 0)
            submit->FUN_1422c1fe0(0);
    }
    ASObj obj(2);
    obj.FUN_1409c0dc0("sale", "");
    int nZero = 0;
    obj.FUN_1407cbb20(s_meso, FUN_1408116a0(0x986, nZero));
    ench->FUN_140acd1f0("selectPetIngredient", AScript(obj));
}

// @0x140cb2ee0
void PetComposePetEnchant::vfunc_5(int nTab)
{
    if (0 < nTab)
    {
        if (nTab < 3 || nTab == 10)
        {
            vfunc_4();
            vfunc_3();
            FUN_140cb2fb0();
        }
        else if (nTab == 0xb)
        {
            vfunc_4();
            vfunc_3();
            FUN_140cb34b0();
        }
        else if (nTab == 0xc)
        {
            vfunc_4();
            vfunc_3();
            FUN_140cb3a30();
        }
    }
}

// The compose bonus: how far the player's counter is below the configured limit (never negative).
static int Unk_ComposeBonus(Unk_PetPlayer* player)
{
    int nBonus;
    if ((int)*FUN_1401d7c10(&FUN_1401d3200()->m_bonusLimit) - player->FUN_141663a20() < 0)
        nBonus = 0;
    else
        nBonus = (int)*FUN_1401d7c10(&FUN_1401d3200()->m_bonusLimit) - player->FUN_141663a20();
    return nBonus;
}

#ifndef MS2_HOOK_DLL
// @0x140cb2fb0
void PetComposePetEnchant::FUN_140cb2fb0()
{
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0 || m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140cb47b0());
    if (pet == 0)
        return;
    ATL::CAtlArray<unsigned __int64> ids;
    ids.Add(m_pOwner->FUN_140cb47b0());
    FUN_140b77500(&m_strBag);
    FUN_140b773a0(&m_strTarget, ids);
    int nBonus = Unk_ComposeBonus(player);
    ASObj obj(2);
    obj.FUN_1407cbb20(s_itemName, reinterpret_cast<Unk_PeItemView*>(pet.get())->FUN_140527b10());
    obj.FUN_1409c48f0(s_itemLevel, FUN_140528c20(pet));
    obj.FUN_1409c0dc0("sale", "");
    obj.FUN_1407cbb20("bonus", FUN_14062b4f0(CStringW(L"s_pet_compose_exp_bonus"), &nBonus));
    int nZero = 0;
    obj.FUN_1407cbb20(s_meso, FUN_1408116a0(0x986, nZero));
    obj.FUN_1409c1180("petExp", FUN_140528b90(pet));
    obj.FUN_1407cba60("bagId", m_strTarget);
    ench->FUN_140acd1f0("selectPetCard", AScript(obj));
    FUN_141276180(CString("pet_Button_Click"), CString(""));
}
#endif

// @0x140cb34b0
void PetComposePetEnchant::FUN_140cb34b0()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140cb47b0());
    if (pet == 0)
        return;
    ATL::CAtlArray<IdCount> selected;
    m_pOwner->FUN_140cb4860(selected);
    __int64 nTotal = 0;
    for (unsigned i = 0; i < selected.GetCount(); i++)
    {
        unsigned __int64 id = selected[i].first;
        unsigned nCount = selected[i].second;
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
        if (!(item == 0))
        {
            __int64 nCost = 0;
            if (FUN_140525640(item) == 0)
            {
                int nRank = pet->FUN_140526bd0();
                nCost = FUN_1401c0db0()->FUN_1406790e0(nRank);
            }
            else
            {
                __int64 nExp = FUN_140528b90(item);
                unsigned short nClass = FUN_140528c20(item);
                int nItemRank = item->FUN_140526bd0();
                int nPetRank = pet->FUN_140526bd0();
                nCost = FUN_1401c0db0()->FUN_140679260(nPetRank, nItemRank, nClass, nExp);
            }
            nTotal += FUN_1401c0d90()->FUN_14047f670(nCost) * nCount;
        }
    }
    ASObj obj(2);
    int nSale = (int)((float)(FUN_1401c0d90()->FUN_14047f520() / 100) + 0.5f);
    if (nSale != 0)
        obj.FUN_1407cbb20("sale", FUN_140938ae0(CStringW(L"s_pet_compose_cost_sale"), nSale));
    obj.FUN_1407cbb20(s_meso, FUN_14052bd00(0x986, FUN_1409404f0(nTotal)));
    ench->FUN_140acd1f0("selectPetIngredient", AScript(obj));
    FUN_141276180(CString("pet_Button_Click"), CString(""));
}

// @0x140cb3a30
void PetComposePetEnchant::FUN_140cb3a30()
{
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0 || m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140cb47b0());
    if (pet == 0)
        return;
    int nBonus = Unk_ComposeBonus(player);
    ASObj obj(2);
    obj.FUN_1407cbb20("bonus", FUN_14062b4f0(CStringW(L"s_pet_compose_exp_bonus"), &nBonus));
    obj.FUN_1407cbb20("successMsg", FUN_14028dfa0(CStringW(L"s_pet_compose_compose_success"), m_pOwner->m_nGainBase, m_pOwner->m_nGainBonus));
    ench->FUN_140acd1f0("selectPetEnchant", AScript(obj));
}

// ---- TabContentsPetCompose ----

// @0x140cb3db0
// MS2-FUNCTIONAL: the exe zeroes the first 0x18 bytes (rep stosb) before the base constructor
TabContentsPetCompose::TabContentsPetCompose()
    : m_uidPet(0), m_parts(10), m_nGainBase(0), m_nGainBonus(0), m_ui(0)
{
    m_parts.AddTail(MS2Ptr<PetComposeBase>(new PetComposePetCard(this)));
    m_parts.AddTail(MS2Ptr<PetComposeBase>(new PetComposePetIngredient(this)));
    m_parts.AddTail(MS2Ptr<PetComposeBase>(new PetComposePetEnchant(this)));
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
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140cb5c00(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnSelectPetIngredient", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140cb5c90(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnSelectPetEnchant", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140cb5fd0(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnPetEnchant", szEvent) == 0)
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
unsigned __int64 TabContentsPetCompose::FUN_140cb47b0()
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
// MS2-FUNCTIONAL: frame layout of the message box and packet branches differs
void TabContentsPetCompose::FUN_140cb48a0(int bUsePoint)
{
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    if (m_selected.IsEmpty())
        return;
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0)
        return;
    if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x37) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return;
    }
    if (bUsePoint == 0)
    {
        if (FUN_140527930(pet)->FUN_140635100() != 0 && FUN_140527930(pet)->FUN_140635120() == 0)
        {
            CStringW strMsg = FUN_1405c2690(L"s_msg_transfer_bind_pet_compose", player->vfunc_77());
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x11, strMsg, 0, s_composeBindPet);
            if (box.get() != 0)
            {
                FUN_141a01600(box.operator->(), pet->FUN_140526a50());
                FUN_141a01ee0(box.operator->(), ItemPtr(pet), reinterpret_cast<Unk_PeItemView*>(pet.get())->FUN_140527b10(), 1, 0, -1, -1, 1);
                FUN_141a01700(box.operator->(), 0x477, 0x478, 0);
                FUN_140d73c60(box);
                return;
            }
        }
    }
    ATL::CRBMap<unsigned __int64, int> counts(10);
    for (size_t i = 0; i < m_selected.GetCount(); i++)
    {
        unsigned __int64 id = m_selected[i].first;
        int nCount = m_selected[i].second;
        int nSum = 0;
        counts.Lookup(id, nSum);
        nSum += nCount;
        counts.SetAt(id, nSum);
    }
    COutPacket pkt(0x78, 0);
    pkt.Encode1(0xc);
    pkt.Encode8(m_uidPet);
    pkt.Encode2((short)counts.GetCount());
    POSITION pos = counts.GetHeadPosition();
    while (pos != 0)
    {
        pkt.Encode8(counts.GetKeyAt(pos));
        pkt.Encode4(counts.GetValueAt(pos));
        counts.GetNext(pos);
    }
    FUN_140710590(pkt);
    FUN_140cb4ed0(&m_nGainBase, &m_nGainBonus);
}

// @0x140cb4ed0
void TabContentsPetCompose::FUN_140cb4ed0(__int64* pBase, __int64* pBonus)
{
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(FUN_140cb47b0());
    if (pet == 0)
        return;
    *pBase = 0;
    *pBonus = 0;
    ATL::CAtlArray<IdCount> selected;
    FUN_140cb4860(selected);
    int nCounter = player->FUN_141663a20();
    unsigned nLimit = *FUN_1401d7c10(&FUN_1401d3200()->m_bonusLimit);
    for (size_t i = 0; i < selected.GetCount(); i++)
    {
        unsigned __int64 id = selected[i].first;
        unsigned nCount = selected[i].second;
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
        if (!(item == 0))
        {
            MS2Ptr<CItemData> data(item->FUN_140527840());
            if (!(data == 0))
            {
                unsigned __int64 nBase = 0;
                __int64 nBonus = 0;
                if (FUN_140525640(item) == 0)
                {
                    if (data->FUN_14053c6f0() == 0xd8)
                    {
                        Unk_ComposeItemView* view = reinterpret_cast<Unk_ComposeItemView*>(data.operator->());
                        if (view->m_args.FUN_1408d2380() != 0)
                            nBase = view->m_args.FUN_1408d1fd0(0, 0);
                    }
                }
                else
                {
                    unsigned short nItemClass = FUN_1405282d0(item);
                    __int64 nExp = FUN_140528b90(item);
                    unsigned short nClass = FUN_140528c20(item);
                    int nItemRank = item->FUN_140526bd0();
                    int nPetRank = pet->FUN_140526bd0();
                    FUN_1401c0db0()->FUN_140678e80(nPetRank, nItemRank, nClass, nExp, nCounter, nLimit, nItemClass, (__int64*)&nBase, &nBonus);
                    nCounter = nCounter + 1;
                }
                *pBase = nBase * nCount + *pBase;
                *pBonus = nBonus * nCount + *pBonus;
            }
        }
    }
}

// @0x140cb5300
void TabContentsPetCompose::FUN_140cb5300(unsigned short* pClass, __int64* pExp)
{
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(FUN_140cb47b0());
    if (pet == 0)
        return;
    unsigned short nClass = FUN_140528c20(pet);
    __int64 nExp = FUN_140528b90(pet);
    int nRank = pet->FUN_140526bd0();
    unsigned nClass2 = nClass;
    if (!(nClass2 < *FUN_1401d7c10(&FUN_1401d3200()->m_petClass)))
        return;
    __int64 nBase = 0;
    __int64 nBonus = 0;
    FUN_140cb4ed0(&nBase, &nBonus);
    __int64 nGain = nBase + nBonus;
    if (nGain < 0 && nExp <= _abs64(nGain))
        nExp = 0;
    else
        nExp = nExp + nGain;
    unsigned short nItemClass = FUN_1405282d0(pet);
    __int64 nNeed = FUN_1404a1bb0()->FUN_140353930(nClass, nRank, nItemClass);
    unsigned short nUp = 0;
    while (nNeed <= nExp)
    {
        nExp = nExp - nNeed;
        nUp = nUp + 1;
        nItemClass = FUN_1405282d0(pet);
        unsigned nNext = (unsigned)nClass + (unsigned)nUp;
        nNeed = FUN_1404a1bb0()->FUN_140353930(nNext & 0xffff, nRank, nItemClass);
    }
    if (nUp != 0)
    {
        nClass = nClass + nUp;
        unsigned nClass3 = nClass;
        if (*FUN_1401d7c10(&FUN_1401d3200()->m_petClass) <= nClass3)
        {
            nClass = (unsigned short)*FUN_1401d7c10(&FUN_1401d3200()->m_petClass);
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
    DAT_143ab2a90.FUN_140a609a0(9, pets);
    for (unsigned i = 0; i < pets.GetCount(); i++)
    {
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(pets[i]);
        if (!(item == 0))
        {
            int nKey = FUN_14053dc60(item->FUN_140527840());
            MS2Ptr<Unk_PetRow> row = FUN_14052d210()->FUN_1407290f0(nKey);
            if (!(row == 0))
            {
                if (row->m_nFlag != 0)
                    m_petCards.Add(item->FUN_140526a50());
            }
        }
    }
    ATL::CAtlArray<unsigned __int64> others;
    DAT_143ab2a90.FUN_140a609a0(3, others);
    for (unsigned i = 0; i < others.GetCount(); i++)
    {
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(others[i]);
        if (!(item == 0))
        {
            MS2Ptr<CItemData> data(item->FUN_140527840());
            if (!(data == 0))
            {
                if (data->FUN_14053c6f0() == 0xd8)
                    m_candidates.Add(item->FUN_140526a50());
            }
        }
    }
}

// @0x140cb5970
void TabContentsPetCompose::FUN_140cb5970()
{
    m_pool.RemoveAll();
    m_selected.RemoveAll();
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    for (unsigned i = 0; i < m_petCards.GetCount(); i++)
    {
        unsigned __int64 id = m_petCards[i];
        if (FUN_140535320()->FUN_140c8b2e0() == id)
            continue;
        if (m_uidPet == id)
            continue;
        m_pool.Add(FUN_140cb65d0(id));
    }
    for (unsigned i = 0; i < m_candidates.GetCount(); i++)
    {
        unsigned __int64 id = m_candidates[i];
        if (FUN_140535320()->FUN_140c8b2e0() == id)
            continue;
        if (m_uidPet == id)
            continue;
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
        if (item == 0)
            continue;
        int nCount = FUN_140cb6450(id);
        m_pool.Add(FUN_140cb6610(id, nCount));
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
    if (!(-1 < nIndex && nIndex < (int)m_petCards.GetCount()))
        return;
    m_uidPet = m_petCards[nIndex];
    FUN_140cb5970();
    FUN_140cb5bd0();
    vfunc_2(10);
}

// @0x140cb5c90
void TabContentsPetCompose::FUN_140cb5c90(int nIndex)
{
    if (!(-1 < nIndex && nIndex < (int)m_pool.GetCount()))
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    __int64 nExp = FUN_140528b90(pet);
    unsigned short nPetClass = FUN_140528c20(pet);
    FUN_140cb5300(&nPetClass, &nExp);
    unsigned __int64 id = m_pool[nIndex].first;
    ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
    if (item == 0)
        return;
    __int64 nPrice = FUN_140528e00(item);
    if (FUN_140528c60(item) != 0)
    {
        FUN_1412752d0(CStringW(L"s_err_cannot_compose_petitem_hasitem"), 1);
    }
    else if (FUN_140528ca0(item) == 0 && FUN_140869440() < nPrice)
    {
        FUN_1412752d0(CStringW(L"s_itemlock_invalid_petcompose"), 1);
    }
    else if (FUN_140528ca0(item) == 1)
    {
        FUN_1412752d0(CStringW(L"s_itemlock_invalid_petcompose"), 1);
    }
    else
    {
        unsigned nClass = nPetClass;
        if (nClass < *FUN_1401d7c10(&FUN_1401d3200()->m_petClass))
        {
            unsigned nMax = 0xc;
            if (11 < m_selected.GetCount())
                return;
            if (FUN_140cb62e0(id) != 0)
                vfunc_2(0xb);
        }
        else
        {
            FUN_1412752d0(CStringW(L"s_pet_not_enchant"), 1);
        }
    }
}

// @0x140cb5fd0
void TabContentsPetCompose::FUN_140cb5fd0(int nIndex)
{
    if (!(-1 < nIndex && nIndex < (int)m_selected.GetCount()))
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
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
        if (id == arr[i].first)
            return (int)i;
    }
    return -1;
}

// @0x140cb6100
unsigned __int64 TabContentsPetCompose::FUN_140cb6100(ATL::CAtlArray<IdCount>& arr, int nIndex)
{
    if (-1 < nIndex)
    {
        for (size_t i = 0; i < arr.GetCount(); i++)
        {
            if (i == (size_t)nIndex)
                return arr[i].first;
        }
    }
    return 0;
}

// @0x140cb6180
int TabContentsPetCompose::FUN_140cb6180(int nIndex)
{
    const unsigned __int64 id = FUN_140cb6100(m_selected, nIndex);
    ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
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
    ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
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
    ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
    if (item == 0)
        return 0;
    unsigned nHave = DAT_143ab2a90.FUN_140a5f060(item->FUN_140526a50());
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
