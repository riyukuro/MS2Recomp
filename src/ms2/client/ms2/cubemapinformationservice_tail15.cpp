// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService COMDAT tail slice 0x1411234d0-
// 0x141126010 (queue unit_1411234d0): the destructor half of the service's container glue, the counterpart of the
// constructor slice unit_141121cf0. For each member tree family the efd::map / efd::set wrapper dtor, the std::map /
// std::set dtor, ~_Tree (_Tidy + base), ~_Tree_comp_alloc (_Freeheadnode + _Compressed_pair), both _Compressed_pair
// dtors and the node allocator dtor; the same chain for the efd::vector members; the pair<const K, V> node value dtors;
// _Uninitialized_backout_al dtors of the vector growth code; the record dtors (AutomaticCreateCubeInfo, SaleStateData,
// SalesInfo, the mark / cell records), the service's message handler dtors and ~TSingleton<CubeMapInformationService>.
// Same driver family as cubemapinformationservice_tail9.cpp; the container types are shared in
// cubemapinformationservice_tail.h. Not an original file.
// MS2-UNIT: unit_1411234d0
// MS2-RANGE: 0x1411234d0-0x141126010 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$CustomAllocator@H@efd@@QEAA@XZ 0x1411234d0 ; unique
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@HPEAX@std@@@efd@@QEAA@XZ 0x1411234e0 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123510 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCell@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123520 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123530 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123540 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123550 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123560 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123570 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123580 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123590 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x1411235a0 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x1411235d0 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@QEAA@XZ 0x1411235e0 ; prop
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x1411235f0 ; unique
// MS2-PIN: ??1?$MessageHandlerImpl@VCubeMapInformationService@@VEntityChangeMessage@egf@@@efd@@UEAA@XZ 0x1411236c0 ; prop
// MS2-PIN: ??1?$MessageHandlerImpl@VCubeMapInformationService@@VSceneGraphAddedMessage@ecr@@@efd@@UEAA@XZ 0x1411236e0 ; prop
// MS2-PIN: ??1?$MessageSubclassHandler@VCubeMapInformationService@@VEntityChangeMessage@egf@@V23@@efd@@UEAA@XZ 0x141123700 ; prop
// MS2-PIN: ??1?$MessageWrapper@VEntityChangeMessage@egf@@$0CADN@@efd@@UEAA@XZ 0x141123720 ; prop
// MS2-PIN: ??1?$MessageWrapperSubclassHandler@VCubeMapInformationService@@VEntityChangeMessage@egf@@V23@$0CADN@@efd@@UEAA@XZ 0x141123740 ; prop
// MS2-PIN: ??1?$MS2Ptr@VFittingDollData@@@@QEAA@XZ 0x141123790 ; prop
// MS2-PIN: ??1?$Unk_PayloadPtr@VNoticeCubeInfo@@@@QEAA@XZ 0x141123820 ; prop
// MS2-PIN: ??1?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123930 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@HPEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@$00@std@@QEAA@XZ 0x141123c70 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123cb0 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123cd0 ; prop
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123d10 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123d50 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123d70 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123d90 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123dd0 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123df0 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e10 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e30 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e50 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e70 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e90 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124050 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124080 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_CMISMarkRec@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411240b0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1411240e0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124110 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124140 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124170 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1411241a0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411241d0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124200 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x141124230 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$map@HV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124260 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124290 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@U?$less@H@2@V?$CustomAllocator@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411242c0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@KKU?$less@K@std@@V?$CustomAllocator@U?$pair@$$CBKK@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411242f0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HW4Unk_CMISKindA@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411243b0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411243e0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124410 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124440 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124470 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411244a0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411244d0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124500 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124530 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$allocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x141124560 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124590 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411245c0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1411245f0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$CustomAllocator@H@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124650 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124680 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1411246b0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@U?$less@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@V?$CustomAllocator@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411246e0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@$0A@@std@@@std@@QEAA@XZ 0x141124710 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124740 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@KKU?$less@K@std@@V?$CustomAllocator@U?$pair@$$CBKK@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124aa0 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124cd0 ; prop
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEAA@XZ 0x141125090 ; prop
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@QEAA@XZ 0x141125110 ; prop
// MS2-PIN: ??1?$map@HHU?$less@H@std@@@efd@@QEAA@XZ 0x141125210 ; prop
// MS2-PIN: ??1?$map@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@@std@@QEAA@XZ 0x141125230 ; prop
// MS2-PIN: ??1?$map@HIU?$less@H@std@@@efd@@QEAA@XZ 0x141125250 ; prop
// MS2-PIN: ??1?$map@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@@std@@QEAA@XZ 0x141125270 ; prop
// MS2-PIN: ??1?$map@HUUnk_CMISMarkRec@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125290 ; prop
// MS2-PIN: ??1?$map@HUUnk_CMISMarkRec@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@efd@@@std@@QEAA@XZ 0x1411252b0 ; prop
// MS2-PIN: ??1?$map@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@@std@@QEAA@XZ 0x1411252d0 ; prop
// MS2-PIN: ??1?$map@HUUnk_CMISCell@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411252f0 ; prop
// MS2-PIN: ??1?$map@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@@std@@QEAA@XZ 0x141125310 ; prop
// MS2-PIN: ??1?$map@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125330 ; prop
// MS2-PIN: ??1?$map@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@2@@std@@QEAA@XZ 0x141125350 ; prop
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125370 ; prop
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@@std@@QEAA@XZ 0x141125390 ; prop
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@@std@@QEAA@XZ 0x1411253b0 ; prop
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411253d0 ; prop
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@@std@@QEAA@XZ 0x1411253f0 ; prop
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125410 ; prop
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@@std@@QEAA@XZ 0x141125430 ; prop
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@@std@@QEAA@XZ 0x141125450 ; prop
// MS2-PIN: ??1?$map@HV?$map@HV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@@std@@@2@@std@@QEAA@XZ 0x141125470 ; prop
// MS2-PIN: ??1?$map@HV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@2@@std@@QEAA@XZ 0x141125490 ; prop
// MS2-PIN: ??1?$map@HV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@U?$less@H@2@@efd@@QEAA@XZ 0x1411254b0 ; prop
// MS2-PIN: ??1?$map@HV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@U?$less@H@2@V?$CustomAllocator@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@efd@@@std@@QEAA@XZ 0x1411254d0 ; prop
// MS2-PIN: ??1?$map@KKU?$less@K@std@@@efd@@QEAA@XZ 0x1411254f0 ; prop
// MS2-PIN: ??1?$map@KKU?$less@K@std@@V?$CustomAllocator@U?$pair@$$CBKK@std@@@efd@@@std@@QEAA@XZ 0x141125510 ; prop
// MS2-PIN: ??1?$map@HW4Unk_CMISKindA@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411255f0 ; prop
// MS2-PIN: ??1?$map@HW4Unk_CMISKindA@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@efd@@@std@@QEAA@XZ 0x141125610 ; prop
// MS2-PIN: ??1?$map@IHU?$less@I@std@@@efd@@QEAA@XZ 0x141125630 ; prop
// MS2-PIN: ??1?$map@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@@std@@QEAA@XZ 0x141125650 ; prop
// MS2-PIN: ??1?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@QEAA@XZ 0x141125670 ; prop
// MS2-PIN: ??1?$map@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@@efd@@QEAA@XZ 0x141125690 ; prop
// MS2-PIN: ??1?$map@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@@std@@QEAA@XZ 0x1411256b0 ; prop
// MS2-PIN: ??1?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@efd@@QEAA@XZ 0x1411256d0 ; prop
// MS2-PIN: ??1?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@@std@@QEAA@XZ 0x1411256f0 ; prop
// MS2-PIN: ??1?$map@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@@efd@@QEAA@XZ 0x141125710 ; prop
// MS2-PIN: ??1?$map@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@@std@@QEAA@XZ 0x141125730 ; prop
// MS2-PIN: ??1?$map@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@@efd@@QEAA@XZ 0x141125750 ; prop
// MS2-PIN: ??1?$map@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@@std@@QEAA@XZ 0x141125770 ; prop
// MS2-PIN: ??1?$map@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@@efd@@QEAA@XZ 0x141125790 ; prop
// MS2-PIN: ??1?$map@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@@std@@QEAA@XZ 0x1411257b0 ; prop
// MS2-PIN: ??1?$map@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@@efd@@QEAA@XZ 0x1411257d0 ; prop
// MS2-PIN: ??1?$map@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@efd@@@std@@QEAA@XZ 0x1411257f0 ; prop
// MS2-PIN: ??1?$map@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$allocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@3@@std@@QEAA@XZ 0x141125810 ; prop
// MS2-PIN: ??1?$map@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@@efd@@QEAA@XZ 0x141125830 ; prop
// MS2-PIN: ??1?$map@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@efd@@@std@@QEAA@XZ 0x141125850 ; prop
// MS2-PIN: ??1?$map@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@@efd@@QEAA@XZ 0x141125870 ; prop
// MS2-PIN: ??1?$map@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@@std@@QEAA@XZ 0x141125890 ; prop
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@QEAA@XZ 0x1411258d0 ; prop
// MS2-PIN: ??1?$pair@$$CBHUUnk_CMISMarkRec@@@std@@QEAA@XZ 0x141125910 ; prop
// MS2-PIN: ??1?$pair@$$CBHUUnk_CMISCell@@@std@@QEAA@XZ 0x141125930 ; prop
// MS2-PIN: ??1?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@QEAA@XZ 0x141125950 ; prop
// MS2-PIN: ??1?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@QEAA@XZ 0x1411259b0 ; prop
// MS2-PIN: ??1?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@QEAA@XZ 0x1411259f0 ; prop
// MS2-PIN: ??1?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@QEAA@XZ 0x141125a90 ; prop
// MS2-PIN: ??1?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@XZ 0x141125af0 ; unique
// MS2-PIN: ??1?$set@HU?$less@H@std@@@efd@@QEAA@XZ 0x141125b70 ; prop
// MS2-PIN: ??1?$set@HU?$less@H@std@@V?$CustomAllocator@H@efd@@@std@@QEAA@XZ 0x141125b90 ; prop
// MS2-PIN: ??1?$set@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@@efd@@QEAA@XZ 0x141125bb0 ; prop
// MS2-PIN: ??1?$set@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@@std@@QEAA@XZ 0x141125bd0 ; prop
// MS2-PIN: ??1?$set@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAA@XZ 0x141125bf0 ; prop
// MS2-PIN: ??1?$set@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@U?$less@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@efd@@QEAA@XZ 0x141125c10 ; prop
// MS2-PIN: ??1?$set@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@U?$less@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@V?$CustomAllocator@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@efd@@@std@@QEAA@XZ 0x141125c30 ; prop
// MS2-PIN: ??1?$set@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@@std@@QEAA@XZ 0x141125c50 ; prop
// MS2-PIN: ??1?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@@efd@@QEAA@XZ 0x141125c70 ; prop
// MS2-PIN: ??1?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@QEAA@XZ 0x141125c90 ; prop
// MS2-PIN: ??1?$vector@H@efd@@QEAA@XZ 0x141125cb0 ; prop
// MS2-PINS-END tplpin
// tplpin --simulate (w560) after the value types were corrected, hand-applied; these override the block above
// MS2-PIN: ??1?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x1411239f0
// MS2-PIN: ??1?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123a50
// MS2-PIN: ??1?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123a90
// MS2-PIN: ??1?$_Compressed_pair@U?$less@K@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKK@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123ab0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123d70
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123d90
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123db0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123df0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e30
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKK@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e50
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123f30
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123f50
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$map@_JV?$MS2Ptr@VCube@@@@U?$less@_J@std@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$map@_JV?$MS2Ptr@VCube@@@@U?$less@_J@std@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1411242c0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$vector@VEntityID@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@VEntityID@egf@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124320
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@VEntityID@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@VEntityID@egf@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124ae0
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@_JV?$MS2Ptr@VCube@@@@U?$less@_J@std@@V?$CustomAllocator@U?$pair@$$CB_JV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124e80
// MS2-PIN: ??1?$map@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@@std@@QEAA@XZ 0x141125230
// MS2-PIN: ??1?$map@HIU?$less@H@std@@@efd@@QEAA@XZ 0x141125250
// MS2-PIN: ??1?$map@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@@std@@QEAA@XZ 0x141125270
// MS2-PIN: ??1?$map@HUUnk_CMISMarkRec@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125290
// MS2-PIN: ??1?$map@HUUnk_CMISMarkRec@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@efd@@@std@@QEAA@XZ 0x1411252b0
// MS2-PIN: ??1?$map@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@@std@@QEAA@XZ 0x1411252d0
// MS2-PIN: ??1?$map@HUUnk_CMISCell@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411252f0
// MS2-PIN: ??1?$map@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@@std@@QEAA@XZ 0x141125310
// MS2-PIN: ??1?$map@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125330
// MS2-PIN: ??1?$map@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@2@@std@@QEAA@XZ 0x141125350
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125370
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@@std@@QEAA@XZ 0x141125390
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@@std@@QEAA@XZ 0x1411253b0
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411253d0
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@@std@@QEAA@XZ 0x1411253f0
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125410
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@@std@@QEAA@XZ 0x141125430
// MS2-PIN: ??1?$map@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@@std@@QEAA@XZ 0x141125450
// MS2-PIN: ??1?$map@HV?$map@HV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@@std@@@2@@std@@QEAA@XZ 0x141125470
// MS2-PIN: ??1?$map@HV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@2@@std@@QEAA@XZ 0x141125490
// MS2-PIN: ??1?$map@HV?$map@_JV?$MS2Ptr@VCube@@@@U?$less@_J@std@@@efd@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411254b0
// MS2-PIN: ??1?$map@HV?$set@HU?$less@H@std@@@efd@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411254f0
// MS2-PIN: ??1?$map@HV?$set@HU?$less@H@std@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@2@@std@@QEAA@XZ 0x141125510
// MS2-PIN: ??1?$map@HV?$vector@VEntityID@egf@@@efd@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125530
// MS2-PIN: ??1?$map@HV?$vector@VEntityID@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@VEntityID@egf@@@efd@@@std@@@2@@std@@QEAA@XZ 0x141125550
// MS2-PIN: ??1?$map@HVEntityID@egf@@U?$less@H@std@@@efd@@QEAA@XZ 0x141125570
// MS2-PIN: ??1?$map@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@@std@@QEAA@XZ 0x141125590
// MS2-PIN: ??1?$map@HUUnk_CMISCubeTimer@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411255b0
// MS2-PIN: ??1?$map@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@@std@@QEAA@XZ 0x1411255d0
// MS2-PIN: ??1?$map@HW4Unk_CMISKindA@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411255f0
// MS2-PIN: ??1?$map@HW4Unk_CMISKindA@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@efd@@@std@@QEAA@XZ 0x141125610
// MS2-PIN: ??1?$map@IHU?$less@I@std@@@efd@@QEAA@XZ 0x141125630
// MS2-PIN: ??1?$map@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@@std@@QEAA@XZ 0x141125650
// MS2-PIN: ??1?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@QEAA@XZ 0x141125670
// MS2-PIN: ??1?$map@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@@efd@@QEAA@XZ 0x141125690
// MS2-PIN: ??1?$map@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@@std@@QEAA@XZ 0x1411256b0
// MS2-PIN: ??1?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@efd@@QEAA@XZ 0x1411256d0
// MS2-PIN: ??1?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@@std@@QEAA@XZ 0x1411256f0
// MS2-PIN: ??1?$map@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@@efd@@QEAA@XZ 0x141125710
// MS2-PIN: ??1?$map@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@@std@@QEAA@XZ 0x141125730
// MS2-PIN: ??1?$map@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@@efd@@QEAA@XZ 0x141125750
// MS2-PIN: ??1?$map@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@@std@@QEAA@XZ 0x141125770
// MS2-PIN: ??1?$map@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@@efd@@QEAA@XZ 0x141125790
// MS2-PIN: ??1?$map@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@@std@@QEAA@XZ 0x1411257b0
// MS2-PIN: ??1?$map@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@@efd@@QEAA@XZ 0x1411257d0
// MS2-PIN: ??1?$map@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@efd@@@std@@QEAA@XZ 0x1411257f0
// MS2-PIN: ??1?$map@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$allocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@3@@std@@QEAA@XZ 0x141125810
// MS2-PIN: ??1?$map@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@@efd@@QEAA@XZ 0x141125830
// MS2-PIN: ??1?$map@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@efd@@@std@@QEAA@XZ 0x141125850
// MS2-PIN: ??1?$map@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@@efd@@QEAA@XZ 0x141125870
// MS2-PIN: ??1?$map@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@@std@@QEAA@XZ 0x141125890
// MS2-PIN: ??1?$map@KKU?$less@K@std@@V?$CustomAllocator@U?$pair@$$CBKK@std@@@efd@@@std@@QEAA@XZ 0x1411258d0
// MS2-PIN: ??1?$map@_JV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@QEAA@XZ 0x1411258f0
// MS2-PIN: ??1?$set@HU?$less@H@std@@@efd@@QEAA@XZ 0x141125b70
// MS2-PIN: ??1?$set@HU?$less@H@std@@V?$CustomAllocator@H@efd@@@std@@QEAA@XZ 0x141125b90
// MS2-PIN: ??1?$set@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@@efd@@QEAA@XZ 0x141125bb0
// MS2-PIN: ??1?$set@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@@std@@QEAA@XZ 0x141125bd0
// MS2-PIN: ??1?$set@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAA@XZ 0x141125bf0
// MS2-PIN: ??1?$set@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@U?$less@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@efd@@QEAA@XZ 0x141125c10
// MS2-PIN: ??1?$set@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@U?$less@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@V?$CustomAllocator@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@efd@@@std@@QEAA@XZ 0x141125c30
// MS2-PIN: ??1?$set@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@@std@@QEAA@XZ 0x141125c50
// MS2-PIN: ??1?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@@efd@@QEAA@XZ 0x141125c70
// MS2-PIN: ??1?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@QEAA@XZ 0x141125c90
// MS2-PIN: ??1?$MessageWrapper@VEntityChangeMessage@egf@@$0CADN@@efd@@UEAA@XZ 0x141123720
// MS2-PIN: ??1?$MS2Ptr@VFittingDollData@@@@QEAA@XZ 0x141123790
// MS2-PIN: ??1?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@VEntityID@egf@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@VEntityID@egf@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123a30
// MS2-PIN: ??1?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123a70
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124050
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124080
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_CMISMarkRec@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411240b0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1411240e0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124110
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124140
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124170
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1411241a0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411241d0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124200
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x141124230
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$map@HV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124260
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124290
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$set@HU?$less@H@std@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1411242f0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124350
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124380
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HW4Unk_CMISKindA@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411243b0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411243e0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124410
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124440
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124470
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411244a0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411244d0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124500
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124530
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$allocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x141124560
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124590
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411245c0
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@_JV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x141124620
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$CustomAllocator@H@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124650
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124680
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1411246b0
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@U?$less@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@V?$CustomAllocator@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411246e0
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@$0A@@std@@@std@@QEAA@XZ 0x141124710
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124740
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1411248a0
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124e00
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124e40
// MS2-PIN: ??1?$pair@$$CBHUUnk_CMISMarkRec@@@std@@QEAA@XZ 0x141125910
// MS2-PIN: ??1?$pair@$$CBHUUnk_CMISCell@@@std@@QEAA@XZ 0x141125930
// MS2-PIN: ??1?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@QEAA@XZ 0x141125950
// MS2-PIN: ??1?$pair@$$CBHV?$vector@VEntityID@egf@@@efd@@@std@@QEAA@XZ 0x141125a70
// MS2-PIN: ??1?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@QEAA@XZ 0x141125a90
// MS2-PIN: ??1?$vector@H@efd@@QEAA@XZ 0x141125cb0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@HPEAX@std@@@efd@@QEAA@XZ 0x1411234e0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123510
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCell@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123520
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123530
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123540
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123550
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123570
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123590
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x1411235b0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@std@@@efd@@QEAA@XZ 0x1411235c0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x1411235d0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@QEAA@XZ 0x1411235e0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123630
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123640
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@@efd@@QEAA@XZ 0x141123650
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123660
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123670
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@efd@@QEAA@XZ 0x141123680
// MS2-PIN: ??1?$MessageHandlerImpl@VCubeMapInformationService@@VSceneGraphAddedMessage@ecr@@@efd@@UEAA@XZ 0x1411236e0
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEAA@XZ 0x141125090
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@QEAA@XZ 0x141125110
// MS2-PIN: ??1?$CustomAllocator@H@efd@@QEAA@XZ 0x1411234d0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x1411235f0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123610
// MS2-PIN: ??1?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123930
// MS2-PIN: ??1?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x1411239d0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@HPEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@$00@std@@QEAA@XZ 0x141123c70
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123cb0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123d30
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123d50
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e70
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e90
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123f10
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123f90
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@std@@$00@std@@QEAA@XZ 0x141123fb0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@$00@std@@QEAA@XZ 0x141123fd0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123560
// MS2-PIN: ??1?$MessageSubclassHandler@VCubeMapInformationService@@VEntityChangeMessage@egf@@V23@@efd@@UEAA@XZ 0x141123700
// MS2-PIN: ??1?$MessageWrapperSubclassHandler@VCubeMapInformationService@@VEntityChangeMessage@egf@@V23@$0CADN@@efd@@UEAA@XZ 0x141123740
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123cd0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123e30
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@KKU?$less@K@std@@V?$CustomAllocator@U?$pair@$$CBKK@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1411242f0
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@KKU?$less@K@std@@V?$CustomAllocator@U?$pair@$$CBKK@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124aa0
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124cd0
// MS2-PIN: ??1?$map@HHU?$less@H@std@@@efd@@QEAA@XZ 0x141125210
// MS2-PIN: ??1?$map@KKU?$less@K@std@@@efd@@QEAA@XZ 0x1411254f0
// MS2-PIN: ??1?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123970
// MS2-PIN: ??1?$_Compressed_pair@U?$less@W4Unk_CMISKindB@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123bf0
// MS2-PIN: ??1?$_Compressed_pair@U?$less@W4Unk_CMISKindB@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123c10
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124860
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@_JV?$MS2Ptr@VCube@@@@U?$less@_J@std@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$map@_JV?$MS2Ptr@VCube@@@@U?$less@_J@std@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124a60
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$set@HU?$less@H@std@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141124aa0
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124b20
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124b60
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124be0
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@_JV?$MS2Ptr@VCube@@@@U?$less@_J@std@@@efd@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123500
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141123620
// MS2-PIN: ??1?$MessageHandlerImpl@VCubeMapInformationService@@VEntityChangeMessage@egf@@@efd@@UEAA@XZ 0x1411236c0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@_JV?$MS2Ptr@VCube@@@@U?$less@_J@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@_JV?$MS2Ptr@VCube@@@@U?$less@_J@std@@@efd@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123cd0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123f70
// MS2-PIN: ??1?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@XZ 0x141125af0
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include <NiTransform.h>
#include "ms2/client/ms2/interactobject.h"
#include <efd/IMessage.h>
#include <efd/MessageHandlerBase.h>
#include <egf/EntityChangeMessage.h>
#include <ecr/CoreRuntimeMessages.h>

class NoticeCubeInfo;

// ---- record classes --------------------------------------------------------------------------------------------------
// The record dtors (AutomaticCreateCubeInfo 0x141125e20, SaleStateData 0x141125fc0, SalesInfo 0x141125fe0) store no
// vptr: they are the implicit ones (= default in cubemapinformationservice_tail.h), pinned at the end of the file.

// the building notification of the service (unit_141121cf0 builds it)
class Unk_CMISNotifyBuilding : public NotifyObject
{
public:
    Unk_CMISNotifyBuilding(const int* pnBuilding) : m_nBuilding(*pnBuilding) {}
    virtual ~Unk_CMISNotifyBuilding() = default;             // 0x141125fa0 (no vptr store)
    int m_nBuilding;                                         // +0x18
};

// ---- the families whose exe type is only known by shape -------------------------------------------------------------
// a record of the service holding an int -> int table as its first member (dtor 0x141125ea0 -> ~efd::map<int, int>)
struct Unk_CMISIntIntTable
{
    Unk_CMISMapIntInt m_table;
};

// The pair / tree dtor chains of the exe name these value types (the tail.h typedefs of the same members differ):
// the int -> entity id vector table (pair dtor 0x141125a70 -> ~efd::vector<EntityID> 0x141125d50), the cube groups
// keyed by a 64-bit id (efd::map 0x1411258b0 -> std::map 0x1411258d0 -> _Tree 0x1411245f0, node pair 0x141125b50) and
// the std::map<__int64, TPtr<CubeOwner>> owner table (std::map 0x1411258f0 -> _Tree 0x141124620, std allocator).
typedef efd::map<int, efd::vector<egf::EntityID> > Unk_CMISMapEntIdVec;
typedef efd::map<__int64, MS2Ptr<Cube> > Unk_CMISMapCubeById;
typedef efd::map<int, Unk_CMISMapCubeById> Unk_CMISMapCubeGroupsById;
typedef std::map<__int64, Unk_PayloadPtr<CubeOwner> > Unk_CMISOwnerById;
typedef std::map<int, Unk_PayloadPtr<CubeOwner> > Unk_CMISStdMapOwner;
// the entity -> prop object table: its node pair dtor (0x141125b10) calls ~Unk_InteractPropPtr 0x140ae16b0 directly
typedef efd::map<egf::EntityID, Unk_InteractPropPtr> Unk_CMISMapPropObj;
typedef std::map<int, Unk_CMISStdMapOwner> Unk_CMISMapOwners;
typedef efd::vector<NiTransform> Unk_CMISXformVec15;

template <class T> inline void Unk_CMISDestroy(T* p)
{
    p->~T();
}

void Unk_CMISDriveTail15(void* p)
{
    // member trees
    Unk_CMISDestroy((Unk_CMISMapIntInt*)p);
    Unk_CMISDestroy((Unk_CMISMapIntUInt*)p);
    Unk_CMISDestroy((Unk_CMISMapMark*)p);
    Unk_CMISDestroy((Unk_CMISMapNear*)p);
    Unk_CMISDestroy((Unk_CMISMapCell*)p);
    Unk_CMISDestroy((Unk_CMISMapEntity*)p);
    Unk_CMISDestroy((Unk_CMISMapDoll*)p);
    Unk_CMISDestroy((Unk_CMISMapSales*)p);
    Unk_CMISDestroy((Unk_CMISMapSetEffect*)p);
    Unk_CMISDestroy((Unk_CMISMapCube*)p);
    Unk_CMISDestroy((Unk_CMISMapHead*)p);
    Unk_CMISDestroy((Unk_CMISMapOwners*)p);
    Unk_CMISDestroy((Unk_CMISMapBuckets*)p);
    Unk_CMISDestroy((Unk_CMISMapCubeGroupsById*)p);
    Unk_CMISDestroy((Unk_CMISMapColumns*)p);
    Unk_CMISDestroy((Unk_CMISMapEntIdVec*)p);
    Unk_CMISDestroy((Unk_CMISMapEntityId*)p);
    Unk_CMISDestroy((Unk_CMISMapCubeTimer*)p);
    Unk_CMISDestroy((Unk_CMISMapKind*)p);
    Unk_CMISDestroy((Unk_CMISMapUIntInt*)p);
    Unk_CMISDestroy((Unk_CMISMapBucket*)p);
    Unk_CMISDestroy((Unk_CMISMapSaleState*)p);
    Unk_CMISDestroy((Unk_CMISMapName*)p);
    Unk_CMISDestroy((Unk_CMISMapEntityVal*)p);
    Unk_CMISDestroy((Unk_CMISMapPropObj*)p);
    Unk_CMISDestroy((Unk_CMISMapEntityCube*)p);
    Unk_CMISDestroy((Unk_CMISMapKindCount*)p);
    Unk_CMISDestroy((Unk_CMISStdMapKindCount*)p);
    Unk_CMISDestroy((Unk_CMISMapKindInt*)p);
    Unk_CMISDestroy((Unk_CMISMapKindByte*)p);
    Unk_CMISDestroy((Unk_CMISOwnerById*)p);
    Unk_CMISDestroy((Unk_CMISMapDword*)p);
    Unk_CMISDestroy((Unk_CMISIntSet*)p);
    Unk_CMISDestroy((Unk_CMISPairSet*)p);
    Unk_CMISDestroy((Unk_CMISStdPairSet*)p);
    Unk_CMISDestroy((Unk_CMISAutoSet*)p);
    Unk_CMISDestroy((Unk_CMISFuncCubeSet*)p);
    Unk_CMISDestroy((Unk_CMISEntityIdSet*)p);
    Unk_CMISDestroy((Unk_CMISIntIntTable*)p);
    // vectors
    Unk_CMISDestroy((Unk_CMISIntVec*)p);
    Unk_CMISDestroy((Unk_CMISEntVec*)p);
    Unk_CMISDestroy((Unk_CMISEntityIdVec*)p);
    Unk_CMISDestroy((Unk_CMISXformVec15*)p);
    Unk_CMISDestroy((Unk_CMISKindVec*)p);
    // the vector growth rollback guards
    Unk_CMISDestroy((std::_Uninitialized_backout_al<int*, efd::CustomAllocator<int> >*)p);
    Unk_CMISDestroy((std::_Uninitialized_backout_al<egf::EntityPtr*, efd::CustomAllocator<egf::EntityPtr> >*)p);
    Unk_CMISDestroy((std::_Uninitialized_backout_al<egf::EntityPtr*, std::allocator<egf::EntityPtr> >*)p);
    Unk_CMISDestroy((std::_Uninitialized_backout_al<egf::EntityID*, efd::CustomAllocator<egf::EntityID> >*)p);
    Unk_CMISDestroy((std::_Uninitialized_backout_al<NiTransform*, efd::CustomAllocator<NiTransform> >*)p);
    // records and smart pointers
    Unk_CMISDestroy((Unk_CMISMarkRec*)p);
    Unk_CMISDestroy((Unk_CMISCell*)p);
    Unk_CMISDestroy((MS2Ptr<AutomaticCreateCubeInfo>*)p);
    Unk_CMISDestroy((MS2Ptr<FittingDollData>*)p);
    Unk_CMISDestroy((MS2Ptr<SaleStateData>*)p);
    Unk_CMISDestroy((MS2Ptr<SalesInfo>*)p);
    Unk_CMISDestroy((MS2Ptr<UICubeUGCHead>*)p);
    Unk_CMISDestroy((MS2Ptr<UIHouseMarkEntity>*)p);
    Unk_CMISDestroy((Unk_PayloadPtr<NoticeCubeInfo>*)p);
    ((AutomaticCreateCubeInfo*)p)->AutomaticCreateCubeInfo::~AutomaticCreateCubeInfo();
    ((SaleStateData*)p)->SaleStateData::~SaleStateData();
    ((SalesInfo*)p)->SalesInfo::~SalesInfo();
    ((Unk_CMISNotifyBuilding*)p)->Unk_CMISNotifyBuilding::~Unk_CMISNotifyBuilding();
    ((TSingleton<CubeMapInformationService>*)p)->TSingleton<CubeMapInformationService>::~TSingleton();
    // message handlers and messages
    typedef efd::MessageHandlerImpl<CubeMapInformationService, egf::EntityChangeMessage> HEntity;
    typedef efd::MessageHandlerImpl<CubeMapInformationService, ecr::SceneGraphAddedMessage> HSceneAdded;
    typedef efd::MessageSubclassHandler<CubeMapInformationService, egf::EntityChangeMessage, egf::EntityChangeMessage> HSub;
    typedef efd::MessageWrapper<egf::EntityChangeMessage, 8253> WEntity;
    typedef efd::MessageWrapperSubclassHandler<CubeMapInformationService, egf::EntityChangeMessage,
                                               egf::EntityChangeMessage, 8253> HWrapSub;
    ((HEntity*)p)->HEntity::~HEntity();
    ((HSceneAdded*)p)->HSceneAdded::~HSceneAdded();
    ((HSub*)p)->HSub::~HSub();
    ((WEntity*)p)->WEntity::~WEntity();
    ((HWrapSub*)p)->HWrapSub::~HWrapSub();
    ((egf::EntityChangeMessage*)p)->egf::EntityChangeMessage::~EntityChangeMessage();
    ((efd::ISystemService*)p)->efd::ISystemService::~ISystemService();
}

// second tplpin --simulate pass (w560) after the prop table / int table types were corrected
// MS2-PIN: ??1?$MS2Ptr@VAutomaticCreateCubeInfo@@@@QEAA@XZ 0x141123760
// MS2-PIN: ??1?$_Compressed_pair@U?$less@VEntityID@egf@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_InteractPropPtr@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_InteractPropPtr@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141123b70
// MS2-PIN: ??1?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@QEAA@XZ 0x141125990
// MS2-PIN: ??1?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@QEAA@XZ 0x1411259b0
// MS2-PIN: ??1?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@QEAA@XZ 0x1411259f0
// MS2-PIN: ??1?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@QEAA@XZ 0x141125a10
// MS2-PIN: ??1?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@QEAA@XZ 0x141125a50
// MS2-PIN: ??1Unk_CMISIntIntTable@@QEAA@XZ 0x141125ea0
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCell@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCell@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141123cf0
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HW4Unk_CMISKindA@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124ba0
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141124d50

// The exe's COMDAT tail is in mangled-name order (SmartPointer before EntityID): the efd::vector<SmartPointer<Entity>>
// chain (also the vector of the mark record, ~0x141125e70) comes first, the efd::vector<EntityID> chain second.
// MS2-PIN: ??1?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@QEAA@XZ 0x141125d00
// MS2-PIN: ??1?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEAA@XZ 0x141125d20
// MS2-PIN: ??1?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@@std@@QEAA@XZ 0x1411251b0
// MS2-PIN: ??1?$vector@VEntityID@egf@@@efd@@QEAA@XZ 0x141125d50
// MS2-PIN: ??1?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@QEAA@XZ 0x141125d70
// MS2-PIN: ??1?$_Vector_alloc@U?$_Vec_base_types@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@@std@@QEAA@XZ 0x1411251d0
// MS2-PIN: ??1AutomaticCreateCubeInfo@@UEAA@XZ 0x141125e20
// MS2-PIN: ??1Unk_CMISNotifyBuilding@@UEAA@XZ 0x141125fa0
// MS2-PIN: ??1SaleStateData@@UEAA@XZ 0x141125fc0
// MS2-PIN: ??1SalesInfo@@UEAA@XZ 0x141125fe0
