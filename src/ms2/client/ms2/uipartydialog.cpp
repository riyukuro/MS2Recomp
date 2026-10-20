// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The party UI: ASPartyVotePage and UIPartyDialog (the party
// window), UIPartyDPSDialog, UIPerformanceDialog, UIPopupEntity and UIPopUpMenu. The exe range holds five original TUs
// (five header-static initializer groups in .text$di, one memmove_s copy); they are recovered here as one file.
// MS2-UNIT: client\ms2\uipartydialog.cpp
// MS2-RANGE: 0x14011a360-0x14011aab0 .text$di
// MS2-RANGE: 0x141a738f0-0x141a8f3a0 .text$mn
// MS2-PIN: ??$Unk_PdSetData@W4Unk_PdTombType@@@@YAXPEAVASObj@@PEBDW4Unk_PdTombType@@@Z 0x141a7a1c0 ; manual: byte-identical pair, first use first
// MS2-PIN: ??$Unk_PdSetData@H@@YAXPEAVASObj@@PEBDH@Z 0x141a7a260 ; manual
// MS2-PIN: ??$Unk_PdSetData@W4Unk_PmMenuType@@@@YAXPEAVASObj@@PEBDW4Unk_PmMenuType@@@Z 0x141a87860 ; manual: byte-identical pair, first use first
// MS2-PIN: ??$Unk_PdSetData@W4Unk_PmDir@@@@YAXPEAVASObj@@PEBDW4Unk_PmDir@@@Z 0x141a87900 ; manual
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0VASPartyVotePage@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVASPartyVotePage@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x141a79960 ; unique
// MS2-PIN: ??$?0VUIPartyDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIPartyDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x141a79b00 ; unique
// MS2-PIN: ??$?8PEAVUIPartyDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIPartyDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x141a79cb0 ; prop
// MS2-PIN: ??$?8PEAVUIPartyDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIPartyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x141a79d20 ; prop
// MS2-PIN: ??$?8PEAVUIPartyDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIPartyDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x141a79d90 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x141a7a680 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAA@XZ 0x141a7a7b0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAPEAXI@Z 0x141a7a970 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVASPartyVotePage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a7ab90 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a7abf0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a7ac50 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a7acb0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVASPartyVotePage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141a7ad10 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x141a7ad40 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141a7ad70 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141a7ada0 ; unique
// MS2-PIN: ??$Call@VASPartyVotePage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVASPartyVotePage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVASPartyVotePage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141a7ade0 ; unique
// MS2-PIN: ??$Call@VUIPartyDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIPartyDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x141a7ae10 ; prop
// MS2-PIN: ??$Call@VUIPartyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIPartyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141a7ae50 ; prop
// MS2-PIN: ??$Call@VUIPartyDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIPartyDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x141a7ae90 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVASPartyVotePage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a7aed0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a7af30 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a7af90 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIPartyDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a7aff0 ; unique
// MS2-PIN: ??_GUIPartyDPSDialog@@UEAAPEAXI@Z 0x141a7c470 ; unique
// MS2-PIN: ??$StringFormat@MI@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBMAEBI@Z 0x141a7c780 ; unique
// MS2-PIN: ??_GUIPerformanceDialog@@UEAAPEAXI@Z 0x141a7caa0 ; unique
// MS2-PIN: ??_GUIPopupEntity@@UEAAPEAXI@Z 0x141a7d410 ; unique
// MS2-PIN: memmove_s 0x141a7d460 ; unique
// MS2-PIN: ??$?8PEAVUIPopUpMenu@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIPopUpMenu@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x141a87590 ; prop
// MS2-PIN: ??$?8PEAVUIPopUpMenu@@P80@EAAXXZ@std@@YA_NAEBU?$pair@PEAVUIPopUpMenu@@P81@EAAXXZ@0@0@Z 0x141a87600 ; prop
// MS2-PIN: ??$?8PEAVUIPopUpMenu@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIPopUpMenu@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x141a87670 ; prop
// MS2-PIN: ??$Unk_PmGetDialog@VUIPCInfoDialog@@@@YAPEAVUIPCInfoDialog@@H@Z 0x141a877c0 ; unique
// MS2-PIN: ??$Unk_PmShowYesNo@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@@YA?AV?$MS2Ptr@VCMsgBoxData@@@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@0@Z 0x141a879a0 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$Delegate@$$A6AXXZ@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Delegate@$$A6AXXZ@@@3@@ATL@@IEAA@H@Z 0x141a88150 ; unique
// MS2-PIN: ??1CPair@?$CAtlMap@HV?$Delegate@$$A6AXXZ@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Delegate@$$A6AXXZ@@@3@@ATL@@QEAA@XZ 0x141a88490 ; unique
// MS2-PIN: ??_EUIPopUpMenu@@WHA@EAAPEAXI@Z 0x141a88774 ; unique
// MS2-PIN: ??_EUIPopUpMenu@@WHI@EAAPEAXI@Z 0x141a88780 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAAXXZ@std@@@?$Delegate@$$A6AXXZ@@UEAAPEAXI@Z 0x141a887d0 ; prop
// MS2-PIN: ??_GUIPopUpMenu@@UEAAPEAXI@Z 0x141a888d0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Delegate@$$A6AXXZ@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Delegate@$$A6AXXZ@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x141a88c50 ; unique
// MS2-PIN: ?vfunc_48@UIPopUpMenu@@UEAAHXZ 0x141a88d40 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a89c90 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAAXXZ@std@@@?$Delegate@$$A6AXXZ@@UEBAPEAVDelegateImplBase@2@XZ 0x141a89cf0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a89d50 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x141a89db0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141a89e00 ; unique
// MS2-PIN: ??$Call@VUIPopUpMenu@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIPopUpMenu@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x141a89e40 ; prop
// MS2-PIN: ??$Call@VUIPopUpMenu@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIPopUpMenu@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x141a89eb0 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a89ef0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAAXXZ@std@@@?$Delegate@$$A6AXXZ@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a89f50 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIPopUpMenu@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a89fb0 ; unique
// MS2-PIN: ??$forward@AEAPEAPEAVGameObject@@@std@@YAAEAPEAPEAVGameObject@@AEAPEAPEAV1@@Z 0x141a8dc70 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_List_node@PEAVUnk_GoPickHit@@PEAX@std@@@std@@YAAEAPEAU?$_List_node@PEAVUnk_GoPickHit@@PEAX@0@AEAPEAU10@@Z 0x141a8dc80 ; unique
// MS2-PIN: ??$forward@AEAPEAVGameObject@@@std@@YAAEAPEAVGameObject@@AEAPEAV1@@Z 0x141a8dc90 ; unique
// MS2-PIN: ??0?$allocator@PEAVGameObject@@@std@@QEAA@XZ 0x141a8e060 ; unique
// MS2-PIN: ??R<lambda_33b4866407a6444b0fe51dcd18b2ae7a>@@QEBA_NPEAVGameObject@@0@Z 0x141a8e3f0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@PEAVGameObject@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVGameObject@@@std@@@2@$00@std@@QEAAAEAV?$allocator@PEAVGameObject@@@2@XZ 0x141a8e970 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@PEAVGameObject@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVGameObject@@@std@@@2@$00@std@@QEBAAEBV?$allocator@PEAVGameObject@@@2@XZ 0x141a8e980 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@PEAVUnk_GoPickHit@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@PEAVUnk_GoPickHit@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_List_node@PEAVUnk_GoPickHit@@PEAX@std@@@2@XZ 0x141a8e990 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@PEAVGameObject@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVGameObject@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVGameObject@@@std@@@2@XZ 0x141a8e9b0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@PEAVGameObject@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVGameObject@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVGameObject@@@std@@@2@XZ 0x141a8e9c0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_List_node@PEAVUnk_GoPickHit@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@PEAVUnk_GoPickHit@@@std@@@2@$00@std@@QEAAAEAV?$_List_val@U?$_List_simple_types@PEAVUnk_GoPickHit@@@std@@@2@XZ 0x141a8e9d0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipartydialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/header_statics_a.h"
#include "uipartydialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/cpartymember.h"
#include "ms2/placeholder/partyvotecli.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/roomstagedungeoncli.h"
#include "ms2/placeholder/cmycharacter.h"
#include "ms2/placeholder/uipopupentity.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/placeholder/cpet.h"
#include "ms2/client/ms2/portraitpc.h"
#include "ms2/client/ms2/scenestatebase.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cinteractobjectdata.h"
#include <ecr/PickService.h>
#include <ecr/SceneGraphService.h>
#include <egf/Entity.h>
#include <list>
#include <vector>
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/commonfiles/clubcommon.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/homeblockmanager.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/client/ms2/ms2clientplatformbase.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uipcinfodialog.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/battlerecordmanager.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/mstime.h"
#include <algorithm>
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/commandchat.h"

// ---- Delegate<void()> (UIPopUpMenu's menu handlers, RTTI vftable 0x142fd4958): this TU's own COMDAT copies. The
// TInterpolator / OnceCallbackTimer callbacks bound at 0x1401cffb0 / 0x14098d150 are TFunctor<void, EmptyParam>. ----
void FUN_140657820();                                                   // throws on a call through an empty delegate

// @0x141a882b0
template <> Delegate<void()>::DelegateImplBase::DelegateImplBase() {}

// @0x141a884b0
template <> Delegate<void()>::DelegateImplBase::~DelegateImplBase() {}

// @0x141a883b0
template <> Delegate<void()>::~Delegate()
{
    if (m_pImpl)
        delete m_pImpl;
}

// @0x141a88650
template <> Delegate<void()>& Delegate<void()>::operator=(const Delegate<void()>& o)
{
    if (this == &o)
        return *this;
    if (m_pImpl)
        delete m_pImpl;
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
    return *this;
}

// @0x141a88740
template <> void Delegate<void()>::operator()() const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2();
}

// ---- out-of-unit callees ----
class Unk_PdWorld                                                       // the world service (FUN_1403ed2d0)
{
public:
    MyPC* FUN_141bd0cc0();                                              // the local player
    PC* FUN_141bd1530(__int64 nCharId);                                 // a player by character id
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                              // the current field data
    int FUN_141bc2bc0();
    int FUN_141bc2b30();
    GameObject* FUN_141bd0fe0(unsigned __int64 nObjectId);              // a game object by id
    MS2Ptr<CProxyGameObject> FUN_141bc9be0(unsigned int nObjectId);     // the proxy of an object id
};
Unk_PdWorld* FUN_1403ed2d0();
class Unk_PdApp                                                         // the application / ui service (FUN_1403ed2b0)
{
public:
    const CString& FUN_141adc530(int nUiId);                            // toggle a dialog
    void FUN_141adc690(int nUiId);                                      // open a dialog
    int FUN_141adc7f0(int nUiId);                                       // is a dialog registered
    int FUN_141adc940(int nUiId);                                       // is a dialog open
    float FUN_141adbe70();                                              // the ui scale
    MS2Ptr<UIObject> FUN_141adcea0(int nUiId);                          // a dialog by id
};
Unk_PdApp* FUN_1403ed2b0();
void FUN_141add1f0(Unk_PdApp* pApp);                                    // open the merat charge page
CPartyManager* FUN_1409670d0();                                         // TSingleton<CPartyManager>::GetInstance
CFeatureManager* FUN_140166410();                                       // TSingleton<CFeatureManager>::GetInstance
CStringTable* FUN_1401a9d70();                                          // TSingleton<CStringTable>::GetInstance
IClientPlatform* FUN_140d86260();
class Unk_PdPopupMenu;                                                  // UIPopUpMenu (below) as seen by the lookup
UIDialog* FUN_140c30140(int nDialogId);                                 // the open dialog of this id
class Unk_PdClubManager { public: int FUN_140b14cd0(); void FUN_140b15c10(CStringW strName); };
Unk_PdClubManager* FUN_140e0d900();
class Unk_PdNametagFlags { public: char m_00[0x30]; bool m_30; };       // m_30: show the returning-user mark
Unk_PdNametagFlags* FUN_1406c7610();
class Unk_PdKeyState;                                                   // the input state; +8 is the lock set (FUN_1402c4c90)
char* FUN_14025e7b0();
int FUN_1402c4c90(void* pLocks, int nLock);
bool FUN_140930b10();
bool FUN_140930b40();
CMyCharacter* FUN_140931510();
unsigned int FUN_140869420();                                           // the server time (seconds)
extern __int64 DAT_143ab2828;                                           // the own character id
extern int DAT_1439f4a7c;
extern Unk_Inventory DAT_143ab2a90;

CString FUN_140719530(unsigned __int64 n);                              // decimal text
__int64 FUN_140718350(const CString& str);                              // parse an __int64
CStringW FUN_140719630(int n);                                          // decimal text
double FUN_140f17ed0(const Scaleform::GFx::Value& v);                   // a number value
bool FUN_141a4bfb0(const Scaleform::GFx::Value& v);                     // is a bool value
bool FUN_1409c1720(const Scaleform::GFx::Value& v);                     // the bool value
CStringW FUN_1408116a0(int nStringId, const int& n);                    // FormatStringId<int>
CStringW FUN_140632a60(int nStringId, const CStringW& a, const CStringW& b);   // FormatStringId<CStringW, CStringW>
CStringW FUN_14028de60(int nStringId);                                  // the string of an id
CStringW FUN_14028b8e0(const CStringW& strKey);                         // the string of a key
void FUN_1412751f0(const CStringW& strText, int nA, int nB);            // system message
void FUN_140d73bc0(int nStringId, int nA, int nB, CStringW strText);    // notice by id
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, IMessageListener* pListener, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);   // yes / no box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                            // show a box
void FUN_140710590(COutPacket& packet);                                 // send
void FUN_14151f200();                                                   // close the message box
void FUN_14025a680(CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szSep);   // split
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
int FUN_141637c40(CPartyMember* pMember);                               // the member state
double FUN_1407184e0(const CStringW& str);                              // parse a number
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);     // FUN_14028dfa0<CStringW>
CStringW FUN_140c2fcc0(CStringW strFormat, const int& nHour, const int& nMinute, const int& nSecond, const CStringW& strArg);
void FUN_141b70810(unsigned nMs, CStringW& strOut);                     // elapsed time text
// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
void FUN_141276f80(const Unk_CommandChat& kChat);                            // post a chat record
class Unk_PdMainSystem { public: unsigned int FUN_141473460(); float FUN_141473210(); };   // CMainSystem: draw count, fps
Unk_PdMainSystem* FUN_14086d260();
extern const wchar_t DAT_142fd11d4[];                                   // L","
extern const char DAT_142fd1144[];                                      // "x"
extern const char DAT_142fd116c[];                                      // "y"

// AScript members this unit calls that the shared header does not declare (same this / return ABI).
struct Unk_PdScript : AScript
{
    Scaleform::GFx::Value FUN_140f0c520(const char* szMethod, CString a1, Scaleform::GFx::Value a2);   // Invoke(method, string, value)
    Scaleform::GFx::Value FUN_140e06cc0(const char* szMethod, double d);   // Invoke(method, number) (uichaosdpsdialog.cpp)
    Scaleform::GFx::Value FUN_1422bb330(const char* szMethod);             // Invoke(method)
    using AScript::m_value;
};

// ASObj member setters through an ASData argument (one COMDAT per value type in this unit).
template <class T> void Unk_PdSetData(ASObj* pObj, const char* szName, T value)
{
    ASData data;
    data.FUN_1422b7f70(value);
    FUN_1407cd930(&static_cast<Unk_PdScript*>(static_cast<AScript*>(pObj))->m_value, szName, data.FUN_1422b9260());
}
enum Unk_PdTombType : int { Unk_PdTombNone = 0 };

#define PD_SWF_ERROR(line) new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(line), __FUNCTION__))

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> PdParamsDelegate;

// ======== ASPartyVotePage ========

// @0x141a738f0
ASPartyVotePage::ASPartyVotePage(MS2Ptr<ASMovieClip> spPage)
    : m_page(spPage)
{
}

// @0x141a739c0
ASPartyVotePage::~ASPartyVotePage()
{
}

// MS2-FUNCTIONAL: written from the decompile (frame slots of the binder temporaries unverified)
// @0x141a73a70
void ASPartyVotePage::OnInit()
{
    if (m_page == 0)
        throw PD_SWF_ERROR(0x27);
    m_page->vfunc_4(false);
    m_page->FUN_140beaf20("m_title", m_title);
    if (m_title == 0)
        throw PD_SWF_ERROR(0x2d);
    m_page->FUN_140beaf20("m_yesCount", m_yesCount);
    if (m_yesCount == 0)
        throw PD_SWF_ERROR(0x2e);
    m_page->FUN_140beaf20("m_noCount", m_noCount);
    if (m_noCount == 0)
        throw PD_SWF_ERROR(0x2f);
    m_page->FUN_140bbe640("m_yesButton", m_yesButton);
    if (m_yesButton == 0)
        throw PD_SWF_ERROR(0x30);
    m_page->FUN_140bbe640("m_noButton", m_noButton);
    if (m_noButton == 0)
        throw PD_SWF_ERROR(0x31);
    m_page->FUN_140beaf20("m_votedText", m_votedText);
    if (m_votedText == 0)
        throw PD_SWF_ERROR(0x32);
    m_yesButton->FUN_1422ce240(PdParamsDelegate(this, &ASPartyVotePage::FUN_141a74a60), 0);
    m_noButton->FUN_1422ce240(PdParamsDelegate(this, &ASPartyVotePage::FUN_141a74a90), 0);
}

// @0x141a74760
void ASPartyVotePage::FUN_141a74760()
{
    if (!(m_page == 0))
    {
        MS2Ptr<PartyVoteCli> spVote = FUN_1409670d0()->FUN_14162c350();
        if (!(spVote == 0) && spVote->vfunc_5())
        {
            m_page->vfunc_4(true);
            CStringW strTitle = spVote->vfunc_4();
            m_title->FUN_1422c4f00(strTitle);
            m_yesCount->FUN_1422c4cd0(FUN_140719630((int)spVote->FUN_140a89560()));
            m_noCount->FUN_1422c4cd0(FUN_140719630((int)spVote->FUN_140a89590()));
            bool bVoted = spVote->FUN_140a895c0();
            m_yesButton->vfunc_4(!bVoted);
            m_noButton->vfunc_4(!bVoted);
            m_votedText->vfunc_4(bVoted);
            return;
        }
        m_page->vfunc_4(false);
    }
}

// @0x141a74a60
void ASPartyVotePage::FUN_141a74a60(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_141a74ac0(true);
}

// @0x141a74a90
void ASPartyVotePage::FUN_141a74a90(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_141a74ac0(false);
}

// @0x141a74ac0
void ASPartyVotePage::FUN_141a74ac0(bool bYes)
{
    MS2Ptr<PartyVoteCli> spVote = FUN_1409670d0()->FUN_14162c350();
    if (spVote == 0)
        return;
    spVote->FUN_140a89680(bYes);
}

// ======== UIPartyDialog ========

// @0x141a74b40
UIPartyDialog::UIPartyDialog()
    : m_deadline(0)
{
    m_2c = 0x11;
    FUN_141925e70(0, 1);
}

// @0x141a74c50
UIPartyDialog::~UIPartyDialog()
{
}

// @0x141a74d00
CString UIPartyDialog::vfunc_1()
{
    return "PartyDialog";
}

// @0x141a74d50
void UIPartyDialog::FUN_141a74d50(CPartyMember* pMember, int nFlags)
{
    if (!(m_30 == 0) && pMember != 0)
    {
        ASObj obj(2);
        if (FUN_141a784b0(obj, pMember, nFlags))
            static_cast<Unk_PdScript*>(m_30.get())->FUN_140f0c520("updateMember", FUN_140719530(pMember->user.m_8), obj.FUN_1422bb870());
    }
}

// @0x141a74ea0
void UIPartyDialog::FUN_141a74ea0()
{
    if (FUN_1409670d0()->FUN_14162ab20())
    {
        ATL::CAtlArray<MS2Ptr<CPartyMember>>& members = FUN_1409670d0()->FUN_14162ba30();
        size_t nCount = members.GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            CPartyMember* pMember = members[i].get();
            if (pMember != 0)
                FUN_141a74d50(pMember, 0x180);
        }
    }
}

// MS2-FUNCTIONAL: written from the decompile (ternary CString temporaries)
// @0x141a74f50
void UIPartyDialog::FUN_141a74f50(CPartyMember* pOld, CPartyMember* pNew)
{
    if (m_30 == 0)
        return;
    CString strOld = pOld == 0 ? CString("") : FUN_140719530(pOld->FUN_141637bb0());
    CString strNew = pNew == 0 ? CString("") : FUN_140719530(pNew->FUN_141637bb0());
    m_30->FUN_1413127f0("changeChief", strOld, strNew);
    if (FUN_140166410()->FUN_14036d570(0x56) == 1)
    {
        FUN_141a79770();
        FUN_141a75a20();
    }
}

// @0x141a752a0
int UIPartyDialog::FUN_141a752a0(CPartyMember* pMember)
{
    if (!(m_30 == 0))
    {
        ASObj obj(2);
        if (FUN_141a784b0(obj, pMember, 0x1ff) == 0)
            return 0;
        m_30->Invoke("addMember", obj.FUN_1422bb870());
        return 1;
    }
    return 0;
}

// @0x141a753d0
int UIPartyDialog::FUN_141a753d0(CPartyMember* pMember)
{
    if (!(m_30 == 0) && pMember != 0)
    {
        m_30->Invoke("removeMember", FUN_140719530(pMember->user.m_8));
        return 1;
    }
    return 0;
}

// @0x141a75490
int UIPartyDialog::FUN_141a75490(__int64 nCharId, float* pPos)
{
    if (!(m_30 == 0))
    {
        Scaleform::GFx::Value ret = m_30->Invoke("getCameraButtonPos", FUN_140719530(nCharId));
        Scaleform::GFx::Value x;
        Scaleform::GFx::Value y;
        ret.GetMember(DAT_142fd1144, &x);
        ret.GetMember(DAT_142fd116c, &y);
        if (FUN_140f17ed0(x) == 0.0 && FUN_140f17ed0(y) == 0.0)
            return 0;
        pPos[0] = (float)(pPos[0] + FUN_140f17ed0(x));
        pPos[1] = (float)(pPos[1] + FUN_140f17ed0(y));
        return 1;
    }
    return 0;
}

// @0x141a75680
int UIPartyDialog::FUN_141a75680(float* pPos)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0 && pMe->FUN_14166ce30() != 0)
    {
        MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (!(spField == 0) && spField->m_nGlobalSplit != 0)
        {
            ATL::CAtlArray<MS2Ptr<CPartyMember>>& members = FUN_1409670d0()->FUN_14162ba30();
            size_t nCount = members.GetCount();
            for (size_t i = 0; i < nCount; i++)
            {
                MS2Ptr<CPartyMember> spMember = members[i];
                if (spMember->user.m_8 == pMe->FUN_141656a80())
                    continue;
                if (FUN_141a75490(spMember->FUN_141637bb0(), pPos) == 1)
                    return 1;
            }
            return 0;
        }
    }
    return 0;
}

// @0x141a75840
bool UIPartyDialog::FUN_141a75840()
{
    if (!(m_30 == 0))
    {
        MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe == 0)
            return false;
        if (pMe->FUN_14166ce30() == 0)
            return false;
        MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (!(spField == 0) && spField->m_nGlobalSplit != 0)
        {
            Scaleform::GFx::Value ret = static_cast<Unk_PdScript*>(m_30.get())->FUN_1422bb330("isCanObserveMode");
            if (!FUN_141a4bfb0(ret))
                return false;
            return FUN_1409c1720(ret);
        }
        return false;
    }
    return false;
}

// @0x141a759b0
void UIPartyDialog::FUN_141a759b0()
{
    if (m_vote.get() != 0)
        m_vote->FUN_141a74760();
}

// @0x141a75a00
void UIPartyDialog::FUN_141a75a00(unsigned int nDeadline)
{
    m_deadline = nDeadline;
}

// @0x141a75a20
void UIPartyDialog::FUN_141a75a20()
{
    if (!(m_30 == 0))
        static_cast<Unk_PdScript*>(m_30.get())->FUN_1422bb330("arrangeBottomButton");
}

// MS2-FUNCTIONAL: written from the decompile (binder temporaries)
// @0x141a75a80
void UIPartyDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_30->FUN_140bbe640("m_enterDungeon", m_enterDungeon);
    if (m_enterDungeon == 0)
        throw PD_SWF_ERROR(0x7d);
    m_30->FUN_140bbe640("m_recall", m_recall);
    if (m_recall == 0)
        throw PD_SWF_ERROR(0x7e);
    m_30->FUN_140bbe640("m_createClub", m_createClub);
    if (m_createClub == 0)
        throw PD_SWF_ERROR(0x7f);
    m_30->FUN_140bbe640("m_giveUpDungeon", m_giveUpDungeon);
    if (m_giveUpDungeon == 0)
        throw PD_SWF_ERROR(0x80);
    m_30->FUN_140bbe640("m_dungeonName", m_dungeonName);
    if (m_dungeonName == 0)
        throw PD_SWF_ERROR(0x81);
    m_vote.AssignRaw(new ASPartyVotePage(GetChild<ASMovieClip>("m_partyVote")));
    m_vote->OnInit();
    m_createClub->FUN_1422ce240(PdParamsDelegate(this, &UIPartyDialog::FUN_141a77ae0), 0);
    m_enterDungeon->FUN_1422ce240(PdParamsDelegate(this, &UIPartyDialog::FUN_141a77ab0), 0);
    m_giveUpDungeon->FUN_1422ce240(PdParamsDelegate(this, &UIPartyDialog::FUN_141a77dd0), 0);
    FUN_141a792b0();
    PacketHandlerManager::GetInstance()->RegisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIPartyDialog::FUN_141a77980));
    PacketHandlerManager::GetInstance()->RegisterHandler(0x100, Delegate<void(CInPacket&)>(this, &UIPartyDialog::FUN_141a77a40));
}

// @0x141a767d0
void UIPartyDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
    if (pMenu != 0)
        pMenu->FUN_141a80770();
    m_vote = 0;
    m_enterDungeon = 0;
    m_recall = 0;
    m_createClub = 0;
    m_giveUpDungeon = 0;
    m_dungeonName = 0;
    PacketHandlerManager::GetInstance()->UnregisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIPartyDialog::FUN_141a77980));
    PacketHandlerManager::GetInstance()->UnregisterHandler(0x100, Delegate<void(CInPacket&)>(this, &UIPartyDialog::FUN_141a77a40));
}

// @0x141a769d0
void UIPartyDialog::vfunc_15()
{
    if (!(m_30 == 0) && m_timer.Check(1000))
    {
        if (FUN_1409670d0()->FUN_14162c300())
            m_vote->FUN_141a74760();
        if (m_deadline != 0 && m_deadline < FUN_140869420())
            FUN_1409670d0()->FUN_14162c4a0(0);
    }
}

// MS2-FUNCTIONAL: written from the decompile (the three method branches share the result slot)
// @0x141a76a80
int UIPartyDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onPopupMenu", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            float x = data.FUN_1422b8c10();
            float y = data.FUN_1422b8c10();
            __int64 nCharId = FUN_140718350(data.FUN_1422b8d30());
            FUN_141a77760(x, y, nCharId);
        }
        return 1;
    }
    if (_stricmp("onCameraClick", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            __int64 nCharId = FUN_140718350(data.FUN_1422b8d30());
            PC* pTarget = FUN_1403ed2d0()->FUN_141bd1530(nCharId);
            MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pMe != 0 && pTarget != 0)
                pMe->FUN_14152a4a0(pTarget);
        }
        return 1;
    }
    if (_stricmp("onPartyRecall", szMethod) == 0)
    {
        if (!FUN_141a77eb0())
            return 1;
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e040(0x14);
        if (spItem == 0)
        {
            int nMerat = *FUN_1401d3200()->PartyRecallMerat.Get();
            CStringW strText = FUN_1408116a0(0xc64, nMerat);
            if (!FUN_140d86260()->vfunc_40(nMerat))
            {
                FUN_141add1f0(FUN_1403ed2b0());
                return 1;
            }
            FUN_140d86260()->vfunc_43(2, false, 1000);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strText, this, CStringW(L"buy_scroll"));
            if (spBox == 0)
                return 1;
            FUN_140d73c60(spBox);
            return 1;
        }
        FUN_141a783d0(((CItem*)spItem)->FUN_140526a50());
    }
    return 0;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x141a76ff0
void UIPartyDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (!(strMethod == "getTooltip"))
        return;
    if (m_70 != 0)
        return;
    UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
    if (pMenu != 0)
    {
        bool bSlotMenu = pMenu->FUN_141a80880() == 0 && _stricmp(pMenu->FUN_141a808c0(), "partySlot") == 0;
        if (bSlotMenu)
            return;
    }
    __int64 nCharId = FUN_140718350(pArgs->FUN_1422b8d30());
    if (nCharId == 0)
        return;
    CPartyMember* pMember = FUN_1409670d0()->FUN_14162afc0(nCharId).get();
    if (pMember == 0)
        return;
    int nStringId = pMember->FUN_141637c20() ? 0x57b : 0x57a;
    CStringW strText;
    if (!pMember->FUN_141637c20())
    {
        Unk_UserProxy* pUser = &pMember->user;
        CStringW strInfo;
        if (pUser->m_38 == 0)
        {
            strInfo = L"";
        }
        else
        {
            strInfo = FUN_1408116a0(0x76b, pUser->m_38);
            strInfo += L" ";
        }
        strInfo += FUN_1401a9d70()->FUN_141811980(3, pUser->m_2c);
        strText = FUN_140632a60(0x76c, FUN_14028de60(nStringId), strInfo);
    }
    else
    {
        strText = FUN_14028de60(nStringId);
    }
    if (!strText.IsEmpty())
    {
        ASTooltip tip(1, 2);
        if (tip.FUN_1409e26b0(strText))
        {
            tip.FUN_1409c6dc0(4);
            tip.FUN_1407cb9c0("offsetX", -30);
            tip.FUN_1407cb9c0("offsetY", -1);
            *pRetVal = tip.FUN_1422bb870();
        }
    }
}

// @0x141a774d0
int UIPartyDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) == 0 && pMsg->FUN_1422e4520() == 0)
    {
        if (pMsg->FUN_1422b8a10() == 0)
        {
            CStringW strTag = pMsg->FUN_1422b8f40();
            ATL::CAtlArray<CStringW> parts;
            FUN_14025a680(strTag, parts, DAT_142fd11d4);
            if (parts[0] == L"buy_scroll")
                FUN_141a783d0(-1);
            FUN_14151f200();
        }
        else
        {
            FUN_14151f200();
        }
    }
    return 1;
}

// @0x141a77600
bool UIPartyDialog::FUN_141a77600(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        CStringW strName = box.FUN_141a02d50();
        strName.Trim(L",");
        if (strName.IsEmpty())
            return false;
        FUN_140e0d900()->FUN_140b15c10(strName);
        return true;
    }
    return true;
}

// @0x141a776e0
bool UIPartyDialog::FUN_141a776e0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        COutPacket packet(0x9d, 0);
        packet.Encode1(5);
        FUN_140710590(packet);
    }
    return true;
}

// @0x141a77760
void UIPartyDialog::FUN_141a77760(float x, float y, __int64 nCharId)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    if (pMe->FUN_141656a80() == nCharId)
    {
        UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
        if (pMenu != 0)
        {
            Unk_PopupMenuInfo info(x, y, 3, 0x63fe, 1, "partySlot", 0);
            pMenu->FUN_141a7e280(info, pMe, 2);
        }
    }
    else
    {
        MS2Ptr<CPartyMember> spMember = FUN_1409670d0()->FUN_14162afc0(nCharId);
        UIPopUpMenu* pMenu;
        if (spMember.get() != 0 && (pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39)) != 0)
        {
            Unk_PopupMenuInfo info(x, y, 3, 0x63fe, 1, "partySlot", 0);
            pMenu->FUN_141a7f190(info, spMember);
        }
    }
}

// @0x141a77980
void UIPartyDialog::FUN_141a77980(CInPacket& packet)
{
    unsigned char nType = packet.vfunc_o8_1();
    if (nType == 0x11)
    {
        FUN_141a79840();
        FUN_141a75a20();
    }
    else if (nType == 0x19)
    {
        FUN_141a794e0();
        FUN_141a79570();
        FUN_141a75a20();
    }
    else if (nType > 0x2f && nType < 0x32)
    {
        FUN_141a759b0();
        FUN_141a75a20();
    }
}

// @0x141a77a40
void UIPartyDialog::FUN_141a77a40(CInPacket& packet)
{
    unsigned char nType = packet.vfunc_o8_1();
    if (nType > 2 && nType < 5)
    {
        FUN_141a79840();
        FUN_141a75a20();
    }
}

// @0x141a77ab0
void UIPartyDialog::FUN_141a77ab0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1409670d0()->FUN_14162bd40(0);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x141a77ae0
void UIPartyDialog::FUN_141a77ae0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (FUN_1409670d0()->FUN_14162ab60())
    {
        if (FUN_140e0d900()->FUN_140b14cd0() == 1)
        {
            int nKind = 3;
            FUN_1412751f0(FUN_1408116a0(0x381, nKind), 1, 1);
        }
        else
        {
            int nMax = *FUN_1401d3200()->ClubNameLengthMax.Get();
            int nHalf = nMax / 2;
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(10, FUN_14028dfa0(CStringW(L"s_party_create_club"), nHalf, nMax), 0, CStringW(L""));
            if ((CMsgBoxData*)spBox != 0)
            {
                spBox->FUN_141a01d30(2, CStringW(L""), nMax, 0, 0);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIPartyDialog::FUN_141a77600));
                FUN_140d73c60(spBox);
            }
        }
    }
}

// @0x141a77dd0
void UIPartyDialog::FUN_141a77dd0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>(this, &UIPartyDialog::FUN_141a776e0), CStringW(L"s_party_dungeon_giveup"));
}

// MS2-FUNCTIONAL: written from the decompile
// @0x141a77eb0
bool UIPartyDialog::FUN_141a77eb0()
{
    if (FUN_1402c4c90(FUN_14025e7b0() + 8, 0x1a) != 0)
    {
        FUN_140d73bc0(0x2f7, 0, 0, CStringW(L""));
        return false;
    }
    if (!FUN_1409670d0()->FUN_14162ab20())
    {
        FUN_140d73bc0(0xb5b, 0, 0, CStringW(L""));
        return false;
    }
    int nCount = FUN_1409670d0()->FUN_14162bf20();
    if (nCount - 1 < 1)
    {
        FUN_140d73bc0(0xb5d, 0, 0, CStringW(L""));
        return false;
    }
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return false;
    if (pMe->FUN_14166ce30() != 0)
    {
        FUN_140d73bc0(0xb57, 0, 0, CStringW(L""));
        return false;
    }
    if (pMe->FUN_14166c930() == 0x2c)
    {
        FUN_140d73bc0(0xb57, 0, 0, CStringW(L""));
        return false;
    }
    if (pMe->FUN_14166c930() != 1 || pMe->FUN_141675ed0() != 0)
    {
        FUN_140d73bc0(0xb59, 0, 0, CStringW(L""));
        return false;
    }
    if (DAT_1439f4a7c == 0)
    {
        FUN_140d73bc0(0xb58, 0, 0, CStringW(L""));
        return false;
    }
    if (FUN_140930b10())
    {
        FUN_140d73bc0(0xb58, 0, 0, CStringW(L""));
        return false;
    }
    if (FUN_1403ed2d0()->FUN_141bd30a0()->FUN_140375490() == 0)
    {
        FUN_140d73bc0(0xb58, 0, 0, CStringW(L""));
        return false;
    }
    int nLimit = FUN_1403ed2d0()->FUN_141bd30a0()->vfunc_2();
    if (nLimit > 0)
    {
        int nA = FUN_1403ed2d0()->FUN_141bc2bc0();
        int nB = FUN_1403ed2d0()->FUN_141bc2b30();
        if (nLimit < nB + nCount - 1 + nA)
        {
            FUN_140d73bc0(0xb5f, 0, 0, CStringW(L""));
            return false;
        }
    }
    if (pMe->FUN_141527160(0x2c) == 0)
    {
        FUN_140d73bc0(0xb59, 0, 0, CStringW(L""));
        return false;
    }
    return true;
}

// @0x141a783d0
void UIPartyDialog::FUN_141a783d0(__int64 nItemUid)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0)
    {
        pMe->FUN_14166d970(pMe->vfunc_20());
        pMe->vfunc_59(0x2c, new StateRecallData(reinterpret_cast<void*>(nItemUid)), 0, 0);
    }
}

// MS2-FUNCTIONAL: written from the decompile
// @0x141a784b0
int UIPartyDialog::FUN_141a784b0(ASObj& obj, CPartyMember* pMember, unsigned int nFlags)
{
    static const CString s_level("level");
    static const CString s_job("job");
    static const CString s_name("name");
    static const CString s_hp("hp");
    static const CString s_maxhp("maxhp");
    static const CString s_oriMaxhp("oriMaxhp");
    static const CString s_chief("chief");
    static const CString s_state("state");
    static const CString s_charSN("charSN");
    static const CString s_profile("profile");
    static const CString s_ch("ch");
    static const CString s_chName("chName");
    static const CString s_observeMode("observeMode");
    static const CString s_tombType("tombType");
    static const CString s_diff("diff");
    if (pMember == 0)
        return 0;
    if (nFlags & 8)
        obj.FUN_1409c48f0(s_level, pMember->user.m_34);
    if (nFlags & 4)
        obj.FUN_140bd0d90(s_job, pMember->user.m_40);
    if (nFlags & 0x20)
        obj.FUN_1407cbb20(s_name, pMember->user.FUN_1408f19e0());
    if (nFlags & 2)
    {
        obj.FUN_1407cb9c0(s_hp, pMember->user.m_48);
        obj.FUN_1407cb9c0(s_maxhp, pMember->user.m_44);
        obj.FUN_1407cb9c0(s_oriMaxhp, pMember->user.m_44);
        int nTomb = pMember->user.FUN_1408f1ce0();
        obj.FUN_1407cb9c0(s_tombType, nTomb);
    }
    if (nFlags & 0x10)
        obj.FUN_1407cb9c0(s_chief, pMember->leader);
    if (nFlags & 1)
    {
        if (pMember->FUN_141637c20())
            Unk_PdSetData(&obj, s_tombType, Unk_PdTombNone);
        int nState = FUN_141637c40(pMember);
        obj.FUN_1407cb9c0(s_state, nState);
        Unk_PdSetData(&obj, "readyState", pMember->FUN_141637c90());
    }
    if (nFlags & 0x80)
    {
        CStringW strChName;
        CString strDiff;
        if (pMember->user.m_38 == 0)
            strChName = FUN_14028b8e0(CStringW(L"s_party_ch_dungeon"));
        else
            strChName = FUN_14028dfa0(CStringW(L"s_party_ch"), pMember->user.m_38);
        MS2Ptr<CPartyMember> spMine = FUN_1409670d0()->FUN_14162afc0(DAT_143ab2828);
        if (spMine.get() != 0)
        {
            CPartyMember* pMine = spMine.operator->();
            if (pMine->user.m_38 == pMember->user.m_38)
            {
                if (pMine->user.m_38 == 0)
                {
                    if (pMine->user.m_30 != pMember->user.m_30)
                        strDiff = s_diff;
                }
                else if (pMine->user.m_2c != pMember->user.m_2c)
                {
                    strDiff = s_diff;
                }
            }
            else
            {
                strDiff = s_diff;
            }
        }
        obj.FUN_1407cba60(s_ch, strDiff);
        obj.FUN_1407cbb20(s_chName, strChName);
    }
    if (nFlags & 0x100)
    {
        int nObserve = 0;
        MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        MS2Ptr<CPartyMember> spMine = FUN_1409670d0()->FUN_14162afc0(DAT_143ab2828);
        MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (pMe != 0 && spMine.get() != 0)
        {
            if (pMe->FUN_141656a80() == pMember->user.m_8)
                nObserve = 0;
            else if (pMe->FUN_14166ce30() == 0)
                nObserve = 0;
            else if (!(spField == 0) && spField->m_nGlobalSplit != 0)
            {
                if (!(spField == 0) && spField->m_nCheckPartyObserve != 0)
                {
                    if (pMember->user.m_38 == spMine->user.m_38 && pMember->user.m_2c == spMine->user.m_2c &&
                        pMember->user.m_30 == spMine->user.m_30)
                        nObserve = pMember->role;
                    else
                        nObserve = 0;
                }
                else
                {
                    nObserve = 0;
                }
            }
            else
            {
                nObserve = 0;
            }
        }
        obj.FUN_1407cb9c0(s_observeMode, nObserve);
    }
    if (nFlags & 0x1ff)
    {
        if (FUN_1406c7610()->m_30)
            obj.FUN_1407cbbe0("returnUser", pMember->user.m_180 == 2);
        obj.FUN_1407cba60(s_charSN, FUN_140719530(pMember->user.m_8));
    }
    return 1;
}

// @0x141a792b0
void UIPartyDialog::FUN_141a792b0()
{
    if (!(m_30 == 0))
    {
        FUN_141a794e0();
        FUN_141a79570();
        FUN_141a796b0();
        FUN_141a79770();
        FUN_141a79840();
        FUN_141a759b0();
        FUN_141a75a20();
        ATL::CAtlArray<MS2Ptr<CPartyMember>>& members = FUN_1409670d0()->FUN_14162ba30();
        size_t nCount = members.GetCount();
        ASArray list(2);
        for (size_t i = 0; i < nCount; i++)
        {
            CPartyMember* pMember = members[i].get();
            if (pMember != 0)
            {
                ASObj obj(2);
                if (FUN_141a784b0(obj, pMember, 0x1ff))
                    list.FUN_1422bc050(obj.FUN_1422bb870());
            }
        }
        m_30->Invoke("initMembers", list.FUN_1422bb870());
    }
}

// @0x141a794e0
void UIPartyDialog::FUN_141a794e0()
{
    int bEnable = 0;
    if (!FUN_140930b40() && FUN_1409670d0()->FUN_14162abe0())
        bEnable = 1;
    if ((ASButton*)m_enterDungeon != 0)
        m_enterDungeon->vfunc_3(bEnable);
}

// @0x141a79570
void UIPartyDialog::FUN_141a79570()
{
    if (!(m_dungeonName == 0))
    {
        int nDungeonId = FUN_1409670d0()->FUN_14162c090();
        if (!FUN_140930b40() && nDungeonId != 0)
        {
            m_dungeonName->vfunc_4(true);
            m_30->Invoke("setDungeonName", FUN_1401a9d70()->FUN_141811980(0x14, nDungeonId));
        }
        else
        {
            m_dungeonName->vfunc_4(false);
        }
    }
}

// @0x141a796b0
void UIPartyDialog::FUN_141a796b0()
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (!(spField == 0) && spField->FUN_140375490() != 0)
        m_recall->vfunc_3(1);
    else
        m_recall->vfunc_3(0);
}

// @0x141a79770
void UIPartyDialog::FUN_141a79770()
{
    if (FUN_140166410()->FUN_14036d570(0x56) == 1)
    {
        if (FUN_1409670d0()->FUN_14162ab60())
            m_createClub->vfunc_3(1);
        else
            m_createClub->vfunc_3(0);
    }
    else
    {
        m_createClub->vfunc_3(0);
    }
}

// @0x141a79840
void UIPartyDialog::FUN_141a79840()
{
    RoomStageDungeonCli* pStage = FUN_140931510()->FUN_140d9f4e0().get();
    if (pStage != 0 && pStage->IsStageFlagSet() && FUN_1409670d0()->FUN_14162ab60())
    {
        m_giveUpDungeon->vfunc_4(true);
        return;
    }
    m_giveUpDungeon->vfunc_4(false);
}

// @0x141a7aa70
int UIPartyDialog::vfunc_48()
{
    return 0x4e45;
}

// The header statics of the next original TU (header_statics_a.h's list; each TU has its own copies).
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

// ======== UIPartyDPSDialog ========

// The sort key shared by the ranking comparator and the rebuild (0x143af5008).
static int s_nPdSortMode;
bool FUN_141a7c2a0(MS2Ptr<CPartyMember> spA, MS2Ptr<CPartyMember> spB);

// @0x141a7b050
UIPartyDPSDialog::UIPartyDPSDialog()
{
    m_2c = 0x11;
    m_nGroup = 1;
    m_nMode = 0;
    FUN_141925e70(0, 1);
}

// @0x141a7b100
UIPartyDPSDialog::~UIPartyDPSDialog()
{
}

// @0x141a7b150
CString UIPartyDPSDialog::vfunc_1()
{
    return "PartyDPSDialog";
}

// @0x141a7b1a0
bool UIPartyDPSDialog::FUN_141a7b1a0(ASObj& obj, CPartyMember* pMember, unsigned int nRank)
{
    if (pMember != 0)
    {
        obj.FUN_1409c0d20("rank", nRank);
        obj.FUN_1409c48f0("level", pMember->user.m_34);
        obj.FUN_140bd0d90("job", pMember->user.m_40);
        obj.FUN_1407cbb20("name", pMember->user.FUN_1408f19e0());
        double dMeter = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(m_nGroup, pMember->FUN_141637bb0(), m_nMode));
        obj.FUN_140e06d60("meterValue", dMeter);
        CStringW strMeter = CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, pMember->FUN_141637bb0(), m_nMode);
        obj.FUN_1407cbb20("meterText", strMeter);
    }
    return pMember != 0;
}

// @0x141a7b3c0
void UIPartyDPSDialog::FUN_141a7b3c0()
{
    if (m_30.IsNull())
        return;
    CStringW strTitle = FUN_1405c2690(CStringW(L"s_partydps_titlebar"), CBattleRecordManager::FUN_140a04bc0(m_nMode));
    m_30->Invoke("setTitle", strTitle);
    m_30->Invoke("setAscendingMeterValue", m_nMode == 6);
}

#ifndef MS2_HOOK_DLL
// @0x141a7b540
void UIPartyDPSDialog::FUN_141a7b540()
{
    if (m_30.IsNull() == 0)
    {
        CStringW strTime = CBattleRecordManager::GetInstance()->FUN_140a04b00(m_nGroup);
        m_30->Invoke("setTime", strTime);
        ATL::CAtlArray<MS2Ptr<CPartyMember> >& members = FUN_1409670d0()->FUN_14162ba30();
        if (members.IsEmpty() == 0)
        {
            m_members.clear();
            for (unsigned i = 0; i < members.GetCount(); i++)
            {
                CPartyMember* pMember = members[i].get();
                if (pMember != 0)
                    m_members.push_back(MS2Ptr<CPartyMember>(pMember));
            }
            s_nPdSortMode = m_nMode;
            std::sort(m_members.begin(), m_members.end(), FUN_141a7c2a0);
            MS2Ptr<CPartyMember> spLast = m_members[m_members.size() - 1];
            if (spLast.get() != 0)
            {
                double dBottom = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(m_nGroup, spLast->FUN_141637bb0(), m_nMode));
                static_cast<Unk_PdScript*>(m_30.operator->())->FUN_140e06cc0("setBottomMeterValue", dBottom);
            }
            for (unsigned i = 0; i < m_members.size(); i++)
            {
                MS2Ptr<CPartyMember> spMember = m_members[i];
                if (i < 10)
                {
                    ASObj obj(2);
                    if (FUN_141a7b1a0(obj, spMember.get(), i + 1) != 0)
                        m_30->Invoke("UpdateMember", Scaleform::GFx::Value(obj.FUN_1422bb870()));
                }
                PCBase* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pMe != 0)
                {
                    __int64 nMyId = pMe->FUN_141656a80();
                    if (nMyId == spMember->user.m_8)
                    {
                        ASObj objMy(2);
                        if (FUN_141a7b1a0(objMy, spMember.get(), i + 1) != 0)
                            m_30->Invoke("SetMyRank", Scaleform::GFx::Value(objMy.FUN_1422bb870()));
                    }
                }
            }
        }
    }
}
#endif

// @0x141a7bb70
void UIPartyDPSDialog::FUN_141a7bb70()
{
    if (m_30.IsNull())
        return;
    int nCount = FUN_1409670d0()->FUN_14162af00();
    if (nCount < 10)
        m_30->Invoke("RemoveMember");
}

// @0x141a7bbf0
void UIPartyDPSDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x141a7bc10
void UIPartyDPSDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_tick.Init();
    CBattleRecordManager::GetInstance()->FUN_140a03f60(m_nGroup);
    FUN_141a7b3c0();
    FUN_141a7b540();
}

// MS2-FUNCTIONAL: same body as UIChaosDPSDialog::vfunc_28 (register / stack allocation)
// @0x141a7bc70
int UIPartyDPSDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnCloseDialog", szMethod) == 0)
    {
        CBattleRecordManager::GetInstance()->FUN_140a03fe0(m_nGroup);
        vfunc_67();
        return 1;
    }
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onReset", szMethod) == 0)
    {
        CBattleRecordManager::GetInstance()->FUN_140a03fa0(m_nGroup);
        return 1;
    }
    if (_stricmp("onNotice", szMethod) == 0)
    {
        CMsTime kNow(GetServerTime());
        int nSecond = kNow.GetSecond();
        int nMinute = kNow.GetMinute();
        int nHour = kNow.GetHour();
        CStringW strHistory = FUN_140c2fcc0(CStringW(L"s_partydps_notice_history_prefix"), nHour, nMinute, nSecond, CBattleRecordManager::FUN_140a04bc0(m_nMode));
        CStringW strRow = FUN_14028b8e0(L"s_partydps_notice_history_row");
        for (unsigned i = 0; i < m_members.size() && i <= 9; i++)
        {
            MS2Ptr<CPartyMember> spMember = m_members[i];
            strHistory.Append(StringFormat((const wchar_t*)strRow, i + 1, spMember->user.FUN_1408f19e0(),
                CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, spMember->FUN_141637bb0(), m_nMode)));
        }
        int nNow = GetTickCountMs2();
        int nTime = CBattleRecordManager::GetInstance()->FUN_140a04060(m_nGroup);
        nTime = nNow - nTime;
        CStringW strTotal;
        FUN_141b70810(nTime, strTotal);
        strHistory.Append(FUN_1405c2690(CStringW(L"s_partydps_notice_history_total_time"), strTotal));
        Unk_CommandChat kChat;
        kChat.kind = 7;
        kChat.message = strHistory;
        FUN_141276f80(kChat);
        return 1;
    }
    if (_stricmp("onTextToggle", szMethod) == 0)
    {
        m_nMode = m_nMode + 1;
        if (6 < m_nMode)
            m_nMode = 0;
        FUN_141a7b3c0();
        return 1;
    }
    return 0;
}

// @0x141a7c210
void UIPartyDPSDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (!FUN_1409670d0()->FUN_14162ab20())
    {
        vfunc_67();
        return;
    }
    if (m_30.IsNull() == 0 && m_tick.Check(100) != 0)
        FUN_141a7b540();
}

// Orders the ranking: descending meter value (ascending for mode 6).
#ifndef MS2_HOOK_DLL
// @0x141a7c2a0
bool FUN_141a7c2a0(MS2Ptr<CPartyMember> spA, MS2Ptr<CPartyMember> spB)
{
    double dA = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(1, spA->FUN_141637bb0(), s_nPdSortMode));
    double dB = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(1, spB->FUN_141637bb0(), s_nPdSortMode));
    bool bLess;
    if (s_nPdSortMode == 6)
        bLess = dA < dB;
    else
        bLess = dB < dA;
    return bLess;
}
#endif

// @0x141a7c4b0
int UIPartyDPSDialog::vfunc_48()
{
    return 0x4e8c;
}

// The header statics of the next original TU (header_statics_a.h's list; each TU has its own copies).
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_3(17, 0.75f, 0.25f, 2.25f, 10);

// ======== UIPerformanceDialog ========

// @0x141a7c4c0
UIPerformanceDialog::UIPerformanceDialog()
{
    m_80 = 1;
    m_88 = 0;
    FUN_141925e70(0, 1);
}

// @0x141a7c560
UIPerformanceDialog::~UIPerformanceDialog()
{
}

// @0x141a7c5b0
CString UIPerformanceDialog::vfunc_1()
{
    return "PerformanceDialog";
}

// @0x141a7c600
void UIPerformanceDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141923680(1);
    m_text = GetChild<ASTextField>("m_text");
}

// @0x141a7c6a0
void UIPerformanceDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_text = 0;
}

// @0x141a7c6e0
void UIPerformanceDialog::vfunc_72()
{
    if ((ASTextField*)m_text != 0)
    {
        unsigned int nDraw = FUN_14086d260()->FUN_141473460();
        float fFps = FUN_14086d260()->FUN_141473210();
        m_text->FUN_1422c4c80(StringFormat("{0:0.1f}({1})", fFps, nDraw));
    }
}

// @0x141a7cae0
int UIPerformanceDialog::vfunc_48()
{
    return 0x4e7d;
}

// The header statics of the next original TU (header_statics_a.h's list; each TU has its own copies).
static CString s_strSortTypeNames4[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill4 = "skill";
static CString s_strStun4 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_4(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_pePopupKeyInput;            // 0x14011a960

// ======== UIPopupEntity (the fourth TU of this range) ========

// The owner's PCBase / GameObject members the popup entity calls (UIPopupEntity keeps the owner as Unk_PopupOwner*).
struct Unk_PeOwner : Unk_PopupOwner
{
    int FUN_141674bc0();                                                    // PCBase: is the local player
    NiAVObject* FUN_141675150(const CString& strName);                      // PCBase: effect dummy node by name
    void FUN_141676310(int nUiId);                                          // PCBase: drop a ui slot
    egf::EntityID FUN_14123c460();                                          // GameObject: entity id
    float FUN_140f4a450();                                                  // GameObject: distance to the camera
};
egf::Entity* FUN_14123c410(Unk_PopupOwner* pOwner);                      // the owner's entity
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                          // the entity's scene graph
class Unk_PeAnimService;
Unk_PeAnimService* FUN_141b6f910();
void* FUN_140999440(Unk_PeAnimService* pService, const egf::EntityID& id);   // the entity's actor manager
const Unk_PopupPos& FUN_140947900(NiAVObject* pNode);                     // world translate of a node
int FUN_141277f40();                                                      // the popup entity ui layer
MS2Ptr<ASGameEntity> FUN_140ba77e0(int nUiId, const Scaleform::GFx::Value& root);
class Unk_PeUiScale { public: float FUN_1422afec0(int nLayer); };
Unk_PeUiScale* FUN_14025e7a0();
float FUN_1412762d0(const Unk_PopupPos& pt);                              // height offset of a position
extern NiPoint3 DAT_143b01a60;                                            // zero position

// @0x141a7caf0
UIPopupEntity::UIPopupEntity(Unk_PopupOwner* pOwner)
    : m_68(pOwner), m_70(0), m_78("Eff_UI"), m_80(0), m_84(0), m_88(0), m_8c(0), m_90(0), m_94(0)
{
    m_28 = FUN_141277f40();
    m_58 = 0;
    m_d0 = 0;
}

// @0x141a7cc10
UIPopupEntity::~UIPopupEntity()
{
    vfunc_55();
    FUN_141a7d300();
}

// @0x141a7cca0
CString UIPopupEntity::vfunc_1()
{
    return "PopupEntity";
}

// @0x141a7ccf0
void UIPopupEntity::vfunc_52()
{
    MS2Ptr<ASDisplayObject> spRoot(dynamic_cast<ASDisplayObject*>(m_30.get()));
    if ((ASDisplayObject*)spRoot.get() != 0)
    {
        vfunc_8(1);
        m_88 = 0;
    }
}

// @0x141a7cd90
void UIPopupEntity::OnLoadInit()
{
    UIObject::OnLoadInit();
    m_d0 = vfunc_48();
}

// @0x141a7cdd0
void UIPopupEntity::OnLoadComplete()
{
    UIObject::OnLoadComplete();
}

// @0x141a7cdf0
// MS2-FUNCTIONAL: the world position goes through Unk_PopupPos copies (the exe passes the efd::Point3 / NiPoint3 locals)
void UIPopupEntity::vfunc_15()
{
    if (m_84 != 0)
    {
        if (vfunc_57(0) == 0)
        {
            NiPoint3 kScreen;
            Unk_PopupPos posWorld = vfunc_60();
            efd::Point3 kWorld(posWorld.x, posWorld.y, posWorld.z);
            if (!CameraMgr::GetInstance()->FUN_140af0700(kWorld, kScreen))
            {
                vfunc_55();
            }
            else
            {
                if (m_88 != 0)
                    vfunc_52();
                kScreen *= FUN_14025e7a0()->FUN_1422afec0(m_28);
                kScreen.y = kScreen.y + vfunc_59();
                kScreen.y = kScreen.y + FUN_1412762d0(vfunc_60());
                Unk_PopupPos pos;
                pos.x = kScreen.x;
                pos.y = kScreen.y;
                pos.z = kScreen.z;
                vfunc_53(pos);
            }
        }
        else
        {
            vfunc_55();
        }
    }
}

// @0x141a7cf60
void UIPopupEntity::vfunc_53(Unk_PopupPos pos)
{
}

// @0x141a7cf80
void UIPopupEntity::vfunc_54(int nMode)
{
    m_80 = nMode;
    m_84 = 1;
    m_88 = 1;
    m_98.FUN_140868750(m_90);
}

// @0x141a7cff0
void UIPopupEntity::vfunc_55()
{
    if (m_84 != 0)
    {
        m_80 = 0;
        m_84 = 0;
        m_88 = 0;
        m_8c = 0;
        m_98.FUN_140868820();
        vfunc_8(0);
    }
}

// @0x141a7d080
int UIPopupEntity::vfunc_56()
{
    return m_84;
}

// @0x141a7d0a0
void UIPopupEntity::FUN_141a7d0a0()
{
    m_8c = 1;
}

// @0x141a7d0c0
int UIPopupEntity::vfunc_57(int nForce)
{
    if (m_68 == 0)
        return 1;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 1;
    if (m_80 == 0 && m_98.FUN_140868ba0() == 0)
        return 1;
    if (vfunc_58() == 0)
        return 1;
    if (FUN_141b6efc0(FUN_14123c410(m_68)) == 0)
        return 1;
    Unk_PeOwner* pOwner = static_cast<Unk_PeOwner*>(m_68);
    if (pOwner->FUN_141674bc0() != 0 && nForce == 0)
        return 1;
    if (FUN_140999440(FUN_141b6f910(), pOwner->FUN_14123c460()) == 0)
        return 1;
    return 0;
}

// @0x141a7d1f0
int UIPopupEntity::vfunc_58()
{
    if (m_8c != 0)
        return 1;
    float fDist = vfunc_61();
    if (fDist <= m_94)
        return 1;
    return 0;
}

// @0x141a7d250
float UIPopupEntity::vfunc_59()
{
    return 0;
}

// @0x141a7d260
// MS2-FUNCTIONAL: returns the zero position as an Unk_PopupPos copy (the exe builds a NiPoint3 from DAT_143b01a60)
Unk_PopupPos UIPopupEntity::vfunc_60()
{
    if (m_68 != 0)
    {
        if (m_70 == 0)
            m_70 = static_cast<Unk_PeOwner*>(m_68)->FUN_141675150(m_78);
        if (m_70 != 0)
            return FUN_140947900(static_cast<NiAVObject*>(m_70));
    }
    Unk_PopupPos pos;
    pos.x = DAT_143b01a60.x;
    pos.y = DAT_143b01a60.y;
    pos.z = DAT_143b01a60.z;
    return pos;
}

// @0x141a7d300
void UIPopupEntity::FUN_141a7d300()
{
    if (m_68 != 0 && 0 < m_d0)
        static_cast<Unk_PeOwner*>(m_68)->FUN_141676310(m_d0);
    m_d0 = 0;
}

// @0x141a7d360
float UIPopupEntity::vfunc_61()
{
    if (m_68 == 0)
        return 1e9f;
    return static_cast<Unk_PeOwner*>(m_68)->FUN_140f4a450();
}

// @0x141a7d3a0
void UIPopupEntity::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x141a7d450
int UIPopupEntity::vfunc_48()
{
    return 0x4e35;
}

// @0x141a7d460
MS2_EMIT_CRT_MEMMOVE_S();

// The header statics of the next original TU (header_statics_a.h's list; each TU has its own copies).
static CString s_strSortTypeNames5[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill5 = "skill";
static CString s_strStun5 = "stun";
// (its condition map initializer follows at 0x14011aab0, outside this range)

// ======== UIPopUpMenu (the fifth TU of this range) ========

// The callees of the popup menu.
CLogString* FUN_140166440();                                            // TSingleton<CLogString>::GetInstance
int FUN_1401859c0(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szText);   // log a line
int FUN_1409c17e0(const Scaleform::GFx::Value& v);                      // an int value
class Unk_PmCamera { public: bool FUN_140af0700(const efd::Point3& kWorld, NiPoint3& kScreen); int FUN_140a18070(); float FUN_141032df0(); float FUN_140b67d10(); float FUN_1409f2430(); };
Unk_PmCamera* FUN_1409478c0();                                          // the camera manager
class Unk_PmInput;
Unk_PmInput* FUN_14025e7c0();                                           // the key input handler
bool FUN_14116d840(Unk_PmInput* pInput);                                // escape pressed
class Unk_PmSwfManager { public: void FUN_1422d4780(UISwfEntity* pEntity, int n); void FUN_1422d4840(UISwfEntity* pEntity, int n); };
Unk_PmSwfManager* FUN_140b632f0();                                      // UISwfEntityManager
class Unk_PmEntityEvents;
Unk_PmEntityEvents* FUN_140c607b0();
void FUN_1419308c0(Unk_PmEntityEvents* pEvents, UIEntityEventListener* pListener);   // register
void FUN_141930950(Unk_PmEntityEvents* pEvents, UIEntityEventListener* pListener);   // unregister
class Unk_PmUgcEvents;
Unk_PmUgcEvents* FUN_140bc09f0();                                       // UIUGCEventDispatcher
void FUN_141b38be0(Unk_PmUgcEvents* pEvents, UIUGCEventListener* pListener);         // register
void FUN_141b38c70(Unk_PmUgcEvents* pEvents, UIUGCEventListener* pListener);         // unregister
MS2Ptr<ASScrollingList> FUN_140bc61d0(int nMovieId, const Scaleform::GFx::Value& v);  // new ASScrollingList
class Unk_PmRoot { public: Scaleform::GFx::Value FUN_140ba4cc0(const char* szMethod, const ASObj& obj); };
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);                     // is an object value
void FUN_14028cd00(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szSep, int n);   // split
bool FUN_140841300(const CStringW& str, const char* sz);               // equals
void FUN_14162b7d0(CPartyManager* pParty, CStringW strName);            // expel member
void FUN_14162b8b0(CPartyManager* pParty, __int64 nCharId);             // vote kick
void FUN_14162bdb0(CPartyManager* pParty);                              // leave
void FUN_14162be10(CPartyManager* pParty);
void FUN_14162ba50(CPartyManager* pParty, CStringW strName);            // invite
bool FUN_14162ab60(CPartyManager* pParty);                              // in a party
int FUN_14162ad50(CPartyManager* pParty, CStringW strName);             // is a member
__int64 FUN_141a02ed0(const CMsgBoxData& data, int nIndex, int nDefault);
int FUN_141a02e50(const CMsgBoxData* pData, int nIndex, int nDefault);
int FUN_1418fd740(__int64 nAccount, __int64 nCharId, int nKind);       // report
int FUN_1418fd330(__int64 nCharId);
int FUN_1418fd530(__int64 nCharId);
int FUN_1418fd580(__int64 nCharId);
int FUN_1418fd5d0(__int64 nCharId);
int FUN_1418fd670(__int64 nCharId);
void FUN_1418fde20(__int64 nAccount, __int64 nCharId, int nKind, const CStringW& strName, Delegate<bool(int, const CMsgBoxData&)> cb);
class Unk_PmWedding { public: void FUN_141b862d0(const CStringW& strName); };
Unk_PmWedding* FUN_1409eed90();                                         // WeddingManager
CString FUN_141028a90(CString strImage, int n);                         // profile image path
CString FUN_141028be0(__int64 nCharId, const CString& strImage, int n, CString strDefault);
__int64 FUN_141656a80(PCBase* pPC);                                     // character id
__int64 FUN_141656ad0(PCBase* pPC);                                     // account id
CString FUN_1416612e0(PCBase* pPC);                                     // PC: profile image
int FUN_14166ce30(PCBase* pPC);
int FUN_141654700(PCBase* pPC);
int FUN_141654730(PCBase* pPC);
CBuddyManager* FUN_14097a780();                                         // TSingleton<CBuddyManager>::GetInstance
HomeBlockManager* FUN_1414a5830();                                      // TSingleton<HomeBlockManager>::GetInstance
CStringW FUN_14016a730(const char* sz, int nCodePage);                  // to wide
CString FUN_14016a600(const wchar_t* sz, int nCodePage);                // to multibyte
class Unk_PmGuild { public: char m_00[8]; CGuildInfo m_info; };
Unk_PmGuild* FUN_1403ed290();                                           // CGuildManager
int FUN_1413b6160(Unk_PmGuild* pGuild);                                 // has a guild
bool FUN_1413b71c0(Unk_PmGuild* pGuild, CStringW strName);              // invite to the guild
CStringW FUN_1401aa6a0(int nNpcId);                                     // the npc name
int FUN_141092fa0(CNpc* pNpc);                                          // the npc id
class Unk_PmCubeMap { public: __int64 FUN_1410c3180(); };
Unk_PmCubeMap* FUN_1409670e0();                                         // CubeMapInformationService
extern __int64 DAT_143ab2820;                                           // the own account id
extern int DAT_143af62d8;                                               // the screen height
float FUN_140bf4fd0(float f);
bool FUN_140900550();                                                   // wedding enabled
void FUN_140d73aa0(CStringW strText, int nType, IMessageListener* pListener, CStringW strTag);   // message box
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a);     // StringFormat<CStringW>
CStringW FUN_14052bd00(int nStringId, const CStringW& a);               // FormatStringId<CStringW>
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);
struct Unk_PmMsgBox : CMsgBoxData { void FUN_1405340b0(__int64 n); };    // Append<__int64>
void FUN_14151f150(MS2Ptr<CMsgBoxData> box);                            // show a box
class Unk_PmMdState { public: char m_00[0x48]; void* m_48; void* m_50; };
Unk_PmMdState* FUN_141482e80();
void FUN_141a252a0(void* pWhisper, const CStringW& strName);            // whisper to
void FUN_141951f70(void* pMail, const CStringW& strName);               // mail to
class Unk_PmCommunity { public: virtual void s0(); };                   // UICommunityDialog
int FUN_1418d6960(Unk_PmCommunity* pDialog);                            // the current tab
UIDialog* FUN_140ae5990(int nUiId);                                     // UICommunityDialog lookup
UIDialog* FUN_140ae5a30(int nUiId);                                     // UICommunityQueryDialog lookup
class Unk_PmCouple { public: void FUN_140bed2a0(unsigned __int64 nCharId); };
UIDialog* FUN_1417f5780(int nUiId);                                     // UICoupleActionDialog lookup
void FUN_140f8ff40(int nStringId, int a, int b);                        // notice
CBlockManager* FUN_140a6a830();                                         // TSingleton<CBlockManager>::GetInstance
class Unk_PmTrade { public: void FUN_14185b870(__int64 nCharId); };
Unk_PmTrade* FUN_14140ea30();                                           // CTradeManagerEx
__int64 FUN_1416769f0(PCBase* pPC);
void FUN_14152b800(MyPC* pMe, void* p);
__int64 FUN_140c75430(CUserReportData* pData, int nKind);                // the report category
// The UIMsg built on the stack (uitalkcinematic.cpp: its ASData setters are free functions bound by address).
struct Unk_FcUIMsg
{
    ~Unk_FcUIMsg();                                                     // 0x140c30570
    char m_pad[0x50];
};
void FUN_1422e4490(Unk_FcUIMsg* p);                                     // construct
void FUN_1422b82b0(Unk_FcUIMsg* p, const char* psz);
void FUN_1422b8310(Unk_FcUIMsg* p, const wchar_t* psz);
void FUN_1422b7f70(Unk_FcUIMsg* p, int n);
// The entry the user-proxy menu reads (FUN_141a7f890): a CPtred with a user proxy at +0x18.
class Unk_PmUserEntry : public CPtred
{
public:
    Unk_UserProxy m_user;
};

CNpc* FUN_140a38a00(GameObject* pObject);                                // the npc of an object
PCBase* FUN_141706540(Ridee* pRidee);                                   // the rider
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned int nId);      // is of the class id
float FUN_1412762d0(const Unk_PopupPos& pt);
const Unk_PopupPos& FUN_140947900(NiAVObject* pNode);
void FUN_140a2ff20(const BlockPtr& spBlock, int nAction, int n);        // notice of a blocked action

// The log call with one argument (0x141a876e0; FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class T> void Unk_PmLog(CLogString* log, int level, int category, const wchar_t* format, const T& value)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(value)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(value), args));
}

// A dialog of the ui service as T (0x141a877c0).
template <class T> T* Unk_PmGetDialog(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spDialog = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (spDialog.get() != 0)
            return dynamic_cast<T*>(spDialog.get());
    }
    return 0;
}

// A yes / no box with one argument (0x141a879a0).
template <class A> MS2Ptr<CMsgBoxData> Unk_PmShowYesNo(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb, A arg)
{
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(nType));
    spBox->FUN_141a01570(strText);
    spBox->FUN_141a027c0(cb);
    spBox->FUN_140b76940(arg);
    FUN_14151f150(spBox);
    return spBox;
}

// The two ASObj member setters through an ASData argument of this TU (0x141a87860 / 0x141a87900).
enum Unk_PmMenuType : int {};
enum Unk_PmDir : int { Unk_PmDirOn = 1 };

// @0x141a7d580
UIPopUpMenu::UIPopUpMenu()
    : m_80(0), m_84(0), m_98(0), m_a0(0), m_a8(0), m_b8(0), m_c8(0), m_d0(0), m_d8(0), m_e0(DAT_143b01a60), m_f0(0), m_100(1),
      m_110(0), m_138(0), m_140(L""), m_148(""), m_160(0x11, 0.75f, 0.25f, 2.25f, 10)
{
    m_58 = 0;
    m_2c = 0x1d;
    FUN_141a80c40();
}

// @0x141a7d850
CString UIPopUpMenu::vfunc_1()
{
    return "PopUpMenu";
}

// @0x141a7d8a0
void UIPopUpMenu::vfunc_2()
{
    FUN_1422dbf00(0x1d, 0, 0);
    PacketHandlerManager::GetInstance()->RegisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIPopUpMenu::FUN_141a80a50));
}

// @0x141a7d960
void UIPopUpMenu::vfunc_3()
{
    PacketHandlerManager::GetInstance()->UnregisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIPopUpMenu::FUN_141a80a50));
    FUN_141a80770();
    FUN_1422dc080();
}

// @0x141a7da20
int UIPopUpMenu::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("MenuItemClick", szMethod) == 0)
    {
        int nMenuId = FUN_1409c17e0(*pArgs);
        Delegate<void()> handler;
        if (m_160.Lookup(nMenuId, handler))
            handler();
    }
    return 0;
}

// @0x141a7daf0
void UIPopUpMenu::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_100 != 0)
        return;
    if (!(m_f0 == 0) && m_f0->FUN_1422bfca0())
    {
    }
    else
    {
        FUN_141a80770();
    }
    if (m_80 == 1)
    {
        PCBase* pTarget = efd::DynamicCast<PCBase>(FUN_1403ed2d0()->FUN_141bd0fe0(m_98));
        if (pTarget != 0)
        {
            NiPoint3 kScreen;
            if (!FUN_1409478c0()->FUN_140af0700(pTarget->vfunc_18(), kScreen) && (1.1f < kScreen.x || 1.1f < 1.0f - kScreen.y))
                FUN_141a80770();
        }
    }
}

// @0x141a7dc20
void UIPopUpMenu::vfunc_o70_2(const void* pId)
{
    if (!m_30)
        FUN_141a80770();
    else if (static_cast<const efd::UniversalID*>(pId)->GetValue() == m_98)
        FUN_141a80770();
}

// @0x141a7dc90
int UIPopUpMenu::vfunc_13()
{
    if (UISwfEntity::vfunc_13() != 0)
        return 1;
    if ((ASScrollingList*)m_f0.get() != 0 && m_f0->FUN_1422bfca0() && FUN_14116d840(FUN_14025e7c0()))
    {
        FUN_141a80770();
        return 1;
    }
    return 0;
}

// @0x141a7dd30
int UIPopUpMenu::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UISwfEntity::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0)
        {
            ATL::CAtlArray<CStringW> args;
            FUN_14028cd00(strTag, args, L":", 2);
            if (args.GetCount() == 2)
            {
                if (FUN_140841300(args[0], "changeChief"))
                {
                    COutPacket packet(0x2c, 0);
                    packet.Encode1(0x11);
                    packet.COutPacket::vfunc_o10_8(args[1]);
                    FUN_140710590(packet);
                }
                else if (FUN_140841300(args[0], "expelMember"))
                {
                    FUN_14162b7d0(FUN_1409670d0(), args[1]);
                }
            }
        }
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x141a7df60
// MS2-FUNCTIONAL: the by-value MS2Ptr<CProxyGameObject> argument arrives as the base's void* (destroyed explicitly)
void UIPopUpMenu::vfunc_4(void* pProxy)
{
    MS2Ptr<CProxyGameObject>& spProxy = *static_cast<MS2Ptr<CProxyGameObject>*>(pProxy);
    if (m_30 == 0)
    {
        FUN_141a80770();
    }
    else if (m_a8 != 0 && spProxy.get() != 0 && (__int64)spProxy->FUN_1416c22f0() == m_a8)
    {
        FUN_141a80770();
    }
    spProxy.~MS2Ptr<CProxyGameObject>();
}

// @0x141a7e020
bool UIPopUpMenu::FUN_141a7e020(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
        FUN_1418fd740(FUN_141a02ed0(data, 0, 0), FUN_141a02ed0(data, 1, 0), FUN_141a02e50(&data, 2, 0));
    return true;
}

// @0x141a7e0a0
bool UIPopUpMenu::FUN_141a7e0a0(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
        FUN_14162b8b0(FUN_1409670d0(), data.FUN_141a02f10(0, 0));
    return true;
}

// @0x141a7e100
bool UIPopUpMenu::FUN_141a7e100(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        CStringW strName = data.FUN_141a02fd0(0, CStringW());
        FUN_1409eed90()->FUN_141b862d0(strName);
    }
    return true;
}

// @0x141a7e1a0
void UIPopUpMenu::vfunc_ugc_1(void* pId, CString strImage)
{
    if (FUN_141a80880() != 0)
        return;
    if (m_a8 == (__int64)pId)
        FUN_141a82fb0(FUN_141028a90(strImage, 0));
}

// @0x141a7e280
void UIPopUpMenu::FUN_141a7e280(const Unk_PopupMenuInfo& info, PCBase* pTarget, int nType)
{
    if (info.m_a == m_80 && pTarget->FUN_14123c500() == m_98)
        return;
    FUN_141a80770();
    int nKind = FUN_141a83080(pTarget);
    if (nKind == 0 || nKind == 3)
        return;
    CStringW strName;
    FUN_141a832e0(pTarget, strName);
    if (strName.IsEmpty())
    {
        FUN_1401859c0(FUN_140166440(), 2, 0x13, L"UIPopUpMenu::PopUpMenu Empty Menu");
        return;
    }
    m_110 = nType;
    FUN_141a80af0(info);
    m_98 = pTarget->FUN_14123c500();
    Unk_PmTarget target;
    if (info.m_a == 2 || info.m_a == 3)
        target.m_pos = efd::Point3(info.m_x, info.m_y, 0);
    else
        target.m_pos = pTarget->vfunc_18();
    target.m_nLevel = (unsigned short)pTarget->vfunc_78();
    target.m_nCharId = FUN_141656a80(pTarget);
    target.m_strImage = FUN_141028be0(FUN_141656a80(pTarget), FUN_1416612e0(pTarget), 1, CString(""));
    target.m_strName = strName;
    target.m_b38 = FUN_14166ce30(pTarget) == 0;
    target.m_bOnline = 1;
    target.m_n20 = FUN_141654700(pTarget);
    target.m_nJobCode = FUN_141654730(pTarget);
    unsigned int nObjectId = pTarget->FUN_14123c580();
    MS2Ptr<CProxyGameObject> spProxy = FUN_1403ed2d0()->FUN_141bc9be0(nObjectId);
    if (spProxy.get() != 0)
        target.m_nTrophy = reinterpret_cast<Unk_GuildTriple*>(spProxy->FUN_1416c2950())->FUN_140267c10();
    m_a0 = FUN_141656ad0(pTarget);
    m_a8 = FUN_141656a80(pTarget);
    m_b0 = pTarget->vfunc_77();
    m_158 = target.m_strImage;
    CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4c30(0, m_a8, m_b0);
    if (spBuddy.get() != 0)
        m_d0 = spBuddy->FUN_1401cc2f0();
    HomeBlockManager::HomePtr spHome = FUN_1414a5830()->FUN_140a47580(m_a8);
    if (spHome.get() != 0)
        m_d8 = spHome->m_18;
    if (FUN_141a82140(target, info.m_b, nKind) == 0)
        FUN_141a82dd0();
}

// @0x141a7e870
void UIPopUpMenu::FUN_141a7e870(const Unk_PopupMenuInfo& info, PCBase* pTarget, int nType)
{
    if (info.m_a == m_80 && pTarget->FUN_14123c500() == m_98)
        return;
    FUN_141a80770();
    int nKind = FUN_141a83080(pTarget);
    if (nKind == 0 || nKind == 3)
        return;
    CStringW strName;
    FUN_141a832e0(pTarget, strName);
    if (strName.IsEmpty())
    {
        FUN_1401859c0(FUN_140166440(), 2, 0x13, L"UIPopUpMenu::PopUpMenu Empty Menu");
        return;
    }
    m_110 = nType;
    FUN_141a80af0(info);
    m_98 = pTarget->FUN_14123c500();
    Unk_PmTarget target;
    if (info.m_a == 2 || info.m_a == 3)
    {
        target.m_pos = efd::Point3(info.m_x, info.m_y, 0);
    }
    else
    {
        target.m_pos = pTarget->vfunc_18();
        NiAVObject* pNode = pTarget->FUN_141675150(CString("Eff_UI"));
        if (pNode != 0)
            target.m_pos.y = target.m_pos.y + FUN_1412762d0(FUN_140947900(pNode));
    }
    target.m_nLevel = (unsigned short)pTarget->vfunc_78();
    target.m_strImage = "";
    target.m_strName = strName;
    target.m_b38 = true;
    target.m_bOnline = 1;
    if (FUN_141a82140(target, info.m_b, nKind) == 0)
        FUN_141a82dd0();
}

// @0x141a7eb60
void UIPopUpMenu::FUN_141a7eb60(const Unk_PopupMenuInfo& info, MS2Ptr<CProxyGameObject> spProxy, int nType)
{
    FUN_141a80770();
    if (spProxy.IsNull() || (spProxy->FUN_1416c2040() == 0 && spProxy->FUN_1416c1ff0() == 0))
        return;
    CStringW strName = spProxy->FUN_1416c23b0();
    if (strName.IsEmpty())
        return;
    m_110 = nType;
    FUN_141a80af0(info);
    Unk_PmTarget target;
    target.m_pos = efd::Point3(info.m_x, info.m_y, 0);
    target.m_nLevel = spProxy->FUN_1416c2330();
    target.m_nCharId = (__int64)spProxy->FUN_1416c22f0();
    target.m_strImage = FUN_141028be0((__int64)spProxy->FUN_1416c22f0(), spProxy->FUN_1416c2520(), 1, CString(""));
    target.m_strName = strName;
    target.m_bOnline = 1;
    target.m_b38 = true;
    target.m_nTrophy = reinterpret_cast<Unk_GuildTriple*>(spProxy->FUN_1416c2950())->FUN_140267c10();
    target.m_n20 = spProxy->FUN_1416c2370();
    target.m_nJobCode = spProxy->FUN_1416c2390();
    m_a0 = (__int64)spProxy->FUN_1416c2310();
    m_a8 = (__int64)spProxy->FUN_1416c22f0();
    m_b0 = spProxy->FUN_1416c23b0();
    __int64 nAccountId = 0;
    CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4c30(nAccountId, m_a8, m_b0);
    if (spBuddy.get() != 0)
        m_d0 = spBuddy->FUN_1401cc2f0();
    HomeBlockManager::HomePtr spHome = FUN_1414a5830()->FUN_140a47580(m_a8);
    if (spHome.get() != 0)
        m_d8 = spHome->m_18;
    int nKind = spProxy->FUN_1416c1ff0() != 0 ? 1 : 2;
    if (FUN_141a82140(target, info.m_b, nKind) == 0)
        FUN_141a82dd0();
}

// @0x141a7f090
void UIPopUpMenu::FUN_141a7f090(const Unk_PopupMenuInfo& info, const CStringW& strName, unsigned __int64 nCharId, void* pAccount, int nType, int nDir)
{
    FUN_141a80770();
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return;
    m_110 = nType;
    FUN_141a80af0(info);
    m_a0 = (__int64)pAccount;
    m_a8 = nCharId;
    m_b0 = strName;
    if (FUN_141a828a0(strName, info, 2, nDir) == 0)
        FUN_141a82dd0();
}

// @0x141a7f190
void UIPopUpMenu::FUN_141a7f190(const Unk_PopupMenuInfo& info, CPartyMember* pMember)
{
    FUN_141a80770();
    CStringW strName = pMember->user.FUN_1408f19e0();
    if (strName.IsEmpty())
    {
        FUN_1401859c0(FUN_140166440(), 2, 0x13, L"UIPopUpMenu::PopUpMenuFromPartyMember Empty Menu");
        return;
    }
    m_110 = 2;
    FUN_141a80af0(info);
    Unk_PmTarget target;
    target.m_pos = efd::Point3(info.m_x, info.m_y, 0);
    Unk_UserProxy* pUser = &pMember->user;
    target.m_nLevel = (unsigned short)pUser->m_34;
    target.m_nCharId = pUser->m_8;
    target.m_strImage = FUN_141028be0(pUser->m_8, pUser->FUN_1408f1a60(), 1, CString(""));
    target.m_strName = strName;
    target.m_b38 = 0 < pUser->m_48;
    target.m_bOnline = !pMember->FUN_141637c20();
    target.m_nTrophy = reinterpret_cast<Unk_GuildTriple*>(&pUser->m_d4)->FUN_140267c10();
    target.m_n20 = pUser->m_3c;
    target.m_nJobCode = pUser->m_40;
    m_a0 = pUser->m_0;
    m_a8 = pUser->m_8;
    m_b0 = pUser->FUN_1408f19e0();
    int nKind = 2;
    if (FUN_141a82140(target, info.m_b, nKind) == 0)
        FUN_141a82dd0();
}

// @0x141a7f510
void UIPopUpMenu::FUN_141a7f510(const Unk_PopupMenuInfo& info, CGuildMember* pMember)
{
    FUN_141a80770();
    CStringW strName = pMember->data.FUN_1404ca890();
    if (strName.IsEmpty())
    {
        FUN_1401859c0(FUN_140166440(), 2, 0x13, L"UIPopUpMenu::PopUpMenuFromGuildMember Empty Menu");
        return;
    }
    m_110 = 3;
    FUN_141a80af0(info);
    Unk_PmTarget target;
    target.m_pos = efd::Point3(info.m_x, info.m_y, 0);
    Unk_GuildMemberData* pData = &pMember->data;
    target.m_nLevel = (unsigned short)pData->f1c;
    target.m_nCharId = pData->f08;
    target.m_strImage = FUN_141028be0(pData->f08, pData->FUN_1404ca980(), 1, CString(""));
    target.m_strName = strName;
    target.m_b38 = true;
    target.m_bOnline = pMember->f158 == 0;
    target.m_nTrophy = pData->f2c.FUN_140267c10();
    target.m_n20 = pData->f14;
    target.m_nJobCode = pData->f18;
    m_a0 = pData->f00;
    m_a8 = pData->f08;
    m_b0 = pData->FUN_1404ca890();
    int nKind = 2;
    if (pData->f08 != 0 && pData->f08 == DAT_143ab2828)
        nKind = 1;
    if (FUN_141a82140(target, info.m_b, nKind) == 0)
        FUN_141a82dd0();
}

// @0x141a7f890
void UIPopUpMenu::FUN_141a7f890(const Unk_PopupMenuInfo& info, Unk_PmUserEntry* pEntry, const CStringW& strText, int nType)
{
    m_108 = strText;
    FUN_141a7f090(info, pEntry->m_user.FUN_1408f19e0(), pEntry->m_user.m_8, (void*)pEntry->m_user.m_0, nType, 1);
}

// @0x141a7f950
void UIPopUpMenu::FUN_141a7f950(const Unk_PopupMenuInfo& info, __int64 nBuddyId)
{
    FUN_141a80770();
    CBuddy* pBuddy = FUN_14097a780()->FUN_140ae4b70(nBuddyId).get();
    if (pBuddy == 0)
        return;
    CStringW strName = pBuddy->FUN_1401cc1c0();
    if (strName.IsEmpty())
    {
        FUN_1401859c0(FUN_140166440(), 0xc, 0x13, L"Popupmenu error!: name is Empty!");
        return;
    }
    m_110 = 7;
    FUN_141a80af0(info);
    m_d0 = pBuddy->FUN_1401cc2f0();
    Unk_PmTarget target;
    target.m_pos = efd::Point3(info.m_x, info.m_y, 0);
    target.m_nLevel = pBuddy->FUN_1401cc210();
    target.m_nCharId = pBuddy->FUN_1401cc230();
    target.m_strImage = FUN_141028be0(pBuddy->FUN_1401cc230(), *pBuddy->FUN_1401cc530(), 1, CString(""));
    target.m_strName = strName;
    target.m_b38 = true;
    target.m_bOnline = pBuddy->FUN_1401cc680();
    target.m_nTrophy = reinterpret_cast<Unk_GuildTriple*>(pBuddy->FUN_1401cc330())->FUN_140267c10();
    target.m_n20 = pBuddy->FUN_1401cc290();
    target.m_nJobCode = pBuddy->FUN_1401cc2b0();
    if (FUN_141a82140(target, info.m_b, 2) == 0)
        FUN_141a82dd0();
}

// @0x141a7fc50
void UIPopUpMenu::FUN_141a7fc50(const Unk_PopupMenuInfo& info, __int64 nHomeId)
{
    FUN_141a80770();
    HomeBlockManager::HomePtr spHome = FUN_1414a5830()->FUN_140a47490(nHomeId);
    if (spHome.IsNull())
        return;
    CStringW strName = FUN_14016a730(spHome->m_30, 0);
    if (strName.IsEmpty())
    {
        FUN_1401859c0(FUN_140166440(), 0xc, 0x13, L"Popupmenu error!: name is Empty!");
        return;
    }
    m_110 = 7;
    FUN_141a80af0(info);
    m_d8 = spHome->m_18;
    Unk_PmTarget target;
    target.m_pos = efd::Point3(info.m_x, info.m_y, 0);
    target.m_nLevel = spHome->m_38;
    target.m_nCharId = spHome->m_28;
    target.m_strImage = FUN_141028be0(spHome->m_28, spHome->m_48, 1, CString(""));
    target.m_strName = strName;
    target.m_b38 = true;
    target.m_bOnline = 0;
    target.m_nTrophy = 0;
    target.m_n20 = spHome->m_3c;
    target.m_nJobCode = spHome->m_40;
    if (FUN_141a82140(target, info.m_b, 2) == 0)
        FUN_141a82dd0();
}

// @0x141a7ff60
void UIPopUpMenu::FUN_141a7ff60(const Unk_PopupMenuInfo& info, int nIndex, MS2Ptr<CUgcRegistBanner> spBanner)
{
    if (spBanner == 0)
        return;
    FUN_141a80770();
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    CStringW strName(spBanner->m_user.m_strName);
    if (pMe->vfunc_77() == strName)
        return;
    m_110 = 1;
    FUN_141a80af0(info);
    m_a0 = spBanner->m_user.m_accountId;
    m_a8 = spBanner->m_user.m_characterId;
    m_b0 = spBanner->m_user.m_strName;
    m_b8 = spBanner->m_upload.m_uid;
    m_c0 = spBanner->m_upload.m_strName;
    m_c8 = nIndex;
    m_158 = spBanner->m_strUrl;
    if (FUN_141a828a0(strName, info, 4, 1) == 0)
        FUN_141a82dd0();
}

// @0x141a80210
void UIPopUpMenu::FUN_141a80210(const Unk_PopupMenuInfo& info, CClubMember* pMember)
{
    FUN_141a80770();
    CStringW strName = pMember->m_info.FUN_14020e5d0();
    if (strName.IsEmpty())
    {
        FUN_1401859c0(FUN_140166440(), 2, 0x13, L"UIPopUpMenu::PopUpMenuFromClubMember Empty Menu");
        return;
    }
    m_110 = 0xe;
    FUN_141a80af0(info);
    Unk_PmTarget target;
    target.m_pos = efd::Point3(info.m_x, info.m_y, 0);
    target.m_nLevel = (unsigned short)pMember->m_info.m_level;
    target.m_nCharId = pMember->m_info.m_characterId;
    target.m_strImage = FUN_141028be0(pMember->m_info.m_characterId, pMember->m_info.FUN_14020e6c0(), 1, CString(""));
    target.m_strName = strName;
    target.m_b38 = true;
    target.m_bOnline = pMember->m_f0 == 0;
    target.m_nTrophy = pMember->m_info.m_trophy.FUN_140267c10();
    target.m_n20 = pMember->m_info.m_jobCode;
    target.m_nJobCode = pMember->m_info.m_job;
    int nKind = 2;
    if (pMember->m_info.m_characterId != 0 && pMember->m_info.m_characterId == DAT_143ab2828)
        nKind = 1;
    m_a0 = pMember->m_info.m_accountId;
    m_a8 = pMember->m_info.m_characterId;
    m_b0 = pMember->m_info.FUN_14020e5d0();
    m_138 = 0;
    m_140 = L"";
    m_148 = "";
    if (FUN_141a82140(target, info.m_b, nKind) == 0)
        FUN_141a82dd0();
}

// @0x141a805f0
void UIPopUpMenu::FUN_141a805f0(const Unk_PopupMenuInfo& info, void* pAccount, unsigned __int64 nCharId, const CStringW& strName, const CStringW& strText, int nType)
{
    m_108 = strText;
    FUN_141a7f090(info, strName, nCharId, pAccount, nType, 1);
}

// @0x141a80670
void UIPopUpMenu::FUN_141a80670(const Unk_PopupMenuInfo& info)
{
    FUN_141a80770();
    FUN_141a80af0(info);
    m_110 = 0x10;
    Unk_PmTarget target;
    target.m_pos = efd::Point3(info.m_x, info.m_y, 0);
    target.m_nCharId = info.m_infoB.m_18;
    target.m_strName = info.m_infoB.m_20;
    FUN_141a82140(target, info.m_b, 0);
}

// @0x141a80770
void UIPopUpMenu::FUN_141a80770()
{
    if (m_100 == 0)
    {
        vfunc_47(1);
        if ((ASScrollingList*)m_f0.get() != 0)
            static_cast<Unk_PdScript*>((AScript*)m_f0.get())->FUN_1422bb330("close");
        FUN_141a82dd0();
        FUN_140b632f0()->FUN_1422d4840(this, 0);
        FUN_141930950(FUN_140c607b0(), this);
        FUN_141b38c70(FUN_140bc09f0(), this);
    }
}

// @0x141a80880
int UIPopUpMenu::FUN_141a80880()
{
    return m_100;
}

// @0x141a808a0
__int64 UIPopUpMenu::FUN_141a808a0()
{
    return m_a8;
}

// @0x141a808c0
CString UIPopUpMenu::FUN_141a808c0()
{
    return m_88;
}

// @0x141a80910
void UIPopUpMenu::FUN_141a80910()
{
    m_138 = FUN_1403ed290()->m_info.FUN_1404ccbd0();
    m_140 = FUN_1403ed290()->m_info.FUN_1404cccb0();
    m_148 = FUN_1403ed290()->m_info.FUN_1404ccdb0();
}

// @0x141a809e0
void UIPopUpMenu::FUN_141a809e0(__int64 nGuildId, const CStringW& strGuild, const CString& strMark)
{
    m_138 = nGuildId;
    m_140 = strGuild;
    m_148 = strMark;
}

// @0x141a80a50
void UIPopUpMenu::FUN_141a80a50(CInPacket& packet)
{
    if (FUN_141a80880() != 0)
        return;
    unsigned char nMode = packet.vfunc_o8_1();
    if (nMode == 7)
    {
        FUN_141a80770();
    }
    else if (nMode == 8)
    {
        if (FUN_14162ab60(FUN_1409670d0()))
            FUN_141a80770();
    }
}

// @0x141a80af0
void UIPopUpMenu::FUN_141a80af0(const Unk_PopupMenuInfo& info)
{
    m_80 = info.m_a;
    m_84 = info.m_c;
    m_88 = info.m_str;
    m_a0 = (__int64)info.m_p;
    m_d0 = 0;
    m_d8 = 0;
    m_98 = 0;
    m_1a8 = Unk_PopupMenuInfo::Unk_PmA(info.m_infoA);
    m_1d0 = Unk_PopupMenuInfo::Unk_PmB(info.m_infoB);
}

// @0x141a80c40
void UIPopUpMenu::FUN_141a80c40()
{
    m_160.SetAt(100, Delegate<void()>(this, &UIPopUpMenu::FUN_141a84d40));
    m_160.SetAt(0x65, Delegate<void()>(this, &UIPopUpMenu::FUN_141a84da0));
    m_160.SetAt(0x66, Delegate<void()>(this, &UIPopUpMenu::FUN_141a84df0));
    m_160.SetAt(200, Delegate<void()>(this, &UIPopUpMenu::FUN_141a84f60));
    m_160.SetAt(0xc9, Delegate<void()>(this, &UIPopUpMenu::FUN_141a84f90));
    m_160.SetAt(0xca, Delegate<void()>(this, &UIPopUpMenu::FUN_141a85010));
    m_160.SetAt(0xcb, Delegate<void()>(this, &UIPopUpMenu::FUN_141a85120));
    m_160.SetAt(0xcc, Delegate<void()>(this, &UIPopUpMenu::FUN_141a85230));
    m_160.SetAt(0xcd, Delegate<void()>(this, &UIPopUpMenu::FUN_141a853a0));
    m_160.SetAt(300, Delegate<void()>(this, &UIPopUpMenu::FUN_141a853c0));
    m_160.SetAt(0x12d, Delegate<void()>(this, &UIPopUpMenu::FUN_141a85410));
    m_160.SetAt(400, Delegate<void()>(this, &UIPopUpMenu::FUN_141a85460));
    m_160.SetAt(0x191, Delegate<void()>(this, &UIPopUpMenu::FUN_141a854b0));
    m_160.SetAt(0x192, Delegate<void()>(this, &UIPopUpMenu::FUN_141a85500));
    m_160.SetAt(500, Delegate<void()>(this, &UIPopUpMenu::FUN_141a85680));
    m_160.SetAt(0x1f5, Delegate<void()>(this, &UIPopUpMenu::FUN_141a85760));
    m_160.SetAt(0x1f6, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86920));
    m_160.SetAt(0x1f7, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86970));
    m_160.SetAt(0x1f8, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86a50));
    m_160.SetAt(0x1f9, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86ad0));
    m_160.SetAt(0x1fa, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86b80));
    if (FUN_140166410()->FUN_14036d570(0x100))
        m_160.SetAt(0x1fb, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86bd0));
    m_160.SetAt(0x1fc, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86ca0));
    m_160.SetAt(600, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86d20));
    m_160.SetAt(0x259, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86db0));
    m_160.SetAt(0x25a, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86e40));
    m_160.SetAt(0x2bd, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86ed0));
    m_160.SetAt(0x321, Delegate<void()>(this, &UIPopUpMenu::FUN_141a86f50));
    m_160.SetAt(0x385, Delegate<void()>(this, &UIPopUpMenu::FUN_141a87100));
    m_160.SetAt(0x386, Delegate<void()>(this, &UIPopUpMenu::FUN_141a87150));
    m_160.SetAt(0x387, Delegate<void()>(this, &UIPopUpMenu::FUN_141a871a0));
}

// @0x141a82140
int UIPopUpMenu::FUN_141a82140(const Unk_PmTarget& target, int nFlags, int nType)
{
    if (m_30 == 0)
        return 0;
    if (FUN_1409478c0()->FUN_140a18070() == 0)
        return 0;
    {
        MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
        bool bPopup = spField->m_bPopupMenu;
        if (!bPopup)
            return 0;
    }
    m_118.RemoveAll();
    FUN_141a83810(nFlags, nType, target);
    if (m_118.IsEmpty())
    {
        FUN_1401859c0(FUN_140166440(), 2, 0x13, L"UIPopUpMenu::Open Empty Menu");
        return 0;
    }
    float fDirX = 1.0f;
    int nDirY = 1;
    NiPoint3 kPos;
    float fOffset = 0;
    bool bPlaced = false;
    float fScale = FUN_14025e7a0()->FUN_1422afec0(m_28);
    if (m_80 == 1)
    {
        nDirY = 2;
        NiPoint3 kWorld;
        FUN_141a82f30(target.m_pos, kWorld, 1.0f);
        bPlaced = FUN_1409478c0()->FUN_140af0700(kWorld, kPos);
        if (!bPlaced)
        {
            fDirX = -1.0f;
            FUN_141a82f30(target.m_pos, kWorld, -1.0f);
            bPlaced = FUN_1409478c0()->FUN_140af0700(kWorld, kPos);
        }
        kPos *= fScale;
        fOffset = FUN_141a83db0();
        fOffset = fOffset * fScale;
    }
    else if (m_80 == 2)
    {
        bPlaced = true;
        kPos = target.m_pos;
        kPos *= fScale;
    }
    else if (m_80 == 3)
    {
        bPlaced = true;
        kPos = target.m_pos;
    }
    if (!bPlaced)
        return 0;
    ASObj obj(2);
    Unk_PdSetData(&obj, "type", (Unk_PmMenuType)m_84);
    {
        ASArray menu(2);
        FUN_141a84320(menu);
        obj.FUN_1409adbe0("menu", menu.FUN_1422bb870());
        obj.FUN_1409c4a30("posx", kPos.x);
        obj.FUN_1409c4a30("posy", kPos.y - fOffset);
        obj.FUN_1407cbb20("name", target.m_strName);
        obj.FUN_1409c4a30("dirx", fDirX);
        obj.FUN_1407cb9c0("diry", nDirY);
        obj.FUN_1407cb9c0("level", target.m_nLevel);
        obj.FUN_1407cba60("imgpath", target.m_strImage);
        obj.FUN_1407cb9c0("trophy", target.m_nTrophy);
        obj.FUN_1407cb9c0("jobcode", target.m_nJobCode);
    }
    Scaleform::GFx::Value list = reinterpret_cast<Unk_PmRoot*>(m_30.get())->FUN_140ba4cc0("open", obj);
    if (!FUN_1409b4d40(list))
        return 0;
    m_100 = 0;
    m_90 = target.m_strName;
    m_a8 = target.m_nCharId;
    vfunc_8(1);
    vfunc_47(0);
    FUN_140b632f0()->FUN_1422d4780(this, 0);
    FUN_1419308c0(FUN_140c607b0(), this);
    FUN_141b38be0(FUN_140bc09f0(), this);
    m_f0 = FUN_140bc61d0(m_28, list);
    return 1;
}

// @0x141a828a0
int UIPopUpMenu::FUN_141a828a0(CStringW strName, const Unk_PopupMenuInfo& info, int nMode, int nDir)
{
    if (m_30 == 0)
        return 0;
    if (FUN_1409478c0()->FUN_140a18070() == 0)
        return 0;
    float fX = info.m_x;
    float fY = info.m_y;
    m_118.RemoveAll();
    FUN_141a834e0(info.m_b, nMode, strName, nDir);
    if (m_118.IsEmpty())
    {
        FUN_1401859c0(FUN_140166440(), 2, 0x13, L"UIPopUpMenu::OpenFromCharName Empty Menu");
        return 0;
    }
    if (m_80 == 2)
    {
        fX = fX * FUN_1403ed2b0()->FUN_141adbe70();
        fY = fY * FUN_1403ed2b0()->FUN_141adbe70();
    }
    ASObj obj(2);
    Unk_PdSetData(&obj, "type", (Unk_PmMenuType)m_84);
    {
        ASArray menu(2);
        FUN_141a84320(menu);
        obj.FUN_1409adbe0("menu", menu.FUN_1422bb870());
        obj.FUN_1409c4a30("posx", fX);
        obj.FUN_1409c4a30("posy", fY);
        obj.FUN_1407cbb20("name", strName);
        Unk_PdSetData(&obj, "dirx", Unk_PmDirOn);
        Unk_PdSetData(&obj, "diry", Unk_PmDirOn);
    }
    Scaleform::GFx::Value list = reinterpret_cast<Unk_PmRoot*>(m_30.get())->FUN_140ba4cc0("open", obj);
    if (!FUN_1409b4d40(list))
        return 0;
    m_100 = 0;
    m_90 = strName;
    vfunc_8(1);
    vfunc_47(0);
    FUN_140b632f0()->FUN_1422d4780(this, 0);
    FUN_1419308c0(FUN_140c607b0(), this);
    FUN_141b38be0(FUN_140bc09f0(), this);
    m_f0 = FUN_140bc61d0(m_28, list);
    return 1;
}

// @0x141a82dd0
void UIPopUpMenu::FUN_141a82dd0()
{
    m_f0 = 0;
    m_e0 = NiPoint3(DAT_143b01a60);
    m_88 = "";
    m_a8 = 0;
    m_100 = 1;
    m_90 = L"";
    m_98 = 0;
    m_d0 = 0;
    m_80 = 0;
    m_84 = 0;
    m_b8 = 0;
}

// @0x141a82ed0
int UIPopUpMenu::FUN_141a82ed0(GameObject* pObject, NiPoint3& out, float fDir)
{
    if (pObject == 0)
        return 0;
    return FUN_141a82f30(pObject->vfunc_18(), out, fDir);
}

// @0x141a82f30
int UIPopUpMenu::FUN_141a82f30(const NiPoint3& pos, NiPoint3& out, float fDir)
{
    out = pos + NiPoint3(fDir * *FUN_1401d3200()->OffsetPcPopupMenu.Get(), 0, 0);
    return 1;
}

// @0x141a82fb0
void UIPopUpMenu::FUN_141a82fb0(const CString& strImage)
{
    if (FUN_141a80880() == 0 && !strImage.IsEmpty() && m_30.get() != 0)
        m_30->Invoke("setProfileImage", CString(strImage));
}

// @0x141a83080
// MS2-FUNCTIONAL: the Ridee owner check keeps the exe's dead result (it returns 0 like the exe)
int UIPopUpMenu::FUN_141a83080(GameObject* pObject)
{
    if (FUN_14087ddc0(pObject ? pObject->GetClassDesc() : 0, 0x6200004))
        return 1;
    if (FUN_14087ddc0(pObject ? pObject->GetClassDesc() : 0, 0x6200045))
    {
        efd::SmartPointer<Ridee> spRidee = efd::DynamicCast<Ridee>(pObject);
        if (spRidee != 0)
            efd::DynamicCast<MyPC>(FUN_141706540(spRidee));
    }
    else
    {
        if (FUN_14087ddc0(pObject ? pObject->GetClassDesc() : 0, 0x6200003))
            return 2;
        if (FUN_14087ddc0(pObject ? pObject->GetClassDesc() : 0, 0x6200074))
            return 5;
        if (FUN_14087ddc0(pObject ? pObject->GetClassDesc() : 0, 0x6200028))
            return 3;
    }
    return 0;
}

// @0x141a832e0
void UIPopUpMenu::FUN_141a832e0(GameObject* pObject, CStringW& strName)
{
    CPet* pPet = efd::DynamicCast<CPet>(pObject);
    if (pPet != 0)
    {
        strName = pPet->vfunc_77();
        return;
    }
    CNpc* pNpc = FUN_140a38a00(pObject);
    if (pNpc != 0)
    {
        strName = FUN_1401aa6a0(FUN_141092fa0(pNpc));
        return;
    }
    PC* pPC = efd::DynamicCast<PC>(pObject);
    if (pPC != 0)
    {
        strName = pPC->vfunc_77();
        return;
    }
    Ridee* pRidee = efd::DynamicCast<Ridee>(pObject);
    if (pRidee != 0)
    {
        PC* pOwner = efd::DynamicCast<PC>(FUN_141706540(pRidee));
        if (pOwner != 0)
            strName = pOwner->vfunc_77();
    }
}

// @0x141a834e0
int UIPopUpMenu::FUN_141a834e0(unsigned nFlags, int nType, const CStringW& strName, int nDir)
{
    if (strName.IsEmpty())
        return 0;
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return 0;
    if ((nFlags & 2) != 0)
        FUN_141a84520(nType, nDir, m_a8);
    if ((nFlags & 0x80) != 0)
        FUN_141a84980(nType, nDir);
    if ((nFlags & 0x100) != 0)
        FUN_141a849c0(nType, m_a8);
    if ((nFlags & 0x200) != 0)
        FUN_141a84a10(nType, m_a8);
    if ((nFlags & 8) != 0 && nType != 1 && 0 < strName.GetLength())
        FUN_141a847c0(nType, pMe, FUN_14097a780()->FUN_140ae4950(strName).get());
    if ((nFlags & 4) != 0)
        FUN_141a84590(nType, pMe, strName, nDir);
    if ((nFlags & 0x4000) != 0)
        FUN_141a84b40(nType, pMe, strName);
    if ((nFlags & 0x2000) != 0)
        FUN_141a84ac0(nType, m_a8);
    if ((nFlags & 0x10) != 0 && nType != 1 && 0 < strName.GetLength())
        FUN_141a84860(nType, pMe, FUN_14097a780()->FUN_140ae4950(strName).get());
    if ((nFlags & 0x40) != 0)
        FUN_141a84940(nType, nDir);
    return 1;
}

// @0x141a83810
int UIPopUpMenu::FUN_141a83810(unsigned nFlags, int nType, const Unk_PmTarget& target)
{
    CStringW strName(target.m_strName);
    __int64 nCharId = target.m_nCharId;
    if (strName.IsEmpty())
        return 0;
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return 0;
    int bOnline = target.m_bOnline;
    CStringW strUnused;
    if ((nFlags & 0x20) != 0)
        FUN_141a848d0(nType, bOnline, nCharId);
    if ((nFlags & 2) != 0)
        FUN_141a84520(nType, bOnline, nCharId);
    if ((nFlags & 0x80) != 0)
        FUN_141a84980(nType, bOnline);
    if ((nFlags & 0x100) != 0)
        FUN_141a849c0(nType, nCharId);
    if ((nFlags & 0x200) != 0)
        FUN_141a84a10(nType, nCharId);
    if ((nFlags & 0x10000) != 0)
        FUN_141a84c60(nType, pMe, m_a8);
    if ((nFlags & 8) != 0 && nType != 1 && nCharId != 0)
    {
        CBuddy* pBuddy = FUN_14097a780()->FUN_140ae4880(nCharId).get();
        FUN_141a847c0(nType, pMe, pBuddy);
    }
    if ((nFlags & 4) != 0)
        FUN_141a84590(nType, pMe, strName, bOnline);
    if ((nFlags & 0x4000) != 0)
        FUN_141a84b40(nType, pMe, strName);
    if ((nFlags & 0x2000) != 0)
        FUN_141a84ac0(nType, m_a8);
    if ((nFlags & 0x10) != 0 && nType != 1 && nCharId != 0)
    {
        CBuddy* pBuddy = FUN_14097a780()->FUN_140ae4880(nCharId).get();
        FUN_141a84860(nType, pMe, pBuddy);
    }
    if ((nFlags & 0x20000) != 0 && nType != 1 && nCharId != 0)
    {
        HomeBlockManager::HomePtr spHome = FUN_1414a5830()->FUN_140a47580(nCharId);
        FUN_141a84cb0(nType, pMe, spHome);
    }
    if ((nFlags & 0x400) != 0)
        FUN_141a84a60(nType);
    if ((nFlags & 0x800) != 0)
        FUN_141a84a90(nType);
    if ((nFlags & 0x8000) != 0)
        FUN_141a84b10(nType);
    if (FUN_140166410()->FUN_14036d570(0x39) && (nFlags & 0x1000) == 0x1000)
    {
        if (FUN_1409670e0()->FUN_1410c3180() == DAT_143ab2820 && nType != 1)
        {
            if (!target.m_b38)
            {
                FUN_141a844a0((Unk_PmMenuId)0x259);
                FUN_141a844a0((Unk_PmMenuId)0x25a);
            }
            else
            {
                FUN_141a844a0((Unk_PmMenuId)600);
                FUN_141a844a0((Unk_PmMenuId)0x25a);
            }
        }
    }
    if ((nFlags & 0x40) != 0)
        FUN_141a84940(nType, bOnline);
    return 1;
}

// @0x141a83db0
float UIPopUpMenu::FUN_141a83db0()
{
    float fNear = FUN_1409478c0()->FUN_141032df0();
    float fFar = FUN_1409478c0()->FUN_140b67d10();
    float fDepth = fFar - fNear;
    float fHeight = FUN_1409478c0()->FUN_1409f2430();
    float fOffset = 0;
    if (fDepth != 0.0f)
        fOffset = FUN_140bf4fd0((fFar / fHeight) * ((-1.0f / fDepth) * fHeight + fFar / fDepth) * 60.0f * ((float)DAT_143af62d8 / 1050.0f));
    return fOffset;
}

// @0x141a83ed0
void UIPopUpMenu::FUN_141a83ed0(int nQuery, int nKind)
{
    __int64 nBuddyId = m_d0;
    if (nBuddyId != 0)
    {
        CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4c30(m_d0, m_a8, m_90);
        if (spBuddy.get() != 0)
        {
            nBuddyId = spBuddy->FUN_1401cc2f0();
            if (nKind == 1 && spBuddy->FUN_1401cc5d0() != 0)
            {
                FUN_140d73bc0(0x623, 0, 0, CStringW(L""));
                return;
            }
        }
    }
    CString strBuddy = FUN_140719530(nBuddyId);
    CString strChar = FUN_140719530(m_a8);
    Unk_FcUIMsg msg;
    FUN_1422e4490(&msg);
    FUN_1422b7f70(&msg, nQuery);
    FUN_1422b7f70(&msg, nKind);
    FUN_1422b8310(&msg, m_90);
    FUN_1422b82b0(&msg, strBuddy);
    FUN_1422b82b0(&msg, strChar);
    UIDialog* pQuery = FUN_140ae5a30(0x4e4e);
    if (pQuery != 0)
        static_cast<IMessageListener*>(pQuery)->OnMessage(this, reinterpret_cast<UIMsg*>(&msg));
}

// @0x141a84130
void UIPopUpMenu::FUN_141a84130(int nQuery, int nKind)
{
    __int64 nHomeId = m_d8;
    if (nHomeId != 0)
    {
        HomeBlockManager::HomePtr spHome = FUN_1414a5830()->FUN_140a47490(m_d8);
        if (spHome == 0)
            return;
        nHomeId = spHome->m_18;
    }
    CString strHome = FUN_140719530(nHomeId);
    CString strChar = FUN_140719530(m_a8);
    Unk_FcUIMsg msg;
    FUN_1422e4490(&msg);
    FUN_1422b7f70(&msg, nQuery);
    FUN_1422b7f70(&msg, nKind);
    FUN_1422b8310(&msg, m_90);
    FUN_1422b82b0(&msg, strHome);
    FUN_1422b82b0(&msg, strChar);
    UIDialog* pQuery = FUN_140ae5a30(0x4e4e);
    if (pQuery != 0)
        static_cast<IMessageListener*>(pQuery)->OnMessage(this, reinterpret_cast<UIMsg*>(&msg));
}

// @0x141a842f0
void UIPopUpMenu::FUN_141a842f0()
{
    FUN_14162bdb0(FUN_1409670d0());
}

// @0x141a84320
void UIPopUpMenu::FUN_141a84320(ASArray& menu)
{
    if (m_118.IsEmpty())
        return;
    for (size_t i = 0; i < m_118.GetCount(); i++)
    {
        ASObj item(2);
        item.FUN_1409c0d20("id", m_118[i]);
        item.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141811980(7, m_118[i]));
        menu.FUN_1422bc050(item.FUN_1422bb870());
    }
}

// @0x141a844a0
void UIPopUpMenu::FUN_141a844a0(Unk_PmMenuId nMenuId)
{
    if (m_160.Lookup(nMenuId) == 0)
        Unk_PmLog(FUN_140166440(), 2, 0x13, L"UIPopUpMenu::AddPopupMenu NotFound MenuID:{0}", nMenuId);
    else
        m_118.Add(nMenuId);
}

// @0x141a84520
void UIPopUpMenu::FUN_141a84520(int nType, int bOnline, __int64 nCharId)
{
    if (nType == 1)
    {
        FUN_141a844a0((Unk_PmMenuId)100);
    }
    else
    {
        if (nCharId != 0)
            FUN_141a844a0((Unk_PmMenuId)0x66);
        if (bOnline != 0)
            FUN_141a844a0((Unk_PmMenuId)0x65);
    }
}

// @0x141a84590
void UIPopUpMenu::FUN_141a84590(int nType, MyPC* pMe, const CStringW& strName, int bOnline)
{
    if (pMe == 0)
        return;
    if (nType == 1)
    {
        if (pMe->FUN_141527280())
        {
            FUN_141a844a0((Unk_PmMenuId)200);
            if (FUN_14162ab60(FUN_1409670d0()))
                FUN_141a844a0((Unk_PmMenuId)0xcd);
        }
        return;
    }
    if (strName.IsEmpty())
        return;
    if (!pMe->FUN_141527280())
    {
        if (bOnline != 0)
            FUN_141a844a0((Unk_PmMenuId)0xc9);
    }
    else if (!FUN_14162ab60(FUN_1409670d0()))
    {
        if (FUN_14162ad50(FUN_1409670d0(), strName) != 0 && FUN_140166410()->FUN_14036d570(0xe0))
            FUN_141a844a0((Unk_PmMenuId)0xcc);
    }
    else if (FUN_14162ad50(FUN_1409670d0(), strName) == 0)
    {
        if (bOnline != 0)
            FUN_141a844a0((Unk_PmMenuId)0xc9);
    }
    else
    {
        FUN_141a844a0((Unk_PmMenuId)0xca);
        if (bOnline != 0)
            FUN_141a844a0((Unk_PmMenuId)0xcb);
        if (FUN_140166410()->FUN_14036d570(0xe0))
            FUN_141a844a0((Unk_PmMenuId)0xcc);
    }
}

// @0x141a847c0
void UIPopUpMenu::FUN_141a847c0(int nType, MyPC* pMe, CBuddy* pBuddy)
{
    if (pMe == 0)
        return;
    if (pBuddy == 0)
    {
        FUN_141a844a0((Unk_PmMenuId)0x12d);
    }
    else if (pBuddy->FUN_1401cc5f0() == 0)
    {
        if (pBuddy->FUN_1401cc5b0() == 0 && pBuddy->FUN_1401cc660() == 0)
            FUN_141a844a0((Unk_PmMenuId)0x12d);
    }
    else
    {
        FUN_141a844a0((Unk_PmMenuId)300);
    }
}

// @0x141a84860
void UIPopUpMenu::FUN_141a84860(int nType, MyPC* pMe, CBuddy* pBuddy)
{
    if (pBuddy != 0 && pBuddy->FUN_1401cc5b0() != 0)
    {
        FUN_141a844a0((Unk_PmMenuId)0x191);
        FUN_141a844a0((Unk_PmMenuId)0x192);
        return;
    }
    FUN_141a844a0((Unk_PmMenuId)400);
}

// @0x141a848d0
void UIPopUpMenu::FUN_141a848d0(int nType, int bOnline, __int64 nCharId)
{
    if (nType != 1 && bOnline != 0 && nCharId != 0 && FUN_1403ed2d0()->FUN_141bd1530(nCharId) != 0)
        FUN_141a844a0((Unk_PmMenuId)500);
}

// @0x141a84940
void UIPopUpMenu::FUN_141a84940(int nType, int bOnline)
{
    if (nType != 1 && bOnline != 0)
        FUN_141a844a0((Unk_PmMenuId)0x1f5);
}

// @0x141a84980
void UIPopUpMenu::FUN_141a84980(int nType, int bOnline)
{
    if (nType == 2 && bOnline != 0)
        FUN_141a844a0((Unk_PmMenuId)0x1f6);
}

// @0x141a849c0
void UIPopUpMenu::FUN_141a849c0(int nType, __int64 nCharId)
{
    if (nType == 2 && FUN_1418fd530(nCharId) != 0)
        FUN_141a844a0((Unk_PmMenuId)0x1f7);
}

// @0x141a84a10
void UIPopUpMenu::FUN_141a84a10(int nType, __int64 nCharId)
{
    if (nType == 2 && FUN_1418fd5d0(nCharId) != 0)
        FUN_141a844a0((Unk_PmMenuId)0x1f8);
}

// @0x141a84a60
void UIPopUpMenu::FUN_141a84a60(int nType)
{
    if (nType == 5)
        FUN_141a844a0((Unk_PmMenuId)0x1f9);
}

// @0x141a84a90
void UIPopUpMenu::FUN_141a84a90(int nType)
{
    if (nType == 5)
        FUN_141a844a0((Unk_PmMenuId)0x1fa);
}

// @0x141a84ac0
void UIPopUpMenu::FUN_141a84ac0(int nType, __int64 nCharId)
{
    if (nType == 2 && FUN_1418fd670(nCharId) != 0)
        FUN_141a844a0((Unk_PmMenuId)0x1fb);
}

// @0x141a84b10
void UIPopUpMenu::FUN_141a84b10(int nType)
{
    if (nType != 1)
        FUN_141a844a0((Unk_PmMenuId)0x1fc);
}

// @0x141a84b40
void UIPopUpMenu::FUN_141a84b40(int nType, MyPC* pMe, const CStringW& strName)
{
    if (pMe == 0)
        return;
    if (FUN_1413b6160(FUN_1403ed290()) != 0 && nType != 1 && 0 < strName.GetLength())
    {
        if (FUN_1403ed290()->m_info.FUN_1404cf9f0(strName).get() == 0)
            FUN_141a844a0((Unk_PmMenuId)0x2bd);
    }
}

// @0x141a84c60
void UIPopUpMenu::FUN_141a84c60(int nType, MyPC* pMe, __int64 nCharId)
{
    if (FUN_140900550() && nType == 2)
        FUN_141a844a0((Unk_PmMenuId)0x321);
}

// @0x141a84cb0
void UIPopUpMenu::FUN_141a84cb0(int nType, MyPC* pMe, HomeBlockManager::HomePtr spHome)
{
    if (spHome.get() == 0)
    {
        if (FUN_1409670e0()->FUN_1410c3180() == DAT_143ab2820)
            FUN_141a844a0((Unk_PmMenuId)0x385);
    }
    else
    {
        FUN_141a844a0((Unk_PmMenuId)0x386);
        FUN_141a844a0((Unk_PmMenuId)0x387);
    }
}

// ---- the menu handlers (registered in FUN_141a80c40) ----

// @0x141a84d40
void UIPopUpMenu::FUN_141a84d40()
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0 && FUN_141656a80(pMe) == m_a8)
        FUN_1403ed2b0()->FUN_141adc530(0x2711);
}

// @0x141a84da0
void UIPopUpMenu::FUN_141a84da0()
{
    if (FUN_141482e80()->m_48 != 0)
        FUN_141a252a0(FUN_141482e80()->m_48, m_90);
}

// @0x141a84df0
void UIPopUpMenu::FUN_141a84df0()
{
    UIPCInfoDialog* pInfo = Unk_PmGetDialog<UIPCInfoDialog>(0x4ec8);
    if (pInfo != 0 && m_a8 != 0 && m_100 == 0)
    {
        int nState = pInfo->FUN_14132c080(m_a8);
        if (nState == 1)
        {
            CStringW strKey(L"s_char_info_already_request");
            FUN_140d73aa0(FUN_14028b8e0(strKey), 0, 0, CStringW(L""));
        }
        else if (nState != 2)
        {
            FUN_1403ed2b0()->FUN_141adc690(0x4ec8);
            COutPacket packet(0x1e, 0);
            packet.Encode8(m_a8);
            FUN_140710590(packet);
        }
    }
}

// @0x141a84f60
void UIPopUpMenu::FUN_141a84f60()
{
    FUN_14162be10(FUN_1409670d0());
}

// @0x141a84f90
void UIPopUpMenu::FUN_141a84f90()
{
    if (!m_90.IsEmpty())
        FUN_14162ba50(FUN_1409670d0(), m_90);
}

// @0x141a85010
void UIPopUpMenu::FUN_141a85010()
{
    if (!m_90.IsEmpty())
    {
        CStringW strTag = FUN_1401e8510(L"expelMember:{0}", m_90);
        FUN_140d73aa0(FUN_14052bd00(0x340, m_90), 1, this, CStringW(strTag));
    }
}

// @0x141a85120
void UIPopUpMenu::FUN_141a85120()
{
    if (!m_90.IsEmpty())
    {
        CStringW strTag = FUN_1401e8510(L"changeChief:{0}", m_90);
        FUN_140d73aa0(FUN_14052bd00(0x33f, m_90), 1, this, CStringW(strTag));
    }
}

// @0x141a85230
void UIPopUpMenu::FUN_141a85230()
{
    if (m_a8 != 0)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &UIPopUpMenu::FUN_141a7e0a0),
                                                  FUN_1405c2690(CStringW(L"s_party_vote_kick_user_confirm"), m_90));
        if ((CMsgBoxData*)spBox.get() != 0)
            static_cast<Unk_PmMsgBox*>(spBox.get())->FUN_1405340b0(m_a8);
    }
}

// @0x141a853a0
void UIPopUpMenu::FUN_141a853a0()
{
    FUN_141a842f0();
}

// @0x141a853c0
void UIPopUpMenu::FUN_141a853c0()
{
    if (!m_90.IsEmpty())
        FUN_141a83ed0(1, 6);
}

// @0x141a85410
void UIPopUpMenu::FUN_141a85410()
{
    if (!m_90.IsEmpty())
        FUN_141a83ed0(0, 1);
}

// @0x141a85460
void UIPopUpMenu::FUN_141a85460()
{
    if (!m_90.IsEmpty())
        FUN_141a83ed0(0, 2);
}

// @0x141a854b0
void UIPopUpMenu::FUN_141a854b0()
{
    if (!m_90.IsEmpty())
        FUN_141a83ed0(1, 7);
}

// @0x141a85500
void UIPopUpMenu::FUN_141a85500()
{
    if (m_90.IsEmpty())
        return;
    UIDialog* pDialog;
    if (m_d0 == 0 || (pDialog = FUN_140ae5990(0x4e4d)) == 0 || pDialog->vfunc_55() != 0 ||
        FUN_1418d6960(reinterpret_cast<Unk_PmCommunity*>(pDialog)) != 3)
    {
        FUN_141a83ed0(0, 4);
    }
    else
    {
        CString strBuddy = FUN_140719530(m_d0);
        Unk_FcUIMsg msg;
    FUN_1422e4490(&msg);
        FUN_1422b82b0(&msg, "editMemo");
        FUN_1422b82b0(&msg, strBuddy);
        static_cast<IMessageListener*>(pDialog)->OnMessage(this, reinterpret_cast<UIMsg*>(&msg));
    }
}

// @0x141a85680
void UIPopUpMenu::FUN_141a85680()
{
    if (FUN_1403ed2b0()->FUN_141adc7f0(0x4e83) == 0)
        return;
    if (FUN_1403ed2b0()->FUN_141adc940(0x4e83) == 0)
    {
        FUN_140f8ff40(0x841, 1, 1);
    }
    else
    {
        BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(0x20);
        if (spBlock.get() == 0)
        {
            if (m_a8 != 0)
                FUN_14140ea30()->FUN_14185b870(m_a8);
        }
        else
        {
            FUN_140a2ff20(spBlock, 0x20, 0);
        }
    }
}

// @0x141a85760
void UIPopUpMenu::FUN_141a85760()
{
    if (m_90.IsEmpty())
        return;
    if (m_b8 == 0)
    {
        if (m_110 == 4 || m_110 == 6)
        {
            MS2Ptr<CUserReportData> spReport(new CUserReportData(1));
            spReport->SetField28((int)FUN_140c75430(spReport.get(), m_110));
            spReport->SetTitle(m_90);
            spReport->SetField78(m_108);
            spReport->SetFielda0(m_a0);
            spReport->SetFielda8(m_a8);
            spReport->SetFieldb0(m_b0);
            spReport->SetFieldd0(m_108);
            FUN_140d86260()->vfunc_48(spReport);
        }
        else if (m_110 == 0xf)
        {
            MS2Ptr<CUserReportData> spReport(new CUserReportData(7));
            spReport->SetField28((int)FUN_140c75430(spReport.get(), m_110));
            spReport->SetField40(m_1a8.m_08);
            spReport->SetTitle(m_1a8.m_10);
            spReport->SetField80(m_90);
            spReport->SetFielda0(m_1a8.m_00);
            spReport->SetFielda8(m_1a8.m_08);
            spReport->SetFieldb0(m_1a8.m_10);
            spReport->SetFieldd0(m_108);
            spReport->SetFieldb8(m_90);
            spReport->SetFieldf0(m_1a8.m_18);
            spReport->SetFieldf8(m_1a8.m_20);
            FUN_140d86260()->vfunc_48(spReport);
        }
        else if (m_110 == 0x10)
        {
            MS2Ptr<CUserReportData> spReport(new CUserReportData(8));
            spReport->SetField28((int)FUN_140c75430(spReport.get(), m_110));
            spReport->SetField88(m_1d0.m_00);
            spReport->SetField90(m_1d0.m_08);
            spReport->SetField98(m_1d0.m_10);
            spReport->SetField40(m_1d0.m_18);
            spReport->SetTitle(m_1d0.m_20);
            spReport->SetFielda0(m_1d0.m_28);
            spReport->SetFielda8(m_1d0.m_18);
            spReport->SetFieldb0(m_1d0.m_20);
            spReport->SetFielde0(m_1d0.m_00);
            spReport->SetFieldc0(m_1d0.m_08);
            spReport->SetFieldc8(FUN_14016a600(m_1d0.m_10, 0));
            FUN_140d86260()->vfunc_48(spReport);
        }
        else
        {
            MS2Ptr<CUserReportData> spReport(new CUserReportData(0));
            spReport->SetField28((int)FUN_140c75430(spReport.get(), m_110));
            spReport->SetField40(m_a8);
            spReport->SetTitle(m_90);
            spReport->SetFielda0(m_a0);
            spReport->SetFielda8(m_a8);
            spReport->SetFieldb0(m_b0);
            spReport->SetFieldb8(m_b0);
            spReport->SetFieldd0(m_108);
            spReport->SetFielde0(m_138);
            spReport->SetField100(m_140);
            spReport->SetField108(m_148);
            FUN_140d86260()->vfunc_48(spReport);
        }
    }
    else
    {
        MS2Ptr<CUserReportData> spReport(new CUserReportData(2));
        spReport->SetField28(4);
        spReport->SetField48(m_b8);
        spReport->SetField58(m_c8);
        spReport->SetField50(m_c0);
        spReport->SetTitle(m_90);
        spReport->SetFielda0(m_a0);
        spReport->SetFielda8(m_a8);
        spReport->SetFieldb0(m_b0);
        spReport->SetFieldc0(m_c8);
        spReport->SetFieldc8(m_158);
        FUN_140d86260()->vfunc_48(spReport);
    }
}

// @0x141a86920
void UIPopUpMenu::FUN_141a86920()
{
    if (FUN_141482e80()->m_50 != 0)
        FUN_141951f70(FUN_141482e80()->m_50, m_90);
}

// @0x141a86970
void UIPopUpMenu::FUN_141a86970()
{
    if (FUN_1418fd330(m_a8) != 0)
        FUN_1418fde20(m_a0, m_a8, m_110, m_90, Delegate<bool(int, const CMsgBoxData&)>(this, &UIPopUpMenu::FUN_141a7e020));
}

// @0x141a86a50
void UIPopUpMenu::FUN_141a86a50()
{
    if (FUN_1418fd580(m_a8) != 0)
    {
        COutPacket packet(0x51, 0);
        packet.Encode1(1);
        packet.COutPacket::vfunc_o10_8(m_90);
        FUN_140710590(packet);
    }
}

// @0x141a86ad0
void UIPopUpMenu::FUN_141a86ad0()
{
    if (m_1a8.m_08 == DAT_143ab2828)
    {
        FUN_1403ed2b0()->FUN_141adc530(0x4f38);
    }
    else
    {
        COutPacket packet(0x78, 0);
        packet.Encode1(0x10);
        packet.Encode8(m_1a8.m_08);
        packet.Encode8(m_1a8.m_20);
        FUN_140710590(packet);
    }
}

// @0x141a86b80
void UIPopUpMenu::FUN_141a86b80()
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0)
        pMe->FUN_14152b800(FUN_1416769f0(pMe));
}

// @0x141a86bd0
void UIPopUpMenu::FUN_141a86bd0()
{
    if (FUN_140166410()->FUN_14036d570(0x100))
    {
        COutPacket packet(0x37, 0);
        packet.Encode1(0x39);
        packet.COutPacket::vfunc_o10_6(FUN_14016a600(m_90, 0));
        FUN_140710590(packet);
    }
}

// @0x141a86ca0
void UIPopUpMenu::FUN_141a86ca0()
{
    __int64 nCharId = m_a8;
    if (FUN_1403ed2b0()->FUN_141adc940(0x4f4e) != 0)
        FUN_1403ed2b0()->FUN_141adc530(0x4f4e);
    Unk_PmCouple* pCouple = reinterpret_cast<Unk_PmCouple*>(FUN_1417f5780(0x4f4e));
    if (pCouple != 0)
        pCouple->FUN_140bed2a0(nCharId);
}

// @0x141a86d20
void UIPopUpMenu::FUN_141a86d20()
{
    if (!m_90.IsEmpty())
    {
        COutPacket packet(0x90, 0);
        packet.Encode1(1);
        packet.COutPacket::vfunc_o10_8(m_90);
        FUN_140710590(packet);
    }
}

// @0x141a86db0
void UIPopUpMenu::FUN_141a86db0()
{
    if (!m_90.IsEmpty())
    {
        COutPacket packet(0x90, 0);
        packet.Encode1(3);
        packet.COutPacket::vfunc_o10_8(m_90);
        FUN_140710590(packet);
    }
}

// @0x141a86e40
void UIPopUpMenu::FUN_141a86e40()
{
    if (!m_90.IsEmpty())
    {
        COutPacket packet(0x90, 0);
        packet.Encode1(2);
        packet.COutPacket::vfunc_o10_8(m_90);
        FUN_140710590(packet);
    }
}

// @0x141a86ed0
void UIPopUpMenu::FUN_141a86ed0()
{
    if (!m_90.IsEmpty())
        FUN_1413b71c0(FUN_1403ed290(), m_90);
}

// @0x141a86f50
void UIPopUpMenu::FUN_141a86f50()
{
    if (!m_90.IsEmpty() && FUN_140900550())
    {
        CStringW strText = FUN_14028b8e0(CStringW(L"s_wedding_msg_box_propose_confirm"));
        Unk_PmShowYesNo(strText, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &UIPopUpMenu::FUN_141a7e100), m_90);
    }
}

// @0x141a87100
void UIPopUpMenu::FUN_141a87100()
{
    if (!m_90.IsEmpty())
        FUN_141a84130(0, 3);
}

// @0x141a87150
void UIPopUpMenu::FUN_141a87150()
{
    if (!m_90.IsEmpty())
        FUN_141a84130(1, 8);
}

// @0x141a871a0
void UIPopUpMenu::FUN_141a871a0()
{
    if (m_90.IsEmpty())
        return;
    UIDialog* pDialog;
    if (m_d8 == 0 || (pDialog = FUN_140ae5990(0x4e4d)) == 0 || pDialog->vfunc_55() != 0 ||
        FUN_1418d6960(reinterpret_cast<Unk_PmCommunity*>(pDialog)) != 4)
    {
        FUN_141a84130(0, 5);
    }
    else
    {
        CString strHome = FUN_140719530(m_d8);
        Unk_FcUIMsg msg;
    FUN_1422e4490(&msg);
        FUN_1422b82b0(&msg, "editMemoHomeBlock");
        FUN_1422b82b0(&msg, strHome);
        static_cast<IMessageListener*>(pDialog)->OnMessage(this, reinterpret_cast<UIMsg*>(&msg));
    }
}

// ======== the popup dispatch (the sixth TU of this range: right click on the scene) ========

// The pick result of CameraMgr::FUN_140af0850 (camera.cpp layout; dtor 0x140a16120 bound in symbols-manual.tsv).
class Unk_GoPickHit;
void* FUN_140a17cb0(Unk_GoPickHit* pHit);                               // the picked mesh
class Unk_GoPickVec
{
public:
    unsigned int FUN_140a17ea0();                                       // size
    Unk_GoPickHit* FUN_140a17d70(unsigned int nIndex);
};
Unk_GoPickVec* FUN_140a17e00(ecr::PickService::PickRecord* pRecord);    // the hits
class Unk_GoPickListPtr
{
public:
    ~Unk_GoPickListPtr();                                               // 0x140a16120
    ecr::PickService::PickRecord* FUN_140a16c00() const;
    ecr::PickService::PickRecord* FUN_140a16c30() const;
    ecr::PickService::PickRecord* m_p;
};
class Unk_PpCamera : public Unk_PmCamera
{
public:
    Unk_GoPickListPtr FUN_140af0850(float fX, float fY, bool bFrontOnly, bool bAppCulled, bool bClosestOnly, NiAVObject* pRoot);
};
class Unk_PpScene;
Unk_PpScene* FUN_1408e57f0();                                           // the ui scene manager
int FUN_1422b9e00(Unk_PpScene* pScene);                                 // the focused scene id
int FUN_1422b9dc0(Unk_PpScene* pScene);                                 // the current scene id
class Unk_PpKeyState : public Unk_PeUiScale { public: int FUN_1422aeed0(int nKey); };   // a mouse button state
ecr::SceneGraphService* FUN_140ad4ba0();
int FUN_140ae11a0(egf::Entity* pEntity, unsigned int nPropId, int* pValue);   // an int property
void FUN_1408a2020(egf::Entity* pEntity, unsigned int nPropId, int* pValue);  // an int property
void FUN_1413fb630(egf::Entity* pEntity, std::vector<unsigned __int64>& meshes);   // the meshes of an entity
// The pick cursor point (TU-local): its ctor 0x141a8e170 constructs an efd::Point3 member (efd::Point3(x, y, z) 0x14027dda0).
struct Unk_PdCursor
{
    Unk_PdCursor(float fX, float fY, float fZ) : m_pt(fX, fY, fZ) {}
    efd::Point3 m_pt;
};
float FUN_140966f00(Unk_PdCursor kA, NiPoint3 kB);                      // the distance
class Unk_PpStates { public: efd::SmartPointer<CSceneStateBase> FUN_1417e26d0(); };   // CStateService
Unk_PpStates* FUN_140aa6d30();
CUgcManager* FUN_14052d220();
MS2Ptr<CInteractObjectData> FUN_14051f670(int nId);                    // the interact table row
extern int DAT_143ab0248;                                               // the client country
struct Unk_PpGuild : Unk_PmGuild { MS2Ptr<CGuildMember> FUN_1413b6200(__int64 nCharId); };
struct Unk_PpInteract : CInteractObjectData
{
    // @0x141a8e590
    bool FUN_141a8e590() { return m_eType == 7; }                       // a guild poster
};

// The entities of a world type hash (worldservice_1.cpp: a 16-byte box pointer to a list of entity references).
typedef ATL::CAtlList<efd::SmartPointer<egf::Entity> > Unk_PpEntityList;
void FUN_1409f20e0(void* pTagPtr);                                      // release
struct Unk_PpTagPtr
{
    ~Unk_PpTagPtr() { FUN_1409f20e0(this); }
    Unk_PpEntityList* operator->() const { return m_list; }
    void* m_unk;
    Unk_PpEntityList* m_list;
};
struct Unk_PpWorld : Unk_PdWorld
{
    Unk_PpTagPtr FUN_141bd0420(unsigned int nKey);
    GameObject* FUN_141bd1050(void* pMesh);                             // the game object of a mesh
    GameObject* FUN_141bd1180(int nId);
    PCBase* FUN_141bd1290(int nId);                                     // a player by object id
};

// The log calls with two and three arguments (0x141a8bdf0 / 0x141a8ba80 / 0x141a8c0f0).
template <class A, class B> void Unk_PpLog(CLogString* log, int level, int category, const wchar_t* format, const A& a, const B& b)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b), args));
}
template <class A, class B, class C> void Unk_PpLog(CLogString* log, int level, int category, const wchar_t* format, const A& a, const B& b, const C& c)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(c)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b, c), args));
}

bool FUN_141a8ab90(GameObject* pObject, float x, float y);
bool FUN_141a8b460(Unk_GoPickHit* pHit, float x, float y);
bool FUN_141a8b670(Unk_GoPickHit* pHit, float x, float y);
void FUN_141a8a990(CSceneStateBase* pState, float x, float y);
void FUN_141a8a730();
bool FUN_141a8b910();

// @0x141a8a010
// MS2-FUNCTIONAL: the exe passes the cursor (Unk_PdCursor, ctor 0x141a8e170) as a prvalue copied straight into the sort predicate; here it is a named local captured by the lambda (closure ctor call)
void FUN_141a8a010(float x, float y)
{
    if (FUN_1403ed2b0() == 0)
        return;
    if (FUN_14025e7a0() == 0)
        return;
    if (!FUN_141a8b910())
        return;
    if (static_cast<Unk_PpKeyState*>(FUN_14025e7a0())->FUN_1422aeed0(2) == 0)
    {
        if (FUN_1409478c0()->FUN_140a18070() == 0)
            return;
        Unk_GoPickListPtr spPick = static_cast<Unk_PpCamera*>(FUN_1409478c0())->FUN_140af0850(x, y, true, true, false, 0);
        if (spPick.FUN_140a16c00() == 0)
            return;
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001f)
            return;
        std::vector<GameObject*> objects;
        std::list<Unk_GoPickHit*> hits;
        for (unsigned int i = 0; i < FUN_140a17e00(spPick.FUN_140a16c30())->FUN_140a17ea0(); i++)
        {
            Unk_GoPickHit* pHit = FUN_140a17e00(spPick.FUN_140a16c30())->FUN_140a17d70(i);
            if (pHit == 0)
                continue;
            void* pMesh = FUN_140a17cb0(pHit);
            GameObject* pObject = static_cast<Unk_PpWorld*>(FUN_1403ed2d0())->FUN_141bd1050(pMesh);
            if (pObject == 0)
                hits.push_back(pHit);
            else if (std::find(objects.begin(), objects.end(), pObject) == objects.end())
                objects.push_back(pObject);
        }
        Unk_PdCursor kCursor(x, y, 0);
        std::sort(objects.begin(), objects.end(), [kCursor](GameObject* pA, GameObject* pB) -> bool {
            if (pA == 0 || pB == 0)
                return false;
            NiPoint3 kScreenA;
            NiPoint3 kScreenB;
            if (!FUN_1409478c0()->FUN_140af0700(pA->vfunc_18(), kScreenA))
                return false;
            if (!FUN_1409478c0()->FUN_140af0700(pB->vfunc_18(), kScreenB))
                return false;
            return FUN_140966f00(kCursor, kScreenA) < FUN_140966f00(kCursor, kScreenB);
        });
        for (std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
        {
            if (FUN_141a8ab90(*it, x, y))
                return;
        }
        for (std::list<Unk_GoPickHit*>::iterator it = hits.begin(); it != hits.end(); ++it)
        {
            Unk_GoPickHit* pHit = *it;
            if (pHit == 0)
                continue;
            if (FUN_141a8b460(pHit, x, y))
                return;
            if (FUN_141a8b670(pHit, x, y))
                return;
        }
        for (unsigned int i = 0; i < FUN_140a17e00(spPick.FUN_140a16c30())->FUN_140a17ea0(); i++)
        {
            Unk_GoPickHit* pHit = FUN_140a17e00(spPick.FUN_140a16c30())->FUN_140a17d70(i);
            GameObject* pObject = 0;
            NiAVObject* pNode = static_cast<NiAVObject*>(FUN_140a17cb0(pHit));
            egf::Entity* pEntity = FUN_140ad4ba0()->GetEntityFromSceneGraphNode(pNode);
            int nId = 0;
            if (FUN_140ae11a0(pEntity, 0x85b708e6, &nId) == 0)
                pObject = static_cast<Unk_PpWorld*>(FUN_1403ed2d0())->FUN_141bd1180(nId);
            if (pObject != 0 && FUN_141a8ab90(pObject, x, y))
                return;
        }
        efd::SmartPointer<CSceneStateBase> spState = FUN_140aa6d30()->FUN_1417e26d0();
        FUN_141a8a990(spState, x, y);
    }
    else
    {
        Unk_PpLog(FUN_140166440(), 0xc, 0x13, L"OnPopup UISwfEntity mouseX[{0}] mouseY[{1}]", x, y);
    }
    FUN_141a8a730();
}

// @0x141a8a730
void FUN_141a8a730()
{
    UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
    if (pMenu != 0)
        pMenu->FUN_141a80770();
}

// @0x141a8a760
int FUN_141a8a760()
{
    UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
    if (pMenu == 0)
        return false;
    return pMenu->FUN_141a80880() == 0;
}

// @0x141a8a7b0
void FUN_141a8a7b0(UIDialog* pDialog, float x, float y)
{
    Unk_PpLog(FUN_140166440(), 0xc, 0x13, L"OnPopup UIDialog name[{0}] mouseX[{1}] mouseY[{2}]", (const char*)pDialog->vfunc_1(), x, y);
}

// @0x141a8a870
void FUN_141a8a870(UISwfEntity* pEntity, float x, float y)
{
    UIDialog* pDialog = dynamic_cast<UIDialog*>(pEntity);
    if (pDialog != 0)
    {
        FUN_141a8a7b0(pDialog, x, y);
    }
    else if (pEntity != 0)
    {
        Unk_PpLog(FUN_140166440(), 0xc, 0x13, L"OnPopup UIEntity name[{0}] mouseX[{1}] mouseY[{2}]", (const char*)pEntity->vfunc_1(), x, y);
    }
}

// @0x141a8a990
void FUN_141a8a990(CSceneStateBase* pState, float x, float y)
{
    if (pState->GetClassID() == 0x620000b)
    {
        Unk_PpLog(FUN_140166440(), 0xc, 0x13, L"OnPopup SceneLogo mouseX[{0}] mouseY[{1}]", x, y);
    }
    else if (pState->GetClassID() == 0x6200009)
    {
        Unk_PpLog(FUN_140166440(), 0xc, 0x13, L"OnPopup SceneLogin mouseX[{0}] mouseY[{1}]", x, y);
    }
    else if (pState->GetClassID() == 0x620000d)
    {
        Unk_PpLog(FUN_140166440(), 0xc, 0x13, L"OnPopup SceneMulti mouseX[{0}] mouseY[{1}]", x, y);
    }
    else if (pState->GetClassID() == 0x620000c)
    {
        Unk_PpLog(FUN_140166440(), 0xc, 0x13, L"OnPopup SceneGame mouseX[{0}] mouseY[{1}]", x, y);
    }
    else if (pState->GetClassID() == 0x620000a)
    {
        Unk_PpLog(FUN_140166440(), 0xc, 0x13, L"OnPopup SceneLoading mouseX[{0}] mouseY[{1}]", x, y);
    }
    else
    {
        unsigned int nClassId = pState->GetClassID();
        Unk_PpLog(FUN_140166440(), 0xc, 0x13, L"ETC SceneLoading  Class ID : {0}, mouseX[{1}] mouseY[{2}]", nClassId, x, y);
    }
}

// @0x141a8ab90
// MS2-FUNCTIONAL: FUN_141a7e870's target is a common base of PCBase and CPet (passed as PCBase here)
bool FUN_141a8ab90(GameObject* pObject, float x, float y)
{
    if (FUN_1422b9dc0(FUN_1408e57f0()) != 0x620000c)
        return false;
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return false;
    UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
    if (pMenu == 0)
        return false;
    if (efd::DynamicCast<PortraitPC>(pObject) != 0)
        return false;
    PC* pPC = efd::DynamicCast<PC>(pObject);
    if (pPC != 0)
    {
        Unk_PopupMenuInfo info(x, y, 1, 0x3f3fe, 1, CString(""), 0);
        pMenu->FUN_141a7e280(info, pPC, 10);
        return true;
    }
    CPet* pPet = efd::DynamicCast<CPet>(pObject);
    if (pPet == 0)
        return false;
    PCBase* pPetTarget = static_cast<PCBase*>(static_cast<GameObject*>(pPet));
    if (pMe->FUN_141676a10() == pPet)
    {
        Unk_PopupMenuInfo info(x, y, 1, 0xc00, 0, CString(""), 0);
        info.m_infoA.m_00 = FUN_141656ad0(pMe);
        info.m_infoA.m_08 = FUN_141656a80(pMe);
        info.m_infoA.m_10 = pMe->vfunc_77();
        info.m_infoA.m_18 = pPet->FUN_140b10290();
        info.m_infoA.m_20 = FUN_1416769f0(pMe);
        pMenu->FUN_141a7e870(info, pPetTarget, 0xf);
        return true;
    }
    PCBase* pOwner = static_cast<Unk_PpWorld*>(FUN_1403ed2d0())->FUN_141bd1290(pPet->FUN_141094f40());
    if (pOwner == 0)
        return false;
    Unk_PopupMenuInfo info(x, y, 1, 0x440, 0, CString(""), 0);
    info.m_infoA.m_00 = FUN_141656ad0(pOwner);
    info.m_infoA.m_08 = FUN_141656a80(pOwner);
    info.m_infoA.m_10 = pOwner->vfunc_77();
    info.m_infoA.m_18 = pPet->FUN_140b10290();
    info.m_infoA.m_20 = FUN_1416769f0(pOwner);
    pMenu->FUN_141a7e870(info, pPetTarget, 0xf);
    return true;
}

// @0x141a8b020
void FUN_141a8b020(int nBannerId, float x, float y)
{
    if (FUN_1422b9dc0(FUN_1408e57f0()) != 0x620000c)
        return;
    UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
    if (pMenu == 0)
        return;
    MS2Ptr<CUgcRegistBanner> spBanner = FUN_14052d220()->FUN_141887ce0(nBannerId);
    if (spBanner == 0)
        return;
    Unk_PopupMenuInfo info(x, y, 2, 0x40, 0, CString(""), 0);
    pMenu->FUN_141a7ff60(info, nBannerId, spBanner);
}

// @0x141a8b190
bool FUN_141a8b190(MS2Ptr<CInteractObjectData> spData, float x, float y)
{
    if (FUN_1422b9dc0(FUN_1408e57f0()) != 0x620000c)
        return false;
    UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
    if (pMenu == 0 || DAT_143ab0248 != 3)
        return false;
    if (static_cast<Unk_PpInteract*>(spData.get())->FUN_141a8e590() != 1)
        return false;
    Unk_PopupMenuInfo info;
    info.m_a = 2;
    info.m_b = 0x40;
    info.m_c = 0;
    info.m_x = x;
    info.m_y = y;
    int nPosterId = spData->m_guild.m_nHousePosterId;
    info.m_infoB.m_08 = nPosterId;
    info.m_infoB.m_10 = FUN_1403ed290()->m_info.FUN_1404d2220(nPosterId);
    info.m_infoB.m_18 = FUN_1403ed290()->m_info.FUN_1404d2330(nPosterId);
    info.m_infoB.m_20 = FUN_1403ed290()->m_info.FUN_1404d2400(nPosterId);
    info.m_infoB.m_28 = 0;
    info.m_infoB.m_00 = FUN_1403ed290()->m_info.FUN_1404ccbd0();
    MS2Ptr<CGuildMember> spMember = static_cast<Unk_PpGuild*>(FUN_1403ed290())->FUN_1413b6200(info.m_infoB.m_18);
    if (spMember.get() != 0)
        info.m_infoB.m_28 = spMember->data.f00;   // the member's account id
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0 && FUN_141656a80(pMe) != info.m_infoB.m_18)
    {
        pMenu->FUN_141a80670(info);
        return true;
    }
    return false;
}

// @0x141a8b460
bool FUN_141a8b460(Unk_GoPickHit* pHit, float x, float y)
{
    Unk_PpTagPtr spList = static_cast<Unk_PpWorld*>(FUN_1403ed2d0())->FUN_141bd0420(0xc7f9dd65);
    if (spList.m_list == 0)
        return false;
    for (POSITION pos = spList->GetHeadPosition(); pos != 0; spList->GetNext(pos))
    {
        efd::SmartPointer<egf::Entity> spEntity = spList->GetAt(pos);
        if (spEntity == 0)
            continue;
        std::vector<unsigned __int64> meshes;
        FUN_1413fb630(spEntity, meshes);
        for (unsigned __int64 i = 0; i < meshes.size(); i++)
        {
            if ((unsigned __int64)FUN_140a17cb0(pHit) == meshes.at(i))
            {
                int nBannerId = 0;
                FUN_1408a2020(spEntity, 0x819a96c0, &nBannerId);
                FUN_141a8b020(nBannerId, x, y);
                return true;
            }
        }
    }
    return false;
}

// @0x141a8b670
bool FUN_141a8b670(Unk_GoPickHit* pHit, float x, float y)
{
    Unk_PpTagPtr spList = static_cast<Unk_PpWorld*>(FUN_1403ed2d0())->FUN_141bd0420(0x72f49865);
    if (spList.m_list == 0)
        return false;
    for (POSITION pos = spList->GetHeadPosition(); pos != 0; spList->GetNext(pos))
    {
        efd::SmartPointer<egf::Entity> spEntity = spList->GetAt(pos);
        if (spEntity == 0)
            continue;
        std::vector<unsigned __int64> meshes;
        FUN_1413fb630(spEntity, meshes);
        for (unsigned __int64 i = 0; i < meshes.size(); i++)
        {
            if ((unsigned __int64)FUN_140a17cb0(pHit) == meshes.at(i))
            {
                int nRowId = 0;
                FUN_1408a2020(spEntity, 0xd460e9bc, &nRowId);
                MS2Ptr<CInteractObjectData> spData = FUN_14051f670(nRowId);
                if (spData != 0 && FUN_141a8b190(spData, x, y) == true)
                    return true;
            }
        }
    }
    return false;
}

// @0x141a8b910
bool FUN_141a8b910()
{
    if (FUN_1403ed2d0() == 0)
        return true;
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return true;
    int nState = pMe->FUN_14166c930();
    if (nState == 0xe)
        return false;
    if (nState == 0x3f)
        return false;
    return true;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc1190-0x142cc1640 .text$yd
