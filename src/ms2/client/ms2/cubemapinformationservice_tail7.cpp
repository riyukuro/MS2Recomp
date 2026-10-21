// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService COMDAT tail slice 0x14111d430-
// 0x14111e450 (queue unit_14111d430): the public map::try_emplace / operator[] wrappers of the service's member trees,
// swap/make_pair/sort helpers and the CAtlArray<void*> ctors. Same driver family as cubemapinformationservice_tail2.cpp;
// the container types are shared in cubemapinformationservice_tail.h. Not an original file.
// MS2-UNIT: unit_14111d430
// MS2-RANGE: 0x14111d430-0x14111e450 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$next@PEAVNiTransform@@@std@@YAPEAVNiTransform@@PEAV1@_J@Z 0x14111d580 ; order
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d6a0 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d6e0 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d720 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d7a0 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCell@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d7e0 ; probe
// MS2-PIN: ??$try_emplace@$$V@?$map@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d860 ; probe
// MS2-PIN: ??$try_emplace@$$V@?$map@HUUnk_CMISMarkRec@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d8a0 ; probe
// MS2-PIN: ??$try_emplace@$$V@?$map@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d8e0 ; probe
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d920 ; probe
// MS2-PIN: ??$try_emplace@$$V@?$map@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@std@@_N@1@AEBU?$pair@HH@1@@Z 0x14111d960 ; probe
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111d9a0 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N@1@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x14111dd20 ; fx28 callee 1411148d0 CString key
// MS2-PIN: ??$try_emplace@$$V@?$map@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@_N@1@AEBVEntityID@egf@@@Z 0x14111dde0 ; fx28 callee 141114cc0 EntityID key (Buynode0 141133130)
// MS2-PIN: ??$try_emplace@$$V@?$map@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@@std@@_N@1@AEBVEntityID@egf@@@Z 0x14111dda0 ; fx28 callee 141114b70 EntityID key
// MS2-PIN: ??$try_emplace@$$V@?$map@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@std@@_N@1@AEBVEntityID@egf@@@Z 0x14111dd60 ; fx28 callee 141114a20 EntityID key
// MS2-PIN: ??$try_emplace@$$V@?$map@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@@std@@_N@1@AEBW4Unk_CMISKindA@@@Z 0x14111de20 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$allocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@@std@@_N@1@AEBW4Unk_CMISKindA@@@Z 0x14111de60 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@std@@@std@@@std@@_N@1@$$QEAW4Unk_CMISKindB@@@Z 0x14111dea0 ; fx28 callee 0x141116070 (int value)
// MS2-PIN: ??$try_emplace@$$V@?$map@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@std@@@std@@@std@@_N@1@$$QEAW4Unk_CMISKindB@@@Z 0x14111df20 ; fx28 callee 0x1411161c0 (uchar value)
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111dfa0 ; prop
// MS2-PIN: ??0?$CAtlArray@PEAUUnk_CMISElem458@@V?$CElementTraits@PEAUUnk_CMISElem458@@@ATL@@@ATL@@QEAA@XZ 0x14111dfe0 ; unique
// MS2-PIN: ??0?$CustomAllocator@H@efd@@QEAA@XZ 0x14111e0a0 ; prop
// MS2-PIN: ??$?0U?$integral_constant@_N$00@std@@@_Unused_parameter@std@@QEAA@$$QEAU?$integral_constant@_N$00@1@@Z 0x14111e0b0 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@HPEAX@std@@@efd@@QEAA@XZ 0x14111e0c0 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e0d0 ; prop
// MS2-PIN: ??$?0U?$integral_constant@_N$0A@@std@@@_Unused_parameter@std@@QEAA@$$QEAU?$integral_constant@_N$0A@@1@@Z 0x14111e0e0 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e0f0 ; order
// MS2-PIN: ??$_Get_unwrapped_n@H_J$0A@@std@@YAPEAHQEAH_J@Z 0x14111e100 ; order
// MS2-PIN: ??$_Get_unwrapped_n@PEAVCube@@_J$0A@@std@@YAPEAPEAVCube@@QEAPEAV1@_J@Z 0x14111e120 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e130 ; prop
// MS2-PIN: ??$_Get_unwrapped_n@UUnk_CMISElem52@@_J$0A@@std@@YAPEAUUnk_CMISElem52@@QEAU1@_J@Z 0x14111e140 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCell@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e150 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e170 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e190 ; prop
// MS2-PIN: ??0?$CTraceCategoryEx@$03$0A@@ATL@@QEAA@PEBD@Z 0x14111e1a0 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e1b0 ; prop
// MS2-PIN: ??0?$CTraceCategoryEx@$07$0A@@ATL@@QEAA@PEBD@Z 0x14111e1c0 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e1d0 ; prop
// MS2-PIN: ??0?$CTraceCategoryEx@$0BA@$0A@@ATL@@QEAA@PEBD@Z 0x14111e1e0 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e1f0 ; prop
// MS2-PIN: ??0?$CTraceCategoryEx@$0BAA@$0A@@ATL@@QEAA@PEBD@Z 0x14111e200 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e210 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e230 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e250 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e270 ; prop
// MS2-PIN: ??0?$CTraceCategoryEx@$0CAA@$0A@@ATL@@QEAA@PEBD@Z 0x14111e280 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e290 ; prop
// MS2-PIN: ??0?$CTraceCategoryEx@$0EAA@$0A@@ATL@@QEAA@PEBD@Z 0x14111e2a0 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e2b0 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e2d0 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e2f0 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e310 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@QEAA@AEBV01@@Z 0x14111e320 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e330 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@std@@@efd@@QEAA@AEBV01@@Z 0x14111e340 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e350 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@QEAA@AEBV01@@Z 0x14111e360 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e370 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e390 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@@efd@@QEAA@XZ 0x14111e3b0 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@efd@@QEAA@AEBV01@@Z 0x14111e3c0 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e3d0 ; prop
// MS2-PIN: ??0?$tuple@$$V@std@@QEAA@AEBV01@@Z 0x14111e3e0 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@efd@@QEAA@XZ 0x14111e3f0 ; prop
// MS2-PIN: ?select_on_container_copy_construction@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SA?AV?$allocator@U?$_Tree_node@HPEAX@std@@@2@AEBV32@@Z 0x14111e400 ; order
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@efd@@QEAA@XZ 0x14111e410 ; prop
// MS2-PIN: ??0?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@QEAA@XZ 0x14111e420 ; prop
// MS2-PIN: ??0?$CustomAllocator@VEntityID@egf@@@efd@@QEAA@XZ 0x14111e430 ; prop
// MS2-PIN: ??0?$CustomAllocator@VNiTransform@@@efd@@QEAA@XZ 0x14111e440 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@std@@@std@@@std@@_N@1@AEBW4Unk_CMISKindB@@@Z 0x14111df60 ; fx28 callee 141115200 KindB uchar const&
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111da20 ; fx28 callee 1411140f0 int key
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$set@HU?$less@H@std@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111da60 ; fx28 callee 141114240 int key
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@U?$less@H@2@V?$CustomAllocator@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111daa0 ; fx28 callee 141114390 int key, nested map value
// MS2-PIN: ??$try_emplace@$$V@?$map@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111db20 ; fx28 callee 1411144e0 int key
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14111db60 ; fx28 callee 141114630 int key, 0x50 node
// MS2-PIN: ??$try_emplace@$$V@?$map@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@_N@1@$$QEAI@Z 0x14111dc20 ; fx28 callee 141115c80 (deepmatch CA)
// MS2-PIN: ??$try_emplace@$$V@?$map@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@_N@1@$$QEAI@Z 0x14111dbe0 ; fx28 callee 141115b30 (deepmatch std::allocator)
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <NiTransform.h>
#include "ms2/commonfiles/ugcmapsetiteminfo.h"

struct Unk_CMISPawn;
// The ordering FUN_1410bb610 sorts its entity list with: by distance from the pawn (ctor 0x141123230, operator()
// 0x14112cbc0, outside this slice).
struct Unk_CMISByDistance
{
    Unk_CMISByDistance(Unk_CMISPawn* pPawn) { m_pPawn = pPawn; }
    bool operator()(egf::EntityPtr a, egf::EntityPtr b) const;
    Unk_CMISPawn* m_pPawn;
};

typedef std::map<unsigned int, int> Unk_CMISStdMapUIntInt;
typedef std::map<unsigned int, MS2SvrPtr<CUGCMapSetItemInfo> > Unk_CMISMapSetItem;
typedef efd::vector<NiTransform> Unk_CMISXformVec2;
typedef std::vector<Cube*> Unk_CMISCubePtrVec;
// This slice's set-bucket operator[] chain is a second exe copy of the map<id, set<int>> glue that
// entityworldmanager.cpp owns at 0x1411d50c0; a linker keeps one COMDAT per name, so the key here is spelled
// unsigned long (byte-identical code, distinct name).
typedef std::map<unsigned long, Unk_CMISStdIntSet> Unk_CMISMapBucketUL;

// operator[] with a temporary key: the exe's try_emplace(key_type&&) copies
template <class M> void Unk_CMISDriveIndexRv7(M& m)
{
    M tmp;
    tmp[typename M::key_type()];
    (void)m;
}
// the map ops without the const-key operator[] (the exe only indexes these with a temporary)
template <class M> void Unk_CMISDriveMapRv7(M& m, const typename M::key_type& k)
{
    Unk_CMISDriveIndexRv7(m);
    Unk_CMISDriveMapOps(m, k);
}

void Unk_CMISDriveTail7()
{
    int nKey = 0;
    unsigned int uKey = 0;
    unsigned __int64 ullKey = 0;
    egf::EntityID id;
    { Unk_CMISMapIntUInt m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapMark m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapNear m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCell m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv7(m); }
    { Unk_CMISMapEntity m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapDoll m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv7(m); }
    { Unk_CMISMapSales m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapSetEffect m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapHead m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapBuckets m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapCubeGroups m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv7(m); }
    { Unk_CMISStdMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapColumns m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntVec m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntityId m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv7(m); }
    { Unk_CMISMapCubeTimer m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapKind m; Unk_CMISDriveMapRv7(m, nKey); }
    { Unk_CMISMapUIntInt m; Unk_CMISDriveMapRv7(m, uKey); }
    { Unk_CMISStdMapUIntInt m; Unk_CMISDriveIndexRv7(m); }
    { Unk_CMISMapSetItem m; Unk_CMISDriveIndexRv7(m); }
    { Unk_CMISMapDword m; unsigned long dwKey = uKey, dwVal; (void)m.find(dwKey, dwVal); (void)m.end(); (void)m.lower_bound(dwKey); }
    { Unk_CMISMapUid m; Unk_CMISDriveMapOps(m, ullKey); (void)m.equal_range(ullKey); m.erase(ullKey); }
    { Unk_CMISMapBucketUL m; Unk_CMISDriveMap(m, static_cast<unsigned long>(uKey)); }
    { Unk_CMISMapSaleState m; std::pair<int, int> k(0, 0); Unk_CMISDriveMapRv7(m, k); (void)m.equal_range(k); m.erase(k); m[k]; }
    { Unk_CMISMapName m; Unk_CMISDriveMapKey(m, CStringA()); }
    { Unk_CMISMapEntityVal m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapProp m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapEntityCube m; Unk_CMISDriveMap(m, id); }
    { Unk_CMISMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISStdMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISMapKindInt m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv7(m); }
    { Unk_CMISMapKindByte m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv7(m); }
    { Unk_CMISMapIntInt m; Unk_CMISDriveMapOps(m, nKey); }
    { Unk_CubeOwners m; }                                                                       // ugcmapdata's owner table
    { Unk_CMISIntSet s; Unk_CMISDriveSet(s, nKey); { int n = nKey; s.insert(std::move(n)); } (void)s.equal_range(nKey); s.erase(nKey); (void)s.key_comp(); }
    { Unk_CMISPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISAutoSet s; MS2Ptr<AutomaticCreateCubeInfo> p; Unk_CMISDriveSet(s, p); }
    { Unk_CMISFuncCubeSet s; MS2Ptr<CFunctionCubeObject> p; Unk_CMISDriveSet(s, p); s.emplace(p); }
    { Unk_CMISEntityIdSet s; Unk_CMISDriveSet(s, id); }
    { Unk_CMISIntVec v; Unk_CMISDriveVector(v, nKey); Unk_CMISIntVec w; v = w; }
    { Unk_CMISStdEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); std::sort(v.begin(), v.end(), Unk_CMISByDistance(0)); }
    { Unk_CMISEntityIdVec v; Unk_CMISDriveVector(v, id); Unk_CMISEntityIdVec w; v = w; }
    { Unk_CMISEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); Unk_CMISEntVec w; v = w; }
    { Unk_CMISElem52Vec v; Unk_CMISDriveVector(v, Unk_CMISElem52()); Unk_CMISElem52Vec w; v = w; }
    { Unk_CMISKindVec v; Unk_CMISDriveVector(v, Unk_CMISKindC_None); Unk_CMISKindVec w; v = w; }
    { Unk_CMISStdIntSet s; { int n = nKey; s.insert(std::move(n)); } }
    { Unk_CMISPairSet s; s.insert(std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; s.insert(std::pair<int, int>(0, 0)); }
    { std::vector<int> v; v.push_back(nKey); { int n = nKey; v.push_back(std::move(n)); } }
    { Unk_CMISMapBucket a, b; a = b; }
    { Unk_CMISXformVec2 v; NiTransform x; v.push_back(x); v.push_back(NiTransform()); Unk_CMISXformVec2 w; v = w; }
    { Unk_CMISCubePtrVec v; Cube* p = 0; v.push_back(p); v.push_back(static_cast<Cube*>(0)); Unk_CMISCubePtrVec w; v = w; }
    { MS2Ptr<UIHouseMarkEntity> p; }
    { efd::utf8string s; (void)s.find_last_of("/", 0); }
    { std::string s; s.append("x"); }
    { int a = nKey, b = nKey; std::pair<int, int> pr = std::make_pair(a, b); (void)pr; }
    { ATL::CAtlArray<Unk_CMISElem388*> a; ATL::CAtlArray<Unk_CMISElem3a8*> b; ATL::CAtlArray<Unk_CMISElem458*> c; }
}
