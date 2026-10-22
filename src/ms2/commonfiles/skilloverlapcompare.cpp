// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The skill table: SkillDataTable (Xml/SkillData/*.xml,
// the Xml/Additional files, Table/glideData.xml), SkillData and the skill XML blocks (condition, beginCondition,
// SkillOverlapCompare).
// MS2-UNIT: ?\skilloverlapcompare.cpp
// MS2-RANGE: 0x1407e5b80-0x1408001f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1Unk_SkillBlockB0@@QEAA@XZ 0x1407eba60 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBQEAIXZ 0x1407ed3d0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_140165cf0@@V?$allocator@PEAVUnk_140165cf0@@@std@@@std@@@std@@QEBAAEBQEAPEAVUnk_140165cf0@@XZ 0x1407ed470 ; prop
// MS2-PIN: ?capacity@?$vector@IV?$allocator@I@std@@@std@@QEBA_KXZ 0x1407edb70 ; unique
// MS2-PIN: ?deallocate@?$allocator@I@std@@QEAAXQEAI_K@Z 0x1407edbe0 ; unique
// MS2-PIN: ??$?0AEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH$0A@@?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@AEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH@Z 0x1407ef2d0 ; unique
// MS2-PIN: ??$?0AEBV?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@$$V@?$_Compressed_pair@V?$allocator@U?$_List_node@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBV?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@1@@Z 0x1407ef3c0 ; unique
// MS2-PIN: ??$?0AEBV?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@X@?$_List_alloc@U?$_List_base_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@2@@std@@@std@@QEAA@AEBV?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@1@@Z 0x1407ef400 ; unique
// MS2-PIN: ??$?0AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@std@@$$V@?$_Compressed_pair@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@1@@Z 0x1407ef630 ; unique
// MS2-PIN: ??$?0AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@std@@X@?$_Vector_alloc@U?$_Vec_base_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@2@@std@@@std@@QEAA@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@1@@Z 0x1407ef670 ; unique
// MS2-PIN: ??$?0AEAHAEAV?$MS2Ptr@VSkillGlideData@@@@$0A@@?$pair@HV?$MS2Ptr@VSkillGlideData@@@@@std@@QEAA@AEAHAEAV?$MS2Ptr@VSkillGlideData@@@@@Z 0x1407ef800 ; unique
// MS2-PIN: ??$?0HV?$MS2Ptr@VSkillGlideData@@@@$0A@@?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VSkillGlideData@@@@@1@@Z 0x1407ef8a0 ; unique
// MS2-PIN: ??$?0U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@std@@QEAA@AEBV?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@1@@Z 0x1407ef900 ; prop
// MS2-PIN: ??$?0V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H$0A@@?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x1407ef950 ; unique
// MS2-PIN: ??$?0V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1407ef9f0 ; prop
// MS2-PIN: ??$_Buynode@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x1407efdb0 ; unique
// MS2-PIN: ??$_Insert@AEAU?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@2@@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@_N@1@AEAU?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@1@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@1@@Z 0x1407f0c70 ; unique
// MS2-PIN: ??$_Insert@AEAU?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@std@@@std@@@2@@?$_Hash@V?$_Umap_traits@IV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@2@V?$allocator@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEAU?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@1@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@std@@@std@@@1@@Z 0x1407f1270 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@1@QEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x1407f3ca0 ; unique
// MS2-PIN: ??$emplace@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x1407f4250 ; unique
// MS2-PIN: ??$erase@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@X@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@1@V21@@Z 0x1407f4480 ; prop
// MS2-PIN: ??$erase@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@std@@@std@@@std@@X@?$_Hash@V?$_Umap_traits@HV?$MS2Ptr@VSkillGlideData@@@@V?$_Uhash_compare@HU?$hash@H@std@@U?$equal_to@H@2@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@std@@@std@@@1@V21@@Z 0x1407f44c0 ; prop
// MS2-PIN: ??$erase@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@std@@@std@@@std@@X@?$_Hash@V?$_Umap_traits@IV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@2@V?$allocator@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@std@@@std@@@1@V21@@Z 0x1407f4500 ; prop
// MS2-PIN: ??$forward@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@std@@@std@@YAAEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@0@AEBV10@@Z 0x1407f4640 ; prop
// MS2-PIN: ??$forward@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@YA$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@0@AEAU10@@Z 0x1407f4690 ; prop
// MS2-PIN: ??$forward@V?$MS2Ptr@VSkillGlideData@@@@@std@@YA$$QEAV?$MS2Ptr@VSkillGlideData@@@@AEAV1@@Z 0x1407f46c0 ; prop
// MS2-PIN: ??$insert@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@X@?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x1407f47b0 ; unique
// MS2-PIN: ??$make_pair@AEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH@std@@YA?AU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@0@AEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH@Z 0x1407f47f0 ; unique
// MS2-PIN: ??$make_pair@AEAHAEAV?$MS2Ptr@VSkillGlideData@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VSkillGlideData@@@@@0@AEAHAEAV?$MS2Ptr@VSkillGlideData@@@@@Z 0x1407f48b0 ; unique
// MS2-PIN: ??0?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBV?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@1@AEBV?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@1@@Z 0x1407f5120 ; unique
// MS2-PIN: ??0?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x1407f54c0 ; unique
// MS2-PIN: ??0?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@QEAA@AEBV?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@1@@Z 0x1407f5cd0 ; unique
// MS2-PIN: ??0?$unordered_map@IV?$MS2Ptr@VSkillData@@@@U?$hash@I@std@@U?$equal_to@I@3@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@@std@@QEAA@XZ 0x1407f6230 ; unique
// MS2-PIN: ??0?$unordered_map@IV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@U?$hash@I@2@U?$equal_to@I@2@V?$allocator@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@2@@std@@QEAA@XZ 0x1407f62d0 ; unique
// MS2-PIN: ??0?$vector@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@2@@std@@QEAA@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@@1@@Z 0x1407f6350 ; unique
// MS2-PIN: ??D?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@1@XZ 0x1407f7460 ; prop
// MS2-PIN: ?_Begin@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@2@_K@Z 0x1407f9350 ; unique
// MS2-PIN: ?_Buyheadnode@?$_List_alloc@U?$_List_base_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@2@@std@@@std@@QEAAPEAU?$_List_node@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@PEAX@2@XZ 0x1407f96e0 ; unique
// MS2-PIN: ?_Check_size@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1407fa000 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAAXV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@2@@Z 0x1407fa320 ; unique
// MS2-PIN: ?_End@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@2@_K@Z 0x1407fa440 ; unique
// MS2-PIN: ?_Erase_bucket@?$_Hash@V?$_Umap_traits@HV?$MS2Ptr@VSkillGlideData@@@@V?$_Uhash_compare@HU?$hash@H@std@@U?$equal_to@H@2@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@3@$0A@@std@@@std@@IEAAXV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@std@@@std@@@2@_K@Z 0x1407fa780 ; unique
// MS2-PIN: ?_Hashval@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@IEBA_KAEBI@Z 0x1407fb190 ; unique
// MS2-PIN: ?_Hashval@?$_Hash@V?$_Umap_traits@IV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@2@V?$allocator@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@2@$0A@@std@@@std@@IEBA_KAEBI@Z 0x1407fb1f0 ; unique
// MS2-PIN: ?_Insert_bucket@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAAXV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@2@0_K@Z 0x1407fb7d0 ; unique
// MS2-PIN: ?_Make_iter@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@QEBA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@2@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@U_Iterator_base0@2@@2@@Z 0x1407fbcc0 ; prop
// MS2-PIN: ?_Make_iter@?$_Hash@V?$_Umap_traits@HV?$MS2Ptr@VSkillGlideData@@@@V?$_Uhash_compare@HU?$hash@H@std@@U?$equal_to@H@2@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@3@$0A@@std@@@std@@QEBA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@std@@@std@@@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@std@@@std@@@2@@Z 0x1407fbd00 ; prop
// MS2-PIN: ?_Make_iter@?$list@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@2@@std@@QEBA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@2@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@U_Iterator_base0@2@@2@@Z 0x1407fbe50 ; unique
// MS2-PIN: ?_Max_bucket_size@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@IEBAAEBMXZ 0x1407fc000 ; prop
// MS2-PIN: ?_Max_bucket_size@?$_Hash@V?$_Umap_traits@IV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@2@V?$allocator@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAAEAMXZ 0x1407fc060 ; unique
// MS2-PIN: ?_Max_bucket_size@?$_Hash@V?$_Umap_traits@IV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@2@V?$allocator@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@2@$0A@@std@@@std@@IEBAAEBMXZ 0x1407fc080 ; unique
// MS2-PIN: ?_Reinsert@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1407fc730 ; unique
// MS2-PIN: ?_Unwrapped@?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@std@@@std@@@std@@QEBA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@std@@@std@@@2@XZ 0x1407fd760 ; unique
// MS2-PIN: ?bucket_count@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x1407fe470 ; unique
// MS2-PIN: ?equal_range@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@std@@V12@@2@AEBI@Z 0x1407fed50 ; unique
// MS2-PIN: ?erase@?$_Hash@V?$_Umap_traits@HV?$MS2Ptr@VSkillGlideData@@@@V?$_Uhash_compare@HU?$hash@H@std@@U?$equal_to@H@2@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@std@@@std@@@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSkillGlideData@@@@@std@@@std@@@std@@@2@@Z 0x1407ff140 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1407ff470 ; unique
// MS2-PIN: ?load_factor@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@QEBAMXZ 0x1407ff5e0 ; unique
// MS2-PIN: ?lower_bound@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@std@@@std@@@2@AEBI@Z 0x1407ff730 ; unique
// MS2-PIN: ?lower_bound@?$_Hash@V?$_Umap_traits@IV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@2@V?$allocator@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@std@@@std@@@std@@@2@AEBI@Z 0x1407ff9d0 ; unique
// MS2-PIN: ?max_load_factor@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@QEBAMXZ 0x1407ffb20 ; unique
// MS2-PIN: ?size@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VSkillData@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VSkillData@@@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x1407fff10 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??1SkillOverlapCompare@@UEAA@XZ 0x1407e7ca0
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include "ms2/commonfiles/skilloverlapcompare.h"
#include <ppl.h>
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Data/Xml/<dir>/<file>
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>& out);
void FUN_1403992a0(CString pattern, CString directory, std::vector<CString>& output, CString exclude, bool localOnly);  // filesystem.cpp
int FUN_1406cfaa0(Unk_140165cf0* pElem, const char* pszName, std::vector<CString>& rOut);   // npcdata.cpp: list attribute
const CString& FUN_14082efb0(int nStat);                // xml name of the nStat-th stat
int FUN_14082ee80(const CStringA& strName);             // stat name -> id (-1 when none)
int FUN_140873710(Unk_140165cf0* pElem, const char* pszName, int* pnOut);  // int attribute (TinyXML query)
int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);  // bool attribute (TinyXML query)
int FUN_1408738d0(Unk_140165cf0* pElem, const char* pszName, int& nOut);   // int attribute (TinyXML query)
int FUN_140873ad0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);
int FUN_140873b30(Unk_140165cf0* pElem, const char* pszName, CStringW& strOut);
void* FUN_14086e000(void* pParent, const void* pChild);                     // InsertEndChild
void FUN_140873bc0(void* pElem, const char* pszName, bool bValue);          // SetAttribute(name, bool)
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);           // SetAttribute(name, int)
void FUN_140873ce0(void* pElem, const char* pszName, unsigned nValue);      // SetAttribute(name, unsigned)
void FUN_14086f970(void* pElem, const char* pszName, double fValue);        // SetDoubleAttribute
unsigned short FUN_140644430(unsigned nSkillId);        // jobtable.cpp: the level cap of a sub skill (0: none)

// The skill flags of the additional effect table (FUN_140186320 is its accessor, inline in additionalactionadditional.cpp).
class Unk_SkillFlags { public: bool FUN_140829ee0(unsigned nSkillId); };
Unk_SkillFlags* FUN_140186320();

// Unit-local view of the game's TiXmlElement (0x90 bytes; the writers only build it and insert it).
class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);      // 0x14086f2f0
    ~Unk_TiXmlElement();                        // 0x14086f450
private:
    void* unknown00[18];
};
MS2_CHECK_SIZE(Unk_TiXmlElement, 0x90);

// Container comparisons (true = same; the templates of additionalactionadditional.cpp).
template <class T> bool IsSameArray(const ATL::CAtlArray<T>& a, const ATL::CAtlArray<T>& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (unsigned i = 0; i < a.GetCount(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// The stat compare type of Unk_CompareStat (an int member in the shared header; values unrecovered).
enum Unk_CompareStatType
{
};

static int LoadXml(TiXmlDocument& doc, const char* pszPath);

// @0x1407e5b80
Unk_SkillWeapon::Unk_SkillWeapon()
    : m_nRightHand(0), m_nLeftHand(0)
{
}

// @0x1407e5bb0
bool Unk_SkillWeapon::operator!=(const Unk_SkillWeapon& o)
{
    if (m_nRightHand != o.m_nRightHand)
        return true;
    if (m_nLeftHand != o.m_nLeftHand)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407e5bb0, Unk_SkillWeapon, operator!=, 55, 0x519B0202);

// @0x1407e5bf0
SkillOverlapCompare::SkillOverlapCompare()
{
}

// @0x1407e5c50
bool SkillOverlapCompare::operator!=(const SkillOverlapCompare& o)
{
    if (!IsSameArray(m_arrHasBuffCount, o.m_arrHasBuffCount))
        return true;
    if (!IsSameArray(m_arrHasBuffCountCompare, o.m_arrHasBuffCountCompare))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407e5c50, SkillOverlapCompare, operator!=, 95, 0xB90FEAFD);

// @0x1407e5cc0
void SkillOverlapCompare::Load(Unk_140165cf0* pElem)
{
    XmlTokenList(pElem, "hasBuffCount", m_arrHasBuffCount);
    std::vector<CString> vCompare;
    FUN_1406cfaa0(pElem, "hasBuffCountCompare", vCompare);
    for (const CString& str : vCompare)
        m_arrHasBuffCountCompare.Add(ParseCompareSign(str));
}
MS2_REPLACE_METHOD(0x1407e5cc0, SkillOverlapCompare, Load, 228, 0xE517F2CE);

// @0x1407e5db0
Unk_CompareStat::Unk_CompareStat()
    : m_f0(0), m_n4(-1), m_n8(0), m_nC(0)
{
}

// @0x1407e5e00
bool Unk_CompareStat::FUN_1407e5e00(const Unk_CompareStat& o)
{
    if (m_f0 != o.m_f0)
        return true;
    if (m_n4 != o.m_n4)
        return true;
    if (m_n8 != o.m_n8)
        return true;
    if (m_nC != o.m_nC)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407e5e00, Unk_CompareStat, FUN_1407e5e00, 102, 0x7B7D842B);

// @0x1407e5e70
int Unk_CompareStat::FUN_1407e5e70(Unk_140165cf0* pElem)
{
    for (unsigned i = 0; i < 35; i++)
    {
        CString strName = FUN_14082efb0(i);
        if (FUN_140873360(pElem, strName, m_f0) == 0)
            m_n4 = FUN_14082ee80(strName);
    }
    XmlEnumName<SkillCompareSign, ParseCompareSign>(pElem, "func", (SkillCompareSign&)m_n8);
    XmlValue(pElem, "type", (Unk_CompareStatType&)m_nC);
    return 1;
}
MS2_REPLACE_METHOD(0x1407e5e70, Unk_CompareStat, FUN_1407e5e70, 219, 0x06E0CB88);

// The writer of a compare stat (writes nothing).
// @0x1407e5f60
int FUN_1407e5f60(Unk_CompareStat* pStat, void* pElem)
{
    return 1;
}
MS2_REPLACE(0x1407e5f60, FUN_1407e5f60, 16, 0x32804D89);

// @0x1407e5f80
// MS2-FUNCTIONAL: the original has five named int fields; additionalactionadditional.h (another unit) declares int m_n4[5], and /Od indexes the array
Unk_SkillOverlapCondition::Unk_SkillOverlapCondition()
{
    m_b0 = false;
    m_n4[0] = 0;
    m_n4[1] = 0;
    m_n4[2] = 0;
    m_n4[3] = 0;
    m_n4[4] = 0;
}

// @0x1407e5fe0
// MS2-FUNCTIONAL: the original has five named int fields; additionalactionadditional.h (another unit) declares int m_n4[5], and /Od indexes the array
bool Unk_SkillOverlapCondition::FUN_1407e5fe0(const Unk_SkillOverlapCondition& o)
{
    if (m_b0 != o.m_b0)
        return true;
    if (m_n4[0] != o.m_n4[0])
        return true;
    if (m_n4[1] != o.m_n4[1])
        return true;
    if (m_n4[2] != o.m_n4[2])
        return true;
    if (m_n4[3] != o.m_n4[3])
        return true;
    if (m_n4[4] != o.m_n4[4])
        return true;
    return false;
}

// @0x1407e6080
// MS2-FUNCTIONAL: m_n4[5] array (see the ctor), and the original returns int 1 where the shared header declares void
void Unk_SkillOverlapCondition::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "targetCheckRange", (unsigned&)m_n4[0]);
    FUN_140873220(pElem, "targetCheckMinRange", (unsigned&)m_n4[1]);
    FUN_140873220(pElem, "targetInRangeCount", (unsigned&)m_n4[2]);
    FUN_140873220(pElem, "targetFriendly", (unsigned&)m_n4[3]);
    XmlEnumName<SkillCompareSign, ParseCompareSign>(pElem, "targetCountSign", (SkillCompareSign&)m_n4[4]);
    if (m_n4[0] != 0 && m_n4[4] != 0)
        m_b0 = true;
}

// The writer of an overlap condition (writes nothing).
// @0x1407e6150
int FUN_1407e6150(Unk_SkillOverlapCondition* pCondition, void* pElem)
{
    return 1;
}
MS2_REPLACE(0x1407e6150, FUN_1407e6150, 16, 0x32804D89);

// @0x1407e6170
SkillHasBuffCondition::SkillHasBuffCondition()
    : m_nHasBuffID(0), m_nHasBuffCount(0), m_bHasBuffOwner(false), m_nHasNotBuffID(0), m_bHasNotBuffOwner(false)
{
}

// @0x1407e61c0
bool SkillHasBuffCondition::operator!=(const SkillHasBuffCondition& o)
{
    if (m_nHasBuffID != o.m_nHasBuffID)
        return true;
    if (m_nHasBuffCount != o.m_nHasBuffCount)
        return true;
    if (m_bHasBuffOwner != o.m_bHasBuffOwner)
        return true;
    if (m_nHasNotBuffID != o.m_nHasNotBuffID)
        return true;
    if (m_bHasNotBuffOwner != o.m_bHasNotBuffOwner)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407e61c0, SkillHasBuffCondition, operator!=, 129, 0x7A6D57F5);

// @0x1407e6250
int SkillHasBuffCondition::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "hasBuffID", m_nHasBuffID);
    FUN_1408730a0(pElem, "hasBuffOwner", m_bHasBuffOwner);
    FUN_140873220(pElem, "hasBuffCount", m_nHasBuffCount);
    FUN_140873220(pElem, "hasNotBuffID", m_nHasNotBuffID);
    FUN_1408730a0(pElem, "hasNotBuffOwner", m_bHasNotBuffOwner);
    return 1;
}
MS2_REPLACE_METHOD(0x1407e6250, SkillHasBuffCondition, Load, 165, 0xC7E39D3E);

// @0x1407e6300
int SkillHasBuffCondition::Save(void* pElem)
{
    static SkillHasBuffCondition s_default;
    FUN_140873ce0(pElem, "hasBuffID", m_nHasBuffID);
    FUN_140873bc0(pElem, "hasBuffOwner", m_bHasBuffOwner);
    FUN_140873ce0(pElem, "hasBuffCount", m_nHasBuffCount);
    FUN_140873ce0(pElem, "hasNotBuffID", m_nHasNotBuffID);
    FUN_140873bc0(pElem, "hasNotBuffOwner", m_bHasNotBuffOwner);
    return 1;
}

// @0x1407e6400
BOOL SkillHasBuffCondition::HasContent()
{
    if (m_nHasBuffID != 0)
        return TRUE;
    if (m_nHasNotBuffID != 0)
        return TRUE;
    return FALSE;
}
MS2_REPLACE_METHOD(0x1407e6400, SkillHasBuffCondition, HasContent, 43, 0xDAEC6844);

// @0x1407e6440
SkillBeginCondition::SkillBeginCondition()
    : m_fProbability(1.0f), m_nUseTargetCountFactor(0), m_nAllowBattleRidingState(0), m_nOnlyBattleRidingState(0)
{
}

// @0x1407e64b0
bool SkillBeginCondition::operator!=(const SkillBeginCondition& o)
{
    if (m_fProbability != o.m_fProbability)
        return true;
    if (m_nUseTargetCountFactor != o.m_nUseTargetCountFactor)
        return true;
    if (m_nAllowBattleRidingState != o.m_nAllowBattleRidingState)
        return true;
    if (m_nOnlyBattleRidingState != o.m_nOnlyBattleRidingState)
        return true;
    if (m_caster != o.m_caster)
        return true;
    if (m_target != o.m_target)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407e64b0, SkillBeginCondition, operator!=, 187, 0x9B84C03E);

// @0x1407e6580
bool SkillBeginCondition::IsDefault()
{
    static SkillBeginCondition s_default;
    if (*this != s_default)
        return false;
    return true;
}

// @0x1407e6610
int SkillBeginCondition::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pBegin = pElem->FUN_140165cf0("beginCondition");
    if (pBegin != 0)
    {
        FUN_140873360(pBegin, "probability", m_fProbability);
        FUN_140873710(pBegin, "useTargetCountFactor", &m_nUseTargetCountFactor);
        FUN_140873710(pBegin, "allowBattleRidingState", &m_nAllowBattleRidingState);
        FUN_140873710(pBegin, "onlyBattleRidingState", &m_nOnlyBattleRidingState);
        Unk_140165cf0* pCaster = pBegin->FUN_140165cf0("caster");
        if (pCaster != 0 && m_caster.Load(pCaster) == 0)
            return 0;
        Unk_140165cf0* pTarget = pBegin->FUN_140165cf0("target");
        if (pTarget != 0 && m_target.Load(pTarget) == 0)
            return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1407e6610, SkillBeginCondition, Load, 290, 0x6A237D67);

// @0x1407e6740
int SkillBeginCondition::Save(void* pParent)
{
    static SkillBeginCondition s_default;
    if (!IsDefault())
    {
        Unk_TiXmlElement elem("beginCondition");
        if (0.0f < m_fProbability)
            FUN_14086f970(&elem, "probability", m_fProbability);
        if (m_nUseTargetCountFactor != s_default.m_nUseTargetCountFactor)
            FUN_140873ca0(&elem, "useTargetCountFactor", m_nUseTargetCountFactor);
        if (m_nAllowBattleRidingState != s_default.m_nAllowBattleRidingState)
            FUN_140873ca0(&elem, "allowBattleRidingState", m_nAllowBattleRidingState);
        if (m_nOnlyBattleRidingState != s_default.m_nOnlyBattleRidingState)
            FUN_140873ca0(&elem, "onlyBattleRidingState", m_nOnlyBattleRidingState);
        if (m_caster.HasContent())
        {
            Unk_TiXmlElement caster("caster");
            if (m_caster.Save(&caster) == 0)
                return 0;
            FUN_14086e000(&elem, &caster);
        }
        if (m_target.HasContent())
        {
            Unk_TiXmlElement target("target");
            if (m_target.Save(&target) == 0)
                return 0;
            FUN_14086e000(&elem, &target);
        }
        FUN_14086e000(pParent, &elem);
    }
    return 1;
}

// @0x1407e69f0
SkillCondition::SkillCondition()
    : m_fDefaultRechargingCooldownTime(0), m_nUseCoolDownShowUI(0), m_nOnlyShadowWorld(0), m_nOnlyFlyableMap(0),
      m_nAllowBattleRidingState(0), m_nOnlyBattleRidingState(0), m_nSp(0), m_fInvokeEffectFactor(1.0f)
{
}

// @0x1407e6ac0
bool SkillCondition::operator!=(const SkillCondition& o)
{
    if (m_fDefaultRechargingCooldownTime != o.m_fDefaultRechargingCooldownTime)
        return true;
    if (m_nUseCoolDownShowUI != o.m_nUseCoolDownShowUI)
        return true;
    if (m_nOnlyShadowWorld != o.m_nOnlyShadowWorld)
        return true;
    if (m_nOnlyFlyableMap != o.m_nOnlyFlyableMap)
        return true;
    if (m_nAllowBattleRidingState != o.m_nAllowBattleRidingState)
        return true;
    if (m_nOnlyBattleRidingState != o.m_nOnlyBattleRidingState)
        return true;
    if (m_fInvokeEffectFactor != o.m_fInvokeEffectFactor)
        return true;
    if (m_nSp != o.m_nSp)
        return true;
    if (m_arrWeapon.GetCount() != o.m_arrWeapon.GetCount())
        return true;
    for (size_t i = 0; i < m_arrWeapon.GetCount(); i++)
    {
        if (m_arrWeapon[i] != o.m_arrWeapon[i])
            return true;
    }
    if (!IsSameArray(m_arrRequireEffect, o.m_arrRequireEffect))
        return true;
    if (!IsSameArray(m_arrRequireMapCodes, o.m_arrRequireMapCodes))
        return true;
    if (!IsSameArray(m_arrHasNotAdditionalEffectGroup, o.m_arrHasNotAdditionalEffectGroup))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407e6ac0, SkillCondition, operator!=, 517, 0xDC2EA063);

// @0x1407e6cd0
bool SkillCondition::IsDefault()
{
    static SkillCondition s_default;
    if (m_fDefaultRechargingCooldownTime != s_default.m_fDefaultRechargingCooldownTime)
        return false;
    if (m_nUseCoolDownShowUI != s_default.m_nUseCoolDownShowUI)
        return false;
    if (m_nOnlyShadowWorld != s_default.m_nOnlyShadowWorld)
        return false;
    if (m_nOnlyFlyableMap != s_default.m_nOnlyFlyableMap)
        return false;
    if (m_nAllowBattleRidingState != s_default.m_nAllowBattleRidingState)
        return false;
    if (m_nOnlyBattleRidingState != s_default.m_nOnlyBattleRidingState)
        return false;
    if (m_fInvokeEffectFactor != s_default.m_fInvokeEffectFactor)
        return false;
    if (m_nSp != s_default.m_nSp)
        return false;
    if (m_arrWeapon.GetCount() != s_default.m_arrWeapon.GetCount())
        return false;
    for (size_t i = 0; i < m_arrWeapon.GetCount(); i++)
    {
        if (m_arrWeapon[i] != s_default.m_arrWeapon[i])
            return false;
    }
    if (!IsSameArray(m_arrRequireEffect, s_default.m_arrRequireEffect))
        return false;
    if (!IsSameArray(m_arrRequireMapCodes, s_default.m_arrRequireMapCodes))
        return false;
    if (!IsSameArray(m_arrHasNotAdditionalEffectGroup, s_default.m_arrHasNotAdditionalEffectGroup))
        return false;
    return true;
}

// @0x1407e6f20
int SkillCondition::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pCondition = pElem->FUN_140165cf0("condition");
    if (pCondition != 0)
    {
        FUN_140873360(pCondition, "invokeEffectFactor", m_fInvokeEffectFactor);
        FUN_140873360(pCondition, "defaultRechargingCooldownTime", m_fDefaultRechargingCooldownTime);
        FUN_140873710(pCondition, "useCoolDownShowUI", &m_nUseCoolDownShowUI);
        FUN_140873710(pCondition, "onlyShadowWorld", &m_nOnlyShadowWorld);
        FUN_140873710(pCondition, "onlyFlyableMap", &m_nOnlyFlyableMap);
        FUN_140873710(pCondition, "allowBattleRidingState", &m_nAllowBattleRidingState);
        FUN_140873710(pCondition, "onlyBattleRidingState", &m_nOnlyBattleRidingState);
        FUN_1408731e0(pCondition, "sp", m_nSp);
        for (Unk_140165cf0* p = pCondition->FUN_140165cf0("requireEffect"); p != 0; p = p->FUN_140168650("requireEffect"))
        {
            unsigned nCode = 0;
            FUN_140873220(p, "code", nCode);
            m_arrRequireEffect.Add(nCode);
        }
        for (Unk_140165cf0* p = pCondition->FUN_140165cf0("requireMapCodes"); p != 0; p = p->FUN_140168650("requireMapCodes"))
        {
            unsigned nCode = 0;
            FUN_140873220(p, "code", nCode);
            m_arrRequireMapCodes.Add(nCode);
        }
        for (Unk_140165cf0* p = pCondition->FUN_140165cf0("hasNotAdditionalEffectGroup"); p != 0;
             p = p->FUN_140168650("hasNotAdditionalEffectGroup"))
        {
            int nId = 0;
            FUN_1408731e0(p, "id", nId);
            m_arrHasNotAdditionalEffectGroup.Add(nId);
        }
        for (Unk_140165cf0* p = pCondition->FUN_140165cf0("weapon"); p != 0; p = p->FUN_140168650("weapon"))
        {
            Unk_SkillWeapon weapon;
            FUN_1408731e0(p, "lh", weapon.m_nLeftHand);
            FUN_1408731e0(p, "rh", weapon.m_nRightHand);
            m_arrWeapon.Add(weapon);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1407e6f20, SkillCondition, Load, 741, 0x58E20B7A);

// @0x1407e7210
int SkillCondition::Save(void* pParent)
{
    static SkillCondition s_default;
    if (!IsDefault())
    {
        // The element name is the beginCondition one in the original.
        Unk_TiXmlElement elem("beginCondition");
        if (s_default.m_fInvokeEffectFactor != m_fInvokeEffectFactor)
            FUN_14086f970(&elem, "invokeEffectFactor", m_fInvokeEffectFactor);
        if (s_default.m_fDefaultRechargingCooldownTime != m_fDefaultRechargingCooldownTime)
            FUN_14086f970(&elem, "defaultRechargingCooldownTime", m_fDefaultRechargingCooldownTime);
        if (m_nUseCoolDownShowUI != s_default.m_nUseCoolDownShowUI)
            FUN_140873ca0(&elem, "useCoolDownShowUI", m_nUseCoolDownShowUI);
        if (m_nOnlyShadowWorld != s_default.m_nOnlyShadowWorld)
            FUN_140873ca0(&elem, "onlyShadowWorld", m_nOnlyShadowWorld);
        if (m_nOnlyFlyableMap != s_default.m_nOnlyFlyableMap)
            FUN_140873ca0(&elem, "onlyFlyableMap", m_nOnlyFlyableMap);
        if (m_nAllowBattleRidingState != s_default.m_nAllowBattleRidingState)
            FUN_140873ca0(&elem, "allowBattleRidingState", m_nAllowBattleRidingState);
        if (m_nOnlyBattleRidingState != s_default.m_nOnlyBattleRidingState)
            FUN_140873ca0(&elem, "onlyBattleRidingState", m_nOnlyBattleRidingState);
        for (unsigned i = 0; i < m_arrRequireEffect.GetCount(); i++)
        {
            unsigned nCode = m_arrRequireEffect[i];
            if (nCode == 0)
                continue;
            Unk_TiXmlElement child("requireEffect");
            FUN_140873ce0(&child, "code", nCode);
            FUN_14086e000(&elem, &child);
        }
        for (unsigned i = 0; i < m_arrRequireMapCodes.GetCount(); i++)
        {
            unsigned nCode = m_arrRequireMapCodes[i];
            if (nCode == 0)
                continue;
            Unk_TiXmlElement child("requireMapCodes");
            FUN_140873ce0(&child, "code", nCode);
            FUN_14086e000(&elem, &child);
        }
        for (unsigned i = 0; i < m_arrHasNotAdditionalEffectGroup.GetCount(); i++)
        {
            int nId = m_arrHasNotAdditionalEffectGroup[i];
            if (nId == 0)
                continue;
            Unk_TiXmlElement child("hasNotAdditionalEffectGroup");
            FUN_140873ca0(&child, "id", nId);
            FUN_14086e000(&elem, &child);
        }
        for (unsigned i = 0; i < m_arrWeapon.GetCount(); i++)
        {
            int nLeftHand = m_arrWeapon[i].m_nLeftHand;
            int nRightHand = m_arrWeapon[i].m_nRightHand;
            if (nLeftHand == 0 && nRightHand == 0)
                continue;
            Unk_TiXmlElement child("weapon");
            FUN_140873ca0(&child, "lh", nLeftHand);
            FUN_140873ca0(&child, "rh", nRightHand);
            FUN_14086e000(&elem, &child);
        }
        FUN_14086e000(pParent, &elem);
    }
    return 1;
}

// @0x1407e7750
SkillCompareSign ParseCompareSign(const CString& str)
{
    if (str.IsEmpty())
        return SkillCompareSign_Never;
    if (str == "Equals")
        return SkillCompareSign_Equals;
    if (str == "Less")
        return SkillCompareSign_Less;
    if (str == "LessEquals")
        return SkillCompareSign_LessEquals;
    if (str == "Greater")
        return SkillCompareSign_Greater;
    if (str == "GreaterEquals")
        return SkillCompareSign_GreaterEquals;
    return SkillCompareSign_Never;
}
MS2_REPLACE(0x1407e7750, ParseCompareSign, 196, 0xD3B9299B);

// @0x1407e7820
CString CompareSignToString(int eSign)
{
    if (eSign == SkillCompareSign_Equals)
        return "Equals";
    if (eSign == SkillCompareSign_Less)
        return "Less";
    if (eSign == SkillCompareSign_LessEquals)
        return "LessEquals";
    if (eSign == SkillCompareSign_Greater)
        return "Greater";
    if (eSign == SkillCompareSign_GreaterEquals)
        return "GreaterEquals";
    return "Never";
}
MS2_REPLACE(0x1407e7820, CompareSignToString, 281, 0x159122B8);

// @0x1407e83a0
SkillData::SkillData()
    : m_eGroupType((SkillGroupType)0), m_nJump(0), m_nOffsetNameTag(0), m_bContinue(false), m_bUnrideOnUse(false),
      m_eImmediateActive((SkillImmediateActive)0), m_bReleaseObjectWeapon(true), m_bDisableWater(false),
      m_bHoldAttack(false), m_nGroupIDs(0), m_eAttackType((DotDamageType)0), m_bDisableChangeSkillIconEffect(false),
      m_bShowCastingBar(false), m_nTooltip(0), m_spParamCastingBar(new CXmlData), m_bBattle(true),
      m_nAutoTargeting(1), m_nAutoTargetingType(0), m_bNotKeepEffect(false), m_bKeyIsDown(false),
      m_bUseDefaultSkill(false), m_bUseInGameTime(false), m_bClearCooldownFromPVPZone(false),
      m_bIgnoreReduceCooldown(false), m_bMovingInMovekey(false), m_nUseDefaultSkillID(0), m_nMoveType(0),
      m_nSuperArmor(0), m_eSuperArmorApplyFieldType((ApplyFieldType)0), m_nCooldownGroupID(0),
      m_nRechargeMaxCount(0), m_bRechargeShareOrigin(false), m_nSplashMaxCount(0), m_nId(0), m_nOriginId(0),
      m_nMaxLevel(0), m_eMainType((SkillMainType)0), m_eRangeType((SkillRangeType)0), m_eElement((ElementType)0),
      m_nParam1(0), m_b2a0(false), m_levels(10)
{
}

// @0x1407e86e0
SkillData::~SkillData()
{
}

// @0x1407e8790
bool SkillData::operator!=(const SkillData& o)
{
    if (m_nId != o.m_nId)
        return true;
    if (m_eMainType != o.m_eMainType)
        return true;
    if (m_eRangeType != o.m_eRangeType)
        return true;
    if (m_eGroupType != o.m_eGroupType)
        return true;
    if (m_nParam1 != o.m_nParam1)
        return true;
    if (m_strParamStr != o.m_strParamStr)
        return true;
    if (m_nJump != o.m_nJump)
        return true;
    if (m_eElement != o.m_eElement)
        return true;
    if (m_nOffsetNameTag != o.m_nOffsetNameTag)
        return true;
    if (m_bContinue != o.m_bContinue)
        return true;
    if (m_bUnrideOnUse != o.m_bUnrideOnUse)
        return true;
    if (m_eImmediateActive != o.m_eImmediateActive)
        return true;
    if (m_bReleaseObjectWeapon != o.m_bReleaseObjectWeapon)
        return true;
    if (m_bDisableWater != o.m_bDisableWater)
        return true;
    if (m_bHoldAttack != o.m_bHoldAttack)
        return true;
    if (m_nGroupIDs != o.m_nGroupIDs)
        return true;
    if (m_strIcon != o.m_strIcon)
        return true;
    if (m_eAttackType != o.m_eAttackType)
        return true;
    if (m_bDisableChangeSkillIconEffect != o.m_bDisableChangeSkillIconEffect)
        return true;
    if (m_bShowCastingBar != o.m_bShowCastingBar)
        return true;
    if (m_nTooltip != o.m_nTooltip)
        return true;
    if (m_spParamCastingBar.get()->FUN_14092c370(o.m_spParamCastingBar.get()))
        return true;
    if (m_bBattle != o.m_bBattle)
        return true;
    if (m_nAutoTargeting != o.m_nAutoTargeting)
        return true;
    if (m_nAutoTargetingType != o.m_nAutoTargetingType)
        return true;
    if (m_bNotKeepEffect != o.m_bNotKeepEffect)
        return true;
    if (m_bKeyIsDown != o.m_bKeyIsDown)
        return true;
    if (m_bUseDefaultSkill != o.m_bUseDefaultSkill)
        return true;
    if (m_nUseDefaultSkillID != o.m_nUseDefaultSkillID)
        return true;
    if (m_nMoveType != o.m_nMoveType)
        return true;
    if (m_nSuperArmor != o.m_nSuperArmor)
        return true;
    if (m_eSuperArmorApplyFieldType != o.m_eSuperArmorApplyFieldType)
        return true;
    if (m_bUseInGameTime != o.m_bUseInGameTime)
        return true;
    if (m_nCooldownGroupID != o.m_nCooldownGroupID)
        return true;
    if (m_bClearCooldownFromPVPZone != o.m_bClearCooldownFromPVPZone)
        return true;
    if (m_bIgnoreReduceCooldown != o.m_bIgnoreReduceCooldown)
        return true;
    if (m_nRechargeMaxCount != o.m_nRechargeMaxCount)
        return true;
    if (m_bRechargeShareOrigin != o.m_bRechargeShareOrigin)
        return true;
    if (m_bMovingInMovekey != o.m_bMovingInMovekey)
        return true;
    if (m_nSplashMaxCount != o.m_nSplashMaxCount)
        return true;
    if (m_blockA4.FUN_140802e40(o.m_blockA4))
        return true;
    if (m_blockB0.FUN_1408033b0(o.m_blockB0))
        return true;
    if (m_block150.FUN_1408037e0(o.m_block150))
        return true;
    if (m_block160.FUN_1408030c0(o.m_block160))
        return true;
    if (m_block170.FUN_140802d00(o.m_block170))
        return true;
    if (m_sensor.FUN_140801270(o.m_sensor))
        return true;
    if (m_condition != o.m_condition)
        return true;
    if (m_b2a0 != o.m_b2a0)
        return true;
    // The original compares its own level count with itself.
    if (m_levels.GetCount() != m_levels.GetCount())
        return true;
    for (POSITION pos = m_levels.GetHeadPosition(); pos != 0; m_levels.GetNext(pos))
    {
        unsigned short nLevel = m_levels.GetKeyAt(pos);
        MS2Ptr<SkillLevelData> spLevel(m_levels.GetValueAt(pos));
        MS2Ptr<SkillLevelData> spOther(0);
        if (!o.m_levels.Lookup(nLevel, spOther))
            return true;
        if (spLevel.get()->FUN_140803b30(*spOther.get()))
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1407e8790, SkillData, operator!=, 2304, 0x812F90A1);

// @0x1407e90a0
MS2Ptr<SkillLevelData> SkillData::FUN_1407e90a0(unsigned short nLevel)
{
    MS2Ptr<SkillLevelData> spLevel;
    m_levels.Lookup(nLevel, spLevel);
    return spLevel;
}
MS2_REPLACE_METHOD(0x1407e90a0, SkillData, FUN_1407e90a0, 123, 0xC3C91360);

// @0x1407e9130
void SkillData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_nId);
    FUN_140873220(pElem, "originID", m_nOriginId);
    Unk_140165cf0* pBasic = pElem->FUN_140165cf0("basic");
    if (pBasic == 0)
        return;
    XmlValue(pBasic, "mainType", m_eMainType);
    FUN_1408731e0(pBasic, "param1", m_nParam1);
    FUN_1408733e0(pBasic, "paramStr", m_strParamStr);
    Unk_140165cf0* pUi = pBasic->FUN_140165cf0("ui");
    if (pUi != 0)
    {
        FUN_140873ad0(pUi, "icon", m_strIcon);
        XmlValue(pUi, "attackType", m_eAttackType);
        FUN_1408736d0(pUi, "disableChangeSkillIconEffect", m_bDisableChangeSkillIconEffect);
        FUN_1408736d0(pUi, "showCastingBar", m_bShowCastingBar);
        FUN_1408738d0(pUi, "tooltip", m_nTooltip);
        CStringW strParam;
        FUN_140873b30(pUi, "paramCastingBar", strParam);
        m_spParamCastingBar->FUN_14092c400(strParam);
    }
    Unk_140165cf0* pKinds = pBasic->FUN_140165cf0("kinds");
    if (pKinds != 0)
    {
        XmlValue(pKinds, "rangeType", m_eRangeType);
        XmlValue(pKinds, "groupType", m_eGroupType);
        FUN_140873220(pKinds, "jump", m_nJump);
        FUN_1408730a0(pKinds, "continue", m_bContinue);
        XmlValue(pKinds, "element", m_eElement);
        FUN_1408731e0(pKinds, "offsetNameTag", m_nOffsetNameTag);
        XmlValue(pKinds, "immediateActive", m_eImmediateActive);
        FUN_1408730a0(pKinds, "unrideOnUse", m_bUnrideOnUse);
        FUN_1408730a0(pKinds, "releaseObjectWeapon", m_bReleaseObjectWeapon);
        FUN_1408730a0(pKinds, "disableWater", m_bDisableWater);
        FUN_1408736d0(pKinds, "holdAttack", m_bHoldAttack);
        FUN_140873220(pKinds, "groupIDs", m_nGroupIDs);
    }
    Unk_140165cf0* pState = pBasic->FUN_140165cf0("stateAttr");
    if (pState != 0)
    {
        FUN_1408730a0(pState, "battle", m_bBattle);
        FUN_1408731e0(pState, "superArmor", m_nSuperArmor);
        XmlValue(pState, "superArmorApplyFieldType", m_eSuperArmorApplyFieldType);
        FUN_1408731e0(pState, "autoTargeting", m_nAutoTargeting);
        FUN_140873220(pState, "autoTargetingType", m_nAutoTargetingType);
        FUN_1408731e0(pState, "moveType", m_nMoveType);
        FUN_1408730a0(pState, "notKeepEffect", m_bNotKeepEffect);
        FUN_1408730a0(pState, "keyIsDown", m_bKeyIsDown);
        FUN_1408730a0(pState, "useDefaultSkill", m_bUseDefaultSkill);
        FUN_140873220(pState, "useDefaultSkillID", m_nUseDefaultSkillID);
        FUN_1408730a0(pState, "useInGameTime", m_bUseInGameTime);
        FUN_140873220(pState, "cooldownGroupID", m_nCooldownGroupID);
        FUN_1408730a0(pState, "clearCooldownFromPVPZone", m_bClearCooldownFromPVPZone);
        FUN_1408730a0(pState, "ignoreReduceCooldown", m_bIgnoreReduceCooldown);
        FUN_140873220(pState, "rechargeMaxCount", m_nRechargeMaxCount);
        FUN_1408730a0(pState, "rechargeShareOrigin", m_bRechargeShareOrigin);
        FUN_1408730a0(pState, "movingInMovekey", m_bMovingInMovekey);
        FUN_140873220(pState, "splashMaxCount", m_nSplashMaxCount);
    }
    m_blockA4.Load(pBasic);
    m_blockB0.Load(pBasic);
    m_block150.Load(pBasic);
    m_block160.Load(pBasic);
    m_block170.FUN_140802d50(pBasic);
    m_sensor.LoadElement(pBasic, "sensor");
    m_condition.Load(pBasic);
    std::vector<Unk_140165cf0*> vLevels;
    FUN_14028faa0(pElem, "level", "value", vLevels);
    for (Unk_140165cf0* pLevel : vLevels)
    {
        MS2Ptr<SkillLevelData> spLevel(new SkillLevelData(this));
        if (spLevel->Load(pLevel) == 0)
            return;
        m_levels.SetAt(spLevel->FUN_140803df0(), spLevel);
        m_nMaxLevel = max(m_nMaxLevel, spLevel->FUN_140803df0());
    }
}
MS2_REPLACE_METHOD(0x1407e9130, SkillData, Load, 2310, 0xB331D5B6);

// @0x1407e9a40
unsigned SkillData::GetId()
{
    return m_nId;
}
MS2_REPLACE_METHOD(0x1407e9a40, SkillData, GetId, 17, 0x60F9BD05);

// @0x1407e9a60
SkillMainType SkillData::GetMainType()
{
    return m_eMainType;
}
MS2_REPLACE_METHOD(0x1407e9a60, SkillData, GetMainType, 17, 0x0700BC69);

// @0x1407e9a80
SkillRangeType SkillData::GetRangeType()
{
    return m_eRangeType;
}
MS2_REPLACE_METHOD(0x1407e9a80, SkillData, GetRangeType, 17, 0xA19D11F5);

// @0x1407e9aa0
ElementType SkillData::GetElement()
{
    return m_eElement;
}
MS2_REPLACE_METHOD(0x1407e9aa0, SkillData, GetElement, 17, 0x3C396781);

// @0x1407e9ac0
unsigned short SkillData::FUN_1407e9ac0()
{
    unsigned short nCap = FUN_140644430(m_nId);
    if (nCap != 0)
        return nCap;
    return m_nMaxLevel;
}
MS2_REPLACE_METHOD(0x1407e9ac0, SkillData, FUN_1407e9ac0, 63, 0x90BEE070);

// @0x1407e9b10
unsigned short SkillData::FUN_1407e9b10()
{
    return m_nMaxLevel;
}
MS2_REPLACE_METHOD(0x1407e9b10, SkillData, FUN_1407e9b10, 18, 0x31A30D1C);

// @0x1407e9b30
unsigned SkillData::GetRechargeMaxCount()
{
    return m_nRechargeMaxCount;
}
MS2_REPLACE_METHOD(0x1407e9b30, SkillData, GetRechargeMaxCount, 17, 0xA9AE535B);

// @0x1407e9b50
unsigned SkillData::GetOriginId()
{
    if (m_nOriginId != 0)
        return m_nOriginId;
    return GetId();
}
MS2_REPLACE_METHOD(0x1407e9b50, SkillData, GetOriginId, 51, 0xCD659FCC);

// @0x1407e9b90
unsigned SkillData::GetRechargeId()
{
    if (m_bRechargeShareOrigin)
        return GetOriginId();
    return GetId();
}
MS2_REPLACE_METHOD(0x1407e9b90, SkillData, GetRechargeId, 52, 0x028E3404);

// @0x1407e9bd0
int SkillData::FUN_1407e9bd0()
{
    switch (GetMainType())
    {
    case 7:
        return 0x1e;
    case 10:
        return 0x26;
    case 11:
        return 0x1c;
    case 12:
        return 0x20;
    case 13:
        return 0x1d;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1407e9bd0, SkillData, FUN_1407e9bd0, 102, 0x905DF2D1);

// @0x1407e9c40
unsigned __int64 SkillData::GetCooldownKey()
{
    return ((unsigned __int64)m_nCooldownGroupID << 32) | m_nId;
}
MS2_REPLACE_METHOD(0x1407e9c40, SkillData, GetCooldownKey, 35, 0x5FC3131F);

// @0x1407e9c70
unsigned SkillData::GetCooldownGroupId()
{
    return m_nCooldownGroupID;
}
MS2_REPLACE_METHOD(0x1407e9c70, SkillData, GetCooldownGroupId, 17, 0x0F11FDCF);

// @0x1407e9c90
int SkillData::GetParam1()
{
    return m_nParam1;
}
MS2_REPLACE_METHOD(0x1407e9c90, SkillData, GetParam1, 17, 0xD6D8E30D);

// @0x1407e9cb0
CString SkillData::GetParamStr()
{
    return m_strParamStr;
}
MS2_REPLACE_METHOD(0x1407e9cb0, SkillData, GetParamStr, 68, 0x0ED0D9A1);

// @0x1407e9d00
Unk_SkillSensor* SkillData::GetSensor()
{
    if (m_sensor.m_nType == 0)
        return 0;
    return &m_sensor;
}
MS2_REPLACE_METHOD(0x1407e9d00, SkillData, GetSensor, 35, 0x77FC31CF);

// @0x1407e9d30
bool SkillData::FUN_1407e9d30()
{
    switch (GetMainType())
    {
    case 14:
    case 15:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1407e9d30, SkillData, FUN_1407e9d30, 50, 0x8F6D364A);

// @0x1407e9d70
bool SkillData::FUN_1407e9d70()
{
    switch (m_eMainType)
    {
    case 3:
    case 5:
    case 7:
    case 10:
    case 17:
    case 18:
    case 19:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1407e9d70, SkillData, FUN_1407e9d70, 80, 0x8794976C);

// @0x1407e9de0
bool SkillData::FUN_1407e9de0()
{
    return m_eMainType == 6;
}
MS2_REPLACE_METHOD(0x1407e9de0, SkillData, FUN_1407e9de0, 48, 0xFEF49BD3);

// @0x1407e9e20
bool SkillData::FUN_1407e9e20()
{
    switch (GetMainType())
    {
    case 1:
    case 4:
    case 7:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 17:
    case 18:
    case 19:
        return true;
    }
    return m_bUnrideOnUse;
}
MS2_REPLACE_METHOD(0x1407e9e20, SkillData, FUN_1407e9e20, 90, 0x00BE5DCE);

// @0x1407e9ea0
bool SkillData::FUN_1407e9ea0()
{
    switch (GetMainType())
    {
    case 3:
    case 5:
    case 17:
    case 18:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1407e9ea0, SkillData, FUN_1407e9ea0, 64, 0x1119804A);

// @0x1407e9ef0
bool SkillData::FUN_1407e9ef0()
{
    switch (GetMainType())
    {
    case 17:
    case 18:
    case 19:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1407e9ef0, SkillData, FUN_1407e9ef0, 50, 0x9E78292D);

// @0x1407e9f30
bool SkillData::FUN_1407e9f30()
{
    switch (GetMainType())
    {
    case 1:
    case 3:
    case 4:
    case 5:
    case 7:
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 17:
    case 18:
    case 19:
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1407e9f30, SkillData, FUN_1407e9f30, 83, 0x1037E64C);

// @0x1407e9fb0
bool SkillData::HasOrigin()
{
    return m_nOriginId != 0;
}
MS2_REPLACE_METHOD(0x1407e9fb0, SkillData, HasOrigin, 48, 0x5506A59A);

// @0x1407e9ff0
bool SkillData::FUN_1407e9ff0()
{
    return m_b2a0;
}
MS2_REPLACE_METHOD(0x1407e9ff0, SkillData, FUN_1407e9ff0, 18, 0x93D7144B);

// @0x1407ea010
void SkillData::FUN_1407ea010()
{
    m_b2a0 = true;
}
MS2_REPLACE_METHOD(0x1407ea010, SkillData, FUN_1407ea010, 18, 0xD2C19275);

// @0x1407ea030
__int64 SkillData::FUN_1407ea030()
{
    __int64 nKey = 0;
    nKey += m_block160.FUN_140803210();
    nKey += (unsigned __int64)m_nAutoTargetingType << 32;
    nKey += (__int64)m_nAutoTargeting << 34;
    nKey += (__int64)m_nMoveType << 35;
    return nKey;
}
MS2_REPLACE_METHOD(0x1407ea030, SkillData, FUN_1407ea030, 152, 0x9E546E36);

// @0x1407ea0d0
std::vector<MS2Ptr<SkillAttackData> > SkillData::GetAttacks() const
{
    std::vector<MS2Ptr<SkillAttackData> > vAttacks;
    for (POSITION pos = m_levels.GetHeadPosition(); pos != 0; m_levels.GetNext(pos))
    {
        MS2Ptr<SkillLevelData> spLevel(m_levels.GetValueAt(pos));
        if (spLevel == 0)
            continue;
        for (MS2Ptr<SkillMotionData> spMotion : spLevel->m_vMotion)
        {
            if (spMotion == 0)
                continue;
            vAttacks.insert(vAttacks.begin(), spMotion->m_vAttack.begin(), spMotion->m_vAttack.end());
        }
    }
    return vAttacks;
}
MS2_REPLACE_METHOD(0x1407ea0d0, SkillData, GetAttacks, 559, 0x1F077D07);

// @0x1407ebc80 (the deleting destructor of SkillData)

// @0x1407edd10
SkillDataTable::SkillDataTable()
{
}

// @0x1407eddd0
void SkillDataTable::LoadSkillData()
{
    if (!m_skills.empty())
        return;
    std::vector<CString> vFiles;
    FindSkillFiles(vFiles);
    m_skillCaches.clear();
    for (const CString& strFile : vFiles)
    {
        MS2Ptr<CCacheData> spCache(new CCacheData);
        spCache->FUN_1401d1160(strFile);
        m_skillCaches.push_back(spCache);
    }
    Concurrency::parallel_for_each(std::begin(vFiles), std::end(vFiles), [this](CString strFile) {
        LoadSkillFile(strFile);
    });
}
MS2_REPLACE_METHOD(0x1407eddd0, SkillDataTable, LoadSkillData, 515, 0xAB03644C);

// @0x1407edfe0
void SkillDataTable::LoadAdditional()
{
    std::vector<CString> vFiles;
    FindAdditionalFiles(vFiles);
    m_additionalCaches.clear();
    for (const CString& strFile : vFiles)
    {
        MS2Ptr<CCacheData> spCache(new CCacheData);
        spCache->FUN_1401d1160(strFile);
        m_additionalCaches.push_back(spCache);
    }
    Concurrency::parallel_for_each(std::begin(vFiles), std::end(vFiles), [this](CString strFile) {
        LoadAdditionalFile(strFile);
    });
}
MS2_REPLACE_METHOD(0x1407edfe0, SkillDataTable, LoadAdditional, 483, 0xF1407CE7);

// @0x1407ee1d0
MS2Ptr<SkillData> SkillDataTable::GetSkillData(unsigned nSkillId)
{
    if (nSkillId == 0)
        return 0;
    Unk_CriticalSectionLock lock(m_cs, 1);
    std::unordered_map<unsigned, MS2Ptr<SkillData> >::iterator it = m_skills.find(nSkillId);
    if (it != m_skills.end())
        return it->second;
    return nullptr;
}
MS2_REPLACE_METHOD(0x1407ee1d0, SkillDataTable, GetSkillData, 272, 0x70E82709);

// @0x1407ee2f0
MS2Ptr<SkillLevelData> SkillDataTable::GetSkillLevelData(unsigned nSkillId, unsigned short nLevel)
{
    MS2Ptr<SkillData> spSkill = GetSkillData(nSkillId);
    if (!spSkill)
        return 0;
    return spSkill->FUN_1407e90a0(nLevel);
}
MS2_REPLACE_METHOD(0x1407ee2f0, SkillDataTable, GetSkillLevelData, 180, 0x950E1BFB);

// @0x1407ee3b0
std::set<unsigned>* SkillDataTable::GetGroupSkills(unsigned nGroupId)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    std::unordered_map<unsigned, std::set<unsigned> >::iterator it = m_groups.find(nGroupId);
    if (it != m_groups.end())
        return &it->second;
    return 0;
}
MS2_REPLACE_METHOD(0x1407ee3b0, SkillDataTable, GetGroupSkills, 185, 0x0B9C383B);

// @0x1407ee470
MS2Ptr<SkillGlideData> SkillDataTable::GetGlideData(int nGlideId)
{
    std::unordered_map<int, MS2Ptr<SkillGlideData> >::iterator it = m_glides.find(nGlideId);
    if (it != m_glides.end())
        return it->second;
    return nullptr;
}
MS2_REPLACE_METHOD(0x1407ee470, SkillDataTable, GetGlideData, 178, 0xDBA62764);

// @0x1407ee530
void SkillDataTable::LoadSkillFile(CString strPath)
{
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    for (Unk_140165cf0* pSkill : pRoot->FUN_140165cf0("skill"))
    {
        MS2Ptr<SkillData> spSkill(new SkillData);
        spSkill->Load(pSkill);
        AddSkill(spSkill);
    }
}
MS2_REPLACE_METHOD(0x1407ee530, SkillDataTable, LoadSkillFile, 498, 0x56830CB3);

// @0x1407ee730
void SkillDataTable::AddSkill(MS2Ptr<SkillData> spSkill)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    unsigned nSkillId = spSkill->GetId();
    std::unordered_map<unsigned, MS2Ptr<SkillData> >::iterator it = m_skills.find(nSkillId);
    if (it != m_skills.end())
    {
        MS2Ptr<SkillData> spOld = it->second;
        unsigned nGroupId = spOld->m_nGroupIDs;
        if (nGroupId != 0)
        {
            std::unordered_map<unsigned, std::set<unsigned> >::iterator itGroup = m_groups.find(nGroupId);
            if (itGroup != m_groups.end())
                itGroup->second.erase(nSkillId);
        }
        m_skills.erase(nSkillId);
    }
    if (spSkill->m_nGroupIDs != 0)
        m_groups[spSkill->m_nGroupIDs].insert(nSkillId);
    m_skills.insert(std::make_pair(spSkill->GetId(), spSkill));
    IndexSensors(spSkill);
    FUN_1407eec60(spSkill);
}

// @0x1407ee9f0
void SkillDataTable::IndexSensors(MS2Ptr<SkillData> spSkill)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    std::vector<MS2Ptr<SkillAttackData> > vAttacks = spSkill->GetAttacks();
    for (MS2Ptr<SkillAttackData> spAttack : vAttacks)
    {
        CString strName = spAttack->m_damage.m_strEffectHit;
        if (strName.IsEmpty())
            continue;
        std::map<CString, int>::iterator it = m_sensorIndex.find(strName);
        if (it != m_sensorIndex.end())
        {
            spAttack->m_damage.m_nNameIndex = it->second;
        }
        else
        {
            spAttack->m_damage.m_nNameIndex = m_nSensorCount;
            m_sensorIndex.insert(std::make_pair(strName, m_nSensorCount));
            m_nSensorCount++;
        }
    }
}

// @0x1407eec60
void SkillDataTable::FUN_1407eec60(MS2Ptr<SkillData> spSkill)
{
    if (FUN_140186320()->FUN_140829ee0(spSkill->GetId()))
        spSkill->FUN_1407ea010();
    return;
}

// @0x1407eece0
void SkillDataTable::FindSkillFiles(std::vector<CString>& out)
{
    FUN_1403992a0(".xml", "./Data/Xml/SkillData", out, "", false);
}
MS2_REPLACE_METHOD(0x1407eece0, SkillDataTable, FindSkillFiles, 192, 0xD3AC2390);

// @0x1407eedb0
void SkillDataTable::FindAdditionalFiles(std::vector<CString>& out)
{
    FUN_1403992a0(".xml", "./Data/Xml/Additional", out, "", false);
}
MS2_REPLACE_METHOD(0x1407eedb0, SkillDataTable, FindAdditionalFiles, 192, 0x5E9A2B2F);

// @0x1407eee80
bool SkillDataTable::Reload()
{
    Concurrency::parallel_for_each(std::begin(m_skillCaches), std::end(m_skillCaches), [this](MS2Ptr<CCacheData> spCache) {
        if (FUN_1401d1320(spCache.get()))
            LoadSkillFile(*spCache.get()->FUN_1401d1140());
    });
    Concurrency::parallel_for_each(std::begin(m_additionalCaches), std::end(m_additionalCaches),
                                   [this](MS2Ptr<CCacheData> spCache) {
        if (FUN_1401d1320(spCache.get()))
            LoadAdditionalFile(*spCache.get()->FUN_1401d1140());
    });
    return true;
}
MS2_REPLACE_METHOD(0x1407eee80, SkillDataTable, Reload, 232, 0xC515757D);

// @0x1407eef70
void SkillDataTable::LoadGlideData()
{
    CString strPath = FUN_14071a5b0("Table", "glideData.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pGlide : pRoot->FUN_140165cf0("glide"))
    {
        MS2Ptr<SkillGlideData> spGlide(new SkillGlideData);
        spGlide->Load(pGlide);
        int nId = spGlide->FUN_140802ab0();
        m_glides.insert(std::make_pair(nId, spGlide));
    }
}
MS2_REPLACE_METHOD(0x1407eef70, SkillDataTable, LoadGlideData, 736, 0x25108745);

// @0x1407ef260
static int LoadXml(TiXmlDocument& doc, const char* pszPath)
{
    return FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c090-0x142c9c0d0 .text$yd
