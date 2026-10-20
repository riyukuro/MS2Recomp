// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPlayInstrumentDialog ("PlayInstrumentDialog", UI type 0x4eec,
// 0x288 bytes) is the instrument playing window: the keyboard play page (m_playDirectPage, 24 key buttons + octave keys),
// the score page (up to three score slots, solo / ensemble play) and the mastery bar. See uiplayinstrumentdialog.h.
// MS2-UNIT: client\ms2\uiplayinstrumentdialog.cpp
// MS2-RANGE: 0x1400e39d0-0x1400e3ce0 .text$di
// MS2-RANGE: 0x14100a030-0x141017950 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSortNames7@@YAXXZ 0x1400e39d0 ; probe
// MS2-PIN: ??__Es_strSkill2@@YAXXZ 0x1400e3a90 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400e3ac0 ; probe
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400e3af0 ; probe
// MS2-PIN: ??__Es_strSortNames7b@@YAXXZ 0x1400e3b70 ; probe
// MS2-PIN: ??__Es_strStun2@@YAXXZ 0x1400e3c30 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400e3c60 ; probe
// MS2-PIN: ??__Es_unk1402a9d70b@@YAXXZ 0x1400e3c90 ; probe
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14100f470 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14100f4a0 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$pair@HH@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14100f4d0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@$$QEA_N@Z 0x14100f550 ; order
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14100f5a0 ; order
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14100f5f0 ; unique
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14100f640 ; prop
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x14100f690 ; prop
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHI@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x14100f6e0 ; prop
// MS2-PIN: ??$?0AEBH$0A@@?$tuple@AEBH@std@@QEAA@AEBH@Z 0x14100f730 ; unique
// MS2-PIN: ??$?0U_Exact_args_t@std@@AEBH$$V$0A@@?$tuple@AEBH@std@@QEAA@U_Exact_args_t@1@AEBH@Z 0x14100f7e0 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@$$QEA_N@Z 0x14100f840 ; order
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14100f890 ; order
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14100f8e0 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHI@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14100f930 ; unique
// MS2-PIN: ??$?0HAEBH$0A@@?$pair@HH@std@@QEAA@$$QEAHAEBH@Z 0x14100f9b0 ; prop
// MS2-PIN: ??$?0HH$0A@@?$pair@HH@std@@QEAA@$$QEAH0@Z 0x14100fa00 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHI@std@@@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHI@1@@Z 0x14100ffa0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14100ffc0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141010090 ; unique
// MS2-PIN: ??$_Const_cast@$$CBU?$pair@HH@std@@@std@@YAPEAU?$pair@HH@0@PEBU10@@Z 0x141010160 ; prop
// MS2-PIN: ??$_Destroy_range1@V?$allocator@U?$pair@HH@std@@@std@@@std@@YAXPEAU?$pair@HH@0@0AEAV?$allocator@U?$pair@HH@std@@@0@U?$integral_constant@_N$00@0@@Z 0x141010170 ; unique
// MS2-PIN: ??$_Destroy_range@V?$allocator@U?$pair@HH@std@@@std@@@std@@YAXPEAU?$pair@HH@0@0AEAV?$allocator@U?$pair@HH@std@@@0@@Z 0x141010190 ; unique
// MS2-PIN: ??$_Emplace_back@U?$pair@HH@std@@@?$_Uninitialized_backout_al@PEAU?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAX$$QEAU?$pair@HH@1@@Z 0x1410101e0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@U?$pair@HH@std@@@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAX$$QEAU?$pair@HH@1@@Z 0x141010240 ; unique
// MS2-PIN: ??$_Emplace_reallocate@U?$pair@HH@std@@@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAPEAU?$pair@HH@1@QEAU21@$$QEAU21@@Z 0x141010300 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@1@PEAU01@@Z 0x1410105d0 ; unique
// MS2-PIN: ??$_Get_unwrapped@U?$pair@HH@std@@@std@@YAPEAU?$pair@HH@0@QEAU10@@Z 0x141010660 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAU?$pair@HH@std@@PEAU12@@std@@YA_JAEBQEAU?$pair@HH@0@0Urandom_access_iterator_tag@0@@Z 0x141010680 ; unique
// MS2-PIN: ??$_Idl_distance@PEAU?$pair@HH@std@@PEAU12@@std@@YA_JAEBQEAU?$pair@HH@0@0@Z 0x1410106b0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHI@std@@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@AEAU?$pair@$$CBHI@1@1@Z 0x141010a40 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@PEAX@1@@Z 0x141010da0 ; prop
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHI@std@@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@AEAU?$pair@$$CBHI@1@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@@Z 0x1410119e0 ; prop
// MS2-PIN: ??$_Kfn@$$CBHI@?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHI@1@@Z 0x141012e50 ; prop
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@AEBH@Z 0x141012f00 ; unique
// MS2-PIN: ??$_Ptr_move_cat@U?$pair@HH@std@@U12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAU?$pair@HH@0@0@Z 0x141012fa0 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141012ff0 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141013140 ; prop
// MS2-PIN: ??$_Unfancy@U?$pair@HH@std@@@std@@YAPEAU?$pair@HH@0@PEAU10@@Z 0x141013290 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAU?$pair@HH@std@@PEAU12@V?$allocator@U?$pair@HH@std@@@2@@std@@YAPEAU?$pair@HH@0@QEAU10@0PEAU10@AEAV?$allocator@U?$pair@HH@std@@@0@@Z 0x1410132a0 ; unique
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAU?$pair@HH@std@@PEAU12@V?$allocator@U?$pair@HH@std@@@2@@std@@YAPEAU?$pair@HH@0@PEAU10@QEAU10@1AEAV?$allocator@U?$pair@HH@std@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141013370 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@0@AEAPEAU10@@Z 0x141013410 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBHI@std@@@std@@YAPEAU?$pair@$$CBHI@0@AEAU10@@Z 0x141013430 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@0@AEAV10@@Z 0x141013450 ; prop
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@0@AEAV10@@Z 0x141013460 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@AEAPEAU31@@Z 0x1410134c0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141013510 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHI@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@1@QEAU?$pair@$$CBHI@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1410135c0 ; unique
// MS2-PIN: ??$construct@U?$pair@HH@std@@U12@@?$_Default_allocator_traits@V?$allocator@U?$pair@HH@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@HH@std@@@1@QEAU?$pair@HH@1@$$QEAU31@@Z 0x141013670 ; unique
// MS2-PIN: ??$destroy@U?$pair@$$CBHI@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@1@QEAU?$pair@$$CBHI@1@@Z 0x141013700 ; prop
// MS2-PIN: ??$emplace_back@U?$pair@HH@std@@@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAX$$QEAU?$pair@HH@1@@Z 0x141013710 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141013780 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141013820 ; unique
// MS2-PIN: ??$erase@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@X@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@V21@@Z 0x1410138c0 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@0@AEAPEAU10@@Z 0x141013910 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBHI@std@@@std@@YAAEAU?$pair@$$CBHI@0@AEAU10@@Z 0x141013930 ; prop
// MS2-PIN: ??$forward@AEBH@std@@YAAEBHAEBH@Z 0x141013960 ; prop
// MS2-PIN: ??$forward@U?$pair@HH@std@@@std@@YA$$QEAU?$pair@HH@0@AEAU10@@Z 0x141013970 ; prop
// MS2-PIN: ??$forward@V?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x1410139a0 ; prop
// MS2-PIN: ??$forward_as_tuple@AEBH@std@@YA?AV?$tuple@AEBH@0@AEBH@Z 0x1410139b0 ; unique
// MS2-PIN: ??$get@$0A@AEBH@std@@YAAEBH$$QEAV?$tuple@AEBH@0@@Z 0x1410139e0 ; unique
// MS2-PIN: ??$make_pair@HAEBH@std@@YA?AU?$pair@HH@0@$$QEAHAEBH@Z 0x141013a60 ; unique
// MS2-PIN: ??$make_pair@HH@std@@YA?AU?$pair@HH@0@$$QEAH0@Z 0x141013ab0 ; unique
// MS2-PIN: ??$move@AEAU?$pair@HH@std@@@std@@YA$$QEAU?$pair@HH@0@AEAU10@@Z 0x141013b20 ; prop
// MS2-PIN: ??$move@AEAV?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x141013b30 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141013b80 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141013bf0 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141013c60 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@1@@Z 0x141013d00 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141013d40 ; order
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@1@@Z 0x141013da0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141013e20 ; order
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@1@@Z 0x141013e40 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141013ea0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@QEAA@XZ 0x141013ed0 ; prop
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAU?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAA@PEAU?$pair@HH@1@AEAV?$allocator@U?$pair@HH@std@@@1@@Z 0x141013f00 ; unique
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEAA@XZ 0x141013f40 ; unique
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@std@@QEAA@PEAU?$pair@HH@1@PEBU_Container_base0@1@@Z 0x141013f70 ; prop
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@std@@QEAA@PEAU?$pair@HH@1@PEBU_Container_base0@1@@Z 0x141013fb0 ; prop
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@QEAA@XZ 0x141013ff0 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141014030 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@QEAA@XZ 0x141014040 ; prop
// MS2-PIN: ??0?$allocator@U?$pair@HH@std@@@std@@QEAA@XZ 0x141014050 ; prop
// MS2-PIN: ??0?$map@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@@std@@QEAA@XZ 0x141014090 ; unique
// MS2-PIN: ??0?$tuple@AEBH@std@@QEAA@$$QEAV01@@Z 0x1410140c0 ; unique
// MS2-PIN: ??0?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAA@XZ 0x141014100 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1410141c0 ; unique
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAU?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAA@XZ 0x1410141f0 ; unique
// MS2-PIN: ??1?$map@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@@std@@QEAA@XZ 0x141014250 ; unique
// MS2-PIN: ??7?$MS2Ptr@VASMovieClip@@@@QEBA_NXZ 0x1410142e0 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141014350 ; unique
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141014390 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141014420 ; prop
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141014460 ; prop
// MS2-PIN: ??A?$map@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@@std@@QEAAAEAIAEBH@Z 0x1410144e0 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHI@1@XZ 0x141014540 ; prop
// MS2-PIN: ??C?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@std@@QEBAPEAU?$pair@HH@1@XZ 0x141014570 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBHI@1@XZ 0x1410145b0 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHI@1@XZ 0x1410145f0 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141014680 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1410146d0 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141014710 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1410147c0 ; unique
// MS2-PIN: ??E?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141014870 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141014890 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1410148b0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1410148d0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1410148f0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1410149e0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@XZ 0x141014c00 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@XZ 0x141014da0 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEBA_K_K@Z 0x141014e80 ; unique
// MS2-PIN: ?_Change_array@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXQEAU?$pair@HH@2@_K1@Z 0x141014f10 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141015020 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141015060 ; prop
// MS2-PIN: ?_Compat@?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@std@@QEBAXAEBV12@@Z 0x1410150a0 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1410150e0 ; unique
// MS2-PIN: ?_Destroy@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXPEAU?$pair@HH@2@0@Z 0x141015110 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x1410151a0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x141015290 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@@Z 0x1410158e0 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x141015ec0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x141015f20 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@XZ 0x141015fb0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@XZ 0x141015fe0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@2@XZ 0x141016010 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@2@XZ 0x141016030 ; prop
// MS2-PIN: ??0?$tuple@$$V@std@@QEAA@XZ 0x141016050 ; order
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@2@XZ 0x1410160b0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@2@XZ 0x1410160c0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@HH@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$pair@HH@std@@@2@XZ 0x1410160d0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@HH@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$pair@HH@std@@@2@XZ 0x1410160e0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@2@XZ 0x141016110 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@2@XZ 0x141016120 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@XZ 0x141016150 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@XZ 0x141016160 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$pair@HH@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@2@XZ 0x141016170 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$pair@HH@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@2@XZ 0x141016180 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@2@XZ 0x1410161f0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@2@XZ 0x141016220 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEAAAEAV?$allocator@U?$pair@HH@std@@@2@XZ 0x141016250 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEBAAEBV?$allocator@U?$pair@HH@std@@@2@XZ 0x141016270 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x1410162d0 ; order
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x1410162f0 ; order
// MS2-PIN: ?_Has_unused_capacity@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEBA_NXZ 0x141016310 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x141016390 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHI@2@@Z 0x1410163e0 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@XZ 0x141016410 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x141016500 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@PEAU32@@Z 0x141016610 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@PEAU32@@Z 0x141016670 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@HH@2@XZ 0x1410166a0 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@HH@2@XZ 0x1410166c0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@HH@2@XZ 0x141016700 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@HH@2@XZ 0x141016720 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@HH@2@XZ 0x141016740 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@@std@@QEAAXXZ 0x141016760 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEBAXPEAU?$pair@HH@2@0@Z 0x141016780 ; unique
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAU?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAPEAU?$pair@HH@2@XZ 0x141016790 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@XZ 0x1410167d0 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@XZ 0x141016810 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x141016910 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x141016a50 ; unique
// MS2-PIN: ?_Tidy@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXXZ 0x141016ab0 ; unique
// MS2-PIN: ?_Umove@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAPEAU?$pair@HH@2@PEAU32@00@Z 0x141016b80 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXPEAU?$pair@HH@2@00U?$integral_constant@_N$00@2@@Z 0x141016bc0 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXPEAU?$pair@HH@2@00@Z 0x141016c00 ; unique
// MS2-PIN: ?_Xrange@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@CAXXZ 0x141016c80 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@_K@Z 0x141016cd0 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$pair@HH@std@@@std@@QEAAPEAU?$pair@HH@2@_K@Z 0x141016d00 ; prop
// MS2-PIN: ?at@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAAEAU?$pair@HH@2@_K@Z 0x141016d30 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@XZ 0x141016de0 ; unique
// MS2-PIN: ?begin@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@2@XZ 0x141016e50 ; prop
// MS2-PIN: ?capacity@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEBA_KXZ 0x141016eb0 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x141016f90 ; unique
// MS2-PIN: ?clear@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAXXZ 0x141017030 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@_K@Z 0x1410170e0 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@_K@Z 0x141017140 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$pair@HH@std@@@std@@QEAAXQEAU?$pair@HH@2@_K@Z 0x141017170 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@XZ 0x141017200 ; unique
// MS2-PIN: ?end@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@HH@std@@@std@@@std@@@2@XZ 0x141017260 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@0@Z 0x141017460 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@@Z 0x141017550 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x141017600 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@AEBH@Z 0x141017740 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@2@@Z 0x1410177b0 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$pair@HH@std@@@std@@@std@@SA_KAEBV?$allocator@U?$pair@HH@std@@@2@@Z 0x1410177c0 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1410177f0 ; prop
// MS2-PIN: ?max_size@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEBA_KXZ 0x141017810 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBHI@std@@@std@@SAPEAU?$pair@$$CBHI@2@AEAU32@@Z 0x141017880 ; prop
// MS2-PIN: ?push_back@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAX$$QEAU?$pair@HH@2@@Z 0x1410178a0 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@HV?$MS2Ptr@VUnk_140acd6e0@@@@@std@@@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1410178d0 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1410178f0 ; prop
// MS2-PIN: ?size@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEBA_KXZ 0x141017910 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HKU?$less@H@std@@V?$allocator@U?$pair@$$CBHK@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHK@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141013140
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHK@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1410148f0
// MS2-PIN: ?Clone@CAtlStringMgr@ATL@@UEAAPEAUIAtlStringMgr@2@XZ 0x14103c770
// MS2-PIN: ??$StringFormat@$$BY0N@D$$BY0EA@DH$$BY0CH@D@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEAY0N@$$CBDAEAY0EA@$$CBDAEBHAEAY0CH@$$CBD@Z 0x14100faa0
//
// File name taken from the GfxError assert text.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiplayinstrumentdialog.cpp"

#define MS2_PTR_MOVE_CONVERT
#include "ms2/placeholder/ms2stdafx.h"

#include "uiplayinstrumentdialog.h"

#include <algorithm>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cinstrumentdatatable.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (dynamic initializers 0x1400e39d0..0x1400e3c90) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strSortNames7b[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);
#endif

// ---- unit-local views of exe objects ----

// A key / octave / play button of the movie.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422cdfb0(const CStringW& strLabel);                           // the button text
};

// The tab bar "m_tab".
class Unk_PiTabBar : public ASDisplayObject
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
    virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(int nOn);
    int FUN_1422e3210();                                                    // the selected tab
    void FUN_1422e31e0(int nTab);                                           // select a tab
};

// The movie clips of the pages (child buttons by name).
class Unk_PiClip : public ASMovieClip
{
public:
    MS2Ptr<Unk_140acd6e0> FUN_140acce30(const CString& strName);            // child button by name
};

// The local player object (vtable slot 59 sets the instrument mode).
class Unk_PiPlayer
{
public:
#define PI_V(n) virtual void vfunc_##n();
    PI_V(0) PI_V(1) PI_V(2) PI_V(3) PI_V(4) PI_V(5) PI_V(6) PI_V(7) PI_V(8) PI_V(9)
    PI_V(10) PI_V(11) PI_V(12) PI_V(13) PI_V(14) PI_V(15) PI_V(16) PI_V(17) PI_V(18) PI_V(19)
    PI_V(20) PI_V(21) PI_V(22) PI_V(23) PI_V(24) PI_V(25) PI_V(26) PI_V(27) PI_V(28) PI_V(29)
    PI_V(30) PI_V(31) PI_V(32) PI_V(33) PI_V(34) PI_V(35) PI_V(36) PI_V(37) PI_V(38) PI_V(39)
    PI_V(40) PI_V(41) PI_V(42) PI_V(43) PI_V(44) PI_V(45) PI_V(46) PI_V(47) PI_V(48) PI_V(49)
    PI_V(50) PI_V(51) PI_V(52) PI_V(53) PI_V(54) PI_V(55) PI_V(56) PI_V(57) PI_V(58)
#undef PI_V
    virtual void vfunc_59(int a1, int a2, int a3, int a4);
    int FUN_141662750(int nKind);                                           // the mastery experience
    int FUN_1416627d0(int nKind);                                           // the mastery level
};
class Unk_WorldSvc { public: Unk_PiPlayer* FUN_141bd0cc0(); };
Unk_WorldSvc* FUN_1403ed2d0();

// The instrument manager (singleton).
class Unk_PiMgr
{
public:
    bool FUN_140d07350();                                                   // a score is playing
    bool FUN_140d07330();                                                   // ensemble mode
    bool FUN_140d07370();                                                   // remote controlled
    int FUN_140d071b0();                                                    // can play the ensemble
    void FUN_140d08600();                                                   // stop
    void FUN_140d085a0();                                                   // stop the ensemble
    void FUN_140d073b0(int nNote);                                          // press a note
    void FUN_140d07840(unsigned nNote);                                     // release a note
    void FUN_140d07260(bool bEnsemble);                                     // set the ensemble mode
    int FUN_140d0b0c0();                                                    // the auto play volume
    void FUN_140d0b0e0(int nVolume);                                        // set it
    bool FUN_140d07960(__int64 nScoreUid);                                  // play the score
    bool FUN_140d07f00(__int64 nScoreUid);                                  // play the ensemble score
};
Unk_PiMgr* FUN_140c8dac0();

// The player inventory (global at 0x143ab2a90): item lookup by uid.
class Unk_PiInventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid); };
extern Unk_PiInventory DAT_143ab2a90;
class Unk_ItemEquipData { public: bool FUN_14053cd10(); };
bool FUN_140a467d0(const MS2Ptr<AScript>* p);                               // the AS object is released

// The UI service (open dialog bookkeeping).
class Unk_PiUiSvc
{
public:
    int FUN_141adbb00();                                                    // the input is blocked
    int FUN_141adc940(int nUiType);                                         // the dialog is closed
    void FUN_141adc530(int nUiType);                                        // open it
    int FUN_141adc890(int nUiType);                                         // the dialog is open
    void FUN_141adc5d0(int nUiType);                                        // close it
};
Unk_PiUiSvc* FUN_1403ed2b0();

class Unk_PiPane
{
public:
#define PI_V(n) virtual void vfunc_##n();
    PI_V(0) PI_V(1) PI_V(2) PI_V(3) PI_V(4) PI_V(5) PI_V(6) PI_V(7) PI_V(8) PI_V(9)
    PI_V(10) PI_V(11) PI_V(12) PI_V(13) PI_V(14) PI_V(15) PI_V(16) PI_V(17) PI_V(18) PI_V(19)
    PI_V(20) PI_V(21) PI_V(22) PI_V(23) PI_V(24) PI_V(25) PI_V(26) PI_V(27) PI_V(28) PI_V(29)
    PI_V(30) PI_V(31) PI_V(32) PI_V(33) PI_V(34) PI_V(35) PI_V(36) PI_V(37) PI_V(38) PI_V(39)
    PI_V(40) PI_V(41) PI_V(42) PI_V(43) PI_V(44) PI_V(45) PI_V(46) PI_V(47) PI_V(48) PI_V(49)
    PI_V(50) PI_V(51) PI_V(52) PI_V(53) PI_V(54)
#undef PI_V
    virtual int vfunc_55();                                                 // the guide pane query
};
Unk_PiPane* FUN_1405344f0(int nUiType);
void FUN_141999d40(Unk_PiPane* pPane, int nMode);

class Unk_PiKeys { public: bool FUN_140d8ad60(int nKey); bool FUN_140d8af70(int nKey); };
Unk_PiKeys* FUN_140a58540();
class Unk_PiKeyNames { public: CStringW FUN_14142d220(int nKey); CStringW FUN_14142d580(int nKey); };
Unk_PiKeyNames* FUN_1409331f0();
CInstrumentDataTable* FUN_14052d1d0();                                      // the instrument table singleton

class Unk_PiPartyMgr {};
Unk_PiPartyMgr* FUN_1409670d0();
bool FUN_14162ab60(Unk_PiPartyMgr* p);                                      // the party is ready
class Unk_PiExpTable {};
Unk_PiExpTable* FUN_1409670c0();
int FUN_14066b310(Unk_PiExpTable* p, int nKind, int nLevel);                // the experience needed for a level

unsigned FUN_140869420();                                                   // the client clock (ms)
void FUN_141b706a0(int nMs, int& nMin, int& nSec, int& nCenti);            // split a time
__int64 FUN_141b71960(const char* sz);                                      // text -> uid
CStringW FUN_141b71910(__int64 nUid);                                       // uid -> text
CString FUN_1402bb1c0(const char* szFormat, const int* pn);                 // format one int
CStringW FUN_14028b8e0(const CStringW& strKey);                             // string table text
CStringW FUN_140298ea0(CStringW strKey);                             // notice text
CStringW FUN_14083dc40(const wchar_t* szFormat, int n1, int n2);            // format two ints
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);     // string table format
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a0, const CStringW& a1);
void FUN_1412751f0(const CStringW& str, int a, int b);                      // notice
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);       // message box
void FUN_14151f200();
void FUN_1408741a0(void* pCfg, const char* szSection, const char* szKey, int* pnValue);
void FUN_140874440(void* pCfg, const char* szSection, const char* szKey, int nValue, int bFlag);
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs, int n);
class Unk_PiBinder {};
Unk_PiBinder* FUN_1422c8e90(const CString& strName);
class Unk_PiSlot : public CPtred { public: __int64 FUN_141405a10(); };
Unk_PiSlot* FUN_140f15b80(Unk_PiBinder* p);
void FUN_1409b4bc0(Scaleform::GFx::Value* pOut, Scaleform::GFx::Value& v);
// The ref-counted pointer to the dragged slot: 16 bytes, driven by the exe functions below.
struct Unk_PiSlotPtr { void* m_unk_00; Unk_PiSlot* m_p; };
void FUN_140f17650(Unk_PiSlotPtr* pPtr, Unk_PiSlot* p);                     // ctor
void FUN_140f177c0(Unk_PiSlotPtr* pPtr);                                    // dtor
Unk_PiSlot* FUN_140f17a50(Unk_PiSlotPtr* pPtr);                             // get
Unk_PiSlot* FUN_140f17a70(Unk_PiSlotPtr* pPtr);                             // operator->
// The instrument row (name accessors are not recovered as members yet).
class Unk_PiInstrData : public CInstrumentData
{
public:
    CStringW FUN_14072c150() const;                                         // the name
    CStringW FUN_14072c240() const;                                         // the category name
};

void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);       // Value = psz
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);                   // Value = f

// ---- AScript::Invoke(string, float, string): the SetMasteryExp call ----
// @0x14100fe60
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, float a2, CStringW a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1.GetString());
    FUN_1422bcd70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3.GetString());
    return FUN_1422bb8f0(szMethod, args);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14100a030
UIPlayInstrumentDialog::UIPlayInstrumentDialog()
    : m_nTab(0), m_spItem(0), m_nInstrument(0), m_nCurrent(0), m_bStop(0), m_nSlotCount(1), m_nIdleTick(0), m_nStartTick(0),
      m_nEndTick(0), m_nKind(0), m_nAutoPlay(0)
{
    FUN_141924170(1);
    m_164 = 1;
    m_nOctave = 4;
    for (int i = 0; i < 3; i++)
        m_spScores[i] = 0;
}

// @0x14100a280
UIPlayInstrumentDialog::~UIPlayInstrumentDialog()
{
    for (int i = 0; i < 3; i++)
        m_spScores[i] = 0;
    m_spItem = 0;
    m_nInstrument = 0;
}

// @0x14100a420
CString UIPlayInstrumentDialog::vfunc_1()
{
    return "PlayInstrumentDialog";
}

// @0x14100a470
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_spPlayPage = FUN_140c02990("m_playDirectPage");
    if (m_spPlayPage.get())
    {
        m_spLowerOctave = static_cast<Unk_PiClip*>(m_spPlayPage.operator->())->FUN_140acce30("m_lowerOctave");
        m_spUpperOctave = static_cast<Unk_PiClip*>(m_spPlayPage.operator->())->FUN_140acce30("m_upperOctave");
    }
    m_spScorePage = FUN_140c02990("m_playScorePage");
    m_spFold = FUN_140bb4cf0("m_foldText");
    FUN_14100e060();
    FUN_14100e910();
    do
    {
        m_30->FUN_140be2480("m_tab", m_spTab);
        if (m_spTab == 0)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(81), __FUNCTION__));
    } while (0);
    FUN_14100c2c0();
    m_nKind = 0;
    if (m_spTab.get())
    {
        m_spTab->FUN_1422e31e0(m_nTab);
        m_spTab->vfunc_24(1);
        m_30->Invoke("onSelectTab", m_nTab);
    }
    CInstrumentDataTable::InstrumentPtr spData = FUN_14052d1d0()->GetInstrument(m_nInstrument);
    if (spData == 0)
        return;
    CStringW strName = static_cast<Unk_PiInstrData*>(spData.get())->FUN_14072c150();
    CStringW strCategory = static_cast<Unk_PiInstrData*>(spData.get())->FUN_14072c240();
    CStringW strText = FUN_140656190(L"{0} {1}", strCategory, strName);
    MS2Ptr<ASTextField> spCurrent = FUN_140bb4cf0("m_currentInstrument");
    if (spCurrent.get())
        spCurrent->FUN_1422c4cd0(strText);
    m_nCurrent = 0;
    m_nSlotCount = spData->m_nSoloRelayScoreCount;
    FUN_14100f1f0();
    if (FUN_1403ed2b0()->FUN_141adc940(0x4e2d))
    {
        FUN_1403ed2b0()->FUN_141adc530(0x4e2d);
        Unk_PiPane* pPane = FUN_1405344f0(0x4e2d);
        if (pPane != 0 && pPane->vfunc_55() == 0)
            FUN_141999d40(pPane, 7);
    }
}

// @0x14100ac50
void UIPlayInstrumentDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    for (int i = 0; i < 3; i++)
        m_spScores[i] = 0;
    m_spItem = 0;
    m_nInstrument = 0;
    m_nCurrent = 0;
    m_nSlotCount = 1;
    m_spTab = 0;
    m_spLowerOctave = 0;
    m_spUpperOctave = 0;
    m_spPlayPage = 0;
    m_spScorePage = 0;
    m_keyButtons.clear();
    m_spFold = 0;
    m_nAutoPlay = 0;
}

// @0x14100ad90
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::vfunc_67()
{
    Unk_PiPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
        pPlayer->vfunc_59(1, 0, 0, 0);
    m_nAutoPlay = 0;
    if (!FUN_140c8dac0()->FUN_140d07370())
    {
        if (FUN_1403ed2b0()->FUN_141adc890(0x4f07))
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f07);
        if (FUN_140c8dac0()->FUN_140d0b0c0())
            FUN_1412751f0(FUN_140298ea0(CStringW(L"s_msg_auto_play_instrument_extend_cancel")), 1, 1);
        FUN_140c8dac0()->FUN_140d0b0e0(0);
    }
}

// @0x14100aec0
int UIPlayInstrumentDialog::vfunc_54(void* pCfg)
{
    UIDialog::vfunc_54(pCfg);
    FUN_1408741a0(pCfg, "Histroy", "lastRadioIndex", &m_nTab);
    return 1;
}

// @0x14100af20
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
int UIPlayInstrumentDialog::vfunc_53(void* pCfg)
{
    if (m_spTab.get())
        m_nTab = m_spTab->FUN_1422e3210();
    UIDialog::vfunc_53(pCfg);
    FUN_140874440(pCfg, "Histroy", "lastRadioIndex", m_nTab, 1);
    return 1;
}

// @0x14100afc0
void UIPlayInstrumentDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (strMethod.CompareNoCase("getItemTooltip") == 0)
    {
        __int64 nUid = FUN_141b71960(pArgs->FUN_1422b8d30());
        ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x20, 2);
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem.get())
        {
            if (tip.FUN_1409e0d40(spItem.get()))
                FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
        }
    }
}

// @0x14100b0f0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
int UIPlayInstrumentDialog::vfunc_71()
{
    if (!FUN_140c8dac0()->FUN_140d07350())
        return 0;
    FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_play_instrument_ui_ask_close_while_playing_score")), 1, static_cast<IMessageListener*>(this), CStringW(L"askClose"));
    return 1;
}

// @0x14100b1e0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::vfunc_72()
{
    if (m_nEndTick != 0 && m_nEndTick < FUN_140869420())
    {
        FUN_140c8dac0()->FUN_140d08600();
        m_nStartTick = 0;
        m_nEndTick = 0;
    }
    FUN_14100da10();
    FUN_14100d920();
    if (FUN_140c8dac0()->FUN_140d07330())
    {
        if (FUN_1403ed2b0()->FUN_141adbb00() == 0)
        {
            KeyButtonMap::iterator it = m_keyButtons.begin();
            KeyButtonMap::iterator itEnd = m_keyButtons.end();
            while (it != itEnd)
            {
                if (FUN_140a58540()->FUN_140d8ad60(it->first))
                {
                    int nNote = m_nOctave * 12 + 12 + it->second.first;
                    m_pressed[it->first] = nNote;
                    FUN_140c8dac0()->FUN_140d073b0(nNote);
                    MS2Ptr<Unk_140acd6e0> spButton(it->second.second);
                    spButton->Invoke("onForcePress");
                }
                ++it;
            }
            std::vector<std::pair<int, int> >::iterator itKey = m_octaveKeys.begin();
            std::vector<std::pair<int, int> >::iterator itKeyEnd = m_octaveKeys.end();
            while (itKey != itKeyEnd)
            {
                if (FUN_140a58540()->FUN_140d8ad60(itKey->first))
                {
                    if (itKey->second == 100)
                        m_nOctave--;
                    else if (itKey->second == 101)
                        m_nOctave++;
                    else
                        m_nOctave = itKey->second;
                    FUN_14100e910();
                }
                ++itKey;
            }
            PressedMap::iterator itDown = m_pressed.begin();
            PressedMap::iterator itDownEnd = m_pressed.end();
            size_t nBefore = m_pressed.size();
            while (itDown != itDownEnd)
            {
                if (FUN_140a58540()->FUN_140d8af70(itDown->first))
                {
                    FUN_140c8dac0()->FUN_140d07840(itDown->second);
                    KeyButtonMap::iterator itBtn = m_keyButtons.find(itDown->first);
                    if (itBtn != m_keyButtons.end())
                    {
                        MS2Ptr<Unk_140acd6e0> spButton(itBtn->second.second);
                        spButton->Invoke("onForceRelease");
                        PressedMap::iterator itErase = itDown;
                        ++itDown;
                        m_pressed.erase(itErase);
                        continue;
                    }
                }
                ++itDown;
            }
            size_t nAfter = m_pressed.size();
            if (nBefore != 0 && nAfter == 0)
                m_nIdleTick = FUN_140869420();
            if (m_pressed.size() == 0 && m_nIdleTick != 0)
            {
                unsigned nLimit = m_nIdleTick + 5000;
                if (nLimit < FUN_140869420())
                {
                    m_nIdleTick = 0;
                    FUN_140c8dac0()->FUN_140d07260(false);
                    FUN_140c8dac0()->FUN_140d07260(true);
                }
            }
        }
    }
}

// @0x14100b7c0
int UIPlayInstrumentDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (strTag.CompareNoCase(L"askClose") == 0 && nResult == 0)
            vfunc_67();
        return 1;
    }
    return 0;
}

// @0x14100b8d0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
int UIPlayInstrumentDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("onPlayNote", szMethod) == 0)
    {
        if (FUN_14100c750() != 0)
            m_nAutoPlay = 1;
        return 1;
    }
    if (_stricmp("onStopNote", szMethod) == 0)
    {
        m_bStop = 1;
        if (m_nMode == 3)
            FUN_140c8dac0()->FUN_140d08600();
        else if (m_nMode == 2)
        {
            if (m_nKind == 0)
                FUN_140c8dac0()->FUN_140d08600();
            else if (m_nKind == 1)
                FUN_140c8dac0()->FUN_140d085a0();
        }
        if (!FUN_140c8dac0()->FUN_140d07370())
        {
            if (FUN_1403ed2b0()->FUN_141adc890(0x4f07))
                FUN_1403ed2b0()->FUN_141adc5d0(0x4f07);
            if (FUN_140c8dac0()->FUN_140d0b0c0())
                FUN_1412751f0(FUN_140298ea0(CStringW(L"s_msg_auto_play_instrument_extend_cancel")), 1, 1);
            FUN_140c8dac0()->FUN_140d0b0e0(0);
        }
        m_nAutoPlay = 0;
        return 1;
    }
    if (_stricmp("OnSelectTab", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14100c200(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("onNoteRadioSelectChange", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_nKind = data.FUN_1422b8a10();
        FUN_14100e9a0(m_nMode);
        return 1;
    }
    if (_stricmp("OnKeyPress", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nKey = data.FUN_1422b8a10();
            int nOctave = m_nOctave;
            FUN_140c8dac0()->FUN_140d073b0(nOctave * 12 + 11 + nKey);
            return 1;
        }
    }
    else if (_stricmp("OnKeyUp", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nKey = data.FUN_1422b8a10();
            int nOctave = m_nOctave;
            FUN_140c8dac0()->FUN_140d07840(nOctave * 12 + 11 + nKey);
            return 1;
        }
    }
    else if (_stricmp("OnOctave", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nDelta = data.FUN_1422b8a10();
            m_nOctave += nDelta;
            FUN_14100e910();
            return 1;
        }
    }
    else if (_stricmp("OnItemDragEnd", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            if (!FUN_14100c8f0())
                return 1;
            int nIndex = data.FUN_1422b8a10();
            CString strName = data.FUN_1422b8d30();
            Scaleform::GFx::Value value = data.FUN_1422b9260();
            Unk_PiSlotPtr spSlot;
            FUN_140f17650(&spSlot, FUN_140f15b80(FUN_1422c8e90(strName)));
            if (FUN_140f17a50(&spSlot))
            {
                __int64 nUid = FUN_140f17a70(&spSlot)->FUN_141405a10();
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
                if (spItem.get())
                {
                    FUN_14100ca90(nIndex - 1, MS2Ptr<CItem>(spItem));
                    for (int i = 0; i < 3; i++)
                    {
                        if (nIndex - 1 != i)
                        {
                            if (m_spScores[i] == spItem.get())
                                FUN_14100ca90(i, MS2Ptr<CItem>(0));
                        }
                    }
                }
            }
            FUN_140f177c0(&spSlot);
        }
        return 1;
    }
    else if (_stricmp("onClearSlot", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nIndex = data.FUN_1422b8a10();
            FUN_14100ca90(nIndex - 1, MS2Ptr<CItem>(0));
        }
        return 1;
    }
    return 0;
}

// @0x14100c1e0
void UIPlayInstrumentDialog::FUN_14100c1e0()
{
    UIDialog::vfunc_67();
}

// @0x14100c200
void UIPlayInstrumentDialog::FUN_14100c200(int nPage)
{
    if (nPage == 0)
    {
        FUN_140c8dac0()->FUN_140d07260(true);
        FUN_140c8dac0()->FUN_140d08600();
        FUN_14100e9a0(0);
    }
    else if (nPage == 1)
    {
        FUN_140c8dac0()->FUN_140d07260(false);
        for (int i = 0; i < 3; i++)
            FUN_14100ca90(i, MS2Ptr<CItem>(0));
        FUN_14100e9a0(1);
    }
}

// @0x14100c2c0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::FUN_14100c2c0()
{
    Unk_PiPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (!m_spScorePage)
        return;
    {
        int nExp = pPlayer->FUN_141662750(2);
        int nLevel = pPlayer->FUN_1416627d0(2);
        CStringW strProgress(L"");
        float fProgress = 0.0f;
        CStringW strGrade(L"");
        if (nLevel == 1)
            strGrade = FUN_14028b8e0(CStringW(L"s_play_instrument_grade_Lv1"));
        else if (nLevel == 2)
            strGrade = FUN_14028b8e0(CStringW(L"s_play_instrument_grade_Lv2"));
        else if (nLevel == 3)
            strGrade = FUN_14028b8e0(CStringW(L"s_play_instrument_grade_Lv3"));
        else if (nLevel == 4)
            strGrade = FUN_14028b8e0(CStringW(L"s_play_instrument_grade_Lv4"));
        if (nLevel == 4)
        {
            strProgress = L"MAX";
            fProgress = 1.0f;
        }
        else
        {
            int nStart = FUN_14066b310(FUN_1409670c0(), 2, nLevel);
            int nNext = nLevel + 1;
            int nEnd = FUN_14066b310(FUN_1409670c0(), 2, nNext);
            int nNeed = nEnd - nStart;
            int nHave = nExp - nStart;
            fProgress = (float)nHave / (float)nNeed;
            strProgress = FUN_14083dc40(L"{0} / {1}", nHave, nNeed);
        }
        m_spScorePage->Invoke("SetMasteryExp", CStringW(strProgress), fProgress, CStringW(strGrade));
    }
}

// @0x14100c750
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
int UIPlayInstrumentDialog::FUN_14100c750()
{
    bool bEmpty = true;
    m_nCurrent = 0;
    for (int i = 0; i < 3; i++)
    {
        if (m_spScores[i].get() != 0)
        {
            m_nCurrent = i;
            bEmpty = false;
            break;
        }
    }
    if (bEmpty)
    {
        FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_play_instrument_ui_need_score")), 0, 0, CStringW(L""));
        return 0;
    }
    m_bStop = 0;
    return FUN_14100f2e0();
}

// @0x14100c890
int UIPlayInstrumentDialog::FUN_14100c890()
{
    if (m_spTab == 0)
        return -1;
    return m_spTab->FUN_1422e3210();
}

// @0x14100c8f0
bool UIPlayInstrumentDialog::FUN_14100c8f0()
{
    if (m_nMode == 1)
        return true;
    return false;
}

// @0x14100c910
void UIPlayInstrumentDialog::FUN_14100c910(MS2Ptr<CItem> spItem)
{
    if (!FUN_14100c8f0())
        return;
    for (int i = 0; i < 3; i++)
    {
        if (m_spScores[i] == spItem.get())
            return;
    }
    int nSlot = 0;
    int nCount = 1;
    if (m_nKind == 0)
        nCount = m_nSlotCount;
    int nLimit = (std::min)(3, nCount);
    for (int i = 0; i < nLimit; i++)
    {
        if (m_spScores[i] == 0)
        {
            nSlot = i;
            break;
        }
    }
    FUN_14100ca90(nSlot, MS2Ptr<CItem>(spItem));
}

// @0x14100ca90
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::FUN_14100ca90(int nIndex, MS2Ptr<CItem> spItem)
{
    if (FUN_140a467d0(&m_30))
        return;
    if (!FUN_14100c8f0())
        return;
    if (nIndex >= 3)
        return;
    if (nIndex >= m_nSlotCount)
        return;
    if (spItem.get() != 0)
    {
        if (spItem->FUN_140527340() < 1)
            return;
        if (!spItem->FUN_140527840()->FUN_14053cd10())
            return;
        if (spItem->FUN_140525730())
            return;
        if (!spItem->FUN_140528980())
            return;
    }
    m_spScores[nIndex] = spItem;
    if (m_spScores[nIndex].get() == 0)
    {
        m_30->FUN_1409ba0d0("OnSetScore", nIndex + 1, 0);
        return;
    }
    ASSlot slot(2);
    if (slot.FUN_1409c3860(spItem.get(), FUN_1403ed2d0()->FUN_141bd0cc0(), 0x415))
    {
        CStringW strTitle = m_spScores[nIndex]->FUN_1405296c0();
        CStringW strWriter = m_spScores[nIndex]->FUN_140529890();
        CStringW strInstrument = m_spScores[nIndex]->FUN_140529aa0();
        int nDuration = m_spScores[nIndex]->FUN_1405299a0();
        CStringW strWriterText;
        if (strWriter.GetLength() > 0)
            strWriterText = FUN_1405c2690(CStringW(L"s_play_instrument_ui_score_info_writer"), strWriter);
        int nMin, nSec, nCenti;
        FUN_141b706a0((int)((float)nDuration / 1000.0f) * 1000, nMin, nSec, nCenti);
        CStringW strTime = FUN_14083dc40(FUN_14028b8e0(CStringW(L"s_writemusic_text_playtimer_cur")), nMin, nSec);
        slot.FUN_1407cbb20("title", FUN_1405c2690(CStringW(L"s_play_instrument_ui_score_info_title"), strTitle));
        slot.FUN_1407cbb20("writer", CStringW(strWriterText));
        slot.FUN_1407cbb20("recommendInstrument", FUN_1405c2690(CStringW(L"s_play_instrument_ui_score_info_instrument"), strInstrument));
        slot.FUN_1407cbb20("playTime", CStringW(strTime));
        slot.FUN_1407cbb20("itemGUID", FUN_141b71910(m_spScores[nIndex]->FUN_140526a50()));
        m_30->Invoke("OnSetScore", nIndex + 1, slot.FUN_1422bb870());
    }
}

// @0x14100d260
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::FUN_14100d260(int nStart, int nEnd)
{
    m_nStartTick = nStart;
    m_nEndTick = nEnd;
    FUN_14100e9a0(3);
    int nLimit = (std::min)(3, m_nSlotCount);
    if (m_nCurrent < nLimit || m_nCurrent >= 0)
    {
        if (m_spScorePage.get())
            m_spScorePage->Invoke("setPlaying", m_nCurrent + 1, true);
        if (m_spFold.get() && m_spScores[m_nCurrent].get())
        {
            CStringW strText;
            if (m_nKind == 0)
                strText = FUN_1405c2690(CStringW(L"s_play_instrument_ui_unfold_solo_text"), m_spScores[m_nCurrent]->FUN_1405296c0());
            else
                strText = FUN_1405c2690(CStringW(L"s_play_instrument_ui_unfold_ensemble_text"), m_spScores[m_nCurrent]->FUN_1405296c0());
            m_spFold->FUN_1422c4cd0(strText);
        }
    }
}

// @0x14100d600
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::FUN_14100d600()
{
    m_nStartTick = 0;
    m_nEndTick = 0;
    FUN_14100e9a0(1);
    int nLimit = (std::min)(3, m_nSlotCount);
    if (m_nCurrent < nLimit || m_nCurrent >= 0)
    {
        if (m_spScorePage.get())
            m_spScorePage->Invoke("setPlaying", m_nCurrent + 1, false);
    }
    if (m_spFold.get())
        m_spFold->FUN_1422c4cd0(CStringW(L""));
    m_nCurrent++;
    bool bFound = false;
    while (true)
    {
        if (m_nCurrent >= nLimit || m_nCurrent < 0)
            break;
        if (m_spScores[m_nCurrent] == 0)
        {
            m_nCurrent++;
            continue;
        }
        bFound = true;
        break;
    }
    if (!m_bStop && bFound)
        FUN_14100f2e0();
    else
    {
        for (int i = 0; i < 3; i++)
            FUN_14100ca90(i, MS2Ptr<CItem>(m_spScores[i]));
        m_nCurrent = 0;
    }
}

// @0x14100d8c0
bool UIPlayInstrumentDialog::FUN_14100d8c0()
{
    for (unsigned i = 0; i < 3; i++)
    {
        if (m_spScores[i].get() != 0)
            return true;
    }
    return false;
}

// @0x14100d920
void UIPlayInstrumentDialog::FUN_14100d920()
{
    if (m_nMode != 1)
        return;
    if (m_nAutoPlay == 0)
        return;
    if (m_nEndTick != 0)
        return;
    if (m_nKind == 1)
        return;
    if (FUN_140c8dac0()->FUN_140d07350())
        return;
    if (FUN_140c8dac0()->FUN_140d07330())
        return;
    if (FUN_140c8dac0()->FUN_140d07370())
        return;
    if (FUN_140c8dac0()->FUN_140d071b0() == 0)
        return;
    m_nAutoPlay = FUN_14100c750();
}

// @0x14100d9f0
int UIPlayInstrumentDialog::FUN_14100d9f0()
{
    return m_nAutoPlay;
}

// @0x14100da10
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::FUN_14100da10()
{
    if (m_spScorePage == 0)
        return;
    if (m_nEndTick != 0 && m_nStartTick != 0 && m_nMode == 3)
    {
        MS2Ptr<ASTextField> spTime = m_spScorePage->FUN_1409b4620("m_timeText");
        if (spTime == 0)
            return;
        int nElapsed = 0;
        if (m_nStartTick < FUN_140869420())
        {
            nElapsed = FUN_140869420();
            nElapsed = nElapsed - m_nStartTick;
        }
        int nTotal = m_nEndTick - m_nStartTick;
        int nMin, nSec, nCenti;
        FUN_141b706a0(nElapsed, nMin, nSec, nCenti);
        CStringW strCur = FUN_14083dc40(FUN_14028b8e0(CStringW(L"s_writemusic_text_playtimer_cur")), nMin, nSec);
        int nTotalMin, nTotalSec, nTotalCenti;
        FUN_141b706a0(nTotal, nTotalMin, nTotalSec, nTotalCenti);
        CStringW strTotal = FUN_14083dc40(FUN_14028b8e0(CStringW(L"s_writemusic_text_playtimer_total")), nTotalMin, nTotalSec);
        CStringW strText = FUN_140656190(L"{0} {1}", strCur, strTotal);
        spTime->FUN_1422c4cd0(strText);
        if ((m_nCurrent < 3 || m_nCurrent >= 0) && m_spFold.get() && m_spScores[m_nCurrent].get())
        {
            CStringW strScore;
            if (m_nKind == 0)
                strScore = FUN_1405c2690(CStringW(L"s_play_instrument_ui_unfold_solo_text"), m_spScores[m_nCurrent]->FUN_1405296c0());
            else
                strScore = FUN_1405c2690(CStringW(L"s_play_instrument_ui_unfold_ensemble_text"), m_spScores[m_nCurrent]->FUN_1405296c0());
            CStringW strFold = FUN_140656190(L"{0} {1}", strText, strScore);
            m_spFold->FUN_1422c4cd0(strFold);
        }
    }
}

static const int s_nOctaveDown = 100;                                       // 0x142e9cd78
static const int s_nOctaveUp = 101;                                         // 0x142e9cd7c

// @0x14100e060
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::FUN_14100e060()
{
    m_octaveKeys.clear();
    m_keyButtons.clear();
    int aKeys[24] = {0x2c, 0x1f, 0x2d, 0x20, 0x2e, 0x2f, 0x22, 0x30, 0x23, 0x31, 0x24, 0x32,
                     0x15, 8, 0x16, 9, 0x17, 0x18, 0xb, 0x19, 0xc, 0x1a, 0xd, 0x1b};
    for (int i = 0; i < 24; i++)
    {
        int nNo = i + 1;
        CString strName = FUN_1402bb1c0("m_key{0}", &nNo);
        MS2Ptr<Unk_140acd6e0> spButton = static_cast<Unk_PiClip*>(m_spPlayPage.operator->())->FUN_140acce30(strName);
        CStringW strKey = FUN_1409331f0()->FUN_14142d220(aKeys[i]);
        spButton->FUN_1422cdfb0(strKey);
        FUN_14100e880(aKeys[i], MS2Ptr<Unk_140acd6e0>(spButton), i);
    }
    m_octaveKeys.push_back(std::make_pair(0x3b, 1));
    m_octaveKeys.push_back(std::make_pair(0x3c, 2));
    m_octaveKeys.push_back(std::make_pair(0x3d, 3));
    m_octaveKeys.push_back(std::make_pair(0x3e, 4));
    m_octaveKeys.push_back(std::make_pair(0x3f, 5));
    m_octaveKeys.push_back(std::make_pair(0x40, 6));
    m_octaveKeys.push_back(std::make_pair(0x41, 7));
    m_octaveKeys.push_back(std::make_pair(0x42, 8));
    m_octaveKeys.push_back(std::make_pair(0x2a, s_nOctaveDown));
    m_octaveKeys.push_back(std::make_pair(0x36, s_nOctaveUp));
    size_t nIndex = 0;
    while (nIndex < m_octaveKeys.size())
    {
        std::pair<int, int>& key = m_octaveKeys.at(nIndex);
        if (key.second < 9)
        {
            CString strName = FUN_1402bb1c0("m_octave{0}", &key.second);
            MS2Ptr<ASDisplayObject> spControl = static_cast<Unk_PiClip*>(m_spPlayPage.operator->())->FUN_140acce30(strName);
            if (spControl == 0)
            {
                nIndex++;
                continue;
            }
            MS2Ptr<ASTextField> spLabel = spControl->FUN_1409b4620("textField");
            if (spLabel == 0)
            {
                nIndex++;
                continue;
            }
            CStringW strKey = FUN_1409331f0()->FUN_14142d580(key.first);
            spLabel->FUN_1422c4cd0(strKey);
        }
        else if (key.second == 100)
        {
            CStringW strKey = FUN_1409331f0()->FUN_14142d580(key.first);
            m_spLowerOctave->FUN_1422cdfb0(strKey);
        }
        else if (key.second == 101)
        {
            CStringW strKey = FUN_1409331f0()->FUN_14142d580(key.first);
            m_spUpperOctave->FUN_1422cdfb0(strKey);
        }
        nIndex++;
    }
}

// @0x14100e880
void UIPlayInstrumentDialog::FUN_14100e880(int nKey, MS2Ptr<Unk_140acd6e0> spButton, int nIndex)
{
    m_keyButtons[nKey] = std::make_pair(nIndex, spButton);
}

// @0x14100e910
void UIPlayInstrumentDialog::FUN_14100e910()
{
    if (m_nOctave < 1)
        m_nOctave = 1;
    if (m_nOctave > 7)
        m_nOctave = 7;
    m_spPlayPage->Invoke("setOctave", m_nOctave);
}

// @0x14100e9a0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIPlayInstrumentDialog::FUN_14100e9a0(int nMode)
{
    if (!m_spScorePage)
        return;
    if (nMode != 0)
    {
        MS2Ptr<Unk_140acd6e0> spStop = static_cast<Unk_PiClip*>(m_spScorePage.operator->())->FUN_140acce30("m_stop");
        MS2Ptr<Unk_140acd6e0> spPlay = static_cast<Unk_PiClip*>(m_spScorePage.operator->())->FUN_140acce30("m_play");
        MS2Ptr<ASTextField> spTime = m_spScorePage->FUN_1409b4620("m_timeText");
        if (spStop == 0 || spPlay == 0)
            return;
        if (nMode == 1)
        {
            if (m_30.get())
                m_30->Invoke("UnLockComponent");
        }
        else
        {
            if (m_30.get())
                m_30->Invoke("LockComponent");
        }
        m_nMode = nMode;
        if (nMode == 1)
        {
            spStop->vfunc_3(0);
            spPlay->vfunc_3(1);
            spTime->vfunc_3(0);
            if (m_nKind == 0)
                spPlay->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_play_instrument_ui_button_play_solo")));
            else if (m_nKind == 1)
            {
                if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
                    return;
                if (!FUN_14162ab60(FUN_1409670d0()))
                    spPlay->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_play_instrument_ui_button_ready_ensemble")));
                else
                    spPlay->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_play_instrument_ui_button_play_ensemble")));
            }
        }
        else if (nMode == 2)
        {
            spStop->vfunc_3(1);
            spPlay->vfunc_3(0);
            spTime->vfunc_3(0);
            if (m_nKind == 0)
                spStop->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_play_instrument_ui_button_stop_solo")));
            else if (m_nKind == 1)
                spStop->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_play_instrument_ui_button_stop_ready_ensemble")));
        }
        else if (nMode == 3)
        {
            spStop->vfunc_3(1);
            spPlay->vfunc_3(0);
            spTime->vfunc_3(1);
            if (m_nKind == 0)
                spStop->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_play_instrument_ui_button_stop_solo")));
            else if (m_nKind == 1)
                spStop->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_play_instrument_ui_button_stop_ensemble")));
        }
        FUN_14100f1f0();
    }
}

// @0x14100f1f0
void UIPlayInstrumentDialog::FUN_14100f1f0()
{
    if (!m_spScorePage)
        return;
    {
        int nCount = 1;
        if (m_nKind == 0)
            nCount = m_nSlotCount;
        for (int i = nCount; i < 3; i++)
            FUN_14100ca90(i, MS2Ptr<CItem>(0));
        m_spScorePage->Invoke("setSlotCount", nCount);
    }
}

// @0x14100f2e0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
unsigned char UIPlayInstrumentDialog::FUN_14100f2e0()
{
    int nLimit = (std::min)(3, m_nSlotCount);
    if (m_nCurrent < 0 || m_nCurrent >= nLimit)
        return 0;
    if (m_spScores[m_nCurrent] == 0)
        return 0;
    unsigned char nResult = 0;
    if (m_nKind == 0)
    {
        __int64 nUid = m_spScores[m_nCurrent]->FUN_140526a50();
        nResult = FUN_140c8dac0()->FUN_140d07960(nUid);
    }
    else
    {
        __int64 nUid = m_spScores[m_nCurrent]->FUN_140526a50();
        nResult = FUN_140c8dac0()->FUN_140d07f00(nUid);
    }
    if (nResult != 0)
        FUN_14100e9a0(2);
    return nResult;
}

// @0x141014b30
int UIPlayInstrumentDialog::vfunc_48()
{
    return 0x4eec;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cab1a0-0x142cab2e0 .text$yd
