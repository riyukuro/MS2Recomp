// uishopdialog.h - UIShopDialog (RTTI .?AVUIShopDialog@@, 0x348 bytes, UI id 0x4e3b, swf "ShopDialog"): the NPC shop
// window. One dialog serves the normal, wandering-merchant (1), star point (2), PSSB (3) and gacha coin (4) shops
// (m_nShopType): the product tabs (normal, repurchase, new), the merat market items of the star shop, the reset button,
// item preview on the avatar and the buy / sell / repurchase requests (packet 0x51). Owning unit: ?\uishopdialog.cpp
// (dir client\ms2; 0x141af2110-0x141b0cc00, statics 0x14011d540-0x14011d8d0). Header name assumed from the unit path;
// member and method names are invented (most follow the v2525 snapshot's UIShopDialog.h, which has the same layout).
//
// Bases: UIDialog (+0x0, vftable 0x142fe5438, IMessageListener 0x142fe56e0 at +0x18), UIStatusEventListener at +0x178
// (vftable 0x142fe56f0), IUIAvatarEventListener at +0x180 (vftable 0x142fe57f8). Ctor 0x141af2420, dtor 0x141af2990
// (??_G 0x141b0a130).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tdirtypremiumsale.h"
#include "ms2/client/ms2/uiskillpreviewdialog.h"        // IUIAvatarEventListener
#include "ms2/client/ms2/tmarketbilldataparam.h"

class ASData;
class ASDataProvider;
class ASLabel;
class ASMovieClip;
class ASTextField;
class CInPacket;
class CItem;
class CMsgBoxData;
class CNpcShopGivePointContextBase;
class CNpcShopMeratItemCli;
class CNpcShopProductBase;
class CNpcShopProductCli;
class CNpcShopProductNewCli;
class ItemPreview;
class NotifyObject;
class ShopTabInfo;
class UIEquipIconContainer;
namespace Scaleform { namespace GFx { class Value; } }

class UIShopDialog : public UIDialog, public UIStatusEventListener, public IUIAvatarEventListener
{
public:
    // The selected product of a pending purchase (+0x1b0; reset when the server answers).
    struct Selection
    {
        Selection();                                                // 0x141af2340
        void Reset();                                               // 0x141af2380
        void ResetIf(int nSecondary);                               // 0x141af23b0 Reset() when m_nSecondary matches
        void Set(int nKind, int nIndex, int nSecondary);            // 0x141af23e0

        int m_nKind;                                                // +0x0
        int m_nIndex;                                               // +0x4 -1
        int m_nSecondary;                                           // +0x8 -1
    };

    // What Update() has to refresh (+0x330): flag bits and the premium sale ids.
    struct DirtyState
    {
        DirtyState();                                               // 0x141af2110
        void AddSale(const int& nId);                               // 0x141af2150 bit 1 + the id
        void ClearSale();                                           // 0x141af2220
        bool Has(const unsigned& nBit);                             // 0x141af2260
        void Clear(const unsigned& nBit);                           // 0x141af2290
        void Set(const unsigned& nBit);                             // 0x141af22d0
        void Reset();                                               // 0x141af2310

        MS2Ptr<UIMeratMarketCommon::TDirtyPremiumSale> m_spSale;    // +0x0
        unsigned m_nFlags;                                          // +0x10
    };

    typedef TMarketBillDataParam::PaymentMap PaymentMap;

    UIShopDialog();                                                 // 0x141af2420
    virtual ~UIShopDialog();                                        //  0 0x141af2990 (??_G 0x141b0a130)
    virtual CString vfunc_1();                                      //  1 0x141af2be0 the movie name of the shop type
    virtual int vfunc_13();                                         // 13 0x141af7b00 Enter in the search box
    virtual void vfunc_16();                                        // 16 0x141af8000
    virtual bool vfunc_17();                                        // 17 0x141af8030
    virtual void vfunc_18();                                        // 18 0x141af7cc0
    virtual void OnLoadComplete();                                  // 22 0x141af3820
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 0x141af8070 avatar events
    virtual void vfunc_26();                                        // 26 0x141af7d00
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x141af5730 OnChangeTab / OnBuyItem / ...
    virtual int vfunc_46();                                         // 46 0x141af7de0
    virtual int vfunc_48() { return 0x4e3b; }                       // 48 0x141b0a2a0
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x141af6b10 tooltips
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x141af5020
    virtual int vfunc_52();                                         // 52 0x141af7dc0 returns 1
    virtual int vfunc_65();                                         // 65 0x141af2c30 Open
    virtual void vfunc_66();                                        // 66 0x141af2cb0 place beside the inventory
    virtual void vfunc_67();                                        // 67 0x141af2e90 Close: leaves the shop
    virtual void vfunc_72();                                        // 72 0x141af3460 the per-frame refresh
    virtual void vfunc_80(void* pReply);                            // 80 0x141af6920 the search check answer
    virtual void vfunc_oa0_7(int a1, CStringW s);                   // UIStatusEventListener 7 0x141af37f0 (empty)
    virtual void vfunc_oa0_9(unsigned short a1);                    // UIStatusEventListener 9 0x141af37d0 (empty)
    virtual int vfunc_o178_1(void* pAvatar);                        // IUIAvatarEventListener 1 0x141af7e10

    void OnShopPacket(CInPacket& packet);                           // 0x141af8710 packet 0x51
    int ConfirmUgcPurchase(int nButton, const CMsgBoxData& data);   // 0x141af8660
    bool BuyBill(MS2Ptr<TMarketBillDataParam> spBill, const PaymentMap& payments);         // 0x141af82b0
    bool GiftBill(MS2Ptr<TMarketBillDataParam> spBill, const PaymentMap& payments, CStringW strTo, CStringW strMsg);
                                                                    // 0x141af8370
    bool BillTooltip(Scaleform::GFx::Value* pOut, ASData& args, MS2Ptr<TMarketBillDataParam> spBill);   // 0x141af8440
    void ReadShopInfo(CInPacket& packet);                           // 0x141af88d0
    void ReadProducts(CInPacket& packet);                           // 0x141af90f0
    void ReadNewStart(CInPacket& packet);                           // 0x141af9390
    void ReadNewProducts(CInPacket& packet);                        // 0x141af94e0
    void ReadMeratStart(CInPacket& packet);                         // 0x141af9700
    void ReadMeratItems(CInPacket& packet);                         // 0x141af9790
    void ReadProductUpdate(CInPacket& packet);                      // 0x141af98d0
    void ReadResetResult(CInPacket& packet);                        // 0x141af9ad0
    void ReadRepurchaseStart(CInPacket& packet);                    // 0x141af9ce0
    void ReadRepurchaseAdd(CInPacket& packet);                      // 0x141af9d70
    void ReadRepurchaseRemoval(CInPacket& packet);                  // 0x141afa130
    void ReadPurchaseResult(CInPacket& packet);                     // 0x141afa2f0
    void ReadShopError(CInPacket& packet);                          // 0x141afa640
    void UpdateProduct(MS2Ptr<CNpcShopProductCli> spProduct);       // 0x141afaeb0
    void StartMeratItem(MS2Ptr<CNpcShopMeratItemCli> spItem);       // 0x141afb0c0
    void StartMeratItem(int nSerial);                               // 0x141afb290
    void RepurchaseAdded(MS2Ptr<CNpcShopProductCli> spProduct);     // 0x141afb320
    void RemoveRepurchaseProduct(MS2Ptr<CNpcShopProductCli> spProduct);   // 0x141afb4a0
    void Search(CStringW strText);                                  // 0x141afb590
    void SetSortKind(int nKind);                                    // 0x141afb720
    int GetSortKind();                                              // 0x141afb740
    void SetSearchDirty();                                          // 0x141afb760
    bool CanSellItem(MS2Ptr<CItem> spItem);                         // 0x141afb780
    void UpdateGachaCoin();                                         // 0x141afbd10
    void FillTabs(ASDataProvider& tabs);                            // 0x141afbe30
    void RefreshItems(const CStringW& strSearch);                   // 0x141afbfb0
    void FillNewProducts(ASDataProvider& list, const CStringW& strSearch);  // 0x141afc9d0
    void FillTab(ASDataProvider& tabs, int nGroup, const CStringW& strTitle, const CStringW& strTooltip);   // 0x141afd270
    void SetTab(int nGroup, int bShow);                             // 0x141afd380
    void UpdateSerial(__int64 tReset);                              // 0x141afd480
    void RefreshResetPrice();                                       // 0x141afd5d0
    void ChangeTab(ASData& args);                                   // 0x141afd840
    void BuyProduct(int nSerial, unsigned nQuantity);               // 0x141afd8e0
    void BuyMeratItem(int nSerial, unsigned nQuantity, AScript& source);   // 0x141afde70
    void SellItem(const CString& strKey);                           // 0x141afe7f0
    void ResetList();                                               // 0x141afe8b0
    void LinkProduct(int nSerial);                                  // 0x141afe960
    void LinkMeratItem(int nSerial);                                // 0x141afeab0
    void PreviewNormalItem(int nSerial, int bForce);                // 0x141afeb80
    void PreviewMeratItem(int nSerial);                             // 0x141afece0
    void PreviewProduct(int nSerial, int nKind, int bForce);        // 0x141afee80
    void ResetAllProducts();                                        // 0x141afeed0
    void ResetProducts(int nGroup);                                 // 0x141afef10
    void SelectTab(int nGroup, unsigned char bNew);                 // 0x141afef80
    void CloseShop();                                               // 0x141aff000
    bool HasStarEvent();                                            // 0x141aff180
    void RefreshCategories();                                       // 0x141aff1c0
    void AddPreviewIcon(MS2Ptr<CItem> spItem);                      // 0x141aff600
    MS2Ptr<CNpcShopProductBase> FindProduct(int nGroup, int nSerial);   // 0x141affbe0
    MS2Ptr<CNpcShopProductBase> FindCurrentProduct(int nSerial);    // 0x141affce0
    MS2Ptr<CNpcShopMeratItemCli> FindMeratItem(int nSerial);        // 0x141affd40
    int RequestRepurchase(int nSerial);                             // 0x141affeb0
    int SendPurchase(int nSerial, int nQuantity);                   // 0x141b00060
    int PopulateProduct(AScript& data, MS2Ptr<CNpcShopProductCli> spProduct,
                        MS2Ptr<CNpcShopGivePointContextBase> spEvent, void* pPlayer);      // 0x141b00240
    int PopulateMerat(AScript& data, MS2Ptr<CNpcShopMeratItemCli> spItem, void* pPlayer);  // 0x141b01480
    int PopulateNewProduct(AScript& data, MS2Ptr<CNpcShopProductNewCli> spProduct,
                           MS2Ptr<CNpcShopGivePointContextBase> spEvent, void* pPlayer);   // 0x141b01e90
    bool SetProductPoints(AScript& data, MS2Ptr<CNpcShopGivePointContextBase> spEvent,
                          MS2Ptr<CNpcShopProductCli> spProduct);                         // 0x141b02260
    void SetProductBackground(AScript& data, MS2Ptr<CNpcShopProductBase> spProduct,
                              MS2Ptr<CNpcShopGivePointContextBase> spEvent);             // 0x141b02450
    CStringW ProductPriceText(__int64 nPrice, MS2Ptr<CNpcShopProductCli> spProduct);     // 0x141b02640
    void ShowPurchaseBill(MS2Ptr<CNpcShopProductCli> spProduct, unsigned nQuantity);     // 0x141b02770
    bool HasShop();                                                 // 0x141b031c0
    int ConfirmPurchase(int nButton, const CMsgBoxData& data);      // 0x141b03200
    void OnPriceChanged(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b03240
    CStringW GetTalk(int nShop, bool bWelcome);                     // 0x141b03470
    void SetTalk(const CStringW& strText);                          // 0x141b035c0
    void ArrangeInventory();                                        // 0x141b03620
    bool TabsEmpty(int nGroup);                                     // 0x141b036b0
    void UpdateProductList(int nGroup);                             // 0x141b03700
    void RefreshPremium();                                          // 0x141b037a0
    void UpdateMoney();                                             // 0x141b03800
    void ChangedTokenMoney(NotifyObject* pNotify);                  // 0x141b03890
    void GameEventChanged(NotifyObject* pNotify);                   // 0x141b039a0
    void LoadRenderTarget();                                        // 0x141b03b70
    void UnloadRenderTarget();                                      // 0x141b03bd0
    void OnEquipmentTooltip(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b03c30
    void OnEquipmentChanged(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b03d50
    bool CanPreviewItem(MS2Ptr<CItem> spItem);                      // 0x141b03f70
    void PreviewGachaItem(int nSerial);                             // 0x141b04050
    void ShowMyEquip();                                             // 0x141b04410
    void UnequipAll();                                              // 0x141b04490
    void ShowMainItems();                                           // 0x141b04510
    void Unequip(ASData& args);                                     // 0x141b04530
    void CollectPreviewItems(std::vector<MS2Ptr<CItem> >& items);   // 0x141b04680
    unsigned char IsSellOnly() { return m_bSellOnly; }              // 0x141b0a2b0

    MS2_LAYOUT_FRIEND;
    unsigned char m_188;                                            // +0x188
    unsigned char m_189;                                            // +0x189
    unsigned char m_bCheckEnableItems;                              // +0x18a 1: list only the usable items
    unsigned char m_18b;                                            // +0x18b
    unsigned char m_bRepurchaseEmpty;                               // +0x18c
    unsigned char m_bNewComplete;                                   // +0x18d all new products received
    unsigned char m_bReady;                                         // +0x18e the movie is initialized
    int m_nCategory;                                                // +0x190
    int m_nSortKind;                                                // +0x194
    int m_nGroup;                                                   // +0x198 the shown tab group (0 normal, 1 repurchase, 2 new)
    __int64 m_1a0;                                                  // +0x1a0
    CStringW m_strSearch;                                           // +0x1a8
    Selection m_selection;                                          // +0x1b0
    ATL::CAtlArray<MS2Ptr<ShopTabInfo> > m_tabs[3];                 // +0x1c0 the tabs of each group
    std::vector<MS2Ptr<CNpcShopMeratItemCli> > m_meratItems;        // +0x220
    std::map<int, MS2Ptr<CNpcShopProductBase> > m_products[3];      // +0x238 serial -> product of each group
    int m_nNpcId;                                                   // +0x268
    int m_nShopId;                                                  // +0x26c 0: no shop
    CString m_strIcon;                                              // +0x270 the npc image name
    __int64 m_tReset;                                               // +0x278 the next list reset time
    int m_280;                                                      // +0x280
    int m_284;                                                      // +0x284
    int m_288;                                                      // +0x288
    int m_nShopType;                                                // +0x28c 0 normal, 1 wander, 2 star, 3 PSSB, 4 gacha
    unsigned char m_290;                                            // +0x290
    unsigned char m_291;                                            // +0x291
    unsigned char m_bProbInfo;                                      // +0x292
    unsigned char m_bSellOnly;                                      // +0x293
    unsigned char m_bResetEnable;                                   // +0x294 1
    unsigned char m_295;                                            // +0x295
    int m_nResetType;                                               // +0x298 99: never
    int m_29c;                                                      // +0x29c
    int m_2a0;                                                      // +0x2a0 the reset currency
    int m_2a4;                                                      // +0x2a4
    __int64 m_nResetPriceOrg;                                       // +0x2a8
    __int64 m_nResetPrice;                                          // +0x2b0
    unsigned char m_bResetLimited;                                  // +0x2b8
    int m_nResetCount;                                              // +0x2bc
    bool m_bHideReset;                                              // +0x2c0 1
    unsigned char m_bResetByAccount;                                // +0x2c1
    unsigned char m_2c2;                                            // +0x2c2
    unsigned char m_bSearchDirty;                                   // +0x2c3
    int m_2c4;                                                      // +0x2c4
    int m_2c8;                                                      // +0x2c8
    int m_nNewTotal;                                                // +0x2cc the announced number of new products
    MS2Ptr<AScript> m_spShop;                                       // +0x2d0 the "initShop" object
    MS2Ptr<ASTextField> m_spTalk;                                   // +0x2e0 the wandering merchant's talk
    MS2Ptr<ASLabel> m_spMoney;                                      // +0x2f0 "m_money"
    MS2Ptr<ASMovieClip> m_spProbInfo;                               // +0x300 "m_probInfo"
    MS2Ptr<ItemPreview> m_spPreview;                                // +0x310 the gacha preview avatar
    MS2Ptr<UIEquipIconContainer> m_spEquip;                         // +0x320 "m_equipContainer"
    DirtyState m_dirty;                                             // +0x330
};
MS2_CHECK_SIZE(UIShopDialog::Selection, 0xc);
MS2_CHECK_SIZE(UIShopDialog::DirtyState, 0x18);
MS2_CHECK_SIZE(UIShopDialog, 0x348);
MS2_CHECK_OFFSET(UIShopDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIShopDialog, m_nCategory, 0x190);
MS2_CHECK_OFFSET(UIShopDialog, m_1a0, 0x1a0);
MS2_CHECK_OFFSET(UIShopDialog, m_strSearch, 0x1a8);
MS2_CHECK_OFFSET(UIShopDialog, m_selection, 0x1b0);
MS2_CHECK_OFFSET(UIShopDialog, m_tabs, 0x1c0);
MS2_CHECK_OFFSET(UIShopDialog, m_meratItems, 0x220);
MS2_CHECK_OFFSET(UIShopDialog, m_products, 0x238);
MS2_CHECK_OFFSET(UIShopDialog, m_nNpcId, 0x268);
MS2_CHECK_OFFSET(UIShopDialog, m_strIcon, 0x270);
MS2_CHECK_OFFSET(UIShopDialog, m_tReset, 0x278);
MS2_CHECK_OFFSET(UIShopDialog, m_nShopType, 0x28c);
MS2_CHECK_OFFSET(UIShopDialog, m_290, 0x290);
MS2_CHECK_OFFSET(UIShopDialog, m_nResetType, 0x298);
MS2_CHECK_OFFSET(UIShopDialog, m_nResetPriceOrg, 0x2a8);
MS2_CHECK_OFFSET(UIShopDialog, m_bResetLimited, 0x2b8);
MS2_CHECK_OFFSET(UIShopDialog, m_nResetCount, 0x2bc);
MS2_CHECK_OFFSET(UIShopDialog, m_bHideReset, 0x2c0);
MS2_CHECK_OFFSET(UIShopDialog, m_2c4, 0x2c4);
MS2_CHECK_OFFSET(UIShopDialog, m_spShop, 0x2d0);
MS2_CHECK_OFFSET(UIShopDialog, m_spProbInfo, 0x300);
MS2_CHECK_OFFSET(UIShopDialog, m_spPreview, 0x310);
MS2_CHECK_OFFSET(UIShopDialog, m_dirty, 0x330);
