// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Pet option remake tab of the pet system dialog (sibling of
// tabcontentspetcompose.cpp / tabcontentspetevolution.cpp: a pet card list, an ingredient list and a board that shows
// the current and the remade options; packet 0x75 like the item option remake dialog, unit_14129cfa0.cpp).
// MS2-UNIT: ?\tabcontentspetremakeoption.cpp
// MS2-RANGE: 0x140b914f0-0x140b9b440 .text$mn
// MS2-RANGE: 0x1400c9520-0x1400c9750 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_itemLevel@@YAXXZ 0x1400c9520 ; probe
// MS2-PIN: ??__Es_itemName@@YAXXZ 0x1400c9550 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400c9670 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400c96a0 ; probe
// MS2-PIN: ??$?0AEA_JAEAI$0A@@?$pair@_KH@std@@QEAA@AEA_JAEAI@Z 0x140b98bd0 ; unique
// MS2-PIN: ??0Unk_RemakeLockOpt@@QEAA@XZ 0x140b98d30 ; unique
// MS2-PIN: ??$StringFormat@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@_K@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBV01@AEB_K@Z 0x140b98e10 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VASTextField@@@@QEBAPEAVASTextField@@XZ 0x140b9a800 ; prop
// MS2-PIN: ?vfunc_4@PetRemakeOptionBase@@UEAAXXZ 0x140b9aab0 ; unique
// MS2-PIN: ?vfunc_7@PetRemakeOptionBase@@UEAAXH@Z 0x140b9ae40 ; unique
// MS2-PIN: ?vfunc_1@PetRemakeOptionBase@@UEAAXXZ 0x140b9ae50 ; unique
// MS2-PIN: ?vfunc_2@PetRemakeOptionBase@@UEAAXXZ 0x140b9ae60 ; unique
// MS2-PIN: ?vfunc_6@PetRemakeOptionBase@@UEAAXV?$MS2Ptr@VCItem@@@@0@Z 0x140b9ae70 ; unique
// MS2-PIN: ?vfunc_5@PetRemakeOptionBase@@UEAAXH@Z 0x140b9aea0 ; unique
// MS2-PIN: ?Release@?$MS2Ptr@VPetRemakeOptionBase@@@@AEAAXXZ 0x140b9b1c0 ; unique
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VPetRemakeOptionBoard@@@@AEAAXPEAX@Z 0x140b9b290 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??$format_arg@_WW4Unk_RemakeError@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_RemakeError@@@Z 0x140b9a000
// MS2-PIN: ??C?$MS2Ptr@VPetRemakeOptionBoard@@@@QEBAPEAVPetRemakeOptionBoard@@XZ 0x140b9a820
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\tabcontentspetremakeoption.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "tabcontentspetremakeoption.h"

#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/citemoptiontable.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/item.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citemremakeoptionpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cpetdatatable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/itemremakeoption.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uidialog.h"

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
extern template class MS2Ptr<CItemOption>;
extern template class MS2Ptr<CPetData>;
extern template class MS2Ptr<CMsgBoxData>;
extern template class MS2Ptr<UIObject>;

// ---- statics of the unit's header and of the shared headers (the .di of this unit constructs them in this order) ----
static CString s_itemLevel("itemLevel");
static CString s_itemName("itemName");
static CStringW s_remakeOptionBindPet(L"remakeOptionBindPet");
#include "ms2/placeholder/header_statics_a.h"
static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local placeholders (the names of the classes shared with tabcontentspetevolution.cpp must stay identical:
// the Unk_PetButton / Unk_PetItemBag members it instantiates are the ones this unit calls) ----
using ATL::CAtlArray;
typedef MS2Ptr<CItem> ItemPtr;
typedef TabContentsPetRemakeOption::IdCount IdCount;

// A pet menu button (m_submit, m_debug, ...): a movie clip with a frame setter and a label.
class Unk_PetButton : public ASMovieClip
{
public:
    Unk_PetButton(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422cdde0
    void FUN_1422c1fe0(unsigned int nFrame);                            // go to the state frame
    void FUN_1422cdfb0(const CStringW& strLabel);                       // the button label
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
    void FUN_1422dd1d0();                                               // drop the selection
    void FUN_1422dcca0(int nIndex);                                     // select a slot
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_PetItemBag, 0x88);

// CItem::FUN_140527840's record: the item data (its <function> name at +0x290 and arguments at +0x2b0).
class Unk_ItemEquipData : public CItemData {};

// The local player: slot 77 is the name.
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
    ItemPtr FUN_141663450();                                            // the equipped pet item
    void FUN_141663400(ItemPtr item);                                   // equip the pet item
};
class Unk_PetPlayerMgr { public: Unk_PetPlayer* FUN_141bd0cc0(); };
Unk_PetPlayerMgr* FUN_1403ed2d0();

// The equipment stats of the player (FUN_1416561a0(pc)); stat 0xad is the pet remake discount rate.
class Unk_PetEquipSet;
Unk_PetEquipSet* FUN_1416561a0(Unk_PetPlayer* pPlayer);
float FUN_1411e1110(Unk_PetEquipSet* pSet, int nStat);
void FUN_1411e7660(Unk_PetEquipSet* pSet);                              // refresh the equipment stats

// Feature flags (slot 0x4d turns the pet remake off).
class Unk_PetFlag { public: int FUN_1402c4c90(int nFlag); };
class Unk_PetFlags { public: void* p0; Unk_PetFlag flags; };
Unk_PetFlags* FUN_14025e7b0();

// Content switches (0x9b: option lock of pets).
class Unk_PetFeatures;
Unk_PetFeatures* FUN_140166410();
bool FUN_14036d570(Unk_PetFeatures* pFeatures, int nFeature);

// Locale/build switches (debug buttons).
class Unk_PetLocale;
Unk_PetLocale* FUN_14025e7c0();
unsigned char FUN_14116d720(Unk_PetLocale*);

CPetDataTable* FUN_14052d210();                                         // TSingleton<CPetDataTable>::GetInstance
CItemOptionTable* FUN_140166430();                                      // TSingleton<CItemOptionTable>::GetInstance

// The pet system dialog (window 0x4f38) and the pet socket page (0x2711).
class UIPetSystemDialog : public UIDialog { public: void FUN_140e73590(int bEnable); };
class Unk_PetUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_PetUIManager* FUN_1403ed2b0();
class Unk_PetSocketPage;
Unk_PetSocketPage* FUN_140938c30(int nId);
void FUN_141a5a5c0(Unk_PetSocketPage* pPage);

// The item of an uid in the inventory or the equipment.
ItemPtr FUN_1419be700(unsigned __int64 uid);
// CItem members the header declares with another signature.
int FUN_140526470(CItem* pItem, unsigned nMode);                        // the item may be remade in nMode
int FUN_14053feb0(int nItemId);                                         // the default rank of an item id
// Unk_Inventory::FUN_140a5f780 returns the count (inventory.h declares it void).
int FUN_140a5f780(Unk_Inventory* pInv, int nItemId, int nRank);
// ASArray: read the int element nIndex.
bool FUN_1422bc860(ASArray* pArr, unsigned nIndex, int& n);
// The CItem sub-objects: the binding state (CItemTransfer) and the status record (its option at +0x18).
class Unk_ItemOwnerRef : public CItemTransfer {};
class Unk_ItemEnchantData : public CItemStatus {};

// Chat/system notices and message boxes.
void FUN_141275260(int nMsgId, int a1, int a2);
void FUN_1412751f0(const CStringW& strText, int a1, int a2);
void FUN_1412751b0(const CStringW& strText, int nType);
void FUN_140d73aa0(CStringW strText, int a1, int a2, CStringW strTitle);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int a, CStringW strKey);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
Delegate<bool(int, const CMsgBoxData&)> FUN_140b240b0();                // the do-nothing callback
void FUN_14151f200();                                                   // close the remake popups

// Item bag registry (the section's bag ids).
void FUN_140b77500(CString* pBag);                                      // release a card bag
void FUN_140b773a0(CString* pBag, CAtlArray<unsigned __int64>& ids);
void FUN_140b77e50(CString* pBag);                                      // release an ingredient bag
void FUN_140b77cf0(CString* pBag, CAtlArray<IdCount>& items);
void FUN_141415600(const CString& strKey);                              // release an item slot
void FUN_141415450(const CString& strKey, ItemPtr item, int a, int b, int c);

// Strings.
CStringW FUN_14028b8e0(const CStringW& strKey);                         // string table text
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_14062b4f0(CStringW strKey, const int* pn);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_14042cb90(CStringW strKey, const float& f);
CStringW FUN_1419021b0(int nHave, int nNeed);                           // "have/need"
CStringW FUN_1409404f0(__int64 n);                                      // number with separators
int FUN_1407181d0(const CString& str);
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);   // string table text, formatted
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
class Unk_PetStringTable { public: CStringW FUN_141811980(int nKind, int nId); };
Unk_PetStringTable* FUN_1401a9d70();
class Unk_PetTextFilter { public: void FUN_1416fb300(CStringW& str); };
Unk_PetTextFilter* FUN_1403b4750();

void FUN_140710590(COutPacket& pkt);                                    // send

extern Unk_Inventory DAT_143ab2a90;
extern __int64 DAT_143ab2898;                                           // the player's meso
extern int DAT_143ab2914;                                               // the account's GM level

// The error code of a 0x75 result packet (formatted through the enum path of fmt).
enum Unk_RemakeError : int {};

// The UI dialog lookup (one COMDAT per dialog class).
// @0x140b99ba0
template <class T> inline T* Unk_PetGetDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> obj = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (obj.get())
            return dynamic_cast<T*>(obj.operator->());
    }
    return 0;
}

// ---- inline members of the unit's header (COMDATs of this unit) ----

// @0x140b9a490
inline PetRemakeOptionBase::PetRemakeOptionBase()
{
}

// @0x140b9a5d0
inline PetRemakeOptionBase::~PetRemakeOptionBase()
{
}

// @0x140b9a610
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
inline PetRemakeOptionBoard::~PetRemakeOptionBoard() = default;

// @0x140b9a650
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
inline PetRemakeOptionPetCard::~PetRemakeOptionPetCard() = default;

// @0x140b9a680
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
inline PetRemakeOptionPetIngredient::~PetRemakeOptionPetIngredient() = default;

// @0x140b9a6b0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
inline TabContentsPetRemakeOption::~TabContentsPetRemakeOption() = default;

// @0x140b9a3c0
inline CItemRemakeOptionIngredient::CItemRemakeOptionIngredient()
{
    m_spContainer = new CIngredientContainer(3);
}

// @0x140b9a580
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
inline CItemRemakeOptionIngredient::~CItemRemakeOptionIngredient() = default;

// @0x140b9b080
inline void PetRemakeOptionBase::FUN_140b9b080(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
}

// ---- PetRemakeOptionPetCard ----

// @0x140b914f0
PetRemakeOptionPetCard::PetRemakeOptionPetCard(TabContentsPetRemakeOption* pOwner)
{
    m_pOwner = pOwner;
}

// @0x140b91550
void PetRemakeOptionPetCard::vfunc_2()
{
    FUN_140b77500(&m_strBag);
    m_strBag.Empty();
}
MS2_REPLACE_METHOD(0x140B91550, PetRemakeOptionPetCard, vfunc_2, 49, 0xFA2E0C11);

// @0x140b91590
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void PetRemakeOptionPetCard::vfunc_4()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> card = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_remakeOptionCard"));
    if (card == 0)
        return;
    if (!m_strBag.IsEmpty())
    {
        FUN_140b77500(&m_strBag);
        m_strBag.Empty();
    }
    m_strBag = "PetRemakeOptionPetCard";
    MS2Ptr<Unk_PetItemBag> bag = card->FUN_140accef0<Unk_PetItemBag>(CString("m_itemBag"));
    if (bag.get() != 0)
    {
        CAtlArray<unsigned __int64> ids;
        m_pOwner->FUN_140b95220(ids);
        FUN_140b773a0(&m_strBag, ids);
        bag->FUN_1422dd1d0();
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(1);
    }
}

// @0x140b917f0
void PetRemakeOptionPetCard::vfunc_5(int nEvent)
{
    switch (nEvent)
    {
    case 1:
    case 2:
    case 10:
        vfunc_4();
        break;
    }
}

// ---- PetRemakeOptionPetIngredient ----

// @0x140b91840
PetRemakeOptionPetIngredient::PetRemakeOptionPetIngredient(TabContentsPetRemakeOption* pOwner)
    : m_strBag("PetRemakeOptionPetIngredient")
{
    m_pOwner = pOwner;
}

// @0x140b918b0
void PetRemakeOptionPetIngredient::vfunc_2()
{
    FUN_140b77e50(&m_strBag);
}
MS2_REPLACE_METHOD(0x140B918B0, PetRemakeOptionPetIngredient, vfunc_2, 31, 0x72D462DE);

// @0x140b918e0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void PetRemakeOptionPetIngredient::vfunc_4()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ingredient = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_remakeOptionIngredient"));
    if (ingredient == 0)
        return;
    {
        MS2Ptr<Unk_PetItemBag> bag = ingredient->FUN_140accef0<Unk_PetItemBag>(CString("m_itemBag"));
        if (bag.get() != 0)
        {
            CAtlArray<IdCount> items;
            m_pOwner->FUN_140b95250(items);
            FUN_140b77e50(&m_strBag);
            FUN_140b77cf0(&m_strBag, items);
            bag->FUN_1422dd1d0();
            bag->FUN_1407cba60("bagId", m_strBag);
            bag->vfunc_24(1);
        }
    }
    ingredient->Invoke("updateBag", m_pOwner->FUN_140b9ad70());
    m_pOwner->FUN_140b96560();
}

// @0x140b91b60
void PetRemakeOptionPetIngredient::vfunc_5(int nEvent)
{
    switch (nEvent)
    {
    case 1:
    case 2:
    case 11:
    case 12:
        vfunc_4();
        break;
    }
}

// ---- PetRemakeOptionBoard ----

// @0x140b91bb0
PetRemakeOptionBoard::PetRemakeOptionBoard(TabContentsPetRemakeOption* pOwner)
{
    m_pOwner = pOwner;
}

// @0x140b91c20
void PetRemakeOptionBoard::vfunc_2()
{
    FUN_140b77500(&m_strBag);
    m_strBag.Empty();
    size_t nCount = m_names.GetCount();
    for (size_t i = 0; i < nCount; i++)
        FUN_141415600(m_names[i]);
    m_names.RemoveAll();
}
MS2_REPLACE_METHOD(0x140B91C20, PetRemakeOptionBoard, vfunc_2, 156, 0x7093D08A);

// @0x140b91cd0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void PetRemakeOptionBoard::vfunc_3()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> board = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petRemakeOptionBoard"));
    if (board == 0)
        return;
    {
        MS2Ptr<Unk_PetButton> submit = board->FUN_140acce30<Unk_PetButton>(CString("m_submit"));
        if (submit.get() != 0)
            submit->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_pet_remake_option_submit")));
    }
    unsigned char bDebug = FUN_14116d720(FUN_14025e7c0());
    {
        MS2Ptr<Unk_PetButton> debug = board->FUN_140acce30<Unk_PetButton>(CString("m_debug"));
        if (debug.get() != 0)
            debug->vfunc_4(bDebug);
    }
    {
        MS2Ptr<Unk_PetButton> compare = board->FUN_140acce30<Unk_PetButton>(CString("m_compareEnchant"));
        if (compare.get() != 0)
            compare->vfunc_4(false);
    }
    {
        MS2Ptr<ASMovieClip> count = board->FUN_1409b4560(CString("m_debugEnchantCount"));
        if (count.get() != 0)
            count->vfunc_4(false);
    }
    m_strBag = "PetRemakeOptionBoardTarget";
}

// @0x140b920b0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void PetRemakeOptionBoard::vfunc_4()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> board = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petRemakeOptionBoard"));
    if (board == 0)
        return;
    {
        MS2Ptr<Unk_PetButton> submit = board->FUN_140acce30<Unk_PetButton>(CString("m_submit"));
        if (submit.get() != 0)
            submit->FUN_1422c1fe0(0);
    }
    board->Invoke("ClearData");
}

// @0x140b92210
void PetRemakeOptionBoard::vfunc_5(int nEvent)
{
    switch (nEvent)
    {
    case 0xe:
        vfunc_3();
        FUN_140b92da0();
        break;
    case 0xb:
        FUN_140b93460();
        break;
    }
}

// @0x140b92270
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void PetRemakeOptionBoard::vfunc_6(MS2Ptr<CItem> cur, MS2Ptr<CItem> next)
{
    MS2Ptr<ASUIComponent> board = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petRemakeOptionBoard"));
    if (board == 0)
        return;
    ASObj obj(2);
    obj.FUN_1407cbb20("itemName", cur->FUN_140528160());
    int nRemakeCount = cur->FUN_140527300();
    CStringW strCount = FUN_14062b4f0(CStringW(L"s_pet_remake_option_count"), &nRemakeCount);
    obj.FUN_1407cbb20("remakeCount", strCount);
    CStringW strCurKey(L"s_pet_remake_cur_random_option");
    CStringW strNewKey(L"s_pet_remake_new_random_option");
    Unk_RemakeStat stat(2, ItemPtr(cur), true);
    obj.FUN_1407cbb20("remakeStat0", FUN_140617e50(strCurKey, stat, 0));
    stat.m_item = next;
    obj.FUN_1407cbb20("remakeStat1", FUN_140617e50(strNewKey, stat, 0));
    int nSelected = 0;
    obj.FUN_1407cb9c0("selectedStatIndex", 0);
    board->Invoke("setRemakeResult", obj.FUN_1422bb870());
    {
        MS2Ptr<Unk_PetButton> submit = board->FUN_140acce30<Unk_PetButton>(CString("m_submit"));
        if (submit.get() != 0)
            submit->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_pet_remake_option_apply")));
    }
}

// @0x140b92740
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void PetRemakeOptionBoard::vfunc_7(int nSelect)
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> board = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petRemakeOptionBoard"));
    if (board == 0)
        return;
    ItemPtr picked = (nSelect != 0) ? m_pOwner->FUN_140b951d0() : m_pOwner->FUN_140b95180();
    if (!(picked == m_pOwner->FUN_140b951d0().get()))
    {
        COutPacket pkt(0x75, 0);
        pkt.Encode1(3);
        pkt.Encode1(2);
        FUN_140710590(pkt);
    }
    else
    {
        CCItemRemakeOptionPacket::ApplyOptionClient apply;
        apply.m_uid = picked->FUN_140526a50();
        COutPacket pkt(0x75, 0);
        pkt.Encode1(2);
        apply.vfunc_1(pkt);
        FUN_140710590(pkt);
    }
    Unk_RemakeStat stat(2, ItemPtr(picked), true);
    CStringW strFinal = FUN_140617ef0(stat, 0);
    ASObj obj(2);
    obj.FUN_1407cbb20("remakeStatFinal", strFinal);
    int nRemakeCount = picked->FUN_140527300();
    CStringW strCount = FUN_14062b4f0(CStringW(L"s_pet_remake_option_count"), &nRemakeCount);
    obj.FUN_1407cbb20("remakeCount", strCount);
    board->Invoke("selectComplete", obj.FUN_1422bb870());
    m_pOwner->FUN_140b96960(ItemPtr(picked));
    {
        MS2Ptr<Unk_PetButton> submit = board->FUN_140acce30<Unk_PetButton>(CString("m_submit"));
        if (submit.get() != 0)
            submit->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_pet_remake_option_retry")));
    }
}

// @0x140b92d90
void PetRemakeOptionBoard::vfunc_1()
{
}
MS2_REPLACE_METHOD(0x140B92D90, PetRemakeOptionBoard, vfunc_1, 6, 0xA9AF6E37);

// @0x140b92da0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void PetRemakeOptionBoard::FUN_140b92da0()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> board = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petRemakeOptionBoard"));
    if (board == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140b95140());
    if (pet == 0)
        return;
    unsigned nMaxLock = 0;
    if (m_pOwner->FUN_140b95160() != 0)
    {
        ItemPtr ingredient = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140b95160());
        if (ingredient.get() != 0)
            nMaxLock = ingredient->FUN_140527840()->function.parameter.FUN_1408d1f60(0, 0);
    }
    CAtlArray<unsigned __int64> ids;
    ids.Add(m_pOwner->FUN_140b95140());
    FUN_140b773a0(&m_strBag, ids);
    ASObj obj(2);
    obj.FUN_1407cbb20(s_itemName, pet->FUN_140527b10());
    obj.FUN_1409c48f0(s_itemLevel, pet->FUN_140528c20());
    obj.FUN_1407cba60("bagId", m_strBag);
    int nRemakeCount = pet->FUN_140527300();
    CStringW strCount = FUN_14062b4f0(CStringW(L"s_pet_remake_option_count"), &nRemakeCount);
    obj.FUN_1407cbb20("remakeCount", strCount);
    unsigned nFrame = (FUN_140b937c0(obj, ItemPtr(pet)) != 0 || FUN_14116d720(FUN_14025e7c0()) != 0) ? 1 : 0;
    {
        MS2Ptr<Unk_PetButton> submit = board->FUN_140acce30<Unk_PetButton>(CString("m_submit"));
        if (submit.get() != 0)
            submit->FUN_1422c1fe0(nFrame);
    }
    unsigned nOptionCount = 0;
    Unk_RemakeStat stat(2, ItemPtr(pet), true);
    CStringW strOption = FUN_140617ef0(stat, &nOptionCount);
    nMaxLock = (std::min)(nOptionCount - 1, nMaxLock);
    bool bLock = FUN_140616fd0(ItemPtr(pet));
    obj.FUN_1407cbb20("currentOption", strOption);
    obj.FUN_1409c0d20("currentOptionCount", nOptionCount);
    obj.FUN_1407cbbe0("enableLock", bLock);
    obj.FUN_1409c0d20("maxOptionLockCount", nMaxLock);
    board->Invoke("selectPetCard", obj.FUN_1422bb870());
}

// @0x140b93460
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void PetRemakeOptionBoard::FUN_140b93460()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> board = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petRemakeOptionBoard"));
    if (board == 0)
        return;
    ItemPtr ingredient = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140b95160());
    if (ingredient == 0)
        return;
    MS2Ptr<CItemData> data(ingredient->FUN_140527840());
    if (data == 0)
        return;
    if (data->function.name != L"LockItemOptionPet")
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140b95140());
    if (pet == 0)
        return;
    unsigned nMaxLock = data->function.parameter.FUN_1408d1f60(0, 0);
    unsigned nOptions = FUN_1406191e0(2, ItemPtr(pet));
    nMaxLock = (std::min)(nOptions - 1, nMaxLock);
    ASObj obj(2);
    obj.FUN_1409c0d20("maxOptionLockCount", nMaxLock);
    board->Invoke("selectIngredientItem", obj.FUN_1422bb870());
}

// @0x140b937c0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
int PetRemakeOptionBoard::FUN_140b937c0(ASObj& obj, MS2Ptr<CItem> item)
{
    if (!(item == 0) && item->FUN_140527840() != 0)
    {
        int nRemakeCount = item->FUN_140527300();
        CItemRemakeOptionIngredient ingredient;
        MS2Ptr<CItemData> data(item->FUN_140527840());
        MS2Ptr<CPetData> pet = FUN_14052d210()->Find(item->FUN_140527840()->FUN_14053dc60());
        if (pet == 0)
            return 0;
        FUN_140166430()->FUN_1405f4bb0(nRemakeCount, item->FUN_140526bd0(), ingredient);
        MS2SvrPtr<CIngredientContainer> container(
            static_cast<const MS2SvrPtr<CIngredientContainer>&>(ingredient.m_spContainer));
        if (container == 0)
            return 0;
        Unk_IngVec* pList = container->FUN_14026c230();
        size_t nList = pList->FUN_14028b500();
        ASArray list(2);
        unsigned nDiscount = 0;
        unsigned nRate = 0;
        Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (player != 0)
            nRate = (unsigned)(__int64)(FUN_1411e1110(FUN_1416561a0(player), 0xad) * 10000.0f);
        int nSale = FUN_140616c50(MS2Ptr<CItemData>(data), &nDiscount, nRate);
        __int64 nFee = 0;
        int bEnough = 1;
        for (size_t i = 0; i < nList; i++)
        {
            Unk_IngRef ref(*pList->FUN_14028a0f0(i));
            if (ref == 0 || ref->FUN_14026b350())
                continue;
            ASObj entry(2);
            unsigned nItemId = ref->FUN_14026b500();
            int nNeed = ref->m_c;
            int nType = ref->m_b;
            int nRank = FUN_14053feb0(nItemId);
            CItem* pIngredient = new CItem();
            if (pIngredient->FUN_14052b2e0(nItemId, nRank, 0, nNeed) != 0)
            {
                CString strKey = StringFormat("{0}.ingredient.{1}", m_strBag, i);
                entry.FUN_1407cba60("binding", FUN_140b94260(pIngredient, CString(strKey), m_names));
                int nHave = FUN_140b94340(ItemPtr(pIngredient));
                int nCount;
                if (nSale == 0)
                    nCount = nNeed;
                else
                    nCount = FUN_140616d40(nNeed, nDiscount);
                if (nType != 0x60 && nHave < nCount)
                    bEnough = 0;
                if (nType == 0x60 && nHave < nCount && DAT_143ab2898 < (nFee = (__int64)((nCount - nHave) * 1000)))
                    bEnough = 0;
                entry.FUN_1407cbb20("countText", FUN_1419021b0(nHave, nCount));
                list.FUN_1422bbf00(entry);
            }
        }
        obj.FUN_1409eb1d0("ingredient", list);
        obj.FUN_1407cbb20("remakeFee", FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(nFee)));
        MS2Ptr<ASUIComponent> board = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petRemakeOptionBoard"));
        if (board.get() != 0)
        {
            MS2Ptr<ASTextField> desc = board->FUN_1409b4620(CString("m_saleDesc"));
            if (desc.get() != 0)
            {
                CStringW strDesc;
                if (nSale == 1)
                {
                    float fRate = (float)nDiscount * 0.01;
                    strDesc = FUN_14042cb90(CStringW(L"s_pet_remake_sale_desc"), fRate);
                }
                else if (nSale == 2)
                {
                    float fRate = (float)nDiscount * 0.01;
                    strDesc = FUN_14042cb90(CStringW(L"s_pet_remake_sa_sale_desc"), fRate);
                }
                desc->FUN_1422c4f00(strDesc);
            }
        }
        return bEnough;
    }
    return 0;
}

// @0x140b94260
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
CString PetRemakeOptionBoard::FUN_140b94260(CItem* pItem, CString strKey, CAtlArray<CString>& names)
{
    FUN_141415600(strKey);
    FUN_141415450(strKey, ItemPtr(pItem), 0, 0x405, 0x2020);
    names.Add(strKey);
    return CString(strKey);
}

// @0x140b94340
int PetRemakeOptionBoard::FUN_140b94340(MS2Ptr<CItem> item)
{
    if (item == 0 || item->FUN_140527840() == 0)
        return 0;
    int nHave = 0;
    int nItemId = item->FUN_140527840()->FUN_14053c6f0();
    if (nItemId != 0)
        nHave = FUN_140a5f780(&DAT_143ab2a90, nItemId, 0);
    return nHave;
}

// ---- TabContentsPetRemakeOption ----

// @0x140b94400
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
TabContentsPetRemakeOption::TabContentsPetRemakeOption()
    : m_uidPet(0), m_uidIngredient(0), m_pet(0), m_petNext(0), m_nPetIndex(0), m_nIngredientIndex(-1), m_parts(10),
      m_nState(0), m_ui(0)
{
    m_parts.AddTail(MS2Ptr<PetRemakeOptionBase>(new PetRemakeOptionPetCard(this)));
    if (FUN_14036d570(FUN_140166410(), 0x9b) == true)
        m_parts.AddTail(MS2Ptr<PetRemakeOptionBase>(new PetRemakeOptionPetIngredient(this)));
    m_board.AssignRaw(new PetRemakeOptionBoard(this));
    m_parts.AddTail(MS2Ptr<PetRemakeOptionBase>(m_board));
}

// @0x140b94710
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::vfunc_1()
{
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetRemakeOptionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_1();
        m_parts.GetNext(pos);
    }
    m_parts.RemoveAll();
    m_ui = 0;
    m_uidPet = 0;
    m_uidIngredient = 0;
    m_pet = 0;
    m_petNext = 0;
    m_nPetIndex = 0;
    m_nIngredientIndex = -1;
}

// @0x140b94860
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::vfunc_4()
{
    FUN_140b96520(0);
    m_uidPet = 0;
    m_uidIngredient = 0;
    m_petCards.RemoveAll();
    m_ingredients.RemoveAll();
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetRemakeOptionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_2();
        m_parts.GetNext(pos);
    }
}

// @0x140b94980
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::vfunc_2(int nEvent)
{
    if (m_ui == 0)
        return;
    if (0 < nEvent && nEvent < 3)
    {
        FUN_140b96ca0();
        FUN_140b96e60();
    }
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetRemakeOptionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_5(nEvent);
        m_parts.GetNext(pos);
    }
}

// @0x140b94aa0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::vfunc_3(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
    FUN_140b96ca0();
    FUN_140b96e60();
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetRemakeOptionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
        {
            p->FUN_140b9b080(MS2Ptr<ASUIComponent>(ui));
            p->vfunc_4();
            p->vfunc_3();
        }
        m_parts.GetNext(pos);
    }
    FUN_140b96520(0);
    FUN_140b967c0(0);
    COutPacket pkt(0x75, 0);
    pkt.Encode1(6);
    pkt.Encode1(2);
    FUN_140710590(pkt);
}

// @0x140b94c90
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
int TabContentsPetRemakeOption::vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (_stricmp("OnSelectPetCard", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140b97170(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnSelectPetIngredient", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140b972f0(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnPetRemakeOption", szEvent) == 0)
    {
        FUN_140b95280(0);
        return 1;
    }
    if (_stricmp("GetEnableLockOption", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140b973b0(&data);
    }
    else if (_stricmp("OnClickApply", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140b97870(&data);
    }
    else if (_stricmp("OnClickRetry", szEvent) == 0)
    {
        FUN_140b979c0();
    }
    else if (_stricmp("OnDebug", szEvent) == 0)
    {
        SendChangeAttributesMode7();
    }
    else if (_stricmp("OnClickCompareEnchant", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140b95db0(&data);
    }
    return 0;
}

// @0x140b94fa0
int TabContentsPetRemakeOption::vfunc_8()
{
    return 3;
}
MS2_REPLACE_METHOD(0x140B94FA0, TabContentsPetRemakeOption, vfunc_8, 11, 0xA6B3D596);

// @0x140b94fc0
void TabContentsPetRemakeOption::vfunc_9(void* pPacket)
{
    if (((CInPacket*)pPacket)->FUN_14070fe80() != 200)
        return;
    if (m_ui == 0)
        return;
    FUN_140b967c0(1);
    int nKind = ((CInPacket*)pPacket)->vfunc_o8_1();
    if (nKind == 6)
        FUN_140b97c90((CInPacket*)pPacket);
    else if (nKind == 1)
        FUN_140b98430((CInPacket*)pPacket);
    else if (nKind == 2)
        FUN_140b98520((CInPacket*)pPacket);
    else if (nKind == 5)
        FUN_140b98610((CInPacket*)pPacket);
}

// @0x140b950b0
void TabContentsPetRemakeOption::vfunc_10(void* pItem, bool b)
{
    if (!pItem)
        return;
    if (!((CItem*)pItem)->FUN_140525640())
        return;
    FUN_140b96520(1);
    m_uidPet = 0;
    m_pet = 0;
    FUN_140b96ca0();
    vfunc_2(10);
}

// @0x140b95140
unsigned __int64 TabContentsPetRemakeOption::FUN_140b95140()
{
    return m_uidPet;
}
MS2_REPLACE_METHOD(0x140B95140, TabContentsPetRemakeOption, FUN_140b95140, 15, 0xBBB219C9);

// @0x140b95160
unsigned __int64 TabContentsPetRemakeOption::FUN_140b95160()
{
    return m_uidIngredient;
}
MS2_REPLACE_METHOD(0x140B95160, TabContentsPetRemakeOption, FUN_140b95160, 15, 0xCBEE5D21);

// @0x140b95180
MS2Ptr<CItem> TabContentsPetRemakeOption::FUN_140b95180()
{
    return m_pet;
}
MS2_REPLACE_METHOD(0x140B95180, TabContentsPetRemakeOption, FUN_140b95180, 65, 0xF7EAD2D8);

// @0x140b951d0
MS2Ptr<CItem> TabContentsPetRemakeOption::FUN_140b951d0()
{
    return m_petNext;
}
MS2_REPLACE_METHOD(0x140B951D0, TabContentsPetRemakeOption, FUN_140b951d0, 65, 0x1EA85501);

// @0x140b95220
void TabContentsPetRemakeOption::FUN_140b95220(CAtlArray<unsigned __int64>& out)
{
    out.Copy(m_petCards);
}
MS2_REPLACE_METHOD(0x140B95220, TabContentsPetRemakeOption, FUN_140b95220, 41, 0x8114B4A9);

// @0x140b95250
void TabContentsPetRemakeOption::FUN_140b95250(CAtlArray<IdCount>& out)
{
    out.Copy(m_ingredients);
}
MS2_REPLACE_METHOD(0x140B95250, TabContentsPetRemakeOption, FUN_140b95250, 41, 0xDBAB1BE9);

// @0x140b95280
// MS2-FUNCTIONAL: message box argument temporaries
void TabContentsPetRemakeOption::FUN_140b95280(int bUsePoint)
{
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0)
        return;
    if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x4d) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return;
    }
    if (bUsePoint == 0)
    {
        if (pet->FUN_140527930()->FUN_140635100() != 0 && pet->FUN_140527930()->FUN_140635120() == 0)
        {
            CStringW strMsg = FUN_1405c2690(CStringW(L"s_msg_transfer_bind_pet_remakeoption"), player->vfunc_77());
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x11, strMsg, 0, s_remakeOptionBindPet);
            if (box.get() != 0)
            {
                box->FUN_141a01600(pet->FUN_140526a50());
                box->FUN_141a01ee0(ItemPtr(pet), pet->FUN_140527b10(), 1, 0, -1, -1, 1);
                box->FUN_141a01700(0x477, 0x478, 0);
                FUN_140d73c60(box);
                return;
            }
        }
    }
    CAtlArray<int> aLocked;
    FUN_140b96b60(aLocked);
    if (aLocked.GetCount() == 0)
    {
        if (m_uidIngredient != 0)
        {
            ItemPtr ingredient = DAT_143ab2a90.FUN_140a5d680(m_uidIngredient);
            if (ingredient == 0)
                return;
            CStringW strAsk = FUN_1405c2690(CStringW(L"s_pet_remake_ask_have_not_lock"), ingredient->FUN_140528160());
            FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &TabContentsPetRemakeOption::FUN_140b964c0), strAsk);
            return;
        }
        FUN_140b95f90();
    }
    else
    {
        ItemPtr ingredient = DAT_143ab2a90.FUN_140a5d680(m_uidIngredient);
        if (ingredient == 0)
            return;
        if (FUN_140616dd0(ItemPtr(pet)) == 0)
            return;
        if (bUsePoint != 0)
            FUN_14151f200();
        MS2Ptr<CItemOption> option(pet->FUN_1405278a0()->m_spOption);
        if (option == 0)
            return;
        Unk_RemakeStat stat(2, ItemPtr(pet), false);
        CStringW strLocked = FUN_140619070(stat, aLocked);
        CStringW strName = ingredient->FUN_140528160();
        unsigned nMaxLock = ingredient->FUN_140527840()->function.parameter.FUN_1408d1f60(0, 0);
        size_t nLocked = aLocked.GetCount();
        CStringW strAsk = FUN_14028dfa0(CStringW(L"s_pet_remake_ask_lock_item_option"), nLocked, nMaxLock, strLocked,
                                        strName, nMaxLock);
        FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &TabContentsPetRemakeOption::FUN_140b964f0), strAsk);
    }
}

// @0x140b95c40
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::SendChangeAttributesMode7()
{
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0)
        return;
    if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x4d) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return;
    }
    if (DAT_143ab2914 < 0x32)
        return;
    FUN_140b96520(4);
    CCItemRemakeOptionPacket::RemakeOptionDebug debug;
    debug.m_18 = m_uidPet;
    COutPacket pkt(0x75, 0);
    pkt.Encode1(7);
    debug.vfunc_1(pkt);
    FUN_140710590(pkt);
}

// @0x140b95db0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b95db0(ASData* pData)
{
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0)
        return;
    if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x4d) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return;
    }
    if (DAT_143ab2914 < 0x32)
        return;
    FUN_140b96520(4);
    CString strValue = pData->FUN_1422b8d30();
    strValue.Replace(",", "");
    CCItemRemakeOptionPacket::RemakeOptionDebug debug;
    debug.m_value = FUN_1407181d0(strValue);
    if (debug.m_value == 0)
        debug.m_value = 100000;
    debug.m_18 = m_uidPet;
    debug.m_kind = 2;
    COutPacket pkt(0x75, 0);
    pkt.Encode1(7);
    debug.vfunc_1(pkt);
    FUN_140710590(pkt);
}

// @0x140b95f90
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b95f90()
{
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    if (FUN_140526470(pet.operator->(), 2) == 0)
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_pet_remake_error_server_impossible")), 1, 1);
        return;
    }
    CAtlArray<int> aLocked;
    FUN_140b96b60(aLocked);
    CCItemRemakeOptionPacket::RemakeOption remake;
    remake.m_18 = m_uidPet;
    remake.m_20 = m_uidIngredient;
    Unk_RemakeLockOpt lockOpt;
    if (aLocked.GetCount() != 0)
    {
        int nLockId = FUN_140616dd0(ItemPtr(pet));
        if (nLockId == 0)
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_pet_remake_error_server_impossible")), 1, 1);
            return;
        }
        unsigned nLockLevel = FUN_140616f10(ItemPtr(pet));
        int nHave = DAT_143ab2a90.FUN_140a5f7b0(nLockId, nLockLevel);
        if (nHave < 1)
        {
            CStringW strLock = FUN_140619760(nLockId, nLockLevel);
            CStringW strNotice = FUN_1405c2690(
                CStringW(L"s_itemremake_notice_disable_lock_item_option_when_click_remake"), strLock);
            FUN_140d74390(strNotice, 0, FUN_140b240b0());
            return;
        }
        Unk_RemakeStat stat(2, ItemPtr(pet), false);
        for (size_t i = 0; i < aLocked.GetCount(); i++)
        {
            if (stat.FUN_140619290(aLocked[i], lockOpt.m_nIndex, lockOpt.m_nValue))
                reinterpret_cast<Unk_RemakeLockOptList&>(remake.m_options).push_back(lockOpt);
        }
    }
    COutPacket pkt(0x75, 0);
    pkt.Encode1(0);
    remake.vfunc_1(pkt);
    FUN_140710590(pkt);
    FUN_140b96520(4);
    FUN_140b967c0(0);
}

// @0x140b964c0
bool TabContentsPetRemakeOption::FUN_140b964c0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
        FUN_140b95f90();
    return true;
}
MS2_REPLACE_METHOD(0x140B964C0, TabContentsPetRemakeOption, FUN_140b964c0, 42, 0x09E39FF4);

// @0x140b964f0
bool TabContentsPetRemakeOption::FUN_140b964f0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
        FUN_140b95f90();
    return true;
}
MS2_REPLACE_METHOD(0x140B964F0, TabContentsPetRemakeOption, FUN_140b964f0, 42, 0x92ECD424);

// @0x140b96520
void TabContentsPetRemakeOption::FUN_140b96520(int nState)
{
    m_nState = nState;
    FUN_140b96560();
}
MS2_REPLACE_METHOD(0x140B96520, TabContentsPetRemakeOption, FUN_140b96520, 43, 0x4279C4C8);

// @0x140b96560
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b96560()
{
    if (m_nState == 2 || m_nState == 3)
    {
        MS2Ptr<ASUIComponent> ingredient = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_remakeOptionIngredient"));
        if (ingredient.get() != 0)
        {
            MS2Ptr<Unk_PetButton> bag = ingredient->FUN_140accef0<Unk_PetButton>(CString("m_itemBag"));
            if (bag.get() != 0)
                bag->FUN_1422c1fe0(1);
        }
    }
    else
    {
        MS2Ptr<ASUIComponent> ingredient = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_remakeOptionIngredient"));
        if (ingredient.get() != 0)
        {
            MS2Ptr<Unk_PetButton> bag = ingredient->FUN_140accef0<Unk_PetButton>(CString("m_itemBag"));
            if (bag.get() != 0)
                bag->FUN_1422c1fe0(0);
        }
    }
}

// @0x140b967a0
int TabContentsPetRemakeOption::FUN_140b967a0()
{
    return m_nState;
}
MS2_REPLACE_METHOD(0x140B967A0, TabContentsPetRemakeOption, FUN_140b967a0, 17, 0x33D25353);

// @0x140b967c0
void TabContentsPetRemakeOption::FUN_140b967c0(int bEnable)
{
    UIPetSystemDialog* dialog = Unk_PetGetDialog<UIPetSystemDialog>(0x4f38);
    if (dialog != 0)
        dialog->FUN_140e73590(bEnable);
}
MS2_REPLACE_METHOD(0x140B967C0, TabContentsPetRemakeOption, FUN_140b967c0, 55, 0xF135DC7C);

// @0x140b96800
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b96800(MS2Ptr<CItem> cur, MS2Ptr<CItem> next)
{
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetRemakeOptionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_6(ItemPtr(cur), ItemPtr(next));
        m_parts.GetNext(pos);
    }
}

// @0x140b96960
void TabContentsPetRemakeOption::FUN_140b96960(MS2Ptr<CItem> item)
{
    if (item == 0)
        return;
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0)
        return;
    ItemPtr held = DAT_143ab2a90.FUN_140a5d680(item->FUN_140526a50());
    if (held == 0)
        return;
    DAT_143ab2a90.FUN_140a5d530(item.get());
    ItemPtr equipped = player->FUN_141663450();
    if (equipped.get() != 0)
    {
        if (m_pet->FUN_140526a50() == equipped->FUN_140526a50())
            player->FUN_141663400(ItemPtr(item));
    }
    m_pet = item;
    FUN_1411e7660(FUN_1416561a0(player));
    Unk_PetSocketPage* page = FUN_140938c30(0x2711);
    if (page != 0)
        FUN_141a5a5c0(page);
}
MS2_REPLACE_METHOD(0x140B96960, TabContentsPetRemakeOption, FUN_140b96960, 491, 0x387E2EE7);

// @0x140b96b60
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b96b60(CAtlArray<int>& out)
{
    MS2Ptr<ASUIComponent> board = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petRemakeOptionBoard"));
    if (board == 0)
        return;
    ASArray indices(board->Invoke("getLockOptionIndex"), 2);
    int nIndex = 0;
    for (unsigned i = 0; i < indices.FUN_1422bc5d0(); i++)
    {
        FUN_1422bc860(&indices, i, nIndex);
        out.Add(nIndex);
    }
}

// @0x140b96ca0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b96ca0()
{
    m_petCards.RemoveAll();
    CAtlArray<unsigned __int64> ids;
    DAT_143ab2a90.FUN_140a609a0(9, ids);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(ids[i]);
        if (item == 0)
            continue;
        MS2Ptr<CPetData> pet = FUN_14052d210()->Find(item->FUN_140527840()->FUN_14053dc60());
        if (pet == 0)
            continue;
        if (FUN_140526470(item.operator->(), 2) == 0)
            continue;
        m_petCards.Add(item->FUN_140526a50());
    }
}

// @0x140b96e60
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b96e60()
{
    m_ingredients.RemoveAll();
    CAtlArray<unsigned __int64> ids;
    DAT_143ab2a90.FUN_140a609a0(3, ids);
    for (unsigned i = 0; i < ids.GetCount(); i++)
    {
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(ids[i]);
        if (item == 0)
            continue;
        MS2Ptr<CItemData> data(item->FUN_140527840());
        if (data == 0)
            continue;
        __int64 uid = item->FUN_140526a50();
        if (uid == 0)
            continue;
        int nItemId = data->FUN_14053c6f0();
        if (nItemId != 0x68)
            continue;
        unsigned nCount = DAT_143ab2a90.FUN_140a5f060(item->FUN_140526a50());
        if (nCount == 0)
            continue;
        if (data->function.name != L"LockItemOptionPet")
            continue;
        if ((int)data->function.parameter.FUN_1408d1f60(0, 0) < 1)
            continue;
        m_ingredients.Add(IdCount(uid, nCount));
    }
    if (m_uidIngredient != 0)
    {
        ItemPtr ingredient = DAT_143ab2a90.FUN_140a5d680(m_uidIngredient);
        if (ingredient == 0)
        {
            m_uidIngredient = 0;
            m_nIngredientIndex = -1;
        }
    }
}

// @0x140b97170
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b97170(int nIndex)
{
    if (m_nState != 0 && m_nState != 4 && -1 < nIndex && nIndex < (int)m_petCards.GetCount())
    {
        m_pet = 0;
        m_petNext = 0;
        ItemPtr item = FUN_1419be700(m_petCards[nIndex]);
        if (item == 0)
            return;
        if (FUN_140526470(item.operator->(), 2) == 0)
            return;
        m_pet = item;
        m_nPetIndex = nIndex;
        m_uidPet = m_petCards[nIndex];
        FUN_140b96520(2);
        vfunc_2(0xe);
    }
}

// @0x140b972f0
void TabContentsPetRemakeOption::FUN_140b972f0(int nIndex)
{
    if (m_nState == 4)
        return;
    if (nIndex < 0 || nIndex >= (int)m_ingredients.GetCount())
        return;
    m_nIngredientIndex = nIndex;
    IdCount entry = m_ingredients[nIndex];
    m_uidIngredient = entry.first;
    FUN_140b96520(3);
    vfunc_2(0xb);
}

// @0x140b973b0
void TabContentsPetRemakeOption::FUN_140b973b0(ASData* pData)
{
    if (m_uidPet == 0)
        return;
    if (!FUN_14036d570(FUN_140166410(), 0x9b))
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    unsigned nLocked = pData->FUN_1422b8b10();
    unsigned nMax = pData->FUN_1422b8b10();
    if (nMax == 0)
    {
        CStringW strNotice = FUN_140298ea0(CStringW(L"s_pet_remake_notice_disable_lock_item_option"));
        FUN_1403b4750()->FUN_1416fb300(strNotice);
        FUN_140d73aa0(strNotice, 0, 0, CStringW(L""));
    }
    else if (nMax <= nLocked)
    {
        ItemPtr ingredient = DAT_143ab2a90.FUN_140a5d680(m_uidIngredient);
        if (ingredient == 0)
            return;
        MS2Ptr<CItemData> data(ingredient->FUN_140527840());
        if (data == 0)
            return;
        if (data->function.name != L"LockItemOptionPet")
            return;
        unsigned nLimit = data->function.parameter.FUN_1408d1f60(0, 0);
        if (nLimit == nMax)
            FUN_140d73aa0(FUN_14028dfa0(CStringW(L"s_pet_remake_notice_lock_item_option_limit"),
                                        ingredient->FUN_140528160(), nLimit), 0, 0, CStringW(L""));
        else
            FUN_140d73aa0(FUN_140298ea0(CStringW(L"s_pet_remake_notice_lock_item_option_max_count")), 0, 0,
                          CStringW(L""));
    }
}
MS2_REPLACE_METHOD(0x140B973B0, TabContentsPetRemakeOption, FUN_140b973b0, 1208, 0x6BE52EC5);

// @0x140b97870
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b97870(ASData* pData)
{
    FUN_140b96520(5);
    int nSelect = pData->FUN_1422b8a10();
    if (nSelect == -1)
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_pet_remake_error_server_fail_apply_option")), 1, 1);
        return;
    }
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetRemakeOptionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_7(nSelect);
        m_parts.GetNext(pos);
    }
}

// @0x140b979c0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b979c0()
{
    MS2Ptr<ASUIComponent> card = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_remakeOptionCard"));
    if (card.get() != 0)
    {
        MS2Ptr<Unk_PetItemBag> bag = card->FUN_140accef0<Unk_PetItemBag>(CString("m_itemBag"));
        if (bag.get() != 0)
            bag->FUN_1422dcca0(m_nPetIndex);
    }
    FUN_140b96520(2);
    vfunc_2(0xe);
}

// @0x140b97b00
int TabContentsPetRemakeOption::FUN_140b97b00(CAtlArray<unsigned __int64>& arr, unsigned __int64 id)
{
    for (size_t i = 0; i < arr.GetCount(); i++)
    {
        if (id == arr[i])
            return 1;
    }
    return 0;
}

// @0x140b97b70
unsigned __int64 TabContentsPetRemakeOption::FUN_140b97b70(CAtlArray<unsigned __int64>& arr, int nIndex)
{
    if (nIndex < 0)
        return 0;
    for (size_t i = 0; i < arr.GetCount(); i++)
    {
        if (i == nIndex)
            return arr[i];
    }
    return 0;
}

// @0x140b97bf0
void TabContentsPetRemakeOption::FUN_140b97bf0(CAtlArray<unsigned __int64>& arr, unsigned __int64 id)
{
    int nFound = -1;
    for (size_t i = 0; i < arr.GetCount(); i++)
    {
        if (id == arr[i])
        {
            nFound = (int)i;
            break;
        }
    }
    if (-1 < nFound)
        arr.RemoveAt(nFound, 1);
}
MS2_REPLACE_METHOD(0x140B97BF0, TabContentsPetRemakeOption, FUN_140b97bf0, 141, 0x428153B5);

// @0x140b97c90
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b97c90(CInPacket* pPacket)
{
    int nResult = pPacket->vfunc_o8_1();
    if (nResult == 0)
    {
        FUN_140b96520(1);
        return;
    }
    size_t nItemId = (unsigned)pPacket->vfunc_o8_3();
    if (nResult == 2)
    {
        FUN_140b98ad0((int)nItemId);
        FUN_140b96520(1);
        return;
    }
    ItemPtr item = FUN_1419be700(pPacket->vfunc_o8_4());
    if (item == 0)
    {
        FUN_140b98ad0((int)nItemId);
        FUN_140b96520(1);
        return;
    }
    if (FUN_140526470(item.operator->(), 2) == 0)
    {
        CStringW strError = FUN_140298ea0(CStringW(L"s_itemremake_error_server_impossible"));
        FUN_1412751f0(strError, 1, 1);
        FUN_140b96520(1);
        return;
    }
    FUN_140b96520(4);
    m_pet = item;
    m_uidPet = item->FUN_140526a50();
    size_t nCards = m_petCards.GetCount();
    for (size_t i = 0; i < nCards; i++)
    {
        if (m_petCards.GetAt(i) == m_uidPet)
        {
            m_nPetIndex = (int)i;
            break;
        }
    }
    m_petNext = m_pet->FUN_140524250();
    CCItemRemakeOptionPacket::ApplyOptionClient apply;
    apply.m_item = m_petNext;
    apply.vfunc_2(*pPacket);
    FUN_140b988d0(m_uidPet);
    MS2Ptr<ASUIComponent> board = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petRemakeOptionBoard"));
    if (board.get() != 0)
    {
        {
            MS2Ptr<Unk_PetButton> submit = board->FUN_140acce30<Unk_PetButton>(CString("m_submit"));
            if (submit.get() != 0)
                submit->FUN_1422c1fe0(1);
        }
        CAtlArray<unsigned __int64> ids;
        ids.Add(m_uidPet);
        CString strBag = m_board->FUN_140b9ad20();
        FUN_140b773a0(&strBag, ids);
        ASObj obj(2);
        obj.FUN_1407cbb20(s_itemName, m_pet->FUN_140527b10());
        obj.FUN_1409c48f0(s_itemLevel, m_pet->FUN_140528c20());
        obj.FUN_1407cba60("bagId", m_board->FUN_140b9ad20());
        int nRemakeCount = m_pet->FUN_140527300();
        CStringW strCount = FUN_14062b4f0(CStringW(L"s_pet_remake_option_count"), &nRemakeCount);
        obj.FUN_1407cbb20("remakeCount", strCount);
        board->Invoke("SetBasicInfo", obj.FUN_1422bb870());
    }
}

// @0x140b98430
void TabContentsPetRemakeOption::FUN_140b98430(CInPacket* pPacket)
{
    if (m_pet == 0)
        return;
    m_petNext = m_pet->FUN_140524250();
    CCItemRemakeOptionPacket::ApplyOptionClient apply;
    apply.m_item = m_petNext;
    apply.vfunc_2(*pPacket);
    FUN_140b988d0(apply.m_uid);
}
MS2_REPLACE_METHOD(0x140B98430, TabContentsPetRemakeOption, FUN_140b98430, 229, 0xB20D8B32);

// @0x140b98520
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b98520(CInPacket* pPacket)
{
    if (m_petNext == 0)
        return;
    CCItemRemakeOptionPacket::ApplyOptionClient apply;
    apply.m_item = m_petNext;
    apply.vfunc_2(*pPacket);
    if (apply.m_uid == m_petNext->FUN_140526a50())
        FUN_140b96960(ItemPtr(m_petNext));
}

// @0x140b98610
// MS2-FUNCTIONAL: switch table shape
void TabContentsPetRemakeOption::FUN_140b98610(CInPacket* pPacket)
{
    int nKind = pPacket->vfunc_o8_1();
    Unk_RemakeError eError = (Unk_RemakeError)pPacket->vfunc_o8_3();
    if (FUN_140b967a0() == 4 && nKind == 0)
        FUN_140b96520(2);
    CStringW strKey;
    switch (eError)
    {
    case 1:
        strKey = L"s_itemremake_error_server_not_in_inven";
        break;
    case 2:
        strKey = L"s_itemremake_error_server_impossible";
        break;
    case 3:
    case 4:
        strKey = L"s_itemremake_error_server_null_status";
        break;
    case 5:
        strKey = L"s_itemremake_error_server_lack_price";
        break;
    case 6:
    case 7:
        strKey = L"s_itemremake_error_server_fail_apply_option";
        break;
    default:
        strKey = L"s_itemremake_error_server_default";
        break;
    case 9:
        strKey = L"s_itemremake_error_server_fail_lack_lock_consume_item";
        break;
    case 10:
        strKey = L"s_content_shutdown_notice";
        break;
    }
    CStringW strMsg = FUN_14028dfa0(CStringW(strKey), nKind, eError);
    FUN_1412751f0(strMsg, 1, 1);
}

// @0x140b988d0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void TabContentsPetRemakeOption::FUN_140b988d0(unsigned __int64 uidIngredient)
{
    m_pet->FUN_1405272e0(m_petNext->FUN_140527300());
    m_pet->FUN_14052b760(ItemPtr(m_petNext));
    ItemPtr ingredient = DAT_143ab2a90.FUN_140a5d680(uidIngredient);
    if (ingredient == 0)
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_not_in_inven")), 1, 1);
        return;
    }
    FUN_140b96800(ItemPtr(m_pet), ItemPtr(m_petNext));
    FUN_140b96e60();
    vfunc_2(0xb);
}

// @0x140b98ad0
void TabContentsPetRemakeOption::FUN_140b98ad0(int nItemId)
{
    CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
    CStringW strMsg = FUN_1405c2690(CStringW(L"s_itemremake_error_prev_option_item_not_exist"), strName);
    FUN_140d73aa0(strMsg, 0, 0, CStringW(L""));
    FUN_1412751b0(strMsg, 0x14);
}
MS2_REPLACE_METHOD(0x140B98AD0, TabContentsPetRemakeOption, FUN_140b98ad0, 256, 0x0184AC03);

// ---- the option list of the remake record: push_back(const&) is this unit's COMDAT ----

template void Unk_RemakeLockOptList::push_back(const Unk_RemakeLockOpt& val);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca1330-0x142ca1440 .text$yd
