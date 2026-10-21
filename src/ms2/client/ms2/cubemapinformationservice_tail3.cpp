// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService container COMDAT tail, the
// `_Alloc_proxy` .. `_Get_data` slice: _Buy / _Buyheadnode / _Buynode0 / _Calculate_growth / _Change_array / _Compare /
// _Construct / _Copy_alloc / _Destroy / _Destroy_if_node / _Erase / _Extract / _Freeheadnode / _Get_data of the std/efd
// map, set and vector families of the service's member trees and local containers. Queue name unit_14112fe60. Like
// cubemapinformationservice_tail.cpp (unit_141148d70) and _tail2.cpp (unit_1410e9350) the range holds no original
// (non-COMDAT) function: it is part of the mangled-name sorted COMDAT tail of client\ms2\cubemapinformationservice.cpp
// (0x1410d5bc0-0x14115b040). The container types and drivers are shared in cubemapinformationservice_tail.h.
// MS2-UNIT: unit_14112fe60
// MS2-RANGE: 0x14112fe60-0x141142d40 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@$0A@@std@@@std@@IEBA_NAEBV?$MS2Ptr@VCFunctionCubeObject@@@@0@Z 0x141134ed0 ; manual: bytes equal, last of the _Compare run (getcomp 0x141145a20 follows the pair<int,int> one)
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBW4Unk_CMISKindA@@0@Z 0x141134d10 ; manual: less<KindA> 0x14112cb40, efd before std
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$allocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@3@$0A@@std@@@std@@IEBA_NAEBW4Unk_CMISKindA@@0@Z 0x141134d50 ; manual: less<KindA> 0x14112cb40, std after efd
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBW4Unk_CMISKindB@@0@Z 0x141134d90 ; manual: less<KindB> 0x14112cb80, E (uchar) before H
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBW4Unk_CMISKindB@@0@Z 0x141134dd0 ; manual: less<KindB> 0x14112cb80, H (int) after E
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@U?$less@_K@std@@V?$CustomAllocator@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@PEAX@2@XZ 0x141133590 ; manual: allocate 0x14114d570 is the Uid family (tail.cpp pin)
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x141135330 ; manual: COMDAT order I < _J puts the set-map pair before the owner-id pair
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@2@XZ 0x141130f90 ; manual: COMDAT order I < _J puts the set-map pair before the owner-id pair
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@_JV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x141135540 ; manual: COMDAT order I < _J puts the set-map pair before the owner-id pair
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@_JV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_JV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@PEAX@2@XZ 0x1411317d0 ; manual: COMDAT order I < _J puts the set-map pair before the owner-id pair
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Buy@?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@AEAA_N_K@Z 0x14112ffa0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@2@XZ 0x1411302d0 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@2@XZ 0x141130510 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@2@XZ 0x141130690 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@XZ 0x141130750 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@KKU?$less@K@std@@V?$CustomAllocator@U?$pair@$$CBKK@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@2@XZ 0x1411311d0 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@2@XZ 0x141131290 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@U?$less@_K@std@@V?$CustomAllocator@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@PEAX@2@XZ 0x141131710 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@HH@std@@PEAX@2@XZ 0x141131950 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@VEntityID@egf@@PEAX@2@XZ 0x141131c50 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@2@XZ 0x141131ed0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@XZ 0x141132410 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@2@XZ 0x1411324f0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@2@XZ 0x141132cd0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@2@XZ 0x141133050 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$allocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@2@XZ 0x1411332f0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@HH@std@@PEAX@2@XZ 0x141133750 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@VEntityID@egf@@PEAX@2@XZ 0x141133ad0 ; prop
// MS2-PIN: ?_Calculate_growth@?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@AEBA_K_K@Z 0x141133df0 ; prop
// MS2-PIN: ?_Change_array@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@AEAAXQEAV?$SmartPointer@VEntity@egf@@@efd@@_K1@Z 0x1411342d0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134710 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_CMISMarkRec@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134750 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134790 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1411347d0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134810 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134850 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134890 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1411348d0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134910 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134950 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134990 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@U?$less@H@2@V?$CustomAllocator@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1411349d0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$set@HU?$less@H@std@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134a10 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134a50 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134a90 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134ad0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HW4Unk_CMISKindA@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134b10 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x141134b90 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBU?$pair@HH@2@0@Z 0x141134bd0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x141134c10 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBVEntityID@egf@@0@Z 0x141134c50 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBVEntityID@egf@@0@Z 0x141134c90 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBVEntityID@egf@@0@Z 0x141134cd0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$CustomAllocator@H@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141134e10 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBU?$pair@HH@2@0@Z 0x141134e50 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IEBA_NAEBU?$pair@HH@2@0@Z 0x141134e90 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x141134fd0 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x141135000 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXXZ 0x1411350c0 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@KKU?$less@K@std@@V?$CustomAllocator@U?$pair@$$CBKK@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x1411353c0 ; prop
// MS2-PIN: ?_Copy_alloc@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@U?$less@_K@std@@V?$CustomAllocator@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@efd@@$0A@@std@@@std@@QEAAXAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@PEAX@std@@@efd@@@Z 0x141135720 ; unique
// MS2-PIN: ?_Copy_alloc@?$_Vector_alloc@U?$_Vec_base_types@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@@std@@QEAAXAEBV?$CustomAllocator@VEntityID@egf@@@efd@@@Z 0x141135990 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_CMISCell@@@std@@PEAX@2@@Z 0x141135c30 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HUUnk_CMISMarkRec@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@2@@Z 0x141135b90 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@@Z 0x141135cd0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@2@@Z 0x141135d20 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@2@@Z 0x141135d70 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@2@@Z 0x141135dc0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@PEAX@2@@Z 0x141135e10 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@2@@Z 0x141135e60 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IV?$MS2SvrPtr@VCUGCMapSetItemInfo@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2SvrPtr@VCUGCMapSetItemInfo@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2SvrPtr@VCUGCMapSetItemInfo@@@@@std@@PEAX@2@@Z 0x141135f50 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@2@@Z 0x141135fa0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@@Z 0x141136090 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@2@@Z 0x1411361d0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@@Z 0x141136270 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@@Z 0x141136400 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@PEAX@2@@Z 0x141136a50 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@@Z 0x141137630 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@@2@@Z 0x141137b30 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@2@@Z 0x1411380e0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCell@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_CMISCell@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCell@@@std@@@std@@@std@@@2@@Z 0x141138690 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@2@@Z 0x141138c40 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@std@@@std@@@2@@Z 0x1411391f0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@2@@Z 0x1411397a0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@2@@Z 0x141139d50 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@@Z 0x14113a300 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@std@@@std@@@2@@Z 0x14113a8b0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@2@@Z 0x14113ae60 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@std@@@std@@@2@@Z 0x14113b410 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@std@@@std@@@2@@Z 0x14113b9c0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@2@@Z 0x14113bf70 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@2@@Z 0x14113c520 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@std@@@std@@@2@@Z 0x14113cad0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@2@@Z 0x14113d080 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@2@@Z 0x14113d630 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@@Z 0x14113dbe0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@2@@Z 0x14113e190 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@@2@@Z 0x14113e740 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@@Z 0x14113ecf0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@@2@@Z 0x14113f2a0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@std@@@std@@@2@@Z 0x14113fe00 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@HH@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@@2@@Z 0x1411403b0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@std@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@std@@@2@@Z 0x141140960 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@@std@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VCFunctionCubeObject@@@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@@std@@@2@@Z 0x141140f10 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@PEAX@2@@Z 0x1411416f0 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@@Z 0x141141960 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@2@@Z 0x1411419c0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@PEAX@2@@Z 0x141141de0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@2@@Z 0x141142080 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@U?$less@_K@std@@V?$CustomAllocator@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@PEAX@2@@Z 0x141142170 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@2@XZ 0x1411423b0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@2@XZ 0x141142500 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@2@XZ 0x141142530 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@2@XZ 0x141142590 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@2@XZ 0x1411425f0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@2@XZ 0x1411426b0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@std@@@2@XZ 0x141142890 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@XZ 0x141142a70 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@std@@@2@XZ 0x141142d10 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ?_Change_array@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@AEAAXQEAV?$SmartPointer@VEntity@egf@@@efd@@_K1@Z 0x1411341c0 ; cf7
// MS2-PIN: ?_Change_array@?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@AEAAXQEAVEntityID@egf@@_K1@Z 0x1411343e0 ; cf7
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include "hook/ms2hook.h"
#include <NiTransform.h>
#include "ms2/commonfiles/ugcmapsetiteminfo.h"

typedef std::map<unsigned int, MS2SvrPtr<CUGCMapSetItemInfo> > Unk_CMISMapSetItem;
typedef efd::vector<NiTransform> Unk_CMISXformVec2;
typedef efd::vector<Cube*> Unk_CMISCubePtrVec;
// actionkeyobject.cpp's owner-id table: the CU constructs one first (_Construct/_Buyheadnode sit in this slice, the rest
// of the family in actionkeyobject's range)
typedef std::map<__int64, Unk_PayloadPtr<CubeOwner> > Unk_CMISOwnerById;

// operator[] with a temporary key: the exe's try_emplace(key_type&&) copies
template <class M> void Unk_CMISDriveIndexRv3(M& m)
{
    M tmp;
    tmp[typename M::key_type()];
    (void)m;
}
// the map ops without the const-key operator[] (the exe only indexes these with a temporary)
template <class M> void Unk_CMISDriveMapRv3(M& m, const typename M::key_type& k)
{
    Unk_CMISDriveIndexRv3(m);
    Unk_CMISDriveMapOps(m, k);
}

// The f58 prop map's operator[] default-constructs its value through Unk_InteractPropPtr(int) (0x140ae1340), which the
// shared Unk_CMISPropPtr stand-in does not declare, so only the two node helpers of this slice are instantiated directly.
typedef std::_Tmap_traits<egf::EntityID, Unk_CMISPropPtr, std::less<egf::EntityID>,
                          efd::CustomAllocator<std::pair<const egf::EntityID, Unk_CMISPropPtr> >, false> Unk_CMISPropTraits;
template std::_Tree_comp_alloc<Unk_CMISPropTraits>::_Nodeptr std::_Tree_comp_alloc<Unk_CMISPropTraits>::_Buynode0();
template void std::_Tree<Unk_CMISPropTraits>::_Destroy_if_node(_Nodeptr);

void Unk_CMISDriveTail3()
{
    int nKey = 0;
    unsigned int uKey = 0;
    unsigned __int64 ullKey = 0;
    egf::EntityID id;
    { Unk_CMISMapIntUInt m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapMark m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapNear m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCell m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapEntity m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapDoll m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapSales m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapSetEffect m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapHead m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapBuckets m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapCubeGroups m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISStdMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapColumns m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntVec m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntityId m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapCubeTimer m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapKind m; Unk_CMISDriveMapRv3(m, nKey); }
    { Unk_CMISMapUIntInt m; Unk_CMISDriveMapRv3(m, uKey); }
    { Unk_CMISMapSetItem m; Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapDword m; unsigned long dwKey = uKey, dwVal; (void)m.find(dwKey, dwVal); (void)m.end(); (void)m.lower_bound(dwKey); }
    { Unk_CMISMapUid m; Unk_CMISDriveMapOps(m, ullKey); (void)m.equal_range(ullKey); m.erase(ullKey); }
    { Unk_CMISMapBucket m; Unk_CMISDriveMap(m, uKey); }
    { Unk_CMISMapSaleState m; std::pair<int, int> k(0, 0); Unk_CMISDriveMapRv3(m, k); (void)m.equal_range(k); m.erase(k); }
    { Unk_CMISMapName m; Unk_CMISDriveMapKey(m, CStringA()); }
    { Unk_CMISMapEntityVal m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapProp m; Unk_CMISDriveMapOps(m, id); }                                           // no operator[]: Unk_CMISPropPtr has no default ctor in the exe
    { Unk_CMISMapEntityCube m; Unk_CMISDriveMap(m, id); }
    { Unk_CMISMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISStdMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISMapKindInt m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapKindByte m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapIntInt m; Unk_CMISDriveMapOps(m, nKey); }
    { Unk_CubeOwners m; }                                                                       // ugcmapdata's owner table
    { Unk_CMISIntSet s; Unk_CMISDriveSet(s, nKey); { int n = nKey; s.insert(std::move(n)); } (void)s.equal_range(nKey); s.erase(nKey); (void)s.key_comp(); }
    { Unk_CMISPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISAutoSet s; MS2Ptr<AutomaticCreateCubeInfo> p; Unk_CMISDriveSet(s, p); }
    { Unk_CMISFuncCubeSet s; MS2Ptr<CFunctionCubeObject> p; Unk_CMISDriveSet(s, p); }
    { Unk_CMISEntityIdSet s; Unk_CMISDriveSet(s, id); }
    { Unk_CMISIntVec v; Unk_CMISDriveVector(v, nKey); }
    { std::vector<Cube*> v; Unk_CMISDriveVector(v, static_cast<Cube*>(0)); }                      // cf7: exe 0x1411340b0 family
    { Unk_CMISEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); Unk_CMISEntVec w; v = w; }     // 0x1411341c0 family
    { Unk_CMISStdEntVec v; v.push_back(egf::EntityPtr()); v.push_back(egf::EntityPtr()); }       // 0x1411342d0 family (std::allocator)
    { Unk_CMISEntityIdVec v; Unk_CMISDriveVector(v, id); Unk_CMISEntityIdVec w; v = w; }        // 0x1411343e0 family
    { Unk_CMISElem52Vec v; Unk_CMISDriveVector(v, Unk_CMISElem52()); }
    { Unk_CMISKindVec v; Unk_CMISDriveVector(v, Unk_CMISKindC_None); }
    { Unk_CMISStdIntSet s; { int n = nKey; s.insert(std::move(n)); } }
    { Unk_CMISPairSet s; s.insert(std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; s.insert(std::pair<int, int>(0, 0)); }
    { std::vector<int> v; v.push_back(nKey); { int n = nKey; v.push_back(std::move(n)); } }
    { Unk_CMISMapBucket a, b; a = b; }
    { Unk_CMISXformVec2 v; NiTransform x; v.push_back(x); v.push_back(NiTransform()); }
    // copy assignments (the exe's _Copy_alloc / _Buynode0 of these families)
    { Unk_CMISMapUid a, b; a = b; }
    { Unk_CMISIntSet a, b; a = b; }
    { Unk_CMISStdIntSet a, b; a = b; }
    { Unk_CMISFuncCubeSet a, b; a = b; }
    { Unk_CMISOwnerById m; }
    { MS2Ptr<UIHouseMarkEntity> p; }
    { efd::utf8string s; (void)s.find_last_of("/", 0); }
    { std::string s; s.append("x"); }
}
// fx25: two merge-induced stubs (look-alike copies the merge pairs elsewhere); the table rows already name these VAs
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@XZ 0x141132bf0
// MS2-PIN: ?_Copy_alloc@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXAEBV?$allocator@U?$_Tree_node@HPEAX@std@@@2@@Z 0x141135840
