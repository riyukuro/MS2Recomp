// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The AS item slot components: ASItemSlot and
// ASAdditionalEffectSlot (slot icons with tooltips), the merat market product data objects (ASMeratMarketProductBase and
// its Product / LimitedProduct / HomeProduct kinds), ASScrollPanel, and ASSlot (the slot data object the icons are fed
// with). The range holds four TUs (four header-static groups in .text$di); they are recovered here as one file, with
// each group's statics under its own names.
// MS2-UNIT: ?\asitemslot.cpp
// MS2-RANGE: 0x1409ba1d0-0x1409c4b40 .text$mn
// MS2-RANGE: 0x1400c06c0-0x1400c13a0 .text$di
// MS2-RANGE: 0x142c9daa0-0x142c9e1c0 .text$yd
// MS2-PIN: ??_7ASObj@@6B@ 0x142db7e28
// MS2-GUESS-LOOKALIKES: MS2Ptr<Unk_MeratFilter> / MS2Ptr<Unk_SlotSkillLevel> operator= fold to one exe copy
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSortTypeNamesA@@YAXXZ 0x1400c06c0 ; probe
// MS2-PIN: ??__Es_strDisable@@YAXXZ 0x1400c0780 ; probe
// MS2-PIN: ??__Es_strDisableDrag@@YAXXZ 0x1400c07b0 ; probe
// MS2-PIN: ??__Es_strSortTypeNamesB@@YAXXZ 0x1400c08b0 ; probe
// MS2-PIN: ??__Es_strDropShadowDisable@@YAXXZ 0x1400c0970 ; probe
// MS2-PIN: ??__Es_strGrayColor@@YAXXZ 0x1400c09a0 ; probe
// MS2-PIN: ??__Es_unk1402a9d70B@@YAXXZ 0x1400c09d0 ; prop
// MS2-PIN: ??__Es_strIconPath@@YAXXZ 0x1400c0a50 ; probe
// MS2-PIN: ??__Es_strIndex@@YAXXZ 0x1400c0a80 ; probe
// MS2-PIN: ??__Es_strItemBothEquip@@YAXXZ 0x1400c0ab0 ; probe
// MS2-PIN: ??__Es_strItemCash@@YAXXZ 0x1400c0ae0 ; probe
// MS2-PIN: ??__Es_strItemCategory@@YAXXZ 0x1400c0b10 ; probe
// MS2-PIN: ??__Es_strItemColor@@YAXXZ 0x1400c0b40 ; probe
// MS2-PIN: ??__Es_strItemConditionLock@@YAXXZ 0x1400c0b70 ; probe
// MS2-PIN: ??__Es_strItemCount@@YAXXZ 0x1400c0ba0 ; probe
// MS2-PIN: ??__Es_strItemEquip2@@YAXXZ 0x1400c0bd0 ; probe
// MS2-PIN: ??__Es_strItemEquip@@YAXXZ 0x1400c0c00 ; probe
// MS2-PIN: ??__Es_strItemEvent@@YAXXZ 0x1400c0c30 ; probe
// MS2-PIN: ??__Es_strItemGUID@@YAXXZ 0x1400c0c60 ; probe
// MS2-PIN: ??__Es_strItemGrade@@YAXXZ 0x1400c0c90 ; probe
// MS2-PIN: ??__Es_strItemID@@YAXXZ 0x1400c0cc0 ; probe
// MS2-PIN: ??__Es_strItemIconLock@@YAXXZ 0x1400c0cf0 ; probe
// MS2-PIN: ??__Es_strItemIconUnLock@@YAXXZ 0x1400c0d20 ; probe
// MS2-PIN: ??__Es_strItemLock@@YAXXZ 0x1400c0d50 ; probe
// MS2-PIN: ??__Es_strItemName@@YAXXZ 0x1400c0d80 ; probe
// MS2-PIN: ??__Es_strItemNew@@YAXXZ 0x1400c0db0 ; probe
// MS2-PIN: ??__Es_strItemPcBang@@YAXXZ 0x1400c0de0 ; probe
// MS2-PIN: ??__Es_strItemPet@@YAXXZ 0x1400c0e10 ; probe
// MS2-PIN: ??__Es_strItemPetRank@@YAXXZ 0x1400c0e40 ; probe
// MS2-PIN: ??__Es_strItemPetSkin@@YAXXZ 0x1400c0e70 ; probe
// MS2-PIN: ??__Es_strItemPiece@@YAXXZ 0x1400c0ea0 ; probe
// MS2-PIN: ??__Es_strItemResultTag@@YAXXZ 0x1400c0ed0 ; probe
// MS2-PIN: ??__Es_strItemSeal@@YAXXZ 0x1400c0f00 ; probe
// MS2-PIN: ??__Es_strItemSkin@@YAXXZ 0x1400c0f30 ; probe
// MS2-PIN: ??__Es_strItemSummon@@YAXXZ 0x1400c0f60 ; probe
// MS2-PIN: ??__Es_strItemVIP@@YAXXZ 0x1400c0f90 ; probe
// MS2-PIN: ??__Es_strItemWedding@@YAXXZ 0x1400c0fc0 ; probe
// MS2-PIN: ??__Es_strJobCode@@YAXXZ 0x1400c0ff0 ; probe
// MS2-PIN: ??__Es_strLearn@@YAXXZ 0x1400c1020 ; probe
// MS2-PIN: ??__Es_strSkillA@@YAXXZ 0x1400c1050 ; probe
// MS2-PIN: ??__Es_strSkillB@@YAXXZ 0x1400c1080 ; probe
// MS2-PIN: ??__Es_strSkillD@@YAXXZ 0x1400c10b0 ; probe
// MS2-PIN: ??__Es_strSkillmaster@@YAXXZ 0x1400c10e0 ; probe
// MS2-PIN: ??__Es_strSkilltype@@YAXXZ 0x1400c1110 ; probe
// MS2-PIN: ??__Es_strSlotHint@@YAXXZ 0x1400c1140 ; probe
// MS2-PIN: ??__Es_strSortValue@@YAXXZ 0x1400c1170 ; probe
// MS2-PIN: ??__Es_strStunA@@YAXXZ 0x1400c11a0 ; probe
// MS2-PIN: ??__Es_strStunB@@YAXXZ 0x1400c11d0 ; probe
// MS2-PIN: ??__Es_strStunD@@YAXXZ 0x1400c1200 ; probe
// MS2-PIN: ??__Es_strSortTypeNamesD@@YAXXZ 0x1400c1230 ; probe
// MS2-PIN: ??__Es_strTabIndex@@YAXXZ 0x1400c12f0 ; probe
// MS2-PIN: ??__Es_strUgctag@@YAXXZ 0x1400c1320 ; probe
// MS2-PIN: ??__Es_unk1402a9d70D@@YAXXZ 0x1400c1350 ; prop
// MS2-PIN: ??$?8PEAVASAdditionalEffectSlot@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVASAdditionalEffectSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x1409bb2d0 ; prop
// MS2-PIN: ??$?8PEAVASItemSlot@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVASItemSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x1409bb320 ; prop
// MS2-PIN: ??_GASAdditionalEffectSlot@@UEAAPEAXI@Z 0x1409bb8e0 ; unique
// MS2-PIN: ??_GASItemSlot@@UEAAPEAXI@Z 0x1409bb920 ; unique
// MS2-PIN: ??_GAScript@@UEAAPEAXI@Z 0x1409bb9a0 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVASAdditionalEffectSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1409bb9f0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVASItemSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1409bba50 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVASAdditionalEffectSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1409bbab0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVASItemSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1409bbae0 ; unique
// MS2-PIN: ??$Call@VASAdditionalEffectSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVASAdditionalEffectSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVASAdditionalEffectSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1409bbb10 ; prop
// MS2-PIN: ??$Call@VASItemSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVASItemSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVASItemSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1409bbb40 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVASAdditionalEffectSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1409bbb70 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVASItemSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1409bbbd0 ; unique
// MS2-PIN: ??$StringFormat@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@HV12@V12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBV01@1AEBH11@Z 0x1409c0920 ; unique
// MS2-PIN: ??1ASMeratMarketHomeProduct@@UEAA@XZ 0x1409c1370 ; prop
// MS2-PIN: ??1ASMeratMarketProduct@@UEAA@XZ 0x1409c1390 ; prop
// MS2-PIN: ?IsNull@?$MS2Ptr@VUnk_MeratEquipEntry@@@@QEBA_NXZ 0x1409c14d0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUnk_MeratEquipEntry@@@@QEBAPEAVUnk_MeratEquipEntry@@XZ 0x1409c1530 ; unique
// MS2-PIN: ??_GASMeratMarketHomeProduct@@UEAAPEAXI@Z 0x1409c1540 ; prop
// MS2-PIN: ??_GASMeratMarketLimitedProduct@@UEAAPEAXI@Z 0x1409c1580 ; prop
// MS2-PIN: ??_GASMeratMarketProduct@@UEAAPEAXI@Z 0x1409c15c0 ; prop
// MS2-PIN: ??_GASMeratMarketProductBase@@UEAAPEAXI@Z 0x1409c1600 ; prop
// MS2-PIN: ??_GASScrollPanel@@UEAAPEAXI@Z 0x1409c1be0 ; unique
// MS2-PIN: ?FUN_1409c4b00@Unk_SlotInventoryDialog@@QEAAHXZ 0x1409c4b00 ; unique
// MS2-PIN: ??__Fs_strSortTypeNamesA@@YAXXZ 0x142c9daa0 ; probe
// MS2-PIN: ??__Fs_strDisable@@YAXXZ 0x142c9dad0 ; probe
// MS2-PIN: ??__Fs_strDisableDrag@@YAXXZ 0x142c9daf0 ; probe
// MS2-PIN: ??__Fs_strSortTypeNamesB@@YAXXZ 0x142c9db40 ; probe
// MS2-PIN: ??__Fs_strDropShadowDisable@@YAXXZ 0x142c9db70 ; probe
// MS2-PIN: ??__Fs_strGrayColor@@YAXXZ 0x142c9db90 ; probe
// MS2-PIN: ??__Fs_strIconPath@@YAXXZ 0x142c9dbf0 ; probe
// MS2-PIN: ??__Fs_strIndex@@YAXXZ 0x142c9dc10 ; probe
// MS2-PIN: ??__Fs_strItemBothEquip@@YAXXZ 0x142c9dc30 ; probe
// MS2-PIN: ??__Fs_strItemCash@@YAXXZ 0x142c9dc50 ; probe
// MS2-PIN: ??__Fs_strItemCategory@@YAXXZ 0x142c9dc70 ; probe
// MS2-PIN: ??__Fs_strItemColor@@YAXXZ 0x142c9dc90 ; probe
// MS2-PIN: ??__Fs_strItemConditionLock@@YAXXZ 0x142c9dcb0 ; probe
// MS2-PIN: ??__Fs_strItemCount@@YAXXZ 0x142c9dcd0 ; probe
// MS2-PIN: ??__Fs_strItemEquip2@@YAXXZ 0x142c9dcf0 ; probe
// MS2-PIN: ??__Fs_strItemEquip@@YAXXZ 0x142c9dd10 ; probe
// MS2-PIN: ??__Fs_strItemEvent@@YAXXZ 0x142c9dd30 ; probe
// MS2-PIN: ??__Fs_strItemGUID@@YAXXZ 0x142c9dd50 ; probe
// MS2-PIN: ??__Fs_strItemGrade@@YAXXZ 0x142c9dd70 ; probe
// MS2-PIN: ??__Fs_strItemID@@YAXXZ 0x142c9dd90 ; probe
// MS2-PIN: ??__Fs_strItemIconLock@@YAXXZ 0x142c9ddb0 ; probe
// MS2-PIN: ??__Fs_strItemIconUnLock@@YAXXZ 0x142c9ddd0 ; probe
// MS2-PIN: ??__Fs_strItemLock@@YAXXZ 0x142c9ddf0 ; probe
// MS2-PIN: ??__Fs_strItemName@@YAXXZ 0x142c9de10 ; probe
// MS2-PIN: ??__Fs_strItemNew@@YAXXZ 0x142c9de30 ; probe
// MS2-PIN: ??__Fs_strItemPcBang@@YAXXZ 0x142c9de50 ; probe
// MS2-PIN: ??__Fs_strItemPet@@YAXXZ 0x142c9de70 ; probe
// MS2-PIN: ??__Fs_strItemPetRank@@YAXXZ 0x142c9de90 ; probe
// MS2-PIN: ??__Fs_strItemPetSkin@@YAXXZ 0x142c9deb0 ; probe
// MS2-PIN: ??__Fs_strItemPiece@@YAXXZ 0x142c9ded0 ; probe
// MS2-PIN: ??__Fs_strItemResultTag@@YAXXZ 0x142c9def0 ; probe
// MS2-PIN: ??__Fs_strItemSeal@@YAXXZ 0x142c9df10 ; probe
// MS2-PIN: ??__Fs_strItemSkin@@YAXXZ 0x142c9df30 ; probe
// MS2-PIN: ??__Fs_strItemSummon@@YAXXZ 0x142c9df50 ; probe
// MS2-PIN: ??__Fs_strItemVIP@@YAXXZ 0x142c9df70 ; probe
// MS2-PIN: ??__Fs_strItemWedding@@YAXXZ 0x142c9df90 ; probe
// MS2-PIN: ??__Fs_strJobCode@@YAXXZ 0x142c9dfb0 ; probe
// MS2-PIN: ??__Fs_strLearn@@YAXXZ 0x142c9dfd0 ; probe
// MS2-PIN: ??__Fs_strSkillA@@YAXXZ 0x142c9dff0 ; probe
// MS2-PIN: ??__Fs_strSkillB@@YAXXZ 0x142c9e010 ; probe
// MS2-PIN: ??__Fs_strSkillD@@YAXXZ 0x142c9e030 ; probe
// MS2-PIN: ??__Fs_strSkillmaster@@YAXXZ 0x142c9e050 ; probe
// MS2-PIN: ??__Fs_strSkilltype@@YAXXZ 0x142c9e070 ; probe
// MS2-PIN: ??__Fs_strSlotHint@@YAXXZ 0x142c9e090 ; probe
// MS2-PIN: ??__Fs_strSortValue@@YAXXZ 0x142c9e0b0 ; probe
// MS2-PIN: ??__Fs_strStunA@@YAXXZ 0x142c9e0d0 ; probe
// MS2-PIN: ??__Fs_strStunB@@YAXXZ 0x142c9e0f0 ; probe
// MS2-PIN: ??__Fs_strStunD@@YAXXZ 0x142c9e110 ; probe
// MS2-PIN: ??__Fs_strSortTypeNamesD@@YAXXZ 0x142c9e130 ; probe
// MS2-PIN: ??__Fs_strTabIndex@@YAXXZ 0x142c9e160 ; probe
// MS2-PIN: ??__Fs_strUgctag@@YAXXZ 0x142c9e180 ; probe
// MS2-PINS-END tplpin
// fx14: byte-identical DelegateImpl copy ctors, bound through the clone (vfunc_1) of each exe vftable (0x142db7ff8 ASItemSlot, 0x142db8020 ASAdditionalEffectSlot)
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVASItemSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x1409bb6d0 ; vftable
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVASAdditionalEffectSlot@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x1409bb630 ; vftable
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_AdditionalEffect@@@@AEAAXPEAX@Z 0x1409c1a30 ; merge-bind
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\asitemslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <new>
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/asmeratmarketproduct.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics, in the exe's initializer order (.text$di) ----
// The ASItemSlot TU.
static CString s_strSortTypeNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillA = "skill";
static CString s_strStunA = "stun";
// The merat market TU.
static CString s_strChartSortNamesB[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillB = "skill";
static CString s_strStunB = "stun";
static Unk_1402a9d70 s_unk1402a9d70B(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputB;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";
// The ASSlot TU: the AS member names of the slot data, then the common header statics.
static CString s_strDisable = "disable";
static CString s_strDisableDrag = "disableDrag";
static CString s_strDropShadowDisable = "dropShadowDisable";
static CString s_strGrayColor = "grayColor";
static CString s_strIconPath = "iconPath";
static CString s_strIndex = "index";
static CString s_strItemBothEquip = "itemBothEquip";
static CString s_strItemCash = "itemCash";
static CString s_strItemCategory = "itemCategory";
static CString s_strItemColor = "itemColor";
static CString s_strItemCount = "itemCount";
static CString s_strItemEquip2 = "itemEquip2";
static CString s_strItemEquip = "itemEquip";
static CString s_strItemEvent = "itemEvent";
static CString s_strItemGrade = "itemGrade";
static CString s_strItemGUID = "itemGUID";
static CString s_strItemIconLock = "itemIconLock";
static CString s_strItemPiece = "itemPiece";
static CString s_strItemIconUnLock = "itemIconUnLock";
static CString s_strItemID = "itemID";
static CString s_strItemLock = "itemLock";
static CString s_strItemName = "itemName";
static CString s_strItemNew = "itemNew";
static CString s_strItemPcBang = "itemPcBang";
static CString s_strItemPet = "itemPet";
static CString s_strItemResultTag = "itemResultTag";
static CString s_strItemSeal = "itemSeal";
static CString s_strItemSkin = "itemSkin";
static CString s_strItemSummon = "itemSummon";
static CString s_strItemVIP = "itemVIP";
static CString s_strItemWedding = "itemWedding";
static CString s_strItemConditionLock = "itemConditionLock";
static CString s_strItemPetRank = "itemPetRank";
static CString s_strItemPetSkin = "itemPetSkin";
static CString s_strLearn = "learn";
static CString s_strSkillmaster = "skillmaster";
static CString s_strSkilltype = "skilltype";
static CString s_strSlotHint = "slotHint";
static CString s_strUgctag = "ugctag";
static CString s_strSortTypeNamesD[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillD = "skill";
static CString s_strStunD = "stun";
static Unk_1402a9d70 s_unk1402a9d70D(17, 0.75f, 0.25f, 2.25f, 10);

// ---- externals ----
typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> Unk_AsDelegate;

void FUN_1422c63f0(Scaleform::GFx::Value& value, int nGroup);   // unbind
void FUN_1422c6380(Scaleform::GFx::Value& value, int nGroup);   // bind
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
void FUN_1422bcc70(Scaleform::GFx::Value* pDst, Scaleform::GFx::Value v);                                // argument = value
void* FUN_1403ed2d0();
void* FUN_141bd0cc0(void*);                                     // the local player (tooltip owner)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                   // the item table row
CStringW FUN_14016a730(const char* sz, int nCodePage);          // multibyte -> wide
CStringW FUN_14028de60(int nStringId);
__int64 FUN_140869440();                                        // server time
unsigned short FUN_140626f20(unsigned nItemId);                 // fixed enchant level of an item
CString FUN_14021c050(int nTag);                                // ugc tag name
CStringW FUN_141b71910(__int64 nUid);                           // item uid text
CStringW FUN_1409e5320(const int& nSeason);                     // season number text

// An AS function object calling back into C++ (ctor 0x1422c8430, dtor 0x1422c85b0; uiquesteventlistener.cpp).
class ASFunction : public AScript
{
public:
    ASFunction(const Unk_AsDelegate& cb, __int64 nUser, int nMovieId);   // the user value is 64-bit (uiquesteventlistener.cpp declares it int)
    virtual ~ASFunction();
private:
    void* m_40;
};

// The reward record ASItemSlot::FUN_1409ba630 reads (slots 0-2: item id, rarity, count).
class Unk_ItemSlotSource
{
public:
    virtual int vfunc_0() const;
    virtual int vfunc_1() const;
    virtual int vfunc_2() const;
};

// The hotkey state the click preview checks (FUN_14025e7c0).
class Unk_SlotKeyState
{
public:
    bool FUN_14116dcb0(int nKey, int a1, int a2);
};
Unk_SlotKeyState* FUN_14025e7c0();

// The item preview window the click preview opens (TSingleton instance 0x143ab3fc0).
class Unk_ItemPreview
{
public:
    int FUN_140d40670();                                        // can preview
    void FUN_140d40120(MS2Ptr<CItem> spItem, int n);            // preview the item
};
extern Unk_ItemPreview* DAT_143ab3fc0;
Unk_ItemPreview* FUN_1409bb9e0();

// The additional effect (buff) record and its table.
class Unk_AdditionalEffect : public CPtred
{
public:
    CString FUN_1401756c0();                                    // copy of the icon path
};
class Unk_SlotSkillData;
class Unk_SlotTables                                            // the client table set (FUN_1401958b0)
{
public:
    MS2Ptr<Unk_AdditionalEffect> FUN_140aafef0(int nId, unsigned short nLevel);
    MS2Ptr<Unk_SlotSkillData> FUN_1407ee1d0(int nSkillId);
};
Unk_SlotTables* FUN_1401958b0();

// ---- ASItemSlot TU ----

class ASAdditionalEffectSlot : public ASUIComponent
{
public:
    ASAdditionalEffectSlot(CString strName, int nMovieId);
    ASAdditionalEffectSlot(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASAdditionalEffectSlot();                          // 0
    virtual void vfunc_3(int nVisible);                         // 3 0x1422c7260 (ASUIComponent's)
    virtual void vfunc_4(bool b);                               // 4 0x1422c7230
    virtual void vfunc_16();                                    // 16-24 0x1422c7ec0..0x1422c80c0
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    virtual void vfunc_25(Scaleform::GFx::Value** ppOut);       // 25 the effect tooltip
    void FUN_1409badd0();                                       // push the slot data
    void FUN_1409baf10(int nId, unsigned short nLevel);         // set the effect and refresh
    void FUN_1409bb060(Unk_AsDelegate callback, __int64 nUser);     // setTooltipFunction
    void FUN_1409bb100(const Scaleform::GFx::FunctionHandler::Params& params);   // the tooltip callback
private:
    int m_nId;                                                  // +0x88
    unsigned short m_nLevel;                                    // +0x8c
};
MS2_CHECK_SIZE(ASAdditionalEffectSlot, 0x90);

// The AScript::Invoke instances with an AS object argument by value (the callee destroys it).
// @0x1409bb370
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, ASFunction a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1.FUN_1422bb890());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1409bb460
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, ASSlot a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1.FUN_1422bb890());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1409bb7b0 (the implicit copy of an AS object, first emitted here)
AScript::AScript(const AScript& o)
    : CPtred(o), m_nMovieId(o.m_nMovieId), m_value(o.m_value)
{
}

// @0x1409ba1d0
ASItemSlot::ASItemSlot(CString strName, int nUnused)
    : ASUIComponent(strName, 2)
{
    m_itemId = 0;
    m_rarity = 0;
    m_nCount = 0;
    m_bLocked = false;
    FUN_1409ba980(Unk_AsDelegate(this, &ASItemSlot::FUN_1409baa20), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409ba310
ASItemSlot::ASItemSlot(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
    m_itemId = 0;
    m_rarity = 0;
    m_nCount = 0;
    m_bLocked = false;
    m_bPreview = false;
    FUN_1409ba980(Unk_AsDelegate(this, &ASItemSlot::FUN_1409baa20), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409ba410
ASItemSlot::~ASItemSlot()
{
    FUN_1422c63f0(FUN_1422bb890(), 2);
}

// @0x1409ba460
void ASItemSlot::FUN_1409ba460()
{
    ASSlot slot(2);
    if (slot.FUN_1409c4510(m_itemId, m_rarity, m_nCount) != 0)
    {
        if (m_bLocked)
            slot.FUN_1409c1e80(1);
        Invoke("setSlotData", slot);
    }
    else if (m_itemId == 0)
    {
        slot.FUN_1409c23a0(m_itemId);
        Invoke("setSlotData", slot);
    }
}

// @0x1409ba5d0
void ASItemSlot::FUN_1409ba5d0(int nItemId, int nRarity, int nCount)
{
    m_itemId = nItemId;
    m_rarity = nRarity;
    m_nCount = nCount;
    FUN_1409ba460();
}
MS2_REPLACE_METHOD(0x1409BA5D0, ASItemSlot, FUN_1409ba5d0, 83, 0x4AF4ED20);

// @0x1409ba630
void ASItemSlot::FUN_1409ba630(const Unk_ItemSlotSource& item)
{
    FUN_1409ba5d0(item.vfunc_0(), item.vfunc_1(), item.vfunc_2());
}

// @0x1409ba6d0
void ASItemSlot::FUN_1409ba6d0()
{
    MS2Ptr<CItemData> spData = FUN_14053f870(m_itemId);
    if (spData == 0)
        return;
    FUN_1422c2cb0(Unk_AsDelegate(this, &ASItemSlot::FUN_1409baa60));
    FUN_1422c2c30(Unk_AsDelegate(this, &ASItemSlot::FUN_1409baa60), 0);
    m_bPreview = true;
}

// @0x1409ba800
void ASItemSlot::vfunc_25(Scaleform::GFx::Value** ppOut)
{
    if (m_itemId == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(m_itemId, m_rarity, 0) != 0)
    {
        ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 0x20, 2);
        if (tip.FUN_1409e0d40(spItem.get()) != 0)
        {
            if (m_bPreview)
                tip.FUN_1409db7b0(spItem);
            **ppOut = tip.FUN_1422bb870();
        }
    }
}

// @0x1409ba980
void ASItemSlot::FUN_1409ba980(Unk_AsDelegate callback, __int64 nUser)
{
    Invoke("setTooltipFunction", ASFunction(callback, nUser, m_nMovieId));
}

// @0x1409baa20
void ASItemSlot::FUN_1409baa20(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_25(reinterpret_cast<Scaleform::GFx::Value**>(const_cast<Scaleform::GFx::FunctionHandler::Params*>(&params)));
}

// @0x1409baa60
void ASItemSlot::FUN_1409baa60(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (!FUN_14025e7c0()->FUN_14116dcb0(0x49406, 0, 0))
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(m_itemId, m_rarity, 0) != 0 && FUN_1409bb9e0()->FUN_140d40670() != 0)
        FUN_1409bb9e0()->FUN_140d40120(spItem, 0);
}

// @0x1409bab90
ASAdditionalEffectSlot::ASAdditionalEffectSlot(CString strName, int nUnused)
    : ASUIComponent(strName, 2)
{
    m_nId = 0;
    m_nLevel = 0;
    FUN_1409bb060(Unk_AsDelegate(this, &ASAdditionalEffectSlot::FUN_1409bb100), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409bacb0
ASAdditionalEffectSlot::ASAdditionalEffectSlot(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
    m_nId = 0;
    m_nLevel = 0;
    FUN_1409bb060(Unk_AsDelegate(this, &ASAdditionalEffectSlot::FUN_1409bb100), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409bad80
ASAdditionalEffectSlot::~ASAdditionalEffectSlot()
{
    FUN_1422c63f0(FUN_1422bb890(), 2);
}

// @0x1409badd0
void ASAdditionalEffectSlot::FUN_1409badd0()
{
    MS2Ptr<Unk_AdditionalEffect> spEffect = FUN_1401958b0()->FUN_140aafef0(m_nId, m_nLevel);
    if (spEffect == 0)
        return;
    ASSlot slot(2);
    if (slot.FUN_1409c48b0(spEffect->FUN_1401756c0()))
        Invoke("setSlotData", slot);
}

// @0x1409baf10
void ASAdditionalEffectSlot::FUN_1409baf10(int nId, unsigned short nLevel)
{
    m_nId = nId;
    m_nLevel = nLevel;
    FUN_1409badd0();
}

// @0x1409baf60
void ASAdditionalEffectSlot::vfunc_25(Scaleform::GFx::Value** ppOut)
{
    MS2Ptr<Unk_AdditionalEffect> spEffect = FUN_1401958b0()->FUN_140aafef0(m_nId, m_nLevel);
    if (spEffect == 0)
        return;
    ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 1, 2);
    if (tip.FUN_1409e2750(spEffect.get(), 5, 0) != 0)
        **ppOut = tip.FUN_1422bb870();
}

// @0x1409bb060
void ASAdditionalEffectSlot::FUN_1409bb060(Unk_AsDelegate callback, __int64 nUser)
{
    Invoke("setTooltipFunction", ASFunction(callback, nUser, m_nMovieId));
}

// @0x1409bb100
void ASAdditionalEffectSlot::FUN_1409bb100(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_25(reinterpret_cast<Scaleform::GFx::Value**>(const_cast<Scaleform::GFx::FunctionHandler::Params*>(&params)));
}

// @0x1409bb9e0 TSingleton<item preview>::GetInstance
Unk_ItemPreview* FUN_1409bb9e0()
{
    return DAT_143ab3fc0;
}


// ---- ASScrollPanel / ASSlot TU ----

class ASScrollPanel : public ASUIComponent
{
public:
    ASScrollPanel(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASScrollPanel();                                   // 0
    virtual void vfunc_3(int nVisible);                         // 3 0x1422c7260 (ASUIComponent's)
    virtual void vfunc_4(bool b);                               // 4 0x1422c7230
    virtual void vfunc_16();                                    // 16-24 0x1422c7ec0..0x1422c80c0
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1409c1ba0(int nHeight);                            // setContentsHeight
};
MS2_CHECK_SIZE(ASScrollPanel, 0x88);

// The local player, as the slot code sees it.
class Unk_SlotSkillBook;
class Unk_SlotSkillLevel : public CPtred
{
public:
    float FUN_140804660();                                      // the cooldown in seconds
};
class Unk_SlotSkillRow : public CPtred
{
public:
    MS2Ptr<Unk_SlotSkillLevel> FUN_1407e90a0(unsigned short nLevel);
private:
    void* m_pad_18[(0x17c - 0x18) / 8];
    int m_pad_178;
public:
    int m_bCooldown;                                            // +0x17c the skill has a cooldown
};
MS2_CHECK_OFFSET(Unk_SlotSkillRow, m_bCooldown, 0x17c);
class Unk_SlotSkillBook
{
public:
    virtual void vfunc_0();
    virtual MS2Ptr<Unk_SlotSkillLevel> vfunc_1(int nSkillId);   // 1 the learned level of a skill
};
class Unk_SlotSkillCooldowns
{
public:
    float FUN_141765fe0(int nSkillId, int n);                   // the cooldown left
};
class Unk_SlotPc
{
public:
    int FUN_1416764d0();                                        // riding
    Unk_SlotSkillCooldowns* FUN_141523bc0();
    int FUN_14152e970(int nId);                                 // the free skill points of nId
};
Unk_SlotPc* FUN_1409613d0(void* pPc);
int FUN_141275a10(CItem* pItem);                                // the usable state of an item (1 locked, 2 disabled, 3 condition)                           // PCBase -> MyPC (NULL for others)
Unk_SlotSkillBook* FUN_1416546d0(Unk_SlotPc* pPc);
MS2Ptr<Unk_SlotSkillRow> FUN_140639210(int nSkillId);            // the skill table row

// The equip set of a PC (FUN_1416561a0).
class CEquipItem;
class Unk_SlotEquipSet
{
public:
    MS2Ptr<CEquipItem> FUN_1411e1780(int nSlot, int nKind);
};
Unk_SlotEquipSet* FUN_1416561a0(void* pPc);
class Unk_SlotMyPc
{
public:
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 nItemUid);        // a worn item by uid
};

// A skill entry (the skill window rows).
class Unk_SlotSkillInfo : public CPtred
{
public:
    int FUN_140637cc0();                                        // skill id
    int FUN_140637e00();                                        // skill tree id
private:
    char m_pad_18[7];
public:
    bool m_bLearned;                                            // +0x1f
};
MS2_CHECK_OFFSET(Unk_SlotSkillInfo, m_bLearned, 0x1f);
// The skill record of the skill table (FUN_1407ee1d0).
class Unk_SlotSkillData : public CPtred
{
public:
    bool FUN_1407e9de0();                                       // passive
private:
    void* m_pad_18[(0x48 - 0x18) / 8];
public:
    CString m_strIcon;                                          // +0x48
};
MS2_CHECK_OFFSET(Unk_SlotSkillData, m_strIcon, 0x48);
bool FUN_140ecf630(MS2Ptr<Unk_SlotSkillInfo> spSkill, int nPoints);   // can upgrade

// The icon source FUN_1409c4860 reads (an icon path at +0xc0).
class Unk_SlotIconSource
{
private:
    void* m_pad_00[0xc0 / 8];
public:
    CString m_strIcon;                                          // +0xc0
};
MS2_CHECK_OFFSET(Unk_SlotIconSource, m_strIcon, 0xc0);

// Item helpers.
class Unk_SlotModelHead                                         // ItemModelHead (itemdata.h)
{
public:
    bool FUN_140547190();                                       // dyeable
};
class Unk_ItemEquipData : public CItemData                      // CItem::FUN_140527840's record (item.cpp)
{
public:
    Unk_SlotModelHead* FUN_14053ec70();                         // the model head (CItemData declares it void)
};
class Unk_UserProxyItemData
{
public:
    unsigned long FUN_140599fd0(int n);                         // the dye colour
};
class Unk_ItemEnchantData
{
public:
    CItemEnchantInfo* FUN_140630d60();                          // the enchant record
    Unk_ItemPlusInfo* FUN_140630d90();                          // the unlimited enchant record
};
class CItemEnchantInfo
{
public:
    int FUN_14058c5f0();                                        // enchant level
    int FUN_14058c8a0();                                        // broken
};
class Unk_ItemPlusInfo
{
public:
    int FUN_1408bbc50();                                        // unlimited enchant level
};
class Unk_SlotSeasonTable
{
public:
    bool FUN_14059eec0(int nItemId);
    int FUN_14059ebb0(int nItemId);
    bool FUN_14059ef70(int nSeason);
    int FUN_14059e6a0(int nCoinShopId);                         // the coin shop is open (merat home products)
    int FUN_14059ed00(int nSeasonId);                           // the season of an item season id
};
Unk_SlotSeasonTable* FUN_14052d230();
class Unk_SlotLapenTable
{
public:
    unsigned short FUN_1405b5780(int nItemId);
};
class Unk_SlotPetRow : public CPtred
{
private:
    char m_pad_18[4];
public:
    bool m_bSummonable;                                         // +0x1c
};
MS2_CHECK_OFFSET(Unk_SlotPetRow, m_bSummonable, 0x1c);
class Unk_SlotPetTable
{
public:
    MS2Ptr<Unk_SlotPetRow> FUN_1407290f0(int nPetId);
};
Unk_SlotPetTable* FUN_14052d210();
class Unk_SlotBreakManager
{
public:
    int FUN_140531aa0(MS2Ptr<CItem> spItem);
};
class Unk_SlotLockManager
{
public:
    int FUN_140613430(MS2Ptr<CItem> spItem);
};
Unk_SlotLockManager* FUN_140535310();
class Unk_SlotQuestManager
{
public:
    int FUN_1416ce6a0(MS2Ptr<CItem> spItem);
};
Unk_SlotQuestManager* FUN_140764020();
class Unk_SlotFeatures
{
public:
    bool FUN_14036d570(int nFeature);
};
Unk_SlotFeatures* FUN_140166410();
class Unk_SlotStrings
{
public:
    CStringW FUN_141811980(int nTable, int nId);
    CStringW FUN_141812f60(int nId);
};
Unk_SlotStrings* FUN_1401a9d70();
class Unk_SlotUidSource
{
public:
    __int64 FUN_140c8b2e0();
};
Unk_SlotUidSource* FUN_140535320();
// The inventory dialog's break/lock mode (UIInventoryDialog +0x1a4).
class Unk_SlotInventoryDialog : public UIDialog
{
public:
    int FUN_1409c4b00() { return m_nMode; }
private:
    void* m_pad_178[(0x1a0 - 0x178) / 8];
    int m_pad_1a0;
public:
    int m_nMode;                                                // +0x1a4
};
MS2_CHECK_OFFSET(Unk_SlotInventoryDialog, m_nMode, 0x1a4);
Unk_SlotInventoryDialog* FUN_1405344f0(int nDialogId);
extern Unk_SlotBreakManager* DAT_143aaf300;
extern Unk_SlotLapenTable* DAT_143aafd98;
Unk_SlotBreakManager* FUN_1409c4b20();
Unk_SlotLapenTable* FUN_1409c4b30();

// @0x1409c1b20
ASScrollPanel::ASScrollPanel(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1409c1b70
ASScrollPanel::~ASScrollPanel()
{
}

// @0x1409c1ba0
void ASScrollPanel::FUN_1409c1ba0(int nHeight)
{
    Invoke("setContentsHeight", nHeight);
}

// @0x1409c1c20
ASSlot::ASSlot(int nType)
    : ASObj(nType)
{
}

// @0x1409c1c60
ASSlot::ASSlot(const Scaleform::GFx::Value& v, int nMovieId)
    : ASObj(v, nMovieId)
{
}

// @0x1409c1cb0
ASSlot::~ASSlot()
{
}

// @0x1409c1ce0
void ASSlot::FUN_1409c1ce0(int n)
{
    FUN_1407cb9c0(s_strItemPet, n);
}

// @0x1409c1d20
void ASSlot::FUN_1409c1d20(int n)
{
    FUN_1407cb9c0(s_strItemCash, n);
}

// @0x1409c1d60
void ASSlot::FUN_1409c1d60(int n)
{
    FUN_1407cb9c0(s_strItemSkin, n);
}

// @0x1409c1da0
void ASSlot::FUN_1409c1da0(bool b)
{
    FUN_1407cb9c0(s_strItemPcBang, b != false);
}

// @0x1409c1e00
void ASSlot::FUN_1409c1e00(int n)
{
    FUN_1407cb9c0(s_strItemVIP, n);
}

// @0x1409c1e40
void ASSlot::FUN_1409c1e40(int n)
{
    FUN_1407cb9c0(s_strItemWedding, n);
}

// @0x1409c1e80
void ASSlot::FUN_1409c1e80(int n)
{
    FUN_1407cb9c0(s_strItemLock, n);
}

// @0x1409c1ec0
void ASSlot::FUN_1409c1ec0(int n)
{
    FUN_1407cb9c0(s_strItemConditionLock, n);
}

// @0x1409c1f00
void ASSlot::FUN_1409c1f00(int n)
{
    FUN_1407cb9c0(s_strItemSeal, n);
}

#ifndef MS2_HOOK_DLL
// @0x1409c1f40
void ASSlot::FUN_1409c1f40(CItem* pItem)
{
    int nLock = pItem->FUN_140528ca0();
    __int64 tUnlock = pItem->FUN_140528e00();
    if (nLock == 0 && tUnlock > FUN_140869440())
    {
        FUN_1407cbbe0(s_strItemIconLock, false);
        FUN_1407cbbe0(s_strItemIconUnLock, true);
        return;
    }
    if (nLock == 1)
    {
        FUN_1407cbbe0(s_strItemIconLock, true);
        FUN_1407cbbe0(s_strItemIconUnLock, false);
    }
    else
    {
        FUN_1407cbbe0(s_strItemIconLock, false);
        FUN_1407cbbe0(s_strItemIconUnLock, false);
    }
}
#endif

// @0x1409c2050
void ASSlot::FUN_1409c2050(int n)
{
    FUN_1407cb9c0(s_strItemPiece, n);
}

// @0x1409c2090
void ASSlot::FUN_1409c2090(int n)
{
    FUN_1407cb9c0(s_strGrayColor, n);
}

// @0x1409c20d0
void ASSlot::FUN_1409c20d0(int n)
{
    FUN_1407cb9c0(s_strItemEquip, n);
}

// @0x1409c2110
void ASSlot::FUN_1409c2110(int n)
{
    FUN_1407cb9c0(s_strItemEquip2, n);
}

// @0x1409c2150
void ASSlot::FUN_1409c2150(int n)
{
    FUN_1407cb9c0(s_strItemSummon, n);
}

// @0x1409c2190
void ASSlot::FUN_1409c2190(unsigned n)
{
    if (n > 0)
        FUN_1407cbb20(s_strItemCount, StringFormat(L"{0}", n));
}

// @0x1409c2200
void ASSlot::FUN_1409c2200(CItem* pItem)
{
    FUN_1407cbb20(s_strItemCount, pItem->FUN_140527840()->FUN_14053c7c0() ? StringFormat(L"{0}", (unsigned)pItem->FUN_140526c50()) : CStringW(L""));
}

// @0x1409c2360
void ASSlot::FUN_1409c2360(unsigned long nColor)
{
    FUN_1409c4990(s_strItemColor, nColor);
}

// @0x1409c23a0
void ASSlot::FUN_1409c23a0(unsigned nItemId)
{
    FUN_1409c0d20(s_strItemID, nItemId);
}

// @0x1409c23e0
void ASSlot::FUN_1409c23e0(int nGrade)
{
    FUN_1409adc90(s_strItemGrade, nGrade);
}

// @0x1409c2420
void ASSlot::FUN_1409c2420(int nRank)
{
    FUN_1409adc90(s_strItemPetRank, nRank);
    FUN_1409c2610();
}

// @0x1409c2470
void ASSlot::FUN_1409c2470(int n)
{
    FUN_1407cb9c0(s_strItemPetSkin, n);
}

// @0x1409c24b0
void ASSlot::FUN_1409c24b0(int n)
{
    FUN_1407cb9c0(s_strItemBothEquip, n);
}

// @0x1409c24f0
void ASSlot::FUN_1409c24f0(int n)
{
    FUN_1407cb9c0(s_strItemNew, n);
}

// @0x1409c2530
void ASSlot::FUN_1409c2530(int n)
{
    FUN_1407cb9c0(s_strItemEvent, n);
}

// @0x1409c2570
void ASSlot::FUN_1409c2570(int n)
{
    FUN_1407cb9c0(s_strItemResultTag, n);
}

// @0x1409c25b0
void ASSlot::FUN_1409c25b0(const CStringW& strName)
{
    FUN_1407cbb20(s_strItemName, strName);
}

// @0x1409c2610
void ASSlot::FUN_1409c2610()
{
    FUN_1407cb9c0(s_strDropShadowDisable, 1);
}

// @0x1409c2650
void ASSlot::FUN_1409c2650()
{
    FUN_1407cb9c0(s_strDisableDrag, 1);
}

// @0x1409c2690
void ASSlot::FUN_1409c2690(int n)
{
    FUN_1407cb9c0(s_strLearn, n);
}

// @0x1409c26d0
void ASSlot::FUN_1409c26d0(int nIndex)
{
    FUN_1407cb9c0(s_strIndex, nIndex);
}

// @0x1409c2710
void ASSlot::FUN_1409c2710(int n)
{
    FUN_1407cb9c0(s_strDisable, n);
}

// @0x1409c2750
void ASSlot::FUN_1409c2750(const CString& strPath)
{
    FUN_1409c27c0(FUN_14016a730(strPath, 0));
}

// @0x1409c27c0
void ASSlot::FUN_1409c27c0(const CStringW& strPath)
{
    FUN_1407cbb20(s_strIconPath, strPath);
}

// @0x1409c2820
void ASSlot::FUN_1409c2820(const CString& strHint)
{
    FUN_1409c2890(FUN_14016a730(strHint, 0));
}

// @0x1409c2890
void ASSlot::FUN_1409c2890(const CStringW& strHint)
{
    FUN_1407cbb20(s_strSlotHint, strHint);
}

// @0x1409c28f0
void ASSlot::FUN_1409c28f0(const CStringW& strGuid)
{
    FUN_1407cbb20(s_strItemGUID, strGuid);
}

// @0x1409c2950
void ASSlot::FUN_1409c2950(int nTag)
{
    if (nTag == 0)
        return;
    FUN_1407cb9c0(s_strUgctag, nTag);
}

// @0x1409c2990
void ASSlot::FUN_1409c2990(const CStringW& strCategory)
{
    FUN_1407cbb20(s_strItemCategory, strCategory);
}

// @0x1409c29f0
void ASSlot::FUN_1409c29f0(unsigned nType)
{
    FUN_1409c0d20(s_strSkilltype, nType);
}

// @0x1409c2a30
void ASSlot::FUN_1409c2a30(int n)
{
    FUN_1407cb9c0(s_strSkillmaster, n);
}

// @0x1409c2a70
void ASSlot::FUN_1409c2a70(MS2Ptr<Unk_SlotSkillInfo> spSkill, int nPoints)
{
    FUN_1407cbbe0("upgradeCondition", FUN_140ecf630(spSkill, nPoints));
}

// @0x1409c2af0
// MS2-FUNCTIONAL: the skill row pointer is built through a converting copy in the exe (FUN_1407f4f80)
void ASSlot::FUN_1409c2af0(CItem* pItem, void* pPlayer)
{
    if (pItem->FUN_140526100() != 0)
        return;
    if (pItem->FUN_140527840()->FUN_14053dc20() == 0)
        return;
    Unk_SlotPc* pPc = FUN_1409613d0(pPlayer);
    if (pPc == NULL)
        return;
    FUN_1416546d0(pPc);
    MS2Ptr<Unk_SlotSkillRow> spRow = FUN_140639210(pItem->FUN_140527840()->FUN_14053dc20());
    if (spRow.IsNull())
        return;
    MS2Ptr<Unk_SlotSkillLevel> spLevel(0);
    if (pPc->FUN_1416764d0() == 0)
        spLevel = FUN_1416546d0(pPc)->vfunc_1(pItem->FUN_140527840()->FUN_14053dc20());
    else
        spLevel = spRow->FUN_1407e90a0(1);
    if (spLevel.IsNull())
        return;
    if (spRow->m_bCooldown == 0)
        return;
    FUN_1409c2dc0(pPc->FUN_141523bc0()->FUN_141765fe0(pItem->FUN_140527840()->FUN_14053dc20(), 0));
    FUN_1409c2e00(spLevel->FUN_140804660());
    FUN_1409c2e40();
}

// @0x1409c2dc0
void ASSlot::FUN_1409c2dc0(float fRemain)
{
    FUN_1409c4a30("remainTime", fRemain);
}

// @0x1409c2e00
void ASSlot::FUN_1409c2e00(float fTotal)
{
    FUN_1409c4a30("totalTime", fTotal);
}

// @0x1409c2e40
void ASSlot::FUN_1409c2e40()
{
    FUN_1407cbb20("cooldownSecStr", FUN_14028de60(0x5cb));
    FUN_1407cbb20("cooldownMinStr", FUN_14028de60(0x5ca));
    FUN_1407cbb20("cooldownHourStr", FUN_14028de60(0x5cc));
    FUN_1407cbb20("cooldownDayStr", FUN_14028de60(0x5ce));
}

// @0x1409c2f40
void ASSlot::FUN_1409c2f40(CItemEnchantInfo* pEnchant)
{
    if (pEnchant->FUN_14058c8a0() != 0)
    {
        int nLevel = pEnchant->FUN_14058c5f0();
        if (nLevel > 0)
        {
            FUN_1407cb9c0("enchantBroken", 1);
            FUN_1407cb9c0("enchant", nLevel);
        }
    }
    else
    {
        int nLevel = pEnchant->FUN_14058c5f0();
        if (nLevel > 0)
            FUN_1407cb9c0("enchant", nLevel);
    }
}

// @0x1409c2fe0
void ASSlot::FUN_1409c2fe0(Unk_ItemPlusInfo* pPlus)
{
    if (pPlus->FUN_1408bbc50() > 0)
    {
        int nLevel = pPlus->FUN_1408bbc50();
        if (nLevel > 0)
            FUN_1407cb9c0("unlimited", nLevel);
    }
}

// @0x1409c3040
void ASSlot::FUN_1409c3040(MS2Ptr<CItemData> spData)
{
    if (spData == 0 || !spData->FUN_14053d840())
        return;
    unsigned short nLevel = FUN_140626f20(spData->FUN_14053c510());
    if (nLevel == 0)
        return;
    FUN_1409c48f0("enchant", nLevel);
}

// @0x1409c30f0
void ASSlot::FUN_1409c30f0(MS2Ptr<CItemData> spData)
{
    if (spData == 0 || !spData->FUN_14053d8c0())
        return;
    unsigned short nLevel = FUN_1409c4b30()->FUN_1405b5780(spData->FUN_14053c510());
    if (nLevel == 0)
        return;
    FUN_1409c48f0("enchant", nLevel);
}

// @0x1409c31b0
void ASSlot::FUN_1409c31b0(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    if (spData == 0)
        return;
    FUN_1409c3290(spData);
}

// @0x1409c3290
void ASSlot::FUN_1409c3290(MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return;
    int nItemId = spData->FUN_14053c510();
    int nSeason = spData->FUN_14053dec0();
    Unk_SlotSeasonTable* pTable = FUN_14052d230();
    if (pTable != NULL && pTable->FUN_14059eec0(nItemId) == true)
        nSeason = pTable->FUN_14059ebb0(nItemId);
    if (nSeason == 0)
        return;
    if (!pTable->FUN_14059ef70(nSeason))
        return;
    CStringW strSeason = FUN_1409e5320(nSeason);
    FUN_1407cbb20("itemSeason", strSeason);
}

// @0x1409c33d0
void ASSlot::FUN_1409c33d0()
{
    FUN_1407cb9c0("enchant", 0);
}

// @0x1409c3400
void ASSlot::FUN_1409c3400()
{
    FUN_1407cb9c0("gradeBG", 0);
}

// @0x1409c3430
void ASSlot::FUN_1409c3430(CItem* pItem)
{
    switch (FUN_140764020()->FUN_1416ce6a0(MS2Ptr<CItem>(pItem)))
    {
    case 0:
        FUN_1407cb9c0("questBeginAble", 1);
        break;
    case 1:
        FUN_1407cb9c0("questProgress", 1);
        break;
    }
}

// @0x1409c34e0
// MS2-FUNCTIONAL: switch temporaries
void ASSlot::FUN_1409c34e0(CItem* pItem)
{
    Unk_SlotInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
    if (pInventory == NULL || pInventory->vfunc_55() != 0)
        return;
    switch (pInventory->FUN_1409c4b00())
    {
    case 0:
        break;
    case 1:
    case 2:
        if (FUN_1409c4b20()->FUN_140531aa0(MS2Ptr<CItem>(pItem)) == 0)
            FUN_1409c1f00(1);
        break;
    case 3:
        if (FUN_140535310()->FUN_140613430(MS2Ptr<CItem>(pItem)) == 0)
            FUN_1409c1f00(1);
        break;
    case 4:
        if (pItem->FUN_1405292a0() == 0)
            FUN_1409c1f00(1);
        break;
    case 5:
        if (pItem->FUN_140525640() == 0)
        {
            FUN_1409c1f00(1);
        }
        else
        {
            MS2Ptr<Unk_SlotPetRow> spPet = FUN_14052d210()->FUN_1407290f0(pItem->FUN_140527840()->FUN_14053dc60());
            if (spPet.IsNull())
                FUN_1409c1f00(1);
            else if (!spPet->m_bSummonable)
                FUN_1409c1f00(1);
        }
        break;
    }
}

// @0x1409c3750
void ASSlot::FUN_1409c3750(bool b)
{
    FUN_1407cbbe0("useRightClick", b);
}

// @0x1409c3780
int ASSlot::FUN_1409c3780()
{
    Scaleform::GFx::Value v = FUN_1422baa20(s_strItemID);
    int nItemId = v.GetUInt();
    return nItemId;
}

// @0x1409c37f0
int ASSlot::FUN_1409c37f0()
{
    Scaleform::GFx::Value v = FUN_1422baa20(s_strItemGrade);
    int nGrade = v.GetInt();
    return nGrade;
}

// @0x1409c3860
// MS2-FUNCTIONAL: big flag-driven filler; frame layout of the temporaries differs
int ASSlot::FUN_1409c3860(CItem* pItem, void* pPlayer, int nFlags)
{
    if (pItem == NULL)
        return 0;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData.IsNull())
        return 0;
    if (nFlags & 1)
    {
        FUN_1409c23a0(spData->FUN_14053c510());
        FUN_1409c23e0(pItem->FUN_140526bd0());
        FUN_1409c26d0(pItem->FUN_140526b50());
        if (!FUN_140166410()->FUN_14036d570(0x8c))
            FUN_1409c1ce0(spData->FUN_14053cc40());
        else if (spData->FUN_14053cc40())
            FUN_1409c2420(pItem->FUN_140526bd0());
        FUN_1409c2470(spData->FUN_14053e900() == 11);
        FUN_1409c1d20(spData->FUN_14053e130());
        FUN_1409c1d60(spData->FUN_14053cf90());
        FUN_1409c1da0(spData->FUN_14053ce20());
        FUN_1409c1e00(spData->FUN_14053d1f0());
        FUN_1409c1e40(spData->FUN_14053d210());
        FUN_1409c2750(pItem->FUN_140528590());
        FUN_1409c2950(pItem->FUN_140528840());
        if (pPlayer != NULL)
            FUN_1409c2af0(pItem, pPlayer);
        FUN_1409c2f40(pItem->FUN_1405278a0()->FUN_140630d60());
        FUN_1409c2fe0(pItem->FUN_1405278a0()->FUN_140630d90());
        FUN_1409c1f40(pItem);
        FUN_1409c2050(spData->FUN_14053d990());
        FUN_1409c3040(spData);
        FUN_1409c30f0(spData);
        FUN_1409c31b0(MS2Ptr<CItem>(pItem));
    }
    if (nFlags & 0x400)
        FUN_1409c2650();
    if (nFlags & 0x800)
        FUN_1409c25b0(pItem->FUN_140527b10());
    if ((nFlags & 0x20) && pPlayer != NULL)
    {
        Unk_SlotPc* pPc = FUN_1409613d0(pPlayer);
        if (pPc != NULL)
        {
            bool bEquipped = false;
            if (pItem->FUN_140527840()->FUN_14053cbc0())
            {
                MS2Ptr<CEquipItem> spEquip = reinterpret_cast<Unk_SlotMyPc*>(pPc)->FUN_141655c30(pItem->FUN_140526a50());
                bEquipped = spEquip.get() != NULL;
            }
            if (bEquipped)
                FUN_1409c20d0(bEquipped);
        }
    }
    if ((nFlags & 0x10000) && pItem->FUN_140525640() != 0)
    {
        __int64 nUid = pItem->FUN_140526a50();
        if (nUid == FUN_140535320()->FUN_140c8b2e0())
            FUN_1409c2150(1);
    }
    if (nFlags & 2)
    {
        if (pItem->FUN_1405268f0() == 0)
        {
            if (pItem->FUN_140526930())
                FUN_1409c2530(1);
        }
        else
        {
            FUN_1409c24f0(1);
        }
    }
    if (nFlags & 4)
    {
        FUN_1409c0d20("level", pItem->FUN_140527710());
        if (pPlayer != NULL)
        {
            Unk_SlotPc* pPc = FUN_1409613d0(pPlayer);
            if (pPc != NULL && pItem->FUN_140527840()->FUN_14053c8b0())
            {
                int nUsable = FUN_141275a10(pItem);
                if (nUsable == 1)
                    FUN_1409c1e80(1);
                else if (nUsable == 2)
                    FUN_1409c2710(1);
                else if (nUsable == 3)
                    FUN_1409c1ec0(1);
            }
        }
    }
    if (nFlags & 8)
    {
        if (pItem->FUN_140527840()->FUN_14053ec70()->FUN_140547190())
            FUN_1409c2360(pItem->FUN_140527870()->FUN_140599fd0(0));
    }
    if (nFlags & 0x10)
        FUN_1409c2200(pItem);
    if (nFlags & 0x80)
        FUN_1409c2820(FUN_14021c050(pItem->FUN_140526c30()));
    if (nFlags & 0x100)
        FUN_1409c28f0(FUN_141b71910(pItem->FUN_140526a50()));
    if (nFlags & 0x1000)
    {
        int nCategory = pItem->FUN_1405276c0();
        FUN_1409c2990(FUN_1401a9d70()->FUN_141812f60(nCategory));
    }
    if ((nFlags & 0x200) && pItem->FUN_140526970() != 0)
        FUN_1409c2570(1);
    if (nFlags & 0x2000)
        FUN_1409c2610();
    if (nFlags & 0x4000)
        FUN_1409c3430(pItem);
    if (nFlags & 0x8000)
        FUN_1409c34e0(pItem);
    if (nFlags & 0x20000)
        FUN_1409c33d0();
    if (nFlags & 0x40000)
        FUN_1409c3400();
    return 1;
}

// @0x1409c41f0
// MS2-FUNCTIONAL: the both-equip test materializes a bool temporary in the exe
int ASSlot::FUN_1409c41f0(CItem* pItem, void* pPc, int nSlot, int nFlags)
{
    if (pPc == NULL)
        return 0;
    if (pItem == NULL)
        return 0;
    if (FUN_1409c3860(pItem, pPc, nFlags) != 0)
    {
        MS2Ptr<CEquipItem> spMain = FUN_1416561a0(pPc)->FUN_1411e1780(nSlot, 0);
        MS2Ptr<CEquipItem> spSub = FUN_1416561a0(pPc)->FUN_1411e1780(nSlot, 1);
        if (pItem->FUN_1405258b0() != 0 && spMain.get() != NULL)
            FUN_1409c24b0(1);
        else if (pItem->FUN_1405258b0() == 0 && spSub.get() != NULL)
            FUN_1409c24b0(1);
        else
            FUN_1409c24b0(0);
        return 1;
    }
    return 0;
}

// @0x1409c4360
int ASSlot::FUN_1409c4360(Unk_SlotSkillInfo* pSkill, unsigned nFlags)
{
    Unk_SlotPc* pPc = static_cast<Unk_SlotPc*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (pPc == NULL)
        return 0;
    MS2Ptr<Unk_SlotSkillData> spRow = FUN_1401958b0()->FUN_1407ee1d0(pSkill->FUN_140637cc0());
    if (spRow.IsNull())
        return 0;
    if (nFlags & 1)
    {
        FUN_1409c2750(spRow->m_strIcon);
        FUN_1409c2a70(MS2Ptr<Unk_SlotSkillInfo>(pSkill), pPc->FUN_14152e970(pSkill->FUN_140637e00()));
    }
    if (nFlags & 0x400)
    {
        FUN_1409c2710(pSkill->m_bLearned == false);
        if (spRow->FUN_1407e9de0())
            FUN_1409c2650();
    }
    return 1;
}

// @0x1409c4510
int ASSlot::FUN_1409c4510(int nItemId, int nRarity, int nCount)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData.IsNull())
        return 0;
    FUN_1409c23a0(nItemId);
    FUN_1409c23e0(nRarity);
    if (!(!FUN_140166410()->FUN_14036d570(0x8c)))
    {
        if (spData->FUN_14053cc40())
            FUN_1409c2420(nRarity);
    }
    else
        FUN_1409c1ce0(spData->FUN_14053cc40());
    FUN_1409c1d20(spData->FUN_14053e130());
    FUN_1409c1d60(spData->FUN_14053cf90());
    FUN_1409c1da0(spData->FUN_14053ce20());
    FUN_1409c1e00(spData->FUN_14053d1f0());
    FUN_1409c1e40(spData->FUN_14053d210());
    FUN_1409c2750(spData->FUN_14053fdd0());
    FUN_1409c25b0(FUN_1401a9d70()->FUN_141811980(1, nItemId));
    FUN_1409c2190(nCount);
    FUN_1409c2650();
    FUN_1409c3040(spData);
    FUN_1409c30f0(spData);
    FUN_1409c3290(spData);
    FUN_1409c2050(spData->FUN_14053d990());
    return 1;
}

// @0x1409c4860
int ASSlot::FUN_1409c4860(Unk_SlotIconSource* pSource)
{
    if (pSource == NULL)
        return 0;
    FUN_1409c2750(pSource->m_strIcon);
    FUN_1409c2650();
    return 1;
}

// @0x1409c48b0
int ASSlot::FUN_1409c48b0(const CString& strText)
{
    FUN_1409c2750(strText);
    FUN_1409c2650();
    return 1;
}

// The ASObj::Set instances (one per value type) first used here.
// @0x1409c48f0
void ASObj::FUN_1409c48f0(const char* szName, short n)
{
    ASData data;
    data.FUN_1422b7f70((unsigned short)n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c4990
void ASObj::FUN_1409c4990(const char* szName, unsigned long n)
{
    ASData data;
    data.FUN_1422b8090(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c4a30
void ASObj::FUN_1409c4a30(const char* szName, float f)
{
    ASData data;
    data.FUN_1422b80f0(f);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c4b20 TSingleton<item break manager>::GetInstance
Unk_SlotBreakManager* FUN_1409c4b20()
{
    return DAT_143aaf300;
}

// @0x1409c4b30 TSingleton<lapenshard table>::GetInstance
Unk_SlotLapenTable* FUN_1409c4b30()
{
    return DAT_143aafd98;
}

// ---- the merat market products (the ASItemSlot TU, 0x1409bbc30-0x1409c1ad0) ----

bool FUN_1409b0390(Scaleform::GFx::Value* pValue);              // Value::IsUndefined (an SDK inline instance of another TU)
bool FUN_1409b0350(Scaleform::GFx::Value* pValue);              // Value::IsNull (same)
extern unsigned int DAT_143ab2914;                              // the GM level of the account

// The product id: a premium (coin shop) product number or a UGC listing id.
// It has a constructor (not called here): without one a 16-byte pointer-free local would be a /GS buffer.
struct Unk_MeratOid
{
    Unk_MeratOid();
    void FUN_140207730();                                       // clear
    void FUN_1409c1640(CStringW strOid);                        // parse "P<n>" / "U<n>"
    CStringW FUN_1409b0470() const;                             // the AS form, "P<n>" / "U<n>" (asbilldata.cpp)
    int m_nPremiumId;                                           // +0x00
    __int64 m_nUgcId;                                           // +0x08
};
MS2_CHECK_SIZE(Unk_MeratOid, 0x10);

// The premium part of a market record (the coin shop product, 0x238 bytes at record +0x30).
class Unk_MeratPremium
{
public:
    unsigned int FUN_1406a1650();                               // the currencies it is sold for (1, 2)
    __int64 FUN_1406a1be0(int nIndex);                          // price
    __int64 FUN_1406a1b30(int nIndex);                          // sale price
    int FUN_14069fee0();                                        // PC bang only
    bool FUN_1406a0a60();                                       // sold out
    bool FUN_140ebfb90(int n);                                  // the required achievement is done
    CStringW FUN_140ec05f0();                                   // the star point text
    int FUN_1406a17f0(int nIndex);                              // item count
    CStringW FUN_1406a00e0();                                   // name
    CStringW FUN_140ec01e0(const CStringW& strKey);             // the buy limit text
    bool FUN_1406a0090();                                       // not a random sale
    CStringW FUN_1406a02c0();                                   // the random sale expiry date
    __int64 FUN_1406a0270();                                    // the random sale payback
    bool FUN_1406a0d20(int n);                                  // expired
    bool FUN_1406a0d60(int n);
    bool FUN_1406a0ea0(int n);                                  // preview only
    int FUN_1406a1ee0();                                        // the extra button kind
    bool FUN_1406a1f50();                                       // has a sale period
    CMsTime FUN_1406a19a0(int n);                               // sale start
    CMsTime FUN_1406a1a70(int n);                               // sale end

private:
    char m_pad_00[0x18];
public:
    int m_nSn;                                                  // +0x18
private:
    char m_pad_1c[0x0c];
public:
    int m_nType;                                                // +0x28 3 limited, 6 home timed, 7 random payback, 8 random coupon
private:
    char m_pad_2c[0x10];
public:
    int m_nSaleTag;                                             // +0x3c (2 special, 4 sale)
private:
    char m_pad_40[0x20];
public:
    CMsTime m_tStart;                                           // +0x60
    CMsTime m_tEnd;                                             // +0x70
private:
    char m_pad_80[0x08];
public:
    int m_nBuyLimitKind;                                        // +0x88
    int m_nBuyLimitArg;                                         // +0x8c
    int m_nBuyLimitCount;                                       // +0x90
    short m_nBuyLimit94;                                        // +0x94
    short m_nBuyLimit96;                                        // +0x96
private:
    int m_pad_98;
public:
    int m_nBg;                                                  // +0x9c
private:
    char m_pad_a0[0x08];
public:
    int m_nCoinShopId;                                          // +0xa8
    int m_nItemGrade;                                           // +0xac
private:
    char m_pad_b0[0x10];
public:
    int m_nLimitCount;                                          // +0xc0
private:
    char m_pad_c4[0x34];
public:
    int m_nAchieveId;                                           // +0xf8
    int m_nAchieveGrade;                                        // +0xfc
private:
    char m_pad_100[0x6c];
public:
    int m_nFirstSale;                                           // +0x16c
private:
    char m_pad_170[0x08];
public:
    CMsTime m_tSaleStart;                                       // +0x178
    CMsTime m_tSaleEnd;                                         // +0x188
    CMsTime m_tNextSale;                                        // +0x198
private:
    int m_pad_1a8;
public:
    unsigned int m_nRandomSaleId;                               // +0x1ac
    unsigned int m_nCouponRate;                                 // +0x1b0
private:
    char m_pad_1b4[0x18];
public:
    int m_nSoldCount;                                           // +0x1cc
    int m_nSoldCountHome;                                       // +0x1d0
private:
    char m_pad_1d4[0x64];
};
MS2_CHECK_SIZE(Unk_MeratPremium, 0x238);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_nType, 0x28);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_tStart, 0x60);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_nBuyLimitKind, 0x88);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_nBg, 0x9c);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_nLimitCount, 0xc0);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_nAchieveId, 0xf8);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_nFirstSale, 0x16c);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_tSaleStart, 0x178);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_nRandomSaleId, 0x1ac);
MS2_CHECK_OFFSET(Unk_MeratPremium, m_nSoldCount, 0x1cc);

// The blueprint look of a UGC listing (FUN_140894060 gives its icon).
class Unk_MeratUgcTemplate
{
public:
    CString FUN_140894060();
private:
    char m_pad_00[0xc0];
};

// The UGC part of a market record (a player's listing, at record +0x268).
class Unk_MeratUgc
{
public:
    int FUN_140896310();                                        // 0 a plain UGC item, else a blueprint
    CStringW FUN_1408960a0();                                   // the seller name
    int FUN_1408961a0();                                        // 1 sold

private:
    char m_pad_00[0x20];
public:
    unsigned __int64 m_nAccountId;                              // +0x20
    int m_nSaleState;                                           // +0x28
    int m_nItemId;                                              // +0x2c
private:
    int m_pad_30;
public:
    int m_nGender;                                              // +0x34
private:
    int m_pad_38;
public:
    int m_nSaleCount;                                           // +0x3c
private:
    int m_pad_40;
public:
    int m_nSaleCountTotal;                                      // +0x44
private:
    char m_pad_48[0x08];
public:
    __int64 m_nPrice;                                           // +0x50
private:
    char m_pad_58[0x10];
public:
    __int64 m_nPeriod;                                          // +0x68
    int m_nResale;                                              // +0x70 (3 free resale)
private:
    int m_pad_74;
public:
    __int64 m_nCreateTime;                                      // +0x78
private:
    char m_pad_80[0x38];
public:
    unsigned __int64 m_nSellerCharId;                           // +0xb8
private:
    char m_pad_c0[0x10];
public:
    CUgcItemLook m_look;                                        // +0xd0
    Unk_MeratUgcTemplate m_template;                            // +0x138
    int m_nItemGrade;                                           // +0x1f8
};
MS2_CHECK_OFFSET(Unk_MeratUgc, m_nAccountId, 0x20);
MS2_CHECK_OFFSET(Unk_MeratUgc, m_nPrice, 0x50);
MS2_CHECK_OFFSET(Unk_MeratUgc, m_nCreateTime, 0x78);
MS2_CHECK_OFFSET(Unk_MeratUgc, m_nSellerCharId, 0xb8);
MS2_CHECK_OFFSET(Unk_MeratUgc, m_look, 0xd0);
MS2_CHECK_OFFSET(Unk_MeratUgc, m_template, 0x138);
MS2_CHECK_OFFSET(Unk_MeratUgc, m_nItemGrade, 0x1f8);

// A market record (uiavatarbase.cpp has a partial local copy of this type).
class Unk_MeratEquipEntry : public CPtred
{
public:
    int FUN_1406a4640();                                        // item id
    int FUN_1406a46a0();                                        // currency
    int FUN_1406a46e0();                                        // home product kind
    CStringW FUN_1406a4770();                                   // the UGC item name
    int FUN_1406ab1a0();                                        // m_nState == 0 (premium)
    int FUN_1406ab1d0();                                        // m_nState == 1 (UGC)
    // @0x1409c1760
    int FUN_1409c1760() { return m_nState; }

    Unk_MeratOid m_oid;                                         // +0x18
    int m_nState;                                               // +0x28
    Unk_MeratPremium m_premium;                                 // +0x30
    Unk_MeratUgc m_ugc;                                         // +0x268
};
MS2_CHECK_OFFSET(Unk_MeratEquipEntry, m_oid, 0x18);
MS2_CHECK_OFFSET(Unk_MeratEquipEntry, m_premium, 0x30);
MS2_CHECK_OFFSET(Unk_MeratEquipEntry, m_ugc, 0x268);

class Unk_MeratBanner : public CPtred
{
public:
    CString m_strBg;                                            // +0x18
};
MS2_CHECK_OFFSET(Unk_MeratBanner, m_strBg, 0x18);

class Unk_MeratFilter : public CPtred
{
public:
    bool FUN_140ebb780(int nJob, int nLevel, MS2Ptr<CItemData> spData);   // passes the filter
};

// The report-blind manager (blinded accounts) and the extra button helper.
class Unk_MeratBlindManager
{
public:
    bool FUN_140a259b0(int nKind, __int64 nAccountId);
};
extern Unk_MeratBlindManager* DAT_143ab4148;
class Unk_MeratButtonHelper
{
public:
    void FUN_140a8b240(CStringW& strText, bool* pbShow);
};
extern Unk_MeratButtonHelper* DAT_143ab4150;

unsigned int FUN_141658e60(void* pPc);                          // job
int FUN_141654700(void* pPc);                                   // level
int FUN_14069c3e0(int nCurrency);                               // the money type of a currency
int FUN_140222b90(int nGender);
CStringW FUN_141b71990(unsigned nValue);
CStringW FUN_14093bad0(int nId, int nGrade, CStringW strFormat);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_1418fef90(int nCurrency, __int64 nAmount);
CStringW FUN_1418fec90(int nCurrency, __int64 nAmount, int nArg);
CStringW FUN_1418fec00(int nCurrency, __int64 nAmount, int nArg);
CStringW FUN_14062b4f0(CStringW strKey, const int& nArg);
CStringW FUN_140938ae0(CStringW strKey, const unsigned int& nArg);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_1409e3050(const CStringW& strKey, int n1, int n2);
CString FUN_1402bad60(const char* szFormat, const int* pn);
CStringW FUN_14028b8e0(const CStringW& str);
CStringW FUN_140763e10(int value);
CStringW FUN_1408116a0(int nId, const int& nArg);
CString FUN_1407194b0(__int64 v);
CString FUN_140719530(unsigned __int64 v);
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);
void FUN_141b70f90(const CMsTime& kTime, const CStringW& kFormat, CStringW& kOut);

// @0x1409c1730 TSingleton<report blind manager>::GetInstance
Unk_MeratBlindManager* FUN_1409c1730()
{
    return DAT_143ab4148;
}

// @0x1409c1740 TSingleton<extra button helper>::GetInstance
Unk_MeratButtonHelper* FUN_1409c1740()
{
    return DAT_143ab4150;
}

// @0x1409bbc30
MS2Ptr<ASMeratMarketProductBase> ASMeratMarketProductBase::FUN_1409bbc30(Scaleform::GFx::Value& v, const int& nMovieId)
{
    if (FUN_1409b0390(&v) || FUN_1409b0350(&v))
        return MS2Ptr<ASMeratMarketProductBase>(0);
    int nType = 0;
    Scaleform::GFx::Value vType;
    v.GetMember("asProductType", &vType);
    if (!FUN_1409b0390(&vType) && !FUN_1409b0350(&vType))
        nType = vType.GetInt();
    MS2Ptr<ASMeratMarketProductBase> sp(0);
    if (nType == 2)
    {
        if (FUN_140166410()->FUN_14036d570(0x108))
            sp.AssignRaw(new ASMeratMarketHomeProduct(v, nMovieId));
        else
            sp.AssignRaw(new ASMeratMarketProduct(v, nMovieId));
    }
    else if (nType == 1)
        sp.AssignRaw(new ASMeratMarketLimitedProduct(v, nMovieId));
    else
        sp.AssignRaw(new ASMeratMarketProduct(v, nMovieId));
    return sp;
}

// @0x1409bbf30
MS2Ptr<ASMeratMarketProductBase> ASMeratMarketProductBase::FUN_1409bbf30(const int& nType, const int& nMovieId)
{
    MS2Ptr<ASMeratMarketProductBase> sp(0);
    if (nType == 2)
    {
        if (FUN_140166410()->FUN_14036d570(0x108))
            sp.AssignRaw(new ASMeratMarketHomeProduct(nMovieId));
        else
            sp.AssignRaw(new ASMeratMarketProduct(nMovieId));
    }
    else if (nType == 1)
        sp.AssignRaw(new ASMeratMarketLimitedProduct(nMovieId));
    else
        sp.AssignRaw(new ASMeratMarketProduct(nMovieId));
    return sp;
}

// @0x1409bc150
ASMeratMarketProductBase::ASMeratMarketProductBase(int nMovieId)
    : ASObj(nMovieId), m_nIndex(0), m_nProductType(0)
{
}

// @0x1409bc1c0
ASMeratMarketProductBase::ASMeratMarketProductBase(const Scaleform::GFx::Value& v, int nMovieId)
    : ASObj(v, nMovieId), m_nIndex(0), m_nProductType(0)
{
}

// @0x1409bc240
ASMeratMarketProductBase::ASMeratMarketProductBase(Scaleform::GFx::Value& v, int nMovieId)
    : ASObj(v, nMovieId), m_nIndex(0), m_nProductType(0)
{
}

// @0x1409bc2c0
bool ASMeratMarketProductBase::vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt)
{
    FUN_1409c0f00("asProductType", m_nProductType);
    return true;
}

// @0x1409bc320
bool ASMeratMarketProductBase::vfunc_2(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    return true;
}

// @0x1409bc350
bool ASMeratMarketProductBase::vfunc_3(MS2Ptr<Unk_MeratEquipEntry> spEntry, const CString& strBg)
{
    if (spEntry == 0)
        return false;
    Unk_MeratOid oid = spEntry->m_oid;
    FUN_1407cbb20("productOID", oid.FUN_1409b0470());
    FUN_1409bc4a0(strBg);
    return true;
}

// @0x1409bc430
bool ASMeratMarketProductBase::vfunc_4()
{
    return false;
}

// @0x1409bc440
bool ASMeratMarketProductBase::vfunc_5()
{
    return false;
}

// @0x1409bc450
void ASMeratMarketProductBase::vfunc_6(bool bSoldOut)
{
    FUN_1407cbbe0("soldOut", bSoldOut);
}

// @0x1409bc480
void ASMeratMarketProductBase::FUN_1409bc480(int nIndex)
{
    m_nIndex = nIndex;
}

// @0x1409bc4a0
void ASMeratMarketProductBase::FUN_1409bc4a0(const CString& strBg)
{
    FUN_1407cba60("bgPath", strBg);
}

// @0x1409bc4f0
void ASMeratMarketProductBase::FUN_1409bc4f0(MS2Ptr<Unk_MeratBanner> spBanner)
{
    m_spBanner = spBanner;
}

// @0x1409bc540
void ASMeratMarketProductBase::FUN_1409bc540(const int& nIndex)
{
    FUN_1409c0d20("index", nIndex);
}

// @0x1409bc580
void ASMeratMarketProductBase::FUN_1409bc580(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    if (spEntry == 0)
        return;
    Unk_MeratOid oid = spEntry->m_oid;
    FUN_1407cbb20("productOID", oid.FUN_1409b0470());
}

// @0x1409bc630
void ASMeratMarketProductBase::FUN_1409bc630(const Unk_MeratOid& oid)
{
    FUN_1407cbb20("productOID", oid.FUN_1409b0470());
}

// @0x1409bc680
int ASMeratMarketProductBase::FUN_1409bc680()
{
    return m_nIndex;
}

// @0x1409bc6a0
void ASMeratMarketProductBase::FUN_1409bc6a0(Unk_MeratOid* pOid)
{
    CStringW strOid;
    FUN_1422baad0("productOID", strOid);
    pOid->FUN_1409c1640(strOid);
}

// @0x1409bc720
unsigned int ASMeratMarketProductBase::FUN_1409bc720()
{
    return FUN_1422baa20("index").GetUInt();
}

// @0x1409bc780
int ASMeratMarketProductBase::FUN_1409bc780()
{
    return m_nProductType;
}

// @0x1409bc7a0
ASMeratMarketProduct::ASMeratMarketProduct(int nMovieId)
    : ASMeratMarketProductBase(nMovieId)
{
    m_nProductType = 0;
}

// @0x1409bc7f0
ASMeratMarketProduct::ASMeratMarketProduct(const Scaleform::GFx::Value& v, int nMovieId)
    : ASMeratMarketProductBase(v, nMovieId)
{
    m_nProductType = 0;
}

// @0x1409bc850
ASMeratMarketProduct::ASMeratMarketProduct(Scaleform::GFx::Value& v, int nMovieId)
    : ASMeratMarketProductBase(v, nMovieId)
{
    m_nProductType = 0;
}

// @0x1409bc8b0
// MS2-FUNCTIONAL: 4 KB product row fill; the frame layout of its many temporaries was not matched.
bool ASMeratMarketProduct::vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt)
{
    if (spEntry.IsNull())
        return false;
    void* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == NULL)
        return false;
    if (!ASMeratMarketProductBase::vfunc_1(spEntry, pOpt))
        return false;

    int nState = spEntry->FUN_1409c1760();
    Unk_MeratOid oid = spEntry->m_oid;
    MS2Ptr<Unk_MeratFilter> spFilter(0);
    if (pOpt != NULL)
        spFilter = pOpt->m_spFilter;
    unsigned int nJob = FUN_141658e60(pPc);
    int nLevel = FUN_141654700(pPc);
    FUN_1407cbb20("productOID", oid.FUN_1409b0470());
    int nItemId = spEntry->FUN_1406a4640();
    FUN_1407cbb20("itemID", FUN_141b71990(nItemId));
    int bPremium = spEntry->FUN_1406ab1a0();
    FUN_1407cbbe0("isPremium", bPremium != 0);
    if (nState == 0)
    {
        Unk_MeratPremium& premium = spEntry->m_premium;
        FUN_1407cb9c0("sn", premium.m_nSn);
        FUN_1407cb9c0("itemGrade", premium.m_nItemGrade);
        {
            MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
            if (spData)
            {
                CStringW strFunction = spData->function.name;
                FUN_1407cba60("iconPath", spData->FUN_14053fdd0());
                FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, nItemId));
                if (spFilter.get() != NULL)
                    FUN_1407cbbe0("disable", !spFilter->FUN_140ebb780(nJob, nLevel, spData));
                FUN_1407cbbe0("showRecipe", spData->FUN_14053cde0());
                FUN_1407cbbe0("showPreview", FUN_1403b3c40(strFunction, L"UGCMapPackage"));
                if (spData->property.slotMax > 1)
                {
                    int nCount = premium.FUN_1406a17f0(0);
                    FUN_1407cb9c0("itemCount", nCount);
                }
            }
        }
        int nSaleTag = premium.m_nSaleTag;
        FUN_1407cb9c0("saleTag", nSaleTag);
        FUN_1407cbbe0("specialBg", nSaleTag == 2);
        FUN_1407cb9c0("isBlind", 0);
        FUN_1409c0e60("seller", L"");
        FUN_1409c0dc0("sellerCharSN", "");
        FUN_1407cb9c0("ugctag", 0);
        FUN_1407cbbe0("soldOut", premium.FUN_1406a0a60());
        if (!premium.FUN_140ebfb90(0))
        {
            CStringW strFormat = FUN_14028de60(0x308);
            FUN_1407cbb20("requireAchieve", FUN_14093bad0(premium.m_nAchieveId, premium.m_nAchieveGrade, strFormat));
        }
        FUN_1407cbbe0("isPcBang", premium.FUN_14069fee0() > 0);
        CStringW strStar = premium.FUN_140ec05f0();
        if (!strStar.IsEmpty())
            FUN_1407cbb20("starPoint", strStar);
    }
    else if (nState == 1)
    {
        Unk_MeratUgc& ugc = spEntry->m_ugc;
        FUN_1407cba60("createtime", FUN_1407194b0(ugc.m_nCreateTime));
        FUN_1409adc90("itemGrade", ugc.m_nItemGrade);
        int nGender = FUN_140222b90(ugc.m_nGender);
        FUN_1407cb9c0("gender", nGender);
        FUN_1407cba60("sn", FUN_140719530(ugc.m_nAccountId));
        int nUgcItemId = ugc.m_nItemId;
        {
            MS2Ptr<CItemData> spData = FUN_14053f870(nUgcItemId);
            if (spData)
            {
                FUN_1407cb9c0("ugctag", 1);
                if (spFilter.get() != NULL)
                    FUN_1407cbbe0("disable", !spFilter->FUN_140ebb780(nJob, nLevel, spData));
            }
        }
        FUN_1407cbb20("itemName", spEntry->FUN_1406a4770());
        CString strIcon;
        if (ugc.FUN_140896310() == 0)
            strIcon = ugc.m_look.GetLocalPath();
        else
            strIcon = ugc.m_template.FUN_140894060();
        FUN_1407cba60("iconPath", strIcon);
        int nSaleState = ugc.m_nSaleState;
        int nResale = ugc.m_nResale;
        FUN_1409c10e0("saleState", nSaleState);
        CStringW strResale(L"$s_meratmarketreg_tooltip_btn_free_resale");
        if (nResale == 3)
            FUN_1407cbb20("resaleTooltip", strResale);
        CStringW strSeller = ugc.FUN_1408960a0();
        FUN_1407cbb20("seller", strSeller);
        FUN_1407cba60("sellerCharSN", FUN_140719530(ugc.m_nSellerCharId));
        FUN_1407cbbe0("soldOut", ugc.FUN_1408961a0() == 1);
        bool bDebug = false;
        if (pOpt != NULL)
            bDebug = pOpt->m_bDebug;
        if (!bDebug)
            FUN_1407cb9c0("saleCountTotal", ugc.m_nSaleCountTotal);
        else
        {
            CStringW strSellCount = FUN_1408116a0(0xa27, ugc.m_nSaleCountTotal);
            FUN_1407cbb20("sellCount", strSellCount);
            CMsTime tPeriod(ugc.m_nPeriod);
            CStringW strPeriod;
            CMsTime tZero(0);
            if (tPeriod == tZero)
                strPeriod = L"-";
            else
                FUN_141b70f90(tPeriod, FUN_14028de60(0x9dd), strPeriod);
            FUN_1407cbb20("period", strPeriod);
        }
        FUN_1407cb9c0("saleCount", ugc.m_nSaleCount);
        if (FUN_1409c1730()->FUN_140a259b0(3, spEntry->m_ugc.m_nAccountId))
            FUN_1407cbbe0("isBlind", true);
        if (bDebug)
        {
            BOOL bGm = DAT_143ab2914 >= 50;
            if (bGm)
                FUN_1407cbbe0("debug", true);
            else
                FUN_1407cbbe0("debug", false);
        }
    }
    FUN_1409bd940(spEntry);
    return true;
}

// @0x1409bd8e0
bool ASMeratMarketProduct::vfunc_4()
{
    return FUN_1422baa20("soldOut").GetBool();
}

// @0x1409bd940
// MS2-FUNCTIONAL: the conditional price string temporaries were not matched.
void ASMeratMarketProduct::FUN_1409bd940(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    if (spEntry == 0)
        return;
    int nCurrency = spEntry->FUN_1406a46a0();
    __int64 nPrice = 0;
    __int64 nSalePrice = 0;
    bool bSale = false;
    if (spEntry->FUN_1406ab1a0() != 0)
    {
        Unk_MeratPremium& premium = spEntry->m_premium;
        nPrice = premium.FUN_1406a1be0(m_nIndex);
        nSalePrice = premium.FUN_1406a1b30(m_nIndex);
        bSale = nSalePrice < nPrice;
        if (premium.m_nSaleTag == 4 && nPrice > 0 && bSale)
        {
            int nRate = (int)((nPrice - nSalePrice) * 100 / nPrice);
            if (nRate > 0)
            {
                CStringW strText = FUN_14062b4f0(CStringW(L"s_common_saletag_sale"), nRate);
                FUN_1407cbb20("saleTagText", strText);
            }
        }
    }
    else if (spEntry->FUN_1406ab1d0() != 0)
    {
        Unk_MeratUgc& ugc = spEntry->m_ugc;
        nPrice = ugc.m_nPrice;
        bSale = false;
        nSalePrice = nPrice;
    }
    int nType = FUN_14069c3e0(nCurrency);
    CStringW strPrice = !bSale ? CStringW(L"") : FUN_1409404f0(nPrice);
    CStringW strSalePrice = FUN_1418fec00(nType, nSalePrice, 0);
    FUN_1407cbb20("price", strPrice);
    FUN_1407cbb20("salePrice", strSalePrice);
}

// @0x1409bdd60
ASMeratMarketLimitedProduct::ASMeratMarketLimitedProduct(int nMovieId)
    : ASMeratMarketProductBase(nMovieId)
{
    m_nProductType = 1;
}

// @0x1409bddb0
ASMeratMarketLimitedProduct::ASMeratMarketLimitedProduct(const Scaleform::GFx::Value& v, int nMovieId)
    : ASMeratMarketProductBase(v, nMovieId)
{
    m_nProductType = 1;
}

// @0x1409bde10
ASMeratMarketLimitedProduct::ASMeratMarketLimitedProduct(Scaleform::GFx::Value& v, int nMovieId)
    : ASMeratMarketProductBase(v, nMovieId)
{
    m_nProductType = 1;
}

// @0x1409bde70
ASMeratMarketLimitedProduct::~ASMeratMarketLimitedProduct()
{
}

// @0x1409bdea0
bool ASMeratMarketLimitedProduct::vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt)
{
    if (spEntry == 0 || spEntry->FUN_1406ab1a0() == 0)
        return false;
    if (!ASMeratMarketProductBase::vfunc_1(spEntry, pOpt))
        return false;
    Unk_MeratOid oid = spEntry->m_oid;
    FUN_1407cbb20("productOID", oid.FUN_1409b0470());
    FUN_1409c0fa0("productUIType", 4);
    if (m_spBanner.get() == NULL)
    {
        FUN_1409c0dc0("type", "normal");
        int nBg = spEntry->m_premium.m_nBg;
        if (nBg < 1)
            FUN_1409bc4a0(CString(""));
        else
            FUN_1409bc4a0(FUN_1402bad60("bg{0}", &nBg));
    }
    else
    {
        FUN_1409c0dc0("type", "banner");
        FUN_1409bc4a0(m_spBanner->m_strBg);
    }
    Unk_MeratPremium& premium = spEntry->m_premium;
    vfunc_7(spEntry);
    FUN_1409be940(premium);
    FUN_1409bf780(premium);
    vfunc_8(premium);
    bool bPcBang = premium.FUN_14069fee0() > 0;
    FUN_1407cbbe0("isPcBang", bPcBang);
    return true;
}

// @0x1409be1f0
bool ASMeratMarketLimitedProduct::vfunc_2(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    if (spEntry == 0)
        return false;
    Unk_MeratOid oid = spEntry->m_oid;
    FUN_1407cbb20("productOID", oid.FUN_1409b0470());
    Unk_MeratPremium& premium = spEntry->m_premium;
    FUN_1409be940(premium);
    FUN_1409bf780(premium);
    vfunc_8(premium);
    vfunc_7(spEntry);
    bool bPcBang = premium.FUN_14069fee0() > 0;
    FUN_1407cbbe0("isPcBang", bPcBang);
    return true;
}

// @0x1409be390
bool ASMeratMarketLimitedProduct::vfunc_4()
{
    return FUN_1422baa20("soldOut").GetBool() || FUN_1422baa20("soldOutBuyLimit").GetBool();
}

// @0x1409be4a0
bool ASMeratMarketLimitedProduct::vfunc_5()
{
    return FUN_1422baa20("expired").GetBool();
}

// @0x1409be500
// MS2-FUNCTIONAL: the description string temporaries were not matched.
void ASMeratMarketLimitedProduct::vfunc_7(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    Unk_MeratPremium& premium = spEntry->m_premium;
    FUN_1407cbb20("itemName", premium.FUN_1406a00e0());
    CStringW strDesc = FUN_14028b8e0(CStringW(L"s_meratmarket_limited_desc"));
    CStringW strStart;
    CStringW strEnd;
    const CStringW& strDateFormat = FUN_14028b8e0(CStringW(L"s_meratmarket_limited_date"));
    CMsTime tStart(premium.m_tStart);
    CMsTime tEnd(premium.m_tEnd);
    FUN_141b70f90(tStart, strDateFormat, strStart);
    FUN_141b70f90(tEnd, strDateFormat, strEnd);
    CStringW strUnused;
    CStringW strBuyLimit;
    if (premium.m_nBuyLimitKind != 0)
    {
        CStringW strFormat = FUN_1409e3050(CStringW(L"s_meratmarket_limited_buylimit"), premium.m_nBuyLimitKind, premium.m_nBuyLimitCount);
        strBuyLimit = FUN_14062b4f0(strFormat, premium.m_nBuyLimitArg);
    }
    CStringW strBuyLimit2;
    if (premium.m_nBuyLimit94 != 0 || premium.m_nBuyLimit96 != 0)
        strBuyLimit2 = premium.FUN_140ec01e0(CStringW(L"s_meratmarket_limited_buylimit_"));
    FUN_1407cbb20("desc", StringFormat((const wchar_t*)strDesc, strStart, strEnd, premium.m_nLimitCount, strBuyLimit, strBuyLimit2));
}

// @0x1409be940
void ASMeratMarketLimitedProduct::FUN_1409be940(Unk_MeratPremium& premium)
{
    switch (premium.m_nType)
    {
    case 7:
        FUN_1409bef00(premium);
        break;
    case 8:
        FUN_1409bf300(premium);
        break;
    default:
        FUN_1409be9b0(premium);
        break;
    }
}

// @0x1409be9b0
// MS2-FUNCTIONAL: the conditional price string temporaries were not matched.
void ASMeratMarketLimitedProduct::FUN_1409be9b0(Unk_MeratPremium& premium)
{
    bool bFree = false;
    unsigned int nFlags = premium.FUN_1406a1650();
    if (nFlags & 1)
    {
        __int64 nPrice = premium.FUN_1406a1be0(0);
        __int64 nSalePrice = premium.FUN_1406a1b30(0);
        int nType = FUN_14069c3e0(1);
        CStringW strPrice = nSalePrice < nPrice ? FUN_1409404f0(nPrice) : CStringW(L"");
        CStringW strSalePrice = FUN_1418fef90(nType, nSalePrice);
        FUN_1407cbb20("price", strPrice);
        FUN_1407cbb20("salePrice", strSalePrice);
        FUN_1409c1040("priceType", 1);
        bFree = nPrice == 0 && nSalePrice == 0;
        FUN_1407cbbe0("showFreeText", bFree);
    }
    if (!bFree && (nFlags & 2))
    {
        __int64 nPrice = premium.FUN_1406a1be0(0);
        __int64 nSalePrice = premium.FUN_1406a1b30(0);
        int nType = FUN_14069c3e0(2);
        CStringW strPrice = nSalePrice < nPrice ? FUN_1409404f0(nPrice) : CStringW(L"");
        CStringW strSalePrice = FUN_1418fef90(nType, nSalePrice);
        FUN_1407cbb20("price2", strPrice);
        FUN_1407cbb20("salePrice2", strSalePrice);
        FUN_1409c1040("priceType2", 2);
    }
}

// @0x1409bef00
// MS2-FUNCTIONAL: string temporaries not matched.
void ASMeratMarketLimitedProduct::FUN_1409bef00(Unk_MeratPremium& premium)
{
    unsigned int nFlags = premium.FUN_1406a1650();
    if (!premium.FUN_1406a0090())
    {
        FUN_1409c0d20("randomSaleID", premium.m_nRandomSaleId);
        FUN_1407cbb20("randomExpiredDate", premium.FUN_1406a02c0());
        if (nFlags & 1)
        {
            int nType = FUN_14069c3e0(1);
            CStringW strSalePrice = FUN_1418fef90(nType, premium.FUN_1406a1b30(0));
            CStringW strPayback = FUN_1418fec90(nType, premium.FUN_1406a0270(), 0);
            FUN_1409c0e60("price", L"");
            FUN_1407cbb20("salePrice", strSalePrice);
            FUN_1407cbb20("randomPaybackPrice", FUN_1405c2690(CStringW(L"s_meratmarket_random_payback"), strPayback));
            FUN_1409c1040("priceType", 1);
        }
        if (nFlags & 2)
        {
            int nType = FUN_14069c3e0(2);
            CStringW strSalePrice = FUN_1418fef90(nType, premium.FUN_1406a1b30(0));
            CStringW strPayback = FUN_1418fec90(nType, premium.FUN_1406a0270(), 0);
            FUN_1409c0e60("price2", L"");
            FUN_1407cbb20("salePrice2", strSalePrice);
            FUN_1407cbb20("randomPaybackPrice2", FUN_1405c2690(CStringW(L"s_meratmarket_random_payback"), strPayback));
            FUN_1409c1040("priceType2", 2);
        }
    }
    else
        FUN_1409be9b0(premium);
}

// @0x1409bf300
// MS2-FUNCTIONAL: string temporaries not matched.
void ASMeratMarketLimitedProduct::FUN_1409bf300(Unk_MeratPremium& premium)
{
    unsigned int nFlags = premium.FUN_1406a1650();
    if (!premium.FUN_1406a0090())
    {
        FUN_1409c0d20("randomSaleID", premium.m_nRandomSaleId);
        FUN_1407cbb20("randomExpiredDate", premium.FUN_1406a02c0());
        if (nFlags & 1)
        {
            int nType = FUN_14069c3e0(1);
            CStringW strPrice = FUN_1409404f0(premium.FUN_1406a1be0(0));
            CStringW strSalePrice = FUN_1418fef90(nType, premium.FUN_1406a1b30(0));
            FUN_1407cbb20("price", strPrice);
            FUN_1407cbb20("salePrice", strSalePrice);
            FUN_1407cbb20("randomCouponRate", FUN_140938ae0(CStringW(L"s_meratmarket_random_sale"), premium.m_nCouponRate));
            FUN_1409c1040("priceType", 1);
        }
        if (nFlags & 2)
        {
            int nType = FUN_14069c3e0(2);
            CStringW strPrice = FUN_1409404f0(premium.FUN_1406a1be0(0));
            CStringW strSalePrice = FUN_1418fef90(nType, premium.FUN_1406a1b30(0));
            FUN_1407cbb20("price2", strPrice);
            FUN_1407cbb20("salePrice2", strSalePrice);
            FUN_1407cbb20("randomCouponRate2", FUN_140938ae0(CStringW(L"s_meratmarket_random_sale"), premium.m_nCouponRate));
            FUN_1409c1040("priceType2", 2);
        }
    }
    else
        FUN_1409be9b0(premium);
}

// @0x1409bf780
// MS2-FUNCTIONAL: string temporaries not matched.
void ASMeratMarketLimitedProduct::FUN_1409bf780(Unk_MeratPremium& premium)
{
    CStringW strRemain;
    bool bSoldOut = false;
    if (premium.m_nType == 3)
    {
        if (premium.m_nLimitCount > 0)
        {
            int nRemain = premium.m_nLimitCount - premium.m_nSoldCount < 0 ? 0 : premium.m_nLimitCount - premium.m_nSoldCount;
            // The text goes to a local of its own and is dropped: limited products never show "remain".
            CStringW strText;
            if (nRemain != 0)
                strText = FUN_1405c2690(CStringW(L"s_meratmarket_limited_remain"), FUN_140763e10(nRemain));
            else
                strText = FUN_14028b8e0(CStringW(L"s_meratmarket_limited_soldout"));
            bSoldOut = nRemain == 0;
        }
    }
    else if (premium.m_nType == 6 && premium.m_nLimitCount > 0)
    {
        int nRemain = premium.m_nLimitCount - premium.m_nSoldCountHome < 0 ? 0 : premium.m_nLimitCount - premium.m_nSoldCountHome;
        if (nRemain == 0)
        {
            bSoldOut = true;
            strRemain = FUN_14028b8e0(CStringW(L"s_meratmarket_limited_soldout"));
        }
        else
            strRemain = FUN_1405c2690(CStringW(L"s_meratmarket_limited_remain"), FUN_140763e10(nRemain));
    }
    if (!strRemain.IsEmpty())
        FUN_1407cbb20("remain", strRemain);
    bool bSold = premium.FUN_1406a0a60();
    if (premium.m_nType == 0 || premium.m_nType == 1 || premium.m_nType == 2)
        FUN_1407cbbe0("soldOut", bSold);
    else
    {
        FUN_1407cbbe0("soldOut", bSoldOut);
        FUN_1407cbbe0("soldOutBuyLimit", bSold);
    }
}

// @0x1409bfc20
void ASMeratMarketLimitedProduct::vfunc_8(Unk_MeratPremium& premium)
{
    bool bExpired = premium.FUN_1406a0d20(0);
    FUN_1407cbbe0("expired", bExpired);
}

// @0x1409bfc60
ASMeratMarketHomeProduct::ASMeratMarketHomeProduct(int nMovieId)
    : ASMeratMarketLimitedProduct(nMovieId)
{
    m_nProductType = 2;
}

// @0x1409bfcb0
ASMeratMarketHomeProduct::ASMeratMarketHomeProduct(const Scaleform::GFx::Value& v, int nMovieId)
    : ASMeratMarketLimitedProduct(v, nMovieId)
{
    m_nProductType = 2;
}

// @0x1409bfd10
ASMeratMarketHomeProduct::ASMeratMarketHomeProduct(Scaleform::GFx::Value& v, int nMovieId)
    : ASMeratMarketLimitedProduct(v, nMovieId)
{
    m_nProductType = 2;
}

// @0x1409bfd70
// MS2-FUNCTIONAL: the per-return locals of the extra button branch were not matched.
bool ASMeratMarketHomeProduct::vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt)
{
    if (spEntry == 0 || spEntry->FUN_1406ab1a0() == 0)
        return false;
    if (!ASMeratMarketLimitedProduct::vfunc_1(spEntry, pOpt))
        return false;
    int nUIType = 0;
    switch (spEntry->FUN_1406a46e0())
    {
    case 6:
        nUIType = 1;
        break;
    case 7:
        nUIType = 2;
        break;
    case 8:
        nUIType = 3;
        break;
    }
    FUN_1407cb9c0("productUIType", nUIType);
    FUN_1409c05d0(spEntry, pOpt);
    Unk_MeratPremium& premium = spEntry->m_premium;
    bool bPreview = premium.FUN_1406a0ea0(0);
    FUN_1407cbbe0("isPreview", bPreview);
    if (!bPreview)
    {
        if (premium.FUN_1406a1ee0() != 0)
        {
            CStringW strText;
            bool bShow = false;
            switch (premium.FUN_1406a1ee0())
            {
            case 1:
                FUN_1409c1740()->FUN_140a8b240(strText, &bShow);
                break;
            case 2:
                strText = L"$s_meratmarket_text_changeable_extra_button_label";
                bShow = true;
                break;
            }
            FUN_1407cbb20("extraButtonText", strText);
            FUN_1407cbbe0("showExtraButton", bShow);
            return true;
        }
        int nCoinShopId = spEntry->m_premium.m_nCoinShopId;
        if (FUN_14052d230()->FUN_14059e6a0(nCoinShopId) == 0)
            return true;
        FUN_1409c0e60("extraButtonText", L"$s_itemgacha_dialog_coinshop_open");
        FUN_1407cbbe0("showExtraButton", true);
    }
    return true;
}

// @0x1409c00e0
bool ASMeratMarketHomeProduct::vfunc_4()
{
    return FUN_1422baa20("soldOutBuyLimit").GetBool();
}

// @0x1409c0140
void ASMeratMarketHomeProduct::vfunc_6(bool bSoldOut)
{
    FUN_1407cbbe0("soldOutBuyLimit", bSoldOut);
}

// @0x1409c0170
// MS2-FUNCTIONAL: the description string temporaries were not matched.
void ASMeratMarketHomeProduct::vfunc_7(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    Unk_MeratPremium& premium = spEntry->m_premium;
    CStringW strDesc;
    if (premium.m_nType == 6)
        strDesc = "";
    else if (premium.FUN_1406a1f50() && !premium.FUN_1406a0ea0(0) && !premium.FUN_1406a19a0(0).IsNull() &&
             !premium.FUN_1406a1a70(0).IsNull())
    {
        CStringW strFormat = FUN_14028b8e0(CStringW(L"s_meratmarket_home_desc_period"));
        CStringW strStart;
        CStringW strEnd;
        const CStringW& strDateFormat = FUN_14028b8e0(CStringW(L"s_meratmarket_limited_date"));
        CMsTime tStart = premium.FUN_1406a19a0(0);
        CMsTime tEnd = premium.FUN_1406a1a70(0);
        FUN_141b70f90(tStart, strDateFormat, strStart);
        FUN_141b70f90(tEnd, strDateFormat, strEnd);
        strDesc = StringFormat((const wchar_t*)strFormat, strStart, strEnd);
    }
    if (!strDesc.IsEmpty())
        FUN_1407cbb20("desc", strDesc);
}

// @0x1409c0430
void ASMeratMarketHomeProduct::vfunc_8(Unk_MeratPremium& premium)
{
    if (premium.m_nType == 6)
    {
        CMsTime tNow(FUN_140869440());
        if (tNow < premium.m_tSaleStart)
        {
            FUN_1409c1180("startNextSaleRemainTime", premium.m_tSaleStart.Get() - tNow.Get());
            if (premium.m_nFirstSale == 1)
                FUN_1407cbbe0("firstSaleTimeBefore", true);
        }
        else
        {
            FUN_1409c1180("endSaleRemainTime", premium.m_tSaleEnd.Get() - tNow.Get());
            FUN_1409c1180("startNextSaleRemainTime", premium.m_tNextSale.Get() - tNow.Get());
        }
    }
    else
    {
        bool bExpired = premium.FUN_1406a0d20(0) && premium.FUN_1406a0d60(0);
        FUN_1407cbbe0("expired", bExpired);
    }
}

// @0x1409c05d0
// MS2-FUNCTIONAL: the item locals were not matched.
void ASMeratMarketHomeProduct::FUN_1409c05d0(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt)
{
    if (spEntry == 0)
        return;
    Unk_MeratPremium& premium = spEntry->m_premium;
    void* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    FUN_1407cb9c0("sn", premium.m_nSn);
    FUN_1407cb9c0("itemGrade", premium.m_nItemGrade);
    MS2Ptr<Unk_MeratFilter> spFilter(0);
    if (pOpt != NULL)
        spFilter = pOpt->m_spFilter;
    unsigned int nJob = FUN_141658e60(pPc);
    int nLevel = FUN_141654700(pPc);
    int nItemId = spEntry->FUN_1406a4640();
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData)
    {
        CStringW strFunction = spData->function.name;
        FUN_1407cba60("iconPath", spData->FUN_14053fdd0());
        if (spFilter.get() != NULL)
            FUN_1407cbbe0("disable", !spFilter->FUN_140ebb780(nJob, nLevel, spData));
        if (spData->property.slotMax > 1)
        {
            int nCount = premium.FUN_1406a17f0(0);
            FUN_1407cb9c0("itemCount", nCount);
        }
        if (spData->FUN_14053da20())
        {
            int nSeasonId = spData->FUN_14053dec0();
            int nSeason = FUN_14052d230()->FUN_14059ed00(nSeasonId);
            FUN_1409c0d20("itemSeason", nSeason);
        }
    }
    FUN_1407cbbe0("ugctag", false);
}

// @0x1409c0d20
void ASObj::FUN_1409c0d20(const char* szName, unsigned int n)
{
    ASData data;
    data.FUN_1422b8030(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c0dc0
void ASObj::FUN_1409c0dc0(const char* szName, const char* szValue)
{
    ASData data;
    data.FUN_1422b82b0(szValue);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c0e60
void ASObj::FUN_1409c0e60(const char* szName, const wchar_t* szValue)
{
    ASData data;
    data.FUN_1422b8310(szValue);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c0f00
void ASMeratMarketProductBase::FUN_1409c0f00(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c0fa0
void ASMeratMarketProductBase::FUN_1409c0fa0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c1040
void ASMeratMarketProductBase::FUN_1409c1040(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c10e0
void ASMeratMarketProductBase::FUN_1409c10e0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c1180
void ASObj::FUN_1409c1180(const char* szName, __int64 n)
{
    ASData data;
    data.FUN_1422b81c0(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c1640
void Unk_MeratOid::FUN_1409c1640(CStringW strOid)
{
    FUN_140207730();
    if (strOid.GetLength() <= 2)
        return;
    wchar_t chKind = strOid[0];
    CStringW strNumber = strOid.Mid(2);
    if (chKind == L'P')
        m_nPremiumId = _wtoi(strNumber);
    else if (chKind == L'U')
        m_nUgcId = _wtoi64(strNumber);
}
