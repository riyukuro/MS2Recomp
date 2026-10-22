// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The item drop tables: Table/individualItemDrop_Final.xml
// (the boxes the client shows and rolls) and the server's global drop boxes/groups (Table/Server/globalDrop*).
// MS2-UNIT: commonfiles\itemdroptable.cpp
// MS2-RANGE: 0x1402e6c50-0x1403142a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAU?$equal_to@I@std@@M@?$_Compressed_pair@U?$equal_to@I@std@@M$00@std@@QEAA@U_One_then_variadic_args_t@1@AEAU?$equal_to@I@1@$$QEAM@Z 0x1402ee150 ; unique
// MS2-PIN: ??$?0AEAU?$hash@I@std@@U_One_then_variadic_args_t@1@AEAU?$equal_to@I@1@M@?$_Compressed_pair@U?$hash@I@std@@V?$_Compressed_pair@U?$equal_to@I@std@@M$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEAU?$hash@I@1@$$QEAU21@AEAU?$equal_to@I@1@$$QEAM@Z 0x1402ee1a0 ; unique
// MS2-PIN: ??$?0AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@std@@$$V@?$_Compressed_pair@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@1@@Z 0x1402ee850 ; prop
// MS2-PIN: ??$?0AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@std@@X@?$_Vector_alloc@U?$_Vec_base_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@2@@std@@@std@@QEAA@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@1@@Z 0x1402ee890 ; unique
// MS2-PIN: ??$?0AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@std@@$$V@?$_Compressed_pair@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@1@@Z 0x1402ee8d0 ; prop
// MS2-PIN: ??$?0AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@std@@X@?$_Vector_alloc@U?$_Vec_base_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@2@@std@@@std@@QEAA@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@1@@Z 0x1402ee910 ; unique
// MS2-PIN: ??$?0AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@std@@$$V@?$_Compressed_pair@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@1@@Z 0x1402ee950 ; prop
// MS2-PIN: ??$?0AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@std@@X@?$_Vector_alloc@U?$_Vec_base_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@2@@std@@@std@@QEAA@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@1@@Z 0x1402ee990 ; unique
// MS2-PIN: ??$?0V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1402eee80 ; prop
// MS2-PIN: ??$?0V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1402eeed0 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1402eef70 ; prop
// MS2-PIN: ??$?0V?$tuple@$$QEAH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$ItemDropPicker@H@@@std@@QEAA@AEAV?$tuple@$$QEAH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1402ef2e0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@1@V21@@Z 0x1402ef540 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@1@V21@@Z 0x1402ef570 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropIndividualBox@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@1@V21@@Z 0x1402ef5a0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x1402ef660 ; unique
// MS2-PIN: ??$_Insert@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@2@@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@_N@1@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@1@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@1@@Z 0x1402f28b0 ; unique
// MS2-PIN: ??$_Insert@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@2@@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@_N@1@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@1@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@1@@Z 0x1402f2bb0 ; unique
// MS2-PIN: ??$_Insert@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@2@@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropIndividualBox@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@_N@1@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@1@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@1@@Z 0x1402f2eb0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@1@AEAU?$pair@$$CBHV?$ItemDropPicker@H@@@1@1@Z 0x1402f3330 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$ItemDropPicker@H@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@1@@Z 0x1402f4410 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHV?$ItemDropPicker@H@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@1@@Z 0x1402f5c90 ; unique
// MS2-PIN: ??$_Try_emplace@H$$V@?$map@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@std@@_N@1@$$QEAH@Z 0x1402f7dd0 ; unique
// MS2-PIN: ??$addressof@I@std@@YAPEAIAEAI@Z 0x1402f9950 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@0@AEBV10@@Z 0x1402f9990 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$ItemDropPicker@H@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x1402f9cd0 ; unique
// MS2-PIN: ??$destroy@I@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@QEAI@Z 0x1402fa8d0 ; prop
// MS2-PIN: ??$emplace_back@AEBV?$MS2Ptr@VItemDropDataGlobal@@@@@?$vector@V?$MS2Ptr@VItemDropDataGlobal@@@@V?$allocator@V?$MS2Ptr@VItemDropDataGlobal@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VItemDropDataGlobal@@@@@Z 0x1402fad00 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x1402fb100 ; unique
// MS2-PIN: ??$forward@$$QEAH@std@@YA$$QEAHAEAH@Z 0x1402fb260 ; prop
// MS2-PIN: ??$forward@AEAU?$equal_to@I@std@@@std@@YAAEAU?$equal_to@I@0@AEAU10@@Z 0x1402fb300 ; prop
// MS2-PIN: ??$forward@AEAU?$hash@I@std@@@std@@YAAEAU?$hash@I@0@AEAU10@@Z 0x1402fb310 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@YAAEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@0@AEAU10@@Z 0x1402fb370 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@YAAEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@0@AEAU10@@Z 0x1402fb380 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@YAAEAU?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@0@AEAU10@@Z 0x1402fb390 ; prop
// MS2-PIN: ??$forward@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@std@@@std@@YAAEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@0@AEBV10@@Z 0x1402fb570 ; prop
// MS2-PIN: ??$forward@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@std@@@std@@YAAEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@0@AEBV10@@Z 0x1402fb580 ; prop
// MS2-PIN: ??$forward@AEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@std@@@std@@YAAEBV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@0@AEBV10@@Z 0x1402fb590 ; prop
// MS2-PIN: ??$forward@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1402fb700 ; prop
// MS2-PIN: ??$forward@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1402fb710 ; prop
// MS2-PIN: ??$forward@V?$tuple@$$QEAH@std@@@std@@YA$$QEAV?$tuple@$$QEAH@0@AEAV10@@Z 0x1402fb7d0 ; prop
// MS2-PIN: ??$forward_as_tuple@H@std@@YA?AV?$tuple@$$QEAH@0@$$QEAH@Z 0x1402fb800 ; unique
// MS2-PIN: ??$get@$0A@$$QEAH@std@@YA$$QEAH$$QEAV?$tuple@$$QEAH@0@@Z 0x1402fb830 ; unique
// MS2-PIN: ??$move@AEAV?$tuple@$$QEAH@std@@@std@@YA$$QEAV?$tuple@$$QEAH@0@AEAV10@@Z 0x1402fbe00 ; prop
// MS2-PIN: ??0?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@QEAA@XZ 0x1402fcd30 ; unique
// MS2-PIN: ??0?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@QEAA@XZ 0x1402fcd90 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@1@@Z 0x1402fd370 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@1@@Z 0x1402fd4f0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAA@XZ 0x1402fd820 ; prop
// MS2-PIN: ??0?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@QEAA@U?$hash@I@1@U?$equal_to@I@1@@Z 0x1402fd850 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x1402fdd90 ; prop
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x1402fde10 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@IPEAX@std@@@std@@QEAA@XZ 0x1402fdf40 ; prop
// MS2-PIN: ??0?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@QEAA@XZ 0x1402fdf50 ; prop
// MS2-PIN: ??0?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@QEAA@XZ 0x1402fdf60 ; prop
// MS2-PIN: ??0?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@QEAA@XZ 0x1402fdf70 ; prop
// MS2-PIN: ??0?$unordered_map@IV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@U?$hash@I@std@@U?$equal_to@I@3@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@3@@std@@QEAA@XZ 0x1402fe260 ; unique
// MS2-PIN: ??0?$unordered_map@IV?$MS2Ptr@VItemDropGlobalGroup@@@@U?$hash@I@std@@U?$equal_to@I@3@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@3@@std@@QEAA@XZ 0x1402fe2b0 ; unique
// MS2-PIN: ??0?$unordered_map@IV?$MS2Ptr@VItemDropIndividualBox@@@@U?$hash@I@std@@U?$equal_to@I@3@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@3@@std@@QEAA@XZ 0x1402fe300 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@K_NU?$less@K@std@@V?$allocator@U?$pair@$$CBK_N@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1402ff2f0 ; prop
// MS2-PIN: ??1?$map@K_NU?$less@K@std@@V?$allocator@U?$pair@$$CBK_N@std@@@2@@std@@QEAA@XZ 0x1402ff6e0 ; unique
// MS2-PIN: ??A?$map@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@@std@@QEAAAEAV?$ItemDropPicker@H@@$$QEAH@Z 0x1403005c0 ; unique
// MS2-PIN: ??D?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEBAAEBU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@1@XZ 0x1403009b0 ; prop
// MS2-PIN: ??D?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEBAAEBU?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@1@XZ 0x1403009f0 ; prop
// MS2-PIN: ??D?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@1@XZ 0x140300a10 ; unique
// MS2-PIN: ??D?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@1@XZ 0x140300a30 ; unique
// MS2-PIN: ??D?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@1@XZ 0x140300a50 ; unique
// MS2-PIN: ??E?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140300d30 ; unique
// MS2-PIN: ??E?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140300d50 ; unique
// MS2-PIN: ??E?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140300d70 ; unique
// MS2-PIN: ??E?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140300d90 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEAAAEAV01@XZ 0x140301090 ; prop
// MS2-PIN: ??F?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140301490 ; unique
// MS2-PIN: ??F?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1403014b0 ; unique
// MS2-PIN: ??F?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1403014d0 ; unique
// MS2-PIN: ??R?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@QEBA_NAEBI0@Z 0x140302200 ; unique
// MS2-PIN: ??_EItemDropResult@@W7EAAPEAXI@Z 0x140302328 ; unique
// MS2-PIN: ??_EItemDropTable@@W7EAAPEAXI@Z 0x140302334 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x140305cd0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@2@@Z 0x140306210 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@2@@Z 0x1403065f0 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@K_NU?$less@K@std@@V?$allocator@U?$pair@$$CBK_N@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@2@@Z 0x140309200 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x140309500 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEBAAEBV?$allocator@I@2@XZ 0x140309970 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@std@@@2@XZ 0x140309a80 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@std@@@2@XZ 0x140309b10 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@2@XZ 0x140309b60 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@2@XZ 0x140309b70 ; unique
// MS2-PIN: ?_Get_max_bucket_size@?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@QEAAAEAMXZ 0x140309c50 ; prop
// MS2-PIN: ?_Get_max_bucket_size@?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@QEBAAEBMXZ 0x140309c80 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$equal_to@I@std@@M$00@std@@QEAAAEAMXZ 0x140309cb0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$equal_to@I@std@@M$00@std@@QEBAAEBMXZ 0x140309cc0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$hash@I@std@@V?$_Compressed_pair@U?$equal_to@I@std@@M$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@U?$equal_to@I@std@@M$00@2@XZ 0x140309cd0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@2@$00@2@XZ 0x140309d90 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x140309e00 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@2@XZ 0x140309ea0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@PEAX@std@@@2@XZ 0x14030a090 ; unique
// MS2-PIN: ?_Hashval@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@3@$0A@@std@@@std@@IEBA_KAEBI@Z 0x14030a850 ; unique
// MS2-PIN: ?_Hashval@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@3@$0A@@std@@@std@@IEBA_KAEBI@Z 0x14030a880 ; unique
// MS2-PIN: ?_Hashval@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropIndividualBox@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@3@$0A@@std@@@std@@IEBA_KAEBI@Z 0x14030a8b0 ; unique
// MS2-PIN: ?_Max_bucket_size@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@3@$0A@@std@@@std@@IEAAAEAMXZ 0x14030bc80 ; unique
// MS2-PIN: ?_Max_bucket_size@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@3@$0A@@std@@@std@@IEBAAEBMXZ 0x14030bca0 ; unique
// MS2-PIN: ?_Max_bucket_size@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@3@$0A@@std@@@std@@IEBAAEBMXZ 0x14030bce0 ; unique
// MS2-PIN: ?_Max_bucket_size@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropIndividualBox@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@3@$0A@@std@@@std@@IEAAAEAMXZ 0x14030bd00 ; unique
// MS2-PIN: ?_Max_bucket_size@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropIndividualBox@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@3@$0A@@std@@@std@@IEBAAEBMXZ 0x14030bd20 ; unique
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_140165cf0@@V?$allocator@PEAVUnk_140165cf0@@@std@@@std@@@std@@QEBAAEBQEAPEAVUnk_140165cf0@@XZ 0x14030c120 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAXXZ 0x14030c6e0 ; prop
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEBAAEAPEAU?$_Tree_node@IPEAX@2@XZ 0x14030d5a0 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x14030ddb0 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@K_NU?$less@K@std@@V?$allocator@U?$pair@$$CBK_N@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x14030df90 ; prop
// MS2-PIN: ?_Unchecked_splice@?$list@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@2@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@U_Iterator_base0@2@@2@00@Z 0x14030f180 ; prop
// MS2-PIN: ?_Unchecked_splice@?$list@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@2@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@U_Iterator_base0@2@@2@00@Z 0x14030f210 ; prop
// MS2-PIN: ?_Unchecked_splice@?$list@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@2@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@U_Iterator_base0@2@@2@00@Z 0x14030f2a0 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBK_N@std@@PEAX@2@_K@Z 0x1403112e0 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@XZ 0x1403117e0 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$ItemDropPicker@H@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$ItemDropPicker@H@@@std@@@std@@@std@@@2@@Z 0x140312020 ; unique
// MS2-PIN: ?lower_bound@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalBoxGroup@@@@@std@@@std@@@std@@@2@AEBI@Z 0x140312ed0 ; unique
// MS2-PIN: ?lower_bound@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropGlobalGroup@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropGlobalGroup@@@@@std@@@std@@@std@@@2@AEBI@Z 0x140313020 ; unique
// MS2-PIN: ?lower_bound@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VItemDropIndividualBox@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemDropIndividualBox@@@@@std@@@std@@@std@@@2@AEBI@Z 0x140313170 ; unique
// MS2-PINS-END tplpin
// cf9: additional attribution accepted by tplpin --simulate.
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$MS2Ptr@VItemDropGlobalBox@@@@@?$vector@V?$MS2Ptr@VItemDropGlobalBox@@@@V?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@@std@@AEAAXAEBV?$MS2Ptr@VItemDropGlobalBox@@@@@Z 0x1402f0b30
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VItemDropGlobalBox@@@@@?$vector@V?$MS2Ptr@VItemDropGlobalBox@@@@V?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VItemDropGlobalBox@@@@QEAV2@AEBV2@@Z 0x1402f12d0
// MS2-PIN: ??1_Chore@details@Concurrency@@MEAA@XZ 0x1402ffb70
// MS2-PIN: ??_G_Chore@details@Concurrency@@MEAAPEAXI@Z 0x140302960
// MS2-PIN: ?_Change_array@?$vector@V?$MS2Ptr@VItemDropGlobalBox@@@@V?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@@std@@AEAAXQEAV?$MS2Ptr@VItemDropGlobalBox@@@@_K1@Z 0x140305200
// MS2-PIN: ??1_UnrealizedChore@details@Concurrency@@UEAA@XZ 0x1402ffb90
// MS2-PIN: ??D?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@QEBAAEAIXZ 0x140300ba0
// MS2-PIN: ?_Unchecked_begin@?$vector@V?$MS2Ptr@VItemDropDataGlobal@@@@V?$allocator@V?$MS2Ptr@VItemDropDataGlobal@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VItemDropDataGlobal@@@@XZ 0x14030ef30
// MS2-PIN: ?_Unchecked_end@?$vector@V?$MS2Ptr@VItemDropDataGlobal@@@@V?$allocator@V?$MS2Ptr@VItemDropDataGlobal@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VItemDropDataGlobal@@@@XZ 0x14030f100
// MS2-PIN: ??R?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@QEBA_KAEBI@Z 0x1403021d0 ; manual: hash operator(), exe copy called from every unordered_map<unsigned> _Hashval
// MS2-PIN: ??_7ItemDropTable@@6B?$TSingleton@VItemDropTable@@@@@ 0x142d24b98 ; manual: RTTI pairing misses the base name
// MS2-PIN: ??_7ItemDropTable@@6B?$CValidData@VItemDropTable@@@@@ 0x142d24ba8 ; manual
// The unit name is a guess: the queue row commonfiles\dungeonmatch.cpp (0x1402e6c50-0x14031b800) is four TUs, see
// commonfiles\dungeonmatch.cpp.
// cf9: residual look-alikes resolved by the pinned vector callers and const getter chain.
// MS2-PIN: ??$emplace_back@AEBV?$MS2Ptr@VItemDropGlobalBox@@@@@?$vector@V?$MS2Ptr@VItemDropGlobalBox@@@@V?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VItemDropGlobalBox@@@@@Z 0x1402fade0
// MS2-PIN: ?_Tidy@?$vector@V?$MS2Ptr@VItemDropGlobalBox@@@@V?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@@std@@AEAAXXZ 0x14030e1f0
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_140165cf0@@V?$allocator@PEAVUnk_140165cf0@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVUnk_140165cf0@@@std@@@2@XZ 0x140309790
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_140165cf0@@V?$allocator@PEAVUnk_140165cf0@@@std@@@std@@@std@@QEBAAEBQEAPEAVUnk_140165cf0@@XZ 0x14030bee0
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VItemDropGlobalBox@@@@V?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VItemDropGlobalBox@@@@XZ 0x14030c3c0
// MS2-PIN: ?_Unchecked_end@?$vector@V?$MS2Ptr@VItemDropGlobalBox@@@@V?$allocator@V?$MS2Ptr@VItemDropGlobalBox@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VItemDropGlobalBox@@@@XZ 0x14030f140
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemdroptable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <ppl.h>
#include "itemdroptable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/cgloabalfactor.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The common log (FUN_140166440()).
class Unk_CommonLog
{
public:
    void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg);
};
Unk_CommonLog* FUN_140166440();
void FUN_140177a80(Unk_CommonLog* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const unsigned& nArg);

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                               // the element is usable
void FUN_14028f5d0(Unk_140165cf0* pParent, const char* pszChild, std::vector<Unk_140165cf0*>& arrOut);
int FUN_14015f500(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);

// The item option generator (FUN_140166430()): a random rank for an item.
class Unk_OptionMgr { public: int FUN_1405f4d30(unsigned nItemId, int nArg, short nLevel, int nRandom, bool bAssist); };
Unk_OptionMgr* FUN_140166430();

MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// The exe's callers test the gender check as a full int (test eax, eax, no movzx of the bool).
class Unk_DropItemData : public CItemData
{
public:
    int FUN_14053c940(int nGender);
};
bool FUN_14053ff30(int nItemId, int nRank);                 // the item exists in that rank
int FUN_14053feb0(int nItemId);                             // default rank of an item
unsigned FUN_140768010(unsigned nRange, unsigned nBase);    // random number in base..base+range-1
bool FUN_14028d470(float a, float b);                       // a == b (within epsilon)
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool ItemDropTable::s_bInit;
#endif

// @0x1402e6c50
ItemDropData::ItemDropData() : m_itemID(0), m_itemID2(0)
{
}

// @0x1402e6d60
bool ItemDropData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "itemID", m_itemID);
    FUN_140873220(pElem, "itemID2", m_itemID2);
    FUN_140873220(pElem, "weight", m_weight);
    FUN_14015f500(pElem, "uiItemRank", &m_uiItemRank);
    FUN_1408736d0(pElem, "assistBonus", m_assistBonus);
    FUN_1408736d0(pElem, "constraintsQuest", m_constraintsQuest);
    FUN_1408731e0(pElem, "enchantLevel", m_enchantLevel);
    FUN_140873220(pElem, "socketDataID", m_socketDataID);
    FUN_1408736d0(pElem, "tradableCountDeduction", m_tradableCountDeduction);
    FUN_1408736d0(pElem, "rePackingLimitCountDeduction", m_rePackingLimitCountDeduction);
    FUN_1408736d0(pElem, "disableBreak", m_disableBreak);
    FUN_1408730a0(pElem, "isBindCharacter", m_isBindCharacter);
    FUN_1408736d0(pElem, "showIconOnGachaUI", m_showIconOnGachaUI);
    unsigned nMinCount = 1;
    unsigned nMaxCount = 0;
    FUN_140873220(pElem, "minCount", nMinCount);
    FUN_140873220(pElem, "maxCount", nMaxCount);
    nMaxCount = (std::max)(nMinCount, nMaxCount);
    m_count.Range(nMinCount, nMaxCount);
    XmlTokenList(pElem, "mapDependency", m_mapDependency);
    {
        std::vector<unsigned> grades;
        std::vector<unsigned> probabilities;
        XmlTokenList(pElem, "grade", grades);
        XmlTokenList(pElem, "gradeProbability", probabilities);
        for (size_t i = 0; i < grades.size(); ++i)
        {
            unsigned nWeight = 1;
            if (i < probabilities.size())
                nWeight = probabilities[i];
            m_grade.Register(nWeight, (ItemDropGrade)grades[i]);
        }
    }
    {
        MS2Ptr<ItemDropItemLife> pLife(new ItemDropItemLife);
        if (pLife->FUN_14026f290(pElem))
            m_itemLife = pLife;
    }
    if (m_itemID == 0 || m_weight == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1402E6D60, ItemDropData, Load, 1042, 0x6CF8D382);

// @0x1402e7180
CString ItemDropData::GetTypeName()
{
    return "Common";
}
MS2_REPLACE_METHOD(0x1402E7180, ItemDropData, GetTypeName, 61, 0xE78D082D);

// @0x1402e71d0
void ItemDropData::OnLoad()
{
}
MS2_REPLACE_METHOD(0x1402E71D0, ItemDropData, OnLoad, 6, 0xA9AF6E37);

// @0x1402e71e0
bool ItemDropData::Check(unsigned nMapId, bool bAssist, ItemDropFilter* pFilter)
{
    if (!CheckMap(nMapId))
        return false;
    if (!CheckAssist(bAssist))
        return false;
    if (!CheckFilter(pFilter))
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1402E71E0, ItemDropData, Check, 107, 0xFCB82703);

// @0x1402e7260
bool ItemDropData::CheckMap(unsigned nMapId) const
{
    if (m_mapDependency.empty())
        return true;
    if (m_mapDependency.find(nMapId) == m_mapDependency.end())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1402E7260, ItemDropData, CheckMap, 126, 0xA59E34AC);

// @0x1402e72f0
bool ItemDropData::CheckAssist(bool bAssist)
{
    if (!m_assistBonus)
        return true;
    if (m_assistBonus && bAssist)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1402E72F0, ItemDropData, CheckAssist, 55, 0xFC30DAFB);

// @0x1402e7330
bool ItemDropData::CheckFilter(ItemDropFilter* pFilter)
{
    if (pFilter == 0)
        return true;
    return pFilter->Accept(this);
}
MS2_REPLACE_METHOD(0x1402E7330, ItemDropData, CheckFilter, 51, 0xACAF4E01);

// @0x1402e7370
unsigned ItemDropData::GetCount()
{
    return m_count.GetValue();
}
MS2_REPLACE_METHOD(0x1402E7370, ItemDropData, GetCount, 31, 0xCADCD796);

// @0x1402e73a0
unsigned ItemDropData::GetCountScaled(float fRate)
{
    return m_count.GetValueScaled(fRate, fRate);
}
MS2_REPLACE_METHOD(0x1402E73A0, ItemDropData, GetCountScaled, 49, 0x1178CA7D);

// @0x1402e73e0
unsigned ItemDropData::GetMaxCount()
{
    return m_count.m_max;
}
MS2_REPLACE_METHOD(0x1402E73E0, ItemDropData, GetMaxCount, 14, 0x5A3CA153);

// @0x1402e7400
unsigned ItemDropData::GetMinCount()
{
    return m_count.m_min;
}
MS2_REPLACE_METHOD(0x1402E7400, ItemDropData, GetMinCount, 14, 0xC2344AAF);

// @0x1402e7420
unsigned ItemDropData::GetItemId()
{
    return m_itemID;
}
MS2_REPLACE_METHOD(0x1402E7420, ItemDropData, GetItemId, 14, 0x72E52537);

// @0x1402e7440
unsigned ItemDropData::GetItemId2()
{
    return m_itemID2;
}
MS2_REPLACE_METHOD(0x1402E7440, ItemDropData, GetItemId2, 14, 0x8AEE455B);

// @0x1402e7460
unsigned ItemDropData::GetWeight()
{
    return m_weight;
}
MS2_REPLACE_METHOD(0x1402E7460, ItemDropData, GetWeight, 14, 0xA25B27BF);

// @0x1402e7480
int ItemDropData::GetRank()
{
    return m_uiItemRank;
}
MS2_REPLACE_METHOD(0x1402E7480, ItemDropData, GetRank, 14, 0xD26D6807);

// @0x1402e74a0
int ItemDropData::GetEnchantLevel()
{
    return m_enchantLevel;
}
MS2_REPLACE_METHOD(0x1402E74A0, ItemDropData, GetEnchantLevel, 14, 0x828204CF);

// @0x1402e74c0
bool ItemDropData::IsTradableCountDeduction()
{
    return m_tradableCountDeduction;
}
MS2_REPLACE_METHOD(0x1402E74C0, ItemDropData, IsTradableCountDeduction, 15, 0x52A185E5);

// @0x1402e74e0
unsigned ItemDropData::GetSocketDataId()
{
    return m_socketDataID;
}
MS2_REPLACE_METHOD(0x1402E74E0, ItemDropData, GetSocketDataId, 14, 0x9A8B24F3);

// @0x1402e7500
bool ItemDropData::IsShowIconOnGachaUI()
{
    return m_showIconOnGachaUI;
}
MS2_REPLACE_METHOD(0x1402E7500, ItemDropData, IsShowIconOnGachaUI, 15, 0x3A9865C1);

// @0x1402e7520
bool ItemDropData::IsConstraintsQuest()
{
    return m_constraintsQuest;
}
MS2_REPLACE_METHOD(0x1402E7520, ItemDropData, IsConstraintsQuest, 15, 0x1ABF42D1);

// @0x1402e7540
bool ItemDropData::IsBindCharacter()
{
    return m_isBindCharacter;
}
MS2_REPLACE_METHOD(0x1402E7540, ItemDropData, IsBindCharacter, 15, 0x72A263DC);

// @0x1402e7560
bool ItemDropData::IsRePackingLimitCountDeduction()
{
    return m_rePackingLimitCountDeduction;
}
MS2_REPLACE_METHOD(0x1402E7560, ItemDropData, IsRePackingLimitCountDeduction, 15, 0x1AA5AAEB);

// @0x1402e7580
bool ItemDropData::IsDisableBreak()
{
    return m_disableBreak;
}
MS2_REPLACE_METHOD(0x1402E7580, ItemDropData, IsDisableBreak, 15, 0x42A9BB7A);

// @0x1402e75a0
bool ItemDropData::HasGrade(ItemDropGrade grade)
{
    return m_grade.Query(grade);
}
MS2_REPLACE_METHOD(0x1402E75A0, ItemDropData, HasGrade, 39, 0x9662F1F9);

// @0x1402e75d0
int ItemDropData::GetDropRank(int nArg, int nLevel, bool bAssist)
{
    if (m_grade.Remains())
        return PickGrade();
    int nRank = FUN_140166430()->FUN_1405f4d30(GetItemId(), nArg, nLevel, rand(), bAssist);
    return nRank;
}
MS2_REPLACE_METHOD(0x1402E75D0, ItemDropData, GetDropRank, 149, 0xEF08F3AC);

// @0x1402e7670
int ItemDropData::PickGrade()
{
    ItemDropGrade grade;
    if (m_grade.Pick(grade))
    {
        if (FUN_14053ff30(GetItemId(), grade))
            return grade;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1402E7670, ItemDropData, PickGrade, 82, 0x74C42950);

// @0x1402e76d0
void ItemDropData::Reset(void* p)
{
}
MS2_REPLACE_METHOD(0x1402E76D0, ItemDropData, Reset, 11, 0x02239C70);

// @0x1402e76f0
bool ItemDropData::IsValid()
{
    return true;
}
MS2_REPLACE_METHOD(0x1402E76F0, ItemDropData, IsValid, 8, 0x71679366);

// @0x1402e7700
ItemDropDataGlobal::ItemDropDataGlobal() : m_minLevel(0), m_maxLevel(0)
{
}

// @0x1402e7750
bool ItemDropDataGlobal::Load(Unk_140165cf0* pElem)
{
    if (!ItemDropData::Load(pElem))
        return false;
    FUN_140873220(pElem, "minLevel", m_minLevel);
    FUN_140873220(pElem, "maxLevel", m_maxLevel);
    return true;
}
MS2_REPLACE_METHOD(0x1402E7750, ItemDropDataGlobal, Load, 109, 0xFB87026F);

// @0x1402e77d0
CString ItemDropDataGlobal::GetTypeName()
{
    return "Global";
}
MS2_REPLACE_METHOD(0x1402E77D0, ItemDropDataGlobal, GetTypeName, 61, 0x1BC3399D);

// @0x1402e7820
bool ItemDropDataGlobal::CheckLevel(unsigned nLevel)
{
    if (m_minLevel != 0 && nLevel < m_minLevel)
        return false;
    if (m_maxLevel != 0 && nLevel > m_maxLevel)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1402E7820, ItemDropDataGlobal, CheckLevel, 82, 0xA1438D45);

// @0x1402e7880
ItemDropDataIndividual::ItemDropDataIndividual()
    : m_properJobWeight(0), m_imProperJobWeight(0), m_isAnnounce(false), m_showTooltip((ItemDropTooltip)0)
{
}

// @0x1402e78f0
bool ItemDropDataIndividual::Load(Unk_140165cf0* pElem)
{
    if (!ItemDropData::Load(pElem))
        return false;
    FUN_140873220(pElem, "properJobWeight", m_properJobWeight);
    FUN_140873220(pElem, "imProperJobWeight", m_imProperJobWeight);
    FUN_1408736d0(pElem, "isAnnounce", m_isAnnounce);
    XmlValue(pElem, "showTooltip", m_showTooltip);
    return true;
}
MS2_REPLACE_METHOD(0x1402E78F0, ItemDropDataIndividual, Load, 171, 0x42F36FF8);

// @0x1402e79b0
CString ItemDropDataIndividual::GetTypeName()
{
    return "Indi";
}
MS2_REPLACE_METHOD(0x1402E79B0, ItemDropDataIndividual, GetTypeName, 61, 0x08247872);

// @0x1402e7a00
unsigned ItemDropDataIndividual::GetProperJobWeight()
{
    return m_properJobWeight;
}
MS2_REPLACE_METHOD(0x1402E7A00, ItemDropDataIndividual, GetProperJobWeight, 17, 0x0A012C13);

// @0x1402e7a20
unsigned ItemDropDataIndividual::GetImProperJobWeight()
{
    return m_imProperJobWeight;
}
MS2_REPLACE_METHOD(0x1402E7A20, ItemDropDataIndividual, GetImProperJobWeight, 17, 0xA49D819F);

// @0x1402e7a40
bool ItemDropDataIndividual::IsAnnounce()
{
    return m_isAnnounce;
}
MS2_REPLACE_METHOD(0x1402E7A40, ItemDropDataIndividual, IsAnnounce, 18, 0x01A1D2ED);

// @0x1402e7a60
ItemDropTooltip ItemDropDataIndividual::GetShowTooltip()
{
    return m_showTooltip;
}
MS2_REPLACE_METHOD(0x1402E7A60, ItemDropDataIndividual, GetShowTooltip, 17, 0xD9D952B7);

// @0x1402e7a80
ItemDropGlobalGroup::ItemDropGlobalGroup() : m_dropGroupID(0)
{
}

// @0x1402e7ad0
bool ItemDropGlobalGroup::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dropGroupID", m_dropGroupID);
    for (Unk_140165cf0* pChild : pElem->FUN_140165cf0("v"))
    {
        if (!FUN_14028f710(pChild))
            continue;
        MS2Ptr<ItemDropDataGlobal> pData(new ItemDropDataGlobal);
        if (!pData->Load(pChild))
            continue;
        pData->OnLoad();
        Add(pData);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1402E7AD0, ItemDropGlobalGroup, Load, 441, 0x7AA259D6);

// @0x1402e7c90
unsigned ItemDropGlobalGroup::GetId()
{
    return m_dropGroupID;
}
MS2_REPLACE_METHOD(0x1402E7C90, ItemDropGlobalGroup, GetId, 14, 0x72E52537);

// @0x1402e7cb0
std::vector<MS2Ptr<ItemDropDataGlobal>>& ItemDropGlobalGroup::GetItems()
{
    return m_items;
}
MS2_REPLACE_METHOD(0x1402E7CB0, ItemDropGlobalGroup, GetItems, 15, 0x5731F599);

// @0x1402e7cd0
void ItemDropGlobalGroup::Add(MS2Ptr<ItemDropDataGlobal> pData)
{
    m_items.push_back(pData);
}
MS2_REPLACE_METHOD(0x1402E7CD0, ItemDropGlobalGroup, Add, 61, 0x602A1C76);

// @0x1402e7d20
ItemDropGlobalBox::ItemDropGlobalBox()
    : m_unk_18(0), m_isOwnerDrop(false), m_minLevel(0), m_maxLevel(0), m_continentCondition(0),
      m_mapTypeCondition((ItemDropMapType)0)
{
}

// @0x1402e7dc0
bool ItemDropGlobalBox::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dropGroupIDs", m_dropGroupIDs);
    FUN_1408730a0(pElem, "isOwnerDrop", m_isOwnerDrop);
    FUN_1408731e0(pElem, "continentCondition", m_continentCondition);
    XmlValue(pElem, "mapTypeCondition", m_mapTypeCondition);
    FUN_140873220(pElem, "minLevel", m_minLevel);
    FUN_140873220(pElem, "maxLevel", m_maxLevel);
    std::vector<unsigned> counts;
    std::vector<unsigned> probabilities;
    XmlTokenList(pElem, "dropCount", counts);
    XmlTokenList(pElem, "dropCountProbability", probabilities);
    if (counts.size() != probabilities.size())
    {
        FUN_140177a80(FUN_140166440(), 1, 0x13, L"(Global)ID: {0}, [{1}] dropCount, dropCountProbability", m_dropGroupIDs);
        return false;
    }
    if (counts.size() != probabilities.size())
        return false;
    for (size_t i = 0; i < counts.size(); ++i)
        m_dropCount[100].Register(probabilities[i], counts[i]);
    m_dropCount[150] = m_dropCount[100];
    m_dropCount[150].Rescale(1.5f, 0);
    m_dropCount[200] = m_dropCount[100];
    m_dropCount[200].Rescale(2.0f, 0);
    m_dropCount[300] = m_dropCount[100];
    m_dropCount[300].Rescale(3.0f, 0);
    return true;
}
MS2_REPLACE_METHOD(0x1402E7DC0, ItemDropGlobalBox, Load, 1169, 0x17BC887C);

// @0x1402e8260
unsigned ItemDropGlobalBox::GetUnk18()
{
    return m_unk_18;
}
MS2_REPLACE_METHOD(0x1402E8260, ItemDropGlobalBox, GetUnk18, 14, 0x72E52537);

// @0x1402e8280
unsigned ItemDropGlobalBox::GetDropCount(float fRate) const
{
    int nCount = 0;
    if (m_dropCount.size() < 1)
        return 0;
    int nRate = (int)(fRate * 100.0f);
    std::map<int, ItemDropPicker<int>>::const_iterator it = m_dropCount.find(nRate);
    if (it == m_dropCount.end())
    {
        int nBaseRate = 100;
        std::map<int, ItemDropPicker<int>>::const_iterator itBase = m_dropCount.find(nBaseRate);
        if (itBase == m_dropCount.end())
            return 0;
        if (!itBase->second.Remains())
            return 0;
        ItemDropPicker<int> picker(itBase->second);
        picker.Rescale(fRate, 0);
        picker.Pick(nCount);
    }
    else
    {
        if (!it->second.Remains())
            return 0;
        it->second.Pick(nCount);
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x1402E8280, ItemDropGlobalBox, GetDropCount, 442, 0x4C3C43FE);

// @0x1402e8440
unsigned ItemDropGlobalBox::GetDropGroupId()
{
    return m_dropGroupIDs;
}
MS2_REPLACE_METHOD(0x1402E8440, ItemDropGlobalBox, GetDropGroupId, 14, 0x828204CF);

// @0x1402e8460
bool ItemDropGlobalBox::IsOwnerDrop()
{
    return m_isOwnerDrop;
}
MS2_REPLACE_METHOD(0x1402E8460, ItemDropGlobalBox, IsOwnerDrop, 15, 0x0A82FF79);

// @0x1402e8480
bool ItemDropGlobalBox::CheckMap(int nMapId)
{
    if (!CheckContinent(nMapId))
        return false;
    if (!CheckMapType(nMapId))
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1402E8480, ItemDropGlobalBox, CheckMap, 70, 0x7ED96E9C);

// @0x1402e84d0
bool ItemDropGlobalBox::CheckLevel(unsigned nLevel)
{
    if (m_minLevel != 0 && nLevel < m_minLevel)
        return false;
    if (m_maxLevel != 0 && nLevel > m_maxLevel)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1402E84D0, ItemDropGlobalBox, CheckLevel, 70, 0x86739229);

// @0x1402e8520
bool ItemDropGlobalBox::CheckContinent(int nMapId)
{
    if (m_continentCondition == 0)
        return true;
    MS2Ptr<CFieldData> pField = CFieldData::FUN_140374140(nMapId);
    if (pField == 0)
        return false;
    return m_continentCondition == pField->GetContinentCode();
}
MS2_REPLACE_METHOD(0x1402E8520, ItemDropGlobalBox, CheckContinent, 168, 0xA22C2B15);

// @0x1402e85d0
bool ItemDropGlobalBox::CheckMapType(int nMapId)
{
    if (m_mapTypeCondition == 0)
        return true;
    MS2Ptr<CFieldData> pField = CFieldData::FUN_140374140(nMapId);
    if (pField == 0)
        return false;
    return m_mapTypeCondition == pField->m_nMapType;
}
MS2_REPLACE_METHOD(0x1402E85D0, ItemDropGlobalBox, CheckMapType, 163, 0xF62BA1CF);

// @0x1402e8680
ItemDropGlobalBoxGroup::ItemDropGlobalBoxGroup() : m_dropBoxID(0)
{
}

// @0x1402e86d0
unsigned ItemDropGlobalBoxGroup::GetId()
{
    return m_dropBoxID;
}
MS2_REPLACE_METHOD(0x1402E86D0, ItemDropGlobalBoxGroup, GetId, 14, 0x72E52537);

// @0x1402e86f0
bool ItemDropGlobalBoxGroup::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dropBoxID", m_dropBoxID);
    for (Unk_140165cf0* pChild : pElem->FUN_140165cf0("v"))
    {
        if (!FUN_14028f710(pChild))
            continue;
        MS2Ptr<ItemDropGlobalBox> pBox(new ItemDropGlobalBox);
        if (!pBox->Load(pChild))
            continue;
        m_boxes.push_back(pBox);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1402E86F0, ItemDropGlobalBoxGroup, Load, 375, 0x7179C60E);

// @0x1402e8870
std::vector<MS2Ptr<ItemDropGlobalBox>>& ItemDropGlobalBoxGroup::GetBoxes()
{
    return m_boxes;
}
MS2_REPLACE_METHOD(0x1402E8870, ItemDropGlobalBoxGroup, GetBoxes, 15, 0x5731F599);

// @0x1402e8890
ItemDropIndividualGroup::ItemDropIndividualGroup()
    : m_dropGroupID(0), m_dropGroupMinLevel(0), m_smartDropRate(0), m_isApplySmartGenderDrop(false),
      m_serverDrop(false)
{
}

// @0x1402e8940
ItemDropIndividualGroup::~ItemDropIndividualGroup()
{
}

// @0x1402e89a0
unsigned ItemDropIndividualGroup::GetId()
{
    return m_dropGroupID;
}
MS2_REPLACE_METHOD(0x1402E89A0, ItemDropIndividualGroup, GetId, 14, 0x72E52537);

// @0x1402e89c0
int ItemDropIndividualGroup::PickDropCount()
{
    int nCount = 0;
    m_dropCount.Pick(nCount);
    return nCount;
}
MS2_REPLACE_METHOD(0x1402E89C0, ItemDropIndividualGroup, PickDropCount, 48, 0x7D314903);

// @0x1402e8a00
unsigned ItemDropIndividualGroup::GetSmartDropRate()
{
    return m_smartDropRate;
}
MS2_REPLACE_METHOD(0x1402E8A00, ItemDropIndividualGroup, GetSmartDropRate, 14, 0x69D980EB);

// @0x1402e8a20
bool ItemDropIndividualGroup::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dropGroupID", m_dropGroupID);
    FUN_140873220(pElem, "smartDropRate", m_smartDropRate);
    FUN_1408730a0(pElem, "isApplySmartGenderDrop", m_isApplySmartGenderDrop);
    FUN_140873220(pElem, "dropGroupMinLevel", m_dropGroupMinLevel);
    FUN_1408730a0(pElem, "serverDrop", m_serverDrop);
    std::vector<unsigned> counts;
    std::vector<unsigned> probabilities;
    XmlTokenList(pElem, "dropCount", counts);
    XmlTokenList(pElem, "dropCountProbability", probabilities);
    if (counts.empty())
    {
        m_dropCount.Register(1, 1);
    }
    else if (counts.size() == 1)
    {
        m_dropCount.Register(1, *counts.begin());
    }
    else
    {
        if (counts.size() != probabilities.size())
            return false;
        for (size_t i = 0; i < counts.size(); ++i)
            m_dropCount.Register(probabilities[i], counts[i]);
    }
    for (Unk_140165cf0* pChild : pElem->FUN_140165cf0("v"))
    {
        if (!FUN_14028f710(pChild))
            continue;
        MS2Ptr<ItemDropDataIndividual> pData(new ItemDropDataIndividual);
        pData->Load(pChild);
        pData->OnLoad();
        m_dataPicker.Register(pData->GetWeight(), pData);
        m_items.push_back(pData);
    }
    if (m_items.empty())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1402E8A20, ItemDropIndividualGroup, Load, 1115, 0x44E8C029);

// @0x1402e8e90
bool ItemDropIndividualGroup::CheckLevel(unsigned nLevel)
{
    if (m_dropGroupMinLevel <= nLevel)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1402E8E90, ItemDropIndividualGroup, CheckLevel, 30, 0x589390AA);

// @0x1402e8ec0
bool ItemDropIndividualGroup::IsApplySmartGenderDrop()
{
    return m_isApplySmartGenderDrop;
}
MS2_REPLACE_METHOD(0x1402E8EC0, ItemDropIndividualGroup, IsApplySmartGenderDrop, 15, 0x232B835D);

// @0x1402e8ee0
bool ItemDropIndividualGroup::IsServerDrop()
{
    return m_serverDrop;
}
MS2_REPLACE_METHOD(0x1402E8EE0, ItemDropIndividualGroup, IsServerDrop, 15, 0x432F8754);

// @0x1402e8f00
std::vector<MS2Ptr<ItemDropDataIndividual>>& ItemDropIndividualGroup::GetItems()
{
    return m_items;
}
MS2_REPLACE_METHOD(0x1402E8F00, ItemDropIndividualGroup, GetItems, 15, 0x77A75649);

// @0x1402e8f20
ItemDropIndividualBox::ItemDropIndividualBox() : m_dropBoxID(0), m_probVer(0)
{
}

// @0x1402e8f80
bool ItemDropIndividualBox::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dropBoxID", m_dropBoxID);
    FUN_140873220(pElem, "probVer", m_probVer);
    for (Unk_140165cf0* pChild : pElem->FUN_140165cf0("group"))
    {
        if (!FUN_14028f710(pChild))
            continue;
        MS2Ptr<ItemDropIndividualGroup> pGroup(new ItemDropIndividualGroup);
        if (!pGroup->Load(pChild))
            continue;
        m_groups.push_back(pGroup);
    }
    if (m_groups.empty())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1402E8F80, ItemDropIndividualBox, Load, 441, 0xA0FEDCED);

// @0x1402e9140
unsigned ItemDropIndividualBox::GetId()
{
    return m_dropBoxID;
}
MS2_REPLACE_METHOD(0x1402E9140, ItemDropIndividualBox, GetId, 14, 0x828204CF);

// @0x1402e9160
unsigned ItemDropIndividualBox::GetProbVer()
{
    return m_probVer;
}
MS2_REPLACE_METHOD(0x1402E9160, ItemDropIndividualBox, GetProbVer, 14, 0x9A8B24F3);

// @0x1402e9180
ItemDropContext::ItemDropContext()
    : m_unk_00(0), m_job(0), m_gender(2), m_mapId(0), m_isOwner(true), m_level(0), m_userLevel(0), m_rankArg(1),
      m_isAssist(true), m_dropRate(1.0f), m_serverDrop(false), m_pFilter(0)
{
}

// @0x1402e9220
int ItemDropContext::GetLevel()
{
    static int s_nLevelBoundary = FUN_1401d3200()->ItemDropLevelMaxBoundry.Read();
    int nLevel = m_level + s_nLevelBoundary;
    return (std::min)(m_userLevel, nLevel);
}
MS2_REPLACE_METHOD(0x1402E9220, ItemDropContext, GetLevel, 160, 0xEBCB217E);

// @0x1402e92d0
ItemDropResult::ItemDropResult()
    : m_itemId(0), m_count(0), m_maxCount(0), m_bAnnounce(false), m_enchant(0), m_socketDataId(0), m_tooltip(0),
      m_tradableCountDeduction(false), m_rePackingLimitCountDeduction(false), m_isBindCharacter(false),
      m_disableBreak(false), m_bServerDrop(false), m_showIconOnGachaUI(true), m_weight(0), m_totalWeight(0),
      m_groupId(0), m_smartGender(false), m_rank(0)
{
}

// @0x1402e9400
ItemDropResult::ItemDropResult(unsigned nItemId, unsigned nCount, int nRank, int nEnchant, unsigned nWeight,
                               unsigned nTotalWeight, unsigned nGroupId, bool bSmartGender, bool bAnnounce,
                               int nTooltip, bool bTradable, bool bIsBind, bool bRePacking, bool bDisableBreak)
    : m_itemId(nItemId), m_count(nCount), m_maxCount(0), m_bAnnounce(bAnnounce), m_enchant(nEnchant),
      m_socketDataId(0), m_tooltip(nTooltip), m_tradableCountDeduction(bTradable),
      m_rePackingLimitCountDeduction(bRePacking), m_isBindCharacter(bIsBind), m_disableBreak(bDisableBreak),
      m_bServerDrop(false), m_showIconOnGachaUI(true), m_weight(nWeight), m_totalWeight(nTotalWeight),
      m_groupId(nGroupId), m_smartGender(bSmartGender), m_rank(0)
{
    SetRank(nRank);
}

// @0x1402e9580
bool ItemDropResult::operator<(ItemDropResult& o)
{
    if (m_itemId < o.m_itemId)
        return true;
    else if (m_itemId == o.m_itemId && vfunc_o18_1() < o.vfunc_o18_1())
        return true;
    return false;
}

// @0x1402e9600
unsigned int ItemDropResult::vfunc_o18_0()
{
    return m_itemId;
}
MS2_REPLACE_METHOD(0x1402E9600, ItemDropResult, vfunc_o18_0, 14, 0xA25B27BF);

// @0x1402e9620
int ItemDropResult::vfunc_o18_1()
{
    return m_rank;
}
MS2_REPLACE_METHOD(0x1402E9620, ItemDropResult, vfunc_o18_1, 14, 0xD1D12A47);

// @0x1402e9640
unsigned int ItemDropResult::vfunc_o18_2()
{
    return m_count;
}
MS2_REPLACE_METHOD(0x1402E9640, ItemDropResult, vfunc_o18_2, 14, 0xBA6447E3);

// @0x1402e9660
bool ItemDropResult::vfunc_o18_3()
{
    return m_tradableCountDeduction;
}
MS2_REPLACE_METHOD(0x1402E9660, ItemDropResult, vfunc_o18_3, 15, 0x3A9865C1);

// @0x1402e9680
bool ItemDropResult::IsRePackingLimitCountDeduction()
{
    return m_rePackingLimitCountDeduction;
}
MS2_REPLACE_METHOD(0x1402E9680, ItemDropResult, IsRePackingLimitCountDeduction, 15, 0x5A9943B8);

// @0x1402e96a0
bool ItemDropResult::IsDisableBreak()
{
    return m_disableBreak;
}
MS2_REPLACE_METHOD(0x1402E96A0, ItemDropResult, IsDisableBreak, 15, 0x2A9D7556);

// @0x1402e96c0
bool ItemDropResult::Set(MS2Ptr<ItemDropDataIndividual> pData)
{
    m_itemId = pData->GetItemId();
    m_count = pData->GetMinCount();
    SetRank(pData->GetRank());
    m_enchant = pData->GetEnchantLevel();
    m_bAnnounce = false;
    m_tooltip = 0;
    m_tradableCountDeduction = pData->IsTradableCountDeduction();
    m_isBindCharacter = false;
    m_rePackingLimitCountDeduction = pData->IsRePackingLimitCountDeduction();
    m_disableBreak = pData->IsDisableBreak();
    m_maxCount = pData->GetMaxCount();
    m_socketDataId = pData->GetSocketDataId();
    m_showIconOnGachaUI = pData->IsShowIconOnGachaUI();
    m_itemLife = pData->m_itemLife;
    return true;
}
MS2_REPLACE_METHOD(0x1402E96C0, ItemDropResult, Set, 373, 0x67F468A4);

// @0x1402e9840
double ItemDropResult::GetProbability()
{
    if (m_totalWeight == 0)
        return 0.0;
    return (double)m_weight / (double)m_totalWeight;
}
MS2_REPLACE_METHOD(0x1402E9840, ItemDropResult, GetProbability, 52, 0x45140BF0);

// @0x1402e9880
bool ItemDropResult::HasItemLife()
{
    if (m_itemLife && m_itemLife->FUN_14026f5d0())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1402E9880, ItemDropResult, HasItemLife, 95, 0xE03CF239);

// @0x1402e98f0
void ItemDropResult::SetRank(int nRank)
{
    m_rank = nRank;
    if (m_rank == 0)
        m_rank = FUN_14053feb0(m_itemId);
}
MS2_REPLACE_METHOD(0x1402E98F0, ItemDropResult, SetRank, 62, 0xCAEEAB4F);

// @0x1402e9940
ItemDropTable::ItemDropTable()
{
}

// @0x1402e9a00
ItemDropTable::~ItemDropTable()
{
    Clear();
}

// @0x1402e9ad0
bool ItemDropTable::Initialize()
{
    if (!LoadIndividualBoxes())
        return false;
    SetInit(true);
    return true;
}
MS2_REPLACE_METHOD(0x1402E9AD0, ItemDropTable, Initialize, 44, 0xBB672298);

// @0x1402e9b10
void ItemDropTable::Drop(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out)
{
    if (IsGlobalBox(nBoxId))
        DropGlobal(nBoxId, ctx, out);
    else
        DropIndividual(nBoxId, ctx, out);
}
MS2_REPLACE_METHOD(0x1402E9B10, ItemDropTable, Drop, 94, 0xE23079DD);

// @0x1402e9b80
void ItemDropTable::DropGlobal(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out)
{
    CheckInit();
    if (nBoxId == 0)
        return;
    if (TSingleton<CGameEventValueManager>::GetInstance()->ShutdownDropBox()->IsShutdown(nBoxId) == true)
        return;
    int nLevel = ctx.GetLevel();
    std::unordered_map<unsigned, MS2Ptr<ItemDropGlobalBoxGroup>>::iterator itBox = m_globalBoxes.find(nBoxId);
    if (itBox == m_globalBoxes.end())
        return;
    for (MS2Ptr<ItemDropGlobalBox> pBox : itBox->second->GetBoxes())
    {
        if (!pBox->CheckLevel(nLevel))
            continue;
        if (pBox->IsOwnerDrop() && !ctx.m_isOwner)
            continue;
        if (!pBox->CheckMap(ctx.m_mapId))
            continue;
        unsigned nDropCount = pBox->GetDropCount(ctx.m_dropRate);
        if (nDropCount == 0)
            continue;
        std::unordered_map<unsigned, MS2Ptr<ItemDropGlobalGroup>>::iterator itGroup = m_globalGroups.find(pBox->GetDropGroupId());
        if (itGroup == m_globalGroups.end())
            continue;
        MS2Ptr<ItemDropGlobalGroup> pGroup = itGroup->second;
        if (pGroup == 0)
            continue;
        ItemDropPicker<ItemDropDataGlobal*> picker;
        for (MS2Ptr<ItemDropDataGlobal> pData : pGroup->GetItems())
        {
            if (!pData->CheckLevel(nLevel))
                continue;
            if (!pData->Check(ctx.m_mapId, ctx.m_isAssist, ctx.m_pFilter))
                continue;
            MS2Ptr<CItemData> pItem = FUN_14053f870(pData->GetItemId());
            if (!pItem)
                continue;
            if (ctx.m_job != 0 && !pItem->limit.FUN_140545da0(ctx.m_job))
                continue;
            picker.Register(pData->GetWeight(), pData);
        }
        if (!picker.Remains())
            continue;
        unsigned nLoop = (std::min)(nDropCount, 15u);
        while (nLoop > 0)
        {
            ItemDropDataGlobal* pData = 0;
            picker.Pick(pData);
            if (pData == 0)
                break;
            int nItemCount = 0;
            float fRate = TSingleton<CGloabalFactor>::GetInstance()->FUN_1404c1810(2, pBox->GetDropGroupId());
            if (FUN_14028d470(fRate, 1.0f) == true)
                nItemCount = pData->GetCount();
            else
                nItemCount = pData->GetCountScaled(fRate);
            int nRank = pData->GetDropRank(ctx.m_rankArg, nLevel, ctx.m_isAssist);
            MS2Ptr<CItemData> pItem = FUN_14053f870(pData->GetItemId());
            if (pItem == 0)
                break;
            const int& nSlotMax = pItem->property.slotMax;
            while (nItemCount > 0)
            {
                int nStack = (std::min)(nItemCount, nSlotMax);
                if (nStack <= 0)
                    nStack = nItemCount;
                ItemDropResult result(pData->GetItemId(), nStack, nRank, pData->GetEnchantLevel(), pData->GetWeight(),
                                      picker.GetTotal(), 0, false, false, 0, pData->IsTradableCountDeduction(), false,
                                      false, false);
                result.m_socketDataId = pData->GetSocketDataId();
                result.m_itemLife = pData->m_itemLife;
                out.push_back(result);
                nItemCount -= nStack;
            }
            nLoop--;
        }
    }
}
MS2_REPLACE_METHOD(0x1402E9B80, ItemDropTable, DropGlobal, 2361, 0x85616E05);

// @0x1402ea4c0
bool ItemDropTable::GetBoxItems(unsigned nBoxId, std::vector<ItemDropResult>& out)
{
    CheckInit();
    if (TSingleton<CGameEventValueManager>::GetInstance()->ShutdownDropBox()->IsShutdown(nBoxId) == true)
        return false;
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>>::iterator it = m_individualBoxes.find(nBoxId);
    if (it == m_individualBoxes.end())
        return false;
    MS2Ptr<ItemDropIndividualBox> pBox = it->second;
    if (pBox == 0)
        return false;
    for (MS2Ptr<ItemDropIndividualGroup> pGroup : pBox->m_groups)
    {
        for (size_t i = 0; i < pGroup->m_items.size(); ++i)
        {
            MS2Ptr<ItemDropDataIndividual> pData = pGroup->m_items[i];
            ItemDropResult result(pData->GetItemId(), pData->GetCount(), pData->GetRank(), pData->GetEnchantLevel(),
                                  pData->GetWeight(), pGroup->GetDataPicker()->GetTotal(), pGroup->GetId(),
                                  pGroup->IsApplySmartGenderDrop(), false, 0, pData->IsTradableCountDeduction(), false,
                                  pData->IsRePackingLimitCountDeduction(), pData->IsDisableBreak());
            result.m_socketDataId = pData->GetSocketDataId();
            result.m_showIconOnGachaUI = pData->IsShowIconOnGachaUI();
            result.m_itemLife = pData->m_itemLife;
            out.push_back(result);
            if (pData->GetItemId2() != 0)
            {
                ItemDropResult result2(pData->GetItemId2(), pData->GetCount(), pData->GetRank(),
                                       pData->GetEnchantLevel(), 0, 0, 0, false, false, 0,
                                       pData->IsTradableCountDeduction(), false,
                                       pData->IsRePackingLimitCountDeduction(), pData->IsDisableBreak());
                result2.m_socketDataId = pData->GetSocketDataId();
                result2.m_itemLife = pData->m_itemLife;
                out.push_back(result2);
            }
        }
    }
    return true;
}

// @0x1402eab20
bool ItemDropTable::GetBoxItems(unsigned nBoxId, std::vector<MS2Ptr<ItemDropResult>>& out)
{
    CheckInit();
    if (TSingleton<CGameEventValueManager>::GetInstance()->ShutdownDropBox()->IsShutdown(nBoxId) == true)
        return false;
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>>::iterator it = m_individualBoxes.find(nBoxId);
    if (it == m_individualBoxes.end())
        return false;
    MS2Ptr<ItemDropIndividualBox> pBox = it->second;
    if (pBox == 0)
        return false;
    for (MS2Ptr<ItemDropIndividualGroup> pGroup : pBox->m_groups)
    {
        for (size_t i = 0; i < pGroup->m_items.size(); ++i)
        {
            MS2Ptr<ItemDropDataIndividual> pData = pGroup->m_items[i];
            MS2Ptr<ItemDropResult> pResult(new ItemDropResult);
            if (pResult)
                pResult->Set(pData);
            out.push_back(pResult);
            if (pData->GetItemId2() != 0)
            {
                MS2Ptr<ItemDropResult> pResult2(new ItemDropResult);
                if (pResult2)
                    pResult2->Set(pData);
                out.push_back(pResult2);
            }
        }
    }
    return true;
}

// @0x1402eaf10
bool ItemDropTable::GetBoxItems(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out, bool bSkipHidden)
{
    CheckInit();
    if (TSingleton<CGameEventValueManager>::GetInstance()->ShutdownDropBox()->IsShutdown(nBoxId) == true)
        return false;
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>>::iterator it = m_individualBoxes.find(nBoxId);
    if (it == m_individualBoxes.end())
        return false;
    MS2Ptr<ItemDropIndividualBox> pBox = it->second;
    if (pBox == 0)
        return false;
    for (MS2Ptr<ItemDropIndividualGroup> pGroup : pBox->m_groups)
    {
        for (size_t i = 0; i < pGroup->m_items.size(); ++i)
        {
            MS2Ptr<ItemDropDataIndividual> pData = pGroup->m_items[i];
            MS2Ptr<CItemData> pItem = FUN_14053f870(pData->GetItemId());
            if (pItem == 0)
                continue;
            if (bSkipHidden && pData->GetShowTooltip() == 2)
                continue;
            if (pGroup->IsApplySmartGenderDrop() && static_cast<Unk_DropItemData*>(pItem.operator->())->FUN_14053c940(ctx.m_gender) == 0)
                continue;
            if (pGroup->GetSmartDropRate() > 0 && !pItem->limit.FUN_140545da0(ctx.m_job))
                continue;
            ItemDropResult result(pData->GetItemId(), pData->GetCount(), pData->GetRank(), pData->GetEnchantLevel(),
                                  pData->GetWeight(), pGroup->GetDataPicker()->GetTotal(), pGroup->GetId(),
                                  pGroup->IsApplySmartGenderDrop(), false, pData->GetShowTooltip(),
                                  pData->IsTradableCountDeduction(), false, pData->IsRePackingLimitCountDeduction(),
                                  pData->IsDisableBreak());
            result.m_socketDataId = pData->GetSocketDataId();
            result.m_maxCount = pData->GetMaxCount();
            result.m_itemLife = pData->m_itemLife;
            out.push_back(result);
            if (pData->GetItemId2() != 0)
            {
                ItemDropResult result2(pData->GetItemId2(), pData->GetCount(), pData->GetRank(),
                                       pData->GetEnchantLevel(), 0, 0, 0, false, false, pData->GetShowTooltip(),
                                       pData->IsTradableCountDeduction(), false,
                                       pData->IsRePackingLimitCountDeduction(), pData->IsDisableBreak());
                result2.m_socketDataId = pData->GetSocketDataId();
                result2.m_itemLife = pData->m_itemLife;
                out.push_back(result2);
            }
        }
    }
    return true;
}

// @0x1402eb730
bool ItemDropTable::GetUniqueBoxItems(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out)
{
    CheckInit();
    std::set<unsigned> itemIds;
    if (TSingleton<CGameEventValueManager>::GetInstance()->ShutdownDropBox()->IsShutdown(nBoxId) == true)
        return false;
    if (IsGlobalBox(nBoxId))
        return false;
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>>::iterator it = m_individualBoxes.find(nBoxId);
    if (it == m_individualBoxes.end())
        return false;
    MS2Ptr<ItemDropIndividualBox> pBox = it->second;
    if (pBox == 0)
        return false;
    for (MS2Ptr<ItemDropIndividualGroup> pGroup : pBox->m_groups)
    {
        for (MS2Ptr<ItemDropDataIndividual> pData : pGroup->m_items)
        {
            MS2Ptr<CItemData> pItem = FUN_14053f870(pData->GetItemId());
            if (pItem == 0)
                continue;
            if (itemIds.find(pData->GetItemId()) != itemIds.end())
                continue;
            if (pData->GetShowTooltip() == 2)
                continue;
            if (pGroup->IsApplySmartGenderDrop() && static_cast<Unk_DropItemData*>(pItem.operator->())->FUN_14053c940(ctx.m_gender) == 0)
                continue;
            if (pGroup->GetSmartDropRate() > 0 && !pItem->limit.FUN_140545da0(ctx.m_job))
                continue;
            ItemDropResult result(pData->GetItemId(), 1, pData->GetRank(), pData->GetEnchantLevel(), pData->GetWeight(),
                                  pGroup->GetDataPicker()->GetTotal(), pGroup->GetId(),
                                  pGroup->IsApplySmartGenderDrop(), false, pData->GetShowTooltip(),
                                  pData->IsTradableCountDeduction(), false, pData->IsRePackingLimitCountDeduction(),
                                  pData->IsDisableBreak());
            result.m_socketDataId = pData->GetSocketDataId();
            out.push_back(result);
            itemIds.insert(pData->GetItemId());
            if (pData->GetItemId2() != 0)
            {
                ItemDropResult result2(pData->GetItemId2(), pData->GetCount(), pData->GetRank(),
                                       pData->GetEnchantLevel(), 0, 0, 0, false, false, pData->GetShowTooltip(),
                                       pData->IsTradableCountDeduction(), false,
                                       pData->IsRePackingLimitCountDeduction(), pData->IsDisableBreak());
                result2.m_socketDataId = pData->GetSocketDataId();
                out.push_back(result2);
                itemIds.insert(pData->GetItemId2());
            }
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x1402EB730, ItemDropTable, GetUniqueBoxItems, 2341, 0x82E6246D);

// @0x1402ec060
bool ItemDropTable::IsGlobalBox(unsigned nBoxId)
{
    const unsigned nIndividualBoxIdMin = 10000000;
    if (nBoxId < nIndividualBoxIdMin)
        return true;
    return false;
}
MS2_REPLACE(0x1402EC060, ItemDropTable::IsGlobalBox, 36, 0x73FC9D0E);

// @0x1402ec090
bool ItemDropTable::HasGlobalBox(unsigned nBoxId)
{
    return m_globalBoxes.find(nBoxId) != m_globalBoxes.end();
}
MS2_REPLACE_METHOD(0x1402EC090, ItemDropTable, HasGlobalBox, 85, 0xDB8E3F1E);

// @0x1402ec0f0
bool ItemDropTable::HasIndividualBox(unsigned nBoxId)
{
    return m_individualBoxes.find(nBoxId) != m_individualBoxes.end();
}
MS2_REPLACE_METHOD(0x1402EC0F0, ItemDropTable, HasIndividualBox, 90, 0x648D2E9E);

// @0x1402ec150
void ItemDropTable::Clear()
{
    m_globalGroups.clear();
    m_globalBoxes.clear();
    m_individualBoxes.clear();
}
MS2_REPLACE_METHOD(0x1402EC150, ItemDropTable, Clear, 67, 0xA37CC753);

// @0x1402ec1c0
bool ItemDropTable::HasItem(unsigned nBoxId, int nItemId, int nRank)
{
    CheckInit();
    if (IsGlobalBox(nBoxId))
        return false;
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>>::iterator it = m_individualBoxes.find(nBoxId);
    if (it == m_individualBoxes.end())
        return false;
    MS2Ptr<ItemDropIndividualBox> pBox = it->second;
    if (pBox == 0)
        return false;
    for (MS2Ptr<ItemDropIndividualGroup> pGroup : pBox->m_groups)
    {
        for (size_t i = 0; i < pGroup->m_items.size(); ++i)
        {
            MS2Ptr<ItemDropDataIndividual> pData = pGroup->m_items[i];
            if (pData == 0)
                continue;
            if (pData->GetItemId() != nItemId)
                continue;
            MS2Ptr<CItemData> pItem = FUN_14053f870(nItemId);
            if (pItem == 0)
                continue;
            if (pItem->FUN_14053cf90())
            {
                if (FUN_14053ff30(nItemId, nRank))
                    return true;
            }
            else if (pItem->FUN_14053cbc0())
            {
                if (pData->HasGrade((ItemDropGrade)nRank))
                    return true;
            }
            else
            {
                if (FUN_14053ff30(nItemId, nRank))
                    return true;
            }
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x1402EC1C0, ItemDropTable, HasItem, 960, 0xF3A6DC42);

// @0x1402ec590
void ItemDropTable::DropGroup(unsigned nBoxId, unsigned nGroupId, ItemDropContext& ctx, std::vector<ItemDropResult>& out)
{
    CheckInit();
    if (nBoxId == 0)
        return;
    if (TSingleton<CGameEventValueManager>::GetInstance()->ShutdownDropBox()->IsShutdown(nBoxId) == true)
        return;
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>>::iterator it = m_individualBoxes.find(nBoxId);
    if (it == m_individualBoxes.end())
        return;
    MS2Ptr<ItemDropIndividualBox> pBox = it->second;
    if (pBox == 0)
        return;
    for (MS2Ptr<ItemDropIndividualGroup> pGroup : pBox->m_groups)
    {
        if (pGroup->GetId() != nGroupId)
            continue;
        DropIndividualGroup(pGroup, ctx, out);
    }
}
MS2_REPLACE_METHOD(0x1402EC590, ItemDropTable, DropGroup, 447, 0xD2A98D71);

// @0x1402ec760
bool ItemDropTable::HasServerDrop(unsigned nBoxId)
{
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>>::iterator it = m_individualBoxes.find(nBoxId);
    if (it == m_individualBoxes.end())
        return false;
    MS2Ptr<ItemDropIndividualBox> pBox = it->second;
    if (pBox == 0)
        return false;
    for (MS2Ptr<ItemDropIndividualGroup> pGroup : pBox->m_groups)
    {
        if (pGroup->IsServerDrop())
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1402EC760, ItemDropTable, HasServerDrop, 377, 0xFD48BC43);

// @0x1402ec8e0
MS2Ptr<ItemDropIndividualBox> ItemDropTable::GetIndividualBox(unsigned nBoxId)
{
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>>::iterator it = m_individualBoxes.find(nBoxId);
    if (it == m_individualBoxes.end())
        return MS2Ptr<ItemDropIndividualBox>(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x1402EC8E0, ItemDropTable, GetIndividualBox, 178, 0xF0568D42);

// @0x1402ec9a0
bool ItemDropTable::LoadGlobalBoxes()
{
    m_globalBoxes.clear();
    CString strPath = FUN_14071a5b0("Table/Server", "globalDropItemBox_Final.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pElem : pRoot->FUN_140165cf0("dropBox"))
    {
        MS2Ptr<ItemDropGlobalBoxGroup> pGroup(new ItemDropGlobalBoxGroup);
        if (!pGroup->Load(pElem))
            continue;
        m_globalBoxes.insert(std::make_pair(pGroup->GetId(), pGroup));
    }
    return true;
}
MS2_REPLACE_METHOD(0x1402EC9A0, ItemDropTable, LoadGlobalBoxes, 823, 0xE9E65D75);

// @0x1402ecce0
bool ItemDropTable::LoadGlobalGroups()
{
    m_globalGroups.clear();
    CString strPath = FUN_14071a5b0("Table/Server", "globalDropItemSet_Final.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pElem : pRoot->FUN_140165cf0("dropBox"))
    {
        if (!FUN_14028f710(pElem))
            continue;
        MS2Ptr<ItemDropGlobalGroup> pGroup(new ItemDropGlobalGroup);
        if (!pGroup->Load(pElem))
            continue;
        if (!m_globalGroups.insert(std::make_pair(pGroup->GetId(), pGroup)).second)
            FUN_140177a80(FUN_140166440(), 1, 0x13, L"Duplicate GlobalDrop GroupID:{0}", pGroup->GetId());
    }
    return true;
}
MS2_REPLACE_METHOD(0x1402ECCE0, ItemDropTable, LoadGlobalGroups, 951, 0x365C7693);

// @0x1402ed0a0
bool ItemDropTable::LoadIndividualBoxes()
{
    m_individualBoxes.clear();
    CString strPath = FUN_14071a5b0("Table", "individualItemDrop_Final.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    std::vector<Unk_140165cf0*> elems;
    FUN_14028f5d0(pRoot, "dropBox", elems);
    CLockCriticalSection lock;
    // @0x140301bf0 (the lambda body)
    Concurrency::parallel_for_each(elems.begin(), elems.end(), [&lock, this](Unk_140165cf0* pElem) {
        MS2Ptr<ItemDropIndividualBox> pBox(new ItemDropIndividualBox);
        if (!pBox->Load(pElem))
            return;
        Unk_CriticalSectionLock guard(lock, 1);
        if (!m_individualBoxes.insert(std::make_pair(pBox->GetId(), pBox)).second)
            FUN_140177a80(FUN_140166440(), 1, 0x13, L"Duplicate IndividualDropID:{0}", pBox->GetId());
    });
    return true;
}
MS2_REPLACE_METHOD(0x1402ED0A0, ItemDropTable, LoadIndividualBoxes, 572, 0x6A3CD276);

// @0x1402ed2f0
void ItemDropTable::DropIndividualGroup(ItemDropIndividualGroup* pGroup, ItemDropContext& ctx, std::vector<ItemDropResult>& out)
{
    if (pGroup == 0)
        return;
    if (!pGroup->CheckLevel(ctx.m_level))
        return;
    ItemDropPicker<ItemDropDataIndividual*> picker;
    bool bSmartDrop = false;
    if (ctx.m_job != 0)
    {
        unsigned nSmartDropRate = pGroup->GetSmartDropRate();
        if (FUN_140768010(100, 0) < nSmartDropRate)
            bSmartDrop = true;
    }
    {
        std::vector<MS2Ptr<ItemDropDataIndividual>> items = pGroup->GetItems();
        for (std::vector<MS2Ptr<ItemDropDataIndividual>>::iterator it = items.begin(), itEnd = items.end(); it != itEnd; ++it)
        {
            ItemDropDataIndividual* pData = *it;
            if (!pData->Check(ctx.m_mapId, ctx.m_isAssist, ctx.m_pFilter))
                continue;
            MS2Ptr<CItemData> pItem = FUN_14053f870(pData->GetItemId());
            if (pItem == 0)
                continue;
            if (pGroup->IsApplySmartGenderDrop() && static_cast<Unk_DropItemData*>(pItem.operator->())->FUN_14053c940(ctx.m_gender) == 0)
                continue;
            if (pGroup->IsServerDrop() && !ctx.m_serverDrop)
                continue;
            if (bSmartDrop)
            {
                if (pItem->limit.FUN_140545da0(ctx.m_job))
                    picker.Register(pData->GetProperJobWeight(), pData);
                else
                    picker.Register(pData->GetImProperJobWeight(), pData);
            }
            else
            {
                picker.Register(pData->GetWeight(), pData);
            }
        }
    }
    if (!picker.Remains())
        return;
    unsigned nMaxLoop = 15;
    unsigned nDropCount = pGroup->PickDropCount();
    unsigned nLoop = (std::min)(nDropCount, nMaxLoop);
    while (nLoop > 0)
    {
        ItemDropDataIndividual* pData = 0;
        if (!picker.Pick(pData))
            break;
        if (pData == 0)
            break;
        unsigned nItemCount = pData->GetCount();
        MS2Ptr<CItemData> pItem = FUN_14053f870(pData->GetItemId());
        if (pItem == 0)
            break;
        int nRank = pItem->FUN_14053c5a0();
        if (nRank == 0)
            nRank = pData->GetDropRank(ctx.m_rankArg, ctx.m_userLevel, ctx.m_isAssist);
        const int& nSlotMax = pItem->property.slotMax;
        bool bAnnounce = pData->IsAnnounce();
        while (nItemCount > 0)
        {
            int nCount = nItemCount;
            int nStack = (std::min)(nCount, nSlotMax);
            if (nStack <= 0)
                nStack = nItemCount;
            ItemDropResult result(pData->GetItemId(), nStack, nRank, pData->GetEnchantLevel(), pData->GetWeight(),
                                  picker.GetTotal(), pGroup->GetId(), pGroup->IsApplySmartGenderDrop(), bAnnounce,
                                  pData->GetShowTooltip(), pData->IsTradableCountDeduction(), false,
                                  pData->IsRePackingLimitCountDeduction(), pData->IsDisableBreak());
            result.m_socketDataId = pData->GetSocketDataId();
            result.m_itemLife = pData->m_itemLife;
            if (pGroup->IsServerDrop())
                result.m_bAnnounce = result.m_bServerDrop = true;
            if (pItem->FUN_14053de60() == 1)
                result.m_isBindCharacter = pData->IsBindCharacter();
            out.push_back(result);
            nItemCount -= nStack;
            bAnnounce = false;
            if (pData->GetItemId2() != 0)
            {
                ItemDropResult result2(pData->GetItemId2(), nStack, nRank, pData->GetEnchantLevel(), 0, 0, 0, false,
                                       bAnnounce, pData->GetShowTooltip(), pData->IsTradableCountDeduction(), false,
                                       pData->IsRePackingLimitCountDeduction(), pData->IsDisableBreak());
                result2.m_socketDataId = pData->GetSocketDataId();
                result2.m_itemLife = pData->m_itemLife;
                if (pItem->FUN_14053de60() == 1)
                    result2.m_isBindCharacter = pData->IsBindCharacter();
                out.push_back(result2);
            }
        }
        nLoop--;
    }
}
MS2_REPLACE_METHOD(0x1402ED2F0, ItemDropTable, DropIndividualGroup, 2302, 0x6C178792);

// @0x1402edc00
void ItemDropTable::DropIndividual(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out)
{
    CheckInit();
    if (nBoxId == 0)
        return;
    if (TSingleton<CGameEventValueManager>::GetInstance()->ShutdownDropBox()->IsShutdown(nBoxId))
        return;
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>>::iterator it = m_individualBoxes.find(nBoxId);
    if (it == m_individualBoxes.end())
        return;
    MS2Ptr<ItemDropIndividualBox> pBox = it->second;
    if (pBox == 0)
        return;
    for (MS2Ptr<ItemDropIndividualGroup> pGroup : pBox->m_groups)
        DropIndividualGroup(pGroup, ctx, out);
}
MS2_REPLACE_METHOD(0x1402EDC00, ItemDropTable, DropIndividual, 404, 0x623CC8DF);

// @0x140302a40
void ItemDropTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(ItemDropTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140303520
void ItemDropTable::SetInit(bool b)
{
    s_bInit = b;
}
