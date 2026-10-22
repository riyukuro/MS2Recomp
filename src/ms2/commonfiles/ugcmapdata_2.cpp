// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UGC map XML loader and cache.
// MS2-UNIT: ?\ugcmapdata.cpp#2
// MS2-RANGE: 0x1408ad320-0x1408b3260 .text$mn
// MS2-RANGE: 0x1400bdde0-0x1400bdf00 .text$di
// MS2-RANGE: 0x142c9c910-0x142c9c980 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_cache@@YAXXZ 0x1400bdde0 ; unique
// MS2-PIN: ??__Es_lock@@YAXXZ 0x1400bde10 ; unique
// MS2-PIN: ??__Es_orderNames@@YAXXZ 0x1400bde40 ; unique
// MS2-PIN: ??0CUGCMapData@@QEAA@XZ 0x1408ad320 ; unique
// MS2-PIN: ??1CUGCMapData@@UEAA@XZ 0x1408ad3a0 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1408ae1c0 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1408ae1f0 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1408ae220 ; unique
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHUUnk_UGCFloor@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x1408ae270 ; unique
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1408ae2c0 ; unique
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1408ae310 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1408ae360 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHUUnk_UGCFloor@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1408ae3b0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHUUnk_UGCFloor@@@std@@@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHUUnk_UGCFloor@@@1@@Z 0x1408ae400 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1408ae420 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1408ae4f0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@AEAU?$pair@$$CBHUUnk_UGCFloor@@@1@1@Z 0x1408ae580 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHUUnk_UGCFloor@@@1@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@@Z 0x1408ae8e0 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHUUnk_UGCFloor@@@1@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@@Z 0x1408af520 ; unique
// MS2-PIN: ??$_Kfn@$$CBHUUnk_UGCFloor@@@?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@SAAEBHAEBU?$pair@$$CBHUUnk_UGCFloor@@@1@@Z 0x1408af930 ; unique
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@AEBH@Z 0x1408af940 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x1408af9e0 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@0@AEAPEAU10@@Z 0x1408afb30 ; unique
// MS2-PIN: ??$addressof@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@YAPEAU?$pair@$$CBHUUnk_UGCFloor@@@0@AEAU10@@Z 0x1408afb40 ; unique
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@0@AEAV10@@Z 0x1408afb50 ; unique
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@AEAPEAU31@@Z 0x1408afb60 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHUUnk_UGCFloor@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHUUnk_UGCFloor@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1408afbb0 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@@Z 0x1408afc60 ; unique
// MS2-PIN: ??$destroy@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHUUnk_UGCFloor@@@1@@Z 0x1408afc70 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1408afc80 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@0@AEAPEAU10@@Z 0x1408afd20 ; unique
// MS2-PIN: ??$forward@AEAU?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@YAAEAU?$pair@$$CBHUUnk_UGCFloor@@@0@AEAU10@@Z 0x1408afd30 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1408afd40 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1408afd50 ; unique
// MS2-PIN: ??$try_emplace@$$V@?$map@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x1408afd60 ; unique
// MS2-PIN: ??0?$CRBMap@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@QEAA@_K@Z 0x1408afda0 ; unique
// MS2-PIN: ??0?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@IEAA@_K@Z 0x1408afdd0 ; unique
// MS2-PIN: ??0?$Unk_PayloadPtr@VCUGCMapData@@@@QEAA@$$QEAV0@@Z 0x1408afe30 ; unique
// MS2-PIN: ??0?$Unk_PayloadPtr@VCUGCMapData@@@@QEAA@AEBV0@@Z 0x1408afe60 ; unique
// MS2-PIN: ??0?$Unk_PayloadPtr@VCUGCMapData@@@@QEAA@PEAVCUGCMapData@@@Z 0x1408afea0 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x1408afed0 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x1408aff00 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x1408aff30 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x1408aff70 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@1@@Z 0x1408affb0 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEAA@XZ 0x1408afff0 ; unique
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@1@@Z 0x1408b0010 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@1@@Z 0x1408b0050 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x1408b0090 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@QEAA@XZ 0x1408b00b0 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@QEAA@XZ 0x1408b00e0 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@QEAA@XZ 0x1408b0110 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@std@@@std@@QEAA@XZ 0x1408b0120 ; unique
// MS2-PIN: ??0?$map@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@@std@@QEAA@XZ 0x1408b0130 ; unique
// MS2-PIN: ??0?$map@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@@std@@QEAA@XZ 0x1408b0160 ; unique
// MS2-PIN: ??0CNode@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@QEAA@IAEBV?$Unk_PayloadPtr@VCUGCMapData@@@@@Z 0x1408b0190 ; unique
// MS2-PIN: ??0CPair@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@IEAA@IAEBV?$Unk_PayloadPtr@VCUGCMapData@@@@@Z 0x1408b01e0 ; unique
// MS2-PIN: ??0Unk_UGCFloor@@QEAA@XZ 0x1408b0220 ; unique
// MS2-PIN: ??1?$CRBMap@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@QEAA@XZ 0x1408b0250 ; unique
// MS2-PIN: ??1?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@QEAA@XZ 0x1408b0270 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1408b02b0 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1408b02e0 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1408b0310 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1408b0340 ; unique
// MS2-PIN: ??1?$map@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@@std@@QEAA@XZ 0x1408b0370 ; unique
// MS2-PIN: ??1?$map@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@@std@@QEAA@XZ 0x1408b0390 ; unique
// MS2-PIN: ??1CNode@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@QEAA@XZ 0x1408b03b0 ; unique
// MS2-PIN: ??1CPair@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@IEAA@XZ 0x1408b03d0 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1408b03f0 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1408b0430 ; unique
// MS2-PIN: ??A?$map@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@@std@@QEAAAEAUUnk_UGCFloor@@AEBH@Z 0x1408b0470 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHUUnk_UGCFloor@@@1@XZ 0x1408b04b0 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBHUUnk_UGCFloor@@@1@XZ 0x1408b04d0 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHUUnk_UGCFloor@@@1@XZ 0x1408b04f0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1408b0510 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1408b0560 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1408b0580 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1408b05d0 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1408b0660 ; unique
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1408b0680 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1408b06a0 ; unique
// MS2-PIN: ??_GCNode@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@QEAAPEAXI@Z 0x1408b0770 ; unique
// MS2-PIN: ?Find@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@IEBAPEAVCNode@12@I@Z 0x1408b07f0 ; unique
// MS2-PIN: ?FreeNode@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x1408b08e0 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@AEAAPEAVCNode@12@IAEBV?$Unk_PayloadPtr@VCUGCMapData@@@@@Z 0x1408b0980 ; unique
// MS2-PIN: ?IsNil@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@AEBA_NPEAVCNode@12@@Z 0x1408b0a80 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x1408b0ac0 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@QEBA_NIAEAV?$Unk_PayloadPtr@VCUGCMapData@@@@@Z 0x1408b0bd0 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1408b0c20 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@AEAAPEAVCNode@12@IAEBV?$Unk_PayloadPtr@VCUGCMapData@@@@@Z 0x1408b0c90 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1408b0ef0 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@IEAAPEAVCNode@12@IAEBV?$Unk_PayloadPtr@VCUGCMapData@@@@@Z 0x1408b0fc0 ; unique
// MS2-PIN: ?RemoveAll@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@QEAAXXZ 0x1408b1240 ; unique
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x1408b12c0 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x1408b1320 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$Unk_PayloadPtr@VCUGCMapData@@@@@Z 0x1408b1430 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@IV?$Unk_PayloadPtr@VCUGCMapData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_PayloadPtr@VCUGCMapData@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x1408b14a0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@XZ 0x1408b1510 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@2@XZ 0x1408b15d0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@XZ 0x1408b1690 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1408b1770 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x1408b17b0 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x1408b17e0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@Z 0x1408b1810 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@Z 0x1408b1860 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@2@@Z 0x1408b1900 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@2@@Z 0x1408b19a0 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@@2@@Z 0x1408b1f50 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@Z 0x1408b2500 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@2@@Z 0x1408b2530 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@Z 0x1408b2560 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@XZ 0x1408b2590 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@XZ 0x1408b25c0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x1408b25f0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x1408b2600 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@2@XZ 0x1408b2610 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@2@XZ 0x1408b2620 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@2@XZ 0x1408b2630 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@2@XZ 0x1408b2640 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@XZ 0x1408b2650 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@2@XZ 0x1408b2660 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@2@XZ 0x1408b2670 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@2@XZ 0x1408b26a0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x1408b26d0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x1408b26f0 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@Z 0x1408b2710 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHUUnk_UGCFloor@@@2@@Z 0x1408b2740 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@XZ 0x1408b2760 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@Z 0x1408b2770 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@PEAU32@@Z 0x1408b2850 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@PEAU32@@Z 0x1408b2880 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@XZ 0x1408b28b0 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@XZ 0x1408b28d0 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@@Z 0x1408b28f0 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1408b29d0 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1408b2a30 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@_K@Z 0x1408b2a90 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@2@XZ 0x1408b2ac0 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x1408b2b30 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x1408b2bd0 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@2@_K@Z 0x1408b2c70 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@2@XZ 0x1408b2cd0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@2@0@Z 0x1408b2d30 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@2@@Z 0x1408b2e20 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@@2@0@Z 0x1408b2ed0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@@2@@Z 0x1408b2fc0 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@@std@@@2@AEBH@Z 0x1408b3070 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCFloor@@@std@@PEAX@std@@@2@@Z 0x1408b30d0 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x1408b30e0 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBHUUnk_UGCFloor@@@std@@@std@@SAPEAU?$pair@$$CBHUUnk_UGCFloor@@@2@AEAU32@@Z 0x1408b3100 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HUUnk_UGCFloor@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCFloor@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x1408b3120 ; unique
// MS2-PIN: ??__Fs_cache@@YAXXZ 0x142c9c910 ; unique
// MS2-PIN: ??__Fs_lock@@YAXXZ 0x142c9c930 ; unique
// MS2-PIN: ??__Fs_orderNames@@YAXXZ 0x142c9c950 ; unique
// MS2-PINS-END tplpin

#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ugcmapdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcmapdata_2.h"
#include "filesystem.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include <atlcoll.h>
#include <string>

class Unk_140163940 {
public:
    Unk_140163940(CLockCriticalSection&);
    ~Unk_140163940();
    operator int() const;
private:
    void* m_lock;
};
MS2_CHECK_SIZE(Unk_140163940,8);
class Unk_140165cf0;
void* FUN_140166440();
Unk_140165cf0* FUN_140165cf0(void*,const char*);
Unk_140165cf0* FUN_140168650(void*,const char*);
void FUN_14015eb90(void*,int,int,const wchar_t*,const CString&);
int FUN_1408731e0(void*,const char*,int*);
int FUN_140873220(void*,const char*,unsigned*);
int FUN_140873360(void*,const char*,float*);
int FUN_1408736d0(void*,const char*,bool*);
int FUN_140873710(void*,const char*,int*);
const char* FUN_14086f4b0(void*,const char*);
CString FUN_14015f710(class Unk_140165cf0*,const char*,CString);
void FUN_1401782a0(const CString&,std::vector<unsigned>&,const char*);
void FUN_140178270(const CString&,std::vector<int>&,const char*);

// Pure local cache/lock initialization. Cache readers and loader are not hooked:
// the exe keeps its own mutable cache and the loader constructs RTTI-bearing objects.
static ATL::CRBMap<unsigned,Unk_UGCMapPtr> s_cache(10);
static CLockCriticalSection s_lock;
static CString s_orderNames[7]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};

// @0x1408ad320
CUGCMapData::CUGCMapData() { groups.clear(); }
// @0x1408ad3a0
CUGCMapData::~CUGCMapData() {}

// MS2-FUNCTIONAL: typed scoped cache lookup; /Od return-object placement differs.
Unk_UGCMapPtr FUN_1408ad3f0(int mapId);
#ifndef MS2_HOOK_DLL
// @0x1408ad3f0
Unk_UGCMapPtr FUN_1408ad3f0(int mapId) {
    Unk_UGCMapPtr value(0);
    if(mapId==0) return Unk_UGCMapPtr(0);
    {
        Unk_140163940 lock(s_lock);
        if(static_cast<int>(lock)) {} else if(s_cache.Lookup(mapId,value)) return value;
    }
    return LoadUGCMap(mapId);
}
#endif

// MS2-FUNCTIONAL: typed XML records retain all defaults, conversions and error/cache paths.
#ifndef MS2_HOOK_DLL
// @0x1408ad500
Unk_UGCMapPtr LoadUGCMap(unsigned mapId) {
    CString path;
    path.Format("./Data/Xml/UGCMap/%08d.xml",mapId);
    if(GetFileSystem()->FUN_1403987d0(std::string(path))==0) return Unk_UGCMapPtr(0);
    TiXmlDocument document;
    if(GetFileSystem()->FUN_1403974b0(&document,path,0,false,false)==0) return Unk_UGCMapPtr(0);
    Unk_UGCMapPtr value(new CUGCMapData);
    class Unk_140165cf0* root=FUN_140165cf0(&document,"ugcmap");
    if(root==0) {
        FUN_14015eb90(FUN_140166440(),1,0x13,L"xml 형식이 잘못 되었습니다[<ugcmap> {0}]",path);
        return Unk_UGCMapPtr(0);
    }
    for(auto* node=FUN_140165cf0(root,"group");node;node=FUN_140168650(node,"group")) {
        int no=0; FUN_1408731e0(node,"no",&no);
        int contractPrice=0; FUN_1408731e0(node,"contractPrice",&contractPrice);
        CString contractText(FUN_14086f4b0(node,"contractPriceItemCode"));
        long contractItemCode=atol(contractText);
        int contractDays=0; FUN_1408731e0(node,"ugcHomeContractDate",&contractDays);
        int extensionDays=0; FUN_1408731e0(node,"ugcHomeExtensionDate",&extensionDays);
        int heightLimit=0; FUN_1408731e0(node,"heightLimit",&heightLimit);
        int buildingCount=0; FUN_1408731e0(node,"installableBuildingCount",&buildingCount);
        int returnPlaceId=0; FUN_1408731e0(node,"returnPlaceID",&returnPlaceId);
        int sellType=0; FUN_1408731e0(node,"sellType",&sellType);
        int buildingType=0; FUN_1408731e0(node,"builingType",&buildingType);
        int area=0; FUN_1408731e0(node,"area",&area);
        int indoorCount=0; FUN_1408731e0(node,"indoorCount",&indoorCount);
        int extensionPrice=0; FUN_1408731e0(node,"extensionPrice",&extensionPrice);
        CString extensionText(FUN_14086f4b0(node,"extensionPriceItemCode"));
        long extensionItemCode=atol(extensionText);
        int houseNumber=0; FUN_1408731e0(node,"houseNumber",&houseNumber);
        CString previewIcon=FUN_14015f710(node,"previewIcon",CString(""));
        int blockCode=0; FUN_1408731e0(node,"blockCode",&blockCode);
        std::vector<unsigned> npcs;
        CString npcText=FUN_14015f710(node,"privilegeNPC",CString(""));
        FUN_1401782a0(npcText,npcs,",");
        std::vector<int> portals;
        CString portalText=FUN_14015f710(node,"privilegePortal",CString(""));
        FUN_140178270(portalText,portals,",");
        std::vector<int> interact;
        CString interactText=FUN_14015f710(node,"privilegeInteract",CString(""));
        FUN_140178270(interactText,interact,",");
        int maidCount=0; FUN_1408731e0(node,"maidCount",&maidCount);
        int triggerCount=0; FUN_1408731e0(node,"triggerCount",&triggerCount);
        int installNpcCount=0; FUN_1408731e0(node,"installNpcCount",&installNpcCount);
        bool privilegeTaxi=false; FUN_1408736d0(node,"privilegeTaxi",&privilegeTaxi);
        bool hideEmoticon=false; FUN_1408736d0(node,"hideEmoticon",&hideEmoticon);
        unsigned trophyId=0; FUN_140873220(node,"trophyID",&trophyId);
        bool adminOnly=false; FUN_1408736d0(node,"adminOnly",&adminOnly);
        CString indoorSizeType=FUN_14015f710(node,"indoorSizeType",CString(""));
        int useCouponEvent=0; FUN_140873710(node,"useCouponEvent",&useCouponEvent);
        if(value->groups.find(no)==value->groups.end()) value->groups[no]=Unk_UGCGroup();
        Unk_UGCGroup& group=value->groups[no];
        group.contractPrice=contractPrice; group.contractPriceItemCode=contractItemCode;
        group.extensionPrice=extensionPrice; group.extensionPriceItemCode=extensionItemCode;
        group.contractDate=contractDays;group.extensionDate=extensionDays;
        group.heightLimit=heightLimit;group.buildingCount=buildingCount;
        group.returnPlaceID=returnPlaceId;group.sellType=sellType;
        group.indoorCount=indoorCount;group.blockCode=blockCode;group.houseNumber=houseNumber;
        group.buildingType=buildingType;group.previewIcon=previewIcon;group.field30=area;
        group.privilegeNPC=npcs;group.privilegePortal=portals;group.privilegeInteract=interact;
        group.privilegeTaxi=privilegeTaxi;group.maidCount=maidCount;group.installNpcCount=installNpcCount;
        group.hideEmoticon=hideEmoticon;group.trophyID=trophyId;group.adminOnly=adminOnly;
        group.triggerCount=triggerCount;group.indoorSizeType=indoorSizeType;group.useCouponEvent=useCouponEvent;
    }
    for(auto* node=FUN_140165cf0(root,"floor");node;node=FUN_140168650(node,"floor")) {
        Unk_UGCFloor floor;
        int id=0;FUN_1408731e0(node,"id",&id);
        FUN_140873360(node,"start_height",&floor.startHeight);
        FUN_1408731e0(node,"step",&floor.field4);
        value->floors[id]=floor;
    }
    {
        Unk_140163940 lock(s_lock);
        if(static_cast<int>(lock)==0) s_cache.SetAt(mapId,value);
    }
    return std::move(value);
}
#endif
MS2_EMIT_CRT_MEMMOVE_S();
