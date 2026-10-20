// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 4 of commonstruct.cpp: the COMDAT tail
// 0x140287f50-0x14028b820 (std::vector/list/_Tree internals, TPtr Release/DecRef, allocator members). The
// instantiations are in commonstruct_tail.inl (shared with part 3).
// MS2-UNIT: commonfiles\commonstruct.cpp#4
// MS2-GUESS-LOOKALIKES
// The boxed history list's vftable (RTTI TPtredDummy<CAtlList<TPtr<CUserLimitHistory>>>; emitted here as in part 3):
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@6B@ 0x142d15c08
// MS2-PIN: ?floor@@YAMM@Z 0x14028aed0
// MS2-PIN: memcpy_s 0x14028b5b0
// MS2-RANGE: 0x140287f50-0x14028b820 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@2@XZ 0x140287fb0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCPtred@@@@@std@@@2@XZ 0x140287fd0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@2@XZ 0x140287ff0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@_J@std@@@2@XZ 0x140288010 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCPtred@@@@@std@@@2@XZ 0x140288030 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@V?$MS2Ptr@VCUserChangeableItemHistory@@@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VCUserChangeableItemHistory@@@@PEAX@std@@@2@XZ 0x140288070 ; order
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@XZ 0x1402880a0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@_J@std@@V?$_Vector_val@U?$_Simple_types@_J@std@@@2@$00@std@@QEBAAEBV?$allocator@_J@2@XZ 0x1402880c0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCPtred@@@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VCPtred@@@@@2@XZ 0x140288110 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@2@XZ 0x140288120 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCPtred@@@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VCPtred@@@@@2@XZ 0x140288140 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@XZ 0x140288150 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@XZ 0x140288160 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Vector_val@U?$_Simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@2@XZ 0x1402881f0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Vector_val@U?$_Simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@2@XZ 0x140288200 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@2@XZ 0x140288220 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@_J@std@@V?$_Vector_val@U?$_Simple_types@_J@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@_J@std@@@2@XZ 0x140288230 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCPtred@@@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCPtred@@@@@std@@@2@XZ 0x140288240 ; prop
// MS2-PIN: ?_Getal@?$_List_alloc@U?$_List_base_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@V?$allocator@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@@std@@QEAAAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VCUserChangeableItemHistory@@@@PEAX@std@@@2@XZ 0x140288250 ; order
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@XZ 0x1402882c0 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEBAAEBV?$allocator@_J@2@XZ 0x140288310 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@@std@@QEBAAEBV?$allocator@UItemEntity@@@2@XZ 0x140288350 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEAAAEAV?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x140288370 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBAAEBV?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x140288390 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VCPtred@@@@@2@XZ 0x1402883b0 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@2@XZ 0x1402883d0 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VCPtred@@@@@2@XZ 0x140288410 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x140288430 ; order
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x140288450 ; order
// MS2-PIN: ?_Has_unused_capacity@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEBA_NXZ 0x140288470 ; prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@AEBA_NXZ 0x140288510 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x1402885e0 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHH@2@@Z 0x140288610 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x140288640 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@PEAU32@@Z 0x1402887e0 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@PEAU32@@Z 0x140288810 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCPtred@@@@XZ 0x140288840 ; probe
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEBAAEBQEA_JXZ 0x140288860 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCIngredientInfo@@@@XZ 0x140288900 ; probe
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VCIngredientInfo@@@@XZ 0x140288920 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEAAAEAPEA_JXZ 0x140288940 ; probe
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VCPtred@@@@XZ 0x140288960 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEBAAEBQEA_JXZ 0x1402889a0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCPtred@@@@XZ 0x140288a40 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEAAAEAPEA_JXZ 0x140288ae0 ; probe
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEBAAEBQEA_JXZ 0x140288b00 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCPtred@@@@XZ 0x140288ba0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VCPtred@@@@XZ 0x140288c00 ; prop
// MS2-PIN: ??C?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UItemEntity@@@std@@@std@@@std@@QEBAPEAUItemEntity@@XZ 0x140288c60 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEAAXXZ 0x140288cc0 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEBAXPEAUItemEntity@@0@Z 0x140288d00 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEBAXPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x140288d10 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@V?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCCompactControlSkill@@@@V?$CElementTraits@V?$MS2Ptr@VCCompactControlSkill@@@@@ATL@@@ATL@@@@@@AEAAXXZ 0x140288dd0 ; order
// MS2-PIN: ?Release@?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@AEAAXXZ 0x140288e10 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VAdditionalEffectEventCtx@@@@AEAAXXZ 0x140288e50 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VCAdditionalEvent@@@@AEAAXXZ 0x140288e90 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VCIngredientInfo@@@@AEAAXXZ 0x140288ed0 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VCPtred@@@@AEAAXXZ 0x140288f10 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VCUserChangeableItemHistory@@@@AEAAXXZ 0x140288f50 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VCUserLimitHistory@@@@AEAAXXZ 0x140288f90 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VChangeableProductInfo@@@@AEAAXXZ 0x140288fd0 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VInvokeEffectOption@@@@AEAAXXZ 0x140289010 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VNpcShopItemLife@@@@AEAAXXZ 0x140289050 ; order
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x140289090 ; order
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAUItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEAAPEAUItemEntity@@XZ 0x1402890b0 ; prop
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCIngredientInfo@@@@XZ 0x1402890d0 ; order
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCPtred@@@@XZ 0x1402890f0 ; order
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEA_JV?$allocator@_J@std@@@std@@QEAAPEA_JXZ 0x140289110 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@V?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCCompactControlSkill@@@@V?$CElementTraits@V?$MS2Ptr@VCCompactControlSkill@@@@@ATL@@@ATL@@@@@@AEAAXPEAX@Z 0x140289130 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VAdditionalEffectEventCtx@@@@AEAAXPEAX@Z 0x1402891d0 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCAdditionalEvent@@@@AEAAXPEAX@Z 0x140289220 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCIngredientInfo@@@@AEAAXPEAX@Z 0x140289270 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCPtred@@@@AEAAXPEAX@Z 0x1402892c0 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCUserChangeableItemHistory@@@@AEAAXPEAX@Z 0x140289310 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCUserLimitHistory@@@@AEAAXPEAX@Z 0x140289360 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VChangeableProductInfo@@@@AEAAXPEAX@Z 0x1402893b0 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VInvokeEffectOption@@@@AEAAXPEAX@Z 0x140289400 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VNpcShopItemLife@@@@AEAAXPEAX@Z 0x140289450 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x1402894c0 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x1402894e0 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x1402895f0 ; unique
// MS2-PIN: ?_Tidy@?$list@V?$MS2Ptr@VCUserChangeableItemHistory@@@@V?$allocator@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@QEAAXXZ 0x140289650 ; prop
// MS2-PIN: ?_Tidy@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEAAXXZ 0x140289740 ; prop
// MS2-PIN: ?_Tidy@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEAAXXZ 0x140289810 ; prop
// MS2-PIN: ?_Umove@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEAAPEAUItemEntity@@PEAU3@00@Z 0x140289a80 ; prop
// MS2-PIN: ?_Umove@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEAAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAV34@00@Z 0x140289ac0 ; prop
// MS2-PIN: ?_Ufill@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEAAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAV34@_KAEBV34@@Z 0x140289b80 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCPtred@@@@00U?$integral_constant@_N$0A@@2@@Z 0x140289bc0 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEAAXPEAUItemEntity@@00@Z 0x140289c00 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCPtred@@@@00@Z 0x140289cc0 ; prop
// MS2-PIN: ?_Unchecked_end@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCIngredientInfo@@@@XZ 0x140289dc0 ; prop
// MS2-PIN: ?_Unused_capacity@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@AEBA_KXZ 0x140289e50 ; prop
// MS2-PIN: ?begin@?$initializer_list@_J@std@@QEBAPEB_JXZ 0x140289e90 ; order
// MS2-PIN: ?_Xlength@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@CAXXZ 0x140289ec0 ; prop
// MS2-PIN: ?_Xlength@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@CAXXZ 0x140289ee0 ; prop
// MS2-PIN: ?_Xlength@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@CAXXZ 0x140289f00 ; prop
// MS2-PIN: ?_Xrange@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@CAXXZ 0x140289f40 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x140289f90 ; prop
// MS2-PIN: ?allocate@?$allocator@_J@std@@QEAAPEA_J_K@Z 0x140289fc0 ; prop
// MS2-PIN: ?allocate@?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@QEAAPEAV?$MS2Ptr@VCIngredientInfo@@@@_K@Z 0x14028a050 ; probe
// MS2-PIN: ?allocate@?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@QEAAPEAV?$MS2Ptr@VCPtred@@@@_K@Z 0x14028a080 ; probe
// MS2-PIN: ?at@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@QEBAAEBV?$MS2Ptr@VCIngredientInfo@@@@_K@Z 0x14028a0f0 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@XZ 0x14028a130 ; unique
// MS2-PIN: ?begin@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UItemEntity@@@std@@@std@@@2@XZ 0x14028a200 ; prop
// MS2-PIN: ?begin@?$vector@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@2@XZ 0x14028a260 ; prop
// MS2-PIN: ?capacity@?$vector@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@QEBA_KXZ 0x14028a3d0 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x14028a410 ; unique
// MS2-PIN: ?clear@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEAAXXZ 0x14028a590 ; prop
// MS2-PIN: ?clear@?$vector@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@QEAAXXZ 0x14028a610 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$MS2Ptr@VCUserChangeableItemHistory@@@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VCUserChangeableItemHistory@@@@PEAX@std@@@2@QEAU?$_List_node@V?$MS2Ptr@VCUserChangeableItemHistory@@@@PEAX@2@_K@Z 0x14028a710 ; order
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x14028a740 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_List_node@V?$MS2Ptr@VCUserChangeableItemHistory@@@@PEAX@std@@@std@@QEAAXQEAU?$_List_node@V?$MS2Ptr@VCUserChangeableItemHistory@@@@PEAX@2@_K@Z 0x14028a770 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x14028a7a0 ; order
// MS2-PIN: ?deallocate@?$allocator@_J@std@@QEAAXQEA_J_K@Z 0x14028a7d0 ; unique
// MS2-PIN: ?deallocate@?$allocator@UItemEntity@@@std@@QEAAXQEAUItemEntity@@_K@Z 0x14028a800 ; unique
// MS2-PIN: ?deallocate@?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@QEAAXQEAV?$MS2Ptr@VCIngredientInfo@@@@_K@Z 0x14028a860 ; order
// MS2-PIN: ?deallocate@?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@QEAAXQEAV?$MS2Ptr@VCPtred@@@@_K@Z 0x14028a890 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@XZ 0x14028a910 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@XZ 0x14028a970 ; prop
// MS2-PIN: ?end@?$list@V?$MS2Ptr@VCUserChangeableItemHistory@@@@V?$allocator@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@@2@XZ 0x14028a9d0 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@0@Z 0x14028ab00 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@@Z 0x14028abf0 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@@Z 0x14028aff0 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@_J@std@@@std@@SA_KAEBV?$allocator@_J@2@@Z 0x14028b000 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@SA_KAEBV?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@2@@Z 0x14028b030 ; prop
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@SA_KAEBV?$allocator@V?$MS2Ptr@VCPtred@@@@@2@@Z 0x14028b040 ; prop
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x14028b050 ; prop
// MS2-PIN: ?max_size@?$vector@_JV?$allocator@_J@std@@@std@@QEBA_KXZ 0x14028b090 ; prop
// MS2-PIN: ?max_size@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEBA_KXZ 0x14028b0e0 ; prop
// MS2-PIN: ?max_size@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEBA_KXZ 0x14028b130 ; prop
// MS2-PIN: ?max_size@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@QEBA_KXZ 0x14028b180 ; prop
// MS2-PIN: ?max_size@?$vector@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@QEBA_KXZ 0x14028b1d0 ; prop
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBHH@std@@@std@@SAPEAU?$pair@$$CBHH@2@AEAU32@@Z 0x14028b220 ; order
// MS2-PIN: ?pointer_to@?$pointer_traits@PEBU?$pair@$$CBHH@std@@@std@@SAPEBU?$pair@$$CBHH@2@AEBU32@@Z 0x14028b240 ; order
// MS2-PIN: ?push_back@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEAAX$$QEAUItemEntity@@@Z 0x14028b2a0 ; prop
// MS2-PIN: ?push_back@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAAX$$QEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x14028b2d0 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x14028b3f0 ; unique
// MS2-PIN: ?size@?$vector@_JV?$allocator@_J@std@@@std@@QEBA_KXZ 0x14028b430 ; prop
// MS2-PIN: ?size@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@QEBA_KXZ 0x14028b500 ; prop
// MS2-PIN: ?size@?$vector@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@QEBA_KXZ 0x14028b540 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/commonfiles/commonstruct_tail.inl"
#include <cmath>
#include <limits>
#include "ms2/fmt/format.h"

// Header inlines whose first copy is in this TU: the float helpers of the record code and the fmt argument tags of its
// log lines (float, __int64 and bool arguments), referenced through selectany pointers so the compiler emits them here.
template class std::_Tree<std::_Tmap_traits<int, int, std::less<int>, std::allocator<std::pair<const int, int> >, false> >;
typedef fmt::internal::MakeValue<fmt::BasicFormatter<char> > Unk_CsMakeValue;
__declspec(selectany) extern float (* const ms2_pfnCsFloatEpsilon)() = &std::numeric_limits<float>::epsilon;
__declspec(selectany) extern float (* const ms2_pfnCsFloorF)(float) = &std::floor;
__declspec(selectany) extern fmt::ULongLong (* const ms2_pfnCsTypeFloat)(float) = &Unk_CsMakeValue::type;
__declspec(selectany) extern fmt::ULongLong (* const ms2_pfnCsTypeLongLong)(fmt::LongLong) = &Unk_CsMakeValue::type;
__declspec(selectany) extern fmt::ULongLong (* const ms2_pfnCsTypeBool)(bool) = &Unk_CsMakeValue::type;
__declspec(selectany) extern errno_t (__cdecl* const ms2_pfnCsMemcpyS)(void*, rsize_t, const void*, rsize_t) = &memcpy_s;

// @0x14028b700
MS2_EMIT_CRT_MEMMOVE_S();
