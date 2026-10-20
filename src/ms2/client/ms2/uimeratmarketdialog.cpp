// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The merat / UGC market window (UIMeratMarketDialog).
// MS2-UNIT: ?\uimeratmarketdialog.cpp
// MS2-RANGE: 0x1400ee9d0-0x1400eed20 .text$di
// MS2-RANGE: 0x1412e84b0-0x141317690 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0PEAVUIMeratMarketDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z$0A@@?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@QEAA@AEBQEAVUIMeratMarketDialog@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x1413111d0 ; prop
// MS2-PIN: ??$?0VUIMeratMarketDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIMeratMarketDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x141311210 ; prop
// MS2-PIN: ??0?$MS2Ptr@VUnk_MeratBasketEntry@@@@QEAA@AEBV0@@Z 0x141311780 ; prop
// MS2-PIN: ??$?8PEAVUIMeratMarketDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x1413118a0 ; prop
// MS2-PIN: ??$?8PEAVUIMeratMarketDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x141311910 ; prop
// MS2-PIN: ??$?8PEAVUIMeratMarketDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x141311980 ; prop
// MS2-PIN: ??$forward@AEBQ8UIMeratMarketDialog@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YAAEBQ8UIMeratMarketDialog@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@ZAEBQ81@EAAX0@Z@Z 0x141313520 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVUIMeratMarketDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA?AU?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@AEBQEAVUIMeratMarketDialog@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x141313640 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x141313a80 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBU?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@Z 0x141313ad0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141313b20 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x141313bc0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VUIEquipIconContainer@@@@QEAA@PEAVUIEquipIconContainer@@@Z 0x141314120 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAA@XZ 0x141314540 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAA@XZ 0x141314560 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x141314580 ; prop
// MS2-PIN: ??1?$MS2Ptr@VUIAvatarPet@@@@QEAA@XZ 0x1413146e0 ; prop
// MS2-PIN: ??8?$MS2Ptr@VMeratMarketShopBannerInfo@@@@QEBA_NPEAVMeratMarketShopBannerInfo@@@Z 0x141314e00 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCAvatarPackageEquip@@@@QEBAPEAVCAvatarPackageEquip@@XZ 0x141314e80 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAPEAXI@Z 0x141314fb0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x141314ff0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x141315030 ; prop
// MS2-PIN: ?GetIconMap@UIEquipIconContainer@@QEAAPEAV?$CAtlMap@HV?$MS2Ptr@VASEquipIcon@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VASEquipIcon@@@@@3@@ATL@@XZ 0x1413157e0 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VCMeratMarketSchCond@@@@AEBAXXZ 0x141316360 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VWeaponType@UIMeratMarketCommon@@@@AEBAXPEAX@Z 0x141316550 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VWeaponType@UIMeratMarketCommon@@@@AEAAXXZ 0x141316640 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCMeratMarketProduct@@@@AEAAXPEAX@Z 0x141316800 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141316910 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141316970 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1413169d0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAV?$CAtlList@V?$MS2Ptr@VCEquipItem@@@@V?$CElementTraits@V?$MS2Ptr@VCEquipItem@@@@@ATL@@@ATL@@PEAUUnk_PCEquipSet@@@Z@std@@@?$Delegate@$$A6AXPEAV?$CAtlList@V?$MS2Ptr@VCEquipItem@@@@V?$CElementTraits@V?$MS2Ptr@VCEquipItem@@@@@ATL@@@ATL@@PEAUUnk_PCEquipSet@@@Z@@UEAAXPEAV?$CAtlList@V?$MS2Ptr@VCEquipItem@@@@V?$CElementTraits@V?$MS2Ptr@VCEquipItem@@@@@ATL@@@ATL@@PEAUUnk_PCEquipSet@@@Z 0x141316bb0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141316c20 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x141316c50 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141316c80 ; unique
// MS2-PIN: ??$Call@VUIMeratMarketDialog@@P81@EAAXPEAV?$CAtlList@V?$MS2Ptr@VCEquipItem@@@@V?$CElementTraits@V?$MS2Ptr@VCEquipItem@@@@@ATL@@@ATL@@PEAUUnk_PCEquipSet@@@Z@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAV?$CAtlList@V?$MS2Ptr@VCEquipItem@@@@V?$CElementTraits@V?$MS2Ptr@VCEquipItem@@@@@ATL@@@ATL@@PEAUUnk_PCEquipSet@@@Z@std@@@?$Delegate@$$A6AXPEAV?$CAtlList@V?$MS2Ptr@VCEquipItem@@@@V?$CElementTraits@V?$MS2Ptr@VCEquipItem@@@@@ATL@@@ATL@@PEAUUnk_PCEquipSet@@@Z@@CAXAEAU?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAV?$CAtlList@V?$MS2Ptr@VCEquipItem@@@@V?$CElementTraits@V?$MS2Ptr@VCEquipItem@@@@@ATL@@@ATL@@PEAUUnk_PCEquipSet@@@Z@std@@PEAV?$CAtlList@V?$MS2Ptr@VCEquipItem@@@@V?$CElementTraits@V?$MS2Ptr@VCEquipItem@@@@@ATL@@@ATL@@PEAUUnk_PCEquipSet@@@Z 0x141316eb0 ; unique
// MS2-PIN: ??$Call@VUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x141316fb0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1413172d0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141317330 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMeratMarketDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141317390 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?vfunc_48@UIMeratMarketDialog@@UEAAHXZ 0x141315a60 ; unique
// MS2-GUESS-LOOKALIKES
// File name assumed (the class name). Bodies cross-checked with the v2525 snapshot (tu/1412e8390.cpp); helper names are
// invented. The TU ends with the template glue (delegates, CAtlArray / CAtlMap, MS2Ptr COMDATs).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimeratmarketdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uimeratmarketdialog.h"
#include "ms2/placeholder/asbuttongroup.h"
#include "ms2/placeholder/asslider.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/cadbannermanagercli.h"
#include "ms2/placeholder/cadbannermanager.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "uiequipiconcontainer.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/asmeratmarketproduct.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/asmeratmarketbuybilldata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cinstrumentdatatable.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/client/ms2/avatarcube.h"
#include "ms2/client/ms2/clonecube.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/clonepc.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uimainplayerinfo.h"
#include "ms2/client/ms2/asequipicon.h"
#include "ms2/client/ms2/asclickoutdata.h"
#include "ms2/client/ms2/shopbannerinfo.h"
#include "ms2/client/ms2/uimeratmarketregisterdialog.h"
#include "ms2/client/ms2/uimarketbilldialog.h"
#include "ms2/client/ms2/tmeratmarketbilldataparam.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uiwebbrowser.h"
#include "ms2/client/ms2/paybackmanagerclient.h"
#include "ms2/client/ms2/uigamemenudialog.h"
#include "ms2/client/ms2/notifychangebuff.h"
#include "ms2/client/ms2/ugcmanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- Header statics of the TU (market sort names, state names, an input map, ...); no code of the unit reads them.

// @0x1400ee9d0
static CStringA s_marketSortNames[8] = { "None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd" };
// @0x1400eeaa0
static CStringA s_ugcMarketSortNames[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
// @0x1400eeb60
static CStringA s_strSkill = "skill";
// @0x1400eeb90
static CStringA s_strStun = "stun";
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };   // zero-initialised pointer holder
// @0x1400eebc0
static Unk_1401cd100 s_pointer(NULL);
// @0x1400eebe0
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
// @0x1400eec30
static UICommon::CMyPCKeyInputController s_keyInput;
// @0x1400eec60
static CStringA s_strJobCode = "jobCode";
// @0x1400eec90
static CStringA s_strSortValue = "sortValue";
// @0x1400eecc0
static CStringA s_strTabIndex = "tabIndex";
// @0x1400eecf0
static CStringA s_strDesignUpload = "design_Upload";

NotifySystem* FUN_140939a10();
CAdBannerManagerCli* FUN_1409fb930();

// @0x1412e84b0
UIMeratMarketDialog::UIMeratMarketDialog()
    : m_spModelView(0), m_spAvatarPC(0), m_spMyAvatarPC(0), m_spAvatar(0), m_250(0), m_254(-1), m_spProduct(0),
      m_spItem(0), m_spItemData(0), m_298(5), m_29c(7), m_2a0(0), m_spSearch(0), m_2f0(0), m_2f1(0), m_2f2(0),
      m_2f3(0), m_4f8(0), m_500(""), m_bPreviewColoring(0), m_620(0), m_624(0), m_628(0), m_62c(0), m_638(0), m_640(0),
      m_openTime(0), m_658(0)
{
    m_88 = 1;
    FUN_141924170(1);
    ResetModels();
    FUN_1422dc3b0(1);
    ClearTabCounts();
    FUN_140939a10()->RegisterNotify(L"NotifyChangeEnableFeature",
        Delegate<void(NotifyObject*)>(this, &UIMeratMarketDialog::OnChangeEnableFeature));
}

// @0x1412e8be0
UIMeratMarketDialog::~UIMeratMarketDialog()
{
    m_spModelView = 0;
    m_spAvatarPC = 0;
    m_spMyAvatarPC = 0;
    m_spAvatar = 0;
    m_tabs100000.RemoveAll();
    m_tabs110000.RemoveAll();
    ResetPreview();
    m_spSearch = 0;
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeEnableFeature",
        Delegate<void(NotifyObject*)>(this, &UIMeratMarketDialog::OnChangeEnableFeature));
}

// @0x1412e9150
CString UIMeratMarketDialog::vfunc_1()
{
    return "MeratMarketDialog";
}

// @0x1412e91a0
void UIMeratMarketDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    Unk_AdBannerArray banners;
    if (FUN_1409fb930()->FUN_14096b540(2, banners))
        ApplyBanners(banners);
}

// ---- unit-local stand-ins for the services this dialog calls (only the proven members) ----

class Unk_MeratKeyState { public: bool FUN_14116d9c0(int nKey, int a, int b); };           // 0x1c = Enter, 0xf = Tab
Unk_MeratKeyState* FUN_14025e7c0();
struct Unk_MeratFlagSet { int FUN_1402c4c90(int nFlag); };
struct Unk_MeratConfig { void* m_0; Unk_MeratFlagSet m_flags; };
Unk_MeratConfig* FUN_14025e7b0();
struct Unk_ConfigPaths { char m_pad[0xc8]; CStringA m_strDefaultImage; };    // the config singleton (members not recovered)
Unk_ConfigPaths* FUN_1401d31f0();


// The shop of one seller: the product array is at +0x58.
class Unk_MmSellerShop : public CPtred { public: char m_pad[0x58 - 0x18]; Unk_MmProductArray m_products; };
// A banner of the market (asmeratmarketproduct.h forward declares it).
class Unk_MeratBanner : public CPtred { public: CStringA m_strBackground; };
// The market product record the equip icon data carries: ASMeratMarketEquipData (asequipicon.h) only forward declares
// the pointee as Unk_MeratEquipEntry; it is the CMeratMarketProduct of this dialog.
class Unk_MeratEquipEntry : public CMeratMarketProduct { };
class Unk_MeratFilter : public CPtred { };                                  // the market filter
// A preview entry of the market (the product at +0x18).
class Unk_MeratPreviewEntry : public CPtred
{
public:
    MS2Ptr<CMeratMarketProduct> m_spProduct;                                // +0x18
};
class Unk_MeratBasketEntry : public CPtred { public: MS2Ptr<CMeratMarketProduct> m_spProduct; };   // a basket row: the product at +0x18
class Unk_McBasketList { public: unsigned FUN_140d66b20(); };              // the basket count
struct Unk_MeratOid : public Unk_MeratProductKey { };

// map, the sellers, the product lists, the basket and the requests to the server.
typedef ATL::CRBMap<Unk_MeratProductKey, MS2Ptr<CMeratMarketProduct> > Unk_MmProductMap;
typedef ATL::CRBMap<__int64, MS2Ptr<CUgcMarketSeller> > Unk_MmSellerMap;
class Unk_MeratMarketMan
{
public:
    void FUN_140d5a200(const int& nUiId);
    void FUN_140d54d50(MS2Ptr<CMeratMarketSchCond> spCond);
    void FUN_140d542c0(int nShop, int nType);
    void FUN_140d550c0(MS2Ptr<CMeratMarketSchCond> spCond, int nPage);
    void FUN_140d553a0();
    void FUN_140d54440();
    void FUN_140d54ba0();
    void FUN_140d543c0(int nMode);
    int FUN_140d56db0(__int64 nId);                                         // the product / seller is bookmarked
    void FUN_140d566f0(int n);
    void FUN_140d54ac0();
    void FUN_140d54c00(__int64 nId);                                        // add the bookmark
    void FUN_140d54c70(__int64 nSellerId);                                  // remove a seller from the list
    void FUN_140d54ce0(__int64 nSellerId);                                  // request the product list of a seller
    MS2Ptr<Unk_MmSellerShop> FUN_140d56cc0(__int64 nSellerId);              // the seller's shop (null when unknown)
    void FUN_140d58260(MS2Ptr<CMeratMarketProduct> spProduct, __int64 nSeller);   // add to the basket
    MS2Ptr<Unk_MeratPreviewEntry> FUN_140d57ed0(int nId);                   // the preview entry of a product
    void FUN_140d584c0(int nId);                                            // remove from the basket
    bool FUN_140d5b4c0(MS2Ptr<CMeratMarketProduct> spProduct, bool bLimited);   // the product is on sale
    void FUN_140d54500();                                                   // request the sale restrictions

    char m_pad_00[0x38];
    Unk_MmProductMap m_productMap;                                          // +0x38
    Unk_MmSellerMap m_sellers;                                              // +0x68
    char m_pad_98[0x100 - 0x98];
    Unk_MmProductArray m_shop;                                              // +0x100
    char m_pad_120[0x1d0 - 0x120];
    Unk_McBasketList m_basket;                                              // +0x1d0
    char m_pad_1d1[0x228 - 0x1d1];
    Unk_MmProductArray m_premium;                                           // +0x228
    Unk_MmProductArray m_second;                                            // +0x248
    int m_nFlags;                                                           // +0x268
    int m_pad_26c;
    Unk_MmProductArray m_products;                                          // +0x270
};
MS2_CHECK_OFFSET(Unk_MeratMarketMan, m_products, 0x270);
Unk_MeratMarketMan* FUN_140939a00();
void FUN_140d54700(Unk_MeratMarketMan* pMan, Unk_MeratOid key);              // cancel a sale
void FUN_140d54610(Unk_MeratMarketMan* pMan, Unk_MeratOid key);              // register a sale
void FUN_140d54960(Unk_MeratMarketMan* pMan, Unk_MeratOid key);              // remove a sale
MS2Ptr<CMeratMarketProduct> FUN_140d55800(Unk_MeratMarketMan* pMan, Unk_MeratOid key);   // the product of a key
__int64 FUN_140d56470(void* pMarket);
MS2Ptr<CMeratMarketProduct> FUN_140ec2300(const Unk_MeratProductKey& key, const int& nKind, __int64 nId);

class Unk_MeratCategories { public: bool FUN_1407cb390(bool bForce); };
Unk_MeratCategories* FUN_1406aa4b0();
CMeratMarketPremium* FUN_1406f2370();
class Unk_MeratStatusEvents { public: void FUN_141b0cd90(UIStatusEventListener* pListener); };
Unk_MeratStatusEvents* FUN_140aa6d40();
class Unk_MeratUgcEvents { public: void FUN_141b38c70(UIUGCEventListener* pListener); };
Unk_MeratUgcEvents* FUN_140bc09f0();
class Unk_MeratSound { public: void FUN_140d09cf0(int nBgm); void FUN_140d09d40(int nBgm); };   // play / stop a background track
Unk_MeratSound* FUN_140c8dac0();
struct Unk_MmStrings { CStringW FUN_141811980(int nTable, int nId); };
Unk_MmStrings* FUN_1401a9d70();
class Unk_MmJobTable { public: int FUN_140644bb0(int nJob); };
Unk_MmJobTable* FUN_1401d7a50();
class Unk_MmLogger;
Unk_MmLogger* FUN_140d8ee90();
void FUN_140a1f970(Unk_MmLogger* pLogger, const CStringA& strEvent, const CStringA& strWhat);
class Unk_MmMessageBox { public: void FUN_1419f82b0(const CStringW& strText); };
Unk_MmMessageBox* FUN_14151f890();
class Unk_MeratCubeMap { public: int FUN_1410c3650(); };
Unk_MeratCubeMap* FUN_1409670e0();

// The blocked-action record of the player (1401cb250 dtor, 1401cb3d0 get).
class Unk_MeratBlockPtr
{
public:
    ~Unk_MeratBlockPtr();                                                   // 0x1401cb250
    void* FUN_1401cb3d0() const;
    void* m_00; void* m_08;
};
class Unk_MeratBlockMgr { public: Unk_MeratBlockPtr FUN_140a2f620(int nKind); };
Unk_MeratBlockMgr* FUN_140a6a830();
void FUN_140a2ff20(Unk_MeratBlockPtr* pBlock, int nKind, __int64 n);

// The dialogs of ids 0x4ecb (merat recipe popup) and 0x4ee3 (interior preview).
class ASDialog : public ASDisplayObject { };
class Unk_MeratRecipeDialog : public UIDialog
{
public:
    void FUN_1412db660(int nItemId, float x, float y);
    void FUN_1412db6c0();
};
Unk_MeratRecipeDialog* FUN_1412dd5a0(int nUiId);
class UIInteriorPreviewDialog : public UIDialog { public: void FUN_140f4cd90(int nItemId); };
UIInteriorPreviewDialog* FUN_141312450(int nUiId);

// The chat line sent to the server (same layout as Unk_CommandChat, 0x20 bytes).
struct Unk_MeratChat
{
    Unk_MeratChat();                                                        // 0x140acd570
    ~Unk_MeratChat();                                                       // 0x140acd770
    void FUN_1401fa700(COutPacket& packet);
    int m_nState;
    int m_nKind;
    CStringW m_strMessage;
    CStringW m_strTarget;
    __int64 m_nValue;
};
MS2_CHECK_SIZE(Unk_MeratChat, 0x20);

// The owner of the items (account and character ids of the player; 0x20 bytes).
struct Unk_McOwner
{
    void FUN_1409aff60();
    void* m_pAccount;                                                       // the account id
    unsigned m_nType;
    int m_n0c;
    void* m_pCharacter;                                                     // the character id
    void* m_p18;
};
MS2_CHECK_SIZE(Unk_McOwner, 0x20);


// The child lookup of an AS container by name (a COMDAT of this unit; the symbol table names its class Unk_1422baa20).
class Unk_1422baa20 : public AScript
{
public:
    MS2Ptr<AScript> FUN_141311f50(const CString& strName);                  // 0x141311f50
};

// The notification objects with the members this unit reads (the classes live in notifychangebuff.h / ugcmanager.h).
class Unk_BlindTargetNotify : public NotifyBlindTarget
{
public:
    int m_nKind;                                                            // +0x18
    Unk_MeratProductKey m_target;                                           // +0x20 the reported product
};
class Unk_EnableFeatureNotify : public NotifyChangeEnableFeature
{
public:
    int m_nFeature;                                                         // +0x18
};

// ---- free callees ----
CFeatureManager* FUN_140166410();                                           // the feature manager
bool FUN_14036d570(void* pFeatures, int nFeature);                          // a feature is on
CUIService* FUN_1403ed2b0();                                                // the UI manager
void FUN_141adc5d0(void* pUIMgr, int nUiId);                                // hide a dialog
void FUN_141adc530(void* pUI, int nId);
bool FUN_1406a5040(int nType);                                              // the search type is a shop tab
bool FUN_1406a5930();                                                       // the star shop is on
bool FUN_1406a5060(int nCategory);                                          // the category is a plain one
bool FUN_1406a56f0();
bool FUN_1406a5740();
bool FUN_1406a5880();
unsigned FUN_140869420();                                                   // GetTickCountMs2
__int64 FUN_140869440();                                                    // the server time
int FUN_1406516b0();                                                        // the region id
CStringA FUN_140719530(unsigned __int64 n);                                 // an id as text
CStringW FUN_140719a00(__int64 nValue);
unsigned __int64 FUN_140718350(const CString& s);                           // _atoi64
int FUN_1407181a0(const CStringW& str);                                     // text -> int
CStringA FUN_141028a90(CStringA str, int n);                                // a path made absolute
CStringA FUN_1410280d0(int nKind, CStringA strName);
CString FUN_14016a600(const wchar_t* sz, int n);                            // wide -> narrow
CStringW FUN_14016a730(const char* sz, int n);                              // narrow -> wide
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szDelimiter);   // split
CStringW FUN_1409404f0(__int64 n);                                          // a number as text
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1409eec40(int nStringId);
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_141311bb0(const wchar_t* pszFormat, const __int64& nA, const int& nB);
CStringW FUN_141b708a0(int nSeconds, bool b);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& strA, const CStringW& strB);
CStringW FUN_140ec1f20();                                                   // the sale notice text
CStringW FUN_140ec2010();                                                   // the sale notice image path
CommonString* FUN_14025e7d0();
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_1412751b0(const CStringW& strText, int nType);
void FUN_1412751f0(const CStringW& strText, int nA, int nB);
void FUN_1412752d0(const CStringW& key, int type);
MS2Ptr<CMsgBoxData> FUN_140d74500(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);   // a prompt
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> callback);
MS2Ptr<CMsgBoxData> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW text);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                              // show it
void FUN_140d73aa0(CStringW strText, int nType, int nArg, CStringW strTag);
void FUN_140d73bc0(int nStringId, int nType, int nArg, CStringW strTag);
bool FUN_14062c1f0(const MS2Ptr<CMsgBoxData>* pBox, int n);
bool FUN_141900c80(int nButton, const CMsgBoxData& box);
Delegate<bool(int, const CMsgBoxData&)> FUN_140b240b0();
size_t FUN_14016eb40(Unk_AdBannerArray* pArray);                            // the count
Unk_AdBannerPtr& FUN_14103ceb0(Unk_AdBannerArray* pArray, size_t nIndex);   // operator[]
bool FUN_14103bf60(Unk_AdBannerPtr* pPtr, void* pNull);                     // operator==(NULL)
AdBannerData* FUN_14016e5a0(Unk_AdBannerPtr* pPtr);                         // operator->
int FUN_140ec1c70(Unk_ShopTabArray& list, int nCategory);                 // index of the category in the list
void FUN_14134a480(AScript& root, const CString& strName, MS2Ptr<ASButton>* pOut);     // bind a child of the root
bool FUN_141b488c0(MS2Ptr<CItemData> spData);                               // the item may be previewed
bool FUN_141b48710(MS2Ptr<CItemData> spData);
bool FUN_1418bf430(MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pFirst,
                   ATL::CAtlArray<MS2Ptr<CItemData> >* pSecond);           // splits a box item into its items
void FUN_1418bf850(MS2Ptr<CMeratMarketProduct> spProduct, Unk_AvPackageKey* pKey);
void FUN_1418bf850(MS2Ptr<Unk_MeratEquipEntry> spProduct, Unk_AvPackageKey* pKey);
void FUN_1418bf800(int nItemId, Unk_AvPackageKey* pKey);
void FUN_141b48a20(PCBase* pPc, MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pFirst,
                   ATL::CAtlArray<MS2Ptr<CItemData> >* pSecond, ATL::CAtlArray<MS2Ptr<CItemData> >* pThird,
                   MS2Ptr<UIMeratMarketCommon::WeaponType> spFilter);
MS2Ptr<CItemData> FUN_141b49860(ATL::CAtlArray<MS2Ptr<CItemData> >& items, bool bFirst);
MS2Ptr<CItem> FUN_140ebc070(CMeratMarketProduct* pProduct);                 // the item shown for a product
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_141658e60(PC* pPC);
int FUN_141654700(PC* pPC);
void FUN_140222be0(ATL::CAtlArray<int>& jobs);
int FUN_140222b30(int nValue, int nMin);
int FUN_1402227e0(int nValue, int nMin);
void FUN_140ec0700(ASObj* pData, int nPremium);
int FUN_140ebc4a0();
void FUN_140ec1da0(int nList, int nCategory, bool* pbGender, bool* pbJob);  // which filters the category has
IClientPlatform* FUN_140d86260();
bool FUN_1409b0350(Scaleform::GFx::Value* pValue);                          // the value is undefined
bool FUN_1409b0390(Scaleform::GFx::Value* pValue);                          // the value is null
int FUN_1409c1750(const Scaleform::GFx::Value& v);
void FUN_1409ac5e0(ASMeratMarketBuyBillData* pBill, MS2Ptr<Unk_MeratPreviewEntry> spEntry);
void FUN_1413160d0(ASMeratMarketBuyBillData* pBill, int nIndex);
bool FUN_141315f00(ASMeratMarketBuyBillData* pBill);
void FUN_1409ac360(ASMeratMarketBuyBillData* pBill, MS2Ptr<CMeratMarketProduct> spProduct, int n, int nCur);
void FUN_1409b03d0(ASMeratMarketBuyBillData* pBill, __int64 n);
int FUN_1413499b0(int nTab);
UIMeratMarketRegisterDialog* FUN_140d61d50(unsigned nUiId);
void FUN_1413190c0(UIMeratMarketRegisterDialog* pDialog, int n, Unk_MeratProductKey key);
UIMarketBillDialog* FUN_140b09580(int nUiId);
UIWebBrowser* FUN_140c43790(int nUiId);
UIGameMenuDialog* FUN_140938b90(int nId);
int FUN_14069c3e0(int nPayType);
extern int DAT_143ab2914;
extern __int64 DAT_143ab2820;
extern unsigned DAT_143ab2830;
extern __int64 DAT_143ab2838;
extern int DAT_143ab2834;
int FUN_1422b8a10(ASData* pData);
class ItemGachaBoxTable;
ItemGachaBoxTable* FUN_14052d230();
class PaybackManagerClient;
PaybackManagerClient* FUN_1409c1740();
void FUN_140ec0b50(MS2Ptr<CMeratMarketProduct> spProduct);
void FUN_140710590(COutPacket& packet);
bool FUN_140896230(CUgcMarketProduct* pUgc, Unk_McOwner* pOwner);
CInstrumentDataTable* FUN_14052d1d0();
CUgcManager* FUN_14052d220();
extern CStringA g_strMeratLogDefault;                                      // 0x143ad76a8 the empty detail text of the item log
void FUN_141349ae0(MS2Ptr<CItem> spItem, int nLogId, const CStringA& strDetail);
void FUN_141b70f90(const CMsTime& time, const CStringW& strFormat, CStringW& strOut);   // the time as text
CShopEventManager* FUN_1403ed2a0();                                         // TSingleton<CShopEventManager>::GetInstance
bool FUN_140ebc630(MS2Ptr<CMeratMarketProduct> spProduct, int nCount);      // the product can be bought
void FUN_141b706a0(int nMs, int* pHour, int* pMin, int* pSec);
void* FUN_14052cd70(MS2Ptr<CItem>* pItem);
void FUN_140ebbb30(ASTooltip* pTip, MS2Ptr<CItem> spItem, MS2Ptr<CMeratMarketProduct> spProduct, bool bMyShop, bool bFlag);
void FUN_1409e3190(ASTooltip* pTip, CMeratMarketPremiumProduct* pProduct, int n);
void FUN_1411e3000(Unk_PCEquipSet* pEquip, ATL::CAtlList<MS2Ptr<CEquipItem> >* pItems, int nType, int a4, bool bFlag);
CGameEventValueManager* FUN_140302b00();
const CStringW& FUN_140424020(Unk_GameEventLockedValue<0x38>* pValue);     // the tab a game event opens

// @0x1412e9f10
int UIMeratMarketDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (vfunc_55() != 0 || m_30 == 0)
        return 0;
    if (FUN_140b632f0()->FUN_1422d4980(m_e0) == this) {
        CString strKey("");
        if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
            strKey = "onEnterKey";
        else if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0))
            strKey = "onTabKey";
        if (!strKey.IsEmpty()) {
            m_30->Invoke("onProcessKey", strKey);
            return 1;
        }
        return 0;
    }
    return 0;
}

// @0x1412eb2c0
void UIMeratMarketDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (vfunc_55() != 0 || WorldService::GetInstance()->FUN_141bd0cc0() == 0)
        return;
    if (m_30 == 0)
        return;
    if (m_dirty.HasFlag(1)) {
        if (m_dirty.HasSearch() && (m_spSearch.get() ? true : false)) {
            FUN_140939a00()->FUN_140d550c0(m_spSearch, m_spSearch->m_48);
        } else {
            int nType = m_dirty.GetSearchType();
            if (FUN_1406a5040(nType)) {
                int nShop = ShopKindOf(m_250);
                FUN_140939a00()->FUN_140d542c0(nShop, nType);
            } else {
                if (0 < nType)
                    FUN_140939a00()->FUN_140d54d50(m_spSearch);
            }
        }
        m_dirty.UnsetFlag(1);
    }
    if (m_dirty.HasFlag(2)) {
        ASArray banners(2);
        m_banner.FUN_141348190(banners);
        m_30->Invoke("buildBanners", Scaleform::GFx::Value(banners.FUN_1422bb870()));
        m_dirty.UnsetFlag(2);
    }
    if (m_dirty.HasFlag(4)) {
        ApplyPremiumSale();
        m_dirty.ClearPremiumSale();
    }
    if (m_dirty.HasFlag(0x10)) {
        bool bStarShop = FUN_1406a5930();
        m_30->Invoke("updateStarShop", bStarShop);
        m_dirty.UnsetFlag(0x10);
    }
    if (m_620) {
        unsigned nNow = FUN_140869420();
        if (nNow < (unsigned)m_628)
            SetModelTime(nNow - m_624);
        else
            Refresh7710(false);
    }
}

// @0x1412eb730
void UIMeratMarketDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    __int64 tNow = FUN_140869440();
    if (tNow == m_640)
        return;
    m_640 = tNow;
    if (vfunc_55() != 0 || WorldService::GetInstance()->FUN_141bd0cc0() == 0)
        return;
    if (FUN_140939a00() != 0)
        FUN_140939a00()->FUN_140d553a0();
}

// MS2-FUNCTIONAL: the exe passes a 4th argument to UIAvatarBase slot 28 (declared with 3)
// @0x1412eb7c0
void UIMeratMarketDialog::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (p2 == 0 || p3 == 0)
        return;
    UIAvatarBase* pAvatar;
    if (m_spAvatar == 0)
        pAvatar = m_spAvatarPC.get();
    else
        pAvatar = m_spAvatar.get();
    m_spModelView = 0;
    if (pAvatar != 0) {
        pAvatar->vfunc_28(p1, p2, p3);
        m_spModelView = pAvatar->FUN_1418b9bc0();
        int nKind = SlotKindOfPreview(pAvatar, m_spItemData);
        ShowAvatarItem(pAvatar, nKind, MS2Ptr<CItemData>(0), true);
        m_spAvatar.AssignRaw(pAvatar);
    }
}

// @0x1412eba20
void UIMeratMarketDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    UnloadRenderTarget();
}

// @0x1412eba50
bool UIMeratMarketDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    LoadRenderTarget();
    return true;
}

// @0x1412eba90
void UIMeratMarketDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    UnloadRenderTarget();
    m_spTabButtonGroup = 0;
    m_spLayerPage = 0;
    m_5a0 = 0;
    m_5b0 = 0;
    m_5c0 = 0;
    m_5d0 = 0;
    m_spSlider = 0;
    m_5f0 = 0;
    m_600 = 0;
    m_spModelHouse = 0;
}

// @0x1412ebb90
int UIMeratMarketDialog::vfunc_46()
{
    if (UISwfEntity::vfunc_46() == 0)
        return 0;
    if (m_30 == 0)
        return 0;
    {
        CString strName("m_probInfo");
        FUN_14134a480(*m_30, strName, &m_600);
    }
    return 1;
}

// @0x1412ec7d0
int UIMeratMarketDialog::vfunc_65()
{
    ResetModels();
    if (FUN_1406aa4b0() != 0) {
        FUN_1406aa4b0()->FUN_1407cb390(m_658);
        ClearLists();
    }
    if (FUN_1406f2370() != 0)
        FUN_1406f2370()->Init();
    m_658 = 0;
    if (UIDialog::vfunc_65() == 0)
        return 0;
    RequestLists();
    FUN_140939a00()->FUN_140d54440();
    FUN_140939a00()->FUN_140d54ba0();
    m_2f1 = 0;
    FUN_140939a00()->FUN_140d543c0(2);
    m_4f8 = 0;
    m_500 = "";
    return 1;
}

// The preview avatar is loaded: apply what was queued while it loaded.
// @0x1412ec8d0
void UIMeratMarketDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_spModelView = 0;
    m_spAvatarPC = 0;
    m_spMyAvatarPC = 0;
    m_spAvatar = 0;
    for (int i = 0; i < 5; i++)
        m_spAvatars[i] = 0;
    m_250 = 0;
    m_254 = -1;
    ResetPreview();
    m_spItemData2 = 0;
    m_2a0 = 0;
    m_spSearch = 0;
    ClearSearchRequest();
    m_dirty.Reset();
    m_model.Reset();
    ClearTabCounts();
    m_spWeaponType.Reset();
    m_bPreviewColoring = 0;
    for (int i = 0; i < 7; i++)
        m_spEquipIcons[i] = 0;
    m_2f1 = 0;
    m_2f2 = 0;
    m_2f3 = 0;
    Refresh7710(false);
    m_62c = 0;
    m_630.Empty();
    int nUiId = vfunc_48();
    FUN_140939a00()->FUN_140d5a200(nUiId);
    FUN_141adc5d0(FUN_1403ed2b0(), 0x4ec5);
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    FUN_140bc09f0()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
    FUN_140939a10()->UnregisterNotify(L"NotifyGameEventChanged",
        Delegate<void(NotifyObject*)>(this, &UIMeratMarketDialog::OnGameEventChanged));
    FUN_140939a10()->UnregisterNotify(L"NotifyBlindTarget",
        Delegate<void(NotifyObject*)>(this, &UIMeratMarketDialog::OnBlindTarget));
    FUN_140939a10()->UnregisterNotify(L"NotifyUgcDownloadComplete",
        Delegate<void(NotifyObject*)>(this, &UIMeratMarketDialog::OnUgcDownloadComplete));
    FUN_140c8dac0()->FUN_140d09d40(2);
}

// @0x1412ece80
int UIMeratMarketDialog::vfunc_73()
{
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(8) != 0) {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    return UIDialog::vfunc_73();
}

// @0x1412ecee0
void UIMeratMarketDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
}

// @0x1412ecf10
void UIMeratMarketDialog::vfunc_oa0_14(void* a1, int a2)
{
    if (m_30 == 0)
        return;
    m_30->Invoke("updateBlueMerat", FUN_1409404f0((__int64)a1));
}

// @0x1412ecfc0
void UIMeratMarketDialog::vfunc_oa0_15(void* a1, int a2)
{
    if (m_30 == 0)
        return;
    m_30->Invoke("updateRedMerat", FUN_1409404f0((__int64)a1));
}

// @0x1412ed070
int UIMeratMarketDialog::vfunc_o178_0(void* pAvatar)
{
    if (m_dirty.HasFlag(8)) {
        ApplyPreviewChanges(false);
        m_dirty.UnsetFlag(8);
        ApplyAvatarEquip(static_cast<UIAvatarPC*>(pAvatar));
    }
    if (m_dirty.HasFlag(0x20)) {
        EquipPreview(static_cast<UIAvatarBase*>(pAvatar), m_spItemData2, false, true);
        m_dirty.UnsetFlag(0x20);
        m_spItemData2 = 0;
    }
    RefreshAvatarOwner(static_cast<UIAvatarBase*>(pAvatar), m_spItem);
    return 1;
}

// @0x1412ed200
int UIMeratMarketDialog::vfunc_o178_2(void* pAvatar)
{
    if ((m_spItem.get() ? true : false) && pAvatar != 0 && static_cast<UIAvatarBase*>(pAvatar)->vfunc_24() != 0)
        RefreshAvatarOwner(static_cast<UIAvatarBase*>(pAvatar), m_spItem);
    return 1;
}

// @0x1412ed2b0
int UIMeratMarketDialog::vfunc_o178_1(void* pAvatar)
{
    if ((m_spItem.get() ? true : false) && pAvatar != 0 && static_cast<UIAvatarBase*>(pAvatar)->vfunc_24() != 0)
        vfunc_o178_0(pAvatar);
    return 1;
}

// @0x1412ed340
int UIMeratMarketDialog::vfunc_o178_3(void* pAvatar)
{
    if (pAvatar != 0) {
        if (static_cast<UIAvatarBase*>(pAvatar)->vfunc_24() != 0) {
            MS2Ptr<CItemData> spData(m_spItemData);
            EquipPreview(m_spAvatar.get(), spData, false, false);
        }
    }
    return 1;
}

// A profile image arrived: show it on the seller page.
// @0x1412ed430
void UIMeratMarketDialog::vfunc_ugc_1(void* pId, CString strPath)
{
    if (vfunc_55() != 0 || m_30 == 0)
        return;
    MS2Ptr<AScript> spPage = GetPage(5);
    if (spPage.get() != 0) {
        ASObj data(2);
        data.FUN_1407cba60("charSN", FUN_140719530((unsigned __int64)pId));
        data.FUN_1407cba60("imgpath", FUN_141028a90(CStringA(strPath), 1));
        spPage->Invoke("updateProfile", Scaleform::GFx::Value(data.FUN_1422bb870()));
    }
}

// A product icon arrived: show it on the product's page.
// @0x1412ed650
void UIMeratMarketDialog::vfunc_ugc_3(void* pCallBack, void* pstrPath)
{
#define MERAT_ICON_KEY (static_cast<const UgcItemIcon::CallBackData*>(pCallBack))
    if (vfunc_55() != 0)
        return;
    MS2Ptr<AScript> spPage(0);
    if (MERAT_ICON_KEY->m_nKind != m_250) {
        int nKind = MERAT_ICON_KEY->m_nKind;
        if (MERAT_ICON_KEY->m_38 == 0 && nKind != 0) {
            spPage = GetPage(nKind);
        } else {
            return;
        }
    }
    if (MERAT_ICON_KEY->m_38 == 0 || MERAT_ICON_KEY->m_spCond->IsSameQuery(m_spSearch.get()) != 0)
        spPage = m_30;
    if (spPage.get() != 0) {
        ASObj data(2);
        Unk_MeratProductKey key(0, MERAT_ICON_KEY->m_30);
        data.FUN_1407cbb20("productOID", key.FUN_1409b0470());
        data.FUN_1407cba60("iconPath", *static_cast<const CStringA*>(pstrPath));
        spPage->Invoke("updateProductIcon", Scaleform::GFx::Value(data.FUN_1422bb870()));
    }
#undef MERAT_ICON_KEY
}

// @0x1412ee460
void UIMeratMarketDialog::ShowUgcTerms(int nParam, int nKind)
{
    if (nKind != 3)
        return;
    if (FUN_1406516b0() != 1)
        return;
    if (m_638 == true)
        return;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d74500(CStringW(L"$s_msgbox_ugc_shop_terms_content"), 0x1e,
        Delegate<bool(int, const CMsgBoxData&)>(this, &UIMeratMarketDialog::OnUgcTermsConfirm));
    if (spBox.operator CMsgBoxData*() != 0) {
        {
            CStringW strTitle(L"$s_msgbox_ugc_shop_terms_title");
            spBox->FUN_141a015d0(strTitle);
        }
        spBox->FUN_140533ff0(nParam);
        FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
    }
}

// MS2-FUNCTIONAL: local slot order / EH state count of the loop temporaries differ
// @0x1412ee610
void UIMeratMarketDialog::ApplyBanners(Unk_AdBannerArray& banners)
{
    m_banner.Clear();
    size_t nCount = FUN_14016eb40(&banners);
    CStringW strLimited(L"limited_");
    CStringW strHome(L"homeproduct_");
    bool bHomeFeature = FUN_14036d570(FUN_140166410(), 0x108);
    for (size_t i = 0; i < nCount; i++) {
        Unk_AdBannerPtr spBanner(FUN_14103ceb0(&banners, i));
        if (FUN_14103bf60(&spBanner, 0))
            continue;
        int nType = 0xcc;
        CStringW* pTypeName = &FUN_14016e5a0(&spBanner)->m_strTypeName;
        if (pTypeName->Find(strLimited, 0) == 0) {
            nType = 0xcf;
        } else if (bHomeFeature) {
            if (pTypeName->Find(strHome, 0) == 0)
                nType = 0xd2;
        }
        MS2Ptr<MeratMarketShopBannerInfo> spInfo(new MeratMarketShopBannerInfo());
        if (!(spInfo == 0)) {
            spInfo->FUN_141347c30(spBanner, nType, CStringA(""));
            m_banner.FUN_141347ed0(MS2Ptr<ShopBannerInfo>(spInfo.get()));
        }
    }
    if (FUN_1422dc430() != 0) {
        if (GetTabCount(0) != 0)
            m_dirty.SetFlag(2);
    }
}

// @0x1412ee920
void UIMeratMarketDialog::OpenBannerProduct(const CStringA& strBanner)
{
    ATL::CAtlArray<CStringW> tokens;
    FUN_14025a680(CStringW((const char*)strBanner), tokens, L",");
    if (tokens.GetCount() == 0)
        return;
    int nTab = TabFromName(tokens[0]);
    if (nTab == 9)
        return;
    int nCategory = 0;
    if (tokens.GetCount() >= 2)
        nCategory = FUN_1407181a0(tokens[1]);
    m_query.Clear();
    m_query.m_30 = nCategory;
    m_query.m_nCategory = 3;
    m_query.m_44 = nTab;
    m_2f3 = 1;
    RunQuery();
}

// @0x1412eeaa0
void UIMeratMarketDialog::OpenBannerSeller(const CStringA& strBanner)
{
    ATL::CAtlArray<CStringW> tokens;
    FUN_14025a680(CStringW((const char*)strBanner), tokens, L",");
    if (tokens.GetCount() < 1)
        return;
    CStringW strName(tokens[0]);
    strName.Trim();
    m_query.Clear();
    m_query.m_strText = strName;
    m_query.m_nCategory = 4;
    m_2f3 = 1;
    RunQuery();
}

// @0x1412eebe0
void UIMeratMarketDialog::OpenBannerSearch(const CStringA& strBanner)
{
    ATL::CAtlArray<CStringW> tokens;
    FUN_14025a680(CStringW((const char*)strBanner), tokens, L",");
    if (tokens.GetCount() < 4)
        return;
    int nTab = TabFromName(tokens[0]);
    if (nTab == 9)
        return;
    int nCategory = FUN_1407181a0(tokens[1]);
    if (nCategory == -1 || FUN_1406a5060(nCategory)) {
        CStringW strText(tokens[2]);
        strText.Trim();
        size_t nCount = tokens.GetCount();
        CStringW strSort(L"");
        for (size_t i = 3; i < nCount; i++) {
            if (!strSort.IsEmpty())
                strSort.Append(L",");
            strSort.Append(tokens[i]);
        }
        m_query.Clear();
        m_query.m_strSort = FUN_14016a600(strSort, 0);
        m_query.m_strText = strText;
        m_query.m_30 = nCategory;
        m_query.m_nCategory = 5;
        m_query.m_44 = nTab;
        m_query.m_48 = nTab == 3;
        m_2f3 = 1;
        RunQuery();
    }
}

// @0x1412eeee0
bool UIMeratMarketDialog::IsCurrentShopTab()
{
    if (m_250 == 0)
        return true;
    if (m_250 == 1 || m_250 == 2)
        return FUN_1406a5040(m_254);
    else if (m_250 == 3)
        return m_254 == 10;
    return false;
}

// @0x1412efc30
int UIMeratMarketDialog::BuildQuery(ASObj& data, SearchQuery& query)
{
    int nCategoryIndex = -1;
    Unk_ShopTabArray* pList = ListOf(query.m_44);
    if (pList != 0) {
        if (FUN_1406a5060(query.m_30))
            nCategoryIndex = FUN_140ec1c70(*pList, query.m_30);
        else
            nCategoryIndex = 0;
    } else if (query.m_44 == 8) {
        nCategoryIndex = 0;
    }
    data.FUN_1407cba60("marketSN", query.m_strSort);
    data.FUN_1407cb9c0("selectedTab", query.m_44);
    data.FUN_1407cb9c0("selectedCategoryIndex", nCategoryIndex);
    data.FUN_1407cbbe0("isUgc", query.m_48);
    if (query.m_nCategory == 4)
        data.FUN_1407cbb20("searchText", query.m_strText);
    return 1;
}

// @0x1412efdb0
void UIMeratMarketDialog::RefreshAvatarOwner(UIAvatarBase* pAvatar, MS2Ptr<CItem> spOwner)
{
    if (pAvatar == 0 || spOwner == 0 || spOwner->FUN_140525f60() == 0)
        return;
    int nKind = pAvatar->FUN_1418b9ba0();
    UIAvatarCube* pCube;
    if (nKind == 2 && (pCube = dynamic_cast<UIAvatarCube*>(pAvatar)) != 0 && pCube->FUN_1418bde80() != 0)
        pCube->FUN_1418bde80()->FUN_141085530(spOwner);
}

// @0x1412f0720
void UIMeratMarketDialog::OpenProductByKey(Unk_MeratProductKey key, bool bShop)
{
    MS2Ptr<CMeratMarketProduct> spProduct = FindProduct(key, CurrentSearchId(), bShop);
    if (spProduct == 0)
        return;
    OpenProduct(spProduct);
}

// MS2-FUNCTIONAL: large body, frame/branch layout differs after 2 attempts
// @0x1412f1180
void UIMeratMarketDialog::PreviewBundle(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (!(spProduct == 0)) {
        if (spProduct->IsPremium() != 0) {
            CMeratMarketPremiumProduct* pPremium = &spProduct->m_premium;
            if (pPremium->m_nType != 3)
                return;
            ATL::CAtlArray<MS2Ptr<CItemData> > arrFirst;
            ATL::CAtlArray<MS2Ptr<CItemData> > arrSecond;
            SplitPackageItems(*pPremium, arrFirst, arrSecond);
            if (arrFirst.IsEmpty() && arrSecond.IsEmpty())
                return;
            MS2Ptr<CItemData> spPick(0);
            UIAvatarBase* pAvatar = 0;
            if (!arrFirst.IsEmpty()) {
                ATL::CAtlArray<MS2Ptr<CItemData> > arrEquip;
                ATL::CAtlArray<MS2Ptr<CItemData> > arrOther;
                SplitEquipItems(MS2Ptr<CItemData>(0), arrFirst, arrEquip, arrOther);
                if (arrEquip.IsEmpty() && arrOther.IsEmpty())
                    return;
                MS2Ptr<UIAvatarPC>* pspAvatar = !arrEquip.IsEmpty() ? &m_spAvatarPC : &m_spMyAvatarPC;
                pAvatar = pspAvatar->get();
                UIAvatarPC* pPC = dynamic_cast<UIAvatarPC*>(pAvatar);
                if (pPC == 0)
                    return;
                ShowEquipIcons(pAvatar, m_29c, 1);
                ATL::CAtlArray<MS2Ptr<CItemData> >* pItems = (pPC == m_spAvatarPC.get()) ? &arrEquip : &arrOther;
                Unk_AvPackageKey key;
                FUN_1418bf850(spProduct, &key);
                if (!pPC->FUN_1418bb3f0(&key, PreviewColorCode(), pItems))
                    return;
                spPick = pItems->GetAt(0);
                if (m_spAvatar.get() != 0) {
                    if (m_spAvatar->FUN_1418b9ba0() == 1)
                        ApplyPreviewChanges(1);
                }
                if (!arrSecond.IsEmpty() && pPC == m_spAvatarPC.get()) {
                    MS2Ptr<CItemData> spOther = PickItem(arrSecond, 1);
                    if (spOther.operator CItemData*() != 0) {
                        spPick = spOther;
                        pAvatar = CreateItemAvatar(spOther);
                    }
                }
            }
            else {
                MS2Ptr<CItemData> spOther = PickItem(arrSecond, 0);
                if (spOther.operator CItemData*() != 0) {
                    if (m_spAvatar.get() != 0) {
                        if (m_spAvatar->FUN_1418b9ba0() == 1)
                            ApplyPreviewChanges(1);
                    }
                    spPick = spOther;
                    UIAvatarBase* pPreview = GetAvatarForItem(spOther);
                    int nSlotKind = SlotKindOfPreview(pPreview, spOther);
                    ShowEquipIcons(pPreview, nSlotKind, 1);
                    pAvatar = CreateItemAvatar(spOther);
                }
            }
            if (pAvatar != 0 && !(spPick == 0)) {
                MS2Ptr<CItem> spItem(new CItem());
                spItem->FUN_14052b130(0, spProduct->m_premium.m_nGrade, 0);
                int nIndex = FindPreview(pAvatar);
                int nSlotKind = SlotKindOf(nIndex, spPick);
                AddPreviewSlot(spItem, spProduct, 0x7a, nIndex, nSlotKind, MS2Ptr<CItemData>(0));
                ShowAvatarItem(pAvatar, nSlotKind, spPick, 1);
                SetPreviewItem(spItem, spPick, nIndex, nSlotKind, spProduct);
            }
        }
    }
}

// @0x1412f1cd0
void UIMeratMarketDialog::PreviewCubeProduct(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spProduct == 0 || spData == 0)
        return;
    if (!FUN_141b488c0(spData))
        return;
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    {
        MS2Ptr<UIAvatarBase> spOld = GetPreviewPtr(2);
        if (spOld.get() != 0) {
            spOld->vfunc_21(0);
            ShowEquipIcons(spOld.get(), 2, 0);
        }
    }
    MS2Ptr<UIAvatarBase> spCube(new UIAvatarCube(spData));
    if (spCube.get() != 0)
        spCube->vfunc_1(static_cast<IUIAvatarEventListener*>(this));
    SetPreview(2, spCube);
    AddPreviewSlot(spItem, spProduct, 0x7f, 2, 2, MS2Ptr<CItemData>(0));
    ShowAvatarItem(spCube.get(), 2, spData, 0);
    SetPreviewItem(spItem, spData, 2, 2, spProduct);
}

// MS2-FUNCTIONAL: large body, codegen layout differs after 2 attempts
// @0x1412f2210
void UIMeratMarketDialog::PreviewEquipProduct(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spProduct == 0 || spData == 0)
        return;
    if (!FUN_141b488c0(spData))
        return;
    PC* pPc = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    int nGender = pPc->FUN_141658e60();
    int nJob = pPc->FUN_141654700();
    UIAvatarPC* pPreview;
    if (m_spWeaponType.get() != 0 && m_spWeaponType->FUN_140ebb780(nGender, nJob, spData))
        pPreview = m_spAvatarPC.get();
    else
        pPreview = m_spMyAvatarPC.get();
    if (pPreview == 0)
        return;
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    int nObjectId = pPreview->vfunc_25();
    spItem->FUN_140526b30(nObjectId);
    Unk_WsC_GameObj* pObject = WorldService::GetInstance()->FUN_141bd1290(nObjectId);
    if (pObject == 0)
        return;
    int nSlotKind = SlotKindOfPreview(pPreview, spData);
    int nIndex = FindPreview(pPreview);
    int nEvent = spItem->FUN_140526c30();
    MS2Ptr<UIEquipIconContainer> spIcons = GetEquipIcon(nSlotKind);
    if (spData) {
        if (spData->FUN_14053d2f0()) {
            int nHand = 0;
            if (spIcons.get() != 0)
                nHand = spIcons->FUN_140e2a7e0(spData);
            if (nHand != 0) {
                nEvent = nHand;
                spItem->FUN_140526c10(nHand);
            }
        }
    }
    if (!ShowEquipIcons(pPreview, nSlotKind, 0)) {
        Unk_AvPackageKey key;
        if (pPreview->FUN_1418bd350(&key, nEvent)) {
            pPreview->FUN_1418bc500(&key);
            if (spIcons.get() != 0)
                spIcons->FUN_140e2a640(0x79);
        }
    }
    pPreview->FUN_1418bafa0(spItem.get(), PreviewColorCode());
    AddPreviewSlot(spItem, spProduct, nEvent, nIndex, nSlotKind, MS2Ptr<CItemData>(0));
    ShowAvatarItem(pPreview, nSlotKind, spData, 0);
    SetPreviewItem(spItem, spData, nIndex, nSlotKind, spProduct);
    m_dirty.SetFlag(8);
}

// MS2-FUNCTIONAL: large body, codegen layout differs after 2 attempts
// @0x1412f29f0
void UIMeratMarketDialog::PreviewBoxProduct(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spProduct == 0 || spData == 0)
        return;
    if (spData->FUN_14053c5c0() != 0x19)
        return;
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    if (spItem->FUN_140527840() == 0)
        return;
    ATL::CAtlArray<MS2Ptr<CItemData> > arrFirst;
    ATL::CAtlArray<MS2Ptr<CItemData> > arrSecond;
    FUN_1418bf430(spData, &arrFirst, &arrSecond);
    if (arrFirst.IsEmpty() && arrSecond.IsEmpty())
        return;
    ATL::CAtlArray<MS2Ptr<CItemData> > arrEquip;
    ATL::CAtlArray<MS2Ptr<CItemData> > arrOther;
    SplitEquipItems(spData, arrFirst, arrEquip, arrOther);
    MS2Ptr<CItemData> spPick(spData);
    UIAvatarBase* pAvatar = 0;
    if (arrEquip.IsEmpty() && arrOther.IsEmpty()) {
        MS2Ptr<CItemData> spOther = PickItem(arrSecond, 0);
        if (spOther.operator CItemData*() != 0) {
            spPick = spOther;
            UIAvatarBase* pPreview = GetAvatarForItem(spOther);
            int nSlotKind = SlotKindOfPreview(pPreview, spOther);
            ShowEquipIcons(pPreview, nSlotKind, 0);
            pAvatar = CreateItemAvatar(spOther);
        }
    }
    else {
        if (WorldService::GetInstance()->FUN_141bd0cc0() == 0)
            return;
        MS2Ptr<UIAvatarPC>* pspAvatar = !arrEquip.IsEmpty() ? &m_spAvatarPC : &m_spMyAvatarPC;
        UIAvatarPC* pPC = pspAvatar->get();
        if (pPC == 0)
            return;
        ATL::CAtlArray<MS2Ptr<CItemData> >* pItems = (pPC == m_spAvatarPC.get()) ? &arrEquip : &arrOther;
        pAvatar = pPC;
        int nSlotKind = SlotKindOfPreview(pPC, spData);
        ShowEquipIcons(pPC, nSlotKind, 0);
        EquipPackageIcon(pPC, nSlotKind, 0x79);
        int nColor = PreviewColorCode();
        if (!pPC->FUN_1418bb2a0(spData, nColor, pItems))
            return;
        MS2Ptr<UIEquipIconContainer> spIcons = GetEquipIcon(nSlotKind);
        if (spIcons.get() != 0) {
            ATL::CAtlMap<int, MS2Ptr<ASEquipIcon> >* pIcons = spIcons->GetIconMap();
            if (!pIcons->IsEmpty()) {
                POSITION pos = pIcons->GetStartPosition();
                while (pos != 0) {
                    POSITION posCur = pos;
                    pIcons->GetNext(pos);
                    int nKey = pIcons->GetAt(posCur)->m_key;
                    if (pPC->FUN_1418bd510(nKey).get() != 0)
                        spIcons->FUN_140e2a640(nKey);
                }
            }
        }
        spPick = pItems->GetAt(0);
        if (!arrSecond.IsEmpty() && pPC == m_spAvatarPC.get()) {
            MS2Ptr<CItemData> spOther = PickItem(arrSecond, 1);
            if (spOther.operator CItemData*() != 0) {
                spPick = spOther;
                CreateItemAvatar(spOther);
            }
        }
    }
    if (pAvatar != 0 && !(spPick == 0)) {
        int nIndex = FindPreview(pAvatar);
        int nSlotKind = SlotKindOf(nIndex, spPick);
        AddPreviewSlot(spItem, spProduct, 0x79, nIndex, nSlotKind, spPick);
        ShowAvatarItem(pAvatar, nSlotKind, spPick, 0);
        SetPreviewItem(spItem, spPick, nIndex, nSlotKind, spProduct);
        m_dirty.SetFlag(8);
    }
}

// @0x1412f3750
void UIMeratMarketDialog::PreviewProductItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (spProduct == 0 || spData == 0)
        return;
    if (!FUN_141b488c0(spData))
        return;
    ApplyProductItem(spProduct, spData);
}

// @0x1412f38a0
void UIMeratMarketDialog::ShowLapenshardItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spProduct == 0 || spData == 0)
        return;
    MS2Ptr<UIAvatarPC> spAvatar = CreateLapenshardAvatar(spData);
    if (spAvatar == 0)
        return;
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    int nIndex = FindPreview(spAvatar.get());
    int nSlotKind = SlotKindOf(nIndex, spData);
    AddPreviewSlot(spItem, spProduct, 0x7b, nIndex, nSlotKind, MS2Ptr<CItemData>(0));
    ShowAvatarItem(spAvatar.get(), nSlotKind, spData, 0);
    SetPreviewItem(spItem, spData, nIndex, nSlotKind, spProduct);
}

// @0x1412f3cd0
void UIMeratMarketDialog::ShowRideeItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (spProduct == 0 || spData == 0 || m_30 == 0)
        return;
    Unk_MpRideePtr spRidee = CreateRideeAvatar(spData);
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    AddPreviewSlot(spItem, spProduct, 0x7e, 3, 3, MS2Ptr<CItemData>(0));
    ShowAvatarItem(spRidee.get(), 3, spData, 0);
    SetPreviewItem(spItem, spData, 3, 3, spProduct);
}

// @0x1412f4060
void UIMeratMarketDialog::ApplyProductItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (spProduct == 0 || spData == 0 || m_30 == 0)
        return;
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    MS2Ptr<UIAvatarPC> spAvatar = CreateCubeAvatar(spData, spItem);
    int nSlotKind = SlotKindOfPreview(spAvatar.get(), spData);
    int nIndex = FindPreview(spAvatar.get());
    AddPreviewSlot(spItem, spProduct, 0x7b, nIndex, nSlotKind, MS2Ptr<CItemData>(0));
    ShowAvatarItem(spAvatar.get(), nSlotKind, spData, 0);
    SetPreviewItem(spItem, spData, nIndex, nSlotKind, spProduct);
}

// @0x1412f44b0
void UIMeratMarketDialog::ShowPetItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (spProduct == 0 || spData == 0 || m_30 == 0)
        return;
    MS2Ptr<UIAvatarPet> spPet = CreatePetAvatar(spData);
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    AddPreviewSlot(spItem, spProduct, 0x80, 4, 4, MS2Ptr<CItemData>(0));
    ShowAvatarItem(spPet.get(), 4, spData, 0);
    SetPreviewItem(spItem, spData, 4, 4, spProduct);
}

// @0x1412f4840
void UIMeratMarketDialog::ShowFurnitureItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spProduct == 0 || spData == 0)
        return;
    MS2Ptr<UIAvatarPC> spAvatar = CreateFurnitureAvatar(spData);
    if (spAvatar == 0)
        return;
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    int nIndex = FindPreview(spAvatar.get());
    int nSlotKind = SlotKindOf(nIndex, spData);
    AddPreviewSlot(spItem, spProduct, 0x7b, nIndex, nSlotKind, MS2Ptr<CItemData>(0));
    ShowAvatarItem(spAvatar.get(), nSlotKind, spData, 0);
    SetPreviewItem(spItem, spData, nIndex, nSlotKind, spProduct);
}

// @0x1412f4c70
void UIMeratMarketDialog::ShowBlueprintItem(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spProduct == 0 || spData == 0)
        return;
    MS2Ptr<UIAvatarPC> spAvatar = CreateBlueprintAvatar(spData);
    if (spAvatar == 0)
        return;
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    int nIndex = FindPreview(spAvatar.get());
    int nSlotKind = SlotKindOf(nIndex, spData);
    AddPreviewSlot(spItem, spProduct, 0x7b, nIndex, nSlotKind, MS2Ptr<CItemData>(0));
    ShowAvatarItem(spAvatar.get(), nSlotKind, spData, 0);
    SetPreviewItem(spItem, spData, nIndex, nSlotKind, spProduct);
}

// MS2-FUNCTIONAL: unwind-help slot 8 bytes bigger in exe than ours (frame 0x138 vs 0x130)
// @0x1412f50a0
void UIMeratMarketDialog::ShowKind5Item(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spProduct == 0 || spData == 0)
        return;
    if (!FUN_14036d570(FUN_140166410(), 0xa9)) {
        PreviewEquipProduct(spProduct, spData);
        return;
    }
    MS2Ptr<UIAvatarPC> spAvatar = CreateKind5Avatar(spData);
    if (spAvatar == 0)
        return;
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    AddPreviewSlot(spItem, spProduct, 0x7c, 0, 5, MS2Ptr<CItemData>(0));
    ShowAvatarItem(spAvatar.get(), 5, spData, 0);
    SetPreviewItem(spItem, spData, 0, 5, spProduct);
}

// MS2-FUNCTIONAL: unwind-help slot 8 bytes bigger in exe than ours (frame 0x138 vs 0x130)
// @0x1412f5540
void UIMeratMarketDialog::ShowKind6Item(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spProduct == 0 || spData == 0)
        return;
    if (!FUN_14036d570(FUN_140166410(), 0xec)) {
        PreviewEquipProduct(spProduct, spData);
        return;
    }
    MS2Ptr<UIAvatarPC> spAvatar = CreateKind6Avatar(spData);
    if (spAvatar == 0)
        return;
    MS2Ptr<CItem> spItem(FUN_140ebc070(spProduct));
    if (spItem == 0)
        return;
    AddPreviewSlot(spItem, spProduct, 0x7d, 0, 6, MS2Ptr<CItemData>(0));
    ShowAvatarItem(spAvatar.get(), 6, spData, 0);
    SetPreviewItem(spItem, spData, 0, 6, spProduct);
}

// @0x1412f59e0
Unk_MpRideePtr UIMeratMarketDialog::CreateRideeAvatar(MS2Ptr<CItemData> spData)
{
    if (spData == 0 || m_30 == 0)
        return Unk_MpRideePtr(0);
    Unk_MpRideePtr spRidee(dynamic_cast<UIAvatarRidee*>(GetPreviewPtr(3).operator UIAvatarBase*()));
    ShowEquipIcons(spRidee.get(), 3, 0);
    // the exe tests "== 0" before dereferencing (the dialog always has the ridee view when this is reached)
    if (spRidee == 0 && spRidee->FUN_1418be7e0() == 0)
        return Unk_MpRideePtr(0);
    spRidee->FUN_1418be460(spData);
    return spRidee;
}

// @0x1412f5be0
MS2Ptr<UIAvatarPC> UIMeratMarketDialog::CreateCubeAvatar(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem)
{
    if (spData == 0 || m_30 == 0)
        return MS2Ptr<UIAvatarPC>(0);
    // the exe tests "== 0" before dereferencing (the dialog always has the avatar when this is reached)
    if (m_spAvatarPC == 0 && m_spAvatarPC->FUN_1418bd1d0() == 0)
        return MS2Ptr<UIAvatarPC>(0);
    ShowEquipIcons(m_spAvatarPC.get(), 0, 0);
    m_spAvatarPC->FUN_1418bd050(spData, spItem);
    return m_spAvatarPC;
}

// @0x1412f5e10
MS2Ptr<UIAvatarPet> UIMeratMarketDialog::CreatePetAvatar(MS2Ptr<CItemData> spData)
{
    if (spData == 0 || m_30 == 0)
        return MS2Ptr<UIAvatarPet>(0);
    MS2Ptr<UIAvatarPet> spPet(dynamic_cast<UIAvatarPet*>(GetPreviewPtr(4).operator UIAvatarBase*()));
    // the exe tests "== 0" before dereferencing (the dialog always has the pet view when this is reached)
    if (spPet == 0 && spPet->FUN_1418bee00() == 0)
        return MS2Ptr<UIAvatarPet>(0);
    ShowEquipIcons(spPet.get(), 4, 0);
    spPet->FUN_1418bebd0(spData);
    return spPet;
}

// @0x1412f6010
MS2Ptr<UIAvatarPC> UIMeratMarketDialog::CreateLapenshardAvatar(MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spData == 0)
        return MS2Ptr<UIAvatarPC>(0);
    if (WorldService::GetInstance()->FUN_141bd0cc0() == 0)
        return MS2Ptr<UIAvatarPC>(0);
    if (!spData->FUN_14053ce40())
        return MS2Ptr<UIAvatarPC>(0);
    UIAvatarPC* pPC = m_spAvatarPC.get();
    if (pPC == 0)
        return MS2Ptr<UIAvatarPC>(0);
    int nObjectId = pPC->vfunc_25();
    Unk_WsC_GameObj* pObject = WorldService::GetInstance()->FUN_141bd1290(nObjectId);
    if (pObject == 0)
        return MS2Ptr<UIAvatarPC>(0);
    int nSlotKind = SlotKindOfPreview(pPC, spData);
    ShowEquipIcons(pPC, nSlotKind, 0);
    pPC->FUN_1418bce80(spData->FUN_14053dc20());
    return MS2Ptr<UIAvatarPC>(pPC);
}

// @0x1412f62b0
MS2Ptr<UIAvatarPC> UIMeratMarketDialog::CreateBlueprintAvatar(MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spData == 0)
        return MS2Ptr<UIAvatarPC>(0);
    if (WorldService::GetInstance()->FUN_141bd0cc0() == 0)
        return MS2Ptr<UIAvatarPC>(0);
    if (!spData->FUN_14053cd50())
        return MS2Ptr<UIAvatarPC>(0);
    UIAvatarPC* pPC = m_spAvatarPC.get();
    if (pPC == 0)
        return MS2Ptr<UIAvatarPC>(0);
    AvatarPC* pObject = pPC->FUN_1418bd1d0();
    if (pObject == 0)
        return MS2Ptr<UIAvatarPC>(0);
    int nSlotKind = SlotKindOfPreview(pPC, spData);
    ShowEquipIcons(pPC, nSlotKind, 0);
    pObject->FUN_1409f45a0(spData);
    return MS2Ptr<UIAvatarPC>(pPC);
}

// @0x1412f6540
MS2Ptr<UIAvatarPC> UIMeratMarketDialog::CreateKind5Avatar(MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spData == 0)
        return MS2Ptr<UIAvatarPC>(0);
    if (WorldService::GetInstance()->FUN_141bd0cc0() == 0)
        return MS2Ptr<UIAvatarPC>(0);
    if (!spData->FUN_14053cd10())
        return MS2Ptr<UIAvatarPC>(0);
    UIAvatarPC* pPC = m_spAvatarPC.get();
    if (pPC == 0)
        return MS2Ptr<UIAvatarPC>(0);
    AvatarPC* pObject = pPC->FUN_1418bd1d0();
    if (pObject == 0)
        return MS2Ptr<UIAvatarPC>(0);
    int nSlotKind = SlotKindOfPreview(pPC, spData);
    ShowEquipIcons(pPC, nSlotKind, 0);
    m_dirty.SetFlag(8);
    return MS2Ptr<UIAvatarPC>(pPC);
}

// @0x1412f6780
MS2Ptr<UIAvatarPC> UIMeratMarketDialog::CreateKind6Avatar(MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spData == 0)
        return MS2Ptr<UIAvatarPC>(0);
    if (!spData->FUN_14053d900())
        return MS2Ptr<UIAvatarPC>(0);
    UIAvatarPC* pPC = m_spAvatarPC.get();
    if (pPC == 0)
        return MS2Ptr<UIAvatarPC>(0);
    AvatarPC* pObject = pPC->FUN_1418bd1d0();
    if (pObject == 0)
        return MS2Ptr<UIAvatarPC>(0);
    int nSlotKind = SlotKindOfPreview(pPC, spData);
    ShowEquipIcons(pPC, nSlotKind, 0);
    return MS2Ptr<UIAvatarPC>(pPC);
}

// @0x1412f6970
MS2Ptr<UIAvatarPC> UIMeratMarketDialog::CreateFurnitureAvatar(MS2Ptr<CItemData> spData)
{
    if (m_30 == 0 || spData == 0)
        return MS2Ptr<UIAvatarPC>(0);
    if (WorldService::GetInstance()->FUN_141bd0cc0() == 0)
        return MS2Ptr<UIAvatarPC>(0);
    if (!spData->FUN_14053cb40())
        return MS2Ptr<UIAvatarPC>(0);
    UIAvatarPC* pPC = m_spAvatarPC.get();
    if (pPC == 0)
        return MS2Ptr<UIAvatarPC>(0);
    AvatarPC* pObject = pPC->FUN_1418bd1d0();
    if (pObject == 0)
        return MS2Ptr<UIAvatarPC>(0);
    int nSlotKind = SlotKindOfPreview(pPC, spData);
    ShowEquipIcons(pPC, nSlotKind, 0);
    pObject->FUN_1409f42a0(spData);
    return MS2Ptr<UIAvatarPC>(pPC);
}

// @0x1412f6c00
void UIMeratMarketDialog::ShowAvatarItem(UIAvatarBase* pAvatar, int nKind, MS2Ptr<CItemData> spData, bool bChanged)
{
    if (m_spAvatar.get() != pAvatar) {
        for (int i = 0; i < 5; i++) {
            MS2Ptr<UIAvatarBase> spPreview = m_spAvatars[i];
            if (spPreview.get() != 0)
                spPreview->vfunc_21(0);
        }
        if (m_spModelView.operator UIRenderView*() != 0)
            m_spModelView.operator->()->vfunc_4();
        bChanged = true;
    }
    if (!bChanged)
        bChanged = IsItemChanged(spData);
    if (pAvatar != 0) {
        pAvatar->vfunc_21(m_spModelView.operator UIRenderView*());
        if (m_29c != nKind)
            bChanged = true;
        SetSlotKind(nKind);
        if (bChanged) {
            m_dirty.SetFlag(0x20);
            m_spItemData2 = spData;
            bChanged = false;
        }
        EquipPreview(pAvatar, spData, 1, bChanged);
    }
    m_spAvatar.AssignRaw(pAvatar);
}

// @0x1412f6ec0
UIAvatarBase* UIMeratMarketDialog::CreateItemAvatar(MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return 0;
    UIAvatarBase* pAvatar = CreatePreviewAvatar(spData);
    if (pAvatar != 0)
        return pAvatar;
    if (spData->FUN_14053cc40())
        return CreatePetAvatar(spData).get();
    return 0;
}

// @0x1412f7040
UIAvatarBase* UIMeratMarketDialog::CreatePreviewAvatar(MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return 0;
    if (spData->FUN_14053ce40())
        return CreateLapenshardAvatar(spData).get();
    else if (spData->FUN_14053cc80())
        return CreateCubeAvatar(spData, MS2Ptr<CItem>(0)).get();
    else if (spData->FUN_14053cd50())
        return CreateBlueprintAvatar(spData).get();
    if (spData->FUN_14053cb40())
        return CreateFurnitureAvatar(spData).get();
    return 0;
}

// @0x1412f73d0
void UIMeratMarketDialog::SplitPackageItems(const CMeratMarketPremiumProduct& premium,
                                            ATL::CAtlArray<MS2Ptr<CItemData> >& arrFirst,
                                            ATL::CAtlArray<MS2Ptr<CItemData> >& arrSecond)
{
    const ATL::CRBMap<int, MS2Ptr<CDBPremiumProduct> >& mapSub = premium.m_mapLimit;
    if (mapSub.IsEmpty())
        return;
    for (POSITION pos = mapSub.GetHeadPosition(); pos != 0; mapSub.GetNext(pos)) {
        MS2Ptr<CDBPremiumProduct> spSub = mapSub.GetValueAt(pos);
        if (spSub == 0)
            continue;
        MS2Ptr<CItemData> spData = FUN_14053f870(spSub->m_nItemId);
        if (spData == 0)
            continue;
        if (spData->FUN_14053c5c0() != 0x19) {
            if (spData->FUN_14053cbc0())
                arrFirst.Add(spData);
            else
                arrSecond.Add(spData);
        }
        else
            FUN_1418bf430(spData, &arrFirst, &arrSecond);
    }
}

// @0x1412f7590
void UIMeratMarketDialog::SplitEquipItems(MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >& arrFirst,
                                          ATL::CAtlArray<MS2Ptr<CItemData> >& arrSecond,
                                          ATL::CAtlArray<MS2Ptr<CItemData> >& arrThird)
{
    PCBase* pPc = static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    FUN_141b48a20(pPc, spData, &arrFirst, &arrSecond, &arrThird, m_spWeaponType);
}

// @0x1412f7690
void UIMeratMarketDialog::LoadRenderTarget()
{
    if (m_30.get() != 0)
        m_30->Invoke("loadRenderTarget");
}

// @0x1412f76f0
void UIMeratMarketDialog::UnloadRenderTarget()
{
    if (m_30.get() != 0) {
        m_spModelView = 0;
        m_30->Invoke("unloadRenderTarget");
    }
}

// @0x1412f7760
void UIMeratMarketDialog::ClearTabCounts()
{
    for (int i = 0; i < 9; i++)
        m_tabCounts[i] = 0;
}

// @0x1412f77b0
void UIMeratMarketDialog::ClearLists()
{
    m_tabs100000.RemoveAll();
    m_tabs100001.RemoveAll();
    m_tabs110000.RemoveAll();
}

// MS2-FUNCTIONAL: tail block 7 bytes shorter than exe; jump targets shift
// @0x1412f7800
bool UIMeratMarketDialog::ShowEquipIcons(UIAvatarBase* pAvatar, int nSlot, bool bClear)
{
    if (pAvatar == 0)
        return 0;
    Refresh7710(1);
    if (pAvatar->FUN_1418b9ba0() == 1) {
        UIAvatarPC* pPC = dynamic_cast<UIAvatarPC*>(pAvatar);
        if (pPC != 0) {
            MS2Ptr<UIEquipIconContainer> spIcons = GetEquipIcon(nSlot);
            if (spIcons == 0)
                return 0;
            if (bClear) {
                if (!spIcons->GetIconMap()->IsEmpty()) {
                    pPC->vfunc_2();
                    spIcons->FUN_140e2a670();
                }
                return 1;
            }
            else {
                MS2Ptr<ASEquipIcon> spIcon = spIcons->FUN_140e2a740(0x7a);
                if (spIcon.get() != 0) {
                    spIcons->FUN_140e2a670();
                    if (pPC->FUN_1418bd300()) {
                        MS2Ptr<ASMeratMarketEquipData> spEquip(
                            dynamic_cast<ASMeratMarketEquipData*>(spIcon->FUN_1409b9330().operator AScript*()));
                        if (spEquip == 0)
                            return 0;
                        MS2Ptr<Unk_MeratEquipEntry> spEntry = spEquip->FUN_1409b9830();
                        Unk_AvPackageKey key;
                        FUN_1418bf850(spEntry, &key);
                        MS2Ptr<CAvatarPackageEquip> spPackage = pPC->FUN_1418bd200(&key);
                        if (spPackage.get() != 0)
                            pPC->FUN_1418bc500(&key);
                    }
                    return 1;
                }
            }
        }
    }
    else {
        MS2Ptr<UIEquipIconContainer> spIcons = GetEquipIcon(nSlot);
        if (spIcons.get() != 0)
            spIcons->FUN_140e2a670();
        return 1;
    }
    return 0;
}

// @0x1412f7bc0
bool UIMeratMarketDialog::EquipPackageIcon(UIAvatarBase* pAvatar, int nSlot, int nIcon)
{
    UIAvatarPC* pPC = dynamic_cast<UIAvatarPC*>(pAvatar);
    if (pPC == 0)
        return 0;
    MS2Ptr<UIEquipIconContainer> spIcons = GetEquipIcon(nSlot);
    if (spIcons == 0)
        return 0;
    if (!pPC->FUN_1418bd300())
        return 0;
    MS2Ptr<ASEquipIcon> spIcon = spIcons->FUN_140e2a740(nIcon);
    if (spIcon == 0)
        return 0;
    MS2Ptr<ASMeratMarketEquipData> spEquip(
        dynamic_cast<ASMeratMarketEquipData*>(spIcon->FUN_1409b9330().operator AScript*()));
    if (spEquip == 0)
        return 0;
    MS2Ptr<Unk_MeratEquipEntry> spEntry = spEquip->FUN_1409b9830();
    Unk_AvPackageKey key;
    if (nIcon == 0x79)
        FUN_1418bf800(spEntry->GetItemId(), &key);
    else
        FUN_1418bf850(spEntry, &key);
    MS2Ptr<CAvatarPackageEquip> spPackage = pPC->FUN_1418bd200(&key);
    if (spPackage == 0)
        return 0;
    pPC->FUN_1418bc500(&key);
    return 1;
}

// @0x1412f7f10
void UIMeratMarketDialog::ResetPreview()
{
    m_spProduct = 0;
    m_spItem = 0;
    m_spItemData = 0;
    m_298 = 5;
    m_29c = 7;
}

// MS2-FUNCTIONAL: exe has inline early-return/kind check layout not reproduced; extra inlined temp in dynamic_cast path
// @0x1412f7f90
bool UIMeratMarketDialog::OnAvatarEquipChanged(const int* pItemId, bool* pChanged, bool* pItemMatch, bool* pHandItem)
{
    if (m_spAvatar == 0)
        return 0;
    if (m_spAvatar->FUN_1418b9ba0() != 1)
        return 0;
    MS2Ptr<UIAvatarPC> spPC(dynamic_cast<UIAvatarPC*>(m_spAvatar.operator UIAvatarBase*()));
    if (spPC.get() != 0) {
        Unk_AvPackageKey key;
        FUN_1418bf800(*pItemId, &key);
        spPC->FUN_1418bc500(&key);
        if (m_spItem.get() != 0) {
            if (m_spItem->FUN_1405276c0() == *pItemId) {
                *pItemMatch = 1;
                if (m_spItemData.operator CItemData*() != 0) {
                    if (m_spItemData->FUN_14053cd50() || m_spItemData->FUN_14053cd10())
                        *pHandItem = 1;
                }
            }
        }
    }
    *pChanged = 1;
    return 1;
}

// @0x1412f8190
void UIMeratMarketDialog::ResetModels()
{
    m_camChar.FUN_141b48530();
    m_camCube.FUN_141b485d0();
    m_camPet.FUN_141b48670();
}

// MS2-FUNCTIONAL: exe keeps extra int temps (the preview slot constants) and a 0x10 larger frame; no source form found
// @0x1412f81e0
void UIMeratMarketDialog::InitAvatars()
{
    if (m_30 == 0)
        return;
    PC* pPC = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    MS2Ptr<ASMovieClip> spCharView = m_30->FUN_1409b4560("m_charView");
    if (spCharView == 0)
        return;
    int nGender = FUN_141658e60(pPC);
    int nNotMale = nGender != 1;
    bool bFlag = true;
    MS2Ptr<UIAvatarBase> spPC(new UIAvatarPC(pPC, bFlag));
    if (spPC.get())
    {
        spPC->vfunc_1(this);
        m_spAvatarPC.AssignRaw(dynamic_cast<UIAvatarPC*>((UIAvatarBase*)spPC));
        SetPreview(0, spPC);
        if (m_spAvatarPC.get() ? true : false)
        {
            if (m_spAvatarPC->FUN_1418bd1d0() != 0)
                m_spAvatarPC->FUN_1418bd1d0()->FUN_1410885d0(
                    Delegate<void(ATL::CAtlList<MS2Ptr<CEquipItem> >*, Unk_PCEquipSet*)>(this, &UIMeratMarketDialog::OnEquipList));
        }
    }
    LoadRenderTarget();
    MS2Ptr<UIAvatarBase> spRidee(new UIAvatarRidee());
    if (spRidee.get())
    {
        spRidee->vfunc_1(this);
        SetPreview(3, spRidee);
    }
    MS2Ptr<UIAvatarBase> spMyPC(new UIAvatarPC(nNotMale, bFlag));
    if (spMyPC.get())
    {
        spMyPC->vfunc_1(this);
        m_spMyAvatarPC.AssignRaw(dynamic_cast<UIAvatarPC*>((UIAvatarBase*)spMyPC));
        SetPreview(1, spMyPC);
    }
    MS2Ptr<UIAvatarBase> spPet(new UIAvatarPet(0));
    if (spPet.get())
    {
        spPet->vfunc_1(this);
        SetPreview(4, spPet);
    }
    for (int i = 0; i < 7; i++)
    {
        Scaleform::GFx::Value vContainer = spCharView->Invoke("getContainer", i);
        if (!FUN_1409b0350(&vContainer) && !FUN_1409b0390(&vContainer))
        {
            MS2Ptr<UIEquipIconContainer> spIcons(new UIEquipIconContainer);
            if (!(spIcons == 0))
            {
                MS2Ptr<ASMovieClip> spClip(new ASMovieClip(vContainer, 2));
                spIcons->FUN_1412d6ca0(spClip);
                m_spEquipIcons[i] = spIcons;
            }
        }
    }
    MS2Ptr<ASMovieClip> spMusic = spCharView->FUN_1409b4560("m_musicControl");
    if (spMusic)
    {
        m_5b0 = spMusic->FUN_140acce30<ASButton>("m_play");
        m_5c0 = spMusic->FUN_140acce30<ASButton>("m_goStart");
        m_5d0 = spMusic->FUN_1409b4620("m_time");
        m_spSlider = spMusic->FUN_140accef0<ASSlider>("m_slider");
        m_5f0 = spMusic->FUN_1409b4560("m_playEff");
        m_5b0->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMeratMarketDialog::OnModelCheck), 0);
        m_5c0->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMeratMarketDialog::OnModelRefresh), 0);
        m_spSlider->FUN_1422ce9a0(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMeratMarketDialog::OnModelReset), 0);
    }
}

// @0x1412f9130
bool UIMeratMarketDialog::SetPreview(int nIndex, MS2Ptr<UIAvatarBase> spPreview)
{
    if (nIndex < 0 || nIndex >= 5)
        return false;
    m_spAvatars[nIndex] = spPreview;
    return true;
}

// @0x1412f91c0
void UIMeratMarketDialog::RequestLists()
{
    if (m_tabs100000.IsEmpty())
        FUN_141348530(100000, m_tabs100000);
    if (m_tabs100001.IsEmpty())
        FUN_141348530(100001, m_tabs100001);
    if (m_tabs110000.IsEmpty())
        FUN_141348530(110000, m_tabs110000);
}

// @0x1412f9270
void UIMeratMarketDialog::InitPreview()
{
    if (m_spWeaponType == 0)
    {
        PC* pOwner = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
        m_spWeaponType.AssignRaw(new UIMeratMarketCommon::WeaponType(pOwner));
    }
}

// @0x1412f9320
void UIMeratMarketDialog::SetPreviewItem(MS2Ptr<CItem> spOwner, MS2Ptr<CItemData> spData, int nSlot, int nKind, MS2Ptr<CMeratMarketProduct> spProduct)
{
    MS2Ptr<CItemData> spPrevious = m_spItemData;
    ResetPreview();
    m_spItem = spOwner;
    m_spItemData = spData;
    m_298 = nSlot;
    m_29c = nKind;
    m_spProduct = spProduct;
    if ((FUN_140166410()->FUN_14036d570(0xac) && m_spItemData->FUN_14053cd50()) || m_spItemData->FUN_14053cd10())
        FUN_140c8dac0()->FUN_140d09cf0(2);
    else
        FUN_140c8dac0()->FUN_140d09d40(2);
}

// @0x1412f9490
bool UIMeratMarketDialog::OnChangeList(ASData& data, bool bRefresh)
{
    if (m_30 == 0)
        return false;
    MS2Ptr<CMeratMarketSchCond> spCond = GetSearchCondition();
    if (spCond == 0)
        return false;
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    ASObj obj(value, 2);
    bool bSearchAll = m_250 == 8;
    if (bSearchAll)
        ApplySearchAll(spCond, obj, false);
    else
        ApplySearch(spCond, obj);
    spCond->m_3c = bRefresh;
    return true;
}

// @0x1412f9650
bool UIMeratMarketDialog::CheckMarketAccess(__int64 nSellerId)
{
    if (m_30 == 0)
        return false;
    CStringW strMessage;
    if (nSellerId == 0)
    {
        strMessage = FUN_14028de60(0x615);
    }
    else
    {
        CStringW strUnused;
        if (FUN_140939a00()->FUN_140d56db0(nSellerId) != 0)
            strMessage = FUN_14028de60(0xa02);
    }
    if (!strMessage.IsEmpty())
    {
        Unk_MmMessageBox* pBox = FUN_14151f890();
        if (pBox != 0)
            pBox->FUN_1419f82b0(strMessage);
    }
    else
    {
        FUN_140939a00()->FUN_140d54c00(nSellerId);
        return true;
    }
    return false;
}

// @0x1412f97d0
void UIMeratMarketDialog::OnClickRefreshBlueMerat()
{
    int nMinutes = 5;
    if (FUN_140d86260()->vfunc_43(2, true, 300000) == true)
        FUN_1412751b0(FUN_1409eec40(0x9e5), 20);
    else
        FUN_1412751b0(FUN_1408116a0(0x9f3, nMinutes), 20);
}

// @0x1412f98b0
void UIMeratMarketDialog::OnClickRefreshRedMerat()
{
    int nMinutes = 5;
    if (FUN_140d86260()->vfunc_43(8, true, 300000) == true)
        FUN_1412751b0(FUN_1409eec40(0x9e5), 20);
    else
        FUN_1412751b0(FUN_1408116a0(0x9f3, nMinutes), 20);
}

// @0x1412f9990
void UIMeratMarketDialog::SendRandomSaleRequest(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0)
        return;
    int nType = spProduct->m_premium.m_nType;
    if (nType == 6)
    {
        CMsTime tNow(FUN_140869440());
        __int64 nRemain = spProduct->m_premium.m_time188.Get() - tNow.Get();
        if (nRemain < 0)
            nRemain = 0;
        int nCount = spProduct->m_premium.GetRemainCount();
        COutPacket pkt(0x39, 0);
        pkt.vfunc_o10_1(0x6f);
        pkt.vfunc_o10_3(spProduct->m_premium.m_n2c);
        pkt.vfunc_o10_1(spProduct->m_premium.m_n16c);
        pkt.vfunc_o10_1(spProduct->m_premium.m_n170);
        pkt.vfunc_o10_3(nCount);
        pkt.vfunc_o10_4(nRemain);
        pkt.vfunc_o10_4(spProduct->m_premium.m_nSalePrice);
        FUN_140710590(pkt);
    }
    else if (nType == 7)
    {
        COutPacket pkt(0x39, 0);
        pkt.vfunc_o10_1(0x73);
        pkt.vfunc_o10_3(spProduct->m_premium.m_nId);
        pkt.vfunc_o10_3(spProduct->m_premium.m_n1b0);
        pkt.vfunc_o10_3(0xd67);
        FUN_140710590(pkt);
    }
    else if (nType == 8)
    {
        COutPacket pkt(0x39, 0);
        pkt.vfunc_o10_1(0x73);
        pkt.vfunc_o10_3(spProduct->m_premium.m_nId);
        pkt.vfunc_o10_3(spProduct->m_premium.m_n1b0);
        pkt.vfunc_o10_3(0xd71);
        FUN_140710590(pkt);
    }
    else
    {
        COutPacket pkt(0x39, 0);
        pkt.vfunc_o10_1(0x76);
        pkt.vfunc_o10_3(spProduct->m_premium.m_nId);
        pkt.vfunc_o10_3(spProduct->m_premium.m_n2c);
        FUN_140710590(pkt);
    }
}

// @0x1412f9d10
bool UIMeratMarketDialog::RefreshSellerList()
{
    if (m_30 == 0)
        return false;
    if (m_250 != 4)
        return false;
    Unk_MmProductMap* pProducts = &FUN_140939a00()->m_productMap;
    Unk_MmViewScope scope;
    scope.Set(m_spWeaponType);
    ASArray rows(2);
    for (POSITION pos = pProducts->GetHeadPosition(); pos != 0; pProducts->GetNext(pos))
    {
        MS2Ptr<CMeratMarketProduct> spProduct = pProducts->GetValueAt(pos);
        if (spProduct.get() != 0)
        {
            ASMeratMarketProduct row(FUN_1422db730());
            if (FillProductRow(row, spProduct, &scope) != 0)
                rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
        }
    }
    {
        MS2Ptr<AScript> spPage = GetPage(m_250);
        if (spPage.get() != 0)
            spPage->Invoke("buildItemList", Scaleform::GFx::Value(rows.FUN_1422bb870()));
    }
    return true;
}

// @0x1412f9fe0
int UIMeratMarketDialog::FillPage(int nFirst, int nLast, ASArray& rows, Unk_MmProductArray& list, Unk_MmViewScope* pScope)
{
    if (list.IsEmpty())
        return 0;
    if (nFirst < 0 || nFirst > nLast)
        return 0;
    nLast = (nFirst + 0x11 < nLast) ? nFirst + 0x11 : nLast;
    nLast = ((int)list.GetCount() - 1 < nLast) ? (int)list.GetCount() - 1 : nLast;
    for (int i = nFirst; i <= nLast; i++)
    {
        MS2Ptr<CMeratMarketProduct> spProduct = list[i];
        if (spProduct == 0)
            continue;
        ASMeratMarketProduct row(FUN_1422db730());
        if (FillProductRow(row, spProduct, pScope) != 0)
            rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
    }
    return (int)list.GetCount();
}

// @0x1412fa200
int UIMeratMarketDialog::FillProducts(ASArray& rows, Unk_MmProductArray& list, Unk_MmViewScope* pScope)
{
    size_t nCount = list.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CMeratMarketProduct> spProduct = list[i];
        if (spProduct == 0)
            continue;
        ASMeratMarketProduct row(FUN_1422db730());
        if (FillProductRow(row, spProduct, pScope) != 0)
            rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
    }
    return (int)nCount;
}

// @0x1412fa7b0
void UIMeratMarketDialog::BuildPage(int nFirst, int nLast)
{
    if (m_30 == 0)
        return;
    MS2Ptr<AScript> spPage = GetPage(m_250);
    if (spPage == 0)
        return;
    ASArray rows(2);
    Unk_MmViewScope scope(m_spWeaponType);
    Unk_MmProductArray& list = GetProductList(m_254);
    FillPage(nFirst, nLast, rows, list, &scope);
    spPage->FUN_140bd2cb0("buildPage", rows);
}

// MS2-FUNCTIONAL: exe frame is 8 bytes larger (one more pointer local) around the seller shop lookup; no source form found
// @0x1412fa950
void UIMeratMarketDialog::ShowSellerShop(__int64 nSellerId, int bForce)
{
    if (m_30 == 0)
        return;
    MS2Ptr<Unk_MmSellerShop> spShop = FUN_140939a00()->FUN_140d56cc0(nSellerId);
    if (spShop == 0)
        return;
    Unk_MmSellerShop* pShop = spShop.operator->();
    if (pShop->m_products.IsEmpty() && bForce == 0)
    {
        FUN_140939a00()->FUN_140d54ce0(nSellerId);
    }
    else
    {
        ASArray rows(2);
        Unk_MmViewScope scope(m_spWeaponType);
        int nCount = FillProducts(rows, pShop->m_products, &scope);
        MS2Ptr<AScript> spPage = GetPage(5);
        if (spPage.get() != 0)
            spPage->FUN_1413128f0("buildSellerItemList", FUN_140719530(nSellerId), Scaleform::GFx::Value(rows.FUN_1422bb870()), nCount, 1, L"");
    }
}

// MS2-FUNCTIONAL: exe takes the checker pointer through a temp MS2Ptr reference (0x10 larger frame); no source form found
// @0x1412fac20
void UIMeratMarketDialog::ShowSeller(__int64 nSellerId, const CStringW& strName, int bForce)
{
    if (m_30 == 0)
        return;
    if (strName.IsEmpty())
    {
        ShowSellerShop(nSellerId, bForce);
    }
    else
    {
        CStringW strFiltered;
        CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker();
        if (pChecker != 0)
        {
            CStringW strMessage;
            if (pChecker->FUN_1402261e0(strName, strMessage) != 0)
            {
                MS2Ptr<AScript> spPage = GetPage(5);
                if (spPage.get() != 0)
                {
                    CStringW strNotice = FUN_14052bd00(0xa13, strMessage);
                    ASArray rows(2);
                    spPage->FUN_141312a70("buildSellerItemList", FUN_140719530(nSellerId), Scaleform::GFx::Value(rows.FUN_1422bb870()), 0, 1, CStringW(strName));
                    spPage->Invoke("updateNoticeText", CStringW(strNotice));
                    return;
                }
            }
        }
        MS2Ptr<Unk_MmSellerShop> spShop = FUN_140939a00()->FUN_140d56cc0(nSellerId);
        if (spShop == 0)
            return;
        Unk_MmProductArray& products = spShop.operator->()->m_products;
        if (!products.IsEmpty() || bForce != 0)
        {
            ASArray rows(2);
            Unk_MmProductArray matches;
            size_t nCount = products.GetCount();
            for (int i = 0; i < nCount; i++)
            {
                MS2Ptr<CMeratMarketProduct> spProduct = products[i];
                if (spProduct.get() != 0)
                {
                    const wchar_t* szName = strName;
                    if (spProduct->m_ugc.m_look.m_str28.Find(szName, 0) != -1)
                        matches.Add(spProduct);
                }
            }
            Unk_MmViewScope scope(m_spWeaponType);
            int nFound = FillProducts(rows, matches, &scope);
            MS2Ptr<AScript> spPage = GetPage(5);
            if (spPage.get() != 0)
            {
                spPage->FUN_141312a70("buildSellerItemList", FUN_140719530(nSellerId), Scaleform::GFx::Value(rows.FUN_1422bb870()), nFound, 1, CStringW(strName));
                if (nFound == 0)
                {
                    CStringW strEmpty = FUN_14052bd00(0xa10, strName);
                    spPage->Invoke("updateNoticeText", CStringW(strEmpty));
                }
            }
        }
        else
        {
            FUN_140939a00()->FUN_140d54ce0(nSellerId);
        }
    }
}

// @0x1412fb410
void UIMeratMarketDialog::BuildSellerList(ASArray& rows)
{
    Unk_MmSellerMap* pSellers = &FUN_140939a00()->m_sellers;
    if (pSellers->IsEmpty())
        return;
    CStringW strCaption = FUN_14028de60(0x9de);
    for (POSITION pos = pSellers->GetHeadPosition(); pos != 0; pSellers->GetNext(pos))
    {
        MS2Ptr<CUgcMarketSeller> spSeller = pSellers->GetValueAt(pos);
        if (spSeller.get() != 0)
        {
            ASObj row(2);
            if (BuildSellerRow(row, spSeller, strCaption) != 0)
                rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
        }
    }
}

// @0x1412fb590
void UIMeratMarketDialog::AddTab(ASArray& tabs, const CStringA& strName, const CStringW& strLabel, const CStringA& strTooltip, const CStringA& strPageCls, int nIndex, const CStringA& strClsName)
{
    ASObj tab(2);
    if (strClsName.IsEmpty())
        tab.FUN_1409c0dc0("clsName", "UIMeratMarketDialog_tab");
    else
        tab.FUN_1407cba60("clsName", strClsName);
    tab.FUN_1407cba60("name", strName);
    tab.FUN_1407cbb20("label", strLabel);
    tab.FUN_1407cba60("tooltip", strTooltip);
    tab.FUN_1407cb9c0("tabIndex", nIndex);
    tab.FUN_1407cba60("pageCls", strPageCls);
    tab.FUN_1407cbbe0("visible", nIndex != 8);
    tabs.FUN_1422bc050(Scaleform::GFx::Value(tab.FUN_1422bb870()));
}

// @0x1412fb7e0
void UIMeratMarketDialog::AddEventTab(ASArray& tabs)
{
    if (m_2f1 == false)
        ShowHelper(true);
    m_2f1 = true;
    AddTab(tabs, TabName(7), L"$s_meratmarket_title_limited", "$s_meratmarket_tooltip_tab_limited", "UIMeratMarketDialog_limited", 7, "UIMeratMarketDialog_tab_limited");
}

// @0x1412fb930
void UIMeratMarketDialog::AddSearchItem(ASDataProvider& provider, const CStringW& strLabel, int nTab)
{
    ASObj item(2);
    item.FUN_1407cbb20("label", strLabel);
    item.FUN_1407cb9c0(s_strTabIndex, nTab);
    provider.FUN_1422bc050(Scaleform::GFx::Value(item.FUN_1422bb870()));
}

// @0x1412fba20
void UIMeratMarketDialog::AddJobItem(ASArray& list, const CStringW& strLabel, int nJob)
{
    ASObj item(2);
    item.FUN_1407cbb20("label", strLabel);
    item.FUN_1407cb9c0(s_strJobCode, nJob);
    list.FUN_1422bc050(Scaleform::GFx::Value(item.FUN_1422bb870()));
}

// @0x1412fbb10
void UIMeratMarketDialog::BuildTabs(ASArray& tabs)
{
    bool bBlue = FUN_1406a56f0();
    bool bRed = FUN_1406a5740();
    bool bUgc = FUN_1406a5880();
    bool bEvent = HasEventTab();
    bool bHome = bBlue;
    if (FUN_140166410()->FUN_14036d570(0x108))
    {
        if (bHome)
            AddTab(tabs, TabName(0), L"", "$s_meratmarket_tooltip_tab_home", "UIMeratMarketDialog_home_newbm", 0, "UIMeratMarketDialog_tab_home");
        if (bBlue)
            AddTab(tabs, TabName(1), L"$s_meratmarket_title_blue", "$s_meratmarket_tooltip_tab_premium", "UIMeratMarketDialog_shop", 1, "");
        AddTab(tabs, TabName(6), L"", "$s_meratmarket_tooltip_tab_basket", "UIMeratMarketDialog_basket", 6, "");
        if (bRed)
            AddTab(tabs, TabName(2), L"$s_meratmarket_title_red", "$s_meratmarket_tooltip_tab_red", "UIMeratMarketDialog_shop", 2, "");
        if (bEvent)
        {
            AddEventTab(tabs);
            m_2f2 = true;
        }
        if (bUgc)
        {
            AddTab(tabs, TabName(3), L"$s_meratmarket_title_designers", "$s_meratmarket_tooltip_tab_designers", "UIMeratMarketDialog_shop", 3, "");
            AddTab(tabs, TabName(4), L"$s_meratmarket_title_myshop", "$s_meratmarket_tooltip_tab_myshop", "UIMeratMarketDialog_myshop", 4, "");
            AddTab(tabs, TabName(5), L"", "$s_meratmarket_tooltip_tab_bookmark", "UIMeratMarketDialog_bookmark", 5, "");
        }
    }
    else
    {
        if (bHome)
            AddTab(tabs, TabName(0), L"", "$s_meratmarket_tooltip_tab_home", "UIMeratMarketDialog_home", 0, "UIMeratMarketDialog_tab_home");
        if (bBlue)
            AddTab(tabs, TabName(1), L"$s_meratmarket_title_blue", "$s_meratmarket_tooltip_tab_premium", "UIMeratMarketDialog_shop", 1, "");
        AddTab(tabs, TabName(6), L"", "$s_meratmarket_tooltip_tab_basket", "UIMeratMarketDialog_basket", 6, "");
        if (bRed)
            AddTab(tabs, TabName(2), L"$s_meratmarket_title_red", "$s_meratmarket_tooltip_tab_red", "UIMeratMarketDialog_shop", 2, "");
        if (bUgc)
        {
            AddTab(tabs, TabName(3), L"$s_meratmarket_title_designers", "$s_meratmarket_tooltip_tab_designers", "UIMeratMarketDialog_shop", 3, "");
            AddTab(tabs, TabName(4), L"$s_meratmarket_title_myshop", "$s_meratmarket_tooltip_tab_myshop", "UIMeratMarketDialog_myshop", 4, "");
            AddTab(tabs, TabName(5), L"", "$s_meratmarket_tooltip_tab_bookmark", "UIMeratMarketDialog_bookmark", 5, "");
        }
        if (bEvent)
        {
            AddEventTab(tabs);
            m_2f2 = true;
        }
    }
    m_250 = DefaultTab();
    AddTab(tabs, TabName(8), L"", "", "UIMeratMarketDialog_search", 8, "");
}

// @0x1412fcda0
void UIMeratMarketDialog::BuildSearchProvider(ASDataProvider& provider)
{
    bool bRed = FUN_1406a5740();
    bool bUgc = FUN_1406a5880();
    bool bBlue = FUN_1406a56f0();
    AddSearchItem(provider, L"$s_meratmarket_dropdown_search_all", 0);
    if (bBlue)
        AddSearchItem(provider, L"$s_meratmarket_dropdown_search_blue", 1);
    if (bRed)
        AddSearchItem(provider, L"$s_meratmarket_dropdown_search_red", 2);
    if (bUgc)
        AddSearchItem(provider, L"$s_meratmarket_dropdown_search_designers", 3);
}

// MS2-FUNCTIONAL: temp/frame layout differs from exe (0x10 frame, local order)
// @0x1412fcee0
void UIMeratMarketDialog::BuildJobList(ASArray& list, int nSelectedJob, int& nSelectedIndex)
{
    ATL::CAtlArray<int> jobs;
    FUN_140222be0(jobs);
    PC* pPC = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC != 0)
        FUN_141654700(pPC);
    nSelectedIndex = 0;
    AddJobItem(list, L"$s_blackmarket_dropdown_joball", 200);
    size_t nCount = jobs.GetCount();
    int nIndex = list.FUN_1422bc5d0();
    for (int i = 0; i < (int)nCount; i++)
    {
        int nJob = jobs[i];
        if (nJob != 0 && nJob != 1)
        {
            CStringW strText = FUN_1401a9d70()->FUN_141811980(6, FUN_1401d7a50()->FUN_140644bb0(nJob));
            CStringW* pName = &strText;
            AddJobItem(list, *pName, nJob);
            if (nJob == nSelectedJob)
                nSelectedIndex = nIndex;
            nIndex++;
        }
    }
}

// @0x1412fd0c0
void UIMeratMarketDialog::SetGenderData(ASObj& data, int nGender)
{
    data.FUN_1407cb9c0("male", 0);
    data.FUN_1407cb9c0("female", 1);
    data.FUN_1407cb9c0("all", 2);
    data.FUN_1407cb9c0("selectGender", nGender);
}

// @0x1412fd140
void UIMeratMarketDialog::LoadSearchResult(MS2Ptr<AScript> spScript, int nKind)
{
    Delegate<void(AScript&)> onLoaded(this, &UIMeratMarketDialog::OnSearchLoaded);
    if (nKind == 1)
        FUN_141348cf0(m_tabs100000, spScript, 100000, &onLoaded);
    else if (nKind == 2)
        FUN_141348cf0(m_tabs100001, spScript, 100001, &onLoaded);
    else if (nKind == 3)
        FUN_141348cf0(m_tabs110000, spScript, 110000, &onLoaded);
}

// @0x1412fd2e0
void UIMeratMarketDialog::OnSearchLoaded(AScript& data)
{
    static_cast<ASObj&>(data).FUN_1407cbbe0("showFoldArrow", 1);
}

// @0x1412fd310
void UIMeratMarketDialog::SetMarketInitData(ASObj& data, int nPremium)
{
    FUN_140ec0700(&data, nPremium);
}

// @0x1412fd340
void UIMeratMarketDialog::SetGenderSelection(ASObj& data, bool bUseMine, int nGender)
{
    ASObj genderData(2);
    if (bUseMine)
    {
        PC* pPC = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPC != 0)
            nGender = FUN_141658e60(pPC);
    }
    SetGenderData(genderData, nGender);
    data.FUN_1409adbe0("genderData", Scaleform::GFx::Value(genderData.FUN_1422bb870()));
}

// @0x1412fd420
void UIMeratMarketDialog::FillJobDropDown(ASObj& data, bool bUseMyJob, int nJob)
{
    ASDataProvider list(2);
    int nSelected = 0;
    if (bUseMyJob)
    {
        PC* pPC = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPC != 0)
            nJob = FUN_141654700(pPC);
    }
    BuildJobList(list, nJob, nSelected);
    data.FUN_1409adbe0("dpDropDownJob", Scaleform::GFx::Value(list.FUN_1422bb870()));
    data.FUN_1407cb9c0("dpDropDownJobSelectedIndex", nSelected);
}

// MS2-FUNCTIONAL: block-ref kind temporaries (stack slot of the kind local) differ in the OnClickCalculate/AddNewItem branches
// @0x1412fd530
int UIMeratMarketDialog::OnCommandMyShop(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("onClickStopSale", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnClickCancelSale(data);
        return 1;
    }
    else if (_stricmp("onClickReSale", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnClickRemoveSale(data);
        return 1;
    }
    else if (_stricmp("onClickRemove", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnClickRegisterSale(data);
        return 1;
    }
    else if (_stricmp("onClickPassSuccess", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnClickSaleCommand(data);
        return 1;
    }
    else if (_stricmp("onClickPassFailed", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnClickSaleCommand(data);
        return 1;
    }
    else if (_stricmp("OnClickHistory", szName) == 0)
    {
        OnShowHistory();
        return 1;
    }
    else if (_stricmp("OnClickCalculate", szName) == 0)
    {
        {
            Unk_MeratBlockPtr block = FUN_140a6a830()->FUN_140a2f620(0x23);
            if (block.FUN_1401cb3d0() != 0)
            {
                FUN_140a2ff20(&block, 0x23, 0);
                return 0;
            }
        }
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            if (data.FUN_1422b8a90())
            {
                if (FUN_140d56470(FUN_140939a00()) > 0)
                    FUN_140939a00()->FUN_140d54ac0();
            }
            else
            {
                FUN_140939a00()->FUN_140d566f0(0);
            }
        }
        return 1;
    }
    else if (_stricmp("OnClickAddNewItem", szName) == 0)
    {
        if (FUN_140ebc4a0() == 0)
            return 1;
        {
            int nKind = 0x21;
            Unk_MeratBlockPtr block = FUN_140a6a830()->FUN_140a2f620(nKind);
            if (block.FUN_1401cb3d0() != 0)
            {
                FUN_140a2ff20(&block, nKind, 0);
                return 1;
            }
        }
        FUN_141adc530(FUN_1403ed2b0(), 0x4ec5);
        return 1;
    }
    return 0;
}

// @0x1412fd9d0
int UIMeratMarketDialog::OnCommandBasket(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("onClickBasketItem", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnClickProductLink(data);
        return 1;
    }
    else if (_stricmp("onClickRemoveBasketItem", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnRemoveBasketItem(data);
        return 1;
    }
    else if (_stricmp("onClickBuyBasketItem", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnBuyBasketItem(szName, data);
        return 1;
    }
    else if (_stricmp("onClickBuyBasketItemAll", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnBuySelected(szName, data);
        return 1;
    }
    else if (_stricmp("onClickGiftBasketItemAll", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnBuyGiftSelected(szName, data);
        return 1;
    }
    return 0;
}

// @0x1412fdcf0
int UIMeratMarketDialog::OnCommandBookmark(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnClickRemoveSeller", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnRemoveSeller(data);
        return 1;
    }
    else if (_stricmp("OnChangeIndexSeller", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnSellerInfo(data);
        return 1;
    }
    else if (_stricmp("OnGetSellerProductList", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnGetSellerProductList(data);
        return 1;
    }
    else if (_stricmp("OnRightClickSeller", szName) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            OnRightClickSeller(data);
        return 1;
    }
    return 0;
}

// @0x1412fdf10
int UIMeratMarketDialog::OnCommandLimited(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return 0;
}

// MS2-FUNCTIONAL: stack-slot/frame layout of the logger string temporaries differs
// @0x1412fdf30
void UIMeratMarketDialog::OnChangeTab(ASData& data)
{
    if (!(m_30 == 0))
    {
        int nTab = data.FUN_1422b8a10();
        int nPrevTab = m_250;
        m_250 = nTab;
        ShowUgcTerms(nPrevTab, nTab);
        int nCount = GetTabCount(nTab);
        if (nCount == 0)
            LoadTab(nTab);
        if (nPrevTab == 7 && !HasEventTab())
        {
            m_30->Invoke("setVisibleLimitedTab", false);
            m_2f2 = false;
        }
        if (nTab == 0)
        {
            SelectCategory(ShopKindOf(0), 10);
        }
        else if (nTab == 7 && nCount != 0)
        {
            FUN_140939a00()->FUN_140d543c0(2);
        }
        if (nPrevTab == 4 && nTab != 4)
        {
            FUN_140939a00()->FUN_140d566f0(0);
            RefreshMyShop();
        }
        if (FUN_140d8ee90() != 0)
        {
            switch (nTab)
            {
            case 0:
                FUN_140a1f970(FUN_140d8ee90(), "dialog_open", "merat_home");
                break;
            case 1:
                FUN_140a1f970(FUN_140d8ee90(), "dialog_open", "merat_premium");
                break;
            case 3:
                FUN_140a1f970(FUN_140d8ee90(), "dialog_open", "merat_designers");
                break;
            case 4:
                FUN_140a1f970(FUN_140d8ee90(), "dialog_open", "merat_myshop");
                break;
            case 5:
                FUN_140a1f970(FUN_140d8ee90(), "dialog_open", "merat_bookmark");
                break;
            case 6:
                FUN_140a1f970(FUN_140d8ee90(), "dialog_open", "merat_basket");
                break;
            }
        }
    }
}

// @0x1412fe370
void UIMeratMarketDialog::OnChangeModel(ASData& data)
{
    if (m_spAvatarPC == 0)
    {
        InitAvatars();
    }
    else
    {
        int nIndex = data.FUN_1422b8a10();
        UIAvatarBase* pPreview = GetPreview(nIndex);
        MS2Ptr<CItemData> spData(0);
        if ((m_spItem.get() != 0 ? true : false) && m_298 == nIndex)
            spData = m_spItemData;
        int nKind = SlotKindOf(nIndex, spData);
        ShowAvatarItem(pPreview, nKind, spData, m_spAvatar.get() != pPreview);
    }
}

// @0x1412fe520
void UIMeratMarketDialog::OnChangePage(ASData& data)
{
    int nFirst = data.FUN_1422b8a10();
    int nCount = data.FUN_1422b8a10();
    BuildPage(nFirst, nFirst + nCount);
}

// MS2-FUNCTIONAL: bool-to-uint temp slot differs
// @0x1412fe580
void UIMeratMarketDialog::OnChangePageRequest(ASData& data)
{
    int nPage = data.FUN_1422b8a10();
    int nDirection = data.FUN_1422b8a10();
    if (!FUN_1406a5040(m_254) && m_spSearch.get() != 0)
    {
        m_spSearch->m_30 = nPage;
        unsigned int nDescending = (nDirection < 0) ? 1 : 0;
        m_spSearch->m_44 = nDescending;
        m_spSearch->m_3c = 0;
        RequestPending(m_spSearch->m_18, m_250 == 8);
    }
}

// @0x1412fe6a0
void UIMeratMarketDialog::OnCheckPreviewColoring(ASData& data)
{
    bool bColoring = data.FUN_1422b8a90();
    m_bPreviewColoring = bColoring;
    if (m_spAvatarPC.get() != 0)
        m_spAvatarPC->FUN_1418bc280(bColoring);
    if (m_spMyAvatarPC.get() != 0)
        m_spMyAvatarPC->FUN_1418bc280(bColoring);
}

// @0x1412ff0b0
void UIMeratMarketDialog::OnSelectItem(ASData& data)
{
    if (m_spModelView == 0)
        return;
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    UIMeratMarketDialogUtil::ASOutData out(value, FUN_1422db730());
    if (m_250 == 7)
    {
        OnSelectLimited(out);
    }
    else
    {
        MS2Ptr<ASMeratMarketProductBase> spProduct = out.FUN_140ec28b0();
        if (spProduct == 0)
            return;
        Unk_MeratProductKey key;
        spProduct->FUN_1409bc6a0(reinterpret_cast<Unk_MeratOid*>(&key));   // Unk_MeratOid is the same {premium id, ugc id} pair
        OpenProductByKey(key, IsCurrentShopTab());
    }
}

// @0x1412ff700
void UIMeratMarketDialog::OnGetSearchAttrVisible(ASData& data)
{
    int nCategory = data.FUN_1422b8a10();
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    bool bGender = false;
    bool bJob = false;
    int nList = CurrentListId(m_250);
    FUN_140ec1da0(nList, nCategory, &bGender, &bJob);
    ASObj obj(value, 2);
    obj.FUN_1407cbbe0("genderVisible", bGender);
    obj.FUN_1407cbbe0("jobVisible", bJob);
}

// MS2-FUNCTIONAL: stack slots of the MS2Ptr<UIAvatarPC>/slot temporaries are swapped; the else-branch layout differs
// @0x1412ff7f0
void UIMeratMarketDialog::OnClickShowMyEquip()
{
    if (m_spAvatar.get() != 0)
    {
        MS2Ptr<UIAvatarPC> spPC(dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar));
        if (spPC.get() != 0)
        {
            ApplyPreviewChanges(true);
            spPC->vfunc_3();
            m_dirty.SetFlag(8);
        }
    }
    ResetPreview();
    int nIndex = FindPreview(m_spAvatar.get());
    int nKind = SlotKindOf(nIndex, MS2Ptr<CItemData>(0));
    MS2Ptr<UIEquipIconContainer> spSlot = GetEquipIcon(nKind);
    if (!(spSlot == 0))
        spSlot->FUN_140e2a670();
}

// MS2-FUNCTIONAL: stack slots of the MS2Ptr<UIAvatarPC>/slot temporaries are swapped; the else-branch layout differs
// @0x1412ff9a0
void UIMeratMarketDialog::OnClickUnequipAll()
{
    if (m_spAvatar.get() != 0)
    {
        MS2Ptr<UIAvatarPC> spPC(dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar));
        if (spPC.get() != 0)
        {
            ApplyPreviewChanges(true);
            spPC->FUN_1418bbe40();
            m_dirty.SetFlag(8);
        }
    }
    ResetPreview();
    int nIndex = FindPreview(m_spAvatar.get());
    int nKind = SlotKindOf(nIndex, MS2Ptr<CItemData>(0));
    MS2Ptr<UIEquipIconContainer> spSlot = GetEquipIcon(nKind);
    if (!(spSlot == 0))
        spSlot->FUN_140e2a670();
}

// @0x1412ffb40
void UIMeratMarketDialog::OnClickBuyMerat()
{
    FUN_140d86260()->vfunc_45();
}

// MS2-FUNCTIONAL: frame 0x20 larger (string temporaries of the two notices / EH temporaries differ)
// @0x1413000d0
void UIMeratMarketDialog::OnClickRandomSalePick(const CStringA& strName, ASData& data)
{
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    UIMeratMarketDialogUtil::ASClickOutData out(value, FUN_1422db730());
    MS2Ptr<ASMeratMarketProductBase> spOut = out.FUN_140ec28b0();
    if (spOut == 0)
        return;
    {
        Unk_MeratProductKey key;
        spOut->FUN_1409bc6a0(reinterpret_cast<Unk_MeratOid*>(&key));   // Unk_MeratOid is the same {premium id, ugc id} pair
        MS2Ptr<CMeratMarketProduct> spProduct = FindProduct(key, CurrentSearchId(), IsCurrentShopTab());
        if (!(spProduct == 0))
        {
            if (spProduct->m_premium.m_nType != 8 && spProduct->m_premium.m_nType != 7)
            {
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_meratmarket_error_random_create_fail")), 1, 1);
                return;
            }
            if (!spProduct->m_premium.FUN_1406a0090())
            {
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_meratmarket_error_random_already_exist")), 1, 1);
            }
            else
            {
                COutPacket pkt(0x39, 0);
                pkt.vfunc_o10_1(0x72);
                pkt.vfunc_o10_3(spProduct->m_premium.m_nId);
                pkt.vfunc_o10_1(spProduct->m_premium.m_nType);
                FUN_140710590(pkt);
            }
        }
    }
}

// @0x141301260
void UIMeratMarketDialog::OnClickBookMark(ASData& data)
{
    unsigned __int64 nId = FUN_140718350(data.FUN_1422b8d30());
    if (nId > 0) {
        if (FUN_140939a00()->FUN_140d56db0(nId) != 0)
            FUN_140d73aa0(FUN_14028de60(0xa02), 0, 0, CStringW(L""));
        else
            FUN_140939a00()->FUN_140d54c00(nId);
    }
}

// @0x141301360
void UIMeratMarketDialog::OnClickRecipe(ASData& data)
{
    if (m_30 == 0)
        return;
    CStringW strKey = FUN_14016a730(data.FUN_1422b8d30(), 0);
    unsigned nItemId = FUN_1407181d0(data.FUN_1422b8d30());
    float fX = data.FUN_1422b8c10();
    float fY = data.FUN_1422b8c10();
    Unk_MeratProductKey key;
    key.FUN_1409c1640(CStringW(strKey));
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0 || spItem->FUN_14053dd30() <= 0)
        return;
    MS2Ptr<ASDialog> spDialog(m_90);
    if (spDialog == 0)
        return;
    MS2Ptr<ASMovieClip> spView = m_30->FUN_1409b4560("m_charView");
    if (spView == 0)
        return;
    float fDlgX = 0.0f;
    float fDlgY = 0.0f;
    spDialog->FUN_1422c0f60(&fDlgX, &fDlgY);
    spView->FUN_1422c0f60(&fX, &fY);
    fX = fDlgX + 90.0f;
    fY = fDlgY + 240.0f;
    Unk_MeratRecipeDialog* pDialog = FUN_1412dd5a0(0x4ecb);
    if (pDialog != 0) {
        pDialog->FUN_1412db660(spItem->FUN_14053dd30(), fX, fY);
        if (pDialog->vfunc_55() == 0)
            pDialog->FUN_1412db6c0();
        else
            FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4ecb);
    }
}

// @0x141301710
void UIMeratMarketDialog::OnClickPreview(ASData& data)
{
    CStringW strKey = FUN_14016a730(data.FUN_1422b8d30(), 0);
    unsigned nItemId = FUN_1407181d0(data.FUN_1422b8d30());
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0 || spItem->function.name != L"UGCMapPackage")
        return;
    UIInteriorPreviewDialog* pDialog = FUN_141312450(0x4ee3);
    if (pDialog != 0)
        pDialog->FUN_140f4cd90(nItemId);
}

// @0x141301860
void UIMeratMarketDialog::OnClickSearchAll(ASData& data)
{
    MS2Ptr<CMeratMarketSchCond> spCond = GetSearchCondition();
    if (spCond == 0)
        return;
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    ASObj obj(value, 2);
    ApplySearchAll(spCond, obj, true);
    ASObj tab(2);
    m_30->Invoke("changeTabToSearch", tab.FUN_1422bb870());
}

// MS2-FUNCTIONAL: frame 0x20 bigger than the exe (temp slot layout not found)
// @0x1413019e0
void UIMeratMarketDialog::OnClickBasket(ASData& data)
{
    Scaleform::GFx::Value vSlot = data.FUN_1422b9260();
    Scaleform::GFx::Value vProduct = data.FUN_1422b9260();
    ASObj objProduct(vProduct, FUN_1422db730());
    ASObj objSlot(vSlot, FUN_1422db730());
    Unk_MeratProductKey key;
    CStringW strOid;
    objSlot.FUN_1422baad0("productOID", strOid);
    key.FUN_1409c1640(CStringW(strOid));
    __int64 nSeller = 0;
    if (m_250 == 5)
        nSeller = CurrentSearchId();
    bool bShop = IsCurrentShopTab();
    MS2Ptr<CMeratMarketProduct> spProduct = FindProduct(key, nSeller, bShop);
    if (spProduct == 0)
        return;
    if (spProduct->IsUgc() != 0) {
        CUgcMarketProduct* pUgc = &spProduct->m_ugc;
        if (pUgc->FUN_140896310() != 0) {
            if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x56) != 0) {
                FUN_141275260(0x2f7, 1, 1);
                return;
            }
        }
        Unk_McOwner owner;
        owner.FUN_1409aff60();
        owner.m_pAccount = (void*)DAT_143ab2820;
        owner.m_nType = DAT_143ab2830;
        owner.m_pCharacter = (void*)DAT_143ab2838;
        owner.m_p18 = (void*)(__int64)DAT_143ab2834;
        if (FUN_140896230(pUgc, &owner) != 0) {
            FUN_140d73bc0(0xa14, 0, 0, CStringW(L""));
            return;
        }
    }
    if (spProduct->HasLimit() != 0) {
        FUN_140d73bc0(0xa16, 0, 0, CStringW(L""));
        return;
    }
    if (FUN_140166410()->FUN_14036e510() == false) {
        if (spProduct->IsUgc() != 0) {
            if (spProduct->m_ugc.FUN_140896310() != 0) {
                CStringW strKey(L"s_meratmarket_error_add_basket_by_music_score");
                FUN_140d73aa0(FUN_14028b8e0(strKey), 0, 0, CStringW(L""));
                return;
            }
        }
    }
    if (FUN_140939a00()->m_basket.FUN_140d66b20() < 0x10) {
        if (spProduct->IsUgc() == 0) {
            if (spProduct->m_premium.HasSubProducts() != 0) {
                UIMarketBillDialog* pDialog = FUN_140b09580(0x4f17);
                if (pDialog == 0)
                    return;
                MS2Ptr<TMeratMarketBillDataParam> spParam = CreateBillParam("OnClickBasket", 4, 2);
                if (spParam == 0)
                    return;
                ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
                {
                    MS2Ptr<ASMeratMarketBuyBillData> spBill(new ASMeratMarketBuyBillData());
                    spBill->FUN_1409ab940(vSlot);
                    FUN_1409b03d0(spBill.operator->(), nSeller);
                    int nCurrency = FUN_14069c3e0(spProduct->GetPayCurrency());
                    FUN_1409ac360(spBill.operator->(), spProduct, 0, nCurrency);
                    MS2Ptr<ASBillData> spRow(spBill);
                    bills.Add(spRow);
                }
                MS2Ptr<TMarketBillDataParam> spBase = spParam;
                pDialog->FUN_140ea7770(spBase);
                FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4f17);
                return;
            }
        }
        FUN_140939a00()->FUN_140d58260(spProduct, nSeller);
    } else {
        int nMax = 0x10;
        FUN_1412751f0(FUN_1408116a0(0xa21, nMax), 1, 1);
    }
}

// @0x141302490
void UIMeratMarketDialog::OnClickBanner(ASData& data)
{
    CStringA strName = data.FUN_1422b8d30();
    MS2Ptr<ShopBannerInfo> spBanner = m_banner.FUN_1413480a0(strName);
    if (spBanner == 0)
        return;
    OpenBanner(spBanner->m_nKind, spBanner->m_strName3);
}

// @0x141302560
void UIMeratMarketDialog::OnClickStarShop()
{
    if (m_30 == 0)
        return;
    FUN_1413499b0(8);
}

// MS2-FUNCTIONAL: epilogue/cleanup duplication differs by 5 bytes (case 2 path)
// @0x1413025a0
void UIMeratMarketDialog::OnClickExtraButton(ASData& data)
{
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    UIMeratMarketDialogUtil::ASClickOutData click(value, FUN_1422db730());
    MS2Ptr<ASMeratMarketProductBase> spBase = click.FUN_140ec28b0();
    if (spBase == 0)
        return;
    Unk_MeratOid key;
    spBase->FUN_1409bc6a0(&key);
    MS2Ptr<CMeratMarketProduct> spProduct = FindProduct(key, 0, IsCurrentShopTab());
    if (spProduct == 0)
        return;
    if (spProduct->m_premium.FUN_1406a1ee0() == 0) {
        int nItemId = spProduct->m_premium.m_nItemId;
        int nCoinItem = FUN_14052d230()->FUN_14059e6a0(nItemId);
        if (nCoinItem == 0)
            return;
        if (FUN_1403ed2b0()->FUN_141adc7f0((eUIClassID)0x4e3b) == 0)
            return;
        FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4e3b);
        COutPacket packet(0x65, 0);
        packet.Encode1(10);
        packet.Encode1(1);
        packet.Encode4(nCoinItem);
        FUN_140710590(packet);
        return;
    } else {
        int nType = spProduct->m_premium.FUN_1406a1ee0();
        if (nType == 1) {
            FUN_1409c1740()->FUN_140a8b290();
        } else if (nType == 2) {
            UIWebBrowser* pBrowser = FUN_140c43790(0x4e6a);
            if (pBrowser == 0)
                return;
            CStringA strUrl = spProduct->m_premium.FUN_1406a1f00();
            if (strUrl.IsEmpty())
                return;
            pBrowser->FUN_14135ec00(spProduct->m_premium.FUN_1406a1f00(), true);
        }
    }
}

// @0x1413029f0
void UIMeratMarketDialog::OnProductMessage(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    if (params.ArgCount == 0)
        return;
    ASObj obj(params.pArgs[0], 2);
    if (obj.FUN_1422ba9a0())
        return;
    Unk_MeratOid key;
    CStringW strOid;
    obj.FUN_1422baad0("productOID", strOid);
    key.FUN_1409c1640(CStringW(strOid));
    __int64 nSeller = CurrentSearchId();
    MS2Ptr<CMeratMarketProduct> spProduct = FindProduct(key, nSeller, IsCurrentShopTab());
    FUN_140ec0b50(spProduct);
}

// @0x141302ba0
void UIMeratMarketDialog::OnProductMessageHouse(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    if (params.ArgCount == 0)
        return;
    Unk_MeratOid key;
    CStringW strOid;
    ASObj obj(params.pArgs[0], 2);
    if (obj.FUN_1422ba9a0())
        return;
    obj.FUN_1422baad0("productOID", strOid);
    key.FUN_1409c1640(CStringW(strOid));
    __int64 nSeller = CurrentSearchId();
    MS2Ptr<CMeratMarketProduct> spProduct = FindProduct(key, nSeller, IsCurrentShopTab());
    if (spProduct == 0 || spProduct->m_ugc.FUN_140896350() == 0)
        return;
    ShowModelHouse(spProduct);
}

// @0x141302db0
void UIMeratMarketDialog::OnModelHouse(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_spProduct == 0 || m_spProduct->m_ugc.FUN_140896350() == 0)
        return;
    ShowModelHouse(m_spProduct);
}

// MS2-FUNCTIONAL: two extra delegate temp slots in the exe frame
// @0x141302e50
void UIMeratMarketDialog::ShowModelHouse(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (FUN_1409670e0()->FUN_1410c3650() == 2) {
        CStringW strAlready(L"s_meratmarket_already_in_modelhouse");
        FUN_1412752d0(strAlready, 1);
        return;
    }
    if (spProduct == 0)
        return;
    CStringW strOid = spProduct->m_key.FUN_1409b0470();
    MS2Ptr<CMsgBoxData> spBox = FUN_140d74090(
        Delegate<bool(int, const CMsgBoxData&)>(this, &UIMeratMarketDialog::OnAskMoveToModelHouse),
        CStringW(L"s_meratmarket_ask_move_to_modelhouse"));
    if (spBox.get() != 0)
        spBox->FUN_140b76940(CStringW(strOid));
}

// @0x141303060
void UIMeratMarketDialog::BuyItems(MS2Ptr<TMeratMarketBillDataParam> spParam, ASArray& arrItems)
{
    if (spParam == 0)
        return;
    UIMarketBillDialog* pDialog = FUN_140b09580(0x4f17);
    if (pDialog == 0)
        return;
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
    bool bFixedPrice = false;
    bool bGift = false;
    unsigned nCount = arrItems.FUN_1422bc5d0();
    for (unsigned i = 0; i < nCount; i++) {
        Scaleform::GFx::Value vItem = arrItems.FUN_1422bc6b0(i);
        ASObj item(vItem, 2);
        if (item.FUN_1422ba9a0())
            continue;
        int nIndex = FUN_1409c1750(item.FUN_1422baa20("index"));
        MS2Ptr<Unk_MeratPreviewEntry> spEntry = FUN_140939a00()->FUN_140d57ed0(nIndex);
        if (spEntry == 0)
            continue;
        Scaleform::GFx::Value vSlot = item.FUN_1422baa20("data");
        MS2Ptr<ASMeratMarketBuyBillData> spBill(new ASMeratMarketBuyBillData());
        spBill->FUN_1409ab940(vSlot);
        FUN_1409ac5e0(spBill.operator->(), spEntry);
        FUN_1413160d0(spBill.operator->(), nIndex);
        bFixedPrice = bFixedPrice | spBill->FUN_140eacf60();
        bGift = bGift | FUN_141315f00(spBill.operator->());
        MS2Ptr<ASBillData> spRow(spBill);
        bills.Add(spRow);
    }
    spParam->FUN_140eab940(bFixedPrice);
    spParam->SetGift(bGift);
    MS2Ptr<TMarketBillDataParam> spBase = spParam;
    pDialog->FUN_140ea7770(spBase);
    FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4f17);
}

// @0x1413034c0
void UIMeratMarketDialog::OnClickProductLink(ASData& data)
{
    if (m_spModelView == 0)
        return;
    int nId = data.FUN_1422b8b10();
    MS2Ptr<Unk_MeratPreviewEntry> spEntry = FUN_140939a00()->FUN_140d57ed0(nId);
    if (spEntry.get() != 0)
        OpenProduct(spEntry->m_spProduct);
}

// @0x141303580
void UIMeratMarketDialog::OnRemoveBasketItem(ASData& data)
{
    int nId = data.FUN_1422b8b10();
    FUN_140939a00()->FUN_140d584c0(nId);
}

// @0x141303b50
void UIMeratMarketDialog::OnBuySelected(const CStringA& strWho, ASData& data)
{
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    ASArray items(value, FUN_1422db730());
    if (items.FUN_1422bc5d0() == 0) {
        FUN_140d73bc0(0xa22, 0, 0, CStringW(L""));
        return;
    }
    MS2Ptr<TMeratMarketBillDataParam> spParam = CreateBillParam(strWho, 1, 2);
    BuyItems(spParam, items);
}

// MS2-FUNCTIONAL: toast argument temporaries (key / empty tag) are constructed in a different order
// @0x141303ca0
void UIMeratMarketDialog::OnBuyGiftSelected(const CStringA& strWho, ASData& data)
{
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    ASArray items(value, FUN_1422db730());
    if (items.FUN_1422bc5d0() == 0) {
        CStringW strKey(L"s_meratmarket_basket_empty_giftall");
        FUN_140d73aa0(FUN_14028b8e0(strKey), 0, 0, CStringW(L""));
        return;
    }
    MS2Ptr<TMeratMarketBillDataParam> spParam = CreateBillParam(strWho, 2, 2);
    BuyItems(spParam, items);
}

// @0x141303e50
void UIMeratMarketDialog::OnRemoveSeller(ASData& data)
{
    unsigned __int64 nSellerId = FUN_140718350(data.FUN_1422b8d30());
    FUN_140939a00()->FUN_140d54c70(nSellerId);
}

// @0x141303ec0
void UIMeratMarketDialog::OnSellerInfo(ASData& data)
{
    m_2a0 = FUN_140718350(data.FUN_1422b8d30());
    CStringW strName = data.FUN_1422b8f40();
    if (!strName.IsEmpty()) {
        Scaleform::GFx::Value value = data.FUN_1422b9260();
        ASObj info(value, 2);
        info.FUN_1407cbb20("text", FUN_14052bd00(0xa10, strName));
    }
}

// @0x141303ff0
void UIMeratMarketDialog::OnGetSellerProductList(ASData& data)
{
    unsigned __int64 nSellerId = FUN_140718350(data.FUN_1422b8d30());
    FUN_140939a00()->FUN_140d54ce0(nSellerId);
}

// MS2-FUNCTIONAL: temporary/cleanup order of the message box copy
// @0x141304830
void UIMeratMarketDialog::OnClickCancelSale(ASData& data)
{
    CStringW strKey = FUN_14016a730(data.FUN_1422b8d30(), 0);
    Unk_MeratOid key;
    key.FUN_1409c1640(CStringW(strKey));
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(FUN_140939a00(), key);
    if (spProduct.get() != 0) {
        if (spProduct->m_ugc.m_n28 == 2) {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FUN_14028de60(0xa2b), 1);
            if (spBox == 0)
                return;
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMeratMarketDialog::OnAskCancelSale));
            spBox->FUN_140b76940(CStringW(strKey));
            FUN_140d73c60(spBox);
        }
    }
}

// MS2-FUNCTIONAL: temporary/cleanup order of the message box copy
// @0x141304b20
void UIMeratMarketDialog::OnClickRemoveSale(ASData& data)
{
    CStringW strKey = FUN_14016a730(data.FUN_1422b8d30(), 0);
    Unk_MeratOid key;
    key.FUN_1409c1640(CStringW(strKey));
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(FUN_140939a00(), key);
    if (spProduct.get() != 0) {
        if (spProduct->m_ugc.m_n28 == 3) {
            {
                Unk_MeratBlockPtr block = FUN_140a6a830()->FUN_140a2f620(0x21);
                if (block.FUN_1401cb3d0() != 0) {
                    FUN_140a2ff20(&block, 0x21, 0);
                    return;
                }
            }
            if (spProduct->m_ugc.m_n70 == 3) {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FUN_14028de60(0xa37), 1);
                if (spBox == 0)
                    return;
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMeratMarketDialog::OnAskRemoveSale));
                spBox->FUN_140b76940(CStringW(strKey));
                FUN_140d73c60(spBox);
            } else {
                FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4ec5);
                UIMeratMarketRegisterDialog* pDialog = FUN_140d61d50(0x4ec5);
                if (pDialog != 0)
                    FUN_1413190c0(pDialog, 1, key);
                FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4ec5);
            }
        }
    }
}

// MS2-FUNCTIONAL: temporary/cleanup order of the message box copy
// @0x141304f20
void UIMeratMarketDialog::OnClickRegisterSale(ASData& data)
{
    CStringW strKey = FUN_14016a730(data.FUN_1422b8d30(), 0);
    Unk_MeratOid key;
    key.FUN_1409c1640(CStringW(strKey));
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(FUN_140939a00(), key);
    if (spProduct.get() != 0) {
        if (spProduct->m_ugc.m_n28 == 2) {
            FUN_140d73bc0(0xa03, 0, 0, CStringW(L""));
        } else {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FUN_14028de60(0xa2c), 1);
            if (spBox == 0)
                return;
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMeratMarketDialog::OnAskRegisterSale));
            spBox->FUN_140b76940(CStringW(strKey));
            FUN_140d73c60(spBox);
        }
    }
}

// MS2-FUNCTIONAL: chat/packet scope cleanup order
// @0x141305250
void UIMeratMarketDialog::OnClickSaleCommand(ASData& data)
{
    if (DAT_143ab2914 > 0x31) {
        CStringW strKey = FUN_14016a730(data.FUN_1422b8d30(), 0);
        int nCount = FUN_1422b8a10(&data);
        Unk_MeratOid key;
        key.FUN_1409c1640(CStringW(strKey));
        MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d55800(FUN_140939a00(), key);
        if (!(spProduct == 0)) {
            COutPacket packet(0x11, 0);
            Unk_MeratChat chat;
            chat.m_strMessage = FUN_141311bb0(L"/UgcProductSale {0} {1}", spProduct->m_ugc.m_n20, nCount);
            chat.m_strTarget = L"";
            chat.FUN_1401fa700(packet);
            FUN_140710590(packet);
        }
    }
}

// MS2-FUNCTIONAL: ASObj/page temporaries order not matched
// @0x141305a20
void UIMeratMarketDialog::RefreshSellerInfo()
{
    if (GetTabCount(4) != 0) {
        ASObj info(2);
        if (BuildSellerInfo(info)) {
            MS2Ptr<AScript> spPage = GetPage(4);
            if (spPage.get() != 0) {
                spPage.get()->Invoke("updateData", info.FUN_1422bb870());
            }
        }
    }
}

// @0x1413062f0
bool UIMeratMarketDialog::OnAskCancelSale(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0) {
        CStringW strOid = box.FUN_141a02fd0(0, CStringW());
        Unk_MeratOid key;
        key.FUN_1409c1640(CStringW(strOid));
        FUN_140d54700(FUN_140939a00(), key);
    }
    return true;
}

// @0x1413063e0
bool UIMeratMarketDialog::OnAskRegisterSale(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0) {
        CStringW strOid = box.FUN_141a02fd0(0, CStringW());
        Unk_MeratOid key;
        key.FUN_1409c1640(CStringW(strOid));
        FUN_140d54610(FUN_140939a00(), key);
    }
    return true;
}

// @0x1413064d0
bool UIMeratMarketDialog::OnAskRemoveSale(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0) {
        CStringW strOid = box.FUN_141a02fd0(0, CStringW());
        Unk_MeratOid key;
        key.FUN_1409c1640(CStringW(strOid));
        FUN_140d54960(FUN_140939a00(), key);
    }
    return true;
}

// @0x141306850
bool UIMeratMarketDialog::OnUgcTermsConfirm(int nButton, const CMsgBoxData& box)
{
    bool bResult = FUN_141900c80(nButton, box);
    if (nButton == 0) {
        m_638 = true;
    } else if (nButton == 1) {
        int nTab = box.FUN_141a02e50(0, 0);
        if (m_30.get() != 0)
            m_30->Invoke("changeTab", nTab);
    }
    return bResult;
}

// @0x141306900
void UIMeratMarketDialog::OnModelLoaded(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_30 == 0)
        return;
    m_2f3 = true;
}

// @0x141308fc0
void UIMeratMarketDialog::ApplyAvatarEquip(UIAvatarPC* pAvatar)
{
    if (pAvatar == 0 || pAvatar != m_spAvatarPC.get())
        return;
    if (m_spItemData)
    {
        MS2Ptr<CItemData> spData(m_spItemData);
        if (spData->FUN_14053ce40())
            m_spAvatarPC->FUN_1418bce80(spData->FUN_14053dc20());
        else if (spData->FUN_14053cb40())
            m_spAvatarPC->FUN_1418bced0(spData);
        else if (spData->FUN_14053cd50())
            m_spAvatarPC->FUN_1418bcfc0(spData);
        else if (spData->FUN_14053cc80())
            m_spAvatarPC->FUN_1418bd050(spData, m_spItem);
    }
}

// @0x141309250
bool UIMeratMarketDialog::IsItemChanged(MS2Ptr<CItemData> spItem)
{
    if (spItem == 0 || m_spItemData == 0)
        return true;
    if (m_spItemData->FUN_14053c5c0() != spItem->FUN_14053c5c0())
        return true;
    return false;
}

// @0x141309320
void UIMeratMarketDialog::SetPreviewControls(ASObj& data, int nKind, MS2Ptr<CMeratMarketProduct> spProduct)
{
    MS2Ptr<CItemData> spItemData(0);
    if (spProduct.get() != 0)
        spItemData = FUN_14053f870(spProduct->GetItemId());
    bool bRadioKind = (nKind == 0 || nKind == 1);
    bool bShowRadio = bRadioKind;
    bool bEnableMyEquip = (nKind == 0);
    bool bEnableUnEquipAll = bRadioKind;
    bool bSkinColor = (nKind == 1);
    bool bShowAction = bRadioKind;
    bool bShowColoring = bRadioKind;
    bool bMusic = (nKind == 5);
    if (spItemData.get() != 0)
    {
        if (spItemData->FUN_14053cd50() && FUN_140166410()->FUN_14036d570(0xac))
        {
            bShowRadio = false;
            bShowAction = false;
            bEnableUnEquipAll = false;
            bEnableMyEquip = false;
            bShowColoring = false;
            bMusic = true;
        }
        else if (spItemData->FUN_14053d900() && FUN_140166410()->FUN_14036d570(0xec))
        {
            bShowRadio = false;
            bShowAction = false;
            bEnableUnEquipAll = false;
            bEnableMyEquip = false;
            bShowColoring = false;
            bMusic = false;
        }
    }
    data.FUN_1407cbbe0("showRadio", bShowRadio);
    data.FUN_1407cbbe0("enableShowMyEquip", bEnableMyEquip);
    data.FUN_1407cbbe0("enableUnEquipAll", bEnableUnEquipAll);
    data.FUN_1407cbbe0("showSkinColorList", bSkinColor);
    data.FUN_1407cbbe0("showActionList", bShowAction);
    data.FUN_1407cbbe0("showPreviewColoring", bShowColoring);
    data.FUN_1407cbbe0("showMusicControl", bMusic);
}

// MS2-FUNCTIONAL: MsToSeconds argument goes through an extra stack temp in the exe
// @0x141309600
void UIMeratMarketDialog::SetMusicInfo(ASObj& data, MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0)
        return;
    if (spProduct->IsUgc())
    {
        if (spProduct->m_ugc.FUN_140896310() == 0)
            return;
        if (!FUN_140166410()->FUN_14036d570(0xa9))
            return;
        CUgcItemMusicNote* pMusic = &spProduct->m_ugc.m_music;
        ASObj info(2);
        info.FUN_1407cbb20("title", pMusic->m_str30);
        info.FUN_1407cbb20("writer", pMusic->m_str28);
        int nSeconds = MsToSeconds(pMusic->m_n20);
        CStringW strTime = FUN_141b708a0(nSeconds, true);
        CStringW strCategory = CInstrumentDataTable::GetCategoryNameById(pMusic->m_n24);
        info.FUN_1407cbb20("info", FUN_1408f71a0(L"s_meratmarket_text_music_info", strCategory, strTime));
        info.FUN_1407cbbe0("infoVisible", true);
        info.FUN_1409c0e60("time", L"00:00");
        if (m_spSlider.get() != 0)
        {
            if (nSeconds < 1)
                nSeconds = 1;
            m_spSlider->FUN_1422ce6a0((float)nSeconds);
        }
        data.FUN_1409adbe0("musicInfo", info.FUN_1422bb870());
    }
    else if (spProduct->IsPremium() != 0)
    {
        if (!FUN_140166410()->FUN_14036d570(0xac))
            return;
        MS2Ptr<CItemData> spItemData = FUN_14053f870(spProduct->GetItemId());
        if (spItemData == 0)
            return;
        if (spItemData->FUN_14053cd50())
        {
            CInstrumentDataTable::CategoryPtr spCategory = FUN_14052d1d0()->GetInstrumentCategory(spItemData->FUN_14053de80());
            if (spCategory == 0)
                return;
            ASObj info(2);
            info.FUN_1409c0e60("title", L"");
            info.FUN_1409c0e60("writer", L"");
            info.FUN_1409c0e60("info", L"");
            info.FUN_1407cbbe0("infoVisible", false);
            int nSeconds = MsToSeconds(m_62c);
            info.FUN_1409c0e60("time", L"00:00");
            if (m_spSlider.get() != 0)
            {
                if (nSeconds < 1)
                    nSeconds = 1;
                m_spSlider->FUN_1422ce6a0((float)nSeconds);
            }
            data.FUN_1409adbe0("musicInfo", info.FUN_1422bb870());
        }
    }
}

// @0x141309c60
void UIMeratMarketDialog::SetBlueprintInfo(ASObj& data, MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0)
        return;
    if (!FUN_140166410()->FUN_14036d570(0xec))
        return;
    if (spProduct->IsUgc() == 0 || spProduct->m_ugc.FUN_140896350() == 0)
        return;
    ASObj info(2);
    {
        CStringA strImage;
        if (FUN_14052d220()->FUN_1418859f0(&spProduct->m_ugc.m_look, &spProduct->m_ugc.m_blueprint, MS2Ptr<CItem>(0)))
            strImage = FUN_1401d31f0()->m_strDefaultImage;
        else
            strImage = FUN_1410280d0(9, spProduct->m_ugc.m_look.m_strUrl);
        info.FUN_1407cba60("imagePath", strImage);
    }
    data.FUN_1409adbe0("blueprintInfo", info.FUN_1422bb870());
}

// @0x141309f20
ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> >& UIMeratMarketDialog::GetProductList(int nCategory)
{
    if (FUN_1406a5040(nCategory))
        return FUN_140939a00()->m_premium;
    return FUN_140939a00()->m_shop;
}

// @0x141309f60
MS2Ptr<CMeratMarketProduct> UIMeratMarketDialog::FindProduct(const Unk_MeratProductKey& key, __int64 nId, bool bShop)
{
    int nKind = 0;
    if (bShop)
        nKind = 1;
    else if (m_250 == 7)
        nKind = 2;
    else if (m_250 == 6)
        nKind = 3;
    return FUN_140ec2300(key, nKind, nId);
}

// @0x14130a000
MS2Ptr<CMeratMarketProduct> UIMeratMarketDialog::FindProductInTab(const Unk_MeratProductKey& key, int nTab)
{
    int nKind = 0;
    if (nTab == 0)
        nKind = 1;
    else if (nTab == 7)
        nKind = 2;
    else if (nTab == 6)
        nKind = 3;
    return FUN_140ec2300(key, nKind, 0);
}

// @0x14130a090
CStringA UIMeratMarketDialog::TabName(int nTab)
{
    CStringA strName("");
    switch (nTab)
    {
    case 0: strName = "m_tabHome"; break;
    case 1: strName = "m_tabBlueShop"; break;
    case 2: strName = "m_tabRedShop"; break;
    case 3: strName = "m_tabDesigners"; break;
    case 4: strName = "m_tabMyShop"; break;
    case 5: strName = "m_tabBookmark"; break;
    case 6: strName = "m_tabBasket"; break;
    case 7: strName = "m_tabLimited"; break;
    case 8: strName = "m_tabSearch"; break;
    }
    return strName;
}

// @0x14130a210
int UIMeratMarketDialog::ShopKindOf(int nTab)
{
    switch (nTab)
    {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    default: return 5;
    }
}

// @0x14130a270
int UIMeratMarketDialog::TabFromName(const CStringW& strName)
{
    if (strName.CompareNoCase(L"designers") == 0)
        return 3;
    else if (strName.CompareNoCase(L"blue") == 0 || strName.CompareNoCase(L"premium") == 0)
        return 1;
    else if (strName.CompareNoCase(L"red") == 0)
        return 2;
    else if (strName.CompareNoCase(L"limited") == 0)
        return 7;
    else if (strName.CompareNoCase(L"myShop") == 0)
        return 4;
    else if (strName.CompareNoCase(L"bookmark") == 0)
        return 5;
    else if (strName.CompareNoCase(L"home") == 0)
        return 0;
    else if (strName.CompareNoCase(L"search") == 0)
        return 8;
    return 9;
}

// @0x14130a3b0
int UIMeratMarketDialog::TabOfKind(int nKind)
{
    switch (nKind)
    {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    default: return 9;
    }
}

// @0x14130a410
MS2Ptr<AScript> UIMeratMarketDialog::GetPage(int nTab)
{
    if (m_30 == 0 || m_spLayerPage == 0)
        return MS2Ptr<AScript>(0);
    CStringA strName = TabName(nTab);
    strName.Append("Page");
    return !strName.IsEmpty() ? static_cast<Unk_1422baa20*>(static_cast<AScript*>(m_spLayerPage.operator->()))->FUN_141311f50(strName)
                              : MS2Ptr<AScript>(0);
}

// @0x14130a5e0
MS2Ptr<AScript> UIMeratMarketDialog::GetPageOfKind(int nKind)
{
    return GetPage(TabOfKind(nKind));
}

// @0x14130a640
MS2Ptr<UIEquipIconContainer> UIMeratMarketDialog::GetEquipIcon(int nIndex)
{
    if (nIndex < 0 || nIndex >= 7)
        return MS2Ptr<UIEquipIconContainer>(0);
    return m_spEquipIcons[nIndex];
}

// @0x14130a6d0
int UIMeratMarketDialog::CurrencyOf(int nUnused)
{
    if (m_250 == 1)
        return 1;
    else if (m_250 == 2)
        return 2;
    else if (m_250 == 8)
        return 0;
    return 0;
}

// @0x14130a730
int UIMeratMarketDialog::GetTabCount(int nTab)
{
    if (nTab >= 0 && nTab < 9)
        return m_tabCounts[nTab];
    return 0;
}

// @0x14130a770
int UIMeratMarketDialog::FindPreview(UIAvatarBase* pPreview)
{
    if (pPreview != 0)
    {
        for (int i = 0; i < 5; i++)
        {
            if (m_spAvatars[i] == pPreview)
                return i;
        }
    }
    return 5;
}

// @0x14130a7f0
UIAvatarBase* UIMeratMarketDialog::GetPreview(int nIndex)
{
    if (nIndex < 0 || nIndex >= 5)
        return 0;
    return m_spAvatars[nIndex].get();
}

// MS2-FUNCTIONAL: the exe re-stores the GetPreviewPtr temporaries and has a larger frame
// @0x14130a840
UIAvatarBase* UIMeratMarketDialog::GetAvatarForItem(MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return 0;
    if (FUN_141b48710(spData))
        return m_spAvatarPC.get();
    if (spData->FUN_14053cc40())
        return GetPreviewPtr(4).get();
    if (spData->FUN_14053cb80())
        return GetPreviewPtr(2).get();
    PC* pPlayer = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    int nGender = pPlayer->FUN_141658e60();
    int nJob = pPlayer->FUN_141654700();
    if (m_spWeaponType)
    {
        if (m_spWeaponType->FUN_140ebb780(nGender, nJob, spData))
            return m_spAvatarPC.get();
    }
    return m_spMyAvatarPC.get();
}

// @0x14130ab70
int UIMeratMarketDialog::CurrentListId(int nUnused)
{
    if (m_250 == 1)
        return 100000;
    else if (m_250 == 2)
        return 100001;
    else if (m_250 == 3)
        return 110000;
    return 0;
}

// MS2-FUNCTIONAL: control-flow shape of nested returns differs (extra jmp)
// @0x14130abd0
int UIMeratMarketDialog::DefaultTab()
{
    if (m_query.IsActive())
    {
        return ResolveTab(m_250);
    }
    else
    {
        int nTab = TabFromName(FUN_140424020(FUN_140302b00()->MeratMarketOpenTab()));
        if (nTab < 0 || nTab >= 9)
            return ResolveTab(m_250);
        if (nTab == 7 && !HasLimitedTab())
            return ResolveTab(0);
        return ResolveTab(nTab);
    }
}

// @0x14130aca0
int UIMeratMarketDialog::ResolveTab(int nTab)
{
    if (nTab != 0)
        return nTab;
    bool bBlue = FUN_1406a56f0();
    bool bHome = bBlue;
    if (bHome)
        return 0;
    bool bRed = FUN_1406a5740();
    if (bRed)
        return 2;
    bool bUgc = FUN_1406a5880();
    if (bUgc)
        return 3;
    return 6;
}

// @0x14130ad20
int UIMeratMarketDialog::SlotKindOfPreview(UIAvatarBase* pPreview, MS2Ptr<CItemData> spData)
{
    int nSlot = FindPreview(pPreview);
    return SlotKindOf(nSlot, spData);
}

// @0x14130ada0
int UIMeratMarketDialog::SlotKindOf(int nSlot, MS2Ptr<CItemData> spData)
{
    switch (nSlot)
    {
    case 0:
        if (spData == 0)
            return 0;
        if (spData->FUN_14053cd10())
            return 5;
        else if (spData->FUN_14053d900())
            return 6;
        return 0;
    case 1:
        return 1;
    case 4:
        return 4;
    case 2:
        return 2;
    case 3:
        return 3;
    }
    return 7;
}

// @0x14130af30
MS2Ptr<CMeratMarketSchCond> UIMeratMarketDialog::GetSearchCondition()
{
    if (m_spSearch == 0)
        m_spSearch.AssignRaw(new CMeratMarketSchCond);
    return m_spSearch;
}

// @0x14130b000
__int64 UIMeratMarketDialog::CurrentSearchId()
{
    if (m_250 == 5)
        return m_2a0;
    return 0;
}

// @0x14130b030
Unk_ShopTabArray* UIMeratMarketDialog::ListOf(int nKind)
{
    if (nKind == 1)
        return &m_tabs100000;
    else if (nKind == 2)
        return &m_tabs100001;
    else if (nKind == 3)
        return &m_tabs110000;
    return 0;
}

// @0x14130b090
MS2Ptr<UIAvatarBase> UIMeratMarketDialog::GetPreviewPtr(int nIndex)
{
    if (nIndex < 0 || nIndex >= 5)
        return MS2Ptr<UIAvatarBase>(0);
    return m_spAvatars[nIndex];
}

// @0x14130b120
MS2Ptr<CItemData> UIMeratMarketDialog::PickItem(ATL::CAtlArray<MS2Ptr<CItemData> >& items, bool bFirst)
{
    return FUN_141b49860(items, bFirst);
}

// @0x14130b170
bool UIMeratMarketDialog::IsLimitedProduct(CMeratMarketPremiumProduct& product)
{
    ATL::CAtlArray<MS2Ptr<CItemData> > setA;
    ATL::CAtlArray<MS2Ptr<CItemData> > setB;
    SplitPackageItems(product, setA, setB);
    if (setA.IsEmpty() && setB.IsEmpty())
        return false;
    if (setA.IsEmpty() && !setB.IsEmpty())
        return true;
    ATL::CAtlArray<MS2Ptr<CItemData> > setC;
    ATL::CAtlArray<MS2Ptr<CItemData> > setD;
    SplitEquipItems(MS2Ptr<CItemData>(0), setA, setC, setD);
    return !setC.IsEmpty();
}

// @0x14130b330
bool UIMeratMarketDialog::HasLimitedTab()
{
    if (FUN_140939a00()->m_products.IsEmpty())
        return false;
    ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> >& products = FUN_140939a00()->m_products;
    size_t nCount = products.GetCount();
    bool bFound = false;
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CMeratMarketProduct> spProduct = products[i];
        if (spProduct == 0)
            continue;
        if (FUN_140939a00()->FUN_140d5b4c0(spProduct, true) == true && IsLimitedProduct(spProduct->m_premium))
        {
            bFound = true;
            break;
        }
    }
    return bFound;
}

// @0x14130b490
bool UIMeratMarketDialog::HasEventTab()
{
    if (FUN_140939a00()->m_products.IsEmpty())
    {
        int nFlags = FUN_140939a00()->m_nFlags;
        if (GetTabCount(7) == 1 && (nFlags & 2) > 0)
            return m_2f2;
        return false;
    }
    ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> >& products = FUN_140939a00()->m_products;
    size_t nCount = products.GetCount();
    bool bFound = false;
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CMeratMarketProduct> spProduct = products[i];
        if (spProduct == 0)
            continue;
        if (FUN_140939a00()->FUN_140d5b4c0(spProduct, false) == true)
        {
            bFound = true;
            break;
        }
    }
    return bFound;
}

// @0x14130b610
void UIMeratMarketDialog::ShowHelper(bool bShow)
{
    if (m_30 == 0)
        return;
    UIGameMenuDialog* pDialog = FUN_140938b90(0x4e28);
    if (pDialog != 0)
        pDialog->FUN_14193daf0(bShow);
}

// @0x14130b670
bool UIMeratMarketDialog::IsPlaceableItem(MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return false;
    return spData->FUN_14053c5c0() == 25 && spData->function.name != L"UGCMapPackage";
}

// @0x14130b730
int UIMeratMarketDialog::MarkTab(int nTab)
{
    if (nTab >= 0 && nTab < 9)
    {
        m_tabCounts[nTab] = 1;
        return 1;
    }
    return 0;
}

// @0x14130b770
void UIMeratMarketDialog::GetProductTooltip(Scaleform::GFx::Value& out, MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0)
        return;
    ASTooltip tooltip(4, 2);
    if (spProduct->IsPremium() != 0 && spProduct->m_premium.m_nType == 3)
    {
        FUN_1409e3190(&tooltip, &spProduct->m_premium, 0);
    }
    else
    {
        MS2Ptr<CItem> spItem = FUN_140ebc070(spProduct.get());
        if (FUN_14052cd70(&spItem) != 0)
            FUN_140ebbb30(&tooltip, spItem, spProduct, m_250 == 4, false);
    }
    out = tooltip.FUN_1422bb870();
}

// @0x14130b930
void UIMeratMarketDialog::OnEquipList(ATL::CAtlList<MS2Ptr<CEquipItem> >* pItems, Unk_PCEquipSet* pEquip)
{
    FUN_1411e3000(pEquip, pItems, 4, 0, false);
}

// @0x14130b970
void UIMeratMarketDialog::OnGameEventChanged(NotifyObject* pNotify)
{
    NotifyGameEventChanged* pEvent = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pEvent != 0)
    {
        const CStringW& strName = pEvent->m_eventName;
        if (strName.CompareNoCase(L"PremiumMarketSale") == 0)
        {
            int nType = pEvent->m_type;
            if (nType == 0 || nType == 1)
                m_dirty.AddPremiumSale(pEvent->m_id);
        }
        else if (strName.CompareNoCase(L"StarShop") == 0)
        {
            int nType = pEvent->m_type;
            if (nType == 0 || nType == 1)
                m_dirty.SetFlag(0x10);
        }
    }
}

// @0x14130ba70
void UIMeratMarketDialog::OnBlindTarget(NotifyObject* pNotify)
{
    if (m_30 == 0)
        return;
    Unk_BlindTargetNotify* pTarget = static_cast<Unk_BlindTargetNotify*>(dynamic_cast<NotifyBlindTarget*>(pNotify));
    if (pTarget == 0)
        return;
    const Unk_MeratProductKey& target = pTarget->m_target;
    MS2Ptr<CMeratMarketProduct> spProduct = FindProduct(target, CurrentSearchId(), IsCurrentShopTab());
    if (spProduct == 0)
        return;
    ShowProduct(spProduct);
}

// MS2-FUNCTIONAL: the exe frame is 0x10 smaller (temporaries of the Invoke call differ), early-return shape
// @0x14130bba0
void UIMeratMarketDialog::OnUgcDownloadComplete(NotifyObject* pNotify)
{
    if (m_30 == 0)
        return;
    NotifyUgcDownloadComplete* pDownload = dynamic_cast<NotifyUgcDownloadComplete*>(pNotify);
    if (pDownload == 0)
        return;
    if (pDownload->m_nType != 9)
        return;
    if (m_spProduct == 0)
        return;
    if (m_spProduct->m_ugc.FUN_140896350() == 0)
        return;
    if (m_spProduct->m_ugc.m_blueprint.m_n18 != pDownload->m_uid)
        return;
    MS2Ptr<ASMovieClip> spCharView = m_30->FUN_1409b4560(CStringA("m_charView"));
    if (spCharView == 0)
        return;
    ASObj data(2);
    data.FUN_1409c0dc0("type", "blueprint");
    data.FUN_1407cba60("imagePath", pDownload->m_strPath);
    spCharView->Invoke("updateData", data.FUN_1422bb870());
}

// @0x14130be10
void UIMeratMarketDialog::OnChangeEnableFeature(NotifyObject* pNotify)
{
    Unk_EnableFeatureNotify* pFeature = static_cast<Unk_EnableFeatureNotify*>(dynamic_cast<NotifyChangeEnableFeature*>(pNotify));
    if (pFeature == 0)
        return;
    switch (pFeature->m_nFeature)
    {
    case 0xa9:
    case 0xec:
    case 0x108:
        m_658 = true;
        break;
    }
}

// @0x14130bea0
CMsTime UIMeratMarketDialog::GetOpenTime()
{
    return m_openTime;
}

// @0x14130bee0
void UIMeratMarketDialog::SetOpenTime(const CMsTime& time)
{
    m_openTime = time;
}

// @0x14130c5b0
void UIMeratMarketDialog::UpdateNotice(const CStringW& strNotice)
{
    if (m_30 == 0 || FUN_1422dc430() == 0)
        return;
    m_30->Invoke("updateNotice", strNotice);
}

// MS2-FUNCTIONAL: page-building layout differs from exe (temp ordering/size)
// @0x14130c670
void UIMeratMarketDialog::BuildItemList(int nKind)
{
    if (m_30 == 0)
        return;
    MS2Ptr<AScript> spPage = GetPageOfKind(nKind);
    if (spPage == 0)
        return;
    if (nKind == 1 || nKind == 2)
    {
        ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> >& list = FUN_140939a00()->m_premium;
        int nLast = ((int)list.GetCount() - 1 < 0x12) ? (int)list.GetCount() - 1 : 0x11;
        ASArray items(2);
        Unk_MmViewScope scope(m_spWeaponType);
        int nResult = FillPage(0, nLast, items, list, &scope);
        ASObj info(2);
        info.FUN_1407cbbe0("isPrevList", false);
        info.FUN_1407cb9c0("curPage", 1);
        info.FUN_1407cbbe0("isSearchItemLink", false);
        info.FUN_1407cbbe0("isEndPage", false);
        info.FUN_1407cb9c0("endPage", (int)(list.GetCount() / 0x12));
        spPage->FUN_1413125d0("buildItemList", items, nResult, 1, info.FUN_1422bb870());
        return;
    }
    ASObj home(2);
    if (nKind == 0 && FUN_140166410()->FUN_14036d570(0x108))
    {
        ASArray items(2);
        Unk_MmViewScope scope(m_spWeaponType);
        ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> >& list = FUN_140939a00()->m_premium;
        if (!list.IsEmpty())
        {
            int nHomeKind = 2;
            FillBannerProducts(nHomeKind, items, list, &scope);
        }
        home.FUN_1409adbe0("arr", items.FUN_1422bb870());
    }
    else
    {
        ASArray itemsA(2);
        {
            Unk_MmViewScope scope(m_spWeaponType);
            ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> >& list = FUN_140939a00()->m_premium;
            if (!list.IsEmpty())
            {
                int nLast = (int)list.GetCount() - 1;
                if (nLast < 0)
                    nLast = 0;
                FillPage(0, nLast, itemsA, list, &scope);
            }
        }
        home.FUN_1409adbe0("arr", itemsA.FUN_1422bb870());
        ASArray itemsB(2);
        {
            Unk_MmViewScope scope(m_spWeaponType);
            ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> >& list = FUN_140939a00()->m_second;
            if (!list.IsEmpty())
            {
                int nLast = (int)list.GetCount() - 1;
                if (nLast < 0)
                    nLast = 0;
                FillPage(0, nLast, itemsB, list, &scope);
            }
        }
        home.FUN_1409adbe0("arr1", itemsB.FUN_1422bb870());
    }
    spPage->Invoke("buildHomeItemList", home.FUN_1422bb870());
}

// MS2-FUNCTIONAL: branch shape not byte-exact
// @0x14130ce70
void UIMeratMarketDialog::RefreshLimitedTab(bool bSkip)
{
    if (!(m_30 == 0) && FUN_1422dc430() != 0)
    {
        if (!bSkip)
        {
            if (GetTabCount(7) == 0)
            {
                if (!m_2f1 && HasEventTab() == true)
                {
                    m_2f2 = true;
                    ASArray tab(2);
                    AddEventTab(tab);
                    if (!FUN_140166410()->FUN_14036d570(0x108))
                        m_30->Invoke("appendTab", tab.FUN_1422bb870());
                    else
                        m_30->FUN_141313220("appendLimitedTab", tab.FUN_1422bb870(), 3);
                }
                if (!m_2f3 && DefaultTab() == 7)
                    m_30->FUN_1409ba030("changeTab", 7);
            }
            else if (!m_2f2)
            {
                m_2f2 = true;
                m_30->Invoke("setVisibleLimitedTab", m_2f2);
            }
        }
        FUN_14130db60();
    }
}

// MS2-FUNCTIONAL: temp ordering of CStringW/ternary differs
// @0x14130d150
void UIMeratMarketDialog::SetCollectState(int nId, __int64 nCount)
{
    if (vfunc_55() == 0 && m_30.get() != 0)
    {
        CStringW strCount = (nCount < 1) ? CStringW(L"") : FUN_140719a00(nCount);
        if (m_250 == 4)
        {
            MS2Ptr<AScript> spPage = GetPage(4);
            if (spPage.get() != 0)
                spPage->FUN_14129cce0("changeCollectState", nId, strCount);
        }
    }
}

// MS2-FUNCTIONAL: stack slot of strNotice/spPage 8 bytes off
// @0x14130d390
void UIMeratMarketDialog::ShowSearchPage(int nPage, int nFrom, int nTo, int nCount, bool bEnd)
{
    if (m_30 == 0)
        return;
    PC* pPlayer = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0 || m_250 == 7)
        return;
    bool bShow = false;
    bool bPrevList = false;
    CStringW strNotice;
    if (!m_query.IsActive())
    {
        if (m_spSearch.get() != 0)
        {
            if (m_spSearch->m_18 == m_dirty.GetSearchType())
            {
                bShow = true;
                bPrevList = m_spSearch->m_44 != 0;
                if (!m_spSearch->m_str.IsEmpty())
                    strNotice = FUN_14052bd00(0xa10, m_spSearch->m_str);
            }
        }
    }
    else
    {
        bShow = true;
        if (nFrom == 0 && nTo < 1)
        {
            if (m_query.m_nCategory == 0)
            {
                if (!m_query.m_strText.IsEmpty())
                    strNotice = FUN_14052bd00(0xa11, m_query.m_strText);
            }
            else
            {
                strNotice = FUN_14028de60(0xa12);
            }
        }
    }
    if (bShow)
    {
        MS2Ptr<AScript> spPage = GetPage(m_250);
        if (spPage == 0)
            return;
        bool bFirstPage = nPage == 1;
        if (bFirstPage && m_250 == 8 && m_spSearch.get() != 0)
        {
            int nLimit = 0x10e;
            if (m_spSearch->m_48 == 0)
                nLimit = 0xb4;
            if (nLimit <= nCount)
            {
                CStringW strKey(L"s_meratmarket_notice_too_many_search_result");
                MS2Ptr<CMsgBoxData> spBox = FUN_140d74390(FUN_14028b8e0(strKey), 0, FUN_140b240b0());
            }
        }
        ASArray items(2);
        Unk_MmViewScope scope(m_spWeaponType);
        int nResult = FillPage(nFrom, nTo, items, FUN_140939a00()->m_shop, &scope);
        ASObj info(2);
        info.FUN_1407cbbe0("isPrevList", bPrevList);
        info.FUN_1407cb9c0("curPage", nPage);
        info.FUN_1407cbbe0("isSearchItemLink", m_query.IsActive());
        info.FUN_1407cbbe0("isEndPage", bEnd);
        spPage->FUN_1413125d0("buildItemList", items, nResult, 1, info.FUN_1422bb870());
        if (bFirstPage && nResult == 0 && !strNotice.IsEmpty())
            spPage->Invoke("updateNoticeText", CStringW(strNotice));
        if (m_query.IsActive())
            m_query.Clear();
        else
            m_dirty.GetSearch()->Reset();
    }
}

// MS2-FUNCTIONAL: stack slot order of spPage/temps differs
// @0x14130db60
void UIMeratMarketDialog::FUN_14130db60()
{
    if (m_30 == 0 || m_250 != 7)
        return;
    MS2Ptr<AScript> spPage = GetPage(m_250);
    if (!(spPage == 0))
    {
        ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> >* pList = &FUN_140939a00()->m_products;
        ASArray items(2);
        Unk_MmViewScope scope(m_spWeaponType);
        int nKind = 1;
        int nResult = FillBannerProducts(nKind, items, *pList, &scope);
        spPage->FUN_1413124f0("buildItemList", items, nResult, true);
    }
}

// @0x14130dd00
void UIMeratMarketDialog::RequestSellerProducts(__int64 nSeller)
{
    if (nSeller != 0)
        ShowSellerProducts(nSeller);
}

// @0x14130dd30
void UIMeratMarketDialog::OnRemoveSellerComplete(__int64 nSeller)
{
    if (nSeller != 0 && (m_30.get() != 0 ? true : false))
    {
        MS2Ptr<AScript> spPage = GetPage(5);
        if (spPage.get() != 0)
            spPage->Invoke("removeSellerComplete", FUN_140719530(nSeller));
    }
}

// @0x14130de30
void UIMeratMarketDialog::OnSellerChanged(__int64 nSeller)
{
    if (nSeller != 0 && nSeller == m_2a0)
    {
        CStringW strName(L"");
        ShowSeller(nSeller, strName, 1);
    }
}

// MS2-FUNCTIONAL: operator-> reuse and stack slot order differ
// @0x14130deb0
void UIMeratMarketDialog::OnProductStateChanged(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (m_30 == 0 || spProduct == 0)
        return;
    int nIndex = m_model.IndexOf(spProduct->m_key);
    {
    MS2Ptr<AScript> spPage = GetPage(4);
    if (spPage.get() != 0)
    {
        ASObj data(2);
        data.FUN_1409c10e0("saleState", spProduct->m_ugc.m_n28);
        CMsTime end(spProduct->m_ugc.m_n68);
        CStringW strPeriod;
        if (!(end == CMsTime(0)))
            FUN_141b70f90(end, FUN_14028de60(0x9dd), strPeriod);
        else
            strPeriod = L"-";
        data.FUN_1407cbb20("period", strPeriod);
        spPage->FUN_1413130e0("changeState", Scaleform::GFx::Value(data.FUN_1422bb870()), spProduct->m_key.FUN_1409b0470(), nIndex);
    }
    }
    if (m_250 == 4)
    {
        int nLogId = 0;
        int nState = spProduct->m_ugc.m_n28;
        if (nState == 3 && spProduct->m_ugc.m_n70 == 1)
            nLogId = 0xa32;
        if (nLogId != 0)
        {
            MS2Ptr<CItem> spItem = FUN_140ebc070(spProduct.get());
            if (FUN_14052cd70(&spItem) != 0)
            {
                CStringA strDetail("");
                FUN_141349ae0(spItem, nLogId, strDetail);
            }
        }
    }
}

// @0x14130e2e0
void UIMeratMarketDialog::OnRegisterItem(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (m_30 == 0 || spProduct == 0)
        return;
    if (m_250 == 4)
    {
        ASMeratMarketProduct row(FUN_1422db730());
        Unk_MmViewScope scope;
        scope.Set(m_spWeaponType);
        if (FillProductRow(row, spProduct, &scope) != 0)
        {
            MS2Ptr<AScript> spPage = GetPage(4);
            if (spPage.get() != 0)
                spPage->Invoke("registerItemComplete", row.FUN_1422bb870());
        }
    }
    {
        MS2Ptr<CItem> spItem = FUN_140ebc070(spProduct.get());
        if (FUN_14052cd70(&spItem) != 0)
            FUN_141349ae0(spItem, 0xa33, g_strMeratLogDefault);
    }
    RefreshMyShop();
}

// MS2-FUNCTIONAL: temp layout of the removeItemComplete call differs
// @0x14130e560
void UIMeratMarketDialog::OnRemoveItem(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (m_30 == 0 || spProduct == 0)
        return;
    {
        MS2Ptr<AScript> spPage = GetPage(4);
        if (spPage.get() != 0)
        {
            int nIndex;
            if (spProduct->m_key.FUN_140899ce0(m_model.m_key))
                nIndex = m_model.m_nIndex;
            else
                nIndex = -1;
            spPage->FUN_141312710("removeItemComplete", FUN_140719530(spProduct->m_ugc.m_n20), nIndex);
        }
    }
    {
        MS2Ptr<CItem> spItem = FUN_140ebc070(spProduct.get());
        if (FUN_14052cd70(&spItem) != 0)
        {
            CStringA strDetail("");
            FUN_141349ae0(spItem, 0xa34, strDetail);
        }
    }
    RefreshMyShop();
}

// @0x14130e790
void UIMeratMarketDialog::OnUpdateItem(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (m_30 == 0 || spProduct == 0)
        return;
    {
        MS2Ptr<AScript> spPage = GetPage(4);
        if (spPage.get() != 0)
        {
            ASMeratMarketProduct row(FUN_1422db730());
            Unk_MmViewScope scope;
            scope.Set(m_spWeaponType);
            if (FillProductRow(row, spProduct, &scope) != 0)
                spPage->Invoke("updateItemData", row.FUN_1422bb870());
        }
    }
    MS2Ptr<CItem> spItem = FUN_140ebc070(spProduct.get());
    if (FUN_14052cd70(&spItem) != 0)
    {
        CUIService::GetInstance()->FUN_141adc5d0(static_cast<eUIClassID>(0x4ec5));
        FUN_141349ae0(spItem, 0xa35, g_strMeratLogDefault);
    }
}

// @0x14130ea00
void UIMeratMarketDialog::OnProductSelected(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (m_30 == 0 || spProduct == 0)
        return;
    ShowProduct(spProduct);
}

// @0x14130eaa0
void UIMeratMarketDialog::RefreshMyShopPage()
{
    if (vfunc_55() != 0)
        return;
    RefreshSellerList();
    RefreshMyShop();
}

// MS2-FUNCTIONAL: CStringT copy-ctor target mix (inline vs import) differs from the exe
// @0x14130eaf0
void UIMeratMarketDialog::InitMarketData()
{
    Unk_MeratMarketMan* pView;
    if (vfunc_55() == 0 && (pView = FUN_140939a00()) != 0)
    {
    ASObj data(2);
    BuildSellerInfo(data);
    {
        CStringW strNotice = FUN_140ec1f20();
        data.FUN_1407cbb20("noticeForSales", CStringW(strNotice));
        CStringW strImage = FUN_140ec2010();
        data.FUN_1407cbb20("noticeImageForSalesTitle", CStringW(strImage));
        if (m_2f0 == false && !strImage.IsEmpty())
        {
            data.FUN_1407cbbe0("showImageForSales", true);
            m_2f0 = true;
        }
    }
    MS2Ptr<AScript> spPage = GetPage(4);
    if (spPage.get() != 0)
        spPage->Invoke("initData", data.FUN_1422bb870());
    }
}

// @0x14130ed10
void UIMeratMarketDialog::UpdateSellerList()
{
    if (vfunc_55() != 0 || m_30 == 0)
        return;
    if (GetTabCount(5) != 0)
    {
        MS2Ptr<AScript> spPage = GetPage(5);
        if (spPage.get() != 0)
        {
            ASArray list(2);
            BuildSellerList(list);
            spPage->Invoke("buildSellerList", list.FUN_1422bb870());
        }
    }
}

// MS2-FUNCTIONAL: CStringT copy-ctor target mix (inline vs import) differs from the exe
// @0x14130ee60
void UIMeratMarketDialog::UpdateSaleNotice()
{
    if (vfunc_55() != 0 || m_30 == 0)
        return;
    if (m_2f0 == false)
    {
        {
            MS2Ptr<AScript> spPage = GetPage(4);
            if (spPage.get() != 0)
            {
                CStringW strNotice = FUN_140ec1f20();
                CStringW strImage = FUN_140ec2010();
                if (!strImage.IsEmpty())
                    m_2f0 = true;
                spPage->Invoke("setNoticeForSaleRestrict", CStringW(strNotice), CStringW(strImage));
            }
        }
        FUN_140939a00()->FUN_140d54500();
    }
}

// MS2-FUNCTIONAL: 8-byte stack slot of the scope temp differs
// @0x14130f010
void UIMeratMarketDialog::AddBasket(MS2Ptr<Unk_MeratBasketEntry> spEntry, int nCount)
{
    if (m_30 == 0 || spEntry == 0)
        return;
    MS2Ptr<CMeratMarketProduct> spProduct(spEntry->m_spProduct);
    if (spProduct == 0)
        return;
    CStringW strMessage = FUN_14052bd00(0xa23, spProduct->GetName());
    FUN_1412751f0(strMessage, 1, 1);
    if (GetTabCount(6) != 0)
    {
        MS2Ptr<AScript> spPage = GetPage(6);
        if (spPage.get() != 0)
        {
            Unk_MmViewScope scope;
            scope.Set(m_spWeaponType);
            ASMeratMarketProduct row(FUN_1422db730());
            if (FillBasketRow(row, spEntry, nCount, &scope))
                spPage->Invoke("addBasket", row.FUN_1422bb870());
        }
    }
}

// @0x14130f310
void UIMeratMarketDialog::RemoveBasket(const Unk_MeratProductKey& key, int nCount)
{
    if (m_30 == 0)
        return;
    if ((0 < key.m_nPremiumId || (unsigned __int64)key.m_nUgcId > 0) && GetTabCount(6) != 0)
    {
        MS2Ptr<AScript> spPage = GetPage(6);
        if (spPage.get() != 0)
            spPage->FUN_141312c10("removeBasket", key.FUN_1409b0470(), nCount);
    }
}

// @0x14130f430
void UIMeratMarketDialog::OnSellerVisible(bool bVisible)
{
    if (m_30 == 0)
        return;
    if (FUN_1422dc430() == 0)
        return;
    if (bVisible)
        RefreshSellerInfo();
}

// MS2-FUNCTIONAL: std::set insert temporaries and iterator slots differ
// @0x14130f490
void UIMeratMarketDialog::ApplyPremiumSale()
{
    if (m_30 == 0)
        return;
    MS2Ptr<UIMeratMarketCommon::TDirtyPremiumSale> spSale = m_dirty.m_spSale;
    if (spSale == 0)
        return;
    ATL::CAtlArray<int>& ids = spSale->m_ids;
    if (ids.IsEmpty())
        return;
    std::set<int> tabs;
    size_t nCount = ids.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        int nId = ids[i];
        MS2Ptr<PreminmMarketSaleEventContext> spEvent = FUN_1403ed2a0()->FUN_1407ce4b0(nId);
        if (spEvent != 0)
        {
            if (spEvent->m_30 == 100000)
                tabs.insert(1);
            else if (spEvent->m_30 == 100001)
                tabs.insert(2);
        }
        else
        {
            tabs.insert(2);
            tabs.insert(1);
        }
    }
    if (!tabs.empty())
    {
        for (std::set<int>::const_iterator it = tabs.begin(); it != tabs.end(); ++it)
            RebuildShopTab(*it);
    }
}

// MS2-FUNCTIONAL: page clamp locals differ (extra temps in the exe)
// @0x14130f720
bool UIMeratMarketDialog::RebuildShopTab(int nTab)
{
    MS2Ptr<AScript> spPage = GetPage(nTab);
    if (!(spPage == 0))
    {
        ASArray items(2);
        if (nTab == 1)
            FUN_141348cf0(m_tabs100000, spPage, 100000, 0);
        else if (nTab == 2)
            FUN_141348cf0(m_tabs100001, spPage, 0x186a1, 0);
        if (m_250 == nTab)
        {
            spPage->Invoke("clearCachedPageAll");
            int nCurPage = FUN_1409c1750(spPage->Invoke("getCurPage"));
            if (nCurPage < 1)
                nCurPage = 1;
            int nFirst = ((nCurPage - 1) % 5) * 0x12;
            BuildPage(nFirst, nFirst + 0x11);
        }
        return true;
    }
    else
    {
        return false;
    }
}

// @0x14130f960
void UIMeratMarketDialog::RefreshHome()
{
    if (m_30 == 0)
        return;
    if (vfunc_55() != 0)
        return;
    if (m_250 != 0)
        return;
    SelectCategory(ShopKindOf(m_250), 10);
}

// @0x14130f9e0
void UIMeratMarketDialog::SearchByKey(const CStringA& strKey, bool bExact, const CStringW& strText, int nValue)
{
    m_query.m_nCategory = 0;
    m_query.m_strSort = strKey;
    m_query.m_strText = strText;
    m_query.m_30 = nValue;
    m_query.m_44 = 8;
    m_query.m_48 = bExact;
    RunQuery();
}

// @0x14130fa80
void UIMeratMarketDialog::SearchByText(const CStringW& strText)
{
    m_query.Clear();
    m_query.m_strText = strText;
    m_query.m_nCategory = 4;
    m_query.m_44 = 8;
    m_query.m_30 = 1;
    m_2f3 = true;
    RunQuery();
}

// @0x14130fb10
void UIMeratMarketDialog::SearchByCategory(const int& nTab, const int& nValue)
{
    if (!(nTab >= 0 && nTab < 9))
        return;
    m_query.Clear();
    m_query.m_30 = nValue;
    m_query.m_nCategory = 3;
    m_query.m_44 = nTab;
    m_2f3 = true;
    RunQuery();
}

// @0x14130fba0
void UIMeratMarketDialog::RequestPending(int nFlag, bool bSet)
{
    m_dirty.SetFlag(1);
    m_dirty.GetSearch()->Set(nFlag, bSet);
    m_query.Clear();
}

// MS2-FUNCTIONAL: the inlined clamp locals (extra int temps) are laid out differently
// @0x14130fc10
bool UIMeratMarketDialog::FillSearchData(MS2Ptr<CMeratMarketSchCond> spCond, AScript& data, bool bForce)
{
    if (!(spCond == 0))
    {
        int nGender = 2;
        int nJob = 200;
        if (data.FUN_1422ba9a0() == false)
        {
            Scaleform::GFx::Value vGender = data.FUN_1422baa20("gender");
            if (!FUN_1409b0350(&vGender))
            {
                if (!FUN_1409b0390(&vGender))
                    nGender = FUN_1409c1750(vGender);
            }
            Scaleform::GFx::Value vSort = data.FUN_1422baa20("sort");
            int nSortKey = 0;
            if (!FUN_1409b0350(&vSort))
            {
                if (!FUN_1409b0390(&vSort))
                {
                    ASObj sortObj(vSort, 2);
                    nSortKey = FUN_1409c1750(sortObj.FUN_1422baa20(s_strJobCode));
                }
            }
            Scaleform::GFx::Value vSortJob = data.FUN_1422baa20("sortJob");
            if (!FUN_1409b0350(&vSortJob))
            {
                if (!FUN_1409b0390(&vSortJob))
                {
                    ASObj jobObj(vSortJob, 2);
                    nJob = FUN_1409c1750(jobObj.FUN_1422baa20(s_strSortValue));
                }
            }
            int nPage = FUN_1409c1750(data.FUN_1422baa20("page"));
            CStringW strId;
            data.FUN_1422baad0("id", strId);
            CStringW strIdCopy(strId);
            spCond->m_24 = nSortKey;
            spCond->m_30 = nPage;
        }
        bool bGenderFilter = false;
        bool bJobFilter = false;
        int nTab = m_250;
        if (m_250 == 8 || bForce)
        {
            bGenderFilter = true;
            bJobFilter = true;
        }
        else
        {
            int nListId = CurrentListId(nTab);
            FUN_140ec1da0(nListId, m_254, &bGenderFilter, &bJobFilter);
        }
        spCond->m_18 = m_254;
        int nGenderValue;
        if (!bGenderFilter)
            nGenderValue = 2;
        else
            nGenderValue = nGender;
        int nJobValue;
        if (!bJobFilter)
            nJobValue = 200;
        else
            nJobValue = nJob;
        int nGenderCode = FUN_140222b30(nGenderValue, 0);
        spCond->m_1c = nGenderCode;
        int nJobCode = FUN_1402227e0(nJobValue, 0);
        spCond->m_20 = nJobCode;
        spCond->m_44 = 0;
        int nCurrency = CurrencyOf(m_250);
        spCond->m_38 = nCurrency;
        spCond->m_40 = 0x12;
        return true;
    }
    else
    {
        return false;
    }
}

// @0x1413107f0
void UIMeratMarketDialog::ApplySearch(MS2Ptr<CMeratMarketSchCond> spCond, AScript& data)
{
    int nCategory = FUN_1409c1750(data.FUN_1422baa20("categoryIndex"));
    m_254 = nCategory;
    if (FUN_1406a5040(nCategory))
        return;
    FillSearchData(spCond, data, 0);
    spCond->m_str.Empty();
    RequestPending(m_254, false);
}

// @0x141310920
void UIMeratMarketDialog::ClearSearchRequest()
{
    m_dirty.GetSearch()->Reset();
    m_dirty.UnsetFlag(1);
}

// MS2-FUNCTIONAL: the child-bind return temporaries (3 pointer copies) differ
// @0x141310970
void UIMeratMarketDialog::ClearSearchInput()
{
    if (m_30 == 0)
        return;
    MS2Ptr<ASTextInput> spInput(m_30->FUN_140bbe880<ASTextInput>("m_inputSearchAll"));
    if (spInput.get() != 0)
    {
        CStringA strEmpty("");
        spInput->FUN_1422e0a60(strEmpty);
    }
}

// MS2-FUNCTIONAL: stack slot layout differs
// @0x141310a60
void UIMeratMarketDialog::ApplyPreviewChanges(bool bApply)
{
    if (m_30 == 0)
        return;
    if (m_spAvatar == 0)
        return;
    MS2Ptr<UIAvatarPC> spPC(dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar));
    if (spPC.get() != 0)
    {
        if (!bApply)
        {
            AvatarPC* pAvatarObj = spPC->FUN_1418bd1d0();
            if (pAvatarObj == 0 || !pAvatarObj->FUN_1409f4f20())
                bApply = false;
            else
                bApply = true;
        }
        bool bChanged = false;
        if (m_spItemData.get() != 0 && (m_spItemData->FUN_14053cd50() || m_spItemData->FUN_14053cd10()))
        {
            bChanged = true;
            if (m_spItemData->FUN_14053cd10())
            {
                int nPose;
                if (!m_620)
                    nPose = 0;
                else
                    nPose = 3;
                spPC->FUN_1418bcd80(nPose);
            }
        }
        else
        {
            if (spPC->FUN_1418bcd20(spPC->FUN_1418bd760()))
                bChanged = true;
        }
        if (bChanged && bApply)
            EquipPreview(spPC.get(), m_spItemData, true, false);
    }
}

// @0x141310d30
void UIMeratMarketDialog::OpenBanner(int nKind, const CStringA& strTarget)
{
    if (m_30 == 0)
    {
        m_4f8 = nKind;
        m_500 = strTarget;
    }
    else
    {
        switch (nKind)
        {
        case 1:
            m_banner.FUN_141348160(strTarget);
            break;
        case 3:
            OpenBannerProduct(strTarget);
            break;
        case 4:
            OpenBannerSeller(strTarget);
            break;
        case 5:
            OpenBannerSearch(strTarget);
            break;
        }
    }
}

// @0x141310e10
int UIMeratMarketDialog::PreviewColorCode()
{
    int nCode;
    if (m_bPreviewColoring)
        nCode = 0x2711;
    else
        nCode = 0;
    return nCode;
}

// MS2-FUNCTIONAL: the float argument is routed through xmm0 in the exe (slider setter shape)
// @0x141310e50
void UIMeratMarketDialog::SetModelTime(int nSeconds)
{
    if (!(m_5d0 == 0))
    {
        int nFirst;
        int nSecond;
        int nThird;
        FUN_141b706a0(nSeconds, &nFirst, &nSecond, &nThird);
        CStringW strTime = StringFormat(L"{0:02d}:{1:02d}", nFirst, nSecond);
        m_5d0->FUN_1422c4cd0(strTime);
        if (m_spSlider.get() != 0)
        {
            int nTotal = nFirst * 60 + nSecond;
            if (m_spSlider->FUN_1422ce840() != (float)nTotal)
            {
                float fTotal = (float)nTotal;
                m_spSlider->FUN_1422ce800(fTotal);
            }
        }
    }
}

// @0x141310f70
bool UIMeratMarketDialog::CheckProduct(MS2Ptr<CMeratMarketProduct> spProduct, int nCount)
{
    return FUN_140ebc630(spProduct, nCount);
}

// ---- the nested helper types (COMDATs placed after the dialog's code) ----

// @0x141314210
ShopBanner::ShopBanner()
    : m_banners(10)
{
}

// @0x141314260
UIMeratMarketDialog::ModelRef::ModelRef()
    : m_nKind(0), m_key(0, 0), m_nIndex(-1)
{
}

// @0x1413142a0
UIMeratMarketDialog::DirtyState::DirtyState()
{
    Reset();
}

// @0x141314330
UIMeratMarketDialog::TDirtySearch::TDirtySearch()
    : m_nType(0), m_bSet(false)
{
}

// @0x141314380
UIMeratMarketDialog::SearchQuery::SearchQuery()
    : m_nCategory(0), m_30(0), m_40(5), m_44(0), m_48(false)
{
}

// @0x1413147c0
ShopBanner::~ShopBanner()
{
    Clear();
}

// @0x141314810
UIMeratMarketDialog::DirtyState::~DirtyState()
{
}

// @0x141314890
UIMeratMarketDialog::SearchQuery::~SearchQuery()
{
}

// @0x1413154e0
void ShopBanner::Clear()
{
    m_banners.RemoveAll();
}

// @0x141315500
void UIMeratMarketDialog::ModelRef::Reset()
{
    m_key.Reset();
    m_nIndex = -1;
    m_nKind = 0;
}

// @0x141315540
void UIMeratMarketDialog::DirtyState::Reset()
{
    m_nFlags = 0;
    m_search.Reset();
}

// @0x141315570
void UIMeratMarketDialog::TDirtySearch::Reset()
{
    m_nType = 0;
    m_bSet = false;
}

// @0x141315590
void UIMeratMarketDialog::SearchQuery::Clear()
{
    m_40 = 5;
    m_30 = 0;
    m_strText = L"";
    m_44 = 0;
    m_strSort = "";
    m_8.RemoveAll();
    m_48 = false;
}

// @0x141315610
void UIMeratMarketDialog::DirtyState::UnsetFlag(unsigned nFlag)
{
    m_nFlags &= ~nFlag;
}

// @0x141315640
void UIMeratMarketDialog::DirtyState::ClearPremiumSale()
{
    UnsetFlag(4);
    m_spSale = 0;
}

// @0x141315970
int UIMeratMarketDialog::ModelRef::IndexOf(Unk_MeratProductKey key)
{
    return m_key == key ? m_nIndex : -1;
}

// @0x1413159d0
UIMeratMarketDialog::TDirtySearch* UIMeratMarketDialog::DirtyState::GetSearch()
{
    return &m_search;
}

// @0x1413159e0
int UIMeratMarketDialog::DirtyState::GetSearchType()
{
    return m_search.m_nType;
}

// @0x141315d60
void UIMeratMarketDialog::TDirtySearch::Set(int nType, bool bSet)
{
    m_nType = nType;
    m_bSet = bSet;
}

// @0x141315de0
bool UIMeratMarketDialog::DirtyState::HasFlag(unsigned nFlag)
{
    return (m_nFlags & nFlag) == nFlag;
}

// @0x141315ef0
bool UIMeratMarketDialog::DirtyState::HasSearch()
{
    return m_search.m_bSet;
}

// @0x141315f60
bool UIMeratMarketDialog::SearchQuery::IsActive()
{
    return m_30 != 0;
}

// @0x141316280
void UIMeratMarketDialog::DirtyState::SetFlag(unsigned nFlag)
{
    m_nFlags |= nFlag;
}

// @0x1413162a0
void UIMeratMarketDialog::DirtyState::AddPremiumSale(const int& nId)
{
    SetFlag(4);
    if (m_spSale == 0)
        m_spSale.AssignRaw(new UIMeratMarketCommon::TDirtyPremiumSale);
    if (m_spSale.get() != 0)
        m_spSale->Add(nId);
}
