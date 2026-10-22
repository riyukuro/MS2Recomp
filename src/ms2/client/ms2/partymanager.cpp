// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Party manager.
// MS2-UNIT: ?\partymanager.cpp
// MS2-RANGE: 0x14162a0d0-0x141637930 .text$mn
// MS2-RANGE: 0x1400fad30-0x1400fb010 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__EDAT_143ae2c58@@YAXXZ 0x1400fad30 ; prop
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400fae80 ; prop
// MS2-PIN: ??__Es_nextClassInfo@@YAXXZ 0x1400fafc0 ; prop
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
#include "ms2/placeholder/partyuidialogs.h"
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
CString DAT_143ae2ca8("PC_InviteSuccess");
static CString s_nextSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// This tail appears to come from an adjacent original object. The callback builds ClassInfo entries.
void FUN_1409f8020(efd::ClassInfo*, size_t);
#ifndef MS2_HOOK_DLL
static efd::ClassInfo s_nextClassInfo(FUN_1409f8020);
#endif
static CString s_capName("Cap");

void* FUN_1409f7c90();
void FUN_14161cd60(void*, __int64);
void* FUN_140e09140();
void FUN_140a05610(void*);
void* FUN_140931510();
int FUN_140d9f880(void*, int);
void* FUN_140a8a680(int);
void FUN_141a74d50(void*, CPartyMember*, int);
void FUN_141a75a00(void*, int);
void* FUN_1403ed2b0();
void FUN_141adc5d0(void*, int);
void* FUN_1413226d0(int);
void FUN_140f8edb0(void*);
void FUN_140f8ee50(void*, CMatchPartyRecruit&);
unsigned FUN_141472bc0();
__time64_t FUN_140869440();
extern __int64 DAT_143ab2828;
MS2Ptr<PartyVoteCli> FUN_140a89240(int);
CStringW GetStringCommon(int);
CStringW FUN_14052bd00(int, const CStringW&);
CStringW FUN_1405c2690(CStringW, const CStringW&);
CStringW FUN_140298ea0(CStringW);
CStringW GetStringCommonByKey(const CStringW&);
CStringW FUN_1409eec40(int);
void FUN_1412751b0(const CStringW&, int);
void FUN_1412751f0(const CStringW&, int, int);
void FUN_141275260(int, int, int);
void FUN_1412760f0(const CStringW&, const CString&);
void FUN_140d73ff0(CStringW);
void FUN_140d9f310(void*, __int64);
void FUN_141a74ea0(void*);
void FUN_141a74f50(void*, CPartyMember*, CPartyMember*);
void* FUN_140c8dac0();
void FUN_140d0b030(void*);
void FUN_140a05670(void*, __int64);
void FUN_140a056c0(void*, __int64);
void FUN_141a752a0(void*, CPartyMember*);
void FUN_141a753d0(void*, CPartyMember*);
void FUN_141adc530(void*, int);
int FUN_141adc890(void*, int);
void* FUN_1409a8b10();
void* FUN_140e09150(void*);
bool FUN_14125bbe0(void*);
void FUN_140f8ee00(void*, const CMatchPartyRecruit&);
void FUN_140268210(Unk_PartyCounters*, CInputStream&);
void FUN_14031bf10(CInputStream&, Unk_PartyBits&);
CInputStream& FUN_14070f300(CInputStream&, bool&);
CInputStream& FUN_14070f480(CInputStream&, int&);
void FUN_140f8ed40(void*, ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit>>&, int);
void FUN_141631f30(const CMatchPartyRecruit&, const CMatchPartyRecruit&);
void* FUN_140a3ab70(int);
void FUN_141a239e0(void*, CStringW);
void FUN_14086a880(CMsTime&, int);
CStringW FUN_140938ae0(CStringW, const unsigned&);
void* FUN_1409c1730();
bool FUN_140a25840(void*, __int64, CStringW);
void* FUN_14097a780();
int FUN_140ae5240(void*, const CStringW&);
int FUN_140ae51b0(void*, __int64);
class Unk_1401a9d70 { public: CStringW FUN_141811980(int, int); };
Unk_1401a9d70* FUN_1401a9d70();
void FUN_141276180(const CString&, const CString&);
class NotifySurvivalState : public NotifyObject {
public:
    NotifySurvivalState();
    // @0x141634260
    virtual ~NotifySurvivalState() = default;
    virtual CStringW GetTypeName(); // original implementation 140db5280
};
MS2_CHECK_SIZE(NotifySurvivalState, 0x18);
void* FUN_140939a10();
void FUN_140da4fe0(void*, MS2Ptr<NotifyObject>);
class Unk_PartyMessage : public CPtred {};
// The returned object is created by the original message-box factory; only the intrusive pointer is local.
MS2Ptr<Unk_PartyMessage> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>, CStringW);
MS2Ptr<Unk_PartyMessage> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>, CStringW);
void FUN_140d73bc0(int, int, void*, CStringW);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_140f8ff40(int, int, int);
void FUN_140f8dde0(void*);
UIPartySearchRegisterDialog* FUN_141632840(int);
void FUN_141321d30(void*);
void FUN_141275460(int, int, int, const fmt::ArgList&);
enum Unk_PartyRecruitError : int { Unk_PartyRecruitSuccess = 0 };
void format_arg(fmt::BasicFormatter<wchar_t>&, const wchar_t*&, const Unk_PartyRecruitError&);

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
void FUN_1401fc0b0(Unk_PartyJoinRequest*, COutputStream&);
void FUN_1401fbd30(Unk_PartyInviteName*, COutputStream&);
void FUN_1401fbf70(const Unk_PartyRecruitInvite*, COutputStream&);
void* FUN_1403ed2d0();

MS2Ptr<CFieldDataCli> FUN_140a55460(int);
char FUN_140375310(CFieldData*);
void FUN_140694280(const Unk_PartyRecruitRequest*, COutputStream&);
void FUN_140694630(const CMatchPartyRecruitSchCond*, COutputStream&);
extern CString DAT_143ae2ca8;
int FUN_141654700(PCBase*);
__int64 FUN_141656a80(PCBase*);
__int64 FUN_141670a30(PCBase*, int);
__int64 FUN_141670a00(PCBase*, int);

void FUN_141adcea0(void*, MS2Ptr<UIObject>*, int);
void FUN_141a7bb70(UIPartyDPSDialog*);
void FUN_140e05f80(UIChaosDPSDialog*);
UIChaosDPSDialog* FUN_141632700(int);
UIPartyDPSDialog* FUN_1416327a0(int);
int FUN_140217850(unsigned char);
CStringW FUN_140cbf840(int);
int FUN_1401d9a00(const CStringW&);
void FUN_141632630(const CStringW&, ATL::CAtlArray<int>&, const wchar_t*);

struct Unk_PartyOptionPrefix { bool flags[3]; bool refuseParty; };
Unk_PartyOptionPrefix* FUN_140ae6540(void*);
class Unk_PartyInviteState;
class Unk_PartyInviteStatePtr {
public:
    ~Unk_PartyInviteStatePtr(); // 140964aa0
    Unk_PartyInviteState* operator->() const; // 140965970
private:
    void* unused;
    Unk_PartyInviteState* value;
};
MS2_CHECK_SIZE(Unk_PartyInviteStatePtr, 0x10);
class Unk_PartyPlayer { public: Unk_PartyInviteStatePtr FUN_140967420(); };
bool FUN_140743550(Unk_PartyInviteState*);
MS2Ptr<Unk_PartyMessage> FUN_140d73d20(int, CStringW, int, CStringW);
void FUN_141a01ca0(Unk_PartyMessage*, int, int, const CStringW&);
void FUN_141a02460(Unk_PartyMessage*, bool);
void FUN_141a02480(Unk_PartyMessage*, bool);
void FUN_141a024a0(Unk_PartyMessage*, bool);
void FUN_140d73c60(MS2Ptr<Unk_PartyMessage>);
void FUN_141bc9c60(WorldService*, MS2Ptr<CProxyGameObject>*, __int64);
extern CStringW DAT_143ae2c58;

// @0x14162a0d0
CPartyManager::CPartyManager()
    : partyId(0), matchmaking(false), dungeonId(0),
      recruits(17, 0.75f, 0.25f, 2.25f, 10), searchPending(0), recruitPending(0)
{
    FUN_14162a370();
    FUN_14162c630();
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
void CPartyManager::FUN_14162a370()
{
    for (size_t i = 0; i < members.GetCount(); ++i)
        FUN_14161cd60(FUN_1409f7c90(), members[i]->FUN_141637bb0());
    members.RemoveAll();
    if (FUN_140e09140() != NULL) FUN_140a05610(FUN_140e09140());
    partyId = 0;
    leaderName = L"";
    leaderId = 0;
    flag29 = false;
    permissions.FUN_140837500();
    FUN_141631030();
}
MS2_REPLACE_METHOD(0x14162A370, CPartyManager, FUN_14162a370, 254, 0xCFB93217);

// @0x14162a480
void CPartyManager::FUN_14162a480() { FUN_14162a370(); FUN_141630fd0(); }
MS2_REPLACE_METHOD(0x14162A480, CPartyManager, FUN_14162a480, 34, 0xDCF04E52);

// Not hooked: dispatches handlers that construct local RTTI objects.
// MS2-FUNCTIONAL: typed packet dispatch preserves every opcode branch.
// @0x14162a4b0
void CPartyManager::OnParty(CInPacket& packet)
{
    switch (static_cast<CInputStream&>(packet).vfunc_o8_1()) {
    case 0: FUN_14162f030(packet); break;
    case 2: FUN_14162cc40(packet); break;
    case 3: FUN_14162cea0(packet); break;
    case 4: FUN_14162d070(packet); break;
    case 5: FUN_14162db10(packet); break;
    case 6: FUN_14162de40(packet); break;
    case 7: FUN_14162d220(); break;
    case 8: FUN_14162d2b0(packet); break;
    case 9: FUN_14162d5b0(packet); break;
    case 0xb: FUN_14162c8b0(packet); break;
    case 0xc: FUN_14162e100(packet); break;
    case 0xd: FUN_14162e100(packet); break;
    case 0xe: FUN_14162e240(packet); break;
    case 0xf: FUN_14162e310(packet); break;
    case 0x12: FUN_14162e3d0(packet); break;
    case 0x13: FUN_14162dfc0(packet); break;
    case 0x14: FUN_14162e5d0(packet); break;
    case 0x15: FUN_14162e730(packet); break;
    case 0x19: FUN_14162e820(packet); break;
    case 0x1a: FUN_14162e9d0(packet); break;
    case 0x1e: FUN_14162ea90(packet); break;
    case 0x1f: FUN_14162ed60(); break;
    case 0x23: FUN_14162ee10(packet); break;
    case 0x25: FUN_14162ee70(packet); break;
    case 0x28: FUN_1416302f0(packet); break;
    case 0x2c: FUN_1416303b0(packet); break;
    case 0x2f: FUN_141630550(packet); break;
    case 0x30: FUN_141630670(packet); break;
    case 0x31: FUN_141630720(); break;
    case 0x37: FUN_141630790(packet); break;
    case 0x38: FUN_141630a60(packet); break;
    }
}

// Not hooked: the external actor-pointer copy constructor is not mapped.
// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162a840
void CPartyManager::FUN_14162a840(TPtr<PCBase> actor)
{
    MS2Ptr<CPartyMember> member = FUN_14162afc0(FUN_141656a80(actor.operator->()));
    if (member.get() != NULL) {
        member->FUN_141637ad0(FUN_141654700(actor.operator->()));
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) FUN_141a74d50(ui, member.operator->(), 4);
    }
}

// Not hooked: the external actor-pointer copy constructor is not mapped.
// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162a910
void CPartyManager::FUN_14162a910(TPtr<PCBase> actor)
{
    MS2Ptr<CPartyMember> member = FUN_14162afc0(FUN_141656a80(actor.operator->()));
    if (member.get() != NULL) {
        int maximum = static_cast<int>(FUN_141670a30(actor.operator->(), 4));
        int current = static_cast<int>(FUN_141670a00(actor.operator->(), 4));
        member->FUN_141637a80(current, maximum);
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) FUN_141a74d50(ui, member.operator->(), 2);
    }
}

// Not hooked: the external actor-pointer copy constructor is not mapped.
// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162aa10
void CPartyManager::FUN_14162aa10(TPtr<PCBase> actor)
{
    MS2Ptr<CPartyMember> member = FUN_14162afc0(FUN_141656a80(actor.operator->()));
    if (member.get() != NULL) {
        member->FUN_141637a60(actor->vfunc_78());
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) FUN_141a74d50(ui, member.operator->(), 8);
    }
}

// @0x14162ab00
int CPartyManager::FUN_14162ab00() { return partyId; }
MS2_REPLACE_METHOD(0x14162AB00, CPartyManager, FUN_14162ab00, 14, 0x92BE4827);

// @0x14162ab20
bool CPartyManager::FUN_14162ab20() { return FUN_14162af00() > 1; }
MS2_REPLACE_METHOD(0x14162AB20, CPartyManager, FUN_14162ab20, 52, 0x99BFAE5D);

// @0x14162ab60
bool CPartyManager::FUN_14162ab60()
{
    if (!FUN_14162ab20())
    {
        return false;
    }
    return FUN_141630c30(DAT_143ab2828);
}
MS2_REPLACE_METHOD(0x14162AB60, CPartyManager, FUN_14162ab60, 52, 0x4F5E0B6C);

// @0x14162aba0
bool CPartyManager::FUN_14162aba0(int id) { return partyId == id; }
MS2_REPLACE_METHOD(0x14162ABA0, CPartyManager, FUN_14162aba0, 52, 0x33C13BD7);

// @0x14162abe0
bool CPartyManager::FUN_14162abe0() { return matchmaking; }
MS2_REPLACE_METHOD(0x14162ABE0, CPartyManager, FUN_14162abe0, 15, 0x82B3C62D);

// @0x14162ac00
bool CPartyManager::FUN_14162ac00(int bit)
{
    if (bit == 0) return false;
    return permissions.FUN_1402e4ee0(bit);
}
MS2_REPLACE_METHOD(0x14162AC00, CPartyManager, FUN_14162ac00, 50, 0xBD8235D8);

// @0x14162ac40
bool CPartyManager::FUN_14162ac40() { return permissions.FUN_140b912f0(); }
MS2_REPLACE_METHOD(0x14162AC40, CPartyManager, FUN_14162ac40, 31, 0x7B803D45);

// @0x14162ac70
bool CPartyManager::FUN_14162ac70(int key)
{
    if (!FUN_14162ab20()) {
        if (FUN_140d9f880(FUN_140931510(), key) >= 10) return false;
        return true;
    }
    for (unsigned i = 0; i < members.GetCount(); ++i)
        if (members[i]->counters.FUN_140268570(key) >= 10) return false;
    return true;
}
MS2_REPLACE_METHOD(0x14162AC70, CPartyManager, FUN_14162ac70, 177, 0xA0EAF4F7);

// @0x14162ad30
bool CPartyManager::FUN_14162ad30() { return flag29; }
MS2_REPLACE_METHOD(0x14162AD30, CPartyManager, FUN_14162ad30, 15, 0x52CC66EC);

// @0x14162ad50
int CPartyManager::FUN_14162ad50(CStringW name)
{
    CPartyMember* p = FUN_14162b0c0(name).get();
    if (p != NULL) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14162AD50, CPartyManager, FUN_14162ad50, 187, 0xEF192C97);

// @0x14162ae20
int CPartyManager::FUN_14162ae20(__int64 id) 
{
    CPartyMember* p = FUN_14162afc0(id).get();
    if (p != NULL) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14162AE20, CPartyManager, FUN_14162ae20, 105, 0x72DB080E);

// @0x14162ae90
int CPartyManager::FUN_14162ae90(__int64 id) 
{
    CPartyMember* p = FUN_14162b260(id).get();
    if (p != NULL) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14162AE90, CPartyManager, FUN_14162ae90, 105, 0xB07D31F7);

// @0x14162af00
int CPartyManager::FUN_14162af00() { return static_cast<int>(members.GetCount()); }
MS2_REPLACE_METHOD(0x14162AF00, CPartyManager, FUN_14162af00, 31, 0x65E40168);

// @0x14162af30
int CPartyManager::FUN_14162af30(__int64 id)
{
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p == NULL) return -1;
    return p->index;
}
MS2_REPLACE_METHOD(0x14162AF30, CPartyManager, FUN_14162af30, 123, 0x7B909FCE);

// @0x14162afc0
MS2Ptr<CPartyMember> CPartyManager::FUN_14162afc0(__int64 id)
{
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p->user.m_8 == id) return p;
    }
    return MS2Ptr<CPartyMember>(0);
}
MS2_REPLACE_METHOD(0x14162AFC0, CPartyManager, FUN_14162afc0, 235, 0x4D1D7331);

// @0x14162b0c0
MS2Ptr<CPartyMember> CPartyManager::FUN_14162b0c0(CStringW name)
{
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p->user.FUN_1408f19e0().CompareNoCase(name) == 0) return p;
    }
    return MS2Ptr<CPartyMember>(0);
}
MS2_REPLACE_METHOD(0x14162B0C0, CPartyManager, FUN_14162b0c0, 396, 0x2A995807);

// @0x14162b260
MS2Ptr<CPartyMember> CPartyManager::FUN_14162b260(__int64 id)
{
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p->user.m_0 == id) return p;
    }
    return MS2Ptr<CPartyMember>(0);
}
MS2_REPLACE_METHOD(0x14162B260, CPartyManager, FUN_14162b260, 235, 0x00372A3F);

// @0x14162b360
MS2Ptr<CPartyMember> CPartyManager::FUN_14162b360(int index)
{
    if (!(index >= 0 && index < static_cast<int>(members.GetCount())))
    {
        return MS2Ptr<CPartyMember>(0);
    }
    return members[index];
}
MS2_REPLACE_METHOD(0x14162B360, CPartyManager, FUN_14162b360, 143, 0x687FF358);

// @0x14162b400
MS2Ptr<CPartyMember> CPartyManager::FUN_14162b400()
{
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (p->leader != 0) return p;
    }
    return MS2Ptr<CPartyMember>(0);
}
MS2_REPLACE_METHOD(0x14162B400, CPartyManager, FUN_14162b400, 225, 0xD11D833A);

// @0x14162b4f0
CStringW CPartyManager::FUN_14162b4f0() { return partyName; }
MS2_REPLACE_METHOD(0x14162B4F0, CPartyManager, FUN_14162b4f0, 66, 0x1554B6B8);

// @0x14162b540
int CPartyManager::FUN_14162b540() { return partyKind; }
MS2_REPLACE_METHOD(0x14162B540, CPartyManager, FUN_14162b540, 14, 0x7245C177);

// @0x14162b560
void CPartyManager::FUN_14162b560(CStringW name)
{
    if (leaderName == name) return;
    {
        MS2Ptr<CPartyMember> oldLeader = FUN_14162b0c0(leaderName);
        if (oldLeader.get() != NULL) {
            oldLeader->FUN_141637b10(1);
            void* ui = FUN_140a8a680(0x4e45);
            if (ui != NULL) FUN_141a74d50(ui, oldLeader.get(), 0x100);
        }
    }
    {
        MS2Ptr<CPartyMember> newLeader = FUN_14162b0c0(name);
        if (newLeader.get() != NULL) {
            newLeader->FUN_141637b10(2);
            void* ui = FUN_140a8a680(0x4e45);
            if (ui != NULL) FUN_141a74d50(ui, newLeader.get(), 0x100);
        }
    }
    leaderName = name;
}
MS2_REPLACE_METHOD(0x14162B560, CPartyManager, FUN_14162b560, 460, 0x62052551);

// @0x14162b740
void CPartyManager::FUN_14162b740() { FUN_14162b560(L""); }
MS2_REPLACE_METHOD(0x14162B740, CPartyManager, FUN_14162b740, 62, 0x4A578BE4);

// @0x14162b790
void CPartyManager::FUN_14162b790()
{
    FUN_141adc5d0(FUN_1403ed2b0(), 0x4e45);
    FUN_141adc5d0(FUN_1403ed2b0(), 0x4f23);
}
MS2_REPLACE_METHOD(0x14162B790, CPartyManager, FUN_14162b790, 50, 0x88AED988);

// @0x14162b7d0
void CPartyManager::SendPartyMode4(CStringW name)
{
    MS2Ptr<CPartyMember> p = FUN_14162b0c0(name);
    if (p.get() != NULL) {
        COutPacket packet(0x2c, 0);
        packet.Encode1(4);
        packet.Encode8(p->FUN_141637bb0());
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x14162B7D0, CPartyManager, SendPartyMode4, 216, 0x0F0F0E53);

// @0x14162b8b0
void CPartyManager::SendPartyMode45(__int64 id)
{
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p.get() != NULL) {
        COutPacket packet(0x2c, 0);
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
    request.name = FUN_14162b4f0();
    request.value = value;
    request.kind = FUN_14162b540();
    COutPacket packet(0x2c, 0);
    packet.Encode1(2);
    FUN_1401fc0b0(&request, packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14162B950, CPartyManager, SendPartyMode2, 211, 0x16AAD5D0);

// @0x14162ba30
ATL::CAtlArray<MS2Ptr<CPartyMember>>& CPartyManager::FUN_14162ba30() { return members; }
MS2_REPLACE_METHOD(0x14162BA30, CPartyManager, FUN_14162ba30, 15, 0x3758D2A9);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162ba50
void CPartyManager::SendPartyMode1(CStringW name)
{
    if (name.IsEmpty()) return;
    Unk_PartyInviteName request;
    request.name = name;
    COutPacket packet(0x2c, 0);
    packet.Encode1(1);
    FUN_1401fbd30(&request, packet);
    FUN_140710590(packet);
    FUN_141276180(DAT_143ae2ca8, CString(""));
}
MS2_REPLACE_METHOD(0x14162BA50, CPartyManager, SendPartyMode1, 239, 0x10B17C55);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162bb50
void CPartyManager::SendPartyMode23(const Unk_PartyRecruitInvite& request)
{
    CStringW name(request.ownerName);
    if (name.IsEmpty()) return;
    if (!(name == static_cast<WorldService*>(FUN_1403ed2d0())->FUN_141bd0d30())) {
        COutPacket packet(0x2c, 0);
        packet.Encode1(0x17);
        FUN_1401fbf70(&request, packet);
        FUN_140710590(packet);
        FUN_141276180(DAT_143ae2ca8, CString(""));
    } else FUN_1412751b0(FUN_1409eec40(0x32e), 0xe);
}
MS2_REPLACE_METHOD(0x14162BB50, CPartyManager, SendPartyMode23, 361, 0x171D882A);

// @0x14162bcc0
void CPartyManager::FUN_14162bcc0(MS2Ptr<CMatchPartyRecruit> recruit)
{
    Unk_PartyRecruitInvite request(recruit);
    SendPartyMode23(request);
}
MS2_REPLACE_METHOD(0x14162BCC0, CPartyManager, FUN_14162bcc0, 111, 0xDEFC1332);

// @0x14162bd40
void CPartyManager::SendRoomDungeon(int value)
{
    COutPacket packet(0x2b, 0);
    packet.Encode1(3);
    packet.Encode4(value);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14162BD40, CPartyManager, SendRoomDungeon, 93, 0xB715FDC7);

// @0x14162bdb0
void CPartyManager::SendPartyMode46()
{
    COutPacket packet(0x2c, 0);
    packet.Encode1(0x2e);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14162BDB0, CPartyManager, SendPartyMode46, 75, 0x02273E69);

// @0x14162be10
void CPartyManager::SendPartyMode3()
{
    COutPacket packet(0x2c, 0);
    packet.Encode1(3);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14162BE10, CPartyManager, SendPartyMode3, 75, 0x87205910);

// @0x14162be70
int CPartyManager::FUN_14162be70()
{
    int count = 0;
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (!p->FUN_141637c20()) ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x14162BE70, CPartyManager, FUN_14162be70, 169, 0x448BA9E2);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162bf20
int CPartyManager::FUN_14162bf20()
{
    int count = 0;
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> member(members[i]);
        if (member == NULL) continue;
        if (member->FUN_141637c20() == true) continue;
        MS2Ptr<CFieldDataCli> field = FUN_140a55460(member->user.m_28);
        if (!(field == NULL) && FUN_140375310(field.operator->()) == 0) ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x14162BF20, CPartyManager, FUN_14162bf20, 354, 0x666BCBA8);

// @0x14162c090
int CPartyManager::FUN_14162c090() { return dungeonId; }
MS2_REPLACE_METHOD(0x14162C090, CPartyManager, FUN_14162c090, 14, 0xBA6447E3);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162c0b0
unsigned short CPartyManager::FUN_14162c0b0()
{
    unsigned short level = 0;
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (!(p == NULL) && !p->FUN_141637c20()) {
            if (level == 0) level = p->user.m_34;
            if (static_cast<unsigned short>(p->user.m_34) < level) level = p->user.m_34;
        }
    }
    return level;
}
MS2_REPLACE_METHOD(0x14162C0B0, CPartyManager, FUN_14162c0b0, 290, 0x73322521);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162c1e0
unsigned CPartyManager::FUN_14162c1e0()
{
    unsigned value = 0;
    for (unsigned i = 0; i < members.GetCount(); ++i) {
        MS2Ptr<CPartyMember> p = members[i];
        if (!(p == NULL) && !p->FUN_141637c20()) {
            if (value == 0) value = p->user.m_d0;
            if (static_cast<unsigned>(p->user.m_d0) < value) value = p->user.m_d0;
        }
    }
    return value;
}
MS2_REPLACE_METHOD(0x14162C1E0, CPartyManager, FUN_14162c1e0, 281, 0x5EFA7901);

// @0x14162c300
bool CPartyManager::FUN_14162c300() { return vote.get() != NULL; }
MS2_REPLACE_METHOD(0x14162C300, CPartyManager, FUN_14162c300, 61, 0xB2E7BDD3);

// @0x14162c350
MS2Ptr<PartyVoteCli> CPartyManager::FUN_14162c350() { return vote; }
MS2_REPLACE_METHOD(0x14162C350, CPartyManager, FUN_14162c350, 67, 0x2F92BE78);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162c3a0
void CPartyManager::FUN_14162c3a0()
{
    void* ui = FUN_140a8a680(0x4e45);
    if (ui != NULL) {
        for (unsigned i = 0; i < members.GetCount(); ++i) {
            if (members[i]->FUN_141637c90() == 1) {
                members[i]->FUN_141637b30(3);
                FUN_141a74d50(ui, members[i].get(), 1);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14162C3A0, CPartyManager, FUN_14162c3a0, 235, 0x62228494);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162c4a0
void CPartyManager::FUN_14162c4a0(int state)
{
    void* ui = FUN_140a8a680(0x4e45);
    if (ui != NULL) {
        FUN_141a75a00(ui, 0);
        for (unsigned i = 0; i < members.GetCount(); ++i) {
            members[i]->FUN_141637b30(state);
            FUN_141a74d50(ui, members[i].get(), 1);
        }
    }
}
MS2_REPLACE_METHOD(0x14162C4A0, CPartyManager, FUN_14162c4a0, 203, 0x1919D602);

// @0x14162c580
void CPartyManager::FUN_14162c580(__int64 id, int state)
{
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p == NULL)
        return;
    p->FUN_141637b30(state);
    void* ui = FUN_140a8a680(0x4e45);
    if (ui != NULL)
        FUN_141a74d50(ui, p.get(), 1);
}
MS2_REPLACE_METHOD(0x14162C580, CPartyManager, FUN_14162c580, 170, 0x2201AA8A);

// @0x14162c630
void CPartyManager::FUN_14162c630() { partyName = L""; partyKind = 0; }
MS2_REPLACE_METHOD(0x14162C630, CPartyManager, FUN_14162c630, 51, 0x6D8B10EA);

// @0x14162c670
void CPartyManager::FUN_14162c670(int index)
{
    if (index < 0 || index >= static_cast<int>(members.GetCount())) return;
    MS2Ptr<CPartyMember> member(members[index]);
    if (member == NULL) return;
    members.RemoveAt(index, 1);
    FUN_140a056c0(FUN_140e09140(), member->FUN_141637bb0());
    FUN_14161cd60(FUN_1409f7c90(), member->FUN_141637bb0());
    void* ui = FUN_140a8a680(0x4e45);
    if (ui != NULL) FUN_141a753d0(ui, member.get());
    FUN_140a056c0(FUN_140e09140(), member->user.m_8);
    for (int i = index; i < static_cast<int>(members.GetCount()); ++i)
        members[i]->FUN_141637cd0(i);
    if (FUN_141adc890(FUN_1403ed2b0(), 0x4e8c)) {
        UIPartyDPSDialog* dps = FUN_1416327a0(0x4e8c);
        if (dps != NULL) FUN_141a7bb70(dps);
    }
    if (FUN_141adc890(FUN_1403ed2b0(), 0x4f23)) {
        UIChaosDPSDialog* dps = FUN_141632700(0x4f23);
        if (dps != NULL) FUN_140e05f80(dps);
    }
}
MS2_REPLACE_METHOD(0x14162C670, CPartyManager, FUN_14162c670, 569, 0xC47B4580);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162c8b0
void CPartyManager::FUN_14162c8b0(CInPacket& packet)
{
    CInputStream& stream = packet;
    partyName = stream.vfunc_o8_8();
    partyKind = stream.vfunc_o8_3();
    Unk_PartyPlayer* player = static_cast<Unk_PartyPlayer*>(
        static_cast<WorldService*>(FUN_1403ed2d0())->FUN_141bd0cc0());
    if (FUN_140ae6540(FUN_1409a8b10())->refuseParty) {
        SendPartyMode2(0x14);
        return;
    }
    if (player != NULL && FUN_140743550(player->FUN_140967420().operator->())) {
        SendPartyMode2(0x15);
    } else {
        CStringW key = StringFormat(L"{0}_{1}", DAT_143ae2c58, partyKind);
        MS2Ptr<Unk_PartyMessage> message = FUN_140d73d20(1,
            FUN_14052bd00(0x2b7, partyName), 0, CStringW(key));
        if (message.get() != NULL) {
            FUN_141a01ca0(message.operator->(), 0x14, 1, GetStringCommon(0x2b8));
            FUN_141a02460(message.operator->(), true);
            FUN_141a02480(message.operator->(), true);
            FUN_141a024a0(message.operator->(), false);
            FUN_140d73c60(message);
        }
    }
}
MS2_REPLACE_METHOD(0x14162C8B0, CPartyManager, FUN_14162c8b0, 892, 0x34000DFD);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162cc40
void CPartyManager::FUN_14162cc40(CInPacket& packet)
{
    int count = FUN_14162af00();
    if (count == 10) return;
    MS2Ptr<CPartyMember> member(new CPartyMember(count));
    member->user.FUN_1408eeb60(&packet);
    FUN_140268210(&member->counters, packet);
    members.Add(member);
    FUN_14161cd60(FUN_1409f7c90(), member->FUN_141637bb0());
    UIDialog* ui = static_cast<UIDialog*>(FUN_140a8a680(0x4e45));
    if (ui != NULL) {
        if (ui->FUN_141924630() == 0) ui->FUN_141924680();
        else FUN_141a752a0(ui, member.get());
    }
    if (FUN_14125bbe0(FUN_140e09150(FUN_1409a8b10())))
        FUN_141adc530(FUN_1403ed2b0(), 0x4f23);
    FUN_140a05670(FUN_140e09140(), member->FUN_141637bb0());
    CStringW text = FUN_14052bd00(0x31c, member->user.FUN_1408f19e0());
    FUN_1412751b0(text, 0xe);
}
MS2_REPLACE_METHOD(0x14162CC40, CPartyManager, FUN_14162cc40, 593, 0x3F7FDB2A);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162cea0
void CPartyManager::FUN_14162cea0(CInPacket& packet)
{
    CInputStream& stream = packet;
    __int64 id = stream.vfunc_o8_4();
    bool disband = stream.vfunc_o8_0();
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p.get() != NULL) {
        if (!disband) {
            int index = FUN_14162af30(id);
            if (index == -1) return;
            FUN_14162c670(index);
            CStringW text = FUN_14052bd00(0x31e, p->FUN_141637bd0());
            FUN_1412751b0(text, 0xe);
        } else {
            FUN_14162a370();
            FUN_141630fd0();
            FUN_141adc5d0(FUN_1403ed2b0(), 0x4e45);
            FUN_1412751b0(GetStringCommon(0x31d), 0xe);
        }
    }
}
MS2_REPLACE_METHOD(0x14162CEA0, CPartyManager, FUN_14162cea0, 458, 0xBE002F26);

// @0x14162d070
void CPartyManager::FUN_14162d070(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p.get() != NULL) {
        if (DAT_143ab2828 == p->FUN_141637bb0()) {
            FUN_14162a370();
            FUN_141630fd0();
            FUN_141adc5d0(FUN_1403ed2b0(), 0x4e45);
            FUN_1412751b0(GetStringCommon(799), 0xe);
        } else {
            int index = FUN_14162af30(id);
            if (index == -1)
                return;
            FUN_14162c670(index);
            CStringW text = FUN_14052bd00(800, p->FUN_141637bd0());
            FUN_1412751b0(text, 0xe);
        }
    }
}
MS2_REPLACE_METHOD(0x14162D070, CPartyManager, FUN_14162d070, 424, 0x58AEE3EB);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162d220
void CPartyManager::FUN_14162d220()
{
    FUN_14162a370();
    FUN_141630fd0();
    FUN_141adc5d0(FUN_1403ed2b0(), 0x4e45);
    FUN_1412751b0(GetStringCommon(0x321), 0xe);
}
MS2_REPLACE_METHOD(0x14162D220, CPartyManager, FUN_14162d220, 123, 0x0016246B);

// @0x14162d2b0
void CPartyManager::FUN_14162d2b0(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW name;
    if (id != 0 && id != leaderId) {
        __int64 oldId = leaderId;
        MS2Ptr<CPartyMember> oldLeader = FUN_14162afc0(oldId);
        if (oldLeader.get() != NULL) oldLeader->FUN_141637af0(0);
        MS2Ptr<CPartyMember> newLeader = FUN_14162afc0(id);
        if (newLeader.get() != NULL) {
            newLeader->FUN_141637af0(1);
            name = newLeader->FUN_141637bd0();
        }
        leaderId = id;
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) FUN_141a74f50(ui, oldLeader.get(), newLeader.get());
        if (DAT_143ab2828 == oldId || DAT_143ab2828 == id) FUN_140d0b030(FUN_140c8dac0());
    }
    if (FUN_14162af00() > 1) {
        CStringW text;
        if (DAT_143ab2828 == leaderId) text = GetStringCommon(0x324);
        else text = FUN_14052bd00(0x325, name);
        FUN_1412751b0(text, 0xe);
    }
}
MS2_REPLACE_METHOD(0x14162D2B0, CPartyManager, FUN_14162d2b0, 747, 0x05A83C2F);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162d5b0
void CPartyManager::FUN_14162d5b0(CInPacket& packet)
{
    CInputStream& stream = packet;
    if (partyId != 0) {
        FUN_14162a370();
        FUN_141630fd0();
        FUN_141adc5d0(FUN_1403ed2b0(), 0x4e45);
    }
    bool announce = stream.vfunc_o8_0();
    partyId = stream.vfunc_o8_3();
    leaderId = stream.vfunc_o8_4();
    unsigned count = stream.vfunc_o8_1();
    members.RemoveAll();
    for (int i = 0; i < static_cast<int>(count) && i < 10; ++i) {
        MS2Ptr<CPartyMember> p(new CPartyMember(i));
        p->offline = stream.vfunc_o8_0();
        p->user.FUN_1408eeb60(&packet);
        FUN_140268210(&p->counters, stream);
        if (FUN_141630c30(p->user.m_8)) p->FUN_141637af0(1);
        members.Add(p);
        FUN_14161cd60(FUN_1409f7c90(), p->FUN_141637bb0());
        FUN_140a05670(FUN_140e09140(), p->FUN_141637bb0());
    }
    FUN_14070f300(stream, matchmaking);
    FUN_14070f480(stream, dungeonId);
    FUN_14031bf10(stream, permissions);
    FUN_14070f300(stream, flag29);
    __int64 previousRecruit = recruitment.recruitId;
    unsigned hasRecruit = stream.vfunc_o8_1();
    if (hasRecruit != 0) recruitment.FUN_140694c10(packet);
    bool changed = previousRecruit != recruitment.recruitId;
    if (FUN_14162af00() > 1) {
        FUN_141adc530(FUN_1403ed2b0(), 0x4e45);
        if (FUN_14125bbe0(FUN_140e09150(FUN_1409a8b10()))) FUN_141adc530(FUN_1403ed2b0(), 0x4f23);
    }
    if (announce && members.GetCount() > 1) FUN_1412751b0(GetStringCommon(0x31b), 0xe);
    if (changed) {
        if (FUN_141adc890(FUN_1403ed2b0(), 0x4eda)) {
            void* ui = FUN_1413226d0(0x4eda);
            if (ui != NULL) FUN_140f8ee00(ui, recruitment);
        }
    }
}
MS2_REPLACE_METHOD(0x14162D5B0, CPartyManager, FUN_14162d5b0, 1356, 0x74FF5328);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162db10
void CPartyManager::FUN_14162db10(CInPacket& packet)
{
    Unk_UserProxy user;
    user.FUN_1408eeb60(&packet);
    MS2Ptr<CPartyMember> p = FUN_14162afc0(user.m_8);
    if (p.get() == NULL) {
        int count = FUN_14162af00();
        if (count == 10) return;
        int index = count;
        p.AssignRaw(new CPartyMember(index));
        p->user.FUN_1408efa70(user);
        members.Add(p);
        FUN_14161cd60(FUN_1409f7c90(), p->FUN_141637bb0());
        FUN_140a05670(FUN_140e09140(), p->FUN_141637bb0());
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) FUN_141a752a0(ui, p.get());
        CStringW text = FUN_14052bd00(0x31c, user.FUN_1408f19e0());
        FUN_1412751b0(text, 0xe);
    } else {
        p->FUN_141637a40(false);
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) FUN_141a74d50(ui, p.get(), 0x1ff);
        CStringW text = FUN_14052bd00(0x322, user.FUN_1408f19e0());
        FUN_1412751b0(text, 0xe);
    }
}
MS2_REPLACE_METHOD(0x14162DB10, CPartyManager, FUN_14162db10, 808, 0x4F26012C);

// @0x14162de40
void CPartyManager::FUN_14162de40(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p.get() != NULL) {
        p->FUN_141637a40(true);
        if (vote.get() != NULL) vote->vfunc_6(id);
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) FUN_141a74d50(ui, p.get(), 1);
        CStringW text = FUN_14052bd00(0x323, p->FUN_141637bd0());
        FUN_1412751b0(text, 0xe);
    }
}
MS2_REPLACE_METHOD(0x14162DE40, CPartyManager, FUN_14162de40, 377, 0xDA2CA186);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162dfc0
void CPartyManager::FUN_14162dfc0(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p.get() != NULL) {
        CString oldName = p->user.FUN_1408f1a60();
        p->user.FUN_1408ec410(packet);
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) FUN_141a74d50(ui, p.get(), 399);
        if (p->user.m_8 == DAT_143ab2828) {
            ui = FUN_140a8a680(0x4e45);
            if (ui != NULL) FUN_141a74ea0(ui);
        }
    }
}
MS2_REPLACE_METHOD(0x14162DFC0, CPartyManager, FUN_14162dfc0, 312, 0xF779CB13);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162e100
void CPartyManager::FUN_14162e100(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p.get() != NULL) {
        CString oldName = p->user.FUN_1408f1a60();
        p->user.FUN_1408eeb60(&packet);
        void* ui = FUN_140a8a680(0x4e45);
        if (ui != NULL) FUN_141a74d50(ui, p.get(), 399);
        if (p->user.m_8 == DAT_143ab2828) {
            ui = FUN_140a8a680(0x4e45);
            if (ui != NULL) FUN_141a74ea0(ui);
        }
    }
}
MS2_REPLACE_METHOD(0x14162E100, CPartyManager, FUN_14162e100, 312, 0x52858474);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162e240
void CPartyManager::FUN_14162e240(CInPacket& packet)
{
    CInputStream& stream = packet;
    __int64 id = stream.vfunc_o8_4();
    Unk_PartyCounters counters;
    FUN_140268210(&counters, stream);
    MS2Ptr<CPartyMember> member = FUN_14162afc0(id);
    if (member.get() != NULL) member->FUN_141637b50(&counters);
}
MS2_REPLACE_METHOD(0x14162E240, CPartyManager, FUN_14162e240, 199, 0xF491A26D);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162e310
void CPartyManager::FUN_14162e310(CInPacket& packet)
{
    CInputStream& stream = packet;
    __int64 id = stream.vfunc_o8_4();
    int value = stream.vfunc_o8_3();
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p.get() != NULL) p->user.m_d0 = value;
}
MS2_REPLACE_METHOD(0x14162E310, CPartyManager, FUN_14162e310, 171, 0x3FCCCFBD);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162e3d0
void CPartyManager::FUN_14162e3d0(CInPacket& packet)
{
    CInputStream& stream = packet;
    __int64 id = stream.vfunc_o8_4();
    unsigned char result = stream.vfunc_o8_1();
    MS2Ptr<CPartyMember> p = FUN_14162afc0(id);
    if (p.get() != NULL) {
        if (p->FUN_141637bb0() == DAT_143ab2828) return;
        if (result == 0) FUN_1412751b0(FUN_14052bd00(0x326, p->FUN_141637bd0()), 0xe);
        else FUN_1412751b0(FUN_14052bd00(0x327, p->FUN_141637bd0()), 0xe);
    }
}
MS2_REPLACE_METHOD(0x14162E3D0, CPartyManager, FUN_14162e3d0, 497, 0x49BC7140);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162e5d0
void CPartyManager::FUN_14162e5d0(CInPacket& packet)
{
    CInputStream& stream = packet;
    CStringW key = stream.vfunc_o8_8();
    CStringW sound = stream.vfunc_o8_8();
    CStringW argument = stream.vfunc_o8_8();
    CStringW text = FUN_1405c2690(key, argument);
    FUN_1412751b0(text, 2);
    FUN_1412760f0(sound, CString(""));
}
MS2_REPLACE_METHOD(0x14162E5D0, CPartyManager, FUN_14162e5d0, 333, 0xD8F6A23F);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162e730
void CPartyManager::FUN_14162e730(CInPacket& packet)
{
    CStringW text = StringIdInterface(packet).FUN_141024e60();
    CStringW sound = static_cast<CInputStream&>(packet).vfunc_o8_8();
    FUN_1412751b0(text, 2);
    FUN_1412760f0(sound, CString(""));
}
MS2_REPLACE_METHOD(0x14162E730, CPartyManager, FUN_14162e730, 224, 0xD696069F);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162e820
void CPartyManager::FUN_14162e820(CInPacket& packet)
{
    CInputStream& stream = packet;
    int previousDungeon = dungeonId;
    matchmaking = stream.vfunc_o8_0();
    dungeonId = stream.vfunc_o8_3();
    if (!matchmaking) {
        if (FUN_14162ab20() && previousDungeon != 0 && dungeonId != 0 && previousDungeon != dungeonId) {
            CStringW name = FUN_1401a9d70()->FUN_141811980(0x14, dungeonId);
            FUN_1412751f0(FUN_1405c2690(L"s_party_change_help_dungeon", name), 1, 1);
        }
    }
}
MS2_REPLACE_METHOD(0x14162E820, CPartyManager, FUN_14162e820, 411, 0x58877D82);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162e9d0
void CPartyManager::FUN_14162e9d0(CInPacket& packet)
{
    CMatchPartyRecruit updated;
    if (static_cast<CInputStream&>(packet).vfunc_o8_1() != 0) updated.FUN_140694c10(packet);
    FUN_141631f30(recruitment, updated);
    recruitment.FUN_140694f70(updated);
}
MS2_REPLACE_METHOD(0x14162E9D0, CPartyManager, FUN_14162e9d0, 178, 0x25C43414);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162ea90
void CPartyManager::FUN_14162ea90(CInPacket& packet)
{
    CInputStream& stream = packet;
    unsigned char kind = stream.vfunc_o8_1();
    bool registered = stream.vfunc_o8_0();
    bool announce = stream.vfunc_o8_0();
    FUN_14031bf10(stream, permissions);
    if (announce) {
        CStringW name = FUN_140cbf840(FUN_140217850(kind));
        if (registered) {
            if (FUN_14162ab20())
                FUN_1412751b0(FUN_1405c2690(L"s_party_match_dungeon_register", name), 2);
            FUN_141276180(CString("Dungeon_Room_searchParty"), CString(""));
        } else {
            if (FUN_14162ab20())
                FUN_1412751b0(FUN_1405c2690(L"s_party_match_dungeon_unregister", name), 2);
            FUN_141276180(CString("Dungeon_Room_searchPartyCancel"), CString(""));
        }
    }
}
MS2_REPLACE_METHOD(0x14162EA90, CPartyManager, FUN_14162ea90, 703, 0x57B044C4);

// Not hooked: the callback object carries DLL-local Delegate RTTI.
// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
#ifndef MS2_HOOK_DLL
// @0x14162ed60
void CPartyManager::FUN_14162ed60()
{
    FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>(this, &CPartyManager::FUN_141630c70), L"s_party_match_dungeon");
}
#endif

// @0x14162ee10
void CPartyManager::FUN_14162ee10(CInPacket& packet)
{
    __int64 value = static_cast<CInputStream&>(packet).vfunc_o8_4();
    FUN_140d9f310(FUN_140931510(), value);
}
MS2_REPLACE_METHOD(0x14162EE10, CPartyManager, FUN_14162ee10, 76, 0x8AE4F91C);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x14162ee70
void CPartyManager::FUN_14162ee70(CInPacket& packet)
{
    CInputStream& stream = packet;
    __int64 id = stream.vfunc_o8_4();
    CStringW name = stream.vfunc_o8_8();
    CStringW text = StringIdInterface(packet).FUN_141024e60();
    if (!FUN_140a25840(FUN_1409c1730(), 0, name)) {
        if (FUN_140ae5240(FUN_14097a780(), name) == 0) {
            if (id != 0 && FUN_140ae51b0(FUN_14097a780(), id) != 0) return;
            FUN_1412751b0(text, 2);
        }
    }
}
MS2_REPLACE_METHOD(0x14162EE70, CPartyManager, FUN_14162ee70, 428, 0x5978F40A);

// MS2-FUNCTIONAL: retain each result case and message API; compact temporaries.
// @0x14162f030
void CPartyManager::FUN_14162f030(CInPacket& packet)
{
    CInputStream& stream = packet;
    unsigned result = stream.vfunc_o8_1();
    CStringW name = stream.vfunc_o8_8();
    switch (result - 2) {
    case 0: FUN_1412751b0(FUN_14052bd00(0x32d, name), 0x14); break;
    default: FUN_1412751b0(FUN_14052bd00(0x979, name), 0x14); break;
    case 2: FUN_1412751b0(GetStringCommon(0x32c), 0x14); break;
    case 3: FUN_1412751b0(FUN_14052bd00(0x32a, name), 0x14); break;
    case 5: case 6: case 0xb: FUN_1412751b0(FUN_14052bd00(0x329, name), 0x14); break;
    case 7: FUN_1412751b0(FUN_14052bd00(0x330, name), 0x14); break;
    case 8: FUN_1412751f0(FUN_1409eec40(0x32a), 1, 1); break;
    case 9: FUN_1412751b0(FUN_14052bd00(0x32e, name), 0x14); break;
    case 10: FUN_1412751b0(FUN_14052bd00(0x333, name), 0x14); break;
    case 0xc: FUN_1412751b0(GetStringCommon(0x32f), 0x14); break;
    case 0xd: FUN_1412751f0(FUN_14052bd00(0x32b, name), 1, 1); break;
    case 0xe: FUN_1412751b0(FUN_14052bd00(0x336, name), 0x14); break;
    case 0xf: FUN_1412751b0(FUN_14052bd00(0x337, name), 0x14); break;
    case 0x10: FUN_1412751b0(FUN_14052bd00(0x338, name), 0x14); break;
    case 0x11: FUN_141275260(0x339, 1, 1); break;
    case 0x12: FUN_1412751b0(FUN_14052bd00(0x331, name), 0x14); break;
    case 0x13: FUN_1412751b0(FUN_14052bd00(0x332, name), 0x14); break;
    case 0x14: FUN_141275260(0x33b, 1, 1); break;
    case 0x15: FUN_1412751b0(FUN_14052bd00(0x33c, name), 0x14); break;
    case 0x16: FUN_141275260(0x33a, 1, 1); break;
    case 0x17: FUN_141275260(0x33d, 1, 1); break;
    case 0x18: FUN_1412751b0(FUN_14052bd00(0x33e, name), 0x14); break;
    case 0x19: FUN_1412751b0(FUN_14052bd00(0x35, name), 0x14); break;
    case 0x1a: FUN_1412751f0(FUN_140298ea0(L"s_party_err_inviteMe"), 1, 1); break;
    case 0x1b: FUN_140d73ff0(L"s_room_party_err_is_in_user"); break;
    case 0x1c: FUN_1412751f0(FUN_140298ea0(L"s_party_invite_boss_room"), 1, 1); break;
    case 0x1d: FUN_1412751f0(FUN_140298ea0(L"s_party_err_not_found"), 1, 1); break;
    case 0x1e: FUN_1412751f0(FUN_1405c2690(L"s_party_request_invite", name), 1, 1); break;
    case 0x1f: FUN_1412751f0(FUN_140298ea0(L"s_party_err_already_vote"), 1, 1); break;
    case 0x20: FUN_1412751f0(FUN_140298ea0(L"s_party_err_vote_need_more_people"), 1, 1); break;
    case 0x21: FUN_1412751f0(FUN_140298ea0(L"s_party_err_vote_cooldown"), 1, 1); break;
    case 0x22: FUN_1412751f0(FUN_1405c2690(L"s_party_err_vote_cannot_kick_vote", FUN_141630db0(name)), 1, 1); break;
    case 0x23: FUN_1412751f0(FUN_140298ea0(L"s_party_err_vote_cannot_kick_vote_only_dungeon"), 1, 1); break;
    case 0x24: FUN_1412751f0(GetStringCommon(0x341), 1, 1); break;
    case 0x25: { CStringW key(L"s_party_expel_maple_survival_squad"); FUN_1412751f0(GetStringCommonByKey(key), 1, 1); } break;
    case 0x26: FUN_140d73ff0(L"s_dungeonMatch_error_isNotChief"); break;
    case 0x27: FUN_140d73ff0(L"s_dungeonMatch_error_hasOfflineUser"); break;
    case 0x28: FUN_140d73ff0(L"s_dungeonMatch_error_insideDungeonUser"); break;
    case 0x29: FUN_1412751f0(FUN_140298ea0(L"s_party_err_dungeon_match_another"), 1, 1); break;
    case 0x2a: FUN_1412751f0(FUN_140298ea0(L"s_party_err_isNotChief"), 1, 1); break;
    case 0x2b: FUN_1412751f0(FUN_140298ea0(L"s_party_err_hasOfflineUser"), 1, 1); break;
    case 0x2c: FUN_1412751f0(FUN_140298ea0(L"s_party_err_inside_survival"), 1, 1); break;
    case 0x2d: FUN_1412751f0(FUN_140298ea0(L"s_party_err_another_matching"), 1, 1); break;
    case 0x2e: FUN_1412751f0(FUN_140298ea0(L"s_party_err_survival_has_solo_register"), 1, 1); break;
    case 0x2f: FUN_1412751f0(FUN_140298ea0(L"s_maple_survival_error_squad_register_over_count"), 1, 1); break;
    }
}
MS2_REPLACE_METHOD(0x14162F030, CPartyManager, FUN_14162f030, 4585, 0x989DDB69);

// @0x1416302f0
void CPartyManager::FUN_1416302f0(CInPacket& packet)
{
    unsigned milliseconds = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned seconds = milliseconds / 1000 + 1;
    FUN_1412751b0(FUN_140938ae0(L"s_party_find_dungeon_helper_cooldown", seconds), 0x14);
}
MS2_REPLACE_METHOD(0x1416302F0, CPartyManager, FUN_1416302f0, 186, 0x6CE86D98);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x1416303b0
void CPartyManager::FUN_1416303b0(CInPacket& packet)
{
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    FUN_141630cb0();
    if (invitations.find(name) == invitations.end()) {
        void* ui = FUN_140a3ab70(0x4e61);
        if (ui != NULL) {
            FUN_141a239e0(ui, name);
            CMsTime expiry(FUN_140869440());
            FUN_14086a880(expiry, 1);
            invitations.insert(std::make_pair(name, expiry));
        }
    }
}
MS2_REPLACE_METHOD(0x1416303B0, CPartyManager, FUN_1416303b0, 398, 0xE942D0CD);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x141630550
void CPartyManager::FUN_141630550(CInPacket& packet)
{
    vote = FUN_140a89240(static_cast<CInputStream&>(packet).vfunc_o8_1());
    if (!(vote == NULL)) {
        vote->vfunc_1(packet);
        vote->vfunc_2();
    }
}
MS2_REPLACE_METHOD(0x141630550, CPartyManager, FUN_141630550, 269, 0x645860E9);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x141630670
void CPartyManager::FUN_141630670(CInPacket& packet)
{
    CInputStream& stream = packet;
    __int64 id = stream.vfunc_o8_4();
    bool yes = stream.vfunc_o8_0();
    if (!(vote == NULL)) vote->FUN_140a894e0(id, yes);
}
MS2_REPLACE_METHOD(0x141630670, CPartyManager, FUN_141630670, 163, 0x94778140);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x141630720
void CPartyManager::FUN_141630720()
{
    if (vote.get() != NULL) vote->vfunc_3();
    FUN_141631030();
}
MS2_REPLACE_METHOD(0x141630720, CPartyManager, FUN_141630720, 93, 0xB83564F9);

// Not hooked: constructing NotifySurvivalState here installs DLL-local RTTI.
// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
#ifndef MS2_HOOK_DLL
// @0x141630790
void CPartyManager::FUN_141630790(CInPacket& packet)
{
    CInputStream& stream = packet;
    flag29 = stream.vfunc_o8_0();
    bool notify = stream.vfunc_o8_0();
    if (notify) {
        int channel = 0xe;
        if (FUN_14162ab20() == true) channel = 2;
        if (!flag29) {
            CStringW key(L"s_maple_survival_squad_unregister_squad");
            FUN_1412751b0(GetStringCommonByKey(key), channel);
            FUN_141276180(CString("Dungeon_Room_searchPartyCancel"), CString(""));
        } else {
            CStringW key(L"s_maple_survival_squad_register_squad");
            FUN_1412751b0(GetStringCommonByKey(key), channel);
            FUN_141276180(CString("Dungeon_Room_searchParty"), CString(""));
        }
        FUN_140da4fe0(FUN_140939a10(), MS2Ptr<NotifyObject>(new NotifySurvivalState));
    }
}
#endif

// Not hooked: the callback object carries DLL-local Delegate RTTI.
// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
#ifndef MS2_HOOK_DLL
// @0x141630a60
void CPartyManager::FUN_141630a60(CInPacket& packet)
{
    int dungeon = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (!FUN_14162ab60()) {
        CStringW name = FUN_1401a9d70()->FUN_141811980(0x14, dungeon);
        FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &CPartyManager::FUN_141630c70),
            FUN_1405c2690(L"s_party_create_dungeon", name));
        FUN_141276180(CString("Dungeon_Room_Open"), CString(""));
    }
}
#endif

// @0x141630c30
bool CPartyManager::FUN_141630c30(__int64 id) { return leaderId == id; }
MS2_REPLACE_METHOD(0x141630C30, CPartyManager, FUN_141630c30, 55, 0xE1350063);

// @0x141630c70
bool CPartyManager::FUN_141630c70(int result, const CMsgBoxData&)
{
    if (result != 0) return true;
    SendRoomDungeon(0);
    return true;
}
MS2_REPLACE_METHOD(0x141630C70, CPartyManager, FUN_141630c70, 48, 0xE4C414EC);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x141630cb0
void CPartyManager::FUN_141630cb0()
{
    std::map<CStringW, CMsTime>::iterator it = invitations.begin();
    std::map<CStringW, CMsTime> retained;
    CMsTime now(FUN_140869440());
    while (it != invitations.end()) {
        if (now < it->second) retained.insert(*it);
        it++;
    }
    invitations.swap(retained);
}
MS2_REPLACE_METHOD(0x141630CB0, CPartyManager, FUN_141630cb0, 242, 0x27F93552);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x141630db0
CStringW CPartyManager::FUN_141630db0(CStringW input)
{
    CStringW result;
    ATL::CAtlArray<int> values;
    FUN_141632630(input, values, L",");
    for (unsigned i = 0; i < values.GetCount(); ++i) {
        if (i == 0) result += StringFormat(L"{0}", FUN_140cbf840(values[i]));
        else result += StringFormat(L", {0}", FUN_140cbf840(values[i]));
    }
    return result;
}
MS2_REPLACE_METHOD(0x141630DB0, CPartyManager, FUN_141630db0, 523, 0x1088CBCE);

// @0x141630fd0
void CPartyManager::FUN_141630fd0()
{
    recruitment.FUN_140694ab0();
    recruitPending = 0;
    void* ui = FUN_1413226d0(0x4eda);
    if (ui != NULL) FUN_140f8edb0(ui);
}
MS2_REPLACE_METHOD(0x141630FD0, CPartyManager, FUN_141630fd0, 79, 0x3E76544C);

// @0x141631030
void CPartyManager::FUN_141631030() { vote = 0; }
MS2_REPLACE_METHOD(0x141631030, CPartyManager, FUN_141631030, 35, 0x0C867F49);

// @0x141631060
void CPartyManager::FUN_141631060()
{
    recruitment.FUN_140694ab0();
    recruitPending = 0;
    void* ui = FUN_1413226d0(0x4eda);
    if (ui != NULL) FUN_140f8ee50(ui, recruitment);
}
MS2_REPLACE_METHOD(0x141631060, CPartyManager, FUN_141631060, 91, 0x2A2536B7);

// @0x1416310d0
void CPartyManager::OnMatchParty(CInPacket& packet)
{
    int type = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (type) {
    case 0: FUN_141631370(packet); break;
    case 1: FUN_141631410(packet); break;
    case 2: FUN_1416314c0(packet); break;
    case 4: FUN_141631700(packet); break;
    }
}
MS2_REPLACE_METHOD(0x1416310D0, CPartyManager, OnMatchParty, 164, 0x4143B2A2);

// @0x141631180
void CPartyManager::SendMatchPartyMode0(const Unk_PartyRecruitRequest& request)
{
    COutPacket packet(0x6e, 0);
    packet.Encode1(0);
    FUN_140694280(&request, packet);
    FUN_140710590(packet);
    recruitPending = 1;
}
MS2_REPLACE_METHOD(0x141631180, CPartyManager, SendMatchPartyMode0, 109, 0xB559BF4D);

// @0x141631200
void CPartyManager::SendMatchPartyMode1()
{
    if (recruitment.recruitId == 0)
        return;
    COutPacket packet(0x6e, 0);
    packet.Encode1(1);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141631200, CPartyManager, SendMatchPartyMode1, 92, 0xF01C980A);

// @0x141631270
void CPartyManager::SendMatchPartyMode2(const CMatchPartyRecruitSchCond& condition)
{
    COutPacket packet(0x6e, 0);
    packet.Encode1(2);
    FUN_140694630(&condition, packet);
    FUN_140710590(packet);
    if (condition.page <= 1) searchPending = 1;
}
MS2_REPLACE_METHOD(0x141631270, CPartyManager, SendMatchPartyMode2, 120, 0x92FC6B3D);

// @0x1416312f0
void CPartyManager::FUN_1416312f0(int id)
{
    if (partyId != id) return;
    deadline = FUN_141472bc0() + 10000;
}
MS2_REPLACE_METHOD(0x1416312F0, CPartyManager, FUN_1416312f0, 55, 0x412FA0CA);

// @0x141631330
int CPartyManager::FUN_141631330()
{
    if (deadline < FUN_141472bc0()) return 0;
    return deadline - FUN_141472bc0();
}
MS2_REPLACE_METHOD(0x141631330, CPartyManager, FUN_141631330, 56, 0x0F45776B);

// @0x141631370
void CPartyManager::FUN_141631370(CInPacket& packet)
{
    recruitPending = 0;
    CMatchPartyRecruit updated;
    updated.FUN_140694c10(packet);
    FUN_141631f30(recruitment, updated);
    recruitment.FUN_140694f70(updated);
}
MS2_REPLACE_METHOD(0x141631370, CPartyManager, FUN_141631370, 142, 0x718E9365);

// @0x141631410
void CPartyManager::FUN_141631410(CInPacket& packet)
{
    __int64 id = static_cast<CInputStream&>(packet).vfunc_o8_4();
    if (recruitment.recruitId == id) {
        CMatchPartyRecruit empty;
        FUN_141631f30(recruitment, empty);
        recruitment.FUN_140694ab0();
    }
}
MS2_REPLACE_METHOD(0x141631410, CPartyManager, FUN_141631410, 168, 0xF4FB48FA);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x1416314c0
void CPartyManager::FUN_1416314c0(CInPacket& packet)
{
    CInputStream& stream = packet;
    unsigned count = stream.vfunc_o8_3();
    if (searchPending != 0) {
        results.RemoveAll();
        recruits.RemoveAll();
        searchPending = 0;
    }
    int last;
    if (static_cast<int>(results.GetCount()) - 1 < 0) last = 0;
    else last = static_cast<int>(results.GetCount()) - 1;
    for (unsigned i = 0; i < count; ++i) {
        if (stream.vfunc_o8_1() != 0) {
            MS2Ptr<CMatchPartyRecruit> p(new CMatchPartyRecruit);
            p->FUN_140694c10(packet);
            results.Add(p);
            recruits.SetAt(p->recruitId, p);
        }
    }
    void* ui = FUN_1413226d0(0x4eda);
    if (ui != NULL) FUN_140f8ed40(ui, results, last);
}
MS2_REPLACE_METHOD(0x1416314C0, CPartyManager, FUN_1416314c0, 561, 0x09B1B047);

// MS2-FUNCTIONAL: equivalent error cases with reduced temporary storage.
// @0x141631700
void CPartyManager::FUN_141631700(CInPacket& packet)
{
    CInputStream& stream = packet;
    int type = stream.vfunc_o8_1();
    Unk_PartyRecruitError result = static_cast<Unk_PartyRecruitError>(stream.vfunc_o8_3());
    if (type == 0) recruitPending = 0;
    if (result == 99) FUN_140f8ff40(0xb46, 1, 1);
    else if (result == 0x65) FUN_140d73bc0(0xb47, 0, 0, L"");
    else if (result == 0x6e) FUN_140d73bc0(0xb48, 0, 0, L"");
    else if (result == 2) FUN_140d73bc0(0xb49, 0, 0, L"");
    else if (result == 0xe || result == 0xc || result == 0xf) FUN_140d73bc0(0xb4a, 0, 0, L"");
    else if (result == 0x6d) FUN_140f8ff40(0xb51, 1, 0);
    else {
        if (type == 0) {
            if (result == 0x69) { FUN_140d73bc0(0xb4a, 0, 0, L""); return; }
            if (result == 0x66) { FUN_140d73bc0(0xb4b, 0, 0, L""); return; }
            if (result == 0x68) { FUN_140d73bc0(0xb4c, 0, 0, L""); return; }
            if (result == 0x6c) {
                void* ui = FUN_141632840(0x4edb);
                if (ui != NULL) FUN_141321d30(ui);
                FUN_140d73bc0(0xb4e, 0, 0, L"");
                return;
            }
            if (result == 0x6f) { FUN_140d73bc0(0xb50, 0, 0, L""); return; }
        } else if (type == 1) {
            if (result == 0x67) { FUN_140d73bc0(0xb4d, 0, 0, L""); return; }
            if (result == 0x6a) {
                CStringW key(L"s_partysearch_err_server_not_find_recruit");
                FUN_140d73aa0(GetStringCommonByKey(key), 0, 0, L"");
                FUN_141631060();
                return;
            }
        } else if (type == 2 && result == 0x6c) {
            void* ui = FUN_1413226d0(0x4eda);
            if (ui != NULL) FUN_140f8dde0(ui);
            FUN_140d73bc0(0xb4f, 0, 0, L"");
            return;
        }
        PartyRecruitMessage(0xb52, 1, 1, type, result);
    }
}
MS2_REPLACE_METHOD(0x141631700, CPartyManager, FUN_141631700, 1410, 0xCF636205);

// @0x141631cc0
int CPartyManager::FUN_141631cc0() { return recruitPending; }
MS2_REPLACE_METHOD(0x141631CC0, CPartyManager, FUN_141631cc0, 17, 0x8EDBEBA2);

// @0x141631ce0
CMatchPartyRecruit& CPartyManager::FUN_141631ce0() { return recruitment; }
MS2_REPLACE_METHOD(0x141631CE0, CPartyManager, FUN_141631ce0, 15, 0x37F83669);

// @0x141631d00
ATL::CAtlMap<__int64, MS2Ptr<CMatchPartyRecruit>>& CPartyManager::FUN_141631d00() { return recruits; }
MS2_REPLACE_METHOD(0x141631D00, CPartyManager, FUN_141631d00, 17, 0xAA3C736B);

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

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x141631dd0
int CPartyManager::FUN_141631dd0()
{
    WorldService* world = static_cast<WorldService*>(FUN_1403ed2d0());
    if (world == NULL) return 0;
    int count = 0;
    int size = static_cast<int>(members.GetCount());
    for (int i = 0; i < size; ++i) {
        MS2Ptr<CPartyMember> member(members[i]);
        if (!member.IsNull()) {
            MS2Ptr<CProxyGameObject> proxy;
            FUN_141bc9c60(world, &proxy, member->FUN_141637bb0());
            if (!proxy.IsNull() && proxy->kind == 0) ++count;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x141631DD0, CPartyManager, FUN_141631dd0, 338, 0xA4F142C3);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x141631f30
void FUN_141631f30(const CMatchPartyRecruit& oldRecruit, const CMatchPartyRecruit& newRecruit)
{
    if (oldRecruit.recruitId != newRecruit.recruitId) {
        if (oldRecruit.recruitId != 0) FUN_141275260(0xb30, 1, 1);
        if (newRecruit.recruitId != 0) FUN_141275260(0xb2e, 1, 1);
        void* ui = FUN_1413226d0(0x4eda);
        if (ui != NULL) FUN_140f8ee00(ui, newRecruit);
    }
}
MS2_REPLACE(0x141631F30, FUN_141631f30, 176, 0x46058A0A);

// MS2-FUNCTIONAL: equivalent control flow with different local scopes and temporary storage.
// @0x141632630
void FUN_141632630(const CStringW& input, ATL::CAtlArray<int>& values, const wchar_t* delimiter)
{
    int start = 0;
    CStringW token = input.Tokenize(delimiter, start);
    while (!token.IsEmpty()) {
        int value = FUN_1401d9a00(token);
        values.Add(value);
        token = input.Tokenize(delimiter, start);
    }
}

// MS2-FUNCTIONAL: typed RTTI lookup with explicit member-return storage.
// @0x141632700
UIChaosDPSDialog* FUN_141632700(int id)
{
    if (FUN_1403ed2b0() != NULL) {
        MS2Ptr<UIObject> object;
        FUN_141adcea0(FUN_1403ed2b0(), &object, id);
        if (object.get() != NULL) return dynamic_cast<UIChaosDPSDialog*>(object.operator->());
    }
    return NULL;
}

// MS2-FUNCTIONAL: typed RTTI lookup with explicit member-return storage.
// @0x1416327a0
UIPartyDPSDialog* FUN_1416327a0(int id)
{
    if (FUN_1403ed2b0() != NULL) {
        MS2Ptr<UIObject> object;
        FUN_141adcea0(FUN_1403ed2b0(), &object, id);
        if (object.get() != NULL) return dynamic_cast<UIPartyDPSDialog*>(object.operator->());
    }
    return NULL;
}

// MS2-FUNCTIONAL: typed RTTI lookup with explicit member-return storage.
// @0x141632840
UIPartySearchRegisterDialog* FUN_141632840(int id)
{
    if (FUN_1403ed2b0() != NULL) {
        MS2Ptr<UIObject> object;
        FUN_141adcea0(FUN_1403ed2b0(), &object, id);
        if (object.get() != NULL) return dynamic_cast<UIPartySearchRegisterDialog*>(object.operator->());
    }
    return NULL;
}

// Enum customization used by PartyRecruitMessage. The legacy unreachable stream-formatting branch is omitted.
// MS2-FUNCTIONAL: integer conversion and formatter cursor update match the enum path.
// @0x1416335b0
void format_arg(fmt::BasicFormatter<wchar_t>& formatter, const wchar_t*& cursor,
                const Unk_PartyRecruitError& value)
{
    fmt::internal::Arg arg;
    arg.int_value = static_cast<int>(value);
    arg.type = fmt::internal::Arg::INT;
    cursor = formatter.format(cursor, arg);
}

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
Unk_PartyCounters::~Unk_PartyCounters() {}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb3c10-0x142cb3d10 .text$yd
// MS2-RANGE: 0x142cb3d30-0x142cb3d50 .text$yd
