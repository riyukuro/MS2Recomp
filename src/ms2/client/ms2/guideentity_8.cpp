// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 8 of client\ms2\guideentity.cpp: the std glue of the
// guide manager's containers (tree / list / vector helpers, allocator limits, delegate impl) and the CGuideEntity
// ctor / dtor. See ms2/placeholder/cguidemanager.h.
// MS2-UNIT: client\ms2\guideentity.cpp#8
// MS2-RANGE: 0x1413a03c0-0x1413a2c00 .text$mn
// MS2-RANGE: 0x1413a4960-0x1413a49a0 .text$mn
// MS2-PINS-BEGIN manual
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@2@XZ 0x1413a0580
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@JU?$less@J@std@@V?$allocator@J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@J@std@@@std@@@2@XZ 0x1413a05f0
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@XZ 0x1413a0660
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@XZ 0x1413a06d0
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@2@XZ 0x1413a0740
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@std@@@2@XZ 0x1413a07b0
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@2@XZ 0x1413a11d0
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@JU?$less@J@std@@V?$allocator@J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@J@std@@@std@@@2@XZ 0x1413a1230
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@XZ 0x1413a1290
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@XZ 0x1413a12f0
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@2@XZ 0x1413a1350
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@std@@@2@XZ 0x1413a13b0
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1413a09c0
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAAXXZ 0x1413a0a60
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1413a0b00
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAAXXZ 0x1413a0ba0
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEAAXXZ 0x1413a0c40
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@2@@Z 0x1413a1620
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@@Z 0x1413a17c0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@@Z 0x1413a1960
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@2@@Z 0x1413a1b00
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@std@@@2@V32@@Z 0x1413a1ca0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@2@0@Z 0x1413a1530
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@0@Z 0x1413a16d0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@0@Z 0x1413a1870
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@2@0@Z 0x1413a1a10
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@std@@@2@V32@0@Z 0x1413a1bb0
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x1413a1dc0
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@JU?$less@J@std@@V?$allocator@J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@J@std@@@std@@@2@AEBJ@Z 0x1413a1ea0
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1413a1f80
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@2@AEBW4Occurrence@CGuideManager@@@Z 0x1413a2060
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@std@@@2@AEBW4Occurrence@CGuideManager@@@Z 0x1413a2140
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x1413a2320
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@JU?$less@J@std@@V?$allocator@J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@J@std@@@std@@@2@AEBJ@Z 0x1413a2380
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1413a23e0
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@2@AEBW4Occurrence@CGuideManager@@@Z 0x1413a2440
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Occurrence@CGuideManager@@@std@@@std@@@2@AEBW4Occurrence@CGuideManager@@@Z 0x1413a24a0
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1413a2570
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@JU?$less@J@std@@V?$allocator@J@2@$0A@@std@@@std@@QEBA_KXZ 0x1413a25f0
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEBA_KXZ 0x1413a2590
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEBA_KXZ 0x1413a25b0
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEBA_KXZ 0x1413a25d0
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@JU?$less@J@std@@V?$allocator@J@2@$0A@@std@@@std@@QEBA_KXZ 0x1413a2830
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEBA_KXZ 0x1413a2850
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@QEBA_KXZ 0x1413a2870
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@QEBA_KXZ 0x1413a2890
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@JPEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@JPEAX@std@@@2@@Z 0x1413a2500
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@2@@Z 0x1413a2510
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@2@@Z 0x1413a2520
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@@2@@Z 0x1413a2530
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@2@@Z 0x1413a2540
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@std@@@std@@SA_KAEBV?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@Z 0x1413a2550
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@SA_KAEBV?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@2@@Z 0x1413a2560
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x1413a0f30
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@_K@Z 0x1413a0f00
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@2@QEAU?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@2@_K@Z 0x1413a0f90
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@JPEAX@std@@@std@@QEAAXQEAU?$_Tree_node@JPEAX@2@_K@Z 0x1413a0fc0
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x1413a1050
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@_K@Z 0x1413a1020
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@2@_K@Z 0x1413a10b0
// MS2-PIN: ?begin@?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@2@XZ 0x1413a08e0
// MS2-PIN: ?end@?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@2@XZ 0x1413a14d0
// MS2-PIN: ?capacity@?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEBA_KXZ 0x1413a0980
// MS2-PIN: ?size@?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEBA_KXZ 0x1413a28f0
// MS2-PIN: ?begin@?$vector@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Occurrence@CGuideManager@@H@std@@@std@@@std@@@2@XZ 0x1413a0880
// MS2-PIN: ?end@?$vector@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Occurrence@CGuideManager@@H@std@@@std@@@std@@@2@XZ 0x1413a1470
// MS2-PIN: ?capacity@?$vector@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@QEBA_KXZ 0x1413a0940
// MS2-PIN: ?size@?$vector@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@QEBA_KXZ 0x1413a28b0
// MS2-PIN: ?end@?$list@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@2@XZ 0x1413a1410
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x1413a0490
// MS2-PIN: ?_Xlength@?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@CAXXZ 0x1413a03c0
// MS2-PIN: ?_Xlength@?$vector@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@CAXXZ 0x1413a03e0
// MS2-PIN: ?clear@?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEAAXXZ 0x1413a0dc0
// MS2-PIN: ?empty@?$vector@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@QEBA_NXZ 0x1413a1180
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCGuideEntity@@@@XZ 0x1413a26b0
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VCGuideEntity@@@@XZ 0x1413a26d0
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@W4Occurrence@CGuideManager@@H@2@XZ 0x1413a26f0
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@W4Occurrence@CGuideManager@@H@2@XZ 0x1413a2710
// MS2-PIN: ?_Myhead@?$_List_alloc@U?$_List_base_types@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEAAAEAPEAU?$_List_node@V?$MS2Ptr@VCGuideEntity@@@@PEAX@2@XZ 0x1413a2730
// MS2-PIN: ?pointer_to@?$pointer_traits@PEBU?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@SAPEBU?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@2@AEBU32@@Z 0x1413a2750
// MS2-PIN: ?select_on_container_copy_construction@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SA?AV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@2@AEBV32@@Z 0x1413a2810
// MS2-PIN: ?push_back@?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEAAX$$QEAV?$MS2Ptr@VCGuideEntity@@@@@Z 0x1413a27b0
// MS2-PIN: ?push_back@?$vector@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@QEAAXAEBU?$pair@W4Occurrence@CGuideManager@@H@2@@Z 0x1413a27e0
// MS2-PINS-END manual
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@JPEAX@std@@@std@@QEAAPEAU?$_Tree_node@JPEAX@2@_K@Z 0x1413a0400 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@_K@Z 0x1413a0460 ; prop
// MS2-PIN: ?begin@?$list@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@2@XZ 0x1413a0820 ; unique
// MS2-PIN: ?clear@?$list@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEAAXXZ 0x1413a0ce0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCGuideManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1413a0e40 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVCGuideManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x1413a2220 ; unique
// MS2-PIN: ??$Call@VCGuideManager@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVCGuideManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVCGuideManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x1413a2250 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCGuideManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1413a2290 ; unique
// MS2-PIN: ?max_size@?$vector@U?$pair@W4Occurrence@CGuideManager@@H@std@@V?$allocator@U?$pair@W4Occurrence@CGuideManager@@H@std@@@2@@std@@QEBA_KXZ 0x1413a2610 ; prop
// MS2-PIN: ?max_size@?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@QEBA_KXZ 0x1413a2660 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\guideentity.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <list>
#include <map>
#include <set>
#include <vector>

#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/client/ms2/guideentity.h"

// @0x1413a2a50
CGuideEntity::CGuideEntity()
    : m_nId(0), m_nState(0), m_nForce(0), m_nSaveId(0), m_nSaveStep(1), m_nNoSave(0)
{
}

// @0x1413a2b40
CGuideEntity::~CGuideEntity()
{
    Clear(false);
}

typedef std::set<CGuideManager::Occurrence> GeSetOcc;
typedef std::set<long> GeSetInt;
typedef std::map<int, int> GeMapIntInt;
typedef std::map<CStringA, int> GeMapName;
typedef std::map<CGuideManager::Occurrence, GuideOccurContainer> GeMapOcc;
typedef std::map<int, std::vector<MS2Ptr<CGuideEntity> > > GeMapSub;
typedef std::list<MS2Ptr<CGuideEntity> > GeListEnt;
typedef std::vector<std::pair<CGuideManager::Occurrence, int> > GeVecSub;
typedef std::vector<MS2Ptr<CGuideEntity> > GeVecEnt;

// The members of the guide manager's containers the exe emits in this part (each container instantiates its own copy).
#define GE_TREE_ROLES(C)                                                                                                \
    template C::_Mybase::iterator C::_Mybase::begin() noexcept;                                                                  \
    template C::_Mybase::iterator C::_Mybase::end() noexcept;                                                                    \
    template C::_Mybase::size_type C::_Mybase::size() const noexcept;                                                            \
    template C::_Mybase::size_type C::_Mybase::max_size() const noexcept;
#define GE_TREE_ERASE(C)                                                                                                \
    template void C::_Mybase::clear() noexcept;                                                                                  \
    template C::_Mybase::iterator C::_Mybase::erase(C::_Mybase::const_iterator);                                        \
    template C::_Mybase::iterator C::_Mybase::erase(C::_Mybase::const_iterator, C::_Mybase::const_iterator);
#define GE_TREE_FIND(C)                                                                                                 \
    template C::_Mybase::iterator C::_Mybase::find(const C::key_type&);                                                 \
    template C::_Mybase::iterator C::_Mybase::lower_bound(const C::key_type&);

GE_TREE_ROLES(GeSetOcc) GE_TREE_ROLES(GeSetInt) GE_TREE_ROLES(GeMapIntInt) GE_TREE_ROLES(GeMapName) GE_TREE_ROLES(GeMapOcc) GE_TREE_ROLES(GeMapSub)
GE_TREE_ERASE(GeSetOcc) GE_TREE_ERASE(GeMapSub) GE_TREE_ERASE(GeMapIntInt) GE_TREE_ERASE(GeMapName) GE_TREE_ERASE(GeMapOcc)
GE_TREE_FIND(GeSetOcc) GE_TREE_FIND(GeSetInt) GE_TREE_FIND(GeMapName) GE_TREE_FIND(GeMapOcc) GE_TREE_FIND(GeMapSub)

template GeListEnt::iterator GeListEnt::begin() noexcept;
template GeListEnt::size_type GeListEnt::max_size() const noexcept;
template void GeListEnt::push_back(const MS2Ptr<CGuideEntity>&);
template GeVecEnt::iterator GeVecEnt::begin() noexcept;
template GeVecEnt::iterator GeVecEnt::end() noexcept;
template void GeVecEnt::clear() noexcept;
template void GeVecEnt::push_back(const MS2Ptr<CGuideEntity>&);
template void GeVecEnt::push_back(MS2Ptr<CGuideEntity>&&);
template GeVecSub::iterator GeVecSub::begin() noexcept;
template GeVecSub::iterator GeVecSub::end() noexcept;
template void GeVecSub::clear() noexcept;
template void GeVecSub::push_back(const std::pair<CGuideManager::Occurrence, int>&);
template void GeVecSub::push_back(std::pair<CGuideManager::Occurrence, int>&&);
template class Delegate<void(NotifyObject*)>::DelegateImpl<std::pair<CGuideManager*, void (CGuideManager::*)(NotifyObject*)> >;

// Allocator glue for every node / element type the containers above use.
#define GE_ALLOC(T)                                                                                                     \
    template T* std::allocator<T>::allocate(size_t);                                                                    \
    template void std::allocator<T>::deallocate(T*, size_t);
#define GE_ALLOC_TREE(C) GE_ALLOC(C::_Mybase::_Node)
GE_ALLOC_TREE(GeSetOcc) GE_ALLOC_TREE(GeSetInt) GE_ALLOC_TREE(GeMapIntInt) GE_ALLOC_TREE(GeMapName) GE_ALLOC_TREE(GeMapOcc) GE_ALLOC_TREE(GeMapSub)
GE_ALLOC(MS2Ptr<CGuideEntity>)
typedef std::pair<CGuideManager::Occurrence, int> GeSubPair;
GE_ALLOC(GeSubPair)
typedef GeListEnt::_Node GeListNode;
GE_ALLOC(GeListNode)
template void GeListEnt::clear() noexcept;
template GeListEnt::iterator GeListEnt::end() noexcept;
template bool GeListEnt::empty() const noexcept;
template bool GeSetOcc::_Mybase::empty() const noexcept;
template GeSetInt::key_compare GeSetInt::_Mybase::key_comp() const;
template GeListEnt::iterator GeListEnt::erase(GeListEnt::const_iterator);
template bool GeVecEnt::empty() const noexcept;
template bool GeVecSub::empty() const noexcept;
template struct std::pointer_traits<const GeMapOcc::value_type*>;
template std::allocator<GeMapSub::_Mybase::_Node>
std::_Default_allocator_traits<std::allocator<GeMapSub::_Mybase::_Node> >::select_on_container_copy_construction(
    const std::allocator<GeMapSub::_Mybase::_Node>&);

MS2_EMIT_CRT_MEMMOVE_S();
