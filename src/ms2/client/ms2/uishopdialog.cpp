// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The NPC shop window (UIShopDialog, UI id 0x4e3b).
// MS2-UNIT: ?\uishopdialog.cpp
// MS2-RANGE: 0x14011d540-0x14011d8d0 .text$di
// MS2-RANGE: 0x141af2110-0x141b0cc00 .text$mn
// File name assumed (the class name). Bodies cross-checked with the v2525 snapshot (tu/141af1ff0.cpp); helper names
// are invented. The TU ends with the template glue (delegates, STL map / vector, CAtlArray, MS2Ptr COMDATs).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uishopdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uishopdialog.h"
#include "mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "npcshopproductbase.h"
#include "shoptabinfo.h"
#include "itempreview.h"
#include "uiequipiconcontainer.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>

// ---- unit-local placeholders (names invented) -------------------------------------------------------------------

// The "m_money" label of the star shop (an ASUIComponent; text setter 0x1422e4b80).
class ASLabel : public ASDisplayObject
{
public:
    void FUN_1422e4b80(const CStringW& strText);
};

// The "openWindowPos" UI message sent to the inventory (ASData + type, 0x50 bytes).
class Unk_ShopUIMsg : public UIMsg
{
public:
    Unk_ShopUIMsg();                                        // 0x1422e4490
    ~Unk_ShopUIMsg();                                       // 0x140c30570
    void FUN_1422b82b0(const char* pszMethod);
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};

// The token money change notice (RTTI .?AVNotifyChangedTokenMoney@@; scenestategame.cpp creates it).
class NotifyChangedTokenMoney : public NotifyObject
{
public:
    virtual ~NotifyChangedTokenMoney();
    virtual CStringW vfunc_1();                             // 0x140db4610
    int m_nType;                                            // +0x18
    __int64 m_nValue;                                       // +0x20
    __int64 m_nDelta;                                       // +0x28
};
MS2_CHECK_SIZE(NotifyChangedTokenMoney, 0x30);

// The inventory dialog (UI id 0x4e2d): the shop opens beside it.
class UIInventoryDialog : public UIDialog
{
};
UIInventoryDialog* FUN_1405344f0(int nUiId);

// The dialog manager (show / hide by UI id).
class Unk_ShopUIManager
{
public:
    void FUN_141adc530(int nUiId);                          // show
    void FUN_141adc5d0(int nUiId);                          // hide
    int FUN_141adc890(int nUiId);                           // is shown
};
Unk_ShopUIManager* FUN_1403ed2b0();

// The world service: the local player.
class Unk_ShopWorld
{
public:
    MyPC* FUN_141bd0cc0();
};
Unk_ShopWorld* FUN_1403ed2d0();

// The shop category table (reload on open).
class Unk_ShopCategories { public: bool FUN_1407cb390(bool bForce); };
Unk_ShopCategories* FUN_1406aa4b0();

// The talk (npc conversation) manager and the network service (npc talk state).
class Unk_ShopTalk { public: void FUN_141b1feb0(); };
Unk_ShopTalk* FUN_140967100();
class Unk_ShopNetwork { public: void FUN_141538c40(int nNpcObject, int nState); };
Unk_ShopNetwork* FUN_140714f90();

// The ugc / merat market service: the dialog's pending requests.
class Unk_ShopMarket { public: void FUN_140d5a200(const int& nUiId); };
Unk_ShopMarket* FUN_140939a00();

// The gacha box table: the coin item of a gacha shop.
class Unk_ShopGacha { public: int FUN_14059e550(int nShopId); int FUN_14059ee00(int nShopId); };
Unk_ShopGacha* FUN_14052d230();

// The dialog offsets of the inventory placement.
struct Unk_ShopXY { float x, y; };
extern Unk_ShopXY DAT_143b02320;                            // zero offset
void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, Unk_ShopXY offLeft, Unk_ShopXY offRight);
Unk_ShopXY* FUN_140a0a600(Unk_ShopXY* pThis, float x, float y);    // efd::Point2 ctor

// The game event values (shop talk, give point, reset price sale).
CGameEventValueManager* FUN_140302b00();
unsigned FUN_1404271c0(Unk_GameEventLockedValue<0x78>* pValue, unsigned nNpcId);           // talk text id
MS2Ptr<CNpcShopGivePointContextBase> FUN_1404273a0(Unk_GameEventLockedValue<0x78>* pValue, unsigned nShopId);
unsigned FUN_1404275a0(Unk_GameEventLockedValue<0x78>* pValue, unsigned nShopId);          // reset discount (%)

// Misc helpers.
NotifySystem* FUN_140939a10();
PacketHandlerManager* FUN_140bccd50();
UIStatusEventDispatcher* FUN_140aa6d40();
__int64 FUN_140869440();                                    // the server time
bool FUN_14086ab70(CMsTime t1, CMsTime t2, int nHour);      // the day changed between the two times
void FUN_140710590(COutPacket& packet);                     // send
__int64 FUN_1405957d0(__int64 nPrice, unsigned nDiscount);  // apply a discount
CStringW FUN_1418fec00(int nType, unsigned __int64 nAmount, bool bShort);   // the currency text
CStringW FUN_1409404f0(__int64 nValue);                     // number with separators
void FUN_141349f30(CStringW& strOut, int nType, int nToken, int nPrice, const CString& strTag);   // price text
void FUN_1412761e0(MS2Ptr<AScript> spRoot, int bEnable);    // enable the shop movie
bool FUN_1406a5930();                                       // the star point event is running
unsigned __int64 FUN_140718350(const CString& s);           // _atoi64
CStringW FUN_14028b8e0(const CStringW& strKey);             // string table text
CStringTable* FUN_1401a9d70();
CLogString* FUN_140166440();

// The unit's two-argument log call (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class T, class U>
inline void Unk_ShopLog(CLogString* log, int level, int category, const wchar_t* format, const T& first, const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// The packet readers' notices and helpers.
int FUN_140869470(int nDays);                               // days -> seconds
int FUN_14086b490(int nYear, int nMonth);                   // days in the month
CStringW FUN_140b99450(CStringW strKey, const CStringW& strA, const int& nB);
void FUN_1412751f0(const CStringW& strText, int nA, int nB);
void FUN_1412751b0(const CStringW& strText, int nType);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_14134a120(int nKind, int nItemId, int nAmount);    // the not-enough-currency notice
int FUN_141276180(const CString& strSound, const CString& strArg);
CStringW FUN_14183e9c0(CStringW strName, int nRank);        // the item name in its rank colour
CStringW FUN_140bfa7f0(CStringW strKey, const CStringW& strArg, const int& nCount);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_1409e97f0(int nId, const int& nArg);
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_140a228f0(int nId, const int& nArg, const CStringW& strArg);
CStringW FUN_1409eec40(int nId);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
bool FUN_141b046e0(int nGroup);                            // a valid product group (0..2)
class Unk_ShopChat { public: void FUN_1416fb300(CStringW& strText); };
Unk_ShopChat* FUN_1403b4750();
class Unk_ShopInventory { public: int FUN_140a5f180(int nItemId, int nRank); };
extern Unk_ShopInventory DAT_143ab2a90;                     // the player's inventory
CStringW FUN_1418fec90(int nType, __int64 nAmount, int nCost);
void FUN_1418fffd0(ASObj* pTab, int nGroup, const CStringW& strTitle, const CStringW& strTooltip);

template <class T>
inline void Unk_ShopLog(CLogString* log, int level, int category, const wchar_t* format, const T& value)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(value)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(value), args));
}
template <class T, class U, class V>
inline void Unk_ShopLog(CLogString* log, int level, int category, const wchar_t* format, const T& first, const U& second,
                        const V& third)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(third)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third), args));
}

// ---- statics of the unit (dynamic initializers 0x14011d540..0x14011d8a0) ----------------------------------------

static CString s_premiumSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strJobCode("jobCode");
static CString s_strSortValue("sortValue");
static CString s_strTabIndex("tabIndex");
static CString s_strBuySound("shop_itembuy");
static CString s_strResetSound("shop_reset");
static CString s_strErrorSound("system_notice_error_warningBag");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141af2110
UIShopDialog::DirtyState::DirtyState()
{
    m_nFlags = 0;
}

void FUN_1418ffec0(unsigned* pFlags, unsigned nBit);        // set
void FUN_1418ffef0(unsigned* pFlags, unsigned nBit);        // clear
bool FUN_1418ffe80(unsigned nFlags, unsigned nBit);         // test

// @0x141af2150
void UIShopDialog::DirtyState::AddSale(const int& nId)
{
    FUN_1418ffec0(&m_nFlags, 1);
    if (m_spSale == 0)
        m_spSale = MS2Ptr<UIMeratMarketCommon::TDirtyPremiumSale>(new UIMeratMarketCommon::TDirtyPremiumSale);
    if (m_spSale.get())
        m_spSale->Add(nId);
}
MS2_REPLACE_METHOD(0x141AF2150, UIShopDialog::DirtyState, AddSale, 193, 0x41AE6227);

// @0x141af2220
void UIShopDialog::DirtyState::ClearSale()
{
    FUN_1418ffef0(&m_nFlags, 1);
    m_spSale = 0;
}
MS2_REPLACE_METHOD(0x141AF2220, UIShopDialog::DirtyState, ClearSale, 51, 0x036C2EB0);

// @0x141af2260
bool UIShopDialog::DirtyState::Has(const unsigned& nBit)
{
    return FUN_1418ffe80(m_nFlags, nBit);
}
MS2_REPLACE_METHOD(0x141AF2260, UIShopDialog::DirtyState, Has, 39, 0x27304002);

// @0x141af2290
void UIShopDialog::DirtyState::Clear(const unsigned& nBit)
{
    FUN_1418ffef0(&m_nFlags, nBit);
}
MS2_REPLACE_METHOD(0x141AF2290, UIShopDialog::DirtyState, Clear, 43, 0x6DBCA6ED);

// @0x141af22d0
void UIShopDialog::DirtyState::Set(const unsigned& nBit)
{
    FUN_1418ffec0(&m_nFlags, nBit);
}
MS2_REPLACE_METHOD(0x141AF22D0, UIShopDialog::DirtyState, Set, 43, 0x050EFE66);

// @0x141af2310
void UIShopDialog::DirtyState::Reset()
{
    m_nFlags = 0;
    m_spSale = 0;
}
MS2_REPLACE_METHOD(0x141AF2310, UIShopDialog::DirtyState, Reset, 41, 0x81217EBB);

// @0x141af2340
UIShopDialog::Selection::Selection()
{
    m_nKind = 0;
    m_nIndex = -1;
    m_nSecondary = -1;
}

// @0x141af2380
void UIShopDialog::Selection::Reset()
{
    m_nKind = 0;
    m_nIndex = -1;
    m_nSecondary = -1;
}
MS2_REPLACE_METHOD(0x141AF2380, UIShopDialog::Selection, Reset, 41, 0x95E94D13);

// @0x141af23b0
void UIShopDialog::Selection::ResetIf(int nSecondary)
{
    if (m_nSecondary == nSecondary)
        Reset();
}
MS2_REPLACE_METHOD(0x141AF23B0, UIShopDialog::Selection, ResetIf, 42, 0x6911532D);

// @0x141af23e0
void UIShopDialog::Selection::Set(int nKind, int nIndex, int nSecondary)
{
    m_nKind = nKind;
    m_nIndex = nIndex;
    m_nSecondary = nSecondary;
}
MS2_REPLACE_METHOD(0x141AF23E0, UIShopDialog::Selection, Set, 55, 0x130FDA81);

// @0x141af2420
UIShopDialog::UIShopDialog()
    : m_188(0), m_189(0), m_bCheckEnableItems(1), m_18b(0), m_bRepurchaseEmpty(0), m_bNewComplete(0), m_bReady(0),
      m_nCategory(0), m_nSortKind(0), m_nGroup(0), m_1a0(0), m_nNpcId(0), m_nShopId(0), m_tReset(0), m_280(0),
      m_284(0), m_288(0), m_nShopType(0), m_290(0), m_291(0), m_bProbInfo(0), m_bSellOnly(0), m_bResetEnable(1),
      m_295(0), m_nResetType(0), m_29c(0), m_2a0(0), m_2a4(0), m_nResetPriceOrg(0), m_nResetPrice(0),
      m_bResetLimited(0), m_nResetCount(0), m_bHideReset(1), m_bResetByAccount(0), m_2c2(0), m_bSearchDirty(0),
      m_2c4(0), m_2c8(0), m_nNewTotal(0), m_spPreview(0)                       // @0x141af2420 (again: the line table starts at the brace)
{
    FUN_141924170(1);
    FUN_1422dc3b0(1);
    m_164 = 1;
    FUN_140bccd50()->RegisterHandler(0x51, Delegate<void(CInPacket&)>(this, &UIShopDialog::OnShopPacket));
}

// @0x141af2990
UIShopDialog::~UIShopDialog()
{
    FUN_140bccd50()->UnregisterHandler(0x51, Delegate<void(CInPacket&)>(this, &UIShopDialog::OnShopPacket));
}

// @0x141af2be0
CString UIShopDialog::vfunc_1()
{
    return "ShopDialog";
}
MS2_REPLACE_METHOD(0x141AF2BE0, UIShopDialog, vfunc_1, 61, 0x14B4119C);

// @0x141af2c30
int UIShopDialog::vfunc_65()
{
    if (FUN_1406aa4b0())
        FUN_1406aa4b0()->FUN_1407cb390(0);
    if (!UIDialog::vfunc_65())
        return 0;
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}
MS2_REPLACE_METHOD(0x141AF2C30, UIShopDialog, vfunc_65, 115, 0xAB72624B);

// Place the shop beside the inventory; the gacha shop sits below its top edge.
// @0x141af2cb0
void UIShopDialog::vfunc_66()
{
    UIDialog::vfunc_66();
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        m_189 = pInv->vfunc_55() == 0;
        if (m_189 == 0)
        {
            if (FUN_14052d230()->FUN_14059e550(m_nShopId) != 0)
                return;
            if (m_30.get())
            {
                Unk_ShopUIMsg msg;
                msg.FUN_1422b82b0("openWindowPos");
                msg.FUN_1422b7f70(vfunc_48());
                pInv->OnMessage(this, &msg);
            }
        }
        else if (m_nShopType == 4)
        {
            Unk_ShopXY offLeft, offRight;
            FUN_141275c30(this, pInv, *FUN_140a0a600(&offLeft, 0.0f, 0.0f), *FUN_140a0a600(&offRight, 0.0f, 180.0f));
        }
        else
        {
            FUN_141275c30(this, pInv, DAT_143b02320, DAT_143b02320);
        }
    }
}
MS2_REPLACE_METHOD(0x141AF2CB0, UIShopDialog, vfunc_66, 460, 0x69F04B4F);

// Close: leave the shop and forget everything about it.
// @0x141af2e90
void UIShopDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    FUN_140939a10()->UnregisterNotify(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UIShopDialog::ChangedTokenMoney));
    FUN_140939a10()->UnregisterNotify(L"NotifyGameEventChanged", Delegate<void(NotifyObject*)>(this, &UIShopDialog::GameEventChanged));
    m_188 = 0;
    m_189 = 0;
    m_bCheckEnableItems = 1;
    m_18b = 0;
    m_bRepurchaseEmpty = 0;
    m_bNewComplete = 0;
    m_bReady = 0;
    m_nCategory = 0;
    m_nGroup = 0;
    m_2c8 = 0;
    m_nNewTotal = 0;
    m_selection.Reset();
    m_meratItems.clear();
    ResetAllProducts();
    m_strSearch = L"";
    m_nNpcId = 0;
    m_nShopId = 0;
    m_tReset = 0;
    m_280 = 0;
    m_2c4 = 0;
    m_284 = 0;
    m_288 = 0;
    m_nShopType = 0;
    m_290 = 0;
    m_291 = 0;
    m_bProbInfo = 0;
    m_bSellOnly = 0;
    m_bResetEnable = 0;
    m_295 = 0;
    m_nResetType = 0;
    m_29c = 0;
    m_2a0 = 0;
    m_2a4 = 0;
    m_nResetPriceOrg = 0;
    m_nResetPrice = 0;
    m_bResetLimited = 0;
    m_nResetCount = 0;
    m_bHideReset = true;
    m_bResetByAccount = 0;
    m_2c2 = 0;
    m_strIcon = "";
    m_spPreview = 0;
    m_spEquip = 0;
    m_dirty.Reset();
    FUN_140967100()->FUN_141b1feb0();
    if (m_nSortKind > 0)
        FUN_140714f90()->FUN_141538c40(m_nSortKind, 0);
    m_nSortKind = 0;
    FUN_140939a00()->FUN_140d5a200(vfunc_48());
    if (m_bSearchDirty)
    {
        m_bSearchDirty = 0;
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e2d);
    }
}
MS2_REPLACE_METHOD(0x141AF2E90, UIShopDialog, vfunc_67, 1474, 0xCC0FEA25);

// Per frame: close a shop the player walked away from, reload an expired list and apply the dirty refreshes.
// @0x141af3460
void UIShopDialog::vfunc_72()
{
    if (m_spShop == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_nSortKind == 0 && pPlayer->FUN_141527e60() == 0)
    {
        CloseShop();
    }
    else
    {
        if (m_18b)
        {
            __int64 tNow = FUN_140869440();
            if (tNow == 0)
                return;
            if (m_nResetType == 99)
                return;
            if (m_tReset < tNow)
            {
                m_spShop->Invoke("endTime");
                ResetProducts(0);
                COutPacket packet(0x28, 0);
                packet.Encode1(10);
                FUN_140710590(packet);
                Unk_ShopLog(FUN_140166440(), 0xc, 0x13, L"PROTOCOL_SHOP::ITEM_LIST_TIMEOUT next:{0}, server:{1}", m_tReset, tNow);
                m_18b = 0;
            }
            else if (m_bResetEnable && m_bResetLimited)
            {
                if (FUN_14086ab70(CMsTime(m_1a0), CMsTime(tNow), 0))
                {
                    m_1a0 = tNow;
                    ResetProducts(0);
                    COutPacket packet(0x28, 0);
                    packet.Encode1(10);
                    FUN_140710590(packet);
                }
            }
        }
        if (m_dirty.Has(1))
        {
            RefreshPremium();
            m_dirty.ClearSale();
        }
        if (m_dirty.Has(2))
        {
            RefreshResetPrice();
            m_dirty.Clear(2);
        }
    }
}
MS2_REPLACE_METHOD(0x141AF3460, UIShopDialog, vfunc_72, 862, 0xF062B756);

// @0x141af37d0
void UIShopDialog::vfunc_oa0_9(unsigned short a1)
{
}

// @0x141af37f0
void UIShopDialog::vfunc_oa0_7(int a1, CStringW s)
{
}

// @0x141af7cc0
void UIShopDialog::vfunc_18()
{
    UIDialog::vfunc_18();
    if (FUN_1422dc430())
        ArrangeInventory();
}
MS2_REPLACE_METHOD(0x141AF7CC0, UIShopDialog, vfunc_18, 48, 0x8110B1EF);

// @0x141af7d00
void UIShopDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_spShop = 0;
    m_spTalk = 0;
    m_spMoney = 0;
    m_spProbInfo = 0;
    m_spEquip = 0;
    UnloadRenderTarget();
    FUN_140939a00()->FUN_140d5a200(vfunc_48());
}
MS2_REPLACE_METHOD(0x141AF7D00, UIShopDialog, vfunc_26, 180, 0x023AF0D9);

// @0x141af7dc0
int UIShopDialog::vfunc_52()
{
    return 1;
}
MS2_REPLACE_METHOD(0x141AF7DC0, UIShopDialog, vfunc_52, 11, 0x30025ED0);

// @0x141af7de0
int UIShopDialog::vfunc_46()
{
    if (UISwfEntity::vfunc_46() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x141AF7DE0, UIShopDialog, vfunc_46, 37, 0x1374D307);

// @0x141af8000
void UIShopDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    UnloadRenderTarget();
}
MS2_REPLACE_METHOD(0x141AF8000, UIShopDialog, vfunc_16, 34, 0x5101492D);

// @0x141af8030
bool UIShopDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    LoadRenderTarget();
    return true;
}
MS2_REPLACE_METHOD(0x141AF8030, UIShopDialog, vfunc_17, 47, 0x0100A81D);

// The shop packet (0x51): the sub command picks the reader.
// @0x141af8710
void UIShopDialog::OnShopPacket(CInPacket& packet)
{
    int nCmd = packet.vfunc_o8_1();
    switch (nCmd)
    {
    case 0:
        ReadShopInfo(packet);
        break;
    case 1:
        ReadProducts(packet);
        break;
    case 11:
        ReadMeratStart(packet);
        break;
    case 12:
        ReadMeratItems(packet);
        break;
    case 2:
        ReadProductUpdate(packet);
        break;
    case 6:
        ReadRepurchaseStart(packet);
        break;
    case 7:
        ReadRepurchaseAdd(packet);
        break;
    case 8:
        ReadRepurchaseRemoval(packet);
        break;
    case 9:
        ReadResetResult(packet);
        break;
    case 4:
        ReadPurchaseResult(packet);
        break;
    case 13:
        ReadNewStart(packet);
        break;
    case 14:
        ReadNewProducts(packet);
        break;
    case 15:
        ReadShopError(packet);
        break;
    }
    UpdateGachaCoin();
    m_selection.ResetIf(nCmd);
}
MS2_REPLACE_METHOD(0x141AF8710, UIShopDialog, OnShopPacket, 370, 0x75D06B23);

// The shop header: npc, shop id, reset time and the reset price configuration.
// @0x141af88d0
void UIShopDialog::ReadShopInfo(CInPacket& packet)
{
    ResetProducts(0);
    m_nNpcId = packet.vfunc_o8_3();
    m_nShopId = packet.vfunc_o8_3();
    m_tReset = packet.vfunc_o8_4();
    m_280 = packet.vfunc_o8_3();
    m_2c4 = packet.vfunc_o8_2();
    m_284 = packet.vfunc_o8_3();
    int bOpenInventory = packet.vfunc_o8_1();
    m_bSellOnly = packet.vfunc_o8_0();
    m_bResetEnable = packet.vfunc_o8_0();
    m_295 = packet.vfunc_o8_0();
    m_nShopType = packet.vfunc_o8_1();
    m_290 = packet.vfunc_o8_0();
    m_291 = packet.vfunc_o8_0();
    m_bProbInfo = packet.vfunc_o8_0();
    m_2c2 = packet.vfunc_o8_0();
    m_strIcon = packet.vfunc_o8_7();
    m_bHideReset = m_bResetEnable == 0;
    if (m_bResetEnable)
    {
        m_29c = packet.vfunc_o8_1();
        m_2a0 = packet.vfunc_o8_1();
        m_2a4 = packet.vfunc_o8_3();
        m_nResetPriceOrg = packet.vfunc_o8_3();
        m_bResetLimited = packet.vfunc_o8_0();
        m_nResetCount = packet.vfunc_o8_3();
        m_nResetType = packet.vfunc_o8_1();
        m_bHideReset = packet.vfunc_o8_0();
        m_bResetByAccount = packet.vfunc_o8_0();
        m_nResetPrice = m_nResetPriceOrg;
    }
    if (!m_188)
        m_bCheckEnableItems = m_290;
    m_18b = m_bResetEnable;
    if (!FUN_1403ed2b0()->FUN_141adc890(0x4ece) && bOpenInventory && !m_188)
        FUN_1403ed2b0()->FUN_141adc530(0x4ece);
    m_188 = 1;
    m_1a0 = FUN_140869440();
    if (m_nResetType != 0)
    {
        if (m_nResetType == 1)
            m_280 = FUN_140869470(1);
        else if (m_nResetType == 2)
            m_280 = FUN_140869470(7);
        else if (m_nResetType == 3)
        {
            CMsTime now(FUN_140869440());
            int nDays = FUN_14086b490(now.GetYear(), now.GetMonth());
            m_280 = FUN_140869470(nDays);
        }
    }
}
MS2_REPLACE_METHOD(0x141AF88D0, UIShopDialog, ReadShopInfo, 2063, 0x5F81DB58);

// The normal products (list entries); the list is shown once all announced products arrived.
// @0x141af90f0
void UIShopDialog::ReadProducts(CInPacket& packet)
{
    if (!HasShop())
        return;
    int nCount = packet.vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        MS2Ptr<CNpcShopProductCli> spProduct(new CNpcShopProductCli);
        if (spProduct.get())
        {
            spProduct->FUN_140db61a0(packet, 1);
            spProduct->FUN_140db6db0(i);
            m_products[0].insert(std::pair<const int, MS2Ptr<CNpcShopProductBase> >(spProduct->FUN_140db5e70(), (CNpcShopProductCli*)spProduct));
        }
    }
    if ((unsigned)m_2c4 == m_products[0].size())
    {
        FUN_1412761e0(m_spShop, 1);
        if (m_bReady)
        {
            UpdateProductList(0);
            UpdateSerial(m_tReset);
            RefreshResetPrice();
        }
    }
}
MS2_REPLACE_METHOD(0x141AF90F0, UIShopDialog, ReadProducts, 652, 0x09174D24);

// The start of the new product list (ignored when it belongs to another npc or shop).
// @0x141af9390
void UIShopDialog::ReadNewStart(CInPacket& packet)
{
    if (!HasShop())
        return;
    int nNpcId = packet.vfunc_o8_3();
    int nShopId = packet.vfunc_o8_3();
    if (nNpcId != m_nNpcId || nShopId != m_nShopId)
        return;
    ResetProducts(2);
    m_bNewComplete = 0;
    m_288 = packet.vfunc_o8_3();
    m_nNewTotal = packet.vfunc_o8_2();
    m_products[2].clear();
}
MS2_REPLACE_METHOD(0x141AF9390, UIShopDialog, ReadNewStart, 321, 0x2D5D8D9A);

// @0x141af94e0
void UIShopDialog::ReadNewProducts(CInPacket& packet)
{
    if (!HasShop())
        return;
    std::map<int, MS2Ptr<CNpcShopProductBase> >& products = m_products[2];
    int nCount = packet.vfunc_o8_1();
    int nFirst = (int)products.size();
    for (int i = 0; i < nCount; i++)
    {
        MS2Ptr<CNpcShopProductNewCli> spProduct(new CNpcShopProductNewCli);
        if (spProduct.get())
        {
            int nIndex = i + nFirst;
            spProduct->m_18 = nIndex;
            spProduct->FUN_140db8840(packet);
            products.insert(std::pair<const int, MS2Ptr<CNpcShopProductBase> >(nIndex, (CNpcShopProductNewCli*)spProduct));
        }
    }
    if ((unsigned)m_nNewTotal <= products.size())
    {
        m_bNewComplete = 1;
        UpdateProductList(2);
    }
}
MS2_REPLACE_METHOD(0x141AF94E0, UIShopDialog, ReadNewProducts, 524, 0x24D935E8);

// @0x141af9700
void UIShopDialog::ReadMeratStart(CInPacket& packet)
{
    if (!HasShop())
        return;
    m_meratItems.clear();
    int nCount = packet.vfunc_o8_2();
    if (nCount > 0)
        m_meratItems.reserve(nCount);
}
MS2_REPLACE_METHOD(0x141AF9700, UIShopDialog, ReadMeratStart, 130, 0x8FE86E78);

// @0x141af9790
void UIShopDialog::ReadMeratItems(CInPacket& packet)
{
    if (!HasShop())
        return;
    int nCount = packet.vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        MS2Ptr<CNpcShopMeratItemCli> spItem(new CNpcShopMeratItemCli);
        if (spItem.get())
        {
            spItem->vfunc_2(&packet);
            m_meratItems.push_back(spItem);
        }
    }
}
MS2_REPLACE_METHOD(0x141AF9790, UIShopDialog, ReadMeratItems, 306, 0x2C7AF15E);

// @0x141af98d0
void UIShopDialog::ReadProductUpdate(CInPacket& packet)
{
    FUN_1412761e0(m_spShop, 1);
    int nSerial = packet.vfunc_o8_3();
    int nBuyCount = packet.vfunc_o8_3();
    MS2Ptr<CNpcShopProductCli> spProduct(dynamic_cast<CNpcShopProductCli*>(FindProduct(0, nSerial).get()));
    if (spProduct.get())
    {
        spProduct->FUN_140db6e30(nBuyCount);
        UpdateProduct(spProduct);
    }
    Unk_ShopLog(FUN_140166440(), 0xc, 0x13, L"OnShop [ITEM_UPDATE] : nSerialID = {0}, nBuyCount = {1}", nSerial, nBuyCount);
}
MS2_REPLACE_METHOD(0x141AF98D0, UIShopDialog, ReadProductUpdate, 493, 0x4ED3B394);

// The list reset answer: the refund notice, then the list is requested again.
// @0x141af9ad0
void UIShopDialog::ReadResetResult(CInPacket& packet)
{
    bool bSuccess = packet.vfunc_o8_0();
    if (bSuccess)
    {
        unsigned nItemId = packet.vfunc_o8_3();
        unsigned nCount = packet.vfunc_o8_3();
        if (nItemId > 0 && nCount > 0)
        {
            CStringW strText = FUN_140b99450(CStringW(L"s_shop_reset_refund_item"), FUN_1401a9d70()->FUN_141811980(1, nItemId), (int&)nCount);
            if (!strText.IsEmpty())
                FUN_1412751f0(strText, 1, 1);
        }
    }
    FUN_141276180(s_strResetSound, CString(""));
    ResetProducts(0);
    if (m_spShop.get())
        m_spShop->Invoke("requestItemList");
}
MS2_REPLACE_METHOD(0x141AF9AD0, UIShopDialog, ReadResetResult, 519, 0xF719E837);

// @0x141af9ce0
void UIShopDialog::ReadRepurchaseStart(CInPacket& packet)
{
    ResetProducts(1);
    m_2c8 = packet.vfunc_o8_2();
    m_bRepurchaseEmpty = m_2c8 == 0;
}
MS2_REPLACE_METHOD(0x141AF9CE0, UIShopDialog, ReadRepurchaseStart, 138, 0xDDAAB002);

// @0x141af9d70
void UIShopDialog::ReadRepurchaseAdd(CInPacket& packet)
{
    unsigned nCount = packet.vfunc_o8_2();
    for (unsigned i = 0; i < nCount; i++)
    {
        MS2Ptr<CNpcShopProductCli> spProduct(new CNpcShopProductCli);
        if (spProduct.get())
        {
            spProduct->FUN_140db61a0(packet, 7);
            spProduct->FUN_140db6db0((int)m_products[1].size());
            m_products[1].insert(std::pair<const int, MS2Ptr<CNpcShopProductBase> >(spProduct->FUN_140db5e70(), (CNpcShopProductCli*)spProduct));
            if (m_bRepurchaseEmpty)
                RepurchaseAdded(spProduct);
            unsigned nItemId = spProduct->FUN_140db5e20();
            int nSerial = spProduct->FUN_140db5e70();
            Unk_ShopLog(FUN_140166440(), 0xc, 0x13, L"OnShop [ITEM_REPURCHASE_ADD] : nRepurchaseID = {0}, itemID = {1}", nSerial, nItemId);
        }
    }
    if (m_bRepurchaseEmpty)
        SelectTab(1, 1);
    if ((unsigned)m_2c8 == m_products[1].size())
    {
        FUN_1412761e0(m_spShop, 1);
        if (m_nGroup == 1 && m_bReady)
            RefreshItems(CStringW(L""));
        m_bRepurchaseEmpty = 1;
    }
}
MS2_REPLACE_METHOD(0x141AF9D70, UIShopDialog, ReadRepurchaseAdd, 940, 0xC0913AB0);

// @0x141afa130
void UIShopDialog::ReadRepurchaseRemoval(CInPacket& packet)
{
    FUN_1412761e0(m_spShop, 1);
    int nSerial = packet.vfunc_o8_3();
    MS2Ptr<CNpcShopProductCli> spProduct(dynamic_cast<CNpcShopProductCli*>(FindProduct(1, nSerial).get()));
    if (spProduct == 0)
        return;
    m_products[1].erase(nSerial);
    RemoveRepurchaseProduct(spProduct);
    Unk_ShopLog(FUN_140166440(), 0xc, 0x13, L"OnShop [ITEM_REPURCHASE_REMOVE] : nRepurchaseID = {0}", nSerial);
}
MS2_REPLACE_METHOD(0x141AFA130, UIShopDialog, ReadRepurchaseRemoval, 432, 0x58D72355);

// The purchase answer; items bought for the guild storage get a notice.
// @0x141afa2f0
void UIShopDialog::ReadPurchaseResult(CInPacket& packet)
{
    FUN_1412761e0(m_spShop, 1);
    int nItemId = packet.vfunc_o8_3();
    int nCount = packet.vfunc_o8_3();
    unsigned __int64 nPrice = (unsigned)packet.vfunc_o8_3();
    int nRank = packet.vfunc_o8_1();
    bool bGuildStorage = packet.vfunc_o8_0();
    if (bGuildStorage)
    {
        CStringW strText;
        CStringW strName = FUN_14183e9c0(FUN_1401a9d70()->FUN_141811980(1, nItemId), nRank);
        if (nCount > 1)
            strText = FUN_140bfa7f0(CStringW(L"s_msg_take_item_count_to_guild_storage"), strName, nCount);
        else
            strText = FUN_1405c2690(CStringW(L"s_msg_take_item_to_guild_storage"), strName);
        FUN_1412751b0(strText, 0x14);
    }
    Unk_ShopLog(FUN_140166440(), 0xc, 0x13, L"OnShop [ITEM_BUY] : itemID = {0}, nCount = {1}, totalPrice = {2}", nItemId, nCount, nPrice);
}
MS2_REPLACE_METHOD(0x141AFA2F0, UIShopDialog, ReadPurchaseResult, 836, 0x826C9615);

// The server's refusal of a request: the matching notice.
// @0x141afa640
void UIShopDialog::ReadShopError(CInPacket& packet)
{
    FUN_1412761e0(m_spShop, 1);
    int nError = packet.vfunc_o8_3();
    int nCmd = packet.vfunc_o8_1();
    int nValue = packet.vfunc_o8_3();
    switch (nError)
    {
    case 8:
    case 9:
        break;
    case 2:
    case 13:
        FUN_141275260(0x49, 1, 1);
        break;
    case 11:
    {
        int nType = nValue;
        FUN_14134a120(nType, 0, 0);
        break;
    }
    case 12:
        FUN_141275260(0x35, 1, 1);
        break;
    case 16:
        FUN_141275260(0x5b, 1, 1);
        break;
    case 20:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_lack_guild_require_date")), 1, 1);
        break;
    case 4:
    case 5:
    case 6:
        FUN_141275260(0x4b, 1, 1);
        break;
    case 7:
        FUN_141275260(0x4a, 1, 1);
        break;
    case 15:
        FUN_141275260(0x43, 1, 1);
        FUN_141276180(s_strErrorSound, CString(""));
        break;
    case 10:
        FUN_141275260(0x2d2, 1, 1);
        break;
    case 18:
    {
        int nLevel = nValue;
        CStringW strText = FUN_1409e97f0(0x38, nLevel);
        FUN_1403b4750()->FUN_1416fb300(strText);
        FUN_1412751f0(strText, 1, 1);
        break;
    }
    case 23:
        FUN_141275260(0xc07, 1, 1);
        break;
    case 24:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_msg_cant_sell_to_only_sell_shop")), 1, 1);
        break;
    case 25:
        FUN_1412751f0(FUN_140a228f0(0x688, *TSingleton<Client::Constants>::GetInstance()->PropertyProtectionTime.Get(), FUN_1409eec40(0x5a3)), 1, 1);
        break;
    case 26:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_guild_err_buy_no_master")), 1, 1);
        break;
    case 27:
        FUN_14134a120(7, 0, 0);
        break;
    case 28:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_invalid_item_cannot_buy_by_period")), 1, 1);
        break;
    case 29:
        break;
    case 30:
        FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_shop_no_star_point_event")), 0, 0, CStringW(L""));
        break;
    case 32:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_meratmarket_error_country_limit")), 1, 1);
        break;
    case 31:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_shop_err_change_reset_price")), 1, 1);
        break;
    case 33:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_cannot_sell_petitem_summon")), 1, 1);
        break;
    default:
    {
        int nCode = nError;
        FUN_1412751f0(FUN_1408116a0(0xcd, nCode), 1, 1);
        break;
    }
    }
    m_selection.ResetIf(nCmd);
}
MS2_REPLACE_METHOD(0x141AFA640, UIShopDialog, ReadShopError, 2006, 0xA323DFFD);

// Rewrites the selected row of the normal product list.
// @0x141afaeb0
void UIShopDialog::UpdateProduct(MS2Ptr<CNpcShopProductCli> spProduct)
{
    if (m_spShop == 0 || spProduct == 0)
        return;
    if (m_nGroup == 0)
    {
        ASSlot slot(2);
        MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        MS2Ptr<CNpcShopGivePointContextBase> spEvent = FUN_1404273a0(FUN_140302b00()->GetNpcShopGivePoint(), m_nShopId);
        if (PopulateProduct(slot, spProduct, spEvent, pPlayer))
            m_spShop->Invoke("updateItem", m_selection.m_nIndex, slot.FUN_1422bb870());
    }
}
MS2_REPLACE_METHOD(0x141AFAEB0, UIShopDialog, UpdateProduct, 513, 0xA9430DA7);

// @0x141afb720
void UIShopDialog::SetSortKind(int nKind)
{
    m_nSortKind = nKind;
}
MS2_REPLACE_METHOD(0x141AFB720, UIShopDialog, SetSortKind, 25, 0x16E3216A);

// @0x141afb740
int UIShopDialog::GetSortKind()
{
    return m_nSortKind;
}
MS2_REPLACE_METHOD(0x141AFB740, UIShopDialog, GetSortKind, 17, 0xE13D7686);

// @0x141afb760
void UIShopDialog::SetSearchDirty()
{
    m_bSearchDirty = 1;
}
MS2_REPLACE_METHOD(0x141AFB760, UIShopDialog, SetSearchDirty, 18, 0xC8019996);

// The gacha shop's coin count.
// @0x141afbd10
void UIShopDialog::UpdateGachaCoin()
{
    if (m_spShop == 0)
        return;
    if (m_nShopType == 4)
    {
        int nAmount = DAT_143ab2a90.FUN_140a5f180(FUN_14052d230()->FUN_14059e550(m_nShopId), 0);
        int nCost = FUN_14052d230()->FUN_14059ee00(m_nShopId);
        m_spShop->Invoke("gachaCoinAmount", FUN_1418fec90(2, nAmount, nCost));
    }
}
MS2_REPLACE_METHOD(0x141AFBD10, UIShopDialog, UpdateGachaCoin, 269, 0xD6307ECC);

// The tab buttons: purchase, repurchase (not in sell-only shops) and new items.
// @0x141afbe30
void UIShopDialog::FillTabs(ASDataProvider& tabs)
{
    FillTab(tabs, 0, CStringW(L"$s_shop_purchase"), CStringW(L"$s_tooltip_shop_tab_purchase"));
    if (!m_bSellOnly)
        FillTab(tabs, 1, CStringW(L"$s_shop_repurchase"), CStringW(L"$s_tooltip_shop_tab_repurchase"));
    if (m_2c2)
        FillTab(tabs, 2, CStringW(L"$s_shop_new_items"), CStringW(L"$s_tooltip_shop_tab_new_items"));
}
MS2_REPLACE_METHOD(0x141AFBE30, UIShopDialog, FillTabs, 375, 0x0A41A786);

// One tab button (the repurchase list is drawn newest first).
// @0x141afd270
void UIShopDialog::FillTab(ASDataProvider& tabs, int nGroup, const CStringW& strTitle, const CStringW& strTooltip)
{
    ASObj tab(2);
    FUN_1418fffd0(&tab, nGroup, strTitle, strTooltip);
    tab.FUN_1407cbbe0("isNewTab", nGroup == 2);
    if (nGroup == 1)
        tab.FUN_1407cbbe0("renderReverse", true);
    else
        tab.FUN_1407cbbe0("renderReverse", false);
    tabs.FUN_1422bc050(tab.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x141AFD270, UIShopDialog, FillTab, 260, 0x8886D243);

// Rebuilds the category tabs of a product group (and shows them).
// @0x141afd380
void UIShopDialog::SetTab(int nGroup, int bShow)
{
    if (!FUN_141b046e0(nGroup))
        return;
    Unk_ShopTabArray& tabs = m_tabs[m_nGroup];
    std::map<int, MS2Ptr<CNpcShopProductBase> >& products = m_products[nGroup];
    int nShop = 0;
    if (nGroup == 0)
        nShop = m_284;
    else if (nGroup == 2)
        nShop = m_288;
    FUN_141348610(nShop, tabs, products);
    if (bShow)
        FUN_141348cf0(tabs, m_spShop, 0, 0);
}
MS2_REPLACE_METHOD(0x141AFD380, UIShopDialog, SetTab, 248, 0x5A841595);

// The reset button's price (and the original price when discounted).
// @0x141afd5d0
void UIShopDialog::RefreshResetPrice()
{
    if (m_spShop == 0 || !m_bResetEnable)
        return;
    if (m_nResetType == 99)
        return;
    UpdateMoney();
    bool bShow = !m_bHideReset;
    CStringW strPrice;
    CStringW strOriginal;
    if (bShow)
    {
        if (m_nResetPrice != m_nResetPriceOrg)
            strOriginal = FUN_1409404f0(m_nResetPriceOrg);
        FUN_141349f30(strPrice, m_29c, m_2a4, (int)m_nResetPrice, CString(""));
    }
    m_spShop->FUN_14190b570("updateResetData", bShow, strPrice, strOriginal);
}
MS2_REPLACE_METHOD(0x141AFD5D0, UIShopDialog, RefreshResetPrice, 615, 0x1029469F);

// OnChangeTab: the group of the clicked tab.
// @0x141afd840
void UIShopDialog::ChangeTab(ASData& args)
{
    if (m_spShop == 0)
        return;
    SelectTab(m_nGroup, 0);
    m_nGroup = args.FUN_1422b8a10();
    if (FUN_141b046e0(m_nGroup))
        UpdateProductList(m_nGroup);
}
MS2_REPLACE_METHOD(0x141AFD840, UIShopDialog, ChangeTab, 146, 0x56C7DCFF);

// @0x141afe8b0
void UIShopDialog::ResetList()
{
    COutPacket packet(0x28, 0);
    packet.Encode1(9);
    packet.Encode4((int)m_nResetPrice);
    FUN_140710590(packet);
    FUN_1412761e0(m_spShop, 0);
}
MS2_REPLACE_METHOD(0x141AFE8B0, UIShopDialog, ResetList, 159, 0x1E4ABB45);

// @0x141afeed0
void UIShopDialog::ResetAllProducts()
{
    for (int i = 0; i < 3; i++)
        ResetProducts(i);
}
MS2_REPLACE_METHOD(0x141AFEED0, UIShopDialog, ResetAllProducts, 57, 0x688D381B);

bool FUN_141b046e0(int nGroup);

// @0x141afef10
void UIShopDialog::ResetProducts(int nGroup)
{
    if (!FUN_141b046e0(nGroup))
        return;
    m_products[nGroup].clear();
    m_tabs[nGroup].RemoveAll();
}
MS2_REPLACE_METHOD(0x141AFEF10, UIShopDialog, ResetProducts, 94, 0xA1C9C0DE);

// The "new" marker of a tab group.
// @0x141afef80
void UIShopDialog::SelectTab(int nGroup, unsigned char bNew)
{
    if (m_spShop.get())
        m_spShop->Invoke("setNew", nGroup, bNew != 0);
}
MS2_REPLACE_METHOD(0x141AFEF80, UIShopDialog, SelectTab, 110, 0xB49808DF);

// @0x141aff180
bool UIShopDialog::HasStarEvent()
{
    if (m_nShopType == 2 && !FUN_1406a5930())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x141AFF180, UIShopDialog, HasStarEvent, 46, 0x806B0318);

// @0x141affbe0
MS2Ptr<CNpcShopProductBase> UIShopDialog::FindProduct(int nGroup, int nSerial)
{
    if (!FUN_141b046e0(nGroup))
        return MS2Ptr<CNpcShopProductBase>(0);
    std::map<int, MS2Ptr<CNpcShopProductBase> >& products = m_products[nGroup];
    std::map<int, MS2Ptr<CNpcShopProductBase> >::iterator it = products.find(nSerial);
    if (it != products.end())
        return it->second;
    return MS2Ptr<CNpcShopProductBase>(0);
}
MS2_REPLACE_METHOD(0x141AFFBE0, UIShopDialog, FindProduct, 241, 0xC16F6AD4);

// @0x141affce0
MS2Ptr<CNpcShopProductBase> UIShopDialog::FindCurrentProduct(int nSerial)
{
    return FindProduct(m_nGroup, nSerial);
}
MS2_REPLACE_METHOD(0x141AFFCE0, UIShopDialog, FindCurrentProduct, 80, 0x73925974);

// @0x141affd40
MS2Ptr<CNpcShopMeratItemCli> UIShopDialog::FindMeratItem(int nSerial)
{
    if (m_meratItems.empty())
        return MS2Ptr<CNpcShopMeratItemCli>(0);
    size_t nCount = m_meratItems.size();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CNpcShopMeratItemCli> spItem = m_meratItems[i];
        if (spItem == 0)
            continue;
        if (spItem->vfunc_3() == (unsigned)nSerial)
            return spItem;
    }
    return MS2Ptr<CNpcShopMeratItemCli>(0);
}
MS2_REPLACE_METHOD(0x141AFFD40, UIShopDialog, FindMeratItem, 359, 0x78C581D0);

// @0x141b031c0
bool UIShopDialog::HasShop()
{
    return m_nShopId != 0;
}
MS2_REPLACE_METHOD(0x141B031C0, UIShopDialog, HasShop, 48, 0x0047626A);

// @0x141b03200
int UIShopDialog::ConfirmPurchase(int nButton, const CMsgBoxData& data)
{
    if (m_spShop == 0)
        return 1;
    return 1;
}
MS2_REPLACE_METHOD(0x141B03200, UIShopDialog, ConfirmPurchase, 57, 0xE95340FD);

// The shop's greeting: the event's talk text, else the standard welcome.
// @0x141b03470
CStringW UIShopDialog::GetTalk(int nShop, bool bWelcome)
{
    unsigned nTextId = FUN_1404271c0(FUN_140302b00()->GetNpcShopTalk(), nShop);
    CStringW strText;
    if (nTextId > 0)
        strText = FUN_1401a9d70()->FUN_141811980(0x40, nTextId);
    else if (bWelcome == 1)
        strText = FUN_14028b8e0(L"s_shop_npc_talk_welcome");
    return strText;
}
MS2_REPLACE_METHOD(0x141B03470, UIShopDialog, GetTalk, 322, 0xC10E22FB);

// @0x141b035c0
void UIShopDialog::SetTalk(const CStringW& strText)
{
    if (m_spTalk == 0)
        return;
    m_spTalk->FUN_1422c4f00(strText);
}
MS2_REPLACE_METHOD(0x141B035C0, UIShopDialog, SetTalk, 81, 0xC45BDEF7);

// @0x141b03620
void UIShopDialog::ArrangeInventory()
{
    if (m_30 == 0)
        return;
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0 && pInv->vfunc_55() == 0 && pInv->FUN_1422dc430())
        FUN_141275c30(this, pInv, DAT_143b02320, DAT_143b02320);
}
MS2_REPLACE_METHOD(0x141B03620, UIShopDialog, ArrangeInventory, 131, 0x643F48E9);

// @0x141b036b0
bool UIShopDialog::TabsEmpty(int nGroup)
{
    if (!FUN_141b046e0(nGroup))
        return true;
    return m_tabs[nGroup].IsEmpty();
}
MS2_REPLACE_METHOD(0x141B036B0, UIShopDialog, TabsEmpty, 68, 0x7AC54E03);

// @0x141b03700
void UIShopDialog::UpdateProductList(int nGroup)
{
    if (m_nGroup == nGroup)
    {
        SetTab(nGroup, 1);
        if (TabsEmpty(nGroup))
            RefreshItems(L"");
    }
    else
    {
        SetTab(nGroup, 0);
    }
}
MS2_REPLACE_METHOD(0x141B03700, UIShopDialog, UpdateProductList, 150, 0x76CA32C9);

// @0x141b037a0
void UIShopDialog::RefreshPremium()
{
    if (m_meratItems.empty())
        return;
    if (m_nGroup == 0)
        RefreshItems(m_strSearch);
}
MS2_REPLACE_METHOD(0x141B037A0, UIShopDialog, RefreshPremium, 80, 0x57C4EF16);

// The reset price with the running reset-price sale.
// @0x141b03800
void UIShopDialog::UpdateMoney()
{
    if (!m_bResetEnable)
        return;
    unsigned nDiscount = FUN_1404275a0(FUN_140302b00()->GetNpcShopResetPriceSale(), m_nShopId);
    if (nDiscount > 0)
        m_nResetPrice = FUN_1405957d0(m_nResetPriceOrg, nDiscount);
    else
        m_nResetPrice = m_nResetPriceOrg;
}
MS2_REPLACE_METHOD(0x141B03800, UIShopDialog, UpdateMoney, 134, 0xD5BC6C05);

// The star shop's wallet ("m_money") follows the star point balance.
// @0x141b03890
void UIShopDialog::ChangedTokenMoney(NotifyObject* pNotify)
{
    if (!pNotify)
        return;
    if (m_spShop == 0 || m_spMoney == 0)
        return;
    NotifyChangedTokenMoney* pMoney = dynamic_cast<NotifyChangedTokenMoney*>(pNotify);
    if (!pMoney)
        return;
    if (pMoney->m_nType == 12 && m_nShopType == 2)
    {
        const CStringW& strText = FUN_1418fec00(15, pMoney->m_nValue, false);
        m_spMoney->FUN_1422e4b80(strText);
    }
}
MS2_REPLACE_METHOD(0x141B03890, UIShopDialog, ChangedTokenMoney, 258, 0x4DE2E1A7);

// @0x141b039a0
void UIShopDialog::GameEventChanged(NotifyObject* pNotify)
{
    if (!pNotify)
        return;
    if (m_spShop == 0)
        return;
    NotifyGameEventChanged* pEvent = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (!pEvent)
        return;
    const CStringW& strName = pEvent->m_eventName;
    if (strName.CompareNoCase(L"NpcShopTalk") == 0)
    {
        if (m_spTalk == 0)
            return;
        int nType = pEvent->m_type;
        if (nType == 0 || nType == 1)
        {
            CStringW strTalk = GetTalk(m_nShopId, true);
            SetTalk(strTalk);
        }
    }
    else if (strName.CompareNoCase(L"PremiumMarketSale") == 0)
    {
        int nType = pEvent->m_type;
        if (nType == 0 || nType == 1)
            m_dirty.AddSale(pEvent->m_id);
    }
    else if (strName.CompareNoCase(L"NpcShopResetPriceSale") == 0)
    {
        int nType = pEvent->m_type;
        if (nType == 0 || nType == 1)
            m_dirty.Set(2);
    }
}
MS2_REPLACE_METHOD(0x141B039A0, UIShopDialog, GameEventChanged, 443, 0xDFC1B38F);

// @0x141b03b70
void UIShopDialog::LoadRenderTarget()
{
    if (m_spShop.get())
        m_spShop->Invoke("loadRenderTarget");
}
MS2_REPLACE_METHOD(0x141B03B70, UIShopDialog, LoadRenderTarget, 87, 0x2781F757);

// @0x141b03bd0
void UIShopDialog::UnloadRenderTarget()
{
    if (m_spShop.get())
        m_spShop->Invoke("unloadRenderTarget");
}
MS2_REPLACE_METHOD(0x141B03BD0, UIShopDialog, UnloadRenderTarget, 87, 0xD3970D13);

// @0x141b04410
void UIShopDialog::ShowMyEquip()
{
    if (m_spPreview.get())
        m_spPreview->FUN_140d3fa30();
    if (m_spEquip.get())
        m_spEquip->FUN_140e2a670();
}
MS2_REPLACE_METHOD(0x141B04410, UIShopDialog, ShowMyEquip, 116, 0x200522A7);

// @0x141b04490
void UIShopDialog::UnequipAll()
{
    if (m_spPreview.get())
        m_spPreview->FUN_140d3f9a0();
    if (m_spEquip.get())
        m_spEquip->FUN_140e2a670();
}
MS2_REPLACE_METHOD(0x141B04490, UIShopDialog, UnequipAll, 116, 0x6A8548B1);

// @0x141b04510
void UIShopDialog::ShowMainItems()
{
    RefreshCategories();
}
MS2_REPLACE_METHOD(0x141B04510, UIShopDialog, ShowMainItems, 24, 0x8EF078DD);

// "OnUnEquip": the equip slot and the item's GUID.
// @0x141b04530
void UIShopDialog::Unequip(ASData& args)
{
    CString strSlot = args.FUN_1422b8d30();
    Scaleform::GFx::Value value = args.FUN_1422b9260();
    AScript obj(value, 2);
    int nSlot = FUN_1407181d0(strSlot);
    CString strGuid;
    obj.FUN_1422bac00("itemGUID", strGuid);
    unsigned __int64 nUid = FUN_140718350(strGuid);
    if (m_spPreview.get())
        m_spPreview->FUN_140d3fac0(nUid);
    if (m_spEquip.get())
        m_spEquip->FUN_140e2a640(nSlot);
}
MS2_REPLACE_METHOD(0x141B04530, UIShopDialog, Unequip, 326, 0x585F5052);

// @0x141b04680
void UIShopDialog::CollectPreviewItems(std::vector<MS2Ptr<CItem> >& items)
{
    if (m_spPreview.get())
        m_spPreview->FUN_140d3c690(items);
}
MS2_REPLACE_METHOD(0x141B04680, UIShopDialog, CollectPreviewItems, 75, 0xFAA3CEFE);

// @0x141b046e0
bool FUN_141b046e0(int nGroup)
{
    if (nGroup < 0 || nGroup >= 3)
        return false;
    return true;
}
MS2_REPLACE(0x141B046E0, FUN_141b046e0, 25, 0xA22EF56D);
