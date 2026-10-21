// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\bgtransparencymgr.cpp
// MS2-RANGE: 0x140a0cd30-0x140a1f250 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_7BGTransparencyMgr@@6B?$TSingleton@VBGTransparencyMgr@@@@@ 0x142dc3ae8
// set<Entity*> and map<SmartPointer<Entity>,TransparencyElement*> node construct look-alikes, by caller (_Buynode0/_Buyheadnode)
// MS2-PIN: ??$construct@PEAU?$_Tree_node@PEAVEntity@egf@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@1@AEAPEAU41@@Z 0x140a145d0
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@1@AEAPEAU41@@Z 0x140a14610
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140a0f6c0 ; unique
// MS2-PIN: ??$?0AEBU?$less@UUnk_BGTRegion@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@UUnk_BGTRegion@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@UUnk_BGTRegion@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140a0f950 ; unique
// MS2-PIN: ??$_Buynode@AEBQEAVEntity@egf@@@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVEntity@egf@@U?$less@PEAVEntity@egf@@@std@@V?$CustomAllocator@PEAVEntity@egf@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@1@AEBQEAVEntity@egf@@@Z 0x140a0fef0 ; unique
// MS2-PIN: ??$_Buynode@AEBQEAVTransparencyStandardMaterial@@@?$_List_buy@PEAVTransparencyStandardMaterial@@V?$allocator@PEAVTransparencyStandardMaterial@@@std@@@std@@QEAAPEAU?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@1@PEAU21@0AEBQEAVTransparencyStandardMaterial@@@Z 0x140a0ff80 ; unique
// MS2-PIN: ??$_Construct1@PEAU?$_Tree_node@PEAVEntity@egf@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@1@AEAPEAU51@@Z 0x140a10240 ; unique
// MS2-PIN: ??$_Construct1@PEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@1@AEAPEAU51@@Z 0x140a10290 ; unique
// MS2-PIN: ??$_Destroy1@PEAU?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@1@U?$integral_constant@_N$00@1@@Z 0x140a10580 ; prop
// MS2-PIN: ??$_Destroy1@PEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@1@U?$integral_constant@_N$00@1@@Z 0x140a10590 ; prop
// MS2-PIN: ??$_Freenode0@V?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@@?$_Tree_node@PEAVEntity@egf@@PEAX@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@PEAU01@@Z 0x140a10a20 ; unique
// MS2-PIN: ??$_Freenode0@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@@?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@PEAU01@@Z 0x140a10ad0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@std@@@std@@@?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@std@@SAXAEAV?$allocator@U?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@std@@@1@PEAU01@@Z 0x140a10b80 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@@?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@1@PEAU01@@Z 0x140a10c80 ; unique
// MS2-PIN: ??$_Insert@AEBQEAVTransparencyStandardMaterial@@@?$list@PEAVTransparencyStandardMaterial@@V?$allocator@PEAVTransparencyStandardMaterial@@@std@@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@PEAVTransparencyStandardMaterial@@@std@@@std@@U_Iterator_base0@2@@1@AEBQEAVTransparencyStandardMaterial@@@Z 0x140a10f90 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@0@AEAPEAU10@@Z 0x140a14470 ; prop
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@0@AEAPEAU10@@Z 0x140a14490 ; prop
// MS2-PIN: ??$addressof@PEAVEntity@egf@@@std@@YAPEAPEAVEntity@egf@@AEAPEAV12@@Z 0x140a144b0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@0@AEAV10@@Z 0x140a14530 ; prop
// MS2-PIN: ??$construct@PEAU?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@std@@@1@QEAPEAU?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@1@AEAPEAU31@@Z 0x140a14580 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@1@QEAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@1@AEAPEAU31@@Z 0x140a146a0 ; prop
// MS2-PIN: ??$construct@PEAVTransparencyStandardMaterial@@AEBQEAV1@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@std@@@1@QEAPEAVTransparencyStandardMaterial@@AEBQEAV3@@Z 0x140a14800 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@1@@Z 0x140a149b0 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@1@@Z 0x140a149e0 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@1@QEAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@1@@Z 0x140a14a20 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@0@AEAPEAU10@@Z 0x140a14d40 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@0@AEAPEAU10@@Z 0x140a14d70 ; prop
// MS2-PIN: ??$forward@AEBQEAVTransparencyStandardMaterial@@@std@@YAAEBQEAVTransparencyStandardMaterial@@AEBQEAV1@@Z 0x140a14de0 ; prop
// MS2-PIN: ??$forward@AEBU?$less@UUnk_BGTRegion@@@std@@@std@@YAAEBU?$less@UUnk_BGTRegion@@@0@AEBU10@@Z 0x140a14e20 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@UUnk_BGTRegion@@@1@@Z 0x140a15730 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@1@@Z 0x140a15890 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@1@@Z 0x140a15a30 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@QEAA@XZ 0x140a15b40 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@QEAA@XZ 0x140a15cf0 ; prop
// MS2-PIN: ??0?$set@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@@std@@QEAA@XZ 0x140a15e00 ; unique
// MS2-PIN: ??1?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@QEAA@XZ 0x140a16100 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAA@XZ 0x140a16480 ; unique
// MS2-PIN: ??1?$set@PEAVEntity@egf@@U?$less@PEAVEntity@egf@@@std@@@efd@@QEAA@XZ 0x140a165d0 ; prop
// MS2-PIN: ??4?$SmartPointer@VSceneGraphService@ecr@@@efd@@QEAAAEAV01@PEAVSceneGraphService@ecr@@@Z 0x140a167d0 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140a16950 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140a16ad0 ; unique
// MS2-PIN: ??B?$SmartPointer@VNiMaterial@@@efd@@QEBAPEAVNiMaterial@@XZ 0x140a16c20 ; order
// MS2-PIN: ??C?$SmartPointer@VSceneGraphService@ecr@@@efd@@QEBAPEAVSceneGraphService@ecr@@XZ 0x140a16c50 ; order
// MS2-PIN: ??C?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@std@@QEBAPEBUUnk_BGTRegion@@XZ 0x140a16c80 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@@std@@QEBAAEBVEntityID@egf@@XZ 0x140a16d60 ; probe
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140a16f50 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140a17250 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@PEAVEntity@egf@@@ATL@@SAHAEBQEAVEntity@egf@@0@Z 0x140a179f0 ; unique
// MS2-PIN: ?GetActiveMaterial@NiRenderObject@@QEBAPEBVNiMaterial@@XZ 0x140a17cd0 ; unique
// MS2-PIN: ?GetAt@?$NiTArray@PEAVRecord@NiPick@@V?$NiTMallocInterface@PEAVRecord@NiPick@@@@@@QEBAAEBQEAVRecord@NiPick@@I@Z 0x140a17d30 ; unique
// MS2-PIN: ?GetAt@?$NiTSet@VNiMaterialInstance@@V?$NiTNewInterface@VNiMaterialInstance@@@@@@QEBAAEBVNiMaterialInstance@@I@Z 0x140a17d50 ; unique
// MS2-PIN: ?GetAt@Results@NiPick@@QEBAPEAVRecord@2@I@Z 0x140a17d70 ; unique
// MS2-PIN: ?GetPickResult@PickRecord@PickService@ecr@@QEBAPEBVResults@NiPick@@XZ 0x140a17e00 ; unique
// MS2-PIN: ?GetSize@?$NiTSet@VNiMaterialInstance@@V?$NiTNewInterface@VNiMaterialInstance@@@@@@QEBAIXZ 0x140a17e90 ; unique
// MS2-PIN: ?GetSize@Results@NiPick@@QEBAIXZ 0x140a17ea0 ; unique
// MS2-PIN: ?vfunc_0@IWorldServiceCallback@@UEAAXH@Z 0x140a184c0 ; unique
// MS2-PIN: ?vfunc_1@IWorldServiceCallback@@UEAAXH@Z 0x140a184d0 ; unique
// MS2-PIN: ?vfunc_2@IWorldServiceCallback@@UEAAXHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x140a184f0 ; unique
// MS2-PIN: ?vfunc_7@IWorldServiceCallback@@UEAAXH@Z 0x140a18520 ; unique
// MS2-PIN: ?vfunc_3@IWorldServiceCallback@@UEAAXH@Z 0x140a18530 ; unique
// MS2-PIN: ?vfunc_4@IWorldServiceCallback@@UEAAXH@Z 0x140a18540 ; unique
// MS2-PIN: ?vfunc_6@IWorldServiceCallback@@UEAAXH@Z 0x140a18550 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@U?$less@V?$SmartPointer@VEntity@egf@@@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@2@XZ 0x140a18bc0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVEntity@egf@@U?$less@PEAVEntity@egf@@@std@@V?$CustomAllocator@PEAVEntity@egf@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@2@XZ 0x140a18c80 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@XZ 0x140a18e00 ; unique
// MS2-PIN: ?_Buynode0@?$_List_alloc@U?$_List_base_types@PEAVTransparencyStandardMaterial@@V?$allocator@PEAVTransparencyStandardMaterial@@@std@@@std@@@std@@QEAAPEAU?$_List_node@PEAVTransparencyStandardMaterial@@PEAX@2@PEAU32@0@Z 0x140a18f80 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@U?$less@V?$SmartPointer@VEntity@egf@@@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@PEAX@2@XZ 0x140a19040 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVEntity@egf@@U?$less@PEAVEntity@egf@@@std@@V?$CustomAllocator@PEAVEntity@egf@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@2@XZ 0x140a19120 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAAXXZ 0x140a195d0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@PEAVEntity@egf@@U?$less@PEAVEntity@egf@@@std@@V?$CustomAllocator@PEAVEntity@egf@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@PEAVEntity@egf@@PEAX@2@@Z 0x140a19780 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@@Z 0x140a198c0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@2@@Z 0x140a1ab10 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@@Z 0x140a1b730 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@2@XZ 0x140a1b9b0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@PEAVEntity@egf@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@PEAVEntity@egf@@@std@@@std@@$00@2@$00@std@@QEAAAEAU?$less@PEAVEntity@egf@@@2@XZ 0x140a1ba50 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@PEAVEntity@egf@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@PEAVEntity@egf@@@std@@@std@@$00@2@$00@std@@QEBAAEBU?$less@PEAVEntity@egf@@@2@XZ 0x140a1ba60 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$SmartPointer@VGameObject@@@efd@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$SmartPointer@VGameObject@@@efd@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VGameObject@@@efd@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$SmartPointer@VGameObject@@@efd@@@2@XZ 0x140a1ba90 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$SmartPointer@VGameObject@@@efd@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$SmartPointer@VGameObject@@@efd@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VGameObject@@@efd@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$SmartPointer@VGameObject@@@efd@@@2@XZ 0x140a1baa0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@2@XZ 0x140a1bb50 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@UUnk_BGTRegion@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@2@$00@2@XZ 0x140a1bbd0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@PEAVEntity@egf@@@std@@@std@@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@PEAVEntity@egf@@@std@@@2@XZ 0x140a1bc10 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@PEAVEntity@egf@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@PEAVEntity@egf@@@std@@@std@@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@PEAVEntity@egf@@@std@@@2@XZ 0x140a1bc20 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$SmartPointer@VGameObject@@@efd@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VGameObject@@@efd@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VGameObject@@@efd@@@std@@@2@XZ 0x140a1bc70 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@2@XZ 0x140a1bc80 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@2@XZ 0x140a1be00 ; prop
// MS2-PIN: ?_Kfn@?$_Tset_traits@V?$SmartPointer@VGameObject@@@efd@@U?$less@V?$SmartPointer@VGameObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VGameObject@@@efd@@@4@$0A@@std@@SAAEBV?$SmartPointer@VGameObject@@@efd@@AEBV34@@Z 0x140a1c130 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@XZ 0x140a1c170 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@@Z 0x140a1c430 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@SAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@PEAU32@@Z 0x140a1c680 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@SAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@PEAU32@@Z 0x140a1c7d0 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@XZ 0x140a1c9e0 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@XZ 0x140a1ca80 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@@Z 0x140a1cd60 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@IEAAXXZ 0x140a1d020 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@_K@Z 0x140a1d450 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@2@XZ 0x140a1d600 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAAXXZ 0x140a1d9c0 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_BGTRegion@@PEAX@std@@@2@QEAU?$_Tree_node@UUnk_BGTRegion@@PEAX@2@_K@Z 0x140a1dd70 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@V?$SmartPointer@VGameObject@@@efd@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@V?$SmartPointer@VGameObject@@@efd@@PEAX@2@_K@Z 0x140a1de60 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@VEntityID@egf@@PEAX@2@_K@Z 0x140a1dec0 ; order
// MS2-PIN: ?empty@?$_Tree@V?$_Tmap_traits@V?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@U?$less@V?$SmartPointer@VEntity@egf@@@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@PEAVTransparencyElement@@@std@@@2@$0A@@std@@@std@@QEBA_NXZ 0x140a1df00 ; unique
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@PEAVEntity@egf@@U?$less@PEAVEntity@egf@@@std@@V?$CustomAllocator@PEAVEntity@egf@@@efd@@$0A@@std@@@std@@QEBA_NXZ 0x140a1df40 ; unique
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VGameObject@@@efd@@U?$less@V?$SmartPointer@VGameObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VGameObject@@@efd@@@4@$0A@@std@@@std@@QEBA_NXZ 0x140a1df80 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@2@XZ 0x140a1e0e0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@PEAVEntity@egf@@U?$less@PEAVEntity@egf@@@std@@V?$CustomAllocator@PEAVEntity@egf@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVEntity@egf@@@std@@@std@@@2@V32@@Z 0x140a1e4f0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@2@V32@0@Z 0x140a1e740 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_BGTRegion@@U?$less@UUnk_BGTRegion@@@std@@V?$allocator@UUnk_BGTRegion@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_BGTRegion@@@std@@@std@@@2@V32@@Z 0x140a1e830 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@PEAVEntity@egf@@U?$less@PEAVEntity@egf@@@std@@V?$CustomAllocator@PEAVEntity@egf@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x140a1f0b0 ; unique
// MS2-PINS-END tplpin
// BGTransparencyMgr (see bgtransparencymgr.h) and TransparencyElement. The unit is large and mostly template glue
// of the std containers the class uses (std::set<SmartPointer<GameObject>>, two std::map<SmartPointer<Entity>,
// TransparencyElement*>, std::list<TransparencyStandardMaterial*> ...); the class itself is below, the glue is paired
// by tools/tplpin.py.
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\bgtransparencymgr.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "bgtransparencymgr.h"
#include <algorithm>
#include <atlcoll.h>
#include <NiAVObject.h>
#include <NiNode.h>
#include <NiPick.h>
#include <NiFloatExtraData.h>
#include <NiRenderObject.h>
#include <NiMaterial.h>
#include <efd/EEMath.h>
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/client/ms2/hardwareinstancingservice.h"
#include "hook/ms2hook.h"
#include "ms2/ms2recover.h"

BGTransparencyMgr* TSingleton<BGTransparencyMgr>::s_instance;

// ---- out-of-unit callees (names are exe addresses) ----------------------------------------------------------------
extern char DAT_143b059e8;                                      // service lookup cell (HardwareInstancingService)
extern NiFixedString DAT_143ae5188;                             // render group (float extra data) key
CameraMgr* FUN_1409478c0();                                     // camera manager singleton
WorldService* FUN_1403ed2d0();                                  // world service singleton
EntityWorldManager* FUN_1409670f0();                            // entity world manager singleton
ecr::PickService* FUN_1413f98f0();                              // pick service (manager id 0x7002004)
ecr::SceneGraphService* FUN_1413f98b0();
HardwareInstancingService* FUN_14098c5b0(char* pCell);
NiNode* FUN_1413fa030(egf::Entity* pEntity);                    // entity -> scene root
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);            // the entity's flat model
int FUN_1408a20a0(egf::Entity* pEntity, unsigned nHash, bool* pbOut);        // get a bool property
void FUN_1409618c0(egf::Entity* pEntity, unsigned nHash, efd::Point3* pOut); // get a point property
void FUN_140961880(egf::Entity* pEntity, unsigned nHash, float* pOut);       // get a float property
void FUN_14098c6e0(egf::Entity* pEntity, unsigned nHash, const bool* pValue);// set a bool property
void FUN_14098f4d0(NiAVObject* pNode, bool b);
const NiBound* FUN_140994490(NiAVObject* pNode);                // world bound
extern char DAT_143d69198;                                      // NiRTTI of the material class the fade supports
extern Unk_StreamPoint DAT_143b01a60;                           // zero point

// A scene-graph walk over a model: the exe's iterator helpers (construct 0x14098cb80, next 0x14098e0d0, destroy 0x14098cf00).
struct Unk_CmWalker
{
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5; void* m_p6; void* m_p7;
    Unk_CmWalker(NiObject* pRoot);                    // 0x14098cb80
    ~Unk_CmWalker();                                  // 0x14098cf00
    NiAVObject* FUN_14098e0d0(int bDescend);
};

// @0x140a15390
TSingleton<BGTransparencyMgr>::TSingleton() { s_instance = static_cast<BGTransparencyMgr*>(this); }

// Header inlines of other classes whose COMDATs this unit instantiates first (camera.h / gameobject.h declare them).
// @0x140a17da0
inline float GameObject::FUN_140a17da0() { return m_fUnk110; }

// @0x140a17dc0
inline float GameObject::FUN_140a17dc0() { return m_fUnk114; }

// @0x140a17e10
inline Unk_StreamPoint CameraMgr::FUN_140a17e10()
{
    if (m_spMode.get() != 0)
        return m_spMode->FUN_1409f2540();
    else
        return DAT_143b01a60;
}

// @0x140a18070
inline int CameraMgr::FUN_140a18070() { return m_1b0; }

// @0x140a0cd30
BGTransparencyMgr::BGTransparencyMgr()
{
    m_nFlags = 1;
    m_nUserFlags = 1;
    m_nWorldFlags = 0;
}

// @0x140a0ce30
BGTransparencyMgr::~BGTransparencyMgr() {}

// @0x140a0cee0
// MS2-FUNCTIONAL: first-pass source; instruction order / temporaries differ from the exe, behaviour follows the decompile
int BGTransparencyMgr::Init()
{
    FUN_1403ed2d0()->FUN_141bbae40(this ? static_cast<IWorldServiceCallback*>(this) : 0);
    m_map30.clear();
    m_map40.clear();
    m_timer.FUN_140868750(300);
    m_spService = FUN_1413f98f0();
    m_spSceneGraph = FUN_1413f98b0();
    return 1;
}

// @0x140a0cf90
// MS2-FUNCTIONAL: first-pass source; instruction order / temporaries differ from the exe, behaviour follows the decompile
void BGTransparencyMgr::Shutdown()
{
    m_spSceneGraph = 0;
    m_spService = 0;
    FUN_1403ed2d0()->FUN_141bbae80(this ? static_cast<IWorldServiceCallback*>(this) : 0);
}

// @0x140a0d000
void BGTransparencyMgr::Tick()
{
    UpdateFadeOut();
    UpdateFadeIn();
    if (m_timer.FUN_140868c00() != 0)
    {
        vfunc_1();
        m_timer.FUN_140868750(300);
    }
}
MS2_REPLACE_METHOD(0x140A0D000, BGTransparencyMgr, Tick, 93, 0x4B724FE6);

// @0x140a0d0c0
void BGTransparencyMgr::SetUserFlags(int nFlags)
{
    m_nUserFlags = nFlags;
    m_nFlags = m_nUserFlags | m_nWorldFlags;
    if (m_nFlags == 0)
        MoveAllToFadeIn();
}
MS2_REPLACE_METHOD(0x140A0D0C0, BGTransparencyMgr, SetUserFlags, 92, 0x9BBA1288);

// @0x140a0d130
// MS2-FUNCTIONAL: first-pass source; instruction order / temporaries differ from the exe, behaviour follows the decompile
void BGTransparencyMgr::AddObject(GameObject* pObject)
{
    m_set20.insert(efd::SmartPointer<GameObject>(pObject));
}

// @0x140a0d190
// MS2-FUNCTIONAL: first-pass source; instruction order / temporaries differ from the exe, behaviour follows the decompile
void BGTransparencyMgr::RemoveObject(GameObject* pObject)
{
    std::set<efd::SmartPointer<GameObject> >::iterator it = m_set20.find(efd::SmartPointer<GameObject>(pObject));
    if (it != m_set20.end())
        m_set20.erase(it);
}

// @0x140a0d230
// MS2-FUNCTIONAL: first-pass source; instruction order / temporaries differ from the exe, behaviour follows the decompile
void BGTransparencyMgr::vfunc_3(int)
{
    m_set20.clear();
    for (Unk_BGTElementMap::iterator it = m_map30.begin(); it != m_map30.end(); ++it)
    {
        ReleaseMaterials(it->first, it->second);
        TransparencyElement* pElement = it->second;
        delete pElement;
    }
    m_map30.clear();
    for (Unk_BGTElementMap::iterator it = m_map40.begin(); it != m_map40.end(); ++it)
    {
        ReleaseMaterials(it->first, it->second);
        TransparencyElement* pElement = it->second;
        delete pElement;
    }
    m_map40.clear();
}

// @0x140a0d450
// MS2-FUNCTIONAL: first-pass source; instruction order / temporaries differ from the exe, behaviour follows the decompile
void BGTransparencyMgr::EraseEntity(egf::Entity* pEntity)
{
    Unk_BGTElementMap::iterator it = m_map30.find(Unk_BGTEntityPtr(pEntity));
    if (it != m_map30.end())
    {
        DeleteMaterials(it->second);
        TransparencyElement* pElement = it->second;
        delete pElement;
        m_map30.erase(it);
    }
    it = m_map40.find(Unk_BGTEntityPtr(pEntity));
    if (it != m_map40.end())
    {
        DeleteMaterials(it->second);
        TransparencyElement* pElement = it->second;
        delete pElement;
        m_map40.erase(it);
    }
}

// @0x140a0d670
// MS2-FUNCTIONAL: first-pass source; instruction order / temporaries differ from the exe, behaviour follows the decompile
bool BGTransparencyMgr::IsTarget(egf::Entity* pEntity)
{
    if (pEntity != 0)
    {
        for (std::set<efd::SmartPointer<GameObject> >::iterator it = m_set20.begin(); it != m_set20.end(); ++it)
        {
            GameObject* pObject = *it;
            if (pObject->FUN_14123c410() == pEntity)
                return false;
        }
        if (FUN_1408a9bd0(pEntity) != 0)
        {
            egf::FlatModel* pModel = FUN_1408a9bd0(pEntity);
            if (pModel->ContainsModel(0x2ea80520))
            {
                bool bValue = false;
                FUN_1408a20a0(pEntity, 0x9004569a, &bValue);
                if (!bValue && m_nWorldFlags != 0)
                    FUN_1408a20a0(pEntity, 0x619a775d, &bValue);
                if (bValue)
                    return true;
                return false;
            }
        }
    }
    return false;
}

// @0x140a0d7a0
// MS2-FUNCTIONAL: first-pass source; instruction order / temporaries differ from the exe, behaviour follows the decompile
bool BGTransparencyMgr::RayHits(efd::Point3 ptOrigin, efd::Point3 ptDir, NiAVObject* pNode)
{
    if (m_spService != 0)
    {
        efd::SmartPointer<ecr::PickService::PickRecord> spRecord(
            m_spService->PerformPick(ptOrigin, ptDir, pNode, false, true, false));
        if (spRecord != 0)
            return true;
        return false;
    }
    return false;
}

// @0x140a0d880
// MS2-FUNCTIONAL: first-pass source; instruction order / temporaries differ from the exe, behaviour follows the decompile
bool BGTransparencyMgr::PickEntities(efd::Point3 ptOrigin, efd::Point3 ptDir, Unk_BGTEntityList& kOut,
    egf::Entity* pSkip)
{
    if (m_spService != 0)
    {
        if (m_spSceneGraph != 0)
        {
            efd::SmartPointer<ecr::PickService::PickRecord> spRecord(
                m_spService->PerformPick(ptOrigin, ptDir, false, true, false));
            if (spRecord != 0)
            {
                egf::Entity* pEntity = 0;
                ATL::CRBMap<egf::Entity*, NiAVObject*> kSeen(10);
                const NiPick::Results* pResults = spRecord->GetPickResult();
                unsigned nCount = pResults->GetSize();
                for (unsigned i = 0; i < nCount; i++)
                {
                    NiAVObject* pNode = pResults->GetAt(i)->GetAVObject();
                    pEntity = m_spSceneGraph->GetEntityFromSceneGraphNode(pNode);
                    NiAVObject* pFound = 0;
                    if (pEntity != pSkip && pEntity != 0 && !kSeen.Lookup(pEntity, pFound) && IsTarget(pEntity))
                    {
                        kSeen.SetAt(pEntity, pNode);
                        kOut.push_back(pEntity);
                    }
                }
                if (kOut.size() != 0)
                    return true;
            }
        }
    }
    return false;
}

// @0x140a0db00
// MS2-FUNCTIONAL: first-pass source; frame layout and temporary order not byte-compared
void BGTransparencyMgr::vfunc_1()
{
    CameraMgr* pCamera = FUN_1409478c0();
    if (pCamera->FUN_140a18070() != 0 && m_nFlags != 0 && !m_set20.empty())
    {
        std::set<Unk_BGTRegion> kVisible;
        Unk_BGTEntitySet kHit;
        Unk_StreamPoint pc = pCamera->FUN_140a17e10();
    efd::Point3 ptCamera(pc.x, pc.y, pc.z);
        FUN_1403ed2d0()->FUN_141bc7920(reinterpret_cast<std::set<void*>&>(kVisible));
        for (std::set<efd::SmartPointer<GameObject> >::iterator it = m_set20.begin(); it != m_set20.end(); ++it)
        {
            if ((*it)->FUN_14123c660() == 0 || (*it)->GetClassID() == 0x6200004)
            {
                efd::Point3 ptPos = (*it)->vfunc_18();
                efd::Point3 ptDirA = ptCamera - (ptPos + efd::Point3::UNIT_Z * (*it)->FUN_140a17da0());
                ptDirA.Unitize();
                efd::Point3 ptDirB = ptCamera - (ptPos + efd::Point3::UNIT_Z * (*it)->FUN_140a17dc0());
                ptDirB.Unitize();
                egf::Entity* pEntityA = 0;
                egf::Entity* pEntityB = 0;
                for (std::set<Unk_BGTRegion>::iterator itRegion = kVisible.begin(); itRegion != kVisible.end();
                    ++itRegion)
                {
                if (RayHits(ptPos + efd::Point3::UNIT_Z * (*it)->FUN_140a17da0(), ptDirA, itRegion->m_pNode))
                {
                    pEntityA = FUN_1409670f0()->FUN_1411cf440(itRegion->m_id);
                    if (pEntityA != 0)
                    {
                        bool bAdded = false;
                        int nKind = itRegion->m_nKind;
                        if (nKind == 0)
                        {
                            kHit.insert(pEntityA);
                            bAdded = true;
                        }
                        else if (nKind == 1 && m_nWorldFlags != 0)
                        {
                            kHit.insert(pEntityA);
                            bAdded = true;
                        }
                        if (bAdded && itRegion->m_nGroup > 0)
                        {
                            std::set<egf::EntityID> kGroup;
                            FUN_1403ed2d0()->FUN_141bc7aa0(itRegion->m_nGroup,
                                reinterpret_cast<std::set<unsigned __int64>&>(kGroup));
                            std::set<egf::EntityID>::iterator itEnd = kGroup.end();
                            std::set<egf::EntityID>::iterator itId = kGroup.begin();
                            while (itId != itEnd)
                            {
                                egf::EntityID id(*itId);
                                pEntityA = FUN_1409670f0()->FUN_1411cf440(id);
                                if (pEntityA != 0)
                                    kHit.insert(pEntityA);
                                ++itId;
                            }
                        }
                    }
                }
                if (RayHits(ptPos + efd::Point3::UNIT_Z * (*it)->FUN_140a17dc0(), ptDirB, itRegion->m_pNode))
                {
                    pEntityB = FUN_1409670f0()->FUN_1411cf440(itRegion->m_id);
                    if (pEntityB != 0 && pEntityA != pEntityB)
                    {
                        bool bAdded = false;
                        int nKind = itRegion->m_nKind;
                        if (nKind == 0)
                        {
                            kHit.insert(pEntityB);
                            bAdded = true;
                        }
                        else if (nKind == 1 && m_nWorldFlags != 0)
                        {
                            kHit.insert(pEntityB);
                            bAdded = true;
                        }
                        if (bAdded && itRegion->m_nGroup > 0)
                        {
                            std::set<egf::EntityID> kGroup;
                            FUN_1403ed2d0()->FUN_141bc7aa0(itRegion->m_nGroup,
                                reinterpret_cast<std::set<unsigned __int64>&>(kGroup));
                            std::set<egf::EntityID>::iterator itEnd = kGroup.end();
                            std::set<egf::EntityID>::iterator itId = kGroup.begin();
                            while (itId != itEnd)
                            {
                                egf::EntityID id(*itId);
                                pEntityB = FUN_1409670f0()->FUN_1411cf440(id);
                                if (pEntityB != 0)
                                    kHit.insert(pEntityB);
                                ++itId;
                            }
                        }
                    }
                }
                }
            }
        }
        Apply(kHit);
    }
}

// @0x140a0e330
// MS2-FUNCTIONAL: first-pass source; frame layout and temporary order not byte-compared
void BGTransparencyMgr::Apply(Unk_BGTEntitySet& kHit)
{
    if (kHit.empty())
    {
        MoveAllToFadeIn();
        return;
    }
    MoveMissingToFadeIn(kHit);
    for (Unk_BGTEntitySet::iterator it = kHit.begin(); it != kHit.end(); ++it)
    {
        egf::Entity* pEntity = *it;
        if (pEntity == 0)
            continue;
        if (m_map30.find(Unk_BGTEntityPtr(pEntity)) != m_map30.end())
            continue;
        if (m_map40.find(Unk_BGTEntityPtr(pEntity)) != m_map40.end())
            continue;
        bool bFlag = false;
        int nResult = FUN_1408a20a0(pEntity, 0x9004569a, &bFlag);
        if (nResult == 0 && !bFlag)
            continue;
        TransparencyElement* pElement = new (efd::MemHint(efd::MemHint::NONE)) TransparencyElement;
        m_map30[Unk_BGTEntityPtr(pEntity)] = pElement;
        float fAlpha = 0.3f;
        FUN_140961880(pEntity, 0x188f01c1, &fAlpha);
        pElement->m_fAlpha = fAlpha;
        NiNode* pRoot = FUN_1413fa030(pEntity);
        if (pRoot == 0)
            continue;
        FUN_14098f4d0(pRoot, false);
        NiBound kBound = *FUN_140994490(pRoot);
        Unk_CmWalker kWalker(pRoot);
        while (NiAVObject* pObject = kWalker.FUN_14098e0d0(1))
        {
            NiRenderObject* pMesh = NiDynamicCast(NiRenderObject, pObject);
            if (pMesh == 0)
                continue;
            TransparencyStandardMaterial* pMaterial = 0;
            const NiMaterial* pActive = pMesh->GetActiveMaterial();
            if (pActive != 0 && NiMaterial::DynamicCast((const NiRTTI*)&DAT_143d69198, pActive) != 0)
                pMaterial = new (efd::MemHint(efd::MemHint::NONE)) TransparencyStandardMaterial(pMesh);
            if (pMaterial == 0)
                continue;
            efd::SmartPointer<HardwareInstancingService> spInstancing(FUN_14098c5b0(&DAT_143b059e8));
            if (spInstancing != 0)
            {
                if (spInstancing->FUN_1413d6f40(pEntity) != 0)
                {
                    bool bTrue = true;
                    FUN_14098c6e0(pEntity, 0xa0b6b179, &bTrue);
                }
            }
            pMaterial->vfunc_2(kBound);
            pElement->m_materials.push_back(pMaterial);
            pElement->m_timer.FUN_140868750(300);
        }
        pRoot->UpdateProperties();
    }
}

// @0x140a0e860
// MS2-FUNCTIONAL: first-pass source; frame layout and temporary order not byte-compared
void BGTransparencyMgr::SortEntities()
{
    Unk_BGTEntityList kList;
    Unk_BGTElementMap::const_iterator it = m_map30.begin();
    Unk_BGTElementMap::const_iterator itEnd = m_map30.end();
    while (it != itEnd)
    {
        kList.push_back(it->first);
        ++it;
    }
    it = m_map40.begin();
    itEnd = m_map40.end();
    while (it != itEnd)
    {
        kList.push_back(it->first);
        ++it;
    }
    if (kList.size() != 0)
    {
        std::sort(kList.begin(), kList.end(), CompareDistance);
        size_t nCount = kList.size();
        for (size_t i = 0; i < nCount; i++)
        {
            egf::Entity* pEntity = kList[i];
            NiNode* pRoot = FUN_1413fa030(pEntity);
            if (pRoot != 0)
            {
                Unk_CmWalker kWalker(pRoot);
                while (NiAVObject* pObject = kWalker.FUN_14098e0d0(1))
                {
                    NiRenderObject* pNet = NiDynamicCast(NiRenderObject, pObject);
                    if (pNet != 0)
                    {
                        NiFloatExtraData* pData = NiDynamicCast(NiFloatExtraData, pNet->GetExtraData(DAT_143ae5188));
                        if (pData == 0)
                        {
                            pData = new (efd::MemHint(efd::MemHint::NONE)) NiFloatExtraData(0.0f);
                            pNet->AddExtraData(DAT_143ae5188, pData);
                        }
                        pData->SetValue((float)i);
                    }
                }
            }
        }
    }
}

// @0x140a0ebf0
void BGTransparencyMgr::UpdateFadeOut()
{
    if (!m_map30.empty())
    {
        Unk_BGTElementMap::const_iterator it = m_map30.begin();
        Unk_BGTElementMap::const_iterator itEnd = m_map30.end();
        while (it != itEnd)
        {
            TransparencyElement* pElement = it->second;
            if (pElement->m_timer.FUN_140868ba0() != 0)
            {
                for (std::list<TransparencyStandardMaterial*>::iterator
                    itMat = pElement->m_materials.begin(); itMat != pElement->m_materials.end(); ++itMat)
                {
                    float fRatio = pElement->m_timer.FUN_140868940();
                    (*itMat)->vfunc_4(efd::Clamp(1.0f - fRatio, pElement->m_fAlpha, 1.0f));
                }
            }
            ++it;
        }
    }
}

// @0x140a0ed80
void BGTransparencyMgr::UpdateFadeIn()
{
    if (!m_map40.empty())
    {
        Unk_BGTElementMap::iterator it = m_map40.begin();
        Unk_BGTElementMap::iterator itEnd = m_map40.end();
        while (it != itEnd)
        {
            egf::Entity* pEntity = it->first;
            TransparencyElement* pElement = it->second;
            if (pElement->m_timer.FUN_140868ba0() == 0)
            {
                efd::SmartPointer<HardwareInstancingService> spInstancing(FUN_14098c5b0(&DAT_143b059e8));
                if (spInstancing != 0)
                {
                    if (spInstancing->FUN_1413d6fc0(pEntity) != 0)
                    {
                        bool bFalse = false;
                        FUN_14098c6e0(pEntity, 0xa0b6b179, &bFalse);
                    }
                }
                ReleaseMaterials(pEntity, pElement);
                delete pElement;
                m_map40.erase(it++);
            }
            else
            {
                for (std::list<TransparencyStandardMaterial*>::iterator
                    itMat = pElement->m_materials.begin(); itMat != pElement->m_materials.end(); ++itMat)
                {
                    float fRatio = pElement->m_timer.FUN_140868940();
                    (*itMat)->vfunc_4(efd::Clamp(fRatio, pElement->m_fAlpha, 1.0f));
                }
                ++it;
            }
        }
    }
}

// @0x140a0f020
void BGTransparencyMgr::ReleaseMaterials(egf::Entity* pEntity, TransparencyElement* pElement)
{
    for (std::list<TransparencyStandardMaterial*>::iterator
        it = pElement->m_materials.begin(); it != pElement->m_materials.end(); ++it)
    {
        (*it)->vfunc_3();
        TransparencyStandardMaterial* pMaterial = *it;
        delete pMaterial;
    }
    pElement->m_materials.clear();
    NiNode* pRoot = FUN_1413fa030(pEntity);
    if (pRoot != 0)
        pRoot->UpdateProperties();
}

// @0x140a0f140
void BGTransparencyMgr::DeleteMaterials(TransparencyElement* pElement)
{
    for (std::list<TransparencyStandardMaterial*>::iterator
        it = pElement->m_materials.begin(); it != pElement->m_materials.end(); ++it)
    {
        TransparencyStandardMaterial* pMaterial = *it;
        delete pMaterial;
    }
    pElement->m_materials.clear();
}

// @0x140a0f200
void BGTransparencyMgr::MoveAllToFadeIn()
{
    for (Unk_BGTElementMap::iterator it = m_map30.begin(); it != m_map30.end(); ++it)
    {
        m_map40[it->first] = it->second;
        it->second->m_timer.FUN_140868750(300);
    }
    m_map30.clear();
}
MS2_REPLACE_METHOD(0x140A0F200, BGTransparencyMgr, MoveAllToFadeIn, 197, 0xE7C475AD);

// @0x140a0f2d0
void BGTransparencyMgr::MoveMissingToFadeIn(Unk_BGTEntitySet& kHit)
{
    if (!m_map30.empty())
    {
        Unk_BGTElementMap::iterator it = m_map30.begin();
        Unk_BGTElementMap::iterator itEnd = m_map30.end();
        while (it != itEnd)
        {
            egf::Entity* pEntity = it->first;
            TransparencyElement* pElement = it->second;
            if (kHit.find(pEntity) == kHit.end())
            {
                m_map40[Unk_BGTEntityPtr(pEntity)] = pElement;
                pElement->m_timer.FUN_140868750(300);
                m_map30.erase(it++);
            }
            else
                ++it;
        }
    }
}

// @0x140a0f460
bool BGTransparencyMgr::CompareDistance(egf::Entity* pA, egf::Entity* pB)
{
    efd::Point3 ptA, ptB;
    FUN_1409618c0(pA, 0xfd95ca52, &ptA);
    FUN_1409618c0(pB, 0xfd95ca52, &ptB);
    CameraMgr* pCamera = FUN_1409478c0();
    if (pCamera->FUN_140a18070() == 0)
        return false;
    Unk_StreamPoint pc = pCamera->FUN_140a17e10();
    efd::Point3 ptCamera(pc.x, pc.y, pc.z);
    float fA = (ptA - ptCamera).Length();
    float fB = (ptB - ptCamera).Length();
    return fB < fA;
}

// @0x140a15fe0
TransparencyElement::TransparencyElement()
{
    m_fAlpha = 0.3f;
}


// @0x140a1f130
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x140a17da0, GameObject, FUN_140a17da0, 19, 0x3A8D58F9);
MS2_REPLACE_METHOD(0x140a17dc0, GameObject, FUN_140a17dc0, 19, 0xD529AE85);
MS2_REPLACE_METHOD(0x140a18070, CameraMgr, FUN_140a18070, 17, 0xF1B8F21A);
MS2_REPLACE_METHOD(0x140a0cee0, BGTransparencyMgr, Init, 167, 0x9450441D);
MS2_REPLACE_METHOD(0x140a0cf90, BGTransparencyMgr, Shutdown, 103, 0xD8877191);
MS2_REPLACE_METHOD(0x140a0d130, BGTransparencyMgr, AddObject, 82, 0x9479868C);
MS2_REPLACE_METHOD(0x140a0d190, BGTransparencyMgr, RemoveObject, 151, 0x9E9E7CB8);
MS2_REPLACE_METHOD_VIA(0x140a0d230, BGTransparencyMgr, IWorldServiceCallback, vfunc_3, 536, 0xE2169CFE);
MS2_REPLACE_METHOD(0x140a0d450, BGTransparencyMgr, EraseEntity, 528, 0xFA013C55);
MS2_REPLACE_METHOD(0x140a0d670, BGTransparencyMgr, IsTarget, 296, 0x706F7CBD);
MS2_REPLACE_METHOD(0x140a0db00, BGTransparencyMgr, vfunc_1, 2087, 0x0C0F44E6);
MS2_REPLACE_METHOD(0x140a0ebf0, BGTransparencyMgr, UpdateFadeOut, 382, 0x360C1663);
MS2_REPLACE_METHOD(0x140a0ed80, BGTransparencyMgr, UpdateFadeIn, 651, 0xFFB6C417);
MS2_REPLACE_METHOD(0x140a0f020, BGTransparencyMgr, ReleaseMaterials, 270, 0x630D92CC);
MS2_REPLACE(0x140a0f140, BGTransparencyMgr::DeleteMaterials, 186, 0xA24BC03D);
MS2_REPLACE_METHOD(0x140a0f2d0, BGTransparencyMgr, MoveMissingToFadeIn, 383, 0x9B2EDDD8);
MS2_REPLACE(0x140a0f460, BGTransparencyMgr::CompareDistance, 234, 0x97E118CA);

