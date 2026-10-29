// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWriteMusicDialog ("WriteMusicDialog", UI type 0x4eed,
// 0x270 bytes) is the music score writing window: up to ten MML tabs (one melody and nine chords) previewed through the
// instrument manager with a piano roll, saved to / loaded from ./Custom/Music/*.ms2mml files and sent to the server as
// the content of a blank score item; a written score is shown read-only. See uiwritemusicdialog.h.
// MS2-UNIT: client\ms2\uiwritemusicdialog.cpp
// MS2-RANGE: 0x1400e37f0-0x1400e39d0 .text$di
// MS2-RANGE: 0x140fed9c0-0x1410084b0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAIAEAV?$MS2Ptr@VMMLToken@@@@$0A@@?$pair@IV?$MS2Ptr@VMMLToken@@@@@std@@QEAA@AEAIAEAV?$MS2Ptr@VMMLToken@@@@@Z 0x140ff6000 ; unique
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x140ff6320 ; prop
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x140ff6370 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_One_then_variadic_args_t@1@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@PEAX@std@@@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU21@$$QEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@PEAX@std@@@1@@Z 0x140ff64b0 ; unique
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140ff6560 ; prop
// MS2-PIN: ??$?0IV?$MS2Ptr@VMMLToken@@@@$0A@@?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@QEAA@$$QEAU?$pair@IV?$MS2Ptr@VMMLToken@@@@@1@@Z 0x140ff65b0 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140ff66d0 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140ff67c0 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140ff6810 ; prop
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140ff6a10 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@@Z 0x140ff72d0 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@$$QEAU?$pair@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@@Z 0x140ff7680 ; unique
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x140ff7a20 ; unique
// MS2-PIN: ??$_Eqrange@_K@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@V12@@1@AEB_K@Z 0x140ff7e50 ; unique
// MS2-PIN: ??$_Eqrange@_K@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@V12@@1@AEB_K@Z 0x140ff7ee0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@AEAU?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@1@Z 0x140ff9350 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@@Z 0x140ff96b0 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@@Z 0x140ffbb70 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@$00@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@PEAX@1@@Z 0x140ffc7a0 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@PEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@@Z 0x140ffcbb0 ; unique
// MS2-PIN: ??$_Kfn@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@?$_Tmap_traits@HV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@1@@Z 0x140ffd130 ; unique
// MS2-PIN: ??$_Kfn@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@?$_Tmap_traits@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@1@@Z 0x140ffd140 ; unique
// MS2-PIN: ??$_Kfn@$$CBIV?$MS2Ptr@VMMLToken@@@@@?$_Tmap_traits@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@$00@std@@SAAEBIAEBU?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@1@@Z 0x140ffd150 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140ffdeb0 ; unique
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@0@AEBV10@@Z 0x140ffe590 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@YAPEAU?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@0@AEAU10@@Z 0x140ffe630 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140ffe8e0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140ffe990 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140fff1b0 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140fff1c0 ; unique
// MS2-PIN: ??$forward@V?$MS2Ptr@VASUIComponent@@@@@std@@YA$$QEAV?$MS2Ptr@VASUIComponent@@@@AEAV1@@Z 0x140fff240 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140fff250 ; prop
// MS2-PIN: ??$make_pair@AEAIAEAV?$MS2Ptr@VMMLToken@@@@@std@@YA?AU?$pair@IV?$MS2Ptr@VMMLToken@@@@@0@AEAIAEAV?$MS2Ptr@VMMLToken@@@@@Z 0x140fff390 ; unique
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140fff5a0 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140fff5e0 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@1@@Z 0x140fffaf0 ; prop
// MS2-PIN: ??0?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@QEAA@AEBU01@@Z 0x1410001d0 ; unique
// MS2-PIN: ??1?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@QEAA@XZ 0x1410005d0 ; unique
// MS2-PIN: ??1?$pair@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@QEAA@XZ 0x141000630 ; unique
// MS2-PIN: ??1?$pair@IV?$MS2Ptr@VMMLToken@@@@@std@@QEAA@XZ 0x141000650 ; unique
// MS2-PIN: ??1?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@QEAA@XZ 0x141000670 ; prop
// MS2-PIN: ??7?$MS2Ptr@VASDataProvider@@@@QEBA_NXZ 0x141000770 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1410007d0 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$pair@HH@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141000ab0 ; prop
// MS2-PIN: ??A?$map@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@@std@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEBH@Z 0x141000b70 ; prop
// MS2-PIN: ??A?$map@HV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@QEAAAEAV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@1@AEBH@Z 0x141000bb0 ; prop
// MS2-PIN: ??A?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@QEAAAEAV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@1@AEBH@Z 0x141000bf0 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@XZ 0x141000c50 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@1@XZ 0x141000c70 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@1@XZ 0x141000c90 ; prop
// MS2-PIN: ??D?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEBAAEBU?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@XZ 0x141000cb0 ; prop
// MS2-PIN: ??D?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@XZ 0x141000d50 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141001390 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1410013d0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141001430 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141001450 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1410017b0 ; unique
// MS2-PIN: ?FindNextNode@?$CAtlMap@HV?$MS2Ptr@VCInstrumentCategoryData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInstrumentCategoryData@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141001aa0 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@HV?$MS2Ptr@VCInstrumentCategoryData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInstrumentCategoryData@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141001b60 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$MS2Ptr@VCInstrumentCategoryData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInstrumentCategoryData@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141001bb0 ; unique
// MS2-PIN: ?vfunc_48@UIWriteMusicDialog@@UEAAHXZ 0x141001c20 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$MS2Ptr@VCInstrumentCategoryData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInstrumentCategoryData@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VCInstrumentCategoryData@@@@PEAU__POSITION@@@Z 0x141001c30 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@HV?$MS2Ptr@VCInstrumentCategoryData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInstrumentCategoryData@@@@@3@@ATL@@QEBA_NXZ 0x141001ca0 ; prop
// MS2-PIN: ?SetStringW@Value@GFx@Scaleform@@QEAAXPEB_W@Z 0x141001cd0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@XZ 0x1410024a0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@@Z 0x141002ab0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@@Z 0x141002d80 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@@Z 0x141004b50 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x141004ea0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141004eb0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141004ed0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x141004f00 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_K@2@XZ 0x141004f20 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@2@XZ 0x141004f30 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@PEAX@std@@@2@XZ 0x141004fa0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIU?$pair@HH@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$pair@HH@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIU?$pair@HH@std@@@std@@PEAX@std@@@2@XZ 0x141004fb0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@2@XZ 0x141004fc0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$multimap@IV?$MS2Ptr@VMMLToken@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VMMLToken@@@@@std@@@3@@std@@@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x141005410 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IU?$pair@HH@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIU?$pair@HH@std@@@std@@@2@$00@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$pair@HH@std@@@std@@@std@@@std@@@2@XZ 0x141006ad0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIWriteMusicDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141006f80 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@XZ 0x141007290 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@0@Z 0x141007510 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@@Z 0x141007c80 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA_KAEB_K@Z 0x141007d30 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@AEB_K@Z 0x141007e80 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@AEB_K@Z 0x141008180 ; unique
// MS2-PINS-END tplpin
//
// File name assumed from the class name (no assert text in the unit).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiwritemusicdialog.cpp"

#define MS2_PTR_MOVE_CONVERT
#include "ms2/placeholder/ms2stdafx.h"

#include "uiwritemusicdialog.h"

#include <algorithm>
#include <utility>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uicartoondialog.h"
#include "ms2/client/ms2/mmltoken.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/item.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/cinstrumentdatatable.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (dynamic initializers 0x1400e37f0..0x1400e3990) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strSortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInputControllerB;
#endif

// ---- unit-local views of exe objects ----

// The MIDI track and score event lists the instrument manager fills while parsing a tab (instrumentmanager.h).
typedef std::multimap<unsigned int, unsigned int> Unk_WmTrack;              // tick -> packed message
typedef std::multimap<unsigned int, std::pair<int, int> > Unk_WmEvents;     // tick -> (note, length)

// The instrument manager (singleton, ?\instrumentmanager.cpp).
class Unk_WmInstrumentMgr
{
public:
    unsigned FUN_140d08660(int nChannel, int nProgram, int nPercussion, Unk_WmTrack* pTrack, Unk_WmEvents* pEvents,
                           unsigned nTime, unsigned nNow, const CString& strMml, bool bFirst);   // parse one tab
    bool FUN_140d099c0(const CString& strMml, int nCategory, int nOffset, int* pnLength);   // preview the score
    void FUN_140d09bc0();                                                   // stop the preview
    void FUN_140d09c10(Unk_WmScore* pScore);                                // send the composed score
    void FUN_140d09c80(unsigned __int64 nItemUid);                          // request a score's text
    void FUN_140d09cf0(unsigned nFlags);                                    // add mode flags
    void FUN_140d09d40(unsigned nFlags);                                    // remove mode flags
};
Unk_WmInstrumentMgr* FUN_140c8dac0();

// The play bar "m_playBar" (a slider).
class Unk_WmSlider : public ASUIComponent
{
public:
    float FUN_1422ce840();                                                  // the value
    void FUN_1422ce800(float f);                                            // set the value
    void FUN_1422ce870(float f);                                            // set the maximum
    void FUN_1409adbe0(const char* szName, Scaleform::GFx::Value v);        // set a member (ASObj)
};

// The root AS object of the movie with the binders this unit needs.
class Unk_WmScript : public AScript
{
public:
    template <class T> MS2Ptr<T> FUN_140fafed0(const CString& strName);    // bind a component by name
    void FUN_1407cbbe0(const char* szName, bool b);                         // set a bool member (ASObj)
    // "setTabFromText" (Invoke(string, value, wide string, int); inline COMDAT of this unit; a1..a3 by value)
    Scaleform::GFx::Value FUN_140ff70d0(const char* szMethod, CString a1, Scaleform::GFx::Value a2, CStringW a3, int a4);
};

// The data provider made from an AS array value (0x40 bytes).
class Unk_WmProvider : public ASDataProvider
{
public:
    Unk_WmProvider(Scaleform::GFx::Value& v, int nMovieId);                 // 0x1422df020
};

// The score owner check (the account of the local player).
struct Unk_WmOwner
{
    void FUN_1409aff60();
    __int64 m_nAccount;
    unsigned m_n8;
    void* m_p10;                                            // a pointer-size id (a pointer member keeps /GS off, as in the exe)
    __int64 m_n18;
};
extern __int64 DAT_143ab2820;
extern unsigned DAT_143ab2830;
extern __int64 DAT_143ab2838;
extern int DAT_143ab2834;
bool FUN_14026d4d0(const Unk_WmOwner* pOwner, int nServer, __int64 nCharacterId);

// The player inventory (global at 0x143ab2a90): item lookup by uid.
class Unk_WmInventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid); };
extern Unk_WmInventory DAT_143ab2a90;
#ifdef __clang__
// Bind the exe's operator+(const char*, const CString&); clang otherwise emits an unavailable CopyChars DLL import.
CString FUN_140298360(const char* szLeft, const CString& strRight);
#define Unk_WmConcat(left, right) FUN_140298360(left, right)
#else
#define Unk_WmConcat(left, right) ((left) + (right))
#endif

// The UI manager's reference to a dialog (16 bytes, object at +8; dtor 0x1403e5630).
class Unk_WmUIRef
{
public:
    ~Unk_WmUIRef();
    UIObject* FUN_1403e8a70() const;                                        // the object, or 0
    UIObject* FUN_1403ed9e0();
private:
    void* m_00;
    UIObject* m_pObject;
};
MS2_CHECK_SIZE(Unk_WmUIRef, 0x10);

// The UI service (open dialog bookkeeping).
class Unk_WmUiSvc
{
public:
    void FUN_141adc530(int nUiType);                                        // open it
    void FUN_141adc5d0(int nUiType);                                        // close it
    Unk_WmUIRef FUN_141adcea0(int nUiType);                                 // the dialog
};
Unk_WmUiSvc* FUN_1403ed2b0();

class Unk_WmBrowser { public: void FUN_141b794e0(CString* pstrOut, const char* szUrl); };
Unk_WmBrowser* FUN_140cc18a0();
void FUN_1418fe1c0(const CString& strUrl);                                  // open the web page

class Unk_WmStrMgr
{
public:
    void FUN_1422b0ea0(const CStringW& str);                                // copy to the clipboard
    CStringW FUN_1422b0570(const CString& strKey);                          // "$key" -> text
};
Unk_WmStrMgr* FUN_14025e7a0();
CommonString* FUN_14025e7d0();
CInstrumentDataTable* FUN_14052d1d0();                                      // the instrument table singleton
CItemDataTable* FUN_140281980();

unsigned FUN_140869420();                                                   // the client clock (ms)
bool FUN_140a467d0(const MS2Ptr<AScript>* p);                               // the AS object is released
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
CStringW GetStringCommon(int nId);                                            // string table text by id
CStringW FUN_1409eec40(int nId);                                            // system message text
void FUN_1412751f0(const CStringW& str, int a, int b);                      // notice
void FUN_1412761e0(MS2Ptr<AScript> spScript, int bEnable);                  // enable the movie input
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);       // message box
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* p, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                                // show it
void FUN_140d746e0(void* pListener, int nType, const CStringW& strTitle, const CStringW& strText);   // the terms box
int FUN_140d74e80(const CStringW& strTag);                                  // the terms box answered
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);                 // equal (no case)
void FUN_14151f200();
void FUN_140d73cd0();                                                       // the keyboard writing guide
void FUN_1401ffd60(Unk_WmScore* pScore);                                    // reset the score
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int bVisible);    // show a child

void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a child's text
void FUN_140cff950(const Scaleform::GFx::Value& root, CString strName, unsigned bEnable);   // enable a child
void FUN_141b706a0(int nMs, int* pnMinutes, int* pnSeconds, int* pnCentis);  // split a time
std::string FUN_14083f9c0(unsigned long nColor);                            // the color as hex text
CStringW FUN_1418fe4e0(const CStringW& strDir);                             // the full path
CStringW FUN_141b6e360(const CStringW& strDir, const wchar_t* szFilter, const CStringW& strDefault);   // the open file box
CStringW FUN_141b6e6f0(const CStringW& strDir, const wchar_t* szFilter, const CStringW& strDefault);   // the save file box
void FUN_14015f0b0(CString& str, ATL::CAtlArray<CString>& parts, const char* szSep);   // split
CString FUN_14016a600(const wchar_t* psz, int nCodePage);                   // wide -> multibyte
CStringW FUN_14016a730(const char* psz, int nCodePage);                    // multibyte -> wide
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* psz);         // Value = psz
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);      // Value = psz
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v); // Value = v
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);                   // Value = n

// The AS function object wrapping a delegate (the same view as uishopdialog.cpp).
class ASFunction : public AScript
{
public:
    ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int nUser, int nMovieId);   // 0x1422c8430
    virtual ~ASFunction();
private:
    void* m_40;
};

// The game TinyXML nodes the .ms2mml files are written with (RTTI names; the parent copies them on insert).
class TiXmlElement
{
public:
    TiXmlElement(const char* szName);                                       // 0x14086f2f0
    ~TiXmlElement();                                                        // 0x14086f450
private:
    void* m_pad[0x90 / sizeof(void*)];
};
class TiXmlText
{
public:
    TiXmlText(const char* szText);                                          // 0x1408723d0
    ~TiXmlText();                                                           // 0x140872500
    void FUN_14087a320(bool bCData);                                        // SetCDATA
private:
    void* m_pad[0x58 / sizeof(void*)];
};
class TiXmlDeclaration
{
public:
    TiXmlDeclaration(const char* szVersion, const char* szEncoding, const char* szStandalone);   // 0x1408704d0
    ~TiXmlDeclaration();                                                    // 0x14081ad20
private:
    void* m_pad[0x68 / sizeof(void*)];
};
void* FUN_14086e000(void* pParent, const void* pChild);                     // InsertEndChild (a copy)
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* szPath);                // SaveFile
void FUN_14086f920(TiXmlElement* pElem, const char* szName, int nValue);    // SetAttribute (int)
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* szName);      // FirstChildElement

// A TinyXML node through its vtable (slot 11: ToText).
class Unk_WmXmlNode
{
public:
    virtual ~Unk_WmXmlNode();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual Unk_140165cf0* ToText();
};
Unk_WmXmlNode* FUN_140872a10(Unk_140165cf0* pElem);                         // FirstChild

// The TiXmlDocument fields after the TiXmlNode part (tinyxml.h: error, errorId, errorDesc).
struct Unk_WmXmlDocState
{
    void* m_node[0x50 / sizeof(void*)];
    bool m_bError;                                                          // +0x50
    int m_nErrorId;                                                         // +0x54
    Unk_TiXmlString m_errorDesc;                                            // +0x58
};
MS2_CHECK_OFFSET(Unk_WmXmlDocState, m_errorDesc, 0x58);
inline const char* FUN_141001a80(TiXmlDocument* pDoc);

// The music note names by semitone.
static const char* const s_szNoteNames[] = {"C", "C+", "D", "D+", "E", "F", "F+", "G", "G+", "A", "A+", "B"};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140fed9c0
UIWriteMusicDialog::UIWriteMusicDialog()
    : m_bPlaying(0), m_nEndTick(0), m_nStartTick(0), m_nRemoveTab(-1), m_spItem(0), m_spTimer(0), m_spTotalTimer(0),
      m_spPlayBar(0), m_spTabs(0), m_spPlayLine(0), m_nMode(0), m_nPage(0)
{
    FUN_141924170(1);
    FUN_1422dc3b0(1);
    FUN_141925e70(1, 1);
}

// @0x140fedbb0
UIWriteMusicDialog::~UIWriteMusicDialog()
{
    m_spTimer = 0;
    m_spTotalTimer = 0;
    m_spPlayBar = 0;
    m_spTabs = 0;
    m_spPlayLine = 0;
    m_spItem = 0;
}

// @0x140fedd90
CString UIWriteMusicDialog::GetTypeName()
{
    return "WriteMusicDialog";
}

// @0x140fedde0
void UIWriteMusicDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (!m_spItem)
    {
        vfunc_67();
        return;
    }
    if (m_30.get())
    {
        int nMax = FUN_140ff40b0();
        ASObj obj(2);
        obj.FUN_1407cb9c0("maxLength", nMax);
        std::vector<std::pair<int, CStringW> > list;
        ATL::CAtlMap<int, CInstrumentDataTable::CategoryPtr>& categories = FUN_14052d1d0()->GetCategories();
        for (POSITION pos = categories.GetStartPosition(); pos != 0; categories.GetNext(pos))
        {
            CInstrumentDataTable::CategoryPtr spCategory = categories.GetValueAt(pos);
            if (!spCategory)
                continue;
            list.push_back(std::make_pair(spCategory->m_nId, spCategory->GetName()));
        }
        std::sort(list.begin(), list.end());
        ASDataProvider provider(2);
        MS2_FOR_EACH(auto entry, list)
        {
            ASObj row(2);
            row.FUN_1407cb9c0("id", entry.first);
            row.FUN_1407cbb20("label", CStringW(entry.second));
            provider.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
        }
        obj.FUN_1409adbe0("dpRecommandInstrument", Scaleform::GFx::Value(provider.FUN_1422bb870()));
        obj.FUN_1407cb9c0("selectedIndexRecommandInstrument", 0);
        bool bReadOnly = m_nMode == 2;
        obj.FUN_1407cbbe0("readOnly", bReadOnly);
        if (bReadOnly)
            obj.FUN_1407cbb20("title", m_spItem->FUN_1405296c0());
        m_30->Invoke("initData", Scaleform::GFx::Value(obj.FUN_1422bb870()));
        m_spTabs = m_30->FUN_140be23c0<ASButtonBar>("m_tabMusic");
        if (!m_strText.IsEmpty())
            FUN_140ff41a0();
        CString strUrl(*TSingleton<Client::Constants>::GetInstance()->WriteMusicDetailWebPage.Get());
        if (strUrl.IsEmpty())
            m_30->Invoke("hideWebPageButton");
        m_spPlayLine = GetChild<ASMovieClip>("m_playLine");
        MS2Ptr<ASDropdownMenu> spRollType = FUN_140c28560("m_rollType");
        if (spRollType)
        {
            spRollType->FUN_1422dfce0(GetStringCommonByKey(L"s_writemusic_playline_show_per_time"));
            spRollType->FUN_1422dfce0(GetStringCommonByKey(L"s_writemusic_playline_show_per_bar"));
            spRollType->FUN_1422df690(0);
        }
        FUN_140cff840(FUN_1422dbb40(), "m_drumInfoText", 0);
        FUN_140ff1b10(0);
    }
    FUN_140c8dac0()->FUN_140d09cf0(1);
}

// @0x140fee700
void UIWriteMusicDialog::vfunc_26()
{
    UIDialog::vfunc_26();
}

// The story book (help) dialog.
inline UICartoonDialog* FUN_140ff7030(int nUiType);

// @0x140fee720
void UIWriteMusicDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_spTimer = 0;
    m_spTotalTimer = 0;
    m_spPlayBar = 0;
    m_spTabs = 0;
    m_spPlayLine = 0;
    m_spItem = 0;
    m_nRemoveTab = -1;
    if (m_bPlaying)
        FUN_140ff1a20();
    FUN_140ff3540();
    FUN_1401ffd60(&m_score);
    m_strPlayMml.Empty();
    m_strText.Empty();
    m_nMode = 0;
    UICartoonDialog* pCartoon = FUN_140ff7030(0x4e87);
    if (pCartoon != 0 && pCartoon->vfunc_55() == 0)
    {
        if (pCartoon->GetBookId() == *TSingleton<Client::Constants>::GetInstance()->WriteMusicStoryBookID.Get())
            FUN_1403ed2b0()->FUN_141adc5d0(0x4e87);
    }
    m_nPage = 0;
    m_notes.clear();
    m_pages.clear();
    if (m_30.get())
        FUN_140c8dac0()->FUN_140d09d40(1);
}

// @0x140fee900
int UIWriteMusicDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onClickMake", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140ff03b0(&data);
        return 1;
    }
    else if (_stricmp("onClickHelpStoryBook", szMethod) == 0)
    {
        UICartoonDialog* pCartoon = FUN_140ff7030(0x4e87);
        if (pCartoon != 0)
        {
            int nBookId = *TSingleton<Client::Constants>::GetInstance()->WriteMusicStoryBookID.Get();
            pCartoon->FUN_1418dfb30(nBookId, 0x22, m_e0);
        }
        return 1;
    }
    else if (_stricmp("onClickHelpWebPage", szMethod) == 0)
    {
        CString strUrl;
        FUN_140cc18a0()->FUN_141b794e0(&strUrl, *TSingleton<Client::Constants>::GetInstance()->WriteMusicDetailWebPage.Get());
        FUN_1418fe1c0(strUrl);
        return 1;
    }
    else if (_stricmp("onClickPlayGoFirstAndPause", szMethod) == 0)
    {
        OnClickPlayGoFirstAndPause();
        return 1;
    }
    else if (_stricmp("onClickPlayStart", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140ff12d0(&data);
        return 1;
    }
    else if (_stricmp("onClickPlayStop", szMethod) == 0)
    {
        FUN_140ff1a20();
        return 1;
    }
    else if (_stricmp("onClickPlayPause", szMethod) == 0)
    {
        FUN_140ff1aa0();
        return 1;
    }
    else if (_stricmp("onClickWriteKeyboard", szMethod) == 0)
    {
        FUN_140d73cd0();
        return 1;
    }
    else if (_stricmp("onClickTabMusicAddMaxCount", szMethod) == 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_add_tab_maxcount"), 0, 0, L"");
        return 1;
    }
    else if (_stricmp("OnAskRemoveTabMusic", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            m_nRemoveTab = data.FUN_1422b8a10();
            if (m_nRemoveTab >= 0)
                FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_msg_ask_remove_tab"), 1, static_cast<IMessageListener*>(this),
                              L"askRemoveTabMusic");
        }
        return 1;
    }
    else if (_stricmp("onClickCopyMusicNote", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strNote = data.FUN_1422b8f40();
            if (!strNote.IsEmpty())
                FUN_14025e7a0()->FUN_1422b0ea0(strNote);
        }
        return 1;
    }
    else if (_stricmp("onClickSaveFile", szMethod) == 0)
    {
        OnClickSaveFile();
        return 1;
    }
    else if (_stricmp("onClickLoadFile", szMethod) == 0)
    {
        OnClickLoadFile();
        return 1;
    }
    else if (_stricmp("onChangeInstrument", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nCategory = data.FUN_1422b8a10();
            CInstrumentDataTable::CategoryPtr spCategory = FUN_14052d1d0()->GetCategory(nCategory);
            if (spCategory == 0)
                return 1;
            if (spCategory->IsPercussion())
                FUN_140cff840(FUN_1422dbb40(), "m_drumInfoText", 1);
            else
                FUN_140cff840(FUN_1422dbb40(), "m_drumInfoText", 0);
        }
        return 1;
    }
    else if (_stricmp("onChangeValuePlayBar", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140ff21a0(&data);
        return 1;
    }
    else if (_stricmp("onThumbBeginDragPlayBar", szMethod) == 0)
        FUN_140ff1aa0();
    else if (_stricmp("onClickPlayLinePage", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nDelta = data.FUN_1422b8a10();
            m_nPage = m_nPage + nDelta;
            FUN_140ff1b10(m_nPage);
        }
        return 1;
    }
    else if (_stricmp("RefreshPianoRoll", szMethod) == 0)
    {
        FUN_140ff1b10(m_nPage);
        return 1;
    }
    return 0;
}

// @0x140fef2f0
int UIWriteMusicDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (nResult == 0)
        {
            if (FUN_140d74e80(strTag) != 0)
            {
                FUN_140c8dac0()->FUN_140d09c10(&m_score);
                FUN_1401ffd60(&m_score);
                FUN_1412761e0(m_30, 0);
            }
            else if (FUN_1403b3c40(strTag, L"completeMakeScore"))
                vfunc_67();
            else if (FUN_1403b3c40(strTag, L"askClose"))
                vfunc_67();
            else if (FUN_1403b3c40(strTag, L"askRemoveTabMusic"))
            {
                if (m_30.get())
                {
                    m_30->Invoke("removeTabMusic", m_nRemoveTab);
                    m_nRemoveTab = -1;
                }
            }
            else if (FUN_1403b3c40(strTag, L"askLoadFile"))
            {
                FUN_140ff2600();
                FUN_140ff1b10(0);
            }
            return 1;
        }
    }
    return 0;
}

// @0x140fef5d0
int UIWriteMusicDialog::vfunc_71()
{
    if (FUN_140ff33c0())
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_msg_ask_close"), 1, static_cast<IMessageListener*>(this), CStringW(L"askClose"));
        return 1;
    }
    return 0;
}

// @0x140fef6c0
void UIWriteMusicDialog::vfunc_72()
{
    if (FUN_140a467d0(&m_30))
        return;
    if (!m_bPlaying)
        return;
    unsigned nNow = FUN_140869420();
    if (nNow < m_nEndTick)
    {
        int nTime = nNow - m_nStartTick;
        FUN_140ff3610(nTime);
        FUN_140ff3d10(nTime);
    }
    else
        FUN_140ff1a20();
}

// @0x140fef760
MS2Ptr<CItem> UIWriteMusicDialog::GetItem()
{
    return m_spItem;
}

// @0x140fef7b0
bool UIWriteMusicDialog::FUN_140fef7b0(MS2Ptr<CItem> spItem)
{
    if (!spItem)
        return false;
    if (m_nMode == 2)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_writemusic_error_cant_write_when_viewscore"), 1, 1);
        return false;
    }
    m_nMode = 1;
    SetItem(spItem);
    return true;
}

// @0x140fef8f0
bool UIWriteMusicDialog::FUN_140fef8f0(MS2Ptr<CItem> spItem)
{
    if (!spItem)
        return false;
    if (m_nMode == 1)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_writemusic_error_cant_viewscore_when_write"), 1, 1);
        return false;
    }
    if (!spItem->FUN_140525790())
        return false;
    CItemCustomMusicScore* pScore = spItem->FUN_140527990();
    if (pScore == 0)
        return false;
    if (pScore->m_note.m_n08 == 0)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_writemusic_error_cant_know_writer"), 1, 1);
        return false;
    }
    if (pScore->m_n38 != 0)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_writemusic_error_cant_edit"), 1, 1);
        return false;
    }
    Unk_WmOwner owner;
    owner.FUN_1409aff60();
    owner.m_nAccount = DAT_143ab2820;
    owner.m_n8 = DAT_143ab2830;
    owner.m_p10 = (void*)DAT_143ab2838;
    owner.m_n18 = DAT_143ab2834;
    if (!FUN_14026d4d0(&owner, pScore->m_note.m_n00, pScore->m_note.m_n08))
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_writemusic_error_not_write_myself"), 1, 1);
        return false;
    }
    m_nMode = 2;
    SetItem(spItem);
    FUN_140ff2500(spItem->FUN_140526a50());
    return true;
}

// @0x140fefd00
void UIWriteMusicDialog::FUN_140fefd00(MS2Ptr<CItem> spItem)
{
    if (vfunc_55() != 0)
        return;
    if (spItem == 0)
        return;
    FUN_1412761e0(m_30, 1);
    if (m_spItem == spItem.get())
    {
        if (MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, GetStringCommonByKey(L"s_writemusic_complete_make"),
                                                      static_cast<IMessageListener*>(this), CStringW(L"completeMakeScore")))
        {
            MS2Ptr<CItem> spInvItem = DAT_143ab2a90.FUN_140a5d680(m_spItem->FUN_140526a50());
            if (spInvItem.get())
            {
                CStringW strName = spInvItem->FUN_140527b10();
                spBox->FUN_141a01ee0(m_spItem, strName, 1, 0, -1, -1, 1);
                FUN_140d73c60(spBox);
            }
        }
    }
    m_texts.erase(spItem->FUN_140526a50());
}

// @0x140ff0090
void UIWriteMusicDialog::FUN_140ff0090(int nResult)
{
    if (nResult == 8)
    {
        if (m_30.get())
            FUN_1412761e0(m_30, 1);
    }
    else if (nResult == 10)
    {
        if (m_30.get())
            FUN_1412761e0(m_30, 1);
        m_nMode = 0;
    }
    else if (nResult == 0x10)
    {
        if (m_30.get())
            FUN_1412761e0(m_30, 1);
        FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
    }
}

// @0x140ff0260
void UIWriteMusicDialog::FUN_140ff0260(unsigned __int64 nItemUid, const CString& strMml)
{
    std::map<unsigned __int64, CString>::const_iterator it = m_texts.find(nItemUid);
    if (it == m_texts.end())
        m_texts.insert(std::make_pair(nItemUid, strMml));
    m_nMode = 2;
    m_strText = strMml;
    if (vfunc_55() != 0)
        FUN_1403ed2b0()->FUN_141adc530(0x4eed);
    else
        FUN_140ff41a0();
}

// The tab list of the AS score (an array of {content}).
inline MS2Ptr<ASDataProvider> FUN_140ff6b60(int nMovieId, Scaleform::GFx::Value& v);

// @0x140ff03b0
void UIWriteMusicDialog::FUN_140ff03b0(ASData* pArgs)
{
    if (!m_spItem)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_make"), 0, 0, L"");
        return;
    }
    CStringW strTitle = pArgs->FUN_1422b8f40();
    strTitle.Trim();
    if (strTitle.IsEmpty())
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_make_empty_title"), 0, 0, L"");
        return;
    }
    if (CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker())
    {
        CStringW strMessage;
        if (pChecker->FUN_140225a70(strTitle, strMessage) != 0)
        {
            FUN_140d73aa0(strMessage, 0, 0, L"");
            return;
        }
    }
    int nCategory = pArgs->FUN_1422b8a10();
    CInstrumentDataTable::CategoryPtr spCategory = FUN_14052d1d0()->GetCategory(nCategory);
    if (spCategory == 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_make_invalid_instrument_type"), 0, 0, L"");
        return;
    }
    Scaleform::GFx::Value tabs = pArgs->FUN_1422b9260();
    MS2Ptr<ASDataProvider> spTabs = FUN_140ff6b60(m_28, tabs);
    CString strMml;
    if (!spTabs || spTabs->FUN_1422bc5d0() == 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_make"), 0, 0, L"");
        return;
    }
    unsigned nCount = spTabs->FUN_1422bc5d0();
    int nTabs = 0;
    Unk_WmTrack track;
    Unk_WmEvents events;
    unsigned nNow = FUN_140869420();
    unsigned nEnd = nNow;
    for (unsigned i = 0; i < nCount; i++)
    {
        Scaleform::GFx::Value tab;
        if (tabs.GetElement(i, &tab))
        {
            Scaleform::GFx::Value content;
            tab.GetMember("content", &content);
            CString strTab(content.GetString());
            if (!strTab.IsEmpty())
            {
                strTab.Remove(':');
                strTab.Remove(' ');
                strTab.Remove('\n');
                strTab.Remove('\t');
                strTab.Remove('\r');
                if (strMml.IsEmpty())
                    strMml = strTab;
                else
                    strMml += Unk_WmConcat(":", strTab);
                track.clear();
                bool bFirst = i == 0;
                unsigned nTabEnd = FUN_140c8dac0()->FUN_140d08660(0, spCategory->m_nGMId, spCategory->m_nPercussionId, &track,
                                                                 &events, nNow, nNow, strTab, bFirst);
                nEnd = (std::max)(nEnd, nTabEnd);
                nTabs++;
            }
        }
    }
    strMml.Remove(' ');
    strMml.Remove('\n');
    strMml.Remove('\t');
    strMml.Remove('\r');
    unsigned nLength = nEnd - nNow;
    if (strMml.GetLength() < 1)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_make_empty_score"), 0, 0, L"");
        return;
    }
    int nMax = 0;
    {
        // FUN_140527840 returns the item's CItemData (citem.h declares it as the incomplete Unk_ItemEquipData).
        MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(static_cast<CItem*>(m_spItem)->FUN_140527840()));
        if (spData)
        {
            MS2Ptr<ItemMusicScore> spScore = FUN_140281980()->GetMusicScore(spData->FUN_14053c510());
            if (spScore)
                nMax = spScore->noteLengthMax;
        }
    }
    if (strMml.GetLength() > nMax + nTabs)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_make_maxlength"), 0, 0, L"");
        return;
    }
    if (nLength < 2000)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_make_zero_time"), 0, 0, L"");
        return;
    }
    m_score.m_nItemUid = static_cast<CItem*>(m_spItem)->FUN_140526a50();
    m_score.m_nLength = nLength;
    m_score.m_nInstrument = nCategory;
    m_score.m_strTitle = strTitle;
    m_score.m_strMml = strMml;
    CStringW strKey(L"s_writemusic_msg_terms");
    FUN_140d746e0(static_cast<IMessageListener*>(this), 0, GetStringCommonByKey(strKey), GetStringCommon(0x9cf));
}

// @0x140ff12a0
void UIWriteMusicDialog::OnClickPlayGoFirstAndPause()
{
    FUN_140ff3610(0);
    FUN_140ff1aa0();
}

// @0x140ff12d0
void UIWriteMusicDialog::FUN_140ff12d0(ASData* pArgs)
{
    int nCategory = pArgs->FUN_1422b8a10();
    bool bInvalid = FUN_14052d1d0()->GetCategory(nCategory) == 0;
    if (bInvalid)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_play_invalid_instrument_type"), 0, 0, CStringW(L""));
        return;
    }
    Scaleform::GFx::Value tabs = pArgs->FUN_1422b9260();
    MS2Ptr<ASDataProvider> spTabs = FUN_140ff6b60(m_28, tabs);
    if (!spTabs || spTabs->FUN_1422bc5d0() == 0)
    {
        FUN_140d73aa0(CStringW(L"s_writemusic_error_play"), 0, 0, CStringW(L""));
        return;
    }
    unsigned nCount = spTabs->FUN_1422bc5d0();
    CString strMml;
    for (unsigned i = 0; i < nCount; i++)
    {
        Scaleform::GFx::Value tab;
        if (tabs.GetElement(i, &tab))
        {
            Scaleform::GFx::Value content;
            tab.GetMember("content", &content);
            CString strTab(content.GetString());
            if (!strTab.IsEmpty())
            {
                strTab.Remove(':');
                if (strMml.IsEmpty())
                    strMml = strTab;
                else
                    strMml += Unk_WmConcat(":", strTab);
            }
        }
    }
    strMml.Remove(' ');
    strMml.Remove('\n');
    strMml.Remove('\t');
    strMml.Remove('\r');
    m_strPlayMml = strMml;
    if (m_strPlayMml.IsEmpty())
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_play_empty_score"), 0, 0, CStringW(L""));
        return;
    }
    int nOffset = (int)DoubleSecondsToMs(pArgs->FUN_1422b8ca0());
    int nLength = 0;
    bool bOk = FUN_140c8dac0()->FUN_140d099c0(m_strPlayMml, nCategory, nOffset, &nLength);
    if (bOk)
    {
        FUN_140ff35c0(nOffset, nLength);
        m_bPlaying = 1;
        if (m_30.get())
        {
            FUN_140ff38f0(nLength);
            FUN_140ff3610(nOffset);
            int nSeconds = MsToSeconds(nLength);
            nSeconds = nSeconds < 1 ? 1 : nSeconds;
            m_30->Invoke("startPlayMusic", nSeconds);
        }
    }
    else
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_play_zero_time"), 0, 0, CStringW(L""));
    FUN_140ff1b10(m_nPage);
    FUN_140ff57e0();
}

// @0x140ff1a20
void UIWriteMusicDialog::FUN_140ff1a20()
{
    FUN_140c8dac0()->FUN_140d09bc0();
    FUN_140ff3540();
    if (m_30.get())
        m_30->Invoke("stopPlayMusic");
    FUN_140ff59a0();
}

// @0x140ff1aa0
void UIWriteMusicDialog::FUN_140ff1aa0()
{
    FUN_140c8dac0()->FUN_140d09bc0();
    FUN_140ff35a0();
    if (m_30.get())
        m_30->Invoke("pausePlayMusic");
}

// @0x140ff1b10
void UIWriteMusicDialog::FUN_140ff1b10(int nPage)
{
    if (m_spTabs == 0)
        return;
    MS2Ptr<ASDataProvider> spTabs = m_spTabs->FUN_1422e2e00();
    if (!spTabs || spTabs->FUN_1422bc5d0() == 0)
        return;
    unsigned nCount = spTabs->FUN_1422bc5d0();
    std::map<int, CString> tabs;
    Scaleform::GFx::Value& array = spTabs->FUN_1422bb870();
    for (unsigned i = 0; i < nCount; i++)
    {
        Scaleform::GFx::Value tab;
        if (array.GetElement(i, &tab))
        {
            Scaleform::GFx::Value content;
            tab.GetMember("content", &content);
            CString strTab(content.GetString());
            strTab.Remove(':');
            strTab.Remove(' ');
            strTab.Remove('\n');
            strTab.Remove('\t');
            strTab.Remove('\r');
            if (strTab.IsEmpty())
                continue;
            tabs[i] = strTab;
        }
    }
    FUN_140ff4610(tabs);
    m_nPage = nPage;
    if (m_pages.empty())
        m_nPage = 0;
    else
    {
        if (m_nPage < 0)
            m_nPage = 0;
        if (m_nPage > (int)(m_pages.size() - 1))
            m_nPage = m_pages.size() - 1;
    }
    FUN_140ff4a80();
}

// @0x140ff1e40
void UIWriteMusicDialog::OnClickSaveFile()
{
    if (FUN_140a467d0(&m_30))
        return;
    if (!PathIsDirectoryW(L"./Custom/Music"))
        CreateDirectoryW(L"./Custom/Music", 0);
    if (FUN_140ff34b0() == 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_savefile_empty_score"), 0, 0, CStringW(L""));
        return;
    }
    CStringW strPath = FUN_141b6e6f0(FUN_1418fe4e0(L"./Custom/Music"), L"ms2mml Files (*.ms2mml)", L"");
    if (strPath.IsEmpty())
        return;
    CStringW strExt(L".ms2mml");
    if (strPath.Find(strExt, 0) < 0)
        strPath += strExt;
    FUN_140ff2cf0(strPath);
}

// @0x140ff2060
void UIWriteMusicDialog::OnClickLoadFile()
{
    if (FUN_140a467d0(&m_30))
        return;
    if (FUN_140ff33c0())
    {
        CStringW strText = GetStringCommonByKey(L"s_writemusic_error_loadfile_ask_during_edit");
        FUN_140d73aa0(strText, 1, static_cast<IMessageListener*>(this), CStringW(L"askLoadFile"));
    }
    else
    {
        FUN_140ff2600();
        FUN_140ff1b10(0);
    }
}

// @0x140ff21a0
void UIWriteMusicDialog::FUN_140ff21a0(ASData* pArgs)
{
    if (FUN_140a467d0(&m_30))
        return;
    int nCategory = pArgs->FUN_1422b8a10();
    bool bInvalid = FUN_14052d1d0()->GetCategory(nCategory) == 0;
    if (bInvalid)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_play_invalid_instrument_type"), 0, 0, CStringW(L""));
        return;
    }
    int nOffset = (int)DoubleSecondsToMs(pArgs->FUN_1422b8ca0());
    FUN_140ff3610(nOffset);
    if (m_bPlaying)
    {
        int nLength = 0;
        bool bOk = FUN_140c8dac0()->FUN_140d099c0(m_strPlayMml, nCategory, nOffset, &nLength);
        if (bOk)
        {
            FUN_140ff35c0(nOffset, nLength);
            m_bPlaying = 1;
            FUN_140ff3350(false);
            FUN_140ff3610(nOffset);
        }
    }
}

// @0x140ff23b0
void UIWriteMusicDialog::FUN_140ff23b0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (params.ArgCount == 0)
        return;
    ASObj arg(static_cast<const Scaleform::GFx::Value&>(params.pArgs[0]), 2);
    double dTime = arg.FUN_1422bb870().GetNumber();
    if (m_spPlayBar)
    {
        int nMs = (int)DoubleSecondsToMs(dTime);
        int nMinutes, nSeconds, nCentis;
        FUN_141b706a0(nMs, &nMinutes, &nSeconds, &nCentis);
        CStringW strText = StringFormat(m_strTimerFormat, nMinutes, nSeconds);
        Scaleform::GFx::Value v;
        v.SetStringW(strText);
        *params.pRetVal = v;
    }
}

// @0x140ff2500
void UIWriteMusicDialog::FUN_140ff2500(unsigned __int64 nItemUid)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
    if (spItem == 0)
        return;
    std::map<unsigned __int64, CString>::const_iterator it = m_texts.find(nItemUid);
    if (it == m_texts.end())
    {
        FUN_140c8dac0()->FUN_140d09c80(nItemUid);
        return;
    }
    FUN_140ff0260(nItemUid, it->second);
}

// @0x140ff2600
void UIWriteMusicDialog::FUN_140ff2600()
{
    if (!PathIsDirectoryW(L"./Custom/Music"))
        CreateDirectoryW(L"./Custom/Music", 0);
    CStringW strPath = FUN_141b6e360(FUN_1418fe4e0(L"./Custom/Music"), L"ms2mml Files (*.ms2mml)", L"");
    if (strPath.IsEmpty())
        return;
    FUN_140ff2700(strPath);
}

// @0x140ff2700
void UIWriteMusicDialog::FUN_140ff2700(const CStringW& strPath)
{
    if (FUN_140a467d0(&m_30) || !m_spItem)
        return;
    if (strPath.IsEmpty())
        return;
    TiXmlDocument doc;
    bool bLoaded = doc.FUN_140870fc0(FUN_14016a600(strPath, 0), 0);
    if (bLoaded)
    {
        Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
        if (pRoot == 0)
            return;
        int nMax = FUN_140ff40b0();
        int nTotal = 0;
        int nMaxChords = 10;
        int nChords = 0;
        CString strMelody;
        Unk_140165cf0* pMelody = pRoot->FUN_140165cf0("melody");
        if (pMelody != 0)
        {
            FUN_140ff3230(pMelody, nMax, strMelody, &nTotal);
            nChords++;
        }
        else
        {
            FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_loadfile_not_exist_melody_tag"), 0, 0, CStringW(L""));
            return;
        }
        ASArray chords(2);
        if (nTotal < nMax)
        {
            for (Unk_140165cf0* pChord = pRoot->FUN_140165cf0("chord"); pChord != 0; pChord = pChord->FUN_140168650("chord"))
            {
                CString strChord;
                if (FUN_140ff3230(pChord, nMax, strChord, &nTotal))
                {
                    if (nChords > nMaxChords)
                        break;
                    chords.FUN_1422bbf70(strChord);
                    nChords++;
                }
            }
        }
        if (nTotal > nMax)
        {
            CStringW strText = FUN_14028dfa0(L"s_writemusic_error_loadfile_maxlength", nTotal, nMax);
            FUN_140d73aa0(strText, 0, 0, CStringW(L""));
        }
        CStringW strSep(L" ");
        FUN_140ff43a0(strMelody, chords, strSep, -1);
    }
    else
    {
        CStringW strText = FUN_14028dfa0(L"s_writemusic_error_loadfile_wrong_xml", FUN_14016a730(FUN_141001a80(&doc), 0));
        FUN_140d73aa0(strText, 0, 0, CStringW(L""));
    }
}

// @0x140ff2cf0
void UIWriteMusicDialog::FUN_140ff2cf0(const CStringW& strPath)
{
    if (FUN_140a467d0(&m_30))
        return;
    if (strPath.IsEmpty())
        return;
    MS2Ptr<ASButtonBar> spTabBar = m_spTabs;
    if (!spTabBar)
        return;
    MS2Ptr<ASDataProvider> spTabs = spTabBar->FUN_1422e2e00();
    if (!spTabs || spTabs->FUN_1422bc5d0() <= 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_writemusic_error_savefile"), 0, 0, CStringW(L""));
        return;
    }
        TiXmlDocument doc;
        TiXmlDeclaration decl("1.0", "utf-8", "");
        FUN_14086e000(&doc, &decl);
        CString strFile = FUN_14016a600(strPath, 0);
        TiXmlElement root("ms2");
        unsigned nCount = spTabs->FUN_1422bc5d0();
        CString strUnused;
        Scaleform::GFx::Value& array = spTabs->FUN_1422bb870();
        for (unsigned i = 0; i < nCount; i++)
        {
            Scaleform::GFx::Value tab;
            if (array.GetElement(i, &tab))
            {
                Scaleform::GFx::Value content;
                tab.GetMember("content", &content);
                CString strTab(content.GetString());
                if (!strTab.IsEmpty())
                {
                    bool bMelody = i == 0;
                CString strTag(bMelody ? "melody" : "chord");
                    TiXmlElement element(strTag);
                    strTab.Replace("\r", "\n");
                    CString strText("\n");
                    strText.Append(strTab);
                    strText.Append("\n");
                    TiXmlText text(strText);
                    text.FUN_14087a320(1);
                    if (!bMelody)
                        FUN_14086f920(&element, "index", i);
                    FUN_14086e000(&element, &text);
                    FUN_14086e000(&root, &element);
                }
            }
        }
        FUN_14086e000(&doc, &root);
        FUN_1408710c0(&doc, strFile);
        FUN_140ff3450(false);
}

// @0x140ff3230
bool UIWriteMusicDialog::FUN_140ff3230(Unk_140165cf0* pElem, int nMax, CString& strOut, int* pnTotal)
{
    strOut.Empty();
    if (pElem == 0)
        return false;
    Unk_WmXmlNode* pChild = FUN_140872a10(pElem);
    if (pChild == 0)
        return false;
    Unk_140165cf0* pText = pChild->ToText();
    if (pText == 0)
        return false;
    strOut = pText->Value();
    strOut.Trim("\n");
    if (strOut.IsEmpty())
        return false;
    *pnTotal = strOut.GetLength() + *pnTotal;
    int nOver = *pnTotal - nMax;
    if (nOver > 0)
    {
        int nStart = strOut.GetLength() - nOver;
        strOut.Delete(nStart, nOver);
    }
    return true;
}

// @0x140ff3350
void UIWriteMusicDialog::FUN_140ff3350(bool bVisible)
{
    if (FUN_140a467d0(&m_30))
        return;
    m_30->Invoke("setPlayStartButtonVisible", bVisible);
}

// @0x140ff33c0
bool UIWriteMusicDialog::FUN_140ff33c0()
{
    if (FUN_140a467d0(&m_30))
        return false;
    return m_30->FUN_1422baa20("m_dirtyMusicScore").GetBool();
}

// @0x140ff3450
void UIWriteMusicDialog::FUN_140ff3450(bool bDirty)
{
    if (FUN_140a467d0(&m_30))
        return;
    static_cast<Unk_WmScript*>(m_30.operator->())->FUN_1407cbbe0("m_dirtyMusicScore", bDirty);
}

// @0x140ff34b0
int UIWriteMusicDialog::FUN_140ff34b0()
{
    if (FUN_140a467d0(&m_30))
        return 0;
    return m_30->FUN_1422baa20("m_totalLength").GetInt();
}

// @0x140ff3540
void UIWriteMusicDialog::FUN_140ff3540()
{
    m_bPlaying = 0;
    m_nEndTick = 0;
    m_nStartTick = 0;
    m_strPlayMml.Empty();
}

// @0x140ff35a0
void UIWriteMusicDialog::FUN_140ff35a0()
{
    m_bPlaying = 0;
}

// @0x140ff35c0
void UIWriteMusicDialog::FUN_140ff35c0(int nOffset, int nLength)
{
    m_nStartTick = FUN_140869420() - nOffset;
    m_nEndTick = m_nStartTick + nLength;
}

// @0x140ff3610
void UIWriteMusicDialog::FUN_140ff3610(int nTime)
{
    if (m_spTimer.IsNull())
    {
        if (MS2Ptr<ASMovieClip> spPlaying = m_30->FUN_1409b4560("m_playingMusic"))
            m_spTimer = spPlaying->FUN_1409b4620("m_timer");
        m_strTimerFormat = GetStringCommonByKey(L"s_writemusic_text_playtimer_cur");
    }
    if (m_spTimer)
    {
        int nMinutes, nSeconds, nCentis;
        FUN_141b706a0(nTime, &nMinutes, &nSeconds, &nCentis);
        CStringW strText = StringFormat(m_strTimerFormat, nMinutes, nSeconds);
        m_spTimer->FUN_1422c4cd0(strText);
        if (m_spPlayBar)
        {
            int nPos = nMinutes * 60 + nSeconds;
            if (m_spPlayBar->FUN_1422ce840() != (float)nPos)
                m_spPlayBar->FUN_1422ce800((float)nPos);
        }
    }
}

// @0x140ff38f0
void UIWriteMusicDialog::FUN_140ff38f0(int nLength)
{
    if (m_spTotalTimer.IsNull())
    {
        if (MS2Ptr<ASMovieClip> spPlaying = m_30->FUN_1409b4560("m_playingMusic"))
            m_spTotalTimer = spPlaying->FUN_1409b4620("m_totalTimer");
        if (m_spPlayBar = static_cast<Unk_WmScript*>(m_30.operator->())->FUN_140fafed0<Unk_WmSlider>("m_playBar"))
        {
            ASFunction tooltip(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIWriteMusicDialog::FUN_140ff23b0), 0,
                               FUN_1422db730());
            m_spPlayBar->FUN_1409adbe0("tooltiplabelFunction", Scaleform::GFx::Value(tooltip.FUN_1422bb870()));
        }
    }
    if (m_spTotalTimer)
    {
        int nMinutes, nSeconds, nCentis;
        FUN_141b706a0(nLength, &nMinutes, &nSeconds, &nCentis);
        CStringW strText = FUN_14028dfa0(CStringW(L"s_writemusic_text_playtimer_total"), nMinutes, nSeconds);
        m_spTotalTimer->FUN_1422c4cd0(strText);
        if (m_spPlayBar)
            m_spPlayBar->FUN_1422ce800(0);
    }
}

// @0x140ff3d10
void UIWriteMusicDialog::FUN_140ff3d10(unsigned nTime)
{
    if (m_spPlayLine == 0)
        return;
    if (!FUN_140ff4550())
        return;
    unsigned nPage = nTime / 12000;
    if (m_nPage != nPage)
    {
        m_nPage = nPage;
        FUN_140ff4a80();
    }
    int nPos = nTime % 12000;
    nPos /= 10;
    nPos += 35;
    nPos -= 15;
    MS2Ptr<ASMovieClip> spLine = m_spPlayLine->FUN_1409b4560("m_playingLine");
    if (spLine)
        spLine->FUN_1422c0320(nPos);
}

// @0x140ff3e50
bool UIWriteMusicDialog::FUN_140ff3e50(MS2Ptr<ASDataProvider> spTabs, CString& strOut)
{
    strOut.Empty();
    if (!spTabs || spTabs->FUN_1422bc5d0() == 0)
        return false;
    unsigned nCount = spTabs->FUN_1422bc5d0();
    CString strMml;
    Scaleform::GFx::Value& array = spTabs->FUN_1422bb870();
    for (unsigned i = 0; i < nCount; i++)
    {
        Scaleform::GFx::Value tab;
        if (array.GetElement(i, &tab))
        {
            Scaleform::GFx::Value content;
            tab.GetMember("content", &content);
            CString strTab(content.GetString());
            if (!strTab.IsEmpty())
            {
                strTab.Remove(':');
                if (strMml.IsEmpty())
                    strMml = strTab;
                else
                    strMml += Unk_WmConcat(":", strTab);
            }
        }
    }
    strMml.Remove(' ');
    strMml.Remove('\n');
    strMml.Remove('\t');
    strMml.Remove('\r');
    return true;
}

// @0x140ff40b0
int UIWriteMusicDialog::FUN_140ff40b0()
{
    if (!m_spItem || static_cast<CItem*>(m_spItem)->FUN_140527840() == 0)
        return 0;
    MS2Ptr<ItemMusicScore> spScore = FUN_140281980()->GetMusicScore(static_cast<CItem*>(m_spItem)->FUN_1405276c0());
    if (spScore == 0)
        return 0;
    return spScore->noteLengthMax;
}

// @0x140ff41a0
void UIWriteMusicDialog::FUN_140ff41a0()
{
    CStringW strTitle;
    int nInstrument = -1;
    if (m_spItem.get())
    {
        strTitle = static_cast<CItem*>(m_spItem)->FUN_1405296c0();
        nInstrument = static_cast<CItem*>(m_spItem)->FUN_140527990()->m_n1c;
    }
    CString& strText = m_strText;
    ATL::CAtlArray<CString> parts;
    FUN_14015f0b0(strText, parts, ":");
    CString strMelody;
    size_t nCount = parts.GetCount();
    ASArray chords(2);
    for (size_t i = 0; i < nCount; i++)
    {
        if (i == 0)
            strMelody = parts[i];
        else
            chords.FUN_1422bbf70(parts[i]);
    }
    FUN_140ff43a0(strMelody, chords, strTitle, nInstrument);
}

// @0x140ff43a0
void UIWriteMusicDialog::FUN_140ff43a0(const CString& strMelody, ASArray& chords, const CStringW& strTitle, int nInstrument)
{
    if (FUN_140a467d0(&m_30))
        return;
    static_cast<Unk_WmScript*>(m_30.operator->())
        ->FUN_140ff70d0("setTabFromText", CString(strMelody), Scaleform::GFx::Value(chords.FUN_1422bb870()), CStringW(strTitle), nInstrument);
    FUN_140ff3450(false);
}

// @0x140ff4500
void UIWriteMusicDialog::SetItem(MS2Ptr<CItem> spItem)
{
    m_spItem = spItem;
}

// @0x140ff4550
bool UIWriteMusicDialog::FUN_140ff4550()
{
    MS2Ptr<ASDropdownMenu> spRollType = FUN_140c28560("m_rollType");
    if (spRollType)
    {
        if (spRollType->FUN_1422df6c0() == 0)
            return true;
        else
            return false;
    }
    return false;
}

// @0x140ff4610
void UIWriteMusicDialog::FUN_140ff4610(std::map<int, CString>& tabs)
{
    m_pages.clear();
    bool bFixed = true;
    if (FUN_140ff4550() == true)
        bFixed = false;
    std::map<int, CString>& range = tabs;
    std::map<int, CString>::iterator itEnd = range.end();
    for (std::map<int, CString>::iterator it = range.begin(); it != itEnd; ++it)
    {
        std::pair<const int, CString> tab = *it;
        int nTab = tab.first;
        CString strTab(tab.second);
        if (strTab.IsEmpty())
            continue;
        double dTime = 0.0;
        MMLParser parser;
        parser.SetText(strTab);
        parser.SetFixedTempo(bFixed);
        parser.Parse();
        std::vector<MS2Ptr<MMLToken> >& tokens = parser.m_tokens;
        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (tokens[i]->m_nType == 1)
                dTime += tokens[i]->m_dTime;
            else if (tokens[i]->m_nType == 0)
            {
                if (tokens[i]->m_dTime <= 1.0)
                    continue;
                unsigned nStart = (unsigned)dTime;
                unsigned nEnd = (unsigned)(tokens[i]->m_dTime + dTime);
                int nFirst = nStart / 12000;
                int nLast = (nEnd - 1) / 12000;
                if (nFirst != nLast)
                {
                    for (int nPage = nFirst; nPage <= nLast; nPage++)
                    {
                        TabNotes& page = m_pages[nPage];
                        NoteMap& notes = page[nTab];
                        notes.insert(std::make_pair(nStart, tokens[i]));
                    }
                }
                else
                {
                    TabNotes& page = m_pages[nFirst];
                    NoteMap& notes = page[nTab];
                    notes.insert(std::make_pair(nStart, tokens[i]));
                }
                dTime += tokens[i]->m_dTime;
            }
        }
    }
}

// @0x140ff4a80
// MS2-FUNCTIONAL: behaviour-equivalent; /Od codegen differs: one temp hop after m_pages[m_nPage] and the colors[] stack slot
void UIWriteMusicDialog::FUN_140ff4a80()
{
    if (m_spPlayLine == 0)
        return;
    const int nLeft = 0x23;
    const int nWidth = 0x4b0;
    const int nBottom = 0x197;
    MS2_FOR_EACH(auto spNote, m_notes)
        m_spPlayLine->FUN_1422c6b70(Scaleform::GFx::Value(spNote->FUN_1422bb890()));
    m_notes.clear();
    if (m_pages.find(m_nPage) != m_pages.end())
    {
        int colors[10] = {0xffd200, 0xff7521, 0xdf0008, 0x8dc63f, 0x139224, 0x13b5f2, 0x2960ff, 0xd85aa5, 0x822eff, 0xffffff};
        TabNotes& range = m_pages[m_nPage];
        TabNotes::const_iterator itEnd = range.end();
        for (TabNotes::const_iterator it = range.begin(); it != itEnd; ++it)
        {
            std::pair<int, NoteMap> tab = *it;
            int nTab = tab.first;
            if (nTab >= 10)
                continue;
            NoteMap& notes = tab.second;
            NoteMap::const_iterator itNoteEnd = notes.end();
            for (NoteMap::const_iterator itNote = notes.begin(); itNote != itNoteEnd; ++itNote)
            {
                std::pair<unsigned, MS2Ptr<MMLToken> > note = *itNote;
                if (note.second->m_nPitch < 0x18 || note.second->m_nPitch >= 0x78)
                    continue;
                int x = nLeft;
                int w = (int)(note.second->m_dTime / 10.0);
                unsigned nPageStart = m_nPage * 12000;
                if (note.first < nPageStart)
                {
                    x = nLeft;
                    w = (int)(((double)note.first + note.second->m_dTime - nPageStart) / 10.0);
                }
                else
                {
                    x = note.first % 12000 / 10 + nLeft;
                    w = (int)(note.second->m_dTime / 10.0);
                }
                int y = nBottom - (note.second->m_nPitch * 4 - 0x60);
                if (x < nLeft)
                    x = nLeft;
                if (x + w > nLeft + nWidth)
                    w = nLeft + nWidth - x;
                CString strName("write_music_note");
                MS2Ptr<ASUIComponent> spNote(new ASUIComponent(strName, 2));
                if (spNote == 0)
                    break;
                m_spPlayLine->FUN_1422c6900(Scaleform::GFx::Value(spNote->FUN_1422bb890()));
                spNote->FUN_1422bffe0(x, y);
                spNote->FUN_1409ba0d0("setActualSize", w - 1, 3);
                spNote->Invoke("setColor", colors[nTab]);
                spNote->FUN_1422c7b40(FUN_140ff5be0(note.second->m_nPitch, nTab, colors[nTab]));
                m_notes.push_back(spNote);
            }
        }
    }
    FUN_140cfee80((*m_spPlayLine).FUN_1422bb890(), CString("m_pageText"), StringFormat(L"{0}", m_nPage + 1));
    FUN_140cff950((*m_spPlayLine).FUN_1422bb890(), CString("m_prevPage"), m_nPage > 0);
    FUN_140cff950((*m_spPlayLine).FUN_1422bb890(), CString("m_nextPage"), m_nPage < (int)(m_pages.size() - 1));
    const int nSteps = 6;
    for (int i = 1; i <= nSteps; i++)
    {
        CString strName = StringFormat("m_lineStep{0}", i);
        int nStep = i + m_nPage * nSteps;
        if (FUN_140ff4550() == true)
        {
            int nTime = nStep * 2 - 2;
            int nSeconds = nTime % 60;
            int nMinutes = nTime / 60;
            CStringW strText = StringFormat(L"{0:02}:{1:02}", nMinutes, nSeconds);
            FUN_140cfee80((*m_spPlayLine).FUN_1422bb890(), CString(strName), CStringW(strText));
        }
        else
        {
            CStringW strText = StringFormat(L"{0}", nStep);
            FUN_140cfee80((*m_spPlayLine).FUN_1422bb890(), CString(strName), CStringW(strText));
        }
    }
}

// @0x140ff57e0
void UIWriteMusicDialog::FUN_140ff57e0()
{
    FUN_140cff950(FUN_1422dbb40(), CString("m_rollType"), 0);
    FUN_140cff950(FUN_1422dbb40(), CString("m_autoRefreshCheck"), 0);
    if (m_spPlayLine == 0)
        return;
    if (FUN_140ff4550() == true)
    {
        FUN_140cff840((*m_spPlayLine).FUN_1422bb890(), CString("m_prevPage"), 0);
        FUN_140cff840((*m_spPlayLine).FUN_1422bb890(), CString("m_nextPage"), 0);
    }
}

// @0x140ff59a0
void UIWriteMusicDialog::FUN_140ff59a0()
{
    FUN_140cff950(FUN_1422dbb40(), CString("m_rollType"), 1);
    FUN_140cff950(FUN_1422dbb40(), CString("m_autoRefreshCheck"), 1);
    if (m_spPlayLine == 0)
        return;
    MS2Ptr<ASMovieClip> spLine = m_spPlayLine->FUN_1409b4560("m_playingLine");
    if (spLine)
        spLine->FUN_1422c0320(0x23);
    FUN_140cff840((*m_spPlayLine).FUN_1422bb890(), CString("m_prevPage"), 1);
    FUN_140cff840((*m_spPlayLine).FUN_1422bb890(), CString("m_nextPage"), 1);
}

// @0x140ff5be0
CStringW UIWriteMusicDialog::FUN_140ff5be0(int nPitch, int nTab, unsigned long nColor)
{
    CString strKey = StringFormat("$s_writemusic_tab_{0}", nTab);
    CStringW strTab = FUN_14025e7a0()->FUN_1422b0570(strKey);
    int nOctave = nPitch / 12;
    int nNote = nPitch % 12;
    CString strNote(s_szNoteNames[nNote]);
    nOctave = nOctave - 1;
    int nNumber = nPitch - 12;
    CStringW strTooltip = FUN_14028dfa0(CStringW(L"s_writemusic_playroll_note_tooltip"), FUN_14083f9c0(nColor), strTab, nOctave, strNote, nNumber);
    return strTooltip;
}

// ---- inline COMDATs of this unit ----

// @0x140ff6b60
inline MS2Ptr<ASDataProvider> FUN_140ff6b60(int nMovieId, Scaleform::GFx::Value& v)
{
    MS2Ptr<ASDataProvider> spTabs(new Unk_WmProvider(v, nMovieId));
    return spTabs;
}

// @0x140ff7030
inline UICartoonDialog* FUN_140ff7030(int nUiType)
{
    if (FUN_1403ed2b0())
    {
        Unk_WmUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nUiType);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UICartoonDialog*>(ref.FUN_1403ed9e0());
    }
    return 0;
}

// @0x140ff70d0
inline Scaleform::GFx::Value Unk_WmScript::FUN_140ff70d0(const char* szMethod, CString a1, Scaleform::GFx::Value a2, CStringW a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141001a80
inline const char* FUN_141001a80(TiXmlDocument* pDoc)
{
    return reinterpret_cast<Unk_WmXmlDocState*>(pDoc)->m_errorDesc.c_str();
}

// Atexit thunks of this unit's statics (gap2 orphan di sweep: owner listed under its client\ms2 name).
// MS2-RANGE: 0x142cab100-0x142cab1a0 .text$yd
