// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemOptionTable: the item option tables (constant,
// random and variation rows, the exclusive option groups and the rank weights).
// MS2-UNIT: commonfiles\itemoptiondata.cpp#3
// MS2-RANGE: 0x1405f4120-0x1406125d0 .text$mn
// MS2-RANGE: 0x1400ba710-0x1400ba7d0 .text$di
// MS2-RANGE: 0x142c9b250-0x142c9b280 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAHAEAV?$MS2Ptr@VItemOptionConstant@@@@$0A@@?$pair@HV?$MS2Ptr@VItemOptionConstant@@@@@std@@QEAA@AEAHAEAV?$MS2Ptr@VItemOptionConstant@@@@@Z 0x1405f8bd0 ; unique
// MS2-PIN: ??$?0AEAHAEAG$0A@@?$pair@HH@std@@QEAA@AEAHAEAG@Z 0x1405f8e60 ; unique
// MS2-PIN: ??$?0HPEAVItemOptionRandom@@$0A@@?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@QEAA@$$QEAU?$pair@HPEAVItemOptionRandom@@@1@@Z 0x1405f92e0 ; unique
// MS2-PIN: ??$?0HPEAVItemOptionRandom@@$0A@@?$pair@HPEAVItemOptionRandom@@@std@@QEAA@$$QEAH$$QEAPEAVItemOptionRandom@@@Z 0x1405f9330 ; unique
// MS2-PIN: ??$?0HV?$MS2Ptr@VItemOptionVariationData@@@@$0A@@?$pair@$$CBIV?$MS2Ptr@VItemOptionVariationData@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VItemOptionVariationData@@@@@1@@Z 0x1405f93d0 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@HPEAVItemOptionRandom@@@std@@@?$_List_buy@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@QEAAPEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@1@PEAU21@0$$QEAU?$pair@HPEAVItemOptionRandom@@@1@@Z 0x1405f9fe0 ; unique
// MS2-PIN: ??$addressof@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@YAPEAU?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@0@AEAU10@@Z 0x140600df0 ; prop
// MS2-PIN: ??$forward@$$QEAU?$pair@HH@std@@@std@@YA$$QEAU?$pair@HH@0@AEAU10@@Z 0x140601a40 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemOptionConstant@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemOptionConstant@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140601b40 ; unique
// MS2-PIN: ??$move@AEAV?$_Tree@V?$_Tmap_traits@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@$0A@@std@@@std@@@std@@YA$$QEAV?$_Tree@V?$_Tmap_traits@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@$0A@@std@@@0@AEAV10@@Z 0x140602140 ; unique
// MS2-PIN: ??$move@AEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@std@@@std@@@std@@YA$$QEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@std@@@0@AEAV10@@Z 0x140602150 ; unique
// MS2-PIN: ??$move@AEAV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@YA$$QEAV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@0@AEAV10@@Z 0x140602160 ; unique
// MS2-PIN: ??1?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@QEAA@XZ 0x140604890 ; unique
// MS2-PIN: ?_Freenode@?$_List_buy@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@QEAAXPEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@2@@Z 0x14060d120 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemOptionVariationData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemOptionVariationData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x14060d420 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x14060d460 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x14060d470 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@2@XZ 0x14060d620 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@2@XZ 0x14060d630 ; unique
// MS2-PIN: ?_Make_iter@?$list@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@QEBA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@@2@@Z 0x14060e650 ; unique
// MS2-PIN: ?_Make_iter@?$list@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@QEBA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@@2@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@U_Iterator_base0@2@@2@@Z 0x14060e6a0 ; unique
// MS2-PIN: ?begin@?$list@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@@2@XZ 0x140610410 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@2@_K@Z 0x140610a40 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VProbabilityFromRank@CItemOptionTable@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VProbabilityFromRank@CItemOptionTable@@@@@std@@@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VProbabilityFromRank@CItemOptionTable@@@@@std@@@std@@@std@@@2@AEBU?$pair@HH@2@@Z 0x140611980 ; unique
// MS2-PIN: ?front@?$list@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@QEAAAEAU?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@2@XZ 0x140611c20 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1ProbabilityFromRank@CItemOptionTable@@UEAA@XZ 0x140604b70
// MS2-PIN: time 0x1405f4120
// callee-consistent pins (symbols.tsv holds stale VAs for these names)
// MS2-PIN: ??$make_pair@AEAHAEAV?$MS2Ptr@VItemOptionConstant@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VItemOptionConstant@@@@@0@AEAHAEAV?$MS2Ptr@VItemOptionConstant@@@@@Z 0x140601f40
// MS2-PIN: ??$make_pair@AEAHAEAV?$MS2Ptr@VItemOptionVariationData@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VItemOptionVariationData@@@@@0@AEAHAEAV?$MS2Ptr@VItemOptionVariationData@@@@@Z 0x140602050
// MS2-PIN: ??$?0AEAHAEAV?$MS2Ptr@VItemOptionVariationData@@@@$0A@@?$pair@HV?$MS2Ptr@VItemOptionVariationData@@@@@std@@QEAA@AEAHAEAV?$MS2Ptr@VItemOptionVariationData@@@@@Z 0x1405f9290
// MS2-PIN: ??$make_pair@HPEAVItemOptionRandom@@@std@@YA?AU?$pair@HPEAVItemOptionRandom@@@0@$$QEAH$$QEAPEAVItemOptionRandom@@@Z 0x1406020b0
// MS2-PIN: ?Ms2PowFI@@YAMMH@Z 0x1406122f0
// map<unsigned long, unsigned long> glue: symbols.tsv binds these names to byte-identical copies elsewhere
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKK@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKK@std@@@std@@@1@@Z 0x140603830
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@K@2@XZ 0x14060da00
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@std@@@2@XZ 0x14060d2d0
// MS2-PIN: ??0?$MS2Ptr@VItemOptionConstant@@@@QEAA@$$QEAV0@@Z 0x1406029c0
// MS2-PIN: ?_Get_data@?$_List_alloc@U?$_List_base_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@@std@@QEBAAEBV?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@2@XZ 0x14060d1c0
// MS2-PIN: ?_Myhead@?$_List_alloc@U?$_List_base_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@@std@@QEBAAEBQEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@2@XZ 0x14060ea20
// MS2-PIN: ?_Mysize@?$_List_alloc@U?$_List_base_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@@std@@QEBAAEB_KXZ 0x14060eaa0
// MS2-PIN: ??C?$MS2Ptr@VItemOptionVariationData@@@@QEBAPEAVItemOptionVariationData@@XZ 0x140605260
// MS2-PIN: ??D?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@1@XZ 0x140605390
// MS2-PIN: ??0?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKK@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKK@std@@@std@@@1@@Z 0x140603930
// MS2-PIN: ?_Get_data@?$_List_alloc@U?$_List_base_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@@std@@QEAAAEAV?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@2@XZ 0x14060d1a0
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VItemOptionVariationData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemOptionVariationData@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x14060d9a0
// MS2-PIN: ?_Myhead@?$_List_alloc@U?$_List_base_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@@std@@QEAAAEAPEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@2@XZ 0x14060ea00
// MS2-PIN: ?end@?$list@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@QEBA?AV?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@@2@XZ 0x140610e40
// MS2-PIN: ??0?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@1@@Z 0x140602cb0
// MS2-PIN: ??C?$MS2Ptr@VItemOptionConstant@@@@QEBAPEAVItemOptionConstant@@XZ 0x140605250
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VProbabilityFromRank@CItemOptionTable@@@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VProbabilityFromRank@CItemOptionTable@@@@@1@XZ 0x140605330
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@W4Unk_SocketSpecialStat@@HU?$less@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@@std@@@std@@@2@0@Z 0x140611650
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemOptionConstant@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemOptionConstant@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemOptionConstant@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1405f8cd0
// MS2-PIN: ??$?0HV?$MS2Ptr@VItemOptionConstant@@@@$0A@@?$pair@$$CBIV?$MS2Ptr@VItemOptionConstant@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VItemOptionConstant@@@@@1@@Z 0x1405f9380
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@W4Unk_SocketSpecialStat@@HU?$less@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBW4Unk_SocketSpecialStat@@H@1@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@PEAX@1@@Z 0x1405fe850
// MS2-PIN: ??$get@$0A@$$QEAU?$pair@HH@std@@@std@@YA$$QEAU?$pair@HH@0@$$QEAV?$tuple@$$QEAU?$pair@HH@std@@@0@@Z 0x140601d30
// MS2-PIN: ??0?$MS2Ptr@VItemOptionRandom@@@@QEAA@H@Z 0x140602a80
// MS2-PIN: ??0?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@1@@Z 0x140602cf0
// MS2-PIN: ??1?$_List_alloc@U?$_List_base_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@@std@@QEAA@XZ 0x140604230
// MS2-PIN: ?get@?$MS2Ptr@VItemOptionRandom@@@@QEBAPEAVItemOptionRandom@@XZ 0x1406051f0
// MS2-PIN: ??E?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKK@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140605b40
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@W4Unk_SocketSpecialStat@@HU?$less@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@PEAX@2@@Z 0x14060ac90
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@W4Unk_SocketSpecialStat@@HU?$less@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@PEAX@2@@Z 0x14060b0a0
// MS2-PIN: ?_Mysize@?$_List_alloc@U?$_List_base_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@@std@@QEAAAEA_KXZ 0x14060ea80
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@W4Unk_SocketSpecialStat@@HU?$less@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@$$CBW4Unk_SocketSpecialStat@@H@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x14060f600
// MS2-PIN: ?_Unchecked_end@?$list@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@2@@std@@QEAA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VItemOptionRandom@@@@@std@@@std@@@std@@@2@XZ 0x14060fb00
// MS2-PIN: ??_7CItemOptionTable@@6B?$TSingleton@VCItemOptionTable@@@@@ 0x142d691b8
// MS2-PIN: ??_7CItemOptionTable@@6B?$CValidData@VCItemOptionTable@@@@@ 0x142d691c8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemoptiondata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <time.h>
#include <ppl.h>
#include <cmath>
#include <algorithm>
#include "itemoption.h"
#include "itemoptiondata.h"
#include "citemoptiontable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/client/ms2/randomeffectparam.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

static CString s_sortNames[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};

MS2Ptr<CItemData> FUN_14053f870(int nItemId);          // the item data of an item id
CItemOptionTable* FUN_140166430();                      // the option table singleton
CString FUN_14016a5c0(const char* psz, int n);
CLogString* FUN_140166440();                            // the log
void FUN_14015eb90(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg);
void FUN_140177a80(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const unsigned& nArg);
// The log's two-argument call (FMT_VARIADIC instantiation outside this unit).
void FUN_1401e0850(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const CString& first,
                   const unsigned& second);
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
void FUN_14028f5d0(Unk_140165cf0* pParent, const char* pszChild, std::vector<Unk_140165cf0*>& arrOut);
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, int& nOut);
const CString& FUN_14082efb0(int nStat);                // the xml name of a stat
const CString& FUN_14081d380(int nStat);                // the xml name of a special stat
unsigned FUN_140767ff0();                               // random number
bool FUN_14053fc90(int nItemId);                        // the item is in the first remake stone class
bool FUN_14053fd10(int nItemId);
bool FUN_14053fd50(int nItemId);
int FUN_14053feb0(int nItemId);                         // the fixed rank of an item (0: none)
int FUN_1406516b0();                                    // the language / region id
float FUN_14028aaf0();                                  // FLT_EPSILON-like constant (2^-23)
float FUN_14028aed0(float f);                           // floorf
extern "C" float(__cdecl* __imp_powf)(float, float);

// <cmath> pow(float, int) (0x1406122f0); the exe calls powf through the CRT import table, which the cmath inline
// (powf as an /Oi intrinsic) does not, so this copy calls __imp_powf directly.
inline float Ms2PowFI(float _Xx, int _Yx)
{
    if (_Yx == 2)
        return (_Xx * _Xx);
    return (__imp_powf(_Xx, static_cast<float>(_Yx)));
}
class Unk_GameRule { public: unsigned FUN_14047f720(unsigned nMeso); };   // CGameRule: the meso cost rate
Unk_GameRule* FUN_1401c0d90();
class Unk_EnchantRates { public: int FUN_140594810(int nItemId); };    // the remake cost rates (item.cpp)
Unk_EnchantRates* FUN_14052d1e0();

// RTTI Probability::LogContext (probability.cpp, unrecovered): only held through MS2Ptr here, so just the CPtred base.
namespace Probability { class LogContext : public CPtred {}; }

// RTTI CItemRemakeOptionIngredient: the cost box of an option remake; only the container is used here.
class CItemRemakeOptionIngredient : public CPtred
{
public:
    MS2SvrPtr<CIngredientContainer> m_spContainer;      // +0x18
};
MS2_CHECK_OFFSET(CItemRemakeOptionIngredient, m_spContainer, 0x18);

// The unit's three-argument log call (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class T, class U, class V>
inline void Unk_ItemOptionLog(CLogString* log, int level, int category, const wchar_t* format, const T& first,
                              const U& second, const V& third)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(third)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third), args));
}

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CItemOptionTable::s_bInit;
#endif

// @0x1405f4140
CItemOptionTable::CItemOptionTable()
{
    m_rankProbs[std::make_pair(1, 1)].AssignRaw(new ProbabilityFromRank(96.9284f, 3.0566f, 0.015f, 0.0f, 0.0f));
    m_rankProbs[std::make_pair(2, 1)].AssignRaw(new ProbabilityFromRank(63.2369f, 36.7402f, 0.0229f, 0.0f, 0.0f));
    m_rankProbs[std::make_pair(3, 1)].AssignRaw(new ProbabilityFromRank(0.0954f, 91.1777f, 8.7269f, 0.0f, 0.0f));
    m_rankProbs[std::make_pair(4, 1)].AssignRaw(new ProbabilityFromRank(0.004f, 29.7556f, 70.2404f, 0.0f, 0.0f));
    m_rankProbs[std::make_pair(5, 1)].AssignRaw(new ProbabilityFromRank(0.0f, 10.0f, 70.0f, 20.0f, 0.0f));
}

// @0x1405f4640
CItemOptionTable::~CItemOptionTable()
{
}

// @0x1405f4720
bool CItemOptionTable::FUN_1405f4720()
{
    FUN_1405f78f0();
    LoadItemOptionVariation();
    SetInit(true);
    if (m_constants.empty())
    {
        LoadItemOptionConstant();
        LoadItemOptionRandom();
    }
    if (!FUN_1405f8770())
        return false;
    return true;
}

// @0x1405f47a0
// MS2-FUNCTIONAL: exe 18 bytes longer (the (std::max)<unsigned> temporaries are laid out differently)
// The remake cost of an item (the stone by slot, meso and the second stone, scaled by item level, remake count and rank).
void CItemOptionTable::FUN_1405f47a0(int nItemId, int nLevel, int nRank, unsigned short nItemLevel,
                                     const CItemRemakeOptionIngredient& kIngredient)
{
    float fEpsilon = FUN_14028aaf0();
    int nStat = 0;
    if (FUN_14053fc90(nItemId))
        nStat = 0x5d;
    else if (FUN_14053fd10(nItemId))
        nStat = 0x5f;
    else if (FUN_14053fd50(nItemId))
        nStat = 0x5e;
    int nRate = FUN_14052d1e0()->FUN_140594810(nItemId);
    unsigned nStone = FUN_14053fd50(nItemId) ? 5 : 1;
    unsigned nMeso = 1;
    unsigned nSecond = 1;
    float fBase = 1.24f;
    unsigned nLv = nItemLevel;
    int nRegion = FUN_1406516b0();
    if (nRegion == 0)
        nLv = (std::min)(56u, nLv);
    else
        nLv = (std::min)(50u, nLv);
    nLevel = (std::min)(nLevel, 14);
    if (nLevel < 10)
        fBase = 1.25f;
    nStone = (unsigned)(nStone * ((nLv - 50.0) / 10.0 + 1.0)) * nRate;
    nMeso = (unsigned)(FUN_14028aed0((Ms2PowFI(fBase, nLevel) + fEpsilon) * 200.0f) * (float)nRate);
    nSecond = (nLevel + 11 + (std::max)(0u, nLv - 50)) * nRate;
    if (nRegion == 0)
    {
        if (nItemLevel < 60)
        {
            if (nRank > 4)
            {
                nStone *= 5;
                nMeso *= 2;
                nSecond *= 3;
            }
        }
        else if (nRank == 5)
        {
            nStone *= 5;
            nMeso *= 10;
            nSecond *= 15;
        }
        else if (nRank > 5)
        {
            nStone *= 5;
            nMeso *= 12;
            nSecond *= 15;
        }
    }
    else if (nRank > 4)
    {
        nStone *= 5;
        if (nRank < 6)
            nMeso *= 10;
        else
            nMeso *= 12;
        nSecond *= 15;
    }
    nStone = (std::max)(1u, nStone);
    nMeso = (std::max)(1u, nMeso);
    nSecond = (std::max)(1u, nSecond);
    MS2SvrPtr<CIngredientContainer> spContainer = kIngredient.m_spContainer;
    if (spContainer == 0)
        return;
    spContainer->FUN_14026bd10(nStat, nStone);
    spContainer->FUN_14026bd10(0x60, nMeso);
    spContainer->FUN_14026bd10(0x5c, nSecond);
}

// @0x1405f4bb0
// The remake cost of a pet / non-equip option (by remake count and rank).
void CItemOptionTable::FUN_1405f4bb0(int nLevel, int nRank, const CItemRemakeOptionIngredient& kIngredient)
{
    double dEpsilon = 1e-05;
    MS2SvrPtr<CIngredientContainer> spContainer = kIngredient.m_spContainer;
    if (spContainer == 0)
        return;
    nLevel = (std::min)(nLevel, 14);
    int nStone = 5;
    double dMeso = 100.0 * pow(1.15, nLevel);
    unsigned nMeso = (unsigned)(dMeso + dEpsilon);
    int nSecond = nLevel * 20 + 100;
    if (nRank >= 4)
    {
        nStone *= 2;
        nMeso *= 3;
        nSecond *= 5;
    }
    nMeso = FUN_1401c0d90()->FUN_14047f720(nMeso);
    spContainer->FUN_14026bd10(0x5d, nStone);
    spContainer->FUN_14026bd10(0x60, nMeso);
    spContainer->FUN_14026bd10(0x5c, nSecond);
}

// @0x1405f4d30
// A random rank for an item of an option group and level (the item's fixed rank when it has one).
int CItemOptionTable::FUN_1405f4d30(int nItemId, int nGroup, unsigned short nLevel, int nSeed, bool bSecond) const
{
    CheckInit();
    int nFixed = FUN_14053feb0(nItemId);
    if (nFixed != 0)
        return nFixed;
    std::pair<int, int> kKey(nGroup, nLevel);
    std::map<std::pair<int, int>, MS2Ptr<ProbabilityFromRank> >::const_iterator it;
    std::map<std::pair<int, int>, MS2Ptr<ProbabilityFromRank> >::const_iterator itEnd;
    if (bSecond)
    {
        it = m_rankProbs2.find(kKey);
        itEnd = m_rankProbs2.end();
    }
    else
    {
        it = m_rankProbs.find(kKey);
        itEnd = m_rankProbs.end();
    }
    if (it != itEnd)
    {
        const MS2Ptr<ProbabilityFromRank>& spProb = it->second;
        Unk_Random random(nSeed);
        unsigned nRoll = random.FUN_1407684c0() % 1000000;
        float fRoll = (float)nRoll / 10000.0f;
        float fSum = spProb->m_f28;
        if (fRoll < fSum)
            return 5;
        fSum += spProb->m_f24;
        if (fRoll < fSum)
            return 4;
        fSum += spProb->m_f20;
        if (fRoll < fSum)
            return 3;
        fSum += spProb->m_f1c;
        if (fRoll < fSum)
            return 2;
    }
    return 1;
}

// @0x1405f4ff0
// A new option of an item: its constant rows up to the rank and a random roll.
MS2Ptr<CItemOption> CItemOptionTable::FUN_1405f4ff0(MS2Ptr<CItemData> spItem, int nRank, Unk_Random* pRandom)
{
    if (spItem == 0)
        return MS2Ptr<CItemOption>(0);
    MS2Ptr<CItemOption> spOption(new CItemOption(spItem->FUN_14053c510()));
    unsigned nConstantId = spItem->FUN_14053efd0();
    if (nConstantId != 0)
    {
        MS2Ptr<ItemOptionConstant> spConstant = FUN_1405f5ee0(nConstantId, nRank);
        if (spConstant.get() != 0)
            spConstant->FUN_1405d2e70(spOption, nRank);
    }
    int nRandomId = spItem->FUN_14053eff0(nRank);
    if (nRandomId != 0)
    {
        MS2Ptr<ItemOptionRandom> spRandom = FUN_1405f6010(nRandomId);
        if (spRandom.get() != 0)
            spRandom->FUN_1405d3f70(spOption, nRank, pRandom);
    }
    return spOption;
}

// @0x1405f5290
// A new option from a preset (the preset's fixed random rows when it has a type).
MS2Ptr<CItemOption> CItemOptionTable::FUN_1405f5290(MS2Ptr<Unk_ItemOptionPreset> spPreset, Unk_Random* pRandom)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(spPreset->m_nItemId);
    if (spItem == 0)
        return MS2Ptr<CItemOption>(0);
    MS2Ptr<CItemOption> spOption(new CItemOption(spPreset->m_nItemId));
    unsigned nConstantId = spItem->FUN_14053efd0();
    if (nConstantId != 0)
    {
        MS2Ptr<ItemOptionConstant> spConstant = FUN_1405f5ee0(nConstantId, spPreset->m_nRank);
        if (spConstant.get() != 0)
            spConstant->FUN_1405d2e70(spOption, spPreset->m_nRank);
    }
    if (spPreset->m_nType != 0)
    {
        int nRandomId = spItem->FUN_14053eff0(spPreset->m_nRank);
        if (nRandomId != 0)
        {
            MS2Ptr<ItemOptionRandom> spRandom = FUN_1405f6010(nRandomId);
            if (spRandom.get() != 0)
                spRandom->FUN_1405d4270(spPreset, spOption, spPreset->m_nRank, pRandom);
        }
    }
    return spOption;
}

// @0x1405f5620
// Rerolls the random rows of an option (the constant rows are rebuilt first).
bool CItemOptionTable::FUN_1405f5620(MS2Ptr<CItemOption> spOption, int nItemId, int nRank)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return false;
    CheckInit();
    Unk_Random random(time(0));
    spOption->FUN_1405cb190(0);
    if (!FUN_1405f5870(spOption, nItemId, nRank))
        return false;
    int nRandomId = spItem->FUN_14053eff0(nRank);
    MS2Ptr<ItemOptionRandom> spRandom = FUN_1405f6010(nRandomId);
    if (spRandom == 0)
        return false;
    return spRandom->FUN_1405d6020(spOption, nRank, &random);
}

// @0x1405f5870
// Rebuilds the constant rows of an option.
bool CItemOptionTable::FUN_1405f5870(MS2Ptr<CItemOption> spOption, int nItemId, int nRank)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return false;
    unsigned nConstantId = spItem->FUN_14053efd0();
    MS2Ptr<ItemOptionConstant> spConstant = FUN_1405f5ee0(nConstantId, nRank);
    if (spConstant.get() != 0)
        spConstant->FUN_1405d2e70(spOption, nRank);
    return true;
}

// @0x1405f59b0
bool CItemOptionTable::FUN_1405f59b0(MS2Ptr<Unk_1405e74c0> spTarget, Unk_Random* pRandom)
{
    CheckInit();
    if (spTarget == 0)
        return false;
    MS2Ptr<CItemData> spItem = FUN_14053f870(spTarget->m_nItemId);
    if (spItem == 0)
        return false;
    int nRandomId = spItem->FUN_14053eff0(spTarget->m_nRank);
    if (nRandomId == 0)
        return false;
    MS2Ptr<ItemOptionRandom> spRandom = FUN_1405f6010(nRandomId);
    if (spRandom == 0)
        return false;
    return spRandom->FUN_1405d4bb0(spTarget, pRandom);
}

// @0x1405f5ba0
bool CItemOptionTable::FUN_1405f5ba0(MS2Ptr<Unk_1405e74c0> spTarget, Unk_Random* pRandom)
{
    CheckInit();
    if (spTarget == 0)
        return false;
    MS2Ptr<CItemData> spItem = FUN_14053f870(spTarget->m_nItemId);
    if (spItem == 0)
        return false;
    int nRandomId = spItem->FUN_14053eff0(spTarget->m_nRank);
    if (nRandomId == 0)
        return false;
    MS2Ptr<ItemOptionRandom> spRandom = FUN_1405f6010(nRandomId);
    if (spRandom == 0)
        return false;
    return spRandom->FUN_1405d55e0(spTarget, pRandom);
}

// @0x1405f5d90
bool CItemOptionTable::FUN_1405f5d90(int nItemId)
{
    CheckInit();
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return false;
    unsigned nId = spItem->FUN_14053efd0();
    auto it = m_constants.lower_bound(nId);
    if (it != m_constants.end() && it->first == nId)
        return true;
    return false;
}

// @0x1405f5e90
int CItemOptionTable::FUN_1405f5e90(int nCode, int nRank, CString strTag, CString strInfo)
{
    return 1;
}

// @0x1405f5ee0
MS2Ptr<ItemOptionConstant> CItemOptionTable::FUN_1405f5ee0(unsigned nId, int nGrade) const
{
    CheckInit();
    int nBest = 0;
    MS2Ptr<ItemOptionConstant> spResult;
    auto range = m_constants.equal_range(nId);
    for (; range.first != range.second; ++range.first)
    {
        MS2Ptr<ItemOptionConstant> spConstant = range.first->second;
        if (nGrade >= spConstant->FUN_1405d2a70() && nGrade >= nBest)
        {
            spResult = spConstant;
            nBest = spConstant->FUN_1405d2a70();
        }
    }
    return spResult;
}

// @0x1405f6010
MS2Ptr<ItemOptionRandom> CItemOptionTable::FUN_1405f6010(int nId) const
{
    CheckInit();
    MS2Ptr<ItemOptionRandom> spResult;
    auto it = m_randoms.find(nId);
    if (it == m_randoms.end())
        return MS2Ptr<ItemOptionRandom>(0);
    return it->second;
}

// @0x1405f6100
int CItemOptionTable::FUN_1405f6100(unsigned nStatId)
{
    CheckInit();
    auto it = m_variations.find(nStatId);
    if (it == m_variations.end())
        return 0;
    return it->second->FUN_1405d3a40();
}

// @0x1405f6190
int CItemOptionTable::FUN_1405f6190(unsigned nStatId, Unk_Random* pRandom)
{
    CheckInit();
    auto it = m_variations.find(nStatId);
    if (it == m_variations.end())
        return 0;
    return it->second->FUN_1405d3a90(pRandom);
}

// @0x1405f6230
int CItemOptionTable::FUN_1405f6230(unsigned nStatId)
{
    CheckInit();
    auto it = m_variations.find(nStatId);
    if (it == m_variations.end())
        return 0;
    return it->second->FUN_1405d3ae0();
}

// @0x1405f62c0
int CItemOptionTable::FUN_1405f62c0(unsigned nStatId)
{
    CheckInit();
    auto it = m_variations.find(nStatId);
    if (it == m_variations.end())
        return 0;
    return it->second->FUN_1405d3b30();
}

// @0x1405f6350
int CItemOptionTable::FUN_1405f6350(unsigned nStatId)
{
    CheckInit();
    auto it = m_variations.find(nStatId);
    if (it == m_variations.end())
        return 0;
    return it->second->FUN_1405d3b80();
}

// @0x1405f63e0
// MS2-FUNCTIONAL: the exe stores the pair(0, 0) argument temporaries left to right (first at +0x24 before +0x20)
std::pair<int, int> CItemOptionTable::FUN_1405f63e0(unsigned nStatId)
{
    std::pair<int, int> kResult(0, 0);
    CheckInit();
    auto it = m_variations.find(nStatId);
    if (it == m_variations.end())
        return kResult;
    kResult.first = it->second->FUN_1405d3ae0();
    kResult.second = it->second->FUN_1405d3b30();
    return kResult;
}

// @0x1405f64e0
// MS2-FUNCTIONAL: the exe stores the pair(0, 0) argument temporaries left to right (first at +0x24 before +0x20)
std::pair<int, int> CItemOptionTable::FUN_1405f64e0(int nItemId, int nRank, int nStat)
{
    std::pair<int, int> kResult(0, 0);
    CheckInit();
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return kResult;
    MS2Ptr<ItemOptionRandom> spRandom = FUN_1405f6010(spItem->FUN_14053eff0(nRank));
    if (spRandom == 0)
        return kResult;
    kResult = FUN_1405f63e0(spRandom->FUN_1405d7680(nStat));
    return kResult;
}

// @0x1405f6650
// MS2-FUNCTIONAL: the exe stores the pair(0, 0) argument temporaries left to right; 2 bytes longer
std::pair<int, int> CItemOptionTable::FUN_1405f6650(int nItemId, int nRank, unsigned nSpecial)
{
    std::pair<int, int> kResult(0, 0);
    CheckInit();
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return kResult;
    unsigned nId = spItem->FUN_14053eff0(nRank);
    MS2Ptr<ItemOptionRandom> spRandom = FUN_140166430()->FUN_1405f6010(nId);
    if (spRandom == 0)
        return kResult;
    kResult = FUN_1405f63e0(spRandom->FUN_1405d7710(nSpecial));
    return kResult;
}

// @0x1405f67e0
// MS2-FUNCTIONAL: exe 4 bytes longer (one wider stack displacement: a temporary slot not reproduced)
// The stat value is in the top band of its variation row (the item must be level 50+).
bool CItemOptionTable::FUN_1405f67e0(MS2Ptr<CItem> spItem, int nStat, int nUnused, int nValue)
{
    CheckInit();
    if (spItem->FUN_1405282d0() < 50)
        return false;
    MS2Ptr<CItemData> spData = FUN_14053f870(spItem->FUN_1405276c0());
    if (spData == 0)
        return false;
    unsigned nRank = spItem->FUN_140526bd0();
    unsigned nRandomId = spData->FUN_14053eff0(nRank);
    MS2Ptr<ItemOptionRandom> spRandom = FUN_140166430()->FUN_1405f6010(nRandomId);
    if (spRandom == 0)
        return false;
    int nId = spRandom->FUN_1405d7680(nStat);
    int nHigh = FUN_1405f6350(nId);
    if (nHigh == 0)
        return false;
    std::pair<int, int> kRange = FUN_1405f63e0(nId);
    if (kRange.first == kRange.second)
        return true;
    if (kRange.first < nValue)
        return nHigh <= nValue;
    return false;
}

// @0x1405f6a90
// MS2-FUNCTIONAL: exe 4 bytes longer (one wider stack displacement: a temporary slot not reproduced)
// The special stat value is in the top band of its variation row (the item must be level 50+).
bool CItemOptionTable::FUN_1405f6a90(MS2Ptr<CItem> spItem, unsigned nSpecial, int nUnused, int nValue)
{
    CheckInit();
    if (spItem->FUN_1405282d0() < 50)
        return false;
    MS2Ptr<CItemData> spData = FUN_14053f870(spItem->FUN_1405276c0());
    if (spData == 0)
        return false;
    unsigned nRank = spItem->FUN_140526bd0();
    unsigned nRandomId = spData->FUN_14053eff0(nRank);
    MS2Ptr<ItemOptionRandom> spRandom = FUN_140166430()->FUN_1405f6010(nRandomId);
    if (spRandom == 0)
        return false;
    int nId = spRandom->FUN_1405d7710(nSpecial);
    int nHigh = FUN_1405f6350(nId);
    if (nHigh == 0)
        return false;
    std::pair<int, int> kRange = FUN_1405f63e0(nId);
    if (kRange.first == kRange.second)
        return true;
    if (kRange.first < nValue)
        return nHigh <= nValue;
    return false;
}

// @0x1405f6d40
int CItemOptionTable::FUN_1405f6d40(MS2Ptr<CItemData> spItem, int nRank, unsigned nSpecial)
{
    if (spItem == 0)
        return 0;
    MS2Ptr<ItemOptionRandom> spRandom = FUN_1405f6010(spItem->FUN_14053eff0(nRank));
    if (spRandom == 0)
        return 0;
    int nValue = FUN_1405f62c0(spRandom->FUN_1405d7710(nSpecial));
    return nValue;
}

// @0x1405f6e40
Unk_OptionNameListPtr CItemOptionTable::FUN_1405f6e40(const CString& strName)
{
    CheckInit();
    Unk_OptionNameListPtr spList(0);
    m_names.Lookup(strName, spList);
    return spList;
}

// @0x1405f6ed0
int CItemOptionTable::FUN_1405f6ed0(Unk_SocketSpecialStat nKey) const
{
    auto it = m_f8.find(nKey);
    if (it == m_f8.end())
        return 0;
    return it->second;
}

// @0x1405f6f50
void CItemOptionTable::FUN_1405f6f50(MS2Ptr<CItemData> spItem, int nRank, unsigned nTrials,
                                     const std::vector<std::pair<int, int> >& vLocked, std::vector<CStringW>* pOut)
{
    if (spItem == 0)
        return;
    MS2Ptr<CItemOption> spOption(new CItemOption(spItem->FUN_14053c510()));
    MS2Ptr<ItemOptionRandom> spRandom = FUN_1405f6010(spItem->FUN_14053eff0(nRank));
    if (spRandom.get() != 0)
        spRandom->FUN_1405d6560(spOption, nRank, nTrials, vLocked, pOut);
}

// @0x1405f70f0
// The roll statistics of nTrials parallel random rolls: how often each stat value came up (all rows, or only the
// nIndex-th roll), as "name:count" and "name:idx value:count" lines (also logged), with the probability logs.
void CItemOptionTable::FUN_1405f70f0(MS2Ptr<CItemData> spItem, int nRank, unsigned nTrials,
                                     const std::vector<std::pair<int, int> >& vLocked, std::vector<CStringW>* pOut,
                                     unsigned nPickCount, int nIndex, Unk_ProbabilityLog& vLogs)
{
    if (spItem == 0)
        return;
    MS2Ptr<ItemOptionRandom> spRandom = FUN_1405f6010(spItem->FUN_14053eff0(nRank));
    if (spRandom == 0)
        return;
    vLogs.reserve(vLogs.size() + nTrials * 2);
    CLockCriticalSection lock;
    unsigned nTotal = 0;
    std::map<CString, std::map<unsigned long, unsigned long> > mapCounts;
    std::vector<unsigned char> vTrials(nTrials);
    // @0x140606450 (the lambda body)
    // MS2-FUNCTIONAL: lambda body frame 0x10 smaller in the exe (0x3a8 vs 0x3b8: one temporary fewer), slots shifted
    Concurrency::parallel_for_each(std::begin(vTrials), std::end(vTrials),
        [&spItem, &spRandom, &nRank, &vLocked, &nPickCount, &lock, &vLogs, &nIndex, &mapCounts, &nTotal](unsigned char)
        {
            MS2Ptr<CItemOption> spOption(new CItemOption(spItem->FUN_14053c510()));
            Unk_ProbabilityLog vLocal;
            Unk_Random random(FUN_140767ff0());
            spRandom->FUN_1405d48d0(spOption, nRank, &random, vLocked, nPickCount, &vLocal);
            Unk_EnchantMap& kStats = spOption->FUN_1405cb8a0(2);
            Unk_SocketSpecialMap& kSpecials = spOption->FUN_1405cb8d0(2);
            Unk_CriticalSectionLock guard(lock, 1);
            vLogs.insert(vLogs.end(), vLocal.begin(), vLocal.end());
            if (nIndex == 0)
            {
                POSITION pos = kStats.GetStartPosition();
                while (pos != NULL)
                {
                    int nKey = kStats.GetKeyAt(pos);
                    int nValue = kStats.GetValueAt(pos)->FUN_140266e30();
                    CString strName = FUN_14082efb0(nKey);
                    if (mapCounts.find(strName) == mapCounts.end())
                        mapCounts.insert(std::make_pair(strName, std::map<unsigned long, unsigned long>()));
                    mapCounts[strName][nValue]++;
                    nTotal++;
                    kStats.GetNext(pos);
                }
                pos = kSpecials.GetStartPosition();
                while (pos != NULL)
                {
                    int nKey = kSpecials.GetKeyAt(pos);
                    int nValue = kSpecials.GetValueAt(pos)->FUN_140266e30();
                    CString strName = FUN_14081d380(nKey);
                    if (mapCounts.find(strName) == mapCounts.end())
                        mapCounts.insert(std::make_pair(strName, std::map<unsigned long, unsigned long>()));
                    mapCounts[strName][nValue]++;
                    nTotal++;
                    kSpecials.GetNext(pos);
                }
            }
            else
            {
                POSITION pos = kStats.GetStartPosition();
                while (pos != NULL)
                {
                    Unk_EnchantPtr<BaseOption> spBase = kStats.GetValueAt(pos);
                    if (spBase->m_nIndex == nIndex - 1)
                    {
                        int nKey = kStats.GetKeyAt(pos);
                        int nValue = spBase->FUN_140266e30();
                        CString strName = FUN_14082efb0(nKey);
                        if (mapCounts.find(strName) == mapCounts.end())
                            mapCounts.insert(std::make_pair(strName, std::map<unsigned long, unsigned long>()));
                        mapCounts[strName][nValue]++;
                        nTotal++;
                    }
                    kStats.GetNext(pos);
                }
                pos = kSpecials.GetStartPosition();
                while (pos != NULL)
                {
                    Unk_EnchantPtr<BaseOption> spBase = kSpecials.GetValueAt(pos);
                    if (spBase->m_nIndex == nIndex - 1)
                    {
                        int nKey = kSpecials.GetKeyAt(pos);
                        int nValue = spBase->FUN_140266e30();
                        CString strName = FUN_14081d380(nKey);
                        if (mapCounts.find(strName) == mapCounts.end())
                            mapCounts.insert(std::make_pair(strName, std::map<unsigned long, unsigned long>()));
                        mapCounts[strName][nValue]++;
                        nTotal++;
                    }
                    kSpecials.GetNext(pos);
                }
            }
        });
    if (nPickCount == 0)
    {
        MS2Ptr<CItemOption> spOption(new CItemOption(spItem->FUN_14053c510()));
        Unk_Random random(FUN_140767ff0());
        spRandom->FUN_1405d48d0(spOption, nRank, &random, vLocked, 0, NULL);
        nPickCount = spRandom->FUN_1405d5fe0(nRank);
    }
    pOut->push_back(StringFormat(L"pickCount {0}", nPickCount));
    if (FUN_140166440() != 0)
        FUN_140177a80(FUN_140166440(), 0xb, 0x13, L"pickCount {0}", nPickCount);
    pOut->push_back(StringFormat(L"TotalCount {0}", nTotal));
    if (FUN_140166440() != 0)
        FUN_140177a80(FUN_140166440(), 0xb, 0x13, L"TotalCount {0}", nTotal);
    for (auto& kCount : mapCounts)
    {
        unsigned nSum = 0;
        for (auto& kValue : kCount.second)
            nSum += kValue.second;
        pOut->push_back(StringFormat(L"{0}:{1}", kCount.first, nSum));
        if (FUN_140166440() != 0)
            FUN_1401e0850(FUN_140166440(), 0xb, 0x13, L"{0}:{1}", kCount.first, nSum);
        for (auto& kValue : kCount.second)
        {
            unsigned nValue = kValue.first;
            unsigned nCount = kValue.second;
            pOut->push_back(StringFormat(L"{0}:idx{1}:{2}", kCount.first, nValue, nCount));
            if (FUN_140166440() != 0)
                Unk_ItemOptionLog(FUN_140166440(), 0xb, 0x13, L"{0}:idx{1}:{2}", kCount.first, nValue, nCount);
        }
    }
}

// @0x1405f78f0
// The exclusive option groups (the attack / defense stats that share one roll) and the display order of the special
// stats; built once.
void CItemOptionTable::FUN_1405f78f0()
{
    if (m_names.IsEmpty())
    {
        Unk_OptionNameListPtr spList;
        spList = Unk_SocketNew(0);
        spList->AddTail(FUN_14082efb0(0x17));
        spList->AddTail(FUN_14082efb0(0x18));
        spList->AddTail(FUN_14082efb0(0));
        spList->AddTail(FUN_14082efb0(2));
        spList->AddTail(FUN_14082efb0(3));
        spList->AddTail(FUN_14082efb0(1));
        spList->AddTail(FUN_14082efb0(0xf));
        spList->AddTail(FUN_14082efb0(0xd));
        spList->AddTail(FUN_14082efb0(0x1f));
        spList->AddTail(FUN_14081d380(0x1b));
        spList->AddTail(FUN_14081d380(0x1a));
        spList->AddTail(FUN_14081d380(9));
        spList->AddTail(FUN_14081d380(0xb));
        spList->AddTail(FUN_14081d380(0xc));
        spList->AddTail(FUN_14081d380(0x23));
        m_names.RemoveAll();
        m_names.SetAt(FUN_14082efb0(0x17), spList);
        m_names.SetAt(FUN_14082efb0(0x18), spList);
        m_names.SetAt(FUN_14082efb0(0), spList);
        m_names.SetAt(FUN_14082efb0(2), spList);
        m_names.SetAt(FUN_14082efb0(3), spList);
        m_names.SetAt(FUN_14082efb0(1), spList);
        m_names.SetAt(FUN_14082efb0(0xf), spList);
        m_names.SetAt(FUN_14082efb0(0xd), spList);
        m_names.SetAt(FUN_14082efb0(0x1f), spList);
        m_names.SetAt(FUN_14081d380(0x1b), spList);
        m_names.SetAt(FUN_14081d380(0x1a), spList);
        m_names.SetAt(FUN_14081d380(9), spList);
        m_names.SetAt(FUN_14081d380(0xb), spList);
        m_names.SetAt(FUN_14081d380(0xc), spList);
        m_names.SetAt(FUN_14081d380(0x23), spList);
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0xc3, 1));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0xc4, 2));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0x18, 3));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0x19, 4));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0xb4, 5));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0x1a, 6));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0x1b, 7));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0xbc, 8));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0xbb, 9));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0xba, 10));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0xbe, 11));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)0xbf, 12));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)7, 13));
        m_f8.insert(std::make_pair((Unk_SocketSpecialStat)199, 14));
    }
}

// @0x1405f8310
bool CItemOptionTable::LoadItemOptionConstant()
{
    CString strPath = FUN_14071a5b0("Table", "ItemOptionConstant.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    CLockCriticalSection lock;
    std::vector<Unk_140165cf0*> elems;
    FUN_14028f5d0(pRoot, "option", elems);
    // @0x140606110 (the lambda body)
    // MS2-FUNCTIONAL: lambda body 1 byte longer in the exe (temporary slot order differs)
    Concurrency::parallel_for_each(std::begin(elems), std::end(elems), [&lock, this](Unk_140165cf0* pElem) {
        int nCode = 0;
        FUN_140873220(pElem, "code", nCode);
        if (nCode != 0)
        {
            std::vector<Unk_140165cf0*> children;
            FUN_14028f5d0(pElem, "rank", children);
            for (auto& pChild : children)
            {
                MS2Ptr<ItemOptionConstant> spConstant(new ItemOptionConstant);
                spConstant->FUN_1405d2a50(nCode);
                if (!spConstant->FUN_1405d2a90(pChild))
                    continue;
                Unk_CriticalSectionLock guard(lock, 1);
                m_constants.insert(std::make_pair(nCode, spConstant));
            }
        }
    });
    return true;
}

// @0x1405f8540
bool CItemOptionTable::LoadItemOptionRandom()
{
    CString strPath = FUN_14071a5b0("Table", "ItemOptionRandom.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    CLockCriticalSection lock;
    std::vector<Unk_140165cf0*> elems;
    FUN_14028f5d0(pRoot, "option", elems);
    // @0x140606320 (the lambda body)
    Concurrency::parallel_for_each(std::begin(elems), std::end(elems), [&lock, this](Unk_140165cf0* pElem) {
        MS2Ptr<ItemOptionRandom> spRandom(new ItemOptionRandom);
        if (!spRandom->Load(pElem))
            return;
        Unk_CriticalSectionLock guard(lock, 1);
        m_randoms.insert(std::make_pair(spRandom->FUN_1405d3c80(), (ItemOptionRandom*)spRandom));
    });
    return true;
}

// @0x1405f8770
bool CItemOptionTable::FUN_1405f8770()
{
    return true;
}

// @0x1405f8780
bool CItemOptionTable::LoadItemOptionVariation()
{
    CString strPath = FUN_14071a5b0("Table", "itemOptionVariation.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pElem : pRoot->FUN_140165cf0("option"))
    {
        MS2Ptr<ItemOptionVariationData> spData(new ItemOptionVariationData);
        spData->FUN_1405d3870(pElem);
        int nId = spData->FUN_1405d3a20();
        m_variations.insert(std::make_pair(nId, spData));
    }
    return true;
}

// @0x140604020
CItemOptionTable::ProbabilityFromRank::ProbabilityFromRank(float f18, float f1c, float f20, float f24, float f28)
{
    m_f18 = f18;
    m_f1c = f1c;
    m_f20 = f20;
    m_f24 = f24;
    m_f28 = f28;
}

// @0x140608280
void CItemOptionTable::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemOptionTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1406124b0 (the CRT memmove_s tail)
MS2_EMIT_CRT_MEMMOVE_S();
