// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Inventory storage.
// MS2-UNIT: client\ms2\inventory.cpp
// MS2-RANGE: 0x140a5c650-0x140a6d890 .text$mn
// MS2-RANGE: 0x1400c4100-0x1400c45a0 .text$di
// MS2-RANGE: 0x142c9f520-0x142c9f710 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400c4320 ; unique
// MS2-PIN: ??__Es_condition2@@YAXXZ 0x1400c4550 ; unique
// MS2-PIN: ?FUN_140a5c650@@YA_NV?$MS2Ptr@VCItem@@@@0@Z 0x140a5c650 ; unique
// MS2-PIN: ??0Unk_Inventory@@QEAA@XZ 0x140a5c7a0 ; unique
// MS2-PIN: ??1Unk_Inventory@@QEAA@XZ 0x140a5c850 ; unique
// MS2-PIN: ?FUN_140a5ca60@Unk_Inventory@@QEAAXH@Z 0x140a5ca60 ; unique
// MS2-PIN: ?FUN_140a5cdc0@Unk_Inventory@@QEAA_NI@Z 0x140a5cdc0 ; unique
// MS2-PIN: ?FUN_140a5d680@Unk_Inventory@@QEAA?AV?$MS2Ptr@VCItem@@@@_J@Z 0x140a5d680 ; unique
// MS2-PIN: ?FUN_140a5d9a0@Unk_Inventory@@QEAA?AV?$MS2Ptr@VCItem@@@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@Z 0x140a5d9a0 ; unique
// MS2-PIN: ?FUN_140a5f780@Unk_Inventory@@QEAAXHH@Z 0x140a5f780 ; unique
// MS2-PIN: ?FUN_140a603e0@Unk_Inventory@@QEAAHHHH@Z 0x140a603e0 ; unique
// MS2-PIN: ?FUN_140a60790@Unk_Inventory@@QEAAXAEAV?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@@Z 0x140a60790 ; unique
// MS2-PIN: ?FUN_140a617f0@Unk_Inventory@@QEAAHV?$MS2Ptr@VCItem@@@@@Z 0x140a617f0 ; unique
// MS2-PIN: ?FUN_140a621c0@Unk_Inventory@@QEAAH_JHH@Z 0x140a621c0 ; unique
// MS2-PIN: ?FUN_140a63900@Unk_Inventory@@QEAAHPEAVCItem@@H@Z 0x140a63900 ; unique
// MS2-PIN: ?FUN_140a661e0@Unk_Inventory@@QEAAHPEAVCItem@@@Z 0x140a661e0 ; unique
// MS2-PIN: ?FUN_140a66c00@Unk_Inventory@@QEAAXXZ 0x140a66c00 ; unique
// MS2-PIN: ?FUN_140a66f20@Unk_Inventory@@QEAA_JXZ 0x140a66f20 ; unique
// MS2-PIN: ?FUN_140a66f40@Unk_Inventory@@QEAAX_J@Z 0x140a66f40 ; unique
// MS2-PIN: ?FUN_140a66fa0@Unk_Inventory@@QEAAXH@Z 0x140a66fa0 ; unique
// MS2-PIN: ?FUN_140a67000@Unk_Inventory@@QEAAHXZ 0x140a67000 ; unique
// MS2-PIN: ?FUN_140a673e0@Unk_Inventory@@QEAAXV?$MS2Ptr@VCItem@@@@@Z 0x140a673e0 ; unique
// MS2-PIN: ?FUN_140a674c0@Unk_Inventory@@QEAAXV?$MS2Ptr@VCItem@@@@@Z 0x140a674c0 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140a676f0 ; unique
// MS2-PIN: ??$?0AEAPEAV?$MS2Ptr@VCItem@@@@AEAPEAV0@$0A@@?$pair@PEAV?$MS2Ptr@VCItem@@@@PEAV1@@std@@QEAA@AEAPEAV?$MS2Ptr@VCItem@@@@0@Z 0x140a67720 ; unique
// MS2-PIN: ??$_Adl_verify_range1@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x140a67770 ; unique
// MS2-PIN: ??$_Adl_verify_range@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@0@0@Z 0x140a67780 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@YAXPEAV?$MS2Ptr@VCItem@@@@0AEAV?$allocator@V?$MS2Ptr@VCItem@@@@@0@U?$integral_constant@_N$0A@@0@@Z 0x140a677c0 ; unique
// MS2-PIN: ??$_Destroy_range@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@YAXPEAV?$MS2Ptr@VCItem@@@@0AEAV?$allocator@V?$MS2Ptr@VCItem@@@@@0@@Z 0x140a67820 ; unique
// MS2-PIN: ??$_Emplace_back@AEAV?$MS2Ptr@VCItem@@@@@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAAXAEAV?$MS2Ptr@VCItem@@@@@Z 0x140a67870 ; unique
// MS2-PIN: ??$_Emplace_back@V?$MS2Ptr@VCItem@@@@@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAAX$$QEAV?$MS2Ptr@VCItem@@@@@Z 0x140a678d0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$MS2Ptr@VCItem@@@@@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEAAXAEBV?$MS2Ptr@VCItem@@@@@Z 0x140a67930 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VCItem@@@@@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCItem@@@@QEAV2@AEBV2@@Z 0x140a679f0 ; unique
// MS2-PIN: ??$_Get_unwrapped@V?$MS2Ptr@VCItem@@@@@std@@YAPEAV?$MS2Ptr@VCItem@@@@QEAV1@@Z 0x140a67c40 ; unique
// MS2-PIN: ??$_Get_unwrapped@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@$0A@@std@@YAPEAV?$MS2Ptr@VCItem@@@@AEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@0@@Z 0x140a67c50 ; unique
// MS2-PIN: ??$_Get_unwrapped_n@V?$MS2Ptr@VCItem@@@@_J$0A@@std@@YAPEAV?$MS2Ptr@VCItem@@@@QEAV1@_J@Z 0x140a67c70 ; unique
// MS2-PIN: ??$_Guess_median_unchecked@PEAV?$MS2Ptr@VCItem@@@@P6A_NV1@0@Z@std@@YAXPEAV?$MS2Ptr@VCItem@@@@00P6A_NV1@1@Z@Z 0x140a67c80 ; unique
// MS2-PIN: ??$_Idl_distance1@PEAV?$MS2Ptr@VCItem@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VCItem@@@@0Urandom_access_iterator_tag@0@@Z 0x140a67dd0 ; unique
// MS2-PIN: ??$_Idl_distance@PEAV?$MS2Ptr@VCItem@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VCItem@@@@0@Z 0x140a67e00 ; unique
// MS2-PIN: ??$_Insertion_sort_unchecked@PEAV?$MS2Ptr@VCItem@@@@P6A_NV1@0@Z@std@@YAPEAV?$MS2Ptr@VCItem@@@@PEAV1@QEAV1@P6A_NV1@2@Z@Z 0x140a67e30 ; unique
// MS2-PIN: ??$_Make_heap_unchecked@PEAV?$MS2Ptr@VCItem@@@@P6A_NV1@0@Z@std@@YAXPEAV?$MS2Ptr@VCItem@@@@0P6A_NV1@1@Z@Z 0x140a68050 ; unique
// MS2-PIN: ??$_Med3_unchecked@PEAV?$MS2Ptr@VCItem@@@@P6A_NV1@0@Z@std@@YAXPEAV?$MS2Ptr@VCItem@@@@00P6A_NV1@1@Z@Z 0x140a68110 ; unique
// MS2-PIN: ??$_Move_backward_unchecked1@PEAV?$MS2Ptr@VCItem@@@@PEAV1@@std@@YAPEAV?$MS2Ptr@VCItem@@@@PEAV1@00U_General_ptr_iterator_tag@0@@Z 0x140a682e0 ; unique
// MS2-PIN: ??$_Move_backward_unchecked@PEAV?$MS2Ptr@VCItem@@@@PEAV1@@std@@YAPEAV?$MS2Ptr@VCItem@@@@PEAV1@00@Z 0x140a68350 ; unique
// MS2-PIN: ??$_Partition_by_median_guess_unchecked@PEAV?$MS2Ptr@VCItem@@@@P6A_NV1@0@Z@std@@YA?AU?$pair@PEAV?$MS2Ptr@VCItem@@@@PEAV1@@0@PEAV?$MS2Ptr@VCItem@@@@0P6A_NV2@1@Z@Z 0x140a683a0 ; unique
// MS2-PIN: ??$_Pass_fn@P6A_NV?$MS2Ptr@VCItem@@@@0@Z$0A@@std@@YAP6A_NV?$MS2Ptr@VCItem@@@@0@ZP6A_N00@Z@Z 0x140a68ac0 ; unique
// MS2-PIN: ??$_Pop_heap_hole_by_index@PEAV?$MS2Ptr@VCItem@@@@V1@P6A_NV1@0@Z@std@@YAXPEAV?$MS2Ptr@VCItem@@@@_J1$$QEAV1@P6A_NV1@3@Z@Z 0x140a68ad0 ; unique
// MS2-PIN: ??$_Pop_heap_hole_unchecked@PEAV?$MS2Ptr@VCItem@@@@V1@P6A_NV1@0@Z@std@@YAXPEAV?$MS2Ptr@VCItem@@@@00$$QEAV1@P6A_NV1@2@Z@Z 0x140a68ce0 ; unique
// MS2-PIN: ??$_Pop_heap_unchecked@PEAV?$MS2Ptr@VCItem@@@@P6A_NV1@0@Z@std@@YAXPEAV?$MS2Ptr@VCItem@@@@0P6A_NV1@1@Z@Z 0x140a68d50 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@V?$MS2Ptr@VCItem@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VCItem@@@@0@Z 0x140a68df0 ; unique
// MS2-PIN: ??$_Ptr_move_cat@V?$MS2Ptr@VCItem@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VCItem@@@@0@Z 0x140a68e20 ; unique
// MS2-PIN: ??$_Push_heap_by_index@PEAV?$MS2Ptr@VCItem@@@@V1@P6A_NV1@0@Z@std@@YAXPEAV?$MS2Ptr@VCItem@@@@_J1$$QEAV1@P6A_NV1@3@Z@Z 0x140a68e50 ; unique
// MS2-PIN: ??$_Seek_wrapped@V?$MS2Ptr@VCItem@@@@@std@@YAXAEAPEAV?$MS2Ptr@VCItem@@@@QEAV1@@Z 0x140a68fb0 ; unique
// MS2-PIN: ??$_Sort_heap_unchecked@PEAV?$MS2Ptr@VCItem@@@@P6A_NV1@0@Z@std@@YAXPEAV?$MS2Ptr@VCItem@@@@0P6A_NV1@1@Z@Z 0x140a68fd0 ; unique
// MS2-PIN: ??$_Sort_unchecked@PEAV?$MS2Ptr@VCItem@@@@P6A_NV1@0@Z@std@@YAXPEAV?$MS2Ptr@VCItem@@@@0_JP6A_NV1@2@Z@Z 0x140a69030 ; unique
// MS2-PIN: ??$_Unfancy@V?$MS2Ptr@VCItem@@@@@std@@YAPEAV?$MS2Ptr@VCItem@@@@PEAV1@@Z 0x140a69180 ; unique
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$MS2Ptr@VCItem@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCItem@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VCItem@@@@@0@@Z 0x140a69190 ; unique
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAV?$MS2Ptr@VCItem@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCItem@@@@PEAV1@QEAV1@1AEAV?$allocator@V?$MS2Ptr@VCItem@@@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140a69260 ; unique
// MS2-PIN: ??$_Uninitialized_move@PEAV?$MS2Ptr@VCItem@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCItem@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VCItem@@@@@0@@Z 0x140a692f0 ; unique
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAV?$MS2Ptr@VCItem@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCItem@@@@PEAV1@QEAV1@1AEAV?$allocator@V?$MS2Ptr@VCItem@@@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140a693c0 ; unique
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@0@AEAV10@@Z 0x140a69450 ; unique
// MS2-PIN: ??$construct@V?$MS2Ptr@VCItem@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCItem@@@@@1@QEAV?$MS2Ptr@VCItem@@@@AEAV3@@Z 0x140a69460 ; unique
// MS2-PIN: ??$construct@V?$MS2Ptr@VCItem@@@@AEBV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCItem@@@@@1@QEAV?$MS2Ptr@VCItem@@@@AEBV3@@Z 0x140a694b0 ; unique
// MS2-PIN: ??$construct@V?$MS2Ptr@VCItem@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCItem@@@@@1@QEAV?$MS2Ptr@VCItem@@@@$$QEAV3@@Z 0x140a69500 ; unique
// MS2-PIN: ??$destroy@V?$MS2Ptr@VCItem@@@@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCItem@@@@@1@QEAV?$MS2Ptr@VCItem@@@@@Z 0x140a69550 ; unique
// MS2-PIN: ??$emplace_back@AEBV?$MS2Ptr@VCItem@@@@@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VCItem@@@@@Z 0x140a69570 ; unique
// MS2-PIN: ??$forward@AEAPEAV?$MS2Ptr@VCItem@@@@@std@@YAAEAPEAV?$MS2Ptr@VCItem@@@@AEAPEAV1@@Z 0x140a695e0 ; unique
// MS2-PIN: ??$forward@AEAV?$MS2Ptr@VCItem@@@@@std@@YAAEAV?$MS2Ptr@VCItem@@@@AEAV1@@Z 0x140a695f0 ; unique
// MS2-PIN: ??$forward@AEBV?$MS2Ptr@VCItem@@@@@std@@YAAEBV?$MS2Ptr@VCItem@@@@AEBV1@@Z 0x140a69600 ; unique
// MS2-PIN: ??$forward@V?$MS2Ptr@VCItem@@@@@std@@YA$$QEAV?$MS2Ptr@VCItem@@@@AEAV1@@Z 0x140a69610 ; unique
// MS2-PIN: ??$iter_swap@PEAV?$MS2Ptr@VCItem@@@@PEAV1@@std@@YAXPEAV?$MS2Ptr@VCItem@@@@0@Z 0x140a69620 ; unique
// MS2-PIN: ??$move@AEAV?$MS2Ptr@VCItem@@@@@std@@YA$$QEAV?$MS2Ptr@VCItem@@@@AEAV1@@Z 0x140a69650 ; unique
// MS2-PIN: ??$sort@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@P6A_NV?$MS2Ptr@VCItem@@@@0@Z@std@@YAXV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@0@0P6A_NV?$MS2Ptr@VCItem@@@@1@Z@Z 0x140a69660 ; unique
// MS2-PIN: ??$swap@V?$MS2Ptr@VCItem@@@@X@std@@YAXAEAV?$MS2Ptr@VCItem@@@@0@Z 0x140a696e0 ; unique
// MS2-PIN: ??0?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAA@I@Z 0x140a69750 ; unique
// MS2-PIN: ??0?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAA@IMMMI@Z 0x140a697b0 ; unique
// MS2-PIN: ??0?$CRBMap@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAA@_K@Z 0x140a698a0 ; unique
// MS2-PIN: ??0?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@IEAA@_K@Z 0x140a698d0 ; unique
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAA@PEAV?$MS2Ptr@VCItem@@@@AEAV?$allocator@V?$MS2Ptr@VCItem@@@@@1@@Z 0x140a69930 ; unique
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEAA@XZ 0x140a69970 ; unique
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEAA@PEAV?$MS2Ptr@VCItem@@@@PEBU_Container_base0@1@@Z 0x140a699a0 ; unique
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEAA@PEAV?$MS2Ptr@VCItem@@@@PEBU_Container_base0@1@@Z 0x140a699e0 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAA@XZ 0x140a69a20 ; unique
// MS2-PIN: ??0?$allocator@V?$MS2Ptr@VCItem@@@@@std@@QEAA@XZ 0x140a69a60 ; unique
// MS2-PIN: ??0?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAA@XZ 0x140a69a70 ; unique
// MS2-PIN: ??0Unk_InventoryUsePacket@@QEAA@XZ 0x140a69aa0 ; unique
// MS2-PIN: ??0CNode@?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAA@AEBV?$MS2Ptr@VCItem@@@@@Z 0x140a69ae0 ; unique
// MS2-PIN: ??0Unk_InventoryUnequipPacket@@QEAA@XZ 0x140a69c20 ; unique
// MS2-PIN: ??0Unk_InventoryEquipPacket@@QEAA@XZ 0x140a69c40 ; unique
// MS2-PIN: ??0TOutBindingParam@ItemUtilTransfer@@QEAA@XZ 0x140a69c70 ; unique
// MS2-PIN: ??1?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAA@XZ 0x140a69cd0 ; unique
// MS2-PIN: ??1?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAA@XZ 0x140a69cf0 ; unique
// MS2-PIN: ??1?$CRBMap@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAA@XZ 0x140a69d20 ; unique
// MS2-PIN: ??1?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAA@XZ 0x140a69d40 ; unique
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAA@XZ 0x140a69d80 ; unique
// MS2-PIN: ??1?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAA@XZ 0x140a69dc0 ; unique
// MS2-PIN: ??1Unk_InventoryUsePacket@@QEAA@XZ 0x140a69df0 ; unique
// MS2-PIN: ??1CNode@?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAA@XZ 0x140a69e10 ; unique
// MS2-PIN: ??1CNode@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAA@XZ 0x140a69e30 ; unique
// MS2-PIN: ??1CNode@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAA@XZ 0x140a69e50 ; unique
// MS2-PIN: ??1CPair@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAA@XZ 0x140a69e70 ; unique
// MS2-PIN: ??1CPair@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@IEAA@XZ 0x140a69e90 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140a69ee0 ; unique
// MS2-PIN: ??A?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAAAEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140a69f20 ; unique
// MS2-PIN: ??_GCNode@?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAAPEAXI@Z 0x140a69f50 ; unique
// MS2-PIN: ??_GCNode@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAAPEAXI@Z 0x140a69f90 ; unique
// MS2-PIN: ??_GCNode@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAAPEAXI@Z 0x140a69fd0 ; unique
// MS2-PIN: ?AddTail@?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAAPEAU__POSITION@@AEBV?$MS2Ptr@VCItem@@@@@Z 0x140a6a050 ; unique
// MS2-PIN: ?FUN_140a6a0d0@Unk_InventoryAccount@@QEAA_NXZ 0x140a6a0d0 ; unique
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAAXXZ 0x140a6a170 ; unique
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAAXXZ 0x140a6a190 ; unique
// MS2-PIN: ?Find@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@IEBAPEAVCNode@12@_K@Z 0x140a6a1b0 ; unique
// MS2-PIN: ?FreeNode@?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@AEAAXPEAVCNode@12@@Z 0x140a6a3e0 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@AEAAXPEAVCNode@12@@Z 0x140a6a450 ; unique
// MS2-PIN: ?FreeNode@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x140a6a550 ; unique
// MS2-PIN: ?FreePlexes@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@AEAAXXZ 0x140a6a5f0 ; unique
// MS2-PIN: ?GetFreeNode@?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@AEAAXXZ 0x140a6a6c0 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEBAIXZ 0x140a6a7a0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140a6a810 ; unique
// MS2-PIN: ?FUN_140a6a830@@YAPEAVUnk_InventoryStateManager@@XZ 0x140a6a830 ; unique
// MS2-PIN: ?FUN_140a6a840@@YAPEAVUnk_InventoryListener@@XZ 0x140a6a840 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140a6a8a0 ; unique
// MS2-PIN: ?FUN_140a6aa40@Unk_InventoryArraySetting@@QEAAAEBV?$vector@HV?$allocator@H@std@@@std@@XZ 0x140a6aa40 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VCItem@@@@PEAU__POSITION@@@Z 0x140a6aaf0 ; unique
// MS2-PIN: ?InitHashTable@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAA_NI_N@Z 0x140a6ab50 ; unique
// MS2-PIN: ?IsLocked@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@AEBA_NXZ 0x140a6ada0 ; unique
// MS2-PIN: ?IsNil@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@AEBA_NPEAVCNode@12@@Z 0x140a6add0 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEBA_N_KAEAV?$MS2Ptr@VCItem@@@@@Z 0x140a6afc0 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140a6b010 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140a6b080 ; unique
// MS2-PIN: ?NewNode@?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@AEAAPEAVCNode@12@AEBV?$MS2Ptr@VCItem@@@@PEAV312@1@Z 0x140a6b0f0 ; unique
// MS2-PIN: ?PickSize@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@AEBAI_K@Z 0x140a6b620 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140a6b710 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAAXI@Z 0x140a6bf40 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlList@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAAXXZ 0x140a6c170 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAAXXZ 0x140a6c250 ; unique
// MS2-PIN: ?RemoveAll@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAAXXZ 0x140a6c360 ; unique
// MS2-PIN: ?RemovePostOrder@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x140a6c710 ; unique
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@QEAAXMMM_N@Z 0x140a6ca10 ; unique
// MS2-PIN: ?Successor@?$CRBTree@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140a6cac0 ; unique
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@W4Unk_InventoryEquipSlot@@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@W4Unk_InventoryEquipSlot@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@4@@ATL@@AEAAXXZ 0x140a6cf30 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEBA_K_K@Z 0x140a6d010 ; unique
// MS2-PIN: ?_Change_array@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEAAXQEAV?$MS2Ptr@VCItem@@@@_K1@Z 0x140a6d0a0 ; unique
// MS2-PIN: ?_Destroy@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCItem@@@@0@Z 0x140a6d1b0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@2@XZ 0x140a6d1f0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VCItem@@@@@2@XZ 0x140a6d210 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VCItem@@@@@2@XZ 0x140a6d220 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@2@XZ 0x140a6d230 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VCItem@@@@@2@XZ 0x140a6d240 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VCItem@@@@@2@XZ 0x140a6d260 ; unique
// MS2-PIN: ?_Has_unused_capacity@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEBA_NXZ 0x140a6d280 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCItem@@@@XZ 0x140a6d2d0 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VCItem@@@@XZ 0x140a6d2f0 ; unique
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCItem@@@@XZ 0x140a6d310 ; unique
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCItem@@@@XZ 0x140a6d330 ; unique
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEAAXXZ 0x140a6d350 ; unique
// MS2-PIN: ?_Orphan_range@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEBAXPEAV?$MS2Ptr@VCItem@@@@0@Z 0x140a6d370 ; unique
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCItem@@@@XZ 0x140a6d380 ; unique
// MS2-PIN: ?_Tidy@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEAAXXZ 0x140a6d3a0 ; unique
// MS2-PIN: ?_Umove@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEAAPEAV?$MS2Ptr@VCItem@@@@PEAV3@00@Z 0x140a6d470 ; unique
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCItem@@@@00U?$integral_constant@_N$0A@@2@@Z 0x140a6d4b0 ; unique
// MS2-PIN: ?_Umove_if_noexcept@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCItem@@@@00@Z 0x140a6d4f0 ; unique
// MS2-PIN: ?_Unwrapped@?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@std@@QEBAPEAV?$MS2Ptr@VCItem@@@@XZ 0x140a6d550 ; unique
// MS2-PIN: ?_Xlength@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@CAXXZ 0x140a6d560 ; unique
// MS2-PIN: ?allocate@?$allocator@V?$MS2Ptr@VCItem@@@@@std@@QEAAPEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140a6d580 ; unique
// MS2-PIN: ?begin@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@2@XZ 0x140a6d5b0 ; unique
// MS2-PIN: ?capacity@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEBA_KXZ 0x140a6d610 ; unique
// MS2-PIN: ?deallocate@?$allocator@V?$MS2Ptr@VCItem@@@@@std@@QEAAXQEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140a6d650 ; unique
// MS2-PIN: ?end@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCItem@@@@@std@@@std@@@2@XZ 0x140a6d680 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@SA_KAEBV?$allocator@V?$MS2Ptr@VCItem@@@@@2@@Z 0x140a6d6e0 ; unique
// MS2-PIN: ?max_size@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEBA_KXZ 0x140a6d6f0 ; unique
// MS2-PIN: ?push_back@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VCItem@@@@@Z 0x140a6d740 ; unique
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142c9f5e0 ; unique
// MS2-PIN: ??__Fs_condition2@@YAXXZ 0x142c9f6f0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\inventory.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "inventory.h"
#include <algorithm>
#include <vector>
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/itemutiltransfer.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// First group precedes the common header's statics in the original object.
static CStringW s_useBindEquipItem = L"useBindEquipItem";
static CString s_chartSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
static CString s_warningBag = "system_notice_error_warningBag";
static CString s_warningClass = "system_notice_error_warningClass";
static CString s_warningGender = "system_notice_error_warningGender";
static CString s_warningLevel = "system_notice_error_warningLevel";
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill2 = "skill";
static CString s_stun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

int FUN_140a66510(int category);
int FUN_140a66750(unsigned category);
class Unk_InventoryFeature { public: bool FUN_14036d570(int feature); };
Unk_InventoryFeature* FUN_140166410();
class Unk_InventoryNames { public: CStringW FUN_141813300(unsigned category); };
Unk_InventoryNames* FUN_1401a9d70();
class Unk_InventoryListener {
public:
    virtual void vfunc_0() = 0;
    virtual void vfunc_1() = 0;
    virtual void vfunc_2(CItem*, int) = 0;
};
Unk_InventoryListener* FUN_140a6a840();
CItemData* FUN_140527840(CItem*);
int FUN_14053fd90(CItemData*);
int FUN_14053dc20(CItemData*);
bool FUN_14053cbc0(CItemData*);
bool FUN_14053cc80(CItemData*);
int FUN_140526100(CItem*);
int FUN_140525640(CItem*);
int FUN_140526c50(CItem*);
unsigned FUN_1405281e0(CItem*);
int FUN_140529640(CItem*);
bool FUN_1405277e0(CItem*, int);
MS2Ptr<CItemData> FUN_14053f870(int);
// Equipment slot record: FUN_1411dc7a0 returns the equipped item, FUN_1411dc7f0 its CItemData.
class Unk_InventoryEquipment { public: MS2Ptr<CItem> FUN_1411dc7a0(); CItemData* FUN_1411dc7f0(); };
// Constructor141763fa0 initializes the full request through item+40.
struct Unk_InventorySkillRequest {
    Unk_InventorySkillRequest(int, unsigned short);
    int skill;
    unsigned short level;
    unsigned __int64 tick;
    unsigned serial, unknown14;
    float origin[3], direction[3];
    unsigned unknown30, unknown34;
    bool remap, suppressDispatch, itemUse;
    __int64 item;
};
MS2_CHECK_SIZE(Unk_InventorySkillRequest, 0x48);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, remap, 0x38);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, itemUse, 0x3a);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, item, 0x40);
class Unk_InventorySkillLevel;
class Unk_InventorySkillTable { public: MS2Ptr<Unk_InventorySkillLevel> FUN_1407ee2f0(int, unsigned short); };
Unk_InventorySkillTable* FUN_1401958b0();
bool FUN_140804450(Unk_InventorySkillLevel*);
bool FUN_14053d270(CItemData*);
bool FUN_14053cb40(CItemData*);
int FUN_141769320(MS2Ptr<CItemData>);
class Unk_InventorySkills {
public: int FUN_141768fb0(int skill, unsigned short level);
    MS2Ptr<CSkillRecord> FUN_141765570(Unk_InventorySkillRequest&);
};
class Unk_InventoryPlayer : public PCBase {
public:
    int FUN_141662eb0(CItem*);
    void FUN_141526c80(int*, unsigned short*);
    MS2Ptr<Unk_InventoryEquipment> FUN_141655e80(int slot, int mode);
    MS2Ptr<Unk_InventoryEquipment> FUN_141655cf0(int slot);
    MS2Ptr<Unk_InventoryEquipment> FUN_141655c90(int slot);
    int FUN_14166ce30();
    int FUN_141658f30();
    int FUN_141658e60();
    int FUN_141654700();
    int FUN_141662de0();
    Unk_InventorySkills* FUN_141523bc0();
    Unk_Inventory::ItemPtr FUN_141655b80(__int64 id);
    __int64 FUN_141656a80();
};
class Unk_InventoryContext { public: Unk_InventoryPlayer* FUN_141bd0cc0(); };
Unk_InventoryContext* FUN_1403ed2d0();
bool FUN_140528e20(CItem*);
bool FUN_140528980(CItem*);
bool FUN_14053c710(CItemData*);
bool FUN_14053cf90(CItemData*);
int FUN_14053c620(CItemData*);
bool FUN_14053d460(CItemData*);
bool FUN_14053d2b0(CItemData*);
bool FUN_14053d2f0(CItemData*);
int FUN_140525e50(CItem*, int, int);
// Block-notice record returned through a hidden pointer by 0x140a2f620 and released by 0x1401cb250.
class Unk_InventoryStateManager;
struct Unk_InventoryBlockRef;
void FUN_1401cb250(Unk_InventoryBlockRef*);
struct Unk_InventoryBlockRef { void* unknown0; void* record; ~Unk_InventoryBlockRef() { FUN_1401cb250(this); } };
MS2_CHECK_SIZE(Unk_InventoryBlockRef, 0x10);
void* FUN_1401cb3d0(Unk_InventoryBlockRef*);
void FUN_140a2f620(Unk_InventoryStateManager*, Unk_InventoryBlockRef*, int);
Unk_InventoryStateManager* FUN_140a6a830();
void FUN_140a2ff20(Unk_InventoryBlockRef*, int, __int64);
extern CString DAT_143ab78e8;
int FUN_140527760(CItem*);
int FUN_14053c5c0(CItemData*);
bool FUN_14053c7c0(CItemData*);
int FUN_140525f10(CItem*);
int FUN_14052a7e0(Unk_Inventory::ItemPtr, Unk_Inventory::ItemPtr);
bool FUN_1406a5a50(Unk_Inventory::ItemPtr, const __int64*);
struct Unk_InventoryScopedLock {
    Unk_InventoryScopedLock(CLockCriticalSection&, int);
    ~Unk_InventoryScopedLock();
    void* lock;
};
MS2_CHECK_SIZE(Unk_InventoryScopedLock, 8);
struct Unk_InventoryStackIdentity {
    void* unknown[6];
    __int64 owner;
};
MS2_CHECK_SIZE(Unk_InventoryStackIdentity, 0x38); // accessed prefix only, never constructed
MS2_CHECK_OFFSET(Unk_InventoryStackIdentity, owner, 0x30);
Unk_InventoryStackIdentity* FUN_1405278d0(CItem*);
int FUN_140527a20(CItem*);
int FUN_14052a170(CItem*);
int FUN_140529070(CItem*);
unsigned short FUN_1405282d0(CItem*);

// Typed prefixes of the constants manager; it is never constructed here.
struct Unk_InventoryIntSetting { unsigned char prefix[0x50]; unsigned value; unsigned pad; unsigned* FUN_1401d7c10(); };
MS2_CHECK_SIZE(Unk_InventoryIntSetting, 0x58);
struct Unk_InventoryArraySetting {
    void* unknown0;
    bool initialized;
    unsigned char unknown9[0x47];
    std::vector<int> values;
    void* unknown68; void* unknown70; void* unknown78;
    const std::vector<int>& FUN_140a6aa40();
};
MS2_CHECK_SIZE(Unk_InventoryArraySetting, 0x80);
MS2_CHECK_OFFSET(Unk_InventoryArraySetting, values, 0x50);
struct Unk_InventoryConstants {
    unsigned char unknown0[0x6ee8];
    Unk_InventoryIntSetting value6ee8;
    unsigned char unknown6f40[0x598];
    Unk_InventoryArraySetting bagLimits[16];
    unsigned char unknown7cd8[0x69e8];
    Unk_InventoryIntSetting autoEquipMinLevel;
    Unk_InventoryIntSetting autoEquipMaxLevel;
};
MS2_CHECK_SIZE(Unk_InventoryConstants, 0xe770); // accessed prefix
MS2_CHECK_OFFSET(Unk_InventoryConstants, bagLimits, 0x74d8);
MS2_CHECK_OFFSET(Unk_InventoryConstants, autoEquipMinLevel, 0xe6c0);
MS2_CHECK_OFFSET(Unk_InventoryConstants, autoEquipMaxLevel, 0xe718);
Unk_InventoryConstants* FUN_1401d3200();
void FUN_1402b7560(Unk_InventoryArraySetting*, const char*);
bool FUN_140528930(CItem*);
bool FUN_14053cde0(CItemData*);
bool FUN_14053ce20(CItemData*);
int FUN_14053c940(CItemData*, int);
int FUN_14053c8e0(CItemData*, int);
int FUN_14053c9a0(CItemData*, unsigned short);
bool FUN_14053d1f0(CItemData*);
bool FUN_14053d210(CItemData*);
bool FUN_14053ce40(CItemData*);
bool FUN_14053cd90(CItemData*);
unsigned short FUN_14053dc40(CItemData*);
class Unk_InventoryVip { public: bool FUN_141b89990(); };
Unk_InventoryVip* FUN_1409eed90();
void FUN_140d73bc0(int, int, void*, CStringW);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_141275260(int, int, int);
void FUN_141276180(const CString&, const CString&);
CStringW FUN_14028b8e0(const CStringW&);
void FUN_140710590(COutPacket&);
struct Unk_InvItemDataView { CString FUN_14053eca0(); };   // CItemData member (this=rcx, hidden return=rdx)
class Unk_InventorySound { public: int FUN_1411a5110(CString, CString, CString, int, __int64, float, int); };
Unk_InventorySound* FUN_1403ed280();
class Unk_InventoryRestrictions { public: int FUN_14138c900(int); };
Unk_InventoryRestrictions* FUN_1409331e0();
int FUN_140525cf0(CItem*);
bool FUN_1403b3c40(const CStringW&, const wchar_t*);
extern Unk_Inventory DAT_143ab2a90;

struct Unk_InventoryUsePacket {
    Unk_InventoryUsePacket();
    ~Unk_InventoryUsePacket();
    void FUN_1401fbc40(COutPacket&);
    __int64 id;
    CStringW argument;
};
MS2_CHECK_SIZE(Unk_InventoryUsePacket, 0x10);
struct Unk_InventoryUnequipPacket {
    Unk_InventoryUnequipPacket();
    void FUN_1401fb910(COutPacket&);
    __int64 id;
};
MS2_CHECK_SIZE(Unk_InventoryUnequipPacket, 8);
struct Unk_InventoryEquipPacket {
    Unk_InventoryEquipPacket();
    void FUN_1401fb870(int mode);
    void FUN_1401fb760(COutPacket&);
    __int64 id;
    int slot, mode;
};
MS2_CHECK_SIZE(Unk_InventoryEquipPacket, 0x10);
class CMsgBoxData;
MS2Ptr<CMsgBoxData> FUN_140d73d20(int, CStringW, void*, CStringW);
void FUN_140534050(CMsgBoxData*, unsigned);
void FUN_141a01600(CMsgBoxData*, __int64);
void FUN_141a01ee0(CMsgBoxData*, Unk_Inventory::ItemPtr, const CStringW&, int, int, int, int, int);
void FUN_141a01700(CMsgBoxData*, int, int, int);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);
CStringW FUN_140527b10(CItem*);
CStringW FUN_1405c2690(CStringW, CStringW);
class Unk_InventoryBinding { public: int FUN_140635100(); int FUN_140635120(); };
Unk_InventoryBinding* FUN_140527930(CItem*);
int FUN_141420a70(CItem*, Unk_InventoryPlayer*);
bool FUN_1406344b0(Unk_Inventory::ItemPtr, const __int64*, ItemUtilTransfer::TOutBindingParam*);
int FUN_1405258b0(CItem*);
class Unk_InventoryEnchant { public: bool FUN_1406210e0(); };
Unk_InventoryEnchant* FUN_1405279c0(CItem*);
struct Unk_InventoryAccount {
    unsigned char prefix[0xa9c]; bool flag;
    bool FUN_140a6a0d0();
};
MS2_CHECK_SIZE(Unk_InventoryAccount, 0xa9d); // accessed prefix
MS2_CHECK_OFFSET(Unk_InventoryAccount, flag, 0xa9c);
Unk_InventoryAccount* FUN_1401c0d90();
// The original iterator has a constructor, so member returns use the hidden
// return buffer (RDX), even though the payload is one pointer.
struct Unk_InventoryCharacterIterator { Unk_InventoryCharacterIterator(); void* node; };
MS2_CHECK_SIZE(Unk_InventoryCharacterIterator, 8);
class Unk_InventoryCharacters {
public:
    Unk_InventoryCharacterIterator FUN_140341f40();
    Unk_InventoryCharacterIterator FUN_1404c0270(const __int64& id);
};
extern Unk_InventoryCharacters DAT_143ab2a30;
bool FUN_1403344a0(const Unk_InventoryCharacterIterator&, const Unk_InventoryCharacterIterator&);
class Unk_InventoryDialog { public: int FUN_141999de0(); };
Unk_InventoryDialog* FUN_1405344f0(int);
class Unk_InventoryStateManager;
extern Unk_InventoryStateManager* DAT_143ab5cc8;
extern Unk_InventoryListener* DAT_143ab7908;

// @0x140a5c650
bool FUN_140a5c650(Unk_Inventory::ItemPtr first, Unk_Inventory::ItemPtr second) {
    if (!first || !second) return false;
    if (first->FUN_140525c60() == 0) return false;
    if (second->FUN_140525c60() == 0) return true;
    return first->FUN_140528910() < second->FUN_140528910();
}
MS2_REPLACE(0x140a5c650, FUN_140a5c650, 315, 0x5B2F0FD5);

// @0x140a5c7a0
Unk_Inventory::Unk_Inventory() : items(10), autoEquipQueue(10), excludedItems(10) {}
// @0x140a5c850
Unk_Inventory::~Unk_Inventory() {}

// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5c8e0
void Unk_Inventory::FUN_140a5c8e0() {
    for (int i = 0; i < 15; ++i) {
        slots[i].SetCount(FUN_140a66510(i), -1);
        extraSlots[i] = 0;
    }
    FUN_140a5c970();
}
MS2_REPLACE_METHOD(0x140a5c8e0, Unk_Inventory, FUN_140a5c8e0, 123, 0x1FB5DEC2);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5c970
void Unk_Inventory::FUN_140a5c970() {
    if (Unk_LockGuard guard = lock) {} else {
        FUN_140a66c00();
        items.RemoveAll();
        for (int i = 0; i < 15; ++i) {
            int count = FUN_140a66510(i);
            slots[i].RemoveAll();
            slots[i].SetCount(count, -1);
            extraSlots[i] = 0;
        }
    }
}
MS2_REPLACE_METHOD(0x140a5c970, Unk_Inventory, FUN_140a5c970, 224, 0x268914F8);
// @0x140a5ca60
void Unk_Inventory::FUN_140a5ca60(int category) {
    ItemArray found;
    if (Unk_LockGuard guard = lock) {} else {
        FUN_140a60880(category, found);
        int count = (int)found.GetCount();
        for (int i = 0; i < count; ++i) {
            ItemPtr item = found[i];
            if (item == nullptr) continue;
            FUN_140a5d390(item->FUN_140526a50());
        }
    }
}
MS2_REPLACE_METHOD(0x140a5ca60, Unk_Inventory, FUN_140a5ca60, 282, 0x2AC17190);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5cb80
void Unk_Inventory::FUN_140a5cb80(int category, int extra) {
    if (category >= 0 && category < 15) {
        ItemArray removed;
        if (Unk_LockGuard guard = lock) {} else {
            ItemArray& bag = slots[category];
            unsigned oldCount = (unsigned)bag.GetCount();
            unsigned newCount = FUN_140a66510(category) + extra;
            for (unsigned i = newCount; i < oldCount; ++i) {
                CItem* item = bag[i].get();
                if (item != nullptr) {
                    removed.Add(ItemPtr(item));
                    FUN_140a5d390(item->FUN_140526a50());
                    bag[i] = 0;
                }
            }
            bag.SetCount(newCount, -1);
            extraSlots[category] = extra;
        }
        for (unsigned i = 0; i < removed.GetCount(); ++i) {
            CItem* item = removed[i].get();
            Unk_InventoryListener* listener = FUN_140a6a840();
            listener->vfunc_2(item, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x140a5cb80, Unk_Inventory, FUN_140a5cb80, 555, 0xD641C1CE);
// @0x140a5cdc0
bool Unk_Inventory::FUN_140a5cdc0(unsigned category) {
    int maximum = FUN_140a66750(category);
    for (unsigned i = 0; (int)i < 15; ++i)
        if (extraSlots[(int)i] == maximum && category == i) return true;
    return false;
}
MS2_REPLACE_METHOD(0x140a5cdc0, Unk_Inventory, FUN_140a5cdc0, 99, 0xEFF4AAF4);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5ce30
bool Unk_Inventory::FUN_140a5ce30(CStringW& names) {
    unsigned count = 0;
    for (size_t i = 0; i < 15; ++i) {
        if (FUN_140a5cdc0((unsigned)i)) {
            if (count != 0) names += L", ";
            names += FUN_1401a9d70()->FUN_141813300((unsigned)i);
            ++count;
        }
    }
    return count < 15;
}
MS2_REPLACE_METHOD(0x140a5ce30, Unk_Inventory, FUN_140a5ce30, 236, 0x77D3BC0E);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5cf30
int Unk_Inventory::FUN_140a5cf30(int category) {
    if (category < 0 || category > 14) return 0;
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        for (unsigned i = 0; i < slots[category].GetCount(); ++i) {
            ItemPtr item = slots[category][i];
            if (item == nullptr) continue;
            ++count;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a5cf30, Unk_Inventory, FUN_140a5cf30, 271, 0xF4C9FBF5);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5d050
int Unk_Inventory::FUN_140a5d050(int category) {
    if (category < 0 || category > 14) return 0;
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        ItemArray& bag = slots[category];
        count = (int)bag.GetCount();
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a5d050, Unk_Inventory, FUN_140a5d050, 140, 0x437B4833);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5d0f0
unsigned FUN_140a5d0f0() { return *FUN_1401d3200()->value6ee8.FUN_1401d7c10(); }
MS2_REPLACE(0x140a5d0f0, FUN_140a5d0f0, 35, 0xEEBD98E0);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5d120
int Unk_Inventory::FUN_140a5d120(CItem* item) {
    int category = FUN_140a617f0(ItemPtr(item));
    if (category < 0 || category > 14) return 11;
    if (Unk_LockGuard guard = lock) {} else {
        if (items.Lookup(item->FUN_140526a50()) != nullptr) return 17;
        int slot = item->FUN_140526b50();
        if (slot == -1) {
            slot = FUN_140a61190(category);
            if (slot == -1) return 13;
            item->FUN_140526b70(slot);
        } else {
            int count = (int)slots[category].GetCount();
            if (slot < 0 || slot >= count) return 29;
            if (slots[category][slot].get() != nullptr) return 17;
        }
        items.SetAt(item->FUN_140526a50(), ItemPtr(item));
        slots[category][slot].AssignRaw(item);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140a5d120, Unk_Inventory, FUN_140a5d120, 614, 0x2B7971F8);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5d390
void Unk_Inventory::FUN_140a5d390(__int64 id) {
    ItemPtr item;
    if (Unk_LockGuard guard = lock) {} else if (items.Lookup(id, item)) {
        items.RemoveKey(id);
        if (item.get() != nullptr) {
            int category = FUN_140a617f0(item);
            if (category < 0 || category > 14) return;
            ItemArray& bag = slots[category];
            int slot = item->FUN_140526b50();
            if (slot < 0 || slot >= (int)bag.GetCount()) return;
            bag[slot] = 0;
        }
    }
}
MS2_REPLACE_METHOD(0x140a5d390, Unk_Inventory, FUN_140a5d390, 408, 0x3477AB4B);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5d530
void Unk_Inventory::FUN_140a5d530(CItem* item) {
    if (item != nullptr) {
        ItemPtr old = FUN_140a5d680(item->FUN_140526a50());
        if (old.get() != nullptr) {
            int slot = old->FUN_140526b50();
            int category = FUN_140a617f0(old);
            item->FUN_140526b70(slot);
            items.SetAt(old->FUN_140526a50(), ItemPtr(item));
            slots[category][slot].AssignRaw(item);
        }
    }
}
MS2_REPLACE_METHOD(0x140a5d530, Unk_Inventory, FUN_140a5d530, 324, 0x1F7F4993);
// @0x140a5d680
Unk_Inventory::ItemPtr Unk_Inventory::FUN_140a5d680(__int64 id) {
    if (id == 0) return ItemPtr(0);
    ItemPtr item;
    { if (Unk_LockGuard guard = lock) {} else { items.Lookup(id, item); } }
    return item;
}
MS2_REPLACE_METHOD(0x140a5d680, Unk_Inventory, FUN_140a5d680, 204, 0x4A1D0688);

// MS2-FUNCTIONAL: early-return spelling; shared pointer return copies instead of moving.
// @0x140a5d760
Unk_Inventory::ItemPtr Unk_Inventory::FUN_140a5d760(int skill, int ignoreUsability) {
    if (skill == 0) return ItemPtr(0);
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return ItemPtr(0);
    if (Unk_LockGuard guard = lock) {} else {
        for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
            ItemPtr item = items.GetValueAt(pos);
            if (!item) continue;
            int itemSkill = FUN_14053dc20(FUN_140527840(item.operator->()));
            if (itemSkill == 0 || itemSkill != skill) continue;
            if (FUN_140526100(item.operator->()) != 0) continue;
            if (ignoreUsability != 0 || player->FUN_141662eb0(item.get()) != 0) return item;
        }
    }
    return ItemPtr(0);
}
MS2_REPLACE_METHOD(0x140a5d760, Unk_Inventory, FUN_140a5d760, 555, 0xDC051FD2);
// @0x140a5d9a0
Unk_Inventory::ItemPtr Unk_Inventory::FUN_140a5d9a0(CStringW function, int ignoreUsability) {
    if (function.IsEmpty()) return ItemPtr(0);
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return ItemPtr(0);
    std::vector<ItemPtr> found;
    { if (Unk_LockGuard guard = lock) {} else {
        for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
            ItemPtr item = items.GetValueAt(pos);
            if (!item) continue;
            if (FUN_140527840(item.operator->())->function.name != function) continue;
            if (ignoreUsability == 0 && player->FUN_141662eb0(item.get()) == 0) continue;
            found.push_back(item);
        }
    } }
    std::sort(found.begin(), found.end(), FUN_140a5c650);
    if (!found.empty()) return found[0];
    return ItemPtr(0);
}
MS2_REPLACE_METHOD(0x140a5d9a0, Unk_Inventory, FUN_140a5d9a0, 755, 0x333AFB3F);
// MS2-FUNCTIONAL: equivalent typed metadata and STL access.
// @0x140a5dca0
Unk_Inventory::ItemPtr Unk_Inventory::FUN_140a5dca0(CStringW function, CStringW parameter) {
    if (function.IsEmpty()) return ItemPtr(0);
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return ItemPtr(0);
    std::vector<ItemPtr> found;
    { if (Unk_LockGuard guard = lock) {} else {
        for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
            ItemPtr item = items.GetValueAt(pos);
            if (!item) continue;
            if (FUN_140527840(item.operator->())->function.name != function) continue;
            CStringW value(FUN_140527840(item.operator->())->function.parameter.text);
            if (value != parameter) continue;
            if (player->FUN_141662eb0(item.get()) == 0) continue;
            found.push_back(item);
        }
    } }
    std::sort(found.begin(), found.end(), FUN_140a5c650);
    if (!found.empty()) return found[0];
    return ItemPtr(0);
}
MS2_REPLACE_METHOD(0x140a5dca0, Unk_Inventory, FUN_140a5dca0, 910, 0xCFFD79FB);
// MS2-FUNCTIONAL: early-return spelling and shared pointer return copy.
// @0x140a5e040
Unk_Inventory::ItemPtr Unk_Inventory::FUN_140a5e040(int tag) {
    if (tag == 0) return ItemPtr(0);
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return ItemPtr(0);
    std::vector<ItemPtr> found;
    { if (Unk_LockGuard guard = lock) {} else {
        for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
            ItemPtr item = items.GetValueAt(pos);
            if (item == nullptr) continue;
            if (!FUN_1405277e0(item.operator->(), tag)) continue;
            if (player->FUN_141662eb0(item.get()) == 0) continue;
            found.push_back(item);
        }
    } }
    std::sort(found.begin(), found.end(), FUN_140a5c650);
    if (found.size() == 0) return ItemPtr(0);
    return found[0];
}
MS2_REPLACE_METHOD(0x140a5e040, Unk_Inventory, FUN_140a5e040, 656, 0x8F0B4180);
// MS2-FUNCTIONAL: early-return spelling and shared pointer return copy.
// @0x140a5e2e0
Unk_Inventory::ItemPtr Unk_Inventory::FUN_140a5e2e0(int itemId) {
    if (itemId == 0) return ItemPtr(0);
    MS2Ptr<CItemData> data = FUN_14053f870(itemId);
    if (data == nullptr) return ItemPtr(0);
    int category = FUN_14053fd90(data.operator->());
    if (category < 0 || category > 14) return ItemPtr(0);
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return ItemPtr(0);
    if (Unk_LockGuard guard = lock) {} else {
        ItemArray& bag = slots[category];
        for (unsigned i = 0; i < bag.GetCount(); ++i) {
            ItemPtr item = bag[i];
            if (item == nullptr) continue;
            if (item->FUN_1405276c0() != itemId) continue;
            if (player->FUN_141662eb0(item.get()) != 0) return item;
        }
    }
    return ItemPtr(0);
}
MS2_REPLACE_METHOD(0x140a5e2e0, Unk_Inventory, FUN_140a5e2e0, 721, 0xA7F7BFD5);
// MS2-FUNCTIONAL: early-return spelling and shared pointer return copy.
// @0x140a5e5c0
Unk_Inventory::ItemPtr Unk_Inventory::FUN_140a5e5c0(int itemId, int rarity) {
    if (itemId == 0) return ItemPtr(0);
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return ItemPtr(0);
    MS2Ptr<CItemData> data = FUN_14053f870(itemId);
    if (data == nullptr) return ItemPtr(0);
    int category = FUN_14053fd90(data.operator->());
    if (category < 0 || category > 14) return ItemPtr(0);
    if (Unk_LockGuard guard = lock) {} else {
        ItemArray& bag = slots[category];
        for (unsigned i = 0; i < bag.GetCount(); ++i) {
            ItemPtr item = bag[i];
            if (item == nullptr) continue;
            if (item->FUN_1405276c0() != itemId) continue;
            if (item->FUN_140526bd0() != rarity) continue;
            if (player->FUN_141662eb0(item.get()) != 0) return item;
        }
    }
    return ItemPtr(0);
}
MS2_REPLACE_METHOD(0x140a5e5c0, Unk_Inventory, FUN_140a5e5c0, 758, 0x01CCEAF4);
// MS2-FUNCTIONAL: typed list access; preserve the original repeated bubble-sort passes.
// @0x140a5e8d0
int Unk_Inventory::FUN_140a5e8d0(int itemId, ATL::CAtlList<ItemPtr>& result, int order) {
    if (itemId == 0) return 0;
    MS2Ptr<CItemData> data = FUN_14053f870(itemId);
    if (data == nullptr) return 0;
    int category = FUN_14053fd90(data.operator->());
    if (category < 0 || category > 14) return 0;
    { if (Unk_LockGuard guard = lock) {} else {
        ItemArray& bag = slots[category];
        for (unsigned i = 0; i < bag.GetCount(); ++i) {
            ItemPtr item = bag[i];
            if (item == nullptr || item->FUN_1405276c0() != itemId) continue;
            if (order == 2) result.AddTail(item);
            else {
                unsigned count = FUN_140526c50(item.operator->());
                if (count < FUN_1405281e0(item.operator->())) result.AddTail(item);
            }
        }
    } }
    if (result.GetCount() > 1) {
        int count = (int)result.GetCount();
        int last = count - 1;
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < last; ++j) {
                int first = FUN_140526c50(result.GetAt(result.FindIndex(j)).operator->());
                int second = FUN_140526c50(result.GetAt(result.FindIndex(j + 1)).operator->());
                if ((order == 2 && second < first) || (order == 1 && first < second))
                    result.SwapElements(result.FindIndex(j), result.FindIndex(j + 1));
            }
        }
    }
    return (int)result.GetCount();
}
MS2_REPLACE_METHOD(0x140a5e8d0, Unk_Inventory, FUN_140a5e8d0, 1024, 0xB1E2B228);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5ece0
bool Unk_Inventory::FUN_140a5ece0(int itemId, int count) { return count <= FUN_140a5f180(itemId, 0); }
MS2_REPLACE_METHOD(0x140a5ece0, Unk_Inventory, FUN_140a5ece0, 76, 0xC0C5259E);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a5ed40
bool Unk_Inventory::FUN_140a5ed40(int itemId, int rarity, int count) { return count <= FUN_140a5f180(itemId, rarity); }
MS2_REPLACE_METHOD(0x140a5ed40, Unk_Inventory, FUN_140a5ed40, 83, 0x5CCABB8D);
// MS2-FUNCTIONAL: typed filter and early-return spelling.
// @0x140a5eda0
int Unk_Inventory::FUN_140a5eda0(const int* filter) {
    if (filter[0] == 0) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    MS2Ptr<CItemData> data = FUN_14053f870(filter[0]);
    if (data == nullptr) return 0;
    int category = FUN_14053fd90(data.operator->());
    if (category < 0 || category > 14) return 0;
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        ItemArray& bag = slots[category];
        for (unsigned i = 0; i < bag.GetCount(); ++i) {
            ItemPtr item = bag[i];
            if (item == nullptr || item->FUN_1405276c0() != filter[0]) continue;
            if (filter[1] != 0 && item->FUN_140526bd0() != filter[1]) continue;
            if (filter[2] != 0 && FUN_140528e20(item.operator->())) continue;
            if (player->FUN_141662eb0(item.get()) != 0) count += FUN_140526c50(item.operator->());
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a5eda0, Unk_Inventory, FUN_140a5eda0, 688, 0x152569D1);
// MS2-FUNCTIONAL: early returns preserve lock and smart-pointer cleanup.
// @0x140a5f060
int Unk_Inventory::FUN_140a5f060(__int64 id) {
    if (id == 0) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        ItemPtr item = FUN_140a5d680(id);
        if (item.get() != nullptr && player->FUN_141662eb0(item.get()) != 0)
            count = item->vfunc_4();
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a5f060, Unk_Inventory, FUN_140a5f060, 274, 0x5F6FCB45);
// MS2-FUNCTIONAL: early-return spelling; typed virtual quantity accessor.
// @0x140a5f180
int Unk_Inventory::FUN_140a5f180(int itemId, int rarity) {
    if (itemId == 0) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    MS2Ptr<CItemData> data = FUN_14053f870(itemId);
    if (data == nullptr) return 0;
    int category = FUN_14053fd90(data.operator->());
    if (category < 0 || category > 14) return 0;
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        ItemArray& bag = slots[category];
        for (unsigned i = 0; i < bag.GetCount(); ++i) {
            ItemPtr item = bag[i];
            if (item == nullptr || item->FUN_1405276c0() != itemId) continue;
            if (rarity != 0 && item->FUN_140526bd0() != rarity) continue;
            if (player->FUN_141662eb0(item.get()) != 0) count += item->vfunc_4();
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a5f180, Unk_Inventory, FUN_140a5f180, 640, 0xA56DD464);
// MS2-FUNCTIONAL: preserve the original reference-item checks and reference quantity.
// @0x140a5f410
int Unk_Inventory::FUN_140a5f410(ItemPtr reference) {
    if (reference == nullptr) return 0;
    int itemId = reference->FUN_1405276c0();
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    MS2Ptr<CItemData> data = FUN_14053f870(itemId);
    if (data == nullptr) return 0;
    int category = FUN_14053fd90(data.operator->());
    if (category < 0 || category > 14) return 0;
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        ItemArray& bag = slots[category];
        for (unsigned i = 0; i < bag.GetCount(); ++i) {
            ItemPtr item = bag[i];
            if (item == nullptr || item->FUN_1405276c0() != itemId) continue;
            int rarity = item->FUN_140526bd0();
            if (rarity != reference->FUN_140526bd0()) continue;
            if (player->FUN_141662eb0(reference.get()) == 0) continue;
            int property = FUN_140529640(item.operator->());
            if (property == FUN_140529640(reference.operator->())) count += reference->vfunc_4();
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a5f410, Unk_Inventory, FUN_140a5f410, 859, 0x51CE102B);
// @0x140a5f780
void Unk_Inventory::FUN_140a5f780(int tag, int rarity) { FUN_140a5f7b0(tag, rarity); }
MS2_REPLACE_METHOD(0x140a5f780, Unk_Inventory, FUN_140a5f780, 42, 0x941253E9);
// MS2-FUNCTIONAL: typed map iteration and early returns.
// @0x140a5f7b0
int Unk_Inventory::FUN_140a5f7b0(int tag, int rarity) {
    if (tag == 0) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
            ItemPtr item = items.GetValueAt(pos);
            if (item == nullptr || !FUN_1405277e0(item.operator->(), tag)) continue;
            if (player->FUN_141662eb0(item.get()) == 0) continue;
            if (rarity != 0 && item->FUN_140526bd0() != rarity) continue;
            count += item->vfunc_4();
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a5f7b0, Unk_Inventory, FUN_140a5f7b0, 460, 0x8916FA33);
// MS2-FUNCTIONAL: equivalent typed metadata and array access.
// @0x140a5f990
int Unk_Inventory::FUN_140a5f990(CStringW function) {
    int count = 0;
    if (function.IsEmpty()) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    if (Unk_LockGuard guard = lock) {} else {
        for (int category = 0; category < 15; ++category) {
            for (unsigned i = 0; i < slots[category].GetCount(); ++i) {
                ItemPtr item = slots[category][i];
                if (item == nullptr) continue;
                if (FUN_140527840(item.operator->())->function.name != function) continue;
                if (player->FUN_141662eb0(item.get()) != 0) count += FUN_140526c50(item.operator->());
            }
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a5f990, Unk_Inventory, FUN_140a5f990, 558, 0xBBA34D0A);
// MS2-FUNCTIONAL: equivalent nested filters expressed with continue.
// @0x140a5fbd0
int Unk_Inventory::FUN_140a5fbd0(int skill, int includeEquipment) {
    if (skill == 0) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        for (int category = 0; category < 15; ++category) {
            for (unsigned i = 0; i < slots[category].GetCount(); ++i) {
                ItemPtr item = slots[category][i];
                if (item == nullptr) continue;
                int itemSkill = FUN_14053dc20(FUN_140527840(item.operator->()));
                if (itemSkill == 0 || itemSkill != skill) continue;
                if (includeEquipment == 0) {
                    if (FUN_14053cbc0(FUN_140527840(item.operator->()))) continue;
                    if (FUN_140525640(item.operator->()) != 0) continue;
                    if (FUN_14053cc80(FUN_140527840(item.operator->()))) continue;
                }
                if (FUN_140526100(item.operator->()) != 0) continue;
                if (player->FUN_141662eb0(item.get()) != 0) count += FUN_140526c50(item.operator->());
            }
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a5fbd0, Unk_Inventory, FUN_140a5fbd0, 653, 0x115EDCE8);

// MS2-FUNCTIONAL: preserve redundant accessor calls and signed capacity subtraction.
// @0x140a5fe70
int Unk_Inventory::FUN_140a5fe70(int category, ItemPtr reference) {
    if (reference == nullptr || category < 0 || category > 14) return 0;
    MS2Ptr<CItemData> data = FUN_14053f870(reference->FUN_1405276c0());
    if (!data || data->property.slotMax == 1) return 0;
    int capacity = 0;
    if (Unk_LockGuard guard = lock) {} else {
        ItemArray& bag = slots[category];
        for (unsigned i = 0; i < bag.GetCount(); ++i) {
            ItemPtr item = bag[i];
            if (item == nullptr) continue;
            int id = item->FUN_1405276c0();
            if (id != reference->FUN_1405276c0()) continue;
            if (FUN_140525f10(reference.operator->()) != 0) {
                if (FUN_140525f10(item.operator->()) == 0) continue;
                Unk_InventoryStackIdentity* first = FUN_1405278d0(reference.operator->());
                Unk_InventoryStackIdentity* second = FUN_1405278d0(item.operator->());
                if (first != nullptr && second != nullptr && first->owner != second->owner) continue;
            }
            FUN_1405281e0(item.operator->());
            FUN_140526c50(item.operator->());
            int limit = FUN_1405281e0(item.operator->());
            int count = FUN_140526c50(item.operator->());
            capacity += limit - count;
        }
    }
    return capacity;
}
MS2_REPLACE_METHOD(0x140a5fe70, Unk_Inventory, FUN_140a5fe70, 1023, 0x1F94ED77);
// MS2-FUNCTIONAL: shared pointer declaration does not expose the move constructor.
// @0x140a60280
Unk_Inventory::ItemPtr Unk_Inventory::FUN_140a60280(int category, int slot) {
    ItemPtr item(0);
    if (category < 0 || category > 14) return ItemPtr(0);
    int count = (int)slots[category].GetCount();
    if (slot < 0 || count <= slot) return ItemPtr(0);
    { if (Unk_LockGuard guard = lock) {} else { item = slots[category][slot]; } }
    return item;
}
MS2_REPLACE_METHOD(0x140a60280, Unk_Inventory, FUN_140a60280, 339, 0x126FE83E);
// @0x140a603e0
int Unk_Inventory::FUN_140a603e0(int category, int from, int to) {
    if (Unk_LockGuard guard = lock) {} else {
        ItemPtr first = FUN_140a60280(category, from);
        if (first.get() != nullptr) {
            FUN_140a5d390(first->FUN_140526a50());
            first->FUN_140526b70(to);
        }
        ItemPtr second = FUN_140a60280(category, to);
        if (second.get() != nullptr) {
            FUN_140a5d390(second->FUN_140526a50());
            second->FUN_140526b70(from);
        }
        if (first.get() != nullptr) FUN_140a5d120(first.get());
        if (second.get() != nullptr) FUN_140a5d120(second.get());
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140a603e0, Unk_Inventory, FUN_140a603e0, 377, 0x816338B7);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a60560
int Unk_Inventory::FUN_140a60560(int category, int slot, ItemPtr item) {
    if (item == nullptr) return 0;
    if (category < 0 || category > 14) return 0;
    if (item->FUN_140526b50() == slot) return 1;
    if (Unk_LockGuard guard = lock) {} else {
        ItemArray& bag = slots[category];
        // The original tests slot <= count here, despite the unusual direction.
        if (slot < 0 || slot <= (int)bag.GetCount()) return 0;
        ItemPtr previous = bag[slot];
        if (previous.get() != nullptr) return 0;
        slots[category][slot] = item;
        item->FUN_140526b70(slot);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140a60560, Unk_Inventory, FUN_140a60560, 550, 0xD1B23BF4);
// @0x140a60790
void Unk_Inventory::FUN_140a60790(ItemArray& result) {
    if (Unk_LockGuard guard = lock) {} else {
        for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
            ItemPtr item = items.GetValueAt(pos);
            if (item == nullptr) continue;
            result.Add(item);
        }
    }
}
MS2_REPLACE_METHOD(0x140a60790, Unk_Inventory, FUN_140a60790, 225, 0x3B659717);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a60880
void Unk_Inventory::FUN_140a60880(int category, ItemArray& result) {
    if (category >= 0 && category < 15) {
        if (Unk_LockGuard guard = lock) {} else {
            for (unsigned i = 0; i < slots[category].GetCount(); ++i) {
                ItemPtr item = slots[category][i];
                if (item == nullptr) continue;
                result.Add(item);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140a60880, Unk_Inventory, FUN_140a60880, 268, 0xE3D94D0C);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a609a0
void Unk_Inventory::FUN_140a609a0(int category, ATL::CAtlArray<unsigned __int64>& result) {
    if (category >= 0 && category < 15) {
        if (Unk_LockGuard guard = lock) {} else {
            for (unsigned i = 0; i < slots[category].GetCount(); ++i) {
                ItemPtr item = slots[category][i];
                if (item == nullptr) continue;
                result.Add(item->FUN_140526a50());
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140a609a0, Unk_Inventory, FUN_140a609a0, 284, 0x2A368F4F);
// MS2-FUNCTIONAL: equivalent typed map iteration with scoped lock.
// @0x140a60ad0
int Unk_Inventory::FUN_140a60ad0(int type) {
    Unk_InventoryScopedLock guard(lock, 1);
    for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
        ItemPtr item = items.GetValueAt(pos);
        if (item == nullptr) continue;
        if (FUN_14053c5c0(FUN_140527840(item.operator->())) == type && FUN_140528980(item.operator->())) return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140a60ad0, Unk_Inventory, FUN_140a60ad0, 321, 0x274281EB);
// MS2-FUNCTIONAL: equivalent typed map iteration with scoped lock.
// @0x140a60c20
int Unk_Inventory::FUN_140a60c20(int type) {
    Unk_InventoryScopedLock guard(lock, 1);
    int count = 0;
    for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
        ItemPtr item = items.GetValueAt(pos);
        if (item == nullptr) continue;
        if (type != 0 && FUN_14053c5c0(FUN_140527840(item.operator->())) != type) continue;
        if (FUN_140528980(item.operator->())) ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a60c20, Unk_Inventory, FUN_140a60c20, 326, 0x43BB48CE);
// MS2-FUNCTIONAL: equivalent typed map iteration with scoped lock.
// @0x140a60d70
int Unk_Inventory::FUN_140a60d70(int type) {
    Unk_InventoryScopedLock guard(lock, 1);
    for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
        ItemPtr item = items.GetValueAt(pos);
        if (item == nullptr) continue;
        if (FUN_140527760(item.operator->()) == type && FUN_140528980(item.operator->())) return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140a60d70, Unk_Inventory, FUN_140a60d70, 313, 0x04FAC3B5);
// MS2-FUNCTIONAL: equivalent typed map iteration with scoped lock.
// @0x140a60ec0
int Unk_Inventory::FUN_140a60ec0(int tag) {
    Unk_InventoryScopedLock guard(lock, 1);
    for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
        ItemPtr item = items.GetValueAt(pos);
        if (item == nullptr) continue;
        if (FUN_1405277e0(item.operator->(), tag) && FUN_140528980(item.operator->())) return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140a60ec0, Unk_Inventory, FUN_140a60ec0, 318, 0x729C8B6E);
// MS2-FUNCTIONAL: equivalent filter loop with scoped cleanup.
// @0x140a61010
void Unk_Inventory::FUN_140a61010(int category, const __int64* filter, ItemArray& result) {
    if (category >= 0 && category < 15 && *filter != 0) {
        if (Unk_LockGuard guard = lock) {} else {
            for (unsigned i = 0; i < slots[category].GetCount(); ++i) {
                ItemPtr item = slots[category][i];
                if (item == nullptr) continue;
                if (FUN_1406a5a50(item, filter)) result.Add(item);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140a61010, Unk_Inventory, FUN_140a61010, 373, 0xDE25A3BB);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a61190
int Unk_Inventory::FUN_140a61190(int category) {
    if (category >= 0 && category < 15) {
        if (Unk_LockGuard guard = lock) {} else {
            for (unsigned i = 0; i < slots[category].GetCount(); ++i) {
                ItemPtr item = slots[category][i];
                if (item == nullptr) return i;
            }
        }
    }
    return -1;
}
MS2_REPLACE_METHOD(0x140a61190, Unk_Inventory, FUN_140a61190, 280, 0xC58578CC);
// MS2-FUNCTIONAL: equivalent early-return spelling.
// @0x140a612b0
int Unk_Inventory::FUN_140a612b0(int category, ItemPtr item, int quantity) {
    if (item == nullptr) return 0;
    if (category == -1) category = FUN_140a617f0(item);
    if (item.get() != nullptr && FUN_1405281e0(item.operator->()) > 1) {
        if (quantity <= FUN_140a5fe70(category, item)) return 0;
    }
    return FUN_140a61190(category);
}
MS2_REPLACE_METHOD(0x140a612b0, Unk_Inventory, FUN_140a612b0, 375, 0x959966DC);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a61430
int Unk_Inventory::FUN_140a61430(int category) {
    if (category >= 0 && category < 15) {
        if (Unk_LockGuard guard = lock) {} else {
            unsigned count = (unsigned)slots[category].GetCount();
            unsigned half = count >> 1;
            int last = count - 1;
            for (int i = 0; i < (int)half; ++i) {
                ItemPtr item = slots[category][last - i];
                if (item == nullptr) return 1;
                item = slots[category][i];
                if (item == nullptr) return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140a61430, Unk_Inventory, FUN_140a61430, 406, 0x33AA553B);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a615d0
int Unk_Inventory::FUN_140a615d0(int category) {
    if (category < 0 || category > 14) return 0;
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        for (unsigned i = 0; i < slots[category].GetCount(); ++i) {
            ItemPtr item = slots[category][i];
            if (item == nullptr) ++count;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a615d0, Unk_Inventory, FUN_140a615d0, 259, 0x5A865E94);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a616e0
int Unk_Inventory::FUN_140a616e0() {
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        for (POSITION pos = items.GetHeadPosition(); pos != nullptr; items.GetNext(pos)) {
            ItemPtr item = items.GetValueAt(pos);
            if (item.get() != nullptr && item->FUN_1405268f0() != 0) ++count;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x140a616e0, Unk_Inventory, FUN_140a616e0, 256, 0x3E4DADBF);
// @0x140a617f0
int Unk_Inventory::FUN_140a617f0(ItemPtr item) {
    return FUN_140a61870(MS2Ptr<CItemData>(FUN_140527840(item.operator->())));
}
MS2_REPLACE_METHOD(0x140a617f0, Unk_Inventory, FUN_140a617f0, 107, 0xFDCE65E4);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a61870
int Unk_Inventory::FUN_140a61870(MS2Ptr<CItemData> data) {
    if (data.get() == nullptr) return 7;
    return FUN_14053fd90(data.operator->());
}

// MS2-FUNCTIONAL: equivalent adjacent-item comparison loop.
// @0x140a618e0
int Unk_Inventory::FUN_140a618e0(int category) {
    if (category < 0 || category > 14) return 0;
    ItemPtr first(0), second(0);
    if (Unk_LockGuard guard = lock) {} else {
        if (FUN_140a61b40(category) != 0) return 1;
        for (unsigned i = 1; i < slots[category].GetCount(); ++i) {
            first = slots[category][i - 1];
            second = slots[category][i];
            if (FUN_14052a7e0(first, second) == 1) return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140a618e0, Unk_Inventory, FUN_140a618e0, 594, 0x5762F162);
// MS2-FUNCTIONAL: typed item metadata; original routine intentionally takes no lock.
// @0x140a61b40
int Unk_Inventory::FUN_140a61b40(int category) {
    if (category < 0 || category > 14) return 0;
    ItemPtr item(0);
    MS2Ptr<CItemData> data(0);
    ATL::CAtlMap<int, unsigned> seen;
    for (unsigned i = 0; i < slots[category].GetCount(); ++i) {
        item = slots[category][i];
        if (item == nullptr) continue;
        data.AssignRaw(FUN_140527840(item.operator->()));
        if (data == nullptr) continue;
        if (FUN_14053c7c0(data.operator->())) {
            unsigned limit = data->property.slotMax;
            if ((unsigned)FUN_140526c50(item.operator->()) < limit) {
                unsigned previous;
                if (seen.Lookup(item->FUN_1405276c0(), previous)) return 1;
                seen.SetAt(item->FUN_1405276c0(), i);
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140a61b40, Unk_Inventory, FUN_140a61b40, 614, 0xF20A9A12);

// MS2-FUNCTIONAL: typed packet payload and equivalent early-return spelling.
// @0x140a61db0
int Unk_Inventory::FUN_140a61db0(__int64 id, const CStringW& argument) {
    ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
    if (!item) return 0;
    int checkState = 1;
    CStringW function = FUN_140527840(item.operator->())->function.name;
    if (FUN_1403b3c40(function, L"OpenItemBox") || FUN_1403b3c40(function, L"OpenItemBoxLullu") ||
        FUN_1403b3c40(function, L"OpenItemBoxLulluSimple")) checkState = 0;
    if (checkState != 0) {
        Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (player == nullptr) return 0;
        if (player->FUN_14166ce30() != 0) { FUN_140d73bc0(66, 0, nullptr, L""); return 0; }
    }
    if (FUN_140a65e30(item.get()) != 0) return 0;
    Unk_InventoryUsePacket payload;
    payload.id = item->FUN_140526a50();
    payload.argument = argument;
    COutPacket packet(25, 0);
    payload.FUN_1401fbc40(packet);
    FUN_140710590(packet);
    MS2Ptr<CItemData> data(FUN_140527840(item.operator->()));
    if (data.get() != nullptr)
        FUN_1403ed280()->FUN_1411a5110("ms2sound/sound/item", reinterpret_cast<Unk_InvItemDataView*>(data.operator->())->FUN_14053eca0(), "", 0, 0, 1.0f, 0);
    return 1;
}
MS2_REPLACE_METHOD(0x140a61db0, Unk_Inventory, FUN_140a61db0, 1024, 0x39622B75);
// @0x140a621c0
int Unk_Inventory::FUN_140a621c0(__int64 id, int slot, int mode) {
    ItemPtr item = DAT_143ab2a90.FUN_140a5d680(id);
    if (!item) return 0;
    return FUN_140a62270(item.get(), slot, mode, 0);
}
MS2_REPLACE_METHOD(0x140a621c0, Unk_Inventory, FUN_140a621c0, 161, 0x7EC969E0);
// MS2-FUNCTIONAL: typed binding prompt and packet payload; equivalent early returns.
// @0x140a62270
int Unk_Inventory::FUN_140a62270(CItem* item, int slot, int mode, int skipBinding) {
    if (FUN_1409331e0()->FUN_14138c900(4) != 0) { FUN_141275260(2185, 1, 1); return 0; }
    if (item == nullptr) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    if (player->FUN_14166ce30() != 0) { FUN_140d73bc0(66, 0, nullptr, L""); return 0; }
    if (FUN_140a65e30(item) != 0) return 0;
    int selected = slot;
    if (slot == 0) selected = FUN_141420a70(item, player);
    if (FUN_140a63950(item, selected, mode) == 0) return 0;
    if (skipBinding == 0) {
        if (FUN_140527930(item)->FUN_140635100() != 0 && FUN_140527930(item)->FUN_140635120() == 0) {
            CStringW prompt = FUN_1405c2690(L"s_msg_transfer_bind_when_equip", player->vfunc_77());
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(17, prompt, nullptr, s_useBindEquipItem);
            if (box.get() != nullptr) {
                FUN_140534050(box.operator->(), slot);
                FUN_140534050(box.operator->(), mode);
                FUN_141a01600(box.operator->(), item->FUN_140526a50());
                FUN_141a01ee0(box.operator->(), ItemPtr(item), FUN_140527b10(item), 1, 0, -1, -1, 1);
                FUN_141a01700(box.operator->(), 1143, 1144, 0);
                FUN_140d73c60(box);
                return 1;
            }
        }
    }
    if (DAT_143ab2a90.FUN_140a661e0(item) == 0) return 0;
    Unk_InventoryEquipPacket payload;
    payload.id = item->FUN_140526a50();
    payload.slot = selected;
    payload.FUN_1401fb870(mode);
    COutPacket packet(22, 0);
    packet.Encode1(0);
    payload.FUN_1401fb760(packet);
    FUN_140710590(packet);
    MS2Ptr<CItemData> data(FUN_140527840(item));
    if (data.get() != nullptr)
        FUN_1403ed280()->FUN_1411a5110("ms2sound/sound/item", reinterpret_cast<Unk_InvItemDataView*>(data.operator->())->FUN_14053eca0(), "", 0, 0, 1.0f, 0);
    return 1;
}
MS2_REPLACE_METHOD(0x140a62270, Unk_Inventory, FUN_140a62270, 1692, 0x65CDD949);
// MS2-FUNCTIONAL: typed packet payload and equivalent early returns.
// @0x140a62920
int Unk_Inventory::FUN_140a62920(__int64 id) {
    if (FUN_1409331e0()->FUN_14138c900(5) != 0) { FUN_141275260(2185, 1, 1); return 0; }
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 1;
    if (player->FUN_14166ce30() != 0) { FUN_140d73bc0(66, 0, nullptr, L""); return 0; }
    ItemPtr item = player->FUN_141655b80(id);
    if (!item) return 1;
    if (FUN_140525cf0(item.operator->()) != 0) { FUN_140d73bc0(207, 0, nullptr, L""); return 0; }
    if (FUN_140a655b0(item.get()) == 0) return 0;
    Unk_InventoryUnequipPacket payload;
    payload.id = id;
    COutPacket packet(22, 0);
    packet.Encode1(1);
    payload.FUN_1401fb910(packet);
    FUN_140710590(packet);
    MS2Ptr<CItemData> data(FUN_140527840(item.operator->()));
    if (data.get() != nullptr)
        FUN_1403ed280()->FUN_1411a5110("ms2sound/sound/item", reinterpret_cast<Unk_InvItemDataView*>(data.operator->())->FUN_14053eca0(), "", 0, 0, 1.0f, 0);
    return 1;
}
MS2_REPLACE_METHOD(0x140a62920, Unk_Inventory, FUN_140a62920, 908, 0x22CFDA56);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a62cc0
void Unk_Inventory::FUN_140a62cc0(unsigned char category) {
    COutPacket packet(23, 0);
    packet.Encode1(9);
    packet.Encode1(category);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140a62cc0, Unk_Inventory, FUN_140a62cc0, 94, 0x4BFCB7B4);
// MS2-FUNCTIONAL: typed skill request and owned skill pointer; equivalent early returns.
// @0x140a62d30
unsigned Unk_Inventory::FUN_140a62d30(int skill) {
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!player) return 0;
    ItemPtr item = FUN_140a5d760(skill, 0);
    if (item.IsNull()) return 0;
    if (FUN_1409331e0()->FUN_14138c900(8)) { FUN_141275260(2184, 1, 1); return 0; }
    if (!FUN_14053d270(FUN_140527840(item.operator->())) &&
        !FUN_14053cb40(FUN_140527840(item.operator->())) &&
        !FUN_14053cc80(FUN_140527840(item.operator->()))) return 0;
    MS2Ptr<Unk_InventorySkillLevel> data = FUN_1401958b0()->FUN_1407ee2f0(skill, 1);
    if (data == 0) return 0;
    Unk_InventorySkillRequest request(skill, 1);
    request.remap = FUN_140804450(data.operator->());
    request.item = item->FUN_140526a50();
    MS2Ptr<CSkillRecord> record = player->FUN_141523bc0()->FUN_141765570(request);
    if (record == 0) return 0;
    return player->vfunc_102(record);
}
MS2_REPLACE_METHOD(0x140a62d30, Unk_Inventory, FUN_140a62d30, 702, 0xBAB5FC29);
// MS2-FUNCTIONAL: typed skill request and owned skill pointer; equivalent early returns.
// @0x140a63000
unsigned Unk_Inventory::FUN_140a63000(int itemId) {
    MS2Ptr<CItemData> metadata = FUN_14053f870(itemId);
    if (metadata == 0) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!player) return 0;
    ItemPtr item = FUN_140a5e2e0(itemId);
    if (item == 0) return 0;
    if (FUN_1409331e0()->FUN_14138c900(8)) { FUN_141275260(2184, 1, 1); return 0; }
    if (!FUN_14053d270(FUN_140527840(item.operator->()))) return 0;
    int skill = FUN_14053dc20(metadata.operator->());
    MS2Ptr<Unk_InventorySkillLevel> data = FUN_1401958b0()->FUN_1407ee2f0(skill, 1);
    if (data == 0) return 0;
    Unk_InventorySkillRequest request(FUN_14053dc20(metadata.operator->()), 1);
    request.remap = FUN_140804450(data.operator->());
    request.itemUse = true;
    request.item = item->FUN_140526a50();
    MS2Ptr<CSkillRecord> record = player->FUN_141523bc0()->FUN_141765570(request);
    if (record == 0) return 0;
    return player->vfunc_102(record);
}
MS2_REPLACE_METHOD(0x140a63000, Unk_Inventory, FUN_140a63000, 857, 0x12C5EF21);
// MS2-FUNCTIONAL: typed skill request and owned skill pointer; equivalent early returns.
// @0x140a63360
unsigned Unk_Inventory::FUN_140a63360(int skill) {
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!player) return 0;
    ItemPtr item = FUN_140a5d760(skill, 0);
    if (item == 0) return 0;
    if (FUN_1409331e0()->FUN_14138c900(8)) { FUN_141275260(2184, 1, 1); return 0; }
    if (!FUN_14053d270(FUN_140527840(item.operator->()))) return 0;
    MS2Ptr<Unk_InventorySkillLevel> data = FUN_1401958b0()->FUN_1407ee2f0(skill, 1);
    if (data == 0) return 0;
    Unk_InventorySkillRequest request(skill, 1);
    request.remap = FUN_140804450(data.operator->());
    request.item = item->FUN_140526a50();
    request.itemUse = true;
    MS2Ptr<CSkillRecord> record = player->FUN_141523bc0()->FUN_141765570(request);
    if (record == 0) return 0;
    return player->vfunc_102(record);
}
MS2_REPLACE_METHOD(0x140a63360, Unk_Inventory, FUN_140a63360, 646, 0xC31C5C98);
// MS2-FUNCTIONAL: preserve initial lookup before player skill/level adjustment and owned call arguments.
// @0x140a635f0
unsigned Unk_Inventory::FUN_140a635f0(CItem* item) {
    if (!item) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!player) return 0;
    if (FUN_1409331e0()->FUN_14138c900(8)) { FUN_141275260(2184, 1, 1); return 0; }
    if (!FUN_14053d270(FUN_140527840(item)) && !FUN_14053cb40(FUN_140527840(item)) &&
        !FUN_14053cc80(FUN_140527840(item))) return 0;
    int skill = FUN_141769320(MS2Ptr<CItemData>(FUN_140527840(item)));
    unsigned short level = 1;
    MS2Ptr<Unk_InventorySkillLevel> data = FUN_1401958b0()->FUN_1407ee2f0(skill, level);
    if (data == 0) return 0;
    player->FUN_141526c80(&skill, &level);
    Unk_InventorySkillRequest request(skill, 1);
    request.level = level;
    request.remap = FUN_140804450(data.operator->());
    request.item = item->FUN_140526a50();
    MS2Ptr<CSkillRecord> record = player->FUN_141523bc0()->FUN_141765570(request);
    if (record == 0) return 0;
    return player->vfunc_102(record);
}
MS2_REPLACE_METHOD(0x140a635f0, Unk_Inventory, FUN_140a635f0, 650, 0x3575D5E0);
// @0x140a63880
int Unk_Inventory::FUN_140a63880(CItem* item, const CStringW& argument) {
    if (!(item != nullptr && FUN_140527840(item) != nullptr))
        return 0;
    if (FUN_14053cd90(FUN_140527840(item)))
        return FUN_140a61db0(item->FUN_140526a50(), argument);
    return 0;
}
MS2_REPLACE_METHOD(0x140a63880, Unk_Inventory, FUN_140a63880, 108, 0x9F2455BA);
// @0x140a63900
int Unk_Inventory::FUN_140a63900(CItem* item, int mode) {
    if (item == nullptr) return 0;
    return FUN_140a63950(item, FUN_140527a20(item), mode);
}
MS2_REPLACE_METHOD(0x140a63900, Unk_Inventory, FUN_140a63900, 69, 0xD5A0FEBB);
// MS2-FUNCTIONAL: typed accessors; the repeated per-slot equip checks are shared helpers.
// Check of an equipped slot against the item being worn (mask/type from the item data); false blocks the change.
static bool Unk_InventorySlotAllows(const MS2Ptr<Unk_InventoryEquipment>& slot, int mask, int type) {
    if (slot.get() == nullptr) return true;
    if (slot->FUN_1411dc7a0().get() == nullptr) return true;
    MS2Ptr<CItem> worn = slot->FUN_1411dc7a0();
    return FUN_140528980(worn.get()) && FUN_140525e50(worn.get(), mask, type) != 0;
}
static void Unk_InventoryCodiSlotError() {
    FUN_140d73aa0(FUN_14028b8e0(L"s_item_err_codi_slot"), 0, nullptr, L"");
}
// Both slots are worn by different items although the item data requires one combined item.
static bool Unk_InventoryPairMismatch(Unk_InventoryPlayer* player, int slotA, int slotB, int mode) {
    MS2Ptr<Unk_InventoryEquipment> a = player->FUN_141655e80(slotA, mode);
    MS2Ptr<Unk_InventoryEquipment> b = player->FUN_141655e80(slotB, mode);
    if (a.get() != nullptr && b.get() != nullptr && a.get() != b.get()) {
        FUN_141275260(0x43, 1, 1);
        FUN_141276180(DAT_143ab78e8, CString(""));
        return true;
    }
    return false;
}
// @0x140a63950
int Unk_Inventory::FUN_140a63950(CItem* item, int slot, int mode) {
    if (item == nullptr) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    MS2Ptr<CItemData> data(FUN_140527840(item));
    if (!data) return 0;
    if (!FUN_14053c710(data.get())) return 0;
    bool codi = FUN_140166410()->FUN_14036d570(0x8e);
    if (mode == 2) {
        if (!codi || !FUN_14053cf90(data.get())) {
            FUN_140d73aa0(FUN_14028b8e0(L"s_item_err_Invalid_slot_codi"), 0, nullptr, L"");
            return 0;
        }
    } else if (mode == 1) {
        if (!FUN_14053cf90(data.get())) { FUN_140d73bc0(0xd3, 0, nullptr, L""); return 0; }
    }
    int mask = player->FUN_141658e60();
    bool gotoCheck = true;   // false: the combined-slot path ran and jumped past the generic check
    if (mode != 2 && !FUN_14053cf90(data.get())) {
        int type = FUN_14053c620(data.get());
        gotoCheck = false;
        if (!FUN_14053d460(data.get())) {
            if (FUN_14053d2f0(data.get())) {
                MS2Ptr<Unk_InventoryEquipment> head = player->FUN_141655cf0(5);
                if (head.get() != nullptr && head->FUN_1411dc7f0() != nullptr && FUN_14053d460(head->FUN_1411dc7f0())) {
                    FUN_140d73bc0(0xd4, 0, nullptr, L"");
                    return 0;
                }
                if (codi) {
                    MS2Ptr<Unk_InventoryEquipment> codiHead = player->FUN_141655e80(5, 2);
                    if (codiHead.get() != nullptr && codiHead->FUN_1411dc7f0() != nullptr && FUN_14053d460(codiHead->FUN_1411dc7f0())) {
                        Unk_InventoryCodiSlotError();
                        return 0;
                    }
                }
                if (!Unk_InventorySlotAllows(player->FUN_141655cf0(slot), mask, type)) { FUN_140d73bc0(0xd4, 0, nullptr, L""); return 0; }
                if (codi && !Unk_InventorySlotAllows(player->FUN_141655e80(slot, 2), mask, type)) { Unk_InventoryCodiSlotError(); return 0; }
            }
            MS2Ptr<Unk_InventoryEquipment> cur = player->FUN_141655c90(slot);
            if (cur.get() != nullptr && FUN_14053d460(cur->FUN_1411dc7f0())) {
                if (slot == 5) {
                    if (player->FUN_141655cf0(4).get() != nullptr) { FUN_140d73bc0(0xd6, 0, nullptr, L""); return 0; }
                    if (codi && player->FUN_141655e80(4, 2).get() != nullptr) { FUN_140d73bc0(0xd6, 0, nullptr, L""); return 0; }
                } else if (slot == 4) {
                    if (player->FUN_141655cf0(5).get() != nullptr) { FUN_140d73bc0(0xd6, 0, nullptr, L""); return 0; }
                    if (codi && player->FUN_141655e80(5, 2).get() != nullptr) { FUN_140d73bc0(0xd6, 0, nullptr, L""); return 0; }
                }
            }
        } else {
            if (!Unk_InventorySlotAllows(player->FUN_141655cf0(5), mask, type)) { FUN_140d73bc0(0xd4, 0, nullptr, L""); return 0; }
            if (!Unk_InventorySlotAllows(player->FUN_141655cf0(4), mask, type)) { FUN_140d73bc0(0xd4, 0, nullptr, L""); return 0; }
            if (codi) {
                if (!Unk_InventorySlotAllows(player->FUN_141655e80(5, 2), mask, type)) { Unk_InventoryCodiSlotError(); return 0; }
                if (!Unk_InventorySlotAllows(player->FUN_141655e80(4, 2), mask, type)) { Unk_InventoryCodiSlotError(); return 0; }
            }
        }
    }
    if (gotoCheck && FUN_14053d2f0(data.get())) {
        int result = reinterpret_cast<PC*>(player)->vfunc_132(item, slot, mode == 2);
        if (FUN_140525e50(item, mask, result) == 0) { FUN_140d73bc0(0xd2, 0, nullptr, L""); return 0; }
    }
    if (FUN_140a61430(FUN_140a617f0(ItemPtr(item))) == 0) {
        int pairMode = FUN_14053cf90(data.get()) ? 1 : 0;
        if (codi && FUN_14052a170(item) == 2) pairMode = 2;
        if (FUN_14053d460(data.get()) && Unk_InventoryPairMismatch(player, 4, 5, pairMode)) return 0;
        if (FUN_14053d2b0(data.get()) && Unk_InventoryPairMismatch(player, 8, 9, pairMode)) return 0;
    }
    if (FUN_140525f10(item) != 0) {
        Unk_InventoryBlockRef block;
        FUN_140a2f620(FUN_140a6a830(), &block, 4);
        if (FUN_1401cb3d0(&block) != nullptr) { FUN_140a2ff20(&block, 4, 0); return 0; }
    }
    return 1;
}
// MS2-FUNCTIONAL: equivalent validation with early-return spelling.
// @0x140a655b0
int Unk_Inventory::FUN_140a655b0(CItem* item) {
    if (item == nullptr) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    MS2Ptr<CItemData> data(FUN_140527840(item));
    if (!data) return 0;
    if (player->FUN_14166ce30() != 0) { FUN_140d73bc0(66, 0, nullptr, L""); return 0; }
    if (FUN_140a61430(FUN_140a617f0(ItemPtr(item))) == 0) {
        FUN_141275260(67, 1, 1);
        FUN_141276180(s_warningBag, CString(""));
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140a655b0, Unk_Inventory, FUN_140a655b0, 438, 0xBDCB1A31);
// MS2-FUNCTIONAL: equivalent validation with early-return spelling.
// @0x140a65770
int Unk_Inventory::FUN_140a65770(CItem* item) {
    if (item == nullptr) return 11;
    CItemData* data = FUN_140527840(item);
    if (data == nullptr) return 11;
    if (FUN_140528930(item) && !FUN_14053cde0(data)) return 5;
    int result = FUN_140a65860(MS2Ptr<CItemData>(data), item->FUN_140526bd0());
    if (result == 0) {
        if (!FUN_140528980(item)) return 10;
        return 0;
    }
    return result;
}
MS2_REPLACE_METHOD(0x140a65770, Unk_Inventory, FUN_140a65770, 220, 0x8761E71D);
// MS2-FUNCTIONAL: equivalent validation with typed player virtual and early returns.
// @0x140a65860
int Unk_Inventory::FUN_140a65860(MS2Ptr<CItemData> data, int) {
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr || data == nullptr) return 11;
    if (FUN_14053ce20(data.operator->()) && player->FUN_141658f30() == 0) return 6;
    if (FUN_14053c940(data.operator->(), player->FUN_141658e60()) == 0) return 2;
    if (FUN_14053c8e0(data.operator->(), player->FUN_141654700()) == 0) return 3;
    if (FUN_14053c9a0(data.operator->(), (unsigned short)player->vfunc_78()) == 0) return 1;
    if (FUN_14053d1f0(data.operator->()) && player->FUN_141662de0() == 0) return 7;
    if (FUN_14053d210(data.operator->()) && !FUN_1409eed90()->FUN_141b89990()) return 7;
    if (FUN_14053ce40(data.operator->())) {
        unsigned short level = FUN_14053dc40(data.operator->());
        int skill = FUN_14053dc20(data.operator->());
        if (player->FUN_141523bc0()->FUN_141768fb0(skill, level) != 0) return 9;
    }
    return 0;
}
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a65b70
int FUN_140a65b70() {
    Unk_InventoryDialog* dialog = FUN_1405344f0(20013);
    if (dialog == nullptr) return -1;
    return dialog->FUN_141999de0();
}
MS2_REPLACE(0x140a65b70, FUN_140a65b70, 54, 0x9D821E3C);
// MS2-FUNCTIONAL: equivalent error paths and packet arguments.
// @0x140a65bb0
int Unk_Inventory::FUN_140a65bb0(CItem* item) {
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr || item == nullptr || FUN_140527840(item) == nullptr) {
        FUN_140d73bc0(2135, 0, nullptr, L""); return 0;
    }
    if (FUN_14053c5c0(FUN_140527840(item)) != 24) { FUN_140d73bc0(2135, 0, nullptr, L""); return 0; }
    unsigned short level = FUN_14053dc40(FUN_140527840(item));
    int skill = FUN_14053dc20(FUN_140527840(item));
    if (player->FUN_141523bc0()->FUN_141768fb0(skill, level) != 0) { FUN_140d73bc0(2136, 0, nullptr, L""); return 0; }
    COutPacket packet(19, 0);
    packet.Encode1(1);
    packet.Encode8(item->FUN_140526a50());
    FUN_140710590(packet);
    return 1;
}
MS2_REPLACE_METHOD(0x140a65bb0, Unk_Inventory, FUN_140a65bb0, 628, 0x3B4AB7C0);
// MS2-FUNCTIONAL: equivalent error dispatch using constant string statics.
// @0x140a65e30
int Unk_Inventory::FUN_140a65e30(CItem* item) {
    int error = FUN_140a65770(item);
    if (error == 1) {
        FUN_141276180(s_warningLevel, CString("")); FUN_140d73bc0(224, 0, nullptr, L""); return 1;
    }
    if (error == 2) {
        FUN_141276180(s_warningGender, CString("")); FUN_140d73bc0(45, 0, nullptr, L""); return 1;
    }
    if (error == 3) {
        FUN_141276180(s_warningClass, CString(""));
        if (FUN_14053cbc0(FUN_140527840(item))) FUN_140d73bc0(232, 0, nullptr, L"");
        else FUN_140d73bc0(233, 0, nullptr, L"");
        return 1;
    }
    if (error == 5) { FUN_140d73bc0(225, 0, nullptr, L""); return 1; }
    if (error == 6) { FUN_140d73bc0(226, 0, nullptr, L""); return 1; }
    if (error == 7) { FUN_140d73aa0(FUN_14028b8e0(L"s_item_err_puton_vip"), 0, nullptr, L""); return 1; }
    if (error == 10) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140a65e30, Unk_Inventory, FUN_140a65e30, 896, 0x74FFD74C);
// @0x140a661e0
int Unk_Inventory::FUN_140a661e0(CItem*) { return 1; }
MS2_REPLACE_METHOD(0x140a661e0, Unk_Inventory, FUN_140a661e0, 16, 0x32804D89);

// Not hooked: constructs a TOutBindingParam with DLL-local RTTI.
// MS2-FUNCTIONAL: typed binding result and character-set iterators.
#ifndef MS2_HOOK_DLL
// @0x140a66200
int Unk_Inventory::FUN_140a66200(CItem* item, int* reason, CStringW& name) {
    *reason = 1;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr || player->FUN_14166ce30() != 0) return 0;
    Unk_InventoryBinding* binding = FUN_140527930(item);
    if (binding == nullptr) return 0;
    CStringW unused;
    ItemUtilTransfer::TOutBindingParam output;
    __int64 character = player->FUN_141656a80();
    if (FUN_1406344b0(ItemPtr(item), &character, &output)) return 1;
    name = output.name;
    bool allowed = FUN_1401c0d90()->FUN_140a6a0d0() && FUN_1405258b0(item) != 0;
    bool enchanted = FUN_1405279c0(item)->FUN_1406210e0();
    if (allowed && enchanted) { *reason = 2; return 0; }
    if (allowed) return 1;
    __int64 owner = output.characterId;
    if (owner != 0) {
        Unk_InventoryCharacterIterator end = DAT_143ab2a30.FUN_140341f40();
        Unk_InventoryCharacterIterator found = DAT_143ab2a30.FUN_1404c0270(owner);
        if (!FUN_1403344a0(found, end)) {
            if (output.kind == 1) *reason = 4;
            else if (output.kind == 2) *reason = 5;
        } else {
            if (output.kind == 1) *reason = 3;
            else if (output.kind == 2) *reason = 2;
        }
    }
    return 0;
}
#endif

// MS2-FUNCTIONAL: indexed typed setting selection replaces the duplicated switch body.
// @0x140a66510
int FUN_140a66510(int category) {
    int count = 48;
    if (FUN_140166410()->FUN_14036d570(116)) {
        Unk_InventoryArraySetting* setting = nullptr;
        static const int indices[] = {0,1,2,3,5,6,7,11,4,8,10,12,13,14,15};
        if (category >= 0 && category < 15) setting = &FUN_1401d3200()->bagLimits[indices[category]];
        else MS2_ASSERT_AT(2333, 0);
        if (setting != nullptr) {
            const std::vector<int>& values = setting->FUN_140a6aa40();
            if (values.size() != 0) count = values[0];
        }
    }
    return count;
}
MS2_REPLACE(0x140a66510, FUN_140a66510, 499, 0x76FF035D);
// MS2-FUNCTIONAL: indexed typed setting selection replaces the duplicated switch body.
// @0x140a66750
int FUN_140a66750(unsigned category) {
    int count = 48;
    if (FUN_140166410()->FUN_14036d570(116)) {
        Unk_InventoryArraySetting* setting = nullptr;
        static const int indices[] = {0,1,2,3,5,6,7,11,4,8,10,12,13,14,15};
        if (category < 15) setting = &FUN_1401d3200()->bagLimits[indices[category]];
        else MS2_ASSERT_AT(2406, 0);
        if (setting != nullptr) {
            const std::vector<int>& values = setting->FUN_140a6aa40();
            if (values.size() > 1) count = values[1];
        }
    }
    return count;
}
MS2_REPLACE(0x140a66750, FUN_140a66750, 503, 0x0D527D0B);
// MS2-FUNCTIONAL: typed ATL map traversal.
// @0x140a66990
void Unk_Inventory::FUN_140a66990(unsigned short level) {
    if (FUN_140166410()->FUN_14036d570(232) && FUN_140a67000() != 0) {
        ATL::CAtlMap<Unk_InventoryEquipSlot, ItemPtr> candidates;
        FUN_140a66ca0(candidates, level);
        for (POSITION pos = candidates.GetStartPosition(); pos != nullptr; candidates.GetNext(pos)) {
            ItemPtr item = candidates.GetValueAt(pos);
            if (item.get() != nullptr) FUN_140a66ae0(item);
        }
    }
}
MS2_REPLACE_METHOD(0x140a66990, Unk_Inventory, FUN_140a66990, 328, 0xA98001E1);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a66ae0
void Unk_Inventory::FUN_140a66ae0(ItemPtr item) {
    if (FUN_140a67020(item) != 0) {
        if (FUN_140a66f20() == 0) {
            if (FUN_140a62270(item.get(), 0, 0, 0) != 0) FUN_140a66f40(item->FUN_140526a50());
        } else FUN_140a673e0(item);
    }
}
MS2_REPLACE_METHOD(0x140a66ae0, Unk_Inventory, FUN_140a66ae0, 276, 0x03FB783B);
// @0x140a66c00
void Unk_Inventory::FUN_140a66c00() {
    if (Unk_LockGuard guard = lock) {} else {
        pendingItem = 0;
        autoEquipQueue.RemoveAll();
        excludedItems.RemoveAll();
        autoEquipEnabled = FUN_140166410()->FUN_14036d570(232);
    }
}
MS2_REPLACE_METHOD(0x140a66c00, Unk_Inventory, FUN_140a66c00, 154, 0x80D2AB72);
// MS2-FUNCTIONAL: typed map and equipment-pointer access.
// @0x140a66ca0
void Unk_Inventory::FUN_140a66ca0(ATL::CAtlMap<Unk_InventoryEquipSlot, ItemPtr>& result, unsigned short level) {
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player != nullptr) {
        ItemArray candidates;
        FUN_140a60880(0, candidates);
        for (size_t i = 0; i < candidates.GetCount(); ++i) {
            ItemPtr item = candidates[i];
            if (item.get() == nullptr) continue;
            if (FUN_140a67390(item->FUN_140526a50())) continue;
            Unk_InventoryEquipSlot slot = (Unk_InventoryEquipSlot)FUN_140527a20(item.operator->());
            int mode = FUN_14052a170(item.operator->());
            if (mode != 0) continue;
            if (!(player->FUN_141655e80(slot, 0) == nullptr)) continue;
            if (level != 0 && (unsigned)level != FUN_1405282d0(item.operator->())) continue;
            ItemPtr old;
            result.Lookup(slot, old);
            if (old.get() == nullptr) result.SetAt(slot, item);
            else {
                int score = FUN_140529070(old.operator->());
                if (score < FUN_140529070(item.operator->())) result.SetAt(slot, item);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140a66ca0, Unk_Inventory, FUN_140a66ca0, 630, 0x75F56A63);
// @0x140a66f20
__int64 Unk_Inventory::FUN_140a66f20() { return pendingItem; }
MS2_REPLACE_METHOD(0x140a66f20, Unk_Inventory, FUN_140a66f20, 18, 0x20724D67);
// @0x140a66f40
void Unk_Inventory::FUN_140a66f40(__int64 id) {
    if (Unk_LockGuard guard = lock) {} else { pendingItem = id; }
}
MS2_REPLACE_METHOD(0x140a66f40, Unk_Inventory, FUN_140a66f40, 90, 0xB23A5279);
// @0x140a66fa0
void Unk_Inventory::FUN_140a66fa0(int enabled) {
    if (Unk_LockGuard guard = lock) {} else { autoEquipEnabled = enabled; }
}
MS2_REPLACE_METHOD(0x140a66fa0, Unk_Inventory, FUN_140a66fa0, 87, 0xEFEB9F60);
// @0x140a67000
int Unk_Inventory::FUN_140a67000() { return autoEquipEnabled; }
MS2_REPLACE_METHOD(0x140a67000, Unk_Inventory, FUN_140a67000, 17, 0xD08230F1);
// MS2-FUNCTIONAL: typed player virtual and constant-setting access.
// @0x140a67020
int Unk_Inventory::FUN_140a67020(ItemPtr item) {
    if (item == nullptr) return 0;
    if (!FUN_140166410()->FUN_14036d570(232)) return 0;
    if (FUN_140a67000() == 0) return 0;
    __int64 id = item->FUN_140526a50();
    if (!FUN_14053cbc0(FUN_140527840(item.operator->()))) return 0;
    if (!FUN_140a5d680(id)) return 0;
    if (FUN_140a67390(id)) return 0;
    Unk_InventoryPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == nullptr) return 0;
    unsigned short level = (unsigned short)player->vfunc_78();
    if (*FUN_1401d3200()->autoEquipMinLevel.FUN_1401d7c10() > (unsigned)level) return 0;
    if ((unsigned)level > *FUN_1401d3200()->autoEquipMaxLevel.FUN_1401d7c10()) return 0;
    int slot = FUN_140527a20(item.operator->());
    if (FUN_14052a170(item.operator->()) != 0) return 0;
    if (player->FUN_141655e80(slot, 0) == nullptr) {
        if (FUN_140a65770(item.get()) == 0) return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140a67020, Unk_Inventory, FUN_140a67020, 869, 0x5B763EAC);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a67390
bool Unk_Inventory::FUN_140a67390(__int64 id) { return excludedItems.Find(id, nullptr) != nullptr; }
MS2_REPLACE_METHOD(0x140a67390, Unk_Inventory, FUN_140a67390, 60, 0xA7CD9978);
// @0x140a673e0
void Unk_Inventory::FUN_140a673e0(ItemPtr item) {
    if (item == nullptr) return;
    if (FUN_140a67020(item) == 0) return;
    if (Unk_LockGuard guard = lock) {} else { autoEquipQueue.AddTail(item); }
}
MS2_REPLACE_METHOD(0x140a673e0, Unk_Inventory, FUN_140a673e0, 204, 0xFEF46B0C);
// @0x140a674c0
void Unk_Inventory::FUN_140a674c0(ItemPtr item) {
    if (item == nullptr) return;
    if (!FUN_140166410()->FUN_14036d570(232)) return;
    if (Unk_LockGuard guard = lock) {} else {
        if (excludedItems.Find(item->FUN_140526a50(), nullptr) == nullptr)
            excludedItems.AddTail(item->FUN_140526a50());
    }
}
MS2_REPLACE_METHOD(0x140a674c0, Unk_Inventory, FUN_140a674c0, 243, 0xD2BF86FC);
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a675c0
void Unk_Inventory::FUN_140a675c0() {
    if (FUN_140166410()->FUN_14036d570(232) && autoEquipQueue.GetCount() != 0 && FUN_140a66f20() == 0) {
        ItemPtr item = autoEquipQueue.GetHead();
        if (item.get() != nullptr) FUN_140a66ae0(item);
        if (Unk_LockGuard guard = lock) {} else { autoEquipQueue.RemoveHead(); }
    }
}
MS2_REPLACE_METHOD(0x140a675c0, Unk_Inventory, FUN_140a675c0, 304, 0xA41E7464);

// @0x140a69aa0
Unk_InventoryUsePacket::Unk_InventoryUsePacket() : id(0), argument(L"") {}
// @0x140a69c20
Unk_InventoryUnequipPacket::Unk_InventoryUnequipPacket() : id(0) {}
// @0x140a69c40
Unk_InventoryEquipPacket::Unk_InventoryEquipPacket() : id(0), slot(0), mode(3) {}
// @0x140a69c70
ItemUtilTransfer::TOutBindingParam::TOutBindingParam() : kind(0), characterId(0) {}
// @0x140a69df0
Unk_InventoryUsePacket::~Unk_InventoryUsePacket() {}
// MS2-FUNCTIONAL: typed accessors and equivalent control flow produce different temporaries.
// @0x140a69eb0
ItemUtilTransfer::TOutBindingParam::~TOutBindingParam() {}
// @0x140a6a0d0
bool Unk_InventoryAccount::FUN_140a6a0d0() { return flag; }
// @0x140a6a830
Unk_InventoryStateManager* FUN_140a6a830() { return DAT_143ab5cc8; }
// @0x140a6a840
Unk_InventoryListener* FUN_140a6a840() { return DAT_143ab7908; }

// @0x140a6aa40
const std::vector<int>& Unk_InventoryArraySetting::FUN_140a6aa40() {
    if (!initialized) FUN_1402b7560(this, "constants is not set");
    return values;
}

MS2_EMIT_CRT_MEMMOVE_S();
