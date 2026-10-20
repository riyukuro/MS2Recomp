// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldMapManager and the UIWorldMap records (see
// worldmapmanager.h and placeholder/uiworldmap.h). No __FILE__ in the range: the unit name is guessed from the class.
// Function bodies follow the exe (cross-checked with the v2525 snapshot work/ext/v2525 src/ms2/tu/141b94a70.cpp).
// MS2-UNIT: ?\worldmapmanager.cpp
// MS2-RANGE: 0x141b94cb0-0x141bb1490 .text$mn
// MS2-RANGE: 0x140120010-0x140120210 .text$di
// MS2-RANGE: 0x142cc3970-0x142cc3a60 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strIconPath@@YAXXZ 0x140120010 ; probe
// MS2-PIN: ??__Es_strItemGrade@@YAXXZ 0x140120040 ; probe
// MS2-PIN: ??__Es_strItemSkin@@YAXXZ 0x140120070 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x140120160 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x140120190 ; probe
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141b9c7f0 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141b9c820 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141b9c850 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@V?$Unk_BmBoxPtr@USpecialNPCInfo@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$Unk_BmBoxPtr@USpecialNPCInfo@@@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141b9c880 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141b9c8e0 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141b9c910 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141b9cf70 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141b9cfc0 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141b9d010 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141b9d0b0 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141b9d100 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141b9d150 ; prop
// MS2-PIN: ??$_Emplace_back@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@QEAAX$$QEAV?$MS2Ptr@VMapTile@UIWorldMap@@@@@Z 0x141b9e3a0 ; prop
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141b9ea70 ; order
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141b9eb90 ; order
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141b9ec20 ; order
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141b9ecb0 ; order
// MS2-PIN: ??$_Kfn@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@?$_Tmap_traits@HV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@@3@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@1@@Z 0x141ba7ec0 ; order
// MS2-PIN: ??$_Kfn@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@?$_Tmap_traits@HV?$MS2Ptr@VIconInfo@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@@3@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@1@@Z 0x141ba7ed0 ; order
// MS2-PIN: ??$_Kfn@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@?$_Tmap_traits@HV?$MS2Ptr@VMapTile@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@3@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@1@@Z 0x141ba7ee0 ; order
// MS2-PIN: ??$_Kfn@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@1@@Z 0x141ba7ef0 ; order
// MS2-PIN: ??$_Kfn@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@?$_Tmap_traits@IV?$MS2Ptr@VEventIconInfo@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@@3@$0A@@std@@SAAEBIAEBU?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@1@@Z 0x141ba7f00 ; order
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@PEAX@1@AEBH@Z 0x141ba7f20 ; order
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VIconInfo@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@1@AEBH@Z 0x141ba7fc0 ; order
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VMapTile@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@1@AEBH@Z 0x141ba8060 ; order
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@PEAX@1@AEBH@Z 0x141ba8100 ; order
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VEventIconInfo@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@PEAX@1@AEBI@Z 0x141ba81a0 ; order
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@1@AEBI@Z 0x141ba8240 ; order
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VMapTile@UIWorldMap@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@1@AEBI@Z 0x141ba82e0 ; order
// MS2-PIN: ??$_Move_backward_unchecked1@PEAV?$Unk_BmBoxPtr@USpecialNPCInfo@@@@PEAV1@@std@@YAPEAV?$Unk_BmBoxPtr@USpecialNPCInfo@@@@PEAV1@00U_General_ptr_iterator_tag@0@@Z 0x141ba88b0 ; unique
// MS2-PIN: ??$_Pass_fn@P6A_NAEBV?$MS2Ptr@VMapTile@UIWorldMap@@@@0@Z$0A@@std@@YAP6A_NAEBV?$MS2Ptr@VMapTile@UIWorldMap@@@@0@ZP6A_N00@Z@Z 0x141ba98a0 ; prop
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$MS2Ptr@VDungeonRoom@@@@PEAV1@V?$allocator@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@YAPEAV?$MS2Ptr@VDungeonRoom@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VDungeonRoom@@@@@0@@Z 0x141bab040 ; prop
// MS2-PIN: ??$addressof@H@std@@YAPEAHAEAH@Z 0x141bab310 ; order
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bab330 ; order
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bab350 ; order
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bab360 ; order
// MS2-PIN: ??$construct@PEAU?$_Tree_node@HPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAPEAU?$_Tree_node@HPEAX@1@AEAPEAU31@@Z 0x141bab440 ; order
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x141bab490 ; order
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x141bab580 ; order
// MS2-PIN: ??$construct@V?$Unk_BmBoxPtr@USpecialNPCInfo@@@@AEBV1@@?$_Default_allocator_traits@V?$allocator@V?$Unk_BmBoxPtr@USpecialNPCInfo@@@@@std@@@std@@SAXAEAV?$allocator@V?$Unk_BmBoxPtr@USpecialNPCInfo@@@@@1@QEAV?$Unk_BmBoxPtr@USpecialNPCInfo@@@@AEBV3@@Z 0x141babbf0 ; prop
// MS2-PIN: ??$construct@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@1@QEAV?$MS2Ptr@VMapTile@UIWorldMap@@@@$$QEAV3@@Z 0x141babc40 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@PEAX@1@@Z 0x141babca0 ; order
// MS2-PIN: ?_Adopt@_Iterator_base0@std@@QEAAXPEBX@Z 0x141babcd0 ; order
// MS2-PIN: ?__empty_global_delete@@YAXPEAX_K@Z 0x141babce0 ; order
// MS2-PIN: ??$destroy@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@1@@Z 0x141babcf0 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@1@@Z 0x141babd10 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@1@@Z 0x141babd50 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@1@@Z 0x141babd70 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@1@@Z 0x141babd90 ; prop
// MS2-PIN: ??$destroy@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@std@@@?$_Default_allocator_traits@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@std@@@1@QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@1@@Z 0x141babdb0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bac3a0 ; order
// MS2-PIN: ??0?$TSingleton@VWorldMapManager@@@@QEAA@XZ 0x141bacc90 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141baccc0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VIconInfo@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141baccf0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VMapTile@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bacd20 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bacd50 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bacd80 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VMapTile@UIWorldMap@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x141bacde0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VIconInfo@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bace50 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VMapTile@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bace90 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141baced0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VEventIconInfo@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x141bacf10 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x141bacf50 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VMapTile@UIWorldMap@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x141bacf90 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bad910 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bad920 ; prop
// MS2-PIN: ??0?$allocator@V?$Unk_BmBoxPtr@USpecialNPCInfo@@@@@std@@QEAA@XZ 0x141bad930 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bad940 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bad950 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bad960 ; prop
// MS2-PIN: ??0?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@std@@@std@@QEAA@XZ 0x141bad970 ; unique
// MS2-PIN: ??0?$map@HV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@@3@@std@@QEAA@XZ 0x141bad9a0 ; unique
// MS2-PIN: ??0?$map@HV?$MS2Ptr@VIconInfo@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@@3@@std@@QEAA@XZ 0x141bad9d0 ; unique
// MS2-PIN: ??0?$map@HV?$MS2Ptr@VMapTile@UIWorldMap@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@3@@std@@QEAA@XZ 0x141bada00 ; unique
// MS2-PIN: ??0?$map@HV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@@2@@std@@QEAA@XZ 0x141bada30 ; unique
// MS2-PIN: ??0?$map@IV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@@3@@std@@QEAA@XZ 0x141bada90 ; unique
// MS2-PIN: ??0?$map@IV?$MS2Ptr@VMapTile@UIWorldMap@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@3@@std@@QEAA@XZ 0x141badac0 ; unique
// MS2-PIN: ??1IconInfo@UIWorldMap@@UEAA@XZ 0x141bae4d0 ; unique
// MS2-PIN: ??_G?$pair@$$CBHV?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@@std@@QEAAPEAXI@Z 0x141bb0000 ; prop
// MS2-PIN: ??_G?$pair@$$CBHV?$MS2Ptr@VIconInfo@UIWorldMap@@@@@std@@QEAAPEAXI@Z 0x141bb0040 ; prop
// MS2-PIN: ??_G?$pair@$$CBIV?$MS2Ptr@VEventIconInfo@@@@@std@@QEAAPEAXI@Z 0x141bb00c0 ; prop
// MS2-PIN: ??_G?$pair@$$CBIV?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@@std@@QEAAPEAXI@Z 0x141bb0100 ; prop
// MS2-PIN: ??_G?$pair@$$CBIV?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@QEAAPEAXI@Z 0x141bb0140 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAAPEAVCPair@12@PEB_W@Z 0x141bb0940 ; unique
// MS2-PIN: ??__Fs_strIconPath@@YAXXZ 0x142cc3970 ; probe
// MS2-PIN: ??__Fs_strItemGrade@@YAXXZ 0x142cc3990 ; probe
// MS2-PIN: ??__Fs_strItemSkin@@YAXXZ 0x142cc39b0 ; probe
// MS2-PIN: ??__Fs_strSkill@@YAXXZ 0x142cc3a00 ; probe
// MS2-PIN: ??__Fs_strStun@@YAXXZ 0x142cc3a20 ; probe
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include "worldmapmanager.h"
#include <algorithm>
#include <stdlib.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/commonfiles/continentregiontable.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/jobconditiontable.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/npcdatacli.h"
#include "ms2/client/ms2/gameeventcli.h"
#include "ms2/client/ms2/rewardpreviewitem.h"
#include "ms2/client/ms2/pcbase.h"
#include <efd/Matrix3.h>
#include <efd/Point3.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#pragma intrinsic(abs)

// ---- statics of the unit's headers (.text$di 0x140120010-0x1401201c0; the next two, the key input controller and the
// WorldService class info, belong to worldservice.cpp) ----

static CString s_strIconPath = "iconPath";                                  // 0x143af8208
static CString s_strItemGrade = "itemGrade";                                // 0x143af8168
static CString s_strItemSkin = "itemSkin";                                  // 0x143af81b8
static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 0x143af8130
static CString s_strSkill = "skill";                                        // 0x143af8128
static CString s_strStun = "stun";                                          // 0x143af8120
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);           // 0x143af8170

// ---- unit-local views of unrecovered callees ----

class Unk_WmLoader { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_WmLoader* FUN_140166420();
CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const CString& strArg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);       // Table/<file>
unsigned char FUN_1401d1320(CCacheData* p);                                 // file changed since load
Unk_140165cf0* FUN_14028f8d0(Unk_140165cf0* pNode);                         // the first child element
bool FUN_14028f710(Unk_140165cf0* pNode);                                   // the node is enabled (feature/locale)
CString FUN_14015f710(Unk_140165cf0* pNode, const char* pszName, CString strDefault);   // an attribute (default by value)
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& rOut);
int FUN_140873220(Unk_140165cf0* pNode, const char* pszName, unsigned& rOut);
int FUN_1408736d0(Unk_140165cf0* pNode, const char* pszName, bool& rOut);
int FUN_140873890(Unk_140165cf0* pNode, const char* pszName, int& rOut);   // an enum attribute
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& rOut);
int FUN_140873ad0(Unk_140165cf0* pNode, const char* pszName, CString& rOut);
int FUN_140d01040(CString& strAlign);                                       // text alignment from its name
void FUN_140177de0(const CString& str, ATL::CAtlArray<int>& out, const char* pszSep);   // split a list of ints
char* FUN_1401d3200();                                                      // the game constants
int* FUN_1402056b0(char* pValue);                                           // an int constant
char* FUN_1401d31f0();                                                      // the path constants (+0xd0 world map images)
Unk_FieldIdListMap& FUN_141b69360(CFieldMetaTable* pTable);                 // field -> npcs (uiworldmapdialog.cpp)
Unk_FieldIdListPtr& FUN_141b695b0(Unk_FieldIdListMap* pMap, POSITION pos);  // CAtlMap::GetValueAt (uiworldmapdialog.cpp)
void FUN_140c956e0(Unk_FieldIdListMap* pMap, POSITION& pos);                // CAtlMap::GetNext (questnavigation.cpp)
CContinentRegionTable* FUN_1403782c0();
QuestDataTable* FUN_1407476c0();
DungeonRoomTable* FUN_14031c2a0();
CStringTable* FUN_1401a9d70();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
int FUN_14074b030(CQuestData* pQuest);                                      // the quest id
int FUN_14074b050(CQuestData* pQuest);                                      // the quest type
bool FUN_140764040(CQuestData* pQuest);
bool FUN_140764080(CQuestData* pQuest);
bool FUN_1407640c0(CQuestData* pQuest);
bool FUN_14031e720(unsigned short nRequired, unsigned short nLevel);        // the level suits the dungeon
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);                                 // the npc table row
NpcDataTableCli* FUN_1406d6e90();
CStringW FUN_1401aa6a0(int nNpcId);                                         // the npc name
CStringW FUN_140e14b70(MS2Ptr<DungeonRoom> spRoom);                         // the dungeon name
int FUN_14083fec0(CStringW str, CStringW strFind);                          // the index of a substring (-1)
CStringW FUN_14028b8e0(const CStringW& strKey);                             // a common string
CStringW FUN_14028de60(int nKey);                                           // a common string by id
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a1, const CStringW& a2);   // "{0}" formatting
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a1);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& a1);               // a formatted string table text
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a1, const CStringW& a2);
CStringW FUN_140f02bd0(CStringW strKey, const CStringW& a1, const unsigned short& a2, const CStringW& a3);
CStringW FUN_140b99450(CStringW strKey, const CStringW& a1, const unsigned& a2);
CStringW FUN_140f48210(int nHour, int nMinute);                             // "hh:mm"
CStringW FUN_140b8e910(const CMsTime& time);                                // the date text of a time
__int64 FUN_140869440();                                                    // the server time
CStringW FUN_14016a730(const char* psz, int nCodePage);                     // widen a string
class Unk_WmTextFilter { public: void FUN_1416fb340(CStringW& str); };       // colours the reserved words
Unk_WmTextFilter* FUN_1403b4750();
class Unk_WmFishing { public: CStringW FUN_140cdc000(unsigned nFieldId); }; // the fishing spot text of a field
Unk_WmFishing* FUN_140953f20();
class Unk_WmFeatures;
Unk_WmFeatures* FUN_140166410();
bool FUN_14036d570(Unk_WmFeatures* p, int nFeature);
struct Unk_WmWorld;
Unk_WmWorld* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(Unk_WmWorld* pWorld);                                 // the player
CRewardPreviewTable* FUN_140f26650();
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);
void FUN_1418adf60(ASObj* pObj, const char* pszName, AScript value);        // set an object member (value by value)
void FUN_1416e5890(int nQuestId, ATL::CAtlArray<CStringW>& out);           // the mission lines of a quest
void FUN_14092c190(SpecialNPCInfo* pInfo, CInputStream& in);                // SpecialNPCInfo::read
class Unk_WmOptions;
Unk_WmOptions* FUN_14025e7c0();
bool FUN_14116d720(Unk_WmOptions* p);                                       // show every special npc
int FUN_1414738f0(int nChannelGroup);                                       // the level limit of a channel group

// ---- free functions ----

int WorldMapQuestTier(MS2Ptr<CQuestData> spQuest, const int& a, const int& b, const int& c, const int& d);
int WorldMapQuestTier(int nQuestId, const int& a, const int& b, const int& c, const int& d);

// @0x141b94cb0
// The icon group (1..10) of a quest on the world map.
int WorldMapQuestGroup(int nMode, MS2Ptr<CQuestData> spQuest, unsigned short nLevel)
{
    if (spQuest.get())
    {
        if (nMode == 0)
        {
            if (nLevel < (unsigned short)spQuest->m_require.m_level)
                return 10;
            return WorldMapQuestTier(FUN_14074b030(spQuest.operator->()), 6, 7, 8, 9);
        }
        if (nMode == 2)
            return WorldMapQuestTier(FUN_14074b030(spQuest.operator->()), 1, 2, 3, 4);
        if (nMode == 1)
            return 5;
    }
    return 0;
}

// @0x141b94e70
// Tooltip lines: kind ascending, level descending within a kind.
bool WorldMapTooltipLess(const UIWorldMap::TooltipEntry& a, const UIWorldMap::TooltipEntry& b)
{
    if (a.m_4 == b.m_4)
        return (unsigned short)a.m_10 > (unsigned short)b.m_10;
    return a.m_4 < b.m_4;
}

// @0x141b94ef0
UIWorldMap::IconInfo::IconInfo()
{
    m_18 = 0;
}

// @0x141b94fb0
UIWorldMap::DisplaySetting::DisplaySetting()
{
    FUN_141b95000();
}

// @0x141b95000
void UIWorldMap::DisplaySetting::FUN_141b95000()
{
    m_18[0] = 1;
    m_18[1] = 1;
    m_18[2] = 1;
    m_18[3] = 0;
    m_18[4] = 0;
}

// @0x141b95080
// The display filter shows a quest.
int UIWorldMap::DisplaySetting::FUN_141b95080(MS2Ptr<CQuestData> spQuest)
{
    if (!spQuest)
        return 0;
    PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPC == 0)
        return 0;
    if (m_18[3] != 0)
    {
        if (abs(spQuest->m_level - (unsigned short)pPC->vfunc_78()) > 5)
            return 0;
    }
    if (FUN_140764040(spQuest.operator->()))
        return m_18[0];
    if (FUN_140764080(spQuest.operator->()))
        return 1;
    if (FUN_1407640c0(spQuest.operator->()))
        return m_18[2];
    return m_18[1];
}

// @0x141b95270
// The display filter shows a dungeon.
int UIWorldMap::DisplaySetting::FUN_141b95270(MS2Ptr<DungeonRoom> spRoom)
{
    if (!spRoom)
        return 0;
    PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPC == 0)
        return 0;
    bool bSuits = FUN_14031e720(spRoom->m_limitPlayerLevel, (unsigned short)pPC->vfunc_78());
    if (m_18[4] != 0 && !bSuits)
        return 0;
    return 1;
}

// ---- WorldMapManager ----

// @0x141b95380
WorldMapManager::WorldMapManager()
{
    m_78 = 0;
    LoadWorldMapFiles();
    LoadFieldTiles();
}

// @0x141b954d0
WorldMapManager::~WorldMapManager()
{
    m_8.clear();
    m_18.clear();
    m_28.clear();
    m_38.clear();
    m_48.clear();
    m_58.clear();
    m_68.clear();
    m_d8.RemoveAll();
}

bool WorldMapTileLess(const MS2Ptr<UIWorldMap::MapTile>& a, const MS2Ptr<UIWorldMap::MapTile>& b);
int FUN_141b9d850(Unk_140165cf0* pNode, const char* pszName, int* pOut);
void FUN_141bb0380(UIWorldMap::MapTile* pThis, MS2Ptr<UIWorldMap::MapTile> spTile);

// @0x141b95640
int WorldMapManager::LoadWorldMapFiles()
{
    ATL::CAtlArray<CString> names;
    LoadWorldMapNames(names);
    TileGroups customWorlds;
    for (size_t i = 0; i < names.GetCount(); i++)
    {
        CString strPath = FUN_14071a5b0("Table", names[i]);
        MS2Ptr<CCacheData> spCache(new CCacheData);
        spCache->FUN_1401d1160(CString(strPath));
        m_d8.Add(spCache);
        TiXmlDocument doc;
        if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
            continue;
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2worldmap");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2worldmap> {0}]", strPath);
            continue;
        }
        Unk_140165cf0* pGroup = FUN_14028f8d0(pRoot);
        if (pGroup == 0)
            continue;
        for (Unk_140165cf0* pNode = pGroup->FUN_140165cf0("portal"); pNode != 0; pNode = pNode->FUN_140168650("portal"))
        {
            if (!FUN_14028f710(pNode))
                continue;
            unsigned nCode = atoi(FUN_14015f710(pNode, "code", CString("")));
            MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(nCode);
            if (spField == 0)
                continue;
            m_8.insert(nCode);
        }
        for (Unk_140165cf0* pNode = pGroup->FUN_140165cf0("map"); pNode != 0; pNode = pNode->FUN_140168650("map"))
        {
            if (!FUN_14028f710(pNode))
                continue;
            MS2Ptr<UIWorldMap::MapTile> spTile(Unk_BmNewTag(0));
            bool bDefault = false;
            spTile->m_34 = atoi(FUN_14015f710(pNode, "code", CString("")));
            MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(spTile->m_34);
            if (!spField)
                continue;
            spTile->m_38 = WorldOfField(spField->FUN_140375350());
            FUN_1408731e0(pNode, "x", spTile->m_24);
            FUN_1408731e0(pNode, "y", spTile->m_28);
            FUN_1408731e0(pNode, "z", spTile->m_2c);
            FUN_1408731e0(pNode, "size", spTile->m_30);
            FUN_1408736d0(pNode, "type", spTile->m_20);
            FUN_1408736d0(pNode, "public", spTile->m_21);
            FUN_1408736d0(pNode, "default", bDefault);
            FUN_141b9d850(pNode, "tileType", &spTile->m_18);
            FUN_140873220(pNode, "dungeon", reinterpret_cast<unsigned&>(spTile->m_70));
            FUN_140873220(pNode, "quest", reinterpret_cast<unsigned&>(spTile->m_74));
            FUN_1408733e0(pNode, "customContinent", spTile->m_78);
            spTile->m_50 = 0;
            spTile->m_54 = 0;
            spTile->m_58 = 0;
            Unk_FieldIdListPtr spNpcs;
            Unk_FieldIdListMap& npcIndex = FUN_141b69360(CFieldMetaTable::GetInstance());
            if (npcIndex.Lookup(spTile->m_34, spNpcs))
            {
                for (POSITION pos = spNpcs->GetHeadPosition(); pos != 0; spNpcs->GetNext(pos))
                {
                    int nNpcId = spNpcs->GetAt(pos);
                    MS2Ptr<CNpcData> spNpc = FUN_1406cd330(nNpcId);
                    if (spNpc.get())
                    {
                        if (spNpc->GetKind() == 0x55)
                        {
                            CJobConditionTable::NpcJobDataPtr spGate = CJobConditionTable::GetInstance()->GetData(nNpcId);
                            if (spGate.get() && spGate->m_nMoveFieldId != 0)
                            {
                                MS2Ptr<CFieldDataCli> spTarget = CFieldDataCli::Find(spGate->m_nMoveFieldId);
                                if (spTarget)
                                {
                                    spTile->m_54 = 1;
                                    spTile->m_58 = spGate->m_nMoveFieldId;
                                }
                            }
                        }
                    }
                }
            }
            spTile->m_24 = spTile->m_24 + *FUN_1402056b0(FUN_1401d3200() + 0x3418);
            spTile->m_28 = spTile->m_28 + *FUN_1402056b0(FUN_1401d3200() + 0x3470);
            CString strImage;
            strImage.Format("%s%08d.png", (const char*)*reinterpret_cast<CString*>(FUN_1401d31f0() + 0xd0), spTile->m_34);
            CString strGreyImage;
            strGreyImage.Format("%sG_%08d.png", (const char*)*reinterpret_cast<CString*>(FUN_1401d31f0() + 0xd0), spTile->m_34);
            spTile->m_40 = strImage;
            spTile->m_48 = strGreyImage;
            if (spTile->m_78.GetLength() == 0)
            {
                m_18[spTile->m_38].push_back(spTile);
            }
            else
            {
                ATL::CAtlArray<int> worlds;
                FUN_140177de0(spTile->m_78, worlds, ",");
                for (size_t j = 0; j < worlds.GetCount(); j++)
                    customWorlds[worlds[j]].push_back(spTile);
            }
            m_48[spTile->m_34] = spTile;
            if (bDefault)
                m_58[spField->FUN_140375350()] = spTile;
        }
    }
    for (TileGroups::iterator it = customWorlds.begin(); it != customWorlds.end(); ++it)
    {
        for (size_t i = 0; i < it->second.size(); i++)
        {
            MS2Ptr<UIWorldMap::MapTile> spTile(Unk_BmNewTag(0));
            FUN_141bb0380(spTile.operator->(), MS2Ptr<UIWorldMap::MapTile>(it->second[i]));
            spTile->m_38 = it->first;
            m_18[it->first].push_back(spTile);
        }
    }
    for (TileGroups::iterator it = m_18.begin(); it != m_18.end(); it++)
    {
        std::sort(it->second.begin(), it->second.end(), WorldMapTileLess);
        int nOrder = 1;
        for (size_t i = 0; i < it->second.size(); i++)
        {
            if (it->second[i]->m_18 != 3)
            {
                it->second[i]->m_1c = nOrder;
                nOrder++;
            }
        }
    }
    LoadFieldNameInfo();
    return 1;
}

// @0x141b96690
int WorldMapManager::LoadFieldTiles()
{
    std::vector<MS2Ptr<CFieldData> > rows;
    CFieldData::FUN_140374090(rows);
    for (MS2Ptr<CFieldData>& spRow : rows)
    {
        MS2Ptr<UIWorldMap::FieldSearchInfo> spInfo(Unk_BmNewTag(0));
        unsigned nId = spRow->m_nFieldID;
        spInfo->m_18 = nId;
        spInfo->m_20 = FUN_1401a9d70()->FUN_141811980(3, nId);
        spInfo->m_2c = spRow->m_nContinentCode;
        spInfo->m_2c = spRow->m_bMapSearch;
        unsigned nMapped = 0;
        if (CFieldMetaTable::GetInstance()->FUN_1406fc110(nId, &nMapped) == 0)
            spInfo->m_28 = nId;
        else
            spInfo->m_28 = nMapped;
        MS2Ptr<UIWorldMap::MapTile> spTile = GetInstance()->FindMapTileByKey(spInfo->m_28);
        if (!spTile || !spRow->m_bMapSearch)
            continue;
        m_68[nId] = spInfo;
    }
    return 1;
}

// @0x141b96930
int WorldMapManager::LoadFieldNameInfo()
{
    if (m_48.empty())
        return 1;
    CString strPath = FUN_14071a5b0("Table", "worldMapFieldNameInfo.xml");
    MS2Ptr<CCacheData> spCache(new CCacheData);
    spCache->FUN_1401d1160(CString(strPath));
    m_d8.Add(spCache);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        unsigned nId;
        if (!FUN_14028f710(pNode) || (FUN_140873220(pNode, "mapCode", nId), nId == 0))
            continue;
        MS2Ptr<UIWorldMap::MapTile> spTile = FindMapTileByKey(nId);
        if (spTile == 0)
            continue;
        CString strAlign;
        FUN_140873ad0(pNode, "align", strAlign);
        spTile->m_5c = FUN_140d01040(strAlign);
        CString strMovie;
        FUN_140873ad0(pNode, "tagMovie", strMovie);
        spTile->m_60 = strMovie;
        FUN_1408731e0(pNode, "alignOffsetX", spTile->m_68);
        FUN_1408731e0(pNode, "alignOffsetY", spTile->m_6c);
    }
    return 1;
}

// @0x141b96d90
void WorldMapManager::PollChangedFiles()
{
    if (m_d8.IsEmpty())
        return;
    bool bChanged = false;
    for (size_t i = 0; i < m_d8.GetCount(); i++)
    {
        MS2Ptr<CCacheData> spCache = m_d8[i];
        if (spCache == 0)
            continue;
        if (FUN_1401d1320(spCache.operator->()))
        {
            bChanged = true;
            break;
        }
    }
    if (bChanged)
    {
        m_d8.RemoveAll();
        m_8.clear();
        m_18.clear();
        m_48.clear();
        m_58.clear();
        LoadWorldMapFiles();
        m_68.clear();
        LoadFieldTiles();
    }
}

// @0x141b96f10
void WorldMapManager::LoadWorldMapNames(ATL::CAtlArray<CString>& names)
{
    CString strPath = FUN_14071a5b0("Table", "worldmap.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("xml"); pNode != 0; pNode = pNode->FUN_140168650("xml"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CString strName;
        FUN_1408733e0(pNode, "name", strName);
        names.Add(strName);
    }
}

// @0x141b970f0
void WorldMapManager::LoadIconPacket(CInPacket* packet)
{
    ClearIconInfos();
    LoadSpecialNpcs(packet);
    if (static_cast<CInputStream*>(packet)->vfunc_o8_1())
        LoadSpecialNpcs(packet);
    if (static_cast<CInputStream*>(packet)->vfunc_o8_1() == 1)
        LoadAddtionalInfos(packet);
}


// @0x141b971a0
void WorldMapManager::LoadSpecialNpcs(CInPacket* packet)
{
    std::vector<Unk_BmBoxPtr<SpecialNPCInfo> > records;
    unsigned nType = static_cast<CInputStream*>(packet)->vfunc_o8_1();
    if (nType == 1)
    {
        unsigned nCount = static_cast<CInputStream*>(packet)->vfunc_o8_3();
        for (unsigned i = 0; i < nCount; i++)
        {
            unsigned nInner = static_cast<CInputStream*>(packet)->vfunc_o8_3();
            for (unsigned j = 0; j < nInner; j++)
            {
                Unk_BmBoxPtr<SpecialNPCInfo> spRecord(Unk_BmNewTag(0));
                FUN_14092c190(spRecord.operator->(), *static_cast<CInputStream*>(packet));
                if (!FUN_14116d720(FUN_14025e7c0()))
                {
                    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(spRecord->m_nFieldId);
                    if (!spField)
                        continue;
                    if (spRecord->m_n08 > FUN_1414738f0(spField->m_nChannelGroupId))
                        continue;
                }
                records.push_back(spRecord);
            }
        }
    }
    struct Less
    {
        // @0x141baff00
        bool operator()(Unk_BmBoxPtr<SpecialNPCInfo> a, Unk_BmBoxPtr<SpecialNPCInfo> b) const
        {
            return a->m_n08 < b->m_n08;
        }
    };
    std::sort(records.begin(), records.end(), Less());
    for (size_t i = 0; i < records.size(); i++)
    {
        Unk_BmBoxPtr<SpecialNPCInfo> spRecord = records[i];
        if (!spRecord)
            continue;
        MS2Ptr<UIWorldMap::IconInfo> spInfo = GetOrAddIconInfo(spRecord->m_nFieldId);
        if (!spInfo)
            continue;
        MS2Ptr<CNpcData> spNpc = FUN_1406cd330(spRecord->m_nNpcId);
        if (!spNpc)
            continue;
        UIWorldMap::IconInfo::Rect* pBoss = &spInfo->m_20;
        if (pBoss->m_0 == 0)
        {
            pBoss->m_0 = spRecord->m_nNpcId;
            pBoss->m_20 = spRecord->m_n18;
        }
        if (pBoss->m_0 != spRecord->m_nNpcId)
            continue;
        if (spRecord->m_n08 > 0)
            pBoss->m_8.push_back(spRecord->m_n08);
        AddSpecialNpc(spRecord);
    }
}

// The 12-byte additional info record of the icon packet (ctor 0x141badeb0, read 0x141bb0440).
struct Unk_WmAddtionalRecord
{
    Unk_WmAddtionalRecord() : m_0(0), m_4(0), m_8(0) {}
    void Read(CInputStream* pStream);
    int m_0;
    int m_4;
    int m_8;
};

// @0x141b97680
void WorldMapManager::LoadAddtionalInfos(CInPacket* packet)
{
    ClearAddtionalInfos();
    std::vector<Unk_BmBoxPtr<SpecialNPCInfo> > unused;
    if (static_cast<CInputStream*>(packet)->vfunc_o8_1() == 3)
    {
        unsigned nCount = static_cast<CInputStream*>(packet)->vfunc_o8_3();
        for (unsigned i = 0; i < nCount; i++)
        {
            Unk_WmAddtionalRecord rec;
            rec.Read(static_cast<CInputStream*>(packet));
            MS2Ptr<UIWorldMap::AddtionalInfo> spInfo = GetOrAddAddtionalInfo(rec.m_0);
            if (!spInfo)
                continue;
            spInfo->m_1c.m_0 = rec.m_4;
            spInfo->m_1c.m_4 = rec.m_8;
        }
    }
}

// @0x141b977e0
WorldMapManager::TileVector& WorldMapManager::GetWorldTiles(int world)
{
    static TileVector s_empty;
    if (m_18.find(world) == m_18.end())
        return s_empty;
    return m_18[world];
}

// @0x141b978c0
WorldMapManager::TileGroups& WorldMapManager::GetTileGroups()
{
    return m_18;
}

// @0x141b978e0
MS2Ptr<UIWorldMap::MapTile> WorldMapManager::FindMapTileByKey(unsigned key)
{
    if (m_48.find(key) != m_48.end())
        return m_48[key];
    return MS2Ptr<UIWorldMap::MapTile>(0);
}

// @0x141b979b0
std::set<int>& WorldMapManager::GetPortalFields()
{
    return m_8;
}

// @0x141b979d0
std::map<unsigned, MS2Ptr<UIWorldMap::FieldSearchInfo> >& WorldMapManager::FieldSearchInfos()
{
    return m_68;
}

// @0x141b979f0
MS2Ptr<UIWorldMap::FieldSearchInfo> WorldMapManager::FindFieldSearchInfo(CStringW name)
{
    for (std::map<unsigned, MS2Ptr<UIWorldMap::FieldSearchInfo> >::iterator it = m_68.begin(); it != m_68.end(); it++)
    {
        MS2Ptr<UIWorldMap::FieldSearchInfo> spInfo = it->second;
        if (!spInfo)
            continue;
        if (spInfo->m_20 == name)
            return spInfo;
    }
    return MS2Ptr<UIWorldMap::FieldSearchInfo>(0);
}

// @0x141b97b50
void WorldMapManager::ClearIconInfos()
{
    m_28.clear();
    m_80.RemoveAll();
}

// @0x141b97b90
void WorldMapManager::SetIconInfo(unsigned id, MS2Ptr<UIWorldMap::IconInfo> info)
{
    m_28[id] = info;
}

// @0x141b97bf0
MS2Ptr<UIWorldMap::IconInfo> WorldMapManager::GetOrAddIconInfo(unsigned id)
{
    if (m_28.find(id) == m_28.end())
    {
        MS2Ptr<UIWorldMap::IconInfo> spInfo(Unk_BmNewTag(0));
        spInfo->m_18 = id;
        m_28[id] = spInfo;
    }
    return m_28[id];
}

// @0x141b97d30
void WorldMapManager::ClearAddtionalInfos()
{
    m_38.clear();
}

// @0x141b97d60
void WorldMapManager::SetAddtionalInfo(unsigned id, MS2Ptr<UIWorldMap::AddtionalInfo> info)
{
    m_38[id] = info;
}

// @0x141b97dc0
MS2Ptr<UIWorldMap::AddtionalInfo> WorldMapManager::GetOrAddAddtionalInfo(unsigned id)
{
    if (m_38.find(id) == m_38.end())
    {
        MS2Ptr<UIWorldMap::AddtionalInfo> spInfo(Unk_BmNewTag(0));
        spInfo->m_18 = id;
        m_38[id] = spInfo;
    }
    return m_38[id];
}

// @0x141b97f00
void WorldMapManager::SelectFieldTile(unsigned key)
{
    if (m_48.find(key) != m_48.end())
    {
        m_78 = key;
    }
    else
    {
        unsigned nMapped;
        if (CFieldMetaTable::GetInstance()->FUN_1406fc110(key, &nMapped))
        {
            if (m_48.find(nMapped) != m_48.end())
                m_78 = nMapped;
        }
    }
}

// @0x141b97fe0
int WorldMapManager::SelectedField()
{
    return m_78;
}

// @0x141b98000
MS2Ptr<UIWorldMap::MapTile> WorldMapManager::FindMapTile(int id)
{
    if (m_58.find(id) == m_58.end())
        return MS2Ptr<UIWorldMap::MapTile>(0);
    return m_58[id];
}

// @0x141b980d0
void WorldMapManager::ClearIconInfoTooltips()
{
    for (std::map<int, MS2Ptr<UIWorldMap::IconInfo> >::iterator it = m_28.begin(); it != m_28.end(); ++it)
    {
        MS2Ptr<UIWorldMap::IconInfo> spInfo = it->second;
        spInfo->m_80.clear();
    }
}

// @0x141b98180
void WorldMapManager::ClearDungeonInfos()
{
    for (std::map<int, MS2Ptr<UIWorldMap::IconInfo> >::iterator it = m_28.begin(); it != m_28.end(); ++it)
    {
        MS2Ptr<UIWorldMap::IconInfo> spInfo = it->second;
        spInfo->m_48.m_18 = 0;
        spInfo->m_48.m_1d = false;
        spInfo->m_48.m_1c = false;
    }
}

// @0x141b98250
void WorldMapManager::ClearAddtionalInfoTooltips()
{
    for (std::map<int, MS2Ptr<UIWorldMap::AddtionalInfo> >::iterator it = m_38.begin(); it != m_38.end(); ++it)
    {
        MS2Ptr<UIWorldMap::AddtionalInfo> spInfo = it->second;
        spInfo->m_28.clear();
    }
}

// @0x141b98300
int WorldMapManager::WorldOfField(int field)
{
    CContinentRegionTable::InfoPtr spContinent = FUN_1403782c0()->GetContinent(field);
    if (spContinent.get() != 0)
        field = spContinent->m_nRepresentWorldmapContinent;
    return field;
}

// @0x141b98380
bool WorldMapManager::HasFieldSearchInfo(unsigned id)
{
    return m_68.find(id) != m_68.end();
}

// @0x141b983f0
void WorldMapManager::AddSpecialNpc(Unk_BmBoxPtr<SpecialNPCInfo> info)
{
    m_80.SetAt(info->m_nNpcId, info);
}

// @0x141b98440
int WorldMapManager::BuildFieldSearch(unsigned field, ASObj* script, bool mission)
{
    if (mission)
        BuildMissionSearch(field, script);
    else
        BuildFieldDetails(field, script);
    return 1;
}

// The npc -> fields index of the field meta table (an inline accessor; first emitted here).
// @0x141bb07e0
Unk_FieldIdListMap& FUN_141bb07e0(CFieldMetaTable* pTable)
{
    return *reinterpret_cast<Unk_FieldIdListMap*>(reinterpret_cast<char*>(pTable) + 0x10);
}

// @0x141b984a0
int WorldMapManager::BuildNameSearch(CStringW search, ASObj* script)
{
    bool bFound = false;
    ASArray maps(2);
    ASArray dungeons(2);
    ASArray monsters(2);
    ASArray bosses(2);
    ASArray elites(2);
    ASArray npcs(2);
    ASArray gates(2);
    ASArray indoors(2);
    std::map<unsigned, MS2Ptr<UIWorldMap::FieldSearchInfo> >& infos = GetInstance()->FieldSearchInfos();
    for (std::map<unsigned, MS2Ptr<UIWorldMap::FieldSearchInfo> >::iterator it = infos.begin(); it != infos.end(); ++it)
    {
        MS2Ptr<UIWorldMap::FieldSearchInfo> spInfo = it->second;
        if (FUN_14083fec0(spInfo->m_20, search) == -1)
            continue;
        if (spInfo->m_28 == spInfo->m_18)
        {
            ASObj item(2);
            item.FUN_1407cbb20("text", spInfo->m_20);
            item.FUN_1409c0d20("id", spInfo->m_18);
            item.FUN_1409c0d20("iconData", spInfo->m_18);
            MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(spInfo->m_18);
            if (spField)
            {
                if (!spField->FUN_140375130() && spField->FUN_1403753d0() != 0)
                    item.FUN_1409c0dc0("icon", "cashTaxi");
            }
            maps.FUN_1422bbf00(item);
        }
        else
        {
            ASObj item(2);
            item.FUN_1407cbb20("text", spInfo->m_20);
            item.FUN_1409c0d20("id", spInfo->m_28);
            indoors.FUN_1422bbf00(item);
        }
        bFound = true;
    }
    Unk_FieldIdListMap& portalMap = CFieldMetaTable::GetInstance()->FUN_1406fc450();
    for (POSITION pos = portalMap.GetStartPosition(); pos != 0; FUN_140c956e0(&portalMap, pos))
    {
        unsigned nField = portalMap.GetKeyAt(pos);
        if (!GetInstance()->FindMapTileByKey(nField))
            continue;
        Unk_FieldIdListPtr spPortals = FUN_141b695b0(&portalMap, pos);
        for (POSITION portalPos = spPortals->GetHeadPosition(); portalPos != 0; spPortals->GetNext(portalPos))
        {
            unsigned nPortal = spPortals->GetAt(portalPos);
            ATL::CAtlArray<MS2Ptr<DungeonRoom> > rooms;
            FUN_14031c2a0()->GetRooms(nPortal, rooms);
            for (size_t i = 0; i < rooms.GetCount(); i++)
            {
                MS2Ptr<DungeonRoom> spRoom = rooms[i];
                CStringW strType = FUN_1401a9d70()->FUN_141811980(0x14, spRoom->GetDungeonRoomID());
                if (FUN_14083fec0(strType, search) != -1)
                {
                    CStringW strName = FUN_140e14b70(spRoom);
                    ASObj item(2);
                    item.FUN_1407cbb20("text", FUN_140656190(L"[{0}] {1}", strName, strType));
                    item.FUN_1409c0d20("id", nField);
                    item.FUN_1409c0dc0("icon", spRoom->m_groupType == 2 ? "dungeon_raid" : "dungeon");
                    item.FUN_1409c0d20("iconData", spRoom->m_dungeonRoomID);
                    dungeons.FUN_1422bbf00(item);
                    bFound = true;
                }
            }
        }
    }
    ATL::CAtlMap<CStringW, int, ATL::CStringElementTraits<CStringW> > seen;
    Unk_FieldIdListMap& npcMap = FUN_141bb07e0(CFieldMetaTable::GetInstance());
    for (POSITION pos = npcMap.GetStartPosition(); pos != 0; FUN_140c956e0(&npcMap, pos))
    {
        int nNpcId = npcMap.GetKeyAt(pos);
        Unk_FieldIdListPtr spFields = FUN_141b695b0(&npcMap, pos);
        if (spFields->GetCount() == 0)
            continue;
        unsigned nField = spFields->GetHead();
        MS2Ptr<CFieldDataCli> spData = CFieldDataCli::Find(nField);
        if (!spData)
            continue;
        MS2Ptr<NpcDataCli> spNpc = FUN_1406d6e90()->Find(nNpcId);
        if (!spNpc)
            continue;
        if (!CFieldMetaTable::GetInstance()->FUN_1406fbb50(nNpcId, nField))
            continue;
        if (!GetInstance()->FindMapTileByKey(nField))
        {
            unsigned nOutdoor = 0;
            if (CFieldMetaTable::GetInstance()->FUN_1406fc110(nField, &nOutdoor) == 0)
                continue;
            if (!GetInstance()->FindMapTileByKey(nOutdoor))
                continue;
        }
        CStringW strPlain = FUN_1401aa6a0(nNpcId);
        if (strPlain.GetLength() == 0)
            continue;
        CStringW strName = NpcSearchName(nNpcId, nField);
        if (seen.Lookup(strName) != 0)
            continue;
        seen.SetAt(strName, 1);
        if (spNpc->GetKind() == 0x55)
        {
            CJobConditionTable::NpcJobDataPtr spGate = CJobConditionTable::GetInstance()->GetData(nNpcId);
            if (spGate.get() && spGate->m_nMoveFieldId != 0)
            {
                CStringW strLabel = FUN_1405c2690(CStringW(L"s_worldmap_tooltip_shadowgate_field"), FUN_1401a9d70()->FUN_141811980(3, spGate->m_nMoveFieldId));
                FUN_1403b4750()->FUN_1416fb340(strLabel);
                if (FUN_14083fec0(strLabel, search) == -1)
                    continue;
                ASObj item(2);
                item.FUN_1407cbb20("text", strLabel);
                item.FUN_1409c0d20("id", nField);
                gates.FUN_1422bbf00(item);
                bFound = true;
            }
        }
        else if (spNpc->GetFriendly() == 1 || spNpc->GetFriendly() == 2)
        {
            if (spNpc->m_strIcon.GetLength() == 0 && spNpc->GetKind() == 0)
                continue;
            if (FUN_14083fec0(strName, search) == -1)
                continue;
            ASObj item(2);
            item.FUN_1407cbb20("text", strName);
            item.FUN_1409c0d20("id", nField);
            npcs.FUN_1422bbf00(item);
            bFound = true;
        }
        else if (spNpc->GetFriendly() == 0)
        {
            if (FUN_14083fec0(strName, search) == -1)
                continue;
            if (spNpc->m_nClass == 6 || spNpc->m_nClass == 7)
            {
                unsigned nOutdoor = 0;
                if (CFieldMetaTable::GetInstance()->FUN_1406fc110(nField, &nOutdoor) == 0)
                    continue;
            }
            if (spNpc->m_nClass == 4)
            {
                CMsTime when;
                if (CFieldMetaTable::GetInstance()->FUN_1406fc620(nNpcId, when) != 0)
                {
                    CStringW strTime = FUN_140f48210(when.GetHour(), when.GetMinute());
                    CStringW strFormat = FUN_14028b8e0(CStringW(L"s_spawnnpc_guarantee"));
                    strName += L" ";
                    strName += FUN_1401e8510(strFormat, strTime);
                }
            }
            ASObj item(2);
            item.FUN_1407cbb20("text", strName);
            item.FUN_1409c0d20("id", nField);
            switch (spNpc->m_nClass)
            {
            case 3: case 7: elites.FUN_1422bbf00(item); break;
            case 4: case 6: bosses.FUN_1422bbf00(item); break;
            default: monsters.FUN_1422bbf00(item); break;
            }
            bFound = true;
        }
    }
    script->FUN_140c16160("map", maps);
    script->FUN_140c16160("dungeon", dungeons);
    script->FUN_140c16160("monster", monsters);
    script->FUN_140c16160("eliteMonster", elites);
    script->FUN_140c16160("bossMonster", bosses);
    script->FUN_140c16160("shadowgate", gates);
    script->FUN_140c16160("indoor", indoors);
    script->FUN_140c16160("npc", npcs);
    if (!bFound)
        script->FUN_1407cbb20("title", FUN_14028b8e0(CStringW(L"s_err_worldmap_search_none")));
    return 1;
}

// @0x141b99dc0
void WorldMapManager::BuildNpcRewardPreview(int npc, ASObj* script)
{
    if (!FUN_14036d570(FUN_140166410(), 0x1a))
        return;
    PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPC == 0)
        return;
    MS2Ptr<RewardPreviewInfo> spPreview = FUN_140f26650()->GetBoss(npc);
    if (spPreview == 0)
        return;
    ASObj reward(2);
    ATL::CAtlList<ItemEntity> items(10);
    spPreview->GetValid(reinterpret_cast<PC*>(pPC), items);
    if (items.GetCount() != 0)
    {
        ASArray array(2);
        reward.FUN_140c16160("previewItems", array);
        for (POSITION pos = items.GetHeadPosition(); pos != 0; items.GetNext(pos))
        {
            ItemEntity& entity = items.GetAt(pos);
            MS2Ptr<CItemData> spItem = FUN_14053f870(entity.m_itemId);
            if (spItem.get())
            {
                ASObj item(2);
                item.FUN_1409adc90(s_strItemGrade, static_cast<ItemAble&>(entity).vfunc_o18_1());
                item.FUN_1407cbbe0(s_strItemSkin, spItem->FUN_14053cf90());
                item.FUN_1407cbb20(s_strIconPath, FUN_14016a730(spItem->FUN_14053fdd0(), 0));
                array.FUN_1422bc050(item.FUN_1422bb870());
            }
        }
    }
    FUN_1418adf60(script, "reward", reward);
    script->FUN_1407cbb20("enableLClick", FUN_14028de60(0x764));
}

// @0x141b9a1e0
void WorldMapManager::SetDungeonScript(MS2Ptr<UIWorldMap::IconInfo> info, ASObj* script, int variant)
{
    if (info->m_48.m_18 == 0)
        return;
    script->FUN_1407cb9c0("portalID", info->m_48.m_18);
    if (info->m_48.m_1c)
    {
        if (info->m_48.m_1d)
            script->FUN_1409c0dc0("dungeonType", "boss_special");
        else
            script->FUN_1409c0dc0("dungeonType", "boss");
    }
    else
    {
        if (info->m_48.m_1d)
            script->FUN_1409c0dc0("dungeonType", "dungeon_special");
        else
            script->FUN_1409c0dc0("dungeonType", "dungeon");
    }
}

// @0x141b9a300
void WorldMapManager::SetEventIconInfo(unsigned id, MS2Ptr<EventIconInfo> info)
{
    m_c8[id] = info;
}

// @0x141b9a360
void WorldMapManager::RemoveEventIconInfo(unsigned id)
{
    m_c8.erase(id);
}

// @0x141b9a390
void WorldMapManager::SetEventScript(unsigned id, ASObj* script)
{
    if (m_c8.find(id) != m_c8.end())
    {
        MS2Ptr<EventIconInfo> spInfo = m_c8[id];
        script->FUN_1407cb9c0("eventField", 1);
        script->FUN_1407cbb20("eventIcon", spInfo->m_strIconFrame);
        script->FUN_1407cbb20("eventStr", FUN_14028b8e0(spInfo->m_strEventStr));
        script->FUN_1407cb9c0("eventTagOffsetX", spInfo->m_nOffsetX);
        script->FUN_1407cb9c0("eventTagOffsetY", spInfo->m_nOffsetY);
        script->FUN_1409c4a30("eventTagScale", spInfo->m_fScale);
    }
}

// @0x141b9a560
CStringW WorldMapManager::NpcSearchName(int npc, int field)
{
    CStringW strText;
    MS2Ptr<CNpcData> spNpc = FUN_1406cd330(npc);
    if (spNpc.get() && spNpc->GetFriendly() == 0)
    {
        unsigned short nLevel = spNpc->GetLevel();
        strText = FUN_140f02bd0(CStringW(L"s_worldmap_search_monster"), FUN_1401aa6a0(npc), nLevel, FUN_1401a9d70()->FUN_141811980(0x11, spNpc->GetRace()));
    }
    else
    {
        CStringW strTitle = FUN_1401a9d70()->FUN_141811980(10, npc);
        if (strTitle.GetLength() > 0)
            strText = FUN_1408f71a0(CStringW(L"s_worldmap_search_npc_function"), strTitle, FUN_1401aa6a0(npc));
        else
            strText = FUN_1401aa6a0(npc);
    }
    CStringW strUnused;
    if (field != 0)
    {
        unsigned nOutdoor = 0;
        if (CFieldMetaTable::GetInstance()->FUN_1406fc110(field, &nOutdoor) != 0)
            return FUN_1408f71a0(CStringW(L"s_worldmap_search_npc_indoor"), strText, FUN_1401a9d70()->FUN_141811980(3, field));
    }
    return strText;
}

bool WorldMapDungeonLess(MS2Ptr<DungeonRoom> a, MS2Ptr<DungeonRoom> b);

// @0x141b9a9f0
int WorldMapManager::BuildFieldDetails(unsigned field, ASObj* script)
{
    MS2Ptr<CFieldDataCli> spData = CFieldDataCli::Find(field);
    if (!spData)
        return 0;
    ASArray dungeons(2);
    ASArray monsters(2);
    ASArray bosses(2);
    ASArray elites(2);
    ASArray npcs(2);
    ASArray gates(2);
    ASArray indoors(2);
    Unk_FieldIdListPtr spPortals = CFieldMetaTable::GetInstance()->FUN_1406fc3c0(field);
    if (spPortals.get())
    {
        std::vector<MS2Ptr<DungeonRoom> > rooms;
        for (POSITION pos = spPortals->GetHeadPosition(); pos != 0; spPortals->GetNext(pos))
        {
            unsigned nPortal = spPortals->GetAt(pos);
            ATL::CAtlArray<MS2Ptr<DungeonRoom> > found;
            FUN_14031c2a0()->GetRooms(nPortal, found);
            for (size_t i = 0; i < found.GetCount(); i++)
            {
                MS2Ptr<DungeonRoom> spRoom = found[i];
                rooms.push_back(spRoom);
            }
        }
        std::sort(rooms.begin(), rooms.end(), WorldMapDungeonLess);
        for (size_t i = 0; i < rooms.size(); i++)
        {
            MS2Ptr<DungeonRoom> spRoom = rooms[i];
            CStringW strName = FUN_140e14b70(MS2Ptr<DungeonRoom>(spRoom));
            CStringW strType = FUN_1401a9d70()->FUN_141811980(0x14, spRoom->GetDungeonRoomID());
            ASObj item(2);
            item.FUN_1407cbb20("text", FUN_140656190(L"[{0}] {1}", strName, strType));
            item.FUN_1409c0d20("id", field);
            item.FUN_1409c0dc0("icon", spRoom->m_groupType == 2 ? "dungeon_raid" : "dungeon");
            item.FUN_1409c0d20("iconData", spRoom->m_dungeonRoomID);
            dungeons.FUN_1422bbf00(item);
        }
    }
    ATL::CAtlMap<CStringW, int, ATL::CStringElementTraits<CStringW> > seen;
    ATL::CAtlList<unsigned> fields(10);
    CFieldMetaTable::GetInstance()->FUN_1406fc2f0(field, fields);
    for (POSITION fieldPos = fields.GetHeadPosition(); fieldPos != 0; fields.GetNext(fieldPos))
    {
        unsigned nConnected = fields.GetAt(fieldPos);
        if (m_68.find(nConnected) == m_68.end())
            continue;
        ATL::CAtlList<unsigned> ids(10);
        CFieldMetaTable::GetInstance()->FUN_1406fb610(nConnected, ids);
        for (POSITION npcPos = ids.GetHeadPosition(); npcPos != 0; ids.GetNext(npcPos))
        {
            unsigned nNpcId = ids.GetAt(npcPos);
            MS2Ptr<NpcDataCli> spNpc = FUN_1406d6e90()->Find(nNpcId);
            if (!spNpc)
                continue;
            CStringW strName = FUN_1401aa6a0(nNpcId);
            if (strName.GetLength() == 0)
                continue;
            strName = NpcSearchName(nNpcId, nConnected);
            if (seen.Lookup(strName) != 0)
                continue;
            seen.SetAt(strName, 1);
            if (spNpc->GetKind() == 0x55)
            {
                CJobConditionTable::NpcJobDataPtr spGate = CJobConditionTable::GetInstance()->GetData(nNpcId);
                if (spGate.get() && spGate->m_nMoveFieldId != 0)
                {
                    MS2Ptr<CFieldDataCli> spTarget = CFieldDataCli::Find(spGate->m_nMoveFieldId);
                    if (spTarget)
                    {
                        CStringW strLabel = FUN_1405c2690(CStringW(L"s_worldmap_tooltip_shadowgate_field"), FUN_1401a9d70()->FUN_141811980(3, spGate->m_nMoveFieldId));
                        FUN_1403b4750()->FUN_1416fb340(strLabel);
                        ASObj item(2);
                        item.FUN_1407cbb20("text", strLabel);
                        gates.FUN_1422bbf00(item);
                    }
                }
            }
            else if (spNpc->GetFriendly() == 1 || spNpc->GetFriendly() == 2)
            {
                if (spNpc->m_strIcon.GetLength() == 0 && spNpc->GetKind() == 0)
                    continue;
                ASObj item(2);
                item.FUN_1407cbb20("text", strName);
                npcs.FUN_1422bbf00(item);
            }
            else if (spNpc->GetFriendly() == 0)
            {
                ASObj item(2);
                if (spNpc->m_nClass == 4)
                {
                    CMsTime when;
                    if (CFieldMetaTable::GetInstance()->FUN_1406fc620(nNpcId, when) != 0)
                    {
                        CStringW strTime;
                        CMsTime now(FUN_140869440());
                        int bSameDay = 1;
                        if (when.GetYear() != now.GetYear())
                            bSameDay = 0;
                        if (when.GetMonth() != now.GetMonth())
                            bSameDay = 0;
                        if (when.GetDay() != now.GetDay())
                            bSameDay = 0;
                        if (bSameDay == 0)
                            strTime = FUN_140b8e910(when);
                        else
                            strTime = FUN_140f48210(when.GetHour(), when.GetMinute());
                        CStringW strFormat = FUN_14028b8e0(CStringW(L"s_spawnnpc_guarantee"));
                        strName += L" ";
                        strName += FUN_1401e8510(strFormat, strTime);
                    }
                }
                item.FUN_1407cbb20("text", strName);
                switch (spNpc->m_nClass)
                {
                case 3: case 7: elites.FUN_1422bbf00(item); break;
                case 4: case 6: bosses.FUN_1422bbf00(item); break;
                default: monsters.FUN_1422bbf00(item); break;
                }
            }
        }
    }
    ATL::CAtlList<unsigned> indoorFields(10);
    CFieldMetaTable::GetInstance()->FUN_1406fc2f0(field, indoorFields);
    for (POSITION indoorPos = indoorFields.GetHeadPosition(); indoorPos != 0; indoorFields.GetNext(indoorPos))
    {
        unsigned nConnected = indoorFields.GetAt(indoorPos);
        if (m_68.find(nConnected) == m_68.end() && field != nConnected)
        {
            ASObj item(2);
            item.FUN_1407cbb20("text", FUN_1401a9d70()->FUN_141811980(3, nConnected));
            indoors.FUN_1422bbf00(item);
        }
    }
    CStringW strTitle = FUN_140b99450(CStringW(L"s_worldmap_search_map_title"), FUN_1401a9d70()->FUN_141811980(3, field), spData->m_nMapLevel);
    CStringW strFishing = FUN_140953f20()->FUN_140cdc000(field);
    script->FUN_1409c0d20("fieldSN", field);
    script->FUN_1407cbb20("title", strTitle);
    script->FUN_1407cbb20("fishingSpot", strFishing);
    script->FUN_1407cbb20("mapDesc", FUN_1401a9d70()->FUN_141811980(0x4b, field));
    script->FUN_140c16160("dungeon", dungeons);
    script->FUN_140c16160("monster", monsters);
    script->FUN_140c16160("bossMonster", bosses);
    script->FUN_140c16160("eliteMonster", elites);
    script->FUN_140c16160("shadowgate", gates);
    script->FUN_140c16160("indoor", indoors);
    script->FUN_140c16160("npc", npcs);
    script->FUN_1407cbbe0("cashtaxi", !spData->FUN_140375130() && spData->FUN_1403753d0() != 0);
    return 1;
}

// @0x141b9bf10
int WorldMapManager::BuildMissionSearch(unsigned field, ASObj* script)
{
    MS2Ptr<CFieldDataCli> spData = CFieldDataCli::Find(field);
    if (!spData)
        return 0;
    ASArray missions(2);
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074cbf0(field, ids);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        int nQuestId = ids[i];
        ATL::CAtlArray<CStringW> lines;
        FUN_1416e5890(nQuestId, lines);
        for (size_t j = 0; j < lines.GetCount(); j++)
        {
            ASObj item(2);
            item.FUN_1407cbb20("tooltip", lines[j]);
            missions.FUN_1422bbf00(item);
        }
    }
    CStringW strTitle = FUN_140b99450(CStringW(L"s_worldmap_search_map_title"), FUN_1401a9d70()->FUN_141811980(3, field), spData->m_nMapLevel);
    CStringW strFishing = FUN_140953f20()->FUN_140cdc000(field);
    script->FUN_1409c0d20("fieldSN", field);
    script->FUN_1407cbb20("title", strTitle);
    script->FUN_1407cbb20("fishingSpot", strFishing);
    script->FUN_1409eb1d0("mission", missions);
    return 1;
}

// @0x141b9c2c0
// The same order over the value pointer flavour of the record (unreferenced in the exe).
bool WorldMapSpecialNpcLess(TPtrValue<SpecialNPCInfo> a, TPtrValue<SpecialNPCInfo> b)
{
    return a->m_n08 < b->m_n08;
}

// @0x141b9c340
bool WorldMapDungeonLess(MS2Ptr<DungeonRoom> a, MS2Ptr<DungeonRoom> b)
{
    if (a->m_groupType == b->m_groupType)
        return a->m_dungeonLevel < b->m_dungeonLevel;
    return a->m_groupType < b->m_groupType;
}

// @0x141b9c450
// Tiles: kind, then height, then the projected centre (isometric 45/45 degree view).
bool WorldMapTileLess(const MS2Ptr<UIWorldMap::MapTile>& a, const MS2Ptr<UIWorldMap::MapTile>& b)
{
    if (a->m_18 == b->m_18)
    {
        if (a->m_2c == b->m_2c)
        {
            efd::Matrix3 rotation;
            rotation.FromEulerAnglesXYZ(0.7853982f, 0.0f, 0.7853982f);
            efd::Point3 first((float)a->m_24 + (float)a->m_30 / 2.0f, (float)a->m_28 + (float)a->m_30 / 2.0f, (float)a->m_2c);
            first = first * rotation;
            efd::Point3 second((float)b->m_24 + (float)b->m_30 / 2.0f, (float)b->m_28 + (float)b->m_30 / 2.0f, (float)b->m_2c);
            second = second * rotation;
            return second.y < first.y;
        }
        return a->m_2c < b->m_2c;
    }
    return a->m_18 < b->m_18;
}

// @0x141b9d650
int WorldMapQuestTier(int nQuestId, const int& a, const int& b, const int& c, const int& d)
{
    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuestId);
    return WorldMapQuestTier(spQuest, a, b, c, d);
}

// @0x141b9d6f0
int WorldMapQuestTier(MS2Ptr<CQuestData> spQuest, const int& a, const int& b, const int& c, const int& d)
{
    if (spQuest.get())
    {
        switch (FUN_14074b050(spQuest.operator->()))
        {
        case 0:
            return a;
        case 1:
        case 6:
            return FUN_1407640c0(spQuest.operator->()) ? c : b;
        case 2:
            return d;
        case 8:
        case 9:
            return b;
        }
    }
    return b;
}

// @0x141b9d850
// The "tileType" enum attribute of a map tile.
int FUN_141b9d850(Unk_140165cf0* pNode, const char* pszName, int* pOut)
{
    int nValue = 0;
    int nResult = FUN_140873890(pNode, pszName, nValue);
    if (nResult == 0)
        *pOut = nValue;
    return nResult;
}

// ---- the UIWorldMap records ----

// The pooled factories behind MS2Ptr<T>(Unk_BmNewTag) (initializers in unit_141bb1490.cpp).
void FUN_141bb1490(void* pPtr);                                             // AddtionalInfo
void FUN_141bb14c0(void* pPtr);                                             // FieldSearchInfo
void FUN_141bb14f0(void* pPtr);                                             // IconInfo
void FUN_141bb1520(void* pPtr);                                             // MapTile

// @0x141b9d8e0
UIWorldMap::AddtionalInfo* FUN_141b9d8e0(void*)
{
    return new UIWorldMap::AddtionalInfo();
}

// @0x141b9d950
UIWorldMap::FieldSearchInfo* FUN_141b9d950(void*)
{
    return new UIWorldMap::FieldSearchInfo();
}

// @0x141b9d9c0
UIWorldMap::IconInfo* FUN_141b9d9c0(void*)
{
    return new UIWorldMap::IconInfo();
}

// @0x141b9da20
UIWorldMap::MapTile* FUN_141b9da20(void*)
{
    return new UIWorldMap::MapTile();
}

// @0x141baca10
template <> MS2Ptr<UIWorldMap::AddtionalInfo>::MS2Ptr(const Unk_BmNewTag&)
{
    m_p = 0;
    FUN_141bb1490(this);
}

// @0x141bacaf0
template <> MS2Ptr<UIWorldMap::FieldSearchInfo>::MS2Ptr(const Unk_BmNewTag&)
{
    m_p = 0;
    FUN_141bb14c0(this);
}

// @0x141bacb60
template <> MS2Ptr<UIWorldMap::IconInfo>::MS2Ptr(const Unk_BmNewTag&)
{
    m_p = 0;
    FUN_141bb14f0(this);
}

// @0x141bacbb0
template <> MS2Ptr<UIWorldMap::MapTile>::MS2Ptr(const Unk_BmNewTag&)
{
    m_p = 0;
    FUN_141bb1520(this);
}

// @0x141badbe0
UIWorldMap::IconInfo::Rect::Rect()
{
    m_0 = 0;
    m_20 = 0;
}

// @0x141badca0
UIWorldMap::DungeonInfo::DungeonInfo()
{
    m_18 = 0;
    m_1c = false;
    m_1d = false;
}

// @0x141badd30
UIWorldMap::MapTile::MapTile()
{
    m_18 = 0;
    m_1c = 0;
    m_20 = false;
    m_21 = false;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_5c = 0;
    m_68 = 0;
    m_6c = 0;
    m_70 = 0;
    m_74 = 0;
}

// @0x141bade80
UIWorldMap::AddtionalInfo::IntPair::IntPair()
{
    m_0 = 0;
    m_4 = 0;
}

// @0x141bb0380
// MapTile::CopyFrom (the header declares no member): a member-wise copy of another tile.
void FUN_141bb0380(UIWorldMap::MapTile* pThis, MS2Ptr<UIWorldMap::MapTile> spTile)
{
    *pThis = *spTile;
}

// @0x141bb0440
void Unk_WmAddtionalRecord::Read(CInputStream* pStream)
{
    m_0 = pStream->vfunc_o8_3();
    m_4 = pStream->vfunc_o8_3();
    m_8 = (unsigned short)pStream->vfunc_o8_2();
}
