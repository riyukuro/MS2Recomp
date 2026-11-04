// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Party manager.
// MS2-UNIT: ?\partymanager.cpp
// MS2-RANGE: 0x14162a0d0-0x141637930 .text$mn
// MS2-RANGE: 0x1400fad30-0x1400fb010 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__EDAT_143ae2c58@@YAXXZ 0x1400fad30 ; prop
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400fae80 ; prop
// MS2-PIN: ??__EDAT_143ae2e20@@YAXXZ 0x1400fafc0 ; prop
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400fae20 ; prop
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400fae50 ; prop
// MS2-PIN: ??__Es_capName@@YAXXZ 0x1400fafe0 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141631fe0 ; prop
// MS2-PIN: ??$?0AEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAVCMsTime@@$0A@@?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@QEAA@AEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAVCMsTime@@@Z 0x141632010 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141632070 ; prop
// MS2-PIN: ??$?0AEBU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1416320c0 ; prop
// MS2-PIN: ??$?0PEAVCPartyManager@@P80@EAA_NHAEBVCMsgBoxData@@@Z$0A@@?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@QEAA@AEBQEAVCPartyManager@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x141632110 ; prop
// MS2-PIN: ??$?0VCPartyManager@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAVCPartyManager@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x141632150 ; prop
// MS2-PIN: ??$?0V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@$0A@@?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@QEAA@$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x1416321e0 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141632240 ; prop
// MS2-PIN: ??$?0W4Unk_PartyRecruitError@@$0A@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@AEBW4Unk_PartyRecruitError@@@Z 0x141632290 ; prop
// MS2-PIN: ??$?0W4Unk_PartyRecruitError@@@ArgType@internal@fmt@@QEAA@AEBW4Unk_PartyRecruitError@@@Z 0x1416322c0 ; prop
// MS2-PIN: ??$?8PEAVCPartyManager@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x1416322f0 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x1416328e0 ; prop
// MS2-PIN: ??$_Buynode@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x141632900 ; prop
// MS2-PIN: ??$_Buynode@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x141632990 ; prop
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141632a20 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@1@Z 0x141632ab0 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@@Z 0x141632e10 ; prop
// MS2-PIN: ??$_Kfn@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@SAAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEBU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x141633220 ; prop
// MS2-PIN: ??$_Lbound@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x141633230 ; prop
// MS2-PIN: ??$_Pocs@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@std@@YAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@0@0@Z 0x1416332d0 ; prop
// MS2-PIN: ??$_Pocs@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@std@@YAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x141633300 ; prop
// MS2-PIN: ??$_Swap_adl@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@YAXAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@0@0@Z 0x141633310 ; prop
// MS2-PIN: ??$_Swap_adl@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@YAXAEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@0@0@Z 0x141633340 ; prop
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@0@AEAPEAU10@@Z 0x141633370 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@YAPEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@0@AEAU10@@Z 0x141633380 ; prop
// MS2-PIN: ??$addressof@V?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@@std@@YAPEAV?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@0@AEAV10@@Z 0x141633390 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@0@AEAV10@@Z 0x1416333a0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@AEAPEAU31@@Z 0x1416333b0 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@AEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@AEAU31@@Z 0x141633400 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x141633450 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@@Z 0x1416334a0 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x1416334b0 ; prop
// MS2-PIN: ??$emplace@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@_N@1@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x1416334d0 ; unique
// MS2-PIN: ??$emplace@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x141633540 ; unique
// MS2-PIN: ??$FormatCustomArg@W4Unk_PartyRecruitError@@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@SAXPEAXPEBX0@Z 0x1416336d0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@0@AEAPEAU10@@Z 0x141633700 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@YAAEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@0@AEAU10@@Z 0x141633710 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141633720 ; prop
// MS2-PIN: ??$forward@AEAVCMsTime@@@std@@YAAEAVCMsTime@@AEAV1@@Z 0x141633730 ; prop
// MS2-PIN: ??$forward@AEBQ8CPartyManager@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8CPartyManager@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x141633740 ; prop
// MS2-PIN: ??$forward@AEBQEAVCPartyManager@@@std@@YAAEBQEAVCPartyManager@@AEBQEAV1@@Z 0x141633750 ; prop
// MS2-PIN: ??$forward@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@YA$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@0@AEAU10@@Z 0x141633760 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141633770 ; prop
// MS2-PIN: ??$forward@VCMsTime@@@std@@YA$$QEAVCMsTime@@AEAV1@@Z 0x141633780 ; prop
// MS2-PIN: ??$insert@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@X@?$map@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@_N@1@AEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x141633790 ; prop
// MS2-PIN: ??$insert@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@X@?$map@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@@Z 0x1416337d0 ; prop
// MS2-PIN: ??$make_pair@AEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAVCMsTime@@@std@@YA?AU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@0@AEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAVCMsTime@@@Z 0x141633810 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVCPartyManager@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA?AU?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@AEBQEAVCPartyManager@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x141633870 ; prop
// MS2-PIN: ??$make_type@W4Unk_PartyRecruitError@@@internal@fmt@@YA_KAEBW4Unk_PartyRecruitError@@@Z 0x1416338c0 ; prop
// MS2-PIN: ??$move@AEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@YA$$QEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@0@AEAPEAU10@@Z 0x1416338e0 ; prop
// MS2-PIN: ??$move@AEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@YA$$QEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@0@AEAU10@@Z 0x1416338f0 ; prop
// MS2-PIN: ??$swap@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@X@std@@YAXAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@0@0@Z 0x141633900 ; prop
// MS2-PIN: ??$swap@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@X@std@@YAXAEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@0@0@Z 0x141633950 ; prop
// MS2-PIN: ??$type@W4Unk_PartyRecruitError@@$0A@@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBW4Unk_PartyRecruitError@@@Z 0x141633990 ; prop
// MS2-PIN: ??0?$CAtlArray@V?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@@ATL@@QEAA@XZ 0x1416339a0 ; prop
// MS2-PIN: ??0?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@QEAA@XZ 0x1416339e0 ; prop
// MS2-PIN: ??0?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAA@IMMMI@Z 0x141633a20 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x141633b10 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x141633b60 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCMatchPartyRecruit@@@@QEAA@$$QEAV0@@Z 0x141633bb0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCMatchPartyRecruit@@@@QEAA@H@Z 0x141633be0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCMatchPartyRecruit@@@@QEAA@PEAVCMatchPartyRecruit@@@Z 0x141633c00 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCMatchPartyRecruit@@@@QEAA@XZ 0x141633c30 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCPartyMember@@@@QEAA@H@Z 0x141633c50 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCPartyMember@@@@QEAA@XZ 0x141633c70 ; prop
// MS2-PIN: ??0?$MS2Ptr@VPartyVoteCli@@@@QEAA@AEBV0@@Z 0x141633c90 ; prop
// MS2-PIN: ??0?$TSingleton@VCPartyManager@@@@QEAA@XZ 0x141633cd0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA@AEBU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@@Z 0x141633d00 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA@AEBU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@@Z 0x141633d30 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@1@@Z 0x141633d70 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@1@@Z 0x141633db0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@1@@Z 0x141633df0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@QEAA@XZ 0x141633e30 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141633e60 ; prop
// MS2-PIN: ??0?$map@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@@std@@QEAA@XZ 0x141633e70 ; prop
// MS2-PIN: ??0?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@QEAA@AEBU01@@Z 0x141633ea0 ; prop
// MS2-PIN: ??0CNode@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAA@_JI@Z 0x141633ef0 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@IEAA@_J@Z 0x141633f30 ; prop
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@@ATL@@QEAA@XZ 0x141634010 ; prop
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@QEAA@XZ 0x141634050 ; prop
// MS2-PIN: ??1?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAA@XZ 0x141634090 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x1416340c0 ; prop
// MS2-PIN: ??1?$TSingleton@VCPartyManager@@@@UEAA@XZ 0x1416340e0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA@XZ 0x141634100 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA@XZ 0x141634130 ; prop
// MS2-PIN: ??1?$map@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@@std@@QEAA@XZ 0x141634160 ; prop
// MS2-PIN: ??1?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@QEAA@XZ 0x141634180 ; prop
// MS2-PIN: ??1?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@QEAA@XZ 0x1416341a0 ; prop
// MS2-PIN: ??1CNode@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAA@XZ 0x1416341e0 ; prop
// MS2-PIN: ??1CPair@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAA@XZ 0x141634200 ; prop
// MS2-PIN: ??1NotifySurvivalState@@UEAA@XZ 0x141634260 ; prop
// MS2-PIN: ??4?$MS2Ptr@VCMatchPartyRecruit@@@@QEAAAEAV0@AEBV0@@Z 0x1416342b0 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCPartyMember@@@@QEAAAEAV1@PEAVCPartyMember@@@Z 0x1416342f0 ; unique
// MS2-PIN: ??4?$MS2Ptr@VPartyVoteCli@@@@QEAAAEAV0@AEBV0@@Z 0x141634360 ; prop
// MS2-PIN: ??4?$MS2Ptr@VPartyVoteCli@@@@QEAAAEAV0@H@Z 0x1416343a0 ; prop
// MS2-PIN: ?IsNull@?$MS2Ptr@VCPartyMember@@@@QEBA_NXZ 0x1416343d0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VPartyVoteCli@@@@QEBA_NPEAVPartyVoteCli@@@Z 0x141634400 ; prop
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141634440 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141634480 ; prop
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCPartyMember@@@@_K@Z 0x1416344c0 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@XZ 0x141634500 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@XZ 0x141634520 ; prop
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@1@XZ 0x141634540 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141634560 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1416345b0 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1416345d0 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141634620 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141634640 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1416346d0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1416346f0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141634710 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x1416347e0 ; prop
// MS2-PIN: ??_G?$MS2Ptr@VCMatchPartyRecruit@@@@QEAAPEAXI@Z 0x141634820 ; prop
// MS2-PIN: ??_G?$TSingleton@VCPartyManager@@@@UEAAPEAXI@Z 0x141634860 ; prop
// MS2-PIN: ??_G?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@QEAAPEAXI@Z 0x1416348a0 ; prop
// MS2-PIN: ??_GCNode@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAAPEAXI@Z 0x1416348e0 ; prop
// MS2-PIN: ??_GCPartyManager@@UEAAPEAXI@Z 0x141634920 ; prop
// MS2-PIN: ??_GNotifySurvivalState@@UEAAPEAXI@Z 0x141634960 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCMatchPartyRecruit@@@@@Z 0x1416349a0 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCPartyMember@@@@@Z 0x141634a50 ; prop
// MS2-PIN: ?CallConstructors@?$CAtlArray@V?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VCMatchPartyRecruit@@@@_K@Z 0x141634b00 ; prop
// MS2-PIN: ?CallConstructors@?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VCPartyMember@@@@_K@Z 0x141634b80 ; prop
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VCMatchPartyRecruit@@@@_K@Z 0x141634c00 ; prop
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VCPartyMember@@@@_K@Z 0x141634c60 ; prop
// MS2-PIN: ?CreateNode@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@AEAAPEAVCNode@12@_JII@Z 0x141634cc0 ; prop
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAAXXZ 0x141634d40 ; prop
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAAXXZ 0x141634d60 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141634d80 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@AEAAXXZ 0x141634e80 ; prop
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEBAIXZ 0x141634ed0 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@AEBAPEAVCNode@12@_JAEAI1AEAPEAV312@@Z 0x141634ee0 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x141634fd0 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x141635170 ; prop
// MS2-PIN: ?InitHashTable@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAA_NI_N@Z 0x141635310 ; prop
// MS2-PIN: ?IsLocked@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@AEBA_NXZ 0x141635430 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEBA_N_JAEAV?$MS2Ptr@VCMatchPartyRecruit@@@@@Z 0x141635460 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@AEAAPEAVCNode@12@_JII@Z 0x1416354d0 ; prop
// MS2-PIN: ?PickSize@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@AEBAI_K@Z 0x1416356e0 ; prop
// MS2-PIN: ?Rehash@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAAXI@Z 0x1416357d0 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@SAXPEAV?$MS2Ptr@VCMatchPartyRecruit@@@@0_K@Z 0x141635a00 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCPartyMember@@@@@ATL@@SAXPEAV?$MS2Ptr@VCPartyMember@@@@0_K@Z 0x141635a40 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlArray@V?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@@ATL@@QEAAXXZ 0x141635a80 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@QEAAXXZ 0x141635aa0 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAAXXZ 0x141635ac0 ; prop
// MS2-PIN: ?RemoveAt@?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@QEAAX_K0@Z 0x141635bd0 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141635cb0 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141635da0 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAAPEAU__POSITION@@_JAEBV?$MS2Ptr@VCMatchPartyRecruit@@@@@Z 0x141635e60 ; prop
// MS2-PIN: ?SetCount@?$CAtlArray@V?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@@ATL@@QEAA_N_KH@Z 0x141635f10 ; prop
// MS2-PIN: ?SetCount@?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@QEAA_N_KH@Z 0x1416360a0 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@QEAAXMMM_N@Z 0x141636230 ; prop
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@_JV?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@3@@ATL@@AEAAXXZ 0x1416362e0 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@XZ 0x1416363c0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@XZ 0x141636480 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEBA_NAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@0@Z 0x141636560 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAXXZ 0x1416365a0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@@Z 0x1416365d0 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@@Z 0x141636620 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@2@@Z 0x1416366c0 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@@Z 0x141636c70 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@@Z 0x141636ca0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@XZ 0x141636cd0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@XZ 0x141636d00 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x141636d30 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@2@XZ 0x141636d50 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@2@XZ 0x141636d60 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@2@XZ 0x141636d70 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@2@XZ 0x141636d80 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@XZ 0x141636d90 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@2@XZ 0x141636da0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@2@XZ 0x141636db0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@2@XZ 0x141636de0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAAEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x141636e10 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEBAAEBU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x141636e30 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEBAAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@@Z 0x141636e50 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEBAAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEBU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@2@@Z 0x141636e80 ; prop
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@XZ 0x141636ea0 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@@Z 0x141636eb0 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@PEAU32@@Z 0x141636f90 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@PEAU32@@Z 0x141636fc0 ; prop
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@XZ 0x141636ff0 ; prop
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@XZ 0x141637010 ; prop
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@@Z 0x141637030 ; prop
// MS2-PIN: ?_Swap_all@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAXAEAV12@@Z 0x141637110 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@IEAAXXZ 0x141637150 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@_K@Z 0x1416371b0 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@2@XZ 0x1416371e0 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAXXZ 0x141637250 ; prop
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1416372f0 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@_K@Z 0x141637350 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@2@_K@Z 0x141637380 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@2@XZ 0x1416373b0 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@2@0@Z 0x141637410 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@2@@Z 0x141637500 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@2@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x1416375b0 ; prop
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141637690 ; unique
// MS2-PIN: ??$Call@VCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x1416376d0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCPartyManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141637700 ; prop
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@@std@@@2@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x141637760 ; prop
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@PEAX@std@@@2@@Z 0x1416377c0 ; prop
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEBA_KXZ 0x1416377d0 ; prop
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@std@@SAPEAU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@2@AEAU32@@Z 0x1416377f0 ; prop
// MS2-PIN: ?swap@?$_Tree@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@$0A@@std@@@std@@QEAAXAEAV12@@Z 0x141637810 ; prop
// MS2-PIN: ?swap@?$map@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@VCMsTime@@@std@@@5@@std@@QEAAXAEAV12@@Z 0x141637900 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\partymanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "partymanager.h"
#include "fielddatacli.h"
#include "pcbase.h"
#include "worldservice.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/client/ms2/uichaosdpsdialog.h"
#include "ms2/client/ms2/uipartydialog.h"
#include "ms2/client/ms2/uipartysearchregisterdialog.h"
#include "ms2/client/ms2/uipartysearchdialog.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
// These instantiations are owned by earlier objects. Avoid spurious look-alike local copies.
template<> bool MS2Ptr<CPartyMember>::operator==(CPartyMember*) const;
template<> bool MS2Ptr<CFieldDataCli>::operator==(CFieldDataCli*) const;
template<> bool MS2Ptr<CProxyGameObject>::IsNull() const;
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/stringidinterface.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Initializers retained in the assigned .text$di range, in original order.
CStringW DAT_143ae2c58(L"partyinvite");
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::OpenDialog
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/blindmanager.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/commonfiles/os.h"
CString DAT_143ae2ca8("PC_InviteSuccess");
static CString s_nextSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// This tail appears to come from an adjacent original object. The callback builds ClassInfo entries.
#ifndef MS2_HOOK_DLL
#ifndef MS2_HOOK_DLL   // s_nextClassInfo: the exe's object at 0x143ae2e20, which other units reach as DAT_143ae2e20 (the hook DLL binds it)
efd::ClassInfo DAT_143ae2e20(PC::SetupClassInfo);
#else
extern efd::ClassInfo DAT_143ae2e20;
#endif
#endif
static CString s_capName("Cap");

class Unk_AvModeSvc* FUN_1409f7c90();   // C3: was FUN_1409f7c90
class CBattleRecordManager   // C3: member view for the former free stand-ins
{
public:
    void FUN_140a05610();
public:
    void FUN_140a05670(__int64);   // C3: was free FUN_140a05670
public:
    void FUN_140a056c0(__int64);   // C3: was free FUN_140a056c0
};
class CMyCharacter* FUN_140931510();   // C3: was FUN_140931510
class CMyCharacter   // C3: member view for the former free stand-ins
{
public:
    unsigned int GetDungeonEnterState(unsigned long);
public:
    void SetExpireAndUpdateTimer(__int64);   // C3: was free SetExpireAndUpdateTimer
};
void* FUN_140a8a680(int);
class CUIService;
class UIPartySearchDialog* FUN_1413226d0(int);   // C3: was FUN_1413226d0
int FUN_141472bc0();   // C3: was FUN_141472bc0
__time64_t GetServerTime();
extern __int64 DAT_143ab2828;
MS2Ptr<PartyVoteCli> FUN_140a89240(int);
CStringW GetStringCommon(int);
template <class T1> CStringW FormatStringId(int, const T1&);
CStringW FUN_140298ea0(CStringW);
CStringW GetStringCommonByKey(const CStringW&);
CStringW BlockFormat(int);
void FUN_1412751b0(const CStringW&, int);
void FUN_1412751f0(const CStringW&, int, int);
void FUN_141275260(int, int, int);
int FUN_1412760f0(const CStringW&, const CString&);
void FUN_140d73ff0(CStringW);
struct Unk_PmFixedItem* FUN_140c8dac0();   // C3: was FUN_140c8dac0
class CInstrumentManager   // C3: member view for the former free stand-ins
{
public:
    void CheckPlayState();
};
class CGameOption;
class Unk_ChaosSettings   // C3: member view for the former free stand-ins
{
public:
    struct Unk_ChaosOpt* FUN_140e09150();
};
bool FUN_14125bbe0(struct Unk_InterfaceState const*);   // C3: was FUN_14125bbe0
CInputStream& operator>>(CInputStream&, Unk_PartyBits&);
void FUN_141631f30(const CMatchPartyRecruit&, const CMatchPartyRecruit&);
class UIMessengerBrowser* FUN_140a3ab70(int);   // C3: was FUN_140a3ab70
class UIMessengerBrowser   // C3: member view for the former free stand-ins
{
public:
    void FUN_141a239e0(CStringW);
};
void AddMinutes(CMsTime&, int);
class Unk_MeratBlindManager* FUN_1409c1730();   // C3: was FUN_1409c1730
class CBuddyManager   // C3: member view for the former free stand-ins
{
public:
    unsigned int FUN_140ae51b0(__int64);
public:
    unsigned int FUN_140ae5240(CStringW const&);   // C3: was free FUN_140ae5240
};
int FUN_141276180(const CString&, const CString&);
class NotifySurvivalState : public NotifyObject {
public:
    NotifySurvivalState();
    // @0x141634260
    virtual ~NotifySurvivalState() = default;
    virtual CStringW GetTypeName(); // original implementation 140db5280
};
MS2_CHECK_SIZE(NotifySurvivalState, 0x18);
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
// The returned object is created by the original message-box factory; only the intrusive pointer is local.
MS2Ptr<CMsgBoxData> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>, CStringW);
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>, CStringW);
void FUN_140d73bc0(int, int, void*, CStringW);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_140f8ff40(int, int, int);
UIPartySearchRegisterDialog* FUN_141632840(int);
void FUN_141275460(int, int, int, const fmt::ArgList&);
enum Unk_PartyRecruitError : int { Unk_PartyRecruitSuccess = 0 };

// @0x141632340
template<class A, class B>
inline void PartyRecruitMessage(int id, int a, int b, const A& x, const B& y)
{
    const fmt::internal::ArgArray<2>::Type values = {
        fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(x),
        fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(y)
    };
    FUN_141275460(id, a, b, fmt::ArgList(fmt::internal::make_type(x, y), values));
}

struct Unk_PartyInviteName {
    Unk_PartyInviteName();
    ~Unk_PartyInviteName();
    CStringW name;
};
struct Unk_PartyJoinRequest {
    Unk_PartyJoinRequest();
    ~Unk_PartyJoinRequest();
    CStringW name;
    int value, kind;
};
struct Unk_PartyRecruitInvite {
    explicit Unk_PartyRecruitInvite(MS2Ptr<CMatchPartyRecruit>);
    ~Unk_PartyRecruitInvite();
    __int64 recruitId;
    int fieldId;
    CStringW ownerName;
};
MS2_CHECK_SIZE(Unk_PartyInviteName, 8);
MS2_CHECK_SIZE(Unk_PartyJoinRequest, 0x10);
MS2_CHECK_SIZE(Unk_PartyRecruitInvite, 0x18);
void FUN_1401fc0b0(unsigned char*, class COutputStream&);   // C3: was FUN_1401fc0b0
void FUN_1401fbd30(unsigned char*, class COutputStream&);   // C3: was FUN_1401fbd30
void FUN_1401fbf70(unsigned char*, class COutputStream&);   // C3: was FUN_1401fbf70

void FUN_140694280(struct Unk_140694210&, class COutputStream&);   // C3: was FUN_140694280
void FUN_140694630(const CMatchPartyRecruitSchCond*, COutputStream&);
extern CString DAT_143ae2ca8;

UIChaosDPSDialog* FUN_141632700(int);
UIPartyDPSDialog* FUN_1416327a0(int);
int Unk_ClubBuffCategory(int);
CStringW TranslateEnumDungeonGroup(unsigned int nGroup);
int FUN_1401d9a00(CStringW&);
void FUN_141632630(const CStringW&, std::vector<int>&, const wchar_t*);

struct Unk_PartyOptionPrefix { bool flags[3]; bool refuseParty; };
class Unk_BuddyOptions   // C3: member view for the former free stand-ins
{
public:
    struct Unk_BuddySettings& GetSettings();
};
class CPvPInfo   // C3: member view for the former free stand-ins
{
public:
    bool HasPoint();
};
MS2Ptr<CMsgBoxData> FUN_140d73d20(int, CStringW, void*, CStringW);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);
// WorldService's proxy-by-id lookup, called through a view (worldservice.h is shared).
class Unk_PartyWorldView
{
public:
    MS2Ptr<CProxyGameObject> FUN_141bc9c60(__int64 nId);    // the proxy of a player by id
};
extern CStringW DAT_143ae2c58;

// @0x14162a0d0
CPartyManager::CPartyManager()
    : partyId(0), matchmaking(false), dungeonId(0),
      recruits(17, 0.75f, 0.25f, 2.25f, 10), searchPending(0), recruitPending(0)
{
    ClearParty();
    ClearPartyNameAndKind();
}

// @0x14162a240
CPartyManager::~CPartyManager() { members.RemoveAll(); }

// @0x14162a310
void CPartyManager::FUN_14162a310() { members.RemoveAll(); }
MS2_REPLACE_METHOD(0x14162A310, CPartyManager, FUN_14162a310, 31, 0x88F25701);

// @0x14162a340
void CPartyManager::FUN_14162a340() { members.RemoveAll(); }
MS2_REPLACE_METHOD(0x14162A340, CPartyManager, FUN_14162a340, 31, 0xEFA360B1);

// @0x14162a370
void CPartyManager::ClearParty()
{
    for (size_t i = 0; i < members.GetCount(); ++i)
        reinterpret_cast<COptimizer*>(FUN_1409f7c90())->AddPreloadPlayer(members[i]->FUN_141637bb0());
    members.RemoveAll();
    if (((void*)TSingleton<CBattleRecordManager>::GetInstance()) != NULL) ((class CBattleRecordManager*)(void*)(((void*)TSingleton<CBattleRecordManager>::GetInstance())))->FUN_140a05610();
    partyId = 0;
    leaderName = L"";
    leaderId = 0;
    flag29 = false;
    permissions.FUN_140837500();
    ClearVote();
}
MS2_REPLACE_METHOD(0x14162A370, CPartyManager, ClearParty, 254, 0xCFB93217);

// @0x14162a480
void CPartyManager::FUN_14162a480() { ClearParty(); ClearRecruitmentAndResetSearchUI(); }
MS2_REPLACE_METHOD(0x14162A480, CPartyManager, FUN_14162a480, 34, 0xDCF04E52);

// Not hooked: dispatches handlers that construct local RTTI objects.
// MS2-FUNCTIONAL: typed packet dispatch preserves every opcode branch.
// @0x14162a4b0
void CPartyManager::OnParty(CInPacket& packet)
{
    int nType = packet.ReadUInt8();
    switch (nType) {
    case 0xb: OnPartyInvite(packet); break;
    case 2: OnPartyMemberJoin(packet); break;
    case 3: OnPartyMemberLeave(packet); break;
    case 4: OnPartyMemberKick(packet); break;
    case 5: OnPartyMemberOnline(packet); break;
    case 6: OnPartyMemberOffline(packet); break;
    case 7: FUN_14162d220(packet); break;
    case 8: OnPartyLeaderChange(packet); break;
    case 9: OnPartyInfo(packet); break;
    case 0x13: FUN_14162dfc0(packet); break;
    case 0xd: FUN_14162e100(packet); break;
    case 0xc: FUN_14162e100(packet); break;
    case 0xe: OnPartyMemberCounters(packet); break;
    case 0xf: FUN_14162e310(packet); break;
    case 0x12: FUN_14162e3d0(packet); break;
    case 0x14: OnPartyNotice(packet); break;
    case 0x15: FUN_14162e730(packet); break;
    case 0x19: OnPartyMatchDungeonChange(packet); break;
    case 0x1a: OnPartyRecruitUpdate(packet); break;
    case 0x1e: OnPartyDungeonMatchRegister(packet); break;
    case 0x1f: OnPartyDungeonMatchConfirm(packet); break;
    case 0x23: FUN_14162ee10(packet); break;
    case 0x37: OnPartySurvivalSquadRegister(packet); break;
    case 0x25: FUN_14162ee70(packet); break;
    case 0: OnPartyResultMessage(packet); break;
    case 0x28: OnPartyFindDungeonCooldown(packet); break;
    case 0x2c: OnPartyInviteSent(packet); break;
    case 0x2f: OnPartyVoteStart(packet); break;
    case 0x30: OnPartyVoteReply(packet); break;
    case 0x31: OnPartyVoteEnd(packet); break;
    case 0x38: OnPartyDungeonRoomCreate(packet); break;
    }
}

// Not hooked: the external actor-pointer copy constructor is not mapped.
// @0x14162a840
void CPartyManager::UpdateMemberJob(TPtr<PCBase> actor)
{
    MS2Ptr<CPartyMember> member = FindMemberByCharId(((class PCBase*)(class PCBase*)(actor.operator->()))->FUN_141656a80());
    if (member.get() != NULL) {
        member->FUN_141637ad0(reinterpret_cast<PC*>(actor.operator->())->FUN_141654700());
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(member.get(), 4);
    }
}

// Not hooked: the external actor-pointer copy constructor is not mapped.
// @0x14162a910
void CPartyManager::UpdateMemberHp(TPtr<PCBase> actor)
{
    MS2Ptr<CPartyMember> member = FindMemberByCharId(((class PCBase*)(class PCBase*)(actor.operator->()))->FUN_141656a80());
    if (member.get() != NULL) {
        member->FUN_141637a80(((class PCBase*)(class PCBase*)(actor.operator->()))->FUN_141670a00(4), ((class PCBase*)(class PCBase*)(actor.operator->()))->FUN_141670a30(4));
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(member.get(), 2);
    }
}

// Not hooked: the external actor-pointer copy constructor is not mapped.
// @0x14162aa10
void CPartyManager::UpdateMemberLevel(TPtr<PCBase> actor)
{
    MS2Ptr<CPartyMember> member = FindMemberByCharId(((class PCBase*)(class PCBase*)(actor.operator->()))->FUN_141656a80());
    if (member.get() != NULL) {
        member->FUN_141637a60((short)actor->vfunc_78());
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(member.get(), 8);
    }
}

// @0x14162ab00
int CPartyManager::GetPartyId() { return partyId; }
MS2_REPLACE_METHOD(0x14162AB00, CPartyManager, GetPartyId, 14, 0x92BE4827);

// @0x14162ab20
bool CPartyManager::IsInParty() { return FUN_14162af00() > 1; }
MS2_REPLACE_METHOD(0x14162AB20, CPartyManager, IsInParty, 52, 0x99BFAE5D);

// @0x14162ab60
bool CPartyManager::IsLocalPlayerLeader()
{
    if (!IsInParty())
    {
        return false;
    }
    return IsLeaderId(DAT_143ab2828);
}
MS2_REPLACE_METHOD(0x14162AB60, CPartyManager, IsLocalPlayerLeader, 52, 0x4F5E0B6C);

// @0x14162aba0
bool CPartyManager::IsPartyId(int id) { return partyId == id; }
MS2_REPLACE_METHOD(0x14162ABA0, CPartyManager, IsPartyId, 52, 0x33C13BD7);

// @0x14162abe0
bool CPartyManager::IsMatchmaking() { return matchmaking; }
MS2_REPLACE_METHOD(0x14162ABE0, CPartyManager, IsMatchmaking, 15, 0x82B3C62D);

// @0x14162ac00
bool CPartyManager::IsMatchSearching(int bit)
{
    if (bit == 0) return false;
    return permissions.FUN_1402e4ee0(bit);
}
MS2_REPLACE_METHOD(0x14162AC00, CPartyManager, IsMatchSearching, 50, 0xBD8235D8);

// @0x14162ac40
bool CPartyManager::IsAnySearching() { return permissions.FUN_140b912f0(); }
MS2_REPLACE_METHOD(0x14162AC40, CPartyManager, IsAnySearching, 31, 0x7B803D45);

// @0x14162ac70
bool CPartyManager::CanEnterDungeonRoom(int key)
{
    if (!IsInParty()) {
        if ((int)((class CMyCharacter*)(void*)(((void*)FUN_140931510())))->GetDungeonEnterState(key) >= 10) return false;
        return true;
    }
    for (unsigned i = 0; i < members.GetCount(); ++i)
        if (members[i]->counters.Get(key) >= 10) return false;
    return true;
}
MS2_REPLACE_METHOD(0x14162AC70, CPartyManager, CanEnterDungeonRoom, 177, 0xA0EAF4F7);

// @0x14162ad30
bool CPartyManager::FUN_14162ad30() { return flag29; }
MS2_REPLACE_METHOD(0x14162AD30, CPartyManager, FUN_14162ad30, 15, 0x52CC66EC);

// @0x14162ad50
int CPartyManager::IsMemberByName(CStringW name)
{
    CPartyMember* p = FindMemberByName(name).get();
    if (p != NULL) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14162AD50, CPartyManager, IsMemberByName, 187, 0xEF192C97);

// @0x14162ae20
int CPartyManager::IsMemberByCharId(__int64 id) 
{
    CPartyMember* p = FindMemberByCharId(id).get();
    if (p != NULL) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14162AE20, CPartyManager, IsMemberByCharId, 105, 0x72DB080E);

// @0x14162ae90
int CPartyManager::IsMemberByAccountId(__int64 id) 
{
    CPartyMember* p = FindMemberByAccountId(id).get();
    if (p != NULL) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14162AE90, CPartyManager, IsMemberByAccountId, 105, 0xB07D31F7);

// @0x14162af00
int CPartyManager::FUN_14162af00() { return static_cast<int>(members.GetCount()); }
MS2_REPLACE_METHOD(0x14162AF00, CPartyManager, FUN_14162af00, 31, 0x65E40168);

// @0x14162af30
int CPartyManager::GetMemberIndex(__int64 id)
{
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p == NULL) return -1;
    return p->index;
}
MS2_REPLACE_METHOD(0x14162AF30, CPartyManager, GetMemberIndex, 123, 0x7B909FCE);

// @0x14162afc0
MS2Ptr<CPartyMember> CPartyManager::FindMemberByCharId(__int64 id)
{
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p->user.m_8 == id) return p;
    }
    return MS2Ptr<CPartyMember>(0);
}
MS2_REPLACE_METHOD(0x14162AFC0, CPartyManager, FindMemberByCharId, 235, 0x4D1D7331);

// @0x14162b0c0
MS2Ptr<CPartyMember> CPartyManager::FindMemberByName(CStringW name)
{
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p->user.FUN_1408f19e0().CompareNoCase(name) == 0) return p;
    }
    return MS2Ptr<CPartyMember>(0);
}
MS2_REPLACE_METHOD(0x14162B0C0, CPartyManager, FindMemberByName, 396, 0x2A995807);

// @0x14162b260
MS2Ptr<CPartyMember> CPartyManager::FindMemberByAccountId(__int64 id)
{
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p->user.m_0 == id) return p;
    }
    return MS2Ptr<CPartyMember>(0);
}
MS2_REPLACE_METHOD(0x14162B260, CPartyManager, FindMemberByAccountId, 235, 0x00372A3F);

// @0x14162b360
MS2Ptr<CPartyMember> CPartyManager::GetMemberAt(int index)
{
    if (!(index >= 0 && index < static_cast<int>(members.GetCount())))
    {
        return MS2Ptr<CPartyMember>(0);
    }
    return members[index];
}
MS2_REPLACE_METHOD(0x14162B360, CPartyManager, GetMemberAt, 143, 0x687FF358);

// @0x14162b400
MS2Ptr<CPartyMember> CPartyManager::FindLeader()
{
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p->leader != 0) return p;
    }
    return MS2Ptr<CPartyMember>(0);
}
MS2_REPLACE_METHOD(0x14162B400, CPartyManager, FindLeader, 225, 0xD11D833A);

// @0x14162b4f0
CStringW CPartyManager::GetPartyName() { return partyName; }
MS2_REPLACE_METHOD(0x14162B4F0, CPartyManager, GetPartyName, 66, 0x1554B6B8);

// @0x14162b540
int CPartyManager::GetPartyKind() { return partyKind; }
MS2_REPLACE_METHOD(0x14162B540, CPartyManager, GetPartyKind, 14, 0x7245C177);

// @0x14162b560
void CPartyManager::SetLeaderByName(CStringW name)
{
    if (leaderName == name) return;
    {
        MS2Ptr<CPartyMember> oldLeader = FindMemberByName(leaderName);
        if (oldLeader.get() != NULL) {
            oldLeader->SetRole(1);
            void* ui = FUN_140a8a680(0x4e45);
            if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(oldLeader.get(), 0x100);
        }
    }
    {
        MS2Ptr<CPartyMember> newLeader = FindMemberByName(name);
        if (newLeader.get() != NULL) {
            newLeader->SetRole(2);
            void* ui = FUN_140a8a680(0x4e45);
            if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(newLeader.get(), 0x100);
        }
    }
    leaderName = name;
}
MS2_REPLACE_METHOD(0x14162B560, CPartyManager, SetLeaderByName, 460, 0x62052551);

// @0x14162b740
void CPartyManager::ClearLeaderName() { SetLeaderByName(L""); }
MS2_REPLACE_METHOD(0x14162B740, CPartyManager, ClearLeaderName, 62, 0x4A578BE4);

// @0x14162b790
void CPartyManager::CloseDialogs()
{
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e45);
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4f23);
}
MS2_REPLACE_METHOD(0x14162B790, CPartyManager, CloseDialogs, 50, 0x88AED988);

// @0x14162b7d0
void CPartyManager::SendPartyMode4(CStringW name)
{
    MS2Ptr<CPartyMember> p = FindMemberByName(name);
    if (p.get() != NULL) {
        COutPacket packet(static_cast<int>(SendOp::Party), 0);
        packet.Encode1(4);
        packet.Encode8(p->FUN_141637bb0());
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x14162B7D0, CPartyManager, SendPartyMode4, 216, 0x0F0F0E53);

// @0x14162b8b0
void CPartyManager::SendPartyMode45(__int64 id)
{
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p.get() != NULL) {
        COutPacket packet(static_cast<int>(SendOp::Party), 0);
        packet.Encode1(0x2d);
        packet.Encode8(id);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x14162B8B0, CPartyManager, SendPartyMode45, 151, 0x6FB2507B);

// @0x14162b950
void CPartyManager::SendPartyMode2(int value)
{
    Unk_PartyJoinRequest request;
    request.name = GetPartyName();
    request.value = value;
    request.kind = GetPartyKind();
    COutPacket packet(static_cast<int>(SendOp::Party), 0);
    packet.Encode1(2);
    FUN_1401fc0b0((unsigned char*)(&request), packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14162B950, CPartyManager, SendPartyMode2, 211, 0x16AAD5D0);

// @0x14162ba30
ATL::CAtlArray<MS2Ptr<CPartyMember>>& CPartyManager::GetMembers() { return members; }
MS2_REPLACE_METHOD(0x14162BA30, CPartyManager, GetMembers, 15, 0x3758D2A9);

// @0x14162ba50
void CPartyManager::SendPartyMode1(CStringW name)
{
    if (name.IsEmpty()) return;
    Unk_PartyInviteName request;
    request.name = name;
    COutPacket packet(static_cast<int>(SendOp::Party), 0);
    packet.Encode1(1);
    FUN_1401fbd30((unsigned char*)(&request), packet);
    FUN_140710590(packet);
    FUN_141276180(DAT_143ae2ca8, "");
}
MS2_REPLACE_METHOD(0x14162BA50, CPartyManager, SendPartyMode1, 239, 0x10B17C55);

// @0x14162bb50
void CPartyManager::SendPartyMode23(const Unk_PartyRecruitInvite& request)
{
    CStringW name(request.ownerName);
    if (name.IsEmpty()) return;
    if (name == static_cast<WorldService*>(((void*)WorldService::GetInstance()))->FUN_141bd0d30()) {
        FUN_1412751b0(BlockFormat(0x32e), 0xe);
        return;
    }
    COutPacket packet(static_cast<int>(SendOp::Party), 0);
    packet.Encode1(0x17);
    FUN_1401fbf70((unsigned char*)(&request), packet);
    FUN_140710590(packet);
    FUN_141276180(DAT_143ae2ca8, "");
}
MS2_REPLACE_METHOD(0x14162BB50, CPartyManager, SendPartyMode23, 361, 0x171D882A);

// @0x14162bcc0
void CPartyManager::SendPartyInviteFromRecruit(MS2Ptr<CMatchPartyRecruit> recruit)
{
    Unk_PartyRecruitInvite request(recruit);
    SendPartyMode23(request);
}
MS2_REPLACE_METHOD(0x14162BCC0, CPartyManager, SendPartyInviteFromRecruit, 111, 0xDEFC1332);

// @0x14162bd40
void CPartyManager::SendRoomDungeon(int value)
{
    COutPacket packet(static_cast<int>(SendOp::RoomDungeon), 0);
    packet.Encode1(3);
    packet.Encode4(value);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14162BD40, CPartyManager, SendRoomDungeon, 93, 0xB715FDC7);

// @0x14162bdb0
void CPartyManager::SendPartyMode46()
{
    COutPacket packet(static_cast<int>(SendOp::Party), 0);
    packet.Encode1(0x2e);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14162BDB0, CPartyManager, SendPartyMode46, 75, 0x02273E69);

// @0x14162be10
void CPartyManager::SendPartyMode3()
{
    COutPacket packet(static_cast<int>(SendOp::Party), 0);
    packet.Encode1(3);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14162BE10, CPartyManager, SendPartyMode3, 75, 0x87205910);

// @0x14162be70
int CPartyManager::GetOnlineMemberCount()
{
    int count = 0;
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (!p->FUN_141637c20()) ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x14162BE70, CPartyManager, GetOnlineMemberCount, 169, 0x448BA9E2);

// @0x14162bf20
int CPartyManager::CountOnlineMembersOutsideTutorial()
{
    int count = 0;
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> member(members[i]);
        if (member == NULL) continue;
        if (member->FUN_141637c20() == true) continue;
        MS2Ptr<CFieldDataCli> field = CFieldDataCli::Find(member->user.m_28);
        if (field == NULL) continue;
        if (((class CFieldData*)(class CFieldData*)(field.operator->()))->HasTutorialType()) continue;
        ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x14162BF20, CPartyManager, CountOnlineMembersOutsideTutorial, 354, 0x666BCBA8);

// @0x14162c090
int CPartyManager::GetDungeonId() { return dungeonId; }
MS2_REPLACE_METHOD(0x14162C090, CPartyManager, GetDungeonId, 14, 0xBA6447E3);

// @0x14162c0b0
unsigned short CPartyManager::GetMinMemberLevel()
{
    unsigned short level = 0;
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p == NULL) continue;
        if (p->FUN_141637c20()) continue;
        if (level == 0) level = p->user.m_34;
        if (level > static_cast<unsigned short>(p->user.m_34)) level = p->user.m_34;
    }
    return level;
}
MS2_REPLACE_METHOD(0x14162C0B0, CPartyManager, GetMinMemberLevel, 290, 0x73322521);

// @0x14162c1e0
unsigned CPartyManager::FUN_14162c1e0()
{
    unsigned value = 0;
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p == NULL) continue;
        if (p->FUN_141637c20()) continue;
        if (value == 0) value = p->user.m_d0;
        if (value > static_cast<unsigned>(p->user.m_d0)) value = p->user.m_d0;
    }
    return value;
}
MS2_REPLACE_METHOD(0x14162C1E0, CPartyManager, FUN_14162c1e0, 281, 0x5EFA7901);

// @0x14162c300
bool CPartyManager::HasVote() { return vote.get() != NULL; }
MS2_REPLACE_METHOD(0x14162C300, CPartyManager, HasVote, 61, 0xB2E7BDD3);

// @0x14162c350
MS2Ptr<PartyVoteCli> CPartyManager::GetVote() { return vote; }
MS2_REPLACE_METHOD(0x14162C350, CPartyManager, GetVote, 67, 0x2F92BE78);

// @0x14162c3a0
void CPartyManager::FUN_14162c3a0()
{
    void* ui = FUN_140a8a680(0x4e45);
    if (ui == NULL) return;
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        if (members[i]->FUN_141637c90() != 1) continue;
        members[i]->SetReadyState(3);
        reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(members[i].get(), 1);
    }
}
MS2_REPLACE_METHOD(0x14162C3A0, CPartyManager, FUN_14162c3a0, 235, 0x62228494);

// @0x14162c4a0
void CPartyManager::SetAllMembersState(int state)
{
    void* ui = FUN_140a8a680(0x4e45);
    if (ui == NULL)
        return;
    reinterpret_cast<UIPartyDialog*>(ui)->SetDeadline(0);
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        members[i]->SetReadyState(state);
        reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(members[i].get(), 1);
    }
}
MS2_REPLACE_METHOD(0x14162C4A0, CPartyManager, SetAllMembersState, 203, 0x1919D602);

// @0x14162c580
void CPartyManager::SetMemberReadyState(__int64 id, int state)
{
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p == NULL)
        return;
    p->SetReadyState(state);
    void* ui = FUN_140a8a680(0x4e45);
    if (ui != NULL)
        reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(p.get(), 1);
}
MS2_REPLACE_METHOD(0x14162C580, CPartyManager, SetMemberReadyState, 170, 0x2201AA8A);

// @0x14162c630
void CPartyManager::ClearPartyNameAndKind() { partyName = L""; partyKind = 0; }
MS2_REPLACE_METHOD(0x14162C630, CPartyManager, ClearPartyNameAndKind, 51, 0x6D8B10EA);

// @0x14162c670
void CPartyManager::RemoveMemberAt(int index)
{
    if (index < 0 || index >= static_cast<int>(members.GetCount())) return;
    MS2Ptr<CPartyMember> member(members[index]);
    if (member == NULL) return;
    members.RemoveAt(index, 1);
    ((class CBattleRecordManager*)(void*)(((void*)TSingleton<CBattleRecordManager>::GetInstance())))->FUN_140a056c0(member->FUN_141637bb0());
    reinterpret_cast<COptimizer*>(FUN_1409f7c90())->AddPreloadPlayer(member->FUN_141637bb0());
    void* ui = FUN_140a8a680(0x4e45);
    if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->RemoveMemberEntry(member.get());
    ((class CBattleRecordManager*)(void*)(((void*)TSingleton<CBattleRecordManager>::GetInstance())))->FUN_140a056c0(member->user.m_8);
    for (int i = index; i < static_cast<int>(members.GetCount()); ++i)
        members[i]->FUN_141637cd0(i);
    if ((TSingleton<CUIService>::GetInstance()->FUN_141adc890((eUIClassID)(0x4e8c)))) {
        UIPartyDPSDialog* dps = FUN_1416327a0(0x4e8c);
        if (dps != NULL) dps->RemoveMemberIfUnderLimit();
    }
    if ((TSingleton<CUIService>::GetInstance()->FUN_141adc890((eUIClassID)(0x4f23)))) {
        UIChaosDPSDialog* dps = FUN_141632700(0x4f23);
        if (dps != NULL) ((class UIChaosDPSDialog*)(class UIChaosDPSDialog*)(dps))->FUN_140e05f80();
    }
}
MS2_REPLACE_METHOD(0x14162C670, CPartyManager, RemoveMemberAt, 569, 0xC47B4580);

// @0x14162c8b0
void CPartyManager::OnPartyInvite(CInPacket& packet)
{
    partyName = static_cast<CInputStream&>(packet).ReadUnicodeString();
    partyKind = static_cast<CInputStream&>(packet).ReadInt32();
    PC* player = static_cast<PC*>(
        static_cast<WorldService*>(((void*)WorldService::GetInstance()))->FUN_141bd0cc0());
    if (((struct Unk_PartyOptionPrefix*)&((Unk_BuddyOptions*)TSingleton<CGameOption>::GetInstance())->GetSettings())->refuseParty) {
        SendPartyMode2(0x14);
        return;
    }
    if (player != NULL && ((class CPvPInfo*)(player->FUN_140967420().operator->()))->HasPoint()) {
        SendPartyMode2(0x15);
    } else {
        CStringW key = StringFormat<CStringW, unsigned int>(L"{0}_{1}", DAT_143ae2c58, reinterpret_cast<const unsigned int&>(partyKind));
        MS2Ptr<CMsgBoxData> message = FUN_140d73d20(1,
            FormatStringId(0x2b7, partyName), 0, CStringW(key));
        if (message.get() != NULL) {
            message->SetTimer(0x14, 1, GetStringCommon(0x2b8));
            message->FUN_141a02460(1);
            message->FUN_141a02480(1);
            message->FUN_141a024a0(0);
            FUN_140d73c60(message);
        }
    }
}
MS2_REPLACE_METHOD(0x14162C8B0, CPartyManager, OnPartyInvite, 892, 0x34000DFD);

// @0x14162cc40
void CPartyManager::OnPartyMemberJoin(CInPacket& packet)
{
    int count = FUN_14162af00();
    if (count == 10) return;
    int index = count;
    MS2Ptr<CPartyMember> member(new CPartyMember(index));
    member->user.FUN_1408eeb60(&packet);
    member->counters.Read(&static_cast<CInputStream&>(packet));
    members.Add(member);
    reinterpret_cast<COptimizer*>(FUN_1409f7c90())->AddPreloadPlayer(member->FUN_141637bb0());
    UIDialog* ui = static_cast<UIDialog*>(FUN_140a8a680(0x4e45));
    if (ui != NULL) {
        if (ui->FUN_141924630() != 0) reinterpret_cast<UIPartyDialog*>(ui)->AddMember(member.get());
        else ui->FUN_141924680();
    }
    if (FUN_14125bbe0((struct Unk_InterfaceState const*)(((void*)((Unk_ChaosSettings*)TSingleton<CGameOption>::GetInstance())->FUN_140e09150()))))
        (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4f23)));
    ((class CBattleRecordManager*)(void*)(((void*)TSingleton<CBattleRecordManager>::GetInstance())))->FUN_140a05670(member->FUN_141637bb0());
    CStringW text = FormatStringId(0x31c, member->user.FUN_1408f19e0());
    FUN_1412751b0(text, 0xe);
}
MS2_REPLACE_METHOD(0x14162CC40, CPartyManager, OnPartyMemberJoin, 593, 0x3F7FDB2A);

// @0x14162cea0
void CPartyManager::OnPartyMemberLeave(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).ReadInt64();
    bool disband = static_cast<CInputStream&>(packet).ReadBool();
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p.get() != NULL) {
        if (disband) {
            ClearParty();
            ClearRecruitmentAndResetSearchUI();
            TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e45);
            FUN_1412751b0(GetStringCommon(0x31d), 0xe);
        } else {
            int index = GetMemberIndex(id);
            if (index == -1) return;
            RemoveMemberAt(index);
            CStringW text = FormatStringId(0x31e, p->FUN_141637bd0());
            FUN_1412751b0(text, 0xe);
        }
    }
}
MS2_REPLACE_METHOD(0x14162CEA0, CPartyManager, OnPartyMemberLeave, 458, 0xBE002F26);

// @0x14162d070
void CPartyManager::OnPartyMemberKick(CInPacket& packet)
{
    __int64 id = packet.ReadInt64();
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p.get() != NULL) {
        if (DAT_143ab2828 == p->FUN_141637bb0()) {
            ClearParty();
            ClearRecruitmentAndResetSearchUI();
            TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e45);
            FUN_1412751b0(GetStringCommon(799), 0xe);
        } else {
            int index = GetMemberIndex(id);
            if (index == -1)
                return;
            RemoveMemberAt(index);
            CStringW text = FormatStringId(800, p->FUN_141637bd0());
            FUN_1412751b0(text, 0xe);
        }
    }
}
MS2_REPLACE_METHOD(0x14162D070, CPartyManager, OnPartyMemberKick, 424, 0x58AEE3EB);

// @0x14162d220
void CPartyManager::FUN_14162d220(CInPacket&)
{
    ClearParty();
    ClearRecruitmentAndResetSearchUI();
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e45);
    FUN_1412751b0(GetStringCommon(0x321), 0xe);
}
MS2_REPLACE_METHOD(0x14162D220, CPartyManager, FUN_14162d220, 123, 0x0016246B);

// @0x14162d2b0
void CPartyManager::OnPartyLeaderChange(CInPacket& packet)
{
    __int64 id = packet.ReadInt64();
    CStringW name;
    if (id != 0 && id != leaderId) {
        __int64 oldId = leaderId;
        MS2Ptr<CPartyMember> oldLeader = FindMemberByCharId(oldId);
        if (oldLeader.get() != NULL) oldLeader->SetLeader(0);
        MS2Ptr<CPartyMember> newLeader = FindMemberByCharId(id);
        if (newLeader.get() != NULL) {
            newLeader->SetLeader(1);
            name = newLeader->FUN_141637bd0();
        }
        leaderId = id;
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->FUN_141a74f50(oldLeader.get(), newLeader.get());
        if (DAT_143ab2828 == oldId || DAT_143ab2828 == id) ((class CInstrumentManager*)(void*)(((void*)FUN_140c8dac0())))->CheckPlayState();
    }
    if (FUN_14162af00() > 1) {
        CStringW text;
        if (DAT_143ab2828 == leaderId) text = GetStringCommon(0x324);
        else text = FormatStringId(0x325, name);
        FUN_1412751b0(text, 0xe);
    }
}
MS2_REPLACE_METHOD(0x14162D2B0, CPartyManager, OnPartyLeaderChange, 747, 0x05A83C2F);

// @0x14162d5b0
void CPartyManager::OnPartyInfo(CInPacket& packet)
{
    if (static_cast<unsigned>(partyId) > 0) {
        ClearParty();
        ClearRecruitmentAndResetSearchUI();
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e45);
    }
    bool announce = static_cast<CInputStream&>(packet).ReadBool();
    partyId = static_cast<CInputStream&>(packet).ReadInt32();
    leaderId = static_cast<CInputStream&>(packet).ReadInt64();
    unsigned count = static_cast<CInputStream&>(packet).ReadUInt8();
    members.RemoveAll();
    for (int i = 0; i < static_cast<int>(count); ++i) {
        if (i >= 10) break;
        MS2Ptr<CPartyMember> p(new CPartyMember(i));
        p->offline = static_cast<CInputStream&>(packet).ReadBool();
        p->user.FUN_1408eeb60(&packet);
        p->counters.Read(&static_cast<CInputStream&>(packet));
        if (IsLeaderId(p->user.m_8)) p->SetLeader(1);
        members.Add(p);
        reinterpret_cast<COptimizer*>(FUN_1409f7c90())->AddPreloadPlayer(p->FUN_141637bb0());
        ((class CBattleRecordManager*)(void*)(((void*)TSingleton<CBattleRecordManager>::GetInstance())))->FUN_140a05670(p->FUN_141637bb0());
    }
    reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read0(matchmaking);
    reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read6(reinterpret_cast<unsigned&>(dungeonId));
    static_cast<CInputStream&>(packet) >> permissions;
    reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read0(flag29);
    __int64 previousRecruit = recruitment.recruitId;
    unsigned hasRecruit = static_cast<CInputStream&>(packet).ReadUInt8();
    int changed = 0;
    if (hasRecruit != 0) recruitment.Read(packet);
    changed = previousRecruit != recruitment.recruitId;
    if (FUN_14162af00() > 1) {
        (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4e45)));
        if (FUN_14125bbe0((struct Unk_InterfaceState const*)(((void*)((Unk_ChaosSettings*)TSingleton<CGameOption>::GetInstance())->FUN_140e09150())))) (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4f23)));
    }
    if (announce && members.GetCount() > 1) FUN_1412751b0(GetStringCommon(0x31b), 0xe);
    if (changed) {
        if ((TSingleton<CUIService>::GetInstance()->FUN_141adc890((eUIClassID)(0x4eda)))) {
            void* ui = ((void*)FUN_1413226d0(0x4eda));
            if (ui != NULL) reinterpret_cast<UIPartySearchDialog*>(ui)->FUN_140f8ee00(&recruitment);
        }
    }
}
MS2_REPLACE_METHOD(0x14162D5B0, CPartyManager, OnPartyInfo, 1356, 0x74FF5328);

// @0x14162db10
void CPartyManager::OnPartyMemberOnline(CInPacket& packet)
{
    Unk_UserProxy user;
    user.FUN_1408eeb60(&packet);
    MS2Ptr<CPartyMember> p = FindMemberByCharId(user.m_8);
    if (p.get() != NULL) {
        p->SetOffline(false);
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(p.get(), 0x1ff);
        CStringW text = FormatStringId(0x322, user.FUN_1408f19e0());
        FUN_1412751b0(text, 0xe);
    } else {
        int count = FUN_14162af00();
        if (count == 10) return;
        int index = count;
        p.AssignRaw(new CPartyMember(index));
        p->user.FUN_1408efa70(user);
        members.Add(p);
        reinterpret_cast<COptimizer*>(FUN_1409f7c90())->AddPreloadPlayer(p->FUN_141637bb0());
        ((class CBattleRecordManager*)(void*)(((void*)TSingleton<CBattleRecordManager>::GetInstance())))->FUN_140a05670(p->FUN_141637bb0());
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->AddMember(p.get());
        CStringW text = FormatStringId(0x31c, user.FUN_1408f19e0());
        FUN_1412751b0(text, 0xe);
    }
}
MS2_REPLACE_METHOD(0x14162DB10, CPartyManager, OnPartyMemberOnline, 808, 0x4F26012C);

// @0x14162de40
void CPartyManager::OnPartyMemberOffline(CInPacket& packet)
{
    __int64 id = packet.ReadInt64();
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p.get() != NULL) {
        p->SetOffline(true);
        if (vote.get() != NULL) vote->vfunc_6(id);
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(p.get(), 1);
        CStringW text = FormatStringId(0x323, p->FUN_141637bd0());
        FUN_1412751b0(text, 0xe);
    }
}
MS2_REPLACE_METHOD(0x14162DE40, CPartyManager, OnPartyMemberOffline, 377, 0xDA2CA186);

// @0x14162dfc0
void CPartyManager::FUN_14162dfc0(CInPacket& packet)
{
    __int64 id = packet.ReadInt64();
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p.get() != NULL) {
        CString oldName = p->user.FUN_1408f1a60();
        p->user.FUN_1408ec410(packet);
        int flags = 399;
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(p.get(), flags);
        if (DAT_143ab2828 == p->user.m_8) {
            void* uiParty = FUN_140a8a680(0x4e45);
            if (uiParty != NULL) reinterpret_cast<UIPartyDialog*>(uiParty)->RefreshAllMembers();
        }
    }
}
MS2_REPLACE_METHOD(0x14162DFC0, CPartyManager, FUN_14162dfc0, 312, 0xF779CB13);

// @0x14162e100
void CPartyManager::FUN_14162e100(CInPacket& packet)
{
    __int64 id = packet.ReadInt64();
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p.get() != NULL) {
        CString oldName = p->user.FUN_1408f1a60();
        p->user.FUN_1408eeb60(&packet);
        int flags = 399;
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) reinterpret_cast<UIPartyDialog*>(ui)->UpdateMember(p.get(), flags);
        if (DAT_143ab2828 == p->user.m_8) {
            void* uiParty = FUN_140a8a680(0x4e45);
            if (uiParty != NULL) reinterpret_cast<UIPartyDialog*>(uiParty)->RefreshAllMembers();
        }
    }
}
MS2_REPLACE_METHOD(0x14162E100, CPartyManager, FUN_14162e100, 312, 0x52858474);

// @0x14162e240
void CPartyManager::OnPartyMemberCounters(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).ReadInt64();
    Unk_LockedIntMap counters;
    counters.Read(&static_cast<CInputStream&>(packet));
    MS2Ptr<CPartyMember> member = FindMemberByCharId(id);
    if (member.get() != NULL) member->SetCounters(&counters);
}
MS2_REPLACE_METHOD(0x14162E240, CPartyManager, OnPartyMemberCounters, 199, 0xF491A26D);

// @0x14162e310
void CPartyManager::FUN_14162e310(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).ReadInt64();
    int value = static_cast<CInputStream&>(packet).ReadInt32();
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p.get() != NULL) p->user.m_d0 = value;
}
MS2_REPLACE_METHOD(0x14162E310, CPartyManager, FUN_14162e310, 171, 0x3FCCCFBD);

// @0x14162e3d0
void CPartyManager::FUN_14162e3d0(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).ReadInt64();
    int result = static_cast<CInputStream&>(packet).ReadUInt8();
    MS2Ptr<CPartyMember> p = FindMemberByCharId(id);
    if (p.get() != NULL) {
        if (DAT_143ab2828 == p->FUN_141637bb0()) return;
        if (result != 0) FUN_1412751b0(FormatStringId(0x327, p->FUN_141637bd0()), 0xe);
        else FUN_1412751b0(FormatStringId(0x326, p->FUN_141637bd0()), 0xe);
    }
}
MS2_REPLACE_METHOD(0x14162E3D0, CPartyManager, FUN_14162e3d0, 497, 0x49BC7140);

// @0x14162e5d0
void CPartyManager::OnPartyNotice(CInPacket& packet)
{
    CStringW key = static_cast<CInputStream&>(packet).ReadUnicodeString();
    CStringW sound = static_cast<CInputStream&>(packet).ReadUnicodeString();
    CStringW argument = static_cast<CInputStream&>(packet).ReadUnicodeString();
    CStringW text = FUN_14028dfa0<CStringW>(key, argument);
    FUN_1412751b0(text, 2);
    FUN_1412760f0(sound, "");
}
MS2_REPLACE_METHOD(0x14162E5D0, CPartyManager, OnPartyNotice, 333, 0xD8F6A23F);

// @0x14162e730
void CPartyManager::FUN_14162e730(CInPacket& packet)
{
    CStringW text = StringIdInterface(packet).FUN_141024e60();
    CStringW sound = packet.ReadUnicodeString();
    FUN_1412751b0(text, 2);
    CString empty("");
    FUN_1412760f0(sound, empty);
}
MS2_REPLACE_METHOD(0x14162E730, CPartyManager, FUN_14162e730, 224, 0xD696069F);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162e820
void CPartyManager::OnPartyMatchDungeonChange(CInPacket& packet)
{
    int previousDungeon = dungeonId;
    matchmaking = static_cast<CInputStream&>(packet).ReadBool();
    dungeonId = static_cast<CInputStream&>(packet).ReadInt32();
    if (!matchmaking) {
        if (IsInParty() && previousDungeon != 0 && dungeonId != 0 && previousDungeon != dungeonId) {
            FUN_1412751f0(FUN_14028dfa0<CStringW>(L"s_party_change_help_dungeon", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x14, dungeonId)), 1, 1);
        }
    }
}
MS2_REPLACE_METHOD(0x14162E820, CPartyManager, OnPartyMatchDungeonChange, 411, 0x58877D82);

// @0x14162e9d0
void CPartyManager::OnPartyRecruitUpdate(CInPacket& packet)
{
    CMatchPartyRecruit updated;
    int hasRecruit = packet.ReadUInt8();
    if (hasRecruit != 0) updated.Read(packet);
    FUN_141631f30(recruitment, updated);
    recruitment.CopyFrom(updated);
}
MS2_REPLACE_METHOD(0x14162E9D0, CPartyManager, OnPartyRecruitUpdate, 178, 0x25C43414);

// @0x14162ea90
void CPartyManager::OnPartyDungeonMatchRegister(CInPacket& packet)
{
    int kind = static_cast<CInputStream&>(packet).ReadUInt8();
    bool registered = static_cast<CInputStream&>(packet).ReadBool();
    bool announce = static_cast<CInputStream&>(packet).ReadBool();
    static_cast<CInputStream&>(packet) >> permissions;
    if (announce) {
        CStringW name = TranslateEnumDungeonGroup(Unk_ClubBuffCategory(kind));
        if (registered) {
            if (IsInParty())
                FUN_1412751b0(FUN_14028dfa0<CStringW>(L"s_party_match_dungeon_register", name), 2);
            FUN_141276180("Dungeon_Room_searchParty", "");
        } else {
            if (IsInParty())
                FUN_1412751b0(FUN_14028dfa0<CStringW>(L"s_party_match_dungeon_unregister", name), 2);
            FUN_141276180("Dungeon_Room_searchPartyCancel", "");
        }
    }
}
MS2_REPLACE_METHOD(0x14162EA90, CPartyManager, OnPartyDungeonMatchRegister, 703, 0x57B044C4);

// Not hooked: the callback object carries DLL-local Delegate RTTI.
#ifndef MS2_HOOK_DLL
// @0x14162ed60
void CPartyManager::OnPartyDungeonMatchConfirm(CInPacket&)
{
    FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>(this, &CPartyManager::OnDungeonRoomMsgBoxAnswer), L"s_party_match_dungeon");
}
#endif

// @0x14162ee10
void CPartyManager::FUN_14162ee10(CInPacket& packet)
{
    __int64 value = packet.ReadInt64();
    ((class CMyCharacter*)(void*)(((void*)FUN_140931510())))->SetExpireAndUpdateTimer(value);
}
MS2_REPLACE_METHOD(0x14162EE10, CPartyManager, FUN_14162ee10, 76, 0x8AE4F91C);

// @0x14162ee70
void CPartyManager::FUN_14162ee70(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).ReadInt64();
    CStringW name = static_cast<CInputStream&>(packet).ReadUnicodeString();
    CStringW text = StringIdInterface(packet).FUN_141024e60();
    if (reinterpret_cast<BlindManager*>(FUN_1409c1730())->IsBlocked(0, name)) return;
    if (((class CBuddyManager*)(void*)(((void*)TSingleton<CBuddyManager>::GetInstance())))->FUN_140ae5240(name) != 0) return;
    if (id != 0 && ((class CBuddyManager*)(void*)(((void*)TSingleton<CBuddyManager>::GetInstance())))->FUN_140ae51b0(id) != 0) return;
    FUN_1412751b0(text, 2);
}
MS2_REPLACE_METHOD(0x14162EE70, CPartyManager, FUN_14162ee70, 428, 0x5978F40A);

// @0x14162f030
void CPartyManager::OnPartyResultMessage(CInPacket& packet)
{
    int result = packet.ReadUInt8();
    CStringW name = packet.ReadUnicodeString();
    switch (result) {
    case 0xa: FUN_1412751f0(BlockFormat(0x32a), 1, 1); break;
    case 0x1c: FUN_1412751f0(FUN_140298ea0(L"s_party_err_inviteMe"), 1, 1); break;
    case 0xf: FUN_1412751f0(FormatStringId(0x32b, name), 1, 1); break;
    case 0x4: FUN_1412751b0(GetStringCommon(0x32c), 0x14); break;
    case 0xe: FUN_1412751b0(GetStringCommon(0x32f), 0x14); break;
    case 0x9: FUN_1412751b0(FormatStringId(0x330, name), 0x14); break;
    case 0x14: FUN_1412751b0(FormatStringId(0x331, name), 0x14); break;
    case 0x15: FUN_1412751b0(FormatStringId(0x332, name), 0x14); break;
    case 0xc: FUN_1412751b0(FormatStringId(0x333, name), 0x14); break;
    case 0xb: FUN_1412751b0(FormatStringId(0x32e, name), 0x14); break;
    case 0x5: FUN_1412751b0(FormatStringId(0x32a, name), 0x14); break;
    case 0x7: case 0x8: case 0xd: FUN_1412751b0(FormatStringId(0x329, name), 0x14); break;
    case 0x2: FUN_1412751b0(FormatStringId(0x32d, name), 0x14); break;
    case 0x10: FUN_1412751b0(FormatStringId(0x336, name), 0x14); break;
    case 0x11: FUN_1412751b0(FormatStringId(0x337, name), 0x14); break;
    case 0x12: FUN_1412751b0(FormatStringId(0x338, name), 0x14); break;
    case 0x13: FUN_141275260(0x339, 1, 1); break;
    case 0x18: FUN_141275260(0x33a, 1, 1); break;
    case 0x16: FUN_141275260(0x33b, 1, 1); break;
    case 0x17: FUN_1412751b0(FormatStringId(0x33c, name), 0x14); break;
    case 0x19: FUN_141275260(0x33d, 1, 1); break;
    case 0x1a: FUN_1412751b0(FormatStringId(0x33e, name), 0x14); break;
    case 0x1b: FUN_1412751b0(FormatStringId(0x35, name), 0x14); break;
    case 0x1d: FUN_140d73ff0(L"s_room_party_err_is_in_user"); break;
    case 0x1e: FUN_1412751f0(FUN_140298ea0(L"s_party_invite_boss_room"), 1, 1); break;
    case 0x1f: FUN_1412751f0(FUN_140298ea0(L"s_party_err_not_found"), 1, 1); break;
    case 0x20: FUN_1412751f0(FUN_14028dfa0<CStringW>(L"s_party_request_invite", name), 1, 1); break;
    case 0x21: FUN_1412751f0(FUN_140298ea0(L"s_party_err_already_vote"), 1, 1); break;
    case 0x22: FUN_1412751f0(FUN_140298ea0(L"s_party_err_vote_need_more_people"), 1, 1); break;
    case 0x23: FUN_1412751f0(FUN_140298ea0(L"s_party_err_vote_cooldown"), 1, 1); break;
    case 0x24: FUN_1412751f0(FUN_14028dfa0<CStringW>(L"s_party_err_vote_cannot_kick_vote", FormatDungeonGroupList(name)), 1, 1); break;
    case 0x25: FUN_1412751f0(FUN_140298ea0(L"s_party_err_vote_cannot_kick_vote_only_dungeon"), 1, 1); break;
    case 0x26: FUN_1412751f0(GetStringCommon(0x341), 1, 1); break;
    case 0x27: { CStringW key(L"s_party_expel_maple_survival_squad"); FUN_1412751f0(GetStringCommonByKey(key), 1, 1); } break;
    case 0x28: FUN_140d73ff0(L"s_dungeonMatch_error_isNotChief"); break;
    case 0x29: FUN_140d73ff0(L"s_dungeonMatch_error_hasOfflineUser"); break;
    case 0x2a: FUN_140d73ff0(L"s_dungeonMatch_error_insideDungeonUser"); break;
    case 0x2b: FUN_1412751f0(FUN_140298ea0(L"s_party_err_dungeon_match_another"), 1, 1); break;
    case 0x2c: FUN_1412751f0(FUN_140298ea0(L"s_party_err_isNotChief"), 1, 1); break;
    case 0x2d: FUN_1412751f0(FUN_140298ea0(L"s_party_err_hasOfflineUser"), 1, 1); break;
    case 0x2e: FUN_1412751f0(FUN_140298ea0(L"s_party_err_inside_survival"), 1, 1); break;
    case 0x2f: FUN_1412751f0(FUN_140298ea0(L"s_party_err_another_matching"), 1, 1); break;
    case 0x30: FUN_1412751f0(FUN_140298ea0(L"s_party_err_survival_has_solo_register"), 1, 1); break;
    case 0x31: FUN_1412751f0(FUN_140298ea0(L"s_maple_survival_error_squad_register_over_count"), 1, 1); break;
    default: FUN_1412751b0(FormatStringId(0x979, name), 0x14); break;
    }
}
MS2_REPLACE_METHOD(0x14162F030, CPartyManager, OnPartyResultMessage, 4585, 0x989DDB69);

// @0x1416302f0
void CPartyManager::OnPartyFindDungeonCooldown(CInPacket& packet)
{
    unsigned milliseconds = packet.ReadInt32();
    unsigned seconds = milliseconds / 1000 + 1;
    FUN_1412751b0(FUN_14028dfa0<unsigned int>(L"s_party_find_dungeon_helper_cooldown", seconds), 0x14);
}
MS2_REPLACE_METHOD(0x1416302F0, CPartyManager, OnPartyFindDungeonCooldown, 186, 0x6CE86D98);

// @0x1416303b0
void CPartyManager::OnPartyInviteSent(CInPacket& packet)
{
    CStringW name = packet.ReadUnicodeString();
    PurgeExpiredInvitations();
    if (invitations.find(name) != invitations.end()) return;
    void* ui = ((void*)FUN_140a3ab70(0x4e61));
    if (ui != NULL) {
        ((class UIMessengerBrowser*)(void*)(ui))->FUN_141a239e0(name);
        CMsTime expiry(GetServerTime());
        AddMinutes(expiry, 1);
        invitations.insert(std::make_pair(name, expiry));
    }
}
MS2_REPLACE_METHOD(0x1416303B0, CPartyManager, OnPartyInviteSent, 398, 0xE942D0CD);

// @0x141630550
void CPartyManager::OnPartyVoteStart(CInPacket& packet)
{
    int type = packet.ReadUInt8();
    vote = FUN_140a89240(type);
    if (vote == NULL) return;
    vote->vfunc_1(packet);
    vote->vfunc_2();
}
MS2_REPLACE_METHOD(0x141630550, CPartyManager, OnPartyVoteStart, 269, 0x645860E9);

// @0x141630670
void CPartyManager::OnPartyVoteReply(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).ReadInt64();
    bool yes = static_cast<CInputStream&>(packet).ReadBool();
    if (vote == NULL) return;
    vote->AddVote(id, yes);
}
MS2_REPLACE_METHOD(0x141630670, CPartyManager, OnPartyVoteReply, 163, 0x94778140);

// @0x141630720
void CPartyManager::OnPartyVoteEnd(CInPacket&)
{
    if (vote.get() != NULL) vote->vfunc_3();
    ClearVote();
}
MS2_REPLACE_METHOD(0x141630720, CPartyManager, OnPartyVoteEnd, 93, 0xB83564F9);

// Not hooked: constructing NotifySurvivalState here installs DLL-local RTTI.
#ifndef MS2_HOOK_DLL
// @0x141630790
void CPartyManager::OnPartySurvivalSquadRegister(CInPacket& packet)
{
    flag29 = static_cast<CInputStream&>(packet).ReadBool();
    bool notify = static_cast<CInputStream&>(packet).ReadBool();
    if (notify) {
        int channel = 0xe;
        if (IsInParty() == true) channel = 2;
        if (flag29) {
            FUN_1412751b0(GetStringCommonByKey(L"s_maple_survival_squad_register_squad"), channel);
            FUN_141276180("Dungeon_Room_searchParty", "");
        } else {
            FUN_1412751b0(GetStringCommonByKey(L"s_maple_survival_squad_unregister_squad"), channel);
            FUN_141276180("Dungeon_Room_searchPartyCancel", "");
        }
        reinterpret_cast<NotifySystem*>(FUN_140939a10())->Post(MS2Ptr<NotifyObject>(new NotifySurvivalState));
    }
}
#endif

// Not hooked: the callback object carries DLL-local Delegate RTTI.
#ifndef MS2_HOOK_DLL
// @0x141630a60
void CPartyManager::OnPartyDungeonRoomCreate(CInPacket& packet)
{
    int dungeon = packet.ReadInt32();
    if (!IsLocalPlayerLeader()) {
        FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &CPartyManager::OnDungeonRoomMsgBoxAnswer),
            FUN_14028dfa0<CStringW>(L"s_party_create_dungeon", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x14, dungeon)));
        FUN_141276180("Dungeon_Room_Open", "");
    }
}
#endif

// @0x141630c30
bool CPartyManager::IsLeaderId(__int64 id) { return leaderId == id; }
MS2_REPLACE_METHOD(0x141630C30, CPartyManager, IsLeaderId, 55, 0xE1350063);

// @0x141630c70
bool CPartyManager::OnDungeonRoomMsgBoxAnswer(int result, const CMsgBoxData&)
{
    if (result != 0) return true;
    SendRoomDungeon(0);
    return true;
}
MS2_REPLACE_METHOD(0x141630C70, CPartyManager, OnDungeonRoomMsgBoxAnswer, 48, 0xE4C414EC);

// @0x141630cb0
void CPartyManager::PurgeExpiredInvitations()
{
    std::map<CStringW, CMsTime>::iterator it = invitations.begin();
    std::map<CStringW, CMsTime> retained;
    CMsTime now(GetServerTime());
    for (; it != invitations.end(); it++) {
        if (now < it->second) retained.insert(*it);
    }
    invitations.swap(retained);
}
MS2_REPLACE_METHOD(0x141630CB0, CPartyManager, PurgeExpiredInvitations, 242, 0x27F93552);

// @0x141630db0
CStringW CPartyManager::FormatDungeonGroupList(CStringW input)
{
    CStringW result;
    std::vector<int> values;
    FUN_141632630(input, values, L",");
    for (unsigned i = 0; i < values.size(); ++i) {
        if (i == 0) result += StringFormat(L"{0}", TranslateEnumDungeonGroup(values[i]));
        else result += StringFormat(L", {0}", TranslateEnumDungeonGroup(values[i]));
    }
    return result;
}
MS2_REPLACE_METHOD(0x141630DB0, CPartyManager, FormatDungeonGroupList, 523, 0x1088CBCE);

// @0x141630fd0
void CPartyManager::ClearRecruitmentAndResetSearchUI()
{
    recruitment.Clear();
    recruitPending = 0;
    void* ui = ((void*)FUN_1413226d0(0x4eda));
    if (ui != NULL) ((class UIPartySearchDialog*)(void*)(ui))->FUN_140f8edb0();
}
MS2_REPLACE_METHOD(0x141630FD0, CPartyManager, ClearRecruitmentAndResetSearchUI, 79, 0x3E76544C);

// @0x141631030
void CPartyManager::ClearVote() { vote = 0; }
MS2_REPLACE_METHOD(0x141631030, CPartyManager, ClearVote, 35, 0x0C867F49);

// @0x141631060
void CPartyManager::ResetRecruitmentAndRefreshSearch()
{
    recruitment.Clear();
    recruitPending = 0;
    void* ui = ((void*)FUN_1413226d0(0x4eda));
    if (ui != NULL) reinterpret_cast<UIPartySearchDialog*>(ui)->FUN_140f8ee50(&recruitment);
}
MS2_REPLACE_METHOD(0x141631060, CPartyManager, ResetRecruitmentAndRefreshSearch, 91, 0x2A2536B7);

// @0x1416310d0
void CPartyManager::OnMatchParty(CInPacket& packet)
{
    int type = packet.ReadUInt8();
    switch (type) {
    case 0: OnMatchPartyRecruitRegistered(packet); break;
    case 1: OnMatchPartyRecruitRemoved(packet); break;
    case 2: OnMatchPartySearchResults(packet); break;
    case 4: OnMatchPartyError(packet); break;
    }
}
MS2_REPLACE_METHOD(0x1416310D0, CPartyManager, OnMatchParty, 164, 0x4143B2A2);

// @0x141631180
void CPartyManager::SendMatchPartyMode0(const Unk_PartyRecruitRequest& request)
{
    COutPacket packet(static_cast<int>(SendOp::PartySearch), 0);
    packet.Encode1(0);
    FUN_140694280(*(struct Unk_140694210*)(&request), packet);
    FUN_140710590(packet);
    recruitPending = 1;
}
MS2_REPLACE_METHOD(0x141631180, CPartyManager, SendMatchPartyMode0, 109, 0xB559BF4D);

// @0x141631200
void CPartyManager::SendMatchPartyMode1()
{
    if (recruitment.recruitId == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::PartySearch), 0);
    packet.Encode1(1);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141631200, CPartyManager, SendMatchPartyMode1, 92, 0xF01C980A);

// @0x141631270
void CPartyManager::SendMatchPartyMode2(const CMatchPartyRecruitSchCond& condition)
{
    COutPacket packet(static_cast<int>(SendOp::PartySearch), 0);
    packet.Encode1(2);
    FUN_140694630(&condition, packet);
    FUN_140710590(packet);
    if (condition.page <= 1) searchPending = 1;
}
MS2_REPLACE_METHOD(0x141631270, CPartyManager, SendMatchPartyMode2, 120, 0x92FC6B3D);

// @0x1416312f0
void CPartyManager::SetPartyDeadline(int id)
{
    if (partyId != id) return;
    deadline = FUN_141472bc0() + 10000;
}
MS2_REPLACE_METHOD(0x1416312F0, CPartyManager, SetPartyDeadline, 55, 0x412FA0CA);

// @0x141631330
int CPartyManager::GetPartyDeadlineRemaining()
{
    if (deadline < FUN_141472bc0()) return 0;
    return deadline - FUN_141472bc0();
}
MS2_REPLACE_METHOD(0x141631330, CPartyManager, GetPartyDeadlineRemaining, 56, 0x0F45776B);

// @0x141631370
void CPartyManager::OnMatchPartyRecruitRegistered(CInPacket& packet)
{
    recruitPending = 0;
    CMatchPartyRecruit updated;
    updated.Read(packet);
    FUN_141631f30(recruitment, updated);
    recruitment.CopyFrom(updated);
}
MS2_REPLACE_METHOD(0x141631370, CPartyManager, OnMatchPartyRecruitRegistered, 142, 0x718E9365);

// @0x141631410
void CPartyManager::OnMatchPartyRecruitRemoved(CInPacket& packet)
{
    __int64 id = packet.ReadInt64();
    if (recruitment.recruitId == id) {
        CMatchPartyRecruit empty;
        FUN_141631f30(recruitment, empty);
        recruitment.Clear();
    }
}
MS2_REPLACE_METHOD(0x141631410, CPartyManager, OnMatchPartyRecruitRemoved, 168, 0xF4FB48FA);

// @0x1416314c0
void CPartyManager::OnMatchPartySearchResults(CInPacket& packet)
{
    unsigned count = static_cast<CInputStream&>(packet).ReadInt32();
    if (searchPending != 0) {
        results.RemoveAll();
        recruits.RemoveAll();
        searchPending = 0;
    }
    int last = static_cast<int>(results.GetCount()) - 1 < 0 ? 0 : static_cast<int>(results.GetCount()) - 1;
    for (unsigned i = 0; i < count; ++i) {
        int bValid = static_cast<CInputStream&>(packet).ReadUInt8();
        if (bValid != 0) {
            MS2Ptr<CMatchPartyRecruit> p(new CMatchPartyRecruit);
            p->Read(packet);
            results.Add(p);
            recruits.SetAt(p->recruitId, p);
        }
    }
    void* ui = ((void*)FUN_1413226d0(0x4eda));
    if (ui != NULL) reinterpret_cast<UIPartySearchDialog*>(ui)->FUN_140f8ed40(results, last);
}
MS2_REPLACE_METHOD(0x1416314C0, CPartyManager, OnMatchPartySearchResults, 561, 0x09B1B047);

// MS2-FUNCTIONAL: equivalent error cases with reduced temporary storage.
// @0x141631700
void CPartyManager::OnMatchPartyError(CInPacket& packet)
{
    int type = static_cast<CInputStream&>(packet).ReadUInt8();
    Unk_PartyRecruitError result = static_cast<Unk_PartyRecruitError>(static_cast<CInputStream&>(packet).ReadInt32());
    if (type == 0) recruitPending = 0;
    if (result == 99) { FUN_140f8ff40(0xb46, 1, 1); return; }
    else if (result == 0x65) { FUN_140d73bc0(0xb47, 0, 0, L""); return; }
    else if (result == 0x6e) { FUN_140d73bc0(0xb48, 0, 0, L""); return; }
    else if (result == 2) { FUN_140d73bc0(0xb49, 0, 0, L""); return; }
    else if (result == 0xe || result == 0xc || result == 0xf) { FUN_140d73bc0(0xb4a, 0, 0, L""); return; }
    else if (result == 0x6d) { FUN_140f8ff40(0xb51, 1, 0); return; }
    else if (type == 0) {
        if (result == 0x69) { FUN_140d73bc0(0xb4a, 0, 0, L""); return; }
        else if (result == 0x66) { FUN_140d73bc0(0xb4b, 0, 0, L""); return; }
        else if (result == 0x68) { FUN_140d73bc0(0xb4c, 0, 0, L""); return; }
        else if (result == 0x6c) {
            void* ui = FUN_141632840(0x4edb);
            if (ui != NULL) reinterpret_cast<UIPartySearchRegisterDialog*>(ui)->FUN_141321d30();
            FUN_140d73bc0(0xb4e, 0, 0, L"");
            return;
        }
        else if (result == 0x6f) { FUN_140d73bc0(0xb50, 0, 0, L""); return; }
    } else if (type == 1) {
        if (result == 0x67) { FUN_140d73bc0(0xb4d, 0, 0, L""); return; }
        else if (result == 0x6a) {
            FUN_140d73aa0(GetStringCommonByKey(L"s_partysearch_err_server_not_find_recruit"), 0, 0, L"");
            ResetRecruitmentAndRefreshSearch();
            return;
        }
    } else if (type == 2 && result == 0x6c) {
        void* ui = ((void*)FUN_1413226d0(0x4eda));
        if (ui != NULL) ((class UIPartySearchDialog*)(void*)(ui))->FUN_140f8dde0();
        FUN_140d73bc0(0xb4f, 0, 0, L"");
        return;
    }
    PartyRecruitMessage(0xb52, 1, 1, type, result);
}
MS2_REPLACE_METHOD(0x141631700, CPartyManager, OnMatchPartyError, 1410, 0xCF636205);

// @0x141631cc0
int CPartyManager::IsRecruitPending() { return recruitPending; }
MS2_REPLACE_METHOD(0x141631CC0, CPartyManager, IsRecruitPending, 17, 0x8EDBEBA2);

// @0x141631ce0
CMatchPartyRecruit& CPartyManager::FUN_141631ce0() { return recruitment; }
MS2_REPLACE_METHOD(0x141631CE0, CPartyManager, FUN_141631ce0, 15, 0x37F83669);

// @0x141631d00
ATL::CAtlMap<__int64, MS2Ptr<CMatchPartyRecruit>>& CPartyManager::GetRecruitMap() { return recruits; }
MS2_REPLACE_METHOD(0x141631D00, CPartyManager, GetRecruitMap, 17, 0xAA3C736B);

// @0x141631d20
ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit>>& CPartyManager::FUN_141631d20() { return results; }
MS2_REPLACE_METHOD(0x141631D20, CPartyManager, FUN_141631d20, 17, 0x86898F9A);

// @0x141631d40
MS2Ptr<CMatchPartyRecruit> CPartyManager::FUN_141631d40(__int64 id)
{
    MS2Ptr<CMatchPartyRecruit> p(0);
    recruits.Lookup(id, p);
    return p;
}
MS2_REPLACE_METHOD(0x141631D40, CPartyManager, FUN_141631d40, 124, 0x95EED447);

// @0x141631dd0
int CPartyManager::FUN_141631dd0()
{
    WorldService* world = static_cast<WorldService*>(((void*)WorldService::GetInstance()));
    if (world == NULL) return 0;
    int count = 0;
    int size = static_cast<int>(members.GetCount());
    for (int i = 0; i < size; ++i) {
        MS2Ptr<CPartyMember> member(members[i]);
        if (member.IsNull()) continue;
        MS2Ptr<CProxyGameObject> proxy = reinterpret_cast<Unk_PartyWorldView*>(world)->FUN_141bc9c60(member->FUN_141637bb0());
        if (proxy.IsNull()) continue;
        if (proxy->kind != 0) continue;
        ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x141631DD0, CPartyManager, FUN_141631dd0, 338, 0xA4F142C3);

// @0x141631f30
void FUN_141631f30(const CMatchPartyRecruit& oldRecruit, const CMatchPartyRecruit& newRecruit)
{
    int changed = oldRecruit.recruitId != newRecruit.recruitId ? 1 : 0;
    if (changed) {
        if (oldRecruit.recruitId != 0) FUN_141275260(0xb30, 1, 1);
        if (newRecruit.recruitId != 0) FUN_141275260(0xb2e, 1, 1);
        void* ui = ((void*)FUN_1413226d0(0x4eda));
        if (ui != NULL) reinterpret_cast<UIPartySearchDialog*>(ui)->FUN_140f8ee00(const_cast<CMatchPartyRecruit*>(&newRecruit));
    }
}
MS2_REPLACE(0x141631F30, FUN_141631f30, 176, 0x46058A0A);

// @0x141632630
void FUN_141632630(const CStringW& input, std::vector<int>& values, const wchar_t* delimiter)
{
    int start = 0;
    CStringW token = input.Tokenize(delimiter, start);
    while (!token.IsEmpty()) {
        values.push_back(FUN_1401d9a00(token));
        token = input.Tokenize(delimiter, start);
    }
}

// @0x141632700
UIChaosDPSDialog* FUN_141632700(int id)
{
    if ((void*)TSingleton<CUIService>::GetInstance() != NULL) {
        MS2Ptr<UIObject> object = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)id);
        if (object.get() != NULL) return dynamic_cast<UIChaosDPSDialog*>(object.operator->());
    }
    return NULL;
}

// @0x1416327a0
UIPartyDPSDialog* FUN_1416327a0(int id)
{
    if ((void*)TSingleton<CUIService>::GetInstance() != NULL) {
        MS2Ptr<UIObject> object = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)id);
        if (object.get() != NULL) return dynamic_cast<UIPartyDPSDialog*>(object.operator->());
    }
    return NULL;
}

// @0x141632840
UIPartySearchRegisterDialog* FUN_141632840(int id)
{
    if ((void*)TSingleton<CUIService>::GetInstance() != NULL) {
        MS2Ptr<UIObject> object = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)id);
        if (object.get() != NULL) return dynamic_cast<UIPartySearchRegisterDialog*>(object.operator->());
    }
    return NULL;
}

// Enum customization used by PartyRecruitMessage: fmt's shared enum shortcut template.
// @0x1416335b0
template void fmt::format_arg<wchar_t, Unk_PartyRecruitError>(fmt::BasicFormatter<wchar_t>& formatter, const wchar_t*& format, const Unk_PartyRecruitError& value);

// @0x141633f70
Unk_PartyInviteName::Unk_PartyInviteName() {}

// @0x141633fa0
Unk_PartyJoinRequest::Unk_PartyJoinRequest() : value(0x32), kind(0) {}

// @0x141633fe0
NotifySurvivalState::NotifySurvivalState() {}

// @0x1416341c0
Unk_PartyRecruitInvite::~Unk_PartyRecruitInvite() {}

// @0x141634220
Unk_PartyInviteName::~Unk_PartyInviteName() {}

// @0x141634240
Unk_PartyJoinRequest::~Unk_PartyJoinRequest() {}

// @0x141634280
Unk_LockedIntMap::~Unk_LockedIntMap() {}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb3c10-0x142cb3d10 .text$yd
// MS2-RANGE: 0x142cb3d30-0x142cb3d50 .text$yd
