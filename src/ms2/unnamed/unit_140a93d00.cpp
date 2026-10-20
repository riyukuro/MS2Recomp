// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Razer Chroma keyboard/mouse lighting of
// client\ms2\razerchroma (the ChromaSDK effect classes, ChromaLinkEffect, ChromaManagerImpl and ChromaManagerDummy) and
// their std::vector / std::map / std::set template glue. The exe range holds several original objs in a row (one per
// effect class, the manager, the dummy); this file keeps them in exe order. Class names from RTTI, the rest invented
// (see unit_140a93d00.h). Bodies cross-checked with the third-party v2525 snapshot and the Razer ChromaSDKPlugin code.
// MS2-UNIT: unit_140a93d00
// MS2-RANGE: 0x1400c4e10-0x1400c5120 .text$di
// MS2-RANGE: 0x140a93d00-0x140aaadb0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GChromaEffectDClear@ChromaSDK@@UEAAPEAXI@Z 0x140a95e30 ; prop
// MS2-PIN: ??_GChromaEffectDeath@ChromaSDK@@UEAAPEAXI@Z 0x140a962b0 ; prop
// MS2-PIN: ??_GChromaEffectLoading@ChromaSDK@@UEAAPEAXI@Z 0x140a96980 ; prop
// MS2-PIN: ??_GChromaEffectLogo@ChromaSDK@@UEAAPEAXI@Z 0x140a96c90 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBI_K@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBI_K@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140a97af0 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140a97b20 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140a97b50 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBI_K@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBI_K@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140a97ba0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@?$_Tree_node@IPEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@PEAU01@@Z 0x140a97c80 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@IPEAX@std@@@std@@YAPEAPEAU?$_Tree_node@IPEAX@0@AEAPEAU10@@Z 0x140a97d20 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@I@std@@@0@AEAV10@@Z 0x140a97d50 ; prop
// MS2-PIN: ??$addressof@I@std@@YAPEAIAEAI@Z 0x140a97d60 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@IPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@QEAPEAU?$_Tree_node@IPEAX@1@AEAPEAU31@@Z 0x140a97dc0 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@IPEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@QEAPEAU?$_Tree_node@IPEAX@1@@Z 0x140a97e20 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@IPEAX@std@@@std@@YAAEAPEAU?$_Tree_node@IPEAX@0@AEAPEAU10@@Z 0x140a97e60 ; prop
// MS2-PIN: ??$forward@AEBU?$less@I@std@@@std@@YAAEBU?$less@I@0@AEBU10@@Z 0x140a97e70 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x140a97f20 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@IPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@1@@Z 0x140a97fa0 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@IPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@1@@Z 0x140a98060 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBI_K@std@@@std@@@std@@QEAA@XZ 0x140a980a0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAA@XZ 0x140a980d0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBI_K@std@@PEAX@std@@@std@@QEAA@XZ 0x140a98100 ; prop
// MS2-PIN: ??0?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@QEAA@XZ 0x140a98150 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA@XZ 0x140a98230 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140a982e0 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140a98360 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEAA?AV01@H@Z 0x140a98410 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEAAAEAV01@XZ 0x140a98460 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140a98510 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@IPEAX@2@XZ 0x140a98850 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXXZ 0x140a98940 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x140a98a10 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAAPEAU?$_Tree_node@IPEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@@Z 0x140a99060 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x140a99640 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x140a996a0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@2@XZ 0x140a996e0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@XZ 0x140a996f0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x140a99720 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@2@XZ 0x140a99760 ; prop
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEBAAEAPEAU?$_Tree_node@IPEAX@2@XZ 0x140a997a0 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x140a99890 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@SAPEAU?$_Tree_node@IPEAX@2@PEAU32@@Z 0x140a999a0 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@SAPEAU?$_Tree_node@IPEAX@2@PEAU32@@Z 0x140a99a00 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEBAAEAPEAU?$_Tree_node@IPEAX@2@XZ 0x140a99a50 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEBAAEAPEAU?$_Tree_node@IPEAX@2@XZ 0x140a99a90 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x140a99b90 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEAAXXZ 0x140a99cd0 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@IPEAX@std@@@std@@QEAAPEAU?$_Tree_node@IPEAX@2@_K@Z 0x140a99d50 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@XZ 0x140a99df0 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXXZ 0x140a99f00 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@2@QEAU?$_Tree_node@IPEAX@2@_K@Z 0x140a99fd0 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@IPEAX@std@@@std@@QEAAXQEAU?$_Tree_node@IPEAX@2@_K@Z 0x140a9a030 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@XZ 0x140a9a0c0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@V32@0@Z 0x140a9a2c0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@V32@@Z 0x140a9a3b0 ; unique
// MS2-PIN: ??_GChromaEffectResurrection@ChromaSDK@@UEAAPEAXI@Z 0x140a9a890 ; prop
// MS2-PIN: ?SetReturnState@ChromaEffectRipple@ChromaSDK@@QEAAXH@Z 0x140a9acf0 ; unique
// MS2-PIN: ??_GChromaEffectRipple@ChromaSDK@@UEAAPEAXI@Z 0x140a9ada0 ; prop
// MS2-PIN: ??_GChromaEffectSurviveWinner@ChromaSDK@@UEAAPEAXI@Z 0x140a9b040 ; prop
// MS2-PIN: ??_GChromaEffectTalking@ChromaSDK@@UEAAPEAXI@Z 0x140a9b3d0 ; prop
// MS2-PIN: ??$?0$$QEAH$$Z$$V@?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAH@1@V?$tuple@$$V@1@@Z 0x140aa07f0 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@K@std@@V?$_Vector_val@U?$_Simple_types@K@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140aa0840 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140aa08a0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140aa0950 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140aa09f0 ; unique
// MS2-PIN: ??$?0U_Exact_args_t@std@@H$$V$0A@@?$tuple@$$QEAH@std@@QEAA@U_Exact_args_t@1@$$QEAH@Z 0x140aa0bd0 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140aa0c80 ; prop
// MS2-PIN: ??$?0V?$tuple@$$QEAH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@QEAA@AEAV?$tuple@$$QEAH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140aa0e20 ; unique
// MS2-PIN: ??$?0H$$V$0A@@?$tuple@$$QEAH@std@@QEAA@$$QEAH@Z 0x140aa0f50 ; unique
// MS2-PIN: ??$?0H@?$_Tuple_val@$$QEAH@std@@QEAA@$$QEAH@Z 0x140aa0fb0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@1@@Z 0x140aa1000 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x140aa10f0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBK@?$vector@KV?$allocator@K@std@@@std@@AEAAXAEBK@Z 0x140aa1480 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBK@?$vector@KV?$allocator@K@std@@@std@@QEAAPEAKQEAKAEBK@Z 0x140aa1600 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@1@AEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@1@1@Z 0x140aa2010 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@1@PEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@1@@Z 0x140aa2fb0 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@1@PEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@1@@Z 0x140aa4000 ; unique
// MS2-PIN: ??$_Kfn@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@SAAEBHAEBU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@1@@Z 0x140aa4420 ; prop
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@1@AEBH@Z 0x140aa44d0 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@KK@std@@YA?AU_Really_trivial_ptr_iterator_tag@0@AEBQEAK0@Z 0x140aa4570 ; prop
// MS2-PIN: ??$_Ptr_move_cat@KK@std@@YA?AU_Really_trivial_ptr_iterator_tag@0@AEBQEAK0@Z 0x140aa4590 ; prop
// MS2-PIN: ??$_Try_emplace@H$$V@?$map@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@_N@1@$$QEAH@Z 0x140aa48c0 ; unique
// MS2-PIN: ??$_Ucopy@PEAK@?$vector@KV?$allocator@K@std@@@std@@AEAAPEAKPEAK00@Z 0x140aa4a10 ; prop
// MS2-PIN: ??$_Unfancy@K@std@@YAPEAKPEAK@Z 0x140aa4a50 ; prop
// MS2-PIN: ??$_Uninitialized_copy@PEAKPEAKV?$allocator@K@std@@@std@@YAPEAKQEAK0PEAKAEAV?$allocator@K@0@@Z 0x140aa4a70 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAKPEAKV?$allocator@K@std@@@std@@YAPEAKQEAK0PEAKAEAV?$allocator@K@0@@Z 0x140aa4b60 ; prop
// MS2-PIN: ??$construct@KAEBK@?$_Default_allocator_traits@V?$allocator@K@std@@@std@@SAXAEAV?$allocator@K@1@QEAKAEBK@Z 0x140aa4e20 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x140aa5060 ; unique
// MS2-PIN: ??$emplace_back@AEBK@?$vector@KV?$allocator@K@std@@@std@@QEAAXAEBK@Z 0x140aa5210 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x140aa5390 ; unique
// MS2-PIN: ??$forward@$$QEAH@std@@YA$$QEAHAEAH@Z 0x140aa54e0 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@YAAEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@0@AEAU10@@Z 0x140aa5520 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140aa5540 ; prop
// MS2-PIN: ??$forward@AEBK@std@@YAAEBKAEBK@Z 0x140aa5550 ; prop
// MS2-PIN: ??$forward@AEBU?$less@H@std@@@std@@YAAEBU?$less@H@0@AEBU10@@Z 0x140aa5570 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140aa55c0 ; prop
// MS2-PIN: ??$forward@V?$tuple@$$QEAH@std@@@std@@YA$$QEAV?$tuple@$$QEAH@0@AEAV10@@Z 0x140aa5600 ; prop
// MS2-PIN: ??$forward@H@std@@YA$$QEAHAEAH@Z 0x140aa5630 ; prop
// MS2-PIN: ??$forward_as_tuple@H@std@@YA?AV?$tuple@$$QEAH@0@$$QEAH@Z 0x140aa56a0 ; unique
// MS2-PIN: ??$get@$0A@$$QEAH@std@@YA$$QEAH$$QEAV?$tuple@$$QEAH@0@@Z 0x140aa56f0 ; unique
// MS2-PIN: ??$move@AEAV?$allocator@K@std@@@std@@YA$$QEAV?$allocator@K@0@AEAV10@@Z 0x140aa5740 ; prop
// MS2-PIN: ??$move@AEAV?$tuple@$$QEAH@std@@@std@@YA$$QEAV?$tuple@$$QEAH@0@AEAV10@@Z 0x140aa5770 ; prop
// MS2-PIN: ??$move@AEAV?$vector@KV?$allocator@K@std@@@std@@@std@@YA$$QEAV?$vector@KV?$allocator@K@std@@@0@AEAV10@@Z 0x140aa5790 ; prop
// MS2-PIN: ??$move@AEAH@std@@YA$$QEAHAEAH@Z 0x140aa57c0 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@_N@1@$$QEAH@Z 0x140aa5850 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@QEAA@XZ 0x140aa5ba0 ; prop
// MS2-PIN: ??0?$allocator@K@std@@QEAA@XZ 0x140aa5cf0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@std@@@std@@QEAA@XZ 0x140aa5d10 ; prop
// MS2-PIN: ??0?$tuple@$$QEAH@std@@QEAA@$$QEAV01@@Z 0x140aa5dd0 ; unique
// MS2-PIN: ??0?$vector@KV?$allocator@K@std@@@std@@QEAA@$$QEAV01@@Z 0x140aa5e50 ; unique
// MS2-PIN: ??0?$vector@KV?$allocator@K@std@@@std@@QEAA@AEBV01@@Z 0x140aa5ed0 ; unique
// MS2-PIN: ??A?$map@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@@std@@QEAAAEAW4RZKEY@Keyboard@ChromaSDK@@$$QEAH@Z 0x140aa6590 ; unique
// MS2-PIN: ??A?$vector@KV?$allocator@K@std@@@std@@QEAAAEAK_K@Z 0x140aa65d0 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@1@XZ 0x140aa66b0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140aa6aa0 ; unique
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x140aa6bb0 ; unique
// MS2-PIN: ?GetState@ChromaManagerImpl@ChromaSDK@@UEAAHXZ 0x140aa6d20 ; unique
// MS2-PIN: ?_Buy@?$vector@KV?$allocator@K@std@@@std@@AEAA_N_K@Z 0x140aa6f40 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@2@XZ 0x140aa7290 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@KV?$allocator@K@std@@@std@@AEBA_K_K@Z 0x140aa7370 ; unique
// MS2-PIN: ?_Change_array@?$vector@KV?$allocator@K@std@@@std@@AEAAXQEAK_K1@Z 0x140aa7490 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x140aa76f0 ; unique
// MS2-PIN: ?_Destroy@?$vector@KV?$allocator@K@std@@@std@@AEAAXPEAK0@Z 0x140aa7790 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@2@@Z 0x140aa7860 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@K@std@@@2@XZ 0x140aa86d0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x140aa8770 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x140aa8780 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@K@std@@V?$_Vector_val@U?$_Simple_types@K@std@@@2@$00@std@@QEAAAEAV?$allocator@K@2@XZ 0x140aa8790 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@K@std@@V?$_Vector_val@U?$_Simple_types@K@std@@@2@$00@std@@QEBAAEBV?$allocator@K@2@XZ 0x140aa87a0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@K@std@@V?$_Vector_val@U?$_Simple_types@K@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@K@std@@@2@XZ 0x140aa8850 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEAAAEAV?$allocator@K@2@XZ 0x140aa8990 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEBAAEBV?$allocator@K@2@XZ 0x140aa89b0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x140aa8a50 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x140aa8a70 ; prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@KV?$allocator@K@std@@@std@@AEBA_NXZ 0x140aa8a90 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@2@@Z 0x140aa8b60 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@2@@Z 0x140aa8bb0 ; unique
// MS2-PIN: ?_Move_from@?$vector@KV?$allocator@K@std@@@std@@AEAAX$$QEAV12@U?$integral_constant@_N$00@2@@Z 0x140aa8e70 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEAAAEAPEAKXZ 0x140aa9030 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEBAAEBQEAKXZ 0x140aa9050 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEAAAEAPEAKXZ 0x140aa90b0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEAAAEAPEAKXZ 0x140aa9130 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEBAAEBQEAKXZ 0x140aa9150 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEAAXXZ 0x140aa91b0 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@KV?$allocator@K@std@@@std@@AEBAXPEAK0@Z 0x140aa91f0 ; unique
// MS2-PIN: ?_Swap_all@?$_Vector_alloc@U?$_Vec_base_types@KV?$allocator@K@std@@@std@@@std@@QEAAXAEAV12@@Z 0x140aa9470 ; unique
// MS2-PIN: ?_Tidy@?$vector@KV?$allocator@K@std@@@std@@AEAAXXZ 0x140aa95b0 ; unique
// MS2-PIN: ?_Umove@?$vector@KV?$allocator@K@std@@@std@@AEAAPEAKPEAK00@Z 0x140aa9750 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@KV?$allocator@K@std@@@std@@AEAAXPEAK00U?$integral_constant@_N$00@2@@Z 0x140aa97d0 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@KV?$allocator@K@std@@@std@@AEAAXPEAK00@Z 0x140aa9850 ; unique
// MS2-PIN: ?allocate@?$allocator@K@std@@QEAAPEAK_K@Z 0x140aa9950 ; prop
// MS2-PIN: ?capacity@?$vector@KV?$allocator@K@std@@@std@@QEBA_KXZ 0x140aa9af0 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@2@AEBH@Z 0x140aaa1e0 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@@std@@@2@AEBH@Z 0x140aaa320 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@PEAX@std@@@2@@Z 0x140aaa3a0 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@QEBA_KXZ 0x140aaa3e0 ; prop
// MS2-PIN: ?max_size@?$vector@KV?$allocator@K@std@@@std@@QEBA_KXZ 0x140aaa400 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@std@@SAPEAU?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@2@AEAU32@@Z 0x140aaa4c0 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HW4RZKEY@Keyboard@ChromaSDK@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHW4RZKEY@Keyboard@ChromaSDK@@@std@@@5@$0A@@std@@@std@@QEBA_KXZ 0x140aaa570 ; unique
// MS2-PIN: ?size@?$vector@KV?$allocator@K@std@@@std@@QEBA_KXZ 0x140aaa590 ; prop
// MS2-PIN: ??_GChromaManagerDummy@ChromaSDK@@UEAAPEAXI@Z 0x140aaa8c0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?Finalize@ChromaManagerDummy@ChromaSDK@@UEAAXXZ 0x140aaa8b0
// MS2-PIN: ?GetKeyboardKey@ChromaManagerDummy@ChromaSDK@@UEAAHH@Z 0x140aaaac0
// MS2-PIN: ?DeleteReservedEffects@ChromaManagerDummy@ChromaSDK@@UEAAXXZ 0x140aaaa80
// MS2-PIN: ?ReserveDeleteEffect@ChromaManagerDummy@ChromaSDK@@UEAAXU_GUID@@@Z 0x140aaab10
// MS2-PIN: ?OnKeyName@ChromaManagerDummy@ChromaSDK@@UEAAXAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x140aaa900
// MS2-PIN: ?OnKeySkill@ChromaManagerDummy@ChromaSDK@@UEAAXH_N@Z 0x140aaa910
// MS2-PIN: ?ResetKeys@ChromaManagerDummy@ChromaSDK@@UEAAX_N@Z 0x140aaaa30
// MS2-PIN: ?RefreshKeys@ChromaManagerDummy@ChromaSDK@@UEAAXXZ 0x140aaab00
// MS2-PIN: ?SetState@ChromaManagerDummy@ChromaSDK@@UEAAXH@Z 0x140aaa920
// MS2-PIN: ?GetState@ChromaManagerDummy@ChromaSDK@@UEAAHXZ 0x140aaaab0
// MS2-PIN: ?Pause@ChromaManagerDummy@ChromaSDK@@UEAAXXZ 0x140aaaae0
// MS2-PIN: ?Resume@ChromaManagerDummy@ChromaSDK@@UEAAXXZ 0x140aaab30
// MS2-PIN: ?SetColorMode@ChromaManagerDummy@ChromaSDK@@UEAAXH@Z 0x140aaaaf0
// MS2-PIN: ?GetColor@ChromaManagerDummy@ChromaSDK@@UEAAKH@Z 0x140aaaad0
// MS2-PIN: ?SetCooldown@ChromaManagerDummy@ChromaSDK@@UEAAXHH_JM@Z 0x140aaaa50
// MS2-PIN: ?ResetCooldown@ChromaManagerDummy@ChromaSDK@@UEAAXH@Z 0x140aaaa40
// MS2-PIN: ?CreateEffect@ChromaManagerDummy@ChromaSDK@@UEAAJU_GUID@@W4EFFECT_TYPE@2@PEAXPEAU3@@Z 0x140aaa950
// MS2-PIN: ?CreateChromaLinkEffect@ChromaManagerDummy@ChromaSDK@@UEAAJHPEAXPEAU_GUID@@@Z 0x140aaa930
// MS2-PIN: ?CreateHeadsetEffect@ChromaManagerDummy@ChromaSDK@@UEAAJHPEAXPEAU_GUID@@@Z 0x140aaa970
// MS2-PIN: ?CreateKeyboardEffect@ChromaManagerDummy@ChromaSDK@@UEAAJHPEAXPEAU_GUID@@@Z 0x140aaa990
// MS2-PIN: ?CreateKeypadEffect@ChromaManagerDummy@ChromaSDK@@UEAAJHPEAXPEAU_GUID@@@Z 0x140aaa9b0
// MS2-PIN: ?CreateMouseEffect@ChromaManagerDummy@ChromaSDK@@UEAAJHPEAXPEAU_GUID@@@Z 0x140aaa9d0
// MS2-PIN: ?CreateMousepadEffect@ChromaManagerDummy@ChromaSDK@@UEAAJHPEAXPEAU_GUID@@@Z 0x140aaa9f0
// MS2-PIN: ?SetEffect@ChromaManagerDummy@ChromaSDK@@UEAAJU_GUID@@@Z 0x140aaaa20
// MS2-PIN: ?DeleteEffect@ChromaManagerDummy@ChromaSDK@@UEAAJU_GUID@@@Z 0x140aaaa10
// MS2-PIN: ?PlayEffect@ChromaManagerDummy@ChromaSDK@@UEAAJU_GUID@@@Z 0x140aaab20
// MS2-PIN: ?RemoveEffect@ChromaManagerDummy@ChromaSDK@@UEAAJU_GUID@@@Z 0x140aaaa70
// MS2-PIN:  0x
// MS2-PIN: tools/progress.py 0x:46
// MS2-PIN: ??_7ChromaManagerImpl@ChromaSDK@@6BIChromaManager@1@@ 0x142dcfa20
// MS2-PIN: memcpy_s 0x140aaab40
// MS2-PIN: memmove_s 0x140aaac90
#define MS2_THIS_FILE ""
// The exe's memcpy_s is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#include <vcruntime_string.h>
#pragma function(memset, memcpy)
#include <corecrt_memcpy_s.h>
#pragma intrinsic(memset, memcpy)
#include "ms2/placeholder/ms2stdafx.h"
#include <process.h>
#include <math.h>
#include <algorithm>
#include <cguid.h>

#include "unit_140a93d00.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/uiservice.h"
#include <egf/Entity.h>
#include "ms2/client/ms2/statemanager.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Header-defined statics of the first obj (the ChromaEffectBase one also defines the dummy service instance).
#include "ms2/placeholder/header_statics_a.h"

unsigned FUN_140869420();                                   // the raw timer tick (ms)
int FUN_14028d260(float fSecond);                           // seconds -> ticks

#define GetCurrentTick() FUN_140869420()

// assert() of the inline Cooldown members in chromaeffectplaying.h
#define CHROMA_ASSERT_H(line, expression)                                                                         \
    (void)((!!(expression)) ||                                                                                  \
           (_wassert(_CRT_WIDE(#expression),                                                                    \
                     L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\razerchroma\\chromaeffectplaying.h",            \
                     (unsigned)(line)), 0))

namespace ChromaSDK {

ChromaManagerDummy g_chromaManagerDummy;                    // 0x143ab89f8

// static_cast helper of the effects (instances IChromaManager -> ChromaManagerImpl, ChromaEffectBase -> Character)
template <class T, class U> T* chroma_cast(U* p)
{
    return static_cast<T*>(p);
}

// ================================================================================================================
// ChromaEffectBase

// @0x140a93d00
ChromaEffectBase::ChromaEffectBase()
{
    m_dwNextTick = 0;
}

// @0x140a93d50
ChromaEffectBase::~ChromaEffectBase()
{
    Clear();
}

// @0x140a93da0
void ChromaEffectBase::Update()
{
    DWORD dwNow = GetCurrentTick();
    if (dwNow >= m_dwNextTick)
    {
        Play();
        m_dwNextTick = dwNow + GetInterval();
    }
}

// @0x140a93e00
void ChromaEffectBase::OnEnter(int nPrevState)
{
    m_dwNextTick = 0;
}

// @0x140a93e20
void ChromaEffectBase::Clear()
{
    for (std::vector<RZEFFECTID>::iterator it = m_effects.begin(); it != m_effects.end(); ++it)
        GetChromaManager()->DeleteEffect(*it);
    m_effects.clear();
}

// @0x140a93ee0
void ChromaEffectBase::Play()
{
    if (m_effects.empty())
        Create();
    if (m_effects.empty())
        return;
    if (m_effects.size() <= m_nFrame)
        m_nFrame = 0;
    GetChromaManager()->SetEffect(m_effects[m_nFrame++]);
}

// @0x140a94360
DWORD ChromaEffectBase::GetInterval()
{
    return 100;
}

// ================================================================================================================
// ChromaEffectCharacter

// @0x140a94850
ChromaEffectCharacter::ChromaEffectCharacter()
{
    m_nFrame = 0;
    m_color = 0;
}

// @0x140a948a0
ChromaEffectCharacter::~ChromaEffectCharacter()
{
}

// @0x140a948d0
void ChromaEffectCharacter::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    Clear();
    Keyboard::STATIC_EFFECT_TYPE keyboard = {};
    m_color = pImpl->GetColor(1);
    keyboard.Color = m_color;
    RZEFFECTID effectId;
    if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_STATIC, &keyboard, &effectId) == 0)
        m_effects.push_back(effectId);
    Mouse::STATIC_EFFECT_TYPE mouse = {};
    mouse.Color = m_color;
    mouse.LEDId = Mouse::RZLED_ALL;
    if (pImpl->CreateMouseEffect(Mouse::CHROMA_STATIC, &mouse, &effectId) == 0)
        m_effects.push_back(effectId);
    Headset::STATIC_EFFECT_TYPE headset = {};
    headset.Color = m_color;
    if (pImpl->CreateHeadsetEffect(Headset::CHROMA_STATIC, &headset, &effectId) == 0)
        m_effects.push_back(effectId);
    Mousepad::STATIC_EFFECT_TYPE mousepad = {};
    mousepad.Color = m_color;
    if (pImpl->CreateMousepadEffect(Mousepad::CHROMA_STATIC, &mousepad, &effectId) == 0)
        m_effects.push_back(effectId);
}

// @0x140a94b30
void ChromaEffectCharacter::Play()
{
    if (m_color != GetChromaManager()->GetColor(1) || m_effects.empty())
        Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// @0x140a94c00
void ChromaEffectCharacter::UpdateMouse()
{
    if (m_effects.empty())
        return;
    for (std::vector<RZEFFECTID>::iterator it = m_effects.begin() + 1; it != m_effects.end(); ++it)
        GetChromaManager()->SetEffect(*it);
}

// @0x140a95420
DWORD ChromaEffectCharacter::GetInterval()
{
    return 200;
}

// ================================================================================================================
// ChromaEffectCinematic

// @0x140a95830
ChromaEffectCinematic::ChromaEffectCinematic()
{
    m_nFrame = 0;
}

// @0x140a95870
ChromaEffectCinematic::~ChromaEffectCinematic()
{
}

// @0x140a958a0
void ChromaEffectCinematic::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    Clear();
    Keyboard::CUSTOM_KEY_EFFECT_TYPE effect = {};
    int nKey = pImpl->GetKeyboardKey(1);
    if (nKey != -1)
    {
        effect.Key[HIBYTE(nKey)][LOBYTE(nKey)] = pImpl->GetColor(1) | 0x01000000;
        RZEFFECTID effectId;
        if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &effect, &effectId) == 0)
            m_effects.push_back(effectId);
    }
}

// @0x140a95a40
DWORD ChromaEffectCinematic::GetInterval()
{
    return 200;
}

// ================================================================================================================
// ChromaEffectDClear

// @0x140a95a50
ChromaEffectDClear::ChromaEffectDClear()
{
    m_nFrame = 0;
    m_nRepeat = 0;
    m_nCenter = 10;
}

// @0x140a95ab0
ChromaEffectDClear::~ChromaEffectDClear()
{
}

// @0x140a95ae0
void ChromaEffectDClear::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
    m_nRepeat = 5;
}

// @0x140a95b20
void ChromaEffectDClear::Create()
{
    Clear();
    IChromaManager* pManager = GetChromaManager();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    int nRadius = m_nFrame - 2;
    int nCount = 0;
    for (int row = 0; row < Keyboard::MAX_ROW; row++)
    {
        for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
        {
            int nDistance = (int)sqrt(pow((float)row - (float)HIBYTE(m_nCenter), 2) + pow((float)col - (float)LOBYTE(m_nCenter), 2));
            if (nRadius <= nDistance)
            {
                effect.Color[row][col] = pManager->GetColor(12);
                nCount++;
            }
            else
            {
                effect.Color[row][col] = pManager->GetColor(13);
            }
        }
    }
    RZEFFECTID effectId;
    if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
    {
        m_effects.push_back(effectId);
        m_nFrame++;
    }
    if (nCount == 0)
    {
        if (--m_nRepeat <= 0)
            pManager->SetState(STATE_PLAYING);
        m_nFrame = 0;
    }
}

// @0x140a95da0
void ChromaEffectDClear::Play()
{
    Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// ================================================================================================================
// ChromaEffectDeath

// @0x140a95e70
ChromaEffectDeath::ChromaEffectDeath()
{
    m_nFrame = 0;
    m_n34 = -1;
    m_n38 = 0;
}

// @0x140a95ed0
ChromaEffectDeath::~ChromaEffectDeath()
{
}

// @0x140a95f00
void ChromaEffectDeath::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
}

// @0x140a95f40
void ChromaEffectDeath::Create()
{
    Clear();
    IChromaManager* pManager = GetChromaManager();
    COLORREF inner = pManager->GetColor(8);
    COLORREF outer = pManager->GetColor(0);
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    int nRadius = 0;
    m_nCenter = 0x409;
    int nLeft = LOBYTE(m_nCenter);
    int nRight = 22 - LOBYTE(m_nCenter) - 1;
    nRadius = (std::max)(nRight, nLeft) - m_nFrame;
    RZEFFECTID effectId;
    if (nRadius <= 0)
    {
        if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_NONE, NULL, &effectId) == 0)
        {
            m_effects.push_back(effectId);
            m_nFrame = 0xffffffff;
        }
    }
    else
    {
        for (int row = 0; row < Keyboard::MAX_ROW; row++)
        {
            for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
            {
                if (nRadius <= (int)sqrt(pow((float)row - (float)HIBYTE(m_nCenter), 2) + pow((float)col - (float)LOBYTE(m_nCenter), 2)))
                    effect.Color[row][col] = outer;
                else
                    effect.Color[row][col] = inner;
            }
        }
        if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
        {
            m_effects.push_back(effectId);
            m_nFrame++;
        }
    }
}

// @0x140a96210
void ChromaEffectDeath::Play()
{
    if (m_nFrame != 0xffffffff)
        Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// ================================================================================================================
// ChromaEffectLoading

// @0x140a962f0
ChromaEffectLoading::ChromaEffectLoading()
{
    m_nFrame = 0;
}

// @0x140a96330
ChromaEffectLoading::~ChromaEffectLoading()
{
}

// @0x140a96360
void ChromaEffectLoading::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    Clear();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    if (m_nFrame > 0xfffffff)
        m_nFrame = 0;
    m_nPattern = 0;
    switch (pImpl->GetColorMode())
    {
    case 30:
    case 40:
        m_nPattern = 1;
        break;
    case 50:
        m_nPattern = 2;
        break;
    case 60:
        m_nPattern = 3;
        break;
    case 70:
    case 80:
        m_nPattern = 6;
        break;
    case 90:
        m_nPattern = 4;
        break;
    case 100:
    case 110:
        m_nPattern = 5;
        break;
    default:
        m_nPattern = 0;
        break;
    }
    for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
    {
        for (int row = 0; row < Keyboard::MAX_ROW; row++)
            effect.Color[row][col] = GetPatternColor(col, row, pImpl->GetColor(1), pImpl->GetColor(2));
    }
    RZEFFECTID effectId;
    if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
    {
        m_effects.push_back(effectId);
        m_nFrame++;
    }
}

// @0x140a96680
void ChromaEffectLoading::Play()
{
    Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// @0x140a96710
DWORD ChromaEffectLoading::GetInterval()
{
    if (m_nPattern == 5 || m_nPattern == 1)
        return 200;
    return 50;
}

// @0x140a96740
COLORREF ChromaEffectLoading::GetPatternColor(int x, int y, COLORREF back, COLORREF fore)
{
    int nCol = m_nFrame % Keyboard::MAX_COLUMN;
    int nRow = m_nFrame % Keyboard::MAX_ROW;
    if (m_nPattern == 0)
    {
        if (nCol == x || nCol == x + 1 || nCol == x - 1)
            return fore;
    }
    else if (m_nPattern == 1)
    {
        if (nRow == y)
            return fore;
    }
    else if (m_nPattern == 4)
    {
        nCol = 22 - nCol - 1;
        if (nCol == x || nCol == x + 1 || nCol == x - 1)
            return fore;
    }
    else if (m_nPattern == 5)
    {
        if (6 - nRow - 1 == y)
            return fore;
    }
    else if (m_nPattern == 6)
    {
        nCol = nCol % (Keyboard::MAX_COLUMN / 2);
        if (nCol + 11 == x || 11 - nCol - 1 == x)
            return fore;
    }
    else if (m_nPattern == 2)
    {
        nCol = m_nFrame % (Keyboard::MAX_COLUMN + Keyboard::MAX_ROW);
        if (x + y == nCol || x + y + 1 == nCol || x + y - 1 == nCol)
            return fore;
    }
    else if (m_nPattern == 3)
    {
        nCol = Keyboard::MAX_COLUMN - m_nFrame % (Keyboard::MAX_COLUMN + Keyboard::MAX_ROW) - 1;
        if (x - y == nCol || x - y - 1 == nCol || x - y + 1 == nCol)
            return fore;
    }
    return back;
}

// ================================================================================================================
// ChromaEffectLogo

// @0x140a969e0
ChromaEffectLogo::ChromaEffectLogo()
{
    m_nFrame = 0;
}

// @0x140a96a20
ChromaEffectLogo::~ChromaEffectLogo()
{
}

// @0x140a96a50
void ChromaEffectLogo::Create()
{
    Clear();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    IChromaManager* pManager = GetChromaManager();
    RZEFFECTID effectId;
    pManager->CreateKeyboardEffect(Keyboard::CHROMA_NONE, NULL, &effectId);
    m_effects.push_back(effectId);
    for (int row = 0; row < Keyboard::MAX_ROW; row++)
    {
        for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
        {
            if (row == 0)
            {
                effect.Color[row][col] = RGB(255, 0, 0);
            }
            else if (col < 18)
            {
                effect.Color[row][col] = RGB(200, 200, 200);
            }
            else if (col >= 18 && col < 21)
            {
                if (row == 1 || row == 3 || row == 5 || (row == 2 && col == 20) || (row == 4 && col == 18))
                    effect.Color[row][col] = RGB(255, 100, 0);
            }
        }
        if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
            m_effects.push_back(effectId);
    }
}

// @0x140a96c30
void ChromaEffectLogo::Play()
{
    if (GetChromaManager()->GetState() != STATE_LOGIN)
        m_nFrame = m_effects.size() - 1;
    ChromaEffectBase::Play();
}

// @0x140a96cd0
DWORD ChromaEffectLogo::GetInterval()
{
    return 200;
}

// ================================================================================================================
// ChromaEffectPlaying

// @0x140a96ce0
ChromaEffectPlaying::ChromaEffectPlaying()
{
    memset(m_bPressed, 0, sizeof(m_bPressed));
    m_nMaxHp = 0;
    m_nHp = 0;
    m_nMaxSp = 0;
    m_nSp = 0;
    m_bFlash = false;
    m_effectId = GUID_NULL;
}

// @0x140a96de0
ChromaEffectPlaying::~ChromaEffectPlaying()
{
    if (m_effectId != GUID_NULL)
        GetChromaManager()->DeleteEffect(m_effectId);
}

// @0x140a96eb0
void ChromaEffectPlaying::SetHp(unsigned nHp, unsigned nMaxHp)
{
    if (m_nHp > 0 && m_nMaxHp > 0 && nMaxHp > 0 && m_nHp > nHp)
    {
        m_bFlash = true;
        ChromaManagerImpl* pImpl = dynamic_cast<ChromaManagerImpl*>(GetChromaManager());
        if (pImpl)
            pImpl->AddLinkFlag(ChromaLinkEffect::FLAG_HIT);
    }
    m_nMaxHp = nMaxHp;
    m_nHp = nHp;
}

// @0x140a96f60
void ChromaEffectPlaying::SetSp(unsigned nSp, unsigned nMaxSp)
{
    m_nMaxSp = nMaxSp;
    m_nSp = nSp;
}

// @0x140a96f90
void ChromaEffectPlaying::StartCooldown(int nSlot, int a2, __int64 a3, float fTime)
{
    if (nSlot < 0 || nSlot >= COOLDOWN_COUNT)
        return;
    if (fTime > 0.0f)
        m_cooldowns[nSlot].Start(fTime);
}

// @0x140a97000
void ChromaEffectPlaying::ResetCooldown(int nSlot)
{
    if (nSlot < 0 || nSlot >= COOLDOWN_COUNT)
        return;
    m_cooldowns[nSlot].Reset();
}

// @0x140a97050
void ChromaEffectPlaying::PressSkill(int nSkill)
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    if (pImpl == NULL)
        return;
    for (int nKey = 1; nKey < KEY_COUNT; nKey++)
    {
        if (nSkill == pImpl->GetKeySkill(nKey))
            m_bPressed[nKey] = true;
    }
}

// @0x140a970d0
void ChromaEffectPlaying::PressKey(const CStringW& strName)
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    if (pImpl == NULL)
        return;
    if (strName.CompareNoCase(L"esc") == 0)
        m_bPressed[1] = true;                                   // DIK_ESCAPE
    else if (strName.CompareNoCase(L"enter") == 0)
        m_bPressed[0x1c] = true;                                // DIK_RETURN
}

// @0x140a97160
void ChromaEffectPlaying::ResetKeys()
{
    memset(m_bPressed, 0, sizeof(m_bPressed));
}

// @0x140a97190
COLORREF ChromaEffectPlaying::GetSkillColor(int nSkill)
{
    if (nSkill >= 500001 && nSkill <= 500025)
    {
        int nIndex = nSkill - 500001;
        if (m_cooldowns[nIndex].IsActive())
        {
            if (m_cooldowns[nIndex].IsExpired())
                return RGB(255, 255, 255);
            else
            {
                COLORREF color = RGB(200, 200, 200);
                float fProgress = m_cooldowns[nIndex].GetProgress();
                return RGB(GetRValue(color) * fProgress, GetGValue(color) * fProgress, GetBValue(color) * fProgress);
            }
        }
        return m_keyColor;
    }
    switch (nSkill)
    {
    case 200001:
    case 200002:
    case 200003:
    case 200004:
        return m_keyColor;
    }
    return m_backColor;
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a97300
void ChromaEffectPlaying::Create()
{
    m_nFrame = (m_nFrame == 0);
    ChromaManagerImpl* pImpl = dynamic_cast<ChromaManagerImpl*>(GetChromaManager());
    if (pImpl)
    {
        m_keyColor = pImpl->GetColor(1);
        m_blinkColor = pImpl->GetColor(2);
        m_backColor = pImpl->GetColor(0);
        Keyboard::CUSTOM_KEY_EFFECT_TYPE effect = {};
        for (int nKey = 1; nKey < KEY_COUNT; nKey++)
        {
            if (m_bPressed[nKey])
            {
                int nRzKey = pImpl->GetKeyboardKey(nKey);
                if (nRzKey != -1)
                {
                    if (m_nFrame % 2 == 0)
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = m_keyColor | 0x01000000;
                    else
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = m_blinkColor | 0x01000000;
                }
            }
            else
            {
                int nSkill = pImpl->GetKeySkill(nKey);
                if (nSkill > 0)
                {
                    int nRzKey = pImpl->GetKeyboardKey(nKey);
                    COLORREF color;
                    if (nRzKey != -1 && m_backColor != (color = GetSkillColor(nSkill)))
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = color | 0x01000000;
                }
            }
        }
        if (m_nMaxHp != 0)
        {
            unsigned nCount = (m_nHp << 3) / m_nMaxHp;
            for (int i = 0; i < 8; i++)
            {
                if (i < (int)nCount)
                    effect.Key[0][LOBYTE(i + 3)] = pImpl->GetColor(3) | 0x01000000;
                else
                    effect.Key[0][LOBYTE(i + 3)] = m_backColor | 0x01000000;
            }
        }
        if (m_nMaxSp != 0)
        {
            unsigned nCount = (m_nSp * 7) / m_nMaxSp;
            for (int i = 0; i < 7; i++)
            {
                if (i < (int)nCount)
                    effect.Key[0][LOBYTE(i + 11)] = pImpl->GetColor(4) | 0x01000000;
                else
                    effect.Key[0][LOBYTE(i + 11)] = m_backColor | 0x01000000;
            }
        }
        bool bLowHp = false;
        if (m_nFrame % 2 == 1 && m_nMaxHp != 0 && m_nHp != 0)
        {
            pImpl->RemoveLinkFlag(ChromaLinkEffect::FLAG_LOW_HP);
            if ((float)m_nHp / (float)m_nMaxHp < 0.3f)
            {
                bLowHp = true;
                pImpl->AddLinkFlag(ChromaLinkEffect::FLAG_LOW_HP);
            }
        }
        if (bLowHp || m_bFlash)
        {
            for (unsigned row = 0; row < Keyboard::MAX_ROW; row++)
            {
                for (unsigned col = 0; col < Keyboard::MAX_COLUMN; col++)
                    effect.Color[(int)row][(int)col] = RGB(255, 0, 0);
            }
            m_bFlash = false;
        }
        IChromaManager* pManager = GetChromaManager();
        if (m_effectId != GUID_NULL)
            pManager->ReserveDeleteEffect(m_effectId);
        if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &effect, &m_effectId) != 0)
            m_effectId = GUID_NULL;
    }
}

// @0x140a979f0
void ChromaEffectPlaying::Play()
{
    Create();
    if (m_effectId != GUID_NULL)
        GetChromaManager()->SetEffect(m_effectId);
}

// @0x140a985e0
DWORD ChromaEffectPlaying::GetInterval()
{
    return 200;
}

// @0x140a98650
bool ChromaEffectPlaying::Cooldown::IsExpired()
{
    CHROMA_ASSERT_H(35, m_fStartTime <= GetCurrentTick());
    if (m_dwDuration <= 0)
        return true;
    if (m_fStartTime + m_dwDuration > GetCurrentTick())
        return false;
    Reset();
    return true;
}

// @0x140a986d0
float ChromaEffectPlaying::Cooldown::GetProgress()
{
    CHROMA_ASSERT_H(46, m_fStartTime <= GetCurrentTick());
    if (m_dwDuration > 0)
        return (float)(GetCurrentTick() - m_fStartTime) / (float)m_dwDuration;
    return 1.0f;
}

// @0x140a98750
void ChromaEffectPlaying::Cooldown::Start(float fSecond)
{
    m_fStartTime = GetCurrentTick();
    m_dwDuration = FUN_14028d260(fSecond);
}

// ================================================================================================================
// ChromaEffectResurrection

// @0x140a9a4b0
ChromaEffectResurrection::ChromaEffectResurrection()
{
    m_nFrame = 0;
    m_n34 = 0;
    m_nCenter = 0x409;
}

// @0x140a9a510
ChromaEffectResurrection::~ChromaEffectResurrection()
{
}

// @0x140a9a540
void ChromaEffectResurrection::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
}

// @0x140a9a580
void ChromaEffectResurrection::Create()
{
    Clear();
    IChromaManager* pManager = GetChromaManager();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    int nRadius = m_nFrame - 2;
    int nCount = 0;
    for (int row = 0; row < Keyboard::MAX_ROW; row++)
    {
        for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
        {
            int nDistance = (int)sqrt(pow((float)row - (float)HIBYTE(m_nCenter), 2) + pow((float)col - (float)LOBYTE(m_nCenter), 2));
            if (nRadius < nDistance)
            {
                effect.Color[row][col] = pManager->GetColor(5);
                nCount++;
            }
            else if (nRadius == nDistance)
            {
                effect.Color[row][col] = pManager->GetColor(6);
                nCount++;
            }
            else
            {
                effect.Color[row][col] = pManager->GetColor(7);
            }
        }
    }
    RZEFFECTID effectId;
    if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
    {
        m_effects.push_back(effectId);
        m_nFrame++;
    }
    if (nCount == 0)
        pManager->SetState(STATE_PLAYING);
}

// @0x140a9a800
void ChromaEffectResurrection::Play()
{
    Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// ================================================================================================================
// ChromaEffectRipple

// @0x140a9a8d0
ChromaEffectRipple::ChromaEffectRipple()
{
    m_nFrame = 0;
    m_nReturnState = -1;
    m_nFieldType = 0;
    m_nRepeat = 0;
}

// @0x140a9a940
ChromaEffectRipple::~ChromaEffectRipple()
{
}

// @0x140a9a970
void ChromaEffectRipple::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
    m_nRepeat = 3;
    m_nReturnState = nPrevState;
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9a9c0
void ChromaEffectRipple::Create()
{
    Clear();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    for (int row = 0; row < Keyboard::MAX_ROW; row++)
    {
        COLORREF color = pImpl->GetColor(9);
        if (row == (int)(Keyboard::MAX_ROW - m_nFrame))
            color = pImpl->GetColor(10);
        else if (row > (int)(Keyboard::MAX_ROW - m_nFrame))
            color = pImpl->GetColor(11);
        for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
            effect.Color[row][col] = color;
    }
    RZEFFECTID effectId;
    if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
        m_effects.push_back(effectId);
    if (m_nFrame++ >= 7)
    {
        m_nFrame = 0;
        if (--m_nRepeat <= 0)
            pImpl->SetStateDirect(m_nReturnState);
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9ac20
void ChromaEffectRipple::OnFieldChanged(unsigned short nFieldType)
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    int nState = pImpl->GetState();
    if (nFieldType != 0 && m_nFieldType != 0 && m_nFieldType != nFieldType && (nState == STATE_PLAYING || nState == STATE_TALKING))
    {
        pImpl->SetState(STATE_RIPPLE);
        pImpl->AddLinkFlag(ChromaLinkEffect::FLAG_RAINBOW);
    }
    m_nFieldType = nFieldType;
}

// @0x140a9ad10
void ChromaEffectRipple::Play()
{
    Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// ================================================================================================================
// ChromaEffectSurviveWinner

// @0x140a9ade0
ChromaEffectSurviveWinner::ChromaEffectSurviveWinner()
{
    m_nFrame = 0;
}

// @0x140a9ae20
ChromaEffectSurviveWinner::~ChromaEffectSurviveWinner()
{
}

// @0x140a9ae50
void ChromaEffectSurviveWinner::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
}

// @0x140a9ae90
void ChromaEffectSurviveWinner::Create()
{
    Clear();
    IChromaManager* pManager = GetChromaManager();
    Keyboard::WAVE_EFFECT_TYPE effect = {};
    effect.Direction = Keyboard::WAVE_EFFECT_TYPE::DIRECTION_LEFT_TO_RIGHT;
    RZEFFECTID effectId;
    if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_WAVE, &effect, &effectId) == 0)
        m_effects.push_back(effectId);
}

// @0x140a9af40
void ChromaEffectSurviveWinner::Play()
{
    if (m_effects.empty())
        Create();
    if (m_effects.empty())
        return;
    if (m_nFrame == 0)
        GetChromaManager()->SetEffect(m_effects[0]);
    if (m_nFrame++ >= 50)
        GetChromaManager()->SetState(STATE_PLAYING);
}

// @0x140a9b080
DWORD ChromaEffectSurviveWinner::GetInterval()
{
    return 100;
}

// ================================================================================================================
// ChromaEffectTalking

// @0x140a9b090
ChromaEffectTalking::ChromaEffectTalking()
{
    m_nFrame = 0;
}

// @0x140a9b0d0
ChromaEffectTalking::~ChromaEffectTalking()
{
}

// @0x140a9b100
void ChromaEffectTalking::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    if (!pImpl)
        return;
    Clear();
    Keyboard::CUSTOM_KEY_EFFECT_TYPE effect = {};
    int nRzKey = pImpl->GetKeyboardKey(1);
    if (nRzKey != -1)
        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = pImpl->GetColor(1) | 0x01000000;
    for (int nFrame = 0; nFrame < 2; nFrame++)
    {
        for (int nKey = 1; nKey < ChromaManagerImpl::KEY_SKILL_COUNT; nKey++)
        {
            int nSkill = pImpl->GetKeySkill(nKey);
            if (nSkill == 300002)
            {
                nRzKey = pImpl->GetKeyboardKey(nKey);
                if (nRzKey != -1)
                {
                    if (nFrame == 0)
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = pImpl->GetColor(1) | 0x01000000;
                    else
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = pImpl->GetColor(2) | 0x01000000;
                }
            }
        }
        RZEFFECTID effectId;
        if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &effect, &effectId) == 0)
            m_effects.push_back(effectId);
    }
}

// @0x140a9b410
DWORD ChromaEffectTalking::GetInterval()
{
    return 200;
}

// ================================================================================================================
// ChromaLinkEffect

// @0x140a9b420
ChromaLinkEffect::ChromaLinkEffect()
{
    m_effectId = GUID_NULL;
    m_nFlags = 0;
    m_dwNextTick = 0;
    m_nFrame = 0;
}

// @0x140a9b470
ChromaLinkEffect::~ChromaLinkEffect()
{
    Delete();
}

// @0x140a9b4a0
void ChromaLinkEffect::Update()
{
    DWORD dwNow = GetCurrentTick();
    if (dwNow >= m_dwNextTick)
    {
        Create();
        if (m_effectId != GUID_NULL)
            GetChromaManager()->SetEffect(m_effectId);
        m_dwNextTick = dwNow + GetInterval();
    }
}

// @0x140a9b550
void ChromaLinkEffect::Delete()
{
    if (m_effectId != GUID_NULL)
    {
        GetChromaManager()->DeleteEffect(m_effectId);
        m_effectId = GUID_NULL;
    }
}

// @0x140a9b5d0
void ChromaLinkEffect::AddFlag(unsigned nFlag)
{
    if (nFlag == 0)
    {
        m_nFlags = 0;
        return;
    }
    if (nFlag == FLAG_RAINBOW)
        m_nFrame = 0;
    else if (nFlag == FLAG_HIT && (m_nFlags & FLAG_HIT) == 0 && m_nFrame % 2 != 0)
        m_nFrame++;
    m_nFlags |= nFlag;
}

// @0x140a9b660
void ChromaLinkEffect::RemoveFlag(unsigned nFlag)
{
    m_nFlags &= ~nFlag;
}

// @0x140a9b690
void ChromaLinkEffect::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    Delete();
    ChromaLink::STATIC_EFFECT_TYPE effect = {};
    if (m_nFlags & FLAG_HIT)
    {
        if (m_nFrame % 2 == 0)
        {
            effect.Color = pImpl->GetColor(14);
        }
        else
        {
            effect.Color = pImpl->GetColor(0);
            RemoveFlag(FLAG_HIT);
        }
    }
    else if (m_nFlags & FLAG_RAINBOW)
    {
        CreateRainbow();
        return;
    }
    else if (m_nFlags & FLAG_LOW_HP)
    {
        int nLevel = abs((int)m_nFrame % 20 - 10);
        effect.Color = RGB(nLevel * 255 / 10, 0, 0);
    }
    else
    {
        effect.Color = pImpl->GetColor(1);
    }
    if (pImpl->CreateChromaLinkEffect(ChromaLink::CHROMA_STATIC, &effect, &m_effectId) != 0)
        m_effectId = GUID_NULL;
    m_nFrame++;
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9b860
void ChromaLinkEffect::CreateRainbow()
{
    ChromaLink::CUSTOM_EFFECT_TYPE effect = {};
    switch ((m_nFrame / 2) % ChromaLink::MAX_LEDS + 1)
    {
    case 5:
        effect.Color[4] = RGB(0, 0, 200);
    case 4:
        effect.Color[3] = RGB(0, 180, 180);
    case 3:
        effect.Color[2] = RGB(0, 200, 0);
    case 2:
        effect.Color[1] = RGB(180, 180, 0);
    case 1:
        effect.Color[0] = RGB(200, 0, 0);
    }
    IChromaManager* pManager = GetChromaManager();
    if (pManager->CreateChromaLinkEffect(ChromaLink::CHROMA_CUSTOM, &effect, &m_effectId) != 0)
        m_effectId = GUID_NULL;
    m_nFrame++;
    if (m_nFrame >= ChromaLink::MAX_LEDS * 6 + 6)
        RemoveFlag(FLAG_RAINBOW);
}

// @0x140a9b9e0
DWORD ChromaLinkEffect::GetInterval()
{
    return 100;
}

// ================================================================================================================
// ChromaManagerImpl

// @0x140a9b9f0
ChromaManagerImpl::~ChromaManagerImpl()
{
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9ba90
void ChromaManagerImpl::SetState(int nState)
{
    if (nState == m_nState)
        return;
    if (m_nState == STATE_RIPPLE && nState != STATE_RIPPLE && m_effects[STATE_RIPPLE] != NULL)
    {
        static_cast<ChromaEffectRipple*>(m_effects[STATE_RIPPLE])->SetReturnState(nState);
        return;
    }
    if (nState < STATE_COUNT && nState > -1 && m_effects[nState] != NULL)
        m_effects[nState]->OnEnter(m_nState);
    if (nState == -1)
    {
        if (m_nPrevState != -1)
            m_nState = m_nPrevState;
    }
    else
    {
        if (nState == STATE_PLAYING)
        {
            if (CStateService::GetInstance()->FUN_1417e2610() != 0x620000c)
                nState = STATE_CHARACTER;
        }
        m_nPrevState = m_nState;
        m_nState = nState;
    }
    ResetKeys(true);
}

// @0x140a9bbe0
void ChromaManagerImpl::SetStateDirect(int nState)
{
    m_nPrevState = -1;
    m_nState = nState;
}

// @0x140a9bc10
void ChromaManagerImpl::vfunc_oa0_3(int nHp, int nMaxHp)
{
    ChromaEffectPlaying* pEffect = static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING]);
    if (pEffect != NULL)
        pEffect->SetHp(nHp, nMaxHp);
}

// @0x140a9bc70
void ChromaManagerImpl::vfunc_oa0_4(int nSp, int nMaxSp)
{
    ChromaEffectPlaying* pEffect = static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING]);
    if (pEffect != NULL)
        pEffect->SetSp(nSp, nMaxSp);
}

// @0x140a9bcd0
void ChromaManagerImpl::vfunc_oa0_9(unsigned short nFieldType)
{
    ChromaEffectRipple* pEffect = static_cast<ChromaEffectRipple*>(m_effects[STATE_RIPPLE]);
    if (pEffect != NULL)
        pEffect->OnFieldChanged(nFieldType);
}

// @0x140a9bd20
void ChromaManagerImpl::SetCooldown(int nSlot, int a2, __int64 a3, float fTime)
{
    ChromaEffectPlaying* pEffect = static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING]);
    if (pEffect != NULL)
        pEffect->StartCooldown(nSlot, a2, a3, fTime);
}

// @0x140a9bd90
void ChromaManagerImpl::ResetCooldown(int nSlot)
{
    ChromaEffectPlaying* pEffect = static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING]);
    if (pEffect != NULL)
        pEffect->ResetCooldown(nSlot);
}

// @0x140a9bde0
void ChromaManagerImpl::Pause()
{
    m_bPaused = true;
}

// @0x140a9be00
void ChromaManagerImpl::Resume()
{
    m_bPaused = false;
    RefreshKeys();
}

// @0x140a9be40
int ChromaManagerImpl::GetKeySkill(int nKey)
{
    if (nKey <= 0 || nKey >= KEY_SKILL_COUNT)
        return 0;
    return m_keySkills[nKey];
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9be80
void ChromaManagerImpl::RefreshKeySkills()
{
    if (m_bPaused)
        return;
    memset(m_keySkills, 0, sizeof(m_keySkills));
    CKeyTable* pKeyTable = CKeyTable::GetInstance();
    for (int nKey = 1; nKey < KEY_SKILL_COUNT; nKey++)
    {
        unsigned __int64 nSkill = pKeyTable->FUN_14142d190(nKey);
        if (nSkill != 0 && nSkill <= 500025)
        {
            int nId = (int)nSkill;
            m_keySkills[nKey] = nId;
        }
    }
}

// @0x140a9bf30
int ChromaManagerImpl::GetKeyboardKey(int nKey)
{
    std::map<int, Keyboard::RZKEY>::iterator it = m_keyboardKeys.find(nKey);
    if (it != m_keyboardKeys.end())
        return (*it).second;
    return -1;
}

// @0x140a9bfb0
void ChromaManagerImpl::DeleteReservedEffects()
{
    for (std::vector<RZEFFECTID>::iterator it = m_reservedDeletes.begin(); it != m_reservedDeletes.end(); ++it)
        DeleteEffect(*it);
    m_reservedDeletes.clear();
}

// @0x140a9c070
void ChromaManagerImpl::ReserveDeleteEffect(RZEFFECTID effectId)
{
    m_reservedDeletes.push_back(effectId);
}

// @0x140a9c0b0
void ChromaManagerImpl::OnKeySkill(int nSkill, bool bKeep)
{
    ChromaEffectPlaying* pEffect = static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING]);
    if (pEffect != NULL)
    {
        pEffect->PressSkill(nSkill);
        m_bKeyLock = bKeep || m_bKeyLock;
    }
}

// @0x140a9c140
void ChromaManagerImpl::OnKeyName(const CStringW& strName)
{
    ChromaEffectPlaying* pEffect = static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING]);
    if (pEffect != NULL)
    {
        pEffect->PressKey(strName);
        m_bKeyLock = true;
    }
}

// @0x140a9c1a0
void ChromaManagerImpl::ResetKeys(bool bForce)
{
    if (m_bKeyLock && !bForce)
        return;
    m_bKeyLock = false;
    ChromaEffectPlaying* pEffect = static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING]);
    if (pEffect != NULL)
        pEffect->ResetKeys();
}

// @0x140a9c210
void ChromaManagerImpl::RefreshKeys()
{
    ResetKeys(true);
    RefreshKeySkills();
}

// @0x140a9c260
void ChromaManagerImpl::SetColorMode(int nMode)
{
    m_nColorMode = nMode;
    m_pColorTable->SetLevel(nMode);
    if (nMode == 0)
    {
        SetState(STATE_LOGO);
    }
    else
    {
        if (CUIService::GetInstance()->FUN_141adc890((eUIClassID)0x4eea) || CUIService::GetInstance()->FUN_141adc890((eUIClassID)0x4ef1))
            SetState(STATE_CHARACTER);
    }
}

// @0x140a9c320
void ChromaManagerImpl::AddLinkFlag(unsigned nFlag)
{
    m_linkEffect.AddFlag(nFlag);
}

// @0x140a9c350
void ChromaManagerImpl::RemoveLinkFlag(unsigned nFlag)
{
    m_linkEffect.RemoveFlag(nFlag);
}

// @0x140a9c380
COLORREF ChromaManagerImpl::GetColor(int nIndex)
{
    return m_pColorTable->GetColor(nIndex);
}

// @0x140a9c3b0
RZRESULT ChromaManagerImpl::Init()
{
    if (m_Init == NULL)
        return RZRESULT_INVALID;
    RZRESULT result = m_Init();
    m_bInitialized = true;
    return result;
}

// @0x140a9c3f0
RZRESULT ChromaManagerImpl::UnInit()
{
    if (m_UnInit == NULL)
        return RZRESULT_INVALID;
    RZRESULT result = m_UnInit();
    m_bInitialized = false;
    return result;
}

// @0x140a9c430
RZRESULT ChromaManagerImpl::CreateEffect(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateEffect(DeviceId, Effect, pParam, pEffectId);
}

// @0x140a9c4a0
RZRESULT ChromaManagerImpl::CreateChromaLinkEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateChromaLinkEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateChromaLinkEffect(Effect, pParam, pEffectId);
}

// @0x140a9c4f0
RZRESULT ChromaManagerImpl::CreateHeadsetEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateHeadsetEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateHeadsetEffect(Effect, pParam, pEffectId);
}

// @0x140a9c540
RZRESULT ChromaManagerImpl::CreateKeyboardEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateKeyboardEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateKeyboardEffect(Effect, pParam, pEffectId);
}

// @0x140a9c590
RZRESULT ChromaManagerImpl::CreateKeypadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateKeypadEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateKeypadEffect(Effect, pParam, pEffectId);
}

// @0x140a9c5e0
RZRESULT ChromaManagerImpl::CreateMouseEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateMouseEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateMouseEffect(Effect, pParam, pEffectId);
}

// @0x140a9c630
RZRESULT ChromaManagerImpl::CreateMousepadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateMousepadEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateMousepadEffect(Effect, pParam, pEffectId);
}

// @0x140a9c680
RZRESULT ChromaManagerImpl::SetEffect(RZEFFECTID EffectId)
{
    if (m_SetEffect == NULL)
        return RZRESULT_INVALID;
    return m_SetEffect(EffectId);
}

// @0x140a9c6e0
RZRESULT ChromaManagerImpl::DeleteEffect(RZEFFECTID EffectId)
{
    if (m_DeleteEffect == NULL)
        return RZRESULT_INVALID;
    return m_DeleteEffect(EffectId);
}

// @0x140a9c740
ChromaManagerImpl::ChromaManagerImpl()
{
    m_bKeyLock = false;
    m_hModule = NULL;
    m_pColorTable = NULL;
    m_bPaused = false;
    m_nColorMode = 0;
    UnloadSDK();
    m_nState = STATE_LOGIN;
    m_hThread = 0;
    memset(m_effects, 0, sizeof(m_effects));
    memset(m_keySkills, 0, sizeof(m_keySkills));
}

// @0x140a9c890
void ChromaManagerImpl::SetModule(HMODULE hModule)
{
    m_hModule = hModule;
}

// @0x140a9c8b0
bool ChromaManagerImpl::IsInitialized()
{
    return m_bInitialized;
}

// @0x140a9c8d0
bool ChromaManagerImpl::Initialize()
{
    if (!LoadSDK())
        return false;
    if (Init() != RZRESULT_SUCCESS)
        return false;
    m_pColorTable = new ChromaColorTable();
    InitKeyMap();
    m_effects[STATE_PLAYING] = new ChromaEffectPlaying();
    m_effects[STATE_LOADING] = new ChromaEffectLoading();
    m_effects[STATE_LOGO] = new ChromaEffectLogo();
    m_effects[STATE_LOGIN] = m_effects[STATE_LOGO];
    m_effects[STATE_TALKING] = new ChromaEffectTalking();
    m_effects[STATE_RIPPLE] = new ChromaEffectRipple();
    m_effects[STATE_CHARACTER] = new ChromaEffectCharacter();
    m_effects[STATE_DEATH] = new ChromaEffectDeath();
    m_effects[STATE_RESURRECTION] = new ChromaEffectResurrection();
    m_effects[STATE_DCLEAR] = new ChromaEffectDClear();
    m_effects[STATE_SURVIVE_WINNER] = new ChromaEffectSurviveWinner();
    m_effects[STATE_CINEMATIC] = new ChromaEffectCinematic();
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd00(this);
    m_hThread = _beginthreadex(NULL, 0, ThreadProc, this, 0, NULL);
    return true;
}

// @0x140a9cee0
void ChromaManagerImpl::Finalize()
{
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd90(this);
    if (m_bInitialized)
    {
        m_bInitialized = false;
        if (m_hThread != 0 && WaitForSingleObject((HANDLE)m_hThread, 1000) != WAIT_OBJECT_0)
            TerminateThread((HANDLE)m_hThread, 0);
        for (int i = 0; i < STATE_COUNT; i++)
        {
            if (m_effects[i] != NULL && i != STATE_LOGIN && i != STATE_CHARACTER)
                delete m_effects[i];
            m_effects[i] = NULL;
        }
        SetChromaManager(NULL);
        UnInit();
    }
    UnloadSDK();
    delete this;
}

// @0x140a9d090
int ChromaManagerImpl::GetMaxLeds(const EChromaSDKDevice1DEnum& device)
{
    switch (device)
    {
    case EChromaSDKDevice1DEnum::DE_ChromaLink:
        return ChromaLink::MAX_LEDS;
    case EChromaSDKDevice1DEnum::DE_Headset:
        return Headset::MAX_LEDS;
    case EChromaSDKDevice1DEnum::DE_Mousepad:
        return Mousepad::MAX_LEDS;
    }
    return 0;
}

// @0x140a9d0e0
int ChromaManagerImpl::GetMaxRow(const EChromaSDKDevice2DEnum& device)
{
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
        return Keyboard::MAX_ROW;
    case EChromaSDKDevice2DEnum::DE_Keypad:
        return Keypad::MAX_ROW;
    case EChromaSDKDevice2DEnum::DE_Mouse:
        return Mouse::MAX_ROW;
    }
    return 0;
}

// @0x140a9d130
int ChromaManagerImpl::GetMaxColumn(const EChromaSDKDevice2DEnum& device)
{
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
        return Keyboard::MAX_COLUMN;
    case EChromaSDKDevice2DEnum::DE_Keypad:
        return Keypad::MAX_COLUMN;
    case EChromaSDKDevice2DEnum::DE_Mouse:
        return Mouse::MAX_COLUMN;
    }
    return 0;
}

// @0x140a9d180
std::vector<COLORREF> ChromaManagerImpl::CreateColors1D(const EChromaSDKDevice1DEnum& device)
{
    std::vector<COLORREF> colors = std::vector<COLORREF>();
    int elements = GetMaxLeds(device);
    COLORREF black = RGB(0, 0, 0);
    for (int i = 0; i < elements; ++i)
        colors.push_back(black);
    return colors;
}

// @0x140a9d230
std::vector<FChromaSDKColors> ChromaManagerImpl::CreateColors2D(const EChromaSDKDevice2DEnum& device)
{
    std::vector<FChromaSDKColors> result = std::vector<FChromaSDKColors>();
    int maxRow = GetMaxRow(device);
    int maxColumn = GetMaxColumn(device);
    COLORREF black = RGB(0, 0, 0);
    for (int i = 0; i < maxRow; ++i)
    {
        FChromaSDKColors row = FChromaSDKColors();
        for (int j = 0; j < maxColumn; ++j)
            row.Colors.push_back(black);
        result.push_back(row);
    }
    return result;
}

// @0x140a9d360
std::vector<COLORREF> ChromaManagerImpl::CreateRandomColors1D(const EChromaSDKDevice1DEnum& device)
{
    std::vector<COLORREF> colors = std::vector<COLORREF>();
    int elements = GetMaxLeds(device);
    for (int i = 0; i < elements; ++i)
    {
        int red = rand() % 256;
        int green = rand() % 256;
        int blue = rand() % 256;
        COLORREF color = RGB(red, green, blue);
        colors.push_back(color);
    }
    return colors;
}

// @0x140a9d480
std::vector<FChromaSDKColors> ChromaManagerImpl::CreateRandomColors2D(const EChromaSDKDevice2DEnum& device)
{
    std::vector<FChromaSDKColors> result = std::vector<FChromaSDKColors>();
    int maxRows = GetMaxRow(device);
    int maxColumns = GetMaxColumn(device);
    for (int i = 0; i < maxRows; ++i)
    {
        FChromaSDKColors row = FChromaSDKColors();
        for (int j = 0; j < maxColumns; ++j)
        {
            int red = rand() % 256;
            int green = rand() % 256;
            int blue = rand() % 256;
            COLORREF color = RGB(red, green, blue);
            row.Colors.push_back(color);
        }
        result.push_back(row);
    }
    return result;
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9d640
const std::vector<FChromaSDKColors>& ChromaManagerImpl::SetMouseLEDColor(const EChromaSDKMouseLED& led, COLORREF color, std::vector<FChromaSDKColors>& colors)
{
    int maxRow = Mouse::MAX_ROW;
    int maxColumn = Mouse::MAX_COLUMN;
    if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
        return colors;
    Mouse::RZLED2 rzled = m_mouseLeds[led];
    colors[HIBYTE(rzled)].Colors[LOBYTE(rzled)] = color;
    return colors;
}

// @0x140a9d730
FChromaSDKEffectResult ChromaManagerImpl::CreateEffect(RZDEVICEID deviceId, ChromaSDK::EFFECT_TYPE effect, const std::vector<FChromaSDKColors>& colors)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    CUSTOM_EFFECT_TYPE pParam = {};
    for (int i = 0; i < MAX_ROW; i++)
    {
        const FChromaSDKColors& row = colors[i];
        for (int j = 0; j < MAX_COLUMN; ++j)
            pParam.Color[i][j] = row.Colors[j];
    }

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    result = CreateEffect(deviceId, ChromaSDK::CHROMA_CUSTOM, &pParam, &effectId);
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9d8e0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectNone1D(const EChromaSDKDevice1DEnum& device)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    switch (device)
    {
    case EChromaSDKDevice1DEnum::DE_ChromaLink:
        result = CreateChromaLinkEffect(ChromaLink::CHROMA_NONE, NULL, &effectId);
        break;
    case EChromaSDKDevice1DEnum::DE_Headset:
        result = CreateHeadsetEffect(Headset::CHROMA_NONE, NULL, &effectId);
        break;
    case EChromaSDKDevice1DEnum::DE_Mousepad:
        result = CreateMousepadEffect(Mousepad::CHROMA_NONE, NULL, &effectId);
        break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9da60
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectNone2D(const EChromaSDKDevice2DEnum& device)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    int result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
        result = CreateKeyboardEffect(Keyboard::CHROMA_NONE, NULL, &effectId);
        break;
    case EChromaSDKDevice2DEnum::DE_Keypad:
        result = CreateKeypadEffect(Keypad::CHROMA_NONE, NULL, &effectId);
        break;
    case EChromaSDKDevice2DEnum::DE_Mouse:
        result = CreateMouseEffect(Mouse::CHROMA_NONE, NULL, &effectId);
        break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9dbe0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectStatic1D(const EChromaSDKDevice1DEnum& device, COLORREF color)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    switch (device)
    {
    case EChromaSDKDevice1DEnum::DE_ChromaLink:
    {
        ChromaLink::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateChromaLinkEffect(ChromaLink::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice1DEnum::DE_Headset:
    {
        Headset::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateHeadsetEffect(Headset::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice1DEnum::DE_Mousepad:
    {
        Mousepad::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateMousepadEffect(Mousepad::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9ddd0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectStatic2D(const EChromaSDKDevice2DEnum& device, COLORREF color)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
    {
        Keyboard::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateKeyboardEffect(Keyboard::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice2DEnum::DE_Keypad:
    {
        Keypad::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateKeypadEffect(Keypad::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice2DEnum::DE_Mouse:
    {
        Mouse::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        pParam.LEDId = Mouse::RZLED_ALL;
        result = CreateMouseEffect(Mouse::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9dfd0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectCustom1D(const EChromaSDKDevice1DEnum& device, const std::vector<COLORREF>& colors)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    int maxLeds = 0;
    switch (device)
    {
    case EChromaSDKDevice1DEnum::DE_ChromaLink:
    {
        maxLeds = ChromaLink::MAX_LEDS;
        if (maxLeds != colors.size())
            break;
        ChromaLink::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxLeds; i++)
            pParam.Color[i] = colors[i];
        result = CreateChromaLinkEffect(ChromaLink::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice1DEnum::DE_Headset:
    {
        maxLeds = Headset::MAX_LEDS;
        if (maxLeds != colors.size())
            break;
        Headset::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxLeds; i++)
            pParam.Color[i] = colors[i];
        result = CreateHeadsetEffect(Headset::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice1DEnum::DE_Mousepad:
    {
        maxLeds = Mousepad::MAX_LEDS;
        if (maxLeds != colors.size())
            break;
        Mousepad::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxLeds; i++)
            pParam.Color[i] = colors[i];
        result = CreateMousepadEffect(Mousepad::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9e300
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectCustom2D(const EChromaSDKDevice2DEnum& device, const std::vector<FChromaSDKColors>& colors)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    int maxRow = 0;
    int maxColumn = 0;
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
    {
        maxRow = Keyboard::MAX_ROW;
        maxColumn = Keyboard::MAX_COLUMN;
        if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
            break;
        Keyboard::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxRow; i++)
        {
            const FChromaSDKColors& row = colors[i];
            for (int j = 0; j < maxColumn; j++)
                pParam.Color[i][j] = row.Colors[j];
        }
        result = CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice2DEnum::DE_Keypad:
    {
        maxRow = Keypad::MAX_ROW;
        maxColumn = Keypad::MAX_COLUMN;
        if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
            break;
        Keypad::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxRow; i++)
        {
            const FChromaSDKColors& row = colors[i];
            for (int j = 0; j < maxColumn; j++)
                pParam.Color[i][j] = row.Colors[j];
        }
        result = CreateKeypadEffect(Keypad::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice2DEnum::DE_Mouse:
    {
        maxRow = Mouse::MAX_ROW;
        maxColumn = Mouse::MAX_COLUMN;
        if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
            break;
        Mouse::CUSTOM_EFFECT_TYPE2 pParam = {};
        for (int i = 0; i < maxRow; i++)
        {
            const FChromaSDKColors& row = colors[i];
            for (int j = 0; j < maxColumn; j++)
                pParam.Color[i][j] = row.Colors[j];
        }
        result = CreateMouseEffect(Mouse::CHROMA_CUSTOM2, &pParam, &effectId);
    }
    break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9e7f0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectKeyboardCustom2D(const std::vector<FChromaSDKColors>& colors)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    int maxRow = Keyboard::MAX_ROW;
    int maxColumn = Keyboard::MAX_COLUMN;
    if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
    {
    }
    else
    {
        Keyboard::CUSTOM_KEY_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxRow; i++)
        {
            const FChromaSDKColors& row = colors[i];
            for (int j = 0; j < maxColumn; j++)
                pParam.Key[i][j] = row.Colors[j];
        }
        result = CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &pParam, &effectId);
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9e9e0
RZRESULT ChromaManagerImpl::PlayEffect(RZEFFECTID EffectId)
{
    RZRESULT result = SetEffect(EffectId);
    return result;
}

// @0x140a9ea40
RZRESULT ChromaManagerImpl::RemoveEffect(RZEFFECTID EffectId)
{
    RZRESULT result = DeleteEffect(EffectId);
    return result;
}

// @0x140a9eaa0
unsigned __stdcall ChromaManagerImpl::ThreadProc(void* pParam)
{
    ChromaManagerImpl* pManager = (ChromaManagerImpl*)pParam;
    ChromaEffectCharacter* pCharacter = chroma_cast<ChromaEffectCharacter>(pManager->m_effects[STATE_CHARACTER]);
    while (pManager->IsInitialized())
    {
        pManager->Tick();
        pCharacter->UpdateMouse();
        pManager->DeleteReservedEffects();
        Sleep(20);
    }
    _endthreadex(0);
    return 0;
}

// @0x140a9eb40
void ChromaManagerImpl::Tick()
{
    if (m_nState >= STATE_COUNT || m_nState <= -1)
        return;
    ChromaEffectBase* pEffect = m_effects[m_nState];
    if (pEffect)
        pEffect->Update();
    m_linkEffect.Update();
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140a9ebb0
bool ChromaManagerImpl::LoadSDK()
{
    try
    {
        m_bInitialized = false;
        if (m_hModule == NULL)
        {
            m_hModule = LoadLibraryA("RzChromaSDK64.dll");
            if (m_hModule == NULL)
                throw "RzChromaSDK64.dll";
        }
        m_Init = (INIT)GetProcAddress(m_hModule, "Init");
        if (m_Init == NULL)
            throw "Init";
        m_UnInit = (UNINIT)GetProcAddress(m_hModule, "UnInit");
        if (m_Init == NULL)
            throw "UnInit";
        m_QueryDevice = (QUERYDEVICE)GetProcAddress(m_hModule, "QueryDevice");
        if (m_Init == NULL)
            throw "UnInit";
        m_UnInit = (UNINIT)GetProcAddress(m_hModule, "UnInit");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateChromaLinkEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateChromaLinkEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateHeadsetEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateHeadsetEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateKeyboardEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateKeyboardEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateMouseEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateMouseEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateMousepadEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateMousepadEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateKeypadEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateKeypadEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateEffect = (CREATEEFFECT)GetProcAddress(m_hModule, "CreateEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_SetEffect = (SETEFFECT)GetProcAddress(m_hModule, "SetEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_DeleteEffect = (DELETEEFFECT)GetProcAddress(m_hModule, "DeleteEffect");
        if (m_Init == NULL)
            throw "UnInit";
    }
    catch (...)
    {
        return false;
    }
    return true;
}

// @0x140a9f080
void ChromaManagerImpl::InitKeyMap()
{
    m_keyboardKeys[0x01] = Keyboard::RZKEY_ESC;
    m_keyboardKeys[0x3B] = Keyboard::RZKEY_F1;
    m_keyboardKeys[0x3C] = Keyboard::RZKEY_F2;
    m_keyboardKeys[0x3D] = Keyboard::RZKEY_F3;
    m_keyboardKeys[0x3E] = Keyboard::RZKEY_F4;
    m_keyboardKeys[0x3F] = Keyboard::RZKEY_F5;
    m_keyboardKeys[0x40] = Keyboard::RZKEY_F6;
    m_keyboardKeys[0x41] = Keyboard::RZKEY_F7;
    m_keyboardKeys[0x42] = Keyboard::RZKEY_F8;
    m_keyboardKeys[0x43] = Keyboard::RZKEY_F9;
    m_keyboardKeys[0x44] = Keyboard::RZKEY_F10;
    m_keyboardKeys[0x55] = Keyboard::RZKEY_F11;
    m_keyboardKeys[0x56] = Keyboard::RZKEY_F12;
    m_keyboardKeys[0x29] = Keyboard::RZKEY_OEM_1;
    m_keyboardKeys[0x02] = Keyboard::RZKEY_1;
    m_keyboardKeys[0x03] = Keyboard::RZKEY_2;
    m_keyboardKeys[0x04] = Keyboard::RZKEY_3;
    m_keyboardKeys[0x05] = Keyboard::RZKEY_4;
    m_keyboardKeys[0x06] = Keyboard::RZKEY_5;
    m_keyboardKeys[0x07] = Keyboard::RZKEY_6;
    m_keyboardKeys[0x08] = Keyboard::RZKEY_7;
    m_keyboardKeys[0x09] = Keyboard::RZKEY_8;
    m_keyboardKeys[0x0A] = Keyboard::RZKEY_9;
    m_keyboardKeys[0x0B] = Keyboard::RZKEY_0;
    m_keyboardKeys[0x1E] = Keyboard::RZKEY_A;
    m_keyboardKeys[0x30] = Keyboard::RZKEY_B;
    m_keyboardKeys[0x2E] = Keyboard::RZKEY_C;
    m_keyboardKeys[0x20] = Keyboard::RZKEY_D;
    m_keyboardKeys[0x12] = Keyboard::RZKEY_E;
    m_keyboardKeys[0x21] = Keyboard::RZKEY_F;
    m_keyboardKeys[0x22] = Keyboard::RZKEY_G;
    m_keyboardKeys[0x23] = Keyboard::RZKEY_H;
    m_keyboardKeys[0x17] = Keyboard::RZKEY_I;
    m_keyboardKeys[0x24] = Keyboard::RZKEY_J;
    m_keyboardKeys[0x25] = Keyboard::RZKEY_K;
    m_keyboardKeys[0x26] = Keyboard::RZKEY_L;
    m_keyboardKeys[0x32] = Keyboard::RZKEY_M;
    m_keyboardKeys[0x31] = Keyboard::RZKEY_N;
    m_keyboardKeys[0x18] = Keyboard::RZKEY_O;
    m_keyboardKeys[0x19] = Keyboard::RZKEY_P;
    m_keyboardKeys[0x10] = Keyboard::RZKEY_Q;
    m_keyboardKeys[0x13] = Keyboard::RZKEY_R;
    m_keyboardKeys[0x1F] = Keyboard::RZKEY_S;
    m_keyboardKeys[0x14] = Keyboard::RZKEY_T;
    m_keyboardKeys[0x16] = Keyboard::RZKEY_U;
    m_keyboardKeys[0x2F] = Keyboard::RZKEY_V;
    m_keyboardKeys[0x11] = Keyboard::RZKEY_W;
    m_keyboardKeys[0x2D] = Keyboard::RZKEY_X;
    m_keyboardKeys[0x15] = Keyboard::RZKEY_Y;
    m_keyboardKeys[0x2C] = Keyboard::RZKEY_Z;
    m_keyboardKeys[0x52] = Keyboard::RZKEY_NUMPAD0;
    m_keyboardKeys[0x4F] = Keyboard::RZKEY_NUMPAD1;
    m_keyboardKeys[0x50] = Keyboard::RZKEY_NUMPAD2;
    m_keyboardKeys[0x51] = Keyboard::RZKEY_NUMPAD3;
    m_keyboardKeys[0x4B] = Keyboard::RZKEY_NUMPAD4;
    m_keyboardKeys[0x4C] = Keyboard::RZKEY_NUMPAD5;
    m_keyboardKeys[0x4D] = Keyboard::RZKEY_NUMPAD6;
    m_keyboardKeys[0x47] = Keyboard::RZKEY_NUMPAD7;
    m_keyboardKeys[0x48] = Keyboard::RZKEY_NUMPAD8;
    m_keyboardKeys[0x49] = Keyboard::RZKEY_NUMPAD9;
    m_keyboardKeys[0x74] = Keyboard::RZKEY_NUMPAD_DIVIDE;
    m_keyboardKeys[0x37] = Keyboard::RZKEY_NUMPAD_MULTIPLY;
    m_keyboardKeys[0x4A] = Keyboard::RZKEY_NUMPAD_SUBTRACT;
    m_keyboardKeys[0x4E] = Keyboard::RZKEY_NUMPAD_ADD;
    m_keyboardKeys[0x6A] = Keyboard::RZKEY_NUMPAD_ENTER;
    m_keyboardKeys[0x53] = Keyboard::RZKEY_NUMPAD_DECIMAL;
    m_keyboardKeys[0x46] = Keyboard::RZKEY_SCROLL;
    m_keyboardKeys[0x77] = Keyboard::RZKEY_PAUSE;
    m_keyboardKeys[0x80] = Keyboard::RZKEY_INSERT;
    m_keyboardKeys[0x78] = Keyboard::RZKEY_HOME;
    m_keyboardKeys[0x7A] = Keyboard::RZKEY_PAGEUP;
    m_keyboardKeys[0x81] = Keyboard::RZKEY_DELETE;
    m_keyboardKeys[0x7D] = Keyboard::RZKEY_END;
    m_keyboardKeys[0x7F] = Keyboard::RZKEY_PAGEDOWN;
    m_keyboardKeys[0x79] = Keyboard::RZKEY_UP;
    m_keyboardKeys[0x7B] = Keyboard::RZKEY_LEFT;
    m_keyboardKeys[0x7E] = Keyboard::RZKEY_DOWN;
    m_keyboardKeys[0x7C] = Keyboard::RZKEY_RIGHT;
    m_keyboardKeys[0x0F] = Keyboard::RZKEY_TAB;
    m_keyboardKeys[0x3A] = Keyboard::RZKEY_CAPSLOCK;
    m_keyboardKeys[0x0E] = Keyboard::RZKEY_BACKSPACE;
    m_keyboardKeys[0x1C] = Keyboard::RZKEY_ENTER;
    m_keyboardKeys[0x1D] = Keyboard::RZKEY_LCTRL;
    m_keyboardKeys[0x82] = Keyboard::RZKEY_LWIN;
    m_keyboardKeys[0x38] = Keyboard::RZKEY_LALT;
    m_keyboardKeys[0x39] = Keyboard::RZKEY_SPACE;
    m_keyboardKeys[0x76] = Keyboard::RZKEY_RALT;
    m_keyboardKeys[0x6B] = Keyboard::RZKEY_RCTRL;
    m_keyboardKeys[0x2A] = Keyboard::RZKEY_LSHIFT;
    m_keyboardKeys[0x36] = Keyboard::RZKEY_RSHIFT;
    m_keyboardKeys[0x0C] = Keyboard::RZKEY_OEM_2;
    m_keyboardKeys[0x0D] = Keyboard::RZKEY_OEM_3;
    m_keyboardKeys[0x1A] = Keyboard::RZKEY_OEM_4;
    m_keyboardKeys[0x1B] = Keyboard::RZKEY_OEM_5;
    m_keyboardKeys[0x2B] = Keyboard::RZKEY_OEM_6;
    m_keyboardKeys[0x27] = Keyboard::RZKEY_OEM_7;
    m_keyboardKeys[0x28] = Keyboard::RZKEY_OEM_8;
    m_keyboardKeys[0x33] = Keyboard::RZKEY_OEM_9;
    m_keyboardKeys[0x34] = Keyboard::RZKEY_OEM_10;
    m_keyboardKeys[0x35] = Keyboard::RZKEY_OEM_11;
    m_mouseLeds[EChromaSDKMouseLED::ML_SCROLLWHEEL] = Mouse::RZLED2_SCROLLWHEEL;
    m_mouseLeds[EChromaSDKMouseLED::ML_LOGO] = Mouse::RZLED2_LOGO;
    m_mouseLeds[EChromaSDKMouseLED::ML_BACKLIGHT] = Mouse::RZLED2_BACKLIGHT;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE1] = Mouse::RZLED2_LEFT_SIDE1;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE2] = Mouse::RZLED2_LEFT_SIDE2;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE3] = Mouse::RZLED2_LEFT_SIDE3;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE4] = Mouse::RZLED2_LEFT_SIDE4;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE5] = Mouse::RZLED2_LEFT_SIDE5;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE6] = Mouse::RZLED2_LEFT_SIDE6;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE7] = Mouse::RZLED2_LEFT_SIDE7;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM1] = Mouse::RZLED2_BOTTOM1;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM2] = Mouse::RZLED2_BOTTOM2;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM3] = Mouse::RZLED2_BOTTOM3;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM4] = Mouse::RZLED2_BOTTOM4;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM5] = Mouse::RZLED2_BOTTOM5;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE1] = Mouse::RZLED2_RIGHT_SIDE1;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE2] = Mouse::RZLED2_RIGHT_SIDE2;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE3] = Mouse::RZLED2_RIGHT_SIDE3;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE4] = Mouse::RZLED2_RIGHT_SIDE4;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE5] = Mouse::RZLED2_RIGHT_SIDE5;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE6] = Mouse::RZLED2_RIGHT_SIDE6;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE7] = Mouse::RZLED2_RIGHT_SIDE7;
}

// @0x140aa0670
void ChromaManagerImpl::UnloadSDK()
{
    m_Init = NULL;
    m_UnInit = NULL;
    m_CreateEffect = NULL;
    m_CreateChromaLinkEffect = NULL;
    m_CreateHeadsetEffect = NULL;
    m_CreateKeyboardEffect = NULL;
    m_CreateKeypadEffect = NULL;
    m_CreateMouseEffect = NULL;
    m_CreateMousepadEffect = NULL;
    m_SetEffect = NULL;
    m_DeleteEffect = NULL;
    m_QueryDevice = NULL;
    if (m_hModule != NULL)
        FreeLibrary(m_hModule);
    if (m_pColorTable != NULL)
    {
        delete m_pColorTable;
        m_pColorTable = NULL;
    }
}

} // namespace ChromaSDK

// ================================================================================================================
// UIStatusEventListener: the no-op base slots (inline in the original header; this obj emitted them first, as the
// ChromaManagerImpl vftable needs them)

// @0x140aa6d50
void UIStatusEventListener::vfunc_oa0_30(int a1)
{
}

// @0x140aa6d60
void UIStatusEventListener::vfunc_oa0_31(void* a1)
{
}

// @0x140aa6d70
void UIStatusEventListener::vfunc_oa0_2()
{
}

// @0x140aa6d80
void UIStatusEventListener::vfunc_oa0_5(int a1, int a2)
{
}

// @0x140aa6d90
void UIStatusEventListener::vfunc_oa0_6(void* a1, void* a2)
{
}

// @0x140aa6da0
void UIStatusEventListener::vfunc_oa0_10(CStringW s)
{
}

// @0x140aa6dc0
void UIStatusEventListener::vfunc_oa0_19(void* a1, int a2)
{
}

// @0x140aa6dd0
void UIStatusEventListener::vfunc_oa0_16(void* a1, int a2)
{
}

// @0x140aa6de0
void UIStatusEventListener::vfunc_oa0_7(int a1, CStringW s)
{
}

// @0x140aa6e10
void UIStatusEventListener::vfunc_oa0_17(void* a1, int a2)
{
}

// @0x140aa6e20
void UIStatusEventListener::vfunc_oa0_18(void* a1, int a2)
{
}

// @0x140aa6e30
void UIStatusEventListener::vfunc_oa0_14(void* a1, int a2)
{
}

// @0x140aa6e40
void UIStatusEventListener::vfunc_oa0_15(void* a1, int a2)
{
}

// @0x140aa6e50
void UIStatusEventListener::vfunc_oa0_11(void* a1)
{
}

// @0x140aa6e60
void UIStatusEventListener::vfunc_oa0_8(CStringW s)
{
}

// @0x140aa6e80
void UIStatusEventListener::vfunc_oa0_20(int a1)
{
}

// @0x140aa6e90
void UIStatusEventListener::vfunc_oa0_27(int a1, int a2)
{
}

// @0x140aa6ea0
void UIStatusEventListener::vfunc_oa0_28()
{
}

// @0x140aa6eb0
void UIStatusEventListener::vfunc_oa0_21()
{
}

// @0x140aa6ec0
void UIStatusEventListener::vfunc_oa0_29()
{
}

// @0x140aa6ed0
void UIStatusEventListener::vfunc_oa0_12(int a1)
{
}

// @0x140aa6ee0
void UIStatusEventListener::vfunc_oa0_13(void* a1)
{
}

// @0x140aa6ef0
void UIStatusEventListener::vfunc_oa0_26(void* a1)
{
}

// @0x140aa6f00
void UIStatusEventListener::vfunc_oa0_25(void* a1)
{
}

// @0x140aa6f10
void UIStatusEventListener::vfunc_oa0_23()
{
}

// @0x140aa6f20
void UIStatusEventListener::vfunc_oa0_22()
{
}

// @0x140aa6f30
void UIStatusEventListener::vfunc_oa0_24(int a1)
{
}

// the plugin's out-of-line ChromaSDKPluginTypes.cpp members

// @0x140aaa620
ChromaSDK::FChromaSDKColorFrame1D::FChromaSDKColorFrame1D()
{
    Duration = 1.0f;
}

// @0x140aaa660
ChromaSDK::FChromaSDKColorFrame2D::FChromaSDKColorFrame2D()
{
    Duration = 1.0f;
}

namespace ChromaSDK {

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140aaa6a0
void SetChromaManager(IChromaManager* pManager)
{
    g_pChromaManager = pManager;
    if (pManager == NULL)
        g_pChromaManager = &g_chromaManagerDummy;
}

// ================================================================================================================
// ChromaManagerDummy

// @0x140aaa6d0
ChromaManagerDummy::ChromaManagerDummy()
{
}

// @0x140aaa710
ChromaManagerDummy::~ChromaManagerDummy()
{
}

// MS2-FUNCTIONAL: behaviour-equivalent, codegen differs (stack-slot/branch layout); left to the permuter lane
// @0x140aaa740
bool ChromaManagerDummy::Initialize()
{
    if (CFeatureManager::GetInstance()->FUN_14036d570(0xd5))
    {
        if (CGameOption::GetInstance()->FUN_140aaaa90()->m_bDisable)
            return false;
        HMODULE hModule = LoadLibraryA("RzChromaSDK64.dll");
        if (hModule != NULL)
        {
            ChromaManagerImpl* pImpl = new ChromaManagerImpl();
            pImpl->SetModule(hModule);
            if (pImpl->Initialize())
            {
                SetChromaManager(pImpl);
                return true;
            }
            delete pImpl;
            return false;
        }
    }
    return false;
}

} // namespace ChromaSDK

// @0x140aaaa90
Unk_GoChroma* CGameOption::FUN_140aaaa90()
{
    return &m_chroma;
}

// The UCRT's `static __inline memcpy_s` / memmove_s of the last obj (kept alive by the pointers below).
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
MS2_EMIT_CRT_MEMMOVE_S();

// The second obj's copy of the header statics.
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);
