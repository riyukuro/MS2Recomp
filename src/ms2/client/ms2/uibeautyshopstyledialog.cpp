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
// MS2-PIN: ??4?$Unk_14102fe10@VUnk_140bfc2e0@@@@QEAAAEAV0@AEBV0@@Z 0x140f0b2d0
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
// MS2-PIN: ??$LocalizedMentorFormat@I_J@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBIAEB_J@Z 0x140f09c60 ; unique
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
template <> Unk_14102fe10<Unk_140bfc2e0>::Unk_14102fe10(const Unk_14102fe10& o);
template <> bool Unk_14102fe10<Unk_140bfc2e0>::operator==(Unk_140bfc2e0* p) const;
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
    int m_id;                                   // +0x18 item id
    char m_pad_1c[0x24 - 0x1c];
    unsigned short m_level;                     // +0x24 required level
    int m_achieve;                              // +0x28 achieve required
    int m_grade;                                // +0x2c grade of that achieve
};
MS2_CHECK_OFFSET(Unk_BSPriceRow, m_level, 0x24);
MS2_CHECK_OFFSET(Unk_BSPriceRow, m_grade, 0x2c);
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
};
class Unk_BSPlayer : public PCBase
{
public:
    MS2Ptr<Unk_InventoryEquipment> FUN_141655c30(__int64 nItemUid);
    MS2Ptr<Unk_InventoryEquipment> FUN_141655e10(int nSlot);
};
class Unk_BSPlayerCap { public: int FUN_1412706f0(int n); };
class Unk_BSEquipSet { public: MS2Ptr<Unk_InventoryEquipment> FUN_1411e1a50(int nSlot, int n); };
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
class Unk_BSCutScene { public: bool FUN_14116d840(); };
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
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW GetStringCommon(int nId);
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
CStringW FUN_140f010c0(int nItemId)
{
    if (nItemId == 0x9a1d21)
        return GetStringCommon(0x26f);
    return FUN_1401a9d70()->FUN_141811980(1, nItemId);
}

// @0x140f01140
int FUN_140f01140()
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    return FUN_141658f30(pPc);
}

// @0x140f01180
__int64 FUN_140f01180()
{
    return FUN_1401d3200()->m_extendPrice.FUN_1402bac90();
}

// @0x140f011b0
unsigned FUN_140f011b0()
{
    return FUN_140f011f0() + *FUN_1401d7c10(&FUN_1401d3200()->m_maxExtend);
}

// @0x140f011f0
int FUN_140f011f0()
{
    return FUN_1401d3200()->m_baseSlots.FUN_140ec2b60();
}

// @0x140f01220
int FUN_140f01220()
{
    return FUN_1401d3200()->m_extendCount.FUN_140ec2b60();
}

// Save the equipped hair into a slot.
// @0x140f01250
bool SendBeautyMode16(__int64 nItemUid)
{
    if (nItemUid == 0)
        return false;
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.vfunc_o10_1(0x10);
    packet.vfunc_o10_4(nItemUid);
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
    packet.vfunc_o10_1(0x11);
    packet.vfunc_o10_4(nItemUid);
    FUN_140710590(packet);
    return true;
}

// The hair change effect on the player.
// @0x140f01350
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void FUN_140f01350()
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        if (pPc->FUN_14166c930() != 0xe)
            pPc->vfunc_59(0xe, 0, 0, 0);
        FUN_14166cc40(pPc, 0x50);
        Unk_BSEffectRequest request;
        FUN_140a52ef0(&request);
        request.m_strName = FUN_1401d31f0()->m_hairApply;
        request.m_n08 = 1;
        FUN_140a53190(&request, FUN_14123c580(pPc));
        FUN_1403ed280()->FUN_1411a4a00(&request);
        FUN_1405a89e0(&request);
    }
}

// @0x140f01430
void FUN_140f01430()
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
        pPc->FUN_14166ed70(0x56057c6);
}

// @0x140f01470
bool FUN_140f01470(unsigned nSlots)
{
    unsigned nNeed = FUN_140f011b0();
    return nSlots >= nNeed;
}

class CEquipItem;
class Unk_PCEquipSet;
void FUN_1411e3000(Unk_PCEquipSet* pSet, ATL::CAtlList<MS2Ptr<CEquipItem> >* pList, int nType, int a4, bool a5);

// @0x140f014b0
void FUN_140f014b0(ATL::CAtlList<MS2Ptr<CEquipItem> >* pList, Unk_PCEquipSet* pSet)
{
    FUN_1411e3000(pSet, pList, 4, 0, false);
}

// @0x140f014f0
void FUN_140f014f0(MS2Ptr<Customize> spCustomize)
{
    if (spCustomize.get())
        spCustomize->FUN_140cd20c0();
}

// @0x140f01540
void FUN_140f01540(ASObj& obj, bool bHair)
{
    bool bExtended = FUN_140166410()->FUN_14036d570(0xb7);
    bool bVisible = bExtended == true;
    obj.FUN_1407cbbe0("colorScrollVisible", bVisible);
    if (bExtended)
    {
        int nRow = bHair == true ? 4 : 5;
        obj.FUN_1407cb9c0("fixRow", nRow);
    }
}

// The colour palette of an item.
// @0x140f015f0
int FUN_140f015f0(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return 0;
    return static_cast<Unk_BSItemData*>(spData.operator->())->FUN_14053e260();
}

int FUN_140f01800(ASTooltip& tip, unsigned nR, unsigned nG, unsigned nB, int nPalette, int nIndex);

// The colour tooltip callback: (r, g, b, ..., {paletteID, colorSN}).
// @0x140f01670
// MS2-FUNCTIONAL: the argument object is built with the non-const Value ctor in the exe
bool FUN_140f01670(ASTooltip& tip, void*, ASData* pArgs)
{
    unsigned nR = pArgs->FUN_1422b8b10();
    unsigned nG = pArgs->FUN_1422b8b10();
    unsigned nB = pArgs->FUN_1422b8b10();
    pArgs->FUN_1422b8b10();
    AScript obj(pArgs->FUN_1422b9260(), 2);
    int nPalette = FUN_1409c17e0(obj.FUN_1422baa20("paletteID"));
    int nIndex = FUN_1409c17e0(obj.FUN_1422baa20("colorSN"));
    return FUN_140f01800(tip, nR, nG, nB, nPalette, nIndex) != 0;
}

// @0x140f01800
// MS2-FUNCTIONAL: string temporaries and branch layout differ
int FUN_140f01800(ASTooltip& tip, unsigned nR, unsigned nG, unsigned nB, int nPalette, int nIndex)
{
    CStringW strOut;
    bool bShowRgb = !FUN_140166410()->FUN_14036d570(0xb7);
    if (nPalette)
    {
        Unk_BSColorPtr spRow = FUN_140281980()->FUN_140558960(nPalette, nIndex);
        if (spRow.get())
        {
            CStringW strRgb = LocalizedMentorFormat(L"s_beauty_tooltip_color", nR, nG, nB);
            CStringW strName;
            if (spRow->m_nameId)
            {
                CStringW strColor = FUN_1401a9d70()->FUN_141811980(0x48, spRow->m_nameId);
                if (!strColor.IsEmpty())
                {
                    strName = FUN_1408f71a0(CStringW(L"s_beauty_tooltip_color_desc"), strColor,
                                            FUN_1401a9d70()->FUN_141811980(0x49, spRow->m_nameId));
                    if (bShowRgb)
                    {
                        strName += L"\n";
                        strName += strRgb;
                    }
                }
            }
            if (strName.IsEmpty() && bShowRgb)
                strName = strRgb;
            CStringW strAchieve;
            if (spRow->m_achieve && FUN_1406c7600()->FUN_140936900(spRow->m_achieve, spRow->m_grade) == 0)
                strAchieve = FUN_14093bd40(spRow->m_achieve, spRow->m_grade, CStringW(L""));
            if (strAchieve.IsEmpty())
                strOut = strName;
            else if (!strName.IsEmpty())
                strOut = FUN_1408f71a0(CStringW(L"s_beauty_tooltip_color_with_achieve"), strName, strAchieve);
            else
                strOut = strAchieve;
        }
    }
    if (strOut.IsEmpty() && bShowRgb)
        strOut = LocalizedMentorFormat(L"s_beauty_tooltip_color", nR, nG, nB);
    if (strOut.IsEmpty())
        return 1;
    if (!tip.FUN_1409e26b0(strOut))
        return 0;
    tip.FUN_1409c6dc0(1);
    return 1;
}

bool FUN_140f02b10(Unk_BSPricePtr spPrice, short nLevel);

// The price tooltip of a beauty shop entry.
// @0x140f01eb0
// MS2-FUNCTIONAL: string temporaries differ
bool FUN_140f01eb0(ASTooltip& tip, Unk_BSPricePtr spPrice, short nLevel, const CStringW& strPrice)
{
    CStringW strText;
    if (FUN_140f02b10(Unk_BSPricePtr(spPrice), nLevel))
    {
        if (spPrice->m_level == 0)
        {
            if (spPrice->m_achieve)
                strText = FUN_1409eaa20(CStringW(L"s_beauty_tooltip_price_with_achieve"), FUN_140f010c0(spPrice->m_id),
                                        FUN_14093bd40(spPrice->m_achieve, spPrice->m_grade, CStringW(L"")), strPrice);
        }
        else
        {
            strText = LocalizedMentorFormat(L"s_beauty_tooltip_price_with_requirelevel", FUN_140f010c0(spPrice->m_id),
                                            spPrice->m_level, strPrice);
        }
    }
    if (strText.IsEmpty())
        strText = FUN_140632a60(0x274, FUN_140f010c0(spPrice->m_id), strPrice);
    int nRet = tip.FUN_1409e26b0(strText);
    if (nRet)
        tip.FUN_1409c6dc0(5);
    return nRet != 0;
}

int FUN_140f02bc0();

// The nIndex-th colour of a palette (past the palette: the extended palette, when enabled).
// @0x140f022f0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
Unk_BSColorPtr FUN_140f022f0(int nPalette, unsigned nIndex)
{
    MS2Ptr<Unk_BSColorList> spList = FUN_140281980()->FUN_140558ad0(nPalette);
    if (spList == 0)
        return Unk_BSColorPtr(0);
    Unk_BSColorPtr spRow(0);
    unsigned nCount = spList->FUN_140570e10();
    if (nIndex < nCount)
        spRow = spList->FUN_140570dd0(nIndex);
    else
    {
        if (!FUN_140166410()->FUN_14036d570(0xb7))
            return Unk_BSColorPtr(0);
        spRow = FUN_140281980()->FUN_1405587f0(FUN_140f02bc0(), nIndex - nCount);
    }
    return Unk_BSColorPtr(std::move(spRow));
}

// The colour tooltip of the "my colour" slots.
// @0x140f024e0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void FUN_140f024e0(ASData* pArgs, int* pnPalette, int* pnType)
{
    *pnPalette = pArgs->FUN_1422b8b10();
    *pnType = pArgs->FUN_1422b8b10() ? 2 : 0;
    unsigned nR = pArgs->FUN_1422b8b10();
    unsigned nG = pArgs->FUN_1422b8b10();
    unsigned nB = pArgs->FUN_1422b8b10();
    AScript obj(pArgs->FUN_1422b9260(), 2);
    static_cast<ASObj&>(obj).FUN_1407cbb20("colorTooltip", LocalizedMentorFormat(L"s_beauty_tooltip_color", nR, nG, nB));
}

bool FUN_140f026f0(Unk_BSColorPtr spRow, bool* pbLocked);
bool FUN_140f02790(unsigned nAchieve, int nGrade, bool* pbLocked);

// @0x140f02650
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool FUN_140f02650(int nItemId, unsigned nIndex, bool* pbLocked)
{
    if (!nItemId)
        return false;
    int nPalette = FUN_140f015f0(nItemId);
    if (!nPalette)
        return true;
    return FUN_140f026f0(Unk_BSColorPtr(FUN_140f022f0(nPalette, nIndex)), pbLocked);
}

// @0x140f026f0
bool FUN_140f026f0(Unk_BSColorPtr spRow, bool* pbLocked)
{
    *pbLocked = false;
    if (spRow == 0)
        return false;
    return FUN_140f02790(spRow->m_achieve, spRow->m_grade, pbLocked);
}

// @0x140f02790
bool FUN_140f02790(unsigned nAchieve, int nGrade, bool* pbLocked)
{
    *pbLocked = false;
    if (nAchieve > 0)
    {
        MS2Ptr<CAchieve> spAchieve = FUN_1406c7600()->FUN_140935e60(nAchieve);
        if (spAchieve == 0)
            return false;
        *pbLocked = FUN_1406c7600()->FUN_140936900(nAchieve, nGrade) == 0;
        return true;
    }
    return true;
}

// @0x140f02860
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool FUN_140f02860(Unk_BSPricePtr spPrice, unsigned short nLevel, bool* pbLocked)
{
    *pbLocked = false;
    if (spPrice == 0)
        return false;
    bool bLowLevel = false;
    if (spPrice->m_level)
        bLowLevel = nLevel < spPrice->m_level;
    bool bAchieve = false;
    if (spPrice->m_achieve && !FUN_140f02790(spPrice->m_achieve, spPrice->m_grade, &bAchieve))
        return false;
    *pbLocked = bLowLevel || bAchieve;
    return true;
}

// @0x140f029b0
bool FUN_140f029b0(int nItemId, unsigned nIndex)
{
    if (!nItemId)
        return false;
    bool bLocked = false;
    FUN_140f02650(nItemId, nIndex, &bLocked);
    return bLocked;
}

// @0x140f029f0
bool FUN_140f029f0(Unk_BSColorPtr spRow)
{
    if (spRow == 0)
        return false;
    bool bLocked = false;
    FUN_140f026f0(Unk_BSColorPtr(spRow), &bLocked);
    return bLocked;
}

// @0x140f02a80
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool FUN_140f02a80(int nPalette, int nIndex)
{
    if (!nPalette)
        return false;
    return FUN_140f029f0(Unk_BSColorPtr(FUN_140281980()->FUN_140558960(nPalette, nIndex)));
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
    FUN_141925e70(0, 1);
    FUN_140bccd50()->FUN_140da5180(0x31, Delegate<void(CInPacket&)>(this, &UIBeautyShopStyleDialog::FUN_140f05a80));
}

// @0x140f03330
UIBeautyShopStyleDialog::~UIBeautyShopStyleDialog()
{
    FUN_140bccd50()->FUN_140da51e0(0x31, Delegate<void(CInPacket&)>(this, &UIBeautyShopStyleDialog::FUN_140f05a80));
}

// @0x140f034d0
CString UIBeautyShopStyleDialog::GetTypeName()
{
    return "BeautyShopStyleDialog";
}

// @0x140f03520
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopStyleDialog::vfunc_84()
{
    return vfunc_55() == 0;
}

// @0x140f03560
void UIBeautyShopStyleDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_1a8.AssignRaw(FUN_140cd47b0(0x4ef2));
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopStyleDialog::FUN_140f05460));
    FUN_140f06e10();
    FUN_140d86260()->vfunc_43(0xe, 0, 1000);
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
    m_1b8.FUN_1406e3d30();
    m_298.clear();
    m_2b0 = 0;
    FUN_140f01430();
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopStyleDialog::FUN_140f05460));
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopStyleDialog::FUN_140f09380));
}

// @0x140f039c0
int UIBeautyShopStyleDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (FUN_14025e7c0()->FUN_14116d840())
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
        m_1a8->FUN_1418dda30(1);
}

// The AS calls of the page.
// @0x140f03aa0
// MS2-FUNCTIONAL: large EH frame; temporaries and branch order differ
int UIBeautyShopStyleDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnChangeItem", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            FUN_140f08950(0);
            int nItemId = FUN_141b71a10(data.FUN_1422b8d30());
            data.FUN_1422b8a10();
            data.FUN_1422b8a10();
            AScript obj(data.FUN_1422b9260(), 2);
            if (!obj.FUN_1422ba9a0())
                FUN_140f08ae0(nItemId, FUN_1409c1750(obj.FUN_1422baa20("index")));
            FUN_140f07cc0();
        }
        return 1;
    }
    if (_stricmp("OnClickClose", szMethod) == 0)
    {
        FUN_140f082d0();
        return 1;
    }
    if (_stricmp("OnClickReset", szMethod) == 0)
    {
        OnClickReset();
        return 1;
    }
    if (_stricmp("OnClickSave", szMethod) == 0)
    {
        if (m_items.get())
        {
            int nIndex = m_items->FUN_1422dccd0();
            if (nIndex == -1)
            {
                FUN_140d74390(GetStringCommonByKey(CStringW(L"s_beauty_msg_error_invalid_selected_style")), 0, FUN_140b240b0());
                return 1;
            }
            MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
            if (!(spItem == 0))
            {
                if (spItem->FUN_140527840() == 0)
                    return 1;
                Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pPc == 0)
                    return 1;
                int nGender = FUN_141658e60(pPc);
                if (reinterpret_cast<Unk_BSItemData*>(spItem->FUN_140527840())->FUN_14053c940(nGender) == 0)
                {
                    FUN_140d74390(GetStringCommonByKey(CStringW(L"s_beauty_msg_error_style_disable_gender")), 0, FUN_140b240b0());
                    return 1;
                }
            }
            else
                return 1;
        }
        if (UIBillDialog* pBill = FUN_140f0a350(0x4e7b))
        {
            MS2Ptr<AScript> spRows(new AScript(2));
            if (spRows.get())
            {
                unsigned nPrice = 0;
                if (FUN_140f084e0(*spRows, &nPrice))
                {
                    unsigned nFee = 0;
                    Unk_BSFee* pFee = FUN_140f08190(&nFee);
                    MS2Ptr<UIBillDialog::TData> spData(new UIBillDialog::TData);
                    if (spData.get())
                    {
                        spData->m_18 = static_cast<IMessageListener*>(this);
                        spData->m_30 = 2;
                        spData->m_20 = spRows;
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
        if (FUN_140f07980() != 1)
            return 1;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int bPreview = data.FUN_1422b8a90() != 0;
            FUN_140f08a30(bPreview);
            if (bPreview && m_268)
                FUN_141275260(0x270, 1, 0);
        }
        return 1;
    }
    if (_stricmp("onClickSaveCurStyle", szMethod) == 0)
    {
        FUN_140f08950(0);
        FUN_140f08f70();
        if (FUN_140f09260() > 0)
        {
            FUN_140f07310();
            return 1;
        }
        if (FUN_140f09230())
        {
            FUN_140d74390(GetStringCommonByKey(CStringW(L"s_beauty_msg_error_style_slot_max_in_style_npc")), 0, FUN_140b240b0());
            return 1;
        }
        unsigned nCount = FUN_140f01220();
        __int64 nPrice = FUN_140f01180();
        CStringW strText = LocalizedMentorFormat(L"s_beauty_msg_ask_save_style_extend_in_style_npc", nPrice, nCount);
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(CStringW(strText), 1);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f05880));
        spBox->FUN_141a024a0(0);
        FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
        return 1;
    }
    if (_stricmp("onClickExtendSlot", szMethod) == 0)
    {
        if (FUN_140f09230())
        {
            FUN_140d74390(GetStringCommonByKey(CStringW(L"s_beauty_msg_error_style_slot_extend_max")), 0, FUN_140b240b0());
            return 1;
        }
        __int64 nPrice = FUN_140f01180();
        unsigned nCount = FUN_140f01220();
        CStringW strText = LocalizedMentorFormat(L"s_beauty_msg_ask_save_style_extend", nCount, nPrice);
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(CStringW(strText), 1);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::SendBeautyMode19));
        spBox->FUN_141a024a0(0);
        FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
        return 1;
    }
    if (_stricmp("onClickDeleteCharacterCreateItem", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            AScript obj(data.FUN_1422b9260(), 2);
            int nIndex = FUN_1409c1750(obj.FUN_1422baa20("index"));
            MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
            if (spItem == 0)
            {
                FUN_140d74390(GetStringCommonByKey(CStringW(L"s_beauty_msg_error_already_empty_slot")), 0, FUN_140b240b0());
                return 1;
            }
            int nItemId = spItem->FUN_1405276c0();
            CStringW strText = FUN_1405c2690(CStringW(L"s_beauty_msg_ask_delete_style"), FUN_1401a9d70()->FUN_141811980(1, nItemId));
            FUN_140f0a930(CStringW(strText), 1,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::SendBeautyMode18), nIndex);
        }
        return 1;
    }
    return 0;
}

// The answers of the scene (OnExit) and of the bill dialog (OK: apply).
// @0x140f04e50
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopStyleDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520())
        return 0;
    if (dynamic_cast<UISceneGameBeautyShop*>(pSender))
    {
        if (FUN_140184310(pMsg->FUN_1422b8d30(), "OnExit"))
            FUN_140f082d0();
        return 1;
    }
    if (dynamic_cast<UIBillDialog*>(pSender))
    {
        if (pMsg->FUN_1422b8a10() == 0)
            FUN_140f08be0();
        return 1;
    }
    return 0;
}

// @0x140f04f80
// MS2-FUNCTIONAL: string temporaries differ
void UIBeautyShopStyleDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (_stricmp("getTooltipFee", strMethod) == 0)
    {
        AScript obj(2);
        unsigned nPrice = 0;
        FUN_140f084e0(obj, &nPrice);
        *pRetVal = obj.FUN_1422bb870();
    }
    else if (_stricmp("getTooltip", strMethod) == 0)
    {
        pArgs->FUN_1422b8a10();
        Scaleform::GFx::Value value = pArgs->FUN_1422b9260();
        if (!FUN_1409b0390(&value))
        {
            AScript obj(value, 2);
            int nIndex = FUN_1409c1750(obj.FUN_1422baa20("index"));
            CStringW strText;
            MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
            if (!(spItem == 0))
            {
                unsigned nFee = 0;
                Unk_BSFee* pFee = FUN_140f08190(&nFee);
                unsigned __int64 nBase = (unsigned)FUN_140f08160();
                CStringW strPrice = FUN_14134a220(pFee, &nBase);
                CStringW strDate = FUN_14052bd00(0x276, FUN_14083bab0(FUN_1406c47a0(spItem->FUN_140528ae0()), CStringW(L"/")));
                strText = FUN_1409eadb0(0x275, FUN_140f010c0(spItem->FUN_1405276c0()), strDate, strPrice);
            }
            else
                strText = GetStringCommonByKey(CStringW(L"s_beauty_tooltip_recommand_save_style"));
            ASTooltip tip(1, 2);
            if (tip.FUN_1409e26b0(strText))
            {
                tip.FUN_1409c6dc0(5);
                *pRetVal = tip.FUN_1422bb870();
            }
        }
        else
        {
            AScript empty(2);
            *pRetVal = empty.FUN_1422bb870();
        }
    }
}

// A game event changed: refresh the sale price.
// @0x140f05460
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopStyleDialog::FUN_140f05460(NotifyObject* pNotify)
{
    NotifyGameEventChanged* pEvent = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pEvent && FUN_140841300(pEvent->m_eventName, "SaleBeautyShop"))
    {
        unsigned nFee = 0;
        Unk_BSFee* pFee = FUN_140f08190(&nFee);
        FUN_140f07520(pFee, &nFee);
        MS2Ptr<ASMovieClip> spPcBang = FUN_140ba7930(CString("m_pcBang"));
        if ((ASMovieClip*)spPcBang)
        {
            int nLevel = FUN_140f01140();
            int nEvent = FUN_140f07960();
            spPcBang->vfunc_4(FUN_1401c0d90()->FUN_140476cf0(nEvent, nLevel) == 0);
        }
        UIBillDialog* pBill;
        if (FUN_1403ed2b0()->FUN_141adc890(0x4e7b) && (pBill = FUN_140f0a350(0x4e7b)) != 0)
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
        packet.vfunc_o10_1(0x13);
        FUN_140710590(packet);
        FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    }
    return true;
}

// Delete a saved style (answer of "s_beauty_msg_ask_delete_style"; argument 0: the slot).
// @0x140f056e0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopStyleDialog::SendBeautyMode18(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        int nIndex = data.FUN_141a02e50(0, 0);
        MS2Ptr<CItem> spItem = FUN_140f09020(nIndex);
        if (!(spItem == 0))
        {
            COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
            packet.vfunc_o10_1(0x12);
            packet.vfunc_o10_4(spItem->FUN_140526a50());
            packet.vfunc_o10_1((unsigned char)nIndex);
            FUN_140710590(packet);
            FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
        }
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
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopStyleDialog::FUN_140f05880(int nResult, const CMsgBoxData&)
{
    if (nResult != 0)
        return true;
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return true;
    MS2Ptr<Unk_InventoryEquipment> spEquip = pPc->FUN_141655e10(FUN_140f01070(FUN_140f07980()));
    if (spEquip == 0 || spEquip->FUN_1411dc7a0() == 0)
        return true;
    MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
    if (!(spItem == 0) && SendBeautyMode17(spItem->FUN_140526a50()))
        FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    return true;
}

// The beauty shop packets (0x31).
// @0x140f05a80
// MS2-FUNCTIONAL: large EH frame; temporaries and branch order differ
void UIBeautyShopStyleDialog::FUN_140f05a80(CInPacket& packet)
{
    unsigned char nOp = packet.vfunc_o8_1();
    if (nOp == 2)
    {
        m_26c = packet.vfunc_o8_1();
        m_1b8.FUN_1406e5420(packet);
    }
    else if (nOp == 0xd)
        m_298.clear();
    else if (nOp == 0xe)
    {
        m_294 = (unsigned short)packet.vfunc_o8_2();
        m_298.reserve(FUN_140f011b0());
        m_260 = 1;
        if (FUN_1422dc430())
            static_cast<UIDialog*>(this)->vfunc_8(1);
    }
    if (nOp == 0x14)
    {
        packet.vfunc_o8_1();
        unsigned nExtended = (unsigned short)packet.vfunc_o8_2();
        int nOld = m_290;
        FUN_140f08f20(nExtended + FUN_140f011f0());
        if (m_30.get() && m_260)
        {
            int nAdded = (int)m_290 - nOld;
            if (nAdded < 0)
                nAdded = 0;
            if (nAdded > 0)
            {
                CStringW strMsg = FUN_14062b4f0(CStringW(L"s_beauty_msg_complete_extend_style_slot"), &nAdded);
                FUN_1412751f0(strMsg, 3, 1);
                ASArray arr(2);
                for (unsigned i = nOld; i < m_290; i++)
                {
                    ASObj obj(2);
                    FUN_140f09810(obj, true);
                    arr.FUN_1422bc050(Scaleform::GFx::Value(obj.FUN_1422bb870()));
                }
                m_30->Invoke("updateItems", nOld, Scaleform::GFx::Value(arr.FUN_1422bb870()));
            }
        }
    }
    else if (nOp == 0xf)
    {
        unsigned nCount = (unsigned short)packet.vfunc_o8_2();
        for (unsigned i = 0; i < nCount; i++)
        {
            MS2Ptr<CItem> spItem(new CItem);
            if (!(spItem == 0))
            {
                int nItemId = packet.vfunc_o8_3();
                __int64 nUid = packet.vfunc_o8_4();
                int nSlot = packet.vfunc_o8_3();
                __int64 nTime = packet.vfunc_o8_4();
                spItem->FUN_140523c40(nItemId, 1, 0);
                spItem->FUN_140526b70(nSlot);
                spItem->FUN_140526a70(nUid);
                spItem->FUN_140528ab0(nTime);
                spItem->FUN_1405255e0(packet);
                m_298.push_back(spItem);
            }
        }
        if (m_298.size() == m_294)
            FUN_140f06e10();
    }
    if (vfunc_55() || m_30 == 0)
        return;
    FUN_1412761e0(MS2Ptr<AScript>(m_30), 1);
    m_2b0 = 0;
    if (nOp == 0x10 || nOp == 0x11)
    {
        __int64 nUid = packet.vfunc_o8_4();
        __int64 nNewUid = packet.vfunc_o8_4();
        int nSlot = packet.vfunc_o8_1();
        __int64 nTime = packet.vfunc_o8_4();
        Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc)
        {
            MS2Ptr<Unk_InventoryEquipment> spEquip = pPc->FUN_141655c30(nUid);
            if (!(spEquip == 0))
            {
                MS2Ptr<CItem> spCopy = spEquip->FUN_1411dc7a0()->FUN_140524250();
                if (!(spCopy == 0))
                {
                    spCopy->FUN_140526a70(nNewUid);
                    spCopy->FUN_140526b70(nSlot);
                    spCopy->FUN_140528ab0(nTime);
                    int nIndex = (int)m_298.size();
                    m_298.push_back(spCopy);
                    ASObj obj(2);
                    int nGender = FUN_141658e60(pPc);
                    FUN_140f096f0(obj, MS2Ptr<CItemData>(reinterpret_cast<CItemData*>(spCopy->FUN_140527840())), nSlot,
                                  FUN_140f08160(), nGender);
                    m_30->Invoke("updateItem", nIndex, Scaleform::GFx::Value(obj.FUN_1422bb870()));
                    FUN_1412752d0(CStringW(L"s_beauty_msg_complete_save_hair_style"), 1);
                }
            }
        }
    }
    else if (nOp == 0x12)
    {
        __int64 nUid = packet.vfunc_o8_4();
        int nIndex = 0;
        for (std::vector<MS2Ptr<CItem> >::iterator it = m_298.begin(); it != m_298.end(); ++it)
        {
            MS2Ptr<CItem> spItem(*it);
            if (spItem.get() && spItem->FUN_140526a50() == nUid)
            {
                m_298.erase(it);
                break;
            }
            nIndex++;
        }
        if (nIndex >= 0)
        {
            ASObj obj(2);
            FUN_140f09810(obj, true);
            m_30->Invoke("removeItemAndAdd", nIndex, (int)m_298.size(), Scaleform::GFx::Value(obj.FUN_1422bb870()));
        }
        FUN_1412752d0(CStringW(L"s_beauty_msg_complete_remove_saved_hair_style"), 1);
        FUN_140f08f70();
    }
    else if (nOp == 0x15)
    {
        FUN_1412752d0(CStringW(L"s_beauty_msg_complete_apply_saved_style"), 3);
        FUN_140f01350();
        FUN_140f092b0();
    }
    else if (nOp == 8)
    {
        Unk_BSResult nCode = (Unk_BSResult)packet.vfunc_o8_3();
        unsigned nFee = 0;
        Unk_BSFee* pFee = FUN_140f08190(&nFee);
        switch (nCode)
        {
        case 2:
            FUN_14134a2e0(pFee);
            break;
        default:
            FUN_140d74390(BlockFormat(0x272, nCode), 0,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f05850));
            break;
        case 7:
            FUN_140d74390(GetStringCommon(0x273), 0,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f05850));
            break;
        case 0x13:
            FUN_140d74390(GetStringCommonByKey(CStringW(L"s_beauty_msg_error_style_slot_extend_max")), 0, FUN_140b240b0());
            break;
        case 0x14:
            FUN_14134a120(4, 0, 0);
            break;
        case 0x17:
            FUN_140d74390(GetStringCommonByKey(CStringW(L"s_beauty_msg_error_style_disable_gender")), 0, FUN_140b240b0());
            break;
        case 0x18:
            FUN_1412752d0(CStringW(L"s_beauty_msg_error_style_apply_already"), 1);
            break;
        case 0x19:
            FUN_1412752d0(CStringW(L"s_beauty_msg_error_style_save_cant_not_beauty_day"), 1);
            break;
        }
    }
}

// All saved styles arrived: fill the page.
// @0x140f06e10
// MS2-FUNCTIONAL: temporaries differ
int UIBeautyShopStyleDialog::FUN_140f06e10()
{
    if (m_30 == 0)
        return 0;
    IItemCustomizeEventListener::FUN_140f0b710(0);
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return 0;
    bool bCap = FUN_140f09630();
    int nKind = FUN_140f07980();
    bool bSale = false;
    if (FUN_140f07960())
    {
        int nLevel = FUN_140f01140();
        bSale = FUN_1401c0d90()->FUN_140476cf0(FUN_140f07960(), nLevel) == 0;
    }
    m_30->Invoke("initData", L"$s_beauty_title_my_style_hair", bCap, bSale);
    m_270 = static_cast<Unk_BSRootScript*>(m_30.operator->())->FUN_140ede0c0(CString("m_customStyle"));
    if (m_270.get())
        m_items = static_cast<Unk_BSStyleEntity*>(m_270.operator->())->FUN_140bfa6a0(CString("m_items"));
    m_198.AssignRaw(new Customize(FUN_14123c580(pPc), static_cast<IItemCustomizeEventListener*>(this), 0));
    int nSlot = FUN_140f01070(nKind);
    if (nKind == 1)
        FUN_140f079a0();
    m_198->FUN_140cd25c0(nSlot);
    FUN_140f07cc0();
    FUN_140f07e20();
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIBeautyShopStyleDialog::FUN_140f09380));
    if (m_260)
        static_cast<UIDialog*>(this)->vfunc_8(1);
    return 1;
}

// Save the equipped hair into a free slot.
// @0x140f07310
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopStyleDialog::FUN_140f07310()
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    MS2Ptr<Unk_InventoryEquipment> spEquip = pPc->FUN_141655e10(FUN_140f01070(FUN_140f07980()));
    if (spEquip == 0 || spEquip->FUN_1411dc7a0() == 0)
        return false;
    MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
    if (spItem == 0 || !SendBeautyMode16(spItem->FUN_140526a50()))
        return false;
    FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    return true;
}

// The fee line ("setFee": price, sale price, sale, discounted).
// @0x140f07520
// MS2-FUNCTIONAL: string temporaries differ
void UIBeautyShopStyleDialog::FUN_140f07520(Unk_BSFee* pFee, unsigned* pPrice)
{
    if (m_30 == 0)
        return;
    int nLevel = FUN_140f01140();
    int nEvent = FUN_140f07960();
    bool bSale = FUN_1401c0d90()->FUN_140476cf0(nEvent, nLevel) == 0;
    if (!pFee)
    {
        CStringW strDefault = GetStringCommonByKey(CStringW(L"s_beauty_fee_default"));
        m_30->Invoke("setFee", CStringW(strDefault), CStringW(strDefault), bSale, false);
        return;
    }
    unsigned __int64 nPrice = *pPrice;
    unsigned nSale = FUN_1401c0d90()->FUN_140476c70(nEvent, (unsigned)nPrice, nLevel);
    bool bDiscount = nPrice != nSale;
    if (bDiscount)
    {
        unsigned __int64 nSale64 = nSale;
        CStringW strSale = FUN_14134a220(pFee, &nSale64);
        m_30->Invoke("setFee", FUN_1409404f0(nPrice), CStringW(strSale), bSale, bDiscount);
    }
    else
    {
        CStringW strPrice = FUN_14134a220(pFee, &nPrice);
        m_30->Invoke("setFee", CStringW(strPrice), FUN_1409eb450(nSale), bSale, bDiscount);
    }
}

// @0x140f07960
int UIBeautyShopStyleDialog::FUN_140f07960()
{
    return m_1b8.m_18;
}

// @0x140f07980
int UIBeautyShopStyleDialog::FUN_140f07980()
{
    return m_1b8.m_1c;
}

// @0x140f079a0
void UIBeautyShopStyleDialog::FUN_140f079a0()
{
    if (m_198 == 0)
        return;
    m_198->FUN_140cd2530(6);
}

// @0x140f07a00
void UIBeautyShopStyleDialog::FUN_140f07a00()
{
    if (m_198 == 0)
        return;
    m_198->FUN_140cd24a0(6);
}

// Preview a saved style on the character.
// @0x140f07a60
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIBeautyShopStyleDialog::FUN_140f07a60(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || spItem->FUN_140527840() == 0)
        return 0;
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    spItem->FUN_140526b30(FUN_14123c580(pPc));
    if (!m_198->FUN_140cd1c90(spItem.get()))
    {
        if (reinterpret_cast<Unk_BSItemData*>(spItem->FUN_140527840())->FUN_14053c940(FUN_141658e60(pPc)) == 0)
            FUN_140d74390(GetStringCommonByKey(CStringW(L"s_beauty_msg_error_save_style_disable_gender")), 0, FUN_140b240b0());
        return 0;
    }
    m_198->FUN_140cd2660(spItem->FUN_1405276c0());
    return 1;
}

// @0x140f07cc0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopStyleDialog::FUN_140f07cc0()
{
    if (m_30.get() && !(m_items == 0))
    {
        Scaleform::GFx::Value& root = m_30->FUN_1422bb870();
        int bChanged = m_198->FUN_140cd2c20();
        FUN_140cff950(root, CString("m_save"), bChanged);
        FUN_140cff950(root, CString("m_reset"), bChanged);
        unsigned nFee = 0;
        Unk_BSFee* pFee = FUN_140f08190(&nFee);
        if (bChanged == 0)
        {
            unsigned nZero = 0;
            FUN_140f07520(0, &nZero);
        }
        else
            FUN_140f07520(pFee, &nFee);
    }
}

// Fill the slot list ("buildItems").
// @0x140f07e20
// MS2-FUNCTIONAL: temporaries differ
void UIBeautyShopStyleDialog::FUN_140f07e20()
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    ASDataProvider arr(2);
    unsigned nFee = FUN_140f08160();
    unsigned nCount = (unsigned)m_298.size();
    unsigned nMax = FUN_140f011b0();
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
                    MS2Ptr<CItemData> spData = FUN_14053f870(spItem->FUN_1405276c0());
                    if (spData.get())
                    {
                        int nGender = FUN_141658e60(pPc);
                        FUN_140f096f0(obj, MS2Ptr<CItemData>(spData), spItem->FUN_140526b50(), nFee, nGender);
                    }
                }
            }
            else
                FUN_140f09810(obj, true);
        }
        else
            FUN_140f09810(obj, false);
        arr.FUN_1422bc050(Scaleform::GFx::Value(obj.FUN_1422bb870()));
    }
    m_30->Invoke("buildItems", Scaleform::GFx::Value(arr.FUN_1422bb870()), -1L);
    FUN_140f092e0(m_290 < nMax);
}

// @0x140f08160
int UIBeautyShopStyleDialog::FUN_140f08160()
{
    return m_1b8.FUN_1406e3dc0()->FUN_1406dc4f0();
}

// The fee row; *pPrice: the fee when a change is billable.
// @0x140f08190
Unk_BSFee* UIBeautyShopStyleDialog::FUN_140f08190(unsigned* pPrice)
{
    Unk_BSFee* pFee = m_1b8.FUN_1406e3dc0();
    *pPrice = 0;
    if (m_198 == 0)
        return pFee;
    if (m_26c == 4)
    {
        *pPrice = pFee->FUN_1406dc4f0();
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
    int nSlot = FUN_140f01070(FUN_140f07980());
    m_198->FUN_140cd22f0(nSlot);
    if (Unk_BSField* pField = FUN_1403ed2d0()->FUN_141bd3620())
        pField->vfunc_149();
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
    return 1;
}

// "OnClickClose": ask when the preview changed.
// @0x140f082d0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopStyleDialog::FUN_140f082d0()
{
    if (!(m_198 == 0))
    {
        if (m_26c != 2 && m_198->FUN_140cd2c20())
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommon(0x271), 1);
            spBox->FUN_141a01800(2);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f05850));
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
            return;
        }
        FUN_140f08220();
    }
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
// MS2-FUNCTIONAL: string temporaries differ
int UIBeautyShopStyleDialog::FUN_140f084e0(AScript& out, unsigned* pPrice)
{
    if (m_198 == 0)
        return 0;
    if (m_26c != 4)
        return 0;
    *pPrice = 0;
    Unk_BSFee* pFee = FUN_140f08190(pPrice);
    int bChanged = m_198->FUN_140cd2a00();
    if (!bChanged)
        *pPrice = 0;
    ASArray arr(2);
    CStringW strRow = GetStringCommonByKey(CStringW(L"s_bill_list_row"));
    ASObj& outObj = static_cast<ASObj&>(out);
    outObj.FUN_1409c0dc0("category", "$s_beauty_saved_hair_style");
    ASObj row(2);
    CString strKey(bChanged ? "$s_beauty_change_style" : "$s_beauty_none");
    row.FUN_1407cbb20("detail", FUN_1401e8510(strRow, FUN_14025e7a0()->FUN_1422b0570(strKey)));
    CStringW strPrice;
    if (bChanged)
    {
        unsigned __int64 nPrice = *pPrice;
        strPrice = FUN_14134a220(pFee, &nPrice);
    }
    else
        strPrice = GetStringCommonByKey(CStringW(L"s_beauty_fee_default"));
    row.FUN_1407cbb20("strPrice", strPrice);
    arr.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
    outObj.FUN_1409adbe0("list", Scaleform::GFx::Value(arr.FUN_1422bb870()));
    return 1;
}

// @0x140f08950
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopStyleDialog::FUN_140f08950(int bPreview)
{
    if (m_30.get() && m_264 != bPreview)
    {
        FUN_140f08aa0(bPreview);
        m_264 = FUN_1409c1720(m_30->Invoke("forceChangeCheckPreviewWithCap", bPreview)) != 0;
    }
}

// @0x140f08a30
void UIBeautyShopStyleDialog::FUN_140f08a30(int bPreview)
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
// MS2-FUNCTIONAL: temporaries differ
int UIBeautyShopStyleDialog::FUN_140f08be0()
{
    if (m_198 == 0)
        return 0;
    Unk_14102fe10<Unk_140bfc2e0> spList(m_items);
    if (spList == 0)
        return 0;
    if (m_items->FUN_1422dccd0() == -1)
        return 0;
    MS2Ptr<CItem> spItem = FUN_140f09020(spList->FUN_1422dccd0());
    if (spItem == 0)
        return 0;
    FUN_140f08950(0);
    int nEvent = FUN_140f07960();
    unsigned nFee = 0;
    Unk_BSFee* pFee = FUN_140f08190(&nFee);
    int nLevel = FUN_140f01140();
    unsigned __int64 nPrice = FUN_1401c0d90()->FUN_140476c70(nEvent, nFee, nLevel);
    if (!FUN_14134a1d0(pFee, &nPrice))
    {
        FUN_14134a2e0(pFee);
        return 0;
    }
    m_198->FUN_140cd22f0(FUN_140f01070(FUN_140f07980()));
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.vfunc_o10_1(0x15);
    packet.vfunc_o10_4(spItem->FUN_140526a50());
    packet.vfunc_o10_1((unsigned char)spItem->FUN_140526b50());
    FUN_140710590(packet);
    FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    m_2b0 = 1;
    return 1;
}

// @0x140f08f20
void UIBeautyShopStyleDialog::FUN_140f08f20(unsigned n)
{
    unsigned nMax = FUN_140f011b0();
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
        int nSlot = FUN_140f01070(FUN_140f07980());
        m_198->FUN_140cd22f0(nSlot);
    }
    FUN_140f08ba0();
    m_items->FUN_1422dcca0(-1);
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
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
MS2Ptr<CItem> UIBeautyShopStyleDialog::FUN_140f090d0(int nSlot)
{
    if (!m_298.empty())
    {
        for (int i = 0; i < (int)m_298.size(); i++)
        {
            MS2Ptr<CItem> spItem(m_298.at(i));
            if (!(spItem == 0) && spItem->FUN_140526b50() == nSlot)
                return std::move(spItem);
        }
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f09230
bool UIBeautyShopStyleDialog::FUN_140f09230()
{
    return FUN_140f01470(m_290);
}

// @0x140f09260
int UIBeautyShopStyleDialog::FUN_140f09260()
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
void UIBeautyShopStyleDialog::FUN_140f092e0(int b)
{
    if (m_30 == 0)
        return;
    FUN_140cff840(m_30->FUN_1422bb870(), CString("m_extendSlot"), b);
}

// The "my codi" tab changed: drop the page when its outfit expired.
// @0x140f09380
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIBeautyShopStyleDialog::FUN_140f09380(NotifyObject* pNotify)
{
    if (!(m_30 == 0) && !(m_198 == 0))
    {
        NotifyChangeActiveMyCodiTab* pTab = dynamic_cast<NotifyChangeActiveMyCodiTab*>(pNotify);
        if (pTab == 0 || pTab->m_bActive)
            FUN_140f09560();
        else
            FUN_140d74390(GetStringCommonByKey(CStringW(L"s_beauty_msg_by_expired_codi")), 0,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopStyleDialog::FUN_140f09520));
    }
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
    int nKind = FUN_140f07980();
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
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIBeautyShopStyleDialog::FUN_140f09630()
{
    Unk_BSPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    if (FUN_140f07980() != 1)
        return false;
    m_268 = FUN_14165f460(pPc)->FUN_1412706f0(0);
    return FUN_1416561a0(pPc)->FUN_1411e1a50(6, 0).get() != 0;
}

// A saved style slot object.
// @0x140f096f0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool FUN_140f096f0(ASObj& obj, MS2Ptr<CItemData> spData, int nIndex, unsigned nMerat, int nGender)
{
    FUN_140f324f0(obj, MS2Ptr<CItemData>(spData), 0);
    obj.FUN_1407cb9c0("idx", nIndex);
    obj.FUN_1409c0d20("merat", nMerat);
    obj.FUN_1407cbbe0("enableDelete", true);
    obj.FUN_1407cbbe0("disable", static_cast<Unk_BSItemData*>(spData.operator->())->FUN_14053c940(nGender) == 0);
    obj.FUN_1407cbbe0("editable", false);
    return true;
}

// An empty (bEnabled) or locked slot object.
// @0x140f09810
bool FUN_140f09810(ASObj& obj, bool bEnabled)
{
    obj.FUN_1407cb9c0("idx", -1);
    obj.FUN_1407cb9c0("merat", 0);
    if (!bEnabled)
        obj.FUN_1407cbbe0("enabled", bEnabled);
    return true;
}

// ---- template / helper zone ----

// The bill dialog when it is open.
// @0x140f0a350
UIBillDialog* FUN_140f0a350(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIBillDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140f0a3f0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, Scaleform::GFx::Value a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcc70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f0a510
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, Scaleform::GFx::Value a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f0a610
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, const wchar_t* a1, bool a2, bool a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f0a6f0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, CStringW a2, bool a3, bool a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    FUN_1422bcce0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f0a830
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, long a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// A message box with a result callback and an int argument.
// @0x140f0a930
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
MS2Ptr<CMsgBoxData> FUN_140f0a930(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb, int nArg)
{
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(nType));
    spBox->SetMsg(strText);
    spBox->FUN_141a027c0(cb);
    spBox->FUN_140533ff0(nArg);
    FUN_14151f150(MS2Ptr<CMsgBoxData>(spBox));
    return std::move(spBox);
}

// The style slot list holder (Unk_14102fe10, uiattendgiftdialog.h): the COMDATs of this unit.
// @0x140f0afb0
template <> Unk_14102fe10<Unk_140bfc2e0>::Unk_14102fe10(const Unk_14102fe10& o) : m_p(o.m_p)
{
    AddRef();
}

// @0x140f0b310
template <> Unk_14102fe10<Unk_140bfc2e0>& Unk_14102fe10<Unk_140bfc2e0>::operator=(int)
{
    Release();
    return *this;
}

// @0x140f0b480
template <> bool Unk_14102fe10<Unk_140bfc2e0>::operator==(Unk_140bfc2e0* p) const
{
    return m_p == p;
}

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
MS2_REPLACE_METHOD(0x140f07980, UIBeautyShopStyleDialog, FUN_140f07980, 17, 0x0B11C3C6);
MS2_REPLACE_METHOD(0x140f079a0, UIBeautyShopStyleDialog, FUN_140f079a0, 76, 0x20CC042B);
MS2_REPLACE_METHOD(0x140f07a00, UIBeautyShopStyleDialog, FUN_140f07a00, 76, 0xC3E666C2);
MS2_REPLACE_METHOD(0x140f07a60, UIBeautyShopStyleDialog, FUN_140f07a60, 597, 0xAB424548);
MS2_REPLACE_METHOD(0x140f07cc0, UIBeautyShopStyleDialog, FUN_140f07cc0, 343, 0xEBC6CC4C);
MS2_REPLACE_METHOD(0x140f07e20, UIBeautyShopStyleDialog, FUN_140f07e20, 825, 0xE90B7407);
MS2_REPLACE_METHOD(0x140f08160, UIBeautyShopStyleDialog, FUN_140f08160, 41, 0xBAEA161B);
MS2_REPLACE_METHOD(0x140f08190, UIBeautyShopStyleDialog, FUN_140f08190, 132, 0xF13C26B8);
MS2_REPLACE_METHOD(0x140f08220, UIBeautyShopStyleDialog, FUN_140f08220, 166, 0x583C8BBF);
MS2_REPLACE_METHOD(0x140f08470, UIBeautyShopStyleDialog, OnClickReset, 92, 0x47771337);
MS2_REPLACE_METHOD(0x140f084e0, UIBeautyShopStyleDialog, FUN_140f084e0, 1119, 0xB28E6AA2);
MS2_REPLACE_METHOD(0x140f08950, UIBeautyShopStyleDialog, FUN_140f08950, 216, 0x7B531712);
MS2_REPLACE_METHOD(0x140f08a30, UIBeautyShopStyleDialog, FUN_140f08a30, 92, 0x844DDB0F);
MS2_REPLACE_METHOD(0x140f08aa0, UIBeautyShopStyleDialog, FUN_140f08aa0, 47, 0x1F4F7493);
MS2_REPLACE_METHOD(0x140f08ae0, UIBeautyShopStyleDialog, FUN_140f08ae0, 173, 0x3696E501);
MS2_REPLACE_METHOD(0x140f08ba0, UIBeautyShopStyleDialog, FUN_140f08ba0, 49, 0xE8A3DCFD);
MS2_REPLACE_METHOD(0x140f08be0, UIBeautyShopStyleDialog, FUN_140f08be0, 818, 0x4A4AF65D);
MS2_REPLACE_METHOD(0x140f08f20, UIBeautyShopStyleDialog, FUN_140f08f20, 70, 0x8AF71560);
MS2_REPLACE_METHOD(0x140f08f70, UIBeautyShopStyleDialog, FUN_140f08f70, 162, 0x67553572);
MS2_REPLACE_METHOD(0x140f09020, UIBeautyShopStyleDialog, FUN_140f09020, 156, 0x8D825A5E);
MS2_REPLACE_METHOD(0x140f090d0, UIBeautyShopStyleDialog, FUN_140f090d0, 343, 0x369D3F05);
MS2_REPLACE_METHOD(0x140f09230, UIBeautyShopStyleDialog, FUN_140f09230, 30, 0xC252B8F0);
MS2_REPLACE_METHOD(0x140f09260, UIBeautyShopStyleDialog, FUN_140f09260, 66, 0x4E988A09);
MS2_REPLACE_METHOD(0x140f092b0, UIBeautyShopStyleDialog, FUN_140f092b0, 36, 0xB6F8D97A);
MS2_REPLACE_METHOD(0x140f092e0, UIBeautyShopStyleDialog, FUN_140f092e0, 142, 0xA00B0550);
MS2_REPLACE_METHOD(0x140f09520, UIBeautyShopStyleDialog, FUN_140f09520, 44, 0x34BE8CED);
MS2_REPLACE_METHOD(0x140f09560, UIBeautyShopStyleDialog, FUN_140f09560, 198, 0x7A0ECB17);
MS2_REPLACE_METHOD(0x140f09630, UIBeautyShopStyleDialog, FUN_140f09630, 172, 0x391CD9C0);
