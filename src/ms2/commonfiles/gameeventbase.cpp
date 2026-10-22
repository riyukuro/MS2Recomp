// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameEvent, the base class of the server-driven events: the
// event id, the event period (eventStart / eventEnd) and the daily part-time ranges / days of the week that narrow it to
// the current period, the four free-form value strings, the flag bitset. The subclasses (gameevent.cpp) parse the value
// strings (vfunc_2) and start / end the event (vfunc_5 / vfunc_6). The unit also holds the container glue of its
// members: CAtlArray<Unk_DayTimeRange>, std::set<int> and the one-byte bitset (Unk_PartyBits, shared with the party and
// dungeon units).
// MS2-UNIT: commonfiles\gameeventbase.cpp
// MS2-RANGE: 0x1402e1b80-0x1402e6c50 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1402e39c0 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@$$QEA_N@Z 0x1402e39f0 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1402e3a40 ; unique
// MS2-PIN: ??$?0V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@$$QEA_N@Z 0x1402e3a90 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEBH@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@HPEAX@1@U_Not_a_node_tag@1@AEBH@Z 0x1402e3ea0 ; unique
// MS2-PIN: ??$_Buynode@AEBH@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@1@AEBH@Z 0x1402e3ed0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@?$_Tree_node@HPEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@PEAU01@@Z 0x1402e3f60 ; unique
// MS2-PIN: ??$_Insert_at@AEBHU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@_NPEAU?$_Tree_node@HPEAX@1@AEBHU_Not_a_node_tag@1@@Z 0x1402e3ff0 ; unique
// MS2-PIN: ??$_Insert_nohint@AEBHU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@1@_NAEBHU_Not_a_node_tag@1@@Z 0x1402e4350 ; unique
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@HPEAX@1@AEBH@Z 0x1402e4760 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@HPEAX@std@@@std@@YAPEAPEAU?$_Tree_node@HPEAX@0@AEAPEAU10@@Z 0x1402e4800 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@H@std@@@0@AEAV10@@Z 0x1402e4810 ; prop
// MS2-PIN: ??$addressof@H@std@@YAPEAHAEAH@Z 0x1402e4820 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@HPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAPEAU?$_Tree_node@HPEAX@1@AEAPEAU31@@Z 0x1402e4830 ; unique
// MS2-PIN: ??$construct@HAEBH@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAHAEBH@Z 0x1402e4880 ; unique
// MS2-PIN: ??$destroy@H@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAH@Z 0x1402e48d0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@HPEAX@std@@@std@@YAAEAPEAU?$_Tree_node@HPEAX@0@AEAPEAU10@@Z 0x1402e48e0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@AEAV10@@Z 0x1402e48f0 ; prop
// MS2-PIN: ??$forward@AEBU?$less@H@std@@@std@@YAAEBU?$less@H@0@AEBU10@@Z 0x1402e4900 ; prop
// MS2-PIN: ??$forward@AEBH@std@@YAAEBHAEBH@Z 0x1402e4910 ; prop
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@AEAV10@@Z 0x1402e4920 ; prop
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@1@AEBH@Z 0x1402e4930 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x1402e4ad0 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@HPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@1@@Z 0x1402e4b10 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@HPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@1@@Z 0x1402e4b50 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAA@XZ 0x1402e4b90 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@HPEAX@std@@@std@@QEAA@XZ 0x1402e4bc0 ; prop
// MS2-PIN: ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QEAA@XZ 0x1402e4bd0 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA@XZ 0x1402e4ca0 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1402e4e00 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1402e4e40 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAA?AV01@H@Z 0x1402e4f50 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x1402e4fa0 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1402e4fc0 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x1402e5050 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1402e5070 ; unique
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x1402e5140 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@XZ 0x1402e5710 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@XZ 0x1402e57d0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1402e58b0 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXXZ 0x1402e58f0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXU_Not_a_node_tag@2@@Z 0x1402e5920 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x1402e5930 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@@Z 0x1402e59d0 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x1402e5f80 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x1402e5fb0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x1402e5fe0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x1402e6010 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x1402e6050 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x1402e6060 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x1402e6070 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@XZ 0x1402e6080 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@XZ 0x1402e6090 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x1402e60a0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x1402e60b0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x1402e60c0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x1402e60f0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x1402e6120 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x1402e6140 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@HPEAX@2@@Z 0x1402e6160 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBAAEBHAEBH@Z 0x1402e6190 ; unique
// MS2-PIN: ?_Kfn@?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@SAAEBHAEBH@Z 0x1402e61b0 ; prop
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEBAAEAPEAU?$_Tree_node@HPEAX@2@XZ 0x1402e61c0 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x1402e61d0 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@SAPEAU?$_Tree_node@HPEAX@2@PEAU32@@Z 0x1402e62b0 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@SAPEAU?$_Tree_node@HPEAX@2@PEAU32@@Z 0x1402e62e0 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEBAAEAPEAU?$_Tree_node@HPEAX@2@XZ 0x1402e6310 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEBAAEAPEAU?$_Tree_node@HPEAX@2@XZ 0x1402e6330 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x1402e6350 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXXZ 0x1402e6430 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@HPEAX@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@_K@Z 0x1402e6480 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@XZ 0x1402e64b0 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXXZ 0x1402e6520 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@QEAU?$_Tree_node@HPEAX@2@_K@Z 0x1402e65c0 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@HPEAX@std@@@std@@QEAAXQEAU?$_Tree_node@HPEAX@2@_K@Z 0x1402e65f0 ; prop
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_NXZ 0x1402e6620 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@XZ 0x1402e6660 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@V32@0@Z 0x1402e66c0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@V32@@Z 0x1402e67b0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@AEBH@Z 0x1402e6860 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@AEBH@Z 0x1402e6940 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@HPEAX@std@@@2@@Z 0x1402e69a0 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_KXZ 0x1402e69b0 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_KXZ 0x1402e6af0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventbase.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include <set>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The TinyXML attribute readers (commonfiles\xmldata).
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, int& rOut);
int FUN_140873420(Unk_140165cf0* pElem, const char* pszName, CStringW& rOut);
int FUN_140873600(Unk_140165cf0* pElem, const char* pszName, CMsTime& rOut);
// The string splitters (commonstringtable.cpp / chapterbooktable.cpp).
void FUN_14025a680(const CStringW& text, ATL::CAtlArray<CStringW>& tokens, const wchar_t* pszDelims);
void FUN_1401d9a30(const CStringW& text, ATL::CAtlArray<int>& values, const wchar_t* pszDelims);

// @0x1402e1b80
GameEvent::GameEvent()
    : m_id(0), m_48(0), m_58(0), m_88(0), m_bValid(false)
{
}

// @0x1402e1d00
int GameEvent::FUN_1402e1d00() { return m_id; }

// @0x1402e1d20
bool GameEvent::Init(int id, const CMsTime& start, const CMsTime& end, const CStringW& value1, const CStringW& value2,
                     const CStringW& value3, const CStringW& value4, const CStringW& partTime,
                     const CStringW& dayOfWeek, int type)
{
    m_id = id;
    m_28 = start;
    m_38 = end;
    m_68 = value1;
    m_70 = value2;
    m_78 = value3;
    m_80 = value4;
    m_90 = partTime;
    m_b8 = dayOfWeek;
    m_88 = type;
    m_68.Trim();
    m_70.Trim();
    m_78.Trim();
    m_80.Trim();
    m_90.Trim();
    m_b8.Trim();
    if (!ParsePartTime(m_90, m_98))
        return false;
    if (!ParseDayOfWeek(m_b8, m_c0))
        return false;
    SetValid(true);
    CMsTime now(GetServerTime());
    UpdatePeriod(now);
    vfunc_2();
    return true;
}
MS2_REPLACE_METHOD(0x1402E1D00, GameEvent, FUN_1402e1d00, 14, 0x72E52537);

// @0x1402e1f40
bool GameEvent::LoadXml(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "gameEventID", m_id);
    FUN_140873600(pElem, "eventStart", m_28);
    FUN_140873600(pElem, "eventEnd", m_38);
    FUN_140873420(pElem, "value1", m_68);
    FUN_140873420(pElem, "value2", m_70);
    FUN_140873420(pElem, "value3", m_78);
    FUN_140873420(pElem, "value4", m_80);
    FUN_140873420(pElem, "partTime", m_90);
    FUN_140873420(pElem, "dayOfWeek", m_b8);
    m_88 = 0;
    m_68.Trim();
    m_70.Trim();
    m_78.Trim();
    m_80.Trim();
    m_90.Trim();
    m_b8.Trim();
    if (!ParsePartTime(m_90, m_98))
        return false;
    if (!ParseDayOfWeek(m_b8, m_c0))
        return false;
    SetValid(true);
    CMsTime now(GetServerTime());
    UpdatePeriod(now);
    vfunc_2();
    return true;
}
MS2_REPLACE_METHOD(0x1402E1F40, GameEvent, LoadXml, 578, 0x76E7150A);

// @0x1402e2190
void GameEvent::vfunc_3(Unk_GEOut* out)
{
    out->WriteInt(m_id);
}
MS2_REPLACE_METHOD(0x1402E2190, GameEvent, vfunc_3, 43, 0xDBE60025);

// @0x1402e21d0
void GameEvent::vfunc_4(Unk_GEIn* in)
{
    m_id = MS2_GE_READ_INT(in);
}
MS2_REPLACE_METHOD(0x1402E21D0, GameEvent, vfunc_4, 61, 0x3103CED6);

// @0x1402e2220
void GameEvent::vfunc_7(MS2Ptr<GameEvent> spPrev)
{
    if (spPrev.get())
        spPrev->vfunc_6();
    OnStart();
}
MS2_REPLACE_METHOD(0x1402E2220, GameEvent, vfunc_7, 101, 0xA9EA75F4);

// @0x1402e2290
bool GameEvent::HasFlag(int kind)
{
    return m_flags.FUN_1402e4ee0(kind);
}
MS2_REPLACE_METHOD(0x1402E2290, GameEvent, HasFlag, 41, 0xDB1D8834);

// @0x1402e22c0
bool GameEvent::IsInEventTime(const CMsTime& now)
{
    return (m_bValid == true && IsInEventRange(now)) ? 1 : 0;
}
MS2_REPLACE_METHOD(0x1402E22C0, GameEvent, IsInEventTime, 81, 0xE518C025);

// @0x1402e2320
bool GameEvent::IsInPeriodTime(const CMsTime& now)
{
    if (!IsInEventTime(now))
        return false;
    return IsInPeriodRange(now);
}
MS2_REPLACE_METHOD(0x1402E2320, GameEvent, IsInPeriodTime, 60, 0x7A6FE9C4);

// @0x1402e2370
bool GameEvent::IsInEventRange(const CMsTime& now)
{
    return (m_28 <= now && now < m_38) ? 1 : 0;
}
MS2_REPLACE_METHOD(0x1402E2370, GameEvent, IsInEventRange, 100, 0x1BBD5F9C);

// @0x1402e23e0
bool GameEvent::IsInPeriodRange(const CMsTime& now)
{
    return (m_48 <= now && now < m_58) ? 1 : 0;
}
MS2_REPLACE_METHOD(0x1402E23E0, GameEvent, IsInPeriodRange, 100, 0x2F998104);

// @0x1402e2450
bool GameEvent::HasTimeRestriction()
{
    return (m_90.IsEmpty() && m_b8.IsEmpty()) ? 0 : 1;
}
MS2_REPLACE_METHOD(0x1402E2450, GameEvent, HasTimeRestriction, 91, 0x871ED604);

// @0x1402e24c0
void GameEvent::SetValid(bool bValid)
{
    m_bValid = bValid;
}
MS2_REPLACE_METHOD(0x1402E24C0, GameEvent, SetValid, 26, 0x1A27417E);

// @0x1402e24e0
void GameEvent::SetName(const CStringW& name)
{
    m_20 = name;
}
MS2_REPLACE_METHOD(0x1402E24E0, GameEvent, SetName, 42, 0xA384A5D3);

// @0x1402e2510
CStringW GameEvent::GetName()
{
    return m_20;
}
MS2_REPLACE_METHOD(0x1402E2510, GameEvent, GetName, 66, 0x00B1AB47);

// @0x1402e2560
int GameEvent::GetType()
{
    return m_88;
}
MS2_REPLACE_METHOD(0x1402E2560, GameEvent, GetType, 17, 0x3F39D72B);

// @0x1402e2580
bool GameEvent::vfunc_9(void* other)
{
    if (m_28 != static_cast<GameEvent*>(other)->m_28)
        return true;
    if (m_38 != static_cast<GameEvent*>(other)->m_38)
        return true;
    if (m_68 != static_cast<GameEvent*>(other)->m_68)
        return true;
    if (m_70 != static_cast<GameEvent*>(other)->m_70)
        return true;
    if (m_78 != static_cast<GameEvent*>(other)->m_78)
        return true;
    if (m_80 != static_cast<GameEvent*>(other)->m_80)
        return true;
    if (m_90 != static_cast<GameEvent*>(other)->m_90)
        return true;
    if (m_b8 != static_cast<GameEvent*>(other)->m_b8)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1402E2580, GameEvent, vfunc_9, 347, 0xD456B33B);

// @0x1402e26f0
CMsTime GameEvent::FUN_1402e26f0()
{
    return m_28;
}
MS2_REPLACE_METHOD(0x1402E26F0, GameEvent, FUN_1402e26f0, 46, 0xCED5C19B);

// @0x1402e2730
CMsTime GameEvent::FUN_1402e2730()
{
    return m_38;
}
MS2_REPLACE_METHOD(0x1402E2730, GameEvent, FUN_1402e2730, 46, 0xDA54068B);

// @0x1402e2770
void GameEvent::UpdatePeriod(const CMsTime& now)
{
    if (!IsInEventTime(now))
        return;
    if (IsInPeriodRange(now) == true)
        return;
    if (!HasTimeRestriction()) {
        m_48 = FUN_1402e26f0();
        m_58 = FUN_1402e2730();
        return;
    }
    if (now < m_48)
        return;
    bool bDays = (!m_c0.empty() && m_c0.size() < 7) ? 1 : 0;
    bool bTimes = !m_98.IsEmpty() ? 1 : 0;
    CMsTime start;
    CMsTime end;
    if (bTimes) {
        Unk_DayTime nowTime(now.GetHour(), now.GetMinute(), now.GetSecond());
        bool bFound = false;
        Unk_DayTimeRange cur;
        for (UINT i = 0; i < m_98.GetCount(); i++) {
            if (nowTime < m_98[i].m_end) {
                bFound = true;
                cur = m_98[i];
                break;
            }
        }
        if (bFound) {
            Unk_DayTime from = cur.m_start;
            Unk_DayTime to = cur.m_end;
            start = CMsTime(now.GetYear(), now.GetMonth(), now.GetDay(), from.GetHour(), from.GetMinute(),
                            from.GetSecond());
            end = CMsTime(now.GetYear(), now.GetMonth(), now.GetDay(), to.GetHour(), to.GetMinute(),
                          to.GetSecond());
        } else {
            Unk_DayTime from = m_98[0].m_start;
            Unk_DayTime to = m_98[0].m_end;
            CMsTime tomorrow = AddByUnit(0, now, 1);
            start = CMsTime(tomorrow.GetYear(), tomorrow.GetMonth(), tomorrow.GetDay(), from.GetHour(),
                            from.GetMinute(), from.GetSecond());
            end = CMsTime(tomorrow.GetYear(), tomorrow.GetMonth(), tomorrow.GetDay(), to.GetHour(),
                          to.GetMinute(), to.GetSecond());
        }
    }
    if (bDays) {
        if (bTimes) {
            int dayOfWeek = start.GetDayOfWeek();
            if (m_c0.find(dayOfWeek) == m_c0.end()) {
                AddDays(start, 1);
                for (int i = 0; i < 7; i++) {
                    int day = start.GetDayOfWeek();
                    if (m_c0.find(day) != m_c0.end())
                        break;
                    AddDays(start, 1);
                }
                Unk_DayTime from = m_98[0].m_start;
                Unk_DayTime to = m_98[0].m_end;
                start = CMsTime(start.GetYear(), start.GetMonth(), start.GetDay(), from.GetHour(),
                                from.GetMinute(), from.GetSecond());
                end = CMsTime(start.GetYear(), start.GetMonth(), start.GetDay(), to.GetHour(),
                              to.GetMinute(), to.GetSecond());
            }
        } else {
            start = CMsTime(now.GetYear(), now.GetMonth(), now.GetDay(), 0, 0, 0);
            for (int i = 0; i < 7; i++) {
                int day = start.GetDayOfWeek();
                if (m_c0.find(day) != m_c0.end())
                    break;
                AddDays(start, 1);
            }
            end = AddByUnit(0, start, 1);
            for (int i = 0; i < 7; i++) {
                int day = end.GetDayOfWeek();
                if (m_c0.find(day) == m_c0.end())
                    break;
                AddDays(end, 1);
            }
        }
    }
    SetPeriod(start, end);
}
MS2_REPLACE_METHOD(0x1402E2770, GameEvent, UpdatePeriod, 2865, 0xCC5C4BCF);

// @0x1402e32b0
void GameEvent::SetPeriod(const CMsTime& start, const CMsTime& end)
{
    if (start > end) {
        MS2_ASSERT_AT(316, FALSE);
    } else {
        m_48 = (std::max)(start.Get(), FUN_1402e26f0().Get());
        m_58 = (std::min)(end.Get(), FUN_1402e2730().Get());
    }
}
MS2_REPLACE_METHOD(0x1402E32B0, GameEvent, SetPeriod, 241, 0x88082BDD);

// @0x1402e33b0
CMsTime GameEvent::GetPeriodBegin()
{
    return m_48;
}
MS2_REPLACE_METHOD(0x1402E33B0, GameEvent, GetPeriodBegin, 46, 0x1FC43196);

// @0x1402e33f0
CMsTime GameEvent::GetPeriodEnd()
{
    return m_58;
}
MS2_REPLACE_METHOD(0x1402E33F0, GameEvent, GetPeriodEnd, 46, 0x9EE10DA6);

// @0x1402e3430
void GameEvent::SetEventRange(const CMsTime& start, const CMsTime& end)
{
    m_28 = start;
    m_38 = end;
}
MS2_REPLACE_METHOD(0x1402E3430, GameEvent, SetEventRange, 68, 0x92925337);

// @0x1402e3480
void GameEvent::FUN_1402e3480(int kind)
{
    m_flags[kind] = true;
}
MS2_REPLACE_METHOD(0x1402E3480, GameEvent, FUN_1402e3480, 57, 0x049C4D57);

// @0x1402e34c0
CStringW GameEvent::GetValuesText()
{
    CStringW text = StringFormat(L"v1={0} v2={1} v3={2} v4={3}", m_68, m_70, m_78, m_80);
    return text;
}
MS2_REPLACE_METHOD(0x1402E34C0, GameEvent, GetValuesText, 148, 0x74C05AB7);

// @0x1402e3560
bool GameEvent::ParsePartTime(const CStringW& text, ATL::CAtlArray<Unk_DayTimeRange>& ranges)
{
    ranges.RemoveAll();
    if (text.IsEmpty())
        return true;
    {
        Unk_DayTime zero(0, 0, 0);
        ATL::CAtlArray<CStringW> tokens;
        FUN_14025a680(text, tokens, L",");
        for (int i = 0; i < (int)tokens.GetCount(); i++) {
            CStringW& token = tokens[i];
            ATL::CAtlArray<CStringW> parts;
            FUN_14025a680(token, parts, L"-");
            if (parts.GetCount() != 2) {
                MS2_ASSERT_AT(386, FALSE);
                return false;
            }
            CStringW& left = parts[0];
            CStringW& right = parts[1];
            Unk_DayTime from;
            Unk_DayTime to;
            if (!from.Parse(left) || !to.Parse(right)) {
                MS2_ASSERT_AT(398, FALSE);
                return false;
            }
            if (from > to || from < zero) {
                MS2_ASSERT_AT(404, FALSE);
                return false;
            }
            ranges.Add(Unk_DayTimeRange(from, to));
        }
    return true;
    }
}
MS2_REPLACE_METHOD(0x1402E3560, GameEvent, ParsePartTime, 675, 0xB1113E01);

// @0x1402e3810
bool GameEvent::ParseDayOfWeek(const CStringW& text, std::set<int>& days)
{
    days.clear();
    if (text.IsEmpty())
        return true;
    {
        ATL::CAtlArray<int> values;
        FUN_1401d9a30(text, values, L",");
        for (int i = 0; i < (int)values.GetCount(); i++) {
            int day = values[i];
            if (day < 1 || 7 < day) {
                MS2_ASSERT_AT(429, FALSE);
                return false;
            }
            if (days.find(day) != days.end()) {
                MS2_ASSERT_AT(435, FALSE);
                return false;
            }
            days.insert(day);
        }
    return true;
    }
}
MS2_REPLACE_METHOD(0x1402E3810, GameEvent, ParseDayOfWeek, 426, 0x51DA1919);

// @0x1402e4c00
Unk_PartyBitRef::Unk_PartyBitRef(Unk_Bitset8* pBits, int nPos) : m_pBits(pBits), m_nPos(nPos)
{
}

// @0x1402e6bb0
void Unk_Bitset8::Fill(bool bFill)
{
    for (int i = 0; i >= 0; i--)
        m_bits[i] = bFill;
    if (bFill)
        ClearUnusedBits();
}
MS2_REPLACE_METHOD(0x1402E6BB0, Unk_Bitset8, Fill, 84, 0x35672ED1);

// @0x1402e6c10
void Unk_Bitset8::ClearUnusedBits()
{
    if (8 % 8 != 0)
        return;
    m_bits[(8 - 1) / 8] &= (1 << (8 % 8)) - 1;
}
MS2_REPLACE_METHOD(0x1402E6C10, Unk_Bitset8, ClearUnusedBits, 52, 0x76B31891);

// @0x1402e4e80
Unk_PartyBitRef Unk_Bitset8::operator[](int nPos)
{
    MS2_PARTYBITS_ASSERT(152, UINT(nPos) < UINT(8));
    return Unk_PartyBitRef(this, nPos);
}

// @0x1402e69d0
Unk_Bitset8& Unk_Bitset8::Set(unsigned nPos, bool bValue)
{
    if (nPos >= 8) { MS2_PARTYBITS_ASSERT(243, 0); }
    if (bValue)
        m_bits[(int)nPos / 8] |= 1 << ((int)nPos % 8);
    else
        m_bits[(int)nPos / 8] &= ~(1 << ((int)nPos % 8));
    return *this;
}
MS2_REPLACE_METHOD(0x1402E69D0, Unk_Bitset8, Set, 286, 0x6ABCC652);

// @0x1402e6b10
bool Unk_Bitset8::Test(unsigned nPos) const
{
    if (nPos >= 8) { MS2_PARTYBITS_ASSERT(404, 0); return false; }
    return (m_bits[(int)nPos / 8] & (1 << ((int)nPos % 8))) != 0;
}
MS2_REPLACE_METHOD(0x1402E6B10, Unk_Bitset8, Test, 159, 0x531283CE);

// @0x1402e4dc0
Unk_PartyBitRef& Unk_PartyBitRef::operator=(bool bValue)
{
    m_pBits->Set(m_nPos, bValue);
    return *this;
}

// @0x1402e4ee0
bool Unk_PartyBits::FUN_1402e4ee0(int nPos)
{
    return Test(nPos);
}
MS2_REPLACE_METHOD(0x1402E4EE0, Unk_PartyBits, FUN_1402e4ee0, 32, 0x3522FD57);

// @0x1402e49d0
Unk_PartyBits::Unk_PartyBits()
{
    Fill(false);
}

// @0x1402e4cf0
// MS2-FUNCTIONAL: the exe destructor stores no vftable pointer (the original GameEvent is probably __declspec(novtable)); gameevent.h is shared
GameEvent::~GameEvent()
{
}

// @0x1402e5510
#pragma warning(push)
#pragma warning(disable : 4716)
int GameEvent::vfunc_8()
{
}
MS2_REPLACE_METHOD(0x1402E5510, GameEvent, vfunc_8, 6, 0xA9AF6E37);
#pragma warning(pop)
