// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Common enum conversions: string <-> enum parsers/namers
// used by the table loaders (grade, exp categories, block types ...). Free-function names are invented from the VA.
// MS2-UNIT: commonfiles\commonenum.cpp
// MS2-RANGE: 0x1400b48f0-0x1400b53d0 .text$di
// MS2-RANGE: 0x140217910-0x1402226b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??8ATL@@YA_NPEB_WAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@0@@Z 0x140220db0 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14021c950 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@1@$$QEA_N@Z 0x14021c980 ; prop
// MS2-PIN: ??$?0AEAY04$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY04$$CBD$$QEAH@Z 0x14021ca20 ; probe
// MS2-PIN: ??$?0AEAY05$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY05$$CBD$$QEAH@Z 0x14021ca70 ; order
// MS2-PIN: ??$?0AEAY06$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY06$$CBD$$QEAH@Z 0x14021cac0 ; order
// MS2-PIN: ??$?0AEAY07$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY07$$CBD$$QEAH@Z 0x14021cb10 ; order
// MS2-PIN: ??$?0AEAY08$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY08$$CBD$$QEAH@Z 0x14021cbb0 ; order
// MS2-PIN: ??$?0AEAY08$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY08$$CBD$$QEAI@Z 0x14021cb60 ; prop
// MS2-PIN: ??$?0AEAY09$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY09$$CBD$$QEAH@Z 0x14021cc50 ; order
// MS2-PIN: ??$?0AEAY09$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY09$$CBD$$QEAI@Z 0x14021cc00 ; prop
// MS2-PIN: ??$?0AEAY0BA@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0BA@$$CBD$$QEAH@Z 0x14021ccf0 ; order
// MS2-PIN: ??$?0AEAY0BA@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BA@$$CBD$$QEAI@Z 0x14021cca0 ; prop
// MS2-PIN: ??$?0AEAY0BB@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0BB@$$CBD$$QEAH@Z 0x14021cd90 ; order
// MS2-PIN: ??$?0AEAY0BB@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BB@$$CBD$$QEAI@Z 0x14021cd40 ; prop
// MS2-PIN: ??$?0AEAY0BC@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0BC@$$CBD$$QEAH@Z 0x14021ce30 ; order
// MS2-PIN: ??$?0AEAY0BC@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BC@$$CBD$$QEAI@Z 0x14021cde0 ; prop
// MS2-PIN: ??$?0AEAY0BD@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0BD@$$CBD$$QEAH@Z 0x14021ced0 ; order
// MS2-PIN: ??$?0AEAY0BD@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BD@$$CBD$$QEAI@Z 0x14021ce80 ; prop
// MS2-PIN: ??$?0AEAY0BE@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0BE@$$CBD$$QEAH@Z 0x14021cf70 ; order
// MS2-PIN: ??$?0AEAY0BE@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BE@$$CBD$$QEAI@Z 0x14021cf20 ; prop
// MS2-PIN: ??$?0AEAY0BF@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BF@$$CBD$$QEAI@Z 0x14021cfc0 ; prop
// MS2-PIN: ??$?0AEAY0BG@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BG@$$CBD$$QEAI@Z 0x14021d010 ; prop
// MS2-PIN: ??$?0AEAY0BH@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0BH@$$CBD$$QEAH@Z 0x14021d100 ; order
// MS2-PIN: ??$?0AEAY0BH@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BH@$$CBD$$QEAI@Z 0x14021d0b0 ; prop
// MS2-PIN: ??$?0AEAY0BI@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BI@$$CBD$$QEAI@Z 0x14021d150 ; prop
// MS2-PIN: ??$?0AEAY0BK@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0BK@$$CBD$$QEAI@Z 0x14021d1a0 ; prop
// MS2-PIN: ??$?0AEAY0L@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0L@$$CBD$$QEAI@Z 0x14021d1f0 ; prop
// MS2-PIN: ??$?0AEAY0M@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0M@$$CBD$$QEAH@Z 0x14021d2e0 ; order
// MS2-PIN: ??$?0AEAY0M@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0M@$$CBD$$QEAI@Z 0x14021d290 ; prop
// MS2-PIN: ??$?0AEAY0N@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0N@$$CBD$$QEAH@Z 0x14021d380 ; order
// MS2-PIN: ??$?0AEAY0N@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0N@$$CBD$$QEAI@Z 0x14021d330 ; prop
// MS2-PIN: ??$?0AEAY0O@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0O@$$CBD$$QEAH@Z 0x14021d420 ; order
// MS2-PIN: ??$?0AEAY0O@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0O@$$CBD$$QEAI@Z 0x14021d3d0 ; prop
// MS2-PIN: ??$?0AEAY0P@$$CBDH$0A@@?$pair@PEBDH@std@@QEAA@AEAY0P@$$CBD$$QEAH@Z 0x14021d4c0 ; order
// MS2-PIN: ??$?0AEAY0P@$$CBDI$0A@@?$pair@PEBDI@std@@QEAA@AEAY0P@$$CBD$$QEAI@Z 0x14021d470 ; prop
// MS2-PIN: ??$?0AEBUCommonEnumNoCaseLess@@U_Zero_then_variadic_args_t@std@@@?$_Compressed_pair@UCommonEnumNoCaseLess@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@std@@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBUCommonEnumNoCaseLess@@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14021d510 ; unique
// MS2-PIN: ??$?0PEBDI$0A@@?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@QEAA@$$QEAU?$pair@PEBDI@1@@Z 0x14021d630 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@1@$$QEA_N@Z 0x14021d6e0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@$$QEAV?$tuple@$$V@1@@Z 0x14021d810 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@PEBDI@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@1@$$QEAU?$pair@PEBDI@1@@Z 0x14021d8e0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@1@PEAU01@@Z 0x14021d970 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@1@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@1@1@Z 0x14021da00 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@1@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@1@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@1@@Z 0x14021dd60 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@1@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@1@@Z 0x14021e9a0 ; unique
// MS2-PIN: ??$_Try_emplace@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@$$V@?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@_N@1@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x14021ee60 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@0@AEAPEAU10@@Z 0x14021efb0 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@YAPEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@0@AEAU10@@Z 0x14021efc0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@0@AEAV10@@Z 0x14021efd0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@1@AEAPEAU31@@Z 0x14021efe0 ; unique
// MS2-PIN: ??$destroy@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@1@QEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@1@@Z 0x14021f140 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@0@AEAPEAU10@@Z 0x14021f270 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@YAAEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@0@AEAU10@@Z 0x14021f280 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@0@AEAV10@@Z 0x14021f290 ; prop
// MS2-PIN: ??$forward@AEAY04$$CBD@std@@YAAEAY04$$CBDAEAY04$$CBD@Z 0x14021f2b0 ; order
// MS2-PIN: ??$forward@AEAY0O@$$CBD@std@@YAAEAY0O@$$CBDAEAY0O@$$CBD@Z 0x14021f2b0 ; order
// MS2-PIN: ??$forward@AEBUCommonEnumNoCaseLess@@@std@@YAAEBUCommonEnumNoCaseLess@@AEBU1@@Z 0x14021f2d0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@0@AEAV10@@Z 0x14021f310 ; prop
// MS2-PIN: ??$forward@I@std@@YA$$QEAIAEAI@Z 0x14021f330 ; prop
// MS2-PIN: ??$forward@H@std@@YA$$QEAHAEAH@Z 0x14021f340 ; prop
// MS2-PIN: ??$make_pair@AEAY04$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY04$$CBD$$QEAH@Z 0x14021f430 ; probe
// MS2-PIN: ??$make_pair@AEAY05$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY05$$CBD$$QEAH@Z 0x14021f480 ; order
// MS2-PIN: ??$make_pair@AEAY06$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY06$$CBD$$QEAH@Z 0x14021f4d0 ; order
// MS2-PIN: ??$make_pair@AEAY07$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY07$$CBD$$QEAH@Z 0x14021f520 ; order
// MS2-PIN: ??$make_pair@AEAY08$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY08$$CBD$$QEAH@Z 0x14021f5c0 ; order
// MS2-PIN: ??$make_pair@AEAY08$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY08$$CBD$$QEAI@Z 0x14021f570 ; unique
// MS2-PIN: ??$make_pair@AEAY09$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY09$$CBD$$QEAH@Z 0x14021f660 ; order
// MS2-PIN: ??$make_pair@AEAY09$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY09$$CBD$$QEAI@Z 0x14021f610 ; unique
// MS2-PIN: ??$make_pair@AEAY0BA@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0BA@$$CBD$$QEAH@Z 0x14021f700 ; order
// MS2-PIN: ??$make_pair@AEAY0BA@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BA@$$CBD$$QEAI@Z 0x14021f6b0 ; unique
// MS2-PIN: ??$make_pair@AEAY0BB@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0BB@$$CBD$$QEAH@Z 0x14021f7a0 ; order
// MS2-PIN: ??$make_pair@AEAY0BB@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BB@$$CBD$$QEAI@Z 0x14021f750 ; unique
// MS2-PIN: ??$make_pair@AEAY0BC@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0BC@$$CBD$$QEAH@Z 0x14021f840 ; order
// MS2-PIN: ??$make_pair@AEAY0BC@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BC@$$CBD$$QEAI@Z 0x14021f7f0 ; unique
// MS2-PIN: ??$make_pair@AEAY0BD@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0BD@$$CBD$$QEAH@Z 0x14021f8e0 ; order
// MS2-PIN: ??$make_pair@AEAY0BD@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BD@$$CBD$$QEAI@Z 0x14021f890 ; unique
// MS2-PIN: ??$make_pair@AEAY0BE@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0BE@$$CBD$$QEAH@Z 0x14021f980 ; order
// MS2-PIN: ??$make_pair@AEAY0BE@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BE@$$CBD$$QEAI@Z 0x14021f930 ; unique
// MS2-PIN: ??$make_pair@AEAY0BF@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BF@$$CBD$$QEAI@Z 0x14021f9d0 ; unique
// MS2-PIN: ??$make_pair@AEAY0BG@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BG@$$CBD$$QEAI@Z 0x14021fa20 ; unique
// MS2-PIN: ??$make_pair@AEAY0BH@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0BH@$$CBD$$QEAH@Z 0x14021fb10 ; order
// MS2-PIN: ??$make_pair@AEAY0BH@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BH@$$CBD$$QEAI@Z 0x14021fac0 ; unique
// MS2-PIN: ??$make_pair@AEAY0BI@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BI@$$CBD$$QEAI@Z 0x14021fb60 ; unique
// MS2-PIN: ??$make_pair@AEAY0BK@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0BK@$$CBD$$QEAI@Z 0x14021fbb0 ; unique
// MS2-PIN: ??$make_pair@AEAY0L@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0L@$$CBD$$QEAI@Z 0x14021fc00 ; unique
// MS2-PIN: ??$make_pair@AEAY0M@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0M@$$CBD$$QEAH@Z 0x14021fcf0 ; order
// MS2-PIN: ??$make_pair@AEAY0M@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0M@$$CBD$$QEAI@Z 0x14021fca0 ; unique
// MS2-PIN: ??$make_pair@AEAY0N@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0N@$$CBD$$QEAH@Z 0x14021fd90 ; order
// MS2-PIN: ??$make_pair@AEAY0N@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0N@$$CBD$$QEAI@Z 0x14021fd40 ; unique
// MS2-PIN: ??$make_pair@AEAY0O@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0O@$$CBD$$QEAH@Z 0x14021fe30 ; order
// MS2-PIN: ??$make_pair@AEAY0O@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0O@$$CBD$$QEAI@Z 0x14021fde0 ; unique
// MS2-PIN: ??$make_pair@AEAY0P@$$CBDH@std@@YA?AU?$pair@PEBDH@0@AEAY0P@$$CBD$$QEAH@Z 0x14021fed0 ; order
// MS2-PIN: ??$make_pair@AEAY0P@$$CBDI@std@@YA?AU?$pair@PEBDI@0@AEAY0P@$$CBD$$QEAI@Z 0x14021fe80 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@1@@Z 0x14021ffe0 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEAA@XZ 0x140220020 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@1@@Z 0x140220040 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@1@@Z 0x140220080 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x1402200c0 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@QEAA@XZ 0x1402200e0 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@QEAA@XZ 0x140220110 ; prop
// MS2-PIN: ??1?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@QEAA@XZ 0x140220d50 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140220d70 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140220df0 ; unique
// MS2-PIN: ??A?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@QEAAAEAIAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x140220e30 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@1@XZ 0x140220e70 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@1@XZ 0x140220e90 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140220ed0 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140220f40 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140220fd0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140220ff0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140221010 ; unique
// MS2-PIN: ??_G?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@QEAAPEAXI@Z 0x140221130 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@XZ 0x140221170 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@XZ 0x140221230 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@@Z 0x140221380 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@@Z 0x1402213d0 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@2@@Z 0x140221470 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@@Z 0x140221a20 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@@Z 0x140221a50 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@XZ 0x140221a80 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@XZ 0x140221ab0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@2@XZ 0x140221b00 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@2@XZ 0x140221b10 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@UCommonEnumNoCaseLess@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@std@@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@2@XZ 0x140221b20 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@UCommonEnumNoCaseLess@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@std@@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@2@XZ 0x140221b30 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@XZ 0x140221b40 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@2@XZ 0x140221b50 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@2@XZ 0x140221b60 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@2@XZ 0x140221b90 ; prop
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@XZ 0x140221c50 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@@Z 0x140221c60 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@PEAU32@@Z 0x140221d40 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@PEAU32@@Z 0x140221d70 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@XZ 0x140221da0 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@XZ 0x140221dc0 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@@Z 0x140221de0 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@_K@Z 0x140221f20 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@2@XZ 0x140221f50 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAAXXZ 0x140221fc0 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@_K@Z 0x140222060 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@2@_K@Z 0x140222090 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@2@XZ 0x1402220c0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@2@0@Z 0x140222120 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@2@@Z 0x140222210 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1402222c0 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1402223a0 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@PEAX@std@@@2@@Z 0x140222400 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IUCommonEnumNoCaseLess@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@$0A@@std@@@std@@QEBA_KXZ 0x140222410 ; prop
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@std@@@std@@SAPEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@2@AEAU32@@Z 0x140222430 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <utility>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
CStringA FUN_14016a600(const wchar_t* psz, bool bFlag);        // wide -> narrow
CStringA FUN_14016a5c0(const char* psz, unsigned nFlags);      // undecorated class name

struct CommonEnumNoCaseLess {
    bool operator()(const CStringA& left, const CStringA& right) const { return left.CompareNoCase(right) < 0; }
};

// @0x140217910
int Parse_140217910(const CStringA& value)
{
    if (value.IsEmpty()) return 0;
    if (value.CompareNoCase("Normal") == 0) return 1;
    else if (value.CompareNoCase("Rare") == 0) return 2;
    else if (value.CompareNoCase("Elite") == 0) return 3;
    else if (value.CompareNoCase("Excellent") == 0) return 4;
    else if (value.CompareNoCase("Legendary") == 0) return 5;
    else if (value.CompareNoCase("Artifact") == 0) return 6;
    return 0;
}

// @0x140217a00
int Parse_140217a00(const CStringA& value)
{
    if (value.IsEmpty()) return 0;
    if (value.CompareNoCase("level") == 0) return 1;
    else if (value.CompareNoCase("level_boost") == 0) return 2;
    else if (value.CompareNoCase("mission_point") == 0) return 5;
    else if (value.CompareNoCase("daily_pick_once") == 0) return 3;
    else if (value.CompareNoCase("daily_pick_repeat") == 0) return 4;
    return 0;
}

// @0x140217ad0
int Parse_140217ad0(const CStringA& value)
{
    if (value.IsEmpty()) return 6;
    if (value.CompareNoCase("levelup") == 0) return 0;
    else if (value.CompareNoCase("farmmeso") == 0) return 4;
    else if (value.CompareNoCase("specup") == 0) return 3;
    else if (value.CompareNoCase("farmingredient") == 0) return 5;
    else if (value.CompareNoCase("community") == 0) return 1;
    else if (value.CompareNoCase("special") == 0) return 2;
    return 6;
}

// @0x140217bd0
int Parse_140217bd0(const CStringA& value)
{
    if (value.IsEmpty()) return 0;
    if (value.CompareNoCase("levelup_package") == 0) return 1;
    else if (value.CompareNoCase("stamp") == 0) return 2;
    else if (value.CompareNoCase("timerun") == 0) return 3;
    else if (value.CompareNoCase("gallery") == 0) return 4;
    return 0;
}

// @0x140217c80
int Parse_140217c80(const CStringW& value)
{
    if (value.IsEmpty()) return 0;
    if (value.CompareNoCase(L"achievement") == 0) return 1;
    return 0;
}

// @0x140217cd0
int Parse_140217cd0(const CStringA& value)
{
    if(value.IsEmpty()) return 0;
    if(value.CompareNoCase("GuildQuest") == 0) { return 0x3eb; }
    else if(value.CompareNoCase("GuildWeeklyQuest") == 0) { return 0x3ec; }
    else if(value.CompareNoCase("MiniGame") == 0) { return 0x3ed; }
    else if(value.CompareNoCase("DungeonHelper") == 0) { return 0x3ee; }
    else if(value.CompareNoCase("MiniGameType2") == 0) { return 0x3ef; }
    else if(value.CompareNoCase("UserOpenMiniGameExtraReward") == 0) { return 0x3f0; }
    else if(value.CompareNoCase("MentorDungeonNormal") == 0) { return 0x3f1; }
    else if(value.CompareNoCase("MentorDungeonRaid") == 0) { return 0x3f2; }
    else if(value.CompareNoCase("MentorDungeonEvent") == 0) { return 0x3f3; }
    else if(value.CompareNoCase("MenteeDungeonNormal1") == 0) { return 0x3f4; }
    else if(value.CompareNoCase("MenteeDungeonNormal2") == 0) { return 0x3f5; }
    else if(value.CompareNoCase("MenteeDungeonRaid") == 0) { return 0x3f6; }
    else if(value.CompareNoCase("MenteeDungeonEvent") == 0) { return 0x3f7; }
    else if(value.CompareNoCase("DungeonMenteePartyGift") == 0) { return 0x3f8; }
    else if(value.CompareNoCase("MentoringReturnUserGift") == 0) { return 0x3f9; }
    else if(value.CompareNoCase("MentoringReturnUserCoin1") == 0) { return 0x3fa; }
    else if(value.CompareNoCase("MentoringReturnUserCoin2") == 0) { return 0x3fb; }
    else if(value.CompareNoCase("MentorDungeonChaos") == 0) { return 0x409; }
    else if(value.CompareNoCase("MenteeDungeonChaos") == 0) { return 0x40a; }
    else if(value.CompareNoCase("MentoringReturnUserCoin3") == 0) { return 0x40b; }
    (void)((!!0)||(_wassert(L"0",
    L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp"
    ,0x93),0));
    return 0;
}

// @0x140217ff0
CStringW Name_140217ff0(int value)
{
    switch(value) {
    case 0: return CStringW(L"block_login");
    case 1: return CStringW(L"block_transfer");
    default: return CStringW(L"block_none");
    }
}

// @0x1402180a0
int Parse_1402180a0(const CStringW& value)
{
    if (value.CompareNoCase(L"block_login") == 0) return 0;
    else if (value.CompareNoCase(L"block_transfer") == 0) return 1;
    return -1;
}

// @0x140218100
int Parse_140218100(const CStringA& value)
{
    if (value.IsEmpty()) return 1;
    if (value.CompareNoCase("fail") == 0) return 1;
    else if (value.CompareNoCase("backward") == 0) return 2;
    else if (value.CompareNoCase("forward") == 0) return 3;
    else if (value.CompareNoCase("gotostarting") == 0) return 4;
    else if (value.CompareNoCase("dicemore") == 0) return 5;
    else if (value.CompareNoCase("starting") == 0) return 6;
    else if (value.CompareNoCase("trap") == 0) return 7;
    else if (value.CompareNoCase("worldtour") == 0) return 8;
    else if (value.CompareNoCase("paradise") == 0) return 9;
    else if (value.CompareNoCase("item") == 0) return 10;
    return 1;
}

// @0x140218290
CStringW Name_140218290(int value)
{
    switch(value) {
        case 1:
        return CStringW(L"fail");
        case 2:
        return CStringW(L"backward");
        case 3:
        return CStringW(L"forward");
        case 4:
        return CStringW(L"gotostarting");
        case 5:
        return CStringW(L"dicemore");
        case 6:
        return CStringW(L"starting");
        case 7:
        return CStringW(L"trap");
        case 8:
        return CStringW(L"worldtour");
        case 9:
        return CStringW(L"paradise");
        case 10:
        return CStringW(L"item");
        default:
        return CStringW(L"");
    }
}

// @0x1402184b0
CStringW Name_1402184b0(int value)
{
    if (value == 0x50) {
        return CStringW(L"Assassin");
    }
    else if (value == 0x14) {
        return CStringW(L"Berserker");
    }
    else if (value == 0x3c) {
        return CStringW(L"HeavyGunner");
    }
    else if (value == 10) {
        return CStringW(L"Knight");
    }
    else if (value == 1) {
        return CStringW(L"Newbie");
    }
    else if (value == 0x28) {
        return CStringW(L"Priest");
    }
    else if (value == 0x32) {
        return CStringW(L"Ranger");
    }
    else if (value == 0x5a) {
        return CStringW(L"RuneBlader");
    }
    else if (value == 0x6e) {
        return CStringW(L"SoulBinder");
    }
    else if (value == 100) {
        return CStringW(L"Striker");
    }
    else if (value == 0x46) {
        return CStringW(L"Thief");
    }
    else if (value == 0x1e) {
        return CStringW(L"Wizard");
    }
    else {
        return CStringW(L"None");
    }
}

// @0x140218720
CStringW Name_140218720(int value)
{
    if (value == 0x385) {
        return CStringW(L"ArcaneRuneBlader");
    }
    else if (value == 800) {
        return CStringW(L"Assassin");
    }
    else if (value == 200) {
        return CStringW(L"Berserker");
    }
    else if (value == 0xc9) {
        return CStringW(L"BloodyBerserker");
    }
    else if (value == 600) {
        return CStringW(L"HeavyGunner");
    }
    else if (value == 0x191) {
        return CStringW(L"HighPriest");
    }
    else if (value == 0x259) {
        return CStringW(L"HyperHeavyGunner");
    }
    else if (value == 100) {
        return CStringW(L"Knight");
    }
    else if (value == 0x12d) {
        return CStringW(L"MagicalWizard")
        ;
    }
    else if (value == 0x44e) {
        return CStringW(L"Max");
    }
    else if (value == 0x44d) {
        return CStringW(L"MysticSoulBinder");
    }
    else if (value == 10) {
        return CStringW(L"Newbie");
    }
    else if (value == 0) {
        return CStringW(L"None");
    }
    else if (value == 0x2bd) {
        return CStringW(L"PhantomThief");
    }
    else if (value == 400) {
        return CStringW(L"Priest");
    }
    else if (value == 500) {
        return CStringW(L"Ranger");
    }
    else if (value == 900) {
        return CStringW(L"RuneBlader");
    }
    else if (value == 0x65) {
        return CStringW(L"SaintKnight");
    }
    else if (value == 0x321) {
        return CStringW(L"ShadowAssassin");
    }
    else if (value == 0x1f5) {
        return CStringW(L"SharpRanger");
    }
    else if (value == 0x44c) {
        return CStringW(L"SoulBinder");
    }
    else if (value == 1000) {
        return CStringW(L"Striker");
    }
    else if (value == 700) {
        return CStringW(L"Thief");
    }
    else if (value == 0x3e9) {
        return CStringW(L"UltimateStriker");
    }
    else if (value == 300) {
        return CStringW(L"Wizard");
    }
    else {
        return CStringW(L"None");
    }
}

// @0x140218c20
int Parse_140218c20(const CStringA& value)
{
    if(value.IsEmpty()) return 0;
    if(value.Compare("normal") == 0) { return 1; }
    else if(value.Compare("raid") == 0) { return 2; }
    else if(value.Compare("chaosRaid") == 0) { return 3; }
    else if(value.Compare("reverseRaid") == 0) { return 4; }
    else if(value.Compare("lapenta") == 0) { return 5; }
    else if(value.Compare("guildRaid") == 0) { return 6; }
    else if(value.Compare("darkStream") == 0) { return 7; }
    else if(value.Compare("worldBossDungeon") == 0) { return 8; }
    else if(value.Compare("item") == 0) { return 9; }
    else if(value.Compare("vip") == 0) { return 10; }
    else if(value.Compare("event") == 0) { return 0xb; }
    else if(value.Compare("fameChallenge") == 0) { return 0xc; }
    else if(value.Compare("colosseum") == 0) { return 0xd; }
    else if(value.Compare("turka") == 0) { return 0xe; }
    (void)((!!0)||(_wassert(L"0",
    L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp"
    ,0x141),0));
    return 0;
}

// @0x140218ed0
CStringW Name_140218ed0(int value)
{
    if (value == 0) return CStringW(L"");
    else if (value == 1) return CStringW(L"normal");
    else if (value == 2) return CStringW(L"raid");
    else if (value == 3) return CStringW(L"chaosRaid");
    else if (value == 4) return CStringW(L"reverseRaid");
    else if (value == 5) return CStringW(L"lapenta");
    else if (value == 6) return CStringW(L"guildRaid");
    else if (value == 7) return CStringW(L"darkStream");
    else if (value == 8) return CStringW(L"worldBossDungeon");
    else if (value == 9) return CStringW(L"item");
    else if (value == 10) return CStringW(L"vip");
    else if (value == 0xb) return CStringW(L"event");
    else if (value == 0xc) return CStringW(L"fameChallenge");
    else {
        (void)((!!0)||(_wassert(L"0",L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp",0x16a),0));
        return CStringW(L"");
    }
}

// @0x1402191c0
int Parse_1402191c0(const CStringA& value)
{
    if(value.IsEmpty()) return 0;
    if(value.CompareNoCase("Playing") == 0) { return 0; }
    else if(value.CompareNoCase("Clear") == 0) { return 1; }
    else if(value.CompareNoCase("Fail") == 0) { return 2; }
    (void)((!!0)||(_wassert(L"0",L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp",0x19e),0));
    return 0;
}

// @0x140219270
int Parse_140219270(const CStringA& value)
{
    if (value.IsEmpty()) return 0;
    if (value.CompareNoCase("None") == 0) return 0;
    else if (value.CompareNoCase("Clear") == 0) return 1;
    else if (value.CompareNoCase("Fail") == 0) return 2;
    return 0;
}

// @0x140219300
int Parse_140219300(const CStringA& value)
{
    if (value.CompareNoCase("lose") == 0) return 0;
    else if (value.CompareNoCase("gameover") == 0) return 1;
    else if (value.CompareNoCase("winner") == 0) return 2;
    else if (value.CompareNoCase("bonus") == 0) return 3;
    else if (value.CompareNoCase("draw") == 0) return 4;
    else if (value.CompareNoCase("success") == 0) return 5;
    else if (value.CompareNoCase("notice") == 0) return 6;
    return -1;
}

// @0x1402195f0
int Parse_1402195f0(const CStringA& value)
{
    if (value.CompareNoCase("meso") == 0) return 1;
    else if (value.CompareNoCase("merat") == 0) return 2;
    return 0;
}

// @0x140219650
int Parse_140219650(const CStringA& value)
{
    if (value.CompareNoCase("additionalEffect") == 0) return 1;
    else if (value.CompareNoCase("autoInteraction") == 0) return 2;
    return 0;
}

// @0x1402196b0
int Parse_1402196b0(const CStringA& value)
{
    if (value.CompareNoCase("character") == 0) return 1;
    else if (value.CompareNoCase("account") == 0) return 2;
    return 0;
}

// @0x140219710
int Parse_140219710(const CStringA& value)
{
    if (value.CompareNoCase("center") == 0) return 0;
    else if (value.CompareNoCase("left") == 0) return 1;
    else if (value.CompareNoCase("right") == 0) return 2;
    return 1;
}

// @0x140219790
CStringA Name_140219790(int value)
{
    if (value == 1) {
        return CStringA("mine");
    }
    else if (value == 3) {
        return CStringA("party");
    }
    return CStringA("all");
}

// @0x140219830
CStringA Name_140219830(int value)
{
    if (value == 1) {
        return CStringA("size");
    }
    if (value == 2) {
        return CStringA("alpha");
    }
    if (value == 3) {
        return CStringA("all");
    }
    return CStringA("default");
}

// @0x140219900
int Parse_140219900(const CStringA& value)
{
    if (value.CompareNoCase("mine") == 0) return 1;
    else if (value.CompareNoCase("party") == 0) return 3;
    return 7;
}

// @0x140219960
int Parse_140219960(const CStringA& value)
{
    if (value.CompareNoCase("alpha") == 0) return 2;
    else if (value.CompareNoCase("size") == 0) return 1;
    else if (value.CompareNoCase("all") == 0) return 3;
    return 0;
}

// @0x1402199e0
int Parse_1402199e0(const CStringA& value)
{
    if (value.IsEmpty()) return 0;
    if (value.CompareNoCase("dayOfWeeks") == 0) return 1;
    else if (value.CompareNoCase("nextDay") == 0) return 2;
    return 0;
}

// @0x140219a50
int Parse_140219a50(const CStringA& value)
{
    if (value.IsEmpty()) return 0;
    if (value.CompareNoCase("dev") == 0) return 1;
    if (value.CompareNoCase("devstage") == 0) return 2;
    if (value.CompareNoCase("qa") == 0) return 3;
    if (value.CompareNoCase("stage") == 0) return 4;
    if (value.CompareNoCase("live") == 0) return 5;
    return 0;
}

// @0x140219b10
CStringA Name_140219b10(int value)
{
    switch(value) {
        case 1:
        return CStringA("trans");
        case 2:
        return CStringA("dmgFont");
        case 3:
        return CStringA("chatBalloon");
        case 4:
        return CStringA("nameTag");
        case 5:
        return CStringA("tomb");
        case 6:
        return CStringA("swim");
        case 7:
        return CStringA("charEffect");
        case 8:
        return CStringA("fishing");
        case 9:
        return CStringA("autoMastery");
        case 10:
        return CStringA("effect");
        case 0xb:
        return CStringA("petSkin");
        case 0xc:
        return CStringA("meta");
        default:
        return CStringA("");
    }
}

// @0x140219d90
int Parse_140219d90(const CStringA& value)
{
    if (value.CompareNoCase("trans") == 0) return 1;
    else if (value.CompareNoCase("dmgFont") == 0) return 2;
    else if (value.CompareNoCase("chatBalloon") == 0) return 3;
    else if (value.CompareNoCase("nameTag") == 0) return 4;
    else if (value.CompareNoCase("tomb") == 0) return 5;
    else if (value.CompareNoCase("swim") == 0) return 6;
    else if (value.CompareNoCase("charEffect") == 0) return 7;
    else if (value.CompareNoCase("fishing") == 0) return 8;
    else if (value.CompareNoCase("autoMastery") == 0) return 9;
    else if (value.CompareNoCase("effect") == 0) return 10;
    else if (value.CompareNoCase("petSkin") == 0) return 0xb;
    else if (value.CompareNoCase("meta") == 0) return 0xc;
    return 0;
}

// @0x140219f50
int Parse_140219f50(const CStringA& value)
{
    if (value.CompareNoCase("equip") == 0) return 1;
    else if (value.CompareNoCase("goods") == 0) return 2;
    else if (value.CompareNoCase("gemstone") == 0) return 3;
    else if (value.CompareNoCase("itemMerge") == 0) return 4;
    else if (value.CompareNoCase("music") == 0) return 5;
    else if (value.CompareNoCase("quest") == 0) return 6;
    return 0;
}

// @0x14021a0a0
int Parse_14021a0a0(const CStringA& value)
{
    if (value.CompareNoCase("attend") == 0) return 1;
    else if (value.CompareNoCase("donation") == 0) return 2;
    else if (value.CompareNoCase("winMiniGame") == 0) return 3;
    else if (value.CompareNoCase("loseMiniGame") == 0) return 4;
    else if (value.CompareNoCase("dailyQuest") == 0) return 5;
    else if (value.CompareNoCase("weeklyQuest") == 0) return 6;
    else if (value.CompareNoCase("raid") == 0) return 7;
    else if (value.CompareNoCase("winPvp") == 0) return 8;
    else if (value.CompareNoCase("losePvp") == 0) return 9;
    return 0;
}

// @0x14021a1f0
int Parse_14021a1f0(const CStringA& value)
{
    if (value.CompareNoCase("npc") == 0) return 0;
    else if (value.CompareNoCase("interact") == 0) return 1;
    else if (value.CompareNoCase("liftable") == 0) return 2;
    return 3;
}

// @0x14021a270
int Parse_14021a270(const CStringA& value)
{
    if (value.CompareNoCase("exchange") == 0) return 1;
    else if (value.CompareNoCase("upgrade") == 0) return 2;
    else if (value.CompareNoCase("trading") == 0) return 3;
    return 0;
}

// @0x14021a2f0
int Parse_14021a2f0(const CStringW& value)
{
    return value.CompareNoCase(L"vipgm") == 0 ? 1 : 0;
}

// @0x14021a330
int Parse_14021a330(const CStringA& value)
{
    if (value.CompareNoCase("darkwind") == 0) return 1;
    else if (value.CompareNoCase("mapleunion") == 0) return 2;
    else if (value.CompareNoCase("lumiknight") == 0) return 3;
    else if (value.CompareNoCase("triaroyalguard") == 0) return 4;
    else if (value.CompareNoCase("greenhood") == 0) return 5;
    else if (value.CompareNoCase("mapleunion_kritiasexped") == 0) return 6;
    else if (value.CompareNoCase("lumiknight_kritiasexped") == 0) return 7;
    else if (value.CompareNoCase("greenhood_kritiasexped") == 0) return 8;
    else if (value.CompareNoCase("georg") == 0) return 9;
    return 0;
}

// @0x14021a480
int Parse_14021a480(const CStringA& value)
{
    if (value.CompareNoCase("skyfotress") == 0) return 1;
    else if (value.CompareNoCase("kritiasexped") == 0) return 2;
    else if (value.CompareNoCase("georg") == 0) return 3;
    return 0;
}

// @0x14021a570
int Parse_14021a570(const CStringA& value)
{
    if (value.CompareNoCase("S") == 0) return 0;
    else if (value.CompareNoCase("A") == 0) return 1;
    else if (value.CompareNoCase("B") == 0) return 2;
    else if (value.CompareNoCase("C") == 0) return 3;
    else if (value.CompareNoCase("D") == 0) return 4;
    return 5;
}

// @0x14021a630
int Parse_14021a630(const CStringA& value)
{
    if (value.CompareNoCase("ShadowGauge") == 0) return 1;
    else if (value.CompareNoCase("ScoreBoardTopCenter") == 0) return 2;
    else if (value.CompareNoCase("ScoreBoardTopRight") == 0) return 3;
    return 0;
}

// @0x14021a6b0
CStringA Name_14021a6b0(int value)
{
    switch(value) {
        case 1:
        return CStringA("darkwind");
        case 2:
        return CStringA("mapleunion");
        case 3:
        return CStringA("lumiknight");
        case 4:
        return CStringA("triaroyalguard");
        case 5:
        return CStringA("greenhood");
        case 6:
        return CStringA("mapleunion_kritiasexped")
        ;
        case 7:
        return CStringA("lumiknight_kritiasexped")
        ;
        case 8:
        return CStringA("greenhood_kritiasexped");
        case 9:
        return CStringA("georg");
        default:
        return CStringA("none");
    }
}

// @0x14021a8b0
CStringA Name_14021a8b0(int value)
{
    switch(value) {
        case 0:
        return CStringA("levelup");
        case 1:
        return CStringA("community");
        case 2:
        return CStringA("special");
        case 3:
        return CStringA("specup");
        case 4:
        return CStringA("farmmeso");
        case 5:
        return CStringA("farmingredient");
        default:
        return CStringA("");
    }
}

// @0x14021aa20
CStringA Name_14021aa20(int value)
{
    if (value == 0) {
        return CStringA("S");
    }
    else if (value == 1) {
        return CStringA("A");
    }
    else if (value == 2) {
        return CStringA("B");
    }
    else if (value == 3) {
        return CStringA("C");
    }
    else if (value == 4) {
        return CStringA("D");
    }
    else {
        return CStringA("");
    }
}

// @0x14021ab60
int Parse_14021ab60(const CStringA& value)
{
    if(value.IsEmpty()) return 0;
    if(value.CompareNoCase("Clock") == 0) { return 1; }
    else if(value.CompareNoCase("Gauge") == 0) { return 2; }
    (void)((!!0)||(_wassert(L"0",L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp",0x393),0));
    return 0;
}

// @0x14021abf0
int Parse_14021abf0(const CStringA& value)
{
    if (value.CompareNoCase("talk") == 0) return 0;
    else if (value.CompareNoCase("movie") == 0) return 1;
    else if (value.CompareNoCase("cutin") == 0) return 2;
    else if (value.CompareNoCase("talkbottom") == 0) return 3;
    return 0;
}

// @0x14021ac80
CStringA Name_14021ac80(int value)
{
    if (value == 0) {
        return CStringA("talk");
    }
    else if (value == 1) {
        return CStringA("movie");
    }
    else if (value == 2) {
        return CStringA("cutin");
    }
    else if (value == 3) {
        return CStringA("talkbottom");
    }
    else {
        return CStringA("");
    }
}

// @0x14021ad80
int Parse_14021ad80(const CStringA& value)
{
    if (value.CompareNoCase("AnyOne") == 0) return 1;
    else if (value.CompareNoCase("NeedAll") == 0) return 2;
    return 0;
}

// @0x14021ade0
int Parse_14021ade0(const CStringA& value)
{
    if (value.CompareNoCase("Keyboard") == 0) return 1;
    else if (value.CompareNoCase("GamePad") == 0) return 2;
    return 0;
}

// @0x14021ae40
int Parse_14021ae40(const CStringA& value)
{
    if (value.CompareNoCase("Snow") == 0) return 1;
    else if (value.CompareNoCase("HeavySnow") == 0) return 2;
    else if (value.CompareNoCase("Rain") == 0) return 3;
    else if (value.CompareNoCase("HeavyRain") == 0) return 4;
    else if (value.CompareNoCase("SandStorm") == 0) return 5;
    else if (value.CompareNoCase("CherryBlossom") == 0) return 6;
    else if (value.CompareNoCase("LeafFall") == 0) return 7;
    return 0;
}

// @0x14021b730
int Parse_14021b730(const CStringA& value)
{
    if (value.IsEmpty()) return 3;
    if (value.CompareNoCase("effectTail") == 0) return 0;
    else if (value.CompareNoCase("riding") == 0) return 1;
    else if (value.CompareNoCase("gliding") == 0) return 2;
    return 3;
}

// @0x14021b8a0
int Parse_14021b8a0(const CStringA& value)
{
    if (value.CompareNoCase("Groom") == 0) return 2;
    else if (value.CompareNoCase("Bride") == 0) return 3;
    else if (value.CompareNoCase("GroomBride") == 0) return 1;
    else if (value.CompareNoCase("Guest") == 0) return 4;
    else if (value.CompareNoCase("All") == 0) return 5;
    return 0;
}

// @0x14021b950
int Parse_14021b950(const CStringA& value)
{
    if (value.CompareNoCase("startActing") == 0) return 1;
    else if (value.CompareNoCase("endActing") == 0) return 2;
    else if (value.CompareNoCase("partnerName") == 0) return 3;
    return 0;
}

// @0x14021b9d0
int Parse_14021b9d0(const CStringA& value)
{
    if (value.CompareNoCase("ready") == 0) return 0;
    else if (value.CompareNoCase("openingComplete") == 0) return 1;
    else if (value.CompareNoCase("weddingBroken") == 0) return 2;
    else if (value.CompareNoCase("weddingComplete") == 0) return 3;
    return 0;
}

// @0x14021ba60
int Parse_14021ba60(const CStringA& value)
{
    if (value.CompareNoCase("mutual") == 0) return 1;
    else if (value.CompareNoCase("individual") == 0) return 2;
    else if (value.CompareNoCase("individualAgree") == 0) return 3;
    else if (value.CompareNoCase("individualcancel") == 0) return 4;
    return 0;
}

// @0x14021baf0
int Parse_14021baf0(const CStringA& value)
{
    if (value.CompareNoCase("MarriedLife") == 0) return 1;
    else if (value.CompareNoCase("LogoutPanelty") == 0) return 4;
    else if (value.CompareNoCase("Attendance") == 0) return 3;
    else if (value.CompareNoCase("CoupleMessage") == 0) return 2;
    else if (value.CompareNoCase("MarriageRegister") == 0) return 5;
    else if (value.CompareNoCase("WeddingExpItem") == 0) return 6;
    return 0;
}

// @0x14021bbd0
int Parse_14021bbd0(const CStringA& value)
{
    if (value.CompareNoCase("day") == 0) return 1;
    else if (value.CompareNoCase("month") == 0) return 2;
    return 0;
}

// @0x14021bc30
int Parse_14021bc30(const CStringA& value)
{
    if(value.CompareNoCase("field_boss") == 0) { return 1; }
    else if(value.CompareNoCase("field_elite") == 0) { return 2; }
    else if(value.CompareNoCase("dungeon_boss") == 0) { return 3; }
    else if(value.CompareNoCase("dungeon_elite") == 0) { return 4; }
    else if(value.CompareNoCase("event_boss") == 0) { return 5; }
    (void)((!!0)||(_wassert(L"0",L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp",0x4f2),0));
    return 0;
}

// @0x14021bd10
int Parse_14021bd10(const CStringA& value)
{
    if (value.IsEmpty()) return 0;
    if (value.CompareNoCase("AdventureLevelUp") == 0) return 1;
    else if (value.CompareNoCase("CreateMasteryItem") == 0) return 2;
    else if (value.CompareNoCase("DungeonRewardItem") == 0) return 3;
    else if (value.CompareNoCase("ShopBuyItem") == 0) return 4;
    return 0;
}

// @0x14021c050
CStringA Name_14021c050(int value)
{
    switch(value) {
        case 1:
        return CStringA("HR");
        case 2:
        return CStringA("FA");
        case 3:
        return CStringA("FD");
        case 4:
        return CStringA("LH");
        case 5:
        return CStringA("RH");
        case 6:
        return CStringA("CP");
        case 7:
        return CStringA("MT");
        case 8:
        return CStringA("CL");
        case 9:
        return CStringA("PA");
        case 10:
        return CStringA("GL");
        case 0xb:
        return CStringA("SH");
        case 0xc:
        return CStringA("FH");
        case 0xd:
        return CStringA("EY");
        case 0xe:
        return CStringA("EA");
        case 0xf:
        return CStringA("PD");
        case 0x10:
        return CStringA("RI");
        case 0x11:
        return CStringA("BE");
        case 0x12:
        return CStringA("ER");
        case 0x13:
        return CStringA("OH");
        default:
        return CStringA("");
    }
}

// @0x14021c400
int Parse_14021c400(const CStringA& value)
{
    if (value.CompareNoCase("Fishing") == 0) return 1;
    else if (value.CompareNoCase("Music") == 0) return 2;
    else if (value.CompareNoCase("Mining") == 0) return 3;
    else if (value.CompareNoCase("Gathering") == 0) return 4;
    else if (value.CompareNoCase("Breeding") == 0) return 5;
    else if (value.CompareNoCase("Farming") == 0) return 6;
    else if (value.CompareNoCase("Blacksmithing") == 0) return 7;
    else if (value.CompareNoCase("Evgraving") == 0) return 8;
    else if (value.CompareNoCase("Alchemist") == 0) return 9;
    else if (value.CompareNoCase("Cooking") == 0) return 10;
    else if (value.CompareNoCase("PetTaming") == 0) return 0xb;
    return 0;
}

// @0x14021c570
CStringA Name_14021c570(int value)
{
    switch(value) {
        case 1:
        return CStringA("Fishing");
        case 2:
        return CStringA("Music");
        case 3:
        return CStringA("Mining");
        case 4:
        return CStringA("Gathering");
        case 5:
        return CStringA("Breeding");
        case 6:
        return CStringA("Farming");
        case 7:
        return CStringA("Blacksmithing");
        case 8:
        return CStringA("Evgraving");
        case 9:
        return CStringA("Alchemist");
        case 10:
        return CStringA("Cooking");
        case 0xb:
        return CStringA("PetTaming");
        default:
        return CStringA("None");
    }
}

// @0x14021c7c0
int Parse_14021c7c0(const CStringA& value)
{
    if (value.CompareNoCase("unknown") == 0) return 1;
    else if (value.CompareNoCase("plant") == 0) return 2;
    else if (value.CompareNoCase("animal") == 0) return 3;
    else if (value.CompareNoCase("bug") == 0) return 4;
    else if (value.CompareNoCase("mystic") == 0) return 5;
    else if (value.CompareNoCase("spirit") == 0) return 6;
    else if (value.CompareNoCase("fairy") == 0) return 7;
    else if (value.CompareNoCase("combine") == 0) return 8;
    else if (value.CompareNoCase("undead") == 0) return 9;
    else if (value.CompareNoCase("devil") == 0) return 10;
    else if (value.CompareNoCase("machine") == 0) return 0xb;
    else if (value.CompareNoCase("creature") == 0) return 0xc;
    return 0;
}

// @0x140219400
int Parse_140219400(const CStringA& value) {
if(value.IsEmpty()) return 0;
else if(value.CompareNoCase("Greater")==0 || value.Compare(">")==0) return 1;
else if(value.CompareNoCase("GreaterEqual")==0 || value.Compare(">=")==0) return 2;
else if(value.CompareNoCase("LessEqual")==0 || value.Compare("<=")==0) return 3;
else if(value.CompareNoCase("Less")==0 || value.Compare("<")==0) return 4;
else if(value.CompareNoCase("Equal")==0 || value.Compare("==")==0 || value.Compare("=")==0) return 0;
else { (void)((!!0)||(_wassert(L"0",L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp",472),0)); return 0; }
 }
std::map<CStringA,unsigned,CommonEnumNoCaseLess> cache; // 0x143aac740, inferred
// inferred: 0x140220190 clears the global then inserts literal/int pairs in this order.
void* InitializeExperienceNames(void* context) {
    cache.clear();
    cache.insert(std::make_pair("Exp_MapCommon", 0u));
    cache.insert(std::make_pair("Exp_MapHidden", 1u));
    cache.insert(std::make_pair("Exp_TaxiStation", 2u));
    cache.insert(std::make_pair("Exp_Telescope", 3u));
    cache.insert(std::make_pair("Exp_RareChest", 4u));
    cache.insert(std::make_pair("Exp_RareChestFirst", 5u));
    cache.insert(std::make_pair("Exp_NormalChest", 6u));
    cache.insert(std::make_pair("Exp_DropItem", 7u));
    cache.insert(std::make_pair("Exp_DungeonBoss", 8u));
    cache.insert(std::make_pair("Exp_MusicMasteryLv1", 9u));
    cache.insert(std::make_pair("Exp_MusicMasteryLv2", 10u));
    cache.insert(std::make_pair("Exp_MusicMasteryLv3", 11u));
    cache.insert(std::make_pair("Exp_MusicMasteryLv4", 12u));
    cache.insert(std::make_pair("Exp_Arcade", 13u));
    cache.insert(std::make_pair("Exp_Fishing", 14u));
    cache.insert(std::make_pair("Exp_Rest", 15u));
    cache.insert(std::make_pair("Exp_Quest", 16u));
    cache.insert(std::make_pair("Exp_QuestSkyFortress", 17u));
    cache.insert(std::make_pair("Exp_PvpBloodMineRank1", 18u));
    cache.insert(std::make_pair("Exp_PvpBloodMineRank2", 19u));
    cache.insert(std::make_pair("Exp_PvpBloodMineRank3", 20u));
    cache.insert(std::make_pair("Exp_PvpBloodMineRankOther", 21u));
    cache.insert(std::make_pair("Exp_PvpRedDuelWin", 22u));
    cache.insert(std::make_pair("Exp_PvpRedDuelLose", 23u));
    cache.insert(std::make_pair("Exp_PvpBtiTeamWin", 24u));
    cache.insert(std::make_pair("Exp_PvpBtiTeamLose", 25u));
    cache.insert(std::make_pair("Exp_PvpRankDuelWin", 26u));
    cache.insert(std::make_pair("Exp_PvpRankDuelLose", 27u));
    cache.insert(std::make_pair("Exp_Gathering", 28u));
    cache.insert(std::make_pair("Exp_Manufacturing", 29u));
    cache.insert(std::make_pair("Exp_RandomDungeonBonus", 30u));
    cache.insert(std::make_pair("Exp_MiniGame", 31u));
    cache.insert(std::make_pair("Exp_UserMiniGame", 32u));
    cache.insert(std::make_pair("Exp_UserMiniGameExtra", 33u));
    cache.insert(std::make_pair("Exp_Mission", 34u));
    cache.insert(std::make_pair("Exp_DungeonRelative", 35u));
    cache.insert(std::make_pair("Exp_GuildUserExp", 36u));
    cache.insert(std::make_pair("Exp_DailyGuildQuest", 37u));
    cache.insert(std::make_pair("Exp_WeeklyGuildQuest", 38u));
    cache.insert(std::make_pair("Exp_PetTaming", 39u));
    cache.insert(std::make_pair("Exp_Construct", 42u));
    cache.insert(std::make_pair("Exp_DailyMission", 40u));
    cache.insert(std::make_pair("Exp_DailyMissionLevelUp", 41u));
    cache.insert(std::make_pair("Exp_MapleSurvival", 43u));
    cache.insert(std::make_pair("Exp_EpicQuest", 44u));
    cache.insert(std::make_pair("Exp_DarkStream", 45u));
    cache.insert(std::make_pair("Exp_DungeonClear", 46u));
    cache.insert(std::make_pair("Exp_KillMonster", 47u));
    return context;
}
// @0x14021af40
int Parse_14021af40(const CStringA& value) {
  if (value.IsEmpty()) {
    return -1;
  }
  else {
 auto it=cache.find(value);
 if (it==cache.end()) {
      if (!((value == "mapCommon"))) {
        if (!((value == "mapHidden"))) {
          if (!((value == "taxi"))) {
            if (!((value == "telescope"))) {
              if (!((value == "rareChestFirst"))) {
                if (!((value == "rareChest"))) {
                  if (!((value == "normalChest"))) {
                    if (!((value == "expDrop"))) {
                      if (!((value == "musicMastery1"))) {
                        if (!((value == "musicMastery2"))) {
                          if (!((value == "musicMastery3"))) {
                            if (!((value == "musicMastery4"))) {
                              if (!((value == "arcade"))) {
                                if (!((value == "fishing"))) {
                                  if (!((value == "rest"))) {
                                    if (!((value == "bloodMineRank1"))) {
                                      if (!((value == "bloodMineRank2"))) {
                                        if (!((value == "bloodMineRank3"))) {
                                          if (!((value == "bloodMineRankOther"))) {
                                            if (!((value == "redDuelWin"))) {
                                              if (!((value == "redDuelLose"))) {
                                                if (!((value == "btiTeamWin"))) {
                                                  if (!((value == "btiTeamLose"))) {
                                                    if (!((value == "rankDuelWin"))) {
                                                      if (!((value == "rankDuelLose"))) {
                                                        if (!((value == "gathering"))) {
                                                          if (!((value == "manufacturing"))) {
                                                    if (!((value == "randomDungeonBonus"))) {
                                                    if (!((value == "miniGame"))) {
                                                      if (!((value == "userMiniGame"))) {
                                                        if (!((value == "userMiniGameExtra"))) {
                                                    if (!((value == "dungeonRelative")
                                                    )) {
                                                      if (!((value == "guildUserExp"))) {
                                                        if (!((value == "petTaming"))) {
                                                          if (!((value == "construct")
                                                          )) {
                                                            if (!((value == "mapleSurvival"))) {
                                                    if (!((value == "quest"))) {
                                                      if (!((value == "questSkyFortress"))) {
                                                    if (!((value == "epicQuest"))) {
                                                      if (!((value == "mission"))) {
                                                        if (!((value == "dailyGuildQuest"))) {
                                                    if (!((value == "weeklyGuildQuest"))) {
                                                      if (!((value == "dailymission"))) {
                                                        if (!((value == "dailymissionLevelUp"))) {
                                                    (void)((!!0)||(_wassert(L"0",
                                                  L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp"
                                                  ,0x463),0));
                                                  return -1;
                                                  }
                                                  else {
                                                    return 0x29;
                                                  }
                                                  }
                                                  else {
                                                    return 0x28;
                                                  }
                                                  }
                                                  else {
                                                    return 0x26;
                                                  }
                                                  }
                                                  else {
                                                    return 0x25;
                                                  }
                                                  }
                                                  else {
                                                    return 0x22;
                                                  }
                                                  }
                                                  else {
                                                    return 0x2c;
                                                  }
                                                  }
                                                  else {
                                                    return 0x11;
                                                  }
                                                  }
                                                  else {
                                                    return 0x10;
                                                  }
                                                  }
                                                  else {
                                                    return 0x2b;
                                                  }
                                                  }
                                                  else {
                                                    return 0x2a;
                                                  }
                                                  }
                                                  else {
                                                    return 0x27;
                                                  }
                                                  }
                                                  else {
                                                    return 0x24;
                                                  }
                                                  }
                                                  else {
                                                    return 0x23;
                                                  }
                                                  }
                                                  else {
                                                    return 0x21;
                                                  }
                                                  }
                                                  else {
                                                    return 0x20;
                                                  }
                                                  }
                                                  else {
                                                    return 0x1f;
                                                  }
                                                  }
                                                  else {
                                                    return 0x1e;
                                                  }
                                                  }
                                                  else {
                                                    return 0x1d;
                                                  }
                                                  }
                                                  else {
                                                    return 0x1c;
                                                  }
                                                  }
                                                  else {
                                                    return 0x1b;
                                                  }
                                                  }
                                                  else {
                                                    return 0x1a;
                                                  }
                                                  }
                                                  else {
                                                    return 0x19;
                                                  }
                                                }
                                                else {
                                                  return 0x18;
                                                }
                                              }
                                              else {
                                                return 0x17;
                                              }
                                            }
                                            else {
                                              return 0x16;
                                            }
                                          }
                                          else {
                                            return 0x15;
                                          }
                                        }
                                        else {
                                          return 0x14;
                                        }
                                      }
                                      else {
                                        return 0x13;
                                      }
                                    }
                                    else {
                                      return 0x12;
                                    }
                                  }
                                  else {
                                    return 0xf;
                                  }
                                }
                                else {
                                  return 0xe;
                                }
                              }
                              else {
                                return 0xd;
                              }
                            }
                            else {
                              return 0xc;
                            }
                          }
                          else {
                            return 0xb;
                          }
                        }
                        else {
                          return 10;
                        }
                      }
                      else {
                        return 9;
                      }
                    }
                    else {
                      return 7;
                    }
                  }
                  else {
                    return 6;
                  }
                }
                else {
                  return 4;
                }
              }
              else {
                return 5;
              }
            }
            else {
              return 3;
            }
          }
          else {
            return 2;
          }
        }
        else {
          return 1;
        }
      }
      else {
        return 0;
      }
    }
    else {
      (void)((!!0)||(_wassert(L"0",L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonenum.cpp",0x431),0));
      return cache[value];
    }
  }

 }
// @0x140218e60
int Parse_140218e60(const CStringW& value) { return Parse_140218c20(FUN_14016a600(static_cast<const wchar_t*>(value),false)); }
// @0x140219580
int Parse_140219580(const CStringW& value) { return Parse_140219400(FUN_14016a600(static_cast<const wchar_t*>(value),false)); }
// @0x14021a030
int Parse_14021a030(const CStringW& value) { return Parse_140219f50(FUN_14016a600(static_cast<const wchar_t*>(value),false)); }
// @0x14021a500
int Parse_14021a500(const CStringW& value) { return Parse_14021a330(FUN_14016a600(static_cast<const wchar_t*>(value),false)); }
// @0x14021b6c0
int Parse_14021b6c0(const CStringW& value) { return Parse_14021af40(FUN_14016a600(static_cast<const wchar_t*>(value),false)); }
// @0x14021b7c0
int Parse_14021b7c0(const CStringW& value) { return Parse_14021b730(FUN_14016a600(static_cast<const wchar_t*>(value),false)); }
// inferred: 0x14021d780 indexes 75 fixed 16-byte records, name pointer +0/code +8.
static std::pair<const char*, int> lookupTable[75]; // 0x143aac760
// @0x1400b4920
static struct Unk_LookupTableInit {
    Unk_LookupTableInit() {
        ::new (&lookupTable[0]) std::pair<const char*, int>(std::make_pair("WorldMap", 1));
        ::new (&lookupTable[1]) std::pair<const char*, int>(std::make_pair("Mail", 2));
        ::new (&lookupTable[2]) std::pair<const char*, int>(std::make_pair("Commuty", 3));
        ::new (&lookupTable[3]) std::pair<const char*, int>(std::make_pair("Guild", 4));
        ::new (&lookupTable[4]) std::pair<const char*, int>(std::make_pair("LevelUp", 5));
        ::new (&lookupTable[5]) std::pair<const char*, int>(std::make_pair("Arcade", 6));
        ::new (&lookupTable[6]) std::pair<const char*, int>(std::make_pair("Option", 7));
        ::new (&lookupTable[7]) std::pair<const char*, int>(std::make_pair("Character", 8));
        ::new (&lookupTable[8]) std::pair<const char*, int>(std::make_pair("Inventory", 9));
        ::new (&lookupTable[9]) std::pair<const char*, int>(std::make_pair("Skill", 10));
        ::new (&lookupTable[10]) std::pair<const char*, int>(std::make_pair("Quest", 11));
        ::new (&lookupTable[11]) std::pair<const char*, int>(std::make_pair("Achieve", 12));
        ::new (&lookupTable[12]) std::pair<const char*, int>(std::make_pair("DungeonSearch", 13));
        ::new (&lookupTable[13]) std::pair<const char*, int>(std::make_pair("Maview", 14));
        ::new (&lookupTable[14]) std::pair<const char*, int>(std::make_pair("MeratMarket", 15));
        ::new (&lookupTable[15]) std::pair<const char*, int>(std::make_pair("CashShop", 16));
        ::new (&lookupTable[16]) std::pair<const char*, int>(std::make_pair("Beauty", 17));
        ::new (&lookupTable[17]) std::pair<const char*, int>(std::make_pair("BlackMarket", 18));
        ::new (&lookupTable[18]) std::pair<const char*, int>(std::make_pair("IndividualBattle", 19));
        ::new (&lookupTable[19]) std::pair<const char*, int>(std::make_pair("CharacterAbility", 20));
        ::new (&lookupTable[20]) std::pair<const char*, int>(std::make_pair("Design", 21));
        ::new (&lookupTable[21]) std::pair<const char*, int>(std::make_pair("Home", 22));
        ::new (&lookupTable[22]) std::pair<const char*, int>(std::make_pair("VIP", 23));
        ::new (&lookupTable[23]) std::pair<const char*, int>(std::make_pair("Mastery", 24));
        ::new (&lookupTable[24]) std::pair<const char*, int>(std::make_pair("PartySearch", 25));
        ::new (&lookupTable[25]) std::pair<const char*, int>(std::make_pair("LearningQuest", 26));
        ::new (&lookupTable[26]) std::pair<const char*, int>(std::make_pair("CompactKey", 27));
        ::new (&lookupTable[27]) std::pair<const char*, int>(std::make_pair("Dictionary", 28));
        ::new (&lookupTable[28]) std::pair<const char*, int>(std::make_pair("Ranking", 29));
        ::new (&lookupTable[29]) std::pair<const char*, int>(std::make_pair("BeautyHair", 30));
        ::new (&lookupTable[30]) std::pair<const char*, int>(std::make_pair("BeautyItem", 31));
        ::new (&lookupTable[31]) std::pair<const char*, int>(std::make_pair("BeautySkin", 32));
        ::new (&lookupTable[32]) std::pair<const char*, int>(std::make_pair("Club", 33));
        ::new (&lookupTable[33]) std::pair<const char*, int>(std::make_pair("EpicRestart", 34));
        ::new (&lookupTable[34]) std::pair<const char*, int>(std::make_pair("LevelUpPackage", 35));
        ::new (&lookupTable[35]) std::pair<const char*, int>(std::make_pair("AdventureBar", 36));
        ::new (&lookupTable[36]) std::pair<const char*, int>(std::make_pair("StampEvent", 37));
        ::new (&lookupTable[37]) std::pair<const char*, int>(std::make_pair("AttendGift", 38));
        ::new (&lookupTable[38]) std::pair<const char*, int>(std::make_pair("Pet", 39));
        ::new (&lookupTable[39]) std::pair<const char*, int>(std::make_pair("LiveBroadCast", 40));
        ::new (&lookupTable[40]) std::pair<const char*, int>(std::make_pair("TimeRunEvent", 41));
        ::new (&lookupTable[41]) std::pair<const char*, int>(std::make_pair("Mentoring", 42));
        ::new (&lookupTable[42]) std::pair<const char*, int>(std::make_pair("DailyMission", 43));
        ::new (&lookupTable[43]) std::pair<const char*, int>(std::make_pair("FamePointBoard", 44));
        ::new (&lookupTable[44]) std::pair<const char*, int>(std::make_pair("GalleryEvent", 45));
        ::new (&lookupTable[45]) std::pair<const char*, int>(std::make_pair("SkyFortress", 46));
        ::new (&lookupTable[46]) std::pair<const char*, int>(std::make_pair("Rps", 47));
        ::new (&lookupTable[47]) std::pair<const char*, int>(std::make_pair("CharacterSelect", 48));
        ::new (&lookupTable[48]) std::pair<const char*, int>(std::make_pair("GameExit", 49));
        ::new (&lookupTable[49]) std::pair<const char*, int>(std::make_pair("SurvivalMap", 50));
        ::new (&lookupTable[50]) std::pair<const char*, int>(std::make_pair("AdventureLevel", 51));
        ::new (&lookupTable[51]) std::pair<const char*, int>(std::make_pair("WorldChampion", 52));
        ::new (&lookupTable[52]) std::pair<const char*, int>(std::make_pair("CashAttend", 53));
        ::new (&lookupTable[53]) std::pair<const char*, int>(std::make_pair("ChangeJob", 54));
        ::new (&lookupTable[54]) std::pair<const char*, int>(std::make_pair("Lapenshard", 55));
        ::new (&lookupTable[55]) std::pair<const char*, int>(std::make_pair("MushkingRoyal", 56));
        ::new (&lookupTable[56]) std::pair<const char*, int>(std::make_pair("CoupleDanceEvent", 57));
        ::new (&lookupTable[57]) std::pair<const char*, int>(std::make_pair("MeratCharge", 58));
        ::new (&lookupTable[58]) std::pair<const char*, int>(std::make_pair("PssbShop", 59));
        ::new (&lookupTable[59]) std::pair<const char*, int>(std::make_pair("CollectItemGroupEvent", 60));
        ::new (&lookupTable[60]) std::pair<const char*, int>(std::make_pair("BingoEvent", 61));
        ::new (&lookupTable[61]) std::pair<const char*, int>(std::make_pair("Payback", 62));
        ::new (&lookupTable[62]) std::pair<const char*, int>(std::make_pair("Wedding", 63));
        ::new (&lookupTable[63]) std::pair<const char*, int>(std::make_pair("LongTermAttendGift", 64));
        ::new (&lookupTable[64]) std::pair<const char*, int>(std::make_pair("MarketGroup", 1000));
        ::new (&lookupTable[65]) std::pair<const char*, int>(std::make_pair("CharacterGroup", 1001));
        ::new (&lookupTable[66]) std::pair<const char*, int>(std::make_pair("ContentsGroup", 1002));
        ::new (&lookupTable[67]) std::pair<const char*, int>(std::make_pair("GameGroup", 1003));
        ::new (&lookupTable[68]) std::pair<const char*, int>(std::make_pair("CommunityGroup", 1004));
        ::new (&lookupTable[69]) std::pair<const char*, int>(std::make_pair("GamePad_SystemGroup", 2000));
        ::new (&lookupTable[70]) std::pair<const char*, int>(std::make_pair("GamePad_CharacterGroup", 2001));
        ::new (&lookupTable[71]) std::pair<const char*, int>(std::make_pair("GamePad_ContentsGroup", 2002));
        ::new (&lookupTable[72]) std::pair<const char*, int>(std::make_pair("GamePad_GameGroup", 2003));
        ::new (&lookupTable[73]) std::pair<const char*, int>(std::make_pair("GamePad_CommunityGroup", 2004));
        ::new (&lookupTable[74]) std::pair<const char*, int>(std::make_pair("GamePad_MarketGroup", 2005));
    }
} s_lookupTableInit;
int Lookup(const CStringA& value, const std::pair<const char*, int> (&table)[75]) {
    for (int index = 0; index < _countof(table); ++index) {
        if (value == table[index].first) return table[index].second;
    }
    return 0;
}
// @0x14021b830
int Parse_14021b830(const CStringA& value) { return Lookup(FUN_14016a5c0(static_cast<const char*>(value),0),lookupTable); }
// @0x14021bdc0
int Parse_14021bdc0(const CStringW& value) { if(L"\u5248" == value) return 1;
if(L"\u4146" == value) return 2;
if(L"\u4446" == value) return 3;
if(L"\u484c" == value) return 4;
if(L"\u4852" == value) return 5;
if(L"\u5043" == value) return 6;
if(L"\u544d" == value) return 7;
if(L"\u4c43" == value) return 8;
if(L"\u4150" == value) return 9;
if(L"\u4c47" == value) return 10;
if(L"\u4853" == value) return 11;
if(L"\u4846" == value) return 12;
if(L"\u5945" == value) return 13;
if(L"\u4145" == value) return 14;
if(L"\u4450" == value) return 15;
if(L"\u4952" == value) return 16;
if(L"\u4542" == value) return 17;
if(L"\u5245" == value) return 18;
if(L"\u484f" == value) return 19;
return 0; }

MS2_EMIT_CRT_MEMMOVE_S();

void* FUN_140166410();
bool FUN_14036d570(void*, int);
// @0x140222590
bool FUN_140222590(int value)
{
    switch (value - 1) {
    case 9: case 0x13: case 0x1d: case 0x27: case 0x31: case 0x3b: case 0x45: case 0x4f:
        return true;
    case 0x59:
        return FUN_14036d570(FUN_140166410(), 8);
    case 99:
        return FUN_14036d570(FUN_140166410(), 0x12);
    case 0x6d:
        return FUN_14036d570(FUN_140166410(), 0x25);
    default:
        return false;
    }
}
