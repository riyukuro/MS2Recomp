// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemMergeOptionDialog, the item merge option dialog.
// MS2-UNIT: client\ms2\uiitemmergeoptiondialog.cpp
// MS2-RANGE: 0x1419ccd00-0x1419d95c0 .text$mn
// MS2-RANGE: 0x1401158f0-0x140115a60 .text$di
// MS2-RANGE: 0x142cbeff0-0x142cbf080 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1401159b0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1401159e0 ; probe
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1419d3120 ; unique
// MS2-PIN: ??$?0AEBU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1419d31f0 ; unique
// MS2-PIN: ??$?0AEBW4Unk_StatType@@AEAW4Unk_SocketSpecialStat@@$0A@@?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@QEAA@AEBW4Unk_StatType@@AEAW4Unk_SocketSpecialStat@@@Z 0x1419d3240 ; prop
// MS2-PIN: ??$?0U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@$$V$0A@@?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@QEAA@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d3360 ; unique
// MS2-PIN: ??$?0U_Exact_args_t@std@@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@$$V$0A@@?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@QEAA@U_Exact_args_t@1@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d33f0 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@1@$$QEA_N@Z 0x1419d3450 ; unique
// MS2-PIN: ??$?0V?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@QEAA@AEAV?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1419d34a0 ; unique
// MS2-PIN: ??$?0AEAW4Unk_StatType@@AEBW4Unk_SocketSpecialStat@@$0A@@?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@QEAA@AEAW4Unk_StatType@@AEBW4Unk_SocketSpecialStat@@@Z 0x1419d34f0 ; prop
// MS2-PIN: ??$?0W4Unk_StatType@@W4Unk_SocketSpecialStat@@$0A@@?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@QEAA@$$QEAW4Unk_StatType@@$$QEAW4Unk_SocketSpecialStat@@@Z 0x1419d3540 ; prop
// MS2-PIN: ??$?4W4Unk_StatType@@W4Unk_SocketSpecialStat@@$0A@@?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@QEAAAEAU01@$$QEAU01@@Z 0x1419d3590 ; unique
// MS2-PIN: ??$?MW4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@YA_NAEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0@Z 0x1419d3650 ; unique
// MS2-PIN: ??$_Adl_verify_range1@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x1419d3710 ; unique
// MS2-PIN: ??$_Adl_verify_range@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@0@0@Z 0x1419d3720 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x1419d3780 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0AEAV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@0@U?$integral_constant@_N$00@0@@Z 0x1419d3850 ; unique
// MS2-PIN: ??$_Destroy_range@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0AEAV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@0@@Z 0x1419d3870 ; unique
// MS2-PIN: ??$_Emplace_back@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@?$_Uninitialized_backout_al@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAAX$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d38c0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEAAX$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d3920 ; unique
// MS2-PIN: ??$_Emplace_reallocate@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@QEAU21@$$QEAU21@@Z 0x1419d39e0 ; unique
// MS2-PIN: ??$_Get_unwrapped@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@YAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@QEAU10@@Z 0x1419d3cb0 ; prop
// MS2-PIN: ??$_Get_unwrapped@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@std@@$0A@@std@@YAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@AEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@0@@Z 0x1419d3cc0 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@PEAU12@@std@@YA_JAEBQEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0Urandom_access_iterator_tag@0@@Z 0x1419d3e40 ; unique
// MS2-PIN: ??$_Idl_distance@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@PEAU12@@std@@YA_JAEBQEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0@Z 0x1419d3e70 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@1@AEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@@Z 0x1419d4200 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@@Z 0x1419d4e40 ; unique
// MS2-PIN: ??$_Insertion_sort_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@PEAU10@QEAU10@VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d5250 ; unique
// MS2-PIN: ??$_Make_heap_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d5440 ; unique
// MS2-PIN: ??$_Move_backward_unchecked1@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@PEAU12@@std@@YAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@PEAU10@00U_General_ptr_iterator_tag@0@@Z 0x1419d5580 ; unique
// MS2-PIN: ??$_Move_backward_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@PEAU12@@std@@YAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@PEAU10@00@Z 0x1419d55f0 ; unique
// MS2-PIN: ??$_Pop_heap_hole_by_index@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@U12@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@_J1$$QEAU10@VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d5a10 ; unique
// MS2-PIN: ??$_Pop_heap_hole_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@U12@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@00$$QEAU10@VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d5b80 ; unique
// MS2-PIN: ??$_Pop_heap_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d5bf0 ; unique
// MS2-PIN: ??$_Ptr_move_cat@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@U12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0@Z 0x1419d5c70 ; unique
// MS2-PIN: ??$_Push_heap_by_index@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@U12@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@_J1$$QEAU10@VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d5ca0 ; unique
// MS2-PIN: ??$_Try_emplace@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@$$V@?$map@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d5fa0 ; unique
// MS2-PIN: ??$_Unfancy@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@YAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@PEAU10@@Z 0x1419d60f0 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@PEAU12@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@YAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@QEAU10@0PEAU10@AEAV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@0@@Z 0x1419d6100 ; unique
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@PEAU12@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@YAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@PEAU10@QEAU10@1AEAV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x1419d61d0 ; unique
// MS2-PIN: ??$addressof@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@YAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@AEAU10@@Z 0x1419d6280 ; prop
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@0@AEAV10@@Z 0x1419d62a0 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@AEBUpiecewise_construct_t@2@V?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@1@QEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x1419d6300 ; unique
// MS2-PIN: ??$construct@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@U12@@?$_Default_allocator_traits@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@$$QEAU31@@Z 0x1419d63b0 ; unique
// MS2-PIN: ??$emplace_back@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAAX$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d6420 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x1419d6490 ; unique
// MS2-PIN: ??$forward@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@YA$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@AEAU10@@Z 0x1419d6530 ; prop
// MS2-PIN: ??$forward@AEBU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@YAAEBU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@0@AEBU10@@Z 0x1419d6590 ; prop
// MS2-PIN: ??$forward@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@YA$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@AEAU10@@Z 0x1419d65a0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@0@AEAV10@@Z 0x1419d65b0 ; prop
// MS2-PIN: ??$forward@V?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@YA$$QEAV?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@0@AEAV10@@Z 0x1419d65c0 ; prop
// MS2-PIN: ??$forward_as_tuple@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@YA?AV?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@0@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@@Z 0x1419d65d0 ; unique
// MS2-PIN: ??$make_pair@AEBW4Unk_StatType@@AEAW4Unk_SocketSpecialStat@@@std@@YA?AU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@AEBW4Unk_StatType@@AEAW4Unk_SocketSpecialStat@@@Z 0x1419d66a0 ; unique
// MS2-PIN: ??$make_pair@AEAW4Unk_StatType@@AEBW4Unk_SocketSpecialStat@@@std@@YA?AU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@AEAW4Unk_StatType@@AEBW4Unk_SocketSpecialStat@@@Z 0x1419d66f0 ; unique
// MS2-PIN: ??$make_pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@YA?AU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@$$QEAW4Unk_StatType@@$$QEAW4Unk_SocketSpecialStat@@@Z 0x1419d6740 ; prop
// MS2-PIN: ??$move@AEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@YA$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@AEAU10@@Z 0x1419d6790 ; prop
// MS2-PIN: ??$move@AEAV?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@YA$$QEAV?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@0@AEAV10@@Z 0x1419d67a0 ; prop
// MS2-PIN: ??$sort@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@0@0VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d67b0 ; unique
// MS2-PIN: ??$try_emplace@$$V@?$map@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d6900 ; unique
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAA@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@AEAV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@@Z 0x1419d6bd0 ; unique
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEAA@XZ 0x1419d6c10 ; unique
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@std@@QEAA@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@PEBU_Container_base0@1@@Z 0x1419d6c40 ; unique
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@std@@QEAA@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@PEBU_Container_base0@1@@Z 0x1419d6c80 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@QEAA@XZ 0x1419d6cc0 ; unique
// MS2-PIN: ??0?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@QEAA@XZ 0x1419d6d10 ; prop
// MS2-PIN: ??0?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@QEAA@$$QEAV01@@Z 0x1419d6d50 ; unique
// MS2-PIN: ??0?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAA@XZ 0x1419d6d90 ; unique
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAA@XZ 0x1419d6e90 ; unique
// MS2-PIN: ??A?$map@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@@std@@QEAAAEAH$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d6fe0 ; unique
// MS2-PIN: ??A?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAAAEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@_K@Z 0x1419d7020 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1419d71c0 ; prop
// MS2-PIN: ??R?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@QEBA_NAEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@0@Z 0x1419d72d0 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEBA_K_K@Z 0x1419d7910 ; unique
// MS2-PIN: ?_Change_array@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEAAXQEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@_K1@Z 0x1419d79a0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEBA_NAEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@0@Z 0x1419d7ab0 ; unique
// MS2-PIN: ?_Destroy@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEAAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@0@Z 0x1419d7b20 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@2@XZ 0x1419d82c0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@2@XZ 0x1419d82e0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@XZ 0x1419d8300 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@XZ 0x1419d8310 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@XZ 0x1419d8340 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@XZ 0x1419d8350 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@2@XZ 0x1419d83b0 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEAAAEAV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@XZ 0x1419d8420 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEBAAEBV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@XZ 0x1419d8440 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@XZ 0x1419d8460 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@XZ 0x1419d8480 ; prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEBA_NXZ 0x1419d84a0 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@XZ 0x1419d8690 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@XZ 0x1419d86b0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@XZ 0x1419d86d0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@XZ 0x1419d8710 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@XZ 0x1419d8730 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEAAXXZ 0x1419d8750 ; unique
// MS2-PIN: ?_Orphan_range@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEBAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@0@Z 0x1419d8770 ; unique
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@XZ 0x1419d87c0 ; unique
// MS2-PIN: ?_Tidy@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEAAXXZ 0x1419d89b0 ; unique
// MS2-PIN: ?_Umove@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEAAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@PEAU32@00@Z 0x1419d8a80 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEAAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@00U?$integral_constant@_N$00@2@@Z 0x1419d8ac0 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@AEAAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@00@Z 0x1419d8b00 ; unique
// MS2-PIN: ?_Unwrapped@?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@XZ 0x1419d8b60 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@QEAAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@_K@Z 0x1419d8bc0 ; unique
// MS2-PIN: ?begin@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@2@XZ 0x1419d8c60 ; unique
// MS2-PIN: ?capacity@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEBA_KXZ 0x1419d8cc0 ; prop
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIItemMergeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419d8da0 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@QEAAXQEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@_K@Z 0x1419d8e60 ; unique
// MS2-PIN: ?end@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@@2@XZ 0x1419d8ef0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@2@AEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@@Z 0x1419d90f0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIItemMergeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x1419d91d0 ; unique
// MS2-PIN: ??$Call@VUIItemMergeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemMergeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIItemMergeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x1419d9210 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemMergeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1419d9250 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@std@@SA_KAEBV?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@Z 0x1419d9320 ; unique
// MS2-PIN: ?max_size@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEBA_KXZ 0x1419d9350 ; unique
// MS2-PIN: ?push_back@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAAX$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@@Z 0x1419d93c0 ; unique
// MS2-PIN: ?size@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEBA_KXZ 0x1419d9410 ; unique
// MS2-PIN: ?swap@?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@QEAAXAEAU12@@Z 0x1419d9450 ; unique
// MS2-PIN: ??__Fs_strSkill@@YAXXZ 0x142cbf020 ; probe
// MS2-PIN: ??__Fs_strStun@@YAXXZ 0x142cbf040 ; probe
// MS2-PINS-END tplpin
// MS2-PIN: ?FUN_1419d7750@@YAPEAVCItemMergeOptionProxy@@PEAX@Z 0x1419d7750
// MS2-PIN: ??$?0U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@?$_Tuple_val@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@QEAA@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d33c0
// MS2-PIN: ??$_Seek_wrapped@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@YAXAEAPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@QEAU10@@Z 0x1419d5d70
// MS2-PIN: ??$_Swap_adl@W4Unk_SocketSpecialStat@@@std@@YAXAEAW4Unk_SocketSpecialStat@@0@Z 0x1419d5f40
// MS2-PIN: ??$get@$0A@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@YA$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@$$QEAV?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@0@@Z 0x1419d6600
// MS2-PIN: ??$swap@W4Unk_SocketSpecialStat@@X@std@@YAXAEAW4Unk_SocketSpecialStat@@0@Z 0x1419d6830
// MS2-PIN: ??1?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@QEAA@XZ 0x1419d6ef0
// MS2-PIN: ?_Xlength@?$vector@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@CAXXZ 0x1419d8b70
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@XZ 0x1419d86f0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@@2@XZ 0x1419d83a0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemmergeoptiondialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astilelist.h"
#include "uiitemmergeoptiondialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/item.h"
#include "ms2/commonfiles/itemoption.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/equipitem.h"  // C3
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include <algorithm>
#include <vector>
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422cdfb0
#include "ms2/placeholder/clientconstants.h"
#include "ms2/client/ms2/equipment.h"
#include "ms2/client/ms2/uitalkcinematic.h"
#include "ms2/commonfiles/os.h"

template <> MS2Ptr<ASButton> UISwfEntity::GetChild<ASButton>(const CString& strName);   // 0x140bb4b10, owned by uiinventorydialog

// ---- unit-local views of exe objects ----

// The dialog's movie children: a clip with child lookups and a button with a text.
class Unk_MergeClip : public ASMovieClip { };
// The AS root of the dialog (m_30), the children of the clip and the helpers the dialog calls on them.
class Unk_MergeDialogAS : public AScript
{
public:
};
class ASDialog : public ASMovieClip
{
};

// The game feature switches (FUN_14025e7c0): GM keys and the debug flag.
class Unk_MergeFeature : public CInputKeyHandler
{
public:
};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The item event listener registry (FUN_140a6a840) and the UI manager (FUN_1403ed2b0).
class Unk_ItemEventSystem
{
public:
    void FUN_1419cae20(UIItemEventListener* pListener);     // register
    void FUN_1419caeb0(UIItemEventListener* pListener);     // unregister
};
class Unk_InventoryListener* FUN_140a6a840();   // C3: was FUN_140a6a840
class CUIService;
class UITalkCinematic* FUN_140a7b2b0(int);   // C3: was FUN_140a7b2b0
bool FUN_14028d470(float f, float fEps);                    // nearly zero

// The world (FUN_1403ed2d0) and its local player; the dialog tooltips are built against it.
class Unk_MergeSelf { public: int FUN_141654700(); };
class Unk_MergeWorld { public: Unk_MergeSelf* FUN_141bd0cc0(); };
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    static class WorldService* GetInstance();
};

// The npc talk state is TSingleton<UITalkManager>; the local player's record (FUN_1401d3200).
class Unk_MergePlayerCfg { public: char m_pad_00[0x69f8]; Common::Constants::Value<int> m_talk; };
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

// The inventory.
extern Unk_Inventory g_143ab2a90;
extern __int64 DAT_143ab2898;                               // the player's meso
extern int DAT_143ab2914;                                   // the player's level

// The item records: ItemData lookup by id, its rank and icon path.
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_14053feb0(int nItemId);
MS2Ptr<CItem> FUN_1419be700(unsigned __int64 nUid);         // an inventory or equipped item by uid

// The equipment of the local player (FUN_1416561a0 / FUN_1411e1ce0) and its slot list.
class PC   // C3: member view for the former free stand-ins
{
public:
    struct Unk_PCEquipSet* FUN_1416561a0();
};

// The bag registry of the item slot bags (FUN_14123a080 / FUN_14123a190).
void FUN_14123a080(const CString& strName, const ATL::CAtlArray<unsigned __int64>& items);
void FUN_14123a190(const CString& strName);
template <class T> int Unk_BreakFind(const ATL::CAtlArray<T>& values, const T& value);   // the index of an uid in a bag

// Texts, notices, message boxes and number formats.
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_140298ea0(CStringW strKey);
template <class T1> CStringW FUN_14028dfa0(CStringW strKey, const T1& a1);
template <class T1, class T2> CStringW FUN_14028dfa0(CStringW strKey, const T1& a1, const T2& a2);
CStringW FUN_1409404f0(__int64 nMeso);                      // a meso amount as text
CStringW FUN_141811980(int nTable, int nId);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_1412751b0(const CStringW& text, int n);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_140710590(COutPacket& packet);                     // send
__int64 FUN_141b71960(const char* sz);             // the uid in a text
CStringW FUN_141b71910(__int64 nUid);                       // the uid as text
CString FUN_140719530(unsigned __int64 nUid);                        // the uid as narrow text
int _stricmp(const char*, const char*);

// The option text builders and the stat tables (stat id -> name / value text).
bool IsStatKindOne(int nStat);                              // the stat is an integer
bool FUN_14081dc50(int nSpecial);                           // the special ability is an integer
bool IsStatKindTwo(int nStat);                              // the stat value is a rate
bool FUN_14081dcd0(int nSpecial);                           // the special ability value is a rate
int FUN_14081d9e0(int nSpecial);                            // the special ability is a skill level up tier
CStringW GetStatCommonText(unsigned nStat);                          // the stat name
CStringW FUN_140630e10(int nSpecial);                       // the special ability name
CStringW FUN_1409e0900(int n);                              // an integer as text
CStringW FUN_1409e0a90(float f);                            // a rate as text
CStringW FUN_1409e0970(int nStat, int nValue);              // a stat value as an integer text
CStringW FUN_1409e0bf0(int nStat, int nValue);              // a stat value as a rate text
CStringW FUN_140631600(int nStat, BaseOption* pOption);     // the option line of a stat
CStringW FUN_140631830(int nSpecial, int nValue, CItemData* pData);   // the option line of a special ability
struct SpecialAbilityInfo;
extern std::vector<SpecialAbilityInfo> DAT_143ab1a40;  //                                     // the special ability table (0x20 byte rows, DAT_143ab1a40)
struct Unk_SATypeInfo
{
    void* m_00;
    int m_nValueType;                                       // +0x08
    int m_0c;
    CStringW m_strFormat;                                   // +0x10
    CStringW m_strName;                                     // +0x18
};

// The MS2Ptr<CItem> / MS2Ptr<CItemData> helper calls of the exe (copy, test, get) are the inline members of MS2Ptr.


// The proxy handle: allocate and reset (the definitions are at the end of the unit).
CPtred* FUN_1401ba820(CPtred* p);                           // sets the count to 1
static CItemMergeOptionProxy* FUN_1419d36b0(void* pUnused);
static CItemMergeOptionProxy* FUN_1419d7750(void* pUnused);
static MS2Ptr<CItemMergeOptionProxy>& FUN_1419d7530(MS2Ptr<CItemMergeOptionProxy>& sp, const MS2SvrNewTag& tag);
void* FUN_1405c5c30(Unk_MergeSpecialMap* pMap, const int& key, unsigned& nHash, unsigned& nBin, void*& pPrev);
void* FUN_1405c5d20(Unk_MergeNormalMap* pMap, const int& key, unsigned& nHash, unsigned& nBin, void*& pPrev);

// @0x1419d2890
MS2Ptr<CItem> UIItemMergeOptionDialog::FindMergeItem(unsigned __int64 nUid)
{
    return FUN_1419be700(nUid);
}

// @0x1419d2db0
void UIItemMergeOptionDialog::SetPhase(int nPhase)
{
    m_nPhase = nPhase;
}

// @0x1419d2dd0
int UIItemMergeOptionDialog::GetPhase()
{
    return m_nPhase;
}

// @0x1419ccd00
UIItemMergeOptionDialog::UIItemMergeOptionDialog()
    : m_nItemUid(0), m_nMaterialUid(0), m_nPhase(0), m_bSpecial(false)
{
    m_2c = 0x1b;
    FUN_1419d7530(m_spProxy, MS2SvrNewTag(0));
    m_optionOrder[std::make_pair((Unk_StatType)4, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)7, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)10, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)0, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)1, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)2, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)3, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)14, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)27, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)29, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)23, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)24, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)31, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)26)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)27)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)15, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)17, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)18, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)24)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)25)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)19)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)18)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)23)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)22)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)20)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)21)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)12)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)7)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)16)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)13, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)35)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)54)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)20, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)25, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)26, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)16, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)19, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)37)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)38)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)29)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)28)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)33)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)32)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)30)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)31)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)34)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)36)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)5, (Unk_SocketSpecialStat)0)] = (int)m_optionOrder.size();
    m_optionOrder[std::make_pair((Unk_StatType)-1, (Unk_SocketSpecialStat)55)] = (int)m_optionOrder.size();
}

// @0x1419ce3d0
UIItemMergeOptionDialog::~UIItemMergeOptionDialog()
{
}

// @0x1419ce4a0
CString UIItemMergeOptionDialog::GetTypeName()
{
    return "ItemMergeOptionDialog";
}

// @0x1419ce4f0
void UIItemMergeOptionDialog::vfunc_2(void* pSlot)
{
    MS2Ptr<CItem> spItem = FindMergeItem(m_nItemUid);
    if (spItem.get() != 0)
        ApplyMergeItem(spItem);
}

// @0x1419ce590
void UIItemMergeOptionDialog::vfunc_3(void* pSlot, bool b)
{
}

// @0x1419ce5b0
void UIItemMergeOptionDialog::vfunc_4(void* pSlot, int n)
{
    MS2Ptr<CItem> spItem = FindMergeItem(m_nItemUid);
    if (spItem.get() != 0)
        ApplyMergeItem(spItem);
}

// @0x1419ce650
void UIItemMergeOptionDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ((class Unk_ItemEventSystem*)FUN_140a6a840())->FUN_1419cae20(this);
    SetPhase(0);
    ResetMergeItems();
    ShowMergePrice(MS2Ptr<CItem>(0));
    if (m_30.get() != 0)
        static_cast<ASObj*>(m_30.operator->())->FUN_1407cbbe0("m_useDebug", ((class Unk_MergeFeature*)FUN_14025e7c0())->IsDebugMode());
    TSingleton<CUIService>::GetInstance()->FUN_141adc190();
    RequestInfo();
}

// @0x1419ce750
void UIItemMergeOptionDialog::vfunc_67()
{
    FUN_14123a190(GetTypeName() + "_MergeSlotBag");
    FUN_14123a190(GetTypeName() + "_MaterialSlotBag");
    UIDialog::vfunc_67();
    m_nItemUid = 0;
    m_nMaterialUid = 0;
    m_bSpecial = false;
    SetPhase(0);
    ((class Unk_ItemEventSystem*)FUN_140a6a840())->FUN_1419caeb0(this);
}

// @0x1419ce8f0
int UIItemMergeOptionDialog::vfunc_13()
{
    if (m_30 == 0)
        return 0;
    if (((class Unk_MergeFeature*)FUN_14025e7c0())->FUN_14116dd30(0x493e2, 0, 0) || ((class Unk_MergeFeature*)FUN_14025e7c0())->FUN_14116d840())
    {
        if (GetPhase() == 4 || GetPhase() == 5)
            return 1;
    }
    return 0;
}

// @0x1419ce980
void UIItemMergeOptionDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
}

// @0x1419ce9a0
void UIItemMergeOptionDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
    if (_stricmp("isMergeable", strMethod) == 0)
    {
        Scaleform::GFx::Value value(true);
        *pRetVal = value;
    }
    else if (_stricmp("getTooltipByGUID", strMethod) == 0)
    {
        unsigned __int64 nUid = FUN_141b71960(pArgs->FUN_1422b8d30());
        ASTooltip tooltip(((Unk_MergeSelf*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()), 0x20, 2);
        if (tooltip.FUN_1409e0d40(FindMergeItem(nUid).get()))
            *pRetVal = tooltip.FUN_1422bb870();
    }
    else if (_stricmp("getTooltipByID", strMethod) == 0)
    {
        int nId = pArgs->PopUInt();
        int nRank = pArgs->PopUInt();
        ASTooltip tooltip(((Unk_MergeSelf*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()), 0x20, 2);
        if (tooltip.FUN_1409e1770(nId, nRank))
            *pRetVal = tooltip.FUN_1422bb870();
    }
}

// @0x1419cec20
void UIItemMergeOptionDialog::vfunc_43()
{
    if (ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30))
    {
        if (UITalkCinematic* pNpc = FUN_140a7b2b0(0x4e40))
        {
            int nY = pNpc->GetLowerCutGlobalY() + 12;
            int nX = pNpc->GetIllustGlobalX() - 80;
            if (nY != -1 && nX != -1)
            {
                pDialog->vfunc_2(5, nX, nY - pDialog->GetHeightCeil());
                double dX = 0;
                double dY = 0.0;
                if (pDialog->FUN_1422c2510(&dX, &dY) && dY < 0.0)
                {
                    float fHeight = (float)pDialog->GetHeightCeil() / 100.0f;
                    if (FUN_14028d470(fHeight, 0))
                        return;
                    float fScale = (float)(dY / fHeight + pDialog->GetXScale());
                    int nOffset = (int)((float)pDialog->GetHeightCeil() * fScale / 100.0f);
                    pDialog->SetScaleFloat(fScale, fScale);
                    pDialog->vfunc_2(5, nX, nY - nOffset);
                }
            }
            return;
        }
    }
    if (ASDialog* pFallback = dynamic_cast<ASDialog*>((AScript*)m_30))
        pFallback->vfunc_2(1, 0, 0);
}

// @0x1419ceea0
int UIItemMergeOptionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onMergeItemSelect") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            if (GetPhase() == 0)
                return 1;
            m_nItemUid = FUN_141b71960(data.FUN_1422b8d30());
            MS2Ptr<CItem> spItem = FindMergeItem(m_nItemUid);
            if (spItem.get() != 0)
                m_bSpecial = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->FUN_140630810();
            SetPhase(2);
            RequestSelection();
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onMaterialItemSelect") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            m_nMaterialUid = FUN_141b71960(data.FUN_1422b8d30());
            SetPhase(3);
            RequestPreview();
        }
    }
    if (_stricmp(szMethod, "onMerge") == 0)
    {
        int nError = CheckMerge();
        if (nError != 0)
        {
            FUN_1419d1d20(nError);
            return 1;
        }
        MS2Ptr<CItem> spItem = FindMergeItem(m_nItemUid);
        if (reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->FUN_140630810())
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommonByKey(L"s_item_merge_option_warn"), 1);
            spBox->FUN_141a024a0(0);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemMergeOptionDialog::ConfirmMerge));
            FUN_140d73c60(spBox);
            SetPhase(4);
        }
        else
        {
            RequestMerge();
            SetPhase(5);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onShowResult") == 0)
    {
        RequestResultTalk();
        return 1;
    }
    else if (_stricmp(szMethod, "onResetDialog") == 0)
    {
        ResetMergeItems();
        ShowMergePrice(MS2Ptr<CItem>(0));
        SetPhase(1);
        return 1;
    }
    else if (_stricmp(szMethod, "onDebug") == 0)
    {
        if (DAT_143ab2914 >= 50)
            RequestMaterial();
        return 1;
    }
    else if (_stricmp(szMethod, "onMergeSelectOption") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
            RequestChoice(data.PopBool());
        return 1;
    }
    return 0;
}

// @0x1419cf520
void UIItemMergeOptionDialog::vfunc_15()
{
}

// The qsort order of the mergeable items: the items of the bag after the equipped ones, special ones first, by rank.
static int FUN_1419d2fa0(const void* pLeft, const void* pRight);

// @0x1419cf530
void UIItemMergeOptionDialog::ResetMergeItems()
{
    ATL::CAtlArray<void*> guids;
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    g_143ab2a90.FUN_140a60880(0, items);
    for (size_t i = 0; i < items.GetCount(); ++i)
    {
        MS2Ptr<CItem> spItem(items[i]);
        if (reinterpret_cast<CItemData*>(spItem->FUN_140527840())->fusion.fusionable != 0)
            guids.Add(reinterpret_cast<void*>(spItem->GetItemUid()));
    }
    Unk_MergeSelf* pSelf = ((Unk_MergeSelf*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pSelf != 0)
    {
        ATL::CAtlList<MS2Ptr<CEquipItem> > equipment(10);
        ((class CEquipment*)((class PC*)(class Unk_MergeSelf*)(pSelf))->FUN_1416561a0())->CollectShownItemsInLayer(equipment, 0);
        for (POSITION pos = equipment.GetHeadPosition(); pos != 0; equipment.GetNext(pos))
        {
            MS2Ptr<CEquipItem> spEquip(equipment.GetAt(pos));
            if (!spEquip)
                continue;
            MS2Ptr<CItem> spItem = spEquip->GetItem();
            if (!spItem)
                continue;
            if (spItem->FUN_140527840() == 0)
                continue;
            if (reinterpret_cast<CItemData*>(spItem->FUN_140527840())->fusion.fusionable != 0)
                guids.Add(reinterpret_cast<void*>(spItem->GetItemUid()));
        }
    }
    qsort(guids.GetData(), guids.GetCount(), 8, FUN_1419d2fa0);
    CString strBag = GetTypeName() + "_MergeSlotBag";
    FUN_14123a190(strBag);
    FUN_14123a080(strBag, reinterpret_cast<const ATL::CAtlArray<unsigned __int64>&>(guids));
    if (MS2Ptr<ASMovieClip> spClip = GetChild<ASMovieClip>("m_itemBag"))
    {
        if (MS2Ptr<ASTileList> spBag = spClip->FUN_140accef0<ASTileList>("bag"))
            spBag->FUN_1407cba60("bagId", CString(strBag));
    }
}


// @0x1419cfa10
void UIItemMergeOptionDialog::RefreshSelectedIngredient()
{
    MS2Ptr<CItem> spMaterial = g_143ab2a90.FUN_140a5d680(m_nMaterialUid);
    MS2Ptr<CItem> spItem = FindMergeItem(m_nItemUid);
    if ((((MS2Ptr<CItem>*)(void*)(&spMaterial))->get() ? true : false) && (((MS2Ptr<CItem>*)(void*)(&spItem))->get() ? true : false))
    {
        MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(((CItem*)spItem)->FUN_140527840()));
        if (!spData)
            return;
        MS2Ptr<CItemData> spMaterialData(reinterpret_cast<CItemData*>(((CItem*)spMaterial)->FUN_140527840()));
        if (!spMaterialData)
            return;
        ASObj obj(2);
        obj.FUN_1407cba60("iconPath", spMaterialData->GetIconPath());
        obj.FUN_1409adc90("itemGrade", spMaterial->GetRarity());
        obj.FUN_1407cb9c0("index", Unk_BreakFind(reinterpret_cast<const ATL::CAtlArray<unsigned __int64>&>(m_items190), m_nMaterialUid));
        obj.FUN_1407cbb20("itemGUID", FUN_141b71910(spMaterial->GetItemUid()));
        m_30->Invoke("setIngredient", obj);
    }
}

// @0x1419cfd10
void UIItemMergeOptionDialog::ApplyMergeItem(MS2Ptr<CItem> spItem)
{
    int nReady = 1;
    ASObj list(2);
    for (size_t i = 0; i < m_spProxy->m_ingredients.FUN_14026bee0(); ++i)
    {
        Unk_IngRef ref = m_spProxy->m_ingredients.FUN_14026bdc0(i);
        MS2Ptr<CItemData> spData = FUN_14053f870(ref->FUN_14026b500());
        if (!spData)
            continue;
        unsigned nHave = 0;
        if (ref->m_b != 0)
            nHave = g_143ab2a90.FUN_140a5f780(ref->m_b, 0);
        else
            nHave = g_143ab2a90.FUN_140a5f180(ref->FUN_14026b500(), 0);
        CStringW strKey(L"s_item_merge_option_material_count_enable");
        if (nHave < (unsigned)ref->m_c)
        {
            nReady = 0;
            strKey = L"s_item_merge_option_material_count_disable";
        }
        ASObj entry(2);
        entry.FUN_1407cba60("iconPath", spData->GetIconPath());
        entry.FUN_1409adc90("itemGrade", FUN_14053feb0(ref->FUN_14026b500()));
        entry.FUN_1407cbb20("itemCount", FUN_14028dfa0(strKey, nHave, reinterpret_cast<const unsigned&>(ref->m_c)));
        entry.FUN_1409c0d20("itemID", ref->FUN_14026b500());
        list.FUN_1409eb270(StringFormat("ingredient{0}", i + 1), entry);
    }
    list.FUN_1407cb9c0("ready", nReady);
    if (m_30.get() != 0)
        m_30->Invoke("setStaticIngredient", list);
}

// @0x1419d0140
void UIItemMergeOptionDialog::ShowOptionPreview(MS2Ptr<CItem> spItem)
{
    std::vector<std::pair<Unk_StatType, Unk_SocketSpecialStat> > options;
    for (POSITION pos = m_spProxy->m_normal.GetStartPosition(); pos != 0; m_spProxy->m_normal.GetNext(pos))
    {
        Unk_SocketSpecialStat nZero = (Unk_SocketSpecialStat)0;
        options.push_back(std::make_pair(reinterpret_cast<const Unk_StatType&>(m_spProxy->m_normal.GetKeyAt(pos)), nZero));
    }
    for (POSITION pos = m_spProxy->m_special.GetStartPosition(); pos != 0; m_spProxy->m_special.GetNext(pos))
    {
        Unk_StatType nNone = (Unk_StatType)-1;
        options.push_back(std::make_pair(nNone, reinterpret_cast<const Unk_SocketSpecialStat&>(m_spProxy->m_special.GetKeyAt(pos))));
    }
    std::sort(options.begin(), options.end(), OptionLess(&m_optionOrder));
    CStringW strResult;
    ASObj obj(2);
    for (size_t i = 0; i < options.size(); ++i)
    {
        int nNormal = options[i].first;
        int nSpecial = options[i].second;
        if (nNormal != -1)
        {
            if (void* pNode = static_cast<Unk_MergeNormalMap&>(m_spProxy->m_normal).Lookup(nNormal))
            {
                CItemMergeOptionVariation* pRange = reinterpret_cast<CItemMergeOptionVariation*>(reinterpret_cast<char*>(pNode) + 8);
                CStringW strText;
                if (IsStatKindOne(nNormal))
                {
                    CStringW strMin = FUN_1409e0900(pRange->FUN_1405beac0());
                    CStringW strMax = FUN_1409e0900(pRange->FUN_1405beae0());
                    strText = StringFormat(L"{0} {1}~{2}", GetStatCommonText(nNormal), strMin, strMax);
                }
                else
                {
                    CStringW strMin = FUN_1409e0a90(pRange->FUN_1405beb00());
                    CStringW strMax = FUN_1409e0a90(pRange->FUN_1405beb20());
                    strText = StringFormat(L"{0} {1}~{2}", GetStatCommonText(nNormal), strMin, strMax);
                }
                if (strText.GetLength() != 0)
                {
                    if (strResult.GetLength() != 0)
                        strResult += L"\n";
                    strResult += FUN_14028dfa0(CStringW(L"s_item_merge_option_current"), strText);
                }
            }
        }
        else
        {
            if (nSpecial != 0)
            {
                if (void* pNode = static_cast<Unk_MergeSpecialMap&>(m_spProxy->m_special).Lookup(nSpecial))
                {
                    CItemMergeOptionVariation* pRange = reinterpret_cast<CItemMergeOptionVariation*>(reinterpret_cast<char*>(pNode) + 8);
                    CStringW strText;
                    if (FUN_14081dc50(nSpecial))
                    {
                        CStringW strMin = FUN_1409e0900(pRange->FUN_1405beac0());
                        CStringW strMax = FUN_1409e0900(pRange->FUN_1405beae0());
                        strText = StringFormat(L"{0} {1}~{2}", FUN_140630e10(nSpecial), strMin, strMax);
                    }
                    else
                    {
                        CStringW strMin = FUN_1409e0a90(pRange->FUN_1405beb00());
                        CStringW strMax = FUN_1409e0a90(pRange->FUN_1405beb20());
                        strText = StringFormat(L"{0} {1}~{2}", FUN_140630e10(nSpecial), strMin, strMax);
                    }
                    if (strText.GetLength() != 0)
                    {
                        if (strResult.GetLength() != 0)
                            strResult += L"\n";
                        strResult += FUN_14028dfa0(CStringW(L"s_item_merge_option_current"), strText);
                    }
                }
            }
        }
    }
    obj.FUN_1407cbb20("title", FUN_140298ea0(CStringW(L"s_item_merge_option_grade_current")));
    obj.FUN_1407cbb20("options", CStringW(strResult));
    if (m_30.get() != 0)
        m_30->Invoke("setOptionPreview", obj);
}

// @0x1419d0ba0
void UIItemMergeOptionDialog::RefreshMaterialBag()
{
    CString strBag = GetTypeName() + "_MaterialSlotBag";
    FUN_14123a190(strBag);
    FUN_14123a080(strBag, reinterpret_cast<const ATL::CAtlArray<unsigned __int64>&>(m_items190));
    if (MS2Ptr<ASMovieClip> spClip = GetChild<ASMovieClip>("m_ingredientBag"))
    {
        if (MS2Ptr<ASTileList> spBag = spClip->FUN_140accef0<ASTileList>("bag"))
            spBag->FUN_1407cba60("bagId", CString(strBag));
    }
}

// @0x1419d0d90
void UIItemMergeOptionDialog::ShowMergePrice(MS2Ptr<CItem> spItem)
{
    if (MS2Ptr<ASButton> spButton = GetChild<ASButton>("m_merge"))
        spButton->FUN_1422cdfb0(FUN_14028dfa0(CStringW(L"s_item_merge_option_consume_meso"), FUN_1409404f0(m_spProxy->m_nMeso)));
}

// @0x1419d0ef0
void UIItemMergeOptionDialog::FUN_1419d0ef0(CInPacket& packet)
{
    int nMode = packet.ReadUInt8();
    if (nMode == 0)
    {
        SetPhase(1);
    }
    else
    {
        unsigned __int64 nId = (unsigned)packet.ReadInt32();
        if (nMode == 2)
        {
            ShowMissingItem((int)nId);
            SetPhase(1);
        }
        else
        {
            unsigned __int64 nUid = packet.ReadInt64();
            int nNormal = packet.ReadInt32();
            int nSpecial = packet.ReadInt32();
            int nValue = packet.ReadInt32();
            MS2Ptr<CItem> spItem = FindMergeItem(nUid);
            if (spItem == (CItem*)0)
            {
                ShowMissingItem((int)nId);
                SetPhase(1);
                return;
            }
            m_nItemUid = nUid;
            m_bSpecial = true;
            m_30->Invoke("setPrevMergeOption", FUN_140719530(m_nItemUid));
            FUN_1419d1490(nNormal, nSpecial, nValue);
        }
    }
}

// @0x1419d11b0
void UIItemMergeOptionDialog::FUN_1419d11b0(CInPacket& packet)
{
    m_items190.RemoveAll();
    unsigned nCount = packet.ReadInt32();
    for (unsigned i = 0; i < nCount; ++i)
        m_items190.Add(reinterpret_cast<void*>(packet.ReadInt64()));
    RefreshMaterialBag();
    if (m_30.get() != 0)
        static_cast<Unk_MergeDialogAS*>(m_30.operator->())->FUN_140fdd6b0("setSelectItem", m_nItemUid, m_bSpecial);
}

// @0x1419d12f0
void UIItemMergeOptionDialog::FUN_1419d12f0(CInPacket& packet)
{
    MS2Ptr<CItemMergeOptionProxy> spProxy(new CItemMergeOptionProxy);
    spProxy->FUN_1405bef60(packet);
    m_spProxy = spProxy;
    MS2Ptr<CItem> spItem = FindMergeItem(m_nItemUid);
    if (spItem.get() != 0)
    {
        RefreshSelectedIngredient();
        ApplyMergeItem(spItem);
        ShowOptionPreview(spItem);
        ShowMergePrice(spItem);
    }
}

// @0x1419d1490
void UIItemMergeOptionDialog::FUN_1419d1490(int nNormal, int nSpecial, int nValue)
{
    MS2Ptr<CItem> spItem = FindMergeItem(m_nItemUid);
    if (spItem == (CItem*)0)
        return;
    CStringW strOld = GetCurrentOption(spItem);
    CStringW strNew(L"");
    if (nNormal != -1)
    {
        if (IsStatKindTwo(nNormal))
            strNew = FUN_1409e0bf0(nNormal, nValue);
        else
            strNew = FUN_1409e0970(nNormal, nValue);
    }
    else if (nSpecial != 0)
    {
        if (FUN_14081d9e0(nSpecial) != 0)
        {
            strNew = FUN_140630e10(nSpecial);
        }
        else if (FUN_14081d9e0(nSpecial) != 0)
        {
            strNew = FUN_140630e10(nSpecial);
        }
        else if (FUN_14081dcd0(nSpecial))
        {
            float fValue = nValue / 10.0f;
            strNew = StringFormat(reinterpret_cast<std::vector<Unk_SATypeInfo>&>(DAT_143ab1a40)[nSpecial].m_strFormat, fValue);
        }
        else
        {
            strNew = StringFormat(reinterpret_cast<std::vector<Unk_SATypeInfo>&>(DAT_143ab1a40)[nSpecial].m_strFormat, nValue);
        }
    }
    if (m_30.get() != 0)
    {
        ASObj obj(2);
        obj.FUN_1407cbb20("oldOption", FUN_14028dfa0(CStringW(L"s_item_merge_option_old_option"), strOld));
        obj.FUN_1407cbb20("newOption", FUN_14028dfa0(CStringW(L"s_item_merge_option_new_option"), strNew));
        obj.FUN_1407cba60("iconPath", reinterpret_cast<CItemData*>(spItem->FUN_140527840())->GetIconPath());
        obj.FUN_1409adc90("itemGrade", spItem->GetRarity());
        obj.FUN_1407cbb20("itemName", spItem->FUN_140528160());
        m_30->Invoke("selectOption", obj);
        m_30->Invoke("onMerge");
    }
    SetPhase(4);
}

// @0x1419d1ad0
void UIItemMergeOptionDialog::FUN_1419d1ad0(MS2Ptr<CItem> spItem)
{
    ASObj obj(2);
    obj.FUN_1407cba60("iconPath", reinterpret_cast<CItemData*>(spItem->FUN_140527840())->GetIconPath());
    obj.FUN_1409adc90("itemGrade", spItem->GetRarity());
    obj.FUN_1407cbb20("itemName", spItem->FUN_140528160());
    obj.FUN_1407cbb20("option", GetCurrentOption(spItem));
    if (m_30.get() != 0)
    {
        m_30->Invoke("setResult", obj);
        if (!m_bSpecial)
            m_30->Invoke("onMerge");
    }
    m_nTalkId = 0;
    SetPhase(6);
}

// @0x1419d1d20
void UIItemMergeOptionDialog::FUN_1419d1d20(int nError)
{
    switch (nError)
    {
    case 3:
        FUN_1412751f0(GetStringCommonByKey(L"s_item_merge_option_error_invalid_mergeitem"), 1, 1);
        break;
    case 4:
        FUN_1412751f0(GetStringCommonByKey(L"s_item_merge_option_error_invalid_material"), 1, 1);
        break;
    case 1:
        FUN_1412751f0(GetStringCommonByKey(L"s_item_merge_option_error_lack_material"), 1, 1);
        break;
    case 9:
        FUN_1412751f0(GetStringCommonByKey(L"s_item_merge_option_error_unknown"), 1, 1);
        break;
    case 5:
        FUN_1412751f0(GetStringCommonByKey(L"s_item_merge_option_error_invalid_merge_scroll"), 1, 1);
        break;
    case 6:
        FUN_1412751f0(GetStringCommonByKey(L"s_item_merge_option_error_invalid_revert_rank"), 1, 1);
        break;
    case 7:
        FUN_1412751f0(GetStringCommonByKey(L"s_item_merge_option_error_invalid_revert_option"), 1, 1);
        break;
    case 2:
        FUN_1412751f0(GetStringCommonByKey(L"s_item_merge_option_error_lack_meso"), 1, 1);
        break;
    }
}

// @0x1419d2140
bool UIItemMergeOptionDialog::ConfirmMerge(int nButton, const CMsgBoxData& box)
{
    if (nButton != 0)
        return true;
    RequestMerge();
    return true;
}

// @0x1419d2180
void UIItemMergeOptionDialog::RequestInfo()
{
    COutPacket packet(static_cast<int>(SendOp::ItemMerge), 0);
    packet.WriteUInt8(0);
    FUN_140710590(packet);
}

// @0x1419d21e0
void UIItemMergeOptionDialog::RequestPreview()
{
    COutPacket packet(static_cast<int>(SendOp::ItemMerge), 0);
    packet.WriteUInt8(2);
    packet.WriteInt64(m_nItemUid);
    packet.WriteInt64(m_nMaterialUid);
    FUN_140710590(packet);
}

// @0x1419d2260
void UIItemMergeOptionDialog::RequestSelection()
{
    COutPacket packet(static_cast<int>(SendOp::ItemMerge), 0);
    packet.WriteUInt8(1);
    packet.WriteInt64(m_nItemUid);
    FUN_140710590(packet);
}

// @0x1419d22d0
void UIItemMergeOptionDialog::RequestMerge()
{
    COutPacket packet(static_cast<int>(SendOp::ItemMerge), 0);
    packet.WriteUInt8(3);
    packet.WriteInt64(m_nItemUid);
    packet.WriteInt64(m_nMaterialUid);
    FUN_140710590(packet);
}

// @0x1419d2350
void UIItemMergeOptionDialog::RequestChoice(unsigned char nChoice)
{
    COutPacket packet(static_cast<int>(SendOp::ItemMerge), 0);
    packet.WriteUInt8(4);
    packet.WriteUInt8(nChoice);
    FUN_140710590(packet);
}

// @0x1419d23c0
void UIItemMergeOptionDialog::RequestMaterial()
{
    COutPacket packet(static_cast<int>(SendOp::ItemMerge), 0);
    packet.WriteUInt8(7);
    packet.WriteInt64(m_nItemUid);
    packet.WriteInt64(m_nMaterialUid);
    FUN_140710590(packet);
}

// @0x1419d2440
void UIItemMergeOptionDialog::RequestResultTalk()
{
    COutPacket packet(static_cast<int>(SendOp::NpcTalk), 0);
    if (TSingleton<UITalkManager>::GetInstance()->FUN_141b213c0() != 0)
    {
        int nTalkId = TSingleton<UITalkManager>::GetInstance()->FUN_141b212f0();
        packet.WriteUInt8(6);
        packet.WriteInt32(nTalkId);
        packet.WriteInt32(*((class Unk_MergePlayerCfg*)FUN_1401d3200())->m_talk.Get());
        packet.WriteInt16(0xca);
        packet.WriteInt16((short)m_nTalkId);
    }
    else
    {
        packet.WriteUInt8(4);
        packet.WriteInt16(0xca);
        packet.WriteInt16((short)m_nTalkId);
    }
    FUN_140710590(packet);
}

// @0x1419d2540
int UIItemMergeOptionDialog::CheckMerge()
{
    MS2Ptr<CItem> spItem = FindMergeItem(m_nItemUid);
    MS2Ptr<CItem> spMaterial = g_143ab2a90.FUN_140a5d680(m_nMaterialUid);
    if (!spItem)
        return 3;
    if (!spMaterial)
        return 4;
    if (DAT_143ab2898 < m_spProxy->m_nMeso)
        return 2;
    for (size_t i = 0; i < m_spProxy->m_ingredients.FUN_14026bee0(); ++i)
    {
        Unk_IngRef ref = m_spProxy->m_ingredients.FUN_14026bdc0(i);
        if (ref->m_b != 0)
        {
            if (g_143ab2a90.FUN_140a5f780(ref->m_b, 0) < ref->m_c)
                return 1;
        }
        else
        {
            if (g_143ab2a90.FUN_140a5f180(ref->FUN_14026b500(), 0) < ref->m_c)
                return 1;
        }
    }
    return 0;
}

// @0x1419d27e0
int UIItemMergeOptionDialog::FUN_1419d27e0(ItemInfoSlot& slot)
{
    if (m_30.get() != 0)
        return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(m_30->GetMember("m_merging")))->GetBool() ? 0 : 1;
    return 0;
}

// @0x1419d28e0
CStringW UIItemMergeOptionDialog::GetCurrentOption(MS2Ptr<CItem> spItem)
{
    if (spItem.get() != 0)
    {
        if (!reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->FUN_140630810())
        {
            MS2_ASSERT_AT(0x3fb, FALSE);
            return CStringW(L"");
        }
        int nType = 4;
        Unk_EnchantMap& stats = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->m_spOption->GetStatMap(nType);
        Unk_SocketSpecialMap& specials = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->m_spOption->GetSpecialMap(nType);
        for (POSITION pos = stats.GetStartPosition(); pos != 0; stats.GetNext(pos))
        {
            int nStat = stats.GetKeyAt(pos);
            Unk_EnchantPtr<BaseOption> spOption(stats.GetValueAt(pos));
            if (!spOption)
                continue;
            if (!spOption->HasValue())
                continue;
            return FUN_140631600(nStat, spOption.get());
        }
        for (POSITION pos = specials.GetStartPosition(); pos != 0; specials.GetNext(pos))
        {
            int nSpecial = specials.GetKeyAt(pos);
            Unk_EnchantPtr<BaseOption> spOption(specials.GetValueAt(pos));
            if (!spOption)
                continue;
            if (!spOption->HasValue())
                continue;
            if (FUN_14081d9e0(nSpecial) != 0)
                return FUN_140630e10(nSpecial);
            else
                return FUN_140631830(nSpecial, spOption->GetValue(), 0);
        }
    }
    return CStringW(L"");
}

// @0x1419d2ca0
void UIItemMergeOptionDialog::ShowMissingItem(int nItemId)
{
    CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId);
    CStringW strText = FUN_14028dfa0(CStringW(L"s_item_merge_option_error_prev_option_item_not_exist"), strName);
    FUN_140d73aa0(CStringW(strText), 0, 0, CStringW(L""));
    FUN_1412751b0(strText, 0x14);
}

// Is the item still in the bag (an equipped one is not)?
// @0x1419d2df0
static int FUN_1419d2df0(MS2Ptr<CItem> spItem)
{
    if (!spItem)
        return 0;
    return g_143ab2a90.FUN_140a5d680(spItem->GetItemUid()).get() != 0;
}

// The sort rank: equipped items (bit 4), merged items (bit 3), then the item rank.
// @0x1419d2eb0
static int FUN_1419d2eb0(MS2Ptr<CItem> spItem)
{
    unsigned nEquipped = FUN_1419d2df0(spItem) == 0;
    unsigned nMerged = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->FUN_140630810();
    unsigned nRank = spItem->GetRarity();
    unsigned nResult = 0;
    nResult |= nEquipped << 4;
    nResult |= nMerged << 3;
    nResult |= nRank;
    return nResult;
}

// @0x1419d2fa0
static int FUN_1419d2fa0(const void* pLeft, const void* pRight)
{
    const unsigned __int64* pLeftUid = (const unsigned __int64*)pLeft;
    const unsigned __int64* pRightUid = (const unsigned __int64*)pRight;
    MS2Ptr<CItem> spLeft = FUN_1419be700(*pLeftUid);
    MS2Ptr<CItem> spRight = FUN_1419be700(*pRightUid);
    return FUN_1419d2eb0(spLeft) > FUN_1419d2eb0(spRight) ? -1 : 1;
}

// @0x1419d36b0
static CItemMergeOptionProxy* FUN_1419d36b0(void* pUnused)
{
    return new CItemMergeOptionProxy();
}

// The sort functor of the option preview.
// @0x1419d7300
bool UIItemMergeOptionDialog::OptionLess::operator()(const std::pair<Unk_StatType, Unk_SocketSpecialStat>& left, const std::pair<Unk_StatType, Unk_SocketSpecialStat>& right)
{
    int nLeft = 0x7fffffff;
    int nRight = 0x7fffffff;
    std::map<std::pair<Unk_StatType, Unk_SocketSpecialStat>, int>::iterator itLeft = m_pOrder->find(left);
    if (itLeft != m_pOrder->end())
        nLeft = itLeft->second;
    std::map<std::pair<Unk_StatType, Unk_SocketSpecialStat>, int>::iterator itRight = m_pOrder->find(right);
    if (itRight != m_pOrder->end())
        nRight = itRight->second;
    if (nLeft == 0x7fffffff && nRight == 0x7fffffff)
        return GetName(left) < GetName(right);
    return nLeft < nRight;
}

// @0x1419d7620
void* Unk_MergeSpecialMap::Lookup(const int& key)
{
    unsigned nBin;
    unsigned nHash;
    void* pAssoc;
    void* pPrev;
    pAssoc = FUN_1405c5c30(this, key, nHash, nBin, pPrev);
    return pAssoc;
}

// @0x1419d7660
void* Unk_MergeNormalMap::Lookup(const int& key)
{
    unsigned nBin;
    unsigned nHash;
    void* pAssoc;
    void* pPrev;
    pAssoc = FUN_1405c5d20(this, key, nHash, nBin, pPrev);
    return pAssoc;
}

// @0x1419d7720
struct Unk_TePtrAccess
{
    static void ResetNew(MS2Ptr<CItemMergeOptionProxy>& sp)
    {
        sp.Release();
        sp.m_p = FUN_1419d7750(0);
    }
};

// @0x1419d7530
static MS2Ptr<CItemMergeOptionProxy>& FUN_1419d7530(MS2Ptr<CItemMergeOptionProxy>& sp, const MS2SvrNewTag& tag)
{
    Unk_TePtrAccess::ResetNew(sp);
    return sp;
}

// @0x1419d7570
CStringW UIItemMergeOptionDialog::OptionLess::GetName(const std::pair<Unk_StatType, Unk_SocketSpecialStat>& option)
{
    if (option.first != -1)
        return GetStatCommonText(option.first);
    if (option.second != 0)
        return FUN_140630e10(option.second);
    return CStringW(L"");
}

static CItemMergeOptionProxy* FUN_1419d7750(void* pUnused)
{
    return static_cast<CItemMergeOptionProxy*>(FUN_1401ba820(FUN_1419d36b0(0)));
}

// MS2-PIN: ??$?0$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@$$Z$$V@?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@V?$tuple@$$V@1@@Z 0x1419d30a0 ; sfk: enum pair retype of ??$?0$$QEAU?$pair@HH@std@@$$Z$$V@?$pair@$$CBU?$pair@HH@std@@H@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAU?$pair@HH@std@@@1@V?$tuple@$$V@1@@Z
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1419d30f0 ; sfk: enum pair retype of ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@1@$$QEA_N@Z 0x1419d31a0 ; sfk: enum pair retype of ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@1@$$QEA_N@Z
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@@Z 0x1419d3760 ; sfk: enum pair retype of ??$_Buy_if_not_node@AEAU?$pair@$$CBU?$pair@HH@std@@H@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBU?$pair@HH@std@@H@1@@Z
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@1@PEAU01@@Z 0x1419d3c20 ; sfk: enum pair retype of ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@1@PEAU01@@Z
// MS2-PIN: ??$_Guess_median_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@00VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d3cf0 ; sfk: enum pair retype of ??$_Guess_median_unchecked@PEAU?$pair@HH@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@HH@0@00VOptionLess@UIItemMergeOptionDialog@@@Z
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@AEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@1@Z 0x1419d3ea0 ; sfk: enum pair retype of ??$_Insert_at@AEAU?$pair@$$CBU?$pair@HH@std@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@1@AEAU?$pair@$$CBU?$pair@HH@std@@H@1@1@Z
// MS2-PIN: ??$_Kfn@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@SAAEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@AEBU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@@Z 0x1419d5390 ; sfk: enum pair retype of ??$_Kfn@$$CBU?$pair@HH@std@@H@?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@SAAEBU?$pair@HH@1@AEBU?$pair@$$CBU?$pair@HH@std@@H@1@@Z
// MS2-PIN: ??$_Lbound@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@AEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@1@@Z 0x1419d53a0 ; sfk: enum pair retype of ??$_Lbound@U?$pair@HH@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@1@AEBU?$pair@HH@1@@Z
// MS2-PIN: ??$_Med3_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@00VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d54e0 ; sfk: enum pair retype of ??$_Med3_unchecked@PEAU?$pair@HH@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@HH@0@00VOptionLess@UIItemMergeOptionDialog@@@Z
// MS2-PIN: ??$_Partition_by_median_guess_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YA?AU?$pair@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@PEAU12@@0@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d5640 ; sfk: enum pair retype of ??$_Partition_by_median_guess_unchecked@PEAU?$pair@HH@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YA?AU?$pair@PEAU?$pair@HH@std@@PEAU12@@0@PEAU?$pair@HH@0@0VOptionLess@UIItemMergeOptionDialog@@@Z
// MS2-PIN: ??$_Sort_heap_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0VOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d5d90 ; sfk: enum pair retype of ??$_Sort_heap_unchecked@PEAU?$pair@HH@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@HH@0@0VOptionLess@UIItemMergeOptionDialog@@@Z
// MS2-PIN: ??$_Sort_unchecked@PEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@0@0_JVOptionLess@UIItemMergeOptionDialog@@@Z 0x1419d5df0 ; sfk: enum pair retype of ??$_Sort_unchecked@PEAU?$pair@HH@std@@VOptionLess@UIItemMergeOptionDialog@@@std@@YAXPEAU?$pair@HH@0@0_JVOptionLess@UIItemMergeOptionDialog@@@Z
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@0@AEAPEAU10@@Z 0x1419d6260 ; sfk: enum pair retype of ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@0@AEAPEAU10@@Z
// MS2-PIN: ??$addressof@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@YAPEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@0@AEAU10@@Z 0x1419d6270 ; sfk: enum pair retype of ??$addressof@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@YAPEAU?$pair@$$CBU?$pair@HH@std@@H@0@AEAU10@@Z
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@0@AEAV10@@Z 0x1419d6290 ; sfk: enum pair retype of ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@0@AEAV10@@Z
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@AEAPEAU31@@Z 0x1419d62b0 ; sfk: enum pair retype of ??$construct@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@1@AEAPEAU31@@Z
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@@Z 0x1419d6400 ; sfk: enum pair retype of ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@1@@Z
// MS2-PIN: ??$destroy@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@1@QEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@@Z 0x1419d6410 ; sfk: enum pair retype of ??$destroy@U?$pair@$$CBU?$pair@HH@std@@H@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@1@QEAU?$pair@$$CBU?$pair@HH@std@@H@1@@Z
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@0@AEAPEAU10@@Z 0x1419d6540 ; sfk: enum pair retype of ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@0@AEAPEAU10@@Z
// MS2-PIN: ??$forward@AEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@YAAEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@0@AEAU10@@Z 0x1419d6560 ; sfk: enum pair retype of ??$forward@AEAU?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@YAAEAU?$pair@$$CBU?$pair@HH@std@@H@0@AEAU10@@Z
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@0@AEAV10@@Z 0x1419d6570 ; sfk: enum pair retype of ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@0@AEAV10@@Z
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@@Z 0x1419d6a30 ; sfk: enum pair retype of ??0?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@U?$pair@HH@std@@@1@@Z
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@1@@Z 0x1419d6a60 ; sfk: enum pair retype of ??0?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@U?$pair@HH@std@@@1@@Z
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@1@@Z 0x1419d6aa0 ; sfk: enum pair retype of ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@1@@Z
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEAA@XZ 0x1419d6ae0 ; sfk: enum pair retype of ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEAA@XZ
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@1@@Z 0x1419d6b00 ; sfk: enum pair retype of ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@1@@Z
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@1@@Z 0x1419d6b40 ; sfk: enum pair retype of ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@1@@Z
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x1419d6b80 ; sfk: enum pair retype of ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@QEAA@XZ 0x1419d6ba0 ; sfk: enum pair retype of ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@QEAA@XZ
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@QEAA@XZ 0x1419d6d00 ; sfk: enum pair retype of ??0?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@QEAA@XZ
// MS2-PIN: ??0?$map@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@@std@@QEAA@XZ 0x1419d6d20 ; sfk: enum pair retype of ??0?$map@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@@std@@QEAA@XZ
// MS2-PIN: ??0OptionLess@UIItemMergeOptionDialog@@QEAA@PEAV?$map@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@@std@@@Z 0x1419d6dc0 ; sfk: enum pair retype of ??0OptionLess@UIItemMergeOptionDialog@@QEAA@PEAV?$map@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@@std@@@Z
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1419d6e30 ; sfk: enum pair retype of ??1?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAA@XZ
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1419d6e60 ; sfk: enum pair retype of ??1?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAA@XZ
// MS2-PIN: ??1?$map@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@@std@@QEAA@XZ 0x1419d6ed0 ; sfk: enum pair retype of ??1?$map@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@@std@@QEAA@XZ
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1419d6f60 ; sfk: enum pair retype of ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1419d6fa0 ; sfk: enum pair retype of ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@XZ 0x1419d7060 ; sfk: enum pair retype of ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBU?$pair@HH@std@@H@1@XZ
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@XZ 0x1419d7080 ; sfk: enum pair retype of ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBU?$pair@HH@std@@H@1@XZ
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@1@XZ 0x1419d70a0 ; sfk: enum pair retype of ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBU?$pair@HH@std@@H@1@XZ
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1419d70c0 ; sfk: enum pair retype of ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEAA?AV01@H@Z
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1419d7110 ; sfk: enum pair retype of ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1419d7130 ; sfk: enum pair retype of ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1419d71e0 ; sfk: enum pair retype of ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1419d7200 ; sfk: enum pair retype of ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ
// MS2-PIN: ??ROptionLess@UIItemMergeOptionDialog@@QEAA_NAEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@0@Z 0x1419d7300 ; sfk: enum pair retype of ??ROptionLess@UIItemMergeOptionDialog@@QEAA_NAEBU?$pair@HH@std@@0@Z
// MS2-PIN: ?GetName@OptionLess@UIItemMergeOptionDialog@@QEAA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@Z 0x1419d7570 ; sfk: enum pair retype of ?GetName@OptionLess@UIItemMergeOptionDialog@@QEAA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEBU?$pair@HH@std@@@Z
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@XZ 0x1419d7770 ; sfk: enum pair retype of ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@XZ
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@XZ 0x1419d7830 ; sfk: enum pair retype of ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@XZ
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1419d7af0 ; sfk: enum pair retype of ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAAXXZ
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@Z 0x1419d7b60 ; sfk: enum pair retype of ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@@Z
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@Z 0x1419d7bb0 ; sfk: enum pair retype of ?_Erase@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@@Z
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@2@@Z 0x1419d7c50 ; sfk: enum pair retype of ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@2@@Z
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@Z 0x1419d8200 ; sfk: enum pair retype of ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@@Z
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@Z 0x1419d8230 ; sfk: enum pair retype of ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@@Z
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@XZ 0x1419d8260 ; sfk: enum pair retype of ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@XZ
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@XZ 0x1419d8290 ; sfk: enum pair retype of ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@XZ
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@2@XZ 0x1419d8320 ; sfk: enum pair retype of ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@2@XZ
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@2@XZ 0x1419d8330 ; sfk: enum pair retype of ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@2@XZ
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@2@XZ 0x1419d8360 ; sfk: enum pair retype of ?_Get_second@?$_Compressed_pair@U?$less@U?$pair@HH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@$00@2@XZ
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@2@XZ 0x1419d8370 ; sfk: enum pair retype of ?_Get_second@?$_Compressed_pair@U?$less@U?$pair@HH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@$00@2@XZ
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@XZ 0x1419d8380 ; sfk: enum pair retype of ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@XZ
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@2@XZ 0x1419d8390 ; sfk: enum pair retype of ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@2@XZ
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@2@XZ 0x1419d83c0 ; sfk: enum pair retype of ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@2@XZ
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@2@XZ 0x1419d83f0 ; sfk: enum pair retype of ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@2@XZ
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@Z 0x1419d84f0 ; sfk: enum pair retype of ?_Key@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@HH@2@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@@Z
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@AEBU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@2@@Z 0x1419d8520 ; sfk: enum pair retype of ?_Kfn@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@HH@2@AEBU?$pair@$$CBU?$pair@HH@std@@H@2@@Z
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@XZ 0x1419d8540 ; sfk: enum pair retype of ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@XZ
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@Z 0x1419d8550 ; sfk: enum pair retype of ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@@Z
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@PEAU32@@Z 0x1419d8630 ; sfk: enum pair retype of ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@PEAU32@@Z
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@PEAU32@@Z 0x1419d8660 ; sfk: enum pair retype of ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@PEAU32@@Z
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@XZ 0x1419d8830 ; sfk: enum pair retype of ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@XZ
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@XZ 0x1419d8850 ; sfk: enum pair retype of ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@XZ
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@@Z 0x1419d8870 ; sfk: enum pair retype of ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@@Z
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x1419d8950 ; sfk: enum pair retype of ?_Tidy@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@IEAAXXZ
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@_K@Z 0x1419d8b90 ; sfk: enum pair retype of ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@_K@Z
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@2@XZ 0x1419d8bf0 ; sfk: enum pair retype of ?begin@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@2@XZ
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1419d8d00 ; sfk: enum pair retype of ?clear@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAAXXZ
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@_K@Z 0x1419d8e00 ; sfk: enum pair retype of ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@_K@Z
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@2@_K@Z 0x1419d8e30 ; sfk: enum pair retype of ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@2@_K@Z
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@2@XZ 0x1419d8e90 ; sfk: enum pair retype of ?end@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@2@XZ
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@2@0@Z 0x1419d8f50 ; sfk: enum pair retype of ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@2@0@Z
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@2@@Z 0x1419d9040 ; sfk: enum pair retype of ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@2@@Z
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@@std@@@2@AEBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@2@@Z 0x1419d92b0 ; sfk: enum pair retype of ?lower_bound@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@@std@@@2@AEBU?$pair@HH@2@@Z
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@PEAX@std@@@2@@Z 0x1419d9310 ; sfk: enum pair retype of ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@H@std@@PEAX@std@@@2@@Z
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1419d9330 ; sfk: enum pair retype of ?max_size@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEBA_KXZ
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@std@@SAPEAU?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@2@AEAU32@@Z 0x1419d93a0 ; sfk: enum pair retype of ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBU?$pair@HH@std@@H@std@@@std@@SAPEAU?$pair@$$CBU?$pair@HH@std@@H@2@AEAU32@@Z
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@HU?$less@U?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_StatType@@W4Unk_SocketSpecialStat@@@std@@H@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1419d93f0 ; sfk: enum pair retype of ?size@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@HU?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@H@std@@@2@$0A@@std@@@std@@QEBA_KXZ
// MS2-PIN: ??$swap@W4Unk_StatType@@X@std@@YAXAEAW4Unk_StatType@@0@Z 0x1419d68b0 ; sfk: the stat-type half of the option pair swap
// MS2-PIN: ??$_Swap_adl@W4Unk_StatType@@@std@@YAXAEAW4Unk_StatType@@0@Z 0x1419d5f70 ; sfk: the stat-type half of the option pair swap
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIItemMergeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x1419d74b0 ; the CAtlList CNode of the equipment list is a byte-identical look-alike
