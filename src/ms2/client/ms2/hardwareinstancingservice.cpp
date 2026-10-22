// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\hardwareinstancingservice.cpp
// MS2-RANGE: 0x1400f4b40-0x1400f4ea0 .text$di
// MS2-RANGE: 0x1413d3000-0x1413e8a20 .text$mn
// MS2-RANGE: 0x1413e8a20-0x1413f31d0 .text$mn
// MS2-RANGE: 0x1413f31d0-0x1413f9290 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$addressof@$$CBV?$list@VEntityID@egf@@V?$allocator@VEntityID@egf@@@std@@@std@@@std@@YAPEBV?$list@VEntityID@egf@@V?$allocator@VEntityID@egf@@@std@@@0@AEBV10@@Z 0x1413d3ca0 ; prop
// MS2-PIN: ??4?$list@VEntityID@egf@@V?$allocator@VEntityID@egf@@@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x1413d3ee0 ; unique
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$CustomAllocator@I@efd@@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@@1@AEBI@Z 0x1413db5e0 ; unique
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@0@AEAV10@@Z 0x1413f2580 ; prop
// MS2-PIN: ?count@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$CustomAllocator@I@efd@@$0A@@std@@@std@@QEBA_KAEBI@Z 0x1413f6b30 ; unique
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$CustomAllocator@I@efd@@$0A@@std@@@std@@QEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@@2@AEBI@Z 0x1413f7760 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$list@UUnk_HwiCreated@@V?$allocator@UUnk_HwiCreated@@@std@@@std@@QEAA@XZ 0x1413e9150 ; hand: FUN_1413d5710's local list (list dtors laid out by type name)
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@UUnk_PropertyCacheEntry@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@UUnk_PropertyCacheEntry@@@std@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1413d89c0 ; hand: calls _Tree_val<pair<utf8string, Unk_PropertyCacheEntry>> 0x1413e8340
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$CustomAllocator@I@efd@@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x1413f2480 ; hand: callee of _Eqrange 0x1413db5e0
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$CustomAllocator@I@efd@@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x1413f3190 ; hand: callee of _Eqrange 0x1413db5e0
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$map@Vutf8string@efd@@UUnk_PropertyCacheEntry@@U?$less@Vutf8string@efd@@@std@@@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIV?$map@Vutf8string@efd@@UUnk_PropertyCacheEntry@@U?$less@Vutf8string@efd@@@std@@@efd@@@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x1413f2ff0 ; hand: callee of _Compare 0x1413ee990
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@@std@@QEBAAEBQEAPEAVNiMesh@@XZ 0x1413f4520 ; hand: callee of _Has_unused_capacity 0x1413f31d0 / size 0x1413f9210
// MS2-PIN: ?_Xlength@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@CAXXZ 0x1413f5880 ; hand: callee of _Emplace_reallocate 0x1413db160
// MS2-PIN: ?deallocate@?$allocator@U?$_List_node@UUnk_HwiNearby@@PEAX@std@@@std@@QEAAXQEAU?$_List_node@UUnk_HwiNearby@@PEAX@2@_K@Z 0x1413f6f30 ; hand: deallocate run laid out by type name
// MS2-PIN: ?deallocate@?$allocator@U?$_List_node@UUnk_HwiPending@@PEAX@std@@@std@@QEAAXQEAU?$_List_node@UUnk_HwiPending@@PEAX@2@_K@Z 0x1413f6f60 ; hand: deallocate run laid out by type name
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@PEAVMeshInstancing@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@PEAVMeshInstancing@@PEAX@2@_K@Z 0x1413f6fc0 ; hand: deallocate run laid out by type name
// MS2-PIN: ??$?0V?$tuple@AEBI@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBIUUnk_HwiMapData@@@std@@QEAA@AEAV?$tuple@AEBI@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1413d97a0 ; hand: tplpin unique
// MS2-PIN: ??E?$_List_iterator@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1413ea1c0 ; hand: tplpin unique
// MS2-PIN: ??0Unk_HwiMapData@@QEAA@XZ 0x1413e8850 ; hand: only caller of the list<Unk_HwiNearby> ctor 0x1413e8550
// MS2-PIN: ??$_Lbound@VEntityID@egf@@@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@PEAVMeshInstancing@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@5@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@PEAX@1@AEBVEntityID@egf@@@Z 0x1413e3ed0 ; hand: tplpin unique
// MS2-PIN: ??$make_pair@_KAEAPEAVEntityInstancing@@@std@@YA?AU?$pair@_KPEAVEntityInstancing@@@0@$$QEA_KAEAPEAVEntityInstancing@@@Z 0x1413e6ac0 ; hand: tplpin unique
// MS2-PIN: ??C?$_List_iterator@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@@std@@QEBAPEAUUnk_HwiCreated@@XZ 0x1413e9be0 ; hand: tplpin unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@PEAVMeshInstancing@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@5@$0A@@std@@@std@@IEBA_NAEBVEntityID@egf@@0@Z 0x1413eea90 ; hand: tplpin prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@PEAVMeshInstancing@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@5@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@std@@@2@XZ 0x1413f2390 ; hand: tplpin prop
// MS2-PIN: ??_7HardwareInstancingService@@6BISystemService@efd@@@ 0x142f0c198 ; w102 manual
// MS2-PIN: ??$_Kfn@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@?$_Tmap_traits@VAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@U?$less@VAssetID@efd@@@4@V?$allocator@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@4@$0A@@std@@SAAEBVAssetID@efd@@AEBU?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@1@@Z 0x1413e3c00 ; w102 manual unique
// MS2-PIN: ??$addressof@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@@std@@YAPEAV?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@0@AEAV10@@Z 0x1413e4d80 ; w102 manual prop
// MS2-PIN: ??$destroy@PEAU?$_List_node@UUnk_HwiCreated@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@1@QEAPEAU?$_List_node@UUnk_HwiCreated@@PEAX@1@@Z 0x1413e5a50 ; w102 manual prop
// MS2-PIN: ??$forward@AEBU?$less@VAssetID@efd@@@std@@@std@@YAAEBU?$less@VAssetID@efd@@@0@AEBU10@@Z 0x1413e6560 ; w102 manual unique
// MS2-PIN: ??$move@AEAUUnk_HwiCreated@@@std@@YA$$QEAUUnk_HwiCreated@@AEAU1@@Z 0x1413e6b80 ; w102 manual prop
// MS2-PIN: ??0?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@UUnk_HwiCreated@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@1@@Z 0x1413e7340 ; w102 manual prop
// MS2-PIN: ??0?$_List_iterator@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@UUnk_HwiCreated@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@1@@Z 0x1413e7480 ; w102 manual prop
// MS2-PIN: ??0?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_List_node@UUnk_HwiCreated@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@1@@Z 0x1413e75c0 ; w102 manual prop
// MS2-PIN: ??0?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@UUnk_HwiCreated@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@1@@Z 0x1413e7700 ; w102 manual prop
// MS2-PIN: ??0?$_List_iterator@V?$_List_val@U?$_List_simple_types@VEntityID@egf@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@VEntityID@egf@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@VEntityID@egf@@@std@@@1@@Z 0x1413e7df0 ; w102 manual prop
// MS2-PIN: ??1?$_List_buy@UUnk_HwiCreated@@V?$allocator@UUnk_HwiCreated@@@std@@@std@@QEAA@XZ 0x1413e8d40 ; hand: callee of ~list<Unk_HwiCreated> 0x1413e9150
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@PEAVNiMesh@@@efd@@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@PEAVNiMesh@@@efd@@XZ 0x1413f2670 ; w102 manual prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@UUnk_HwiNearby@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@UUnk_HwiNearby@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_List_node@UUnk_HwiNearby@@PEAX@std@@@2@XZ 0x1413f2710 ; w102 manual prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@2@XZ 0x1413f2750 ; w102 manual prop
// MS2-PIN: ?_Getal@?$_List_alloc@U?$_List_base_types@UUnk_HwiNearby@@V?$allocator@UUnk_HwiNearby@@@std@@@std@@@std@@QEBAAEBV?$allocator@U?$_List_node@UUnk_HwiNearby@@PEAX@std@@@2@XZ 0x1413f2bb0 ; w102 manual unique
// MS2-PIN: ?_Getal@?$_List_alloc@U?$_List_base_types@UUnk_HwiCreated@@V?$allocator@UUnk_HwiCreated@@@std@@@std@@@std@@QEBAAEBV?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@2@XZ 0x1413f2c30 ; w102 manual prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@@std@@QEBAAEBV?$CustomAllocator@PEAVNiMesh@@@efd@@XZ 0x1413f2f70 ; w102 manual prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@AEBA_NXZ 0x1413f31d0 ; w102 manual unique
// MS2-PIN: ?_Max_size1@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SA_KAEBV?$CustomAllocator@PEAVNiMesh@@@efd@@U?$integral_constant@_N$00@2@@Z 0x1413f4180 ; w102 manual prop
// MS2-PIN: ?_Max_size1@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIV?$map@Vutf8string@efd@@UUnk_PropertyCacheEntry@@U?$less@Vutf8string@efd@@@std@@@efd@@@std@@PEAX@std@@@efd@@@std@@SA_KAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIV?$map@Vutf8string@efd@@UUnk_PropertyCacheEntry@@U?$less@Vutf8string@efd@@@std@@@efd@@@std@@PEAX@std@@@efd@@U?$integral_constant@_N$00@2@@Z 0x1413f41a0 ; w102 manual prop (tx1: the tree-node allocator, calls max_size 0x1413f8af0 = 0x1249249; CustomAllocator<char> is 0x1408769d0)
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@@std@@QEBAAEBQEAPEAVNiMesh@@XZ 0x1413f4400 ; w102 manual prop
// MS2-PIN: ?_Mysize@?$_List_alloc@U?$_List_base_types@UUnk_HwiCreated@@V?$allocator@UUnk_HwiCreated@@@std@@@std@@@std@@QEAAAEA_KXZ 0x1413f4660 ; w102 manual unique
// MS2-PIN: ?_Orphan_range@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@AEBAXPEAPEAVNiMesh@@0@Z 0x1413f46c0 ; w102 manual unique
// MS2-PIN: ?_Tidy@?$list@UUnk_HwiCreated@@V?$allocator@UUnk_HwiCreated@@@std@@@std@@QEAAXXZ 0x1413f5330 ; hand: callee of ~list<Unk_HwiCreated> 0x1413e9150
// MS2-PIN: ?allocate@?$CustomAllocator@PEAVNiMesh@@@efd@@QEAAPEAPEAVNiMesh@@_KPEBX@Z 0x1413f58c0 ; w102 manual unique
// MS2-PIN: ?capacity@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEBA_KXZ 0x1413f61b0 ; w102 manual unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@2@QEAU?$_List_node@UUnk_HwiCreated@@PEAX@2@_K@Z 0x1413f6d20 ; w102 manual unique
// MS2-PIN: ?max_size@?$CustomAllocator@PEAVNiMesh@@@efd@@QEBA_KXZ 0x1413f8ae0 ; w102 manual unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@2@@Z 0x1413f8b50 ; w102 manual unique
// MS2-PIN: ?max_size@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SA_KAEBV?$CustomAllocator@PEAVNiMesh@@@efd@@@Z 0x1413f8bd0 ; w102 manual prop
// MS2-PIN: ?max_size@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIV?$map@Vutf8string@efd@@UUnk_PropertyCacheEntry@@U?$less@Vutf8string@efd@@@std@@@efd@@@std@@PEAX@std@@@efd@@@std@@SA_KAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIV?$map@Vutf8string@efd@@UUnk_PropertyCacheEntry@@U?$less@Vutf8string@efd@@@std@@@efd@@@std@@PEAX@std@@@efd@@@Z 0x1413f8bf0 ; w102 manual prop (tx1: tree-node instantiation, the <char> copy is 0x140876d30)
// MS2-PIN: ?max_size@?$list@UUnk_HwiCreated@@V?$allocator@UUnk_HwiCreated@@@std@@@std@@QEBA_KXZ 0x1413f8db0 ; w102 manual unique
// MS2-PIN: ?max_size@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEBA_KXZ 0x1413f8dd0 ; w102 manual unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAUUnk_HwiCreated@@@std@@SAPEAUUnk_HwiCreated@@AEAU3@@Z 0x1413f8f70 ; w102 manual prop
// MS2-PIN: ?push_back@?$list@UUnk_HwiCreated@@V?$allocator@UUnk_HwiCreated@@@std@@@std@@QEAAX$$QEAUUnk_HwiCreated@@@Z 0x1413f9090 ; w102 manual unique
// MS2-PIN: ?push_back@?$vector@PEAVIPropertyCallback@egf@@V?$CustomAllocator@PEAVIPropertyCallback@egf@@@efd@@@std@@QEAAXAEBQEAVIPropertyCallback@egf@@@Z 0x1413f90e0 ; hand: called by IPropertyCallbackInvoker::AddPropertyCallback 0x1413eb760
// MS2-PIN: ?size@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEBA_KXZ 0x1413f9210 ; w102 manual unique
// MS2-PIN: ??_7HardwareInstancingService@@6BIPropertyCallback@egf@@@ 0x142f0c220 ; w102 manual
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@std@@@2@@Z 0x1413eff20 ; w102 manual
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@H@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@H@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@H@std@@@std@@@std@@@2@@Z 0x1413f04d0 ; w102 manual
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@std@@@std@@@2@@Z 0x1413f0a80 ; w102 manual
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1413d8f60 ; w102 manual unique
// MS2-PIN: ??$?0_KAEAPEAVDynamicInstancing@@$0A@@?$pair@_KPEAVDynamicInstancing@@@std@@QEAA@$$QEA_KAEAPEAVDynamicInstancing@@@Z 0x1413d99a0 ; w102 manual prop
// MS2-PIN: ??$?0_KAEAPEAVEntityInstancing@@$0A@@?$pair@_KPEAVEntityInstancing@@@std@@QEAA@$$QEA_KAEAPEAVEntityInstancing@@@Z 0x1413d99f0 ; w102 manual prop
// MS2-PIN: ??$?0_KAEAPEAVMeshInstancing@@$0A@@?$pair@_KPEAVMeshInstancing@@@std@@QEAA@$$QEA_KAEAPEAVMeshInstancing@@@Z 0x1413d9a40 ; w102 manual prop
// MS2-PIN: ??$?0_KPEAVDynamicInstancing@@$0A@@?$pair@$$CB_KPEAVMeshInstancing@@@std@@QEAA@$$QEAU?$pair@_KPEAVDynamicInstancing@@@1@@Z 0x1413d9a90 ; w102 manual unique
// MS2-PIN: ??$?0_KPEAVEntityInstancing@@$0A@@?$pair@$$CB_KPEAVMeshInstancing@@@std@@QEAA@$$QEAU?$pair@_KPEAVEntityInstancing@@@1@@Z 0x1413d9ae0 ; w102 manual unique
// MS2-PIN: ??$?0_KPEAVMeshInstancing@@$0A@@?$pair@$$CB_KPEAVMeshInstancing@@@std@@QEAA@$$QEAU?$pair@_KPEAVMeshInstancing@@@1@@Z 0x1413d9b30 ; w102 manual unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_HwiMapData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x1413da340 ; w102 manual prop
// MS2-PIN: ??$_Construct1@PEADAEBQEAD@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@D@efd@@PEAPEADAEBQEAD@Z 0x1413daa70 ; w102 manual prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBQEAVNiMesh@@@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@AEAAXAEBQEAVNiMesh@@@Z 0x1413dafe0 ; w102 manual unique
// MS2-PIN: ??$_Emplace_reallocate@AEBQEAVNiMesh@@@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEAAPEAPEAVNiMesh@@QEAPEAV2@AEBQEAV2@@Z 0x1413db160 ; w102 manual unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUUnk_HwiMapData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBIUUnk_HwiMapData@@@1@PEAU?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@1@@Z 0x1413de9a0 ; w102 manual prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUUnk_HwiMapData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIUUnk_HwiMapData@@@1@PEAU?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@1@@Z 0x1413e1eb0 ; w102 manual prop
// MS2-PIN: ??$_Try_emplace@AEBI$$V@?$map@IUUnk_HwiMapData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x1413e4240 ; w102 manual unique
// MS2-PIN: ??$addressof@PEAU?$_List_node@PEAVEntityInstancing@@PEAX@std@@@std@@YAPEAPEAU?$_List_node@PEAVEntityInstancing@@PEAX@0@AEAPEAU10@@Z 0x1413e4bd0 ; w102 manual unique
// MS2-PIN: ??$addressof@PEAU?$_List_node@PEAVMeshInstancing@@PEAX@std@@@std@@YAPEAPEAU?$_List_node@PEAVMeshInstancing@@PEAX@0@AEAPEAU10@@Z 0x1413e4be0 ; w102 manual unique
// MS2-PIN: ??$addressof@PEAU?$_List_node@UUnk_HwiNearby@@PEAX@std@@@std@@YAPEAPEAU?$_List_node@UUnk_HwiNearby@@PEAX@0@AEAPEAU10@@Z 0x1413e4bf0 ; w102 manual unique
// MS2-PIN: ??$addressof@PEAU?$_List_node@UUnk_HwiCreated@@PEAX@std@@@std@@YAPEAPEAU?$_List_node@UUnk_HwiCreated@@PEAX@0@AEAPEAU10@@Z 0x1413e4c10 ; w102 manual unique
// MS2-PIN: ??$construct@PEAU?$_List_node@PEAVEntityInstancing@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@PEAVEntityInstancing@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@PEAVEntityInstancing@@PEAX@std@@@1@QEAPEAU?$_List_node@PEAVEntityInstancing@@PEAX@1@AEAPEAU31@@Z 0x1413e4e30 ; w102 manual unique
// MS2-PIN: ??$construct@PEAU?$_List_node@PEAVMeshInstancing@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@PEAVMeshInstancing@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@PEAVMeshInstancing@@PEAX@std@@@1@QEAPEAU?$_List_node@PEAVMeshInstancing@@PEAX@1@AEAPEAU31@@Z 0x1413e4e80 ; w102 manual unique
// MS2-PIN: ??$construct@PEAU?$_List_node@UUnk_HwiCreated@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@1@QEAPEAU?$_List_node@UUnk_HwiCreated@@PEAX@1@AEAPEAU31@@Z 0x1413e4f70 ; w102 manual unique
// MS2-PIN: ??$construct@PEADAEBQEAD@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SAXAEAV?$CustomAllocator@D@efd@@PEAPEADAEBQEAD@Z 0x1413e5010 ; w102 manual prop
// MS2-PIN: ??$construct@PEAVNiMesh@@AEBQEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVNiMesh@@@efd@@PEAPEAVNiMesh@@AEBQEAV4@@Z 0x1413e5270 ; w102 manual prop
// MS2-PIN: ??$construct@U?$pair@$$CBIUUnk_HwiMapData@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIUUnk_HwiMapData@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x1413e5410 ; w102 manual unique
// MS2-PIN: ??$destroy@PEAU?$_List_node@PEAVEntityInstancing@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@PEAVEntityInstancing@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@PEAVEntityInstancing@@PEAX@std@@@1@QEAPEAU?$_List_node@PEAVEntityInstancing@@PEAX@1@@Z 0x1413e5a10 ; w102 manual unique
// MS2-PIN: ??$destroy@PEAU?$_List_node@PEAVMeshInstancing@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@PEAVMeshInstancing@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@PEAVMeshInstancing@@PEAX@std@@@1@QEAPEAU?$_List_node@PEAVMeshInstancing@@PEAX@1@@Z 0x1413e5a20 ; w102 manual unique
// MS2-PIN: ??$destroy@PEAU?$_List_node@UUnk_HwiNearby@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@UUnk_HwiNearby@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@UUnk_HwiNearby@@PEAX@std@@@1@QEAPEAU?$_List_node@UUnk_HwiNearby@@PEAX@1@@Z 0x1413e5a30 ; w102 manual unique
// MS2-PIN: ??$destroy@PEAD@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SAXAEAV?$CustomAllocator@D@efd@@PEAPEAD@Z 0x1413e5a70 ; w102 manual prop
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@IUUnk_HwiMapData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x1413e6030 ; w102 manual prop
// MS2-PIN: ??$forward@AEAPEAU?$_List_node@PEAVEntityInstancing@@PEAX@std@@@std@@YAAEAPEAU?$_List_node@PEAVEntityInstancing@@PEAX@0@AEAPEAU10@@Z 0x1413e6330 ; w102 manual prop
// MS2-PIN: ??$forward@AEAPEAU?$_List_node@PEAVMeshInstancing@@PEAX@std@@@std@@YAAEAPEAU?$_List_node@PEAVMeshInstancing@@PEAX@0@AEAPEAU10@@Z 0x1413e6340 ; w102 manual prop
// MS2-PIN: ??$forward@AEAPEAU?$_List_node@UUnk_HwiCreated@@PEAX@std@@@std@@YAAEAPEAU?$_List_node@UUnk_HwiCreated@@PEAX@0@AEAPEAU10@@Z 0x1413e6370 ; w102 manual prop
// MS2-PIN: ??$forward@AEBQEAD@std@@YAAEBQEADAEBQEAD@Z 0x1413e6390 ; w102 manual prop
// MS2-PIN: ??$forward@AEBU?$less@Vutf8string@efd@@@std@@@std@@YAAEBU?$less@Vutf8string@efd@@@0@AEBU10@@Z 0x1413e6570 ; hand: called by the utf8string map _Compressed_pair ctor 0x1413d90f0
// MS2-PIN: ??$forward@PEAVMeshInstancing@@@std@@YA$$QEAPEAVMeshInstancing@@AEAPEAV1@@Z 0x1413e65e0 ; w102 manual prop
// MS2-PIN: ??$make_pair@_KAEAPEAVDynamicInstancing@@@std@@YA?AU?$pair@_KPEAVDynamicInstancing@@@0@$$QEA_KAEAPEAVDynamicInstancing@@@Z 0x1413e6a70 ; w102 manual unique
// MS2-PIN: ??$make_pair@_KAEAPEAVMeshInstancing@@@std@@YA?AU?$pair@_KPEAVMeshInstancing@@@0@$$QEA_KAEAPEAVMeshInstancing@@@Z 0x1413e6b10 ; w102 manual unique
// MS2-PIN: ??0?$list@UUnk_HwiCreated@@V?$allocator@UUnk_HwiCreated@@@std@@@std@@QEAA@XZ 0x1413e8650 ; w102 manual unique
// MS2-PIN: ??1?$_List_buy@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@QEAA@XZ 0x1413e8cc0 ; w102 manual unique
// MS2-PIN: ??1?$_List_buy@PEAVMeshInstancing@@V?$allocator@PEAVMeshInstancing@@@std@@@std@@QEAA@XZ 0x1413e8ce0 ; w102 manual prop
// MS2-PIN: ??1?$_List_buy@UUnk_HwiNearby@@V?$allocator@UUnk_HwiNearby@@@std@@@std@@QEAA@XZ 0x1413e8d00 ; w102 manual prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@VAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@U?$less@VAssetID@efd@@@4@V?$allocator@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@4@$0A@@std@@@std@@QEAA@XZ 0x1413e8d90 ; w102 manual prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@VEntityID@egf@@HU?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@H@std@@@4@$0A@@std@@@std@@QEAA@XZ 0x1413e8dc0 ; w102 manual prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@VEntityID@egf@@PEAVMeshInstancing@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@5@$0A@@std@@@std@@QEAA@XZ 0x1413e8df0 ; w102 manual prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@_KPEAVMeshInstancing@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KPEAVMeshInstancing@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1413e8e50 ; w102 manual prop
// MS2-PIN: ??1?$list@UUnk_HwiNearby@@V?$allocator@UUnk_HwiNearby@@@std@@@std@@QEAA@XZ 0x1413e90f0 ; w102 manual prop
// MS2-PIN: ??1?$map@VAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@U?$less@VAssetID@efd@@@4@V?$allocator@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@4@@std@@QEAA@XZ 0x1413e91a0 ; w102 manual unique
// MS2-PIN: ??1?$map@VEntityID@egf@@HU?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@H@std@@@4@@std@@QEAA@XZ 0x1413e91c0 ; w102 manual prop
// MS2-PIN: ??1?$map@VEntityID@egf@@PEAVMeshInstancing@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@5@@std@@QEAA@XZ 0x1413e91e0 ; w102 manual prop
// MS2-PIN: ??1?$map@_KPEAVMeshInstancing@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KPEAVMeshInstancing@@@std@@@3@@std@@QEAA@XZ 0x1413e9240 ; w102 manual prop
// MS2-PIN: ??1Unk_HwiMapData@@QEAA@XZ 0x1413e9340 ; w102 manual unique
// MS2-PIN: ??8?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1413e9510 ; w102 manual prop
// MS2-PIN: ??9?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1413e9880 ; w102 manual unique
// MS2-PIN: ??D?$_List_iterator@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@std@@@std@@QEBAAEAUUnk_HwiCreated@@XZ 0x1413e9e00 ; w102 manual prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KPEAVMeshInstancing@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1413ea980 ; w102 manual unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1413eae00 ; w102 manual unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1413eaed0 ; w102 manual unique
// MS2-PIN: ?SetAt@?$CAtlMap@_KV?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@4@@ATL@@QEAAPEAU__POSITION@@_KAEBV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x1413ed240 ; w102 manual unique
// MS2-PIN: ?TypeCast@HardwareInstancingService@@UEBA_NIPEAPEAX@Z 0x1413ed430 ; w102 manual unique
// MS2-PIN: ?_Calculate_growth@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@AEBA_K_K@Z 0x1413ee650 ; w102 manual unique
// MS2-PIN: ?_Change_array@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@AEAAXQEAPEAVNiMesh@@_K1@Z 0x1413ee770 ; w102 manual unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IUUnk_HwiMapData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x1413ee9d0 ; w102 manual unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$map@Vutf8string@efd@@UUnk_PropertyCacheEntry@@U?$less@Vutf8string@efd@@@std@@@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIV?$map@Vutf8string@efd@@UUnk_PropertyCacheEntry@@U?$less@Vutf8string@efd@@@std@@@efd@@@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$map@Vutf8string@efd@@UUnk_PropertyCacheEntry@@U?$less@Vutf8string@efd@@@std@@@efd@@@std@@PEAX@2@@Z 0x1413f1dd0 ; hand: _Buynode's catch funclet; _Getal 0x1413f2c50 + node _Freenode0 0x1413db820
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x1413f2590 ; w102 manual prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@VAssetID@efd@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@VAssetID@efd@@@2@XZ 0x1413f25c0 ; w102 manual unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@VAssetID@efd@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@VAssetID@efd@@@2@XZ 0x1413f25d0 ; w102 manual unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@VEntityID@egf@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@VEntityID@egf@@@2@XZ 0x1413f2610 ; w102 manual prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KPEAVMeshInstancing@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KPEAVMeshInstancing@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_K@2@XZ 0x1413f2650 ; w102 manual unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@PEAVNiMesh@@@efd@@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@PEAVNiMesh@@@efd@@XZ 0x1413f2660 ; w102 manual unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@PEAVEntityInstancing@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@PEAVEntityInstancing@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_List_node@PEAVEntityInstancing@@PEAX@std@@@2@XZ 0x1413f26c0 ; w102 manual unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@PEAVMeshInstancing@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@PEAVMeshInstancing@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_List_node@PEAVMeshInstancing@@PEAX@std@@@2@XZ 0x1413f26e0 ; w102 manual unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@UUnk_HwiNearby@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@UUnk_HwiNearby@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_List_node@UUnk_HwiNearby@@PEAX@std@@@2@XZ 0x1413f2700 ; w102 manual unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@UUnk_HwiCreated@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_List_node@UUnk_HwiCreated@@PEAX@std@@@2@XZ 0x1413f2740 ; w102 manual unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@2@XZ 0x1413f2790 ; w102 manual prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x1413f27a0 ; w102 manual unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x1413f27b0 ; w102 manual prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@VEntityID@egf@@@std@@V?$_Vector_val@U?$_Simple_types@VEntityID@egf@@@std@@@2@$00@std@@QEAAAEAV?$allocator@VEntityID@egf@@@2@XZ 0x1413f2820 ; w102 manual unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@2@$00@2@XZ 0x1413f2880 ; w102 manual unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@VAssetID@efd@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@2@XZ 0x1413f28b0 ; w102 manual unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@VAssetID@efd@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@2@XZ 0x1413f28c0 ; w102 manual unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@VEntityID@egf@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@std@@@2@$00@2@XZ 0x1413f2900 ; w102 manual unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@std@@@2@XZ 0x1413f2a60 ; w102 manual unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@XZ 0x1413f2a70 ; w102 manual unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@std@@@2@XZ 0x1413f2a80 ; w102 manual unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KPEAVMeshInstancing@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KPEAVMeshInstancing@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KPEAVMeshInstancing@@@std@@@std@@@2@XZ 0x1413f2ae0 ; w102 manual unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_HwiMapData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_HwiMapData@@@std@@PEAX@std@@@2@XZ 0x1413f2ce0 ; w102 manual prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@VAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@U?$less@VAssetID@efd@@@4@V?$allocator@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@@4@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBVAssetID@efd@@V?$list@PEAVEntityInstancing@@V?$allocator@PEAVEntityInstancing@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x1413f2d40 ; w102 manual prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@PEAVMeshInstancing@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@5@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@PEAX@std@@@2@XZ 0x1413f2e00 ; w102 manual prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_HwiMapData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_HwiMapData@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x1413f3010 ; w102 manual prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@PEAVMeshInstancing@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@PEAVMeshInstancing@@@std@@@5@$0A@@std@@@std@@QEBAAEBU?$less@VEntityID@egf@@@2@XZ 0x1413f30f0 ; w102 manual unique
// HardwareInstancingService: the hardware instancing of the static map entities (see hardwareinstancingservice.h),
// plus the instancing configuration helpers of meshinstancing.h. The container glue of the exe (CAtlMap / std::map /
// std::list instances and the message handler templates) comes from the real templates here.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\hardwareinstancingservice.cpp"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <atlcoll.h>
#include <efd/MessageService.h>
#include <efd/ServiceManager.h>
#include <efd/Category.h>
#include <egf/Entity.h>
#include <egf/EntityChangeMessage.h>
#include <egf/FlatModel.h>
#include <egf/FlatModelManager.h>
#include <egf/PlaceableModel.h>
#include <ecr/CoreRuntimeMessages.h>
#include <ecr/RenderService.h>
#include <ecr/ShaderService.h>
#include <NiMesh.h>
#include "hardwareinstancingservice.h"
#include "entityinstancing.h"
#include "dynamicinstancing.h"
#include "entityworldmanager.h"
#include "ms2lightservice.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the entity property cache (MS2's keyed Entity::SetPropertyValue<T>) ----
// @0x1413d9bb0
template<typename T>
void Unk_HwiCachedEntity::CacheKeyedPropertyValue(egf::PropertyID propID, const efd::utf8string& key, const T& data)
{
    if (m_bCaching)
    {
        efd::map<unsigned, efd::map<efd::utf8string, Unk_PropertyCacheEntry> >::iterator it = m_mapKeyedCache.find(propID);
        if (it == m_mapKeyedCache.end())
        {
            T kOld;
            GetPropertyValueUnsafe(propID, key, &kOld, efd::GetClassIDFromType<T>());
            m_mapKeyedCache[propID][key] = Unk_PropertyCacheEntry(propID, new T(kOld), efd::GetClassIDFromType<T>());
        }
        else
        {
            efd::map<efd::utf8string, Unk_PropertyCacheEntry>::iterator itKey = it->second.find(key);
            if (itKey == it->second.end())
            {
                T kOld;
                GetPropertyValueUnsafe(propID, key, &kOld, efd::GetClassIDFromType<T>());
                it->second[key] = Unk_PropertyCacheEntry(propID, new T(kOld), efd::GetClassIDFromType<T>());
            }
        }
    }
}

// @0x1413d9ec0
template<typename T>
egf::PropertyResult Unk_HwiCachedEntity::SetPropertyValue(egf::PropertyID propID, const efd::utf8string& key, const T& data)
{
    CacheKeyedPropertyValue(propID, key, data);
    return SetPropertyValueUnsafe(propID, key, &data, efd::GetClassIDFromType<T>());
}

// ---- MeshInstancing accessors (emitted in this unit) ----
// @0x1413eb720
void Unk_MeshInstancingConfig::FUN_1413eb720()
{
    ++activeCount;
}

// @0x1413eb740
void MeshInstancing::FUN_1413eb740()
{
    config.FUN_1413eb720();
}

// @0x1413ebb00
egf::EntityID MeshInstancing::FUN_1413ebb00() const
{
    return id18;
}

// @0x1413ebb30
unsigned MeshInstancing::FUN_1413ebb30() const
{
    return config.activeCount;
}

// @0x1413ebb70
NiNode* MeshInstancing::FUN_1413ebb70() const
{
    return root;
}

// @0x1413ebb90
unsigned MeshInstancing::FUN_1413ebb90() const
{
    return capacity;
}

// @0x1413ec820
bool MeshInstancing::FUN_1413ec820() const
{
    return !config.ids.m_list.empty();
}

// @0x1413ec890
bool MeshInstancing::FUN_1413ec890() const
{
    return flag28;
}

// @0x1413ed2f0
void MeshInstancing::FUN_1413ed2f0()
{
    dirty = true;
}

// @0x1413ed300
void MeshInstancing::FUN_1413ed300(int nCount)
{
    config.activeCount = nCount;
}

// ---- services reached through globals ----
extern char DAT_143b059e8;                                          // the application framework
HardwareInstancingService* FUN_14098c5b0(char* pFramework);
EntityWorldManager* FUN_1409670f0();
class WorldService;
WorldService* FUN_1403ed2d0();
void FUN_141bbae40(WorldService* pWorld, IWorldServiceCallback* pCallback);
bool FUN_141bc7b20(void* pWorld, const egf::EntityID& id);         // is the entity drawn by the world itself
efd::MessageService* FUN_1413f9830();
ecr::RenderService* FUN_1413f9890();
class Unk_Clock { public: double FUN_141473260(); };
Unk_Clock* FUN_14086d260();
double FUN_141473280(Unk_Clock* pClock);
int FUN_140ae1c10();                                                // the current game mode
class COptimizer;
COptimizer* FUN_1409f7c90();
int FUN_14112f0b0(COptimizer* pOptimizer);
void FUN_1410db460(efd::IDependencyRegistrar* pRegistrar, unsigned n);   // <MS2 service 0x0610001a>

// ---- entities ----
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);
void FUN_1408a20a0(egf::Entity* pEntity, unsigned uPropId, bool* pOut);
void FUN_14098c6e0(egf::Entity* pEntity, unsigned uPropId, const bool& rValue);
int FUN_1409618c0(egf::Entity* pEntity, unsigned uPropId, efd::Point3* pOut);
void FUN_140961880(egf::Entity* pEntity, unsigned uPropId, float* pOut);
egf::Entity* FUN_1408a9090(const void* pSmartPointer);
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);
efd::AssetID FUN_1413fa0d0(egf::Entity* pEntity);
bool FUN_1413fa2a0(egf::Entity* pEntity);
bool FUN_1413fa2e0(egf::Entity* pEntity);
Unk_InstancingScale FUN_1413fa320(egf::Entity* pEntity);
void FUN_1413fa1b0(egf::Entity* pEntity);
bool FUN_140a56f50(const Unk_InstancingScale* pA, const Unk_InstancingScale* pB);   // differ
bool FUN_14106bee0(NiMeshModifier* pModifier);
extern NiRTTI DAT_143afbef0;                                        // the hardware skinning modifier type
extern efd::AssetID DAT_143a0acf8;                                  // the null asset

// ---- static initializers (.text$di, in this order) ----
// @0x1400f4b40
EE_IMPLEMENT_CONCRETE_CLASS_INFO(HardwareInstancingService);
#ifndef MS2_HOOK_DLL
// @0x1400f4b60
EE_HANDLER(HardwareInstancingService, FUN_1413d7570, ecr::SceneGraphAddedMessage);
// @0x1400f4bc0
EE_HANDLER_WRAP(HardwareInstancingService, FUN_1413d7710, egf::EntityChangeMessage, 8254);
// @0x1400f4c20
EE_HANDLER_WRAP(HardwareInstancingService, FUN_1413d7800, egf::EntityChangeMessage, 8196);
#endif
// @0x1400f4c80
static CString s_strSkill = "skill";
// @0x1400f4cb0
static CString s_strStun = "stun";
// @0x1400f4ce0
static const efd::Category s_catEntityChannel(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);
// @0x1400f4d10
static const egf::EntityID s_invalidId((efd::UInt64)0);
// @0x1400f4d30
static CString s_aSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400f4df0
static CString s_strSkill2 = "skill";
// @0x1400f4e20
static CString s_strStun2 = "stun";
// @0x1400f4e50
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);

// ---- the instancing configuration (meshinstancing.h) ----

// @0x1413d3000
Unk_MeshInstancingConfig::Unk_MeshInstancingConfig(egf::Entity* pEntity, int nCellSize, int nId)
    : flags30(false), flags31(false), flags32(false), unknown48(pEntity, nCellSize), unknown58(180.0f, 180.0f, 180.0f),
      unknown64(nId), activeCount(1)
{
    asset = FUN_1413fa0d0(pEntity);
    flags30 = FUN_1413fa2a0(pEntity);
    flags31 = FUN_1413fa2e0(pEntity);
    unknown58 = FUN_1413fa320(pEntity);
    FUN_1408a20a0(pEntity, 0x861681cb, &flags32);
    efd::SmartPointer<HardwareInstancingService> spService(FUN_14098c5b0(&DAT_143b059e8));
    ids = spService->FUN_1413d7160(pEntity);
}

// @0x1413d3250
Unk_MeshInstancingConfig::~Unk_MeshInstancingConfig()
{
}

// @0x1413d3290
Unk_MeshInstancingConfig& Unk_MeshInstancingConfig::operator=(const Unk_MeshInstancingConfig& other)
{
    asset = other.asset;
    flags30 = other.flags30;
    flags31 = other.flags31;
    ids = other.ids;
    unknown48 = other.unknown48;
    unknown58 = other.unknown58;
    flags32 = other.flags32;
    unknown64 = other.unknown64;
    activeCount = other.activeCount;
    return *this;
}

// @0x1413d3370
bool Unk_MeshInstancingConfig::operator==(const Unk_MeshInstancingConfig& other) const
{
    if (asset != other.asset)
        return false;
    return FUN_1413d33c0(other);
}

// @0x1413d33c0
bool Unk_MeshInstancingConfig::FUN_1413d33c0(const Unk_MeshInstancingConfig& other) const
{
    if (flags30 != other.flags30)
        return false;
    if (flags31 != other.flags31)
        return false;
    if (ids != other.ids)
        return false;
    if (!flags32 && unknown48 != other.unknown48)
        return false;
    if (FUN_140a56f50(&unknown58, &other.unknown58))
        return false;
    if (unknown64 != other.unknown64)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1413D33C0, Unk_MeshInstancingConfig, FUN_1413d33c0, 225, 0x70F8AC45);

// @0x1413d34b0
Unk_InstanceIdList::Unk_InstanceIdList()
{
}

// @0x1413d34d0
Unk_InstanceIdList::~Unk_InstanceIdList()
{
}

// @0x1413d34f0
Unk_InstanceIdList& Unk_InstanceIdList::operator=(const Unk_InstanceIdList& other)
{
    m_list = other.m_list;
    return *this;
}

// Same ids in any order.
// @0x1413d3520
bool Unk_InstanceIdList::operator==(const Unk_InstanceIdList& other) const
{
    if (m_list.size() == other.m_list.size())
    {
        for (std::list<egf::EntityID>::const_iterator it = other.m_list.begin(); it != other.m_list.end(); ++it)
        {
            if (std::find(m_list.begin(), m_list.end(), *it) == m_list.end())
                return false;
        }
        return true;
    }
    return false;
}

// @0x1413d3650
bool Unk_InstanceIdList::operator!=(const Unk_InstanceIdList& other) const
{
    return !(*this == other);
}

// @0x1413d36a0
bool Unk_InstanceIdList::operator<(const Unk_InstanceIdList& other) const
{
    if (m_list.size() == other.m_list.size())
    {
        std::list<egf::EntityID>::const_iterator itOther = other.m_list.begin();
        std::list<egf::EntityID>::const_iterator it = m_list.begin();
        while (itOther != other.m_list.end())
        {
            if (*itOther > *it || *itOther == *it)
                return false;
            ++itOther;
            ++it;
        }
    }
    return m_list.size() < other.m_list.size();
}

// @0x1413d37f0
Unk_InstancingCell::Unk_InstancingCell(egf::Entity* pEntity, int nSize)
{
    size = nSize;
    if (size != 0)
    {
        efd::Point3 kPos(0, 0, 0);
        FUN_1409618c0(pEntity, 0xfd95ca52, &kPos);
        x = (int)kPos.x / size;
        y = (int)kPos.y / size;
        z = (int)kPos.z / size;
    }
    else
    {
        x = 0;
        y = 0;
        z = 0;
    }
}

// @0x1413d38c0
Unk_InstancingCell& Unk_InstancingCell::operator=(const Unk_InstancingCell& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    size = other.size;
    return *this;
}

// @0x1413d3920
bool Unk_InstancingCell::operator==(const Unk_InstancingCell& other) const
{
    return x == other.x && y == other.y && z == other.z;
}

// @0x1413d3990
bool Unk_InstancingCell::operator!=(const Unk_InstancingCell& other) const
{
    return !(*this == other);
}

// @0x1413d39e0
bool Unk_InstancingCell::operator>=(const Unk_InstancingCell& other) const
{
    return !(x < other.x && y < other.y && z < other.z);
}

// ---- HardwareInstancingService ----

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1413d42a0
HardwareInstancingService::HardwareInstancingService()
    : m_bEnabled(false), m_bReady(false), m_bVisible(true), m_nMap(0), m_mapQueued(17, 0.75f, 0.25f, 2.25f, 10),
      m_nNextId(0)
{
}
#endif

// @0x1413d43d0
HardwareInstancingService::~HardwareInstancingService()
{
}

// @0x1413d4470
const char* HardwareInstancingService::GetDisplayName() const
{
    return "HardwareInstancingService";
}
MS2_REPLACE_METHOD(0x1413D4470, HardwareInstancingService, GetDisplayName, 13, 0x20BE739F);

// @0x1413d4490
efd::SyncResult HardwareInstancingService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    pRegistrar->AddDependency<egf::FlatModelManager>(1);
    pRegistrar->AddDependency<efd::MessageService>(1);
    pRegistrar->AddDependency<ecr::ShaderService>(1);
    FUN_1410db460(pRegistrar, 1);
    egf::PlaceableModel::AddCallback(this);
    return efd::SyncResult_Success;
}
MS2_REPLACE_METHOD(0x1413D4490, HardwareInstancingService, OnPreInit, 127, 0x5C215D93);

// @0x1413d4520
efd::AsyncResult HardwareInstancingService::OnInit()
{
    FUN_1413f9830()->Subscribe(this, s_catEntityChannel, 0, false);
    FUN_141bbae40(FUN_1403ed2d0(), this);
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD(0x1413D4520, HardwareInstancingService, OnInit, 119, 0x716913E8);

// @0x1413d45a0
efd::AsyncResult HardwareInstancingService::OnTick()
{
    FUN_1413d47b0();
    return efd::AsyncResult_Pending;
}
MS2_REPLACE_METHOD(0x1413D45A0, HardwareInstancingService, OnTick, 29, 0x19570291);

// @0x1413d45d0
efd::AsyncResult HardwareInstancingService::OnShutdown()
{
    for (std::map<unsigned, Unk_HwiMapData>::iterator it = m_maps.begin(); it != m_maps.end(); ++it)
        FUN_1413d73a0(it->first);
    m_maps.clear();
    m_pServiceManager = NULL;
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD(0x1413D45D0, HardwareInstancingService, OnShutdown, 155, 0x5E0F59A8);

// Queue an instanced entity for a refresh when its position, rotation or scale changes.
// @0x1413d4680
void HardwareInstancingService::OnPropertyUpdate(const efd::ClassID& callerID, egf::Entity* pEntity,
    const egf::PropertyID& propertyID, const egf::IProperty* pProperty, const efd::UInt32 tags)
{
    if (pEntity == NULL)
        return;
    if ((propertyID == 0xfd95ca52 || propertyID == 0x68c7c29d || propertyID == 0x2d7cad2d)
        && (IsEnabled() & m_bReady))
    {
        if (m_mapQueued.Lookup(pEntity->GetEntityIDValue()) == NULL)
        {
            if (FUN_1408a9bd0(pEntity)->ContainsProperty(0x23f9860e))
            {
                bool bInstanced = false;
                FUN_1408a20a0(pEntity, 0x23f9860e, &bInstanced);
                if (bInstanced)
                    m_mapQueued.SetAt(pEntity->GetEntityIDValue(), pEntity);
            }
        }
    }
}
MS2_REPLACE_METHOD_VIA(0x1413D4680, HardwareInstancingService, egf::IPropertyCallback, OnPropertyUpdate, 288, 0x811CBDB9);

// @0x1413d47b0
void HardwareInstancingService::FUN_1413d47b0()
{
    double dTime = FUN_141473280(FUN_14086d260());
    if (!m_mapQueued.IsEmpty())
    {
        std::set<MeshInstancing*> setDirty;
        for (POSITION pos = m_mapQueued.GetStartPosition(); pos != NULL; m_mapQueued.GetNext(pos))
        {
            egf::Entity* pEntity = FUN_1408a9090(&m_mapQueued.GetValueAt(pos));
            MeshInstancing* pInstancing = FUN_1413d66b0(pEntity);
            if (pInstancing != NULL)
            {
                if (pInstancing->FUN_140ad4bb0() == 0)
                {
                    static_cast<EntityInstancing*>(pInstancing)->FUN_1411c5f40(pEntity);
                    setDirty.insert(pInstancing);
                }
            }
        }
        for (std::set<MeshInstancing*>::iterator it = setDirty.begin(); it != setDirty.end(); ++it)
            (*it)->FUN_14147c910(dTime);
        setDirty.clear();
        m_mapQueued.RemoveAll();
    }
    for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
         it != m_maps[m_nMap].m_listInstancings.end(); ++it)
        (*it)->FUN_14147c730(dTime);
}
MS2_REPLACE_METHOD(0x1413D47B0, HardwareInstancingService, FUN_1413d47b0, 564, 0xC5162B8A);

// @0x1413d49f0
egf::EntityID HardwareInstancingService::FUN_1413d49f0(const efd::utf8string& strName, efd::AssetID& rAsset,
    bool bInstanced, NiTransform* pTransform, int nArg10, int nArg14)
{
    egf::EntityID id = FUN_1409670f0()->FUN_1411ce760(strName, rAsset, false);
    egf::Entity* pEntity = FUN_1409670f0()->FUN_1411cf440(id);
    if (pEntity == NULL)
        return s_invalidId;
    FUN_14098c6e0(pEntity, 0x2a7fd9f4, bInstanced);
    NiAVObject* pObject = FUN_141b6efc0(pEntity);
    if (pObject != NULL)
    {
        FUN_1413d84e0(pEntity, pTransform, nArg10, nArg14);
    }
    else
    {
        Unk_HwiPending kPending;
        kPending.m_id = id;
        kPending.m_pTransform = pTransform;
        kPending.m_nArg10 = nArg10;
        kPending.m_nArg14 = nArg14;
        m_listPending.push_back(kPending);
    }
    return id;
}
MS2_REPLACE_METHOD(0x1413D49F0, HardwareInstancingService, FUN_1413d49f0, 320, 0x986C43C2);

// @0x1413d4b40
MeshInstancing* HardwareInstancingService::FUN_1413d4b40(egf::Entity* pEntity, int nCellZ, unsigned nCapacity)
{
    if (pEntity == NULL)
        return NULL;
    Unk_MeshInstancingConfig kConfig(pEntity, 0, 0);
    kConfig.activeCount = 1;
    kConfig.unknown48.z = nCellZ;
    MeshInstancing* pExisting = FUN_1413d6770(kConfig);
    if (pExisting != NULL)
        return NULL;
    efd::AssetID kAsset;
    if (FUN_1413d6890(pEntity) != 0)
        return NULL;
    bool bInstanced = false;
    FUN_1408a20a0(pEntity, 0x23f9860e, &bInstanced);
    if (!bInstanced)
        return NULL;
    kAsset = FUN_1413fa0d0(pEntity);
    if (kAsset == DAT_143a0acf8)
        return NULL;
    if (FUN_1413d6c70(pEntity))
        return NULL;
    EntityInstancing* pInstancing = new EntityInstancing(kConfig);
    pInstancing->FUN_1411c5880(pEntity, nCapacity);
    m_maps[m_nMap].m_listInstancings.push_back(pInstancing);
    pInstancing->FUN_14147c830();
    m_maps[m_nMap].m_mapByValue.insert(std::make_pair(pEntity->GetEntityIDValue(), pInstancing));
    ecr::RenderService* pRender = FUN_1413f9890();
    bool bHidden = false;
    FUN_14098c6e0(pEntity, 0xa0b6b179, bHidden);
    bool bDrawn = true;
    FUN_14098c6e0(pEntity, 0x2a7fd9f4, bDrawn);
    if (!FUN_141bc7b20(FUN_1403ed2d0(), pEntity->GetEntityID()))
    {
        NiAVObject* pObject = FUN_141b6efc0(pEntity);
        pRender->RemoveRenderedEntity(pEntity, pObject);
        MS2LightService::GetInstance()->RemoveRenderedEntity(pEntity, pObject);
    }
    return pInstancing;
}
MS2_REPLACE_METHOD(0x1413D4B40, HardwareInstancingService, FUN_1413d4b40, 1171, 0x0684388E);

// @0x1413d4fe0
// MS2-FUNCTIONAL: the exe loads the needed count into ecx before the capacity compare (cmp ecx,eax); same test
int HardwareInstancingService::FUN_1413d4fe0(EntityInstancing* pInstancing, egf::Entity* pEntity)
{
    if (pInstancing == NULL || pEntity == NULL)
        return 0;
    bool bInstanced = false;
    FUN_1408a20a0(pEntity, 0x23f9860e, &bInstanced);
    if (!bInstanced)
        return 0;
    if (FUN_14112f0b0(FUN_1409f7c90()) != 0)
    {
        int nCount = pInstancing->FUN_1413ebb30();
        unsigned nNeeded = nCount + 1;
        if (nNeeded > pInstancing->FUN_1413ebb90())
            pInstancing->FUN_1411c6ae0(nCount * 2);
    }
    if (pInstancing->FUN_1411c58d0(pEntity) != 0)
    {
        pInstancing->FUN_1413eb740();
        pInstancing->FUN_14147c830();
        pInstancing->FUN_1413ed2f0();
        ecr::RenderService* pRender = FUN_1413f9890();
        bool bHidden = false;
        FUN_14098c6e0(pEntity, 0xa0b6b179, bHidden);
        bool bDrawn = true;
        FUN_14098c6e0(pEntity, 0x2a7fd9f4, bDrawn);
        if (!FUN_141bc7b20(FUN_1403ed2d0(), pEntity->GetEntityID()))
        {
            NiAVObject* pObject = FUN_141b6efc0(pEntity);
            pRender->RemoveRenderedEntity(pEntity, pObject);
            MS2LightService::GetInstance()->RemoveRenderedEntity(pEntity, pObject);
        }
        m_maps[m_nMap].m_mapByValue.insert(std::make_pair(pEntity->GetEntityIDValue(), pInstancing));
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1413D4FE0, HardwareInstancingService, FUN_1413d4fe0, 566, 0xA9A46416);

// @0x1413d5220
// MS2-FUNCTIONAL: the exe passes EntityWorldManager::FUN_1411cf540 its id by value (a copy through a stored temp
// pointer); entityworldmanager.h declares it const&
void HardwareInstancingService::FUN_1413d5220(egf::EntityID id)
{
    std::map<egf::EntityID, MeshInstancing*>::iterator itDynamic = m_maps[m_nMap].m_mapDynamic.find(id);
    if (itDynamic != m_maps[m_nMap].m_mapDynamic.end())
    {
        egf::Entity* pEntity = FUN_1409670f0()->FUN_1411cf440(id);
        efd::UInt64 uValue = pEntity->GetEntityIDValue();
        std::map<efd::UInt64, MeshInstancing*>::iterator itValue = m_maps[m_nMap].m_mapByValue.find(uValue);
        if (itValue != m_maps[m_nMap].m_mapByValue.end())
            m_maps[m_nMap].m_mapByValue.erase(itValue);
        for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
             it != m_maps[m_nMap].m_listInstancings.end(); ++it)
        {
            if (itDynamic->second == *it)
            {
                m_maps[m_nMap].m_listInstancings.erase(it);
                break;
            }
        }
        delete itDynamic->second;
        m_maps[m_nMap].m_mapDynamic.erase(itDynamic);
        FUN_1409670f0()->FUN_1411cf540(egf::EntityID(id));
    }
    else
    {
        for (std::list<Unk_HwiPending>::iterator it = m_listPending.begin(); it != m_listPending.end(); ++it)
        {
            Unk_HwiPending& rPending = *it;
            if (id == rPending.m_id)
            {
                EE_FREE(rPending.m_pTransform);
                m_listPending.erase(it);
                return;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1413D5220, HardwareInstancingService, FUN_1413d5220, 1070, 0x4753CC8C);

// @0x1413d5660
void HardwareInstancingService::FUN_1413d5660()
{
    for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
         it != m_maps[m_nMap].m_listInstancings.end(); ++it)
        (*it)->FUN_14147ccf0();
}
MS2_REPLACE_METHOD(0x1413D5660, HardwareInstancingService, FUN_1413d5660, 158, 0x9D148C04);

// Build the instancings of the current map: collect the nearby entities, group the instanced entities by asset into
// EntityInstancing objects (sharing one when the configuration matches), keep the groups of two or more and tell
// the nearby entities which instancing covers them.
// @0x1413d5710
// MS2-FUNCTIONAL: the exe stages the EntityInstancing count through ecx before passing it to FUN_1411c5880
// (mov ecx,[n]; mov r8d,ecx); no int/unsigned spelling reproduced it, everything else matches
void HardwareInstancingService::FUN_1413d5710()
{
    char szKey[0x100];
    if (!IsEnabled())
        return;
    Unk_HwiNearby kNearby;
    egf::Entity* pEntity;
    Unk_WorldEntityMap::iterator itEntity = FUN_1409670f0()->FUN_1411ce5a0();
    m_maps[m_nMap].m_listNearby.clear();
    while (FUN_1409670f0()->FUN_1411ce5f0(itEntity, pEntity))
    {
        if (FUN_1408a9bd0(pEntity) != NULL)
        {
            if (FUN_1408a9bd0(pEntity)->ContainsModel(0x2c4767f5))
            {
                if (!FUN_1408a9bd0(pEntity)->ContainsModel(0x171049c9))
                {
                    if (!FUN_1408a9bd0(pEntity)->ContainsModel(0x169ea355))
                    {
                        kNearby.m_pEntity = pEntity;
                        FUN_1409618c0(pEntity, 0xfd95ca52, &kNearby.m_kPos);
                        FUN_140961880(pEntity, 0x4871503b, &kNearby.m_fRadius);
                        m_maps[m_nMap].m_listNearby.push_back(kNearby);
                    }
                }
            }
        }
    }

    std::list<Unk_HwiCreated> listCreated;
    {
        std::map<efd::AssetID, std::list<EntityInstancing*> > mapByAsset;
        size_t nCreated = 0;
        Unk_WorldEntityMap::iterator itEntity2 = FUN_1409670f0()->FUN_1411ce5a0();
        while (FUN_1409670f0()->FUN_1411ce5f0(itEntity2, pEntity))
        {
            bool bVisible = false;
            bool bInstanced = false;
            efd::AssetID kAsset;
            FUN_1408a20a0(pEntity, 0x23f9860e, &bInstanced);
            if (!bInstanced)
                continue;
            if (FUN_1413d6890(pEntity) != 0)
                continue;
            kAsset = FUN_1413fa0d0(pEntity);
            if (kAsset == DAT_143a0acf8)
                continue;
            FUN_1408a20a0(pEntity, 0xa0b6b179, &bVisible);
            if (!bVisible)
                continue;
            bool bShared = false;
            Unk_MeshInstancingConfig kConfig(pEntity, m_maps[m_nMap].m_nCellSize, 0);
            for (std::list<EntityInstancing*>::iterator it = mapByAsset[kAsset].begin();
                 it != mapByAsset[kAsset].end(); ++it)
            {
                if ((*it)->FUN_14147cfd0(kConfig) != 0)
                {
                    if ((*it)->FUN_140ad4bb0() == 0)
                    {
                        bShared = true;
                        (*it)->FUN_1413eb740();
                        listCreated.push_back(Unk_HwiCreated(pEntity, *it));
                        break;
                    }
                }
            }
            if (!bShared && !FUN_1413d6c70(pEntity))
            {
                EntityInstancing* pInstancing = new EntityInstancing(kConfig);
                mapByAsset[kAsset].push_back(pInstancing);
                listCreated.push_back(Unk_HwiCreated(pEntity, pInstancing));
                ++nCreated;
            }
        }
        for (std::map<efd::AssetID, std::list<EntityInstancing*> >::iterator itAsset = mapByAsset.begin();
             itAsset != mapByAsset.end(); ++itAsset)
        {
            for (std::list<EntityInstancing*>::iterator it = itAsset->second.begin(); it != itAsset->second.end(); ++it)
                m_maps[m_nMap].m_listInstancings.push_back(*it);
        }
    }

    for (std::list<Unk_HwiCreated>::iterator itCreated = listCreated.begin();
         itCreated != listCreated.end(); ++itCreated)
    {
        if (itCreated->m_pInstancing->FUN_1413ebb30() > 1)
        {
            int nCount = itCreated->m_pInstancing->FUN_1413ebb30();
            itCreated->m_pInstancing->FUN_1411c5880(itCreated->m_pEntity, nCount);
            itCreated->m_pInstancing->FUN_1411c58d0(itCreated->m_pEntity);
            m_maps[m_nMap].m_mapByValue.insert(
                std::make_pair(itCreated->m_pEntity->GetEntityIDValue(), itCreated->m_pInstancing));
        }
        else
        {
            for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
                 it != m_maps[m_nMap].m_listInstancings.end(); ++it)
            {
                if (*it == itCreated->m_pInstancing)
                {
                    if ((*it)->FUN_140ad4bb0() == 0)
                    {
                        delete *it;
                        m_maps[m_nMap].m_listInstancings.erase(it);
                        break;
                    }
                }
            }
        }
    }
    listCreated.clear();

    for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
         it != m_maps[m_nMap].m_listInstancings.end(); ++it)
    {
        if (!(*it)->FUN_1413ec820())
        {
            NiAVObject* pRoot = (*it)->FUN_1413ebb70();
            pRoot->Update(0.0f, true);
            for (std::list<Unk_HwiNearby>::iterator itNear = m_maps[m_nMap].m_listNearby.begin();
                 itNear != m_maps[m_nMap].m_listNearby.end(); ++itNear)
            {
                float fRange = itNear->m_fRadius + pRoot->GetWorldBound().GetRadius();
                float fDistance = (itNear->m_kPos - pRoot->GetWorldBound().GetCenter()).Length();
                if (fDistance <= fRange)
                {
                    egf::Entity* pNear = itNear->m_pEntity;
                    sprintf(szKey, "%I64u", (*it)->FUN_1413ebb00().GetValue());
                    efd::utf8string strKey(szKey);
                    static_cast<Unk_HwiCachedEntity*>(pNear)->SetPropertyValue(0xe68ebfdf, strKey, (*it)->FUN_1413ebb00());
                }
            }
        }
        else
        {
            for (std::list<Unk_HwiNearby>::iterator itNear = m_maps[m_nMap].m_listNearby.begin();
                 itNear != m_maps[m_nMap].m_listNearby.end(); ++itNear)
            {
                if (!(*it)->FUN_14147cde0(itNear->m_pEntity->GetEntityID()))
                {
                    sprintf(szKey, "%I64u", (*it)->FUN_1413ebb00().GetValue());
                    efd::utf8string strKey(szKey);
                    static_cast<Unk_HwiCachedEntity*>(itNear->m_pEntity)->SetPropertyValue(0xe68ebfdf, strKey, (*it)->FUN_1413ebb00());
                }
            }
        }
    }

    for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
         it != m_maps[m_nMap].m_listInstancings.end(); ++it)
        (*it)->FUN_14147c830();
    FUN_1413d7040(m_bVisible);
    m_bReady = true;
    FUN_1413d6db0();
    m_maps[m_nMap].m_bLoaded = true;
}
MS2_REPLACE_METHOD(0x1413D5710, HardwareInstancingService, FUN_1413d5710, 3853, 0xD632A151);

// @0x1413d6630
void HardwareInstancingService::SetEnabled(bool bEnabled)
{
    m_bEnabled = bEnabled;
}
MS2_REPLACE_METHOD(0x1413D6630, HardwareInstancingService, SetEnabled, 23, 0xF15E3A79);

// @0x1413d6650
int HardwareInstancingService::FUN_1413d6650()
{
    return !m_maps[m_nMap].m_listInstancings.empty();
}
MS2_REPLACE_METHOD(0x1413D6650, HardwareInstancingService, FUN_1413d6650, 84, 0xF5DADACA);

// @0x1413d66b0
MeshInstancing* HardwareInstancingService::FUN_1413d66b0(egf::Entity* pEntity)
{
    if (pEntity != NULL)
    {
        efd::UInt64 uValue = pEntity->GetEntityIDValue();
        std::map<efd::UInt64, MeshInstancing*>::iterator it = m_maps[m_nMap].m_mapByValue.find(uValue);
        if (it != m_maps[m_nMap].m_mapByValue.end())
            return it->second;
    }
    return NULL;
}
MS2_REPLACE_METHOD(0x1413D66B0, HardwareInstancingService, FUN_1413d66b0, 181, 0xDE018891);

// @0x1413d6770
MeshInstancing* HardwareInstancingService::FUN_1413d6770(const Unk_MeshInstancingConfig& rConfig)
{
    for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
         it != m_maps[m_nMap].m_listInstancings.end(); ++it)
    {
        if ((*it)->FUN_14147cf90(rConfig) != 0)
            return *it;
    }
    return NULL;
}
MS2_REPLACE_METHOD(0x1413D6770, HardwareInstancingService, FUN_1413d6770, 189, 0xBC8717CD);

// @0x1413d6840
NiNode* HardwareInstancingService::FUN_1413d6840(egf::Entity* pEntity)
{
    MeshInstancing* pInstancing = FUN_1413d66b0(pEntity);
    if (pInstancing != NULL)
        return pInstancing->FUN_14147d200(pEntity);
    return NULL;
}
MS2_REPLACE_METHOD(0x1413D6840, HardwareInstancingService, FUN_1413d6840, 66, 0xD611F6F6);

// @0x1413d6890
int HardwareInstancingService::FUN_1413d6890(egf::Entity* pEntity)
{
    if (pEntity != NULL)
        return FUN_1413d7d90(pEntity->GetEntityID());
    return 0;
}
MS2_REPLACE_METHOD(0x1413D6890, HardwareInstancingService, FUN_1413d6890, 54, 0x153775AB);

// @0x1413d68d0
// MS2-FUNCTIONAL: the exe returns FUN_14147d010's result as an int (eax); meshinstancing.h declares that callee bool
bool HardwareInstancingService::FUN_1413d68d0(egf::Entity* pEntity)
{
    MeshInstancing* pInstancing = FUN_1413d66b0(pEntity);
    if (pInstancing != NULL)
        return pInstancing->FUN_14147d010(pEntity);
    return false;
}

// @0x1413d6920
bool HardwareInstancingService::FUN_1413d6920()
{
    return m_maps[m_nMap].m_nVisited == m_maps[m_nMap].m_mapExcluded.size();
}
MS2_REPLACE_METHOD(0x1413D6920, HardwareInstancingService, FUN_1413d6920, 133, 0x99718910);

// @0x1413d69b0
void HardwareInstancingService::FUN_1413d69b0(const egf::EntityID& id)
{
    std::map<egf::EntityID, int>::iterator it = m_maps[m_nMap].m_mapExcluded.find(id);
    if (it != m_maps[m_nMap].m_mapExcluded.end())
    {
        m_maps[m_nMap].m_mapExcluded[id] = 1;
        ++m_maps[m_nMap].m_nVisited;
    }
}
MS2_REPLACE_METHOD(0x1413D69B0, HardwareInstancingService, FUN_1413d69b0, 245, 0x58BC72AD);

// @0x1413d6ab0
void HardwareInstancingService::FUN_1413d6ab0(bool bShow)
{
    for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
         it != m_maps[m_nMap].m_listInstancings.end(); ++it)
        (*it)->FUN_14147ca20(bShow);
}
MS2_REPLACE_METHOD(0x1413D6AB0, HardwareInstancingService, FUN_1413d6ab0, 167, 0x490BD059);

// @0x1413d6b60
bool HardwareInstancingService::FUN_1413d6b60(egf::Entity* pEntity)
{
    if (pEntity != NULL)
    {
        bool bHasAsset = FUN_1413fa0d0(pEntity) != DAT_143a0acf8;
        if (bHasAsset)
        {
            bool bVisible = false;
            bool bInstanced = false;
            FUN_1408a20a0(pEntity, 0x23f9860e, &bInstanced);
            FUN_1408a20a0(pEntity, 0xa0b6b179, &bVisible);
            if (bVisible & bInstanced)
                return !FUN_1413d6c70(pEntity);
        }
    }
    return false;
}
MS2_REPLACE(0x1413D6B60, HardwareInstancingService::FUN_1413d6b60, 264, 0x256AA7F4);

// @0x1413d6c70
bool HardwareInstancingService::FUN_1413d6c70(egf::Entity* pEntity)
{
    NiAVObject* pObject = FUN_141b6efc0(pEntity);
    if (pObject != NULL)
    {
        efd::vector<NiMesh*> kMeshes;
        EntityHelper::SceneGraphMeshFunctor<NiMesh> kFunctor(kMeshes);
        EntityHelper::Traverse(pObject, kFunctor);
        efd::vector<NiMesh*>& rMeshes = kMeshes;
        efd::vector<NiMesh*>::BaseClass::const_iterator itEnd = rMeshes.end();
        efd::vector<NiMesh*>::BaseClass::const_iterator it = rMeshes.begin();
        for (; it != itEnd; ++it)
        {
            NiMesh* pMesh = *it;
            NiMeshModifier* pModifier = pMesh->GetModifierByType(&DAT_143afbef0);
            if (pModifier != NULL && !FUN_14106bee0(pModifier))
                return true;
        }
        return false;
    }
    return false;
}
MS2_REPLACE(0x1413D6C70, HardwareInstancingService::FUN_1413d6c70, 312, 0xB1B941B1);

// @0x1413d6db0
void HardwareInstancingService::FUN_1413d6db0()
{
    for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
         it != m_maps[m_nMap].m_listInstancings.end(); ++it)
        (*it)->FUN_14147caa0();
}
MS2_REPLACE_METHOD(0x1413D6DB0, HardwareInstancingService, FUN_1413d6db0, 158, 0x0D8D0CE2);

// @0x1413d6e60
int HardwareInstancingService::FUN_1413d6e60(egf::Entity* pEntity, bool bFlag)
{
    if (IsEnabled() && m_bReady && pEntity != NULL)
    {
        bool bInstanced = false;
        FUN_1408a20a0(pEntity, 0x23f9860e, &bInstanced);
        MeshInstancing* pInstancing;
        if (bInstanced && (pInstancing = FUN_1413d66b0(pEntity)) != NULL && pInstancing->FUN_140ad4bb0() == 0)
        {
            static_cast<EntityInstancing*>(pInstancing)->FUN_1411c5e30(pEntity, bFlag);
            pInstancing->FUN_14147c910(FUN_141473280(FUN_14086d260()));
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1413D6E60, HardwareInstancingService, FUN_1413d6e60, 206, 0xBE549D35);

// @0x1413d6f40
int HardwareInstancingService::FUN_1413d6f40(egf::Entity* pEntity)
{
    MeshInstancing* pInstancing;
    if ((IsEnabled() & m_bReady) && (pInstancing = FUN_1413d66b0(pEntity)) != NULL
        && pInstancing->FUN_140ad4bb0() == 0)
    {
        static_cast<EntityInstancing*>(pInstancing)->FUN_1411c6030(pEntity);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1413D6F40, HardwareInstancingService, FUN_1413d6f40, 113, 0x12BC64AA);

// @0x1413d6fc0
int HardwareInstancingService::FUN_1413d6fc0(egf::Entity* pEntity)
{
    MeshInstancing* pInstancing;
    if ((IsEnabled() & m_bReady) && (pInstancing = FUN_1413d66b0(pEntity)) != NULL
        && pInstancing->FUN_140ad4bb0() == 0)
        return static_cast<EntityInstancing*>(pInstancing)->FUN_1411c6390(pEntity, true);
    return 0;
}
MS2_REPLACE_METHOD(0x1413D6FC0, HardwareInstancingService, FUN_1413d6fc0, 111, 0xED51C0F4);

// @0x1413d7040
void HardwareInstancingService::FUN_1413d7040(bool bVisible)
{
    for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
         it != m_maps[m_nMap].m_listInstancings.end(); ++it)
    {
        (*it)->FUN_14147d0c0(bVisible);
        if ((*it)->FUN_1413ec890())
        {
            bool bShow = (FUN_140ae1c10() == 4) & bVisible;
            (*it)->FUN_14147d180(bShow);
        }
    }
    m_bVisible = bVisible;
}
MS2_REPLACE_METHOD(0x1413D7040, HardwareInstancingService, FUN_1413d7040, 276, 0xE5740C79);

// @0x1413d7160
Unk_InstanceIdList HardwareInstancingService::FUN_1413d7160(egf::Entity* pEntity)
{
    Unk_InstanceIdList listIds;
    if (!m_maps[m_nMap].m_listNearby.empty())
    {
        efd::Point3 kUnused;
        NiAVObject* pObject = FUN_141b6efc0(pEntity);
        if (pObject != NULL)
        {
            for (std::list<Unk_HwiNearby>::iterator it = m_maps[m_nMap].m_listNearby.begin();
                 it != m_maps[m_nMap].m_listNearby.end(); ++it)
            {
                float fRange = it->m_fRadius + pObject->GetWorldBound().GetRadius();
                if ((it->m_kPos - pObject->GetWorldTranslate()).Length() <= fRange)
                    listIds.m_list.push_back(it->m_pEntity->GetEntityID());
            }
        }
    }
    return listIds;
}
MS2_REPLACE_METHOD(0x1413D7160, HardwareInstancingService, FUN_1413d7160, 503, 0x74A853C2);

// @0x1413d7360
bool HardwareInstancingService::FUN_1413d7360()
{
    return m_maps[m_nMap].m_bLoaded;
}
MS2_REPLACE_METHOD(0x1413D7360, HardwareInstancingService, FUN_1413d7360, 46, 0x63B881CC);

// @0x1413d73a0
void HardwareInstancingService::FUN_1413d73a0(unsigned nMap)
{
    m_maps[nMap].m_bLoaded = false;
    m_maps[nMap].m_nCellSize = 0;
    m_maps[nMap].m_listNearby.clear();
    m_maps[nMap].m_mapExcluded.clear();
    for (std::list<MeshInstancing*>::iterator it = m_maps[nMap].m_listInstancings.begin();
         it != m_maps[nMap].m_listInstancings.end(); ++it)
        delete *it;
    m_maps[nMap].m_listInstancings.clear();
    m_maps[nMap].m_mapByValue.clear();
    m_maps[nMap].m_mapDynamic.clear();
}
MS2_REPLACE_METHOD(0x1413D73A0, HardwareInstancingService, FUN_1413d73a0, 447, 0x38A9F97E);

// A dynamic instancing request whose entity just got its scene graph.
// @0x1413d7570
void HardwareInstancingService::FUN_1413d7570(const ecr::SceneGraphAddedMessage* pMsg, efd::Category targetChannel)
{
    if (!m_listPending.empty())
    {
        if (pMsg->GetEntity() != NULL)
        {
            for (std::list<Unk_HwiPending>::iterator it = m_listPending.begin(); it != m_listPending.end(); ++it)
            {
                Unk_HwiPending& rPending = *it;
                if (pMsg->GetEntity()->GetEntityID() == rPending.m_id)
                {
                    FUN_1413d84e0(pMsg->GetEntity(), rPending.m_pTransform, rPending.m_nArg10, rPending.m_nArg14);
                    m_listPending.erase(it);
                    break;
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1413D7570, HardwareInstancingService, FUN_1413d7570, 405, 0xA8F11BFF);

// @0x1413d7710
void HardwareInstancingService::FUN_1413d7710(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel)
{
    if (IsEnabled() & m_bReady)
    {
        bool bInstanced = false;
        FUN_1408a20a0(pMsg->GetEntity(), 0x23f9860e, &bInstanced);
        if (bInstanced)
        {
            MeshInstancing* pInstancing = FUN_1413d66b0(pMsg->GetEntity());
            if (pInstancing != NULL)
            {
                if (pInstancing->FUN_140ad4bb0() == 0)
                    static_cast<EntityInstancing*>(pInstancing)->FUN_1411c6030(pMsg->GetEntity());
            }
            m_mapQueued.RemoveKey(pMsg->GetEntity()->GetEntityIDValue());
        }
    }
}
MS2_REPLACE_METHOD(0x1413D7710, HardwareInstancingService, FUN_1413d7710, 226, 0xF03B7653);

// @0x1413d7800
void HardwareInstancingService::FUN_1413d7800(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel)
{
    if (IsEnabled() & m_bReady)
    {
        egf::Entity* pEntity = pMsg->GetEntity();
        if (pEntity != NULL)
        {
            if (pEntity->IsDirty(0x23f9860e))
            {
                bool bInstanced = false;
                FUN_1408a20a0(pEntity, 0x23f9860e, &bInstanced);
                if (bInstanced)
                {
                    MeshInstancing* pInstancing = FUN_1413d66b0(pEntity);
                    if (pInstancing != NULL)
                    {
                        if (pInstancing->FUN_140ad4bb0() == 0)
                            static_cast<EntityInstancing*>(pInstancing)->FUN_1411c5f40(pEntity);
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1413D7800, HardwareInstancingService, FUN_1413d7800, 212, 0xD5098918);

// @0x1413d78e0
void HardwareInstancingService::FUN_1413d78e0(egf::Entity* pEntity)
{
    if (pEntity != NULL)
    {
        if (IsEnabled() && m_bReady)
        {
            MeshInstancing* pInstancing = FUN_1413d66b0(pEntity);
            if (pInstancing != NULL)
            {
                if (pInstancing->FUN_140ad4bb0() == 0)
                    static_cast<EntityInstancing*>(pInstancing)->FUN_1411c5f40(pEntity);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1413D78E0, HardwareInstancingService, FUN_1413d78e0, 114, 0x4E6F4AAB);

// @0x1413d7960
void HardwareInstancingService::vfunc_0(int nMap)
{
    m_bReady = false;
    m_nMap = nMap;
}
MS2_REPLACE_METHOD_VIA(0x1413D7960, HardwareInstancingService, IWorldServiceCallback, vfunc_0, 31, 0x43C64CC5);

// @0x1413d7990 functional: the exe's slot takes the map id unsigned (passes &nMap straight to m_maps[]); the shared
// IWorldServiceCallback placeholder declares int, so m_maps[nMap] converts through a temporary here.
void HardwareInstancingService::vfunc_3(int nMap)
{
    m_bReady = false;
    std::vector<egf::EntityID> vecIds;
    for (std::map<egf::EntityID, MeshInstancing*>::iterator it = m_maps[nMap].m_mapDynamic.begin();
         it != m_maps[nMap].m_mapDynamic.end(); ++it)
        vecIds.push_back(it->first);
    std::vector<egf::EntityID>& rIds = vecIds;
    std::vector<egf::EntityID>::const_iterator itIdEnd = rIds.end();
    std::vector<egf::EntityID>::const_iterator itId = rIds.begin();
    for (; itId != itIdEnd; ++itId)
    {
        egf::EntityID id = *itId;
        FUN_1413d5220(id);
    }
    for (std::list<MeshInstancing*>::iterator it = m_maps[nMap].m_listInstancings.begin();
         it != m_maps[nMap].m_listInstancings.end(); ++it)
    {
        if ((*it)->FUN_140ad4bb0() == 0)
            static_cast<EntityInstancing*>(*it)->FUN_1411c66e0();
    }
    SetEnabled(false);
    m_mapQueued.RemoveAll();
    m_listPending.clear();
    m_maps[nMap].m_mapDynamic.clear();
    m_maps[nMap].m_nVisited = 0;
    for (std::map<egf::EntityID, int>::iterator it = m_maps[nMap].m_mapExcluded.begin();
         it != m_maps[nMap].m_mapExcluded.end(); ++it)
        it->second = 0;
    m_nNextId = 0;
}
MS2_REPLACE_METHOD_VIA(0x1413D7990, HardwareInstancingService, IWorldServiceCallback, vfunc_3, 849, 0x242AF35E);

// @0x1413d7cf0
void HardwareInstancingService::vfunc_1(int nMap)
{
}
MS2_REPLACE_METHOD_VIA(0x1413D7CF0, HardwareInstancingService, IWorldServiceCallback, vfunc_1, 10, 0x96F6F902);

// @0x1413d7d00
void HardwareInstancingService::vfunc_4(int nMap)
{
}
MS2_REPLACE_METHOD_VIA(0x1413D7D00, HardwareInstancingService, IWorldServiceCallback, vfunc_4, 10, 0x96F6F902);

// @0x1413d7d10
void HardwareInstancingService::FUN_1413d7d10(const egf::EntityID& id)
{
    m_maps[m_nMap].m_mapExcluded.insert(std::make_pair(id, 0));
}
MS2_REPLACE_METHOD(0x1413D7D10, HardwareInstancingService, FUN_1413d7d10, 116, 0xE39B6C0F);

// @0x1413d7d90
int HardwareInstancingService::FUN_1413d7d90(const egf::EntityID& id)
{
    return m_maps[m_nMap].m_mapExcluded.find(id) != m_maps[m_nMap].m_mapExcluded.end();
}
MS2_REPLACE_METHOD(0x1413D7D90, HardwareInstancingService, FUN_1413d7d90, 150, 0x6F78B170);

// @0x1413d7e30
int HardwareInstancingService::FUN_1413d7e30()
{
    return m_maps[m_nMap].m_nCellSize;
}
MS2_REPLACE_METHOD(0x1413D7E30, HardwareInstancingService, FUN_1413d7e30, 46, 0xED6BF537);

// @0x1413d7e70
void HardwareInstancingService::FUN_1413d7e70(int nCellSize)
{
    m_maps[m_nMap].m_nCellSize = nCellSize;
}
MS2_REPLACE_METHOD(0x1413D7E70, HardwareInstancingService, FUN_1413d7e70, 54, 0x0E7A3DD3);

// @0x1413d7eb0
unsigned HardwareInstancingService::FUN_1413d7eb0()
{
    return m_maps[m_nMap].m_listInstancings.size();
}
MS2_REPLACE_METHOD(0x1413D7EB0, HardwareInstancingService, FUN_1413d7eb0, 55, 0x2FC185CC);

// Show only the instancings before nIndex (or only the nIndex-th one, counted from 1).
// @0x1413d7ef0
MeshInstancing* HardwareInstancingService::FUN_1413d7ef0(int nIndex, bool bOnly)
{
    int i = 0;
    MeshInstancing* pLast = NULL;
    if (!bOnly)
    {
        for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
             it != m_maps[m_nMap].m_listInstancings.end(); ++it)
        {
            if (i < nIndex)
                pLast = *it;
            (*it)->FUN_14147ca20(i < nIndex);
            ++i;
        }
    }
    else
    {
        i = 1;
        for (std::list<MeshInstancing*>::iterator it = m_maps[m_nMap].m_listInstancings.begin();
             it != m_maps[m_nMap].m_listInstancings.end(); ++it)
        {
            if (i == nIndex)
                pLast = *it;
            (*it)->FUN_14147ca20(i == nIndex);
            ++i;
        }
    }
    return pLast;
}
MS2_REPLACE_METHOD(0x1413D7EF0, HardwareInstancingService, FUN_1413d7ef0, 495, 0xD79FC9A0);

// @0x1413d80f0
MeshInstancing* HardwareInstancingService::FUN_1413d80f0(egf::Entity* pEntity)
{
    if (pEntity == NULL)
        return NULL;
    efd::AssetID kAsset = FUN_1413fa0d0(pEntity);
    if (kAsset == DAT_143a0acf8)
        return NULL;
    Unk_MeshInstancingConfig kConfig(pEntity, m_maps[m_nMap].m_nCellSize, 0);
    MeshInstancing* pInstancing = FUN_1413d6770(kConfig);
    if (pInstancing == NULL)
    {
        pInstancing = new EntityInstancing(kConfig);
        pInstancing->FUN_1413ed300(0x4000);
        static_cast<EntityInstancing*>(pInstancing)->FUN_1411c5880(pEntity, 0x4000);
        m_maps[m_nMap].m_listInstancings.push_back(pInstancing);
        pInstancing->FUN_14147c830();
    }
    if (pInstancing->FUN_140ad4bb0() != 0)
        return NULL;
    static_cast<EntityInstancing*>(pInstancing)->FUN_1411c58d0(pEntity);
    static_cast<EntityInstancing*>(pInstancing)->FUN_1411c5f40(pEntity);
    if (pInstancing != NULL)
        m_maps[m_nMap].m_mapByValue.insert(std::make_pair(pEntity->GetEntityIDValue(), pInstancing));
    bool bHidden = false;
    FUN_14098c6e0(pEntity, 0xa0b6b179, bHidden);
    FUN_1413fa1b0(pEntity);
    return pInstancing;
}
MS2_REPLACE_METHOD(0x1413D80F0, HardwareInstancingService, FUN_1413d80f0, 753, 0x9E137AF4);

// @0x1413d83f0
void HardwareInstancingService::FUN_1413d83f0(egf::Entity* pEntity)
{
    if (pEntity == NULL)
        return;
    efd::AssetID kAsset = FUN_1413fa0d0(pEntity);
    if (kAsset == DAT_143a0acf8)
        return;
    MeshInstancing* pInstancing = FUN_1413d66b0(pEntity);
    if (pInstancing != NULL)
        pInstancing->FUN_14147c910(FUN_14086d260()->FUN_141473260());
}
MS2_REPLACE_METHOD(0x1413D83F0, HardwareInstancingService, FUN_1413d83f0, 195, 0xBD0271EA);

// @0x1413d84c0
bool HardwareInstancingService::IsEnabled()
{
    return m_bEnabled;
}
MS2_REPLACE_METHOD(0x1413D84C0, HardwareInstancingService, IsEnabled, 15, 0x0A82FF79);

// @0x1413d84e0
bool HardwareInstancingService::FUN_1413d84e0(egf::Entity* pEntity, NiTransform* pTransform, int nArg10, int nArg14)
{
    int nId = ++m_nNextId;
    Unk_MeshInstancingConfig kConfig(pEntity, m_maps[m_nMap].m_nCellSize, nId);
    if (!FUN_1413d6c70(pEntity))
    {
        DynamicInstancing* pInstancing = new DynamicInstancing(kConfig);
        m_maps[m_nMap].m_listInstancings.push_back(pInstancing);
        if (pInstancing->FUN_141194330(pEntity, nArg14, nArg10, pTransform))
        {
            if (!pInstancing->FUN_1413ec820())
            {
                NiNode* pRoot = pInstancing->FUN_1413ebb70();
                for (std::list<Unk_HwiNearby>::iterator it = m_maps[m_nMap].m_listNearby.begin();
                     it != m_maps[m_nMap].m_listNearby.end(); ++it)
                {
                    float fRange = it->m_fRadius + pRoot->GetWorldBound().GetRadius();
                    float fDistance = (it->m_kPos - pRoot->GetWorldBound().GetCenter()).Length();
                    if (fDistance <= fRange)
                    {
                        egf::Entity* pNear = it->m_pEntity;
                        char szKey[0x100];
                        sprintf(szKey, "%I64u", pInstancing->FUN_1413ebb00().GetValue());
                        efd::utf8string strKey(szKey);
                        static_cast<Unk_HwiCachedEntity*>(pNear)->SetPropertyValue(0xe68ebfdf, strKey, pInstancing->FUN_1413ebb00());
                    }
                }
            }
            pInstancing->FUN_14147c830();
            pInstancing->FUN_14147caa0();
            m_maps[m_nMap].m_mapByValue.insert(std::make_pair(pEntity->GetEntityIDValue(), pInstancing));
            m_maps[m_nMap].m_mapDynamic.insert(std::make_pair(pEntity->GetEntityID(), pInstancing));
            return true;
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x1413D84E0, HardwareInstancingService, FUN_1413d84e0, 1246, 0xEF4D8B6E);
// MS2-PIN: ?begin@?$vector@VEntityID@egf@@V?$allocator@VEntityID@egf@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@VEntityID@egf@@@std@@@std@@@2@XZ 0x1413f6150 ; vector<EntityID> iterator accessor copy (strict auto-pairing misses it)
// MS2-PIN: ?end@?$vector@VEntityID@egf@@V?$allocator@VEntityID@egf@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@VEntityID@egf@@@std@@@std@@@2@XZ 0x1413f7700 ; vector<EntityID> iterator accessor copy (strict auto-pairing misses it)
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb1430-0x142cb1580 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x1413eb720, Unk_MeshInstancingConfig, FUN_1413eb720, 24, 0x83E9AC83);
MS2_REPLACE_METHOD(0x1413eb740, MeshInstancing, FUN_1413eb740, 31, 0xCCFBBD0B);
MS2_REPLACE_METHOD(0x1413ebb30, MeshInstancing, FUN_1413ebb30, 17, 0xB518FD33);
MS2_REPLACE_METHOD(0x1413ebb70, MeshInstancing, FUN_1413ebb70, 31, 0xF5647058);
MS2_REPLACE_METHOD(0x1413ebb90, MeshInstancing, FUN_1413ebb90, 14, 0xA25B27BF);
MS2_REPLACE_METHOD(0x1413ec820, MeshInstancing, FUN_1413ec820, 61, 0xDAF38CA1);
MS2_REPLACE_METHOD(0x1413ec890, MeshInstancing, FUN_1413ec890, 15, 0x32C862F5);
MS2_REPLACE_METHOD(0x1413ed2f0, MeshInstancing, FUN_1413ed2f0, 15, 0x7CF2C742);
MS2_REPLACE_METHOD(0x1413ed300, MeshInstancing, FUN_1413ed300, 25, 0x9EB3CF4F);
MS2_REPLACE_METHOD(0x1413d68d0, HardwareInstancingService, FUN_1413d68d0, 66, 0xFE5168AF);

