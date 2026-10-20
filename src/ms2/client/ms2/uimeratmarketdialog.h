// uimeratmarketdialog.h - UIMeratMarketDialog (RTTI .?AVUIMeratMarketDialog@@, 0x660 bytes, swf "MeratMarketDialog"): the
// merat (premium) market and UGC market window: the shop tabs, the search pages, the seller (my shop) pages, the
// bookmark and basket lists, the banner, and the item preview on the avatar / cube / ridee / pet model views.
// Bases: UIDialog (+0x0, vftable 0x142ee8060; IMessageListener 0x142ee8308 at +0x18), UIStatusEventListener (+0x178,
// 0x142ee8318), IUIAvatarEventListener (+0x180, 0x142ee8420), IAvatarObjectEventListener (+0x188, 0x142ee8448, no
// overrides) and UIUGCEventListener (+0x190, 0x142ee8478). Ctor 0x1412e84b0, dtor 0x1412e8be0 (??_G 0x141315370).
// Owning unit: ?\uimeratmarketdialog.cpp (0x1412e84b0-0x141317690, statics 0x1400ee9d0-0x1400eed20). File name assumed
// from the class name; member and method names are invented from use (many follow the v2525 snapshot's
// UIMeratMarketDialog.h, which has the same layout).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiavatarbase.h"
#include "ms2/client/ms2/uimodelview.h"
#include "ms2/client/ms2/uiskillpreviewdialog.h"       // IUIAvatarEventListener
#include "ms2/client/ms2/shoptabinfo.h"                // ShopBanner
// meratmarketbasketinfo.h models CShopCategoryTable with its own placeholder (cshopcategorytable.h) that clashes with
// commonfiles/shopcategorytable.h (via shoptabinfo.h); its copy is renamed while it is read (as in uishopdialog.cpp).
#define CShopCategoryTable Unk_ShopMeratCategoryView
#include "ms2/commonfiles/meratmarketbasketinfo.h"      // CMeratMarketProduct, Unk_MeratProductKey
#undef CShopCategoryTable
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cmeratmarketschcond.h"
#include "ms2/placeholder/tdirtypremiumsale.h"
#include "ms2/placeholder/uimeratmarketweapontype.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cadbannermanager.h"
#include "ms2/client/ms2/tmarketbilldataparam.h"

class ASArray;
class ASObj;
class TMeratMarketBillDataParam;
class ASButton;
class ASButtonGroup;
class ASData;
class ASDataProvider;
class ASMovieClip;
class ASSlider;
class ASTextField;
class CItem;
class CItemData;
class CMsgBoxData;
class NotifyObject;
class UIEquipIconContainer;
class UIModelView;

class UIRenderView;
class CEquipItem;
class CEquipment;
class CMeratMarketPremiumProduct;
class CUgcMarketSeller;
class ASMeratMarketProduct;
struct Unk_PCEquipSet;
class Unk_MpRideePtr;                                               // uimainplayerinfo.h (the ridee avatar handle)
class Unk_MmSellerShop;
class Unk_MeratBasketEntry;
namespace UIMeratMarketDialogUtil { class ASOutData; class ASClickOutData; }

// The payment map of the market bill and its gift callback (exe RTTI: the strings by const reference; the shared
// TMarketBillDataParam::GiftCallback spells them by value).
typedef ATL::CAtlMap<ePayType, __int64> Unk_MmPayMap;
typedef Delegate<bool(MS2Ptr<TMarketBillDataParam>, const Unk_MmPayMap&, const CStringW&, const CStringW&)> Unk_MmGiftCallback;

// A list of market products (the CMeratMarketMan product lists).
typedef ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> > Unk_MmProductArray;

// The view options of a product row (an Unk_MeratViewOpt, 0x18 bytes): the debug flag and the weapon filter. Built
// from a copy of m_spWeaponType.
class Unk_MmViewScope
{
public:
    Unk_MmViewScope();                                                      // 0x140bbf8a0
    Unk_MmViewScope(MS2Ptr<UIMeratMarketCommon::WeaponType> spWeapon);      // 0x140bbf850
    ~Unk_MmViewScope();                                                     // 0x140bbfe60
    void Set(MS2Ptr<UIMeratMarketCommon::WeaponType> spWeapon);             // 0x141315d90
private:
    bool m_bDebug;                                                          // +0x0
    MS2Ptr<UIMeratMarketCommon::WeaponType> m_spFilter;                     // +0x8
};
MS2_CHECK_SIZE(Unk_MmViewScope, 0x18);

class UIMeratMarketDialog : public UIDialog,
                            public UIStatusEventListener,
                            public IUIAvatarEventListener,
                            public IAvatarObjectEventListener,
                            public UIUGCEventListener
{
public:
    // The pending search state of the dirty set (RTTI .?AVTDirtySearch@UIMeratMarketDialog@@, 0x20).
    class TDirtySearch : public CPtred
    {
    public:
        TDirtySearch();                                             // 0x141314330
        // implicit virtual dtor 0x141314870 (??_G 0x141315320)
        void Reset();                                               // 0x141315570
        void Set(int nType, bool bSet);                             // 0x141315d60

        int m_nType;                                                // +0x18
        bool m_bSet;                                                // +0x1c
    };

    // What Update() has to refresh (+0x2b8): the premium sale ids, the search request and the flag bits.
    struct DirtyState
    {
        DirtyState();                                               // 0x1413142a0
        ~DirtyState();                                              // 0x141314810
        void Reset();                                               // 0x141315540
        void UnsetFlag(unsigned nFlag);                             // 0x141315610
        void ClearPremiumSale();                                    // 0x141315640
        TDirtySearch* GetSearch();                                  // 0x1413159d0
        int GetSearchType();                                        // 0x1413159e0 m_search.m_nType
        bool HasFlag(unsigned nFlag);                               // 0x141315de0
        bool HasSearch();                                           // 0x141315ef0 m_search.m_bSet
        void SetFlag(unsigned nFlag);                               // 0x141316280
        void AddPremiumSale(const int& nId);                        // 0x1413162a0

        MS2Ptr<UIMeratMarketCommon::TDirtyPremiumSale> m_spSale;    // +0x0
        TDirtySearch m_search;                                      // +0x10
        unsigned m_nFlags;                                          // +0x30
    };

    // The previewed product (+0x338): a kind and the product key.
    struct ModelRef
    {
        ModelRef();                                                 // 0x141314260
        void Reset();                                               // 0x141315500
        int IndexOf(Unk_MeratProductKey key);                       // 0x141315970 the preview slot of a product

        int m_nKind;                                                // +0x0
        Unk_MeratProductKey m_key;                                  // +0x8
        int m_nIndex;                                               // +0x18 -1
    };

    // The last search query (+0x4a8).
    struct SearchQuery
    {
        SearchQuery();                                              // 0x141314380
        ~SearchQuery();                                             // 0x141314890
        void Clear();                                               // 0x141315590

        bool IsActive();                                            // 0x141315f60
        int m_nCategory;                                            // +0x0
        ATL::CAtlArray<CStringA> m_8;                               // +0x8
        CStringA m_strSort;                                         // +0x28
        int m_30;                                                   // +0x30
        CStringW m_strText;                                         // +0x38
        int m_40;                                                   // +0x40 5
        int m_44;                                                   // +0x44
        bool m_48;                                                  // +0x48
    };

    UIMeratMarketDialog();                                          // 0x1412e84b0
    virtual ~UIMeratMarketDialog();                                 //  0 0x1412e8be0 (??_G 0x141315370)
    virtual CString vfunc_1();                                      //  1 0x1412e9150 "MeratMarketDialog"
    virtual void OnLoadInit();                                      // 20 0x1412e91a0 read the merat banners
    virtual void OnLoadComplete();                                  // 22 0x1412e9210 bind the movie children and pages
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1412ea0e0 the AS commands
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x1412ec1e0 "getTooltip"
    virtual int vfunc_48() { return 0x4ec1; }                       // 48 0x141315a60 the UI type id

    void ApplyBanners(Unk_AdBannerArray& banners);                  // 0x1412ee610
    void ClearTabCounts();                                          // 0x1412f7760
    void ResetPreview();                                            // 0x1412f7f10
    void ResetModels();                                             // 0x1412f8190
    void OnChangeEnableFeature(NotifyObject* pNotify);              // 0x14130be10
    int BuildSellerRow(ASObj& row, MS2Ptr<Unk_MmSellerShop> spShop, const CStringW& strTooltipKey);   // 0x1412ef960
    int BuildQuery(ASObj& data, SearchQuery& query);                // 0x1412efc30
    void ShowUgcTerms(int nParam, int nKind);                       // 0x1412ee460
    void OpenBannerProduct(const CStringA& strBanner);              // 0x1412ee920
    void OpenBannerSeller(const CStringA& strBanner);               // 0x1412eeaa0
    void OpenBannerSearch(const CStringA& strBanner);               // 0x1412eebe0
    bool IsCurrentShopTab();                                        // 0x1412eeee0
    void OpenProductByKey(Unk_MeratProductKey key, bool bShop);      // 0x1412f0720
    void OpenProduct(MS2Ptr<CMeratMarketProduct> spProduct);        // 0x1412f07e0
    void RunQuery();                                                // 0x141308de0 foreign
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 0x1412eb7c0 the preview view was attached
    virtual void vfunc_15();                                        // 15 0x1412eb2c0 per frame: the dirty set
    void ApplyPremiumSale();                                        // 0x14130f490 rebuild the shop tabs whose sale changed
    void OnProductStateChanged(MS2Ptr<CMeratMarketProduct> spProduct);   // 0x14130deb0 a product of my shop changed its sale state
    virtual int vfunc_65();                                         // 65 0x1412ec7d0 Open
    virtual void vfunc_67();                                        // 67 0x1412ec8d0 Close
    virtual int vfunc_o178_0(void* pAvatar);                        // IUIAvatarEventListener 0 0x1412ed070 the preview avatar loaded
    virtual int vfunc_o178_1(void* pAvatar);                        // IUIAvatarEventListener 1 0x1412ed2b0
    virtual int vfunc_o178_2(void* pAvatar);                        // IUIAvatarEventListener 2 0x1412ed200
    virtual int vfunc_o178_3(void* pAvatar);                        // IUIAvatarEventListener 3 0x1412ed340
    virtual void vfunc_ugc_1(void* pId, CString strPath);           // UIUGCEventListener 1 0x1412ed430 a profile image arrived
    virtual void vfunc_ugc_3(void* pCallBack, void* pstrPath);      // UIUGCEventListener 3 0x1412ed650 a product icon arrived (const CStringA*)
    void RefreshAvatarOwner(UIAvatarBase* pAvatar, MS2Ptr<CItem> spOwner);   // 0x1412efdb0
    void Refresh7710(bool b);                                       // 0x141307710 foreign
    void EquipPreview(UIAvatarBase* pAvatar, MS2Ptr<CItemData> spData, bool bA, bool bB);   // 0x141308540 foreign
    virtual int vfunc_13();                                         // 13 0x1412e9f10 Enter / Tab in the page
    virtual void vfunc_16();                                        // 16 0x1412eba20
    virtual bool vfunc_17();                                        // 17 0x1412eba50
    virtual void vfunc_26();                                        // 26 0x1412eba90 drop the movie children
    virtual int vfunc_46();                                         // 46 0x1412ebb90 bind "m_probInfo"
    virtual void vfunc_72();                                        // 72 0x1412eb730 per frame
    virtual int vfunc_73();                                         // 73 0x1412ece80 may open
    virtual void vfunc_79(void* p);                                 // 79 0x1412ecee0
    virtual void vfunc_oa0_14(void* a1, int a2);                    // UIStatusEventListener 14 0x1412ecf10 blue merat
    virtual void vfunc_oa0_15(void* a1, int a2);                    // UIStatusEventListener 15 0x1412ecfc0 red merat
    void PreviewBundle(MS2Ptr<CMeratMarketProduct> spProduct);                                                  // 0x1412f1180
    void PreviewCubeProduct(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                   // 0x1412f1cd0
    void PreviewEquipProduct(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                  // 0x1412f2210
    void PreviewBoxProduct(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                    // 0x1412f29f0
    void PreviewProductItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                   // 0x1412f3750
    void ShowLapenshardItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                   // 0x1412f38a0
    void ShowRideeItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                        // 0x1412f3cd0
    void ApplyProductItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                     // 0x1412f4060
    void ShowPetItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                          // 0x1412f44b0
    void ShowFurnitureItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                    // 0x1412f4840
    void ShowBlueprintItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                    // 0x1412f4c70
    void ShowKind5Item(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                        // 0x1412f50a0
    void ShowKind6Item(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData);                        // 0x1412f5540
    Unk_MpRideePtr CreateRideeAvatar(MS2Ptr<CItemData> spData);                                                 // 0x1412f59e0
    MS2Ptr<UIAvatarPC> CreateCubeAvatar(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem);                        // 0x1412f5be0
    MS2Ptr<UIAvatarPet> CreatePetAvatar(MS2Ptr<CItemData> spData);                                              // 0x1412f5e10
    MS2Ptr<UIAvatarPC> CreateLapenshardAvatar(MS2Ptr<CItemData> spData);                                        // 0x1412f6010
    MS2Ptr<UIAvatarPC> CreateBlueprintAvatar(MS2Ptr<CItemData> spData);                                         // 0x1412f62b0
    MS2Ptr<UIAvatarPC> CreateKind5Avatar(MS2Ptr<CItemData> spData);                                             // 0x1412f6540
    MS2Ptr<UIAvatarPC> CreateKind6Avatar(MS2Ptr<CItemData> spData);                                             // 0x1412f6780
    MS2Ptr<UIAvatarPC> CreateFurnitureAvatar(MS2Ptr<CItemData> spData);                                         // 0x1412f6970
    void ShowAvatarItem(UIAvatarBase* pAvatar, int nKind, MS2Ptr<CItemData> spData, bool bChanged);             // 0x1412f6c00
    UIAvatarBase* CreateItemAvatar(MS2Ptr<CItemData> spData);                                                   // 0x1412f6ec0
    UIAvatarBase* CreatePreviewAvatar(MS2Ptr<CItemData> spData);                                                // 0x1412f7040
    void SplitEquipItems(MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >& arrFirst,
                         ATL::CAtlArray<MS2Ptr<CItemData> >& arrSecond, ATL::CAtlArray<MS2Ptr<CItemData> >& arrThird);   // 0x1412f7590
    void LoadRenderTarget();                                                                                    // 0x1412f7690
    void UnloadRenderTarget();                                                                                  // 0x1412f76f0
    void ClearLists();                                                                                          // 0x1412f77b0
    bool ShowEquipIcons(UIAvatarBase* pAvatar, int nSlot, bool bClear);                                         // 0x1412f7800
    bool EquipPackageIcon(UIAvatarBase* pAvatar, int nSlot, int nIcon);                                         // 0x1412f7bc0
    bool OnAvatarEquipChanged(const int* pItemId, bool* pChanged, bool* pFlag1, bool* pFlag2);                  // 0x1412f7f90
    void SplitPackageItems(const CMeratMarketPremiumProduct& premium, ATL::CAtlArray<MS2Ptr<CItemData> >& arrFirst,
                           ATL::CAtlArray<MS2Ptr<CItemData> >& arrSecond);                                      // 0x1412f73d0
    // foreign (other fragments)
    void SetSlotKind(int nKind);                                                                                // 0x141308440 foreign
    void AddPreviewSlot(MS2Ptr<CItem> spItem, MS2Ptr<CMeratMarketProduct> spProduct, int nEvent, int nIndex,
                        int nSlotKind, MS2Ptr<CItemData> spData);                                               // 0x1412efee0 foreign
    void InitAvatars();                                             // 0x1412f81e0
    bool SetPreview(int nIndex, MS2Ptr<UIAvatarBase> spPreview);    // 0x1412f9130
    void RequestLists();                                            // 0x1412f91c0
    void InitPreview();                                             // 0x1412f9270
    void SetPreviewItem(MS2Ptr<CItem> spOwner, MS2Ptr<CItemData> spData, int nSlot, int nKind, MS2Ptr<CMeratMarketProduct> spProduct);   // 0x1412f9320
    bool OnChangeList(ASData& data, bool bRefresh);                 // 0x1412f9490
    bool CheckMarketAccess(__int64 nSellerId);                      // 0x1412f9650
    void OnClickRefreshBlueMerat();                                 // 0x1412f97d0
    void OnClickRefreshRedMerat();                                  // 0x1412f98b0
    void SendRandomSaleRequest(MS2Ptr<CMeratMarketProduct> spProduct);   // 0x1412f9990
    bool RefreshSellerList();                                       // 0x1412f9d10
    int FillPage(int nFirst, int nLast, ASArray& rows, Unk_MmProductArray& list, Unk_MmViewScope* pScope);   // 0x1412f9fe0
    int FillProducts(ASArray& rows, Unk_MmProductArray& list, Unk_MmViewScope* pScope);   // 0x1412fa200
    int FillBannerProducts(const int& nType, ASArray& rows, Unk_MmProductArray& list, const Unk_MmViewScope* pScope);   // 0x1412fa370
    void BuildPage(int nFirst, int nLast);                          // 0x1412fa7b0
    void ShowSellerShop(__int64 nSellerId, int bForce);             // 0x1412fa950
    void ShowSeller(__int64 nSellerId, const CStringW& strName, int bForce);   // 0x1412fac20
    void BuildSellerList(ASArray& rows);                            // 0x1412fb410
    void AddTab(ASArray& tabs, const CStringA& strName, const CStringW& strLabel, const CStringA& strTooltip, const CStringA& strPageCls, int nIndex, const CStringA& strClsName);   // 0x1412fb590
    void AddEventTab(ASArray& tabs);                                // 0x1412fb7e0
    void AddSearchItem(ASDataProvider& provider, const CStringW& strLabel, int nTab);   // 0x1412fb930
    void AddJobItem(ASArray& list, const CStringW& strLabel, int nJob);   // 0x1412fba20
    void BuildTabs(ASArray& tabs);                                  // 0x1412fbb10
    void BuildSearchProvider(ASDataProvider& provider);             // 0x1412fcda0
    void BuildJobList(ASArray& list, int nSelectedJob, int& nSelectedIndex);   // 0x1412fcee0
    void SetGenderData(ASObj& data, int nGender);                   // 0x1412fd0c0
    void LoadSearchResult(MS2Ptr<AScript> spScript, int nKind);     // 0x1412fd140
    void OnSearchLoaded(AScript& data);                             // 0x1412fd2e0
    void SetMarketInitData(ASObj& data, int nPremium);              // 0x1412fd310
    void SetGenderSelection(ASObj& data, bool bUseMine, int nGender);   // 0x1412fd340
    void FillJobDropDown(ASObj& data, bool bUseMyJob, int nJob);    // 0x1412fd420
    int OnCommandMyShop(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 0x1412fd530
    int OnCommandBasket(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 0x1412fd9d0
    int OnCommandBookmark(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs); // 0x1412fdcf0
    int OnCommandLimited(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);  // 0x1412fdf10
    void OnChangeTab(ASData& data);                                 // 0x1412fdf30
    void OnChangeModel(ASData& data);                               // 0x1412fe370
    void OnChangePage(ASData& data);                                // 0x1412fe520
    void OnChangePageRequest(ASData& data);                         // 0x1412fe580
    void OnCheckPreviewColoring(ASData& data);                      // 0x1412fe6a0
    void OnSelectItem(ASData& data);                                // 0x1412ff0b0
    void OnGetSearchAttrVisible(ASData& data);                      // 0x1412ff700
    void OnClickShowMyEquip();                                      // 0x1412ff7f0
    void OnClickUnequipAll();                                       // 0x1412ff9a0
    void OnClickBuyMerat();                                         // 0x1412ffb40
    void OnClickRandomSalePick(const CStringA& strName, ASData& data);   // 0x1413000d0
    // foreign (other fragments)
    void OnSelectLimited(UIMeratMarketDialogUtil::ASOutData& out);  // 0x141305e70 foreign
    void OnShowHistory();                                           // 0x141305480 foreign
    void OnBuyBasketItem(const CStringA& strName, ASData& data);    // 0x1413035c0 foreign
    void OnRightClickSeller(ASData& data);                          // 0x141304060 foreign
    void LoadTab(int nTab);                                         // 0x1412ed920 foreign
    void SelectCategory(int nKind, int nCategory);                  // 0x141308d60 foreign
    void RefreshMyShop();                                           // 0x1412eef70 foreign
    void OnModelCheck(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141306ed0 foreign
    void OnModelRefresh(const Scaleform::GFx::FunctionHandler::Params& params); // 0x141306fa0 foreign
    void OnModelReset(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141306ff0 foreign
    void OnBuyProduct(const CStringA& strMovie, UIMeratMarketDialogUtil::ASClickOutData& click);   // 0x141305ce0
    void OnEquipIconTooltip(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141306950
    void ShowBuyBill(const CStringA& strMovie, MS2Ptr<CMeratMarketProduct> spProduct, int nCount);   // 0x1413061b0
    void SetMusicPlayTime(int nStart, int nLength);                 // 0x141307080
    bool StartMusicPreview();                                       // 0x1413070d0
    void StopMusicPreview(bool bApply);                             // 0x141307600
    bool OnBillBuy(MS2Ptr<TMarketBillDataParam> spParam, const Unk_MmPayMap& prices);   // 0x141307f30
    bool OnBillGift(MS2Ptr<TMarketBillDataParam> spParam, const Unk_MmPayMap& prices, const CStringW& strTo,
                    const CStringW& strMessage);                    // 0x141307fc0
    bool OnBillToBasket(MS2Ptr<TMarketBillDataParam> spParam);      // 0x141308070
    bool OnBillTooltip(Scaleform::GFx::Value* pValue, ASData& data, MS2Ptr<TMarketBillDataParam> spParam);   // 0x141308390
    void ApplySearchAll(MS2Ptr<CMeratMarketSchCond> spCond, ASObj& obj, bool bAll);  // 0x141310110
    int FillProductRow(ASMeratMarketProduct& row, MS2Ptr<CMeratMarketProduct> spProduct, Unk_MmViewScope* pScope);   // 0x1412ef330 foreign
    void RefreshSellerInfo();                                       // 0x141305a20
    bool BuildSellerInfo(ASObj& info);                              // 0x141305b40 foreign
    void OnClickCancelSale(ASData& data);                           // 0x141304830
    void OnClickRemoveSale(ASData& data);                           // 0x141304b20
    void OnClickRegisterSale(ASData& data);                         // 0x141304f20
    void OnClickSaleCommand(ASData& data);                          // 0x141305250
    bool OnAskCancelSale(int nButton, const CMsgBoxData& box);      // 0x1413062f0
    bool OnAskRegisterSale(int nButton, const CMsgBoxData& box);    // 0x1413063e0
    bool OnAskRemoveSale(int nButton, const CMsgBoxData& box);      // 0x1413064d0
    bool OnUgcTermsConfirm(int nButton, const CMsgBoxData& box);    // 0x141306850
    void OnModelLoaded(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141306900
    void OnBuySelected(const CStringA& strWho, ASData& data);       // 0x141303b50
    void OnBuyGiftSelected(const CStringA& strWho, ASData& data);   // 0x141303ca0
    void OnRemoveSeller(ASData& data);                              // 0x141303e50
    void OnSellerInfo(ASData& data);                                // 0x141303ec0
    void OnGetSellerProductList(ASData& data);                      // 0x141303ff0
    void BuyItems(MS2Ptr<TMeratMarketBillDataParam> spParam, ASArray& arrItems);   // 0x141303060
    void OnClickExtraButton(ASData& data);                          // 0x1413025a0
    void OnProductMessage(const Scaleform::GFx::FunctionHandler::Params& params);        // 0x1413029f0
    void OnProductMessageHouse(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141302ba0
    void OnModelHouse(const Scaleform::GFx::FunctionHandler::Params& params);            // 0x141302db0
    void ShowModelHouse(MS2Ptr<CMeratMarketProduct> spProduct);     // 0x141302e50
    void OnClickProductLink(ASData& data);                          // 0x1413034c0
    void OnRemoveBasketItem(ASData& data);                          // 0x141303580
    bool OnAskMoveToModelHouse(int nButton, const CMsgBoxData& box);   // 0x1413065c0
    void OnClickBasket(ASData& data);                               // 0x1413019e0
    MS2Ptr<TMeratMarketBillDataParam> CreateBillParam(const CStringA& strMovie, int nType, int nSourceKind);   // 0x141307ac0
    void OnClickBookMark(ASData& data);                             // 0x141301260
    void OnClickRecipe(ASData& data);                               // 0x141301360
    void OnClickPreview(ASData& data);                              // 0x141301710
    void OnClickSearchAll(ASData& data);                            // 0x141301860
    void OnClickBanner(ASData& data);                               // 0x141302490
    void OnClickStarShop();                                         // 0x141302560
    void ApplyAvatarEquip(UIAvatarPC* pAvatar);                     // 0x141308fc0
    bool IsItemChanged(MS2Ptr<CItemData> spItem);                   // 0x141309250
    void SetPreviewControls(ASObj& data, int nKind, MS2Ptr<CMeratMarketProduct> spProduct);   // 0x141309320
    void SetMusicInfo(ASObj& data, MS2Ptr<CMeratMarketProduct> spProduct);                    // 0x141309600
    void SetBlueprintInfo(ASObj& data, MS2Ptr<CMeratMarketProduct> spProduct);                // 0x141309c60
    void ChangeModel(int nSlot, int nKind, MS2Ptr<CMeratMarketProduct> spProduct);            // 0x141308ae0 show a product on a preview model slot
    void LoadSampleScore();                                         // 0x1413077f0 the instrument preview sample score (m_630) and its length (m_62c)
    ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> >& GetProductList(int nCategory);   // 0x141309f20
    MS2Ptr<CMeratMarketProduct> FindProduct(const Unk_MeratProductKey& key, __int64 nId, bool bShop);   // 0x141309f60
    MS2Ptr<CMeratMarketProduct> FindProductInTab(const Unk_MeratProductKey& key, int nTab);         // 0x14130a000
    CStringA TabName(int nTab);                                     // 0x14130a090
    int ShopKindOf(int nTab);                                       // 0x14130a210
    int TabFromName(const CStringW& strName);                       // 0x14130a270
    int TabOfKind(int nKind);                                       // 0x14130a3b0
    MS2Ptr<AScript> GetPage(int nTab);                              // 0x14130a410
    MS2Ptr<AScript> GetPageOfKind(int nKind);                       // 0x14130a5e0
    MS2Ptr<UIEquipIconContainer> GetEquipIcon(int nIndex);          // 0x14130a640
    int CurrencyOf(int nUnused);                                    // 0x14130a6d0
    int GetTabCount(int nTab);                                      // 0x14130a730
    int FindPreview(UIAvatarBase* pPreview);                        // 0x14130a770
    UIAvatarBase* GetPreview(int nIndex);                           // 0x14130a7f0
    UIAvatarBase* GetAvatarForItem(MS2Ptr<CItemData> spData);       // 0x14130a840
    int CurrentListId(int nUnused);                                 // 0x14130ab70
    int DefaultTab();                                               // 0x14130abd0
    int ResolveTab(int nTab);                                       // 0x14130aca0
    int SlotKindOfPreview(UIAvatarBase* pPreview, MS2Ptr<CItemData> spData);   // 0x14130ad20
    int SlotKindOf(int nSlot, MS2Ptr<CItemData> spData);            // 0x14130ada0
    MS2Ptr<CMeratMarketSchCond> GetSearchCondition();               // 0x14130af30
    __int64 CurrentSearchId();                                      // 0x14130b000
    Unk_ShopTabArray* ListOf(int nKind);                            // 0x14130b030
    MS2Ptr<UIAvatarBase> GetPreviewPtr(int nIndex);                 // 0x14130b090
    MS2Ptr<CItemData> PickItem(ATL::CAtlArray<MS2Ptr<CItemData> >& items, bool bFirst);   // 0x14130b120
    bool IsLimitedProduct(CMeratMarketPremiumProduct& product);     // 0x14130b170
    bool HasLimitedTab();                                           // 0x14130b330
    bool HasEventTab();                                             // 0x14130b490
    void ShowHelper(bool bShow);                                    // 0x14130b610
    void GetProductTooltip(Scaleform::GFx::Value& out, MS2Ptr<CMeratMarketProduct> spProduct);   // 0x14130b770
    void OnEquipList(ATL::CAtlList<MS2Ptr<CEquipItem> >* pItems, Unk_PCEquipSet* pEquip); // 0x14130b930
    void OnGameEventChanged(NotifyObject* pNotify);                 // 0x14130b970
    void OnBlindTarget(NotifyObject* pNotify);                      // 0x14130ba70
    void OnUgcDownloadComplete(NotifyObject* pNotify);              // 0x14130bba0
    CMsTime GetOpenTime();                                          // 0x14130bea0
    void SetOpenTime(const CMsTime& time);                          // 0x14130bee0
    void BuildItemList(int nKind);                                  // 0x14130c670
    void UpdateNotice(const CStringW& strNotice);                   // 0x14130c5b0
    void RefreshLimitedTab(bool bSkip);                             // 0x14130ce70
    void SetCollectState(int nId, __int64 nCount);                  // 0x14130d150
    void FUN_14130db60();                                           // 0x14130db60
    void ShowSearchPage(int nPage, int nFrom, int nTo, int nCount, bool bEnd);   // 0x14130d390
    void RequestSellerProducts(__int64 nSeller);                    // 0x14130dd00
    void OnRemoveSellerComplete(__int64 nSeller);                   // 0x14130dd30
    void OnSellerChanged(__int64 nSeller);                          // 0x14130de30
    void OnRegisterItem(MS2Ptr<CMeratMarketProduct> spProduct);     // 0x14130e2e0
    void OnRemoveItem(MS2Ptr<CMeratMarketProduct> spProduct);       // 0x14130e560
    void OnUpdateItem(MS2Ptr<CMeratMarketProduct> spProduct);       // 0x14130e790
    void OnProductSelected(MS2Ptr<CMeratMarketProduct> spProduct);  // 0x14130ea00
    void RefreshMyShopPage();                                       // 0x14130eaa0
    void InitMarketData();                                          // 0x14130eaf0
    void UpdateSellerList();                                        // 0x14130ed10
    void UpdateSaleNotice();                                        // 0x14130ee60
    void AddBasket(MS2Ptr<Unk_MeratBasketEntry> spEntry, int nCount);   // 0x14130f010
    void RemoveBasket(const Unk_MeratProductKey& key, int nCount);  // 0x14130f310
    void OnSellerVisible(bool bVisible);                            // 0x14130f430
    bool RebuildShopTab(int nTab);                                  // 0x14130f720
    void RefreshHome();                                             // 0x14130f960
    void SearchByKey(const CStringA& strKey, bool bExact, const CStringW& strText, int nValue);   // 0x14130f9e0
    void SearchByText(const CStringW& strText);                     // 0x14130fa80
    void SearchByCategory(const int& nTab, const int& nValue);      // 0x14130fb10
    void RequestPending(int nFlag, bool bSet);                      // 0x14130fba0
    bool FillBasketRow(ASMeratMarketProduct& row, MS2Ptr<Unk_MeratBasketEntry> spEntry, int nCount, Unk_MmViewScope* pScope);   // 0x1412ef150 foreign
    void ApplySearch(MS2Ptr<CMeratMarketSchCond> spCond, AScript& data);   // 0x1413107f0
    void ClearSearchRequest();                                      // 0x141310920
    void ClearSearchInput();                                        // 0x141310970
    void OpenBanner(int nKind, const CStringA& strTarget);          // 0x141310d30
    int PreviewColorCode();                                         // 0x141310e10
    void SetModelTime(int nSeconds);                                // 0x141310e50
    bool CheckProduct(MS2Ptr<CMeratMarketProduct> spProduct, int nCount);   // 0x141310f70
    bool FillSearchData(MS2Ptr<CMeratMarketSchCond> spCond, AScript& data, bool bForce);   // 0x14130fc10
    void ApplyPreviewChanges(bool bApply);                          // 0x141310a60
    void ShowSellerProducts(const __int64& nSeller);                // 0x141304270 foreign
    void ShowProduct(MS2Ptr<CMeratMarketProduct> spProduct);        // 0x1412ebc40 foreign
    bool IsPlaceableItem(MS2Ptr<CItemData> spData);                 // 0x14130b670
    int MarkTab(int nTab);                                          // 0x14130b730

    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                                    // +0x198
    efd::SmartPointer<UIRenderView> m_spModelView;                  // +0x1c8 (was UIModelView: the avatar hands out its UIRenderView)
    MS2Ptr<UIAvatarPC> m_spAvatarPC;                                // +0x1d0
    MS2Ptr<UIAvatarPC> m_spMyAvatarPC;                              // +0x1e0
    MS2Ptr<UIAvatarBase> m_spAvatars[5];                            // +0x1f0
    MS2Ptr<UIAvatarBase> m_spAvatar;                                // +0x240
    int m_250;                                                      // +0x250
    int m_254;                                                      // +0x254 -1
    MS2Ptr<CMeratMarketProduct> m_spProduct;                        // +0x258
    MS2Ptr<CItem> m_spItem;                                         // +0x268
    MS2Ptr<CItemData> m_spItemData;                                 // +0x278
    MS2Ptr<CItemData> m_spItemData2;                                // +0x288
    int m_298;                                                      // +0x298 5
    int m_29c;                                                      // +0x29c 7
    __int64 m_2a0;                                                  // +0x2a0
    MS2Ptr<CMeratMarketSchCond> m_spSearch;                         // +0x2a8
    DirtyState m_dirty;                                             // +0x2b8
    bool m_2f0;                                                     // +0x2f0
    bool m_2f1;                                                     // +0x2f1
    bool m_2f2;                                                     // +0x2f2
    bool m_2f3;                                                     // +0x2f3
    int m_tabCounts[9];                                             // +0x2f4
    CStringW m_318[4];                                              // +0x318
    ModelRef m_model;                                               // +0x338
    Unk_ShopTabArray m_tabs100000;                                  // +0x358 the merat shop tabs (shop 100000)
    Unk_ShopTabArray m_tabs100001;                                  // +0x378 shop 100001
    Unk_ShopTabArray m_tabs110000;                                  // +0x398 the UGC market tabs (shop 110000)
    Unk_ModelViewCamera m_camChar;                                  // +0x3b8 the model view presets: character
    Unk_ModelViewCamera m_camCube;                                  // +0x3e8 cube
    Unk_ModelViewCamera m_camPet;                                   // +0x418 pet / ridee
    MS2Ptr<UIMeratMarketCommon::WeaponType> m_spWeaponType;         // +0x448
    CStringA m_458;                                                 // +0x458
    ShopBanner m_banner;                                            // +0x460
    SearchQuery m_query;                                            // +0x4a8
    int m_4f8;                                                      // +0x4f8
    CStringA m_500;                                                 // +0x500
    bool m_bPreviewColoring;                                        // +0x508
    MS2Ptr<ASButtonGroup> m_spTabButtonGroup;                       // +0x510
    MS2Ptr<UIEquipIconContainer> m_spEquipIcons[7];                 // +0x520
    MS2Ptr<ASMovieClip> m_spLayerPage;                              // +0x590
    MS2Ptr<ASTextField> m_5a0;                                      // +0x5a0
    MS2Ptr<ASButton> m_5b0;                                         // +0x5b0
    MS2Ptr<ASButton> m_5c0;                                         // +0x5c0
    MS2Ptr<ASTextField> m_5d0;                                      // +0x5d0
    MS2Ptr<ASSlider> m_spSlider;                                    // +0x5e0
    MS2Ptr<ASMovieClip> m_5f0;                                      // +0x5f0
    MS2Ptr<ASButton> m_600;                                         // +0x600
    MS2Ptr<ASButton> m_spModelHouse;                                // +0x610
    bool m_620;                                                     // +0x620
    int m_624;                                                      // +0x624
    int m_628;                                                      // +0x628
    int m_62c;                                                      // +0x62c
    CStringA m_630;                                                 // +0x630
    bool m_638;                                                     // +0x638
    __int64 m_640;                                                  // +0x640
    CMsTime m_openTime;                                             // +0x648
    bool m_658;                                                     // +0x658
};
MS2_CHECK_SIZE(UIMeratMarketDialog::TDirtySearch, 0x20);
MS2_CHECK_SIZE(UIMeratMarketDialog::DirtyState, 0x38);
MS2_CHECK_SIZE(UIMeratMarketDialog::ModelRef, 0x20);
MS2_CHECK_SIZE(UIMeratMarketDialog::SearchQuery, 0x50);
MS2_CHECK_SIZE(UIMeratMarketDialog, 0x660);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_lock, 0x198);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_spSearch, 0x2a8);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_dirty, 0x2b8);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_tabCounts, 0x2f4);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_model, 0x338);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_camChar, 0x3b8);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_banner, 0x460);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_query, 0x4a8);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_spTabButtonGroup, 0x510);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_spLayerPage, 0x590);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_620, 0x620);
MS2_CHECK_OFFSET(UIMeratMarketDialog, m_openTime, 0x648);
