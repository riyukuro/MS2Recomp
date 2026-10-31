// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CooltimeManager, the cooldown gate shared by sounds and
// effects (Table/CooltimeTable.xml: <cooltime cooltimeID cooltimeTick/>), plus the template glue of its two
// std::map<unsigned, unsigned>. Names are invented from use.
// MS2-UNIT: ?\cooltimemanager.cpp
// MS2-RANGE: 0x140a40940-0x140a435a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAIAEAI$0A@@?$pair@II@std@@QEAA@AEAI0@Z 0x140a40e60 ; prop
// MS2-PIN: ??$?0AEAII$0A@@?$pair@II@std@@QEAA@AEAI$$QEAI@Z 0x140a40eb0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@$$QEA_N@Z 0x140a40f00 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140a40f50 ; unique
// MS2-PIN: ??$?0II$0A@@?$pair@$$CBII@std@@QEAA@$$QEAU?$pair@II@1@@Z 0x140a40fa0 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@$$QEA_N@Z 0x140a40ff0 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBII@std@@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBII@1@@Z 0x140a41040 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@II@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@$$QEAU?$pair@II@1@@Z 0x140a41060 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@PEAU01@@Z 0x140a410f0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBII@std@@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@AEAU?$pair@$$CBII@1@1@Z 0x140a41180 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBII@std@@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBII@1@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@@Z 0x140a414e0 ; unique
// MS2-PIN: ??$_Kfn@$$CBII@?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@SAAEBIAEBU?$pair@$$CBII@1@@Z 0x140a418f0 ; prop
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@AEBI@Z 0x140a41900 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@0@AEAPEAU10@@Z 0x140a419a0 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBII@std@@@std@@YAPEAU?$pair@$$CBII@0@AEAU10@@Z 0x140a419b0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@0@AEAV10@@Z 0x140a419c0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@AEAPEAU31@@Z 0x140a419d0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBII@std@@U?$pair@II@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@QEAU?$pair@$$CBII@1@$$QEAU?$pair@II@1@@Z 0x140a41a20 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@@Z 0x140a41a70 ; prop
// MS2-PIN: ??$emplace@U?$pair@II@std@@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@II@1@@Z 0x140a41a90 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@0@AEAPEAU10@@Z 0x140a41b00 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBII@std@@@std@@YAAEAU?$pair@$$CBII@0@AEAU10@@Z 0x140a41b10 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@0@AEAV10@@Z 0x140a41b20 ; prop
// MS2-PIN: ??$forward@I@std@@YA$$QEAIAEAI@Z 0x140a41b30 ; prop
// MS2-PIN: ??$forward@U?$pair@II@std@@@std@@YA$$QEAU?$pair@II@0@AEAU10@@Z 0x140a41b40 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@0@AEAV10@@Z 0x140a41b50 ; prop
// MS2-PIN: ??$insert@U?$pair@II@std@@X@?$map@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@II@1@@Z 0x140a41b60 ; unique
// MS2-PIN: ??$make_pair@AEAIAEAI@std@@YA?AU?$pair@II@0@AEAI0@Z 0x140a41ba0 ; unique
// MS2-PIN: ??$make_pair@AEAII@std@@YA?AU?$pair@II@0@AEAI$$QEAI@Z 0x140a41bf0 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x140a41c90 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x140a41cc0 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@1@@Z 0x140a41d00 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@1@@Z 0x140a41d40 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@1@@Z 0x140a41d80 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAA@XZ 0x140a41dc0 ; unique
// MS2-PIN: ??0?$map@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@@std@@QEAA@XZ 0x140a41e00 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x140a41ea0 ; unique
// MS2-PIN: ??1?$map@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@@std@@QEAA@XZ 0x140a41ed0 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140a41ef0 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140a41f30 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBII@1@XZ 0x140a41f90 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBII@1@XZ 0x140a41fb0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140a41fd0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140a42020 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140a420d0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140a420f0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140a42110 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@XZ 0x140a422c0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@XZ 0x140a42380 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x140a42460 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x140a424a0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x140a424d0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x140a42520 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@@Z 0x140a425c0 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x140a42b70 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x140a42ba0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@XZ 0x140a42bd0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@XZ 0x140a42c00 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@2@XZ 0x140a42c50 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@2@XZ 0x140a42c60 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@2@XZ 0x140a42c70 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@2@XZ 0x140a42c80 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@XZ 0x140a42c90 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@2@XZ 0x140a42cb0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@2@XZ 0x140a42ce0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x140a42d10 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEBAAEBIPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x140a42d50 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEBAAEBIAEBU?$pair@$$CBII@2@@Z 0x140a42d80 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@XZ 0x140a42da0 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x140a42db0 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@PEAU32@@Z 0x140a42e90 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@XZ 0x140a42ef0 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@XZ 0x140a42f10 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x140a42f30 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x140a43010 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@XZ 0x140a430a0 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x140a43110 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@_K@Z 0x140a431b0 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@_K@Z 0x140a431e0 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@XZ 0x140a43210 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@0@Z 0x140a43270 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@@Z 0x140a43360 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@AEBI@Z 0x140a43410 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@AEBI@Z 0x140a434f0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_7CooltimeManager@@6B?$TSingleton@VCooltimeManager@@@@@ 0x142dc6988
// MS2-PIN: ??_7CooltimeManager@@6B?$CValidData@VCooltimeManager@@@@@ 0x142dc6998
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cooltimemanager.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include <vector>
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"

class Unk_140166420 : public CFileSystem { };
Unk_140166420* FUN_140166420();
class Unk_CommonLog { public: void FUN_140177a80(int level, int category, const wchar_t* format, const unsigned& arg); };
Unk_CommonLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
unsigned FUN_140869420();                                   // millisecond clock

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CooltimeManager::s_bInit;
#endif

// @0x140a40940
CooltimeManager::CooltimeManager()
{
    Load();
}

// @0x140a409d0
CooltimeManager::~CooltimeManager()
{
}

// @0x140a40a40
void CooltimeManager::Load()
{
    m_ticks.clear();
    CString strPath = FUN_14071a5b0("Table", "CooltimeTable.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "v", "cooltimeID", &nodes);
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        Unk_140165cf0* pNode = nodes[i];
        unsigned nId = 0;
        unsigned nTick = 0;
        FUN_140873220(pNode, "cooltimeID", nId);
        FUN_1408732a0(pNode, "cooltimeTick", nTick);
        if (nId == 0 || nTick == 0)
            continue;
        m_ticks.insert(std::make_pair(nId, nTick));
    }
    SetInit(true);
}

// @0x140a40ca0
bool CooltimeManager::Use(unsigned nCooltimeId)
{
    std::map<unsigned, unsigned>::iterator itTick = m_ticks.find(nCooltimeId);
    if (itTick == m_ticks.end())
        return true;
    unsigned now = FUN_140869420();
    std::map<unsigned, unsigned>::iterator itReady = m_ready.find(nCooltimeId);
    if (itReady != m_ready.end())
    {
        if (now < itReady->second)
        {
            if (FUN_140166440() != 0)
                FUN_140166440()->FUN_140177a80(0xb, 0x136, L"cooltimeID:{0} Has cooldown", nCooltimeId);
            return false;
        }
        itReady->second = now + itTick->second;
    }
    else
    {
        m_ready.insert(std::make_pair(nCooltimeId, now + itTick->second));
    }
    return true;
}
