// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CLogDialog, the log viewer tool dialog, and
// ClientLogManager, the CLogString listener that feeds it. See logdialog.h and placeholder/clientlogmanager.h.
// MS2-UNIT: ?\logdialog.cpp
// MS2-RANGE: 0x14144fec0-0x14145bd70 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: memcpy_s 0x14145bb00
// MS2-PIN: memmove_s 0x14145bc50
// MS2-PIN: ??$format_arg@DW4Unk_LogCategory@@@fmt@@YAXAEAV?$BasicFormatter@D@0@AEAPEBDAEBW4Unk_LogCategory@@@Z 0x141455d60
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1414520c0 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141452150 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@1@$$QEA_N@Z 0x141452180 ; prop
// MS2-PIN: ??$?0AEBU?$less@W4Unk_LogLevel@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@W4Unk_LogLevel@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@W4Unk_LogLevel@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1414521d0 ; unique
// MS2-PIN: ??$?0AEBW4Unk_LogLevel@@$$Z$$V@?$pair@$$CBW4Unk_LogLevel@@_N@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBW4Unk_LogLevel@@@1@V?$tuple@$$V@1@@Z 0x141452220 ; unique
// MS2-PIN: ??$?0AEBW4Unk_LogLevel@@$0A@@?$tuple@AEBW4Unk_LogLevel@@@std@@QEAA@AEBW4Unk_LogLevel@@@Z 0x141452270 ; unique
// MS2-PIN: ??$?0AEBW4Unk_LogLevel@@@?$_Tuple_val@AEBW4Unk_LogLevel@@@std@@QEAA@AEBW4Unk_LogLevel@@@Z 0x1414522c0 ; prop
// MS2-PIN: ??$?0U_Exact_args_t@std@@AEBW4Unk_LogLevel@@$$V$0A@@?$tuple@AEBW4Unk_LogLevel@@@std@@QEAA@U_Exact_args_t@1@AEBW4Unk_LogLevel@@@Z 0x1414523c0 ; prop
// MS2-PIN: ??$?0U_Exact_args_t@std@@W4Unk_LogLevel@@$$V$0A@@?$tuple@$$QEAW4Unk_LogLevel@@@std@@QEAA@U_Exact_args_t@1@$$QEAW4Unk_LogLevel@@@Z 0x141452420 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@1@$$QEA_N@Z 0x1414524a0 ; prop
// MS2-PIN: ??$?0V?$tuple@$$QEAW4Unk_LogLevel@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBW4Unk_LogLevel@@_N@std@@QEAA@AEAV?$tuple@$$QEAW4Unk_LogLevel@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1414524f0 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBW4Unk_LogLevel@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBW4Unk_LogLevel@@_N@std@@QEAA@AEAV?$tuple@AEBW4Unk_LogLevel@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x141452540 ; prop
// MS2-PIN: ??$?0W4Unk_LogLevel@@$$V$0A@@?$tuple@$$QEAW4Unk_LogLevel@@@std@@QEAA@$$QEAW4Unk_LogLevel@@@Z 0x141452590 ; unique
// MS2-PIN: ??$?0W4Unk_LogLevel@@@?$_Tuple_val@$$QEAW4Unk_LogLevel@@@std@@QEAA@$$QEAW4Unk_LogLevel@@@Z 0x1414525f0 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBW4Unk_LogLevel@@_N@std@@@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBW4Unk_LogLevel@@_N@1@@Z 0x141452790 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAW4Unk_LogLevel@@@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAW4Unk_LogLevel@@@1@$$QEAV?$tuple@$$V@1@@Z 0x1414527b0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBW4Unk_LogLevel@@@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBW4Unk_LogLevel@@@1@$$QEAV?$tuple@$$V@1@@Z 0x141452880 ; prop
// MS2-PIN: ??$_Copy_memmove@PEAHPEAH@std@@YAPEAHPEAH00@Z 0x141452a50 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$allocator@H@std@@@std@@YAXPEAH0AEAV?$allocator@H@0@U?$integral_constant@_N$00@0@@Z 0x141452c30 ; unique
// MS2-PIN: ??$_Destroy_range@V?$allocator@H@std@@@std@@YAXPEAH0AEAV?$allocator@H@0@@Z 0x141452cf0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@H@?$vector@HV?$allocator@H@std@@@std@@AEAAX$$QEAH@Z 0x141452ec0 ; unique
// MS2-PIN: ??$_Emplace_reallocate@H@?$vector@HV?$allocator@H@std@@@std@@QEAAPEAHQEAH$$QEAH@Z 0x1414531d0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@1@PEAU01@@Z 0x141453480 ; unique
// MS2-PIN: ??$_Get_unwrapped@H@std@@YAPEAHQEAH@Z 0x141453560 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAHPEAH@std@@YA_JAEBQEAH0Urandom_access_iterator_tag@0@@Z 0x141453610 ; unique
// MS2-PIN: ??$_Idl_distance@PEAHPEAH@std@@YA_JAEBQEAH0@Z 0x1414536d0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@AEAU?$pair@$$CBW4Unk_LogLevel@@_N@1@1@Z 0x1414537c0 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@1@AEAU?$pair@$$CBW4Unk_LogLevel@@_N@1@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@@Z 0x141453b20 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBW4Unk_LogLevel@@_N@1@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@@Z 0x141454760 ; unique
// MS2-PIN: ??$_Kfn@$$CBW4Unk_LogLevel@@_N@?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@SAAEBW4Unk_LogLevel@@AEBU?$pair@$$CBW4Unk_LogLevel@@_N@1@@Z 0x141454b70 ; prop
// MS2-PIN: ??$_Lbound@W4Unk_LogLevel@@@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@AEBW4Unk_LogLevel@@@Z 0x141454b80 ; unique
// MS2-PIN: ??$_Ptr_move_cat@HH@std@@YA?AU_Really_trivial_ptr_iterator_tag@0@AEBQEAH0@Z 0x141454cd0 ; unique
// MS2-PIN: ??$_Try_emplace@W4Unk_LogLevel@@$$V@?$map@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@_N@1@$$QEAW4Unk_LogLevel@@@Z 0x141454ec0 ; prop
// MS2-PIN: ??$_Unfancy@H@std@@YAPEAHPEAH@Z 0x141455020 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAHPEAHV?$allocator@H@std@@@std@@YAPEAHQEAH0PEAHAEAV?$allocator@H@0@@Z 0x141455350 ; unique
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@HHV?$allocator@H@std@@@std@@YAPEAHQEAH00AEAV?$allocator@H@0@U_Really_trivial_ptr_iterator_tag@0@U?$integral_constant@_N$00@0@@Z 0x141455490 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@0@AEAPEAU10@@Z 0x1414555d0 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@YAPEAU?$pair@$$CBW4Unk_LogLevel@@_N@0@AEAU10@@Z 0x1414555f0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@0@AEAV10@@Z 0x141455630 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@AEAPEAU31@@Z 0x1414556e0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@AEBUpiecewise_construct_t@2@V?$tuple@$$QEAW4Unk_LogLevel@@@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@1@QEAU?$pair@$$CBW4Unk_LogLevel@@_N@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAW4Unk_LogLevel@@@1@$$QEAV?$tuple@$$V@1@@Z 0x141455730 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBW4Unk_LogLevel@@@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@1@QEAU?$pair@$$CBW4Unk_LogLevel@@_N@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBW4Unk_LogLevel@@@1@$$QEAV?$tuple@$$V@1@@Z 0x1414557e0 ; prop
// MS2-PIN: ??$construct@HH@?$_Default_allocator_traits@V?$allocator@H@std@@@std@@SAXAEAV?$allocator@H@1@QEAH$$QEAH@Z 0x1414559d0 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@@Z 0x141455ad0 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@1@QEAU?$pair@$$CBW4Unk_LogLevel@@_N@1@@Z 0x141455af0 ; prop
// MS2-PIN: ??$emplace_back@H@?$vector@HV?$allocator@H@std@@@std@@QEAAX$$QEAH@Z 0x141455bb0 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAW4Unk_LogLevel@@@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAW4Unk_LogLevel@@@1@$$QEAV?$tuple@$$V@1@@Z 0x141455c20 ; prop
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBW4Unk_LogLevel@@@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBW4Unk_LogLevel@@@1@$$QEAV?$tuple@$$V@1@@Z 0x141455cc0 ; prop
// MS2-PIN: ??$forward@$$QEAW4Unk_LogLevel@@@std@@YA$$QEAW4Unk_LogLevel@@AEAW41@@Z 0x141455eb0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@0@AEAPEAU10@@Z 0x141455ed0 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@YAAEAU?$pair@$$CBW4Unk_LogLevel@@_N@0@AEAU10@@Z 0x141455ee0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@0@AEAV10@@Z 0x141455f00 ; prop
// MS2-PIN: ??$forward@AEBU?$less@W4Unk_LogLevel@@@std@@@std@@YAAEBU?$less@W4Unk_LogLevel@@@0@AEBU10@@Z 0x141455f30 ; prop
// MS2-PIN: ??$forward@AEBW4Unk_LogLevel@@@std@@YAAEBW4Unk_LogLevel@@AEBW41@@Z 0x141455f50 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@0@AEAV10@@Z 0x141455f70 ; prop
// MS2-PIN: ??$forward@V?$tuple@$$QEAW4Unk_LogLevel@@@std@@@std@@YA$$QEAV?$tuple@$$QEAW4Unk_LogLevel@@@0@AEAV10@@Z 0x141455f80 ; prop
// MS2-PIN: ??$forward@V?$tuple@AEBW4Unk_LogLevel@@@std@@@std@@YA$$QEAV?$tuple@AEBW4Unk_LogLevel@@@0@AEAV10@@Z 0x141455f90 ; prop
// MS2-PIN: ??$forward@H@std@@YA$$QEAHAEAH@Z 0x141455fb0 ; prop
// MS2-PIN: ??$forward_as_tuple@AEBW4Unk_LogLevel@@@std@@YA?AV?$tuple@AEBW4Unk_LogLevel@@@0@AEBW4Unk_LogLevel@@@Z 0x141455fc0 ; prop
// MS2-PIN: ??$forward_as_tuple@W4Unk_LogLevel@@@std@@YA?AV?$tuple@$$QEAW4Unk_LogLevel@@@0@$$QEAW4Unk_LogLevel@@@Z 0x141455ff0 ; prop
// MS2-PIN: ??$get@$0A@$$QEAW4Unk_LogLevel@@@std@@YA$$QEAW4Unk_LogLevel@@$$QEAV?$tuple@$$QEAW4Unk_LogLevel@@@0@@Z 0x141456020 ; prop
// MS2-PIN: ??$get@$0A@AEBW4Unk_LogLevel@@@std@@YAAEBW4Unk_LogLevel@@$$QEAV?$tuple@AEBW4Unk_LogLevel@@@0@@Z 0x141456040 ; prop
// MS2-PIN: ??$move@AEAV?$tuple@$$QEAW4Unk_LogLevel@@@std@@@std@@YA$$QEAV?$tuple@$$QEAW4Unk_LogLevel@@@0@AEAV10@@Z 0x1414560c0 ; prop
// MS2-PIN: ??$move@AEAV?$tuple@AEBW4Unk_LogLevel@@@std@@@std@@YA$$QEAV?$tuple@AEBW4Unk_LogLevel@@@0@AEAV10@@Z 0x1414560d0 ; prop
// MS2-PIN: ??$move@AEAH@std@@YA$$QEAHAEAH@Z 0x1414560e0 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@_N@1@$$QEAW4Unk_LogLevel@@@Z 0x141456100 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVClientLogManager@@P81@EAAXPEAVCLogStringCtx@@@Z@std@@@?$Delegate@$$A6AXPEAVCLogStringCtx@@@Z@@QEAA@AEBV01@@Z 0x141456180 ; unique
// MS2-PIN: ??0?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VLogDialogCtx@@@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VLogDialogCtx@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VLogDialogCtx@@@@@std@@@1@@Z 0x141456560 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@W4Unk_LogLevel@@@1@@Z 0x141456690 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@W4Unk_LogLevel@@@1@@Z 0x1414566c0 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@1@@Z 0x141456700 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEAA@XZ 0x141456740 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@1@@Z 0x141456760 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@1@@Z 0x1414567a0 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAA@XZ 0x1414568a0 ; unique
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEAA@PEAHPEBU_Container_base0@1@@Z 0x1414568d0 ; prop
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEAA@PEAHPEBU_Container_base0@1@@Z 0x141456910 ; prop
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@H@std@@@std@@QEAA@XZ 0x141456990 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@QEAA@XZ 0x1414569e0 ; prop
// MS2-PIN: ??0?$allocator@H@std@@QEAA@XZ 0x141456a00 ; prop
// MS2-PIN: ??0?$map@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@@std@@QEAA@XZ 0x141456a80 ; unique
// MS2-PIN: ??0?$tuple@$$QEAW4Unk_LogLevel@@@std@@QEAA@$$QEAV01@@Z 0x141456ab0 ; prop
// MS2-PIN: ??0?$tuple@AEBW4Unk_LogLevel@@@std@@QEAA@$$QEAV01@@Z 0x141456af0 ; prop
// MS2-PIN: ??0?$vector@HV?$allocator@H@std@@@std@@QEAA@XZ 0x141456b60 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x141456e30 ; unique
// MS2-PIN: ??1?$map@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@@std@@QEAA@XZ 0x141456f00 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141457200 ; unique
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141457240 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141457350 ; prop
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141457390 ; unique
// MS2-PIN: ??A?$map@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@@std@@QEAAAEA_N$$QEAW4Unk_LogLevel@@@Z 0x1414573d0 ; unique
// MS2-PIN: ??A?$vector@HV?$allocator@H@std@@@std@@QEAAAEAH_K@Z 0x141457480 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBW4Unk_LogLevel@@_N@1@XZ 0x1414574e0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBW4Unk_LogLevel@@_N@1@XZ 0x1414575e0 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBW4Unk_LogLevel@@_N@1@XZ 0x141457600 ; prop
// MS2-PIN: ??D?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBAAEBHXZ 0x141457620 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141457730 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141457780 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1414577a0 ; unique
// MS2-PIN: ??E?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x141457830 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1414578b0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1414578d0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1414578f0 ; unique
// MS2-PIN: ??R?$less@W4Unk_LogLevel@@@std@@QEBA_NAEBW4Unk_LogLevel@@0@Z 0x1414579c0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@XZ 0x141458140 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@XZ 0x1414582c0 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@HV?$allocator@H@std@@@std@@AEBA_K_K@Z 0x141458430 ; unique
// MS2-PIN: ?_Change_array@?$vector@HV?$allocator@H@std@@@std@@AEAAXQEAH_K1@Z 0x1414585d0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEBA_NAEBW4Unk_LogLevel@@0@Z 0x1414586e0 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x141458740 ; unique
// MS2-PIN: ?_Destroy@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH0@Z 0x1414587b0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@Z 0x1414587f0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@Z 0x141458840 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@2@@Z 0x1414588e0 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@Z 0x141458f30 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@Z 0x141458f60 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@XZ 0x141459060 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@XZ 0x141459090 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x141459120 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@W4Unk_LogLevel@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@W4Unk_LogLevel@@@2@XZ 0x141459140 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@W4Unk_LogLevel@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@W4Unk_LogLevel@@@2@XZ 0x141459150 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@2@XZ 0x141459180 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@2@XZ 0x141459190 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAAAEAV?$allocator@H@2@XZ 0x1414591e0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEBAAEBV?$allocator@H@2@XZ 0x1414591f0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@W4Unk_LogLevel@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@2@XZ 0x141459200 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@W4Unk_LogLevel@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@2@XZ 0x141459210 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@XZ 0x141459240 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@2@XZ 0x141459250 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x1414592b0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@2@XZ 0x141459340 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@2@XZ 0x141459370 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAV?$allocator@H@2@XZ 0x1414593e0 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBV?$allocator@H@2@XZ 0x141459400 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@W4Unk_LogLevel@@@2@XZ 0x141459480 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@W4Unk_LogLevel@@@2@XZ 0x1414594a0 ; prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@HV?$allocator@H@std@@@std@@AEBA_NXZ 0x141459910 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEBAAEBW4Unk_LogLevel@@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@Z 0x1414599e0 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEBAAEBW4Unk_LogLevel@@AEBU?$pair@$$CBW4Unk_LogLevel@@_N@2@@Z 0x141459a10 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@XZ 0x141459a30 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@Z 0x141459a40 ; unique
// MS2-PIN: ?_Make_iter@?$list@V?$MS2Ptr@VLogDialogCtx@@@@V?$allocator@V?$MS2Ptr@VLogDialogCtx@@@@@std@@@std@@QEBA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VLogDialogCtx@@@@@std@@@std@@@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VLogDialogCtx@@@@@std@@@std@@@2@@Z 0x141459b20 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@PEAU32@@Z 0x141459bb0 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@PEAU32@@Z 0x141459be0 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x141459c50 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x141459c70 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x141459cf0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x141459d70 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x141459d90 ; prop
// MS2-PIN: ?_Mysize@?$_List_alloc@U?$_List_base_types@V?$MS2Ptr@VLogDialogCtx@@@@V?$allocator@V?$MS2Ptr@VLogDialogCtx@@@@@std@@@std@@@std@@QEBAAEB_KXZ 0x141459e50 ; unique
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAXXZ 0x141459eb0 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@HV?$allocator@H@std@@@std@@AEBAXPEAH0@Z 0x141459ee0 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@XZ 0x14145a0a0 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@XZ 0x14145a0c0 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@@Z 0x14145a0e0 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x14145a1f0 ; unique
// MS2-PIN: ?_Tidy@?$vector@HV?$allocator@H@std@@@std@@AEAAXXZ 0x14145a490 ; unique
// MS2-PIN: ?_Umove@?$vector@HV?$allocator@H@std@@@std@@AEAAPEAHPEAH00@Z 0x14145a5a0 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH00U?$integral_constant@_N$00@2@@Z 0x14145a620 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH00@Z 0x14145a6c0 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@_K@Z 0x14145a8d0 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@2@XZ 0x14145a960 ; unique
// MS2-PIN: ?capacity@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x14145ab30 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14145ab70 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVClientLogManager@@P81@EAAXPEAVCLogStringCtx@@@Z@std@@@?$Delegate@$$A6AXPEAVCLogStringCtx@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14145ada0 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@_K@Z 0x14145ae30 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@2@_K@Z 0x14145aec0 ; prop
// MS2-PIN: ?deallocate@?$allocator@H@std@@QEAAXQEAH_K@Z 0x14145af20 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@2@XZ 0x14145af90 ; unique
// MS2-PIN: ?end@?$vector@HV?$allocator@H@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@2@XZ 0x14145b0d0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@2@0@Z 0x14145b130 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@2@@Z 0x14145b220 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVClientLogManager@@P81@EAAXPEAVCLogStringCtx@@@Z@std@@@?$Delegate@$$A6AXPEAVCLogStringCtx@@@Z@@UEAAXPEAVCLogStringCtx@@@Z 0x14145b340 ; unique
// MS2-PIN: ??$Call@VClientLogManager@@P81@EAAXPEAVCLogStringCtx@@@Z@?$DelegateImpl@U?$pair@PEAVClientLogManager@@P81@EAAXPEAVCLogStringCtx@@@Z@std@@@?$Delegate@$$A6AXPEAVCLogStringCtx@@@Z@@CAXAEAU?$pair@PEAVClientLogManager@@P81@EAAXPEAVCLogStringCtx@@@Z@std@@PEAVCLogStringCtx@@@Z 0x14145b370 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVClientLogManager@@P81@EAAXPEAVCLogStringCtx@@@Z@std@@@?$Delegate@$$A6AXPEAVCLogStringCtx@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14145b3a0 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@@std@@@2@AEBW4Unk_LogLevel@@@Z 0x14145b400 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@PEAX@std@@@2@@Z 0x14145b470 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@H@std@@@std@@SA_KAEBV?$allocator@H@2@@Z 0x14145b490 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x14145b4a0 ; prop
// MS2-PIN: ?max_size@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x14145b550 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBW4Unk_LogLevel@@_N@std@@@std@@SAPEAU?$pair@$$CBW4Unk_LogLevel@@_N@2@AEAU32@@Z 0x14145b5a0 ; prop
// MS2-PIN: ?push_back@?$vector@HV?$allocator@H@std@@@std@@QEAAX$$QEAH@Z 0x14145b9f0 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@W4Unk_LogLevel@@_NU?$less@W4Unk_LogLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_LogLevel@@_N@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x14145ba20 ; unique
// MS2-PIN: ?size@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x14145bac0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\logdialog.cpp"    // assumed
// The exe's memcpy_s/memmove_s are plain calls (no /Oi expansion); the pragma must precede the inline copies.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include <iterator>
#include "logdialog.h"
#include "ms2/placeholder/clientlogmanager.h"
#include "ms2/guess/usercommandcli.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#pragma intrinsic(memset, memcpy)                                       // template code below expands them inline again

// ---- unit-local views of callees emitted in other units ----
CStringA FUN_140540050(const char* pszFormat, const CStringA& arg0);    // StringFormat<CStringA>
CStringW FUN_14016a730(const char* psz, int nCodePage);                 // narrow -> wide
CStringA FUN_14016a600(const wchar_t* psz, int nCodePage);              // wide -> narrow
void FUN_141361e60(CStringW strCommand);                                // send a chat line
void FUN_14083d990(CStringA strText);                                   // copy to the clipboard
void FUN_1412751b0(const CStringW& strText, int nType);                 // HUD system message
struct Unk_DcApp;
Unk_DcApp* FUN_140aadf80();                                             // the app
HWND FUN_14209c720(Unk_DcApp* pApp);                                    // its main window

// MS2Ptr<CLogDialog>: CLogDialog's CPtred base is at +0x138, so the exe's pointer converts through CPtred* (the
// reference helpers take a CPtred* tag computed from a null CLogDialog*).
template <> void MS2Ptr<CLogDialog>::AddRef() const
{
    if (m_p)
        AddRefImpl(static_cast<CPtred*>((CLogDialog*)0));
}
template <> void MS2Ptr<CLogDialog>::Release()
{
    if (m_p)
    {
        ReleaseImpl(static_cast<CPtred*>((CLogDialog*)0));
        m_p = 0;
    }
}
template <> MS2Ptr<CLogDialog>::MS2Ptr(CLogDialog* p)
{
    m_p = static_cast<CLogDialog*>(static_cast<CPtred*>(p));
    AddRef();
}

template <> Delegate<void(CLogStringCtx*)>::DelegateImplBase::DelegateImplBase() {}
template <> Delegate<void(CLogStringCtx*)>::DelegateImplBase::~DelegateImplBase() {}

int g_nLogDialogLine = 0;                                               // DAT_143adc958 the running line number

IMPLEMENT_DYNAMIC(CLogDialog, CDialog)

// @0x14144fee0
CLogDialog::CLogDialog(CWnd* pParent) : CToolBaseDialog(0x8c, pParent), m_nCategory(0)
{
    m_levels[(Unk_LogLevel)1] = true;
    m_levels[(Unk_LogLevel)2] = true;
    m_levels[(Unk_LogLevel)11] = true;
    m_levels[(Unk_LogLevel)12] = true;
    m_categories.push_back(0);
    m_categories.push_back(0x13);
    m_categories.push_back(0x12f);
    m_categories.push_back(0x133);
    m_categories.push_back(0x134);
}

// @0x141450130
CLogDialog::~CLogDialog()
{
}

// @0x141450220
void CLogDialog::SetLogContexts(std::list<LogDialogCtxPtr>& logs)
{
    m_all.clear();
    std::copy(logs.begin(), logs.end(), std::back_inserter(m_all));
}

// @0x1414502b0
void CLogDialog::AddLogContext(LogDialogCtxPtr spCtx)
{
    if (IsNotCreated())
        return;
    if (m_all.size() > 1000)
        m_all.pop_front();
    m_all.push_back(spCtx);
    if (IsFiltered(spCtx))
        return;
    m_shown.push_back(spCtx);
    SetRowCount((int)m_shown.size());
}

// @0x1414503c0
void CLogDialog::DoDataExchange(CDataExchange* pDX)
{
    CWnd::DoDataExchange(pDX);
    DDX_Control(pDX, 0x4b5, m_list);
    DDX_Control(pDX, 0x4b6, m_comboCategory);
    DDX_Control(pDX, 0x4e1, m_editCommand);
}

// @0x141450440
BOOL CLogDialog::OnInitDialog()
{
    if (!CToolBaseDialog::OnInitDialog())
        return FALSE;
    UpdateData(FALSE);
    CRect rc;
    m_list.GetClientRect(rc);
    m_list.InsertColumn(0, "Num", LVCFMT_RIGHT, 0x32, -1);
    m_list.InsertColumn(1, "Lv", LVCFMT_LEFT, 0x1e, -1);
    m_list.InsertColumn(2, "Type", LVCFMT_LEFT, 0x46, -1);
    m_list.InsertColumn(3, "Log", LVCFMT_LEFT, rc.Width() - 0x96, -1);
    m_list.SetExtendedStyle(LVS_EX_DOUBLEBUFFER | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    Rebuild();
    MS2_FOR_EACH(int nCategory, m_categories)
    {
        m_comboCategory.AddString(ClientLogManager::GetCategoryName((Unk_LogCategory)nCategory));
    }
    m_comboCategory.SetCurSel(0);
    CheckDlgButton(0x4b8, m_levels[(Unk_LogLevel)1]);
    CheckDlgButton(0x4b9, m_levels[(Unk_LogLevel)2]);
    CheckDlgButton(0x4ba, m_levels[(Unk_LogLevel)11]);
    CheckDlgButton(0x4bb, m_levels[(Unk_LogLevel)12]);
    return TRUE;
}

// @0x1414507c0
BOOL CLogDialog::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_RETURN)
        {
            CWnd* pFocus = GetFocus();
            if (pFocus)
            {
                int nId = pFocus->GetDlgCtrlID();
                switch (nId)
                {
                case 0x4e1:
                    ExecuteCommand();
                    return FALSE;
                }
            }
        }
        else if (pMsg->wParam == 'C')
        {
            if (GetAsyncKeyState(VK_CONTROL) < 0)
                CopySelection();
        }
    }
    return CToolBaseDialog::PreTranslateMessage(pMsg);
}

BEGIN_MESSAGE_MAP(CLogDialog, CDialog)
    ON_WM_WINDOWPOSCHANGING()
    ON_WM_SIZE()
    ON_WM_CLOSE()
    ON_WM_DESTROY()
    ON_NOTIFY(LVN_COLUMNCLICK, 0x4b5, &CLogDialog::OnLvnColumnclickList)
    ON_BN_CLICKED(0x4b7, &CLogDialog::OnBnClickedClear)
    ON_BN_CLICKED(0x4f1, &CLogDialog::OnBnClickedClearFilter)
    ON_CBN_SELCHANGE(0x4b6, &CLogDialog::OnCbnSelchangeCategory)
    ON_EN_CHANGE(0x4e2, &CLogDialog::OnEnChangeFilter)
    ON_NOTIFY(LVN_GETDISPINFOA, 0x4b5, &CLogDialog::OnLvnGetdispinfoList)
    ON_BN_CLICKED(0x4b8, &CLogDialog::OnBnClickedError)
    ON_BN_CLICKED(0x4b9, &CLogDialog::OnBnClickedWarning)
    ON_BN_CLICKED(0x4ba, &CLogDialog::OnBnClickedInfo)
    ON_BN_CLICKED(0x4bb, &CLogDialog::OnBnClickedDebug)
END_MESSAGE_MAP()

// @0x1414508a0
void CLogDialog::OnSize(UINT nType, int cx, int cy)
{
    CToolBaseDialog::OnSize(nType, cx, cy);
    Resize(cx, cy);
}

// @0x1414508f0
void CLogDialog::OnLvnColumnclickList(NMHDR* pNMHDR, LRESULT* pResult)
{
}

// @0x141450910
void CLogDialog::OnCbnSelchangeCategory()
{
    int nSel = m_comboCategory.GetCurSel();
    if (nSel < 0 || nSel >= (int)m_categories.size())
        return;
    m_nCategory = m_categories[m_comboCategory.GetCurSel()];
    Rebuild();
}

// @0x1414509a0
void CLogDialog::OnBnClickedClear()
{
    m_all.clear();
    m_shown.clear();
    SetRowCount(0);
}

// @0x1414509f0
void CLogDialog::OnBnClickedClearFilter()
{
    m_strFilter.Empty();
    SetDlgItemText(0x4e2, m_strFilter);
}

// @0x141450a40
void CLogDialog::OnEnChangeFilter()
{
    GetDlgItemText(0x4e2, m_strFilter);
}

// @0x141450a80
void CLogDialog::OnBnClickedError()
{
    m_levels[(Unk_LogLevel)1] = IsDlgButtonChecked(0x4b8) ? 1 : 0;
    Rebuild();
}

// @0x141450af0
void CLogDialog::OnBnClickedWarning()
{
    m_levels[(Unk_LogLevel)2] = IsDlgButtonChecked(0x4b9) ? 1 : 0;
    Rebuild();
}

// @0x141450b60
void CLogDialog::OnBnClickedInfo()
{
    m_levels[(Unk_LogLevel)11] = IsDlgButtonChecked(0x4ba) ? 1 : 0;
    Rebuild();
}

// @0x141450bd0
void CLogDialog::OnBnClickedDebug()
{
    m_levels[(Unk_LogLevel)12] = IsDlgButtonChecked(0x4bb) ? 1 : 0;
    Rebuild();
}

// @0x141450c40
void CLogDialog::Resize(int cx, int cy)
{
    CRect rc;
    m_list.GetWindowRect(&rc);
    ScreenToClient(rc);
    rc.right = cx - 10;
    rc.bottom = cy - 10;
    m_list.MoveWindow(rc, TRUE);
}

// @0x141450cf0
void CLogDialog::ExecuteCommand()
{
    CStringA strText;
    m_editCommand.GetWindowText(strText);
    if (!strText.IsEmpty())
    {
        m_editCommand.SetWindowText("");
        CStringW strCommand = FUN_14016a730(strText, 0);
        if (CUserCommandCli::GetInstance()->Execute(strCommand))
            return;
        FUN_141361e60(strCommand);
    }
}

// @0x141450e20
bool CLogDialog::IsFiltered(LogDialogCtxPtr spCtx)
{
    if (!m_levels[reinterpret_cast<const Unk_LogLevel&>(spCtx->m_nLevel)])
        return true;
    if (m_nCategory != 0 && m_nCategory != spCtx->m_nCategory)
        return true;
    if (!m_strFilter.IsEmpty())
    {
        if (spCtx->m_strText.Find(m_strFilter, 0) == -1)
            return true;
    }
    return false;
}

// @0x141450f50
void CLogDialog::Rebuild()
{
    m_shown.clear();
    MS2_FOR_EACH(LogDialogCtxPtr spCtx, m_all)
    {
        if (IsFiltered(spCtx))
            continue;
        m_shown.push_back(spCtx);
    }
    SetRowCount((int)m_shown.size());
}

// @0x1414510f0
void CLogDialog::SetRowCount(int nCount)
{
    m_list.SetItemCount(nCount);
    if (nCount > 0)
        m_list.EnsureVisible(nCount - 1, TRUE);
}

// @0x141451150
void CLogDialog::CopySelection()
{
    CStringA strText;
    POSITION pos = m_list.GetFirstSelectedItemPosition();
    while (pos)
    {
        int nItem = m_list.GetNextSelectedItem(pos);
        strText.Append(FUN_140540050("{0}\n", m_list.GetItemText(nItem, 3)));
    }
    FUN_14083d990(strText);
}

// @0x141451290
void CLogDialog::OnLvnGetdispinfoList(NMHDR* pNMHDR, LRESULT* pResult)
{
    NMLVDISPINFOA* pDispInfo = reinterpret_cast<NMLVDISPINFOA*>(pNMHDR);
    LVITEMA* pItem = &pDispInfo->item;
    if (pItem->mask & LVIF_TEXT)
    {
        LogDialogCtxPtr spCtx = m_shown[pItem->iItem];
        if (spCtx == 0)
        {
            *pResult = 0;
            return;
        }
        switch (pItem->iSubItem)
        {
        case 0:
            pItem->pszText = (LPSTR)(LPCSTR)spCtx->m_strNum;
            break;
        case 1:
            pItem->pszText = (LPSTR)(LPCSTR)spCtx->m_strLevel;
            break;
        case 2:
            pItem->pszText = (LPSTR)(LPCSTR)spCtx->m_strCategory;
            break;
        case 3:
            pItem->pszText = (LPSTR)(LPCSTR)spCtx->m_strText;
            break;
        }
    }
    *pResult = 0;
}

// ---- ClientLogManager ----

// @0x141451410
ClientLogManager::ClientLogManager() : m_bQuiet(false), m_itPending(m_logs.end())
{
    TSingleton<CLogString>::GetInstance()->FUN_140653b80(
        Delegate<void(CLogStringCtx*)>(this, &ClientLogManager::OnLogString));
}

// @0x141451500
ClientLogManager::~ClientLogManager()
{
    TSingleton<CLogString>::GetInstance()->FUN_140653bf0(
        Delegate<void(CLogStringCtx*)>(this, &ClientLogManager::OnLogString));
}

// @0x1414515c0
void ClientLogManager::SetQuiet()
{
    m_bQuiet = true;
}
MS2_REPLACE_METHOD(0x1414515C0, ClientLogManager, SetQuiet, 15, 0xD30DC895);

// @0x1414515e0
void ClientLogManager::ToggleDialog()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_spDialog && !m_spDialog->IsNotCreated())
    {
        m_spDialog->SendMessage(WM_CLOSE);
        m_spDialog = 0;
    }
    else
    {
        m_spDialog.AssignRaw(new CLogDialog);
        m_spDialog->SetLogContexts(m_logs);
        m_spDialog->Create(0x8c, CWnd::FromHandle(FUN_14209c720(FUN_140aadf80())));
        m_itPending = m_logs.end();
    }
}

// @0x1414517c0
void ClientLogManager::OnLogString(CLogStringCtx* pCtx)
{
    MS2Ptr<LogDialogCtx> spCtx(new LogDialogCtx);
    spCtx->m_nLevel = pCtx->m_level;
    spCtx->m_nCategory = pCtx->m_category;
    spCtx->m_strNum = StringFormat("{0}", ++g_nLogDialogLine);
    spCtx->m_strLevel = GetLevelName(pCtx->m_level);
    spCtx->m_strCategory = GetCategoryName((Unk_LogCategory)pCtx->m_category);
    spCtx->m_strText = FUN_14016a600(pCtx->m_text, 0);
    spCtx->m_strTextW = pCtx->m_text;
    AppendLogContext(spCtx);
}

// @0x141451a60
void ClientLogManager::Flush()
{
    if (m_itPending == m_logs.end())
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (; m_itPending != m_logs.end(); ++m_itPending)
    {
        if (m_spDialog.get())
            m_spDialog->AddLogContext(*m_itPending);
        if (!m_bQuiet)
        {
            MS2Ptr<LogDialogCtx> spCtx = *m_itPending;
            if (spCtx->m_nLevel <= TSingleton<CLogString>::GetInstance()->FUN_140653860() && spCtx->m_nLevel <= 2)
                FUN_1412751b0(spCtx->m_strTextW, 0x14);
        }
    }
}

// @0x141451c40
CStringA ClientLogManager::GetCategoryName(Unk_LogCategory nCategory)
{
    switch ((int)nCategory)
    {
    case 0:
        return "None";
    case 0x13:
        return "Data";
    case 0x12f:
        return "Sound";
    case 0x133:
        return "Effect";
    case 0x134:
        return "Skill";
    default:
        return StringFormat("LT{0:03}", nCategory);
    }
}
MS2_REPLACE(0x141451C40, ClientLogManager::GetCategoryName, 315, 0x068DAAEA);

// @0x141451d90
CStringA ClientLogManager::GetLevelName(int nLevel)
{
    switch (nLevel)
    {
    case 1:
        return "E";
    case 2:
        return "W";
    case 11:
        return "I";
    case 12:
        return "D";
    default:
        return "U";
    }
}
MS2_REPLACE_METHOD(0x141451D90, ClientLogManager, GetLevelName, 254, 0x19E8B4EF);

// @0x141451ea0
void ClientLogManager::AppendLogContext(MS2Ptr<LogDialogCtx> spCtx)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    const size_t nMax = 1000;
    if (m_logs.size() > nMax)
    {
        if (m_itPending == m_logs.begin())
            ++m_itPending;
        m_logs.erase(m_logs.begin());
    }
    m_logs.push_back(spCtx);
    if (m_itPending == m_logs.end())
    {
        m_itPending = m_logs.end();
        --m_itPending;
    }
}

// memcpy_s 0x14145bb00 and memmove_s 0x14145bc50 close the obj's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_logDialogMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
__declspec(selectany) extern errno_t(__cdecl* const ms2_logDialogMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;

// IMPLEMENT_DYNAMIC's _GetBaseClass sits just before this TU's range start in the exe.
// MS2-RANGE: 0x14144fe90-0x14144fec0 .text$mn
