// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Beauty shop page (UIBeautyShopDialog, UI id 0x4eee): the hair /
// makeup / skin shops of the salon. The player previews an item on the character (Customize), the page prices the change
// (fee row, sale event, coupon) and hands it to the bill dialog (UIBillDialog, 0x4e7b), which sends it to the server (0x31).
// The unit's range also holds the bill dialog (UIBillDialog) and the AScript::Invoke COMDATs the page instantiates.
// MS2-UNIT: ?\uibeautyshopdialog.cpp
// MS2-RANGE: 0x1418c3630-0x1418ce5e0 .text$mn
// MS2-RANGE: 0x140110080-0x1401105f0 .text$di
// MS2-RANGE: 0x142cbca30-0x142cbcd10 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strCustomize@@YAXXZ 0x140110080 ; probe
// MS2-PIN: ??__Es_strDefault@@YAXXZ 0x1401100b0 ; probe
// MS2-PIN: ??__Es_strEmotion@@YAXXZ 0x1401100e0 ; probe
// MS2-PIN: ??__Es_strExceptRender@@YAXXZ 0x140110110 ; probe
// MS2-PIN: ??__Es_strExpired@@YAXXZ 0x140110140 ; probe
// MS2-PIN: ??__Es_strHair@@YAXXZ 0x140110170 ; probe
// MS2-PIN: ??__Es_strInvalide@@YAXXZ 0x1401101a0 ; probe
// MS2-PIN: ??__Es_strLayerExpired@@YAXXZ 0x1401101d0 ; probe
// MS2-PIN: ??__Es_strLower@@YAXXZ 0x140110200 ; probe
// MS2-PIN: ??__Es_strMissMatch@@YAXXZ 0x140110230 ; probe
// MS2-PIN: ??__Es_strOptimizer@@YAXXZ 0x140110260 ; probe
// MS2-PIN: ??__Es_strPCBang@@YAXXZ 0x140110290 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1401102c0 ; probe
// MS2-PIN: ??__Es_strSlot@@YAXXZ 0x1401102f0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x140110320 ; probe
// MS2-PIN: ??__Es_strUndo@@YAXXZ 0x140110350 ; probe
// MS2-PIN: ??__Es_strVIP@@YAXXZ 0x140110510 ; probe
// MS2-PIN: ??__Es_strWillUpdatePos@@YAXXZ 0x140110540 ; probe
// MS2-PIN: ??$?4HH$0A@@?$pair@HH@std@@QEAAAEAU01@$$QEAU01@@Z 0x1418cc1e0 ; unique
// MS2-PIN: ??$?8PEAVUIBeautyShopDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x1418cc230 ; prop
// MS2-PIN: ??$?8PEAVUIBeautyShopDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x1418cc2a0 ; prop
// MS2-PIN: ??$?8PEAVUIBeautyShopDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIBeautyShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x1418cc310 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x1418cc570 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x1418cc610 ; prop
// MS2-PIN: ?GetAt@?$CAtlArray@V?$MS2Ptr@VUnk_BSPriceRow@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_BSPriceRow@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VUnk_BSPriceRow@@@@_K@Z 0x1418cc920 ; prop
// MS2-PIN: ?GetAt@?$CAtlArray@V?$MS2Ptr@VUnk_BSPriceRow@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_BSPriceRow@@@@@ATL@@@ATL@@QEBAAEBV?$MS2Ptr@VUnk_BSPriceRow@@@@_K@Z 0x1418ccb00 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@V?$MS2Ptr@VUnk_BSPriceRow@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_BSPriceRow@@@@@ATL@@@ATL@@QEAAXXZ 0x1418ccb70 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@V?$MS2Ptr@VUnk_BSPriceRow@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_BSPriceRow@@@@@ATL@@@ATL@@QEAA_N_KH@Z 0x1418ccb90 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1418ccd20 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1418ccd80 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1418ccde0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x1418cce40 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x1418cce70 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x1418ccea0 ; unique
// MS2-PIN: ??$Call@VUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x1418ccee0 ; prop
// MS2-PIN: ??$Call@VUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x1418ccf20 ; prop
// MS2-PIN: ??$Call@VUIBeautyShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIBeautyShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x1418ccf60 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1418ccfa0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1418cd000 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1418cd060 ; unique
// MS2-PIN: ??__Fs_strCustomize@@YAXXZ 0x142cbca30 ; probe
// MS2-PIN: ??__Fs_strDefault@@YAXXZ 0x142cbca50 ; probe
// MS2-PIN: ??__Fs_strEmotion@@YAXXZ 0x142cbca70 ; probe
// MS2-PIN: ??__Fs_strExceptRender@@YAXXZ 0x142cbca90 ; probe
// MS2-PIN: ??__Fs_strExpired@@YAXXZ 0x142cbcab0 ; probe
// MS2-PIN: ??__Fs_strHair@@YAXXZ 0x142cbcad0 ; probe
// MS2-PIN: ??__Fs_strInvalide@@YAXXZ 0x142cbcaf0 ; probe
// MS2-PIN: ??__Fs_strLayerExpired@@YAXXZ 0x142cbcb10 ; probe
// MS2-PIN: ??__Fs_strLower@@YAXXZ 0x142cbcb30 ; probe
// MS2-PIN: ??__Fs_strMissMatch@@YAXXZ 0x142cbcb50 ; probe
// MS2-PIN: ??__Fs_strOptimizer@@YAXXZ 0x142cbcb70 ; probe
// MS2-PIN: ??__Fs_strPCBang@@YAXXZ 0x142cbcb90 ; probe
// MS2-PIN: ??__Fs_strSkill@@YAXXZ 0x142cbcbb0 ; probe
// MS2-PIN: ??__Fs_strSlot@@YAXXZ 0x142cbcbd0 ; probe
// MS2-PIN: ??__Fs_strStun@@YAXXZ 0x142cbcbf0 ; probe
// MS2-PIN: ??__Fs_strUndo@@YAXXZ 0x142cbcc10 ; probe
// MS2-PIN: ??__Fs_strVIP@@YAXXZ 0x142cbcc90 ; probe
// MS2-PIN: ??__Fs_strWillUpdatePos@@YAXXZ 0x142cbccb0 ; probe
// MS2-PINS-END tplpin
// MS2-PIN: ??0?$MS2Ptr@VBeautyShopContext@Customize@@@@QEAA@PEAVBeautyShopContext@Customize@@@Z 0x1418cc750 ; merge-bind
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAA@XZ 0x1418cc7c0 ; merge-bind
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAA@XZ 0x1418cc7e0 ; merge-bind
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x1418cc800 ; merge-bind
// MS2-PIN: ??4?$MS2Ptr@VUnk_BSPriceRow@@@@QEAAAEAV0@AEBV0@@Z 0x1418cc820 ; merge-bind
// MS2-PIN: ??4?$MS2Ptr@VUnk_BSPriceRow@@@@QEAAAEAV0@H@Z 0x1418cc860 ; merge-bind
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAPEAXI@Z 0x1418cc980 ; merge-bind
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x1418cc9c0 ; merge-bind
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIBeautyShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x1418cca00 ; merge-bind
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibeautyshopdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uibeautyshopdialog.h"
static CString s_strCustomize = "Customize";
static CString s_strDefault = "Default";
static CString s_strEmotion = "Emotion";
static CString s_strExceptRender = "ExceptRender";
static CString s_strExpired = "Expired";
static CString s_strHair = "Hair";
static CString s_strInvalide = "Invalide";
static CString s_strLayerExpired = "layerExpired";
static CString s_strLower = "Lower";
static CString s_strMissMatch = "MissMatch";
static CString s_strOptimizer = "Optimizer";
static CString s_strPCBang = "PCBang";
static CString s_strSlot = "Slot";
static CString s_strUndo = "Undo";
static CString s_strVIP = "VIP";
static CString s_strWillUpdatePos = "WillUpdatePos";
static CString s_strItemSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
static UICommon::CMyPCKeyInputController s_keyInputController;
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <vector>

// ---- local stand-ins for classes whose units are not recovered yet ----

// The notifications the page listens to (NotifyObject subclasses, dispatched by name).
#include "ms2/placeholder/notifygameeventchanged.h"
class NotifyChangeActiveMyCodiTab : public NotifyObject
{
public:
    NotifyChangeActiveMyCodiTab();
    virtual ~NotifyChangeActiveMyCodiTab();
    bool m_bActive;                             // +0x18 the "my codi" tab is still valid
};
MS2_CHECK_OFFSET(NotifyChangeActiveMyCodiTab, m_bActive, 0x18);

// The beauty shop scene (the page's parent movie); only its RTTI is used.
class UISceneGameBeautyShop : public UISwfEntity
{
public:
    virtual ~UISceneGameBeautyShop();
};

// The style slot list ("m_items" of "m_customStyle").
class Unk_140bfc2e0 : public ASDisplayObject
{
public:
    void FUN_1422dcca0(int nIndex);             // select
    int FUN_1422dccd0();                        // the selected index (-1: none)
};
class Unk_BSStyleEntity : public ASGameEntity
{
public:
    Unk_14102fe10<Unk_140bfc2e0> FUN_140bfa6a0(const CString& strName);
};
class Unk_BSRootScript : public AScript
{
public:
    MS2Ptr<ASGameEntity> FUN_140ede0c0(const CString& strName);
};

class ASTooltip : public AScript
{
public:
    ASTooltip(int a1, int a2);
    virtual ~ASTooltip();
    int FUN_1409e26b0(const CStringW& strText);     // set the text (0: empty)
    void FUN_1409c6dc0(int nType);                  // tooltip layout
private:
    void* m_40;
    void* m_48;
    void* m_50;
    void* m_58;
};
MS2_CHECK_SIZE(ASTooltip, 0x60);

// The colour palette rows (FUN_140281980: the ingredient/palette tables).
class Unk_BSColorRow : public CPtred
{
public:
    char m_pad_18[0x24 - 0x18];
    int m_achieve;                              // +0x24 achieve required to use the colour
    int m_grade;                                // +0x28 grade of that achieve
    int m_nameId;                               // +0x2c name string (0x48 table; 0x49: description)
};
MS2_CHECK_OFFSET(Unk_BSColorRow, m_nameId, 0x2c);
typedef MS2Ptr<Unk_BSColorRow> Unk_BSColorPtr;
class Unk_BSColorList : public CPtred
{
public:
    unsigned FUN_140570e10();                                   // count
    const Unk_BSColorPtr& FUN_140570dd0(size_t nIndex);         // row
};
class Unk_BSColorTable
{
public:
    Unk_BSColorPtr FUN_1405587f0(int nPalette, int nIndex);     // row of the extended palette
    Unk_BSColorPtr FUN_140558960(int nPalette, int nIndex);     // row
    MS2Ptr<Unk_BSColorList> FUN_140558ad0(int nPalette);        // palette
};
Unk_BSColorTable* FUN_140281980();

// The price row of a beauty shop entry.
class Unk_BSPriceRow : public CPtred
{
public:
    Unk_BSPriceRow();                           // 0x1406e3690
    ~Unk_BSPriceRow();                          // 0x1406ef4f0
    void FUN_1406e37f0(CInPacket& packet);      // read the row
    unsigned FUN_1406e3bc0();                   // the price in merets
    int m_id;                                   // +0x18 item id
    char m_pad_1c[0x20 - 0x1c];
    int m_saleTag;                              // +0x20 the sale tag
    unsigned short m_level;                     // +0x24 required level
    int m_achieve;                              // +0x28 achieve required
    int m_grade;                                // +0x2c grade of that achieve
    Unk_BSFee m_fee;                            // +0x30 the fee
};
MS2_CHECK_SIZE(Unk_BSPriceRow, 0x68);
MS2_CHECK_OFFSET(Unk_BSPriceRow, m_level, 0x24);
MS2_CHECK_OFFSET(Unk_BSPriceRow, m_grade, 0x2c);
MS2_CHECK_OFFSET(Unk_BSPriceRow, m_fee, 0x30);
typedef MS2Ptr<Unk_BSPriceRow> Unk_BSPricePtr;

class Unk_BSItemData : public CItemData
{
public:
    int FUN_14053c940(int nGender);             // wearable by the gender
    int FUN_14053e260();                        // colour palette id
};
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
void FUN_140f324f0(ASObj& obj, MS2Ptr<CItemData> spData, int n);

// The achieve manager.
class CAchieve : public CPtred {};
class Unk_BSAchieves
{
public:
    MS2Ptr<CAchieve> FUN_140935e60(int nAchieve);
    int FUN_140936900(int nAchieve, int nGrade);        // 0: not reached
};
Unk_BSAchieves* FUN_1406c7600();
CStringW FUN_14093bd40(int nAchieve, int nGrade, CStringW strDefault);

// The player and its equipment.
class Unk_InventoryEquipment : public CPtred
{
public:
    MS2Ptr<CItem> FUN_1411dc7a0();
    void FUN_1411dcf10(const CString& strTag);
};
class Unk_BSPlayer : public PCBase
{
public:
    MS2Ptr<Unk_InventoryEquipment> FUN_141655c30(__int64 nItemUid);
    MS2Ptr<Unk_InventoryEquipment> FUN_141655e10(int nSlot);
};
class Unk_BSPlayerCap { public: int FUN_1412706f0(int n); };
class Unk_BSEquipSet { public: MS2Ptr<Unk_InventoryEquipment> FUN_1411e1a50(int nSlot, int n); MS2Ptr<Unk_InventoryEquipment> FUN_1411e1780(int nSlot, int n); int FUN_1411e0c30(int nItemId); };
Unk_BSPlayerCap* FUN_14165f460(PCBase* pPc);
Unk_BSEquipSet* FUN_1416561a0(PCBase* pPc);
int FUN_14123c580(PCBase* pPc);                 // object id
int FUN_141658e60(PCBase* pPc);                 // gender
int FUN_141658f30(PCBase* pPc);                 // level
void FUN_14166cc40(PCBase* pPc, int n);

// The current field (the page refreshes its camera through it).
class Unk_BSField
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
    virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69();
    virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77(); virtual void vfunc_78(); virtual void vfunc_79();
    virtual void vfunc_80(); virtual void vfunc_81(); virtual void vfunc_82(); virtual void vfunc_83(); virtual void vfunc_84(); virtual void vfunc_85(); virtual void vfunc_86(); virtual void vfunc_87(); virtual void vfunc_88(); virtual void vfunc_89();
    virtual void vfunc_90(); virtual void vfunc_91(); virtual void vfunc_92(); virtual void vfunc_93(); virtual void vfunc_94(); virtual void vfunc_95(); virtual void vfunc_96(); virtual void vfunc_97(); virtual void vfunc_98(); virtual void vfunc_99();
    virtual void vfunc_100(); virtual void vfunc_101(); virtual void vfunc_102(); virtual void vfunc_103(); virtual void vfunc_104(); virtual void vfunc_105(); virtual void vfunc_106(); virtual void vfunc_107(); virtual void vfunc_108(); virtual void vfunc_109();
    virtual void vfunc_110(); virtual void vfunc_111(); virtual void vfunc_112(); virtual void vfunc_113(); virtual void vfunc_114(); virtual void vfunc_115(); virtual void vfunc_116(); virtual void vfunc_117(); virtual void vfunc_118(); virtual void vfunc_119();
    virtual void vfunc_120(); virtual void vfunc_121(); virtual void vfunc_122(); virtual void vfunc_123(); virtual void vfunc_124(); virtual void vfunc_125(); virtual void vfunc_126(); virtual void vfunc_127(); virtual void vfunc_128(); virtual void vfunc_129();
    virtual void vfunc_130(); virtual void vfunc_131(); virtual void vfunc_132(); virtual void vfunc_133(); virtual void vfunc_134(); virtual void vfunc_135(); virtual void vfunc_136(); virtual void vfunc_137(); virtual void vfunc_138(); virtual void vfunc_139();
    virtual void vfunc_140(); virtual void vfunc_141(); virtual void vfunc_142(); virtual void vfunc_143(); virtual void vfunc_144(); virtual void vfunc_145(); virtual void vfunc_146(); virtual void vfunc_147(); virtual void vfunc_148();
    virtual void vfunc_149();                   // 149 restore the field camera
};
class Unk_BSWorld
{
public:
    Unk_BSPlayer* FUN_141bd0cc0();              // the player (NULL outside the game)
    Unk_BSField* FUN_141bd3620();
};
Unk_BSWorld* FUN_1403ed2d0();

class Unk_BSUIMgr
{
public:
    void FUN_141adc530(int nId);                // open
    int FUN_141adc890(int nId);                 // is open
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
};
Unk_BSUIMgr* FUN_1403ed2b0();

// The app platform (slot 43: post a window event).
class Unk_BSPlatform
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42();
    virtual void vfunc_43(int nEvent, int a2, int nDelay);
};
Unk_BSPlatform* FUN_140d86260();

// Client constants (the style slot counts and the slot extend price).
class Unk_BSConstI64 { public: __int64 FUN_1402bac90(); char m_pad[0x58]; };
class Unk_BSConstInt { public: int FUN_140ec2b60(); char m_pad[0x58]; };
struct Unk_BSConstUInt { char m_pad[0x58]; };
class Unk_BSConstStr
{
public:
    const CString& FUN_140298f80();             // the string value (by reference: this+0x50)
    char m_data[0x58];
};
struct Unk_BSConstants
{
    char m_pad_0[0x64b8];
    Unk_BSConstI64 m_extendPrice;               // +0x64b8 merets per slot extension
    char m_pad_6510[0x6518 - 0x6510];
    Unk_BSConstInt m_extendCount;               // +0x6518 slots per extension
    Unk_BSConstInt m_baseSlots;                 // +0x6570 free slots
    Unk_BSConstUInt m_maxExtend;                // +0x65c8 extra slots that can be bought
    char m_pad_6620[0xccb0 - 0x6620];
    Unk_BSConstStr m_hairGuide;                 // +0xccb0 the hair guide movie
    char m_pad_cd08[0xcd10 - 0xcd08];
    Unk_BSConstStr m_makeUpGuide;               // +0xcd10 the makeup guide movie
};
MS2_CHECK_OFFSET(Unk_BSConstants, m_hairGuide, 0xccb0);
MS2_CHECK_OFFSET(Unk_BSConstants, m_makeUpGuide, 0xcd10);
MS2_CHECK_OFFSET(Unk_BSConstants, m_extendCount, 0x6518);
MS2_CHECK_OFFSET(Unk_BSConstants, m_maxExtend, 0x65c8);
Unk_BSConstants* FUN_1401d3200();
unsigned* FUN_1401d7c10(Unk_BSConstUInt* pSlot);

// The hair apply effect.
struct Unk_BSEffectRequest
{
    CString m_strName;                          // +0x00 effect xml
    int m_n08;                                  // +0x08
    char m_pad_0c[0x78 - 0x0c];
};
MS2_CHECK_SIZE(Unk_BSEffectRequest, 0x78);
class Unk_BSEffectMgr { public: void FUN_1411a4a00(Unk_BSEffectRequest* pRequest); };
Unk_BSEffectMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_BSEffectRequest* p);         // construct
void FUN_140a53190(Unk_BSEffectRequest* p, int nObjectId);
void FUN_1405a89e0(Unk_BSEffectRequest* p);         // destroy
struct Unk_BSEffectPaths { char m_pad_0[0x2e0]; CString m_hairApply; };   // +0x2e0
Unk_BSEffectPaths* FUN_1401d31f0();

// Misc singletons.
class Unk_BSOptions { public: bool FUN_14036d570(int nId); };
Unk_BSOptions* FUN_140166410();
class Unk_BSStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_BSStrings* FUN_1401a9d70();
class Unk_BSGameEvents
{
public:
    int FUN_140476cf0(int nEvent, int nLevel);                          // 0: the sale applies
    unsigned FUN_140476c70(int nEvent, unsigned nPrice, int nLevel);    // the sale price
};
Unk_BSGameEvents* FUN_1401c0d90();
class Unk_BSLocalizer { public: CStringW FUN_1422b0570(const CString& strKey); };
Unk_BSLocalizer* FUN_14025e7a0();
class Unk_BSCutScene { public: bool FUN_14116d840(); bool FUN_14116d720(); };
Unk_BSCutScene* FUN_14025e7c0();
class Unk_DTNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> cb);
};
Unk_DTNotices* FUN_140939a10();
class Unk_140bccd50
{
public:
    void FUN_140da5180(int nOp, Delegate<void(CInPacket&)> cb);
    void FUN_140da51e0(int nOp, Delegate<void(CInPacket&)> cb);
};
Unk_140bccd50* FUN_140bccd50();
class Unk_BSItemEvents
{
public:
    void FUN_1419cae20(UIItemEventListener* pListener);
    void FUN_1419caeb0(UIItemEventListener* pListener);
};
Unk_BSItemEvents* FUN_140a6a840();
Unk_BSCamera* FUN_140cd47b0(int nId);
class Unk_BSSound;
Unk_BSSound* FUN_1408e57f0();
void FUN_1422b9fd0(Unk_BSSound* p, int nEvent);

// Message boxes and strings.
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
Delegate<bool(int, const CMsgBoxData&)> FUN_140b240b0();
void FUN_14151f150(MS2Ptr<CMsgBoxData> spBox);
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_14028de60(int nId);
CStringW FUN_14052bd00(int nId, const CStringW& a);
CStringW FUN_1409eadb0(int nId, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW FUN_1409eaa20(CStringW strKey, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW FUN_140632a60(int nId, const CStringW& a, const CStringW& b);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& a);
CStringW FUN_14062b4f0(CStringW strKey, const int* pn);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a);
CStringW FUN_1409404f0(__int64 n);                  // a crossed-out price
CStringW FUN_1409eb450(int n);
void FUN_1412751f0(const CStringW& strText, int nA, int nB);
void FUN_1412752d0(const CStringW& strKey, int nType);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_1412761e0(MS2Ptr<AScript> spRoot, int bEnable);   // enable the root's input
CMsTime FUN_1406c47a0(__int64 nTime);
CStringW FUN_14083bab0(const CMsTime& time, CStringW strSep);
bool FUN_140841300(const CStringW& str, const char* sz);
bool FUN_140184310(const CString& str, const char* sz);
int FUN_141b71a10(const char* sz);
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int bVisible);
void FUN_140cff950(const Scaleform::GFx::Value& root, CString strName, int bEnable);
bool FUN_1409c1720(const Scaleform::GFx::Value& v);
int FUN_1409c1750(const Scaleform::GFx::Value& v);
int FUN_1409c17e0(const Scaleform::GFx::Value& v);
bool FUN_1409b0390(Scaleform::GFx::Value* pValue);  // undefined
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// The fee helpers (beautyshop fee rows).
CStringW FUN_14134a220(Unk_BSFee* pFee, const unsigned __int64* pPrice);   // the price text
bool FUN_14134a1d0(Unk_BSFee* pFee, const unsigned __int64* pPrice);       // the player can pay
void FUN_14134a2e0(Unk_BSFee* pFee);                                       // "not enough" message
void FUN_14134a120(int a1, int a2, int a3);

// The server result of a beauty shop request (formatted into string 0x272 for the unknown codes).
enum Unk_BSResult : unsigned int {};

CStringW LocalizedMentorFormat(const CStringW&, const fmt::ArgList&);
FMT_VARIADIC_W(CStringW, LocalizedMentorFormat, CStringW)
CStringW BlockFormat(int, const fmt::ArgList&);
FMT_VARIADIC_W(CStringW, BlockFormat, int)

MS2Ptr<CMsgBoxData> FUN_140f0a930(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb, int nArg);
bool FUN_140f096f0(ASObj& obj, MS2Ptr<CItemData> spData, int nIndex, unsigned nMerat, int nGender);
bool FUN_140f09810(ASObj& obj, bool bEnabled);
// ---- more stand-ins ----
CStringW FUN_140275590(const wchar_t* szFormat, const CStringW& a1, const int& a2);
CStringW FUN_141081c60(CStringW strKey, const CStringW& a, const CStringW& b, const int& n);
CStringW FUN_140292a70(const wchar_t* szFormat, const int& n0);
CStringW FUN_1418fe870(int nKind, int* pnZero, int nItemId);                 // the item icon url
void FUN_140961010(int nStringId, int nA, int nB, const CStringW& strArg);
extern Unk_Inventory DAT_143ab2a90;                                          // the player's inventory
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    int FUN_1422c2030();                                        // is enabled
    void FUN_1422c1fe0(unsigned int bEnabled);                  // enable
};
void FUN_14134a480(AScript& root, const CString& strName, MS2Ptr<Unk_140acd6e0>* pOut);     // bind a child of the root
MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);
bool FUN_14166c930();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
void FUN_140f327a0(MS2Ptr<CItemData> spData, int nColor, ASObj& obj, int n);
int FUN_1414124a0(void* pPart);
bool FUN_140f32290(ASObj& obj, MS2Ptr<CItemData> spData, MS2Ptr<Customize> spCustomize, int nMode, int nA, int nB);                 // the item id of a part


// The beauty shop helpers next door (uibeautyshopstyledialog.cpp).
int FUN_140f01070(int nShopKind);
CStringW FUN_140f010c0(int nItemId);
int FUN_140f01140();
unsigned FUN_140f011b0();
int FUN_140f011f0();
int FUN_140f01220();
bool FUN_140f01250(__int64 nItemUid);
bool FUN_140f012d0(__int64 nItemUid);
void FUN_140f01350();
void FUN_140f01430();
void FUN_140f01540(ASObj& obj, bool bHair);
bool FUN_140f01670(ASTooltip& tip, void*, ASData* pArgs);
bool FUN_140f01eb0(ASTooltip& tip, Unk_BSPricePtr spPrice, short nLevel, const CStringW& strPrice);
void FUN_140f024e0(ASData* pArgs, int* pnPalette, int* pnType);
bool FUN_140f02860(Unk_BSPricePtr spPrice, unsigned short nLevel, bool* pbLocked);
bool FUN_140f02a80(int nPalette, int nIndex);
bool FUN_140f02b10(Unk_BSPricePtr spPrice, short nLevel);
UIBillDialog* FUN_140f0a350(int nId);

// The part of the character the customize controller edits.
class Unk_BSPartObj
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(int nIndex, float fSize);
    virtual void vfunc_9(int nIndex);
    virtual void vfunc_10(float fValue);
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
    virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual const float* vfunc_24(int nIndex);
    virtual void vfunc_25(); virtual void vfunc_26();
    virtual int vfunc_27();
};

void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);                 // Value = f
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);                   // Value = n
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);          // Value = sz

// The customize controller's part handle (8 bytes).
class Unk_BSPartHandle
{
public:
    ~Unk_BSPartHandle();                        // 0x140cd4cf0
    Unk_BSPartObj* FUN_140cd5210();             // get
    Unk_BSPartObj* operator->() { return FUN_140cd5240(); }
    Unk_BSPartObj* FUN_140cd5240();             // operator->
    void* m_p;
};

// ---- UIBeautyShopDialog ----

// @0x1418cc380
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, float a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcd70(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1418c3630
UIBeautyShopDialog::UIBeautyShopDialog()
    : m_1c8(0), m_278(0), m_290(0), m_2a0(0), m_2a8(0), m_2ac(0), m_2b0(0), m_2b4(0), m_2b5(0), m_2d8(0), m_2dc(0),
      m_2e0(0), m_2e4(-1)
{
    m_2c = 0xc;
    m_80 = 0;
    m_88 = 1;
    m_58 = 0;
    FUN_141925e70(0, 1);
    FUN_140bccd50()->FUN_140da5180(0x31, Delegate<void(CInPacket&)>(this, &UIBeautyShopDialog::FUN_1418c80b0));
}

// @0x1418c3950
UIBeautyShopDialog::~UIBeautyShopDialog()
{
    FUN_140bccd50()->FUN_140da51e0(0x31, Delegate<void(CInPacket&)>(this, &UIBeautyShopDialog::FUN_1418c80b0));
}

// @0x1418c3b00
CString UIBeautyShopDialog::vfunc_1()
{
    return "BeautyShopDialog";
}

// @0x1418c3b50
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_1418cae60();
    m_290 = 0;
    m_298 = 0;
    m_294 = 0;
    m_2a0 = 0;
    m_1d0.FUN_1406e3d30();
    m_1b8 = 0;
    m_1c8 = 0;
    m_2a8 = 0;
    m_2ac = 0;
    m_2b0 = 0;
    m_2b4 = 0;
    m_278 = 0;
    int nPalette = 0;
    int nColor = 0;
    m_288 = std::make_pair(nPalette, nColor);
    m_198.RemoveAll();
    m_2b5 = 0;
    m_2d8 = 0;
    m_2dc = 0;
    m_2e0 = 0;
    m_2e4 = -1;
    FUN_140f01430();
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopDialog::FUN_1418c9780));
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopDialog::FUN_1418c9b20));
}

// @0x1418c3f00
int UIBeautyShopDialog::vfunc_74(int a1, void* p2, void* p3)
{
    return UIDialog::vfunc_74(a1, p2, p3);
}

// @0x1418c3f40
void UIBeautyShopDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    m_1c8 = FUN_140cd47b0(0x4ef2);
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopDialog::FUN_1418c9780));
}

// @0x1418c4040
void UIBeautyShopDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1418c8ee0();
    m_2a8 = 1;
    FUN_140d86260()->vfunc_43(0xe, 0, 1000);
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopDialog::FUN_1418c9b20));
}

// @0x1418c4170
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (FUN_14025e7c0()->FUN_14116d840())
    {
        if (m_2b5 == 0)
            FUN_1418c9d80();
        return 1;
    }
    return 0;
}

// @0x1418c41d0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::vfunc_15()
{
    if (!(m_1b8 == 0) && vfunc_55() == 0)
    {
        m_1b8->FUN_140cd1bf0();
        if (m_1c8)
            m_1c8->FUN_1418dda30(m_1b8->FUN_140cd27f0() == 0);
        Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc && pPc->FUN_14166c930() != 0xe)
            pPc->vfunc_59(0xe, 0, 0, 0);
    }
}

// @0x1418c42e0
void UIBeautyShopDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_2e8 = 0;
}

// @0x1418c4320
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::vfunc_46()
{
    if (UISwfEntity::vfunc_46() == 0)
        return 0;
    if (m_30 == 0)
        return 0;
    if (m_290 != 2)
        return 0;
    CString strName("m_probInfo");
    FUN_14134a480(*m_30, strName, &m_2e8);
    return 1;
}

// The answers of the scene (OnExit) and of the bill dialog (OK: apply).
// @0x1418c43e0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520())
        return 0;
    if (dynamic_cast<UISceneGameBeautyShop*>(pSender))
    {
        if (FUN_140184310(pMsg->FUN_1422b8d30(), "OnExit"))
            FUN_1418c9d80();
        return 1;
    }
    if (dynamic_cast<UIBillDialog*>(pSender))
    {
        int nResult = pMsg->FUN_1422b8a10();
        m_10 = pMsg->FUN_1422b8a90() != 0;
        if (nResult == 0)
            FUN_1418c9f20();
        return 1;
    }
    return 0;
}

// The AS calls of the page.
// @0x1418c4550
// MS2-FUNCTIONAL: large EH frame; temporaries and branch order differ
int UIBeautyShopDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnChangeItem", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            FUN_1418c7400(0);
            int nItemId = FUN_141b71a10(data.FUN_1422b8d30());
            int nIndex = data.FUN_1422b8a10();
            data.FUN_1422b8a10();
            if (nIndex < 0 || nIndex >= (int)m_198.GetCount())
                m_278 = FUN_1418cbeb0(nItemId);
            else
                m_278 = m_198.GetAt(nIndex);
            FUN_1418c76d0(nItemId);
            FUN_1418c7ab0();
        }
        return 1;
    }
    if (_stricmp("OnChangeColor", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            data.FUN_1422b8a10();
            CString strName = data.FUN_1422b8d30();
            AScript obj(data.FUN_1422b9260(), 2);
            int nColorSN = FUN_1409c17e0(obj.FUN_1422baa20("colorSN"));
            int nPaletteId = FUN_1409c17e0(obj.FUN_1422baa20("paletteID"));
            m_288 = std::make_pair(nPaletteId, nColorSN);
            FUN_1418c7750(nPaletteId, nColorSN);
            FUN_1418c7aa0(0);
            FUN_1418c7ab0();
        }
        return 1;
    }
    if (_stricmp("OnChangeDetailColor", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nPalette0 = 0;
            int nColor0 = 0;
            m_288 = std::make_pair(nPalette0, nColor0);
            int nPalette = 0;
            int nType = 0;
            FUN_140f024e0(&data, &nPalette, &nType);
            FUN_1418c77c0(nPalette, nType);
            FUN_1418c7aa0(1);
            FUN_1418c7ab0();
        }
        return 1;
    }
    if (_stricmp("OnChangeDegree", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            FUN_1418c7400(0);
            int nDegree = data.FUN_1422b8a10();
            FUN_1418c79f0((float)nDegree);
            FUN_1418c7ab0();
        }
        return 1;
    }
    if (_stricmp("OnChangePosition", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            FUN_1418c7400(0);
            int nPos = data.FUN_1422b8a10();
            FUN_1418c7830(nPos);
            FUN_1418c7ab0();
        }
        return 1;
    }
    if (_stricmp("OnChangeSize", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            FUN_1418c7400(0);
            int nIndex = data.FUN_1422b8a10();
            float fSize = data.FUN_1422b8c10();
            FUN_1418c78d0(nIndex, fSize);
            FUN_1418c7ab0();
        }
        return 1;
    }
    if (_stricmp("OnClickClose", szMethod) == 0)
    {
        FUN_1418c9d80();
        return 1;
    }
    if (_stricmp("OnClickReset", szMethod) == 0)
    {
        FUN_1418ca420();
        return 1;
    }
    if (_stricmp("OnClickSave", szMethod) == 0)
    {
        if (UIBillDialog* pBill = FUN_140f0a350(0x4e7b))
        {
            MS2Ptr<AScript> spRows(new ASObj(2));
            if (spRows.get())
            {
                unsigned nPrice = 0;
                if (FUN_1418ca510(static_cast<ASObj&>(*spRows), &nPrice))
                {
                    int nShopKind = FUN_1418cbbe0();
                    CStringW strTitle = FUN_1418cb920(nShopKind, m_290);
                    bool bCoupon = FUN_1418cbc00(1) != 0;
                    unsigned nFee = 0;
                    Unk_BSFee* pFee = FUN_1418c74e0(&nFee);
                    int nLevel = FUN_140f01140();
                    int nEvent = FUN_1418ccb40();
                    if (FUN_1401c0d90()->FUN_140476c70(nEvent, nFee, nLevel) == 0)
                        bCoupon = false;
                    MS2Ptr<UIBillDialog::TData> spData(new UIBillDialog::TData);
                    if (spData.get())
                    {
                        spData->m_18 = static_cast<IMessageListener*>(this);
                        spData->m_30 = 1;
                        spData->m_20 = spRows;
                        if (m_1d0.m_20 != 0)
                        {
                            spData->m_60 = bCoupon;
                            spData->m_50 = strTitle;
                            spData->m_58 = FUN_1418cbb40(nShopKind, m_290);
                        }
                        spData->m_34 = pFee->FUN_1406dc510();
                        spData->m_38 = pFee->FUN_1406dc4d0();
                        spData->m_40 = pFee->FUN_1406dc4b0();
                        spData->m_48 = nPrice;
                        pBill->FUN_1418cda20(MS2Ptr<UIBillDialog::TData>(spData));
                        FUN_1403ed2b0()->FUN_141adc530(0x4e7b);
                    }
                }
            }
        }
        return 1;
    }
    if (_stricmp("OnCheckPreviewWithCap", szMethod) == 0)
    {
        if (FUN_1418cbbe0() != 1)
            return 1;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int bPreview = data.FUN_1422b8a90() != 0;
            FUN_1418c7d20(bPreview);
            if (bPreview && m_2b0)
                FUN_141275260(0x270, 1, 0);
        }
        return 1;
    }
    if (_stricmp("OnClickRandomSelect", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nSlot = data.FUN_1422b8a10();
            FUN_1418c7dd0(nSlot);
            m_2b5 = 0;
        }
        return 1;
    }
    if (_stricmp("onChangeSelectedIndexItem", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nIndex = data.FUN_1422b8a10();
            FUN_1418c7fe0(nIndex);
        }
        return 1;
    }
    return 0;
}

// @0x1418c5410
// MS2-FUNCTIONAL: string temporaries differ
void UIBeautyShopDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (m_1b8 == 0)
        return;
    if (_stricmp("getTooltipFee", strMethod) == 0)
    {
        ASObj obj(2);
        unsigned nPrice = 0;
        FUN_1418ca510(obj, &nPrice);
        *pRetVal = obj.FUN_1422bb870();
    }
    else if (_stricmp("getTooltip", strMethod) == 0)
    {
        Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc)
        {
            int nIndex = pArgs->FUN_1422b8a10();
            if (nIndex >= 0 && nIndex < (int)m_198.GetCount())
            {
                MS2Ptr<Unk_BSPriceRow> spRow(m_198.GetAt(nIndex));
                if (!(spRow == 0))
                {
                    Unk_BSFee* pFee = &spRow->m_fee;
                    if (m_290 == 2)
                        *pFee = *m_1d0.FUN_1406e3dc0();
                    unsigned __int64 nPrice = pFee->FUN_1406dc4f0();
                    CStringW strPrice = FUN_14134a220(pFee, &nPrice);
                    ASTooltip tip(1, 2);
                    int nLevel = pPc->vfunc_78();
                    if (FUN_140f01eb0(tip, spRow, nLevel, strPrice))
                        *pRetVal = tip.FUN_1422bb870();
                }
            }
        }
    }
    else if (_stricmp("getTooltipColor", strMethod) == 0)
    {
        ASTooltip tip(1, 2);
        if (FUN_140f01670(tip, 0, pArgs))
            *pRetVal = tip.FUN_1422bb870();
    }
}

// UIItemEventListener overrides.
// @0x1418c57b0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::vfunc_21(void* p)
{
    if (!(m_30 == 0))
    {
        FUN_1418ca240(p);
        if (m_290 == 2)
            m_2c8.AssignRaw(reinterpret_cast<CItem*>(p));
    }
}

// @0x1418c5830
void UIBeautyShopDialog::vfunc_22(void*)
{
}

// @0x1418c5850
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::vfunc_24(void* p)
{
    if (!(m_30 == 0))
        FUN_1418ca240(p);
}

// @0x1418c58a0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::vfunc_25(void* p)
{
    if (!(m_30 == 0))
        FUN_1418ca240(p);
}

// IItemCustomizeEventListener overrides.
// @0x1418c58f0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::vfunc_0(void* p, int)
{
    if (!(m_1b8 == 0) && m_30.get() && p)
        FUN_1418c7400(0);
    return 1;
}

// @0x1418c5980
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::vfunc_1(void* p)
{
    if (!(m_1b8 == 0) && m_30.get() && p)
    {
        if (m_1b8->FUN_140cd17e0() == FUN_1414124a0(p))
        {
            FUN_1418c7400(0);
            m_30->Invoke("startChangeCustomPosition");
            FUN_1418c7ab0();
        }
    }
    return 1;
}

// @0x1418c5a90
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::vfunc_2(void* p, float fValue, int nIndex)
{
    if (!(m_1b8 == 0) && m_30.get() && p)
    {
        if (m_1b8->FUN_140cd17e0() == FUN_1414124a0(p))
        {
            FUN_1418c7400(0);
            Unk_BSPartObj* pPart = static_cast<Unk_BSPartObj*>(p);
            const float* pRange = pPart->vfunc_24(nIndex);
            float fSize = fValue;
            if (pRange[2] != 0.0f)
                fSize = (pRange[0] - fValue) + pRange[1];
            int nSel;
            if (pPart->vfunc_27() - nIndex - 1 < 0)
                nSel = 0;
            else
                nSel = pPart->vfunc_27() - nIndex - 1;
            m_30->Invoke("changeCustomSize", fSize, nSel);
        }
    }
    return 1;
}

// @0x1418c5c90
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::vfunc_3(void* p, float fValue)
{
    if (!(m_1b8 == 0) && m_30.get() && p)
    {
        if (m_1b8->FUN_140cd17e0() == FUN_1414124a0(p))
        {
            FUN_1418c7400(0);
            int nDegree = (int)fValue;
            if (nDegree < 0)
                nDegree += 360;
            m_30->Invoke("changeCustomDegree", nDegree % 360);
        }
    }
    return 1;
}

// @0x1418c5dc0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::vfunc_84()
{
    if (!(m_1b8 == 0) && m_290 != 0)
    {
        if (m_290 == 3)
            vfunc_86();
        else
            vfunc_87();
    }
}

// @0x1418c5e40
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::vfunc_85()
{
    if (!(m_1b8 == 0) && m_290 != 0)
    {
        if (m_290 == 3)
            vfunc_86();
        else
            vfunc_87();
    }
}

// Build the current item of the skin page.
// @0x1418c5ec0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::vfunc_86()
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        ASObj data(2);
        ASObj item(2);
        if (FUN_1418cbbe0() == 4)
        {
            MS2Ptr<CItemData> spData = FUN_14053f870(0x9a1d21);
            if (!(spData == 0))
            {
                int nColor = FUN_1418cbdc0(0x9a1d21);
                FUN_140f327a0(FUN_14053f870(0x9a1d21), nColor, item, 1);
                FUN_1418caf20(0x9a1d21);
                data.FUN_1409adbe0("skincolor", item.FUN_1422baa20("color"));
                data.FUN_1409adbe0("skinSelectedIndex", item.FUN_1422baa20("colorSelectedIndex"));
                m_30->Invoke("buildCurrentItem", Scaleform::GFx::Value(data.FUN_1422bb870()));
            }
        }
        else
        {
            FUN_140d74390(BlockFormat(0x272, -1), 0,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopDialog::FUN_1418c9960));
        }
    }
}

// Build the item list.
// @0x1418c6250
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::vfunc_87()
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        ASArray items(2);
        int nSelectedId = 0;
        int nSelectedIndex = -1;
        if (m_290 == 1)
            FUN_1418c6580(items, &nSelectedId, &nSelectedIndex);
        m_2e0 = nSelectedId;
        m_2e4 = nSelectedIndex;
        int nCount = (int)m_198.GetCount();
        for (int i = 0; i < nCount; i++)
        {
            MS2Ptr<Unk_BSPriceRow> spRow(static_cast<const ATL::CAtlArray<MS2Ptr<Unk_BSPriceRow> >&>(m_198).GetAt(i));
            if (!(spRow == 0))
            {
                if (m_2e0 != spRow->m_id)
                {
                    ASObj row(2);
                    if (FUN_1418c6870(row, MS2Ptr<Unk_BSPriceRow>(spRow), pPc, false))
                    {
                        row.FUN_1407cb9c0("idx", i);
                        items.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
                    }
                }
            }
        }
        long nSelect = (m_290 == 2) ? -1 : 0;
        m_30->Invoke("buildItems", Scaleform::GFx::Value(items.FUN_1422bb870()), nSelect);
    }
}

// The row of the item being worn (the first entry of the list).
// @0x1418c6580
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::FUN_1418c6580(ASArray& out, int* pnItemId, int* pnIndex)
{
    *pnItemId = 0;
    *pnIndex = -1;
    if (m_1b8 == 0)
        return 0;
    *pnItemId = m_1b8->FUN_140cd17e0();
    MS2Ptr<Unk_BSPriceRow> spRow(0);
    for (size_t i = 0; i < m_198.GetCount(); i++)
    {
        MS2Ptr<Unk_BSPriceRow> spCur(static_cast<const ATL::CAtlArray<MS2Ptr<Unk_BSPriceRow> >&>(m_198).GetAt(i));
        if (*pnItemId == spCur->m_id)
        {
            spRow = spCur;
            *pnIndex = (int)i;
            break;
        }
    }
    if (spRow == 0)
        spRow = FUN_1418cbeb0(m_1b8->FUN_140cd17e0());
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (spRow.get() != 0)
    {
        ASObj row(2);
        if (FUN_1418c6870(row, MS2Ptr<Unk_BSPriceRow>(spRow), pPc, true) == 1)
            row.FUN_1407cb9c0("idx", *pnIndex);
        out.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
    }
    return 1;
}

// Fill one list row (the item, its colours, the price, the lock).
// @0x1418c6870
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopDialog::FUN_1418c6870(ASObj& row, MS2Ptr<Unk_BSPriceRow> spRow, Unk_BSPlayer* pPc, bool bMy)
{
    if (!(spRow == 0) && pPc)
    {
        int nItemId = spRow->m_id;
        if (nItemId == 0)
            return false;
        MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
        if (!(spData == 0))
        {
            FUN_140f324f0(row, MS2Ptr<CItemData>(spData), 0);
            row.FUN_1407cbbe0("my", bMy);
            unsigned nMerat = spRow->FUN_1406e3bc0();
            row.FUN_1409c0d20("merat", nMerat);
            if (!bMy)
                row.FUN_1407cb9c0("saleTag", spRow->m_saleTag);
            int nLevel = pPc->vfunc_78();
            bool bLocked = false;
            if (!FUN_140f02860(MS2Ptr<Unk_BSPriceRow>(spRow), nLevel, &bLocked))
                return false;
            row.FUN_1407cbbe0("saleLock", bLocked);
            return true;
        }
        return false;
    }
    return false;
}

// @0x1418c6af0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::FUN_1418c6af0()
{
    if (m_30.get())
    {
        MS2Ptr<Unk_140acd6e0> spSave = FUN_140bb4b10(CString("m_save"));
        if (spSave.get())
            return spSave->FUN_1422c2030();
    }
    return 0;
}

// @0x1418c6bc0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c6bc0(int nValue)
{
    if (m_30.get())
    {
        MS2Ptr<Unk_140acd6e0> spSave = FUN_140bb4b10(CString("m_save"));
        if (spSave.get())
            spSave->FUN_1422c1fe0(nValue);
    }
}

// @0x1418c6c80
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c6c80(int nValue)
{
    if (m_30.get())
    {
        MS2Ptr<Unk_140acd6e0> spReset = FUN_140bb4b10(CString("m_reset"));
        if (spReset.get())
            spReset->FUN_1422c1fe0(nValue);
    }
}

// Show the fee (and the sale price when an event applies).
// @0x1418c6d40
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c6d40(Unk_BSFee* pFee, unsigned* pPrice)
{
    if (m_30 == 0)
    {
        int nLevel = FUN_140f01140();
        int nEvent = FUN_1418ccb40();
        bool bSale = FUN_1401c0d90()->FUN_140476cf0(nEvent, nLevel) == 0;
        if (pFee == 0)
        {
            CStringW strDefault = FUN_14028b8e0(CStringW(L"s_beauty_fee_default"));
            m_30->Invoke("setFee", CStringW(strDefault), CStringW(strDefault), bSale, false);
        }
        else
        {
            unsigned __int64 nBase = *pPrice;
            unsigned nSale = FUN_1401c0d90()->FUN_140476c70(nEvent, *pPrice, nLevel);
            bool bDiscount = nBase != nSale;
            if (bDiscount)
            {
                unsigned __int64 nSalePrice = nSale;
                CStringW strPrice = FUN_14134a220(pFee, &nSalePrice);
                m_30->Invoke("setFee", FUN_1409404f0(nBase), CStringW(strPrice), bSale, bDiscount);
            }
            else
            {
                CStringW strPrice = FUN_14134a220(pFee, &nBase);
                m_30->Invoke("setFee", FUN_1409eb450(nSale), CStringW(strPrice), bSale, bDiscount);
            }
        }
    }
}

// Show the item (the colour detail of the current part).
// @0x1418c7180
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7180(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!(spData == 0))
    {
        ASObj item(2);
        int nMode = FUN_1418cbd30(nItemId) == 1 ? 3 : 2;
        if (FUN_140f32290(item, MS2Ptr<CItemData>(spData), MS2Ptr<Customize>(m_1b8), nMode, 0xf, 0))
        {
            int nDetail = 0;
            AScript detail(item.FUN_1422baa20("colorDetail"), 2);
            if (!detail.FUN_1422ba9a0())
                nDetail = FUN_1409c1750(detail.FUN_1422bb870());
            FUN_1418c7aa0(nDetail);
        }
        m_30->Invoke("buildCurrentItem", Scaleform::GFx::Value(item.FUN_1422bb870()));
    }
}

// Apply the "preview with cap" flag and tell the page.
// @0x1418c7400
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7400(int bPreview)
{
    if (!m_30.IsNull() && m_2ac != bPreview)
    {
        FUN_1418c7d90(bPreview);
        m_2ac = FUN_1409c1720(m_30->Invoke("forceChangeCheckPreviewWithCap", bPreview)) != 0;
    }
}

// The fee row of the page and its price.
// @0x1418c74e0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
Unk_BSFee* UIBeautyShopDialog::FUN_1418c74e0(unsigned* pPrice)
{
    Unk_BSFee* pFee = 0;
    *pPrice = 0;
    if (!(m_1b8 == 0))
    {
        bool bNoFee = true;
        if (m_290 == 1)
        {
            if (m_1b8->FUN_140cd28a0() == 0)
            {
                if (m_1b8->FUN_140cd2ea0() != 0)
                {
                    pFee = m_1d0.FUN_1406e3de0();
                    bNoFee = false;
                }
            }
            else
            {
                if (m_278.get() == 0)
                    pFee = m_1d0.FUN_1406e3dc0();
                else
                    pFee = &m_278->m_fee;
                bNoFee = false;
            }
        }
        else if (m_290 == 2)
        {
            pFee = m_1d0.FUN_1406e3dc0();
            bNoFee = false;
        }
        else if (m_290 == 3)
        {
            int nColor = m_1b8->FUN_140cd2ea0();
            if (nColor != 0)
                pFee = m_1d0.FUN_1406e3de0();
            bNoFee = nColor == 0;
        }
        if (!bNoFee && pFee)
            *pPrice = pFee->FUN_1406dc4f0();
        if (pFee == 0)
            pFee = m_1d0.FUN_1406e3dc0();
    }
    else
        pFee = m_1d0.FUN_1406e3dc0();
    return pFee;
}

// @0x1418c76d0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c76d0(int nItemId)
{
    if (!(m_1b8 == 0))
    {
        if (FUN_1418caf20(nItemId) == 0)
            m_1b8->FUN_140cd2660(nItemId);
        FUN_1418c7180(nItemId);
    }
}

// @0x1418c7750
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7750(int nPalette, int nColor)
{
    if (!(m_1b8 == 0))
        m_1b8->FUN_140cd3220(nPalette, nColor, 0);
}

// @0x1418c77c0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c77c0(int nA, int nB)
{
    if (!(m_1b8 == 0))
        m_1b8->FUN_140cd32f0(nA, nB, 0);
}

// @0x1418c7830
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7830(int nPos)
{
    if (!(m_1b8 == 0))
    {
        Unk_BSPartHandle part = m_1b8->FUN_140cd1a30();
        if (part.FUN_140cd5210())
            part.FUN_140cd5240()->vfunc_9(nPos);
    }
}

// @0x1418c78d0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c78d0(int nIndex, float fSize)
{
    if (!(m_1b8 == 0))
    {
        Unk_BSPartHandle part = m_1b8->FUN_140cd1a30();
        if (part.FUN_140cd5210())
        {
            const float* pRange = part.FUN_140cd5240()->vfunc_24(nIndex);
            float fValue = fSize;
            if (pRange[2] != 0.0f)
                fValue = (pRange[0] - fSize) + pRange[1];
            part.FUN_140cd5240()->vfunc_8(nIndex, fValue);
        }
    }
}

// @0x1418c79f0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c79f0(float fDegree)
{
    if (!(m_1b8 == 0))
    {
        Unk_BSPartHandle part = m_1b8->FUN_140cd1a30();
        if (part.FUN_140cd5210())
            part.FUN_140cd5240()->vfunc_10(fDegree);
    }
}

// @0x1418c7aa0
void UIBeautyShopDialog::FUN_1418c7aa0(int)
{
}

// Refresh the buttons (save / reset) and the fee.
// @0x1418c7ab0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7ab0()
{
    if (!(m_1b8 == 0))
    {
        int nSave = m_1b8->FUN_140cd2a00();
        int nReset;
        if (m_290 == 2)
        {
            nSave = 1;
            nReset = 1;
        }
        else
        {
            nReset = nSave;
            if (m_278.get() != 0)
            {
                bool bLocked = false;
                Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pPc)
                {
                    if (FUN_140f02b10(MS2Ptr<Unk_BSPriceRow>(m_278), (short)pPc->vfunc_78()))
                        bLocked = true;
                }
                if (m_288.first != 0 && FUN_140f02a80(m_288.first, m_288.second))
                    bLocked = true;
                if (bLocked)
                {
                    nSave = 0;
                    nReset = 1;
                }
            }
        }
        FUN_1418c6bc0(nSave);
        FUN_1418c6c80(nReset);
        unsigned nPrice = 0;
        Unk_BSFee* pFee = FUN_1418c74e0(&nPrice);
        if (nSave == 0 && nPrice == 0)
        {
            unsigned nZero = 0;
            FUN_1418c6d40(0, &nZero);
        }
        else
            FUN_1418c6d40(pFee, &nPrice);
    }
}

// @0x1418c7ce0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7ce0()
{
    if (vfunc_55() == 0)
        FUN_1418c7ab0();
}

// @0x1418c7d20
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7d20(int bPreview)
{
    if (!(m_30 == 0))
    {
        if (m_2ac != bPreview)
            FUN_1418c7d90(bPreview);
        m_2ac = bPreview;
    }
}

// @0x1418c7d90
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7d90(int bPreview)
{
    if (bPreview == 0)
        FUN_1418caec0();
    else
        FUN_1418cae60();
}

// Pick a style slot (-1: none selected).
// @0x1418c7dd0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7dd0(int nSlot)
{
    if (!(m_30 == 0))
    {
        if (nSlot == -1)
        {
            FUN_140d74390(BlockFormat(0x272, -1), 0,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopDialog::FUN_1418c9960));
        }
        else
        {
            m_1b8->FUN_140cd22f0(FUN_140f01070(FUN_1418cbbe0()));
            if (m_290 == 2)
            {
                COutPacket packet(0x23, 0);
                packet.vfunc_o10_1(0xc);
                packet.vfunc_o10_1((unsigned char)nSlot);
                FUN_140710590(packet);
            }
            if (nSlot == 1)
                FUN_1418cb6a0(MS2Ptr<CItem>(m_2c8));
        }
    }
}

// @0x1418c7fe0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c7fe0(int nSlot)
{
    if (!(m_30 == 0) && nSlot != -1)
    {
        MS2Ptr<CItem> spItem(nSlot == 0 ? m_2b8 : m_2c8);
        m_1b8->FUN_140cd1c90(spItem.get());
    }
}

// The beauty shop packets (0x31).
// @0x1418c80b0
// MS2-FUNCTIONAL: large EH frame; temporaries and branch order differ
void UIBeautyShopDialog::FUN_1418c80b0(CInPacket& packet)
{
    unsigned char nOp = packet.vfunc_o8_1();
    if (nOp == 0)
    {
        m_198.RemoveAll();
        m_290 = packet.vfunc_o8_1();
        m_1d0.FUN_1406e5420(packet);
        m_294 = packet.vfunc_o8_1();
        m_298 = packet.vfunc_o8_1();
        m_2a0 = packet.vfunc_o8_4();
        unsigned nCount = (unsigned short)packet.vfunc_o8_2();
        if (nCount != 0)
        {
            for (unsigned i = 0; i < nCount; i++)
            {
                MS2Ptr<Unk_BSPriceRow> spRow(new Unk_BSPriceRow);
                if (spRow.get() != 0)
                {
                    spRow->FUN_1406e37f0(packet);
                    m_198.Add(spRow);
                }
            }
        }
        FUN_1418cb6d0();
        if (m_2a8 != 0)
            FUN_1418c8ee0();
    }
    else if (nOp == 9)
    {
        int nItemId = packet.vfunc_o8_3();
        int nCount = packet.vfunc_o8_3();
        if (nItemId != 0 && nCount != 0)
            FUN_140961010(0x996, 1, 1, FUN_1401a9d70()->FUN_141811980(1, nItemId));
    }
    if (vfunc_55() == 0)
    {
        m_2d8 = 0;
        if (nOp == 0xb)
        {
            int nOldId = packet.vfunc_o8_3();
            int nNewId = packet.vfunc_o8_3();
            if (m_2b8.get() != 0)
            {
                if (m_2b8->FUN_1405276c0() == nOldId && m_2c8.get() != 0)
                {
                    if (m_2c8->FUN_1405276c0() == nNewId)
                        FUN_1418cb000(MS2Ptr<CItem>(m_2b8), MS2Ptr<CItem>(m_2c8));
                }
            }
        }
        else if (nOp == 0xc)
        {
            int nCoupon = packet.vfunc_o8_3();
            char bMail = packet.vfunc_o8_1();
            CStringW strMsg;
            if (nCoupon == 0)
                strMsg = FUN_14028b8e0(CStringW(L"s_beauty_msg_complete_apply_special_hair"));
            else if (bMail == 1)
                strMsg = FUN_1405c2690(CStringW(L"s_beauty_msg_complete_apply_return_coupon_to_mail"),
                                       FUN_1401a9d70()->FUN_141811980(1, nCoupon));
            else
                strMsg = FUN_1405c2690(CStringW(L"s_beauty_msg_complete_apply_return_coupon"),
                                       FUN_1401a9d70()->FUN_141811980(1, nCoupon));
            FUN_1412751f0(strMsg, 3, 1);
        }
        else if (nOp == 0x10)
        {
            m_298++;
            FUN_1412752d0(CStringW(L"s_beauty_msg_complete_save_hair_style"), 1);
        }
        else if (nOp == 0x11)
        {
            m_298++;
            m_294 += FUN_140f01220();
            m_294 = FUN_140f011b0() < m_294 ? FUN_140f011b0() : m_294;
            FUN_1412752d0(CStringW(L"s_beauty_msg_complete_save_hair_style"), 1);
        }
        else if (nOp == 8)
        {
            Unk_BSResult nResult = (Unk_BSResult)packet.vfunc_o8_3();
            unsigned nPrice = 0;
            Unk_BSFee* pFee = FUN_1418c74e0(&nPrice);
            switch (nResult)
            {
            case 2:
                FUN_14134a2e0(pFee);
                break;
            default:
                FUN_140d74390(BlockFormat(0x272, nResult), 0,
                              Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopDialog::FUN_1418c9960));
                break;
            case 7:
                FUN_140d74390(FUN_14028de60(0x273), 0,
                              Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopDialog::FUN_1418c9960));
                break;
            case 0xc:
                FUN_140d74390(FUN_14028b8e0(CStringW(L"s_beauty_msg_error_color")), 0, FUN_140b240b0());
                break;
            case 0x12:
                break;
            case 0x13:
                FUN_140d74390(FUN_14028b8e0(CStringW(L"s_beauty_msg_error_style_slot_max")), 0, FUN_140b240b0());
                break;
            case 0x14:
                FUN_14134a120(4, 0, 0);
            }
            if (nResult != 0)
                FUN_1418ca380();
        }
    }
}

// Build the page (called once the swf is loaded and the shop list arrived).
// @0x1418c8ee0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::FUN_1418c8ee0()
{
    if (FUN_1418ccb40() == 0 || m_30 == 0)
        return 0;
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    static_cast<UIDialog*>(this)->vfunc_8(1);
    int bCap = FUN_1418cbc70();
    unsigned nNoPrice = 0;
    FUN_1418c6d40(0, &nNoPrice);
    int nLevel = FUN_140f01140();
    int nEvent = FUN_1418ccb40();
    int bSale = FUN_1401c0d90()->FUN_140476cf0(nEvent, nLevel);
    int nShopKind = FUN_1418cbbe0();
    ASObj init(2);
    init.FUN_1407cb9c0("type", m_290);
    init.FUN_1407cb9c0("category", nShopKind);
    init.FUN_1407cbbe0("isEquipCap", bCap);
    init.FUN_1407cbbe0("isPcBang", bSale == 0);
    int bDetailColor = 0;
    if (nShopKind != 4)
    {
        bDetailColor = FUN_140166410()->FUN_14036d570(0xb6);
        FUN_140f01540(init, bDetailColor);
    }
    init.FUN_1407cbbe0("useDetailColor", bDetailColor);
    FUN_1418cb750(init);
    m_30->Invoke("initData", Scaleform::GFx::Value(init.FUN_1422bb870()));
    m_1b8.AssignRaw(new Customize(FUN_14123c580(pPc), static_cast<IItemCustomizeEventListener*>(this), 0));
    int nSlot = FUN_140f01070(nShopKind);
    if (nShopKind == 1)
        FUN_1418caec0();
    m_1b8->FUN_140cd25c0(nSlot);
    int nDetail = FUN_1418cbdc0(m_1b8->FUN_140cd17e0());
    m_1b8->FUN_140cd38d0(nDetail);
    MS2Ptr<Customize::BeautyShopContext> spContext(new Customize::BeautyShopContext(FUN_1418ccb40(), m_2a0));
    m_1b8->FUN_140cd38f0(spContext);
    FUN_1418c7ab0();
    FUN_1418c7180(m_1b8->FUN_140cd17e0());
    vfunc_84();
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    if (FUN_14025e7c0()->FUN_14116d720())
    {
        MS2Ptr<ASTextField> spTitle = FUN_140bb4cf0(CString("m_title"));
        if (spTitle.get())
        {
            CStringW strTitle = spTitle->FUN_1422c4da0();
            if (strTitle.Find(L"$", 0) == 0)
                strTitle = FUN_14025e7a0()->FUN_1422b0570(CString((const wchar_t*)strTitle));
            strTitle.Append(FUN_140292a70(L"<font color='#909090'>| [debug] shopId: {0}</font>", m_1d0.m_18));
            spTitle->FUN_1422c4f00(strTitle);
        }
    }
    return 1;
}

// Enable the "preview with cap" check box (hair shop only).
// @0x1418c9610
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopDialog::FUN_1418c9610()
{
    if (!(m_30 == 0) && !(m_1b8 == 0))
    {
        if (FUN_1418cbbe0() == 1)
        {
            Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPc)
            {
                MS2Ptr<Unk_InventoryEquipment> spEquip = FUN_1416561a0(pPc)->FUN_1411e1780(6, 2);
                if (spEquip.get())
                    spEquip->FUN_1411dcf10(s_strCustomize);
            }
            m_30->Invoke("setEnableCheckPreviewWithCap", FUN_1418cbc70() != 0);
            if (m_2ac == 0)
                FUN_1418caec0();
            else
                FUN_1418cae60();
        }
    }
    return true;
}

// A game event changed: refresh the sale price.
// @0x1418c9780
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c9780(NotifyObject* pNotify)
{
    NotifyGameEventChanged* pEvent = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pEvent && FUN_140841300(pEvent->m_eventName, "SaleBeautyShop"))
    {
        unsigned nFee = 0;
        Unk_BSFee* pFee = FUN_1418c74e0(&nFee);
        FUN_1418c6d40(pFee, &nFee);
        MS2Ptr<ASMovieClip> spPcBang = FUN_140ba7930(CString("m_pcBang"));
        if ((ASMovieClip*)spPcBang)
        {
            int nLevel = FUN_140f01140();
            int nEvent = FUN_1418ccb40();
            spPcBang->vfunc_4(FUN_1401c0d90()->FUN_140476cf0(nEvent, nLevel) == 0);
        }
        UIBillDialog* pBill;
        if (FUN_1403ed2b0()->FUN_141adc890(0x4e7b) && (pBill = FUN_140f0a350(0x4e7b)) != 0)
            pBill->FUN_1418cda70(nFee);
    }
}

// @0x1418c9960
bool UIBeautyShopDialog::FUN_1418c9960(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
        FUN_1418c9cd0();
    return true;
}

// @0x1418c9990
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopDialog::FUN_1418c9990(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
        FUN_140f01250(data.FUN_141a02f10(0, 0));
    return true;
}

// @0x1418c99e0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopDialog::FUN_1418c99e0(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        if (m_298 == FUN_140f011b0())
            FUN_140d74390(FUN_14028b8e0(CStringW(L"s_beauty_msg_error_style_slot_max")), 0, FUN_140b240b0());
        else
            FUN_140f012d0(data.FUN_141a02f10(0, 0));
    }
    return true;
}

// @0x1418c9ae0
bool UIBeautyShopDialog::FUN_1418c9ae0(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
        return FUN_1418c9610();
    return true;
}

// The active my-codi tab changed.
// @0x1418c9b20
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c9b20(NotifyObject* pNotify)
{
    if (!(m_30 == 0) && pNotify)
    {
        NotifyChangeActiveMyCodiTab* pTab = dynamic_cast<NotifyChangeActiveMyCodiTab*>(pNotify);
        if (pTab == 0 || pTab->m_bActive)
            FUN_1418c9610();
        else
            FUN_140d74390(FUN_14028b8e0(CStringW(L"s_beauty_msg_by_expired_codi")), 0,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopDialog::FUN_1418c9ae0));
    }
}

// @0x1418c9cb0
void UIBeautyShopDialog::FUN_1418c9cb0(int nPalette)
{
    m_2dc = nPalette;
}

// Leave the page: restore the worn item and the field camera.
// @0x1418c9cd0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::FUN_1418c9cd0()
{
    if (m_1b8.get() != 0)
        m_1b8->FUN_140cd22f0(FUN_140f01070(FUN_1418cbbe0()));
    Unk_BSField* pField = FUN_1403ed2d0()->FUN_141bd3620();
    if (pField)
        pField->vfunc_149();
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
    return 1;
}

// Close: ask first when something was changed.
// @0x1418c9d80
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418c9d80()
{
    if (m_290 != 2 && !(m_1b8 == 0))
    {
        if (m_1b8->FUN_140cd2a00() != 0)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FUN_14028de60(0x271), 1);
            spBox->FUN_141a01800(2);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopDialog::FUN_1418c9960));
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
            return;
        }
    }
    FUN_1418c9cd0();
}

// The bill was accepted: send the change.
// @0x1418c9f20
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::FUN_1418c9f20()
{
    if (!(m_1b8 == 0))
    {
        FUN_1418c7400(0);
        int nEvent = FUN_1418ccb40();
        unsigned nPrice = 0;
        Unk_BSFee* pFee = FUN_1418c74e0(&nPrice);
        int nLevel = FUN_140f01140();
        unsigned nSale = FUN_1401c0d90()->FUN_140476c70(nEvent, nPrice, nLevel);
        unsigned __int64 nPay = nSale;
        bool bCanPay = FUN_14134a1d0(pFee, &nPay);
        bool bCoupon = FUN_1418cbc00(IItemCustomizeEventListener::m_10);
        if (!bCanPay && !bCoupon)
        {
            FUN_14134a2e0(pFee);
            return 0;
        }
        int nSlot = FUN_140f01070(FUN_1418cbbe0());
        if (m_290 == 2)
        {
            m_1b8->FUN_140cd22f0(nSlot);
            Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPc)
            {
                MS2Ptr<Unk_InventoryEquipment> spEquip = pPc->FUN_141655e10(FUN_140f01070(FUN_1418cbbe0()));
                m_2b8 = spEquip->FUN_1411dc7a0();
            }
            COutPacket packet(0x23, 0);
            packet.vfunc_o10_1(7);
            packet.vfunc_o10_3(nEvent);
            packet.vfunc_o10_1(IItemCustomizeEventListener::m_10 != 0);
            packet.vfunc_o10_4(m_2a0);
            FUN_140710590(packet);
        }
        else
            m_1b8->FUN_140cd2280(nSlot);
        FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
        m_2d8 = 1;
        return 1;
    }
    return 0;
}

// An item was dropped / double clicked on the page: preview it.
// @0x1418ca240
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::FUN_1418ca240(void* p)
{
    m_2d8 = 0;
    if (!(m_1b8 == 0))
    {
        m_1b8->FUN_140cd22f0(FUN_140f01070(FUN_1418cbbe0()));
        FUN_1418c7ce0();
        FUN_1418ca400();
        FUN_1412761e0(MS2Ptr<AScript>(m_30), 1);
        vfunc_84();
        if (m_290 == 1)
            FUN_1418cb6a0(MS2Ptr<CItem>(reinterpret_cast<CItem*>(p)));
        return 1;
    }
    return 0;
}

// @0x1418ca380
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418ca380()
{
    m_2d8 = 0;
    if (!(m_1b8 == 0))
        FUN_1412761e0(MS2Ptr<AScript>(m_30), 1);
}

// @0x1418ca400
void UIBeautyShopDialog::FUN_1418ca400()
{
    FUN_140f01350();
}

// Reset the preview.
// @0x1418ca420
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418ca420()
{
    if (!(m_30 == 0))
    {
        FUN_1418c7400(0);
        if (m_1b8.get() != 0)
            m_1b8->FUN_140cd22f0(FUN_140f01070(FUN_1418cbbe0()));
        FUN_1418c7ce0();
        if (m_290 == 2)
            m_30->Invoke("setItemsSelectedIndex", -1);
        else
            vfunc_85();
    }
}

// The bill rows (the changes and their prices) and the total.
// @0x1418ca510
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::FUN_1418ca510(ASObj& out, unsigned* pPrice)
{
    if (m_1b8 == 0)
        return 0;
    if (m_290 == 0)
        return 0;
    *pPrice = 0;
    Unk_BSFee* pFee = FUN_1418c74e0(pPrice);
    ASArray rows(2);
    CStringW strRow = FUN_14028b8e0(CStringW(L"s_bill_list_row"));
    if (m_290 == 2)
    {
        out.FUN_1409c0dc0("category", "$s_beauty_special_hair");
        ASObj row(2);
        CStringW strChange = FUN_14025e7a0()->FUN_1422b0570(CString("$s_beauty_change_style"));
        row.FUN_1407cbb20("detail", FUN_1401e8510(strRow, strChange));
        unsigned __int64 nPrice = *pPrice;
        CStringW strPrice = FUN_14134a220(pFee, &nPrice);
        row.FUN_1407cbb20("strPrice", CStringW(strPrice));
        rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
    }
    else
    {
        out.FUN_1407cbb20("category", FUN_140f010c0(m_1b8->FUN_140cd17e0()));
        ASObj row(2);
        if (m_1b8->FUN_140cd28a0() == 0)
        {
            if (m_1b8->FUN_140cd2ea0() == 0)
            {
                *pPrice = 0;
                int nCrop = m_1b8->FUN_140cd3000();
                CStringW strDetail = FUN_14025e7a0()->FUN_1422b0570(CString(nCrop == 0 ? "$s_beauty_none" : "$s_beauty_crop"));
                unsigned __int64 nPrice = *pPrice;
                CStringW strPrice = nCrop == 0 ? FUN_14028b8e0(CStringW(L"s_beauty_fee_default"))
                                               : FUN_14134a220(pFee, &nPrice);
                row.FUN_1407cbb20("detail", CStringW(strDetail));
                row.FUN_1407cbb20("strPrice", CStringW(strPrice));
                rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
            }
            else
            {
                CStringW strChange = FUN_14025e7a0()->FUN_1422b0570(CString("$s_beauty_change_color"));
                row.FUN_1407cbb20("detail", FUN_1401e8510(strRow, strChange));
                unsigned __int64 nPrice = *pPrice;
                row.FUN_1407cbb20("strPrice", FUN_14134a220(pFee, &nPrice));
                rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
            }
        }
        else
        {
            CStringW strChange = FUN_14025e7a0()->FUN_1422b0570(CString("$s_beauty_change_style"));
            row.FUN_1407cbb20("detail", FUN_1401e8510(strRow, strChange));
            unsigned __int64 nPrice = *pPrice;
            row.FUN_1407cbb20("strPrice", FUN_14134a220(pFee, &nPrice));
            rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
        }
    }
    out.FUN_1409adbe0("list", Scaleform::GFx::Value(rows.FUN_1422bb870()));
    return 1;
}

// @0x1418cae60
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418cae60()
{
    if (!(m_1b8 == 0))
        m_1b8->FUN_140cd24a0(6);
}

// @0x1418caec0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418caec0()
{
    if (!(m_1b8 == 0))
        m_1b8->FUN_140cd2530(6);
}

// Preview the item unless it is already worn.
// @0x1418caf20
int UIBeautyShopDialog::FUN_1418caf20(int nItemId)
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    int nCurrent = m_1b8->FUN_140cd17e0();
    if (nCurrent == 0 || nCurrent != nItemId)
    {
        if (FUN_1416561a0(pPc)->FUN_1411e0c30(nItemId) == 0)
            m_1b8->FUN_140cd1d50(nItemId);
        if (m_290 != 4)
            m_1b8->FUN_140cd2660(nItemId);
    }
    return 1;
}

// The "which hair do you want to keep" dialog (the saved style against the new one).
// @0x1418cb000
// MS2-FUNCTIONAL: large EH frame; temporaries and branch order differ
void UIBeautyShopDialog::FUN_1418cb000(MS2Ptr<CItem> spCur, MS2Ptr<CItem> spNew)
{
    if (!(m_30 == 0) && !(spCur == 0) && !(spNew == 0))
    {
        if (m_290 == 2)
        {
            ASObj cur(2);
            FUN_140f324f0(cur, MS2Ptr<CItemData>(reinterpret_cast<CItemData*>(spCur->FUN_140527840())), 0);
            CStringW strCur = FUN_1405c2690(CStringW(L"s_beauty_fmt_style_select_cur_hair"),
                                            FUN_1401a9d70()->FUN_141811980(1, spCur->FUN_1405276c0()));
            if (m_1d0.m_28 != 0)
            {
                MS2Ptr<CItemData> spCoupon = FUN_14053f870(m_1d0.m_28);
                if (spCoupon.get() != 0)
                {
                    int nCouponId = m_1d0.m_28;
                    int nZero = 0;
                    CStringW strImg = FUN_140275590(L"<img src='{0}' vspace='{1}'>", FUN_1418fe870(2, &nZero, nCouponId), nZero);
                    int nOne = 1;
                    CStringW strCoupon = FUN_141081c60(CStringW(L"s_beauty_fmt_return_coupon"), strImg,
                                                       FUN_1401a9d70()->FUN_141811980(1, nCouponId), nOne);
                    if (!strCoupon.IsEmpty())
                    {
                        strCur.Append(L"\n");
                        strCur.Append(strCoupon);
                    }
                }
                cur.FUN_1407cbb20("itemname", CStringW(strCur));
            }
            ASObj nw(2);
            FUN_140f324f0(nw, MS2Ptr<CItemData>(reinterpret_cast<CItemData*>(spNew->FUN_140527840())), 0);
            CStringW strNew = FUN_1405c2690(CStringW(L"s_beauty_fmt_style_select_new_hair"),
                                            FUN_1401a9d70()->FUN_141811980(1, spNew->FUN_1405276c0()));
            nw.FUN_1407cbb20("itemname", CStringW(strNew));
            ASObj both(2);
            both.FUN_1409adbe0("item0", Scaleform::GFx::Value(cur.FUN_1422bb870()));
            both.FUN_1409adbe0("item1", Scaleform::GFx::Value(nw.FUN_1422bb870()));
            m_30->Invoke("openStyleSelectDialog", Scaleform::GFx::Value(both.FUN_1422bb870()));
            m_2b5 = 1;
        }
    }
}

// @0x1418cb6a0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418cb6a0(MS2Ptr<CItem>)
{
}

// @0x1418cb6d0
void UIBeautyShopDialog::FUN_1418cb6d0()
{
}

// @0x1418cb6e0
void UIBeautyShopDialog::FUN_1418cb6e0(int n)
{
    if (m_30.get())
        m_30->Invoke("enableCustomColorDetail", n);
}

// The guide movie of the page (hair and makeup only).
// @0x1418cb750
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopDialog::FUN_1418cb750(ASObj& out)
{
    int nShopKind = FUN_1418cbbe0();
    bool bGuide = nShopKind == 1 || nShopKind == 2;
    if (bGuide)
    {
        CString strCategory;
        CString strPath;
        if (nShopKind == 1)
        {
            strCategory = "hair";
            strPath = FUN_1401d3200()->m_hairGuide.FUN_140298f80();
        }
        else if (nShopKind == 2)
        {
            strCategory = "makeUp";
            strPath = FUN_1401d3200()->m_makeUpGuide.FUN_140298f80();
        }
        out.FUN_1407cba60("guideCategory", CString(strCategory));
        out.FUN_1407cba60("guideMoviePath", CString(strPath));
    }
}

// The bill's coupon line.
// @0x1418cb920
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
CStringW UIBeautyShopDialog::FUN_1418cb920(int nShopKind, int nMode)
{
    if (m_1d0.m_20 == 0)
    {
        if (nShopKind == 1)
        {
            if (nMode == 2)
                return FUN_14028b8e0(CStringW(L"s_bill_coupon_special"));
            return FUN_14028de60(0x991);
        }
        else if (nShopKind == 2)
            return FUN_14028de60(0x993);
        else if (nShopKind == 3)
            return FUN_14028de60(0x992);
        else if (nShopKind == 4)
            return FUN_14028de60(0x994);
        else if (nShopKind == 5)
            return FUN_14028de60(0x995);
        return CStringW(L"");
    }
    CStringW strCoupon = FUN_1401a9d70()->FUN_141811980(1, m_1d0.m_20);
    return FUN_1405c2690(CStringW(L"s_bill_coupon_beauty_coupon"), strCoupon);
}

// @0x1418cbb40
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
CStringW UIBeautyShopDialog::FUN_1418cbb40(int nShopKind, int nMode)
{
    if (nMode == 2)
        return FUN_14028b8e0(CStringW(L"s_beauty_msg_bill_warning_special_hair"));
    return CStringW(L"");
}

// @0x1418cbbe0
int UIBeautyShopDialog::FUN_1418cbbe0()
{
    return m_1d0.m_1c;
}

// The sale event of the coupon is active.
// @0x1418cbc00
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopDialog::FUN_1418cbc00(int n)
{
    if (n == 0 || m_1d0.m_2c == 0)
        return false;
    return DAT_143ab2a90.FUN_140a60ec0(m_1d0.m_2c) == 1;
}

// The hair shop and the player wears something in the cap slot.
// @0x1418cbc70
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopDialog::FUN_1418cbc70()
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    bool bResult = false;
    if (FUN_1418cbbe0() == 1)
    {
        m_2b0 = FUN_14165f460(pPc)->FUN_1412706f0(0);
        MS2Ptr<Unk_InventoryEquipment> spCap = FUN_1416561a0(pPc)->FUN_1411e1a50(6, 0);
        bResult = spCap.get() != 0;
    }
    return bResult;
}

// @0x1418cbd30
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopDialog::FUN_1418cbd30(int nItemId)
{
    if (m_30 == 0)
        return false;
    bool bResult = true;
    if (m_1d0.m_30 == 1 && m_2e4 == -1)
        bResult = m_2e0 != nItemId;
    return bResult;
}

// The colour palette of the item (the one picked, or the item's own).
// @0x1418cbdc0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopDialog::FUN_1418cbdc0(int nItemId)
{
    if (m_2dc != 0)
    {
        MS2Ptr<Unk_BSColorList> spPalette = FUN_140281980()->FUN_140558ad0(m_2dc);
        if (spPalette.get() != 0)
            return m_2dc;
    }
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!(spData == 0))
        return static_cast<Unk_BSItemData*>(spData.get())->FUN_14053e260();
    return 0;
}

// A blank price row for the item.
// @0x1418cbeb0
MS2Ptr<Unk_BSPriceRow> UIBeautyShopDialog::FUN_1418cbeb0(int nItemId)
{
    MS2Ptr<Unk_BSPriceRow> spRow(new Unk_BSPriceRow());
    spRow->m_id = nItemId;
    return spRow;
}

// ---- the dialog classes the bill looks up ----

// The item colouring dialog (RTTI UIItemColoringDialog, UI id 0x4e23): only the sale event.
class UIItemColoringDialog : public UIDialog
{
public:
    int FUN_1418ce5b0() { return m_1c0; }       // 0x1418ce5b0 the sale event id
    char m_pad_178[0x1c0 - 0x178];
    int m_1c0;
};
class Unk_BSMarketDialog;
UIBeautyShopDialog* FUN_141742770(int nId);                                  // the beauty shop page when it is open
Unk_BSMarketDialog* FUN_141296ab0(int nId);
unsigned FUN_140fdcb30(Unk_BSMarketDialog* p);                               // the price of the market purchase
void FUN_140eabc00(CStringW& strLabel, CStringW& strSum, int nPrice);        // the meret price strings
void FUN_141349f30(CStringW& strOut, int nFeeType, int nCurrency, int nPrice, const CString& strCurrency);

// @0x1418ce0c0
static UIBeautyShopStyleDialog* FUN_1418ce0c0(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIBeautyShopStyleDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x1418ce160
static UIItemColoringDialog* FUN_1418ce160(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIItemColoringDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x1418ce200
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, CStringW a2, CStringW a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1.GetString());
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2.GetString());
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3.GetString());
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1418ce360
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, int a2, CString a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bce70(args.FUN_1409b1f70(2), a3.GetString());
    return FUN_1422bb8f0(szMethod, args);
}

// ---- UIBillDialog ----

// The scaleform dialog object of the bill.
class ASDialog : public ASDisplayObjectContainer
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(const CString& strMode);              // "normal" / "checkbox"
    Scaleform::GFx::Value FUN_140cbe3a0(const char* szMethod, const wchar_t* szArg);
};

// The bill's check box ("m_checkbox").
class Unk_BSCheckBox : public ASDisplayObject
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
    virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(int n);
    void FUN_1422cdfb0(const CStringW& strLabel);
    void FUN_1422c1fe0(unsigned int bEnabled);
    void FUN_1422ce090(int bChecked);
};

// The UI message the bill answers its owner with.
class Unk_BSUIMsg : public UIMsg
{
public:
    Unk_BSUIMsg();                                              // 0x1422e4490
    ~Unk_BSUIMsg();                                             // 0x140c30570
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};

// @0x1418cd0c0
UIBillDialog::UIBillDialog()
    : m_188(0)
{
    m_80 = 0;
    m_58 = 0;
    FUN_141924170(1);
}

// @0x1418cd170
UIBillDialog::~UIBillDialog()
{
    m_188 = 0;
}

// @0x1418cd200
CString UIBillDialog::vfunc_1()
{
    return CString("BillDialog");
}

// @0x1418cd250
void UIBillDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    m_188 = 0;
    m_180.Empty();
}

// Fill the dialog: the mode, the check box, the warning and the rows.
// @0x1418cd2a0
// MS2-FUNCTIONAL: large EH frame; temporaries and branch order differ
void UIBillDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    if (!(m_188 == 0) && !(m_30 == 0))
    {
        ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30.get());
        if (pDlg)
        {
            pDlg->FUN_140cbe3a0("initData", L"");
            MS2Ptr<AScript> spRows(m_188->m_20);
            if (spRows.get())
            {
                CString strMode(m_188->m_50.GetLength() < 1 ? "normal" : "checkbox");
                pDlg->vfunc_13(strMode);
                CStringW& strCheck = m_188->m_50;
                int bEnabled = m_188->m_60;
                if (!strCheck.IsEmpty())
                {
                    MS2Ptr<Unk_BSCheckBox> spCheck = FUN_140e52670(CString("m_checkbox"));
                    if (spCheck.get())
                    {
                        spCheck->FUN_1422cdfb0(strCheck);
                        spCheck->FUN_1422c1fe0(bEnabled);
                        spCheck->FUN_1422ce090(bEnabled);
                        spCheck->vfunc_24(1);
                    }
                    MS2Ptr<ASTextField> spWarning = FUN_140bb4cf0(CString("m_warning"));
                    if (spWarning.get())
                        spWarning->FUN_1422c4cd0(m_188->m_58);
                }
                pDlg->Invoke("buildList", Scaleform::GFx::Value(spRows->FUN_1422bb870()), m_188->m_30, CString(strMode));
            }
        }
        vfunc_8(1);
    }
}

// @0x1418cd740
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBillDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() == 0)
    {
        if (m_30.IsNull())
            vfunc_67();
        return 0;
    }
    return 1;
}

// The player answered the bill.
// @0x1418cd7a0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBillDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (vfunc_55() == 1 || m_188 == 0)
        return 0;
    CString strMethod(szMethod);
    if (_stricmp("OnSubmit", strMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nResult = data.FUN_1422b8a10();
            int bChecked = data.FUN_1422b8a90() ? 1 : 0;
            if (IMessageListener* pOwner = m_188->m_18)
            {
                Unk_BSUIMsg msg;
                msg.FUN_1422b7f70(nResult);
                msg.FUN_1422b7f70(bChecked);
                pOwner->OnMessage(this, &msg);
            }
            vfunc_67();
        }
        return 1;
    }
    if (_stricmp("OnSetSumPrice", strMethod) == 0)
    {
        FUN_1418cda70(m_188->m_48);
        return 1;
    }
    return 0;
}

// @0x1418cda20
void UIBillDialog::FUN_1418cda20(MS2Ptr<TData> spData)
{
    m_188 = spData;
}

// Show the total (and the original price when a sale applies).
// @0x1418cda70
// MS2-FUNCTIONAL: large EH frame; temporaries and branch order differ
void UIBillDialog::FUN_1418cda70(int nPrice)
{
    if (!(m_188 == 0) && !(m_30 == 0))
    {
        int nSale = 0;
        int nSalePrice = nPrice;
        Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc)
        {
            int nLevel = FUN_141658f30(pPc);
            int nShop = m_188->m_30;
            if (nShop == 0)
            {
                if (UIItemColoringDialog* pDlg = FUN_1418ce160(0x4e23))
                {
                    int nEvent = pDlg->FUN_1418ce5b0();
                    nSalePrice = FUN_1401c0d90()->FUN_140476c70(nEvent, nPrice, nLevel);
                    nSale = FUN_1401c0d90()->FUN_140476cf0(nEvent, nLevel);
                }
            }
            else if (nShop == 1)
            {
                if (UIBeautyShopDialog* pDlg = FUN_141742770(0x4eee))
                {
                    int nEvent = pDlg->FUN_1418ccb40();
                    nSalePrice = FUN_1401c0d90()->FUN_140476c70(nEvent, nPrice, nLevel);
                    nSale = FUN_1401c0d90()->FUN_140476cf0(nEvent, nLevel);
                }
            }
            else if (nShop == 2)
            {
                if (UIBeautyShopStyleDialog* pDlg = FUN_1418ce0c0(0x4f03))
                {
                    int nEvent = pDlg->FUN_140f07960();
                    nSalePrice = FUN_1401c0d90()->FUN_140476c70(nEvent, nPrice, nLevel);
                    nSale = FUN_1401c0d90()->FUN_140476cf0(nEvent, nLevel);
                }
            }
            else if (nShop == 3)
            {
                if (Unk_BSMarketDialog* pDlg = FUN_141296ab0(0x4f8d))
                {
                    nSalePrice = FUN_140fdcb30(pDlg);
                    nSale = 2;
                }
            }
            CStringW strOriginal;
            if (nSalePrice != nPrice)
                strOriginal = FUN_1409eb450(nPrice);
            int bNoSale = nSale == 0;
            CStringW strLabel;
            CStringW strSum;
            if (m_188->m_34 == 4)
            {
                FUN_140eabc00(strLabel, strSum, nSalePrice);
                CStringW strHead = FUN_14052bd00(0x998, strLabel);
                CStringW strPrice = FUN_14052bd00(0x98f, FUN_1409eb450(nSalePrice));
                CStringW strTail = FUN_140632a60(0x999, strSum, strPrice);
                strSum = strTail;
                strLabel = strHead;
            }
            else
                FUN_141349f30(strSum, m_188->m_34, m_188->m_38, nSalePrice, m_188->m_40);
            m_30->Invoke("setSumPrice", CStringW(strSum), CStringW(strLabel), CStringW(strOriginal), bNoSale);
        }
    }
}

// @0x1418ccb40
int UIBeautyShopDialog::FUN_1418ccb40()
{
    return m_1d0.m_18;
}

// @0x1418cc890
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
Unk_BSFee& Unk_BSFee::operator=(const Unk_BSFee& o)
{
    CPtred::operator=(o);
    m_18 = o.m_18;
    return *this;
}

// @@APPEND@@
