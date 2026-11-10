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
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEAAXXZ 0x140288cc0 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEBAXPEAUItemEntity@@0@Z 0x140288d00 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEBAXPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x140288d10 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@V?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCCompactControlSkill@@@@V?$CElementTraits@V?$MS2Ptr@VCCompactControlSkill@@@@@ATL@@@ATL@@@@@@AEAAXXZ 0x140288ed0 ; caller-evidence (byte-identical slot: no exe copy of this type here)
// MS2-PIN: ?Release@?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@AEAAXXZ 0x140288e10 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VAdditionalEffectEventCtx@@@@AEAAXXZ 0x140288e50 ; caller-evidence
// MS2-PIN: ?Release@?$MS2Ptr@VCAdditionalEvent@@@@AEAAXXZ 0x140288e90 ; caller-evidence
// MS2-PIN: ?Release@?$MS2Ptr@VCIngredientInfo@@@@AEAAXXZ 0x140288dd0 ; caller-evidence
// MS2-PIN: ?Release@?$MS2Ptr@VCPtred@@@@AEAAXXZ 0x140289050 ; caller-evidence
// MS2-PIN: ?Release@?$MS2Ptr@VCUserChangeableItemHistory@@@@AEAAXXZ 0x140288f10 ; caller-evidence
// MS2-PIN: ?Release@?$MS2Ptr@VCUserLimitHistory@@@@AEAAXXZ 0x140288f50 ; caller-evidence
// MS2-PIN: ?Release@?$MS2Ptr@VChangeableProductInfo@@@@AEAAXXZ 0x140288f90 ; caller-evidence
// MS2-PIN: ?Release@?$MS2Ptr@VInvokeEffectOption@@@@AEAAXXZ 0x140288fd0 ; caller-evidence
// MS2-PIN: ?Release@?$MS2Ptr@VNpcShopItemLife@@@@AEAAXXZ 0x140289010 ; caller-evidence (byte-identical slot: no exe copy of this type here)
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x1402890d0 ; caller-evidence
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAUItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEAAPEAUItemEntity@@XZ 0x1402890b0 ; prop
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCIngredientInfo@@@@XZ 0x1402890f0 ; caller-evidence
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCPtred@@@@XZ 0x140289110 ; caller-evidence (byte-identical slot: no exe copy of this type here)
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEA_JV?$allocator@_J@std@@@std@@QEAAPEA_JXZ 0x140289090 ; caller-evidence (byte-identical slot: no exe copy of this type here)
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@V?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCCompactControlSkill@@@@V?$CElementTraits@V?$MS2Ptr@VCCompactControlSkill@@@@@ATL@@@ATL@@@@@@AEAAXPEAX@Z 0x140289270 ; caller-evidence (byte-identical slot: no exe copy of this type here)
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VAdditionalEffectEventCtx@@@@AEAAXPEAX@Z 0x1402891d0 ; caller-evidence
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCAdditionalEvent@@@@AEAAXPEAX@Z 0x140289220 ; caller-evidence
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCIngredientInfo@@@@AEAAXPEAX@Z 0x140289130 ; caller-evidence
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCPtred@@@@AEAAXPEAX@Z 0x140289450 ; caller-evidence
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCUserChangeableItemHistory@@@@AEAAXPEAX@Z 0x1402892c0 ; caller-evidence
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCUserLimitHistory@@@@AEAAXPEAX@Z 0x140289310 ; caller-evidence
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VChangeableProductInfo@@@@AEAAXPEAX@Z 0x140289360 ; caller-evidence
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VInvokeEffectOption@@@@AEAAXPEAX@Z 0x1402893b0 ; caller-evidence
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VNpcShopItemLife@@@@AEAAXPEAX@Z 0x140289400 ; caller-evidence (byte-identical slot: no exe copy of this type here)
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x1402894c0 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x1402894e0 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x1402895f0 ; unique
// MS2-PIN: ?_Tidy@?$list@V?$MS2Ptr@VCUserChangeableItemHistory@@@@V?$allocator@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@QEAAXXZ 0x140289650 ; prop
// MS2-PIN: ?_Tidy@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEAAXXZ 0x140289740 ; prop
// MS2-PIN: ?_Tidy@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEAAXXZ 0x140289810 ; prop
// MS2-PIN: ?_Umove@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEAAPEAUItemEntity@@PEAU3@00@Z 0x140289a80 ; prop
// MS2-PIN: ?_Umove@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEAAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAV34@00@Z 0x140289ac0 ; prop
// MS2-PIN: ??$_Ucopy@PEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEAAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAV23@00@Z 0x140289b80 ; w537: the callee 0x14027ab70 is _Uninitialized_copy (_Ptr_copy_cat), so this is _Ucopy, not _Ufill (the CString _Ufill is unit_140c77ab0 0x140c7cb10)
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
// MS2-PIN: ?clear@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@QEAAXXZ 0x14028a610 ; hand: calls the CIngredientInfo _Destroy 0x140287670; CIngredientContainer::m_items
// MS2-PIN: ?clear@?$vector@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@QEAAXXZ 0x14028a690 ; hand: calls the CPtred _Destroy 0x1402876b0; RemakeOptionContext::m_list68
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
// The exe's memcpy_s copy calls memcpy/memset (no /Oi expansion): the pragma must precede the inline definitions.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/commonfiles/commonstruct_tail.inl"
#include <cmath>
#include <limits>
#include "ms2/fmt/format.h"
#include "ms2/placeholder/itemremakeoption.h"

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

// ---- Full-exe entry points under the FUN_ spellings the commonstruct slices call. The exe's bodies are ICF-folded
// template instances; these give the same behaviour over the real containers. ----
typedef std::vector<MS2Ptr<CIngredientInfo> > Unk_CsIngVector;
typedef std::list<MS2Ptr<CUserChangeableItemHistory> > Unk_CsHistList;
// The ICF-folded accessor instances, named by the instantiation the exe's symbol rows bind.
class Unk_XmlNode;
typedef std::_Vector_alloc<std::_Vec_base_types<Unk_RemakeLockOpt, std::allocator<Unk_RemakeLockOpt> > > Unk_CsRemakeAlloc; template void std::vector<Unk_RemakeLockOpt>::_Xlength();   // 0x140289ea0 (ICF fold; harvest name)
typedef std::_Vector_alloc<std::_Vec_base_types<__int64, std::allocator<__int64> > > Unk_CsI64Alloc;
typedef std::_Vector_alloc<std::_Vec_base_types<MS2Ptr<CPtred>, std::allocator<MS2Ptr<CPtred> > > > Unk_CsPtredAlloc;
typedef std::_Vector_alloc<std::_Vec_base_types<Unk_XmlNode*, std::allocator<Unk_XmlNode*> > > Unk_CsXmlAlloc;
typedef std::_Vector_alloc<std::_Vec_base_types<MS2Ptr<CIngredientInfo>, std::allocator<MS2Ptr<CIngredientInfo> > > > Unk_CsIngAlloc;
typedef std::_Compressed_pair<std::allocator<MS2Ptr<CPtred> >, std::_Vector_val<std::_Simple_types<MS2Ptr<CPtred> > >, true> Unk_CsPtredPair;
typedef std::_List_alloc<std::_List_base_types<MS2Ptr<CUserChangeableItemHistory>, std::allocator<MS2Ptr<CUserChangeableItemHistory> > > > Unk_CsHistAlloc;

// vector<MS2Ptr<CIngredientInfo>>::_Make_iterator_offset: auto& d = _Get_data(); return iterator(d._Myfirst + idx, addressof(d)).
struct Unk_CsIngVal { Unk_IngRef* first; Unk_IngRef* last; Unk_IngRef* end; };   // _Vector_val
struct Unk_CsVecView { Unk_CsPtredPair m_alloc; };
__int64 FUN_14027b590(__int64 p);                       // std::addressof
void* FUN_14027d3d0(void* it, __int64 ptr, __int64 cont);   // iterator ctor
// @0x140288770
template Unk_CsIngVector::iterator Unk_CsIngVector::_Mybase::_Make_iterator_offset(size_t) noexcept;
// MS2-PIN: ?_Make_iterator_offset@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@@2@_K@Z 0x140288770 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@AEBH@Z 0x14028ad10 ; callees: non-const end 0x14028a910 / _Getcomp 0x140288430, lower_bound 0x14028af20
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@AEBH@Z 0x14028adf0 ; callees: const end 0x14028a970 / _Getcomp 0x140288450, lower_bound 0x14028af80
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@AEBH@Z 0x14028af20 ; caller (non-const find 0x14028ad10)
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@AEBH@Z 0x14028af80 ; caller (const find 0x14028adf0 only)

// vector<__int64>::_Tidy, written over the exe's accessor instances (view structs; the callees auto-bind).
void FUN_1402875b0(__int64, __int64, __int64);        // _Destroy
struct Unk_CsI64Vec {
    void Tidy();
};
// @0x140289670
void Unk_CsI64Vec::Tidy()
{
    reinterpret_cast<Unk_CsXmlAlloc*>(this)->_Orphan_all();
    if (reinterpret_cast<Unk_CsRemakeAlloc*>(this)->_Myfirst() != 0) {
        FUN_1402875b0((__int64)this, (__int64)reinterpret_cast<Unk_CsRemakeAlloc*>(this)->_Myfirst(),
                      (__int64)reinterpret_cast<Unk_CsI64Alloc*>(this)->_Mylast());
        reinterpret_cast<std::allocator<__int64>&>(reinterpret_cast<Unk_CsRemakeAlloc*>(this)->_Getal()).deallocate(
            reinterpret_cast<__int64*>(reinterpret_cast<Unk_CsRemakeAlloc*>(this)->_Myfirst()),
            reinterpret_cast<std::vector<__int64>*>(this)->capacity());
        reinterpret_cast<Unk_CsRemakeAlloc*>(this)->_Myfirst() = 0;
        reinterpret_cast<Unk_CsI64Alloc*>(this)->_Mylast() = 0;
        reinterpret_cast<Unk_CsPtredAlloc*>(this)->_Myend() = 0;
    }
}

// The list/vector iterator helpers below go through the exe's accessor and iterator-ctor instances.
__int64 FUN_14027b560(__int64 p);                       // std::addressof
void* FUN_14027ce50(void* it, __int64 node, __int64 cont); // list iterator ctor
void * FUN_14027ced0(void *, __int64, __int64);  // C3: the definition's signature
// (0x14027d630 = the reverse_iterator<vector<ItemEntity>::iterator> ctor, commonstruct_2)

// list::_Unchecked_begin: an unchecked iterator at the head's next node.
// @0x140289d20
template Unk_CsHistList::_Unchecked_iterator Unk_CsHistList::_Unchecked_begin();
//
//
//
//

// list::begin: iterator(_Myhead()->_Next, addressof(_Get_data())).
// @0x14028a1a0
template Unk_CsHistList::iterator Unk_CsHistList::begin() noexcept;
//
//
//
//
//

// list::front: *begin().
// @0x14028aef0
template Unk_CsHistList::reference Unk_CsHistList::front();
//
//
//
//

// float floor(float): <cmath>'s inline, calling floorf through the exe's import slot.
extern "C" float (__cdecl* __imp_floorf)(float);
// @0x14028aed0
float Floor(float f)
{
    return __imp_floorf(f);
}

// vector<MS2Ptr<CIngredientInfo>>::push_back(T&&): calls emplace_back 14027be20 out of line (was Unk_IngVec::FUN_14028b300).
// @0x14028b300
template void Unk_CsIngVector::push_back(MS2Ptr<CIngredientInfo>&&);
//
//
//
//

// vector<MS2Ptr<CIngredientInfo>>::push_back(const T&): calls emplace_back 14027bcd0 out of line (was FUN_14028b330).
// @0x14028b330
template void Unk_CsIngVector::push_back(const MS2Ptr<CIngredientInfo>&);





// vector<ItemEntity>::rbegin: reverse_iterator(end()).
// @0x14028b360
template std::vector<ItemEntity>::reverse_iterator std::vector<ItemEntity>::rbegin() noexcept;
// MS2-PIN: ?rbegin@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEAA?AV?$reverse_iterator@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UItemEntity@@@std@@@std@@@std@@@2@XZ 0x14028b360 ; unique
//
//
//
//

// vector<16-byte value>::_Ucopy body shared by the insertion paths in commonstruct slices C/D.
// Keep the allocator-aware copy path: these values carry reference-counted members.
// @0x140289b00
template MS2Ptr<CIngredientInfo>* Unk_CsIngVector::_Umove(MS2Ptr<CIngredientInfo>*, MS2Ptr<CIngredientInfo>*, MS2Ptr<CIngredientInfo>*);












// vector<MS2Ptr<CPtred>>'s _Buy 0x140286b50, _Destroy 0x1402876b0, _Tidy 0x1402899b0 and clear 0x14028a690
// call _Getal 0x1402883f0 and _Mylast 0x140288be0.
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VCPtred@@@@@2@XZ 0x1402883f0
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCPtred@@@@XZ 0x140288be0
