// CFilePreload worker and its owned template tail.
// MS2-UNIT: ?\filepreload.cpp#1
// MS2-RANGE: 0x14120f7c0-0x141218010 .text$mn
// MS2-RANGE: 0x1400e9020-0x1400e9260 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0CFilePreload@@QEAA@XZ 0x14120f7c0 ; unique
// MS2-PIN: ??1CFilePreload@@UEAA@XZ 0x14120f9d0 ; unique
// MS2-PIN: ?vfunc_1@CFilePreload@@UEAAIPEAXAEAVUnk_140659080@@@Z 0x14120fb80 ; unique
// MS2-PIN: ?FUN_1412102e0@CFilePreload@@QEAAXXZ 0x1412102e0 ; unique
// MS2-PIN: ?FUN_141210420@CFilePreload@@QEAAXH@Z 0x141210420 ; unique
// MS2-PIN: ?FUN_1412104a0@CFilePreload@@QEAAXH@Z 0x1412104a0 ; unique
// MS2-PIN: ?FUN_1412104c0@CFilePreload@@QEAAXI@Z 0x1412104c0 ; unique
// MS2-PIN: ?FUN_141210540@CFilePreload@@QEAAXIGH@Z 0x141210540 ; unique
// MS2-PIN: ?FUN_1412106a0@CFilePreload@@QEAAXU?$pair@IG@std@@H@Z 0x1412106a0 ; unique
// MS2-PIN: ?FUN_141210770@CFilePreload@@QEAAXI@Z 0x141210770 ; unique
// MS2-PIN: ?FUN_1412107f0@CFilePreload@@QEAAXV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@Z 0x1412107f0 ; unique
// MS2-PIN: ?FUN_141210960@CFilePreload@@QEAAXV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@Z 0x141210960 ; unique
// MS2-PIN: ?FUN_141210ac0@CFilePreload@@QEAAXV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x141210ac0 ; unique
// MS2-PIN: ?FUN_141210c20@CFilePreload@@QEAAXXZ 0x141210c20 ; unique
// MS2-PIN: ?FUN_141210c60@CFilePreload@@QEAAHXZ 0x141210c60 ; unique
// MS2-PIN: ?FUN_141210c80@CFilePreload@@QEAAHXZ 0x141210c80 ; unique
// MS2-PIN: ?FUN_141210ca0@CFilePreload@@SAX_N@Z 0x141210ca0 ; unique
// MS2-PIN: ?FUN_141210cc0@CFilePreload@@QEAAX_N@Z 0x141210cc0 ; unique
// MS2-PIN: ?FUN_141210ce0@CFilePreload@@QEAAXV?$TFunctor@XV?$ParamList@PEAXVEmptyParam@@@@@@@Z 0x141210ce0 ; unique
// MS2-PIN: ?FUN_141210da0@CFilePreload@@QEAAXXZ 0x141210da0 ; unique
// MS2-PIN: ?FUN_141210e10@CFilePreload@@QEAAX_N@Z 0x141210e10 ; unique
// MS2-PIN: ?FUN_141210f00@CFilePreload@@QEAAX_N@Z 0x141210f00 ; unique
// MS2-PIN: ?FUN_141211240@CFilePreload@@QEAAXPEAX@Z 0x141211240 ; unique
// MS2-PIN: ?FUN_141211380@CFilePreload@@QEAAXPEAX@Z 0x141211380 ; unique
// MS2-PIN: ?FUN_141211480@CFilePreload@@QEAAXPEAX@Z 0x141211480 ; unique
// MS2-PIN: ?FUN_1412115e0@CFilePreload@@QEAAXPEAX@Z 0x1412115e0 ; unique
// MS2-PIN: ?FUN_141211b30@CFilePreload@@QEAAXH@Z 0x141211b30 ; unique
// MS2-PIN: ?FUN_141211b80@CFilePreload@@SAIPEAX@Z 0x141211b80 ; unique
// MS2-PIN: ?FUN_141211c20@CFilePreload@@QEAAXXZ 0x141211c20 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141211c40 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141211c70 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@1@$$QEA_N@Z 0x141211ca0 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@1@$$QEA_N@Z 0x141211cf0 ; unique
// MS2-PIN: ??$?0AEBU?$less@UUnk_PreloadId@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@UUnk_PreloadId@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@UUnk_PreloadId@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141211d40 ; unique
// MS2-PIN: ??$?0AEBU?$less@UUnk_PreloadPath@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@UUnk_PreloadPath@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@UUnk_PreloadPath@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141211d90 ; unique
// MS2-PIN: ??$?0V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@1@$$QEA_N@Z 0x141211e80 ; unique
// MS2-PIN: ??$?0V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@1@$$QEA_N@Z 0x141211ed0 ; unique
// MS2-PIN: ?Clone@?$TFunctor@XV?$ParamList@PEAXVEmptyParam@@@@@@CAPEAV?$FunctorImpl@XV?$ParamList@PEAXVEmptyParam@@@@@@PEAV2@@Z 0x141211f20 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEBUUnk_PreloadId@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@U_Not_a_node_tag@1@AEBUUnk_PreloadId@@@Z 0x141211f60 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEBUUnk_PreloadPath@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@U_Not_a_node_tag@1@AEBUUnk_PreloadPath@@@Z 0x141211f90 ; unique
// MS2-PIN: ??$_Buynode@AEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@1@AEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x141211fc0 ; unique
// MS2-PIN: ??$_Buynode@AEAUUnk_PreloadId@@@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@AEAUUnk_PreloadId@@@Z 0x141212050 ; unique
// MS2-PIN: ??$_Buynode@AEAUUnk_PreloadPath@@@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@AEAUUnk_PreloadPath@@@Z 0x1412120e0 ; unique
// MS2-PIN: ??$_Buynode@AEBUUnk_PreloadId@@@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@AEBUUnk_PreloadId@@@Z 0x141212170 ; unique
// MS2-PIN: ??$_Buynode@AEBUUnk_PreloadPath@@@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@AEBUUnk_PreloadPath@@@Z 0x141212200 ; unique
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x141212290 ; unique
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x1412123b0 ; unique
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x1412124d0 ; unique
// MS2-PIN: ??$_Copy_nodes@U_Copy_tag@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@1@PEAU21@0U_Copy_tag@01@@Z 0x1412125f0 ; unique
// MS2-PIN: ??$_Copy_nodes@U_Copy_tag@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@PEAU21@0U_Copy_tag@01@@Z 0x141212700 ; unique
// MS2-PIN: ??$_Copy_nodes@U_Copy_tag@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@PEAU21@0U_Copy_tag@01@@Z 0x141212810 ; unique
// MS2-PIN: ??$_Copy_or_move@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$integral_constant@_N$00@std@@@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@1@AEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U_Copy_tag@01@U?$integral_constant@_N$00@1@@Z 0x141212920 ; unique
// MS2-PIN: ??$_Copy_or_move@UUnk_PreloadId@@U?$integral_constant@_N$00@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@AEAUUnk_PreloadId@@U_Copy_tag@01@U?$integral_constant@_N$00@1@@Z 0x141212950 ; unique
// MS2-PIN: ??$_Copy_or_move@UUnk_PreloadPath@@U?$integral_constant@_N$00@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@AEAUUnk_PreloadPath@@U_Copy_tag@01@U?$integral_constant@_N$00@1@@Z 0x141212980 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@?$_Tree_node@UUnk_PreloadId@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@1@PEAU01@@Z 0x1412129b0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@1@PEAU01@@Z 0x141212a40 ; unique
// MS2-PIN: ??$_Insert_at@AEBUUnk_PreloadId@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@1@_NPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@AEBUUnk_PreloadId@@U_Not_a_node_tag@1@@Z 0x141212ad0 ; unique
// MS2-PIN: ??$_Insert_at@AEBUUnk_PreloadPath@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@1@_NPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@AEBUUnk_PreloadPath@@U_Not_a_node_tag@1@@Z 0x141212e30 ; unique
// MS2-PIN: ??$_Insert_nohint@AEBUUnk_PreloadId@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@_N@1@_NAEBUUnk_PreloadId@@U_Not_a_node_tag@1@@Z 0x141213190 ; unique
// MS2-PIN: ??$_Insert_nohint@AEBUUnk_PreloadPath@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@_N@1@_NAEBUUnk_PreloadPath@@U_Not_a_node_tag@1@@Z 0x1412135a0 ; unique
// MS2-PIN: ??$_Lbound@UUnk_PreloadId@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@AEBUUnk_PreloadId@@@Z 0x1412139b0 ; unique
// MS2-PIN: ??$_Lbound@UUnk_PreloadPath@@@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@AEBUUnk_PreloadPath@@@Z 0x141213a50 ; unique
// MS2-PIN: ??$_Pocca@V?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@@std@@YAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@0@AEBV10@@Z 0x141213af0 ; unique
// MS2-PIN: ??$_Pocca@V?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@@std@@YAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@0@AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x141213b20 ; unique
// MS2-PIN: ??$_Pocca@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@std@@YAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@0@AEBV10@@Z 0x141213b30 ; unique
// MS2-PIN: ??$_Pocca@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@std@@YAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@0@AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x141213b60 ; unique
// MS2-PIN: ??$_Pocca@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@std@@YAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@0@AEBV10@@Z 0x141213b70 ; unique
// MS2-PIN: ??$_Pocca@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@std@@YAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@0@AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x141213ba0 ; unique
// MS2-PIN: ??$addressof@$$CBV?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@@std@@YAPEBV?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@0@AEBV10@@Z 0x141213bb0 ; unique
// MS2-PIN: ??$addressof@$$CBV?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@@std@@YAPEBV?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@0@AEBV10@@Z 0x141213bc0 ; unique
// MS2-PIN: ??$addressof@$$CBV?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@@std@@YAPEBV?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@0@AEBV10@@Z 0x141213bd0 ; unique
// MS2-PIN: ??$addressof@$$CBUUnk_PreloadId@@@std@@YAPEBUUnk_PreloadId@@AEBU1@@Z 0x141213be0 ; unique
// MS2-PIN: ??$addressof@$$CBUUnk_PreloadPath@@@std@@YAPEBUUnk_PreloadPath@@AEBU1@@Z 0x141213bf0 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@0@AEAPEAU10@@Z 0x141213c00 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@0@AEAPEAU10@@Z 0x141213c10 ; unique
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@0@AEAV10@@Z 0x141213c20 ; unique
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@0@AEAV10@@Z 0x141213c30 ; unique
// MS2-PIN: ??$addressof@UUnk_PreloadId@@@std@@YAPEAUUnk_PreloadId@@AEAU1@@Z 0x141213c40 ; unique
// MS2-PIN: ??$addressof@UUnk_PreloadPath@@@std@@YAPEAUUnk_PreloadPath@@AEAU1@@Z 0x141213c50 ; unique
// MS2-PIN: ??$construct@PEAU?$_Tree_node@UUnk_PreloadId@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@1@QEAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@AEAPEAU31@@Z 0x141213c60 ; unique
// MS2-PIN: ??$construct@PEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@1@QEAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@AEAPEAU31@@Z 0x141213cb0 ; unique
// MS2-PIN: ??$construct@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAV12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@1@QEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAV34@@Z 0x141213d00 ; unique
// MS2-PIN: ??$construct@UUnk_PreloadId@@AEAU1@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@1@QEAUUnk_PreloadId@@AEAU3@@Z 0x141213d50 ; unique
// MS2-PIN: ??$construct@UUnk_PreloadId@@AEBU1@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@1@QEAUUnk_PreloadId@@AEBU3@@Z 0x141213da0 ; unique
// MS2-PIN: ??$construct@UUnk_PreloadPath@@AEAU1@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@1@QEAUUnk_PreloadPath@@AEAU3@@Z 0x141213df0 ; unique
// MS2-PIN: ??$construct@UUnk_PreloadPath@@AEBU1@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@1@QEAUUnk_PreloadPath@@AEBU3@@Z 0x141213e40 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@1@QEAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@@Z 0x141213e90 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@1@QEAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@@Z 0x141213ea0 ; unique
// MS2-PIN: ??$destroy@UUnk_PreloadId@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@1@QEAUUnk_PreloadId@@@Z 0x141213eb0 ; unique
// MS2-PIN: ??$destroy@UUnk_PreloadPath@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@1@QEAUUnk_PreloadPath@@@Z 0x141213ec0 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@0@AEAPEAU10@@Z 0x141213ee0 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@0@AEAPEAU10@@Z 0x141213ef0 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@0@AEAV10@@Z 0x141213f00 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@0@AEAV10@@Z 0x141213f10 ; unique
// MS2-PIN: ??$forward@AEAUUnk_PreloadId@@@std@@YAAEAUUnk_PreloadId@@AEAU1@@Z 0x141213f20 ; unique
// MS2-PIN: ??$forward@AEAUUnk_PreloadPath@@@std@@YAAEAUUnk_PreloadPath@@AEAU1@@Z 0x141213f30 ; unique
// MS2-PIN: ??$forward@AEBU?$less@UUnk_PreloadId@@@std@@@std@@YAAEBU?$less@UUnk_PreloadId@@@0@AEBU10@@Z 0x141213f40 ; unique
// MS2-PIN: ??$forward@AEBU?$less@UUnk_PreloadPath@@@std@@@std@@YAAEBU?$less@UUnk_PreloadPath@@@0@AEBU10@@Z 0x141213f50 ; unique
// MS2-PIN: ??$forward@AEBUUnk_PreloadId@@@std@@YAAEBUUnk_PreloadId@@AEBU1@@Z 0x141213f60 ; unique
// MS2-PIN: ??$forward@AEBUUnk_PreloadPath@@@std@@YAAEBUUnk_PreloadPath@@AEBU1@@Z 0x141213f70 ; unique
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@0@AEAV10@@Z 0x141213f80 ; unique
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@0@AEAV10@@Z 0x141213f90 ; unique
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@_N@1@AEBUUnk_PreloadId@@@Z 0x141213fa0 ; unique
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@_N@1@AEBUUnk_PreloadPath@@@Z 0x141213fe0 ; unique
// MS2-PIN: ??0?$TFunctor@XV?$ParamList@HVEmptyParam@@@@@@QEAA@XZ 0x141214160 ; unique
// MS2-PIN: ??0?$TFunctor@XV?$ParamList@PEAXVEmptyParam@@@@@@QEAA@XZ 0x141214180 ; unique
// MS2-PIN: ??0?$TSingleton@VCFilePreload@@@@QEAA@XZ 0x1412141a0 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@UUnk_PreloadId@@@1@@Z 0x1412141f0 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@UUnk_PreloadPath@@@1@@Z 0x141214220 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@UUnk_PreloadId@@@1@@Z 0x141214250 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@UUnk_PreloadPath@@@1@@Z 0x141214290 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@1@@Z 0x1412142d0 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@1@@Z 0x141214310 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@UUnk_PreloadId@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@1@@Z 0x141214350 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@1@@Z 0x141214390 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@QEAA@XZ 0x1412143d0 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@QEAA@XZ 0x141214400 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@QEAA@XZ 0x141214430 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@QEAA@XZ 0x141214440 ; unique
// MS2-PIN: ??0?$set@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@@std@@QEAA@XZ 0x141214450 ; unique
// MS2-PIN: ??0?$set@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@@std@@QEAA@XZ 0x141214480 ; unique
// MS2-PIN: ??0Unk_PreloadId@@QEAA@AEBU?$pair@IG@std@@H@Z 0x1412144b0 ; unique
// MS2-PIN: ??0Unk_PreloadId@@QEAA@IGH@Z 0x1412144f0 ; unique
// MS2-PIN: ??0Unk_PreloadPath@@QEAA@AEBU0@@Z 0x141214540 ; unique
// MS2-PIN: ??0Unk_PreloadPath@@QEAA@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@Z 0x141214580 ; unique
// MS2-PIN: ??1?$FunctorImpl@XV?$ParamList@PEAXVEmptyParam@@@@@@UEAA@XZ 0x141214600 ; unique
// MS2-PIN: ??1?$TFunctor@XV?$ParamList@HVEmptyParam@@@@@@QEAA@XZ 0x141214620 ; unique
// MS2-PIN: ??1?$TFunctor@XV?$ParamList@PEAXVEmptyParam@@@@@@QEAA@XZ 0x141214650 ; unique
// MS2-PIN: ??1?$TSingleton@VCFilePreload@@@@UEAA@XZ 0x141214680 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA@XZ 0x1412146a0 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA@XZ 0x1412146d0 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA@XZ 0x141214700 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA@XZ 0x141214730 ; unique
// MS2-PIN: ??1?$set@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@@std@@QEAA@XZ 0x141214760 ; unique
// MS2-PIN: ??1?$set@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@@std@@QEAA@XZ 0x141214780 ; unique
// MS2-PIN: ??1Unk_PreloadPath@@QEAA@XZ 0x1412147a0 ; unique
// MS2-PIN: ??4?$TFunctor@XV?$ParamList@PEAXVEmptyParam@@@@@@QEAAAEAV0@AEBV0@@Z 0x1412147c0 ; unique
// MS2-PIN: ??4?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x141214800 ; unique
// MS2-PIN: ??4?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x141214880 ; unique
// MS2-PIN: ??4?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x141214900 ; unique
// MS2-PIN: ??4?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@QEAAAEAV01@AEBV01@@Z 0x141214980 ; unique
// MS2-PIN: ??4?$set@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@@std@@QEAAAEAV01@AEBV01@@Z 0x1412149b0 ; unique
// MS2-PIN: ??4?$set@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@@std@@QEAAAEAV01@AEBV01@@Z 0x1412149e0 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141214a10 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141214a50 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141214a90 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141214ad0 ; unique
// MS2-PIN: ??C?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@QEBAPEBUUnk_PreloadId@@XZ 0x141214b10 ; unique
// MS2-PIN: ??C?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@QEBAPEBUUnk_PreloadPath@@XZ 0x141214b30 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@QEBAAEBUUnk_PreloadId@@XZ 0x141214b50 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@QEBAAEBUUnk_PreloadPath@@XZ 0x141214b70 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141214b90 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141214be0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141214c00 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141214c50 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141214c70 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141214d00 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141214d90 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141214db0 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141214dd0 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141214ea0 ; unique
// MS2-PIN: ??MUnk_PreloadId@@QEBA_NAEBU0@@Z 0x141214f70 ; unique
// MS2-PIN: ??MUnk_PreloadPath@@QEBA_NAEBU0@@Z 0x141214fa0 ; unique
// MS2-PIN: ?Invoke@?$ClassFunHandler@V?$TFunctor@XV?$ParamList@PEAXVEmptyParam@@@@@@PEAVCFilePreload@@P82@EAAXPEAX@Z@@UEAAXPEAX@Z 0x141214fd0 ; unique
// MS2-PIN: ??R?$TFunctor@XV?$ParamList@HVEmptyParam@@@@@@QEAAXH@Z 0x141215010 ; unique
// MS2-PIN: ??R?$TFunctor@XV?$ParamList@PEAXVEmptyParam@@@@@@QEAAXPEAX@Z 0x141215040 ; unique
// MS2-PIN: ??R?$less@UUnk_PreloadId@@@std@@QEBA_NAEBUUnk_PreloadId@@0@Z 0x141215070 ; unique
// MS2-PIN: ??R?$less@UUnk_PreloadPath@@@std@@QEBA_NAEBUUnk_PreloadPath@@0@Z 0x1412150a0 ; unique
// MS2-PIN: ??_G?$FunctorImpl@XV?$ParamList@PEAXVEmptyParam@@@@@@UEAAPEAXI@Z 0x141215120 ; unique
// MS2-PIN: ??_G?$TSingleton@VCFilePreload@@@@UEAAPEAXI@Z 0x141215160 ; unique
// MS2-PIN: ??_GUnk_PreloadPath@@QEAAPEAXI@Z 0x1412151e0 ; unique
// MS2-PIN: ?Start@CThread@@QEAAHPEAXHHIPEAU_SECURITY_ATTRIBUTES@@@Z 0x141215220 ; unique
// MS2-PIN: ?FUN_141215480@@YAPEAVCLearningQuestTable@@XZ 0x141215480 ; unique
// MS2-PIN: ?FUN_141215500@@YAPEAVCMeratMarketPremium@@XZ 0x141215500 ; unique
// MS2-PIN: ?IsNull@?$TFunctor@XV?$ParamList@HVEmptyParam@@@@@@QEBA_NXZ 0x1412155d0 ; unique
// MS2-PIN: ?IsNull@?$TFunctor@XV?$ParamList@PEAXVEmptyParam@@@@@@QEBA_NXZ 0x141215600 ; unique
// MS2-PIN: ?FUN_141215630@COptimizer@@QEBAHXZ 0x141215630 ; unique
// MS2-PIN: ?GetThreadId@CThread@@QEBAKXZ 0x141215640 ; unique
// MS2-PIN: ?Clear@?$TFunctor@XV?$ParamList@HVEmptyParam@@@@@@QEAAXXZ 0x141215650 ; unique
// MS2-PIN: ?Clear@?$TFunctor@XV?$ParamList@PEAXVEmptyParam@@@@@@QEAAXXZ 0x1412156c0 ; unique
// MS2-PIN: ?_Alloc_proxy@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAXXZ 0x141215730 ; unique
// MS2-PIN: ?_Alloc_proxy@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAXXZ 0x141215740 ; unique
// MS2-PIN: ?_Alloc_proxy@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAXXZ 0x141215750 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@XZ 0x141215760 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@XZ 0x141215820 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@XZ 0x1412158e0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@XZ 0x1412159c0 ; unique
// MS2-PIN: ?PreloadThreadEntry@@YAIPEAX@Z 0x141215aa0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEBA_NAEBUUnk_PreloadId@@0@Z 0x141215b10 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEBA_NAEBUUnk_PreloadPath@@0@Z 0x141215b50 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAXXZ 0x141215b90 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAXXZ 0x141215bc0 ; unique
// MS2-PIN: ?_Copy_alloc@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAXAEBV?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@2@@Z 0x141215bf0 ; unique
// MS2-PIN: ?_Copy_alloc@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAXAEBV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@2@@Z 0x141215c80 ; unique
// MS2-PIN: ?_Copy_alloc@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAXAEBV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@2@@Z 0x141215d10 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEAAXU_Not_a_node_tag@2@@Z 0x141215da0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEAAXU_Not_a_node_tag@2@@Z 0x141215db0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@@Z 0x141215dc0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@@Z 0x141215e60 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@2@@Z 0x141215f00 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@2@@Z 0x1412164b0 ; unique
// MS2-PIN: ?_Free_proxy@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAXXZ 0x141216a60 ; unique
// MS2-PIN: ?_Free_proxy@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAXXZ 0x141216a70 ; unique
// MS2-PIN: ?_Free_proxy@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAXXZ 0x141216a80 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@@Z 0x141216a90 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@@Z 0x141216ac0 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@@Z 0x141216af0 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@@Z 0x141216b20 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@XZ 0x141216b50 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@XZ 0x141216b80 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@XZ 0x141216bb0 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@XZ 0x141216be0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@UUnk_PreloadId@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@UUnk_PreloadId@@@2@XZ 0x141216c10 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@UUnk_PreloadId@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@UUnk_PreloadId@@@2@XZ 0x141216c20 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@UUnk_PreloadPath@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@UUnk_PreloadPath@@@2@XZ 0x141216c30 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@UUnk_PreloadPath@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@UUnk_PreloadPath@@@2@XZ 0x141216c40 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@2@XZ 0x141216c50 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@2@XZ 0x141216c60 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@2@XZ 0x141216c70 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@2@XZ 0x141216c80 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@UUnk_PreloadId@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@2@XZ 0x141216c90 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@UUnk_PreloadId@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@2@XZ 0x141216ca0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@UUnk_PreloadPath@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@2@XZ 0x141216cb0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@UUnk_PreloadPath@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@2@XZ 0x141216cc0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@XZ 0x141216cd0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@2@XZ 0x141216ce0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@XZ 0x141216cf0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@2@XZ 0x141216d00 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@2@XZ 0x141216d10 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@2@XZ 0x141216d40 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@2@XZ 0x141216d70 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@2@XZ 0x141216da0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAAEAU?$less@UUnk_PreloadId@@@2@XZ 0x141216dd0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEBAAEBU?$less@UUnk_PreloadId@@@2@XZ 0x141216df0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAAEAU?$less@UUnk_PreloadPath@@@2@XZ 0x141216e10 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEBAAEBU?$less@UUnk_PreloadPath@@@2@XZ 0x141216e30 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEBAAEBUUnk_PreloadId@@PEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@@Z 0x141216e50 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEBAAEBUUnk_PreloadPath@@PEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@@Z 0x141216e80 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEBAAEBUUnk_PreloadId@@AEBU3@@Z 0x141216eb0 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEBAAEBUUnk_PreloadPath@@AEBU3@@Z 0x141216ed0 ; unique
// MS2-PIN: ?_Kfn@?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@SAAEBUUnk_PreloadId@@AEBU3@@Z 0x141216ef0 ; unique
// MS2-PIN: ?_Kfn@?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@SAAEBUUnk_PreloadPath@@AEBU3@@Z 0x141216f00 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@XZ 0x141216f10 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@XZ 0x141216f20 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@@Z 0x141216f30 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@@Z 0x141217010 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@SAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@PEAU32@@Z 0x1412170f0 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@SAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@PEAU32@@Z 0x141217120 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@SAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@PEAU32@@Z 0x141217150 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@SAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@PEAU32@@Z 0x141217180 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@XZ 0x1412171b0 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@XZ 0x1412171d0 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@XZ 0x1412171f0 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@XZ 0x141217210 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@@Z 0x141217230 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@@Z 0x141217310 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@IEAAXXZ 0x1412173f0 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@IEAAXXZ 0x141217440 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@_K@Z 0x141217490 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@_K@Z 0x1412174c0 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@2@XZ 0x1412174f0 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@2@XZ 0x141217560 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAAXXZ 0x1412175d0 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAAXXZ 0x141217670 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@2@QEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@_K@Z 0x141217710 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@2@QEAU?$_Tree_node@UUnk_PreloadPath@@PEAX@2@_K@Z 0x141217740 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@UUnk_PreloadId@@PEAX@2@_K@Z 0x141217770 ; unique
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEBA_NXZ 0x1412177d0 ; manual: set<CString>::empty (calls set<CString>::size 0x141217fb0)
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEBA_NXZ 0x141217810 ; unique
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEBA_NXZ 0x141217850 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@2@XZ 0x141217890 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@2@XZ 0x1412178f0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@2@V32@0@Z 0x141217950 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@2@V32@@Z 0x141217a40 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@2@V32@0@Z 0x141217af0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@2@V32@@Z 0x141217be0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@2@AEBUUnk_PreloadId@@@Z 0x141217c90 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@2@AEBUUnk_PreloadPath@@@Z 0x141217d70 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadId@@@std@@@std@@@2@AEBUUnk_PreloadId@@@Z 0x141217e50 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_PreloadPath@@@std@@@std@@@2@AEBUUnk_PreloadPath@@@Z 0x141217eb0 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@UUnk_PreloadId@@PEAX@std@@@2@@Z 0x141217f10 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@UUnk_PreloadPath@@PEAX@std@@@2@@Z 0x141217f20 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141217f30 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141217f50 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEBUUnk_PreloadId@@@std@@SAPEBUUnk_PreloadId@@AEBU3@@Z 0x141217f70 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEBUUnk_PreloadPath@@@std@@SAPEBUUnk_PreloadPath@@AEBU3@@Z 0x141217f90 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEBA_KXZ 0x141217fb0 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@UUnk_PreloadId@@U?$less@UUnk_PreloadId@@@std@@V?$allocator@UUnk_PreloadId@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141217fd0 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@UUnk_PreloadPath@@U?$less@UUnk_PreloadPath@@@std@@V?$allocator@UUnk_PreloadPath@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141217ff0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CFilePreload@@6B?$TSingleton@VCFilePreload@@@@@ 0x142ec2438
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\filepreload.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "filepreload_1.h"
#include "ms2/placeholder/cthread_startup.h"
#include "ms2/commonfiles/timeutil.h"
#include "hook/ms2hook.h"
#include <process.h>
#include "ms2/placeholder/coptimizer.h"
#include "ms2/placeholder/clearningquesttable.h"
#include "ms2/placeholder/cmeratmarketpremium.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include <NiTexture.h>
#include <efd/SmartPointer.h>
CFilePreload* TSingleton<CFilePreload>::s_instance=0;
// Pure constant tables: these do not register with the executable.
static CString s_chartNames[]={"None","Buy","PriceLow","PriceHigh","Create","ChartOrder","BuyTotal","EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
extern bool DAT_1439f7068;
COptimizer* FUN_1409f7c90();
void* FUN_1403ed2d0();
int FUN_141bca2e0(void*);
void FUN_141b6de20();
void FUN_141b6db40(int);
// @0x14120f7c0
CFilePreload::CFilePreload() : stopped(0),preloadIds(0),asynchronous(true),initialized(0),dataReady(1),phase(0),state(0),backgroundThread(0) {
    semaphore=CreateSemaphoreA(0,0,INT_MAX,0);
}
// @0x14120f9d0
CFilePreload::~CFilePreload() {
    FUN_1412102e0();
    if(semaphore) CloseHandle(semaphore);
}
// @0x14120fb80
unsigned CFilePreload::vfunc_1(void* user,Unk_140659080& startup) {
    startup.FUN_1401d42d0();
    while(state!=3) {
        WaitForSingleObject(semaphore,INFINITE);
        if(state==1) {
            { if(Unk_LockGuard guard=stateLock) { __assume(0); } else { state=2; } }
            if(!job.IsNull()) job(user);
            { if(Unk_LockGuard guard=stateLock) { __assume(0); } else {
                if(state==3) return 0;
                state=0;
            } }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14120fb80, CFilePreload, vfunc_1, 312, 0x55CFED34);
// Scheduling entry points remain unhooked: they create local ClassFunHandler RTTI.
// MS2-FUNCTIONAL: Early-out branch shape differs; the same initialization and job are scheduled.
// @0x14120fcc0
void CFilePreload::FUN_14120fcc0() {
    if(!initialized && !state) {
        FUN_141210da0();
        Start(this,0,0,0,0);
        FUN_141210ce0(Job(this,&CFilePreload::FUN_141211240));
    }
}
// MS2-FUNCTIONAL: Early-out branch shape differs; startup parameters and scheduled job are unchanged.
// @0x14120fdb0
void CFilePreload::FUN_14120fdb0() {
    if(!initialized) {
        Start(this,0,0,0,0);
        FUN_141210ce0(Job(this,&CFilePreload::FUN_141211240));
    }
}
// MS2-FUNCTIONAL: Early-out branches differ; all six queues retain the original priority order.
// @0x14120fe80
void CFilePreload::FUN_14120fe80() {
    if(initialized && !state) {
        if(preloadIds!=0 && !ids.empty()) FUN_141210ce0(Job(this,&CFilePreload::FUN_141211380));
        else if(!itemRequests.empty()) FUN_141210ce0(Job(this,&CFilePreload::FUN_141211480));
        else if(!effectRequests.empty()) FUN_141210ce0(Job(this,&CFilePreload::FUN_1412115e0));
        else if(!nifRequests.empty()) FUN_141210ce0(Job(this,&CFilePreload::FUN_141211700));
        else if(!paths.empty()) FUN_141210ce0(Job(this,&CFilePreload::FUN_141211880));
        else if(!itemIds.empty()) FUN_141210ce0(Job(this,&CFilePreload::FUN_1412119e0));
    }
}
// @0x1412102e0
void CFilePreload::FUN_1412102e0() {
    if(stopped==0) {
        stopped=1;
        { if(Unk_LockGuard guard=stateLock) { __assume(0); } else { state=3; } }
        if(backgroundThread!=0) {
            if(WaitForSingleObject(backgroundThread->m_hThread,0)==WAIT_TIMEOUT) {
                TerminateThread(backgroundThread->m_hThread,0);
                CloseHandle(backgroundThread->m_hThread);
            }
            backgroundThread=0;
        }
        if(semaphore) ReleaseSemaphore(semaphore,1,0);
        if(WaitForExit(INFINITE)) job.Clear();
        FUN_1401d2fa0();
    }
}
MS2_REPLACE_METHOD(0x1412102e0, CFilePreload, FUN_1412102e0, 306, 0x14F19F7E);
// @0x141210420
void CFilePreload::FUN_141210420(int ignored) {
    preloadIds=0;
    if(Unk_LockGuard guard=idsLock) { __assume(0); } else { ids.clear(); }
}
MS2_REPLACE_METHOD(0x141210420, CFilePreload, FUN_141210420, 110, 0xC342E578);
// @0x1412104a0
void CFilePreload::FUN_1412104a0(int ignored) { preloadIds=1; }
MS2_REPLACE_METHOD(0x1412104a0, CFilePreload, FUN_1412104a0, 22, 0x6EA4C275);
// @0x1412104c0
void CFilePreload::FUN_1412104c0(unsigned id) {
    if(Unk_LockGuard guard=idsLock) { __assume(0); } else { ids.insert(id); }
}
MS2_REPLACE_METHOD(0x1412104c0, CFilePreload, FUN_1412104c0, 108, 0x3223B7B3);
// @0x141210540
void CFilePreload::FUN_141210540(unsigned id,unsigned short level,int priority) {
    if(id!=0) {
        if(priority==3 && FUN_1409f7c90()->FUN_141215630()==1 && FUN_1403ed2d0()!=0 && FUN_141bca2e0(FUN_1403ed2d0())!=0) return;
        Unk_PreloadId request(id,level,priority);
        if(Unk_LockGuard guard=itemLock) { __assume(0); } else {
            auto found=itemRequests.find(request);
            if(found!=itemRequests.end()) { if(found->priority>priority) (*found).priority=priority; }
            else itemRequests.insert(request);
        }
    }
}
MS2_REPLACE_METHOD(0x141210540, CFilePreload, FUN_141210540, 341, 0xB396B8B5);
// @0x1412106a0
void CFilePreload::FUN_1412106a0(Unk_PreloadKey key,int priority) {
    if(key.first!=0) {
        if(priority==3 && FUN_1409f7c90()->FUN_141215630()==1 && FUN_1403ed2d0()!=0 && FUN_141bca2e0(FUN_1403ed2d0())!=0) return;
        Unk_PreloadId request(key,priority);
        if(Unk_LockGuard guard=itemLock) { __assume(0); } else { itemRequests.insert(request); }
    }
}
MS2_REPLACE_METHOD(0x1412106a0, CFilePreload, FUN_1412106a0, 199, 0x000AA8EB);
// @0x141210770
void CFilePreload::FUN_141210770(unsigned id) {
    if(id==0) return;
    if(Unk_LockGuard guard=itemIdsLock) { __assume(0); } else { itemIds.insert(id); }
}
MS2_REPLACE_METHOD(0x141210770, CFilePreload, FUN_141210770, 117, 0xCCD192E8);
// @0x1412107f0
void CFilePreload::FUN_1412107f0(CString path,int priority) {
    if(!path.IsEmpty()) {
        if(Unk_LockGuard guard=effectLock) { __assume(0); } else {
            Unk_PreloadPath request(path,priority);
            auto found=effectRequests.find(request);
            if(found!=effectRequests.end()) { if(found->priority>priority) (*found).priority=priority; }
            else effectRequests.insert(request);
        }
    }
}
MS2_REPLACE_METHOD(0x1412107f0, CFilePreload, FUN_1412107f0, 361, 0x99CB4735);
// @0x141210960
void CFilePreload::FUN_141210960(CString path,int priority) {
    if(Unk_LockGuard guard=nifLock) { __assume(0); } else {
        Unk_PreloadPath request(path,priority);
        auto found=nifRequests.find(request);
        if(found!=nifRequests.end()) { if(found->priority>priority) (*found).priority=priority; }
        else nifRequests.insert(request);
    }
}
MS2_REPLACE_METHOD(0x141210960, CFilePreload, FUN_141210960, 336, 0x073C4155);
// @0x141210ac0
void CFilePreload::FUN_141210ac0(CString path) {
    if(!path.IsEmpty()) { if(Unk_LockGuard guard=pathLock) { __assume(0); } else { paths.insert(path); } }
}
MS2_REPLACE_METHOD(0x141210ac0, CFilePreload, FUN_141210ac0, 139, 0x4E4DCC81);
// @0x141210b60
int CFilePreload::FUN_141210b60(unsigned id) {
    if(Unk_LockGuard guard=idsLock) { __assume(0); } else { return ids.find(id)!=ids.end(); }
    // Original has no defined return on a failed lock; lock guards always succeed here.

}
MS2_REPLACE_METHOD(0x141210b60, CFilePreload, FUN_141210b60, 174, 0xBD7D11C6);
// @0x141210c20
void CFilePreload::FUN_141210c20() { if(GetThreadId()!=0) WaitForExit(INFINITE); }
MS2_REPLACE_METHOD(0x141210c20, CFilePreload, FUN_141210c20, 43, 0x0152E27A);
// @0x141210c60
int CFilePreload::FUN_141210c60() { return dataReady; }
MS2_REPLACE_METHOD(0x141210c60, CFilePreload, FUN_141210c60, 14, 0x620CA41F);
// @0x141210c80
int CFilePreload::FUN_141210c80() { return phase; }
MS2_REPLACE_METHOD(0x141210c80, CFilePreload, FUN_141210c80, 14, 0x7A15C443);
// @0x141210ca0
void CFilePreload::FUN_141210ca0(bool enabled) { DAT_1439f7068=enabled; }
MS2_REPLACE(0x141210ca0, CFilePreload::FUN_141210ca0, 16, 0xD5595944);
// @0x141210cc0
void CFilePreload::FUN_141210cc0(bool enabled) { asynchronous=enabled; }
MS2_REPLACE_METHOD(0x141210cc0, CFilePreload, FUN_141210cc0, 23, 0x397CC0E5);
// @0x141210ce0
void CFilePreload::FUN_141210ce0(Job next) {
    if(asynchronous) {
        { if(Unk_LockGuard guard=stateLock) { __assume(0); } else { job=next; state=1; } }
        ReleaseSemaphore(semaphore,1,0);
    } else next(this);
}
MS2_REPLACE_METHOD(0x141210ce0, CFilePreload, FUN_141210ce0, 178, 0xE0D783F8);
// @0x141210da0
void CFilePreload::FUN_141210da0() {
    if(asynchronous) backgroundThread=AfxBeginThread(FUN_141211b80,this,0,0,0,0);
    else FUN_141211b80(this);
}
MS2_REPLACE_METHOD(0x141210da0, CFilePreload, FUN_141210da0, 91, 0x9EA0C72E);

// Named, typed external operations. Unknown service classes are forward-only.
class CReactorDataTable; class CNifLoadingService; class SkillDataTableCli; class SkillData;
class Unk_PreloadServiceA; class Unk_PreloadServiceB; class Unk_PreloadServiceC; class Unk_PreloadServiceD;
void FUN_14051f2b0();
CReactorDataTable* FUN_14076dcd0();
void FUN_14076b7d0(CReactorDataTable*);
extern CLearningQuestTable* DAT_143ab0200;
extern CMeratMarketPremium* DAT_143ab0540;
CLearningQuestTable* FUN_140ea4060();
CMeratMarketPremium* FUN_1406f2370();
CLearningQuestTable* FUN_141215480();
CMeratMarketPremium* FUN_141215500();
void FUN_1406a27b0(CMeratMarketPremium*);
void* FUN_1406aeee0();
bool FUN_1406af0a0(void*);
void* FUN_1406d6e90();
void FUN_140a7cbf0(void*);
void FUN_1411a49a0(CString);
CNifLoadingService* FUN_140a0afd0();
void FUN_141551c10(CNifLoadingService*);
Unk_PreloadServiceA* FUN_1407476c0();
void FUN_14074c320(Unk_PreloadServiceA*);
Unk_PreloadServiceB* FUN_140c9b8e0();
void FUN_140c91690(Unk_PreloadServiceB*);
Unk_PreloadServiceC* FUN_14034f780();
void FUN_14034dde0(Unk_PreloadServiceC*);
void FUN_1416e4340(); void FUN_140855540(); void FUN_14093af30(); void FUN_14015c050();
void FUN_14064cc80(CLearningQuestTable*);
void FUN_1410917a0(unsigned);
SkillDataTableCli* FUN_1401958b0();
void FUN_140aae720(SkillDataTableCli*,unsigned,unsigned short,int);
void FUN_1411a4800(const CString&,int);
// Explicit result-storage forms preserve the member hidden-result ABI.
efd::SmartPointer<NiTexture>* FUN_141552f90(CNifLoadingService*,efd::SmartPointer<NiTexture>*,CString,int);
void FUN_1415525d0(CNifLoadingService*,CString,int,int);
Unk_PayloadPtr<SkillData>* FUN_140aafd60(SkillDataTableCli*,Unk_PayloadPtr<SkillData>*,unsigned);
Unk_PreloadServiceD* FUN_1411b1dd0(); void FUN_14119fa60(Unk_PreloadServiceD*);
void* FUN_140281980(); void FUN_140556f50(void*); void FUN_140c909a0(Unk_PreloadServiceB*);
// @0x141210e10
void CFilePreload::FUN_141210e10(bool notify) {
    CStopWatch watch("PreloadDataStep1");
    if(stopped==0) FUN_14051f2b0();
    watch.vfunc_1("CInteractObjectData::ReadAll");
    if(stopped==0) FUN_14076b7d0(FUN_14076dcd0());
    watch.vfunc_1("CReactorDataTable::GetInstance()->Init");
    if(notify) FUN_141211b30(0x40);
    if(stopped==0) FUN_1406a27b0(FUN_141215500());
    watch.vfunc_1("CMeratMarketPremium::CreateInstance()->Init");
    if(notify) FUN_141211b30(0x80);
    phase=1;
}
MS2_REPLACE_METHOD(0x141210e10, CFilePreload, FUN_141210e10, 230, 0x9568662A);
// @0x141210f00
void CFilePreload::FUN_141210f00(bool notify) {
    if(FUN_1406af0a0(FUN_1406aeee0())) {
        CStopWatch watch("PreloadDataStep2");
        if(stopped==0 && DAT_1439f7068) FUN_140a7cbf0(FUN_1406d6e90());
        watch.vfunc_1("CNpcData::ReadAll");
        if(notify) FUN_141211b30(0x100);
        if(stopped==0 && DAT_1439f7068) FUN_1411a49a0(CString("./Data/Xml/Effect/CH/Common"));
        watch.vfunc_1("PreLoadCommonEffect CH/Common");
        if(notify) FUN_141211b30(0x200);
        if(stopped==0 && DAT_1439f7068) FUN_1411a49a0(CString("./Data/Xml/Effect/CH/Emotion"));
        watch.vfunc_1("PreLoadCommonEffect CH/Emotion");
        if(stopped==0 && DAT_1439f7068) FUN_1411a49a0(CString("./Data/Xml/Effect/CH/Music"));
        watch.vfunc_1("PreLoadCommonEffect CH/Music");
        if(notify) FUN_141211b30(0x400);
        if(stopped==0 && DAT_1439f7068) FUN_1411a49a0(CString("./Data/Xml/Effect/NPC/Common"));
        watch.vfunc_1("PreLoadCommonEffect NPC/Common");
        if(stopped==0 && DAT_1439f7068) FUN_1411a49a0(CString("./Data/Xml/Effect/Item/enchant"));
        watch.vfunc_1("PreLoadCommonEffect Item/enchant");
        if(notify) FUN_141211b30(0x800);
        if(stopped==0 && DAT_1439f7068 && FUN_140a0afd0()!=0) FUN_141551c10(FUN_140a0afd0());
        watch.vfunc_1("CNifLoadingService::GetInstance()->PreLoad");
        if(notify) FUN_141211b30(0x1000);
    }
    phase=2;
}
MS2_REPLACE_METHOD(0x141210f00, CFilePreload, FUN_141210f00, 826, 0xAF9D15C6);
// @0x141211240
void CFilePreload::FUN_141211240(void*) {
    dataReady=0;
    if(stopped==0) FUN_14074c320(FUN_1407476c0());
    if(stopped==0) FUN_140c91690(FUN_140c9b8e0());
    FUN_141211b30(2);
    if(stopped==0) FUN_14034dde0(FUN_14034f780());
    if(stopped==0) FUN_1416e4340();
    FUN_141211b30(4);
    if(stopped==0) FUN_140855540();
    if(stopped==0) FUN_14093af30();
    if(stopped==0) FUN_14015c050();
    FUN_141211b30(8);
    if(stopped==0) FUN_14064cc80(FUN_141215480());
    FUN_141211b30(0x10);
    dataReady=1;
    initialized=1;
    FUN_141211b30(0x2000);
    callback.Clear();
}
MS2_REPLACE_METHOD(0x141211240, CFilePreload, FUN_141211240, 307, 0xA3D8BB95);
// @0x141211380
void CFilePreload::FUN_141211380(void*) {
    std::set<unsigned> pending;
    { if(Unk_LockGuard guard=idsLock) { __assume(0); } else { pending=ids; ids.clear(); } }
    for(auto it=pending.begin();it!=pending.end();++it) {
        if(stopped==0) { FUN_1410917a0(*it); }
        else return;
    }
}
MS2_REPLACE_METHOD(0x141211380, CFilePreload, FUN_141211380, 250, 0x321844C5);
// @0x141211480
void CFilePreload::FUN_141211480(void*) {
    std::set<Unk_PreloadId> pending;
    { if(Unk_LockGuard guard=itemLock) { __assume(0); } else { pending=itemRequests; itemRequests.clear(); } }
    for(auto it=pending.begin();it!=pending.end();++it) {
        if(stopped==0) { FUN_140aae720(FUN_1401958b0(),it->key.first,it->key.second,it->priority); }
        else return;
    }
}
MS2_REPLACE_METHOD(0x141211480, CFilePreload, FUN_141211480, 332, 0xE2D2878C);
// @0x1412115e0
void CFilePreload::FUN_1412115e0(void*) {
    std::set<Unk_PreloadPath> pending;
    { if(Unk_LockGuard guard=effectLock) { __assume(0); } else { pending=effectRequests; effectRequests.clear(); } }
    for(auto it=pending.begin();it!=pending.end();++it) {
        if(stopped==0) { FUN_1411a4800(it->path,it->priority); }
        else return;
    }
}
MS2_REPLACE_METHOD(0x1412115e0, CFilePreload, FUN_1412115e0, 274, 0x12FA9D57);
// MS2-FUNCTIONAL: Explicit result storage initializes the texture pointer before the callee writes it; ownership and calls are preserved.
// @0x141211700
void CFilePreload::FUN_141211700(void*) {
    std::set<Unk_PreloadPath> pending;
    { if(Unk_LockGuard guard=nifLock) { __assume(0); } else { pending=nifRequests; nifRequests.clear(); } }
    for(auto it=pending.begin();it!=pending.end();++it) {
        if(stopped!=0 || FUN_140a0afd0()==0) return;
        efd::SmartPointer<NiTexture> texture;
        FUN_141552f90(FUN_140a0afd0(),&texture,CString(it->path),it->priority);
    }
}
MS2_REPLACE_METHOD(0x141211700, CFilePreload, FUN_141211700, 375, 0x74A47ED7);
// MS2-FUNCTIONAL: Early-return block order differs; the same CString and loader flags 0 and 5 are passed.
// @0x141211880
void CFilePreload::FUN_141211880(void*) {
    std::set<CString> pending;
    { if(Unk_LockGuard guard=pathLock) { __assume(0); } else { pending=paths; paths.clear(); } }
    for(auto it=pending.begin();it!=pending.end();++it) {
        if(stopped!=0 || FUN_140a0afd0()==0) return;
        FUN_1415525d0(FUN_140a0afd0(),CString(*it),0,5);
    }
}
MS2_REPLACE_METHOD(0x141211880, CFilePreload, FUN_141211880, 335, 0x0F68167A);
// MS2-FUNCTIONAL: Explicit result storage initializes the shared pointer before lookup; reference release and all guards are preserved.
// @0x1412119e0
void CFilePreload::FUN_1412119e0(void*) {
    std::set<unsigned> pending;
    { if(Unk_LockGuard guard=itemIdsLock) { __assume(0); } else { pending=itemIds; itemIds.clear(); } }
    for(auto it=pending.begin();it!=pending.end();++it) {
        if(stopped!=0 || FUN_140a0afd0()==0) return;
        if(FUN_1401958b0()!=0) {
            Unk_PayloadPtr<SkillData> data;
            FUN_140aafd60(FUN_1401958b0(),&data,*it);
        }
    }
}
MS2_REPLACE_METHOD(0x1412119e0, CFilePreload, FUN_1412119e0, 319, 0xF38A508F);
// @0x141211b30
void CFilePreload::FUN_141211b30(int mask) {
    if(stopped==0 && !callback.IsNull()) callback(mask);
}
MS2_REPLACE_METHOD(0x141211b30, CFilePreload, FUN_141211b30, 74, 0xBA47AD5F);
// @0x141211b80
UINT CFilePreload::FUN_141211b80(void* context) {
    CFilePreload* self=static_cast<CFilePreload*>(context);
    if(self==0) return 0;
    {
        if(self->stopped==0) FUN_14119fa60(FUN_1411b1dd0());
        if(self->stopped==0) {
            self->FUN_141210e10(false);
            FUN_140556f50(FUN_140281980());
            if(self->stopped==0) FUN_140c909a0(FUN_140c9b8e0());
            self->FUN_141210f00(false);
        }
        self->FUN_141211c20();
    }
    return 0;
}
MS2_REPLACE(0x141211b80, CFilePreload::FUN_141211b80, 144, 0x5105728F);
// @0x141211c20
void CFilePreload::FUN_141211c20() { backgroundThread=0; }
MS2_REPLACE_METHOD(0x141211c20, CFilePreload, FUN_141211c20, 22, 0x94B5ABB3);

static unsigned __stdcall PreloadThreadEntry(void* context);
#pragma function(memset)
// @0x141215220
int CThread::Start(void* user,int priority,int suspended,unsigned stackSize,LPSECURITY_ATTRIBUTES attributes) {
    Unk_140659080 startup;
    memset(&startup,0,sizeof(startup));
    startup.owner=this;
    startup.user=user;
    startup.flags=suspended ? CREATE_SUSPENDED : 0;
    startup.ready=CreateEventA(0,TRUE,FALSE,0);
    startup.resume=CreateEventA(0,TRUE,FALSE,0);
    startup.error=0;
    if(startup.ready==0 || startup.resume==0) {
        DWORD error=GetLastError();
        if(startup.ready) CloseHandle(startup.ready);
        if(startup.resume) CloseHandle(startup.resume);
        SetLastError(error);
        return 0;
    }
    unsigned id=0;
    m_thread=reinterpret_cast<HANDLE>(_beginthreadex(attributes,stackSize,PreloadThreadEntry,&startup,startup.flags|CREATE_SUSPENDED,&id));
    if(m_thread==0) {
        DWORD error=GetLastError();
        CloseHandle(startup.ready);
        CloseHandle(startup.resume);
        SetLastError(error);
        return 0;
    }
    m_threadId=id;
    if(priority!=0) SetThreadPriority(m_thread,priority);
    ResumeThread(m_thread);
    WaitForSingleObject(startup.ready,INFINITE);
    CloseHandle(startup.ready);
    if(startup.error!=0) {
        CloseHandle(m_thread);
        m_thread=0;
        m_threadId=0;
        SetLastError(startup.error);
        return 0;
    }
    if((startup.flags&CREATE_SUSPENDED)!=0) SuspendThread(m_thread);
    SetEvent(startup.resume);
    return 1;
}
MS2_REPLACE_METHOD(0x141215220, CThread, Start, 594, 0x0FE72BCD);
// Unhooked: these allocate using executable constructors and expose singletons.
// @0x141215480
CLearningQuestTable* FUN_141215480() {
    return DAT_143ab0200!=0 ? FUN_140ea4060() : new CLearningQuestTable;
}
// @0x141215500
CMeratMarketPremium* FUN_141215500() {
    return DAT_143ab0540!=0 ? FUN_1406f2370() : new CMeratMarketPremium;
}
// @0x141215630
int COptimizer::FUN_141215630() const { return preloadMode; }
// @0x141215640
DWORD CThread::GetThreadId() const { return m_threadId; }
// @0x141215aa0
static unsigned __stdcall PreloadThreadEntry(void* context) {
    Unk_140659080* startup=static_cast<Unk_140659080*>(context);
    FUN_141b6de20();
    try {
        SetThreadLocale(0x412);
        startup->owner->vfunc_1(startup->user,*startup);
    } catch(std::bad_alloc& error) {
        error.what();
        FUN_141b6db40(0);
    }
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cad780-0x142cad840 .text$yd
