// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemDataTable: the client item table (Table/ItemData.xml,
// the item rows of Table/itemData/<nnn>.xml, the item models, colour palettes, ui material sounds, music scores and
// housing rows) and its colour palette record CColorPaletteInfo.
// MS2-UNIT: ?\itemdatatable.cpp
// MS2-RANGE: 0x140555a70-0x14057a380 .text$mn
// MS2-RANGE: 0x1400b9a40-0x1400b9b40 .text$di
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0HAEAV?$MS2Ptr@VCItemData@@@@$0A@@?$pair@HV?$MS2Ptr@VCItemData@@@@@std@@QEAA@$$QEAHAEAV?$MS2Ptr@VCItemData@@@@@Z 0x140560510 ; unique
// MS2-PIN: ??$?0HV?$MS2Ptr@VCItemData@@@@$0A@@?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VCItemData@@@@@1@@Z 0x140560560 ; unique
// MS2-PIN: ??$StringFormat@II@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBI1@Z 0x1405608f0 ; unique
// MS2-PIN: ?Allocate@?$Unk_BmBoxPtr@V?$CAtlArray@V?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@ATL@@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@ATL@@@ATL@@@@PEAX@Z 0x140560ca0 ; unique
// MS2-PIN: ?Allocate@?$Unk_BmBoxPtr@V?$CAtlMap@HV?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@3@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlMap@HV?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@3@@ATL@@@@PEAX@Z 0x140560d10 ; unique
// MS2-PIN: ?Allocate@?$Unk_BmPtr@VCColorPaletteInfo@@@@CAPEAVCColorPaletteInfo@@PEAX@Z 0x140560d80 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@YAXPEAV?$MS2Ptr@VCItemData@@@@0AEAV?$allocator@V?$MS2Ptr@VCItemData@@@@@0@U?$integral_constant@_N$0A@@0@@Z 0x1405612a0 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@YAXPEAV?$MS2Ptr@VDropNifData@@@@0AEAV?$allocator@V?$MS2Ptr@VDropNifData@@@@@0@U?$integral_constant@_N$0A@@0@@Z 0x140561300 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$MS2Ptr@VDropNifData@@@@@?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@AEAAXAEBV?$MS2Ptr@VDropNifData@@@@@Z 0x140561820 ; prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$MS2Ptr@VCItemData@@@@@?$vector@V?$MS2Ptr@VCItemData@@@@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@AEAAXAEBV?$MS2Ptr@VCItemData@@@@@Z 0x1405618e0 ; prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$MS2Ptr@VItemModelData@@@@@?$vector@V?$MS2Ptr@VItemModelData@@@@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@AEAAXAEBV?$MS2Ptr@VItemModelData@@@@@Z 0x1405619a0 ; prop
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VDropNifData@@@@@?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VDropNifData@@@@QEAV2@AEBV2@@Z 0x140561a60 ; prop
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VCItemData@@@@@?$vector@V?$MS2Ptr@VCItemData@@@@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCItemData@@@@QEAV2@AEBV2@@Z 0x140561cb0 ; prop
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VItemModelData@@@@@?$vector@V?$MS2Ptr@VItemModelData@@@@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VItemModelData@@@@QEAV2@AEBV2@@Z 0x140561f00 ; prop
// MS2-PIN: ??$_Fill_memset_is_safe@PEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@V12@@std@@YA?AU?$integral_constant@_N$0A@@0@AEBQEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@0@AEBV20@@Z 0x140562150 ; prop
// MS2-PIN: ??$_Fill_unchecked1@PEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@V12@@std@@YAXPEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@0@0AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x140562180 ; unique
// MS2-PIN: ??$_Fill_unchecked@PEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@V12@@std@@YAXPEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@0@0AEBV10@@Z 0x1405621d0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@std@@@?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140562220 ; unique
// MS2-PIN: ??$_Idl_distance1@PEAV?$MS2Ptr@VCItemData@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VCItemData@@@@0Urandom_access_iterator_tag@0@@Z 0x140562620 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAV?$MS2Ptr@VDropNifData@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VDropNifData@@@@0Urandom_access_iterator_tag@0@@Z 0x140562650 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAV?$MS2Ptr@VItemModelData@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VItemModelData@@@@0Urandom_access_iterator_tag@0@@Z 0x140562680 ; prop
// MS2-PIN: ??$_Idl_distance@PEAV?$MS2Ptr@VCItemData@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VCItemData@@@@0@Z 0x1405626e0 ; prop
// MS2-PIN: ??$_Idl_distance@PEAV?$MS2Ptr@VDropNifData@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VDropNifData@@@@0@Z 0x140562710 ; prop
// MS2-PIN: ??$_Ptr_copy_cat@V?$MS2Ptr@VCItemData@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VCItemData@@@@0@Z 0x1405671c0 ; prop
// MS2-PIN: ??$_Ptr_copy_cat@V?$MS2Ptr@VDropNifData@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VDropNifData@@@@0@Z 0x1405671f0 ; prop
// MS2-PIN: ??$_Ptr_copy_cat@V?$MS2Ptr@VItemModelData@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VItemModelData@@@@0@Z 0x140567220 ; prop
// MS2-PIN: ??$_Ptr_move_cat@V?$MS2Ptr@VCItemData@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VCItemData@@@@0@Z 0x140567250 ; prop
// MS2-PIN: ??$_Ptr_move_cat@V?$MS2Ptr@VDropNifData@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VDropNifData@@@@0@Z 0x140567280 ; prop
// MS2-PIN: ??$_Ptr_move_cat@V?$MS2Ptr@VItemModelData@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VItemModelData@@@@0@Z 0x1405672b0 ; prop
// MS2-PIN: ??$_Seek_wrapped@V?$MS2Ptr@VCItemData@@@@@std@@YAXAEAPEAV?$MS2Ptr@VCItemData@@@@QEAV1@@Z 0x140567300 ; prop
// MS2-PIN: ??$_Seek_wrapped@V?$MS2Ptr@VDropNifData@@@@@std@@YAXAEAPEAV?$MS2Ptr@VDropNifData@@@@QEAV1@@Z 0x140567320 ; prop
// MS2-PIN: ??$_Unfancy@V?$MS2Ptr@VCItemData@@@@@std@@YAPEAV?$MS2Ptr@VCItemData@@@@PEAV1@@Z 0x140567620 ; unique
// MS2-PIN: ??$_Unfancy@V?$MS2Ptr@VDropNifData@@@@@std@@YAPEAV?$MS2Ptr@VDropNifData@@@@PEAV1@@Z 0x140567630 ; unique
// MS2-PIN: ??$_Unfancy@V?$MS2Ptr@VItemModelData@@@@@std@@YAPEAV?$MS2Ptr@VItemModelData@@@@PEAV1@@Z 0x140567640 ; unique
// MS2-PIN: ??$_Unfancy@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@@std@@YAPEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@0@PEAV10@@Z 0x140567650 ; unique
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$MS2Ptr@VCItemData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCItemData@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VCItemData@@@@@0@@Z 0x1405676f0 ; prop
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$MS2Ptr@VDropNifData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VDropNifData@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VDropNifData@@@@@0@@Z 0x1405677c0 ; prop
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$MS2Ptr@VItemModelData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VItemModelData@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VItemModelData@@@@@0@@Z 0x140567890 ; prop
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAV?$MS2Ptr@VCItemData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCItemData@@@@PEAV1@QEAV1@1AEAV?$allocator@V?$MS2Ptr@VCItemData@@@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140567960 ; prop
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAV?$MS2Ptr@VDropNifData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VDropNifData@@@@PEAV1@QEAV1@1AEAV?$allocator@V?$MS2Ptr@VDropNifData@@@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x1405679f0 ; prop
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAV?$MS2Ptr@VItemModelData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VItemModelData@@@@PEAV1@QEAV1@1AEAV?$allocator@V?$MS2Ptr@VItemModelData@@@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140567a80 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAV?$MS2Ptr@VCItemData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCItemData@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VCItemData@@@@@0@@Z 0x140567b70 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAV?$MS2Ptr@VDropNifData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VDropNifData@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VDropNifData@@@@@0@@Z 0x140567c40 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAV?$MS2Ptr@VItemModelData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VItemModelData@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VItemModelData@@@@@0@@Z 0x140567d10 ; prop
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAV?$MS2Ptr@VCItemData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCItemData@@@@PEAV1@QEAV1@1AEAV?$allocator@V?$MS2Ptr@VCItemData@@@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140567eb0 ; prop
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAV?$MS2Ptr@VDropNifData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VDropNifData@@@@PEAV1@QEAV1@1AEAV?$allocator@V?$MS2Ptr@VDropNifData@@@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140567f40 ; prop
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAV?$MS2Ptr@VItemModelData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VItemModelData@@@@PEAV1@QEAV1@1AEAV?$allocator@V?$MS2Ptr@VItemModelData@@@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140567fd0 ; prop
// MS2-PIN: ??$addressof@PEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x140568100 ; prop
// MS2-PIN: ??$addressof@UUnk_TrophyKey@@@std@@YAPEAUUnk_TrophyKey@@AEAU1@@Z 0x140568220 ; unique
// MS2-PIN: ??$construct@PEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@1@QEAPEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x140568260 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x140568300 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x140568350 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@1@AEAPEAU31@@Z 0x1405683a0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@UUnk_TrophyKey@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_TrophyKey@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_TrophyKey@@PEAX@std@@@1@QEAPEAU?$_Tree_node@UUnk_TrophyKey@@PEAX@1@AEAPEAU31@@Z 0x1405683f0 ; prop
// MS2-PIN: ??$construct@V?$MS2Ptr@VDropNifData@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VDropNifData@@@@@1@QEAV?$MS2Ptr@VDropNifData@@@@AEAV3@@Z 0x140568690 ; prop
// MS2-PIN: ??$construct@V?$MS2Ptr@VDropNifData@@@@AEBV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VDropNifData@@@@@1@QEAV?$MS2Ptr@VDropNifData@@@@AEBV3@@Z 0x1405686e0 ; prop
// MS2-PIN: ??$construct@V?$MS2Ptr@VCItemData@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCItemData@@@@@1@QEAV?$MS2Ptr@VCItemData@@@@AEAV3@@Z 0x140568780 ; prop
// MS2-PIN: ??$construct@V?$MS2Ptr@VCItemData@@@@AEBV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCItemData@@@@@1@QEAV?$MS2Ptr@VCItemData@@@@AEBV3@@Z 0x1405687d0 ; prop
// MS2-PIN: ??$construct@V?$MS2Ptr@VItemModelData@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VItemModelData@@@@@1@QEAV?$MS2Ptr@VItemModelData@@@@AEAV3@@Z 0x140568870 ; unique
// MS2-PIN: ??$construct@V?$MS2Ptr@VItemModelData@@@@AEBV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VItemModelData@@@@@1@QEAV?$MS2Ptr@VItemModelData@@@@AEBV3@@Z 0x1405688c0 ; prop
// MS2-PIN: ??$construct@V?$MS2Ptr@VItemModelData@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VItemModelData@@@@@1@QEAV?$MS2Ptr@VItemModelData@@@@$$QEAV3@@Z 0x140568910 ; unique
// MS2-PIN: ??$construct@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@AEBV12@@?$_Default_allocator_traits@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@@std@@@std@@SAXAEAV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@@1@QEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@1@AEBV31@@Z 0x140568960 ; unique
// MS2-PIN: ??$construct@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@V12@@?$_Default_allocator_traits@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@@std@@@std@@SAXAEAV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@@1@QEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@1@$$QEAV31@@Z 0x1405689b0 ; unique
// MS2-PIN: ??$construct@UUnk_TrophyKey@@AEBU1@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_TrophyKey@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_TrophyKey@@PEAX@std@@@1@QEAUUnk_TrophyKey@@AEBU3@@Z 0x140568a00 ; unique
// MS2-PIN: ??$destroy@PEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@1@QEAPEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@1@@Z 0x140568a50 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@1@@Z 0x140568ab0 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@1@@Z 0x140568ad0 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@1@@Z 0x140568af0 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@1@@Z 0x140568b30 ; prop
// MS2-PIN: ??$destroy@V?$MS2Ptr@VCItemData@@@@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCItemData@@@@@1@QEAV?$MS2Ptr@VCItemData@@@@@Z 0x140568b50 ; prop
// MS2-PIN: ??$destroy@V?$MS2Ptr@VDropNifData@@@@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VDropNifData@@@@@1@QEAV?$MS2Ptr@VDropNifData@@@@@Z 0x140568b70 ; prop
// MS2-PIN: ??$destroy@V?$MS2Ptr@VItemModelData@@@@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VItemModelData@@@@@1@QEAV?$MS2Ptr@VItemModelData@@@@@Z 0x140568b90 ; unique
// MS2-PIN: ??$emplace_back@AEBV?$MS2Ptr@VCItemData@@@@@?$vector@V?$MS2Ptr@VCItemData@@@@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VCItemData@@@@@Z 0x140568d90 ; prop
// MS2-PIN: ??$emplace_back@AEBV?$MS2Ptr@VItemModelData@@@@@?$vector@V?$MS2Ptr@VItemModelData@@@@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VItemModelData@@@@@Z 0x140568e00 ; prop
// MS2-PIN: ??$forward@AEAV?$MS2Ptr@VDropNifData@@@@@std@@YAAEAV?$MS2Ptr@VDropNifData@@@@AEAV1@@Z 0x140569120 ; prop
// MS2-PIN: ??$forward@AEAV?$MS2Ptr@VCItemData@@@@@std@@YAAEAV?$MS2Ptr@VCItemData@@@@AEAV1@@Z 0x140569130 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TrophyKey@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TrophyKey@@@std@@@std@@@0@AEAV10@@Z 0x140569170 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140569180 ; unique
// MS2-PIN: ??$forward@AEBV?$MS2Ptr@VItemModelData@@@@@std@@YAAEBV?$MS2Ptr@VItemModelData@@@@AEBV1@@Z 0x1405691f0 ; prop
// MS2-PIN: ??$forward@V?$MS2Ptr@VCItemData@@@@@std@@YA$$QEAV?$MS2Ptr@VCItemData@@@@AEAV1@@Z 0x140569270 ; unique
// MS2-PIN: ??$forward@V?$MS2Ptr@VDropNifData@@@@@std@@YA$$QEAV?$MS2Ptr@VDropNifData@@@@AEAV1@@Z 0x140569280 ; unique
// MS2-PIN: ??$forward@V?$MS2Ptr@VItemHousing@@@@@std@@YA$$QEAV?$MS2Ptr@VItemHousing@@@@AEAV1@@Z 0x140569290 ; unique
// MS2-PIN: ??$forward@V?$MS2Ptr@VItemModelData@@@@@std@@YA$$QEAV?$MS2Ptr@VItemModelData@@@@AEAV1@@Z 0x1405692a0 ; unique
// MS2-PIN: ??$forward@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1405692d0 ; unique
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TrophyKey@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TrophyKey@@@std@@@std@@@0@AEAV10@@Z 0x1405692e0 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1405692f0 ; unique
// MS2-PIN: ??$make_pair@HAEAV?$MS2Ptr@VCItemData@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VCItemData@@@@@0@$$QEAHAEAV?$MS2Ptr@VCItemData@@@@@Z 0x1405694f0 ; unique
// MS2-PIN: ??$move@AEAV?$MS2Ptr@VCItemData@@@@@std@@YA$$QEAV?$MS2Ptr@VCItemData@@@@AEAV1@@Z 0x140569550 ; prop
// MS2-PIN: ??$move@AEAV?$MS2Ptr@VDropNifData@@@@@std@@YA$$QEAV?$MS2Ptr@VDropNifData@@@@AEAV1@@Z 0x140569560 ; prop
// MS2-PIN: ??$move@AEAV?$MS2Ptr@VItemModelData@@@@@std@@YA$$QEAV?$MS2Ptr@VItemModelData@@@@AEAV1@@Z 0x140569570 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCItemData@@@@QEAA@$$QEAV0@@Z 0x14056a0e0 ; unique
// MS2-PIN: ??0?$Unk_BmPtr@VCColorPaletteInfo@@@@QEAA@AEBUUnk_BmNewTag@@@Z 0x14056a460 ; unique
// MS2-PIN: ??0?$MS2Ptr@VItemHousing@@@@QEAA@$$QEAV0@@Z 0x14056a600 ; unique
// MS2-PIN: ??0?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@1@@Z 0x14056aa20 ; prop
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCItemData@@@@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@QEAA@PEAV?$MS2Ptr@VCItemData@@@@AEAV?$allocator@V?$MS2Ptr@VCItemData@@@@@1@@Z 0x14056b3f0 ; prop
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@QEAA@PEAV?$MS2Ptr@VDropNifData@@@@AEAV?$allocator@V?$MS2Ptr@VDropNifData@@@@@1@@Z 0x14056b430 ; prop
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VItemModelData@@@@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@QEAA@PEAV?$MS2Ptr@VItemModelData@@@@AEAV?$allocator@V?$MS2Ptr@VItemModelData@@@@@1@@Z 0x14056b470 ; prop
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCItemData@@@@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@QEAA@XZ 0x14056c710 ; prop
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@QEAA@XZ 0x14056c750 ; prop
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VItemModelData@@@@V?$allocator@V?$MS2Ptr@VItemModelData@@@@@std@@@std@@QEAA@XZ 0x14056c790 ; prop
// MS2-PIN: ??1?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@QEAA@XZ 0x14056c8c0 ; prop
// MS2-PIN: ??1?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@QEAA@XZ 0x14056c900 ; prop
// MS2-PIN: ??4?$Unk_BmBoxPtr@V?$CAtlMap@HV?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@3@@ATL@@@@QEAAAEAV0@AEBV0@@Z 0x14056ce10 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14056d190 ; unique
// MS2-PIN: ??C?$MS2Ptr@VItemHousing@@@@QEBAPEAVItemHousing@@XZ 0x14056d580 ; unique
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14056dad0 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TrophyKey@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14056ddf0 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14056e250 ; unique
// MS2-PIN: ??_G?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@QEAAPEAXI@Z 0x14056ee40 ; prop
// MS2-PIN: ??_G?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@QEAAPEAXI@Z 0x14056ee80 ; prop
// MS2-PIN: ??_G?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@QEAAPEAXI@Z 0x14056eec0 ; prop
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VCItemData@@@@_K@Z 0x14056f5b0 ; unique
// MS2-PIN: ?GetColorMap@CColorPaletteInfo@@QEBA?AV?$Unk_BmBoxPtr@V?$CAtlMap@HV?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@3@@ATL@@@@XZ 0x140570eb0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140570f50 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@HMV?$CElementTraits@H@ATL@@V?$CElementTraits@M@2@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140571040 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@H@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140571130 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140571220 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VItemDropEffect@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VItemDropEffect@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140571400 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_BmPtr@VCColorPaletteInfo@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VCColorPaletteInfo@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1405714f0 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x140571990 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBA_NHAEAH@Z 0x140572d80 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEBA_NIAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x140572f20 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCItemData@@@@@ATL@@SAXPEAV?$MS2Ptr@VCItemData@@@@0_K@Z 0x140576890 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1405773a0 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HMV?$CElementTraits@H@ATL@@V?$CElementTraits@M@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140577490 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140577d00 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@HMV?$CElementTraits@H@ATL@@V?$CElementTraits@M@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140577dc0 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAPEAU__POSITION@@HH@Z 0x1405785f0 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@QEAA_N_KH@Z 0x140578ce0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CItemDataTable@@6B?$TSingleton@VCItemDataTable@@@@@ 0x142d5f500
// MS2-PIN: ??_7CItemDataTable@@6B?$CValidData@VCItemDataTable@@@@@ 0x142d5f510
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@ATL@@@ATL@@@@6B@ 0x142d5f538
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlMap@HV?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@3@@ATL@@@@6B@ 0x142d5f528
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140562290
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140562320
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1405623b0
// cf9: DropNifData-vector tree nodes deallocate 0x40 bytes, not 0x38.
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140562440
// cf9: the deleting destructor calls MS2Ptr<DropNifData>::~MS2Ptr.
// MS2-PIN: ??_G?$MS2Ptr@VDropNifData@@@@QEAAPEAXI@Z 0x14056ec00
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemdatatable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/itemdatatable.h"
#include <ppl.h>
#include <shlwapi.h>
#include <typeinfo>
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Data/Xml/<dir>/<file>
CString FUN_14071a840(const CString& strDir, const CString& strFile);   // the item model path of a dir and file
CString FUN_14071a940(unsigned nFile);                                  // the item model file of a model file number
CString FUN_14071ae20(const CString& strFile);                          // a string table file path
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
Unk_140165cf0* FUN_14028f8d0(Unk_140165cf0* pElem);                    // the <environment> child of an item row
unsigned FUN_14028c0d0(const char* psz);                                // a colour value of a "#rrggbb" style string
Unk_ConstColor FUN_140718770(const CString& str);                       // a hex colour
int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>& out);
void FUN_1403992a0(CString pattern, CString directory, std::vector<CString>& output, CString exclude, bool localOnly);  // filesystem.cpp
unsigned FUN_14053c690(unsigned nItemId);                               // the itemData file of an item id

// The client string tables (singleton at 0x143aac298): FUN_141811980(table, id) is the string of id in table.
class Unk_1401a9d70 { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_1401a9d70* FUN_1401a9d70();

// The empty-delegate error (the implicit default ctor 0x14056be40: `throw InvalidCallException()` value-initialises).
class InvalidCallException : public std::exception
{
};

template <class R>
R ThrowInvalidCall()
{
    throw InvalidCallException();
}

// @0x14056e650
template <> inline bool CItemDataTable::ColorFilter::operator()(const ItemColorEx& a1, MS2Ptr<CItemData> a2) const
{
    if (m_pImpl == 0)
        ThrowInvalidCall<bool>();
    return m_pImpl->Invoke(a1, a2);
}

// @0x14056c150
template <> inline CItemDataTable::ColorFilter::~Delegate()
{
    if (m_pImpl != 0)
        delete m_pImpl;
}

// @0x14056d500
// The packed colour value (a conversion of the clientconstants colour; its COMDAT is in this unit).
inline unsigned Unk_ColorValue(const Unk_ConstColor& c) { return c.argb; }

static void FindFiles(CString strExt, CString strDir, std::vector<CString>& out);
static int LoadXml(TiXmlDocument& doc, const char* pszPath);

// The market sort-key names (the header statics this unit includes; names are invented).
static CString s_strSortTypeNames[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
// The default item table's per-kind maps (written by ?\itemdefaultdata.cpp; the name is invented).
ATL::CAtlMap<int, int, ATL::CDefaultElementTraits<int> > g_itemDefaultSlotMaps[2];

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CItemDataTable::s_bInit;
#endif

// @0x140555a70
CColorPaletteInfo::CColorPaletteInfo()
{
    Init();
}

// MS2-FUNCTIONAL: box ptr NewTag temporaries / SEH state layout differ; behaviour equivalent
// @0x140555ae0
void CColorPaletteInfo::Init()
{
    m_spColors = Unk_BmBoxPtr<ColorArray>(Unk_BmNewTag(0));
    m_spColorMap = Unk_BmBoxPtr<ColorMap>(Unk_BmNewTag(0));
}

// @0x140555b80
void CColorPaletteInfo::Clear()
{
    if (m_spColors.get())
        m_spColors->RemoveAll();
    if (m_spColorMap.get())
        m_spColorMap->RemoveAll();
}

// @0x140555c00
bool CColorPaletteInfo::AddColor(MS2Ptr<ItemColorEx> spColor)
{
    if (spColor == 0)
        return false;
    if (m_spColors.get())
        m_spColors->Add(spColor);
    if (m_spColorMap.get())
        m_spColorMap->SetAt(spColor->m_nColor, spColor);
    return true;
}

// @0x140555ce0
CItemDataTable::CItemDataTable()
{
}

// @0x140556140
CItemDataTable::~CItemDataTable()
{
}

// @0x140556380
MS2Ptr<ItemDropEffect> CItemDataTable::GetDropEffect(int nType)
{
    CheckInit();
    MS2Ptr<ItemDropEffect> spEffect(0);
    if (m_mapDropEffect.Lookup(nType, spEffect))
        return spEffect;
    return MS2Ptr<ItemDropEffect>(0);
}

// @0x140556440
MS2Ptr<ItemDropEffect> CItemDataTable::GetItemDropEffect(unsigned nItemId, unsigned nValue)
{
    std::map<unsigned, std::vector<MS2Ptr<DropNifData> > >::iterator it = m_mapDropNif.find(nItemId);
    if (it == m_mapDropNif.end())
        return MS2Ptr<ItemDropEffect>(0);
    MS2Ptr<DropNifData> spNif;
    std::vector<MS2Ptr<DropNifData> >& nifs = it->second;
    for (size_t i = 0; i < nifs.size(); i++)
    {
        if (nifs[i]->FUN_140543550(nValue))
            spNif = nifs[i];
    }
    if (spNif == 0)
        return MS2Ptr<ItemDropEffect>(0);
    return GetDropEffect(spNif->FUN_140543590());
}

// @0x1405565f0
MS2Ptr<ItemMusicScore> CItemDataTable::GetMusicScore(unsigned nId)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    std::map<unsigned, MS2Ptr<ItemMusicScore> >::iterator it = m_mapMusicScore.find(nId);
    if (it != m_mapMusicScore.end())
        return it->second;
    return MS2Ptr<ItemMusicScore>(0);
}

// @0x1405566e0
MS2Ptr<ItemHousing> CItemDataTable::GetHousing(unsigned nId)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    std::map<unsigned, MS2Ptr<ItemHousing> >::iterator it = m_mapHousing.find(nId);
    if (it != m_mapHousing.end())
        return it->second;
    return MS2Ptr<ItemHousing>(0);
}

// @0x1405567e0
CString CItemDataTable::GetGradeNif(ItemGradeKey eGrade)
{
    CString str;
    if (m_mapGradeNif.Lookup(eGrade, str))
        return str;
    return CString("");
}

// @0x1405568a0
CString CItemDataTable::GetGradePetNif(ItemGradeKey eGrade)
{
    CString str;
    m_mapGradePetNif.Lookup(eGrade, str);
    return str;
}

// @0x140556930
CString CItemDataTable::GetGradeEffect(ItemGradeKey eGrade)
{
    CString str;
    if (m_mapGradeEffect.Lookup(eGrade, str))
        return str;
    return CString("");
}

// @0x1405569f0
unsigned CItemDataTable::GetTextColor(ItemGradeKey eGrade)
{
    unsigned nColor;
    if (m_mapTextColor.Lookup(eGrade, nColor))
        return nColor;
    return 0xffffff;
}

// @0x140556a40
CStringW CItemDataTable::GetTextColorString(ItemGradeKey eGrade)
{
    return StringFormat(L"#{0:x}", static_cast<unsigned long>(GetTextColor(eGrade)));
}

// @0x140556aa0
int CItemDataTable::GetWeaponSpeed(int nWeapon)
{
    int nSpeed;
    if (m_mapWeaponSpeed.Lookup(nWeapon, nSpeed))
        return nSpeed;
    return 0;
}

// @0x140556af0
float CItemDataTable::GetRevisionRatio(int nWeapon, int nIndex)
{
    if (nIndex == 0)
        return 1.0f;
    int nSpeed = GetWeaponSpeed(nWeapon);
    int nKey = nSpeed * 10 + nIndex;
    float fRatio;
    if (m_mapRevisionRatio.Lookup(nKey, fRatio))
        return fRatio;
    return 1.0f;
}

// @0x140556b70
void CItemDataTable::Load()
{
    TiXmlDocument doc;
    CString strPath = FUN_14071a5b0("Table", "ItemData.xml");
    if (LoadXml(doc, strPath) == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}]", strPath);
        return;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    LoadDropItemAsset(pRoot);
    LoadDropStyle(pRoot);
    LoadGradeNif(pRoot);
    LoadGradePetNif(pRoot);
    LoadGradeEffect(pRoot);
    LoadTextColor(pRoot);
    LoadWeaponSpeed(pRoot);
    LoadRevisionRatio(pRoot);
    LoadEnchant(pRoot);
    LoadUnlimitedEnchant(pRoot);
    InitItemTags();
    LoadTagItemIds(pRoot);
    FUN_1401d1160(strPath);
    LoadUiMaterialSound();
    LoadColorPalette(FUN_14071a5b0("Table", "colorPalette.xml"));
    LoadMusicScore();
    LoadHousing();
    SetInit(true);
}

// @0x140556ea0
void CItemDataTable::Reload()
{
    m_mapGradeNif.RemoveAll();
    m_mapGradePetNif.RemoveAll();
    m_mapGradeEffect.RemoveAll();
    m_mapTextColor.RemoveAll();
    m_mapDropEffect.RemoveAll();
    m_mapWeaponSpeed.RemoveAll();
    m_mapRevisionRatio.RemoveAll();
    Load();
}

// @0x140556f50
void CItemDataTable::LoadAllItemData()
{
    std::vector<CString> files;
    FindFiles(".xml", "./Data/xml/ItemData", files);
    // @0x14056e5c0
    Concurrency::parallel_for_each(std::begin(files), std::end(files), [this](CString strFile) {
        CString strName = PathFindFileNameA(strFile);
        strName.Replace(".xml", "");
        unsigned nFile = FUN_1407181d0(strName);
        LoadItemDataFile(nFile);
    });
}

// @0x140557050
void CItemDataTable::LoadBlackMarketSearchable()
{
    CString strPath = FUN_14071a5b0("Table", "blackMarketSearchableItemID.xml");
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("v"); pNode != 0; pNode = pNode->FUN_140168650("v"))
    {
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nId);
        if (strName.IsEmpty())
            continue;
        m_mapBlackMarketSearchable.SetAt(strName, nId);
    }
}

// @0x140557250
std::set<Unk_TrophyKey>* CItemDataTable::GetTrophySet()
{
    return &m_setTrophy;
}

// MS2-FUNCTIONAL: string temporaries and SEH state layout differ; behaviour equivalent
// @0x140557270
CString CItemDataTable::GetEnchantNif(int nWeapon, int nEnchant, int nUnlimited, unsigned nType)
{
    if (nUnlimited > 0)
    {
        CString strNif;
        if (m_mapUnlimitedEnchant.Lookup(nWeapon, strNif))
        {
            strNif.Replace(".xml", "");
            CString str;
            str.Format("%s_Type%d.xml", (const char*)strNif, nType);
            return str;
        }
    }
    Unk_GameEventIntRange range0(5, 9);
    Unk_GameEventIntRange range1(10, 12);
    Unk_GameEventIntRange range2(13, 14);
    Unk_GameEventIntRange range3(15, 15);
    int nLevel;
    if (range0.IsInRange(nEnchant))
        nLevel = 0;
    else if (range1.IsInRange(nEnchant))
        nLevel = 1;
    else if (range2.IsInRange(nEnchant))
        nLevel = 2;
    else if (range3.IsInRange(nEnchant))
        nLevel = 3;
    else
        return CString("");
    CString strNif;
    if (!m_mapEnchant.Lookup(GetEnchantKey(nWeapon, nLevel), strNif))
        return CString("");
    strNif.Replace(".xml", "");
    CString str;
    str.Format("%s_Type%d.xml", (const char*)strNif, nType);
    return str;
}

// @0x1405575b0
int CItemDataTable::GetTagItemId(ItemTagKey eTag)
{
    MS2Ptr<ItemTagParam> spTag(0);
    if (m_mapTag.Lookup(eTag, spTag))
        return spTag->m_nItemId;
    return 0;
}

// @0x140557640
ItemTagKey CItemDataTable::GetTagByName(const CString& strName)
{
    for (POSITION pos = m_mapTag.GetStartPosition(); pos != 0; m_mapTag.GetNext(pos))
    {
        MS2Ptr<ItemTagParam> spTag = m_mapTag.GetValueAt(pos);
        if (spTag->m_strName.CompareNoCase(strName) == 0)
            return spTag->m_eTag;
    }
    return ItemTagKey(0);
}

// @0x140557730
CString CItemDataTable::GetTagName(ItemTagKey eTag)
{
    MS2Ptr<ItemTagParam> spTag = FindTag(eTag);
    if (spTag == 0)
        return CString("");
    return spTag->m_strName;
}

// @0x1405577f0
CItemDataTable::ModelPtr CItemDataTable::GetModel(unsigned nPreset)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    ModelPtr spModel = FindModel(nPreset);
    if (spModel == 0)
    {
        LoadModelFile(ItemModelData::FUN_14054aec0(nPreset));
        spModel = FindModel(nPreset);
    }
    return spModel;
}

// @0x140557910
void CItemDataTable::FUN_140557910(int)
{
}

// @0x140557920
void CItemDataTable::GetHousingByCategory(int nCategory, ATL::CAtlArray<MS2Ptr<ItemHousing> >& out)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    for (std::map<unsigned, MS2Ptr<ItemHousing> >::iterator it = m_mapHousing.begin(); it != m_mapHousing.end(); it++)
    {
        MS2Ptr<ItemHousing> spHousing = it->second;
        if (spHousing->categoryIndex != nCategory)
            continue;
        out.Add(spHousing);
    }
}

// MS2-FUNCTIONAL: job switch lowering and SEH state layout differ; behaviour equivalent
// @0x140557a30
bool CItemDataTable::FindItems(unsigned short nLevel, int nGender, int nJob, int nType, ATL::CAtlArray<ItemDataPtr>& out)
{
    unsigned nMaxLevel = 0;
    Unk_CriticalSectionLock lock(m_cs, 1);
    for (auto& kv : m_mapItem)
    {
        CItemData* pItem = kv.second.get();
        if (!pItem->FUN_14053cbc0() || !pItem->FUN_14053c8e0(nJob) || !pItem->FUN_14053c940(nGender)
            || !pItem->FUN_14053c9a0(nLevel))
            continue;
        if (!pItem->FUN_14053eba0()->FUN_14054b450(nType) || pItem->FUN_14053e130())
            continue;
        if (nType == 5)
        {
            int nGroup = 30;
            switch (nJob)
            {
            case 1: nGroup = 30; break;
            case 10: nGroup = 32; break;
            case 20: nGroup = 50; break;
            case 30: nGroup = 52; break;
            case 40: nGroup = 33; break;
            case 50: nGroup = 51; break;
            case 60: nGroup = 53; break;
            case 70: nGroup = 31; break;
            case 80: nGroup = 34; break;
            case 90: nGroup = 54; break;
            case 100: nGroup = 55; break;
            case 110: nGroup = 56; break;
            }
            if (pItem->FUN_14053c620() != nGroup)
                continue;
        }
        else if (nType == 4)
        {
            int nGroup = 0;
            switch (nJob)
            {
            case 1: nGroup = 0; break;
            case 10: nGroup = 41; break;
            case 20: nGroup = 0; break;
            case 30: nGroup = 0; break;
            case 40: nGroup = 40; break;
            case 50: nGroup = 0; break;
            case 60: nGroup = 0; break;
            case 70: nGroup = 31; break;
            case 80: nGroup = 34; break;
            case 90: nGroup = 0; break;
            case 100: nGroup = 55; break;
            case 110: nGroup = 56; break;
            }
            if (nGroup == 0 || pItem->FUN_14053c620() != nGroup)
                continue;
        }
        if (nMaxLevel < pItem->limit.levelLimit)
        {
            nMaxLevel = pItem->limit.levelLimit;
            out.RemoveAll();
        }
        if (nMaxLevel == pItem->limit.levelLimit)
            out.Add(ItemDataPtr(pItem));
    }
    return !out.IsEmpty();
}

// @0x140557f70
CItemDataTable::ItemDataPtr CItemDataTable::GetItemData(int nItemId)
{
    if (nItemId == 0)
        return ItemDataPtr(0);
    ItemDataPtr spItem = FindItemData(nItemId);
    if (spItem.get() != 0)
        return spItem;
    LoadItemDataFile(FUN_14053c690(nItemId));
    return FindItemData(nItemId);
}

// @0x140558060
void CItemDataTable::LoadItemFile(const CString& strPath, std::vector<ItemDataPtr>& out)
{
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("item"); pNode != 0; pNode = pNode->FUN_140168650("item"))
    {
        ItemDataPtr spItem(new CItemData);
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        spItem->FUN_14053c4f0(nId);
        Unk_140165cf0* pEnv = FUN_14028f8d0(pNode);
        if (pEnv == 0)
            continue;
        spItem->Load(pEnv);
        out.push_back(spItem);
    }
}

// @0x140558260
void CItemDataTable::LoadItemDataFile(unsigned nFile)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    if (m_setItemFile.find(nFile) != m_setItemFile.end())
        return;
    CString strPath = FUN_14071a5b0("itemData", Unk_SocketFormat("{0:03d}.xml", nFile));
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("item"); pNode != 0; pNode = pNode->FUN_140168650("item"))
    {
        ItemDataPtr spItem(new CItemData);
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        spItem->FUN_14053c4f0(nId);
        Unk_140165cf0* pEnv = FUN_14028f8d0(pNode);
        if (pEnv == 0)
            continue;
        spItem->Load(pEnv);
        OnItemLoaded(spItem);
        m_mapItem.insert(std::make_pair(spItem->FUN_14053c510(), spItem));
    }
    m_setItemFile.insert(nFile);
}

// @0x140558690
CString CItemDataTable::GetUiMaterialSound(unsigned nMaterial)
{
    CheckInit();
    static CString s_strDefault("09300001");
    if (nMaterial == 0)
        return s_strDefault;
    CString strSound;
    if (m_mapUiMaterialSound.Lookup(nMaterial, strSound))
        return strSound;
    return s_strDefault;
}

// MS2-FUNCTIONAL: exe materialises the box null test into a bool temporary; behaviour equivalent
// @0x1405587f0
MS2Ptr<ItemColorEx> CItemDataTable::GetPaletteColor(int nPalette, unsigned nIndex)
{
    CheckInit();
    Unk_BmPtr<CColorPaletteInfo> spInfo(0);
    if (m_mapPalette.Lookup(nPalette, spInfo))
    {
        Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> spColors = spInfo->GetColors();
        if (spColors.get() != 0 && nIndex < spColors->GetCount())
            return spColors->GetAt(nIndex);
    }
    return MS2Ptr<ItemColorEx>(0);
}

// MS2-FUNCTIONAL: exe materialises the box null test into a bool temporary; behaviour equivalent
// @0x140558960
MS2Ptr<ItemColorEx> CItemDataTable::GetPaletteColorBySN(int nPalette, int nColorSN)
{
    CheckInit();
    Unk_BmPtr<CColorPaletteInfo> spInfo;
    if (m_mapPalette.Lookup(nPalette, spInfo))
    {
        Unk_BmBoxPtr<CColorPaletteInfo::ColorMap> spMap = spInfo->GetColorMap();
        if (spMap.get() != 0 && !spMap->IsEmpty())
        {
            MS2Ptr<ItemColorEx> spColor(0);
            spMap->Lookup(nColorSN, spColor);
            return spColor;
        }
    }
    return MS2Ptr<ItemColorEx>(0);
}

// @0x140558ad0
Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> CItemDataTable::GetPaletteColors(int nPalette)
{
    CheckInit();
    Unk_BmPtr<CColorPaletteInfo> spInfo;
    if (m_mapPalette.Lookup(nPalette, spInfo))
        return spInfo->GetColors();
    return Unk_BmBoxPtr<CColorPaletteInfo::ColorArray>(0);
}

// MS2-FUNCTIONAL: random index temporaries / frame layout differ; behaviour equivalent
// @0x140558b90
MS2Ptr<ItemColorEx> CItemDataTable::GetPaletteColorOrRandom(int nPalette, int nIndex)
{
    CheckInit();
    Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> spColors = GetPaletteColors(nPalette);
    if (spColors == 0)
        return MS2Ptr<ItemColorEx>(0);
    size_t nCount = spColors->GetCount();
    int nSel = nIndex;
    if (nIndex == -1 || (int)nCount <= nIndex)
        nSel = (int)(rand() % nCount);
    return spColors->GetAt(nSel);
}

// MS2-FUNCTIONAL: iteration temporaries and SEH state layout differ; behaviour equivalent
// @0x140558cc0
MS2Ptr<ItemColorEx> CItemDataTable::FindPaletteColor(int nPalette, const int& nCh0)
{
    CheckInit();
    Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> spColors = GetPaletteColors(nPalette);
    if (!(spColors == 0) && !spColors->IsEmpty())
    {
        size_t nCount = spColors->GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            MS2Ptr<ItemColorEx> spColor = spColors->GetAt(i);
            if (spColor == 0)
                continue;
            if (spColor->m_aValues[0] == nCh0)
                return spColor;
        }
    }
    return MS2Ptr<ItemColorEx>(0);
}

// MS2-FUNCTIONAL: delegate call temporaries and SEH state layout differ; behaviour equivalent
// @0x140558e80
MS2Ptr<ItemColorEx> CItemDataTable::FindPaletteColor(int nPalette, ItemDataPtr spItem, ColorFilter fnFilter)
{
    CheckInit();
    Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> spColors = GetPaletteColors(nPalette);
    if (!(spColors == 0) && !spColors->IsEmpty())
    {
        size_t nCount = spColors->GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            MS2Ptr<ItemColorEx> spColor = spColors->GetAt(i);
            if (spColor == 0)
                continue;
            if (fnFilter(*spColor, spItem) == true)
                return spColor;
        }
    }
    return MS2Ptr<ItemColorEx>(0);
}

// MS2-FUNCTIONAL: iteration temporaries and SEH state layout differ; behaviour equivalent
// @0x1405590e0
MS2Ptr<ItemColorEx> CItemDataTable::FindPaletteColor(int nPalette, const int& nCh0, const int& nCh1)
{
    CheckInit();
    Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> spColors = GetPaletteColors(nPalette);
    if (!(spColors == 0) && !spColors->IsEmpty())
    {
        size_t nCount = spColors->GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            MS2Ptr<ItemColorEx> spColor = spColors->GetAt(i);
            if (spColor == 0)
                continue;
            if (spColor->m_aValues[0] == nCh0 && spColor->m_aValues[1] == nCh1)
                return spColor;
        }
    }
    return MS2Ptr<ItemColorEx>(0);
}

// @0x1405592c0
ATL::CRBMap<CStringW, int, ATL::CStringElementTraitsI<CStringW> >* CItemDataTable::GetBlackMarketSearchable()
{
    return &m_mapBlackMarketSearchable;
}

// @0x1405592e0
void CItemDataTable::GetAllItemData(std::vector<ItemDataPtr>& out)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    out.reserve(m_mapItem.size());
    for (auto& kv : m_mapItem)
        out.push_back(kv.second);
}

// @0x1405593d0
void CItemDataTable::GetAllModels(std::vector<ModelPtr>& out)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    out.reserve(m_mapModel.size());
    for (std::map<unsigned, ModelPtr>::iterator it = m_mapModel.begin(); it != m_mapModel.end(); it++)
        out.push_back(it->second);
}

// MS2-FUNCTIONAL: XML attribute temporaries and SEH state layout differ; behaviour equivalent
// @0x1405594b0
void CItemDataTable::LoadItemNameIds(std::vector<unsigned>& out)
{
    out.reserve(40000);
    CString strPath = FUN_14071ae20("itemName.xml");
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "key", "id", nodes);
    for (Unk_140165cf0* pNode : nodes)
    {
        unsigned nId;
        FUN_140873220(pNode, "id", nId);
        out.push_back(nId);
    }
}

// @0x140559690
void CItemDataTable::ResetAllItemData()
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    for (auto& kv : m_mapItem)
        kv.second->FUN_14053ed00();
}

// @0x140559750
CString CItemDataTable::GetDefaultUiMaterialSound()
{
    return CString("09600011");
}

// @0x1405597a0
void CItemDataTable::LoadDropStyle(Unk_140165cf0* pRoot)
{
    Unk_140165cf0* pStyle = pRoot->FUN_140165cf0("dropStyle");
    if (pStyle == 0)
        return;
    for (Unk_140165cf0* pNode = pStyle->FUN_140165cf0("v"); pNode != 0; pNode = pNode->FUN_140168650("v"))
    {
        MS2Ptr<ItemDropEffect> spEffect(new ItemDropEffect);
        spEffect->Load(pNode);
        m_mapDropEffect.SetAt(spEffect->typeID, spEffect);
    }
}

// MS2-FUNCTIONAL: XML node temporaries and SEH state layout differ; behaviour equivalent
// @0x1405598c0
void CItemDataTable::LoadDropItemAsset(Unk_140165cf0* pRoot)
{
    Unk_140165cf0* pAsset = pRoot->FUN_140165cf0("dropItemAsset");
    if (pAsset == 0)
        return;
    for (Unk_140165cf0* pItem = pAsset->FUN_140165cf0("Item"); pItem != 0; pItem = pItem->FUN_140168650("Item"))
    {
        int nItemId = 0;
        FUN_140873220(pItem, "itemID", reinterpret_cast<unsigned&>(nItemId));
        if (nItemId == 0)
            continue;
        std::vector<MS2Ptr<DropNifData> >& nifs = m_mapDropNif[nItemId];
        for (Unk_140165cf0* pNode = pItem->FUN_140165cf0("v"); pNode != 0; pNode = pNode->FUN_140168650("v"))
        {
            MS2Ptr<DropNifData> spNif(new DropNifData);
            spNif->FUN_1405434f0(pNode);
            nifs.push_back(spNif);
        }
    }
}

// @0x140559a50
void CItemDataTable::LoadGradeNif(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("gradeNif"); pNode != 0; pNode = pNode->FUN_140168650("gradeNif"))
    {
        int nGrade;
        FUN_1408731e0(pNode, "id", nGrade);
        CString strNif = FUN_14015f710(pNode, "nif", CString(""));
        m_mapGradeNif.SetAt(ItemGradeKey(nGrade), strNif);
    }
}

// @0x140559b40
void CItemDataTable::LoadGradePetNif(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("gradePetNif"); pNode != 0; pNode = pNode->FUN_140168650("gradePetNif"))
    {
        int nGrade;
        FUN_1408731e0(pNode, "id", nGrade);
        CString strNif = FUN_14015f710(pNode, "nif", CString(""));
        m_mapGradePetNif.SetAt(ItemGradeKey(nGrade), strNif);
    }
}

// @0x140559c30
void CItemDataTable::LoadGradeEffect(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("gradeEffect"); pNode != 0; pNode = pNode->FUN_140168650("gradeEffect"))
    {
        int nGrade;
        FUN_1408731e0(pNode, "id", nGrade);
        CString strEffect = FUN_14015f710(pNode, "effect", CString(""));
        m_mapGradeEffect.SetAt(ItemGradeKey(nGrade), strEffect);
    }
}

// @0x140559d20
void CItemDataTable::LoadTextColor(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("Text"); pNode != 0; pNode = pNode->FUN_140168650("Text"))
    {
        int nGrade;
        FUN_1408731e0(pNode, "id", nGrade);
        CString strColor;
        strColor = FUN_14015f710(pNode, "color", CString(""));
        unsigned nColor = FUN_14028c0d0(strColor);
        m_mapTextColor.SetAt(ItemGradeKey(nGrade), nColor);
    }
}

// @0x140559e60
void CItemDataTable::LoadWeaponSpeed(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("weaponspeed"); pNode != 0; pNode = pNode->FUN_140168650("weaponspeed"))
    {
        int nWeapon;
        int nRank;
        FUN_1408731e0(pNode, "id", nWeapon);
        FUN_1408731e0(pNode, "speedRank", nRank);
        m_mapWeaponSpeed.SetAt(nWeapon, nRank);
    }
}

// @0x140559f00
void CItemDataTable::LoadRevisionRatio(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("revisionratio"); pNode != 0; pNode = pNode->FUN_140168650("revisionratio"))
    {
        int nKey;
        float fRatio;
        FUN_1408731e0(pNode, "id", nKey);
        FUN_140873360(pNode, "ratio", fRatio);
        m_mapRevisionRatio.SetAt(nKey, fRatio);
    }
}

// @0x140559fa0
void CItemDataTable::LoadEnchant(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("enchant"); pNode != 0; pNode = pNode->FUN_140168650("enchant"))
    {
        int nWeapon = 0;
        FUN_1408731e0(pNode, "weapon", nWeapon);
        for (Unk_140165cf0* pEffect = pNode->FUN_140165cf0("effect"); pEffect != 0; pEffect = pEffect->FUN_140168650("effect"))
        {
            int nLevel = 0;
            FUN_1408731e0(pEffect, "level", nLevel);
            CString strName = FUN_14015f710(pEffect, "name", CString(""));
            if (strName.IsEmpty())
                continue;
            m_mapEnchant.SetAt(GetEnchantKey(nWeapon, nLevel), strName);
        }
    }
}

// @0x14055a120
void CItemDataTable::LoadUnlimitedEnchant(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("unlimitedenchant"); pNode != 0; pNode = pNode->FUN_140168650("unlimitedenchant"))
    {
        int nWeapon = 0;
        FUN_1408731e0(pNode, "weapon", nWeapon);
        CString strName = FUN_14015f710(pNode, "name", CString(""));
        if (strName.IsEmpty())
            continue;
        m_mapUnlimitedEnchant.SetAt(nWeapon, strName);
    }
}

// @0x14055a230
void CItemDataTable::LoadUiMaterialSound()
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    m_mapUiMaterialSound.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "uiMaterialSound.xml");
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("uiMaterial"); pNode != 0; pNode = pNode->FUN_140168650("uiMaterial"))
    {
        int nId = 0;
        CString strSound("");
        FUN_1408731e0(pNode, "id", nId);
        FUN_1408733e0(pNode, "sound", strSound);
        if (strSound.IsEmpty())
            continue;
        m_mapUiMaterialSound.SetAt(nId, strSound);
    }
}

// MS2-FUNCTIONAL: CString temporaries order and SEH state layout differ; behaviour equivalent
// @0x14055a4a0
void CItemDataTable::LoadColorPalette(const CString& strPath)
{
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    Unk_CriticalSectionLock lock(m_cs, 1);
    for (Unk_140165cf0* pPalette = pRoot->FUN_140165cf0("colorPalette"); pPalette != 0; pPalette = pPalette->FUN_140168650("colorPalette"))
    {
        int nId = 0;
        FUN_140873220(pPalette, "id", reinterpret_cast<unsigned&>(nId));
        Unk_BmPtr<CColorPaletteInfo> spInfo(0);
        if (!m_mapPalette.Lookup(nId, spInfo))
            spInfo = Unk_BmPtr<CColorPaletteInfo>(Unk_BmNewTag(0));
        else
            spInfo->Clear();
        for (Unk_140165cf0* pColor = pPalette->FUN_140165cf0("color"); pColor != 0; pColor = pColor->FUN_140168650("color"))
        {
            CString str;
            MS2Ptr<ItemColorEx> spColor(new ItemColorEx(nId));
            str = FUN_14015f710(pColor, "ch0", CString(""));
            spColor->m_aValues[0] = Unk_ColorValue(FUN_140718770(str));
            str = FUN_14015f710(pColor, "ch1", CString(""));
            spColor->m_aValues[1] = Unk_ColorValue(FUN_140718770(str));
            str = FUN_14015f710(pColor, "ch2", CString(""));
            spColor->m_aValues[2] = Unk_ColorValue(FUN_140718770(str));
            str = FUN_14015f710(pColor, "palette", CString(""));
            spColor->m_n38 = Unk_ColorValue(str.GetLength() < 1 ? Unk_ConstColor(spColor->m_aValues[0]) : FUN_140718770(str));
            FUN_1408736d0(pColor, "show2color", spColor->m_bFlag);
            FUN_140873220(pColor, "achieveID", reinterpret_cast<unsigned&>(spColor->m_n24));
            FUN_1408731e0(pColor, "achieveGrade", spColor->m_n28);
            FUN_140873220(pColor, "stringKey", reinterpret_cast<unsigned&>(spColor->m_n2c));
            FUN_1408731e0(pColor, "colorSN", spColor->m_nColor);
            str = FUN_14015f710(pColor, "ch0_eye", CString(""));
            spColor->m_n30 = Unk_ColorValue(FUN_140718770(str));
            str = FUN_14015f710(pColor, "ch2_eye", CString(""));
            spColor->m_n34 = Unk_ColorValue(FUN_140718770(str));
            spInfo->AddColor(spColor);
        }
        m_mapPalette.SetAt(nId, spInfo);
    }
}

// @0x14055ad50
void CItemDataTable::LoadMusicScore()
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    m_mapMusicScore.clear();
    CString strPath = FUN_14071a5b0("Table", "MusicScore.xml");
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("MusicScore"); pNode != 0; pNode = pNode->FUN_140168650("MusicScore"))
    {
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        MS2Ptr<ItemMusicScore> spScore(new ItemMusicScore);
        spScore->FUN_14054a8c0(pNode);
        m_mapMusicScore.insert(std::make_pair(nId, spScore));
    }
}

// @0x14055b030
void CItemDataTable::LoadHousing()
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    m_mapHousing.clear();
    CString strPath = FUN_14071a5b0("Table", "Housing.xml");
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("housing"); pNode != 0; pNode = pNode->FUN_140168650("housing"))
    {
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        MS2Ptr<ItemHousing> spHousing(new ItemHousing);
        spHousing->FUN_140548fe0(pNode, nId);
        if (spHousing->trophyID > 0)
        {
            Unk_TrophyKey trophy(spHousing->trophyID, spHousing->trophyLevel);
            if (m_setTrophy.find(trophy) == m_setTrophy.end())
                m_setTrophy.insert(trophy);
        }
        m_mapHousing.insert(std::make_pair(nId, spHousing));
    }
}

// @0x14055b3f0
void CItemDataTable::InitItemTags()
{
    AddItemTag(ItemTagKey(1), "FreeChannelChatCoupon");
    AddItemTag(ItemTagKey(2), "FreeWorldChatCoupon");
    AddItemTag(ItemTagKey(3), "FreeSuperChatCoupon");
    AddItemTag(ItemTagKey(4), "FreeReviveCoupon");
    AddItemTag(ItemTagKey(5), "FreeDesignCoupon");
    AddItemTag(ItemTagKey(6), "FreePetNameChangeCoupon");
    AddItemTag(ItemTagKey(7), "DungeonRewardTicketA");
    AddItemTag(ItemTagKey(8), "DungeonRewardTicketB");
    AddItemTag(ItemTagKey(9), "DungeonRewardTicketC");
    AddItemTag(ItemTagKey(10), "air_taxi");
    AddItemTag(ItemTagKey(11), "air_taxi_advanced");
    AddItemTag(ItemTagKey(12), "beauty_face");
    AddItemTag(ItemTagKey(13), "beauty_hair");
    AddItemTag(ItemTagKey(14), "beauty_itemcolor");
    AddItemTag(ItemTagKey(15), "beauty_skin");
    AddItemTag(ItemTagKey(16), "beauty_makeup");
    AddItemTag(ItemTagKey(17), "beauty_hair_special");
    AddItemTag(ItemTagKey(18), "beauty_hair_special_bonus");
    AddItemTag(ItemTagKey(19), "Cashshop_Figure");
    AddItemTag(ItemTagKey(20), "party_call");
    AddItemTag(ItemTagKey(21), "ShadowPointReset");
    AddItemTag(ItemTagKey(22), "LulluKey");
    AddItemTag(ItemTagKey(23), "LulluBox");
    AddItemTag(ItemTagKey(24), "LulluKey01");
    AddItemTag(ItemTagKey(25), "LulluBox01");
    AddItemTag(ItemTagKey(26), "LulluKey02");
    AddItemTag(ItemTagKey(27), "LulluBox02");
    AddItemTag(ItemTagKey(28), "LulluKey03");
    AddItemTag(ItemTagKey(29), "LulluBox03");
    AddItemTag(ItemTagKey(30), "LulluKey04");
    AddItemTag(ItemTagKey(31), "LulluBox04");
    AddItemTag(ItemTagKey(32), "LulluKey05");
    AddItemTag(ItemTagKey(33), "LulluBox05");
    AddItemTag(ItemTagKey(34), "LulluKey06");
    AddItemTag(ItemTagKey(35), "LulluBox06");
    AddItemTag(ItemTagKey(36), "LulluKey07");
    AddItemTag(ItemTagKey(37), "LulluBox07");
    AddItemTag(ItemTagKey(38), "LulluKey08");
    AddItemTag(ItemTagKey(39), "LulluBox08");
    AddItemTag(ItemTagKey(40), "LulluKey09");
    AddItemTag(ItemTagKey(41), "LulluBox09");
    AddItemTag(ItemTagKey(42), "LulluKey10");
    AddItemTag(ItemTagKey(43), "LulluBox10");
    AddItemTag(ItemTagKey(44), "LulluKey11");
    AddItemTag(ItemTagKey(45), "LulluBox11");
    AddItemTag(ItemTagKey(46), "LulluKey12");
    AddItemTag(ItemTagKey(47), "LulluBox12");
    AddItemTag(ItemTagKey(48), "LulluKey13");
    AddItemTag(ItemTagKey(49), "LulluBox13");
    AddItemTag(ItemTagKey(50), "LulluKey14");
    AddItemTag(ItemTagKey(51), "LulluBox14");
    AddItemTag(ItemTagKey(52), "LulluKey15");
    AddItemTag(ItemTagKey(53), "LulluBox15");
    AddItemTag(ItemTagKey(54), "LulluKey16");
    AddItemTag(ItemTagKey(55), "LulluBox16");
    AddItemTag(ItemTagKey(56), "LulluKey17");
    AddItemTag(ItemTagKey(57), "LulluBox17");
    AddItemTag(ItemTagKey(58), "LulluKey18");
    AddItemTag(ItemTagKey(59), "LulluBox18");
    AddItemTag(ItemTagKey(60), "LulluKey19");
    AddItemTag(ItemTagKey(61), "LulluBox19");
    AddItemTag(ItemTagKey(62), "LulluKey20");
    AddItemTag(ItemTagKey(63), "LulluBox20");
    AddItemTag(ItemTagKey(64), "LulluKey21");
    AddItemTag(ItemTagKey(65), "LulluBox21");
    AddItemTag(ItemTagKey(66), "LulluKey22");
    AddItemTag(ItemTagKey(67), "LulluBox22");
    AddItemTag(ItemTagKey(68), "LulluKey23");
    AddItemTag(ItemTagKey(69), "LulluBox23");
    AddItemTag(ItemTagKey(70), "LulluKey24");
    AddItemTag(ItemTagKey(71), "LulluBox24");
    AddItemTag(ItemTagKey(72), "LulluKey25");
    AddItemTag(ItemTagKey(73), "LulluBox25");
    AddItemTag(ItemTagKey(74), "LulluKey26");
    AddItemTag(ItemTagKey(75), "LulluBox26");
    AddItemTag(ItemTagKey(76), "LulluKey27");
    AddItemTag(ItemTagKey(77), "LulluBox27");
    AddItemTag(ItemTagKey(78), "LulluKey28");
    AddItemTag(ItemTagKey(79), "LulluBox28");
    AddItemTag(ItemTagKey(80), "LulluKey29");
    AddItemTag(ItemTagKey(81), "LulluBox29");
    AddItemTag(ItemTagKey(82), "LulluKey30");
    AddItemTag(ItemTagKey(83), "LulluBox30");
    AddItemTag(ItemTagKey(84), "PetBox");
    AddItemTag(ItemTagKey(85), "DungeonLimitItem");
    AddItemTag(ItemTagKey(86), "SkinGemDustA");
    AddItemTag(ItemTagKey(87), "SkinGemDustB");
    AddItemTag(ItemTagKey(88), "SkinCrystal");
    AddItemTag(ItemTagKey(89), "SkinGemMaterial");
    AddItemTag(ItemTagKey(90), "CharmStone");
    AddItemTag(ItemTagKey(91), "ProtectStone");
    AddItemTag(ItemTagKey(92), "MetaCell");
    AddItemTag(ItemTagKey(93), "RedCrystal");
    AddItemTag(ItemTagKey(94), "GreenCrystal");
    AddItemTag(ItemTagKey(95), "BlueCrystal");
    AddItemTag(ItemTagKey(96), "CrystalPiece");
    AddItemTag(ItemTagKey(97), "Onix");
    AddItemTag(ItemTagKey(98), "ChaosOnix");
    AddItemTag(ItemTagKey(99), "CrystalGemstone");
    AddItemTag(ItemTagKey(100), "FishingLure");
    AddItemTag(ItemTagKey(101), "LockItemOptionWeapon");
    AddItemTag(ItemTagKey(102), "LockItemOptionArmor");
    AddItemTag(ItemTagKey(103), "LockItemOptionAccessory");
    AddItemTag(ItemTagKey(104), "LockItemOptionPet");
    AddItemTag(ItemTagKey(105), "UGCEventOxOpen");
    AddItemTag(ItemTagKey(106), "ItemExtraction");
    AddItemTag(ItemTagKey(107), "PetExtraction");
    AddItemTag(ItemTagKey(108), "ExpenseRewardTicket");
    AddItemTag(ItemTagKey(109), "AutoMastery");
    AddItemTag(ItemTagKey(110), "DustBlue");
    AddItemTag(ItemTagKey(111), "DustPurple");
    AddItemTag(ItemTagKey(112), "DustOrange");
    AddItemTag(ItemTagKey(113), "DustWhite");
    AddItemTag(ItemTagKey(114), "DustRed");
    AddItemTag(ItemTagKey(115), "DustGreen");
    AddItemTag(ItemTagKey(116), "DustCyan");
    AddItemTag(ItemTagKey(117), "DustYellow");
    AddItemTag(ItemTagKey(118), "SkillBookTreeAddTabCoupon");
    AddItemTag(ItemTagKey(119), "EpicCharmStone");
    AddItemTag(ItemTagKey(120), "EpicProtectStone");
    AddItemTag(ItemTagKey(121), "SlimeFood");
    AddItemTag(ItemTagKey(122), "Firework");
    AddItemTag(ItemTagKey(123), "GemstoneA01");
    AddItemTag(ItemTagKey(124), "GemstoneA02");
    AddItemTag(ItemTagKey(125), "GemstoneA03");
    AddItemTag(ItemTagKey(126), "GemstoneA04");
    AddItemTag(ItemTagKey(127), "GemstoneA05");
    AddItemTag(ItemTagKey(128), "GemstoneA06");
    AddItemTag(ItemTagKey(129), "GemstoneA07");
    AddItemTag(ItemTagKey(130), "GemstoneA08");
    AddItemTag(ItemTagKey(131), "GemstoneA09");
    AddItemTag(ItemTagKey(132), "GemstoneA10");
    AddItemTag(ItemTagKey(133), "GemstoneB01");
    AddItemTag(ItemTagKey(134), "GemstoneB02");
    AddItemTag(ItemTagKey(135), "GemstoneB03");
    AddItemTag(ItemTagKey(136), "GemstoneB04");
    AddItemTag(ItemTagKey(137), "GemstoneB05");
    AddItemTag(ItemTagKey(138), "GemstoneB06");
    AddItemTag(ItemTagKey(139), "GemstoneB07");
    AddItemTag(ItemTagKey(140), "GemstoneB08");
    AddItemTag(ItemTagKey(141), "GemstoneB09");
    AddItemTag(ItemTagKey(142), "GemstoneB10");
    AddItemTag(ItemTagKey(143), "GemstoneC01");
    AddItemTag(ItemTagKey(144), "GemstoneC02");
    AddItemTag(ItemTagKey(145), "GemstoneC03");
    AddItemTag(ItemTagKey(146), "GemstoneC04");
    AddItemTag(ItemTagKey(147), "GemstoneC05");
    AddItemTag(ItemTagKey(148), "GemstoneC06");
    AddItemTag(ItemTagKey(149), "GemstoneC07");
    AddItemTag(ItemTagKey(150), "GemstoneC08");
    AddItemTag(ItemTagKey(151), "GemstoneC09");
    AddItemTag(ItemTagKey(152), "GemstoneC10");
    AddItemTag(ItemTagKey(153), "GemstoneD01");
    AddItemTag(ItemTagKey(154), "GemstoneD02");
    AddItemTag(ItemTagKey(155), "GemstoneD03");
    AddItemTag(ItemTagKey(156), "GemstoneD04");
    AddItemTag(ItemTagKey(157), "GemstoneD05");
    AddItemTag(ItemTagKey(158), "GemstoneD06");
    AddItemTag(ItemTagKey(159), "GemstoneD07");
    AddItemTag(ItemTagKey(160), "GemstoneD08");
    AddItemTag(ItemTagKey(161), "GemstoneD09");
    AddItemTag(ItemTagKey(162), "GemstoneD10");
    AddItemTag(ItemTagKey(163), "GemstoneE01");
    AddItemTag(ItemTagKey(164), "GemstoneE02");
    AddItemTag(ItemTagKey(165), "GemstoneE03");
    AddItemTag(ItemTagKey(166), "GemstoneE04");
    AddItemTag(ItemTagKey(167), "GemstoneE05");
    AddItemTag(ItemTagKey(168), "GemstoneE06");
    AddItemTag(ItemTagKey(169), "GemstoneE07");
    AddItemTag(ItemTagKey(170), "GemstoneE08");
    AddItemTag(ItemTagKey(171), "GemstoneE09");
    AddItemTag(ItemTagKey(172), "GemstoneE10");
    AddItemTag(ItemTagKey(173), "GemstoneF01");
    AddItemTag(ItemTagKey(174), "GemstoneF02");
    AddItemTag(ItemTagKey(175), "GemstoneF03");
    AddItemTag(ItemTagKey(176), "GemstoneF04");
    AddItemTag(ItemTagKey(177), "GemstoneF05");
    AddItemTag(ItemTagKey(178), "GemstoneF06");
    AddItemTag(ItemTagKey(179), "GemstoneF07");
    AddItemTag(ItemTagKey(180), "GemstoneF08");
    AddItemTag(ItemTagKey(181), "GemstoneF09");
    AddItemTag(ItemTagKey(182), "GemstoneF10");
    AddItemTag(ItemTagKey(183), "GemstoneG01");
    AddItemTag(ItemTagKey(184), "GemstoneG02");
    AddItemTag(ItemTagKey(185), "GemstoneG03");
    AddItemTag(ItemTagKey(186), "GemstoneG04");
    AddItemTag(ItemTagKey(187), "GemstoneG05");
    AddItemTag(ItemTagKey(188), "GemstoneG06");
    AddItemTag(ItemTagKey(189), "GemstoneG07");
    AddItemTag(ItemTagKey(190), "GemstoneG08");
    AddItemTag(ItemTagKey(191), "GemstoneG09");
    AddItemTag(ItemTagKey(192), "GemstoneG10");
    AddItemTag(ItemTagKey(193), "GemstoneH01");
    AddItemTag(ItemTagKey(194), "GemstoneH02");
    AddItemTag(ItemTagKey(195), "GemstoneH03");
    AddItemTag(ItemTagKey(196), "GemstoneH04");
    AddItemTag(ItemTagKey(197), "GemstoneH05");
    AddItemTag(ItemTagKey(198), "GemstoneH06");
    AddItemTag(ItemTagKey(199), "GemstoneH07");
    AddItemTag(ItemTagKey(200), "GemstoneH08");
    AddItemTag(ItemTagKey(201), "GemstoneH09");
    AddItemTag(ItemTagKey(202), "GemstoneH10");
    AddItemTag(ItemTagKey(203), "EnchantJockerItemNormal");
    AddItemTag(ItemTagKey(204), "EnchantJockerItemRare");
    AddItemTag(ItemTagKey(205), "EnchantJockerItemElite");
    AddItemTag(ItemTagKey(206), "EnchantJockerItemExcellent");
    AddItemTag(ItemTagKey(207), "EnchantJockerItemLegendary");
    AddItemTag(ItemTagKey(208), "EnchantJockerItemEpic");
    AddItemTag(ItemTagKey(209), "FameCompletionTicket");
    AddItemTag(ItemTagKey(210), "PrismShard");
    AddItemTag(ItemTagKey(211), "PrismStone");
    AddItemTag(ItemTagKey(212), "WeddingHallCoupon_Grade1");
    AddItemTag(ItemTagKey(213), "WeddingHallCoupon_Grade2");
    AddItemTag(ItemTagKey(214), "WeddingHallCoupon_Grade3");
    AddItemTag(ItemTagKey(215), "GuildStorageItemOnlyToMe");
    AddItemTag(ItemTagKey(216), "PetEXP");
    AddItemTag(ItemTagKey(217), "UGCMapOX");
    AddItemTag(ItemTagKey(218), "Enix");
    AddItemTag(ItemTagKey(219), "Eragonix");
}

// @0x14055f090
void CItemDataTable::AddItemTag(ItemTagKey eTag, CString strName)
{
    MS2Ptr<ItemTagParam> spTag(new ItemTagParam());
    spTag->m_eTag = eTag;
    spTag->m_strName = strName;
    spTag->m_nItemId = 0;
    m_mapTag.SetAt(eTag, spTag);
}

// @0x14055f190
void CItemDataTable::LoadTagItemIds(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("tag"); pNode != 0; pNode = pNode->FUN_140168650("tag"))
    {
        CString strName;
        unsigned nItemId = 0;
        FUN_1408733e0(pNode, "name", strName);
        FUN_140873220(pNode, "itemID", nItemId);
        ItemTagKey eTag = GetTagByName(strName);
        if (eTag == 0)
            continue;
        MS2Ptr<ItemTagParam> spTag(0);
        if (m_mapTag.Lookup(eTag, spTag))
            spTag->m_nItemId = nItemId;
    }
}

// @0x14055f2c0
void CItemDataTable::OnItemLoaded(ItemDataPtr spItem)
{
    spItem->FUN_14053ecf0();
}

// MS2-FUNCTIONAL: iterator temporaries and SEH state layout differ; behaviour equivalent
// @0x14055f300
CItemDataTable::ItemDataPtr CItemDataTable::FindItemData(int nItemId)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    std::unordered_map<int, ItemDataPtr>::iterator it = m_mapItem.find(nItemId);
    if (it != m_mapItem.end())
    {
        if (it->second->FUN_14053ef80())
            it->second->FUN_14053eb20();
        return it->second;
    }
    return ItemDataPtr(0);
}

// @0x14055f440
MS2Ptr<CItemDataTable::ItemTagParam> CItemDataTable::FindTag(ItemTagKey eTag)
{
    MS2Ptr<ItemTagParam> spTag(0);
    m_mapTag.Lookup(eTag, spTag);
    return spTag;
}

// @0x14055f4d0
CItemDataTable::ModelPtr CItemDataTable::FindModel(unsigned nPreset)
{
    Unk_CriticalSectionLock lock(m_csModel, 1);
    std::map<unsigned, ModelPtr>::iterator it = m_mapModel.find(nPreset);
    if (it != m_mapModel.end())
    {
        ModelPtr spModel = it->second;
        if (spModel.get() != 0)
        {
            if (!FUN_1401d1320(spModel.operator->()))
                return spModel;
            unsigned nFile = ItemModelData::FUN_14054aec0(nPreset);
            m_setModelFile.erase(nFile);
        }
    }
    return ModelPtr(0);
}

// @0x14055f640
bool CItemDataTable::LoadModel(unsigned nPreset)
{
    unsigned nFile = nPreset / 100000;
    unsigned nSub = nFile % 100;
    unsigned nDir = nFile / 100;
    CString strDir = Unk_SocketFormat("{0}/{1:02d}/", nDir, nSub);
    CString strPath = FUN_14071a840(strDir, Unk_SocketFormat("{0:08d}", nPreset));
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    ModelPtr spModel(new ItemModelData);
    spModel->FUN_14054aee0(nPreset);
    spModel->FUN_1401d1160(strPath);
    spModel->FUN_14054af00(pRoot);
    {
        Unk_CriticalSectionLock lock(m_csModel, 1);
        m_mapModel[nPreset] = spModel;
    }
    return true;
}

// @0x14055f970
bool CItemDataTable::LoadModelFile(unsigned nFile)
{
    Unk_CriticalSectionLock lock(m_csModel, 1);
    if (m_setModelFile.find(nFile) != m_setModelFile.end())
        return true;
    CString strPath = FUN_14071a940(nFile);
    TiXmlDocument doc;
    if (LoadXml(doc, strPath) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("ItemModel"); pNode != 0; pNode = pNode->FUN_140168650("ItemModel"))
    {
        ModelPtr spModel(new ItemModelData);
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        spModel->FUN_14054aee0(nId);
        spModel->FUN_1401d1160(strPath);
        spModel->FUN_14054af00(pNode);
        m_mapModel[nId] = spModel;
    }
    m_setModelFile.insert(nFile);
    return true;
}

// @0x14055fce0
int CItemDataTable::GetEnchantKey(int nWeapon, int nLevel)
{
    return nWeapon * 100000 + nLevel;
}

// @0x14055fd10
static void FindFiles(CString strExt, CString strDir, std::vector<CString>& out)
{
    FUN_1403992a0(strExt, strDir, out, "", false);
}

// @0x14055fe00
static int LoadXml(TiXmlDocument& doc, const char* pszPath)
{
    return FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9ae90-0x142c9af10 .text$yd
