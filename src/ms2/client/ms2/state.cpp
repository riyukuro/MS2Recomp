// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The actor state base (State / StateData), the state-sync
// controllers (StateLocalController and its PcGuide / Ridee sends), the StateData payloads and the climb / crawl /
// dash states. See ms2/placeholder/state.h and statedata.h.
// MS2-UNIT: ?\state.cpp
// MS2-RANGE: 0x1417b73c0-0x1417c24a0 .text$mn
// MS2-RANGE: 0x140101890-0x140101fe0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH$0A@@?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@$$QEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH@Z 0x1417b9600 ; unique
// MS2-PIN: ??$?0V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H$0A@@?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x1417b9650 ; unique
// MS2-PIN: ??$forward@AEAH@std@@YAAEAHAEAH@Z 0x1417ba1f0 ; prop
// MS2-PIN: ??$make_pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH@std@@YA?AU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@0@$$QEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH@Z 0x1417ba260 ; unique
// MS2-PIN: ??1?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@XZ 0x1417ba590 ; unique
// MS2-PIN: ??1?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@XZ 0x1417ba5b0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@XZ 0x1417ba6a0 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@XZ 0x1417ba6c0 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1417ba6e0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1417ba730 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1417ba750 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1417ba820 ; unique
// MS2-PIN: ??_GState@@UEAAPEAXI@Z 0x1417ba930 ; prop
// MS2-PIN: ?AddTail@?$CAtlList@V?$MS2Ptr@VUnk_GuideRecord@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_GuideRecord@@@@@ATL@@@ATL@@QEAAPEAU__POSITION@@AEBV?$MS2Ptr@VUnk_GuideRecord@@@@@Z 0x1417ba970 ; unique
// MS2-PIN: ?GetAt@?$CAtlList@V?$MS2Ptr@VUnk_GuideRecord@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_GuideRecord@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VUnk_GuideRecord@@@@PEAU__POSITION@@@Z 0x1417ba9f0 ; unique
// MS2-PIN: ?GetCount@?$CAtlList@V?$MS2Ptr@VUnk_GuideRecord@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_GuideRecord@@@@@ATL@@@ATL@@QEBA_KXZ 0x1417baa60 ; unique
// MS2-PIN: ?GetFreeNode@?$CAtlList@V?$MS2Ptr@VUnk_GuideRecord@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_GuideRecord@@@@@ATL@@@ATL@@AEAAXXZ 0x1417baa70 ; unique
// MS2-PIN: ?GetNext@?$CAtlList@V?$MS2Ptr@VUnk_GuideRecord@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_GuideRecord@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VUnk_GuideRecord@@@@AEAPEAU__POSITION@@@Z 0x1417bab60 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlList@V?$MS2Ptr@VUnk_GuideRecord@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_GuideRecord@@@@@ATL@@@ATL@@QEBA_NXZ 0x1417babe0 ; unique
// MS2-PIN: ?NewNode@?$CAtlList@V?$MS2Ptr@VUnk_GuideRecord@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_GuideRecord@@@@@ATL@@@ATL@@AEAAPEAVCNode@12@AEBV?$MS2Ptr@VUnk_GuideRecord@@@@PEAV312@1@Z 0x1417bac10 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@XZ 0x1417bacd0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@@Z 0x1417baf30 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@@Z 0x1417bafd0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x1417bb640 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@2@XZ 0x1417bb660 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@2@XZ 0x1417bb670 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@2@XZ 0x1417bb680 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@2@XZ 0x1417bb690 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@XZ 0x1417bb6a0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@XZ 0x1417bb6b0 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@2@XZ 0x1417bb6f0 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@PEAU32@@Z 0x1417bb8a0 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@PEAU32@@Z 0x1417bb8d0 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAAXXZ 0x1417bbb20 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@_K@Z 0x1417bbbf0 ; unique
// MS2-PIN: ?empty@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEBA_NXZ 0x1417bbc20 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@XZ 0x1417bbc60 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@0@Z 0x1417bbcc0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@@Z 0x1417bbdb0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1417bbe60 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1417bbf40 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@2@@Z 0x1417bbfa0 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@SAPEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@2@AEAU32@@Z 0x1417bbfd0 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEBA_KXZ 0x1417bbff0 ; unique
// MS2-PIN: ??_GStateClimb@@UEAAPEAXI@Z 0x1417bee60 ; unique
// MS2-PIN: ??_GStateCrawl@@UEAAPEAXI@Z 0x1417bf880 ; unique
// MS2-PIN: ??0NiTextKeyMatch@@QEAA@AEBVNiFixedString@@@Z 0x1417c0710 ; unique
// MS2-PIN: ??1NiTextKeyMatch@@UEAA@XZ 0x1417c0790 ; unique
// MS2-PIN: ??_GNiTextKeyMatch@@UEAAPEAXI@Z 0x1417c07e0 ; unique
// MS2-PIN: ??_GStateDash@@UEAAPEAXI@Z 0x1417c0840 ; unique
// MS2-PIN: ?GetEndTextKey@NiAnimationConstants@@SAAEBVNiFixedString@@XZ 0x1417c0880 ; unique
// MS2-PIN: ?GetNextEndOfSequenceTime@NiActorManager@@IEAAMI@Z 0x1417c0890 ; unique
// MS2-PIN: ?GetNextEventTime@NiActorManager@@QEAAMW4EventType@1@IAEBVNiFixedString@@@Z 0x1417c08f0 ; unique
// MS2-PIN: ?GetNextEventTime@NiActorManager@@QEAAMW4EventType@1@IPEAVNiTextKeyMatch@@@Z 0x1417c0990 ; unique
// MS2-PIN: ?GetRTTI@NiTextKeyMatch@@UEBAPEBVNiRTTI@@XZ 0x1417c0a20 ; unique
// MS2-PIN: ?IsKeyMatch@NiTextKeyMatch@@UEAA_NAEBVNiFixedString@@@Z 0x1417c0a40 ; unique
// MS2-PIN: ?SetLastMatchedKey@NiTextKeyMatch@@IEAAXAEBVNiFixedString@@@Z 0x1417c0a90 ; unique
// MS2-PIN: ??_GStateFallData@@UEAAPEAXI@Z 0x1417c1e80 ; order
// MS2-PIN: ??_GStateGlideData@@UEAAPEAXI@Z 0x1417c1ec0 ; order
// MS2-PIN: ??_GStateHitData@@UEAAPEAXI@Z 0x1417c1f00 ; prop
// MS2-PIN: ??_GStateHomemadeData@@UEAAPEAXI@Z 0x1417c1f40 ; order
// MS2-PIN: ??_GStateInteractNpcData@@UEAAPEAXI@Z 0x1417c1f80 ; order
// MS2-PIN: ??_GStateJumpData@@UEAAPEAXI@Z 0x1417c1fc0 ; prop
// MS2-PIN: ??_GStateJumpToData@@UEAAPEAXI@Z 0x1417c2000 ; prop
// MS2-PIN: ??_GStateLandData@@UEAAPEAXI@Z 0x1417c2040 ; prop
// MS2-PIN: ??_GStateMicroGameCoupleDanceData@@UEAAPEAXI@Z 0x1417c2080 ; order
// MS2-PIN: ??_GStateRecallData@@UEAAPEAXI@Z 0x1417c2100 ; order
// MS2-PIN: ??_GStateSkillData@@UEAAPEAXI@Z 0x1417c2140 ; order
// MS2-PIN: ??_GStateSpawnData@@UEAAPEAXI@Z 0x1417c2180 ; prop
// MS2-PIN: ??_GStateStunData@@UEAAPEAXI@Z 0x1417c21c0 ; order
// MS2-PIN: ??_GStateSummonData@@UEAAPEAXI@Z 0x1417c2200 ; order
// MS2-PIN: ??_GStateTurnData@@UEAAPEAXI@Z 0x1417c2240 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??0?$MS2Ptr@VStateData@@@@QEAA@XZ 0x1417ba320
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\state.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <map>
#include <efd/SmartPointer.h>
#include <efd/utf8string.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <egf/FlatModel.h>
#include <NiActorManager.h>

#include "statedata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/cubecraft_1.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/stateeffectmgr.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit statics (.text$di): the shared sort-name / skill / stun / condition header statics, included five times ----

static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
static Unk_Handle1401cd100 s_dat_143aea848(0);                                       // @0x140101b20
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames4[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill4 = "skill";
static CString s_strStun4 = "stun";
static Unk_1402a9d70 s_condition4(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames5[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill5 = "skill";
static CString s_strStun5 = "stun";
static Unk_1402a9d70 s_condition5(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local placeholders ----

// The state-sync record (StateSyncObject; Unk_StateArg22 in statemanager.h) as StateData slots 1/2 see it.
class Unk_StateDataArg
{
public:
    char m_pad_00[0x64];
    int m_n64;                                          // +0x64 skill id
    int m_n68;                                          // +0x68
    short m_n6c;                                        // +0x6c skill level
    CStringA m_str70;                                   // +0x70
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);
class Unk_StateDataArgRps : public Unk_StateDataArg
{
public:
    int m_nB8;
    int m_nBC;
    int m_nC0;
    CStringW m_strC8;                                   // +0xc8
};
MS2_CHECK_OFFSET(Unk_StateDataArgRps, m_strC8, 0xc8);
class Unk_StateDataArgDance : public Unk_StateDataArg
{
public:
    int m_nB8;
    bool m_bBC;
    CStringA m_strC0;                                   // +0xc0
};
MS2_CHECK_OFFSET(Unk_StateDataArgDance, m_strC0, 0xc0);

// The micro-game sync records (RTTI .?AVStateSyncObjectMicroGameRps@@ / ...CoupleDance@@).
class StateSyncObjectMicroGameRps : public Unk_StateArg22
{
public:
    int m_nB8;
    int m_nBC;
    int m_nC0;
    CStringW m_strC8;                                   // +0xc8
};
MS2_CHECK_OFFSET(StateSyncObjectMicroGameRps, m_strC8, 0xc8);
class StateSyncObjectMicroGameCoupleDance : public Unk_StateArg22
{
public:
    int m_nB8;
    bool m_bBC;
    CStringA m_strC0;                                   // +0xc0
};
MS2_CHECK_OFFSET(StateSyncObjectMicroGameCoupleDance, m_strC0, 0xc0);

// A record the controllers send (the sync record plus its packet writer).
class Unk_GuideRecord : public Unk_StateArg22
{
public:
    void FUN_1408356c0(COutPacket& packet);
};

// Packet send / the session globals.
void FUN_140710590(COutPacket& packet);
extern unsigned char DAT_143ab2856;
int FUN_141472bc0();
class Unk_StClock
{
public:
    int FUN_141473610();
    float FUN_141473230();
    float FUN_141473280();
};
Unk_StClock* FUN_14086d260();
class Unk_StPlayback { public: bool FUN_1406af100(); };     // replay / spectator mode
Unk_StPlayback* FUN_1406aeee0();
class Unk_StTraffic { public: unsigned FUN_14087d2f0(PCBase* pOwner); };
Unk_StTraffic* FUN_140cea080();

// The field service (FUN_1403ed2d0).
class Unk_RideeFieldObj
{
public:
    efd::Point3 FUN_140ae0150();                        // ground normal
};
template <> MS2Ptr<Unk_RideeFieldObj>::~MS2Ptr();
template <> Unk_RideeFieldObj* MS2Ptr<Unk_RideeFieldObj>::get() const;
template <> Unk_RideeFieldObj* MS2Ptr<Unk_RideeFieldObj>::operator->() const;
class Unk_StWorld
{
public:
    MS2Ptr<Unk_RideeFieldObj> FUN_141bc4f10(egf::Entity* pEntity);
    void* FUN_141bd0cc0();                              // the local player
    int FUN_141bd1a10(PCBase* pActor);
};
Unk_StWorld* FUN_1403ed2d0();

// The effect request (0x70) and the client effect manager (FUN_1403ed280).
struct Unk_ExpTarget
{
    Unk_ExpTarget();                                    // 0x140a52ef0
    ~Unk_ExpTarget();                                   // 0x1405a89e0
    void FUN_140a53190(int nObjectId);
    CString m_strName;                                  // +0x00
    int m_nOwnerId;                                     // +0x08
    int m_pad_0c;
    __int64 m_pad_10[12];
};
MS2_CHECK_SIZE(Unk_ExpTarget, 0x70);
class Unk_StEffects
{
public:
    void FUN_1411a4a00(Unk_ExpTarget* pRequest);        // play once
    void FUN_1411a6060(int nHandle);                    // release
};
Unk_StEffects* FUN_1403ed280();
StateEffectMgr* FUN_1414a5870();

// Config tables.
class Unk_StCfgValue { public: float FUN_1402bac70(); };
class Unk_StConsts
{
public:
    char m_pad_0[0x1a80];
    Unk_StCfgValue m_climbOverShake;                    // +0x1a80
    char m_pad_1[0x28c0 - 0x1a81];
    Unk_StCfgValue m_climbSpeedV;                       // +0x28c0
    char m_pad_2[0x2918 - 0x28c1];
    Unk_StCfgValue m_climbSpeedH;                       // +0x2918
};
MS2_CHECK_OFFSET(Unk_StConsts, m_climbSpeedH, 0x2918);
Unk_StConsts* FUN_1401d3200();
class Unk_StEffectCfg
{
public:
    char m_pad_0[0x270];
    CString m_strDashEffect;                            // +0x270
};
Unk_StEffectCfg* FUN_1401d31f0();

// Physics: the ray cast record, the PhysX helper and the entity physics service.
struct Unk_RayCastInfo
{
    Unk_RayCastInfo();                                  // 0x140ad4440
    efd::Point3 m_origin;                               // +0x00
    efd::Point3 m_dir;                                  // +0x0c
    float m_maxDist;                                    // +0x18
    int m_groups;                                       // +0x1c
    void* m_20;
    void* m_28;
    egf::Entity* m_hitEntity;                           // +0x30
    void* m_hitActor;
    void* m_hitShape;
    float m_hitDist;                                    // +0x48
    efd::Point3 m_hitPoint;                             // +0x4c
    efd::Point3 m_hitNormal;                            // +0x58
};
MS2_CHECK_SIZE(Unk_RayCastInfo, 0x68);
class NxGroupsMask;
class CPhysXHelper
{
public:
    bool FUN_1416892f0(Unk_RayCastInfo* pInfo, const NxGroupsMask* pMask);
    int FUN_14168a450(efd::Point3 kPos, float* pfDist, float fMaxDist);     // ground below kPos
};
CPhysXHelper* FUN_1409f7ca0();
class Unk_StPhysObj
{
public:
    char m_pad_00[0x20];
    efd::SmartPointer<egf::Entity> m_spEntity;          // +0x20
};
class Unk_StPhysSvc
{
public:
    Unk_StPhysObj* FUN_1410b8e60(egf::Entity* pEntity);
    Unk_StPhysObj* FUN_1410b9080(Unk_StPhysObj* pObj, int nFlags);
};
class Unk_GmGridRef
{
public:
    Unk_GmGridRef(void* p);                             // 0x1401cd0b0
    ~Unk_GmGridRef();                                   // 0x1401cd150
    void* FUN_140885310();
    Unk_StPhysSvc* FUN_1401cd1a0();
    void* m_p;
};
extern char DAT_143b059e8;
void* FUN_1401cd040(void* pKey);
int FUN_1409618c0(egf::Entity* pEntity, unsigned nProperty, efd::Point3* pOut);
float FUN_140966ea0(efd::Point3 a, efd::Point3 b);     // distance
void FUN_140a01250(efd::Point3 kDir, efd::Point3* pRight, efd::Point3* pSide);

// The actor's physics body and its hit report.
class GameObjectControllerHitReport
{
public:
    void FUN_140cfaf30();
    egf::EntityID GetEntityID() const;
};
class Unk_StBody
{
public:
    void FUN_141240700(efd::Point3 kVel);
    void FUN_141240730();
    GameObjectControllerHitReport* FUN_141240f20();
};
Unk_StBody* FUN_14166d220(PCBase* pOwner);
float FUN_14059d930(float f);                                         // fabs
float FUN_141240c40(bool b);                                          // the move speed (xmm0)

// The actor's buffs.
class Unk_StBuff
{
public:
    efd::Point3 FUN_141683290();                        // knock-back velocity
    efd::Point3 FUN_141683900();
    bool FUN_141683100(int nBuff);
    bool FUN_141682fe0(int nBuff);
};
Unk_StBuff* FUN_14166d240(PCBase* pOwner);

// The animation service.
class Unk_StAnimSvc { public: unsigned FUN_140b7f6a0(const egf::EntityID& kId); };
Unk_StAnimSvc* FUN_141b6f910();

// PCBase non-virtuals that return structs (member form) and the free-function helpers.
class Unk_StPC : public PCBase
{
public:
    CString FUN_14166dc50();                            // current animation name
    efd::Point3 FUN_141674b60(efd::Point3 kInput);      // input -> world direction
};
struct Unk_StSpeedCfg { float m_f0; float m_f4; float m_f8; };
Unk_StSpeedCfg* FUN_141671920(PCBase* pOwner);
void FUN_141670d80(PCBase* pOwner, float f);
float FUN_1416713c0(PCBase* pOwner);
int FUN_141671a30(PCBase* pOwner);
int FUN_141675ed0(PCBase* pOwner);
bool FUN_14166de90(PCBase* pOwner, int nKind, unsigned nSeq);
void FUN_14166dda0(PCBase* pOwner, int nKind);
void FUN_14166f8f0(PCBase* pOwner, int n, int b);
void FUN_14166d430(PCBase* pOwner, efd::Point3 kNormal, int a, int b);
PCBase* FUN_140974230(PCBase* pOwner);                  // as PC
PCBase* FUN_1409ffc60(PCBase* pOwner);                  // as npc
PCBase* FUN_14096e110(PCBase* pOwner);                  // mount
MyPC* FUN_14096e160(PCBase* pOwner);                    // as MyPC
PCBase* FUN_140b10360(PCBase* pNpc);
PCBase* FUN_141094f60(PCBase* pNpc);
PCBase* FUN_1409613d0(PCBase* p);
class Unk_UtilHolder;
Unk_UtilHolder* FUN_141468360(PCBase* pOwner);          // as Ridee holder
PCBase* FUN_141706540(Unk_UtilHolder* pHolder);         // the Ridee's rider
class Unk_UtilHolderRef
{
public:
    Unk_UtilHolderRef(Unk_UtilHolder* p);               // 0x140963df0
    ~Unk_UtilHolderRef();                               // 0x1409648b0
    Unk_UtilHolder* FUN_140965790() const;              // get
    Unk_UtilHolder* FUN_140975bc0() const;              // operator->
private:
    Unk_UtilHolder* m_p;
};
void* FUN_14165f100(MyPC* pPC);
void FUN_14165f170(MyPC* pPC);
int FUN_14165b500(PCBase* pPC, int n);
int FUN_141658e60(PCBase* pPC);
egf::Entity* FUN_141659af0(PCBase* pPC, int n);
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);
int FUN_14028d260(float f);                             // round to ms
egf::Entity* FUN_1408a9090(const void* pspEntity);      // SmartPointer<Entity> get
float FUN_14028d3a0(float fDeg);
float FUN_14096b1c0(float f);
class Unk_StCamera { public: void FUN_140aeb880(float a, float b, float c); };
Unk_StCamera* FUN_1409478c0();
class Unk_StInput { public: int FUN_140ad21f0(); };
Unk_StInput* FUN_140953f30();
class Unk_StSound { public: void FUN_141377420(PCBase* pOwner, CString strKey); };
Unk_StSound* FUN_141475cf0();
int FUN_140718170(const CStringA& str);

template <> MS2Ptr<CSkillRecord>::MS2Ptr(const MS2Ptr& o);                               // 0x1409f71b0
template <> MS2Ptr<CSkillRecord>::~MS2Ptr();                                            // 0x140975740
template <> MS2Ptr<Unk_PCBaseComp_b18>::MS2Ptr(const MS2Ptr& o);                         // 0x141532430
template <> MS2Ptr<Unk_PCBaseComp_b18>::~MS2Ptr();                                      // 0x140964b60
template <> bool MS2Ptr<Unk_PCBaseComp_b18>::operator==(Unk_PCBaseComp_b18* p) const;    // 0x1417089e0 (defined in ridee.cpp; an implicit copy here is a duplicate symbol under lld-link)
template <> MS2Ptr<Unk_StateArg29>::~MS2Ptr();                                          // 0x1401bfde0 (ICF-folded)

// ---- StateLocalController / StatePcGuideObjectController / StateRideeController ----

// @0x1417b73c0
// MS2-FUNCTIONAL: the base owns the records / current / owner in the exe; they are declared on the PcGuide subclass
StateLocalController::StateLocalController()
{
    StatePcGuideObjectController* pView = static_cast<StatePcGuideObjectController*>(this);
    new (&pView->m_records) ATL::CAtlList<MS2Ptr<Unk_GuideRecord> >(10);
    new (&pView->m_spCurrent) MS2Ptr<Unk_GuideRecord>();
    pView->m_pOwner = 0;
}

// @0x1417b7430
void StatePcGuideObjectController::FUN_1417b7430(PCBase* pOwner)
{
    m_pOwner = pOwner;
}
MS2_REPLACE_METHOD(0x1417b7430, StatePcGuideObjectController, FUN_1417b7430, 25, 0x4C00882B);

// @0x1417b7450
void StatePcGuideObjectController::FUN_1417b7450()
{
    m_spCurrent = 0;
    m_records.RemoveAll();
}
MS2_REPLACE_METHOD(0x1417b7450, StatePcGuideObjectController, FUN_1417b7450, 50, 0x96E31A32);

// @0x1417b7490
int StatePcGuideObjectController::FUN_1417b7490()
{
    if ((m_spCurrent.get() ? true : false) && m_spCurrent->m_nA8 != 0)
        return 0;
    unsigned nTotal = FUN_1417b7540();
    if (nTotal == 0)
        return 0;
    unsigned nLimit = FUN_140cea080()->FUN_14087d2f0(m_pOwner);
    if (nTotal < nLimit)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1417b7490, StatePcGuideObjectController, FUN_1417b7490, 157, 0x119CB649);

// @0x1417b7540
int StatePcGuideObjectController::FUN_1417b7540()
{
    int nTotal = m_spCurrent.get() ? FUN_14028d260(m_spCurrent->m_fTime) : 0;
    for (POSITION pos = m_records.GetHeadPosition(); pos; m_records.GetNext(pos)) {
        Unk_GuideRecord* pRec = m_records.GetAt(pos).get();
        nTotal += FUN_14028d260(pRec->m_fTime);
    }
    return nTotal;
}
MS2_REPLACE_METHOD(0x1417b7540, StatePcGuideObjectController, FUN_1417b7540, 207, 0x4BE4E6B4);

// @0x1417b7620
MS2Ptr<Unk_GuideRecord> StatePcGuideObjectController::FUN_1417b7620()
{
    return m_spCurrent;
}
MS2_REPLACE_METHOD(0x1417b7620, StatePcGuideObjectController, FUN_1417b7620, 65, 0x19C58750);

// @0x1417b7670
void StatePcGuideObjectController::FUN_1417b7670(Unk_GuideRecord* pRec)
{
    FUN_1417b7720();
    m_spCurrent.AssignRaw(pRec);
}
MS2_REPLACE_METHOD(0x1417b7670, StatePcGuideObjectController, FUN_1417b7670, 51, 0xE57F6758);

// @0x1417b76b0
void StatePcGuideObjectController::FUN_1417b76b0(float fTime)
{
    if (m_spCurrent.IsNull())
        return;
    m_spCurrent->m_fTime += fTime;
}
MS2_REPLACE_METHOD(0x1417b76b0, StatePcGuideObjectController, FUN_1417b76b0, 96, 0xF1BA3FD4);

// @0x1417b7720
void StatePcGuideObjectController::FUN_1417b7720()
{
    if (FUN_1406aeee0()->FUN_1406af100()) {
        if (m_spCurrent == 0)
            return;
        if (m_spCurrent->m_nA8 == 0) {
            m_records.AddTail(m_spCurrent);
            m_spCurrent->m_nA8 = 1;
        }
    } else {
        if ((m_spCurrent.get() ? true : false) && m_spCurrent->m_nA8 != 0)
            m_spCurrent = 0;
        if (m_spCurrent.IsNull())
            return;
        m_records.AddTail(m_spCurrent);
        m_spCurrent = 0;
    }
}
MS2_REPLACE_METHOD(0x1417b7720, StatePcGuideObjectController, FUN_1417b7720, 308, 0x8185DDFC);

// @0x1417b7860
void StateLocalController::vfunc_0()
{
    // the records live on the PcGuide layout (StateLocalController declares no members)
    typedef StatePcGuideObjectController View;
    static_cast<View*>(this)->FUN_1417b7720();
    if (static_cast<View*>(this)->m_records.IsEmpty())
        return;
    COutPacket packet(0x12, 0);
    packet.vfunc_o10_1(DAT_143ab2856);
    packet.vfunc_o10_3(FUN_141472bc0());
    packet.vfunc_o10_3(FUN_14086d260()->FUN_141473610());
    packet.vfunc_o10_1((unsigned char)static_cast<View*>(this)->m_records.GetCount());
    for (POSITION pos = static_cast<View*>(this)->m_records.GetHeadPosition(); pos;
        static_cast<View*>(this)->m_records.GetNext(pos)) {
        Unk_GuideRecord* pRec = static_cast<View*>(this)->m_records.GetAt(pos).get();
        pRec->FUN_1408356c0(packet);
        if (pRec->m_nState == 6 || pRec->m_nState == 0x14) {
            pRec->m_nA8 = 1;
            static_cast<View*>(this)->m_spCurrent.AssignRaw(pRec);
        }
    }
    FUN_140710590(packet);
    static_cast<View*>(this)->m_records.RemoveAll();
}
MS2_REPLACE_METHOD(0x1417b7860, StateLocalController, vfunc_0, 400, 0x707A8861);

// @0x1417b7a00
void StatePcGuideObjectController::vfunc_0()
{
    if (m_nKind == 3)
        return;
    FUN_1417b7720();
    if (m_records.IsEmpty())
        return;
    COutPacket packet(0x35, 0);
    packet.vfunc_o10_2((short)m_nKind);
    packet.vfunc_o10_1((unsigned char)m_records.GetCount());
    for (POSITION pos = m_records.GetHeadPosition(); pos; m_records.GetNext(pos)) {
        Unk_GuideRecord* pRec = m_records.GetAt(pos).get();
        pRec->FUN_1408356c0(packet);
    }
    FUN_140710590(packet);
    m_records.RemoveAll();
}
MS2_REPLACE_METHOD(0x1417b7a00, StatePcGuideObjectController, vfunc_0, 317, 0x9B009223);

// @0x1417b7b50
void StatePcGuideObjectController::FUN_1417b7b50(int nKind)
{
    m_nKind = nKind;
}
MS2_REPLACE_METHOD(0x1417b7b50, StatePcGuideObjectController, FUN_1417b7b50, 22, 0x55CC0123);

// @0x1417b7b70
void StateRideeController::vfunc_0()
{
    typedef StatePcGuideObjectController View;
    static_cast<View*>(static_cast<StateLocalController*>(this))->FUN_1417b7720();
    if (static_cast<View*>(static_cast<StateLocalController*>(this))->m_records.IsEmpty())
        return;
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    COutPacket packet(0x41, 0);
    packet.vfunc_o10_1(DAT_143ab2856);
    packet.vfunc_o10_3(FUN_141472bc0());
    packet.vfunc_o10_3(FUN_14086d260()->FUN_141473610());
    packet.vfunc_o10_1((unsigned char)static_cast<View*>(static_cast<StateLocalController*>(this))->m_records.GetCount());
    for (POSITION pos = static_cast<View*>(static_cast<StateLocalController*>(this))->m_records.GetHeadPosition(); pos;
        static_cast<View*>(static_cast<StateLocalController*>(this))->m_records.GetNext(pos)) {
        Unk_GuideRecord* pRec = static_cast<View*>(static_cast<StateLocalController*>(this))->m_records.GetAt(pos).get();
        pRec->FUN_1408356c0(packet);
        if (pRec->m_nState == 6 || pRec->m_nState == 0x14) {
            pRec->m_nA8 = 1;
            static_cast<View*>(static_cast<StateLocalController*>(this))->m_spCurrent.AssignRaw(pRec);
        }
    }
    FUN_140710590(packet);
    static_cast<View*>(static_cast<StateLocalController*>(this))->m_records.RemoveAll();
}
MS2_REPLACE_METHOD(0x1417b7b70, StateRideeController, vfunc_0, 437, 0x7301229D);

// ---- State ----

// @0x1417b7d30
State::State(PCBase* pOwner)
    : m_pOwner(pOwner), m_n10(0), m_n14(1), m_n28(0)
{
}

// @0x1417b7dc0
State::~State()
{
    FUN_1417b9310();
}

// @0x1417b7e20
void State::vfunc_2(int n)
{
    m_n10 = n;
}
MS2_REPLACE_METHOD(0x1417b7e20, State, vfunc_2, 22, 0x566B64E3);

// @0x1417b7e40
int State::FUN_1417b7e40()
{
    return m_n10;
}
MS2_REPLACE_METHOD(0x1417b7e40, State, FUN_1417b7e40, 14, 0xC2D0886F);

// @0x1417b7e60
void State::vfunc_3(double fTime)
{
}
MS2_REPLACE_METHOD(0x1417b7e60, State, vfunc_3, 12, 0x49415BA5);

// @0x1417b7e80
void State::vfunc_4(StateData* pData)
{
    m_spData.AssignRaw(pData);
    if (PCBase* pMount = FUN_1417b8480()) {
        pMount->vfunc_95();
    } else {
        Unk_StSpeedCfg* pCfg = FUN_141671920(m_pOwner);
        vfunc_10(m_pOwner->vfunc_95(), pCfg->m_f8, pCfg->m_f4, 1.0f, 0);
    }
    FUN_1417b9310();
}
MS2_REPLACE_METHOD(0x1417b7e80, State, vfunc_4, 202, 0xCE7AB324);

// @0x1417b7f50
void State::vfunc_5(int n)
{
    m_spData = 0;
    FUN_1417b9310();
}
MS2_REPLACE_METHOD(0x1417b7f50, State, vfunc_5, 47, 0x0AEE5F15);

// @0x1417b7f90
void State::vfunc_6()
{
}
MS2_REPLACE_METHOD(0x1417b7f90, State, vfunc_6, 6, 0xA9AF6E37);

// @0x1417b7fa0
void State::vfunc_7(int n)
{
}
MS2_REPLACE_METHOD(0x1417b7fa0, State, vfunc_7, 10, 0x96F6F902);

// @0x1417b7fb0
void State::vfunc_8(double fTime)
{
    MS2Ptr<Unk_PCBaseComp_b18> spSkill = m_pOwner->vfunc_104(false, false, false);
    if (spSkill.get())
        m_pOwner->vfunc_102(reinterpret_cast<MS2Ptr<CSkillRecord>&>(spSkill));
}
MS2_REPLACE_METHOD(0x1417b7fb0, State, vfunc_8, 173, 0xE555EBD3);

// @0x1417b8070
void State::vfunc_9(double fTime)
{
}
MS2_REPLACE_METHOD(0x1417b8070, State, vfunc_9, 12, 0x49415BA5);

// @0x1417b8090
void State::vfunc_10(float a, float b, float c, float d, int e)
{
    FUN_141670d80(m_pOwner, d);
}
MS2_REPLACE_METHOD(0x1417b8090, State, vfunc_10, 52, 0xE0D1BA4D);

// @0x1417b80d0
void State::AnimActivated(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
}
MS2_REPLACE_METHOD(0x1417b80d0, State, AnimActivated, 21, 0x6CD428AE);

// @0x1417b80f0
void State::TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID, const NiFixedString& kTextKey,
    const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime)
{
}
MS2_REPLACE_METHOD(0x1417b80f0, State, TextKeyEvent, 21, 0x6CD428AE);

// @0x1417b8110
void State::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
}
MS2_REPLACE_METHOD(0x1417b8110, State, EndOfSequence, 21, 0x6CD428AE);

// @0x1417b8130
int State::vfunc_14()
{
    return m_n14;
}
MS2_REPLACE_METHOD(0x1417b8130, State, vfunc_14, 14, 0x5ADC0513);

// @0x1417b8150
int State::vfunc_15()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1417b8150, State, vfunc_15, 8, 0x7F371472);

// @0x1417b8160
int State::vfunc_16()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1417b8160, State, vfunc_16, 8, 0x7F371472);

// @0x1417b8170
int State::vfunc_17()
{
    return 1;
}
MS2_REPLACE_METHOD(0x1417b8170, State, vfunc_17, 11, 0x30025ED0);

// @0x1417b8190
int State::vfunc_18()
{
    return 1;
}
MS2_REPLACE_METHOD(0x1417b8190, State, vfunc_18, 11, 0x30025ED0);

// @0x1417b81b0
int State::vfunc_19()
{
    return 1;
}
MS2_REPLACE_METHOD(0x1417b81b0, State, vfunc_19, 11, 0x30025ED0);

// @0x1417b81d0
int State::vfunc_20()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1417b81d0, State, vfunc_20, 8, 0x7F371472);

// @0x1417b81e0
void State::vfunc_21(int n)
{
}
MS2_REPLACE_METHOD(0x1417b81e0, State, vfunc_21, 10, 0x96F6F902);

// @0x1417b81f0
int State::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    return 0;
}
MS2_REPLACE_METHOD(0x1417b81f0, State, vfunc_22, 41, 0xD63B3876);

// @0x1417b8220
void State::vfunc_23()
{
}
MS2_REPLACE_METHOD(0x1417b8220, State, vfunc_23, 6, 0xA9AF6E37);

// @0x1417b8230
void State::vfunc_24()
{
}
MS2_REPLACE_METHOD(0x1417b8230, State, vfunc_24, 6, 0xA9AF6E37);

// @0x1417b8240
bool State::vfunc_25(int n, void* p)
{
    if (n)
        vfunc_2(n);
    return true;
}
MS2_REPLACE_METHOD(0x1417b8240, State, vfunc_25, 52, 0x65BFD9CA);

// @0x1417b8280
void State::vfunc_26(Unk_StateDataArg* p)
{
    if (StateData* pData = vfunc_35())
        pData->vfunc_1(p);
}
MS2_REPLACE_METHOD(0x1417b8280, State, vfunc_26, 72, 0xAB6DB27F);

// @0x1417b82d0
MS2Ptr<StateData> State::vfunc_27()
{
    return MS2Ptr<StateData>(0);
}
MS2_REPLACE_METHOD(0x1417b82d0, State, vfunc_27, 55, 0xF68217F9);

// @0x1417b8310
bool State::vfunc_28(MS2Ptr<Unk_StateArg22> p)
{
    return false;
}
MS2_REPLACE_METHOD(0x1417b8310, State, vfunc_28, 39, 0xF472F595);

// @0x1417b8340
int State::FUN_1417b8340()
{
    return m_pOwner->vfunc_108();
}
MS2_REPLACE_METHOD(0x1417b8340, State, FUN_1417b8340, 41, 0x080AADA3);

// @0x1417b8370
PCBase* State::FUN_1417b8370()
{
    return FUN_140974230(m_pOwner);
}
MS2_REPLACE_METHOD(0x1417b8370, State, FUN_1417b8370, 28, 0xC8ECB84E);

// @0x1417b83a0
PCBase* State::FUN_1417b83a0()
{
    return FUN_1409ffc60(m_pOwner);
}
MS2_REPLACE_METHOD(0x1417b83a0, State, FUN_1417b83a0, 28, 0x95CC374D);

// @0x1417b83d0
PCBase* State::FUN_1417b83d0()
{
    if (FUN_1417b83a0() && FUN_140b10360(FUN_1417b83a0()))
        return FUN_140b10360(FUN_1417b83a0());
    if (FUN_1417b83a0()) {
        PCBase* pOwner = FUN_141094f60(FUN_1417b83a0());
        if (pOwner && pOwner->GetClassID() == 0x6200004)
            return FUN_1409613d0(pOwner);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1417b83d0, State, FUN_1417b83d0, 155, 0x10ECA9CD);

// @0x1417b8480
PCBase* State::FUN_1417b8480()
{
    return FUN_14096e110(m_pOwner);
}
MS2_REPLACE_METHOD(0x1417b8480, State, FUN_1417b8480, 28, 0xFE73463C);

// @0x1417b84b0
MyPC* State::FUN_1417b84b0()
{
    if (m_pOwner->GetClassID() == 0x6200045) {
        Unk_UtilHolderRef kHolder(FUN_141468360(m_pOwner));
        if (kHolder.FUN_140965790())
            return FUN_14096e160(FUN_141706540(kHolder.FUN_140975bc0()));
    }
    return FUN_14096e160(m_pOwner);
}
MS2_REPLACE_METHOD(0x1417b84b0, State, FUN_1417b84b0, 169, 0xAC80C391);

// @0x1417b8560
int State::FUN_1417b8560()
{
    return FUN_1417b84b0() != 0;
}
MS2_REPLACE_METHOD(0x1417b8560, State, FUN_1417b8560, 51, 0xBBDF672C);

// @0x1417b85a0
CString FUN_1417b85a0(int nState)
{
    switch (nState) {
    case 0: return "gosNone";
    case 1: return "gosIdle";
    case 2: return "gosWalk";
    case 3: return "gosCrawl";
    case 4: return "gosLand";
    case 5: return "gosFall";
    case 6: return "gosJump";
    case 7: return "gosJumpTo";
    case 8: return "gosLadder";
    case 9: return "gosRope";
    case 10: return "gosSit";
    case 0xb: return "gosEmotion";
    case 0xc: return "gosDead";
    case 0xd: return "gosHit";
    case 0xe: return "gosWaittingSelect";
    case 0xf: return "gosEmotionIdle";
    case 0x10: return "gosPcSkill";
    case 0x11: return "gosSpawn";
    case 0x12: return "gosStun";
    case 0x14: return "gosDash";
    case 0x15: return "gosPush";
    case 0x16: return "gosTalk";
    case 0x17: return "gosRegen";
    case 0x18: return "gosRevival";
    case 0x19: return "gosInteraction";
    case 0x1a: return "gosInteractionNpc";
    case 0x1b: return "gosSwim";
    case 0x1c: return "gosSwimDash";
    case 0x1d: return "gosClimb";
    case 0x1e: return "gosGlide";
    case 0x1f: return "gosFallDamage";
    case 0x20: return "gosHold";
    case 0x21: return "gosRide";
    case 0x22: return "gosTransform";
    case 0x23: return "gosPuppet";
    case 0x24: return "gosFloat";
    case 0x25: return "gosTaxiCall";
    case 0x26: return "gosSummon";
    case 0x27: return "gosGotoHome";
    case 0x28: return "gosPvPWinLose";
    case 0x29: return "gosUseFurniture";
    case 0x2a: return "gosCashCall";
    case 0x2b: return "gosGrabTarget";
    case 0x2c: return "gosRecall";
    case 0x2d: return "gosFishing";
    case 0x2e: return "gosFishingFloat";
    case 0x2f: return "gosPlayInstrument";
    case 0x30: return "gosSummonRevive";
    case 0x31: return "gosSummonExpire";
    case 0x32: return "gosSummonItemPick";
    case 0x33: return "gosWarp";
    case 0x34: return "gosTrace";
    case 0x35: return "gosTriggerEmotion";
    case 0x36: return "gosHomeConvenient";
    case 0x37: return "gosHomemade";
    case 0x38: return "gosSummonPortal";
    case 0x3a: return "gosCoupleEmotion";
    case 0x3b: return "gosBanner";
    case 0x3c: return "gosMiniGameRps";
    case 0x3d: return "gosReact";
    case 0x3e: return "gosTreeWatering";
    case 0x3f: return "gosObserver";
    case 0x40: return "gosNurturing";
    case 0x47: return "gosWeddingEmotion";
    default: return "";
    }
}

int FUN_1417b90f0(CString strName);
#ifndef MS2_HOOK_DLL
// @0x1417b90f0
int FUN_1417b90f0(CString strName)
{
    static std::map<CString, int> s_names;
    if (s_names.empty()) {
        for (int i = 0; i < 0x48; i++) {
            int nState = i;
            s_names.insert(std::make_pair(FUN_1417b85a0(nState), nState));
        }
    }
    std::map<CString, int>::iterator it = s_names.find(strName);
    if (it != s_names.end())
        return it->second;
    return 0;
}
#endif

// @0x1417b92a0
void State::FUN_1417b92a0()
{
    FUN_1417b9310();
    FUN_1414a5870()->GetEffects(m_pOwner, vfunc_1(), reinterpret_cast<Unk_StateEffectIdList*>(&m_ids));
}
MS2_REPLACE_METHOD(0x1417b92a0, State, FUN_1417b92a0, 105, 0x48BDACAF);

// @0x1417b9310
void State::FUN_1417b9310()
{
    if (FUN_1403ed280()) {
        for (std::list<unsigned>::iterator it = m_ids.begin(); it != m_ids.end(); ++it)
            FUN_1403ed280()->FUN_1411a6060(*it);
    }
    m_ids.clear();
}
MS2_REPLACE_METHOD(0x1417b9310, State, FUN_1417b9310, 154, 0x577F43ED);

// @0x1417b93b0
void State::vfunc_29(MS2Ptr<Unk_StateArg29> p)
{
}
MS2_REPLACE_METHOD(0x1417b93b0, State, vfunc_29, 29, 0xA6990103);

// @0x1417b93e0
void State::vfunc_30(MS2Ptr<Unk_StateArg29> p)
{
}
MS2_REPLACE_METHOD(0x1417b93e0, State, vfunc_30, 29, 0x67B6B264);

// @0x1417b9410
void State::vfunc_31(int n)
{
}
MS2_REPLACE_METHOD(0x1417b9410, State, vfunc_31, 10, 0x96F6F902);

// @0x1417b9420
void State::vfunc_34()
{
}
MS2_REPLACE_METHOD(0x1417b9420, State, vfunc_34, 6, 0xA9AF6E37);

// @0x1417b9430
StateData* State::vfunc_35()
{
    return m_spData.get();
}
MS2_REPLACE_METHOD(0x1417b9430, State, vfunc_35, 31, 0x6B5D2CCA);

// @0x1417b9460
bool State::FUN_1417b9460()
{
    MS2Ptr<Unk_PCBaseComp_b18> spSkill = m_pOwner->vfunc_104(true, false, false);
    if (spSkill == 0)
        return false;
    m_pOwner->vfunc_102(reinterpret_cast<MS2Ptr<CSkillRecord>&>(spSkill));
    return true;
}
MS2_REPLACE_METHOD(0x1417b9460, State, FUN_1417b9460, 202, 0x2798BF0C);

// ---- StateClimb ----

// @0x1417bc010
int StateClimb::FUN_1417bc010()
{
    return 0x201;
}

// @0x1417bc020
StateClimb::StateClimb(PCBase* pOwner)
    : StateMoveSkill(pOwner), m_fF4(1.0f)
{
    m_n14 = 0;
    m_n44 = 0x1d;
    m_nFallbackState = 1;
    m_nMode = 1;
    m_bAltUp = false;
    m_bAltSide = false;
    m_fSpeedV = 0;
    m_fSpeedH = 0;
}

// @0x1417bc110
StateClimb::~StateClimb()
{
}

// @0x1417bc170
int StateClimb::vfunc_18()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1417bc170, StateClimb, vfunc_18, 8, 0x7F371472);

// @0x1417bc180
void StateClimb::vfunc_4(StateData* pData)
{
    StateMoveSkill::vfunc_4(pData);
    m_bAltUp = false;
    m_bAltSide = false;
    m_fSpeedV = FUN_1401d3200()->m_climbSpeedV.FUN_1402bac70();
    m_fSpeedH = FUN_1401d3200()->m_climbSpeedH.FUN_1402bac70();
    m_timerHit.FUN_140868750(100);
    m_timerHang.FUN_140868750(100);
    m_pOwner->FUN_14123cb20(false);
    if (MyPC* pMyPC = FUN_1417b84b0()) {
        if (FUN_14165f100(pMyPC))
            FUN_14165f170(pMyPC);
    }
    Unk_GmGridRef kSvc(FUN_1401cd040(&DAT_143b059e8));
    if (kSvc.FUN_140885310()) {
        efd::Point3 kPos;
        m_pOwner->vfunc_18();
        if (PCBase* pPC = FUN_140974230(m_pOwner)) {
            if (FUN_14165b500(pPC, 1))
                m_n10 = 0x60;
            else
                m_n10 = 0x61;
        }
    }
    FUN_14166d220(m_pOwner)->FUN_141240730();
}
MS2_REPLACE_METHOD(0x1417bc180, StateClimb, vfunc_4, 429, 0x2DF306D0);

// @0x1417bc340
void StateClimb::vfunc_5(int n)
{
    StateMoveSkill::vfunc_5(n);
    FUN_14166d220(m_pOwner)->FUN_141240730();
    m_pOwner->FUN_14123cb20(true);
}
MS2_REPLACE_METHOD(0x1417bc340, StateClimb, vfunc_5, 70, 0xFD7CFEDA);

// @0x1417bc390
void StateClimb::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (!FUN_1417df6a0())
        return;
    FUN_1417bdee0();
    FUN_1417be120(fTime);
    FUN_1417bda60();
    if (FUN_1417bd6c0())
        m_pOwner->vfunc_59(1, 0, 0, 0);
    if (FUN_14166d220(m_pOwner))
        FUN_14166d220(m_pOwner)->FUN_141240f20()->FUN_140cfaf30();
}
MS2_REPLACE_METHOD(0x1417bc390, StateClimb, vfunc_3, 203, 0x491A3090);

// @0x1417bc470
// MS2-FUNCTIONAL: slot 22 takes the velocity by value in the exe (the shared slot list declares a const reference)
void StateClimb::vfunc_8(double fTime)
{
    StateMoveSkill::vfunc_8(fTime);
    Unk_StBuff* pBuff = FUN_14166d240(m_pOwner);
    efd::Point3 kVel = efd::Point3::ZERO;
    if (m_timerHit.FUN_140868c00())
        kVel = pBuff->FUN_141683290();
    efd::Point3 kFacing = m_pOwner->FUN_14123cc20();
    if ((kFacing.y == -1.0f || kFacing.x == -1.0f) && kVel.z < 0.0f)
        kVel.z = 0.0f;
    m_pOwner->vfunc_22(kVel);
    if (pBuff->FUN_141683100(0x493e1)) {
        m_pOwner->vfunc_22(pBuff->FUN_141683290());
        if (m_pOwner->FUN_1416749c0() && !pBuff->FUN_141682fe0(0x30d43) && !pBuff->FUN_141682fe0(0x30d44)
            && pBuff->FUN_141682fe0(0x30d41))
            m_pOwner->vfunc_22(efd::Point3::ZERO);
        m_pOwner->vfunc_59(6, 0, 0x25, 0);
    }
}
MS2_REPLACE_METHOD(0x1417bc470, StateClimb, vfunc_8, 609, 0xA11BE701);

// @0x1417bc6e0
void StateClimb::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    switch (m_n10) {
    case 0x56:
        FUN_14166dda0(m_pOwner, 0x11);
        m_bAltSide = false;
        m_bAltUp = false;
        break;
    case 0x57:
    case 0x58:
    case 0x59:
        FUN_14166dda0(m_pOwner, m_bAltUp ? 0x12 : 0x15);
        break;
    case 0x5a:
    case 0x5b:
    case 0x5c:
        FUN_14166dda0(m_pOwner, m_bAltSide ? 0x14 : 0x17);
        break;
    case 0x5d:
        FUN_14166dda0(m_pOwner, 0x13);
        break;
    case 0x5e:
        FUN_14166dda0(m_pOwner, 0x16);
        break;
    case 0x5f:
        FUN_14166dda0(m_pOwner, 0x18);
        break;
    case 0x60:
        FUN_14166dda0(m_pOwner, 0x19);
        break;
    case 0x61:
        FUN_14166dda0(m_pOwner, 0x1b);
        break;
    case 0x62:
        FUN_14166dda0(m_pOwner, 0x1a);
        break;
    }
}
MS2_REPLACE_METHOD(0x1417bc6e0, StateClimb, vfunc_9, 377, 0xF83D6876);

// @0x1417bc8a0
// MS2-FUNCTIONAL: slot 68 takes the move by value in the exe (declared as a pointer in the shared slot list)
void StateClimb::TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID, const NiFixedString& kTextKey,
    const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime)
{
    if (FUN_14166de90(m_pOwner, 0x18, eSequenceID) && kTextKey == "upLanding") {
        efd::Point3 kFacing = m_pOwner->FUN_14123cc20();
        float fNow = FUN_14086d260()->FUN_141473230();
        efd::Point3 kMove = kFacing * 0.02f;
        m_pOwner->vfunc_68(&kMove, fNow, 0, 0, 1);
    }
}
MS2_REPLACE_METHOD(0x1417bc8a0, StateClimb, TextKeyEvent, 265, 0x6FB5E754);

// @0x1417bc9b0
void StateClimb::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (FUN_14166de90(m_pOwner, 0x12, eSequenceID) || FUN_14166de90(m_pOwner, 0x15, eSequenceID)) {
        if (m_pOwner->FUN_14123c360().y != 0.0f)
            m_pOwner->FUN_14166e0a0();
        m_bAltUp = !m_bAltUp;
    } else if (FUN_14166de90(m_pOwner, 0x14, eSequenceID) || FUN_14166de90(m_pOwner, 0x17, eSequenceID)) {
        if (m_pOwner->FUN_14123c360().y != 0.0f)
            m_pOwner->FUN_14166e0a0();
        m_bAltSide = !m_bAltSide;
    } else if (FUN_14166de90(m_pOwner, 0x13, eSequenceID) || FUN_14166de90(m_pOwner, 0x16, eSequenceID)) {
        if (m_pOwner->FUN_14123c360().x != 0.0f)
            m_pOwner->FUN_14166e0a0();
    } else if (FUN_14166de90(m_pOwner, 0x18, eSequenceID)) {
        FUN_1417beb40();
    } else if (FUN_14166de90(m_pOwner, 0x19, eSequenceID)) {
        m_n10 = 0x56;
    } else if (FUN_14166de90(m_pOwner, 0x1b, eSequenceID)) {
        m_n10 = 0x56;
    } else if (FUN_14166de90(m_pOwner, 0x1a, eSequenceID)) {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x1417bc9b0, StateClimb, EndOfSequence, 701, 0x726973E7);

// @0x1417bcc80
int StateClimb::FUN_1417bcc80()
{
    Unk_GmGridRef kSvc(FUN_1401cd040(&DAT_143b059e8));
    if (kSvc.FUN_140885310() == 0)
        return 0;
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = m_pOwner->vfunc_18() + efd::Point3(0.0f, 0.0f, 54.0f);
    kInfo.m_dir = m_pOwner->FUN_14123cc20();
    kInfo.m_maxDist = 50.0f;
    kInfo.m_groups = FUN_1417bc010();
    if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0)) {
        Unk_StPhysObj* pWall = kSvc.FUN_1401cd1a0()->FUN_1410b8e60(kInfo.m_hitEntity);
        if (pWall != 0 && kSvc.FUN_1401cd1a0()->FUN_1410b9080(pWall, 0x10000) == 0) {
            efd::Point3 kTop;
            FUN_1409618c0(pWall->m_spEntity, 0xfd95ca52, &kTop);
            float fReach = m_pOwner->vfunc_18().z + 90.0f;
            float fTop = kTop.z + 150.0f;
            if (fReach >= fTop) {
                if (FUN_1417bd420(pWall) == 0)
                    return 0;
                return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1417bcc80, StateClimb, FUN_1417bcc80, 660, 0x0B505292);

// @0x1417bcf20
int StateClimb::FUN_1417bcf20()
{
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = m_pOwner->vfunc_18() + efd::Point3(0.0f, 0.0f, 90.0f);
    kInfo.m_dir = m_pOwner->FUN_14123cc20();
    kInfo.m_maxDist = 50.0f;
    kInfo.m_groups = FUN_1417bc010();
    if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1417bcf20, StateClimb, FUN_1417bcf20, 256, 0xD1B40E82);

// @0x1417bd030
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
int StateClimb::FUN_1417bd030(int bLeft)
{
    Unk_GmGridRef kSvc(FUN_1401cd040(&DAT_143b059e8));
    if (kSvc.FUN_140885310() == 0)
        return 0;
    efd::Point3 kRight;
    efd::Point3 kSide;
    FUN_140a01250(m_pOwner->vfunc_20(), &kRight, &kSide);
    efd::Point3 kDir = bLeft ? -kSide : kSide;
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = m_pOwner->vfunc_18() + kDir * 150.0f * 0.2f + efd::Point3(0.0f, 0.0f, 54.000004f);
    kInfo.m_dir = kRight;
    kInfo.m_maxDist = 50.0f;
    kInfo.m_groups = FUN_1417bc010();
    if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0)) {
        Unk_StPhysObj* pObj = kSvc.FUN_1401cd1a0()->FUN_1410b8e60(kInfo.m_hitEntity);
        if (pObj != 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1417bd030, StateClimb, FUN_1417bd030, 723, 0xB6766466);

// @0x1417bd310
int StateClimb::FUN_1417bd310(efd::Point3 kPos)
{
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = kPos + efd::Point3(0.0f, 0.0f, 54.000004f);
    kInfo.m_dir = m_pOwner->FUN_14123cc20();
    kInfo.m_maxDist = 50.0f;
    kInfo.m_groups = FUN_1417bc010();
    if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0)) {
        FUN_14166d430(m_pOwner, -kInfo.m_hitNormal, 1, 0);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1417bd310, StateClimb, FUN_1417bd310, 259, 0x8EE1AB12);

// @0x1417bd420
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
int StateClimb::FUN_1417bd420(void* pWall)
{
    Unk_GmGridRef kSvc(FUN_1401cd040(&DAT_143b059e8));
    if (kSvc.FUN_140885310()) {
        efd::Point3 kFacing = m_pOwner->FUN_14123cc20();
        int anFlags[2];
        if (kFacing.x == 1.0f) {
            anFlags[0] = 0x10100;
            anFlags[1] = 0x1ff00;
        } else {
            anFlags[0] = 0x100ff;
            anFlags[1] = 0x10001;
        }
        for (int i = 0; i < 2; i++) {
            Unk_StPhysObj* pEdge = kSvc.FUN_1401cd1a0()->FUN_1410b9080(static_cast<Unk_StPhysObj*>(pWall), anFlags[i]);
            if (pEdge != 0) {
                efd::Point3 kEdge;
                FUN_1409618c0(pEdge->m_spEntity, 0xfd95ca52, &kEdge);
                if (anFlags[i] == 0x10100 || anFlags[i] == 0x1ff00)
                    kEdge.x = m_pOwner->vfunc_18().x;
                else
                    kEdge.y = m_pOwner->vfunc_18().y;
                if (FUN_140966ea0(kEdge, m_pOwner->vfunc_18()) < 100.0f)
                    return 0;
            }
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1417bd420, StateClimb, FUN_1417bd420, 660, 0x0D6F8F5D);

// @0x1417bd6c0
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
int StateClimb::FUN_1417bd6c0()
{
    Unk_RayCastInfo kDown;
    kDown.m_origin = m_pOwner->vfunc_18();
    kDown.m_dir = -efd::Point3::UNIT_Z;
    kDown.m_maxDist = 50.0f;
    kDown.m_groups = FUN_1417bc010();
    if (FUN_1409f7ca0()->FUN_1416892f0(&kDown, 0) && kDown.m_hitEntity != 0) {
        egf::EntityID kSelf = FUN_14166d220(m_pOwner)->FUN_141240f20()->GetEntityID();
        if (kDown.m_hitEntity->GetEntityID() != kSelf) {
            MS2Ptr<Unk_RideeFieldObj> spObj = FUN_1403ed2d0()->FUN_141bc4f10(kDown.m_hitEntity);
            if (spObj.get()) {
                efd::Point3 kNormal = spObj->FUN_140ae0150();
                if (0.0f < kNormal.z && kDown.m_hitDist <= 50.0f)
                    return 1;
            }
        }
    }
    Unk_RayCastInfo kUp;
    kUp.m_origin = m_pOwner->vfunc_18() + efd::Point3(0.0f, 0.0f, 90.0f);
    kUp.m_dir = efd::Point3::UNIT_Z;
    kUp.m_maxDist = 50.0f;
    kUp.m_groups = FUN_1417bc010();
    if (FUN_1409f7ca0()->FUN_1416892f0(&kUp, 0) && kUp.m_hitEntity != 0) {
        egf::EntityID kSelf = FUN_14166d220(m_pOwner)->FUN_141240f20()->GetEntityID();
        if (kUp.m_hitEntity->GetEntityID() != kSelf) {
            MS2Ptr<Unk_RideeFieldObj> spObj = FUN_1403ed2d0()->FUN_141bc4f10(kUp.m_hitEntity);
            if (spObj.get()) {
                efd::Point3 kNormal = spObj->FUN_140ae0150();
                if (kNormal.z < 0.0f && kUp.m_hitDist <= 140.0f)
                    return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1417bd6c0, StateClimb, FUN_1417bd6c0, 913, 0x2F74AC1A);

// @0x1417bda60
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
bool StateClimb::FUN_1417bda60()
{
    switch (m_n10) {
    case 0x56:
    case 0x5f:
    case 0x60:
    case 0x61:
        return true;
    case 0x57:
    case 0x58:
    case 0x59:
        if (FUN_1417bcc80()) {
            Unk_RayCastInfo kInfo;
            kInfo.m_dir = m_pOwner->FUN_14123cc20();
            kInfo.m_maxDist = 50.0f;
            kInfo.m_groups = 1;
            kInfo.m_origin = m_pOwner->vfunc_18() + efd::Point3(0.0f, 0.0f, 99.0f);
            if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
                return true;
            kInfo.m_origin = m_pOwner->vfunc_18() + efd::Point3(5.0f, 0.0f, 99.0f);
            if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
                return true;
            kInfo.m_origin = m_pOwner->vfunc_18() + efd::Point3(-5.0f, 0.0f, 99.0f);
            if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
                return true;
            m_n10 = 0x5f;
            return true;
        }
        break;
    case 0x5a:
    case 0x5b:
    case 0x5c: {
        NiPoint3 kPos = m_pOwner->vfunc_18();
        float afDist[2];
        afDist[1] = 5.0f;
        afDist[0] = 0.0f;
        if (FUN_1409f7ca0()->FUN_14168a450(kPos, afDist, 5.0f) && afDist[0] <= 5.0f) {
            m_n10 = 0x62;
            return true;
        }
        break;
    }
    }
    int bAttached = FUN_1417bd310(m_pOwner->vfunc_18());
    if (bAttached == 0) {
        FUN_14166d220(m_pOwner)->FUN_141240730();
        m_pOwner->vfunc_59(5, 0, 0, 0);
    }
    return bAttached != 0;
}
MS2_REPLACE_METHOD(0x1417bda60, StateClimb, FUN_1417bda60, 1095, 0x7609E356);

// @0x1417bdee0
int StateClimb::FUN_1417bdee0()
{
    if (m_n10 == 0x60)
        return 1;
    if (m_n10 == 0x5f)
        return 1;
    if (m_n10 == 0x61)
        return 1;
    if (m_n10 == 0x62)
        return 1;
    {
        efd::Point3 kFacing = m_pOwner->FUN_14123cc20();
        NiPoint3 kInput = m_pOwner->FUN_14123c360();
        if (kFacing.y == -1.0f || kFacing.x == -1.0f)
            kInput.x = -kInput.x;
        if (kInput == efd::Point3::ZERO)
            m_n10 = 0x56;
        else if (kInput.x == 0.0f) {
            if (0.0f < kInput.y)
                m_n10 = 0x57;
            else if (kInput.y < 0.0f)
                m_n10 = 0x5a;
        } else if (kInput.y == 0.0f) {
            if (0.0f < kInput.x)
                m_n10 = 0x5d;
            else if (kInput.x < 0.0f)
                m_n10 = 0x5e;
        } else if (0.0f < kInput.y && 0.0f < kInput.x)
            m_n10 = 0x58;
        else if (kInput.y < 0.0f && 0.0f < kInput.x)
            m_n10 = 0x5b;
        else if (0.0f < kInput.y && kInput.x < 0.0f)
            m_n10 = 0x59;
        else if (kInput.y < 0.0f && kInput.x < 0.0f)
            m_n10 = 0x5c;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1417bdee0, StateClimb, FUN_1417bdee0, 560, 0x7F40A0EE);

// @0x1417be120
// MS2-FUNCTIONAL: slot 68 takes the move by value in the exe (declared as a pointer in the shared slot list)
int StateClimb::FUN_1417be120(double fTime)
{
    if (FUN_1417be990(fTime) == 0) {
        switch (m_n10) {
        case 0x56:
            if (m_timerHang.FUN_140868c00()) {
                if (FUN_1417bcf20() == 0) {
                    m_pOwner->vfunc_59(1, 0, 0, 0);
                    m_timerHang.FUN_1408687f0();
                } else {
                    m_timerHang.FUN_140868750(100);
                }
            }
            break;
        case 0x57:
            FUN_1417be590(fTime);
            break;
        case 0x58:
            FUN_1417be590(fTime);
            FUN_1417be760(fTime);
            break;
        case 0x59:
            FUN_1417be590(fTime);
            FUN_1417be880(fTime);
            break;
        case 0x5a:
            FUN_1417be680(fTime);
            break;
        case 0x5b:
            FUN_1417be680(fTime);
            FUN_1417be760(fTime);
            break;
        case 0x5c:
            FUN_1417be680(fTime);
            FUN_1417be880(fTime);
            break;
        case 0x5d:
            FUN_1417be760(fTime);
            break;
        case 0x5e:
            FUN_1417be880(fTime);
            break;
        case 0x5f: {
            efd::Point3 kUp = efd::Point3::UNIT_Z * FUN_14028d3a0(170.0f);
            float fForward = FUN_14028d3a0(105.0f);
            efd::Point3 kForward = m_pOwner->FUN_14123cc20() * fForward;
            efd::Point3 kMove = (kUp + kForward) * (float)fTime;
            m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 1);
            break;
        }
        case 0x61: {
            efd::Point3 kDown = -efd::Point3::UNIT_Z;
            efd::Point3 kMove = kDown * FUN_14028d3a0(170.0f) * (float)fTime;
            m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 1);
            break;
        }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1417be120, StateClimb, FUN_1417be120, 1068, 0xD2400617);

// @0x1417be590
// MS2-FUNCTIONAL: slot 68 takes the move by value in the exe (declared as a pointer in the shared slot list)
int StateClimb::FUN_1417be590(double fTime)
{
    if (FUN_1417bcf20()) {
        efd::Point3 kMove = efd::Point3::UNIT_Z * m_fSpeedV * (float)fTime;
        m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 1);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1417be590, StateClimb, FUN_1417be590, 233, 0x59FE2165);

// @0x1417be680
// MS2-FUNCTIONAL: slot 68 takes the move by value in the exe (declared as a pointer in the shared slot list)
int StateClimb::FUN_1417be680(double fTime)
{
    efd::Point3 kDown = -efd::Point3::UNIT_Z;
    efd::Point3 kMove = kDown * m_fSpeedV * (float)fTime;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 1);
    return 1;
}
MS2_REPLACE_METHOD(0x1417be680, StateClimb, FUN_1417be680, 204, 0x1D4AF32B);

// @0x1417be760
// MS2-FUNCTIONAL: slot 68 takes the move by value in the exe (declared as a pointer in the shared slot list)
int StateClimb::FUN_1417be760(double fTime)
{
    if (FUN_1417bd030(1) == 0)
        return 0;
    efd::Point3 kFacing = m_pOwner->FUN_14123cc20();
    efd::Point3 kLeft = -kFacing.UnitCross(efd::Point3::UNIT_Z);
    efd::Point3 kMove = kLeft * m_fSpeedH * (float)fTime;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 1);
    return 1;
}
MS2_REPLACE_METHOD(0x1417be760, StateClimb, FUN_1417be760, 277, 0x525039FC);

// @0x1417be880
// MS2-FUNCTIONAL: slot 68 takes the move by value in the exe (declared as a pointer in the shared slot list)
int StateClimb::FUN_1417be880(double fTime)
{
    if (FUN_1417bd030(0) == 0)
        return 0;
    efd::Point3 kFacing = m_pOwner->FUN_14123cc20();
    efd::Point3 kRight = kFacing.UnitCross(efd::Point3::UNIT_Z);
    efd::Point3 kMove = kRight * m_fSpeedH * (float)fTime;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 1);
    return 1;
}
MS2_REPLACE_METHOD(0x1417be880, StateClimb, FUN_1417be880, 258, 0x8A0801F8);

// @0x1417be990
// MS2-FUNCTIONAL: slot 68 takes the move by value in the exe (declared as a pointer in the shared slot list)
int StateClimb::FUN_1417be990(double fTime)
{
    if (FUN_140953f30()->FUN_140ad21f0() == 0)
        return 0;
    if (m_n10 < 0x57 || 0x5e < m_n10)
        return 0;
    NiPoint3 kInput = m_pOwner->FUN_14123c360();
    efd::Point3 kFacing = m_pOwner->FUN_14123cc20();
    efd::Point3 kSide = -kFacing.UnitCross(efd::Point3::UNIT_Z);
    efd::Point3 kUp = efd::Point3::UNIT_Z;
    kUp *= kInput.y * (float)fTime * m_fSpeedV;
    kSide *= kInput.x * (float)fTime * m_fSpeedH;
    efd::Point3 kMove = kSide + kUp;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 1);
    return 1;
}
MS2_REPLACE_METHOD(0x1417be990, StateClimb, FUN_1417be990, 423, 0xEB583BE6);

// @0x1417beb40
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
void StateClimb::FUN_1417beb40()
{
    float fMargin = 2.0f;
    NiPoint3 kPos = m_pOwner->vfunc_18();
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = kPos + efd::Point3(0.0f, 0.0f, m_fF4 + 90.0f + fMargin);
    kInfo.m_dir = m_pOwner->FUN_14123cc20();
    kInfo.m_maxDist = 77.0f;
    kInfo.m_groups = FUN_1417bc010();
    efd::Point3 kTarget = kInfo.m_origin + kInfo.m_dir * 52.0f;
    float afDist[1];
    afDist[0] = 0.0f;
    if (FUN_1409f7ca0()->FUN_14168a450(kTarget, afDist, 150.0f))
        afDist[0] = afDist[0] - fMargin;
    kTarget.x = kPos.x;
    kTarget.y = kPos.y;
    kTarget.z = kTarget.z - afDist[0];
    if (FUN_1417b84b0()) {
        static float s_fShake = FUN_1401d3200()->m_climbOverShake.FUN_1402bac70();
        float fDecay = s_fShake / 3.0f;
        float fFreq = s_fShake / 60.0f;
        FUN_1409478c0()->FUN_140aeb880(s_fShake, fFreq, fDecay);
    }
    m_pOwner->vfunc_19(kTarget);
    m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417bee30
int StateClimb::vfunc_36()
{
    if (m_n10 == 0x5f)
        return 1;
    return StateMoveSkill::vfunc_36();
}
MS2_REPLACE_METHOD(0x1417bee30, StateClimb, vfunc_36, 42, 0x9C3D4954);

// @0x1417beea0
MS2Ptr<StateData> StateMoveSkill::vfunc_27()
{
    return MS2Ptr<StateData>(new StateSkillData);
}
MS2_REPLACE_METHOD(0x1417beea0, StateMoveSkill, vfunc_27, 126, 0x878E9CB0);

// @0x1417bef20
int StateMoveSkill::vfunc_15()
{
    return 1;
}
MS2_REPLACE_METHOD(0x1417bef20, StateMoveSkill, vfunc_15, 11, 0x30025ED0);

// @0x1417bef30
int StateClimb::vfunc_1()
{
    return 0x1d;
}
MS2_REPLACE_METHOD(0x1417bef30, StateClimb, vfunc_1, 11, 0xEA4E3824);

// ---- StateCrawl ----

// @0x1417bef40
StateCrawl::StateCrawl(PCBase* pOwner)
    : State(pOwner)
{
    m_bCrawling = false;
}

// @0x1417bef90
StateCrawl::~StateCrawl()
{
}

// @0x1417befc0
void StateCrawl::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n10 = 0x1c;
    m_bCrawling = false;
    FUN_14166f8f0(m_pOwner, 0, 1);
}
MS2_REPLACE_METHOD(0x1417befc0, StateCrawl, vfunc_4, 77, 0xA66A8311);

// @0x1417bf020
void StateCrawl::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_n10 = 0x1c;
    Unk_StSpeedCfg* pCfg = FUN_141671920(m_pOwner);
    m_pOwner->FUN_141671960(pCfg->m_f8);
}
MS2_REPLACE_METHOD(0x1417bf020, StateCrawl, vfunc_5, 87, 0xF66CD8AD);

// @0x1417bf080
// MS2-FUNCTIONAL: slot 68 takes the move by value in the exe (declared as a pointer in the shared slot list)
void StateCrawl::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->vfunc_63()) {
        efd::Point3 kMove = efd::Point3::ZERO;
        if (m_n10 == 0x1c) {
            efd::Point3 kDir = static_cast<Unk_StPC*>(m_pOwner)->FUN_141674b60(m_pOwner->FUN_14123c360());
            float fSpeed = m_bCrawling ? m_pOwner->vfunc_95() : 0.0001f;
            kMove = kDir * fSpeed * (float)fTime;
            FUN_14166d220(m_pOwner)->FUN_141240700(kDir * fSpeed);
        }
        m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x1417bf080, StateCrawl, vfunc_3, 534, 0x8A8E5046);

// @0x1417bf2a0
// MS2-FUNCTIONAL: slot 22 takes the velocity by value in the exe (the shared slot list declares a const reference)
void StateCrawl::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (FUN_1417b84b0()) {
        Unk_StBuff* pBuff = FUN_14166d240(m_pOwner);
        m_pOwner->vfunc_22(pBuff->FUN_141683900());
        if (!pBuff->FUN_141682fe0(0x493e5))
            m_pOwner->vfunc_59(1, 0, 0, 0);
        else if (m_pOwner->FUN_1416749c0())
            m_n10 = 0x1c;
        else if (m_n10 == 0x1c)
            m_n10 = 0x1b;
    }
}
MS2_REPLACE_METHOD(0x1417bf2a0, StateCrawl, vfunc_8, 321, 0x977C4340);

// @0x1417bf3f0
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
void StateCrawl::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    int bFalling = FUN_141675ed0(m_pOwner);
    static int s_nFallDelay = FUN_14028d260(FUN_14096b1c0(3.0f / FUN_14059d930(FUN_141240c40(true))));
    if (bFalling == 0) {
        if (m_pOwner->vfunc_99(s_nFallDelay) == 0) {
            switch (m_n10) {
            case 0x1b:
                if (!FUN_14166de90(m_pOwner, 0x20, FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460())))
                    FUN_14166dda0(m_pOwner, 0x20);
                break;
            case 0x1c: {
                CString strAnim("Prostrate_Crawl_A");
                PCBase* pPC = FUN_140974230(m_pOwner);
                if (pPC != 0 && FUN_141658e60(pPC) == 1)
                    strAnim = "Prostrate_Crawl_B";
                bool bChanged = strAnim != static_cast<Unk_StPC*>(m_pOwner)->FUN_14166dc50();
                if (bChanged) {
                    if (strAnim == "Prostrate_Crawl_A")
                        m_pOwner->FUN_141671960(0.807f);
                    else
                        m_pOwner->FUN_141671960(0.84f);
                    efd::utf8string strName((const char*)strAnim);
                    m_pOwner->FUN_14166dd20(strName, FUN_1416713c0(m_pOwner), false, false);
                }
                break;
            }
            }
        } else {
            m_pOwner->vfunc_59(5, 0, 0, 0);
        }
    } else {
        m_pOwner->vfunc_59(0x1b, 0, 0, 0);
    }
}

// @0x1417bf760
void StateCrawl::TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID, const NiFixedString& kTextKey,
    const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime)
{
    if (FUN_14166de90(m_pOwner, 0x21, eSequenceID)) {
        if (kTextKey == "begin_crawling")
            m_bCrawling = true;
        else if (kTextKey == "end_crawling")
            m_bCrawling = false;
    }
}
MS2_REPLACE_METHOD(0x1417bf760, StateCrawl, TextKeyEvent, 128, 0x4B897556);

// @0x1417bf7f0
int StateCrawl::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
        return 0;
    if (m_n10 == p->m_nSub)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1417bf7f0, StateCrawl, vfunc_22, 140, 0x1447C05F);

// @0x1417bf8c0
int StateCrawl::vfunc_1()
{
    return 3;
}
MS2_REPLACE_METHOD(0x1417bf8c0, StateCrawl, vfunc_1, 11, 0xA6B3D596);

// ---- StateDash ----

// @0x1417bf8d0
StateDash::StateDash(PCBase* pOwner)
    : State(pOwner)
{
    m_n14 = 0;
    m_fDist = 0;
    m_posLast = efd::Point3::ZERO;
    m_dir = efd::Point3::ZERO;
}

// @0x1417bf9b0
StateDash::~StateDash()
{
}

// @0x1417bf9f0
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
void StateDash::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_fDist = 0;
    m_posLast = m_pOwner->vfunc_18();
    m_dir = m_pOwner->FUN_14123cc20();
    m_pOwner->FUN_141671960(20.0f);
    FUN_14166d220(m_pOwner)->FUN_141240730();
    m_tick.FUN_140268840();
    Unk_ExpTarget kEffect;
    kEffect.m_strName = FUN_1401d31f0()->m_strDashEffect;
    kEffect.m_nOwnerId = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
    kEffect.FUN_140a53190(m_pOwner->FUN_14123c580());
    FUN_1403ed280()->FUN_1411a4a00(&kEffect);
}
MS2_REPLACE_METHOD(0x1417bf9f0, StateDash, vfunc_4, 366, 0x5300BC55);

// @0x1417bfb70
void StateDash::vfunc_5(int n)
{
    State::vfunc_5(n);
    Unk_StSpeedCfg* pCfg = FUN_141671920(m_pOwner);
    m_pOwner->FUN_141671960(pCfg->m_f8);
}
MS2_REPLACE_METHOD(0x1417bfb70, StateDash, vfunc_5, 75, 0x2CDCDE57);

// @0x1417bfbd0
// MS2-FUNCTIONAL: slot 68 takes the move by value in the exe (declared as a pointer in the shared slot list)
void StateDash::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    switch (m_n10) {
    case 0x1e: {
        if (FUN_141671a30(m_pOwner))
            m_n10 = 0x1f;
        efd::Point3 kMove = m_dir * m_pOwner->vfunc_95() * (float)fTime;
        m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
        return;
    }
    case 0x1f: {
        if (!m_timerStop.FUN_140868b80()) {
            efd::Point3 kMove = m_dir * m_pOwner->vfunc_95() * (float)fTime;
            m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
            return;
        }
        if (m_timerStop.FUN_140868c00())
            return;
        m_pOwner->FUN_141671960((1.0f - m_timerStop.FUN_140868940()) * 20.0f);
        efd::Point3 kMove = m_dir * m_pOwner->vfunc_95() * (float)fTime;
        m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
        return;
    }
    case 0x1d:
    case 0x20:
        break;
    default:
        return;
    }
    efd::Point3 kMove = m_dir * m_pOwner->vfunc_95() * (float)fTime;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
    float fStep = FUN_140966ea0(m_posLast, m_pOwner->vfunc_18());
    m_fDist += fStep;
    m_posLast = m_pOwner->vfunc_18();
    if (2.0f <= fStep) {
        if (FUN_141671a30(m_pOwner))
            m_n10 = 0x1f;
        else if (600.0f <= m_fDist)
            m_n10 = 0x1e;
    } else {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x1417bfbd0, StateDash, vfunc_3, 1436, 0xB4537625);

// @0x1417c0180
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
void StateDash::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    unsigned nSeq = FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460());
    if (m_n10 == 0x1d) {
        if (!FUN_14166de90(m_pOwner, 6, nSeq))
            FUN_14166dda0(m_pOwner, 6);
    } else if (m_n10 == 0x1f && !FUN_14166de90(m_pOwner, 7, nSeq)) {
        FUN_14166dda0(m_pOwner, 7);
        m_pOwner->vfunc_93(true);
        FUN_141475cf0()->FUN_141377420(m_pOwner, CString("land"));
    }
}
MS2_REPLACE_METHOD(0x1417c0180, StateDash, vfunc_9, 331, 0xC86FDBE5);

// @0x1417c02e0
void StateDash::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    FUN_1417c0510();
}
MS2_REPLACE_METHOD(0x1417c02e0, StateDash, vfunc_8, 46, 0x24D4758A);

// @0x1417c0320
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
void StateDash::AnimActivated(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (FUN_14166de90(m_pOwner, 7, eSequenceID)) {
        float fStop = pkManager->GetNextEventTime(NiActorManager::TEXT_KEY_EVENT, eSequenceID, NiFixedString("stop"));
        if (fStop != NiActorManager::INVALID_TIME) {
            float fNow = FUN_14086d260()->FUN_141473280();
            m_timerStop.FUN_140868750((int)((fStop - fNow) * 1000.0f));
        }
    }
}
MS2_REPLACE_METHOD(0x1417c0320, StateDash, AnimActivated, 217, 0xAA13EA93);

// @0x1417c0400
void StateDash::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (FUN_14166de90(m_pOwner, 7, eSequenceID))
        m_pOwner->vfunc_59(1, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x1417c0400, StateDash, EndOfSequence, 106, 0x0E50E152);

// @0x1417c0470
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
void StateDash::vfunc_6()
{
    State::vfunc_6();
    if (m_n10 == 0x1d) {
        m_n10 = 0x20;
        if (!FUN_14166de90(m_pOwner, 0x35, FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460())))
            FUN_14166dda0(m_pOwner, 0x35);
    }
}
MS2_REPLACE_METHOD(0x1417c0470, StateDash, vfunc_6, 148, 0xB6201BF7);

// @0x1417c0510
// MS2-FUNCTIONAL: slot 22 takes the velocity by value in the exe (the shared slot list declares a const reference)
int StateDash::FUN_1417c0510()
{
    PCBase* pPC;
    if (m_n10 == 0x1d && (pPC = FUN_1417b8370()) != 0) {
        efd::SmartPointer<egf::Entity> spEntity(FUN_141659af0(pPC, 0));
        if (FUN_1408a9090(&spEntity)) {
            if (FUN_1408a9bd0(spEntity)->ContainsModel(0xbadf0a13)) {
                m_pOwner->vfunc_22(efd::Point3::ZERO);
                m_pOwner->vfunc_59(8, 0, 0, 0);
                return 1;
            }
            if (FUN_1408a9bd0(spEntity)->ContainsModel(0xc13e30c8)) {
                m_pOwner->vfunc_22(efd::Point3::ZERO);
                m_pOwner->vfunc_59(9, 0, 0, 0);
                return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1417c0510, StateDash, FUN_1417c0510, 497, 0x7D6BE704);

// @0x1417c0a30
int StateDash::vfunc_1()
{
    return 0x14;
}
MS2_REPLACE_METHOD(0x1417c0a30, StateDash, vfunc_1, 11, 0xF06BEBEF);

// ---- StateData payloads ----

// @0x1417c0ac0
StateData::StateData()
{
}

// @0x1417c0b00
StateData::~StateData()
{
}

// @0x1417c0b30
void StateData::vfunc_1(Unk_StateDataArg* p)
{
}
MS2_REPLACE_METHOD(0x1417c0b30, StateData, vfunc_1, 11, 0x02239C70);

// @0x1417c0b50
void StateData::vfunc_2(Unk_StateDataArg* p)
{
}
MS2_REPLACE_METHOD(0x1417c0b50, StateData, vfunc_2, 11, 0x02239C70);

// @0x1417c0b70
StateSpawnData::StateSpawnData()
{
    m_pos = efd::Point3::ZERO;
}

// @0x1417c0bf0
StateSpawnData::~StateSpawnData()
{
}

// @0x1417c0c30
StateJumpToData::StateJumpToData()
{
    m_pos = efd::Point3::ZERO;
    m_f24 = 0;
    m_fGravity = -9.8f;
    m_b2c = false;
    m_fScale = 1.0f;
    m_n34 = 0;
    m_f38 = 0.0f;
}

// @0x1417c0cf0
StateJumpToData::~StateJumpToData()
{
}

// @0x1417c0d20
StateJumpData::StateJumpData()
{
    m_pos = efd::Point3::ZERO;
}

// @0x1417c0d90
StateJumpData::~StateJumpData()
{
}

// @0x1417c0dc0
StateLandData::StateLandData()
{
    m_str = "";
}

// @0x1417c0e30
StateLandData::~StateLandData()
{
}

// @0x1417c0e70
StateTurnData::StateTurnData()
{
    m_f18 = 0.0f;
    m_f1c = 0.0f;
    m_f20 = 0.0f;
    m_f24 = 1.0f;
}

// @0x1417c0ee0
StateTurnData::~StateTurnData()
{
}

// @0x1417c0f10
StateInteractNpcData::StateInteractNpcData()
{
    m_nNpc = 0;
}

// @0x1417c0f50
// MS2-FUNCTIONAL: /Od stack-slot / branch layout differs; logic follows the decompile
StateHitData::StateHitData()
{
    m_f18 = 1.0f;
    m_f1c = 0;
    m_f24 = 0;
    m_f28 = 0;
    m_n2c = 0;
    m_n30 = 0;
}

// @0x1417c0ff0
StateSkillData::StateSkillData()
{
    m_nSkill = 0;
    m_nLevel = 0;
}

// @0x1417c1040
void StateSkillData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_n64 = m_nSkill;
    p->m_n6c = m_nLevel;
}
MS2_REPLACE_METHOD(0x1417c1040, StateSkillData, vfunc_1, 68, 0x955BB070);

// @0x1417c1090
void StateSkillData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nSkill = p->m_n64;
    m_nLevel = p->m_n6c;
}
MS2_REPLACE_METHOD(0x1417c1090, StateSkillData, vfunc_2, 68, 0x32FBCE68);

// @0x1417c10e0
StateGlideData::StateGlideData()
{
    m_n20 = 0;
}

// @0x1417c1120
void StateGlideData::vfunc_1(Unk_StateDataArg* p)
{
    StateSkillData::vfunc_1(p);
    p->m_n68 = m_n20;
}
MS2_REPLACE_METHOD(0x1417c1120, StateGlideData, vfunc_1, 50, 0x9C2E0D39);

// @0x1417c1160
void StateGlideData::vfunc_2(Unk_StateDataArg* p)
{
    StateSkillData::vfunc_2(p);
    m_n20 = p->m_n68;
}
MS2_REPLACE_METHOD(0x1417c1160, StateGlideData, vfunc_2, 50, 0xD2968F69);

// @0x1417c11a0
StateSummonData::StateSummonData()
{
    m_b18 = false;
    m_pSummon = 0;
}

// @0x1417c11f0
StateSummonData::StateSummonData(void* pSummon, bool b)
{
    m_b18 = b;
    m_pSummon = pSummon;
}

// @0x1417c1250
StateStunData::StateStunData(long n)
{
    m_n18 = n;
}

// @0x1417c12a0
StateDeadNPCData::StateDeadNPCData(bool b)
{
    m_b18 = b;
}

// @0x1417c12f0
StateRecallData::StateRecallData()
{
    m_p18 = 0;
}

// @0x1417c1330
StateRecallData::StateRecallData(void* p)
{
    m_p18 = p;
}

// @0x1417c1380
StateFallData::StateFallData(const efd::Point3& kPos)
    : m_pos(kPos)
{
}

// @0x1417c13d0
StateHomemadeData::StateHomemadeData(int nA, CString str, int nB)
    : m_str(str)
{
    m_n20 = nB;
    m_n24 = nA;
}

// @0x1417c1460
void StateHomemadeData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_n24 = FUN_140718170(p->m_str70);
}
MS2_REPLACE_METHOD(0x1417c1460, StateHomemadeData, vfunc_2, 59, 0x1AFB6346);

// @0x1417c14b0
StateAutoInteractionData::StateAutoInteractionData(int a, int b, int c)
{
    m_n18 = a;
    m_n1c = b;
    m_n20 = c;
}

// @0x1417c1520
StateMicroGameRpsData::StateMicroGameRpsData(int n)
    : m_n18(n), m_n1c(-1), m_n20(-1)
{
}

// @0x1417c1590
void StateMicroGameRpsData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    Unk_StateDataArgRps* pRec = static_cast<Unk_StateDataArgRps*>(p);
    pRec->m_nB8 = m_n18;
    pRec->m_nBC = m_n1c;
    pRec->m_nC0 = m_n20;
    pRec->m_strC8 = m_str;
}
MS2_REPLACE_METHOD(0x1417c1590, StateMicroGameRpsData, vfunc_1, 131, 0xA8D16945);

// @0x1417c1620
void StateMicroGameRpsData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    Unk_StateDataArgRps* pRec = static_cast<Unk_StateDataArgRps*>(p);
    m_n18 = pRec->m_nB8;
    m_n1c = pRec->m_nBC;
    m_n20 = pRec->m_nC0;
    m_str = pRec->m_strC8;
}
MS2_REPLACE_METHOD(0x1417c1620, StateMicroGameRpsData, vfunc_2, 130, 0x6BB4FA5D);

// @0x1417c16b0
bool StateMicroGameRpsData::FUN_1417c16b0(MS2Ptr<Unk_StateArg22> p)
{
    MS2Ptr<StateSyncObjectMicroGameRps> spRps(dynamic_cast<StateSyncObjectMicroGameRps*>((Unk_StateArg22*)p));
    if (spRps == 0)
        return false;
    if (m_n1c != spRps->m_nBC)
        return false;
    if (m_n20 != spRps->m_nC0)
        return false;
    if (m_str != spRps->m_strC8)
        return false;
    return true;
}

// @0x1417c1830
StateMicroGameCoupleDanceData::StateMicroGameCoupleDanceData(int n)
    : m_n18(n), m_b1c(false)
{
}

// @0x1417c1890
void StateMicroGameCoupleDanceData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    Unk_StateDataArgDance* pRec = static_cast<Unk_StateDataArgDance*>(p);
    pRec->m_nB8 = m_n18;
    pRec->m_bBC = m_b1c;
    pRec->m_strC0 = m_str;
}
MS2_REPLACE_METHOD(0x1417c1890, StateMicroGameCoupleDanceData, vfunc_1, 113, 0x0EA4A1B5);

// @0x1417c1910
void StateMicroGameCoupleDanceData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    Unk_StateDataArgDance* pRec = static_cast<Unk_StateDataArgDance*>(p);
    m_n18 = pRec->m_nB8;
    m_b1c = pRec->m_bBC;
    m_str = pRec->m_strC0;
}
MS2_REPLACE_METHOD(0x1417c1910, StateMicroGameCoupleDanceData, vfunc_2, 112, 0xCEF11D0A);

// @0x1417c1990
bool StateMicroGameCoupleDanceData::FUN_1417c1990(MS2Ptr<Unk_StateArg22> p)
{
    MS2Ptr<StateSyncObjectMicroGameCoupleDance> spDance(
        dynamic_cast<StateSyncObjectMicroGameCoupleDance*>((Unk_StateArg22*)p));
    if (spDance == 0)
        return false;
    if (m_str != spDance->m_strC0)
        return false;
    return true;
}

// The implicit payload dtors (0x1417c1b40-0x1417c1d00) are defaulted in statedata.h and emitted here as COMDATs.

// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@@Z 0x1417bb580 ; this TU's copy (called by ~_Tree_comp_alloc 0x1417ba540; 0x14139e1c0 is another TU's)
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@@Z 0x1417bb5b0 ; called from _Buynode's catch(...)
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb6ec0-0x142cb71b0 .text$yd
