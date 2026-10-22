// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See pcbase.h.
// This file covers the PCBase translation unit only. The PC TU (0x14164dfd0-0x14166a650, .text$di 0x1400fb010-0x1400fb4d0)
// and the buff-tracker TU at 0x141682e90 (.text$di 0x1400fb790-) share the unit name but are separate objects.
// MS2-UNIT: client\ms2\pcbase.cpp
// MS2-RANGE: 0x14166a650-0x141682e90 .text$mn
// MS2-RANGE: 0x1400fb4d0-0x1400fb790 .text$di
// MS2-RANGE: 0x142cb4000-0x142cb40e0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14167a570 ; unique
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x14167a760 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14167a8b0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@1@@Z 0x14167a9c0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14167aab0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@1@AEAU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@1@1@Z 0x14167b0a0 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@1@@Z 0x14167c040 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@1@@Z 0x14167d090 ; unique
// MS2-PIN: ??$_Kfn@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@1@@Z 0x14167d4b0 ; prop
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@1@AEBH@Z 0x14167d560 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14167d780 ; unique
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@1@AEAPEAU31@@Z 0x14167d980 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14167da80 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14167dc30 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x14167e2a0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x14167e400 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14167e460 ; prop
// MS2-PIN: ??1CNode@?$CAtlList@V?$MS2Ptr@VUnk_PCBaseComp_b18@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_PCBaseComp_b18@@@@@ATL@@@ATL@@QEAA@XZ 0x14167e7e0 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14167eec0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14167f1c0 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14167f270 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14167f450 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@XZ 0x141680aa0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141680bc0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@@Z 0x141680cb0 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@@Z 0x141681d90 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@2@@Z 0x141681de0 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@@Z 0x141681f00 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@PEAU32@@Z 0x141682010 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@PEAU32@@Z 0x141682070 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@@Z 0x141682320 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@2@XZ 0x1416825d0 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@2@XZ 0x141682920 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x141682d20 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@std@@@2@@Z 0x141682d90 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x141682e70 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GPCBase@@UEAAPEAXI@Z 0x14167f670
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@2@@Z 0x141681a30
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14167a620
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14167a800
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14167dda0
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14167ddc0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14167f320
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141681b40
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14167a6c0
// MS2-PIN: ?GetClassDesc@PCBase@@UEBAPEBVClassInfo@efd@@XZ 0x14167f940
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$vector@IV?$allocator@I@std@@@std@@@std@@@4@@std@@@std@@@std@@@std@@QEAA@XZ 0x14167e430
// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400fb6f0
// MS2-PIN: ??0PCBase@@QEAA@XZ 0x14166a650
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VUnk_PCBaseComp_b18@@@@QEAAAEAV1@PEAVUnk_PCBaseComp_b18@@@Z 0x14167ebf0
// MS2-PIN: ?GetTail@?$CAtlList@V?$MS2Ptr@VUnk_PCBaseComp_b18@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_PCBaseComp_b18@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VUnk_PCBaseComp_b18@@@@XZ 0x14167fa30
// MS2-PIN: ??$PCBaseDialog@VUIDPSDialog@@@@YAPEAVUIDPSDialog@@H@Z 0x14167a900
// MS2-PIN: ??_7PCBase@@6BIBase@efd@@@ 0x142f4c6f0
// MS2-PIN: ?TypeCast@PCBase@@UEBA_NIPEAPEAX@Z 0x141680720
// MS2-PIN: ?TypeCast@PCBase@@UEBA_NIPEAPEBX@Z 0x141680770
// MS2-PIN: ??_7PCBase@@6BCallbackObject@NiActorManager@@@ 0x142f4cad8
// MS2-PIN: ??0?$MS2Ptr@VCStateManager@@@@QEAA@XZ 0x14167dfe0
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCBaseEmoPlayer@@@@QEAA@XZ 0x14167e030
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCBaseComp_ac8@@@@QEAA@XZ 0x14167e090
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCBaseComp_a68@@@@QEAA@XZ 0x14167e0b0
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pcbase.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "pcbase.h"
#include <egf/Entity.h>
#include "ms2/client/ms2/ridee.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/animationmanager.h"
#include "ms2/placeholder/state.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/stateemotionidle.h"
#include "ms2/client/ms2/functioncubeobject.h"        // CBoxCollision
#include "ms2/client/ms2/afterimageeffectparam.h"    // Unk_AfterImageColor
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/effectdummy.h"
#include "ms2/client/ms2/effectservice.h"           // EffectNode
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/Matrix3.h>
#include <algorithm>
#include <NiMatrix3.h>
#include <NiFixedString.h>
#include <NiFloatsExtraData.h>
#include <NiActorManager.h>

// ---- unit-local placeholders ----

// The lazily created per-actor components (vfunc_80..87, 103/104). Their exe types are UI entities:
// a58 UIHpBar, a68 UIShieldBar, a78 UINameTag, a88 UIEmoticon, a98 UIBuffBalloon, aa8 UIChatBalloon,
// ab8 UIPopupProfileImage, ac8 UIBanner (::Entity each).
class Unk_PCBaseComp_a58 : public CPtred
{
public:
    void FUN_141992140(int bShow);
    int FUN_141992160();
    void FUN_141992180(__int64 nCur, __int64 nMax);
    void FUN_141992230(__int64 nCur, __int64 nMax);                 // UIHpBar::Entity, set hp
};
class Unk_PCBaseComp_a68 : public CPtred
{
public:
    void FUN_140e85fc0(__int64 nCur, __int64 nMax);                 // UIShieldBar::Entity, set shield
    void FUN_140e85ed0(int bShow);
    void FUN_140e85f10(__int64 nCur, __int64 nMax);
};
class Unk_PCBaseComp_a78 : public CPtred
{
public:
    void FUN_140f48d80();                                           // UIHudEntity::Entity: m_48 = 1
};
class Unk_PCBaseComp_a88 : public CPtred {};
class Unk_PCBaseComp_a98 : public CPtred {};
class Unk_PCBaseComp_aa8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // refresh
    void FUN_1418fb730(const CStringW& strText);                    // UIChatBalloon::Entity, set the text
};
class Unk_PCBaseTextFilter
{
public:
    void FUN_1416fb340(CStringW& strText);
};
Unk_PCBaseTextFilter* FUN_1403b4750();
class Unk_PCBaseComp_ab8 : public CPtred {};
class Unk_PCBaseComp_ac8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // show
    virtual void vfunc_3();                                         // hide
    void FUN_140ba8720(int nType);                                  // UIBanner::Entity
};
// RideeItemInfo (RTTI; 0x90, vftable 0x142d9fff8): the ugc item a ridee was summoned with.
class Unk_PCBaseComp_b18 : public CPtred
{
public:
    Unk_PCBaseComp_b18(int nItemId, __int64 nItemUid, const CUgcItemLook& kLook);   // 0x1408970e0
    int FUN_141759960();
    int FUN_141759e40();

    char m_pad_10[0x28 - sizeof(CPtred)];
    __int64 m_nTagId;                                               // +0x28
    char m_pad_30[0x8c - 0x30];
    int m_n8c;                                                      // +0x8c
};
void FUN_1417ea750(PCBase* pActor, MS2Ptr<Unk_PCBaseComp_b18> spItem);

// CColorBoostData (0x20; ?\colorboostdata.cpp).
class CColorBoostData
{
public:
    CColorBoostData(float a, float b, float c);                     // 0x14109b6b0
    virtual ~CColorBoostData();                                     // 0x14109b750
private:
    bool m_b08;
    float m_f0c;                                                    // start time
    float m_f10;
    float m_f14;                                                    // duration
    float m_f18;
    float m_f1c;
};

// The buffs' extra members (FUN_141674bc0 / FUN_141675240).
class Unk_PCBaseBuffsEx : public Unk_PCBaseBuffList
{
public:
    int FUN_140970990();
    unsigned int FUN_140970bf0();                                   // skill-use disable mask
    int FUN_140970c10(class Unk_PCBaseSkillLevel* pLevel, int n);         // a buff blocks this skill's knock-back
    unsigned int FUN_1409711c0();                                   // movement flags of the active buffs
};

int FUN_1417e9330(State* pState);                                 // the skill state's skill id

extern const NiRTTI DAT_143ad1588;                                  // EffectNode::ms_RTTI

// The emotion table (?\\stateemotionidle.cpp has the same row type).
class Unk_EmoRow : public CPtred
{
public:
    int FUN_1407e9a60();                                 // row kind (0xe = emotion)
    CString FUN_1407e9cb0();                             // animation name
    char m_pad_18[0x18];
    int m_n30;                                           // +0x30 animation speed
};
class Unk_PCBaseEmoTable
{
public:
    MS2Ptr<Unk_EmoRow> FUN_1407ee1d0(int nEmotion);
};
Unk_PCBaseEmoTable* FUN_1401958b0();
template <> MS2Ptr<Unk_EmoRow>::~MS2Ptr();                                              // 0x14063e5c0
template <> bool MS2Ptr<Unk_EmoRow>::operator==(Unk_EmoRow* p) const;                   // 0x14063eab0
template <> Unk_EmoRow* MS2Ptr<Unk_EmoRow>::operator->() const;                         // 0x14063ed50

// The graphics option singleton (FUN_141679fa0).
class Unk_PCBaseGfxOption
{
public:
    int FUN_14109a9d0();                                            // skin colour on the "FA_Skin" child
};
Unk_PCBaseGfxOption* FUN_1409f7c90();
extern NiFixedString DAT_143ae50f8;                                 // the skin colour extra data key

// TSingleton<CBattleRecordManager> (vfunc_113).
class Unk_PCBaseBattleRecord
{
public:
    void FUN_140a04ef0(void* p);
};
Unk_PCBaseBattleRecord* FUN_140e09140();

// MS2Ptr members instantiated by other objs.
template <> MS2Ptr<UISwfEntity>::MS2Ptr(UISwfEntity* p);                                 // 0x140f9c100
template <> MS2Ptr<UISwfEntity>::~MS2Ptr();                                             // 0x140b62af0
template <> MS2Ptr<CSkillRecord>::~MS2Ptr();                                            // 0x140975740
template <> MS2Ptr<Unk_RideeData>::~MS2Ptr();                                           // 0x140788ed0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::operator->() const;                   // 0x1407895d0

// The argument of vfunc_71/73 (passed as MS2Ptr by value; the callee releases it).
class Unk_PCBaseEmoAnim : public CPtred {};                          // the effect set's +0x30 animation record
template <> Unk_PCBaseEmoAnim* MS2Ptr<Unk_PCBaseEmoAnim>::get() const;                 // 0x1411c0200
class Unk_PCBaseFxSet : public CPtred
{
public:
    CString FUN_1411bd0c0(int n);
    void* m_pad_18[3];
    MS2Ptr<Unk_PCBaseEmoAnim> m_sp30;                               // +0x30
    CAtlArray<CString> m_arrEffects;                                // +0x40 effect names
};
MS2_CHECK_OFFSET(Unk_PCBaseFxSet, m_arrEffects, 0x40);
class Unk_PCBaseFxSource : public CPtred
{
public:
    virtual CString vfunc_1();                                      // the source's name
    virtual MS2Ptr<Unk_PCBaseFxSet> vfunc_2(void* pKey);
};
template <> bool MS2Ptr<Unk_PCBaseFxSet>::operator==(Unk_PCBaseFxSet* p) const;           // 0x1411c0130
template <> bool MS2Ptr<Unk_PCBaseFxSource>::operator==(Unk_PCBaseFxSource* p) const;     // 0x1411c0170
class Unk_PCBaseEmoPlayer : public CPtred                           // 0x88
{
public:
    Unk_PCBaseEmoPlayer(PCBase* pOwner);                            // 0x1418482f0
    void FUN_1418484a0(MS2Ptr<Unk_PCBaseEmoAnim> spAnim, const CString& strName);
    void FUN_141848650();
    bool FUN_141848740(int nTime);
    void* m_pad_18[14];
};
MS2_CHECK_SIZE(Unk_PCBaseEmoPlayer, 0x88);
class Unk_PCBaseState0b : public State                              // StateEmotion (stateemotionidle.h)
{
public:
    int FUN_1417c4320();
    // @0x14167f950
    CString FUN_14167f950() { return m_strAnim; }
    void* m_pad_40[2];
    CString m_strAnim;                                              // +0x50
};
class Unk_PCBaseState0d : public State                              // ?\statehit.cpp
{
public:
    int FUN_1417cb160();
};
class Unk_PCBaseState0f : public State
{
public:
    int FUN_1417c6a30();
};
class Unk_PCBaseSpawnMgr
{
public:
    Unk_PCBaseFxLib* FUN_1411bf1b0();
};
class Unk_PCBaseFxLib
{
public:
    MS2Ptr<Unk_PCBaseFxSource> FUN_1411bde10(int nId);
};
Unk_PCBaseSpawnMgr* FUN_140a50010();

// The stat formula service (FUN_1401c0db0; blackmarketitemoption / usermail use other slices of it).
class Unk_PCBaseFormula
{
public:
    float FUN_140674100(__int64 nStat, int nBonus);                // move speed
    float FUN_140674290(__int64 nStat);                             // move speed of a 0x6200045 actor
    float FUN_140674420(__int64 nStat, float f);                    // CLua::FUN_140674420 (luautil.h)
};
Unk_PCBaseFormula* FUN_1401c0db0();

// An entity seen through its property getters.
class Unk_PCBaseEntity : public egf::Entity
{
public:
    int FUN_1408a2060(unsigned int uiPropId, efd::utf8string* pOut);   // string property
    void FUN_140ae1160(unsigned int uiPropId, unsigned short* pOut);  // short property
};
class Unk_PCBaseHitReport
{
public:
    egf::EntityID FUN_140cfaf70();                                  // id of the entity stood on
    void FUN_140cfb020(egf::Entity* pEntity);                       // the entity stood on
    Unk_PCBaseEntity* FUN_140cfaff0();                              // the entity stood on
};

// The fall-damage request (packet 0x34).
struct Unk_PCBaseFallDamage
{
    Unk_PCBaseFallDamage() : m_fHeight(0.0f) {}                     // 0x14167e4e0
    void FUN_1401fc710(COutPacket& kPacket);                        // encode
    float m_fHeight;
};
void FUN_140710590(COutPacket& kPacket);                            // send

// A physics ray query (physxhelper.h's Unk_RayCastInfo; 0x68).
struct Unk_PCBaseRayHit
{
    Unk_PCBaseRayHit();                                             // 0x140ad4440
    efd::Point3 m_origin;                                           // +0x00
    efd::Point3 m_dir;                                              // +0x0c
    float m_maxDist;                                                // +0x18
    int m_groups;                                                   // +0x1c
    void* m_20;
    void* m_28;
    egf::Entity* m_hitEntity;                                       // +0x30
    void* m_hitActor;
    void* m_hitShape;
    float m_hitDist;                                                // +0x48
    efd::Point3 m_hitPoint;                                         // +0x4c
    efd::Point3 m_hitNormal;                                        // +0x58
};
MS2_CHECK_SIZE(Unk_PCBaseRayHit, 0x68);
class Unk_PCBasePhysX
{
public:
    int FUN_14168a310(const efd::Point3& kFrom, efd::Point3* pHit, Unk_PCBaseRayHit* pInfo, float fMaxDist, efd::Point3* pNormal, int nB);
    int FUN_14168a230(NiPoint3 kFrom, efd::Point3& kHit, NiPoint3 kDir, float fLen, int nMask);   // ray cast
    int FUN_14168a450(efd::Point3& kPos, float* pfHeight, float fRange);                                // ground probe
};
Unk_PCBasePhysX* FUN_1409f7ca0();
float FUN_14028d380(float fValue);                                  // percent (x100)
int FUN_14082f1a0(int nType);                                       // stat kind: 0 = 32-bit value

// The physics/controller body of an actor (0xf8; gameobject unit 0x14123f2d0..0x141241300).
class GameObjectControllerHitReport;
class Unk_PCBaseBody
{
public:
    Unk_PCBaseBody();                                               // 0x14123f2d0
    ~Unk_PCBaseBody();                                              // 0x14123f460
    void FUN_14123f5b0(PCBase* pOwner, void* pEntity, efd::Point3 kPos, float fHeight, float fRadius);
    void FUN_14123fd30(int nGroup);
    void FUN_14123fbf0(short nMode);
    NiPoint3 FUN_141240df0();                                       // ground normal
    int FUN_141240ed0();                                            // collision flags
    int FUN_141240ef0();                                            // slope limit
    Unk_PCBaseHitReport* FUN_141240f20();
    void FUN_141240730();                                           // drop the stood-on entity
    void FUN_141241070();                                           // start falling
    int FUN_141240f40();                                            // grounded
    int FUN_141240db0();
    int FUN_141240780();
    efd::Point3 FUN_1412407f0(float fTime, int bStill);             // the velocity step of this frame
    int FUN_1412412b0();
    void FUN_14123fe70(NiPoint3 kPos);
    efd::Point3 FUN_14123fd90();
    void FUN_14123ff80(efd::Point3 kMove, unsigned int nFlags);     // move the controller
private:
    char m_pad[0xf8];
};

// The object a GameObject carries along (vfunc_26; gameobject.cpp).
class Unk_GoAttachment
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual float vfunc_6();                                        // height
};

// The actor's buffs as other units see them (FUN_1416749a0 returns &m_unk_748).
class Unk_PCBaseBuffs : public Unk_PCBaseBuffList
{
};

// The weak reference at +0x628 (ctor 0x140ae13b0, dtor 0x140a00490).
Unk_GoAttachment* FUN_140a006f0(void* pWeak);

// CString + const char* (the exe's out-of-line operator+; compiling it here needs the unresolvable MFC CopyChars import).
CString FUN_14038f6d0(const CString& str, const char* psz);

// The node smart pointers at +0xbe8 / +0xc38 / +0xc40.
// The entity manager (0x1409670f0) and its lookup / property getter.
class Unk_PCBaseEntMgr;
Unk_PCBaseEntMgr* FUN_1409670f0();
egf::Entity* FUN_1411cf440(Unk_PCBaseEntMgr* pMgr, const egf::EntityID& kId);
void FUN_1409618c0(egf::Entity* pEntity, unsigned int nPropId, NiPoint3& kValue);
const egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);          // the entity's id
int FUN_1408a13d0(NiPoint3 kPos);                                   // the cube cell index of a position (ugcmapdata_1.cpp)
void FUN_1409fabf0(void* pNodePtr, void* pNode);

// The shadow mesh (efd::SmartPointer at GameObject +0x58; unit_14160fb10).
class CObjectShadow : public NiRefObject
{
public:
    void FUN_14160fe50(bool b);
    void FUN_14160feb0(int n, const efd::Point3& kPos, const efd::Point3& kUp, float f, bool b);
};

// An effect request handed to the effect manager (0x70; ctor 0x140a52ef0 / dtor 0x1405a89e0, same functions as
// effectquery.h's Unk_EffectQuery whose placeholder layout is only 0x10 bytes).
class Unk_PCBaseFxQuery
{
public:
    Unk_PCBaseFxQuery();                                            // 0x140a52ef0
    ~Unk_PCBaseFxQuery();                                           // 0x1405a89e0
    void FUN_140a53190(int nObject);

    CString m_strName;                                              // +0x00
    int m_nPlayer;                                                  // +0x08 = 9
    int m_n0c;
    void* m_p10;                                                    // +0x10 node pointer (0x14097eba0)
    void* m_p18;
    void* m_p20;
    void* m_p28;
    bool m_b30;
    bool m_b31;
    bool m_b32;
    bool m_bEmotion;                                                // +0x33
    bool m_b34;                                                     // = 1
    void* m_p38;
    void* m_p40;                                                    // (0x140a53660)
    int m_n48;                                                      // = 6
    int m_n4c;
    int m_n50;
    int m_n54;
    void* m_p58;
    int m_n60;
    void* m_p68;
};
MS2_CHECK_SIZE(Unk_PCBaseFxQuery, 0x70);
MS2_CHECK_OFFSET(Unk_PCBaseFxQuery, m_bEmotion, 0x33);

class Unk_PCBaseFxMgr
{
public:
    int FUN_1411a49c0(Unk_PCBaseFxQuery* pQuery);                   // spawn, returns the handle
    void FUN_1411a4a00(Unk_PCBaseFxQuery* pQuery);                  // play once
    void FUN_1411a6060(int nHandle);                                // stop
};
Unk_PCBaseFxMgr* FUN_1403ed280();

// The hit record (?\skillrecord.cpp, ctor 0x14175a4e0); only the members used here.
class Unk_PCBaseSkillFlag
{
public:
    int FUN_1407e0f40();
    int FUN_1407e0f90(int nMapId);                                  // the knock-back kind on that map (0 none)
};
class Unk_PCBaseSkillLevel                                          // skill level row (FUN_140803f60)
{
public:
    char m_pad_00[0x168];
    Unk_PCBaseSkillFlag m_168;                                      // +0x168 nonzero: shows damage numbers
    char m_pad_169[0x1cc - 0x169];
    float m_fPushDistance;                                          // +0x1cc
    float m_fPush1d0;                                               // +0x1d0
    char m_pad_1d4[4];
    int m_nPushCurve;                                               // +0x1d8
    char m_pad_1dc[4];
    float m_fPush1e0;                                               // +0x1e0
    char m_pad_1e4[4];
    int m_nPush1e8;                                                 // +0x1e8
    int m_nPushPriority;                                            // +0x1ec
};
MS2_CHECK_OFFSET(Unk_PCBaseSkillLevel, m_nPushPriority, 0x1ec);
class Unk_PCBaseSkillData { public: int FUN_1407e9a60(); };         // the skill's kind (0x12: shows the miss effect)
class CDamageRecord : public CPtred
{
public:
    Unk_PCBaseSkillData* FUN_14175a820();
    Unk_PCBaseSkillLevel* FUN_14175a8b0();
    void* FUN_14175ac30();                                          // the tick's damage
    char m_pad_18[0x2c - 0x18];
    int m_n2c;                                                      // +0x2c the attacker's object id
    char m_pad_30[0x60 - 0x30];
    efd::Point3 m_kOrigin;                                          // +0x60 the skill's origin
    efd::Point3 m_kPushDir;                                         // +0x6c the knock-back direction
    efd::Point3 m_kPos;                                             // +0x78
    efd::Point3 m_kFacing;                                          // +0x84 the attack direction
    CAtlArray<int> m_arrTypes;                                      // +0x90 per hit: damage kind (2 = miss)
    CAtlArray<__int64> m_arrDamage;                                 // +0xb0 per hit: amount
};
MS2_CHECK_OFFSET(CDamageRecord, m_arrDamage, 0xb0);
MS2_CHECK_SIZE(CDamageRecord, 0xd0);
// The DoT / splash damage records (scenestategame.cpp holds other views of them); only the members used here.
class CDotDamageRecord : public CDamageRecord
{
public:
    virtual ~CDotDamageRecord();                                    // 0x14175b590
    int FUN_14175b130();                                            // the tick's damage kind
    char m_pad_d0[0xe0 - 0xd0];
};
MS2_CHECK_SIZE(CDotDamageRecord, 0xe0);
class CSplashDamageRecord : public CDamageRecord
{
public:
    virtual ~CSplashDamageRecord();                                 // 0x14175b5f0
    char m_pad_d0[0xd8 - 0xd0];
};
MS2_CHECK_SIZE(CSplashDamageRecord, 0xd8);
class Unk_PCBaseConstStr { public: CString& FUN_140298f80(); };
class Unk_PCBaseConstants
{
public:
    char m_pad_00[0x8350];
    Unk_PCBaseConstStr m_8350;                                      // +0x8350 the miss effect name
};
Unk_PCBaseConstants* FUN_1401d3200();

// A moving field object (platform; scenestategame.cpp/state.cpp); held by MS2Ptr, so a CPtred.
class Unk_RideeFieldObj : public CPtred
{
public:
    efd::Point3 FUN_140ae0150();                                    // ground normal
    void FUN_140ae0190();                                           // advance to the current time
    efd::Point3 FUN_140adf8e0();                                    // +0x148 position
    efd::Point3 FUN_140ae0660();                                    // +0x154 offset
};
template <> MS2Ptr<Unk_RideeFieldObj>::~MS2Ptr();
template <> Unk_RideeFieldObj* MS2Ptr<Unk_RideeFieldObj>::get() const;
template <> Unk_RideeFieldObj* MS2Ptr<Unk_RideeFieldObj>::operator->() const;
class Unk_PCBaseWorld
{
public:
    int FUN_141bd1a10(PCBase* pActor);
    class Unk_PCBaseWorldActor* FUN_141bd13a0(int nId);
    PCBase* FUN_141bd0cc0();                                        // the local player
    class Unk_PCBaseWorldObj* FUN_141bd1200(int nId);
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                          // the current field data
    bool FUN_141bd7230(const NiPoint3& kPos);
    int FUN_141bdb660(int n);
    MS2Ptr<Unk_RideeFieldObj> FUN_141bc4f10(egf::Entity* pEntity);  // the field object of an entity
    int FUN_141bbb1e0(GameObject* pObj, int bFullInit, int nCamera); // register a created object
    void FUN_141bbb7f0(GameObject* pObj, int n);                    // unregister an object
    GameObject* FUN_141bd0fa0(egf::EntityID kId);                   // the object of an entity
    int FUN_141bd3060();                                            // the current map id
    bool FUN_141bc8420(PCBase* pActor, float fTime, int* pNoVelocity, efd::Point3* pPush); // pending push of an actor
    int FUN_141bc9a80();
    int FUN_141bd36f0(efd::Point3 kPos, efd::Point3* pNormal);     // 0: blocked, *pNormal = the wall normal
};
Unk_PCBaseWorld* FUN_1403ed2d0();
// The skill request a CSkillRecord is built from (same view as avatarpc.cpp / uimessagebox.cpp).
struct Unk_InventorySkillRequest
{
    Unk_InventorySkillRequest(int, unsigned short);                 // 0x141763fa0
    int skill;
    unsigned short level;
    unsigned __int64 tick;
    unsigned serial, unknown14;
    efd::Point3 origin;                                             // +0x18
    efd::Point3 direction;                                          // +0x24
    float fValue;                                                   // +0x30 (the pc's speed scale)
    unsigned unknown34;
    bool remap, suppressDispatch, itemUse;
    __int64 item;
};
MS2_CHECK_SIZE(Unk_InventorySkillRequest, 0x48);
// The skill's table row (MS2Ptr at CSkillRecord +0x30); only the members used here.
class Unk_PCBaseSkillRow
{
public:
    char m_pad_00[0x34];
    bool m_b34;                                                     // +0x34 keeps the running skill's aim
    char m_pad_35[0x74 - 0x35];
    int m_n74;                                                      // +0x74 nonzero: vfunc_101 auto-targets the cast
    int m_n78;                                                      // +0x78 the target pick (0/3 cone by angle, 1/2 by distance)
    char m_pad_7c[0x88 - 0x7c];
    int m_n88;                                                      // +0x88 the aim mode (0, or 2 with option 0xca)
    char m_pad_8c[0x160 - 0x8c];
    float m_f160;                                                   // +0x160 the target cone angle
    float m_f164;                                                   // +0x164 the detect radius (0: from the level row)
    float m_f168;                                                   // +0x168 the detect height (0: 150)
    int m_n16c;                                                     // +0x16c nonzero: store the target distance
};
// The skill's level data (MS2Ptr at CSkillRecord +0x40).
class Unk_PCBaseSkillObj { public: float FUN_1408042a0(int nLevel, int nIndex); };   // the detect radius
// The skill's cast shape (FUN_14175a000).
class Unk_PCBaseSkillCast
{
public:
    char m_pad_00[0xb4];
    efd::Point3 m_kOffset;                                          // +0xb4 the detect centre, in the caster's frame
    float m_fRaise;                                                 // +0xc0
    char m_pad_c4[0xcc - 0xc4];
    int m_nTargetKind;                                              // +0xcc
};
class CSkillRecord : public CPtred                                  // RTTI, 0x1c0 (?\skillrecord.cpp)
{
public:
    CSkillRecord();                                                 // 0x141759260
    bool FUN_1417595d0(Unk_InventorySkillRequest& kReq);
    int FUN_141759960();                                            // the skill id
    int FUN_141759f70();                                            // nonzero: the cast shape has no offset
    Unk_PCBaseSkillCast* FUN_14175a000();
    char m_pad_18[0x30 - 0x18];
    MS2Ptr<Unk_PCBaseSkillRow> m_sp30;                              // +0x30
    MS2Ptr<Unk_PCBaseSkillObj> m_sp40;                              // +0x40
    efd::Point3 m_k50;                                              // +0x50 the caster's position
    efd::Point3 m_k5c;                                              // +0x5c the target position
    efd::Point3 m_k68;                                              // +0x68 the direction
    float m_f74;                                                    // +0x74 the target distance
    char m_pad_78[0x8c - 0x78];
    int m_n8c;                                                      // +0x8c the skill level
    char m_pad_90[4];
    int m_n94;                                                      // +0x94
    char m_pad_98[0x1c0 - 0x98];
};
MS2_CHECK_OFFSET(CSkillRecord, m_k68, 0x68);
// The skill state (State subclass while the state manager is in state 0x10).
class Unk_PCBaseSkillState : public State
{
public:
    MS2Ptr<CSkillRecord> FUN_1417ed6f0();                           // the record being cast
};
// The detect query of a collision shape (?\basecollision.cpp; 0x90, ctor 0x1409fbb80).
class CDetectContext : public CPtred
{
public:
    CDetectContext();
    virtual ~CDetectContext();
    GameObject* m_pOwner;                                           // +0x18
    void* m_p20;                                                    // +0x20
    efd::Point3 m_kPos;                                             // +0x28
    char m_pad_34[0x50 - 0x34];
    CAtlArray<efd::SmartPointer<GameObject> > m_arrTargets;         // +0x50 the hits
    int m_nTargetKind;                                              // +0x70
    int m_n74;                                                      // +0x74
    char m_pad_78[4];
    int m_n7c;                                                      // +0x7c
    char m_pad_80[0x90 - 0x80];
};
MS2_CHECK_OFFSET(CDetectContext, m_arrTargets, 0x50);
MS2_CHECK_SIZE(CDetectContext, 0x90);
// The cylinder shape (unit_141083230); only the members used here.
class CCylinderCollision : public CBaseCollision
{
public:
    CCylinderCollision();                                           // 0x141083230
    virtual ~CCylinderCollision();                                  // 0x141083320
    // 0x1410833c0, the slot 3 override (declared with Unk_StreamPoint by its owner; only called directly here)
    void vfunc_3(NiPoint3 kPos, NiPoint3 kDir, float fScale);
    virtual void vfunc_5();
    virtual float vfunc_6();
    void FUN_1409fc390(MS2Ptr<CDetectContext> spCtx, const NiPoint3& kDir);   // CBaseCollision: collect the objects inside
    char m_pad_78[0xb0 - 0x78];
    float m_fRadius;                                                // +0xb0
    Unk_StreamPoint m_ptCenter;                                     // +0xb4
    float m_fHeight;                                                // +0xc0
    char m_pad_c4[4];
};
MS2_CHECK_OFFSET(CCylinderCollision, m_fHeight, 0xc0);
MS2_CHECK_SIZE(CCylinderCollision, 0xc8);
// The position the actor is heading to (the tracker at +0x6d8, FUN_14166d240).
class Unk_PCBaseMoveTarget { public: efd::Point3 FUN_141683900(); };
class Unk_PCBaseOptions;
Unk_PCBaseOptions* FUN_140166410();
bool FUN_14036d570(Unk_PCBaseOptions* pOptions, int nId);
MS2_CHECK_SIZE(CSkillRecord, 0x1c0);
CStringW FUN_1409eec40(int nId);                                    // system string by id
void FUN_1412751f0(const CStringW& strMsg, int a, int b);           // notice
void FUN_141276180(const CString& strSound, const CString& strArg); // play a ui sound
extern CString DAT_143ae32c8;                                       // the "denied" ui sound name

class Unk_PCBaseLog
{
public:
    void FUN_14054c030(int nLevel, int nLine, const wchar_t* szFormat, const CString& str0, const CString& str1);
};
Unk_PCBaseLog* FUN_140166440();
class Unk_PCBaseClock;
Unk_PCBaseClock* FUN_14086d260();                                   // the game clock
double FUN_141473280(Unk_PCBaseClock* pClock);                      // seconds

// The house privileges of the local player (MyPC +0x1628; commonfiles\homeprivilege.cpp); completes mypc.h's MS2Ptr.
class CHomePrivilege : public CPtred
{
public:
    MyPC* m_pOwner;                                                 // +0x18
};
Ridee* FUN_141468360(PCBase* pEntity);                              // the mount an actor rides (entity property 0x6200045)

// The action container at +0xd00 (?\actioncontainer.cpp).
class Unk_PCBaseActions : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(int n);
    virtual CString vfunc_5(int n);
    virtual CString vfunc_6(int a, int b);
    virtual std::vector<CString>* vfunc_7(int nKey);                // sequence names
};
// The action containers (0x1414a5860).
class Unk_PCBaseActionsMgr
{
public:
    MS2Ptr<Unk_PCBaseActions> FUN_1409494e0(int nId);
};
Unk_PCBaseActionsMgr* FUN_1414a5860();

// The world object found by id (FUN_141676a10).
class Unk_PCBaseWorldObj : public GameObject
{
public:
    void* FUN_1409ffc60();
};

// The actor found by id (vfunc_111).
class Unk_PCBaseWorldActor
{
public:
    unsigned int FUN_141094f40();                                   // the owner's id
};

// The damage UIs (vfunc_111/112).
class Unk_PCBaseDamageUI
{
public:
    void FUN_141911e90(PCBase* pActor, __int64 nValue, int nType, int nTargetId, void* pPos);
};
Unk_PCBaseDamageUI* FUN_140b624b0(int nId);
// The DPS meter (RTTI UIDPSDialog, UI id 0x4e44).
class UIDPSDialog : public UIDialog
{
public:
    int FUN_1419299e0();                                            // open
    void FUN_141929a00(__int64 nValue, int nType);                  // add a hit
};
class Unk_PCBaseUIMgr
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                        // CUIService: object by UI class id
};
Unk_PCBaseUIMgr* FUN_1403ed2b0();

// A dialog by UI id (0x14167a900 for UIDPSDialog).
template <class T> T* PCBaseDialog(int nId)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}
class Unk_PCBaseTargetUI
{
public:
    void FUN_1419df2a0(PCBase* pActor);
};
Unk_PCBaseTargetUI* FUN_141531aa0(int nId);
class Unk_PCBaseUpperHpBar
{
public:
    void FUN_141b4c510(PCBase* pActor, int nId);                    // UIUpperHpBar
};
Unk_PCBaseUpperHpBar* FUN_14096e340(int nId);

// The sound manager (footsteps).
class Unk_PCBaseSound
{
public:
    void FUN_141377420(PCBase* pOwner, CString strKey);
};
Unk_PCBaseSound* FUN_141475cf0();

// The animation service (model cache).
class Unk_PCBaseAnimSvc
{
public:
    efd::utf8string FUN_140b7cc50(const egf::EntityID& kId);         // current animation name
    unsigned int FUN_140999490(const egf::EntityID& kId, const efd::utf8string& strName);   // GetAnimationIdFromName
    NiActorManager* FUN_140999440(const egf::EntityID& kId);        // GetActorManager
};
Unk_PCBaseAnimSvc* FUN_141b6f910();

// Free helpers of other units.
CString FUN_1409a2360(const char* psz, int n);                      // text conversion
void FUN_140ae1240(void* pEntity, unsigned uHash, const efd::utf8string& str);   // set an entity string property
NiAVObject* FUN_141b6efc0(void* pEntity);
CString FUN_140188f50(const char* psz, int nCodePage);              // multibyte copy (0 = default code page)
void FUN_141567330(NiAVObject* pNode, bool bShadow);
const char* FUN_142087e50(const NiFixedString& kFixed);            // NiFixedString -> c string
int FUN_1409a1a00(NiActorManager* pkManager);                       // the current sequence id
void FUN_140291b70(float* pfAngle);                                 // wrap degrees into [0, 360)
void FUN_140291bc0(efd::Point3* pkAngles);
void FUN_1419929f0(int nActorId);                                   // hp bar
void FUN_140e863f0(int nActorId);                                   // shield bar
void FUN_141a60ec0(int nActorId);                                   // name tag
void FUN_141a60f00(int nActorId);                                   // name tag text
void FUN_14192fdc0(int nActorId);                                   // emoticon
void FUN_14128eff0(int nActorId);
void FUN_1418fbe30(int nActorId);                                   // chat balloon
void FUN_141a8fbd0(int nActorId);                                   // profile image
void FUN_140ba8d70(int nActorId);                                   // banner

// ---- class info and statics ----

EE_IMPLEMENT_CONCRETE_CLASS_INFO(PCBase);

static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
// The NIF resource loader (FUN_140a0afd0; cubecraft_1.cpp's Unk_CubeResourceService).
class Unk_PCBaseResourceSvc
{
public:
    efd::SmartPointer<NiAVObject> FUN_141551ea0(CString strPath, int nA, int nFlags, int nB, int nC);
};
Unk_PCBaseResourceSvc* FUN_140a0afd0();
CString FUN_140cc2a00(const CString& strRoot, const CString& strFile);   // path join
void FUN_1410b2450(NiAVObject* pObj, float fScale);                   // uniform scale
void FUN_141b70cb0(NiRenderObject* pObj, float fWidth, const NiColor& kColor, float fAlpha);   // outline tint
// Depth-first walker over a scene graph (0x38; util.cpp).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);                              // 0x14098cb80
    ~Unk_SceneWalker();                                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);
extern NiFixedString DAT_143ae5470[9][30];
float FUN_14059d930(float f);                                       // fabs
class Unk_PCBaseCameraMgr
{
public:
    int FUN_140af0210();                                            // the guide (top-down) camera is on
    void FUN_140aeaf40(PCBase* pTarget, int n);                     // set the camera target
    int FUN_140af7e30();                                            // the camera mode
    efd::Point3 FUN_140af8290();                                    // the aim direction (mode 10)
    int FUN_140aed3a0();
    bool FUN_140aed3e0();
    GameObject* FUN_140a38d60();                                    // the camera target
};
Unk_PCBaseCameraMgr* FUN_1409478c0();
// The pvp/guild config (uipvpguildteamdialog.cpp); +0x2b0 is the ride-on effect name.
struct Unk_PgtConfig
{
    char m_pad_00[0x2b0];
    CString m_str2b0;
    CString m_str2b8;                                               // the ride-off effect name
};
Unk_PgtConfig* FUN_1401d31f0();
PC* FUN_140974230(PCBase* pActor);                                  // efd::DynamicCast<PC>
NiAVObject* FUN_141b6ef70(egf::EntityID kId);                       // the scene node of an entity
void FUN_140b86230(const NiPoint3& kDir, NiMatrix3& kRot);          // facing angles -> rotation
extern NiFixedString DAT_143ae5ce0[50];                             // "Hold_PointNN" dummy names (unit_1416bc380)
PCBase* FUN_1409ffd30(GameObject* pObj);                            // efd::DynamicCast<PCBase> (class id 0x06200013)
bool FUN_14028d470(float fA, float fB);                             // float equality
float FUN_140966f00(NiPoint3 kA, NiPoint3 kB);                      // distance
float FUN_14028d3a0(float fValue);                                  // (commonutil.cpp)
float FUN_140a0fde0(float fValue, float fMax);                      // min(value, max)
void FUN_140a01250(efd::Point3 kDir, efd::Point3* pForward, efd::Point3* pRight);
bool FUN_140a33ff0(const efd::Point3& kPt);                         // a usable (non-sentinel) point
float FUN_141224f30(float fX, float fY);                            // atan2-style heading                         // "<part>NN" dummy names (unit_1416bc380)
static CString s_partNames[] = {"Head", "Body", "Back", "RHand", "LHand", "RFoot", "LFoot", "Tail", "Hold_Point"};
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);
static CString s_strNotice("system_notice_error_warningNotThisPlace");

// ---- PCBase ----

// MS2-FUNCTIONAL 0x14166a650: m_pos920/m_posBF4(NiPoint3::ZERO) go through NiPoint3(const efd::Point3&) 0x14027dcf0
//   (ZERO is efd::Point3's) where the exe copies a NiPoint3-typed zero trivially (rep movsb, rdi/rsi saved), and the comp
//   MS2Ptr instantiations are the UI entity types (UIHpBar::Entity ...), not the Unk_PCBaseComp_ stand-ins. The ctor is
//   pinned (the line table starts at the brace, below the initializer list).
PCBase::PCBase()
    : m_unk_150(0), m_unk_158(0), m_unk_15c(0), m_unk_160(0), m_unk_1bc(0), m_unk_620(25.0f, 105.0f),
      m_unk_748(this), m_unk_8e8(10), m_pos920(NiPoint3::ZERO), m_f92c(1.0f), m_f930(1.0f), m_f934(0.0f),
      m_f938(1.0f), m_str940(""), m_str948(""), m_str958(""), m_str960(""), m_unk_968(0), m_unk_9a8(0),
      m_pos9ac(efd::Point3::ZERO), m_unk_9c4(0), m_f9c8(0.0f), m_b9d0(true), m_b9d1(true), m_unk_a50(1), m_spA58(0),
      m_spA78(0), m_spA88(0), m_spA98(0), m_spAA8(0), m_spAB8(0), m_unk_ad8(0), m_unk_af4(0x7fffffff), m_unk_af8(0),
      m_spB00(0), m_spB10(0), m_spB18(0), m_mapB28(17, .75f, .25f, 2.25f, 10), m_unk_b70(0), m_nUidB78(0),
      m_unk_b80(0), m_unk_b88(10), m_unk_bb8(10), m_spBE8(0), m_fBF0(0.0f), m_posBF4(NiPoint3::ZERO), m_unk_c00(0),
      m_unk_c04(1), m_unk_c0c(0), m_posC10(efd::Point3::ZERO), m_spC38(0), m_spC40(0), m_unk_c48(5), m_unk_c50(0),
      m_unk_c60(0), m_unk_c64(0), m_unk_c68(0), m_mapCA8(17, .75f, .25f, 2.25f, 10), m_unk_d20(0)
{
    m_str88 = "GameObject";
    m_str9d8 = "default";
    for (int i = 0; i < 3; i++)
        memset(m_unk_1c0[i], 0, sizeof(m_unk_1c0[i]));
    memset(m_unk_508, 0, sizeof(m_unk_508));
    m_unk_1a0.m_a = 50.0f;
    m_unk_180.m_x = 1800.0f;
    m_unk_190.m_x = 1800.0f;
    m_f9cc = 0.0f;
    m_unk_ae0 = egf::kENTITY_INVALID;
    m_posAE8 = NiPoint3::ZERO;
    m_timerC70.FUN_140868750(1000);
    m_spBE8 = 0;
    m_mapB28.RemoveAll();
}

// @0x14166af20
PCBase::~PCBase()
{
    FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(m_unk_ad8));
    m_spA58 = 0;
    m_spA68 = 0;
    m_spA78 = 0;
    m_spA88 = 0;
    m_spA98 = 0;
    m_spAA8 = 0;
    m_spAB8 = 0;
    m_spAC8 = 0;
    m_spStateMgr = 0;
    m_unk_ad8 = 0;
    m_spB18 = 0;
    if (m_unk_150) {
        delete m_unk_150;
        m_unk_150 = 0;
    }
    FUN_141679e00();
    FUN_141679e90();
}

// @0x14166b470
// MS2-FUNCTIONAL: the exe keeps two extra pointer temporaries around the utf8string argument (frame 0x88).
void PCBase::vfunc_9(void* p)
{
    GameObject::vfunc_9(p);
    CString strIdle = FUN_1409a2360("Idle_A", 0);
    FUN_140ae1240(p, 0x3ff293c8, (const char*)strIdle);
}
MS2_REPLACE_METHOD(0x14166b470, PCBase, vfunc_9, 203, 0x4ACEA6A0);

// @0x14166b810
void PCBase::vfunc_12()
{
    GameObject::vfunc_12();
    NiAVObject* pNode = FUN_141b6efc0(FUN_14123c410());
    if (pNode)
        FUN_141567330(pNode, true);
    vfunc_119();
    FUN_141675980();
}
MS2_REPLACE_METHOD(0x14166b810, PCBase, vfunc_12, 96, 0x7E2C6D08);

// @0x14166b880
void PCBase::vfunc_14()
{
    m_spC38 = 0;
    if (FUN_1416764a0())
        vfunc_121(MS2Ptr<RideOffAction>(0));
    if (m_spStateMgr.get() ? true : false) {
        if (m_spStateMgr->GetState())
            m_spStateMgr->GetState()->vfunc_5(0);
    }
    m_unk_b88.RemoveAll();
    GameObject::vfunc_14();
}
MS2_REPLACE_METHOD(0x14166b880, PCBase, vfunc_14, 257, 0x75887CFA);

// @0x14166b990
void PCBase::vfunc_15()
{
    GameObject::vfunc_15();
    m_unk_748.FUN_140970490();
    vfunc_16();
}
MS2_REPLACE_METHOD(0x14166b990, PCBase, vfunc_15, 62, 0xB1BD862D);

// @0x14166b9e0
void PCBase::vfunc_16()
{
    m_spA58 = 0;
    m_spA68 = 0;
    m_spA78 = 0;
    m_spA88 = 0;
    m_spA98 = 0;
    m_spAA8 = 0;
    m_spAB8 = 0;
    m_spAC8 = 0;
    FUN_1419929f0(m_unk_70);
    FUN_140e863f0(m_unk_70);
    FUN_141a60ec0(m_unk_70);
    FUN_14192fdc0(m_unk_70);
    FUN_14128eff0(m_unk_70);
    FUN_1418fbe30(m_unk_70);
    FUN_141a8fbd0(m_unk_70);
    FUN_140ba8d70(m_unk_70);
}
MS2_REPLACE_METHOD(0x14166b9e0, PCBase, vfunc_16, 286, 0x096137A0);

// @0x14166bb10
void PCBase::vfunc_19(efd::Point3 kPos)
{
    GameObject::vfunc_19(kPos);
    FUN_14166d260();
}
MS2_REPLACE_METHOD(0x14166bb10, PCBase, vfunc_19, 68, 0x8E98DEA5);

// @0x14166b550
int PCBase::vfunc_10()
{
    GameObject::vfunc_10();
    FUN_14166d8b0(vfunc_20().z);
    FUN_141671960(m_unk_180.m_z);
    m_unk_150 = new Unk_PCBaseBody();
    m_unk_150->FUN_14123f5b0(this, m_unk_80, static_cast<const efd::Point3&>(vfunc_18()), m_unk_620.y, m_unk_620.x);
    FUN_14166d260();
    m_unk_150->FUN_14123fd30(0x389);
    vfunc_109(1);
    m_spD10 = vfunc_70()->FUN_1411bde10(vfunc_69());
    FUN_141679760();
    vfunc_120(FUN_141676370());
    FUN_1416795e0();
    FUN_14166cb30();
    m_unk_c0c = 0;
    return 1;
}
MS2_REPLACE_METHOD(0x14166b550, PCBase, vfunc_10, 696, 0x7DE0F435);

// @0x14166bb60
void PCBase::vfunc_21(efd::Point3 kDir)
{
    float fZ = 0;
    if (FUN_1416749a0()->FUN_140970eb0(fZ))
        kDir.z = fZ;
    GameObject::vfunc_21(kDir);
}
MS2_REPLACE_METHOD(0x14166bb60, PCBase, vfunc_21, 110, 0xD1F026CA);

// @0x14166bbe0
NiPoint3 PCBase::vfunc_18()
{
    if (FUN_1416764d0())
        return FUN_1416764a0()->vfunc_18();
    return GameObject::vfunc_18();
}
MS2_REPLACE_METHOD(0x14166bbe0, PCBase, vfunc_18, 99, 0x024B508D);

// @0x14166bc50
NiPoint3 PCBase::vfunc_20()
{
    if (FUN_1416764d0())
        return FUN_1416764a0()->vfunc_20();
    return GameObject::vfunc_20();
}
MS2_REPLACE_METHOD(0x14166bc50, PCBase, vfunc_20, 99, 0xA554E806);

// @0x14166bcc0
// MS2-FUNCTIONAL: the exe returns the efd::Point3 local with a plain 12-byte copy (its return type is efd::Point3); the
// NiPoint3 return of the GameObject slot converts through NiPoint3(const efd::Point3&).
NiPoint3 PCBase::vfunc_37()
{
    efd::Point3 kOffset(0, 0, 0);
    vfunc_51(&kOffset);
    if (Unk_GoAttachment* pAttach = vfunc_26())
        kOffset.z += pAttach->vfunc_6() * 0.5f;
    return kOffset;
}
MS2_REPLACE_METHOD(0x14166bcc0, PCBase, vfunc_37, 166, 0x76F42DDD);

// @0x14166bd70
Unk_GoAttachment* PCBase::vfunc_26()
{
    if (FUN_1416764d0())
        return FUN_1416764a0()->vfunc_26();
    return FUN_140a006f0(&m_sp628);
}
MS2_REPLACE_METHOD(0x14166bd70, PCBase, vfunc_26, 83, 0x28C24E0F);

// @0x14166bdd0
// MS2-FUNCTIONAL: the exe materialises the distance test as an int temporary before narrowing it to the bool argument.
void PCBase::vfunc_32(bool b)
{
    if (m_spShadow) {
        m_spShadow->FUN_14160fe50(FUN_140f4a450() < 200000.0f);
        m_spShadow->FUN_14160feb0(m_unk_9a8, m_pos9ac, m_pos9b8, m_f9c8, b);
    }
}
MS2_REPLACE_METHOD(0x14166bdd0, PCBase, vfunc_32, 233, 0x2951F41F);

// @0x14166bec0
void PCBase::AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    m_spStateMgr->FUN_1417dbef0(pkManager, eSequenceID, pkSeq, fEventTime);
    if (m_unk_d20 != eSequenceID)
        FUN_141679e90();
}

// @0x14166bf40
// MS2-FUNCTIONAL: same calls and branches; the exe frame is 0x20 smaller (temporaries shared between the branches).
void PCBase::TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (strncmp(FUN_142087e50(kTextKey), "run", 3) == 0) {
        if (FUN_14166c930() != 0 && GetClassID() != 0x6200028)
            FUN_141475cf0()->FUN_141377420(this, CString(FUN_142087e50(kTextKey)));
    }
    else if (strncmp(FUN_142087e50(kTextKey), "walk", 4) == 0) {
        if (FUN_14166c930() != 0 && GetClassID() != 0x6200028)
            FUN_141475cf0()->FUN_141377420(this, CString(FUN_142087e50(kTextKey)));
    }
    else if (strncmp(FUN_142087e50(kTextKey), "effect_", 7) == 0) {
        CString strName(FUN_142087e50(kTextKey) + 7);
        Unk_PCBaseFxQuery kQuery;
        kQuery.m_strName = strName;
        kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
        kQuery.FUN_140a53190(FUN_14123c580());
        kQuery.m_bEmotion = FUN_14166c930() == 0x35;
        FUN_1403ed280()->FUN_1411a4a00(&kQuery);
    }
    else if (strncmp(FUN_142087e50(kTextKey), "ani_eff_", 8) == 0) {
        CString strName(FUN_142087e50(kTextKey) + 8);
        Unk_PCBaseFxQuery kQuery;
        kQuery.m_strName = strName;
        kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
        kQuery.FUN_140a53190(FUN_14123c580());
        kQuery.m_bEmotion = FUN_14166c930() == 0x35;
        unsigned int nHandle = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
        if (nHandle != 0) {
            m_unk_d20 = eSequenceID;
            m_vecD28.push_back(nHandle);
        }
    }
    if (eSequenceID == FUN_1409a1a00(pkManager) && m_b9d1 && kTextKey.GetLength() > 4) {
        if (strncmp(FUN_142087e50(kTextKey), "emo_", 4) == 0) {
            int nState = FUN_14166c930();
            FUN_14166ef10(CString(FUN_142087e50(kTextKey) + 4), true, 0, nState == 0x35);
        }
    }
    m_spStateMgr->FUN_1417dbf50(pkManager, eSequenceID, kTextKey, pkMatchObject, pkSeq, fEventTime);
}

// @0x14166c550
void PCBase::EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    m_spStateMgr->FUN_1417dbfc0(pkManager, eSequenceID, pkSeq, fEventTime);
}

// @0x14166c5b0
void PCBase::vfunc_23(int n)
{
    GameObject::vfunc_23(n);
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee != 0)
        spRidee->vfunc_23(n);
}
MS2_REPLACE_METHOD(0x14166c5b0, PCBase, vfunc_23, 133, 0x138B180B);

// @0x14166c640
void PCBase::vfunc_52(double fTime)
{
    if (GetClassID() != 0x6200016)
        FUN_14123c330(m_unk_748.FUN_1409705d0());
    float fScale = FUN_14123c260() / GetScaleAC();
    if (fScale != m_fScaleA8) {
        BOOL bDown = m_fScaleA8 - fScale > 0.0f ? FALSE : TRUE;
        float fStep = 3.0f * (float)fTime;
        if (bDown)
            fStep = -fStep;
        fScale += fStep;
        if (bDown) {
            if (fScale < m_fScaleA8)
                fScale = m_fScaleA8;
        }
        else if (fScale > m_fScaleA8) {
            fScale = m_fScaleA8;
        }
        FUN_14123c280(fScale * GetScaleAC());
    }
}
MS2_REPLACE_METHOD(0x14166c640, PCBase, vfunc_52, 392, 0xFE6B5ABE);

// @0x14166c7d0
int PCBase::vfunc_57()
{
    return 0;
}

// @0x14166c7e0
int PCBase::vfunc_58()
{
    return 3;
}

// @0x14166c800
void PCBase::vfunc_59(int nState, StateData* pData, int nSub, int bForce)
{
    if (m_unk_b4 == 0) {
        m_unk_c48 = nState;
        m_unk_c50.AssignRaw(pData);
        m_unk_c60 = nSub;
        m_unk_c64 = bForce;
    }
    else {
        if (m_spStateMgr->GetCur() == 0x21 && m_spB10 != 0) {
            m_spB10->vfunc_59(nState, pData, nSub, bForce);
            return;
        }
        m_spStateMgr->FUN_1417dafa0(nState, pData, nSub, bForce);
    }
}
MS2_REPLACE_METHOD(0x14166c800, PCBase, vfunc_59, 292, 0xAA88E2C6);

// @0x14166c930
int PCBase::FUN_14166c930()
{
    return m_spStateMgr->GetCur();
}
MS2_REPLACE_METHOD(0x14166c930, PCBase, FUN_14166c930, 41, 0xB1D51893);

// @0x14166c960
int PCBase::FUN_14166c960()
{
    return m_unk_c48;
}

// @0x14166c980
int PCBase::FUN_14166c980()
{
    return m_spStateMgr->GetPrev();
}
MS2_REPLACE_METHOD(0x14166c980, PCBase, FUN_14166c980, 41, 0x7E67C403);

// @0x14166c9b0
CString PCBase::vfunc_60()
{
    return "";
}

// @0x14166ca00
int PCBase::vfunc_61()
{
    return 0;
}

// @0x14166ca10
bool PCBase::vfunc_62()
{
    return false;
}

// @0x14166ca20
void PCBase::FUN_14166ca20(unsigned int nReason)
{
    if (FUN_14166cb00(nReason) == true)
        return;
    m_unk_c08.FUN_140d75120(nReason, true);
    FUN_14166cb30();
}
MS2_REPLACE_METHOD(0x14166ca20, PCBase, FUN_14166ca20, 78, 0x7DD9BEF0);

// @0x14166ca80
void PCBase::FUN_14166ca80(unsigned int nReason)
{
    if (!FUN_14166cb00(nReason))
        return;
    m_unk_c08.Reset(nReason);
    FUN_14166cb30();
}
MS2_REPLACE_METHOD(0x14166ca80, PCBase, FUN_14166ca80, 74, 0x9A398081);

// @0x14166cad0
bool PCBase::FUN_14166cad0()
{
    return m_unk_c08.Any();
}

// @0x14166cb00
bool PCBase::FUN_14166cb00(unsigned int nReason)
{
    return m_unk_c08.FUN_140d75240(nReason);
}
MS2_REPLACE_METHOD(0x14166cb00, PCBase, FUN_14166cb00, 41, 0x8EEE3358);

// @0x14166cb30
void PCBase::FUN_14166cb30()
{
    if (FUN_14166cad0()) {
        vfunc_23(1);
        FUN_14123cb20(false);
        efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
        if (spRidee != 0) {
            if (m_unk_c08.Count() == 1 && m_unk_c08.FUN_140d75240(2))
                spRidee->vfunc_23(0);
        }
    }
    else {
        vfunc_23(0);
        FUN_14123cb20(true);
    }
}
MS2_REPLACE_METHOD(0x14166cb30, PCBase, FUN_14166cb30, 260, 0x3EF2F43D);

// @0x14166cc40
void PCBase::FUN_14166cc40(int nValue)
{
    m_spStateMgr->FUN_1417db230(nValue);
}
MS2_REPLACE_METHOD(0x14166cc40, PCBase, FUN_14166cc40, 49, 0x3714E64A);

// @0x14166cc80
int PCBase::FUN_14166cc80()
{
    return m_spStateMgr->FUN_1417db290();
}
MS2_REPLACE_METHOD(0x14166cc80, PCBase, FUN_14166cc80, 41, 0x305EC96C);

// @0x14166ccb0
State* PCBase::FUN_14166ccb0()
{
    return m_spStateMgr->GetState();
}
MS2_REPLACE_METHOD(0x14166ccb0, PCBase, FUN_14166ccb0, 41, 0x7B781849);

// @0x14166cce0
void PCBase::FUN_14166cce0(unsigned int nFlags)
{
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee)
        spRidee->FUN_14166cce0(nFlags);
    m_unk_158 |= nFlags;
}
MS2_REPLACE_METHOD(0x14166cce0, PCBase, FUN_14166cce0, 126, 0xFCEF1179);

// @0x14166cd70
void PCBase::FUN_14166cd70(unsigned int nFlags)
{
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee)
        spRidee->FUN_14166cd70(nFlags);
    m_unk_158 &= ~nFlags;
}
MS2_REPLACE_METHOD(0x14166cd70, PCBase, FUN_14166cd70, 130, 0xF904541E);

// @0x14166ce00
int PCBase::vfunc_63()
{
    if (m_unk_158 != 0)
        return 0;
    return 1;
}

// @0x14166ce30
int PCBase::FUN_14166ce30()
{
    return m_unk_15c;
}

// @0x14166ce50
void PCBase::FUN_14166ce50(int n)
{
    m_unk_15c = n;
}

// @0x14166ce70
void PCBase::FUN_14166ce70(int nEmotion)
{
    if (m_unk_160 != nEmotion) {
        m_unk_160 = nEmotion;
        vfunc_66(nEmotion);
    }
}
MS2_REPLACE_METHOD(0x14166ce70, PCBase, FUN_14166ce70, 73, 0xEEB9D1DF);

// @0x14166cec0
int PCBase::vfunc_64()
{
    return 0;
}

// @0x14166ced0
int PCBase::vfunc_65()
{
    return m_unk_160;
}

// @0x14166cef0
void PCBase::vfunc_66(int n)
{
    if (m_spStateMgr.get())
        m_spStateMgr->FUN_1417dc020(n);
}
MS2_REPLACE_METHOD(0x14166cef0, PCBase, vfunc_66, 73, 0x590E688A);

// @0x14166d220
Unk_PCBaseBody* PCBase::FUN_14166d220()
{
    return m_unk_150;
}

// @0x14166d240
void* PCBase::FUN_14166d240()
{
    return &m_unk_6d8;
}

// @0x14166cf40
void PCBase::vfunc_67(efd::Point3* pDir, efd::Point3* pSide)
{
    if (m_unk_c00 == 0xe)
    {
        NiPoint3 kRot = vfunc_20();
        NiMatrix3 kMat;
        kMat.MakeZRotation((kRot.z * 3.1415927f) / 180.0f);
        *pDir = -efd::Point3::UNIT_Y * kMat;
        *pSide = -pDir->UnitCross(efd::Point3::UNIT_Z);
    }
    else
    {
        efd::Point3 kAngles = m_posBF4;
        kAngles = (kAngles * 3.1415927f) / 180.0f;
        efd::Matrix3 kMat;
        kMat.FromEulerAnglesXYZ(kAngles.x, kAngles.y, kAngles.z);
        kMat.GetCol(0, *pDir);
        pDir->z = 0.0f;
        if (FUN_14059d930(pDir->x) < 0.001f)
            pDir->x = 0.0f;
        if (FUN_14059d930(pDir->y) < 0.001f)
            pDir->y = 0.0f;
        pDir->Unitize();
        *pSide = -pDir->Cross(efd::Point3::UNIT_Z);
    }
    if (m_unk_c00 == 0x11 && FUN_1409478c0()->FUN_140af0210() != 0)
    {
        *pSide = NiPoint3(-1.0f, 0.0f, 0.0f);
        *pDir = NiPoint3(0.0f, 1.0f, 0.0f);
    }
}
MS2_REPLACE_METHOD(0x14166cf40, PCBase, vfunc_67, 730, 0x7C8F1331);

// @0x14166d260
void PCBase::FUN_14166d260()
{
    if (Unk_PCBaseBody* pBody = FUN_14166d220())
        pBody->FUN_14123fe70(vfunc_18());
}
MS2_REPLACE_METHOD(0x14166d260, PCBase, FUN_14166d260, 98, 0x6C91CBAE);

// @0x14166d2d0
// MS2-FUNCTIONAL: temporaries of the mount branch are laid out differently (frame 0x70).
void PCBase::FUN_14166d2d0(const efd::Point3& kTarget, int bTurn)
{
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee != 0)
        spRidee->FUN_14166d430(kTarget - spRidee->vfunc_18(), bTurn, 1);
    else
        FUN_14166d430(kTarget - vfunc_18(), bTurn, 1);
}
MS2_REPLACE_METHOD(0x14166d2d0, PCBase, FUN_14166d2d0, 331, 0xBA911878);

// @0x14166d430
void PCBase::FUN_14166d430(efd::Point3 kDir, int bTurn, int bResetTilt)
{
    kDir = -kDir;
    kDir.z = 0;
    kDir.Unitize();
    efd::Point3 kRight = kDir.UnitCross(efd::Point3::UNIT_Z);
    efd::Point3 kUp = kRight.UnitCross(efd::Point3::UNIT_Z);
    NiMatrix3 kRot;
    kRot.SetCol(0, kRight);
    kRot.SetCol(1, kUp);
    kRot.SetCol(2, efd::Point3::UNIT_Z);
    float fX, fY, fZ;
    kRot.ToEulerAnglesXYZ(fX, fY, fZ);
    efd::Point3 kAngles(0, 0, fZ * 180.0f / 3.1415927f);
    FUN_140291b70(&kAngles.z);
    FUN_14166d8b0(kAngles.z);
    if (bResetTilt) {
        efd::Point3 kZero = efd::Point3::ZERO;
        vfunc_22(kZero);
    }
    if (bTurn)
        vfunc_21(kAngles);
}
MS2_REPLACE_METHOD(0x14166d430, PCBase, FUN_14166d430, 493, 0x7EEA4855);

// @0x14166d630
// MS2-FUNCTIONAL: the exe passes the NiPoint3 local to slot 21 with a single 12-byte copy (one temporary less).
void PCBase::FUN_14166d630(float fTime)
{
    NiPoint3 kRot = vfunc_20();
    if (kRot.z == m_f934)
        return;
    FUN_140291b70(&m_f934);
    if (kRot.z < m_f934) {
        if (m_f934 - kRot.z > 180.0f)
            kRot.z -= FUN_14166dab0() * fTime;
        else
            kRot.z += FUN_14166dab0() * fTime;
        if (kRot.z > m_f934)
            kRot.z = m_f934;
    }
    else if (kRot.z > m_f934) {
        if (kRot.z - m_f934 > 180.0f)
            kRot.z += FUN_14166dab0() * fTime;
        else
            kRot.z -= FUN_14166dab0() * fTime;
        if (kRot.z < m_f934)
            kRot.z = m_f934;
    }
    FUN_140291bc0(&kRot);
    vfunc_21(kRot);
}
MS2_REPLACE_METHOD(0x14166d630, PCBase, FUN_14166d630, 480, 0x758C90FC);

// @0x14166d820
void PCBase::FUN_14166d820()
{
    NiPoint3 kLook = FUN_14123c360();
    if (kLook != efd::Point3::ZERO) {
        efd::Point3 kA;
        efd::Point3 kB;
        vfunc_67(&kA, &kB);
        FUN_14166d8b0(FUN_14166dad0(kLook, kB));
    }
}
MS2_REPLACE_METHOD(0x14166d820, PCBase, FUN_14166d820, 135, 0xF230AF85);

// @0x14166d8b0
void PCBase::FUN_14166d8b0(float fAngle)
{
    m_f934 = fAngle;
}

// @0x14166d8e0
// MS2-FUNCTIONAL: the exe copies kTilt into a local before the slot-22 call.
void PCBase::FUN_14166d8e0(efd::Point3 kTilt)
{
    vfunc_22(kTilt);
    FUN_14166d820();
    NiPoint3 kRot = vfunc_20();
    kRot.z = FUN_14166da40();
    FUN_14166d970(kRot);
}
MS2_REPLACE_METHOD(0x14166d8e0, PCBase, FUN_14166d8e0, 132, 0x81D98B51);

// @0x14166d970
void PCBase::FUN_14166d970(efd::Point3 kRot)
{
    FUN_14166d8b0(kRot.z);
    vfunc_21(kRot);
}
MS2_REPLACE_METHOD(0x14166d970, PCBase, FUN_14166d970, 87, 0x4BF2CA41);

// @0x14166d9d0
void PCBase::FUN_14166d9d0(const NiPoint3& kPos)
{
    m_pos920 = kPos;
}
MS2_REPLACE_METHOD(0x14166d9d0, PCBase, FUN_14166d9d0, 43, 0x3F019449);

// @0x14166da10
void PCBase::FUN_14166da10(float fSpeed)
{
    m_unk_190.m_x = fSpeed;
}

// @0x14166da40
float PCBase::FUN_14166da40()
{
    return m_f934;
}

// @0x14166da60
float PCBase::FUN_14166da60()
{
    return m_f930 * ((float)m_unk_1c0[2][0x16] / 100.0f);
}

// @0x14166dab0
float PCBase::FUN_14166dab0()
{
    return m_unk_190.m_x;
}

// @0x14166dad0
// MS2-FUNCTIONAL: the exe spills the second degree term to a temporary before the add.
float PCBase::FUN_14166dad0(const efd::Point3& kLook, const efd::Point3& kDir)
{
    float fA = atan2f(kDir.y, kDir.x);
    float fB = atan2f(kLook.x, kLook.y);
    float fAngle = fA * 180.0f / 3.1415927f + fB * 180.0f / 3.1415927f;
    if (fAngle < 0.0f)
        fAngle += 360.0f;
    if (fAngle >= 360.0f)
        fAngle -= 360.0f;
    return fAngle;
}
MS2_REPLACE_METHOD(0x14166dad0, PCBase, FUN_14166dad0, 210, 0x20A23D56);

// @0x14166dbb0
NiPoint3 PCBase::FUN_14166dbb0()
{
    return m_pos920;
}

// @0x14166dbf0
CString PCBase::FUN_14166dbf0(const efd::utf8string& kName)
{
    return m_spAnimMgr->FUN_14099ddb0(kName);
}
MS2_REPLACE_METHOD(0x14166dbf0, PCBase, FUN_14166dbf0, 83, 0xADE5A5FD);

// @0x14166dc50
CString PCBase::FUN_14166dc50()
{
    return CString(FUN_141b6f910()->FUN_140b7cc50(FUN_14123c460()).c_str());
}
MS2_REPLACE_METHOD(0x14166dc50, PCBase, FUN_14166dc50, 190, 0x36C8CC31);

// @0x14166dd20
bool PCBase::FUN_14166dd20(const efd::utf8string& strAnim, float fSpeed, bool bA, bool bB)
{
    m_unk_968 = bB;
    if (m_unk_968 != 0)
        fSpeed = 1.0f;
    return m_spAnimMgr->FUN_14099e050(const_cast<efd::utf8string&>(strAnim), fSpeed, bA);
}
MS2_REPLACE_METHOD(0x14166dd20, PCBase, FUN_14166dd20, 116, 0x26C26AF1);

// @0x14166dda0
bool PCBase::FUN_14166dda0(int nId)
{
    return FUN_14166dd20(vfunc_123(nId), FUN_1416713c0(), false, false);
}

// @0x14166de50
void PCBase::FUN_14166de50(float fOffset)
{
    m_spAnimMgr->FUN_14099e710(fOffset);
}
MS2_REPLACE_METHOD(0x14166de50, PCBase, FUN_14166de50, 51, 0x1292505D);

// @0x14166f6d0
int PCBase::FUN_14166f6d0()
{
    if (FUN_14166c930() == 0xb)
        return static_cast<Unk_PCBaseState0b*>(FUN_14166ccb0())->FUN_1417c4320();
    if (FUN_14166c930() == 0xf)
        return static_cast<Unk_PCBaseState0f*>(FUN_14166ccb0())->FUN_1417c6a30();
    return 0;
}
MS2_REPLACE_METHOD(0x14166f6d0, PCBase, FUN_14166f6d0, 100, 0xE80CDCB9);

// @0x14166f790
bool PCBase::FUN_14166f790(void* pKey, CString& strOut, int n)
{
    if (m_spD10 == 0) {
        MS2_ASSERT_AT(0x4c5, 0);
        return false;
    }
    MS2Ptr<Unk_PCBaseFxSet> spSet = m_spD10->vfunc_2(pKey);
    if (spSet == 0)
        return false;
    strOut = spSet->FUN_1411bd0c0(n);
    return strOut.IsEmpty() ? false : true;
}
MS2_REPLACE_METHOD(0x14166f790, PCBase, FUN_14166f790, 336, 0x1E9BA79D);

// @0x14166f940
void PCBase::FUN_14166f940()
{
    if (m_timer9e8.FUN_140868ba0() != 0) {
        int nTime = m_timer9e8.FUN_140868a70();
        bool bBusy = false;
        if (m_sp638.get() != 0 && m_sp638->FUN_141848740(nTime))
            bBusy = true;
        if (!bBusy)
            FUN_14166f8f0(0, 1);
    }
}
MS2_REPLACE_METHOD(0x14166f940, PCBase, FUN_14166f940, 159, 0x60041217);

// @0x14166f9f0
int PCBase::vfunc_69()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14166f9f0, PCBase, vfunc_69, 8, 0x7F371472);

// @0x14166fa00
Unk_PCBaseFxLib* PCBase::vfunc_70()
{
    return FUN_140a50010()->FUN_1411bf1b0();
}
MS2_REPLACE_METHOD(0x14166fa00, PCBase, vfunc_70, 27, 0x7E5CDCB1);

// @0x14166fa30
void PCBase::vfunc_71(MS2Ptr<Unk_PCBaseFxSet> spSet)
{
}
MS2_REPLACE_METHOD(0x14166fa30, PCBase, vfunc_71, 29, 0x0BDFA7F1);

// @0x14166fa60
void PCBase::vfunc_72()
{
}

// @0x14166fa70
void PCBase::vfunc_73(MS2Ptr<Unk_PCBaseFxSet> spSet, int bFx)
{
    if (spSet == 0)
        return;
    if (m_unk_a50 != 0 && bFx != 0) {
        for (unsigned int i = 0; i < spSet->m_arrEffects.GetCount(); i++) {
            Unk_PCBaseFxQuery kQuery;
            kQuery.m_strName = spSet->m_arrEffects[i];
            kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
            kQuery.FUN_140a53190(FUN_14123c580());
            unsigned int nHandle = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
            m_arrA30.Add(nHandle);
        }
    }
}
MS2_REPLACE_METHOD(0x14166fa70, PCBase, vfunc_73, 376, 0xE3593D94);

// @0x14166fbf0
void PCBase::vfunc_74(__int64 nCur, __int64 nMax)
{
    MS2Ptr<Unk_PCBaseComp_a58> spBar = vfunc_80();
    if (spBar.get() != 0)
        spBar->FUN_141992230(nCur, nMax);
}
MS2_REPLACE_METHOD(0x14166fbf0, PCBase, vfunc_74, 112, 0x3B69713E);

// @0x14166fc70
void PCBase::vfunc_75(__int64 nCur, __int64 nMax)
{
    MS2Ptr<Unk_PCBaseComp_a68> spBar = vfunc_81();
    if (spBar.get() != 0)
        spBar->FUN_140e85fc0(nCur, nMax);
}
MS2_REPLACE_METHOD(0x14166fc70, PCBase, vfunc_75, 112, 0x44FD6E43);

// @0x14166fcf0
void PCBase::vfunc_76(CStringW str)
{
    m_strW918 = str;
    FUN_141a60f00(m_unk_70);
}
MS2_REPLACE_METHOD(0x14166fcf0, PCBase, vfunc_76, 78, 0x72F191E4);

// @0x14166fd50
CStringW PCBase::vfunc_77()
{
    return m_strW918;
}
MS2_REPLACE_METHOD(0x14166fd50, PCBase, vfunc_77, 68, 0x928E7FA5);

// @0x14166fff0
void PCBase::FUN_14166fff0(CStringW str)
{
    vfunc_94(0);
    FUN_1403b4750()->FUN_1416fb340(str);
    MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = vfunc_85();
    if (spBalloon.get() != 0) {
        spBalloon->FUN_1418fb730(str);
        spBalloon->vfunc_2();
    }
}
MS2_REPLACE_METHOD(0x14166fff0, PCBase, FUN_14166fff0, 184, 0xF815B00C);

// @0x14166fda0
int PCBase::vfunc_78()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14166fda0, PCBase, vfunc_78, 8, 0x7F371472);

// @0x14166fdb0
void PCBase::vfunc_79()
{
    vfunc_78();
}
MS2_REPLACE_METHOD(0x14166fdb0, PCBase, vfunc_79, 33, 0xAE300131);

// @0x14166fde0
MS2Ptr<Unk_PCBaseComp_a58> PCBase::vfunc_80()
{
    return MS2Ptr<Unk_PCBaseComp_a58>(0);
}
MS2_REPLACE_METHOD(0x14166fde0, PCBase, vfunc_80, 55, 0x634E2F19);

// @0x14166fe20
MS2Ptr<Unk_PCBaseComp_a68> PCBase::vfunc_81()
{
    return MS2Ptr<Unk_PCBaseComp_a68>(0);
}
MS2_REPLACE_METHOD(0x14166fe20, PCBase, vfunc_81, 55, 0x726A9F94);

// @0x14166fe60
MS2Ptr<Unk_PCBaseComp_a78> PCBase::vfunc_82()
{
    return MS2Ptr<Unk_PCBaseComp_a78>(0);
}
MS2_REPLACE_METHOD(0x14166fe60, PCBase, vfunc_82, 55, 0x8DF18BD0);

// @0x14166fea0
MS2Ptr<Unk_PCBaseComp_a88> PCBase::vfunc_83()
{
    return MS2Ptr<Unk_PCBaseComp_a88>(0);
}
MS2_REPLACE_METHOD(0x14166fea0, PCBase, vfunc_83, 55, 0x74036550);

// @0x14166fee0
MS2Ptr<Unk_PCBaseComp_a98> PCBase::vfunc_84()
{
    return MS2Ptr<Unk_PCBaseComp_a98>(0);
}
MS2_REPLACE_METHOD(0x14166fee0, PCBase, vfunc_84, 55, 0xCD6979FF);

// @0x14166ff20
MS2Ptr<Unk_PCBaseComp_aa8> PCBase::vfunc_85()
{
    return MS2Ptr<Unk_PCBaseComp_aa8>(0);
}
MS2_REPLACE_METHOD(0x14166ff20, PCBase, vfunc_85, 55, 0xB27808D8);

// @0x14166ff60
MS2Ptr<Unk_PCBaseComp_ab8> PCBase::vfunc_86()
{
    return MS2Ptr<Unk_PCBaseComp_ab8>(0);
}
MS2_REPLACE_METHOD(0x14166ff60, PCBase, vfunc_86, 55, 0x895D3E07);

// @0x14166ffa0
MS2Ptr<Unk_PCBaseComp_ac8> PCBase::vfunc_87()
{
    return MS2Ptr<Unk_PCBaseComp_ac8>(0);
}
MS2_REPLACE_METHOD(0x14166ffa0, PCBase, vfunc_87, 55, 0xEA2BBE0A);

// @0x14166ffe0
UISwfEntity* PCBase::vfunc_88()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14166ffe0, PCBase, vfunc_88, 8, 0x7F371472);

// @0x14166e0d0
efd::utf8string& PCBase::FUN_14166e0d0()
{
    return m_spAnimMgr->FUN_140a53f90();
}
MS2_REPLACE_METHOD(0x14166e0d0, PCBase, FUN_14166e0d0, 39, 0x04A60983);

// @0x14166e100
// The per-frame move step: pMove is the efd::Point3 move of this frame (in/out, in 1/100 units), nFlags the
// controller flags, bNoVelocity skips the body's own velocity. True when the actor's position changed.
bool PCBase::vfunc_68(void* pMove, double dTime, int b, unsigned nFlags, int bNoVelocity)
{
    NiPoint3 kOldPos = vfunc_18();
    m_unk_c68 = 0;
    if (m_unk_150 == 0)
        return false;
    m_posC1C = *static_cast<efd::Point3*>(pMove);
    bool bPushed = false;
    nFlags |= FUN_141675240();
    efd::Point3 kPush = efd::Point3::ZERO;
    if (FUN_1403ed2d0()->FUN_141bc8420(this, (float)dTime, &bNoVelocity, &kPush)) {
        kPush *= 0.01f;
        bPushed = true;
    }
    Unk_PCBaseEntity* pEntity = m_unk_150->FUN_141240f20()->FUN_140cfaff0();
    if (m_unk_150->FUN_141240f40() && !m_unk_150->FUN_141240db0() && !m_unk_150->FUN_141240ef0()
        && !FUN_1403ed2d0()->FUN_141bc9a80() && pEntity != 0 && *static_cast<efd::Point3*>(pMove) == efd::Point3::ZERO)
        bNoVelocity = 1;
    if (bNoVelocity == 0) {
        efd::Point3 kVel = m_unk_150->FUN_1412407f0((float)dTime, vfunc_99(0) && *static_cast<efd::Point3*>(pMove) == efd::Point3::ZERO);
        int nState = FUN_14166c930();
        if (nState != 2 && nState != 5 && nState != 6) {
            if ((nState == 0x10 && m_unk_150->FUN_141240780()) == 0) {
                kVel.x = 0.0f;
                kVel.y = 0.0f;
            }
        }
        *static_cast<efd::Point3*>(pMove) = *static_cast<efd::Point3*>(pMove) + kVel;
    }
    *static_cast<efd::Point3*>(pMove) += kPush;

    // Carried along by the entity stood on (a moving platform).
    NiPoint3 kEntPos = m_posAE8;
    egf::EntityID kEntId(egf::kENTITY_INVALID);
    MS2Ptr<Unk_RideeFieldObj> spField;
    if (pEntity != 0) {
        kEntId = *FUN_1408b76f0(pEntity);
        FUN_1409618c0(pEntity, 0xfd95ca52, kEntPos);
        m_unk_af4 = FUN_1408a13d0(kEntPos);
        spField = FUN_1403ed2d0()->FUN_141bc4f10(pEntity);
        if (spField.get() != 0 && spField->FUN_140ae0150() != efd::Point3::ZERO)
            spField->FUN_140ae0190();
    }
    if (pEntity != 0 && kEntId == m_unk_ae0 && spField.get() != 0) {
        efd::Point3 kDelta = kEntPos - m_posAE8;
        if (kDelta != efd::Point3::ZERO)
            bPushed = true;
        if (!(kDelta.z > 0.0f))
            *static_cast<efd::Point3*>(pMove) += kDelta * 0.01f;
        else if (kDelta.z > 0.0f)
            vfunc_19(vfunc_18() + kDelta);
    }
    m_posAE8 = kEntPos;
    m_unk_ae0 = kEntId;

    m_posC28 = m_unk_150->FUN_14123fd90();
    if (*static_cast<efd::Point3*>(pMove) != efd::Point3::ZERO) {
        m_unk_150->FUN_14123ff80(*static_cast<efd::Point3*>(pMove), nFlags);
        if (bPushed)
            vfunc_110();
    }
    efd::Point3 kMoved = m_unk_150->FUN_14123fd90();
    if (!FUN_140a33ff0(kMoved)) {
        vfunc_19(m_posC28);
        *static_cast<efd::Point3*>(pMove) = efd::Point3::ZERO;
    }
    int nColl = m_unk_150->FUN_141240ed0();
    if (nColl & 4) {
        m_f9cc = 0.0f;
    } else if (nColl & 1) {
        if (m_unk_c68 == 0)
            m_unk_c68 = m_unk_150->FUN_1412412b0();
    } else if (vfunc_99(0)) {
        m_f9cc = 0.0f;
    }

    // Slide off a blocking wall.
    efd::Point3 kBodyPos = m_unk_150->FUN_14123fd90();
    efd::Point3 kNormal;
    if (FUN_1403ed2d0()->FUN_141bd36f0(kBodyPos, &kNormal) == 0) {
        if (kNormal.z != 0.0f && static_cast<efd::Point3*>(pMove)->z < 0.0f)
            kNormal.z = 0.0f;
        if (kNormal != efd::Point3::ZERO) {
            efd::Point3 kSlide = -*static_cast<efd::Point3*>(pMove);
            kSlide.x *= kNormal.x;
            kSlide.y *= kNormal.y;
            kSlide.z *= kNormal.z;
            if (!FUN_140a33ff0(kSlide))
                kSlide = efd::Point3::ZERO;
            efd::Point3 kPrev = m_unk_150->FUN_14123fd90();
            m_unk_150->FUN_14123ff80(kSlide, nFlags);
            kBodyPos = m_unk_150->FUN_14123fd90();
            if (!FUN_140a33ff0(kBodyPos)) {
                vfunc_19(kPrev);
                *static_cast<efd::Point3*>(pMove) = efd::Point3::ZERO;
                kBodyPos = kPrev;
            }
        }
    }
    GameObject::vfunc_19(kBodyPos);
    bool bMoved = kBodyPos != kOldPos;
    if (FUN_1409478c0()->FUN_140aed3a0() != 0) {
        if (FUN_1409478c0()->FUN_140a38d60() == this && FUN_1409478c0()->FUN_140aed3e0())
            FUN_14166d630((float)dTime);
    } else {
        FUN_14166d630((float)dTime);
    }
    return bMoved;
}
MS2_REPLACE_METHOD(0x14166e100, PCBase, vfunc_68, 2779, 0xBB0D06D1);

// @0x14166e0a0
void PCBase::FUN_14166e0a0()
{
    m_spAnimMgr->FUN_14099e680();
}
MS2_REPLACE_METHOD(0x14166e0a0, PCBase, FUN_14166e0a0, 39, 0x4949AA37);

// @0x14166ed10
bool PCBase::FUN_14166ed10()
{
    return m_b9d0;
}
MS2_REPLACE_METHOD(0x14166ed10, PCBase, FUN_14166ed10, 18, 0x00EA9B7C);

// @0x14166ed30
void PCBase::FUN_14166ed30(bool b)
{
    m_b9d0 = b;
}
MS2_REPLACE_METHOD(0x14166ed30, PCBase, FUN_14166ed30, 26, 0xEF65E47C);

// @0x14166ed50
void PCBase::FUN_14166ed50(bool b)
{
    m_b9d1 = b;
}
MS2_REPLACE_METHOD(0x14166ed50, PCBase, FUN_14166ed50, 26, 0x97B64443);

// @0x14166f740
CString PCBase::FUN_14166f740()
{
    return m_str9e0;
}
MS2_REPLACE_METHOD(0x14166f740, PCBase, FUN_14166f740, 68, 0xC97EA0D3);

// @0x14166f8f0
void PCBase::FUN_14166f8f0(int nA, int nB)
{
    FUN_14166ed50(true);
    FUN_14166ef10(m_str9d8, nA, nB, false);
}
MS2_REPLACE_METHOD(0x14166f8f0, PCBase, FUN_14166f8f0, 74, 0x17B9A2EE);

// @0x141670330
void PCBase::FUN_141670330(float f)
{
    m_f170 = f;
}
MS2_REPLACE_METHOD(0x141670330, PCBase, FUN_141670330, 31, 0xF6772D25);

// @0x141670360
void PCBase::FUN_141670360(float f)
{
    m_f174 = f;
}
MS2_REPLACE_METHOD(0x141670360, PCBase, FUN_141670360, 31, 0x5BDAD799);

// @0x141670430
float PCBase::FUN_141670430()
{
    return m_f178;
}
MS2_REPLACE_METHOD(0x141670430, PCBase, FUN_141670430, 19, 0x040BA781);

// @0x141670500
float PCBase::FUN_141670500()
{
    return m_f168;
}
MS2_REPLACE_METHOD(0x141670500, PCBase, FUN_141670500, 19, 0x99972B51);

// @0x141670520
float PCBase::FUN_141670520()
{
    return m_f17c;
}
MS2_REPLACE_METHOD(0x141670520, PCBase, FUN_141670520, 19, 0x9EAB230D);

// @0x141670990
__int64 PCBase::FUN_141670990(int nKind, int nStat)
{
    return m_unk_1c0[nKind][nStat];
}
MS2_REPLACE_METHOD(0x141670990, PCBase, FUN_141670990, 49, 0xFF3D117E);

// @0x1416709d0
__int64 PCBase::FUN_1416709d0(int nStat)
{
    return m_unk_1c0[1][nStat];
}
MS2_REPLACE_METHOD(0x1416709d0, PCBase, FUN_1416709d0, 41, 0x1193CA91);

// @0x141670a00
__int64 PCBase::FUN_141670a00(int nStat)
{
    return m_unk_1c0[2][nStat];
}
MS2_REPLACE_METHOD(0x141670a00, PCBase, FUN_141670a00, 41, 0xE53E749A);

// @0x141670a30
__int64 PCBase::FUN_141670a30(int nStat)
{
    return m_unk_1c0[0][nStat];
}
MS2_REPLACE_METHOD(0x141670a30, PCBase, FUN_141670a30, 41, 0x740EAF44);

// @0x141670a60
__int64 PCBase::FUN_141670a60(int nStat)
{
    return m_unk_508[nStat];
}
MS2_REPLACE_METHOD(0x141670a60, PCBase, FUN_141670a60, 28, 0x0DFD3A6B);

// @0x141670d50
void PCBase::FUN_141670d50(efd::Point2 kSize)
{
    m_unk_620 = kSize;
}
MS2_REPLACE_METHOD(0x141670d50, PCBase, FUN_141670d50, 28, 0x9913344D);

// @0x141670d80
void PCBase::FUN_141670d80(float fSpeed)
{
    m_f938 = fSpeed;
}
MS2_REPLACE_METHOD(0x141670d80, PCBase, FUN_141670d80, 31, 0x98CE89D5);

// @0x141670db0
void PCBase::FUN_141670db0(CString str)
{
    m_str940 = str;
}
MS2_REPLACE_METHOD(0x141670db0, PCBase, FUN_141670db0, 65, 0x35877EDC);

// @0x141670e00
void PCBase::FUN_141670e00(CString str)
{
    m_str948 = str;
}
MS2_REPLACE_METHOD(0x141670e00, PCBase, FUN_141670e00, 65, 0x4B4FE054);

// @0x141670e50
void PCBase::FUN_141670e50(CString str)
{
    m_str960 = str;
}
MS2_REPLACE_METHOD(0x141670e50, PCBase, FUN_141670e50, 65, 0x796101FC);

// @0x141670ea0
void PCBase::FUN_141670ea0()
{
    m_str960.Empty();
}
MS2_REPLACE_METHOD(0x141670ea0, PCBase, FUN_141670ea0, 34, 0xB2735B13);

// @0x141671390
efd::Point2 PCBase::FUN_141671390()
{
    return m_unk_620;
}
MS2_REPLACE_METHOD(0x141671390, PCBase, FUN_141671390, 36, 0x977D29BC);

// @0x1416713c0
float PCBase::FUN_1416713c0()
{
    return m_f938;
}
MS2_REPLACE_METHOD(0x1416713c0, PCBase, FUN_1416713c0, 19, 0xD8D95139);

// @0x1416713e0
CString PCBase::FUN_1416713e0()
{
    return m_str940;
}
MS2_REPLACE_METHOD(0x1416713e0, PCBase, FUN_1416713e0, 68, 0xEF54CDE1);

// @0x141671430
CString PCBase::FUN_141671430()
{
    return m_str948;
}
MS2_REPLACE_METHOD(0x141671430, PCBase, FUN_141671430, 68, 0xD486A189);

// @0x1416715b0
CString PCBase::FUN_1416715b0()
{
    return m_str950;
}
MS2_REPLACE_METHOD(0x1416715b0, PCBase, FUN_1416715b0, 68, 0x981B8463);

// @0x141671600
float PCBase::FUN_141671600()
{
    return m_unk_1a0.m_a;
}
MS2_REPLACE_METHOD(0x141671600, PCBase, FUN_141671600, 19, 0x515C60A9);

// @0x141671920
float* PCBase::FUN_141671920()
{
    return &m_unk_180.m_x;
}
MS2_REPLACE_METHOD(0x141671920, PCBase, FUN_141671920, 17, 0x87CF6FFA);

// @0x141671940
float PCBase::FUN_141671940()
{
    return m_unk_190.m_z;
}
MS2_REPLACE_METHOD(0x141671940, PCBase, FUN_141671940, 19, 0x31ACDCE1);

// @0x141671960
void PCBase::FUN_141671960(float fSpeed)
{
    m_unk_190.m_z = fSpeed;
}
MS2_REPLACE_METHOD(0x141671960, PCBase, FUN_141671960, 31, 0xEEDFB76D);

// @0x141671990
void PCBase::FUN_141671990(float fScale)
{
    m_f92c = fScale;
}
MS2_REPLACE_METHOD(0x141671990, PCBase, FUN_141671990, 31, 0x10F8FD89);

// @0x141671b20
BOOL PCBase::FUN_141671b20()
{
    return GetClassID() == 0x6200050;
}
MS2_REPLACE_METHOD(0x141671b20, PCBase, FUN_141671b20, 59, 0xF6428016);

// @0x1416749a0
Unk_PCBaseBuffs* PCBase::FUN_1416749a0()
{
    return static_cast<Unk_PCBaseBuffs*>(&m_unk_748);
}
MS2_REPLACE_METHOD(0x1416749a0, PCBase, FUN_1416749a0, 17, 0xD57792A0);

// @0x141676020
efd::Point3 PCBase::FUN_141676020()
{
    return m_posC10;
}
MS2_REPLACE_METHOD(0x141676020, PCBase, FUN_141676020, 44, 0x0E0311C6);

// @0x141676980
void PCBase::FUN_141676980(int n)
{
    m_unk_b70 = n;
}
MS2_REPLACE_METHOD(0x141676980, PCBase, FUN_141676980, 25, 0x39A0BC30);

// @0x1416769a0
void PCBase::FUN_1416769a0(__int64 nUid)
{
    m_nUidB78 = nUid;
}
MS2_REPLACE_METHOD(0x1416769a0, PCBase, FUN_1416769a0, 28, 0x17093EA8);

// @0x1416769d0
int PCBase::FUN_1416769d0()
{
    return m_unk_b70;
}
MS2_REPLACE_METHOD(0x1416769d0, PCBase, FUN_1416769d0, 17, 0xCC36A574);

// @0x1416769f0
__int64 PCBase::FUN_1416769f0()
{
    return m_nUidB78;
}
MS2_REPLACE_METHOD(0x1416769f0, PCBase, FUN_1416769f0, 18, 0x5451CDDE);

// @0x141676b50
void PCBase::FUN_141676b50(int n)
{
    m_unk_b80 = n;
}
MS2_REPLACE_METHOD(0x141676b50, PCBase, FUN_141676b50, 25, 0xF9008D40);

// @0x141676b70
int PCBase::FUN_141676b70()
{
    return m_unk_b80;
}
MS2_REPLACE_METHOD(0x141676b70, PCBase, FUN_141676b70, 17, 0x3936E264);

// @0x1416781a0
void PCBase::FUN_1416781a0(int n)
{
    m_unk_c00 = n;
}
MS2_REPLACE_METHOD(0x1416781a0, PCBase, FUN_1416781a0, 25, 0xB8378DBB);

// @0x1416782e0
int PCBase::FUN_1416782e0()
{
    return m_unk_af4;
}
MS2_REPLACE_METHOD(0x1416782e0, PCBase, FUN_1416782e0, 17, 0x49054061);

// @0x141678300
void PCBase::FUN_141678300(int n)
{
    m_unk_af4 = n;
}
MS2_REPLACE_METHOD(0x141678300, PCBase, FUN_141678300, 25, 0x287B4905);

// @0x141678320
int PCBase::FUN_141678320()
{
    return m_unk_af8;
}
MS2_REPLACE_METHOD(0x141678320, PCBase, FUN_141678320, 17, 0xE0DF37DD);

// @0x141678340
void PCBase::FUN_141678340(int n)
{
    m_unk_af8 = n;
}
MS2_REPLACE_METHOD(0x141678340, PCBase, FUN_141678340, 25, 0x758EB519);

// @0x141678710
efd::Point3 PCBase::FUN_141678710()
{
    return m_pos9ac;
}
MS2_REPLACE_METHOD(0x141678710, PCBase, FUN_141678710, 44, 0xFCD0A4DB);

// @0x141679070
int PCBase::FUN_141679070()
{
    return m_unk_c0c;
}
MS2_REPLACE_METHOD(0x141679070, PCBase, FUN_141679070, 17, 0x6CCB6E73);

// @0x141679090
void PCBase::FUN_141679090(int n)
{
    m_unk_c0c = n;
}
MS2_REPLACE_METHOD(0x141679090, PCBase, FUN_141679090, 25, 0xCEB11FAF);

// @0x141670cd0
void PCBase::vfunc_91(void* p)
{
    vfunc_90(p);
}
MS2_REPLACE_METHOD(0x141670cd0, PCBase, vfunc_91, 43, 0x79C52993);

// @0x141670d10
void PCBase::vfunc_92(void* p)
{
    vfunc_90(p);
}
MS2_REPLACE_METHOD(0x141670d10, PCBase, vfunc_92, 43, 0x79C52993);

// @0x141671380
void PCBase::vfunc_94(int n)
{
}

// @0x141671620
float PCBase::vfunc_95()
{
    float fBase = FUN_141671940();
    float fRate = vfunc_96();
    return fBase * fRate * m_f92c;
}
MS2_REPLACE_METHOD(0x141671620, PCBase, vfunc_95, 80, 0x873F203D);

// @0x141674bf0
int PCBase::vfunc_108()
{
    return 0;
}
MS2_REPLACE_METHOD(0x141674bf0, PCBase, vfunc_108, 8, 0x7F371472);

// @0x141674c00
void PCBase::vfunc_109(int n)
{
    if (n != 0)
        m_unk_150->FUN_14123fbf0(2);
    else
        m_unk_150->FUN_14123fbf0(5);
}
MS2_REPLACE_METHOD(0x141674c00, PCBase, vfunc_109, 69, 0x460AC9D8);

// @0x141674c50
void PCBase::vfunc_110()
{
}

// @0x141671680
float PCBase::vfunc_96()
{
    if (GetClassID() == 0x6200045)
        return FUN_1401c0db0()->FUN_140674290(FUN_141670a00(0x20));
    return FUN_1401c0db0()->FUN_140674100(FUN_141670a00(0xe), FUN_1416787a0());
}
MS2_REPLACE_METHOD(0x141671680, PCBase, vfunc_96, 142, 0x5A4E0AB6);

// @0x1416718d0
float PCBase::vfunc_98(float f)
{
    return FUN_1401c0db0()->FUN_140674420(FUN_141670a00(0xd), f);
}
MS2_REPLACE_METHOD(0x1416718d0, PCBase, vfunc_98, 67, 0x9F70B920);

// @0x1416700b0
void PCBase::FUN_1416700b0(int nType)
{
    MS2Ptr<Unk_PCBaseComp_ac8> spBanner = vfunc_87();
    if (spBanner == 0)
        return;
    if (nType == 0) {
        spBanner->vfunc_3();
        return;
    }
    spBanner->FUN_140ba8720(nType);
    spBanner->vfunc_2();
}
MS2_REPLACE_METHOD(0x1416700b0, PCBase, FUN_1416700b0, 198, 0xEB11A23B);

// @0x141670180
void PCBase::FUN_141670180(bool bShow)
{
    if (FUN_14166ce30() != 0)
        return;
    MS2Ptr<Unk_PCBaseComp_a58> spBar = vfunc_80();
    if (spBar.get() != 0) {
        spBar->FUN_141992180(FUN_141670a00(4), FUN_141670a30(4));
        if (bShow)
            spBar->FUN_141992140(bShow);
    }
}
MS2_REPLACE_METHOD(0x141670180, PCBase, FUN_141670180, 213, 0x5B144CC8);

// @0x141670260
void PCBase::FUN_141670260(int nShield, bool bShow)
{
    if (FUN_14166ce30() != 0)
        return;
    MS2Ptr<Unk_PCBaseComp_a68> spBar = vfunc_81();
    if (spBar.get() != 0) {
        spBar->FUN_140e85f10(nShield, nShield);
        if (bShow)
            spBar->FUN_140e85ed0(bShow);
    }
}
MS2_REPLACE_METHOD(0x141670260, PCBase, FUN_141670260, 198, 0x18291DE7);

// @0x141670390
float PCBase::FUN_141670390()
{
    float fMount = 0.0f;
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0)
        fMount = spRidee->FUN_141707960();
    return m_f164 + m_f174 + fMount;
}
MS2_REPLACE_METHOD(0x141670390, PCBase, FUN_141670390, 153, 0xEF36227E);

// @0x141670450
float PCBase::vfunc_89()
{
    float fMount = 0.0f;
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0)
        fMount = spRidee->vfunc_89();
    return m_f16c + m_f170 + fMount;
}
MS2_REPLACE_METHOD(0x141670450, PCBase, vfunc_89, 169, 0x56B885A2);

// @0x141670540
void PCBase::FUN_141670540(int nKind, int nStat, __int64 nValue)
{
    if (nKind == 1)
        FUN_1416705c0(nStat, nValue);
    else if (nKind == 2)
        FUN_141670700(nStat, nValue);
    else if (nKind == 0)
        FUN_1416708a0(nStat, nValue);
}
MS2_REPLACE_METHOD(0x141670540, PCBase, FUN_141670540, 110, 0xF9DEC14D);

// @0x1416705c0
void PCBase::FUN_1416705c0(int nStat, __int64 nValue)
{
    m_unk_1c0[1][nStat] = nValue;
    if (m_unk_1c0[1][nStat] < 0)
        m_unk_1c0[1][nStat] = 0;
    if (m_unk_1c0[1][nStat] > m_unk_1c0[0][nStat])
        m_unk_1c0[1][nStat] = m_unk_1c0[0][nStat];
    if (m_spB10)
        m_spB10->FUN_1416705c0(nStat, nValue);
}
MS2_REPLACE_METHOD(0x1416705c0, PCBase, FUN_1416705c0, 314, 0xA07389F9);

// @0x141670700
void PCBase::FUN_141670700(int nStat, __int64 nValue)
{
    if (nValue != m_unk_1c0[2][nStat])
        FUN_141670920(nStat, m_unk_1c0[2][nStat]);
    m_unk_1c0[2][nStat] = nValue;
    if (m_unk_1c0[2][nStat] < 0)
        m_unk_1c0[2][nStat] = 0;
    if (m_unk_1c0[2][nStat] > m_unk_1c0[0][nStat])
        m_unk_1c0[2][nStat] = m_unk_1c0[0][nStat];
    if (m_spB10)
        m_spB10->FUN_141670700(nStat, nValue);
}
MS2_REPLACE_METHOD(0x141670700, PCBase, FUN_141670700, 397, 0xDF9AE4CF);

// @0x1416708a0
void PCBase::FUN_1416708a0(int nStat, __int64 nValue)
{
    m_unk_1c0[0][nStat] = nValue;
    if (m_spB10)
        m_spB10->FUN_1416708a0(nStat, nValue);
}
MS2_REPLACE_METHOD(0x1416708a0, PCBase, FUN_1416708a0, 119, 0x0F9E58B8);

// @0x141670920
void PCBase::FUN_141670920(int nStat, __int64 nValue)
{
    m_unk_508[nStat] = nValue;
    if (m_spB10)
        m_spB10->FUN_141670920(nStat, nValue);
}
MS2_REPLACE_METHOD(0x141670920, PCBase, FUN_141670920, 106, 0x9D769AB6);

// @0x141670a90
// MS2-FUNCTIONAL: slot 90 takes void* in the shared PCBase/PC declarations (as in MyPC::vfunc_90).
void PCBase::vfunc_90(void* p)
{
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    unsigned char nCount = pPacket->ReadUInt8();
    if (nCount == 0x23) {
        for (int nType = 0; nType < 0x23; nType++) {
            for (int i = 0; i < 3; i++) {
                __int64 nValue;
                if (FUN_14082f1a0(nType) == 0)
                    nValue = (unsigned)pPacket->ReadInt32();
                else
                    nValue = pPacket->ReadInt64();
                FUN_141670540(i, nType, nValue);
            }
        }
    }
    else {
        for (int n = 0; n < nCount; n++) {
            unsigned char nType = pPacket->ReadUInt8();
            for (int i = 0; i < 3; i++) {
                __int64 nValue;
                if (FUN_14082f1a0(nType) == 0)
                    nValue = (unsigned)pPacket->ReadInt32();
                else
                    nValue = pPacket->ReadInt64();
                FUN_141670540(i, nType, nValue);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141670a90, PCBase, vfunc_90, 569, 0xAFACA969);

// @0x141670ed0
void PCBase::FUN_141670ed0(Unk_PCBaseEntity* pEntity)
{
    m_str958 = "default";
    if (m_unk_9a8 != 0 && pEntity != 0) {
        efd::utf8string strMaterial;
        pEntity->FUN_1408a2060(0xde5dd580, &strMaterial);
        unsigned short nKind = 0;
        pEntity->FUN_140ae1160(0xada5c5d2, &nKind);
        if (!strMaterial.empty()) {
            m_unk_9c4 = nKind;
            m_str958 = strMaterial.c_str();
        }
    }
}
MS2_REPLACE_METHOD(0x141670ed0, PCBase, FUN_141670ed0, 247, 0xF98BBCFA);

// @0x141671130
void PCBase::vfunc_93(bool bMaterial)
{
    if (FUN_141671a30() != 0) {
        m_unk_9a8 = 1;
        m_f9c8 = 0;
        m_pos9ac = vfunc_18();
        m_pos9b8 = FUN_14166d220()->FUN_141240df0();
    }
    else {
        Unk_PCBaseRayHit kHit;
        m_unk_9a8 = FUN_1409f7ca0()->FUN_14168a310(vfunc_18(), &m_pos9ac, &kHit, 0.0f, &m_pos9b8, 0);
        if (m_unk_9a8 == 0) {
            m_pos9ac = efd::Point3::ZERO;
            m_f9c8 = FLT_MAX;
        }
        else {
            m_f9c8 = kHit.m_hitDist;
        }
    }
    if (bMaterial) {
        m_unk_9c4 = 0;
        m_str958.Empty();
        Unk_PCBaseEntity* pEntity = m_unk_150->FUN_141240f20()->FUN_140cfaff0();
        if (pEntity != 0)
            FUN_141670ed0(pEntity);
    }
}
MS2_REPLACE_METHOD(0x141671130, PCBase, vfunc_93, 576, 0x9C628E51);

// @0x141671480
CString PCBase::FUN_141671480()
{
    if (!m_str960.IsEmpty()) {
        BOOL bUse = FALSE;
        if (vfunc_62() == false)
            bUse = m_unk_9c4 != 8;
        else
            bUse = m_unk_9c4 != 8 && vfunc_61() == 2;
        if (bUse)
            return m_str960;
    }
    return m_str958;
}
MS2_REPLACE_METHOD(0x141671480, PCBase, FUN_141671480, 295, 0xCA524CA6);

// @0x141671720
float PCBase::vfunc_97()
{
    float fRate = 1.0f;
    if (m_fScaleA8 != m_fScaleAC) {
        if (m_fScaleAC / 2.0f > m_fScaleA8)
            fRate = 1.5f;
        else if (m_fScaleAC / 2.0f <= m_fScaleA8 && m_fScaleA8 < m_fScaleAC)
            fRate = 2.0f - m_fScaleA8 / m_fScaleAC;
        else if (m_fScaleA8 > m_fScaleAC && m_fScaleAC * 2.0f >= m_fScaleA8)
            fRate = 1.0f - (m_fScaleA8 - m_fScaleAC) / (m_fScaleAC * 2.0f);
        else if (m_fScaleAC * 2.0f < m_fScaleA8)
            fRate = 0.5f;
    }
    return fRate;
}
MS2_REPLACE_METHOD(0x141671720, PCBase, vfunc_97, 412, 0xA3371C75);

// @0x1416719c0
BOOL PCBase::FUN_1416719c0()
{
    CString strModel = FUN_14166dc50();
    if (strModel.Find("Dash", 0) != -1)
        return TRUE;
    return FALSE;
}
MS2_REPLACE_METHOD(0x1416719c0, PCBase, FUN_1416719c0, 103, 0xCE9ED2D7);

// @0x141671a30
int PCBase::FUN_141671a30()
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0 && FUN_14166c930() == 0x21)
        return spRidee->FUN_141671a30();
    if (FUN_14166d220() == 0)
        return 0;
    return FUN_14166d220()->FUN_141240f40() != 0;
}
MS2_REPLACE_METHOD(0x141671a30, PCBase, FUN_141671a30, 220, 0x9D9E0C20);

// @0x141671b70
int PCBase::vfunc_99(int nSlope)
{
    if (m_unk_150 == 0)
        return 0;
    if (nSlope < 0)
        nSlope = 0;
    if (nSlope == 0)
        nSlope = 100;
    int nLimit = m_unk_150->FUN_141240ef0();
    if (nLimit > nSlope && FUN_14028d380(0.3f) < m_f9c8 && (FUN_14166d220()->FUN_141240ed0() & 4) == 0)
        return 1;
    else
        return 0;
}
MS2_REPLACE_METHOD(0x141671b70, PCBase, vfunc_99, 159, 0x1EE7592B);

// @0x141672910
void PCBase::vfunc_100(MS2Ptr<CSkillRecord> spSkill, int n)
{
    if (spSkill.IsNull())
        return;
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee) {
        spRidee->vfunc_100(spSkill, n);
        return;
    }
    Unk_PCBaseMoveTarget* pMove = static_cast<Unk_PCBaseMoveTarget*>(FUN_14166d240());
    efd::Point3 kPos = pMove->FUN_141683900();
    float fAngle = FUN_14166da40();
    efd::Point3 kTarget;
    efd::Point3 kDir;
    int bAim = 1;
    if (m_spStateMgr->GetCur() == 0x10) {
        int nMode = spSkill->m_sp30->m_n88;
        int bKeep = 0;
        if (nMode == 0)
            bKeep = 1;
        else if (FUN_14036d570(FUN_140166410(), 0xca) && nMode == 2)
            bKeep = 1;
        State* pState = m_spStateMgr->GetState();
        if (bKeep && FUN_1417e9330(pState) == spSkill->FUN_141759960() && spSkill->m_sp30->m_b34) {
            MS2Ptr<CSkillRecord> spCur = static_cast<Unk_PCBaseSkillState*>(pState)->FUN_1417ed6f0();
            if (spCur.get()) {
                bAim = 0;
                kTarget = spCur->m_k5c;
                kDir = spCur->m_k68;
            }
        }
    }
    if (bAim)
        vfunc_105(kPos, &kTarget, &kDir, 1);
    if (FUN_1409478c0()->FUN_140af7e30() == 10)
        kDir = FUN_1409478c0()->FUN_140af8290();
    if (n == 0)
        FUN_14166d8b0(fAngle);
    if (m_unk_c00 != 10 && m_unk_c00 != 9 && spSkill->m_sp30->m_n74 != 0)
        vfunc_101(spSkill, n, &kDir);
    spSkill->m_k5c = kTarget;
    spSkill->m_k68 = kDir;
    spSkill->m_k50 = vfunc_18();
}
MS2_REPLACE_METHOD(0x141672910, PCBase, vfunc_100, 1214, 0x11D2F197);

// @0x141672de0
// vfunc_18/20 return NiPoint3 in this tree; the casts to efd::Point3 give the exe's NiPoint3(efd::Point3) conversions.
void PCBase::vfunc_101(MS2Ptr<CSkillRecord> spSkill, int n, void* pRot)
{
    if (spSkill.IsNull())
        return;
    if (spSkill->m_sp30->m_n74 == 0)
        return;
    Unk_PCBaseSkillCast* pCast = spSkill->FUN_14175a000();
    if (pCast == 0)
        return;
    CCylinderCollision kCyl;
    kCyl.m_fRadius = spSkill->m_sp30->m_f164;
    if (FUN_14028d470(kCyl.m_fRadius, 0.0f))
        kCyl.m_fRadius = spSkill->m_sp40->FUN_1408042a0(spSkill->m_n8c, spSkill->m_n94);
    NiPoint3 kPos = vfunc_18();
    kCyl.m_fHeight = 150.0f;
    float fHeight = spSkill->m_sp30->m_f168;
    if (!FUN_14028d470(fHeight, 0.0f)) {
        kCyl.m_fHeight = fHeight;
        kPos.z -= fHeight * 0.5f;
    }
    kCyl.vfunc_3(static_cast<const efd::Point3&>(kPos), static_cast<const efd::Point3&>(vfunc_20()), 1.0f);
    int nTargetKind = pCast->m_nTargetKind;
    efd::Point3 kOffset = efd::Point3::ZERO;
    efd::Point3 kRaise = efd::Point3::ZERO;
    if (spSkill->FUN_141759f70() == 0) {
        kOffset = pCast->m_kOffset;
        kRaise.z = pCast->m_fRaise;
        float fYaw = GameObject::FUN_14123ce70(FUN_14123cc20());
        NiMatrix3 kRot;
        kRot.MakeZRotation(fYaw + 3.1415927f);
        kOffset = kRot * kOffset;
    }
    efd::Point3 kCenter = kPos + kOffset;
    efd::Point3 kDir = vfunc_20() + kRaise;
    MS2Ptr<CDetectContext> spCtx(new CDetectContext);
    spCtx->m_pOwner = this;
    spCtx->m_p20 = 0;
    spCtx->m_kPos = kCenter;
    spCtx->m_nTargetKind = nTargetKind;
    spCtx->m_n74 = 3;
    spCtx->m_n7c = 0;
    kCyl.FUN_1409fc390(spCtx, kDir);
    if (spCtx->m_arrTargets.IsEmpty())
        return;
    GameObject* pTarget = 0;
    int nPick = spSkill->m_sp30->m_n78;
    float fAngle = spSkill->m_sp30->m_f160;
    efd::Point3 kAim = GameObject::FUN_14123cc80(*static_cast<NiPoint3*>(pRot));
    switch (nPick) {
    case 0:
    case 3:
        pTarget = FUN_141679800(spCtx->m_arrTargets, fAngle, kAim, nPick);
        break;
    case 1:
    case 2:
        pTarget = FUN_141679ad0(spCtx->m_arrTargets, fAngle, kAim, nPick);
        break;
    }
    if (pTarget == 0)
        return;
    GameObject* pObj = pTarget;
    efd::Point3 kLook = pObj->vfunc_30(this) - vfunc_18();
    kLook = -kLook;
    kLook.z = 0.0f;
    kLook.Unitize();
    efd::Point3 kRight = kLook.UnitCross(efd::Point3::UNIT_Z);
    efd::Point3 kFront = kRight.UnitCross(efd::Point3::UNIT_Z);
    NiMatrix3 kMat;
    kMat.SetCol(0, kRight);
    kMat.SetCol(1, kFront);
    kMat.SetCol(2, efd::Point3::UNIT_Z);
    float fX, fY, fZ;
    kMat.ToEulerAnglesXYZ(fX, fY, fZ);
    efd::Point3 kAngles(0.0f, 0.0f, fZ * 180.0f / 3.1415927f);
    FUN_140291bc0(&kAngles);
    if (n)
        FUN_14166d8b0(kAngles.z);
    *static_cast<efd::Point3*>(pRot) = kAngles;
    if (spSkill->m_sp30->m_n16c) {
        spSkill->m_f74 = FUN_140966f00(pObj->vfunc_30(this), vfunc_18());
        if (spSkill->m_f74 > 100.0f)
            spSkill->m_f74 -= 100.0f;
    }
}
MS2_REPLACE_METHOD(0x141672de0, PCBase, vfunc_101, 2726, 0xE7371410);

// @0x141673890
bool PCBase::vfunc_102(MS2Ptr<CSkillRecord> skill)
{
    return true;
}
MS2_REPLACE_METHOD(0x141673890, PCBase, vfunc_102, 39, 0xDCF00779);

// @0x1416738c0
MS2Ptr<Unk_PCBaseComp_b18> PCBase::vfunc_103()
{
    if (m_unk_8e8.IsEmpty())
        return MS2Ptr<Unk_PCBaseComp_b18>(0);
    MS2Ptr<Unk_PCBaseComp_b18> spItem = m_unk_8e8.GetTail();
    if (spItem->FUN_141759e40() != 0)
        return MS2Ptr<Unk_PCBaseComp_b18>(0);
    else
        return spItem;
}
MS2_REPLACE_METHOD(0x1416738c0, PCBase, vfunc_103, 233, 0xF71E697F);

// @0x1416739c0
MS2Ptr<Unk_PCBaseComp_b18> PCBase::vfunc_104(bool a, bool b, bool c)
{
    return MS2Ptr<Unk_PCBaseComp_b18>(0);
}
MS2_REPLACE_METHOD(0x1416739c0, PCBase, vfunc_104, 65, 0x3097854B);

// @0x1416749c0
bool PCBase::FUN_1416749c0()
{
    NiPoint3 kPos = FUN_14123c360();
    if (kPos != efd::Point3::ZERO)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1416749c0, PCBase, FUN_1416749c0, 59, 0x3D7C4A38);

// @0x141674ec0
void PCBase::vfunc_113(void* p)
{
    FUN_140e09140()->FUN_140a04ef0(p);
}
MS2_REPLACE_METHOD(0x141674ec0, PCBase, vfunc_113, 37, 0x2955B135);

// @0x141675270
float PCBase::vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut)
{
    return 0;
}
MS2_REPLACE_METHOD(0x141675270, PCBase, vfunc_115, 27, 0x2EA3D17C);

// @0x1416752a0
int PCBase::vfunc_117()
{
    return !m_unk_b88.IsEmpty();
}
MS2_REPLACE_METHOD(0x1416752a0, PCBase, vfunc_117, 62, 0x58D030AC);

// @0x141676410
int PCBase::FUN_141676410()
{
    if (m_spB10 == 0)
        return 0;
    return m_spB10->GetData()->m_nNameId;
}
MS2_REPLACE_METHOD(0x141676410, PCBase, FUN_141676410, 133, 0x8F2137E9);

// @0x1416764a0
Ridee* PCBase::FUN_1416764a0()
{
    return m_spB10;
}
MS2_REPLACE_METHOD(0x1416764a0, PCBase, FUN_1416764a0, 33, 0x3B108532);

// @0x1416764d0
int PCBase::FUN_1416764d0()
{
    return m_spB10 != 0;
}
MS2_REPLACE_METHOD(0x1416764d0, PCBase, FUN_1416764d0, 38, 0x78397EF1);

// @0x141676930
MS2Ptr<Unk_PCBaseComp_b18> PCBase::FUN_141676930()
{
    return m_spB18;
}
MS2_REPLACE_METHOD(0x141676930, PCBase, FUN_141676930, 67, 0xDAC1A857);

// @0x1416781c0
int PCBase::vfunc_122(void* p)
{
    if (p == 0)
        return 0;
    return vfunc_116() != static_cast<PCBase*>(p)->vfunc_116();
}
MS2_REPLACE_METHOD(0x1416781c0, PCBase, vfunc_122, 113, 0xCFF8EA1D);

// @0x1416752f0
int PCBase::vfunc_118(const NiPoint3& kPos, float* pDist, CString* pName)
{
    if (vfunc_117() == 0)
        return 0;
    *pDist = FLT_MAX;
    for (POSITION pos = m_unk_b88.GetHeadPosition(); pos != 0; m_unk_b88.GetNext(pos)) {
        CString strName = m_unk_b88.GetKeyAt(pos);
        NiAVObject* pNode = m_unk_b88.GetValueAt(pos);
        float fDist = (pNode->GetWorldTranslate() - kPos).Length();
        if (fDist < *pDist) {
            *pDist = fDist;
            *pName = strName;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1416752f0, PCBase, vfunc_118, 346, 0x49F5AB68);

// @0x141673a10
// MS2-FUNCTIONAL: the exe moves the saved z pointer through rcx into rdx for FUN_140970eb0; the source loads rdx directly (register choice only).
void PCBase::vfunc_105(efd::Point3 kPos, void* b, void* c, int d)
{
    float fYaw = 0;
    *static_cast<efd::Point3*>(b) = FUN_141674a10(kPos, &fYaw);
    *static_cast<efd::Point3*>(c) = vfunc_20();
    if (d != 0) {
        static_cast<efd::Point3*>(c)->y = 0;
        static_cast<efd::Point3*>(c)->x = 0;
    }
    if (*static_cast<efd::Point3*>(b) != efd::Point3::ZERO)
        static_cast<efd::Point3*>(c)->z = fYaw;
    float* pRotZ = &static_cast<efd::Point3*>(c)->z;
    FUN_1416749a0()->FUN_140970eb0(*pRotZ);
}
MS2_REPLACE_METHOD(0x141673a10, PCBase, vfunc_105, 288, 0xE5649AD4);

// @0x141674a10
efd::Point3 PCBase::FUN_141674a10(efd::Point3 kDir, float* pYaw)
{
    efd::Point3 kRet = efd::Point3::ZERO;
    if (kDir != efd::Point3::ZERO) {
        efd::Point3 kSide;
        efd::Point3 kFront;
        vfunc_67(&kSide, &kFront);
        kRet = kDir.y * kSide + kDir.x * kFront;
        kRet.Unitize();
        *pYaw = FUN_14166dad0(kDir, kFront);
    }
    return kRet;
}
MS2_REPLACE_METHOD(0x141674a10, PCBase, FUN_141674a10, 323, 0xCA310BE2);

// @0x141674c60
void PCBase::vfunc_111(void* p, int a, int b, void* q)
{
    __int64 nValue = abs(reinterpret_cast<__int64>(p));
    Unk_PCBaseDamageUI* pDamage = FUN_140b624b0(0x4e32);
    if (pDamage != 0)
        pDamage->FUN_141911e90(this, nValue, a, b, q);
    int nOwnerId = b;
    Unk_PCBaseWorldActor* pTarget = FUN_1403ed2d0()->FUN_141bd13a0(nOwnerId);
    if (pTarget != 0)
        nOwnerId = pTarget->FUN_141094f40();
    PCBase* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal != 0) {
        if (nOwnerId == pLocal->FUN_14123c580()) {
            UIDPSDialog* pLog = PCBaseDialog<UIDPSDialog>(0x4e44);
            if (pLog != 0) {
                if (pLog->FUN_1419299e0() != 0)
                    pLog->FUN_141929a00(nValue, a);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141674c60, PCBase, vfunc_111, 276, 0xDD2381FF);

// @0x141674d80
void PCBase::vfunc_112(void* p, int n)
{
    PCBase* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal != 0 && n == pLocal->FUN_14123c580()) {
        Unk_PCBaseTargetUI* pTargetUI = FUN_141531aa0(0x4e51);
        if (pTargetUI != 0)
            pTargetUI->FUN_1419df2a0(this);
    }
    Unk_PCBaseUpperHpBar* pUpper = FUN_14096e340(0x4e3d);
    if (pUpper != 0)
        pUpper->FUN_141b4c510(this, n);
    MS2Ptr<Unk_PCBaseComp_a58> spBar = vfunc_80();
    if (spBar.get() != 0) {
        if (spBar->FUN_141992160() == 0 && pLocal != 0)
            spBar->FUN_141992140(pLocal->FUN_14123c580() == n);
    }
}
MS2_REPLACE_METHOD(0x141674d80, PCBase, vfunc_112, 302, 0x0D7211D8);

// @0x141673b40
int PCBase::FUN_141673b40(MS2Ptr<Unk_PCBaseComp_b18> spItem)
{
    if (spItem.IsNull() || spItem->FUN_141759960() == 0)
        return 0;
    FUN_1417ea750(this, spItem);
    return 1;
}
MS2_REPLACE_METHOD(0x141673b40, PCBase, FUN_141673b40, 158, 0x65CBAB49);

// @0x141673bf0
MS2Ptr<Unk_PCBaseComp_b18> PCBase::FUN_141673bf0(__int64 nTagId, int nKind)
{
    for (POSITION pos = m_unk_8e8.GetHeadPosition(); pos != 0; m_unk_8e8.GetNext(pos)) {
        Unk_PCBaseComp_b18* pItem = m_unk_8e8.GetAt(pos).get();
        if (pItem->m_nTagId == nTagId && pItem->m_n8c == nKind)
            return MS2Ptr<Unk_PCBaseComp_b18>(pItem);
    }
    return MS2Ptr<Unk_PCBaseComp_b18>(0);
}
MS2_REPLACE_METHOD(0x141673bf0, PCBase, FUN_141673bf0, 231, 0x8DC370DA);

// @0x141673ce0
MS2Ptr<Unk_PCBaseComp_b18> PCBase::FUN_141673ce0(MS2Ptr<Unk_PCBaseComp_b18> spItem)
{
    if (FUN_141673bf0(spItem->m_nTagId, spItem->m_n8c).IsNull()) {
        m_unk_8e8.RemoveAll();
        m_unk_8e8.AddTail(spItem);
        return spItem;
    }
    return MS2Ptr<Unk_PCBaseComp_b18>(0);
}
MS2_REPLACE_METHOD(0x141673ce0, PCBase, FUN_141673ce0, 287, 0x81523824);

// @0x141673e10
MS2Ptr<Unk_PCBaseComp_b18> PCBase::FUN_141673e10(__int64 nTagId)
{
    for (POSITION pos = m_unk_8e8.GetHeadPosition(); pos != 0; m_unk_8e8.GetNext(pos)) {
        Unk_PCBaseComp_b18* pItem = m_unk_8e8.GetAt(pos).get();
        if (pItem->m_nTagId == nTagId)
            return MS2Ptr<Unk_PCBaseComp_b18>(pItem);
    }
    return MS2Ptr<Unk_PCBaseComp_b18>(0);
}
MS2_REPLACE_METHOD(0x141673e10, PCBase, FUN_141673e10, 206, 0x44C1FD7A);

// @0x141673ef0
int PCBase::FUN_141673ef0()
{
    if (m_spStateMgr.get() != 0) {
        if (m_spStateMgr->GetCur() == 0x10) {
            State* pState = m_spStateMgr->GetState();
            return FUN_1417e9330(pState);
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141673ef0, PCBase, FUN_141673ef0, 116, 0xAEB0C93F);

// @0x141673f70
void PCBase::FUN_141673f70(float a, float b, float c)
{
    CColorBoostData kData(a, b, c);
    m_colorBoost.FUN_14109be00(kData);
    Ridee* pRidee = FUN_1416764a0();
    if (pRidee != 0)
        pRidee->FUN_141673f70(a, b, c);
}
MS2_REPLACE_METHOD(0x141673f70, PCBase, FUN_141673f70, 156, 0xA481120A);

// @0x141674b60
efd::Point3 PCBase::FUN_141674b60(efd::Point3 kDir)
{
    float fYaw = 0;
    return FUN_141674a10(kDir, &fYaw);
}
MS2_REPLACE_METHOD(0x141674b60, PCBase, FUN_141674b60, 87, 0x56E1EF6F);

// @0x141674bc0
int PCBase::FUN_141674bc0()
{
    return static_cast<Unk_PCBaseBuffsEx*>(&m_unk_748)->FUN_140970990();
}
MS2_REPLACE_METHOD(0x141674bc0, PCBase, FUN_141674bc0, 33, 0xD3B461DE);

// @0x141675150
NiAVObject* PCBase::FUN_141675150(const CString& strNode)
{
    Ridee* pRidee;
    if (FUN_14123c660() != 0 && (pRidee = FUN_1416764a0()) != 0)
        return pRidee->FUN_141675150(strNode);
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0) {
        NiFixedString kName((const char*)strNode);
        return static_cast<NiAVObject*>(NiObject::DynamicCast(&DAT_143ad1588, pRoot->GetObjectByName(kName)));
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141675150, PCBase, FUN_141675150, 219, 0x54BDAE33);

// @0x141675240
unsigned int PCBase::FUN_141675240()
{
    return static_cast<Unk_PCBaseBuffsEx*>(&m_unk_748)->FUN_1409711c0();
}
MS2_REPLACE_METHOD(0x141675240, PCBase, FUN_141675240, 33, 0x084A2064);

// @0x1416757c0
efd::SmartPointer<NiAVObject> PCBase::FUN_1416757c0(CString strName)
{
    efd::SmartPointer<NiAVObject> spNode(0);
    if (m_unk_b88.IsEmpty())
        return spNode;
    m_unk_b88.Lookup(strName, spNode);
    return spNode;
}
MS2_REPLACE_METHOD(0x1416757c0, PCBase, FUN_1416757c0, 217, 0xE4622531);

// @0x1416758a0
efd::SmartPointer<NiAVObject> PCBase::FUN_1416758a0(CString strName)
{
    efd::SmartPointer<NiAVObject> spNode(0);
    m_unk_bb8.Lookup(strName, spNode);
    return spNode;
}
MS2_REPLACE_METHOD(0x1416758a0, PCBase, FUN_1416758a0, 136, 0xA990BF2D);

// @0x141675930
efd::SmartPointer<NiAVObject> PCBase::FUN_141675930()
{
    return m_spBE8;
}
MS2_REPLACE_METHOD(0x141675930, PCBase, FUN_141675930, 67, 0x12297BF2);

// @0x141675450
void PCBase::vfunc_119()
{
    m_unk_b88.RemoveAll();
    if (FUN_1409f7c90()->FUN_14109a9d0() != 0)
    {
        NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
        if (pRoot != 0)
        {
            for (int i = 0; i < 50; i++)
            {
                NiAVObject* pNode = pRoot->GetObjectByName(DAT_143ae5ce0[i]);
                if (pNode != 0)
                {
                    efd::SmartPointer<NiAVObject> spNode(pNode);
                    m_unk_b88.SetAt(FUN_140188f50(pNode->GetName(), 0), spNode);
                }
            }
            {
                NiFixedString kRide("Ride_A");
                m_spBE8 = pRoot->GetObjectByName(kRide);
            }
        }
    }
    else
    {
        NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
        if (pRoot != 0)
        {
            for (int i = 0; i < 50; i++)
            {
                CString strName;
                strName.Format("Hold_Point%02d", i);
                NiAVObject* pNode;
                {
                    NiFixedString kName(strName);
                    pNode = pRoot->GetObjectByName(kName);
                }
                if (pNode != 0)
                {
                    efd::SmartPointer<NiAVObject> spNode(pNode);
                    m_unk_b88.SetAt(FUN_140188f50(pNode->GetName(), 0), spNode);
                }
            }
            {
                NiFixedString kRide("Ride_A");
                m_spBE8 = pRoot->GetObjectByName(kRide);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141675450, PCBase, vfunc_119, 874, 0x7584E738);

// @0x141675980
void PCBase::FUN_141675980()
{
    m_unk_bb8.RemoveAll();
    if (FUN_1409f7c90()->FUN_14109a9d0() != 0)
    {
        NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
        if (pRoot != 0)
        {
            for (unsigned int i = 0; i < 9; i++)
            {
                for (unsigned int j = 0; j < 30; j++)
                {
                    NiAVObject* pNode = pRoot->GetObjectByName(DAT_143ae5470[i][j]);
                    if (pNode != 0)
                    {
                        efd::SmartPointer<NiAVObject> spNode(pNode);
                        m_unk_bb8.SetAt(FUN_140188f50(pNode->GetName(), 0), spNode);
                    }
                }
            }
        }
    }
    else
    {
        NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
        if (pRoot != 0)
        {
            for (unsigned int i = 0; i < 9; i++)
            {
                for (unsigned int j = 0; j < 30; j++)
                {
                    CString strName;
                    strName.Format("%s%02d", (const char*)s_partNames[i], j);
                    NiAVObject* pNode;
                    {
                        NiFixedString kName(strName);
                        pNode = pRoot->GetObjectByName(kName);
                    }
                    if (pNode != 0)
                    {
                        efd::SmartPointer<NiAVObject> spNode(pNode);
                        m_unk_bb8.SetAt(FUN_140188f50(pNode->GetName(), 0), spNode);
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141675980, PCBase, FUN_141675980, 831, 0x095AE68E);

// @0x141675cd0
int PCBase::FUN_141675cd0(const NiPoint3& kPos, CString strUnused, CString* pName, float* pDist)
{
    if (FUN_141675e60() == 0)
        return 0;
    *pDist = FLT_MAX;
    for (POSITION pos = m_unk_bb8.GetHeadPosition(); pos != 0; m_unk_bb8.GetNext(pos)) {
        CString strName = m_unk_bb8.GetKeyAt(pos);
        NiAVObject* pNode = m_unk_bb8.GetValueAt(pos);
        float fDist = (pNode->GetWorldTranslate() - kPos).Length();
        if (fDist < *pDist) {
            *pDist = fDist;
            *pName = strName;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141675cd0, PCBase, FUN_141675cd0, 382, 0x94FD3298);

// @0x141675e60
int PCBase::FUN_141675e60()
{
    return !m_unk_bb8.IsEmpty();
}
MS2_REPLACE_METHOD(0x141675e60, PCBase, FUN_141675e60, 62, 0xF082B080);

// @0x141675eb0
void* PCBase::FUN_141675eb0()
{
    return &m_pushControl;
}
MS2_REPLACE_METHOD(0x141675eb0, PCBase, FUN_141675eb0, 17, 0xEE253D79);

// @0x141676320
void PCBase::FUN_141676320(MS2Ptr<RideOnAction> spAction)
{
    m_spB00 = spAction;
}
MS2_REPLACE_METHOD(0x141676320, PCBase, FUN_141676320, 63, 0x5F552001);

// @0x141676370
MS2Ptr<RideOnAction> PCBase::FUN_141676370()
{
    return m_spB00;
}
MS2_REPLACE_METHOD(0x141676370, PCBase, FUN_141676370, 67, 0x77B23705);

// @0x1416763c0
int PCBase::FUN_1416763c0()
{
    if (m_spB10 == 0)
        return 0;
    return m_spB10->FUN_14123c580();
}
MS2_REPLACE_METHOD(0x1416763c0, PCBase, FUN_1416763c0, 73, 0x9715FB89);

// @0x141676500
int PCBase::FUN_141676500()
{
    if (m_spB10 == 0)
        return 0;
    return m_spB10->GetData()->m_nType == 1;
}
MS2_REPLACE_METHOD(0x141676500, PCBase, FUN_141676500, 158, 0x9A8E329D);

// @0x141676670
void PCBase::FUN_141676670(unsigned int nKey, int nValue)
{
    m_mapB28.SetAt(nKey, nValue);
}
MS2_REPLACE_METHOD(0x141676670, PCBase, FUN_141676670, 51, 0x3464AB17);

// @0x1416766b0
void PCBase::FUN_1416766b0(MS2Ptr<Unk_PCBaseComp_b18> spItem)
{
    m_spB18 = spItem;
}
MS2_REPLACE_METHOD(0x1416766b0, PCBase, FUN_1416766b0, 63, 0x3B963751);

// @0x141676700
void PCBase::FUN_141676700()
{
    m_mapB28.RemoveAll();
}
MS2_REPLACE_METHOD(0x141676700, PCBase, FUN_141676700, 33, 0x8B35E0E0);

// @0x141676730
void PCBase::FUN_141676730(unsigned int nKey)
{
    m_mapB28.RemoveKey(nKey);
}
MS2_REPLACE_METHOD(0x141676730, PCBase, FUN_141676730, 41, 0x5ACF4772);

// @0x141676760
int PCBase::FUN_141676760()
{
    return (int)m_mapB28.GetCount();
}
MS2_REPLACE_METHOD(0x141676760, PCBase, FUN_141676760, 33, 0xCAABD8C0);

// @0x141676790
int PCBase::FUN_141676790(unsigned int nKey)
{
    int nValue = 0;
    m_mapB28.Lookup(nKey, nValue);
    return nValue;
}
MS2_REPLACE_METHOD(0x141676790, PCBase, FUN_141676790, 58, 0xC1A3BF59);

// @0x1416767d0
NiPoint3 PCBase::FUN_1416767d0()
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0)
        return spRidee->vfunc_18();
    return vfunc_18();
}
MS2_REPLACE_METHOD(0x1416767d0, PCBase, FUN_1416767d0, 168, 0x794ABE09);

// @0x141676880
NiPoint3 PCBase::FUN_141676880()
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0)
        return spRidee->vfunc_20();
    return vfunc_20();
}
MS2_REPLACE_METHOD(0x141676880, PCBase, FUN_141676880, 168, 0xF147A9F0);

// @0x141676a10
void* PCBase::FUN_141676a10()
{
    return FUN_1403ed2d0()->FUN_141bd1200(m_unk_b70)->FUN_1409ffc60();
}
MS2_REPLACE_METHOD(0x141676a10, PCBase, FUN_141676a10, 46, 0xB9F2C777);

// @0x141676a50
void PCBase::FUN_141676a50(__int64 nUid, int n)
{
    FUN_141676980(n);
    FUN_1416769a0(nUid);
    m_mapCA8.SetAt(nUid, n);
}
MS2_REPLACE_METHOD(0x141676a50, PCBase, FUN_141676a50, 82, 0x230F5B7A);

// @0x141676ab0
void PCBase::FUN_141676ab0(__int64 nUid)
{
    FUN_141676980(0);
    FUN_1416769a0(0);
    m_mapCA8.RemoveKey(nUid);
}
MS2_REPLACE_METHOD(0x141676ab0, PCBase, FUN_141676ab0, 67, 0x8D619E4A);

// @0x141676b00
int PCBase::FUN_141676b00(__int64 nUid)
{
    return m_mapCA8.Lookup(nUid) != 0;
}
MS2_REPLACE_METHOD(0x141676b00, PCBase, FUN_141676b00, 70, 0xA2EC986C);

// Ride on: an unloaded actor only records the action; otherwise the ridee is created, bound to its riding row and
// registered in the world, the rider's stats are copied over and the ride-on effect is played.
// MS2-FUNCTIONAL: GameObject::vfunc_19/21 take efd::Point3 while vfunc_18/20 return NiPoint3 here (one slicing copy per
// call); in the exe both are the same type.
// @0x141676b90
void PCBase::vfunc_120(MS2Ptr<RideOnAction> spAction)
{
    if (spAction == 0)
        return;
    if (m_spB10 != 0)
        return;
    MS2Ptr<Unk_PCBaseComp_b18> spItem(0);
    if (spAction->m_nType == 1) {
        MS2Ptr<RideOnActionUseItem> spUse(dynamic_cast<RideOnActionUseItem*>(spAction.get()));
        if (spUse == 0)
            return;
        spItem.AssignRaw(new Unk_PCBaseComp_b18(spUse->m_n30, spUse->m_n38, spUse->m_look));
    }
    if (FUN_14123bea0() == 0) {
        FUN_141676320(spAction);
        FUN_1416766b0(spItem);
        return;
    }
    efd::SmartPointer<Ridee> spRidee = NiNew Ridee;
    if (spRidee->FUN_1417043a0(spAction->m_n1c, spAction->m_n20, this) == 0)
        return;
    spRidee->m_unk_158 = m_unk_158;
    spRidee->vfunc_19(vfunc_18());
    spRidee->vfunc_21(vfunc_20());
    spRidee->SetRider(this);
    m_spB10 = spRidee;
    FUN_141676320(spAction);
    FUN_1416766b0(spItem);
    for (int nKind = 0; nKind < 3; nKind++) {
        for (int nStat = 0; nStat < 0x23; nStat++)
            m_spB10->FUN_141670540(nKind, nStat, FUN_141670990(nKind, nStat));
    }
    FUN_1403ed2d0()->FUN_141bbb1e0(m_spB10, 0, 1);
    if (GetClassID() == 0x6200004)
        FUN_1409478c0()->FUN_140aeaf40(m_spB10, 0);
    if (vfunc_25() == 0) {
        Unk_PCBaseFxQuery kQuery;
        kQuery.m_strName = FUN_1401d31f0()->m_str2b0;
        kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
        kQuery.FUN_140a53190(FUN_14123c580());
        FUN_1403ed280()->FUN_1411a4a00(&kQuery);
    }
    int nHide = m_spB10->GetData()->m_n5c;
    if (nHide != 0)
        FUN_14166ca20(2);
    if (FUN_14166cb00(1))
        m_spB10->FUN_14166ca20(1);
    MS2Ptr<Unk_PCBaseComp_a78> spNameTag = vfunc_82();
    if (spNameTag.get())
        spNameTag->FUN_140f48d80();
    PC* pPC = FUN_140974230(this);
    if (pPC)
        pPC->FUN_1416642c0(spAction->m_b28);
}
MS2_REPLACE_METHOD(0x141676b90, PCBase, vfunc_120, 2127, 0x4D932F9C);

// Ride off: the rider takes the ridee's place (or keeps its own platform anchor when the ridee stood on a moving field
// object), the ridee is unregistered and released, and the rider falls or idles; then the ride-off effects.
// MS2-FUNCTIONAL: NiPoint3 and efd::Point3 are distinct here (slicing copies / a converting ctor where the exe copies
// the bytes); same calls, same order.
// @0x1416773f0
void PCBase::vfunc_121(MS2Ptr<RideOffAction> spAction)
{
    if (m_spB10 == 0) {
        FUN_141676320(MS2Ptr<RideOnAction>(0));
        FUN_1416766b0(MS2Ptr<Unk_PCBaseComp_b18>(0));
        return;
    }
    m_spB10->FUN_1417058b0();
    efd::Point3 kPos = m_spB10->vfunc_18();
    NiPoint3 kDir = m_spB10->vfunc_20();
    int bFall = 1;
    FUN_141678300(m_spB10->FUN_1416782e0());
    Unk_PCBaseBody* pBody = m_spB10->FUN_14166d220();
    if (pBody != 0) {
        efd::SmartPointer<egf::Entity> spEntity(pBody->FUN_141240f20()->FUN_140cfaff0());
        if (spEntity != 0) {
            FUN_14166d220()->FUN_141240f20()->FUN_140cfb020(spEntity);
            MS2Ptr<Unk_RideeFieldObj> spObj = FUN_1403ed2d0()->FUN_141bc4f10(spEntity);
            if (spObj.get()) {
                if (m_spB10->FUN_141671a30() != 0)
                    kPos.z = spObj->FUN_140adf8e0().z + spObj->FUN_140ae0660().z + 10.0f;
                egf::EntityID kId(egf::kENTITY_INVALID);
                NiPoint3 kOffset = efd::Point3::ZERO;
                m_spB10->FUN_141678240(kId, kOffset);
                FUN_141678290(kId, kOffset);
                bFall = 0;
            }
        }
    }
    vfunc_19(kPos);
    vfunc_21(kDir);
    FUN_14166d8b0(kDir.z);
    NiAVObject* pNode = FUN_141b6ef70(FUN_14123c460());
    if (pNode != 0) {
        NiMatrix3 kRot;
        FUN_140b86230(kDir, kRot);
        pNode->SetTranslate(kPos);
        pNode->SetRotate(kRot);
    }
    efd::Point3 kRideePos = m_spB10->FUN_141676020();
    if (FUN_1403ed2d0()->FUN_141bd0fa0(m_spB10->FUN_14123c460()) != 0)
        FUN_1403ed2d0()->FUN_141bbb7f0(m_spB10, 0);
    if (GetClassID() == 0x6200004)
        FUN_1409478c0()->FUN_140aeaf40(this, 0);
    int bGround = m_spB10->FUN_141671a30();
    CString strEffect("");
    if (spAction.get() && spAction->m_nType == 0x18) {
        bool bEffect = !m_spB10->GetData()->m_strE8.IsEmpty();
        if (bEffect)
            strEffect = m_spB10->GetData()->m_strE8;
    }
    int nHide = m_spB10->GetData()->m_n5c;
    if (nHide != 0)
        FUN_14166ca80(2);
    m_spB10 = 0;
    FUN_141676320(MS2Ptr<RideOnAction>(0));
    FUN_1416766b0(MS2Ptr<Unk_PCBaseComp_b18>(0));
    FUN_14166d220()->FUN_141240730();
    if (bGround == 0) {
        FUN_14166d220()->FUN_141241070();
        vfunc_59(5, new StateFallData(kRideePos), 0, 0);
    }
    else {
        vfunc_59(1, 0, 0, 0);
    }
    if (vfunc_25() == 0) {
        Unk_PCBaseFxQuery kQuery;
        kQuery.m_strName = FUN_1401d31f0()->m_str2b8;
        kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
        kQuery.FUN_140a53190(FUN_14123c580());
        FUN_1403ed280()->FUN_1411a4a00(&kQuery);
    }
    if (!strEffect.IsEmpty()) {
        Unk_PCBaseFxQuery kQuery;
        kQuery.m_strName = strEffect;
        kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
        kQuery.FUN_140a53190(FUN_14123c580());
        FUN_1403ed280()->FUN_1411a4a00(&kQuery);
    }
    FUN_141676700();
    MS2Ptr<Unk_PCBaseComp_a78> spNameTag = vfunc_82();
    if (spNameTag.get())
        spNameTag->FUN_140f48d80();
}
MS2_REPLACE_METHOD(0x1416773f0, PCBase, vfunc_121, 2878, 0x41C13759);

// @0x141678160
void PCBase::FUN_141678160(const NiPoint3& kPos)
{
    m_posBF4 = kPos;
}
MS2_REPLACE_METHOD(0x141678160, PCBase, FUN_141678160, 43, 0x6EE29682);

// @0x141678240
void PCBase::FUN_141678240(egf::EntityID& kId, NiPoint3& kPos)
{
    kId = m_unk_ae0;
    kPos = m_posAE8;
}
MS2_REPLACE_METHOD(0x141678240, PCBase, FUN_141678240, 72, 0x119736F1);

// @0x141678290
void PCBase::FUN_141678290(egf::EntityID kId, NiPoint3 kPos)
{
    m_posAE8 = kPos;
    m_unk_ae0 = kId;
}
MS2_REPLACE_METHOD(0x141678290, PCBase, FUN_141678290, 72, 0xE8669FA0);

// @0x141678680
unsigned int PCBase::FUN_141678680()
{
    unsigned int nMask = static_cast<Unk_PCBaseBuffsEx*>(&m_unk_748)->FUN_140970bf0();
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField.get() != 0)
        nMask |= spField->m_nSkillUseDisableMask;
    return nMask;
}
MS2_REPLACE_METHOD(0x141678680, PCBase, FUN_141678680, 130, 0x482C383A);

// @0x1416787a0
int PCBase::FUN_1416787a0()
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0)
        return 0;
    return spField->m_nMapType;
}
MS2_REPLACE_METHOD(0x1416787a0, PCBase, FUN_1416787a0, 116, 0xE689F429);

// @0x141678820
int PCBase::FUN_141678820()
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0)
        return 0;
    if (spField->m_nCheckClimb == 0)
        return 0;
    return m_unk_c68;
}
MS2_REPLACE_METHOD(0x141678820, PCBase, FUN_141678820, 157, 0xB74623DA);

// @0x1416790b0
const char* PCBase::vfunc_123(int n)
{
    return m_spD00->vfunc_5(n);
}
MS2_REPLACE_METHOD(0x1416790b0, PCBase, vfunc_123, 105, 0x3D3A5EA7);

// @0x141679120
void PCBase::FUN_141679120(int n)
{
    m_spD00->vfunc_4(n);
}
MS2_REPLACE_METHOD(0x141679120, PCBase, FUN_141679120, 62, 0x06B74A69);

// @0x141679170
efd::utf8string PCBase::FUN_141679170(int a, int b)
{
    return efd::utf8string((const char*)m_spD00->vfunc_6(a, b));
}
MS2_REPLACE_METHOD(0x141679170, PCBase, FUN_141679170, 167, 0x25DB4066);

// @0x14166de90
bool PCBase::FUN_14166de90(int nKey, unsigned int nSeq)
{
    Unk_PCBaseAnimSvc* pSvc = FUN_141b6f910();
    if (pSvc == 0)
        return false;
    std::map<CString, std::vector<unsigned int> >& kByName = m_mapCF0[nKey];
    CString strPrefix = vfunc_60();
    std::vector<unsigned int>& kIds = kByName[strPrefix];
    if (kIds.empty()) {
        std::vector<CString>* pNames = m_spD00->vfunc_7(nKey);
        if (pNames->empty())
            return false;
        for (size_t i = 0; i < pNames->size(); ++i) {
            unsigned int nId = FUN_141679270((*pNames)[i]);
            if (nId != NiActorManager::INVALID_SEQUENCE_ID)
                kIds.push_back(nId);
        }
    }
    return std::find(kIds.begin(), kIds.end(), nSeq) != kIds.end();
}
MS2_REPLACE_METHOD(0x14166de90, PCBase, FUN_14166de90, 511, 0xCC0FDC50);

// @0x141679270
unsigned int PCBase::FUN_141679270(const char* szName)
{
    Unk_PCBaseAnimSvc* pSvc = FUN_141b6f910();
    if (pSvc == 0)
        return NiActorManager::INVALID_SEQUENCE_ID;
    CString strPrefix = vfunc_60();
    CString strName;
    if (!strPrefix.IsEmpty())
        strName = FUN_14038f6d0(strPrefix, szName);
    else
        strName = szName;
    unsigned int nId = pSvc->FUN_140999490(FUN_14123c460(), (const char*)strName);
    if (nId == NiActorManager::INVALID_SEQUENCE_ID && !strPrefix.IsEmpty())
        nId = pSvc->FUN_140999490(FUN_14123c460(), szName);
    return nId;
}
MS2_REPLACE_METHOD(0x141679270, PCBase, FUN_141679270, 463, 0x55F4C7F1);

// @0x1416795e0
void PCBase::FUN_1416795e0()
{
    if (m_unk_c48 == 0)
        return;
    if (m_spStateMgr->GetCur() == 0x21 && m_spB10 != 0)
        m_spB10->vfunc_59(m_unk_c48, m_unk_c50.get(), m_unk_c60, m_unk_c64);
    else
        m_spStateMgr->FUN_1417dafa0(m_unk_c48, m_unk_c50.get(), m_unk_c60, m_unk_c64);
    m_unk_c48 = 0;
    m_unk_c50 = 0;
    m_unk_c60 = 0;
    m_unk_c64 = 0;
}
MS2_REPLACE_METHOD(0x1416795e0, PCBase, FUN_1416795e0, 373, 0xA091CF77);

// @0x141679760
void PCBase::FUN_141679760()
{
    m_spD00 = FUN_1414a5860()->FUN_1409494e0(vfunc_57());
    m_mapCF0.clear();
}
MS2_REPLACE_METHOD(0x141679760, PCBase, FUN_141679760, 140, 0xB20F089E);

// @0x141679e00
void PCBase::FUN_141679e00()
{
    for (unsigned int i = 0; i < m_arrA30.GetCount(); ++i)
    {
        unsigned int nHandle = m_arrA30[i];
        FUN_1403ed280()->FUN_1411a6060(nHandle);
    }
    m_arrA30.RemoveAll();
}
MS2_REPLACE_METHOD(0x141679e00, PCBase, FUN_141679e00, 137, 0x85FE2DC4);

// @0x141679e90
void PCBase::FUN_141679e90()
{
    for (size_t i = 0; i < m_vecD28.size(); ++i)
        FUN_1403ed280()->FUN_1411a6060(m_vecD28[i]);
    m_vecD28.clear();
    m_unk_d20 = 0;
}
MS2_REPLACE_METHOD(0x141679e90, PCBase, FUN_141679e90, 149, 0xC892B3AB);

// @0x141679f30
void PCBase::FUN_141679f30()
{
    if (m_sp638.get() != 0)
        m_sp638->FUN_141848650();
    m_timer9e8.FUN_1408687f0();
    FUN_141679e00();
}
MS2_REPLACE_METHOD(0x141679f30, PCBase, FUN_141679f30, 94, 0x69BC8436);

// @0x141676310
void PCBase::FUN_141676310(int n)
{
}
MS2_REPLACE_METHOD(0x141676310, PCBase, FUN_141676310, 10, 0x96F6F902);

// @0x141678750
MS2Ptr<CStateManager> PCBase::GetStateMgr()
{
    return m_spStateMgr;
}
MS2_REPLACE_METHOD(0x141678750, PCBase, GetStateMgr, 67, 0xE1DD1C3D);

// @0x141679220
bool PCBase::FUN_141679220(const char* szName)
{
    unsigned int nId = FUN_141679270(szName);
    return nId != NiActorManager::INVALID_SEQUENCE_ID;
}
MS2_REPLACE_METHOD(0x141679220, PCBase, FUN_141679220, 73, 0x7A70E4CC);

// @0x1416765b0
int PCBase::FUN_1416765b0()
{
    if (FUN_1416764a0() != 0)
        return (int)m_mapB28.GetCount() < FUN_1416764a0()->GetData()->m_seats.FUN_140784180();
    else
        return 0;
}
MS2_REPLACE_METHOD(0x1416765b0, PCBase, FUN_1416765b0, 181, 0x26DE6170);

// @0x141676060
void PCBase::FUN_141676060(NiPoint3 kPos)
{
    if (kPos != efd::Point3::ZERO && m_posC10 != efd::Point3::ZERO)
        return;
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee)
        spRidee->FUN_141676060(kPos);
    else
        m_posC10 = kPos;
}
MS2_REPLACE_METHOD(0x141676060, PCBase, FUN_141676060, 210, 0xAEE43850);

// @0x14166ebf0
void PCBase::FUN_14166ebf0(PCBase* pOther)
{
    if (pOther == 0)
        return;
    NiPoint3 kPos = pOther->m_posAE8;
    egf::EntityID kId = pOther->m_unk_ae0;
    if (kId != egf::kENTITY_INVALID) {
        egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_unk_ae0);
        if (pEntity == 0)
            return;
        FUN_1409618c0(pEntity, 0xfd95ca52, kPos);
        FUN_141678290(kId, kPos);
    }
}
MS2_REPLACE_METHOD(0x14166ebf0, PCBase, FUN_14166ebf0, 268, 0x8CB8826E);

// @0x14166ed70
void PCBase::FUN_14166ed70(int nEmotion)
{
    MS2Ptr<Unk_EmoRow> spRow = FUN_1401958b0()->FUN_1407ee1d0(nEmotion);
    if (spRow == 0)
        return;
    if (FUN_14166c930() == 0xb) {
        Unk_PCBaseState0b* pState = static_cast<Unk_PCBaseState0b*>(FUN_14166ccb0());
        if (pState->FUN_14167f950() == spRow->FUN_1407e9cb0())
            return;
    }
    vfunc_59(0xb, new StateEmotionData(nEmotion), 0, 1);
}
MS2_REPLACE_METHOD(0x14166ED70, PCBase, FUN_14166ed70, 396, 0x285198E6);

// @0x14166ef10
void PCBase::FUN_14166ef10(const CString& str, int nA, int nB, bool bC)
{
    if (!m_b9d0)
        return;
    if (m_spD10 == 0)
        return;
    {
        MS2Ptr<Unk_PCBaseFxSet> spSet = m_spD10->vfunc_2((void*)&str);
        if (spSet == 0)
            return;
        if (nB == 0 && m_str9e0 == str)
            return;
        FUN_141679fa0();
        FUN_141679f30();
        vfunc_72();
        m_str9e0 = str;
        m_timer9e8.FUN_1408687c0();
        vfunc_71(spSet);
        if (spSet->m_sp30.get() != 0) {
            if (m_sp638 == 0)
                m_sp638.AssignRaw(new Unk_PCBaseEmoPlayer(this));
            m_sp638->FUN_1418484a0(spSet->m_sp30, m_spD10->vfunc_1());
        }
        if (m_unk_a50 != 0 && nA != 0) {
            for (unsigned int i = 0; i < spSet->m_arrEffects.GetCount(); i++) {
                Unk_PCBaseFxQuery kQuery;
                kQuery.m_strName = spSet->m_arrEffects[i];
                kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
                kQuery.FUN_140a53190(FUN_14123c580());
                kQuery.m_bEmotion = bC;
                unsigned int nHandle = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
                m_arrA30.Add(nHandle);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14166EF10, PCBase, FUN_14166ef10, 1117, 0x56C2592F);

// @0x141679450
void PCBase::vfunc_53(float f)
{
    GameObject::vfunc_53(f);
    FUN_14166f940();
    m_spStateMgr->FUN_1417daaa0(f);
    m_colorBoost.FUN_14109be30(FUN_14123c460());
    bool bMoved = false;
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee)
        bMoved = m_pushControl.vfunc_1(spRidee, f);
    else
        bMoved = m_pushControl.vfunc_1(this, f);
    if (bMoved)
        vfunc_110();
    m_unk_748.FUN_140970420(f);
}
MS2_REPLACE_METHOD(0x141679450, PCBase, vfunc_53, 383, 0x2D2ECE5C);

// @0x141679800
GameObject* PCBase::FUN_141679800(CAtlArray<efd::SmartPointer<GameObject> >& arrTargets, float fAngle, efd::Point3 kDir, int nMode)
{
    GameObject* pBest = 0;
    float fBest = -1.0f;
    GameObject* pBestDead = 0;
    float fBestDead = -1.0f;
    for (unsigned int i = 0; i < arrTargets.GetCount(); i++)
    {
        GameObject* pTarget = arrTargets[i];
        efd::Point3 kTo = pTarget->vfunc_18() - vfunc_18();
        kTo.z = 0.0f;
        kTo.Unitize();
        float fDot = kDir.Dot(kTo);
        if (fDot < cos(((fAngle / 2.0f) * 3.1415927f) / 180.0f))
            continue;
        {
            int nDead = 0;
            PCBase* pPC = FUN_1409ffd30(pTarget);
            if (pPC != 0)
                nDead = pPC->FUN_14166ce30();
            if (nDead != 0)
            {
                int bPick = 0;
                if (nMode == 0)
                {
                    if (fBestDead < fDot)
                        bPick = 1;
                }
                else if (nMode == 3 && (fBestDead > fDot || FUN_14028d470(fBestDead, -1.0f)))
                    bPick = 1;
                if (bPick)
                {
                    fBestDead = fDot;
                    pBestDead = pTarget;
                }
            }
            else
            {
                int bPick = 0;
                if (nMode == 0)
                {
                    if (fBest < fDot)
                        bPick = 1;
                }
                else if (nMode == 3 && (fBest > fDot || FUN_14028d470(fBest, -1.0f)))
                    bPick = 1;
                if (bPick)
                {
                    fBest = fDot;
                    pBest = pTarget;
                }
            }
        }
    }
    if (pBest == 0)
        return pBestDead;
    return pBest;
}
MS2_REPLACE_METHOD(0x141679800, PCBase, FUN_141679800, 707, 0xB9D64A5E);

// @0x141679ad0
GameObject* PCBase::FUN_141679ad0(CAtlArray<efd::SmartPointer<GameObject> >& arrTargets, float fAngle, efd::Point3 kDir, int nMode)
{
    GameObject* pBest = 0;
    float fBest = -1.0f;
    GameObject* pBestDead = 0;
    float fBestDead = -1.0f;
    for (unsigned int i = 0; i < arrTargets.GetCount(); i++)
    {
        GameObject* pTarget = arrTargets[i];
        NiPoint3 kPos = pTarget->vfunc_30(this);
        efd::Point3 kTo = kPos - vfunc_18();
        kTo.z = 0.0f;
        kTo.Unitize();
        float fDot = kDir.Dot(kTo);
        if (fDot < cos(((fAngle / 2.0f) * 3.1415927f) / 180.0f))
            continue;
        {
            float fDist = FUN_140966f00(kPos, vfunc_18());
            int nDead = 0;
            PCBase* pPC = FUN_1409ffd30(pTarget);
            if (pPC != 0)
                nDead = pPC->FUN_14166ce30();
            if (nDead != 0)
            {
                int bPick = 0;
                if (nMode == 2)
                {
                    if (fBestDead < fDist)
                        bPick = 1;
                }
                else if (nMode == 1 && (fBestDead > fDist || FUN_14028d470(fBestDead, -1.0f)))
                    bPick = 1;
                if (bPick)
                {
                    fBestDead = fDist;
                    pBestDead = pTarget;
                }
            }
            else
            {
                int bPick = 0;
                if (nMode == 2)
                {
                    if (fBest < fDist)
                        bPick = 1;
                }
                else if (nMode == 1 && (fBest > fDist || FUN_14028d470(fBest, -1.0f)))
                    bPick = 1;
                if (bPick)
                {
                    fBest = fDist;
                    pBest = pTarget;
                }
            }
        }
    }
    if (pBest == 0)
        return pBestDead;
    return pBest;
}
MS2_REPLACE_METHOD(0x141679ad0, PCBase, FUN_141679ad0, 807, 0x7FC7CEBC);

// @0x141679fa0
// MS2-FUNCTIONAL: pointer locals get other frame slots (the exe copies the "FA_Skin" child into a second slot); same calls and stores.
void PCBase::FUN_141679fa0()
{
    if (FUN_1409f7c90()->FUN_14109a9d0() != 0) {
        if (!m_spC38) {
            NiActorManager* pActor = FUN_141b6f910()->FUN_140999440(FUN_14123c460());
            NiAVObject* pRoot;
            if (pActor != 0 && (pRoot = pActor->GetNIFRoot()) != 0)
                m_spC38 = pRoot->GetObjectByName("FA_Skin");
        }
        if (m_spC38) {
            NiFloatsExtraData* pData = NiDynamicCast(NiFloatsExtraData, m_spC38->GetExtraData(DAT_143ae50f8));
            if (pData == 0) {
                m_afA20[0] = 0.0f;
                m_afA20[1] = 0.0f;
                m_afA20[2] = 0.0f;
                m_afA20[3] = 0.0f;
                pData = NiNew NiFloatsExtraData(4, m_afA20);
                m_spC38->AddExtraData(DAT_143ae50f8, pData);
            } else {
                m_afA20[0] = pData->GetValue(0);
                m_afA20[1] = pData->GetValue(1);
                m_afA20[2] = pData->GetValue(2);
                m_afA20[3] = pData->GetValue(3);
            }
        }
    } else {
        NiActorManager* pActor = FUN_141b6f910()->FUN_140999440(FUN_14123c460());
        NiAVObject* pRoot;
        if (pActor != 0 && (pRoot = pActor->GetNIFRoot()) != 0) {
            NiAVObject* pSkin = pRoot->GetObjectByName("FA_Skin");
            if (pSkin != 0) {
                NiFloatsExtraData* pData = NiDynamicCast(NiFloatsExtraData, pSkin->GetExtraData(DAT_143ae50f8));
                if (pData == 0) {
                    m_afA20[0] = 0.0f;
                    m_afA20[1] = 0.0f;
                    m_afA20[2] = 0.0f;
                    m_afA20[3] = 0.0f;
                    NiExtraData* pNew = NiNew NiFloatsExtraData(4, m_afA20);
                    pSkin->AddExtraData(DAT_143ae50f8, pNew);
                } else {
                    m_afA20[0] = pData->GetValue(0);
                    m_afA20[1] = pData->GetValue(1);
                    m_afA20[2] = pData->GetValue(2);
                    m_afA20[3] = pData->GetValue(3);
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141679FA0, PCBase, FUN_141679fa0, 1479, 0xF07072FF);

// @0x141671c20
void PCBase::FUN_141671c20(MS2Ptr<CDamageRecord> spRecord)
{
    if (spRecord == 0)
        return;
    Unk_PCBaseSkillLevel* pLevel = spRecord->FUN_14175a8b0();
    if (pLevel == 0)
        return;
    if (pLevel->m_168.FUN_1407e0f40() != 0) {
        if (FUN_1403ed2d0()->FUN_141bd7230(vfunc_18()))
            return;
        unsigned int nCount = spRecord->m_arrDamage.GetCount();
        if (nCount > 0) {
            __int64 nTotal = 0;
            for (unsigned int i = 0; i < nCount; i++) {
                nTotal += spRecord->m_arrDamage[i];
                efd::Point3 kPos = spRecord->m_kPos;
                vfunc_111(reinterpret_cast<void*>(spRecord->m_arrDamage[i]), spRecord->m_arrTypes[i], spRecord->m_n2c, &kPos);
            }
            vfunc_112(reinterpret_cast<void*>(nTotal), spRecord->m_n2c);
        }
    }
    else if (spRecord->FUN_14175a820()->FUN_1407e9a60() == 0x12) {
        for (unsigned int i = 0; i < spRecord->m_arrDamage.GetCount(); i++) {
            int nType = spRecord->m_arrTypes[i];
            if (nType == 2) {
                Unk_PCBaseFxQuery kQuery;
                kQuery.m_strName = FUN_1401d3200()->m_8350.FUN_140298f80();
                kQuery.m_nPlayer = 0;
                kQuery.FUN_140a53190(FUN_14123c580());
                FUN_1403ed280()->FUN_1411a4a00(&kQuery);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141671c20, PCBase, FUN_141671c20, 1004, 0x393C4E4D);

// @0x141672020
void PCBase::FUN_141672020(MS2Ptr<CDotDamageRecord> spRecord)
{
    if (spRecord == 0)
        return;
    if (FUN_1403ed2d0()->FUN_141bd7230(vfunc_18()))
        return;
    efd::Point3 kZero = efd::Point3::ZERO;
    vfunc_111(spRecord->FUN_14175ac30(), spRecord->FUN_14175b130(), spRecord->m_n2c, &kZero);
    vfunc_112(spRecord->FUN_14175ac30(), spRecord->m_n2c);
}
MS2_REPLACE_METHOD(0x141672020, PCBase, FUN_141672020, 412, 0xA04BB489);

// @0x1416721d0
void PCBase::FUN_1416721d0(MS2Ptr<CSplashDamageRecord> spRecord)
{
    if (spRecord == 0)
        return;
    Unk_PCBaseSkillLevel* pLevel = spRecord->FUN_14175a8b0();
    if (pLevel == 0)
        return;
    if (pLevel->m_168.FUN_1407e0f40() != 0) {
        if (FUN_1403ed2d0()->FUN_141bd7230(vfunc_18()))
            return;
        __int64 nTotal = 0;
        unsigned int nCount = spRecord->m_arrDamage.GetCount();
        if (nCount > 0) {
            for (unsigned int i = 0; i < nCount; i++) {
                nTotal += spRecord->m_arrDamage[i];
                efd::Point3 kZero = efd::Point3::ZERO;
                vfunc_111(reinterpret_cast<void*>(spRecord->m_arrDamage[i]), spRecord->m_arrTypes[i], spRecord->m_n2c, &kZero);
            }
            vfunc_112(reinterpret_cast<void*>(nTotal), spRecord->m_n2c);
        }
    }
    else if (spRecord->FUN_14175a820()->FUN_1407e9a60() == 0x12) {
        for (unsigned int i = 0; i < spRecord->m_arrDamage.GetCount(); i++) {
            int nType = spRecord->m_arrTypes[i];
            if (nType == 2) {
                Unk_PCBaseFxQuery kQuery;
                kQuery.m_strName = FUN_1401d3200()->m_8350.FUN_140298f80();
                kQuery.m_nPlayer = 0;
                kQuery.FUN_140a53190(FUN_14123c580());
                FUN_1403ed280()->FUN_1411a4a00(&kQuery);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1416721d0, PCBase, FUN_1416721d0, 997, 0x69395726);

// @0x1416725c0
int PCBase::FUN_1416725c0(NiPoint3& kDir, float fDist, float fHeight, float fUp)
{
    kDir.Unitize();
    if (kDir == efd::Point3::ZERO)
        return 0;
    NiPoint3 kPos = vfunc_18();
    kPos.z += fUp;
    efd::Point3 kHit = efd::Point3::ZERO;
    if (fDist < 0.0f) {
        static_cast<efd::Point3&>(kDir) = kDir * -1.0f;
        fDist = fDist * -1.0f;
    }
    NiPoint3 kFlat = kDir;
    kFlat.z = 0.0f;
    if (FUN_1409f7ca0()->FUN_14168a230(kPos, kHit, kDir, fDist, 0))
        return 0;
    if (FUN_1409f7ca0()->FUN_14168a230(kPos, kHit, kFlat, fDist, 0))
        return 0;
    static_cast<efd::Point3&>(kPos) = kPos + kDir * fDist + efd::Point3(0.0f, 0.0f, 10.0f);
    float fGround = 0.0f;
    if (FUN_1409f7ca0()->FUN_14168a450(kPos, &fGround, 10.0f + fHeight + 1.0f))
        return 0;
    kPos.x += 0.1f;
    kPos.y += 0.05f;
    if (FUN_1409f7ca0()->FUN_14168a450(kPos, &fGround, 10.0f + fHeight + 1.0f))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1416725c0, PCBase, FUN_1416725c0, 841, 0xACCFEB93);

// @0x141677f40
int PCBase::FUN_141677f40(PCBase* pActor)
{
    efd::SmartPointer<Ridee> spRidee = FUN_141468360(pActor);
    if (spRidee) {
        PCBase* pRider = spRidee->GetRider();
        PCBase* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
        MS2Ptr<Unk_RideeData> spData = spRidee->GetData();
        if ((spData.get() ? true : false) && pLocal != 0 && pRider != 0) {
            if (pLocal->FUN_14123c580() == pRider->FUN_14123c580() && spData->m_n88 == 0) {
                if (spRidee->FUN_1417075e0() == 0) {
                    MS2Ptr<RideOffAction> spAction(new RideOffAction(1));
                    if (static_cast<MyPC*>(pLocal)->SendRequestRideMode1(spAction.get()) == 0)
                        return 0;
                    return 1;
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE(0x141677f40, PCBase::FUN_141677f40, 523, 0x3E530166);

// @0x141678360
void PCBase::FUN_141678360()
{
    if (m_unk_c04 != 0)
    {
        float fRange = 50.0f;
        Unk_PCBaseRayHit kRay;
        efd::Point3 kFrom = vfunc_18() + efd::Point3(0.0f, 0.0f, 50.0f);
        efd::Point3 kHit = efd::Point3::ZERO;
        efd::Point3 kNormal = efd::Point3::ZERO;
        int nHit = FUN_1409f7ca0()->FUN_14168a310(kFrom, &kHit, &kRay, 50.0f, &kNormal, 0);
        if (nHit != 0 && kRay.m_hitEntity != 0)
        {
            if (kRay.m_hitEntity->GetEntityID() != FUN_14166d220()->FUN_141240f20()->FUN_140cfaf70())
            {
                MS2Ptr<Unk_RideeFieldObj> spObj = FUN_1403ed2d0()->FUN_141bc4f10(kRay.m_hitEntity);
                if (spObj.get())
                {
                    efd::Point3 kNormalUp = spObj->FUN_140ae0150();
                    if (kNormalUp.z > 0.0f && kRay.m_hitDist <= 50.0f)
                    {
                        spObj->FUN_140ae0190();
                        efd::Point3 kPos = kRay.m_hitPoint;
                        kPos.z = spObj->FUN_140adf8e0().z + spObj->FUN_140ae0660().z + 10.0f;
                        vfunc_19(kPos);
                        FUN_14166d220()->FUN_141240f20()->FUN_140cfb020(kRay.m_hitEntity);
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141678360, PCBase, FUN_141678360, 786, 0x4E893F00);

// @0x1416788d0
void PCBase::FUN_1416788d0()
{
    if (FUN_1403ed2d0()->FUN_141bdb660(1) != 0) {
        if (m_timerC70.FUN_140868c00()) {
            FUN_1412751f0(FUN_1409eec40(0x5f), 1, 1);
            {
                CString strArg("");
                FUN_141276180(DAT_143ae32c8, strArg);
            }
            m_timerC70.FUN_140868750(1000);
        }
    }
    else {
        Unk_InventorySkillRequest kReq(0x1312d0b, 1);
        kReq.origin = vfunc_18();
        kReq.fValue = FUN_14166da40();
        MS2Ptr<CSkillRecord> spSkill(new CSkillRecord);
        if (spSkill->FUN_1417595d0(kReq))
            vfunc_102(spSkill);
    }
}
MS2_REPLACE_METHOD(0x1416788d0, PCBase, FUN_1416788d0, 504, 0xE79706B1);

// @0x141674020
void PCBase::vfunc_107(MS2Ptr<CDamageRecord> spRecord, float fScale)
{
    if (FUN_14028d470(fScale, 0.0f))
        return;
    if (static_cast<Unk_PCBaseBuffsEx*>(&m_unk_748)->FUN_140970c10(spRecord->FUN_14175a8b0(), 1) != 0)
        return;
    if (spRecord->FUN_14175ac30() == 0)
        return;
    Unk_PCBaseSkillLevel* pLevel = spRecord->FUN_14175a8b0();
    if (pLevel == 0)
        return;
    int nKind = pLevel->m_168.FUN_1407e0f90(FUN_1403ed2d0()->FUN_141bd3060());
    if (nKind == 0)
        return;
    if (m_pushControl.m_kDir != efd::Point3::ZERO && m_pushControl.m_nPriority >= pLevel->m_nPushPriority)
        return;
    float fSpeed = FUN_14028d3a0(pLevel->m_fPushDistance);
    efd::Point3 kDir;
    if (nKind == 2) {
        kDir = spRecord->m_kOrigin - vfunc_18();
    }
    else if (nKind == 1) {
        kDir = vfunc_18() - spRecord->m_kOrigin;
    }
    else if (nKind == 5) {
        if (spRecord->m_kPushDir == efd::Point3::ZERO) {
            Unk_PCBaseWorldObj* pAttacker = FUN_1403ed2d0()->FUN_141bd1200(spRecord->m_n2c);
            if (pAttacker)
                kDir = pAttacker->FUN_14123cc20();
        }
        else {
            kDir = spRecord->m_kPushDir;
        }
    }
    else if (nKind == 6) {
        efd::Point3 kFacing = spRecord->m_kFacing;
        efd::Point3 kForward;
        efd::Point3 kRight;
        FUN_140a01250(kFacing, &kForward, &kRight);
        kDir = -kForward;
    }
    kDir.Unitize();
    spRecord->m_kPushDir = kDir;
    fSpeed *= fScale;
    if (nKind == 2) {
        Unk_PCBaseWorldObj* pAttacker = FUN_1403ed2d0()->FUN_141bd1200(spRecord->m_n2c);
        if (pAttacker)
            fSpeed = FUN_140a0fde0((FUN_140966f00(pAttacker->vfunc_18(), vfunc_18()) - 150.0f) * 0.01f, fSpeed);
    }
    else if (nKind == 4) {
        spRecord->m_kPushDir = spRecord->m_kOrigin - vfunc_18();
        spRecord->m_kPushDir.z = 0.0f;
        fSpeed = FUN_14028d3a0(spRecord->m_kPushDir.Length());
        spRecord->m_kPushDir.Unitize();
    }
    if (FUN_14028d470(fSpeed, 0.0f))
        return;
    m_pushControl.FUN_1413fcf90();
    m_pushControl.m_kDir = spRecord->m_kPushDir;
    m_pushControl.m_fSpeed = fSpeed;
    m_pushControl.m_f28 = pLevel->m_fPush1d0;
    m_pushControl.m_f2c = 0.0f;
    m_pushControl.m_b30 = pLevel->m_fPush1e0 != 0.0f ? 1 : 0;
    m_pushControl.m_n34 = pLevel->m_nPush1e8;
    m_pushControl.m_nPriority = pLevel->m_nPushPriority;
    m_pushControl.FUN_1413fd050(pLevel->m_nPushCurve);
}
MS2_REPLACE_METHOD(0x141674020, PCBase, vfunc_107, 1821, 0x048E418F);

// @0x141674750
void PCBase::vfunc_106(const efd::Point3& kMove, double dTime, int nFlags)
{
    if (m_unk_150 != 0)
    {
        efd::Point3 kOld = m_unk_150->FUN_14123fd90();
        if (!FUN_140a33ff0(kMove))
            m_unk_150->FUN_14123ff80(efd::Point3::ZERO, nFlags);
        else
            m_unk_150->FUN_14123ff80(kMove, nFlags);
        efd::Point3 kNew = m_unk_150->FUN_14123fd90();
        if (!FUN_140a33ff0(kNew))
        {
            vfunc_19(kOld);
            kNew = kOld;
        }
        vfunc_19(kNew);
        float fHeading = FUN_141224f30(kMove.x, kMove.y);
        NiPoint3 kRot = vfunc_20();
        kRot.z = -((fHeading * 180.0f) / 3.1415927f);
        vfunc_21(static_cast<efd::Point3&>(kRot));
        FUN_14166d8b0(kRot.z);
    }
}
MS2_REPLACE_METHOD(0x141674750, PCBase, vfunc_106, 577, 0x913C575A);

// @0x141674ef0
bool PCBase::FUN_141674ef0(const CEffectDummy& kDummy)
{
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot == 0)
        return false;
    NiNode* pParent;
    {
        NiFixedString kParentName((const char*)kDummy.GetParentNode());
        pParent = NiDynamicCast(NiNode, pRoot->GetObjectByName(kParentName));
    }
    if (pParent == 0) {
        FUN_140166440()->FUN_14054c030(1, 0x13, L"EffectDummy의 부모를 찾을 수 없습니다.effectDummy[{0}] - [{1}]",
                                       kDummy.GetName(), kDummy.GetParentNode());
        return false;
    }
    EffectNode* pNode;
    {
        NiFixedString kName((const char*)kDummy.GetName());
        pNode = static_cast<EffectNode*>(NiObject::DynamicCast(&DAT_143ad1588, pParent->GetObjectByName(kName)));
    }
    if (pNode == 0) {
        pNode = NiNew EffectNode(kDummy);
        pParent->AttachChild(pNode, true);
    }
    else
        pNode->FUN_1411a3cb0(kDummy);
    pNode->FUN_1411a3fd0(pRoot);
    pNode->Update((float)FUN_141473280(FUN_14086d260()), true);
    return true;
}
MS2_REPLACE_METHOD(0x141674ef0, PCBase, FUN_141674ef0, 597, 0x968AEBEC);

// @0x14166f380
void PCBase::FUN_14166f380()
{
    FUN_141679fa0();
    if (m_sp638.get() != 0)
        m_sp638->FUN_141848650();
    m_timer9e8.FUN_1408687f0();
    m_timer9e8.FUN_1408687c0();
    m_spD10 = vfunc_70()->FUN_1411bde10(vfunc_69());
    if (m_spD10.get() != 0) {
        MS2Ptr<Unk_PCBaseFxSet> spSet = m_spD10->vfunc_2((void*)&m_str9e0);
        if ((spSet.get() ? true : false) && (spSet->m_sp30.get() ? true : false)) {
            if (m_sp638 == 0)
                m_sp638.AssignRaw(new Unk_PCBaseEmoPlayer(this));
            m_sp638->FUN_1418484a0(spSet->m_sp30, m_spD10->vfunc_1());
        }
    }
}
MS2_REPLACE_METHOD(0x14166f380, PCBase, FUN_14166f380, 831, 0xC410A395);

// @0x141670fd0
void PCBase::FUN_141670fd0(efd::Point3 kSize, efd::Point3 kOffset)
{
    m_sp628.AssignRaw(new CBoxCollision);
    m_sp628->m_ptBox = reinterpret_cast<const Unk_StreamPoint&>(kSize);
    m_sp628->m_ptSize = reinterpret_cast<const Unk_StreamPoint&>(kOffset);
    m_sp628->m_kColor = Unk_AfterImageColor(0, 0, 1.0f, 1.0f);
    m_sp628->vfunc_4();
}
MS2_REPLACE_METHOD(0x141670fd0, PCBase, FUN_141670fd0, 332, 0x3365AEC9);

// @0x141678ad0
// MS2-FUNCTIONAL: the /GS frame puts the rotation matrix and cookie 8 bytes higher (0x110/0x138 vs 0x108/0x130); code otherwise identical.
void PCBase::FUN_141678ad0(CString strName, bool bOutline, float fScale, float fAngle)
{
    if (m_spC40)
        return;
    efd::SmartPointer<NiNode> spRoot = (NiNode*)FUN_141675150("Eff_UI");
    if (spRoot == 0)
        return;
    m_spC40 = FUN_140a0afd0()->FUN_141551ea0(FUN_140cc2a00("Model", strName), 0, 5, 0, 0);
    if (m_spC40 == 0)
        return;
    if (fScale != 1.0f)
        FUN_1410b2450(m_spC40.operator->(), fScale);
    if (fAngle != 0.0f)
    {
        float fRad = fAngle != 0.0f ? (fAngle * 3.1415927f) / 180.0f : 0.0f;
        NiMatrix3 kRot;
        kRot.MakeIdentity();
        kRot.FromEulerAnglesXYZ(0.0f, 0.0f, fRad);
        m_spC40->SetRotate(kRot);
    }
    spRoot->AttachChild(m_spC40, false);
    m_spC40->UpdateEffects();
    m_spC40->UpdateProperties();
    if (bOutline)
    {
        NiColor kColor(1.0f, 0.95f, 0.5058f);
        Unk_SceneWalker kWalker(m_spC40);
        NiAVObject* pObj;
        while ((pObj = kWalker.Next(true)) != 0)
        {
            NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObj);
            if (pRender != 0)
                FUN_141b70cb0(NiDynamicCast(NiRenderObject, pObj), 3.0f, kColor, 0.0f);
        }
    }
}
MS2_REPLACE_METHOD(0x141678ad0, PCBase, FUN_141678ad0, 1135, 0x6DF40066);

// @0x141678f50
// MS2-FUNCTIONAL: the exe keeps the NiNode smart pointer's ctor result in three extra slots (frame 0x78 vs 0x58); same calls and order.
void PCBase::FUN_141678f50()
{
    if (m_spC40 == 0)
        return;
    efd::SmartPointer<NiNode> spRoot = (NiNode*)FUN_141675150("Eff_UI");
    if (spRoot)
        spRoot->DetachChild(m_spC40);
    m_spC40 = 0;
}
MS2_REPLACE_METHOD(0x141678f50, PCBase, FUN_141678f50, 279, 0x6D1CA468);

// @0x141675ed0
int PCBase::FUN_141675ed0()
{
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee)
        return spRidee->FUN_141675ed0();
    if (m_unk_150 == 0)
        return 0;
    egf::EntityID kId = m_unk_150->FUN_141240f20()->FUN_140cfaf70();
    if (kId != egf::kENTITY_INVALID) {
        Unk_PCBaseEntity* pEntity = m_unk_150->FUN_141240f20()->FUN_140cfaff0();
        if (pEntity != 0) {
            unsigned short nKind = 0;
            pEntity->FUN_140ae1160(0xada5c5d2, &nKind);
            if (nKind == 8)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141675ed0, PCBase, FUN_141675ed0, 320, 0x703C9673);

// @0x141676140
void PCBase::FUN_141676140()
{
    if (m_posC10 == efd::Point3::ZERO)
        return;
    if (FUN_141671a30() == 0)
        return;
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField.get() != 0 && spField->m_nFallDamage == 0)
        return;
    Unk_PCBaseState0d* pState;
    if (FUN_14166c930() == 0xd && (pState = static_cast<Unk_PCBaseState0d*>(FUN_14166ccb0())) != 0 && pState->FUN_1417cb160() == 0)
        return;
    if (FUN_141675ed0() == 0) {
        float fHeight = m_posC10.z - vfunc_18().z;
        if (fHeight > 0.0f) {
            Unk_PCBaseFallDamage kFall;
            kFall.m_fHeight = fHeight;
            COutPacket kPacket(static_cast<int>(SendOp::StateFallDamage), 0);
            kFall.FUN_1401fc710(kPacket);
            FUN_140710590(kPacket);
        }
    }
    m_posC10 = efd::Point3::ZERO;
}
MS2_REPLACE_METHOD(0x141676140, PCBase, FUN_141676140, 443, 0x505E464D);
