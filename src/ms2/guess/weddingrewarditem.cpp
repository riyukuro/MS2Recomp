// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WeddingTable: the wedding tables (Table/weddingPackage.xml,
// weddingReward.xml, weddingExp.xml, weddingMaintenance.xml, weddingSkill.xml) and their rows (WeddingPackage /
// WeddingHallData / WeddingRewardItem / WeddingCompleteRewardItem, WeddingRewardData, WeddingExpData,
// WeddingMaintenanceData, WeddingSkillData), plus the template glue of their containers. The TU ends with the CRT
// memcpy_s / memmove_s copies at 0x140920420 / 0x140920570; 0x140920690.. is the next TU (the WinHttp client).
// Names of the classes from RTTI; method and member names follow the v2525 reference decomp and the XML keys.
// MS2-UNIT: ?\weddingrewarditem.cpp
// MS2-RANGE: 0x1409063b0-0x140920690 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x14090a150
// MS2-PIN: ??$?0AEBH$0A@@?$tuple@AEBH@std@@QEAA@AEBH@Z 0x14090a1a0
// MS2-PIN: ??$?0U_Exact_args_t@std@@AEBH$$V$0A@@?$tuple@AEBH@std@@QEAA@U_Exact_args_t@1@AEBH@Z 0x14090a270
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14090a5a0
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@1@@Z 0x14090ac60
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14090afc0
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@1@AEAU?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@1@1@Z 0x14090d1f0
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@1@@Z 0x1409122d0
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@1@AEBH@Z 0x1409129b0
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140914120
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140914ab0
// MS2-PIN: ??$forward_as_tuple@AEBH@std@@YA?AV?$tuple@AEBH@0@AEBH@Z 0x140914da0
// MS2-PIN: ??$get@$0A@AEBH@std@@YAAEBH$$QEAV?$tuple@AEBH@0@@Z 0x140914dd0
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@QEAA@XZ 0x140915e40
// MS2-PIN: ??0?$tuple@AEBH@std@@QEAA@$$QEAV01@@Z 0x1409162c0
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140917c30
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@2@XZ 0x140918dd0
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x140919490
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@2@@Z 0x1409197e0
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@2@@Z 0x14091c680
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@2@@Z 0x14091c730
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@2@AEBH@Z 0x14091fe90
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@std@@@2@@Z 0x14091ff40
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x140920340
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14090a100
// MS2-PIN: ??$_Get_unwrapped@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@std@@YAPEAV?$MS2Ptr@VWeddingCompleteRewardItem@@@@QEAV1@@Z 0x14090c270
// MS2-PIN: ??$_Get_unwrapped@V?$MS2Ptr@VWeddingRewardItem@@@@@std@@YAPEAV?$MS2Ptr@VWeddingRewardItem@@@@QEAV1@@Z 0x14090c280
// MS2-PIN: ??$_Get_unwrapped_n@V?$MS2Ptr@VWeddingRewardItem@@@@_J$0A@@std@@YAPEAV?$MS2Ptr@VWeddingRewardItem@@@@QEAV1@_J@Z 0x14090c2b0
// MS2-PIN: ??$_Idl_distance@PEAV?$MS2Ptr@VWeddingRewardItem@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VWeddingRewardItem@@@@0@Z 0x14090c390
// MS2-PIN: ??$_Ptr_copy_cat@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VWeddingCompleteRewardItem@@@@0@Z 0x140912a80
// MS2-PIN: ??$_Ptr_move_cat@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VWeddingCompleteRewardItem@@@@0@Z 0x140912b10
// MS2-PIN: ??$_Ptr_move_cat@V?$MS2Ptr@VWeddingRewardItem@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VWeddingRewardItem@@@@0@Z 0x140912b40
// MS2-PIN: ??$_Seek_wrapped@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@std@@YAXAEAPEAV?$MS2Ptr@VWeddingCompleteRewardItem@@@@QEAV1@@Z 0x140912ba0
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140913140
// MS2-PIN: ??0?$_List_alloc@U?$_List_base_types@V?$MS2Ptr@VWeddingMaintenanceData@@@@V?$allocator@V?$MS2Ptr@VWeddingMaintenanceData@@@@@std@@@std@@@std@@QEAA@XZ 0x1409155b0
// MS2-PIN: ??1?$_List_alloc@U?$_List_base_types@V?$MS2Ptr@VWeddingMaintenanceData@@@@V?$allocator@V?$MS2Ptr@VWeddingMaintenanceData@@@@@std@@@std@@@std@@QEAA@XZ 0x1409164c0
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140916e00
// MS2-PIN: ??D?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingRewardItem@@@@@std@@@std@@@std@@QEBAAEBV?$MS2Ptr@VWeddingRewardItem@@@@XZ 0x140917210
// MS2-PIN: ??D?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@std@@@std@@@std@@QEBAAEAV?$MS2Ptr@VWeddingCompleteRewardItem@@@@XZ 0x140917220
// MS2-PIN: ??E?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingRewardItem@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140917750
// MS2-PIN: ??E?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140917770
// MS2-PIN: ??E?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingRewardItem@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140917790
// MS2-PIN: ?_Unchecked_end@?$list@V?$MS2Ptr@VWeddingMaintenanceData@@@@V?$allocator@V?$MS2Ptr@VWeddingMaintenanceData@@@@@std@@@std@@QEAA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VWeddingMaintenanceData@@@@@std@@@std@@@2@XZ 0x14091e070
// MS2-PIN: ?clear@?$list@V?$MS2Ptr@VWeddingMaintenanceData@@@@V?$allocator@V?$MS2Ptr@VWeddingMaintenanceData@@@@@std@@@std@@QEAAXXZ 0x14091e9e0
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@2@AEBH@Z 0x14091fc30
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@std@@@std@@SA_KAEBV?$allocator@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@2@@Z 0x14091ff50
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VWeddingRewardItem@@@@@std@@@std@@SA_KAEBV?$allocator@V?$MS2Ptr@VWeddingRewardItem@@@@@2@@Z 0x14091ff60
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140909e30
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14090a410
// MS2-PIN: ??$_Idl_distance1@PEAV?$MS2Ptr@VWeddingCompleteRewardItem@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VWeddingCompleteRewardItem@@@@0Urandom_access_iterator_tag@0@@Z 0x14090c2d0
// MS2-PIN: ??$_Idl_distance1@PEAV?$MS2Ptr@VWeddingRewardItem@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VWeddingRewardItem@@@@0Urandom_access_iterator_tag@0@@Z 0x14090c300
// MS2-PIN: ??$_Kfn@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@1@@Z 0x140912720
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140914c80
// MS2-PIN: ??$forward@AEBU?$less@H@std@@@std@@YAAEBU?$less@H@0@AEBU10@@Z 0x140914c90
// MS2-PIN: ??$forward@V?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x140914d90
// MS2-PIN: ??$move@AEAV?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x140914ee0
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x140916160
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140916c20
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingRewardItem@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140916c70
// MS2-PIN: ?_Compat@?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@std@@@std@@@std@@QEBAXAEBV12@@Z 0x1409194d0
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_140165cf0@@V?$allocator@PEAVUnk_140165cf0@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVUnk_140165cf0@@@std@@@2@XZ 0x14091ba20
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VWeddingRewardData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x14091c410
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VWeddingRewardData@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140917830
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_140165cf0@@V?$allocator@PEAVUnk_140165cf0@@@std@@@std@@@std@@QEAAAEAPEAPEAVUnk_140165cf0@@XZ 0x14091cf20
// MS2-PIN: ??E?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingCompleteRewardItem@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140917730
// MS2-PINS-END tplpin
// MS2-PIN: ??_7WeddingTable@@6B?$TSingleton@VWeddingTable@@@@@ 0x142da97e0
// MS2-PIN: ??_7WeddingTable@@6B?$CValidData@VWeddingTable@@@@@ 0x142da97f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\weddingtable.cpp"   // no asserts of its own
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <algorithm>
#include <vector>
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
bool FUN_14028f710(Unk_140165cf0* pNode);                                // the element is a real row (not commented out)
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& arr, const wchar_t* pszDelim);   // split
int Parse_14021baf0(const CStringA& value);                             // the wedding reward type by name (commonenum.cpp)
int Parse_14021bbd0(const CStringA& value);                             // the reward limit by name (commonenum.cpp)

// The common log (FUN_140166440()) with the unit's FMT_VARIADIC LogError instantiations.
class Unk_WeddingLog : public CLogString
{
public:
    template <class T>
    void Log(unsigned __int64 a, unsigned __int64 b, int category, const wchar_t* format, const T& value)
    {
        fmt::internal::Value values[] = { fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(value) };
        FUN_1406535b0(a, b, category, format, fmt::ArgList(fmt::internal::make_type(value), values));
    }
    template <class T, class U>
    void Log(unsigned __int64 a, unsigned __int64 b, int category, const wchar_t* format, const T& first,
             const U& second)
    {
        const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                       fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
        FUN_1406535b0(a, b, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
    }
};
Unk_WeddingLog* FUN_140166440();

// @0x140909aa0
int ParseWeddingSkillType(const CStringA& value)
{
    if (value.CompareNoCase("passive") == 0)
        return 0;
    else if (value.CompareNoCase("item") == 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x140909aa0, ParseWeddingSkillType, 71, 0xAF4DEA26);

// @0x1409063b0
WeddingRewardItem::WeddingRewardItem()
{
}

// @0x140906400
WeddingRewardItem::~WeddingRewardItem()
{
}

// @0x140906440
bool WeddingRewardItem::Read(Unk_140165cf0* pNode)
{
    (&m_item)->vfunc_2(pNode);
    return true;
}
MS2_REPLACE_METHOD(0x140906440, WeddingRewardItem, Read, 60, 0xF922C23D);

// @0x140906490
void WeddingRewardItem::CopyFrom(MS2Ptr<WeddingRewardItem> spOther)
{
    m_item = spOther->m_item;
}

// @0x1409064e0
WeddingCompleteRewardItem::WeddingCompleteRewardItem()
{
    m_bNightReward = false;
}

// @0x140906540
WeddingCompleteRewardItem::~WeddingCompleteRewardItem()
{
}

// @0x140906580
bool WeddingCompleteRewardItem::Read(Unk_140165cf0* pNode)
{
    (&m_item)->vfunc_2(pNode);
    FUN_1408730a0(pNode, "nightReward", m_bNightReward);
    return true;
}
MS2_REPLACE_METHOD(0x140906580, WeddingCompleteRewardItem, Read, 89, 0xE65EBF1C);

// @0x1409065e0
WeddingHallData::WeddingHallData()
    : m_nId(0), m_nGrade(0), m_nMerat(0), m_nFieldId(0), m_nNightFieldId(0)
{
}

// @0x1409066b0
WeddingHallData::~WeddingHallData()
{
}

// @0x140906740
bool WeddingHallData::Read(Unk_140165cf0* pNode)
{
    FUN_1408731e0(pNode, "id", m_nId);
    FUN_140873220(pNode, "fieldID", m_nFieldId);
    FUN_140873220(pNode, "nightFieldID", m_nNightFieldId);
    FUN_1408733e0(pNode, "videoPath", m_strVideoPath);
    FUN_140873420(pNode, "desc", m_strDesc);
    FUN_1408731e0(pNode, "grade", m_nGrade);
    FUN_1408732e0(pNode, "merat", m_nMerat);
    FUN_140873420(pNode, "mcillust", m_strIllust);
    for (Unk_140165cf0* pItem = pNode->FUN_140165cf0("weddingItem"); pItem != 0;
         pItem = pItem->FUN_140168650("weddingItem"))
    {
        MS2Ptr<WeddingRewardItem> spItem(new WeddingRewardItem);
        if (!spItem->Read(pItem))
            continue;
        bool bMerged = false;
        for (std::vector<MS2Ptr<WeddingRewardItem> >::iterator it = m_items.begin(); it != m_items.end(); ++it)
        {
            if (((ItemAble&)(*it)->m_item).vfunc_o18_0() == ((ItemAble&)spItem->m_item).vfunc_o18_0())
            {
                if (((ItemAble&)(*it)->m_item).vfunc_o18_1() == ((ItemAble&)spItem->m_item).vfunc_o18_1())
                {
                    (*it)->m_item.m_count += ((ItemAble&)spItem->m_item).vfunc_o18_2();
                    bMerged = true;
                    break;
                }
            }
        }
        if (!bMerged)
            m_items.push_back(spItem);
    }
    for (Unk_140165cf0* pItem = pNode->FUN_140165cf0("weddingCompleteItem"); pItem != 0;
         pItem = pItem->FUN_140168650("weddingCompleteItem"))
    {
        MS2Ptr<WeddingCompleteRewardItem> spItem(new WeddingCompleteRewardItem);
        if (!spItem->Read(pItem))
            continue;
        bool bMerged = false;
        for (std::vector<MS2Ptr<WeddingCompleteRewardItem> >::iterator it = m_completeItems.begin();
             it != m_completeItems.end(); ++it)
        {
            if (((ItemAble&)(*it)->m_item).vfunc_o18_0() == ((ItemAble&)spItem->m_item).vfunc_o18_0())
            {
                if (((ItemAble&)(*it)->m_item).vfunc_o18_1() == ((ItemAble&)spItem->m_item).vfunc_o18_1())
                {
                    if ((*it)->m_bNightReward == spItem->m_bNightReward)
                    {
                        (*it)->m_item.m_count += ((ItemAble&)spItem->m_item).vfunc_o18_2();
                        bMerged = true;
                        break;
                    }
                }
            }
        }
        if (!bMerged)
            m_completeItems.push_back(spItem);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140906740, WeddingHallData, Read, 1781, 0x877EF4F7);

// @0x140906e40
unsigned int WeddingHallData::FUN_140906e40(bool bNight)
{
    if (bNight && m_nNightFieldId != 0)
        return m_nNightFieldId;
    return m_nFieldId;
}
MS2_REPLACE_METHOD(0x140906e40, WeddingHallData, FUN_140906e40, 48, 0x34703355);

// @0x140906e80
int WeddingHallData::FUN_140906e80()
{
    switch (m_nGrade)
    {
    case 1: return 0xd4;
    case 2: return 0xd5;
    case 3: return 0xd6;
    default: return 0;
    }
}
MS2_REPLACE_METHOD(0x140906e80, WeddingHallData, FUN_140906e80, 68, 0x91943924);

// @0x140906ed0
WeddingPackage::WeddingPackage()
    : m_nId(0), m_nPlanner(0)
{
}

// @0x140906f40
WeddingPackage::~WeddingPackage()
{
}

// @0x140906f80
bool WeddingPackage::Read(Unk_140165cf0* pNode)
{
    FUN_1408731e0(pNode, "id", m_nId);
    FUN_140873220(pNode, "planner", m_nPlanner);
    for (Unk_140165cf0* pHall = pNode->FUN_140165cf0("weddingHall"); pHall != 0;
         pHall = pHall->FUN_140168650("weddingHall"))
    {
        MS2Ptr<WeddingHallData> spHall(new WeddingHallData);
        if (!spHall->Read(pHall))
            continue;
        m_halls.insert(std::make_pair(spHall->m_nId, spHall));
    }
    return true;
}
MS2_REPLACE_METHOD(0x140906f80, WeddingPackage, Read, 394, 0x14BB0ADC);

// @0x140907110
MS2Ptr<WeddingHallData> WeddingPackage::FUN_140907110(int nHallId)
{
    if (m_halls.find(nHallId) == m_halls.end())
        return MS2Ptr<WeddingHallData>(0);
    return m_halls[nHallId];
}
MS2_REPLACE_METHOD(0x140907110, WeddingPackage, FUN_140907110, 187, 0x5689F444);

// @0x1409071e0
WeddingRewardData::WeddingRewardData()
    : m_nType(0), m_nRewardExp(0), m_nRewardLimit(0)
{
}

// @0x140907240
WeddingRewardData::~WeddingRewardData()
{
}

// @0x140907270
bool WeddingRewardData::Read(Unk_140165cf0* pNode)
{
    XmlEnumName<int, Parse_14021baf0>(pNode, "type", m_nType);
    FUN_1408732e0(pNode, "rewardExp", m_nRewardExp);
    XmlEnumName<int, Parse_14021bbd0>(pNode, "rewardLimit", m_nRewardLimit);
    return m_nType != 0;
}
MS2_REPLACE_METHOD(0x140907270, WeddingRewardData, Read, 140, 0x5C586699);

// @0x140907310
WeddingExpData::WeddingExpData()
    : m_nGrade(1), m_nValue(0)
{
}

// @0x140907360
WeddingExpData::~WeddingExpData()
{
}

// @0x140907390
bool WeddingExpData::Read(Unk_140165cf0* pNode)
{
    FUN_1408731e0(pNode, "grade", m_nGrade);
    FUN_1408732e0(pNode, "value", m_nValue);
    return true;
}
MS2_REPLACE_METHOD(0x140907390, WeddingExpData, Read, 79, 0x3943B3D3);

// @0x1409073f0
WeddingMaintenanceData::WeddingMaintenanceData()
    : m_nWorld(0), m_nDayOfWeek(0), m_startTime(0), m_endTime(0)
{
}

// @0x140907470
WeddingMaintenanceData::~WeddingMaintenanceData()
{
}

// @0x1409074a0
bool WeddingMaintenanceData::Read(Unk_140165cf0* pNode)
{
    int nDayOfWeek = 0;
    CStringW strTimeRange;
    FUN_1408731e0(pNode, "world", m_nWorld);
    if (FUN_1408731e0(pNode, "dayOfWeek", nDayOfWeek) != 0)
    {
        FUN_140166440()->Log(0, 0, 0x13, L"{0}. Attribute not found - dayOfWeek.", L"WeddingMaintenanceData::Read");
        return false;
    }
    if (FUN_140873420(pNode, "time_range", strTimeRange) != 0)
    {
        FUN_140166440()->Log(0, 0, 0x13, L"{0}. Attribute not found - time_range.", L"WeddingMaintenanceData::Read");
        return false;
    }
    m_nDayOfWeek = nDayOfWeek;
    ATL::CAtlArray<CStringW> parts;
    FUN_14025a680(strTimeRange, parts, L"-");
    if (parts.GetCount() != 2)
    {
        FUN_140166440()->Log(0, 0, 0x13, L"{0}. Invalid time_range={1}", L"WeddingMaintenanceData::Read",
                             strTimeRange);
        return false;
    }
    if (!m_startTime.Parse(parts[0]))
    {
        FUN_140166440()->Log(0, 0, 0x13, L"{0}. Invalid m_startDayTime={1}", L"WeddingMaintenanceData::Read",
                             strTimeRange);
        return false;
    }
    if (!m_endTime.Parse(parts[1]))
    {
        FUN_140166440()->Log(0, 0, 0x13, L"{0}. Invalid m_endDayTime={1}", L"WeddingMaintenanceData::Read",
                             strTimeRange);
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1409074a0, WeddingMaintenanceData, Read, 754, 0x3AECFAE8);

// @0x1409077a0
bool WeddingMaintenanceData::IsMaintenance(int nWorld, const CMsTime& time)
{
    if (m_nWorld != 0 && m_nWorld != nWorld)
        return false;
    Unk_DayTime now(time);
    unsigned int nDayOfWeek = time.GetDayOfWeek();
    if (m_startTime > m_endTime)
    {
        if (nDayOfWeek == m_nDayOfWeek)
            return now > m_startTime;
        else if (nDayOfWeek == m_nDayOfWeek + 1)
            return now >= m_endTime;
        else
            return false;
    }
    else
    {
        if (nDayOfWeek == m_nDayOfWeek && now >= m_startTime && now < m_endTime)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1409077a0, WeddingMaintenanceData, IsMaintenance, 280, 0xAE0EB6D8);

// @0x1409078d0
WeddingSkillData::WeddingSkillData()
    : m_nId(0), m_nType(0), m_nRequireGrade(0), m_nMaxCount(0), m_nAdditionalEffectId(0), m_fStartValue(0),
      m_fAddValue(0)
{
}

// @0x140907980
WeddingSkillData::~WeddingSkillData()
{
}

// @0x1409079c0
bool WeddingSkillData::Read(Unk_140165cf0* pNode)
{
    FUN_1408731e0(pNode, "id", m_nId);
    XmlEnumName<int, ParseWeddingSkillType>(pNode, "type", m_nType);
    FUN_1408731e0(pNode, "requireGrade", m_nRequireGrade);
    FUN_140873220(pNode, "additionalEffectID", m_nAdditionalEffectId);
    FUN_140873360(pNode, "startValue", m_fStartValue);
    FUN_140873360(pNode, "addValue", m_fAddValue);
    FUN_1408731e0(pNode, "maxCount", m_nMaxCount);
    (&m_item)->vfunc_2(pNode);
    return true;
}
MS2_REPLACE_METHOD(0x1409079c0, WeddingSkillData, Read, 263, 0x650AFB46);

// @0x140907ad0
unsigned short WeddingSkillData::GetLevel(int nGrade)
{
    if (m_nType != 0)
        return 0;
    if (nGrade < m_nRequireGrade)
        return 0;
    unsigned short nMaxLevel = (unsigned short)(m_nMaxCount + 1);
    unsigned short nLevel = (unsigned short)(nGrade - m_nRequireGrade + 1);
    return (std::min)(nMaxLevel, nLevel);
}
MS2_REPLACE_METHOD(0x140907ad0, WeddingSkillData, GetLevel, 107, 0xAB4C5BD4);

// @0x140907b50
float WeddingSkillData::GetValue(int nGrade)
{
    unsigned short nLevel = GetLevel(nGrade);
    if (nLevel == 0)
        return m_fStartValue * 100.0f;
    float fDelta = (float)(nLevel - 1) * m_fAddValue;
    return (m_fStartValue + fDelta) * 100.0f;
}
MS2_REPLACE_METHOD(0x140907b50, WeddingSkillData, GetValue, 117, 0xF527CBA6);

// @0x140907bd0
WeddingTable::WeddingTable()
{
}

// @0x140907c90
WeddingTable::~WeddingTable()
{
}

// @0x140907d40
bool WeddingTable::Load()
{
    if (!LoadPackage())
        return false;
    if (!LoadReward())
        return false;
    if (!LoadExp())
        return false;
    if (!LoadMaintenance())
        return false;
    if (!LoadSkill())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140907d40, WeddingTable, Load, 121, 0x0C86D934);

// @0x140907dc0
bool WeddingTable::LoadPackage()
{
    CString strPath = FUN_14071a5b0("Table", "weddingPackage.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "package", "id", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        MS2Ptr<WeddingPackage> spPackage(new WeddingPackage);
        if (!spPackage->Read(pNode))
            continue;
        m_packages[spPackage->m_nId] = spPackage;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140907dc0, WeddingTable, LoadPackage, 718, 0x5F37CE29);

// @0x1409080a0
bool WeddingTable::LoadReward()
{
    CString strPath = FUN_14071a5b0("Table", "weddingReward.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "v", "type", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        MS2Ptr<WeddingRewardData> spReward(new WeddingRewardData);
        if (!spReward->Read(pNode))
            continue;
        m_rewards[spReward->m_nType] = spReward;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1409080a0, WeddingTable, LoadReward, 718, 0x7BC1ECB2);

// @0x140908380
bool WeddingTable::LoadExp()
{
    CString strPath = FUN_14071a5b0("Table", "weddingExp.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "v", "grade", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        MS2Ptr<WeddingExpData> spExp(new WeddingExpData);
        if (!spExp->Read(pNode))
            continue;
        m_exps[spExp->m_nGrade] = spExp;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140908380, WeddingTable, LoadExp, 718, 0xDBC076D2);

// @0x140908660
bool WeddingTable::LoadMaintenance()
{
    CString strPath = FUN_14071a5b0("Table", "weddingMaintenance.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("mainternance"); pNode != 0;
         pNode = pNode->FUN_140168650("mainternance"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        MS2Ptr<WeddingMaintenanceData> spData(new WeddingMaintenanceData);
        if (!spData->Read(pNode))
            continue;
        m_maintenance.push_back(spData);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140908660, WeddingTable, LoadMaintenance, 629, 0xDF3E5F92);

// @0x1409088e0
bool WeddingTable::LoadSkill()
{
    CString strPath = FUN_14071a5b0("Table", "weddingSkill.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("v"); pNode != 0; pNode = pNode->FUN_140168650("v"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        MS2Ptr<WeddingSkillData> spSkill(new WeddingSkillData);
        if (!spSkill->Read(pNode))
            continue;
        m_skills[spSkill->m_nId] = spSkill;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1409088e0, WeddingTable, LoadSkill, 651, 0xD6DED500);

// @0x140908b80
MS2Ptr<WeddingPackage> WeddingTable::FUN_140908b80(int nPackageId)
{
    if (m_packages.find(nPackageId) == m_packages.end())
        return MS2Ptr<WeddingPackage>(0);
    return m_packages[nPackageId];
}
MS2_REPLACE_METHOD(0x140908b80, WeddingTable, FUN_140908b80, 187, 0x621C9EE1);

// @0x140908c50
MS2Ptr<WeddingPackage> WeddingTable::FindPackageByPlanner(int nPlanner)
{
    for (std::map<int, MS2Ptr<WeddingPackage> >::iterator it = m_packages.begin(); it != m_packages.end(); ++it)
    {
        MS2Ptr<WeddingPackage> spPackage(it->second);
        if (spPackage->m_nPlanner == nPlanner)
            return spPackage;
    }
    return MS2Ptr<WeddingPackage>(0);
}
MS2_REPLACE_METHOD(0x140908c50, WeddingTable, FindPackageByPlanner, 250, 0x737940CE);

// @0x140908d50
unsigned int WeddingTable::FUN_140908d50(int nPackageId, int nHallId, bool bNight)
{
    MS2Ptr<WeddingPackage> spPackage = FUN_140908b80(nPackageId);
    if (spPackage == 0)
        return 0;
    MS2Ptr<WeddingHallData> spHall = spPackage->FUN_140907110(nHallId);
    if (spHall == 0)
        return 0;
    unsigned int nFieldId = spHall->FUN_140906e40(bNight);
    return nFieldId;
}
MS2_REPLACE_METHOD(0x140908d50, WeddingTable, FUN_140908d50, 253, 0x73D8FEEF);

// @0x140908e60
__int64 WeddingTable::FUN_140908e60(int nType, __int64 nLastTime)
{
    std::map<int, MS2Ptr<WeddingRewardData> >::iterator it = m_rewards.find(nType);
    if (it == m_rewards.end())
        return 0;
    MS2Ptr<WeddingRewardData> spReward(it->second);
    int bPassed = 0;
    switch (spReward->m_nRewardLimit)
    {
    case 1:
        bPassed = IsNotRecentDayChange(nLastTime);
        break;
    case 2:
        bPassed = IsMonthChanged(nLastTime);
        break;
    default:
        bPassed = 1;
        break;
    }
    if (bPassed == 0)
        return 0;
    return spReward->m_nRewardExp;
}
MS2_REPLACE_METHOD(0x140908e60, WeddingTable, FUN_140908e60, 290, 0x4159F3A0);

// @0x140908f90
int WeddingTable::GetGrade(__int64 nExp)
{
    for (std::map<int, MS2Ptr<WeddingExpData> >::iterator it = m_exps.begin(); it != m_exps.end(); ++it)
    {
        MS2Ptr<WeddingExpData> spExp(it->second);
        if (spExp->m_nValue > nExp)
            return spExp->m_nGrade - 1;
    }
    return GetMaxGrade();
}
MS2_REPLACE_METHOD(0x140908f90, WeddingTable, GetGrade, 213, 0x52720196);

// @0x140909070
__int64 WeddingTable::GetExpValue(int nGrade)
{
    std::map<int, MS2Ptr<WeddingExpData> >::iterator it = m_exps.find(nGrade);
    if (it != m_exps.end())
        return it->second->m_nValue;
    return 0;
}
MS2_REPLACE_METHOD(0x140909070, WeddingTable, GetExpValue, 117, 0x7B00F53F);

// @0x1409090f0
int WeddingTable::GetMaxGrade()
{
    return m_exps.rbegin()->first;
}
MS2_REPLACE_METHOD(0x1409090f0, WeddingTable, GetMaxGrade, 46, 0xAFD7CDB2);

// @0x140909130
int WeddingTable::FUN_140909130(int nPackageId, int nHallId)
{
    MS2Ptr<WeddingPackage> spPackage = FUN_140908b80(nPackageId);
    if (spPackage == 0)
        return 0;
    MS2Ptr<WeddingHallData> spHall = spPackage->FUN_140907110(nHallId);
    if (spHall == 0)
        return 0;
    return spHall->m_nGrade;
}
MS2_REPLACE_METHOD(0x140909130, WeddingTable, FUN_140909130, 227, 0x4882E462);

// @0x140909220
__int64 WeddingTable::FUN_140909220(int nPackageId, int nHallId)
{
    MS2Ptr<WeddingPackage> spPackage = FUN_140908b80(nPackageId);
    if (spPackage == 0)
        return 0;
    MS2Ptr<WeddingHallData> spHall = spPackage->FUN_140907110(nHallId);
    if (spHall == 0)
        return 0;
    return spHall->m_nMerat;
}
MS2_REPLACE_METHOD(0x140909220, WeddingTable, FUN_140909220, 234, 0xA4931C76);

// @0x140909310
bool WeddingTable::GetUpgradeItems(int nFromPackageId, int nFromHallId, int nToPackageId, int nToHallId,
                                   std::vector<ItemEntity>& items)
{
    items.clear();
    MS2Ptr<WeddingPackage> spFromPackage = FUN_140908b80(nFromPackageId);
    if (spFromPackage == 0)
        return false;
    MS2Ptr<WeddingHallData> spFromHall = spFromPackage->FUN_140907110(nFromHallId);
    if (spFromHall == 0)
        return false;
    MS2Ptr<WeddingPackage> spToPackage = FUN_140908b80(nToPackageId);
    if (spToPackage == 0)
        return false;
    MS2Ptr<WeddingHallData> spToHall = spToPackage->FUN_140907110(nToHallId);
    if (spToHall == 0)
        return false;
    if (spFromHall->m_nGrade >= spToHall->m_nGrade)
        return true;
    const std::vector<MS2Ptr<WeddingRewardItem> >& fromItems = spFromHall->m_items;
    const std::vector<MS2Ptr<WeddingRewardItem> >& toItems = spToHall->m_items;
    for (std::vector<MS2Ptr<WeddingRewardItem> >::const_iterator itTo = toItems.begin(); itTo != toItems.end(); ++itTo)
    {
        ItemEntity& to = (*itTo)->m_item;
        bool bFound = false;
        for (std::vector<MS2Ptr<WeddingRewardItem> >::const_iterator itFrom = fromItems.begin(); itFrom != fromItems.end();
             ++itFrom)
        {
            ItemEntity& from = (*itFrom)->m_item;
            if (((ItemAble&)to).vfunc_o18_0() == ((ItemAble&)from).vfunc_o18_0())
            {
                if (((ItemAble&)to).vfunc_o18_1() == ((ItemAble&)from).vfunc_o18_1())
                {
                    int nCount = ((unsigned int)(to.m_count - from.m_count) < 0) ? 0 : to.m_count - from.m_count;
                    if (nCount > 0)
                    {
                        ItemEntity item;
                        item.m_itemId = to.m_itemId;
                        item.SetRank(((ItemAble&)to).vfunc_o18_1());
                        item.m_count = nCount;
                        items.push_back(item);
                    }
                    bFound = true;
                    break;
                }
            }
        }
        if (!bFound)
        {
            ItemEntity item;
            item.m_itemId = to.m_itemId;
            item.SetRank(((ItemAble&)to).vfunc_o18_1());
            item.m_count = to.m_count;
            items.push_back(item);
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x140909310, WeddingTable, GetUpgradeItems, 1367, 0xC00F9162);

// @0x140909870
bool WeddingTable::FUN_140909870(int nWorld, const CMsTime& time)
{
    for (std::list<MS2Ptr<WeddingMaintenanceData> >::iterator it = m_maintenance.begin(); it != m_maintenance.end();
         ++it)
    {
        if ((*it)->IsMaintenance(nWorld, time) == true)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140909870, WeddingTable, FUN_140909870, 150, 0x09828A71);

// @0x140909910
MS2Ptr<WeddingSkillData> WeddingTable::FindSkill(int nId)
{
    std::map<int, MS2Ptr<WeddingSkillData> >::iterator it = m_skills.find(nId);
    if (it == m_skills.end())
        return MS2Ptr<WeddingSkillData>(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x140909910, WeddingTable, FindSkill, 174, 0xC0490205);

// @0x1409099d0
void WeddingTable::GetSkillsByGrade(int nGrade, std::vector<MS2Ptr<WeddingSkillData> >& skills)
{
    std::map<int, MS2Ptr<WeddingSkillData> >::iterator it = m_skills.begin();
    std::map<int, MS2Ptr<WeddingSkillData> >::iterator itEnd = m_skills.end();
    for (; it != itEnd; ++it)
    {
        if (nGrade >= it->second->m_nRequireGrade)
            skills.push_back(it->second);
    }
}
MS2_REPLACE_METHOD(0x1409099d0, WeddingTable, GetSkillsByGrade, 161, 0xAD160B83);

// @0x140909a80
std::map<int, MS2Ptr<WeddingSkillData> >& WeddingTable::GetSkills()
{
    return m_skills;
}
MS2_REPLACE_METHOD(0x140909a80, WeddingTable, GetSkills, 15, 0x77A75649);

// The UCRT's `static __inline memcpy_s` copy of this TU (corecrt_memcpy_s.h; the exe calls memset/memcpy here), kept
// alive by the pointer below, then the ATL memmove_s copy (0x140920570).
#pragma function(memcpy, memset)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
// @0x140920420
static __inline errno_t ms2_memcpy_s_copy(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    if (src == NULL || dstSize < srcSize) {
        memset(dst, 0, dstSize);
        MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
        MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
        return EINVAL;
    }
    memcpy(dst, src, srcSize);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy;

MS2_EMIT_CRT_MEMMOVE_S();
