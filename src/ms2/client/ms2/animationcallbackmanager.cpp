// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The text-key callback plumbing of the animation system:
// - Unk_AnimTable: per-owner table of the text keys ("HeightFromGround_<f>", free texts) of an actor's sequences. It
//   binds the owner (a GameObject) as the NiActorManager callback listener and registers the events of every sequence;
// - CGlobalKeyTextCallback: the world's listener of "bgEffect_<name>" text keys (plays the background effect);
// - AniCallbackBridge / AnimationCallbackManager: the queueing indirection between an NiActorManager and its listener
//   (in "queue mode" the events are stored and replayed later), plus the CAtlMap/CAtlList/NiTPointerMap glue they use.
// MS2-UNIT: client\ms2\animationcallbackmanager.cpp
// MS2-RANGE: 0x140996b20-0x14099db10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Kfn@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@4@$0A@@std@@SAAEBVEntityID@egf@@AEBU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@1@@Z 0x140998370 ; prop
// MS2-PIN: ??$_Kfn@$$CBVutf8string@efd@@I@?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@SAAEBVutf8string@efd@@AEBU?$pair@$$CBVutf8string@efd@@I@1@@Z 0x140998380 ; prop
// MS2-PIN: ??$_Lbound@VEntityID@egf@@@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@4@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@1@AEBVEntityID@egf@@@Z 0x140998390 ; prop
// MS2-PIN: ??$_Lbound@Vutf8string@efd@@@?$_Tree@V?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@1@AEBVutf8string@efd@@@Z 0x140998430 ; prop
// MS2-PIN: ??$addressof@$$CBU?$pair@$$CBVutf8string@efd@@I@std@@@std@@YAPEBU?$pair@$$CBVutf8string@efd@@I@0@AEBU10@@Z 0x1409984d0 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@0@AEBV10@@Z 0x1409984e0 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@YAPEAU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@0@AEAU10@@Z 0x1409984f0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@0@AEAV10@@Z 0x140998500 ; unique
// MS2-PIN: ??0?$SmartPointer@VNiSequenceData@@@efd@@QEAA@PEAVNiSequenceData@@@Z 0x140998680 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@1@@Z 0x140998770 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@1@@Z 0x1409987b0 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@1@@Z 0x1409987f0 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@1@@Z 0x140998830 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@1@@Z 0x140998870 ; prop
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140998d40 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140998d80 ; prop
// MS2-PIN: ??8@YA_NAEBVNiFixedString@@PEBD@Z 0x140998dc0 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140998e30 ; unique
// MS2-PIN: ??B?$SmartPointer@VNiSequenceData@@@efd@@QEBAPEAVNiSequenceData@@XZ 0x140998eb0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@4@$0A@@std@@@std@@IEBA_NAEBVEntityID@egf@@0@Z 0x14099aa10 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@@std@@IEBA_NAEBVutf8string@efd@@0@Z 0x14099aa50 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@4@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@2@XZ 0x14099aa90 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@4@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@2@XZ 0x14099aac0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@2@XZ 0x14099aaf0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@VEntityID@egf@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEAAAEAU?$less@VEntityID@egf@@@2@XZ 0x14099ab20 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@Vutf8string@efd@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBU?$less@Vutf8string@efd@@@2@XZ 0x14099ab40 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@VEntityID@egf@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@$00@2@XZ 0x14099ab50 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@VEntityID@egf@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@$00@2@XZ 0x14099ab60 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@Vutf8string@efd@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@2@XZ 0x14099ab70 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@2@XZ 0x14099ab80 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@2@XZ 0x14099aba0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@4@$0A@@std@@@std@@QEAAAEAU?$less@VEntityID@egf@@@2@XZ 0x14099abb0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@Vutf8string@efd@@@2@XZ 0x14099abf0 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@4@$0A@@std@@@std@@IEBAAEBVEntityID@egf@@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@PEAX@2@@Z 0x14099ac10 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@@std@@IEBAAEBVutf8string@efd@@PEAU?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@2@@Z 0x14099ac40 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@4@$0A@@std@@@std@@IEBAAEBVEntityID@egf@@AEBU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@2@@Z 0x14099ac70 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@@std@@IEBAAEBVutf8string@efd@@AEBU?$pair@$$CBVutf8string@efd@@I@2@@Z 0x14099ac90 ; prop
// MS2-PIN: ?compare@?$basic_string@DU?$char_traits@D@std@@V?$CustomAllocator@D@efd@@@std@@QEBAHAEBV12@@Z 0x14099ad60 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@2@XZ 0x14099ae70 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@2@AEBVutf8string@efd@@@Z 0x14099afb0 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x14099b190 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@Vutf8string@efd@@IU?$less@Vutf8string@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBVutf8string@efd@@I@std@@@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@2@AEBVutf8string@efd@@@Z 0x14099b1f0 ; prop
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@std@@@std@@SAPEAU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VActorEntry@AnimationService@egmAnimation@@@efd@@@2@AEAU32@@Z 0x14099b250 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?get@?$MS2Ptr@VCAnimationCallbackItem@@@@QEBAPEAVCAnimationCallbackItem@@XZ 0x140998ed0 ; hand
// MS2-PIN: ??0?$MS2Ptr@VCAnimationCallbackItem@@@@QEAA@AEBV0@@Z 0x1409986c0 ; hand
// MS2-PIN: ??C?$SmartPointer@VNiControllerManager@@@efd@@QEBAPEAVNiControllerManager@@XZ 0x140998ef0 ; hand
// MS2-FUNCTIONAL: opaque FUN_ callees (effect request, logger, locator service), ATL/STL glue not yet byte-paired.
#include "ms2/placeholder/ms2stdafx.h"
#include "animationcallbackmanager.h"
#include "gameobject.h"
#include "pcbase.h"
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\animationcallbackmanager.cpp"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ecrcameraservice.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <egmAnimation/AnimationService.h>
#include <efd/AssetID.h>
#include <efd/AssetLocatorService.h>
#include <efd/utf8string.h>
#include <egf/Entity.h>
#include <NiControllerManager.h>
#include <NiKFMTool.h>
#include <NiSequenceData.h>
#include <NiTextKeyExtraData.h>
#include <stdlib.h>

#include "ms2/commonfiles/logstring.h"

// ---- exe data ----
extern int DAT_143ae2b30;                   // 1: actor-manager callbacks are routed through the callback manager

// ---- exe functions outside this unit ----
egf::Entity* FUN_14123c410(GameObject* pObj);                                       // the owner's entity (0 if none)
NiActorManager* FUN_1413f9b70(const egf::EntityID& kId);                            // AnimationService::GetActorManager
bool FUN_14028d470(float fValue, float fCompare);                                   // float equality
CLogString* GetLogString();
void FUN_142095bc0(efd::AssetLocatorService* pService, const efd::utf8string& kUrn, efd::utf8string& kOut);
template <class T, class U> void Unk_FileLog(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat,
                                             const T& first, const U& second);      // filesystem.cpp 0x1403a1310

// The background effect play request is the NoticeMessage of effectquery.h (ctor 0x140a52ef0, dtor 0x1405a89e0).
class Unk_BgEffectMgr { public: void FUN_1411a4a00(NoticeMessage* pRequest); };
Unk_BgEffectMgr* FUN_1403ed280();

// The URN text of an asset id (m_urn.c_str() read straight off the AssetID, +8).
// @0x14099ad40
inline const char* Unk_AssetUrnText(const efd::AssetID* pAsset)
{
    return reinterpret_cast<const efd::utf8string*>(reinterpret_cast<const char*>(pAsset) + 8)->c_str();
}

// ---- singleton ----
AnimationCallbackManager* TSingleton<AnimationCallbackManager>::s_instance = 0;
// @0x14099c240
inline TSingleton<AnimationCallbackManager>::TSingleton() { s_instance = static_cast<AnimationCallbackManager*>(this); }

// ---- Unk_AnimTable ----
// @0x140996b20
Unk_AnimTable::Unk_AnimTable()
    : m_pActor(0)
{
}

// @0x140996b80
Unk_AnimTable::~Unk_AnimTable()
{
    m_items.RemoveAll();
}

// @0x140996bc0
bool Unk_AnimTable::FUN_140996bc0(GameObject* pObj)
{
    if (FUN_14123c410(pObj) == 0)
        return false;
    egmAnimation::AnimationService* pService = g_143b059e8.GetSystemServiceAs<egmAnimation::AnimationService>();
    if (pService == 0)
        return false;
    egf::EntityID kId;
    NiActorManager* pMgr = pService->GetActorManager(pObj->FUN_14123c460(kId));
    if (pMgr == 0)
        return false;
    if (m_pActor == pMgr)
        return true;
    m_pActor = pMgr;
    if (DAT_143ae2b30 == 0)
    {
        NiActorManager::CallbackObject* pCb = (pObj == 0) ? 0 : static_cast<NiActorManager::CallbackObject*>(pObj);
        m_pActor->SetCallbackObject(pCb);
    }
    else
    {
        NiActorManager::CallbackObject* pCb = (pObj == 0) ? 0 : static_cast<NiActorManager::CallbackObject*>(pObj);
        AnimationCallbackManager::GetInstance()->FUN_14099bb80(pMgr, pCb);
    }
    NiKFMTool* pKfm = m_pActor->GetKFMTool();
    unsigned int* pIds = 0;
    unsigned int nIds;
    pKfm->GetSequenceIDs(pIds, nIds);
    for (unsigned int i = 0; i < nIds; i++)
    {
        unsigned int uiSeq = pIds[i];
        NiSequenceData* pSeqData = static_cast<Unk_CbActorMgr*>(m_pActor)->FUN_140999740(uiSeq);
        if (pSeqData != 0)
        {
            NiTextKeyExtraData* pTextKeys = pSeqData->GetTextKeys();
            unsigned int nKeys = 0;
            NiTextKey* pKeys = pTextKeys->GetKeys(nKeys);
            const char* pszName = pSeqData->GetName();
            FUN_140997710(CString(pszName));
            ItemPtr spItem;
            if (m_items.Lookup(pszName, spItem))
            {
                for (unsigned int k = 0; k < nKeys; k++)
                {
                    const NiFixedString& kText = pKeys[k].GetText();
                    if (!(kText == "start") && !(kText == "end"))
                        FUN_140997990(ItemPtr(spItem), CString((const char*)kText));
                }
                pMgr->RegisterCallback(NiActorManager::ANIM_ACTIVATED, uiSeq, 0);
                pMgr->RegisterCallback(NiActorManager::END_OF_SEQUENCE, uiSeq);
                for (int t = 0; t < (int)spItem->m_texts.GetCount(); t++)
                    pMgr->RegisterCallback(NiActorManager::TEXT_KEY_EVENT, uiSeq, NiFixedString((const char*)spItem->m_texts[t]));
            }
        }
    }
    if (pIds != 0)
        NiFree(pIds);
    return true;
}

// @0x140997070
bool Unk_AnimTable::FUN_140997070(GameObject* pObj, CString strName)
{
    if (m_items.Lookup((const char*)strName) != 0)
        return true;
    if (FUN_14123c410(pObj) == 0)
        return false;
    egmAnimation::AnimationService* pService = g_143b059e8.GetSystemServiceAs<egmAnimation::AnimationService>();
    if (pService == 0)
        return false;
    egf::EntityID kId;
    NiActorManager* pMgr = pService->GetActorManager(pObj->FUN_14123c460(kId));
    if (pMgr == 0)
        return false;
    if (m_pActor != pMgr)
    {
        m_pActor = pMgr;
        if (DAT_143ae2b30 == 0)
        {
            NiActorManager::CallbackObject* pCb = (pObj == 0) ? 0 : static_cast<NiActorManager::CallbackObject*>(pObj);
            m_pActor->SetCallbackObject(pCb);
        }
        else
        {
            NiActorManager::CallbackObject* pCb = (pObj == 0) ? 0 : static_cast<NiActorManager::CallbackObject*>(pObj);
            AnimationCallbackManager::GetInstance()->FUN_14099bb80(pMgr, pCb);
        }
    }
    efd::utf8string kName((const char*)strName);
    egf::EntityID kId2;
    NiActorManager::SequenceID uiSeq = pService->GetAnimationIdFromName(pObj->FUN_14123c460(kId2), kName);
    NiSequenceData* pSeqData = static_cast<Unk_CbActorMgr*>(m_pActor)->FUN_140999740(uiSeq);
    if (pSeqData == 0)
        return false;
    NiTextKeyExtraData* pTextKeys = pSeqData->GetTextKeys();
    unsigned int nKeys = 0;
    NiTextKey* pKeys = pTextKeys->GetKeys(nKeys);
    FUN_140997710(CString(strName));
    ItemPtr spItem;
    if (m_items.Lookup((const char*)strName, spItem))
    {
        for (unsigned int k = 0; k < nKeys; k++)
        {
            const NiFixedString& kText = pKeys[k].GetText();
            if (!(kText == "start") && !(kText == "end"))
                FUN_140997990(ItemPtr(spItem), CString((const char*)kText));
        }
        pMgr->RegisterCallback(NiActorManager::ANIM_ACTIVATED, uiSeq, 0);
        pMgr->RegisterCallback(NiActorManager::END_OF_SEQUENCE, uiSeq, 0);
        for (int t = 0; t < (int)spItem->m_texts.GetCount(); t++)
            pMgr->RegisterCallback(NiActorManager::TEXT_KEY_EVENT, uiSeq, NiFixedString((const char*)spItem->m_texts[t]));
    }
    return true;
}

// @0x1409975a0
void Unk_AnimTable::FUN_1409975a0(GameObject* pObj)
{
    egmAnimation::AnimationService* pService = g_143b059e8.GetSystemServiceAs<egmAnimation::AnimationService>();
    if (pService != 0)
    {
        egf::EntityID kId;
        NiActorManager* pMgr = pService->GetActorManager(pObj->FUN_14123c460(kId));
        if (pMgr != 0)
        {
            m_items.RemoveAll();
            if (DAT_143ae2b30 == 0)
            {
                pMgr->SetCallbackObject(0);
                pMgr->ClearAllRegisteredCallbacks();
            }
            else
            {
                AnimationCallbackManager::GetInstance()->FUN_14099bb80(pMgr, 0);
            }
        }
    }
}

// @0x140997650
float Unk_AnimTable::FUN_140997650(CString strName)
{
    ItemPtr spItem;
    m_items.Lookup((const char*)strName, spItem);
    if (spItem.get() == 0)
        return 0.0f;
    return spItem->m_fHeight;
}

// @0x140997710
bool Unk_AnimTable::FUN_140997710(CString strName)
{
    ItemPtr spItem(0);
    if (!m_items.Lookup((const char*)strName, spItem))
    {
        spItem.AssignRaw(new CAnimationCallbackItem);
        m_items.SetAt((const char*)strName, spItem);
    }
    return true;
}

// @0x1409977f0
bool Unk_AnimTable::FUN_1409977f0(CString strName, CString strText)
{
    ItemPtr spItem(0);
    if (!m_items.Lookup((const char*)strName, spItem))
    {
        spItem.AssignRaw(new CAnimationCallbackItem);
        m_items.SetAt((const char*)strName, spItem);
    }
    spItem->m_texts.Add(strText);
    if (FUN_14028d470(spItem->m_fHeight, 0.0f))
    {
        if (strText.Find("HeightFromGround_", 0) == 0)
        {
            strText.Replace("HeightFromGround_", "");
            spItem->m_fHeight = (float)atof((const char*)strText);
        }
    }
    return true;
}

// @0x140997990
bool Unk_AnimTable::FUN_140997990(ItemPtr spItem, CString strText)
{
    if (spItem.IsNull())
        return false;
    spItem->m_texts.Add(strText);
    if (FUN_14028d470(spItem->m_fHeight, 0.0f))
    {
        if (strText.Find("HeightFromGround_", 0) == 0)
        {
            strText.Replace("HeightFromGround_", "");
            spItem->m_fHeight = (float)atof((const char*)strText);
        }
    }
    return true;
}

// Registers the entity's actor manager with the global listener: every non-trivial text key becomes a callback; the
// "emo_" / "-GlobalRatio" keys of an asset without an expression table are reported.
// @0x140997ab0
void FUN_140997ab0(egf::EntityPtr spEntity, NiActorManager::CallbackObject* pCb)
{
    if (spEntity == 0)
        return;
    NiActorManager* pMgr = FUN_1413f9b70(spEntity->GetEntityID());
    if (pMgr == 0)
        return;
    if (DAT_143ae2b30 != 0)
    {
        AnimationCallbackManager::GetInstance()->FUN_14099bb80(pMgr, pCb);
    }
    else
    {
        pMgr->SetCallbackObject(0);
        pMgr->ClearAllRegisteredCallbacks();
        pMgr->SetCallbackObject(pCb);
    }
    NiKFMTool* pKfm = pMgr->GetKFMTool();
    unsigned int* pIds = 0;
    unsigned int nIds;
    pKfm->GetSequenceIDs(pIds, nIds);
    for (unsigned int i = 0; i < nIds; i++)
    {
        unsigned int uiSeq = pIds[i];
        NiSequenceData* pSeqData = static_cast<Unk_CbActorMgr*>(pMgr)->FUN_140999740(uiSeq);
        if (pSeqData == 0)
            continue;
        NiTextKeyExtraData* pTextKeys = pSeqData->GetTextKeys();
        unsigned int nKeys = 0;
        NiTextKey* pKeys = pTextKeys->GetKeys(nKeys);
        pMgr->RegisterCallback(NiActorManager::ANIM_ACTIVATED, uiSeq, 0);
        pMgr->RegisterCallback(NiActorManager::END_OF_SEQUENCE, uiSeq, 0);
        for (unsigned int k = 0; k < nKeys; k++)
        {
            const NiFixedString& kText = pKeys[k].GetText();
            if (kText == "start" || kText == "end")
                continue;
            if (kText.Contains("emo_") || kText.Contains("-GlobalRatio"))
            {
                efd::AssetID kAsset;
                spEntity->GetPropertyValue(0x12383cea, kAsset);
                efd::AssetLocatorService* pLocator =
                    g_143b059e8.GetSystemServiceAs<efd::AssetLocatorService>();
                efd::utf8string kResult("Unknown");
                {
                    efd::utf8string kUrn(Unk_AssetUrnText(&kAsset));
                    FUN_142095bc0(pLocator, kUrn, kResult);
                }
                const char* pszResult = kResult.c_str();
                const char* pszKey = (const char*)kText;
                Unk_FileLog(GetLogString(), 12, 0x13, L"skip text {0} - [{1}]", pszKey, pszResult);
                continue;
            }
            pMgr->RegisterCallback(NiActorManager::TEXT_KEY_EVENT, uiSeq, kText);
        }
    }
    if (pIds != 0)
        NiFree(pIds);
}

// ---- CGlobalKeyTextCallback ----
// @0x140997ec0
void CGlobalKeyTextCallback::FUN_140997ec0(egf::EntityPtr pEntity)
{
    FUN_140997ab0(pEntity, this);
}

// @0x140997f20
void CGlobalKeyTextCallback::AnimActivated(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float)
{
}

// @0x140997f40
void CGlobalKeyTextCallback::AnimDeactivated(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float)
{
}

// @0x140997f60
void CGlobalKeyTextCallback::AnimCompleted(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float)
{
}

// @0x140997f80
void CGlobalKeyTextCallback::TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID,
    const NiFixedString& kTextKey, const NiTextKeyMatch*, NiControllerSequence*, float)
{
    CString strKey((const char*)kTextKey);
    if (strKey.Find("bgEffect_", 0) == 0)
    {
        NoticeMessage kRequest;
        kRequest.m_strName = strKey.Right(strKey.GetLength() - 9);
        kRequest.m_nObject = 7;
        if (DAT_143ae2b30 != 0)
        {
            NiActorManager::CallbackObject* pCb = pkManager->GetCallbackObject();
            AniCallbackBridge* pBridge = dynamic_cast<AniCallbackBridge*>(pCb);
            if (pBridge != 0)
            {
                PCBase* pPC = dynamic_cast<PCBase*>(pBridge->m_pTarget);
                if (pPC != 0)
                    kRequest.SetActor(pPC->FUN_14123c580());
            }
        }
        else
        {
            NiActorManager::CallbackObject* pCb = pkManager->GetCallbackObject();
            PCBase* pPC = dynamic_cast<PCBase*>(pCb);
            if (pPC != 0)
                kRequest.SetActor(pPC->FUN_14123c580());
        }
        FUN_1403ed280()->FUN_1411a4a00(&kRequest);
    }
}

// @0x140998180
void CGlobalKeyTextCallback::EndOfSequence(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float)
{
}

// ---- MS2 NiActorManager::GetSequenceData ----
// @0x140999740
NiSequenceData* Unk_CbActorMgr::FUN_140999740(SequenceID eSequenceID)
{
    NiSequenceDataPtr spSeqData(0);
    if (m_kMS2PendingSeqDataMap.GetAt(eSequenceID, spSeqData))
    {
        m_spManager->AddSequenceData(spSeqData);
        m_kSeqDataMap.SetAt(eSequenceID, spSeqData);
        m_kMS2PendingSeqDataMap.RemoveAt(eSequenceID);
        return spSeqData;
    }
    if (!m_kSeqDataMap.GetAt(eSequenceID, spSeqData))
        return 0;
    return spSeqData;
}

// ---- AniCallbackBridge ----
// @0x14099b290
AniCallbackBridge::AniCallbackBridge(NiActorManager::CallbackObject* pTarget)
    : m_pTarget(pTarget), m_queue(10)
{
}

// @0x14099b2f0
AniCallbackBridge::~AniCallbackBridge()
{
    m_queue.RemoveAll();
}

// @0x14099b330
void AniCallbackBridge::FUN_14099b330(NiActorManager::CallbackObject* pObj)
{
    MS2_ASSERT_AT(0x16, pObj != 0);
    m_pTarget = pObj;
    m_queue.RemoveAll();
}

// @0x14099b390
void AniCallbackBridge::AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (AnimationCallbackManager::GetInstance()->GetQueueMode() == 0)
    {
        if (m_pTarget != 0)
            m_pTarget->AnimActivated(pkManager, eSequenceID, pkSeq, fEventTime);
    }
    else
    {
        m_queue.AddTail(Unk_BridgeEvent(0, pkManager, eSequenceID, NiFixedString(), 0, pkSeq, fEventTime));
    }
}

// @0x14099b4d0
void AniCallbackBridge::AnimDeactivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (AnimationCallbackManager::GetInstance()->GetQueueMode() == 0)
    {
        if (m_pTarget != 0)
            m_pTarget->AnimDeactivated(pkManager, eSequenceID, pkSeq, fEventTime);
    }
    else
    {
        m_queue.AddTail(Unk_BridgeEvent(1, pkManager, eSequenceID, NiFixedString(), 0, pkSeq, fEventTime));
    }
}

// @0x14099b620
void AniCallbackBridge::AnimCompleted(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (AnimationCallbackManager::GetInstance()->GetQueueMode() == 0)
    {
        if (m_pTarget != 0)
            m_pTarget->AnimCompleted(pkManager, eSequenceID, pkSeq, fEventTime);
    }
    else
    {
        m_queue.AddTail(Unk_BridgeEvent(2, pkManager, eSequenceID, NiFixedString(), 0, pkSeq, fEventTime));
    }
}

// @0x14099b770
void AniCallbackBridge::TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime)
{
    if (AnimationCallbackManager::GetInstance()->GetQueueMode() == 0)
    {
        if (m_pTarget != 0)
            m_pTarget->TextKeyEvent(pkManager, eSequenceID, kTextKey, pkMatchObject, pkSeq, fEventTime);
    }
    else
    {
        m_queue.AddTail(Unk_BridgeEvent(3, pkManager, eSequenceID, kTextKey, pkMatchObject, pkSeq, fEventTime));
    }
}

// @0x14099b8b0
void AniCallbackBridge::EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (AnimationCallbackManager::GetInstance()->GetQueueMode() == 0)
    {
        if (m_pTarget != 0)
            m_pTarget->EndOfSequence(pkManager, eSequenceID, pkSeq, fEventTime);
    }
    else
    {
        m_queue.AddTail(Unk_BridgeEvent(4, pkManager, eSequenceID, NiFixedString(), 0, pkSeq, fEventTime));
    }
}

// ---- AnimationCallbackManager ----
// @0x14099ba00
AnimationCallbackManager::AnimationCallbackManager()
    : m_nQueue(0)
{
}

// @0x14099ba80
AnimationCallbackManager::~AnimationCallbackManager()
{
    POSITION pos = m_bridges.GetStartPosition();
    while (pos != 0)
    {
        AniCallbackBridge* pBridge = m_bridges.GetValueAt(pos);
        if (pBridge != 0)
            delete pBridge;
        m_bridges.GetNext(pos);
    }
    m_bridges.RemoveAll();
}

// @0x14099bb80
void AnimationCallbackManager::FUN_14099bb80(NiActorManager* pMgr, NiActorManager::CallbackObject* pCb)
{
    if (pMgr != 0)
    {
        if (pCb == 0)
        {
            AniCallbackBridge* pBridge = 0;
            if (!m_bridges.Lookup(pMgr, pBridge))
            {
                pMgr->SetCallbackObject(0);
                pMgr->ClearAllRegisteredCallbacks();
            }
            else
            {
                pMgr->SetCallbackObject(0);
                pMgr->ClearAllRegisteredCallbacks();
                m_bridges.RemoveKey(pMgr);
                if (pBridge != 0)
                    delete pBridge;
            }
        }
        else
        {
            AniCallbackBridge* pBridge = 0;
            if (!m_bridges.Lookup(pMgr, pBridge))
            {
                pBridge = new AniCallbackBridge(pCb);
                m_bridges[pMgr] = pBridge;
            }
            pBridge->FUN_14099b330(pCb);
            pMgr->SetCallbackObject(0);
            pMgr->ClearAllRegisteredCallbacks();
            pMgr->SetCallbackObject(pBridge);
        }
    }
}

// @0x14099bd80
void AnimationCallbackManager::FUN_14099bd80()
{
    POSITION pos = m_bridges.GetStartPosition();
    while (pos != 0)
    {
        AniCallbackBridge* pBridge = m_bridges.GetValueAt(pos);
        if (pBridge != 0)
        {
            NiActorManager::CallbackObject* pTarget = pBridge->m_pTarget;
            POSITION posEvent = pBridge->m_queue.GetHeadPosition();
            while (posEvent != 0)
            {
                Unk_BridgeEvent& kEvent = pBridge->m_queue.GetAt(posEvent);
                int eKind = kEvent.m_eKind;
                if (eKind == 0)
                    pTarget->AnimActivated(kEvent.m_pManager, kEvent.m_eSequenceID, kEvent.m_pSequence,
                                           kEvent.m_fEventTime);
                else if (eKind == 1)
                    pTarget->AnimDeactivated(kEvent.m_pManager, kEvent.m_eSequenceID, kEvent.m_pSequence,
                                             kEvent.m_fEventTime);
                else if (eKind == 2)
                    pTarget->AnimCompleted(kEvent.m_pManager, kEvent.m_eSequenceID, kEvent.m_pSequence,
                                           kEvent.m_fEventTime);
                else if (eKind == 3)
                    pTarget->TextKeyEvent(kEvent.m_pManager, kEvent.m_eSequenceID, kEvent.m_kTextKey,
                                          kEvent.m_pMatch, kEvent.m_pSequence, kEvent.m_fEventTime);
                else if (eKind == 4)
                    pTarget->EndOfSequence(kEvent.m_pManager, kEvent.m_eSequenceID, kEvent.m_pSequence,
                                           kEvent.m_fEventTime);
                pBridge->m_queue.GetNext(posEvent);
            }
            pBridge->m_queue.RemoveAll();
        }
        m_bridges.GetNext(pos);
    }
}

// @0x14099c030
void AnimationCallbackManager::FUN_14099c030()
{
    POSITION pos = m_bridges.GetStartPosition();
    while (pos != 0)
    {
        AniCallbackBridge* pBridge = m_bridges.GetValueAt(pos);
        if (pBridge != 0)
            delete pBridge;
        m_bridges.GetNext(pos);
    }
    m_bridges.RemoveAll();
}
