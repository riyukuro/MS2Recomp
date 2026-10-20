// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The merat market manager CMeratMarketMan (products, UGC
// sellers and bookmarks, the basket, pending purchases) and its purchase requests (CMeratMarketBuy, CMeratMarketBasket).
// See placeholder/cmeratmarketman.h and cmeratmarketbuy.h. Function names are the exe's addresses; meanings in comments.
// MS2-UNIT: client\ms2\meratmarketman.cpp
// MS2-RANGE: 0x1400d3440-0x1400d3940 .text$di
// MS2-RANGE: 0x140d53ad0-0x140d6d8c0 .text$mn
// MS2-RANGE: 0x142ca5250-0x142ca54a0 .text$yd
// MS2-PIN: ??_7?$TPtredDummy@V?$list@V?$MS2Ptr@VCMeratMarketProduct@@@@V?$allocator@V?$MS2Ptr@VCMeratMarketProduct@@@@@std@@@std@@@@6B@ 0x142e2f7f8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\meratmarketman.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cmeratmarketman.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/commonfiles/ugcdef.h"
#include "cmeratmarketbuy.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cmeratmarketpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/ms2format.h"
#include "uimessageboxdata.h"
#include "networkservice.h"
#include "pcbase.h"
#include "ms2/commonfiles/achievedata.h"
#include "ms2/unnamed/unit_140e3efd0.h"
#include "uimeratmarketregisterdialog.h"
#include "uirandomcoupon.h"
#include "ms2/placeholder/asmeratmarketbuybilldata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- header statics (the shared list of the merat market units) ----
#ifndef MS2_HOOK_DLL
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill = "skill";
static CString s_stun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyController;
static CString s_jobCode = "jobCode";
static CString s_sortValue = "sortValue";
static CString s_tabIndex = "tabIndex";
#endif
static CString s_designUpload = "design_Upload";
static CString s_cashBuy = "cash_Buy";
static CString s_marketCalculate = "Market_Caculate";
static CString s_ugcEndSale = "PC_ugc_endsale";
static CString s_warningBag = "system_notice_error_warningBag";
#ifndef MS2_HOOK_DLL
// The second header block (the purchase half of the unit includes the market headers again).
static CString s_shopSort2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyController2;
static CString s_shopSort3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill2 = "skill";
#endif

// ---- unit-local declarations (names describe uses, not original class names) ----

// The merat market dialog (?\uimeratmarketdialog.cpp, UIMeratMarketDialog); only the calls of this unit.
class Unk_MmDialog
{
public:
    CMsTime FUN_14130bea0();                                    // the time of the last refresh
    void FUN_14130bee0(CMsTime time);                           // store it
    void FUN_1412ebc40(MS2Ptr<CMeratMarketProduct> spProduct);  // a random-sale product changed
    void FUN_14130d150(int nSellerState, __int64 nAmount);      // the UGC seller state changed
    void FUN_14130f010(MS2Ptr<CMeratMarketBasket> spLine, int nIndex);      // a basket line was added
    void FUN_14130f310(Unk_MeratProductKey key, int nIndex);    // a basket line was removed
    void FUN_14130c670(unsigned char nPage);                    // the main page products arrived
    void FUN_14130ce70(bool bEmpty);                            // the advertised products arrived
    void FUN_14130eaa0();                                       // my products on sale arrived
    void FUN_14130eaf0();                                       // the sellers arrived
    void FUN_14130e2e0(MS2Ptr<CMeratMarketProduct> spProduct);  // a product was registered
    void FUN_14130e560(MS2Ptr<CMeratMarketProduct> spProduct);  // a product was removed
    void FUN_14130e790(MS2Ptr<CMeratMarketProduct> spProduct);  // a product was updated
    void FUN_14130deb0(MS2Ptr<CMeratMarketProduct> spProduct);  // a product's sale state changed
    void FUN_14130ed10();                                       // the bookmarks arrived
    void FUN_14130dd00(__int64 nBookMarkId);                    // a bookmark was added
    void FUN_14130dd30(__int64 nBookMarkId);                    // a bookmark was removed
    void FUN_14130de30(__int64 nBookMarkId);                    // a bookmark was updated
    void FUN_14130ee60();                                       // the promotion time changed
    void FUN_14130f430(bool bChanged);                          // the sale settings arrived
    void FUN_14130d390(int nPage, int nFirst, int nLast, int nTotal, bool bMore);   // a page of search results
    void FUN_14130f960();                                       // the search failed
    void FUN_14130ea00(MS2Ptr<CMeratMarketProduct> spProduct);  // a product's counts changed
};
Unk_MmDialog* FUN_140bd2c00();                                  // the open market dialog (or NULL)
Unk_MmDialog* FUN_140bfed50(int nUIClassID);                    // a dialog of a class id (0x4ec1: the market)

// A scoped lock of a critical section with a mode (0x1401b4ec0 / 0x1401b5120).
class Unk_MmScopedLock
{
public:
    Unk_MmScopedLock(CLockCriticalSection& cs, int nMode);
    ~Unk_MmScopedLock();
private:
    void* m_p;
};

// A UGC product uid as the packet writes it (ctor 0x140d64c50 zeroes it).
struct Unk_MmUid
{
    Unk_MmUid() : m_n(0) {}
    __int64 m_n;
};
void FUN_1401fe790(Unk_MmUid* pUid, COutputStream& stream);

bool FUN_1418ffe80(int nFlags, int nBit);                       // a flag bit is set
void FUN_1418ffef0(int* pFlags, int nBits);                     // clear flag bits

// An open dialog of a UI class id, of the given class (NULL when closed or of another class).
template <class T> T* Unk_MmGetDialog(int nId)
{
    if (FUN_1403ed2b0() != 0) {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (spObject.get() != 0)
            return dynamic_cast<T*>(spObject.get());
    }
    return 0;
}

// The ad push dialog's view of a market product (unit_140e3efd0.h's Unk_AdMarketItem): the same exe object.
static MS2Ptr<Unk_AdMarketItem> Unk_MmAdItem(MS2Ptr<CMeratMarketProduct> spProduct)
{
    return MS2Ptr<Unk_AdMarketItem>(reinterpret_cast<Unk_AdMarketItem*>(spProduct.get()));
}

// The game menu (UI type 0x4e28, FUN_140938b90); only the call of this unit.
class Unk_MmGameMenu
{
public:
    void FUN_14193dd50();                                       // refresh the merat market alarm
};
Unk_MmGameMenu* FUN_140938b90(int nUIType);

// The shop dialog (UI type 0x4e3b) as FUN_140534780 returns it; only the call of this unit.
class Unk_MmShopDialog
{
public:
    void FUN_141afb290(int nProductId);                         // a product could not be bought
};

// Player inventory (global at 0x143ab2a90): item lookup by uid (the same declaration as unit_1406125d0.h).
class Unk_LockInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid);
};
extern Unk_LockInventory DAT_143ab2a90;

// The item event hub (uiitemenchantdialog.h's UIItemEventDispatcher, FUN_140a6a840); the slots up to the one called.
class Unk_MmItemEvents
{
public:
    virtual ~Unk_MmItemEvents();
    virtual void vfunc_1(void* pItem);
    virtual void vfunc_2(void* pItem, bool b);
    virtual void vfunc_3(void* pItem, int n);                   // an item changed
};
Unk_MmItemEvents* FUN_140a6a840();

// The blueprint market dialog (RTTI .?AVUIBlueprintMarketDialog@@, UI type 0x4f7f); only the calls of this unit.
class UIBlueprintMarketDialog : public UIObject
{
public:
    static int FUN_140d66e70() { return 0x4f7f; }               // the UI type id
    void FUN_140bbb440(int nPage, int nFirst, int nLast, int nTotal, bool bMore);   // a page of blueprints
    void FUN_140bbbc70(MS2Ptr<CMeratMarketProduct> spProduct);  // a blueprint changed
};

bool FUN_1406a5040(int nSort);                                  // a valid market sort kind
void FUN_1418ffec0(int& nFlags, int nBit);                      // set a flag bit
__int64 FUN_140869440();                                        // the server time
extern int DAT_143ab0248;                                       // the service region

// The game constants singleton (FUN_1401d3200); only the slots read here.
struct Unk_MmConstSlot { char m_pad[8]; };
class Unk_MmConfig
{
public:
    char m_pad_0[0x47c8];
    Unk_MmConstSlot m_sellerLimit;                              // +0x47c8 the merat amount of a UGC seller
    char m_pad_47d0[0x6aa8 - 0x47c8 - sizeof(Unk_MmConstSlot)];
    Unk_MmConstSlot m_pcBangLevel;                              // +0x6aa8 the PC bang level needed
};
Unk_MmConfig* FUN_1401d3200();
__int64* FUN_1402c05b0(Unk_MmConstSlot* pSlot);
int* FUN_1402056b0(Unk_MmConstSlot* pSlot);

// The UI manager (FUN_1403ed2b0).
class Unk_MmUIManager
{
public:
    void FUN_141adc5d0(int nClass);                             // close a dialog (if open)
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                    // an open dialog
    int FUN_141adc890(int nClass);                              // a dialog is open
};
Unk_MmUIManager* FUN_1403ed2b0();

// The notify centre (FUN_140939a10).
class Unk_MmNotices
{
public:
    void FUN_140da4e40(CStringW name, Delegate<void(NotifyObject*)> handler);   // add
    void FUN_140da4eb0(CStringW name, Delegate<void(NotifyObject*)> handler);   // remove
};
Unk_MmNotices* FUN_140939a10();

// The world service (FUN_1403ed2d0).
class Unk_MmWorld
{
public:
    PCBase* FUN_141bd0cc0();                                    // the local player
};
Unk_MmWorld* FUN_1403ed2d0();

CStringW FUN_1409404f0(__int64 nValue);                         // a number with digit groups
void FUN_141276180(const CString& strSound, const CString& strArg);    // play a system sound
bool FUN_140ebfc70(unsigned short nLevel, CDBPremiumProduct* pProduct, bool bShowError);  // the level fits the product

CStringW FUN_14028de60(int nKey);                               // a common string by id
CStringW FUN_14028b8e0(const CStringW& str);                    // a string by key
CStringW FUN_1409eec40(int nKey);                               // a system string by id
CStringW FormatStringId(int nId, const fmt::ArgList& args);     // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)
CStringW FUN_14062b4f0(CStringW strKey, const int& nArg);       // a string by key with one argument
CStringW FUN_140a228f0(int nId, const int& n, const CStringW& str);
CStringW FUN_1418fec00(int nType, __int64 nValue, int);         // money text by pay type
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_1412751f0(const CStringW& text, int nA, int nB);       // system notice
void FUN_141275260(int nStringId, int nA, int nB);
void* FUN_1408e57f0();
int FUN_1422b9dc0(void*);                                       // the screen layout id
Unk_MmShopDialog* FUN_140534780(int nUIType);                   // the shop dialog (refreshes it)
int FUN_1406a50b0(Unk_MeratProductMap& map);                    // meratmarketbasketinfo.cpp: the product count
// UIMeratMarketCommon (uimeratmarketcommon.cpp): purchase checks.
bool FUN_140ebff70(CDBPremiumProduct* pProduct, bool bShowError);
bool FUN_140ebfdd0(CDBPremiumProduct* pProduct, bool bShowError);
bool FUN_140ebfe30(CDBPremiumProduct* pProduct, bool bShowError);
bool FUN_140ebfb90(CMeratMarketPremiumProduct* pProduct, bool bShowError);
CStringW FUN_140ec01e0(CDBPremiumProduct* pProduct, const CStringW& strKey);
CStringW FUN_140ec05f0(CDBPremiumProduct* pProduct);            // the option text of a product (empty: none)
CStringW FUN_140ebd520(CMeratMarketPremiumProduct* pProduct, int nOption);  // the text of a chosen option
CStringW FUN_1408f71a0(const CStringW& strKey, const CStringW& strA, const CStringW& strB);  // a string by key, 2 args
int FUN_14069c3e0(int nCurrency);                               // the pay type of a currency

// ---- CMeratMarketMan ----

// @0x140d53ad0
CMeratMarketMan::CMeratMarketMan()
    : m_products(10), m_bookMarks(10), m_sellers(10), m_nSellerState(0), m_nd0(0), m_nd8(0), m_ne0(0), m_ne8(0),
      m_nf0(0), m_bf8(false), m_120(10), m_170(10), m_n1a0(0), m_n1a8(0), m_n1b0(0), m_n1b8(0), m_n1bc(0), m_n1c0(0),
      m_n1c4(7), m_b1f0(false), m_1f8(10), m_nFlags(0), m_n2a0(0), m_n2a4(0), m_n2a8(0), m_str2d0(L""), m_b2d8(false)
{
}

// @0x140d53da0
CMeratMarketMan::~CMeratMarketMan()
{
    m_products.RemoveAll();
    m_bookMarks.RemoveAll();
    m_sellers.RemoveAll();
    m_100.RemoveAll();
    m_120.RemoveAll();
    m_basket.RemoveAll();
    FUN_140d57e40();
    FUN_140d59ce0();
    m_pending.RemoveAll();
}

// The market packet (0x6c) of the server: dispatch on the sub-opcode.
// @0x140d53fb0
void CMeratMarketMan::FUN_140d53fb0(CInPacket& packet)
{
    unsigned char nOp = packet.vfunc_o8_1();
    if (nOp == 0x65)
        FUN_140d5bc30(packet);
    else if (nOp == 0x67)
        FUN_140d5c2f0(packet);
    else if (nOp == 0x66)
        FUN_140d5c910(packet);
    else if (nOp == 0x0b)
        FUN_140d5cb90(packet);
    else if (nOp == 0x0c)
        FUN_140d5ce00(packet);
    else if (nOp == 0x0d)
        FUN_140d5cfa0(packet);
    else if (nOp == 0x0e)
        FUN_140d5d140(packet);
    else if (nOp == 0x12)
        FUN_140d5d2c0(packet);
    else if (nOp == 0x13)
        FUN_140d5d3e0(packet);
    else if (nOp == 0x14)
        FUN_140d5d500(packet);
    else if (nOp == 0x15)
        FUN_140d5d760(packet);
    else if (nOp == 0x16)
        FUN_140d5da10(packet);
    else if (nOp == 0x17)
        FUN_140d5dba0(packet);
    else if (nOp == 0x18)
        FUN_140d5dcf0(packet);
    else if (nOp == 0x19)
        FUN_140d5dd80(packet);
    else if (nOp == 0x1a)
        FUN_140d5de90(packet);
    else if (nOp == 0x1b)
        FUN_140d5e190(packet);
    else if (nOp == 0x1e)
        FUN_140d5ed50(packet);
    else if (nOp == 0x1f)
        FUN_140d5f190(packet);
    else if (nOp == 0x22)
        FUN_140d5f250(packet);
    else if (nOp == 0x20)
        FUN_140d5f5b0(packet);
    else if (nOp == 0x21)
        FUN_140d5f5e0(packet);
    else if (nOp == 0x00)
        FUN_140d5f610(packet);
    else if (nOp == 0x6b)
        FUN_140d5e020(packet);
    else if (nOp == 0x1c)
        FUN_140d5e540(packet);
    else if (nOp == 0x6e)
        FUN_140d5e930(packet);
    else if (nOp == 0x72)
        FUN_140d5e970(packet);
}

// Ask for the shop list of a sort kind (sub-opcode 0x65).
// @0x140d542c0
void CMeratMarketMan::FUN_140d542c0(int nTab, int nSort)
{
    if (nTab != 5 && FUN_1406a5040(nSort)) {
        COutPacket packet(0x39, 0);
        packet.vfunc_o10_1(0x65);
        packet.vfunc_o10_1((unsigned char)nTab);
        packet.vfunc_o10_1((unsigned char)nSort);
        FUN_140710590(packet);
    }
}

// @0x140d54360
void CMeratMarketMan::FUN_140d54360()
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x66);
    FUN_140710590(packet);
}

// Ask for the ad list and drop the cached one.
// @0x140d543c0
void CMeratMarketMan::FUN_140d543c0(int nFlag)
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x67);
    FUN_140710590(packet);
    FUN_140d59ce0();
    FUN_1418ffec0(m_nFlags, nFlag);
}

// @0x140d54440
void CMeratMarketMan::FUN_140d54440()
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x6b);
    FUN_140710590(packet);
}

// @0x140d544a0
void CMeratMarketMan::FUN_140d544a0()
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x0b);
    FUN_140710590(packet);
}

// @0x140d54500
void CMeratMarketMan::FUN_140d54500()
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x0c);
    FUN_140710590(packet);
}

// Register a UGC design for sale (sub-opcode 0x0d).
// @0x140d54560
void CMeratMarketMan::FUN_140d54560(MS2Ptr<CMeratMarketPacket::UgcAddProduct> spRequest)
{
    if (spRequest == 0)
        return;
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x0d);
    spRequest->vfunc_1(packet);
    FUN_140710590(packet);
}

// Stop selling a UGC product (sub-opcode 0x0e).
// @0x140d54610
void CMeratMarketMan::FUN_140d54610(Unk_MeratProductKey key)
{
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(key);
    if (spProduct == 0)
        return;
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x0e);
    key.Write(packet);
    packet.vfunc_o10_4(spProduct->m_ugc.m_n20);
    FUN_140710590(packet);
}

// Delete a UGC product (sub-opcode 0x0f).
// @0x140d54700
void CMeratMarketMan::FUN_140d54700(Unk_MeratProductKey key)
{
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(key);
    if (spProduct == 0)
        return;
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x0f);
    key.Write(packet);
    packet.vfunc_o10_4(spProduct->m_ugc.m_n20);
    FUN_140710590(packet);
}

// Put a UGC product on sale again (sub-opcode 0x12).
// @0x140d547f0
void CMeratMarketMan::FUN_140d547f0(MS2Ptr<CMeratMarketPacket::UgcResaleProduct> spRequest)
{
    if (spRequest == 0)
        return;
    Unk_MeratProductKey key(0, spRequest->product);
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(key);
    if (spProduct == 0)
        return;
    CMeratMarketProduct* pProduct = spProduct.operator->();
    spRequest->product = pProduct->m_ugc.m_n20;
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x12);
    spRequest->vfunc_1(packet);
    FUN_140710590(packet);
}

// Ask for the sale details of a UGC product (sub-opcode 0x13).
// @0x140d54960
void CMeratMarketMan::FUN_140d54960(Unk_MeratProductKey key)
{
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(key);
    if (spProduct == 0)
        return;
    Unk_MmUid uid;
    uid.m_n = spProduct->m_ugc.m_n20;
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x13);
    FUN_1401fe790(&uid, packet);
    FUN_140710590(packet);
}

// Ask for the sales of a seller (sub-opcode 0x14).
// @0x140d54a50
void CMeratMarketMan::FUN_140d54a50(__int64 nSellerId)
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x14);
    packet.vfunc_o10_4(nSellerId);
    FUN_140710590(packet);
}

// Ask for the next seller's sales, or finish when there are none.
// @0x140d54ac0
void CMeratMarketMan::FUN_140d54ac0()
{
    m_ne0 = 0;
    if (!m_sellers.IsEmpty()) {
        MS2Ptr<CUgcMarketSeller> spSeller = FUN_140d56000();
        if (spSeller.get() != 0) {
            if (FUN_140d567a0(spSeller)) {
                FUN_140d566f0(1);
                FUN_140d54a50(spSeller->m_n18);
            }
        }
    } else {
        FUN_140d56840();
    }
}

// @0x140d54ba0
void CMeratMarketMan::FUN_140d54ba0()
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x16);
    FUN_140710590(packet);
}

// @0x140d54c00
void CMeratMarketMan::FUN_140d54c00(__int64 nId)
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x17);
    packet.vfunc_o10_4(nId);
    FUN_140710590(packet);
}

// @0x140d54c70
void CMeratMarketMan::FUN_140d54c70(__int64 nId)
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x18);
    packet.vfunc_o10_4(nId);
    FUN_140710590(packet);
}

// @0x140d54ce0
void CMeratMarketMan::FUN_140d54ce0(__int64 nId)
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x19);
    packet.vfunc_o10_4(nId);
    FUN_140710590(packet);
}

// Search the market (sub-opcode 0x1b).
// @0x140d54d50
void CMeratMarketMan::FUN_140d54d50(MS2Ptr<CMeratMarketSchCond> spCond)
{
    if (spCond == 0)
        return;
    int nPage = spCond->m_30;
    spCond->m_34 = nPage;
    if (spCond->m_44 != 0)
        spCond->m_30 = nPage - 4;
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x1b);
    spCond->Write(&packet);
    FUN_140710590(packet);
}

// Search the UGC market: a category search (0x1c) or a text search (0x69).
// @0x140d54e50
void CMeratMarketMan::FUN_140d54e50(MS2Ptr<CMeratMarketSchCond> spCond)
{
    if (spCond == 0)
        return;
    int nPage = spCond->m_30;
    spCond->m_34 = nPage;
    if (spCond->m_44 != 0)
        spCond->m_30 = nPage - 4;
    if (spCond->m_str.IsEmpty()) {
        COutPacket packet(0x39, 0);
        packet.vfunc_o10_1(0x1c);
        spCond->Write(&packet);
        FUN_140710590(packet);
    } else {
        COutPacket packet(0x39, 0);
        packet.vfunc_o10_1(0x69);
        spCond->Write(&packet);
        packet.vfunc_o10_0(true);
        FUN_140710590(packet);
    }
}

// Like / unlike a product (sub-opcode 0x1d).
// @0x140d54fe0
void CMeratMarketMan::FUN_140d54fe0(bool bLike, const __int64& nUgcId, const int& nUIClassID)
{
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x1d);
    packet.vfunc_o10_1(bLike);
    packet.vfunc_o10_4(nUgcId);
    packet.vfunc_o10_0(nUIClassID == 0x4f7f);
    FUN_140710590(packet);
}

// Search with a sort byte (sub-opcode 0x68).
// @0x140d550c0
void CMeratMarketMan::FUN_140d550c0(MS2Ptr<CMeratMarketSchCond> spCond, unsigned char nSort)
{
    if (spCond == 0)
        return;
    int nPage = spCond->m_30;
    spCond->m_34 = nPage;
    if (spCond->m_44 != 0)
        spCond->m_30 = nPage - 4;
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x68);
    spCond->Write(&packet);
    packet.vfunc_o10_1(nSort);
    FUN_140710590(packet);
}

// Ask for premium products by id (sub-opcode 0x20, at most 20).
// @0x140d551e0
void CMeratMarketMan::FUN_140d551e0(ATL::CAtlArray<int>& ids)
{
    if (ids.GetCount() < 0x15) {
        COutPacket packet(0x39, 0);
        packet.vfunc_o10_1(0x20);
        packet.vfunc_o10_3((int)ids.GetCount());
        for (unsigned int i = 0; i < ids.GetCount(); i++)
            packet.vfunc_o10_3(ids.GetAt(i));
        FUN_140710590(packet);
    }
}

// Ask for UGC products by id (sub-opcode 0x21, at most 20).
// @0x140d552c0
void CMeratMarketMan::FUN_140d552c0(ATL::CAtlArray<unsigned __int64>& ids)
{
    if (ids.GetCount() < 0x15) {
        COutPacket packet(0x39, 0);
        packet.vfunc_o10_1(0x21);
        packet.vfunc_o10_3((int)ids.GetCount());
        for (unsigned int i = 0; i < ids.GetCount(); i++)
            packet.vfunc_o10_4(ids[i]);
        FUN_140710590(packet);
    }
}

// Refresh the random-sale products of the open dialog once a day.
// @0x140d553a0
void CMeratMarketMan::FUN_140d553a0()
{
    CMsTime now(FUN_140869440());
    Unk_MmScopedLock lock(m_lock, 1);
    Unk_MmDialog* pDialog = FUN_140bd2c00();
    if (pDialog == 0)
        return;
    CMsTime last = pDialog->FUN_14130bea0();
    unsigned int nCount = (unsigned int)m_228.GetCount();
    for (unsigned int i = 0; i < nCount; i++) {
        MS2Ptr<CMeratMarketProduct> spProduct = m_228.GetAt(i);
        if (spProduct == 0)
            continue;
        int nType = spProduct->GetType();
        if (nType != 7 && nType != 8)
            continue;
        if (IsNotRecentDayChange(last.Get())) {
            pDialog->FUN_1412ebc40(spProduct);
            continue;
        }
        if (spProduct->m_premium.m_n1ac == 0)
            continue;
        if (!spProduct->m_premium.FUN_1406a0090())
            continue;
        spProduct->m_premium.m_n1ac = 0;
        pDialog->FUN_1412ebc40(spProduct);
    }
    pDialog->FUN_14130bee0(now);
}

// Add a UGC product; true when it is new.
// @0x140d55620
bool CMeratMarketMan::FUN_140d55620(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0)
        return false;
    if (spProduct->m_nKind != 1)
        return false;
    MS2Ptr<CMeratMarketProduct> spOld = FUN_140d55800(spProduct->m_key);
    bool bNew = spOld.get() == 0;
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_products.SetAt(spProduct->m_key, spProduct);
    return bNew;
}

// @0x140d55790
void CMeratMarketMan::FUN_140d55790(const Unk_MeratProductKey& key)
{
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_products.RemoveKey(key);
}

// The product of a key.
// @0x140d55800
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d55800(Unk_MeratProductKey key)
{
    MS2Ptr<CMeratMarketProduct> spProduct(0);
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_products.Lookup(key, spProduct);
    return spProduct;
}

// The UGC product of a product uid.
// @0x140d558c0
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d558c0(__int64 nUid)
{
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        POSITION pos = m_products.GetHeadPosition();
        while (pos != 0) {
            MS2Ptr<CMeratMarketProduct> spProduct = m_products.GetValueAt(pos);
            if (spProduct.get() != 0 && spProduct->m_ugc.m_n20 == nUid)
                return spProduct;
            m_products.GetNext(pos);
        }
    }
    return MS2Ptr<CMeratMarketProduct>(0);
}

// The UGC product of a design (item look) uid.
// @0x140d55a10
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d55a10(__int64 nUgcUid)
{
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        POSITION pos = m_products.GetHeadPosition();
        while (pos != 0) {
            MS2Ptr<CMeratMarketProduct> spProduct = m_products.GetValueAt(pos);
            if (spProduct.get() != 0 && spProduct->m_ugc.m_look.m_n18 == nUgcUid)
                return spProduct;
            m_products.GetNext(pos);
        }
    }
    return MS2Ptr<CMeratMarketProduct>(0);
}

// The UGC product of a music score uid.
// @0x140d55b60
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d55b60(__int64 nMusicUid)
{
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        POSITION pos = m_products.GetHeadPosition();
        while (pos != 0) {
            MS2Ptr<CMeratMarketProduct> spProduct = m_products.GetValueAt(pos);
            if (spProduct.get() != 0) {
                if (spProduct->m_ugc.FUN_140896310()) {
                    if (spProduct->m_ugc.m_music.m_n18 == nMusicUid)
                        return spProduct;
                }
            }
            m_products.GetNext(pos);
        }
    }
    return MS2Ptr<CMeratMarketProduct>(0);
}

// Add a seller (and its sales to the sums) when it is new.
// @0x140d55ce0
void CMeratMarketMan::FUN_140d55ce0(MS2Ptr<CUgcMarketSeller> spSeller)
{
    if (spSeller == 0)
        return;
    MS2Ptr<CUgcMarketSeller> spOld = FUN_140d55f40(spSeller->m_n18);
    if (spOld.get() != 0)
        return;
    FUN_140d56320(spSeller, spSeller->m_n80);
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_sellers.SetAt(spSeller->m_n18, spSeller);
}

// Remove a seller (and its sales from the sums).
// @0x140d55e50
void CMeratMarketMan::FUN_140d55e50(MS2Ptr<CUgcMarketSeller> spSeller)
{
    if (spSeller.get() == 0)
        return;
    __int64 nAmount = spSeller->m_n80;
    FUN_140d56320(spSeller, -nAmount);
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_sellers.RemoveKey(spSeller->m_n18);
}

// The seller of an id.
// @0x140d55f40
MS2Ptr<CUgcMarketSeller> CMeratMarketMan::FUN_140d55f40(__int64 nId)
{
    MS2Ptr<CUgcMarketSeller> spSeller(0);
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_sellers.Lookup(nId, spSeller);
    return spSeller;
}

// The first seller.
// @0x140d56000
MS2Ptr<CUgcMarketSeller> CMeratMarketMan::FUN_140d56000()
{
    MS2Ptr<CUgcMarketSeller> spSeller(0);
    Unk_LockGuard lock(m_lock);
    POSITION pos;
    if (!lock && (pos = m_sellers.GetHeadPosition()) != 0)
        spSeller = m_sellers.GetValueAt(pos);
    return spSeller;
}

// @0x140d560e0
int CMeratMarketMan::FUN_140d560e0()
{
    int nCount = 0;
    Unk_LockGuard lock(m_lock);
    if (!lock)
        nCount = (int)m_sellers.GetCount();
    return nCount;
}

// @0x140d56160
int CMeratMarketMan::FUN_140d56160()
{
    return (int)m_products.GetCount();
}

// Recompute the sale sums: the sales still in the settlement period, and the settled ones.
// @0x140d56190
void CMeratMarketMan::FUN_140d56190()
{
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        FUN_140d566f0(0);
        m_nd8 = 0;
        m_nd0 = 0;
        POSITION pos = m_sellers.GetHeadPosition();
        while (pos != 0) {
            MS2Ptr<CUgcMarketSeller> spSeller = m_sellers.GetValueAt(pos);
            if (spSeller.get() != 0) {
                __int64 nAmount = spSeller->m_n90;
                if (m_nf0 < FUN_140d61530(spSeller->m_n88, m_n1c4))
                    m_nd0 += nAmount;
                else
                    m_nd8 += nAmount;
            }
            m_sellers.GetNext(pos);
        }
        m_bf8 = true;
    }
}

// Add (or with a negative amount, remove) a seller's sales to the sums.
// @0x140d56320
void CMeratMarketMan::FUN_140d56320(MS2Ptr<CUgcMarketSeller> spSeller, __int64 nAmount)
{
    if (m_nf0 == 0)
        m_nf0 = FUN_140869440();
    if (spSeller == 0)
        return;
    if (m_bf8) {
        __int64 nSales = spSeller->m_n90;
        if (nAmount < 0)
            nSales = -nSales;
        if (m_nf0 < FUN_140d61530(spSeller->m_n88, m_n1c4))
            m_nd0 += nSales;
        else
            m_nd8 += nSales;
    }
    m_ne8 += nAmount;
}

// @0x140d56470
__int64 CMeratMarketMan::FUN_140d56470()
{
    return m_nd8;
}

// @0x140d56490
__int64 CMeratMarketMan::FUN_140d56490()
{
    return m_nd0;
}

// The goal count of the UGC seller achievement grade.
// @0x140d564b0
int CMeratMarketMan::FUN_140d564b0()
{
    if (m_n1b8 == 0) {
        MS2_ASSERT_AT(0x776, 0);
    } else {
        MS2Ptr<CAchieveGradeData> spGrade = CAchieveData::Find(0x141f613, m_n1b8);
        if (!(spGrade == 0) && !(spGrade->m_pCondition == 0))
            return (int)spGrade->m_pCondition->m_nGoal;
        MS2_ASSERT_AT(0x77d, 0);
    }
    return 0;
}

// The goal count of the UGC buyer achievement grade.
// @0x140d565c0
int CMeratMarketMan::FUN_140d565c0()
{
    if (m_n1bc == 0) {
        MS2_ASSERT_AT(0x788, 0);
    } else {
        MS2Ptr<CAchieveGradeData> spGrade = CAchieveData::Find(0x141f614, m_n1bc);
        if (!(spGrade == 0) && !(spGrade->m_pCondition == 0))
            return (int)spGrade->m_pCondition->m_nGoal;
        MS2_ASSERT_AT(0x78f, 0);
    }
    return 0;
}

// @0x140d566d0
int CMeratMarketMan::FUN_140d566d0()
{
    return m_nSellerState;
}

// @0x140d566f0
void CMeratMarketMan::FUN_140d566f0(int nState)
{
    int nOld = m_nSellerState;
    m_nSellerState = nState;
    Unk_MmDialog* pDialog;
    if (nOld != nState && (pDialog = FUN_140bd2c00()) != 0)
        pDialog->FUN_14130d150(m_nSellerState, m_nd8);
}

// @0x140d56780
__int64 CMeratMarketMan::FUN_140d56780()
{
    return m_nf0;
}

// The seller's settlement period is over.
// @0x140d567a0
bool CMeratMarketMan::FUN_140d567a0(MS2Ptr<CUgcMarketSeller> spSeller)
{
    if (spSeller.get() == 0)
        return false;
    return FUN_140d61530(spSeller->m_n88, m_n1c4) <= m_nf0;
}

// The settlement is done: show the settled amount.
// @0x140d56840
int CMeratMarketMan::FUN_140d56840()
{
    int nOld = FUN_140d566d0();
    FUN_140d566f0(0);
    if (nOld != 0 && 0 < m_ne0) {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, FormatStringId(0xa36, FUN_1409404f0(m_ne0)), 0, CStringW(L""));
        if (spBox.get() != 0) {
            spBox->FUN_141a01c30(s_marketCalculate);
            FUN_140d73c60(spBox);
            FUN_141276180(s_ugcEndSale, CString(""));
        }
        m_ne0 = 0;
    }
    return 1;
}

// Add a bookmark (at most 16).
// @0x140d56a40
void CMeratMarketMan::FUN_140d56a40(MS2Ptr<CUgcBookMark> spOwner)
{
    if (spOwner == 0)
        return;
    if (FUN_140d56e40() >= 0x10)
        return;
    if (FUN_140d56db0(spOwner->m_n20))
        return;
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        MS2Ptr<CUgcCharBookMark> spMark(new CUgcCharBookMark(spOwner));
        m_bookMarks.SetAt(spOwner->m_n20, spMark);
    }
}

// @0x140d56be0
void CMeratMarketMan::FUN_140d56be0(__int64 nId)
{
    if (FUN_140d56db0(nId)) {
        Unk_LockGuard lock(m_lock);
        if (!lock)
            m_bookMarks.RemoveKey(nId);
    }
}

// @0x140d56c60
void CMeratMarketMan::FUN_140d56c60()
{
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_bookMarks.RemoveAll();
}

// The bookmark of an id.
// @0x140d56cc0
MS2Ptr<CUgcCharBookMark> CMeratMarketMan::FUN_140d56cc0(__int64 nId)
{
    if (!FUN_140d56db0(nId))
        return MS2Ptr<CUgcCharBookMark>(0);
    MS2Ptr<CUgcCharBookMark> spMark(0);
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_bookMarks.Lookup(nId, spMark);
    return spMark;
}

// @0x140d56db0
int CMeratMarketMan::FUN_140d56db0(__int64 nId)
{
    int bFound = 0;
    Unk_LockGuard lock(m_lock);
    if (!lock && m_bookMarks.Lookup(nId) != 0)
        bFound = 1;
    return bFound;
}

// @0x140d56e40
int CMeratMarketMan::FUN_140d56e40()
{
    int nCount = 0;
    Unk_LockGuard lock(m_lock);
    if (!lock)
        nCount = (int)m_bookMarks.GetCount();
    return nCount;
}

// Read the products of a bookmark.
// @0x140d56eb0
void CMeratMarketMan::FUN_140d56eb0(__int64 nId, CInPacket& packet)
{
    if (!FUN_140d56db0(nId))
        return;
    MS2Ptr<CUgcCharBookMark> spMark = FUN_140d56cc0(nId);
    if (spMark == 0)
        return;
    spMark->FUN_140896d90();
    int nCount = packet.vfunc_o8_3();
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
            spMark->FUN_140896dd0(spProduct);
        }
    }
}

// Add a product to a map and a list.
// @0x140d57090
void CMeratMarketMan::FUN_140d57090(MS2Ptr<CMeratMarketProduct> spProduct, Unk_MeratProductMap& map, Unk_MeratProductArray& list)
{
    if (spProduct == 0)
        return;
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        map.SetAt(spProduct->m_key, spProduct);
        list.Add(spProduct);
    }
}

// Find a product anywhere (or in a bookmark).
// @0x140d57150
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d57150(Unk_MeratProductKey key, __int64 nBookMarkId)
{
    MS2Ptr<CMeratMarketProduct> spProduct(0);
    if (nBookMarkId == 0) {
        spProduct = FUN_140d575e0(key);
        if (spProduct.get() != 0)
            return spProduct;
        spProduct = FUN_140d576a0(key);
        if (spProduct.get() != 0)
            return spProduct;
        spProduct = FUN_140d57d80(key);
        if (spProduct.get() != 0)
            return spProduct;
        spProduct = FUN_140d57f70(key);
        if (spProduct.get() != 0)
            return spProduct;
        spProduct = FUN_140d578d0(key);
        if (spProduct.get() != 0)
            return spProduct;
    } else {
        MS2Ptr<CUgcCharBookMark> spMark = FUN_140d56cc0(nBookMarkId);
        if (spMark.get() != 0)
            spProduct = spMark->FUN_140896e80(key);
    }
    return spProduct;
}

// @0x140d575e0
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d575e0(Unk_MeratProductKey key)
{
    MS2Ptr<CMeratMarketProduct> spProduct(0);
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_120.Lookup(key, spProduct);
    return spProduct;
}

// @0x140d576a0
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d576a0(Unk_MeratProductKey key)
{
    MS2Ptr<CMeratMarketProduct> spProduct(0);
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_170.Lookup(key, spProduct);
    return spProduct;
}

// The ad product at an index.
// @0x140d57760
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d57760(int nIndex)
{
    MS2Ptr<CMeratMarketProduct> spProduct(0);
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        if (m_270.IsEmpty())
            return MS2Ptr<CMeratMarketProduct>(0);
        if (nIndex < 0 || (int)m_270.GetCount() <= nIndex)
            return MS2Ptr<CMeratMarketProduct>(0);
        spProduct = m_270[nIndex];
    }
    return spProduct;
}

// The ad product of a key.
// @0x140d578d0
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d578d0(Unk_MeratProductKey key)
{
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        if (m_270.IsEmpty())
            return MS2Ptr<CMeratMarketProduct>(0);
        size_t nCount = m_270.GetCount();
        for (unsigned int i = 0; i < nCount; i++) {
            MS2Ptr<CMeratMarketProduct> spProduct = m_270[i];
            if (spProduct.get() != 0 && spProduct->m_key.FUN_140899ce0(key))
                return spProduct;
        }
    }
    return MS2Ptr<CMeratMarketProduct>(0);
}

// The premium products of a category and tab that the player can see.
// @0x140d57a80
bool CMeratMarketMan::FUN_140d57a80(unsigned int nCategory, int nTab, Unk_MeratProductArray& out)
{
    {
        Unk_LockGuard lock(m_lock);
        if (!lock) {
            if (m_lists.empty())
                return false;
            Unk_MeratProductListMap::iterator it = m_lists.find(std::pair<unsigned int, int>(nCategory, nTab));
            if (it == m_lists.end())
                return false;
            const TPtrValue<std::list<MS2Ptr<CMeratMarketProduct> > > spList = it->second;
            if (spList == 0 || spList->empty() == true)
                return false;
            unsigned short nLevel = 0;
            PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPlayer != 0)
                nLevel = (unsigned short)pPlayer->vfunc_78();
            for (std::list<MS2Ptr<CMeratMarketProduct> >::iterator itProduct = spList->begin(); itProduct != spList->end(); ++itProduct) {
                MS2Ptr<CMeratMarketProduct> spProduct = *itProduct;
                if (spProduct == 0)
                    continue;
                if (!spProduct->IsPremium())
                    continue;
                if (FUN_140ebfc70(nLevel, &spProduct->m_premium, false))
                    out.Add(spProduct);
            }
        }
    }
    return !out.IsEmpty();
}

// @0x140d57d80
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d57d80(Unk_MeratProductKey key)
{
    MS2Ptr<CMeratMarketProduct> spProduct(0);
    Unk_LockGuard lock(m_lock);
    if (!lock)
        m_1f8.Lookup(key, spProduct);
    return spProduct;
}

// @0x140d57e40
void CMeratMarketMan::FUN_140d57e40()
{
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        m_1f8.RemoveAll();
        m_228.RemoveAll();
        m_248.RemoveAll();
    }
}

// The basket line at an index.
// @0x140d57ed0
MS2Ptr<CMeratMarketBasket> CMeratMarketMan::FUN_140d57ed0(unsigned int nIndex)
{
    if (nIndex < m_basket.GetCount())
        return m_basket[nIndex];
    return MS2Ptr<CMeratMarketBasket>(0);
}

// The basket product of a key.
// @0x140d57f70
MS2Ptr<CMeratMarketProduct> CMeratMarketMan::FUN_140d57f70(Unk_MeratProductKey key)
{
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        for (unsigned int i = 0; i < m_basket.GetCount(); i++) {
            MS2Ptr<CMeratMarketBasket> spLine = m_basket[i];
            if (spLine.get() != 0) {
                if (spLine->m_spProduct.get() != 0 && spLine->m_spProduct->m_key.FUN_140899ce0(key))
                    return spLine->m_spProduct;
            }
        }
    }
    return MS2Ptr<CMeratMarketProduct>(0);
}

// Add a basket line and tell the dialog.
// @0x140d58130
int CMeratMarketMan::FUN_140d58130(MS2Ptr<CMeratMarketBasket> spLine)
{
    if (spLine == 0)
        return 0;
    int nIndex = (int)m_basket.GetCount();
    {
        Unk_LockGuard lock(m_lock);
        if (!lock)
            m_basket.Add(spLine);
    }
    Unk_MmDialog* pDialog = FUN_140bd2c00();
    if (pDialog != 0)
        pDialog->FUN_14130f010(spLine, nIndex);
    return 1;
}

// Put a product in the basket (at most 16 lines).
// @0x140d58260
int CMeratMarketMan::FUN_140d58260(MS2Ptr<CMeratMarketProduct> spProduct, __int64 nBookMarkId)
{
    if (spProduct == 0)
        return 0;
    if (m_basket.GetCount() >= 0x10)
        return 0;
    MS2Ptr<CMeratMarketBasket> spLine(new CMeratMarketBasket());
    spLine->m_spProduct = spProduct;
    spLine->m_n28 = nBookMarkId;
    FUN_140d58130(spLine);
    return 1;
}

// Mark a basket line as bought.
// @0x140d583d0
void CMeratMarketMan::FUN_140d583d0(unsigned int nIndex)
{
    if (nIndex < m_basket.GetCount()) {
        Unk_MeratProductKey key;
        MS2Ptr<CMeratMarketBasket> spLine = m_basket[nIndex];
        if (spLine.get() != 0) {
            key = spLine->m_spProduct->m_key;
            spLine->FUN_140d6a9d0(true);
            m_b1f0 = true;
        }
    }
}

// Remove a basket line and tell the dialog.
// @0x140d584c0
void CMeratMarketMan::FUN_140d584c0(unsigned int nIndex)
{
    if (nIndex < m_basket.GetCount()) {
        Unk_MeratProductKey key;
        MS2Ptr<CMeratMarketBasket> spLine = m_basket[nIndex];
        if (spLine.get() != 0) {
            key = spLine->m_spProduct->m_key;
            {
                Unk_LockGuard lock(m_lock);
                if (!lock) {
                    m_basket.RemoveAt(nIndex, 1);
                    m_basket.FreeExtra();
                }
            }
            Unk_MmDialog* pDialog = FUN_140bd2c00();
            if (pDialog != 0)
                pDialog->FUN_14130f310(key, nIndex);
        }
    }
}

// Start the queued purchases (all of one buy type).
// @0x140d58650
void CMeratMarketMan::FUN_140d58650(int nBuyType)
{
    if (m_n2a0 == 0) {
        if (!m_pending.IsEmpty()) {
            if (nBuyType == m_n2a8) {
                m_n2a0 = 1;
                MS2Ptr<CPendingBuyBase> spBuy = m_pending[0];
                if (spBuy.get() != 0)
                    spBuy->vfunc_4();
            } else {
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_meratmarket_error_buying_diff_buytype")), 1, 1);
            }
        } else {
            FUN_140d589f0(0);
        }
    } else {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_meratmarket_error_buying")), 1, 1);
    }
}

// One queued purchase is answered: store the result and start the next one (or finish).
// @0x140d58810
void CMeratMarketMan::FUN_140d58810(bool bSuccess, int nResult, int nIndex)
{
    if (m_n2a0 == 0)
        return;
    {
        MS2Ptr<CPendingBuyBase> spBuy = m_pending[nIndex];
        if (spBuy.get() != 0) {
            spBuy->m_nState = nResult;
            if (spBuy->m_nCount == 2) {
                MS2Ptr<CMeratMarketBuy> spMarketBuy(dynamic_cast<CMeratMarketBuy*>(spBuy.get()));
                if (spMarketBuy.get() != 0)
                    FUN_140d583d0(spMarketBuy->FUN_140d60ef0());
            }
        }
    }
    if (nIndex + 1 < (int)m_pending.GetCount()) {
        MS2Ptr<CPendingBuyBase> spNext = m_pending[nIndex + 1];
        if (spNext.get() != 0)
            spNext->vfunc_4();
    } else {
        FUN_140d59930();
        FUN_140d589f0(0);
    }
}

// All queued purchases are answered (or cancelled): show one message box with the bought and the failed products.
// @0x140d589f0
void CMeratMarketMan::FUN_140d589f0(int bCancel)
{
    m_n2a0 = 0;
    m_n2a4 = 0;
    FUN_1403ed2b0()->FUN_141adc5d0(0x4f17);
    if (bCancel) {
        FUN_140d595b0();
        return;
    }
    if (m_pending.IsEmpty())
        return;
    int nCount = (int)m_pending.GetCount();
    int nFailed = 0;
    CStringW strFail(L"");
    CStringW strOk(L"");
    bool bPremium = false;
    {
        MS2Ptr<CPendingBuyBase> spFirst = m_pending[0];
        if (spFirst.get() != 0)
            bPremium = spFirst->vfunc_5();
    }
    int nOkId = bPremium ? 0x9fc : 0x9f6;
    int nFailId = bPremium ? 0x9fd : 0x9f7;
    CStringW strOkFormat = FUN_14028de60(nOkId);
    CStringW strFailFormat = FUN_14028de60(nFailId);
    CStringW strItemName = FUN_14028b8e0(CStringW(L"s_meratmarket_buy_itemname"));
    m_b2d8 = false;
    for (unsigned i = 0; i < m_pending.GetCount(); i++) {
        MS2Ptr<CPendingBuyBase> spBuy = m_pending[i];
        if (spBuy.get() == 0)
            continue;
        CStringW strName = spBuy->vfunc_1();
        if (spBuy->m_nState == 0) {
            if (!strOk.IsEmpty())
                strOk += L"\n";
            strOk += StringFormat(strOkFormat, strName, FUN_1418fec00(spBuy->vfunc_3(), spBuy->vfunc_2(), 0));
        } else {
            if (spBuy->m_nState == 0x88)
                m_b2d8 = true;
            if (!strFail.IsEmpty())
                strFail += L"\n";
            strFail += StringFormat(strFailFormat, strName, FUN_1418fec00(spBuy->vfunc_3(), spBuy->vfunc_2(), 0),
                                    FUN_140d5a330(spBuy->m_nState, spBuy));
            nFailed++;
        }
    }
    if (FUN_1422b9dc0(FUN_1408e57f0()) == 0x620000c) {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x10, CStringW(L""), 0, CStringW(L""));
        if (spBox.get() != 0) {
            CStringW strTitle = FUN_14028de60(0x9f4);
            CStringW strCaption = FUN_14028de60(bPremium ? 0x9fb : 0x9f5);
            spBox->FUN_141a015d0(strCaption);
            spBox->FUN_141a02770(0x1e0, 300);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CMeratMarketMan::FUN_140d60280));
            if (nFailed == 0) {
                spBox->FUN_141a01570(StringFormat(strTitle, FUN_14028de60(bPremium ? 0x9fe : 0x9f8), strOk));
                spBox->FUN_141a01c30(s_cashBuy);
            } else if (nCount == nFailed) {
                spBox->FUN_141a01570(StringFormat(strTitle, FUN_14028de60(bPremium ? 0xa00 : 0x9fa), strFail));
            } else {
                spBox->FUN_141a01570(StringFormat(strTitle, FUN_14028de60(bPremium ? 0x9ff : 0x9f9),
                                                  StringFormat(L"{0}\n{1}", strOk, strFail)));
                spBox->FUN_141a01c30(s_cashBuy);
            }
            FUN_140d73c60(spBox);
        }
    }
    FUN_140d595b0();
}

// Forget the queued purchases and drop the bought basket lines.
// @0x140d595b0
void CMeratMarketMan::FUN_140d595b0()
{
    m_n2a8 = 0;
    m_pending.RemoveAll();
    m_n2a4 = 0;
    if (!m_b1f0)
        return;
    if (!m_basket.IsEmpty()) {
        Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
        bool bRemoved = false;
        for (int i = (int)m_basket.GetCount() - 1; i >= 0; i--) {
            MS2Ptr<CMeratMarketBasket> spLine = m_basket[i];
            if (spLine.get() != 0 && spLine->FUN_140d676f0()) {
                if (pDialog != 0)
                    pDialog->FUN_14130f310(spLine->FUN_140d613e0(), i);
                Unk_LockGuard lock(m_lock);
                if (!lock) {
                    m_basket.RemoveAt(i, 1);
                    bRemoved = true;
                }
            }
        }
        if (bRemoved) {
            Unk_LockGuard lock(m_lock);
            if (!lock)
                m_basket.FreeExtra();
        }
    }
    m_b1f0 = false;
}

// Queue a purchase (all queued purchases must be of one buy type).
// @0x140d59810
void CMeratMarketMan::FUN_140d59810(MS2Ptr<CPendingBuyBase> spBuy, int nBuyType)
{
    if (m_n2a0 != 0)
        return;
    if (m_n2a8 == 0 && m_pending.IsEmpty())
        m_n2a8 = nBuyType;
    if (nBuyType == m_n2a8)
        m_pending.Add(spBuy);
    else
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_meratmarket_error_buying_diff_buytype")), 1, 1);
}

// After a shop purchase: refresh the shop dialog.
// @0x140d59930
void CMeratMarketMan::FUN_140d59930()
{
    if (m_n2a8 == 4)
        FUN_140534780(0x4e3b);
}

// @0x140d59970
__int64 CMeratMarketMan::FUN_140d59970()
{
    return m_n1a8;
}

// @0x140d59990
void CMeratMarketMan::FUN_140d59990(const CStringW& str)
{
    m_str2d0 = str;
}

// The purchase title (a default text when none is set).
// @0x140d599d0
CStringW CMeratMarketMan::FUN_140d599d0()
{
    if (m_str2d0.IsEmpty())
        return FUN_1409eec40(0xa46);
    return m_str2d0;
}

// Add an advertised product, into its (category, tab) list (free products first).
// @0x140d59a60
bool CMeratMarketMan::FUN_140d59a60(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0)
        return false;
    std::pair<unsigned int, int> key(spProduct->m_premium.m_nf8, spProduct->m_premium.m_nfc);
    TPtrValue<std::list<MS2Ptr<CMeratMarketProduct> > > spList(0);
    Unk_LockGuard lock(m_lock);
    if (!lock) {
        m_270.Add(spProduct);
        Unk_MeratProductListMap::iterator it = m_lists.find(key);
        if (it != m_lists.end()) {
            spList = it->second;
        } else {
            spList = TPtrValue<std::list<MS2Ptr<CMeratMarketProduct> > >(Unk_GrNewTag(0));
            m_lists[key] = spList;
        }
        if (spList.get() != 0) {
            if (spProduct->GetSalePrice() == 0)
                spList->push_front(spProduct);
            else
                spList->push_back(spProduct);
            return true;
        }
    }
    return false;
}

// Forget the advertised products and stop watching the level.
// @0x140d59ce0
void CMeratMarketMan::FUN_140d59ce0()
{
    {
        Unk_LockGuard lock(m_lock);
        if (!lock) {
            m_270.RemoveAll();
            m_lists.clear();
        }
    }
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyChangeMyLevel"),
                                   Delegate<void(NotifyObject*)>(this, &CMeratMarketMan::FUN_140d59df0));
}

// "NotifyChangeMyLevel"
// @0x140d59df0
void CMeratMarketMan::FUN_140d59df0(NotifyObject* pObject)
{
    FUN_140d5ba70();
}

// Send a purchase request.
// @0x140d5a0d0
void CMeratMarketMan::FUN_140d5a0d0(MS2Ptr<CMeratMarketBuy> spBuy)
{
    if (spBuy == 0 || spBuy->m_spPacket == 0)
        return;
    CMeratMarketPacket::BuyPacket* pPacket = spBuy->m_spPacket.get();
    COutPacket packet(0x39, 0);
    packet.vfunc_o10_1(0x1e);
    pPacket->Write(packet);
    FUN_140710590(packet);
}

// @0x140d5a1b0
__int64 CMeratMarketMan::FUN_140d5a1b0()
{
    return m_n1b0;
}

// The merat amount needed for a UGC seller (a game constant).
// @0x140d5a1d0
__int64 CMeratMarketMan::FUN_140d5a1d0()
{
    return *FUN_1402c05b0(&FUN_1401d3200()->m_sellerLimit);
}

// A dialog closed.
// @0x140d5a200
void CMeratMarketMan::FUN_140d5a200(const int& nUIClassID)
{
    if (nUIClassID == 0x4ec1) {
        FUN_140d57e40();
        FUN_140d589f0(1);
        m_bf8 = false;
    } else if (nUIClassID == 0x4e3b && m_n2a0 != 0 && m_n2a8 == 4) {
        FUN_140d589f0(1);
    }
}

// Leaving the field: close the market and the shop, forget the ad products.
// @0x140d5a290
void CMeratMarketMan::FUN_140d5a290()
{
    FUN_140d5a200(0x4ec1);
    FUN_140d5a200(0x4f7f);
    FUN_140d59ce0();
}

// @0x140d5a2e0
bool CMeratMarketMan::FUN_140d5a2e0()
{
    return FUN_140d5a1d0() <= FUN_140d5a1b0();
}

// The text of a purchase error.
// @0x140d5a330
CStringW CMeratMarketMan::FUN_140d5a330(int nError, MS2Ptr<CPendingBuyBase> spBuy)
{
    switch (nError) {
    case 0x6a:
        return FUN_14028de60(0x9f0);
    default:
        return FormatStringId(0x9f2, nError);
    case 0x80:
        return FUN_14028de60(0x9ef);
    case 0x87:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_buy_invalid_price_type"));
    case 0x88:
        return FUN_14028de60(0x9e8);
    case 0x89:
        return FUN_14028de60(0x9e9);
    case 0x90:
        return FUN_14028de60(0x9ea);
    case 0x91:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_result_gift_own_product"));
    case 0x92:
        return FUN_14028de60(0x9eb);
    case 0x94:
        return FUN_14028de60(0x9ec);
    case 0x95:
        return FUN_14028de60(0x9ee);
    case 0x97:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_result_buy_change_star_point"));
    case 0x9d:
        return FUN_14028de60(0x9ed);
    case 0x9f:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_result_buy_sold_out_limitedbundle"));
    case 0xa1:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_result_buy_sold_out_changeable"));
    case 0xa2:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_random_payback_not_exist"));
    case 0xa3:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_random_coupon_not_exist"));
    case 0xa4:
    case 0xa5:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_result_gift_cannot"));
    case 0xa6:
        return FUN_14028de60(0xa47);
    case 0xa8:
    case 0xa9:
        return FUN_14028de60(0xa48);
    case 0xab:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_result_buy_ing"));
    case 0xac:
        return FUN_14028de60(0xa0f);
    case 0xad:
        return FUN_14028b8e0(CStringW(L"s_ban_check_err_all_word"));
    case 0xb1:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_result_buy_achieve_complete"));
    case 0xb2:
        return FUN_14028de60(0x9f0);
    case 0xb3:
        return FUN_14028de60(0xa6e);
    case 0xb4: {
        MS2Ptr<CMeratMarketBuy> spMarketBuy(dynamic_cast<CMeratMarketBuy*>(spBuy.get()));
        if (spMarketBuy.get() != 0) {
            MS2Ptr<CMeratMarketProduct> spProduct(spMarketBuy->m_spItem.get());
            if (spProduct.get() != 0 && spProduct->IsPremium())
                return FUN_140ec01e0(&spProduct->m_premium, CStringW(L"s_meratmarket_error_buy_limit_"));
        }
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_buy_limit_level"));
    }
    case 0xb5:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_buy_limit_job"));
    case 0xb6: {
        CStringW strName = FUN_1409eec40(0x5a7);
        return FUN_140a228f0(0x688, *FUN_1402056b0(&FUN_1401d3200()->m_pcBangLevel), strName);
    }
    case 0xb7:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_buy_not_pcbang"));
    case 0xb8:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_buy_low_pcbang_level"));
    case 0xbc:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_buy_shutdown"));
    case 0xbd: {
        int nLevel = FUN_140d564b0();
        return FUN_14062b4f0(CStringW(L"s_meratmarket_error_ugc_buy_limit_achieve_account_char_level"), nLevel);
    }
    case 0xbe: {
        int nLevel = FUN_140d565c0();
        return FUN_14062b4f0(CStringW(L"s_meratmarket_error_ugc_buy_limit_achieve_account_ad_level"), nLevel);
    }
    case 0xbf:
        return FUN_14062b4f0(CStringW(L"s_meratmarket_error_ugc_buy_limit_product_buy_count"), m_n1c0);
    case 0xc3:
        return FUN_14028b8e0(CStringW(L"s_meratmarket_error_country_limit"));
    }
}

// The number of known products.
// @0x140d5b170
int CMeratMarketMan::FUN_140d5b170()
{
    Unk_LockGuard lock(m_lock);
    if (!lock)
        return FUN_1406a50b0(m_products);
    return 0;
}

// Can the product be bought (a UGC product always can)?
// @0x140d5b1f0
bool CMeratMarketMan::FUN_140d5b1f0(MS2Ptr<CMeratMarketProduct> spProduct, bool bShowError)
{
    if (!spProduct->IsPremium())
        return true;
    return FUN_140d5b280(&spProduct->m_premium, bShowError);
}

// Can the premium product be bought (on sale, not sold out, requirements met)?
// @0x140d5b280
bool CMeratMarketMan::FUN_140d5b280(CMeratMarketPremiumProduct* pProduct, bool bShowError)
{
    if (!FUN_140ebff70(pProduct, bShowError))
        return false;
    if (!FUN_140ebfdd0(pProduct, bShowError))
        return false;
    if (!FUN_140ebfe30(pProduct, bShowError))
        return false;
    if (!FUN_140ebfb90(pProduct, bShowError))
        return false;
    bool bResult = true;
    if (pProduct->IsSoldOut() || pProduct->IsNotSelling(0) || pProduct->IsEventPeriod(0)) {
        bResult = false;
        if (bShowError)
            FUN_141275260(0xa17, 1, 1);
    }
    return bResult;
}

// Can the premium product be given as a gift?
// @0x140d5b370
bool CMeratMarketMan::FUN_140d5b370(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (!spProduct->IsPremium())
        return false;
    CMeratMarketPremiumProduct* pProduct = &spProduct->m_premium;
    if (pProduct->m_n124 == 0)
        return false;
    if (!FUN_140ebfdd0(pProduct, false))
        return false;
    if (!FUN_140ebfb90(pProduct, false))
        return false;
    if (!pProduct->IsSoldOut() && !pProduct->IsNotSelling(0) && !pProduct->IsEventPeriod(0))
        return true;
    return false;
}

// The purchase result box closed: a failed premium purchase (0x88) opens the charge page (region 3).
// @0x140d60280
bool CMeratMarketMan::FUN_140d60280(int nResult, const CMsgBoxData& box)
{
    if (m_b2d8 == true && DAT_143ab0248 == 3)
        FUN_140d86260()->vfunc_45();
    return true;
}

// A time plus some days.
// @0x140d61530
__int64 CMeratMarketMan::FUN_140d61530(__int64 nTime, int nDays)
{
    CMsTime time(nTime);
    time += ATL::CTimeSpan(nDays, 0, 0, 0);
    return time.Get();
}

// ---- CMeratMarketBuy ----

// @0x140d602f0
CMeratMarketBuy::CMeratMarketBuy()
{
    m_spPacket = new CMeratMarketPacket::BuyPacket();
}

// @0x140d603c0
CMeratMarketBuy::~CMeratMarketBuy()
{
    m_spPacket = 0;
    m_spBill = 0;
}

// Send the request.
// @0x140d60460
void CMeratMarketBuy::vfunc_4()
{
    CMeratMarketMan::GetInstance()->FUN_140d5a0d0(MS2Ptr<CMeratMarketBuy>(this));
}

// Fill the packet from the product.
// @0x140d60a80
void CMeratMarketBuy::FUN_140d60a80(MS2Ptr<CMeratMarketProduct> spItem, int nBuyType, int nPayType, int nFlag)
{
    if (spItem == 0 || m_spPacket == 0)
        return;
    __int64 nPrice = spItem->GetSalePrice();
    CMeratMarketPacket::BuyPacket* pPacket = m_spPacket.get();
    pPacket->m_nKind = nBuyType;
    pPacket->m_key = spItem->m_key;
    if (spItem.get() != 0 && spItem->IsPremium()) {
        pPacket->m_n30 = 0;
        pPacket->m_n34 = nFlag;
        pPacket->m_b68 = !FUN_140ec05f0(&spItem->m_premium).IsEmpty();
    } else {
        pPacket->m_n34 = nFlag;
        pPacket->m_n38 = 0;
    }
    pPacket->m_n60 = nPrice;
    pPacket->m_n6c = nPayType;
    m_strName = spItem->GetName();
    m_spItem = spItem;
    m_spBill = 0;
    m_nCount = nBuyType;
    m_n30 = nPrice;
}

// @0x140d60d10
void CMeratMarketBuy::FUN_140d60d10(int nValue)
{
    if (m_spPacket == 0)
        return;
    m_spPacket->m_n34 = nValue;
}

// @0x140d60d60
void CMeratMarketBuy::FUN_140d60d60(int nA, int nB)
{
    if (m_spPacket == 0)
        return;
    m_spPacket->m_n40 = nA;
    m_spPacket->m_n44 = nB;
}

// A gift: the receiver and the message.
// @0x140d60dd0
void CMeratMarketBuy::FUN_140d60dd0(const CStringW& strReceiver, const CStringW& strMessage)
{
    if (m_spPacket == 0)
        return;
    m_spPacket->m_n4c = 1;
    m_spPacket->m_str50 = strReceiver;
    m_spPacket->m_str58 = strMessage;
}

// @0x140d60e70
void CMeratMarketBuy::FUN_140d60e70(int nPayType)
{
    m_spPacket->m_n6c = nPayType;
}

// @0x140d60ea0
void CMeratMarketBuy::FUN_140d60ea0(const int& nValue)
{
    if (m_spPacket == 0)
        return;
    m_spPacket->m_n48 = nValue;
}

// The basket line of the bill (-1 without a bill).
// @0x140d60ef0
int CMeratMarketBuy::FUN_140d60ef0()
{
    if (m_spBill.get() == 0)
        return -1;
    return m_spBill->FUN_140d66b00();
}

// The product name (with the chosen option of a premium product).
// @0x140d60f40
CStringW CMeratMarketBuy::vfunc_1()
{
    CMeratMarketPremiumProduct* pPremium = 0;
    if (m_nCount == 4 && m_spBill.get() != 0) {
        MS2Ptr<CMeratMarketPremiumProduct> spPremium = m_spBill->FUN_140d66da0();
        pPremium = spPremium.get();
    } else if (m_spItem.get() != 0 && m_spItem->IsPremium()) {
        pPremium = &m_spItem->m_premium;
    }
    if (pPremium != 0 && m_spPacket.get() != 0) {
        CStringW strOption = FUN_140ebd520(pPremium, m_spPacket->m_n30);
        if (!strOption.IsEmpty())
            return FUN_1408f71a0(CStringW(L"s_meratmarket_buy_itemname"), m_strName, strOption);
    }
    return m_strName;
}

// A gift purchase.
// @0x140d61190
bool CMeratMarketBuy::vfunc_5()
{
    if (m_spPacket.get() == 0)
        return false;
    return m_spPacket->m_n4c == 1;
}

// The pay type.
// @0x140d611f0
int CMeratMarketBuy::vfunc_3()
{
    if (m_spPacket.get() != 0)
        return m_spPacket->m_n6c;
    if (m_spItem.get() != 0)
        return CPendingBuyBase::vfunc_3();
    if (m_spBill.get() != 0 && m_nCount == 4) {
        MS2Ptr<CMeratMarketPremiumProduct> spPremium = m_spBill->FUN_140d66da0();
        if (spPremium.get() != 0)
            return spPremium->FUN_1406a0230();
    }
    return 3;
}

// ---- CMeratMarketBasket ----

// @0x140d61300
CMeratMarketBasket::CMeratMarketBasket()
{
    m_n28 = 0;
    m_n30 = 0;
    m_b34 = false;
}

// @0x140d61380
CMeratMarketBasket::~CMeratMarketBasket()
{
    m_spProduct = 0;
}

// @0x140d613e0
Unk_MeratProductKey CMeratMarketBasket::FUN_140d613e0()
{
    if (m_spProduct == 0)
        return Unk_MeratProductKey();
    return m_spProduct->m_key;
}

// Take the product and the counts of a bill.
// @0x140d61450
void CMeratMarketBasket::FUN_140d61450(MS2Ptr<ASMeratMarketBuyBillData> spBill)
{
    if (spBill == 0)
        return;
    m_spProduct = spBill->FUN_140a8e4e0();
    m_n28 = spBill->FUN_140d66b10();
    m_n30 = spBill->FUN_1409acb50();
}

// ---- CPendingBuyBase ----

// @0x140d64be0
CPendingBuyBase::CPendingBuyBase()
{
    m_nState = 1;
    m_nCount = 0;
    m_n30 = 0;
}

// @0x140d65230
CPendingBuyBase::~CPendingBuyBase()
{
    m_spItem = 0;
}

// @0x140d66ba0
CStringW CPendingBuyBase::vfunc_1()
{
    if (m_spItem.get() == 0)
        return CStringW(L"");
    return m_spItem->GetName();
}

// @0x140d66e40
__int64 CPendingBuyBase::vfunc_2()
{
    return m_n30;
}

// @0x140d66df0
int CPendingBuyBase::vfunc_3()
{
    if (m_spItem.get() == 0)
        return 3;
    return FUN_14069c3e0(m_spItem->GetPayCurrency());
}

// @0x140d6a430
void CPendingBuyBase::vfunc_4()
{
}

// @0x140d67630
bool CPendingBuyBase::vfunc_5()
{
    return false;
}

// ---- the server answers ----

// 0x65: the main page products (0: the home page, 1..2: a category page).
// @0x140d5bc30
void CMeratMarketMan::FUN_140d5bc30(CInPacket& packet)
{
    unsigned char nPage = packet.vfunc_o8_1();
    unsigned char nValue = packet.vfunc_o8_1();
    if (nPage == 0)
        FUN_140d5bd10(packet);
    else if (nPage != 0 && nPage < 3)
        FUN_140d5c0c0(packet);
    Unk_MmDialog* pDialog = FUN_140bd2c00();
    if (pDialog != 0)
        pDialog->FUN_14130c670(nPage);
}

// The home page: three product groups, then the flagged products.
// @0x140d5bd10
void CMeratMarketMan::FUN_140d5bd10(CInPacket& packet)
{
    FUN_140d57e40();
    FUN_140d5bf40(packet);
    FUN_140d5bf40(packet);
    FUN_140d5bf40(packet);
    unsigned int nUnused = packet.vfunc_o8_1();
    unsigned char nCount = packet.vfunc_o8_1();
    for (int i = 0; i < (int)nCount; i++) {
        if (packet.vfunc_o8_1()) {
            MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
            if (spProduct == 0)
                continue;
            Unk_LockGuard lock(m_lock);
            if (!lock) {
                m_228.Add(spProduct);
                m_1f8.SetAt(spProduct->m_key, spProduct);
            }
        }
    }
}

// A product group of the home page.
// @0x140d5bf40
void CMeratMarketMan::FUN_140d5bf40(CInPacket& packet)
{
    unsigned char nCount = packet.vfunc_o8_1();
    for (int i = 0; i < (int)nCount; i++) {
        Unk_LockGuard lock(m_lock);
        if (!lock) {
            MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
            if (spProduct == 0)
                continue;
            m_228.Add(spProduct);
            m_1f8.SetAt(spProduct->m_key, spProduct);
        }
    }
}

// A category page.
// @0x140d5c0c0
void CMeratMarketMan::FUN_140d5c0c0(CInPacket& packet)
{
    unsigned int nUnused = packet.vfunc_o8_1();
    FUN_140d57e40();
    unsigned char nCount = packet.vfunc_o8_1();
    Unk_MeratProductArray* pList = &m_228;
    Unk_MeratProductMap* pMap = &m_1f8;
    if (pList != 0 && pMap != 0) {
        for (int i = 0; i < (int)nCount; i++) {
            if (packet.vfunc_o8_1()) {
                MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
                if (spProduct == 0)
                    continue;
                Unk_LockGuard lock(m_lock);
                if (!lock) {
                    pList->Add(spProduct);
                    pMap->SetAt(spProduct->m_key, spProduct);
                }
            }
        }
    }
}

// 0x67: the advertised products (premium products only): the ad lists, the level watch and the push dialog.
// @0x140d5c2f0
void CMeratMarketMan::FUN_140d5c2f0(CInPacket& packet)
{
    FUN_140d59ce0();
    unsigned int nCount = packet.vfunc_o8_1();
    bool bPush = FUN_1418ffe80(m_nFlags, 1);
    Unk_MeratProductArray aPush;
    for (int i = 0; i < (int)nCount; i++) {
        unsigned int bHas = packet.vfunc_o8_1();
        if (bHas == 0)
            continue;
        MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
        if (spProduct.get() == 0)
            continue;
        if (spProduct->IsUgc())
            continue;
        FUN_140d59a60(spProduct);
        CMeratMarketPremiumProduct* pPremium = &spProduct->m_premium;
        if (bPush && pPremium->m_n124 == 1) {
            if (CMeratMarketMan::GetInstance()->FUN_140d5b370(spProduct) == true)
                aPush.Add(spProduct);
        }
    }
    if (bPush && !m_270.IsEmpty())
        FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyChangeMyLevel"),
                                       Delegate<void(NotifyObject*)>(this, &CMeratMarketMan::FUN_140d59df0));
    Unk_MmDialog* pDialog;
    if (FUN_1418ffe80(m_nFlags, 2) && (pDialog = FUN_140bd2c00()) != 0)
        pDialog->FUN_14130ce70(m_270.IsEmpty());
    UIAdPushDialog* pAdDialog;
    if (!aPush.IsEmpty() && (pAdDialog = Unk_MmGetDialog<UIAdPushDialog>(0x4f34)) != 0) {
        for (Unk_MeratProductListMap::iterator it = m_lists.begin(); it != m_lists.end(); ++it) {
            TPtrValue<std::list<MS2Ptr<CMeratMarketProduct> > > spList = it->second;
            if (spList == 0)
                continue;
            int nSize = (int)spList->size();
            int nIndex = 0;
            for (std::list<MS2Ptr<CMeratMarketProduct> >::iterator itProduct = spList->begin(); itProduct != spList->end();
                 ++itProduct) {
                MS2Ptr<CMeratMarketProduct> spProduct = *itProduct;
                if (spProduct == 0)
                    continue;
                if (pAdDialog->AddBundle(Unk_MmAdItem(spProduct), nIndex, nSize, false))
                    nIndex++;
            }
        }
        pAdDialog->Refresh(1);
    }
    FUN_1418ffef0(&m_nFlags, m_nFlags);
}

// 0x66: the products of the "new / hot" page (kind 1 or 2 of a UGC product).
// @0x140d5c910
void CMeratMarketMan::FUN_140d5c910(CInPacket& packet)
{
    FUN_140d57e40();
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; i++) {
        if (!packet.vfunc_o8_1())
            continue;
        MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
        if (spProduct.get() == 0)
            continue;
        if (spProduct->m_ugc.m_n1f4 == 1) {
            Unk_LockGuard lock(m_lock);
            if (!lock)
                m_228.Add(spProduct);
        } else if (spProduct->m_ugc.m_n1f4 == 2) {
            Unk_LockGuard lock(m_lock);
            if (!lock)
                m_248.Add(spProduct);
        }
        Unk_LockGuard lock(m_lock);
        if (!lock)
            m_1f8.SetAt(spProduct->m_key, spProduct);
    }
    Unk_MmDialog* pDialog = FUN_140bd2c00();
    if (pDialog != 0)
        pDialog->FUN_14130c670(3);
}

// 0x0b: my UGC products on sale (and the total of their sales).
// @0x140d5cb90
void CMeratMarketMan::FUN_140d5cb90(CInPacket& packet)
{
    m_products.RemoveAll();
    m_n1b0 = packet.vfunc_o8_4();
    m_n1a8 = 0;
    __int64 nLast = 0;
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; i++) {
        if (!packet.vfunc_o8_1())
            continue;
        MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
        if (spProduct.get() != 0) {
            nLast = spProduct->m_ugc.m_n88;
            FUN_140d601c0(spProduct);
            FUN_140d55620(spProduct);
        }
    }
    m_n1a0 = nLast;
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130eaa0();
}

// The earliest sale end of my products on sale (state 2).
// @0x140d601c0
void CMeratMarketMan::FUN_140d601c0(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0 || spProduct->m_ugc.m_n28 != 2)
        return;
    if (m_n1a8 == 0)
        m_n1a8 = spProduct->m_ugc.m_n68;
    else
        m_n1a8 = (std::min)(m_n1a8, spProduct->m_ugc.m_n68);
}

// 0x0c: the UGC sellers (my settlements).
// @0x140d5ce00
void CMeratMarketMan::FUN_140d5ce00(CInPacket& packet)
{
    m_bf8 = false;
    m_ne8 = 0;
    m_sellers.RemoveAll();
    m_nf0 = FUN_140869440();
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; i++) {
        MS2Ptr<CUgcMarketSeller> spSeller(new CUgcMarketSeller());
        spSeller->Read(packet);
        FUN_140d55ce0(spSeller);
    }
    FUN_140d56190();
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130eaf0();
}

// 0x0d: a product was registered.
// @0x140d5cfa0
void CMeratMarketMan::FUN_140d5cfa0(CInPacket& packet)
{
    MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
    if (FUN_140d55620(spProduct)) {
        Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
        if (pDialog != 0)
            pDialog->FUN_14130e2e0(spProduct);
        UIMeratMarketRegisterDialog* pRegister = Unk_MmGetDialog<UIMeratMarketRegisterDialog>(0x4ec5);
        if (pRegister != 0)
            pRegister->FUN_141318aa0(spProduct);
        FUN_141276180(s_designUpload, CString(""));
    }
}

// 0x0e: a product was removed.
// @0x140d5d140
void CMeratMarketMan::FUN_140d5d140(CInPacket& packet)
{
    Unk_MeratProductKey key(0, 0);
    key.Read(packet);
    __int64 nUid = packet.vfunc_o8_4();
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(key);
    if (spProduct == 0)
        return;
    if (spProduct->m_ugc.m_n20 == nUid) {
        FUN_140d55790(key);
        Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
        if (pDialog != 0)
            pDialog->FUN_14130e560(spProduct);
    }
}

// 0x0f: a product was updated.
// @0x140d5d2c0
void CMeratMarketMan::FUN_140d5d2c0(CInPacket& packet)
{
    CMeratMarketProduct product(packet);
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(product.m_key);
    if (spProduct == 0)
        return;
    spProduct->m_ugc.CopyFrom(&product.m_ugc);
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130e790(spProduct);
}

// 0x10: the same as 0x0f.
// @0x140d5d3e0
void CMeratMarketMan::FUN_140d5d3e0(CInPacket& packet)
{
    CMeratMarketProduct product(packet);
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(product.m_key);
    if (spProduct == 0)
        return;
    spProduct->m_ugc.CopyFrom(&product.m_ugc);
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130e790(spProduct);
}

// 0x11: a seller was settled.
// @0x140d5d500
void CMeratMarketMan::FUN_140d5d500(CInPacket& packet)
{
    __int64 nId = packet.vfunc_o8_4();
    int nType = packet.vfunc_o8_3();
    __int64 nAmount = packet.vfunc_o8_4();
    MS2Ptr<CUgcMarketSeller> spSeller = FUN_140d55f40(nId);
    if (spSeller == 0)
        return;
    FUN_140d55e50(spSeller);
    if (nType != 0x3fa)
        return;
    m_ne0 += nAmount;
    if (FUN_140d566d0() == 0)
        return;
    bool bDone = m_sellers.IsEmpty();
    if (!bDone) {
        MS2Ptr<CUgcMarketSeller> spFirst = FUN_140d56000();
        if (spFirst != 0) {
            if (!FUN_140d567a0(spFirst))
                bDone = true;
            else
                FUN_140d54a50(spFirst->m_n18);
        }
    }
    if (bDone)
        FUN_140d56840();
}

// 0x12: a product's sale state changed.
// @0x140d5d760
void CMeratMarketMan::FUN_140d5d760(CInPacket& packet)
{
    Unk_MeratProductKey key(0, 0);
    key.Read(packet);
    __int64 nUid = packet.vfunc_o8_4();
    (void)nUid;
    int nState = packet.vfunc_o8_1();
    int nKind = packet.vfunc_o8_1();
    __int64 nEnd = packet.vfunc_o8_4();
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(key);
    if (spProduct == 0)
        return;
    spProduct->m_ugc.m_n28 = nState;
    spProduct->m_ugc.m_n70 = nKind;
    spProduct->m_ugc.m_n68 = nEnd;
    FUN_140d601c0(spProduct);
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130deb0(spProduct);
    if (FUN_1403ed2b0()->FUN_141adc890(0x4ec5) != 0) {
        UIMeratMarketRegisterDialog* pRegister = Unk_MmGetDialog<UIMeratMarketRegisterDialog>(0x4ec5);
        if (pRegister != 0)
            pRegister->FUN_141318a20(spProduct);
    }
}

// 0x13: the bookmarks.
// @0x140d5da10
void CMeratMarketMan::FUN_140d5da10(CInPacket& packet)
{
    unsigned char nCount = packet.vfunc_o8_1();
    {
        Unk_LockGuard lock(m_lock);
        if (!lock) {
            FUN_140d56c60();
            for (int i = 0; i < (int)nCount; i++) {
                MS2Ptr<CUgcBookMark> spBookMark(new CUgcBookMark());
                spBookMark->Read(packet);
                FUN_140d56a40(spBookMark);
            }
        }
    }
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130ed10();
}

// 0x14: a bookmark was added.
// @0x140d5dba0
void CMeratMarketMan::FUN_140d5dba0(CInPacket& packet)
{
    MS2Ptr<CUgcBookMark> spBookMark(new CUgcBookMark());
    spBookMark->Read(packet);
    if (FUN_140d56db0(spBookMark->m_n20) != 0)
        return;
    FUN_140d56a40(spBookMark);
    FUN_140d56eb0(spBookMark->m_n20, packet);
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130dd00(spBookMark->m_n20);
}

// 0x15: a bookmark was removed.
// @0x140d5dcf0
void CMeratMarketMan::FUN_140d5dcf0(CInPacket& packet)
{
    __int64 nId = packet.vfunc_o8_4();
    if (FUN_140d56db0(nId) == 0)
        return;
    FUN_140d56be0(nId);
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130dd30(nId);
}

// 0x16: a bookmark was updated.
// @0x140d5dd80
void CMeratMarketMan::FUN_140d5dd80(CInPacket& packet)
{
    MS2Ptr<CUgcBookMark> spBookMark(new CUgcBookMark());
    spBookMark->Read(packet);
    if (FUN_140d56db0(spBookMark->m_n20) == 0)
        return;
    FUN_140d56eb0(spBookMark->m_n20, packet);
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130de30(spBookMark->m_n20);
}

// 0x17: the promotion times.
// @0x140d5de90
void CMeratMarketMan::FUN_140d5de90(CInPacket& packet)
{
    __int64 nStart = packet.vfunc_o8_4();
    __int64 nEnd = packet.vfunc_o8_4();
    m_n1b0 = nStart;
    m_n1a0 = nEnd;
    {
        Unk_LockGuard lock(m_lock);
        if (!lock) {
            POSITION pos = m_products.GetHeadPosition();
            while (pos != 0) {
                MS2Ptr<CMeratMarketProduct> spProduct = m_products.GetValueAt(pos);
                if (spProduct.get() != 0)
                    spProduct->m_ugc.m_n88 = nEnd;
                m_products.GetNext(pos);
            }
        }
    }
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130ee60();
}

// 0x18: the sale settings.
// @0x140d5e020
void CMeratMarketMan::FUN_140d5e020(CInPacket& packet)
{
    int nOldDays = m_n1c4;
    m_n1b8 = packet.vfunc_o8_3();
    m_n1bc = packet.vfunc_o8_3();
    m_n1c0 = packet.vfunc_o8_3();
    m_n1c4 = packet.vfunc_o8_3();
    bool bChanged = nOldDays != m_n1c4;
    if (bChanged) {
        FUN_140d566f0(0);
        if (m_bf8) {
            m_bf8 = false;
            FUN_140d56190();
        }
    }
    Unk_MmDialog* pDialog = FUN_140bd2c00();
    if (pDialog != 0)
        pDialog->FUN_14130f430(bChanged);
}

// 0x19: a page of search results.
// @0x140d5e190
void CMeratMarketMan::FUN_140d5e190(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_3();
    int nTotal = packet.vfunc_o8_3();
    int nPage = packet.vfunc_o8_3();
    bool bMore = false;
    if (nPage < 2 || nCount != 0) {
        Unk_LockGuard lock(m_lock);
        if (!lock) {
            m_120.RemoveAll();
            m_100.RemoveAll();
        }
    }
    else {
        nPage--;
        bMore = true;
    }
    int nFirst = ((nPage - 1 < 0 ? 0 : nPage - 1) % 5) * 0x12;
    for (int i = 0; i < nCount; i++) {
        if (packet.vfunc_o8_1() == 0)
            continue;
        MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
        if (spProduct.get() != 0)
            FUN_140d57090(spProduct, m_120, m_100);
    }
    int nEnd = nFirst + 0x11;
    int nLast = nEnd;
    if ((int)m_100.GetCount() - 1 <= nEnd)
        nLast = (int)m_100.GetCount() - 1;
    if (!bMore)
        bMore = nLast < nEnd;
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130d390(nPage, nFirst, nLast, nTotal, bMore);
}

// 0x1a: a page of blueprints.
// @0x140d5e540
void CMeratMarketMan::FUN_140d5e540(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_3();
    int nTotal = packet.vfunc_o8_3();
    unsigned char nPerPage = packet.vfunc_o8_1();
    int nPage = packet.vfunc_o8_3();
    bool bMore = false;
    if (nPage < 2 || nCount != 0) {
        Unk_LockGuard lock(m_lock);
        if (!lock) {
            m_150.RemoveAll();
            m_170.RemoveAll();
        }
    }
    else {
        nPage--;
        bMore = true;
    }
    int nFirst = ((nPage - 1 < 0 ? 0 : nPage - 1) % 5) * (int)nPerPage;
    for (int i = 0; i < nCount; i++) {
        if (packet.vfunc_o8_1() == 0)
            continue;
        MS2Ptr<CMeratMarketProduct> spProduct(new CMeratMarketProduct(packet));
        if (spProduct.get() != 0)
            FUN_140d57090(spProduct, m_170, m_150);
    }
    int nEnd = nFirst - 1 + (int)nPerPage;
    int nLast = nEnd;
    if ((int)m_150.GetCount() - 1 <= nEnd)
        nLast = (int)m_150.GetCount() - 1;
    if (!bMore)
        bMore = nLast < nEnd;
    UIBlueprintMarketDialog* pDialog = Unk_MmGetDialog<UIBlueprintMarketDialog>(UIBlueprintMarketDialog::FUN_140d66e70());
    if (pDialog != 0)
        pDialog->FUN_140bbb440(nPage, nFirst, nLast, nTotal, bMore);
}

// 0x1b: the search failed.
// @0x140d5e930
void CMeratMarketMan::FUN_140d5e930(CInPacket& packet)
{
    Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
    if (pDialog != 0)
        pDialog->FUN_14130f960();
}

// 0x1c: a random coupon pick.
// @0x140d5e970
void CMeratMarketMan::FUN_140d5e970(CInPacket& packet)
{
    int nId = packet.vfunc_o8_3();
    int nSale = packet.vfunc_o8_3();
    int nRate = packet.vfunc_o8_3();
    unsigned char nCount = packet.vfunc_o8_1();
    CMsTime day(packet.vfunc_o8_4());
    Unk_MeratProductKey key(nId, 0);
    MS2Ptr<CMeratMarketProduct> spProduct = CMeratMarketMan::GetInstance()->FUN_140d57150(key, 0);
    if (spProduct == 0)
        return;
    int nType = spProduct->GetType();
    if (nType != 7 && nType != 8)
        return;
    spProduct->m_premium.m_n1ac = nSale;
    spProduct->m_premium.m_n1b0 = nRate;
    spProduct->m_premium.m_n1b4 = nCount;
    spProduct->m_premium.m_randomSaleDay = day;
    UIRandomCoupon* pCoupon = Unk_MmGetDialog<UIRandomCoupon>(0x4f99);
    if (pCoupon == 0)
        return;
    CStringW strDay = spProduct->m_premium.GetSellDayText();
    if (nType == 7) {
        __int64 nValue = spProduct->m_premium.FUN_1406a0270();
        pCoupon->FUN_140bfebf0(spProduct);
        pCoupon->FUN_140bfeb50(1, (int)nValue, nCount, CStringW(strDay));
    }
    else if (nType == 8) {
        pCoupon->FUN_140bfebf0(spProduct);
        pCoupon->FUN_140bfeb50(2, nRate, nCount, CStringW(strDay));
    }
}

// 0x1d: a purchase succeeded.
// @0x140d5ed50
void CMeratMarketMan::FUN_140d5ed50(CInPacket& packet)
{
    CMeratMarketPacket::BuyPacket buy;
    buy.Read(packet);
    Unk_MeratProductKey key = buy.m_key;
    int nBuyCount = packet.vfunc_o8_3();
    int nSoldCount = packet.vfunc_o8_3();
    int nUgc3c = packet.vfunc_o8_3();
    int nUgc40 = packet.vfunc_o8_3();
    __int64 nBookMarkId = buy.m_n38;
    if (buy.m_n40 >= 0 && buy.m_n40 < (int)m_pending.GetCount()) {
        MS2Ptr<CPendingBuyBase> spBuy = m_pending[buy.m_n40];
        if (spBuy.get() != 0) {
            MS2Ptr<CMeratMarketProduct> spProduct = spBuy->m_spItem;
            if (spProduct == 0)
                spProduct = FUN_140d57150(key, nBookMarkId);
            if (spProduct.get() != 0) {
                if (!spProduct->IsUgc()) {
                    CMeratMarketPremiumProduct& premium = spProduct->m_premium;
                    premium.m_nBuyCount = nBuyCount;
                    if (premium.m_nType == 6)
                        premium.m_nHomeSoldCount = nSoldCount;
                    else
                        premium.m_nSoldCount = nSoldCount;
                    if (premium.HasLimit()) {
                        Unk_MmDialog* pDialog = FUN_140bfed50(0x4ec1);
                        if (pDialog != 0)
                            pDialog->FUN_14130ea00(spProduct);
                        UIAdPushDialog* pAdDialog = Unk_MmGetDialog<UIAdPushDialog>(0x4f34);
                        if (pAdDialog != 0)
                            pAdDialog->UpdateBundles(Unk_MmAdItem(spProduct));
                        Unk_MmGameMenu* pMenu = FUN_140938b90(0x4e28);
                        if (pMenu != 0)
                            pMenu->FUN_14193dd50();
                    }
                }
                else {
                    spProduct->m_ugc.m_n3c = nUgc3c;
                    spProduct->m_ugc.m_n40 = nUgc40;
                }
            }
        }
    }
    FUN_140d58810(true, 0, buy.m_n40);
}

// 0x1e: a purchase failed.
// @0x140d5f190
void CMeratMarketMan::FUN_140d5f190(CInPacket& packet)
{
    CMeratMarketPacket::BuyPacket buy;
    buy.Read(packet);
    int nError = packet.vfunc_o8_3();
    FUN_140d58810(false, nError, buy.m_n40);
    FUN_140d5f330(buy, nError);
}

// 0x1f: a bought item changed.
// @0x140d5f250
void CMeratMarketMan::FUN_140d5f250(CInPacket& packet)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(packet.vfunc_o8_4());
    if (spItem.get() != 0) {
        spItem->FUN_140524eb0(packet);
        FUN_140a6a840()->vfunc_3(spItem.get(), 0);
    }
}

// A failed purchase: refresh what shows the product.
// @0x140d5f330
void CMeratMarketMan::FUN_140d5f330(CMeratMarketPacket::BuyPacket& buy, int nError)
{
    Unk_MeratProductKey key = buy.m_key;
    __int64 nBookMarkId = buy.m_n38;
    if (buy.m_n48 == 0) {
        MS2Ptr<CMeratMarketProduct> spProduct = CMeratMarketMan::GetInstance()->FUN_140d57150(key, nBookMarkId);
        if (spProduct == 0)
            return;
        if (!spProduct->IsUgc()) {
            Unk_MmDialog* pDialog;
            if (spProduct->IsPremium() && (pDialog = FUN_140bfed50(0x4ec1)) != 0)
                pDialog->FUN_14130ea00(spProduct);
        }
        else {
            int nState = 0;
            if (nError == 0x6a)
                nState = 3;
            if (nState != 0) {
                spProduct->m_ugc.m_n28 = nState;
                Unk_MmDialog* pDialog = FUN_140bd2c00();
                if (pDialog != 0)
                    pDialog->FUN_14130ea00(spProduct);
                UIBlueprintMarketDialog* pBlueprint =
                    Unk_MmGetDialog<UIBlueprintMarketDialog>(UIBlueprintMarketDialog::FUN_140d66e70());
                if (pBlueprint != 0)
                    pBlueprint->FUN_140bbbc70(spProduct);
            }
        }
    }
    else if (nError == 0x9d && m_n2a8 == 4) {
        Unk_MmShopDialog* pShop = FUN_140534780(0x4e3b);
        if (pShop != 0)
            pShop->FUN_141afb290(key.m_nPremiumId);
    }
}
