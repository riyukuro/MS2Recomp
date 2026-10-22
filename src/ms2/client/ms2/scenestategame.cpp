// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSceneStateGame: the in-field scene state and its field
// packet handlers (see scenestategame.h). The units.tsv range 0x141703a70-0x14174bd70 holds six objs; the other five
// (ridee, uirimlightdialog, rpgcameramode, scalemodifier, scenestatebase) are their own units.
// MS2-UNIT: client\ms2\scenestategame.cpp
// MS2-RANGE: 0x14170bda0-0x14174bd70 .text$mn
// MS2-RANGE: 0x1400ff860-0x140100050 .text$di
// MS2-RANGE: 0x142cb5fd0-0x142cb6450 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$type@W4Unk_SSGJobError@@$0A@@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBW4Unk_SSGJobError@@@Z 0x141745390 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSceneStateGame@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x141745520 ; unique
// MS2-PIN: ??0?$Unk_BmPtr@VUserUGCMapInfo@@@@QEAA@AEBUUnk_BmNewTag@@@Z 0x141745a10 ; unique
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1417473e0 ; unique
// MS2-PIN: ??_GCEnchantOption@@UEAAPEAXI@Z 0x1417475f0 ; unique
// MS2-PIN: ?TypeCast@CSceneStateGame@@UEBA_NIPEAPEAX@Z 0x14174a720 ; unique
// MS2-PIN: ?TypeCast@CSceneStateGame@@UEBA_NIPEAPEBX@Z 0x14174a770 ; unique
// MS2-PIN: ?Make@?$Unk_BmPtr@VUserUGCMapInfo@@@@AEAAXXZ 0x14174a9b0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCSceneStateGame@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14174b7f0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCSceneStateGame@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x14174bbb0 ; unique
// MS2-PIN: ??$Call@VCSceneStateGame@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVCSceneStateGame@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVCSceneStateGame@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x14174bbf0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCSceneStateGame@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14174bc30 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?get@?$MS2Ptr@VCDotDamageRecord@@@@QEBAPEAVCDotDamageRecord@@XZ 0x141747270 ; w95 manual
// MS2-PIN: ?FUN_14174a510@Unk_SSGMyPCScore@@QEAAXH@Z 0x14174a510 ; w95 manual
// MS2-PIN: ??4?$MS2Ptr@VUnk_StateArg22@@@@QEAAAEAV0@AEBV0@@Z 0x141746f20 ; w95 manual
// MS2-PIN: ?SetupClassInfo@CSceneStateGame@@SAXPEAVClassInfo@efd@@_K@Z 0x14174a6c0
// MS2-PIN: ??_7Unk_SkillMagicInfo@@6B@ 0x142f5fb08 ; CSkillMagicControlGuide::SkillContext
// MS2-PIN: ?FUN_14174a560@Unk_SSGNpc@@QEAAXD@Z 0x14174a560
// MS2-PIN: ??1Unk_SSGCharNameResult@@QEAA@XZ 0x141746aa0 ; w97 manual
// MS2-PIN: ?Id@UIExpBar@@SAHXZ 0x141748200 ; w102 manual
// MS2-PIN: ?get@?$MS2Ptr@VCSplashDamageRecord@@@@QEBAPEAVCSplashDamageRecord@@XZ 0x1417472a0 ; w102 manual
// MS2-PIN: ??$Log@IW4Unk_SSGSkillUseError@@@Unk_SSGCommandLog@@QEAAXHHPEB_WAEBIAEBW4Unk_SSGSkillUseError@@@Z 0x141740800 ; w102 manual (fx18: skill id is unsigned, ArgType<unsigned> 0x14015e5d0)
// MS2-PIN: ??0?$MS2Ptr@VCSplashDamageRecord@@@@QEAA@PEAVCSplashDamageRecord@@@Z 0x141745850 ; w109 manual (was auto-order)
// MS2-PIN: ??0?$MS2Ptr@VUGCMapBlueprintInfo@@@@QEAA@PEAVUGCMapBlueprintInfo@@@Z 0x141745880 ; w109 manual (was auto-order)
// MS2-PIN: ??0?$MS2Ptr@VUGCMapDesignInfo@@@@QEAA@PEAVUGCMapDesignInfo@@@Z 0x1417458f0 ; w109 manual (was auto-order)
// MS2-PIN: ??_GNotifyChangeMyLevel@@UEAAPEAXI@Z 0x141747890 ; w109 manual
// MS2-PIN: ??1NotifyChangeMyLevel@@UEAA@XZ 0x141746be0 ; w109 manual
// MS2-PIN: ?Reference@?$MS2Ptr@VCDotDamageRecord@@@@CAXPEAVCDotDamageRecord@@@Z 0x14174a850 ; w109 manual (was auto-order)
// MS2-PIN: ?Reference@?$MS2Ptr@VCMsgBoxData@@@@CAXPEAVCMsgBoxData@@@Z 0x14174a870 ; w109 manual (was auto-order)
// MS2-PIN: ?Ref@?$Unk_BmBoxPtr@USpecialNPCInfo@@@@CAXPEAVCPtred@@@Z 0x14174a8b0 ; w109 manual (byte-identical look-alike slot)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIArcadeLifeBar@@@@YAPEAVUIArcadeLifeBar@@H@Z 0x1417424f0 ; w118 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIArcadeMainDialog@@@@YAPEAVUIArcadeMainDialog@@H@Z 0x141742590 ; w118 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIArcadeTextEffectDialog@@@@YAPEAVUIArcadeTextEffectDialog@@H@Z 0x141742630 ; w118 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIHpBar@@@@YAPEAVUIHpBar@@H@Z 0x141742c80 ; w118 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIUGCPortalDialog@@@@YAPEAVUIUGCPortalDialog@@H@Z 0x141743410 ; w118 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIUGCCubeNoticeDialog@@@@YAPEAVUIUGCCubeNoticeDialog@@H@Z 0x1417432d0 ; w118 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIUGCPVPControlDialog@@@@YAPEAVUIUGCPVPControlDialog@@H@Z 0x141743370 ; w118 manual (RTTI)
// MS2-PIN: ??1Unk_SSGUserChat@@QEAA@XZ 0x1417469a0 ; w118 manual
// MS2-PIN: ??4?$Unk_PayloadPtr@VNoticeCubeInfo@@@@QEAAAEAV0@PEAVNoticeCubeInfo@@@Z 0x141746eb0 ; w118 manual
// MS2-PIN: ??$Unk_SSGGetDialog@VUIHomeResizeDialog@@@@YAPEAVUIHomeResizeDialog@@H@Z 0x141742be0 ; w120 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIWatchAGameDialog@@@@YAPEAVUIWatchAGameDialog@@H@Z 0x141743690 ; w120 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIHideAndSeekResultDialog@@@@YAPEAVUIHideAndSeekResultDialog@@H@Z 0x141742b40 ; w120 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIApartmentDialog@@@@YAPEAVUIApartmentDialog@@H@Z 0x141742450 ; w131 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIAdventureLevelDialog@@@@YAPEAVUIAdventureLevelDialog@@H@Z 0x141742310 ; w131 manual (RTTI)
// MS2-PIN: ??$Unk_SSGGetDialog@VUIAdventureLevelOldDialog@@@@YAPEAVUIAdventureLevelOldDialog@@H@Z 0x1417423b0 ; w131 manual (RTTI)
// MS2-PIN: ??0?$Unk_BmPtr@VUserUGCMapInfo@@@@QEAA@AEBV0@@Z 0x1417459d0 ; w120 manual (call site)
// MS2-PIN: ?get@?$Unk_PayloadPtr@VObjectWeaponInfo@@@@QEBAPEAVObjectWeaponInfo@@XZ 0x1417472b0 ; w120 manual (call site)
// MS2-PIN: ??_GNotifyChangeMyJob@@UEAAPEAXI@Z 0x141747850 ; w125 manual
// MS2-PIN: ??1NotifyChangeMyJob@@UEAA@XZ 0x141746bc0 ; w125 manual
// MS2-PIN: ??1Unk_MagicTag@@UEAA@XZ 0x141746cb0 ; w125 manual (RTTI SkillTargetRecord)
// MS2-PIN: ??_7Unk_MagicTag@@6B@ 0x142f5faf8 ; w125 manual (RTTI SkillTargetRecord)
// MS2-PIN: ??4?$MS2Ptr@VUnk_PCBaseComp_b18@@@@QEAAAEAV0@AEBV0@@Z 0x141746e70 ; w125 manual (this obj's copy; mypc has 0x141532e00)
// MS2-PIN: ?IsNull@?$MS2Ptr@VCInteractObject@@@@QEBA_NXZ 0x140a7b5e0 ; w125 manual (call site 0x14172d0f0; the in-range look-alike 0x141747040 is called only by stubs 0x14171dc40/0x141732b20)
// MS2-PIN: ?get@?$MS2Ptr@VCInteractObjectData@@@@QEBAPEAVCInteractObjectData@@XZ 0x1411926f0 ; w125 manual (call site 0x14172d0f0; look-alike 0x141747280 is called by stub 0x141732b20)
// MS2-PIN: ??0?$MS2Ptr@VNotifyChangeBuff@@@@QEAA@PEAVNotifyChangeBuff@@@Z 0x141745880 ; w131 manual (call sites 0x141720480; the look-alike 0x141745850 is called by 0x141746eb0)
// MS2-PIN: ?get@?$MS2Ptr@VUnk_SnowmanContext@@@@QEBAPEAVUnk_SnowmanContext@@XZ 0x1417472c0 ; w131 manual (only caller 0x141736240; the look-alike 0x141747350 is called by stub 0x141732b20)
// MS2-PIN: ??1NotifyLearnEmotion@@UEAA@XZ 0x141746c60 ; w131 manual (called by its ??_G 0x141747950)
// MS2-PIN: ??1NotifyKillPlayer@@UEAA@XZ 0x141746c20 ; w131 manual (called by its ??_G 0x141747910)
// MS2-PIN: ??1NotifyChangedTokenMoney@@UEAA@XZ 0x141746c00 ; w131 manual (called by its ??_G 0x1417478d0)
// MS2-PIN: ??_GNotifyChangedTokenMoney@@UEAAPEAXI@Z 0x1417478d0 ; w131 manual (vftable slot 0)
// MS2-PIN: ??1NotifyActiveMyCodiTab@@UEAA@XZ 0x141746ba0 ; w131 manual (called by its ??_G 0x141747810)
// MS2-PIN: ??_GNotifyKillPlayer@@UEAAPEAXI@Z 0x141747910 ; w131 manual (look-alike of the enchant map's CNode ??_G)
// MS2-PIN: ??0CAdventureLevelMissionData@@QEAA@AEBV0@@Z 0x141745bd0 ; w131 manual (copy; called by the make_pair pair ctor 0x141740490)
// MS2-PIN: ??0CAdventureLevelMissionData@@QEAA@$$QEAV0@@Z 0x141745b60 ; w131 manual (move; called by the pair ctor 0x141740530)
// MS2-PIN: ??$?0AEBIAEAVCAdventureLevelMissionData@@$0A@@?$pair@IVCAdventureLevelMissionData@@@std@@QEAA@AEBIAEAVCAdventureLevelMissionData@@@Z 0x141740490 ; w131 manual (make_pair in OnPrestige)
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@2@@Z 0x14174af90 ; w131 manual (ICF-folded with map<unsigned,Unk_ALMissionState>, callees 0x1409347f0/0x140931d80)
// MS2-PIN: ??1?$TPtredDummy@USpecialNPCInfo@@@@UEAA@XZ 0x141746800 ; w131 manual (called by its ??_G 0x1417475b0)
// MS2-PIN: ??_G?$TPtredDummy@USpecialNPCInfo@@@@UEAAPEAXI@Z 0x1417475b0 ; w131 manual (size 0x38 delete, calls 0x141746800)
// MS2-FUNCTIONAL 0x141745310: pinned by call-site order (w131); the exe body is a non-leaf wrapper calling 0x141745390,
//   not the leaf std::forward<const int&> our VS2017 15.9 <utility> emits (map<int,bool> emplace chain of another STL drop)
// MS2-PIN: ??$make_type@W4Unk_SSGJobError@@@internal@fmt@@YA_KAEBW4Unk_SSGJobError@@@Z 0x141745310 ; fx24: calls MakeValue::type<Unk_SSGJobError> 0x141745390 (0x141745370 calls the SkillUseError one); was a forward<int const &> filler
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@@Z 0x14174aec0 ; w131 manual (call site 0x14174aec0/0x14174b750)
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@V32@@Z 0x14174ba20 ; w131 manual (call site 0x14174b930)
// MS2-PIN: ??$format_arg@_WW4Unk_SSGInteractResult@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_SSGInteractResult@@@Z 0x141744d40 ; w131 manual (call site 0x1417450d0)
// MS2-PIN: ??$format_arg@_WW4Unk_SSGEnchantExpError@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_SSGEnchantExpError@@@Z 0x141744e60 ; w131 manual (call site 0x141745100)
// MS2-PIN: ??$format_arg@_WW4Unk_SSGJobError@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_SSGJobError@@@Z 0x141744f80 ; w131 manual (call site 0x141745130)
// MS2-PIN: ??1Unk_1407a7d20@@QEAA@XZ 0x141746960 ; w131 manual (call site 0x141728c20)
// MS2-PIN: ??C?$MS2Ptr@VCEnchantOption@@@@QEBAPEAVCEnchantOption@@XZ 0x141747350 ; w131 manual (call site 0x141732b20)
// MS2-PIN: ?Find@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@_J@Z 0x141747bc0 ; w131 manual (call site 0x14174a3d0)
// MS2-PIN: ?InsertImpl@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_JH@Z 0x1417484c0 ; w131 manual (call site 0x1417496f0)
// MS2-PIN: ?ReleaseImpl@?$Unk_BmBoxPtr@USpecialNPCInfo@@@@AEAAXPEAX@Z 0x14174b370 ; w131 manual (call site 0x14174b230)
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@UUnk_PropertyCacheEntry@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVutf8string@efd@@UUnk_PropertyCacheEntry@@@std@@PEAX@std@@_K@Z 0x14174b850 ; w131 manual (call site 0x14174b8a0)
// MS2-PIN: ??$format_arg@_WW4Unk_SSGSkillUseError@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_SSGSkillUseError@@@Z 0x141744c20 ; w131 manual (call site 0x1417450a0)
// MS2-PIN: ??$?0IVCAdventureLevelMissionData@@$0A@@?$pair@$$CBIVCAdventureLevelMissionData@@@std@@QEAA@$$QEAU?$pair@IVCAdventureLevelMissionData@@@1@@Z 0x141740530 ; w131 manual (called by construct 0x141744ac0)
#define NOMINMAX                        // NxPhysics (interactobject.h)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestategame.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestategame.h"
#include "networkservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ridee.h"
#include "reactor.h"
#include "cubecraft_1.h"
#include "statemanager.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/commonstruct_wb.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/effectquery.h"
#include "uimasterydialog.h"
#include "uiupperhuddialog.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/placeholder/stringidinterface.h"
#include <NiColor.h>
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/stateemotionidle.h"
#include "uigalleryeventdialog.h"
#include "uilongtermattendgiftdialog.h"
#include "uisnowmaneventdialog.h"
#include "ms2/placeholder/sidepopuptalkparam.h"
#include "ms2/placeholder/dropitem.h"
#include "ms2/placeholder/cube.h"
#include "ms2/commonfiles/blackmarketitemoption.h"   // Unk_BmBoxPtr / Unk_BmNewTag
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/ms2format.h"
#include <efd/Helpers.h>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include <efd/StdContainers.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include "ms2/placeholder/csadventurelevelmission.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"   // Unk_Int3
#include "ms2/commonfiles/ugcmapdata.h"          // CubeOwner
#include "ms2/unnamed/unit_140fa9eb0.h"
#include "uiugccubepalettedialog.h"
#include "ms2/commonfiles/userproxy.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "cubemapinformationservice_3.h"   // FittingDollData
#include "magicdata.h"                    // CMagicModel, Unk_MagicTagPtr (0x3d mode 0)
#include "ms2/commonfiles/timeutil.h"     // Unk_ServerClock
#include "ms2/client/ms2/uihideandseekresultdialog.h"
#include "interactobject.h"                // CInteractObject (0x63)
#include "entityworldmanager.h"
#include "ms2/commonfiles/famegradedata.h"   // Unk_FameAlliance (0xa8)
#include "statedata.h"                   // StateSummonData, StateHoldData (0x79)
// usermail.h declares FUN_1403ed2d0 over its own Unk_MailSession stand-in; this unit's world type is Unk_SSGWorld,
// so the header's declaration is renamed out of the way.
#define FUN_1403ed2d0 FUN_1403ed2d0_UserMail
#include "ms2/commonfiles/usermail.h"     // CUserMail (DAT_143ab2ee0), CMailInfo (0x54)
#undef FUN_1403ed2d0
#include <egf/EntityIDFactory.h>
#include <egf/Entity.h>
// the exe calls the unit_1410dbc10 specialization (0x1410dc360, cache refresh + engine write), not an instantiation
template <> egf::PropertyResult egf::Entity::SetPropertyValue<int>(egf::PropertyID propID, const int& data);
// MS2Ptr<CProxyGameObject>::operator-> / get are the exe's out-of-range copies (0x1406c71d0 / 0x1406c71b0); left
// undefined here so they are not paired with the unit's in-range look-alikes.
template <> CProxyGameObject* MS2Ptr<CProxyGameObject>::operator->() const;
template <> CProxyGameObject* MS2Ptr<CProxyGameObject>::get() const;

// ---- singletons and callees (names inferred; unit-local stand-ins) -----------------------------------------------
CNetworkService* FUN_140714f90();

// The world/field manager (FUN_1403ed2d0).
// 0x1417212d0: a named field object (the cube/ridee field object of ridee.cpp/state.cpp).
class Unk_RideeFieldObj : public CPtred { public: void FUN_140ade420(int nState, int nFlag); void FUN_140adeaa0(int nA, int nB, int nC); };
class Unk_SSGWorld
{
public:
    bool FUN_141bc32d0(class CRegionSkillObject* pObj);   // register a region skill
    class CRegionSkillObject* FUN_141bc3360(int nId);
    void FUN_141bc33d0(int nId);
    MS2Ptr<Unk_RideeFieldObj> FUN_141bc4e70(CString strName);
    void FUN_141bd9950(const CString& strUrl);              // open in the external browser
    void FUN_141bbae40(IWorldServiceCallback* cb);          // register a callback
    void FUN_141bbae80(IWorldServiceCallback* cb);          // unregister it
    void FUN_141bbc580(int a, int b);
    int FUN_141bcfd10();                                    // world state (4 = in field)
    bool FUN_141bcb0a0();                                   // when set, the mail notices are skipped
    int FUN_141bcfbd0();                                    // loading complete
    void FUN_141bdb690();
    void FUN_141bbbcf0(int nMapId, int n);
    GameObject* FUN_141bd1180(int nId);
    PC* FUN_141bd1290(int nId);
    void FUN_141bda290(const std::vector<unsigned>* ids);    // strip and hide the entities of the ids
    PCBase* FUN_141bd1200(int nId);
    int FUN_141bbb1e0(GameObject* pObj, int nA, int nB);    // add an object to the world
    int FUN_141bd1a10(PCBase* pActor);
    PCBase* FUN_141bd1530(__int64 nUid);                    // the actor by its object uid
    void FUN_141bc5ab0(efd::SmartPointer<CSkillMagicControlGuide> spGuide);   // keep the skill guide alive
    PCBase* FUN_141bd3620();
    void FUN_141bd92c0(float fX, float fY, float fZ, int n);
    void FUN_141bd9380();
    class Unk_SSGNpc* FUN_141bd1320(int nId);
    class CPet* FUN_141bd13a0(int nId);
    void FUN_141bc92e0(CString strName);
    void FUN_141bc9020(CString strName, MS2Ptr<Unk_PCBaseComp_b18> spSkill, CString strBone, unsigned char nFlag);   // 0x75 start a named field skill
    void FUN_141bc9560(CString strName, CString strModel, unsigned char nFlag);   // 0x75 mode 2
    void FUN_141bc9480(CString strName);
    void FUN_141bca220();
    void FUN_141bca6d0(CInPacket& packet);
    void FUN_141bd3d70(Unk_StreamPoint pos, Unk_StreamPoint rot);
    void FUN_141bbbe40(int nMapId, int a, int nPortal);
    MyPC* FUN_141bd0cc0();                                  // the local player actor
    MS2Ptr<class Unk_SSGNamedObj> FUN_141bc5a20(CString strName);   // a named field object (0x73)
    void FUN_141bc5420(CInPacket& packet);                  // 0x73 mode 3
    void FUN_141bc5830(CString strName);                    // remove a named field object
    struct Unk_SSGEntListPtr FUN_141bd0420(unsigned int nModelHash);   // the entities of a model
    void FUN_141bc9aa0(MS2Ptr<CProxyGameObject> spProxy);   // add a field object proxy
    void FUN_141bc9b30(int nId);                            // remove one
    MS2Ptr<CProxyGameObject> FUN_141bc9be0(int nId);        // find one
    int FUN_141bd98d0();                                    // current field id
    void FUN_141bd9c20(CInPacket& packet);
    void FUN_141bdb6a0();                                   // hide the world tooltips
    void FUN_141bdb7a0();                                   // show them
    // interact objects (0x63)
    void FUN_141bc6860(const CString& strName, int nA, int nB);
    MS2Ptr<CInteractObject> FUN_141bc66b0(const CString& strName);  // find one by name
    void FUN_141bc6930(int nKind, int n);
    void FUN_141bc6a20(int n);
    void FUN_141bc6760(const CString& strName, int nA, int nB, int nC);
    void FUN_141bc5c40(MS2Ptr<CInteractObject> spObj);      // add one
    void FUN_141bc5d60(const CString& strName);              // remove one
    int FUN_141bd3060();                                    // current channel's map id
    int FUN_141bc1720(MS2Ptr<class CPortal> spPortal);      // register a field object (portal) (0x48)
    void FUN_141bc24e0(int nId);                            // unregister a field object
    MS2Ptr<class CPortal> FUN_141bc2800(int nId);            // a field object by id
    void FUN_141bc3140(int nId, int nVisible, int nEnabled, int nHidden);
    void FUN_141bc31d0(int nId, Unk_StreamPoint kPos, Unk_StreamPoint kScale);
    void FUN_141bc5e20(int nType);                          // refresh the field objects of a type (0xcd)
};
Unk_SSGWorld* FUN_1403ed2d0();

// The UI manager (FUN_1403ed2b0).
class Unk_SSGUIMgr
{
public:
    void FUN_141add040(int nId);
    void FUN_141adc050();
    void FUN_141ad93b0();
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
    void FUN_141adc400();
    int FUN_141adc940(int nId);
    void FUN_141ad9a60(CString strName);
    void FUN_141adc530(int nId);
    void FUN_141add1f0();
    void FUN_141adc5d0(int nId);
    void FUN_141add0b0(int nId);
    void FUN_141add1b0(int nSlot, bool bOn);                // enable one hot key slot
    void FUN_141ada6f0(int nScene);
    void FUN_141ad9e50(int nScene);
    void FUN_141adafd0(int nScene);
    void FUN_141adad20(int nScene);
    void FUN_141ada610(int nScene);
    void FUN_141adb2a0(int nScene);
    void FUN_141ad9650();
    void FUN_141ad9b30();
    bool FUN_141ad9b60();
    void FUN_141ad9c10();
    void FUN_141ad9c40(MS2Ptr<class CGemBase> spGem);       // show a socketed gem
};
Unk_SSGUIMgr* FUN_1403ed2b0();

class Unk_SSGGuildMgr
{
public:
    void FUN_1413bc1f0(__int64 nGuildId, CStringW strName);
    void FUN_1413bcd10();
    void FUN_1413bc250(CInPacket& packet);                  // 0xb6 mode 4: the guild of a guild battle
};
Unk_SSGGuildMgr* FUN_1403ed290();

class Unk_SSGEffectMgr
{
public:
    void FUN_1411a6060(int nHandle);                        // remove an effect
    void FUN_1411a4f40(CString strName, const NiPoint3& kPos);
    void FUN_1411a4a00(Unk_EffectQuery* pQuery);                    // play once
    int FUN_1411a4a00(struct Unk_SSGEffectReq& req);                // the same, with the full 0x70 request
    int FUN_1411a49c0(struct Unk_SSGEffectReq& req);                // play, returns the handle
    void FUN_1411a5110(CString strPath, CString strName, CString strBone, int a, struct Unk_SSGXform* pXform, float fScale, int b);   // play a sound
    void FUN_1411a8e50(int nSerial);                        // a skill cast object serial was used
};
Unk_SSGEffectMgr* FUN_1403ed280();

class Unk_SSGOption
{
public:
    void FUN_140a1f7f0(bool bInField);
    void FUN_140a1f8a0();
    void FUN_140a1f970(const CString& strKey, const CString& strValue);
};
Unk_SSGOption* FUN_140d8ee90();

class Unk_SSGInput
{
public:
    void FUN_140ad1ef0();
    void FUN_140ad1da0(unsigned int nMsg, int wParam, int lParam);
};
Unk_SSGInput* FUN_140953f30();

class Unk_SSGKeyState { public: int FUN_1422aeed0(int n); };
Unk_SSGKeyState* FUN_14025e7a0();
class Unk_SSGKeyboard { public: bool FUN_14116d950(int nKey, bool bA, int b); bool FUN_14116d9c0(int nKey, bool bA, int b); };
Unk_SSGKeyboard* FUN_14025e7c0();

class Unk_SSGQuery { public: int FUN_140a18070(); void FUN_140aeb1a0(); void FUN_140aecbb0(int a, int b, bool c); void FUN_140aeaf40(MyPC* pTarget, int n); };
Unk_SSGQuery* FUN_1409478c0();

// OnEnter/OnLeave service calls
class Unk_143a09680 { public: void* m_a; void* m_b; };
class Unk_1409879 : public Unk_143a09680 { };
Unk_1409879 FUN_140987930(const void*);
extern char DAT_143a09680[];
void* FUN_140aae430();
void FUN_141489ff0(void*, Unk_143a09680);
void* FUN_14086d260();
double FUN_141473280(void*);
void* FUN_140c7a250();
void FUN_140db8eb0(void*);
class Unk_SSG931510* FUN_140931510();
void FUN_140d9f040(void*);
void FUN_140d9f0c0(void*);
void* FUN_140e800e0();
void FUN_140aad0d0(void*);
void FUN_140aadd70(void*);
void* FUN_14015a050();
void FUN_140ceac00(void*);
void* FUN_1409eed70();
void FUN_140ad68a0(void*);
class Unk_SSGUgcMgr { public: int FUN_14187f3b0(); void FUN_1418894d0(); void FUN_141889150(); void FUN_14188ff10(CInPacket& packet); };   // UGC manager
Unk_SSGUgcMgr* FUN_14052d220();
void* FUN_1409670d0();
void FUN_14162b790(void*);
void* FUN_1409a8b00();
void FUN_1409a4090(void*);

// Reconnect (as CSceneStateMulti/CSceneStateMove::OnUpdate)
extern CString DAT_143ab2a48;
extern unsigned short DAT_143ab2848;
extern int DAT_1439f4a78;
extern int DAT_143ab285c;
extern int DAT_143ab2860;
extern unsigned char DAT_143ab284b;
extern void (*DAT_143b03490)(short, unsigned char, const char*);
extern unsigned char DAT_1430c3b20;
CString FUN_14016a600(const wchar_t*, int);
CStringW FUN_14062b4f0(CStringW, const int&);
CStringW FUN_1408116a0(int, const int&);
void* FUN_141540270(int);
void FUN_1419e0050(void*, const CStringW&);
void FUN_141b6fcf0(const CStringW&, const CStringW&, int);

// The player's sub actors (FUN_141662440: ride/pet slots 0..2); slot 126 is their per-frame update.
class Unk_SSGSubActor : public PCBase
{
public:
    virtual void vfunc_124();
    virtual void vfunc_125();
    virtual void vfunc_126();
};
void FUN_141524a80(MyPC* pPC, int n);
Unk_SSGSubActor* FUN_141662440(MyPC* pPC, int nSlot);

// OnPacket direct dispatch targets
class Unk_SSGMisc2d80 { public: void FUN_140de3480(CInPacket& packet); void FUN_140de2a00(); };
extern Unk_SSGMisc2d80 DAT_143ab2d80;
class Unk_SSGArcade { public: void FUN_140b8c260(CInPacket& packet); };
Unk_SSGArcade* FUN_140ee0d10();
void FUN_140ceab50(void* pMgr, CInPacket& packet);
void FUN_140ad5f00(void* pMgr, CInPacket& packet);
class Unk_SSGDialog4edc { public: void FUN_1412a53e0(CInPacket& packet); };
Unk_SSGDialog4edc* FUN_140ce84f0(int nId);
class Unk_SSGSlotMgr { public: void FUN_141b83750(CInPacket& packet); };
Unk_SSGSlotMgr* FUN_1409eed90();

// The dialogs this unit looks up by id (GetDialog<T> instances 0x141742310..0x141743690).
// 0x4e6a / 0x4f40 / 0x4ee9: web browser dialogs (slot 89 navigates).
class UIWebBrowser : public UIWebBrowserBase { public: void FUN_14135ec00(const CString& strUrl, bool bShow); };
class Unk_SSGDlg4f24 { public: void FUN_140e2e030(CString strUrl); };
Unk_SSGDlg4f24* FUN_140b2d030(int nId);                     // GetDialog<T>(0x4f24)
class UIWebBrowserPopup : public UIWebBrowserBase { };
UIWebBrowser* FUN_140c43790(int nId);                       // GetDialog<UIWebBrowser>
UIWebBrowserPopup* FUN_140beafe0(int nId);                  // GetDialog<UIWebBrowserPopup>
class UINoticeDialog : public UIWebBrowserBase
{
public:
    void FUN_141009680(CInPacket& packet);
};

template <class T> T* Unk_SSGGetDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// ---- packet handler callees ------------------------------------------------------------------------------------
// 0x9: the field-enter request body (account id, two ints, machine id), encoded by FUN_1401f9d20.
class Unk_SSGMachineId
{
public:
    Unk_SSGMachineId& FUN_14067c080(const Unk_SSGMachineId& other);
    unsigned char m_data[16];
};
class Unk_SSGEnterRequest
{
public:
    Unk_SSGEnterRequest();                                  // 0x141540ca0
    void FUN_1401f9d20(COutPacket& out);
    __int64 m_nAccountId;                                   // +0x00
    int m_n8;                                               // +0x08
    int m_nC;                                               // +0x0c
    Unk_SSGMachineId m_machineId;                           // +0x10
};
MS2_CHECK_SIZE(Unk_SSGEnterRequest, 0x20);
class Unk_SSGMachine { public: const Unk_SSGMachineId& FUN_140d4fdf0(); };
Unk_SSGMachine* FUN_140aadf70();
extern __int64 DAT_143ab2820;
extern __int64 DAT_143ab2920;
extern int DAT_143ab284c;
extern int DAT_143ab2850;

// 0x15: field enter
class Unk_SSGIntList
{
public:
    void FUN_1402c2830();                                   // clear
    void FUN_1401855a0(int n);                              // push_back
    int FUN_140408410(const unsigned* pValue);              // index of a value (-1: absent)
};
extern Unk_SSGIntList DAT_143ab3058;
extern Unk_SSGIntList DAT_143ab3078;
extern Unk_SSGIntList DAT_143ab3098;
void FUN_14092f420();
int FUN_14092f640();
void FUN_1412751b0(const CStringW& strMsg, int nType);
extern int DAT_143ab2864;
extern __int64 DAT_143ab2828;
extern int DAT_1439f4a7c;
extern int DAT_1439f4a80;
extern __int64 DAT_143ab28a0;
extern __int64 DAT_143ab28a8;
extern __int64 DAT_143ab2898;
extern __int64 DAT_143ab28b0;
extern __int64 DAT_143ab28b8;
extern __int64 DAT_143ab28c0;
extern __int64 DAT_143ab28c8;
extern __int64 DAT_143ab28d0;
extern __int64 DAT_143ab28d8;
extern __int64 DAT_143ab28e0;
extern __int64 DAT_143ab28e8;
extern __int64 DAT_143ab28f0;
extern int DAT_143ab2918;
void FUN_1409304d0(__int64 a, __int64 b, __int64 c, __int64 d);
void FUN_140930af0(__int64 a);
class Unk_SSGChatTab { public: void FUN_140dbde50(int n); };
// The game-mode service (FUN_140f97ef0): the chat tab, plus the individual PvP (duel) state at +0x100.
class Unk_SSGChatHolder
{
public:
    Unk_SSGChatTab* FUN_140f97f00();
    void FUN_141280c60();                                   // 0xb6 'f'
    int FUN_1412818a0();                                    // the duel state before the reset (1: was matched)
    void FUN_141280cd0(int nMode, CInPacket& packet);       // the other 0xb6 modes
    void FUN_14174a530(int nState, int nArg) { m_nPvPState = nState; m_nPvPArg = nArg; }
private:
    char m_pad0[0x100];
    int m_nPvPState;                                        // +0x100
    int m_nPvPArg;                                          // +0x104
};
Unk_SSGChatHolder* FUN_140f97ef0();
class Unk_SSGProfile
{
public:
    static void FUN_141b77e50(const CString& str);
    static void FUN_141b77e90(const CString& str);
    static void FUN_141b77ed0(const CString& str);
    void FUN_141b794e0(CString& strOut, const char* pszUrl);  // resolve the url macros
    void FUN_141b78cf0(int nType, const CString& strUrl);  // open the url externally
};
Unk_SSGProfile* FUN_140cc18a0();
class Unk_SSGChannelDialog { public: void FUN_141ad2ea0(int nChannel); };
Unk_SSGChannelDialog* FUN_14136f520(int nId);
class Unk_SSG1c0d90 { public: void FUN_1404766e0(); bool FUN_14047f0f0(); bool FUN_14047f300(); void FUN_1404779b0(CInPacket& packet); MS2Ptr<class Unk_SnowmanContext> FUN_14047d050(); };   // game rules (the two are pet-taming event checks)
Unk_SSG1c0d90* FUN_1401c0d90();
class Unk_SSG3ed2a0 { public: void FUN_1407ce240(); };
Unk_SSG3ed2a0* FUN_1403ed2a0();
class Unk_SSGHome { public: __int64 FUN_14034a1b0(); };
Unk_SSGHome* FUN_1414a56d0();
class Unk_SSGConfig { public: bool FUN_14036e5b0(); bool FUN_14036d570(int nOption); };
Unk_SSGConfig* FUN_140166410();
class Unk_SSGB05bf0 { public: void FUN_140b06450(int n); };
Unk_SSGB05bf0* FUN_140b05bf0();

// 0x2b: the UGC map (house) info of the current field
class UGCMapDesignInfo : public CPtred
{
public:
    UGCMapDesignInfo();
    int m_nId;                                              // +0x18
    CString m_strName;                                      // +0x20
    __int64 m_nTime;                                        // +0x28
};
MS2_CHECK_SIZE(UGCMapDesignInfo, 0x30);
class UGCMapBlueprintInfo : public CPtred
{
public:
    UGCMapBlueprintInfo();
    int m_nId;                                              // +0x18
    CString m_strName;                                      // +0x20
    __int64 m_nTime;                                        // +0x28
};
MS2_CHECK_SIZE(UGCMapBlueprintInfo, 0x30);
// Three byte-sized house rules, decoded from the packet.
class Unk_SSGHouseRule
{
public:
    Unk_SSGHouseRule();                                     // 0x140b68e60
    void FUN_140b68ec0(CInPacket& packet);
    void FUN_140b68f60();
    unsigned char m_a, m_b, m_c;
};
MS2_CHECK_SIZE(Unk_SSGHouseRule, 3);
class NoticeCubeInfo;
class Unk_Service6100017 : public efd::ISystemService
{
public:
    void FUN_1410cb4c0(MS2Ptr<FittingDollData> spDoll);    // add a fitting doll (0x7b)
    // 0x69 (UGC housing) results
    void FUN_1410c4240(int nA, int nB, const CStringW& strName, __int64 nC, __int64 nCharId);
    void FUN_1410d6590(int nError);                         // report a housing error code
    void FUN_1410c44b0(int nA, int nB, int bFlag);
    void FUN_1410c4850(__int64 nItemUid, Unk_Int3 kPos, const CubeItemInfo& info, float fRot, int nA, int nB, bool bFlag,
        int nC, int nD, Unk_PayloadPtr<NoticeCubeInfo> spNotice);   // a cube placed
    void FUN_1410c4b50(Unk_Int3 kPos, bool bFlag);          // a cube removed
    void FUN_1410c4d80(Unk_Int3 kPos, float fRot);          // a cube rotated
    void FUN_1410c4e20(__int64 nItemUid, Unk_Int3 kPos, const CubeItemInfo& info, float fRot, bool bFlag, int nA, int nB);
    void FUN_1410caf20(Cube* pCube, int nValue);
    __int64 FUN_1410c3180();                                // the house owner
    bool FUN_1410c35c0();                                   // the player is in a house
    void FUN_1410d5350();
    void FUN_1410c51d0(int nA, int nB, CStringW strName);
    void FUN_1410c7a50(int nA, int nB, int nC, __int64 nD);
    // 0x6a (housing snapshot)
    void FUN_1410c3f50(int nState);
    void FUN_1410bbc00(int nBlock, int nState);
    Unk_CubeOwners* FUN_1410d3360();                        // the owners by group and block
    void FUN_1410ce3f0(Unk_CubeOwnerPtr spOwner);
    bool FUN_1410b7e80(efd::Point3 kPos);
    bool FUN_1410b7da0(efd::Point3 kPos);
    void FUN_1410c1910(const Unk_Int3& kPos, bool bFlag);
    unsigned int FUN_1410c3470();
    unsigned int FUN_1410c34b0();
    void FUN_1410d4450(__int64 nCharId, int nSlot, CString strName, __int64 nTime);
    void FUN_1410d4710(__int64 nCharId, int nSlot, CString strName, __int64 nTime);
    void FUN_1410d54f0(int n);
    void FUN_1410d5700(__int64 n);
    void FUN_1410d5750(__int64 n);
    void FUN_1410d57a0(__int64 n);
    void FUN_1410d5830(__int64 n);
    void FUN_1410d5ae0(int n);
    int FUN_1410d5b00();
    Cube* FUN_1410b8b00(int nCubeId);                      // the placed cube with this id
    static const efd::ClassID CLASS_ID = 0x06100017;
    void FUN_1410c3020(int n);
    void FUN_1410bc1c0();                                   // UI hidden (debug key)
    void FUN_1410bc320();                                   // UI shown again
    void FUN_1410c3120(int n);
    void FUN_1410c3160(int n);
    void FUN_1410cb8b0(bool b);
    void FUN_1410c31a0(__int64 nOwner);
    void FUN_1410c3220(const CStringW& str);
    void FUN_1410c32b0(const CStringW& str);
    void FUN_1410c3310(int n);
    void FUN_1410c3410(int n);
    void FUN_1410c3450(int n);
    void FUN_1410c3630(int n);
    void FUN_1410c3490(int n);
    void FUN_1410c34d0(int n);
    void FUN_1410c3530(Unk_SSGHouseRule rule);
    void FUN_1410c3670();
    void FUN_1410d43c0(ATL::CAtlArray<MS2Ptr<UGCMapDesignInfo> >& arr);
    void FUN_1410d4680(ATL::CAtlArray<MS2Ptr<UGCMapBlueprintInfo> >& arr);
    void FUN_1410c3e40(int nKey, bool bValue);
    void FUN_1410c3f10(int nKey, int nValue);
    void FUN_1410caa60(const CString& strName, int nState);
};
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework* framework);
class Unk_SSG6aeee0 { public: bool FUN_1406af0c0(); };
Unk_SSG6aeee0* FUN_1406aeee0();

// 0x1a / 0x1b: character / channel move results
struct Unk_StreamPoint;
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
CStringW FUN_140cc20a0(int nError);
CStringW FUN_14028de60(int nId);
void FUN_1412751f0(const CStringW& strMsg, int a, int b);
void FUN_140930ba0(int n);
extern int DAT_143ab2870;
extern int DAT_143ab2878;
extern int DAT_143ab287c;
extern int DAT_143ab2880;
extern int DAT_143ab2890;
class Unk_SSG967100 { public: void FUN_141b21390(); void FUN_141b1ddd0(CInPacket& packet); };
Unk_SSG967100* FUN_140967100();
class Unk_SSG9331e0 { public: void FUN_14138d7e0(int a, int nMapId); void FUN_14138bf00(int nKind, int nId, int nArg); void FUN_14138b280(CInPacket& packet); };
Unk_SSG9331e0* FUN_1409331e0();
class Unk_SSGSoundCtl { public: void FUN_1422ba0d0(); void FUN_1422b9fd0(int nId); UISwfEntity* FUN_1422b9e20(int nId); UISwfEntity* FUN_1422b9e80(); };
Unk_SSGSoundCtl* FUN_1408e57f0();
class Unk_SSG931510 { public: void FUN_140d9f310(__int64 nValue); void FUN_140d9f710(CInPacket& packet); MS2Ptr<class Unk_SSGDungeonRecord> FUN_140d9f2c0(); MS2Ptr<class Unk_SSGChatEmoticon> FUN_140d9f8f0(); };
void FUN_1412b9870(int nId, int nType);

// 0x18..0x41: actor packets
class Unk_SSG9f7c90 { public: int FUN_1409f7ea0(); };
Unk_SSG9f7c90* FUN_1409f7c90();
void FUN_141663500(MyPC* pPC, int nMapId);                 // PC member (0x141663500), called on the local MyPC
// The npc / monster class (class id 0x06200011).
class Unk_SSGNpcData : public CPtred { public: bool FUN_1406ccf40(); bool FUN_1406cd200(int nFlag); char m_pad[0x60 - sizeof(CPtred)]; int m_n60; char m_pad_64[0x8c - 0x64]; bool m_b8c; };   // the npc table row
MS2_CHECK_OFFSET(Unk_SSGNpcData, m_n60, 0x60);
// The drop item (class id 0x06200011; its members live in client\ms2\dropitem.cpp 0x14118c730-0x141192960). w95: split
// from Unk_SSGNpc, whose +0x150/+0x1a0 do not fit PCBase.
// The DoT damage record (?\skillrecord.cpp; new(0xe0)); only the members the DoT handler uses.
class CDotDamageRecord : public CPtred
{
public:
    CDotDamageRecord();                                     // 0x14175af90
    virtual ~CDotDamageRecord();                            // 0x14175b590
    int FUN_14175aff0(int nSkillId, int nOwnerId, int nTargetId, int nFlag, __int64 nDamage);
private:
    char m_pad_18[0xe0 - 0x18];
};
MS2_CHECK_SIZE(CDotDamageRecord, 0xe0);
// The splash damage record (?\skillrecord.cpp; new(0xd8)); only the members the splash handler uses.
class CSplashDamageRecord : public CPtred
{
public:
    CSplashDamageRecord();                                  // 0x14175b180
    virtual ~CSplashDamageRecord();                         // 0x14175b5f0
    int FUN_14175b1c0(int nOwnerId, int n, __int64 nSkillUid, int nSkillId, short nLevel, int a, int b, Unk_StreamPoint kDir, Unk_StreamPoint kPos);
    void FUN_14175abc0(int nFlag, __int64 nDamage);
    char m_pad_18[0x78 - 0x18];
    Unk_StreamPoint m_kPos;                                 // +0x78 the hit position
    char m_pad_84[0xd8 - 0x84];
};
MS2_CHECK_OFFSET(CSplashDamageRecord, m_kPos, 0x78);
MS2_CHECK_SIZE(CSplashDamageRecord, 0xd8);
template <> MS2Ptr<CSplashDamageRecord>::MS2Ptr(CSplashDamageRecord* p);   // out-of-unit COMDAT (0x141099d10)
// The skill level row of a damage record (FUN_140803f60); only the fields the hit handler reads.
class Unk_PCBaseSkillLevel
{
public:
    char m_pad_00[0x10c];
    int m_n10c;                                             // +0x10c the attack kind (2, 3, 4: no model drop)
    int m_n110;                                             // +0x110
};
MS2_CHECK_OFFSET(Unk_PCBaseSkillLevel, m_n110, 0x110);
class Unk_SSGSkillAim;                                      // the record's aim info (FUN_14175a850)
// The skill hit record (?\skillrecord.cpp, ctor 0x14175a4e0, new(0xd8)); only the members the hit handler uses.
class CDamageRecord : public CPtred
{
public:
    CDamageRecord();
    int FUN_14175a610(__int64 nCasterUid, __int64 nCastUid, int nOwnerId, int nCasterId, int nSkillId, short nLevel,
                      int nMotion, int nAttack, Unk_StreamPoint kPos, Unk_StreamPoint kAim, Unk_StreamPoint kDir);
    void FUN_14175abc0(int nFlag, __int64 nDamage);
    int FUN_14175acc0();                                    // nonzero: the skill tracks its target
    Unk_SSGSkillAim* FUN_14175a850();
    Unk_PCBaseSkillLevel* FUN_14175a8b0();
    char m_pad_18[0x6c - 0x18];
    Unk_StreamPoint m_kDir;                                 // +0x6c
    Unk_StreamPoint m_kPos;                                 // +0x78
    char m_pad_84[0xd0 - 0x84];
    int m_nd0;                                              // +0xd0
    char m_pad_d4[0xd8 - 0xd4];
};
MS2_CHECK_OFFSET(CDamageRecord, m_kDir, 0x6c);
MS2_CHECK_OFFSET(CDamageRecord, m_nd0, 0xd0);
MS2_CHECK_SIZE(CDamageRecord, 0xd8);
struct Unk_MagicXform { Unk_MagicXform(); char m_pad[0x34]; };   // NiTransform (0x140a332d0)
// Builds the hit transform from a position and a direction (?\magicdata.cpp).
void FUN_141467f60(Unk_StreamPoint kPos, Unk_StreamPoint kDir, Unk_MagicXform* pOut);
// Moves the hit position / direction onto the target (?\magicdata.cpp).
int FUN_14145e1a0(int nFrom, int nTo, Unk_SSGSkillAim* pAim, const Unk_PCBaseSkillLevel* pLevel, Unk_StreamPoint* pPos,
                  Unk_StreamPoint* pDir);
class Unk_SSGMagicService
{
public:
    void FUN_14146bc20(CDotDamageRecord* pRecord);
    void FUN_14146bc80(CSplashDamageRecord* pRecord);
    void FUN_14146b440(CDamageRecord* pRecord, int bTracked, Unk_MagicXform* pXform, Unk_StreamPoint kDir);
    void FUN_14146c4b0(unsigned long long nCaster, unsigned long long nCast);   // drop the cast's model
    Unk_SocketPtr<CMagicModel> FUN_14146c5d0(unsigned long long nCaster, unsigned long long nCast);   // find one
};
Unk_SSGMagicService* FUN_1410a7630();

class Unk_SSGDropItem : public GameObject
{
public:
    static const efd::ClassID CLASS_ID = 0x06200011;
    int FUN_1411900d0();
    int FUN_14118fea0();                                    // +0x150 > 0
    int FUN_14118ff10();                                   // the item (+0x1a0) is 0x55d4a8a
    void FUN_141190b70(int nOwnerId);
    void FUN_141192840(int n);                              // +0x294 = n
    void FUN_14174a5a0(__int64 n) { m_n150 = n; }

    unsigned char m_pad_140[0x150 - 0x140];
    __int64 m_n150;                                         // +0x150
    unsigned char m_pad_158[0x294 - 0x158];
    int m_n294;                                             // +0x294
};
MS2_CHECK_OFFSET(Unk_SSGDropItem, m_n150, 0x150);
MS2_CHECK_OFFSET(Unk_SSGDropItem, m_n294, 0x294);
class Unk_SSGNpc : public PCBase
{
public:
    int vfunc_116() override;                               // 116 (CNpc)
    virtual int vfunc_124(int nNpcId);                      // 124 (0x3e0): set up from the npc table
    virtual void vfunc_125(int n);                          // 125 (called with 1 on packet 0x57)
    MS2Ptr<Unk_SSGNpcData> FUN_141093270();                 // the npc table row
    void FUN_1410932c0(int n);
    void FUN_1410918e0(CByteBuffer& buf);                   // apply a sync block
    void FUN_14174a560(char c) { m_ce50 = c; }
    void FUN_141092c50(CInPacket& packet);
    void FUN_141094df0(__int64 nExp);                       // pet/npc exp gain
    void FUN_141094f20(int n);
    void FUN_141094790(__int64 n);
    void FUN_14174a580(unsigned short n) { m_ne58 = n; }
    void FUN_14174a4f0(int n) { m_nea8 = n; }
    void FUN_141095190(const CString& strName);
    void FUN_141094f90(CString strModel);
    void FUN_1410951d0(const CString& strScript);           // 0xe8 mode 2
    void FUN_141095290(int n);
    void FUN_141095240(__int64 n);
    void FUN_1410952b0(bool b);
    int FUN_141092ff0();                                    // nonzero: the npc carries a custom model block

    char m_pad_d40[0xe50 - 0xd40];
    char m_ce50;                                            // +0xe50
    char m_pad_e51[0xe58 - 0xe51];
    int m_ne58;                                             // +0xe58
    char m_pad_e5c[0xea8 - 0xe5c];
    int m_nea8;                                             // +0xea8
};
MS2_CHECK_OFFSET(Unk_SSGNpc, m_ce50, 0xe50);
MS2_CHECK_OFFSET(Unk_SSGNpc, m_ne58, 0xe58);
MS2_CHECK_OFFSET(Unk_SSGNpc, m_nea8, 0xea8);
class Unk_PCItemCooldowns { public: void FUN_140c86510(__int64 nItemUid); void FUN_140c86450(MS2Ptr<CItem> spItem); void FUN_140c860b0(CInputStream& stream, int nObjId); };
// The item event hub (FUN_140a6a840); slots 5/21/23 are item notifications.
class Unk_SSGItemHub
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1(CItem* pItem);
    virtual void vfunc_2(CItem* pItem, bool bRemoved);     // 0x21 modes 1/3
    virtual void vfunc_3(CItem* pItem, int nDelta);         // count changed
    virtual void vfunc_4(CItem* pItem, int n);              // 0x21 mode 7
    virtual void vfunc_5(CItem* pItem);
    virtual void vfunc_6(CItem* pItem);
    virtual void vfunc_7(CItem* pItem);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(CItem* pItem);                    // cube inventory item added
    virtual void vfunc_14(CItem* pItem);                    // cube inventory item removed
    virtual void vfunc_15(CItem* pItem);                    // cube inventory count changed
    virtual void vfunc_16(CItem* pItem, int nValue);        // cube inventory item used
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20(CItem* pItem);                    // an item was equipped
    virtual void vfunc_21(CItem* pItem);
    virtual void vfunc_22(CItem* pItem);
    virtual void vfunc_23(CItem* pItem);
    virtual void vfunc_24(CItem* pItem);
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29(CItem* pItem);                    // gem socketed
    virtual void vfunc_30(CItem* pItem);                    // gem taken out
};
Unk_SSGItemHub* FUN_140a6a840();
MyPC* FUN_1409613d0(PCBase* pPC);                          // efd::DynamicCast<MyPC> (class id 0x6200004)
int FUN_1422b9e00(Unk_SSGSoundCtl* p);
class UISceneEntity : public UISwfEntity { };
class UISceneGameBeautyShop : public UISceneEntity { public: void FUN_141ac9270(); };
UISceneEntity* FUN_1422b9e50(Unk_SSGSoundCtl* p);          // the current scene entity

MyPC* FUN_14096e160(PCBase* pActor);                        // efd::DynamicCast<MyPC> (class id 0x06200004)
// 0x1417127b0: an actor's state request list (Unk_StateArg22 in statemanager.h).
MS2Ptr<Unk_StateArg22> FUN_140835450(int nType);
class Unk_SSGHitReport { public: void FUN_140cfaf30(); };
class Unk_SSGStBody { public: void FUN_141240730(); Unk_SSGHitReport* FUN_141240f20(); };
Unk_SSGStBody* FUN_14166d220(PCBase* pActor);

// 0x3f..0x5a: npc / actor state packets
// The skill request a skill record is built from (0x48; avatarpc.cpp's view, points as Unk_StreamPoint).
struct Unk_InventorySkillRequest
{
    Unk_InventorySkillRequest(int nSkillId, unsigned short nLevel);   // 0x141763fa0
    int skill;
    unsigned short level;
    unsigned __int64 tick;                                  // +0x08 the cast uid
    unsigned serial, unknown14;                             // +0x10 / +0x14
    Unk_StreamPoint origin;                                 // +0x18
    Unk_StreamPoint direction;                              // +0x24
    float fValue;                                           // +0x30
    unsigned unknown34;
    bool remap, suppressDispatch, itemUse;
    __int64 item;
};
MS2_CHECK_SIZE(Unk_InventorySkillRequest, 0x48);
class Unk_PCBaseComp_b18 : public CPtred   // the casting skill (CSkillRecord, 0x1c0)
{
public:
    Unk_PCBaseComp_b18();                                   // 0x141759260
    bool FUN_1417595d0(Unk_InventorySkillRequest& kReq);    // build the record of a request
    char m_pad[0x28 - sizeof(CPtred)];
    __int64 m_nSkillUid;                                    // +0x28
    char m_pad_30[0x68 - 0x30];
    Unk_StreamPoint m_kRot;                                 // +0x68 the cast rotation
    float m_fSpeed;                                         // +0x74 the caster's speed scale
    char m_pad_78[0x8c - 0x78];
    unsigned int m_nMotion;                                 // +0x8c the motion index of the cast
    char m_pad_90[0x94 - 0x90];
    unsigned int m_n94;                                     // +0x94 (packet 0x75)
    char m_pad_98[0xa0 - 0x98];
    int m_nA0;                                              // +0xa0 nonzero: the cast is finished (no new projectiles)
    char m_pad_a4[0xb0 - 0xa4];
    int m_nExtra;                                           // +0xb0 option 0xae: the extra id of the cast
    CString m_strExtra;                                     // +0xb8 option 0xae: its name
    char m_pad_c0[0x108 - 0xc0];
    ATL::CAtlList<Unk_SocketPtr<CMagicModel> > m_listModels;   // +0x108 the projectiles started by this cast
    char m_pad_tail[0x1c0 - 0x108 - sizeof(ATL::CAtlList<Unk_SocketPtr<CMagicModel> >)];
};
MS2_CHECK_SIZE(Unk_PCBaseComp_b18, 0x1c0);
MS2_CHECK_OFFSET(Unk_PCBaseComp_b18, m_fSpeed, 0x74);
MS2_CHECK_OFFSET(Unk_PCBaseComp_b18, m_strExtra, 0xb8);
MS2_CHECK_OFFSET(Unk_PCBaseComp_b18, m_nSkillUid, 0x28);
MS2_CHECK_OFFSET(Unk_PCBaseComp_b18, m_nA0, 0xa0);
MS2_CHECK_OFFSET(Unk_PCBaseComp_b18, m_listModels, 0x108);
class NotifyRemoveNpc : public NotifyObject
{
public:
    NotifyRemoveNpc(efd::SmartPointer<Unk_SSGNpc> spNpc);   // 0x140db4930
    efd::SmartPointer<Unk_SSGNpc> m_spNpc;                  // +0x18
};
MS2_CHECK_SIZE(NotifyRemoveNpc, 0x20);
class Unk_SSGNotifyCenter { public: void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify); };
Unk_SSGNotifyCenter* FUN_140939a10();
// 0x141733850: the pvp kill notification (ctor/dtor are emitted in this unit; vfunc_1 lives in the notify unit).
class NotifyKillPlayer : public NotifyObject
{
public:
    NotifyKillPlayer(const CStringW& strKiller, const CStringW& strVictim) : m_strKiller(strKiller), m_strVictim(strVictim) {}
    virtual ~NotifyKillPlayer() = default;
    virtual CStringW vfunc_1();                             // 0x140db5220
    CStringW m_strKiller;                                   // +0x18
    CStringW m_strVictim;                                   // +0x20
};
MS2_CHECK_SIZE(NotifyKillPlayer, 0x28);
class UIPvPKillLogDialog : public UIDialog { public: void FUN_141342880(CStringW strKiller, CStringW strVictim); };
extern CString DAT_143ae7a10;                               // the kill sound event name
// 0x14171bd90: the token money change notification (ctor/dtor are emitted in this unit; vfunc_1 lives in the notify unit).
class NotifyChangedTokenMoney : public NotifyObject
{
public:
    NotifyChangedTokenMoney(int nType, __int64 nValue, __int64 nDelta) : m_nType(nType), m_nValue(nValue), m_nDelta(nDelta) {}
    virtual ~NotifyChangedTokenMoney() = default;
    virtual CStringW vfunc_1();                             // 0x140db4610
    int m_nType;                                            // +0x18
    __int64 m_nValue;                                       // +0x20
    __int64 m_nDelta;                                       // +0x28
};
MS2_CHECK_SIZE(NotifyChangedTokenMoney, 0x30);
void FUN_141361460(int nType, __int64 nDelta, int nX);
int FUN_1403bb010(int nType, int nColor);
class Unk_SSGStrTable { public: CStringW FUN_141811980(int nTable, int nIndex); CStringW FUN_141812290(int nId, unsigned short nRank, CString strField); };
Unk_SSGStrTable* FUN_1401a9d70();
void FUN_141275460(int nStringId, int nA, int nB, const fmt::ArgList& args);
// 0x141740df0: fmt message with two arguments (a template over the argument types in the original).
template <class A, class B> void Unk_SSGFormatMsg(int nStringId, int nA, int nB, const A& a, const B& b)
{
    const fmt::internal::ArgArray<2>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a), fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
    FUN_141275460(nStringId, nA, nB, fmt::ArgList(fmt::internal::make_type(a, b), values));
}

// 0x4d..0xf2: forwarders to the feature managers
class Unk_SSGad4b90 { public: void FUN_141861840(CInPacket& packet); void FUN_141861f60(CInPacket& packet); void FUN_141863630(int nId, bool bHas, CString strName); };
Unk_SSGad4b90* FUN_140ad4b90();
class Unk_SSG9670b0 { public: void FUN_14122f270(CInPacket& packet); void FUN_141232260(); };
Unk_SSG9670b0* FUN_1409670b0();
class Unk_SSG97a780                                         // the buddy manager
{
public:
    void FUN_140ae2e90(CInPacket& packet);
    unsigned FUN_140ae51b0(__int64 nCharId);                // blocked by character id
    unsigned FUN_140ae5240(const CStringW& strName);        // blocked by name
};
Unk_SSG97a780* FUN_14097a780();
class Unk_SSGa6a830 { public: void FUN_140a2f730(CInPacket& packet); };
Unk_SSGa6a830* FUN_140a6a830();
class Unk_SSG9c4b20 { public: void FUN_1405322b0(CInPacket& packet); };
Unk_SSG9c4b20* FUN_1409c4b20();
class Unk_SSG535310 { public: void FUN_140612850(CInPacket& packet); };
Unk_SSG535310* FUN_140535310();
class Unk_SSG09a700 { public: void FUN_14127e250(CInPacket& packet); };
Unk_SSG09a700* FUN_14109a700();
class Unk_SSG9eed60 { public: void FUN_14127e550(CInPacket& packet); };
Unk_SSG9eed60* FUN_1409eed60();
class Unk_SSG953f20 { public: void FUN_140cd9840(CInPacket& packet); };
Unk_SSG953f20* FUN_140953f20();
class Unk_SSGc8dac0 { public: void FUN_140d061b0(CInPacket& packet); };
Unk_SSGc8dac0* FUN_140c8dac0();
class Unk_SSGDlg4e4c { public: void FUN_1419f5e90(CInPacket& packet); };
Unk_SSGDlg4e4c* FUN_140e01890(int nId);                     // GetDialog<T>(0x4e4c)
class Unk_SSGDlg4e52 { public: void FUN_141908290(CInPacket& packet); };
Unk_SSGDlg4e52* FUN_14136f290(int nId);                     // GetDialog<T>(0x4e52)
void FUN_140930fe0(CInPacket& packet);

// 0x1a..0xe7: feature manager / dialog handlers
class CPet : public Unk_SSGNpc
{
public:
    CPet();                                                 // 0x140b0f4c0, size 0x10b0
    virtual void vfunc_126();
    virtual int vfunc_127();                                // 127 (0x3f8): plays the removal sound
    void FUN_140b107f0(int n);
    void FUN_140b10a10(__int64 n);
    void FUN_140b10210(int n);
    void FUN_140b10f90(unsigned short n);
    GameObject* FUN_140b10320();                            // the owner (the sound plays at it)
    void FUN_140b10c80(CStringW strName);

    char m_pad_eb0[0x10b0 - 0xeb0];
};
MS2_CHECK_SIZE(CPet, 0x10b0);
extern int DAT_143ab2900;
extern int DAT_143ab2918;
class Unk_SSGDlg4e28 : public UIDialog { public: void FUN_141938ae0(int nId, int n); void FUN_141939620(); void FUN_140ea5f80(); void FUN_141938190(); void FUN_1419391c0();
    void FUN_141937e00(int nMode); void FUN_141937e40(int nMode); };   // UIGameMenuDialog
Unk_SSGDlg4e28* FUN_140938b90(int nId);                     // GetDialog<T>(0x4e28)
class Unk_MyPCSkillSlots { public: void FUN_141769250(); void FUN_141768e70(int nId, unsigned short nLevel, __int64 nStart, __int64 nEnd, bool bA, bool bB, int bNew);
    void FUN_141767f80(int nSkillId); void FUN_141768100(int nSkillId); void FUN_1417683d0(); void FUN_141765de0(); void FUN_141767ae0(CInPacket& packet);
    void FUN_141765f60(__int64 nUid); void FUN_141766900(__int64 nUid, int nSlot); void FUN_141768530(int nSkillId, int nValue);
    unsigned int FUN_141768680(class Unk_SSGSkillRow* pRow); void FUN_141765e70(int nSkillId);
    void FUN_1417669c0(int nSlot, int nSkillId, float fCool); };
class Unk_MyPCStatPoints : public CPtred { public: void FUN_140ca9e90(CInPacket& packet); };
class Unk_SSGConstValue { public: int* FUN_1402056b0(); int FUN_140ad5c50(); };
class Unk_SSGConstValue2 { public: int* FUN_1401d7c10(); };
class Unk_BSConstInt { public: int FUN_140ec2b60(); };   // a constant row (uibeautyshopstyledialog.cpp's name)
class Unk_SSGConstStr { public: CString& FUN_140298f80(); };   // a string constant row (commonutil.cpp's Unk_StringOptionEntry)
class Unk_SSGConstants
{
public:
    char m_pad_00[0x2970];
    Unk_SSGConstValue m_2970;                               // +0x2970
    char m_pad_2971[0x3578 - 0x2971];
    Unk_SSGConstValue m_3578;                               // +0x3578
    char m_pad_3579[0x3680 - 0x3579];
    Unk_SSGConstValue m_3680;                               // +0x3680
    char m_pad_3681[0x66d0 - 0x3681];
    Unk_SSGConstValue2 m_66d0;                              // +0x66d0
    char m_pad_66d1[0x67e0 - 0x66d1];
    Unk_SSGConstValue2 m_67e0;                              // +0x67e0
    char m_pad_67e1[0x7f48 - 0x67e1];
    Unk_SSGConstStr m_7f48;                                 // +0x7f48 the effect of a remote cast with the effect flag
    char m_pad_7f49[0x9190 - 0x7f49];
    Unk_BSConstInt m_9190;                                  // +0x9190 adventure level-up chat notice id
    char m_pad_9191[0x9718 - 0x9191];
    unsigned short m_n9718;                                 // +0x9718 skill point level cap (the larger of the two)
    unsigned short m_n971a;                                 // +0x971a
};
MS2_CHECK_OFFSET(Unk_SSGConstants, m_67e0, 0x67e0);
MS2_CHECK_OFFSET(Unk_SSGConstants, m_n971a, 0x971a);
MS2_CHECK_OFFSET(Unk_SSGConstants, m_2970, 0x2970);
MS2_CHECK_OFFSET(Unk_SSGConstants, m_3680, 0x3680);
MS2_CHECK_OFFSET(Unk_SSGConstants, m_66d0, 0x66d0);
Unk_SSGConstants* FUN_1401d3200();
class UIAutoReviveCountDownDialog : public UIDialog { public: void FUN_141284d70(int n); };
class UIGlobalPortalDialog : public UIDialog { public: void FUN_1412c3020(CInPacket& packet); };
class UIQuizDialog : public UIDialog { public: void FUN_14129a930(CInPacket& packet); };
class UIIndividualPvPDialog : public UIDialog { public: void FUN_1412cacc0(); void FUN_1412cb220(); void FUN_1412cb240(); };
void FUN_141276180(const CString& strA, const CString& strB);   // play a sound event
class Unk_SSGDungeonRecord : public CPtred { public: void FUN_140b20be0(CInPacket& packet); };
class Unk_SSGGlobalFactor { public: void FUN_1404c18c0(CInPacket& packet); };
Unk_SSGGlobalFactor* FUN_140302b10();
class Unk_SSGPreload { public: void FUN_14074ee30(); };
Unk_SSGPreload* FUN_1407476c0();

// 0xef..0x138
extern int DAT_143ab2950;
extern char DAT_143ab2943;
class Unk_SSGChatEmoticon : public CPtred { public: void FUN_140a3a700(CInPacket& packet); };   // CChatEmoticonCli
void FUN_140e146f0(CInPacket& packet);
class Unk_SSGHomeBlocks { public: void FUN_140a46b90(CInPacket& packet); };                     // HomeBlockManager
Unk_SSGHomeBlocks* FUN_1414a5830();

class Unk_SSGStatusListener { public: void FUN_141b0ce20(int a, int b); void FUN_141b0e050(); void FUN_141b0e1d0(int nSkillId); };
Unk_SSGStatusListener* FUN_140aa6d40();
void FUN_140930150(int n);
class Unk_PCCubeCraft { public: void FUN_1410aa5c0(CubeItemInfo* pInfo); void FUN_1410aa550(int n); void FUN_1410aa380(bool b); void FUN_1410aa590(); };

void FUN_1403d7440(CInputStream& stream, CAtlArray<unsigned int>& arr);   // read a u32 array
class Unk_SSGMsgBoxFlags { public: void FUN_1417e25a0(int nClassId); };
Unk_SSGMsgBoxFlags* FUN_140aa6d30();
void FUN_140d73bc0(int nType, int a, void* p, CStringW strTag);
extern CStringW DAT_143ae79f0;
bool FUN_14028d780(unsigned char n);
class Unk_SSGDlg4e47 { public: void FUN_141b10ba0(int n); };
Unk_SSGDlg4e47* FUN_140de48d0(int nId);                     // GetDialog<T>(0x4e47)
class Unk_SSGDlg4ed8 { public: void FUN_1412c5330(int n); void FUN_1412c54e0(int n); void FUN_1412c5f00(); void FUN_1412c6070();
    void FUN_1412c5c30(); void FUN_1412c6220(); void FUN_1412c66c0(); void FUN_1412c6b50(); };
Unk_SSGDlg4ed8* FUN_140bbea00(int nId);                     // GetDialog<T>(0x4ed8)

class Unk_SSGDlg4e29
{
public:
    void FUN_141a3b130(__int64 nUid, int nType, const Unk_NiPoint3& kPos);
    void FUN_141a3a780(int nId);
    void FUN_141a39770(MS2Ptr<CInteractObject> spObj);     // an interact object was added
    void FUN_141a39bf0(MS2Ptr<CInteractObject> spObj);     // one was removed
    void FUN_141a3a890();                                   // first use of a gathering object
};
Unk_SSGDlg4e29* FUN_140c9b540(int nId);                     // GetDialog<T>(0x4e29)

class Unk_SSGCommandLog
{
public:
    int FUN_1401859c0(int nType, int nValue, const wchar_t* pszText);
    void FUN_14015eb90(int nCat, int nLevel, const wchar_t* pszFormat, const CString& strArg);
    void FUN_1406530d0(int nCat, int nLevel, const wchar_t* pszFormat, const fmt::ArgList& args);
    // fmt log line with two arguments (0x141740800 = <unsigned, Unk_SSGSkillUseError>).
    template <class A, class B> void Log(int nCat, int nLevel, const wchar_t* pszFormat, const A& a, const B& b)
    {
        const fmt::internal::ArgArray<2>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a), fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
        FUN_1406530d0(nCat, nLevel, pszFormat, fmt::ArgList(fmt::internal::make_type(a, b), values));
    }
};
Unk_SSGCommandLog* FUN_140166440();
class Unk_SSGChatDialog { public: void FUN_141ac0ac0(int nId); void FUN_141ac0210(MyPC* pPlayer); void FUN_141ac14b0(); void FUN_141ac1d10(int n); void FUN_141abf6e0(int nId, int nValue); void FUN_141ac1580(const CStringW& strImage, const CStringW& strText, int n); void FUN_141ac0990(__int64 nAmount); void FUN_141ac0860(__int64 nAmount); };
Unk_SSGChatDialog* FUN_140938cd0(int nId);                  // GetDialog<UIChatDialog>
class Unk_SSGMessengerBrowser { public: void FUN_141a265d0(); void FUN_141a26560(unsigned int nId); void FUN_141a26600(); };
Unk_SSGMessengerBrowser* FUN_140a3ab70(int nId);            // GetDialog<UIMessengerBrowser>
class UIUnlimitedEnchantDialog : public UIDialog
{
public:
    void FUN_140fb6310(CInPacket& packet);
    void FUN_140fb6b00(CInPacket& packet);
    void FUN_140fb6c30(int n);
};

class Unk_SSGBattleRecord { public: void FUN_140a05550(__int64 nKey, __int64 nDelta); void FUN_140a05490(__int64 nKey, __int64 nExp); };
Unk_SSGBattleRecord* FUN_140e09140();                       // TSingleton<CBattleRecordManager>
class Unk_SSG9a6f0 { public: void FUN_14117e4c0(__int64 nDelta); void FUN_14117d090(int nSide, int n, __int64 nA, __int64 nB, __int64 nC, int nD); void FUN_14117e690(); int FUN_14117c8b0(); void FUN_14117e7c0(__int64 nValue); void FUN_14117e720(__int64 nValue); };
Unk_SSG9a6f0* FUN_14109a6f0();
void FUN_1413612c0(__int64 nDelta, int n);
class Unk_SSGQuestMgr { public: void FUN_1416ca2f0(); };
Unk_SSGQuestMgr* FUN_140764020();
class Unk_SSGGrabState : public State { public: int FUN_141024a30(int nId); };
class Unk_SSGDlg2711
{
public:
    void FUN_141a5a560();
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77(); virtual void vfunc_78(); virtual void vfunc_79(); virtual void vfunc_80(); virtual void vfunc_81(); virtual void vfunc_82(); virtual void vfunc_83(); virtual void vfunc_84(); virtual void vfunc_85(); virtual void vfunc_86(); virtual void vfunc_87(); virtual void vfunc_88(); virtual void vfunc_89(); virtual void vfunc_90(); virtual void vfunc_91(); virtual void vfunc_92(); virtual void vfunc_93(); virtual void vfunc_94(); virtual void vfunc_95(); virtual void vfunc_96(); virtual void vfunc_97(); virtual void vfunc_98();
    virtual void vfunc_99(const CStringW& strName);
};
Unk_SSGDlg2711* FUN_140938c30(int nId);
void FUN_141a60f00(int nObjectId);
class Unk_SSGcea070 { public: void FUN_140dd86a0(int nA, int nB); };
Unk_SSGcea070* FUN_140cea070();
void FUN_141275260(int nStringId, int nA, int nB);

class Unk_SSGEffectCfg { public: char m_pad_00[0xd0]; CString m_strd0; char m_pad_d8[0x2c8 - 0xd8]; CString m_str2c8; CString m_str2d0; CString m_str2d8; char m_pad_2e0[0x328 - 0x2e0]; CString m_str328; char m_pad_330[0x358 - 0x330]; CString m_str358; CString m_str360; char m_pad_368[0x380 - 0x368]; CString m_str380; char m_pad_388[0x5b0 - 0x388]; CString m_str5b0; };
MS2_CHECK_OFFSET(Unk_SSGEffectCfg, m_str2d8, 0x2d8);
int FUN_141658e60(PCBase* pPC);                             // the partner gem id of an actor
class Unk_SSGDlg4e3c { public: void FUN_141910b10(__int64 nDelta); };
Unk_SSGDlg4e3c* FUN_140ac55a0(int nId);
MS2_CHECK_OFFSET(Unk_SSGEffectCfg, m_str358, 0x358);
Unk_SSGEffectCfg* FUN_1401d31f0();
PC* FUN_140974230(PCBase* pActor);                          // DynamicCast<PC> (class id 0x6200003)
class Unk_SSGa94350
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
    virtual void vfunc_14(int nJob);                        // the player's job changed
};
Unk_SSGa94350* FUN_140a94350();

class Unk_SSGSkillAttr : public CPtred { };
class Unk_SSGSkillRow : public CPtred { public: int FUN_1407e9b90(); };   // SkillDataTableCli row (base skill id or 0)
class Unk_SSGSkillTable { public: MS2Ptr<Unk_SSGSkillAttr> FUN_140aafef0(int nSkillId, unsigned short nLevel);
    MS2Ptr<Unk_SSGSkillRow> FUN_1407ee1d0(int nSkillId); };
Unk_SSGSkillTable* FUN_1401958b0();                         // SkillDataTableCli
class Unk_SSGSkillCollision
{
public:
    void FUN_141755cd0(PCBase* pActor, MS2Ptr<Unk_SSGSkillAttr> spSkill, const Unk_StreamPoint& kPos, const Unk_StreamPoint& kDir);
};
Unk_SSGSkillCollision* FUN_141469a90();                     // CSkillCollisionManager
class Unk_SSGMyPCV : public PC
{
public:
    virtual void vfunc_147(); virtual void vfunc_148(); virtual void vfunc_149();
};

extern Unk_StreamPoint DAT_143b01a60;                      // efd::Point3::ZERO
int FUN_1417692f0(__int64 nUid);                            // skill id from the low half of an item uid
void FUN_1419f37f0(unsigned int n);

CInputStream& FUN_14070f300(CInputStream& stream, bool& b);   // stream >> bool
extern CString DAT_143ae79e8;
class Unk_SSGTaxiStation { public: void FUN_1409f1970(); };
Unk_SSGTaxiStation* FUN_1412787a0();                        // TSingleton<CAutoFindTaxiStation>
CStringW FUN_14028b8e0(const CStringW& strKey);              // localized text for a string key
class Unk_SSGDlgShop { public: void FUN_141afb720(int nType); };
Unk_SSGDlgShop* FUN_140534780(int nId);                     // Unk_BreakDialog<UIShopDialog>

class Unk_SSGNotifyInventory : public NotifyObject
{
public:
    Unk_SSGNotifyInventory();                               // 0x141328cf0 (vftable 0x142eebd58)
};
MS2_CHECK_SIZE(Unk_SSGNotifyInventory, 0x18);
class Unk_SSGDlgInv : public UIDialog { public: void FUN_141999f60(); void FUN_141999e00(); int FUN_141999de0(); void FUN_141999e50(); };
Unk_SSGDlgInv* FUN_1405344f0(int nId);                      // Unk_BreakDialog<UIInventoryDialog>
CStringW FUN_140d2e2b0(int nA, int nB, __int64 nC);
CStringW FUN_140632a60(int nId, const CStringW& strArg0, const CStringW& strArg1);
class UIEnchantScrollDialog : public UIDialog
{
public:
    void FUN_140f3b920(CInPacket& packet);
    void FUN_140f3bd10(CInPacket& packet);
    void FUN_140f3c6c0(CInPacket& packet);
};
UIEnchantScrollDialog* FUN_140cd7aa0(int nId);              // GetDialog<UIEnchantScrollDialog>
UIMasteryDialog* FUN_140faf160(int nId);                    // GetDialog<UIMasteryDialog>
class UIDarkStreamScoreDialog : public UIDialog
{
public:
    virtual void vfunc_84(int nScore);
    void FUN_140f35660(int nOffset);
    void FUN_140f356a0(int nAlign);
};
UIDarkStreamScoreDialog* FUN_140f9d8a0(int nId);            // GetDialog<UIDarkStreamScoreDialog>
class UIDarkStreamResultDialog : public UIDialog { public: void FUN_140f34cb0(bool bShow); void FUN_140f34ab0(CInPacket& packet); };
// 0x141734e00: the arcade mini game packet fans out to these dialogs and the local player's hud entity.
class Unk_PCBaseComp_a78 : public CPtred                    // UIHudEntity::Entity
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();                                 // hide
    void FUN_140f48dc0(int bVisible);
};
extern template class MS2Ptr<Unk_PCBaseComp_a78>;           // instances live outside the unit (0x1405a89b0...)
class UIMainPlayerInfo : public UIDialog { public: void FUN_1419f1d10(unsigned int nMask, bool bShow); void FUN_1419f2720(bool bArcade); };
UIMainPlayerInfo* FUN_140931900(int nId);                   // GetDialog<UIMainPlayerInfo>
class UIHpBar : public UIDialog { };
void FUN_1419929f0(int nActorId);                           // refresh the hp bar of an actor
class UIArcadeMainDialog : public UIDialog { public: void FUN_140ef7d30(int nMode, CInPacket& packet); };
class UIArcadeLifeBar : public UIDialog { public: void FUN_140ef51e0(int nMode, CInPacket& packet); void FUN_140ef53f0(int nX, int nY);
    void FUN_140ef5370(int nA, int nB, int nC); void FUN_140ef5320(int nA, int nB); };
class UIMicroGameCoupleDance : public UIDialog { public: void FUN_140e647c0(int nMode, CInPacket& packet); };
UIMicroGameCoupleDance* FUN_140b8b5c0(int nId);             // GetDialog<UIMicroGameCoupleDance>
class UIArcadeTextEffectDialog : public UIDialog { public: void FUN_140ba7fe0(int nMode, CInPacket& packet); };

MS2Ptr<CItemData> FUN_14053f870(int nItemId);
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);  // str == psz
class UIItemMultiOpenBoxDialog { public: void FUN_140c3fa80(int nA, int nB); };
UIItemMultiOpenBoxDialog* FUN_140d27580(int nId);           // GetDialog<UIItemMultiOpenBoxDialog>
class UIVIPDialog : public UIDialog { public: void FUN_140fb87d0(CInPacket& packet, int nMode); };

class StateFishingData : public StateData
{
public:
    StateFishingData(int nRod);                             // 0x140dda2c0
    int m_nRod;
    char m_pad[0x20 - sizeof(StateData) - sizeof(int)];
};
MS2_CHECK_SIZE(StateFishingData, 0x20);

class Unk_SSGInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid);
    int FUN_140a621c0(__int64 nItemUid, int a, int b);      // remove an item (packet 0x20 mode 2)
    void FUN_140a62920(__int64 nItemUid);                   // packet 0x20 mode 3
    int FUN_140a5d120(CItem* pItem);                        // add an item
    void FUN_140a66990(unsigned short nLevel);              // packet 0x2f: level changed
    void FUN_140a66c00();                                   // OnAddUser: the local player entered
    // 0x21 (item inventory updates)
    void FUN_140a5ca60(int nTab);                           // mode 0xb
    void FUN_140a5cb80(int nTab, int nCount);               // mode 0xc: tab size
    MS2Ptr<CItem> FUN_140a60280(int nTab, int nSlot);       // the item in a tab slot
    void FUN_140a5d390(__int64 nItemUid);                   // remove an item
    void FUN_140a66ae0(MS2Ptr<CItem> spItem);
    // 0x25 (equip): the item the auto-install prompt was raised for
    int FUN_140a67000();
    __int64 FUN_140a66f20();
    void FUN_140a66f40(__int64 nItemUid);
};
extern Unk_SSGInventory DAT_143ab2a90;                      // the local player's inventory

class Unk_SSGCommunityPopup { public: void FUN_140bea390(CStringW strName, CString strText); };
Unk_SSGCommunityPopup* FUN_14136f1f0(int nId);              // GetDialog<UICommunityPopup>
CString FUN_14016a5c0(const char* psz, int n);
struct Unk_SSGBeautyReq                                     // FUN_1407a8340 reads it
{
    Unk_SSGBeautyReq() : m_nType(0), m_nUid(0) { }
    int m_nType;
    __int64 m_nUid;
};
MS2_CHECK_OFFSET(Unk_SSGBeautyReq, m_nUid, 8);
void FUN_1407a8340(Unk_SSGBeautyReq& req, CInputStream& stream);
class UIBeautyShopDialog : public UIDialog { };
class Unk_SSGUIMsg : public UIMsg                           // an ActionScript call (ASData)
{
public:
    Unk_SSGUIMsg();                                         // 0x1422e4490
    ~Unk_SSGUIMsg();                                        // 0x140c30570
    void FUN_1422b82b0(const char* pszMethod);
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};

class StateObserverData : public StateData
{
public:
    StateObserverData(__int64 nTargetUid);                  // 0x140ac3b40
    __int64 m_nTargetUid;
};
MS2_CHECK_SIZE(StateObserverData, 0x20);

class Unk_SSG5b5dd0                                         // packet 0x11b mode 1 entry
{
public:
    Unk_SSG5b5dd0();                                        // 0x140a6ffe0
    void FUN_1405b5dd0(CInPacket& packet);                  // reads m_nA, m_nB
    int m_nA;
    __int64 m_n8;
    int m_nB;
};
MS2_CHECK_SIZE(Unk_SSG5b5dd0, 0x18);
MS2_CHECK_OFFSET(Unk_SSG5b5dd0, m_nB, 0x10);

class Unk_SSG5b5e70                                         // packet 0x11b mode 2 entry
{
public:
    Unk_SSG5b5e70();                                        // 0x140c5e480
    void FUN_1405b5e70(CInPacket& packet);                  // reads m_nA
    int m_nA;
};
MS2_CHECK_SIZE(Unk_SSG5b5e70, 4);

bool FUN_1418fd6c0(__int64 nUid);

// ---- statics (exe .di order) -----------------------------------------------------------------------------------
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateGame);

static CStringW s_confirmChangeCharName(L"confirmChangeCharName");
static CStringW s_individualArenaJoin(L"individualArenaJoin");
static CStringW s_maintenanceExit(L"maintenanceExit");
static CStringW s_recallconfirm(L"recallconfirm");
static CStringW s_startbypass(L"startbypass");
static CStringW s_useBindEquipItem(L"useBindEquipItem");
static CString s_sort8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_sort7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill = "skill";
static CString s_stun = "stun";
static Unk_Handle1401cd100 s_handle(0);                     // @0x1400ffb90
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_jobCode = "jobCode";
static CString s_sortValue = "sortValue";
static CString s_tabIndex = "tabIndex";
static CString s_noticeBattleHp10 = "notice_battle_hp_10percent";
static CString s_sound02100201 = "02100201";
static CString s_sound02100200 = "02100200";
static CString s_sound02100199 = "02100199";
static CString s_pcBuyHouse = "PC_buy_house";
static CString s_systemFieldWar = "System_FieldWar";
static CString s_telescopeFind = "Telescope_Find";
static CString s_guildBattleApply = "guildBattle_Apply";
static CString s_noticeWarningBag = "system_notice_error_warningBag";
static CString s_noticeWarningDanger = "system_notice_warningDanger";
static CString s_noticeWarningNoBuild = "system_notice_error_warningNoBuild";
static CString s_systemKillSlayer = "System_KillSlayer";
static CString s_summonCash = "Summon_Cash";
static CString s_systemTaxiFind = "system_Taxi_Find";
static CString s_ugcBuyland = "ugc_buyland";
static CString s_ugcRemoveblock = "ugc_removeblock";
static CString s_ugcRotateblock = "ugc_rotateblock";
static CString s_ugcSellland = "ugc_sellland";
static CString s_ugcSetblock = "ugc_setblock";

// ---- callees of the w95 handlers (names inferred) -----------------------------------------------------------------
int FUN_140222f60(int nType);
class Unk_PCWaterGunInfo : public CPtred { public: void FUN_1408fdfe0(CInPacket& packet); };
// The trophy/achievement counters (std::map<int, map<unsigned short, int>> and a map<unsigned short, int> total;
// only the clear/operator[] instances this unit calls are named).
class Unk_SSGCountMap
{
public:
    void FUN_140642910();                                   // clear
    int& FUN_14063ec70(const int& nKey);                    // operator[]
};
class Unk_SSGCountMapMap
{
public:
    void FUN_1409353d0();                                   // clear
    Unk_SSGCountMap& FUN_140ed3b20(const int& nKey);        // operator[]
};
extern int DAT_143ab2954;
extern Unk_SSGCountMapMap DAT_143ab32e8;
extern Unk_SSGCountMap DAT_143ab32f8;
// MyPC +0x179c (MyPC's members are unrecovered; this view only carries the inline setter at 0x14174a510).
class Unk_SSGMyPCScore
{
public:
    void FUN_14174a510(int n) { m_n179c = n; }
private:
    char m_pad_0[0x179c];
    int m_n179c;
};
CFieldMetaTable* FUN_140700390();                          // the field meta table singleton
CStringW FormatStringId(int id, const fmt::ArgList& args);  // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)
CStringW FUN_14052bd00(int nId, const CStringW& strArg);   // formatted system text
CStringW FUN_1409404f0(__int64 nAmount);                    // money string
CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);   // formatted system text (util.cpp)
CStringW FUN_1409eec40(int nId);                                // 0/1/2 -> same, else 6
// The EP gauge of the HUD (?\uiepprogress.cpp).
class Unk_SSGEPGauge { public: void FUN_141931bd0(int nValue, int nMax); };
// MyPC's vftable as far as slot 88: MyPC overrides slot 88 to return its EP gauge (PCBase declares it as int).
class Unk_SSGMyPCSlots
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47();
    virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55();
    virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63();
    virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71();
    virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77(); virtual void vfunc_78(); virtual void vfunc_79();
    virtual void vfunc_80(); virtual void vfunc_81(); virtual void vfunc_82(); virtual void vfunc_83(); virtual void vfunc_84(); virtual void vfunc_85(); virtual void vfunc_86(); virtual void vfunc_87();

    virtual Unk_SSGEPGauge* vfunc_88();
};
NiColor FUN_141b6dea0(unsigned uColor);                     // 0xAARRGGBB -> NiColor
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);            // an entity's scene root
void FUN_141b6f220(NiAVObject* pRoot, int nSlot, const NiColor& kColor);   // tint the skin/hair materials

// @0x14170bda0
CSceneStateGame::CSceneStateGame()
{
    m_f20 = 0;
    m_nOpcode = 0;
    m_nTaxiEffect = 0;
    m_b18 = true;
}

// @0x14170be40
CSceneStateGame::~CSceneStateGame()
{
}

// @0x14170be90
int CSceneStateGame::vfunc_15()
{
    return 1;
}
MS2_REPLACE_METHOD(0x14170be90, CSceneStateGame, vfunc_15, 11, 0x30025ED0);

// @0x14170beb0
// MS2-FUNCTIONAL: the exe keeps the 24-byte FUN_140987930 result slot pointer in a stack temp before the call (same as CSceneStateMove/Multi::OnEnter)
void CSceneStateGame::OnEnter(int nPrevState)
{
    CSceneStateBase::OnEnter(nPrevState);
    FUN_1403ed2d0()->FUN_141bbae40(this);
    m_f20 = FUN_141473280(FUN_14086d260());
    FUN_141489ff0(FUN_140aae430(), static_cast<const Unk_143a09680&>(FUN_140987930(DAT_143a09680)));
    FUN_140d8ee90()->FUN_140a1f7f0(true);
    FUN_140db8eb0(FUN_140c7a250());
    m_bReconnecting = false;
    m_nRetry = 0;
    m_reconnectTimer.FUN_1408687f0();
    FUN_1403ed2b0()->FUN_141add040(0x4e32);
    FUN_140d9f040(FUN_140931510());
}
MS2_REPLACE_METHOD(0x14170beb0, CSceneStateGame, OnEnter, 270, 0x562E95A4);

// @0x14170bfd0
void CSceneStateGame::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
    FUN_140aad0d0(FUN_140e800e0());
    FUN_140d9f0c0(FUN_140931510());
    FUN_140ceac00(FUN_14015a050());
    FUN_140ad68a0(FUN_1409eed70());
    FUN_14052d220()->FUN_1418894d0();
    FUN_1403ed2d0()->FUN_141bbae80(this);
    FUN_1403ed2b0()->FUN_141adc050();
    FUN_1403ed2d0()->FUN_141bbc580(0, 0);
    FUN_14162b790(FUN_1409670d0());
    FUN_140d8ee90()->FUN_140a1f7f0(false);
    FUN_1409a4090(FUN_1409a8b00());
}
MS2_REPLACE_METHOD(0x14170bfd0, CSceneStateGame, OnLeave, 220, 0x6782486F);

// @0x14170c0c0
void CSceneStateGame::OnUpdate(double fTime)
{
    CSceneStateBase::OnUpdate(fTime);
    if (m_bReconnecting)
    {
        if (m_nRetry < 5)
        {
            if (m_reconnectTimer.FUN_140868c00() != 0)
            {
                if (FUN_140714f90()->FUN_1415384e0() == 0)
                {
                    FUN_140714f90()->FUN_1415383a0(DAT_143ab2a48, DAT_143ab2848, 1, 1, 0);
                    m_nRetry = m_nRetry + 1;
                    CStringW text = FUN_14062b4f0(CStringW(L"s_reconnect_to_server"), m_nRetry);
                    void* loading = FUN_141540270(0x3ed);
                    if (loading)
                        FUN_1419e0050(loading, text);
                }
                m_reconnectTimer.FUN_140868750(10000);
            }
        }
        else if (m_nRetry == 5 && m_reconnectTimer.FUN_140868c00() != 0)
        {
            m_reconnectTimer.FUN_1408687f0();
            m_nRetry = 6;
            if (DAT_143b03490)
                DAT_143b03490(1, DAT_1430c3b20, efd::LogHelper(FUN_14016a600(FUN_1408116a0(0x20f, 7), 0)));
            FUN_140d86260()->vfunc_58(0x20f, 7);
            {
                CStringW title(L"MS2");
                FUN_141b6fcf0(FUN_1408116a0(0x20f, 7), title, 0);
            }
            TerminateProcess(GetCurrentProcess(), 2);
        }
    }
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
    {
        Ridee* pRidee = pPC->FUN_1416764a0();
        if (pRidee != 0)
            pRidee->FUN_141706650(false);
        else
            FUN_141524a80(pPC, 0);
        for (unsigned __int64 i = 0; i < 3; i++)
        {
            Unk_SSGSubActor* pSub = FUN_141662440(pPC, (int)i);
            if (pSub != 0)
                pSub->vfunc_126();
        }
    }
    FUN_140d8ee90()->FUN_140a1f8a0();
    FUN_140953f30()->FUN_140ad1ef0();
    if (FUN_140e800e0() != 0)
        FUN_140aadd70(FUN_140e800e0());
    FUN_14173fe20();
}
MS2_REPLACE_METHOD(0x14170c0c0, CSceneStateGame, OnUpdate, 1244, 0x2C40A545);

// @0x14170c5b0
void CSceneStateGame::OnPacket(CInPacket& packet)
{
    CSceneStateBase::OnPacket(packet);
    m_nOpcode = packet.FUN_14070fe80();
    switch (m_nOpcode)
    {
    case 0x9:
        FUN_14170dc90(packet);
        break;
    case 0x15:
        OnServerEnter(packet);
        break;
    case 0x7d:
        OnLoadUgcMap(packet);
        break;
    case 0x16:
        FUN_14170f930(packet);
        break;
    case 0x19:
        FUN_14170fc70(packet);
        break;
    case 0x17:
        OnAddUser(packet);
        break;
    case 0x18:
        FUN_141711dc0(packet);
        break;
    case 0x1c:
        OnUserSync(packet);
        break;
    case 0x7a:
        OnRideSync(packet);
        break;
    case 0x1f:
        FUN_141712a90(packet);
        break;
    case 0x20:
        OnItemPutOnOrOff(packet);
        break;
    case 0xce:
        FUN_1417132b0(packet);
        break;
    case 0x21:
        OnItemInventory(packet);
        break;
    case 0x22:
        DAT_143ab2d80.FUN_140de3480(packet);
        break;
    case 0x23:
        FUN_141715bd0(packet);
        break;
    case 0x24:
        OnFurnishingInventory(packet);
        break;
    case 0x25:
        OnItemPutOn(packet);
        break;
    case 0x26:
        OnItemPutOff(packet);
        break;
    case 0x27:
        FUN_141716d10(packet);
        break;
    case 0x28:
        OnItemSkinPutOff(packet);
        break;
    case 0x29:
        FUN_141717560(packet);
        break;
    case 0x2a:
        OnItemUpdate(packet);
        break;
    case 0x30:
        OnUserSkinColor(packet);
        break;
    case 0x2b:
        OnFieldAddItem(packet);
        break;
    case 0x2c:
        FUN_141712340(packet);
        break;
    case 0x2d:
        OnFieldPickupItem(packet);
        break;
    case 0x3c:
        OnSkillUse(packet);
        break;
    case 0x40:
        OnSkillUseFailed(packet);
        break;
    case 0x41:
        FUN_141718b80(packet);
        break;
    case 0x2e:
        OnStat(packet);
        break;
    case 0x2f:
        OnUserBattle(packet);
        break;
    case 0x34:
        OnRevival(packet);
        break;
    case 0x33:
        OnRevivalConfirm(packet);
        break;
    case 0x35:
        FUN_14171aa90(packet);
        break;
    case 0x38:
        OnLevelUp(packet);
        break;
    case 0xae:
        OnMyInfo(packet);
        break;
    case 0x37:
        FUN_14171ab00(packet);
        break;
    case 0x39:
        OnMeso(packet);
        break;
    case 0x3a:
        OnMeret(packet);
        break;
    case 0x117:
        FUN_14171bad0(packet);
        break;
    case 0x3b:
        OnCurrencyToken(packet);
        break;
    case 0x32:
        FUN_14171a6c0(packet);
        break;
    case 0x4b:
        FUN_141719a30(packet);
        break;
    case 0x48:
        OnFieldPortal(packet);
        break;
    case 0x49:
        OnJob(packet);
        break;
    case 0x3d:
        OnSkillDamage(packet);
        break;
    case 0x47:
        OnBuff(packet);
        break;
    case 0x130:
        FUN_141720c60(packet);
        break;
    case 0x4c:
        OnRegionSkill(packet);
        break;
    case 0x4e:
        FUN_141721270(packet);
        break;
    case 0x4d:
        FUN_1417212a0(packet);
        break;
    case 0x55:
        OnFieldAddNpc(packet);
        break;
    case 0x56:
        FUN_1417195f0(packet);
        break;
    case 0x57:
        FUN_1417197c0(packet);
        break;
    case 0x5a:
        OnFieldAddPet(packet);
        break;
    case 0x5b:
        FUN_14171a2e0(packet);
        break;
    case 0x58:
        FUN_141719840(packet);
        break;
    case 0x5c:
        OnSyncPetTamingPoint(packet);
        break;
    case 0x59:
        OnInteractNpc(packet);
        break;
    case 0x4f:
        FUN_1417212d0(packet);
        break;
    case 0x50:
        if (FUN_140ee0d10() != 0)
            FUN_140ee0d10()->FUN_140b8c260(packet);
        break;
    case 0x5d:
        OnTombstone(packet);
        break;
    case 0x36:
        OnUserState(packet);
        break;
    case 0xfa:
        FUN_14173b080(packet);
        break;
    case 0x3e:
        FUN_141718150(packet);
        break;
    case 0x3f:
        OnSkillCancel(packet);
        break;
    case 0x5f:
        OnUserMoveByPortal(packet);
        break;
    case 0x54:
        FUN_141721cd0(packet);
        break;
    case 0x60:
        OnMassiveEvent(packet);
        break;
    case 0x61:
        FUN_141721c50(packet);
        break;
    case 0x62:
        FUN_141721c90(packet);
        break;
    case 0x64:
        FUN_141722fb0(packet);
        break;
    case 0x65:
        OnStateFallDamage(packet);
        break;
    case 0x66:
        OnCinematic(packet);
        break;
    case 0x68:
        OnSetCraftMode(packet);
        break;
    case 0x69:
        OnResponseCube(packet);
        break;
    case 0x6a:
        OnLoadCubes(packet);
        break;
    case 0x67:
        FUN_1417232a0(packet);
        break;
    case 0x70:
        FUN_141723330(packet);
        break;
    case 0x71:
        FUN_141728c20(packet);
        break;
    case 0x73:
        OnLiftable(packet);
        break;
    case 0x74:
        OnItemFusion(packet);
        break;
    case 0x75:
        FUN_14172a1c0(packet);
        break;
    case 0x76:
        FUN_14172a7b0(packet);
        break;
    case 0x77:
        FUN_14172a850(packet);
        break;
    case 0x79:
        OnResponseRide(packet);
        break;
    case 0x7b:
        FUN_14172b350(packet);
        break;
    case 0x6e:
        FUN_14172c170(packet);
        break;
    case 0x63:
        OnInteractObject(packet);
        break;
    case 0x42:
        FUN_14172f030(packet);
        break;
    case 0x43:
        FUN_14172f1c0(packet);
        break;
    case 0x44:
        FUN_14172f210(packet);
        break;
    case 0x45:
        FUN_14172f480(packet);
        break;
    case 0x7e:
        FUN_14172f500(packet);
        break;
    case 0x7f:
        FUN_141730920(packet);
        break;
    case 0x80:
        FUN_141731470(packet);
        break;
    case 0x81:
        FUN_141731610(packet);
        break;
    case 0x83:
        FUN_1417316d0(packet);
        break;
    case 0x86:
        FUN_141731730(packet);
        break;
    case 0x89:
        FUN_141731160(packet);
        break;
    case 0x94:
        FUN_141731190(packet);
        break;
    case 0x95:
        FUN_141731350(packet);
        break;
    case 0x96:
        FUN_141731ac0(packet);
        break;
    case 0xdb:
        FUN_141731af0(packet);
        break;
    case 0xc:
        FUN_141731b20(packet);
        break;
    case 0x8c:
        FUN_141731c10(packet);
        break;
    case 0xb6:
        OnPvp(packet);
        break;
    case 0x9d:
        FUN_141732ac0(packet);
        break;
    case 0x9e:
        FUN_141732af0(packet);
        break;
    case 0x97:
        OnItemEnchant(packet);
        break;
    case 0x9b:
        OnWebOpen(packet);
        break;
    case 0x9f:
        FUN_141733440(packet);
        break;
    case 0xa1:
        OnSystemShop(packet);
        break;
    case 0xa2:
        OnAutoRevive(packet);
        break;
    case 0xa3:
        OnPlayerKillNotice(packet);
        break;
    case 0xa6:
        FUN_141736880(packet);
        break;
    case 0xa8:
        FUN_141736940(packet);
        break;
    case 0x1a:
        FUN_141737360(packet);
        break;
    case 0xaa:
        FUN_1417373d0(packet);
        break;
    case 0xab:
        FUN_141739910(packet);
        break;
    case 0xac:
        FUN_141739e40(packet);
        break;
    case 0xb0:
        FUN_141733b30(packet);
        break;
    case 0xb1:
        OnNametag(packet);
        break;
    case 0xb2:
        FUN_140ceab50(FUN_14015a050(), packet);
        break;
    case 0x137:
        FUN_140ad5f00(FUN_1409eed70(), packet);
        break;
    case 0xb5:
        OnSetPcbang(packet);
        break;
    case 0xb7:
        FUN_1417340f0(packet);
        break;
    case 0xb9:
        FUN_1417343c0(packet);
        break;
    case 0xba:
        OnItemDropNotice(packet);
        break;
    case 0xbc:
        OnRecallScroll(packet);
        break;
    case 0xbd:
        {
            Unk_SSGDialog4edc* pDlg = FUN_140ce84f0(0x4edc);
            if (pDlg != 0)
                pDlg->FUN_1412a53e0(packet);
        }
        break;
    case 0xbe:
        FUN_141734930(packet);
        break;
    case 0xbf:
        OnEnchantScroll(packet);
        break;
    case 0xc1:
        OnGlobalPortal(packet);
        break;
    case 0xc2:
        OnQuizEvent(packet);
        break;
    case 0xc3:
        FUN_141734bc0(packet);
        break;
    case 0xc4:
        FUN_141734c70(packet);
        break;
    case 0xc5:
        OnDarkStream(packet);
        break;
    case 0xd8:
        OnPlayArcade(packet);
        break;
    case 0xc7:
        FUN_1417353b0(packet);
        break;
    case 0xca:
        FUN_1417353e0(packet);
        break;
    case 0xcb:
        FUN_141735410(packet);
        break;
    case 0xcd:
        OnMastery(packet);
        break;
    case 0xd1:
        FUN_141737d60(packet);
        break;
    case 0xcf:
        {
            UINoticeDialog* pDlg = Unk_SSGGetDialog<UINoticeDialog>(0x4ee9);
            if (pDlg != 0)
                pDlg->FUN_141009680(packet);
        }
        break;
    case 0xd3:
        FUN_141737db0(packet);
        break;
    case 0xd6:
        FUN_1417380c0(packet);
        break;
    case 0xd7:
        FUN_141738120(packet);
        break;
    case 0xdc:
        FUN_141738290(packet);
        break;
    case 0xdd:
        FUN_141738380(packet);
        break;
    case 0xe8:
        FUN_141738430(packet);
        break;
    case 0xe7:
        FUN_141738ad0(packet);
        break;
    case 0xea:
        FUN_141738b40(packet);
        break;
    case 0xeb:
        OnPremiumClub(packet);
        break;
    case 0xec:
        FUN_14173a0d0(packet);
        break;
    case 0x101:
        FUN_14173a0f0(packet);
        break;
    case 0xe9:
        OnLocalCamera(packet);
        break;
    case 0xf1:
        OnOneTimeEffect(packet);
        break;
    case 0xf2:
        FUN_14173a5b0(packet);
        break;
    case 0xf3:
        OnTimeScale(packet);
        break;
    case 0xf4:
        FUN_14173a720(packet);
        break;
    case 0xf8:
        OnHomeInvite(packet);
        break;
    case 0xf7:
        OnEventReward(packet);
        break;
    case 0xf9:
        FUN_141736240(packet);
        break;
    case 0xfb:
        FUN_14173b1d0(packet);
        break;
    case 0xfd:
        FUN_14173b220(packet);
        break;
    case 0xfe:
        FUN_14173b380(packet);
        break;
    case 0x103:
        FUN_14173b420(packet);
        break;
    case 0x105:
        FUN_14173b5a0(packet);
        break;
    case 0x106:
        FUN_14173c090(packet);
        break;
    case 0x113:
        FUN_1403ed2d0()->FUN_141bd9c20(packet);
        break;
    case 0x111:
        FUN_14173c7a0(packet);
        break;
    case 0x115:
        OnReactor(packet);
        break;
    case 0x118:
        FUN_14173ce30(packet);
        break;
    case 0x11a:
        FUN_14173d180(packet);
        break;
    case 0x11b:
        OnLapenshard(packet);
        break;
    case 0x11c:
        OnPrestige(packet);
        break;
        break;  // the exe keeps a dead jmp here (a removed case's leftover break)
    case 0x120:
        FUN_14173ddf0(packet);
        break;
    case 0x121:
        FUN_14173de10(packet);
        break;
    case 0x91:
        FUN_14173def0(packet);
        break;
    case 0x11f:
        FUN_14173dfd0(packet);
        break;
    case 0x126:
        FUN_14173e440(packet);
        break;
    case 0xef:
        FUN_14173e4b0(packet);
        break;
    case 0xf5:
        FUN_14173e510(packet);
        break;
    case 0x128:
        FUN_1409eed90()->FUN_141b83750(packet);
        break;
    case 0x12b:
        OnHideAndSeek(packet);
        break;
    case 0x12c:
        FUN_14173f0c0(packet);
        break;
    case 0x12e:
        OnLimitBreak(packet);
        break;
    case 0x12f:
        FUN_14173f280(packet);
        break;
    case 0xde:
        OnItemSocketSystem(packet);
        break;
    case 0x131:
        FUN_14173f7c0(packet);
        break;
    case 0x135:
        FUN_14173f810(packet);
        break;
    case 0x136:
        FUN_14173f860(packet);
        break;
    case 0x138:
        FUN_14173fc00(packet);
        break;
    case 0x139:
        FUN_14173fc40(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14170c5b0, CSceneStateGame, OnPacket, 4075, 0x85D9EB98);

// @0x14170d9f0
void CSceneStateGame::vfunc_1(int nParam)
{
    {
        COutPacket out(0xf, 0);
        out.COutPacket::vfunc_o10_3(FUN_1403ed2d0()->FUN_141bd98d0());
        FUN_140710590(out);
    }
    FUN_14052d220()->FUN_141889150();
    {
        COutPacket out(0x38, 0);
        out.COutPacket::vfunc_o10_1(0x12);
        out.COutPacket::vfunc_o10_3(nParam);
        FUN_140710590(out);
    }
    FUN_141739450(false);
    if (DAT_143ab285c != 0 && DAT_143ab2860 == 3)
    {
        DAT_143ab285c = 0;
        DAT_143ab284b = 0;
    }
}

// @0x14170daf0
void CSceneStateGame::vfunc_4(int)
{
    FUN_141739880();
    if (DAT_1439f4a78 == 1)
    {
        m_bReconnecting = true;
        m_nRetry = 0;
        m_reconnectTimer.FUN_140868750(10000);
        FUN_140714f90()->FUN_1415383a0(DAT_143ab2a48, DAT_143ab2848, 1, 1, 0);
    }
}

// @0x14170dbc0
int CSceneStateGame::vfunc_14()
{
    return 1;
}
MS2_REPLACE_METHOD(0x14170dbc0, CSceneStateGame, vfunc_14, 11, 0x30025ED0);

// @0x14170dbe0
void CSceneStateGame::OnWndMessage(unsigned int nMsg, int wParam, int lParam)
{
    if (nMsg == 0x203)
    {
        if (FUN_14025e7a0()->FUN_1422aeed0(2) != 0)
            return;
        if (FUN_1409478c0()->FUN_140a18070() != 0)
            FUN_1409478c0()->FUN_140aeb1a0();
    }
    else if (nMsg == 0x200)
    {
        if (FUN_14025e7a0()->FUN_1422aeed0(2) != 0)
            return;
    }
    FUN_140953f30()->FUN_140ad1da0(nMsg, wParam, lParam);
}
MS2_REPLACE_METHOD(0x14170dbe0, CSceneStateGame, OnWndMessage, 155, 0x19D25A81);

// @0x14170dc90
void CSceneStateGame::FUN_14170dc90(CInPacket& packet)
{
    Unk_SSGEnterRequest req;
    req.m_nAccountId = DAT_143ab2820;
    req.m_n8 = DAT_143ab284c;
    req.m_nC = DAT_143ab2850;
    req.m_machineId.FUN_14067c080(FUN_140aadf70()->FUN_140d4fdf0());
    COutPacket out(4, 0);
    req.FUN_1401f9d20(out);
    FUN_140710590(out);
}
MS2_REPLACE_METHOD(0x14170dc90, CSceneStateGame, FUN_14170dc90, 191, 0x74DA6D2C);

// @0x14170dd60
void CSceneStateGame::OnServerEnter(CInPacket& packet)
{
    FUN_14092f420();
    DAT_143ab2864 = static_cast<CInputStream&>(packet).vfunc_o8_3();
    DAT_143ab2828 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nChannel = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    if (nChannel == 0 && DAT_1439f4a7c != 0)
        DAT_1439f4a80 = DAT_1439f4a7c < 1 ? 1 : DAT_1439f4a7c;
    if (nChannel != 0 && FUN_14092f640() != 0 && FUN_14092f640() != nChannel)
    {
        CStringW strMsg = FUN_1408116a0(0x2d7, nChannel);
        FUN_1412751b0(strMsg, 0x14);
    }
    if (nChannel != 0)
        FUN_140714f90()->FUN_141539130();
    __int64 a = 0, b = 0, c = 0, d = 0, e = 0;
    DAT_1439f4a7c = nChannel;
    DAT_143ab28a0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28a8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab2898 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    a = static_cast<CInputStream&>(packet).vfunc_o8_4();
    b = static_cast<CInputStream&>(packet).vfunc_o8_4();
    c = static_cast<CInputStream&>(packet).vfunc_o8_4();
    d = static_cast<CInputStream&>(packet).vfunc_o8_4();
    e = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28b0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28b8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28c0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28c8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28d0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28d8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28e0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28e8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28f0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CString strUnk = static_cast<CInputStream&>(packet).vfunc_o8_6();
    int nChatFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
    FUN_1409304d0(a, b, c, d);
    FUN_140930af0(e);
    if (FUN_140f97ef0() != 0)
        FUN_140f97ef0()->FUN_140f97f00()->FUN_140dbde50(nChatFlag);
    DAT_143ab3058.FUN_1402c2830();
    int nCount = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    for (int i = 0; i < nCount; i++)
    {
        int n = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab3058.FUN_1401855a0(n);
    }
    DAT_143ab3098.FUN_1402c2830();
    DAT_143ab3078.FUN_1402c2830();
    nCount = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    for (int j = 0; j < nCount; j++)
    {
        int n = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab3078.FUN_1401855a0(n);
    }
    __int64 nGuildId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW strGuildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    FUN_1403ed290()->FUN_1413bc1f0(nGuildId, strGuildName);
    FUN_1403ed290()->FUN_1413bcd10();
    CString str1 = static_cast<CInputStream&>(packet).vfunc_o8_6();
    CString str2 = static_cast<CInputStream&>(packet).vfunc_o8_6();
    CString str3 = static_cast<CInputStream&>(packet).vfunc_o8_6();
    if (FUN_140cc18a0() != 0)
    {
        FUN_140cc18a0()->FUN_141b77e50(str1);
        FUN_140cc18a0()->FUN_141b77e90(str2);
        FUN_140cc18a0()->FUN_141b77ed0(str3);
    }
    Unk_SSGChannelDialog* pDlg = FUN_14136f520(0x4ef0);
    if (pDlg != 0)
        pDlg->FUN_141ad2ea0(nChannel);
    FUN_1403ed2b0()->FUN_141ad93b0();
    FUN_1401c0d90()->FUN_1404766e0();
    FUN_1403ed2a0()->FUN_1407ce240();
    if (DAT_143ab2918 == 0)
    {
        COutPacket out(0x82, 0);
        FUN_140710590(out);
    }
    FUN_140714f90()->FUN_141539260();
    if (FUN_1414a56d0() != 0)
    {
        COutPacket out(0xe, 0);
        out.COutPacket::vfunc_o10_4(FUN_1414a56d0()->FUN_14034a1b0());
        FUN_140710590(out);
    }
    if (FUN_140166410()->FUN_14036e5b0())
    {
        if (FUN_140b05bf0() != 0)
            FUN_140b05bf0()->FUN_140b06450(1);
    }
    CString strValue("x64");
    CString strKey("client_arch");
    FUN_140d8ee90()->FUN_140a1f970(strKey, strValue);
}
MS2_REPLACE_METHOD(0x14170dd60, CSceneStateGame, OnServerEnter, 2707, 0x78081C2A);

// The option kind keying the house option tables (as cubemapinformationservice_tail.h / ugcmapoptions.h).
enum Unk_CMISKindB { Unk_CMISKindB_None };

// @0x14170e800
// MS2-FUNCTIONAL: code bytes match; the two option tables are the CubeMapInformationService efd::map<Unk_CMISKindB, ...>
// family (ctor/dtor wrappers 0x141122880/0x141122830, 0x141125870/0x141125830, operator[] 0x141128310/0x141128290), whose
// glue symbols.tsv still names after the Unk_CMISTree<280>/<281> stand-ins (fx24)
void CSceneStateGame::OnLoadUgcMap(CInPacket& packet)
{
    if (FUN_1403ed2d0()->FUN_141bcfd10() != 4)
        return;
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nMapId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int bHasInfo = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (FUN_1406aeee0()->FUN_1406af0c0())
        nMode = 0;
    CStringW strName = L"";
    CStringW strDesc = L"";
    int nC = 0;
    __int64 nOwner = 0;
    int nA = 0;
    int nB = 0;
    int nD = 0;
    int nE = 0;
    int nF = 0;
    int nG = 10;
    int nH = 5;
    Unk_SSGHouseRule rule;
    efd::map<Unk_CMISKindB, unsigned char> mapFlags;
    efd::map<Unk_CMISKindB, int> mapValues;
    ATL::CAtlArray<MS2Ptr<UGCMapDesignInfo> > arrDesign;
    ATL::CAtlArray<MS2Ptr<UGCMapBlueprintInfo> > arrBlueprint;
    if (bHasInfo != 0)
    {
        nOwner = static_cast<CInputStream&>(packet).vfunc_o8_4();
        strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        strDesc = static_cast<CInputStream&>(packet).vfunc_o8_8();
        nC = static_cast<CInputStream&>(packet).vfunc_o8_1();
        nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        nD = static_cast<CInputStream&>(packet).vfunc_o8_3();
        nE = static_cast<CInputStream&>(packet).vfunc_o8_3();
        nF = static_cast<CInputStream&>(packet).vfunc_o8_1();
        nG = static_cast<CInputStream&>(packet).vfunc_o8_1();
        nH = static_cast<CInputStream&>(packet).vfunc_o8_1();
        rule.FUN_140b68ec0(packet);
        unsigned __int64 nFlags = static_cast<CInputStream&>(packet).vfunc_o8_1();
        for (unsigned __int64 i = 0; i < nFlags; i++)
        {
            int nKey = (int)i;
            bool bSet = static_cast<CInputStream&>(packet).vfunc_o8_1() == 1 ? true : false;
            mapFlags[(Unk_CMISKindB)nKey] = bSet;
            if (bSet)
            {
                int nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
                mapValues[(Unk_CMISKindB)nKey] = nValue;
            }
        }
        if (nOwner == DAT_143ab2820)
        {
            unsigned __int64 nDesigns = static_cast<CInputStream&>(packet).vfunc_o8_1();
            for (unsigned __int64 j = 0; j < nDesigns; j++)
            {
                MS2Ptr<UGCMapDesignInfo> pInfo(new UGCMapDesignInfo());
                pInfo->m_nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                pInfo->m_strName = static_cast<CInputStream&>(packet).vfunc_o8_6();
                pInfo->m_nTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
                arrDesign.Add(pInfo);
            }
            unsigned __int64 nBlueprints = static_cast<CInputStream&>(packet).vfunc_o8_1();
            for (unsigned __int64 k = 0; k < nBlueprints; k++)
            {
                MS2Ptr<UGCMapBlueprintInfo> pInfo(new UGCMapBlueprintInfo());
                pInfo->m_nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                pInfo->m_strName = static_cast<CInputStream&>(packet).vfunc_o8_6();
                pInfo->m_nTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
                arrBlueprint.Add(pInfo);
            }
        }
        rule.FUN_140b68f60();
    }
    if (nMode == 0)
    {
        efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService)
        {
            spService->FUN_1410c3020(nMapId);
            spService->FUN_1410c3160(nE);
            spService->FUN_1410c3120(nD);
            spService->FUN_1410cb8b0(true);
            spService->FUN_1410c31a0(nOwner);
            spService->FUN_1410c3220(strName);
            spService->FUN_1410c32b0(strDesc);
            spService->FUN_1410c3310(nC);
            spService->FUN_1410c3410(nA);
            spService->FUN_1410c3450(nB);
            spService->FUN_1410c3630(nF);
            spService->FUN_1410c3490(nG);
            spService->FUN_1410c34d0(nH);
            spService->FUN_1410c3530(rule);
            if (bHasInfo != 0)
            {
                spService->FUN_1410c3670();
                if (nOwner == DAT_143ab2820)
                {
                    spService->FUN_1410d43c0(arrDesign);
                    spService->FUN_1410d4680(arrBlueprint);
                }
            }
            for (efd::map<Unk_CMISKindB, unsigned char>::iterator it = mapFlags.begin(); it != mapFlags.end(); ++it)
            {
                int nKey = it->first;
                bool bValue = it->second;
                spService->FUN_1410c3e40(nKey, bValue);
            }
            for (efd::map<Unk_CMISKindB, int>::iterator it = mapValues.begin(); it != mapValues.end(); ++it)
            {
                int nKey = it->first;
                int nValue = it->second;
                spService->FUN_1410c3f10(nKey, nValue);
            }
        }
        COutPacket out(0x10, 0);
        out.COutPacket::vfunc_o10_3(FUN_1403ed2d0()->FUN_141bd98d0());
        FUN_140710590(out);
        FUN_1403ed2d0()->FUN_141bdb690();
    }
    else
    {
        efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService)
        {
            spService->FUN_1410c3020(nMapId);
            spService->FUN_1410c3160(nE);
            spService->FUN_1410c3120(nD);
            spService->FUN_1410cb8b0(false);
            spService->FUN_1410c31a0(nOwner);
            spService->FUN_1410c3220(strName);
            spService->FUN_1410c32b0(strDesc);
            spService->FUN_1410c3310(nC);
            spService->FUN_1410c3410(nA);
            spService->FUN_1410c3450(nB);
            spService->FUN_1410c3630(nF);
            spService->FUN_1410c3490(nG);
            spService->FUN_1410c34d0(nH);
            spService->FUN_1410c3530(rule);
            if (bHasInfo != 0)
            {
                spService->FUN_1410c3670();
                if (nOwner == DAT_143ab2820)
                {
                    spService->FUN_1410d43c0(arrDesign);
                    spService->FUN_1410d4680(arrBlueprint);
                }
            }
            for (efd::map<Unk_CMISKindB, unsigned char>::iterator it = mapFlags.begin(); it != mapFlags.end(); ++it)
            {
                int nKey = it->first;
                bool bValue = it->second;
                spService->FUN_1410c3e40(nKey, bValue);
            }
            for (efd::map<Unk_CMISKindB, int>::iterator it = mapValues.begin(); it != mapValues.end(); ++it)
            {
                int nKey = it->first;
                int nValue = it->second;
                spService->FUN_1410c3f10(nKey, nValue);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14170e800, CSceneStateGame, OnLoadUgcMap, 4389, 0xE0B12C5E);

// @0x14170f930
void CSceneStateGame::FUN_14170f930(CInPacket& packet)
{
    int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nError == 0)
    {
        DAT_143ab2870 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab2878 = static_cast<CInputStream&>(packet).vfunc_o8_1();
        DAT_143ab287c = static_cast<CInputStream&>(packet).vfunc_o8_1();
        DAT_143ab2880 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_140930ba0(static_cast<CInputStream&>(packet).vfunc_o8_3());
        Unk_StreamPoint pos = static_cast<CInputStream&>(packet).vfunc_o8_10();
        Unk_StreamPoint rot = static_cast<CInputStream&>(packet).vfunc_o8_10();
        int nPortal = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_1403ed2d0()->FUN_141bd3d70(pos, rot);
        FUN_1403ed2d0()->FUN_141bbbe40(DAT_143ab2870, 1, nPortal);
        FUN_1403ed2b0()->FUN_141adc400();
        DAT_143ab2890 = 0;
        FUN_140967100()->FUN_141b21390();
        FUN_1409331e0()->FUN_14138d7e0(1, DAT_143ab2870);
    }
    else
    {
        FUN_140d73aa0(FUN_140cc20a0(nError), 0, 0, CStringW(L""));
    }
    FUN_1408e57f0()->FUN_1422ba0d0();
    if (DAT_143ab287c == 0xd)
        FUN_1408e57f0()->FUN_1422b9fd0(0x6200086);
}
MS2_REPLACE_METHOD(0x14170f930, CSceneStateGame, FUN_14170f930, 812, 0xCE56891C);

// @0x14170fc70
void CSceneStateGame::FUN_14170fc70(CInPacket& packet)
{
    int nResult = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nResult == 0)
    {
        FUN_140931510()->FUN_140d9f710(packet);
    }
    else if (nResult == 2)
    {
        int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_1412b9870(nId, nType);
    }
    else if (nResult == 1)
    {
        FUN_1412751f0(FUN_14028de60(0x99d), 1, 1);
    }
}
MS2_REPLACE_METHOD(0x14170fc70, CSceneStateGame, FUN_14170fc70, 291, 0x93A32950);

// @0x141711dc0
void CSceneStateGame::FUN_141711dc0(CInPacket& packet)
{
    int nMapId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    MyPC* pPC = pWorld->FUN_141bd0cc0();
    if (pPC != 0)
        FUN_141663500(pPC, nMapId);
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0)
        pWorld->FUN_141bbbcf0(nMapId, 1);
    else
        pWorld->FUN_141bbbcf0(nMapId, 0);
}
MS2_REPLACE_METHOD(0x141711dc0, CSceneStateGame, FUN_141711dc0, 160, 0xEBC6BBF3);

// @0x141712340
void CSceneStateGame::FUN_141712340(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    GameObject* pObj = FUN_1403ed2d0()->FUN_141bd1180(nId);
    if (pObj == 0)
        return;
    Unk_SSGDropItem* pDrop = efd::DynamicCast<Unk_SSGDropItem>(pObj);
    if (pDrop == 0)
        return;
    if (pDrop->FUN_1411900d0() == 0)
    {
        Unk_SSGWorld* pWorld = FUN_1403ed2d0();
        pDrop->vfunc_40(1.0f, 0, 0, 0.5f);
        pWorld->FUN_141bbbcf0(nId, 1);
    }
}
MS2_REPLACE_METHOD(0x141712340, CSceneStateGame, FUN_141712340, 205, 0x49E1B8C7);
// @0x141712420
// MS2-FUNCTIONAL: stack temp layout differs (the exe spills the uid and EP reads to expression temps); same calls and args
void CSceneStateGame::OnFieldPickupItem(CInPacket& packet)
{
    int bPicked = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    GameObject* pObj = FUN_1403ed2d0()->FUN_141bd1180(nId);
    if (pObj == 0)
        return;
    Unk_SSGDropItem* pDrop = efd::DynamicCast<Unk_SSGDropItem>(pObj);
    if (pDrop == 0)
        return;
    if (bPicked)
    {
        int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (pDrop->FUN_14118fea0())
        {
            __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
            pDrop->FUN_14174a5a0(nValue);
        }
        if (pDrop->FUN_14118ff10())
        {
            unsigned __int64 nAdd = (unsigned)static_cast<CInputStream&>(packet).vfunc_o8_3();
            MyPC* pMyPC = FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(nOwnerId));
            if (pMyPC != 0)
            {
                // MS2: slot 88 (MyPC's override returns its EP gauge; PCBase declares the slot as int)
                Unk_SSGMyPCSlots* pSlots = (Unk_SSGMyPCSlots*)pMyPC;
                pSlots->vfunc_88()->FUN_141931bd0(pMyPC->FUN_141670a00(10) + nAdd, pMyPC->FUN_141670a30(10));
            }
        }
        pDrop->FUN_141190b70(nOwnerId);
    }
    else
    {
        int nMode = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (nMode == 1)
            pDrop->FUN_141192840(0);
    }
}
MS2_REPLACE_METHOD(0x141712420, CSceneStateGame, OnFieldPickupItem, 617, 0x6508A283);


// @0x141712690
void CSceneStateGame::OnUserSync(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    FUN_1417127b0(packet, pPC);
}
MS2_REPLACE_METHOD(0x141712690, CSceneStateGame, OnUserSync, 109, 0x001F1562);

// @0x141712710
void CSceneStateGame::OnRideSync(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    if (pPC->FUN_1416764a0() == 0)
        return;
    Ridee* pRidee = pPC->FUN_1416764a0();
    FUN_1417127b0(packet, pRidee);
}
MS2_REPLACE_METHOD(0x141712710, CSceneStateGame, OnRideSync, 141, 0xA57CCB2D);

// @0x1417127b0
void CSceneStateGame::FUN_1417127b0(CInPacket& packet, PCBase* pActor)
{
    if (pActor == 0)
        return;
    int nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();
    MyPC* pMyPC = FUN_14096e160(pActor);
    if (pMyPC != 0)
    {
        MS2Ptr<Unk_StateArg22> spReq(0);
        for (int i = 0; i < nCount; i++)
        {
            int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
            spReq = FUN_140835450(nType);
            spReq->FUN_1408356f0(packet);
        }
        pMyPC->FUN_141523be0()->FUN_1417b7450();
        static_cast<CStateManager*>(pMyPC->GetStateMgr())->FUN_1417db550(spReq.get());
        if (FUN_14166d220(pMyPC) != 0)
        {
            FUN_14166d220(pMyPC)->FUN_141240730();
            FUN_14166d220(pMyPC)->FUN_141240f20()->FUN_140cfaf30();
        }
    }
    else
    {
        for (int i = 0; i < nCount; i++)
        {
            int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
            MS2Ptr<Unk_StateArg22> spReq = FUN_140835450(nType);
            spReq->FUN_1408356f0(packet);
            pActor->vfunc_114(spReq.get());
        }
    }
}
MS2_REPLACE_METHOD(0x1417127b0, CSceneStateGame, FUN_1417127b0, 718, 0x3B245B75);

// 0x141746370: the learned emotion notification (ctor/dtor are emitted in this unit; vfunc_1 lives in the notify unit).
class NotifyLearnEmotion : public NotifyObject
{
public:
    NotifyLearnEmotion(int nId) : m_nId(nId) {}
    virtual ~NotifyLearnEmotion() = default;
    virtual CStringW vfunc_1();                             // 0x140db4190
    int m_nId;                                              // +0x18
};
MS2_CHECK_SIZE(NotifyLearnEmotion, 0x20);
// @0x141712a90
void CSceneStateGame::FUN_141712a90(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    if (nMode == 0)
    {
        pMyPC->FUN_141523bc0()->FUN_141769250();
        size_t nCount = (unsigned int)static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (size_t i = 0; i < nCount; i++)
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            unsigned short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_3();
            bool bA = static_cast<CInputStream&>(packet).vfunc_o8_0();
            __int64 nStart = static_cast<CInputStream&>(packet).vfunc_o8_4();
            __int64 nEnd = static_cast<CInputStream&>(packet).vfunc_o8_4();
            bool bB = static_cast<CInputStream&>(packet).vfunc_o8_0();
            pMyPC->FUN_141523bc0()->FUN_141768e70(nId, nLevel, nStart, nEnd, bA, bB, 0);
        }
    }
    else if (nMode == 1)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        unsigned short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nStart = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nEnd = static_cast<CInputStream&>(packet).vfunc_o8_4();
        pMyPC->FUN_141523bc0()->FUN_141768e70(nId, nLevel, nStart, nEnd, false, false, 1);
        FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyLearnEmotion(nId)));
    }
    else if (nMode == 3)
    {
        int nResult = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nResult == 1)
            FUN_140d73bc0(0x858, 0, 0, L"");
        else if (nResult == 0)
            FUN_140d73bc0(0x857, 0, 0, L"");
    }
}
MS2_REPLACE_METHOD(0x141712a90, CSceneStateGame, FUN_141712a90, 1298, 0xE15A5F74);

// @0x141712fb0
// MS2-FUNCTIONAL: exe frame 0x20 larger (the uid reads go through extra expression temps); same calls and args
void CSceneStateGame::OnItemPutOnOrOff(CInPacket& packet)
{
    switch (static_cast<CInputStream&>(packet).vfunc_o8_1())
    {
    case 2:
        DAT_143ab2a90.FUN_140a621c0(static_cast<CInputStream&>(packet).vfunc_o8_4(), 0, 0);
        break;
    case 3:
        DAT_143ab2a90.FUN_140a62920(static_cast<CInputStream&>(packet).vfunc_o8_4());
        break;
    case 5:
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        unsigned char nSlot = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nKind = FUN_140222f60(static_cast<CInputStream&>(packet).vfunc_o8_1());
        MyPC* pMyPC = FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(nId));
        if (pMyPC == 0)
            return;
        MS2Ptr<CEquipItem> spEquip = pMyPC->FUN_1416561a0()->FUN_1411e1580(nItemUid);
        if (!spEquip)
            return;
        pMyPC->FUN_1416561a0()->FUN_1411e4150(nItemUid, nSlot, nKind);
        Unk_SSGItemHub* pHub = FUN_140a6a840();
        pHub->vfunc_22(spEquip->GetItem().get());
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x141712fb0, CSceneStateGame, OnItemPutOnOrOff, 748, 0xAE8F8967);
// ---- item storage (bank) updates ---------------------------------------------------------------------------------
class Unk_SSGStorage
{
public:
    void FUN_140c868d0();                                   // the storage was cleared
    void FUN_140c869e0(CItem* pItem);                       // add an item
    MS2Ptr<CItem> FUN_140c87250(__int64 nItemUid);          // find an item by uid
    void FUN_140c86bb0(__int64 nItemUid);                   // remove an item
    int FUN_140c874f0();
    MS2Ptr<CItem> FUN_140c86c90(int nSlot);
    void FUN_140c88100();                                   // a pet of the local player was summoned
};
class Unk_SSG535320 { public: Unk_SSGStorage* FUN_140c8b410(); __int64 FUN_140c8b2e0(); void FUN_140c8b300(__int64 nValue); };
Unk_SSG535320* FUN_140535320();

// @0x1417132b0
void CSceneStateGame::FUN_1417132b0(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 6)
    {
        FUN_140535320()->FUN_140c8b410()->FUN_140c868d0();
    }
    else if (nMode == 4)
    {
        int nCount = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        for (int i = 0; i < nCount; i++)
        {
            int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
            short nAmount = static_cast<CInputStream&>(packet).vfunc_o8_2();
            int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_140523c40(nItemId, nRarity, 0))
            {
                spItem->FUN_140526b30(DAT_143ab2864);
                spItem->FUN_140526a70(nItemUid);
                spItem->FUN_140526b70(nAmount);
                spItem->FUN_140524eb0(packet);
                spItem->FUN_1405268d0(0);
                FUN_140535320()->FUN_140c8b410()->FUN_140c869e0(spItem.get());
                FUN_140a6a840()->vfunc_5(spItem.get());
            }
        }
    }
    else if (nMode == 0)
    {
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        short nAmount = static_cast<CInputStream&>(packet).vfunc_o8_2();
        int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->FUN_140526b30(DAT_143ab2864);
            spItem->FUN_140526a70(nItemUid);
            spItem->FUN_140526b70(nAmount);
            spItem->FUN_140524eb0(packet);
            FUN_140535320()->FUN_140c8b410()->FUN_140c869e0(spItem.get());
            FUN_140a6a840()->vfunc_5(spItem.get());
        }
        MS2Ptr<CItem> spSelected = DAT_143ab2a90.FUN_140a5d680(FUN_140535320()->FUN_140c8b2e0());
        if (spSelected.get() != 0)
            spSelected->FUN_140528c40(FUN_140535320()->FUN_140c8b410()->FUN_140c874f0() > 0);
    }
    else if (nMode == 1)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(nItemUid);
        if (!spItem)
            return;
        FUN_140535320()->FUN_140c8b410()->FUN_140c86bb0(nItemUid);
        FUN_140a6a840()->vfunc_6(spItem.get());
        MS2Ptr<CItem> spSelected = DAT_143ab2a90.FUN_140a5d680(FUN_140535320()->FUN_140c8b2e0());
        if (spSelected.get() != 0)
            spSelected->FUN_140528c40(FUN_140535320()->FUN_140c8b410()->FUN_140c874f0() > 0);
    }
    else if (nMode == 3)
    {
        MS2Ptr<CItem> aspItem[2] = { 0, 0 };
        for (int i = 0; i < 2; i++)
        {
            __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
            short nSlot = static_cast<CInputStream&>(packet).vfunc_o8_2();
            if (nItemUid == 0)
            {
                MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c86c90(nSlot);
                if (spItem.get() != 0)
                    FUN_140a6a840()->vfunc_6(spItem.get());
                continue;
            }
            aspItem[i] = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(nItemUid);
            if (!aspItem[i])
                continue;
            FUN_140535320()->FUN_140c8b410()->FUN_140c86bb0(nItemUid);
            aspItem[i]->FUN_140526b70(nSlot);
        }
        for (unsigned int i = 0; i < 2; i++)
        {
            if (aspItem[i].get() != 0)
                FUN_140535320()->FUN_140c8b410()->FUN_140c869e0(aspItem[i].get());
        }
        for (unsigned int i = 0; i < 2; i++)
        {
            if (aspItem[i].get() != 0)
                FUN_140a6a840()->vfunc_7(aspItem[i].get());
        }
    }
    else if (nMode == 2)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nAmount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(nItemUid);
        if (!spItem)
            return;
        spItem->FUN_140526c70(nAmount);
        int bNotify = 1;
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0 && pPC->FUN_141527eb0() != 0)
            bNotify = 0;
        if (bNotify)
            FUN_140a6a840()->vfunc_7(spItem.get());
    }
}
MS2_REPLACE_METHOD(0x1417132B0, CSceneStateGame, FUN_1417132b0, 3305, 0xFCDC2CD4);

// The housing cube inventory (items keyed by uid).
class Unk_CubeFallbackInventory
{
public:
    void FUN_1408fbac0();                                   // clear
    void FUN_1408fbaf0(CItem* pItem);                       // add
    void FUN_1408fbc00(__int64 nItemUid);                   // remove
    MS2Ptr<CItem> FUN_1408fbf90(__int64 nItemUid);
};
extern Unk_CubeFallbackInventory DAT_143ab2e20;

// @0x141715bd0
// 0x23: the housing cube inventory.
void CSceneStateGame::FUN_141715bd0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 1)
        DAT_143ab2e20.FUN_1408fbac0();
    else if (nMode == 2)
    {
        int nUnused = static_cast<CInputStream&>(packet).vfunc_o8_3();
    }
    else if (nMode == 3)
    {
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nAmount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->FUN_140526b30(DAT_143ab2864);
            spItem->FUN_140526a70(nItemUid);
            spItem->FUN_140526b70(nAmount);
            spItem->FUN_140524eb0(packet);
            DAT_143ab2e20.FUN_1408fbaf0(spItem.get());
            FUN_140a6a840()->vfunc_13(spItem.get());
        }
    }
    else if (nMode == 4)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        MS2Ptr<CItem> spItem = DAT_143ab2e20.FUN_1408fbf90(nItemUid);
        if (!spItem)
            return;
        DAT_143ab2e20.FUN_1408fbc00(nItemUid);
        FUN_140a6a840()->vfunc_14(spItem.get());
    }
    else if (nMode == 5)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItem> spItem = DAT_143ab2e20.FUN_1408fbf90(nItemUid);
        if (spItem.get() != 0)
        {
            int bNotify = 1;
            MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPC != 0 && pPC->FUN_141527eb0() != 0)
                bNotify = 0;
            if (bNotify)
                FUN_140a6a840()->vfunc_16(spItem.get(), nValue);
        }
    }
    else if (nMode == 7)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nAmount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItem> spItem = DAT_143ab2e20.FUN_1408fbf90(nItemUid);
        if (!spItem)
            return;
        spItem->FUN_140526c70(nAmount);
        FUN_140a6a840()->vfunc_15(spItem.get());
    }
}
MS2_REPLACE_METHOD(0x141715BD0, CSceneStateGame, FUN_141715bd0, 1564, 0x3F30BB71);

// ---- inventory updates (0x21) --------------------------------------------------------------------------------------
class Unk_ItemEquipData : public CItemData { };            // CItem::FUN_140527840's record (item.cpp)
void FUN_1414047c0(MS2Ptr<CItemData> spData);
CStringW FUN_140a22c00(int nStringId, const CStringW& a, const unsigned short& b);   // FormatStringId<CStringW, unsigned short>
extern CString DAT_143ae7978;                               // sound event of the codi slot error

// @0x141713fb0
void CSceneStateGame::OnItemInventory(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0xb)
    {
        int nTab = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab2a90.FUN_140a5ca60(nTab);
    }
    else if (nMode == 0)
    {
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        short nAmount = static_cast<CInputStream&>(packet).vfunc_o8_2();
        int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->FUN_140526b30(DAT_143ab2864);
            spItem->FUN_140526a70(nItemUid);
            spItem->FUN_140526b70(nAmount);
            spItem->FUN_140524eb0(packet);
            DAT_143ab2a90.FUN_140a5d120(spItem.get());
            int bNotify = 1;
            MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPC != 0 && pPC->FUN_141527eb0() != 0)
                bNotify = 0;
            if (bNotify)
                FUN_140a6a840()->vfunc_1(spItem.get());
        }
    }
    else if (nMode == 7)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nArg = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (spItem.get() != 0)
        {
            spItem->FUN_1405268d0(1);
            if (!strName.IsEmpty())
                spItem->FUN_140529500(strName);
            if (spItem->FUN_140527840()->FUN_14053e130())
                FUN_1414047c0(spItem->FUN_140527840());
            int bNotify = 1;
            MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPC != 0 && pPC->FUN_141527eb0() != 0)
                bNotify = 0;
            if (bNotify)
                FUN_140a6a840()->vfunc_4(spItem.get(), nArg);
            if (FUN_140166410()->FUN_14036d570(0xe8))
            {
                if (spItem->FUN_140527840()->FUN_14053cbc0())
                    DAT_143ab2a90.FUN_140a66ae0(spItem);
            }
        }
    }
    else if (nMode == 6)
    {
        int nCount = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        for (int i = 0; i < nCount; i++)
        {
            int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
            short nAmount = static_cast<CInputStream&>(packet).vfunc_o8_2();
            int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_140523c40(nItemId, nRarity, 0))
            {
                spItem->FUN_140526b30(DAT_143ab2864);
                spItem->FUN_140526a70(nItemUid);
                spItem->FUN_140526b70(nAmount);
                spItem->FUN_140524eb0(packet);
                spItem->FUN_1405268d0(0);
                DAT_143ab2a90.FUN_140a5d120(spItem.get());
                FUN_140a6a840()->vfunc_1(spItem.get());
            }
        }
    }
    else if (nMode == 1)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (!spItem)
            return;
        if (spItem->FUN_140526b90() >= 0)
            FUN_140a6a840()->vfunc_21(spItem.get());
        DAT_143ab2a90.FUN_140a5d390(nItemUid);
        FUN_140a6a840()->vfunc_2(spItem.get(), false);
    }
    else if (nMode == 2)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nAmount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (!spItem)
            return;
        int nOld = spItem->FUN_140526c50();
        spItem->FUN_140526c70(nAmount);
        int bNotify = 1;
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0 && pPC->FUN_141527eb0() != 0)
            bNotify = 0;
        if (bNotify)
            FUN_140a6a840()->vfunc_3(spItem.get(), nAmount - nOld);
    }
    else if (nMode == 3)
    {
        MS2Ptr<CItem> aspItem[2] = { 0, 0 };
        for (int i = 0; i < 2; i++)
        {
            __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
            short nSlot = static_cast<CInputStream&>(packet).vfunc_o8_2();
            if (nItemUid == 0)
            {
                Unk_SSGDlgInv* pDlg = FUN_1405344f0(0x4e2d);
                if (pDlg != 0)
                {
                    int nTab = pDlg->FUN_141999de0();
                    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a60280(nTab, nSlot);
                    if (spItem.get() != 0)
                        FUN_140a6a840()->vfunc_2(spItem.get(), true);
                }
                continue;
            }
            aspItem[i] = DAT_143ab2a90.FUN_140a5d680(nItemUid);
            if (!aspItem[i])
                continue;
            DAT_143ab2a90.FUN_140a5d390(nItemUid);
            aspItem[i]->FUN_140526b70(nSlot);
        }
        for (unsigned int i = 0; i < 2; i++)
        {
            if (aspItem[i].get() != 0)
                DAT_143ab2a90.FUN_140a5d120(aspItem[i].get());
        }
        for (unsigned int i = 0; i < 2; i++)
        {
            if (aspItem[i].get() != 0)
                FUN_140a6a840()->vfunc_3(aspItem[i].get(), 0);
        }
    }
    else if (nMode == 8)
    {
        FUN_141715860(packet);
    }
    else if (nMode == 0xc)
    {
        int nTab = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab2a90.FUN_140a5cb80(nTab, nCount);
        Unk_SSGDlgInv* pDlg = FUN_1405344f0(0x4e2d);
        if (pDlg != 0 && pDlg->vfunc_55() == 0)
            pDlg->FUN_141999e50();
    }
    else if (nMode == 0xe)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        if (nItemUid != 0)
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
            if (spItem.get() != 0)
            {
                spItem->FUN_140524eb0(packet);
                FUN_140a6a840()->vfunc_3(spItem.get(), 0);
            }
        }
    }
    else if (nMode == 0xd)
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nCode = nError;
        switch (nCode)
        {
        case 0xc:
            FUN_140d73bc0(0xeb, 0, 0, L"");
            break;
        case 0xd:
            FUN_141275260(0x43, 1, 1);
            FUN_141276180(DAT_143ae7978, "");
            break;
        case 0x1f:
            FUN_140d73bc0(0x72, 0, 0, L"");
            break;
        case 0x22:
            FUN_1403ed2b0()->FUN_141add1f0();
            break;
        case 0x23:
            FUN_140d73bc0(0xfd, 0, 0, L"");
            break;
        case 0x24:
            FUN_140d73bc0(0xfe, 0, 0, L"");
            break;
        case 0x25:
            FUN_140d73aa0(FUN_14028b8e0(L"s_item_err_Invalid_slot_codi"), 0, 0, L"");
            break;
        case 0x26:
            FUN_140d73aa0(FUN_14028b8e0(L"s_item_err_not_active_tab"), 0, 0, L"");
            break;
        case 0x28:
        {
            int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            unsigned short nCount = static_cast<CInputStream&>(packet).vfunc_o8_2();
            FUN_140d73aa0(FUN_140a22c00(0x941, FUN_1401a9d70()->FUN_141811980(1, nItemId), nCount), 0, 0, L"");
            break;
        }
        case 0x29:
        {
            int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            unsigned short nCount = static_cast<CInputStream&>(packet).vfunc_o8_2();
            Unk_SSGFormatMsg(0x942, 1, 1, FUN_1401a9d70()->FUN_141811980(1, nItemId), nCount);
            break;
        }
        case 0x2a:
            FUN_140d73bc0(0xd7, 0, 0, L"");
            break;
        default:
            FUN_140d73aa0(FUN_1408116a0(0xcd, nError), 0, 0, L"");
            break;
        }
    }
    else if (nMode == 0xa)
    {
        FUN_140d73bc0(0x2a2, 0, 0, L"");
    }
    FUN_140d86260()->vfunc_56(nMode);
}
MS2_REPLACE_METHOD(0x141713FB0, CSceneStateGame, OnItemInventory, 6229, 0xDF6CC70B);
// @0x141715860
void CSceneStateGame::FUN_141715860(CInPacket& packet)
{
    int nCheck = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nCount = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
    int nNew = 0;
    if (nCheck < 0)
    {
        MS2_ASSERT_AT(0xadb, 0);
        return;
    }
    for (int i = 0; i < nCount; i++)
    {
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        short nAmount = static_cast<CInputStream&>(packet).vfunc_o8_2();
        int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->FUN_140526b30(DAT_143ab2864);
            spItem->FUN_140526a70(nItemUid);
            spItem->FUN_140526b70(nAmount);
            spItem->FUN_140524eb0(packet);
            if (spItem->FUN_140528930() == true)
                nNew++;
            DAT_143ab2a90.FUN_140a5d120(spItem.get());
            FUN_140a6a840()->vfunc_1(spItem.get());
        }
    }
    Unk_SSGDlgInv* pDlg = FUN_1405344f0(0x4e2d);
    if (pDlg != 0 && pDlg->vfunc_55() == 0)
        pDlg->FUN_141999e00();
}
MS2_REPLACE_METHOD(0x141715860, CSceneStateGame, FUN_141715860, 869, 0x0FAB05F1);

// The equip packet header (?\unit_1407a4f20.cpp decodes it): owner, item id, uid, slot, rarity, item type.
struct Unk_1407a8050
{
    Unk_1407a8050() : m_00(0), m_04(0), m_08(0), m_14(0), m_18(0) {}   // 0x141745ff0
    int m_00, m_04; __int64 m_08; int m_10; int m_14; int m_18;
};
void FUN_1407a8100(Unk_1407a8050& v, CInputStream& in);
extern CStringW DAT_143ae7980;                              // L"useBindEquipItem" (the bind confirm box tag)
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);   // fmt one-argument format
UIMessageBox* FUN_14151f890();                              // the open message box

// @0x141716680
void CSceneStateGame::OnItemPutOn(CInPacket& packet)
{
    Unk_1407a8050 kInfo;
    FUN_1407a8100(kInfo, packet);
    int nId = kInfo.m_00;
    int nItemId = kInfo.m_04;
    __int64 nItemUid = kInfo.m_08;
    int nSlot = kInfo.m_10;
    int nRarity = kInfo.m_14;
    int nType = kInfo.m_18;
    int nKind = FUN_140222f60(nType);
    if (nKind == 6)
        return;
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (!spItem->FUN_140523c40(nItemId, nRarity, 0))
        return;
    spItem->FUN_140526b30(nId);
    spItem->FUN_140526a70(nItemUid);
    spItem->FUN_140526c10(nSlot);
    if (nKind == 2)
        spItem->FUN_14052a130(nKind);
    spItem->FUN_140524eb0(packet);
    if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001f)
        pPC->vfunc_127(spItem.get(), 1);
    else
        pPC->vfunc_127(spItem.get(), 0);
    MyPC* pMyPC = FUN_1409613d0(pPC);
    if (pMyPC != 0)
    {
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001f)
        {
            if (nSlot == 1 || nSlot == 3 || nSlot == 2)
            {
                Unk_SSGItemHub* pHub = FUN_140a6a840();
                pHub->vfunc_20(spItem.get());
            }
        }
        else
        {
            Unk_SSGItemHub* pHub = FUN_140a6a840();
            pHub->vfunc_20(spItem.get());
        }
        if (FUN_140166410()->FUN_14036d570(0xe8) && DAT_143ab2a90.FUN_140a67000() != 0 &&
            DAT_143ab2a90.FUN_140a66f20() == nItemUid)
        {
            DAT_143ab2a90.FUN_140a66f40(0);
            FUN_1412751f0(FUN_1405c2690(CStringW(L"s_msg_item_auto_install_equipment"),
                FUN_1401a9d70()->FUN_141811980(1, nItemId)), 1, 1);
            UIMessageBox* pBox = FUN_14151f890();
            if (pBox != 0)
            {
                MS2Ptr<CMsgBoxData> spBox = pBox->FUN_1419f8470();
                if (spBox.get() != 0 && spBox->GetExtra() == DAT_143ae7980)
                    pBox->FUN_1419f8120();
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141716680, CSceneStateGame, OnItemPutOn, 1230, 0xCBFF9958);

// @0x141716b60
void CSceneStateGame::OnItemPutOff(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MS2Ptr<CItem> pItem = pPC->FUN_141655b80(nItemUid);
    if (!pItem)
        return;
    if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001f)
        pPC->vfunc_128(pItem.get(), 1);
    else
        pPC->vfunc_128(pItem.get(), 0);
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        Unk_SSGItemHub* pHub = FUN_140a6a840();
        pHub->vfunc_21(pItem.get());
    }
}
MS2_REPLACE_METHOD(0x141716b60, CSceneStateGame, OnItemPutOff, 415, 0xAD56BCEE);
// @0x141716d10
void CSceneStateGame::FUN_141716d10(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nAmount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (!spItem->FUN_140523c40(nItemId, nRarity, 0))
        return;
    spItem->FUN_140526b30(nId);
    spItem->FUN_140526a70(nItemUid);
    spItem->FUN_140526b70(nAmount);
    spItem->FUN_140524eb0(packet);
    pPC->FUN_1416561c0()->FUN_140c86450(spItem);
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        Unk_SSGItemHub* pHub = FUN_140a6a840();
        pHub->vfunc_6(spItem.get());
    }
}
MS2_REPLACE_METHOD(0x141716d10, CSceneStateGame, FUN_141716d10, 740, 0xFABDC7DD);


// @0x141717000
void CSceneStateGame::OnItemSkinPutOff(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MS2Ptr<CItem> pItem = pPC->FUN_141655b80(nItemUid);
    if (!pItem)
        return;
    pPC->FUN_1416561c0()->FUN_140c86510(nItemUid);
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
        FUN_140a6a840()->vfunc_5(pItem.get());
}
MS2_REPLACE_METHOD(0x141717000, CSceneStateGame, OnItemSkinPutOff, 314, 0xBDB25741);

// @0x141717140
void CSceneStateGame::OnItemUpdate(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MS2Ptr<CEquipItem> pEquip = pPC->FUN_141655c30(nItemUid);
    if (!pEquip)
        return;
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        Unk_SSGItemHub* pHub = FUN_140a6a840();
        pHub->vfunc_23(pEquip->GetItem().get());
    }
    else
    {
        pEquip->GetItem()->FUN_140524eb0(packet);
        pEquip->FUN_1411dd1c0();
    }
}
MS2_REPLACE_METHOD(0x141717140, CSceneStateGame, OnItemUpdate, 494, 0xF8FCFF09);

// @0x141717340
void CSceneStateGame::OnUserSkinColor(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    NiColor aColor[2];
    aColor[0] = FUN_141b6dea0(static_cast<CInputStream&>(packet).vfunc_o8_3());
    aColor[1] = FUN_141b6dea0(static_cast<CInputStream&>(packet).vfunc_o8_3());
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    pPC->FUN_1416591e0(0, aColor[0]);
    pPC->FUN_1416591e0(1, aColor[1]);
    FUN_141b6f220(FUN_141b6efc0(pPC->FUN_14123c410()), 0, pPC->FUN_141659220(0));
    FUN_141b6f220(FUN_141b6efc0(pPC->FUN_14123c410()), 2, pPC->FUN_141659220(1));
    pPC->FUN_141656780();
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        Unk_SSGItemHub* pHub = FUN_140a6a840();
        pHub->vfunc_24(0);
    }
}
MS2_REPLACE_METHOD(0x141717340, CSceneStateGame, OnUserSkinColor, 531, 0xB87F7FB1);

// @0x141717560
void CSceneStateGame::FUN_141717560(CInPacket& packet)
{
}
MS2_REPLACE_METHOD(0x141717560, CSceneStateGame, FUN_141717560, 11, 0x02239C70);

// @0x141717580
void CSceneStateGame::OnUserBattle(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nEmotion = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor != 0)
    {
        if (pActor->FUN_14166c930() != 0xe)
            pActor->FUN_14166ce70(nEmotion);
        efd::SmartPointer<Ridee> spRidee(pActor->FUN_1416764a0());
        if (spRidee)
            spRidee->FUN_14166ce70(nEmotion);
        if (FUN_14096e160(pActor) != 0)
        {
            PCBase* pTarget = FUN_1403ed2d0()->FUN_141bd3620();
            if (pTarget != 0)
                pTarget->FUN_14166ce70(nEmotion);
        }
    }
}
MS2_REPLACE_METHOD(0x141717580, CSceneStateGame, OnUserBattle, 297, 0xF8FFE207);

// The object an actor is linked to (FUN_141676a10: a DynamicCast to class 0x06200074 of the world object of +0xb70).
class Unk_SSGLinkedActor : public PCBase
{
public:
    void FUN_140b11760(CString strEffect);                  // play an effect on the object
};
// @0x141717b40
void CSceneStateGame::OnSkillUse(CInPacket& packet)
{
    __int64 nCastUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nSerial = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nActorId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
    int nMotion = static_cast<CInputStream&>(packet).vfunc_o8_1();
    Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_11();
    Unk_StreamPoint kDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_StreamPoint kRot = static_cast<CInputStream&>(packet).vfunc_o8_10();
    float fSpeed = static_cast<CInputStream&>(packet).vfunc_o8_15();
    bool bEffect = static_cast<CInputStream&>(packet).vfunc_o8_0();
    int nExtra = 0;
    CString strExtra;
    if (FUN_140166410()->FUN_14036d570(0xae))
    {
        bool bHasExtra = static_cast<CInputStream&>(packet).vfunc_o8_0();
        if (bHasExtra)
        {
            nExtra = static_cast<CInputStream&>(packet).vfunc_o8_3();
            strExtra = static_cast<CInputStream&>(packet).vfunc_o8_6();
        }
    }
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nActorId);
    if (pActor != 0)
    {
        Unk_InventorySkillRequest kReq(nSkillId, nLevel);
        kReq.serial = nSerial;
        kReq.tick = nCastUid;
        kReq.unknown14 = nMotion;
        kReq.origin = kPos;
        kReq.direction = kDir;
        kReq.fValue = kRot.z;
        MS2Ptr<Unk_PCBaseComp_b18> spSkill(new Unk_PCBaseComp_b18());
        if (!spSkill->FUN_1417595d0(kReq))
            return;
        if (FUN_140166410()->FUN_14036d570(0xae))
        {
            spSkill->m_nExtra = nExtra;
            spSkill->m_strExtra = strExtra;
        }
        spSkill->m_fSpeed = fSpeed;
        FUN_1403ed280()->FUN_1411a8e50(nSerial);
        pActor->FUN_141673b40(spSkill);
        Unk_SSGLinkedActor* pLinked;
        if (bEffect && (pLinked = static_cast<Unk_SSGLinkedActor*>(pActor->FUN_141676a10())) != 0)
        {
            pLinked->FUN_140b11760(FUN_1401d3200()->m_7f48.FUN_140298f80());
            pLinked->FUN_14166cc40(0x10);
        }
        MyPC* pMyPC = FUN_14096e160(pActor);
        if (pMyPC != 0)
            FUN_140aa6d40()->FUN_141b0e1d0(nSkillId);
    }
}
MS2_REPLACE_METHOD(0x141717b40, CSceneStateGame, OnSkillUse, 1544, 0xE568A4B3);
// The skill state of an actor (?\stateskill.cpp; the state while FUN_14166c930() == 0x10).
class StateSkill : public State
{
public:
    void FUN_1417ec630(bool bA, bool bB);                   // sync the cast flags
};
// @0x141718150
void CSceneStateGame::FUN_141718150(CInPacket& packet)
{
    __int64 nCastUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nActorId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
    int nMotion = static_cast<CInputStream&>(packet).vfunc_o8_1();
    Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_StreamPoint kDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_StreamPoint kRot = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_StreamPoint kMove = static_cast<CInputStream&>(packet).vfunc_o8_10();
    bool bA = static_cast<CInputStream&>(packet).vfunc_o8_0();
    bool bB = static_cast<CInputStream&>(packet).vfunc_o8_0();
    float fSpeed = static_cast<CInputStream&>(packet).vfunc_o8_5();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nActorId);
    if (pActor != 0)
    {
        MS2Ptr<Unk_PCBaseComp_b18> spCast = pActor->vfunc_103();
        if (!spCast || spCast->m_nSkillUid != nCastUid || spCast->m_nMotion != nMotion || pActor->FUN_14166c930() != 0x10)
        {
            Unk_InventorySkillRequest kReq(nSkillId, nLevel);
            kReq.serial = 0;
            kReq.tick = nCastUid;
            kReq.unknown14 = nMotion;
            kReq.origin = kPos;
            kReq.direction = kDir;
            kReq.fValue = kRot.z;
            MS2Ptr<Unk_PCBaseComp_b18> spSkill(new Unk_PCBaseComp_b18());
            if (!spSkill->FUN_1417595d0(kReq))
                return;
            spSkill->m_fSpeed = fSpeed;
            pActor->FUN_141673b40(spSkill);
        }
        else
        {
            spCast->m_kRot = kRot;
            pActor->vfunc_22(efd::Point3(reinterpret_cast<efd::Point3&>(kMove)));
            if (pActor->FUN_14166c930() == 0x10)
            {
                StateSkill* pState = static_cast<StateSkill*>(pActor->FUN_14166ccb0());
                pState->FUN_1417ec630(bA, bB);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141718150, CSceneStateGame, FUN_141718150, 1309, 0xDAA82545);

// @0x141718680
void CSceneStateGame::OnSkillCancel(CInPacket& packet)
{
    __int64 nSkillUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor != 0)
    {
        MS2Ptr<Unk_PCBaseComp_b18> spSkill = pActor->vfunc_103();
        if ((spSkill.get() ? true : false) && spSkill->m_nSkillUid == nSkillUid && pActor->FUN_14166c930() == 0x10)
            pActor->FUN_14166ccb0()->vfunc_7(1);
    }
}
MS2_REPLACE_METHOD(0x141718680, CSceneStateGame, OnSkillCancel, 295, 0x1170D80D);
enum Unk_SSGSkillUseError { Unk_SSGSkillUseError_None };   // skill use fail reason (logged through the enum MakeValue)
// @0x1417187b0
// MS2-FUNCTIONAL: code identical; the exe gives eError a lower stack slot than nState/nSlot (0x50 vs 0x58).
void CSceneStateGame::OnSkillUseFailed(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    __int64 nSkillUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    unsigned int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGSkillUseError eError = static_cast<Unk_SSGSkillUseError>(static_cast<CInputStream&>(packet).vfunc_o8_1());
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC != 0)
    {
        if (nMode == 5)
        {
            MS2Ptr<Unk_PCBaseComp_b18> spSkill = pMyPC->vfunc_103();
            if (spSkill.get() != 0 && pMyPC->FUN_14166c930() == 0x10 && spSkill->m_nSkillUid == nSkillUid)
                pMyPC->FUN_14166ccb0()->vfunc_7(1);
        }
        else if (nMode == 6)
        {
            int nState = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (nState == pMyPC->FUN_14166c930())
            {
                State* pState = pMyPC->FUN_14166ccb0();
                if (pState != 0)
                    pState->vfunc_7(1);
            }
        }
        int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_3();
        float fCool = static_cast<CInputStream&>(packet).vfunc_o8_15();
        int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (fCool > 0.0f)
        {
            MS2Ptr<Unk_SSGSkillRow> spRow = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
            if (spRow.get() != 0)
            {
                int nBaseId = spRow->FUN_1407e9b90();
                if (nBaseId != 0)
                    nSkillId = nBaseId;
            }
            pMyPC->FUN_141523bc0()->FUN_1417669c0(nSlot, nSkillId, fCool);
        }
        else if (nValue == 0)
        {
            pMyPC->FUN_141523bc0()->FUN_141765e70(nSkillId);
        }
        pMyPC->FUN_141523bc0()->FUN_141768530(nSkillId, nValue);
        if (FUN_140166440() != 0)
            FUN_140166440()->Log(0xb, 0x134, L"OnSkillUseFailed skillID :{0}, errorType :{1}", nSkillId, eError);
    }
}
MS2_REPLACE_METHOD(0x1417187b0, CSceneStateGame, OnSkillUseFailed, 955, 0xBEA2CACC);

// @0x141718b80
void CSceneStateGame::FUN_141718b80(CInPacket& packet)
{
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nType)
    {
    case 6:
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nSkillUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nLevel = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            break;
        State* pState = pPC->FUN_14166ccb0();
        if (pState == 0)
            break;
        pState->vfunc_33(true);
    }
    }
}
MS2_REPLACE_METHOD(0x141718b80, CSceneStateGame, FUN_141718b80, 347, 0x325308DD);

// Packet 0x55: an npc enters the field.
// The npc object (RTTI CNpc, 0xf40; ctor 0x14108e420 in unit_14108e1e0). Unk_SSGNpc is its member view.
class CNpc : public Unk_SSGNpc
{
public:
    CNpc();
    char m_pad_eb0[0xf40 - 0xeb0];
};
MS2_CHECK_SIZE(CNpc, 0xf40);
class NotifyAddNpc : public NotifyObject
{
public:
    NotifyAddNpc(efd::SmartPointer<Unk_SSGNpc> spNpc);      // 0x140db4860
    efd::SmartPointer<Unk_SSGNpc> m_spNpc;                  // +0x18
};
MS2_CHECK_SIZE(NotifyAddNpc, 0x20);
class CFilePreload { public: void FUN_141210540(unsigned int nId, unsigned short nType, int nPriority); };
CFilePreload* FUN_140ab7a10();
template <> bool MS2Ptr<Unk_SSGNpcData>::operator==(Unk_SSGNpcData* p) const;   // 0x1406a9050 (out of unit)
class AdditionalCli;
struct Unk_SSGBuffOwner;
class Unk_PCBaseBuffs
{
public:
    void FUN_14096fc00(int nBuffId);
    void FUN_140970ff0(CInPacket& packet);
    int FUN_14096f070(MS2Ptr<AdditionalCli> spCli);         // add a buff
    MS2Ptr<AdditionalCli> FUN_14096fc80(int nBuffId);       // find a buff
    void FUN_14096f500(int nBuffId, int nLevel);            // remove a buff
    MS2Ptr<AdditionalCli> FUN_14096f820(Unk_SSGBuffOwner* pOwner, CInPacket& packet);   // update a buff from the packet
};
MS2Ptr<Unk_SSGNpcData> FUN_1406cd330(int nNpcId);           // the npc table row
// @0x141718cf0
void CSceneStateGame::OnFieldAddNpc(CInPacket& packet)
{
    int nObjId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nNpcId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_StreamPoint kDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    kPos.z += 4.0f;
    efd::SmartPointer<Unk_SSGNpc> spNpc = new (efd::MemHint(efd::MemHint::NONE)) CNpc;
    MS2Ptr<Unk_SSGNpcData> spData = FUN_1406cd330(nNpcId);
    if (spData == 0)
        return;
    if (spData->FUN_1406ccf40())
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        spNpc->FUN_141095190(strName);
    }
    spNpc->FUN_14123c5a0(nObjId);
    spNpc->vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
    spNpc->vfunc_21(reinterpret_cast<efd::Point3&>(kDir));
    if (spNpc->vfunc_124(nNpcId) == 0)
        return;
    spNpc->vfunc_90(&packet);
    int bHidden = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (bHidden != 0)
        spNpc->vfunc_125(0);
    spNpc->FUN_1416749a0()->FUN_140970ff0(packet);
    spNpc->FUN_141094790(static_cast<CInputStream&>(packet).vfunc_o8_4());
    spNpc->FUN_14174a560(static_cast<CInputStream&>(packet).vfunc_o8_1());
    spNpc->FUN_14174a580(static_cast<CInputStream&>(packet).vfunc_o8_3());
    spNpc->FUN_14174a4f0(static_cast<CInputStream&>(packet).vfunc_o8_3());
    if (spNpc->FUN_141092ff0() != 0)
    {
        spNpc->FUN_141094f90(static_cast<CInputStream&>(packet).vfunc_o8_6());
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (int i = 0; i < nCount; i++)
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            short nType = static_cast<CInputStream&>(packet).vfunc_o8_2();
            FUN_140ab7a10()->FUN_141210540(nId, nType, 4);
        }
        spNpc->FUN_141095290(static_cast<CInputStream&>(packet).vfunc_o8_3());
    }
    if (spData->FUN_1406cd200(5) == true)
        spNpc->FUN_141095240(static_cast<CInputStream&>(packet).vfunc_o8_4());
    bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_1() == 1;
    spNpc->FUN_1410952b0(bFlag);
    if (pWorld->FUN_141bbb1e0(spNpc, 0, 1) == 0)
        return;
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyAddNpc(spNpc)));
}
MS2_REPLACE_METHOD(0x141718CF0, CSceneStateGame, OnFieldAddNpc, 2289, 0x593CABAD);

// @0x1417195f0
void CSceneStateGame::FUN_1417195f0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    Unk_SSGNpc* pNpc = pWorld->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    int n = pNpc->FUN_141093270()->m_n60;
    if (n != 0)
        pNpc->vfunc_40(1.0f, 0.0f, 0.0f, 0.5f);
    pNpc->FUN_1410932c0(0);
    pWorld->FUN_141bbbcf0(nId, 1);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyRemoveNpc(efd::SmartPointer<Unk_SSGNpc>(pNpc))));
}
MS2_REPLACE_METHOD(0x1417195f0, CSceneStateGame, FUN_1417195f0, 455, 0xC7E9BA24);

// @0x1417197c0
void CSceneStateGame::FUN_1417197c0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    pNpc->vfunc_125(1);
}
MS2_REPLACE_METHOD(0x1417197c0, CSceneStateGame, FUN_1417197c0, 113, 0xF86CD5AB);

// @0x141719840
void CSceneStateGame::FUN_141719840(CInPacket& packet)
{
    int nCount = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    CByteBuffer buf;
    for (int i = 0; i < nCount; i++)
    {
        int nSize = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        buf.FUN_140518490();
        buf.FUN_140715230(nSize);
        static_cast<CInputStream&>(packet).vfunc_o8_9(buf.FUN_140204eb0(), nSize);
        int nId = buf.CByteBuffer::vfunc_o8_3();
        Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
        if (pNpc != 0)
            pNpc->FUN_1410918e0(buf);
    }
}
MS2_REPLACE_METHOD(0x141719840, CSceneStateGame, FUN_141719840, 329, 0xF8C75F47);

// @0x141719990
void CSceneStateGame::OnInteractNpc(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    char cFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
    pNpc->FUN_14174a560(cFlag);
}
MS2_REPLACE_METHOD(0x141719990, CSceneStateGame, OnInteractNpc, 142, 0xE0A802D1);

// @0x141719a30
void CSceneStateGame::FUN_141719a30(CInPacket& packet)
{
    FUN_140967100()->FUN_141b1ddd0(packet);
}
MS2_REPLACE_METHOD(0x141719a30, CSceneStateGame, FUN_141719a30, 37, 0xEF938A5F);

// @0x141721270
void CSceneStateGame::FUN_141721270(CInPacket& packet)
{
    FUN_140ad4b90()->FUN_141861840(packet);
}
MS2_REPLACE_METHOD(0x141721270, CSceneStateGame, FUN_141721270, 37, 0x55E34197);

// @0x1417212a0
void CSceneStateGame::FUN_1417212a0(CInPacket& packet)
{
    FUN_1409670b0()->FUN_14122f270(packet);
}
MS2_REPLACE_METHOD(0x1417212a0, CSceneStateGame, FUN_1417212a0, 37, 0xF8895DB9);

// @0x1417212d0
void CSceneStateGame::FUN_1417212d0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nCount = 0;
    if (nMode == 1)
        nCount = 1;
    else if (nMode == 0)
        nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < nCount; i++)
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nA = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<Unk_RideeFieldObj> spObj = FUN_1403ed2d0()->FUN_141bc4e70(strName);
        if (spObj.get() != 0)
        {
            spObj->FUN_140ade420(nState, 0);
            spObj->FUN_140adeaa0(nA, nB, nC);
        }
        else
        {
            efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
            if (spService)
                spService->FUN_1410caa60(strName, nState);
        }
    }
}
MS2_REPLACE_METHOD(0x1417212d0, CSceneStateGame, FUN_1417212d0, 709, 0x5D2F19F9);

// @0x141721c50
void CSceneStateGame::FUN_141721c50(CInPacket& packet)
{
    if (FUN_14097a780() != 0)
        FUN_14097a780()->FUN_140ae2e90(packet);
}
MS2_REPLACE_METHOD(0x141721c50, CSceneStateGame, FUN_141721c50, 47, 0xF8C8662A);

// @0x141721c90
void CSceneStateGame::FUN_141721c90(CInPacket& packet)
{
    if (FUN_140a6a830() != 0)
        FUN_140a6a830()->FUN_140a2f730(packet);
}
MS2_REPLACE_METHOD(0x141721c90, CSceneStateGame, FUN_141721c90, 47, 0x45BF210A);

// @0x141731ac0
void CSceneStateGame::FUN_141731ac0(CInPacket& packet)
{
    FUN_1409c4b20()->FUN_1405322b0(packet);
}
MS2_REPLACE_METHOD(0x141731ac0, CSceneStateGame, FUN_141731ac0, 37, 0x0832EFFE);

// @0x141731af0
void CSceneStateGame::FUN_141731af0(CInPacket& packet)
{
    FUN_140535310()->FUN_140612850(packet);
}
MS2_REPLACE_METHOD(0x141731af0, CSceneStateGame, FUN_141731af0, 37, 0x324CBB58);

// @0x141732ac0
void CSceneStateGame::FUN_141732ac0(CInPacket& packet)
{
    FUN_14109a700()->FUN_14127e250(packet);
}
MS2_REPLACE_METHOD(0x141732ac0, CSceneStateGame, FUN_141732ac0, 37, 0x8634E0BC);

// @0x141732af0
void CSceneStateGame::FUN_141732af0(CInPacket& packet)
{
    FUN_1409eed60()->FUN_14127e550(packet);
}
MS2_REPLACE_METHOD(0x141732af0, CSceneStateGame, FUN_141732af0, 37, 0x8D93BFEE);

// @0x141733140
void CSceneStateGame::OnWebOpen(CInPacket& packet)
{
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    CString strUrl = static_cast<CInputStream&>(packet).vfunc_o8_6();
    CString strTarget(strUrl);
    FUN_140cc18a0()->FUN_141b794e0(strTarget, strUrl);
    if (nType == 1)
    {
        if (FUN_140166410()->FUN_14036d570(0x3f) == true)
        {
            Unk_SSGDlg4f24* pDlg = FUN_140b2d030(0x4f24);
            if (pDlg != 0)
            {
                pDlg->FUN_140e2e030(strUrl);
                FUN_1403ed2b0()->FUN_141adc530(0x4f24);
                return;
            }
        }
        if (!FUN_140166410()->FUN_14036d570(0x3b))
            return;
        UIWebBrowser* pBrowser = FUN_140c43790(0x4e6a);
        if (pBrowser == 0)
            return;
        pBrowser->FUN_14135ec00(strTarget, true);
        FUN_140166440()->FUN_14015eb90(0xc, 0x13, L"Open URL in Maview: {0}", strUrl);
    }
    else if (nType == 0)
    {
        FUN_1403ed2d0()->FUN_141bd9950(strTarget);
        FUN_140166440()->FUN_14015eb90(0xc, 0x13, L"Open URL in External Browser: {0}", strUrl);
    }
    else if (nType == 2)
    {
        if (FUN_140166410()->FUN_14036d570(0x5c) == true)
        {
            UIWebBrowser* pBrowser = FUN_140c43790(0x4e6a);
            if (pBrowser == 0)
                return;
            pBrowser->FUN_14135ec00(strTarget, true);
            FUN_140166440()->FUN_14015eb90(0xc, 0x13, L"Open URL in AdventureBar: {0}", strUrl);
        }
    }
}
MS2_REPLACE_METHOD(0x141733140, CSceneStateGame, OnWebOpen, 758, 0xE8555A88);

// @0x141733440
void CSceneStateGame::FUN_141733440(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        {
            CString strUrl = static_cast<CInputStream&>(packet).vfunc_o8_6();
            unsigned char bInGame = static_cast<CInputStream&>(packet).vfunc_o8_1();
            int nType = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (!bInGame)
            {
                FUN_140cc18a0()->FUN_141b78cf0(nType, strUrl);
            }
            else
            {
                switch (nType)
                {
                case 0:
                    {
                        UIWebBrowser* pDlg = FUN_140c43790(0x4e6a);
                        if (pDlg != 0)
                            pDlg->vfunc_89(strUrl);
                    }
                    break;
                case 1:
                    {
                        UIVisitorsBookDialog* pDlg = Unk_SSGGetDialog<UIVisitorsBookDialog>(0x4ed9);
                        if (pDlg != 0)
                            pDlg->vfunc_89(strUrl);
                    }
                    break;
                case 2:
                    {
                        UINoticeDialog* pDlg = Unk_SSGGetDialog<UINoticeDialog>(0x4ee9);
                        if (pDlg != 0)
                            pDlg->vfunc_89(strUrl);
                    }
                    break;
                case 5:
                    {
                        UIWebBrowserPopup* pDlg = FUN_140beafe0(0x4f40);
                        if (pDlg != 0)
                            pDlg->vfunc_89(strUrl);
                    }
                    break;
                }
            }
        }
        break;
    }
}
MS2_REPLACE_METHOD(0x141733440, CSceneStateGame, FUN_141733440, 528, 0x7F5A9213);

// @0x141734c70
void CSceneStateGame::FUN_141734c70(CInPacket& packet)
{
    FUN_140953f20()->FUN_140cd9840(packet);
}
MS2_REPLACE_METHOD(0x141734c70, CSceneStateGame, FUN_141734c70, 37, 0x3370C6DF);

// @0x1417353b0
void CSceneStateGame::FUN_1417353b0(CInPacket& packet)
{
    FUN_140c8dac0()->FUN_140d061b0(packet);
}
MS2_REPLACE_METHOD(0x1417353b0, CSceneStateGame, FUN_1417353b0, 37, 0x814EE860);

// @0x141722f70
void CSceneStateGame::OnMassiveEvent(CInPacket& packet)
{
    Unk_SSGDlg4e4c* pDlg = FUN_140e01890(0x4e4c);
    if (pDlg != 0)
        pDlg->FUN_1419f5e90(packet);
}
MS2_REPLACE_METHOD(0x141722f70, CSceneStateGame, OnMassiveEvent, 57, 0x8318DC96);

// @0x141723260
void CSceneStateGame::OnCinematic(CInPacket& packet)
{
    Unk_SSGDlg4e52* pDlg = FUN_14136f290(0x4e52);
    if (pDlg != 0)
        pDlg->FUN_141908290(packet);
}
MS2_REPLACE_METHOD(0x141723260, CSceneStateGame, OnCinematic, 57, 0x8F3BC42A);

// @0x141731160
void CSceneStateGame::FUN_141731160(CInPacket& packet)
{
    FUN_1409331e0()->FUN_14138b280(packet);
}
MS2_REPLACE_METHOD(0x141731160, CSceneStateGame, FUN_141731160, 37, 0x18BEB48B);

// @0x1417343c0
void CSceneStateGame::FUN_1417343c0(CInPacket& packet)
{
    FUN_1403ed2d0()->FUN_141bca220();
}
MS2_REPLACE_METHOD(0x1417343c0, CSceneStateGame, FUN_1417343c0, 32, 0xFBF9896B);

// @0x141734930
void CSceneStateGame::FUN_141734930(CInPacket& packet)
{
}

// @0x1417353e0
void CSceneStateGame::FUN_1417353e0(CInPacket& packet)
{
    FUN_1403ed2d0()->FUN_141bca6d0(packet);
}
MS2_REPLACE_METHOD(0x1417353e0, CSceneStateGame, FUN_1417353e0, 37, 0xAEE8CE21);

// @0x141735410
void CSceneStateGame::FUN_141735410(CInPacket& packet)
{
    FUN_140930fe0(packet);
}
MS2_REPLACE_METHOD(0x141735410, CSceneStateGame, FUN_141735410, 29, 0x1B221102);

class Unk_SSGMastery
{
public:
    CStringW FUN_14066bdd0(int nType);                      // the mastery name
    CStringW FUN_14066c690(int nType, int nGrade);          // the mastery grade name
    int FUN_14066b050(int nType);                           // the max grade
    int FUN_14066ba00(int nType);                           // nonzero: a grade change refreshes the world (0xcd)
    int FUN_14066b4c0(unsigned int nRecipe);                // recipe / 1000 (mastery type)
    int FUN_14066b4e0(unsigned int nRecipe);                // recipe % 1000
};
Unk_SSGMastery* FUN_1409670c0();
// Packet 0xcd: life-skill mastery (exp and grade changes, rewards, recipe unlocks).
class Unk_SSGFishData { public: CStringW FUN_1403b2240(int nGrade); };     // the fishing grade name
Unk_SSGFishData* FUN_1403b4740();
class UIFishingBookDialog : public UIDialog { public: void FUN_140f41a10(); };     // refresh
UIFishingBookDialog* FUN_140cdecd0(int nId);                 // GetDialog<UIFishingBookDialog>
class UIPlayInstrumentDialog : public UIDialog { public: void FUN_14100c2c0(); };  // refresh
UIPlayInstrumentDialog* FUN_140d0c040(int nId);              // GetDialog<UIPlayInstrumentDialog>
class Unk_SSGMasteryMgr { public: void FUN_140b6d710(int nRecipeId); };
Unk_SSGMasteryMgr* FUN_140e5ca20();
CStringW FUN_140938ae0(CStringW sFormat, const unsigned& v0);   // FUN_14028dfa0<unsigned> (out-of-unit instance)
extern ATL::CAtlMap<unsigned int, int> DAT_143ab31a0;       // mastery id -> value
// @0x141735440
void CSceneStateGame::OnMastery(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nExp = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nSubType = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nOldGrade = static_cast<PC*>(static_cast<PCBase*>(pMyPC))->FUN_1416627d0(nType);
        unsigned int nGain = nExp - static_cast<PC*>(static_cast<PCBase*>(pMyPC))->FUN_141662750(nType);
        static_cast<PC*>(static_cast<PCBase*>(pMyPC))->FUN_141662790(nType, nExp);
        int bGradeUp = static_cast<PC*>(static_cast<PCBase*>(pMyPC))->FUN_1416627d0(nType) != nOldGrade;
        if (nType == 1)
        {
            if (bGradeUp)
            {
                int nGrade = static_cast<PC*>(static_cast<PCBase*>(pMyPC))->FUN_1416627d0(1);
                CStringW strGrade = FUN_1403b4740()->FUN_1403b2240(nGrade);
                if (nGrade == FUN_1409670c0()->FUN_14066b050(1))
                    FUN_1412751b0(FUN_1405c2690(CStringW(L"s_fishing_grade_up_max"), strGrade), 10);
                else
                    FUN_1412751b0(FUN_1405c2690(CStringW(L"s_fishing_grade_up"), strGrade), 10);
            }
            UIFishingBookDialog* pBook = FUN_140cdecd0(0x4ee6);
            if (pBook != 0 && pBook->FUN_141924630())
                pBook->FUN_140f41a10();
        }
        else if (nType == 2)
        {
            UIPlayInstrumentDialog* pInstrument = FUN_140d0c040(0x4eec);
            if (pInstrument != 0 && pInstrument->FUN_141924630())
                pInstrument->FUN_14100c2c0();
            if (nGain > 0 && nOldGrade != 4)
            {
                CStringW strMsg = FUN_140938ae0(CStringW(L"s_play_instrument_mastery"), nGain);
                FUN_1412751b0(strMsg, 0x14);
            }
        }
        else if (nType == 0xb)
        {
            int bEvent = 0;
            if (nSubType == 0xc80)
            {
                if (FUN_1401c0d90()->FUN_14047f0f0())
                    bEvent = 1;
            }
            else
            {
                if (FUN_1401c0d90()->FUN_14047f300())
                    bEvent = 1;
            }
            if (bEvent)
            {
                CStringW strMsg = FUN_140938ae0(CStringW(L"s_pettaming_mastery_event"), nGain);
                FUN_1412751b0(strMsg, 0x14);
            }
            else
            {
                CStringW strMsg = FUN_140938ae0(CStringW(L"s_pettaming_mastery"), nGain);
                FUN_1412751b0(strMsg, 0x14);
            }
        }
        else
        {
            if (nType == 5 || nType == 6)
                FUN_1409670b0()->FUN_141232260();
            UIMasteryDialog* pMastery = FUN_140faf160(0x4f1e);
            if (pMastery != 0)
                pMastery->FUN_140eb4c10(nType, bGradeUp);
            if (bGradeUp)
            {
                Unk_SSGDlg4e28* pDlg = FUN_140938b90(0x4e28);
                if (pDlg != 0)
                    pDlg->FUN_141938190();
            }
            if (FUN_1409670c0()->FUN_14066ba00(nType))
                FUN_1403ed2d0()->FUN_141bc5e20(6);
        }
    }
    else if (nMode == 1)
    {
        int nRecipe = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab31a0.SetAt(nRecipe, 1);
        Unk_SSGChatDialog* pChat = FUN_140938cd0(0x4e5d);
        if (pChat != 0)
        {
            for (int i = 0; i < nCount; i++)
            {
                int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                int nAmount = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
                pChat->FUN_141abf6e0(nItemId, nAmount);
            }
        }
        UIMasteryDialog* pMastery = FUN_140faf160(0x4f1e);
        if (pMastery != 0)
        {
            int nType = FUN_1409670c0()->FUN_14066b4c0(nRecipe);
            int nIndex = FUN_1409670c0()->FUN_14066b4e0(nRecipe);
            pMastery->FUN_140eb0bf0(nType, nIndex);
            pMastery->FUN_140eb4be0();
        }
        Unk_SSGDlg4e28* pDlg = FUN_140938b90(0x4e28);
        if (pDlg != 0)
            pDlg->FUN_141938190();
    }
    else if (nMode == 2)
    {
        int nType = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        Unk_SSGChatDialog* pChat = FUN_140938cd0(0x4e5d);
        if (pChat != 0)
        {
            for (int i = 0; i < nCount; i++)
            {
                int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                int nAmount = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
                pChat->FUN_141abf6e0(nItemId, nAmount);
            }
        }
        UIMasteryDialog* pMastery = FUN_140faf160(0x4f1e);
        if (pMastery != 0)
            pMastery->FUN_140eb5260(nType);
    }
    else if (nMode == 3)
    {
        int nRecipeId = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        FUN_140e5ca20()->FUN_140b6d710(nRecipeId);
    }
}
MS2_REPLACE_METHOD(0x141735440, CSceneStateGame, OnMastery, 2437, 0x2F06ECD1);

// @0x14173a0d0
void CSceneStateGame::FUN_14173a0d0(CInPacket& packet)
{
}

// @0x14173a5b0
void CSceneStateGame::FUN_14173a5b0(CInPacket& packet)
{
    FUN_140ad4b90()->FUN_141861f60(packet);
}
MS2_REPLACE_METHOD(0x14173a5b0, CSceneStateGame, FUN_14173a5b0, 37, 0xDB58DC13);

// @0x14171a5f0
void CSceneStateGame::OnSyncPetTamingPoint(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nB = (unsigned int)static_cast<CInputStream&>(packet).vfunc_o8_3();
    CPet* pObj = FUN_1403ed2d0()->FUN_141bd13a0(nId);
    if (pObj == 0)
        return;
    pObj->FUN_140b107f0(nA);
    pObj->FUN_140b10a10(nB);
}
MS2_REPLACE_METHOD(0x14171a5f0, CSceneStateGame, OnSyncPetTamingPoint, 197, 0x64D7F3EC);

// @0x14171a6c0
void CSceneStateGame::FUN_14171a6c0(CInPacket& packet)
{
    DAT_143ab2900 = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGDlg4e28* pDlg = FUN_140938b90(0x4e28);
    if (pDlg != 0)
        pDlg->FUN_141939620();
}
MS2_REPLACE_METHOD(0x14171a6c0, CSceneStateGame, FUN_14171a6c0, 92, 0x4986CD7D);

// @0x14171aa90
void CSceneStateGame::FUN_14171aa90(CInPacket& packet)
{
    int n = static_cast<CInputStream&>(packet).vfunc_o8_3();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_14152a2f0(n);
}
MS2_REPLACE_METHOD(0x14171aa90, CSceneStateGame, FUN_14171aa90, 99, 0x3346EE17);
// GetDialog<T>() over T's fixed dialog id (T::Id()).
template <class T> T* Unk_SSGGetUI()
{
    Unk_SSGUIMgr* pMgr = FUN_1403ed2b0();
    if (pMgr == 0)
        return 0;
    MS2Ptr<UIObject> p = pMgr->FUN_141adcea0(T::Id());
    if (p.IsNull())
        return 0;
    return dynamic_cast<T*>((UIObject*)p);
}
class UIExpBar : public UIDialog
{
public:
    static int Id() { return 0x4e27; }
    void FUN_141932080(const int& nState);
};
class Unk_SSGExpDlg : public UIDialog { public: void FUN_1419129d0(MyPC* pMyPC, int nExp, int n); void FUN_141912a80(MyPC* pMyPC, int nExp, int n); };
Unk_SSGExpDlg* FUN_140b624b0(int nId);                     // GetDialog<T>(0x4e32)
void FUN_1413606c0(__int64 nExp, int nType, int bRested, bool bFlag);   // exp chat log
// @0x14171ab00
void CSceneStateGame::FUN_14171ab00(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        __int64 nExp = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nType = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        __int64 nTotal = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nRest = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nNpcId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_0();
        int bRested = (DAT_143ab28a8 > 0);
        DAT_143ab28a0 = nTotal;
        DAT_143ab28a8 = nRest;
        if (nExp > 0)
        {
            Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nNpcId);
            if (pNpc != 0)
            {
                pNpc->FUN_141094df0(nExp);
            }
            else
            {
                int bQuest = 0;
                switch (nType)
                {
                case 0xc1f:
                case 0xc20:
                case 0xc21:
                case 0xc22:
                    bQuest = 1;
                }
                MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pMyPC != 0)
                {
                    Unk_SSGExpDlg* pDlg = FUN_140b624b0(0x4e32);
                    if (pDlg != 0)
                    {
                        if (bQuest)
                            pDlg->FUN_1419129d0(pMyPC, static_cast<int>(nExp), 0);
                        else
                            pDlg->FUN_141912a80(pMyPC, static_cast<int>(nExp), 0);
                    }
                }
            }
            UIExpBar* pBar = Unk_SSGGetUI<UIExpBar>();
            if (pBar != 0)
                pBar->FUN_141932080(3);
            MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pMyPC != 0)
                FUN_140e09140()->FUN_140a05490(pMyPC->FUN_141656a80(), nExp);
        }
        FUN_140aa6d40()->FUN_141b0ce20(3, 0);
        FUN_1413606c0(nExp, nType, bRested, bFlag);
    }
    else if (nMode == 1)
    {
        DAT_143ab28a8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
        UIExpBar* pBar = Unk_SSGGetUI<UIExpBar>();
        if (pBar != 0)
            pBar->FUN_141932080(2);
    }
}
MS2_REPLACE_METHOD(0x14171AB00, CSceneStateGame, FUN_14171ab00, 950, 0x6F4C1FBE);

// @0x14171b380
void CSceneStateGame::OnMyInfo(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MyPC* pMyPC = FUN_1409613d0(pPC);
    if (pMyPC != 0)
    {
        int nResult = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CStringW strMsg = static_cast<CInputStream&>(packet).vfunc_o8_8();
        if (nResult == 0)
        {
            pPC->FUN_141661330(strName);
            Unk_SSGDlg2711* pDlg = FUN_140938c30(0x2711);
            if (pDlg != 0)
                pDlg->vfunc_99(strName);
        }
        else if (strMsg.IsEmpty() == true)
        {
            FUN_140d73aa0(FUN_14052bd00(0x8b9, strName), 0, 0, CStringW(L""));
        }
        else
        {
            FUN_140d73aa0(strMsg, 0, 0, CStringW(L""));
        }
    }
    else
    {
        pPC->FUN_141661330(strName);
    }
}
MS2_REPLACE_METHOD(0x14171b380, CSceneStateGame, OnMyInfo, 681, 0xC07E2180);

// @0x14172f1c0
void CSceneStateGame::FUN_14172f1c0(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141523bc0()->FUN_141765de0();
}
MS2_REPLACE_METHOD(0x14172f1c0, CSceneStateGame, FUN_14172f1c0, 65, 0xDA4F33D3);

// @0x14172f210
// MS2-FUNCTIONAL: exe frame 0x10 larger (one extra stack temp shifts the later slots); same reads, calls and stores
void CSceneStateGame::FUN_14172f210(CInPacket& packet)
{
    DAT_143ab2954 = static_cast<CInputStream&>(packet).vfunc_o8_3();
    DAT_143ab32e8.FUN_1409353d0();
    DAT_143ab32f8.FUN_140642910();
    int nGroupCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < nGroupCount; i++)
    {
        int nGroup = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        Unk_SSGCountMap& kGroup = DAT_143ab32e8.FUN_140ed3b20(nGroup);
        for (int j = 0; j < nCount; j++)
        {
            int nKey = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
            int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
            kGroup.FUN_14063ec70(nKey) = nValue;
            DAT_143ab32f8.FUN_14063ec70(nKey) += nValue;
        }
    }
    int nScore = static_cast<CInputStream&>(packet).vfunc_o8_3();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC != 0)
        ((Unk_SSGMyPCScore*)pMyPC)->FUN_14174a510(nScore);
    FUN_140aa6d40()->FUN_141b0ce20(0xf, 0);
}
MS2_REPLACE_METHOD(0x14172f210, CSceneStateGame, FUN_14172f210, 610, 0xDFC46FA8);

// @0x14172f480
void CSceneStateGame::FUN_14172f480(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_140c25130()->FUN_140ca9e90(packet);
}
MS2_REPLACE_METHOD(0x14172f480, CSceneStateGame, FUN_14172f480, 120, 0xAF5B8007);

// @0x1417316d0
void CSceneStateGame::FUN_1417316d0(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141661370(1, *FUN_1401d3200()->m_3680.FUN_1402056b0(), 100000005);
}
MS2_REPLACE_METHOD(0x1417316d0, CSceneStateGame, FUN_1417316d0, 90, 0xE19EC5E4);
// @0x141731730
void CSceneStateGame::FUN_141731730(CInPacket& packet)
{
    if (FUN_14109a6f0()->FUN_14117c8b0() == 0)
        return;
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nType = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nValue = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        if (nType == 4)
            FUN_14109a6f0()->FUN_14117d090(0, nMode, nValue, 0, 0, nFlag);
        else if (nType == 7)
            FUN_14109a6f0()->FUN_14117d090(0, nMode, 0, nValue, 0, nFlag);
        else if (nType == 10)
            FUN_14109a6f0()->FUN_14117d090(0, nMode, 0, 0, nValue, nFlag);
    }
    else if (nMode == 1)
    {
        __int64 nA = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        __int64 nB = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        __int64 nC = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        FUN_14109a6f0()->FUN_14117d090(0, nMode, nA, nB, nC, 0);
    }
    else if (nMode == 2)
    {
        int nKind = static_cast<CInputStream&>(packet).vfunc_o8_1();
        __int64 nValue = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        if (FUN_14109a6f0()->FUN_14117c8b0() != 0)
        {
            if (nKind == 0)
                FUN_14109a6f0()->FUN_14117e7c0(nValue);
            if (nKind == 1)
                FUN_14109a6f0()->FUN_14117e720(nValue);
        }
    }
}
MS2_REPLACE_METHOD(0x141731730, CSceneStateGame, FUN_141731730, 891, 0x1BD4802F);

// @0x1417337c0
void CSceneStateGame::OnAutoRevive(CInPacket& packet)
{
    int n = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (FUN_1403ed2b0()->FUN_141adc940(0x4ea2) != 0)
        FUN_1403ed2b0()->FUN_141adc530(0x4ea2);
    UIAutoReviveCountDownDialog* pDlg = Unk_SSGGetDialog<UIAutoReviveCountDownDialog>(0x4ea2);
    if (pDlg != 0)
        pDlg->FUN_141284d70(n);
}
MS2_REPLACE_METHOD(0x1417337c0, CSceneStateGame, OnAutoRevive, 134, 0x0C0969CE);

// @0x141733850
void CSceneStateGame::OnPlayerKillNotice(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (FUN_1403ed2b0()->FUN_141adc940(0x4ea0) != 0)
        FUN_1403ed2b0()->FUN_141adc530(0x4ea0);
    if (nMode == 0)
    {
        CStringW strKiller = static_cast<CInputStream&>(packet).vfunc_o8_8();
        CStringW strVictim = static_cast<CInputStream&>(packet).vfunc_o8_8();
        FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyKillPlayer(strKiller, strVictim)));
        UIPvPKillLogDialog* pDlg = Unk_SSGGetDialog<UIPvPKillLogDialog>(0x4ea0);
        if (pDlg != 0)
            pDlg->FUN_141342880(strKiller, strVictim);
    }
    else if (nMode == 1)
    {
        CStringW strMsg = StringIdInterface(packet).FUN_141024e60();
        FUN_1412751f0(strMsg, 4, 1);
        CString strArg("");
        FUN_141276180(DAT_143ae7a10, strArg);
    }
}
MS2_REPLACE_METHOD(0x141733850, CSceneStateGame, OnPlayerKillNotice, 729, 0x5BEE76B4);

// @0x141734b20
void CSceneStateGame::OnGlobalPortal(CInPacket& packet)
{
    UIGlobalPortalDialog* pDlg = Unk_SSGGetDialog<UIGlobalPortalDialog>(0x4ed7);
    if (pDlg == 0)
        return;
    pDlg->FUN_1412c3020(packet);
}
MS2_REPLACE_METHOD(0x141734b20, CSceneStateGame, OnGlobalPortal, 59, 0x0FB46947);

// @0x141734b70
void CSceneStateGame::OnQuizEvent(CInPacket& packet)
{
    UIQuizDialog* pDlg = Unk_SSGGetDialog<UIQuizDialog>(0x4ee1);
    if (pDlg == 0)
        return;
    pDlg->FUN_14129a930(packet);
}
MS2_REPLACE_METHOD(0x141734b70, CSceneStateGame, OnQuizEvent, 59, 0x27EDF9AF);

// @0x141734bc0
void CSceneStateGame::FUN_141734bc0(CInPacket& packet)
{
    CString strUrl = static_cast<CInputStream&>(packet).vfunc_o8_6();
    if (strUrl.GetLength() < 1)
        return;
    FUN_141276180(strUrl, "");
}
MS2_REPLACE_METHOD(0x141734bc0, CSceneStateGame, FUN_141734bc0, 155, 0x8BD553A5);

// Packet 0xa8: fame / achievement / collection counters held in globals.
class UIAchieveDialog { public: void FUN_1418a8f80(); };   // refresh when not hidden
UIAchieveDialog* FUN_1412bcec0(int nId);                    // GetDialog<UIAchieveDialog>
extern ATL::CAtlArray<unsigned int> DAT_143ab3268;          // completed achievement ids
extern ATL::CAtlMap<unsigned int, unsigned int> DAT_143ab30e0;  // achievement id -> grade
extern ATL::CAtlArray<int> DAT_143ab3128;                    // templates whose first use was announced
extern ATL::CAtlMap<int, int> DAT_143ab3150;                // item id -> count
extern ATL::CAtlMap<unsigned int, int> DAT_143ab31a0;       // mastery id -> value
extern ATL::CAtlMap<Unk_FameAlliance, int> DAT_143ab3220;   // alliance -> fame points
extern ATL::CRBMap<__int64, int> DAT_143ab31e8;             // character id -> fame points
// RemoveAll of DAT_143ab31e8's tree is unit_14092f420's COMDAT (0x1409333a0); the in-range RemoveAll is another tree's.
template <> void ATL::CRBTree<__int64, int, ATL::CElementTraits<__int64>, ATL::CElementTraits<int> >::RemoveAll() throw();
// @0x141736940
void CSceneStateGame::FUN_141736940(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 1)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            return;
        pPC->FUN_141661c70(nValue);
    }
    else if (nMode == 0)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab3268.Add(nId);
        Unk_SSGChatDialog* pChat = FUN_140938cd0(0x4e5d);
        if (pChat != 0)
            pChat->FUN_141ac0ac0(nId);
        MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC != 0)
            FUN_141a60f00(pMyPC->FUN_14123c580());
    }
    else if (nMode == 2)
    {
        DAT_143ab3268.RemoveAll();
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (int i = 0; i < nCount; i++)
        {
            unsigned int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            DAT_143ab3268.Add(nId);
        }
    }
    else if (nMode == 3)
    {
        DAT_143ab30e0.RemoveAll();
        size_t nCount = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        for (size_t i = 0; i < nCount; i++)
        {
            unsigned int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            unsigned int nGrade = static_cast<CInputStream&>(packet).vfunc_o8_1();
            DAT_143ab30e0.SetAt(nId, nGrade);
        }
        UIAchieveDialog* pDlg = FUN_1412bcec0(0x4e73);
        if (pDlg != 0)
            pDlg->FUN_1418a8f80();
    }
    else if (nMode == 4)
    {
        DAT_143ab3128.RemoveAll();
        size_t nCount = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        for (size_t i = 0; i < nCount; i++)
        {
            int nTemplate = static_cast<CInputStream&>(packet).vfunc_o8_3();
            DAT_143ab3128.Add(nTemplate);
        }
    }
    else if (nMode == 8)
    {
        DAT_143ab3150.RemoveAll();
        size_t nCount = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        for (size_t i = 0; i < nCount; i++)
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
            DAT_143ab3150.SetAt(nId, nValue);
        }
    }
    else if (nMode == 9)
    {
        DAT_143ab31a0.RemoveAll();
        size_t nCount = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        for (size_t i = 0; i < nCount; i++)
        {
            unsigned int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
            DAT_143ab31a0.SetAt(nId, nValue);
        }
    }
    else if (nMode == 0xa)
    {
        DAT_143ab3220.RemoveAll();
        size_t nCount = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        for (size_t i = 0; i < nCount; i++)
        {
            Unk_FameAlliance eAlliance = static_cast<Unk_FameAlliance>(static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2()));
            int nFame = static_cast<CInputStream&>(packet).vfunc_o8_3();
            DAT_143ab3220.SetAt(eAlliance, nFame);
        }
    }
    else if (nMode == 0xb)
    {
        Unk_FameAlliance eAlliance = static_cast<Unk_FameAlliance>(static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2()));
        int nFame = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab3220.SetAt(eAlliance, nFame);
    }
    else if (nMode == 0xc)
    {
        DAT_143ab31e8.RemoveAll();
        size_t nCount = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        for (size_t i = 0; i < nCount; i++)
        {
            int nFame = static_cast<CInputStream&>(packet).vfunc_o8_3();
            __int64 nCharId = static_cast<CInputStream&>(packet).vfunc_o8_4();
            DAT_143ab31e8.SetAt(nCharId, nFame);
        }
    }
    else if (nMode == 0xd)
    {
        int nFame = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nCharId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        DAT_143ab31e8.SetAt(nCharId, nFame);
        CStringW strKey(L"s_fame_point_update");
        FUN_1412751b0(FUN_14028b8e0(strKey), 0x14);
    }
}
MS2_REPLACE_METHOD(0x141736940, CSceneStateGame, FUN_141736940, 2576, 0xC99A41D7);

// @0x141737360
void CSceneStateGame::FUN_141737360(CInPacket& packet)
{
    FUN_140931510()->FUN_140d9f2c0()->FUN_140b20be0(packet);
}
MS2_REPLACE_METHOD(0x141737360, CSceneStateGame, FUN_141737360, 95, 0x096233CB);

// Packet 0xce: UGC map (home) visit results and the password portal (mypc.cpp's lock map and key).
class UIApartmentDialog : public UIDialog { public: bool FUN_1418b6ab0(int nMode); };   // nonzero: handled
// A password portal lock (RTTI UGCMapEnterBlockInfo, 0x28; ctor 0x1408b3e20 in ?\ugcmapoptions.cpp).
class Unk_MyPCPortalLock : public CPtred
{
public:
    Unk_MyPCPortalLock();
    __int64 m_nUntil;                                       // +0x18 the portal cannot be retried before this
    int m_nTries;                                           // +0x20 wrong passwords
};
// The key of a password portal (world, portal coordinates and the portal object uid).
struct Unk_MyPCPortalKey
{
    Unk_MyPCPortalKey(unsigned nWorld, int nA, int nB, unsigned __int64 nC);   // 0x141532850
    bool operator==(const Unk_MyPCPortalKey& o) const;      // 0x141533020
    bool operator<(const Unk_MyPCPortalKey& o) const;       // 0x1415332e0
    unsigned m_nWorld;
    int m_nA;
    int m_nB;
    unsigned __int64 m_nC;
};
extern ATL::CRBMap<Unk_MyPCPortalKey, MS2Ptr<Unk_MyPCPortalLock> > DAT_143ab3288;   // the locked password portals
// The pending portal move (mypc.h; +0x17a0 of MyPC).
struct Unk_SSGPortalMove
{
    int m_nPortalId;                                        // +0x00
    int m_nA;                                               // +0x04
    int m_nB;                                               // +0x08
    __int64 m_nC;                                           // +0x10
    int m_nD;                                               // +0x18
    int m_bWithPwd;                                         // +0x1c
};
// MyPC's IMessageListener base (+0x12e0; the real MyPC is PC + IMessageListener, mypc.h of the owning unit).
class Unk_SSGMyPCView : public PC, public IMessageListener
{
public:
    char m_pad12e8[0x17a0 - 0x12e8];
    Unk_SSGPortalMove m_kPortalMove;                        // +0x17a0
};
MS2_CHECK_OFFSET(Unk_SSGMyPCView, m_kPortalMove, 0x17a0);
__int64 GetServerTime();
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStringId, IMessageListener* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
// @0x1417373d0
void CSceneStateGame::FUN_1417373d0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        FUN_140d73bc0(0x9cb, 0, 0, L"");
        break;
    case 2:
        FUN_140d73bc0(0x9cd, 0, 0, L"");
        break;
    case 1:
    {
        UIApartmentDialog* pDlg = Unk_SSGGetDialog<UIApartmentDialog>(0x4e74);
        if (pDlg != 0 && pDlg->FUN_1418b6ab0(nMode))
            return;
    }
        break;
    case 3:
    {
        int nPortalId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nC = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nD = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int bWithPwd = static_cast<CInputStream&>(packet).vfunc_o8_1();
        Unk_SSGMyPCView* pMyPC = static_cast<Unk_SSGMyPCView*>(static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0()));
        if (pMyPC != 0)
        {
            pMyPC->m_kPortalMove.m_nPortalId = nPortalId;
            pMyPC->m_kPortalMove.m_nA = nA;
            pMyPC->m_kPortalMove.m_nB = nB;
            pMyPC->m_kPortalMove.m_nC = nC;
            pMyPC->m_kPortalMove.m_nD = nD;
            pMyPC->m_kPortalMove.m_bWithPwd = bWithPwd;
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(10, 0xb07, pMyPC, L"movePortalWithPwd");
            if (spBox.get() != 0)
            {
                CStringW strEmpty(L"");
                spBox->FUN_141a01d30(5, strEmpty, 6, 0, 0);
                FUN_140d73c60(spBox);
            }
        }
    }
        break;
    case 4:
    {
        UIMessageBox* pBox = FUN_14151f890();
        if (pBox != 0)
            pBox->FUN_1419f82b0(FUN_14028de60(0xb0b));
        int nPortalId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nC = static_cast<CInputStream&>(packet).vfunc_o8_4();
        Unk_MyPCPortalKey key(FUN_1403ed2d0()->FUN_141bd3060(), nA, nB, nC);
        MS2Ptr<Unk_MyPCPortalLock> spLock(0);
        if (!DAT_143ab3288.Lookup(key, spLock))
        {
            spLock.AssignRaw(new Unk_MyPCPortalLock);
            DAT_143ab3288.SetAt(key, spLock);
        }
        if (spLock->m_nUntil > GetServerTime())
            break;
        spLock->m_nTries++;
        if (spLock->m_nTries >= 5)
            spLock->m_nUntil = GetServerTime() + 10;
    }
        break;
    case 5:
        FUN_140d73bc0(0x9ce, 0, 0, L"");
        break;
    case 6:
        FUN_140d73bc0(0x87c, 0, 0, L"");
        break;
    case 7:
        FUN_140d73bc0(0x87b, 0, 0, L"");
        break;
    case 8:
        FUN_140d73bc0(0x87d, 0, 0, L"");
        break;
    case 9:
        FUN_140d73bc0(0x87a, 0, 0, L"");
        break;
    case 10:
        FUN_140d73bc0(0x87e, 0, 0, L"");
        break;
    case 11:
        FUN_140d73aa0(FUN_14028b8e0(L"s_home_visit_failed_private"), 0, 0, L"");
        break;
    }
}
MS2_REPLACE_METHOD(0x1417373D0, CSceneStateGame, FUN_1417373d0, 2381, 0x68C26CA3);

// @0x141737d60
void CSceneStateGame::FUN_141737d60(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141523bc0()->FUN_141767ae0(packet);
}
MS2_REPLACE_METHOD(0x141737d60, CSceneStateGame, FUN_141737d60, 70, 0x9CE84DE8);

// 0xd3: the character name change result (an error text, or the confirm box with the name change item).
struct Unk_SSGCharNameResult
{
    Unk_SSGCharNameResult() : m_bFailed(false), m_nItemUid(0) {}   // @0x141745f30
    bool m_bFailed;                                         // +0x00
    __int64 m_nItemUid;                                     // +0x08
    CStringW m_strName;                                     // +0x10
};
void FUN_1407a5fd0(Unk_SSGCharNameResult& v, CInputStream& in);     // decode (unit_1407a4f20.cpp)
void FUN_14151f200();                                       // show the next queued message box (messageboxqueue.cpp)
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

// MS2-FUNCTIONAL: same code; the exe keeps kResult low in the frame (rsp+0x60, ours +0xf8), so every slot differs.
// @0x141737db0
void CSceneStateGame::FUN_141737db0(CInputStream& in)
{
    Unk_SSGCharNameResult kResult;
    FUN_1407a5fd0(kResult, in);
    __int64 nItemUid = kResult.m_nItemUid;
    const CStringW& strName = kResult.m_strName;
    if (kResult.m_bFailed == true)
    {
        CStringW strMsg = FUN_14052bd00(0x2a, strName);
        FUN_140d73aa0(strMsg, 0, 0, CStringW(L""));
    }
    else
    {
        MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC != 0)
        {
            CStringW strMsg = FUN_140632a60(0x28, pMyPC->vfunc_77(), strName);
            FUN_14151f200();
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strMsg, 0, s_confirmChangeCharName);
            if (spBox.get() != 0)
            {
                spBox->FUN_1405340b0(nItemUid);
                spBox->FUN_140b76940(strName);
                FUN_140d73c60(spBox);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141737DB0, CSceneStateGame, FUN_141737db0, 769, 0x55485FD5);

extern int DAT_143ab2904;                                   // the pending invite (0: none; the first one opens a message box)
extern CStringW DAT_143ae79f8;                              // the invite message box tag

// @0x141731c10
// 0x8c: invite results (system messages by mode and result).
void CSceneStateGame::FUN_141731c10(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    CStringW strMsg;
    if (nMode == 4)
    {
        int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
        CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        int nInvite = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (DAT_143ab2904 == 0)
        {
            DAT_143ab2904 = nInvite;
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14052bd00(0x902, strName), 0, DAT_143ae79f8);
            if (spBox.get() != 0)
            {
                spBox->FUN_141a01ca0(0x14, 1, FUN_14028de60(0x2b8));
                spBox->FUN_141a02460(1);
                spBox->FUN_141a02480(1);
                spBox->FUN_141a024a0(0);
                FUN_140d73c60(spBox);
            }
        }
        else
            FUN_140714f90()->FUN_141538bb0(strName, 4);
    }
    else if (nMode == 5)
    {
        CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        int nResult = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nResult == 0 || nResult == 2)
            strMsg = FUN_14052bd00(0x8fb, strName);
        else if (nResult == 1 || nResult == 3)
            strMsg = FUN_14052bd00(0x8fc, strName);
        FUN_1412751b0(strMsg, 0x14);
    }
    else if (nMode == 6)
    {
        CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        strMsg = FUN_14052bd00(0x8fd, strName);
        FUN_1412751b0(strMsg, 0x14);
    }
    else if (nMode == 7)
    {
        CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        int nResult = static_cast<CInputStream&>(packet).vfunc_o8_1();
        switch (nResult)
        {
        case 2:
            strMsg = FUN_14052bd00(0x8ff, strName);
            break;
        case 4:
            strMsg = FUN_14052bd00(0x901, strName);
            break;
        case 6:
            strMsg = FUN_14052bd00(0x8fe, strName);
            break;
        default:
            strMsg = FUN_14052bd00(0x900, strName);
            break;
        }
        FUN_1412751b0(strMsg, 0x14);
    }
}
MS2_REPLACE_METHOD(0x141731C10, CSceneStateGame, FUN_141731c10, 1838, 0x26AB7A52);

// Socket gem packet records (decoders in itemsocketsystemutil.cpp).
class TSocketGemStoneInfo : public CPtred { };   // 0x48 (ctor 0x14061f790, itemsocket.cpp), opaque here
// The exe calls the itemsocket copy (0x140623630); a local COMDAT would take the CEnchantOption dtor slot here.
template<> MS2Ptr<TSocketGemStoneInfo>::~MS2Ptr();
struct Unk_SSGGemEquip {
    Unk_SSGGemEquip();                      // 0x140c4de50
    ~Unk_SSGGemEquip();                     // 0x140c4e0b0
    __int64 m_nItemUid; int m_nSlot; MS2Ptr<TSocketGemStoneInfo> m_spGem; };
struct Unk_SSGGemUnequip {
    Unk_SSGGemUnequip();                    // 0x140c4de20
    __int64 m_nItemUid; __int64 m_nGemUid; int m_nSlot; };
void FUN_140628a00(Unk_SSGGemEquip& v, CInPacket& packet);
void FUN_140628be0(Unk_SSGGemUnequip& v, CInPacket& packet);
MS2Ptr<CItem> FUN_141425750(__int64 nUid, bool* pbEquipped);
// The item's socket record (CItemSocket, opaque in item.h).
class Unk_SSGItemSocket {
public:
    bool FUN_140621600(int nSlot, MS2Ptr<TSocketGemStoneInfo> spGem);
    MS2Ptr<TSocketGemStoneInfo> FUN_140621830(int nSlot);
};

// Socket gem update: 9 = a gem went into a slot, 11 = a gem came out.
// @0x14173f550
void CSceneStateGame::OnItemSocketSystem(CInPacket& packet)
{
    int nMode = static_cast<unsigned char>(static_cast<CInputStream&>(packet).vfunc_o8_1());
    if (nMode == 9)
    {
        Unk_SSGGemEquip kInfo;
        FUN_140628a00(kInfo, packet);
        MS2Ptr<CItem> spItem = FUN_141425750(kInfo.m_nItemUid, 0);
        if (spItem == 0 || spItem->FUN_1405279c0() == 0)
            return;
        MS2Ptr<TSocketGemStoneInfo> spGem = kInfo.m_spGem;
        if (spGem == 0)
            return;
        Unk_SSGItemSocket* pSocket = (Unk_SSGItemSocket*)spItem->FUN_1405279c0();
        pSocket->FUN_140621600(kInfo.m_nSlot, spGem);
    }
    else if (nMode == 11)
    {
        Unk_SSGGemUnequip kInfo;
        FUN_140628be0(kInfo, packet);
        MS2Ptr<CItem> spItem = FUN_141425750(kInfo.m_nItemUid, 0);
        if (spItem == 0 || spItem->FUN_1405279c0() == 0)
            return;
        Unk_SSGItemSocket* pSocket = (Unk_SSGItemSocket*)spItem->FUN_1405279c0();
        pSocket->FUN_140621830(kInfo.m_nSlot);
    }
}
MS2_REPLACE_METHOD(0x14173F550, CSceneStateGame, OnItemSocketSystem, 614, 0xF7B4DFEF);

// @0x1417380c0
void CSceneStateGame::FUN_1417380c0(CInPacket& packet)
{
    if (FUN_140302b10() == 0)
        return;
    if (DAT_143ab2918 != 0)
        return;
    FUN_140302b10()->FUN_1404c18c0(packet);
    FUN_1407476c0()->FUN_14074ee30();
    DAT_143ab2918 = 1;
}
MS2_REPLACE_METHOD(0x1417380c0, CSceneStateGame, FUN_1417380c0, 83, 0x2B6EC18E);

// @0x141738240
void CSceneStateGame::FUN_141738240(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x141738240, CSceneStateGame, FUN_141738240, 60, 0xBCDE2DFF);

// @0x141738ad0
void CSceneStateGame::FUN_141738ad0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    pNpc->FUN_141092c50(packet);
}
MS2_REPLACE_METHOD(0x141738ad0, CSceneStateGame, FUN_141738ad0, 104, 0x158C510C);

// @0x141739220
void CSceneStateGame::FUN_141739220(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            CStringW strArg0 = static_cast<CInputStream&>(packet).vfunc_o8_8();
            CStringW strArg1 = static_cast<CInputStream&>(packet).vfunc_o8_8();
            CStringW strArg2 = static_cast<CInputStream&>(packet).vfunc_o8_8();
            CStringW strArg3 = static_cast<CInputStream&>(packet).vfunc_o8_8();
            int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
            CStringW strMsg = FormatStringId(nId, strArg1, strArg2, strArg3, nValue, strArg0);
            FUN_1412751b0(strMsg, 0x14);
        }
        break;
    }
}
MS2_REPLACE_METHOD(0x141739220, CSceneStateGame, FUN_141739220, 542, 0xE9FA735F);

// @0x141739880
void CSceneStateGame::FUN_141739880()
{
    if (m_nTaxiEffect == 0)
        return;
    FUN_1403ed280()->FUN_1411a6060(m_nTaxiEffect);
    m_nTaxiEffect = 0;
}
MS2_REPLACE_METHOD(0x141739880, CSceneStateGame, FUN_141739880, 60, 0xCFA8D3E8);

#include "ms2/client/ms2/uiitemcreatedialog.h"

// ---- 0x101: the item option simulator (debug; ?\uiitemcreatedialog.cpp) -----------------------------------------
// The rolled option block of an item (commonfiles\item.h; that header clashes with this unit's CItemEnchantInfo).
class CItemOption : public CPtred
{
public:
    CItemOption(unsigned nItemId);                          // 0x1405caed0
    void FUN_1405cc190(CInputStream&);                      // 0x1405cc190 read
private:
    char m_pad[0x2f8 - 0x18];                               // unrecovered members
};
MS2_CHECK_SIZE(CItemOption, 0x2f8);

// @0x14173a0f0
void CSceneStateGame::FUN_14173a0f0(CInPacket& packet)
{
    static Unk_ItemOptionSimulator s_kSimulator;
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        s_kSimulator.FUN_1419b8730();
    }
    else if (nMode == 2)
    {
        s_kSimulator.FUN_1419b8810();
    }
    else if (nMode == 1)
    {
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
        size_t nCount = static_cast<unsigned>(static_cast<CInputStream&>(packet).vfunc_o8_3());
        for (size_t i = 0; i < nCount; i++)
        {
            MS2Ptr<CItemOption> spOption(new CItemOption(nItemId));
            spOption->FUN_1405cc190(packet);
            s_kSimulator.FUN_1419b9030(nItemId, nRarity, spOption);
        }
    }
}
MS2_REPLACE_METHOD(0x14173a0f0, CSceneStateGame, FUN_14173a0f0, 634, 0x6C9F708E);

// @0x1417398d0
void CSceneStateGame::FUN_1417398d0()
{
    UIIndividualPvPDialog* pDlg = Unk_SSGGetDialog<UIIndividualPvPDialog>(0x4ed1);
    if (pDlg != 0)
    {
        pDlg->FUN_1412cacc0();
        pDlg->FUN_1412cb220();
    }
}
MS2_REPLACE_METHOD(0x1417398d0, CSceneStateGame, FUN_1417398d0, 57, 0x29BCBD60);

// The guild battle dialogs; their getters are instantiated in mypc.cpp and guildmanager.cpp.
class UIPvPGuildTeamDialog : public UIDialog { public: void FUN_14133a210(CInPacket* pPacket); };
class UIPvPGuildTeamResultDialog : public UIDialog { public: void FUN_141340d70(CInPacket& packet); };
template <class T> T* MyPCDialog(int nId);
template <class T> T* Unk_GuildFindDialog(int nId);
extern CString DAT_143ae7a00;                               // the duel start sound event
extern CStringW DAT_143ae7a08;                              // the duel invite message box tag

// @0x141732350
// 0xb6: individual PvP (duel) and guild battle.
void CSceneStateGame::OnPvp(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 'f')
        FUN_140f97ef0()->FUN_141280c60();
    else if (nMode == 'd')
    {
        int nObjId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nObjId);
        if (pPC == 0)
            return;
        pPC->FUN_140967420()->FUN_140743a10(packet);
    }
    else if (nMode == 'e')
    {
        int bWin = static_cast<CInputStream&>(packet).vfunc_o8_1();
        MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC != 0)
            pMyPC->vfunc_59(0x28, 0, bWin ? 0x73 : 0x74, 0);
    }
    else if (nMode == 'r')
    {
        if (FUN_1403ed2b0()->FUN_141adc940(0x4ec4))
            FUN_1403ed2b0()->FUN_141adc530(0x4ec4);
        UIPvPGuildTeamDialog* pDlg = MyPCDialog<UIPvPGuildTeamDialog>(0x4ec4);
        if (pDlg != 0)
            pDlg->FUN_14133a210(&packet);
    }
    else if (nMode == 'u')
    {
        UIPvPGuildTeamResultDialog* pDlg = Unk_GuildFindDialog<UIPvPGuildTeamResultDialog>(0x4ec7);
        if (pDlg != 0)
            pDlg->FUN_141340d70(packet);
    }
    else if (nMode == 4)
        FUN_1403ed290()->FUN_1413bc250(packet);
    else if (nMode == 9)
    {
        int nArg = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_140f97ef0()->FUN_14174a530(1, nArg);
        FUN_1417398d0();
        FUN_1412751b0(FUN_14028de60(0x42b), 0x14);
        FUN_141276180(DAT_143ae7a00, "");
    }
    else if (nMode == 10)
    {
        int nPrev = FUN_140f97ef0()->FUN_1412818a0();
        FUN_140f97ef0()->FUN_14174a530(0, 0);
        FUN_1417398d0();
        if (nPrev == 1)
            FUN_1412751b0(FUN_14028de60(0x42c), 0x14);
    }
    else if (nMode == 11)
    {
        int nArg = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_140f97ef0()->FUN_14174a530(2, nArg);
        FUN_1417398d0();
        CStringW strMsg = FUN_14028de60(0x42d);
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strMsg, 0, DAT_143ae7a08);
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01ca0(0x19, 1, FUN_14028de60(0x2b8));
            spBox->FUN_141a02460(1);
            spBox->FUN_141a02480(1);
            spBox->FUN_141a024a0(0);
            FUN_140d73c60(spBox);
        }
    }
    else if (nMode == 12)
    {
        FUN_1401c0d90()->FUN_1404779b0(packet);
        UIIndividualPvPDialog* pDlg = Unk_SSGGetDialog<UIIndividualPvPDialog>(0x4ed1);
        if (pDlg != 0)
            pDlg->FUN_1412cb240();
    }
    else if (nMode == 0x11)
    {
        int nResult = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (nResult == 0)
            FUN_140d73aa0(FUN_14028b8e0(L"s_rank_duel_ui_error_in_arena_field"), 0, 0, L"");
        return;
    }
    else
        FUN_140f97ef0()->FUN_141280cd0(nMode, packet);
}
MS2_REPLACE_METHOD(0x141732350, CSceneStateGame, OnPvp, 1891, 0x04B092F0);

// @0x14173b1d0
void CSceneStateGame::FUN_14173b1d0(CInPacket& packet)
{
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    DAT_143ab2950 = nValue;
}
MS2_REPLACE_METHOD(0x14173b1d0, CSceneStateGame, FUN_14173b1d0, 67, 0x30E383DD);

// ---- 0x105: red envelope (hongbao) and massive box-opening notices ----
// FUN_14028dfa0 is the localized string-key formatter (its <CStringW, CStringW, CStringW, int>, <CStringW, CStringW,
// int, CStringW> and <CStringW, CStringW, CStringW, CStringW, int> instances sit after the handlers); the
// <CStringW, CStringW> and <int, int> instances belong to ?\vipgoods.cpp and ?\astooltip.cpp.
CStringW FUN_14028dfa0(const CStringW& sFormat, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
CStringW FUN_1408f71a0(CStringW sFormat, const CStringW& v0, const CStringW& v1);
CStringW FUN_1409e9890(CStringW sFormat, const unsigned& v0, const unsigned& v1);
// "<a href={0}><FONT color='{1}'>[{2}]</FONT></a>" (the text is escaped first).
CStringW FUN_140d2ef00(CStringW strHref, CStringW strColor, CStringW strText);

// @0x14173b5a0
void CSceneStateGame::FUN_14173b5a0(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nEnvelopeId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nRewardId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nTotal = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        CStringW strCreate = FUN_14028dfa0(CStringW(L"s_special_item_hongbao_create"), strName,
            FUN_1401a9d70()->FUN_141811980(1, nItemId), FUN_1401a9d70()->FUN_141811980(1, nRewardId), nCount);
        FUN_1412751b0(strCreate, 0x11);
        CStringW strLink = StringFormat(L"'event:itemSelect,HongBao,{0}'", nEnvelopeId);
        CStringW strHref = FUN_140d2ef00(strLink, CStringW(L"#ff8c37"), FUN_1401a9d70()->FUN_141811980(1, nItemId));
        CStringW strAnnounce = FUN_14028dfa0(CStringW(L"s_speical_item_hongbao_announce"), strName, strHref, nTotal,
            FUN_1401a9d70()->FUN_141811980(1, nRewardId));
        FUN_1412751b0(strAnnounce, 0x11);
    }
    else if (nMode == 2)
    {
        bool bGot = static_cast<CInputStream&>(packet).vfunc_o8_0();
        if (bGot == true)
        {
            int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nRewardId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
            CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
            CStringW strOwner = static_cast<CInputStream&>(packet).vfunc_o8_8();
            CStringW strMsg = FUN_14028dfa0(CStringW(L"s_special_item_hongbao_getitem"), strName,
                FUN_1401a9d70()->FUN_141811980(1, nItemId), strOwner, FUN_1401a9d70()->FUN_141811980(1, nRewardId),
                nCount);
            FUN_1412751b0(strMsg, 0x11);
        }
        else
        {
            CStringW strMsg = FUN_14028b8e0(L"s_special_item_hongbao_cantget");
            FUN_1412751b0(strMsg, 0x11);
        }
    }
    else if (nMode == 3)
    {
        CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CStringW strMsg = FUN_1408f71a0(CStringW(L"s_msg_item_open_massive_open_message"), strName,
            FUN_1401a9d70()->FUN_141811980(3, nItemId));
        FUN_1412751b0(strMsg, 0x11);
    }
    else if (nMode == 4)
    {
        unsigned nStart = static_cast<CInputStream&>(packet).vfunc_o8_3();
        unsigned nEnd = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (nStart > nEnd)
            return;
        unsigned nLeft = nEnd - nStart;
        CStringW strMsg = FUN_1409e9890(CStringW(L"s_msg_item_open_massive_extra_reward_start"), nStart, nLeft);
        FUN_1412751b0(strMsg, 0x11);
    }
    else if (nMode == 5)
    {
        unsigned nStart = static_cast<CInputStream&>(packet).vfunc_o8_3();
        unsigned nEnd = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (nStart > nEnd)
            return;
        unsigned nLeft = nEnd - nStart;
        CStringW strMsg = FUN_1409e9890(CStringW(L"s_msg_item_open_massive_extra_reward_clear"), nStart, nLeft);
        FUN_1412751b0(strMsg, 0x11);
    }
}
MS2_REPLACE_METHOD(0x14173b5a0, CSceneStateGame, FUN_14173b5a0, 2782, 0xE2711461);

// @0x14173c090
void CSceneStateGame::FUN_14173c090(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 1:
        FUN_14173c0f0(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14173c090, CSceneStateGame, FUN_14173c090, 90, 0x95D6D254);

// @0x14173ddf0
void CSceneStateGame::FUN_14173ddf0(CInPacket& packet)
{
}

// @0x14173e440
void CSceneStateGame::FUN_14173e440(CInPacket& packet)
{
    FUN_140931510()->FUN_140d9f8f0()->FUN_140a3a700(packet);
}
MS2_REPLACE_METHOD(0x14173e440, CSceneStateGame, FUN_14173e440, 95, 0x9668CF92);

// @0x14173e4b0
void CSceneStateGame::FUN_14173e4b0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        FUN_140e146f0(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14173e4b0, CSceneStateGame, FUN_14173e4b0, 87, 0xEB0B5C95);

// ---- 0x12b: arcade / hide and seek events ---------------------------------------------------------------------
// The hide and seek record of a player (PC::FUN_141664200); only the decode is called here.
class Unk_HsInfo : public CPtred { public: void FUN_14050a320(CInPacket& packet); };
template <> Unk_HsInfo* MS2Ptr<Unk_HsInfo>::get() const;     // ICF copy outside the unit (0x141371260)
class UIWatchAGameDialog : public UIDialog
{
public:
    void SetValue(int nValue);
    void SetCharId(int nCharId);
    void FUN_140fc0b60(bool bFlag);
};

// @0x14173e5b0
void CSceneStateGame::OnHideAndSeek(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
    {
        int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nCharId);
        if (pPC == 0)
            break;
        MS2Ptr<Unk_HsInfo> spInfo = pPC->FUN_141664200();
        if (spInfo.get() != 0)
            spInfo->FUN_14050a320(packet);
        break;
    }
    case 1:
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();
        std::vector<unsigned> vIds;
        for (unsigned int i = 0; i < nCount; i++)
        {
            vIds.push_back(static_cast<CInputStream&>(packet).vfunc_o8_1());
        }
        FUN_1403ed2d0()->FUN_141bda290(&vIds);
        break;
    }
    case 2:
    {
        int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nType = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MyPC* pMyPC = FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(nCharId));
        if (pMyPC == 0)
            break;
        if (nType == 2)
        {
            UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
            if (pInfo != 0)
                pInfo->FUN_1419f2720(true);
            UIArcadeLifeBar* pBar = Unk_SSGGetDialog<UIArcadeLifeBar>(0x4efc);
            if (pBar != 0)
            {
                pBar->FUN_140ef53f0(0x122, -50);
                pBar->FUN_140ef5370(nA, nB, nC);
            }
        }
        else
        {
            UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
            if (pInfo != 0)
                pInfo->FUN_1419f1d10(2, false);
            UIArcadeLifeBar* pBar = Unk_SSGGetDialog<UIArcadeLifeBar>(0x4efc);
            if (pBar != 0)
            {
                pBar->FUN_140ef53f0(0, -50);
                pBar->FUN_140ef5370(nA, nB, nC);
            }
        }
        FUN_1403ed2b0()->FUN_141add0b0(0x4e3d);
    }
        break;
    case 3:
    {
        int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MyPC* pMyPC = FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(nCharId));
        if (pMyPC == 0)
            break;
        UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
        if (pInfo != 0)
        {
            pInfo->FUN_1419f2720(false);
            pInfo->FUN_1419f1d10(2, true);
        }
        FUN_1403ed2b0()->FUN_141adc5d0(0x4efc);
    }
        break;
    case 4:
    {
        int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MyPC* pMyPC = FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(nCharId));
        if (pMyPC == 0)
            break;
        UIArcadeLifeBar* pBar = Unk_SSGGetDialog<UIArcadeLifeBar>(0x4efc);
        if (pBar != 0)
            pBar->FUN_140ef5320(nA, nB);
    }
        break;
    case 5:
    {
        int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MyPC* pMyPC = FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(nCharId));
        if (pMyPC == 0)
            break;
        pMyPC->FUN_141523bc0()->FUN_141767f80(nSkillId);
        pMyPC->FUN_141523bc0()->FUN_1417683d0();
    }
        break;
    case 6:
    {
        int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MyPC* pMyPC = FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(nCharId));
        if (pMyPC == 0)
            break;
        pMyPC->FUN_141523bc0()->FUN_141768100(nSkillId);
        pMyPC->FUN_141523bc0()->FUN_1417683d0();
    }
        break;
    case 7:
    {
        int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
        bool bShow = static_cast<CInputStream&>(packet).vfunc_o8_0();
        bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_0();
        MyPC* pMyPC = FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(nCharId));
        if (pMyPC == 0)
            break;
        UIWatchAGameDialog* pDlg = Unk_SSGGetDialog<UIWatchAGameDialog>(0x4f91);
        if (pDlg == 0)
            break;
        if (bShow)
        {
            pDlg->SetValue(nValue);
            pDlg->SetCharId(nCharId);
            pDlg->FUN_140fc0b60(bFlag);
            FUN_1403ed2b0()->FUN_141adc530(0x4f91);
        }
        else
        {
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f91);
        }
    }
        break;
    case 8:
    {
        int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nRound = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nUnused = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MyPC* pMyPC = FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(nCharId));
        if (pMyPC == 0)
            break;
        UIHideAndSeekResultDialog* pDlg = Unk_SSGGetDialog<UIHideAndSeekResultDialog>(0x4f92);
        if (pDlg != 0)
        {
            pDlg->FUN_140c1eac0(nRound, nItemId, nUnused, nCount);
            FUN_1403ed2b0()->FUN_141adc530(0x4f92);
        }
    }
        break;
    }
}
MS2_REPLACE_METHOD(0x14173E5B0, CSceneStateGame, OnHideAndSeek, 2757, 0xCF47C4D0);

// @0x14173f7c0
void CSceneStateGame::FUN_14173f7c0(CInPacket& packet)
{
    DAT_143ab2943 = static_cast<CInputStream&>(packet).vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x14173f7c0, CSceneStateGame, FUN_14173f7c0, 59, 0x3565632F);

// @0x14173f810
void CSceneStateGame::FUN_14173f810(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC != 0)
        pMyPC->FUN_141528c30(packet);
}
MS2_REPLACE_METHOD(0x14173f810, CSceneStateGame, FUN_14173f810, 60, 0xDC170DA8);
void FUN_140274970(DamageCalculatorInfo* pInfo);           // show ToString() as a system message
CStringW FUN_14061ad70(const CStringW& str, const wchar_t* pszSuffix);

// @0x14173f860
// MS2-FUNCTIONAL: stack slots differ (SYSTEMTIME/strText/hFile placement) and the exe has one extra dead jmp after the switch dispatch.
void CSceneStateGame::FUN_14173f860(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 1:
    {
        CStringW strFile = static_cast<CInputStream&>(packet).vfunc_o8_8();
        CStringW strText = static_cast<CInputStream&>(packet).vfunc_o8_8();
        SYSTEMTIME st;
        if (strFile.IsEmpty())
        {
            GetLocalTime(&st);
            strFile.Format(L"DropBox_%04d%02d%02d_%02d%02d%02d_%03d.txt", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
        }
        else if (strFile.Right(4) != L".txt")
        {
            strFile = FUN_14061ad70(strFile, L".txt");
        }
        HANDLE hFile = CreateFileW(strFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
            return;
        DWORD dwWritten = 0;
        wchar_t wBom = 0xfeff;
        WriteFile(hFile, &wBom, 2, &dwWritten, NULL);
        WriteFile(hFile, static_cast<const wchar_t*>(strText), static_cast<DWORD>(strText.GetLength() * sizeof(wchar_t)), &dwWritten, NULL);
        CloseHandle(hFile);
        break;
    }
    case 2:
    {
        DamageCalculatorInfo kInfo;
        // The client hands its CInPacket to the shared reader (same CIOBuffer + CInputStream prefix as CByteBuffer).
        kInfo.Read(reinterpret_cast<CByteBuffer&>(packet));
        kInfo.SaveToFile();
        FUN_140274970(&kInfo);
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x14173f860, CSceneStateGame, FUN_14173f860, 908, 0x688A76E0);

// @0x14173fc00
void CSceneStateGame::FUN_14173fc00(CInPacket& packet)
{
    if (FUN_1414a5830() != 0)
        FUN_1414a5830()->FUN_140a46b90(packet);
}
MS2_REPLACE_METHOD(0x14173fc00, CSceneStateGame, FUN_14173fc00, 47, 0xF0AACA5F);

// @0x14171c0b0
void CSceneStateGame::OnSkillDamage(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        FUN_14171c1d0(packet);
        break;
    case 1:
        FUN_14171cdf0(packet);
        break;
    case 3:
        FUN_14171d610(packet);
        break;
    case 4:
        FUN_14171d820(packet);
        break;
    case 5:
        FUN_14171dc40(packet);
        break;
    case 6:
        FUN_14171e440(packet);
        break;
    case 7:
        FUN_14171e860(packet);
        break;
    case 8:
        FUN_14171e9a0(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14171c0b0, CSceneStateGame, OnSkillDamage, 237, 0x1D3E61F8);

// ---- 0x3d mode 0: a skill cast's projectiles (the cast record chain, one CMagicModel per record) ----
// The cast record (RTTI SkillTargetRecord, new(0xd8); ?\skillrecord.cpp owns its members). magicdata.h hands it out
// through the 16 byte Unk_MagicTagPtr handle, so it keeps that name here.
class Unk_SSGSkillLevel : public CPtred { };                // the skill level row behind the record's +0x48 handle
struct Unk_MagicTag : public CPtred
{
    Unk_MagicTag() = default;                                       // 0x141746440 (implicit: 0x3d mode 8 value-inits it)
    virtual ~Unk_MagicTag() = default;                              // 0x141746cb0 (pinned)
    bool FUN_141758d70(unsigned long long nTagId, unsigned long long nTagSub, int nOwnerId, int nCasterId, int nSkillId,
        short nLevel, int nSrcLevel, Unk_StreamPoint ptDir, int n80, int n84, int nSrcIndex, int n8c);   // 0x141758d70 fill in

    unsigned long long m_nTagId;                                    // +0x18
    unsigned long long m_nTagSub;                                   // +0x20
    int m_nCasterId;                                                // +0x28
    int m_nOwnerId;                                                 // +0x2c
    int m_nTimeMode;                                                // +0x30
    MS2Ptr<Unk_SSGSkillRow> m_spSkill;                              // +0x38
    MS2Ptr<Unk_SSGSkillLevel> m_spLevel;                            // +0x48
    int m_nSrcLevel;                                                // +0x58
    int m_nSrcIndex;                                                // +0x5c
    Unk_StreamPoint m_ptDir;                                        // +0x60
    Unk_MagicTagPtr m_spLinked;                                     // +0x70 the cast this one continues into
    int m_n80;                                                      // +0x80
    int m_n84;                                                      // +0x84
    int m_nStartTick;                                               // +0x88
    int m_n8c;                                                      // +0x8c
    ATL::CAtlMap<__int64, int> m_mapHit;                            // +0x90
};
MS2_CHECK_OFFSET(Unk_MagicTag, m_spSkill, 0x38);
MS2_CHECK_OFFSET(Unk_MagicTag, m_spLinked, 0x70);
MS2_CHECK_OFFSET(Unk_MagicTag, m_mapHit, 0x90);
MS2_CHECK_SIZE(Unk_MagicTag, 0xd8);

// @0x14171c1d0
void CSceneStateGame::FUN_14171c1d0(CInPacket& packet)
{
    unsigned long long nTagId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
    int nSrcLevel = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nSrcIndex = static_cast<CInputStream&>(packet).vfunc_o8_1();
    Unk_StreamPoint ptStart = static_cast<CInputStream&>(packet).vfunc_o8_11();
    Unk_StreamPoint ptDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
    int bServer = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();

    MS2Ptr<Unk_PCBaseComp_b18> spCast(0);
    PCBase* pOwner = FUN_1403ed2d0()->FUN_141bd1200(nOwnerId);
    if (pOwner != 0)
    {
        MS2Ptr<Unk_PCBaseComp_b18> spFound = pOwner->FUN_141673bf0(nTagId, nSrcLevel);
        if (spFound.get() != 0 && spFound->m_nA0 == 0)
            spCast = spFound;
    }
    int nStartTick = 0;
    if (bServer != 0)
    {
        int nTimeMode = FUN_1403ed2d0()->FUN_141bd1a10(pOwner);
        nStartTick = Unk_ServerClock::GetInstance()->FUN_1414732f0(nTimeMode);
    }

    ATL::CAtlArray<Unk_MagicTagPtr> arrRoots;
    ATL::CRBMap<unsigned long long, Unk_MagicTagPtr> mapTags(10);
    for (int i = 0; i < nCount; i++)
    {
        unsigned long long nParent = static_cast<CInputStream&>(packet).vfunc_o8_4();
        unsigned long long nTagSub = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nCasterId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int n84 = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int n80 = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (static_cast<bool>(spCast.get()) || bServer != 0)
        {
            if (nParent > 0)
            {
                Unk_MagicTagPtr spParent(0);
                if (mapTags.Lookup(nParent, spParent))
                {
                    Unk_MagicTagPtr spTag(new Unk_MagicTag);
                    if (spTag->FUN_141758d70(nTagId, nTagSub, nOwnerId, nCasterId, nSkillId, nLevel, nSrcLevel, ptDir,
                            n80, n84, nSrcIndex, 0))
                    {
                        spParent->m_spLinked = spTag;
                        mapTags.SetAt(nTagSub, spTag);
                    }
                }
            }
            else
            {
                Unk_MagicTagPtr spTag(new Unk_MagicTag);
                if (spTag->FUN_141758d70(nTagId, nTagSub, nOwnerId, nCasterId, nSkillId, nLevel, nSrcLevel, ptDir,
                        n80, n84, nSrcIndex, 0))
                {
                    arrRoots.Add(spTag);
                    mapTags.SetAt(nTagSub, spTag);
                    spTag->m_nStartTick = nStartTick;
                }
            }
        }
    }

    if (static_cast<bool>(spCast.get()) || bServer != 0)
    {
        for (unsigned i = 0; i < arrRoots.GetCount(); i++)
        {
            Unk_MagicTagPtr spCur(arrRoots[i]);
            Unk_SocketPtr<CMagicModel> spModel(new CMagicModel());
            spModel->FUN_141467500(spCur, Unk_MagicTagPtr(0), ptStart, 1, bServer, 0);
            if (spCast.get() != 0)
                spCast->m_listModels.AddTail(spModel);
            do
            {
                Unk_MagicTagPtr spPrev(spCur);
                spCur = spCur->m_spLinked;
                if (spCur.get() != 0)
                {
                    Unk_SocketPtr<CMagicModel> spLinkModel(new CMagicModel());
                    spLinkModel->FUN_141467500(spCur, spPrev, ptStart, 1, bServer, 0);
                }
            } while (spCur.get() != 0);
        }
    }
}
MS2_REPLACE_METHOD(0x14171c1d0, CSceneStateGame, FUN_14171c1d0, 3088, 0xC2D4B0C8);

Unk_SSGNpc* FUN_140a38a00(GameObject* pObj);                // cast to the npc class (0x6200028)

// 0x3d mode 1: skill hits. A cast header (caster/cast uids, owner, skill, level, motion, position, direction), then
// per target its id and (flag, damage) hits; plays the hit on the target and drops the cast model when it is done.
// @0x14171cdf0
void CSceneStateGame::FUN_14171cdf0(CInPacket& packet)
{
    __int64 nCasterUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 nCastUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
    int nMotion = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nAttack = static_cast<CInputStream&>(packet).vfunc_o8_1();
    Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_11();
    Unk_StreamPoint kDir = static_cast<CInputStream&>(packet).vfunc_o8_11();
    int nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        int nCasterId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nHits = static_cast<CInputStream&>(packet).vfunc_o8_1();
        MS2Ptr<CDamageRecord> spRecord(new CDamageRecord());
        if (!spRecord->FUN_14175a610(nCasterUid, nCastUid, nOwnerId, nCasterId, nSkillId, nLevel, nMotion, nAttack, kPos,
                                     DAT_143b01a60, kDir))
            return;
        for (int j = 0; j < nHits; j++)
        {
            int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
            __int64 nDamage = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spRecord->FUN_14175abc0(nFlag, nDamage);
        }
        GameObject* pCaster = FUN_1403ed2d0()->FUN_141bd1180(nCasterId);
        if (pCaster != 0)
        {
            Unk_StreamPoint ptPos = kPos;
            Unk_StreamPoint ptDir = kDir;
            if (spRecord->FUN_14175acc0() == 0)
                FUN_14145e1a0(nCasterId, nOwnerId, spRecord->FUN_14175a850(), spRecord->FUN_14175a8b0(), &ptPos, &ptDir);
            else
                spRecord->m_kDir = ptDir;
            Unk_SSGNpc* pNpc = FUN_140a38a00(pCaster);
            if (pNpc != 0)
            {
                if (pNpc->FUN_141093270()->FUN_1406cd200(0x11))
                    spRecord->m_kPos = ptPos;
            }
            Unk_MagicXform kXform;
            FUN_141467f60(ptPos, ptDir, &kXform);
            FUN_1410a7630()->FUN_14146b440(spRecord.get(), 1, &kXform, ptDir);
        }
        if (spRecord->FUN_14175acc0() != 0 && spRecord->m_nd0 != 8)
        {
            Unk_PCBaseSkillLevel* pLevel = spRecord->FUN_14175a8b0();
            if (pLevel->m_n10c != 3 && pLevel->m_n10c != 4 && pLevel->m_n10c != 2 && pLevel->m_n110 <= 1)
                FUN_1410a7630()->FUN_14146c4b0(nCasterUid, nCastUid);
        }
    }
}
MS2_REPLACE_METHOD(0x14171CDF0, CSceneStateGame, FUN_14171cdf0, 2073, 0xD06DFEFB);

// @0x14171d610
void CSceneStateGame::FUN_14171d610(CInPacket& packet)
{
    int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nTargetId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
    __int64 nDamage = static_cast<CInputStream&>(packet).vfunc_o8_4();
    PCBase* pOwner = FUN_1403ed2d0()->FUN_141bd1200(nOwnerId);
    if (pOwner == 0)
        return;
    MS2Ptr<CDotDamageRecord> spRecord(new CDotDamageRecord());
    if (!spRecord->FUN_14175aff0(nSkillId, nOwnerId, nTargetId, nFlag, nDamage))
        return;
    FUN_1410a7630()->FUN_14146bc20(spRecord.get());
}
MS2_REPLACE_METHOD(0x14171d610, CSceneStateGame, FUN_14171d610, 514, 0xFE149045);

// 0x3d mode 4: a buff/effect update between two actors (ids, buff id, three effect values, effect flag).
// Picks an effect value: when nValue is set, it becomes the (type, value) pair to show.
static int FUN_1417403b0(const __int64& nValue, const int& nType, int& nOutType, __int64& nOutValue);

// @0x14171d820
void CSceneStateGame::FUN_14171d820(CInPacket& packet)
{
    int nTargetId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nBuffId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nValue1 = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
    __int64 nValue2 = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
    __int64 nValue3 = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
    int bShow = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PCBase* pOwner = FUN_1403ed2d0()->FUN_141bd1200(nOwnerId);
    if (pOwner == 0)
        return;
    pOwner->FUN_1416749a0()->FUN_14096fc00(nBuffId);
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC != 0)
    {
        if (pMyPC->FUN_14123c580() == nOwnerId)
            FUN_14109a6f0()->FUN_14117d090(0, 0, nValue1, nValue2, nValue3, 0);
        if (pMyPC->FUN_14123c580() == nTargetId)
        {
            FUN_14109a6f0()->FUN_14117d090(1, 0, nValue1, nValue2, nValue3, 0);
            if (nValue1 != 0)
                FUN_14109a6f0()->FUN_14117e690();
        }
    }
    if (bShow != 0)
    {
        int nType = 5;
        __int64 nValue = 0;
        if (FUN_1417403b0(nValue1, 5, nType, nValue))
        {
            Unk_StreamPoint kPos = DAT_143b01a60;
            pOwner->vfunc_111((void*)nValue, nType, nTargetId, &kPos);
        }
        if (FUN_1417403b0(nValue2, 6, nType, nValue))
        {
            Unk_StreamPoint kPos = DAT_143b01a60;
            pOwner->vfunc_111((void*)nValue, nType, nTargetId, &kPos);
        }
        if (FUN_1417403b0(nValue3, 7, nType, nValue))
        {
            Unk_StreamPoint kPos = DAT_143b01a60;
            pOwner->vfunc_111((void*)nValue, nType, nTargetId, &kPos);
        }
    }
}
MS2_REPLACE_METHOD(0x14171D820, CSceneStateGame, FUN_14171d820, 1036, 0xBA2CEA1E);
// @0x14171e440
void CSceneStateGame::FUN_14171e440(CInPacket& packet)
{
    __int64 nSkillUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nLevel = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
    int nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nHits = static_cast<CInputStream&>(packet).vfunc_o8_1();
        Unk_StreamPoint kDir = static_cast<CInputStream&>(packet).vfunc_o8_11();
        Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
        MS2Ptr<CSplashDamageRecord> spRecord(new CSplashDamageRecord());
        if (!spRecord->FUN_14175b1c0(nOwnerId, 0, nSkillUid, nSkillId, nLevel, 0, 0, kDir, kPos))
            return;
        for (int j = 0; j < nHits; j++)
        {
            int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
            __int64 nDamage = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spRecord->FUN_14175abc0(nFlag, nDamage);
        }
        GameObject* pOwner = FUN_1403ed2d0()->FUN_141bd1180(nOwnerId);
        if (pOwner != 0)
            FUN_1410a7630()->FUN_14146bc80(spRecord.get());
    }
}
MS2_REPLACE_METHOD(0x14171e440, CSceneStateGame, FUN_14171e440, 1035, 0x6B7211C5);

// @0x141721940
void CSceneStateGame::OnUserState(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    pPC->vfunc_59(nState, 0, 0, 0);
    if (nState == 12)
        pPC->vfunc_137();
    else
        pPC->vfunc_59(nState, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x141721940, CSceneStateGame, OnUserState, 232, 0x5ADFE327);

// @0x141721a30
void CSceneStateGame::OnUserMoveByPortal(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_StreamPoint kRot = static_cast<CInputStream&>(packet).vfunc_o8_10();
    int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MyPC* pMyPC = FUN_1409613d0(pPC);
    if (pMyPC != 0)
        pMyPC->FUN_141528e50(kPos, kRot, nFlag);
    else
        pPC->FUN_1416629d0(kPos, kRot);
    if (pMyPC != 0 && FUN_1422b9e00(FUN_1408e57f0()) == 0x620001f)
    {
        UISceneGameBeautyShop* pShop = dynamic_cast<UISceneGameBeautyShop*>(FUN_1422b9e50(FUN_1408e57f0()));
        if (pShop != 0)
            pShop->FUN_141ac9270();
    }
}
MS2_REPLACE_METHOD(0x141721a30, CSceneStateGame, OnUserMoveByPortal, 536, 0xEC73B912);

// @0x141722fb0
void CSceneStateGame::FUN_141722fb0(CInPacket& packet)
{
    __int64 nSkillId = (unsigned int)static_cast<CInputStream&>(packet).vfunc_o8_3();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    State* pState = pMyPC->FUN_14166ccb0();
    if (pState != 0)
    {
        pMyPC->FUN_141670700(10, nSkillId);
        FUN_140aa6d40()->FUN_141b0ce20(2, 0);
    }
}
MS2_REPLACE_METHOD(0x141722fb0, CSceneStateGame, FUN_141722fb0, 152, 0x8674E8E3);

// MS2-FUNCTIONAL: small residual code difference (the old 0x10 Unk_EffectQuery frame-size cause is fixed)
// @0x141723050
void CSceneStateGame::OnStateFallDamage(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nAmount = static_cast<unsigned int>(static_cast<CInputStream&>(packet).vfunc_o8_3());
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC != 0)
    {
        if (FUN_1403ed2d0()->FUN_141bd0cc0() == static_cast<PCBase*>(pPC))
        {
            if (pPC->FUN_14166ce30() == 0)
                pPC->vfunc_59(0x1f, 0, 0, 0);
            Unk_SSGDlg4e3c* pDlg = FUN_140ac55a0(0x4e3c);
            if (pDlg != 0)
                pDlg->FUN_141910b10(-nAmount);
            FUN_1409331e0()->FUN_14138bf00(0xf, pPC->FUN_14166ce30() == 0 ? -1 : 1, 0);
            if (pPC->FUN_1416764a0() != 0)
            {
                Unk_EffectQuery query;
                if (FUN_141658e60(pPC) == 1)
                    query.m_strName = FUN_1401d31f0()->m_str2d0;
                else if (FUN_141658e60(pPC) == 0)
                    query.m_strName = FUN_1401d31f0()->m_str2d8;
                query.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(pPC);
                query.SetActor(pPC->FUN_14123c580());
                FUN_1403ed280()->FUN_1411a4a00(&query);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141723050, CSceneStateGame, OnStateFallDamage, 522, 0x8423E0F7);

// @0x1417232a0
void CSceneStateGame::FUN_1417232a0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
    {
        unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
        FUN_140930150(nValue);
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x1417232a0, CSceneStateGame, FUN_1417232a0, 127, 0x2183B5C9);

// @0x141723330
void CSceneStateGame::FUN_141723330(CInPacket& packet)
{
    int nNpcId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->vfunc_59(0x46, new StateDataTriggerFollowNpc(nNpcId), 0, 0);
}
MS2_REPLACE_METHOD(0x141723330, CSceneStateGame, FUN_141723330, 203, 0x0195DA6E);

// @0x1417235a0
void CSceneStateGame::FUN_1417235a0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    CubeItemInfo info(packet);
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    if (pPC->FUN_1416595d0() != 0)
    {
        Unk_PCCubeCraft* pCraft = pPC->GetCubeCraft();
        if (pCraft != 0)
            pCraft->FUN_1410aa5c0(&info);
    }
}
MS2_REPLACE_METHOD(0x1417235a0, CSceneStateGame, FUN_1417235a0, 202, 0x35B1E1B2);

// Packet 0x74: the item merge option dialog (0x4e68) and the merge revert dialog (0x4f3d).
class UIItemMergeOptionDialog : public UIDialog
{
public:
    void FUN_1419d0ef0(CInPacket& packet);
    void FUN_1419d11b0(CInPacket& packet);
    void FUN_1419d12f0(CInPacket& packet);
    void FUN_1419d1490(int nA, int nB, int nC);
    void FUN_1419d1ad0(MS2Ptr<CItem> spItem);
    void FUN_1419d1d20(int nError);
};
UIItemMergeOptionDialog* FUN_14123a9b0(int nId);            // GetDialog<UIItemMergeOptionDialog>
class UIItemMergeRevertDialog : public UIDialog { public: void FUN_140e4cda0(CItem* pItem); };
UIItemMergeRevertDialog* FUN_140d274e0(int nId);            // GetDialog<UIItemMergeRevertDialog>
MS2Ptr<CItem> FUN_1419be700(unsigned __int64 nItemUid);    // inventory or equipped item
// @0x141729ce0
void CSceneStateGame::OnItemFusion(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        UIItemMergeOptionDialog* pDlg = FUN_14123a9b0(0x4e68);
        if (pDlg != 0)
            pDlg->FUN_1419d0ef0(packet);
    }
    else if (nMode == 1)
    {
        UIItemMergeOptionDialog* pDlg = FUN_14123a9b0(0x4e68);
        if (pDlg != 0)
            pDlg->FUN_1419d11b0(packet);
    }
    else if (nMode == 2)
    {
        UIItemMergeOptionDialog* pDlg = FUN_14123a9b0(0x4e68);
        if (pDlg != 0)
            pDlg->FUN_1419d12f0(packet);
    }
    else if (nMode == 6)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (spItem.get() != 0)
        {
            spItem->FUN_140524eb0(packet);
            UIItemMergeRevertDialog* pDlg = FUN_140d274e0(0x4f3d);
            if (pDlg != 0)
                pDlg->FUN_140e4cda0(spItem.get());
        }
    }
    else if (nMode == 4)
    {
        int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
        UIItemMergeOptionDialog* pDlg = FUN_14123a9b0(0x4e68);
        if (pDlg != 0)
            pDlg->FUN_1419d1490(nA, nB, nC);
    }
    else if (nMode == 5)
    {
        int nError = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        if (nError == 0)
        {
            __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
            MS2Ptr<CItem> spItem = FUN_1419be700(nItemUid);
            if (spItem.get() != 0)
            {
                spItem->FUN_140524eb0(packet);
                UIItemMergeOptionDialog* pDlg = FUN_14123a9b0(0x4e68);
                if (pDlg != 0)
                    pDlg->FUN_1419d1ad0(spItem);
                int bInInventory = DAT_143ab2a90.FUN_140a5d680(nItemUid).get() != 0;
                if (!bInInventory)
                {
                    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
                    if (pMyPC != 0)
                        pMyPC->FUN_1416561a0()->FUN_1411e7660();
                }
            }
        }
        else
        {
            UIItemMergeOptionDialog* pDlg = FUN_14123a9b0(0x4e68);
            if (pDlg != 0)
                pDlg->FUN_1419d1d20(nError);
        }
    }
}
MS2_REPLACE_METHOD(0x141729ce0, CSceneStateGame, OnItemFusion, 1232, 0xC6F49804);

// @0x14172a1c0
void CSceneStateGame::FUN_14172a1c0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0 || nMode == 1)
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        __int64 nCastUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        unsigned short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
        int nMotion = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int n94 = static_cast<CInputStream&>(packet).vfunc_o8_1();
        Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_11();
        int nSerial = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CString strBone = static_cast<CInputStream&>(packet).vfunc_o8_7();
        unsigned char nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
        Unk_InventorySkillRequest kReq(nSkillId, nLevel);
        kReq.serial = nSerial;
        kReq.tick = nCastUid;
        kReq.unknown14 = nMotion;
        kReq.origin = kPos;
        MS2Ptr<Unk_PCBaseComp_b18> spSkill(new Unk_PCBaseComp_b18());
        if (!spSkill->FUN_1417595d0(kReq))
            return;
        spSkill->m_n94 = n94;
        FUN_1403ed2d0()->FUN_141bc9020(strName, spSkill, strBone, nFlag);
    }
    if (nMode == 2)
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        CString strModel = static_cast<CInputStream&>(packet).vfunc_o8_7();
        unsigned char nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
        FUN_1403ed2d0()->FUN_141bc9560(strName, strModel, nFlag);
    }
}
MS2_REPLACE_METHOD(0x14172a1c0, CSceneStateGame, FUN_14172a1c0, 1501, 0x7E67768A);

// @0x14172a7b0
void CSceneStateGame::FUN_14172a7b0(CInPacket& packet)
{
    CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
    FUN_1403ed2d0()->FUN_141bc92e0(strName);
}
MS2_REPLACE_METHOD(0x14172a7b0, CSceneStateGame, FUN_14172a7b0, 140, 0x6F42AED7);

// @0x14172a850
void CSceneStateGame::FUN_14172a850(CInPacket& packet)
{
    CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
    FUN_1403ed2d0()->FUN_141bc9480(strName);
}
MS2_REPLACE_METHOD(0x14172a850, CSceneStateGame, FUN_14172a850, 140, 0xE3DF6E2B);

// NiTransform (rotation, translation, scale) for the sound call (same free-function placeholders as uimessagebox.cpp).
struct Unk_SSGPt3 { float x, y, z; };
struct Unk_SSGNiPt3
{
    Unk_SSGNiPt3(const NiPoint3& src);                      // 0x14027dcf0 NiPoint3 from efd::Point3
    Unk_SSGNiPt3(const Unk_StreamPoint& src);               // 0x14027dcf0 (the same ctor)
    Unk_SSGNiPt3(const efd::Point3& src);                   // 0x14027dcf0 (the same ctor)
    float x, y, z;
};
struct Unk_SSGRot { float m[3][3]; };
struct Unk_SSGXform
{
    Unk_SSGRot m_rotate;                                    // +0x00
    Unk_SSGPt3 m_translate;                                 // +0x24
    float m_fScale;                                         // +0x30
    void FUN_141d2fab0();                                   // NiTransform::MakeIdentity
};
MS2_CHECK_SIZE(Unk_SSGXform, 0x34);
void FUN_140a332d0(Unk_SSGXform* p);                        // NiTransform default ctor
void FUN_14097faa0(Unk_SSGPt3* pDst, const Unk_SSGNiPt3& src);   // NiPoint3::operator=
void FUN_140a33240(Unk_SSGRot* pDst, const Unk_EfdMatrix3* pSrc);   // NiMatrix3 from efd::Matrix3
extern Unk_EfdMatrix3 DAT_143a09600;                        // identity rotation

// ---- 0x63: interact objects of the field (create / update / remove, use results) --------------------------------
MS2Ptr<CInteractObjectData> FUN_14051f670(int nId);          // the interact table row
EntityWorldManager* FUN_1409670f0();
CString FUN_1409a2360(const char* psz, int nFlag);           // a copy of the string
void FUN_140de0cb0(efd::AssetID* pAsset, const efd::utf8string& strUrn);   // set an asset id from its urn
#ifdef __clang__
CString FUN_140298360(const char* pszLeft, const CString& strRight);   // ATL::operator+(const char*, const CString&)
#endif
extern ATL::CAtlArray<int> DAT_143ab3128;                    // templates whose first use was announced
int FUN_1402bacf0(ATL::CAtlArray<int>& arr, const int& n);  // index of n (-1 if absent)
extern CString DAT_143ae79e0;                                // the first use sound event
void FUN_141275460(int nStringId, int nA, int nB, const fmt::ArgList& args);
// fmt center notices with one / two arguments (the same template as actionkeyobject.cpp's).
template <class A> void Unk_AkoMessage(int nStringId, int nA, int nB, const A& x)
{
    const fmt::internal::ArgArray<1>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(x)};
    FUN_141275460(nStringId, nA, nB, fmt::ArgList(fmt::internal::make_type(x), values));
}
template <class A, class B> void Unk_AkoMessage(int nStringId, int nA, int nB, const A& x, const B& y)
{
    const fmt::internal::ArgArray<2>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(x),
        fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(y)};
    FUN_141275460(nStringId, nA, nB, fmt::ArgList(fmt::internal::make_type(x, y), values));
}

// 0x97: item enchant (UIItemEnchantDialog 0x4e92).
class CEnchantOption : public CPtred                         // the enchant result options (0x68)
{
public:
    CEnchantOption() : m_18(0) {}                           // 0x141745c40
    void FUN_14058d5c0(CInPacket& packet);                  // decode
    void* m_18;
    Unk_EnchantMap m_options;                               // +0x20
};
MS2_CHECK_SIZE(CEnchantOption, 0x68);
class UIItemEnchantDialog : public UIDialog
{
public:
    void FUN_1419c1f20(CInPacket& packet);
    void FUN_1419c2e30(CItem* pItem, int nPrevLevel, CInPacket& packet);
    void FUN_1419c3390(CItem* pItem, CEnchantOption* pOption, int nPrevLevel);
    void FUN_1419c37f0(unsigned __int64 nItemUid, CInPacket& packet);   // re-read the item
    void FUN_1419c3950(CInPacket& packet);
    void FUN_1419c3b90(CInPacket& packet);
    void FUN_1419c3e70(CInPacket& packet);
    void FUN_1419c3fd0();                                   // request the exp refund list again
    void FUN_1419c41b0();
};
UIItemEnchantDialog* FUN_1413b1bc0(int nId);
class Unk_ItemEnchantData { public: CItemEnchantInfo* FUN_140630d60(); };   // CItemStatus
void FUN_140d73ff0(CStringW strKey);                        // system message box by string key
enum Unk_SSGEnchantExpError { };                            // the 0x97 mode 12 error code

// @0x141732b20
void CSceneStateGame::OnItemEnchant(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 5)
    {
        UIItemEnchantDialog* pDlg = FUN_1413b1bc0(0x4e92);
        if (pDlg != 0)
            pDlg->FUN_1419c1f20(packet);
    }
    else if (nMode == 10)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        MS2Ptr<CItem> spItem = FUN_1419be700(nItemUid);
        if (spItem.get() != 0)
        {
            int nPrevLevel = spItem->FUN_1405278a0()->FUN_140630d60()->GetLevel();
            UIItemEnchantDialog* pDlg = FUN_1413b1bc0(0x4e92);
            if (pDlg != 0)
            {
                pDlg->FUN_1419c37f0(nItemUid, packet);
                MS2Ptr<CEnchantOption> spOption(new CEnchantOption);
                spOption->FUN_14058d5c0(packet);
                pDlg->FUN_1419c3390(spItem.get(), spOption.get(), nPrevLevel);
            }
        }
    }
    else if (nMode == 15)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        MS2Ptr<CItem> spItem = FUN_1419be700(nItemUid);
        if (spItem.get() != 0)
        {
            spItem->FUN_140524eb0(packet);
            Unk_SSGDlgInv* pInv = FUN_1405344f0(0x4e2d);
            if (pInv != 0)
                pInv->FUN_141999e00();
        }
    }
    else if (nMode == 16)
    {
        UIItemEnchantDialog* pDlg = FUN_1413b1bc0(0x4e92);
        if (pDlg != 0)
            pDlg->FUN_1419c41b0();
    }
    else if (nMode == 11)
    {
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        MS2Ptr<CItem> spItem = FUN_1419be700(nItemUid);
        if (spItem.get() != 0)
        {
            int nPrevLevel = spItem->FUN_1405278a0()->FUN_140630d60()->GetLevel();
            UIItemEnchantDialog* pDlg = FUN_1413b1bc0(0x4e92);
            if (pDlg != 0)
            {
                pDlg->FUN_1419c37f0(nItemUid, packet);
                pDlg->FUN_1419c2e30(spItem.get(), nPrevLevel, packet);
            }
        }
    }
    else if (nMode == 6)
    {
        UIItemEnchantDialog* pDlg = FUN_1413b1bc0(0x4e92);
        if (pDlg != 0)
            pDlg->FUN_1419c3950(packet);
    }
    else if (nMode == 7)
    {
        UIItemEnchantDialog* pDlg = FUN_1413b1bc0(0x4e92);
        if (pDlg != 0)
            pDlg->FUN_1419c3b90(packet);
    }
    else if (nMode == 8)
    {
        UIItemEnchantDialog* pDlg = FUN_1413b1bc0(0x4e92);
        if (pDlg != 0)
            pDlg->FUN_1419c3e70(packet);
    }
    else if (nMode == 9)
    {
        FUN_140d73ff0(L"s_itemenchant_enchant_exp_refund_ok");
        UIItemEnchantDialog* pDlg = FUN_1413b1bc0(0x4e92);
        if (pDlg != 0 && pDlg->FUN_141924630() != 0)
            pDlg->FUN_1419c3fd0();
    }
    else if (nMode == 12)
    {
        Unk_SSGEnchantExpError nError = (Unk_SSGEnchantExpError)(unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        switch (nError)
        {
        case 1:
            FUN_141275260(0x94d, 1, 1);
            break;
        case 2:
            FUN_141275260(0x94f, 1, 1);
            break;
        case 3:
            FUN_141275260(0x950, 1, 1);
            break;
        default:
            Unk_AkoMessage(0x94c, 1, 1, nError);
            break;
        }
    }
}
MS2_REPLACE_METHOD(0x141732B20, CSceneStateGame, OnItemEnchant, 1550, 0x20409A41);
// The effect play request (0x70 bytes; effectquery.h declares only its first 0x10).
struct Unk_SSGEffectReq
{
    Unk_SSGEffectReq();                                     // 0x140a52ef0
    ~Unk_SSGEffectReq();                                    // 0x1405a89e0
    void FUN_140a53190(int nOwnerId);                       // the owner object
    CString m_strName;                                      // +0x00
    int m_nType;                                            // +0x08
    int m_pad_0c;
    void* m_pad_10;
    Unk_SSGXform* m_pXform;                                 // +0x18
    void* m_pad_20[10];
};
MS2_CHECK_SIZE(Unk_SSGEffectReq, 0x70);
MS2_CHECK_OFFSET(Unk_SSGEffectReq, m_pXform, 0x18);

// The use result of an interact object (0x63 mode 13; 0 ok, 1.. the failure notices; formatted into notice 0x895).
enum Unk_SSGInteractResult { SSG_INTERACT_OK };

enum Unk_SSGInteractMode
{
    SSG_INTERACT_STATE = 4, SSG_INTERACT_MSG, SSG_INTERACT_KIND_STATE, SSG_INTERACT_ALL_STATE, SSG_INTERACT_STATES,
    SSG_INTERACT_ADD, SSG_INTERACT_REMOVE, SSG_INTERACT_11, SSG_INTERACT_12, SSG_INTERACT_RESULT, SSG_INTERACT_NOTICE,
    SSG_INTERACT_WEAPON
};

// @0x14172d0f0
void CSceneStateGame::OnInteractObject(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (static_cast<Unk_SSGInteractMode>(nMode))
    {
    case SSG_INTERACT_MSG:
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        unsigned char nKind = static_cast<CInputStream&>(packet).vfunc_o8_1();
        MS2Ptr<CInteractObject> spObj = FUN_1403ed2d0()->FUN_141bc66b0(strName);
        if (spObj.IsNull())
            break;
        if (spObj->vfunc_5() != nKind)
            break;
        // the stream of the packet is the message's (Unk_InteractMsg keeps it at +8 as CInPacket does)
        spObj->vfunc_2(reinterpret_cast<Unk_InteractMsg*>(&packet));
    }
    break;
    case SSG_INTERACT_RESULT:
    {
        Unk_SSGInteractResult nResult = static_cast<Unk_SSGInteractResult>(static_cast<CInputStream&>(packet).vfunc_o8_1());
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        unsigned char nKind = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nResult == 0)
        {
            MS2Ptr<CInteractObject> spObj = FUN_1403ed2d0()->FUN_141bc66b0(strName);
            if (spObj.IsNull())
                return;
            if (spObj->vfunc_5() != nKind)
                return;
            spObj->vfunc_12();
            int nNotice = spObj->GetRow()->m_nCollection;
            if (nNotice != 0)
            {
                int nTemplate = spObj->GetRowId();
                if (FUN_1402bacf0(DAT_143ab3128, nTemplate) == -1)
                {
                    DAT_143ab3128.Add(spObj->GetRowId());
                    if (spObj->vfunc_5() == 2)
                    {
                        if (Unk_SSGDlg4e29* pDlg = FUN_140c9b540(0x4e29))
                            pDlg->FUN_141a3a890();
                        FUN_141275260(0x897, 3, 1);
                        FUN_141276180(DAT_143ae79e0, "");
                    }
                }
            }
        }
        else if (nResult == 1)
        {
            Unk_AkoMessage(0x895, 1, 1, nResult);
        }
        else if (nResult == 12)
        {
        }
        else if (nResult == 4)
        {
            MS2Ptr<CInteractObject> spObj = FUN_1403ed2d0()->FUN_141bc66b0(strName);
            if (spObj.IsNull())
                return;
            if (spObj->GetRow().IsNull())
                return;
            Unk_AkoMessage(0x7c9, 1, 1, FUN_1401a9d70()->FUN_141811980(1, spObj->GetRow()->m_item.m_nCode));
        }
        else if (nResult == 13)
        {
            MS2Ptr<CInteractObject> spObj = FUN_1403ed2d0()->FUN_141bc66b0(strName);
            if (spObj.IsNull())
                return;
            MS2Ptr<CInteractObjectData> spData = spObj->GetRow();
            if (spData.IsNull())
                return;
            CStringW strMastery = FUN_1409670c0()->FUN_14066bdd0(spData->m_mastery.m_eType);
            CStringW strGrade = FUN_1409670c0()->FUN_14066c690(spData->m_mastery.m_eType, spData->m_mastery.m_nValue);
            Unk_AkoMessage(0x896, 1, 1, strMastery, strGrade);
        }
        else
        {
            int nStringId = 0;
            switch (nResult)
            {
            case 7: nStringId = 0x891; break;
            case 2: nStringId = 0x892; break;
            case 3: nStringId = 0x893; break;
            case 5: nStringId = 0x894; break;
            case 6: return;
            default: return;
            }
            FUN_141275260(nStringId, 1, 1);
        }
    }
    break;
    case SSG_INTERACT_ADD:
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
        unsigned char nKind = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nRowId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        Unk_StreamPoint ptPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
        Unk_StreamPoint ptRot = static_cast<CInputStream&>(packet).vfunc_o8_10();
        CString strModel = static_cast<CInputStream&>(packet).vfunc_o8_6();
        CString strAnim = static_cast<CInputStream&>(packet).vfunc_o8_6();
        CString strAssetA = static_cast<CInputStream&>(packet).vfunc_o8_6();
        CString strAssetB = static_cast<CInputStream&>(packet).vfunc_o8_6();
        float fScale = static_cast<CInputStream&>(packet).vfunc_o8_5();
        bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_0();
        efd::utf8string strUrnA(FUN_1409a2360(strAssetA, 0));
        efd::utf8string strUrnB(FUN_1409a2360(strAssetB, 0));
        MS2Ptr<CInteractObjectData> spData = FUN_14051f670(nRowId);
        if (spData.get() != 0)
        {
            MS2Ptr<CInteractObject> spObj(0);
            if (spData->FUN_1417486f0() || spData->FUN_1417486c0())
            {
                efd::SmartPointer<egf::Entity> spEntity(0);
                if (strModel == "MS2InteractMesh")
                {
                    egf::EntityID id = egf::EntityIDFactory::GetNextID();
                    spEntity = FUN_1409670f0()->FactoryEntity("MS2InteractMesh", id, true);
                    if (spEntity != 0)
                    {
                        efd::AssetID assetA;
                        efd::AssetID assetB;
                        if (strUrnA.length() != 0 && strUrnB.length() != 0)
                        {
                            strUrnA = static_cast<const char*>(FUN_1409a2360("urn:gamebryo-scenegraph:", 0)) + strUrnA;
                            strUrnB = static_cast<const char*>(FUN_1409a2360("urn:gamebryo-scenegraph:", 0)) + strUrnB;
                            FUN_140de0cb0(&assetA, strUrnA);
                            FUN_140de0cb0(&assetB, strUrnB);
                            spEntity->SetPropertyValue(0x770e5fc6, assetA);
                            spEntity->SetPropertyValue(0xae1cf70e, assetB);
                        }
                    }
                }
                else if (strModel == "MS2InteractActor")
                {
                    egf::EntityID id = egf::EntityIDFactory::GetNextID();
                    spEntity = FUN_1409670f0()->FactoryEntity("MS2InteractActor", id, true);
                    if (spEntity)
                    {
                        efd::AssetID asset;
                        if (!strAnim.IsEmpty())
                        {
#ifdef __clang__
                            // clang otherwise emits an unavailable CopyChars DLL import; bind the exe's operator+.
                            strAnim = FUN_140298360("urn:gamebryo-animation:", strAnim);
#else
                            strAnim = "urn:gamebryo-animation:" + strAnim;
#endif
                            FUN_140de0cb0(&asset, efd::utf8string(FUN_1409a2360(strAnim, 0)));
                            spEntity->SetPropertyValue(0x12383cea, asset);
                            spEntity->SetPropertyValue(0x3ff293c8, strUrnA);
                            spEntity->SetPropertyValue(0x63c7b14a, strUrnB);
                        }
                    }
                }
                if (spEntity)
                {
                    spEntity->SetPropertyValue(0xfd95ca52, reinterpret_cast<const efd::Point3&>(ptPos));
                    spEntity->SetPropertyValue(0x68c7c29d, reinterpret_cast<const efd::Point3&>(ptRot));
                    spEntity->SetPropertyValue(0xd460e9bc, nRowId);
                    spEntity->SetPropertyValue(0x2d7cad2d, fScale);
                    bool bFalse = false;
                    spEntity->SetPropertyValue(0x9004569a, bFalse);
                    if (bFlag)
                        spEntity->SetPropertyValue(0x2e0ec6f3, bFlag);
                    if (nKind == 1)
                    {
                        spObj.AssignRaw(new CInteractMeshObject());
                    }
                    else if (nKind == 8)
                    {
                        CInteractBillBoardObject* pBoard = new CInteractBillBoardObject();
                        pBoard->m_nBoard = static_cast<CInputStream&>(packet).vfunc_o8_4();
                        pBoard->m_strText = static_cast<CInputStream&>(packet).vfunc_o8_8();
                        spObj.AssignRaw(pBoard);
                    }
                    if (static_cast<bool>(spObj))
                    {
                        // Unk_Entity is the interact objects' opaque name of the egf entity
                        if (spObj->vfunc_1(reinterpret_cast<Unk_Entity*>(static_cast<egf::Entity*>(spEntity)), nState) != 0)
                        {
                            spObj->FUN_14174a4a0(strName);
                            spObj->FUN_14174a4d0();
                            FUN_1403ed2d0()->FUN_141bc5c40(spObj);
                        }
                    }
                    FUN_1409670f0()->FUN_1411cf2d0(spEntity, 0);
                }
                if (Unk_SSGDlg4e29* pDlg = FUN_140c9b540(0x4e29))
                    pDlg->FUN_141a39770(spObj);
            }
        }
    }
    break;
    case SSG_INTERACT_REMOVE:
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        CString strEffect = static_cast<CInputStream&>(packet).vfunc_o8_6();
        MS2Ptr<CInteractObject> spObj = FUN_1403ed2d0()->FUN_141bc66b0(strName);
        if (spObj.IsNull())
            return;
        if (strEffect.GetLength() != 0)
        {
            Unk_SSGXform xf;
            FUN_140a332d0(&xf);
            xf.FUN_141d2fab0();
            Unk_SSGNiPt3 pos(spObj->GetPos());
            FUN_14097faa0(&xf.m_translate, pos);
            Unk_SSGEffectReq req;
            req.m_strName = strEffect;
            req.m_nType = 0;
            req.m_pXform = &xf;
            FUN_1403ed280()->FUN_1411a4a00(req);
        }
        FUN_1403ed2d0()->FUN_141bc5d60(strName);
        if (Unk_SSGDlg4e29* pDlg = FUN_140c9b540(0x4e29))
            pDlg->FUN_141a39bf0(spObj);
    }
    break;
    case SSG_INTERACT_STATE:
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_1();
        FUN_1403ed2d0()->FUN_141bc6860(strName, nState, nB);
    }
    break;
    case SSG_INTERACT_STATES:
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (int i = 0; i < nCount; i++)
        {
            CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
            int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_1();
            int nC = 0;
            if (nB == 6)
                nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
            FUN_1403ed2d0()->FUN_141bc6760(strName, nState, nB, nC);
        }
    }
    break;
    case SSG_INTERACT_KIND_STATE:
    {
        int nKind = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
        FUN_1403ed2d0()->FUN_141bc6930(nKind, nState);
    }
    break;
    case SSG_INTERACT_ALL_STATE:
    {
        int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
        FUN_1403ed2d0()->FUN_141bc6a20(nState);
    }
    break;
    case SSG_INTERACT_NOTICE:
    {
        int nChannel = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        int nMapId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nNameId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CStringW strArg = static_cast<CInputStream&>(packet).vfunc_o8_8();
        CStringW strMsg = StringFormat(FUN_1401a9d70()->FUN_141811980(0x2b, nNameId), strArg);
        if (DAT_1439f4a7c == nChannel && nMapId == FUN_1403ed2d0()->FUN_141bd3060())
            FUN_1412751f0(strMsg, 10, 1);
        else
            FUN_1412751b0(strMsg, 0x14);
    }
    break;
    case SSG_INTERACT_WEAPON:
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int n = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            return;
        pPC->FUN_14165f1f0(n, 1);
    }
    break;
    }
}
MS2_REPLACE_METHOD(0x14172d0f0, CSceneStateGame, OnInteractObject, 7933, 0xF4607904);

// @0x141731610
void CSceneStateGame::FUN_141731610(CInPacket& packet)
{
    CAtlArray<unsigned int> arrIds;
    FUN_1403d7440(packet, arrIds);
    if (arrIds.IsEmpty())
        return;
    for (unsigned int i = 0; i < arrIds.GetCount(); i++)
        DAT_143ab3058.FUN_1401855a0(arrIds[i]);
}
MS2_REPLACE_METHOD(0x141731610, CSceneStateGame, FUN_141731610, 181, 0x2EBB1C24);

// @0x141731b20
void CSceneStateGame::FUN_141731b20(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 7:
    {
        int nResult = static_cast<CInputStream&>(packet).vfunc_o8_3();
        switch (nResult)
        {
        case 1:
            DAT_143ab284b = 1;
            FUN_140714f90()->FUN_1415388a0();
            FUN_140aa6d30()->FUN_1417e25a0(0x6200009);
            FUN_140d73bc0(0x27, 0, 0, DAT_143ae79f0);
            break;
        }
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x141731b20, CSceneStateGame, FUN_141731b20, 226, 0x7BCCAB8F);

// @0x141736880
void CSceneStateGame::FUN_141736880(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    bool bFlag = FUN_14028d780(static_cast<CInputStream&>(packet).vfunc_o8_1());
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    if (bFlag)
        pPC->FUN_141661ba0(1);
    pPC->vfunc_137();
}
MS2_REPLACE_METHOD(0x141736880, CSceneStateGame, FUN_141736880, 178, 0x4A0A130E);

// @0x141738290
void CSceneStateGame::FUN_141738290(CInPacket& packet)
{
    __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141662850(nValue);
    DAT_143ab2d80.FUN_140de2a00();
    FUN_1403ed2b0()->FUN_141adc530(0x4e47);
    Unk_SSGDlg4e47* pDlg = FUN_140de48d0(0x4e47);
    if (pDlg != 0)
        pDlg->FUN_141b10ba0(1);
    Unk_SSGDlg4ed8* pDlg2 = FUN_140bbea00(0x4ed8);
    if (pDlg2 != 0)
        pDlg2->FUN_1412c5330(*FUN_1401d3200()->m_66d0.FUN_1401d7c10());
}
MS2_REPLACE_METHOD(0x141738290, CSceneStateGame, FUN_141738290, 226, 0xEA7CE9F9);

// @0x141738380
void CSceneStateGame::FUN_141738380(CInPacket& packet)
{
    __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141662890(nValue);
    Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
    if (pDlg != 0)
        pDlg->FUN_1412c54e0(*FUN_1401d3200()->m_67e0.FUN_1401d7c10());
}
MS2_REPLACE_METHOD(0x141738380, CSceneStateGame, FUN_141738380, 155, 0xA0FA9FF3);

// @0x14173a370
void CSceneStateGame::OnLocalCamera(CInPacket& packet)
{
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
    bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_0();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (FUN_1409478c0() != 0)
        FUN_1409478c0()->FUN_140aecbb0(nA, nB, bFlag);
}
MS2_REPLACE_METHOD(0x14173a370, CSceneStateGame, OnLocalCamera, 170, 0x0E98F324);

// @0x14173a990
void CSceneStateGame::OnHomeInvite(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 2:
        FUN_14173aa10(packet);
        break;
    case 0:
        FUN_14173ad60(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14173a990, CSceneStateGame, OnHomeInvite, 116, 0x91EABDAC);

// Guild/party invite request (mode 2): ask the player unless invites are blocked in the options (then answer 5).
class Unk_SSGGameOpt { public: bool m_b0, m_b1, m_b2, m_b3, m_b4, m_b5, m_b6, m_b7, m_b8; bool m_bBlockInvite; };   // +9
class Unk_SSGCfg { public: Unk_SSGGameOpt* FUN_140ae6540(); class Unk_SSGAdvCfg* FUN_140b123b0(); class Unk_SSGHouseCfg* FUN_140a46860(); };
Unk_SSGCfg* FUN_1409a8b10();

// @0x14173aa10
void CSceneStateGame::FUN_14173aa10(CInPacket& packet)
{
    __int64 nUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    if (FUN_1409a8b10()->FUN_140ae6540()->m_bBlockInvite)
        FUN_141740200(strName, 5);
    else
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14052bd00(0x87f, strName), 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01ca0(0x14, 1, FUN_14028de60(0x2b8));
            spBox->FUN_141a02460(1);
            spBox->FUN_141a02480(1);
            spBox->FUN_141a024a0(0);
            spBox->FUN_1405340b0(nUid);
            spBox->FUN_140b76940(strName);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CSceneStateGame::FUN_141740280));
            FUN_140d73c60(spBox);
        }
    }
}
MS2_REPLACE_METHOD(0x14173AA10, CSceneStateGame, FUN_14173aa10, 839, 0x1C632D3A);

// @0x14173ad60
void CSceneStateGame::FUN_14173ad60(CInPacket& packet)
{
    int nResult = static_cast<CInputStream&>(packet).vfunc_o8_1();
    CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    switch (nResult)
    {
    case 1:
        FUN_1412751f0(FUN_14052bd00(0x880, strName), 1, 1);
        break;
    case 2:
        FUN_1412751f0(FUN_14052bd00(0x881, strName), 1, 1);
        break;
    case 3:
        FUN_141275260(0x882, 1, 1);
        break;
    case 4:
        FUN_1412751f0(FUN_14052bd00(0x883, strName), 1, 1);
        break;
    case 5:
        FUN_1412751f0(FUN_14052bd00(0x884, strName), 1, 1);
        break;
    case 6:
        FUN_1412751f0(FUN_14052bd00(0x885, strName), 1, 1);
        break;
    case 7:
        {
            FUN_141275260(0x886, 1, 1);
            break;
        }
        break;
    case 9:
        FUN_1412751f0(FUN_14052bd00(0x887, strName), 1, 1);
        break;
    }
}
MS2_REPLACE_METHOD(0x14173ad60, CSceneStateGame, FUN_14173ad60, 740, 0x9F113A47);

// @0x14173b380
void CSceneStateGame::FUN_14173b380(CInPacket& packet)
{
    CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
    FUN_1403ed2b0()->FUN_141ad9a60(strName);
}
MS2_REPLACE_METHOD(0x14173b380, CSceneStateGame, FUN_14173b380, 140, 0x9A5D042E);

// @0x14173c7a0
void CSceneStateGame::FUN_14173c7a0(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 1)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC != 0)
            pPC->FUN_141660000(nValue);
    }
}
MS2_REPLACE_METHOD(0x14173c7a0, CSceneStateGame, FUN_14173c7a0, 189, 0x0673F946);

// 0x118: result notices (mode 2: sub 0..2, mode 3: sub 0/3).
// @0x14173c870
void CSceneStateGame::OnReactor(CInPacket& packet)
{
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    if (pWorld == 0)
    {
        MS2_ASSERT_AT(0x2adc, 0);
        return;
    }
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
    {
        efd::SmartPointer<CReactor> spReactor = new (efd::MemHint(efd::MemHint::NONE)) CReactor;
        if (!spReactor)
        {
            MS2_ASSERT_AT(0x2ae8, 0);
            return;
        }
        if (!spReactor->FUN_140b79490(&packet))
            return;
        if (pWorld->FUN_141bbb1e0(spReactor, 0, 1) == 0)
            return;     // (the add failure and success paths are separate returns in the exe)
        return;
    }
    case 1:
    {
        int nMapId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        pWorld->FUN_141bbbcf0(nMapId, 0);
        break;
    }
    case 3:
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        GameObject* pObj = pWorld->FUN_141bd1180(nId);
        if (pObj == 0)
            return;
        efd::SmartPointer<CReactor> spReactor = efd::DynamicCast<CReactor>(pObj);
        if (!spReactor)
            return;
        spReactor->FUN_140b79a10(&packet);
        return;
    }
    case 4:
    {
        Unk_SSGChatDialog* pChat = FUN_140938cd0(0x4e5d);
        if (pChat == 0)
            return;
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (int i = 0; i < nCount; i++)
        {
            int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nAmount = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
            pChat->FUN_141abf6e0(nItemId, nAmount);
        }
        break;
    }
    case 5:
    {
        int nReactorId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MyPC* pPC = pWorld->FUN_141bd0cc0();
        if (pPC == 0)
        {
            MS2_ASSERT_AT(0x2b1e, 0);
            return;
        }
        MS2Ptr<StateReactData> spData(new StateReactData(nReactorId, "", ""));
        pPC->vfunc_59(0x3d, spData, 0x9e, 1);
    }
    }
}
MS2_REPLACE_METHOD(0x14173c870, CSceneStateGame, OnReactor, 1452, 0xA52CF4B9);

// @0x14173ce30
void CSceneStateGame::FUN_14173ce30(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 2)
    {
        unsigned char nResult = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nResult == 0)
        {
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            FUN_1412751f0(FUN_140811740(0xd1d, nA, nB), 1, 1);
        }
        if (nResult == 1)
            FUN_1412751f0(FUN_1409eec40(0xd1f), 1, 1);
        if (nResult == 2)
            FUN_1412751f0(FUN_1409eec40(0xd20), 1, 1);
    }
    if (nMode == 3)
    {
        unsigned char nResult = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nResult == 0)
        {
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            FUN_1412751f0(FUN_140811740(0xd1e, nA, nB), 1, 1);
        }
        if (nResult == 3)
            FUN_1412751f0(FUN_1409eec40(0xd21), 1, 1);
    }
}
MS2_REPLACE_METHOD(0x14173CE30, CSceneStateGame, FUN_14173ce30, 842, 0x499679E3);

// @0x14173de10
void CSceneStateGame::FUN_14173de10(CInPacket& packet)
{
    __int64 nUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    Unk_NiPoint3 kPos(static_cast<CInputStream&>(packet).vfunc_o8_10());
    Unk_SSGDlg4e29* pDlg = FUN_140c9b540(0x4e29);
    if (pDlg != 0)
        pDlg->FUN_141a3b130(nUid, nType, kPos);
}
MS2_REPLACE_METHOD(0x14173de10, CSceneStateGame, FUN_14173de10, 217, 0x968A66BC);

// @0x14173def0
void CSceneStateGame::FUN_14173def0(CInPacket& packet)
{
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    CStringW strText = static_cast<CInputStream&>(packet).vfunc_o8_8();
    if (FUN_140166440() != 0)
        FUN_140166440()->FUN_1401859c0(nType, nValue, strText);
}
MS2_REPLACE_METHOD(0x14173def0, CSceneStateGame, FUN_14173def0, 215, 0x136244C6);

// @0x14173e510
void CSceneStateGame::FUN_14173e510(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode != 4)
        return;
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGChatDialog* pDlg = FUN_140938cd0(0x4e5d);
    if (pDlg != 0)
        pDlg->FUN_141ac1d10(nValue);
}
MS2_REPLACE_METHOD(0x14173e510, CSceneStateGame, FUN_14173e510, 144, 0xC2688D81);

// @0x14173f0c0
void CSceneStateGame::FUN_14173f0c0(CInPacket& packet)
{
    Unk_SSGMessengerBrowser* pDlg = FUN_140a3ab70(0x4e61);
    if (pDlg == 0)
        return;
    pDlg->FUN_141a265d0();
    unsigned int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (unsigned int i = 0; i < nCount; i++)
    {
        const unsigned int& nId = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        pDlg->FUN_141a26560(nId);
    }
    pDlg->FUN_141a26600();
}
MS2_REPLACE_METHOD(0x14173f0c0, CSceneStateGame, FUN_14173f0c0, 205, 0x3BC94772);

// @0x14173f1a0
void CSceneStateGame::OnLimitBreak(CInPacket& packet)
{
    UIUnlimitedEnchantDialog* pDlg = Unk_SSGGetDialog<UIUnlimitedEnchantDialog>(0x4f97);
    if (pDlg == 0)
        return;
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        pDlg->FUN_140fb6310(packet);
        break;
    case 1:
        pDlg->FUN_140fb6b00(packet);
        break;
    case 2:
    {
        int nValue = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        pDlg->FUN_140fb6c30(nValue);
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x14173f1a0, CSceneStateGame, OnLimitBreak, 206, 0xE5A97C8E);

// @0x14173f280
// MS2-FUNCTIONAL: the exe places the smart pointer below the vtable spill temps (stack slot order); same calls and control flow
void CSceneStateGame::FUN_14173f280(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
            if (pPC == 0)
                return;
            MS2Ptr<Unk_PCWaterGunInfo> spInfo = pPC->FUN_141664250();
            if (spInfo.get() != 0)
                spInfo->FUN_1408fdfe0(packet);
            return;
        }
        break;
    case 1:
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            MyPC* pMyPC = dynamic_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd1290(nId));
            if (pMyPC == 0)
                return;
            pMyPC->FUN_141523bc0()->FUN_141767f80(nSkillId);
            pMyPC->FUN_141523bc0()->FUN_1417683d0();
        }
        break;
    case 2:
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            MyPC* pMyPC = dynamic_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd1290(nId));
            if (pMyPC == 0)
                return;
            pMyPC->FUN_141523bc0()->FUN_141768100(nSkillId);
            pMyPC->FUN_141523bc0()->FUN_1417683d0();
        }
        break;
    }
}
MS2_REPLACE_METHOD(0x14173f280, CSceneStateGame, FUN_14173f280, 700, 0xAB64CE43);

// @0x14173fe20
int CSceneStateGame::FUN_14173fe20()
{
    if (FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0) && FUN_14025e7c0()->FUN_14116d950(0x38, true, 0)
        && FUN_14025e7c0()->FUN_14116d9c0(0x43, true, 0))
    {
        FUN_14173feb0();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14173fe20, CSceneStateGame, FUN_14173fe20, 126, 0x98F76DA5);

// The debug key action: toggle the whole UI (m_b18) for screenshots.
// @0x14173feb0
void CSceneStateGame::FUN_14173feb0()
{
    int nScene = FUN_1422b9e00(FUN_1408e57f0());
    if (m_b18)
    {
        Unk_SSGUIMgr* pUI = FUN_1403ed2b0();
        if (pUI != 0)
        {
            pUI->FUN_141adad20(nScene);
            pUI->FUN_141ada610(nScene);
            pUI->FUN_141adb2a0(nScene);
            pUI->FUN_141ad9b30();
        }
        UISwfEntity* pHud = FUN_1408e57f0()->FUN_1422b9e80();
        if (pHud != 0)
            pHud->FUN_1422dc080();
        UISwfEntity* pScene = FUN_1422b9e50(FUN_1408e57f0());
        if (pScene != 0)
            pScene->FUN_1422dc080();
        efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService)
            spService->FUN_1410bc320();
        FUN_1403ed2d0()->FUN_141bdb7a0();
        FUN_140b632f0()->FUN_1422d4b70(true);
        FUN_1403ed2b0()->FUN_141ad9c10();
    }
    else
    {
        FUN_140b632f0()->FUN_1422d4b70(false);
        UISwfEntity* pHud = FUN_1408e57f0()->FUN_1422b9e80();
        if (pHud != 0)
            pHud->FUN_1422dbf80(pHud->FUN_1422db790(), pHud->FUN_1422db750(), 0, 0);
        UISwfEntity* pScene = FUN_1422b9e50(FUN_1408e57f0());
        if (pScene != 0)
            pScene->FUN_1422dbf80(pScene->FUN_1422db790(), pScene->FUN_1422db750(), 0, 0);
        Unk_SSGUIMgr* pUI = FUN_1403ed2b0();
        if (pUI != 0)
        {
            pUI->FUN_141ada6f0(nScene);
            pUI->FUN_141ad9e50(nScene);
            pUI->FUN_141adafd0(nScene);
            pUI->FUN_141ad9650();
            pUI->FUN_141ad9b60();
        }
        efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService)
            spService->FUN_1410bc1c0();
        FUN_1403ed2d0()->FUN_141bdb6a0();
    }
    m_b18 = !m_b18;
}
MS2_REPLACE_METHOD(0x14173FEB0, CSceneStateGame, FUN_14173feb0, 830, 0xE21C6DBD);

// @0x141740200
void CSceneStateGame::FUN_141740200(const CStringW& strName, int nType)
{
    COutPacket out(0x51, 0);
    out.COutPacket::vfunc_o10_1(0);
    out.COutPacket::vfunc_o10_8(strName);
    out.COutPacket::vfunc_o10_1(nType);
    FUN_140710590(out);
}
MS2_REPLACE_METHOD(0x141740200, CSceneStateGame, FUN_141740200, 118, 0x74A0A5D8);

// @0x14171b630
void CSceneStateGame::OnMeso(CInPacket& packet)
{
    __int64 nNew = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 nDelta = nNew - DAT_143ab2898;
    DAT_143ab2898 = nNew;
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (nDelta > 0)
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
            FUN_140e09140()->FUN_140a05550(pPC->FUN_141656a80(), nDelta);
        FUN_14109a6f0()->FUN_14117e4c0(nDelta);
    }
    FUN_1413612c0(nDelta, nValue);
    FUN_140aa6d40()->FUN_141b0ce20(8, 0);
    FUN_140764020()->FUN_1416ca2f0();
}
MS2_REPLACE_METHOD(0x14171b630, CSceneStateGame, OnMeso, 272, 0xCC9143A6);
// @0x14171b750
void CSceneStateGame::OnMeret(CInPacket& packet)
{
    __int64 a = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 b = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 c = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 d = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 nDelta = static_cast<CInputStream&>(packet).vfunc_o8_4();
    FUN_1409304d0(a, b, c, d);
    if (nDelta > 0)
    {
        FUN_141276180("Merat_Get", "");
        CStringW strMoney = FUN_1409404f0(nDelta);
        FUN_1412751b0(FUN_14052bd00(0x2c6, strMoney), 6);
        Unk_SSGChatDialog* pChat = FUN_140938cd0(0x4e5d);
        if (pChat != 0)
            pChat->FUN_141ac0860(nDelta);
    }
    else if (nDelta < 0)
    {
        FUN_141276180("Merat_Use", "");
        CStringW strMoney = FUN_1409404f0(-nDelta);
        FUN_1412751b0(FUN_14052bd00(0x2d8, strMoney), 6);
        if (FUN_140166410()->FUN_14036d570(0xba))
            FUN_1412751b0(FUN_1409eec40(0x2db), 6);
    }
    FUN_140aa6d40()->FUN_141b0ce20(0xb, static_cast<int>(nDelta));
}
MS2_REPLACE_METHOD(0x14171B750, CSceneStateGame, OnMeret, 883, 0x63E8AB8C);

// @0x14171bad0
void CSceneStateGame::FUN_14171bad0(CInPacket& packet)
{
    __int64 nTotal = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 nDelta = static_cast<CInputStream&>(packet).vfunc_o8_4();
    FUN_140930af0(nTotal);
    if (nDelta > 0)
    {
        {
            CString strArg("");
            CString strEvent("Merat_Get");
            FUN_141276180(strEvent, strArg);
        }
        CStringW strAmount = FUN_1409404f0(nDelta);
        FUN_1412751b0(FUN_14052bd00(0x2c8, strAmount), 6);
        Unk_SSGChatDialog* pDlg = FUN_140938cd0(0x4e5d);
        if (pDlg != 0)
            pDlg->FUN_141ac0990(nDelta);
    }
    else if (nDelta < 0)
    {
        {
            CString strArg("");
            CString strEvent("Merat_Use");
            FUN_141276180(strEvent, strArg);
        }
        CStringW strAmount = FUN_1409404f0(-nDelta);
        FUN_1412751b0(FUN_14052bd00(0x2da, strAmount), 6);
        if (FUN_140166410()->FUN_14036d570(0xba))
            FUN_1412751b0(FUN_1409eec40(0x2db), 6);
    }
    FUN_140aa6d40()->FUN_141b0ce20(0xd, (int)nDelta);
}
MS2_REPLACE_METHOD(0x14171bad0, CSceneStateGame, FUN_14171bad0, 697, 0x379D3D2D);

#ifdef __clang__
// Keep the exe token-money globals referenced in code, not in an absolute-address switch table.
#pragma clang optimize off
#endif
// @0x14171bd90
void CSceneStateGame::OnCurrencyToken(CInPacket& packet)
{
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 nDelta = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nX = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nShow = static_cast<CInputStream&>(packet).vfunc_o8_4();
    switch (static_cast<unsigned int>(nType))
    {
    case 3: DAT_143ab28b0 = nValue; break;
    case 4: DAT_143ab28b8 = nValue; break;
    case 5: DAT_143ab28c0 = nValue; break;
    case 6: DAT_143ab28c8 = nValue; break;
    case 9: DAT_143ab28d0 = nValue; break;
    case 10: DAT_143ab28d8 = nValue; break;
    case 11: DAT_143ab28e0 = nValue; break;
    case 12: DAT_143ab28e8 = nValue; break;
    case 13: DAT_143ab28f0 = nValue; break;
    }
    FUN_141361460(nType, nDelta, nX);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangedTokenMoney(nType, nValue, nDelta)));
    if (nShow != 0)
    {
        int nIndex = FUN_1403bb010(nType, 99);
        CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nIndex);
        Unk_SSGFormatMsg(0x2f6, 1, 1, strName, nShow);
    }
}
MS2_REPLACE_METHOD(0x14171bd90, CSceneStateGame, OnCurrencyToken, 740, 0xBC7B1ED3);
#ifdef __clang__
#pragma clang optimize on
#endif

// @0x14171e860
void CSceneStateGame::FUN_14171e860(CInPacket& packet)
{
    int nTargetId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < nCount; i++)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            continue;
        if (pPC->FUN_14166c930() == 0x2b)
        {
            Unk_SSGGrabState* pState = static_cast<Unk_SSGGrabState*>(pPC->FUN_14166ccb0());
            if (pState->FUN_141024a30(nTargetId))
                pPC->vfunc_59(1, 0, 0, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x14171e860, CSceneStateGame, FUN_14171e860, 308, 0x3B1A059E);

// @0x14171e9a0
void CSceneStateGame::FUN_14171e9a0(CInPacket& packet)
{
    unsigned long long nTagId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int bCreate = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (bCreate)
    {
        int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nLevel = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nCasterId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        Unk_MagicTagPtr spTag(new Unk_MagicTag());
        if (!spTag->FUN_141758d70(nTagId, 0, nOwnerId, nCasterId, nSkillId, nLevel, 0, Unk_StreamPoint(0, 0, 0), 0, 0,
                0, 0))
            return;
        PCBase* pOwner = FUN_1403ed2d0()->FUN_141bd1200(nOwnerId);
        int nTimeMode = FUN_1403ed2d0()->FUN_141bd1a10(pOwner);
        int nStartTick = Unk_ServerClock::GetInstance()->FUN_1414732f0(nTimeMode);
        spTag->m_nStartTick = nStartTick;
        Unk_SocketPtr<CMagicModel> spModel = FUN_1410a7630()->FUN_14146c5d0(nTagId, 0);
        if (spModel == 0)
        {
            spModel = new CMagicModel();
            spModel->FUN_141467500(spTag, Unk_MagicTagPtr(0), Unk_StreamPoint(0, 0, 0), 0, 1, 1);
        }
    }
    else
    {
        if (FUN_1410a7630() == 0)
            return;
        FUN_1410a7630()->FUN_14146c4b0(nTagId, 0);
    }
}
MS2_REPLACE_METHOD(0x14171e9a0, CSceneStateGame, FUN_14171e9a0, 1232, 0x81595E1A);

// A field object placed by the server (portal, field-entry object); RTTI CPortal, 0x1b8 bytes. Same layout as
// worldservice_1.cpp's Unk_WsE_FieldObject; only the fields set by packet 0x48 are named.
class CPortal : public CPtred
{
public:
    CPortal();                                              // 0x14169b350

    egf::EntityID m_entityId;                               // +0x18
    int m_nId;                                              // +0x20
    int m_nVisible;                                         // +0x24
    int m_nEnabled;                                         // +0x28
    Unk_StreamPoint m_kPos;                                 // +0x2c
    Unk_StreamPoint m_kScale;                               // +0x38
    Unk_StreamPoint m_kRot;                                 // +0x44
    char m_pad_50[0xf8];                                    // +0x50 placement
    int m_nMapType;                                         // +0x148
    int m_nTargetField;                                     // +0x14c
    int m_nTargetPortal;                                    // +0x150
    int m_nHidden;                                          // +0x154
    __int64 m_nOwnerId;                                     // +0x158
    int m_nType;                                            // +0x160
    int m_n164;                                             // +0x164
    char m_pad_168[8];
    int m_n170;                                             // +0x170
    char m_pad_174[4];
    CStringW m_strName;                                     // +0x178
    CString m_strModel;                                     // +0x180 scene graph urn
    int m_n188;                                             // +0x188
    bool m_bConfirm;                                        // +0x18c
    CStringW m_str190;                                      // +0x190
    CStringW m_str198;                                      // +0x198
    char m_pad_1a0[0x18];
};
MS2_CHECK_OFFSET(CPortal, m_nMapType, 0x148);
MS2_CHECK_OFFSET(CPortal, m_strName, 0x178);
MS2_CHECK_OFFSET(CPortal, m_str198, 0x198);
MS2_CHECK_SIZE(CPortal, 0x1b8);
template <> MS2Ptr<CPortal>::MS2Ptr(const MS2Ptr& o);                // 0x1409640d0
template <> MS2Ptr<CPortal>::~MS2Ptr();                              // 0x140964a70
template <> CPortal* MS2Ptr<CPortal>::operator->() const;            // 0x140965960
template <> CPortal* MS2Ptr<CPortal>::get() const;                   // 0x140c9b7d0

// Packet 0x48: field objects (add / remove / properties / placement).
// @0x14171ee80
void CSceneStateGame::OnFieldPortal(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (nMode == 0)
    {
        MS2Ptr<CPortal> spPortal = new CPortal;
        spPortal->m_nId = nId;
        int nVisible = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nEnabled = static_cast<CInputStream&>(packet).vfunc_o8_1();
        Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
        Unk_StreamPoint kScale = static_cast<CInputStream&>(packet).vfunc_o8_10();
        Unk_StreamPoint kRot = static_cast<CInputStream&>(packet).vfunc_o8_10();
        CString strModel = static_cast<CInputStream&>(packet).vfunc_o8_6();
        int nMapType = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nTargetField = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nTargetPortal = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nHidden = static_cast<CInputStream&>(packet).vfunc_o8_1();
        __int64 nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int n164 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int n188 = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        int n170 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        bool bConfirm = static_cast<CInputStream&>(packet).vfunc_o8_0();
        CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        CStringW str190 = static_cast<CInputStream&>(packet).vfunc_o8_8();
        CStringW str198 = static_cast<CInputStream&>(packet).vfunc_o8_8();
        spPortal->m_nVisible = nVisible;
        spPortal->m_nEnabled = nEnabled;
        spPortal->m_kPos = kPos;
        spPortal->m_kScale = kScale;
        spPortal->m_kRot = kRot;
        spPortal->m_nTargetField = nTargetField;
        spPortal->m_nTargetPortal = nTargetPortal;
        spPortal->m_nHidden = nHidden;
        spPortal->m_nOwnerId = nOwnerId;
        spPortal->m_nType = nType;
        spPortal->m_n164 = n164;
        spPortal->m_n188 = n188;
        spPortal->m_n170 = n170;
        spPortal->m_bConfirm = bConfirm;
        spPortal->m_strName = strName;
        spPortal->m_str190 = str190;
        spPortal->m_str198 = str198;
        if (!strModel.IsEmpty())
#ifdef __clang__
            // clang otherwise emits an unavailable CopyChars DLL import; bind the exe's operator+.
            spPortal->m_strModel = FUN_140298360("urn:gamebryo-scenegraph:", strModel);
#else
            spPortal->m_strModel = "urn:gamebryo-scenegraph:" + strModel;
#endif
        if (nMapType != 0)
            spPortal->m_nMapType = nMapType;
        FUN_1403ed2d0()->FUN_141bc1720(spPortal);
    }
    else if (nMode == 1)
    {
        FUN_1403ed2d0()->FUN_141bc24e0(nId);
    }
    else if (nMode == 2)
    {
        int nVisible = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nEnabled = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nHidden = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int n188 = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        MS2Ptr<CPortal> spPortal = FUN_1403ed2d0()->FUN_141bc2800(nId);
        if (spPortal.get() != 0)
            spPortal->m_n188 = n188;
        FUN_1403ed2d0()->FUN_141bc3140(nId, nVisible, nEnabled, nHidden);
    }
    else if (nMode == 3)
    {
        Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
        Unk_StreamPoint kScale = static_cast<CInputStream&>(packet).vfunc_o8_10();
        FUN_1403ed2d0()->FUN_141bc31d0(nId, kPos, kScale);
    }
}
MS2_REPLACE_METHOD(0x14171EE80, CSceneStateGame, OnFieldPortal, 2574, 0x7FDDB2DD);

// @0x141731350
void CSceneStateGame::FUN_141731350(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    CString strEffect = static_cast<CInputStream&>(packet).vfunc_o8_6();
    FUN_1403ed280()->FUN_1411a4f40(strEffect, pNpc->vfunc_18());
}
MS2_REPLACE_METHOD(0x141731350, CSceneStateGame, FUN_141731350, 268, 0xD3681616);

// @0x141733e40
void CSceneStateGame::OnNametag(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned short nA = static_cast<CInputStream&>(packet).vfunc_o8_2();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    pPC->FUN_141661dc0(nA, nB);
    FUN_141a60f00(pPC->FUN_14123c580());
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        Unk_SSGDlg2711* pDlg = FUN_140938c30(0x2711);
        if (pDlg != 0)
            pDlg->FUN_141a5a560();
    }
}
MS2_REPLACE_METHOD(0x141733e40, CSceneStateGame, OnNametag, 262, 0x20BDD114);

// @0x141738120
void CSceneStateGame::FUN_141738120(CInPacket& packet)
{
    bool bPos = static_cast<CInputStream&>(packet).vfunc_o8_0();
    if (bPos)
    {
        int nX = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nY = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_140cea070()->FUN_140dd86a0(nX, nY);
    }
    else
    {
        unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_0();
        if (nMode == 1)
            FUN_1403ed2b0()->FUN_141add1f0();
        else
            FUN_141275260(static_cast<CInputStream&>(packet).vfunc_o8_3(), 1, 1);
    }
}
MS2_REPLACE_METHOD(0x141738120, CSceneStateGame, FUN_141738120, 279, 0x1DD3407C);

// @0x14171a730
void CSceneStateGame::OnRevivalConfirm(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int bEffect = pPC->FUN_141661aa0() && nB == 0;
    pPC->FUN_141661a60(nB);
    pPC->FUN_1416619d0(nA);
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        if (bEffect)
        {
            Unk_EffectQuery query;
            query.m_strName = FUN_1401d31f0()->m_str358;
            query.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(pPC);
            query.SetActor(pPC->FUN_14123c580());
            FUN_1403ed280()->FUN_1411a4a00(&query);
        }
        else if (nB != 0)
        {
            FUN_1409331e0()->FUN_14138bf00(0xe, 0, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x14171a730, CSceneStateGame, OnRevivalConfirm, 452, 0xFA154A72);

// @0x14171a900
void CSceneStateGame::OnRevival(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor == 0)
        return;
    PC* pPC = FUN_140974230(pActor);
    if (pPC != 0)
        pPC->FUN_141661ba0(nFlag);
    pActor->FUN_14166ce50(0);
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pActor == pMyPC)
    {
        pMyPC->vfunc_59(0x18, 0, 0, 0);
        pMyPC->FUN_14152a960();
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e38);
        FUN_140a94350()->vfunc_10(8);
        FUN_1409331e0()->FUN_14138d7e0(0xb, 0);
    }
    if (pPC != 0)
        pPC->FUN_141661370(1, FUN_1401d3200()->m_2970.FUN_140ad5c50(), 100000004);
}
MS2_REPLACE_METHOD(0x14171a900, CSceneStateGame, OnRevival, 393, 0xEF236C66);

// ---- 0x49: a player's job / skill book update (modes 0..11) ----
class Unk_SSGSkillBook
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(unsigned short nLevel);
    virtual void vfunc_5(); virtual void vfunc_6();
    virtual void vfunc_7(CInPacket& packet);                // decode the skill book
    void FUN_140a6e240();
};
Unk_SSGSkillBook* FUN_1416546d0(PC* pPC);                  // the actor's skill book
class Unk_PCSkillTree : public CPtred { };
template <> Unk_PCSkillTree* MS2Ptr<Unk_PCSkillTree>::get() const;   // 0x1409ee2c0 (astooltip's COMDAT)
template <> MS2Ptr<Unk_PCSkillTree>::~MS2Ptr();                      // 0x1409ed920
void FUN_14080bb80(Unk_PCSkillTree* pTree);                         // reset the tree (skilltieroptionmanager)
void FUN_141654790(PC* pPC);                                        // refresh the actor's skills
int FUN_141654700(MyPC* pPC);                                       // job
enum Unk_SSGJobCode { };                                            // job code
Unk_SSGJobCode FUN_141654730(MyPC* pPC);                            // job code
class Unk_SSGJobTable { };
Unk_SSGJobTable* FUN_140bd8b60();
int FUN_1401d6ef0(Unk_SSGJobTable* pTable, int nJobCode);           // the job code is an awakened job
class Unk_SSGDlg4f2d { public: void FUN_140ec8220(); };
Unk_SSGDlg4f2d* FUN_1409eb120(int nId);                             // GetDialog<T>(0x4f2d)
class UIChangeJobEffect : public UIDialog { };
enum Unk_SSGJobError { };                                           // the 0x49 mode 3 error code
class NotifyChangeMyJob : public NotifyObject
{
public:
    NotifyChangeMyJob(MyPC* pMyPC) : m_pMyPC(pMyPC) {}
    virtual ~NotifyChangeMyJob() = default;
    virtual CStringW vfunc_1();                             // 0x140db4370
    MyPC* m_pMyPC;                                          // +0x18
};
MS2_CHECK_SIZE(NotifyChangeMyJob, 0x20);

// @0x14171f8a0
void CSceneStateGame::OnJob(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        FUN_1416546d0(pPC)->vfunc_7(packet);
        FUN_141654790(pPC);
        MyPC* pMyPC = FUN_1409613d0(pPC);
        if (pMyPC != 0)
        {
            FUN_140aa6d40()->FUN_141b0ce20(4, 0);
            Unk_SSGChatDialog* pDlg = FUN_140938cd0(0x4e5d);
            if (pDlg != 0)
                pDlg->FUN_141ac0210(pMyPC);
            FUN_140a94350()->vfunc_14(FUN_141654700(pMyPC));
        }
    }
    else if (nMode == 1 || nMode == 2)
    {
        FUN_1416546d0(pPC)->vfunc_7(packet);
        FUN_141654790(pPC);
        if (nMode == 2)
        {
            Unk_EffectQuery query;
            query.m_strName = FUN_1401d31f0()->m_str2c8;
            query.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(pPC);
            query.SetActor(pPC->FUN_14123c580());
            FUN_1403ed280()->FUN_1411a4a00(&query);
            FUN_14080bb80(pPC->FUN_1409eee00().get());
            MyPC* pMyPC = FUN_1409613d0(pPC);
            if (pMyPC != 0)
            {
                FUN_140aa6d40()->FUN_141b0ce20(4, 0);
                FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangeMyJob(pMyPC)));
                Unk_SSGChatDialog* pDlg = FUN_140938cd0(0x4e5d);
                if (pDlg != 0)
                    pDlg->FUN_141ac0210(pMyPC);
                if (FUN_140166410()->FUN_14036d570(0xca) == true)
                {
                    if (FUN_1401d6ef0(FUN_140bd8b60(), FUN_141654730(pMyPC)) != 0)
                    {
                        UIChangeJobEffect* pEffect = Unk_SSGGetDialog<UIChangeJobEffect>(0x4f6c);
                        if (pEffect != 0)
                            pEffect->vfunc_2();
                    }
                }
                FUN_140a94350()->vfunc_14(FUN_141654700(pMyPC));
            }
        }
    }
    else if (nMode == 7)
    {
        FUN_1416546d0(pPC)->vfunc_7(packet);
        MyPC* pMyPC = FUN_1409613d0(pPC);
        if (pMyPC != 0)
        {
            FUN_140aa6d40()->FUN_141b0ce20(4, 0);
            Unk_SSGChatDialog* pDlg = FUN_140938cd0(0x4e5d);
            if (pDlg != 0)
                pDlg->FUN_141ac0210(pMyPC);
        }
    }
    else if (nMode == 9 || nMode == 10 || nMode == 11)
    {
        FUN_1416546d0(pPC)->vfunc_7(packet);
        MyPC* pMyPC = FUN_1409613d0(pPC);
        if (pMyPC != 0)
        {
            Unk_SSGDlg4f2d* pTree = FUN_1409eb120(0x4f2d);
            if (pTree != 0)
                pTree->FUN_140ec8220();
            if (nMode == 9 || nMode == 11)
            {
                Unk_SSGChatDialog* pDlg = FUN_140938cd0(0x4e5d);
                if (pDlg != 0)
                    pDlg->FUN_141ac0210(pMyPC);
            }
        }
    }
    else if (nMode == 8)
    {
        FUN_1416546d0(pPC)->vfunc_7(packet);
    }
    else if (nMode == 3)
    {
        Unk_SSGJobError nError = (Unk_SSGJobError)static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError != 0)
        {
            CStringW strMsg;
            switch (nError)
            {
            case 9: strMsg = FUN_14028de60(0x76); break;
            case 10: strMsg = FUN_14028de60(0x77); break;
            case 2: strMsg = FUN_14028de60(0x78); break;
            case 12: strMsg = FUN_14028de60(0x79); break;
            case 11: strMsg = FUN_14028de60(0x7a); break;
            case 3:
            case 4: strMsg = FUN_14028de60(0x7b); break;
            case 5: strMsg = FUN_14028de60(0x7c); break;
            case 15: strMsg = FUN_14028de60(0x7d); break;
            case 8: strMsg = FUN_14028de60(0x7e); break;
            case 14: strMsg = FUN_14028de60(0x7f); break;
            case 18:
            {
                int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
                strMsg = FUN_1408116a0(0x80, nValue);
                FUN_140d73aa0(strMsg, 0, 0, CStringW(L""));
                break;
            }
            default: strMsg = FormatStringId(0x81, nError); break;
            }
            if (!strMsg.IsEmpty())
                FUN_1412751f0(strMsg, 1, 1);
        }
    }
    Unk_SSGDlg4e28* pMenu = FUN_140938b90(0x4e28);
    if (pMenu != 0 && pMenu->vfunc_55() == 0)
        pMenu->FUN_141937e00(nMode);
}
MS2_REPLACE_METHOD(0x14171f8a0, CSceneStateGame, OnJob, 2952, 0x3E6FD877);

// The owner header of a buff packet (?\additionalcli.cpp; same layout as Unk_AdditionalOwner).
struct Unk_SSGBuffOwner
{
    Unk_SSGBuffOwner();                                     // 0x1409755b0
    void Decode(CInPacket& packet);                         // 0x140175fe0
    int m_nObjId;                                           // the actor carrying the buff
    int m_nBuffId;
    int m_nLevel;
};
MS2_CHECK_SIZE(Unk_SSGBuffOwner, 0xc);
// A buff record (?\additionalcli.cpp, new(0x78)); only the members the buff handler uses.
class AdditionalCli : public CPtred
{
public:
    AdditionalCli();                                        // 0x14096bae0
    void FUN_14096be10(PCBase* pActor, Unk_SSGBuffOwner* pOwner, CInPacket& packet);   // read the buff
    void FUN_14096c3c0(CStringW strTag, int bMine);         // log the buff
    unsigned int FUN_14096d2a0();                           // data id
    unsigned short GetLevel();                         // data sub id
    int m_nCasterId;                                        // +0x18
    char m_pad_1c[0x78 - 0x1c];
};
MS2_CHECK_SIZE(AdditionalCli, 0x78);
template <> AdditionalCli* MS2Ptr<AdditionalCli>::operator->() const;   // out-of-unit COMDATs (0x14096e8b0, 0x140975b90)
template <> AdditionalCli* MS2Ptr<AdditionalCli>::get() const;
// The buff change notification (0x38, ctor 0x140db4720).
class NotifyChangeBuff : public NotifyObject
{
public:
    NotifyChangeBuff(unsigned int nId, unsigned short nSubId);
    char m_pad_18[0x20 - 0x18];
    int m_bAdded;                                           // +0x20
    MS2Ptr<AdditionalCli> m_spCli;                          // +0x28
};
MS2_CHECK_OFFSET(NotifyChangeBuff, m_spCli, 0x28);
MS2_CHECK_SIZE(NotifyChangeBuff, 0x38);

// 0x47 buffs: mode 0 add (owner header + buff data), mode 1 remove, mode 2 update. The local player's buffs refresh
// the buff dialog (0x2711) and post a NotifyChangeBuff.
// @0x141720480
void CSceneStateGame::OnBuff(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    Unk_SSGBuffOwner kOwner;
    kOwner.Decode(packet);
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(kOwner.m_nObjId);
    if (pActor == 0)
        return;
    if (nMode == 0)
    {
        MS2Ptr<AdditionalCli> spCli(new AdditionalCli());
        spCli->FUN_14096be10(pActor, &kOwner, packet);
        if (pActor->FUN_1416749a0()->FUN_14096f070(spCli) == 0)
            return;
        if (FUN_14096e160(pActor) != 0)
        {
            Unk_SSGDlg2711* pDlg = FUN_140938c30(0x2711);
            if (pDlg != 0)
                pDlg->FUN_141a5a560();
            if (spCli.get() != 0)
            {
                MS2Ptr<NotifyChangeBuff> spNotify(new NotifyChangeBuff(spCli->FUN_14096d2a0(), spCli->GetLevel()));
                spNotify->m_spCli = spCli;
                spNotify->m_bAdded = 1;
                FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(spNotify.get()));
            }
            spCli->FUN_14096c3c0(CStringW(L"[Add]"), 1);
        }
        else
        {
            MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pMyPC != 0)
            {
                if (pMyPC->FUN_14123c580() == spCli->m_nCasterId)
                    spCli->FUN_14096c3c0(CStringW(L"[Add]"), 0);
            }
        }
    }
    else if (nMode == 1)
    {
        MS2Ptr<AdditionalCli> spCli = pActor->FUN_1416749a0()->FUN_14096fc80(kOwner.m_nBuffId);
        pActor->FUN_1416749a0()->FUN_14096f500(kOwner.m_nBuffId, kOwner.m_nLevel);
        if (FUN_14096e160(pActor) != 0)
        {
            Unk_SSGDlg2711* pDlg = FUN_140938c30(0x2711);
            if (pDlg != 0)
                pDlg->FUN_141a5a560();
            if (spCli.get() != 0)
            {
                MS2Ptr<NotifyChangeBuff> spNotify(new NotifyChangeBuff(spCli->FUN_14096d2a0(), spCli->GetLevel()));
                spNotify->m_spCli = spCli;
                spNotify->m_bAdded = 0;
                FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(spNotify.get()));
            }
        }
    }
    else if (nMode == 2)
    {
        MS2Ptr<AdditionalCli> spCli = pActor->FUN_1416749a0()->FUN_14096f820(&kOwner, packet);
        if (spCli == 0)
            return;
        bool bMine = FUN_14096e160(pActor) != 0;
        if (bMine)
        {
            Unk_SSGDlg2711* pDlg = FUN_140938c30(0x2711);
            if (pDlg != 0)
                pDlg->FUN_141a5a560();
        }
        if (bMine)
        {
            spCli->FUN_14096c3c0(CStringW(L"[Modify]"), 1);
        }
        else
        {
            MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pMyPC != 0)
            {
                if (pMyPC->FUN_14123c580() == spCli->m_nCasterId)
                    spCli->FUN_14096c3c0(CStringW(L"[Modify]"), 0);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141720480, CSceneStateGame, OnBuff, 2008, 0x7964F895);

// @0x141720c60
void CSceneStateGame::FUN_141720c60(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
    Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_StreamPoint kDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor == 0)
        return;
    MS2Ptr<Unk_SSGSkillAttr> spSkill = FUN_1401958b0()->FUN_140aafef0(nSkillId, nLevel);
    if (spSkill == 0)
        return;
    FUN_141469a90()->FUN_141755cd0(pActor, spSkill, kPos, kDir);
}
MS2_REPLACE_METHOD(0x141720c60, CSceneStateGame, FUN_141720c60, 479, 0x10631625);
// The skill of a region skill object (id 0x140803dc0, level 0x140803df0).
class Unk_InventorySkillLevel : public CPtred { public: unsigned FUN_140803dc0(); unsigned short FUN_140803df0(); };
// The region skill object (?\regionskillobject.cpp; new(0x158)); only the members the 0x4c handler uses.
class CRegionSkillObject : public CPtred
{
public:
    CRegionSkillObject();                                   // 0x1416f57c0
    virtual ~CRegionSkillObject();
    int FUN_1416f5a20(int nId, int nSkillId, const ATL::CAtlArray<Unk_StreamPoint>& kPoints, int nOwnerId, short nLevel, float fB, float fA, int nTick);
    void FUN_1416f6e40();                                   // end the region skill
    void FUN_1416f6900();                                   // a tick hit
    char m_pad_18[0x28 - 0x18];
    MS2Ptr<Unk_InventorySkillLevel> m_spSkill;                      // +0x28 the skill (id, level)
    char m_pad_38[0x158 - 0x38];
};
MS2_CHECK_OFFSET(CRegionSkillObject, m_spSkill, 0x28);
MS2_CHECK_SIZE(CRegionSkillObject, 0x158);
template <> Unk_InventorySkillLevel* MS2Ptr<Unk_InventorySkillLevel>::operator->() const;   // out-of-unit COMDAT (0x1407ebbf0)
// @0x141720e50
void CSceneStateGame::OnRegionSkill(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (nMode == 0)
    {
        int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nTick = static_cast<CInputStream&>(packet).vfunc_o8_3();
        ATL::CAtlArray<Unk_StreamPoint> kPoints;
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();
        for (int i = 0; i < nCount; i++)
            kPoints.Add(static_cast<CInputStream&>(packet).vfunc_o8_10());
        int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
        float fA = static_cast<CInputStream&>(packet).vfunc_o8_5();
        float fB = static_cast<CInputStream&>(packet).vfunc_o8_5();
        MS2Ptr<CRegionSkillObject> spObj(new CRegionSkillObject());
        if (!spObj->FUN_1416f5a20(nId, nSkillId, kPoints, nOwnerId, nLevel, fB, fA, nTick))
            return;
        FUN_1403ed2d0()->FUN_141bc32d0(spObj.get());
    }
    else if (nMode == 1)
    {
        FUN_1403ed2d0()->FUN_141bc33d0(nId);
    }
    else if (nMode == 2)
    {
        MS2Ptr<CRegionSkillObject> spObj(FUN_1403ed2d0()->FUN_141bc3360(nId));
        if (spObj.get() != 0)
            spObj->FUN_1416f6e40();
    }
}
MS2_REPLACE_METHOD(0x141720E50, CSceneStateGame, OnRegionSkill, 1037, 0xEEED3063);

// Part anchors of an actor (gameobject.cpp's 16-byte handle; GameObject::vfunc_27 collects them).
struct Unk_UtilFloat3 { float x, y, z; };
Unk_StreamPoint FUN_141b6e150(const Unk_UtilFloat3* p);
class Unk_GoAnchor
{
public:
    char m_pad[0xb4];
    Unk_UtilFloat3 m_kPos;                                  // +0xb4
};
class Unk_GoAnchorPtr
{
public:
    Unk_GoAnchorPtr(const Unk_GoAnchorPtr& o);              // 0x140a00180
    ~Unk_GoAnchorPtr();                                     // 0x140a00490
    bool FUN_140a00660(int n) const;                        // == NULL
    Unk_GoAnchor* FUN_140ae1940() const;
    void* m_pad[2];
};

// 0x3d mode 5: region skill hits. The region skill (cast uid, owner, region id, attack), then per target its id,
// (flag, damage) hits, origin and direction; npcs with flag 0x1d are hit at their nearest part anchor.
// @0x14171dc40
void CSceneStateGame::FUN_14171dc40(CInPacket& packet)
{
    __int64 nSkillUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nRegionId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nAttack = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();
    MS2Ptr<CRegionSkillObject> spRegion(FUN_1403ed2d0()->FUN_141bc3360(nRegionId));
    if (!spRegion)
        return;
    spRegion->FUN_1416f6900();
    for (int i = 0; i < nCount; i++)
    {
        int nTargetId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nHits = static_cast<CInputStream&>(packet).vfunc_o8_1();
        Unk_StreamPoint kOrigin = static_cast<CInputStream&>(packet).vfunc_o8_11();
        Unk_StreamPoint kDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
        MS2Ptr<CSplashDamageRecord> spRecord(new CSplashDamageRecord());
        if (!spRecord->FUN_14175b1c0(nTargetId, nOwnerId, nSkillUid, spRegion->m_spSkill->FUN_140803dc0(),
                                     spRegion->m_spSkill->FUN_140803df0(), 0, nAttack, kOrigin, kDir))
            return;
        for (int j = 0; j < nHits; j++)
        {
            int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
            __int64 nDamage = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spRecord->FUN_14175abc0(nFlag, nDamage);
        }
        GameObject* pTarget = FUN_1403ed2d0()->FUN_141bd1180(nTargetId);
        if (pTarget != 0)
        {
            CNpc* pNpc = dynamic_cast<CNpc*>(pTarget);
            if (pNpc != 0 && pNpc->FUN_141093270()->FUN_1406cd200(0x1d))
            {
                Unk_StreamPoint kBest = kOrigin;
                ATL::CAtlArray<Unk_GoAnchorPtr> kAnchors;
                pNpc->vfunc_27(kAnchors);
                if (kAnchors.IsEmpty() == true)
                    return;
                float fMin = FLT_MAX;
                for (size_t k = 0; k < kAnchors.GetCount(); k++)
                {
                    Unk_GoAnchorPtr spAnchor(kAnchors[k]);
                    if (spAnchor.FUN_140a00660(0))
                        continue;
                    Unk_StreamPoint kPt = FUN_141b6e150(&spAnchor.FUN_140ae1940()->m_kPos);
                    float fDist = kOrigin.FUN_140965c40(kPt).FUN_140967ac0();
                    if (fDist < fMin)
                    {
                        fMin = fDist;
                        kBest = kPt;
                    }
                }
                spRecord->m_kPos = kBest;
            }
            FUN_1410a7630()->FUN_14146bc80(spRecord.get());
        }
    }
}
MS2_REPLACE_METHOD(0x14171DC40, CSceneStateGame, FUN_14171dc40, 2035, 0x57F2ECD1);

// @0x141723410
void CSceneStateGame::OnSetCraftMode(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int bHasItem = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    if (pPC->FUN_14166ce30() != 0)
        return;
    if (bHasItem)
    {
        CubeItemInfo info(packet);
        int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_3();
        pPC->vfunc_135(bHasItem, nSlot, &info);
    }
    else
    {
        pPC->vfunc_135(bHasItem, 0, 0);
    }
    if (FUN_1409613d0(pPC) != 0)
    {
        PCBase* pTarget = FUN_1403ed2d0()->FUN_141bd3620();
        if (pTarget != 0)
            static_cast<Unk_SSGMyPCV*>(pTarget)->vfunc_149();
    }
}
MS2_REPLACE_METHOD(0x141723410, CSceneStateGame, OnSetCraftMode, 384, 0xE64CE8BE);

// @0x14172f030
// MS2-FUNCTIONAL: exe passes nSkillId to FUN_141768530 as mov ecx,[x]; mov edx,ecx (unrecovered argument conversion)
void CSceneStateGame::FUN_14172f030(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    int nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        __int64 nUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (nSlot == 0)
            pMyPC->FUN_141523bc0()->FUN_141765f60(nUid);
        else
            pMyPC->FUN_141523bc0()->FUN_141766900(nUid, nSlot);
        int nSkillId = FUN_1417692f0(nUid);
        pMyPC->FUN_141523bc0()->FUN_141768530(nSkillId, nValue);
    }
    FUN_1419f37f0(5);
}
MS2_REPLACE_METHOD(0x14172f030, CSceneStateGame, FUN_14172f030, 382, 0xAA5F3F51);

// @0x141731190
void CSceneStateGame::FUN_141731190(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nValue = (unsigned int)static_cast<CInputStream&>(packet).vfunc_o8_3();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor == 0)
        return;
    if (nType == 4)
    {
        Unk_StreamPoint kPos = DAT_143b01a60;
        pActor->vfunc_111(reinterpret_cast<void*>(nValue), 5, nId, &kPos);
    }
    if (nType == 7)
    {
        Unk_StreamPoint kPos = DAT_143b01a60;
        pActor->vfunc_111(reinterpret_cast<void*>(nValue), 6, nId, &kPos);
    }
    if (nType == 0xa)
    {
        Unk_StreamPoint kPos = DAT_143b01a60;
        pActor->vfunc_111(reinterpret_cast<void*>(nValue), 7, nId, &kPos);
    }
}
MS2_REPLACE_METHOD(0x141731190, CSceneStateGame, FUN_141731190, 436, 0x6F315244);

// @0x141731470
void CSceneStateGame::FUN_141731470(CInPacket& packet)
{
    bool bOpen = false;
    CAtlArray<unsigned int> arrIds;
    FUN_1403d7440(packet, arrIds);
    FUN_14070f300(packet, bOpen);
    if (arrIds.IsEmpty())
        return;
    for (unsigned int i = 0; i < arrIds.GetCount(); i++)
        DAT_143ab3078.FUN_1401855a0(arrIds[i]);
    if (bOpen)
    {
        int nFirst = arrIds[0];
        FUN_141275260(0x7c8, 3, 1);
        FUN_141276180(DAT_143ae79e8, "");
        Unk_SSGDlg4e29* pDlg = FUN_140c9b540(0x4e29);
        if (pDlg != 0)
            pDlg->FUN_141a3a780(nFirst);
        FUN_141739450(true);
        FUN_1409331e0()->FUN_14138bf00(0x10, 0, 0);
    }
    FUN_1412787a0()->FUN_1409f1970();
}
MS2_REPLACE_METHOD(0x141731470, CSceneStateGame, FUN_141731470, 407, 0x5515C134);

// @0x141733660
void CSceneStateGame::OnSystemShop(CInPacket& packet)
{
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    bool bOk = static_cast<CInputStream&>(packet).vfunc_o8_0();
    if (nType == 0)
        return;
    if (!bOk)
    {
        if (nType == 8)
        {
            FUN_140d73aa0(FUN_14028b8e0(L"s_shop_no_star_point_event"), 0, 0, CStringW(L""));
        }
    }
    else
    {
        FUN_1403ed2b0()->FUN_141adc530(0x4e3b);
        Unk_SSGDlgShop* pDlg = FUN_140534780(0x4e3b);
        if (pDlg != 0)
            pDlg->FUN_141afb720(nType);
    }
}
MS2_REPLACE_METHOD(0x141733660, CSceneStateGame, OnSystemShop, 340, 0x89D2A43C);

// @0x141733f50
void CSceneStateGame::OnSetPcbang(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    pPC->FUN_141658ed0(nValue);
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        PCBase* pTarget = FUN_1403ed2d0()->FUN_141bd3620();
        if (pTarget != 0)
            static_cast<PC*>(pTarget)->FUN_141658ed0(nValue);
        Unk_SSGDlgInv* pDlg = FUN_1405344f0(0x4e2d);
        if (pDlg != 0)
            pDlg->FUN_141999f60();
        FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new Unk_SSGNotifyInventory()));
    }
}
MS2_REPLACE_METHOD(0x141733f50, CSceneStateGame, OnSetPcbang, 403, 0xB72802C3);

// @0x1417340f0
void CSceneStateGame::FUN_1417340f0(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 1:
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
            if (pPC == 0)
                return;
            pPC->FUN_141662640(nValue);
            pPC->FUN_141662690(nA);
            pPC->FUN_141662710(nB);
            if (pPC->GetClassID() == 0x6200004)
            {
                Unk_SSGDlg2711* pDlg = FUN_140938c30(0x2711);
                if (pDlg != 0)
                    pDlg->FUN_141a5a560();
            }
        }
        break;
    case 0:
        {
            __int64 nAccountId = static_cast<CInputStream&>(packet).vfunc_o8_4();
            __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
            if (DAT_143ab2820 != nAccountId)
                return;
            DAT_143ab2920 = nValue;
        }
        break;
    case 2:
        {
            __int64 nAccountId = static_cast<CInputStream&>(packet).vfunc_o8_4();
            __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
            if (DAT_143ab2820 != nAccountId)
                return;
            DAT_143ab2920 = nValue;
        }
        break;
    }
}
MS2_REPLACE_METHOD(0x1417340f0, CSceneStateGame, FUN_1417340f0, 714, 0x6B3B25EC);

// @0x1417343f0
void CSceneStateGame::OnItemDropNotice(CInPacket& packet)
{
    CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nC = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW strItem = FUN_140d2e2b0(nA, nB, nC);
    CStringW strMsg = FUN_140632a60(0x342, strName, strItem);
    FUN_1412751b0(strMsg, 0x14);
}
MS2_REPLACE_METHOD(0x1417343f0, CSceneStateGame, OnItemDropNotice, 309, 0x3BC0794C);
// The recall notice (packet 0xbc mode 1): text, three ints and a uid.
struct Unk_SSGRecallInfo
{
    Unk_SSGRecallInfo();                                    // 0x1408f2300
    ~Unk_SSGRecallInfo();                                   // 0x1408f2590
    CStringW m_strText;
    int m_n8;
    int m_nC;
    int m_n10;
    __int64 m_n18;
};
MS2_CHECK_SIZE(Unk_SSGRecallInfo, 0x20);
class Unk_SSGRecallDlg : public UIDialog { public: void FUN_14129c920(int nType, __int64 nUid, const Unk_SSGRecallInfo& info, int nValue); void FUN_14129caa0(int nType); };
Unk_SSGRecallDlg* FUN_140bc1870(int nId);                   // GetDialog<T>(0x4edd)
extern CString DAT_143ae7558;                               // the recall notice sound event name
// @0x141734530
void CSceneStateGame::OnRecallScroll(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode != 0)
    {
        Unk_SSGRecallInfo kInfo;
        kInfo.m_strText = static_cast<CInputStream&>(packet).vfunc_o8_8();
        kInfo.m_n8 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        kInfo.m_nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
        kInfo.m_n10 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        kInfo.m_n18 = static_cast<CInputStream&>(packet).vfunc_o8_4();
        Unk_SSGRecallDlg* pDlg = FUN_140bc1870(0x4edd);
        if (pDlg == 0)
            return;
        CStringW strMsg;
        switch (nType)
        {
        case 0:
            strMsg = FUN_14028de60(0xb64);
            break;
        case 1:
            strMsg = FUN_14028de60(0xb63);
            break;
        case 2:
            strMsg = FUN_14028b8e0(L"s_cash_recall_wedding_notice");
            break;
        }
        pDlg->FUN_14129c920(nType, kInfo.m_n18, kInfo, kInfo.m_nC);
        FUN_1412751f0(strMsg, 3, 1);
        FUN_141276180(DAT_143ae7558, "");
    }
    else
    {
        Unk_SSGRecallDlg* pDlg = FUN_140bc1870(0x4edd);
        if (pDlg == 0)
            return;
        pDlg->FUN_14129caa0(nType);
    }
}
MS2_REPLACE_METHOD(0x141734530, CSceneStateGame, OnRecallScroll, 1003, 0x1620B1DD);

// @0x141734950
void CSceneStateGame::OnEnchantScroll(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    UIEnchantScrollDialog* pDlg = FUN_140cd7aa0(0x4ee0);
    if (pDlg == 0)
        return;
    if (nMode == 0)
    {
        pDlg->FUN_140f3b920(packet);
    }
    else if (nMode == 1)
    {
        pDlg->FUN_140f3bd10(packet);
    }
    else if (nMode == 3)
    {
        pDlg->FUN_140f3c6c0(packet);
    }
    else if (nMode == 4)
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        Unk_SSGChatDialog* pChat = FUN_140938cd0(0x4e5d);
        if (pChat != 0)
        {
            for (int i = 0; i < nCount; i++)
            {
                int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                int nValue = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
                pChat->FUN_141abf6e0(nItemId, nValue);
            }
        }
        UIMasteryDialog* pMastery = FUN_140faf160(0x4f1e);
        if (pMastery != 0)
            pMastery->FUN_140eb4ba0();
    }
}
MS2_REPLACE_METHOD(0x141734950, CSceneStateGame, OnEnchantScroll, 452, 0x69A47724);

// @0x141734ca0
void CSceneStateGame::OnDarkStream(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        FUN_1403ed2b0()->FUN_141adc530(0x4ee4);
        UIDarkStreamScoreDialog* pDlg = FUN_140f9d8a0(0x4ee4);
        if (pDlg == 0)
            return;
        pDlg->vfunc_84(0);
    }
    else if (nMode == 1)
    {
        int nScore = static_cast<CInputStream&>(packet).vfunc_o8_3();
        UIDarkStreamScoreDialog* pDlg = FUN_140f9d8a0(0x4ee4);
        if (pDlg == 0)
            return;
        pDlg->vfunc_84(nScore);
    }
    else if (nMode == 2)
    {
        FUN_1403ed2b0()->FUN_141adc5d0(0x4ee4);
        FUN_1403ed2b0()->FUN_141adc530(0x4ee5);
        UIDarkStreamResultDialog* pDlg = Unk_SSGGetDialog<UIDarkStreamResultDialog>(0x4ee5);
        if (pDlg == 0)
            return;
        pDlg->FUN_140f34cb0(0);
        pDlg->FUN_140f34ab0(packet);
    }
}
MS2_REPLACE_METHOD(0x141734ca0, CSceneStateGame, OnDarkStream, 334, 0x7DA5CD92);

// 0x141738b40: UGC map notices. Chat from another player (0x1407a7eb0 reads it; the dtor 0x1417469a0 is emitted here).
struct Unk_SSGUserChat
{
    Unk_SSGUserChat(CInPacket& packet);
    __int64 m_nCharId;
    CStringW m_strName;
    unsigned char m_nType;
    CStringW m_strMsg;
};
MS2_CHECK_SIZE(Unk_SSGUserChat, 0x20);
class Unk_SSG9c1730 { public: bool FUN_140a25840(__int64 nId, CStringW strName); };   // chat filter
Unk_SSG9c1730* FUN_1409c1730();
CStringW FUN_14028ee20(unsigned int nFlags, CStringW strText);
class UISurveyDialog : public UIDialog { public: void FUN_140eda1b0(CInPacket& packet); };
class UIUGCPortalDialog : public UIDialog { public: void FUN_140fb0290(CInPacket& packet); };
class UIUGCCubeNoticeDialog : public UIDialog { public: void FUN_140faf900(CInPacket& packet); };
class UIUGCPVPControlDialog : public UIDialog { public: void FUN_140fb5650(CInPacket& packet); };
void FUN_140dee4a0(CInPacket& packet);
void FUN_140dff600(CInPacket& packet);
// The notice text of a cube (0x28 bytes, ctor 0x1408b4850).
class NoticeCubeInfo
{
public:
    NoticeCubeInfo();
    void FUN_1408b4970(const CStringW& strText, int nType);
private:
    void* m_unk_00[5];
};
MS2_CHECK_SIZE(NoticeCubeInfo, 0x28);
extern template class MS2Ptr<Cube>;                          // instances live outside the unit (0x140884fb0...)
// Unk_PayloadPtr<NoticeCubeInfo>: only operator=(T*) is emitted here (0x141746eb0); the rest are ICF copies elsewhere.
extern template Unk_PayloadPtr<NoticeCubeInfo>::Unk_PayloadPtr(NoticeCubeInfo* value);
extern template Unk_PayloadPtr<NoticeCubeInfo>::~Unk_PayloadPtr();
extern template bool Unk_PayloadPtr<NoticeCubeInfo>::operator==(NoticeCubeInfo* value) const;
extern template NoticeCubeInfo* Unk_PayloadPtr<NoticeCubeInfo>::operator->() const;
class Unk_SSG9670e0 { public: void FUN_1410c92e0(int nCubeId); void FUN_1410c3560(unsigned char n); void FUN_1410c3580(unsigned char n);
    void FUN_1410c35a0(unsigned char n); void FUN_1410d5b20(__int64 n); };
Unk_SSG9670e0* FUN_1409670e0();

UIDialog* FUN_141386950(const CString& strName);           // a dialog by its name

// @0x141734e00
// MS2-FUNCTIONAL: exe frame is 0x10 bytes larger (point copy at +0xe0, unwind state at +0xf0); code otherwise identical
void CSceneStateGame::OnPlayArcade(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nType = static_cast<CInputStream&>(packet).vfunc_o8_3();
        UIDarkStreamScoreDialog* pScore = FUN_140f9d8a0(0x4ee4);
        if (pScore != 0)
        {
            pScore->vfunc_84(0);
            pScore->FUN_140f35660(-80);
            pScore->FUN_140f356a0(6);
            if (nType == 3)
            {
                pScore->FUN_140f35660(100);
                pScore->FUN_140f356a0(1);
            }
            pScore->FUN_141924680();
        }
        UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
        if (pInfo != 0)
            pInfo->FUN_1419f1d10(2, false);
        FUN_1403ed2b0()->FUN_141add0b0(0x4e3d);
        FUN_1403ed2b0()->FUN_141add0b0(0x4e51);
        FUN_1403ed2b0()->FUN_141add1b0(8, false);
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
        {
            {
                MS2Ptr<Unk_PCBaseComp_a78> spHud = pPC->vfunc_82();
                if (spHud.get())
                {
                    spHud->FUN_140f48dc0(0);
                    spHud->vfunc_3();
                }
            }
            UIHpBar* pHpBar = Unk_SSGGetDialog<UIHpBar>(0x4e36);
            if (pHpBar != 0)
                FUN_1419929f0(pPC->FUN_14123c580());
        }
    }
    else if (nMode == 1)
    {
        int nScore = static_cast<CInputStream&>(packet).vfunc_o8_3();
        UIDarkStreamScoreDialog* pScore = FUN_140f9d8a0(0x4ee4);
        if (pScore == 0)
            return;
        pScore->vfunc_84(nScore);
    }
    else if (nMode == 2)
    {
        FUN_1403ed2b0()->FUN_141adc5d0(0x4ee4);
        FUN_1403ed2b0()->FUN_141adc530(0x4ee5);
        UIDarkStreamResultDialog* pResult = Unk_SSGGetDialog<UIDarkStreamResultDialog>(0x4ee5);
        if (pResult == 0)
            return;
        pResult->FUN_140f34cb0(true);
        pResult->FUN_140f34ab0(packet);
    }
    else if (nMode == 12)
    {
        int nAlign = static_cast<CInputStream&>(packet).vfunc_o8_1();
        UIDarkStreamScoreDialog* pScore = FUN_140f9d8a0(0x4ee4);
        if (pScore != 0)
        {
            pScore->vfunc_84(0);
            if (nAlign == 1)
            {
                pScore->FUN_140f35660(0);
                pScore->FUN_140f356a0(1);
            }
            else if (nAlign == 2)
            {
                pScore->FUN_140f35660(-80);
                pScore->FUN_140f356a0(6);
            }
            pScore->FUN_141924680();
        }
    }
    else if (nMode == 13)
    {
        FUN_1403ed2b0()->FUN_141adc5d0(0x4ee4);
    }
    else if (nMode == 14)
    {
        bool bOn = static_cast<CInputStream&>(packet).vfunc_o8_0();
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC == 0)
            return;
        if (bOn)
            pPC->FUN_14166cd70(0x200);
        else
        {
            efd::Point3 kPos = efd::Point3::ZERO;
            pPC->vfunc_22(kPos);
            pPC->FUN_14166cce0(0x200);
        }
    }
    UIArcadeMainDialog* pMain = Unk_SSGGetDialog<UIArcadeMainDialog>(0x4efd);
    if (pMain != 0)
        pMain->FUN_140ef7d30(nMode, packet);
    UIArcadeLifeBar* pLifeBar = Unk_SSGGetDialog<UIArcadeLifeBar>(0x4efc);
    if (pLifeBar != 0)
        pLifeBar->FUN_140ef51e0(nMode, packet);
    UIMicroGameCoupleDance* pDance = FUN_140b8b5c0(0x4f70);
    if (pDance != 0)
        pDance->FUN_140e647c0(nMode, packet);
    UIArcadeTextEffectDialog* pText = Unk_SSGGetDialog<UIArcadeTextEffectDialog>(0x4f82);
    if (pText != 0)
        pText->FUN_140ba7fe0(nMode, packet);
}
MS2_REPLACE_METHOD(0x141734E00, CSceneStateGame, OnPlayArcade, 1437, 0xAD857D61);

// @0x141738b40
void CSceneStateGame::FUN_141738b40(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 8:
        FUN_141739220(packet);
        break;
    case 4:
    {
        StringIdInterface kText(packet);
        FUN_1412751f0(kText.FUN_141024e60(), 3, 1);
        break;
    }
    case 5:
    {
        UISurveyDialog* pDlg = dynamic_cast<UISurveyDialog*>((UIObject*)FUN_1403ed2b0()->FUN_141adcea0(0x4f1a));
        if (pDlg != 0)
            pDlg->FUN_140eda1b0(packet);
        break;
    }
    case 6:
        switch (static_cast<CInputStream&>(packet).vfunc_o8_1())
        {
        case 0:
            UIUGCPortalDialog* pDlg = Unk_SSGGetDialog<UIUGCPortalDialog>(0x4f1f);
            if (pDlg != 0)
                pDlg->FUN_140fb0290(packet);
        }
        break;
    case 12:
        switch (static_cast<CInputStream&>(packet).vfunc_o8_1())
        {
        case 1:
        {
            UIUGCCubeNoticeDialog* pDlg = Unk_SSGGetDialog<UIUGCCubeNoticeDialog>(0x4f51);
            if (pDlg != 0)
                pDlg->FUN_140faf900(packet);
            break;
        }
        case 0:
            efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
            if (spService)
            {
                int nCubeId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                CStringW strText = static_cast<CInputStream&>(packet).vfunc_o8_8();
                int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
                MS2Ptr<Cube> spCube(spService->FUN_1410b8b00(nCubeId));
                if (spCube->notice == 0)
                    spCube->notice = new NoticeCubeInfo;
                spCube->notice->FUN_1408b4970(strText, nType);
                FUN_1409670e0()->FUN_1410c92e0(nCubeId);
            }
        }
        break;
    case 7:
        FUN_140dee4a0(packet);
        break;
    case 10:
        FUN_140dff600(packet);
        break;
    case 11:
    {
        Unk_SSGUserChat kChat(packet);
        if (FUN_1409c1730()->FUN_140a25840(0, kChat.m_strName))
            break;
        if (FUN_14097a780()->FUN_140ae5240(kChat.m_strName) != 0)
            break;
        if (kChat.m_nCharId != 0 && FUN_14097a780()->FUN_140ae51b0(kChat.m_nCharId) != 0)
            break;
        FUN_1412751b0(FUN_14028ee20(4, kChat.m_strMsg), 0x14);
        break;
    }
    case 14:
        switch (static_cast<CInputStream&>(packet).vfunc_o8_1())
        {
        case 0:
            UIUGCPVPControlDialog* pDlg = Unk_SSGGetDialog<UIUGCPVPControlDialog>(0x4f64);
            if (pDlg != 0)
                pDlg->FUN_140fb5650(packet);
        }
    }
}
MS2_REPLACE_METHOD(0x141738B40, CSceneStateGame, FUN_141738b40, 1665, 0x3FD69AC2);

// @0x141739e40
void CSceneStateGame::FUN_141739e40(CInPacket& packet)
{
    int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nB = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    const CStringW& strFunction = spData->function.name;
    if (FUN_1403b3c40(strFunction, L"OpenItemBox") || FUN_1403b3c40(strFunction, L"SelectItemBox"))
    {
        UIItemMultiOpenBoxDialog* pDlg = FUN_140d27580(0x4f88);
        if (pDlg != 0)
            pDlg->FUN_140c3fa80(nA, nB);
    }
}
MS2_REPLACE_METHOD(0x141739e40, CSceneStateGame, FUN_141739e40, 329, 0xADF56E72);

// @0x141739f90
void CSceneStateGame::OnPremiumClub(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            return;
        pPC->FUN_141662d60(static_cast<CInputStream&>(packet).vfunc_o8_4());
        FUN_141a60f00(nId);
        if (pPC->vfunc_108())
            FUN_1419f37f0(1);
        Unk_SSGDlgInv* pDlg = FUN_1405344f0(0x4e2d);
        if (pDlg != 0)
            pDlg->FUN_141999f60();
    }
    else
    {
        UIVIPDialog* pDlg = Unk_SSGGetDialog<UIVIPDialog>(0x4f1b);
        if (pDlg != 0)
            pDlg->FUN_140fb87d0(packet, nMode);
    }
}
MS2_REPLACE_METHOD(0x141739f90, CSceneStateGame, OnPremiumClub, 311, 0x8CE619AA);

// @0x14173a420
void CSceneStateGame::OnOneTimeEffect(CInPacket& packet)
{
    CString strName;
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    bool bHas = static_cast<CInputStream&>(packet).vfunc_o8_0();
    if (bHas)
        strName = FUN_14016a600(static_cast<CInputStream&>(packet).vfunc_o8_8(), 0);
    FUN_140ad4b90()->FUN_141863630(nId, bHas, strName);
}
MS2_REPLACE_METHOD(0x14173a420, CSceneStateGame, OnOneTimeEffect, 388, 0x0C53B150);

// @0x14173a5e0
void CSceneStateGame::OnTimeScale(CInPacket& packet)
{
    bool bShow = static_cast<CInputStream&>(packet).vfunc_o8_0();
    float fX = static_cast<CInputStream&>(packet).vfunc_o8_5();
    float fY = static_cast<CInputStream&>(packet).vfunc_o8_5();
    float fZ = static_cast<CInputStream&>(packet).vfunc_o8_5();
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (bShow)
        FUN_1403ed2d0()->FUN_141bd92c0(fX, fY, fZ, nType);
    else
        FUN_1403ed2d0()->FUN_141bd9380();
}
MS2_REPLACE_METHOD(0x14173a5e0, CSceneStateGame, OnTimeScale, 310, 0xA7D1CD36);

// @0x14173a720
void CSceneStateGame::FUN_14173a720(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nCount = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        for (int i = 0; i < nCount; i++)
        {
            int nFieldId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nNpcId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            CMsTime kTime(static_cast<CInputStream&>(packet).vfunc_o8_4());
            FUN_140700390()->FUN_1406fc480(nFieldId, nNpcId, kTime);
        }
    }
    else if (nMode == 1)
    {
        int nFieldId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nNpcId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CMsTime kTime(static_cast<CInputStream&>(packet).vfunc_o8_4());
        FUN_140700390()->FUN_1406fc480(nFieldId, nNpcId, kTime);
    }
    else if (nMode == 2)
    {
        int nFieldId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_140700390()->FUN_1406fc590(nFieldId);
    }
}
MS2_REPLACE_METHOD(0x14173a720, CSceneStateGame, FUN_14173a720, 609, 0xCA68677E);

// @0x14173b080
void CSceneStateGame::FUN_14173b080(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    StateFishingData* pData = new StateFishingData(32000001);
    int nState = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nArg = static_cast<CInputStream&>(packet).vfunc_o8_3();
    pPC->vfunc_59(nState, pData, nArg, 0);
}
MS2_REPLACE_METHOD(0x14173b080, CSceneStateGame, FUN_14173b080, 319, 0x1E71DC7F);

// @0x14173b220
void CSceneStateGame::FUN_14173b220(CInPacket& packet)
{
    __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    const CStringW& strTitle = static_cast<CInputStream&>(packet).vfunc_o8_8();
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
    if (spItem == 0)
        return;
    CUgcItemLook* pLook = ((CItem*)spItem)->FUN_140528380();
    if (pLook != 0)
    {
        pLook->m_n60 = nValue;
        pLook->m_str28 = strTitle;
    }
}
MS2_REPLACE_METHOD(0x14173b220, CSceneStateGame, FUN_14173b220, 334, 0xD2E16AC7);

// @0x14173b420
void CSceneStateGame::FUN_14173b420(CInPacket& packet)
{
    __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
    if (spItem == 0)
    {
        MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC == 0)
            return;
        MS2Ptr<CEquipItem> spEquip = pMyPC->FUN_141655c30(nItemUid);
        if (spEquip.get())
            spItem = spEquip->GetItem();
        if (spItem == 0)
            return;
    }
    ((CItem*)spItem)->FUN_140524eb0(packet);
}
MS2_REPLACE_METHOD(0x14173b420, CSceneStateGame, FUN_14173b420, 372, 0x5E75A989);

// @0x14173c0f0
void CSceneStateGame::FUN_14173c0f0(CInPacket& packet)
{
    if (!FUN_140166410()->FUN_14036d570(0x88))
        return;
    CStringW strA = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW strC = static_cast<CInputStream&>(packet).vfunc_o8_8();
    Unk_SSGCommunityPopup* pPopup = FUN_14136f1f0(0x4f5c);
    if (pPopup != 0)
    {
        CString strTextA = FUN_14016a600(strA, 0);
        CString strTextC = FUN_14016a600(strC, 0);
        pPopup->FUN_140bea390(strName, FUN_14016a5c0(strTextA, 0));
    }
}
MS2_REPLACE_METHOD(0x14173c0f0, CSceneStateGame, FUN_14173c0f0, 469, 0x00599B3A);

// 0xab mode 5: an outfit (codi) tab was activated, permanently or for a period.
struct Unk_SSGCodiTabInfo
{
    Unk_SSGCodiTabInfo() : m_nActorId(0), m_nStart(0), m_nEnd(0), m_nExpire(0), m_bSilent(false) {}   // @0x141745f70
    int m_nActorId;                                         // +0x00
    __int64 m_nStart;                                       // +0x08
    __int64 m_nEnd;                                         // +0x10
    __int64 m_nExpire;                                      // +0x18 (0 = limitless)
    bool m_bSilent;                                         // +0x20
};
void FUN_1407a8250(Unk_SSGCodiTabInfo& v, CInputStream& in);   // decode (unit_1407a4f20.cpp)
int FUN_14086be70(int nTime);                               // days left until nTime (32-bit time)
// The codi tab notification (ctor/dtor are emitted in this unit; vfunc_1 lives in the notify unit).
class NotifyActiveMyCodiTab : public NotifyObject
{
public:
    NotifyActiveMyCodiTab(const __int64& nStart, const __int64& nEnd) : m_nStart(nStart), m_nEnd(nEnd) {}
    virtual ~NotifyActiveMyCodiTab() = default;
    virtual CStringW vfunc_1();                             // 0x140db4cd0
    __int64 m_nStart;                                       // +0x18
    __int64 m_nEnd;                                         // +0x20
};
MS2_CHECK_SIZE(NotifyActiveMyCodiTab, 0x28);

// @0x141739910
void CSceneStateGame::FUN_141739910(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        FUN_140d73bc0(0x2a2, 0, 0, L"");
        break;
    case 1:
        FUN_140d73bc0(0x2a3, 0, 0, L"");
        break;
    case 2:
        FUN_140d73bc0(0x2a4, 0, 0, L"");
        break;
    case 3:
        FUN_140d73bc0(0x2a5, 0, 0, L"");
        break;
    case 4:
    {
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
        if (spData)
        {
            CString strDialog = spData->function.xml.FUN_1409e8560(L"notifyDlg", "");
            CStringW strMsg = spData->function.xml.FUN_14042cad0(L"notifyMsg", L"");
            if (strDialog.GetLength() != 0)
            {
                UIDialog* pDlg = FUN_141386950(strDialog);
                if (pDlg != 0)
                    pDlg->FUN_141924680();
            }
            else if (strMsg.GetLength() != 0)
            {
                CStringW strText = FUN_14052bd00(0x5f6, FUN_1401a9d70()->FUN_141811980(1, nItemId));
                strText += L"\n";
                strText += FUN_14028b8e0(strMsg);
                FUN_140d73aa0(strText, 0, 0, L"");
            }
        }
        Unk_SSGDlg4e28* pDlg = FUN_140938b90(0x4e28);
        if (pDlg != 0)
            pDlg->FUN_140ea5f80();
    }
        break;
    case 5:
        FUN_14173c2d0(packet);
        break;
    case 6:
        SendBeauty(packet);
        break;
    case 7:
        Unk_SSGDlg4e28* pDlg = FUN_140938b90(0x4e28);
        if (pDlg != 0)
            pDlg->FUN_140ea5f80();
    }
}
MS2_REPLACE_METHOD(0x141739910, CSceneStateGame, FUN_141739910, 1277, 0x53BFFD2C);

// @0x14173c2d0
void CSceneStateGame::FUN_14173c2d0(CInPacket& packet)
{
    Unk_SSGCodiTabInfo kInfo;
    FUN_1407a8250(kInfo, packet);
    int nActorId = kInfo.m_nActorId;
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nActorId);
    if (pPC == 0)
        return;
    const __int64& nStart = kInfo.m_nStart;
    const __int64& nEnd = kInfo.m_nEnd;
    pPC->FUN_1416561a0()->FUN_1411ea620(nStart, nEnd);
    if (efd::ClassInfo::IsKindOf(pPC != NULL ? pPC->GetClassDesc() : NULL, 0x6200004))
    {
        if (kInfo.m_bSilent == false)
        {
            if (kInfo.m_nExpire == 0)
                FUN_140d73aa0(FUN_14028b8e0(L"s_msg_item_active_codi_tab_complete_limitless"), 0, 0, CStringW(L""));
            else
            {
                int nDays = FUN_14086be70(static_cast<int>(kInfo.m_nExpire));
                if (0 < nDays)
                    FUN_140d73aa0(FUN_14062b4f0(CStringW(L"s_msg_item_active_codi_tab_complete_period"), nDays), 0, 0, CStringW(L""));
            }
        }
        FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyActiveMyCodiTab(nStart, nEnd)));
    }
}
MS2_REPLACE_METHOD(0x14173C2D0, CSceneStateGame, FUN_14173c2d0, 850, 0x8F073C4A);

// @0x14173c630
void CSceneStateGame::SendBeauty(CInPacket& packet)
{
    Unk_SSGBeautyReq req;
    FUN_1407a8340(req, packet);
    int nType = req.m_nType;
    if (nType == 0)
        return;
    UIBeautyShopDialog* pDlg = Unk_SSGGetDialog<UIBeautyShopDialog>(0x4eee);
    if (pDlg == 0 || pDlg->FUN_141924630() == 1)
        return;
    UISwfEntity* pEntity = FUN_1408e57f0()->FUN_1422b9e20(0x620001f);
    if (pEntity != 0)
    {
        Unk_SSGUIMsg msg;
        msg.FUN_1422b82b0("openDialog");
        msg.FUN_1422b7f70(0x4eee);
        pEntity->OnMessage(0, &msg);
    }
    COutPacket out(0x23, 0);
    out.COutPacket::vfunc_o10_1(0x17);
    out.COutPacket::vfunc_o10_4(req.m_nUid);
    FUN_140710590(out);
    FUN_1408e57f0()->FUN_1422b9fd0(0x620001f);
}
MS2_REPLACE_METHOD(0x14173c630, CSceneStateGame, SendBeauty, 357, 0x2D049D06);

// @0x14173d180
void CSceneStateGame::FUN_14173d180(CInPacket& packet)
{
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    if (pWorld == 0)
        return;
    MyPC* pPC = pWorld->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 1:
    {
        __int64 nTargetUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        pPC->vfunc_59(0x3f, new StateObserverData(nTargetUid), 0, 1);
        break;
    }
    default:
        MS2_ASSERT_AT(11116, 0);
    }
}
MS2_REPLACE_METHOD(0x14173d180, CSceneStateGame, FUN_14173d180, 337, 0xAC8A7984);

// @0x14173d2e0
void CSceneStateGame::OnLapenshard(CInPacket& packet)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
    {
        pPC->FUN_14152f9e0();
        unsigned int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (unsigned int i = 0; i < nCount; ++i)
        {
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            pPC->FUN_14152f530(nA, nB, 1);
        }
        pPC->FUN_14152fa20();
        FUN_1419f37f0(5);
        break;
    }
    case 1:
    {
        Unk_SSG5b5dd0 kEntry;
        kEntry.FUN_1405b5dd0(packet);
        pPC->FUN_14152f530(kEntry.m_nA, kEntry.m_nB, 0);
        FUN_1419f37f0(5);
        break;
    }
    case 2:
    {
        Unk_SSG5b5e70 kEntry;
        kEntry.FUN_1405b5e70(packet);
        pPC->FUN_14152f620(kEntry.m_nA);
        FUN_1419f37f0(5);
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x14173d2e0, CSceneStateGame, OnLapenshard, 483, 0x21A44490);

// Packet 0xd4: adventure level (prestige): exp, level-up, claimed rewards and missions.
// The payload (unit_1407a4f20's tagged body; kind 0: exp + claimed set, 1: exp gain, 2: level of a player, 4: new claims).
struct Unk_1407a8820
{
    Unk_1407a8820() : m_00(8), m_08(0), m_10(0), m_18(0), m_30(0), m_38(0), m_3c(0), m_40(0) {}
    int m_00;                                               // kind
    __int64 m_08;                                           // exp
    int m_10;                                               // level threshold reached
    __int64 m_18;
    std::set<unsigned int> m_20;                            // claimed reward levels
    __int64 m_30;                                           // exp gained
    int m_38;                                               // level
    int m_3c;                                               // player id
    int m_40;                                               // 1: the claim succeeded
};
void FUN_1407a8b20(Unk_1407a8820& v, CInputStream& in);
extern __int64 DAT_143ab2958;                               // current adventure exp
extern unsigned int DAT_143ab2960;                          // adventure level threshold reached
extern __int64 DAT_143ab2968;
extern std::set<unsigned int> DAT_143ab3308;                // the claimed level rewards
extern std::map<unsigned int, CAdventureLevelMissionData> DAT_143ab3318;   // the mission progress
class UIAdventureLevelDialog : public UIDialog { public: void FUN_140ba31c0(); void FUN_140ba3200(); };   // refresh rewards / missions
class UIAdventureLevelOldDialog : public UIDialog { public: void FUN_140ba5a70(); };                    // refresh rewards
class UIAdventureLevelExpBar { public: void FUN_140ba6cf0(__int64 nGain); };
UIAdventureLevelExpBar* FUN_14125b160(int nId);             // GetDialog<UIAdventureLevelExpBar> (gameoptionstruct.cpp)
void FUN_1413610f0(__int64 nGain);                          // the exp gain notice
void FUN_141b16580(int nLevel);                             // system text 0xd22 (level up)
// @0x14173d4d0
// deleting dtor; it calls the real dtor 0x140195700, which the exe calls here)
void CSceneStateGame::OnPrestige(CInPacket& packet)
{
    unsigned int nOffset = packet.vfunc_0();
    Unk_1407a8820 kPayload;
    FUN_1407a8b20(kPayload, packet);
    __int64 nGain = 0;
    switch (kPayload.m_00)
    {
    case 1:
        nGain = kPayload.m_30;
        DAT_143ab2958 = kPayload.m_08;
        FUN_140aa6d40()->FUN_141b0ce20(0x12, 0);
        FUN_1413610f0(nGain);
        break;
    case 2:
    {
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(kPayload.m_3c);
        if (pPC == 0)
            break;
        {
            unsigned int nOldLevel = pPC->vfunc_141();
            pPC->vfunc_140(kPayload.m_38);
            if (nOldLevel < pPC->vfunc_141())
            {
                Unk_SSGEffectReq req;
                req.m_strName = FUN_1401d31f0()->m_str5b0;
                req.m_nType = FUN_1403ed2d0()->FUN_141bd1a10(pPC);
                if (pPC->FUN_1416764a0() != 0)
                {
                    efd::SmartPointer<Ridee> spRidee(pPC->FUN_1416764a0());
                    req.FUN_140a53190(spRidee->FUN_14123c580());
                }
                else
                    req.FUN_140a53190(pPC->FUN_14123c580());
                FUN_1403ed280()->FUN_1411a49c0(req);
            }
            MyPC* pMyPC = FUN_1409613d0(pPC);
            if (pMyPC == 0)
                break;
            {
                if (nOldLevel == 0)
                    DAT_143ab2960 = 1;
                Unk_SSGChatDialog* pChat;
                if (nOldLevel < pPC->vfunc_141() && (pChat = FUN_140938cd0(0x4e5d)) != 0)
                    pChat->FUN_141abf6e0(FUN_1401d3200()->m_9190.FUN_140ec2b60(), 1);
                FUN_140aa6d40()->FUN_141b0ce20(0x11, 0);
                FUN_141b16580(kPayload.m_38);
            }
        }
    }
        break;
    case 0:
        DAT_143ab2958 = kPayload.m_08;
        DAT_143ab2960 = kPayload.m_10;
        DAT_143ab2968 = kPayload.m_18;
        DAT_143ab3308 = kPayload.m_20;
        break;
    case 4:
    {
        if (kPayload.m_40 != 1)
            return;
        DAT_143ab3308.insert(kPayload.m_20.begin(), kPayload.m_20.end());
        if (FUN_140166410()->FUN_14036d570(0xfb))
        {
            UIAdventureLevelDialog* pDlg = Unk_SSGGetDialog<UIAdventureLevelDialog>(0x4f67);
            if (pDlg == 0)
                return;
            pDlg->FUN_140ba31c0();
            Unk_SSGDlg4e28* pMenu = FUN_140938b90(0x4e28);
            if (pMenu == 0)
                return;
            pMenu->FUN_141938ae0(0x4f67, 0);
        }
        else
        {
            UIAdventureLevelOldDialog* pOld = Unk_SSGGetDialog<UIAdventureLevelOldDialog>(0x4f87);
            if (pOld == 0)
                return;
            pOld->FUN_140ba5a70();
            Unk_SSGDlg4e28* pMenu = FUN_140938b90(0x4e28);
            if (pMenu == 0)
                return;
            pMenu->FUN_141938ae0(0x4f87, 0);
        }
        return;
    }
    case 7:
    {
        if (!FUN_140166410()->FUN_14036d570(0xfb))
            return;
        packet.FUN_140715280(nOffset);
        CSAdventureLevelMission kMission;
        kMission.FUN_1407a90e0(packet);
        DAT_143ab3318.clear();
        const std::map<unsigned int, CAdventureLevelMissionData*>& missions = kMission.GetMissions();
        for (std::map<unsigned int, CAdventureLevelMissionData*>::const_iterator it = missions.begin(); it != missions.end(); ++it)
        {
            CAdventureLevelMissionData kData;
            kData.m_progress = it->second->m_progress;
            kData.m_complete = it->second->m_complete;
            DAT_143ab3318.insert(std::make_pair(it->first, kData));
        }
        UIAdventureLevelDialog* pDlg = Unk_SSGGetDialog<UIAdventureLevelDialog>(0x4f67);
        if (pDlg == 0)
            return;
        pDlg->FUN_140ba3200();
        Unk_SSGDlg4e28* pMenu = FUN_140938b90(0x4e28);
        if (pMenu == 0)
            return;
        pMenu->FUN_141938ae0(0x4f67, 0);
    }
        break;
    case 6:
    {
        if (!FUN_140166410()->FUN_14036d570(0xfb))
            return;
        packet.FUN_140715280(nOffset);
        CSAdventureLevelMission kMission;
        kMission.FUN_1407a90e0(packet);
        if (kMission.m_0c != 1)
            return;
        DAT_143ab3318.clear();
        const std::map<unsigned int, CAdventureLevelMissionData*>& missions = kMission.GetMissions();
        for (std::map<unsigned int, CAdventureLevelMissionData*>::const_iterator it = missions.begin(); it != missions.end(); ++it)
        {
            CAdventureLevelMissionData kData;
            kData.m_progress = it->second->m_progress;
            kData.m_complete = it->second->m_complete;
            DAT_143ab3318.insert(std::make_pair(it->first, kData));
        }
        UIAdventureLevelDialog* pDlg = Unk_SSGGetDialog<UIAdventureLevelDialog>(0x4f67);
        if (pDlg == 0)
            return;
        pDlg->FUN_140ba3200();
    }
        break;
    }
    UIAdventureLevelExpBar* pBar = FUN_14125b160(0x4f66);
    if (pBar != 0)
        pBar->FUN_140ba6cf0(nGain);
}
MS2_REPLACE_METHOD(0x14173D4D0, CSceneStateGame, OnPrestige, 2295, 0xD65FBD22);

// @0x14173fc40
void CSceneStateGame::FUN_14173fc40(CInPacket& packet)
{
    int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned int nMin = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned int nUsed = static_cast<CInputStream&>(packet).vfunc_o8_3();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    MS2Ptr<Unk_SSGSkillRow> spRow = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
    if (spRow == 0)
        return;
    int nBaseId = spRow->FUN_1407e9b90();
    if (nBaseId != 0)
        nSkillId = nBaseId;
    unsigned int nPoint = pMyPC->FUN_141523bc0()->FUN_141768680(spRow.get());
    nPoint -= (std::min)(nPoint, nUsed);
    unsigned int nValue = nPoint;
    if (nPoint < nMin)
        nValue = nMin;
    if (nValue == 0)
        pMyPC->FUN_141523bc0()->FUN_141765e70(nSkillId);
    pMyPC->FUN_141523bc0()->FUN_141768530(nSkillId, nValue);
}
MS2_REPLACE_METHOD(0x14173fc40, CSceneStateGame, FUN_14173fc40, 459, 0x11D57B92);

// @0x141740280
bool CSceneStateGame::FUN_141740280(int nButton, const CMsgBoxData& data)
{
    __int64 nUid = data.FUN_141a02ed0(0, 0);
    const CStringW& strName = data.FUN_141a02fd0(1, CStringW());
    if (nButton == 0)
    {
        FUN_1418fd6c0(nUid);
        FUN_141740200(strName, 1);
    }
    else if (data.GetTimer().m_nButton != 0)
        FUN_141740200(strName, 6);
    else if (data.FUN_141a049d0())
        FUN_141740200(strName, 6);
    else
        FUN_141740200(strName, 2);
    return true;
}
MS2_REPLACE_METHOD(0x141740280, CSceneStateGame, FUN_141740280, 285, 0x7362E0DC);

// @0x1417403b0
static int FUN_1417403b0(const __int64& nValue, const int& nType, int& nOutType, __int64& nOutValue)
{
    if (nValue != 0)
    {
        nOutType = nType;
        nOutValue = nValue;
        return 1;
    }
    return 0;
}

// ---- w109: event dialog / misc handlers -------------------------------------------------------------------------
class UIStampEventDialog : public UIDialog { public: void FUN_140ed7ea0(); };
class UITimeRunEventDialog : public UIDialog { public: void FUN_140ee4570(int nMode); };
UITimeRunEventDialog* FUN_140cf8380(int nId);               // GetDialog<UITimeRunEventDialog>
UISnowmanEventDialog* FUN_140ce8450(int nId);               // GetDialog<UISnowmanEventDialog>
class Unk_SSGGameMenuDlg { public: void FUN_141938ae0(int nId, int n); };

// @0x141735dd0
void CSceneStateGame::OnEventReward(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0 || nMode == 1)
    {
        Unk_SSGChatDialog* pChat = FUN_140938cd0(0x4e5d);
        if (pChat != 0)
        {
            int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
            for (int i = 0; i < nCount; i++)
            {
                int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                int nValue = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
                pChat->FUN_141abf6e0(nItemId, nValue);
            }
        }
        UIStampEventDialog* pStamp = Unk_SSGGetDialog<UIStampEventDialog>(0x4f33);
        if (pStamp != 0)
            pStamp->FUN_140ed7ea0();
        Unk_SSGGameMenuDlg* pMenu = (Unk_SSGGameMenuDlg*)FUN_140938b90(0x4e28);
        if (pMenu != 0)
            pMenu->FUN_141938ae0(0x4f33, 0);
    }
    else if (nMode == 4 || nMode == 3)
    {
        Unk_SSGChatDialog* pChat = FUN_140938cd0(0x4e5d);
        if (pChat != 0)
        {
            int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nValue = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
            pChat->FUN_141abf6e0(nItemId, nValue);
        }
        UITimeRunEventDialog* pDlg = FUN_140cf8380(0x4f43);
        if (pDlg != 0)
            pDlg->FUN_140ee4570(nMode);
    }
    else if (nMode > 6 && nMode < 10)
    {
        UIGalleryEventDialog* pDlg = Unk_SSGGetDialog<UIGalleryEventDialog>(0x4f59);
        if (pDlg != 0)
            pDlg->FUN_140c17200(nMode, (Unk_GalleryPacket*)&packet);
    }
    else if (nMode > 11 && nMode < 14)
    {
        UISnowmanEventDialog* pDlg = FUN_140ce8450(0x4f5d);
        if (pDlg != 0)
            pDlg->FUN_140e96c50(nMode, packet);
    }
    else if (nMode == 0x17)
    {
        Unk_SSGChatDialog* pChat = FUN_140938cd0(0x4e5d);
        if (pChat != 0)
        {
            int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
            for (int i = 0; i < nCount; i++)
            {
                int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                int nValue = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
                pChat->FUN_141abf6e0(nItemId, nValue);
            }
        }
    }
    else if (nMode > 0x18 && nMode < 0x1c)
    {
        UILongTermAttendGiftDialog* pDlg = Unk_SSGGetDialog<UILongTermAttendGiftDialog>(0x4f98);
        if (pDlg != 0)
            pDlg->FUN_140c6bac0(nMode, packet);
    }
}
MS2_REPLACE_METHOD(0x141735dd0, CSceneStateGame, OnEventReward, 1120, 0xD1CA309C);

// 0x11f: field war announcement (side popup talk by Neirin).
class Unk_SSGFieldWarInfo : public CPtred { public: char m_pad_18[0x2c - 0x18]; unsigned int m_nId; };
MS2_CHECK_OFFSET(Unk_SSGFieldWarInfo, m_nId, 0x2c);
class Unk_SSGFieldWarTable { public: MS2Ptr<Unk_SSGFieldWarInfo> FUN_140382be0(int nId); };
Unk_SSGFieldWarTable* FUN_1414a5820();
class Unk_SSGSidePopupTalk { public: void FUN_140e879a0(MS2Ptr<SidePopupTalkParam> spParam); };
Unk_SSGSidePopupTalk* FUN_1413868b0(int nId);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);

// @0x14173dfd0
void CSceneStateGame::FUN_14173dfd0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        MS2Ptr<Unk_SSGFieldWarInfo> spInfo = FUN_1414a5820()->FUN_140382be0(nId);
        if (spInfo == 0)
            return;
        MS2Ptr<SidePopupTalkParam> spParam(new SidePopupTalkParam);
        spParam->m_nKind = 4;
        spParam->m_strIcon = "Neirin_normal";
        spParam->m_nNpcId = 30000;
        spParam->m_strScript = s_systemFieldWar;
        spParam->m_strText = FUN_1405c2690(L"s_fieldwar_sidepopup_script", FUN_1401a9d70()->FUN_141811980(3, spInfo->m_nId));
        spParam->m_str70 = FUN_1401a9d70()->FUN_141811980(3, spInfo->m_nId);
        spParam->m_str68 = StringFormat("{0}{1:08d}.png", FUN_1401d31f0()->m_strd0, spInfo->m_nId);
        spParam->m_str78 = StringFormat("{0}", nUid);
        Unk_SSGSidePopupTalk* pUi = FUN_1413868b0(0x4f57);
        if (pUi != 0)
            pUi->FUN_140e879a0(spParam);
    }
}
MS2_REPLACE_METHOD(0x14173dfd0, CSceneStateGame, FUN_14173dfd0, 1121, 0x0D03AAC3);

// The online patch manager (FUN_140a87680) owns the text filter at +0xd0.
class Unk_SSGTextFilter { public: CStringW FUN_14087ede0(const CStringW& strText); };
class Unk_SSGPatchMgr
{
public:
    Unk_SSGTextFilter* FUN_141747b40() { return &m_kFilter; }
    Unk_SSGTextFilter* FUN_140a87690();                     // the filter at +0x8
private:
    char m_pad0[0xd0];
    Unk_SSGTextFilter m_kFilter;                            // +0xd0
};
Unk_SSGPatchMgr* FUN_140a87680();
void FUN_141275360(const CStringW& strMsg, int nType, int nArg);

// @0x141738430
// 0xe8: npc talk: a system notice, npc model/script changes and the side popup talk.
void CSceneStateGame::FUN_141738430(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        CStringW strMsg = FUN_140a87680()->FUN_141747b40()->FUN_14087ede0(static_cast<CInputStream&>(packet).vfunc_o8_8());
        int nArg = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_141275360(strMsg, 0xc, nArg);
        FUN_1412751b0(strMsg, 0x14);
    }
    else if (nMode == 1)
    {
        int nObjId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CString strModel = static_cast<CInputStream&>(packet).vfunc_o8_6();
        Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nObjId);
        if (pNpc == 0)
            return;
        pNpc->FUN_141094f90(strModel);
    }
    else if (nMode == 2)
    {
        int nObjId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CString strScript = static_cast<CInputStream&>(packet).vfunc_o8_6();
        Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nObjId);
        if (pNpc == 0)
            return;
        pNpc->FUN_1410951d0(strScript);
    }
    else if (nMode == 3)
    {
        int nKind = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nNpcId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        CString strIcon = static_cast<CInputStream&>(packet).vfunc_o8_7();
        CString strSound = static_cast<CInputStream&>(packet).vfunc_o8_7();
        CString strScript = static_cast<CInputStream&>(packet).vfunc_o8_7();
        CStringW strText = static_cast<CInputStream&>(packet).vfunc_o8_8();
        Unk_SSGSidePopupTalk* pUi = FUN_1413868b0(0x4f57);
        if (pUi != 0)
        {
            MS2Ptr<SidePopupTalkParam> spParam(new SidePopupTalkParam);
            spParam->m_nKind = nKind;
            spParam->m_strName = strName;
            spParam->m_strIcon = strIcon;
            spParam->m_nNpcId = nNpcId;
            spParam->m_strText = FUN_140a87680()->FUN_141747b40()->FUN_14087ede0(strText);
            spParam->m_strSound = strSound;
            spParam->m_strScript = strScript;
            pUi->FUN_140e879a0(spParam);
        }
    }
}
MS2_REPLACE_METHOD(0x141738430, CSceneStateGame, FUN_141738430, 1684, 0x1D689E6E);

// The system notice record (decoder 0x1407a7d20 in unit_1407a4f20.cpp); its dtor is emitted here.
struct Unk_1407a7d20
{
    Unk_1407a7d20(CInPacket& in);
    unsigned char m_nKind;                                  // +0x00 4: notice, 5: forced logout
    unsigned m_nFlags;                                      // +0x04 where to show it
    CStringW m_strText;                                     // +0x08
    unsigned m_nArg;                                        // +0x10 (flag 0x10: the repeat count)
    ATL::CAtlArray<CString> m_aExtra;                       // +0x18 (dtor 0x1401641d0 = CAtlArray<CStringA>, fx18)
};
CStringW FUN_14083d340(CStringW strText);                   // expand the text macros
void FUN_1412753b0(const CStringW& strMsg, int nType, int nArg);
void FUN_141275400(const CStringW& strMsg, int nArg);
extern CStringW DAT_143ae79d8;                              // the maintenance exit message box tag

// @0x141728c20
// 0x71: system notices, shown in the places their flags select.
void CSceneStateGame::FUN_141728c20(CInPacket& packet)
{
    Unk_1407a7d20 kNotice(packet);
    int nKind = kNotice.m_nKind;
    if (nKind == 4)
    {
        unsigned nFlags = kNotice.m_nFlags;
        CStringW strText(kNotice.m_strText);
        strText = FUN_140a87680()->FUN_140a87690()->FUN_14087ede0(strText);
        int nArg = kNotice.m_nArg;
        if (nFlags & 2)
            return;
        if (nFlags & 0x20)
        {
            FUN_141276180(FUN_14016a600(strText, 0), "");
            return;
        }
        strText = FUN_14083d340(strText);
        if (nFlags & 4)
            FUN_1412751f0(strText, 6, 0);
        else if (nFlags & 0x10)
            FUN_1412753b0(strText, 9, nArg);
        else if (nFlags & 0x200)
        {
            int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
            FUN_141275400(strText, nValue);
        }
        else if (nFlags & 0x400)
            FUN_1412751f0(strText, 2, 1);
        if (nFlags & 1)
        {
            int nType = (nFlags & 0x100) ? 0x1d : 0x14;
            FUN_1412751b0(FUN_14028ee20(nFlags, strText), nType);
        }
        if (nFlags == 0)
            FUN_1412751b0(strText, 0x14);
        if (nFlags & 0x40)
            FUN_140d73aa0(strText, 0, 0, L"");
        else if (nFlags & 0x80)
        {
            FUN_140d73aa0(strText, 0, 0, DAT_143ae79d8);
            FUN_140d86260()->vfunc_58(0x289, 0);
        }
        if ((nFlags & 0x800) && FUN_140166440())
            FUN_140166440()->FUN_1401859c0(0xb, 0x2f, strText);
    }
    else if (nKind == 5)
    {
        unsigned nFlags = kNotice.m_nFlags;
        CStringW strText(kNotice.m_strText);
        if (nFlags == 0x40)
        {
            FUN_140714f90()->FUN_1415388a0();
            FUN_140aa6d30()->FUN_1417e25a0(0x6200009);
            FUN_140d73aa0(strText, 0, 0, L"");
        }
    }
}
MS2_REPLACE_METHOD(0x141728C20, CSceneStateGame, FUN_141728c20, 1567, 0x47A4AE53);

// The current snowman event context (FUN_1401c0d90()->FUN_14047d050()).
class Unk_SnowmanContext : public CPtred { public: char m_pad_18[0x40 - 0x18]; CStringW m_strName; };
MS2_CHECK_OFFSET(Unk_SnowmanContext, m_strName, 0x40);
CStringW FUN_140298ea0(CStringW strKey);                    // localized text for a string key

// @0x141736240
// 0xf9: promotion event rewards (Goldus, Pesca, Stefan, the snowman), listed in the reward notifier.
void CSceneStateGame::FUN_141736240(CInPacket& packet)
{
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned short nRank = static_cast<CInputStream&>(packet).vfunc_o8_2();
    unsigned int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int bNotice = static_cast<CInputStream&>(packet).vfunc_o8_1();
    CStringW strImage;
    CStringW strKey;
    switch (nType)
    {
    case 1:
        strImage = L"./Data/Resource/Image/Portrait/Npc/11000252_Goldus_P.png";
        strKey = L"s_goldus_promotion_reward";
        break;
    case 3:
        strImage = L"./Data/Resource/Image/Portrait/Npc/11000765_Musician4_P.png";
        strKey = L"s_stefan_promotion_reward";
        break;
    case 2:
        strImage = L"./Data/Resource/Image/Portrait/Npc/11000781_ToolMan1_P.png";
        strKey = L"s_pesca_promotion_reward";
        break;
    case 4:
    {
        MS2Ptr<Unk_SnowmanContext> spSnowman = FUN_1401c0d90()->FUN_14047d050();
        if (spSnowman.get() != 0)
        {
            strImage = StringFormat(L"./Data/Resource/Image/ETC/snow_{0}.png", spSnowman->m_strName);
            strKey = StringFormat(L"s_snowman_{0}_promotion_reward", spSnowman->m_strName);
            break;
        }
    }
    }

    Unk_SSGChatDialog* pDlg = FUN_140938cd0(0x4e5d);
    if (pDlg != 0)
    {
        for (size_t i = 0; i < nCount; i++)
        {
            int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nAmount = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
            if (nType != 0)
            {
                CStringW strText = FUN_1405c2690(strKey, FUN_1401a9d70()->FUN_141811980(1, nItemId));
                pDlg->FUN_141ac1580(strImage, strText, 1);
            }
            else
                pDlg->FUN_141abf6e0(nItemId, nAmount);
        }
        if (nType != 0 && nId != 0)
        {
            // Original bug: the inner strKey shadows the outer one and is copied before it is constructed.
            CStringW strKey = FUN_1405c2690(strKey, FUN_1401a9d70()->FUN_141812290(nId, nRank, "name"));
            pDlg->FUN_141ac1580(strImage, strKey, 1);
        }
        if (bNotice == 1)
        {
            CStringW strText = FUN_140298ea0(strKey);
            pDlg->FUN_141ac1580(strImage, strText, 1);
            FUN_1412751f0(strText, 0, 1);
        }
    }
}
MS2_REPLACE_METHOD(0x141736240, CSceneStateGame, FUN_141736240, 1588, 0x6A7CAA6F);

// 0x24: the housing cube stock (UGC map items).
class CUGCMapItem : public CPtred
{
public:
    CUGCMapItem();                                          // 0x140dfc1b0
    void FUN_140dfc280(int n);
    void SetItemId(int nItemId);
    void SetUid(__int64 nUid);
    void SetCount(__int64 nCount);
    void SetLook(MS2Ptr<CUgcItemLook> spLook);
    int m_n18;                                              // +0x18 (FUN_140dfc280)
    int m_nItemId;                                          // +0x1c
    __int64 m_nUid;                                         // +0x20
    __int64 m_nCount;                                       // +0x28
    MS2Ptr<CUgcItemLook> m_spLook;                          // +0x30
};
MS2_CHECK_SIZE(CUGCMapItem, 0x40);
class Unk_CubeStock
{
public:
    void FUN_140dfc4f0();                                   // clear
    void FUN_140dfc520(CUGCMapItem* pItem);                 // add
    void FUN_140dfc6e0(__int64 nUid);                       // remove
    MS2Ptr<CUGCMapItem> FUN_140dfc8f0(__int64 nUid);        // find
};
extern Unk_CubeStock DAT_143ab2e50;
void FUN_140893250(CUgcItemLook* pLook, CInputStream* pIn);  // read a UGC look

// @0x141716200
void CSceneStateGame::OnFurnishingInventory(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        DAT_143ab2e50.FUN_140dfc4f0();
    }
    else if (nMode == 1)
    {
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nCount = static_cast<CInputStream&>(packet).vfunc_o8_4();
        bool bHasLook = static_cast<CInputStream&>(packet).vfunc_o8_0();
        MS2Ptr<CUgcItemLook> spLook(0);
        if (bHasLook)
        {
            spLook.AssignRaw(new CUgcItemLook);
            FUN_140893250(spLook.operator->(), &static_cast<CInputStream&>(packet));
        }
        MS2Ptr<CUGCMapItem> spItem(new CUGCMapItem);
        spItem->SetItemId(nItemId);
        spItem->SetUid(nUid);
        spItem->SetCount(nCount);
        spItem->SetLook(spLook);
        DAT_143ab2e50.FUN_140dfc520(spItem.get());
    }
    else if (nMode == 2)
    {
        __int64 nUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        MS2Ptr<CUGCMapItem> spItem = DAT_143ab2e50.FUN_140dfc8f0(nUid);
        if (!spItem)
            return;
        DAT_143ab2e50.FUN_140dfc6e0(nUid);
    }
    else if (nMode == 3)
    {
        __int64 nUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CUGCMapItem> spItem = DAT_143ab2e50.FUN_140dfc8f0(nUid);
        if (!spItem)
            return;
        spItem->FUN_140dfc280(nValue);
    }
}
MS2_REPLACE_METHOD(0x141716200, CSceneStateGame, OnFurnishingInventory, 1144, 0x21D35F8C);

extern CString DAT_143ae7968;                               // the low-hp sound event name
extern CString DAT_143ae7970;

// @0x1417176b0
// MS2-FUNCTIONAL: the exe spills the world singleton to a temp slot before the actor lookup (one extra stack temp); everything else matches.
void CSceneStateGame::OnStat(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor == 0)
        return;
    __int64 aBefore[3][0x23];
    for (int i = 0; i < 0x23; i++)
    {
        for (int j = 0; j < 3; j++)
            aBefore[j][i] = pActor->FUN_141670990(j, i);
    }
    pActor->m_unk_1bc = nFlag;
    pActor->vfunc_90(&packet);
    __int64 nHp = pActor->FUN_141670a00(4);
    __int64 nMaxHp = pActor->FUN_141670a30(4);
    pActor->vfunc_74(nHp, nMaxHp);
    if (FUN_14096e160(pActor) == 0)
        return;
    int bHp = 0;
    int bSp = 0;
    int bEp = 0;
    int bOther = 0;
    __int64 aAfter[3][0x23];
    for (int i = 0; i < 0x23; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            aAfter[j][i] = pActor->FUN_141670990(j, i);
            if (aBefore[j][i] != aAfter[j][i])
            {
                if (i == 4)
                    bHp = 1;
                else if (i == 7)
                    bSp = 1;
                else if (i == 10)
                    bEp = 1;
                else
                    bOther = 1;
            }
        }
    }
    if (bHp != 0)
    {
        if (nHp > 0)
        {
            float fThreshold = nMaxHp * 0.3f;
            if (fThreshold <= aBefore[2][4] && fThreshold >= nHp)
                FUN_141276180(DAT_143ae7968, "");
            else if (nHp <= fThreshold)
                FUN_141276180(DAT_143ae7970, "");
            float fPercent = (float)nHp / nMaxHp * 100.0f;
            FUN_140d86260()->vfunc_55(fPercent);
        }
        else
        {
            FUN_140d86260()->vfunc_55(0);
        }
        FUN_140aa6d40()->FUN_141b0ce20(0, 0);
    }
    if (bSp != 0)
        FUN_140aa6d40()->FUN_141b0ce20(1, 0);
    if (bEp != 0)
        FUN_140aa6d40()->FUN_141b0ce20(2, 0);
    if (bOther != 0)
        FUN_140aa6d40()->FUN_141b0e050();
}
MS2_REPLACE_METHOD(0x1417176b0, CSceneStateGame, OnStat, 1160, 0xBADC93AA);

// 0x141746230: the level change notification (ctor/dtor are emitted in this unit; vfunc_1 lives in the notify unit).
class NotifyChangeMyLevel : public NotifyObject
{
public:
    NotifyChangeMyLevel(unsigned short nLevel, unsigned short nOldLevel) : m_nLevel(nLevel), m_nOldLevel(nOldLevel) {}
    virtual ~NotifyChangeMyLevel() = default;
    virtual CStringW vfunc_1();                             // 0x140db43d0
    unsigned short m_nLevel;                                // +0x18
    unsigned short m_nOldLevel;                             // +0x1a
};
MS2_CHECK_SIZE(NotifyChangeMyLevel, 0x20);
void FUN_141b16550(unsigned short nLevel);
UIExpBar* FUN_14125b200(int nId);                           // GetDialog<UIExpBar> (another unit's COMDAT)

// @0x14171aec0
// MS2-FUNCTIONAL: small residual code difference (the old 0x10 Unk_EffectQuery frame-size cause is fixed)
void CSceneStateGame::OnLevelUp(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    int nOldLevel = (unsigned short)pPC->vfunc_78();
    pPC->vfunc_131(nLevel);
    if (nLevel > nOldLevel)
    {
        Unk_EffectQuery query;
        query.m_strName = FUN_1401d31f0()->m_str328;
        query.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(pPC);
        if (pPC->FUN_1416764a0() != 0)
        {
            efd::SmartPointer<Ridee> spRidee(pPC->FUN_1416764a0());
            query.SetActor(spRidee->FUN_14123c580());
        }
        else
        {
            query.SetActor(pPC->FUN_14123c580());
        }
        Unk_SSGDlgInv* pInv = FUN_1405344f0(0x4e2d);
        if (pInv != 0)
            pInv->FUN_141999f60();
        Unk_SSGDlg4e28* pMenu = FUN_140938b90(0x4e28);
        if (pMenu != 0)
            pMenu->FUN_140ea5f80();
        FUN_1403ed280()->FUN_1411a4a00(&query);
    }
    Unk_SSGSkillBook* pBook = FUN_1416546d0(pPC);
    pBook->vfunc_4(nLevel);
    MyPC* pMyPC = FUN_1409613d0(pPC);
    if (pMyPC == 0)
        return;
    FUN_141b16550(nLevel);
    Unk_SSGChatDialog* pNotify = FUN_140938cd0(0x4e5d);
    if (pNotify != 0)
    {
        pNotify->FUN_141ac0210(pMyPC);
        if ((unsigned short)pMyPC->vfunc_78() >= 10 && nLevel > nOldLevel)
        {
            unsigned short nCap = FUN_1401d3200()->m_n9718 > FUN_1401d3200()->m_n971a ? FUN_1401d3200()->m_n9718 : FUN_1401d3200()->m_n971a;
            if (nLevel <= nCap)
            {
                if (FUN_1403ed2b0()->FUN_141adc940(0x4f2d) != 0)
                    pNotify->FUN_141ac14b0();
                FUN_1412751b0(FUN_14028b8e0(L"s_msg_skillbook_add_skillpoint"), 0x14);
            }
        }
    }
    FUN_140aa6d40()->FUN_141b0ce20(6, 0);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangeMyLevel((unsigned short)pMyPC->vfunc_78(), nOldLevel)));
    DAT_143ab2a90.FUN_140a66990(nLevel);
    UIExpBar* pBar = FUN_14125b200(0x4e27);
    if (pBar != 0)
        pBar->FUN_141932080(3);
}
MS2_REPLACE_METHOD(0x14171aec0, CSceneStateGame, OnLevelUp, 1199, 0xEAC30A37);

unsigned char FUN_14053f8c0(unsigned nItemId);              // the item id is a currency (no item record)

// @0x141711e70
void CSceneStateGame::OnFieldAddItem(CInPacket& packet)
{
    int nObjectId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nAmount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nOwnerUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    ATL::CAtlList<__int64> kOwners(10);
    kOwners.AddTail(nOwnerUid);
    Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nRarity = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    int bFlag1 = static_cast<CInputStream&>(packet).vfunc_o8_0();
    int bFlag2 = static_cast<CInputStream&>(packet).vfunc_o8_0();
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    efd::SmartPointer<CDropItem> spDrop = EE_NEW CDropItem(nType, nRarity);
    if (spDrop->FUN_14118d1c0(nObjectId, nItemId, nAmount, nA, nB, kOwners) == 0)
        return;
    spDrop->FUN_14118fe60(bFlag1);
    spDrop->FUN_14118fe80(bFlag2);
    if (!FUN_14053f8c0(nItemId))
    {
        spDrop->FUN_140b12380()->FUN_14052a040(nObjectId);
        spDrop->FUN_140b12380()->FUN_140524eb0(static_cast<CInputStream&>(packet));
    }
    kPos.z += 70.0f;
    spDrop->vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
    if (pWorld->FUN_141bbb1e0(spDrop, 0, 1) == 0)
        return;
}
MS2_REPLACE_METHOD(0x141711e70, CSceneStateGame, OnFieldAddItem, 1221, 0x738FBD8D);

extern CString DAT_143ae7990;                               // the pet removal sound name
extern CString DAT_143ae7988;                               // the pet summon sound name
bool FUN_14028d470(float a, float b);                       // approx equal

// @0x14171a2e0
void CSceneStateGame::FUN_14171a2e0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    CPet* pObj = pWorld->FUN_141bd13a0(nId);
    if (pObj == 0)
        return;
    int n = pObj->FUN_141093270()->m_n60;
    if (n != 0)
        pObj->vfunc_40(1.0f, 0.0f, 0.0f, 0.5f);
    pObj->FUN_1410932c0(0);
    pWorld->FUN_141bbbcf0(nId, 1);
    GameObject* pTarget = pObj->FUN_140b10320();
    if (pTarget != 0 && pObj->vfunc_127() != 0)
    {
        Unk_SSGXform xf;
        FUN_140a332d0(&xf);
        xf.m_fScale = 1.0f;
        Unk_SSGNiPt3 pos(pTarget->vfunc_18());
        FUN_14097faa0(&xf.m_translate, pos);
        Unk_SSGRot rot;
        FUN_140a33240(&rot, &DAT_143a09600);
        xf.m_rotate = rot;
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/system"), CString(DAT_143ae7990), CString(""), 1, &xf, 1.0f, 0);
    }
}
MS2_REPLACE_METHOD(0x14171a2e0, CSceneStateGame, FUN_14171a2e0, 765, 0x54213933);

extern CString DAT_143ae7998;                               // the pet sound on the owner's state change
// @0x1417215a0
void CSceneStateGame::OnTombstone(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
    bool bPet = static_cast<CInputStream&>(packet).vfunc_o8_0();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    pPC->FUN_14165d300(nA, nB, nC);
    if (bPet)
    {
        CPet* pPet = static_cast<CPet*>(pPC->FUN_141676a10());
        if (pPet != 0)
        {
            pPet->vfunc_59(1, 0, 0x11, 0);
            GameObject* pOwner;
            if (pPet->vfunc_127() != 0 && (pOwner = pPet->FUN_140b10320()) != 0)
            {
                Unk_SSGXform xf;
                FUN_140a332d0(&xf);
                xf.m_fScale = 1.0f;
                Unk_SSGNiPt3 pos(pOwner->vfunc_18());
                FUN_14097faa0(&xf.m_translate, pos);
                Unk_SSGRot rot;
                FUN_140a33240(&rot, &DAT_143a09600);
                xf.m_rotate = rot;
                FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/system"), CString(DAT_143ae7998), CString(""), 1,
                    &xf, 1.0f, 0);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1417215a0, CSceneStateGame, OnTombstone, 919, 0xDCE8365B);

// Packet 0x5a: a pet is summoned (field add).
// @0x141719a60
void CSceneStateGame::OnFieldAddPet(CInPacket& packet)
{
    int nObjId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nNpcId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nLevel = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_StreamPoint kDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
    float fScale = static_cast<CInputStream&>(packet).vfunc_o8_5();
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    kPos.z += 4.0f;
    efd::SmartPointer<CPet> spPet = new (efd::MemHint(efd::MemHint::NONE)) CPet;
    spPet->FUN_14123c5a0(nObjId);
    spPet->vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
    spPet->vfunc_21(reinterpret_cast<efd::Point3&>(kDir));
    spPet->FUN_140b10210(nLevel);
    spPet->FUN_141094f20(nValue);
    if (spPet->vfunc_124(nNpcId) == 0)
        return;
    if (!FUN_14028d470(fScale, 1.0f))
        spPet->SetScaleAC(fScale);
    spPet->vfunc_90(&packet);
    spPet->FUN_141094790(static_cast<CInputStream&>(packet).vfunc_o8_4());
    spPet->FUN_14174a560(static_cast<CInputStream&>(packet).vfunc_o8_1());
    spPet->FUN_14174a580(static_cast<CInputStream&>(packet).vfunc_o8_2());
    spPet->FUN_140b10f90(static_cast<CInputStream&>(packet).vfunc_o8_2());
    spPet->FUN_14174a4f0(static_cast<CInputStream&>(packet).vfunc_o8_3());
    spPet->FUN_140b10c80(static_cast<CInputStream&>(packet).vfunc_o8_8());
    if (pWorld->FUN_141bbb1e0(spPet, 0, 1) == 0)
        return;
    MyPC* pMyPC = pWorld->FUN_141bd0cc0();
    GameObject* pOwner = spPet->FUN_140b10320();
    if (pMyPC != 0 && pMyPC == pOwner)
    {
        FUN_140535320()->FUN_140c8b410()->FUN_140c88100();
        if (pMyPC->FUN_14166cb00(1))
            spPet->FUN_14166ca20(1);
    }
    if (pOwner != 0 && spPet->vfunc_127() != 0)
    {
        Unk_SSGXform xf;
        FUN_140a332d0(&xf);
        xf.m_fScale = 1.0f;
        Unk_SSGNiPt3 pos(pOwner->vfunc_18());
        FUN_14097faa0(&xf.m_translate, pos);
        Unk_SSGRot rot;
        FUN_140a33240(&rot, &DAT_143a09600);
        xf.m_rotate = rot;
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/system"), CString(DAT_143ae7988), CString(""), 1, &xf, 1.0f, 0);
    }
}
MS2_REPLACE_METHOD(0x141719A60, CSceneStateGame, OnFieldAddPet, 2169, 0xA7D32A68);

// A special (event) npc announced by packet 0x?? (boxed in TPtredDummy<SpecialNPCInfo>; its unit is near 0x14092c0a0).
struct SpecialNPCInfo
{
    SpecialNPCInfo();                                       // 0x14092c0a0
    void FUN_14092c190(CInputStream& in);                   // read
    int m_nNpcId;                                           // +0x00
    unsigned m_nFieldId;                                    // +0x04
    short m_n08;                                            // +0x08
    __int64 m_n10;                                          // +0x10
    int m_n18;                                              // +0x18
};
MS2_CHECK_SIZE(SpecialNPCInfo, 0x20);
MS2Ptr<Unk_SSGNpcData> FUN_1406cd330(int nNpcId);           // the npc table row
class Unk_SSGFieldInfo : public CPtred { public: char m_pad_18[0x21 - 0x18]; bool m_b21; };
class Unk_SSGFieldTable { public: MS2Ptr<Unk_SSGFieldInfo> FUN_141b978e0(unsigned nFieldId); };
Unk_SSGFieldTable* FUN_140cb17d0();
class Unk_SSGAdvCfg { public: int FUN_14125c5d0(int nNpcId, int* pA, int* pB); };
class Unk_SSGSpecialNpcUI { public: virtual void vfunc_0(); virtual void vfunc_1(SpecialNPCInfo* pInfo, int nA, int nB); };
Unk_SSGSpecialNpcUI* FUN_140e898d0();
bool FUN_140930b10();

// @0x141733b30
void CSceneStateGame::FUN_141733b30(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        Unk_BmBoxPtr<SpecialNPCInfo> spInfo(Unk_BmNewTag(0));
        spInfo->FUN_14092c190(static_cast<CInputStream&>(packet));
        MS2Ptr<Unk_SSGNpcData> spNpc = FUN_1406cd330(spInfo->m_nNpcId);
        if (!spNpc)
            return;
        if (!spNpc->m_b8c)
            return;
        MS2Ptr<Unk_SSGFieldInfo> spField = FUN_140cb17d0()->FUN_141b978e0(spInfo->m_nFieldId);
        if (spField == 0)
            return;
        if (!spField->m_b21)
            return;
        if (DAT_143ab3058.FUN_140408410(&spInfo->m_nFieldId) == -1)
            return;
        if (FUN_140930b10())
            return;
        int nA = 2;
        int nB = 0;
        if (FUN_1409a8b10()->FUN_140b123b0()->FUN_14125c5d0(spInfo->m_nNpcId, &nA, &nB) == 0)
            return;
        FUN_140e898d0()->vfunc_1(spInfo.get(), nA, nB);
    }
}
MS2_REPLACE_METHOD(0x141733b30, CSceneStateGame, FUN_141733b30, 768, 0x4F3DB91A);

// ---- 0x69: UGC housing (cube placement, house settings, save slots) ---------------------------------------------
#include "ms2/placeholder/userugcmapinfo.h"
// The weapon data of a cube object (RTTI ObjectWeaponInfo, 0x58 bytes; ctor 0x1408b45b0).
class ObjectWeaponInfo
{
public:
    void* m_unk_00[3];
    int m_n18;
    int m_n1c;                                              // +0x1c the holder's value written by 0x69 mode 0x11
    void* m_unk_20[7];
};
MS2_CHECK_SIZE(ObjectWeaponInfo, 0x58);
extern template Unk_PayloadPtr<NoticeCubeInfo>::Unk_PayloadPtr(int);
extern template Unk_PayloadPtr<NoticeCubeInfo>::Unk_PayloadPtr(const Unk_PayloadPtr<NoticeCubeInfo>& value);
extern template ObjectWeaponInfo* Unk_PayloadPtr<ObjectWeaponInfo>::operator->() const;
// Unk_BmPtr<UserUGCMapInfo>: the raw-pointer ctor, dtor, operator-> and operator== are ICF copies outside the unit.
extern template Unk_BmPtr<UserUGCMapInfo>::Unk_BmPtr(UserUGCMapInfo* p);
extern template Unk_BmPtr<UserUGCMapInfo>::~Unk_BmPtr();
extern template UserUGCMapInfo* Unk_BmPtr<UserUGCMapInfo>::operator->() const;
extern template bool Unk_BmPtr<UserUGCMapInfo>::operator==(UserUGCMapInfo* p) const;
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStringId, IMessageListener* pListener, CStringW strTag);
// The UGC event dispatcher (FUN_140bc09f0; UIUGCEventListener registry): slots 5..7 notify the listeners.
class Unk_SSGUgcEvents
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();                                 // build mode started
    virtual void vfunc_6();                                 // build mode ended
    virtual void vfunc_7(int bChanged);                     // the house info was refreshed
};
Unk_SSGUgcEvents* FUN_140bc09f0();
class Unk_SSGTaxiTable { public: bool FUN_14085f730(int nMapId); };
Unk_SSGTaxiTable* FUN_1409f24a0();
class Unk_SSGHouseCfg { public: void FUN_141262180(); void FUN_141262650(); void FUN_141261e90(int n); };
int FUN_14151f6e0();                                        // messageboxqueue.cpp
void FUN_140ee8190(CInPacket& packet);
void FUN_140ee83f0(CInPacket& packet);
class Unk_SSGHomeMenu { public: void FUN_140b682c0(unsigned char n); void FUN_140b682f0(unsigned char n); void FUN_140b683f0(unsigned char n); };
Unk_SSGHomeMenu* FUN_140b6a040();
class UIHomeResizeDialog : public UIDialog { public: void FUN_140c2bf40(); void FUN_140c2bf70(); };
class UIUGCHousingPointDialog : public UIHomeResizeDialog { public: void FUN_140fae0d0(); };
UIUGCHousingPointDialog* FUN_140ef4af0(int nId);            // GetDialog<UIUGCHousingPointDialog>
UIUGCCubePaletteDialog* FUN_140ef4a50(int nId);
UIHomeSaveSlotDialog* FUN_140c2b5c0(int nId);
Unk_Int3 FUN_1408a0400(int nPacked);                        // unpack a cube coordinate
extern CString DAT_143ae79a0;                               // housing sound event names
extern CString DAT_143ae79a8;
extern CString DAT_143ae79b0;
extern CString DAT_143ae79b8;
extern CString DAT_143ae79c0;
extern CString DAT_143ae79c8;
extern CString DAT_143ae79d0;
extern bool DAT_143ab2857;
extern unsigned short DAT_143ab291c;
extern bool DAT_143ab291e;
extern __int64 DAT_143ab2928;
extern __int64 DAT_143ab2930;
extern __int64 DAT_143ab2938;
extern unsigned short DAT_143ab2940;
extern __int64 DAT_143ab2948;
extern ATL::CAtlArray<unsigned int> DAT_143ab32b8;
// A (cube id, value) pair of the house set 0x143ab32d8 (ctor 0x1409ed810).
struct Unk_SSGHouseKey
{
    Unk_SSGHouseKey();   // 0x1409ed810, out of range
    unsigned int m_nA;
    unsigned int m_nB;
};
inline bool operator<(const Unk_SSGHouseKey& a, const Unk_SSGHouseKey& b)
{
    if (a.m_nA != b.m_nA)
        return a.m_nA < b.m_nA;
    return a.m_nB < b.m_nB;
}
// The set's members live in another unit (clear 0x140581e40, end 0x140582470, find 0x140583270, insert 0x140569330).
// Declared as explicit specializations so this TU calls them instead of emitting look-alikes of the unit's other set.
typedef std::_Tree<std::_Tset_traits<Unk_SSGHouseKey, std::less<Unk_SSGHouseKey>, std::allocator<Unk_SSGHouseKey>, false> > Unk_SSGHouseTree;
template <> Unk_SSGHouseTree::iterator Unk_SSGHouseTree::find(const Unk_SSGHouseKey& kKey);
template <> Unk_SSGHouseTree::iterator Unk_SSGHouseTree::end() noexcept;
template <> void Unk_SSGHouseTree::clear() noexcept;
template <> template <> Unk_SSGHouseTree::_Pairib Unk_SSGHouseTree::insert<false, 0>(const Unk_SSGHouseKey& kKey);
extern std::set<Unk_SSGHouseKey> DAT_143ab32d8;

// @0x141723670
// MS2-FUNCTIONAL: identical instructions; the exe swaps two dword stack slots (mode 2 nError at +0x90, the mode 5 `nFlag == 0` temp at +0x128) and shifts the four loop counters by 4
void CSceneStateGame::OnResponseCube(CInPacket& packet)
{
    efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    switch (nMode)
    {
    case 0:
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            return;
        if (pPC->FUN_1416595d0() != 0)
        {
            Unk_PCCubeCraft* pCraft = pPC->GetCubeCraft();
            if (pCraft != 0)
                pCraft->FUN_1410aa550(nValue);
        }
    }
        break;
    case 1:
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        CubeItemInfo info(packet);
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            return;
        if (pPC->FUN_1416595d0() != 0)
        {
            Unk_PCCubeCraft* pCraft = pPC->GetCubeCraft();
            if (pCraft != 0)
                pCraft->FUN_1410aa5c0(&info);
        }
    }
        break;
    case 2:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
            __int64 nC = static_cast<CInputStream&>(packet).vfunc_o8_4();
            __int64 nCharId = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spService->FUN_1410c4240(nA, nB, strName, nC, nCharId);
            if (nCharId == DAT_143ab2820)
            {
                COutPacket out(0x37, 0);
                out.COutPacket::vfunc_o10_1(0x15);
                out.COutPacket::vfunc_o10_8(strName);
                FUN_140710590(out);
            }
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 4:
        if (pMyPC != 0)
        {
            FUN_140bc09f0()->vfunc_5();
            FUN_141276180(DAT_143ae79a0, "");
            FUN_141276180(DAT_143ae79a8, "");
            FUN_141275260(0x6f1, 3, 1);
        }
        break;
    case 5:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
            spService->FUN_1410c44b0(nA, nB, nFlag == 0);
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 7:
    {
        int nReason = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        int bFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (nReason == 0x75)
            FUN_141275260(0x6c1, 3, 1);
        else
            FUN_141275260(0x6f2, 3, 1);
        if (pMyPC != 0)
        {
            FUN_140bc09f0()->vfunc_6();
            FUN_141276180(DAT_143ae79b0, "");
            int nValue = 0;
            if (bFlag != 0)
                nValue = *FUN_1401d3200()->m_3578.FUN_1402056b0();
        }
    }
        break;
    case 0xa:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (nCharId != 0 && pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
            {
                Unk_PCCubeCraft* pCraft = pMyPC->FUN_141530290();
                if (pCraft != 0)
                    pCraft->FUN_1410aa380(false);
                FUN_141276180(DAT_143ae79b8, "");
            }
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nPacked = static_cast<CInputStream&>(packet).vfunc_o8_3();
            Unk_Int3 kPos = FUN_1408a0400(nPacked);
            __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
            CubeItemInfo info(packet);
            bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_1() == 0 ? false : true;
            float fRot = static_cast<CInputStream&>(packet).vfunc_o8_5();
            int nD = static_cast<CInputStream&>(packet).vfunc_o8_3();
            Unk_PayloadPtr<NoticeCubeInfo> spNotice(0);
            int nHasNotice = static_cast<CInputStream&>(packet).vfunc_o8_1();
            if (nHasNotice == 1)
            {
                CStringW strText = static_cast<CInputStream&>(packet).vfunc_o8_8();
                int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
                spNotice = new NoticeCubeInfo;
                spNotice->FUN_1408b4970(strText, nType);
            }
            spService->FUN_1410c4850(nItemUid, kPos, info, fRot, nA, nB, bFlag, nC, nD, spNotice);
        }
        else
        {
            int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
            {
                Unk_PCCubeCraft* pCraft = pMyPC->FUN_141530290();
                if (pCraft != 0)
                    pCraft->FUN_1410aa590();
                MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pPC != 0)
                {
                    if (pPC->FUN_141659690() != 0)
                    {
                        FUN_141275260(0x6c9, 1, 1);
                        FUN_141276180(DAT_143ae79c0, "");
                    }
                    else
                        spService->FUN_1410d6590(nError);
                }
            }
        }
    }
        break;
    case 0xc:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nPacked = static_cast<CInputStream&>(packet).vfunc_o8_3();
            bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_1() == 1;
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
            {
                Unk_PCCubeCraft* pCraft = pMyPC->FUN_141530290();
                if (pCraft != 0)
                    pCraft->FUN_1410aa380(true);
                FUN_141276180(DAT_143ae79c8, "");
            }
            Unk_Int3 kPos = FUN_1408a0400(nPacked);
            spService->FUN_1410c4b50(kPos, bFlag);
        }
        else
        {
            int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
            {
                if (pMyPC->FUN_141659690() != 0)
                {
                    FUN_141275260(0x6c9, 1, 1);
                    FUN_141276180(DAT_143ae79c0, "");
                }
                else
                    spService->FUN_1410d6590(nError);
            }
        }
    }
        break;
    case 0xe:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
                FUN_141276180(DAT_143ae79d0, "");
            int nPacked = static_cast<CInputStream&>(packet).vfunc_o8_3();
            Unk_Int3 kPos = FUN_1408a0400(nPacked);
            float fRot = static_cast<CInputStream&>(packet).vfunc_o8_5();
            spService->FUN_1410c4d80(kPos, fRot);
        }
        else
        {
            int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
            {
                if (pMyPC->FUN_141659690() != 0)
                {
                    FUN_141275260(0x6c9, 1, 1);
                    FUN_141276180(DAT_143ae79c0, "");
                }
                else
                    spService->FUN_1410d6590(nError);
            }
        }
    }
        break;
    case 0xf:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
            {
                Unk_PCCubeCraft* pCraft = pMyPC->FUN_141530290();
                if (pCraft != 0)
                    pCraft->FUN_1410aa380(false);
                FUN_141276180(DAT_143ae79b8, "");
            }
            int nPacked = static_cast<CInputStream&>(packet).vfunc_o8_3();
            Unk_Int3 kPos = FUN_1408a0400(nPacked);
            __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
            CubeItemInfo info(packet);
            bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_1() == 0 ? false : true;
            float fRot = static_cast<CInputStream&>(packet).vfunc_o8_5();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            spService->FUN_1410c4e20(nItemUid, kPos, info, fRot, bFlag, nA, nB);
        }
        else
        {
            int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
            {
                if (pMyPC->FUN_141659690() != 0)
                {
                    FUN_141275260(0x6c9, 1, 1);
                    FUN_141276180(DAT_143ae79c0, "");
                }
                else
                    spService->FUN_1410d6590(nError);
            }
        }
    }
        break;
    case 0x11:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nCubeId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
            MS2Ptr<Cube> spCube(spService->FUN_1410b8b00(nCubeId));
            if (spCube.get() != 0 ? true : false)
            {
                if (spCube->weapon.get() != 0)
                {
                    spCube->weapon->m_n1c = nValue;
                    spService->FUN_1410caf20(spCube.get(), nValue);
                    PC* pPC = FUN_140974230(FUN_1403ed2d0()->FUN_141bd1200(nId));
                    if (pPC == 0)
                        return;
                    pPC->FUN_14165f1f0(nA, 1);
                }
            }
        }
        else
        {
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
                spService->FUN_1410d6590(nError);
        }
    }
        break;
    case 0x12:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            PC* pPC = FUN_140974230(FUN_1403ed2d0()->FUN_141bd1200(nId));
            if (pPC == 0)
                return;
            pPC->FUN_14165f1f0(0, 0);
        }
        else
        {
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
                spService->FUN_1410d6590(nError);
        }
    }
        break;
    case 0x1b:
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (unsigned int i = 0; i < nCount; i++)
        {
            int nCubeId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
            MS2Ptr<Cube> spCube(spService->FUN_1410b8b00(nCubeId));
            if (spCube.get() != 0)
                spService->FUN_1410caf20(spCube.get(), nValue);
        }
    }
        break;
    case 0x14:
    {
        int nResult = 0;
        Unk_BmPtr<UserUGCMapInfo> spInfo(Unk_BmNewTag(0));
        spInfo->FUN_1408b4220(packet, &nResult);
        if (pMyPC != 0)
        {
            if (pMyPC->FUN_14123c580() == spInfo->m_n18)
            {
                int bChanged = 0;
                Unk_BmPtr<UserUGCMapInfo> spCur(pMyPC->FUN_141523c50());
                if (spCur == 0)
                {
                    spCur.AssignRaw(new UserUGCMapInfo);
                    pMyPC->FUN_141524880(spCur);
                }
                else if (pMyPC->FUN_141527e00() == 0)
                {
                    if (spCur->m_n30 != spInfo->m_n30)
                        bChanged = 1;
                }
                spService->FUN_1410d5ae0(1);
                spCur->FUN_1408b40d0(spInfo);
                FUN_140bc09f0()->vfunc_7(bChanged);
                if (pMyPC->FUN_141527e00() == 0)
                {
                    if (FUN_14151f6e0() != 0)
                        FUN_1409a8b10()->FUN_140a46860()->FUN_141262180();
                    FUN_1409a8b10()->FUN_140a46860()->FUN_141262650();
                }
                if (pMyPC->FUN_141527e00() != 0 && pMyPC->FUN_1416595d0() != 0)
                    pMyPC->FUN_141530200();
                if (FUN_1409f24a0()->FUN_14085f730(DAT_143ab2870))
                    FUN_141739450(nResult != 0 ? false : true);
            }
        }
    }
        break;
    case 0x15:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            __int64 nOwner = static_cast<CInputStream&>(packet).vfunc_o8_4();
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
            if (spService->FUN_1410c3180() == nOwner)
            {
                spService->FUN_1410c3220(strName);
                Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
                if (pDlg != 0)
                    pDlg->FUN_1412c5f00();
                spService->FUN_1410c51d0(nA, nB, strName);
            }
        }
        else
        {
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
                spService->FUN_1410d6590(nError);
        }
    }
        break;
    case 0x1d:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            CStringW strDesc = static_cast<CInputStream&>(packet).vfunc_o8_8();
            spService->FUN_1410c32b0(strDesc);
            Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
            if (pDlg != 0)
                pDlg->FUN_1412c5c30();
        }
        else
        {
            int nCharId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (pMyPC != 0 && pMyPC->FUN_14123c580() == nCharId)
                spService->FUN_1410d6590(nError);
        }
    }
        break;
    case 0x18:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
            break;
        spService->FUN_1410d6590(nError);
    }
        break;
    case 0x16:
    {
        int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nC = static_cast<CInputStream&>(packet).vfunc_o8_1();
        __int64 nD = static_cast<CInputStream&>(packet).vfunc_o8_4();
        spService->FUN_1410c7a50(nA, nB, nC, nD);
    }
        break;
    case 9:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
            break;
        spService->FUN_1410d6590(nError);
    }
        break;
    case 0x19:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            __int64 nCharId = static_cast<CInputStream&>(packet).vfunc_o8_4();
            __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
            if (DAT_143ab2820 == nCharId)
                DAT_143ab2920 = nValue;
            Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
            if (pDlg != 0)
                pDlg->FUN_1412c6070();
            FUN_141275260(0xb13, 1, 1);
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x1a:
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0, 0xb10,
                static_cast<Unk_SSGMyPCView*>(static_cast<PCBase*>(pPC)), L"userOutNotice");
            if (spBox.get() != 0)
            {
                spBox->FUN_141a01700(0xb12, 0, 0);
                spBox->FUN_141a02460(1);
                spBox->FUN_141a02480(1);
                spBox->FUN_141a024a0(0);
                FUN_140d73c60(spBox);
            }
        }
    }
        break;
    case 0x1c:
    {
        int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spService->FUN_1410c3410(nA);
        spService->FUN_1410c3450(nB);
        Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
        if (pDlg != 0)
            pDlg->FUN_1412c6070();
    }
        break;
    case 0x47:
    {
        int nType = static_cast<CInputStream&>(packet).vfunc_o8_3();
        if (nType == 1 || nType == 2)
            FUN_1412751f0(FUN_14028de60(0xb89), 1, 1);
        else if (nType == 3)
            FUN_1412751f0(FUN_14028de60(0xb8a), 1, 1);
        else if (nType == 4)
            FUN_1412751f0(FUN_14028de60(0xb8b), 1, 1);
    }
        break;
    case 0x20:
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
        {
            FUN_1403ed2b0()->FUN_141adc5d0(0x4e2d);
            pPC->FUN_141530700(1);
        }
    }
        break;
    case 0x21:
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
            pPC->FUN_141530700(0);
    }
        break;
    case 0x22:
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
        {
            int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
            pPC->FUN_14152a2d0(nValue);
        }
    }
        break;
    case 0x24:
        FUN_140ee8190(packet);
        break;
    case 0x43:
        FUN_140ee83f0(packet);
        break;
    case 0x25:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
            if (spService != 0)
            {
                if (nValue != spService->FUN_1410c3470())
                {
                    spService->FUN_1410c3490(nValue);
                    spService->FUN_1410c3670();
                    FUN_141275260(0x6e6, 3, 1);
                }
                UIUGCHousingPointDialog* pPoint = FUN_140ef4af0(0x4f28);
                if (pPoint != 0)
                    pPoint->FUN_140c2bf40();
                UIHomeResizeDialog* pResize = Unk_SSGGetDialog<UIHomeResizeDialog>(0x4f7e);
                if (pResize != 0)
                    pResize->FUN_140c2bf40();
            }
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x26:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
            if (spService != 0)
            {
                if (nValue != spService->FUN_1410c3470())
                {
                    spService->FUN_1410c3490(nValue);
                    spService->FUN_1410c3670();
                    FUN_141275260(0x6e8, 3, 1);
                }
                UIUGCHousingPointDialog* pPoint = FUN_140ef4af0(0x4f28);
                if (pPoint != 0)
                    pPoint->FUN_140c2bf40();
                UIHomeResizeDialog* pResize = Unk_SSGGetDialog<UIHomeResizeDialog>(0x4f7e);
                if (pResize != 0)
                    pResize->FUN_140c2bf40();
            }
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x2c:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
            if (spService != 0)
            {
                if (nValue != spService->FUN_1410c34b0())
                {
                    spService->FUN_1410c34d0(nValue);
                    spService->FUN_1410c3670();
                    FUN_141275260(0x6e7, 3, 1);
                    UIUGCHousingPointDialog* pPoint = FUN_140ef4af0(0x4f28);
                    if (pPoint != 0)
                        pPoint->FUN_140c2bf70();
                    UIHomeResizeDialog* pResize = Unk_SSGGetDialog<UIHomeResizeDialog>(0x4f7e);
                    if (pResize != 0)
                        pResize->FUN_140c2bf70();
                }
            }
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x2d:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
            if (spService != 0)
            {
                if (nValue != spService->FUN_1410c34b0())
                {
                    spService->FUN_1410c34d0(nValue);
                    spService->FUN_1410c3670();
                    FUN_141275260(0x6e9, 3, 1);
                    UIUGCHousingPointDialog* pPoint = FUN_140ef4af0(0x4f28);
                    if (pPoint != 0)
                        pPoint->FUN_140c2bf70();
                    UIHomeResizeDialog* pResize = Unk_SSGGetDialog<UIHomeResizeDialog>(0x4f7e);
                    if (pResize != 0)
                        pResize->FUN_140c2bf70();
                }
            }
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x3e:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            unsigned char nA = static_cast<CInputStream&>(packet).vfunc_o8_1();
            unsigned char nB = static_cast<CInputStream&>(packet).vfunc_o8_1();
            bool bChanged = false;
            if (spService != 0)
            {
                if (nA != spService->FUN_1410c3470())
                {
                    spService->FUN_1410c3490(nA);
                    bChanged = true;
                }
                if (nB != spService->FUN_1410c34b0())
                {
                    spService->FUN_1410c34d0(nB);
                    bChanged = true;
                }
                if (bChanged)
                {
                    spService->FUN_1410c3670();
                    UIUGCHousingPointDialog* pPoint = FUN_140ef4af0(0x4f28);
                    if (pPoint != 0)
                    {
                        pPoint->FUN_140c2bf40();
                        pPoint->FUN_140c2bf70();
                    }
                    UIHomeResizeDialog* pResize = Unk_SSGGetDialog<UIHomeResizeDialog>(0x4f7e);
                    if (pResize != 0)
                    {
                        pResize->FUN_140c2bf40();
                        pResize->FUN_140c2bf70();
                    }
                    Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
                    if (pDlg != 0)
                        pDlg->FUN_1412c6b50();
                }
            }
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x27:
    {
        __int64 nCharId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        if (DAT_143ab2820 != nCharId)
            return;
        __int64 nA = static_cast<CInputStream&>(packet).vfunc_o8_4();
        unsigned short nB = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_4());
        __int64 nC = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab2928 = nA;
        DAT_143ab291c = nB;
        DAT_143ab2930 = nC;
        DAT_143ab32b8.RemoveAll();
        for (int i = 0; i < nCount; i++)
            DAT_143ab32b8.Add(static_cast<CInputStream&>(packet).vfunc_o8_3());
        UIMasteryDialog* pMastery = FUN_140faf160(0x4f1e);
        if (pMastery != 0)
        {
            pMastery->FUN_140eb2460();
            pMastery->FUN_140eb4be0();
        }
        Unk_SSGDlg4e28* pDlg = FUN_140938b90(0x4e28);
        if (pDlg != 0)
        {
            pDlg->FUN_141938190();
            pDlg->FUN_1419391c0();
        }
        UIUGCHousingPointDialog* pPoint = FUN_140ef4af0(0x4f28);
        if (pPoint != 0)
            pPoint->FUN_140fae0d0();
    }
        break;
    case 0x35:
    {
        __int64 nCharId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nA = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nB = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nC = static_cast<CInputStream&>(packet).vfunc_o8_4();
        if (DAT_143ab2820 != nCharId)
            return;
        DAT_143ab2857 = true;
        DAT_143ab2938 = nA;
        spService->FUN_1410d5700(nB);
        spService->FUN_1410d5750(nC);
        Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
        if (pDlg != 0)
            pDlg->FUN_1412c6220();
    }
        break;
    case 0x3c:
    {
        __int64 nCharId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
        if (DAT_143ab2820 != nCharId)
            return;
        DAT_143ab291e = true;
        DAT_143ab2948 = nValue;
    }
        break;
    case 0x2a:
    {
        int nKey = static_cast<CInputStream&>(packet).vfunc_o8_1();
        bool bValue = static_cast<CInputStream&>(packet).vfunc_o8_1() == 1 ? true : false;
        if (spService != 0)
            spService->FUN_1410c3e40(nKey, bValue);
    }
        break;
    case 0x2b:
    {
        int nKey = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (spService != 0)
            spService->FUN_1410c3f10(nKey, nValue);
    }
        break;
    case 0x28:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
            break;
        spService->FUN_1410d6590(nError);
    }
        break;
    case 0x29:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
            break;
        spService->FUN_1410d6590(nError);
    }
        break;
    case 0x2e:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            __int64 nCharId = static_cast<CInputStream&>(packet).vfunc_o8_4();
            int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_3();
            CString strName = static_cast<CInputStream&>(packet).vfunc_o8_6();
            __int64 nTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
            if (nCharId == DAT_143ab2820 && spService != 0)
            {
                spService->FUN_1410d4450(nCharId, nSlot, strName, nTime);
                spService->FUN_1410d54f0(0);
            }
            UIHomeSaveSlotDialog* pSlots = FUN_140c2b5c0(0x4f27);
            if (pSlots != 0)
                pSlots->FUN_140faa2d0();
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x40:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            __int64 nCharId = static_cast<CInputStream&>(packet).vfunc_o8_4();
            int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_3();
            CString strName = static_cast<CInputStream&>(packet).vfunc_o8_6();
            __int64 nTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
            if (nCharId == DAT_143ab2820 && spService != 0)
            {
                spService->FUN_1410d4710(nCharId, nSlot, strName, nTime);
                spService->FUN_1410d54f0(0);
            }
            UIHomeSaveSlotDialog* pSlots = FUN_140c2b5c0(0x4f27);
            if (pSlots != 0)
                pSlots->FUN_140faa2d0();
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x32:
    {
        unsigned __int64 nUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        UIUGCCubePaletteDialog* pPalette = FUN_140ef4a50(0x4f16);
        if (pPalette != 0)
            pPalette->FUN_140eec0b0(nUid);
    }
        break;
    case 0x33:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
            FUN_1409670e0()->FUN_1410c3560(nValue);
            FUN_140b6a040()->FUN_140b682c0(nValue);
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x34:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
            FUN_1409670e0()->FUN_1410c3580(nValue);
            FUN_140b6a040()->FUN_140b682f0(nValue);
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x36:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
            FUN_1409670e0()->FUN_1410c35a0(nValue);
            FUN_140b6a040()->FUN_140b683f0(nValue);
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x37:
    {
        DAT_143ab2940 = static_cast<CInputStream&>(packet).vfunc_o8_2();
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab32d8.clear();
        for (unsigned int i = 0; i < nCount; i++)
        {
            Unk_SSGHouseKey kKey;
            kKey.m_nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            kKey.m_nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (DAT_143ab32d8.find(kKey) == DAT_143ab32d8.end())
                DAT_143ab32d8.insert(kKey);
        }
    }
        break;
    case 0x39:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spService->FUN_1410d57a0(nValue);
            Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
            if (pDlg != 0)
                pDlg->FUN_1412c66c0();
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x3a:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spService->FUN_1410d5830(nValue);
            Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
            if (pDlg != 0)
                pDlg->FUN_1412c66c0();
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x38:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 0)
        {
            __int64 nA = static_cast<CInputStream&>(packet).vfunc_o8_4();
            __int64 nB = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spService->FUN_1410d5700(nA);
            spService->FUN_1410d5750(nB);
            Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
            if (pDlg != 0)
                pDlg->FUN_1412c6220();
        }
        else
            spService->FUN_1410d6590(nError);
    }
        break;
    case 0x3b:
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (unsigned int i = 0; i < nCount; i++)
        {
            __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spService->FUN_1410d57a0(nValue);
        }
        Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
        if (pDlg != 0)
            pDlg->FUN_1412c66c0();
    }
        break;
    case 0x3d:
    {
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (nError == 100)
        {
            int nSub = static_cast<CInputStream&>(packet).vfunc_o8_1();
            if (nSub != 0 || spService->FUN_1410d5b00() != 0)
            {
                spService->FUN_1410d6590(100);
                spService->FUN_1410d5ae0(0);
            }
        }
    }
        break;
    case 0x3f:
        FUN_14052d220()->FUN_14188ff10(packet);
        break;
    case 0x45:
    {
        __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
        FUN_1409670e0()->FUN_1410d5b20(nValue);
    }
        break;
    }
}
MS2_REPLACE_METHOD(0x141723670, CSceneStateGame, OnResponseCube, 18808, 0xE92E47F8);

// ---- 0x6a: the housing cube snapshot (cubes, block states, block owners, block flags) --------------------------
// Unk_PayloadPtr<NoticeCubeInfo>() and Unk_PayloadPtr<CubeOwner>::get are ICF copies outside the unit.
extern template Unk_PayloadPtr<NoticeCubeInfo>::Unk_PayloadPtr();
extern template CubeOwner* Unk_PayloadPtr<CubeOwner>::get() const;
efd::Point3 FUN_1408a15b0(Unk_Int3 kCell, efd::Point3& kOut);   // a cube coordinate to world units
Unk_CubeOwnerPtr FUN_1408a0fa0(Unk_CubeOwners& owners, int nGroup, int nBlock);
void FUN_1408a10e0(Unk_CubeOwners& owners, int nGroup, int nBlock, const CStringW& strName, __int64 nOwnerId);

// @0x141728110
void CSceneStateGame::OnLoadCubes(CInPacket& packet)
{
    efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
    {
        if (!FUN_1406aeee0()->FUN_1406af0c0())
        {
            int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
            spService->FUN_1410c3f50(nState);
            int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
            for (int i = 0; i < nCount; ++i)
            {
                int nPacked = static_cast<CInputStream&>(packet).vfunc_o8_3();
                Unk_Int3 kPos = FUN_1408a0400(nPacked);
                __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
                CubeItemInfo info(packet);
                int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
                int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
                bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_1() == 0 ? false : true;
                float fRot = static_cast<CInputStream&>(packet).vfunc_o8_5();
                int nD = static_cast<CInputStream&>(packet).vfunc_o8_3();
                Unk_PayloadPtr<NoticeCubeInfo> spNotice;
                int nHasNotice = static_cast<CInputStream&>(packet).vfunc_o8_1();
                if (nHasNotice == 1)
                {
                    CStringW strText = static_cast<CInputStream&>(packet).vfunc_o8_8();
                    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
                    spNotice = new NoticeCubeInfo;
                    spNotice->FUN_1408b4970(strText, nType);
                }
                efd::Point3 kWorld;
                FUN_1408a15b0(kPos, kWorld);
                if (spService->FUN_1410b7e80(kWorld))
                {
                    if (!spService->FUN_1410b7da0(kWorld))
                        spService->FUN_1410c1910(kPos, false);
                }
                spService->FUN_1410c4850(nItemUid, kPos, info, fRot, nA, nB, bFlag, 0, nD, spNotice);
            }
        }
    }
        break;
    case 1:
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (int i = 0; i < nCount; ++i)
        {
            int nBlock = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
            spService->FUN_1410bbc00(nBlock, nState);
        }
    }
        break;
    case 2:
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        Unk_CubeOwners* pOwners = spService->FUN_1410d3360();
        for (int i = 0; i < nCount; ++i)
        {
            int nGroup = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nBlock = static_cast<CInputStream&>(packet).vfunc_o8_3();
            CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
            __int64 nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_4();
            FUN_1408a10e0(*pOwners, nGroup, nBlock, strName, nOwnerId);
            Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(*pOwners, nGroup, nBlock);
            if (spOwner.get() != 0)
                spService->FUN_1410ce3f0(spOwner);
        }
    }
        break;
    case 3:
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (int i = 0; i < nCount; ++i)
        {
            int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nC = static_cast<CInputStream&>(packet).vfunc_o8_1();
            __int64 nD = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spService->FUN_1410c7a50(nA, nB, nC, nD);
        }
    }
        break;
    }
}
MS2_REPLACE_METHOD(0x141728110, CSceneStateGame, OnLoadCubes, 2816, 0xFC8AA5C6);

// ---- 0x17: a user (player character) entered the field ---------------------------------------------------------
// TPtr<PC>::operator=(PC*) is an inline COMDAT in this unit's range (0x141746d10).
template <> inline TPtr<PC>& TPtr<PC>::operator=(PC* p)
{
    if (m_p != p)
    {
        if (m_p)
            m_p->DecRefCount();
        m_p = p;
        if (m_p)
            m_p->IncRefCount();
    }
    return *this;
}
MyPC* FUN_14161e580(const TPtr<PC>& spPC);                  // DynamicCast<MyPC>
// The members of physxhelper.h used here (that header needs NOMINMAX, which this unit's includes cannot take).
struct Unk_RayCastInfo;
class CPhysXHelper
{
public:
    int FUN_14168a310(const Unk_StreamPoint& ptFrom, Unk_StreamPoint& ptHit, Unk_RayCastInfo* pInfo, float fLen,
                      Unk_StreamPoint* pNormal, int nMask);
    bool FUN_14168a770(const Unk_StreamPoint* pPoint);
};
CPhysXHelper* FUN_1409f7ca0();
// The compressed sub packet (efd RTTI "CZlibPacket"; ctor 0x141746040, vftable 0x142f5f9e8).
class CZlibPacket final : public CPtred
{
public:
    CZlibPacket() : m_stream(true, 0x28) { m_bDirty = true; }
    CByteBuffer& FUN_14083b6b0(CInputStream& stream);       // decode; the decompressed buffer
private:
    Unk_CompressedStream m_stream;                          // +0x18
    bool m_bDirty;                                          // +0xa0
};
MS2_CHECK_SIZE(CZlibPacket, 0xa8);
// The equipment (PC::FUN_14165f460; members in mypc.cpp's neighbours).
class Unk_MyPCEquip
{
public:
    void FUN_14126fea0(CInputStream& stream, int nObjId);   // decode the worn items
    MS2Ptr<CItem> FUN_141270140(int nSlot);
    MS2Ptr<CGemBase> FUN_141270740(int nSlot);
    void FUN_141270bf0(MS2Ptr<CItem> spItem);               // socket the item (gemslot)
    MS2Ptr<CItem> FUN_141270ab0(int nSlot);                 // take the item out of a gem slot
};
void FUN_141425610();
extern __int64 DAT_143ab2840;                               // the platform account id
extern CString DAT_143ab2a40;                               // the platform account name
extern bool DAT_143ab2942;                                  // the game began
extern int DAT_143ab0248;                                   // client country (0..3)
extern "C" const wchar_t* DAT_1439f8350;                    // L"ACCOUNT_ID"
extern "C" const wchar_t* DAT_1439f8358;                    // L"CHAR_NAME"
extern "C" void (__cdecl* __imp_CrashReporter_SetStrInfoA)(const wchar_t*, const char*);
extern "C" void (__cdecl* __imp_CrashReporter_SetStrInfoW)(const wchar_t*, const wchar_t*);
extern "C" void (__cdecl* __imp_CrashReporter_SetInt64Info)(const wchar_t*, __int64*);

// The item a state is told about in its slots 29/30 (state.h passes it as MS2Ptr<Unk_StateArg29>).
class Unk_StateArg29 : public CItem { };

// 0x7f gem slots: mode 0 socket an item (owner, item id/uid/rarity, slot, item data), mode 1 take it out (owner,
// slot), mode 4 an error code.
// MS2-FUNCTIONAL: the states' slots 29/30 take MS2Ptr<Unk_StateArg29>, so the item is passed through a pointer
// ctor instead of the exe's MS2Ptr<CItem> copy ctor.
// @0x141730920
void CSceneStateGame::FUN_141730920(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nObjId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
        unsigned char nSlot = static_cast<CInputStream&>(packet).vfunc_o8_1();
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->FUN_140526b30(nObjId);
            spItem->FUN_140526a70(nItemUid);
            spItem->FUN_140526b70(nSlot);
            spItem->FUN_140524eb0(packet);
            PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nObjId);
            if (pPC != 0)
            {
                pPC->FUN_14165f460()->FUN_141270bf0(spItem);
                pPC->FUN_14166ccb0()->vfunc_29(MS2Ptr<Unk_StateArg29>(static_cast<Unk_StateArg29*>(spItem.get())));
            }
            bool bMine = efd::ClassInfo::IsKindOf(pPC != NULL ? pPC->GetClassDesc() : NULL, 0x6200004);
            bool bShow = false;
            if (spItem->FUN_140527900() != 0)
            {
                if (spItem->FUN_140527900()->vfunc_1() == 2)
                    bShow = pPC->vfunc_65() == 1 || bMine;
            }
            if (bMine)
                FUN_140a6a840()->vfunc_29(spItem.get());
            if (bShow)
                FUN_1403ed2b0()->FUN_141ad9c40(spItem->FUN_140527900()->GetGem());
        }
    }
    else if (nMode == 1)
    {
        int nObjId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_1();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nObjId);
        if (pPC != 0)
        {
            MS2Ptr<CItem> spItem = pPC->FUN_14165f460()->FUN_141270ab0(nSlot);
            if (spItem.get() != 0)
            {
                pPC->FUN_14166ccb0()->vfunc_30(MS2Ptr<Unk_StateArg29>(static_cast<Unk_StateArg29*>(spItem.get())));
                if (FUN_1409613d0(pPC) != 0)
                    FUN_140a6a840()->vfunc_30(spItem.get());
            }
        }
    }
    else if (nMode == 4)
    {
        short nError = static_cast<CInputStream&>(packet).vfunc_o8_2();
        switch (nError)
        {
        case 0:
            FUN_141275260(0xaa9, 1, 1);
            break;
        case 2:
            FUN_141275260(0xaab, 1, 1);
            break;
        case 1:
            FUN_141275260(0xaaa, 1, 1);
            break;
        case 3:
            FUN_141275260(0xaac, 1, 1);
            break;
        case 4:
            FUN_141275260(0xaad, 1, 1);
            break;
        case 5:
            if (FUN_140166410()->FUN_14036d570(0x4a))
            {
                FUN_1412751f0(FUN_14028b8e0(L"s_gem_error_VIP"), 1, 1);
            }
            else
            {
                FUN_141275260(0xaae, 1, 1);
                break;
            }
            break;
        default:
            FUN_141275260(0xaae, 1, 1);
        }
    }
}
MS2_REPLACE_METHOD(0x141730920, CSceneStateGame, FUN_141730920, 2066, 0x0E9ABD5A);

// @0x14170fda0
void CSceneStateGame::OnAddUser(CInPacket& packet)
{
    int nObjId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    if (!pWorld->FUN_141bcfbd0())
    {
        MessageBoxA(0, "Error - !world.IsLoadingComplete()", "CSceneStateGame::OnAddUser()", 0);
        throw 13;
    }
    Unk_UserProxy proxy;
    proxy.FUN_1408eeb60(&packet);
    Unk_StreamPoint kPos;
    Unk_StreamPoint kDir;
    CString strAnim;
    if (proxy.m_14 == 0)
        strAnim = "urn:gamebryo-animation:Male";
    else
        strAnim = "urn:gamebryo-animation:Female";
    TPtr<PC> spPC(0);
    int bMyPC = 0;
    if (DAT_143ab2828 == proxy.m_8)
    {
        spPC = static_cast<PC*>(static_cast<PCBase*>(new (efd::MemHint(efd::MemHint::NONE)) MyPC));
        bMyPC = 1;
        DAT_143ab2840 = proxy.FUN_141748180();
        DAT_143ab2a40 = FUN_14016a5c0(proxy.FUN_1417480a0(), 0);
        DAT_143ab2a90.FUN_140a66c00();
        CString strAccount;
        strAccount.Format("%d", DAT_143ab2820);
        __imp_CrashReporter_SetStrInfoA(DAT_1439f8350, strAccount.GetBuffer());
        __int64 nNexonId = proxy.FUN_141748180();
        __imp_CrashReporter_SetInt64Info(L"NEXON_ID", &nNexonId);
        __imp_CrashReporter_SetStrInfoW(DAT_1439f8358, proxy.FUN_1408f19e0().GetBuffer());
    }
    else
    {
        spPC = new (efd::MemHint(efd::MemHint::NONE)) PC;
    }
    FUN_1416546d0(spPC.operator->())->vfunc_7(packet);
    kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
    kDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
    kPos.z += 25.0f;
    spPC->FUN_14123c5a0(nObjId);
    spPC->FUN_141656aa0(proxy.m_0);
    spPC->FUN_141656a50(proxy.m_8);
    spPC->FUN_141658e40(proxy.m_14);
    spPC->vfunc_131(proxy.m_34);
    spPC->vfunc_76(proxy.FUN_1408f19e0());
    spPC->FUN_14123bb80(strAnim);
    spPC->vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
    spPC->vfunc_21(reinterpret_cast<efd::Point3&>(kDir));
    spPC->vfunc_129(proxy.FUN_1408f1b60());
    spPC->FUN_141661330(proxy.FUN_1408f1ae0());
    spPC->FUN_141658e80(proxy.m_70);
    spPC->FUN_141658ed0(proxy.FUN_1408f2000());
    spPC->FUN_141662850(proxy.m_b0);
    spPC->FUN_141662890(proxy.m_b8);
    spPC->FUN_14174a340(proxy.m_78);
    spPC->FUN_14165ffc0(proxy.m_180);
    spPC->FUN_141660000(proxy.m_188);
    spPC->FUN_141663a00(proxy.m_190);
    spPC->FUN_141663a70(proxy.m_194);
    spPC->FUN_141663a90(proxy.m_198);
    spPC->FUN_141663b10(proxy.m_1ac);
    if (DAT_143ab0248 == 3 && proxy.m_330.get() != 0)
    {
        spPC->FUN_141663060(proxy.m_330->vfunc_37());
        spPC->FUN_1416630a0(proxy.m_330->vfunc_38());
        if (bMyPC)
        {
            int nPlatform = proxy.m_330->vfunc_60();
            FUN_1409a8b10()->FUN_140a46860()->FUN_141261e90(nPlatform);
        }
    }
    for (size_t i = 0; i < 12; i++)
        spPC->FUN_141662790((int)i, proxy.m_140[i]);

    // snap the spawn point to the ground
    Unk_StreamPoint kHit;
    if (FUN_1409f7ca0()->FUN_14168a310(kPos, kHit, 0, 0.0f, 0, 0))
    {
        kHit.z += 25.0f;
        if (!FUN_1409f7ca0()->FUN_14168a770(&kHit))
            spPC->vfunc_19(reinterpret_cast<efd::Point3&>(kHit));
    }

    spPC->m_unk_1bc = static_cast<CInputStream&>(packet).vfunc_o8_1();
    spPC->vfunc_91(&packet);
    if (spPC->FUN_141670a00(4) == 0)
        spPC->FUN_14166ce50(1);
    int nEmotion = static_cast<CInputStream&>(packet).vfunc_o8_1();
    spPC->FUN_14166ce70(nEmotion);
    int nCubeA = static_cast<CInputStream&>(packet).vfunc_o8_1();
    CubeItemInfo kCube(packet);
    int nCubeB = static_cast<CInputStream&>(packet).vfunc_o8_3();
    spPC->vfunc_135(nCubeA, nCubeB, &kCube);
    NiColor aColor[2];
    aColor[0] = FUN_141b6dea0(static_cast<CInputStream&>(packet).vfunc_o8_3());
    aColor[1] = FUN_141b6dea0(static_cast<CInputStream&>(packet).vfunc_o8_3());
    spPC->FUN_1416591e0(0, aColor[0]);
    spPC->FUN_1416591e0(1, aColor[1]);
    CString strTitle = static_cast<CInputStream&>(packet).vfunc_o8_6();
    spPC->FUN_141660fc0(strTitle);
    bool bRide = static_cast<CInputStream&>(packet).vfunc_o8_0();
    if (bRide)
    {
        MS2Ptr<RideOnAction> spRide = FUN_14077deb0(&static_cast<CInputStream&>(packet));
        spPC->FUN_141676320(spRide);
        spPC->FUN_141676700();
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();
        for (int i = 0; i < nCount; i++)
        {
            int nKey = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
            spPC->FUN_141676670(nKey, nValue);
        }
    }
    if (pWorld->FUN_141bbb1e0(spPC.get(), 0, 1) == 0)
        return;

    int nTitleId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    spPC->FUN_14165f090(nTitleId);
    __int64 nA = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nC = static_cast<CInputStream&>(packet).vfunc_o8_3();
    spPC->FUN_141662640(nA);
    spPC->FUN_141662690(nB);
    spPC->FUN_141662710(nC);

    // the owned items
    CZlibPacket kItems;
    CByteBuffer& buf = kItems.FUN_14083b6b0(static_cast<CInputStream&>(packet));
    int nItems = static_cast<CInputStream&>(buf).vfunc_o8_1();
    for (int i = 0; i < nItems; i++)
    {
        int nItemId = static_cast<CInputStream&>(buf).vfunc_o8_3();
        __int64 nItemUid = static_cast<CInputStream&>(buf).vfunc_o8_4();
        int nSlot = static_cast<CInputStream&>(buf).vfunc_o8_1();
        int nRarity = static_cast<CInputStream&>(buf).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nItemId, nRarity, 0))
            break;
        spItem->FUN_140526c10(nSlot);
        spItem->FUN_140524eb0(static_cast<CInputStream&>(buf));
        spItem->FUN_140526a70(nItemUid);
        spItem->FUN_140526b30(nObjId);
        spPC->FUN_141653d10(spItem);
    }
    bool bTime = static_cast<CInputStream&>(buf).vfunc_o8_0();
    __int64 nStart = static_cast<CInputStream&>(buf).vfunc_o8_4();
    __int64 nEnd = static_cast<CInputStream&>(buf).vfunc_o8_4();
    spPC->FUN_1416561a0()->FUN_1411ea620(nStart, nEnd);
    int nOutfits = static_cast<CInputStream&>(buf).vfunc_o8_1();
    for (int i = 0; i < nOutfits; i++)
    {
        int nItemId = static_cast<CInputStream&>(buf).vfunc_o8_3();
        __int64 nItemUid = static_cast<CInputStream&>(buf).vfunc_o8_4();
        int nSlot = static_cast<CInputStream&>(buf).vfunc_o8_1();
        int nRarity = static_cast<CInputStream&>(buf).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nItemId, nRarity, 0))
            break;
        spItem->FUN_140526c10(nSlot);
        spItem->FUN_140524eb0(static_cast<CInputStream&>(buf));
        spItem->FUN_140526a70(nItemUid);
        spItem->FUN_140526b30(nObjId);
        spItem->FUN_14052a130(2);
        spPC->FUN_141653d10(spItem);
    }

    // the item cooldowns and the worn equipment
    CZlibPacket kCooldowns;
    CByteBuffer& kCooldownBuf = kCooldowns.FUN_14083b6b0(static_cast<CInputStream&>(packet));
    spPC->FUN_1416561c0()->FUN_140c860b0(kCooldownBuf, nObjId);
    CZlibPacket kEquip;
    CByteBuffer& kEquipBuf = kEquip.FUN_14083b6b0(static_cast<CInputStream&>(packet));
    spPC->FUN_14165f460()->FUN_14126fea0(kEquipBuf, nObjId);
    MS2Ptr<CGemBase> spGem = spPC->FUN_14165f460()->FUN_141270740(1);
    if (spGem.get())
        spGem->vfunc_6(spPC.get(), spPC->FUN_14165f460()->FUN_141270140(1));

    spPC->FUN_1416749a0()->FUN_140970ff0(packet);
    FUN_1416546d0(spPC.operator->())->FUN_140a6e240();
    spPC->FUN_141661b20(packet);
    spPC->FUN_141661ba0(static_cast<CInputStream&>(packet).vfunc_o8_1());
    spPC->FUN_140967420()->FUN_140743a10(packet);
    spPC->FUN_141661c00(packet);
    spPC->FUN_141661d40(packet);
    spPC->FUN_141676980(static_cast<CInputStream&>(packet).vfunc_o8_3());
    spPC->FUN_141663150(packet);
    spPC->FUN_141662d60(static_cast<CInputStream&>(packet).vfunc_o8_4());
    spPC->FUN_141678300(static_cast<CInputStream&>(packet).vfunc_o8_3());
    spPC->FUN_141678340(static_cast<CInputStream&>(packet).vfunc_o8_1());
    spPC->FUN_141662e30((unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2());

    MyPC* pMyPC = FUN_14161e580(spPC);
    if (pMyPC)
    {
        FUN_140535320()->FUN_140c8b300(proxy.FUN_1408f1330());
        FUN_140931510()->FUN_140d9f310(proxy.m_50);
        pMyPC->FUN_141699a20();
        pMyPC->FUN_1416561a0()->FUN_1411ea7c0();
        pMyPC->vfunc_88();
        DAT_143ab2942 = true;
        FUN_140d86260()->vfunc_22(0x2d0, "GameBegin");
        efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService ? true : false)
        {
            if (!spService->FUN_1410c35c0())
            {
                if (spService->FUN_1410c3180() == DAT_143ab2820)
                    spService->FUN_1410d5350();
            }
        }
        FUN_141425610();
        pMyPC->FUN_14152ed60(&proxy);
    }
    MyPC* pLocal = pWorld->FUN_141bd0cc0();
    if (pLocal)
        pLocal->FUN_1416634a0(proxy.m_8);
    if (bMyPC)
        FUN_140d86260()->vfunc_61();
    spPC->vfunc_140(proxy.m_1a8);
    spPC->FUN_141663550();
}
MS2_REPLACE_METHOD(0x14170FDA0, CSceneStateGame, OnAddUser, 8209, 0xDFA14B88);

// ---- 0x7e: field object proxies (mode 3..5 players, 6..8 template objects, 9..11 spawn points) -----------------
class Unk_Svc6d6e90 { public: Unk_ProxyHandle28 FUN_140a7cab0(int id); };
Unk_Svc6d6e90* FUN_1406d6e90();
class Unk_SSGProxyListener
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(MS2Ptr<CProxyGameObject> spProxy, int nFlags);   // a proxy changed
};
Unk_SSGProxyListener* FUN_140c607b0();

// @0x14172f500
void CSceneStateGame::FUN_14172f500(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 3)
    {
        MS2Ptr<CProxyGameObject> spProxy(new CProxyGameObject);
        spProxy->m_proxyId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->m_40 = static_cast<CInputStream&>(packet).vfunc_o8_4();
        spProxy->m_48 = static_cast<CInputStream&>(packet).vfunc_o8_4();
        spProxy->m_58 = static_cast<CInputStream&>(packet).vfunc_o8_8();
        spProxy->m_50 = static_cast<CInputStream&>(packet).vfunc_o8_6();
        spProxy->m_60 = static_cast<CInputStream&>(packet).vfunc_o8_8();
        spProxy->kind = static_cast<CInputStream&>(packet).vfunc_o8_1();
        spProxy->m_6c = static_cast<CInputStream&>(packet).vfunc_o8_10();
        spProxy->m_a8 = static_cast<CInputStream&>(packet).vfunc_o8_2();
        spProxy->m_ac = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        spProxy->m_b0 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->m_b4 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->m_b8 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->m_bc = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->m_c0 = static_cast<CInputStream&>(packet).vfunc_o8_8();
        spProxy->m_c8 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->m_cc = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        spProxy->m_d0.FUN_140267e70(static_cast<CInputStream&>(packet));
        if (FUN_14052d220()->FUN_14187f3b0() == 1)
            spProxy->m_50 = "";
        FUN_1403ed2d0()->FUN_141bc9aa0(spProxy);
    }
    else if (nMode == 4)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_1403ed2d0()->FUN_141bc9b30(nId);
    }
    else if (nMode == 5)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CProxyGameObject> spProxy = FUN_1403ed2d0()->FUN_141bc9be0(nId);
        if (spProxy.get())
        {
            int nFlags = static_cast<CInputStream&>(packet).vfunc_o8_1();
            if (nFlags & 1)
                spProxy->kind = static_cast<CInputStream&>(packet).vfunc_o8_1();
            if (nFlags & 2)
                spProxy->m_6c = static_cast<CInputStream&>(packet).vfunc_o8_10();
            if (nFlags & 4)
                spProxy->m_a8 = static_cast<CInputStream&>(packet).vfunc_o8_2();
            if (nFlags & 8)
            {
                spProxy->m_ac = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
                spProxy->m_b0 = static_cast<CInputStream&>(packet).vfunc_o8_3();
            }
            if (nFlags & 0x10)
                spProxy->m_60 = static_cast<CInputStream&>(packet).vfunc_o8_8();
            if (nFlags & 0x20)
                spProxy->m_c8 = static_cast<CInputStream&>(packet).vfunc_o8_3();
            if (nFlags & 0x40)
                spProxy->m_cc = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
            FUN_140c607b0()->vfunc_5(spProxy, nFlags);
        }
    }
    else if (nMode == 6)
    {
        MS2Ptr<CProxyGameObject> spProxy(new CProxyGameObject);
        spProxy->m_proxyId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nTemplateId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->kind = static_cast<CInputStream&>(packet).vfunc_o8_1();
        spProxy->m_7c = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->m_6c = static_cast<CInputStream&>(packet).vfunc_o8_10();
        if (spProxy->FUN_1416c2990(nTemplateId))
            FUN_1403ed2d0()->FUN_141bc9aa0(spProxy);
    }
    else if (nMode == 7)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_1403ed2d0()->FUN_141bc9b30(nId);
    }
    else if (nMode == 8)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CProxyGameObject> spProxy = FUN_1403ed2d0()->FUN_141bc9be0(nId);
        if (spProxy.get())
        {
            spProxy->kind = static_cast<CInputStream&>(packet).vfunc_o8_1();
            spProxy->m_6c = static_cast<CInputStream&>(packet).vfunc_o8_10();
        }
    }
    else if (nMode == 9)
    {
        MS2Ptr<CProxyGameObject> spProxy(new CProxyGameObject);
        spProxy->m_proxyId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->m_84 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->m_78 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spProxy->kind = static_cast<CInputStream&>(packet).vfunc_o8_1();
        spProxy->m_6c = static_cast<CInputStream&>(packet).vfunc_o8_10();
        spProxy->m_28.FUN_140a4fe50(FUN_1406d6e90()->FUN_140a7cab0(spProxy->m_78));
        if (spProxy->m_28.FUN_140a4ff10())
            FUN_1403ed2d0()->FUN_141bc9aa0(spProxy);
    }
    else if (nMode == 10)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_1403ed2d0()->FUN_141bc9b30(nId);
    }
    else if (nMode == 11)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CProxyGameObject> spProxy = FUN_1403ed2d0()->FUN_141bc9be0(nId);
        if (spProxy.get())
        {
            spProxy->kind = static_cast<CInputStream&>(packet).vfunc_o8_1();
            spProxy->m_6c = static_cast<CInputStream&>(packet).vfunc_o8_10();
        }
    }
}
MS2_REPLACE_METHOD(0x14172F500, CSceneStateGame, FUN_14172f500, 5132, 0xD54955F8);

// 0x54: mail. CCMailPacket payloads (ctors/dtors are this obj's comdats); the readers live in unit_1401f9eb0.
class CCMailPacket {
public:
    class MailNew : public CPtred {
    public:
        MailNew() : m_nUnread(0), m_nUnreadAlarm(0), m_bAlarm(true) {}
        int m_nUnread;                                      // +0x18
        int m_nUnreadAlarm;                                 // +0x1c
        bool m_bAlarm;                                      // +0x20
    };
    class GiftNew : public CPtred {
    public:
        GiftNew() : m_nType(0), m_nItemId(0), m_nRarity(0), m_nCount(0) {}
        CStringW m_strSender;                               // +0x18
        unsigned int m_nType;                               // +0x20
        int m_nItemId;                                      // +0x24
        unsigned int m_nRarity;                             // +0x28
        int m_nCount;                                       // +0x2c
        CString m_strUgcPath;                               // +0x30
        CStringW m_strUgcTitle;                             // +0x38
    };
};
MS2_CHECK_SIZE(CCMailPacket::MailNew, 0x28);
MS2_CHECK_SIZE(CCMailPacket::GiftNew, 0x40);
void FUN_140201b00(unsigned char* payload, void* inputPacket);   // read CCMailPacket::GiftNew
void FUN_140201db0(unsigned char* payload, void* inputPacket);   // read CCMailPacket::MailNew
extern CUserMail DAT_143ab2ee0;
extern int DAT_143af37b0;                                   // the mail list needs a refresh
extern int DAT_143af37b4;
extern __int64 DAT_143af37b8;                               // the mail to select when the list opens
class UIMailListDialog : public UIDialog
{
public:
    static int Id() { return 0x4e49; }
    void FUN_1419e5000(__int64 nMailId);
    void FUN_1419e5150();
};
class UIMailSendDialog : public UIDialog { public: void FUN_1419ecb80(); };
class UIWhisperNotifyDialog : public UIDialog { public: void FUN_141b52210(MS2Ptr<CItem> spItem, const CStringW& strMsg, const CString& strUgcPath); };
// The UGC info behind CItem::FUN_1405278d0 holds its look at +0x18.
class Unk_SSGItemUgc : public CPtred { public: CUgcItemLook m_look; };
CStringW FUN_14183e9c0(CStringW strName, int nRank);        // the name coloured by rank
CString FUN_14072ceb0(int nId);
int FUN_140718170(const CString& s);

// @0x141721cd0
void CSceneStateGame::FUN_141721cd0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0x10)
    {
        DAT_143ab2ee0.FUN_1408e3030();
    }
    else if (nMode == 0)
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (int i = 0; i < nCount; i++)
        {
            CUserMail::MailPtr spMail(new CMailInfo(0));
            spMail->FUN_1406913e0(packet);
            DAT_143ab2ee0.FUN_1408e3a60(spMail);
        }
        DAT_143ab2ee0.FUN_1408e3490(0);
        DAT_143ab2ee0.FUN_1408e3500(0);
    }
    else if (nMode == 0x11)
    {
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e49) == 0)
            DAT_143af37b0 = 1;
        DAT_143ab2ee0.FUN_1408e4890();
    }
    else if (nMode == 1)
    {
        FUN_140d73bc0(0x228, 0, 0, L"");
        DAT_143ab2ee0.FUN_1408e3ff0(0);
        UIMailSendDialog* pDlg = Unk_SSGGetDialog<UIMailSendDialog>(0x4e4a);
        if (pDlg != 0)
            pDlg->FUN_1419ecb80();
    }
    else if (nMode == 2)
    {
        __int64 nMailId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
        DAT_143ab2ee0.FUN_1408e3540(nMailId, nValue);
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e49) == 0)
        {
            UIMailListDialog* pList = Unk_SSGGetDialog<UIMailListDialog>(0x4e49);
            if (pList != 0)
                pList->FUN_1419e5000(nMailId);
        }
    }
    else if (nMode == 3)
    {
        __int64 nMailId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        FUN_141275260(0x229, 1, 1);
        DAT_143ab2ee0.FUN_1408e3b70(nMailId, 1, 0);
    }
    else if (nMode == 0xa)
    {
        __int64 nMailId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int bSlot = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_1();
        __int64 nTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
        CUserMail::MailPtr spMail = DAT_143ab2ee0.FUN_1408e3720(nMailId);
        if (spMail == 0)
            return;
        if (bSlot != 0)
            spMail->FUN_1406906c0(nSlot, nTime);
        else
            spMail->FUN_140690d60(nTime);
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e49) == 0)
            DAT_143af37b8 = nMailId;
    }
    else if (nMode == 0xb)
    {
        __int64 nMailId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
        CUserMail::MailPtr spMail = DAT_143ab2ee0.FUN_1408e3720(nMailId);
        if (spMail == 0)
            return;
        spMail->FUN_140690d60(nTime);
        spMail->FUN_140690df0(nTime);
        spMail->FUN_140690e80(nTime);
        spMail->FUN_140690f10(nTime);
        for (int i = 0; i < 5; i++)
            spMail->FUN_1406906c0(i, nTime);
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e49) == 0)
        {
            DAT_143af37b8 = nMailId;
            DAT_143af37b0 = 1;
        }
    }
    else if (nMode == 0xc)
    {
        __int64 nMailId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        __int64 nTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
        CUserMail::MailPtr spMail = DAT_143ab2ee0.FUN_1408e3720(nMailId);
        if (spMail == 0)
            return;
        spMail->FUN_140692420(nTime);
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e49) == 0)
        {
            DAT_143af37b8 = nMailId;
            DAT_143af37b0 = 1;
        }
    }
    else if (nMode == 0xd)
    {
        __int64 nMailId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        DAT_143ab2ee0.FUN_1408e3b70(nMailId, 1, 0x41);
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e49) == 0)
            DAT_143af37b4 = 1;
    }
    else if (nMode == 0xe)
    {
        CCMailPacket::MailNew mailNew;
        FUN_140201db0(reinterpret_cast<unsigned char*>(&mailNew), &packet);
        int nUnread = mailNew.m_nUnread;
        DAT_143ab2ee0.FUN_1408e3490(nUnread);
        DAT_143ab2ee0.FUN_1408e3500(mailNew.m_nUnreadAlarm);
        if (nUnread != 0 && !FUN_1403ed2d0()->FUN_141bcb0a0() && mailNew.m_bAlarm)
            FUN_141275260(0x22b, 8, 1);
        UIMailListDialog* pList = Unk_SSGGetUI<UIMailListDialog>();
        if (pList != 0 && pList->FUN_141924630() != 0)
            pList->FUN_1419e5150();
    }
    else if (nMode == 0xf)
    {
        if (!FUN_1403ed2d0()->FUN_141bcb0a0())
            FUN_141275260(0x257, 1, 0);
        FUN_1412751b0(FUN_14028de60(0x258), 0x14);
    }
    else if (nMode == 0x16)
    {
        CCMailPacket::GiftNew gift;
        FUN_140201b00(reinterpret_cast<unsigned char*>(&gift), &packet);
        if (!FUN_1403ed2d0()->FUN_141bcb0a0())
        {
            const CStringW& strSender = gift.m_strSender;
            FUN_1412751f0(FUN_1405c2690(L"s_mail_notify_recieve_gift", strSender), 8, 1);
            UIWhisperNotifyDialog* pDlg = Unk_SSGGetDialog<UIWhisperNotifyDialog>(0x4e5e);
            if (pDlg != 0)
            {
                int nItemId = gift.m_nItemId;
                MS2Ptr<CItem> spItem(new CItem);
                if (spItem.get() != 0 && spItem->FUN_14052b2e0(nItemId, gift.m_nRarity, 0, gift.m_nCount) != 0)
                {
                    CString strUgcPath;
                    if (spItem->FUN_140525f10() != 0 || spItem->FUN_140526010() != 0)
                    {
                        Unk_ItemUgcInfo* pInfo = spItem->FUN_1405278d0();
                        if (pInfo != 0)
                        {
                            CUgcItemLook* pLook = &reinterpret_cast<Unk_SSGItemUgc*>(pInfo)->m_look;
                            pLook->m_n30 = 1;
                            pLook->m_strUrl = gift.m_strUgcPath;
                            pLook->m_str28 = gift.m_strUgcTitle;
                        }
                    }
                    else if (spItem->FUN_140525680())
                    {
                        spItem->FUN_140529500(gift.m_strUgcTitle);
                        int nId = FUN_140718170(gift.m_strUgcPath);
                        strUgcPath = FUN_14072ceb0(nId);
                    }
                    CStringW strMsg = FUN_1408f71a0(L"s_mail_get_gift_item", FUN_14183e9c0(spItem->FUN_140527b10(), gift.m_nRarity), strSender);
                    pDlg->FUN_141b52210(spItem, strMsg, strUgcPath);
                }
            }
        }
    }
    else if (nMode == 0x14)
    {
        int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
        CString strUnused;
        switch (nError)
        {
        case 1:
            FUN_141275260(0x23e, 1, 1);
            break;
        case 0x1d:
            FUN_141275260(0x24f, 1, 1);
            break;
        case 0x1e:
            FUN_141275260(0x250, 1, 1);
            break;
        case 2:
        case 5:
            FUN_141275260(0x240, 1, 1);
            break;
        case 3:
        case 4:
            FUN_141275260(0x23f, 1, 1);
            break;
        case 0xc:
            FUN_141275260(0x244, 1, 1);
            break;
        case 0x10:
            FUN_141275260(0x249, 1, 1);
            break;
        case 0x11:
            FUN_141275260(0x241, 1, 1);
            break;
        case 0x18:
            FUN_141275260(0x243, 1, 1);
            break;
        case 0x19:
            FUN_141275260(0x242, 1, 1);
            break;
        case 0x14:
            FUN_141275260(0x24a, 1, 1);
            FUN_141276180(DAT_143ae7978, "");
            break;
        case 0x16:
            FUN_141275260(0x24a, 1, 1);
            FUN_141276180(DAT_143ae7978, "");
            break;
        case 0x15:
            FUN_141275260(0x24b, 1, 1);
            break;
        case 0x17:
            FUN_141275260(0x24c, 1, 1);
            break;
        case 0x1a:
            FUN_141275260(0x34, 1, 1);
            break;
        case 0x1b:
            FUN_141275260(0x24d, 1, 1);
            break;
        case 0x1c:
            FUN_141275260(0x24e, 1, 1);
            break;
        case 0x1f:
            FUN_141275260(0x251, 1, 1);
            break;
        case 0x20:
            FUN_141275260(0x252, 1, 1);
            break;
        case 0x21:
            FUN_141275260(0xc07, 1, 1);
            break;
        default:
            Unk_SSGFormatMsg(0x23a, 1, 1, nType, nError);
            break;
        }
    }
    Unk_SSGDlg4e28* pMenu = FUN_140938b90(0x4e28);
    if (pMenu != 0 && pMenu->vfunc_55() == 0)
        pMenu->FUN_141937e40(nMode);
}
MS2_REPLACE_METHOD(0x141721CD0, CSceneStateGame, FUN_141721cd0, 4625, 0x92ABA4C9);

// 0x6e: guide objects (construction / fishing / skill-magic control). The skill context is
// CSkillMagicControlGuide::SkillContext (RTTI); cubecraft_1.h knows it as Unk_SkillMagicInfo.
// CSkillMagicControlGuide::SkillContext (RTTI)
class Unk_SkillMagicInfo : public CPtred
{
public:
    Unk_SkillMagicInfo();
    __int64 m_nTagId;                                       // +0x18
    int m_nSkillId;                                         // +0x20
    short m_nLevel;                                         // +0x24
    int m_nSrcLevel;                                        // +0x28
    int m_nSrcIndex;                                        // +0x2c
    int m_n30;                                              // +0x30
    ATL::CAtlList<Unk_MagicTagPtr> m_tags;                  // +0x38
};
MS2_CHECK_OFFSET(Unk_SkillMagicInfo, m_tags, 0x38);
MS2_CHECK_SIZE(Unk_SkillMagicInfo, 0x68);

// @0x1417463b0
Unk_SkillMagicInfo::Unk_SkillMagicInfo()
    : m_nTagId(0), m_nSkillId(0), m_nLevel(0), m_nSrcLevel(0), m_nSrcIndex(0), m_n30(0)
{
}

CSkillMagicControlGuide* FUN_141662610(PCBase* pOwner);   // the owner's skill-magic control guide

extern int DAT_143af25f8;                                    // set after a fitting doll's equipment changed
FittingDollPC* FUN_140884db0(PCBase* pObj);                 // the object as a fitting doll (class 0x6200046) or 0
void FUN_14121b840(int nId);                                // FittingDollPC: packet 0x7b mode 0xb

// A named field object of packet 0x73 (methods in an unrecovered unit near 0x141447800).
class Unk_SSGNamedObj : public CPtred
{
public:
    void FUN_1414477f0(CString strA, CString strB);
    void FUN_141447850(CString strA, CString strB);
    void FUN_141447a60(int n);
    void FUN_1414478b0(bool b);
    void FUN_141447aa0(bool b);
    void FUN_141447b00(int n);
};
typedef ATL::CAtlList<efd::SmartPointer<egf::Entity> > Unk_SSGEntList;
// 16-byte smart pointer to a boxed entity list (TPtredDummy<T>; the same COMDATs as autofindtaxistation's Unk_TaxiPtr).
struct Unk_SSGEntListPtr
{
    Unk_SSGEntList* get() const { return m_p; }
    Unk_SSGEntList* operator->() const { return m_p; }
    bool operator==(Unk_SSGEntList* p) const { return m_p == p; }
    ~Unk_SSGEntListPtr() { Release(); }
    void Release()
    {
        if (m_p)
        {
            ReleaseImpl(0);
            m_p = 0;
        }
    }
    void ReleaseImpl(void*)
    {
        CPtred* owner = Owner(m_p);
        if (CPtred::ReleasePtred(owner) == 0)
        {
            Ref(owner);
            CPtred::DeletePtred(owner);
        }
    }
    static void Ref(CPtred* p) { CPtred::AddRefPtred(p); }
    static TPtredDummy<Unk_SSGEntList>* Owner(Unk_SSGEntList* p)
    {
        return p == NULL ? NULL : reinterpret_cast<TPtredDummy<Unk_SSGEntList>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<Unk_SSGEntList>, value));
    }
    void* m_00;
    Unk_SSGEntList* m_p;
};
// ---- taxi-station markers -----------------------------------------------------------------------------------------
// The house privileges of the local player (MyPC +0x1628; commonfiles\homeprivilege.cpp).
class CHomePrivilege : public CPtred
{
public:
    int FUN_14050da30();                                    // the player may use the house taxi
};
// A property write saved while an entity's property cache is on (id, a heap copy of the value, its class id).
struct Unk_PropertyCacheEntry
{
    unsigned m_id;
    void* m_pValue;
    unsigned m_type;
};
MS2_CHECK_SIZE(Unk_PropertyCacheEntry, 0x18);
// A client entity with a property cache (egf::Entity subclass: +0xc8 caching on, +0xd0 the plain writes, +0xe0 the
// keyed writes). The cached values are written back and freed by FUN_141749ed0.
class Unk_SSGCachedEntity : public egf::Entity
{
public:
    void FUN_14174a6a0(bool bCaching) { m_bCaching = bCaching; }   // 0x14174a6a0
    void FUN_141749ed0();                                           // write the cached values back

    bool m_bCaching;                                                        // +0xc8
    efd::map<unsigned, Unk_PropertyCacheEntry> m_mapCache;                  // +0xd0
    efd::map<unsigned, efd::map<efd::utf8string, Unk_PropertyCacheEntry> > m_mapKeyedCache;   // +0xe0
};
MS2_CHECK_OFFSET(Unk_SSGCachedEntity, m_bCaching, 0xc8);
MS2_CHECK_OFFSET(Unk_SSGCachedEntity, m_mapCache, 0xd0);
MS2_CHECK_OFFSET(Unk_SSGCachedEntity, m_mapKeyedCache, 0xe0);

// 0x14174b5a0/0x14174b8d0, the exe calls the folded out-of-range 0x1413f5e20/0x1413f7400.
// @0x141749ed0
void Unk_SSGCachedEntity::FUN_141749ed0()
{
    for (efd::map<unsigned, Unk_PropertyCacheEntry>::iterator it = m_mapCache.begin(); it != m_mapCache.end(); ++it)
    {
        SetPropertyValueUnsafe(it->second.m_id, it->second.m_pValue, it->second.m_type);
        delete it->second.m_pValue;
    }
    m_mapCache.clear();
    for (efd::map<unsigned, efd::map<efd::utf8string, Unk_PropertyCacheEntry> >::iterator it = m_mapKeyedCache.begin();
         it != m_mapKeyedCache.end(); ++it)
    {
        efd::map<efd::utf8string, Unk_PropertyCacheEntry>& kKeyed = it->second;
        for (efd::map<efd::utf8string, Unk_PropertyCacheEntry>::iterator itKey = kKeyed.begin(); itKey != kKeyed.end();
             ++itKey)
        {
            SetPropertyValueUnsafe(itKey->second.m_id, itKey->first, itKey->second.m_pValue, itKey->second.m_type);
            delete itKey->second.m_pValue;
        }
    }
    m_mapKeyedCache.clear();
}
MS2_REPLACE_METHOD(0x141749ed0, Unk_SSGCachedEntity, FUN_141749ed0, 591, 0x17038293);

// @0x141739450
void CSceneStateGame::FUN_141739450(bool bFlag)
{
    Unk_SSGEntListPtr taxiStations = FUN_1403ed2d0()->FUN_141bd0420(0x85359406);
    if (taxiStations == 0)
        return;
    MS2_ASSERT_AT(0x2088, taxiStations->GetCount() <= 1);
    int bOpen = 0;
    if (FUN_1409f24a0()->FUN_14085f730(DAT_143ab2870))
    {
        MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        bool bHouseTaxi = pMyPC != 0 && pMyPC->FUN_140967010()->FUN_14050da30() != 0;
        if (bHouseTaxi)
            bOpen = 1;
    }
    else
    {
        bOpen = DAT_143ab3078.FUN_140408410(reinterpret_cast<const unsigned*>(&DAT_143ab2870)) >= 0;
    }
    for (POSITION pos = taxiStations->GetHeadPosition(); pos != 0; taxiStations->GetNext(pos))
    {
        efd::SmartPointer<egf::Entity> spEntity = taxiStations->GetAt(pos);
        FUN_141739880();
        efd::Point3 kPos;
        Unk_SSGXform xf;
        FUN_140a332d0(&xf);
        spEntity->GetPropertyValue(0xfd95ca52, kPos);
        xf.FUN_141d2fab0();
        Unk_SSGNiPt3 kNiPos(kPos);
        FUN_14097faa0(&xf.m_translate, kNiPos);
        if (bFlag)
        {
            Unk_SSGEffectReq req;
            req.m_strName = FUN_1401d31f0()->m_str380;
            req.m_nType = 0;
            req.m_pXform = &xf;
            FUN_1403ed280()->FUN_1411a4a00(req);
        }
        if (bOpen)
        {
            static_cast<Unk_SSGCachedEntity*>(static_cast<egf::Entity*>(spEntity))->FUN_141749ed0();
            Unk_SSGEffectReq req;
            req.m_strName = FUN_1401d31f0()->m_str360;
            req.m_nType = 0;
            req.m_pXform = &xf;
            m_nTaxiEffect = FUN_1403ed280()->FUN_1411a49c0(req);
        }
        else
        {
            efd::AssetID kAsset;
            if (spEntity->GetPropertyValue(0x78cb6d8d, kAsset) == 0)
            {
                static_cast<Unk_SSGCachedEntity*>(static_cast<egf::Entity*>(spEntity))->FUN_14174a6a0(true);
                spEntity->SetPropertyValue(0x770e5fc6, kAsset);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141739450, CSceneStateGame, FUN_141739450, 1057, 0x227E65F0);


efd::ID128* FUN_140ae1be0(egf::Entity* pEntity);            // the entity's data file id
void FUN_140ae1f60(efd::ID128* pId, efd::utf8string& strOut);   // the id as text
void FUN_1401d3700(CString& str);                           // normalise a name
Unk_Int3 FUN_1408a1430(efd::Point3 kPos);                   // the cube cell of a world position

// Packet 0x73: named field objects (state sync, remove).
// @0x141729250
void CSceneStateGame::OnLiftable(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
    {
        int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
        efd::set<CString> names;
        for (int i = 0; i < nCount; i++)
        {
            CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
            bool bEnable = static_cast<CInputStream&>(packet).vfunc_o8_1() == 0 ? false : true;
            int nState = static_cast<CInputStream&>(packet).vfunc_o8_3();
            int nKind = static_cast<CInputStream&>(packet).vfunc_o8_1();
            CString strA = static_cast<CInputStream&>(packet).vfunc_o8_6();
            CString strB = static_cast<CInputStream&>(packet).vfunc_o8_6();
            CString strC = static_cast<CInputStream&>(packet).vfunc_o8_6();
            CString strD = static_cast<CInputStream&>(packet).vfunc_o8_6();
            bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_0();
            names.insert(strName);
            MS2Ptr<Unk_SSGNamedObj> spObj = FUN_1403ed2d0()->FUN_141bc5a20(strName);
            if (spObj.get() != 0)
            {
                spObj->FUN_1414477f0(strA, strB);
                spObj->FUN_141447850(strC, strD);
                spObj->FUN_141447a60(nState);
                spObj->FUN_1414478b0(bEnable);
                spObj->FUN_141447aa0(bFlag);
                spObj->FUN_141447b00(nKind);
            }
        }
        Unk_SSGEntListPtr list = FUN_1403ed2d0()->FUN_141bd0420(0x32767dd);
        if (list.get() != 0)
        {
            for (POSITION pos = list->GetHeadPosition(); pos != 0; list->GetNext(pos))
            {
                egf::Entity* pEntity = list->GetAt(pos);
                efd::utf8string strId;
                FUN_140ae1f60(FUN_140ae1be0(pEntity), strId);
                CString strName(strId.c_str());
                FUN_1401d3700(strName);
                if (names.find(strName) == names.end())
                {
                    efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
                    efd::Point3 kPos = efd::Point3::ZERO;
                    pEntity->GetPropertyValue(0xfd95ca52, kPos);
                    Unk_Int3 kCell = FUN_1408a1430(kPos);
                    spService->FUN_1410c4b50(kCell, 0);
                    FUN_1403ed2d0()->FUN_141bc5830(strName);
                }
            }
        }
    }
        break;
    case 2:
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        bool bEnable = static_cast<CInputStream&>(packet).vfunc_o8_1() == 0 ? false : true;
        int nState = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nKind = static_cast<CInputStream&>(packet).vfunc_o8_1();
        MS2Ptr<Unk_SSGNamedObj> spObj = FUN_1403ed2d0()->FUN_141bc5a20(strName);
        if (spObj.get() != 0)
        {
            spObj->FUN_141447a60(nState);
            spObj->FUN_1414478b0(bEnable);
            spObj->FUN_141447b00(nKind);
        }
    }
        break;
    case 3:
        FUN_1403ed2d0()->FUN_141bc5420(packet);
        break;
    case 4:
    {
        CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
        FUN_1403ed2d0()->FUN_141bc5830(strName);
    }
        break;
    }
}
MS2_REPLACE_METHOD(0x141729250, CSceneStateGame, OnLiftable, 2696, 0x7EC41E6F);

template <> MS2Ptr<Unk_RideeData>::~MS2Ptr();                                           // 0x140788ed0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::operator->() const;                   // 0x1407895d0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::get() const;                          // 0x1409f78a0
template <> MS2Ptr<Unk_RideeModel>::~MS2Ptr();                                          // 0x140788ea0
template <> Unk_RideeModel* MS2Ptr<Unk_RideeModel>::operator->() const;                 // 0x1407895c0
template <> Unk_RideeModel* MS2Ptr<Unk_RideeModel>::get() const;                        // 0x140789570
MS2Ptr<Unk_RideeData> FUN_1407844b0(int nRideeId);             // the ridee table row of an id

// Packet 0x79: riding (ride on / ride off / mount summon / passenger seats / ride flag).
// @0x14172a8f0
void CSceneStateGame::OnResponseRide(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<RideOnAction> spAction = FUN_14077deb0(&static_cast<CInputStream&>(packet));
        PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
        if (pActor == 0)
            return;
        pActor->vfunc_120(spAction);
    }
    else if (nMode == 1)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
        if (pActor == 0)
            return;
        MS2Ptr<RideOffAction> spAction = FUN_14077e5b0(&static_cast<CInputStream&>(packet));
        pActor->vfunc_121(spAction);
    }
    else if (nMode == 2)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
        if (pActor == 0)
            return;
        pActor->vfunc_121(MS2Ptr<RideOffAction>(0));
        if (pActor->GetClassID() == 0x6200004)
        {
            int nRideeId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
            MS2Ptr<Unk_RideeData> spData = FUN_1407844b0(nRideeId);
            if (spData.get() != 0)
                pActor->vfunc_59(0x26, new StateSummonData(reinterpret_cast<void*>(nItemUid), 0), 0, 0);
        }
    }
    else if (nMode == 3)
    {
        int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nRiderId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nSeat = static_cast<CInputStream&>(packet).vfunc_o8_1();
        CString strNode("");
        PC* pOwner = FUN_1403ed2d0()->FUN_141bd1290(nOwnerId);
        if (pOwner == 0)
            return;
        pOwner->FUN_141676670(nRiderId, nSeat);
        MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC != 0 && pMyPC->FUN_14123c580() == nRiderId)
        {
            efd::SmartPointer<Ridee> spRidee = pOwner->FUN_1416764a0();
            if (spRidee)
            {
                MS2Ptr<Unk_RideeModel> spModel = spRidee->GetData()->FUN_1407849c0(nSeat);
                if (spModel.get() != 0)
                    strNode = spModel->m_strNode;
            }
            MS2Ptr<StateHoldData> spHold = new StateHoldData;
            spHold->m_nTargetId = nOwnerId;
            spHold->m_strTargetName = strNode;
            pMyPC->vfunc_59(0x20, spHold, 0, 0);
        }
    }
    else if (nMode == 4)
    {
        int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nRiderId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pOwner = FUN_1403ed2d0()->FUN_141bd1290(nOwnerId);
        if (pOwner == 0)
            return;
        pOwner->FUN_141676730(nRiderId);
        MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC != 0 && pMyPC->FUN_14152e060() == nOwnerId)
            FUN_1409478c0()->FUN_140aeaf40(pMyPC, 1);
    }
    else if (nMode == 5)
    {
        int nOwnerId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pOwner = FUN_1403ed2d0()->FUN_141bd1290(nOwnerId);
        if (pOwner == 0)
            return;
        pOwner->FUN_141676700();
        MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC != 0 && pMyPC->FUN_14152e060() == nOwnerId)
            FUN_1409478c0()->FUN_140aeaf40(pMyPC, 1);
    }
    else if (nMode == 6)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            return;
        pPC->FUN_1416642c0(bFlag);
        RideOnAction* pAction = pPC->FUN_141676370().get();
        if (pAction != 0)
            pPC->FUN_141676370()->m_b28 = bFlag;
    }
}
MS2_REPLACE_METHOD(0x14172A8F0, CSceneStateGame, OnResponseRide, 2640, 0x4B945ADF);

// Packet 0x7b: fitting dolls (housing mannequins).
// @0x14172b350
void CSceneStateGame::FUN_14172b350(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 4)
        return;
    if (nMode == 5)
        return;
    if (nMode == 0)
    {
        MS2Ptr<FittingDollData> spDoll(new FittingDollData());
        spDoll->kind = static_cast<CInputStream&>(packet).vfunc_o8_3();
        spDoll->instanceId = static_cast<CInputStream&>(packet).vfunc_o8_4();
        spDoll->field28 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        reinterpret_cast<Unk_StreamPoint&>(spDoll->position) = static_cast<CInputStream&>(packet).vfunc_o8_10();
        reinterpret_cast<Unk_StreamPoint&>(spDoll->rotation) = static_cast<CInputStream&>(packet).vfunc_o8_10();
        spDoll->field44 = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (spDoll->field44 != 0)
        {
            spDoll->field48 = static_cast<CInputStream&>(packet).vfunc_o8_3();
            for (unsigned __int64 i = 0; i < static_cast<unsigned int>(spDoll->field48); i++)
            {
                int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
                int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_1();
                int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
                MS2Ptr<CItem> spItem(new CItem());
                if (!spItem->FUN_140523c40(nItemId, nRarity, 0))
                    return;
                spItem->FUN_140524eb0(packet);
                spItem->FUN_140526b30(spDoll->kind);
                spItem->FUN_140526a70(nItemUid);
                spItem->FUN_140526c10(nSlot);
                spDoll->items.Add(spItem);
            }
        }
        Unk_Service6100017* pCubeMap = FUN_1401cd040(&DAT_143b059e8);
        pCubeMap->FUN_1410cb4c0(spDoll);
    }
    else if (nMode == 1)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_1403ed2d0()->FUN_141bbbcf0(nId, 0);
    }
    else if (nMode == 6)
    {
        __int64 nOwnerUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nItemId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nRarity = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem());
        if (!spItem->FUN_140523c40(nItemId, nRarity, 0))
            return;
        FittingDollPC* pDoll = FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(nOwnerUid));
        if (pDoll != 0)
        {
            spItem->FUN_140526b30(pDoll->FUN_14123c580());
            spItem->FUN_140526a70(nItemUid);
            spItem->FUN_140526c10(nSlot);
            spItem->FUN_140524eb0(packet);
            pDoll->vfunc_127(spItem.get(), 0);
        }
        DAT_143af25f8 = 1;
    }
    else if (nMode == 7)
    {
        __int64 nOwnerUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_1();
        FittingDollPC* pDoll = FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(nOwnerUid));
        if (pDoll != 0)
        {
            int nKind = 0;
            if (pDoll->FUN_14121c710() != 0)
                nKind = 1;
            MS2Ptr<CEquipItem> spEquip = pDoll->FUN_141655e80(nSlot, nKind);
            bool bSame = static_cast<bool>(spEquip.get()) && spEquip->GetItem()->FUN_140527a20() == nSlot;
            if (bSame)
                pDoll->vfunc_128(spEquip->GetItem().get(), 0);
        }
        DAT_143af25f8 = 1;
    }
    else if (nMode == 8)
    {
        if (FUN_140166410()->FUN_14036d570(0xd4))
        {
            __int64 nOwnerUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
            bool bPose = true;
            int nResult = static_cast<CInputStream&>(packet).vfunc_o8_3();
            switch (nResult)
            {
            case 0x17:
                FUN_140d73bc0(0x86c, 0, 0, L"");
                break;
            case 0x18:
                FUN_140d73bc0(0x86d, 0, 0, L"");
                break;
            case 0x19:
                bPose = false;
                break;
            default:
                MS2_ASSERT_AT(0x1d7d, 0);
            }
            if (bPose)
            {
                FittingDollPC* pDoll = FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(nOwnerUid));
                if (pDoll != 0)
                {
                    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
                    if (pMyPC != 0)
                    {
                        pMyPC->vfunc_59(0x22, 0, 0, 0);
                        if (pDoll->FUN_14166c930() != 0x22)
                            pDoll->vfunc_59(0x22, 0, 0, 0);
                    }
                }
            }
        }
    }
    else if (nMode == 0xb)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_14121b840(nId);
    }
}
MS2_REPLACE_METHOD(0x14172B350, CSceneStateGame, FUN_14172b350, 3596, 0x220A03F9);

// @0x14172c170
void CSceneStateGame::FUN_14172c170(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 0)
    {
        int nType = static_cast<unsigned short>(static_cast<CInputStream&>(packet).vfunc_o8_2());
        int nGuideId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nOwnerUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        Unk_StreamPoint ptPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
        Unk_StreamPoint ptDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
        PCBase* pOwner = FUN_1403ed2d0()->FUN_141bd1530(nOwnerUid);
        if (pOwner == 0)
            return;
        efd::SmartPointer<CGuideObject> spGuide(0);
        if (nType == 0)
        {
            int nItemId = static_cast<int>(static_cast<CInputStream&>(packet).vfunc_o8_4());
            efd::SmartPointer<CConstructionGuideObject> spBuild = EE_NEW CConstructionGuideObject;
            if (spBuild->FUN_1410a1ee0(nGuideId, reinterpret_cast<efd::Point3&>(ptPos), reinterpret_cast<efd::Point3&>(ptDir), pOwner, nItemId) == 0)
                return;
            spGuide = spBuild;
        }
        else if (nType == 1)
        {
            efd::SmartPointer<CFishingGuideObject> spFish = EE_NEW CFishingGuideObject;
            if (spFish->vfunc_124(nGuideId, reinterpret_cast<efd::Point3&>(ptPos), reinterpret_cast<efd::Point3&>(ptDir), pOwner) == 0)
                return;
            spGuide = spFish;
        }
        else if (nType == 2)
        {
            int nTimeMode = FUN_1403ed2d0()->FUN_141bd1a10(pOwner);
            int nStartTick = Unk_ServerClock::GetInstance()->FUN_1414732f0(nTimeMode);
            MS2Ptr<Unk_SkillMagicInfo> spInfo(new Unk_SkillMagicInfo);
            spInfo->m_nTagId = static_cast<CInputStream&>(packet).vfunc_o8_4();
            spInfo->m_nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
            spInfo->m_nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
            spInfo->m_nSrcLevel = static_cast<CInputStream&>(packet).vfunc_o8_1();
            spInfo->m_nSrcIndex = static_cast<CInputStream&>(packet).vfunc_o8_1();
            unsigned char nCount = static_cast<CInputStream&>(packet).vfunc_o8_1();
            for (unsigned char i = 0; i < nCount; i++)
            {
                __int64 nTagSub = static_cast<CInputStream&>(packet).vfunc_o8_4();
                unsigned char n84 = static_cast<CInputStream&>(packet).vfunc_o8_1();
                Unk_MagicTagPtr spTag(new Unk_MagicTag);
                if (spTag->FUN_141758d70(spInfo->m_nTagId, nTagSub, pOwner->FUN_14123c580(), 0, spInfo->m_nSkillId,
                        spInfo->m_nLevel, spInfo->m_nSrcLevel, ptDir, 0, n84, spInfo->m_nSrcIndex, 0))
                {
                    spTag->m_nStartTick = nStartTick;
                    spInfo->m_tags.AddTail(spTag);
                }
            }
            efd::SmartPointer<CSkillMagicControlGuide> spSkill = EE_NEW CSkillMagicControlGuide;
            if (spSkill->FUN_1410a5ea0(nGuideId, reinterpret_cast<efd::Point3&>(ptPos), reinterpret_cast<efd::Point3&>(ptDir), pOwner, spInfo) == 0)
                return;
            FUN_1403ed2d0()->FUN_141bc5ab0(spSkill);
            spGuide = spSkill;
        }
        if (!spGuide)
            return;
        spGuide->vfunc_127();
        FUN_1403ed2d0()->FUN_141bbb1e0(spGuide, 0, 1);
    }
    else if (nMode == 1)
    {
        int nGuideId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nOwnerUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        PCBase* pOwner = FUN_1403ed2d0()->FUN_141bd1530(nOwnerUid);
        if (pOwner == 0)
            return;
        GameObject* pObj = FUN_1403ed2d0()->FUN_141bd1180(nGuideId);
        if (pObj == 0)
            return;
        CGuideObject* pGuide = efd::DynamicCast<CGuideObject>(pObj);
        if (pGuide == 0)
            return;
        pGuide->vfunc_128();
        FUN_1403ed2d0()->FUN_141bbbcf0(nGuideId, 0);
        MyPC* pMyPC = FUN_1409613d0(pOwner);
        if (pMyPC != 0 && pMyPC->FUN_141530290() != 0)
        {
            pMyPC->FUN_141530200();
            FUN_141275260(0xbb2, 1, 1);
        }
    }
    else if (nMode == 2)
    {
        int nGuideId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        GameObject* pObj = FUN_1403ed2d0()->FUN_141bd1180(nGuideId);
        if (pObj == 0)
            return;
        CGuideObject* pGuide = efd::DynamicCast<CGuideObject>(pObj);
        if (pGuide == 0)
            return;
        pGuide->vfunc_129(&packet);
    }
    else if (nMode == 3)
    {
        int nGuideId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nOwnerUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        PCBase* pOwner = FUN_1403ed2d0()->FUN_141bd1530(nOwnerUid);
        if (pOwner == 0)
            return;
        CSkillMagicControlGuide* pSkill = FUN_141662610(pOwner);
        if (pSkill == 0)
            return;
        if (pSkill->FUN_14123c580() != nGuideId)
            return;
        pSkill->FUN_1410a6520();
    }
}
MS2_REPLACE_METHOD(0x14172C170, CSceneStateGame, FUN_14172c170, 3949, 0x6D5C85AE);
