// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Chat / name text filter (CBanTextChecker) and CommonString.
// MS2-UNIT: commonfiles\commonstringtable.cpp
// MS2-RANGE: 0x1400b54f0-0x1400b5621 .text$di
// MS2-RANGE: 0x140223c60-0x140266860 .text$mn
// MS2-RANGE: 0x142c9a3b0-0x142c9a3f0 .text$yd
// MS2-RANGE: 0x142c9a400-0x142c9a420 .text$yd
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x14025d8e0
// MS2-PIN: ??1?$map@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@@std@@QEAA@XZ 0x14025c810
// MS2-PIN: ?__empty_global_delete@@YAXPEAX@Z 0x1402272b0
// MS2-PIN: ?__empty_global_delete@@YAXPEAX_K@Z 0x140266770
// MS2-PIN: ?_Adopt@_Iterator_base0@std@@QEAAXPEBX@Z 0x140266670
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@1@@Z 0x14025be00
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@1@@Z 0x14025be40
// MS2-PIN: memmove_s 0x140266500
// MS2-PIN: ??1CPair@?$CRBTree@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V32@@ATL@@IEAA@XZ 0x14025c970
// MS2-PIN: ??1CNode@?$CRBTree@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V32@@ATL@@QEAA@XZ 0x14025c8d0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_7CBanTextChecker@@6B?$CValidData@VCBanTextChecker@@@@@ 0x142d129b8
// MS2-PIN: ??_7CommonString@@6B?$TSingleton@VCommonString@@@@@ 0x142d129f8
// MS2-PIN: ??_7CommonString@@6B?$CValidData@VCommonString@@@@@ 0x142d12a08
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14025a4b0 ; unique
// MS2-PIN: ??$_Buynode@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@1@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x14025a820 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@@?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@1@PEAU01@@Z 0x14025a940 ; unique
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@1@AEBI@Z 0x14025b150 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@0@AEAPEAU10@@Z 0x14025b290 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@0@AEAPEAU10@@Z 0x14025b2a0 ; prop
// MS2-PIN: ??$addressof@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@YAPEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAV12@@Z 0x14025b2c0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@0@AEAV10@@Z 0x14025b2d0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@1@AEAPEAU31@@Z 0x14025b310 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@1@QEAPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@1@AEAPEAU31@@Z 0x14025b360 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@1@@Z 0x14025b400 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@1@QEAPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@1@@Z 0x14025b410 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@0@AEAPEAU10@@Z 0x14025b450 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@QEAA@XZ 0x14025be80 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@QEAA@XZ 0x14025beb0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@QEAA@XZ 0x14025bee0 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@QEAA@XZ 0x14025bef0 ; prop
// MS2-PIN: ??0?$map@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@@std@@QEAA@XZ 0x14025bf00 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14025cce0 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14025cdb0 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBIH@1@XZ 0x14025cf40 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14025cfc0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14025d010 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@QEAAAEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@1@_K@Z 0x14025e580 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultElementTraits@H@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x14025ea30 ; unique
// MS2-PIN: ?Hash@?$CDefaultHashTraits@H@ATL@@SAKAEBH@Z 0x14025ece0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@XZ 0x140263f30 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@2@XZ 0x140263ff0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@2@XZ 0x1402640b0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@2@@Z 0x140264320 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@@Z 0x1402643c0 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@2@@Z 0x140264f50 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@2@@Z 0x140264f80 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x140265070 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x140265080 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@2@XZ 0x140265190 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x1402651f0 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@IEBAAEBIPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@@Z 0x140265270 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x140265a40 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@_K@Z 0x140265af0 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@2@_K@Z 0x140265b20 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@XZ 0x140265b50 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x140265c30 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@_K@Z 0x140265d70 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@2@QEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@2@_K@Z 0x140265da0 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@XZ 0x140265e30 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@0@Z 0x140265ef0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@@Z 0x140265fe0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@V32@@Z 0x140266180 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@AEBI@Z 0x140266230 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@AEBI@Z 0x1402663f0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@XZ 0x140265320
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@XZ 0x140265800
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@XZ 0x140265840
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@1@@Z 0x14025bdc0
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@IEBAAEBIAEBU?$pair@$$CBIH@2@@Z 0x1402652d0
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@@Z 0x140265340
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@@Z 0x140265880
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstringtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "commonstringtable.h"
#include "ms2/placeholder/unkvec47.h"
#include "portaldata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include <typeinfo>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The exe binds a temporary to a non-const reference (MSVC extension); clang-cl needs the cast.
#define AS_LVALUE(T, expr) const_cast<T&>(static_cast<const T&>(expr))

// The exe keeps these map<unsigned, int> tree accessors out of line.
template std::_Tree_node<std::pair<const unsigned, int>, void*>*& std::_Tree_val<std::_Tree_simple_types<std::pair<const unsigned, int>>>::_Lmost() const;
template std::_Tree_node<std::pair<const unsigned, int>, void*>*& std::_Tree_val<std::_Tree_simple_types<std::pair<const unsigned, int>>>::_Rmost() const;
template std::_Tree_node<std::pair<const unsigned, int>, void*>*& std::_Tree_val<std::_Tree_simple_types<std::pair<const unsigned, int>>>::_Root() const;

CStringW GetStringCommon(EBanStringId nStringId);
bool FUN_14028f710(Unk_140165cf0* pNode);   // node is enabled for this client
CString FUN_140cc2a00(const CString& strRoot, const CString& strFile);   // path join

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14071ae20(const CString& strFile);                          // path of a Table file
CStringW FUN_1401bf530(Unk_140165cf0*, const char*, CStringW strDefault);   // string attribute with default (callee destroys the default)
unsigned FUN_14025ed00(const wchar_t* psz);                             // string hash
struct Unk_BanFlags { int FUN_1402c4c90(int nFlag); };                          // blocked-action flag set
struct Unk_BanConfig { unsigned char m_pad_0[8]; Unk_BanFlags m_8; };
Unk_BanConfig* FUN_14025e7b0();                                                 // global client config
void* FUN_140166410();
bool FUN_14036e560(void* pService);
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);   // formats one text argument into the message
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);          // formats one number argument into the message
bool FUN_14025fab0(CStringW& str);                                          // MakeLower
extern int DAT_143ab2914;                                                   // client build / region level (below 50: checks active)
extern int DAT_143ab0248;                                                   // client country (0..3)
void FUN_140165320(Unk_BanWordList* pList, const CStringW& str);               // append a string to an array
void FUN_14025a680(CStringW& src, ATL::CAtlArray<CStringW>& out, const wchar_t* pszSep);   // split into the pieces between separators

// The game constants table (FUN_1401d3200()): only the 0x58-byte slots read here.
class Unk_ConstVal { char m_pad_00[0x58]; };
struct Unk_BanConstTable
{
    char m_pad_0000[0x9cb0];
    Unk_ConstVal m_nameMin;                                 // +0x9cb0
    Unk_ConstVal m_nameMax;                                 // +0x9d08
    Unk_ConstVal m_guildNameMin;                            // +0x9d60
    Unk_ConstVal m_guildNameMax;                            // +0x9db8
    char m_pad_9e10[0x9ec0 - 0x9e10];
    Unk_ConstVal m_cNameMin;                                // +0x9ec0
    Unk_ConstVal m_cNameMax;                                // +0x9f18
    Unk_ConstVal m_wideTextMax;                             // +0x9f70
    char m_pad_9fc8[0xa0c0 - 0x9fc8];
    Unk_ConstVal m_dNameMin;                                // +0xa0c0
    Unk_ConstVal m_dNameMax;                                // +0xa118
    Unk_ConstVal m_eNameMin;                                // +0xa170
    Unk_ConstVal m_eNameMax;                                // +0xa1c8
};
MS2_CHECK_OFFSET(Unk_BanConstTable, m_nameMin, 0x9cb0);
MS2_CHECK_OFFSET(Unk_BanConstTable, m_cNameMin, 0x9ec0);
MS2_CHECK_OFFSET(Unk_BanConstTable, m_wideTextMax, 0x9f70);
MS2_CHECK_OFFSET(Unk_BanConstTable, m_dNameMin, 0xa0c0);
MS2_CHECK_OFFSET(Unk_BanConstTable, m_eNameMax, 0xa1c8);
Unk_BanConstTable* FUN_1401d3200();
int* FUN_1402056b0(Unk_ConstVal* slot);
// @0x14025a620
int FUN_14025a620(Unk_ConstVal* slot) { return *FUN_1402056b0(slot); }

// @0x140223c60
TextFilterUnit::TextFilterUnit() : m_children(17, 0.75f, 0.25f, 2.25f, 10), m_ch(0), m_nDepth(0), m_bWordEnd(0)
{
}

// @0x140223d10
TextFilterUnit::TextFilterUnit(wchar_t ch, int nDepth) : m_children(17, 0.75f, 0.25f, 2.25f, 10), m_ch(ch), m_nDepth(nDepth), m_bWordEnd(0)
{
}

// @0x140223dc0
wchar_t TextFilterUnit::GetChar() const
{
    return m_ch;
}

// @0x140223de0
void TextFilterUnit::Insert(const CStringW& str, int nIndex, CStringW replacement)
{
    if (str.GetLength() == nIndex)
    {
        m_bWordEnd = 1;
        m_replacement = replacement;
        return;
    }
    MS2Ptr<TextFilterUnit> child;
    if (!m_children.Lookup(str[nIndex], child))
    {
        child.AssignRaw(new TextFilterUnit(str[nIndex], m_nDepth + 1));
        m_children.SetAt(str[nIndex], child);
    }
    child->Insert(str, ++nIndex, replacement);
}

// @0x140223fe0
bool TextFilterUnit::Find(const CStringW& str, int nStart, bool bSkipTags, int* pnPos, int* pnLen, CStringW* pReplacement)
{
    if (m_children.IsEmpty())
        return false;
    int nLen = str.GetLength();
    for (int i = nStart; i < nLen; ++i)
    {
        if (bSkipTags && IsTagStart(str[i]) && i < nLen)
        {
            SkipTag(str, &i);
            continue;
        }
        MS2Ptr<TextFilterUnit> child;
        if (m_children.Lookup(towlower(str[i]), child))
        {
            if (child->Match(str, i, pnLen, pReplacement))
            {
                if (pnPos)
                    *pnPos = i;
                return true;
            }
        }
    }
    return false;
}

// @0x140224170
void TextFilterUnit::Clear()
{
    m_children.RemoveAll();
}

// @0x1402241a0
int TextFilterUnit::GetChildCount() const
{
    return (int)m_children.GetCount();
}

// @0x1402241d0
bool TextFilterUnit::Match(const CStringW& str, int nIndex, int* pnLen, CStringW* pReplacement)
{
    if (towlower(str[nIndex]) != m_ch)
        return false;
    if (!m_children.IsEmpty())
    {
        ++nIndex;
        MS2Ptr<TextFilterUnit> child;
        if (m_children.Lookup(towlower(str[nIndex]), child))
        {
            if (child->Match(str, nIndex, pnLen, pReplacement))
                return true;
        }
    }
    if (m_bWordEnd != 0)
    {
        if (pReplacement)
            *pReplacement = m_replacement;
        if (pnLen)
            *pnLen = m_nDepth;
        return true;
    }
    return false;
}

// @0x140224340
bool TextFilterUnit::IsTagStart(wchar_t ch)
{
    return ch == L'<';
}

// @0x140224380
void TextFilterUnit::SkipTag(const CStringW& str, int* pnIndex)
{
    if (str[*pnIndex + 1] == L'A')
    {
        int nEnd = str.Find(L"</A>", *pnIndex);
        if (0 < nEnd)
            *pnIndex = nEnd - 1 + lstrlenW(L"</A>");
    }
    else
    {
        int nEnd = str.Find(L'>', *pnIndex);
        if (0 < nEnd)
            *pnIndex = nEnd;
    }
}

// @0x140224430
CBanTextChecker::CheckerErrStringPackage::CheckerErrStringPackage() : m_ids(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1402244a0
CBanTextChecker::CheckerErrStringPackage::~CheckerErrStringPackage()
{
    m_ids.RemoveAll();
}

// @0x140224500
bool CBanTextChecker::CheckerErrStringPackage::IsEmpty() const
{
    return m_ids.IsEmpty();
}

// @0x140224530
void CBanTextChecker::CheckerErrStringPackage::Add(EBanErrKind nKind, EBanStringId nStringId)
{
    m_ids.SetAt(nKind, nStringId);
}

// @0x140224570
CStringW CBanTextChecker::CheckerErrStringPackage::GetErrString(EBanErrKind nKind)
{
    EBanStringId nId = (EBanStringId)0;
    if (m_ids.Lookup(nKind, nId))
        return GetStringCommon(nId);
    return GetDefaultErrString(nKind);
}

static ATL::CAtlMap<EBanErrKind, EBanStringId> s_mapDefaultErr;   // 0x143aacca0
static CStringA s_strSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};  // 0x143aacc50
static QuestMask s_questMask;                                       // 0x143aacd50

// @0x140224600
// The default error kind -> string id table, filled on first use.
static void FUN_140224600()
{
    if (!s_mapDefaultErr.IsEmpty())
        return;
    s_mapDefaultErr.SetAt((EBanErrKind)1, (EBanStringId)0x8b8);
    s_mapDefaultErr.SetAt((EBanErrKind)2, (EBanStringId)0x8b7);
    s_mapDefaultErr.SetAt((EBanErrKind)3, (EBanStringId)0x8b9);
    s_mapDefaultErr.SetAt((EBanErrKind)4, (EBanStringId)0x8ba);
    s_mapDefaultErr.SetAt((EBanErrKind)5, (EBanStringId)0x8b3);
    s_mapDefaultErr.SetAt((EBanErrKind)6, (EBanStringId)0x8b4);
    s_mapDefaultErr.SetAt((EBanErrKind)7, (EBanStringId)0x8b5);
    s_mapDefaultErr.SetAt((EBanErrKind)8, (EBanStringId)0x8b6);
}

// @0x140224760
CStringW CBanTextChecker::GetDefaultErrString(EBanErrKind nKind)
{
    EBanStringId nId = (EBanStringId)0;
    FUN_140224600();
    if (s_mapDefaultErr.Lookup(nKind, nId))
        return GetStringCommon(nId);
    return CStringW(L"");
}

// @0x1402247f0
CStringW CBanTextChecker::GetErrString(EBanErrKind nKind, MS2Ptr<CheckerErrStringPackage> pkg)
{
    if (pkg.IsNull())
        return GetDefaultErrString(nKind);
    return pkg->GetErrString(nKind);
}

// @0x14025c350
CBanTextChecker::CheckerOption::CheckerOption(unsigned nTypes, bool bFlag) : m_bFlag(bFlag), m_nTypes(nTypes), m_errs(0)
{
}

// @0x14025c2e0
CBanTextChecker::CheckerOption::CheckerOption(MS2Ptr<CheckerErrStringPackage> errs, unsigned nTypes, bool bFlag) : m_bFlag(bFlag), m_nTypes(nTypes), m_errs(errs)
{
}

// @0x14025c9d0
CBanTextChecker::CheckerOption::~CheckerOption()
{
    m_errs = 0;
}

// @0x14025c3a0
CBanTextChecker::CheckerLimit::CheckerLimit(int nMin, int nMax, bool bAllowSpace, bool bSkipTrimCheck, bool bNoCharCheck, bool bWideCountsTwice, bool bAllowPunct)
    : m_nMin(nMin), m_nMax(nMax), m_bAllowSpace(bAllowSpace), m_bSkipTrimCheck(bSkipTrimCheck), m_bNoCharCheck(bNoCharCheck),
      m_bWideCountsTwice(bWideCountsTwice), m_bAllowPunct(bAllowPunct), m_errs(0)
{
}

// @0x14025ca10
CBanTextChecker::CheckerLimit::~CheckerLimit()
{
    m_errs = 0;
}

// @0x140229220
void CBanTextChecker::FUN_140229220()
{
}

// @0x140224890
CBanTextChecker::CBanTextChecker() : m_mapUrlHash(10), m_mapBanWords(10)
{
    FUN_140229220();
}

// @0x1402249e0
CBanTextChecker::~CBanTextChecker()
{
    ClearTries();
}

// @0x140227890
void CBanTextChecker::ClearTries()
{
    m_trieBanUrl.Clear();
    m_trieBanWord.Clear();
    m_trieReserveWord.Clear();
    m_trieReserveIdAny.Clear();
    m_setReserveIdAll.clear();
    m_mapUrlHash.RemoveAll();
    m_mapBanWords.RemoveAll();
}

// @0x140224f80
int CBanTextChecker::HasStartWithWords(unsigned nTypes)
{
    if (nTypes & 0x40) return (unsigned)m_trieStartWith.GetChildCount() > 0;
    return 0;
}

// @0x140224fe0
bool CBanTextChecker::IsAlnumName(const CStringW& str, void*)
{
    CStringW s(str);
    if (s.GetLength() > 0x20) return false;
    int nLen = s.GetLength();
    if (nLen < 1 || 0x20 < nLen) return false;
    for (int i = 0; i < nLen; ++i) {
        wchar_t ch = s.GetAt(i);
        if (ch >= L'0' && ch <= L'9') continue;
        if ((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z')) continue;
        return false;
    }
    return true;
}

// @0x140259fe0
CStringW CBanTextChecker::GetLimitErrString(CheckerLimit& limit, unsigned nKind)
{
    EBanErrKind eKind = static_cast<EBanErrKind>(0);
    switch (nKind) {
    case 1: {
        eKind = static_cast<EBanErrKind>(5);
        CStringW format = CBanTextChecker::GetErrString(eKind, limit.m_errs);
        int nCount = limit.m_nMin < 1 ? 1 : limit.m_nMin;
        return FUN_1401ceea0(format, nCount);
    }
    case 2: {
        eKind = static_cast<EBanErrKind>(6);
        CStringW format = CBanTextChecker::GetErrString(eKind, limit.m_errs);
        int nCount = limit.m_nMax > 1 ? limit.m_nMax : 1;
        return FUN_1401ceea0(format, nCount);
    }
    case 3: {
        eKind = static_cast<EBanErrKind>(limit.m_bAllowSpace ? 7 : 8);
        CStringW format = CBanTextChecker::GetErrString(eKind, limit.m_errs);
        return format;
    }
    }
    return CStringW(L"");
}

// @0x14025a290
CStringW CBanTextChecker::GetOptionErrString(CheckerOption& opt, EBanErrKind nKind, const CStringW& strMatched, unsigned char bFlag)
{
    EBanErrKind eKind = static_cast<EBanErrKind>(0);
    switch (nKind) {
    case 5:
    case 9: {
        eKind = static_cast<EBanErrKind>(bFlag ? 1 : 2);
        CStringW format = CBanTextChecker::GetErrString(eKind, opt.m_errs);
        return FUN_1401e8510(format, strMatched);
    }
    case 6:
    case 7:
    case 8: {
        eKind = static_cast<EBanErrKind>(opt.m_bFlag ? 3 : 4);
        CStringW format = CBanTextChecker::GetErrString(eKind, opt.m_errs);
        return FUN_1401e8510(format, strMatched);
    }
    }
    return CStringW(L"");
}

// @0x140228b40
bool CBanTextChecker::FindReserveIdAny(const CStringW& str, CStringW& matched)
{
    CheckInit();
    int nPos = 0;
    int nLen = 0;
    CStringW s(str);
    if (m_trieReserveIdAny.Find(s, 0, true, &nPos, &nLen, NULL)) {
        matched = s.Mid(nPos, nLen);
        return true;
    }
    return false;
}

// @0x140228c50
bool CBanTextChecker::FindBanWord(const CStringW& str, CStringW& matched)
{
    CheckInit();
    int nPos = 0;
    int nLen = 0;
    CStringW s(str);
    if (m_trieBanWord.Find(s, 0, true, &nPos, &nLen, NULL)) {
        matched = s.Mid(nPos, nLen);
        return true;
    }
    return false;
}

// @0x140228d60
bool CBanTextChecker::FindUgcBanWord(const CStringW& str, CStringW& matched)
{
    CheckInit();
    int nPos = 0;
    int nLen = 0;
    CStringW s(str);
    if (m_trieUgcBanWord.Find(s, 0, true, &nPos, &nLen, NULL)) {
        matched = s.Mid(nPos, nLen);
        return true;
    }
    return false;
}

// @0x140228e70
bool CBanTextChecker::FindReserveWord(const CStringW& str, CStringW& matched)
{
    CheckInit();
    int nPos = 0;
    int nLen = 0;
    CStringW s(str);
    if (m_trieReserveWord.Find(s, 0, true, &nPos, &nLen, NULL)) {
        matched = s.Mid(nPos, nLen);
        return true;
    }
    return false;
}

// @0x140228a60
bool CBanTextChecker::FindReserveIdAll(const CStringW& str, CStringW& matched)
{
    CheckInit();
    CStringW s(str);
    FUN_14025fab0(s);
    std::set<CStringW>::iterator it = m_setReserveIdAll.find(s);
    if (it != m_setReserveIdAll.end()) {
        matched = *it;
        return true;
    }
    return false;
}

// @0x140228f80
bool CBanTextChecker::FindStartWithWord(const CStringW& str, CStringW& matched)
{
    CheckInit();
    int nStart = 0;
    int nPos = 0;
    int nLen = 0;
    while (m_trieStartWith.Find(str, nStart, true, &nPos, &nLen, NULL)) {
        if (nPos == nStart) {
            matched = str.Mid(nPos, nLen);
            return true;
        } else {
            nStart = str.Find(L' ', nPos);
            if (nStart < 0) break;
            nStart = nStart + 1;
        }
    }
    return false;
}

// @0x1402290b0
bool CBanTextChecker::FindBanWordAll(const CStringW& str, CStringW& matched)
{
    CheckInit();
    int nTotal = str.GetLength();
    int nStart = 0;
    int nPos = 0;
    int nLen = 0;
    while (m_trieBanWordAll.Find(str, nStart, true, &nPos, &nLen, NULL)) {
        int nSpace = str.Find(L' ', nPos);
        bool bWhole = true;
        if (nStart == nPos) {
            if (nSpace == -1 && nPos + nLen != nTotal) bWhole = false;
            else if (nSpace != -1 && nPos + nLen != nSpace) bWhole = false;
        } else {
            int nPrevSpace = str.Find(L' ', nStart);
            if (nSpace - nPrevSpace - 1 != nLen) bWhole = false;
        }
        if (bWhole) return true;
        nStart = str.Find(L' ', nPos);
        if (nStart < 0) break;
        nStart = nStart + 1;
    }
    return false;
}

// @0x140227930
int CBanTextChecker::CheckTextOption(const CStringW& str, CheckerOption& opt, CStringW& message)
{
    if (DAT_143ab2914 >= 0x32) return 0;
    {
        unsigned nTypes = opt.m_nTypes;
        unsigned char bFlag = nTypes & 1;
        if ((nTypes & 2) != 0) {
            CStringW matched;
            if (FindReserveIdAll(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(5);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 4) != 0) {
            CStringW matched;
            if (FindReserveIdAny(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(6);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 8) != 0) {
            CStringW matched;
            if (FindReserveWord(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(7);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 0x10) != 0) {
            CStringW matched;
            if (FindBanWord(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(8);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 0x20) != 0) {
            CStringW matched;
            if (FindUgcBanWord(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(8);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 0x40) != 0) {
            CStringW matched;
            if (FindStartWithWord(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(8);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 0x80) != 0) {
            CStringW matched;
            if (FindBanWordAll(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(9);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
    }
    return 0;
}

// @0x140228110
unsigned CBanTextChecker::ScanLimit(const CStringW& str, CheckerLimit& limit)
{
    CStringW s(str);
    // Per client country: 1 hangul counts double, 2 characters are looked up in the char class table, 4 (unused here),
    // 8 CJK ideographs count double, 0x10 umlauts are fine, 0x20 Portuguese letters are fine.
    int nFlags = 0;
    switch (DAT_143ab0248) {
    case 0: nFlags = 5; break;
    case 1: nFlags = 6; break;
    case 2: nFlags = 0x34; break;
    case 3: nFlags = 0xc; break;
    default:
        MS2_ASSERT_AT(0x57d, FALSE);
        nFlags = 5;
        break;
    }
    if (!limit.m_bSkipTrimCheck) {
        CStringW trimmed(s);
        trimmed.Trim();
        if (trimmed.GetLength() < (limit.m_nMin > 1 ? limit.m_nMin : 1)) return 1;
        if (trimmed.GetLength() != s.GetLength()) return 3;
    }
    int nExtra = 0;
    int nLen = s.GetLength();
    if (nLen < (limit.m_nMin > 1 ? limit.m_nMin : 1)) return 1;
    bool bBad = false;
    if (!limit.m_bNoCharCheck) {
        for (int i = 0; i < nLen; ++i) {
            wchar_t chPrev = i > 0 ? s.GetAt(i - 1) : 0;
            wchar_t ch = s.GetAt(i);
            if (limit.m_bAllowSpace && ch == L' ' && chPrev != L' ') continue;
            if (limit.m_bAllowPunct) {
                if (ch == L'\'') continue;
                if (ch == L'-') continue;
                if (ch == L'_') continue;
                if (ch == L'.') continue;
            }
            if (ch >= 0x30 && ch <= 0x39) continue;
            if ((ch >= 0x61 && ch <= 0x7a) || (ch >= 0x41 && ch <= 0x5a)) continue;
            if ((nFlags & 1) && ch >= 0xac00 && ch < 0xd7a4) {
                if (limit.m_bWideCountsTwice) ++nExtra;
                continue;
            }
            if ((nFlags & 8) && ch >= 0x4e00 && ch < 0x9faf) {
                if (limit.m_bWideCountsTwice) ++nExtra;
                continue;
            }
            if (nFlags & 2) {
                unsigned nKey = ch;
                std::map<unsigned, int>::iterator it = m_mapCharClass.find(nKey);
                if (it != m_mapCharClass.end()) {
                    int nClass = it->second;
                    if (nClass != 0 && limit.m_bWideCountsTwice) ++nExtra;
                    continue;
                }
            }
            if (nFlags & 0x10) {
                if (ch == 0xc4) continue;
                if (ch == 0xe4) continue;
                if (ch == 0xd6) continue;
                if (ch == 0xf6) continue;
                if (ch == 0xdc) continue;
                if (ch == 0xfc) continue;
                if (ch == 0xdf) continue;
            }
            if (nFlags & 0x20) {
                switch (ch) {
                case 0xaa: case 0xba: case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc7: case 0xc9: case 0xca: case 0xcd: case 0xd3: case 0xd4: case 0xd5: case 0xda: case 0xdc: case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe7: case 0xe9: case 0xea: case 0xed: case 0xf3: case 0xf4: case 0xf5: case 0xfa: case 0xfc:
                    continue;
                }
            }
            bBad = true;
        }
    }
    if (nLen + nExtra > limit.m_nMax) return 2;
    if (bBad) return 3;
    return 0;
}

// @0x140225120
int CBanTextChecker::FUN_140225120(const CStringW& str, CStringW& message)
{
    int nMin = *FUN_1402056b0(&FUN_1401d3200()->m_nameMin);
    int nMax = *FUN_1402056b0(&FUN_1401d3200()->m_nameMax);
    CheckerOption opt(0x91, true);
    CheckerLimit limit(nMin, nMax, true, false, false, true, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225210
int CBanTextChecker::FUN_140225210(const CStringW& str, CStringW& message, int bShort)
{
    int nMax = bShort ? 0xc : 0x18;
    CheckerOption opt(0xdf, true);
    CheckerLimit limit(2, nMax, false, false, false, true, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x1402252f0
int CBanTextChecker::FUN_1402252f0(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(1, 0x10, true, false, false, true, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x1402253b0
int CBanTextChecker::FUN_1402253b0(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(0, 100, true, false, false, false, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225470
int CBanTextChecker::FUN_140225470(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(FUN_14025a620(&FUN_1401d3200()->m_dNameMin), FUN_14025a620(&FUN_1401d3200()->m_dNameMax), true, false, false, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225550
int CBanTextChecker::FUN_140225550(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(FUN_14025a620(&FUN_1401d3200()->m_eNameMin), FUN_14025a620(&FUN_1401d3200()->m_eNameMax), true, false, true, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225630
int CBanTextChecker::FUN_140225630(const CStringW& str, CStringW& message)
{
    int nMin = *FUN_1402056b0(&FUN_1401d3200()->m_cNameMin);
    int nMax = *FUN_1402056b0(&FUN_1401d3200()->m_cNameMax);
    CheckerOption opt(0xf9, true);
    CheckerLimit limit(nMin, nMax, true, false, false, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225720
int CBanTextChecker::FUN_140225720(const CStringW& str, CStringW& message)
{
    int nMin = *FUN_1402056b0(&FUN_1401d3200()->m_guildNameMin);
    int nMax = *FUN_1402056b0(&FUN_1401d3200()->m_guildNameMax);
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(nMin, nMax, true, false, false, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225810
int CBanTextChecker::FUN_140225810(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    int nMax = 7;
    if (FUN_14036e560(FUN_140166410())) nMax = 0xf;
    CheckerLimit limit(1, nMax, true, false, false, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x1402258f0
int CBanTextChecker::FUN_1402258f0(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd8, true);
    CheckerLimit limit(1, 1000, false, false, false, false, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x1402259b0
int CBanTextChecker::FUN_1402259b0(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd8, true);
    CheckerLimit limit(1, 300, false, false, false, false, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225a70
int CBanTextChecker::FUN_140225a70(const CStringW& str, CStringW& message)
{
    CheckerLimit limit(3, 0xe, true, false, false, false, false);
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(5), static_cast<EBanStringId>(0x8bd));
        pkg->Add(static_cast<EBanErrKind>(6), static_cast<EBanStringId>(0x8be));
        pkg->Add(static_cast<EBanErrKind>(7), static_cast<EBanStringId>(0x8bf));
        pkg->Add(static_cast<EBanErrKind>(8), static_cast<EBanStringId>(0x8c0));
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c1));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c2));
        limit.m_errs = pkg;
    }
    CheckerOption opt(pkg, 0xd1, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225c90
int CBanTextChecker::FUN_140225c90(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c1));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c2));
    }
    return CheckTextOption(str, AS_LVALUE(CheckerOption, CheckerOption(pkg, 0xd8, true)), message);
}

// @0x140225de0
int CBanTextChecker::FUN_140225de0(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c3));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c4));
    }
    return CheckTextOption(str, AS_LVALUE(CheckerOption, CheckerOption(pkg, 0xd8, true)), message);
}

// @0x140225f70
int CBanTextChecker::FUN_140225f70(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8bb));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8bc));
    }
    return CheckTextOption(str, AS_LVALUE(CheckerOption, CheckerOption(pkg, 0xd8, true)), message);
}

// @0x140226440
int CBanTextChecker::FUN_140226440(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c1));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c2));
    }
    return CheckTextOption(str, AS_LVALUE(CheckerOption, CheckerOption(pkg, 0xd8, true)), message);
}

// @0x140226590
int CBanTextChecker::FUN_140226590(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c3));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c4));
    }
    return CheckTextOption(str, AS_LVALUE(CheckerOption, CheckerOption(pkg, 0xd8, true)), message);
}

// @0x1402266e0
int CBanTextChecker::FUN_1402266e0(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c3));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c4));
    }
    return CheckTextOption(str, AS_LVALUE(CheckerOption, CheckerOption(pkg, 0xd8, true)), message);
}

// @0x140226830
int CBanTextChecker::FUN_140226830(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c3));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c4));
    }
    return CheckTextOption(str, AS_LVALUE(CheckerOption, CheckerOption(pkg, 0xd8, true)), message);
}

// @0x140225f30
int CBanTextChecker::FUN_140225f30(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd0, true, message);
}

// @0x1402260c0
int CBanTextChecker::FUN_1402260c0(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x1402261e0
int CBanTextChecker::FUN_1402261e0(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xf8, true, message);
}

// @0x140226220
int CBanTextChecker::FUN_140226220(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x140226260
int CBanTextChecker::FUN_140226260(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x1402262a0
int CBanTextChecker::FUN_1402262a0(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd0, true, message);
}

// @0x1402262e0
int CBanTextChecker::FUN_1402262e0(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x140226400
int CBanTextChecker::FUN_140226400(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x140226100
int CBanTextChecker::FUN_140226100(const CStringW& str, CStringW& message)
{
    int nMax = 200;
    if (str.GetLength() > nMax) return 2;
    return CheckTypes(str, 0xf8, true, message);
}

// @0x140226160
int CBanTextChecker::FUN_140226160(const CStringW& str, CStringW& message)
{
    int nMax = *FUN_1402056b0(&FUN_1401d3200()->m_wideTextMax) * 3 + 10;
    if (str.GetLength() > nMax) return 2;
    return CheckTypes(str, 0xf8, true, message);
}

// @0x140226320
int CBanTextChecker::FUN_140226320(const CStringW& str, CStringW& message)
{
    if (str.IsEmpty()) return 0;
    CheckerOption opt(0xdf, true);
    CheckerLimit limit(1, 200, true, false, false, false, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140227fb0
int CBanTextChecker::CheckTextWithLimit(const CStringW& str, CheckerOption& opt, CheckerLimit& limit, CStringW& message)
{
    unsigned nTypes = opt.m_nTypes;
    unsigned char bCheckLimit = nTypes & 1;
    unsigned nResult;
    if (bCheckLimit && (nResult = ScanLimit(str, limit)) != 0) {
        message = GetLimitErrString(limit, nResult);
        return nResult;
    }
    return CheckTextOption(str, opt, message);
}

// @0x140228080
int CBanTextChecker::CheckTypes(const CStringW& str, unsigned nTypes, bool bFlag, CStringW& message)
{
    return CheckTextOption(str, AS_LVALUE(CheckerOption, CheckerOption(nTypes, bFlag)), message);
}

// @0x14025a640
CStringW FUN_14025a640(const CStringW& str)
{
    return str;
}

// @0x14025a680
void FUN_14025a680(CStringW& src, ATL::CAtlArray<CStringW>& out, const wchar_t* pszSep)
{
    int iStart = 0;
    CStringW tok = src.Tokenize(pszSep, iStart);
    while (!tok.IsEmpty())
    {
        out.Add(FUN_14025a640(tok));
        tok = src.Tokenize(pszSep, iStart);
    }
}

// @0x1402272c0
int CBanTextChecker::LoadWords(CString strPath, TextFilterUnit* pTrie)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        return 0;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        CStringW strName = FUN_1401bf530(pNode, "name", CStringW(L""));
        if (strName.IsEmpty())
            continue;
        FUN_14025fab0(strName);
        ATL::CAtlArray<CStringW> parts;
        FUN_14025a680(strName, parts, L",");
        if (parts.GetCount() == 1)
        {
            pTrie->Insert(parts[0], 0, CStringW(L""));
        }
        else if (parts.GetCount() == 2)
        {
            pTrie->Insert(parts[0], 0, CStringW(parts[1]));
        }
        else if (parts.GetCount() > 2)
        {
            MS2_ASSERT_AT(0x28f, 0);
            return 0;
        }
    }
    return 1;
}

// @0x140227670
int CBanTextChecker::LoadIdSet(CString strPath, std::set<CStringW>* pSet)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        return 0;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        CStringW strName = FUN_1401bf530(pNode, "name", CStringW(L""));
        if (strName.IsEmpty())
            continue;
        FUN_14025fab0(strName);
        pSet->insert(strName);
    }
    return 1;
}

// @0x140224b20
int CBanTextChecker::LoadTables()
{
    ClearTries();
    LoadWords(FUN_14071a5b0("Table", "banUrl.xml"), &m_trieBanUrl);
    LoadWords(FUN_14071ae20("banWord.xml"), &m_trieBanWord);
    LoadWords(FUN_14071ae20("reserveWord.xml"), &m_trieReserveWord);
    LoadIdSet(FUN_14071ae20("reserveIDAll.xml"), &m_setReserveIdAll);
    LoadWords(FUN_14071ae20("reserveIDAny.xml"), &m_trieReserveIdAny);
    LoadWords(FUN_14071ae20("ugcBanWord.xml"), &m_trieUgcBanWord);
    LoadWords(FUN_14071ae20("startWithWord.xml"), &m_trieStartWith);
    LoadWords(FUN_14071ae20("banWordAll.xml"), &m_trieBanWordAll);
    BuildUrlHashes();
    SetInit(true);
    return 1;
}

// @0x1402271a0
void CBanTextChecker::SetBanWords(unsigned nKey, Unk_BanWordList& words)
{
    m_mapBanWords.RemoveKey(nKey);
    Unk_BanWordPtr list((Unk_SocketNew(0)));
    for (unsigned i = 0; i < words.GetCount(); ++i)
    {
        const CStringW& strWord = words[i];
        FUN_140165320(list.operator->(), strWord);
    }
    m_mapBanWords.SetAt(nKey, list);
}

// @0x140227280
void CBanTextChecker::RemoveBanWords(unsigned nKey)
{
    m_mapBanWords.RemoveKey(nKey);
}

// @0x140228740
void CBanTextChecker::BuildUrlHashes()
{
    ATL::CAtlList<CStringW, ATL::CElementTraitsBase<CStringW> > urls(10);
    {
        CStringW strUrl1(L"//qq.com");
        urls.AddTail(strUrl1);
    }
    {
        CStringW strUrl2(L"www.qq.com");
        urls.AddTail(strUrl2);
    }
    for (POSITION pos = urls.GetHeadPosition(); pos != 0; urls.GetNext(pos))
    {
        const CStringW& strUrl = urls.GetAt(pos);
        CStringW strHash;
        strHash.Format(L"%d", FUN_14025ed00(strUrl));
        m_mapUrlHash.SetAt(strUrl, strHash);
    }
}

// @0x140228880
bool CBanTextChecker::ReplaceUrlsWithHashes(CStringW& str)
{
    int nCount = 0;
    for (POSITION pos = m_mapUrlHash.GetHeadPosition(); pos != 0; m_mapUrlHash.GetNext(pos))
    {
        const CStringW& strUrl = m_mapUrlHash.GetKeyAt(pos);
        CStringW& strHash = m_mapUrlHash.GetValueAt(pos);
        nCount += str.Replace(strUrl, strHash);
    }
    if (0 < nCount)
        return true;
    return false;
}

// @0x140228970
bool CBanTextChecker::ReplaceHashesWithUrls(CStringW& str)
{
    int nCount = 0;
    for (POSITION pos = m_mapUrlHash.GetHeadPosition(); pos != 0; m_mapUrlHash.GetNext(pos))
    {
        const CStringW& strUrl = m_mapUrlHash.GetKeyAt(pos);
        CStringW& strHash = m_mapUrlHash.GetValueAt(pos);
        nCount += str.Replace(strHash, strUrl);
    }
    if (0 < nCount)
        return true;
    return false;
}

// @0x140226980
void CBanTextChecker::MaskBannedWords(CStringW& str)
{
    FilterBanWords(str);
    str.Replace(L'\r', L'*');
    str.Replace(L'\n', L'*');
    str.Replace(L"&", L"*");
    for (POSITION pos = m_mapBanWords.GetHeadPosition(); pos != 0; m_mapBanWords.GetNext(pos))
    {
        Unk_BanWordPtr words = m_mapBanWords.GetValueAt(pos);
        if (words == 0)
            continue;
        for (unsigned i = 0; i < words->GetCount(); ++i)
        {
            CStringW& strWord = (*words)[i];
            str.Replace(strWord, L"*");
        }
    }
}

// @0x140226b10
void CBanTextChecker::FilterReservedWords(CStringW& str)
{
    CheckInit();
    if (DAT_143ab2914 >= 0x32)
        return;
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(0x3a) == 0)
    {
        bool bHashed = ReplaceUrlsWithHashes(str);
        int nStart = 0;
        int nPos = 0;
        int nLen = 0;
        CStringW strReplace;
        while (m_trieBanUrl.Find(str, nStart, true, &nPos, &nLen, &strReplace))
        {
            if (strReplace.IsEmpty())
                strReplace = CStringW(L'*', nLen);
            str.Delete(nPos, nLen);
            str.Insert(nPos, strReplace);
            nStart = nPos + strReplace.GetLength();
        }
        if (bHashed)
            ReplaceHashesWithUrls(str);
    }
}

// @0x140226cd0
void CBanTextChecker::FilterBanWords(CStringW& str)
{
    CheckInit();
    if (DAT_143ab2914 >= 0x32)
        return;
    unsigned nMask = 0;
    nMask = 7;
    switch (DAT_143ab0248)
    {
    case 2:
        nMask ^= 2;
        break;
    }
    int nStart = 0;
    int nPos = 0;
    int nLen = 0;
    CStringW strReplace;
    while (m_trieBanWord.Find(str, nStart, true, &nPos, &nLen, &strReplace))
    {
        if (strReplace.IsEmpty())
            strReplace = CStringW(L'*', nLen);
        str.Delete(nPos, nLen);
        str.Insert(nPos, strReplace);
        nStart = nPos + strReplace.GetLength();
    }
    nStart = nPos = nLen = 0;
    while ((nMask & 2) != 0 && m_trieStartWith.Find(str, nStart, true, &nPos, &nLen, &strReplace))
    {
        if (strReplace.IsEmpty())
            strReplace = CStringW(L'*', nLen);
        str.Delete(nPos, nLen);
        str.Insert(nPos, strReplace);
        nStart = str.Find(L' ', nPos);
        if (nStart < 0)
            break;
        nStart = nStart + 1;
    }
    nStart = nPos = nLen = 0;
    while (m_trieBanWordAll.Find(str, nStart, true, &nPos, &nLen, &strReplace))
    {
        if (strReplace.IsEmpty())
            strReplace = CStringW(L'*', nLen);
        bool bWhole = true;
        int nTok = nStart;
        CStringW strTok;
        while (nTok <= nPos)
        {
            strTok = str.Tokenize(L" ", nTok);
        }
        if (strTok.GetLength() != nLen)
            bWhole = false;
        if (bWhole)
        {
            str.Delete(nPos, nLen);
            str.Insert(nPos, strReplace);
        }
        nStart = str.Find(L' ', nPos);
        if (nStart < 0)
            break;
        nStart = nStart + 1;
    }
}

CString FUN_14016a600(const wchar_t* pwsz, int n);                              // wide -> narrow
CString FUN_14016a5c0(const char* psz, int n);
CStringW FUN_14016a730(const char* psz, int n);                                 // narrow -> wide
extern CStringW DAT_143aacc90;                                                  // the shared empty string
class Unk_AltStringMgr { public: CStringW FUN_1422b0570(const CString& strKey); };
extern Unk_AltStringMgr* DAT_143aaccf8;
extern void* DAT_143aacd08;
extern void* DAT_143aacd00;
Unk_AltStringMgr* FUN_14025e7a0();
void* FUN_14025e7c0();                                                          // the client's text-hook object
CommonString* FUN_14025e7d0();                                                  // the CommonString singleton
unsigned char FUN_14116d950(void* pObj, int nFlag, bool a, int b);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton and init flags (symbols.tsv); local copies stay false -> "is not initialized" box
CommonString* TSingleton<CommonString>::s_instance = 0;
bool CBanTextChecker::s_bInit = false;
bool CommonString::s_bInit = false;
#endif

inline TSingleton<CommonString>::TSingleton() { s_instance = static_cast<CommonString*>(this); }

// @0x140229230
CommonString::CommonString() : m_spChecker(new CBanTextChecker)
{
    RegisterIds();
    Reload();
    m_bRaw = 0;
}

// @0x1402293a0
CommonString::~CommonString()
{
    TextMap* maps = m_maps;
    for (unsigned i = 0; i < 2; ++i)
    {
        TextMap* pMap = maps + (int)i;
        pMap->RemoveAll();
    }
    m_strings.RemoveAll();
    m_spChecker = 0;
}

// @0x1402294e0
CStringW CommonString::MapText(int nMap, const CStringW& strKey)
{
    CheckInit();
    if (nMap < 0 || nMap >= 2)
        return CStringW(L"");
    CStringW strText;
    m_maps[nMap].Lookup(strKey, strText);
    return strText;
}

// @0x1402295b0
CString CommonString::GetNarrowDefault(int nId)
{
    return GetNarrow(nId);
}

// @0x140229600
CString CommonString::GetNarrow(int nId)
{
    return FUN_14016a600(GetWide(nId), 0);
}

// @0x140229690
CString CommonString::GetNarrowByKey(const CString& strKey)
{
    return FUN_14016a600(GetWideByKey(FUN_14016a730(strKey, 0)), 0);
}

// @0x140229760
CStringW CommonString::GetWide(int nId)
{
    CStringW strText;
    if (!m_strings.Lookup(nId, strText))
        return DAT_143aacc90;
    return GetWideByKey(strText);
}

// @0x140229820
CStringW CommonString::GetWideByKey(const CStringW& strKey)
{
    if (strKey.GetLength() == 0)
        return DAT_143aacc90;
    if (FUN_14025e7c0() != 0)
    {
        if (FUN_14116d950(FUN_14025e7c0(), 0x2a, 1, 0))
        {
            if (FUN_14116d950(FUN_14025e7c0(), 0x1d, 1, 0))
                return strKey;
        }
    }
    if (m_bRaw != 0)
        return strKey;
    return MapText(0, strKey);
}

// @0x140229940
CStringW CommonString::FUN_140229940(const CString& strKey)
{
    return FUN_14025e7a0()->FUN_1422b0570(strKey);
}

// @0x140229990
CStringW CommonString::GetWideRaw(int nId)
{
    CStringW strText;
    if (!m_strings.Lookup(nId, strText))
        return DAT_143aacc90;
    return strText;
}

// @0x140229a50
MS2Ptr<CBanTextChecker> CommonString::GetChecker()
{
    if (this != 0)
    {
        return m_spChecker;
    }
    else
    {
        return MS2Ptr<CBanTextChecker>(0);
    }
}

// @0x14025ed00
unsigned FUN_14025ed00(const wchar_t* psz)
{
    ATLENSURE(psz != NULL);
    ULONG nHash = 0;
    const wchar_t* pch = psz;
    while (*pch != 0)
    {
        nHash = (nHash << 5) + nHash + (*pch);
        pch++;
    }
    return nHash;
}


struct Unk_Vec3
{
    float m_x;
    float m_y;
    float m_z;
    bool operator!=(const Unk_Vec3& other) const;
};


// @0x140266620
Unk_Vec4::Unk_Vec4() : m_x(0), m_y(0), m_z(0), m_w(0)
{
}

// @0x140266690
bool Unk_Vec3::operator!=(const Unk_Vec3& other) const
{
    if (m_x != other.m_x)
        return true;
    if (m_y != other.m_y)
        return true;
    if (m_z != other.m_z)
        return true;
    return false;
}

// @0x1402666f0
Unk_Vec7::Unk_Vec7() : m_a(0), m_b(0), m_c(200.0f), m_d(50.0f), m_e(0), m_f(0), m_g(0)
{
}

// @0x140266790
bool Unk_Vec7::operator!=(const Unk_Vec7& other) const
{
    if (m_a != other.m_a)
        return true;
    if (m_b != other.m_b)
        return true;
    if (m_c != other.m_c)
        return true;
    if (m_d != other.m_d)
        return true;
    if (m_e != other.m_e)
        return true;
    if (m_f != other.m_f)
        return true;
    if (m_g != other.m_g)
        return true;
    return false;
}

// @0x14025e7a0
Unk_AltStringMgr* FUN_14025e7a0()
{
    return DAT_143aaccf8;
}

// @0x14025e7b0
Unk_BanConfig* FUN_14025e7b0()
{
    return static_cast<Unk_BanConfig*>(DAT_143aacd08);
}

// @0x14025e7c0
void* FUN_14025e7c0()
{
    return DAT_143aacd00;
}

// @0x14025e7d0
CommonString* FUN_14025e7d0()
{
    return TSingleton<CommonString>::s_instance;
}

// @0x14025fab0
bool FUN_14025fab0(CStringW& str)
{
    try
    {
        str.MakeLower();
    }
    catch (ATL::CAtlException e)
    {
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\stringutil.h", 0x1a3), 0));
        return false;
    }
    return true;
}

template <class T, size_t N> size_t CountOf(T (&)[N])
{
    return N;
}

#define MS2_ASSERT_MSG_AT(line, msg, cond) (void)((!!(cond)) || (_wassert(msg, _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))

struct BanTestWord
{
    CStringW m_str;
    bool m_bOk;
};

struct BanTestMask
{
    CStringW m_src;
    CStringW m_masked;
};

// @0x1402599e0
bool CommonString::FUN_1402599e0()
{
    CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker();
    if (pChecker == 0)
    {
        MS2_ASSERT_AT(0xde, 0);
        return false;
    }
    if (pChecker->HasStartWithWords(0x40) == 0)
        return true;
    BanTestWord words[3] = { { CStringW(L"StaffSofia"), false }, { CStringW(L"magicstaff"), true }, { CStringW(L"staff"), false } };
    size_t nCount = CountOf(words);
    for (size_t i = 0; i < nCount; ++i)
    {
        BanTestWord* pWord = words + i;
        CStringW strMessage;
        bool bOk = false;
        int eResult = pChecker->FUN_140225210(pWord->m_str, strMessage, 0);
        if (pWord->m_bOk)
        {
            MS2_ASSERT_MSG_AT(0xfb, L"eResult == BanCheckResult_Ok", eResult == 0);
            bOk = eResult == 0;
        }
        else
        {
            MS2_ASSERT_MSG_AT(0x100, L"eResult != BanCheckResult_Ok", eResult != 0);
            bOk = eResult != 0;
        }
        if (bOk == false)
            return false;
    }
    BanTestMask masks[2] = { { CStringW(L"wow staffSofia staffStaff staffOlivia"), CStringW(L"wow *****Sofia *****Staff *****Olivia") }, { CStringW(L"staffSofia"), CStringW(L"*****Sofia") } };
    nCount = CountOf(masks);
    for (size_t i = 0; i < nCount; ++i)
    {
        BanTestMask* pMask = masks + i;
        CStringW strUnused;
        bool bOk = false;
        pChecker->MaskBannedWords(pMask->m_src);
        bOk = pMask->m_src.Compare(pMask->m_masked) == 0;
        if (!bOk)
        {
            MS2_ASSERT_AT(0x122, 0);
            return false;
        }
    }
    return true;
}

// @0x140229ad0
void CommonString::RegisterIds()
{
    m_strings[0] = "s_empty_string";
    m_strings[1] = "s_char_input_name";
    m_strings[2] = "s_char_level_job";
    m_strings[3] = "s_char_delete_waiting";
    m_strings[4] = "s_char_ask_delete";
    m_strings[5] = "s_char_ask_delete_with_wait";
    m_strings[6] = "s_char_ask_delete_final";
    m_strings[7] = "s_char_ask_delete_confirm_checkbox";
    m_strings[8] = "s_char_ask_revival_char";
    m_strings[9] = "s_char_err_char_count";
    m_strings[10] = "s_char_err_char_count_by_gameevent";
    m_strings[11] = "s_char_err_name";
    m_strings[12] = "s_char_err_system";
    m_strings[13] = "s_char_err_input";
    m_strings[15] = "s_char_err_ban_all";
    m_strings[14] = "s_char_err_ban_any";
    m_strings[16] = "s_char_err_already_taken";
    m_strings[17] = "s_char_err_invalid_def_item";
    m_strings[18] = "s_char_err_job_forbidden";
    m_strings[19] = "s_char_err_creation_restriction";
    m_strings[20] = "s_char_err_unknown";
    m_strings[21] = "s_char_err_exist_ugc_map";
    m_strings[22] = "s_char_err_already_destroy";
    m_strings[23] = "s_char_err_destroy";
    m_strings[24] = "s_char_err_delete_name";
    m_strings[25] = "s_char_err_guild_master";
    m_strings[26] = "s_char_err_guild";
    m_strings[27] = "s_char_err_ugc_market";
    m_strings[28] = "s_char_err_black_market_count";
    m_strings[29] = "s_char_err_unread_mail";
    m_strings[30] = "s_char_err_no_destroy_wait";
    m_strings[31] = "s_char_info_birthday";
    m_strings[32] = "s_char_info_level_job";
    m_strings[33] = "s_char_info_guild";
    m_strings[34] = "s_char_info_ugcmap";
    m_strings[35] = "s_char_info_home_name";
    m_strings[36] = "s_char_info_guild_name";
    m_strings[37] = "s_char_info_home_commend";
    m_strings[38] = "s_char_info_err_not_found";
    m_strings[39] = "s_change_charname_disconnect";
    m_strings[40] = "s_change_charname_confirm";
    m_strings[41] = "s_change_charname_err_bad_words";
    m_strings[42] = "s_change_charname_err_already_taken";
    m_strings[43] = "s_change_charname_err_consume_item";
    m_strings[44] = "s_change_charname_err_system";
    m_strings[45] = "s_err_gender";
    m_strings[46] = "s_err_target";
    m_strings[47] = "s_err_job";
    m_strings[48] = "s_err_stat";
    m_strings[49] = "s_err_lack_coupon";
    m_strings[50] = "s_err_lack_super_coupon";
    m_strings[51] = "s_err_lack_money";
    m_strings[52] = "s_err_lack_meso";
    m_strings[53] = "s_err_lack_merat";
    m_strings[54] = "s_err_lack_merat_blue";
    m_strings[55] = "s_err_lack_merat_red";
    m_strings[56] = "s_err_lack_payment_item";
    m_strings[57] = "s_err_lack_honor_token";
    m_strings[58] = "s_err_lack_karma_token";
    m_strings[59] = "s_err_lack_lu_token";
    m_strings[60] = "s_err_lack_habi_token";
    m_strings[61] = "s_err_lack_reverse_coin";
    m_strings[62] = "s_err_lack_mentor_token";
    m_strings[63] = "s_err_lack_mentee_token";
    m_strings[64] = "s_err_lack_star_point";
    m_strings[65] = "s_err_lack_meso_market_token";
    m_strings[66] = "s_err_unable";
    m_strings[67] = "s_err_inventory";
    m_strings[68] = "s_err_inventory_tab_full";
    m_strings[69] = "s_err_dropitem_pickfail_ownership";
    m_strings[70] = "s_err_lack_hp";
    m_strings[71] = "s_err_lack_sp";
    m_strings[72] = "s_err_lack_ep";
    m_strings[73] = "s_err_lack_shopitem";
    m_strings[74] = "s_err_shop_expired";
    m_strings[75] = "s_err_invalid_item";
    m_strings[76] = "s_err_input";
    m_strings[77] = "s_err_cannot_find_user";
    m_strings[78] = "s_err_input_whisper_target";
    m_strings[79] = "s_err_cannot_find_club";
    m_strings[80] = "s_err_input_club";
    m_strings[81] = "s_err_cannot_move";
    m_strings[82] = "s_err_cannot_fly";
    m_strings[83] = "s_err_cannot_use_here";
    m_strings[84] = "s_err_cannot_use_dead";
    m_strings[85] = "s_err_cannot_use_cooltime";
    m_strings[86] = "s_err_cannot_use_only_shadowworld";
    m_strings[87] = "s_err_require_additional_effect";
    m_strings[88] = "s_err_got_of_control_unable_potion";
    m_strings[133] = "s_err_empty_tabname";
    m_strings[134] = "s_err_duplicate_tabname";
    m_strings[135] = "s_err_lack_itemcount";
    m_strings[136] = "s_err_null_product";
    m_strings[89] = "s_err_skill_use_disable";
    m_strings[90] = "s_err_skill_use_disable_by_require_condition";
    m_strings[91] = "s_err_lack_guild_trophy";
    m_strings[92] = "s_err_lack_achieve";
    m_strings[93] = "s_err_lack_championship_grade";
    m_strings[94] = "s_err_lack_championship_join_count";
    m_strings[95] = "s_err_cannot_use_by_function_cube_climb";
    m_strings[96] = "s_err_cannot_use_by_function_cube_jump";
    m_strings[97] = "s_err_cannot_use_by_function_cube_skill";
    m_strings[98] = "s_err_cannot_use_by_function_cube_play_instrument";
    m_strings[99] = "s_err_cannot_use_in_design_home";
    m_strings[100] = "s_err_cannot_buy_limited_item_more";
    m_strings[101] = "s_err_cannot_install_blueprint";
    m_strings[102] = "s_err_cannot_install_maid_in_practice";
    m_strings[103] = "s_err_cannot_install_nurturing_in_design_home";
    m_strings[104] = "s_err_cannot_install_magic_portal";
    m_strings[105] = "s_err_cannot_install_trigger_editor";
    m_strings[106] = "s_err_cannot_install_trigger_controlobject";
    m_strings[107] = "s_err_cannot_install_interior_message";
    m_strings[108] = "s_err_cannot_install_event_cube";
    m_strings[109] = "s_err_cannot_install_trophy_relative_cube";
    m_strings[110] = "s_err_cannot_install_workbench_cube";
    m_strings[111] = "s_err_cannot_install_fittingdoll";
    m_strings[112] = "s_err_cannot_install_ugcdesign_maidin_other";
    m_strings[113] = "s_err_cannot_destroy_petitem_summon";
    m_strings[114] = "s_err_cannot_destroy_petitem_hasitem";
    m_strings[115] = "s_err_check_survival_with";
    m_strings[116] = "s_err_cannot_use_maview_in_testsvr";
    m_strings[117] = "s_job_difficulty";
    m_strings[118] = "s_err_job_not_enough_meso";
    m_strings[119] = "s_err_job_not_enough_level";
    m_strings[120] = "s_err_job_bad_job";
    m_strings[121] = "s_err_job_no_penalty";
    m_strings[122] = "s_err_job_no_home";
    m_strings[123] = "s_err_job_not_complete_quest";
    m_strings[124] = "s_err_job_privilege";
    m_strings[125] = "s_err_job_dayofweek";
    m_strings[126] = "s_err_job_debuff";
    m_strings[127] = "s_err_job_guild";
    m_strings[128] = "s_err_job_inventory_full";
    m_strings[129] = "s_err_job_unknown";
    m_strings[130] = "s_mirror_err_not_editable_cp";
    m_strings[131] = "s_mirror_err_not_editable_cp_by_transp_badge";
    m_strings[132] = "s_mirror_err_not_equip_cp";
    m_strings[137] = "s_err_near_taxi_station";
    m_strings[138] = "s_err_taxi_same_field";
    m_strings[139] = "s_taxi_transfer";
    m_strings[140] = "s_cash_taxi_transfer";
    m_strings[141] = "s_event_free_taxi_transfer";
    m_strings[142] = "s_err_cash_taxi_continent";
    m_strings[143] = "s_err_cash_taxi_cannot_departure";
    m_strings[144] = "s_err_cash_taxi_cannot_destination";
    m_strings[145] = "s_err_cash_taxi_cannot_now";
    m_strings[146] = "s_err_cash_taxi_cannot_craft_mode";
    m_strings[147] = "s_err_cash_taxi_cannot_place";
    m_strings[148] = "s_err_cash_call_medic_prohibit_map";
    m_strings[149] = "s_err_cash_call_medic_cannot_now";
    m_strings[150] = "s_err_cash_call_medic_revival_count";
    m_strings[151] = "s_err_cash_call_medic_cannot_place";
    m_strings[152] = "s_cash_call_medic_complete";
    m_strings[153] = "s_err_cash_call_market_prohibit_map";
    m_strings[154] = "s_err_cash_call_market_cannot_now";
    m_strings[155] = "s_err_cash_call_market_cannot_place";
    m_strings[156] = "s_err_cash_call_market_cannot_already";
    m_strings[157] = "s_err_cash_call_bank_cannot_now";
    m_strings[158] = "s_err_cash_call_bank_cannot_now_already";
    m_strings[159] = "s_err_cash_call_bank_cannot_now_place";
    m_strings[160] = "s_err_cash_call_cancel";
    m_strings[161] = "s_err_timeevent_move_field";
    m_strings[162] = "s_err_timeevent_battle";
    m_strings[163] = "s_err_timeevent_samefield";
    m_strings[164] = "s_err_timeevent_same_continent";
    m_strings[165] = "s_err_itemlink_cannot_other_user";
    m_strings[168] = "s_worldmap_timeevent_move";
    m_strings[166] = "s_err_worldmap_search_nothing_field";
    m_strings[167] = "s_err_worldmap_search_invisible_field";
    m_strings[169] = "s_timeevent_notice_chat";
    m_strings[170] = "s_revival_panelty";
    m_strings[171] = "s_fail_login";
    m_strings[172] = "s_fail_connect";
    m_strings[173] = "s_fail_char_create";
    m_strings[174] = "s_notice_shutdown";
    m_strings[175] = "s_npc_normal";
    m_strings[176] = "s_npc_leader";
    m_strings[177] = "s_npc_named";
    m_strings[178] = "s_npc_boss";
    m_strings[179] = "s_npc_field_boss";
    m_strings[180] = "s_npc_dungeon_boss";
    m_strings[181] = "s_npc_friendly";
    m_strings[182] = "s_item_require_weapon";
    m_strings[183] = "s_item_edit_time";
    m_strings[184] = "s_item_end_time";
    m_strings[185] = "s_item_end_time_expired";
    m_strings[186] = "s_item_end_time_maid";
    m_strings[187] = "s_item_end_time_maid_expired";
    m_strings[188] = "s_item_end_time_pcbang";
    m_strings[189] = "s_item_end_time_pcbang_expired";
    m_strings[190] = "s_item_end_time_tooltip";
    m_strings[191] = "s_item_end_time_tooltip_expiration";
    m_strings[192] = "s_item_end_time_tooltip_pcbang";
    m_strings[193] = "s_item_end_time_tooltip_maid";
    m_strings[194] = "s_item_end_time_when_item_get_tooltip";
    m_strings[195] = "s_item_end_time_when_item_get_tooltip_pcbang";
    m_strings[196] = "s_item_end_time_when_item_get_tooltip_maid";
    m_strings[197] = "s_item_word_d";
    m_strings[198] = "s_item_word_h";
    m_strings[199] = "s_item_word_m";
    m_strings[200] = "s_item_type_active";
    m_strings[201] = "s_item_type_passive";
    m_strings[202] = "s_item_type_twohand";
    m_strings[203] = "s_item_type_lefthand";
    m_strings[204] = "s_item_type_righthand";
    m_strings[205] = "s_item_err_code";
    m_strings[206] = "s_item_err_puton";
    m_strings[207] = "s_item_err_putoff";
    m_strings[208] = "s_item_err_destroy_equip";
    m_strings[209] = "s_item_err_no_weapon";
    m_strings[210] = "s_item_err_invalid_weapon";
    m_strings[211] = "s_item_err_Invalid_slot";
    m_strings[212] = "s_item_err_cash_slot";
    m_strings[213] = "s_item_err_cash_putoff";
    m_strings[214] = "s_item_err_twohand";
    m_strings[215] = "s_item_err_drop";
    m_strings[216] = "s_item_err_cannot_drop";
    m_strings[217] = "s_item_err_cannot_drop_if_binding";
    m_strings[218] = "s_item_err_binding_destroy";
    m_strings[219] = "s_item_err_binding_destroy_at_fittingdoll";
    m_strings[220] = "s_item_err_binditem_in_socket_store_out";
    m_strings[221] = "s_item_err_binding_in_socket_destroy";
    m_strings[222] = "s_item_err_binding_in_socket_destroy_at_fittingdoll";
    m_strings[223] = "s_item_err_cubeitem_destroy";
    m_strings[224] = "s_item_err_puton_low_level";
    m_strings[225] = "s_item_err_puton_expired";
    m_strings[226] = "s_item_err_puton_pcbang";
    m_strings[227] = "s_item_err_use_low_level";
    m_strings[228] = "s_item_invalid_function_item";
    m_strings[229] = "s_item_invalid_function_not_use_item";
    m_strings[230] = "s_item_invalid_do_not_have";
    m_strings[231] = "s_word_item_change_name_samename";
    m_strings[232] = "s_item_err_puton_job";
    m_strings[233] = "s_item_err_disable_job";
    m_strings[234] = "s_item_err_puton_invalid";
    m_strings[235] = "s_item_err_invalid_count";
    m_strings[236] = "s_item_err_cant_sell";
    m_strings[237] = "s_item_err_transfer_item_bound";
    m_strings[238] = "s_item_err_range";
    m_strings[239] = "s_item_err_skill_level";
    m_strings[240] = "s_item_err_puton_skill_samekinds";
    m_strings[241] = "s_item_err_invaild_store_type";
    m_strings[242] = "s_item_err_store_full";
    m_strings[243] = "s_item_tooltip_ugc_removed";
    m_strings[244] = "s_item_ugc_name_blocked";
    m_strings[245] = "s_item_err_cant_sell_riding_item";
    m_strings[246] = "s_item_err_cant_attach_to_mail_riding_item";
    m_strings[247] = "s_item_err_cant_drop_riding_item";
    m_strings[248] = "s_item_err_cant_trade_riding_item";
    m_strings[249] = "s_item_err_donot_preview";
    m_strings[250] = "s_item_err_donot_preview_expire";
    m_strings[251] = "s_item_err_binditem";
    m_strings[252] = "s_item_err_binditem_store_out";
    m_strings[253] = "s_item_err_puton_invalid_binding";
    m_strings[254] = "s_item_err_use_invalid_binding";
    m_strings[255] = "s_item_err_moveDisableitem_store_out";
    m_strings[256] = "s_item_opt_error";
    m_strings[257] = "s_item_opt_sa_improve_acquire_exp";
    m_strings[258] = "s_item_opt_sa_improve_acquire_exp_v";
    m_strings[259] = "s_item_opt_sa_improve_acquire_exp_r";
    m_strings[260] = "s_item_opt_sa_improve_acquire_meso";
    m_strings[261] = "s_item_opt_sa_improve_acquire_meso_v";
    m_strings[262] = "s_item_opt_sa_improve_acquire_meso_r";
    m_strings[263] = "s_item_opt_sa_improve_speed_swim";
    m_strings[264] = "s_item_opt_sa_improve_speed_swim_v";
    m_strings[265] = "s_item_opt_sa_improve_speed_swim_r";
    m_strings[266] = "s_item_opt_sa_improve_speed_dash";
    m_strings[267] = "s_item_opt_sa_improve_speed_dash_v";
    m_strings[268] = "s_item_opt_sa_improve_speed_dash_r";
    m_strings[269] = "s_item_opt_sa_improve_damage_critical";
    m_strings[270] = "s_item_opt_sa_improve_damage_critical_v";
    m_strings[271] = "s_item_opt_sa_improve_damage_critical_r";
    m_strings[272] = "s_item_opt_sa_improve_damage_normalNpc";
    m_strings[273] = "s_item_opt_sa_improve_damage_normalNpc_v";
    m_strings[274] = "s_item_opt_sa_improve_damage_normalNpc_r";
    m_strings[275] = "s_item_opt_sa_improve_damage_namedNpc";
    m_strings[276] = "s_item_opt_sa_improve_damage_namedNpc_v";
    m_strings[277] = "s_item_opt_sa_improve_damage_namedNpc_r";
    m_strings[278] = "s_item_opt_sa_improve_damage_bossNpc";
    m_strings[279] = "s_item_opt_sa_improve_damage_bossNpc_v";
    m_strings[280] = "s_item_opt_sa_improve_damage_bossNpc_r";
    m_strings[281] = "s_item_opt_sa_improve_recovery_regen_doheal";
    m_strings[282] = "s_item_opt_sa_improve_recovery_regen_doheal_v";
    m_strings[283] = "s_item_opt_sa_improve_recovery_regen_doheal_r";
    m_strings[284] = "s_item_opt_sa_improve_recovery_regen_receiveheal";
    m_strings[285] = "s_item_opt_sa_improve_recovery_regen_receiveheal_v";
    m_strings[286] = "s_item_opt_sa_improve_recovery_regen_receiveheal_r";
    m_strings[287] = "s_item_opt_sa_reduce_time_stun";
    m_strings[288] = "s_item_opt_sa_reduce_time_stun_v";
    m_strings[289] = "s_item_opt_sa_reduce_time_stun_r";
    m_strings[290] = "s_item_opt_sa_improve_recovery_hp_dokill";
    m_strings[291] = "s_item_opt_sa_improve_recovery_hp_dokill_v";
    m_strings[292] = "s_item_opt_sa_improve_recovery_hp_dokill_r";
    m_strings[293] = "s_item_opt_sa_improve_recovery_sp_dokill";
    m_strings[294] = "s_item_opt_sa_improve_recovery_sp_dokill_v";
    m_strings[295] = "s_item_opt_sa_improve_recovery_sp_dokill_r";
    m_strings[296] = "s_item_opt_sa_improve_recovery_ep_dokill";
    m_strings[297] = "s_item_opt_sa_improve_recovery_ep_dokill_v";
    m_strings[298] = "s_item_opt_sa_improve_recovery_ep_dokill_r";
    m_strings[299] = "s_item_opt_sa_reduce_time_cooldown";
    m_strings[300] = "s_item_opt_sa_reduce_time_cooldown_v";
    m_strings[301] = "s_item_opt_sa_reduce_time_cooldown_r";
    m_strings[302] = "s_item_opt_sa_stat_attackpoint";
    m_strings[303] = "s_item_opt_sa_stat_attackpoint_v";
    m_strings[304] = "s_item_opt_sa_stat_attackpoint_r";
    m_strings[305] = "s_item_opt_sa_improve_elements_ice";
    m_strings[306] = "s_item_opt_sa_improve_elements_ice_v";
    m_strings[307] = "s_item_opt_sa_improve_elements_ice_r";
    m_strings[308] = "s_item_opt_sa_improve_elements_fire";
    m_strings[309] = "s_item_opt_sa_improve_elements_fire_v";
    m_strings[310] = "s_item_opt_sa_improve_elements_fire_r";
    m_strings[311] = "s_item_opt_sa_improve_elements_dark";
    m_strings[312] = "s_item_opt_sa_improve_elements_dark_v";
    m_strings[313] = "s_item_opt_sa_improve_elements_dark_r";
    m_strings[314] = "s_item_opt_sa_improve_elements_light";
    m_strings[315] = "s_item_opt_sa_improve_elements_light_v";
    m_strings[316] = "s_item_opt_sa_improve_elements_light_r";
    m_strings[317] = "s_item_opt_sa_improve_elements_poison";
    m_strings[318] = "s_item_opt_sa_improve_elements_poison_v";
    m_strings[319] = "s_item_opt_sa_improve_elements_poison_r";
    m_strings[320] = "s_item_opt_sa_improve_elements_thunder";
    m_strings[321] = "s_item_opt_sa_improve_elements_thunder_v";
    m_strings[322] = "s_item_opt_sa_improve_elements_thunder_r";
    m_strings[323] = "s_item_opt_sa_improve_damage_nearrange";
    m_strings[324] = "s_item_opt_sa_improve_damage_nearrange_r";
    m_strings[325] = "s_item_opt_sa_improve_damage_nearrange_v";
    m_strings[326] = "s_item_opt_sa_improve_damage_longrange";
    m_strings[327] = "s_item_opt_sa_improve_damage_longrange_r";
    m_strings[328] = "s_item_opt_sa_improve_damage_longrange_v";
    m_strings[329] = "s_item_opt_sa_improve_piercing_par";
    m_strings[330] = "s_item_opt_sa_improve_piercing_par_r";
    m_strings[331] = "s_item_opt_sa_improve_piercing_par_v";
    m_strings[332] = "s_item_opt_sa_improve_piercing_mar";
    m_strings[333] = "s_item_opt_sa_improve_piercing_mar_r";
    m_strings[334] = "s_item_opt_sa_improve_piercing_mar_v";
    m_strings[335] = "s_item_opt_sa_reduce_elements_ice";
    m_strings[336] = "s_item_opt_sa_reduce_elements_ice_v";
    m_strings[337] = "s_item_opt_sa_reduce_elements_ice_r";
    m_strings[338] = "s_item_opt_sa_reduce_elements_fire";
    m_strings[339] = "s_item_opt_sa_reduce_elements_fire_v";
    m_strings[340] = "s_item_opt_sa_reduce_elements_fire_r";
    m_strings[341] = "s_item_opt_sa_reduce_elements_dark";
    m_strings[342] = "s_item_opt_sa_reduce_elements_dark_v";
    m_strings[343] = "s_item_opt_sa_reduce_elements_dark_r";
    m_strings[344] = "s_item_opt_sa_reduce_elements_light";
    m_strings[345] = "s_item_opt_sa_reduce_elements_light_v";
    m_strings[346] = "s_item_opt_sa_reduce_elements_light_r";
    m_strings[347] = "s_item_opt_sa_reduce_elements_poison";
    m_strings[348] = "s_item_opt_sa_reduce_elements_poison_v";
    m_strings[349] = "s_item_opt_sa_reduce_elements_poison_r";
    m_strings[350] = "s_item_opt_sa_reduce_elements_thunder";
    m_strings[351] = "s_item_opt_sa_reduce_elements_thunder_v";
    m_strings[352] = "s_item_opt_sa_reduce_elements_thunder_r";
    m_strings[353] = "s_item_opt_sa_reduce_time_condition";
    m_strings[354] = "s_item_opt_sa_reduce_time_condition_v";
    m_strings[355] = "s_item_opt_sa_reduce_time_condition_r";
    m_strings[356] = "s_item_opt_sa_reduce_distance_knockBack";
    m_strings[357] = "s_item_opt_sa_reduce_distance_knockBack_v";
    m_strings[358] = "s_item_opt_sa_reduce_distance_knockBack_r";
    m_strings[359] = "s_item_opt_sa_reduce_damage_nearrange";
    m_strings[361] = "s_item_opt_sa_reduce_damage_nearrange_v";
    m_strings[360] = "s_item_opt_sa_reduce_damage_nearrange_r";
    m_strings[362] = "s_item_opt_sa_reduce_damage_longrange";
    m_strings[364] = "s_item_opt_sa_reduce_damage_longrange_v";
    m_strings[363] = "s_item_opt_sa_reduce_damage_longrange_r";
    m_strings[365] = "s_item_opt_sa_improve_damage_final";
    m_strings[367] = "s_item_opt_sa_improve_damage_final_v";
    m_strings[366] = "s_item_opt_sa_improve_damage_final_r";
    m_strings[368] = "s_item_opt_sa_probability_stun_nearrange";
    m_strings[370] = "s_item_opt_sa_probability_stun_nearrange_v";
    m_strings[369] = "s_item_opt_sa_probability_stun_nearrange_r";
    m_strings[371] = "s_item_opt_sa_probability_stun_longrange";
    m_strings[373] = "s_item_opt_sa_probability_stun_longrange_v";
    m_strings[372] = "s_item_opt_sa_probability_stun_longrange_r";
    m_strings[374] = "s_item_opt_sa_probability_knockback_nearrange";
    m_strings[376] = "s_item_opt_sa_probability_knockback_nearrange_v";
    m_strings[375] = "s_item_opt_sa_probability_knockback_nearrange_r";
    m_strings[377] = "s_item_opt_sa_probability_knockback_longrange";
    m_strings[379] = "s_item_opt_sa_probability_knockback_longrange_v";
    m_strings[378] = "s_item_opt_sa_probability_knockback_longrange_r";
    m_strings[380] = "s_item_opt_sa_probability_cannotmove_nearrange";
    m_strings[382] = "s_item_opt_sa_probability_cannotmove_nearrange_v";
    m_strings[381] = "s_item_opt_sa_probability_cannotmove_nearrange_r";
    m_strings[383] = "s_item_opt_sa_probability_cannotmove_longrange";
    m_strings[385] = "s_item_opt_sa_probability_cannotmove_longrange_v";
    m_strings[384] = "s_item_opt_sa_probability_cannotmove_longrange_r";
    m_strings[386] = "s_item_opt_sa_probability_splashdamage_nearrange";
    m_strings[388] = "s_item_opt_sa_probability_splashdamage_nearrange_v";
    m_strings[387] = "s_item_opt_sa_probability_splashdamage_nearrange_r";
    m_strings[389] = "s_item_opt_sa_probability_splashdamage_longrange";
    m_strings[391] = "s_item_opt_sa_probability_splashdamage_longrange_v";
    m_strings[390] = "s_item_opt_sa_probability_splashdamage_longrange_r";
    m_strings[392] = "s_item_opt_sa_improve_npckill_dropitem_incrate";
    m_strings[393] = "s_item_opt_sa_improve_npckill_dropitem_incrate_r";
    m_strings[394] = "s_item_opt_sa_improve_npckill_dropitem_incrate_v";
    m_strings[395] = "s_item_opt_sa_improve_acquire_questreward_exp";
    m_strings[396] = "s_item_opt_sa_improve_acquire_questreward_exp_v";
    m_strings[397] = "s_item_opt_sa_improve_acquire_questreward_exp_r";
    m_strings[398] = "s_item_opt_sa_improve_acquire_fishing_exp";
    m_strings[399] = "s_item_opt_sa_improve_acquire_fishing_exp_v";
    m_strings[400] = "s_item_opt_sa_improve_acquire_fishing_exp_r";
    m_strings[401] = "s_item_opt_sa_improve_acquire_arcade_exp";
    m_strings[402] = "s_item_opt_sa_improve_acquire_arcade_exp_v";
    m_strings[403] = "s_item_opt_sa_improve_acquire_arcade_exp_r";
    m_strings[404] = "s_item_opt_sa_improve_acquire_playinstrument_exp";
    m_strings[405] = "s_item_opt_sa_improve_acquire_playinstrument_exp_v";
    m_strings[406] = "s_item_opt_sa_improve_acquire_playinstrument_exp_r";
    m_strings[407] = "s_item_opt_sa_invoke_effect";
    m_strings[408] = "s_item_opt_sa_invoke_skill_decrease_cooldowntime_v";
    m_strings[409] = "s_item_opt_sa_invoke_skill_increase_cooldowntime_v";
    m_strings[410] = "s_item_opt_sa_invoke_skill_damage_v";
    m_strings[411] = "s_item_opt_sa_invoke_effect_duration_v";
    m_strings[412] = "s_item_opt_sa_invoke_effect_conditioneffect_probability_v";
    m_strings[413] = "s_item_opt_sa_invoke_effect_dotdamage_v";
    m_strings[414] = "s_item_opt_sa_invoke_effect_hprecovery_v";
    m_strings[415] = "s_item_opt_sa_invoke_effect_hp_v";
    m_strings[416] = "s_item_opt_sa_invoke_effect_hp_rgp_v";
    m_strings[417] = "s_item_opt_sa_invoke_effect_hp_inv_v";
    m_strings[418] = "s_item_opt_sa_invoke_effect_sp_v";
    m_strings[419] = "s_item_opt_sa_invoke_effect_sp_rgp_v";
    m_strings[420] = "s_item_opt_sa_invoke_effect_sp_inv_v";
    m_strings[421] = "s_item_opt_sa_invoke_effect_ep_v";
    m_strings[422] = "s_item_opt_sa_invoke_effect_ep_rgp_v";
    m_strings[423] = "s_item_opt_sa_invoke_effect_ep_inv_v";
    m_strings[424] = "s_item_opt_sa_invoke_effect_str_v";
    m_strings[425] = "s_item_opt_sa_invoke_effect_atp_v";
    m_strings[426] = "s_item_opt_sa_invoke_effect_pap_v";
    m_strings[427] = "s_item_opt_sa_invoke_effect_dex_v";
    m_strings[428] = "s_item_opt_sa_invoke_effect_evp_v";
    m_strings[429] = "s_item_opt_sa_invoke_effect_map_v";
    m_strings[430] = "s_item_opt_sa_invoke_effect_int_v";
    m_strings[431] = "s_item_opt_sa_invoke_effect_cap_v";
    m_strings[432] = "s_item_opt_sa_invoke_effect_par_v";
    m_strings[433] = "s_item_opt_sa_invoke_effect_luk_v";
    m_strings[434] = "s_item_opt_sa_invoke_effect_cad_v";
    m_strings[435] = "s_item_opt_sa_invoke_effect_mar_v";
    m_strings[436] = "s_item_opt_sa_invoke_effect_car_v";
    m_strings[437] = "s_item_opt_sa_invoke_effect_pen_v";
    m_strings[438] = "s_item_opt_sa_invoke_effect_asp_v";
    m_strings[439] = "s_item_opt_sa_invoke_effect_ndd_v";
    m_strings[440] = "s_item_opt_sa_invoke_effect_msp_v";
    m_strings[441] = "s_item_opt_sa_invoke_effect_abp_v";
    m_strings[442] = "s_item_opt_sa_invoke_effect_rmsp_v";
    m_strings[443] = "s_item_opt_sa_invoke_effect_jmp_v";
    m_strings[444] = "s_item_opt_sa_invoke_effect_wap_min_v";
    m_strings[445] = "s_item_opt_sa_invoke_effect_wap_max_v";
    m_strings[446] = "s_item_opt_sa_invoke_effect_offensive_physical_damage_v";
    m_strings[447] = "s_item_opt_sa_invoke_effect_defensive_physical_damage_v";
    m_strings[448] = "s_item_opt_sa_invoke_effect_offensive_magical_damage_v";
    m_strings[449] = "s_item_opt_sa_invoke_effect_defensive_magical_damage_v";
    m_strings[450] = "s_item_opt_sa_invoke_effect_defensive_neardistance_damage_v";
    m_strings[451] = "s_item_opt_sa_invoke_effect_defensive_longdistance_damage_v";
    m_strings[452] = "s_item_opt_sa_invoke_effect_improve_elements_fire_v";
    m_strings[453] = "s_item_opt_sa_invoke_effect_improve_elements_ice_v";
    m_strings[454] = "s_item_opt_sa_invoke_effect_improve_elements_thunder_v";
    m_strings[455] = "s_item_opt_sa_invoke_effect_improve_elements_poison_v";
    m_strings[456] = "s_item_opt_sa_invoke_effect_improve_elements_holy_v";
    m_strings[457] = "s_item_opt_sa_invoke_effect_improve_elements_dark_v";
    m_strings[458] = "s_item_opt_sa_invoke_effect_reduce_elements_fire_v";
    m_strings[459] = "s_item_opt_sa_invoke_effect_reduce_elements_ice_v";
    m_strings[460] = "s_item_opt_sa_invoke_effect_reduce_elements_thunder_v";
    m_strings[461] = "s_item_opt_sa_invoke_effect_reduce_elements_poison_v";
    m_strings[462] = "s_item_opt_sa_invoke_effect_reduce_elements_holy_v";
    m_strings[463] = "s_item_opt_sa_invoke_effect_reduce_elements_dark_v";
    m_strings[464] = "s_item_opt_sa_invoke_skill_decrease_cooldowntime_r";
    m_strings[465] = "s_item_opt_sa_invoke_skill_increase_cooldowntime_r";
    m_strings[466] = "s_item_opt_sa_invoke_skill_damage_r";
    m_strings[467] = "s_item_opt_sa_invoke_effect_duration_r";
    m_strings[468] = "s_item_opt_sa_invoke_effect_conditioneffect_probability_r";
    m_strings[469] = "s_item_opt_sa_invoke_effect_dotdamage_r";
    m_strings[470] = "s_item_opt_sa_invoke_effect_hprecovery_r";
    m_strings[471] = "s_item_opt_sa_invoke_effect_hp_r";
    m_strings[472] = "s_item_opt_sa_invoke_effect_hp_rgp_r";
    m_strings[473] = "s_item_opt_sa_invoke_effect_hp_inv_r";
    m_strings[474] = "s_item_opt_sa_invoke_effect_sp_r";
    m_strings[475] = "s_item_opt_sa_invoke_effect_sp_rgp_r";
    m_strings[476] = "s_item_opt_sa_invoke_effect_sp_inv_r";
    m_strings[477] = "s_item_opt_sa_invoke_effect_ep_r";
    m_strings[478] = "s_item_opt_sa_invoke_effect_ep_rgp_r";
    m_strings[479] = "s_item_opt_sa_invoke_effect_ep_inv_r";
    m_strings[480] = "s_item_opt_sa_invoke_effect_str_r";
    m_strings[481] = "s_item_opt_sa_invoke_effect_atp_r";
    m_strings[482] = "s_item_opt_sa_invoke_effect_pap_r";
    m_strings[483] = "s_item_opt_sa_invoke_effect_dex_r";
    m_strings[484] = "s_item_opt_sa_invoke_effect_evp_r";
    m_strings[485] = "s_item_opt_sa_invoke_effect_map_r";
    m_strings[486] = "s_item_opt_sa_invoke_effect_int_r";
    m_strings[487] = "s_item_opt_sa_invoke_effect_cap_r";
    m_strings[488] = "s_item_opt_sa_invoke_effect_par_r";
    m_strings[489] = "s_item_opt_sa_invoke_effect_luk_r";
    m_strings[490] = "s_item_opt_sa_invoke_effect_cad_r";
    m_strings[491] = "s_item_opt_sa_invoke_effect_mar_r";
    m_strings[492] = "s_item_opt_sa_invoke_effect_car_r";
    m_strings[493] = "s_item_opt_sa_invoke_effect_pen_r";
    m_strings[494] = "s_item_opt_sa_invoke_effect_asp_r";
    m_strings[495] = "s_item_opt_sa_invoke_effect_ndd_r";
    m_strings[496] = "s_item_opt_sa_invoke_effect_msp_r";
    m_strings[497] = "s_item_opt_sa_invoke_effect_abp_r";
    m_strings[498] = "s_item_opt_sa_invoke_effect_rmsp_r";
    m_strings[499] = "s_item_opt_sa_invoke_effect_jmp_r";
    m_strings[500] = "s_item_opt_sa_invoke_effect_wap_min_r";
    m_strings[501] = "s_item_opt_sa_invoke_effect_wap_max_r";
    m_strings[502] = "s_item_opt_sa_invoke_effect_offensive_physical_damage_r";
    m_strings[503] = "s_item_opt_sa_invoke_effect_defensive_physical_damage_r";
    m_strings[504] = "s_item_opt_sa_invoke_effect_offensive_magical_damage_r";
    m_strings[505] = "s_item_opt_sa_invoke_effect_defensive_magical_damage_r";
    m_strings[506] = "s_item_opt_sa_invoke_effect_defensive_neardistance_damage_r";
    m_strings[507] = "s_item_opt_sa_invoke_effect_defensive_longdistance_damage_r";
    m_strings[508] = "s_item_opt_sa_invoke_effect_improve_elements_fire_r";
    m_strings[509] = "s_item_opt_sa_invoke_effect_improve_elements_ice_r";
    m_strings[510] = "s_item_opt_sa_invoke_effect_improve_elements_thunder_r";
    m_strings[511] = "s_item_opt_sa_invoke_effect_improve_elements_poison_r";
    m_strings[512] = "s_item_opt_sa_invoke_effect_improve_elements_holy_r";
    m_strings[513] = "s_item_opt_sa_invoke_effect_improve_elements_dark_r";
    m_strings[514] = "s_item_opt_sa_invoke_effect_reduce_elements_fire_r";
    m_strings[515] = "s_item_opt_sa_invoke_effect_reduce_elements_ice_r";
    m_strings[516] = "s_item_opt_sa_invoke_effect_reduce_elements_thunder_r";
    m_strings[517] = "s_item_opt_sa_invoke_effect_reduce_elements_poison_r";
    m_strings[518] = "s_item_opt_sa_invoke_effect_reduce_elements_holy_r";
    m_strings[519] = "s_item_opt_sa_invoke_effect_reduce_elements_dark_r";
    m_strings[520] = "s_item_opt_sa_improve_damage_pvp";
    m_strings[521] = "s_item_opt_sa_improve_damage_pvp_r";
    m_strings[522] = "s_item_opt_sa_improve_damage_pvp_v";
    m_strings[523] = "s_item_opt_sa_reduce_damage_pvp";
    m_strings[524] = "s_item_opt_sa_reduce_damage_pvp_v";
    m_strings[525] = "s_item_opt_sa_reduce_damage_pvp_r";
    m_strings[526] = "s_login_err_connect";
    m_strings[527] = "s_login_err_disconnected";
    m_strings[528] = "s_login_err_id";
    m_strings[529] = "s_login_err_pwd";
    m_strings[530] = "s_login_err_access";
    m_strings[531] = "s_login_err_full_server";
    m_strings[532] = "s_login_err_version";
    m_strings[533] = "s_login_err_full_ch";
    m_strings[534] = "s_login_err_db";
    m_strings[535] = "s_login_err_unknown";
    m_strings[536] = "s_login_err_check_passport";
    m_strings[537] = "s_login_err_restrict_title";
    m_strings[538] = "s_login_err_restrict";
    m_strings[539] = "s_login_err_alphatester";
    m_strings[540] = "s_login_err_block_new_account";
    m_strings[541] = "s_login_err_guest_nopcbang";
    m_strings[542] = "s_login_err_session_error";
    m_strings[543] = "s_login_err_external_block_nsn";
    m_strings[544] = "s_login_err_external_block_ip";
    m_strings[545] = "s_login_err_admin_ip";
    m_strings[546] = "s_login_err_main_atl";
    m_strings[547] = "s_login_err_auto_external_block";
    m_strings[548] = "s_login_err_tencent_signature";
    m_strings[549] = "s_ah_err_close";
    m_strings[550] = "s_ngs_err_login_error";
    m_strings[551] = "s_relocate_world_err";
    m_strings[552] = "s_mail_send";
    m_strings[553] = "s_mail_return";
    m_strings[554] = "s_mail_delete";
    m_strings[555] = "s_notify_mail_recieve";
    m_strings[556] = "s_mail_err_cannot_attach_item";
    m_strings[557] = "s_mail_read_list";
    m_strings[558] = "s_mail_delete_list";
    m_strings[559] = "s_mail_receive_list";
    m_strings[560] = "s_mail_delete_list_received_mail";
    m_strings[561] = "s_mail_delete_list_attached_mail";
    m_strings[562] = "s_mail_delete_list_attached_mail_checkbox";
    m_strings[563] = "s_mail_send_date";
    m_strings[564] = "s_mail_attach_item";
    m_strings[565] = "s_mail_delete_confirm";
    m_strings[566] = "s_mail_delete_exist_ad";
    m_strings[567] = "s_mail_delete_exist_attach";
    m_strings[568] = "s_mail_send_really";
    m_strings[569] = "s_mail_read_fail";
    m_strings[570] = "s_mail_error";
    m_strings[571] = "s_mail_error_already_attach_meso";
    m_strings[572] = "s_mail_error_range";
    m_strings[573] = "s_mail_error_not_select";
    m_strings[574] = "s_mail_error_username";
    m_strings[575] = "s_mail_error_cannot_attach_item";
    m_strings[576] = "s_mail_error_attachcount";
    m_strings[577] = "s_mail_error_already_receive";
    m_strings[578] = "s_mail_error_recipient_equal_sender";
    m_strings[579] = "s_mail_error_createmail";
    m_strings[580] = "s_mail_error_sendmail";
    m_strings[581] = "s_mail_error_empty_cleaning_user";
    m_strings[582] = "s_mail_error_empty_cleaning_system";
    m_strings[583] = "s_mail_error_empty_title";
    m_strings[584] = "s_mail_error_empty_content";
    m_strings[585] = "s_mail_error_alreadyread";
    m_strings[586] = "s_mail_error_receiveitem_to_inven";
    m_strings[587] = "s_mail_error_receive_expired";
    m_strings[588] = "s_mail_error_ad_expired";
    m_strings[589] = "s_mail_error_block_from_me";
    m_strings[590] = "s_mail_error_block_from_other";
    m_strings[591] = "s_mail_error_admin_character";
    m_strings[592] = "s_mail_error_from_admin_to_user";
    m_strings[593] = "s_mail_error_bancheck";
    m_strings[594] = "s_mail_error_admin_block";
    m_strings[595] = "s_mail_cleaning_title";
    m_strings[596] = "s_mail_cleaning_usermail";
    m_strings[597] = "s_mail_cleaning_systemmail";
    m_strings[598] = "s_mail_error_limit_input";
    m_strings[599] = "s_mail_period_item_include";
    m_strings[600] = "s_mail_period_item_include_chat";
    m_strings[601] = "s_inventory_tab_equip";
    m_strings[602] = "s_inventory_tab_life";
    m_strings[603] = "s_inventory_tab_etc";
    m_strings[604] = "s_inventory_tab_summon";
    m_strings[605] = "s_inventory_tab_skin";
    m_strings[606] = "s_inventory_tab_gem";
    m_strings[607] = "s_inventory_tab_quest";
    m_strings[608] = "s_inventory_tab_material";
    m_strings[609] = "s_inventory_tab_mastery";
    m_strings[610] = "s_inventory_tab_pet";
    m_strings[611] = "s_inventory_tab_activeskill";
    m_strings[612] = "s_inventory_tab_coin";
    m_strings[613] = "s_inventory_tab_badge";
    m_strings[614] = "s_inventory_ask_expand";
    m_strings[615] = "s_inventory_err_expand_max";
    m_strings[616] = "s_move_err_no_server";
    m_strings[617] = "s_move_err_over_user";
    m_strings[618] = "s_move_err_dungeon_not_exist";
    m_strings[620] = "s_move_err_member_limit";
    m_strings[621] = "s_move_err_time_out";
    m_strings[622] = "s_move_err_field_limit";
    m_strings[636] = "s_msg_die_beginner";
    m_strings[637] = "s_msg_die_warring_different_map_revive";
    m_strings[638] = "s_msg_revival_btn";
    m_strings[639] = "s_msg_revival_mapleworld_btn";
    m_strings[640] = "s_msg_revival_merat_btn";
    m_strings[641] = "s_msg_revival_merat_cannot_debuff";
    m_strings[642] = "s_msg_revival_merat_cannot_here";
    m_strings[643] = "s_msg_revival_merat_msg_box";
    m_strings[644] = "s_msg_revival_merat_not_dead";
    m_strings[645] = "s_msg_revival_meso_btn";
    m_strings[646] = "s_msg_revival_meso_event_btn";
    m_strings[647] = "s_msg_revival_dungeon_warning";
    m_strings[625] = "s_beauty_msg_back_game_no_save";
    m_strings[623] = "s_beauty_skin_name";
    m_strings[624] = "s_beauty_notice_hide_cap_by_transp_badge";
    m_strings[626] = "s_beauty_msg_error_code";
    m_strings[627] = "s_beauty_msg_error_product_expired";
    m_strings[628] = "s_beauty_tooltip_price";
    m_strings[629] = "s_beauty_tooltip_style";
    m_strings[630] = "s_beauty_tooltip_style_save_date";
    m_strings[631] = "s_beauty_msg_random";
    m_strings[632] = "s_beauty_msg_coloring_confirm";
    m_strings[633] = "s_beauty_goto_map_invalid_dead";
    m_strings[634] = "s_beauty_goto_map_invalid_battle";
    m_strings[635] = "s_beauty_goto_map_invalid_samefield";
    m_strings[648] = "s_msg_game_over";
    m_strings[649] = "s_msg_disconnect_kickuser";
    m_strings[650] = "s_msg_item_sell_request";
    m_strings[651] = "s_msg_item_sell_count_request";
    m_strings[654] = "s_msg_revial_meso";
    m_strings[655] = "s_msg_not_visit";
    m_strings[656] = "s_msg_not_visitable";
    m_strings[657] = "s_msg_admin_input_accountsn";
    m_strings[658] = "s_msg_tombstone";
    m_strings[659] = "s_msg_meso_drop";
    m_strings[660] = "s_msg_item_drop";
    m_strings[661] = "s_msg_item_buy";
    m_strings[662] = "s_msg_item_sell";
    m_strings[652] = "s_msg_item_sell_confirm";
    m_strings[653] = "s_msg_item_buy_confirm";
    m_strings[663] = "s_msg_item_repurchase";
    m_strings[664] = "s_msg_item_upgrade_level";
    m_strings[665] = "s_msg_item_upgrade_failed";
    m_strings[666] = "s_msg_item_upgrade_disabled";
    m_strings[667] = "s_msg_item_upgrade_complete";
    m_strings[668] = "s_msg_item_default";
    m_strings[669] = "s_msg_item_open_item_box";
    m_strings[670] = "s_msg_item_open_item_dont_ask_check";
    m_strings[671] = "s_msg_item_open_item_dont_ask_check_buycube";
    m_strings[672] = "s_msg_item_use_name";
    m_strings[673] = "s_msg_item_remove_expired_item_in_inventory";
    m_strings[674] = "s_msg_expand_inven_complete";
    m_strings[675] = "s_msg_expand_inven_already_maximum";
    m_strings[676] = "s_msg_expand_character_slot_complete";
    m_strings[677] = "s_msg_expand_character_slot_already_maximum";
    m_strings[678] = "s_msg_expand_inven_forced";
    m_strings[679] = "s_msg_currency_overflow";
    m_strings[695] = "s_msg_party_invite";
    m_strings[696] = "s_msg_popup_time";
    m_strings[697] = "s_msg_take_item";
    m_strings[698] = "s_msg_take_item_count";
    m_strings[699] = "s_msg_take_item_ugc_cube";
    m_strings[700] = "s_msg_take_item_count_ugc_cube";
    m_strings[701] = "s_msg_take_exp";
    m_strings[702] = "s_msg_take_assist_bonus_exp";
    m_strings[703] = "s_msg_take_assist_bonus_exp_system";
    m_strings[704] = "s_msg_take_map_exp";
    m_strings[705] = "s_msg_take_taxi_exp";
    m_strings[706] = "s_msg_take_telescope_exp";
    m_strings[707] = "s_msg_take_meso";
    m_strings[708] = "s_msg_consume_meso";
    m_strings[709] = "s_msg_take_pcbang";
    m_strings[710] = "s_msg_take_merat";
    m_strings[711] = "s_msg_take_merat_blue";
    m_strings[712] = "s_msg_take_merat_red";
    m_strings[713] = "s_msg_take_honor_token";
    m_strings[714] = "s_msg_take_karma_token";
    m_strings[715] = "s_msg_take_lu_token";
    m_strings[716] = "s_msg_take_habi_token";
    m_strings[717] = "s_msg_take_star_point";
    m_strings[718] = "s_msg_take_meso_market_token";
    m_strings[719] = "s_msg_cant_sell_trade_drop";
    m_strings[720] = "s_msg_cant_sell_trade";
    m_strings[721] = "s_msg_cant_sell_drop";
    m_strings[722] = "s_msg_cant_sell";
    m_strings[723] = "s_msg_cant_trade_drop";
    m_strings[724] = "s_msg_cant_trade";
    m_strings[725] = "s_msg_cant_drop";
    m_strings[726] = "s_msg_chatting_welcome";
    m_strings[727] = "s_msg_chatting_changechannel";
    m_strings[728] = "s_msg_chatting_consume_merat";
    m_strings[729] = "s_msg_chatting_consume_merat_blue";
    m_strings[730] = "s_msg_chatting_consume_merat_red";
    m_strings[731] = "s_msg_chatting_consume_merat_message";
    m_strings[758] = "s_notify_currency_overflow";
    m_strings[759] = "s_content_shutdown_notice";
    m_strings[760] = "s_banner_billboard_shutdown";
    m_strings[761] = "s_msg_warehouse_container_out";
    m_strings[762] = "s_msg_warehouse_container_loading";
    m_strings[763] = "s_msg_warehouse_container_count";
    m_strings[764] = "s_msg_warehouse_container_count_empty";
    m_strings[766] = "s_msg_crystal_upgrade_empty";
    m_strings[767] = "s_msg_crystal_upgrade_disabled";
    m_strings[768] = "s_msg_crystal_upgrade_complete";
    m_strings[769] = "s_msg_memo_today";
    m_strings[770] = "s_msg_preparing";
    m_strings[771] = "s_msg_transfer_bind_when_transform";
    m_strings[772] = "s_shop_reset_time_ddhhmmss";
    m_strings[773] = "s_shop_reset_time_hhmmss";
    m_strings[774] = "s_shop_reset_time_mmss";
    m_strings[775] = "s_shop_reset_time_ss";
    m_strings[776] = "s_shop_require_achieve";
    m_strings[777] = "s_shop_require_guild_trophy";
    m_strings[778] = "s_shop_require_championship_grade";
    m_strings[779] = "s_shop_err_item_restricted";
    m_strings[732] = "s_msg_skillbook_reset_all";
    m_strings[733] = "s_mas_move_connect";
    m_strings[734] = "s_msg_ugc_cannot_edit";
    m_strings[735] = "s_msg_ugc_cannot_find";
    m_strings[736] = "s_msg_ugc_not_select";
    m_strings[737] = "s_msg_ugc_not_file_preview";
    m_strings[738] = "s_msg_ugc_not_file_noexist";
    m_strings[739] = "s_msg_ugc_too_many_files";
    m_strings[740] = "s_msg_ugc_not_select_reserve";
    m_strings[741] = "s_msg_ugc_error_item_name";
    m_strings[742] = "s_msg_ugc_admin_banner";
    m_strings[743] = "s_msg_ugc_shutdown";
    m_strings[744] = "s_msg_ugc_cant_register_shortcut";
    m_strings[745] = "s_msg_ugc_fail_file_exist";
    m_strings[746] = "s_msg_ugc_fail_file_size";
    m_strings[747] = "s_msg_ugc_item_upload_confirm";
    m_strings[748] = "s_msg_ugc_item_edit_thumbnail_tooltip";
    m_strings[749] = "s_msg_ugc_item_edit_text_title";
    m_strings[750] = "s_msg_ugc_item_edit_complete";
    m_strings[751] = "s_msg_ugc_expired_item";
    m_strings[752] = "s_ugc_uic_error";
    m_strings[753] = "s_msg_cant_movechannel";
    m_strings[754] = "s_change_gender_confirm";
    m_strings[755] = "s_change_gender_err_equip_items";
    m_strings[756] = "s_change_gender_result_success";
    m_strings[757] = "s_change_gender_result_failed";
    m_strings[765] = "s_msg_skill_upgrade";
    m_strings[780] = "s_option_fullscreen";
    m_strings[781] = "s_option_windowmode";
    m_strings[782] = "s_option_windowmode_full";
    m_strings[783] = "s_option_resolution";
    m_strings[784] = "s_option_resolution_wide";
    m_strings[785] = "s_option_perf_very_low";
    m_strings[786] = "s_option_perf_low";
    m_strings[787] = "s_option_perf_normal";
    m_strings[788] = "s_option_perf_high";
    m_strings[789] = "s_option_perf_very_high";
    m_strings[790] = "s_option_category_action";
    m_strings[791] = "s_option_category_menu";
    m_strings[792] = "s_option_category_emotion";
    m_strings[793] = "s_option_category_etc";
    m_strings[794] = "s_option_category_debug";
    m_strings[795] = "s_party_join_me";
    m_strings[796] = "s_party_join_someone";
    m_strings[797] = "s_party_leave_me";
    m_strings[798] = "s_party_leave_someone";
    m_strings[799] = "s_party_expel_me";
    m_strings[800] = "s_party_expel_someone";
    m_strings[801] = "s_party_break";
    m_strings[802] = "s_party_member_login";
    m_strings[803] = "s_party_member_logout";
    m_strings[804] = "s_party_chief_me";
    m_strings[805] = "s_party_chief_someone";
    m_strings[806] = "s_party_member_dead_tomb";
    m_strings[807] = "s_party_member_dead_dark_tomb";
    m_strings[808] = "s_party_err_code";
    m_strings[809] = "s_party_err_not_exist";
    m_strings[810] = "s_party_err_already";
    m_strings[811] = "s_party_err_alreadyInvite";
    m_strings[812] = "s_party_err_not_chief";
    m_strings[813] = "s_party_err_full";
    m_strings[814] = "s_party_err_myself";
    m_strings[815] = "s_party_err_cannot_invite";
    m_strings[816] = "s_party_err_deny";
    m_strings[817] = "s_party_err_deny_by_auto";
    m_strings[818] = "s_party_err_deny_by_system";
    m_strings[819] = "s_party_err_deny_by_timeout";
    m_strings[820] = "s_party_err_leave_no_party";
    m_strings[821] = "s_party_err_no_party";
    m_strings[822] = "s_party_err_fail_enterable_result";
    m_strings[823] = "s_party_err_lack_level";
    m_strings[824] = "s_party_err_lack_gear_score";
    m_strings[825] = "s_party_err_full_limit_player";
    m_strings[826] = "s_party_err_invalid_recruit";
    m_strings[827] = "s_party_err_invalid_party";
    m_strings[828] = "s_party_err_invalid_chief";
    m_strings[829] = "s_party_err_wrong_party";
    m_strings[830] = "s_party_err_wrong_recruit";
    m_strings[831] = "s_party_check_change_chief";
    m_strings[832] = "s_party_check_expel_member";
    m_strings[833] = "s_party_expel_boss_room";
    m_strings[834] = "s_party_someone_get_high_item";
    m_strings[835] = "s_party_auto_join_confirm";
    m_strings[836] = "s_club_create";
    m_strings[837] = "s_club_create_ask";
    m_strings[838] = "s_club_break";
    m_strings[839] = "s_club_invite_someone";
    m_strings[840] = "s_club_invite_me";
    m_strings[841] = "s_club_invite_cant_me";
    m_strings[842] = "s_club_invite_invalid_charname";
    m_strings[843] = "s_club_join";
    m_strings[844] = "s_club_join_reject";
    m_strings[845] = "s_club_join_reject_invite";
    m_strings[846] = "s_club_join_reject_timeout";
    m_strings[847] = "s_club_join_reject_logout";
    m_strings[848] = "s_club_leave";
    m_strings[849] = "s_club_notify_leave";
    m_strings[850] = "s_club_notify_accept_invite";
    m_strings[851] = "s_club_notify_login_member";
    m_strings[852] = "s_club_notify_logout_member";
    m_strings[853] = "s_club_notify_change_master";
    m_strings[854] = "s_club_notify_change_master_me";
    m_strings[855] = "s_club_notify_change_buff";
    m_strings[856] = "s_club_notify_change_name";
    m_strings[857] = "s_club_ui_offline_time_day";
    m_strings[858] = "s_club_ui_offline_time_hour";
    m_strings[859] = "s_club_ui_offline_time_min";
    m_strings[860] = "s_club_ui_offline_time_sec";
    m_strings[861] = "s_club_ui_offline_unknown";
    m_strings[862] = "s_club_ui_offline";
    m_strings[863] = "s_club_ui_member_location";
    m_strings[864] = "s_club_ui_member_detail";
    m_strings[865] = "s_club_ui_invite_member";
    m_strings[866] = "s_club_ui_create";
    m_strings[867] = "s_club_ui_leave";
    m_strings[868] = "s_club_ui_change_master";
    m_strings[869] = "s_club_ui_create_time";
    m_strings[870] = "s_club_ui_select_target_member";
    m_strings[871] = "s_club_ui_current_member";
    m_strings[872] = "s_club_err_unknown";
    m_strings[873] = "s_club_err_create";
    m_strings[874] = "s_club_err_create_reject";
    m_strings[875] = "s_club_err_null_club";
    m_strings[876] = "s_club_err_create_no_party";
    m_strings[877] = "s_club_err_already_exist";
    m_strings[878] = "s_club_err_wait_inviting";
    m_strings[879] = "s_club_err_blocked";
    m_strings[880] = "s_club_err_has_guild";
    m_strings[881] = "s_club_err_invalid_guild";
    m_strings[882] = "s_club_err_null_user";
    m_strings[883] = "s_club_err_name_exist";
    m_strings[884] = "s_club_err_name_value";
    m_strings[885] = "s_club_err_null_member";
    m_strings[886] = "s_club_err_exist_member";
    m_strings[887] = "s_club_err_full_member";
    m_strings[888] = "s_club_err_not_join_member";
    m_strings[889] = "s_club_err_cannot_leave_master";
    m_strings[890] = "s_club_err_expel_target_master";
    m_strings[891] = "s_club_err_no_master";
    m_strings[892] = "s_club_err_fail_addmember";
    m_strings[893] = "s_club_err_null_invite_member";
    m_strings[894] = "s_club_err_none";
    m_strings[895] = "s_club_err_block";
    m_strings[896] = "s_club_err_fail_this_field";
    m_strings[897] = "s_club_err_full_club";
    m_strings[898] = "s_club_err_full_club_member";
    m_strings[899] = "s_club_err_notparty_alllogin";
    m_strings[900] = "s_club_err_remain_time";
    m_strings[901] = "s_club_err_same_club_name";
    m_strings[902] = "s_club_err_clubname_has_blank";
    m_strings[904] = "s_guild_err_no_guild";
    m_strings[905] = "s_guild_create";
    m_strings[906] = "s_guild_break";
    m_strings[907] = "s_guild_invite_someone";
    m_strings[908] = "s_guild_invite_me";
    m_strings[909] = "s_guild_invite_cant_me";
    m_strings[910] = "s_guild_invite_invalid_charname";
    m_strings[911] = "s_guild_join";
    m_strings[912] = "s_guild_join_reject";
    m_strings[913] = "s_guild_join_accecpt_invite";
    m_strings[914] = "s_guild_join_reject_invite";
    m_strings[915] = "s_guild_join_reject_logout";
    m_strings[916] = "s_guild_join_reject_timeout";
    m_strings[917] = "s_guild_leave";
    m_strings[918] = "s_guild_leave_master_cant";
    m_strings[919] = "s_guild_change_notify";
    m_strings[920] = "s_guild_change_grade_sucess";
    m_strings[921] = "s_guild_grade_default_master";
    m_strings[922] = "s_guild_grade_default_group1";
    m_strings[923] = "s_guild_grade_default_group2";
    m_strings[924] = "s_guild_grade_default_group3";
    m_strings[925] = "s_guild_grade_default_group4";
    m_strings[926] = "s_guild_grade_default_group5";
    m_strings[927] = "s_guild_extend_capacity_success";
    m_strings[928] = "s_guild_extend_capacity_err_cannot";
    m_strings[929] = "s_guild_extend_capacity_err_current";
    m_strings[930] = "s_guild_search_same_propensity";
    m_strings[931] = "s_guild_search_max_join_request";
    m_strings[932] = "s_guild_search_last_request";
    m_strings[933] = "s_guild_search_null_join_guild_request";
    m_strings[934] = "s_guild_notify_leave";
    m_strings[935] = "s_guild_notify_change_grade";
    m_strings[936] = "s_guild_notify_accept_invite";
    m_strings[937] = "s_guild_notify_expel_member";
    m_strings[938] = "s_guild_notify_expeled";
    m_strings[939] = "s_guild_notify_expeled_from";
    m_strings[940] = "s_guild_notify_login_member";
    m_strings[941] = "s_guild_notify_logout_member";
    m_strings[942] = "s_guild_notify_change_member_grade";
    m_strings[943] = "s_guild_notify_change_member_grade_me";
    m_strings[944] = "s_guild_notify_change_master";
    m_strings[945] = "s_guild_notify_change_master_me";
    m_strings[946] = "s_guild_notify_change_notify";
    m_strings[947] = "s_guild_notify_change_mark";
    m_strings[948] = "s_guild_notify_change_name";
    m_strings[949] = "s_guild_notify_change_capacity";
    m_strings[950] = "s_guild_notify_achieve_progress";
    m_strings[951] = "s_guild_notify_achieve_complete";
    m_strings[952] = "s_guild_notify_pvp_get_grade";
    m_strings[953] = "s_guild_notify_pvp_regist";
    m_strings[954] = "s_guild_notify_pvp_unregist";
    m_strings[955] = "s_guild_notify_pvp_result_win";
    m_strings[956] = "s_guild_notify_pvp_result_lose";
    m_strings[957] = "s_guild_notify_search_join_accept";
    m_strings[958] = "s_guild_notify_search_join_reject";
    m_strings[959] = "s_guild_pvp_matching_complete_success";
    m_strings[960] = "s_guild_pvp_matching_complete_fail";
    m_strings[961] = "s_guild_pvp_matching_complete_popup";
    m_strings[962] = "s_guild_pvp_already_pvp_field";
    m_strings[963] = "s_guild_pvp_can_regist_when_login";
    m_strings[964] = "s_guild_pvp_can_regist_when_playing";
    m_strings[965] = "s_guild_pvp_join_only_matched";
    m_strings[967] = "s_guild_pvp_join_not_equal_championship_guild";
    m_strings[968] = "s_guild_pvp_done_choose_championship_guild";
    m_strings[969] = "s_guild_search_choose_propensity";
    m_strings[970] = "s_guild_search_guild_search_no_result";
    m_strings[971] = "s_guild_search_join_reject_mail_sender";
    m_strings[972] = "s_guild_search_join_reject_mail_title";
    m_strings[973] = "s_guild_search_join_reject_mail_content";
    m_strings[974] = "s_guild_search_request_join_guild";
    m_strings[975] = "s_guild_search_cancel_request_join_guild";
    m_strings[976] = "s_guild_search_accept_requested_member";
    m_strings[977] = "s_guild_search_reject_requested_member";
    m_strings[978] = "s_guild_ui_offline_time_day";
    m_strings[979] = "s_guild_ui_offline_time_hour";
    m_strings[980] = "s_guild_ui_offline_time_min";
    m_strings[981] = "s_guild_ui_offline_time_sec";
    m_strings[982] = "s_guild_ui_offline_unknown";
    m_strings[983] = "s_guild_ui_offline";
    m_strings[984] = "s_guild_ui_member_location";
    m_strings[985] = "s_guild_ui_member_detail";
    m_strings[986] = "s_guild_ui_invite_member";
    m_strings[987] = "s_guild_ui_create";
    m_strings[988] = "s_guild_ui_change_notify";
    m_strings[989] = "s_guild_ui_extend_member";
    m_strings[990] = "s_guild_ui_extend_max";
    m_strings[991] = "s_guild_ui_break";
    m_strings[992] = "s_guild_ui_leave";
    m_strings[993] = "s_guild_ui_not_to_master";
    m_strings[994] = "s_guild_ui_change_master";
    m_strings[995] = "s_guild_ui_expel";
    m_strings[996] = "s_guild_ui_guild_create_time";
    m_strings[997] = "s_guild_ui_must_input_group_name";
    m_strings[998] = "s_guild_ui_already_member_have_group";
    m_strings[999] = "s_guild_ui_select_target_member";
    m_strings[1000] = "s_guild_ui_current_member";
    m_strings[1001] = "s_guild_ui_championship_history_score_normal";
    m_strings[1002] = "s_guild_ui_championship_history_no_fight_win";
    m_strings[1003] = "s_guild_ui_championship_history_no_fight_lose";
    m_strings[1004] = "s_guild_ui_championship_condition";
    m_strings[1005] = "s_guild_ui_championship_rating";
    m_strings[1006] = "s_guild_ui_championship_combat";
    m_strings[1007] = "s_guild_ui_championship_rank";
    m_strings[1008] = "s_guild_ui_championship_grade_tooltip";
    m_strings[1009] = "s_guild_ui_championship_really_unregist";
    m_strings[1010] = "s_guild_ui_championship_no_regist_auth";
    m_strings[1011] = "s_guild_ui_championship_no_period_day";
    m_strings[1012] = "s_guild_ui_championship_no_period_time";
    m_strings[1013] = "s_guild_ui_championship_my_participate";
    m_strings[1014] = "s_guild_ui_championship_member_participate";
    m_strings[1015] = "s_guild_ui_championship_member_grade_score";
    m_strings[1016] = "s_guild_ui_championship_reward_player";
    m_strings[1017] = "s_guild_ui_championship_reward_supporter";
    m_strings[1018] = "s_guild_ui_championship_choose_championship_guild";
    m_strings[1019] = "s_guild_ui_championship_info_championship_guild";
    m_strings[1020] = "s_guild_ui_pvp_draw";
    m_strings[1021] = "s_guild_ui_pvp_win";
    m_strings[1022] = "s_guild_ui_pvp_lose";
    m_strings[1023] = "s_guild_ui_pvp_result_winner_rating";
    m_strings[1024] = "s_guild_ui_pvp_result_loser_rating_add";
    m_strings[1025] = "s_guild_ui_pvp_result_reward";
    m_strings[1026] = "s_guild_search_join_requester_info";
    m_strings[1027] = "s_guild_err_unknown";
    m_strings[1028] = "s_guild_err_null_guild";
    m_strings[1029] = "s_guild_err_already_exist";
    m_strings[1030] = "s_guild_err_wait_inviting";
    m_strings[1031] = "s_guild_err_blocked";
    m_strings[1032] = "s_guild_err_has_guild";
    m_strings[1033] = "s_guild_err_invalid_guild";
    m_strings[1034] = "s_guild_err_null_user";
    m_strings[1035] = "s_guild_err_name_exist";
    m_strings[1036] = "s_guild_err_name_value";
    m_strings[1037] = "s_guild_err_null_member";
    m_strings[1038] = "s_guild_err_exist_member";
    m_strings[1039] = "s_guild_err_full_member";
    m_strings[1040] = "s_guild_err_not_join_member";
    m_strings[1041] = "s_guild_err_cannot_leave_master";
    m_strings[1042] = "s_guild_err_expel_target_master";
    m_strings[1043] = "s_guild_err_not_enough_level";
    m_strings[1044] = "s_guild_err_no_money";
    m_strings[1045] = "s_guild_err_no_authority";
    m_strings[1046] = "s_guild_err_no_master";
    m_strings[1047] = "s_guild_err_invalid_grade_range";
    m_strings[1048] = "s_guild_err_invalid_capacity_range";
    m_strings[1049] = "s_guild_err_invalid_grade_data";
    m_strings[1050] = "s_guild_err_invalid_grade_index";
    m_strings[1051] = "s_guild_err_exist_empty_grade_index";
    m_strings[1052] = "s_guild_err_set_grade_failed";
    m_strings[1053] = "s_guild_err_fail_addmember";
    m_strings[1054] = "s_guild_err_null_invite_member";
    m_strings[1055] = "s_guild_err_cant_during_pvp";
    m_strings[1056] = "s_guild_err_none";
    m_strings[1057] = "s_guild_err_block";
    m_strings[1058] = "s_guild_err_fail_change_gradename";
    m_strings[1059] = "s_guild_err_fail_change_gradename_row";
    m_strings[1060] = "s_guild_err_fail_this_field";
    m_strings[1061] = "s_individual_waiting_unknown";
    m_strings[1062] = "s_individual_waiting_min";
    m_strings[1063] = "s_individual_waiting_hour";
    m_strings[1064] = "s_individual_register_other_arena";
    m_strings[1065] = "s_individual_register_call_of_arena";
    m_strings[1066] = "s_individual_register_low_level";
    m_strings[1067] = "s_individual_register_done";
    m_strings[1068] = "s_individual_unregister_done";
    m_strings[1069] = "s_individual_matching_done";
    m_strings[1070] = "s_individual_join_error_dead";
    m_strings[1071] = "s_individual_join_error_field";
    m_strings[1072] = "s_whisper_err_myself";
    m_strings[1073] = "s_whisper_err_target";
    m_strings[1074] = "s_admin_block_velma_notice";
    m_strings[1075] = "s_admin_block_velma_notice_chat";
    m_strings[1076] = "s_admin_block_velma_add";
    m_strings[1077] = "s_admin_block_velma_endtime_dec";
    m_strings[1078] = "s_admin_block_velma_msgbox_title";
    m_strings[1079] = "s_admin_block_velma_msgbox_content";
    m_strings[1080] = "s_admin_block_velma_ugc_notice";
    m_strings[1081] = "s_admin_block_velma_ugc_add";
    m_strings[1082] = "s_admin_block_velma_ugc_endtime_dec";
    m_strings[1083] = "s_admin_block_velma_ugc_msgbox_title";
    m_strings[1084] = "s_admin_block_velma_ugc_msgbox_content";
    m_strings[1085] = "s_admin_block_transfer_msgbox_title";
    m_strings[1086] = "s_admin_block_transfer_msgbox_content";
    m_strings[1087] = "s_admin_block_transfer_msgbox_title_kr";
    m_strings[1088] = "s_admin_block_transfer_msgbox_content_kr";
    m_strings[1089] = "s_admin_block_login";
    m_strings[1090] = "s_admin_block_chat";
    m_strings[1091] = "s_admin_block_banner_reg";
    m_strings[1092] = "s_admin_block_ugcmarket_reg";
    m_strings[1093] = "s_admin_block_ugc_equip";
    m_strings[1094] = "s_admin_block_ugc_create";
    m_strings[1095] = "s_admin_block_guild_create";
    m_strings[1096] = "s_admin_block_guild_mark_change";
    m_strings[1097] = "s_admin_block_profile_change";
    m_strings[1098] = "s_admin_block_char_name_change";
    m_strings[1099] = "s_admin_block_mail_send";
    m_strings[1100] = "s_admin_block_ugcmap_create";
    m_strings[1101] = "s_admin_block_party_search";
    m_strings[1102] = "s_admin_block_play_score";
    m_strings[1103] = "s_admin_block_write_music";
    m_strings[1104] = "s_admin_block_period";
    m_strings[1105] = "s_admin_block_transfer";
    m_strings[1106] = "s_admin_block_profit";
    m_strings[1107] = "s_admin_block_default";
    m_strings[1108] = "s_admin_block_create_guild_msgbox_title";
    m_strings[1109] = "s_admin_block_create_guild_msgbox_content";
    m_strings[1110] = "s_quest_clear_time";
    m_strings[1111] = "s_quest_clear_morning";
    m_strings[1112] = "s_quest_clear_afternoon";
    m_strings[1113] = "s_quest_standard_level";
    m_strings[1114] = "s_skill_err_male";
    m_strings[1115] = "s_skill_err_female";
    m_strings[1116] = "s_skill_err_low_level";
    m_strings[1117] = "s_skill_err_weapon";
    m_strings[680] = "s_store_ask_expand";
    m_strings[681] = "s_store_ask_deposit";
    m_strings[682] = "s_store_ask_withdraw";
    m_strings[683] = "s_store_ask_in";
    m_strings[684] = "s_store_ask_out";
    m_strings[685] = "s_store_ask_close";
    m_strings[686] = "s_store_ask_homebank_close";
    m_strings[687] = "s_store_err_code";
    m_strings[688] = "s_store_err_expand_max";
    m_strings[689] = "s_store_err_deposit_disable_type";
    m_strings[690] = "s_store_err_deposit_invalid_money";
    m_strings[691] = "s_store_err_deposit_max_money";
    m_strings[692] = "s_store_err_withdraw_invalid_money";
    m_strings[693] = "s_store_err_withdraw_not_enough_balance";
    m_strings[694] = "s_store_err_deposit_not_enough_balance";
    m_strings[1118] = "s_title_shop";
    m_strings[1119] = "s_title_buyitem";
    m_strings[1120] = "s_title_sellitem";
    m_strings[1121] = "s_ugc_err_code";
    m_strings[1122] = "s_ugc_err_url";
    m_strings[1123] = "s_ugc_regist_ok";
    m_strings[1124] = "s_ugc_upload_ok_item";
    m_strings[1125] = "s_ugc_upload_ok_item_screenshot";
    m_strings[1126] = "s_ugc_upload_ok_home_screenshot";
    m_strings[1127] = "s_ugc_upload_ok_profile";
    m_strings[1128] = "s_ugc_upload_ok_banner_sch";
    m_strings[1129] = "s_ugc_upload_ok_banner";
    m_strings[1130] = "s_ugc_upload_must_profile";
    m_strings[1131] = "s_ugc_camera_profile_upload";
    m_strings[1132] = "s_ugc_sign_buy";
    m_strings[1133] = "s_ugc_sign_sell";
    m_strings[1134] = "s_ugc_err_craft_mode";
    m_strings[1135] = "s_ugc_confirm_destroy_bank";
    m_strings[1136] = "s_ugc_confirm_destroy_fittingdoll";
    m_strings[1137] = "s_ugc_confirm_destroy_fittingdoll_v2";
    m_strings[1138] = "s_ugc_confirm_destroy_password";
    m_strings[1139] = "s_ugc_confirm_destroy_trigger_editor";
    m_strings[1140] = "s_ugc_confirm_destroy_field_affected";
    m_strings[1141] = "s_word_ok";
    m_strings[1142] = "s_word_cancel";
    m_strings[1143] = "s_word_yes";
    m_strings[1144] = "s_word_no";
    m_strings[1145] = "s_word_accept";
    m_strings[1146] = "s_word_deny";
    m_strings[1147] = "s_word_complete";
    m_strings[1148] = "s_word_next";
    m_strings[1149] = "s_word_buy";
    m_strings[1150] = "s_word_sell";
    m_strings[1151] = "s_word_release";
    m_strings[1152] = "s_word_store_unlock";
    m_strings[1153] = "s_word_system";
    m_strings[1154] = "s_word_entire";
    m_strings[1155] = "s_word_friend";
    m_strings[1156] = "s_word_party";
    m_strings[1157] = "s_word_guild";
    m_strings[1158] = "s_word_increase";
    m_strings[1159] = "s_word_man";
    m_strings[1160] = "s_word_woman";
    m_strings[1161] = "s_word_man_or_woman";
    m_strings[1162] = "s_word_usercount";
    m_strings[1163] = "s_word_stat_increase";
    m_strings[1164] = "s_word_stat_increase_near_zero";
    m_strings[1165] = "s_word_stat_max";
    m_strings[1166] = "s_word_exp";
    m_strings[1167] = "s_word_stat_hp";
    m_strings[1168] = "s_word_stat_sp";
    m_strings[1169] = "s_word_stat_ep";
    m_strings[1170] = "s_word_stat_msp";
    m_strings[1171] = "s_word_stat_str";
    m_strings[1172] = "s_word_stat_dex";
    m_strings[1173] = "s_word_stat_int";
    m_strings[1174] = "s_word_stat_luk";
    m_strings[1175] = "s_word_stat_pap";
    m_strings[1176] = "s_word_stat_map";
    m_strings[1177] = "s_word_stat_par";
    m_strings[1178] = "s_word_stat_mar";
    m_strings[1179] = "s_word_stat_asp";
    m_strings[1180] = "s_word_stat_atp";
    m_strings[1181] = "s_word_stat_cap";
    m_strings[1182] = "s_word_stat_cad";
    m_strings[1183] = "s_word_stat_ndd";
    m_strings[1184] = "s_word_stat_evp";
    m_strings[1185] = "s_word_stat_car";
    m_strings[1186] = "s_word_stat_abp";
    m_strings[1187] = "s_word_stat_jmp";
    m_strings[1188] = "s_word_stat_hp_rgp";
    m_strings[1189] = "s_word_stat_hp_inv";
    m_strings[1190] = "s_word_stat_sp_rgp";
    m_strings[1191] = "s_word_stat_sp_inv";
    m_strings[1192] = "s_word_stat_ep_rgp";
    m_strings[1193] = "s_word_stat_ep_inv";
    m_strings[1194] = "s_word_stat_wap";
    m_strings[1195] = "s_word_stat_dmg";
    m_strings[1196] = "s_word_stat_pen";
    m_strings[1197] = "s_word_stat_rmsp";
    m_strings[1198] = "s_word_stat_bap";
    m_strings[1199] = "s_word_stat_bap_pet";
    m_strings[1200] = "s_word_stat_hp_v";
    m_strings[1201] = "s_word_stat_sp_v";
    m_strings[1202] = "s_word_stat_ep_v";
    m_strings[1203] = "s_word_stat_msp_v";
    m_strings[1204] = "s_word_stat_str_v";
    m_strings[1205] = "s_word_stat_dex_v";
    m_strings[1206] = "s_word_stat_int_v";
    m_strings[1207] = "s_word_stat_luk_v";
    m_strings[1208] = "s_word_stat_pap_v";
    m_strings[1209] = "s_word_stat_map_v";
    m_strings[1210] = "s_word_stat_par_v";
    m_strings[1211] = "s_word_stat_mar_v";
    m_strings[1212] = "s_word_stat_asp_v";
    m_strings[1213] = "s_word_stat_atp_v";
    m_strings[1214] = "s_word_stat_cap_v";
    m_strings[1215] = "s_word_stat_cad_v";
    m_strings[1216] = "s_word_stat_ndd_v";
    m_strings[1217] = "s_word_stat_evp_v";
    m_strings[1218] = "s_word_stat_car_v";
    m_strings[1219] = "s_word_stat_abp_v";
    m_strings[1220] = "s_word_stat_jmp_v";
    m_strings[1221] = "s_word_stat_hp_rgp_v";
    m_strings[1222] = "s_word_stat_hp_inv_v";
    m_strings[1223] = "s_word_stat_sp_rgp_v";
    m_strings[1224] = "s_word_stat_sp_inv_v";
    m_strings[1225] = "s_word_stat_ep_rgp_v";
    m_strings[1226] = "s_word_stat_ep_inv_v";
    m_strings[1227] = "s_word_stat_wap_d_v";
    m_strings[1228] = "s_word_stat_wap_u_v";
    m_strings[1229] = "s_word_stat_wap_common_v";
    m_strings[1230] = "s_word_stat_dmg_v";
    m_strings[1231] = "s_word_stat_pen_v";
    m_strings[1232] = "s_word_stat_rmsp_v";
    m_strings[1233] = "s_word_stat_bap_v";
    m_strings[1234] = "s_word_stat_bap_pet_v";
    m_strings[1235] = "s_word_stat_hp_r";
    m_strings[1236] = "s_word_stat_sp_r";
    m_strings[1237] = "s_word_stat_ep_r";
    m_strings[1238] = "s_word_stat_msp_r";
    m_strings[1239] = "s_word_stat_str_r";
    m_strings[1240] = "s_word_stat_dex_r";
    m_strings[1241] = "s_word_stat_int_r";
    m_strings[1242] = "s_word_stat_luk_r";
    m_strings[1243] = "s_word_stat_pap_r";
    m_strings[1244] = "s_word_stat_map_r";
    m_strings[1245] = "s_word_stat_par_r";
    m_strings[1246] = "s_word_stat_mar_r";
    m_strings[1247] = "s_word_stat_asp_r";
    m_strings[1248] = "s_word_stat_atp_r";
    m_strings[1249] = "s_word_stat_cap_r";
    m_strings[1250] = "s_word_stat_cad_r";
    m_strings[1251] = "s_word_stat_ndd_r";
    m_strings[1252] = "s_word_stat_evp_r";
    m_strings[1253] = "s_word_stat_car_r";
    m_strings[1254] = "s_word_stat_abp_r";
    m_strings[1255] = "s_word_stat_jmp_r";
    m_strings[1256] = "s_word_stat_hp_rgp_r";
    m_strings[1257] = "s_word_stat_hp_inv_r";
    m_strings[1258] = "s_word_stat_sp_rgp_r";
    m_strings[1259] = "s_word_stat_sp_inv_r";
    m_strings[1260] = "s_word_stat_ep_rgp_r";
    m_strings[1261] = "s_word_stat_ep_inv_r";
    m_strings[1262] = "s_word_stat_wap_d_r";
    m_strings[1263] = "s_word_stat_wap_u_r";
    m_strings[1264] = "s_word_stat_wap_common_r";
    m_strings[1265] = "s_word_stat_dmg_r";
    m_strings[1266] = "s_word_stat_pen_r";
    m_strings[1267] = "s_word_stat_rmsp_r";
    m_strings[1268] = "s_word_stat_bap_r";
    m_strings[1269] = "s_word_stat_bap_pet_r";
    m_strings[1270] = "s_word_stat_tnap";
    m_strings[1271] = "s_word_stat_twap";
    m_strings[1272] = "s_word_stat_weapon_damage";
    m_strings[1273] = "s_word_rank_no";
    m_strings[1274] = "s_word_rank_01";
    m_strings[1275] = "s_word_rank_02";
    m_strings[1276] = "s_word_rank_03";
    m_strings[1277] = "s_word_rank_04";
    m_strings[1278] = "s_word_rank_05";
    m_strings[1279] = "s_word_rank_06";
    m_strings[1280] = "s_word_rank_bonus";
    m_strings[1281] = "s_word_item_sk";
    m_strings[1282] = "s_word_item_hr";
    m_strings[1283] = "s_word_item_fa";
    m_strings[1284] = "s_word_item_fd";
    m_strings[1285] = "s_word_item_lh";
    m_strings[1286] = "s_word_item_rh";
    m_strings[1287] = "s_word_item_cp";
    m_strings[1288] = "s_word_item_mt";
    m_strings[1289] = "s_word_item_cl";
    m_strings[1290] = "s_word_item_pa";
    m_strings[1291] = "s_word_item_gl";
    m_strings[1292] = "s_word_item_sh";
    m_strings[1293] = "s_word_item_fh";
    m_strings[1294] = "s_word_item_ey";
    m_strings[1295] = "s_word_item_ea";
    m_strings[1296] = "s_word_item_pd";
    m_strings[1297] = "s_word_item_ri";
    m_strings[1298] = "s_word_item_be";
    m_strings[1299] = "s_word_item_er";
    m_strings[1302] = "s_word_item_oh";
    m_strings[1300] = "s_word_item_bu";
    m_strings[1301] = "s_word_item_de";
    m_strings[1303] = "s_word_item_look";
    m_strings[1304] = "s_word_item_equip";
    m_strings[1305] = "s_word_item_category_clothes";
    m_strings[1306] = "s_word_item_category_construction";
    m_strings[1307] = "s_word_item_unlimited_period";
    m_strings[1308] = "s_word_item_soldout";
    m_strings[1309] = "s_word_item_soldout_html";
    m_strings[1310] = "s_word_item_limit_sell";
    m_strings[1311] = "s_word_item_limit_trade";
    m_strings[1312] = "s_word_item_limit_sell_trade";
    m_strings[1313] = "s_word_item_limit_blackmarket";
    m_strings[1314] = "s_word_item_limit_blackmarket_sell";
    m_strings[1315] = "s_word_item_limit_trade_count";
    m_strings[1316] = "s_word_item_limit_trade_count_without_sell";
    m_strings[1317] = "s_word_item_limit_trade_count_without_sell_for_itemlock";
    m_strings[1318] = "s_word_item_limit_bind";
    m_strings[1319] = "s_word_item_limit_bind_format";
    m_strings[1320] = "s_word_item_notuse";
    m_strings[1321] = "s_word_item_notuse_hpfull";
    m_strings[1322] = "s_word_item_notuse_spfull";
    m_strings[1323] = "s_word_item_notuse_epfull";
    m_strings[1324] = "s_word_iconcode_none";
    m_strings[1325] = "s_word_iconcode_weapon";
    m_strings[1326] = "s_word_iconcode_armor";
    m_strings[1327] = "s_word_iconcode_accessory";
    m_strings[1328] = "s_word_iconcode_active";
    m_strings[1329] = "s_word_iconcode_passive";
    m_strings[1330] = "s_word_iconcode_potion";
    m_strings[1331] = "s_word_iconcode_scroll";
    m_strings[1332] = "s_word_iconcode_action";
    m_strings[1333] = "s_word_iconcode_etc";
    m_strings[1334] = "s_word_iconcode_land";
    m_strings[1335] = "s_word_iconcode_building";
    m_strings[1336] = "s_word_iconcode_interior";
    m_strings[1337] = "s_word_iconcode_souvenir";
    m_strings[1338] = "s_word_iconcode_pet";
    m_strings[1339] = "s_word_iconcode_riding";
    m_strings[1340] = "s_word_iconcode_mannequin";
    m_strings[1341] = "s_word_iconcode_store";
    m_strings[1342] = "s_word_iconcode_electronics";
    m_strings[1343] = "s_word_iconcode_coupon";
    m_strings[1344] = "s_word_iconcode_action_skillbook";
    m_strings[1345] = "s_word_iconcode_gem";
    m_strings[1346] = "s_word_iconcode_storybook";
    m_strings[1347] = "s_word_iconcode_maid";
    m_strings[1348] = "s_word_iconcode_package";
    m_strings[1349] = "s_word_iconcode_random";
    m_strings[1350] = "s_word_iconcode_crystal";
    m_strings[1351] = "s_word_iconcode_airtaxi";
    m_strings[1352] = "s_word_iconcode_dungeonkey";
    m_strings[1353] = "s_word_iconcode_workbench_cook";
    m_strings[1354] = "s_word_iconcode_workbench_alchemy";
    m_strings[1355] = "s_word_iconcode_workbench_biz";
    m_strings[1356] = "s_word_iconcode_buffportion";
    m_strings[1357] = "s_word_iconcode_trigger_controller";
    m_strings[1358] = "s_word_iconcode_interior_pack";
    m_strings[1359] = "s_word_iconcode_fishing_rod";
    m_strings[1360] = "s_word_iconcode_music_note";
    m_strings[1361] = "s_word_iconcode_music_instrument";
    m_strings[1362] = "s_word_iconcode_petfood";
    m_strings[1363] = "s_word_iconcode_bait";
    m_strings[1364] = "s_word_iconcode_gemstone";
    m_strings[1365] = "s_word_iconcode_jeweldust";
    m_strings[1366] = "s_word_iconcode_coin";
    m_strings[1367] = "s_word_iconcode_quest";
    m_strings[1368] = "s_word_iconcode_glide_item";
    m_strings[1369] = "s_word_iconcode_petequip";
    m_strings[1370] = "s_word_iconcode_blueprint";
    m_strings[1371] = "s_word_iconcode_capsule";
    m_strings[1372] = "s_word_week_sun";
    m_strings[1373] = "s_word_week_mon";
    m_strings[1374] = "s_word_week_tue";
    m_strings[1375] = "s_word_week_wed";
    m_strings[1376] = "s_word_week_thu";
    m_strings[1377] = "s_word_week_fri";
    m_strings[1378] = "s_word_week_sat";
    m_strings[1379] = "s_word_week_sun2";
    m_strings[1380] = "s_word_week_mon2";
    m_strings[1381] = "s_word_week_tue2";
    m_strings[1382] = "s_word_week_wed2";
    m_strings[1383] = "s_word_week_thu2";
    m_strings[1384] = "s_word_week_fri2";
    m_strings[1385] = "s_word_week_sat2";
    m_strings[1386] = "s_word_date_week";
    m_strings[1387] = "s_word_customize_length";
    m_strings[1388] = "s_word_customize_size";
    m_strings[1389] = "s_word_customize_location";
    m_strings[1390] = "s_word_customize_angle";
    m_strings[1391] = "s_word_customize_change";
    m_strings[1392] = "s_word_customize_no_edit";
    m_strings[1393] = "s_word_customize_comma";
    m_strings[1394] = "s_word_game_over";
    m_strings[1395] = "s_word_unknown";
    m_strings[1396] = "s_word_welcome";
    m_strings[1397] = "s_word_item_damage";
    m_strings[1398] = "s_word_unuse";
    m_strings[1399] = "s_word_screenshot";
    m_strings[1400] = "s_cannot_move_to_npc";
    m_strings[1401] = "s_word_ch";
    m_strings[1402] = "s_word_online";
    m_strings[1403] = "s_word_offline";
    m_strings[1404] = "s_word_dungeon";
    m_strings[1405] = "s_word_newTab";
    m_strings[1406] = "s_word_level";
    m_strings[1407] = "s_word_level_max";
    m_strings[1408] = "s_word_learn_level";
    m_strings[1409] = "s_word_learn_skillbook";
    m_strings[1410] = "s_word_acquire_level";
    m_strings[1411] = "s_word_cooltime";
    m_strings[1412] = "s_word_needs";
    m_strings[1413] = "s_word_fitness";
    m_strings[1414] = "s_word_disable_job";
    m_strings[1415] = "s_word_sellprice";
    m_strings[1416] = "s_word_sellremind_format";
    m_strings[1417] = "s_word_require_level";
    m_strings[1418] = "s_word_equiped";
    m_strings[1419] = "s_word_skillbook";
    m_strings[1420] = "s_word_designed";
    m_strings[1421] = "s_word_indoor_area";
    m_strings[1422] = "s_word_indoor_only";
    m_strings[1424] = "s_word_outdoor_indoor";
    m_strings[1423] = "s_word_outdoor_only";
    m_strings[1425] = "s_word_stackable";
    m_strings[1426] = "s_word_do_not_stack";
    m_strings[1427] = "s_word_cash";
    m_strings[1428] = "s_word_skin";
    m_strings[1429] = "s_word_count";
    m_strings[1430] = "s_word_magic";
    m_strings[1431] = "s_word_nearrange";
    m_strings[1432] = "s_word_longrange";
    m_strings[1433] = "s_word_taxistation";
    m_strings[1434] = "s_word_besttaxistation";
    m_strings[1435] = "s_word_telescope";
    m_strings[1436] = "s_word_myhome";
    m_strings[1437] = "s_word_myhome_property";
    m_strings[1438] = "s_word_minimap_alpha";
    m_strings[1439] = "s_word_mapbg_alpha";
    m_strings[1440] = "s_word_exit_yes";
    m_strings[1441] = "s_word_exit_no";
    m_strings[1442] = "s_word_item";
    m_strings[1443] = "s_word_trade";
    m_strings[1444] = "s_word_cashshop";
    m_strings[1445] = "s_word_blackmarket";
    m_strings[1446] = "s_word_mesomarket";
    m_strings[1447] = "s_word_meratmarket";
    m_strings[1448] = "s_word_ugc";
    m_strings[1449] = "s_word_ugc_banner";
    m_strings[1450] = "s_word_homepage";
    m_strings[1451] = "s_word_sunday";
    m_strings[1452] = "s_word_monday";
    m_strings[1453] = "s_word_tuesday";
    m_strings[1454] = "s_word_wednesday";
    m_strings[1455] = "s_word_thursday";
    m_strings[1456] = "s_word_friday";
    m_strings[1457] = "s_word_saturday";
    m_strings[1458] = "s_word_chatting";
    m_strings[1459] = "s_word_mail";
    m_strings[1460] = "s_word_smart_push";
    m_strings[1461] = "s_word_fishing";
    m_strings[1462] = "s_word_safe_riding";
    m_strings[1463] = "s_word_amphibious";
    m_strings[1464] = "s_word_auto_play_instrument";
    m_strings[1465] = "s_word_auto_mining";
    m_strings[1466] = "s_word_auto_gathering";
    m_strings[1467] = "s_word_auto_breeding";
    m_strings[1468] = "s_word_auto_farming";
    m_strings[1470] = "s_word_revival";
    m_strings[1471] = "s_word_quest";
    m_strings[1472] = "s_word_skill";
    m_strings[1473] = "s_word_skill_active";
    m_strings[1474] = "s_word_skill_passive";
    m_strings[1475] = "s_word_element_physics";
    m_strings[1476] = "s_word_element_fire";
    m_strings[1477] = "s_word_element_ice";
    m_strings[1478] = "s_word_element_lightning";
    m_strings[1479] = "s_word_element_holy";
    m_strings[1480] = "s_word_element_darkness";
    m_strings[1481] = "s_word_element_poison";
    m_strings[1482] = "s_word_min";
    m_strings[1484] = "s_word_hour";
    m_strings[1485] = "s_word_hour2";
    m_strings[1483] = "s_word_sec";
    m_strings[1486] = "s_word_day";
    m_strings[1487] = "s_word_remain";
    m_strings[1488] = "s_word_group";
    m_strings[1489] = "s_word_newgroup";
    m_strings[1490] = "s_quest_chapter";
    m_strings[1491] = "s_quest_talk_accept";
    m_strings[1492] = "s_quest_talk_complete";
    m_strings[1493] = "s_quest_talk_progress";
    m_strings[1494] = "s_quest_talk_end";
    m_strings[1495] = "s_quest_talk_reward_title";
    m_strings[1496] = "s_quest_state_init";
    m_strings[1497] = "s_quest_state_beginAble";
    m_strings[1498] = "s_quest_state_progress";
    m_strings[1499] = "s_quest_state_completeAble";
    m_strings[1500] = "s_quest_state_complete";
    m_strings[1501] = "s_quest_main_quest";
    m_strings[1502] = "s_quest_sub_quest";
    m_strings[1503] = "s_quest_event_quest";
    m_strings[1504] = "s_quest_repeat_infinite";
    m_strings[1505] = "s_quest_repeat_daily";
    m_strings[1506] = "s_quest_replace_npc";
    m_strings[1507] = "s_quest_replace_talk";
    m_strings[1508] = "s_quest_replace_quest_object";
    m_strings[1509] = "s_quest_replace_field";
    m_strings[1510] = "s_quest_replace_item";
    m_strings[1511] = "s_quest_replace_satisfied";
    m_strings[1512] = "s_mission_replace_npc_meso";
    m_strings[1513] = "s_quest_replace_item_move";
    m_strings[1514] = "s_quest_not_selected_reward";
    m_strings[1515] = "s_quest_boss_notify";
    m_strings[1516] = "s_quest_boss_notify_chat";
    m_strings[1517] = "s_quest_boss_notify_quest";
    m_strings[1518] = "s_quest_error_inventory_full";
    m_strings[1519] = "s_quest_error_consume_fail";
    m_strings[1520] = "s_quest_error_accept_fail";
    m_strings[1521] = "s_quest_error_count_limit";
    m_strings[1522] = "s_quest_error_invalid_date";
    m_strings[1523] = "s_quest_scroll_progress_quest";
    m_strings[1524] = "s_quest_scroll_invalid_begin_quest";
    m_strings[1525] = "s_quest_scroll_inventory_full";
    m_strings[1526] = "s_quest_scroll_use_item";
    m_strings[1527] = "s_title_scroll_duplicate_err";
    m_strings[1528] = "s_buddy_confirm_del_somebody_from_list";
    m_strings[1529] = "s_buddy_confirm_del_somebody_from_banlist";
    m_strings[1530] = "s_buddy_confirm_del_somebody_from_homeblocklist";
    m_strings[1531] = "s_buddy_confirm_ban_somebody";
    m_strings[1532] = "s_buddy_confirm_homeblock_somebody";
    m_strings[1533] = "s_buddy_add_somebody";
    m_strings[1534] = "s_buddy_ban_somebody";
    m_strings[1535] = "s_buddy_ban_memo_complete";
    m_strings[1536] = "s_buddy_request_to_somebody";
    m_strings[1537] = "s_buddy_decline_request_from_somebody";
    m_strings[1538] = "s_buddy_refused_request_from_somebody";
    m_strings[1539] = "s_buddy_cancel_request_from_somebody";
    m_strings[1540] = "s_buddy_cancel_request";
    m_strings[1541] = "s_buddy_del_somebody_from_list";
    m_strings[1542] = "s_buddy_del_somebody_from_banlist";
    m_strings[1543] = "s_buddy_alert_receive_request";
    m_strings[1544] = "s_buddy_alert_online_somebody";
    m_strings[1545] = "s_buddy_alert_offline_somebody";
    m_strings[1546] = "s_buddy_request_default_msg";
    m_strings[1547] = "s_buddy_waiting";
    m_strings[1548] = "s_buddy_format_ch_map";
    m_strings[1549] = "s_buddy_format_offline";
    m_strings[1550] = "s_buddy_format_mapuser_count";
    m_strings[1551] = "s_buddy_format_recv_count";
    m_strings[1552] = "s_buddy_format_ban_count";
    m_strings[1553] = "s_buddy_format_homeblock_count";
    m_strings[1554] = "s_buddy_format_buddy_count";
    m_strings[1555] = "s_buddy_err_unknown";
    m_strings[1556] = "s_buddy_err_miss_id";
    m_strings[1557] = "s_buddy_err_empty_id";
    m_strings[1558] = "s_buddy_err_my_id";
    m_strings[1559] = "s_buddy_err_my_id_ex";
    m_strings[1560] = "s_buddy_err_not_exist_id";
    m_strings[1561] = "s_buddy_err_ban_buddy_add";
    m_strings[1562] = "s_buddy_err_already_receive";
    m_strings[1563] = "s_buddy_err_max_block";
    m_strings[1564] = "s_buddy_err_request_somebody";
    m_strings[1565] = "s_buddy_err_max_buddy";
    m_strings[1566] = "s_buddy_err_target_full";
    m_strings[1567] = "s_buddy_err_already_request";
    m_strings[1568] = "s_buddy_err_already_ban";
    m_strings[1569] = "s_buddy_err_already_buddy";
    m_strings[1570] = "s_buddy_err_already_request_somebody";
    m_strings[1571] = "s_buddy_err_already_receive_from_this_char";
    m_strings[1572] = "s_format_meso";
    m_strings[1573] = "s_format_exp";
    m_strings[1574] = "s_format_item";
    m_strings[1575] = "s_format_reward_exp";
    m_strings[1576] = "s_format_reward_meso";
    m_strings[1577] = "s_msg_worldmap_title";
    m_strings[1578] = "s_change_ch_err_field";
    m_strings[1579] = "s_change_ch_err_battle";
    m_strings[1580] = "s_change_ch_err_dead";
    m_strings[1581] = "s_action_talk_normal";
    m_strings[1582] = "s_action_talk_normal_cinematic";
    m_strings[1583] = "s_action_talk_shop";
    m_strings[1584] = "s_action_talk_store";
    m_strings[1585] = "s_action_talk_mail";
    m_strings[1586] = "s_action_enter_cube";
    m_strings[1587] = "s_action_portal";
    m_strings[1588] = "s_action_interact";
    m_strings[1589] = "s_action_buy_site";
    m_strings[1590] = "s_action_sell_cube";
    m_strings[1591] = "s_action_regist_ugc";
    m_strings[1592] = "s_action_construct";
    m_strings[1593] = "s_action_changejob";
    m_strings[1594] = "s_action_lift_cube";
    m_strings[1595] = "s_action_ride";
    m_strings[1596] = "s_action_pull";
    m_strings[1597] = "s_action_putdown_liftable";
    m_strings[1598] = "s_action_switchcube";
    m_strings[1599] = "s_action_breedingcube";
    m_strings[1600] = "s_action_farmingcube";
    m_strings[1601] = "s_action_harvest";
    m_strings[1602] = "s_action_harvesting";
    m_strings[1603] = "s_action_remain_time";
    m_strings[1604] = "s_action_breeding_growing";
    m_strings[1605] = "s_action_farming_growing";
    m_strings[1606] = "s_action_fittingdoll";
    m_strings[1607] = "s_action_use_telescope";
    m_strings[1608] = "s_action_view_cube_profile";
    m_strings[1609] = "s_action_owner";
    m_strings[1610] = "s_action_taxi_call";
    m_strings[1611] = "s_action_taxi_call_progress";
    m_strings[1612] = "s_action_cash_taxi_call_progress";
    m_strings[1613] = "s_action_regist_banner";
    m_strings[1614] = "s_action_fusion";
    m_strings[1615] = "s_action_summon_pet";
    m_strings[1616] = "s_action_summon_ridee";
    m_strings[1617] = "s_action_goto_home";
    m_strings[1618] = "s_action_hold";
    m_strings[1619] = "s_action_hold_end";
    m_strings[1620] = "s_action_cant_pet";
    m_strings[1621] = "s_action_cant_ride";
    m_strings[1622] = "s_action_privilege_portal";
    m_strings[1623] = "s_action_recall_otheruser";
    m_strings[1624] = "s_action_fishing";
    m_strings[1625] = "s_action_fishing_try";
    m_strings[1626] = "s_action_bank_call_progress";
    m_strings[1631] = "s_action_homebank_call_progress";
    m_strings[1627] = "s_action_webopen";
    m_strings[1628] = "s_action_banner";
    m_strings[1629] = "s_action_banner_rps";
    m_strings[1630] = "s_action_reactor";
    m_strings[1632] = "s_err_homebank_cannot_now";
    m_strings[1633] = "s_err_homebank_cannot_now_place";
    m_strings[1634] = "s_err_homebank_cannot_now_already";
    m_strings[1635] = "s_action_homedoctor_call_progress";
    m_strings[1636] = "s_err_homedoctor_cannot_now";
    m_strings[1637] = "s_err_homedoctor_cannot_now_place";
    m_strings[1638] = "s_cutscene_telescope_keycap";
    m_strings[1639] = "s_cutscene_telescope_keydesc";
    m_strings[1640] = "s_changejob_accept";
    m_strings[1641] = "s_take_boat_accept";
    m_strings[1642] = "s_resolve_panelty_accept";
    m_strings[1643] = "s_sell_ugc_map_accept";
    m_strings[1644] = "s_roulette_accept";
    m_strings[1645] = "s_roulette_talk_skip";
    m_strings[1646] = "s_html_chat_super";
    m_strings[1647] = "s_html_chat_world";
    m_strings[1648] = "s_html_chat_channel";
    m_strings[1649] = "s_html_chat_normal";
    m_strings[1651] = "s_html_chat_guild";
    m_strings[1650] = "s_html_chat_party";
    m_strings[1652] = "s_html_chat_whisper_to";
    m_strings[1653] = "s_html_chat_whisper_from";
    m_strings[1654] = "s_html_chat_notice";
    m_strings[1655] = "s_html_chat_img_notice";
    m_strings[1656] = "s_html_chat_linkable_title";
    m_strings[1657] = "s_html_chat_system_notice";
    m_strings[1658] = "s_html_chat_club";
    m_strings[1659] = "s_html_chat_ugc_event";
    m_strings[1660] = "s_html_chat_super_custom";
    m_strings[1661] = "s_html_chat_guild_mega_phone";
    m_strings[1662] = "s_html_chat_system";
    m_strings[1663] = "s_html_chat_wedding";
    m_strings[1664] = "s_html_chat_wedding_custom";
    m_strings[1665] = "s_system_quest_reward_exp";
    m_strings[1666] = "s_system_quest_reward_exp_with_hottimebonus";
    m_strings[1667] = "s_system_quest_reward_meso";
    m_strings[1668] = "s_system_quest_reward_meso_with_hottimebonus";
    m_strings[1669] = "s_system_quest_reward_merat";
    m_strings[1673] = "s_system_achieve_reward_title";
    m_strings[1674] = "s_system_achieve_reward_field_enterance";
    m_strings[1675] = "s_system_achieve_reward_shop_unlock";
    m_strings[1676] = "s_system_achieve_reward_honor";
    m_strings[1677] = "s_system_achieve_reward_karma";
    m_strings[1678] = "s_system_achieve_reward_lu";
    m_strings[1679] = "s_system_achieve_reward_habi";
    m_strings[1670] = "s_system_quest_condition";
    m_strings[1671] = "s_system_get_item";
    m_strings[1672] = "s_system_property_protection_time";
    m_strings[1680] = "s_html_quest_reward";
    m_strings[1681] = "s_ugcmap_ok";
    m_strings[1682] = "s_ugcmap_create_on_non_empty_area";
    m_strings[1683] = "s_ugcmap_not_exist_craft_item";
    m_strings[1684] = "s_ugcmap_not_owned_item";
    m_strings[1685] = "s_ugcmap_cant_be_created";
    m_strings[1686] = "s_ugcmap_cant_create_on_place";
    m_strings[1687] = "s_ugcmap_no_base_cube";
    m_strings[1688] = "s_ugcmap_dont_have_ownership";
    m_strings[1689] = "s_ugcmap_cant_create_ground_on_ground";
    m_strings[1690] = "s_ugcmap_cant_create_on_ground";
    m_strings[1691] = "s_ugcmap_only_be_created_on_ground";
    m_strings[1692] = "s_ugcmap_cant_stack_on";
    m_strings[1693] = "s_ugcmap_db";
    m_strings[1694] = "s_ugcmap_center";
    m_strings[1695] = "s_ugcmap_no_wall_to_attach";
    m_strings[1696] = "s_ugcmap_not_wall_attachable";
    m_strings[1697] = "s_ugcmap_only_be_created_on_wall";
    m_strings[1698] = "s_ugcmap_cant_attached_to_this_wall";
    m_strings[1699] = "s_ugcmap_have_already_attached";
    m_strings[1700] = "s_ugcmap_no_cube_to_remove";
    m_strings[1701] = "s_ugcmap_cant_be_removed";
    m_strings[1702] = "s_ugcmap_cant_remove_before_remove_all_stacked";
    m_strings[1703] = "s_ugcmap_cant_remove_building_with_indoor_items";
    m_strings[1704] = "s_ugcmap_can_be_remove_from_wall";
    m_strings[1705] = "s_ugcmap_no_attached_object";
    m_strings[1706] = "s_ugcmap_no_cube_to_rotate";
    m_strings[1707] = "s_ugcmap_cant_rotate_default_cube";
    m_strings[1708] = "s_ugcmap_no_cube_to_replace";
    m_strings[1709] = "s_ugcmap_cant_be_replaced";
    m_strings[1710] = "s_ugcmap_attached_cube_exist";
    m_strings[1711] = "s_ugcmap_cant_replace_stackable_with_not_stackable";
    m_strings[1712] = "s_ugcmap_not_a_buyable";
    m_strings[1713] = "s_ugcmap_not_enough_money";
    m_strings[1714] = "s_ugcmap_already_owned";
    m_strings[1715] = "s_ugcmap_salable";
    m_strings[1716] = "s_ugcmap_no_cube_to_lift";
    m_strings[1717] = "s_ugcmap_cant_lift_ugc_cube";
    m_strings[1718] = "s_ugcmap_cant_lift_salable";
    m_strings[1719] = "s_ugcmap_cant_remove_default_cube";
    m_strings[1720] = "s_ugcmap_cant_remove_cube_with_attached";
    m_strings[1721] = "s_ugcmap_null_cube_item_info";
    m_strings[1722] = "s_ugcmap_height_limit";
    m_strings[1723] = "s_ugcmap_area_limit";
    m_strings[1724] = "s_ugcmap_building_count";
    m_strings[1725] = "s_ugcmap_not_for_sale";
    m_strings[1726] = "s_ugcmap_no_more_room";
    m_strings[1727] = "s_ugcmap_no_home";
    m_strings[1728] = "s_ugcmap_my_house";
    m_strings[1729] = "s_ugcmap_already_expired";
    m_strings[1730] = "s_ugcmap_system_error";
    m_strings[1731] = "s_ugcmap_have_equipitems";
    m_strings[1732] = "s_ugcmap_cant_replace_same_cube";
    m_strings[1733] = "s_ugcmap_cant_buy_more_than_two_house";
    m_strings[1734] = "s_ugcmap_need_trophy";
    m_strings[1736] = "s_ugcmap_wall_direction_error";
    m_strings[1741] = "s_ugcmap_cant_create_under_attach";
    m_strings[1742] = "s_ugcmap_cant_attach_upper_cube";
    m_strings[1743] = "s_ugcmap_cant_replace_under_attach";
    m_strings[1744] = "s_ugcmap_cant_place_maid";
    m_strings[1745] = "s_ugcmap_only_place_on_the_floor";
    m_strings[1746] = "s_ugcmap_not_extension_date";
    m_strings[1747] = "s_ugcmap_need_extansion_pay";
    m_strings[1748] = "s_ugcmap_expired_salable_group";
    m_strings[1749] = "s_ugcmap_cant_sell_my_home_in_indoor";
    m_strings[1750] = "s_ugcmap_blocked_salable_group";
    m_strings[1751] = "s_ugcmap_retry_later";
    m_strings[1752] = "s_ugcmap_waiting_for_cube_to_be_created";
    m_strings[1753] = "s_ugcmap_waiting_for_cube_to_be_replaced";
    m_strings[1754] = "s_ugcmap_waiting_for_cube_to_be_removed";
    m_strings[1755] = "s_ugcmap_trigger_count";
    m_strings[1756] = "s_ugcmap_no_owner_to_commend";
    m_strings[1757] = "s_ugcmap_add_commend_home_fail_from_db";
    m_strings[1758] = "s_ugcmap_cant_commend_myself";
    m_strings[1759] = "s_ugcmap_cant_commend_duplicate";
    m_strings[1760] = "s_ugcmap_ban_word_included";
    m_strings[1761] = "s_ugcmap_not_my_house";
    m_strings[1762] = "s_ugcmap_automatic_removal";
    m_strings[1763] = "s_ugcmap_cant_take_interior_gift_more";
    m_strings[1764] = "s_ugcmap_take_interior_gift_fail_from_db";
    m_strings[1765] = "s_ugcmap_already_taken_interior_grade_gift";
    m_strings[1766] = "s_ugcmap_area_level_extended_successfully";
    m_strings[1767] = "s_ugcmap_height_level_extended_successfully";
    m_strings[1768] = "s_ugcmap_area_level_shrink_successfully";
    m_strings[1769] = "s_ugcmap_height_level_shrink_successfully";
    m_strings[1770] = "s_ugcmap_not_use_blueprint_item";
    m_strings[1771] = "s_ugc_edit_homeless";
    m_strings[1772] = "s_ugc_edit_different_indoorsize";
    m_strings[1773] = "s_ugcmap_package_name";
    m_strings[1774] = "s_ugcmap_package_description";
    m_strings[1775] = "s_ugcmap_package_build_condition";
    m_strings[1776] = "s_ugcmap_package_build_description";
    m_strings[1737] = "s_ugcmap_lift_error_msg";
    m_strings[1738] = "s_ugcmap_try_place_empty";
    m_strings[1739] = "s_ugcmap_cant_replace_type";
    m_strings[1740] = "s_ugcmap_cant_rotate_attached";
    m_strings[1777] = "s_ugcmap_buy_realestate";
    m_strings[1778] = "s_ugcmap_sell_realestate";
    m_strings[1779] = "s_ugcmap_use_sale_coupon_to_buy";
    m_strings[1780] = "s_construct_up_limit";
    m_strings[1781] = "s_construct_down_limit";
    m_strings[1782] = "s_construct_only_indoor";
    m_strings[1783] = "s_construct_only_outdoor";
    m_strings[1784] = "s_construct_category";
    m_strings[1785] = "s_construct_buy_price";
    m_strings[1786] = "s_construct_require_interior_level";
    m_strings[1787] = "s_construct_require_trophy";
    m_strings[1788] = "s_construct_usecount_and_hascount";
    m_strings[1789] = "s_construct_usecount_and_hascount_arg";
    m_strings[1790] = "s_housing_point_interior_level";
    m_strings[1735] = "s_ugcmap_cant_guide_build";
    m_strings[1791] = "s_tip_whisper";
    m_strings[1792] = "s_mainplayinfo_build_count";
    m_strings[1793] = "s_mainplayinfo_maid_count";
    m_strings[1794] = "s_mainplayinfo_trigger_count";
    m_strings[1795] = "s_warehouse_timeleft_day_normal";
    m_strings[1796] = "s_warehouse_timeleft_day_red";
    m_strings[1797] = "s_warehouse_timeleft_hour_red";
    m_strings[1798] = "s_warehouse_timeleft_minute_red";
    m_strings[1799] = "s_warehouse_timeleft_second_red";
    m_strings[1800] = "s_warehouse_timeleft_timeover_red";
    m_strings[1801] = "s_warehouse_accept";
    m_strings[1802] = "s_warehouse_send_to_mail_sender";
    m_strings[1803] = "s_warehouse_send_to_mail_title";
    m_strings[1804] = "s_warehouse_send_to_mail_content";
    m_strings[1805] = "s_worldmap_tooltip_channel";
    m_strings[1806] = "s_worldmap_tooltip_myname";
    m_strings[1807] = "s_worldmap_tooltip_myhome";
    m_strings[1808] = "s_worldmap_tooltip_friend";
    m_strings[1809] = "s_worldmap_tooltip_friendhome";
    m_strings[1810] = "s_worldmap_tooltip_party";
    m_strings[1811] = "s_worldmap_tooltip_level";
    m_strings[1812] = "s_worldmap_tooltip_level_upper";
    m_strings[1813] = "s_worldmap_tooltip_mapname";
    m_strings[1814] = "s_worldmap_tooltip_mapname_low";
    m_strings[1815] = "s_worldmap_tooltip_mapname_high";
    m_strings[1816] = "s_worldmap_tooltip_fishingspot_low";
    m_strings[1817] = "s_worldmap_tooltip_fishingspot_high";
    m_strings[1818] = "s_worldmap_tooltip_boss";
    m_strings[1819] = "s_worldmap_tooltip_channel_enabled";
    m_strings[1820] = "s_worldmap_tooltip_channel_disabled";
    m_strings[1821] = "s_worldmap_tooltip_channel_extra";
    m_strings[1822] = "s_worldmap_tooltip_portal";
    m_strings[1823] = "s_worldmap_tooltip_portal_time";
    m_strings[1824] = "s_worldmap_tooltip_quest_completable";
    m_strings[1825] = "s_worldmap_tooltip_quest_progress";
    m_strings[1826] = "s_worldmap_tooltip_quest_ablenow";
    m_strings[1827] = "s_worldmap_tooltip_quest_ableupper";
    m_strings[1828] = "s_worldmap_tooltip_taxi_title";
    m_strings[1829] = "s_worldmap_tooltip_taxi_price";
    m_strings[1830] = "s_worldmap_tooltip_taxi_seal";
    m_strings[1831] = "s_worldmap_tooltip_taxi_current";
    m_strings[1832] = "s_worldmap_tooltip_taxi_other_continent";
    m_strings[1833] = "s_worldmap_tooltip_open_now";
    m_strings[1834] = "s_worldmap_tooltip_quest_epic";
    m_strings[1835] = "s_worldmap_tooltip_quest_world";
    m_strings[1836] = "s_worldmap_tooltip_shadowgate";
    m_strings[1837] = "s_worldmap_dungeon_rank_level_proper";
    m_strings[1838] = "s_worldmap_dungeon_rank_level_upper";
    m_strings[1839] = "s_worldmap_dungeon_expire_date";
    m_strings[1840] = "s_minimap_icon_quest_completable_epic";
    m_strings[1841] = "s_minimap_icon_quest_completable_event";
    m_strings[1842] = "s_minimap_icon_quest_completable_world";
    m_strings[1843] = "s_minimap_icon_quest_completable_repeat";
    m_strings[1844] = "s_minimap_icon_quest_ablenow_epic";
    m_strings[1845] = "s_minimap_icon_quest_ablenow_event";
    m_strings[1846] = "s_minimap_icon_quest_ablenow_world";
    m_strings[1847] = "s_minimap_icon_quest_ablenow_repeat";
    m_strings[1848] = "s_minimap_icon_quest_progress";
    m_strings[1849] = "s_minimap_icon_quest_ableupper";
    m_strings[1850] = "s_minimap_tooltip_function_npc";
    m_strings[1851] = "s_minimap_tooltip_function_npc_1row";
    m_strings[1852] = "s_minimap_tooltip_function_portal";
    m_strings[1853] = "s_minimap_tooltip_portal";
    m_strings[1854] = "s_minimap_tooltip_normal";
    m_strings[1855] = "s_minimap_tooltip_normal_alignleft";
    m_strings[1856] = "s_minimap_tooltip_quest_completable";
    m_strings[1857] = "s_minimap_tooltip_quest_progress";
    m_strings[1858] = "s_minimap_tooltip_quest_ablenow";
    m_strings[1859] = "s_minimap_tooltip_quest_ableupper";
    m_strings[1860] = "s_triggereditor_state_change";
    m_strings[1861] = "s_triggereditor_delete_state_invalid";
    m_strings[1862] = "s_triggereditor_delete_state_confirm";
    m_strings[1863] = "s_triggereditor_modifiy_state_invalid";
    m_strings[1864] = "s_triggereditor_delete_attribute";
    m_strings[1865] = "s_triggereditor_modelsize_too_long";
    m_strings[1866] = "s_triggereditor_modify_attribute_invalid";
    m_strings[1867] = "s_triggereditor_new_trigger";
    m_strings[1868] = "s_triggereditor_exit_trigger";
    m_strings[1869] = "s_triggereditor_upload";
    m_strings[1870] = "s_triggereditor_download";
    m_strings[1871] = "s_msg_rclick_attach_trade";
    m_strings[1872] = "s_msg_rclick_dettach_trade";
    m_strings[1873] = "s_msg_rclick_puton_equip";
    m_strings[1874] = "s_msg_rclick_putoff_equip";
    m_strings[1875] = "s_msg_rclick_store_in";
    m_strings[1876] = "s_msg_rclick_store_out";
    m_strings[1877] = "s_msg_rclick_sell";
    m_strings[1878] = "s_msg_rclick_attach_mail";
    m_strings[1879] = "s_msg_rclick_dettach_mail";
    m_strings[1880] = "s_msg_rclick_buy";
    m_strings[1881] = "s_msg_rclick_putoff_qslot";
    m_strings[1882] = "s_msg_rclick_puton_qslot";
    m_strings[1883] = "s_msg_rclick_puton_doll";
    m_strings[1884] = "s_msg_rclick_putoff_doll";
    m_strings[1885] = "s_msg_rclick_upgrade";
    m_strings[1886] = "s_msg_rclick_warehouse_out";
    m_strings[1887] = "s_msg_rclick_item_break";
    m_strings[1888] = "s_msg_rclick_blackmarket";
    m_strings[1889] = "s_msg_rclick_play_instrument";
    m_strings[1890] = "s_msg_dclick_usable";
    m_strings[1891] = "s_msg_dclick_readable";
    m_strings[1892] = "s_msg_lclick_usable";
    m_strings[1893] = "s_msg_tooltip_compare_swap";
    m_strings[1894] = "s_fusion_error";
    m_strings[1895] = "s_record_error";
    m_strings[1896] = "s_record_audio_error";
    m_strings[1897] = "s_tooltip_exp";
    m_strings[1898] = "s_tooltip_todayword";
    m_strings[1899] = "s_tooltip_party_ch";
    m_strings[1900] = "s_tooltip_party";
    m_strings[1901] = "s_achieve_adventure";
    m_strings[1902] = "s_achieve_combat";
    m_strings[1903] = "s_achieve_life";
    m_strings[1904] = "s_achieve_reward_item";
    m_strings[1905] = "s_achieve_reward_meso";
    m_strings[1906] = "s_achieve_reward_exp";
    m_strings[1907] = "s_achieve_reward_function";
    m_strings[1908] = "s_achieve_reward_title";
    m_strings[1909] = "s_achieve_reward_merat";
    m_strings[1910] = "s_achieve_reward_field_enterance";
    m_strings[1911] = "s_achieve_reward_item_buy_auth";
    m_strings[1912] = "s_achieve_meter";
    m_strings[1913] = "s_achieve_killometer";
    m_strings[1914] = "s_achieve_killometer_f";
    m_strings[1915] = "s_achieve_get_achieve_daily";
    m_strings[1917] = "s_achieve_get_achieve_hero_complete";
    m_strings[1916] = "s_achieve_get_achieve_hero_progress";
    m_strings[1918] = "s_achieve_grade";
    m_strings[1919] = "s_achieve_state_progress";
    m_strings[1920] = "s_achieve_state_complete";
    m_strings[1921] = "s_achieve_tooltip_comment";
    m_strings[1922] = "s_achieve_reset_account";
    m_strings[1923] = "s_achieve_reset_char";
    m_strings[1924] = "s_achieve_category_reward_count";
    m_strings[1925] = "s_maid_change_maid_name";
    m_strings[1926] = "s_maid_change_owner_name";
    m_strings[1927] = "s_maid_default_owner_name";
    m_strings[1928] = "s_maid_label_birth";
    m_strings[1929] = "s_maid_label_constel";
    m_strings[1930] = "s_maid_label_height";
    m_strings[1931] = "s_maid_label_weight";
    m_strings[1932] = "s_maid_label_like";
    m_strings[1933] = "s_maid_label_hate";
    m_strings[1934] = "s_maid_label_hobby";
    m_strings[1935] = "s_maid_label_ownername";
    m_strings[1936] = "s_maid_label_belongto";
    m_strings[1937] = "s_maid_label_name";
    m_strings[1938] = "s_maid_label_title";
    m_strings[1939] = "s_maid_label_salary";
    m_strings[1940] = "s_maid_need_salary";
    m_strings[1941] = "s_maid_expire_date";
    m_strings[1942] = "s_maid_expire_date_morning";
    m_strings[1943] = "s_maid_expire_date_afternoon";
    m_strings[1944] = "s_maid_expire_date_reserved_word";
    m_strings[1945] = "s_maid_extend_date_reserved_word";
    m_strings[1946] = "s_maid_affinity_gauge_level";
    m_strings[1947] = "s_maid_affinity_gauge_level_max";
    m_strings[1948] = "s_maid_affinity_gauge_affinity";
    m_strings[1949] = "s_maid_affinity_gauge_affinity_max";
    m_strings[1950] = "s_maid_edit_confirm";
    m_strings[1951] = "s_maid_feel_normal";
    m_strings[1952] = "s_maid_feel_good";
    m_strings[1953] = "s_maid_feel_very_good";
    m_strings[1954] = "s_maid_tooltip_maid_desc";
    m_strings[1955] = "s_maid_tooltip_manufactured";
    m_strings[1956] = "s_maid_tooltip_manufacturing";
    m_strings[1957] = "s_maid_reserved_word_passed_days";
    m_strings[1958] = "s_maid_reserved_word_pay_type_meso";
    m_strings[1959] = "s_maid_reserved_word_pay_type_merat";
    m_strings[1960] = "s_maid_recipe_item_option";
    m_strings[1961] = "s_maid_recipe_item_option_range";
    m_strings[1962] = "s_manufacture_require";
    m_strings[1963] = "s_manufacture_require_over_max";
    m_strings[1964] = "s_manufacture_detail";
    m_strings[1965] = "s_manufacture_ingredient_count_satisfied";
    m_strings[1966] = "s_manufacture_ingredient_count_need";
    m_strings[1967] = "s_manufacture_title_specialty";
    m_strings[1968] = "s_manufacture_title_status";
    m_strings[1969] = "s_manufacture_title_status_tooltip";
    m_strings[1970] = "s_manufacture_title_status_tooltip_max";
    m_strings[1971] = "s_manufacture_progress_hour";
    m_strings[1972] = "s_manufacture_progress_min";
    m_strings[1973] = "s_manufacture_progress_sec";
    m_strings[1974] = "s_manufacture_progress_left";
    m_strings[1975] = "s_manufacture_cancel_confirm";
    m_strings[1976] = "s_manufacture_complete";
    m_strings[1977] = "s_manufacture_complete_jackpot";
    m_strings[1978] = "s_manufacture_complete_by_merat";
    m_strings[1979] = "s_manufacture_workbench_tooltip_cook_on";
    m_strings[1980] = "s_manufacture_workbench_tooltip_cook_off";
    m_strings[1981] = "s_manufacture_workbench_tooltip_alchemy_on";
    m_strings[1982] = "s_manufacture_workbench_tooltip_alchemy_off";
    m_strings[1983] = "s_manufacture_workbench_tooltip_biz_on";
    m_strings[1984] = "s_manufacture_workbench_tooltip_biz_off";
    m_strings[1985] = "s_manufacture_cinematic_title";
    m_strings[1986] = "s_manufacture_cinematic_affinity";
    m_strings[1987] = "s_manufacture_cinematic_affinity_grade_up";
    m_strings[1988] = "s_manufacture_cinematic_mood_plus";
    m_strings[1989] = "s_manufacture_cinematic_mood_minus";
    m_strings[1990] = "s_manufacture_error_msg";
    m_strings[1991] = "s_maid_recipe_list_title";
    m_strings[1992] = "s_reveal_taxi_station";
    m_strings[1993] = "s_interact_err_item";
    m_strings[1994] = "s_function_reward_itemget";
    m_strings[1995] = "s_cinematic_job_change";
    m_strings[1996] = "s_interact_err_quest";
    m_strings[1997] = "s_realestate_ask_contract";
    m_strings[1998] = "s_realestate_expire_data";
    m_strings[1999] = "s_realestate_extension_date";
    m_strings[2000] = "s_realestate_ask_extention_merat";
    m_strings[2001] = "s_realestate_ask_extention_meso";
    m_strings[2002] = "s_realestate_ask_extention_item";
    m_strings[2003] = "s_realestate_building_type_0";
    m_strings[2004] = "s_realestate_building_type_1";
    m_strings[2005] = "s_realestate_building_type_2";
    m_strings[2006] = "s_realestate_building_type_3";
    m_strings[2007] = "s_realestate_area";
    m_strings[2008] = "s_realestate_install_building_count";
    m_strings[2045] = "s_achieve_reward_tab";
    m_strings[2046] = "s_achieve_reward_tab_great";
    m_strings[2047] = "s_achieve_renderer_count";
    m_strings[2048] = "s_achieve_renderer_count_time";
    m_strings[2049] = "s_achieve_renderer_hour";
    m_strings[2050] = "s_achieve_renderer_min";
    m_strings[2051] = "s_notify_levelup";
    m_strings[2052] = "s_notify_learn_skill";
    m_strings[2053] = "s_notify_mail_reply";
    m_strings[2054] = "s_notify_mail_reply_content";
    m_strings[2055] = "s_notify_mail_remainDay";
    m_strings[2056] = "s_notify_mail_remainDay_tooltip";
    m_strings[2057] = "s_notify_mail_remainDay_today";
    m_strings[2058] = "s_notify_mail_remainDay_tooltip_today";
    m_strings[2059] = "s_notify_mail_remainDay_expire";
    m_strings[2060] = "s_notify_achieve_reward_function";
    m_strings[2061] = "s_notify_achieve_reward_deadfail";
    m_strings[2062] = "s_notify_groupchat_invite";
    m_strings[2063] = "s_notify_groupchat_invited";
    m_strings[2064] = "s_notify_groupchat_leave";
    m_strings[2065] = "s_notify_groupchat_login";
    m_strings[2066] = "s_notify_groupchat_logout";
    m_strings[2067] = "s_notify_groupchat_reject";
    m_strings[2068] = "s_err_groupchat_maxjoin";
    m_strings[2069] = "s_err_groupchat_null_target_user";
    m_strings[2070] = "s_err_groupchat_join_exist";
    m_strings[2071] = "s_err_groupchat_name_exist";
    m_strings[2072] = "s_err_groupchat_maxgroup";
    m_strings[2073] = "s_err_groupchat_add_member_target";
    m_strings[2074] = "s_groupchat_list";
    m_strings[2075] = "s_groupchat_exit";
    m_strings[2009] = "s_realestate_detail_expire_date";
    m_strings[2010] = "s_realestate_detail_expire_time";
    m_strings[2011] = "s_realestate_morning";
    m_strings[2012] = "s_realestate_afternoon";
    m_strings[2013] = "s_realestate_waiting_time";
    m_strings[2014] = "s_realestate_date_string";
    m_strings[2015] = "s_realestate_price_desc_money";
    m_strings[2016] = "s_realestate_price_desc_item";
    m_strings[2017] = "s_realestate_description";
    m_strings[2018] = "s_realestate_sell_meso";
    m_strings[2019] = "s_realestate_sell_merat";
    m_strings[2020] = "s_realestate_sell_name";
    m_strings[2021] = "s_realestate_sell_wrong";
    m_strings[2022] = "s_realestate_sell_cant_sell_my_home_in_indoor";
    m_strings[2023] = "s_address_popup_sale";
    m_strings[2024] = "s_address_popup_waiting";
    m_strings[2025] = "s_address_popup_noroom";
    m_strings[2026] = "s_address_popup_myhome";
    m_strings[2027] = "s_address_popup_privilege";
    m_strings[2028] = "s_address_popup_meso_icon";
    m_strings[2029] = "s_address_popup_merat_icon";
    m_strings[2030] = "s_realestate_broker_default_buy";
    m_strings[2031] = "s_realestate_broker_default_no_room";
    m_strings[2032] = "s_realestate_broker_default_my_house";
    m_strings[2033] = "s_realestate_broker_click_buy";
    m_strings[2034] = "s_realestate_broker_click_no_room";
    m_strings[2035] = "s_realestate_broker_click_my_house";
    m_strings[2036] = "s_realestate_broker_sell_confirm";
    m_strings[2037] = "s_realestate_broker_cant_buy_more_than_two_house_for_site";
    m_strings[2038] = "s_realestate_broker_need_trophy";
    m_strings[2039] = "s_realestate_this_is_my_apartment";
    m_strings[2040] = "s_realestate_apartment_sold_out";
    m_strings[2041] = "s_realestate_apartment_sold_out_desc";
    m_strings[2042] = "s_realestate_contractable";
    m_strings[2043] = "s_realestate_terms";
    m_strings[2044] = "s_realestate_terms_text_content";
    m_strings[2076] = "s_tooltip_home_buff";
    m_strings[2077] = "s_msg_error_realestate_name";
    m_strings[2078] = "s_msg_error_realestate_name_ban_all";
    m_strings[2079] = "s_msg_error_realestate_name_ban_text";
    m_strings[2080] = "s_worldmap_go_myhome";
    m_strings[2081] = "s_worldmap_go_myhome_no_station";
    m_strings[2082] = "s_trade_request_success";
    m_strings[2083] = "s_trade_recieved_request";
    m_strings[2084] = "s_trade_decline";
    m_strings[2085] = "s_trade_cancel";
    m_strings[2086] = "s_trade_success";
    m_strings[2087] = "s_trade_error_system";
    m_strings[2088] = "s_trade_error_distance";
    m_strings[2089] = "s_trade_error_timeout";
    m_strings[2090] = "s_trade_error_already_request";
    m_strings[2091] = "s_trade_error_trading_now";
    m_strings[2092] = "s_trade_error_meso";
    m_strings[2093] = "s_trade_error_latched";
    m_strings[2094] = "s_trade_error_decline";
    m_strings[2095] = "s_trade_error_itemcount";
    m_strings[2096] = "s_trade_error_slotcount";
    m_strings[2097] = "s_trade_error_itemnone";
    m_strings[2098] = "s_trade_error_pvp";
    m_strings[2099] = "s_trade_error_mapLimit";
    m_strings[2100] = "s_trade_error_invalid_meso";
    m_strings[2101] = "s_trade_error_target_property_protection_time";
    m_strings[2102] = "s_trade_error_target_fatigue_penalty";
    m_strings[2103] = "s_trade_error";
    m_strings[2104] = "s_trade_error_meso_transfer_limited";
    m_strings[2105] = "s_trade_error_meso_transfer_limited_other";
    m_strings[2106] = "s_trade_error_meso_transfer_limited2";
    m_strings[2107] = "s_trade_error_meso_transfer_limited_other2";
    m_strings[2108] = "s_trade_error_meso_transfer_adv_level_limited";
    m_strings[2109] = "s_trade_error_meso_transfer_adv_level_limited_other";
    m_strings[2110] = "s_trade_meso";
    m_strings[2111] = "s_trade_tradelimit";
    m_strings[2112] = "s_trade_tradelimit_blackmarket";
    m_strings[2113] = "s_trade_restrict";
    m_strings[2114] = "s_trade_tradein";
    m_strings[2115] = "s_trade_already_requested";
    m_strings[2116] = "s_trade_unlatch_me";
    m_strings[2117] = "s_trade_unlatch_oppnent";
    m_strings[2118] = "s_trade_begin";
    m_strings[2119] = "s_gameoption_init";
    m_strings[2120] = "s_gameoption_init_all";
    m_strings[2121] = "s_gameoption_init_current";
    m_strings[2122] = "s_gameoption_quickslot_warning";
    m_strings[2123] = "s_gameoption_modified_warning";
    m_strings[2124] = "s_gameoption_keysetting_warning";
    m_strings[2127] = "s_gameoption_keysetting_shortcutkey_warning1";
    m_strings[2128] = "s_gameoption_keysetting_shortcutkey_warning2";
    m_strings[2129] = "s_gameoption_keysetting_shortcutkey_warning3";
    m_strings[2125] = "s_gameoption_quality_warning";
    m_strings[2126] = "s_gameoption_restart_warning";
    m_strings[2130] = "s_gameoption_confirm_reset_layout";
    m_strings[2131] = "s_gameoption_keysetting_modifiedkey";
    m_strings[2132] = "s_gameoption_keysetting_usenot_gamepad";
    m_strings[2133] = "s_gameoption_keysetting_usenot_keyboard";
    m_strings[2134] = "s_dynamic_action_already_alloc";
    m_strings[2135] = "s_dynamic_action_item_invalid";
    m_strings[2136] = "s_dynamic_action_already_learn";
    m_strings[2137] = "s_dynamic_action_err_shortcutkey";
    m_strings[2138] = "s_dynamic_action_learn";
    m_strings[2139] = "s_dynamic_action_learn_ok";
    m_strings[2141] = "s_fittingdoll_InventoryFull";
    m_strings[2140] = "s_fittingdoll_error_invalid_owner";
    m_strings[2142] = "s_fittingdoll_InvalidDoll";
    m_strings[2143] = "s_fittingdoll_InvalidItemType_Skin";
    m_strings[2144] = "s_fittingdoll_InvalidItemType_Equip";
    m_strings[2145] = "s_fittingdoll_InvalidItemType_PutonPc";
    m_strings[2146] = "s_fittingdoll_InvalidItemType_PutonDoll";
    m_strings[2147] = "s_fittingdoll_InvalidItem";
    m_strings[2148] = "s_fittingdoll_InvalidItem_rule";
    m_strings[2149] = "s_fittingdoll_Invaliditem_limit";
    m_strings[2150] = "s_fittingdoll_Invaliditem_male";
    m_strings[2151] = "s_fittingdoll_Invaliditem_female";
    m_strings[2152] = "s_fittingdoll_Invalid_slot";
    m_strings[2153] = "s_fittingdoll_Invalid_binding";
    m_strings[2154] = "s_fittingdoll_Invalid_doll";
    m_strings[2155] = "s_fittingdoll_Invalid_moveDisable";
    m_strings[2156] = "s_fittingdoll_transform_done_all";
    m_strings[2157] = "s_fittingdoll_transform_done_partially";
    m_strings[2158] = "s_home_returnable_invalid_state";
    m_strings[2159] = "s_home_returnable_forbidden";
    m_strings[2160] = "s_home_returnable_forbidden_to_sameplace";
    m_strings[2161] = "s_home_returnable_homeless";
    m_strings[2162] = "s_home_returnable_samefield";
    m_strings[2163] = "s_home_returnable_cooldown";
    m_strings[2164] = "s_home_returnable_fieldname";
    m_strings[2165] = "s_home_returnable_newcharacter";
    m_strings[2166] = "s_home_returnable_confirm_place";
    m_strings[2167] = "s_home_returnable_confirm_last_place";
    m_strings[2168] = "s_home_returnable_without_indoor";
    m_strings[2169] = "s_home_visit_confirm";
    m_strings[2170] = "s_home_visit_failed_dead";
    m_strings[2171] = "s_home_visit_failed_common";
    m_strings[2172] = "s_home_visit_failed_homeless";
    m_strings[2173] = "s_home_visit_failed_disablemap";
    m_strings[2174] = "s_home_visit_failed_myhome";
    m_strings[2175] = "s_home_invite_confirm";
    m_strings[2176] = "s_home_invite_accept";
    m_strings[2177] = "s_home_invite_reject";
    m_strings[2178] = "s_home_invite_acceptwait";
    m_strings[2179] = "s_home_invite_logout";
    m_strings[2180] = "s_home_invite_denybyauto";
    m_strings[2181] = "s_home_invite_timeout";
    m_strings[2182] = "s_home_invite_self";
    m_strings[2183] = "s_home_invite_cant_invite_now";
    m_strings[2184] = "s_tutorial_shortcutkey_limit";
    m_strings[2185] = "s_tutorial_itemputonoff_limit";
    m_strings[2186] = "s_tutorial_itemdrop_limit";
    m_strings[2187] = "s_tutorial_dialog_limit";
    m_strings[2188] = "s_tutorial_skip_movie";
    m_strings[2189] = "s_fail_enterfield_invaliduser";
    m_strings[2190] = "s_fail_enterfield_userfull";
    m_strings[2192] = "s_fail_enterfield_event_already_start";
    m_strings[2193] = "s_interact_result_auth";
    m_strings[2194] = "s_interact_result_quest";
    m_strings[2195] = "s_interact_result_party";
    m_strings[2196] = "s_interact_result_privilege";
    m_strings[2197] = "s_interact_result_unknown";
    m_strings[2198] = "s_interact_result_mastery";
    m_strings[2199] = "s_interact_find_new_telescope";
    m_strings[2200] = "s_hunting_kill_boss";
    m_strings[2201] = "s_hunting_npc_kill_boss";
    m_strings[2202] = "s_mode_pvp_status_winner";
    m_strings[2203] = "s_mode_pvp_status_challenger";
    m_strings[2204] = "s_returnhome_enable";
    m_strings[2205] = "s_returnhome_homeless";
    m_strings[2206] = "s_returnhome_disable_cooldown";
    m_strings[2207] = "s_returnhome_disable";
    m_strings[2208] = "s_returnhome_enable_merat";
    m_strings[2209] = "s_returnhome_homeless_merat";
    m_strings[2210] = "s_returnhome_disable_cooldown_merat";
    m_strings[2211] = "s_returnhome_disable_merat";
    m_strings[2212] = "s_report_fail_no_context";
    m_strings[2213] = "s_report_fail_no_reason";
    m_strings[2214] = "s_report_fail_no_blind_profile_check";
    m_strings[2215] = "s_report_really_report";
    m_strings[2216] = "s_report_really_report_with_ban";
    m_strings[2217] = "s_report_really_report_with_blind";
    m_strings[2218] = "s_report_really_blind";
    m_strings[2219] = "s_report_success";
    m_strings[2220] = "s_report_fail";
    m_strings[2221] = "s_report_blind_success";
    m_strings[2222] = "s_report_cant_report_own_item";
    m_strings[2223] = "s_report_ban_reason";
    m_strings[2224] = "s_tencent_report_block_warning_user";
    m_strings[2225] = "s_tencent_report_block_warning_ugc_field_banner";
    m_strings[2226] = "s_tencent_report_block_warning_ugc_item";
    m_strings[2227] = "s_ban_check_err_min_length";
    m_strings[2228] = "s_ban_check_err_max_length";
    m_strings[2229] = "s_ban_check_err_invalid_char";
    m_strings[2230] = "s_ban_check_err_invalid_char_space";
    m_strings[2231] = "s_ban_check_err_all_word";
    m_strings[2232] = "s_ban_check_err_all_name";
    m_strings[2233] = "s_ban_check_err_any_word";
    m_strings[2234] = "s_ban_check_err_any";
    m_strings[2235] = "s_ban_check_tabname_err_any_word";
    m_strings[2236] = "s_ban_check_tabname_err_any";
    m_strings[2237] = "s_ban_check_title_err_min_length";
    m_strings[2238] = "s_ban_check_title_err_max_length";
    m_strings[2239] = "s_ban_check_title_err_invalid_char";
    m_strings[2240] = "s_ban_check_title_err_invalid_char_space";
    m_strings[2241] = "s_ban_check_title_err_any_word";
    m_strings[2242] = "s_ban_check_title_err_any";
    m_strings[2243] = "s_ban_check_comment_err_any_word";
    m_strings[2244] = "s_ban_check_comment_err_any";
    m_strings[2245] = "s_nes_adminRoomEnterFailed";
    m_strings[2246] = "s_maintenance_title";
    m_strings[2247] = "s_maintenance_modify_enable";
    m_strings[2248] = "s_chat_restrict_samechat";
    m_strings[2249] = "s_chat_restrict_fastchat";
    m_strings[2250] = "s_chat_restrict_addtime";
    m_strings[2251] = "s_chat_restrict_accumwarning";
    m_strings[2252] = "s_chat_unknown_command";
    m_strings[2253] = "s_chat_whisper_decline";
    m_strings[2254] = "s_portal_invincible_effect_name";
    m_strings[2255] = "s_portal_invincible_effect_description";
    m_strings[2256] = "s_revival_effect_name";
    m_strings[2257] = "s_revival_effect_description";
    m_strings[2258] = "s_revival_invincible_effect_name";
    m_strings[2259] = "s_revival_invincible_effect_description";
    m_strings[2260] = "s_err_system_title";
    m_strings[2261] = "s_err_system_check_graphic_driver";
    m_strings[2262] = "s_err_system_graphic_error0";
    m_strings[2263] = "s_err_system_graphic_error1";
    m_strings[2264] = "s_err_system_graphic_error2";
    m_strings[2265] = "s_err_system_graphic_error3";
    m_strings[2266] = "s_err_system_graphic_error4";
    m_strings[2267] = "s_err_system_graphic_error5";
    m_strings[2268] = "s_err_system_graphic_error6";
    m_strings[2269] = "s_err_system_graphic_error7";
    m_strings[2270] = "s_err_system_graphic_error8";
    m_strings[2271] = "s_err_system_graphic_error9";
    m_strings[2272] = "s_err_system_graphic_error10";
    m_strings[2273] = "s_err_system_graphic_error11";
    m_strings[2274] = "s_err_system_graphic_error12";
    m_strings[2275] = "s_err_system_graphic_error13";
    m_strings[2276] = "s_err_system_graphic_error14";
    m_strings[2277] = "s_err_system_graphic_error15";
    m_strings[2278] = "s_err_system_graphic_error16";
    m_strings[2279] = "s_err_system_graphic_error17";
    m_strings[2280] = "s_err_system_graphic_error18";
    m_strings[2281] = "s_msg_restriction_special_chatting_need_acc_char_level";
    m_strings[2282] = "s_msg_restriction_special_chatting_need_acc_adv_level";
    m_strings[2283] = "s_msg_restriction_special_chatting_over_daily_usage_limit";
    m_strings[2284] = "s_msg_restriction_mail_send_need_acc_char_level";
    m_strings[2285] = "s_msg_restriction_mail_send_need_acc_adv_level";
    m_strings[2286] = "s_msg_restriction_mail_send_over_daily_usage_limit";
    m_strings[2287] = "s_msg_restriction_whisper_chatting_need_acc_char_level";
    m_strings[2288] = "s_msg_restriction_whisper_chatting_need_acc_adv_level";
    m_strings[2289] = "s_msg_restriction_group_chatting_need_acc_char_level";
    m_strings[2290] = "s_msg_restriction_group_chatting_need_acc_adv_level";
    m_strings[2291] = "s_msg_restriction_ugc_banner_need_acc_char_level";
    m_strings[2292] = "s_msg_restriction_ugc_banner_need_acc_adv_level";
    m_strings[2293] = "s_admin_character_name";
    m_strings[2294] = "s_itembreak_invalid_item";
    m_strings[2295] = "s_itembreak_invalid_donation_item";
    m_strings[2296] = "s_itembreak_unknown";
    m_strings[2297] = "s_itembreak_excellent_item";
    m_strings[2298] = "s_itembreak_donation_excellent_item";
    m_strings[2299] = "s_recall_user_notify_recall";
    m_strings[2300] = "s_recall_user_notify_confirm_recall";
    m_strings[2301] = "s_recall_user_notify_recalled";
    m_strings[2302] = "s_recall_user_notify_not_found";
    m_strings[2303] = "s_recall_user_notify_cannot_move";
    m_strings[2304] = "s_recall_user_notify_reject";
    m_strings[2305] = "s_recall_user_notify_already_recalled";
    m_strings[2306] = "s_recall_user_confirm";
    m_strings[2307] = "s_blackmarket_mail_to_sender";
    m_strings[2308] = "s_blackmarket_mail_to_cancel_direct";
    m_strings[2309] = "s_blackmarket_mail_to_cancel_expired";
    m_strings[2310] = "s_blackmarket_mail_to_cancel_hide";
    m_strings[2311] = "s_blackmarket_mail_to_seller_title";
    m_strings[2312] = "s_blackmarket_mail_to_seller_title2";
    m_strings[2313] = "s_blackmarket_mail_to_seller_title_pending";
    m_strings[2314] = "s_blackmarket_mail_to_seller_content";
    m_strings[2315] = "s_blackmarket_mail_to_seller_content_soldout";
    m_strings[2316] = "s_blackmarket_mail_to_vipseller_content";
    m_strings[2317] = "s_blackmarket_mail_to_vipseller_content_soldout";
    m_strings[2318] = "s_blackmarket_mail_to_seller_content2";
    m_strings[2319] = "s_blackmarket_mail_to_seller_content_pending2";
    m_strings[2320] = "s_blackmarket_mail_to_seller_content_pending3";
    m_strings[2321] = "s_blackmarket_mail_to_seller_content2_itemname";
    m_strings[2322] = "s_blackmarket_mail_to_buyer_title";
    m_strings[2323] = "s_blackmarket_mail_to_buyer_content";
    m_strings[2324] = "s_blackmarket_mail_to_cancel_title";
    m_strings[2325] = "s_blackmarket_mail_to_cancel_title_expired";
    m_strings[2326] = "s_blackmarket_mail_to_cancel_title_hide";
    m_strings[2327] = "s_blackmarket_mail_to_cancel_content";
    m_strings[2328] = "s_blackmarket_mail_to_fail_add_title";
    m_strings[2329] = "s_blackmarket_mail_to_fail_add_content";
    m_strings[2330] = "s_blackmarket_notice_try_later";
    m_strings[2332] = "s_blackmarket_upper_rank";
    m_strings[2331] = "s_blackmarket_price_1_unit";
    m_strings[2333] = "s_blackmarket_period";
    m_strings[2334] = "s_blackmarket_openday_1day";
    m_strings[2335] = "s_blackmarket_openday_2day";
    m_strings[2336] = "s_blackmarket_openday_over_2day";
    m_strings[2337] = "s_blackmarket_openday_with_hour";
    m_strings[2338] = "s_blackmarket_openday_am";
    m_strings[2339] = "s_blackmarket_openday_pm";
    m_strings[2340] = "s_blackmarket_notice_close";
    m_strings[2341] = "s_blackmarket_notice_sell_complete";
    m_strings[2342] = "s_blackmarket_remain_time_hhmmss";
    m_strings[2343] = "s_blackmarket_remain_time_mmss";
    m_strings[2344] = "s_blackmarket_remain_time_ss";
    m_strings[2345] = "s_blackmarket_shutdown";
    m_strings[2346] = "s_blackmarket_notice_fee";
    m_strings[2347] = "s_blackmarket_error_code";
    m_strings[2348] = "s_blackmarket_error_disable_registitem";
    m_strings[2349] = "s_blackmarket_error_close";
    m_strings[2350] = "s_blackmarket_error_already_remove";
    m_strings[2351] = "s_blackmarket_error_invalid_sale_price";
    m_strings[2352] = "s_blackmarket_error_invalid_sale_price_range";
    m_strings[2353] = "s_blackmarket_error_invalid_sale_count";
    m_strings[2354] = "s_blackmarket_error_lack_sale_count";
    m_strings[2355] = "s_blackmarket_error_max_register_item";
    m_strings[2356] = "s_blackmarket_error_fail_register";
    m_strings[2357] = "s_blackmarket_error_register_not_exist_in_inven";
    m_strings[2358] = "s_blackmarket_error_already_add";
    m_strings[2359] = "s_blackmarket_error_search_invalid_name";
    m_strings[2360] = "s_blackmarket_error_search_invalid_count";
    m_strings[2361] = "s_blackmarket_error_sell_restricted_by_user_level";
    m_strings[2362] = "s_blackmarket_error_buy_restricted_by_user_level";
    m_strings[2363] = "s_blackmarket_error_sell_restricted_by_char_cdate";
    m_strings[2364] = "s_blackmarket_error_buy_restricted_by_char_cdate";
    m_strings[2365] = "s_blackmarket_error_sell_restricted_by_user_level_ex";
    m_strings[2366] = "s_blackmarket_error_buy_restricted_by_user_level_ex";
    m_strings[2367] = "s_trade_error_send_restricted_by_user_level_ex";
    m_strings[2368] = "s_trade_error_recv_restricted_by_user_level_ex";
    m_strings[2369] = "s_itemdrop_error_restricted_by_user_level_ex";
    m_strings[2370] = "s_itempickup_error_restricted_by_user_level_ex";
    m_strings[2371] = "s_msg_blackmarket_complete_register";
    m_strings[2372] = "s_msg_blackmarket_complete_remove";
    m_strings[2373] = "s_msg_blackmarket_complete_buy";
    m_strings[2374] = "s_msg_blackmarket_complete_stopsale";
    m_strings[2375] = "s_msg_blackmarket_ask_buy";
    m_strings[2376] = "s_msg_blackmarket_ask_stopsale";
    m_strings[2377] = "s_msg_blackmarket_notice_discount_fee";
    m_strings[2378] = "s_tooltip_blackmarket_sellprice";
    m_strings[2379] = "s_talk_reward_title";
    m_strings[2380] = "s_itemenchant_unknown_err";
    m_strings[2381] = "s_itemenchant_invalid_item";
    m_strings[2382] = "s_itemenchant_except_item";
    m_strings[2383] = "s_itemenchant_damaged_item";
    m_strings[2384] = "s_itemenchant_lack_ingredient";
    m_strings[2389] = "s_itemenchant_fail_duration";
    m_strings[2385] = "s_itemenchant_fail_sec";
    m_strings[2386] = "s_itemenchant_fail_min";
    m_strings[2387] = "s_itemenchant_fail_hour";
    m_strings[2388] = "s_itemenchant_fail_day";
    m_strings[2390] = "s_itemenchant_return_item";
    m_strings[2391] = "s_itemenchant_messagebox";
    m_strings[2392] = "s_itemenchant_cinematic_btn";
    m_strings[2393] = "s_itemenchant_valid_item";
    m_strings[2394] = "s_itemenchant_damaged_item_tooltip";
    m_strings[2383] = "s_itemenchant_damaged_item";
    m_strings[2395] = "s_itemenchant_option_prop";
    m_strings[2396] = "s_itemenchant_option_damage";
    m_strings[2397] = "s_itemenchant_option_low_prop";
    m_strings[2398] = "s_itemenchant_option_repair";
    m_strings[2399] = "s_itemenchant_damage_warning";
    m_strings[2400] = "s_itemenchant_success_notice";
    m_strings[2401] = "s_itemenchant_use_protector";
    m_strings[2402] = "s_itemremake_chat_maxoption";
    m_strings[2403] = "s_item_repacking_limit_count";
    m_strings[2404] = "s_item_repacking_item_consume_count";
    m_strings[2405] = "s_item_repacking_item_limit_desc";
    m_strings[2406] = "s_item_repacking_item_consume_desc";
    m_strings[2407] = "s_item_repacking_scroll_success_dialog";
    m_strings[2408] = "s_shadowworld_removebuff";
    m_strings[2409] = "s_shadowworld_removebuff_before";
    m_strings[2410] = "s_shadowworld_player_kill";
    m_strings[2411] = "s_shadowworld_player_kill_slayer";
    m_strings[2412] = "s_shadowworld_player_kill_ruler";
    m_strings[2413] = "s_shadowworld_pkzone_msg";
    m_strings[2414] = "s_shadowworld_pkzone_chat_msg";
    m_strings[2415] = "s_shadowworld_safezone_msg";
    m_strings[2416] = "s_shadowworld_safezone_chat_msg";
    m_strings[2417] = "s_shadowworld_pkzone_allert";
    m_strings[2418] = "s_shadowworld_kill_log_die";
    m_strings[2419] = "s_shadowworld_kill_log_kill";
    m_strings[2420] = "s_pvp_start";
    m_strings[2421] = "s_pvp_ffa_double_kill";
    m_strings[2422] = "s_pvp_ffa_triple_kill";
    m_strings[2423] = "s_pvp_ffa_slayer_kill";
    m_strings[2424] = "s_pvp_ffa_ruler_kill";
    m_strings[2425] = "s_common_error_unknown";
    m_strings[2426] = "s_common_day";
    m_strings[2427] = "s_common_sec";
    m_strings[2428] = "s_common_min";
    m_strings[2429] = "s_common_hour";
    m_strings[2430] = "s_common_min_sec";
    m_strings[2431] = "s_common_hour_min";
    m_strings[2432] = "s_common_hour_min_sec";
    m_strings[2433] = "s_common_date_week";
    m_strings[2434] = "s_common_max_size";
    m_strings[2435] = "s_common_min_size";
    m_strings[2436] = "s_common_text_count";
    m_strings[2437] = "s_common_set";
    m_strings[2438] = "s_common_meso";
    m_strings[2439] = "s_common_merat";
    m_strings[2440] = "s_common_cash";
    m_strings[2441] = "s_common_payitem";
    m_strings[2442] = "s_common_meratname_cash";
    m_strings[2443] = "s_common_meratname_free";
    m_strings[2444] = "s_common_meratname_market";
    m_strings[2445] = "s_common_meratname_event";
    m_strings[2446] = "s_common_percent";
    m_strings[2447] = "s_bill_format_sumprice";
    m_strings[2448] = "s_bill_format_sumprice_beauty";
    m_strings[2449] = "s_bill_coupon_hair";
    m_strings[2450] = "s_bill_coupon_face";
    m_strings[2451] = "s_bill_coupon_makeup";
    m_strings[2452] = "s_bill_coupon_skin";
    m_strings[2453] = "s_bill_coupon_equip";
    m_strings[2454] = "s_beauty_use_coupon";
    m_strings[2455] = "s_bill_warning_coloring";
    m_strings[2456] = "s_bill_meratname_total";
    m_strings[2457] = "s_bill_meratprice_total";
    m_strings[2458] = "s_field_limit_unknown";
    m_strings[2459] = "s_field_limit_level_min";
    m_strings[2460] = "s_field_limit_achieve";
    m_strings[2461] = "s_field_limit_admin";
    m_strings[2462] = "s_field_limit_content_chat";
    m_strings[2463] = "s_room_increase_time";
    m_strings[2464] = "s_room_increase_time_type2";
    m_strings[2465] = "s_room_decrease_time";
    m_strings[2466] = "s_room_party_err_cooldown";
    m_strings[2467] = "s_room_dungeon_time_up";
    m_strings[2468] = "s_room_dungeon_cooldown";
    m_strings[2469] = "s_shutdown_notify";
    m_strings[2470] = "s_msg_shortcutkey_slot_full";
    m_strings[2471] = "s_msg_shortcutkey_error";
    m_strings[2472] = "s_bootypopup_buff_duration";
    m_strings[2473] = "s_field_enteracne_dungeon_boss_tooltip";
    m_strings[2474] = "s_field_enteracne_party_status_unknown";
    m_strings[2475] = "s_field_enteracne_party_status_level";
    m_strings[2476] = "s_field_enteracne_party_status_etc";
    m_strings[2477] = "s_field_enteracne_party_notify_enter_cheif";
    m_strings[2478] = "s_field_enteracne_party_notify_reset_dungeon";
    m_strings[2479] = "s_field_enterance_solo_status";
    m_strings[2480] = "s_field_enterance_party_status";
    m_strings[2481] = "s_dungeonRoom_cooldown_nextDay";
    m_strings[2482] = "s_dungeonRoom_cooldown_dayOfWeeks";
    m_strings[2483] = "s_emergency_maintenance_remain_minute";
    m_strings[2484] = "s_emergency_maintenance_remain_seconds";
    m_strings[2485] = "s_emergency_maintenance_function_limit";
    m_strings[2486] = "s_ugc_unload_banner_tooltip";
    m_strings[2487] = "s_msg_tooltip_customize_color";
    m_strings[2488] = "s_msg_tooltip_customize_buy_random_color";
    m_strings[2489] = "s_msg_tooltip_limit_register_meratmarket";
    m_strings[2490] = "s_msg_tooltip_enable_play_music";
    m_strings[2491] = "s_msg_tooltip_musicscore_enable_playcount";
    m_strings[2492] = "s_msg_tooltip_musicscore_disable_playcount";
    m_strings[2493] = "s_msg_tooltip_musicscore_enable_playcount_custom_empty";
    m_strings[2494] = "s_msg_tooltip_musicscore_custom_used_item_desc";
    m_strings[2495] = "s_msg_tooltip_musicscore_custom_used_item_desc_guide";
    m_strings[2496] = "s_msg_tooltip_musicscore_custom_empty_stat_desc";
    m_strings[2497] = "s_msg_tooltip_musicscore_stat_desc";
    m_strings[2498] = "s_msg_tooltip_musicscore_writer";
    m_strings[2499] = "s_msg_tooltip_gemstone_enable_upgrade";
    m_strings[2500] = "s_upper_hud_token_pocket";
    m_strings[2501] = "s_upper_hud_token_pocket_honor";
    m_strings[2502] = "s_upper_hud_token_pocket_karma";
    m_strings[2503] = "s_upper_hud_token_pocket_lu";
    m_strings[2504] = "s_upper_hud_token_pocket_habi";
    m_strings[2505] = "s_upper_hud_merat";
    m_strings[2506] = "s_upper_hud_merat_raw";
    m_strings[2507] = "s_enter_ugcmap_result_no_room";
    m_strings[2508] = "s_enter_ugcmap_result_not_exist_room";
    m_strings[2509] = "s_enter_ugcmap_result_expired";
    m_strings[2510] = "s_enter_ugcmap_result_not_exist_building";
    m_strings[2511] = "s_ugc_edit_terms_text_content";
    m_strings[2512] = "s_ugc_edit_terms_agree";
    m_strings[2513] = "s_ugc_edit_demolish_agree";
    m_strings[2514] = "s_ugc_edit_terms_coupon_consume";
    m_strings[2515] = "s_ugc_item_edit_terms";
    m_strings[2516] = "s_ugc_banner_terms";
    m_strings[2517] = "s_ugc_profile_terms";
    m_strings[2518] = "s_ugc_guildmark_terms";
    m_strings[2519] = "s_ugc_guildposter_terms";
    m_strings[2520] = "s_blackmarket_terms";
    m_strings[2521] = "s_blackmarket_terms_text_content";
    m_strings[2522] = "s_meratmarket_designers_terms";
    m_strings[2523] = "s_meratmarket_designers_terms_text_content";
    m_strings[2524] = "s_meratmarket_tooltip_sell_count";
    m_strings[2525] = "s_meratmarket_tooltip_sell_date";
    m_strings[2526] = "s_meratmarket_tooltip_bookmark";
    m_strings[2527] = "s_meratmarket_tooltip_myshop_calculate";
    m_strings[2528] = "s_meratmarket_complete_buy_item";
    m_strings[2529] = "s_meratmarket_complete_buy_item_all";
    m_strings[2530] = "s_meratmarket_complete_buy_item_error";
    m_strings[2531] = "s_meratmarket_complete_buy_item_all_error";
    m_strings[2532] = "s_meratmarket_complete_buy_item_all_with_error";
    m_strings[2533] = "s_meratmarket_complete_check_balance_success";
    m_strings[2534] = "s_meratmarket_emptytext_ad";
    m_strings[2535] = "s_meratmarket_emptytext_not_exist";
    m_strings[2536] = "s_meratmarket_error_result_buy_lack_merat";
    m_strings[2537] = "s_meratmarket_error_result_buy_lack_empty_slot";
    m_strings[2538] = "s_meratmarket_error_result_buy_own_product";
    m_strings[2539] = "s_meratmarket_error_result_buy_price_index";
    m_strings[2540] = "s_meratmarket_error_result_buy_sold_out";
    m_strings[2541] = "s_meratmarket_error_result_buy_sold_out_premium_buylimit";
    m_strings[2542] = "s_meratmarket_error_result_buy_change_price";
    m_strings[2543] = "s_meratmarket_error_result_buy_count";
    m_strings[2544] = "s_meratmarket_error_result_buy_not_sale";
    m_strings[2545] = "s_meratmarket_error_result_already_add";
    m_strings[2546] = "s_meratmarket_error_result_buy_error";
    m_strings[2547] = "s_meratmarket_error_result_check_balance_delay_time";
    m_strings[2548] = "s_meratmarket_buy_format";
    m_strings[2549] = "s_meratmarket_buy_title";
    m_strings[2550] = "s_meratmarket_buy_success_row";
    m_strings[2551] = "s_meratmarket_buy_fail_row";
    m_strings[2552] = "s_meratmarket_buy_success_all";
    m_strings[2553] = "s_meratmarket_buy_success_with_fail";
    m_strings[2554] = "s_meratmarket_buy_fail_all";
    m_strings[2555] = "s_meratmarket_gift_title";
    m_strings[2556] = "s_meratmarket_gift_success_row";
    m_strings[2557] = "s_meratmarket_gift_fail_row";
    m_strings[2558] = "s_meratmarket_gift_success_all";
    m_strings[2559] = "s_meratmarket_gift_success_with_fail";
    m_strings[2560] = "s_meratmarket_gift_fail_all";
    m_strings[2561] = "s_meratmarket_error_lack_invenslot";
    m_strings[2562] = "s_meratmarket_error_already_add_bookmark";
    m_strings[2563] = "s_meratmarket_error_remove_state_sale";
    m_strings[2564] = "s_meratmarket_error_calculating";
    m_strings[2565] = "s_meratmarket_error_register_price";
    m_strings[2566] = "s_meratmarket_error_register_invalid_category";
    m_strings[2567] = "s_meratmarket_error_register_disable_ugcitem";
    m_strings[2568] = "s_meratmarket_error_register_blocked_ugcitem";
    m_strings[2569] = "s_meratmarket_error_bancheck_desc";
    m_strings[2570] = "s_meratmarket_error_bancheck_tags";
    m_strings[2571] = "s_meratmarket_error_bancheck_desc_or_tags";
    m_strings[2572] = "s_meratmarket_error_common";
    m_strings[2573] = "s_meratmarket_error_already_sale";
    m_strings[2574] = "s_meratmarket_error_not_sale";
    m_strings[2575] = "s_meratmarket_error_not_sale_expired";
    m_strings[2576] = "s_meratmarket_error_search_result_empty";
    m_strings[2577] = "s_meratmarket_error_search_result_empty_by_itemlink";
    m_strings[2578] = "s_meratmarket_error_search_result_empty_by_banner";
    m_strings[2579] = "s_meratmarket_error_search_result_with_ban";
    m_strings[2580] = "s_meratmarket_error_buy_owner_product";
    m_strings[2581] = "s_meratmarket_error_buy_soldout";
    m_strings[2582] = "s_meratmarket_error_add_basket_by_buylimit";
    m_strings[2583] = "s_meratmarket_error_buy_soldout_premium_buylimit";
    m_strings[2589] = "s_meratmarket_bookmark_add_complete";
    m_strings[2590] = "s_meratmarket_bookmark_limit_maxcount";
    m_strings[2591] = "s_meratmarket_bookmark_input_search";
    m_strings[2592] = "s_meratmarket_bookmark_empty_products";
    m_strings[2593] = "s_meratmarket_basket_limit_maxcount";
    m_strings[2594] = "s_meratmarket_basket_empty_buyall";
    m_strings[2595] = "s_meratmarket_basket_complete_add";
    m_strings[2596] = "s_meratmarket_myshop_notice_sell_restrict";
    m_strings[2597] = "s_meratmarket_myshop_notice_sell_restrict_title";
    m_strings[2598] = "s_meratmarket_myshop_notice_restrict_by_sellingamount";
    m_strings[2599] = "s_meratmarket_myshop_sell_count";
    m_strings[2600] = "s_meratmarket_myshop_history_buy_date";
    m_strings[2601] = "s_meratmarket_myshop_limit_register_count";
    m_strings[2602] = "s_meratmarket_myshop_notice_calculate";
    m_strings[2603] = "s_meratmarket_myshop_ask_stopsale";
    m_strings[2604] = "s_meratmarket_myshop_ask_remove";
    m_strings[2605] = "s_meratmarket_myshop_empty_calculate";
    m_strings[2606] = "s_meratmarket_myshop_history_row";
    m_strings[2607] = "s_meratmarket_myshop_history_enable_collect";
    m_strings[2608] = "s_meratmarket_myshop_history_schedule_collect";
    m_strings[2609] = "s_meratmarket_myshop_history_title";
    m_strings[2610] = "s_meratmarket_myshop_complete_stopsale";
    m_strings[2611] = "s_meratmarket_myshop_complete_register";
    m_strings[2612] = "s_meratmarket_myshop_complete_remove";
    m_strings[2613] = "s_meratmarket_myshop_complete_resale";
    m_strings[2614] = "s_meratmarket_myshop_complete_calculate";
    m_strings[2615] = "s_meratmarket_free_resale_confirm";
    m_strings[2616] = "s_meratmarket_register_limit_desc";
    m_strings[2617] = "s_meratmarket_register_sale_day";
    m_strings[2618] = "s_meratmarket_register_ad_hour_and_price";
    m_strings[2619] = "s_meratmarket_register_royalty";
    m_strings[2620] = "s_meratmarket_register_notice_price";
    m_strings[2621] = "s_meratmarket_register_fee";
    m_strings[2622] = "s_meratmarket_register_error_add_not_find";
    m_strings[2623] = "s_meratmarket_register_error_add_already";
    m_strings[2624] = "s_meratmarket_bill_total_fee";
    m_strings[2625] = "s_meratmarket_priceday";
    m_strings[2626] = "s_meratmarket_priceday_limitless";
    m_strings[2627] = "s_meratmarket_gift_mail_sender";
    m_strings[2628] = "s_meratmarket_gift_mail_title";
    m_strings[2629] = "s_meratmarket_gift_mail_content";
    m_strings[2630] = "s_meratmarket_notice_default";
    m_strings[2631] = "s_meratmarket_error_result_gift_not_exist_user";
    m_strings[2632] = "s_meratmarket_error_result_gift_target_admin";
    m_strings[2633] = "s_meratmarket_error_result_gift_admin";
    m_strings[2634] = "s_meratmarket_already_in_modelhouse";
    m_strings[2635] = "s_meratmarket_moveto_modelhouse_forbidden";
    m_strings[2636] = "s_mesoMarket_mail_to_sender";
    m_strings[2637] = "s_mesoMarket_mail_to_cancel_title";
    m_strings[2638] = "s_mesoMarket_mail_to_cancel_content";
    m_strings[2639] = "s_mesoMarket_mail_to_seller_title";
    m_strings[2640] = "s_mesoMarket_mail_to_seller_content";
    m_strings[2641] = "s_mesoMarket_mail_to_buyer_title";
    m_strings[2642] = "s_mesoMarket_mail_to_buyer_content";
    m_strings[2643] = "s_mentoring_new_mentor_mail_sender";
    m_strings[2644] = "s_mentoring_new_mentor_mail_title";
    m_strings[2645] = "s_mentoring_new_mentor_mail_content";
    m_strings[2646] = "s_cashshop_invenpickup";
    m_strings[2647] = "s_cashshop_invenpickup_refund";
    m_strings[2648] = "s_cashshop_refund";
    m_strings[2649] = "s_cashshop_error_onetime_buy";
    m_strings[2650] = "s_cashshop_expand_inven_warning";
    m_strings[2651] = "s_cashshop_expand_inven_tab_warning";
    m_strings[2652] = "s_cashshop_expand_character_slot_warning";
    m_strings[2653] = "s_cashshop_dbclick_info";
    m_strings[2654] = "s_cashshop_lack_balance";
    m_strings[2655] = "s_cashshop_basket";
    m_strings[2656] = "s_cashshop_buy_success";
    m_strings[2657] = "s_cashshop_get_coupon_success";
    m_strings[2658] = "s_cashshop_buy_success_send_mail";
    m_strings[2659] = "s_cashshop_gift_success";
    m_strings[2660] = "s_cashshop_refund_success";
    m_strings[2661] = "s_cashshop_pickup_success";
    m_strings[2662] = "s_cashshop_gift_message";
    m_strings[2663] = "s_cashshop_gift_comfirm";
    m_strings[2664] = "s_cashshop_err_unknown";
    m_strings[2665] = "s_cashshop_err_closed";
    m_strings[2666] = "s_cashshop_err_closed_pubtest";
    m_strings[2667] = "s_cashshop_err_disconnect";
    m_strings[2668] = "s_cashshop_err_not_ready_product";
    m_strings[2669] = "s_cashshop_err_invalid_gift_name";
    m_strings[2670] = "s_cashshop_err_same_account";
    m_strings[2671] = "s_cashshop_err_no_empty_slot";
    m_strings[2672] = "s_cashshop_err_no_empty_slot_pickup_jp";
    m_strings[2673] = "s_cashshop_err_not_purchase_date";
    m_strings[2674] = "s_cashshop_err_cannot_gift_product";
    m_strings[2675] = "s_cashshop_err_cannot_refund_product";
    m_strings[2676] = "s_cashshop_err_null_cash_product_data";
    m_strings[2677] = "s_cashshop_err_null_nisms_product";
    m_strings[2678] = "s_cashshop_err_requesting";
    m_strings[2679] = "s_cashshop_err_invalid_authorization_token";
    m_strings[2680] = "s_cashshop_err_balance_unknown";
    m_strings[2681] = "s_cashshop_err_balance_block_user";
    m_strings[2682] = "s_cashshop_err_balance_maintenance";
    m_strings[2683] = "s_cashshop_err_balance_notfind_user";
    m_strings[2684] = "s_cashshop_err_purchase_unknown";
    m_strings[2685] = "s_cashshop_err_purchase_total_sale_count_over";
    m_strings[2686] = "s_cashshop_err_purchase_sale_count_over";
    m_strings[2687] = "s_cashshop_err_purchase_invalid_game";
    m_strings[2688] = "s_cashshop_err_purchase_invalid_gift_product";
    m_strings[2689] = "s_cashshop_err_purchase_eventcash_protect_gift";
    m_strings[2690] = "s_cashshop_err_purchase_eventcash_protect_buy";
    m_strings[2691] = "s_cashshop_err_purchase_maintenance";
    m_strings[2692] = "s_cashshop_err_purchase_limit_purchase";
    m_strings[2693] = "s_cashshop_err_purchase_lock_cashuse";
    m_strings[2694] = "s_cashshop_err_purchase_block_user";
    m_strings[2695] = "s_cashshop_err_purchase_notfind_user";
    m_strings[2696] = "s_cashshop_err_purchase_lack_balance";
    m_strings[2697] = "s_cashshop_err_purchase_invalid_cash_date";
    m_strings[2698] = "s_cashshop_err_purchase_invalid_sale_product";
    m_strings[2699] = "s_cashshop_err_purchase_invalid_cash_user";
    m_strings[2700] = "s_cashshop_err_inventory_inquiry_unknown";
    m_strings[2701] = "s_cashshop_err_inventory_inquiry_maintenance";
    m_strings[2702] = "s_cashshop_err_inventory_pickup_unknown";
    m_strings[2703] = "s_cashshop_err_inventory_pickup_no_inventory";
    m_strings[2704] = "s_cashshop_err_inventory_pickup_lackcount";
    m_strings[2705] = "s_cashshop_err_inventory_pickup_maintenance";
    m_strings[2706] = "s_cashshop_err_refund_unknown";
    m_strings[2707] = "s_cashshop_err_refund_disable_refund";
    m_strings[2708] = "s_cashshop_err_refund_over_date";
    m_strings[2709] = "s_cashshop_err_refund_no_inventory";
    m_strings[2710] = "s_cashshop_err_refund_gift";
    m_strings[2711] = "s_cashshop_err_gift_limit";
    m_strings[2712] = "s_cashshop_err_gift_age";
    m_strings[2713] = "s_cashshop_err_gift_send_block";
    m_strings[2714] = "s_cashshop_err_gift_recv_block";
    m_strings[2715] = "s_cashshop_err_gift_unknown";
    m_strings[2716] = "s_cashshop_err_gift_sale_count_over";
    m_strings[2717] = "s_partydps_notice_history_prefix";
    m_strings[2718] = "s_partydps_notice_history_row";
    m_strings[2719] = "s_partydps_notice_history_total_time";
    m_strings[2720] = "s_msgbox_format_profile_char_detail";
    m_strings[2721] = "s_messenger_comfirm_chat_super";
    m_strings[2722] = "s_messenger_comfirm_chat_world";
    m_strings[2723] = "s_messenger_comfirm_chat_channel";
    m_strings[2724] = "s_messenger_no_show_messagebox";
    m_strings[2725] = "s_messenger_whisper";
    m_strings[2726] = "s_messenger_club";
    m_strings[2727] = "s_messenger_party_chatballoon_prefix";
    m_strings[2728] = "s_messenger_guild_chatballoon_prefix";
    m_strings[2729] = "s_gem_error_inventory_full";
    m_strings[2730] = "s_gem_error_InvalidSlot";
    m_strings[2731] = "s_gem_error_InvalidItem";
    m_strings[2732] = "s_gem_error_Expired";
    m_strings[2733] = "s_gem_error_PCBang";
    m_strings[2734] = "s_gem_error_unknown";
    m_strings[2735] = "s_room_exit_ugc_indoor";
    m_strings[2736] = "s_room_exit_bonus";
    m_strings[2737] = "s_room_exit_massive_event";
    m_strings[2738] = "s_room_exit_pvp_zone";
    m_strings[2739] = "s_room_exit_msg_ugc_indoor";
    m_strings[2740] = "s_room_exit_msg_boss_dungeon";
    m_strings[2741] = "s_room_exit_msg_party_dungeon";
    m_strings[2742] = "s_room_exit_msg_shadow_expedition_dungeon";
    m_strings[2743] = "s_room_exit_msg_bonus";
    m_strings[2744] = "s_room_exit_msg_massive_event";
    m_strings[2745] = "s_room_exit_msg_pvp_zone";
    m_strings[2746] = "s_room_exit_msg_pvp_field";
    m_strings[2747] = "s_room_exit_msg_design";
    m_strings[2748] = "s_room_exit_msg_blueprint";
    m_strings[2749] = "s_room_exit_msg_blueprint_preview";
    m_strings[2750] = "s_itemlink_meratmarket";
    m_strings[2751] = "s_itemlink_cashshop";
    m_strings[2752] = "s_waitingticket_message";
    m_strings[2753] = "s_waitingticket_cancel";
    m_strings[2754] = "s_debug_invincible";
    m_strings[2755] = "s_debug_god_mode";
    m_strings[2756] = "s_debug_invisible_all";
    m_strings[2757] = "s_debug_invisible_npc";
    m_strings[2758] = "s_debug_instant_death";
    m_strings[2759] = "s_superchat_use_coupon";
    m_strings[2760] = "s_worldchat_use_coupon";
    m_strings[2761] = "s_channelchat_use_coupon";
    m_strings[2762] = "s_weddingchat_use_coupon";
    m_strings[2763] = "s_revival_use_coupon";
    m_strings[2764] = "s_pet_name_change_use_coupon";
    m_strings[2765] = "s_alreadyloginuser_request_kick";
    m_strings[2766] = "s_alreadyloginuser_response_kick";
    m_strings[2767] = "s_lauchingfestival_onetimecharacter";
    m_strings[2768] = "s_pcbang_play_time1";
    m_strings[2769] = "s_pcbang_play_time2";
    m_strings[2770] = "s_pcbang_cant_tutorial_field";
    m_strings[2771] = "s_pcbang_no_pcbang";
    m_strings[2772] = "s_pcbang_get_gift_item";
    m_strings[2773] = "s_pcbang_get_play_item";
    m_strings[2774] = "s_play_time_warnning";
    m_strings[2775] = "s_play_time_warnning_fatigue_half_begin";
    m_strings[2776] = "s_play_time_warnning_fatigue_half";
    m_strings[2777] = "s_play_time_warnning_fatigue_max";
    m_strings[2778] = "s_play_time_warnning_chat";
    m_strings[2779] = "s_nametag_symbol_none";
    m_strings[2780] = "s_nametag_symbol_enchant";
    m_strings[2781] = "s_nametag_symbol_seller";
    m_strings[2782] = "s_nametag_symbol_guild";
    m_strings[2783] = "s_nametag_symbol_architect";
    m_strings[2784] = "s_nametag_symbol_trophy";
    m_strings[2785] = "s_nametag_symbol_fisher";
    m_strings[2786] = "s_nametag_symbol_musician";
    m_strings[2787] = "s_nametag_symbol_balrog";
    m_strings[2788] = "s_nametag_symbol_pioneer";
    m_strings[2789] = "s_nametag_symbol_oneyear";
    m_strings[2790] = "s_nametag_symbol_level";
    m_strings[2791] = "s_nametag_symbol_enchant_desc";
    m_strings[2792] = "s_nametag_symbol_seller_desc";
    m_strings[2793] = "s_nametag_symbol_guild_desc";
    m_strings[2794] = "s_nametag_symbol_architect_desc";
    m_strings[2795] = "s_nametag_symbol_trophy_desc";
    m_strings[2796] = "s_nametag_symbol_fisher_desc";
    m_strings[2797] = "s_nametag_symbol_musician_desc";
    m_strings[2798] = "s_nametag_symbol_balrog_desc";
    m_strings[2799] = "s_nametag_symbol_pioneer_desc";
    m_strings[2800] = "s_nametag_symbol_oneyear_desc";
    m_strings[2801] = "s_nametag_symbol_level_desc";
    m_strings[2802] = "s_fieldboss_reward_assistbonus_notify";
    m_strings[2803] = "s_macro_penalty_reward_notify";
    m_strings[2804] = "s_user_trigger_over_max_length";
    m_strings[2805] = "s_user_trigger_over_max_state";
    m_strings[2806] = "s_user_trigger_over_max_enter_action";
    m_strings[2807] = "s_user_trigger_over_max_condition";
    m_strings[2808] = "s_user_trigger_over_max_condition_action";
    m_strings[2809] = "s_user_trigger_item_tooltip_enable_trigger_control";
    m_strings[2810] = "s_user_trigger_item_tooltip_state_change_action_permission";
    m_strings[2811] = "s_user_trigger_debugging_msg";
    m_strings[2812] = "s_user_trigger_error_msg_system_error";
    m_strings[2813] = "s_user_trigger_error_msg_cube_position";
    m_strings[2814] = "s_user_trigger_ask_msg_rollback";
    m_strings[2815] = "s_user_trigger_ask_msg_clear_contents";
    m_strings[2816] = "s_user_trigger_ask_msg_save";
    m_strings[2817] = "s_user_trigger_ask_msg_close";
    m_strings[2818] = "s_user_trigger_msg_show_debug";
    m_strings[2819] = "s_user_trigger_msg_rollback";
    m_strings[2820] = "s_home_password_on_msg";
    m_strings[2821] = "s_home_password_off_msg";
    m_strings[2822] = "s_home_password_off_confirm";
    m_strings[2823] = "s_home_password_input";
    m_strings[2824] = "s_home_password_state_on";
    m_strings[2825] = "s_home_password_state_off";
    m_strings[2826] = "s_home_password_string_error";
    m_strings[2827] = "s_home_password_mismatch";
    m_strings[2828] = "s_home_password_block_time";
    m_strings[2829] = "s_home_password_on_chat_msg";
    m_strings[2830] = "s_home_password_off_chat_msg";
    m_strings[2831] = "s_home_password_enter_field_chat_msg";
    m_strings[2832] = "s_home_password_user_out_chat_msg";
    m_strings[2833] = "s_home_password_expire_date_chat_msg";
    m_strings[2834] = "s_home_password_user_out_button";
    m_strings[2835] = "s_home_commend_success";
    m_strings[2836] = "s_home_commend_send_confirm";
    m_strings[2837] = "s_team_pvp_red_team_name";
    m_strings[2838] = "s_team_pvp_blue_team_name";
    m_strings[2839] = "s_team_pvp_north";
    m_strings[2840] = "s_team_pvp_center";
    m_strings[2841] = "s_team_pvp_south";
    m_strings[2842] = "s_team_pvp_conquered";
    m_strings[2843] = "s_team_pvp_red_player_plunder";
    m_strings[2844] = "s_team_pvp_blue_player_plunder";
    m_strings[2845] = "s_team_pvp_winner_reward";
    m_strings[2846] = "s_team_pvp_loser_reward";
    m_strings[2847] = "s_render_screen_restoration_failed";
    m_strings[2848] = "s_render_graphiccard_error";
    m_strings[2849] = "s_window_service_auth_error";
    m_strings[2850] = "s_util_mem_depletion_url";
    m_strings[2851] = "s_util_mem_depletion_phyx";
    m_strings[2852] = "s_util_mem_depletion_default";
    m_strings[2853] = "s_partysearch_sort_party_create_hi";
    m_strings[2854] = "s_partysearch_sort_party_create_low";
    m_strings[2855] = "s_partysearch_sort_party_level_hi";
    m_strings[2856] = "s_partysearch_sort_party_level_low";
    m_strings[2857] = "s_partysearch_sort_memeber_count_hi";
    m_strings[2858] = "s_partysearch_sort_memeber_count_low";
    m_strings[2859] = "s_partysearch_sort_memeber_create_hi";
    m_strings[2860] = "s_partysearch_sort_memeber_create_low";
    m_strings[2861] = "s_partysearch_complete_register_partysearch";
    m_strings[2862] = "s_partysearch_complete_register_membersearch";
    m_strings[2863] = "s_partysearch_complete_remove_partysearch";
    m_strings[2864] = "s_partysearch_complete_remove_membersearch";
    m_strings[2865] = "s_partysearch_ask_party_join_already_memebersearch";
    m_strings[2866] = "s_partysearch_err_search_result_empty";
    m_strings[2867] = "s_partysearch_err_search_result_with_ban";
    m_strings[2868] = "s_partysearch_err_whisper_myself";
    m_strings[2869] = "s_partysearch_err_party_join_myself";
    m_strings[2870] = "s_partysearch_err_party_join_already";
    m_strings[2871] = "s_partysearch_err_party_join_lack_gearscore";
    m_strings[2872] = "s_partysearch_err_party_invite_myself";
    m_strings[2873] = "s_partysearch_err_party_invite_not_chief";
    m_strings[2874] = "s_partysearch_err_memebersearch_cant_register_not_chief";
    m_strings[2875] = "s_partysearch_err_memebersearch_cant_register_max_memebercount";
    m_strings[2876] = "s_partysearch_err_memebersearch_cant_register_limit_condition";
    m_strings[2877] = "s_partysearch_err_memebersearch_cant_register_already";
    m_strings[2878] = "s_partysearch_err_memebersearch_cant_modify_not_chief";
    m_strings[2879] = "s_partysearch_err_memebersearch_cant_modify_no_register";
    m_strings[2880] = "s_partysearch_err_partysearch_cant_register_in_party";
    m_strings[2881] = "s_partysearch_err_partysearch_cant_register_limit_condition";
    m_strings[2882] = "s_partysearch_err_partysearch_cant_register_already";
    m_strings[2883] = "s_partysearch_err_partysearch_cant_modify_in_party";
    m_strings[2884] = "s_partysearch_err_partysearch_cant_modify_no_register";
    m_strings[2885] = "s_partysearch_err_dungeon_cooldown";
    m_strings[2886] = "s_partysearch_err_server_lastaction";
    m_strings[2887] = "s_partysearch_err_server_not_chief";
    m_strings[2888] = "s_partysearch_err_server_max_member";
    m_strings[2889] = "s_partysearch_err_server_db";
    m_strings[2890] = "s_partysearch_err_server_already_register";
    m_strings[2891] = "s_partysearch_err_server_invalid_type";
    m_strings[2892] = "s_partysearch_err_server_in_party";
    m_strings[2893] = "s_partysearch_err_server_registring";
    m_strings[2898] = "s_partysearch_err_server_code";
    m_strings[2894] = "s_partysearch_err_server_banword_title";
    m_strings[2895] = "s_partysearch_err_server_banword_findword";
    m_strings[2896] = "s_partysearch_err_server_party_invited";
    m_strings[2897] = "s_partysearch_err_server_blocked";
    m_strings[2899] = "s_partysearchregister_err_title";
    m_strings[2900] = "s_partysearchregister_invalid_dungeonlevel";
    m_strings[2901] = "s_partysearchregister_invalid_dungeondata";
    m_strings[2902] = "s_partysearchregister_ask_remove";
    m_strings[2903] = "s_err_cash_recall_cannot_now";
    m_strings[2904] = "s_err_cash_recall_prohibit_map";
    m_strings[2905] = "s_err_cash_recall_cannot_place";
    m_strings[2906] = "s_err_cash_recall_not_guild";
    m_strings[2907] = "s_err_cash_recall_not_party";
    m_strings[2908] = "s_err_cash_recall_no_guildmember";
    m_strings[2909] = "s_err_cash_recall_no_partymember";
    m_strings[2910] = "s_err_cash_recall_no_weddingmember";
    m_strings[2911] = "s_err_cash_recall_overflow";
    m_strings[2912] = "s_err_cash_recall_cannot_dead";
    m_strings[2913] = "s_err_cash_recall_cannot_battle";
    m_strings[2914] = "s_cash_recall_confirm";
    m_strings[2915] = "s_cash_recall_party_notice";
    m_strings[2916] = "s_cash_recall_guild_notice";
    m_strings[2917] = "s_cash_recall_expired_notice";
    m_strings[2918] = "s_cash_recall_end_notice";
    m_strings[2919] = "s_cash_recall_other_continent";
    m_strings[2920] = "s_enchantscroll_openscroll";
    m_strings[2921] = "s_enchantscroll_desc_enchant";
    m_strings[2922] = "s_enchantscroll_desc_restore";
    m_strings[2923] = "s_enchantscroll_desc_repair";
    m_strings[2924] = "s_enchantscroll_desc_random_enchant";
    m_strings[2925] = "s_enchantscroll_limit";
    m_strings[2926] = "s_enchantscroll_itemname";
    m_strings[2927] = "s_enchantscroll_breaking";
    m_strings[2928] = "s_enchantscroll_successprop";
    m_strings[2929] = "s_enchantscroll_ok";
    m_strings[2930] = "s_enchantscroll_invalid_scroll";
    m_strings[2931] = "s_enchantscroll_invalid_item";
    m_strings[2932] = "s_enchantscroll_breaking_item";
    m_strings[2933] = "s_enchantscroll_invalid_level";
    m_strings[2934] = "s_enchantscroll_invalid_slot";
    m_strings[2935] = "s_enchantscroll_invalid_rank";
    m_strings[2936] = "s_enchantscroll_invalid_grade";
    m_strings[2937] = "s_enchantscroll_not_breaking_item";
    m_strings[2938] = "s_systemmail_notify_ontime_confirm";
    m_strings[2939] = "s_server_name_scania";
    m_strings[2940] = "s_server_name_mardia";
    m_strings[2941] = "s_server_name_hasello";
    m_strings[2942] = "s_server_name_windia";
    m_strings[2943] = "s_server_name_flata";
    m_strings[2944] = "s_recovery_mail_title";
    m_strings[2945] = "s_recovery_mail_content";
    m_strings[2946] = "s_recovery_mail_sender";
    m_strings[2947] = "s_trade_recovery_mail_title";
    m_strings[2948] = "s_trade_recovery_mail_content";
    m_strings[2949] = "s_trade_recovery_mail_sender";
    m_strings[2950] = "s_doll_recovery_mail_title";
    m_strings[2951] = "s_doll_recovery_mail_content";
    m_strings[2952] = "s_doll_recovery_mail_sender";
    m_strings[2953] = "s_function_cube_error_invalid_cube";
    m_strings[2954] = "s_function_cube_error_invalid_pos";
    m_strings[2955] = "s_function_cube_error_invalid_summon_user";
    m_strings[2956] = "s_err_ugcmap_package_cant_use";
    m_strings[2957] = "s_err_ugcmap_package_cant_use_in_this_map";
    m_strings[2958] = "s_err_ugcmap_package_should_use_in_indoor";
    m_strings[2959] = "s_err_ugcmap_package_not_a_valid_package_item";
    m_strings[2960] = "s_err_ugcmap_package_cant_use_in_others_home";
    m_strings[2961] = "s_err_ugcmap_package_clear_indoor_first";
    m_strings[2962] = "s_err_ugcmap_package_not_a_valid_indoor";
    m_strings[2963] = "s_err_ugcmap_package_not_a_indoor_for_package_item";
    m_strings[2964] = "s_err_ugcmap_package_not_a_indoor_for_this_package_item";
    m_strings[2965] = "s_err_ugcmap_package_failed_to_consume_package_item";
    m_strings[2966] = "s_err_ugcmap_package_automatic_creation_is_in_progress";
    m_strings[2967] = "s_err_ugcmap_package_automatic_removal_is_in_progress";
    m_strings[2968] = "s_ugcmap_package_automatic_creation_completed";
    m_strings[2969] = "s_ugcmap_package_automatic_removal_completed";
    m_strings[2970] = "s_ugcmap_package_automatic_creation_suspended";
    m_strings[2971] = "s_ugcmap_package_automatic_removal_suspended";
    m_strings[2972] = "s_ugcmap_package_automatic_creation_skip";
    m_strings[2973] = "s_ugcmap_package_open_package_when_indoor_size_is_different";
    m_strings[2974] = "s_ugcmap_package_open_package_when_indoor_is_empty";
    m_strings[2975] = "s_err_ugcmap_design_home_should_use_in_design_home";
    m_strings[2976] = "s_err_ugcmap_design_home_not_my_design_home";
    m_strings[2977] = "s_err_ugcmap_design_home_indoor_isnt_empty";
    m_strings[2978] = "s_err_ugcmap_design_home_should_use_in_home";
    m_strings[2979] = "s_err_ugcmap_design_home_nothing_to_import";
    m_strings[2980] = "s_err_ugcmap_design_home_invalid_item";
    m_strings[2981] = "s_err_ugcmap_design_home_not_enough_meso";
    m_strings[2982] = "s_err_ugcmap_design_home_not_enough_merat";
    m_strings[2983] = "s_err_ugcmap_design_home_not_enough_item";
    m_strings[2984] = "s_err_ugcmap_design_home_not_enough_honor_token";
    m_strings[2985] = "s_err_ugcmap_design_home_not_enough_karma_token";
    m_strings[2986] = "s_err_ugcmap_design_home_not_enough_lu_token";
    m_strings[2987] = "s_err_ugcmap_design_home_not_enough_habi_token";
    m_strings[2988] = "s_err_ugcmap_design_home_not_enough_shard_token";
    m_strings[2989] = "s_err_ugcmap_design_home_not_enough_red_merat";
    m_strings[2990] = "s_err_ugcmap_design_home_not_enough_reverse_coin";
    m_strings[2991] = "s_err_ugcmap_design_home_not_enough_star_point";
    m_strings[2992] = "s_err_ugcmap_design_home_invalid_design_index";
    m_strings[2993] = "s_err_ugcmap_cant_save_maid";
    m_strings[2994] = "s_err_ugcmap_guide_object_cant_go_far";
    m_strings[2995] = "s_err_ugcmap_cant_find_delegate_owner";
    m_strings[2996] = "s_err_ugcmap_cant_use_clear_ugc_map";
    m_strings[2997] = "s_err_ugcmap_not_massive_event_field";
    m_strings[2998] = "s_err_ugcmap_only_owner_can_set_balance";
    m_strings[2999] = "s_err_ugcmap_meso_balance_should_be_positive_number";
    m_strings[3000] = "s_err_ugcmap_merat_balance_should_be_positive_number";
    m_strings[3001] = "s_err_ugcmap_meso_merat_balance_description";
    m_strings[3002] = "s_err_ugcmap_nothing_to_export";
    m_strings[3003] = "s_fishing_grade_Lv1";
    m_strings[3004] = "s_fishing_grade_Lv2";
    m_strings[3005] = "s_fishing_grade_Lv3";
    m_strings[3006] = "s_fishing_grade_Lv4";
    m_strings[3007] = "s_fishing_grade_Lv5";
    m_strings[3008] = "s_fishing_grade_Lv6";
    m_strings[3009] = "s_fishing_grade_Lv7";
    m_strings[3010] = "s_fishing_grade_Lv8";
    m_strings[3011] = "s_fishing_grade_Lv9";
    m_strings[3012] = "s_fishing_grade_Lv10";
    m_strings[3013] = "s_fishing_grade_Lv11";
    m_strings[3014] = "s_fishing_grade_Lv12";
    m_strings[3015] = "s_fishing_grade_Lv13";
    m_strings[3016] = "s_fishing_grade_Lv14";
    m_strings[3017] = "s_fishing_grade_Lv15";
    m_strings[3018] = "s_fishing_grade_Lv16";
    m_strings[3019] = "s_fishing_grade_Lv17";
    m_strings[3020] = "s_fishing_grade_Lv18";
    m_strings[3021] = "s_fishing_grade_Lv19";
    m_strings[3022] = "s_fishing_grade_Lv20";
    m_strings[3023] = "s_fishing_grade_Lv21";
    m_strings[3024] = "s_fishing_habitat_water";
    m_strings[3025] = "s_fishing_habitat_seawater";
    m_strings[3026] = "s_fishing_habitat_poison";
    m_strings[3027] = "s_fishing_habitat_lava";
    m_strings[3028] = "s_fishing_habitat_oil";
    m_strings[3029] = "s_fishing_habitat_devilwater";
    m_strings[3030] = "s_fishing_habitat_emeraldwater";
    m_strings[3031] = "s_fishing_habitat_all";
    m_strings[3032] = "s_fishing_notify_success";
    m_strings[3033] = "s_fishing_notify_fail";
    m_strings[3034] = "s_fishing_fish_grade";
    m_strings[3035] = "s_fishing_fish_catch_count";
    m_strings[3036] = "s_fishing_fish_size";
    m_strings[3037] = "s_fishing_error_invalid_cube";
    m_strings[3038] = "s_fishing_error_notexist_water";
    m_strings[3039] = "s_fishing_error_invalid_item";
    m_strings[3040] = "s_fishing_error_lack_mastery";
    m_strings[3041] = "s_fishing_error_notexist_fish";
    m_strings[3042] = "s_fishing_error_system_error";
    m_strings[3043] = "s_fishing_error_fishingrod_mastery";
    m_strings[3044] = "s_fishing_error_ride";
    m_strings[3045] = "s_fishing_error_inventory_full";
    m_strings[3046] = "s_fishing_error_ugcmap";
    m_strings[3047] = "s_fishing_offset_mastery";
    m_strings[3048] = "s_fishing_offset_mastery_firstcatch";
    m_strings[3049] = "s_fishing_offset_mastery_bigsizecatch";
    m_strings[3050] = "s_fishing_total_mastery";
    m_strings[3051] = "s_fishing_need_mastery";
    m_strings[3052] = "s_fishing_size_small";
    m_strings[3053] = "s_fishing_size_medium";
    m_strings[3054] = "s_fishing_size_large";
    m_strings[3055] = "s_fishing_size_bigfish";
    m_strings[3056] = "s_remake_itemoption_error";
    m_strings[3057] = "s_remake_itemoption_error_impossible";
    m_strings[3058] = "s_remake_itemoption_error_limitlevel";
    m_strings[3059] = "s_tooltip_itemoption_kinds_constant";
    m_strings[3060] = "s_tooltip_itemoption_kinds_random";
    m_strings[3061] = "s_tooltip_itemoption_kinds_space";
    m_strings[3062] = "s_tooltip_itemoption_enchant";
    m_strings[3063] = "s_tooltip_itemoption_enchant_broken";
    m_strings[3064] = "s_tooltip_itemoption_stat_row";
    m_strings[3065] = "s_tooltip_itemremake_count";
    m_strings[3066] = "s_tooltip_itemremake_enable";
    m_strings[3067] = "s_wedding_visit_confirm";
    m_strings[3068] = "s_wedding_visit_failed_common";
    m_strings[3069] = "s_wedding_visit_failed_dead";
    m_strings[3070] = "s_wedding_visit_failed_invalid_time";
    m_strings[3071] = "s_wedding_visit_failed_user_count_limit_exceeded";
    m_strings[3072] = "s_wedding_visit_failed_user_self_link";
    m_strings[3073] = "s_wedding_visit_failed_disablemap";
    m_strings[3074] = "s_wedding_visit_failed_solo_instance";
    m_strings[3075] = "s_wedding_visit_failed_same_place";
    m_strings[3076] = "s_err_wedding_chat_cannot_use_common";
    m_strings[3077] = "s_err_wedding_chat_cannot_use_no_reservation";
    m_strings[3078] = "s_err_wedding_chat_cannot_use_complete";
    m_strings[3079] = "s_anti_addiction_cannot_receive";
    m_strings[3080] = "s_auto_itemuse_default";
    m_strings[3081] = "s_auto_itemuse_condition";
    m_strings[3082] = "s_pet_input_name";
    m_strings[3083] = "s_pet_summon_on";
    m_strings[3084] = "s_pet_summon_off";
    m_strings[3085] = "s_pet_btn_summon_on";
    m_strings[3086] = "s_pet_btn_summon_off";
    m_strings[3087] = "s_pet_inventory_ask_in";
    m_strings[3088] = "s_pet_inventory_ask_out";
    m_strings[3089] = "s_pet_inventory_slot_use_count";
    m_strings[3090] = "s_pet_inventory_expire";
    m_strings[3091] = "s_pet_inventory_end_time";
    m_strings[3092] = "s_pet_inventory_not_use";
    m_strings[3093] = "s_pet_inventory_not_sendin";
    m_strings[3094] = "s_pet_inventory_not_sendin_petitem";
    m_strings[3095] = "s_pet_effect_end_time";
    m_strings[3096] = "s_pet_additional_desc_name";
    m_strings[3097] = "s_pet_change_name_free";
    m_strings[3098] = "s_pet_change_name_merat";
    m_strings[3099] = "s_pet_change_name_samename";
    m_strings[3100] = "s_pet_itemuse_cannot_not_posion";
    m_strings[3101] = "s_pet_itemuse_cannot_same_item";
    m_strings[3102] = "s_pet_itemuse_cannot_same_condition";
    m_strings[3103] = "s_pet_itemuse_cannot_notexist_condition";
    m_strings[3104] = "s_pet_itemuse_cannot_drag_user_inventory";
    m_strings[3105] = "s_pet_error_summon_potion";
    m_strings[3106] = "s_pet_extension_ontarget";
    m_strings[3107] = "s_pet_extension_period";
    m_strings[3108] = "s_pet_extension_period_limit";
    m_strings[3109] = "s_pet_extension_period_remain";
    m_strings[3110] = "s_pet_extension_period_hungry";
    m_strings[3111] = "s_pet_extension_period_not_extendlife";
    m_strings[3112] = "s_pet_nutrient_ontarget";
    m_strings[3113] = "s_pet_nutrient_period_limit";
    m_strings[3114] = "s_pet_nutrient_confirm_replace_effect";
    m_strings[3115] = "s_pet_nutrient_success";
    m_strings[3116] = "s_pet_nutrient_success_extension";
    m_strings[3117] = "s_pet_nutrient_cannot_hungry";
    m_strings[3118] = "s_usercommanddescription_user";
    m_strings[3119] = "s_usercommanddescription_tester";
    m_strings[3120] = "s_usercommanddescription_admin";
    m_strings[3121] = "s_timeevent_common_1";
    m_strings[3122] = "s_timeevent_common_4";
    m_strings[3123] = "s_timeevent_common_7";
    m_strings[3124] = "s_timestring_am";
    m_strings[3125] = "s_timestring_pm";
    m_strings[3126] = "s_skill_compact_control_add_tab";
    m_strings[3127] = "s_skill_compact_control_rename_tab";
    m_strings[3128] = "s_skill_compact_control_same_tabname";
    m_strings[3129] = "s_skill_compact_control_default_tabname";
    m_strings[3131] = "s_window_title_name";
    m_strings[3130] = "s_skill_level_max";
    m_strings[3132] = "s_crashreporter_title";
    m_strings[3133] = "s_crashreporter_text";
    m_strings[3134] = "s_gameevent_enterfield_confirm";
    m_strings[3135] = "s_card_reverse_game_consume_fail";
    m_strings[3136] = "s_card_reverse_game_select_count";
    m_strings[3137] = "s_card_reverse_game_close_message";
    m_strings[3138] = "s_card_reverse_game_reward_notice";
    m_strings[3139] = "s_rank_duel_arena_fail";
    m_strings[3140] = "s_invalid_break_skinitem";
    m_strings[3141] = "s_itemlock_unknown_err";
    m_strings[3142] = "s_itemlock_invalid_item_lock";
    m_strings[3143] = "s_itemlock_invalid_item_unlock";
    m_strings[3144] = "s_party_search_default_msg_1";
    m_strings[3145] = "s_party_search_default_msg_2";
    m_strings[3146] = "s_party_search_default_msg_3";
    m_strings[3147] = "s_party_search_default_msg_4";
    m_strings[3148] = "s_party_search_default_msg_5";
    m_strings[3149] = "s_character_ability_character_category_name";
    m_strings[3150] = "s_character_ability_monster_and_dungeon_category_name";
    m_strings[3151] = "s_character_ability_play_and_feature_category_name";
    m_strings[3152] = "s_character_ability_quest_and_grow_category_name";
    m_strings[3153] = "s_character_ability_content_category_name";
    m_strings[3154] = "s_character_ability_character_category_tooltip";
    m_strings[3155] = "s_character_ability_monster_and_dungeon_category_tooltip";
    m_strings[3156] = "s_character_ability_play_and_feature_category_tooltip";
    m_strings[3157] = "s_character_ability_quest_and_grow_category_tooltip";
    m_strings[3158] = "s_character_ability_content_category_tooltip";
    m_strings[3159] = "s_character_ability_err_no_abilitypoint";
    m_strings[3160] = "s_character_ability_err_no_meso";
    m_strings[3161] = "s_character_ability_err_no_merat";
    m_strings[3162] = "s_character_ability_point_info_text";
    m_strings[3163] = "s_character_ability_meso_reset_desc";
    m_strings[3164] = "s_character_ability_meso_reset_button";
    m_strings[3165] = "s_character_ability_merat_reset_desc";
    m_strings[3166] = "s_character_ability_merat_reset_button";
    m_strings[3167] = "s_character_ability_err_reset_cooltime";
    m_strings[3168] = "s_character_ability_disabled_quest_desc";
    m_strings[3169] = "s_character_ability_reset_cooltime";
    m_strings[3170] = "s_character_ability_reset_cooltime_request";
    m_strings[3171] = "s_character_ability_err_level_reset_cooltime";
    m_strings[3172] = "s_party_recall_scroll_buy";
    m_strings[3173] = "s_msg_autofishing_extend";
    m_strings[3174] = "s_msg_autofishing_extend_desc";
    m_strings[3175] = "s_msg_autofishing_extend_showcurrentduration_desc";
    m_strings[3176] = "s_system_shop_title_extend_autofishing";
    m_strings[3177] = "s_notice_bypass";
    m_strings[3178] = "s_notice_unstable_network_state";
    m_strings[3179] = "s_ugcmap_fun_host_gravity_change";
    m_strings[3180] = "s_ugcmap_fun_card_info_user_open";
    m_strings[3181] = "s_ugcmap_fun_card_info_user_private";
    m_strings[3182] = "s_ugcmap_fun_card_info_deck_open";
    m_strings[3183] = "s_ugcmap_fun_card_info_deck_private";
    m_strings[3184] = "s_ugcmap_fun_card_info_mine";
    m_strings[3185] = "s_ugcmap_fun_card_open_mine";
    m_strings[3188] = "s_ugcmap_fun_card_discard_mine";
    m_strings[3186] = "s_ugcmap_fun_card_discard_open";
    m_strings[3187] = "s_ugcmap_fun_card_discard_private";
    m_strings[3189] = "s_ugcmap_fun_card_verify_owned";
    m_strings[3190] = "s_ugcmap_fun_card_verify_not_owned";
    m_strings[3191] = "s_ugcmap_fun_card_handover_open";
    m_strings[3192] = "s_ugcmap_fun_card_handover_private";
    m_strings[3193] = "s_ugcmap_fun_card_handover_sender";
    m_strings[3194] = "s_ugcmap_fun_card_handover_receiver";
    m_strings[3195] = "s_ugcmap_fun_card_add";
    m_strings[3196] = "s_ugcmap_fun_card_receive_open";
    m_strings[3197] = "s_ugcmap_fun_card_receive_private";
    m_strings[3198] = "s_ugcmap_fun_card_receive_mine";
    m_strings[3199] = "s_ugcmap_fun_card_deck_not_exist";
    m_strings[3200] = "s_ugcmap_fun_card_deck_reset";
    m_strings[3201] = "s_ugcmap_fun_card_deck_reset_empty";
    m_strings[3202] = "s_ugcmap_fun_card_not_exist";
    m_strings[3203] = "s_ugcmap_fun_card_empty_in_deck";
    m_strings[3204] = "s_ugcmap_fun_card_too_many_in_deck";
    m_strings[3205] = "s_ugcmap_fun_card_target_not_exist";
    m_strings[3206] = "s_ugcmap_fun_card_deck_name_empty";
    m_strings[3207] = "s_ugcmap_fun_card_deck_name_invalid";
    m_strings[3208] = "s_ugcmap_fun_card_deck_too_many";
    m_strings[3209] = "s_ugcmap_fun_card_deck_exist_already";
    m_strings[3210] = "s_ugcmap_fun_card_deck_is_permanent";
    m_strings[3211] = "s_ugcmap_fun_card_deck_add";
    m_strings[3212] = "s_ugcmap_fun_card_deck_discard";
    m_strings[3213] = "s_ugcmap_fun_survey_open";
    m_strings[3214] = "s_ugcmap_fun_survey_secret";
    m_strings[3215] = "s_ugcmap_fun_survey_abstention";
    m_strings[3216] = "s_ugcmap_fun_survey_guide";
    m_strings[3217] = "s_ugcmap_fun_survey_info_head";
    m_strings[3218] = "s_ugcmap_fun_survey_info_footer";
    m_strings[3219] = "s_ugcmap_fun_survey_create_success";
    m_strings[3220] = "s_ugcmap_fun_survey_create_error";
    m_strings[3221] = "s_ugcmap_fun_survey_add_success";
    m_strings[3222] = "s_ugcmap_fun_survey_add_error";
    m_strings[3223] = "s_ugcmap_fun_survey_start";
    m_strings[3224] = "s_ugcmap_fun_survey_vote";
    m_strings[3225] = "s_ugcmap_fun_survey_end";
    m_strings[3226] = "s_ugcmap_fun_survey_result";
    m_strings[3227] = "s_ugcmap_fun_survey_close_without_vote";
    m_strings[3228] = "s_ugcmap_fun_portal_name_duplicated";
    m_strings[3229] = "s_ugcmap_fun_roll";
    m_strings[3230] = "s_ugcmap_fun_roll_error";
    m_strings[3231] = "s_ugcmap_fun_random_group";
    m_strings[3232] = "s_ugcmap_fun_random_pick";
    m_strings[3233] = "s_ugcmap_fun_random_pick_special";
    m_strings[3234] = "s_ugcmap_fun_typing_ready";
    m_strings[3235] = "s_ugcmap_fun_typing_begin";
    m_strings[3236] = "s_ugcmap_fun_typing_submit";
    m_strings[3237] = "s_ugcmap_fun_typing_end";
    m_strings[3238] = "s_ugcmap_fun_typing_ranking";
    m_strings[3239] = "s_ugcmap_fun_pvp_ffa_finished";
    m_strings[3240] = "s_ugcmap_fun_pvp_ffa_finished_draw";
    m_strings[3241] = "s_ugcmap_fun_pvp_ffa_winnter_name";
    m_strings[3242] = "s_ugcmap_cant_extend_area_level_anymore";
    m_strings[3243] = "s_ugcmap_cant_extend_height_level_anymore";
    m_strings[3244] = "s_ugcmap_cube_lock";
    m_strings[3245] = "s_ugcmap_cant_additionalbuy";
    m_strings[3246] = "s_ugcmap_admin_only";
    m_strings[3247] = "s_ugcmap_not_allowed_item";
    m_strings[3248] = "s_err_ugcmap_not_enough_meso_balance";
    m_strings[3249] = "s_err_ugcmap_not_enough_merat_balance";
    m_strings[3250] = "s_err_ugcmap_cant_find_delegator_in_this_map";
    m_strings[3251] = "s_err_ugcmap_cant_full_delegator_user";
    m_strings[3252] = "s_err_ugcmap_cant_duplicate_delegator_in_this_map";
    m_strings[3253] = "s_err_ugcmap_cant_build_empty_ugc";
    m_strings[3254] = "s_err_ugcmap_should_use_in_home";
    m_strings[3255] = "s_err_ugcmap_construct_exp_overtime";
    m_strings[3256] = "s_ugcmap_add_delegator_user";
    m_strings[3257] = "s_ugcmap_remove_delegator_user";
    m_strings[3258] = "s_ugcmap_give_delegator_user";
    m_strings[3259] = "s_ugcmap_release_delegator_user";
    m_strings[3260] = "s_ugcmap_removeall_delegator_user";
    m_strings[3261] = "s_err_ugcmap_blueprint_preview_cube_action_disabled";
    m_strings[3262] = "s_home_today_reward";
    m_strings[3263] = "s_home_bill_description";
    m_strings[3264] = "s_home_interior_grade_gift_taken";
    m_strings[3265] = "s_platform_common_error_unknown_error_code";
    m_strings[3266] = "s_platform_common_error_unknown";
    m_strings[3267] = "s_platform_common_error_invalid_param";
    m_strings[3268] = "s_platform_common_error_not_initialize";
    m_strings[3269] = "s_platform_common_error_unstable_install";
    m_strings[3270] = "s_platform_common_error_unstable_install_path";
    m_strings[3271] = "s_platform_common_error_unstable_install_data";
    m_strings[3272] = "s_gamehelper_game_optimize_apply";
    m_strings[3273] = "s_gamehelper_voice_chat_enter";
    m_strings[3274] = "s_gamehelper_voice_chat_leave";
    m_strings[3275] = "s_vip_coupon_extend_msg";
    m_strings[3276] = "s_vip_coupon_new_msg";
    m_strings[3277] = "s_word_tab_petinfo";
    m_strings[3278] = "s_word_tab_petcompose";
    m_strings[3279] = "s_word_tab_petevolution";
    m_strings[3280] = "s_word_tab_petcollect";
    m_strings[3281] = "s_word_tab_remakeoption";
    m_strings[3282] = "s_char_input_itemname";
    m_strings[3283] = "s_timeevent_boss_lifetimetext1";
    m_strings[3284] = "s_timeevent_boss_lifetimetext2";
    m_strings[3285] = "s_word_pet";
    m_strings[3286] = "s_word_battle_pet";
    m_strings[3287] = "s_live_broadcast_system_error";
    m_strings[3289] = "s_ugcox_host_commission_meso_get";
    m_strings[3288] = "s_ugcox_create_portal";
    m_strings[3290] = "s_ugcox_entry_prize_meso_get";
    m_strings[3291] = "s_ugcox_entry_fee_refund_meso_get";
    m_strings[3292] = "s_ugcox_enter_fail_full";
    m_strings[3301] = "s_couple_emotion_request_recv";
    m_strings[3302] = "s_couple_emotion_request_success";
    m_strings[3303] = "s_couple_emotion_failed";
    m_strings[3304] = "s_couple_emotion_response_accept";
    m_strings[3305] = "s_couple_emotion_response_decline";
    m_strings[3306] = "s_couple_emotion_target_user_wrong_position";
    m_strings[3307] = "s_couple_emotion_recv_request_in_progressed";
    m_strings[3293] = "s_couple_effect_error_openbox_unknown";
    m_strings[3294] = "s_couple_effect_error_openbox_charname";
    m_strings[3295] = "s_couple_effect_error_openbox_myself_char";
    m_strings[3296] = "s_couple_effect_error_openbox_myself_account";
    m_strings[3297] = "s_couple_effect_mail_sender";
    m_strings[3298] = "s_couple_effect_mail_title_receiver";
    m_strings[3299] = "s_couple_effect_mail_content_receiver";
    m_strings[3300] = "s_couple_effect_mail_send_partner";
    m_strings[3314] = "s_couple_emotion_failed_request_not_exist_skill";
    m_strings[3315] = "s_couple_emotion_failed_accept_request_user_wrong_state";
    m_strings[3316] = "s_couple_emotion_failed_request_already_recv";
    m_strings[3317] = "s_couple_emotion_failed_request_already_in_action";
    m_strings[3320] = "s_couple_emotion_failed_accept_cannot_find_request_user";
    m_strings[3321] = "s_couple_emotion_failed_teleport_limit_distance";
    m_strings[3322] = "s_couple_emotion_failed_response_wrong_state_target_user";
    m_strings[3308] = "s_couple_emotion_cannot_request_wrong_state";
    m_strings[3309] = "s_couple_emotion_cannot_request_already_in_recv_state";
    m_strings[3311] = "s_couple_emotion_cannot_request_blocked_target";
    m_strings[3310] = "s_couple_emotion_cannot_request_long_distance";
    m_strings[3312] = "s_couple_emotion_cannot_request_in_this_map";
    m_strings[3313] = "s_couple_emotion_cannot_response_not_exist_request_user";
    m_strings[3318] = "s_couple_emotion_failed_requset_auto_decline";
    m_strings[3319] = "s_couple_emotion_failed_request_wrong_state_target_user";
    m_strings[3323] = "s_galleryevent_cannot_open_card";
    m_strings[3324] = "s_galleryevent_invalid_event";
    m_strings[3325] = "s_microgame_rps_open_banner_failed_not_exist_ticket";
    m_strings[3326] = "s_microgame_rps_open_banner_failed_action_key";
    m_strings[3327] = "s_microgame_rps_open_banner_failed_wrong_state";
    m_strings[3328] = "s_microgame_rps_request_failed_not_exist_ticket";
    m_strings[3329] = "s_microgame_rps_request_failed_wrong_distance";
    m_strings[3330] = "s_microgame_rps_request_failed_wrong_position";
    m_strings[3331] = "s_microgame_rps_request_failed_wrong_state";
    m_strings[3332] = "s_microgame_rps_request_cancel";
    m_strings[3333] = "s_microgame_rps_peer_game_cancel";
    m_strings[3334] = "s_microgame_rps_banner_failed_blocked_in_this_field";
    m_strings[3335] = "s_microgame_rps_request_failed_blocked_in_this_field";
    m_strings[3336] = "s_microgame_rps_request_failed_blocked_user";
    m_strings[3337] = "s_microgame_rps_response_failed_blocked_user";
    m_strings[3338] = "s_microgame_rps_request_failed_peer_wrong_state";
    m_strings[3339] = "s_microgame_rps_accept_failed_peer_wrong_state";
    m_strings[3340] = "s_microgame_rps_close";
    m_strings[3341] = "s_microgame_rps_waiting";
    m_strings[3342] = "s_microgame_rps_request_recv";
    m_strings[3343] = "s_microgame_rps_response_decline";
    m_strings[3344] = "s_microgame_rps_response_accept";
    m_strings[3345] = "s_microgame_rps_failed";
    m_strings[3346] = "s_microgame_rps_result_win";
    m_strings[3347] = "s_microgame_rps_result_lose";
    m_strings[3348] = "s_microgame_rps_result_draw";
    m_strings[3349] = "s_survival_event_reduce_safezone_ready";
    m_strings[3350] = "s_survival_event_reduce_safezone_start";
    m_strings[3351] = "s_function_item_survival_scan_info";
    m_strings[3352] = "s_function_item_survival_scan_announce";
    m_strings[3353] = "s_treewatering_watering";
    m_strings[3354] = "s_treewatering_emotion";
    m_strings[3355] = "s_treewatering_watering_casting";
    m_strings[3356] = "s_treewatering_emotion_casting";
    m_strings[3357] = "s_treewatering_wateringreward";
    m_strings[3358] = "s_treewatering_emotionreward";
    m_strings[3359] = "s_treewatering_no_waterpot";
    m_strings[3360] = "s_treewatering_nomore_watering_reward";
    m_strings[3361] = "s_treewatering_nomore_emotion_reward";
    m_strings[3362] = "s_notify_adventure_levelup";
    m_strings[3363] = "s_cashshop_err_purchase_steam_restircted_country";
    m_strings[3364] = "s_cashshop_err_purchase_product_info_expired";
    m_strings[3365] = "s_closet_msg_success";
    m_strings[3366] = "s_closet_msg_item_not_exist";
    m_strings[3367] = "s_closet_msg_item_failed";
    m_strings[3368] = "s_socket_error_common";
    m_strings[3369] = "s_socket_error_10004";
    m_strings[3370] = "s_socket_error_10013";
    m_strings[3371] = "s_socket_error_10014";
    m_strings[3372] = "s_socket_error_10022";
    m_strings[3373] = "s_socket_error_10024";
    m_strings[3374] = "s_socket_error_10035";
    m_strings[3375] = "s_socket_error_10036";
    m_strings[3376] = "s_socket_error_10037";
    m_strings[3377] = "s_socket_error_10039";
    m_strings[3378] = "s_socket_error_10040";
    m_strings[3379] = "s_socket_error_10048";
    m_strings[3380] = "s_socket_error_10050";
    m_strings[3381] = "s_socket_error_10051";
    m_strings[3382] = "s_socket_error_10052";
    m_strings[3383] = "s_socket_error_10053";
    m_strings[3384] = "s_socket_error_10054";
    m_strings[3385] = "s_socket_error_10055";
    m_strings[3386] = "s_socket_error_10056";
    m_strings[3387] = "s_socket_error_10058";
    m_strings[3388] = "s_socket_error_10060";
    m_strings[3389] = "s_socket_error_10061";
    m_strings[3390] = "s_socket_error_10064";
    m_strings[3391] = "s_socket_error_10065";
    m_strings[3392] = "s_socket_error_10067";
    m_strings[3393] = "s_socket_error_10101";
    m_strings[3394] = "s_socket_error_11001";
    m_strings[3395] = "s_socket_error_11002";
    m_strings[3396] = "s_steam_purchase_restriction_adventure_level";
    m_strings[3397] = "s_steam_purchase_restriction_character_level";
    m_strings[3398] = "s_steam_purchase_restriction_account_create_days";
    m_strings[3399] = "s_common_block_for_spamer_not_enough_max_level";
    m_strings[3400] = "s_common_block_for_spamer_not_enough_adventure_level";
    m_strings[3401] = "s_wedding_mail_title_receiver";
    m_strings[3402] = "s_wedding_mail_contents_receiver";
    m_strings[3403] = "s_wedding_mail_change_title_receiver";
    m_strings[3404] = "s_wedding_mail_change_contents_receiver";
    m_strings[3405] = "s_wedding_mail_cancel_title_receiver";
    m_strings[3406] = "s_wedding_mail_cancel_contents_receiver";
    m_strings[3407] = "s_payback_error_reward_time";
    m_strings[3408] = "s_hideandseek_remain_user";
    m_strings[3409] = "s_itemgacha_dialog_title";
    m_strings[3410] = "s_itemgacha_dialog_gacha_type_skin";
    m_strings[3411] = "s_itemgacha_dialog_gacha_type_look";
    m_strings[3412] = "s_itemgacha_dialog_gacha_type_specup";
    m_strings[3413] = "s_itemgacha_dialog_gacha_type_special";
    m_strings[3414] = "s_adventure_protect_err";
    m_strings[3415] = "s_home_block_somebody";
    m_strings[3416] = "s_home_block_del_somebody_from_banlist";
    m_strings[3417] = "s_home_block_memo_complete";
    m_strings[3418] = "s_home_block_err_unknown";
    m_strings[3419] = "s_home_block_err_no_user";
    m_strings[3420] = "s_home_block_err_self_block";
    m_strings[3421] = "s_home_block_err_already_block";
    m_strings[3422] = "s_home_block_err_max_block";
    m_strings[3423] = "s_home_block_err_enterance_block";
    m_strings[3424] = "s_home_block_err_kick";
    m_strings[3425] = "s_pc_info_name_shield";
}

// @0x140259340
int CommonString::LoadCommon()
{
    TextMap& map = m_maps[0];
    CString strPath = FUN_14071ae20("stringCommon.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        return 0;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CStringW strId = FUN_1401bf530(pNode, "id", CStringW(L""));
        CStringW strValue = FUN_1401bf530(pNode, "value", CStringW(L""));
        strValue.Replace(L"\\n", L"\n");
        map.SetAt(strId, strValue);
    }
    FUN_1401d1160(CString(strPath));
    return 1;
}

// @0x140259640
bool CommonString::LoadDebug()
{
    TextMap& map = m_maps[0];
    CString strPath = FUN_140cc2a00("../XmlDebug", "stringDebug.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        return false;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        CStringW strId = FUN_1401bf530(pNode, "id", CStringW(L""));
        CStringW strValue = FUN_1401bf530(pNode, "value", CStringW(L""));
        strValue.Replace(L"\\n", L"\n");
        map.SetAt(strId, strValue);
    }
    return true;
}

// @0x140259910
int CommonString::FUN_140259910()
{
    return 1;
}

// @0x140259930
void CommonString::Reload()
{
    TextMap* maps = m_maps;
    for (unsigned i = 0; i < 2; ++i)
    {
        TextMap* pMap = maps + (int)i;
        pMap->RemoveAll();
    }
    LoadCommon();
    FUN_140259910();
    LoadDebug();
    m_spChecker->LoadTables();
    SetInit(true);
}

// @0x140259e60
void CommonString::LoadStrings(Unk_140165cf0* pRoot)
{
    TextMap& map = m_maps[0];
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CStringW strId = FUN_1401bf530(pNode, "id", CStringW(L""));
        CStringW strValue = FUN_1401bf530(pNode, "value", CStringW(L""));
        if (!strId.IsEmpty())
        {
            strValue.Replace(L"\\n", L"\n");
            map.SetAt(strId, strValue);
        }
    }
}

// @0x14025d6f0
void CBanTextChecker::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CBanTextChecker).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140263710
void CBanTextChecker::SetInit(bool bInit)
{
    s_bInit = bInit;
}

// @0x14025d7a0
void CommonString::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CommonString).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140263720
void CommonString::SetInit(bool bInit)
{
    s_bInit = bInit;
}


// ---- hooks (byte-exact members that do not read the unit's mutable statics) ----
MS2_REPLACE_METHOD(0x140223DC0, TextFilterUnit, GetChar, 15, 0x5AC51DCC);
MS2_REPLACE_METHOD(0x140223FE0, TextFilterUnit, Find, 384, 0x77FB699A);
MS2_REPLACE_METHOD(0x140224170, TextFilterUnit, Clear, 31, 0x14AA08D7);
MS2_REPLACE_METHOD(0x1402241A0, TextFilterUnit, GetChildCount, 31, 0x597A3807);
MS2_REPLACE_METHOD(0x1402241D0, TextFilterUnit, Match, 349, 0xCFDAE958);
MS2_REPLACE_METHOD(0x140224340, TextFilterUnit, IsTagStart, 49, 0xF8F833AF);
MS2_REPLACE_METHOD(0x140224380, TextFilterUnit, SkipTag, 166, 0x9398CF96);
MS2_REPLACE_METHOD(0x140229220, CBanTextChecker, FUN_140229220, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140227890, CBanTextChecker, ClearTries, 145, 0x9B3C9039);
MS2_REPLACE_METHOD(0x140224F80, CBanTextChecker, HasStartWithWords, 78, 0x43438119);
MS2_REPLACE_METHOD(0x140224FE0, CBanTextChecker, IsAlnumName, 305, 0x9686387E);
MS2_REPLACE_METHOD(0x140225120, CBanTextChecker, FUN_140225120, 224, 0xFCE38FF3);
MS2_REPLACE_METHOD(0x140225210, CBanTextChecker, FUN_140225210, 216, 0xE33FE7DC);
MS2_REPLACE_METHOD(0x1402252F0, CBanTextChecker, FUN_1402252f0, 176, 0x88FCA6B1);
MS2_REPLACE_METHOD(0x1402253B0, CBanTextChecker, FUN_1402253b0, 173, 0x09FEAF57);
MS2_REPLACE_METHOD(0x140225470, CBanTextChecker, FUN_140225470, 216, 0xE1731069);
MS2_REPLACE_METHOD(0x140225550, CBanTextChecker, FUN_140225550, 216, 0x29173518);
MS2_REPLACE_METHOD(0x140225630, CBanTextChecker, FUN_140225630, 224, 0x4D5BA48F);
MS2_REPLACE_METHOD(0x140225720, CBanTextChecker, FUN_140225720, 224, 0x2840BD6F);
MS2_REPLACE_METHOD(0x140225810, CBanTextChecker, FUN_140225810, 211, 0x36F09730);
MS2_REPLACE_METHOD(0x1402258F0, CBanTextChecker, FUN_1402258f0, 176, 0x8AC2EC42);
MS2_REPLACE_METHOD(0x1402259B0, CBanTextChecker, FUN_1402259b0, 176, 0xC7A7B0EF);
MS2_REPLACE_METHOD(0x140225A70, CBanTextChecker, FUN_140225a70, 533, 0x4789474A);
MS2_REPLACE_METHOD(0x140225C90, CBanTextChecker, FUN_140225c90, 322, 0x5177F359);
MS2_REPLACE_METHOD(0x140225DE0, CBanTextChecker, FUN_140225de0, 322, 0x416B8E3D);
MS2_REPLACE_METHOD(0x140225F70, CBanTextChecker, FUN_140225f70, 322, 0x1BB88BF2);
MS2_REPLACE_METHOD(0x140226440, CBanTextChecker, FUN_140226440, 322, 0xFE4EB06B);
MS2_REPLACE_METHOD(0x140226590, CBanTextChecker, FUN_140226590, 322, 0x92FA53AE);
MS2_REPLACE_METHOD(0x1402266E0, CBanTextChecker, FUN_1402266e0, 322, 0x659E94EA);
MS2_REPLACE_METHOD(0x140226830, CBanTextChecker, FUN_140226830, 322, 0x83ADDA52);
MS2_REPLACE_METHOD(0x140225F30, CBanTextChecker, FUN_140225f30, 58, 0xAF657D4B);
MS2_REPLACE_METHOD(0x1402260C0, CBanTextChecker, FUN_1402260c0, 58, 0xBB338219);
MS2_REPLACE_METHOD(0x1402261E0, CBanTextChecker, FUN_1402261e0, 58, 0xD69737A8);
MS2_REPLACE_METHOD(0x140226220, CBanTextChecker, FUN_140226220, 58, 0x63305908);
MS2_REPLACE_METHOD(0x140226260, CBanTextChecker, FUN_140226260, 58, 0x75DD8167);
MS2_REPLACE_METHOD(0x1402262A0, CBanTextChecker, FUN_1402262a0, 58, 0xA084B6AF);
MS2_REPLACE_METHOD(0x1402262E0, CBanTextChecker, FUN_1402262e0, 58, 0x2D31E9E7);
MS2_REPLACE_METHOD(0x140226400, CBanTextChecker, FUN_140226400, 58, 0xA1F0E4A6);
MS2_REPLACE_METHOD(0x140226100, CBanTextChecker, FUN_140226100, 90, 0x0415F78B);
MS2_REPLACE_METHOD(0x140226160, CBanTextChecker, FUN_140226160, 111, 0x679211E4);
MS2_REPLACE_METHOD(0x140226320, CBanTextChecker, FUN_140226320, 204, 0x7A9039D6);
MS2_REPLACE_METHOD(0x140227FB0, CBanTextChecker, CheckTextWithLimit, 201, 0x12BA3C46);
MS2_REPLACE_METHOD(0x140228080, CBanTextChecker, CheckTypes, 125, 0xBCBD8433);
MS2_REPLACE_METHOD(0x1402271A0, CBanTextChecker, SetBanWords, 215, 0x174E9D70);
MS2_REPLACE_METHOD(0x140227280, CBanTextChecker, RemoveBanWords, 41, 0xDEB9B3F6);
MS2_REPLACE_METHOD(0x140228740, CBanTextChecker, BuildUrlHashes, 308, 0xD24ECED3);
MS2_REPLACE_METHOD(0x140228880, CBanTextChecker, ReplaceUrlsWithHashes, 222, 0xAF1E4F1C);
MS2_REPLACE_METHOD(0x140228970, CBanTextChecker, ReplaceHashesWithUrls, 222, 0x9417CD7A);
MS2_REPLACE_METHOD(0x140226980, CBanTextChecker, MaskBannedWords, 385, 0xC7374C85);
MS2_REPLACE_METHOD(0x1402295B0, CommonString, GetNarrowDefault, 68, 0x66E9412D);
MS2_REPLACE_METHOD(0x140229600, CommonString, GetNarrow, 130, 0x6A0BF3EA);
MS2_REPLACE_METHOD(0x140229690, CommonString, GetNarrowByKey, 187, 0x89D93563);
MS2_REPLACE_METHOD(0x140229940, CommonString, FUN_140229940, 71, 0x8E6E398A);
MS2_REPLACE_METHOD(0x140229A50, CommonString, GetChecker, 105, 0xDA7A8C8F);
MS2_REPLACE_METHOD(0x140259340, CommonString, LoadCommon, 752, 0xAFDA9937);
MS2_REPLACE_METHOD(0x140259640, CommonString, LoadDebug, 699, 0x7F19123D);
MS2_REPLACE_METHOD(0x140259910, CommonString, FUN_140259910, 11, 0x30025ED0);
MS2_REPLACE_METHOD(0x140259E60, CommonString, LoadStrings, 364, 0xBDFDA64C);
