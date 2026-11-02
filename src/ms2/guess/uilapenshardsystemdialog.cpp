// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Lapenshard system window (UILapenshardSystemDialog and its
// "equip" / "upgrade" pages and sections) and the Lapenshard shield bar HUD; see unit_140c5d230.h. Sibling of the pet system
// dialog's pages (client\ms2\tabcontentspetcompose.cpp). Names of the classes are the RTTI names; the member names are invented.
// MS2-UNIT: unit_140c5d230
// MS2-RANGE: 0x140c5d230-0x140c6b300 .text$mn
// MS2-RANGE: 0x1400ce050-0x1400ce500 .text$di
// MS2-PIN: memmove_s 0x140c607d0
// MS2-PIN: ??0?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x140c69c40
// MS2-PIN: ??1?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x140c6a090
// MS2-PIN: ?CallConstructors@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@CAXPEAH_K@Z 0x140c6a630
// MS2-PIN: ?CallDestructors@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@CAXPEAH_K@Z 0x140c6a6a0
// MS2-PIN: ??A?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@QEAAAEAH_K@Z 0x140c6a330
// MS2-PIN: ?GrowBuffer@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@AEAA_N_K@Z 0x140c6a7e0
// MS2-PIN: ?SetCount@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@QEAA_N_KH@Z 0x140c6abf0
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@V?$CElementTraits@V?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@@ATL@@@ATL@@QEAA@XZ 0x140c62ab0
// MS2-PIN: ??0?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@QEAA@AEBV0@@Z 0x140c62990
// MS2-PIN: ??1?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@QEAA@XZ 0x140c62af0
// MS2-PIN: ??0?$MS2Ptr@VCItemLapenshardData@@@@QEAA@AEBV0@@Z 0x140c69f50
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VLapenshardSystemTabPanelBase@@@@QEAA@PEAVLapenshardSystemTabPanelBase@@@Z 0x140c5e420 ; prop
// MS2-PIN: ??$Unk_Fmt2@HH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH1@Z 0x140c60060 ; unique
// MS2-PIN: ??_EUILapenshardShieldBar@@WHA@EAAPEAXI@Z 0x140c6075c ; unique
// MS2-PIN: ??_GUILapenshardShieldBar@@UEAAPEAXI@Z 0x140c60770 ; unique
// MS2-PIN: ?FUN_140c62500@UILapenshardSystemDialog@@QEBAHXZ 0x140c62500 ; unique
// MS2-PIN: ??0?$MS2Ptr@VLapenshardSystemTabContents@@@@QEAA@PEAVLapenshardSystemTabContents@@@Z 0x140c62a80 ; prop
// MS2-PIN: ??8?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@QEBA_NPEAVTabInfo@UILapenshardSystemDialog@@@Z 0x140c62c70 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCreateParam@ItemSlotBag@@@@QEBAPEAVCreateParam@ItemSlotBag@@XZ 0x140c62d30 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140c62fe0 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@V?$CElementTraits@V?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@@ATL@@@ATL@@QEBA_KXZ 0x140c63020 ; unique
// MS2-PIN: ?vfunc_48@UILapenshardSystemDialog@@UEAAHXZ 0x140c63030 ; unique
// MS2-PIN: ?FUN_140c68e20@UILapenshardUpgradeTab@@QEAAHXZ 0x140c68e20 ; unique
// MS2-PIN: ?FUN_140c68fd0@UILapenshardUpgradeTab@@QEAAHXZ 0x140c68fd0 ; unique
// MS2-PIN: ??$?8PEAVLapenshardIngredientItemSlotBagPanel@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140c69940 ; prop
// MS2-PIN: ??$?8PEAVLapenshardUpgradeSlotPanel@@P80@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@YA_NAEBU?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@0@0@Z 0x140c69990 ; prop
// MS2-PIN: ??$?8PEAVLapenshardUpgradeSlotPanel@@P80@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@YA_NAEBU?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@0@0@Z 0x140c699e0 ; prop
// MS2-PIN: ??0?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@IMMMI@Z 0x140c69c80 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140c69d70 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140c69dc0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@QEAA@AEBV01@@Z 0x140c69e10 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@QEAA@AEBU?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@Z 0x140c69e60 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@QEAA@AEBV01@@Z 0x140c69eb0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@QEAA@AEBU?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@Z 0x140c69f00 ; prop
// MS2-PIN: ??1?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x140c6a0d0 ; unique
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x140c6a100 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEAA@XZ 0x140c6a120 ; prop
// MS2-PIN: ??1Unk_LsPktB@@QEAA@XZ 0x140c6a2b0 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140c6a380 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEAAPEAXI@Z 0x140c6a3c0 ; prop
// MS2-PIN: ??_GLapenshardIngredientItemSlotBagPanel@@UEAAPEAXI@Z 0x140c6a480 ; prop
// MS2-PIN: ??_GLapenshardSourceItemSlotBagPanel@@UEAAPEAXI@Z 0x140c6a4c0 ; prop
// MS2-PIN: ??_GLapenshardUpgradeSlotPanel@@UEAAPEAXI@Z 0x140c6a500 ; prop
// MS2-PIN: ??_GUILapenshardUpgradeTab@@UEAAPEAXI@Z 0x140c6a540 ; prop
// MS2-PIN: ?Add@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@QEAA_KAEBH@Z 0x140c6a580 ; unique
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x140c6a6e0 ; unique
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x140c6a700 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140c6a720 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEBA_N_KAEAH@Z 0x140c6a9b0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@H@ATL@@SAXPEAH0_K@Z 0x140c6aa10 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@QEAAXXZ 0x140c6aa50 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x140c6aa70 ; unique
// MS2-PIN: ?RemoveKey@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA_N_K@Z 0x140c6ab80 ; unique
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXMMM_N@Z 0x140c6ad80 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c6ae30 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c6ae90 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c6aef0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140c6af50 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z 0x140c6af90 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@UEAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z 0x140c6afd0 ; unique
// MS2-PIN: ??$Call@VLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140c6b010 ; unique
// MS2-PIN: ??$Call@VLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@CAXAEAU?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@AEAVItemInfoSlot@@AEAVASSlot@@@Z 0x140c6b040 ; prop
// MS2-PIN: ??$Call@VLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@CAXAEAU?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@AEAVItemInfoSlot@@AEAVASTooltip@@@Z 0x140c6b080 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVLapenshardIngredientItemSlotBagPanel@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c6b0c0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c6b120 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVLapenshardUpgradeSlotPanel@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c6b180 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#define MS2_ASUICOMPONENT_SLOTS   // ASTileList::vfunc_24 (validateNow)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astilelist.h"

#include "ms2/unnamed/unit_140c5d230.h"

#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/placeholder/uientityeventdispatcher.h"

// The tooltip callback's Delegate base is first emitted here.
// @0x140c69f90
template<> Delegate<void(ItemInfoSlot&, ASTooltip&)>::DelegateImplBase::DelegateImplBase() {}
// @0x140c6a160
template<> Delegate<void(ItemInfoSlot&, ASTooltip&)>::DelegateImplBase::~DelegateImplBase() {}

// @0x140c628f0 TPtr<> copy: AddRef through the pointee's slot 1
// (the pointee's first two virtual slots; Unk_UISwfEntity_25 itself is incomplete here)
class Unk_SwfRefView { public: virtual void vfunc_0(); virtual void vfunc_1(); };
template <> inline TPtr<Unk_UISwfEntity_25>::TPtr(const TPtr& o)
{
    if (o.get() != 0)
        reinterpret_cast<Unk_SwfRefView*>(o.operator->())->vfunc_1();
    m_p = o.get();
}

#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/commonfiles/itemlapensharddata.h"
#include "ms2/commonfiles/contentshutdown.h"
#include "ms2/client/ms2/lapenshardslotbag.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/placeholder/cquestmanagercommon.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/gfxui/notifyhandler.h"   // C3: Unk_NotifyContext::FUN_1422c8e90/f10/f70
#include "ms2/placeholder/ascorelist.h"   // C3: ASCoreList::SetSelectedIndex

// return types of the getters this unit calls
class Unk_InventoryListener;
class Unk_SingletonObj1;
class Unk_SlotLapenTable;
struct Unk_BanConfig;
// ---- statics of the headers this unit includes (three translation units folded into one: the .di of each constructs them
// in this order; the third and fourth sets also carry a CMyPCKeyInputController) ----

void FUN_142ca31f0();
void FUN_142ca3220();
void FUN_142ca3240();
void FUN_142ca3280();
void FUN_142ca32b0();
void FUN_142ca32d0();
void FUN_142ca3310();
void FUN_142ca3330();
void FUN_142ca3360();
void FUN_142ca3380();
void FUN_142ca33c0();
struct Unk_RegMarker {};

namespace Unk_LsHeaderA
{
// @0x1400ce050
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400ce110
static CString s_strSkill = "skill";
// @0x1400ce140
static CString s_strStun = "stun";
#ifndef MS2_HOOK_DLL
// @0x1400ce170
static Unk_1402a9d70 s_marker(17, 0.75f, 0.25f, 2.25f, 10);   // atexit thunk FUN_142ca3260
#endif
}

namespace Unk_LsHeaderB
{
// @0x1400ce1c0
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400ce280
static CString s_strSkill = "skill";
// @0x1400ce2b0
static CString s_strStun = "stun";
#ifndef MS2_HOOK_DLL
// @0x1400ce2e0
static Unk_1402a9d70 s_marker(17, 0.75f, 0.25f, 2.25f, 10);   // atexit thunk FUN_142ca32f0
#endif
// @0x1400ce330
static UICommon::CMyPCKeyInputController s_keyInput;
}

namespace Unk_LsHeaderC
{
// @0x1400ce360
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400ce420
static CString s_strSkill = "skill";
// @0x1400ce450
static CString s_strStun = "stun";
#ifndef MS2_HOOK_DLL
// @0x1400ce480
static Unk_1402a9d70 s_marker(17, 0.75f, 0.25f, 2.25f, 10);   // atexit thunk FUN_142ca33a0
#endif
// @0x1400ce4d0
static UICommon::CMyPCKeyInputController s_keyInput;
}

// ---- unit-local views of the exe objects and unrecovered callees ----------------------------------------------------

class Unk_LsWorld { public: MyPC* FUN_141bd0cc0(); };                   // the local player


typedef MS2Ptr<CItem> ItemPtr;
typedef LapenshardItemArray ItemArray;

// The item bag registry (a name -> item list map of the inventory dialogs).
void FUN_140a704a0(const CString& strBag);                                   // unbind the bag name
void FUN_140a702f0(const CString& strBag, const ItemArray& items, int nFlag);     // bind the bag name to the items
// The inventory: the bag lookup used by FUN_140c60920 below.
void FUN_140c60920(ItemArray* pOut, int bCheckUse, int bWithBound, int bWithEquipped, int bTableOnly, int nKind, __int64 nExcludeUid);   // 0x140c60920

// @0x140c610a0
static void BindBag(CString* pstrBag, ItemArray* pItems, int nFlag)
{
    FUN_140a704a0(*pstrBag);
    FUN_140a702f0(*pstrBag, *pItems, nFlag);
}

// ---- LapenshardSystemTabPanelBase / LapenshardSystemTabContents (the shared defaults) ----

// @0x140c5e4d0
LapenshardSystemTabPanelBase::LapenshardSystemTabPanelBase()
{
}

// @0x140c5e620
LapenshardSystemTabPanelBase::~LapenshardSystemTabPanelBase()
{
}

// @0x140c5e5f0
LapenshardSystemTabContents::~LapenshardSystemTabContents()
{
}

// @0x140c5ec40
void LapenshardSystemTabPanelBase::vfunc_1()
{
}

// @0x140c5eca0
void LapenshardSystemTabPanelBase::vfunc_2()
{
}

// @0x140c5e900
void LapenshardSystemTabPanelBase::vfunc_3()
{
}

// @0x140c5e8f0
void LapenshardSystemTabPanelBase::vfunc_4()
{
}

// @0x140c5ed60
void LapenshardSystemTabPanelBase::vfunc_5(int nEvent)
{
    (void)nEvent;
}

// @0x140c5ed00
void LapenshardSystemTabPanelBase::vfunc_6(MS2Ptr<CItem> spA, MS2Ptr<CItem> spB)
{
    (void)spA;
    (void)spB;
}

// @0x140c5ec20
void LapenshardSystemTabPanelBase::vfunc_7(int a1)
{
}

// @0x140c5ec70
int LapenshardSystemTabPanelBase::vfunc_8(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    (void)szMethod;
    (void)pArgs;
    (void)nArgs;
    return 0;
}

// @0x140c5ec30
void LapenshardSystemTabContents::vfunc_1()
{
}

// @0x140c5ed50
void LapenshardSystemTabContents::vfunc_2(int nEvent)
{
    (void)nEvent;
}

// @0x140c5ec90
void LapenshardSystemTabContents::vfunc_4()
{
}

// @0x140c5ed30
void LapenshardSystemTabContents::vfunc_5(void* a1, void* a2, void* a3)
{
    (void)a1;
    (void)a2;
    (void)a3;
}

// @0x140c5ec50
int LapenshardSystemTabContents::vfunc_6(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    (void)szMethod;
    (void)pArgs;
    (void)nArgs;
    return 0;
}

// @0x140c5ecb0
void LapenshardSystemTabContents::vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4)
{
    (void)a1;
    (void)a3;
    (void)a4;
}

// @0x140c5ece0
void LapenshardSystemTabContents::vfunc_9(CInPacket& packet)
{
    (void)packet;
}

// @0x140c5ecf0
void LapenshardSystemTabContents::vfunc_10(void* a1, bool b)
{
    (void)a1;
    (void)b;
}

// @0x140c608f0
MyPC* LapenshardSystemTabContents::vfunc_11()
{
    return ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
}

// ---- LapenshardItemSlotBagPanel ----

// @0x140c5d230
LapenshardItemSlotBagPanel::LapenshardItemSlotBagPanel(UILapenshardEquipTab* pTab)
    : m_pTab(pTab)
{
}

// @0x140c5d290
void LapenshardItemSlotBagPanel::vfunc_1()
{
    vfunc_4();
}

// @0x140c5d2c0
void LapenshardItemSlotBagPanel::vfunc_2()
{
    vfunc_4();
}

// @0x140c5d2f0
void LapenshardItemSlotBagPanel::vfunc_3()
{
    if (m_pTab == 0)
        return;
    vfunc_4();
    m_strBag = "LapenshardItemSlotBag";
    if (MS2Ptr<ASTileList> bag = m_ui->FUN_140accef0<ASTileList>("m_itemBag"))
    {
        bag->Invoke("resetRenderer");
        reinterpret_cast<ASCoreList*>(bag.operator->())->SetSelectedIndex(0xffffffff);
        ItemArray items;
        FUN_140c60920(&items, 1, 1, 0, 0, 0, 0);
        BindBag(&m_strBag, &items, 1);
        bag->FUN_1422dd1d0();
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(true);
    }
}

// @0x140c5d530
void LapenshardItemSlotBagPanel::vfunc_4()
{
    if (!m_strBag.IsEmpty())
    {
        FUN_140a704a0(m_strBag);
        m_strBag.Empty();
    }
}

// @0x140c5d580
void LapenshardItemSlotBagPanel::vfunc_5(int nEvent)
{
    switch (nEvent)
    {
    case 0:
    case 1:
    case 2:
        vfunc_3();
    }
}

// ---- LapenshardEquipSlotPanel ----

// @0x140c5d5c0
LapenshardEquipSlotPanel::LapenshardEquipSlotPanel(UILapenshardEquipTab* pTab)
    : m_pTab(pTab)
{
}

// @0x140c5d620
void LapenshardEquipSlotPanel::vfunc_1()
{
    vfunc_4();
}

// @0x140c5d650
void LapenshardEquipSlotPanel::vfunc_2()
{
    vfunc_4();
}

// ---- unit-local views, second part ----

// The bag registry entry of a name (FUN_140c610e0): per-slot ids.
LapenshardSlotBag* FUN_140a703d0(const CString& strBag);                          // the bag of a name
class Unk_SlotLapenTable* FUN_1409c4b30();   // C3: was FUN_1409c4b30
struct Unk_LsSlotArg { unsigned m_n; Unk_LsSlotArg() : m_n(0) {} };      // 0x140c5e480
LapenshardSlotBag* FUN_140a70b70(NotifyContext::BindData* pEntry);
ItemInfoSlot* FUN_140c69ab0(NotifyContext::BindData* pEntry);                              // the bag component (class id 0x6200084) of a registry entry
UILapenshardSystemDialog* FUN_140a6ff40(int nId);                      // the open Lapenshard window
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
int FUN_140c62520();                                                    // the window may be used (not in battle / disabled field)

// @0x140c610e0
static LapenshardSlotBag* BindBagReg(CString* pstrBag)
{
    FUN_140a704a0(*pstrBag);
    return FUN_140a703d0(*pstrBag);
}

// ---- LapenshardEquipSlotPanel ----

// @0x140c5d680
void LapenshardEquipSlotPanel::vfunc_3()
{
    if (m_pTab == 0)
        return;
    vfunc_4();
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    m_strBag = "LapenshardEquipSlotBag";
    LapenshardSlotBag* pReg = BindBagReg(&m_strBag);
    if (pReg == 0)
        return;
    for (unsigned i = 1; i < 7; ++i)
    {
        CString strName;
        strName.Format("m_equipSlot%d", i);
        int nIndex = i - 1;
        MS2Ptr<ASMovieClip> slot = m_ui->FUN_1409b4560(strName);
        if (slot.get() != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cba60("bindID", pReg->vfunc_15(nIndex));
            obj.FUN_1409c0d20("slotIndex", i);
            int bEquip = pPlayer->GetLapenshardItemId((Unk_MyPCLapenSlot)i) ? 1 : 0;
            obj.FUN_1407cb9c0("isEquip", bEquip);
            slot->FUN_140acd1f0("setData", AScript(obj));
        }
    }
}

// @0x140c5d900
void LapenshardEquipSlotPanel::vfunc_4()
{
    if (!m_strBag.IsEmpty())
    {
        FUN_140a704a0(m_strBag);
        m_strBag.Empty();
    }
}

// @0x140c5d950
void LapenshardEquipSlotPanel::vfunc_5(int nEvent)
{
    switch (nEvent)
    {
    case 0:
    case 1:
    case 2:
        vfunc_3();
        break;
    case 10:
        FUN_140c5d9c0(1);
        break;
    case 0xb:
        FUN_140c5d9c0(0);
    }
}

// @0x140c5d9c0
void LapenshardEquipSlotPanel::FUN_140c5d9c0(int bOn)
{
    LapenshardSlotBag* pReg = FUN_140a70b70(Unk_NotifyContext::FUN_1422c8e90(m_strBag));
    if (pReg == 0)
        return;
    int nKind = 0;
    UILapenshardSystemDialog* pDlg = FUN_140a6ff40(0x4f6d);
    if (pDlg != 0)
        nKind = pDlg->FUN_140c62500();
    if (nKind == 0)
        return;
    for (unsigned i = 1; i < 7; ++i)
    {
        int nSlotKind = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->GetEquipPart((CItemLapenshardTable::Slot)i);
        if (nKind != nSlotKind)
            continue;
        CString strName;
        strName.Format("m_equipSlot%d", i);
        MS2Ptr<ASMovieClip> slot = m_ui->FUN_1409b4560(strName);
        if (slot.get() != 0)
        {
            if (MS2Ptr<ASMovieClip> effect = slot->FUN_1409b4560("m_equipEffect"))
                effect->vfunc_3(bOn);
        }
    }
}

// ---- LapenshardSystemTabPanelBase ----

// @0x140c5ee50
void LapenshardSystemTabPanelBase::FUN_140c5ee50(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
}

// ---- UILapenshardEquipTab ----

// @0x140c5dba0
UILapenshardEquipTab::UILapenshardEquipTab()
    : LapenshardSystemTabContents(), m_panels(10), m_ui(0)
{
    m_panels.AddTail(new LapenshardItemSlotBagPanel(this));
    m_panels.AddTail(new LapenshardEquipSlotPanel(this));
}

// @0x140c5dd20
void UILapenshardEquipTab::vfunc_1()
{
    for (POSITION pos = m_panels.GetHeadPosition(); pos != 0; m_panels.GetNext(pos))
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (p == 0)
            continue;
        p->vfunc_1();
    }
    m_panels.RemoveAll();
    m_ui = 0;
}

// @0x140c5de10
void UILapenshardEquipTab::vfunc_4()
{
    for (POSITION pos = m_panels.GetHeadPosition(); pos != 0; m_panels.GetNext(pos))
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (p == 0)
            continue;
        p->vfunc_2();
    }
}

// @0x140c5dee0
void UILapenshardEquipTab::vfunc_2(int nEvent)
{
    if (m_ui == 0)
        return;
    for (POSITION pos = m_panels.GetHeadPosition(); pos != 0; m_panels.GetNext(pos))
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (p == 0)
            continue;
        p->vfunc_5(nEvent);
    }
}

// @0x140c5dfd0
void UILapenshardEquipTab::vfunc_3(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
    for (POSITION pos = m_panels.GetHeadPosition(); pos != 0; m_panels.GetNext(pos))
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (p == 0)
            continue;
        p->FUN_140c5ee50(ui);
        p->vfunc_4();
        p->vfunc_3();
    }
}

// @0x140c5e140
int UILapenshardEquipTab::vfunc_6(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    if (_stricmp("OnUnmountEquipSlot", szMethod) == 0)
    {
        if (FUN_140c62520() == 0)
            return 1;
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nSlot = data.PopInt();
            int bMounted = pPlayer->GetLapenshardItemId((Unk_MyPCLapenSlot)nSlot);
            if (bMounted != 0)
            {
                COutPacket pkt(static_cast<int>(SendOp::Lapenshard), 0);
                pkt.WriteUInt8(2);
                Unk_LsSlotArg arg;
                arg.m_n = nSlot;
                ((struct Unk_LapenUnequip*)(struct Unk_LsSlotArg*)(&arg))->Write((class COutputStream*)(&pkt));
                FUN_140710590(pkt);
            }
        }
        return 1;
    }
    return 0;
}

// @0x140c5e290
int UILapenshardEquipTab::vfunc_8()
{
    return 1;
}

// @0x140c5e2b0
void UILapenshardEquipTab::vfunc_9(CInPacket& packet)
{
    if (packet.FUN_14070fe80() == 0x11b)
    {
        int nKind = (unsigned char)packet.ReadUInt8();
        switch (nKind)
        {
        case 0:
            vfunc_2(2);
            break;
        case 1:
            vfunc_2(0);
            break;
        case 2:
            vfunc_2(1);
        }
    }
}

// @0x140c5e370
void UILapenshardEquipTab::vfunc_10(void* a1, bool b)
{
    (void)a1;
    (void)b;
}

// ---- UILapenshardSystemDialog ----

// "m_buttonBar": the tab strip.

class Unk_LsItemEvents;
class Unk_InventoryListener* FUN_140a6a840();   // C3: was FUN_140a6a840
class Unk_ItemEventSystem   // C3: member view for the former free stand-ins
{
public:
    void FUN_1419cae20(class UIItemEventListener*);
    void FUN_1419caeb0(class UIItemEventListener*);
};
int FUN_1418fc760(char const*, void*, int, void*);   // C3: was FUN_1418fc760
template <class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v);
class UIDailyMissionDialog : public UIDialog { public: MS2Ptr<ASButtonBar> FUN_140c02870(const CString& strName); };   // C3: owns the child lookup COMDAT
CStringW GetStringCommonByKey(const CStringW& str);

// @0x140c61110
UILapenshardSystemDialog::TabInfo::TabInfo(CString strName, CStringW strLabel, LapenshardTabPtr spPage)
    : m_strName(strName), m_strLabel(strLabel), m_spPage(spPage)
{
}

// @0x140c611d0
UILapenshardSystemDialog::UILapenshardSystemDialog()
    : m_spPage(0), m_nSlot(0)
{
    m_164 = 1;
    FUN_141924170(1);
}

// @0x140c612a0
CString UILapenshardSystemDialog::GetTypeName()
{
    return "LapenshardSystemDialog";
}

// @0x140c616f0
void UILapenshardSystemDialog::vfunc_67()
{
    ((class Unk_ItemEventSystem*)(class Unk_LsItemEvents*)(reinterpret_cast<Unk_LsItemEvents*>(((class Unk_LsItemEvents*)FUN_140a6a840()))))->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    OnLeaveTab();
    for (unsigned i = 0; i < m_tabs.GetCount(); ++i)
    {
        TabInfoPtr spTab = m_tabs[i];
        if (spTab == 0)
            continue;
        if (spTab->m_spPage == 0)
            continue;
        spTab->m_spPage->vfunc_1();
    }
    m_tabs.RemoveAll();
    m_spPage = 0;
    UIModalDialog::vfunc_67();
}

// @0x140c61870
void UILapenshardSystemDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    if (MS2Ptr<ASButtonBar> spBar = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02870("m_buttonBar"))
    {
        for (unsigned i = 0; i < m_tabs.GetCount(); ++i)
        {
            TabInfoPtr spTab = m_tabs[i];
            if (spTab == 0)
                continue;
            if (spTab->m_spPage == 0)
                continue;
            ASObj row(2);
            row.FUN_1409c0d20("tabIndex", i);
            row.FUN_1407cbb20("label", spTab->m_strLabel);
            row.FUN_1407cba60("frame", spTab->m_strName);
            spBar->AddItem(row);
        }
        spBar->vfunc_24(true);
        spBar->SetSelectedIndex(0);
    }
    FUN_1419260d0("m_webGuideButton", 0);
}

// @0x140c61b50
void UILapenshardSystemDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
    if (m_spPage.get() != 0)
        m_spPage->vfunc_5(pRetVal, (void*)&strMethod, pArgs);
}

// @0x140c61be0
int UILapenshardSystemDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)(pArgs), nArgs, (void*)(this)) != 0)
        return 1;
    if (m_spPage.get() != 0 && m_spPage->vfunc_6(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnLeaveTab", szMethod) == 0)
    {
        OnLeaveTab();
        return 1;
    }
    else if (_stricmp("OnChangeTab", szMethod) == 0 && data.SetArgsIfAny(pArgs, nArgs) != 0)
    {
        unsigned nTab = data.PopUInt();
        Scaleform::GFx::Value root = data.PopValue();
        FUN_140c627a0(nTab, root);
        return 1;
    }
    return 0;
}

// @0x140c61de0
void UILapenshardSystemDialog::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (m_spPage.get() != 0)
        m_spPage->vfunc_7(p1, p2, p3, p4);
}

// @0x140c61ea0
int UILapenshardSystemDialog::vfunc_82()
{
    if (m_spPage == 0)
        return -1;
    return m_spPage->vfunc_8();
}

// @0x140c61f00
void UILapenshardSystemDialog::vfunc_79(void* p)
{
    if (m_spPage.get() != 0)
        m_spPage->vfunc_9(*static_cast<CInPacket*>(p));
}

// @0x140c61f60
void UILapenshardSystemDialog::vfunc_3(void* pItem, bool b)
{
    if (pItem == 0)
        return;
    if (static_cast<CItem*>(pItem)->IsLapenshard() == 0)
        return;
    FUN_140c623c0(2);
    if (m_spPage.get() != 0)
        m_spPage->vfunc_10(pItem, b);
}

// @0x140c62390
bool UILapenshardSystemDialog::vfunc_75()
{
    return ((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xd3);
}

// @0x140c623c0
void UILapenshardSystemDialog::FUN_140c623c0(int nEvent)
{
    if (vfunc_55() != 0)
        return;
    if (m_spPage.get() != 0)
        m_spPage->vfunc_2(nEvent);
}

// @0x140c62490
void UILapenshardSystemDialog::FUN_140c62490(int nSlot)
{
    m_nSlot = nSlot;
    FUN_140c623c0(10);
}

// @0x140c624d0
void UILapenshardSystemDialog::FUN_140c624d0()
{
    FUN_140c623c0(11);
}

// @0x140c62740
void UILapenshardSystemDialog::OnLeaveTab()
{
    if (m_spPage.get() != 0)
        m_spPage->vfunc_4();
}

// @0x140c627a0
void UILapenshardSystemDialog::FUN_140c627a0(unsigned nTab, const Scaleform::GFx::Value& root)
{
    if (m_tabs.GetCount() <= nTab)
        return;
    TabInfoPtr spTab = m_tabs[nTab];
    if (spTab.get() != 0)
    {
        if ((m_spPage = spTab->m_spPage).get() != 0)
        {
            MS2Ptr<ASUIComponent> spUi = Unk_ASCreate<ASUIComponent>(m_28, root);
            if (spUi.get() != 0)
                m_spPage->vfunc_3(spUi);
        }
    }
}

// ---- UILapenshardShieldBar ----

class UIRewardNotify;
#include <set>
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Init, Check
class AdditionalLevelData;
class AdditionalCli { public: unsigned GetRemainTicks(); AdditionalLevelData* FUN_14096d810(); };   // C3: member view of the buff
#ifdef __clang__
// FUN_140c60920 passes the address of the temporary CStringW from vfunc_77 (an MSVC extension).
#pragma clang diagnostic ignored "-Waddress-of-temporary"
#endif

class Unk_UpperEvents   // C3: member view for the former free stand-ins
{
public:
    void FUN_1419308c0(class UIEntityEventListener*);
    void FUN_141930950(class UIEntityEventListener*);
};
UIRewardNotify* FUN_140938cd0(int nId);
enum eUIClassID : int;
class UIUpperHpBar;
template <class T> T* Unk_AcFindUI(eUIClassID nId);                       // a shown UI by id
int FUN_141472bc0();   // C3: was FUN_141472bc0
float FUN_14028d280(unsigned nMs);                                      // ms -> s

// @0x140c607b0
Unk_LsEntityEvents* FUN_140c607b0()
{
    return reinterpret_cast<Unk_LsEntityEvents*>(TSingleton<UIEntityEventDispatcher>::s_instance);
}

// @0x140c5efa0
UILapenshardShieldBar::UILapenshardShieldBar()
    : m_spBuff(0), m_nPending(0), m_bImpending(0), m_bEnded(0)
{
    m_58 = 0;
    m_2c = 0x12;
}

// @0x140c5f090
UILapenshardShieldBar::~UILapenshardShieldBar()
{
}

// @0x140c5f120
CString UILapenshardShieldBar::GetTypeName()
{
    return "LapenshardShieldBar";
}

// @0x140c5f170
void UILapenshardShieldBar::OnLoadInit()
{
    UIObject::OnLoadInit();
    ((class Unk_UpperEvents*)(class Unk_LsEntityEvents*)(FUN_140c607b0()))->FUN_1419308c0(static_cast<UIEntityEventListener*>(this));
}

// @0x140c5f1d0
void UILapenshardShieldBar::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140c5fbd0();
}

// @0x140c5f200
void UILapenshardShieldBar::vfunc_26()
{
    UIObject::vfunc_26();
    ((class Unk_UpperEvents*)(class Unk_LsEntityEvents*)(FUN_140c607b0()))->FUN_141930950(static_cast<UIEntityEventListener*>(this));
    if (!m_strBind.IsEmpty())
        Unk_NotifyContext::FUN_1422c8f70(m_strBind);
    m_strBind.Empty();
}

// @0x140c5f2a0
void UILapenshardShieldBar::vfunc_43()
{
    if (MS2Ptr<ASGameEntity> spEntity = dynamic_cast<ASGameEntity*>(m_30.operator->()))
    {
        int nX = (int)spEntity->FUN_1422c10a0();
        int nY = (int)spEntity->FUN_1422c1110();
        spEntity->vfunc_2(1, 0, 0);
        spEntity->vfunc_3(1);
        int nOffset = 0x96;
        UIObject* pHpBar = (UIObject*)Unk_AcFindUI<UIUpperHpBar>((eUIClassID)0x4e3d);
        if (pHpBar != 0)
        {
            if (MS2Ptr<ASGameEntity> spHp = dynamic_cast<ASGameEntity*>(pHpBar->FUN_1422dba00().operator->()))
                nOffset = (int)(spHp->FUN_1422c1110() + (float)spHp->GetHeightCeil() + 30.0f);
        }
        spEntity->vfunc_2(1, 0, nOffset);
        int nW = (int)spEntity->FUN_1422c10a0();
        int nH = (int)spEntity->FUN_1422c1110();
        ((AScript*)((MS2Ptr<ASObj>*)(&m_30))->operator->())->Invoke("alignmentWithHpBarOffsetY", nOffset, nX, nY, nW, nH);
    }
}

// @0x140c5f5b0
void UILapenshardShieldBar::vfunc_3()
{
    UIHeadUpDisplay::vfunc_3();
    m_spBuff = 0;
    UIRewardNotify* pReward = FUN_140938cd0(0x4e5d);
    if (pReward != 0)
        pReward->RewardComplete();
}

// @0x140c5f610
void UILapenshardShieldBar::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (!m_30)
        return;
    if (m_spBuff == 0)
        return;
    if (m_nPending != 0)
        FUN_140c5fbd0();
    if (m_bEnded == 0 && m_tick.Check(100) != 0)
    {
        MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPlayer == 0)
            return;
        if (m_bImpending == 0)
        {
            if (reinterpret_cast<AdditionalCli*>(m_spBuff.operator->())->GetRemainTicks() < 5000)
            {
                m_30->Invoke("impending");
                m_bImpending = 1;
            }
        }
        if (reinterpret_cast<AdditionalCli*>(m_spBuff.operator->())->GetRemainTicks() <= 0)
            return;
        CStringW strLeft = FUN_140c5f9e0();
        m_30->Invoke("setValue", m_spBuff->m_nId, reinterpret_cast<Unk_LsBuffInfo*>(reinterpret_cast<AdditionalCli*>(m_spBuff.operator->())->FUN_14096d810())->m_nValue, strLeft);
    }
}

// @0x140c5f870
int UILapenshardShieldBar::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onEndComplete", szMethod) == 0)
    {
        vfunc_3();
        return 1;
    }
    return 0;
}

// @0x140c5f8f0
void UILapenshardShieldBar::FUN_140c5f8f0(MS2Ptr<Unk_LsBuff> spBuff)
{
    if (m_spBuff == spBuff.get())
        return;
    if (FUN_141986d30() == 0)
        vfunc_2();
    m_spBuff = spBuff;
    m_nPending = 1;
}

// @0x140c5f990
MS2Ptr<Unk_LsBuff> UILapenshardShieldBar::GetBuff()
{
    return m_spBuff;
}

// The "{0:02}:{1:02}" formatter (0x140c60060): StringFormat's 2-argument body with its own MakeValue copy.
namespace fmt { namespace internal { struct Unk_LsFormatter { typedef wchar_t Char; }; } }
#define LS_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_LsFormatter>(v##n)
template <typename T0, typename T1>
CStringW Unk_Fmt2(const wchar_t* format, const T0& v0, const T1& v1)
{
    const fmt::internal::ArgArray<2>::Type array = {LS_REF(0), LS_REF(1)};
    return StringFormat(format, fmt::ArgList(fmt::internal::make_type(v0, v1), array));
}

// @0x140c5f9e0
CStringW UILapenshardShieldBar::FUN_140c5f9e0()
{
    if (m_spBuff == 0)
        return L"";
    ATL::CTimeSpan span = CMsTime((__int64)FUN_14028d280(m_spBuff->m_nEnd)) - CMsTime((__int64)FUN_14028d280(FUN_141472bc0()));
    int nSeconds = span.GetSeconds();
    int nMinutes = span.GetMinutes();
    return Unk_Fmt2(L"{0:02}:{1:02}", nMinutes, nSeconds);
}

// @0x140c5faf0
void UILapenshardShieldBar::FUN_140c5faf0()
{
    if (m_bEnded != 0)
        return;
    if (!m_30)
        return;
    if (m_spBuff == 0)
        return;
    m_bEnded = 1;
    m_30->Invoke("end", m_spBuff->m_nId);
}

MS2_EMIT_CRT_MEMMOVE_S();


// The Invoke COMDATs of this unit.
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);

// @0x140c60370
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, int a3, int a4, int a5)
{
    ASArgList args;
    args.FUN_1409b2800(5);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    FUN_1422bccb0(args.FUN_1409b1f70(4), a5);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140c60480
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, __int64 a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140c60520
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, __int64 a1, __int64 a2, CStringW a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140c60620
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, __int64 a1, __int64 a2, CStringW a3, CString a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bce70(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- the upgrade page: unit-local views ----

void FUN_140710590(COutPacket& packet);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_14151f200();

// ---- LapenshardSourceItemSlotBagPanel ----

// @0x140c635f0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

// @0x140c63710
LapenshardSourceItemSlotBagPanel::LapenshardSourceItemSlotBagPanel(UILapenshardUpgradeTab* pTab)
    : m_pTab(pTab)
{
}

// @0x140c63780
void LapenshardSourceItemSlotBagPanel::vfunc_1()
{
    vfunc_4();
}

// @0x140c637b0
void LapenshardSourceItemSlotBagPanel::vfunc_2()
{
    vfunc_4();
}

// @0x140c637e0
void LapenshardSourceItemSlotBagPanel::vfunc_3()
{
    if (m_pTab == 0)
        return;
    vfunc_4();
    m_strBag = "LapenshardSourceItemSlotBag";
    if (MS2Ptr<ASTileList> bag = m_ui->FUN_140accef0<ASTileList>("m_sourceItemBag"))
    {
        bag->Invoke("resetRenderer");
        reinterpret_cast<ASCoreList*>(bag.operator->())->SetSelectedIndex(0xffffffff);
        FUN_140c60920(&m_items, 0, 1, 1, 1, 0, 0);
        BindBag(&m_strBag, &m_items, 0);
        bag->FUN_1422dd1d0();
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(true);
    }
}

// @0x140c63a00
void LapenshardSourceItemSlotBagPanel::vfunc_4()
{
    if (!m_strBag.IsEmpty())
    {
        FUN_140a704a0(m_strBag);
        m_strBag.Empty();
    }
    m_items.RemoveAll();
}

// @0x140c63a70
void LapenshardSourceItemSlotBagPanel::vfunc_5(int nEvent)
{
    switch (nEvent)
    {
    case 2:
    case 8:
    case 0xc:
        if (m_pTab->FUN_140c68e20() == 3)
            return;
        vfunc_3();
    }
}

// @0x140c63ad0
int LapenshardSourceItemSlotBagPanel::vfunc_8(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (m_pTab == 0)
        return 0;
    if (m_pTab->FUN_140c68e20() > 1)
        return 0;
    if (_stricmp("OnSelectSourceItem", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopInt();
            FUN_140c63bb0(nIndex);
        }
        return 1;
    }
    return 0;
}

// @0x140c63bb0
void LapenshardSourceItemSlotBagPanel::FUN_140c63bb0(int nIndex)
{
    if (m_pTab == 0)
        return;
    if (nIndex < 0 || nIndex >= (int)m_items.GetCount())
        return;
    MS2Ptr<CItem> spItem = m_items[nIndex];
    m_pTab->SendLapenshardMode3(spItem);
}

// ---- LapenshardIngredientItemSlotBagPanel ----

// @0x140c63c70
LapenshardIngredientItemSlotBagPanel::LapenshardIngredientItemSlotBagPanel(UILapenshardUpgradeTab* pTab)
    : m_pTab(pTab)
{
}

// @0x140c63ce0
void LapenshardIngredientItemSlotBagPanel::vfunc_1()
{
    vfunc_4();
}

// @0x140c63d10
void LapenshardIngredientItemSlotBagPanel::vfunc_2()
{
    vfunc_4();
}

// @0x140c63d40
void LapenshardIngredientItemSlotBagPanel::vfunc_3()
{
    if (m_pTab == 0)
        return;
    vfunc_4();
    MS2Ptr<CItem> spSource = m_pTab->GetSource();
    if (spSource == 0)
        return;
    MS2Ptr<CItemLapenshardData> spRec = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->Get(spSource->FUN_1405276c0());
    if (spRec == 0)
        return;
    if (spRec->m_nMinCount <= 0)
        return;
    m_strBag = "LapenshardIngredientItemSlotBag";
    if (MS2Ptr<ASTileList> bag = m_ui->FUN_140accef0<ASTileList>("m_ingredientItemBag"))
    {
        bag->Invoke("resetRenderer");
        reinterpret_cast<ASCoreList*>(bag.operator->())->SetSelectedIndex(0xffffffff);
        FUN_140c60920(&m_items, 0, 0, 0, 0, spRec->m_nGroup, spSource->GetItemUid());
        MS2Ptr<CItem> spCopy = spSource->Clone();
        if (spCopy)
        {
            if (!spCopy->FUN_140528e20())
            {
                unsigned nLeft = (unsigned)spCopy->GetCount() - 1 > 0 ? spCopy->GetCount() - 1 : 0;
                if (nLeft > 0)
                {
                    spCopy->SetCountClamped(nLeft);
                    m_items.Add(spCopy);
                }
            }
        }
        BindBag(&m_strBag, &m_items, 0);
        bag->FUN_1422dd1d0();
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(true);
    }
}

// @0x140c64160
void LapenshardIngredientItemSlotBagPanel::vfunc_4()
{
    if (!m_strBag.IsEmpty())
    {
        FUN_140a704a0(m_strBag);
        m_strBag.Empty();
    }
    m_items.RemoveAll();
    if (m_pTab == 0)
        return;
    m_pTab->FUN_140c68f90();
    m_pTab->vfunc_2(0xd);
}

// @0x140c64200
void LapenshardIngredientItemSlotBagPanel::vfunc_5(int nEvent)
{
    switch (nEvent)
    {
    case 2:
    case 3:
    case 8:
    case 9:
    case 0xc:
        if (m_pTab->FUN_140c68e20() == 3)
            return;
        vfunc_3();
        break;
    case 6:
    case 7:
        vfunc_4();
    }
}

// @0x140c642b0
int LapenshardIngredientItemSlotBagPanel::vfunc_8(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (m_pTab == 0)
        return 0;
    if (m_pTab->FUN_140c68e20() != 1)
        return 0;
    if (_stricmp("OnSelectIngredientItem", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopInt();
            FUN_140c64390(nIndex);
        }
        return 1;
    }
    return 0;
}

// @0x140c64390
void LapenshardIngredientItemSlotBagPanel::FUN_140c64390(int nIndex)
{
    if (m_pTab == 0)
        return;
    if (nIndex < 0 || nIndex >= (int)m_items.GetCount())
        return;
    MS2Ptr<CItem> spSource = m_pTab->GetSource();
    if (spSource == 0)
        return;
    MS2Ptr<CItemLapenshardData> spSrcRec = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->Get(spSource->FUN_1405276c0());
    if (spSrcRec == 0)
        return;
    MS2Ptr<CItem> spItem = m_items[nIndex];
    if (spItem == 0)
        return;
    MS2Ptr<CItemLapenshardData> spItemRec = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->Get(spItem->FUN_1405276c0());
    if (spItemRec == 0)
        return;
    if (spItem->FUN_14052a290(2))
    {
        int nHave = m_pTab->FUN_140c68ff0(spItem->GetItemUid());
        FUN_140c64960(nIndex, nHave);
    }
    else
    {
        unsigned nNeed = spSrcRec->m_nMinCount - m_pTab->FUN_140c68fd0() < 0 ? 0 : spSrcRec->m_nMinCount - m_pTab->FUN_140c68fd0();
        if (nNeed == 0)
            return;
        if (spItemRec->m_nLevel < 2)
        {
            int nTake = (unsigned)spItem->GetCount() < nNeed ? spItem->GetCount() : nNeed;
            FUN_140c64960(nIndex, -nTake);
        }
        else
        {
            if (MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, GetStringCommonByKey(L"s_lapenshard_upgraded_item"), 0, CStringW(L"")))
            {
                box->Append<int>(nIndex);
                box->Append<unsigned>(spSource->FUN_1405276c0());
                box->Append<unsigned>(nNeed);
                box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &LapenshardIngredientItemSlotBagPanel::FUN_140c64bc0));
                FUN_140d73c60(box);
            }
        }
    }
}

// @0x140c64960
void LapenshardIngredientItemSlotBagPanel::FUN_140c64960(int nIndex, int nCount)
{
    MS2Ptr<CItem> spItem = m_items[nIndex];
    if (spItem.get() != 0)
    {
        m_pTab->FUN_140c68e60(spItem->GetItemUid(), -nCount);
        spItem->SetCountClamped(spItem->GetCount() + nCount);
        if (spItem->FUN_14052a290(2))
            spItem->FUN_14052a260(2);
        else
            spItem->FUN_14052a230(2);
        LapenshardSlotBag* pReg = FUN_140a70b70(Unk_NotifyContext::FUN_1422c8e90(m_strBag));
        if (pReg != 0)
        {
            pReg->vfunc_14(nIndex);
            pReg->FUN_1422c8be0();
        }
        m_ui->Invoke("toggleIngredientSelectItem", nIndex);
    }
}

// @0x140c64b10
bool LapenshardIngredientItemSlotBagPanel::FUN_140c64b10(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        int nCount = _wtoi(box.FUN_141a02d50().Trim(L','));
        int nIndex = box.FUN_141a02e50(0, 0);
        FUN_140c64960(nIndex, nCount);
    }
    FUN_14151f200();
    return true;
}

// @0x140c64bc0
bool LapenshardIngredientItemSlotBagPanel::FUN_140c64bc0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        int nIndex = box.FUN_141a02e50(0, 0);
        unsigned nItemId = box.FUN_141a02e90(1, 0);
        unsigned nCount = box.FUN_141a02e90(2, 0);
        MS2Ptr<CItemLapenshardData> spRec = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->Get(nItemId);
        if (spRec == 0)
            return false;
        MS2Ptr<CItem> spItem = m_items[nIndex];
        if (spItem == 0)
            return false;
        unsigned nUse = (unsigned)spItem->GetCount() < nCount ? spItem->GetCount() : nCount;
        FUN_140c64960(nIndex, -(int)nUse);
    }
    FUN_14151f200();
    return true;
}

// ---- the upgrade page: records of the packet 0xad ----

// The head every upgrade record starts with (the source item).
struct Unk_LsRecHead
{
    __int64 m_nUid;                                                     // +0x00
    int m_nItemId;                                                      // +0x08
    int m_nSlot;                                                        // +0x0c
    Unk_LsRecHead();
};
struct Unk_LsPktA : Unk_LsRecHead
{
    int m_n10;                                                          // +0x10
    int m_nTotal;                                                       // +0x14
    Unk_LsPktA();
};
struct Unk_LsPktB : Unk_LsRecHead
{
    ATL::CAtlMap<unsigned __int64, int> m_ingredients;                  // +0x10
    bool m_bSuccess;                                                    // +0x58
    int m_n5c;                                                          // +0x5c
    Unk_LsPktB();
};
// @0x140c6a020
Unk_LsRecHead::Unk_LsRecHead() : m_nUid(0), m_nItemId(0), m_nSlot(0) {}
// @0x140c6a050
Unk_LsPktA::Unk_LsPktA() : m_n10(0), m_nTotal(0) {}
// @0x140c69fb0
Unk_LsPktB::Unk_LsPktB() : m_ingredients(0x11, 0.75f, 0.25f, 2.25f, 10), m_bSuccess(false), m_n5c(0) {}
void* FUN_14025e7c0();
class CInputKeyHandler   // C3: member view for the former free stand-ins
{
public:
    bool IsDebugMode();
};
void FUN_141415600(const CString& strSlot);                                  // unbind a slot name
void FUN_14141f970(const CString& strSlot);
void FUN_141415450(const CString& strSlot, MS2Ptr<CItem> spItem, int a, int b, int c);   // create the item slot of a name
int FUN_14053feb0(int nItemId);
void* FUN_1401c0d90();
class CGameRule   // C3: member view for the former free stand-ins
{
public:
    unsigned int GetLapenshardUpgradeSaleRate();
};

// ---- LapenshardUpgradeSlotPanel ----

// @0x140c64d50
LapenshardUpgradeSlotPanel::LapenshardUpgradeSlotPanel(UILapenshardUpgradeTab* pTab)
    : m_strSource("lapenshardUpgradeSourceSlot"), m_strResult("lapenshardUpgradeResultSlot"), m_pTab(pTab), m_spSource(0), m_body(0)
{
}

// @0x140c64e50
void LapenshardUpgradeSlotPanel::vfunc_1()
{
    vfunc_4();
}

// @0x140c64e80
void LapenshardUpgradeSlotPanel::vfunc_2()
{
    vfunc_4();
}

// @0x140c64eb0
void LapenshardUpgradeSlotPanel::vfunc_3()
{
    if (m_pTab == 0)
        return;
    vfunc_4();
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    m_body = m_ui->FUN_140accfb0<ASUIComponent>("m_body");
    if (m_body == 0)
        return;
    FUN_140c67ce0();
    m_spSource = m_pTab->GetSource();
    int nState = m_pTab->FUN_140c68e20();
    switch (nState)
    {
    case 0:
        {
            CString strLabel("start");
            m_body->vfunc_13(strLabel);
        }
        break;
    case 1:
        if (m_spSource.get() != 0)
        {
            m_pTab->FUN_140c69620();
            FUN_140c671d0();
        }
        break;
    }
}

// @0x140c650d0
void LapenshardUpgradeSlotPanel::vfunc_4()
{
    for (unsigned i = 0; i < m_slotNames.GetCount(); ++i)
    {
        CString& strSlot = m_slotNames[i];
        if (!strSlot.IsEmpty())
            FUN_141415600(strSlot);
    }
    m_slotNames.RemoveAll();
    m_spSource = 0;
    if (!m_strBind.IsEmpty())
        FUN_14141f970(m_strBind);
}

// @0x140c651a0
void LapenshardUpgradeSlotPanel::vfunc_5(int nEvent)
{
    if (m_pTab == 0)
        return;
    switch (nEvent)
    {
    case 3:
    case 8:
        vfunc_3();
        break;
    case 2:
        if (m_pTab->FUN_140c68e20() == 0 || m_pTab->FUN_140c68e20() == 1)
            vfunc_3();
        break;
    case 5:
        FUN_140c65e00();
        break;
    case 4:
        FUN_140c65ef0();
        break;
    case 6:
        FUN_140c67440(true);
        break;
    case 7:
        FUN_140c67440(false);
        break;
    case 9:
        FUN_140c660f0();
        break;
    case 0xd:
        FUN_140c65ef0();
    }
}

// @0x140c652d0
void LapenshardUpgradeSlotPanel::FUN_140c652d0(ItemInfoSlot& slot, ASSlot& asSlot)
{
    MS2Ptr<CItem> spItem = slot.vfunc_25();
    if (spItem.get() != 0)
    {
        if (spItem->GetItemUid() == 0)
            asSlot.SetItemEquip(1);
        else
            asSlot.SetItemEquip(0);
    }
}

// @0x140c65360
void LapenshardUpgradeSlotPanel::FUN_140c65360(ItemInfoSlot& slot, ASTooltip& tooltip)
{
    MS2Ptr<CItem> spItem = slot.vfunc_25();
    if (spItem.get() != 0)
    {
        MS2Ptr<CItem> spShown = spItem;
        if (spItem->GetRarity() == 0)
        {
            spShown = spItem->Clone();
            if (spShown.get() != 0)
                spShown->FUN_140526bf0(FUN_14053feb0(spItem->FUN_1405276c0()));
        }
        tooltip.FUN_1409e0d40(spShown.get());
    }
}

// @0x140c654a0
void LapenshardUpgradeSlotPanel::FUN_140c654a0(CString& strSlot, MS2Ptr<CItem> spItem)
{
    FUN_141415600(strSlot);
    FUN_141415450(strSlot, spItem, 0, 0x40401, 0x2020);
    m_slotNames.Add(strSlot);
}

// ---- UILapenshardUpgradeTab ----

// @0x140c67de0
UILapenshardUpgradeTab::UILapenshardUpgradeTab()
    : LapenshardSystemTabContents(), m_panels(10), m_nState(0), m_ui(0), m_spSource(0), m_ingredients(0x11, 0.75f, 0.25f, 2.25f, 10), m_nTotal(0), m_n_bc(0), m_n_c0(0)
{
    m_panels.AddTail(new LapenshardSourceItemSlotBagPanel(this));
    m_panels.AddTail(new LapenshardUpgradeSlotPanel(this));
    m_panels.AddTail(new LapenshardIngredientItemSlotBagPanel(this));
}

// @0x140c68090
void UILapenshardUpgradeTab::vfunc_1()
{
    for (POSITION pos = m_panels.GetHeadPosition(); pos != 0; m_panels.GetNext(pos))
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (p == 0)
            continue;
        p->vfunc_1();
    }
    m_panels.RemoveAll();
    m_ui = 0;
    FUN_140c68a50();
}

// @0x140c68190
void UILapenshardUpgradeTab::vfunc_4()
{
    for (POSITION pos = m_panels.GetHeadPosition(); pos != 0; m_panels.GetNext(pos))
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (p == 0)
            continue;
        p->vfunc_2();
    }
    FUN_140c68a50();
}

// @0x140c68260
void UILapenshardUpgradeTab::vfunc_2(int nEvent)
{
    if (m_ui == 0)
        return;
    if (nEvent == 2 && (FUN_140c68e20() == 0 || FUN_140c68e20() == 1))
    {
        FUN_140c68a50();
        FUN_140c68f90();
    }
    for (POSITION pos = m_panels.GetHeadPosition(); pos != 0; m_panels.GetNext(pos))
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (p == 0)
            continue;
        p->vfunc_5(nEvent);
    }
}

// @0x140c68390
void UILapenshardUpgradeTab::vfunc_3(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
    for (POSITION pos = m_panels.GetHeadPosition(); pos != 0; m_panels.GetNext(pos))
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (p == 0)
            continue;
        p->FUN_140c5ee50(ui);
        p->vfunc_4();
        p->vfunc_3();
    }
}

// @0x140c68500
int UILapenshardUpgradeTab::vfunc_6(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (m_ui == 0)
        return 0;
    for (POSITION pos = m_panels.GetHeadPosition(); pos != 0; m_panels.GetNext(pos))
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (p == 0)
            continue;
        p->vfunc_8(szMethod, pArgs, nArgs);
    }
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    if (_stricmp("OnAction", szMethod) == 0)
    {
        if (FUN_140c62520() == 0)
            return 1;
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nAction = data.PopInt();
            if (nAction == 1)
                SendLapenshardMode5();
            else if (nAction == 3)
            {
                FUN_140c68a50();
                vfunc_2(8);
            }
        }
        return 1;
    }
    else if (_stricmp("OnFillIngredientDebug", szMethod) == 0)
    {
        if (m_nState != 1)
            return 0;
        if (!((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode())
            return 0;
        if (m_spSource == 0)
            return 0;
        COutPacket pkt(static_cast<int>(SendOp::Lapenshard), 0);
        pkt.WriteUInt8(6);
        pkt.WriteInt32(m_spSource->FUN_1405276c0());
        pkt.WriteInt32(m_n_c0);
        FUN_140710590(pkt);
        return 1;
    }
    else if (_stricmp("OnProcessingComplete", szMethod) == 0)
    {
        m_nState = 4;
        vfunc_2(0xc);
    }
    return 0;
}

// @0x140c68860
int UILapenshardUpgradeTab::vfunc_8()
{
    return 0;
}

// @0x140c68870
void UILapenshardUpgradeTab::vfunc_9(CInPacket& packet)
{
    if (packet.FUN_14070fe80() == 0x11b)
    {
        int nKind = (unsigned char)packet.ReadUInt8();
        switch (nKind)
        {
        case 4:
        {
            Unk_LsPktA rec;
            ((struct Unk_LapenPreview*)(struct Unk_LsPktA*)(&rec))->Read(packet);
            m_n_bc = rec.m_n10;
            vfunc_2(5);
            break;
        }
        case 5:
        {
            if (m_nState != 2)
                return;
            Unk_LsPktB rec;
            ((struct Unk_LapenUpgradeResult*)(struct Unk_LsPktB*)(&rec))->Read(packet);
            if (m_spSource->FUN_1405276c0() != rec.m_nItemId)
                return;
            if (rec.m_bSuccess)
                vfunc_2(6);
            else
                vfunc_2(7);
            m_nState = 3;
        }
        case 6:
            vfunc_2(9);
        }
    }
}

// @0x140c68a30
void UILapenshardUpgradeTab::vfunc_10(void* a1, bool b)
{
    (void)a1;
    (void)b;
}

// @0x140c68a50
void UILapenshardUpgradeTab::FUN_140c68a50()
{
    m_nState = 0;
    m_spSource = 0;
    m_n_bc = 0;
}

// @0x140c68aa0
void UILapenshardUpgradeTab::SendLapenshardMode4()
{
    MyPC* pPlayer = vfunc_11();
    if (pPlayer == 0)
        return;
    COutPacket pkt(static_cast<int>(SendOp::Lapenshard), 0);
    pkt.WriteUInt8(4);
    Unk_LsPktA rec;
    rec.m_nItemId = m_spSource->FUN_1405276c0();
    rec.m_nUid = m_spSource->GetItemUid();
    rec.m_nTotal = m_nTotal;
    if (rec.m_nUid == 0)
    {
        rec.m_nSlot = vfunc_11()->FindLapenshardSlot(rec.m_nItemId);
        if (rec.m_nSlot == 0)
            return;
    }
    reinterpret_cast<Unk_LapenAddFodder*>(&rec)->Write(&pkt);
    FUN_140710590(pkt);
}

// @0x140c68bd0
void UILapenshardUpgradeTab::SendLapenshardMode3(MS2Ptr<CItem> spItem)
{
    if (m_ui == 0)
        return;
    if (FUN_140c62520() == 0)
        return;
    MyPC* pPlayer = vfunc_11();
    if (pPlayer == 0)
        return;
    m_spSource = spItem;
    FUN_140c68f90();
    m_nState = 1;
    COutPacket pkt(static_cast<int>(SendOp::Lapenshard), 0);
    pkt.WriteUInt8(3);
    Unk_LsRecHead rec;
    rec.m_nItemId = spItem->FUN_1405276c0();
    rec.m_nUid = spItem->GetItemUid();
    if (rec.m_nUid == 0)
    {
        rec.m_nSlot = pPlayer->FindLapenshardSlot(rec.m_nItemId);
        if (rec.m_nSlot == 0)
            return;
    }
    reinterpret_cast<Unk_LapenItem*>(&rec)->Write(&pkt);
    FUN_140710590(pkt);
    vfunc_2(3);
}

// @0x140c68da0
MS2Ptr<CItem> UILapenshardUpgradeTab::GetSource()
{
    return m_spSource;
}

// @0x140c68df0
void UILapenshardUpgradeTab::FUN_140c68df0()
{
    m_spSource = 0;
}

// @0x140c68e60
void UILapenshardUpgradeTab::FUN_140c68e60(unsigned __int64 nUid, int nDelta)
{
    MyPC* pPlayer = vfunc_11();
    if (pPlayer == 0)
        return;
    int nCount = 0;
    m_ingredients.Lookup(nUid, nCount);
    // clamped at zero through an unsigned compare, so the clamp never fires
    nCount = (unsigned)(nCount + nDelta) < 0 ? 0 : nCount + nDelta;
    if (nCount == 0)
        m_ingredients.RemoveKey(nUid);
    else
        m_ingredients.SetAt(nUid, nCount);
    m_nTotal = (unsigned)(m_nTotal + nDelta) < 0 ? 0 : m_nTotal + nDelta;
    vfunc_2(4);
    SendLapenshardMode4();
}

// @0x140c68f90
void UILapenshardUpgradeTab::FUN_140c68f90()
{
    m_ingredients.RemoveAll();
    m_nTotal = 0;
}

// @0x140c68ff0
int UILapenshardUpgradeTab::FUN_140c68ff0(unsigned __int64 nUid)
{
    int nCount = 0;
    m_ingredients.Lookup(nUid, nCount);
    return nCount;
}

// @0x140c69620
void UILapenshardUpgradeTab::FUN_140c69620()
{
    m_n_c0 = ((class CGameRule*)(void*)(FUN_1401c0d90()))->GetLapenshardUpgradeSaleRate();
}

// ---- the bag registry helpers and the rest of the upgrade slot panel ----

CString FUN_1422cc860(const CString& strBase, int nIndex);
void FUN_14141f770(const CString&, int, void*, MS2Ptr<CItem>(*)(void*, int), int, int);
MS2Ptr<CItem> FUN_141420330(void*, int);
CStringW FUN_1419021b0(unsigned a, unsigned b);

// @0x140c5fbb0 (the shield bar), 0x140c68e40 and 0x140c69650 (the upgrade page): plain getters
int UILapenshardShieldBar::FUN_140c5fbb0()
{
    return m_bEnded;
}

// @0x140c68e40
int UILapenshardUpgradeTab::GetN_bc()
{
    return m_n_bc;
}

// @0x140c69650
int UILapenshardUpgradeTab::FUN_140c69650()
{
    return m_n_c0;
}

// @0x140c60ed0
void FUN_140c60ed0(CString& strBag, const ItemArray& items, int nIconType, int nFlags)
{
    FUN_14141f970(strBag);
    MS2Ptr<CItem> (*pfnGetItem)(void*, int) = FUN_141420330;
    FUN_14141f770(strBag, (int)items.GetCount(), (void*)&items, pfnGetItem, nIconType, nFlags);
}

// @0x140c61010
void FUN_140c61010(CString& strSlot, MS2Ptr<CItem> spItem, int nIconType, int nFlags)
{
    FUN_141415600(strSlot);
    FUN_141415450(strSlot, spItem, 0, nIconType, nFlags);
}

// @0x140c65d60
MS2Ptr<CItemLapenshardData> LapenshardUpgradeSlotPanel::FUN_140c65d60()
{
    if (m_spSource == 0)
        return MS2Ptr<CItemLapenshardData>(0);
    return reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->Get(m_spSource->FUN_1405276c0());
}

// @0x140c65e00
void LapenshardUpgradeSlotPanel::FUN_140c65e00()
{
    if (m_body == 0)
        return;
    float fProb = (float)m_pTab->GetN_bc() / 100.0f;
    m_ui->Invoke("setSuccessProb", FUN_14028dfa0<float>(CStringW(L"s_lapenshard_tabname_upgrade_success_prob"), fProb));
}

// @0x140c65ef0
void LapenshardUpgradeSlotPanel::FUN_140c65ef0()
{
    if (m_spSource == 0)
        return;
    MS2Ptr<CItemLapenshardData> spRec = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->Get(m_spSource->FUN_1405276c0());
    if (spRec == 0)
        return;
    if ((unsigned)spRec->m_nMinCount <= 0)
        return;
    if (!(m_pTab->FUN_140c68e20() == 0 || m_pTab->FUN_140c68e20() == 1))
        return;
    CString strSlot = FUN_1422cc860(m_strBind, 0);
    ItemInfoSlot* pBag = FUN_140c69ab0(Unk_NotifyContext::FUN_1422c8e90(strSlot));
    if (pBag == 0)
        return;
    int nCount = m_pTab->FUN_140c68fd0();
    int nNeed = spRec->m_nMinCount;
    m_ui->Invoke("setIngredientLapenshardCount", FUN_1419021b0(nCount, nNeed));
}

// @0x140c67ce0
void LapenshardUpgradeSlotPanel::FUN_140c67ce0()
{
    if (m_body == 0)
        return;
    if (!(((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode()))
        return;
    if (MS2Ptr<ASMovieClip> spButton = m_body->FUN_140acce30<ASMovieClip>("m_fillIngredientDebug"))
        spButton->vfunc_3(1);
}

// ---- the window: opening conditions ----

// The map the player stands on.
void FUN_140d73aa0(CStringW strMsg, int nType, void* pListener, CStringW strTag);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_141275260(int nStringId, int nA, int nB);

// @0x140c62520
int FUN_140c62520()
{
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    if (pPlayer->vfunc_65() != 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_lapenshard_disable_battle"), 0, 0, L"");
        return 0;
    }
    MS2Ptr<CFieldDataCli> info = WorldService::GetInstance()->FUN_141bd30a0();
    if (info == 0)
        return 0;
    if (info->FUN_140375660(0x200) != 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_lapenshard_disable_field"), 0, 0, L"");
        return 0;
    }
    return 1;
}

// The singletons the opening conditions read.
class Unk_LsRules { public: unsigned char m_pad[8]; CContentShutdown m_flags; };
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0
// The constants manager's int-array setting (inventory.cpp has the same layout).
struct Unk_InventoryArraySetting {
    void* unknown0;
    bool initialized;
    unsigned char unknown9[0x47];
    std::vector<int> values;
    void* unknown68; void* unknown70; void* unknown78;
    const std::vector<int>& FUN_140a6aa40();
};
MS2_CHECK_SIZE(Unk_InventoryArraySetting, 0x80);
class Unk_LsGameTables { public: unsigned char m_pad[0xa040]; Unk_InventoryArraySetting m_quests; };   // +0xa040 embedded, not a pointer
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
class Unk_LsQuestLog { public: unsigned char m_pad[0x10]; unsigned char m_done[1]; };
void* FUN_140764020();   // C3: was FUN_140764020
CStringW FUN_1416e4df0(int nQuest);                                     // the name of a quest

// @0x140c62000
int UILapenshardSystemDialog::vfunc_73()
{
    if (UIDialog::vfunc_73() == 0)
        return 0;
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    if (reinterpret_cast<Unk_LsRules*>(((class Unk_LsRules*)FUN_14025e7b0()))->m_flags.Get((CContentShutdown::Content)0x5b) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    std::vector<int> quests = reinterpret_cast<Unk_LsGameTables*>(((class Unk_LsGameTables*)FUN_1401d3200()))->m_quests.FUN_140a6aa40();
    if (quests.size() != 2)
        return 0;
    int nNewbie = quests[0];
    int nQuest = quests[1];
    if (((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode())
        return 1;
    for (size_t i = 0; i < quests.size(); ++i)
    {
        int nId = quests[i];
        if (reinterpret_cast<CQuestManagerCommon*>(reinterpret_cast<Unk_LsQuestLog*>(FUN_140764020())->m_done)->FUN_140745590(nId) != 0)
            return 1;
    }
    CStringW strName;
    if (pPlayer->FUN_141654700() == 1)
    {
        strName = FUN_1416e4df0(nQuest);
        FUN_1412751f0(FUN_14028dfa0<CStringW>(CStringW(L"s_lapenshard_open_newbie_quest_message"), strName), 1, 1);
    }
    else
    {
        strName = FUN_1416e4df0(nNewbie);
        FUN_1412751f0(FUN_14028dfa0<CStringW>(CStringW(L"s_lapenshard_open_quest_message"), strName), 1, 1);
    }
    return 0;
}
// @0x140c612f0
int UILapenshardSystemDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    m_tabs.Add(new TabInfo("equip", GetStringCommonByKey(L"s_lapenshard_tabname_equip"), new UILapenshardEquipTab()));
    m_tabs.Add(new TabInfo("upgrade", GetStringCommonByKey(L"s_lapenshard_tabname_upgrade"), new UILapenshardUpgradeTab()));
    ((class Unk_ItemEventSystem*)(class Unk_LsItemEvents*)(reinterpret_cast<Unk_LsItemEvents*>(((class Unk_LsItemEvents*)FUN_140a6a840()))))->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    return 0;
}


// ---- the upgrade request ----


extern Unk_Inventory g_143ab2a90;                                       // the inventory
extern __int64 DAT_143ab2898;                                           // the money


// @0x140c69670
int FUN_140c69670(unsigned nItemId, int nGrade, int* pnTag)
{
    int nCount = g_143ab2a90.FUN_140a5f180(nItemId, nGrade);
    if (*pnTag != 0)
        nCount = g_143ab2a90.FUN_140a5f780(*pnTag, 0);
    return nCount;
}

// @0x140c69a30
static void Unk_LsCopyMap(ATL::CAtlMap<unsigned __int64, int>& dst, ATL::CAtlMap<unsigned __int64, int>& src)
{
    for (POSITION pos = src.GetStartPosition(); pos != 0; src.GetNext(pos))
    {
        const int& rValue = src.GetValueAt(pos);
        dst.SetAt(src.GetKeyAt(pos), rValue);
    }
}

// @0x140c691f0
int UILapenshardUpgradeTab::FUN_140c691f0()
{
    if (m_nState != 1)
        return 0;
    if (m_spSource == 0)
        return 0;
    MS2Ptr<CItemLapenshardData> spRec = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->Get(m_spSource->FUN_1405276c0());
    if (spRec == 0)
        return 0;
    if (0 < spRec->m_nMeso && DAT_143ab2898 < spRec->m_nMeso)
    {
        FUN_141275260(0x34, 1, 1);
        return 0;
    }
    if (spRec->m_nMinCount > (unsigned)FUN_140c68fd0())
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_lapenshard_tabname_upgrade_lack_ingredient"), 1, 1);
        return 0;
    }
    MS2SvrPtr<CIngredientContainer> spRecipe = spRec->GetIngredients(m_n_c0);
    if (spRecipe == 0)
        return 0;
    std::vector<MS2Ptr<CIngredientInfo> >* pList = reinterpret_cast<std::vector<MS2Ptr<CIngredientInfo> >*>(spRecipe->FUN_14026c230());
    unsigned nEntries = (unsigned)pList->size();
    for (unsigned i = 0; i < nEntries; ++i)
    {
        MS2Ptr<CIngredientInfo> spEntry = pList->at(i);
        if (spEntry == 0 || spEntry->IsEmpty())
            continue;
        unsigned nItemId = spEntry->FUN_14026b500();
        int nGrade = FUN_14053feb0(nItemId);
        int nNeed = spEntry->m_c;
        int nHave = FUN_140c69670(nItemId, nGrade, &spEntry->m_b);
        if (nNeed > nHave)
        {
            FUN_1412751f0(GetStringCommonByKey(L"s_lapenshard_tabname_upgrade_lack_ingredient"), 1, 1);
            return 0;
        }
    }
    return 1;
}

// @0x140c69030
void UILapenshardUpgradeTab::SendLapenshardMode5()
{
    if (FUN_140c691f0() == 0)
        return;
    MyPC* pPlayer = vfunc_11();
    if (pPlayer == 0)
        return;
    COutPacket pkt(static_cast<int>(SendOp::Lapenshard), 0);
    pkt.WriteUInt8(5);
    Unk_LsPktB rec;
    rec.m_nItemId = m_spSource->FUN_1405276c0();
    rec.m_nUid = m_spSource->GetItemUid();
    rec.m_n5c = m_n_c0;
    if (rec.m_nUid == 0)
    {
        rec.m_nSlot = pPlayer->FindLapenshardSlot(rec.m_nItemId);
        if (rec.m_nSlot == 0)
            return;
    }
    Unk_LsCopyMap(rec.m_ingredients, m_ingredients);
    reinterpret_cast<Unk_LapenUpgrade*>(&rec)->Write(&pkt);
    FUN_140710590(pkt);
    m_nState = 2;
    m_ui->Invoke("RequestUpgrade");
}

// ---- the shield bar: open ----

// The skill slot of the HUD (0x150 bytes, owned by ?\skillslot.cpp).
class SkillSlot : public MS2DragSlot
{
public:
    SkillSlot(const CString& strName, int nIndex, unsigned nSkillId, int nUnk, __int64 nUnk2);      // 0x14175c840
    virtual ~SkillSlot();
    void SetFixed(int n);                                          // m_bc = n
private:
    unsigned char m_pad_90[0x150 - 0x90];
};


// @0x140c5fbd0
void UILapenshardShieldBar::FUN_140c5fbd0()
{
    m_bImpending = 0;
    m_bEnded = 0;
    m_tick.Init();
    if (m_spBuff == 0)
        return;
    if (!m_strBind.IsEmpty())
        Unk_NotifyContext::FUN_1422c8f70(m_strBind);
    m_strBind = "LapenshardShieldBarSkillBindID";
    int nSkill = reinterpret_cast<Unk_LsBuffInfo*>(reinterpret_cast<AdditionalCli*>(m_spBuff.operator->())->FUN_14096d810())->m_nSkillId;
    SkillSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) SkillSlot(m_strBind, 0, nSkill, 0, 0);
    if (pSlot == 0)
        return;
    pSlot->SetFixed(1);
    Unk_NotifyContext::FUN_1422c8f10(m_strBind, pSlot);
    CStringW strLeft = FUN_140c5f9e0();
    m_30->Invoke("open", m_spBuff->m_nId, reinterpret_cast<Unk_LsBuffInfo*>(reinterpret_cast<AdditionalCli*>(m_spBuff.operator->())->FUN_14096d810())->m_nValue, strLeft, m_strBind);
    UIRewardNotify* pReward = FUN_140938cd0(0x4e5d);
    if (pReward != 0)
    {
        if (!reinterpret_cast<std::set<unsigned>&>(reinterpret_cast<Unk_LsBuffInfo*>(reinterpret_cast<AdditionalCli*>(m_spBuff.operator->())->FUN_14096d810())->m_skills).empty())
        {
            unsigned nSkillId = *reinterpret_cast<std::set<unsigned>&>(reinterpret_cast<Unk_LsBuffInfo*>(reinterpret_cast<AdditionalCli*>(m_spBuff.operator->())->FUN_14096d810())->m_skills).begin();
            CStringW strMsg = FUN_14028dfa0<CStringW>(CStringW(L"s_lapenshard_skill_possible_msg"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(4, nSkillId));
            pReward->FUN_141ac05d0(nSkillId, strMsg, 1);
        }
    }
    m_nPending = 0;
}

// ---- the lapenshard bag filter ----


// @0x140c60920
void FUN_140c60920(ItemArray* pOut, int bCheckUse, int bWithBound, int bWithEquipped, int bTableOnly, int nKind, __int64 nExcludeUid)
{
    pOut->RemoveAll();
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    ItemArray items;
    g_143ab2a90.FUN_140a60880(0xd, items);
    if (bWithEquipped != 0)
    {
        ATL::CAtlArray<unsigned int> equipped;
        pPlayer->FUN_14152f960(equipped);
        for (unsigned i = 0; i < equipped.GetCount(); ++i)
        {
            unsigned nItemId = equipped[i];
            if (bTableOnly != 0 && reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->HasUpgrade(nItemId) == 0)
                continue;
            MS2Ptr<CItem> spItem(new CItem());
            int nGrade = FUN_14053feb0(nItemId);
            if (spItem->InitWithCount(nItemId, nGrade, 0, 1) == 0)
                continue;
            if (reinterpret_cast<CItemTransfer*>(spItem->FUN_140527930())->GetType() == 2)
            {
                __int64 nCharId = pPlayer->FUN_141656a80();
                spItem->BindToCharacter(nCharId, pPlayer->vfunc_77());
            }
            items.Add(spItem);
        }
    }
    if (!items.IsEmpty())
    {
        size_t nCount = items.GetCount();
        for (size_t i = 0; i < nCount; ++i)
        {
            MS2Ptr<CItem> spItem = items[i];
            if (spItem == 0)
                continue;
            if (bCheckUse != 0)
            {
                if (pPlayer->FUN_141662eb0(spItem.get()) == 0)
                    continue;
                if (spItem->IsJobAllowed(pPlayer->FUN_141654700()) == 0)
                    continue;
                if (spItem->CanUseAtLevel(pPlayer->vfunc_78()) == 0)
                    continue;
            }
            if (spItem->IsLapenshard() == 0)
                continue;
            if (bWithBound == 0 && spItem->FUN_140528e20())
                continue;
            if (bTableOnly != 0 && reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->HasUpgrade(spItem->FUN_1405276c0()) == 0)
                continue;
            if (nKind != 0 && reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->GetGroup(spItem->FUN_1405276c0()) != nKind)
                continue;
            if (nExcludeUid != 0 && spItem->GetItemUid() == nExcludeUid)
                continue;
            if (spItem->FUN_1405291f0() != 0)
                pOut->Add(spItem);
            else
                pOut->Add(spItem->Clone());
        }
    }
}

CStringW FUN_1418fec00(int nType, __int64 nValue, bool);                 // money text by pay type

// @0x140c65540
void LapenshardUpgradeSlotPanel::FUN_140c65540(CString& strBag, MS2Ptr<CItemLapenshardData> spRec, ItemArray& items, LapenshardKindArray& kinds, ASObj& out)
{
    int bNeed = spRec->m_nMinCount > 0;
    if (bNeed != 0)
    {
        unsigned nItemId = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->GetFirstItem(spRec->m_nGroup);
        int nGrade = FUN_14053feb0(nItemId);
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->InitWithCount(nItemId, nGrade, 0, spRec->m_nMinCount) != 0)
        {
            items.Add(spItem);
            int nZero = 0;
            kinds.Add(nZero);
        }
    }
    int nTier = 0;
    if (m_pTab != 0)
        nTier = m_pTab->FUN_140c69650();
    MS2SvrPtr<CIngredientContainer> spRecipe = spRec->GetIngredients(nTier);
    if (spRecipe)
    {
        std::vector<MS2Ptr<CIngredientInfo> >* pList = reinterpret_cast<std::vector<MS2Ptr<CIngredientInfo> >*>(spRecipe->FUN_14026c230());
        unsigned nEntries = (unsigned)pList->size();
        for (unsigned i = 0; i < nEntries; ++i)
        {
            MS2Ptr<CIngredientInfo> spEntry = pList->at(i);
            if (spEntry == 0 || spEntry->IsEmpty())
                continue;
            unsigned nItemId = spEntry->FUN_14026b500();
            int nKind = spEntry->m_b;
            int nGrade = FUN_14053feb0(nItemId);
            int nCount = spEntry->m_c;
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->InitWithCount(nItemId, nGrade, 0, nCount) == 0)
                continue;
            if (nTier != 0)
            {
                bool bMark = nKind == 0x5d || nKind == 0x5e || nKind == 0x5f;
                if (bMark)
                    spItem->FUN_140526910(1);
            }
            items.Add(spItem);
            kinds.Add(nKind);
        }
    }
    int nStyle = 0x20403;
    int nFlags = 0x2020;
    FUN_14141f770(strBag, (int)items.GetCount(), (void*)&items, FUN_141420330, nStyle, nFlags);
    ASArray rows(2);
    for (unsigned i = 0; i < items.GetCount(); ++i)
    {
        MS2Ptr<CItem> spItem = items[i];
        if (spItem == 0)
            continue;
        CString strBinding = FUN_1422cc860(strBag, i);
        ASObj row(2);
        row.FUN_1407cba60("binding", strBinding);
        int nHave = spItem->IsLapenshard() != 0 ? 0 : FUN_140c69670(spItem->FUN_1405276c0(), spItem->GetRarity(), &kinds[i]);
        int nNeed = spItem->GetCount();
        row.FUN_1407cbb20("countText", FUN_1419021b0(nHave, nNeed));
        rows.PushValue(row.FUN_1422bb870());
    }
    out.FUN_1409adbe0("ingredient", rows.FUN_1422bb870());
    if (0 < spRec->m_nMeso)
        out.FUN_1407cbb20("requireMeso", FUN_1418fec00(1, spRec->m_nMeso, false));
    FUN_140c65ef0();
}

CStringW FUN_14183e9c0(CStringW strName, int nRank);                    // the item name coloured by rank
void FUN_140d01420(const Scaleform::GFx::Value& root, CString strName, int n);   // set a child's mode

// @0x140c664e0
void LapenshardUpgradeSlotPanel::FUN_140c664e0()
{
    if (m_body == 0)
        return;
    if (MS2Ptr<ASMovieClip> spSourceSlot = m_body->FUN_1409b4560("m_sourceSlot"))
    {
        CStringW strName;
        if (m_spSource)
        {
            MS2Ptr<CItem> spItem(new CItem());
            int nRarity = 0;
            if (spItem->InitWithCount(m_spSource->FUN_1405276c0(), nRarity, 0, 0) != 0)
            {
                spItem->SetItemUid(m_spSource->GetItemUid());
                FUN_140c654a0(m_strSource, spItem);
                ItemInfoSlot* pBag = FUN_140c69ab0(Unk_NotifyContext::FUN_1422c8e90(m_strSource));
                if (pBag != 0)
                {
                    pBag->SetSlotFn(Delegate<void(ItemInfoSlot&, ASSlot&)>(this, &LapenshardUpgradeSlotPanel::FUN_140c652d0));
                    pBag->SetTipFn(Delegate<void(ItemInfoSlot&, ASTooltip&)>(this, &LapenshardUpgradeSlotPanel::FUN_140c65360));
                    ASObj obj(2);
                    obj.FUN_1407cba60("bindID", m_strSource);
                    spSourceSlot->FUN_140acd1f0("setData", AScript(obj));
                    strName = FUN_14183e9c0(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spItem->FUN_1405276c0()), FUN_14053feb0(spItem->FUN_1405276c0()));
                }
            }
        }
        if (MS2Ptr<ASMovieClip> spNameClip = m_body->FUN_1409b4560("m_sourceItemName"))
        {
            if (MS2Ptr<ASTextField> tf = spNameClip->FUN_1409b4620("textField"))
            {
                FUN_140d01420((*spNameClip).FUN_1422bb890(), CString("textField"), 2);
                tf->SetTextHTMLW(strName);
            }
        }
    }
    if (MS2Ptr<ASMovieClip> spResultSlot = m_body->FUN_1409b4560("m_resultSlot"))
    {
        CStringW strName;
        MS2Ptr<CItemLapenshardData> spRec = FUN_140c65d60();
        if (spRec.get() != 0 && spRec->m_nNext != 0)
        {
            MS2Ptr<CItem> spItem(new CItem());
            int nRarity = 0;
            if (spItem->InitWithCount(spRec->m_nNext, nRarity, 0, 0) != 0)
            {
                FUN_140c654a0(m_strResult, spItem);
                ItemInfoSlot* pBag = FUN_140c69ab0(Unk_NotifyContext::FUN_1422c8e90(m_strResult));
                if (pBag != 0)
                {
                    pBag->SetTipFn(Delegate<void(ItemInfoSlot&, ASTooltip&)>(this, &LapenshardUpgradeSlotPanel::FUN_140c65360));
                    ASObj obj(2);
                    obj.FUN_1407cba60("bindID", m_strResult);
                    spResultSlot->FUN_140acd1f0("setData", AScript(obj));
                    strName = FUN_14183e9c0(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spItem->FUN_1405276c0()), FUN_14053feb0(spItem->FUN_1405276c0()));
                }
            }
        }
        if (MS2Ptr<ASMovieClip> spNameClip = m_body->FUN_1409b4560("m_resultItemName"))
        {
            if (MS2Ptr<ASTextField> tf = spNameClip->FUN_1409b4620("textField"))
            {
                FUN_140d01420((*spNameClip).FUN_1422bb890(), CString("textField"), 2);
                tf->SetTextHTMLW(strName);
            }
        }
    }
}

// @0x140c660f0
void LapenshardUpgradeSlotPanel::FUN_140c660f0()
{
    if (m_ui == 0)
        return;
    if (m_items.IsEmpty() || m_kinds.IsEmpty())
        return;
    ASArray rows(2);
    for (unsigned i = 0; i < m_items.GetCount(); ++i)
    {
        MS2Ptr<CItem> spItem = m_items[i];
        if (spItem == 0)
            continue;
        CString strBinding = FUN_1422cc860(m_strBind, i);
        ASObj row(2);
        row.FUN_1407cba60("binding", strBinding);
        int nHave = spItem->IsLapenshard() != 0 ? 0 : FUN_140c69670(spItem->FUN_1405276c0(), spItem->GetRarity(), &m_kinds[i]);
        int nNeed = spItem->GetCount();
        row.FUN_1407cbb20("countText", FUN_1419021b0(nHave, nNeed));
        rows.PushValue(row.FUN_1422bb870());
    }
    ASObj data(2);
    data.FUN_1409adbe0("ingredient", rows.FUN_1422bb870());
    m_ui->Invoke("setIngredientData", data.FUN_1422bb870());
    FUN_140c65ef0();
}

// @0x140c671d0
void LapenshardUpgradeSlotPanel::FUN_140c671d0()
{
    if (m_body == 0)
        return;
    {
        CString strLabel("select");
        m_body->vfunc_13(strLabel);
    }
    FUN_140c664e0();
    MS2Ptr<CItemLapenshardData> spRec = FUN_140c65d60();
    if (spRec == 0)
        return;
    if (spRec->m_nNext == 0)
        return;
    m_strBind = "lapenshardUpgradeIngredientSlotBag";
    m_items.RemoveAll();
    m_kinds.RemoveAll();
    ASObj data(2);
    FUN_140c65540(m_strBind, spRec, m_items, m_kinds, data);
    m_ui->Invoke("selectItem", data.FUN_1422bb870());
}

// @0x140c67440
void LapenshardUpgradeSlotPanel::FUN_140c67440(bool bSuccess)
{
    if (m_body == 0)
        return;
    {
        CString strLabel("result");
        m_body->vfunc_13(strLabel);
    }
    MS2Ptr<CItemLapenshardData> spRec = FUN_140c65d60();
    if (spRec == 0)
        return;
    if (spRec->m_nNext == 0)
        return;
    ASObj obj(2);
    obj.FUN_1407cbbe0("success", bSuccess);
    {
        CString strSuccess("lapenshardUpgradeSuccessSlotID");
        MS2Ptr<CItem> spItem(new CItem());
        int nRarity = 0;
        if (spItem->InitWithCount(spRec->m_nNext, nRarity, 0, 0) != 0)
        {
            FUN_140c654a0(strSuccess, spItem);
            ItemInfoSlot* pBag = FUN_140c69ab0(Unk_NotifyContext::FUN_1422c8e90(strSuccess));
            if (pBag != 0)
                pBag->SetTipFn(Delegate<void(ItemInfoSlot&, ASTooltip&)>(this, &LapenshardUpgradeSlotPanel::FUN_140c65360));
        }
        CStringW strName = FUN_14183e9c0(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spItem->FUN_1405276c0()), FUN_14053feb0(spItem->FUN_1405276c0()));
        obj.FUN_1407cba60("successSlotBindID", strSuccess);
        obj.FUN_1407cbb20("successItemName", strName);
    }
    int bLimit = 0;
    if (bSuccess != 0)
    {
        MS2Ptr<CItemLapenshardData> spNext = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->Get(spRec->m_nNext);
        if (spNext && spNext->m_nNext == 0)
            bLimit = 1;
    }
    obj.FUN_1407cb9c0("limitLevel", bLimit);
    if (m_spSource)
    {
        CString strFail("lapenshardUpgradeFailSlotID");
        MS2Ptr<CItem> spItem(new CItem());
        int nRarity = 0;
        if (spItem->InitWithCount(m_spSource->FUN_1405276c0(), nRarity, 0, 0) != 0)
        {
            FUN_140c654a0(strFail, spItem);
            ItemInfoSlot* pBag = FUN_140c69ab0(Unk_NotifyContext::FUN_1422c8e90(strFail));
            if (pBag != 0)
                pBag->SetTipFn(Delegate<void(ItemInfoSlot&, ASTooltip&)>(this, &LapenshardUpgradeSlotPanel::FUN_140c65360));
        }
        CStringW strName = FUN_14183e9c0(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spItem->FUN_1405276c0()), FUN_14053feb0(spItem->FUN_1405276c0()));
        obj.FUN_1407cba60("failSlotBindID", strFail);
        obj.FUN_1407cbb20("failItemName", strName);
    }
    m_ui->Invoke("upgradeComplete", obj.FUN_1422bb870());
    m_spSource = 0;
    m_pTab->FUN_140c68df0();
}

// @0x140c6b1e0
MS2_EMIT_CRT_MEMMOVE_S_COPY(3);

// @0x140c62440
MS2Ptr<LapenshardSystemTabContents> UILapenshardSystemDialog::GetPage()
{
    return m_spPage;
}

// @0x140c69ab0
ItemInfoSlot* FUN_140c69ab0(NotifyContext::BindData* pEntry)
{
    void* pResult = 0;
    if (pEntry != 0 && pEntry->TypeCast(0x620002f, &pResult))
        return static_cast<ItemInfoSlot*>(pResult);
    else
        return 0;
}

void FUN_14141f860(const CString&, int, void*, MS2Ptr<ItemSlotBag::CreateParam>);

// @0x140c60f40
void FUN_140c60f40(CString& strBag, ItemArray& items, MS2Ptr<ItemSlotBag::CreateParam> param)
{
    FUN_14141f970(strBag);
    if ((bool)(param.get() != 0) && param->m_pfnGetItem == 0)
        param->m_pfnGetItem = FUN_141420330;
    FUN_14141f860(strBag, static_cast<int>(items.GetCount()), &items, param);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca31f0-0x142ca3260 .text$yd
// MS2-RANGE: 0x142ca3280-0x142ca32f0 .text$yd
// MS2-RANGE: 0x142ca3310-0x142ca33a0 .text$yd
// MS2-RANGE: 0x142ca33c0-0x142ca33e0 .text$yd
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca3260-0x142ca3280 .text$yd
// MS2-RANGE: 0x142ca32f0-0x142ca3310 .text$yd
// MS2-RANGE: 0x142ca33a0-0x142ca33c0 .text$yd
