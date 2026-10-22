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
// MS2-PIN: ?GrowBuffer@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@AEAA_N_K@Z 0x140c6a7e0
// MS2-PIN: ?SetCount@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@QEAA_N_KH@Z 0x140c6abf0
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@V?$CElementTraits@V?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@@ATL@@@ATL@@QEAA@XZ 0x140c62ab0
// MS2-PIN: ??0?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@QEAA@AEBV0@@Z 0x140c62990
// MS2-PIN: ??1?$MS2Ptr@VTabInfo@UILapenshardSystemDialog@@@@QEAA@XZ 0x140c62af0
// MS2-PIN: ??0?$MS2Ptr@VUnk_LsRecord@@@@QEAA@AEBV0@@Z 0x140c69f50
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
#include "ms2/placeholder/ms2stdafx.h"

#include "unit_140c5d230.h"

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

class Unk_LsMapInfo;
class Unk_LsWorld { public: MyPC* FUN_141bd0cc0(); Unk_LsMapInfo FUN_141bd30a0(); };                   // the local player
Unk_LsWorld* FUN_1403ed2d0();

// The item bag control inside a section clip (as Unk_PetItemBag in tabcontentspetcompose.cpp).
class Unk_LsBag : public ASMovieClip
{
public:
    Unk_LsBag(const Scaleform::GFx::Value& v, int nMovieId);            // 0x1422cf330
    void FUN_1422dcca0(unsigned nIndex);                                // select a slot (-1: none)
    void FUN_1422dd1d0();                                               // refresh the registered bag
#define LS_V(n) virtual void vfunc_##n();
    LS_V(16) LS_V(17) LS_V(18) LS_V(19) LS_V(20) LS_V(21) LS_V(22) LS_V(23)
#undef LS_V
    virtual void vfunc_24(bool bVisible);                               // 24 (+0xc0) show
    void FUN_1407cba60(const char* szName, CString str);                // set the bag id
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_LsBag, 0x88);

typedef MS2Ptr<CItem> ItemPtr;
typedef LapenshardItemArray ItemArray;

// The item bag registry (a name -> item list map of the inventory dialogs).
void FUN_140a704a0(CString* pstrBag);                                   // unbind the bag name
void FUN_140a702f0(CString* pstrBag, ItemArray* pItems, int nFlag);     // bind the bag name to the items
// The inventory: the bag lookup used by FUN_140c60920 below.
void FUN_140c60920(ItemArray* pOut, int bCheckUse, int bWithBound, int bWithEquipped, int bTableOnly, int nKind, __int64 nExcludeUid);   // 0x140c60920

// @0x140c610a0
static void BindBag(CString* pstrBag, ItemArray* pItems, int nFlag)
{
    FUN_140a704a0(pstrBag);
    FUN_140a702f0(pstrBag, pItems, nFlag);
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

// @0x140c5e4a0
LapenshardSystemTabContents::LapenshardSystemTabContents()
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
void LapenshardSystemTabPanelBase::vfunc_7()
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
    return FUN_1403ed2d0()->FUN_141bd0cc0();
}

// ---- LapenshardItemSlotBagPanel ----

// @0x140c5d230
LapenshardItemSlotBagPanel::LapenshardItemSlotBagPanel(UILapenshardEquipTab* pTab)
    : m_pTab(pTab)
{
}

// @0x140c5e5c0
LapenshardItemSlotBagPanel::~LapenshardItemSlotBagPanel()
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
    if (MS2Ptr<Unk_LsBag> bag = m_ui->FUN_140accef0<Unk_LsBag>("m_itemBag"))
    {
        bag->Invoke("resetRenderer");
        bag->FUN_1422dcca0(0xffffffff);
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
        FUN_140a704a0(&m_strBag);
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

// @0x140c5e590
LapenshardEquipSlotPanel::~LapenshardEquipSlotPanel()
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
class Unk_LsBagReg
{
public:
#define LS_R(n) virtual void vfunc_##n();
    LS_R(0) LS_R(1) LS_R(2) LS_R(3) LS_R(4) LS_R(5) LS_R(6) LS_R(7) LS_R(8) LS_R(9) LS_R(10) LS_R(11) LS_R(12) LS_R(13)
#undef LS_R
    virtual void vfunc_14(int nIndex);                                  // 14 (+0x70) refresh slot nIndex
    virtual CString vfunc_15(unsigned nIndex);                          // 15 (+0x78) the bag id of slot nIndex
};
Unk_LsBagReg* FUN_140a703d0(CString* pstrBag);                          // the bag of a name
class Unk_LsRecord;
class Unk_LsTable { public: int FUN_1405b5810(unsigned nSlot); MS2Ptr<Unk_LsRecord> FUN_1405b56a0(unsigned nItemId); unsigned FUN_1405b5af0(int nKind); };   // lapenshard slot -> equip kind; item id -> record
Unk_LsTable* FUN_1409c4b30();
struct Unk_LsSlotArg { unsigned m_n; Unk_LsSlotArg() : m_n(0) {} };      // 0x140c5e480
void FUN_1405b5e40(Unk_LsSlotArg* pArg, COutPacket* pPacket);            // write it
Unk_LsBagReg* FUN_140a70b70(NotifyContext::BindData* pEntry);
NotifyContext::BindData* FUN_1422c8e90(const CString& strBag);   // the registry entry of a bag name
ItemInfoSlot* FUN_140c69ab0(NotifyContext::BindData* pEntry);                              // the bag component (class id 0x6200084) of a registry entry
UILapenshardSystemDialog* FUN_140a6ff40(int nId);                      // the open Lapenshard window
CFeatureManager* FUN_140166410();
int FUN_140c62520();                                                    // the window may be used (not in battle / disabled field)

// @0x140c610e0
static Unk_LsBagReg* BindBagReg(CString* pstrBag)
{
    FUN_140a704a0(pstrBag);
    return FUN_140a703d0(pstrBag);
}

// ---- LapenshardEquipSlotPanel ----

// @0x140c5d680
void LapenshardEquipSlotPanel::vfunc_3()
{
    if (m_pTab == 0)
        return;
    vfunc_4();
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    m_strBag = "LapenshardEquipSlotBag";
    Unk_LsBagReg* pReg = BindBagReg(&m_strBag);
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
            int bEquip = pPlayer->FUN_14152f770((Unk_MyPCLapenSlot)i) ? 1 : 0;
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
        FUN_140a704a0(&m_strBag);
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
    Unk_LsBagReg* pReg = FUN_140a70b70(FUN_1422c8e90(m_strBag));
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
        int nSlotKind = FUN_1409c4b30()->FUN_1405b5810(i);
        if (nKind != nSlotKind)
            continue;
        CString strName;
        strName.Format("m_equipSlot%d", i);
        MS2Ptr<ASMovieClip> slot = m_ui->FUN_1409b4560(strName);
        if (slot.get() != 0)
        {
            MS2Ptr<ASMovieClip> effect = slot->FUN_1409b4560(CString("m_equipEffect"));
            if (effect.get() != 0)
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
    : m_panels(10), m_ui(0)
{
    m_panels.AddTail(LapenshardPanelPtr(new LapenshardItemSlotBagPanel(this)));
    m_panels.AddTail(LapenshardPanelPtr(new LapenshardEquipSlotPanel(this)));
}

// @0x140c5e660
UILapenshardEquipTab::~UILapenshardEquipTab()
{
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
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (_stricmp("OnUnmountEquipSlot", szMethod) == 0)
    {
        if (FUN_140c62520() == 0)
            return 1;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nSlot = data.FUN_1422b8a10();
            int bMounted = pPlayer->FUN_14152f770((Unk_MyPCLapenSlot)nSlot);
            if (bMounted != 0)
            {
                COutPacket pkt(0xad, 0);
                pkt.vfunc_o10_1(2);
                Unk_LsSlotArg arg;
                arg.m_n = nSlot;
                FUN_1405b5e40(&arg, &pkt);
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
        int nKind = (unsigned char)packet.vfunc_o8_1();
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
class Unk_LsTabBar : public ASDisplayObject
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bVisible);
    void FUN_1422e3460(const ASObj& row);                       // add a tab
    void FUN_1422e31e0(int nIndex);                             // select a tab
};

class Unk_LsItemEvents;
Unk_LsItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_LsItemEvents*, UIItemEventListener*);
void FUN_1419caeb0(Unk_LsItemEvents*, UIItemEventListener*);
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, UIDialog* pDialog);
MS2Ptr<ASUIComponent> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);
CStringW FUN_14028b8e0(const CStringW& str);

// @0x140c61110
UILapenshardSystemDialog::TabInfo::TabInfo(CString strName, CStringW strLabel, LapenshardTabPtr spPage)
    : m_strName(strName), m_strLabel(strLabel), m_spPage(spPage)
{
}

// @0x140c62b50
UILapenshardSystemDialog::TabInfo::~TabInfo()
{
}

// @0x140c611d0
UILapenshardSystemDialog::UILapenshardSystemDialog()
    : m_spPage(0), m_nSlot(0)
{
    m_164 = 1;
    FUN_141924170(1);
}

// @0x140c62ba0
UILapenshardSystemDialog::~UILapenshardSystemDialog()
{
}

// @0x140c612a0
CString UILapenshardSystemDialog::vfunc_1()
{
    return "LapenshardSystemDialog";
}

// @0x140c616f0
void UILapenshardSystemDialog::vfunc_67()
{
    FUN_1419caeb0(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
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
    if (MS2Ptr<Unk_LsTabBar> spBar = FUN_140c02870("m_buttonBar"))
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
            spBar->FUN_1422e3460(row);
        }
        spBar->vfunc_24(true);
        spBar->FUN_1422e31e0(0);
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
    if (FUN_1418fc760(szMethod, pArgs, nArgs, this) != 0)
        return 1;
    if (m_spPage.get() != 0 && m_spPage->vfunc_6(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnLeaveTab", szMethod) == 0)
    {
        OnLeaveTab();
        return 1;
    }
    else if (_stricmp("OnChangeTab", szMethod) == 0 && data.FUN_1422b9620(pArgs, nArgs) != 0)
    {
        unsigned nTab = data.FUN_1422b8b10();
        Scaleform::GFx::Value root = data.FUN_1422b9260();
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
    if (static_cast<CItem*>(pItem)->FUN_140526100() == 0)
        return;
    FUN_140c623c0(2);
    if (m_spPage.get() != 0)
        m_spPage->vfunc_10(pItem, b);
}

// @0x140c62390
bool UILapenshardSystemDialog::vfunc_75()
{
    return FUN_140166410()->FUN_14036d570(0xd3);
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
            MS2Ptr<ASUIComponent> spUi = FUN_140acca70(m_28, root);
            if (spUi.get() != 0)
                m_spPage->vfunc_3(spUi);
        }
    }
}

// ---- UILapenshardShieldBar ----

class UIRewardNotify;
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cmainsystem.h"

extern Unk_LsEntityEvents* DAT_143abf028;                               // the entity event hub
void FUN_1419308c0(Unk_LsEntityEvents* pHub, UIEntityEventListener* pListener);
void FUN_141930950(Unk_LsEntityEvents* pHub, UIEntityEventListener* pListener);
void FUN_1422c8f70(const CString& strName);                             // unbind a bag / slot name
UIRewardNotify* FUN_140938cd0(int nId);
UIObject* FUN_14096e340(int nId);                                       // a shown UI by id
unsigned FUN_141472bc0();                                               // the server tick
float FUN_14028d280(unsigned nMs);                                      // ms -> s

// @0x140c607b0
Unk_LsEntityEvents* FUN_140c607b0()
{
    return DAT_143abf028;
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
CString UILapenshardShieldBar::vfunc_1()
{
    return "LapenshardShieldBar";
}

// @0x140c5f170
void UILapenshardShieldBar::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_1419308c0(FUN_140c607b0(), static_cast<UIEntityEventListener*>(this));
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
    FUN_141930950(FUN_140c607b0(), static_cast<UIEntityEventListener*>(this));
    if (!m_strBind.IsEmpty())
        FUN_1422c8f70(m_strBind);
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
        UIObject* pHpBar = FUN_14096e340(0x4e3d);
        if (pHpBar != 0)
        {
            if (MS2Ptr<ASGameEntity> spHp = dynamic_cast<ASGameEntity*>(pHpBar->FUN_1422dba00().operator->()))
                nOffset = (int)(spHp->FUN_1422c1110() + (float)spHp->FUN_1422c13b0() + 30.0f);
        }
        spEntity->vfunc_2(1, 0, nOffset);
        int nW = (int)spEntity->FUN_1422c10a0();
        int nH = (int)spEntity->FUN_1422c1110();
        m_30->Invoke("alignmentWithHpBarOffsetY", nOffset, nX, nY, nW, nH);
    }
}

// @0x140c5f5b0
void UILapenshardShieldBar::vfunc_3()
{
    UIHeadUpDisplay::vfunc_3();
    m_spBuff = 0;
    UIRewardNotify* pReward = FUN_140938cd0(0x4e5d);
    if (pReward != 0)
        pReward->FUN_141ac1f40();
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
    if (m_bEnded == 0 && m_tick.FUN_140268870(100) != 0)
    {
        MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return;
        if (m_bImpending == 0)
        {
            if (m_spBuff->FUN_14096d2e0() < 5000)
            {
                m_30->Invoke("impending");
                m_bImpending = 1;
            }
        }
        if (m_spBuff->FUN_14096d2e0() <= 0)
            return;
        CStringW strLeft = FUN_140c5f9e0();
        m_30->Invoke("setValue", m_spBuff->m_nId, FUN_14096d810(m_spBuff.operator->())->m_nValue, strLeft);
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
MS2Ptr<Unk_LsBuff> UILapenshardShieldBar::FUN_140c5f990()
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

// A lapenshard record of the item table (as far as the page reads it).
class Unk_LsRecord : public CPtred
{
public:
    int m_nKind;                                                        // +0x18
    unsigned short m_nGrade;                                            // +0x1c
    unsigned char m_pad_1e[2];
    int m_n20;                                                          // +0x20
    unsigned char m_pad_24[4];
    int m_nNeed;                                                        // +0x28 the number of ingredients
    unsigned char m_pad_2c[4];
    __int64 m_nCost;                                                    // +0x30 the money an upgrade costs
    MS2Ptr<class Unk_LsRecipe> FUN_1405b41b0(unsigned nTier);           // the recipe of an upgrade tier
};

void FUN_1422c8be0(Unk_LsBagReg* pReg);                                 // refresh the bag slots
void FUN_140710590(COutPacket& packet);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
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

// @0x140c6a1c0
LapenshardSourceItemSlotBagPanel::~LapenshardSourceItemSlotBagPanel()
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
    if (MS2Ptr<Unk_LsBag> bag = m_ui->FUN_140accef0<Unk_LsBag>("m_sourceItemBag"))
    {
        bag->Invoke("resetRenderer");
        bag->FUN_1422dcca0(0xffffffff);
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
        FUN_140a704a0(&m_strBag);
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
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8a10();
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

// @0x140c6a180
LapenshardIngredientItemSlotBagPanel::~LapenshardIngredientItemSlotBagPanel()
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
    MS2Ptr<CItem> spSource = m_pTab->FUN_140c68da0();
    if (spSource == 0)
        return;
    MS2Ptr<Unk_LsRecord> spRec = FUN_1409c4b30()->FUN_1405b56a0(spSource->FUN_1405276c0());
    if (spRec == 0)
        return;
    if (spRec->m_nNeed == 0)
        return;
    m_strBag = "LapenshardIngredientItemSlotBag";
    if (MS2Ptr<Unk_LsBag> bag = m_ui->FUN_140accef0<Unk_LsBag>("m_ingredientItemBag"))
    {
        bag->Invoke("resetRenderer");
        bag->FUN_1422dcca0(0xffffffff);
        FUN_140c60920(&m_items, 0, 0, 0, 0, spRec->m_nKind, spSource->FUN_140526a50());
        if (MS2Ptr<CItem> spCopy = spSource->FUN_140524250())
        {
            if (!spCopy->FUN_140528e20())
            {
                int nLeft;
                if (spCopy->FUN_140526c50() == 1)
                    nLeft = 0;
                else
                    nLeft = spCopy->FUN_140526c50() - 1;
                if (nLeft != 0)
                {
                    spCopy->FUN_140526c70(nLeft);
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
        FUN_140a704a0(&m_strBag);
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
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8a10();
            FUN_140c64390(nIndex);
        }
        return 1;
    }
    return 0;
}

// @0x140c64390
// MS2-FUNCTIONAL: nested early-outs and message-box temporaries are laid out differently
void LapenshardIngredientItemSlotBagPanel::FUN_140c64390(int nIndex)
{
    if (m_pTab == 0 || nIndex <= -1 || nIndex >= (int)m_items.GetCount())
        return;
    MS2Ptr<CItem> spSource = m_pTab->FUN_140c68da0();
    if (spSource == 0)
        return;
    MS2Ptr<Unk_LsRecord> spSrcRec = FUN_1409c4b30()->FUN_1405b56a0(spSource->FUN_1405276c0());
    if (spSrcRec == 0)
        return;
    MS2Ptr<CItem> spItem = m_items[nIndex];
    if (spItem == 0)
        return;
    MS2Ptr<Unk_LsRecord> spItemRec = FUN_1409c4b30()->FUN_1405b56a0(spItem->FUN_1405276c0());
    if (spItemRec == 0)
        return;
    if (!spItem->FUN_14052a290(2))
    {
        int nNeed = spSrcRec->m_nNeed - m_pTab->FUN_140c68fd0();
        if (nNeed == 0)
            return;
        if (spItemRec->m_nGrade < 2)
        {
            if ((unsigned)spItem->FUN_140526c50() < (unsigned)nNeed)
                nNeed = spItem->FUN_140526c50();
            FUN_140c64960(nIndex, -nNeed);
        }
        else
        {
            if (MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_14028b8e0(CStringW(L"s_lapenshard_upgraded_item")), 0, CStringW(L"")))
            {
                box->FUN_140533ff0(nIndex);
                box->FUN_140534050(spSource->FUN_1405276c0());
                box->FUN_140534050(nNeed);
                box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &LapenshardIngredientItemSlotBagPanel::FUN_140c64bc0));
                FUN_140d73c60(box);
            }
        }
    }
    else
    {
        int nHave = m_pTab->FUN_140c68ff0(spItem->FUN_140526a50());
        FUN_140c64960(nIndex, nHave);
    }
}

// @0x140c64960
void LapenshardIngredientItemSlotBagPanel::FUN_140c64960(int nIndex, int nCount)
{
    MS2Ptr<CItem> spItem = m_items[nIndex];
    if (spItem.get() != 0)
    {
        m_pTab->FUN_140c68e60(spItem->FUN_140526a50(), -nCount);
        spItem->FUN_140526c70(spItem->FUN_140526c50() + nCount);
        if (spItem->FUN_14052a290(2))
            spItem->FUN_14052a260(2);
        else
            spItem->FUN_14052a230(2);
        Unk_LsBagReg* pReg = FUN_140a70b70(FUN_1422c8e90(m_strBag));
        if (pReg != 0)
        {
            pReg->vfunc_14(nIndex);
            FUN_1422c8be0(pReg);
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
        MS2Ptr<Unk_LsRecord> spRec = FUN_1409c4b30()->FUN_1405b56a0(nItemId);
        if (spRec == 0)
            return false;
        MS2Ptr<CItem> spItem = m_items[nIndex];
        if (spItem == 0)
            return false;
        unsigned nUse = (unsigned)spItem->FUN_140526c50() < nCount ? spItem->FUN_140526c50() : nCount;
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
void FUN_1405b6360(Unk_LsPktA* pRecord, CInPacket& packet);             // read
void FUN_1405b6280(Unk_LsPktA* pRecord, COutPacket& packet);            // write the source record
void FUN_1405b5ec0(Unk_LsRecHead* pRecord, COutPacket& packet);         // write the source record (pick)
void FUN_1405b6220(Unk_LsPktB* pRecord, CInPacket& packet);             // read
void FUN_1405b5fd0(Unk_LsPktB* pRecord, COutPacket& packet);            // write
void* FUN_14025e7c0();
bool FUN_14116d720(void* p);                                            // the debug fill is allowed
void FUN_141415600(CString* pstrSlot);                                  // unbind a slot name
void FUN_14141f970(CString* pstrSlot);
void FUN_141415450(CString* pstrSlot, MS2Ptr<CItem> spItem, int a, int b, int c);   // create the item slot of a name
int FUN_14053feb0(int nItemId);
void* FUN_1401c0d90();
int FUN_14047f880(void* p);

// ---- LapenshardUpgradeSlotPanel ----

// @0x140c64d50
LapenshardUpgradeSlotPanel::LapenshardUpgradeSlotPanel(UILapenshardUpgradeTab* pTab)
    : m_strSource("lapenshardUpgradeSourceSlot"), m_strResult("lapenshardUpgradeResultSlot"), m_pTab(pTab), m_spSource(0), m_body(0)
{
}

// @0x140c6a200
LapenshardUpgradeSlotPanel::~LapenshardUpgradeSlotPanel()
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
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    m_body = m_ui->FUN_140accfb0<ASUIComponent>("m_body");
    if (m_body == 0)
        return;
    FUN_140c67ce0();
    m_spSource = m_pTab->FUN_140c68da0();
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
            FUN_141415600(&strSlot);
    }
    m_slotNames.RemoveAll();
    m_spSource = 0;
    if (!m_strBind.IsEmpty())
        FUN_14141f970(&m_strBind);
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
        if (spItem->FUN_140526a50() == 0)
            asSlot.FUN_1409c20d0(1);
        else
            asSlot.FUN_1409c20d0(0);
    }
}

// @0x140c65360
void LapenshardUpgradeSlotPanel::FUN_140c65360(ItemInfoSlot& slot, ASTooltip& tooltip)
{
    MS2Ptr<CItem> spItem = slot.vfunc_25();
    if (spItem.get() != 0)
    {
        MS2Ptr<CItem> spShown = spItem;
        if (spItem->FUN_140526bd0() == 0)
        {
            spShown = spItem->FUN_140524250();
            if (spShown.get() != 0)
                spShown->FUN_140526bf0(FUN_14053feb0(spItem->FUN_1405276c0()));
        }
        tooltip.FUN_1409e0d40(spShown.get());
    }
}

// @0x140c654a0
void LapenshardUpgradeSlotPanel::FUN_140c654a0(CString& strSlot, MS2Ptr<CItem> spItem)
{
    FUN_141415600(&strSlot);
    FUN_141415450(&strSlot, spItem, 0, 0x40401, 0x2020);
    m_slotNames.Add(strSlot);
}

// ---- UILapenshardUpgradeTab ----

// @0x140c67de0
UILapenshardUpgradeTab::UILapenshardUpgradeTab()
    : m_panels(10), m_nState(0), m_ui(0), m_spSource(0), m_ingredients(0x11, 0.75f, 0.25f, 2.25f, 10), m_nTotal(0), m_n_bc(0), m_n_c0(0)
{
    m_panels.AddTail(LapenshardPanelPtr(new LapenshardSourceItemSlotBagPanel(this)));
    m_panels.AddTail(LapenshardPanelPtr(new LapenshardUpgradeSlotPanel(this)));
    m_panels.AddTail(LapenshardPanelPtr(new LapenshardIngredientItemSlotBagPanel(this)));
}

// @0x140c6a2d0
UILapenshardUpgradeTab::~UILapenshardUpgradeTab()
{
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
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (_stricmp("OnAction", szMethod) == 0)
    {
        if (FUN_140c62520() == 0)
            return 1;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nAction = data.FUN_1422b8a10();
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
        if (!FUN_14116d720(FUN_14025e7c0()))
            return 0;
        if (m_spSource == 0)
            return 0;
        COutPacket pkt(0xad, 0);
        pkt.vfunc_o10_1(6);
        pkt.vfunc_o10_3(m_spSource->FUN_1405276c0());
        pkt.vfunc_o10_3(m_n_c0);
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
        int nKind = (unsigned char)packet.vfunc_o8_1();
        switch (nKind)
        {
        case 4:
        {
            Unk_LsPktA rec;
            FUN_1405b6360(&rec, packet);
            m_n_bc = rec.m_n10;
            vfunc_2(5);
            break;
        }
        case 5:
        {
            if (m_nState != 2)
                return;
            Unk_LsPktB rec;
            FUN_1405b6220(&rec, packet);
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
    COutPacket pkt(0xad, 0);
    pkt.vfunc_o10_1(4);
    Unk_LsPktA rec;
    rec.m_nItemId = m_spSource->FUN_1405276c0();
    rec.m_nUid = m_spSource->FUN_140526a50();
    rec.m_nTotal = m_nTotal;
    if (rec.m_nUid == 0)
    {
        rec.m_nSlot = vfunc_11()->FUN_14152f7c0(rec.m_nItemId);
        if (rec.m_nSlot == 0)
            return;
    }
    FUN_1405b6280(&rec, pkt);
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
    COutPacket pkt(0xad, 0);
    pkt.vfunc_o10_1(3);
    Unk_LsRecHead rec;
    rec.m_nItemId = spItem->FUN_1405276c0();
    rec.m_nUid = spItem->FUN_140526a50();
    if (rec.m_nUid == 0)
    {
        rec.m_nSlot = pPlayer->FUN_14152f7c0(rec.m_nItemId);
        if (rec.m_nSlot == 0)
            return;
    }
    FUN_1405b5ec0(&rec, pkt);
    FUN_140710590(pkt);
    vfunc_2(3);
}

// @0x140c68da0
MS2Ptr<CItem> UILapenshardUpgradeTab::FUN_140c68da0()
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
    m_n_c0 = FUN_14047f880(FUN_1401c0d90());
}

// ---- the bag registry helpers and the rest of the upgrade slot panel ----

CString FUN_1422cc860(const CString& strBase, int nIndex);
void FUN_14141f770(CString&, unsigned int, const ItemArray&, MS2Ptr<CItem>(*)(const ItemArray&, int), int, int);
MS2Ptr<CItem> FUN_141420330(const ItemArray&, int);
void FUN_14141f970(CString* pstrBag);
CStringW FUN_14042cb90(CStringW key, const float& v);
CStringW FUN_1419021b0(int a, int b);

// @0x140c5fbb0 (the shield bar), 0x140c68e40 and 0x140c69650 (the upgrade page): plain getters
int UILapenshardShieldBar::FUN_140c5fbb0()
{
    return m_bEnded;
}

// @0x140c68e40
int UILapenshardUpgradeTab::FUN_140c68e40()
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
    FUN_14141f970(&strBag);
    MS2Ptr<CItem> (*pfnGetItem)(const ItemArray&, int) = FUN_141420330;
    FUN_14141f770(strBag, items.GetCount(), items, pfnGetItem, nIconType, nFlags);
}

// @0x140c61010
void FUN_140c61010(CString& strSlot, MS2Ptr<CItem> spItem, int nIconType, int nFlags)
{
    FUN_141415600(&strSlot);
    FUN_141415450(&strSlot, spItem, 0, nIconType, nFlags);
}

// @0x140c65d60
MS2Ptr<Unk_LsRecord> LapenshardUpgradeSlotPanel::FUN_140c65d60()
{
    if (m_spSource == 0)
        return MS2Ptr<Unk_LsRecord>(0);
    return FUN_1409c4b30()->FUN_1405b56a0(m_spSource->FUN_1405276c0());
}

// @0x140c65e00
void LapenshardUpgradeSlotPanel::FUN_140c65e00()
{
    if (m_body == 0)
        return;
    float fProb = (float)m_pTab->FUN_140c68e40() / 100.0f;
    m_ui->Invoke("setSuccessProb", FUN_14042cb90(CStringW(L"s_lapenshard_tabname_upgrade_success_prob"), fProb));
}

// @0x140c65ef0
void LapenshardUpgradeSlotPanel::FUN_140c65ef0()
{
    if (m_spSource == 0)
        return;
    MS2Ptr<Unk_LsRecord> spRec = FUN_1409c4b30()->FUN_1405b56a0(m_spSource->FUN_1405276c0());
    if (spRec == 0)
        return;
    if ((unsigned)spRec->m_nNeed <= 0)
        return;
    if (!(m_pTab->FUN_140c68e20() == 0 || m_pTab->FUN_140c68e20() == 1))
        return;
    CString strSlot = FUN_1422cc860(m_strBind, 0);
    ItemInfoSlot* pBag = FUN_140c69ab0(FUN_1422c8e90(strSlot));
    if (pBag == 0)
        return;
    int nCount = m_pTab->FUN_140c68fd0();
    int nNeed = spRec->m_nNeed;
    m_ui->Invoke("setIngredientLapenshardCount", FUN_1419021b0(nCount, nNeed));
}

// @0x140c67ce0
void LapenshardUpgradeSlotPanel::FUN_140c67ce0()
{
    if (m_body == 0)
        return;
    if (!(FUN_14116d720(FUN_14025e7c0())))
        return;
    if (MS2Ptr<ASMovieClip> spButton = m_body->FUN_140acce30<ASMovieClip>("m_fillIngredientDebug"))
        spButton->vfunc_3(1);
}

// ---- the window: opening conditions ----

// The map the player stands on.
class Unk_LsMapInfo
{
public:
    bool FUN_140965240(int nFlag);                                      // no map
    CFieldData* FUN_140885340();                                        // its field data
    void* m_p0; void* m_p1; void* m_p2; void* m_p3;
};
void FUN_1408850f0(Unk_LsMapInfo* pInfo);
void FUN_140d73aa0(CStringW strMsg, int nType, int nTarget, CStringW strTag);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_141275260(int nStringId, int nA, int nB);

// @0x140c62520
int FUN_140c62520()
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (pPlayer->vfunc_65() == 0)
    {
        Unk_LsMapInfo info = FUN_1403ed2d0()->FUN_141bd30a0();
        if (!info.FUN_140965240(0))
        {
            if (info.FUN_140885340()->FUN_140375660(0x200) == 0)
            {
                FUN_1408850f0(&info);
                return 1;
            }
            FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_lapenshard_disable_field")), 0, 0, CStringW(L""));
            FUN_1408850f0(&info);
            return 0;
        }
        FUN_1408850f0(&info);
        return 0;
    }
    FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_lapenshard_disable_battle")), 0, 0, CStringW(L""));
    return 0;
}

// The singletons the opening conditions read.
class Unk_LsRuleFlags { public: int FUN_1402c4c90(int nRule); };
class Unk_LsRules { public: unsigned char m_pad[8]; Unk_LsRuleFlags m_flags; };
Unk_LsRules* FUN_14025e7b0();
class Unk_LsQuestRef;
class Unk_LsGameTables { public: unsigned char m_pad[0xa040]; Unk_LsQuestRef* m_pQuests; };
Unk_LsGameTables* FUN_1401d3200();
const ATL::CAtlArray<int>& FUN_140a6aa40(Unk_LsQuestRef* pRef);         // the quests that open the window
class Unk_LsQuestDone { public: int FUN_140745590(int nQuest); };
class Unk_LsQuestLog { public: unsigned char m_pad[0x10]; Unk_LsQuestDone m_done; };
Unk_LsQuestLog* FUN_140764020();
CStringW FUN_1416e4df0(int nQuest);                                     // the name of a quest
CStringW FUN_1405c2690(CStringW fmt, const CStringW& arg);

// @0x140c62000
int UILapenshardSystemDialog::vfunc_73()
{
    if (UIDialog::vfunc_73() == 0)
        return 0;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x5b) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    ATL::CAtlArray<int> quests;
    quests.Copy(FUN_140a6aa40(FUN_1401d3200()->m_pQuests));
    if (quests.GetCount() != 2)
        return 0;
    int nNewbie = quests[0];
    int nQuest = quests[1];
    if (FUN_14116d720(FUN_14025e7c0()))
        return 1;
    for (unsigned i = 0; i < quests.GetCount(); ++i)
    {
        if (FUN_140764020()->m_done.FUN_140745590(quests[i]) != 0)
            return 1;
    }
    CStringW strName;
    if (pPlayer->FUN_141654700() == 1)
    {
        strName = FUN_1416e4df0(nQuest);
        FUN_1412751f0(FUN_1405c2690(CStringW(L"s_lapenshard_open_newbie_quest_message"), strName), 1, 1);
    }
    else
    {
        strName = FUN_1416e4df0(nNewbie);
        FUN_1412751f0(FUN_1405c2690(CStringW(L"s_lapenshard_open_quest_message"), strName), 1, 1);
    }
    return 0;
}
// @0x140c612f0
int UILapenshardSystemDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() != 0)
    {
        m_tabs.Add(TabInfoPtr(new TabInfo(CString("equip"), FUN_14028b8e0(CStringW(L"s_lapenshard_tabname_equip")), LapenshardTabPtr(new UILapenshardEquipTab()))));
        m_tabs.Add(TabInfoPtr(new TabInfo(CString("upgrade"), FUN_14028b8e0(CStringW(L"s_lapenshard_tabname_upgrade")), LapenshardTabPtr(new UILapenshardUpgradeTab()))));
        FUN_1419cae20(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    }
    return 0;
}


// ---- the upgrade request ----

// The item table's upgrade recipe of a lapenshard.
class Unk_LsCostEntry : public CPtred
{
public:
    bool FUN_14026b350();                                               // the entry is not an ingredient
    unsigned FUN_14026b500();                                           // its item id
    unsigned char m_pad_18[4];
    int m_n1c;                                                          // +0x1c
    int m_nNeed;                                                        // +0x20 how many are needed
};
class Unk_LsCostList : public CPtred
{
public:
    int FUN_14028b500();                                                // the number of entries
    MS2Ptr<Unk_LsCostEntry> FUN_14028a0f0(int nIndex);
};
class Unk_LsRecipe : public CPtred
{
public:
    MS2Ptr<Unk_LsCostList> FUN_14026c230();                             // the ingredient entries
};

extern char DAT_143ab2a90;                                              // the inventory
extern __int64 DAT_143ab2898;                                           // the money

// Unk_Inventory::FUN_140a5f780 returns the count (inventory.h declares it void).
int FUN_140a5f780(Unk_Inventory* pInv, int nTag, int nGrade);

// @0x140c69670
int FUN_140c69670(unsigned nItemId, int nGrade, int* pnTag)
{
    int nCount = reinterpret_cast<Unk_Inventory*>(&DAT_143ab2a90)->FUN_140a5f180(nItemId, nGrade);
    if (*pnTag != 0)
        nCount = FUN_140a5f780(reinterpret_cast<Unk_Inventory*>(&DAT_143ab2a90), *pnTag, 0);
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
// MS2-FUNCTIONAL: the recipe walk keeps different temporaries than the exe
int UILapenshardUpgradeTab::FUN_140c691f0()
{
    if (m_nState != 1)
        return 0;
    if (m_spSource == 0)
        return 0;
    MS2Ptr<Unk_LsRecord> spRec = FUN_1409c4b30()->FUN_1405b56a0(m_spSource->FUN_1405276c0());
    if (spRec == 0)
        return 0;
    if (0 < spRec->m_nCost && DAT_143ab2898 < spRec->m_nCost)
    {
        FUN_141275260(0x34, 1, 1);
        return 0;
    }
    if ((unsigned)FUN_140c68fd0() < (unsigned)spRec->m_nNeed)
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_lapenshard_tabname_upgrade_lack_ingredient")), 1, 1);
        return 0;
    }
    MS2Ptr<Unk_LsRecipe> spRecipe = spRec->FUN_1405b41b0(m_n_c0);
    if (spRecipe == 0)
        return 0;
    MS2Ptr<Unk_LsCostList> spList = spRecipe->FUN_14026c230();
    int nEntries = spList->FUN_14028b500();
    for (int i = 0; i < nEntries; ++i)
    {
        MS2Ptr<Unk_LsCostEntry> spEntry = spList->FUN_14028a0f0(i);
        if (spEntry == 0)
            continue;
        if (spEntry->FUN_14026b350())
            continue;
        unsigned nItemId = spEntry->FUN_14026b500();
        int nGrade = FUN_14053feb0(nItemId);
        int nNeed = spEntry->m_nNeed;
        int nHave = FUN_140c69670(nItemId, nGrade, &spEntry->m_n1c);
        if (nHave < nNeed)
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_lapenshard_tabname_upgrade_lack_ingredient")), 1, 1);
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
    COutPacket pkt(0xad, 0);
    pkt.vfunc_o10_1(5);
    Unk_LsPktB rec;
    rec.m_nItemId = m_spSource->FUN_1405276c0();
    rec.m_nUid = m_spSource->FUN_140526a50();
    rec.m_n5c = m_n_c0;
    if (rec.m_nUid == 0)
    {
        rec.m_nSlot = pPlayer->FUN_14152f7c0(rec.m_nItemId);
        if (rec.m_nSlot == 0)
            return;
    }
    Unk_LsCopyMap(rec.m_ingredients, m_ingredients);
    FUN_1405b5fd0(&rec, pkt);
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
    void FUN_14175cdb0(int n);                                          // m_bc = n
private:
    unsigned char m_pad_90[0x150 - 0x90];
};

class Unk_LsSkillNames { public: CStringW FUN_141811980(int nKind, unsigned nId); };
Unk_LsSkillNames* FUN_1401a9d70();
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);

// @0x140c5fbd0
// MS2-FUNCTIONAL: the allocation hint temporaries and the skill list walk differ from the exe
void UILapenshardShieldBar::FUN_140c5fbd0()
{
    m_bImpending = 0;
    m_bEnded = 0;
    m_tick.FUN_140268840();
    if (m_spBuff == 0)
        return;
    if (!m_strBind.IsEmpty())
        FUN_1422c8f70(m_strBind);
    m_strBind = "LapenshardShieldBarSkillBindID";
    Unk_LsBuffInfo* pInfo = FUN_14096d810(m_spBuff.operator->());
    SkillSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) SkillSlot(m_strBind, 0, pInfo->m_nSkillId, 0, 0);
    if (pSlot == 0)
        return;
    pSlot->FUN_14175cdb0(1);
    FUN_1422c8f10(m_strBind, pSlot);
    CStringW strLeft = FUN_140c5f9e0();
    m_30->Invoke("open", m_spBuff->m_nId, FUN_14096d810(m_spBuff.operator->())->m_nValue, strLeft, m_strBind);
    UIRewardNotify* pReward = FUN_140938cd0(0x4e5d);
    if (pReward != 0)
    {
        Unk_LsBuffInfo* pBuffInfo = FUN_14096d810(m_spBuff.operator->());
        if (!pBuffInfo->m_skills.FUN_140311670())
        {
            unsigned nSkillId = *pBuffInfo->m_skills.FUN_14018ee60().FUN_1403e8d90();
            CStringW strMsg = FUN_1405c2690(CStringW(L"s_lapenshard_skill_possible_msg"), FUN_1401a9d70()->FUN_141811980(4, nSkillId));
            pReward->FUN_141ac05d0(nSkillId, strMsg, 1);
        }
    }
    m_nPending = 0;
}

// ---- the lapenshard bag filter ----

class Unk_ItemOwnerRef { public: int FUN_140635190(); };                // the binding owner holder of an item
int FUN_1405b5a50(Unk_LsTable* pTable, unsigned nItemId);               // the item is a lapenshard of the table
int FUN_1405b59d0(Unk_LsTable* pTable, unsigned nItemId);               // its category
int FUN_140526790(CItem* pItem, int nJob);                              // the job may use it
int FUN_140526810(CItem* pItem, unsigned nGender);                      // the gender may use it

// @0x140c60920
// MS2-FUNCTIONAL: the three nested item-reference scopes use different temporaries than the exe
void FUN_140c60920(ItemArray* pOut, int bCheckUse, int bWithBound, int bWithEquipped, int bTableOnly, int nKind, __int64 nExcludeUid)
{
    pOut->RemoveAll();
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    ItemArray items;
    reinterpret_cast<Unk_Inventory*>(&DAT_143ab2a90)->FUN_140a60880(0xd, items);
    if (bWithEquipped != 0)
    {
        ATL::CAtlArray<unsigned int> equipped;
        pPlayer->FUN_14152f960(equipped);
        for (size_t i = 0; i < equipped.GetCount(); ++i)
        {
            unsigned nItemId = equipped[i];
            if (bTableOnly == 0 || FUN_1405b5a50(FUN_1409c4b30(), nItemId) != 0)
            {
                MS2Ptr<CItem> spItem(new CItem());
                int nGrade = FUN_14053feb0(nItemId);
                if (spItem->FUN_14052b2e0(nItemId, nGrade, 0, 1) != 0)
                {
                    if (spItem->FUN_140527930()->FUN_140635190() == 2)
                    {
                        __int64 nCharId = pPlayer->FUN_141656a80();
                        CStringW strName = pPlayer->vfunc_77();
                        spItem->FUN_14052b5e0(&nCharId, &strName);
                    }
                    items.Add(spItem);
                }
            }
        }
    }
    if (items.IsEmpty())
        return;
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
            if (FUN_140526790(spItem.get(), pPlayer->FUN_141654700()) == 0)
                continue;
            if (FUN_140526810(spItem.get(), pPlayer->vfunc_78()) == 0)
                continue;
        }
        if (spItem->FUN_140526100() == 0)
            continue;
        if (bWithBound == 0 && spItem->FUN_140528e20())
            continue;
        if (bTableOnly != 0 && FUN_1405b5a50(FUN_1409c4b30(), spItem->FUN_1405276c0()) == 0)
            continue;
        if (nKind != 0 && FUN_1405b59d0(FUN_1409c4b30(), spItem->FUN_1405276c0()) != nKind)
            continue;
        if (nExcludeUid != 0 && spItem->FUN_140526a50() == nExcludeUid)
            continue;
        if (spItem->FUN_1405291f0() == 0)
            pOut->Add(spItem->FUN_140524250());
        else
            pOut->Add(spItem);
    }
}

CStringW FUN_1418fec00(int nType, __int64 nValue, int);                 // money text by pay type

// @0x140c65540
// MS2-FUNCTIONAL: the ingredient rows are built with different temporaries
void LapenshardUpgradeSlotPanel::FUN_140c65540(CString& strBag, MS2Ptr<Unk_LsRecord> spRec, ItemArray& items, LapenshardKindArray& kinds, ASObj& out)
{
    if (spRec->m_nNeed != 0)
    {
        unsigned nItemId = FUN_1409c4b30()->FUN_1405b5af0(spRec->m_nKind);
        int nGrade = FUN_14053feb0(nItemId);
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b2e0(nItemId, nGrade, 0, spRec->m_nNeed) != 0)
        {
            items.Add(spItem);
            int nZero = 0;
            kinds.Add(nZero);
        }
    }
    int nTier = 0;
    if (m_pTab != 0)
        nTier = m_pTab->FUN_140c69650();
    MS2Ptr<Unk_LsRecipe> spRecipe = spRec->FUN_1405b41b0(nTier);
    if (!(spRecipe == 0))
    {
        MS2Ptr<Unk_LsCostList> spList = spRecipe->FUN_14026c230();
        unsigned nEntries = spList->FUN_14028b500();
        for (unsigned i = 0; i < nEntries; ++i)
        {
            MS2Ptr<Unk_LsCostEntry> spEntry = spList->FUN_14028a0f0(i);
            if (spEntry == 0)
                continue;
            if (spEntry->FUN_14026b350())
                continue;
            unsigned nItemId = spEntry->FUN_14026b500();
            int nKind = spEntry->m_n1c;
            int nGrade = FUN_14053feb0(nItemId);
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_14052b2e0(nItemId, nGrade, 0, spEntry->m_nNeed) == 0)
                continue;
            if (nTier != 0)
            {
                if (nKind == 0x5d || nKind == 0x5e || nKind == 0x5f)
                    spItem->FUN_140526910(1);
            }
            items.Add(spItem);
            kinds.Add(nKind);
        }
    }
    FUN_14141f770(strBag, items.GetCount(), items, FUN_141420330, 0x20403, 0x2020);
    ASArray rows(2);
    for (unsigned i = 0; i < items.GetCount(); ++i)
    {
        MS2Ptr<CItem> spItem = items[i];
        if (spItem == 0)
            continue;
        ASObj row(2);
        row.FUN_1407cba60("binding", FUN_1422cc860(strBag, i));
        int nHave = 0;
        if (spItem->FUN_140526100() == 0)
            nHave = FUN_140c69670(spItem->FUN_1405276c0(), spItem->FUN_140526bd0(), &kinds[i]);
        row.FUN_1407cbb20("countText", FUN_1419021b0(nHave, spItem->FUN_140526c50()));
        rows.FUN_1422bc050(row.FUN_1422bb870());
    }
    out.FUN_1409adbe0("ingredient", rows.FUN_1422bb870());
    if (0 < spRec->m_nCost)
        out.FUN_1407cbb20("requireMeso", FUN_1418fec00(1, spRec->m_nCost, 0));
    FUN_140c65ef0();
}

CStringW FUN_14183e9c0(CStringW strName, int nRank);                    // the item name coloured by rank
void FUN_140d01420(const Scaleform::GFx::Value& root, CString strName, int n);   // set a child's mode
void FUN_141416650(ItemInfoSlot* pSlot, Delegate<void(ItemInfoSlot&, ASSlot&)> fn);
void FUN_1414166a0(ItemInfoSlot* pSlot, Delegate<void(ItemInfoSlot&, ASTooltip&)> fn);

// Shows an item's name in the textField of a named child of the upgrade body.
static void Unk_LsSetNameText(MS2Ptr<ASUIComponent>& spBody, const char* szClip, const CStringW& strText)
{
    MS2Ptr<ASMovieClip> clip = spBody->FUN_1409b4560(CString(szClip));
    if (clip.get() != 0)
    {
        MS2Ptr<ASTextField> tf = clip->FUN_1409b4620(CString("textField"));
        if (tf.get() != 0)
        {
            FUN_140d01420(clip->FUN_1422bb890(), CString("textField"), 2);
            tf->FUN_1422c4f00(strText);
        }
    }
}

// @0x140c664e0
// MS2-FUNCTIONAL: the source and result halves share one helper and the temporaries are laid out differently
void LapenshardUpgradeSlotPanel::FUN_140c664e0()
{
    if (m_body == 0)
        return;
    MS2Ptr<ASMovieClip> spSourceSlot = m_body->FUN_1409b4560(CString("m_sourceSlot"));
    if (spSourceSlot.get() != 0)
    {
        CStringW strName;
        if (!(m_spSource == 0))
        {
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_14052b2e0(m_spSource->FUN_1405276c0(), 0, 0, 0) != 0)
            {
                spItem->FUN_140526a70(m_spSource->FUN_140526a50());
                FUN_140c654a0(m_strSource, spItem);
                ItemInfoSlot* pBag = FUN_140c69ab0(FUN_1422c8e90(m_strSource));
                if (pBag != 0)
                {
                    FUN_141416650(pBag, Delegate<void(ItemInfoSlot&, ASSlot&)>(this, &LapenshardUpgradeSlotPanel::FUN_140c652d0));
                    FUN_1414166a0(pBag, Delegate<void(ItemInfoSlot&, ASTooltip&)>(this, &LapenshardUpgradeSlotPanel::FUN_140c65360));
                    ASObj obj(2);
                    obj.FUN_1407cba60("bindID", m_strSource);
                    spSourceSlot->FUN_140acd1f0("setData", AScript(obj));
                    unsigned nItemId = spItem->FUN_1405276c0();
                    strName = FUN_14183e9c0(FUN_1401a9d70()->FUN_141811980(1, nItemId), FUN_14053feb0(nItemId));
                }
            }
        }
        Unk_LsSetNameText(m_body, "m_sourceItemName", strName);
    }
    MS2Ptr<ASMovieClip> spResultSlot = m_body->FUN_1409b4560(CString("m_resultSlot"));
    if (spResultSlot.get() != 0)
    {
        CStringW strName;
        MS2Ptr<Unk_LsRecord> spRec = FUN_140c65d60();
        if (!(spRec == 0) && spRec->m_n20 != 0)
        {
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_14052b2e0(spRec->m_n20, 0, 0, 0) != 0)
            {
                FUN_140c654a0(m_strResult, spItem);
                ItemInfoSlot* pBag = FUN_140c69ab0(FUN_1422c8e90(m_strResult));
                if (pBag != 0)
                {
                    FUN_1414166a0(pBag, Delegate<void(ItemInfoSlot&, ASTooltip&)>(this, &LapenshardUpgradeSlotPanel::FUN_140c65360));
                    ASObj obj(2);
                    obj.FUN_1407cba60("bindID", m_strResult);
                    spResultSlot->FUN_140acd1f0("setData", AScript(obj));
                    unsigned nItemId = spItem->FUN_1405276c0();
                    strName = FUN_14183e9c0(FUN_1401a9d70()->FUN_141811980(1, nItemId), FUN_14053feb0(nItemId));
                }
            }
        }
        Unk_LsSetNameText(m_body, "m_resultItemName", strName);
    }
}

// @0x140c660f0
void LapenshardUpgradeSlotPanel::FUN_140c660f0()
{
    if (!(!(m_ui == 0) && !m_items.IsEmpty() && !m_kinds.IsEmpty()))
        return;
    ASArray rows(2);
    for (unsigned i = 0; i < m_items.GetCount(); ++i)
    {
        MS2Ptr<CItem> spItem = m_items[i];
        if (spItem == 0)
            continue;
        ASObj row(2);
        row.FUN_1407cba60("binding", FUN_1422cc860(m_strBind, i));
        int nHave = 0;
        if (spItem->FUN_140526100() == 0)
            nHave = FUN_140c69670(spItem->FUN_1405276c0(), spItem->FUN_140526bd0(), &m_kinds[i]);
        row.FUN_1407cbb20("countText", FUN_1419021b0(nHave, spItem->FUN_140526c50()));
        rows.FUN_1422bc050(row.FUN_1422bb870());
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
    MS2Ptr<Unk_LsRecord> spRec = FUN_140c65d60();
    if (spRec == 0)
        return;
    if (spRec->m_n20 == 0)
        return;
    m_strBind = "lapenshardUpgradeIngredientSlotBag";
    m_items.RemoveAll();
    m_kinds.RemoveAll();
    ASObj data(2);
    FUN_140c65540(m_strBind, spRec, m_items, m_kinds, data);
    m_ui->Invoke("selectItem", data.FUN_1422bb870());
}

// Binds an item to a named slot of the result animation and returns its coloured name.
static CStringW Unk_LsBindResultSlot(LapenshardUpgradeSlotPanel* pPanel, CString& strSlot, unsigned nItemId, ASObj& obj, const char* szBindKey, const char* szNameKey)
{
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b2e0(nItemId, 0, 0, 0) != 0)
    {
        pPanel->FUN_140c654a0(strSlot, spItem);
        ItemInfoSlot* pBag = FUN_140c69ab0(FUN_1422c8e90(strSlot));
        if (pBag != 0)
            FUN_1414166a0(pBag, Delegate<void(ItemInfoSlot&, ASTooltip&)>(pPanel, &LapenshardUpgradeSlotPanel::FUN_140c65360));
    }
    unsigned nShown = spItem->FUN_1405276c0();
    CStringW strName = FUN_14183e9c0(FUN_1401a9d70()->FUN_141811980(1, nShown), FUN_14053feb0(nShown));
    obj.FUN_1407cba60(szBindKey, strSlot);
    obj.FUN_1407cbb20(szNameKey, strName);
    return strName;
}

// @0x140c67440
// MS2-FUNCTIONAL: the success and fail slots share one helper and the temporaries are laid out differently
void LapenshardUpgradeSlotPanel::FUN_140c67440(bool bSuccess)
{
    if (m_body == 0)
        return;
    {
        CString strLabel("result");
        m_body->vfunc_13(strLabel);
    }
    MS2Ptr<Unk_LsRecord> spRec = FUN_140c65d60();
    if (spRec == 0)
        return;
    if (spRec->m_n20 == 0)
        return;
    ASObj obj(2);
    obj.FUN_1407cbbe0("success", bSuccess != 0);
    CString strSuccess("lapenshardUpgradeSuccessSlotID");
    Unk_LsBindResultSlot(this, strSuccess, spRec->m_n20, obj, "successSlotBindID", "successItemName");
    int bLimit = 0;
    if (bSuccess != 0)
    {
        MS2Ptr<Unk_LsRecord> spNext = FUN_1409c4b30()->FUN_1405b56a0(spRec->m_n20);
        if (!(spNext == 0) && spNext->m_n20 == 0)
            bLimit = 1;
    }
    obj.FUN_1407cb9c0("limitLevel", bLimit);
    if (!(m_spSource == 0))
    {
        CString strFail("lapenshardUpgradeFailSlotID");
        Unk_LsBindResultSlot(this, strFail, m_spSource->FUN_1405276c0(), obj, "failSlotBindID", "failItemName");
    }
    m_ui->Invoke("upgradeComplete", obj.FUN_1422bb870());
    m_spSource = 0;
    m_pTab->FUN_140c68df0();
}

// @0x140c6b1e0
MS2_EMIT_CRT_MEMMOVE_S_COPY(3);

// @0x140c62440
MS2Ptr<LapenshardSystemTabContents> UILapenshardSystemDialog::FUN_140c62440()
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
    FUN_14141f970(&strBag);
    if ((bool)(param.get() != 0) && param->m_pfnGetItem == 0)
        param->m_pfnGetItem = reinterpret_cast<ItemSlotBag::CreateParam::GetItemFn>(FUN_141420330);
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
