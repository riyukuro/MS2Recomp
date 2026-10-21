// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Pet evolution tab of the pet system dialog.
// MS2-UNIT: ?\tabcontentspetevolution.cpp
// MS2-RANGE: 0x140ac7740-0x140aced60 .text$mn
// MS2-RANGE: 0x1400c5c20-0x1400c5e00 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEA_KAEAH$0A@@?$pair@_KH@std@@QEAA@AEA_KAEAH@Z 0x140acc810 ; unique
// MS2-PIN: ??$?0AEB_KAEAH$0A@@?$pair@_KH@std@@QEAA@AEB_KAEAH@Z 0x140acc860 ; prop
// MS2-PIN: ?vfunc_3@PetEvolutionBase@@UEAAXXZ 0x140acdf80 ; unique
// MS2-PIN: ??A?$CAtlArray@U?$pair@_KH@std@@V?$CElementTraits@U?$pair@_KH@std@@@ATL@@@ATL@@QEAAAEAU?$pair@_KH@std@@_K@Z 0x140ace000 ; unique
// MS2-PIN: ?vfunc_5@PetEvolutionBase@@UEAAXH@Z 0x140ace4e0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??0?$MS2Ptr@VUnk_PetButton@@@@QEAA@H@Z 0x140acd3b0
// MS2-PIN: ??0?$MS2Ptr@VUnk_PetItemBag@@@@QEAA@H@Z 0x140acd430
// MS2-PIN: ?get@?$MS2Ptr@VUnk_PetButton@@@@QEBAPEAVUnk_PetButton@@XZ 0x140acd9c0
// MS2-PIN: ?get@?$MS2Ptr@VUnk_PetItemBag@@@@QEBAPEAVUnk_PetItemBag@@XZ 0x140acd9d0
// MS2-PIN: ??C?$MS2Ptr@VUnk_PetButton@@@@QEBAPEAVUnk_PetButton@@XZ 0x140acd9e0
// MS2-PIN: ??C?$MS2Ptr@VUnk_PetItemBag@@@@QEBAPEAVUnk_PetItemBag@@XZ 0x140acd9f0
// MS2-PIN: ??C?$MS2Ptr@VPetEvolutionBase@@@@QEBAPEAVPetEvolutionBase@@XZ 0x140acda00
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_PetButton@@@@AEBAXXZ 0x140ace8e0
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_PetItemBag@@@@AEBAXXZ 0x140ace910
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_PetButton@@@@CAXPEAVUnk_PetButton@@@Z 0x140ace970
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUnk_PetButton@@@@AEBAXPEAX@Z 0x140ace9d0
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_PetButton@@@@AEAAXXZ 0x140acea60
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_PetItemBag@@@@AEAAXXZ 0x140aceaa0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_PetButton@@@@AEAAXPEAX@Z 0x140aceb20
// MS2-PIN: ??0?$CAtlArray@_KV?$CElementTraits@_K@ATL@@@ATL@@QEAA@XZ 0x140acd2e0
// MS2-PIN: ??1?$MS2Ptr@VPetEvolutionBase@@@@QEAA@XZ 0x140acd740
// MS2-PIN: ??__Es_itemLevel@@YAXXZ 0x1400c5c20
// MS2-PIN: ??__Es_itemName@@YAXXZ 0x1400c5c50
// MS2-PIN: ??__Es_meso@@YAXXZ 0x1400c5c80
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400c5da0
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400c5dd0
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\tabcontentspetevolution.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "tabcontentspetevolution.h"

#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/commandchat.h"

// MS2Ptr<ASUIComponent>: the exe shares every member except these four, which are COMDATs of this unit.
template <> MS2Ptr<ASUIComponent>::MS2Ptr(MS2Ptr<ASUIComponent>&& o);                 // 0x140acd480
template <> MS2Ptr<ASUIComponent>::MS2Ptr(int nNull);                                   // 0x140acd4b0
template <> MS2Ptr<ASUIComponent>::MS2Ptr(ASUIComponent* p);                            // 0x140acd4d0
template <> bool MS2Ptr<ASUIComponent>::operator==(ASUIComponent* p) const;             // 0x140acd940
extern template class MS2Ptr<ASUIComponent>;
extern template class MS2Ptr<ASMovieClip>;
extern template class MS2Ptr<CItem>;

// ---- statics of the unit's header (the .di of this unit constructs them in this order) ----
static CString s_itemLevel("itemLevel");
static CString s_itemName("itemName");
static CString s_meso("meso");
static CStringW s_evolutionBindPet(L"evolutionBindPet");
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----

// A Scaleform value seen through its "is this an object" test (the exe calls one shared function on it).
class Unk_PetValueView { public: bool FUN_1409b4d40() const; };

// A pet menu button (m_submit, m_debug, ...): a movie clip with a frame setter.
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

// The pet part of an item (item->FUN_1405278a0()->m_pet).
class Unk_PetData : public CPtred
{
public:
    void FUN_1405cc480(MS2Ptr<Unk_PetData> src);                        // copy the pet data over
};
class Unk_PetItemInfo : public CPtred
{
public:
    MS2Ptr<Unk_PetData> m_pet;                                          // +0x18
};
MS2_CHECK_OFFSET(Unk_PetItemInfo, m_pet, 0x18);

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

// The bind state of an item.
class Unk_PetBind { public: int FUN_140635100(); int FUN_140635120(); };

// The local player: slot 77 is the name; FUN_141663450 / FUN_141663400 read and set the equipped pet item.
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
    MS2Ptr<CItem> FUN_141663450();                                      // the equipped pet item
    void FUN_141663400(MS2Ptr<CItem> item);                             // equip the pet item
};
class Unk_PetPlayerMgr { public: Unk_PetPlayer* FUN_141bd0cc0(); };
Unk_PetPlayerMgr* FUN_1403ed2d0();

// Evolution point table: the points an (item class, rank) needs for the next rank.
class Unk_PetTable { public: unsigned FUN_1403539d0(unsigned short nClass, int nRank); };
Unk_PetTable* FUN_1404a1bb0();

// Recipe table (evolution cost and the preview item's grade).
class Unk_PetRecipe
{
public:
    __int64 FUN_140679460(int nRank);                                   // meso cost of an ingredient of the rank
    short FUN_1406795e0(int nRank, unsigned short nClass);              // the next grade (0 when there is none)
};
Unk_PetRecipe* FUN_1401c0db0();

// Feature flags (slot 0x67 turns the evolution off).
class Unk_PetFlag { public: int FUN_1402c4c90(int nFlag); };
class Unk_PetFlags { public: void* p0; Unk_PetFlag flags; };
Unk_PetFlags* FUN_14025e7b0();

// Client configuration: the pet class that may be evolved by points sits at +0x84c0.
class Unk_PetUIntSlot { public: unsigned* FUN_1401d7c10(); };
class Unk_PetConfig { public: unsigned char m_pad[0x84c0]; Unk_PetUIntSlot m_petClass; };
Unk_PetConfig* FUN_1401d3200();
unsigned* FUN_1401d7c10(Unk_PetUIntSlot* pSlot);

// Locale/build switches (debug buttons).
class Unk_PetLocale;
Unk_PetLocale* FUN_14025e7c0();
unsigned char FUN_14116d720(Unk_PetLocale*);

// The item picked in the inventory dialog.
class Unk_PetSelected { public: __int64 FUN_140c8b2e0(); };
Unk_PetSelected* FUN_140535320();

// The inventory dialog (window id 0x4e2d).
class Unk_PetInventoryDialog { public: void FUN_14199a3f0(__int64 nItemUid); };
Unk_PetInventoryDialog* FUN_1405344f0(int nWindowId);

// CItem accessors the exe calls as free functions.
unsigned FUN_140528bd0(CItem* pItem);                                   // evolution point
unsigned short FUN_1405282d0(CItem* pItem);                             // item class
unsigned short FUN_140528c20(CItem* pItem);                             // pet class
Unk_PetItemInfo* FUN_1405278a0(CItem* pItem);
Unk_PetBind* FUN_140527930(CItem* pItem);
struct Unk_PeItemView { CStringW FUN_140528160(); };                     // item name (CItem member: this=rcx, hidden return=rdx)
CStringW FUN_140527b10(CItem* pItem);
__int64 FUN_140528e00(CItem* pItem);                                    // item price
int FUN_140528c60(CItem* pItem);
int FUN_140528ca0(CItem* pItem);                                        // item lock state
int FUN_140525640(CItem* pItem);
__int64 FUN_140528b40(CItem* pItem);
void FUN_140528b00(CItem* pItem, __int64 n);
short FUN_140528bf0(CItem* pItem);
void FUN_140528bf0(CItem* pItem, short n);
void FUN_14052b760(CItem* pItem, MS2Ptr<CItem> src);
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
void FUN_140b77cf0(CString* pBag, ATL::CAtlArray<TabContentsPetEvolution::IdCount>& items);

// Item icon registry and UI helpers.
void FUN_141415600(const CString& strBindID);
void FUN_141415450(const CString& strName, MS2Ptr<CItem> pItem, int a1, int a2, int a3);
void FUN_141276180(const CString& strSound, const CString& strArg);     // play a UI sound
void FUN_1412752d0(const CStringW& strMsg, int nType);                  // chat/system notice
void FUN_141275260(int nMsgId, int a1, int a2);

// String helpers.
const unsigned& FUN_1402fbd50(const unsigned& a, const unsigned& b);   // min
CStringW FUN_14028b8e0(const CStringW& str);                            // localized string
CStringW FUN_140298ea0(CStringW str);
CStringW FUN_1409e9890(CStringW fmt, const unsigned& a, const unsigned& b);
CStringW FUN_140938ae0(CStringW fmt, const int& a);
CStringW FUN_1409404f0(__int64 n);                                      // number with separators
CStringW FUN_14052bd00(int nStringId, const CStringW& str);
CStringW FUN_1408116a0(int nStringId, const int& n);
CStringW FUN_1405c2690(CStringW fmt, const CStringW& arg);
CString FUN_14038f6d0(const CString& a, const char* b);                 // a + b

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
void FUN_141276f80(Unk_CommandChat* pCmd);
void FUN_140710590(COutPacket& pkt);                                    // send

// The Value setters/getters the Invoke helpers use.
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);

extern Unk_Inventory DAT_143ab2a90;
typedef MS2Ptr<CItem> ItemPtr;
typedef TabContentsPetEvolution::IdCount IdCount;

// ---- glue: AS child control binding ----

// @0x140acd480
template <> inline MS2Ptr<ASUIComponent>::MS2Ptr(MS2Ptr<ASUIComponent>&& o)
{
    m_p = o.m_p;
    o.m_p = 0;
}

// @0x140acd4b0
template <> inline MS2Ptr<ASUIComponent>::MS2Ptr(int)
{
    m_p = 0;
}

// @0x140acd4d0
template <> inline MS2Ptr<ASUIComponent>::MS2Ptr(ASUIComponent* p)
{
    m_p = p;
    AddRef();
}

// @0x140acd940
template <> inline bool MS2Ptr<ASUIComponent>::operator==(ASUIComponent* p) const
{
    return m_p == p;
}

template <class T> inline MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// @0x140acc910 @0x140acc9c0 @0x140acca70 (Unk_ASCreate for the button, the bag and the component)

// @0x140acce30
template <> MS2Ptr<Unk_PetButton> AScript::FUN_140acce30<Unk_PetButton>(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (reinterpret_cast<const Unk_PetValueView*>(&v)->FUN_1409b4d40())
        return Unk_ASCreate<Unk_PetButton>(m_nMovieId, v);
    return MS2Ptr<Unk_PetButton>(0);
}

// @0x140accef0
template <> MS2Ptr<Unk_PetItemBag> AScript::FUN_140accef0<Unk_PetItemBag>(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (reinterpret_cast<const Unk_PetValueView*>(&v)->FUN_1409b4d40())
        return Unk_ASCreate<Unk_PetItemBag>(m_nMovieId, v);
    return MS2Ptr<Unk_PetItemBag>(0);
}

// @0x140accfb0
template <> MS2Ptr<ASUIComponent> AScript::FUN_140accfb0<ASUIComponent>(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (reinterpret_cast<const Unk_PetValueView*>(&v)->FUN_1409b4d40())
        return Unk_ASCreate<ASUIComponent>(m_nMovieId, v);
    return MS2Ptr<ASUIComponent>(0);
}

// @0x140acd070
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140acd130
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140acd1f0
inline Scaleform::GFx::Value AScript::FUN_140acd1f0(const char* szMethod, AScript a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1.FUN_1422bb890());
    return FUN_1422bb8f0(szMethod, args);
}

// ---- PetEvolutionBase ----

// @0x140acd600
inline PetEvolutionBase::PetEvolutionBase()
{
}

// @0x140acd7d0
inline PetEvolutionBase::~PetEvolutionBase()
{
}

// @0x140acd810
inline PetEvolutionPetCard::~PetEvolutionPetCard() = default;

// @0x140acd840
inline PetEvolutionPetEnchant::~PetEvolutionPetEnchant()
{
}

// @0x140acd890
inline PetEvolutionPetIngredient::~PetEvolutionPetIngredient()
{
}

// @0x140acd8c0
inline TabContentsPetEvolution::~TabContentsPetEvolution()
{
}

// @0x140ace8a0
inline void PetEvolutionBase::FUN_140ace8a0(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
}

// @0x140ace4d0
inline void PetSystemTabContents::vfunc_9(void*)
{
}

// @0x140acd570
inline Unk_CommandChat::Unk_CommandChat() : state(1), kind(0), value(0)
{
}

// @0x140acd770
inline Unk_CommandChat::~Unk_CommandChat()
{
}

// @0x140acd650
inline PetSystemTabContents::PetSystemTabContents()
{
}

// @0x140ac7740
void PetEvolutionBase::vfunc_1()
{
    vfunc_2();
}

// ---- PetEvolutionPetCard ----

// @0x140ac7770
PetEvolutionPetCard::PetEvolutionPetCard(TabContentsPetEvolution* pOwner)
    : m_strBag("PetEvolutionPetCard")
{
    m_pOwner = pOwner;
}

// @0x140ac77e0
void PetEvolutionPetCard::vfunc_2()
{
    FUN_140b77500(&m_strBag);
}

// @0x140ac7810
void PetEvolutionPetCard::vfunc_4()
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
    m_pOwner->FUN_140acaec0(ids);
    FUN_140b77500(&m_strBag);
    FUN_140b773a0(&m_strBag, ids);
    bag->FUN_1407cba60("bagId", m_strBag);
    bag->vfunc_24(1);
}

// @0x140ac7a10
void PetEvolutionPetCard::vfunc_5(int nTab)
{
    switch (nTab)
    {
    case 1:
    case 2:
    case 7:
    case 8:
        vfunc_4();
        break;
    }
}

// ---- PetEvolutionPetIngredient ----

// @0x140ac7a60
PetEvolutionPetIngredient::PetEvolutionPetIngredient(TabContentsPetEvolution* pOwner)
    : m_strBag("PetEvolutionPetIngredient")
{
    m_pOwner = pOwner;
}

// @0x140ac7ad0
void PetEvolutionPetIngredient::vfunc_2()
{
    FUN_140b77e50(&m_strBag);
}

// @0x140ac7b00
void PetEvolutionPetIngredient::vfunc_4()
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
    m_pOwner->FUN_140acaef0(items);
    FUN_140b77e50(&m_strBag);
    FUN_140b77cf0(&m_strBag, items);
    bag->FUN_1407cba60("bagId", m_strBag);
    bag->vfunc_24(1);
}

// @0x140ac7d00
void PetEvolutionPetIngredient::vfunc_5(int nTab)
{
    switch (nTab)
    {
    case 1:
    case 2:
    case 7:
    case 8:
    case 10:
    case 11:
        vfunc_4();
    }
}

// ---- PetEvolutionPetEnchant ----

// @0x140ac7d90
PetEvolutionPetEnchant::PetEvolutionPetEnchant(TabContentsPetEvolution* pOwner)
    : m_strBag("PetEvolutionPetEnchantBag"), m_strTarget("PetEvolutionPetEnchantTarget"), m_strResult("PetEvolutionPetEnchantResult")
{
    m_pOwner = pOwner;
}

// @0x140ac7e30
void PetEvolutionPetEnchant::vfunc_2()
{
    FUN_140b77e50(&m_strBag);
    FUN_140b77500(&m_strTarget);
    FUN_141415600(m_strResult);
}

// @0x140ac7e80
void PetEvolutionPetEnchant::vfunc_3()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140acaea0());
    if (pet == 0)
        return;
    unsigned nPoint = FUN_140528bd0(pet);
    int nRank = pet->FUN_140526bd0();
    unsigned short nClass = FUN_1405282d0(pet);
    unsigned nNeed = FUN_1404a1bb0()->FUN_1403539d0(nClass, nRank);
    unsigned short nPetClass = FUN_140528c20(pet);
    unsigned char bDebug = FUN_14116d720(FUN_14025e7c0());
    MS2Ptr<Unk_PetButton> submit = ench->FUN_140acce30<Unk_PetButton>(CString("m_submit"));
    if (submit.get() != 0)
    {
        ATL::CAtlArray<IdCount> selected;
        m_pOwner->FUN_140acaf20(selected);
        unsigned nPetClass2 = nPetClass;
        if (nPetClass2 == *FUN_1401d7c10(&FUN_1401d3200()->m_petClass) && selected.GetCount() != 0)
            submit->FUN_1422c1fe0(1);
        else if (nNeed == 0 || nPoint < nNeed)
            submit->FUN_1422c1fe0(0);
        else
            submit->FUN_1422c1fe0(1);
    }
    submit = 0;
    MS2Ptr<Unk_PetButton> debug = ench->FUN_140acce30<Unk_PetButton>(CString("m_debug"));
    if (debug.get() != 0)
        debug->vfunc_4(bDebug);
    debug = 0;
    MS2Ptr<Unk_PetButton> debug30 = ench->FUN_140acce30<Unk_PetButton>(CString("m_debug30"));
    if (debug30.get() != 0)
        debug30->vfunc_4(bDebug);
    debug30 = 0;
    MS2Ptr<ASUIComponent> bar = ench->FUN_140accfb0<ASUIComponent>(CString("m_pointBar"));
    if (bar.get() != 0)
    {
        nPoint += m_pOwner->FUN_140acb6f0();
        if (nNeed < nPoint)
            bar->Invoke("setText", FUN_1409e9890(CStringW(L"s_pet_evolution_point"), nPoint, nNeed));
        else
            bar->Invoke("setText", StringFormat(L"{0}/{1}", nPoint, nNeed));
        bar->Invoke("setPercentTween", (int)FUN_1402fbd50(nPoint, nNeed), (int)nNeed);
    }
}

// @0x140ac8530
void PetEvolutionPetEnchant::vfunc_4()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    MS2Ptr<Unk_PetItemBag> bag = ench->FUN_140accef0<Unk_PetItemBag>(CString("m_itemBag"));
    if (bag.get() != 0)
    {
        ATL::CAtlArray<IdCount> items;
        m_pOwner->FUN_140acaf20(items);
        FUN_140b77e50(&m_strBag);
        FUN_140b77cf0(&m_strBag, items);
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(1);
    }
    bag = 0;
    MS2Ptr<Unk_PetButton> submit = ench->FUN_140acce30<Unk_PetButton>(CString("m_submit"));
    if (submit.get() != 0)
        submit->FUN_1422c1fe0(0);
    submit = 0;
    ASObj obj(2);
    int nZero = 0;
    obj.FUN_1407cbb20(s_meso, FUN_1408116a0(0x986, nZero));
    ench->FUN_140acd1f0("selectPetIngredient", AScript(obj));
}

// @0x140ac88d0
void PetEvolutionPetEnchant::vfunc_5(int nTab)
{
    switch (nTab)
    {
    case 1:
    case 2:
    case 10:
        vfunc_4();
        vfunc_3();
        FUN_140ac8a00();
        break;
    case 7:
        vfunc_4();
        vfunc_3();
        FUN_140ac9520();
        break;
    case 8:
        vfunc_4();
        vfunc_3();
        FUN_140ac9a60();
        break;
    case 0xb:
        vfunc_4();
        vfunc_3();
        FUN_140ac9140();
    }
}

#ifndef MS2_HOOK_DLL
// @0x140ac8a00
void PetEvolutionPetEnchant::FUN_140ac8a00()
{
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0 || m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140acaea0());
    if (pet == 0)
        return;
    int nRank = pet->FUN_140526bd0();
    unsigned nNeed = FUN_1404a1bb0()->FUN_1403539d0(FUN_1405282d0(pet), nRank);
    unsigned short nPetClass = FUN_140528c20(pet);
    ATL::CAtlArray<unsigned __int64> ids;
    ids.Add(m_pOwner->FUN_140acaea0());
    FUN_140b77500(&m_strBag);
    FUN_140b773a0(&m_strTarget, ids);
    ASObj obj(2);
    if (nNeed == 0)
    {
        obj.FUN_1409c0e60("frame", L"notice");
        obj.FUN_1407cbb20("evolutionMsg", FUN_14028b8e0(CStringW(L"s_pet_evolution_max")));
        obj.FUN_1407cba60("bagId", m_strTarget);
        ench->FUN_140acd1f0("notice", AScript(obj));
    }
    else
    {
        obj.FUN_1409c0dc0("frame", "select");
        obj.FUN_1407cbb20(s_itemName, reinterpret_cast<Unk_PeItemView*>(pet.get())->FUN_140528160());
        obj.FUN_1409c48f0(s_itemLevel, nPetClass);
        int nZero = 0;
        obj.FUN_1407cbb20(s_meso, FUN_1408116a0(0x986, nZero));
        obj.FUN_1409c0d20("petEvolutionPoint", FUN_140528bd0(pet));
        obj.FUN_1407cba60("bagId", m_strTarget);
        obj.FUN_1407cbb20("resultMsg", FUN_14028b8e0(CStringW(L"s_pet_evolution_notice")));
        obj.FUN_1407cba60("bagId", m_strTarget);
        obj.FUN_1409c0d20("requirePoint", nNeed);
        if (nNeed <= FUN_140528bd0(pet))
        {
            obj.FUN_1407cbbe0("isEvolution", true);
            obj.FUN_1407cbb20("evolutionMsg", FUN_140298ea0(CStringW(L"s_pet_evolution_enable_evolution")));
        }
        FUN_140ac9e20(obj);
        ench->FUN_140acd1f0("selectPetCard", AScript(obj));
    }
    FUN_141276180(CString("pet_Button_Click"), CString(""));
}
#endif

// @0x140ac9140
void PetEvolutionPetEnchant::FUN_140ac9140()
{
    if (m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140acaea0());
    if (pet == 0)
        return;
    ATL::CAtlArray<IdCount> selected;
    m_pOwner->FUN_140acaf20(selected);
    __int64 nTotal = 0;
    for (unsigned i = 0; i < selected.GetCount(); i++)
    {
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(selected[i].first);
        if (!(item == 0))
        {
            __int64 nCost = 0;
            if (FUN_140525640(item) != 0)
                nCost = FUN_1401c0db0()->FUN_140679460(item->FUN_140526bd0());
            nTotal += nCost;
        }
    }
    ASObj obj(2);
    obj.FUN_1407cbb20(s_meso, FUN_14052bd00(0x986, FUN_1409404f0(nTotal)));
    ench->FUN_140acd1f0("selectPetIngredient", AScript(obj));
    FUN_141276180(CString("pet_Button_Click"), CString(""));
}

// @0x140ac9520
void PetEvolutionPetEnchant::FUN_140ac9520()
{
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0 || m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140acaea0());
    if (pet == 0)
        return;
    int nRank = pet->FUN_140526bd0();
    unsigned nNeed = FUN_1404a1bb0()->FUN_1403539d0(FUN_1405282d0(pet), nRank);
    int nState = m_pOwner->FUN_140acb830();
    CStringW strResult = FUN_140938ae0(CStringW(L"s_pet_evolution_success"), nState);
    CStringW strMax = FUN_140298ea0(CStringW(L"s_pet_evolution_max"));
    ASObj obj(2);
    obj.FUN_1407cbb20(s_itemName, reinterpret_cast<Unk_PeItemView*>(pet.get())->FUN_140528160());
    obj.FUN_1407cbb20("resultMsg", strResult);
    if (nNeed == 0)
        obj.FUN_1407cbb20("evolutionMsg", strMax);
    obj.FUN_1407cba60("bagId", m_strTarget);
    ench->FUN_140acd1f0("resultEvolution", AScript(obj));
    FUN_141276180(CString("pet_Evolution_Success02"), CString(""));
    Unk_PetInventoryDialog* pInven = FUN_1405344f0(0x4e2d);
    if (pInven != 0)
        pInven->FUN_14199a3f0(m_pOwner->FUN_140acaea0());
    ItemPtr equipped = player->FUN_141663450();
    if (equipped.get() != 0)
    {
        __int64 idPet = pet->FUN_140526a50();
        if (idPet == equipped->FUN_140526a50())
            player->FUN_141663400(ItemPtr(pet));
    }
}

// @0x140ac9a60
void PetEvolutionPetEnchant::FUN_140ac9a60()
{
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0 || m_pOwner == NULL)
        return;
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140acaea0());
    if (pet == 0)
        return;
    int nRank = pet->FUN_140526bd0();
    unsigned nNeed = FUN_1404a1bb0()->FUN_1403539d0(FUN_1405282d0(pet), nRank);
    int nState = m_pOwner->FUN_140acb830();
    CStringW strPointUp = FUN_140938ae0(CStringW(L"s_pet_evolution_pointup_success"), nState);
    CStringW strEnable = FUN_140298ea0(CStringW(L"s_pet_evolution_enable_evolution"));
    ASObj obj(2);
    if (FUN_140528bd0(pet) < nNeed)
        obj.FUN_1407cbb20("resultMsg", strPointUp);
    else
        obj.FUN_1407cbb20("evolutionMsg", strEnable);
    ench->FUN_140acd1f0("resultEvolutionPoint", AScript(obj));
    FUN_141276180(CString("pet_Evolution_Success"), CString(""));
}

// @0x140ac9e20
void PetEvolutionPetEnchant::FUN_140ac9e20(ASObj& obj)
{
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_pOwner->FUN_140acaea0());
    if (pet == 0)
        return;
    Unk_PetItemInfo* info = FUN_1405278a0(pet);
    if (info == 0)
        return;
    ItemPtr preview(new CItem);
    int nNextRank = pet->FUN_140526bd0();
    nNextRank = nNextRank + 1;
    short nGrade = FUN_1401c0db0()->FUN_1406795e0(nNextRank, FUN_1405282d0(pet));
    if (nGrade == 0)
        return;
    int nItemId = pet->FUN_1405276c0();
    if (preview->FUN_14052b130(nItemId, nNextRank, 0) == 0)
        return;
    __int64 nUnk = FUN_140528b40(pet);
    FUN_140528b00(preview, nUnk);
    FUN_14052b760(preview, ItemPtr(pet));
    FUN_140528bf0(preview, nGrade);
    if (FUN_1405278a0(preview) != 0)
        FUN_1405278a0(preview)->m_pet->FUN_1405cc480(info->m_pet);
    MS2Ptr<ASUIComponent> ench = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_petEnchant"));
    if (ench == 0)
        return;
    MS2Ptr<ASMovieClip> evolutionSlot = ench->FUN_1409b4560(CString("m_evolutionSlot"));
    if (evolutionSlot == 0)
        return;
    MS2Ptr<ASMovieClip> slot = evolutionSlot->FUN_1409b4560(CString("m_slot"));
    if (slot == 0)
        return;
    FUN_141415600(m_strResult);
    FUN_141415450(m_strResult, ItemPtr(preview), 0, 0, 0x10800);
    obj.FUN_1407cbb20(FUN_14038f6d0(s_itemName, "2"), reinterpret_cast<Unk_PeItemView*>(preview.get())->FUN_140528160());
    slot->Invoke("setData", CString(m_strResult));
}

// ---- TabContentsPetEvolution ----

// @0x140aca490
// MS2-FUNCTIONAL: the exe zeroes the first 0x18 bytes (rep stosb) before the base constructor
TabContentsPetEvolution::TabContentsPetEvolution()
    : m_nState(0), m_uidPet(0), m_parts(10), m_ui(0)
{
    m_parts.AddTail(MS2Ptr<PetEvolutionBase>(new PetEvolutionPetCard(this)));
    m_parts.AddTail(MS2Ptr<PetEvolutionBase>(new PetEvolutionPetIngredient(this)));
    m_parts.AddTail(MS2Ptr<PetEvolutionBase>(new PetEvolutionPetEnchant(this)));
}

// @0x140aca700
void TabContentsPetEvolution::vfunc_1()
{
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetEvolutionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_1();
        m_parts.GetNext(pos);
    }
    m_ui = 0;
}

// @0x140aca7e0
void TabContentsPetEvolution::vfunc_4()
{
    m_uidPet = 0;
    m_petCards.RemoveAll();
    m_pool.RemoveAll();
    m_selected.RemoveAll();
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetEvolutionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_2();
        m_parts.GetNext(pos);
    }
}

// @0x140aca8f0
void TabContentsPetEvolution::vfunc_2(int nTab)
{
    if (m_ui == 0)
        return;
    if (0 < nTab)
    {
        if (nTab < 3)
        {
            FUN_140acb850();
            FUN_140acba80();
            FUN_140acbd40();
        }
        else if (6 < nTab && nTab < 9)
        {
            FUN_140acb850();
            FUN_140acba80();
            FUN_140acbd40();
        }
    }
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetEvolutionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_5(nTab);
        m_parts.GetNext(pos);
    }
}

// @0x140acaa50
void TabContentsPetEvolution::vfunc_3(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
    FUN_140acb850();
    FUN_140acba80();
    FUN_140acbd40();
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetEvolutionBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
        {
            p->FUN_140ace8a0(ui);
            p->vfunc_4();
            p->vfunc_3();
        }
        m_parts.GetNext(pos);
    }
}

// @0x140acabf0
int TabContentsPetEvolution::vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (_stricmp("OnSelectPetCard", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140acbd70(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnSelectPetIngredient", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140acbe00(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnSelectPetEnchant", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140acc1d0(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnPetEnchant", szEvent) == 0)
    {
        FUN_140acaf50(0);
        return 1;
    }
    if (_stricmp("OnPetEnchantDebug", szEvent) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140acb560(data.FUN_1422b8a10());
        return 1;
    }
    return 0;
}

// @0x140acae80
int TabContentsPetEvolution::vfunc_8()
{
    return 4;
}

// @0x140acaea0
unsigned __int64 TabContentsPetEvolution::FUN_140acaea0()
{
    return m_uidPet;
}

// @0x140acaec0
void TabContentsPetEvolution::FUN_140acaec0(ATL::CAtlArray<unsigned __int64>& out)
{
    out.Copy(m_petCards);
}

// @0x140acaef0
void TabContentsPetEvolution::FUN_140acaef0(ATL::CAtlArray<IdCount>& out)
{
    out.Copy(m_pool);
}

// @0x140acaf20
void TabContentsPetEvolution::FUN_140acaf20(ATL::CAtlArray<IdCount>& out)
{
    out.Copy(m_selected);
}

// @0x140acaf50
// MS2-FUNCTIONAL: frame layout of the message box and packet branches differs
void TabContentsPetEvolution::FUN_140acaf50(int bUsePoint)
{
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    Unk_PetPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0)
        return;
    if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x67) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return;
    }
    unsigned nPoint = FUN_140528bd0(pet);
    int nRank = pet->FUN_140526bd0();
    unsigned nNeed = FUN_1404a1bb0()->FUN_1403539d0(FUN_1405282d0(pet), nRank);
    FUN_140acb810(0);
    if (nNeed <= nPoint)
    {
        COutPacket pkt(0x78, 0);
        pkt.Encode1(0x11);
        pkt.Encode8(m_uidPet);
        FUN_140710590(pkt);
        return;
    }
    if (m_selected.IsEmpty())
        return;
    if (bUsePoint == 0)
    {
        if (FUN_140527930(pet)->FUN_140635100() != 0 && FUN_140527930(pet)->FUN_140635120() == 0)
        {
            CStringW strMsg = FUN_1405c2690(L"s_msg_transfer_bind_pet_evolution", player->vfunc_77());
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x11, strMsg, 0, s_evolutionBindPet);
            if (box.get() != 0)
            {
                FUN_141a01600(box.operator->(), pet->FUN_140526a50());
                FUN_141a01ee0(box.operator->(), ItemPtr(pet), FUN_140527b10(pet), 1, 0, -1, -1, 1);
                FUN_141a01700(box.operator->(), 0x477, 0x478, 0);
                FUN_140d73c60(box);
                return;
            }
        }
    }
    COutPacket pkt(0x78, 0);
    pkt.Encode1(0x12);
    pkt.Encode8(m_uidPet);
    pkt.Encode2((short)m_selected.GetCount());
    for (size_t i = 0; i < m_selected.GetCount(); i++)
        pkt.Encode8(m_selected[i].first);
    FUN_140710590(pkt);
    FUN_140acb810(FUN_140acb6f0());
}

// @0x140acb560
void TabContentsPetEvolution::FUN_140acb560(unsigned nPoint)
{
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(FUN_140acaea0());
    if (pet == 0)
        return;
    unsigned nHave = FUN_140528bd0(pet);
    int nRank = pet->FUN_140526bd0();
    unsigned nNeed = FUN_1404a1bb0()->FUN_1403539d0(FUN_1405282d0(pet), nRank);
    if (nHave < nNeed)
    {
        FUN_140acb810(nPoint);
        Unk_CommandChat cmd;
        cmd.kind = 0;
        cmd.message = StringFormat(L"/petevolutionpoint {0} {1}", m_uidPet, nPoint);
        FUN_141276f80(&cmd);
    }
}

// @0x140acb6f0
int TabContentsPetEvolution::FUN_140acb6f0()
{
    int nTotal = 0;
    for (unsigned i = 0; i < m_selected.GetCount(); i++)
    {
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(m_selected[i].first);
        if (!(item == 0))
        {
            int nAdd;
            if (FUN_140528bd0(item) == 0)
                nAdd = 1;
            else
                nAdd = FUN_140528bd0(item);
            nTotal += nAdd;
        }
    }
    return nTotal;
}

// @0x140acb810
void TabContentsPetEvolution::FUN_140acb810(int nState)
{
    m_nState = nState;
}

// @0x140acb830
int TabContentsPetEvolution::FUN_140acb830()
{
    return m_nState;
}

// @0x140acb850
void TabContentsPetEvolution::FUN_140acb850()
{
    m_petCards.RemoveAll();
    m_pool.RemoveAll();
    m_selected.RemoveAll();
    ATL::CAtlArray<unsigned __int64> ids;
    DAT_143ab2a90.FUN_140a609a0(9, ids);
    for (unsigned i = 0; i < ids.GetCount(); i++)
    {
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(ids[i]);
        if (!(item == 0))
        {
            int nKey = FUN_14053dc60(item->FUN_140527840());
            MS2Ptr<Unk_PetRow> row = FUN_14052d210()->FUN_1407290f0(nKey);
            if (!(row == 0))
            {
                if (row->m_nFlag != 0)
                {
                    unsigned nPetClass = FUN_140528c20(item);
                    if (nPetClass == *FUN_1401d7c10(&FUN_1401d3200()->m_petClass))
                        m_petCards.Add(item->FUN_140526a50());
                }
            }
        }
    }
}

// @0x140acba80
void TabContentsPetEvolution::FUN_140acba80()
{
    m_pool.RemoveAll();
    m_selected.RemoveAll();
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    int nRank = pet->FUN_140526bd0();
    unsigned nNeed = FUN_1404a1bb0()->FUN_1403539d0(FUN_1405282d0(pet), nRank);
    if (nNeed == 0)
        return;
    ATL::CAtlArray<unsigned __int64> ids;
    DAT_143ab2a90.FUN_140a609a0(9, ids);
    for (unsigned i = 0; i < ids.GetCount(); i++)
    {
        __int64 id = ids[i];
        ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
        if (!(item == 0))
        {
            if (FUN_140535320()->FUN_140c8b2e0() == id)
                continue;
            if (m_uidPet == id)
                continue;
            int nKeyItem = FUN_14053dc60(item->FUN_140527840());
            if (nKeyItem == FUN_14053dc60(pet->FUN_140527840()))
            {
                int nItemRank = item->FUN_140526bd0();
                if (nItemRank == pet->FUN_140526bd0())
                    m_pool.Add(FUN_140acc7d0(id));
            }
        }
    }
}

// @0x140acbd40
void TabContentsPetEvolution::FUN_140acbd40()
{
    m_selected.RemoveAll();
}

// @0x140acbd70
void TabContentsPetEvolution::FUN_140acbd70(int nIndex)
{
    if (nIndex < 0 || nIndex >= (int)m_petCards.GetCount())
        return;
    m_uidPet = m_petCards[nIndex];
    FUN_140acba80();
    FUN_140acbd40();
    vfunc_2(10);
}

// @0x140acbe00
void TabContentsPetEvolution::FUN_140acbe00(int nIndex)
{
    if (-1 < nIndex && nIndex < (int)m_pool.GetCount())
    {
        ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
        if (!(pet == 0))
        {
            unsigned __int64 id = m_pool[nIndex].first;
            ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
            if (!(item == 0))
            {
                __int64 nPrice = FUN_140528e00(item);
                unsigned short nPetClass = FUN_140528c20(pet);
                unsigned nPoint = FUN_140528bd0(pet);
                int nRank = pet->FUN_140526bd0();
                unsigned nNeed = FUN_1404a1bb0()->FUN_1403539d0(FUN_1405282d0(pet), nRank);
                unsigned nTotal = nPoint + FUN_140acb6f0();
                if (FUN_140528c60(item) != 0)
                {
                    FUN_1412752d0(CStringW(L"s_err_cannot_evolution_petitem_hasitem"), 1);
                }
                else if (FUN_140528ca0(item) == 0 && FUN_140869440() < nPrice)
                {
                    FUN_1412752d0(CStringW(L"s_itemlock_invalid_petevolution"), 1);
                }
                else if (FUN_140528ca0(item) == 1)
                {
                    FUN_1412752d0(CStringW(L"s_itemlock_invalid_petevolution"), 1);
                }
                else if (nTotal < nNeed)
                {
                    unsigned nClass = nPetClass;
                    if (nClass == *FUN_1401d7c10(&FUN_1401d3200()->m_petClass))
                    {
                        unsigned nMax = 0xc;
                        if (11 < m_selected.GetCount())
                            return;
                        if (FUN_140acc4e0(id) != 0)
                            vfunc_2(0xb);
                    }
                    else
                    {
                        FUN_1412752d0(CStringW(L"s_pet_not_evolution"), 1);
                    }
                }
                else
                {
                    FUN_1412752d0(CStringW(L"s_err_cannot_evolution_consume"), 1);
                }
            }
        }
    }
}

// @0x140acc1d0
void TabContentsPetEvolution::FUN_140acc1d0(int nIndex)
{
    if (nIndex < 0 || nIndex >= (int)m_selected.GetCount())
        return;
    ItemPtr pet = DAT_143ab2a90.FUN_140a5d680(m_uidPet);
    if (pet == 0)
        return;
    FUN_140acc380(nIndex);
    vfunc_2(0xb);
}

// @0x140acc280
int TabContentsPetEvolution::FUN_140acc280(ATL::CAtlArray<IdCount>& arr, unsigned __int64 id)
{
    for (size_t i = 0; i < arr.GetCount(); i++)
    {
        IdCount& e = arr[i];
        if (id == e.first)
            return (int)i;
    }
    return -1;
}

// @0x140acc300
unsigned __int64 TabContentsPetEvolution::FUN_140acc300(ATL::CAtlArray<IdCount>& arr, int nIndex)
{
    if (nIndex < 0)
        return 0;
    for (size_t i = 0; i < arr.GetCount(); i++)
    {
        if (i == (size_t)nIndex)
        {
            IdCount& e = arr[i];
            return e.first;
        }
    }
    return 0;
}

// @0x140acc380
int TabContentsPetEvolution::FUN_140acc380(int nIndex)
{
    const unsigned __int64 id = FUN_140acc300(m_selected, nIndex);
    ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
    if (item.get() == 0)
        return 0;
    m_selected.RemoveAt(nIndex, 1);
    int nPos = FUN_140acc280(m_pool, id);
    if (nPos < 0)
    {
        int nOne = 1;
        m_pool.Add(IdCount(id, nOne));
    }
    else
    {
        m_pool[nPos].second++;
    }
    return 1;
}

// @0x140acc4e0
int TabContentsPetEvolution::FUN_140acc4e0(unsigned __int64 id)
{
    int nPos = FUN_140acc280(m_pool, id);
    if (nPos < 0)
        return 0;
    if (FUN_140acc650(id) == 0)
        return 0;
    IdCount& entry = m_pool[nPos];
    entry.second--;
    if (entry.second == 0)
        m_pool.RemoveAt(nPos, 1);
    ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
    if (item.get() == 0)
        return 0;
    m_selected.Add(FUN_140acc7d0(id));
    return 1;
}

// @0x140acc650
int TabContentsPetEvolution::FUN_140acc650(unsigned __int64 id)
{
    ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
    if (!(item == 0))
    {
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
        if (nUsed < (int)nHave)
            return nHave - nUsed;
        return 0;
    }
    return 0;
}

// @0x140acc7d0
TabContentsPetEvolution::IdCount TabContentsPetEvolution::FUN_140acc7d0(unsigned __int64 id)
{
    int nOne = 1;
    return IdCount(id, nOne);
}

// @0x140acec10
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

MS2_REPLACE_METHOD(0x140AC7740, PetEvolutionBase, vfunc_1, 30, 0x7BC078D9);
MS2_REPLACE_METHOD(0x140AC77E0, PetEvolutionPetCard, vfunc_2, 31, 0xFB341541);
MS2_REPLACE_METHOD(0x140AC7AD0, PetEvolutionPetIngredient, vfunc_2, 31, 0xB45999E8);
MS2_REPLACE_METHOD(0x140AC7D00, PetEvolutionPetIngredient, vfunc_5, 83, 0xA5579BB4);
MS2_REPLACE_METHOD(0x140AC7E30, PetEvolutionPetEnchant, vfunc_2, 65, 0x0DD59B63);
MS2_REPLACE_METHOD(0x140ACAE80, TabContentsPetEvolution, vfunc_8, 11, 0x85F76FBF);
MS2_REPLACE_METHOD(0x140ACAEA0, TabContentsPetEvolution, FUN_140acaea0, 15, 0xCBEE5D21);
MS2_REPLACE_METHOD(0x140ACAEC0, TabContentsPetEvolution, FUN_140acaec0, 41, 0x10E7944F);
MS2_REPLACE_METHOD(0x140ACAEF0, TabContentsPetEvolution, FUN_140acaef0, 41, 0xD06597EE);
MS2_REPLACE_METHOD(0x140ACAF20, TabContentsPetEvolution, FUN_140acaf20, 41, 0x8918D4BE);
MS2_REPLACE_METHOD(0x140ACB810, TabContentsPetEvolution, FUN_140acb810, 22, 0x068001AB);
MS2_REPLACE_METHOD(0x140ACB830, TabContentsPetEvolution, FUN_140acb830, 14, 0x72E52537);
MS2_REPLACE_METHOD(0x140ACBD40, TabContentsPetEvolution, FUN_140acbd40, 31, 0x6D578E79);
MS2_REPLACE_METHOD(0x140ACC7D0, TabContentsPetEvolution, FUN_140acc7d0, 57, 0xDB3DD032);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9ff40-0x142ca0030 .text$yd
