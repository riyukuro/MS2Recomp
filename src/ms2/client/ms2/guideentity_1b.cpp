// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Remainder of part 1 of client\ms2\guideentity.cpp: the guide
// manager CGuideManager (ctor / dtor, the guide.xml loader, the entity state machine, the trigger / occurrence queues, the
// item / UGC / status listener slots and the notify callbacks) and the template glue its code emits.
// See ms2/placeholder/cguidemanager.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: client\ms2\guideentity.cpp
// MS2-RANGE: 0x14138a4d0-0x141398800 .text$mn
// MS2-RANGE: 0x141399320-0x141399600 .text$mn
// MS2-PIN: ??_7CGuideManager@@6B?$TSingleton@VCGuideManager@@@@@ 0x142f00c90
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14138ed30 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14138ed90 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14138f110 ; unique
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14138f160 ; prop
// MS2-PIN: ??$?0AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH$0A@@?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH@Z 0x14138f2a0 ; unique
// MS2-PIN: ??$?0V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H$0A@@?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x14138f540 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x14138fe10 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x141390260 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141390ea0 ; node 0x40
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@1@PEAU01@@Z 0x141390f30 ; node 0x30
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@1@PEAU01@@Z 0x141390fc0 ; prop
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141391050 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@1@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@1@Z 0x141391650 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@1@@Z 0x141393d00 ; unique
// MS2-PIN: ??$_Const_cast@$$CBU?$pair@W4Occurrence@CGuideManager@@H@std@@@std@@YAPEAU?$pair@W4Occurrence@CGuideManager@@H@0@PEBU10@@Z 0x141394930 ; probe
// MS2-PIN: ??$_Kfn@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@SAAEBW4Occurrence@CGuideManager@@AEBU?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@1@@Z 0x141394950 ; order
// MS2-PIN: ??$_Lbound@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@1@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x141394a00 ; caller 0x1413a23e0
// MS2-PIN: ??$_Lbound@W4Occurrence@CGuideManager@@@?$_Tree@V?$_Tmap_traits@W4Occurrence@CGuideManager@@VGuideOccurContainer@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@5@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@1@AEBW4Occurrence@CGuideManager@@@Z 0x141394aa0 ; order
// MS2-PIN: ??$_Lbound@W4Occurrence@CGuideManager@@@?$_Tree@V?$_Tset_traits@W4Occurrence@CGuideManager@@U?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@W4Occurrence@CGuideManager@@@4@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@1@AEBW4Occurrence@CGuideManager@@@Z 0x141394b40 ; order
// MS2-PIN: ??$addressof@$$CBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@YAPEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@0@AEBV10@@Z 0x141395430 ; probe
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@J@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@J@std@@@0@AEBV10@@Z 0x141395440 ; probe
// MS2-PIN: ??$addressof@H@std@@YAPEAHAEAH@Z 0x141395450 ; probe
// MS2-PIN: ??$addressof@J@std@@YAPEAJAEAJ@Z 0x141395460 ; probe
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@HPEAX@std@@@std@@YAPEAPEAU?$_Tree_node@HPEAX@0@AEAPEAU10@@Z 0x141395470 ; probe
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@0@AEAPEAU10@@Z 0x141395480 ; probe
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@J@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@J@std@@@0@AEAV10@@Z 0x141395530 ; order
// MS2-PIN: ??$construct@PEAU?$_List_node@V?$MS2Ptr@VCGuideEntity@@@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$MS2Ptr@VCGuideEntity@@@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VCGuideEntity@@@@PEAX@std@@@1@QEAPEAU?$_List_node@V?$MS2Ptr@VCGuideEntity@@@@PEAX@1@AEAPEAU31@@Z 0x1413955a0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@JPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@JPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@JPEAX@std@@@1@QEAPEAU?$_Tree_node@JPEAX@1@AEAPEAU31@@Z 0x1413955f0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@1@AEAPEAU31@@Z 0x141395640 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@1@AEAPEAU31@@Z 0x1413956e0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@1@QEAPEAU?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@1@AEAPEAU31@@Z 0x141395730 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@1@QEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x1413958d0 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@1@@Z 0x141395c10 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@1@@Z 0x141395c20 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@PEAX@1@@Z 0x141395c30 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@std@@@1@QEAPEAU?$_Tree_node@W4Occurrence@CGuideManager@@PEAX@1@@Z 0x141395c40 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@1@QEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x141395c70 ; unique
// MS2-PIN: ??$emplace@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x141395d80 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141396110 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141396120 ; unique
// MS2-PIN: ??$forward@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@YA$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@0@AEAU10@@Z 0x1413961c0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141396210 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141396220 ; unique
// MS2-PIN: ??$insert@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@X@?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x141396360 ; unique
// MS2-PIN: ??$make_pair@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH@std@@YA?AU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@0@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAH@Z 0x141396540 ; unique
// MS2-PIN: ??0?$CRBMap@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEAA@_K@Z 0x1413968c0 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCGuideManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141396980 ; unique
// MS2-PIN: ??0?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VCGuideEntity@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@1@@Z 0x141396c10 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@W4Occurrence@CGuideManager@@HU?$less@W4Occurrence@CGuideManager@@@std@@V?$allocator@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@4@$0A@@std@@@std@@QEAA@AEBU?$less@W4Occurrence@CGuideManager@@@1@@Z 0x141396ef0 ; prop
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEAA@PEAV?$MS2Ptr@VCGuideEntity@@@@PEBU_Container_base0@1@@Z 0x141397490 ; prop
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEAA@PEAV?$MS2Ptr@VCGuideEntity@@@@PEBU_Container_base0@1@@Z 0x141397510 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@PEAX@std@@@std@@QEAA@XZ 0x1413975e0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@PEAX@std@@@std@@QEAA@XZ 0x141397600 ; prop
// MS2-PIN: ??0?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@@std@@QEAA@XZ 0x141397720 ; unique
// MS2-PIN: ??1?$CRBMap@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEAA@XZ 0x141397d10 ; unique
// MS2-PIN: ??1?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@@std@@QEAA@XZ 0x141398130 ; unique
// MS2-PIN: ??4?$MS2Ptr@VCGuideEntity@@@@QEAAAEAV0@AEBV0@@Z 0x1413983b0 ; order
// MS2-PIN: ??4?$MS2Ptr@VGuideTriggerEventGroup@@@@QEAAAEAV0@AEBV0@@Z 0x1413983f0 ; order
// MS2-PIN: ??8?$MS2Ptr@VCGuideEntity@@@@QEBA_NPEAVCGuideEntity@@@Z 0x1413984a0 ; unique
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@U?$pair@W4Occurrence@CGuideManager@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141398620 ; order
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141398670 ; order
// MS2-PIN: ??9?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1413986c0 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VCGuideEntity@@@@V?$allocator@V?$MS2Ptr@VCGuideEntity@@@@@std@@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141398700 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141398740 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Occurrence@CGuideManager@@VGuideOccurContainer@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141398780 ; prop
// MS2-PINS-END tplpin
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

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

class Unk_GmItemEvents;
Unk_GmItemEvents* FUN_140a6a840();                                  // the item event dispatcher
void FUN_1419cae20(Unk_GmItemEvents* pEvents, UIItemEventListener* pListener);
void FUN_1419caeb0(Unk_GmItemEvents* pEvents, UIItemEventListener* pListener);
class Unk_GmUgcEvents;
Unk_GmUgcEvents* FUN_140bc09f0();                                   // the UGC event dispatcher
void FUN_141b38be0(Unk_GmUgcEvents* pEvents, UIUGCEventListener* pListener);
void FUN_141b38c70(Unk_GmUgcEvents* pEvents, UIUGCEventListener* pListener);
class Unk_GmStatusEvents;
Unk_GmStatusEvents* FUN_140aa6d40();                                // the status event dispatcher
void FUN_141b0cd00(Unk_GmStatusEvents* pEvents, UIStatusEventListener* pListener);
void FUN_141b0cd90(Unk_GmStatusEvents* pEvents, UIStatusEventListener* pListener);
NotifySystem* FUN_140939a10();

unsigned char* FUN_141396750(Unk_Bitset8* pBits, unsigned char nValue);   // bitset<8>(value)
void FUN_1412751b0(const CStringW& text, int a);                    // the debug log
int FUN_140869420();                                                // millisecond clock
int FUN_141383760(int nType);                                       // the active action restriction of a type
CStringW FUN_1413892f0(int nTrigger);                               // trigger name
void FUN_1413a3710(CGuideEntity* pEntity);                          // empty hook (guideentity_9.cpp)

class Unk_GmFileSystem { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); bool FUN_140398190(); };
Unk_GmFileSystem* FUN_140166420();
class Unk_GmLog { public: void FUN_14015eb90(int level, int category, const wchar_t* format, const CStringA& arg); };
Unk_GmLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
bool FUN_14028f710(Unk_140165cf0* pElem);                           // element is enabled

class Unk_GmMovie { public: int FUN_1419102c0(); };
Unk_GmMovie* FUN_14138fd50(unsigned nUIId);                         // the cut scene movie dialog
class Unk_CommandUIRef {
public:
    ~Unk_CommandUIRef();
    UIObject* FUN_1403e8a70() const;
private: void* unknown; UIObject* object;
};
void* FUN_1403ed2b0();
struct Unk_GeUiMgr { Unk_CommandUIRef FUN_141adcea0(int); };
UIObject* FUN_1403ed9e0(Unk_CommandUIRef&);
class Unk_GmPane { public: int FUN_1422dc2d0(); };
Unk_GmPane* FUN_14136f3e0(unsigned nUIId);
class Unk_GmScene { public: int FUN_1422b9dc0(); int FUN_1422b9e00(); };
Unk_GmScene* FUN_1408e57f0();
struct Unk_GmApp { char m_pad[0x48]; void* m_pActiveWnd; };
Unk_GmApp* FUN_141482e80();
struct Unk_GmPlayerFlags { unsigned char m_a; unsigned char m_b; unsigned char m_nMode; };
void* FUN_1409a8b10();
Unk_GmPlayerFlags* FUN_140e09150(void* pPlayerInfo);

bool FUN_140528980(void* pItem);                                    // item is valid
int FUN_1405276c0(void* pItem);                                     // item id
int FUN_14053fc10(int nItemId);                                     // item kind
bool FUN_140d1a9d0(const Unk_GcOptInt* pOpt);                       // Nullable<int>::HasValue
const int* FUN_1413989f0(const Unk_GcOptInt* pOpt);                 // Nullable<int>::GetValue
Unk_GcCondRef FUN_1413a5420(CStringA strTag);                       // the condition class of a tag
void FUN_140710590(COutPacket& kPacket);                            // sends the packet

typedef CGuideManager::Occurrence GmOcc;
typedef std::vector<MS2Ptr<CGuideEntity> > GmEntVec;
typedef std::map<int, GmEntVec> GmSubMap;

// ---- ctor / dtor ------------------------------------------------------------------------------------------------------

// @0x14138a4d0
CGuideManager::CGuideManager()
    : m_n20(0), m_n24(0), m_nDebug(0), m_entities(10), m_map60(10), m_map90(10), m_triggers(0x11, 0.75f, 0.25f, 2.25f, 10)
{
    FUN_1419cae20(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_141b38be0(FUN_140bc09f0(), static_cast<UIUGCEventListener*>(this));
    FUN_141b0cd00(FUN_140aa6d40(), static_cast<UIStatusEventListener*>(this));
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyLearnEmotion"), Delegate<void(NotifyObject*)>(this, &CGuideManager::OnLearnEmotion));
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyUseSKill"), Delegate<void(NotifyObject*)>(this, &CGuideManager::OnUseSkill));
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyChangeMyLevel"), Delegate<void(NotifyObject*)>(this, &CGuideManager::OnChangeMyLevel));
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyDungeonEnterState"), Delegate<void(NotifyObject*)>(this, &CGuideManager::OnDungeonEnterState));
}

// @0x14138ab80
CGuideManager::~CGuideManager()
{
    FUN_1419caeb0(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_141b38c70(FUN_140bc09f0(), static_cast<UIUGCEventListener*>(this));
    FUN_141b0cd90(FUN_140aa6d40(), static_cast<UIStatusEventListener*>(this));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyLearnEmotion"), Delegate<void(NotifyObject*)>(this, &CGuideManager::OnLearnEmotion));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyUseSKill"), Delegate<void(NotifyObject*)>(this, &CGuideManager::OnUseSkill));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyChangeMyLevel"), Delegate<void(NotifyObject*)>(this, &CGuideManager::OnChangeMyLevel));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyDungeonEnterState"), Delegate<void(NotifyObject*)>(this, &CGuideManager::OnDungeonEnterState));
}

// ---- the state machine --------------------------------------------------------------------------------------------------

// @0x14138b140
void CGuideManager::StopAndUpdate()
{
    UpdateEntities();
    ClearEntities();
}

// @0x14138b170
int CGuideManager::SendStates()
{
    COutPacket packet(static_cast<int>(SendOp::GuideRecord), 0);
    int nCount = (int)m_map60.GetCount();
    packet.Encode4(nCount);
    for (POSITION pos = m_map60.GetHeadPosition(); pos != 0; m_map60.GetNext(pos))
    {
        packet.Encode4(m_map60.GetKeyAt(pos));
        packet.Encode4(m_map60.GetValueAt(pos));
    }
    FUN_140710590(packet);
    m_n24 = 0;
    return 1;
}

// @0x14138b280
void CGuideManager::ReceiveStates(CInPacket& kPacket)
{
    ClearEntities();
    unsigned nCount = kPacket.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        int nKey = kPacket.ReadInt32();
        int nValue = kPacket.ReadInt32();
        if (nKey == 0)
            continue;
        m_map60.SetAt(nKey, nValue);
    }
    Unk_Bitset8 bits;
    static_cast<Unk_Bitset8&>(m_bits) = *reinterpret_cast<Unk_Bitset8*>(FUN_141396750(&bits, kPacket.ReadUInt8()));
}

// @0x14138b3a0
void CGuideManager::ClearStates()
{
    m_map90.RemoveAll();
    m_map60.RemoveAll();
}

// @0x14138b3e0
void CGuideManager::Load()
{
    m_entities.RemoveAll();
    m_caches.RemoveAll();
    LoadFile(FUN_14071a5b0("Table", "guide.xml"));
    PrepareEntities();
    NotifyEntitiesLoaded();
    RefreshEntities();
    BuildOccurIndex();
    QueueAllEntities();
}

// @0x14138b4d0
void CGuideManager::LoadFile(const CStringA& strPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 1, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    MS2Ptr<CCacheData> spCache(new CCacheData);
    spCache->FUN_1401d1160(CStringA(strPath));
    m_caches.Add(spCache);
    spCache.Reset();

    std::vector<Unk_140165cf0*> events;
    FUN_14028faa0(pRoot, "event", "id", &events);
    for (unsigned i = 0; i < events.size(); i++)
    {
        Unk_140165cf0* pElem = events[i];
        if (pElem == 0)
            continue;
        MS2Ptr<CGuideEntity> spEntity(new CGuideEntity);
        if (!spEntity->Load(pElem))
            continue;
        if (m_entities.Lookup(spEntity->m_nId) != 0)
            throw std::exception("Guide Entity is Duplicated");
        m_entities.SetAt(spEntity->m_nId, spEntity);
    }
    for (Unk_140165cf0* pImport = pRoot->FUN_140165cf0("import"); pImport != 0; pImport = pImport->FUN_140168650("import"))
    {
        if (FUN_14028f710(pImport))
        {
            CStringA strName;
            FUN_1408733e0(pImport, "name", strName);
            CStringA strDir("Table");
            LoadFile(FUN_14071a5b0(strDir, strName));
        }
    }
}

// @0x14138b990
MS2Ptr<CGuideEntity> CGuideManager::FindEntity(int nId)
{
    MS2Ptr<CGuideEntity> spEntity(0);
    if (m_entities.Lookup(nId, spEntity))
        return spEntity;
    return MS2Ptr<CGuideEntity>(0);
}

// @0x14138ba40
void CGuideManager::ClearEntities()
{
    POSITION pos = m_entities.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CGuideEntity> spEntity = m_entities.GetValueAt(pos);
        spEntity->Clear(true);
        m_entities.GetNext(pos);
    }
    QueueAllEntities();
}

// @0x14138baf0
void CGuideManager::Tick()
{
    int nNow = FUN_140869420();
    if ((unsigned)(nNow - m_n20) > 250)
    {
        ProcessOccurrences();
        UpdateEntities();
        m_n20 = nNow;
    }
}

// @0x14138bb50
void CGuideManager::UpdateEntities()
{
    Unk_GmPane* pPane = FUN_14136f3e0(0x4e53);
    if (pPane == 0 || pPane->FUN_1422dc2d0() == 0)
        return;
    if (FUN_14138fd50(0x4e7e)->FUN_1419102c0() != 0)
        return;
    if (FUN_1408e57f0()->FUN_1422b9e00() == 0x6200031)
        return;
    if (!m_names.IsEmpty() && FUN_141482e80()->m_pActiveWnd != 0)
    {
        for (unsigned i = 0; i < m_names.GetCount(); i++)
            FUN_1412751b0(m_names[i], 0x14);
        m_names.RemoveAll();
    }
    if (!FUN_140166420()->FUN_140398190())
    {
        for (unsigned i = 0; i < m_caches.GetCount(); i++)
        {
            if (FUN_1401d1320(m_caches[i].operator->()))
            {
                Load();
                if (m_nDebug != 0)
                {
                    CStringW strMessage(L"Guide Reload!!!!");
                    FUN_1412751b0(strMessage, 0x14);
                }
                break;
            }
        }
    }
    unsigned nMode = FUN_140e09150(FUN_1409a8b10())->m_nMode;
    std::list<MS2Ptr<CGuideEntity> >::iterator it = m_listQueued.begin();
    while (it != m_listQueued.end())
    {
        if (ProcessEntity(*it, nMode) == true)
        {
            m_setQueued.erase(reinterpret_cast<const long&>((*it)->m_nId));
            it = m_listQueued.erase(it);
        }
        else
        {
            ++it;
        }
    }
    m_triggers.RemoveAll();
}

// @0x14138be90
void CGuideManager::ProcessOccurrences()
{
    QueueSubkeyEntities();
    QueueWholeSubkeyEntities();
    QueueBaseEntities();
    m_setPlain.clear();
    m_vecSub.clear();
    m_setPending.clear();
}

// @0x14138bf00
void CGuideManager::AddTrigger(TriggerType eType, int nValue, int nSubValue)
{
    if (FUN_14138fd50(0x4e7e)->FUN_1419102c0() != 0)
        return;
    MS2Ptr<GuideTriggerEventGroup> spGroup;
    if (!m_triggers.Lookup(eType, spGroup))
    {
        spGroup.AssignRaw(new GuideTriggerEventGroup);
        m_triggers.SetAt(eType, spGroup);
    }
    spGroup->AddValue(nValue);
    spGroup->AddSubValue(nSubValue);
    if (m_nDebug != 0)
        FUN_1412751b0(StringFormat(L"Guide Trigger:{0} value:{1} subValue:{2}", FUN_1413892f0(eType), nValue, nSubValue), 0x14);
}

// @0x14138c0d0
bool CGuideManager::CheckTrigger(TriggerType eType, Unk_GcOptInt oValue, Unk_GcOptInt oSubValue)
{
    MS2Ptr<GuideTriggerEventGroup> spGroup;
    if (!m_triggers.Lookup(eType, spGroup))
        return false;
    if (FUN_140d1a9d0(&oValue) != 0 && !spGroup->HasValue(*FUN_1413989f0(&oValue)))
        return false;
    if (FUN_140d1a9d0(&oSubValue) != 0 && !spGroup->HasSubValue(*FUN_1413989f0(&oSubValue)))
        return false;
    return true;
}

// @0x14138c210
bool CGuideManager::CheckTriggerRange(TriggerType eType, Unk_GameEventIntRange range)
{
    MS2Ptr<GuideTriggerEventGroup> spGroup;
    if (!m_triggers.Lookup(eType, spGroup))
        return false;
    if (!spGroup->HasValueInRange(&range))
        return false;
    return true;
}

// @0x14138c2d0
bool CGuideManager::ProcessEntity(MS2Ptr<CGuideEntity> spEntity, int nMode)
{
    int nStart = (spEntity->GetForce() == 0 && nMode == 0) ? 0 : 1;
    if (spEntity->m_nState == 0)
    {
        if (nStart == 0)
            return false;
        if (IsCleared(spEntity->m_nId))
            return true;
        bool bOpen = false;
        if (spEntity->CheckStart(&bOpen, 0) == 0)
        {
            if (bOpen)
                return true;
        }
        else
        {
            spEntity->StartActions();
            spEntity->SetState(1);
            if (m_nDebug != 0)
                FUN_1412751b0(StringFormat(L"[Guide] {0}:{1} Open", spEntity->m_nId, spEntity->m_strDesc), 0x14);
        }
    }
    if (spEntity->m_nState == 1)
    {
        if (spEntity->AreActionsDone() != 0)
            spEntity->SetState(2);
    }
    if (spEntity->m_nState == 2)
    {
        if (spEntity->CheckClose(0) == 0)
        {
            if (spEntity->CheckCancel(0) == 0)
            {
                if (nStart == 0)
                    spEntity->Clear(true);
            }
            else
            {
                spEntity->Clear(true);
            }
        }
        else
        {
            spEntity->StopActions();
            if (m_nDebug != 0)
                FUN_1412751b0(StringFormat(L"[Guide] {0}:{1} Close", spEntity->m_nId, spEntity->m_strDesc), 0x14);
            FinishEntity(spEntity);
            spEntity->SetState(0);
        }
    }
    return false;
}

// @0x14138c680
void CGuideManager::FinishById(int nId)
{
    MS2Ptr<CGuideEntity> spEntity = FindEntity(nId);
    if (spEntity == 0)
        return;
    FinishEntity(spEntity);
}

// @0x14138c710
void CGuideManager::FinishEntity(MS2Ptr<CGuideEntity> spEntity)
{
    m_map90.SetAt(spEntity->m_nId, 1);
    QueueOccurrence(static_cast<Occurrence>(2), spEntity->m_nId);
    if (spEntity->IsSaveSkipped() != 0)
        return;
    unsigned nStep = 0;
    if (m_map60.Lookup(spEntity->GetSaveId(), nStep) && nStep > spEntity->GetSaveStep())
        return;
    unsigned nNewStep = spEntity->GetSaveStep();
    m_map60.SetAt(spEntity->GetSaveId(), nNewStep);
    m_n24 = 1;
}

// @0x14138c850
void CGuideManager::ResetEntity(MS2Ptr<CGuideEntity> spEntity)
{
    unsigned nStep = spEntity->GetSaveStep();
    if (nStep != 0)
        nStep = nStep - 1;
    m_map90.SetAt(spEntity->m_nId, 0);
    m_map60.SetAt(spEntity->GetSaveId(), nStep);
    QueueOccurrence(static_cast<Occurrence>(2), 0);
}

// @0x14138c900
int CGuideManager::IsRestricted(int nType)
{
    return FUN_141383760(nType);
}

// @0x14138c930
int CGuideManager::IsSkillRestricted(int nSkillId)
{
    int nResult;
    if (IsRestricted(0x15) == 0)
    {
        if (IsRestricted(0x14) == 0)
            nResult = 0;
        else if (nSkillId < 0x30d41 || nSkillId > 0x30d48)
            nResult = 0;
        else
            nResult = 1;
    }
    else
    {
        nResult = 1;
    }
    return nResult;
}

// @0x14138c9c0
int CGuideManager::IsActionRestricted(int nType)
{
    if (IsRestricted(0x13) != 0)
        return 1;
    if (nType == 1 || nType == 0x1e)
        return 0;
    if (nType == 0x11)
        return IsRestricted(0x10);
    else if (nType == 0x1f)
        return IsRestricted(0x11);
    else if (nType == 0x39)
        return IsRestricted(0xd);
    else if (nType == 0x12)
        return IsRestricted(0xf);
    else if (nType == 0x13)
        return IsRestricted(0xe);
    return IsRestricted(0x12);
}

// @0x14138caa0
bool CGuideManager::IsCleared(int nId)
{
    MS2Ptr<CGuideEntity> spEntity = FindEntity(nId);
    if (spEntity == 0)
        return false;
    if (spEntity->GetSaveId() != 0 && m_map60.Lookup(1) != 0)
        return true;
    unsigned nStep = 0;
    if (m_map60.Lookup(spEntity->GetSaveId(), nStep))
    {
        if (nStep >= spEntity->GetSaveStep())
            return true;
    }
    unsigned nCleared = 0;
    if (m_map90.Lookup(spEntity->m_nId, nCleared) && nCleared == 1)
        return true;
    return false;
}

// @0x14138cc20
int CGuideManager::GetStateChanged()
{
    return m_n24;
}

// @0x14138cc40
void CGuideManager::ResetClearState()
{
    m_map90.RemoveAll();
    m_map60.RemoveAll();
    QueueOccurrence(static_cast<Occurrence>(2), 0);
    m_n24 = 1;
    ClearEntities();
    CStringW strMessage(L"[Guide] Complete ResetClearState");
    FUN_1412751b0(strMessage, 0x14);
}

// @0x14138cce0
void CGuideManager::TestEntity(int nMode, int nId)
{
    MS2Ptr<CGuideEntity> spEntity = FindEntity(nId);
    if (spEntity == 0)
    {
        CStringW strMessage(L"[Guide] Not Found Guide!!");
        FUN_1412751b0(strMessage, 0x14);
        return;
    }
    unsigned nFailed = 0;
    int nOk = 0;
    unsigned nPlayerMode = FUN_140e09150(FUN_1409a8b10())->m_nMode;
    bool bOpen = false;
    if (nMode == 0)
    {
        if (nPlayerMode == 0 && spEntity->GetForce() == 0)
        {
            CStringW strMessage(L"[Guide] Test Fail By Help Option(Not Force Type)");
            FUN_1412751b0(strMessage, 0x14);
            return;
        }
        nOk = spEntity->CheckStart(&bOpen, &nFailed);
    }
    else if (nMode == 1)
    {
        nOk = spEntity->CheckClose(&nFailed);
    }
    else if (nMode == 2)
    {
        nOk = spEntity->CheckCancel(&nFailed);
    }
    if (nOk == 0)
    {
        if (nMode == 0)
        {
            CStringW strText;
            spEntity->GetFailedText(strText, bOpen, nFailed);
            FUN_1412751b0(StringFormat(L"[Guide] OpenCondition Test Fail Step({0})", strText), 0x14);
        }
        else if (nMode == 1)
        {
            CStringW strText;
            spEntity->GetCloseText(strText, nFailed);
            FUN_1412751b0(StringFormat(L"[Guide] CloseCondition Test Fail Step({0})", strText), 0x14);
        }
        else if (nMode == 2)
        {
            CStringW strText;
            spEntity->GetCancelText(strText, nFailed);
            FUN_1412751b0(StringFormat(L"[Guide] CancelCondition Test Fail Step({0})", strText), 0x14);
        }
    }
    else
    {
        CStringW strMessage(L"[Guide] Condition Test Ok!");
        FUN_1412751b0(strMessage, 0x14);
    }
}

// @0x14138d090
void CGuideManager::TestCondition(CStringA strName)
{
    Unk_GcCondRef ref = FUN_1413a5420(CStringA(strName));
    if (ref.FUN_141387b90() == 0)
    {
        CStringW strMessage(L"[Guide] Not Found Condition Name");
        FUN_1412751b0(strMessage, 0x14);
    }
    else
    {
        ref.FUN_141387bb0()->vfunc_5();
    }
}

// @0x14138d160
void CGuideManager::ShowEntityState(int nId)
{
    if (nId == 0)
    {
        CStringW strMessage(L"[Guide] -- ShowOpenGuide Start ---");
        FUN_1412751b0(strMessage, 0x14);
        POSITION pos = m_entities.GetHeadPosition();
        while (pos != 0)
        {
            MS2Ptr<CGuideEntity> spEntity = m_entities.GetValueAt(pos);
            if (spEntity->m_nState > 0 && spEntity->m_nState < 3)
                ShowEntityState(spEntity->m_nId);
            m_entities.GetNext(pos);
        }
    }
    else
    {
        MS2Ptr<CGuideEntity> spEntity = FindEntity(nId);
        if (spEntity == 0)
        {
            CStringW strMessage(L"[Guide] Not Found Guide!!");
            FUN_1412751b0(strMessage, 0x14);
        }
        else
        {
            CStringW strState(L"Unknown");
            if (spEntity->m_nState == 0)
                strState = L"Init";
            else if (spEntity->m_nState == 1)
                strState = L"Opening";
            else if (spEntity->m_nState == 2)
                strState = L"Open";
            CStringW strCleared(IsCleared(spEntity->m_nId) ? L"O" : L"X");
            FUN_1412751b0(StringFormat(L"[Guide] {0}:{1} State({2}) isClear({3})", (unsigned)nId, spEntity->m_strDesc, strState, strCleared), 0x14);
        }
    }
}

// @0x14138d460
void CGuideManager::ToggleDebug()
{
    m_nDebug = (m_nDebug == 0);
    const wchar_t* pszState = (m_nDebug == 0) ? L"Off" : L"On";
    FUN_1412751b0(StringFormat(L"[Guide] Debug Message {0}!", pszState), 0x14);
}

// @0x14138d520
void CGuideManager::ChangeEntityState(int nId)
{
    MS2Ptr<CGuideEntity> spEntity = FindEntity(nId);
    if (spEntity == 0)
    {
        CStringW strMessage(L"[Guide] Not Found Guide!!");
        FUN_1412751b0(strMessage, 0x14);
        return;
    }
    if (spEntity->m_nState == 0)
    {
        if (IsCleared(nId))
        {
            ResetEntity(spEntity);
            spEntity->Clear(true);
            CStringW strMessage(L"[Guide] ChangeState (Clear->Init)");
            FUN_1412751b0(strMessage, 0x14);
        }
        else
        {
            spEntity->StartActions();
            spEntity->m_nState = 1;
            CStringW strMessage(L"[Guide] ChangeState (Init->Openning)");
            FUN_1412751b0(strMessage, 0x14);
        }
    }
    else if (spEntity->m_nState == 1)
    {
        CStringW strMessage(L"[Guide] ChangeState(Openning) Please Wait Moment");
        FUN_1412751b0(strMessage, 0x14);
    }
    else if (spEntity->m_nState == 2)
    {
        FinishEntity(spEntity);
        spEntity->Clear(true);
        CStringW strMessage(L"[Guide] ChangeState (Open->Clear)");
        FUN_1412751b0(strMessage, 0x14);
    }
}

// @0x14138d790
void CGuideManager::SetInitialState()
{
    m_map60.SetAt(1, 1);
    m_n24 = 1;
    QueueOccurrence(static_cast<Occurrence>(2), 0);
}

// @0x14138d7e0
void CGuideManager::QueueOccurrence(Occurrence eOccurrence, int nSubValue)
{
    if (nSubValue == 0)
        m_setPlain.insert(eOccurrence);
    else
        m_vecSub.push_back(std::make_pair(eOccurrence, nSubValue));
    m_setPending.insert(eOccurrence);
}

// @0x14138d870
int CGuideManager::InternOccurrence(const CStringA& strName)
{
    std::map<CStringA, int>::const_iterator it = m_mapNames.find(strName);
    if (it == m_mapNames.end())
    {
        int nId = (int)(m_mapNames.size() + 1);
        m_mapNames.insert(std::make_pair(strName, nId));
        return nId;
    }
    int nId = it->second;
    return nId;
}

// @0x14138d980
void CGuideManager::PrepareEntities()
{
    POSITION pos = m_entities.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CGuideEntity> spEntity = m_entities.GetValueAt(pos);
        spEntity->UpdateConditions();
        m_entities.GetNext(pos);
    }
}

// @0x14138da20
void CGuideManager::NotifyEntitiesLoaded()
{
    POSITION pos = m_entities.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CGuideEntity> spEntity = m_entities.GetValueAt(pos);
        FUN_1413a3710(spEntity.operator->());
        m_entities.GetNext(pos);
    }
}

// @0x14138dac0
void CGuideManager::QueueAllEntities()
{
    m_listQueued.clear();
    m_setQueued.clear();
    for (POSITION pos = m_entities.GetHeadPosition(); pos != 0; m_entities.GetNext(pos))
    {
        MS2Ptr<CGuideEntity> spEntity = m_entities.GetValueAt(pos);
        m_listQueued.push_back(spEntity);
        m_setQueued.insert(reinterpret_cast<const long&>(spEntity->m_nId));
    }
}

// @0x14138dbb0
void CGuideManager::RefreshEntities()
{
    POSITION pos = m_entities.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CGuideEntity> spEntity = m_entities.GetValueAt(pos);
        spEntity->MoveStartedConditions();
        m_entities.GetNext(pos);
    }
}

// @0x14138dc50
void CGuideManager::BuildOccurIndex()
{
    m_byOccur.clear();
    m_setIndexed.clear();
    POSITION pos = m_entities.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CGuideEntity> spEntity = m_entities.GetValueAt(pos);
        std::map<Occurrence, int> occurs;
        spEntity->CollectTriggerValues(reinterpret_cast<std::map<int, int>&>(occurs));   // MS2-FUNCTIONAL: the exe's map is keyed by Occurrence
        for (std::map<Occurrence, int>::iterator it = occurs.begin(); it != occurs.end(); ++it)
        {
            Occurrence eKey = it->first;
            int nSub = it->second;
            if (eKey != 0)
            {
                if (m_byOccur.find(eKey) == m_byOccur.end())
                {
                    GuideOccurContainer container;
                    m_byOccur.insert(std::make_pair(eKey, container));
                }
                if (nSub == 0)
                {
                    m_byOccur[eKey].m_all.push_back(spEntity);
                }
                else
                {
                    if (m_byOccur[eKey].m_byValue.find(nSub) == m_byOccur[eKey].m_byValue.end())
                    {
                        GmEntVec vec;
                        m_byOccur[eKey].m_byValue.insert(std::make_pair(nSub, vec));
                    }
                    m_byOccur[eKey].m_byValue[nSub].push_back(spEntity);
                }
            }
        }
        m_entities.GetNext(pos);
    }
    for (std::map<Occurrence, GuideOccurContainer>::iterator it = m_byOccur.begin(); it != m_byOccur.end(); ++it)
    {
        if (it->second.m_byValue.size() != 0)
            m_setIndexed.insert(it->first);
    }
}

// @0x14138e0c0
void CGuideManager::QueueSubkeyEntities()
{
    if (m_vecSub.empty())
        return;
    for (std::vector<std::pair<Occurrence, int> >::iterator it = m_vecSub.begin(); it != m_vecSub.end(); ++it)
    {
        Occurrence eKey = it->first;
        int nSub = it->second;
        if (m_setPlain.find(eKey) == m_setPlain.end())
        {
            std::map<Occurrence, GuideOccurContainer>::iterator itOcc = m_byOccur.find(eKey);
            if (itOcc != m_byOccur.end())
            {
                GmSubMap& groups = itOcc->second.m_byValue;
                GmSubMap::iterator itGroup = groups.find(nSub);
                if (itGroup != groups.end())
                {
                    GmEntVec& vec = itGroup->second;
                    for (GmEntVec::iterator itEnt = vec.begin(); itEnt != vec.end(); ++itEnt)
                    {
                        long nId = (*itEnt)->m_nId;
                        if (m_setQueued.find(nId) == m_setQueued.end())
                        {
                            bool bOpen = false;
                            if ((*itEnt)->CheckStart(&bOpen, 0) == 1 || !bOpen)
                            {
                                m_setQueued.insert(nId);
                                m_listQueued.push_back(*itEnt);
                            }
                        }
                    }
                }
            }
        }
    }
}

// @0x14138e400
void CGuideManager::QueueWholeSubkeyEntities()
{
    if (m_setPlain.empty())
        return;
    for (std::set<Occurrence>::iterator it = m_setPlain.begin(); it != m_setPlain.end(); ++it)
    {
        Occurrence eKey = *it;
        std::map<Occurrence, GuideOccurContainer>::iterator itOcc = m_byOccur.find(eKey);
        if (itOcc != m_byOccur.end())
        {
            GmSubMap& groups = itOcc->second.m_byValue;
            for (GmSubMap::iterator itGroup = groups.begin(); itGroup != groups.end(); ++itGroup)
            {
                GmEntVec& vec = itGroup->second;
                for (GmEntVec::iterator itEnt = vec.begin(); itEnt != vec.end(); ++itEnt)
                {
                    long nId = (*itEnt)->m_nId;
                    if (m_setQueued.find(nId) == m_setQueued.end())
                    {
                        bool bOpen = false;
                        if ((*itEnt)->CheckStart(&bOpen, 0) == 1 || !bOpen)
                        {
                            m_setQueued.insert(nId);
                            m_listQueued.push_back(*itEnt);
                        }
                    }
                }
            }
        }
    }
}

// @0x14138e6d0
void CGuideManager::QueueBaseEntities()
{
    if (m_setPending.empty())
        return;
    for (std::set<Occurrence>::iterator it = m_setPending.begin(); it != m_setPending.end(); ++it)
    {
        Occurrence eKey = *it;
        std::map<Occurrence, GuideOccurContainer>::iterator itOcc = m_byOccur.find(eKey);
        if (itOcc != m_byOccur.end())
        {
            GmEntVec& vec = itOcc->second.m_all;
            for (GmEntVec::iterator itEnt = vec.begin(); itEnt != vec.end(); ++itEnt)
            {
                long nId = (*itEnt)->m_nId;
                if (m_setQueued.find(nId) == m_setQueued.end())
                {
                    bool bOpen = false;
                    if ((*itEnt)->CheckStart(&bOpen, 0) == 1 || !bOpen)
                    {
                        m_setQueued.insert(nId);
                        m_listQueued.push_back(*itEnt);
                    }
                }
            }
        }
    }
}

// ---- the listener slots and the notify callbacks ------------------------------------------------------------------------

// @0x14138e940
void CGuideManager::vfunc_2(void* pItem)
{
    if (pItem == 0)
        return;
    if (!FUN_140528980(pItem))
        return;
    AddTrigger(static_cast<TriggerType>(0x12), FUN_1405276c0(pItem), 0);
    AddTrigger(static_cast<TriggerType>(0x13), FUN_14053fc10(FUN_1405276c0(pItem)), 0);
    QueueOccurrence(static_cast<Occurrence>(6), 0);
    QueueOccurrence(static_cast<Occurrence>(0xc), 0);
}

// @0x14138ea00
void CGuideManager::vfunc_3(void* pItem, bool)
{
    if (pItem == 0)
        return;
    if (!FUN_140528980(pItem))
        return;
    QueueOccurrence(static_cast<Occurrence>(6), 0);
    QueueOccurrence(static_cast<Occurrence>(0xc), 0);
}

// @0x14138ea70
void CGuideManager::vfunc_5(void* pItem, int)
{
    if (pItem == 0)
        return;
    if (!FUN_140528980(pItem))
        return;
    QueueOccurrence(static_cast<Occurrence>(0xc), 0);
}

// @0x14138ead0
void CGuideManager::vfunc_4(void* pItem, int)
{
    if (pItem == 0)
        return;
    if (!FUN_140528980(pItem))
        return;
    QueueOccurrence(static_cast<Occurrence>(0xc), 0);
}

// @0x14138eb30
void CGuideManager::vfunc_ugc_5()
{
    AddTrigger(static_cast<TriggerType>(1), 0, 0);
}

// @0x14138eb60
void CGuideManager::vfunc_ugc_6()
{
    AddTrigger(static_cast<TriggerType>(2), 0, 0);
}

// @0x14138eb90
void CGuideManager::OnLearnEmotion(NotifyObject* pNotify)
{
    AddTrigger(static_cast<TriggerType>(0x14), *reinterpret_cast<int*>(reinterpret_cast<char*>(pNotify) + 0x18), 0);
}

// @0x14138ebd0
void CGuideManager::OnUseSkill(NotifyObject* pNotify)
{
    AddTrigger(static_cast<TriggerType>(0x18), *reinterpret_cast<int*>(reinterpret_cast<char*>(pNotify) + 0x18), 0);
}

// @0x14138ec10
void CGuideManager::OnChangeMyLevel(NotifyObject*)
{
    QueueOccurrence(static_cast<Occurrence>(4), 0);
}

// @0x14138ec40
void CGuideManager::OnDungeonEnterState(NotifyObject*)
{
    QueueOccurrence(static_cast<Occurrence>(10), 0);
}

// @0x14138ec70
void CGuideManager::vfunc_oa0_7(int nMode, CStringW)
{
    if (FUN_1408e57f0()->FUN_1422b9dc0() != 0x620000c)
        return;
    QueueOccurrence(static_cast<Occurrence>(5), 0);
    if (nMode != 1)
        AddTrigger(static_cast<TriggerType>(4), 0, 0);
}

// @0x14138fd50
Unk_GmMovie* FUN_14138fd50(unsigned nUIId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_CommandUIRef ref = reinterpret_cast<Unk_GeUiMgr*>(FUN_1403ed2b0())->FUN_141adcea0(nUIId);
        if (ref.FUN_1403e8a70() != 0)
            return reinterpret_cast<Unk_GmMovie*>(dynamic_cast<UICutSceneMovie*>(FUN_1403ed9e0(ref)));
    }
    return 0;
}

typedef std::set<CGuideManager::Occurrence> GeSetOcc;
typedef std::set<long> GeSetInt;
typedef std::map<CGuideManager::Occurrence, GuideOccurContainer> GeMapOcc;
typedef std::map<CStringA, int> GeMapName;
typedef std::map<int, int> GeMapIntInt;
typedef std::vector<MS2Ptr<CGuideEntity> > GeVecEnt;
#define GE_SET_CTOR(K) template std::_Tree<std::_Tset_traits<K, std::less<K>, std::allocator<K>, false> >::_Tree(const std::less<K>&);
#define GE_MAP_CTOR(K, V) template std::_Tree<std::_Tmap_traits<K, V, std::less<K>, std::allocator<std::pair<const K, V> >, false> >::_Tree(const std::less<K>&);
GE_SET_CTOR(CGuideManager::Occurrence) GE_SET_CTOR(long)
GE_MAP_CTOR(CGuideManager::Occurrence, GuideOccurContainer) GE_MAP_CTOR(CStringA, int) GE_MAP_CTOR(CGuideManager::Occurrence, int)
GE_MAP_CTOR(int, GeVecEnt)

// @0x141397ba0
GuideOccurContainer::GuideOccurContainer(const GuideOccurContainer& other)
    : CPtred(other), m_byValue(other.m_byValue), m_all(other.m_all)
{
}

// @0x141397b20
GuideOccurContainer::GuideOccurContainer(GuideOccurContainer&& other)
    : CPtred(other), m_byValue(std::move(other.m_byValue)), m_all(std::move(other.m_all))
{
}

// @0x141397c80
GuideTriggerEventGroup::GuideTriggerEventGroup()
{
}

// @0x141396750
unsigned char* FUN_141396750(Unk_Bitset8* pBits, unsigned char nValue)
{
    pBits->Fill(false);
    unsigned char nRest = nValue;
    for (unsigned nBit = 0; nRest != 0 && nBit < 8; ++nBit)
    {
        if ((nRest & 1) != 0)
            pBits->Set(nBit, true);
        nRest = nRest >> 1;
    }
    return pBits->m_bits;
}
