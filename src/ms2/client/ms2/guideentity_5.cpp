// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Parts 5-7 of client\ms2\guideentity.cpp: the template glue of
// the guide manager's containers (std tree erase / rebalance / iterator helpers, ATL map / red-black map nodes, allocator
// and construct helpers). See ms2/placeholder/cguidemanager.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: client\ms2\guideentity.cpp#5
// MS2-RANGE: 0x141398800-0x141399320 .text$mn
// MS2-RANGE: 0x141399600-0x1413a03c0 .text$mn
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@2@@Z 0x14139c960
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@IEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@@Z 0x14139edb0
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@IEAAXXZ 0x14139fee0
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@HU?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@4@$0A@@std@@@std@@IEAAXXZ 0x14139fe80
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??A?$map@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@@std@@QEAAAEAV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@1@AEBH@Z 0x141398880 ; prop
// MS2-PIN: ??A?$map@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@@std@@QEAAAEAVGuideOccurContainer@@AEBW4Occurrence@CGuideManager@@@Z 0x1413988c0 ; prop
// MS2-PIN: ??C?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@1@XZ 0x141398940 ; prop
// MS2-PIN: ??C?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@std@@QEBAPEBU?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@1@XZ 0x141398980 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBW4Occurrence@CGuideManager@@H@1@XZ 0x141398a90 ; prop
// MS2-PIN: ??E?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141398b40 ; prop
// MS2-PIN: ??E?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141398bb0 ; prop
// MS2-PIN: ?Find@?$CRBTree@IV?$MS2Ptr@VCGuideEntity@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCGuideEntity@@@@@3@@ATL@@IEBAPEAVCNode@12@I@Z 0x141399710 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@IV?$MS2Ptr@VCGuideEntity@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCGuideEntity@@@@@3@@ATL@@AEAAPEAVCNode@12@IAEBV?$MS2Ptr@VCGuideEntity@@@@@Z 0x141399d70 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEBA_NIAEAI@Z 0x14139a080 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEAAPEAU__POSITION@@II@Z 0x14139b260 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@HU?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@2@XZ 0x14139b970 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@2@XZ 0x14139baf0 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@JU?$less@J@std@@V?$allocator@J@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@JPEAX@2@XZ 0x14139bbb0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@2@XZ 0x14139bd30 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@2@XZ 0x14139bef0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@2@XZ 0x14139bfd0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x14139c3f0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@IEBA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x14139c430 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x14139c510 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@HU?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@4@$0A@@std@@@std@@QEAAXXZ 0x14139c570 ; caller 0x141396ef0
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAAXXZ 0x14139c5a0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@2@@Z 0x14139c680 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@@Z 0x14139c6d0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@2@@Z 0x14139c720 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@2@@Z 0x14139c780 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@@Z 0x14139c820 ; prop
// MS2-PIN: ?_Freeheadnode@?$_List_alloc@U?$_List_base_types@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEAAXPEAU?$_List_node@V?$MS2Ptr@VCGuideEntity@@@@PEAX@2@@Z 0x14139e160 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@HU?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@2@@Z 0x14139e1f0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@2@XZ 0x14139e400 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@HU?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@4@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@std@@@2@XZ 0x14139e430 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@HU?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@4@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@std@@@2@XZ 0x14139e460 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@XZ 0x14139e490 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@JU?$less@J@std@@V?$allocator@J@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@J@std@@@2@XZ 0x14139e4f0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@2@XZ 0x14139e520 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@2@XZ 0x14139e550 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x14139e630 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x14139e6b0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@2@XZ 0x14139e6d0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@2@XZ 0x14139e6e0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@2@XZ 0x14139e700 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@2@XZ 0x14139e710 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@2@XZ 0x14139e720 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Occurrence@CGuideManager@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@XZ 0x14139e730 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@XZ 0x14139e7b0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@W4Occurrence@CGuideManager@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@2@$00@2@XZ 0x14139e7e0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@W4Occurrence@CGuideManager@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@2@$00@2@XZ 0x14139e7f0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x14139e960 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@HU?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@4@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@2@XZ 0x14139e9c0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@2@XZ 0x14139eab0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEBAAEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x14139ebc0 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@IEBAAEBW4Occurrence@CGuideManager@@AEBW434@@Z 0x14139eea0 ; prop
// MS2-PIN: ?_Umove@?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@AEAAPEAV?$MS2Ptr@VCGuideEntity@@@@PEAV3@00@Z 0x1413a0190 ; calls 0x141395240
// MS2-PIN: ?Reference@?$MS2Ptr@VCGuideEntity@@@@CAXPEAVCGuideEntity@@@Z 0x14139b660 ; calls AddRefPtred
// MS2-PIN: ?_Umove_if_noexcept@?$vector@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@AEAAXPEAU?$pair@W4Occurrence@CGuideManager@@H@2@00@Z 0x1413a0250 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCGuideEntity@@@@AEAAXPEAX@Z 0x14139f820 ; merge-bind
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VGuideTriggerEventGroup@@@@AEAAXPEAX@Z 0x14139f870 ; merge-bind
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\guideentity.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <list>
#include <map>
#include <set>
#include <vector>
#include <exception>

#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/placeholder/cguidecondition.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/client/ms2/guideentity.h"
#include "ms2/client/ms2/uicutscenemovie.h"

typedef std::set<CGuideManager::Occurrence> GeSetOcc;
typedef std::set<long> GeSetInt;
typedef std::map<int, int> GeMapIntInt;
typedef std::map<CStringA, int> GeMapName;
typedef std::map<CGuideManager::Occurrence, int> GeMapOccInt;
typedef std::map<CGuideManager::Occurrence, GuideOccurContainer> GeMapOcc;
typedef std::map<int, std::vector<MS2Ptr<CGuideEntity> > > GeMapSub;

// The members of the guide manager's containers the exe emits in this part (each container instantiates its own copy).
#define GE_TREE_ERASE(C)                                                                                                \
    template C::_Mybase::iterator C::_Mybase::erase(C::_Mybase::const_iterator);                                        \
    template void C::_Mybase::_Erase(C::_Mybase::_Nodeptr);

GE_TREE_ERASE(GeSetOcc) GE_TREE_ERASE(GeMapOccInt) GE_TREE_ERASE(GeMapSub) GE_TREE_ERASE(GeMapName) GE_TREE_ERASE(GeMapOcc)

#define GE_TREE_CLASSES(V)                                                                                              \
    template class std::_Tree_val<std::_Tree_simple_types<V> >;                                                         \
    template class std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<V> > >;                              \
    template class std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<V> > >;                                    \
    template class std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<V> > >;                    \
    template class std::_Tree_unchecked_iterator<std::_Tree_val<std::_Tree_simple_types<V> > >;
typedef std::pair<const CGuideManager::Occurrence, GuideOccurContainer> GePairOcc;
typedef std::pair<const CGuideManager::Occurrence, int> GePairOccInt;
typedef std::pair<const int, std::vector<MS2Ptr<CGuideEntity> > > GePairSub;
typedef std::pair<const CStringA, int> GePairName;
typedef std::pair<const int, int> GePairIntInt;
GE_TREE_CLASSES(CGuideManager::Occurrence) GE_TREE_CLASSES(long) GE_TREE_CLASSES(GePairOcc) GE_TREE_CLASSES(GePairOccInt)
GE_TREE_CLASSES(GePairSub) GE_TREE_CLASSES(GePairName) GE_TREE_CLASSES(GePairIntInt)

template class ATL::CRBMap<unsigned, MS2Ptr<CGuideEntity> >;
template class ATL::CRBMap<unsigned, unsigned>;

typedef std::list<MS2Ptr<CGuideEntity> > GeListEnt;
typedef std::vector<std::pair<CGuideManager::Occurrence, int> > GeVecSub;
typedef std::vector<MS2Ptr<CGuideEntity> > GeVecEnt;
template class std::list<MS2Ptr<CGuideEntity> >;
template class std::vector<MS2Ptr<CGuideEntity> >;
template class std::vector<std::pair<CGuideManager::Occurrence, int> >;
#define GE_ALLOC(T) template class std::allocator<T>;
#define GE_ALLOC_TREE(C) GE_ALLOC(C::_Mybase::_Node)
GE_ALLOC_TREE(GeSetOcc) GE_ALLOC_TREE(GeSetInt) GE_ALLOC_TREE(GeMapIntInt) GE_ALLOC_TREE(GeMapName) GE_ALLOC_TREE(GeMapOcc) GE_ALLOC_TREE(GeMapSub) GE_ALLOC_TREE(GeMapOccInt)
template class ATL::CAtlMap<CGuideManager::TriggerType, MS2Ptr<GuideTriggerEventGroup> >;

#define GE_TCA_SET(K) template class std::_Tree_comp_alloc<std::_Tset_traits<K, std::less<K>, std::allocator<K>, false> >;
#define GE_TCA_MAP(K, V)                                                                                                \
    template class std::_Tree_comp_alloc<std::_Tmap_traits<K, V, std::less<K>, std::allocator<std::pair<const K, V> >, false> >;
GE_TCA_SET(CGuideManager::Occurrence) GE_TCA_SET(long)
GE_TCA_MAP(int, int) GE_TCA_MAP(CStringA, int) GE_TCA_MAP(CGuideManager::Occurrence, int)
GE_TCA_MAP(CGuideManager::Occurrence, GuideOccurContainer) GE_TCA_MAP(int, GeVecEnt)
template class std::_List_alloc<std::_List_base_types<MS2Ptr<CGuideEntity>, std::allocator<MS2Ptr<CGuideEntity> > > >;

typedef CGuideManager::Occurrence GeOcc;
template std::vector<MS2Ptr<CGuideEntity> >& GeMapSub::operator[](const int&);
template GuideOccurContainer& GeMapOcc::operator[](const GeOcc&);
template class ATL::CRBTree<unsigned, MS2Ptr<CGuideEntity> >;
template class ATL::CRBTree<unsigned, unsigned>;

#define GE_TREE_MORE(C)                                                                                                 \
    template void C::_Mybase::clear() noexcept;                                                                         \
    template C::_Mybase::iterator C::_Mybase::erase(C::_Mybase::const_iterator, C::_Mybase::const_iterator);            \
    template C::_Mybase::iterator C::_Mybase::find(const C::key_type&);                                                 \
    template C::_Mybase::iterator C::_Mybase::lower_bound(const C::key_type&);
GE_TREE_MORE(GeSetOcc) GE_TREE_MORE(GeMapSub) GE_TREE_MORE(GeMapName) GE_TREE_MORE(GeMapOcc)
GE_TREE_MORE(GeMapOccInt)
template void GeListEnt::swap(GeListEnt&) noexcept;

// @0x1413989f0
const int* FUN_1413989f0(const Unk_GcOptInt* pOpt)
{
    if (!pOpt->m_bSet)
        _wassert(L"m_isValueSet", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\nullable.h", 0x5c);
    return &pOpt->m_nValue;
}

#define GE_TREE_DTOR_SET(K) template std::_Tree<std::_Tset_traits<K, std::less<K>, std::allocator<K>, false> >::~_Tree();
#define GE_TREE_DTOR_MAP(K, V)                                                                                          \
    template std::_Tree<std::_Tmap_traits<K, V, std::less<K>, std::allocator<std::pair<const K, V> >, false> >::~_Tree();
GE_TREE_DTOR_SET(CGuideManager::Occurrence) GE_TREE_DTOR_SET(long)
GE_TREE_DTOR_MAP(CGuideManager::Occurrence, GuideOccurContainer) GE_TREE_DTOR_MAP(CGuideManager::Occurrence, int)
GE_TREE_DTOR_MAP(CStringA, int) GE_TREE_DTOR_MAP(int, GeVecEnt)
template void GeMapSub::_Mybase::_Assign_rv(GeMapSub::_Mybase&&, std::true_type);

// @0x141398fd0
MS2Ptr<CGuideEntity>** FUN_141398fd0(MS2Ptr<CGuideEntity>** ppIt)
{
    ++*ppIt;
    return ppIt;
}

// @0x141398ff0
std::pair<CStringA, int>** FUN_141398ff0(std::pair<CStringA, int>** ppIt)
{
    ++*ppIt;
    return ppIt;
}

// @0x14139c770
void FUN_14139c770(void*, bool)
{
}

template void GeMapSub::_Mybase::_Destroy_if_node(GeMapSub::_Mybase::_Nodeptr);
template void GeMapName::_Mybase::_Destroy_if_node(GeMapName::_Mybase::_Nodeptr);
template void GeMapOcc::_Mybase::_Destroy_if_node(GeMapOcc::_Mybase::_Nodeptr);
