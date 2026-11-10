// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Beauty shop "my style" page (UIBeautyShopStyleDialog).
//
// The page lists the hair styles the player saved (one CItem per slot, sent by the server on 0x31/0x0e-0x0f), lets the
// player preview one on the character (Customize), apply it (bill dialog 0x4e7b, packet 0x23/0x15), save the current
// hair into a free slot (0x23/0x10), delete one (0x23/0x12) and buy more slots (0x23/0x13). The free functions at the
// start of the range are the beauty shop tooltip / colour / price helpers shared with the other beauty shop pages.
// MS2-UNIT: ?\uibeautyshopstyledialog.cpp
// MS2-RANGE: 0x140f01070-0x140f0be80 .text$mn
// MS2-RANGE: 0x1400ddde0-0x1400de020 .text$di
// MS2-RANGE: 0x142ca8dc0-0x142ca8e80 .text$yd
// MS2-PIN: ??0?$MS2Ptr@VTData@UIBillDialog@@@@QEAA@AEBV0@@Z 0x140f0af40
// MS2-PIN: ??0?$MS2Ptr@VTData@UIBillDialog@@@@QEAA@PEAVTData@UIBillDialog@@@Z 0x140f0af80
// MS2-PIN: ??0?$MS2Ptr@VCustomize@@@@QEAA@PEAVCustomize@@@Z 0x140f0b010
// MS2-PIN: ??1?$MS2Ptr@VTData@UIBillDialog@@@@QEAA@XZ 0x140f0b210
// MS2-PIN: ??1TData@UIBillDialog@@UEAA@XZ 0x140f0b270
// MS2-PIN: ??4?$MS2Ptr@VASTileCacheList@@@@QEAAAEAV0@AEBV0@@Z 0x140f0b2d0
// MS2-PIN: ?get@?$MS2Ptr@VTData@UIBillDialog@@@@QEBAPEAVTData@UIBillDialog@@XZ 0x140f0b4c0
// MS2-PIN: ?get@?$MS2Ptr@VUnk_BSCamera@@@@QEBAPEAVUnk_BSCamera@@XZ 0x140f0b4d0
// MS2-PIN: ??C?$MS2Ptr@VTData@UIBillDialog@@@@QEBAPEAVTData@UIBillDialog@@XZ 0x140f0b4e0
// MS2-PIN: ??C?$MS2Ptr@VUnk_BSCamera@@@@QEBAPEAVUnk_BSCamera@@XZ 0x140f0b4f0
// MS2-PIN: ?AddRef@?$MS2Ptr@VTData@UIBillDialog@@@@AEBAXXZ 0x140f0b730
// MS2-PIN: ?AddRef@?$MS2Ptr@VCustomize@@@@AEBAXXZ 0x140f0b760
// MS2-PIN: ?Reference@?$MS2Ptr@VTData@UIBillDialog@@@@CAXPEAVTData@UIBillDialog@@@Z 0x140f0b7c0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VTData@UIBillDialog@@@@AEBAXPEAX@Z 0x140f0b800
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCustomize@@@@AEBAXPEAX@Z 0x140f0b830
// MS2-PIN: ?Release@?$MS2Ptr@VTData@UIBillDialog@@@@AEAAXXZ 0x140f0b930
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VTData@UIBillDialog@@@@AEAAXPEAX@Z 0x140f0b9b0
// MS2-PIN: ?at@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAAAEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140f0ba50
// MS2-PIN: ??$format_arg@_WW4Unk_BSResult@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_BSResult@@@Z 0x140f0aab0
// MS2-PIN: ?reserve@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAAX_K@Z 0x140f0be30
// MS2-PIN: ?_Reallocate_exactly@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEAAX_K@Z 0x140f0b890
// MS2-PIN: ??$BlockFormat@W4Unk_BSResult@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBW4Unk_BSResult@@@Z 0x140f09f90
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140f0bc10
// MS2-PINS-BEGIN tplpin
// MS2-PIN: memmove_s 0x140f02f70 ; unique
// MS2-PIN: ??$?8PEAVUIBeautyShopStyleDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x140f09b10 ; prop
// MS2-PIN: ??$?8PEAVUIBeautyShopStyleDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140f09b80 ; prop
// MS2-PIN: ??$?8PEAVUIBeautyShopStyleDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140f09bf0 ; prop
// MS2-PIN: ??$FUN_14028dfa0@I_J@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBIAEB_J@Z 0x140f09c60 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x140f0ad60 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x140f0ae00 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCustomize@@@@QEAAAEAV1@PEAVCustomize@@@Z 0x140f0b370 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f0ba90 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f0baf0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f0bb50 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x140f0bbb0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140f0bbe0 ; unique
// MS2-PIN: ??$Call@VUIBeautyShopStyleDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x140f0bc50 ; prop
// MS2-PIN: ??$Call@VUIBeautyShopStyleDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x140f0bc90 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f0bd10 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f0bd70 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBeautyShopStyleDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f0bdd0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibeautyshopstyledialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uibeautyshopstyledialog.h"
//
//
static CString s_strItemSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // @0x1400ddde0
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
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
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/effectquery.h"   // C3: NoticeMessage (ctor 0x140a52ef0, dtor 0x1405a89e0, SetActor 0x140a53190)
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/placeholder/ascorelist.h"   // C3: ASCoreList::SetSelectedIndex
#include "ms2/client/ms2/equipitem.h"  // C3
#include "ms2/placeholder/formatstringid.h"   // C3: FormatStringId<CStringW>
#include "ms2/placeholder/packethandlermanager.h"   // C3: PacketHandlerManager::RegisterHandler
#include "ms2/client/ms2/equipment.h"   // C3: CEquipment::GetTopLayerItem
#include "ms2/commonfiles/usermail.h"   // C3: CUserMail::FUN_1408e57f0
#include "ms2/commonfiles/itemdatatable.h"   // C3: TSingleton<CItemDataTable>
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
#include "ms2/placeholder/asmultiselecttilecachelist.h"   // C3: the style list is ASTileCacheList (was Unk_140bfc2e0 / Unk_BSStyleEntity)
//
//
//
//
//
//
//
//
class Unk_ReportScript    // the m_30 root script view; GetChild<T> is defined in uitencentuserreportdialog.cpp (0x140ede0c0)
{
public:
    template<class T> MS2Ptr<T> GetChild(const CString& name);
};

class ASTooltip : public AScript
{
public:
    ASTooltip(int a1, int a2);
    virtual ~ASTooltip();
    int ApplyTextTooltip(const CStringW& strText);     // set the text (0: empty)
    void SetTooltipAlign(int nType);                  // tooltip layout
private:
    void* m_40;
    void* m_48;
    void* m_50;
    void* m_58;
};
MS2_CHECK_SIZE(ASTooltip, 0x60);

// The colour palette rows are ItemColorEx (CItemDataTable::GetPaletteColor*, 0x1405587f0 / 0x140558960 / 0x140558ad0):
// the former unit-local views Unk_BSColorRow / Unk_BSColorList / Unk_BSColorTable went to the real classes.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// The price row of a beauty shop entry.
class Unk_BSPriceRow : public CPtred
{
public:
    int m_id;                                   // +0x18 item id
    char m_pad_1c[0x24 - 0x1c];
    unsigned short m_level;                     // +0x24 required level
    unsigned m_achieve;                         // +0x28 achieve required
    int m_grade;                                // +0x2c grade of that achieve
};
MS2_CHECK_OFFSET(Unk_BSPriceRow, m_level, 0x24);
MS2_CHECK_OFFSET(Unk_BSPriceRow, m_grade, 0x2c);
typedef MS2Ptr<Unk_BSPriceRow> Unk_BSPricePtr;

class Unk_BSItemData : public CItemData
{
};
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
void WriteItemInfo(ASObj& obj, MS2Ptr<CItemData> spData, bool b);

// The achieve manager.
class CAchieve : public CPtred {};
class TShopPaymentAttr;
class CBeautyShopDataCommon { public: void Reset(); TShopPaymentAttr& GetPayment(); };   // C3: npcshopdata members (CBeautyShopDataCli base)
class CAchieveManager   // C3: member view
{
public:
    MS2Ptr<CAchieve> Find(unsigned nAchieve);
    int IsBeforeStartGrade(unsigned nAchieve, int nGrade);        // 0: not reached
};
class Unk_NametagTrophy* GetAchieveManager();   // C3: was GetAchieveManager
CStringW GetRequireAchieveText(int nAchieve, int nGrade, CStringW strDefault);

// The player and its equipment.
class Unk_BSPlayer : public PCBase
{
public:
};
class Unk_BSPlayerCap : public PCGemEquip { };
class PC   // C3: member view for the former free stand-ins
{
public:
    int GetGender();
    int FUN_141658f30();
    class Unk_MyPCEquip* GetGemEquip();
    MS2Ptr<CEquipItem> GetEquipByUid(__int64 nItemUid);
    MS2Ptr<CEquipItem> FUN_141655e10(int nSlot);
    struct Unk_PCEquipSet* GetEquipment();
};

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
    Unk_BSPlayer* GetLocalPlayer();              // the player (NULL outside the game)
};

class Unk_BSUIMgr
{
public:
    void FUN_141adc530(int nId);                // open
};

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
class IClientPlatform* GetClientPlatform();   // C3: was void* FUN_140d86260()

// Client constants (the style slot counts and the slot extend price).
class Unk_BSConstI64 { public: char m_pad[0x58]; };
class Unk_BSConstInt { public: char m_pad[0x58]; };
int FUN_140ec2b60(void* pValue);
struct Unk_BSConstUInt { char m_pad[0x58]; };
struct Unk_BSConstants
{
    char m_pad_0[0x64b8];
    Unk_BSConstI64 m_extendPrice;               // +0x64b8 merets per slot extension
    char m_pad_6510[0x6518 - 0x6510];
    Unk_BSConstInt m_extendCount;               // +0x6518 slots per extension
    Unk_BSConstInt m_baseSlots;                 // +0x6570 free slots
    Unk_BSConstUInt m_maxExtend;                // +0x65c8 extra slots that can be bought
};
MS2_CHECK_OFFSET(Unk_BSConstants, m_extendCount, 0x6518);
MS2_CHECK_OFFSET(Unk_BSConstants, m_maxExtend, 0x65c8);
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())

struct Unk_BSEffectPaths { char m_pad_0[0x2e0]; CString m_hairApply; };   // +0x2e0
class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource

// Misc singletons.
class Unk_140166410* FUN_140166410();
void* GetGameRule();
// FUN_14025e7a0 (the GFxManager singleton, 0x14025e7a0) is declared in gfxmanager.h
void* FUN_14025e7c0();
class Unk_SingletonObj* FUN_140939a10();
class Unk_140bccd50
{
public:
};
Unk_140bccd50* GetPacketHandlerManager();
class Unk_ItemEventSystem
{
public:
    void FUN_1419cae20(UIItemEventListener* pListener);
    void FUN_1419caeb0(UIItemEventListener* pListener);
};
class Unk_InventoryListener* GetItemEventDispatcher();   // C3: was GetItemEventDispatcher
class UICameraEditDialog* FindCameraEditDialog(eUIClassID nId);
class UICameraEditDialog   // C3: member view
{
public:
    void SetEnableFlagIfHidden(int n);
};
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int SetSubScene(int);
};

// Message boxes and strings.
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
MS2Ptr<CMsgBoxData> ShowMessageBoxWithCallback(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
Delegate<bool(int, const CMsgBoxData&)> FUN_140b240b0();
void FUN_14151f150(MS2Ptr<CMsgBoxData> spBox);
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW GetStringCommon(int nId);
CStringW FUN_1409404f0(__int64 n);                  // a crossed-out price
CStringW FUN_1409eb450(int n);
void ShowSystemNotice(const CStringW& strText, int nA, int nB);
void FUN_1412752d0(const CStringW& strKey, int nType);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_1412761e0(MS2Ptr<AScript> spRoot, int bEnable);   // enable the root's input
CStringW FUN_14083bab0(const CMsTime& time, CStringW strSep);
int ParseInt(const char* sz);
void SetChildVisible(const Scaleform::GFx::Value& root, CString strName, int bVisible);
void SetChildEnabled(const Scaleform::GFx::Value& root, CString strName, unsigned bEnable);
void SetValue(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void SetBoolean(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// The shop payment row (npcshopdata.h; that header's CBeautyShopDataCli clashes with this unit's view).
enum ePaymentType {};
class TShopPaymentAttr   // C3: member view
{
public:
    const CString& GetIconTag() const;
    unsigned GetItemId() const;
    __int64 GetAmount() const;
    ePaymentType GetPaymentType() const;
};

// The fee helpers (beautyshop fee rows).
CStringW GetFeePriceText(Unk_BSFee* pFee, const unsigned* pPrice);   // the price text
bool CanPayFee(Unk_BSFee* pFee, const unsigned* pPrice);       // the player can pay
void FUN_14134a2e0(Unk_BSFee* pFee);                                       // "not enough" message
void FUN_14134a120(int, int, unsigned int);   // C3: was FUN_14134a120

// The server result of a beauty shop request (formatted into string 0x272 for the unknown codes).
enum Unk_BSResult : unsigned int {};

//   (the string-key formatter is wcformat.h FUN_14028dfa0)
//
#include "ms2/placeholder/blockformat.h"   // C3: BlockFormat<...> over FUN_14028dee0 by its real name (was BlockFormat(int, const ArgList&))

int FUN_140f011f0();
UIBillDialog* FUN_140f0a350(int nId);
MS2Ptr<CMsgBoxData> FUN_140f0a930(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb, int nArg);
bool FUN_140f096f0(ASObj& obj, MS2Ptr<CItemData> spData, int nIndex, unsigned nMerat, int nGender);
bool FUN_140f09810(ASObj& obj, bool bEnabled);

// ---- the beauty shop helpers ----

// @0x140f01070
int FUN_140f01070(int nShopKind)
{
    switch (nShopKind)
    {
    case 1:
        return 1;
    case 2:
        return 3;
    case 3:
        return 2;
    }
    return 0;
}

// The name of a beauty item (0x9a1d21: the default hair).
// @0x140f010c0
CStringW GetItemName(int nItemId)
{
    if (nItemId == 0x9a1d21)
        return GetStringCommon(0x26f);
    return TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId);
}

// @0x140f01140
int GetPlayerLevel()
{
    Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return 0;
    return ((class PC*)(class PCBase*)(pPc))->FUN_141658f30();
}

// @0x140f01180
__int64 GetExtendPrice()
{
    return reinterpret_cast<Common::Constants::Value<__int64>*>(&((struct Unk_BSConstants*)GetClientConstants())->m_extendPrice)->Read();
}

// @0x140f011b0
unsigned GetMaxSlotCount()
{
    return FUN_140f011f0() + *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((struct Unk_BSConstants*)GetClientConstants())->m_maxExtend)->Get();
}

// @0x140f011f0
int FUN_140f011f0()
{
    return FUN_140ec2b60(&((struct Unk_BSConstants*)GetClientConstants())->m_baseSlots);
}

// @0x140f01220
int FUN_140f01220()
{
    return FUN_140ec2b60(&((struct Unk_BSConstants*)GetClientConstants())->m_extendCount);
}

// Save the equipped hair into a slot.
// @0x140f01250
bool SendBeautyMode16(__int64 nItemUid)
{
    if (nItemUid == 0)
        return false;
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.WriteUInt8(0x10);
    packet.WriteInt64(nItemUid);
    FUN_140710590(packet);
    return true;
}

// Save the equipped hair into a new slot (the slots are full: extends first).
// @0x140f012d0
bool SendBeautyMode17(__int64 nItemUid)
{
    if (nItemUid == 0)
        return false;
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.WriteUInt8(0x11);
    packet.WriteInt64(nItemUid);
    FUN_140710590(packet);
    return true;
}

// The hair change effect on the player.
// @0x140f01350
void PlayHairApplyEffect()
{
    Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return;
    if (pPc->GetCurStateId() != 0xe)
        pPc->vfunc_59(0xe, 0, 0, 0);
    ((class PCBase*)(class PCBase*)(pPc))->FUN_14166cc40(0x50);
    NoticeMessage request;
    request.m_strName = ((struct Unk_BSEffectPaths*)GetCommonResource())->m_hairApply;
    request.m_nObject = 1;
    request.SetActor(((class GameObject*)(class PCBase*)(pPc))->GetObjectId());
    TSingleton<CEffectService>::GetInstance()->InsertEffect(*reinterpret_cast<Unk_EffectTarget*>(&request));
}

// @0x140f01430
void FUN_140f01430()
{
    Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc)
        pPc->FUN_14166ed70(0x56057c6);
}

// @0x140f01470
bool FUN_140f01470(unsigned nSlots)
{
    unsigned nNeed = GetMaxSlotCount();
    return nSlots >= nNeed;
}

class CEquipItem;
class Unk_PCEquipSet;

// @0x140f014b0
void FUN_140f014b0(ATL::CAtlList<MS2Ptr<CEquipItem> >* pList, Unk_PCEquipSet* pSet)
{
    reinterpret_cast<CEquipment*>(pSet)->FUN_1411e3000(*pList, 4, 0, false);
}

// @0x140f014f0
void FUN_140f014f0(MS2Ptr<Customize> spCustomize)
{
    if (spCustomize.get())
        spCustomize->RestoreAll();
}

// @0x140f01540
void FUN_140f01540(ASObj& obj, bool bHair)
{
    bool bExtended = ((CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xb7);
    bool bVisible = bExtended == true;
    obj.SetBoolMember("colorScrollVisible", bVisible);
    if (bExtended)
    {
        int nRow = bHair == true ? 4 : 5;
        obj.SetIntMember("fixRow", nRow);
    }
}

// The colour palette of an item.
// @0x140f015f0
int GetItemPaletteId(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return 0;
    return static_cast<Unk_BSItemData*>(spData.operator->())->FUN_14053e260();
}

bool FUN_140f01800(ASTooltip& tip, unsigned nR, unsigned nG, unsigned nB, unsigned nPalette, int nIndex);

// The colour tooltip callback: (r, g, b, ..., {paletteID, colorSN}).
// @0x140f01670
bool FUN_140f01670(ASTooltip& tip, int, ASData* pArgs)
{
    unsigned nR = pArgs->PopUInt();
    unsigned nG = pArgs->PopUInt();
    unsigned nB = pArgs->PopUInt();
    int nType = pArgs->PopUInt();
    AScript obj(pArgs->PopValue(), 2);
    int nPalette = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(obj.GetMember("paletteID")))->GetUInt();
    int nIndex = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(obj.GetMember("colorSN")))->GetUInt();
    return FUN_140f01800(tip, nR, nG, nB, nPalette, nIndex);
}

// @0x140f01800
bool FUN_140f01800(ASTooltip& tip, unsigned nR, unsigned nG, unsigned nB, unsigned nPalette, int nIndex)
{
    CStringW strOut;
    bool bHideRgb = ((CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xb7);
    bool bShowRgb = !bHideRgb;
    if (nPalette > 0)
    {
        MS2Ptr<ItemColorEx> spRow = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColorBySN(nPalette, nIndex);
        if (spRow.get())
        {
            CStringW strRgb = FUN_14028dfa0(L"s_beauty_tooltip_color", nR, nG, nB);
            CStringW strName;
            if (static_cast<unsigned>(spRow->m_n2c) > 0)
            {
                unsigned nNameId = static_cast<unsigned>(spRow->m_n2c);
                CStringW strColor = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x48, nNameId);
                if (!strColor.IsEmpty())
                {
                    strName = FUN_14028dfa0<CStringW, CStringW>(L"s_beauty_tooltip_color_desc", strColor,
                                            TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x49, nNameId));
                    if (bShowRgb)
                    {
                        strName.Append(L"\n");
                        strName.Append(strRgb);
                    }
                }
            }
            if (strName.IsEmpty() && bShowRgb == true)
                strName = strRgb;
            CStringW strAchieve;
            if (static_cast<unsigned>(spRow->m_n24) > 0 && ((class CAchieveManager*)GetAchieveManager())->IsBeforeStartGrade(static_cast<unsigned>(spRow->m_n24), spRow->m_n28) == 0)
                strAchieve = GetRequireAchieveText(static_cast<unsigned>(spRow->m_n24), spRow->m_n28, L"");
            if (!strAchieve.IsEmpty())
                strOut = strName.IsEmpty() == true
                             ? strAchieve
                             : FUN_14028dfa0<CStringW, CStringW>(L"s_beauty_tooltip_color_with_achieve", strName, strAchieve);
            else
                strOut = strName;
        }
    }
    if (strOut.IsEmpty() && bShowRgb == true)
        strOut = FUN_14028dfa0(L"s_beauty_tooltip_color", nR, nG, nB);
    if (strOut.IsEmpty())
        return true;
    if (!tip.ApplyTextTooltip(strOut))
        return false;
    tip.SetTooltipAlign(1);
    return true;
}

bool FUN_140f02b10(Unk_BSPricePtr spPrice, short nLevel);

// The price tooltip of a beauty shop entry.
// @0x140f01eb0
bool FUN_140f01eb0(ASTooltip& tip, Unk_BSPricePtr spPrice, short nLevel, const CStringW& strPrice)
{
    CStringW strText;
    if (FUN_140f02b10(Unk_BSPricePtr(spPrice), nLevel))
    {
        if (spPrice->m_level > 0)
        {
            strText = FUN_14028dfa0(L"s_beauty_tooltip_price_with_requirelevel", GetItemName(spPrice->m_id),
                                            spPrice->m_level, strPrice);
        }
        else if (spPrice->m_achieve > 0)
        {
            strText = FUN_14028dfa0<CStringW, CStringW, CStringW>(L"s_beauty_tooltip_price_with_achieve", GetItemName(spPrice->m_id),
                                    GetRequireAchieveText(spPrice->m_achieve, spPrice->m_grade, L""), strPrice);
        }
    }
    if (strText.IsEmpty())
        strText = FormatStringId(0x274, GetItemName(spPrice->m_id), strPrice);
    if (!tip.ApplyTextTooltip(strText))
        return false;
    tip.SetTooltipAlign(5);
    return true;
}

int FUN_140f02bc0();

// The nIndex-th colour of a palette (past the palette: the extended palette, when enabled).
// @0x140f022f0
MS2Ptr<ItemColorEx> GetPaletteColor(int nPalette, unsigned nIndex)
{
    Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> spList = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColors(nPalette);
    if (spList == 0)
        return MS2Ptr<ItemColorEx>(0);
    MS2Ptr<ItemColorEx> spRow(0);
    unsigned nCount = static_cast<unsigned>(spList->GetCount());
    if (nCount <= nIndex)
    {
        if (!((CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xb7))
            return MS2Ptr<ItemColorEx>(0);
        int nOffset = nIndex - nCount;
        int nExtraPalette = FUN_140f02bc0();
        spRow = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColor(nExtraPalette, nOffset);
    }
    else
        spRow = spList->GetAt(nIndex);
    return spRow;
}

// The colour tooltip of the "my colour" slots.
// @0x140f024e0
void FUN_140f024e0(ASData* pArgs, int* pnPalette, int* pnType)
{
    *pnPalette = pArgs->PopUInt();
    *pnType = pArgs->PopUInt() == 0 ? 0 : 2;
    unsigned nR = pArgs->PopUInt();
    unsigned nG = pArgs->PopUInt();
    unsigned nB = pArgs->PopUInt();
    const Scaleform::GFx::Value value = pArgs->PopValue();
    AScript obj(value, 2);
    static_cast<ASObj&>(obj).SetWStringMember("colorTooltip", FUN_14028dfa0(L"s_beauty_tooltip_color", nR, nG, nB));
}

bool FUN_140f026f0(MS2Ptr<ItemColorEx> spRow, bool* pbLocked);
bool FUN_140f02790(unsigned nAchieve, int nGrade, bool* pbLocked);

// @0x140f02650
bool FUN_140f02650(int nItemId, unsigned nIndex, bool* pbLocked)
{
    if (!nItemId)
        return false;
    unsigned nPalette = GetItemPaletteId(nItemId);
    if (nPalette > 0)
    {
        MS2Ptr<ItemColorEx> spRow = GetPaletteColor(nPalette, nIndex);
        return FUN_140f026f0(spRow, pbLocked);
    }
    return true;
}

// @0x140f026f0
bool FUN_140f026f0(MS2Ptr<ItemColorEx> spRow, bool* pbLocked)
{
    *pbLocked = false;
    if (spRow == 0)
        return false;
    return FUN_140f02790(static_cast<unsigned>(spRow->m_n24), spRow->m_n28, pbLocked);
}

// @0x140f02790
bool FUN_140f02790(unsigned nAchieve, int nGrade, bool* pbLocked)
{
    *pbLocked = false;
    if (nAchieve > 0)
    {
        MS2Ptr<CAchieve> spAchieve = ((class CAchieveManager*)GetAchieveManager())->Find(nAchieve);
        if (spAchieve == 0)
            return false;
        *pbLocked = ((class CAchieveManager*)GetAchieveManager())->IsBeforeStartGrade(nAchieve, nGrade) == 0;
        return true;
    }
    return true;
}

// @0x140f02860
bool FUN_140f02860(Unk_BSPricePtr spPrice, unsigned short nLevel, bool* pbLocked)
{
    *pbLocked = false;
    if (spPrice == 0)
        return false;
    bool bLowLevel = false;
    if (spPrice->m_level > 0)
        bLowLevel = spPrice->m_level > nLevel;
    bool bAchieve = false;
    if (spPrice->m_achieve > 0)
    {
        if (!FUN_140f02790(spPrice->m_achieve, spPrice->m_grade, &bAchieve))
            return false;
    }
    *pbLocked = bLowLevel || bAchieve;
    return true;
}

// @0x140f029b0
bool IsItemColorLocked(int nItemId, unsigned nIndex)
{
    if (!nItemId)
        return false;
    bool bLocked = false;
    FUN_140f02650(nItemId, nIndex, &bLocked);
    return bLocked;
}

// @0x140f029f0
bool IsColorRowLocked(MS2Ptr<ItemColorEx> spRow)
{
    if (spRow == 0)
        return false;
    bool bLocked = false;
    FUN_140f026f0(MS2Ptr<ItemColorEx>(spRow), &bLocked);
    return bLocked;
}

// @0x140f02a80
bool IsPaletteColorLocked(int nPalette, int nIndex)
{
    if (!nPalette)
        return false;
    MS2Ptr<ItemColorEx> spRow = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColorBySN(nPalette, nIndex);
    return IsColorRowLocked(spRow);
}

// @0x140f02b10
bool FUN_140f02b10(Unk_BSPricePtr spPrice, short nLevel)
{
    if (spPrice == 0)
        return false;
    bool bLocked = false;
    FUN_140f02860(Unk_BSPricePtr(spPrice), nLevel, &bLocked);
    return bLocked;
}

// The extended colour palette id.
// @0x140f02bc0
int FUN_140f02bc0()
{
    return 100000000;
}

// ---- IItemCustomizeEventListener / UIBillDialog::TData are inline in the header ----

// ---- UIBeautyShopStyleDialog ----

// @0x140f03090
UIBeautyShopStyleDialog::UIBeautyShopStyleDialog()
    : m_198(0), m_1a8(0), m_260(0), m_264(0), m_268(0), m_26c(0), m_270(0), m_items(0), m_290(FUN_140f011f0()),
      m_294(0), m_2b0(0)
{
    m_2c = 0xc;
    m_80 = 0;
    m_88 = 1;
    m_58 = 0;
    SetFlag(0, 1);
    ((PacketHandlerManager*)GetPacketHandlerManager())->RegisterHandler(0x31, Delegate<void(CInPacket&)>(this, &UIBeautyShopStyleDialog::FUN_140f05a80));
}

// @0x140f03330
UIBeautyShopStyleDialog::~UIBeautyShopStyleDialog()
{
    ((PacketHandlerManager*)GetPacketHandlerManager())->UnregisterHandler(0x31, Delegate<void(CInPacket&)>(this, &UIBeautyShopStyleDialog::FUN_140f05a80));
}

// @0x140f034d0
CString UIBeautyShopStyleDialog::GetTypeName()
{
    return "BeautyShopStyleDialog";
}

// @0x140f03520
int UIBeautyShopStyleDialog::vfunc_84()
{
    if (vfunc_55())
        return 0;
    return 1;
}

// @0x140f03560
void UIBeautyShopStyleDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_1a8.AssignRaw((Unk_BSCamera*)FindCameraEditDialog((eUIClassID)0x4ef2));
    ((NotifySystem*)FUN_140939a10())->RegisterNotify(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopStyleDialog::OnNotifyGameEventChanged));
    InitData();
    ((class Unk_BSPlatform*)((void*)GetClientPlatform()))->vfunc_43(0xe, 0, 1000);
}

// @0x140f036a0
void UIBeautyShopStyleDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140f07a00();
    m_26c = 0;
    m_290 = FUN_140f011f0();
    m_294 = 0;
    m_260 = 0;
    m_270 = 0;
    m_items = 0;
    m_264 = 0;
    m_268 = 0;
    m_198 = 0;
    m_1a8 = 0;
    reinterpret_cast<CBeautyShopDataCommon*>(&m_1b8)->Reset();
    m_298.clear();
    m_2b0 = 0;
    FUN_140f01430();
    ((class Unk_ItemEventSystem*)GetItemEventDispatcher())->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    ((NotifySystem*)FUN_140939a10())->UnregisterNotify(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopStyleDialog::OnNotifyGameEventChanged));
    ((NotifySystem*)FUN_140939a10())->UnregisterNotify(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopStyleDialog::FUN_140f09380));
}

// @0x140f039c0
int UIBeautyShopStyleDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (((CInputKeyHandler*)FUN_14025e7c0())->IsEscapePressed())
    {
        FUN_140f082d0();
        return 1;
    }
    return 0;
}

// @0x140f03a10
void UIBeautyShopStyleDialog::vfunc_15()
{
    if (m_198 == 0)
        return;
    if (vfunc_55() != 0)
        return;
    if (m_1a8.get())
        reinterpret_cast<UICameraEditDialog*>(m_1a8.operator->())->SetEnableFlagIfHidden(1);
}

// The AS calls of the page.
// @0x140f03aa0
int UIBeautyShopStyleDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnChangeItem", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            FUN_140f08950(0);
            int nItemId = ParseInt(data.FUN_1422b8d30());
            int nArg1 = data.PopInt();
            int nArg2 = data.PopInt();
            Scaleform::GFx::Value value = data.PopValue();
            AScript obj(value, 2);
            if (!obj.IsUndefinedOrNull())
            {
                int nIndex = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(obj.GetMember("index")))->GetInt();
                FUN_140f08ae0(nItemId, nIndex);
            }
            FUN_140f07cc0();
        }
        return 1;
    }
    else if (_stricmp("OnClickClose", szMethod) == 0)
    {
        FUN_140f082d0();
        return 1;
    }
    else if (_stricmp("OnClickReset", szMethod) == 0)
    {
        OnClickReset();
        return 1;
    }
    else if (_stricmp("OnClickSave", szMethod) == 0)
    {
        int nIndex = -1;
        if (m_items.get())
        {
            nIndex = reinterpret_cast<ASCoreList*>(m_items.operator->())->GetSelectedIndex();
            if (nIndex == -1)
            {
                ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_error_invalid_selected_style"), 0, FUN_140b240b0());
                return 1;
            }
            else
            {
                MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
                if (spItem == 0 || spItem->GetData() == 0)
                    return 1;
                Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
                if (pPc == 0)
                    return 1;
                if (reinterpret_cast<Unk_BSItemData*>(spItem->GetData())->IsGenderAllowed(((class PC*)(class PCBase*)(pPc))->GetGender()) == 0)
                {
                    ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_error_style_disable_gender"), 0, FUN_140b240b0());
                    return 1;
                }
            }
        }
        if (UIBillDialog* pBill = FUN_140f0a350(0x4e7b))
        {
            MS2Ptr<AScript> spRows(new AScript(2));
            if (spRows.get())
            {
                unsigned nPrice = 0;
                if (BuildBillRows(*spRows, &nPrice))
                {
                    unsigned nFee = 0;
                    Unk_BSFee* pFee = GetFee(&nFee);
                    MS2Ptr<UIBillDialog::TData> spData(new UIBillDialog::TData);
                    if (spData.get())
                    {
                        spData->m_18 = static_cast<IMessageListener*>(this);
                        spData->m_30 = 2;
                        spData->m_20 = spRows;
                        spData->m_34 = reinterpret_cast<TShopPaymentAttr*>(pFee)->GetPaymentType();
                        spData->m_38 = reinterpret_cast<TShopPaymentAttr*>(pFee)->GetItemId();
                        spData->m_40 = reinterpret_cast<TShopPaymentAttr*>(pFee)->GetIconTag();
                        spData->m_48 = nPrice;
                        pBill->SetData(MS2Ptr<UIBillDialog::TData>(spData));
                        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4e7b)));
                    }
                }
            }
        }
        return 1;
    }
    else if (_stricmp("OnCheckPreviewWithCap", szMethod) == 0)
    {
        if (GetShopKind() != 1)
            return 1;
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            int bPreview = data.PopBool() != 0;
            SetPreview(bPreview);
            if (bPreview && m_268)
                FUN_141275260(0x270, 1, 0);
        }
        return 1;
    }
    else if (_stricmp("onClickSaveCurStyle", szMethod) == 0)
    {
        FUN_140f08950(0);
        FUN_140f08f70();
        if (GetRemainSlotCount() <= 0)
        {
            if (FUN_140f09230())
            {
                ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_error_style_slot_max_in_style_npc"), 0, FUN_140b240b0());
                return 1;
            }
            unsigned nCount = FUN_140f01220();
            __int64 nPrice = GetExtendPrice();
            CStringW strText = FUN_14028dfa0(L"s_beauty_msg_ask_save_style_extend_in_style_npc", nPrice, nCount);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(CStringW(strText), 1);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f05880));
            spBox->FUN_141a024a0(0);
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
            return 1;
        }
        FUN_140f07310();
        return 1;
    }
    else if (_stricmp("onClickExtendSlot", szMethod) == 0)
    {
        if (FUN_140f09230())
        {
            ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_error_style_slot_extend_max"), 0, FUN_140b240b0());
            return 1;
        }
        __int64 nPrice = GetExtendPrice();
        unsigned nCount = FUN_140f01220();
        CStringW strText = FUN_14028dfa0(L"s_beauty_msg_ask_save_style_extend", nCount, nPrice);
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(CStringW(strText), 1);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::SendBeautyMode19));
        spBox->FUN_141a024a0(0);
        FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
        return 1;
    }
    else if (_stricmp("onClickDeleteCharacterCreateItem", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            Scaleform::GFx::Value value = data.PopValue();
            AScript obj(value, 2);
            int nIndex = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(obj.GetMember("index")))->GetInt();
            MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
            if (spItem == 0)
            {
                ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_error_already_empty_slot"), 0, FUN_140b240b0());
                return 1;
            }
            CStringW strText = FUN_14028dfa0<CStringW>(CStringW(L"s_beauty_msg_ask_delete_style"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spItem->GetItemId()));
            FUN_140f0a930(CStringW(strText), 1,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::SendBeautyMode18), nIndex);
            return 1;
        }
        return 1;
    }
    return 0;
}

// The answers of the scene (OnExit) and of the bill dialog (OK: apply).
// @0x140f04e50
int UIBeautyShopStyleDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() == 0)
    {
        if (dynamic_cast<UISceneGameBeautyShop*>(pSender))
        {
            CString strMethod = pMsg->FUN_1422b8d30();
            if ((strMethod == "OnExit"))
                FUN_140f082d0();
            return 1;
        }
        else if (dynamic_cast<UIBillDialog*>(pSender))
        {
            int nResult = pMsg->PopInt();
            if (nResult == 0)
                FUN_140f08be0();
            return 1;
        }
    }
    return 0;
}

// @0x140f04f80
void UIBeautyShopStyleDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (_stricmp("getTooltipFee", strMethod) == 0)
    {
        AScript obj(2);
        unsigned nPrice = 0;
        BuildBillRows(obj, &nPrice);
        *pRetVal = obj.GetValue();
    }
    else if (_stricmp("getTooltip", strMethod) == 0)
    {
        int nArgs = pArgs->PopInt();
        Scaleform::GFx::Value value = pArgs->PopValue();
        if (((Scaleform::GFx::Value*)(void*)(&value))->IsUndefined())
        {
            AScript empty(2);
            *pRetVal = empty.GetValue();
            return;
        }
        AScript obj(value, 2);
        int nIndex = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(obj.GetMember("index")))->GetInt();
        CStringW strText;
        MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
        if (spItem == 0)
            strText = GetStringCommonByKey(L"s_beauty_tooltip_recommand_save_style");
        else
        {
            unsigned nFee = 0;
            Unk_BSFee* pFee = GetFee(&nFee);
            unsigned __int64 nBase = (unsigned)GetFeeAmount();
            CStringW strPrice = GetFeePriceText(pFee, (const unsigned*)&nBase);
            CMsTime tDate(spItem->GetCreationTime());
            CStringW strDate = FormatStringId(0x276, FUN_14083bab0(tDate, L"/"));
            strText = BlockFormat(0x275, GetItemName(spItem->GetItemId()), strDate, strPrice);
        }
        ASTooltip tip(1, 2);
        if (tip.ApplyTextTooltip(strText))
        {
            tip.SetTooltipAlign(5);
            *pRetVal = tip.GetValue();
        }
    }
}

// A game event changed: refresh the sale price.
// @0x140f05460
void UIBeautyShopStyleDialog::OnNotifyGameEventChanged(NotifyObject* pNotify)
{
    NotifyGameEventChanged* pEvent = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pEvent && pEvent->m_eventName == "SaleBeautyShop")
    {
        unsigned nFee = 0;
        Unk_BSFee* pFee = GetFee(&nFee);
        FUN_140f07520(pFee, &nFee);
        if (MS2Ptr<ASMovieClip> spPcBang = GetChild<ASMovieClip>("m_pcBang"))
        {
            int nRet = ((CGameRule*)GetGameRule())->GetSaleIndex(FUN_140f07960(), GetPlayerLevel());
            spPcBang->vfunc_4(nRet == 0);
        }
        UIBillDialog* pBill;
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->IsDialogOpen((eUIClassID)(0x4e7b))) && (pBill = FUN_140f0a350(0x4e7b)) != 0)
            pBill->FUN_1418cda70(nFee);
    }
}

// Extend the slots (answer of "s_beauty_msg_ask_save_style_extend").
// @0x140f05640
bool UIBeautyShopStyleDialog::SendBeautyMode19(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
        packet.WriteUInt8(0x13);
        FUN_140710590(packet);
        FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    }
    return true;
}

// Delete a saved style (answer of "s_beauty_msg_ask_delete_style"; argument 0: the slot).
// @0x140f056e0
bool UIBeautyShopStyleDialog::SendBeautyMode18(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        int nIndex = data.FUN_141a02e50(0, 0);
        MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
        if (spItem == 0)
            return true;
        COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
        packet.WriteUInt8(0x12);
        packet.WriteInt64(spItem->GetItemUid());
        packet.WriteUInt8((unsigned char)nIndex);
        FUN_140710590(packet);
        FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    }
    return true;
}

// @0x140f05820
bool UIBeautyShopStyleDialog::FUN_140f05820(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
        FUN_140f07310();
    return true;
}

// @0x140f05850
bool UIBeautyShopStyleDialog::FUN_140f05850(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
        FUN_140f08220();
    return true;
}

// Save the equipped hair into a new slot (answer of "s_beauty_msg_ask_save_style_extend_in_style_npc").
// @0x140f05880
bool UIBeautyShopStyleDialog::FUN_140f05880(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
    {
        Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
        if (pPc != 0)
        {
            int nSlot = FUN_140f01070(GetShopKind());
            MS2Ptr<CEquipItem> spEquip = ((class PC*)(class PCBase*)(pPc))->FUN_141655e10(nSlot);
            if (spEquip == 0 || spEquip->GetItem() == 0)
                return true;
            MS2Ptr<CItem> spItem = spEquip->GetItem();
            if (spItem == 0)
                return true;
            if (SendBeautyMode17(spItem->GetItemUid()))
                FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
        }
    }
    return true;
}

// The beauty shop packets (0x31).
// @0x140f05a80
void UIBeautyShopStyleDialog::FUN_140f05a80(CInPacket& packet)
{
    int nOp = packet.ReadUInt8();
    if (nOp == 2)
    {
        m_26c = packet.ReadUInt8();
        m_1b8.Read(packet);
    }
    else if (nOp == 0xd)
        m_298.clear();
    else if (nOp == 0xe)
    {
        m_294 = (unsigned short)packet.ReadInt16();
        m_298.reserve(GetMaxSlotCount());
        m_260 = 1;
        if (FUN_1422dc430())
            static_cast<UIDialog*>(this)->vfunc_8(1);
    }
    if (nOp == 0x14)
    {
        int nType = packet.ReadUInt8();
        int nExtended = (unsigned short)packet.ReadInt16();
        int nOld = m_290;
        FUN_140f08f20(nExtended + FUN_140f011f0());
        if ((m_30.get() ? true : false) && m_260)
        {
            int nNew = m_290;
            int nAdded = (std::max)(0, nNew - nOld);
            if (nAdded > 0)
            {
                CStringW strMsg = FUN_14028dfa0(L"s_beauty_msg_complete_extend_style_slot", nAdded);
                ShowSystemNotice(strMsg, 3, 1);
                ASArray arr(2);
                for (int i = nOld; i < nNew; i++)
                {
                    ASObj obj(2);
                    FUN_140f09810(obj, true);
                    arr.PushValue(Scaleform::GFx::Value(obj.GetValue()));
                }
                m_30->Invoke("updateItems", nOld, Scaleform::GFx::Value(arr.GetValue()));
            }
        }
    }
    else if (nOp == 0xf)
    {
        unsigned nCount = (unsigned short)packet.ReadInt16();
        for (unsigned i = 0; i < nCount; i++)
        {
            MS2Ptr<CItem> spItem(new CItem);
            if (spItem == 0)
                continue;
            int nItemId = packet.ReadInt32();
            __int64 nUid = packet.ReadInt64();
            int nSlot = packet.ReadInt32();
            __int64 nTime = packet.ReadInt64();
            spItem->FUN_140523c40(nItemId, 1, 0);
            spItem->SetSlot(nSlot);
            spItem->SetItemUid(nUid);
            spItem->SetCreationTime(nTime);
            spItem->ReadProxyFromPacket(packet);
            m_298.push_back(spItem);
        }
        if (m_298.size() == m_294)
            InitData();
    }
    if (vfunc_55() || m_30 == 0)
        return;
    FUN_1412761e0(MS2Ptr<AScript>(m_30), 1);
    m_2b0 = 0;
    if (nOp == 0x10 || nOp == 0x11)
    {
        __int64 nUid = packet.ReadInt64();
        __int64 nNewUid = packet.ReadInt64();
        int nSlot = packet.ReadUInt8();
        __int64 nTime = packet.ReadInt64();
        Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
        if (pPc)
        {
            MS2Ptr<CEquipItem> spEquip = ((class PC*)(class PCBase*)(pPc))->GetEquipByUid(nUid);
            if (spEquip == 0)
                return;
            MS2Ptr<CItem> spCopy = spEquip->GetItem()->Clone();
            if (spCopy == 0)
                return;
            spCopy->SetItemUid(nNewUid);
            spCopy->SetSlot(nSlot);
            spCopy->SetCreationTime(nTime);
            int nIndex = (int)m_298.size();
            m_298.push_back(spCopy);
            ASObj obj(2);
            FUN_140f096f0(obj, MS2Ptr<CItemData>(reinterpret_cast<CItemData*>(spCopy->GetData())), nSlot,
                          GetFeeAmount(), ((class PC*)(class PCBase*)(pPc))->GetGender());
            m_30->Invoke("updateItem", nIndex, Scaleform::GFx::Value(obj.GetValue()));
            FUN_1412752d0(L"s_beauty_msg_complete_save_hair_style", 1);
        }
    }
    else if (nOp == 0x12)
    {
        __int64 nUid = packet.ReadInt64();
        int nIndex = 0;
        for (std::vector<MS2Ptr<CItem> >::iterator it = m_298.begin(); it != m_298.end(); ++it)
        {
            MS2Ptr<CItem> spItem(*it);
            if ((spItem.get() ? true : false) && spItem->GetItemUid() == nUid)
            {
                m_298.erase(it);
                break;
            }
            nIndex++;
        }
        if (nIndex >= 0)
        {
            int nSize = (int)m_298.size();
            ASObj obj(2);
            FUN_140f09810(obj, true);
            m_30->Invoke("removeItemAndAdd", nIndex, nSize, Scaleform::GFx::Value(obj.GetValue()));
        }
        FUN_1412752d0(L"s_beauty_msg_complete_remove_saved_hair_style", 1);
        FUN_140f08f70();
    }
    else if (nOp == 0x15)
    {
        FUN_1412752d0(L"s_beauty_msg_complete_apply_saved_style", 3);
        PlayHairApplyEffect();
        FUN_140f092b0();
    }
    else if (nOp == 8)
    {
        Unk_BSResult nCode = (Unk_BSResult)packet.ReadInt32();
        unsigned nFee = 0;
        Unk_BSFee* pFee = GetFee(&nFee);
        switch ((int)nCode)
        {
        case 2:
            FUN_14134a2e0(pFee);
            break;
        case 0x14:
            FUN_14134a120(4, 0, 0);
            break;
        case 0x18:
            FUN_1412752d0(L"s_beauty_msg_error_style_apply_already", 1);
            break;
        case 0x19:
            FUN_1412752d0(L"s_beauty_msg_error_style_save_cant_not_beauty_day", 1);
            break;
        case 0x13:
            ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_error_style_slot_extend_max"), 0, FUN_140b240b0());
            break;
        case 0x17:
            ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_error_style_disable_gender"), 0, FUN_140b240b0());
            break;
        case 7:
            ShowMessageBoxWithCallback(GetStringCommon(0x273), 0,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f05850));
            break;
        default:
            ShowMessageBoxWithCallback(BlockFormat(0x272, nCode), 0,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f05850));
            break;
        }
    }
}

// All saved styles arrived: fill the page.
// @0x140f06e10
bool UIBeautyShopStyleDialog::InitData()
{
    if (m_30 == 0)
        return false;
    IItemCustomizeEventListener::FUN_140f0b710(0);
    Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (!pPc)
        return false;
    bool bCap = FUN_140f09630();
    int nKind = GetShopKind();
    bool bSale = false;
    if (FUN_140f07960() > 0)
    {
        int nRet = ((CGameRule*)GetGameRule())->GetSaleIndex(FUN_140f07960(), GetPlayerLevel());
        bSale = nRet == 0;
    }
    m_30->Invoke("initData", L"$s_beauty_title_my_style_hair", bCap, bSale);
    m_270 = reinterpret_cast<Unk_ReportScript*>(m_30.operator->())->GetChild<ASGameEntity>("m_customStyle");
    if (m_270.get())
        m_items = m_270.operator->()->FUN_140bfa6a0<ASTileCacheList>("m_items");   // C3: AScript::FUN_140bfa6a0<ASTileCacheList>
    m_198.AssignRaw(new Customize(((class GameObject*)(class PCBase*)(pPc))->GetObjectId(), static_cast<IItemCustomizeEventListener*>(this), 0));
    int nSlot = FUN_140f01070(nKind);
    if (nKind == 1)
        FUN_140f079a0();
    m_198->SelectSlot(nSlot);
    FUN_140f07cc0();
    FUN_140f07e20();
    ((class Unk_ItemEventSystem*)GetItemEventDispatcher())->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    ((NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyChangeActiveMyCodiTab",
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopStyleDialog::FUN_140f09380));
    if (m_260)
        static_cast<UIDialog*>(this)->vfunc_8(1);
    return true;
}

// Save the equipped hair into a free slot.
// @0x140f07310
bool UIBeautyShopStyleDialog::FUN_140f07310()
{
    Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc != 0)
    {
        int nSlot = FUN_140f01070(GetShopKind());
        MS2Ptr<CEquipItem> spEquip = ((class PC*)(class PCBase*)(pPc))->FUN_141655e10(nSlot);
        if (spEquip == 0 || spEquip->GetItem() == 0)
            return false;
        MS2Ptr<CItem> spItem = spEquip->GetItem();
        if (spItem == 0)
            return false;
        if (SendBeautyMode16(spItem->GetItemUid()))
        {
            FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
            return true;
        }
    }
    return false;
}

// The fee line ("setFee": price, sale price, sale, discounted).
// @0x140f07520
void UIBeautyShopStyleDialog::FUN_140f07520(Unk_BSFee* pFee, unsigned* pPrice)
{
    if (m_30 == 0)
        return;
    int nLevel = GetPlayerLevel();
    int nEvent = FUN_140f07960();
    int nRet = ((CGameRule*)GetGameRule())->GetSaleIndex(nEvent, nLevel);
    bool bSale = nRet == 0;
    if (!pFee)
    {
        CStringW strDefault = GetStringCommonByKey(L"s_beauty_fee_default");
        m_30->Invoke("setFee", CStringW(strDefault), CStringW(strDefault), bSale, false);
        return;
    }
    unsigned __int64 nPrice = *pPrice;
    unsigned nSale = ((CGameRule*)GetGameRule())->GetDiscountedPrice(nEvent, (unsigned)nPrice, nLevel);
    bool bDiscount = nPrice != nSale;
    if (bDiscount)
    {
        unsigned __int64 nSale64 = nSale;
        CStringW strSale = GetFeePriceText(pFee, (const unsigned*)&nSale64);
        m_30->Invoke("setFee", FUN_1409404f0(nPrice), CStringW(strSale), bSale, bDiscount);
    }
    else
    {
        CStringW strPrice = GetFeePriceText(pFee, (const unsigned*)&nPrice);
        m_30->Invoke("setFee", CStringW(strPrice), FUN_1409eb450(nSale), bSale, bDiscount);
    }
}

// @0x140f07960
unsigned UIBeautyShopStyleDialog::FUN_140f07960()
{
    return m_1b8.m_18;
}

// @0x140f07980
int UIBeautyShopStyleDialog::GetShopKind()
{
    return m_1b8.m_1c;
}

// @0x140f079a0
void UIBeautyShopStyleDialog::FUN_140f079a0()
{
    if (m_198 == 0)
        return;
    m_198->HideSlot(6);
}

// @0x140f07a00
void UIBeautyShopStyleDialog::FUN_140f07a00()
{
    if (m_198 == 0)
        return;
    m_198->ShowSlot(6);
}

// Preview a saved style on the character.
// @0x140f07a60
int UIBeautyShopStyleDialog::FUN_140f07a60(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || spItem->GetData() == 0)
        return 0;
    Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return 0;
    spItem->SetObjectId(((class GameObject*)(class PCBase*)(((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer())))->GetObjectId());
    if (!m_198->EquipItem(spItem.get()))
    {
        if (reinterpret_cast<Unk_BSItemData*>(spItem->GetData())->IsGenderAllowed(((class PC*)(class PCBase*)(pPc))->GetGender()) == 0)
            ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_error_save_style_disable_gender"), 0, FUN_140b240b0());
        return 0;
    }
    m_198->SelectId(spItem->GetItemId());
    return 1;
}

// @0x140f07cc0
void UIBeautyShopStyleDialog::FUN_140f07cc0()
{
    if (m_30 == 0 || m_items == 0)
        return;
    Scaleform::GFx::Value& root = m_30->GetValue();
    int bChanged = m_198->FUN_140cd2c20();
    SetChildEnabled(root, CString("m_save"), bChanged);
    SetChildEnabled(root, CString("m_reset"), bChanged);
    unsigned nFee = 0;
    Unk_BSFee* pFee = GetFee(&nFee);
    if (bChanged)
        FUN_140f07520(pFee, &nFee);
    else
    {
        unsigned nZero = 0;
        FUN_140f07520(0, &nZero);
    }
}

// Fill the slot list ("buildItems").
// @0x140f07e20
void UIBeautyShopStyleDialog::FUN_140f07e20()
{
    Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return;
    ASDataProvider arr(2);
    unsigned nFee = GetFeeAmount();
    unsigned nCount = (unsigned)m_298.size();
    unsigned nMax = GetMaxSlotCount();
    for (unsigned i = 0; i < nMax; i++)
    {
        ASObj obj(2);
        if (i < m_290)
        {
            if (i < nCount)
            {
                MS2Ptr<CItem> spItem(m_298.at(i));
                if (spItem.get())
                {
                    MS2Ptr<CItemData> spData = FUN_14053f870(spItem->GetItemId());
                    if (spData.get())
                        FUN_140f096f0(obj, MS2Ptr<CItemData>(spData), spItem->GetSlot(), nFee, ((class PC*)(class PCBase*)(pPc))->GetGender());
                }
            }
            else
                FUN_140f09810(obj, true);
        }
        else
            FUN_140f09810(obj, false);
        arr.PushValue(Scaleform::GFx::Value(obj.GetValue()));
    }
    long nIndex = -1;
    m_30->Invoke("buildItems", arr.GetValue(), nIndex);
    int bMore = m_290 < nMax;
    SetExtendSlotVisible(bMore);
}

// @0x140f08160
int UIBeautyShopStyleDialog::GetFeeAmount()
{
    return reinterpret_cast<CBeautyShopDataCommon*>(&m_1b8)->GetPayment().GetAmount();   // C3: CBeautyShopDataCommon::GetPayment (npcshopdata.cpp)
}

// The fee row; *pPrice: the fee when a change is billable.
// @0x140f08190
Unk_BSFee* UIBeautyShopStyleDialog::GetFee(unsigned* pPrice)
{
    Unk_BSFee* pFee = (Unk_BSFee*)&reinterpret_cast<CBeautyShopDataCommon*>(&m_1b8)->GetPayment();   // C3: as uibeautyshopdialog
    *pPrice = 0;
    if (m_198 == 0)
        return pFee;
    if (m_26c == 4)
    {
        *pPrice = reinterpret_cast<TShopPaymentAttr*>(pFee)->GetAmount();
        return pFee;
    }
    return pFee;
}

// Close: restore the hair and the camera.
// @0x140f08220
int UIBeautyShopStyleDialog::FUN_140f08220()
{
    if (m_198 == 0)
        return 0;
    int nSlot = FUN_140f01070(GetShopKind());
    m_198->RestoreSlot(nSlot);
    if (Unk_BSField* pField = (Unk_BSField*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd3620())
        pField->vfunc_149();
    ((class GFxSceneService*)(CUserMail::GetGFxSceneService()))->SetSubScene(0x620001d);
    return 1;
}

// "OnClickClose": ask when the preview changed.
// @0x140f082d0
void UIBeautyShopStyleDialog::FUN_140f082d0()
{
    if (m_198 == 0)
        return;
    if (m_26c == 2 || m_198->FUN_140cd2c20() == 0)
    {
        FUN_140f08220();
        return;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommon(0x271), 1);
    spBox->SetButtonPreset(2);
    spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f05850));
    FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
}

// "OnClickReset".
// @0x140f08470
void UIBeautyShopStyleDialog::OnClickReset()
{
    if (m_30 == 0 || m_items == 0)
        return;
    FUN_140f08950(0);
    FUN_140f08f70();
}

// The bill rows ("category", "list" of {detail, strPrice}); *pPrice: the fee.
// @0x140f084e0
int UIBeautyShopStyleDialog::BuildBillRows(AScript& out, unsigned* pPrice)
{
    if (m_198 == 0)
        return 0;
    if (m_26c == 0 || m_26c != 4)
        return 0;
    *pPrice = 0;
    Unk_BSFee* pFee = GetFee(pPrice);
    int bChanged = m_198->FUN_140cd2a00();
    if (!bChanged)
        *pPrice = 0;
    ASArray arr(2);
    {
        CStringW strRow = GetStringCommonByKey(L"s_bill_list_row");
        static_cast<ASObj&>(out).FUN_1409c0dc0("category", "$s_beauty_saved_hair_style");
        ASObj row(2);
        CString strKey(bChanged ? "$s_beauty_change_style" : "$s_beauty_none");
        CStringW strName = GetGFxManager()->Localize(strKey);
        row.SetWStringMember("detail", StringFormat<CStringW>(strRow, strName));
        CStringW strPrice = bChanged ? GetFeePriceText(pFee, (const unsigned*)&static_cast<const unsigned __int64&>(*pPrice))
                                     : GetStringCommonByKey(L"s_beauty_fee_default");
        row.SetWStringMember("strPrice", strPrice);
        arr.PushValue(Scaleform::GFx::Value(row.GetValue()));
    }
    static_cast<ASObj&>(out).FUN_1409adbe0("list", Scaleform::GFx::Value(arr.GetValue()));
    return 1;
}

// @0x140f08950
void UIBeautyShopStyleDialog::FUN_140f08950(int bPreview)
{
    if (m_30 == 0)
        return;
    if (m_264 != bPreview)
    {
        FUN_140f08aa0(bPreview);
        bool bChecked = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(m_30->Invoke("forceChangeCheckPreviewWithCap", bPreview)))->GetBool();
        m_264 = bChecked != 0;
    }
}

// @0x140f08a30
void UIBeautyShopStyleDialog::SetPreview(int bPreview)
{
    if (m_30 == 0)
        return;
    if (m_264 != bPreview)
        FUN_140f08aa0(bPreview);
    m_264 = bPreview;
}

// @0x140f08aa0
void UIBeautyShopStyleDialog::FUN_140f08aa0(int bPreview)
{
    if (bPreview != 0)
        FUN_140f07a00();
    else
        FUN_140f079a0();
}

// @0x140f08ae0
void UIBeautyShopStyleDialog::FUN_140f08ae0(int, int nIndex)
{
    if (m_198 == 0)
        return;
    MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
    if (spItem == 0)
        return;
    FUN_140f07a60(MS2Ptr<CItem>(spItem));
}

// @0x140f08ba0
void UIBeautyShopStyleDialog::FUN_140f08ba0()
{
    if (vfunc_55() != 0)
        return;
    FUN_140f07cc0();
}

// Apply the selected style (bill dialog OK).
// @0x140f08be0
int UIBeautyShopStyleDialog::FUN_140f08be0()
{
    if (m_198 == 0)
        return 0;
    MS2Ptr<ASTileCacheList> spList(m_items);
    if (spList == 0)
        return 0;
    if (reinterpret_cast<ASCoreList*>(m_items.operator->())->GetSelectedIndex() == -1)
        return 0;
    int nIndex = reinterpret_cast<ASCoreList*>(spList.operator->())->GetSelectedIndex();
    MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
    if (spItem == 0)
        return 0;
    FUN_140f08950(0);
    int nEvent = FUN_140f07960();
    unsigned nFee = 0;
    Unk_BSFee* pFee = GetFee(&nFee);
    unsigned nSale = ((CGameRule*)GetGameRule())->GetDiscountedPrice(nEvent, nFee, GetPlayerLevel());
    unsigned __int64 nPrice = nSale;
    bool bCanPay = CanPayFee(pFee, (const unsigned*)&nPrice);
    bool bFree = false;
    if (!bCanPay && !bFree)
    {
        FUN_14134a2e0(pFee);
        return 0;
    }
    int nSlot = FUN_140f01070(GetShopKind());
    m_198->RestoreSlot(nSlot);
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.WriteUInt8(0x15);
    packet.WriteInt64(spItem->GetItemUid());
    packet.WriteUInt8((unsigned char)spItem->GetSlot());
    FUN_140710590(packet);
    FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    m_2b0 = 1;
    return 1;
}

// @0x140f08f20
void UIBeautyShopStyleDialog::FUN_140f08f20(unsigned n)
{
    unsigned nMax = GetMaxSlotCount();
    m_290 = n < nMax ? n : nMax;
}

// Drop the selection and restore the hair.
// @0x140f08f70
void UIBeautyShopStyleDialog::FUN_140f08f70()
{
    if (m_items == 0)
        return;
    if (m_198.get())
    {
        int nSlot = FUN_140f01070(GetShopKind());
        m_198->RestoreSlot(nSlot);
    }
    FUN_140f08ba0();
    reinterpret_cast<ASCoreList*>(m_items.operator->())->SetSelectedIndex(-1);
}

// @0x140f09020
MS2Ptr<CItem> UIBeautyShopStyleDialog::FUN_140f09020(int nIndex)
{
    int nCount = (int)m_298.size();
    if (nIndex < 0 || nCount <= nIndex)
        return MS2Ptr<CItem>(0);
    return MS2Ptr<CItem>(m_298.at(nIndex));
}

// @0x140f090d0
MS2Ptr<CItem> UIBeautyShopStyleDialog::FUN_140f090d0(int nSlot)
{
    if (m_298.empty())
        return MS2Ptr<CItem>(0);
    size_t nCount = m_298.size();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CItem> spItem(m_298.at(i));
        if (spItem == 0)
            continue;
        if (spItem->GetSlot() == nSlot)
            return spItem;
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f09230
bool UIBeautyShopStyleDialog::FUN_140f09230()
{
    return FUN_140f01470(m_290);
}

// @0x140f09260
int UIBeautyShopStyleDialog::GetRemainSlotCount()
{
    int nRemain = m_290 - m_298.size();
    return nRemain;
}

// @0x140f092b0
void UIBeautyShopStyleDialog::FUN_140f092b0()
{
    m_2b0 = 0;
    FUN_140f08f70();
}

// @0x140f092e0
void UIBeautyShopStyleDialog::SetExtendSlotVisible(int b)
{
    if (m_30 == 0)
        return;
    SetChildVisible(m_30->GetValue(), CString("m_extendSlot"), b);
}

// The "my codi" tab changed: drop the page when its outfit expired.
// @0x140f09380
void UIBeautyShopStyleDialog::FUN_140f09380(NotifyObject* pNotify)
{
    if (m_30 == 0 || m_198 == 0)
        return;
    NotifyChangeActiveMyCodiTab* pTab = dynamic_cast<NotifyChangeActiveMyCodiTab*>(pNotify);
    if (pTab != 0 && pTab->m_bActive == 0)
        ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_by_expired_codi"), 0,
                      Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f09520));
    else
        FUN_140f09560();
}

// @0x140f09520
bool UIBeautyShopStyleDialog::FUN_140f09520(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
        return FUN_140f09560();
    return true;
}

// @0x140f09560
bool UIBeautyShopStyleDialog::FUN_140f09560()
{
    if (m_30 == 0 || m_198 == 0)
        return true;
    int nKind = GetShopKind();
    if (nKind == 1)
    {
        m_30->Invoke("setEnableCheckPreviewWithCap", FUN_140f09630());
        if (m_264 != 0)
            FUN_140f07a00();
        else
            FUN_140f079a0();
    }
    return true;
}

// The player wears a cap (m_268) / has a hair slot item.
// @0x140f09630
bool UIBeautyShopStyleDialog::FUN_140f09630()
{
    Unk_BSPlayer* pPc = ((Unk_BSPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return false;
    bool bResult = false;
    if (GetShopKind() == 1)
    {
        m_268 = ((class Unk_BSPlayerCap*)((class PC*)(class PCBase*)(pPc))->GetGemEquip())->IsSlotHidden(0);
        MS2Ptr<CEquipItem> spEquip = reinterpret_cast<CEquipment*>(((class PC*)(class PCBase*)(pPc))->GetEquipment())->GetTopLayerItem(6, 0);
        if (spEquip.get())
            bResult = true;
    }
    return bResult;
}

// A saved style slot object.
// @0x140f096f0
bool FUN_140f096f0(ASObj& obj, MS2Ptr<CItemData> spData, int nIndex, unsigned nMerat, int nGender)
{
    WriteItemInfo(obj, MS2Ptr<CItemData>(spData), false);
    obj.SetIntMember("idx", nIndex);
    obj.SetMemberUInt("merat", nMerat);
    obj.SetBoolMember("enableDelete", true);
    bool bDisable = static_cast<Unk_BSItemData*>(spData.operator->())->IsGenderAllowed(nGender) == 0;
    obj.SetBoolMember("disable", bDisable);
    obj.SetBoolMember("editable", false);
    return true;
}

// An empty (bEnabled) or locked slot object.
// @0x140f09810
bool FUN_140f09810(ASObj& obj, bool bEnabled)
{
    obj.SetIntMember("idx", -1);
    obj.SetIntMember("merat", 0);
    if (!bEnabled)
        obj.SetBoolMember("enabled", bEnabled);
    return true;
}

// ---- template / helper zone ----

// The bill dialog when it is open.
// @0x140f0a350
UIBillDialog* FUN_140f0a350(int nId)
{
    if (reinterpret_cast<Unk_BSUIMgr*>(TSingleton<CUIService>::GetInstance()))
    {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<UIBillDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140f0a3f0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, Scaleform::GFx::Value a3)
{
    ASArgList args;
    args.resize(3);
    FUN_1422bccb0(&args[0], a1);
    FUN_1422bccb0(&args[1], a2);
    SetValue(&args[2], a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f0a510
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, Scaleform::GFx::Value a2)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bccb0(&args[0], a1);
    SetValue(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f0a610
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, const wchar_t* a1, bool a2, bool a3)
{
    ASArgList args;
    args.resize(3);
    FUN_1422bcea0(&args[0], a1);
    SetBoolean(&args[1], a2);
    SetBoolean(&args[2], a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f0a6f0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, CStringW a2, bool a3, bool a4)
{
    ASArgList args;
    args.resize(4);
    FUN_1422bcea0(&args[0], a1);
    FUN_1422bcea0(&args[1], a2);
    SetBoolean(&args[2], a3);
    SetBoolean(&args[3], a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f0a830
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, long a2)
{
    ASArgList args;
    args.resize(2);
    SetValue(&args[0], a1);
    FUN_1422bccb0(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// A message box with a result callback and an int argument.
// @0x140f0a930
MS2Ptr<CMsgBoxData> FUN_140f0a930(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb, int nArg)
{
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(nType));
    spBox->SetMsg(strText);
    spBox->SetCallback(cb);
    spBox->Append<int>(nArg);
    FUN_14151f150(MS2Ptr<CMsgBoxData>(spBox));
    return spBox;
}

// The style list (MS2Ptr<ASTileCacheList>): its copy ctor 0x140f0afb0, reset 0x140f0b310 and test 0x140f0b480 COMDATs come from ms2ptr_impl.h.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// The range-checked vector::at is out of line in the exe (0x140f0ba50).
template MS2Ptr<CItem>& std::vector<MS2Ptr<CItem> >::at(size_t);

MS2_EMIT_CRT_MEMMOVE_S();  // memmove_s 0x140f02f70

// ---- hooks ----
MS2_REPLACE_METHOD(0x140f034d0, UIBeautyShopStyleDialog, GetTypeName, 61, 0xC0C64D99);
MS2_REPLACE_METHOD(0x140f03520, UIBeautyShopStyleDialog, vfunc_84, 46, 0xB677C877);
MS2_REPLACE_METHOD(0x140f039c0, UIBeautyShopStyleDialog, vfunc_13, 74, 0x7553428A);
MS2_REPLACE_METHOD(0x140f03a10, UIBeautyShopStyleDialog, vfunc_15, 125, 0x26EE34D7);
MS2_REPLACE_METHOD(0x140f04f80, UIBeautyShopStyleDialog, vfunc_45, 1234, 0xF288E122);
MS2_REPLACE_METHOD(0x140f05640, UIBeautyShopStyleDialog, SendBeautyMode19, 154, 0xFB315DAA);
MS2_REPLACE_METHOD(0x140f056e0, UIBeautyShopStyleDialog, SendBeautyMode18, 308, 0xE4575DF0);
MS2_REPLACE_METHOD(0x140f05820, UIBeautyShopStyleDialog, FUN_140f05820, 42, 0x71D82932);
MS2_REPLACE_METHOD(0x140f05850, UIBeautyShopStyleDialog, FUN_140f05850, 42, 0x46B9E12D);
MS2_REPLACE_METHOD(0x140f05880, UIBeautyShopStyleDialog, FUN_140f05880, 503, 0xCAE5A632);
MS2_REPLACE_METHOD(0x140f07310, UIBeautyShopStyleDialog, FUN_140f07310, 515, 0x90E4B570);
MS2_REPLACE_METHOD(0x140f07520, UIBeautyShopStyleDialog, FUN_140f07520, 1073, 0x79B02DCF);
MS2_REPLACE_METHOD(0x140f07960, UIBeautyShopStyleDialog, FUN_140f07960, 17, 0x7072483A);
MS2_REPLACE_METHOD(0x140f07980, UIBeautyShopStyleDialog, GetShopKind, 17, 0x0B11C3C6);
MS2_REPLACE_METHOD(0x140f079a0, UIBeautyShopStyleDialog, FUN_140f079a0, 76, 0x20CC042B);
MS2_REPLACE_METHOD(0x140f07a00, UIBeautyShopStyleDialog, FUN_140f07a00, 76, 0xC3E666C2);
MS2_REPLACE_METHOD(0x140f07a60, UIBeautyShopStyleDialog, FUN_140f07a60, 597, 0xAB424548);
MS2_REPLACE_METHOD(0x140f07cc0, UIBeautyShopStyleDialog, FUN_140f07cc0, 343, 0xEBC6CC4C);
MS2_REPLACE_METHOD(0x140f07e20, UIBeautyShopStyleDialog, FUN_140f07e20, 825, 0xE90B7407);
MS2_REPLACE_METHOD(0x140f08160, UIBeautyShopStyleDialog, GetFeeAmount, 41, 0xBAEA161B);
MS2_REPLACE_METHOD(0x140f08190, UIBeautyShopStyleDialog, GetFee, 132, 0xF13C26B8);
MS2_REPLACE_METHOD(0x140f08220, UIBeautyShopStyleDialog, FUN_140f08220, 166, 0x583C8BBF);
MS2_REPLACE_METHOD(0x140f08470, UIBeautyShopStyleDialog, OnClickReset, 92, 0x47771337);
MS2_REPLACE_METHOD(0x140f084e0, UIBeautyShopStyleDialog, BuildBillRows, 1119, 0xB28E6AA2);
MS2_REPLACE_METHOD(0x140f08950, UIBeautyShopStyleDialog, FUN_140f08950, 216, 0x7B531712);
MS2_REPLACE_METHOD(0x140f08a30, UIBeautyShopStyleDialog, SetPreview, 92, 0x844DDB0F);
MS2_REPLACE_METHOD(0x140f08aa0, UIBeautyShopStyleDialog, FUN_140f08aa0, 47, 0x1F4F7493);
MS2_REPLACE_METHOD(0x140f08ae0, UIBeautyShopStyleDialog, FUN_140f08ae0, 173, 0x3696E501);
MS2_REPLACE_METHOD(0x140f08ba0, UIBeautyShopStyleDialog, FUN_140f08ba0, 49, 0xE8A3DCFD);
MS2_REPLACE_METHOD(0x140f08be0, UIBeautyShopStyleDialog, FUN_140f08be0, 818, 0x4A4AF65D);
MS2_REPLACE_METHOD(0x140f08f20, UIBeautyShopStyleDialog, FUN_140f08f20, 70, 0x8AF71560);
MS2_REPLACE_METHOD(0x140f08f70, UIBeautyShopStyleDialog, FUN_140f08f70, 162, 0x67553572);
MS2_REPLACE_METHOD(0x140f09020, UIBeautyShopStyleDialog, FUN_140f09020, 156, 0x8D825A5E);
MS2_REPLACE_METHOD(0x140f090d0, UIBeautyShopStyleDialog, FUN_140f090d0, 343, 0x369D3F05);
MS2_REPLACE_METHOD(0x140f09230, UIBeautyShopStyleDialog, FUN_140f09230, 30, 0xC252B8F0);
MS2_REPLACE_METHOD(0x140f09260, UIBeautyShopStyleDialog, GetRemainSlotCount, 66, 0x4E988A09);
MS2_REPLACE_METHOD(0x140f092b0, UIBeautyShopStyleDialog, FUN_140f092b0, 36, 0xB6F8D97A);
MS2_REPLACE_METHOD(0x140f092e0, UIBeautyShopStyleDialog, SetExtendSlotVisible, 142, 0xA00B0550);
MS2_REPLACE_METHOD(0x140f09520, UIBeautyShopStyleDialog, FUN_140f09520, 44, 0x34BE8CED);
MS2_REPLACE_METHOD(0x140f09560, UIBeautyShopStyleDialog, FUN_140f09560, 198, 0x7A0ECB17);
MS2_REPLACE_METHOD(0x140f09630, UIBeautyShopStyleDialog, FUN_140f09630, 172, 0x391CD9C0);
