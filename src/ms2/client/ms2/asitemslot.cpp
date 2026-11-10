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
// MS2-GUESS-LOOKALIKES: MS2Ptr<Unk_MeratFilter> / MS2Ptr<SkillLevelData> operator= fold to one exe copy
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
// MS2-PIN: ?GetMode@Unk_SlotInventoryDialog@@QEAAHXZ 0x1409c4b00 ; unique
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
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VAdditionalLevelData@@@@AEAAXPEAX@Z 0x1409c1a30 ; merge-bind
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\asitemslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#define MS2_ASUICOMPONENT_SLOTS   // C3: slots 3 and 16-24 are ASUIComponent's (not redeclared below)
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
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/client/ms2/skillsystem.h"
#include "ms2/client/ms2/itempreview.h"
#include "ms2/client/ms2/equipment.h"
#include "ms2/commonfiles/itemlapensharddata.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/chomeprivilege.h"  // C3: CHomePrivilege complete for the headers above
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/uimeratmarketweapontype.h"
#include "ms2/placeholder/cpetdatatable.h"
#include "ms2/commonfiles/itembreakmanager.h"
#include "ms2/commonfiles/meratproductkey.h"

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
void SetValue(Scaleform::GFx::Value* pDst, Scaleform::GFx::Value v);                                // argument = value
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                   // the item table row
CStringW FUN_14016a730(const char* sz, int nCodePage);          // multibyte -> wide
CStringW GetStringCommon(int nStringId);
__int64 GetServerTime();                                        // server time
unsigned short FUN_140626f20(unsigned nItemId);                 // fixed enchant level of an item
CString Name_14021c050(int nTag);                                // ugc tag name
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
class CInputKeyHandler   // C3: unit-local view (cinputkeyhandler.h)
{
public:
    bool IsActionKeyDown(int nSetting, bool bDebugOnly, int nLevel);
};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The item preview window the click preview opens (TSingleton instance 0x143ab3fc0).
class Unk_ItemPreview : public ItemPreviewMgr
{
public:
};
Unk_ItemPreview* GetItemPreviewMgr();

// The additional effect (buff) record and its table.
// C3: the record is AdditionalLevelData (FUN_140aafef0 is SkillDataTableCli's, skilldatatablecli.h)
//
//
//
class SkillData;
class SkillDataTableCli { public: MS2Ptr<AdditionalLevelData> FUN_140aafef0(int nId, unsigned short nLevel); };   // C3: member view
class SkillDataTable   // C3: member view (def in skilloverlapcompare)
{
public:
    MS2Ptr<SkillData> GetSkillData(unsigned nSkillId);
};
//
//
//
//
//

// ---- ASItemSlot TU ----

class ASAdditionalEffectSlot : public ASUIComponent
{
public:
    ASAdditionalEffectSlot(CString strName, int nMovieId);
    ASAdditionalEffectSlot(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASAdditionalEffectSlot();                          // 0
    // slots 3, 4 and 16-24: ASUIComponent's (0x1422c7260, 0x1422c7230, 0x1422c7ec0..0x1422c80c0)
    virtual void vfunc_25(Scaleform::GFx::Value** ppOut);       // 25 the effect tooltip
    void SendSlotData();                                       // push the slot data
    void SetEffect(int nId, unsigned short nLevel);         // set the effect and refresh
    void SetTooltipFunction(Unk_AsDelegate callback, __int64 nUser);     // setTooltipFunction
    void OnGetTooltip(const Scaleform::GFx::FunctionHandler::Params& params);   // the tooltip callback
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
    args.resize(1);
    SetValue(&args[0], a1.FUN_1422bb890());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1409bb460
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, ASSlot a1)
{
    ASArgList args;
    args.resize(1);
    SetValue(&args[0], a1.FUN_1422bb890());
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
    SetTooltipFunction(Unk_AsDelegate(this, &ASItemSlot::OnGetTooltip), 0);
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
    SetTooltipFunction(Unk_AsDelegate(this, &ASItemSlot::OnGetTooltip), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409ba410
ASItemSlot::~ASItemSlot()
{
    FUN_1422c63f0(FUN_1422bb890(), 2);
}

// @0x1409ba460
void ASItemSlot::UpdateSlotData()
{
    ASSlot slot(2);
    if (slot.SetItemById(m_itemId, m_rarity, m_nCount) != 0)
    {
        if (m_bLocked)
            slot.SetItemLock(1);
        Invoke("setSlotData", slot);
    }
    else if (m_itemId == 0)
    {
        slot.SetItemID(m_itemId);
        Invoke("setSlotData", slot);
    }
}

// @0x1409ba5d0
void ASItemSlot::SetItem(int nItemId, int nRarity, int nCount)
{
    m_itemId = nItemId;
    m_rarity = nRarity;
    m_nCount = nCount;
    UpdateSlotData();
}
MS2_REPLACE_METHOD(0x1409BA5D0, ASItemSlot, SetItem, 83, 0x4AF4ED20);

// @0x1409ba630
void ASItemSlot::FUN_1409ba630(const Unk_ItemSlotSource& item)
{
    SetItem(item.vfunc_0(), item.vfunc_1(), item.vfunc_2());
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
        ASTooltip tip(((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0(), 0x20, 2);
        if (tip.FUN_1409e0d40(spItem.get()) != 0)
        {
            if (m_bPreview)
                tip.SetEnablePreview(spItem);
            **ppOut = tip.GetValue();
        }
    }
}

// @0x1409ba980
void ASItemSlot::SetTooltipFunction(Unk_AsDelegate callback, __int64 nUser)
{
    Invoke("setTooltipFunction", ASFunction(callback, nUser, m_nMovieId));
}

// @0x1409baa20
void ASItemSlot::OnGetTooltip(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_25(reinterpret_cast<Scaleform::GFx::Value**>(const_cast<Scaleform::GFx::FunctionHandler::Params*>(&params)));
}

// @0x1409baa60
void ASItemSlot::FUN_1409baa60(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (!((class CInputKeyHandler*)FUN_14025e7c0())->IsActionKeyDown(0x49406, false, 0))
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(m_itemId, m_rarity, 0) != 0 && GetItemPreviewMgr()->IsHudOn() != 0)
        ((ItemPreviewMgr*)(Unk_ItemPreview*)(GetItemPreviewMgr()))->OpenPreview(spItem, 0);
}

// @0x1409bab90
ASAdditionalEffectSlot::ASAdditionalEffectSlot(CString strName, int nUnused)
    : ASUIComponent(strName, 2)
{
    m_nId = 0;
    m_nLevel = 0;
    SetTooltipFunction(Unk_AsDelegate(this, &ASAdditionalEffectSlot::OnGetTooltip), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409bacb0
ASAdditionalEffectSlot::ASAdditionalEffectSlot(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
    m_nId = 0;
    m_nLevel = 0;
    SetTooltipFunction(Unk_AsDelegate(this, &ASAdditionalEffectSlot::OnGetTooltip), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409bad80
ASAdditionalEffectSlot::~ASAdditionalEffectSlot()
{
    FUN_1422c63f0(FUN_1422bb890(), 2);
}

// @0x1409badd0
void ASAdditionalEffectSlot::SendSlotData()
{
    MS2Ptr<AdditionalLevelData> spEffect = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(m_nId, m_nLevel);
    if (spEffect == 0)
        return;
    ASSlot slot(2);
    if (slot.FUN_1409c48b0(((AdditionalLevelData*)(spEffect).operator->())->GetIcon()))
        Invoke("setSlotData", slot);
}

// @0x1409baf10
void ASAdditionalEffectSlot::SetEffect(int nId, unsigned short nLevel)
{
    m_nId = nId;
    m_nLevel = nLevel;
    SendSlotData();
}

// @0x1409baf60
void ASAdditionalEffectSlot::vfunc_25(Scaleform::GFx::Value** ppOut)
{
    MS2Ptr<AdditionalLevelData> spEffect = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(m_nId, m_nLevel);
    if (spEffect == 0)
        return;
    ASTooltip tip(((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0(), 1, 2);
    if (tip.FUN_1409e2750(spEffect.get(), 5, 0) != 0)
        **ppOut = tip.GetValue();
}

// @0x1409bb060
void ASAdditionalEffectSlot::SetTooltipFunction(Unk_AsDelegate callback, __int64 nUser)
{
    Invoke("setTooltipFunction", ASFunction(callback, nUser, m_nMovieId));
}

// @0x1409bb100
void ASAdditionalEffectSlot::OnGetTooltip(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_25(reinterpret_cast<Scaleform::GFx::Value**>(const_cast<Scaleform::GFx::FunctionHandler::Params*>(&params)));
}

// @0x1409bb9e0 TSingleton<item preview>::GetInstance
Unk_ItemPreview* GetItemPreviewMgr()
{
    return reinterpret_cast<Unk_ItemPreview*>(TSingleton<ItemPreviewMgr>::s_instance);
}


// ---- ASScrollPanel / ASSlot TU ----

class ASScrollPanel : public ASUIComponent
{
public:
    ASScrollPanel(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASScrollPanel();                                   // 0
    // slots 3, 4 and 16-24: ASUIComponent's (0x1422c7260, 0x1422c7230, 0x1422c7ec0..0x1422c80c0)
    void SetContentsHeight(int nHeight);                            // setContentsHeight
};
MS2_CHECK_SIZE(ASScrollPanel, 0x88);

// The local player, as the slot code sees it.
class Unk_SlotSkillBook;
class SkillLevelData : public CPtred   // C3: member view (real class not in this TU)
{
public:
    float GetCooldown();
};
class SkillData : public CPtred   // C3: member view (real class not in this TU)
{
public:
    bool FUN_1407e9de0();
    MS2Ptr<SkillLevelData> GetLevelData(unsigned short nLevel);
};
class Unk_SlotSkillRow : public CPtred
{
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
    virtual MS2Ptr<SkillLevelData> vfunc_1(int nSkillId);   // 1 the learned level of a skill
};
class Unk_SlotSkillCooldowns : public CSkillSystem
{
};
class Unk_SlotPc : public MyPC
{
public:
};
class Unk_AkoMyPC;
template <> Unk_AkoMyPC* efd::DynamicCast<Unk_AkoMyPC, PCBase>(PCBase* Source);   // C3: was FUN_1409613d0
int GetItemUsableState(CItem* pItem);                                // the usable state of an item (1 locked, 2 disabled, 3 condition)                           // PCBase -> MyPC (NULL for others)
class JobSystem { public: static MS2Ptr<SkillData> GetSkillData(unsigned nSkillId); };   // C3: member view (0x140639210, jobsystem.h)


// The equip set of a PC (FUN_1416561a0).
class CEquipItem;
class Unk_SlotEquipSet : public CEquipment
{
};

// A skill entry (the skill window rows).
class JobSkill : public CPtred   // C3: member view (real class not in this TU)
{
public:
    unsigned int GetID();
    int GetJobLevel();
};
class Unk_SlotSkillInfo : public CPtred
{
public:
private:
    char m_pad_18[7];
public:
    bool m_bLearned;                                            // +0x1f
};
MS2_CHECK_OFFSET(Unk_SlotSkillInfo, m_bLearned, 0x1f);
// The skill record of the skill table (SkillDataTable::GetSkillData).
class Unk_SlotSkillData : public CPtred
{
public:
private:
    void* m_pad_18[(0x48 - 0x18) / 8];
public:
    CString m_strIcon;                                          // +0x48
};
MS2_CHECK_OFFSET(Unk_SlotSkillData, m_strIcon, 0x48);
class UISkillBookTreeDialog   // C3: member view (uiskillbookautodistributedialog.h)
{
public:
    static bool CanUpgrade(MS2Ptr<JobSkill> spSkill, int bCheck);
};

// The icon source SetIconFromSource reads (an icon path at +0xc0).
class Unk_SlotIconSource
{
private:
    void* m_pad_00[0xc0 / 8];
public:
    CString m_strIcon;                                          // +0xc0
};
MS2_CHECK_OFFSET(Unk_SlotIconSource, m_strIcon, 0xc0);

// Item helpers.
class Unk_ItemEquipData : public CItemData {};              // CItem::FUN_140527840's record (item.cpp)
class CItemExtraData   // C3: member view (real class not in this TU)
{
public:
    int GetCurrentRgbComponent(unsigned int);
};
class Unk_UserProxyItemData
{
public:
};
class CItemStatus   // C3: member view (real class not in this TU)
{
public:
    Unk_ItemPlusInfo* GetUnlimitedEnchantInfo();
    CItemEnchantInfo* GetEnchant();
};
// C3: Unk_ItemEnchantData = CItemStatus (CItem::m_spStatus +0xf8)



class CItemEnchantInfo
{
public:
    int GetLevel();                                        // enchant level
    int FUN_14058c8a0();                                        // broken
};
class UnlimitedEnchantInfo   // C3: member view (real class not in this TU)
{
public:
    int GetLevel();
};
class Unk_ItemPlusInfo
{
public:
};
// (C3: FUN_14052d230 = TSingleton<ItemGachaBoxTable>::GetInstance, itemgachaboxtable.h)
class Unk_SlotLapenTable : public CItemLapenshardTable
{
};
class CItemLockManager   // C3: unit-local view (def in unit_1406125d0)
{
public:
    int CanAddItem(MS2Ptr<CItem> spItem);
};
class Unk_BreakRules* FUN_140535310();   // C3: was FUN_140535310
void* FUN_140764020();   // C3: was FUN_140764020
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class Unk_BreakSelected* GetPetManager();   // C3: was GetPetManager
// The inventory dialog's break/lock mode (UIInventoryDialog +0x1a4).
class Unk_SlotInventoryDialog : public UIDialog
{
public:
    int GetMode() { return m_nMode; }
private:
    void* m_pad_178[(0x1a0 - 0x178) / 8];
    int m_pad_1a0;
public:
    int m_nMode;                                                // +0x1a4
};
MS2_CHECK_OFFSET(Unk_SlotInventoryDialog, m_nMode, 0x1a4);
class UIInventoryDialog;
template<class T> T* Unk_BreakDialog(int);   // C3: was Unk_SlotInventoryDialog* FUN_1405344f0 (calls cast back)
class Unk_SlotBreakManager;
Unk_SlotBreakManager* GetItemBreakManager();
Unk_SlotLapenTable* GetLapenshardTable();

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
void ASScrollPanel::SetContentsHeight(int nHeight)
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
void ASSlot::SetItemPet(int n)
{
    SetIntMember(s_strItemPet, n);
}

// @0x1409c1d20
void ASSlot::SetItemCash(int n)
{
    SetIntMember(s_strItemCash, n);
}

// @0x1409c1d60
void ASSlot::SetItemSkin(int n)
{
    SetIntMember(s_strItemSkin, n);
}

// @0x1409c1da0
void ASSlot::SetItemPcBang(bool b)
{
    SetIntMember(s_strItemPcBang, b != false);
}

// @0x1409c1e00
void ASSlot::SetItemVIP(int n)
{
    SetIntMember(s_strItemVIP, n);
}

// @0x1409c1e40
void ASSlot::SetItemWedding(int n)
{
    SetIntMember(s_strItemWedding, n);
}

// @0x1409c1e80
void ASSlot::SetItemLock(int n)
{
    SetIntMember(s_strItemLock, n);
}

// @0x1409c1ec0
void ASSlot::SetItemConditionLock(int n)
{
    SetIntMember(s_strItemConditionLock, n);
}

// @0x1409c1f00
void ASSlot::SetItemSeal(int n)
{
    SetIntMember(s_strItemSeal, n);
}

#ifndef MS2_HOOK_DLL
// @0x1409c1f40
void ASSlot::FUN_1409c1f40(CItem* pItem)
{
    int nLock = pItem->FUN_140528ca0();
    __int64 tUnlock = pItem->GetUnlockTime();
    if (nLock == 0 && tUnlock > GetServerTime())
    {
        SetBoolMember(s_strItemIconLock, false);
        SetBoolMember(s_strItemIconUnLock, true);
        return;
    }
    if (nLock == 1)
    {
        SetBoolMember(s_strItemIconLock, true);
        SetBoolMember(s_strItemIconUnLock, false);
    }
    else
    {
        SetBoolMember(s_strItemIconLock, false);
        SetBoolMember(s_strItemIconUnLock, false);
    }
}
#endif

// @0x1409c2050
void ASSlot::SetItemPiece(int n)
{
    SetIntMember(s_strItemPiece, n);
}

// @0x1409c2090
void ASSlot::SetGrayColor(int n)
{
    SetIntMember(s_strGrayColor, n);
}

// @0x1409c20d0
void ASSlot::SetItemEquip(int n)
{
    SetIntMember(s_strItemEquip, n);
}

// @0x1409c2110
void ASSlot::SetItemEquip2(int n)
{
    SetIntMember(s_strItemEquip2, n);
}

// @0x1409c2150
void ASSlot::SetItemSummon(int n)
{
    SetIntMember(s_strItemSummon, n);
}

// @0x1409c2190
void ASSlot::SetItemCountValue(unsigned n)
{
    if (n > 0)
        SetWStringMember(s_strItemCount, StringFormat(L"{0}", n));
}

// @0x1409c2200
void ASSlot::SetItemCountFromItem(CItem* pItem)
{
    SetWStringMember(s_strItemCount, pItem->FUN_140527840()->IsStackable() ? StringFormat(L"{0}", (unsigned)pItem->GetCount()) : CStringW(L""));
}

// @0x1409c2360
void ASSlot::SetItemColor(unsigned long nColor)
{
    FUN_1409c4990(s_strItemColor, nColor);
}

// @0x1409c23a0
void ASSlot::SetItemID(unsigned nItemId)
{
    SetMemberUInt(s_strItemID, nItemId);
}

// @0x1409c23e0
void ASSlot::SetItemGrade(int nGrade)
{
    FUN_1409adc90(s_strItemGrade, nGrade);
}

// @0x1409c2420
void ASSlot::SetItemPetRankAndDisableShadow(int nRank)
{
    FUN_1409adc90(s_strItemPetRank, nRank);
    DisableDropShadow();
}

// @0x1409c2470
void ASSlot::SetItemPetSkin(int n)
{
    SetIntMember(s_strItemPetSkin, n);
}

// @0x1409c24b0
void ASSlot::SetItemBothEquip(int n)
{
    SetIntMember(s_strItemBothEquip, n);
}

// @0x1409c24f0
void ASSlot::SetItemNew(int n)
{
    SetIntMember(s_strItemNew, n);
}

// @0x1409c2530
void ASSlot::SetItemEvent(int n)
{
    SetIntMember(s_strItemEvent, n);
}

// @0x1409c2570
void ASSlot::SetItemResultTag(int n)
{
    SetIntMember(s_strItemResultTag, n);
}

// @0x1409c25b0
void ASSlot::SetItemName(const CStringW& strName)
{
    SetWStringMember(s_strItemName, strName);
}

// @0x1409c2610
void ASSlot::DisableDropShadow()
{
    SetIntMember(s_strDropShadowDisable, 1);
}

// @0x1409c2650
void ASSlot::DisableDrag()
{
    SetIntMember(s_strDisableDrag, 1);
}

// @0x1409c2690
void ASSlot::SetLearn(int n)
{
    SetIntMember(s_strLearn, n);
}

// @0x1409c26d0
void ASSlot::SetIndex(int nIndex)
{
    SetIntMember(s_strIndex, nIndex);
}

// @0x1409c2710
void ASSlot::SetDisable(int n)
{
    SetIntMember(s_strDisable, n);
}

// @0x1409c2750
void ASSlot::SetIconPathString(const CString& strPath)
{
    SetIconPath(FUN_14016a730(strPath, 0));
}

// @0x1409c27c0
void ASSlot::SetIconPath(const CStringW& strPath)
{
    SetWStringMember(s_strIconPath, strPath);
}

// @0x1409c2820
void ASSlot::SetSlotHintString(const CString& strHint)
{
    SetSlotHint(FUN_14016a730(strHint, 0));
}

// @0x1409c2890
void ASSlot::SetSlotHint(const CStringW& strHint)
{
    SetWStringMember(s_strSlotHint, strHint);
}

// @0x1409c28f0
void ASSlot::SetItemGUID(const CStringW& strGuid)
{
    SetWStringMember(s_strItemGUID, strGuid);
}

// @0x1409c2950
void ASSlot::SetUgcTag(int nTag)
{
    if (nTag == 0)
        return;
    SetIntMember(s_strUgctag, nTag);
}

// @0x1409c2990
void ASSlot::SetItemCategory(const CStringW& strCategory)
{
    SetWStringMember(s_strItemCategory, strCategory);
}

// @0x1409c29f0
void ASSlot::SetSkillType(unsigned nType)
{
    SetMemberUInt(s_strSkilltype, nType);
}

// @0x1409c2a30
void ASSlot::SetSkillMaster(int n)
{
    SetIntMember(s_strSkillmaster, n);
}

// @0x1409c2a70
void ASSlot::SetUpgradeCondition(MS2Ptr<Unk_SlotSkillInfo> spSkill, int nPoints)
{
    SetBoolMember("upgradeCondition", UISkillBookTreeDialog::CanUpgrade(*(MS2Ptr<JobSkill>*)&spSkill, nPoints));
}

// @0x1409c2af0
void ASSlot::FUN_1409c2af0(CItem* pItem, void* pPlayer)
{
    if (pItem->IsLapenshard() != 0)
        return;
    if (pItem->FUN_140527840()->GetSkillId() == 0)
        return;
    Unk_SlotPc* pPc = (Unk_SlotPc*)efd::DynamicCast<Unk_AkoMyPC, PCBase>((PCBase*)pPlayer);
    if (pPc == NULL)
        return;
    ((class Unk_SlotSkillBook*)((class PC*)(class Unk_SlotPc*)(pPc))->GetJobSystem());
    MS2Ptr<SkillData> spRow(const_cast<MS2Ptr<SkillData>&&>(static_cast<const MS2Ptr<SkillData>&>(JobSystem::GetSkillData(pItem->FUN_140527840()->GetSkillId()))));   // moved through a reference to the temporary (2-slot chain, move ctor 0x1407f4f80)
    if (spRow.IsNull())
        return;
    MS2Ptr<SkillLevelData> spLevel(0);
    if (pPc->IsRiding() != 0)
        spLevel = spRow->GetLevelData(1);
    else
        spLevel = ((class Unk_SlotSkillBook*)((class PC*)(class Unk_SlotPc*)(pPc))->GetJobSystem())->vfunc_1(pItem->FUN_140527840()->GetSkillId());
    if (spLevel.IsNull())
        return;
    if (((Unk_SlotSkillRow*)spRow.operator->())->m_bCooldown == 0)
        return;
    SetRemainTime(((Unk_SlotSkillCooldowns*)((MyPC*)(Unk_SlotPc*)(pPc))->GetSkillSystem())->FUN_141765fe0(pItem->FUN_140527840()->GetSkillId(), 0));
    SetTotalTime(((SkillLevelData*)(spLevel).operator->())->GetCooldown());
    SetCooldownStrings();
}

// @0x1409c2dc0
void ASSlot::SetRemainTime(float fRemain)
{
    SetMemberFloat("remainTime", fRemain);
}

// @0x1409c2e00
void ASSlot::SetTotalTime(float fTotal)
{
    SetMemberFloat("totalTime", fTotal);
}

// @0x1409c2e40
void ASSlot::SetCooldownStrings()
{
    SetWStringMember("cooldownSecStr", GetStringCommon(0x5cb));
    SetWStringMember("cooldownMinStr", GetStringCommon(0x5ca));
    SetWStringMember("cooldownHourStr", GetStringCommon(0x5cc));
    SetWStringMember("cooldownDayStr", GetStringCommon(0x5ce));
}

// @0x1409c2f40
void ASSlot::SetItemEnchant(CItemEnchantInfo* pEnchant)
{
    if (pEnchant->FUN_14058c8a0() != 0)
    {
        int nLevel = pEnchant->GetLevel();
        if (nLevel > 0)
        {
            SetIntMember("enchantBroken", 1);
            SetIntMember("enchant", nLevel);
        }
    }
    else
    {
        int nLevel = pEnchant->GetLevel();
        if (nLevel > 0)
            SetIntMember("enchant", nLevel);
    }
}

// @0x1409c2fe0
void ASSlot::SetItemUnlimitedEnchant(Unk_ItemPlusInfo* pPlus)
{
    if (((UnlimitedEnchantInfo*)(Unk_ItemPlusInfo*)(pPlus))->GetLevel() > 0)
    {
        int nLevel = ((UnlimitedEnchantInfo*)(Unk_ItemPlusInfo*)(pPlus))->GetLevel();
        if (nLevel > 0)
            SetIntMember("unlimited", nLevel);
    }
}

// @0x1409c3040
void ASSlot::SetGemstoneLevel(MS2Ptr<CItemData> spData)
{
    if (spData == 0 || !spData->FUN_14053d840())
        return;
    unsigned short nLevel = FUN_140626f20(spData->GetItemId());
    if (nLevel == 0)
        return;
    FUN_1409c48f0("enchant", nLevel);
}

// @0x1409c30f0
void ASSlot::SetLapenshardLevel(MS2Ptr<CItemData> spData)
{
    if (spData == 0 || !spData->IsLapenshardType())
        return;
    unsigned short nLevel = GetLapenshardTable()->GetLevel(spData->GetItemId());
    if (nLevel == 0)
        return;
    FUN_1409c48f0("enchant", nLevel);
}

// @0x1409c31b0
void ASSlot::SetItemSeasonFromItem(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    if (spData == 0)
        return;
    SetItemSeason(spData);
}

// @0x1409c3290
void ASSlot::SetItemSeason(MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return;
    int nItemId = spData->GetItemId();
    int nSeason = spData->GetOpenGachaBoxParam0();
    ItemGachaBoxTable* pTable = TSingleton<ItemGachaBoxTable>::GetInstance();
    if (pTable != NULL && pTable->IsCoinItem(nItemId) == true)
        nSeason = pTable->GetRandomBoxIdByCoinItem(nItemId);
    if (nSeason == 0)
        return;
    if (!pTable->IsSeasonNumberOnIcon(nSeason))
        return;
    CStringW strSeason = FUN_1409e5320(nSeason);
    SetWStringMember("itemSeason", strSeason);
}

// @0x1409c33d0
void ASSlot::ClearEnchant()
{
    SetIntMember("enchant", 0);
}

// @0x1409c3400
void ASSlot::ClearGradeBG()
{
    SetIntMember("gradeBG", 0);
}

// @0x1409c3430
void ASSlot::SetItemQuestMark(CItem* pItem)
{
    switch (((class CQuestManager*)FUN_140764020())->FUN_1416ce6a0(MS2Ptr<CItem>(pItem)))
    {
    case 0:
        SetIntMember("questBeginAble", 1);
        break;
    case 1:
        SetIntMember("questProgress", 1);
        break;
    }
}

// @0x1409c34e0
void ASSlot::FUN_1409c34e0(CItem* pItem)
{
    Unk_SlotInventoryDialog* pInventory = reinterpret_cast<Unk_SlotInventoryDialog*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
    if (pInventory != NULL && pInventory->vfunc_55() == 0)
    {
        int nMode = pInventory->GetMode();
        switch (nMode)
        {
        case 0:
            return;
        case 1:
        case 2:
            if (reinterpret_cast<CItemBreakManager*>(GetItemBreakManager())->CanAddItem(MS2Ptr<CItem>(pItem)) == 0)
                SetItemSeal(1);
            break;
        case 3:
            if (((class CItemLockManager*)FUN_140535310())->CanAddItem(MS2Ptr<CItem>(pItem)) == 0)
                SetItemSeal(1);
            break;
        case 4:
            if (static_cast<unsigned int>(pItem->GetExtractionCount()) < 1)
                SetItemSeal(1);
            break;
        case 5:
        {
            if (pItem->IsPetItem() == 0)
            {
                SetItemSeal(1);
                break;
            }
            int nPetId = pItem->FUN_140527840()->GetPetId();
            MS2Ptr<CPetData> spPet = TSingleton<CPetDataTable>::GetInstance()->Find(nPetId);
            if (spPet.IsNull())
            {
                SetItemSeal(1);
                break;
            }
            if (!spPet->m_bEnablePetExtraction)
            {
                SetItemSeal(1);
                break;
            }
            break;
        }
        default:
            break;
        }
    }
}

// @0x1409c3750
void ASSlot::SetUseRightClick(bool b)
{
    SetBoolMember("useRightClick", b);
}

// @0x1409c3780
int ASSlot::GetItemID()
{
    Scaleform::GFx::Value v = GetMember(s_strItemID);
    int nItemId = v.GetUInt();
    return nItemId;
}

// @0x1409c37f0
int ASSlot::GetItemGrade()
{
    Scaleform::GFx::Value v = GetMember(s_strItemGrade);
    int nGrade = v.GetInt();
    return nGrade;
}

// @0x1409c3860
int ASSlot::FUN_1409c3860(CItem* pItem, void* pPlayer, int nFlags)
{
    if (pItem == NULL)
        return 0;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData.IsNull())
        return 0;
    if (nFlags & 1)
    {
        SetItemID(spData->GetItemId());
        SetItemGrade(pItem->GetRarity());
        SetIndex(pItem->GetSlot());
        if (((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0x8c))
        {
            if (spData->IsPetItem())
                SetItemPetRankAndDisableShadow(pItem->GetRarity());
        }
        else
        {
            SetItemPet(spData->IsPetItem());
        }
        int bPet = spData->FUN_14053e900() == 11;
        SetItemPetSkin(bPet);
        SetItemCash(spData->IsCashItem());
        SetItemSkin(spData->HasSkinType());
        SetItemPcBang(spData->IsPCBangItem());
        SetItemVIP(spData->FUN_14053d1f0());
        SetItemWedding(spData->HasWeddingLimit());
        SetIconPathString(pItem->GetIconPath());
        SetUgcTag(pItem->GetUgcTag());
        if (pPlayer != NULL)
            FUN_1409c2af0(pItem, pPlayer);
        SetItemEnchant(((CItemStatus*)(pItem->GetStatus()))->GetEnchant());
        SetItemUnlimitedEnchant(((CItemStatus*)(pItem->GetStatus()))->GetUnlimitedEnchantInfo());
        FUN_1409c1f40(pItem);
        SetItemPiece(spData->IsPieceItem());
        SetGemstoneLevel(spData);
        SetLapenshardLevel(spData);
        SetItemSeasonFromItem(MS2Ptr<CItem>(pItem));
    }
    if (nFlags & 0x400)
        DisableDrag();
    if (nFlags & 0x800)
        SetItemName(pItem->FUN_140527b10());
    if ((nFlags & 0x20) && pPlayer != NULL)
    {
        Unk_SlotPc* pPc = (Unk_SlotPc*)efd::DynamicCast<Unk_AkoMyPC, PCBase>((PCBase*)pPlayer);
        if (pPc != NULL)
        {
            BOOL bEquipped = FALSE;
            if (pItem->FUN_140527840()->FUN_14053cbc0())
            {
                MS2Ptr<CEquipItem> spEquip = reinterpret_cast<PC*>(pPc)->GetEquipByUid(pItem->GetItemUid());
                if (spEquip.get() != NULL)
                    bEquipped = TRUE;
            }
            if (bEquipped)
                SetItemEquip(bEquipped);
        }
    }
    if ((nFlags & 0x10000) && pItem->IsPetItem() != 0)
    {
        if (pItem->GetItemUid() == ((class CPetManager*)GetPetManager())->GetSummonUid())
            SetItemSummon(1);
    }
    if (nFlags & 2)
    {
        if (pItem->IsNew() != 0)
            SetItemNew(1);
        else if (pItem->IsEvent())
            SetItemEvent(1);
    }
    if (nFlags & 4)
    {
        SetMemberUInt("level", pItem->GetRequiredLevel());
        if (pPlayer != NULL)
        {
            Unk_SlotPc* pPc = (Unk_SlotPc*)efd::DynamicCast<Unk_AkoMyPC, PCBase>((PCBase*)pPlayer);
            if (pPc != NULL && pItem->FUN_140527840()->FUN_14053c8b0())
            {
                int nUsable = GetItemUsableState(pItem);
                if (nUsable == 1)
                    SetItemLock(1);
                else if (nUsable == 2)
                    SetDisable(1);
                else if (nUsable == 3)
                    SetItemConditionLock(1);
            }
        }
    }
    if (nFlags & 8)
    {
        if (pItem->FUN_140527840()->FUN_14053ec70()->FUN_140547190())
            SetItemColor(((CItemExtraData*)(Unk_UserProxyItemData*)(pItem->FUN_140527870()))->GetCurrentRgbComponent(0));
    }
    if (nFlags & 0x10)
        SetItemCountFromItem(pItem);
    if (nFlags & 0x80)
        SetSlotHintString(Name_14021c050(pItem->FUN_140526c30()));
    if (nFlags & 0x100)
    {
        CStringW strGuid = FUN_141b71910(pItem->GetItemUid());
        SetItemGUID(strGuid);
    }
    if (nFlags & 0x1000)
    {
        SetItemCategory(TSingleton<CStringTable>::GetInstance()->FUN_141812f60(pItem->GetItemId()));
    }
    if ((nFlags & 0x200) && pItem->FUN_140526970() != 0)
        SetItemResultTag(1);
    if (nFlags & 0x2000)
        DisableDropShadow();
    if (nFlags & 0x4000)
        SetItemQuestMark(pItem);
    if (nFlags & 0x8000)
        FUN_1409c34e0(pItem);
    if (nFlags & 0x20000)
        ClearEnchant();
    if (nFlags & 0x40000)
        ClearGradeBG();
    return 1;
}

// @0x1409c41f0
int ASSlot::SetEquipItem(CItem* pItem, void* pPc, int nSlot, int nFlags)
{
    if (pPc == NULL)
        return 0;
    if (pItem == NULL)
        return 0;
    if (FUN_1409c3860(pItem, pPc, nFlags) != 0)
    {
        MS2Ptr<CEquipItem> spMain = ((class Unk_SlotEquipSet*)((class PC*)(void*)(pPc))->GetEquipment())->GetItemAt(nSlot, 0);
        MS2Ptr<CEquipItem> spSub = ((class Unk_SlotEquipSet*)((class PC*)(void*)(pPc))->GetEquipment())->GetItemAt(nSlot, 1);
        if (pItem->HasSkin() != 0 && (spMain.get() ? true : false))
            SetItemBothEquip(1);
        else if (pItem->HasSkin() == 0 && (spSub.get() ? true : false))
            SetItemBothEquip(1);
        else
            SetItemBothEquip(0);
        return 1;
    }
    return 0;
}

// @0x1409c4360
int ASSlot::FUN_1409c4360(Unk_SlotSkillInfo* pSkill, unsigned nFlags)
{
    Unk_SlotPc* pPc = static_cast<Unk_SlotPc*>(((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPc == NULL)
        return 0;
    MS2Ptr<SkillData> spRow = ((SkillDataTable*)TSingleton<SkillDataTableCli>::GetInstance())->GetSkillData(((JobSkill*)(Unk_SlotSkillInfo*)(pSkill))->GetID());
    if (spRow.IsNull())
        return 0;
    if (nFlags & 1)
    {
        SetIconPathString(((Unk_SlotSkillData*)spRow.operator->())->m_strIcon);
        SetUpgradeCondition(MS2Ptr<Unk_SlotSkillInfo>(pSkill), pPc->GetRemainingSkillPoints(((JobSkill*)(Unk_SlotSkillInfo*)(pSkill))->GetJobLevel()));
    }
    if (nFlags & 0x400)
    {
        SetDisable(pSkill->m_bLearned == false);
        if (((SkillData*)(spRow).operator->())->FUN_1407e9de0())
            DisableDrag();
    }
    return 1;
}

// @0x1409c4510
int ASSlot::SetItemById(int nItemId, int nRarity, int nCount)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData.IsNull())
        return 0;
    SetItemID(nItemId);
    SetItemGrade(nRarity);
    if (!(!((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0x8c)))
    {
        if (spData->IsPetItem())
            SetItemPetRankAndDisableShadow(nRarity);
    }
    else
        SetItemPet(spData->IsPetItem());
    SetItemCash(spData->IsCashItem());
    SetItemSkin(spData->HasSkinType());
    SetItemPcBang(spData->IsPCBangItem());
    SetItemVIP(spData->FUN_14053d1f0());
    SetItemWedding(spData->HasWeddingLimit());
    SetIconPathString(spData->GetIconPath());
    SetItemName(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
    SetItemCountValue(nCount);
    DisableDrag();
    SetGemstoneLevel(spData);
    SetLapenshardLevel(spData);
    SetItemSeason(spData);
    SetItemPiece(spData->IsPieceItem());
    return 1;
}

// @0x1409c4860
int ASSlot::SetIconFromSource(Unk_SlotIconSource* pSource)
{
    if (pSource == NULL)
        return 0;
    SetIconPathString(pSource->m_strIcon);
    DisableDrag();
    return 1;
}

// @0x1409c48b0
int ASSlot::FUN_1409c48b0(const CString& strText)
{
    SetIconPathString(strText);
    DisableDrag();
    return 1;
}

// The ASObj::Set instances (one per value type) first used here.
// @0x1409c48f0
void ASObj::FUN_1409c48f0(const char* szName, short n)
{
    ASData data;
    data.AddInt((unsigned short)n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c4990
void ASObj::FUN_1409c4990(const char* szName, unsigned long n)
{
    ASData data;
    data.AddULong(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c4a30
void AScript::SetMemberFloat(const char* szName, float f)
{
    ASData data;
    data.AddFloat(f);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c4b20 TSingleton<item break manager>::GetInstance
Unk_SlotBreakManager* GetItemBreakManager()
{
    return reinterpret_cast<Unk_SlotBreakManager*>(TSingleton<CItemBreakManager>::s_instance);
}

// @0x1409c4b30 TSingleton<lapenshard table>::GetInstance
Unk_SlotLapenTable* GetLapenshardTable()
{
    return reinterpret_cast<Unk_SlotLapenTable*>(TSingleton<CItemLapenshardTable>::s_instance);
}

// ---- the merat market products (the ASItemSlot TU, 0x1409bbc30-0x1409c1ad0) ----

extern int DAT_143ab2914;                                       // the GM level of the account

// The product id: a premium (coin shop) product number or a UGC listing id.
// It has a constructor (not called here): without one a 16-byte pointer-free local would be a /GS buffer.
struct Unk_MeratOid
{
    Unk_MeratOid();
    int m_nPremiumId;                                           // +0x00
    __int64 m_nUgcId;                                           // +0x08
};
MS2_CHECK_SIZE(Unk_MeratOid, 0x10);

// The premium part of a market record (the coin shop product, 0x238 bytes at record +0x30).
class CDBPremiumProduct;
class CMeratMarketPremiumProduct;
CStringW GetStarPointText(CMeratMarketPremiumProduct* pProduct);                  // the star point text (uimeratmarketcommon.cpp)
CStringW GetLevelLimitText(CDBPremiumProduct* pProduct, const CStringW& strKey);   // the buy limit text (uimeratmarketcommon.cpp)
class CDBPremiumProduct   // C3: member view (real class not in this TU)
{
public:
    int FUN_14069fee0();
    bool IsRandomSaleExpired();
    __int64 GetPaybackPrice();
    CStringW GetName();
    CStringW GetSellDayText();
};
bool FUN_140ebfb90(CDBPremiumProduct* pProduct, bool bShowError);   // C3: the required achievement is done (uimeratmarketcommon.cpp)
class CMeratMarketPremiumProduct   // C3: member view (real class not in this TU)
{
public:
    int FUN_1406a1ee0();
    bool FUN_1406a1f50();
    int GetB0(int);
    int GetCurrency();
    CMsTime GetEndDate(int);
    __int64 GetPriceOf(int);
    __int64 GetSalePriceOf(int);
    CMsTime GetStartDate(int);
    bool IsBuyLimitReached();
    bool IsNotSelling(__int64 nOffset);
    bool IsNotEventPeriod(__int64 nOffset);
    bool IsEventPeriod(__int64 nOffset);
};
class Unk_MeratPremium
{
public:

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
    unsigned short m_nBuyLimit94;                                  // +0x94
    unsigned short m_nBuyLimit96;                                  // +0x96
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
class CUgcItemMusicNote   // C3: member view (def in ugcdef)
{
public:
    CStringA FUN_140894060() const;
};
class Unk_MeratUgcTemplate
{
public:
private:
    char m_pad_00[0xc0];
};

// The UGC part of a market record (a player's listing, at record +0x268).
class CUgcMarketProduct   // C3: member view (real class not in this TU)
{
public:
    int FUN_1408961a0() const;
    int IsMusicType() const;
    CStringW GetStr210();
};
class Unk_MeratUgc
{
public:
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

class CMeratMarketProduct   // C3: member view (meratmarketbasketinfo.h)
{
public:
    int GetItemId();
    int GetCurrency();
    int GetType();
    CStringW GetName();
    BOOL IsPremium();
    BOOL IsUgc();
};
// A market record (uiavatarbase.cpp has a partial local copy of this type).
class Unk_MeratEquipEntry : public CPtred
{
public:
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

#include "ms2/client/ms2/shopbannerinfo.h"   // ShopBannerInfo, the banner behind ASMeratMarketProductBase::m_spBanner

class Unk_MeratFilter : public CPtred
{
};

// The report-blind manager (blinded accounts) and the extra button helper.
class BlindManager   // C3: member view (real class not in this TU)
{
public:
    bool IsBlockedId(int, unsigned __int64);
};
class Unk_MeratBlindManager
{
public:
};
class Unk_MeratButtonHelper
{
public:
};
class PaybackManagerClient   // C3: member view (def in paybackmanagerclient)
{
public:
    void GetMenuButton(CStringW& strButton, bool& bShow);
};

int FUN_14069c3e0(int nCurrency);                               // the money type of a currency
int FUN_140222b90(int nGender);
CStringW FUN_141b71990(unsigned nValue);
CStringW FUN_14093bad0(int nId, int nGrade, CStringW strFormat);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_1418fef90(int nCurrency, __int64 nAmount);
CStringW FUN_1418fec90(int nCurrency, __int64 nAmount, int nArg);
CStringW FUN_1418fec00(int nCurrency, __int64 nAmount, bool bArg);
CStringW FUN_1409e3050(const CStringW& strKey, int n1, int n2);
CStringW GetStringCommonByKey(const CStringW& str);
CStringW FUN_140763e10(int value);
#include "ms2/placeholder/blockformat.h"
CString FUN_1407194b0(__int64 v);
CString FUN_140719530(unsigned __int64 v);
void FUN_141b70f90(const CMsTime& kTime, const CStringW& kFormat, CStringW& kOut);

// @0x1409c1730 TSingleton<report blind manager>::GetInstance
Unk_MeratBlindManager* GetBlindManager()
{
    return reinterpret_cast<Unk_MeratBlindManager*>(TSingleton<BlindManager>::s_instance);
}

// @0x1409c1740 TSingleton<extra button helper>::GetInstance
Unk_MeratButtonHelper* GetPaybackManager()
{
    return reinterpret_cast<Unk_MeratButtonHelper*>(TSingleton<PaybackManagerClient>::s_instance);
}

// @0x1409bbc30
MS2Ptr<ASMeratMarketProductBase> ASMeratMarketProductBase::CreateFromValue(Scaleform::GFx::Value& v, const int& nMovieId)
{
    if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() || ((Scaleform::GFx::Value*)(void*)(&v))->IsNull())
        return MS2Ptr<ASMeratMarketProductBase>(0);
    int nType = 0;
    Scaleform::GFx::Value vType;
    v.GetMember("asProductType", &vType);
    if (!((Scaleform::GFx::Value*)(void*)(&vType))->IsUndefined() && !((Scaleform::GFx::Value*)(void*)(&vType))->IsNull())
        nType = vType.GetInt();
    MS2Ptr<ASMeratMarketProductBase> sp(0);
    if (nType == 2)
    {
        if (((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0x108))
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
        if (((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0x108))
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
    SetMemberInt("asProductType", m_nProductType);
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
    SetWStringMember("productOID", reinterpret_cast<const Unk_MeratProductKey&>(oid).GetKeyString());
    SetBgPath(strBg);
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
    SetBoolMember("soldOut", bSoldOut);
}

// @0x1409bc480
void ASMeratMarketProductBase::SetIndex(int nIndex)
{
    m_nIndex = nIndex;
}

// @0x1409bc4a0
void ASMeratMarketProductBase::SetBgPath(const CString& strBg)
{
    SetStringMember("bgPath", strBg);
}

// @0x1409bc4f0
void ASMeratMarketProductBase::SetBanner(MS2Ptr<ShopBannerInfo> spBanner)
{
    m_spBanner = spBanner;
}

// @0x1409bc540
void ASMeratMarketProductBase::FUN_1409bc540(const int& nIndex)
{
    SetMemberUInt("index", nIndex);
}

// @0x1409bc580
void ASMeratMarketProductBase::SetProductOid(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    if (spEntry == 0)
        return;
    Unk_MeratOid oid = spEntry->m_oid;
    SetWStringMember("productOID", reinterpret_cast<const Unk_MeratProductKey&>(oid).GetKeyString());
}

// @0x1409bc630
void ASMeratMarketProductBase::SetProductOID(const Unk_MeratOid& oid)
{
    SetWStringMember("productOID", reinterpret_cast<const Unk_MeratProductKey&>(oid).GetKeyString());
}

// @0x1409bc680
int ASMeratMarketProductBase::GetIndex()
{
    return m_nIndex;
}

// @0x1409bc6a0
void ASMeratMarketProductBase::GetProductOID(Unk_MeratOid* pOid)
{
    CStringW strOid;
    TryGetWString("productOID", strOid);
    reinterpret_cast<Unk_MeratProductKey*>(pOid)->ParseOid(strOid);
}

// @0x1409bc720
unsigned int ASMeratMarketProductBase::FUN_1409bc720()
{
    return GetMember("index").GetUInt();
}

// @0x1409bc780
int ASMeratMarketProductBase::GetProductType()
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
bool ASMeratMarketProduct::vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt)
{
    if (spEntry.IsNull())
        return false;
    void* pPc = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pPc == NULL)
        return false;
    if (!ASMeratMarketProductBase::vfunc_1(spEntry, pOpt))
        return false;

    int nState = spEntry->FUN_1409c1760();
    Unk_MeratOid oid = spEntry->m_oid;
    MS2Ptr<Unk_MeratFilter> spFilter(0);
    if (pOpt != NULL)
        spFilter = pOpt->m_spFilter;
    unsigned int nJob = ((class PC*)(void*)(pPc))->GetGender();
    int nLevel = ((class PC*)(void*)(pPc))->GetJobGroupId();
    SetWStringMember("productOID", reinterpret_cast<const Unk_MeratProductKey&>(oid).GetKeyString());
    int nItemId = ((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->GetItemId();
    SetWStringMember("itemID", FUN_141b71990(nItemId));
    int bPremium = ((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->IsPremium();
    SetBoolMember("isPremium", bPremium != 0);
    if (nState == 0)
    {
        Unk_MeratPremium& premium = spEntry->m_premium;
        SetIntMember("sn", premium.m_nSn);
        SetIntMember("itemGrade", premium.m_nItemGrade);
        {
            MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
            if (spData)
            {
                CStringW strFunction = spData->function.name;
                SetStringMember("iconPath", spData->GetIconPath());
                SetWStringMember("itemName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
                if (spFilter.get() != NULL)
                {
                    bool bDisable = !((UIMeratMarketCommon::WeaponType*)(Unk_MeratFilter*)(spFilter.operator->()))->FUN_140ebb780(nJob, nLevel, spData) ? TRUE : FALSE;
                    SetBoolMember("disable", bDisable);
                }
                SetBoolMember("showRecipe", spData->HasMaidId());
                SetBoolMember("showPreview", strFunction == L"UGCMapPackage");
                if (spData->property.slotMax > 1)
                {
                    int nCount = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetB0(0);
                    SetIntMember("itemCount", nCount);
                }
            }
        }
        int nSaleTag = premium.m_nSaleTag;
        SetIntMember("saleTag", nSaleTag);
        SetBoolMember("specialBg", nSaleTag == 2);
        SetIntMember("isBlind", 0);
        FUN_1409c0e60("seller", L"");
        FUN_1409c0dc0("sellerCharSN", "");
        SetIntMember("ugctag", 0);
        bool bSoldOut = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->IsBuyLimitReached();
        SetBoolMember("soldOut", bSoldOut);
        if (!FUN_140ebfb90((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium), false))
        {
            CStringW strFormat = GetStringCommon(0x308);
            SetWStringMember("requireAchieve", FUN_14093bad0(premium.m_nAchieveId, premium.m_nAchieveGrade, strFormat));
        }
        bool bPcBang = ((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->FUN_14069fee0() > 0;
        SetBoolMember("isPcBang", bPcBang);
        CStringW strStar = GetStarPointText((CMeratMarketPremiumProduct*)&premium);
        if (!strStar.IsEmpty())
            SetWStringMember("starPoint", strStar);
    }
    else if (nState == 1)
    {
        Unk_MeratUgc& ugc = spEntry->m_ugc;
        SetStringMember("createtime", FUN_1407194b0(ugc.m_nCreateTime));
        FUN_1409adc90("itemGrade", ugc.m_nItemGrade);
        int nGender = FUN_140222b90(ugc.m_nGender);
        SetIntMember("gender", nGender);
        SetStringMember("sn", FUN_140719530(ugc.m_nAccountId));
        int nUgcItemId = ugc.m_nItemId;
        {
            MS2Ptr<CItemData> spData = FUN_14053f870(nUgcItemId);
            if (spData)
            {
                SetIntMember("ugctag", 1);
                if (spFilter.get() != NULL)
                {
                    bool bDisable = !((UIMeratMarketCommon::WeaponType*)(Unk_MeratFilter*)(spFilter.operator->()))->FUN_140ebb780(nJob, nLevel, spData) ? TRUE : FALSE;
                    SetBoolMember("disable", bDisable);
                }
            }
        }
        SetWStringMember("itemName", ((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->GetName());
        CString strIcon;
        if (((CUgcMarketProduct*)(Unk_MeratUgc*)&(ugc))->IsMusicType() != 0)
        {
            Unk_MeratUgcTemplate& tpl = ugc.m_template;
            strIcon = ((const CUgcItemMusicNote*)(Unk_MeratUgcTemplate*)&(tpl))->FUN_140894060();
        }
        else
            strIcon = ugc.m_look.GetLocalPath();
        SetStringMember("iconPath", strIcon);
        int nSaleState = ugc.m_nSaleState;
        int nResale = ugc.m_nResale;
        FUN_1409c10e0("saleState", nSaleState);
        CStringW strResale(L"$s_meratmarketreg_tooltip_btn_free_resale");
        if (nResale == 3)
            SetWStringMember("resaleTooltip", strResale);
        CStringW strSeller = ((CUgcMarketProduct*)(Unk_MeratUgc*)&(ugc))->GetStr210();
        SetWStringMember("seller", strSeller);
        SetStringMember("sellerCharSN", FUN_140719530(ugc.m_nSellerCharId));
        bool bSoldOut = ((CUgcMarketProduct*)(Unk_MeratUgc*)&(ugc))->FUN_1408961a0() == 1;
        SetBoolMember("soldOut", bSoldOut);
        bool bDebug = false;
        if (pOpt != NULL)
            bDebug = pOpt->m_bDebug;
        if (bDebug)
        {
            CStringW strSellCount = BlockFormat<int>(0xa27, ugc.m_nSaleCountTotal);
            SetWStringMember("sellCount", strSellCount);
            CMsTime tPeriod(ugc.m_nPeriod);
            CStringW strPeriod;
            CMsTime tZero(0);
            if (tPeriod == tZero)
                strPeriod = L"-";
            else
                FUN_141b70f90(tPeriod, GetStringCommon(0x9dd), strPeriod);
            SetWStringMember("period", strPeriod);
        }
        else
            SetIntMember("saleCountTotal", ugc.m_nSaleCountTotal);
        SetIntMember("saleCount", ugc.m_nSaleCount);
        if (((BlindManager*)(Unk_MeratBlindManager*)(GetBlindManager()))->IsBlockedId(3, spEntry->m_ugc.m_nAccountId))
            SetBoolMember("isBlind", true);
        if (bDebug)
        {
            BOOL bGm = DAT_143ab2914 >= 50;
            if (bGm)
                SetBoolMember("debug", true);
            else
                SetBoolMember("debug", false);
        }
    }
    FUN_1409bd940(spEntry);
    return true;
}

// @0x1409bd8e0
bool ASMeratMarketProduct::vfunc_4()
{
    return GetMember("soldOut").GetBool();
}

// @0x1409bd940
void ASMeratMarketProduct::FUN_1409bd940(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    if (spEntry == 0)
        return;
    int nCurrency = ((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->GetCurrency();
    __int64 nPrice = 0;
    __int64 nSalePrice = 0;
    bool bSale = false;
    if (((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->IsPremium() != 0)
    {
        Unk_MeratPremium& premium = spEntry->m_premium;
        nPrice = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetPriceOf(m_nIndex);
        nSalePrice = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetSalePriceOf(m_nIndex);
        bSale = nPrice > nSalePrice;
        if (premium.m_nSaleTag == 4 && nPrice > 0 && bSale)
        {
            int nRate = (int)((nPrice - nSalePrice) * 100 / nPrice);
            if (nRate > 0)
            {
                CStringW strText = FUN_14028dfa0(CStringW(L"s_common_saletag_sale"), nRate);
                SetWStringMember("saleTagText", strText);
            }
        }
    }
    else if (((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->IsUgc() != 0)
    {
        Unk_MeratUgc& ugc = spEntry->m_ugc;
        nPrice = ugc.m_nPrice;
        nSalePrice = nPrice;
        bSale = false;
    }
    int nType = FUN_14069c3e0(nCurrency);
    CStringW strPrice = bSale ? FUN_1409404f0(nPrice) : CStringW(L"");
    CStringW strSalePrice = FUN_1418fec00(nType, nSalePrice, false);
    SetWStringMember("price", strPrice);
    SetWStringMember("salePrice", strSalePrice);
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
    if (spEntry == 0 || ((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->IsPremium() == 0)
        return false;
    if (!ASMeratMarketProductBase::vfunc_1(spEntry, pOpt))
        return false;
    Unk_MeratOid oid = spEntry->m_oid;
    SetWStringMember("productOID", reinterpret_cast<const Unk_MeratProductKey&>(oid).GetKeyString());
    FUN_1409c0fa0("productUIType", 4);
    if (m_spBanner.get() != NULL)
    {
        FUN_1409c0dc0("type", "banner");
        SetBgPath(m_spBanner->m_strImgPath);
    }
    else
    {
        FUN_1409c0dc0("type", "normal");
        int nBg = spEntry->m_premium.m_nBg;
        if (nBg > 0)
        {
            CString strBg = Unk_SocketFormat("bg{0}", nBg);
            SetBgPath(strBg);
        }
        else
        {
            SetBgPath("");
        }
    }
    Unk_MeratPremium& premium = spEntry->m_premium;
    vfunc_7(spEntry);
    FUN_1409be940(premium);
    SetRemainAndSoldOut(premium);
    vfunc_8(premium);
    bool bPcBang = ((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->FUN_14069fee0() > 0;
    SetBoolMember("isPcBang", bPcBang);
    return true;
}

// @0x1409be1f0
bool ASMeratMarketLimitedProduct::vfunc_2(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    if (spEntry == 0)
        return false;
    Unk_MeratOid oid = spEntry->m_oid;
    SetWStringMember("productOID", reinterpret_cast<const Unk_MeratProductKey&>(oid).GetKeyString());
    Unk_MeratPremium& premium = spEntry->m_premium;
    FUN_1409be940(premium);
    SetRemainAndSoldOut(premium);
    vfunc_8(premium);
    vfunc_7(spEntry);
    bool bPcBang = ((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->FUN_14069fee0() > 0;
    SetBoolMember("isPcBang", bPcBang);
    return true;
}

// @0x1409be390
bool ASMeratMarketLimitedProduct::vfunc_4()
{
    return GetMember("soldOut").GetBool() || GetMember("soldOutBuyLimit").GetBool();
}

// @0x1409be4a0
bool ASMeratMarketLimitedProduct::vfunc_5()
{
    return GetMember("expired").GetBool();
}

// @0x1409be500
void ASMeratMarketLimitedProduct::vfunc_7(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    Unk_MeratPremium& premium = spEntry->m_premium;
    SetWStringMember("itemName", ((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetName());
    CStringW strDesc = GetStringCommonByKey(L"s_meratmarket_limited_desc");
    CStringW strStart;
    CStringW strEnd;
    const CStringW& strDateFormat = GetStringCommonByKey(L"s_meratmarket_limited_date");
    CMsTime tStart(premium.m_tStart);
    CMsTime tEnd(premium.m_tEnd);
    FUN_141b70f90(tStart, strDateFormat, strStart);
    FUN_141b70f90(tEnd, strDateFormat, strEnd);
    CStringW strUnused;
    CStringW strBuyLimit;
    if (premium.m_nBuyLimitKind != 0)
    {
        CStringW strFormat = FUN_1409e3050(L"s_meratmarket_limited_buylimit", premium.m_nBuyLimitKind, premium.m_nBuyLimitCount);
        strBuyLimit = FUN_14028dfa0(strFormat, premium.m_nBuyLimitArg);
    }
    CStringW strBuyLimit2;
    if (premium.m_nBuyLimit94 > 0 || premium.m_nBuyLimit96 > 0)
        strBuyLimit2 = GetLevelLimitText((CDBPremiumProduct*)&premium, L"s_meratmarket_limited_buylimit_");
    SetWStringMember("desc", StringFormat((const wchar_t*)strDesc, strStart, strEnd, premium.m_nLimitCount, strBuyLimit, strBuyLimit2));
}

// @0x1409be940
void ASMeratMarketLimitedProduct::FUN_1409be940(Unk_MeratPremium& premium)
{
    switch (premium.m_nType)
    {
    case 7:
        SetRandomPaybackPrice(premium);
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
void ASMeratMarketLimitedProduct::FUN_1409be9b0(Unk_MeratPremium& premium)
{
    bool bFree = false;
    unsigned int nFlags = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetCurrency();
    if (nFlags & 1)
    {
        int nPriceType = 1;
        __int64 nPrice = 0;
        __int64 nSalePrice = 0;
        bool bSale = false;
        nPrice = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetPriceOf(0);
        nSalePrice = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetSalePriceOf(0);
        bSale = nPrice > nSalePrice;
        int nType = FUN_14069c3e0(nPriceType);
        CStringW strPrice = bSale ? FUN_1409404f0(nPrice) : CStringW(L"");
        CStringW strSalePrice = FUN_1418fef90(nType, nSalePrice);
        SetWStringMember("price", strPrice);
        SetWStringMember("salePrice", strSalePrice);
        FUN_1409c1040("priceType", nPriceType);
        bFree = nPrice == 0 && nSalePrice == 0;
        SetBoolMember("showFreeText", bFree);
    }
    if (!bFree && (nFlags & 2))
    {
        int nPriceType = 2;
        __int64 nPrice = 0;
        __int64 nSalePrice = 0;
        bool bSale = false;
        nPrice = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetPriceOf(0);
        nSalePrice = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetSalePriceOf(0);
        bSale = nPrice > nSalePrice;
        int nType = FUN_14069c3e0(nPriceType);
        CStringW strPrice = bSale ? FUN_1409404f0(nPrice) : CStringW(L"");
        CStringW strSalePrice = FUN_1418fef90(nType, nSalePrice);
        SetWStringMember("price2", strPrice);
        SetWStringMember("salePrice2", strSalePrice);
        FUN_1409c1040("priceType2", nPriceType);
    }
}

// @0x1409bef00
void ASMeratMarketLimitedProduct::SetRandomPaybackPrice(Unk_MeratPremium& premium)
{
    unsigned int nFlags = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetCurrency();
    if (((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->IsRandomSaleExpired())
    {
        FUN_1409be9b0(premium);
    }
    else
    {
        SetMemberUInt("randomSaleID", premium.m_nRandomSaleId);
        SetWStringMember("randomExpiredDate", ((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetSellDayText());
        if (nFlags & 1)
        {
            int nPriceType = 1;
            int nType = FUN_14069c3e0(nPriceType);
            __int64 nSale = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetSalePriceOf(0);
            CStringW strSalePrice = FUN_1418fef90(nType, nSale);
            __int64 nPayback = ((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetPaybackPrice();
            CStringW strPayback = FUN_1418fec90(nType, nPayback, 0);
            FUN_1409c0e60("price", L"");
            SetWStringMember("salePrice", strSalePrice);
            SetWStringMember("randomPaybackPrice", FUN_14028dfa0<CStringW>(CStringW(L"s_meratmarket_random_payback"), strPayback));
            FUN_1409c1040("priceType", nPriceType);
        }
        if (nFlags & 2)
        {
            int nPriceType = 2;
            int nType = FUN_14069c3e0(nPriceType);
            __int64 nSale = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetSalePriceOf(0);
            CStringW strSalePrice = FUN_1418fef90(nType, nSale);
            __int64 nPayback = ((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetPaybackPrice();
            CStringW strPayback = FUN_1418fec90(nType, nPayback, 0);
            FUN_1409c0e60("price2", L"");
            SetWStringMember("salePrice2", strSalePrice);
            SetWStringMember("randomPaybackPrice2", FUN_14028dfa0<CStringW>(CStringW(L"s_meratmarket_random_payback"), strPayback));
            FUN_1409c1040("priceType2", nPriceType);
        }
    }
}

// @0x1409bf300
void ASMeratMarketLimitedProduct::FUN_1409bf300(Unk_MeratPremium& premium)
{
    unsigned int nFlags = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetCurrency();
    if (((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->IsRandomSaleExpired())
    {
        FUN_1409be9b0(premium);
    }
    else
    {
        SetMemberUInt("randomSaleID", premium.m_nRandomSaleId);
        SetWStringMember("randomExpiredDate", ((CDBPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetSellDayText());
        if (nFlags & 1)
        {
            int nPriceType = 1;
            int nType = FUN_14069c3e0(nPriceType);
            __int64 nPrice = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetPriceOf(0);
            CStringW strPrice = FUN_1409404f0(nPrice);
            __int64 nSale = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetSalePriceOf(0);
            CStringW strSalePrice = FUN_1418fef90(nType, nSale);
            SetWStringMember("price", strPrice);
            SetWStringMember("salePrice", strSalePrice);
            SetWStringMember("randomCouponRate", FUN_14028dfa0(CStringW(L"s_meratmarket_random_sale"), premium.m_nCouponRate));
            FUN_1409c1040("priceType", nPriceType);
        }
        if (nFlags & 2)
        {
            int nPriceType = 2;
            int nType = FUN_14069c3e0(nPriceType);
            __int64 nPrice = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetPriceOf(0);
            CStringW strPrice = FUN_1409404f0(nPrice);
            __int64 nSale = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetSalePriceOf(0);
            CStringW strSalePrice = FUN_1418fef90(nType, nSale);
            SetWStringMember("price2", strPrice);
            SetWStringMember("salePrice2", strSalePrice);
            SetWStringMember("randomCouponRate2", FUN_14028dfa0(CStringW(L"s_meratmarket_random_sale"), premium.m_nCouponRate));
            FUN_1409c1040("priceType2", nPriceType);
        }
    }
}

// @0x1409bf780
void ASMeratMarketLimitedProduct::SetRemainAndSoldOut(Unk_MeratPremium& premium)
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
            if (nRemain == 0)
            {
                bSoldOut = true;
                strText = GetStringCommonByKey(L"s_meratmarket_limited_soldout");
            }
            else
                strText = FUN_14028dfa0<CStringW>(CStringW(L"s_meratmarket_limited_remain"), FUN_140763e10(nRemain));
        }
    }
    else if (premium.m_nType == 6 && premium.m_nLimitCount > 0)
    {
        int nRemain = premium.m_nLimitCount - premium.m_nSoldCountHome < 0 ? 0 : premium.m_nLimitCount - premium.m_nSoldCountHome;
        if (nRemain == 0)
        {
            bSoldOut = true;
            strRemain = GetStringCommonByKey(L"s_meratmarket_limited_soldout");
        }
        else
            strRemain = FUN_14028dfa0<CStringW>(CStringW(L"s_meratmarket_limited_remain"), FUN_140763e10(nRemain));
    }
    if (!strRemain.IsEmpty())
        SetWStringMember("remain", strRemain);
    bool bSold = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->IsBuyLimitReached();
    if (premium.m_nType == 0 || premium.m_nType == 1 || premium.m_nType == 2)
        SetBoolMember("soldOut", bSold);
    else
    {
        SetBoolMember("soldOut", bSoldOut);
        SetBoolMember("soldOutBuyLimit", bSold);
    }
}

// @0x1409bfc20
void ASMeratMarketLimitedProduct::vfunc_8(Unk_MeratPremium& premium)
{
    bool bExpired = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->IsNotSelling(0);
    SetBoolMember("expired", bExpired);
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
bool ASMeratMarketHomeProduct::vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt)
{
    if (spEntry == 0 || ((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->IsPremium() == 0)
        return false;
    if (!ASMeratMarketLimitedProduct::vfunc_1(spEntry, pOpt))
        return false;
    int nKind = ((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->GetType();
    int nUIType = 0;
    switch (nKind)
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
    SetIntMember("productUIType", nUIType);
    FUN_1409c05d0(spEntry, pOpt);
    Unk_MeratPremium& premium = spEntry->m_premium;
    bool bPreview = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->IsEventPeriod(0);
    SetBoolMember("isPreview", bPreview);
    if (!bPreview)
    {
        if (((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->FUN_1406a1ee0() != 0)
        {
            CStringW strText;
            bool bShow = false;
            int nExtra = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->FUN_1406a1ee0();
            switch (nExtra)
            {
            case 1:
                ((PaybackManagerClient*)GetPaybackManager())->GetMenuButton(strText, bShow);
                break;
            case 2:
                strText = L"$s_meratmarket_text_changeable_extra_button_label";
                bShow = true;
                break;
            }
            SetWStringMember("extraButtonText", strText);
            SetBoolMember("showExtraButton", bShow);
            return true;
        }
        int nCoinShopId = spEntry->m_premium.m_nCoinShopId;
        int nOpen = TSingleton<ItemGachaBoxTable>::GetInstance()->FUN_14059e6a0(nCoinShopId);
        if (nOpen == 0)
            return true;
        FUN_1409c0e60("extraButtonText", L"$s_itemgacha_dialog_coinshop_open");
        SetBoolMember("showExtraButton", true);
    }
    return true;
}

// @0x1409c00e0
bool ASMeratMarketHomeProduct::vfunc_4()
{
    return GetMember("soldOutBuyLimit").GetBool();
}

// @0x1409c0140
void ASMeratMarketHomeProduct::vfunc_6(bool bSoldOut)
{
    SetBoolMember("soldOutBuyLimit", bSoldOut);
}

// @0x1409c0170
void ASMeratMarketHomeProduct::vfunc_7(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    Unk_MeratPremium& premium = spEntry->m_premium;
    CStringW strDesc;
    if (premium.m_nType == 6)
        strDesc = "";
    else if (((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->FUN_1406a1f50() && !((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->IsEventPeriod(0) && !((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetStartDate(0).IsNull() &&
             !((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetEndDate(0).IsNull())
    {
        CStringW strFormat = GetStringCommonByKey(L"s_meratmarket_home_desc_period");
        CStringW strStart;
        CStringW strEnd;
        const CStringW& strDateFormat = GetStringCommonByKey(L"s_meratmarket_limited_date");
        CMsTime tStart = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetStartDate(0);
        CMsTime tEnd = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetEndDate(0);
        FUN_141b70f90(tStart, strDateFormat, strStart);
        FUN_141b70f90(tEnd, strDateFormat, strEnd);
        strDesc = StringFormat((const wchar_t*)strFormat, strStart, strEnd);
    }
    if (!strDesc.IsEmpty())
        SetWStringMember("desc", strDesc);
}

// @0x1409c0430
void ASMeratMarketHomeProduct::vfunc_8(Unk_MeratPremium& premium)
{
    if (premium.m_nType == 6)
    {
        CMsTime tNow(GetServerTime());
        if (tNow < premium.m_tSaleStart)
        {
            FUN_1409c1180("startNextSaleRemainTime", premium.m_tSaleStart.Get() - tNow.Get());
            if (premium.m_nFirstSale == 1)
                SetBoolMember("firstSaleTimeBefore", true);
        }
        else
        {
            FUN_1409c1180("endSaleRemainTime", premium.m_tSaleEnd.Get() - tNow.Get());
            FUN_1409c1180("startNextSaleRemainTime", premium.m_tNextSale.Get() - tNow.Get());
        }
    }
    else
    {
        bool bExpired = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->IsNotSelling(0) && ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->IsNotEventPeriod(0);
        SetBoolMember("expired", bExpired);
    }
}

// @0x1409c05d0
void ASMeratMarketHomeProduct::FUN_1409c05d0(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt)
{
    if (spEntry == 0)
        return;
    Unk_MeratPremium& premium = spEntry->m_premium;
    void* pPc = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0();
    SetIntMember("sn", premium.m_nSn);
    SetIntMember("itemGrade", premium.m_nItemGrade);
    MS2Ptr<Unk_MeratFilter> spFilter(0);
    if (pOpt != NULL)
        spFilter = pOpt->m_spFilter;
    unsigned int nJob = ((class PC*)(void*)(pPc))->GetGender();
    int nLevel = ((class PC*)(void*)(pPc))->GetJobGroupId();
    int nItemId = ((CMeratMarketProduct*)(Unk_MeratEquipEntry*)(spEntry.operator->()))->GetItemId();
    const int& nKey = nItemId;
    MS2Ptr<CItemData> spData = FUN_14053f870(nKey);
    if (spData)
    {
        CStringW strFunction = spData->function.name;
        SetStringMember("iconPath", spData->GetIconPath());
        if (spFilter.get() != NULL)
        {
            bool bDisable = !((UIMeratMarketCommon::WeaponType*)(Unk_MeratFilter*)(spFilter.operator->()))->FUN_140ebb780(nJob, nLevel, spData) ? TRUE : FALSE;
            SetBoolMember("disable", bDisable);
        }
        if (spData->property.slotMax > 1)
        {
            int nCount = ((CMeratMarketPremiumProduct*)(Unk_MeratPremium*)&(premium))->GetB0(0);
            SetIntMember("itemCount", nCount);
        }
        if (spData->HasOpenGachaBoxFunction())
        {
            int nSeason = TSingleton<ItemGachaBoxTable>::GetInstance()->GetSeasonByCoinOrBoxItemId(spData->GetOpenGachaBoxParam0());
            SetMemberUInt("itemSeason", nSeason);
        }
    }
    SetBoolMember("ugctag", false);
}

// @0x1409c0d20
void AScript::SetMemberUInt(const char* szName, unsigned int n)
{
    ASData data;
    data.AddUInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c0dc0
void ASObj::FUN_1409c0dc0(const char* szName, const char* szValue)
{
    ASData data;
    data.AddString(szValue);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c0e60
void ASObj::FUN_1409c0e60(const char* szName, const wchar_t* szValue)
{
    ASData data;
    data.AddWString(szValue);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c0f00
void ASMeratMarketProductBase::SetMemberInt(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c0fa0
void ASMeratMarketProductBase::FUN_1409c0fa0(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c1040
void ASMeratMarketProductBase::FUN_1409c1040(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c10e0
void ASMeratMarketProductBase::FUN_1409c10e0(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c1180
void ASObj::FUN_1409c1180(const char* szName, __int64 n)
{
    ASData data;
    data.AddInt64(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409c1640
// Parse the key from its text: "P<n>" (premium) or "U<n>" (UGC).
void Unk_MeratProductKey::ParseOid(CStringW strOid)
{
    Reset();
    if (strOid.GetLength() <= 2)
        return;
    wchar_t chKind = strOid[0];
    CStringW strNumber = strOid.Mid(2);
    if (chKind == L'P')
        m_nPremiumId = _wtoi(strNumber);
    else if (chKind == L'U')
        m_nUgcId = _wtoi64(strNumber);
}
