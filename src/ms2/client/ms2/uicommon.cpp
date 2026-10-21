// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's uicommon.cpp: UI helpers shared by many dialogs
// (wallet / currency checks and their texts, the key-block counters of the main PC, the dialog alignment record).
// MS2-UNIT: client\ms2\uicommon.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x1418fcee0-0x141905eb0 .text$mn
// MS2-RANGE: 0x1401117c0-0x1401119b0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141902eb0 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@0@Z 0x141902ee0 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@$$QEA_N@Z 0x141902f30 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141902f80 ; unique
// MS2-PIN: ??$?0V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@$$QEA_N@Z 0x141902fd0 ; prop
// MS2-PIN: ??$FormatStringId@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBV01@0@Z 0x1419033e0 ; unique
// MS2-FUNCTIONAL ??$FormatStringId@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBV01@0@Z: bytes equal the exe; its MakeValue/ArgType callees bind to the exe's ICF-folded copies (0x140163740 MakeValue<wide formatter>, 0x1401cee00 ArgType<CString>) while FMT_VARIADIC_W instantiates MakeValue<BasicFormatter<wchar_t>> 0x1401cfcf0 / ArgType<CStringW> 0x1401cee30 - linker folding, not a type error
// MS2-PIN: ??$_Buy_if_not_node@AEBH@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@HPEAX@1@U_Not_a_node_tag@1@AEBH@Z 0x1419036f0 ; unique
// MS2-PIN: ??$_Buynode@AEBH@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@1@AEBH@Z 0x141903720 ; unique
// MS2-PIN: ??$_Distance1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x1419037b0 ; unique
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@1@AEBH@Z 0x141903810 ; unique
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@1@AEBH@Z 0x1419038a0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@?$_Tree_node@HPEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@PEAU01@@Z 0x141903ae0 ; unique
// MS2-PIN: ??$_Insert_at@AEBHU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@_NPEAU?$_Tree_node@HPEAX@1@AEBHU_Not_a_node_tag@1@@Z 0x141903b70 ; unique
// MS2-PIN: ??$_Insert_nohint@AEBHU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@1@_NAEBHU_Not_a_node_tag@1@@Z 0x141903ed0 ; unique
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@HPEAX@1@AEBH@Z 0x1419042e0 ; unique
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@0@AEBV10@@Z 0x141904380 ; prop
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@HPEAX@std@@@std@@YAPEAPEAU?$_Tree_node@HPEAX@0@AEAPEAU10@@Z 0x141904390 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@H@std@@@0@AEAV10@@Z 0x1419043a0 ; prop
// MS2-PIN: ??$addressof@H@std@@YAPEAHAEAH@Z 0x1419043b0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@HPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAPEAU?$_Tree_node@HPEAX@1@AEAPEAU31@@Z 0x1419043c0 ; unique
// MS2-PIN: ??$construct@HAEBH@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAHAEBH@Z 0x141904410 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@HPEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAPEAU?$_Tree_node@HPEAX@1@@Z 0x141904450 ; prop
// MS2-PIN: ??$distance@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@0@Z 0x141904470 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@HPEAX@std@@@std@@YAAEAPEAU?$_Tree_node@HPEAX@0@AEAPEAU10@@Z 0x1419044a0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@AEAV10@@Z 0x1419044b0 ; prop
// MS2-PIN: ??$forward@AEBU?$less@H@std@@@std@@YAAEBU?$less@H@0@AEBU10@@Z 0x1419044c0 ; prop
// MS2-PIN: ??$forward@AEBH@std@@YAAEBHAEBH@Z 0x1419044d0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@AEAV10@@Z 0x1419044e0 ; prop
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@1@AEBH@Z 0x1419044f0 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141904560 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@HPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@1@@Z 0x1419045a0 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@HPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@1@@Z 0x1419045e0 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAA@XZ 0x141904620 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@HPEAX@std@@@std@@QEAA@XZ 0x141904650 ; prop
// MS2-PIN: ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QEAA@XZ 0x141904660 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA@XZ 0x1419046c0 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141904730 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141904770 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAA?AV01@H@Z 0x1419047c0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x141904810 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141904830 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x1419048c0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1419048e0 ; unique
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x1419049b0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@XZ 0x141904b30 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@XZ 0x141904bf0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141904cd0 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXXZ 0x141904d10 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXU_Not_a_node_tag@2@@Z 0x141904d40 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x141904d50 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@@Z 0x141904df0 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x1419053a0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x1419053d0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x141905400 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x141905430 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141905460 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x141905470 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x141905480 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x141905490 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@XZ 0x1419054a0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x1419054c0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x1419054d0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x1419054e0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x141905510 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x141905540 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x141905560 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@HPEAX@2@@Z 0x141905580 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBAAEBHAEBH@Z 0x1419055b0 ; unique
// MS2-PIN: ?_Kfn@?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@SAAEBHAEBH@Z 0x1419055d0 ; prop
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEBAAEAPEAU?$_Tree_node@HPEAX@2@XZ 0x1419055e0 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x1419055f0 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@SAPEAU?$_Tree_node@HPEAX@2@PEAU32@@Z 0x1419056d0 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@SAPEAU?$_Tree_node@HPEAX@2@PEAU32@@Z 0x141905700 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEBAAEAPEAU?$_Tree_node@HPEAX@2@XZ 0x141905730 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEBAAEAPEAU?$_Tree_node@HPEAX@2@XZ 0x141905750 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x141905770 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXXZ 0x141905850 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@HPEAX@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@_K@Z 0x1419058a0 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@XZ 0x1419058d0 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXXZ 0x141905940 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@QEAU?$_Tree_node@HPEAX@2@_K@Z 0x1419059e0 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@HPEAX@std@@@std@@QEAAXQEAU?$_Tree_node@HPEAX@2@_K@Z 0x141905a10 ; prop
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_NXZ 0x141905a40 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@XZ 0x141905a80 ; unique
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@2@AEBH@Z 0x141905ae0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@V32@0@Z 0x141905b20 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@V32@@Z 0x141905c10 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA_KAEBH@Z 0x141905cc0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@AEBH@Z 0x141905d20 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@AEBH@Z 0x141905e00 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@HPEAX@std@@@2@@Z 0x141905e60 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_KXZ 0x141905e70 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_KXZ 0x141905e90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_pointer1401cd100@@YAXXZ 0x140111910
// MS2-PIN: ??_GCAlignmentInfo@UICommon@@UEAAPEAXI@Z 0x1419049f0
// MS2-PIN: ?get@?$MS2Ptr@VCItem@@@@QEBAPEAVCItem@@XZ 0x1419047b0
// MS2-PIN: ??$StringFormat@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV12@V12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBV01@AEBH11@Z 0x141903020
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicommon.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <shellapi.h>
#include <shlwapi.h>
#include <set>
#include "uicommon.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/clubcli.h"
#include "ms2/client/ms2/uiclubdialog.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/client/ms2/networkservice.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/cpartymember.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The unit's statics: "gameexit", then the shared header statics (a pointer handle sits between "stun" and the
// condition), then the key-block controller.
static CStringW s_strGameExit = L"gameexit";                       // @0x1401117c0
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uichatballoon_ptr.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
static UICommon::CMyPCKeyInputController s_keyInput;               // @0x140111980

// ---- globals of the exe (bound by the DAT_ names) ----
extern __int64 DAT_143ab2820;                                       // the local player's character id
extern __int64 DAT_143ab2898;                                       // wallet: meso
extern __int64 DAT_143ab28b0;                                       // wallet: merat / honor / treva / lu ... (see FUN_1418ff1f0)
extern __int64 DAT_143ab28b8;
extern __int64 DAT_143ab28c0;
extern __int64 DAT_143ab28c8;
extern __int64 DAT_143ab28d0;
extern __int64 DAT_143ab28d8;
extern __int64 DAT_143ab28e0;
extern __int64 DAT_143ab28e8;
extern __int64 DAT_143ab28f0;
extern int DAT_143ab0248;                                           // client region (2 = the global build)
extern int DAT_1439f4a7c;
extern CStringW DAT_143af1c18;
extern int DAT_143b059e8;

// ---- out-of-unit types and callees ----
class MyPC;
class CMsgBoxData : public CPtred
{
public:
    template <class T> void Append(T v);                            // 0x140533ff0 (int) / 0x1405340b0 (__int64)
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb);
    void FUN_141a024a0(bool b);
    __int64 FUN_141a02f10(int nIndex, int nDefault) const;
private:
    unsigned char m_pad[0x2a0 - sizeof(CPtred)];
};
template <> void CMsgBoxData::Append<int>(int);
template <> void CMsgBoxData::Append<__int64>(__int64);
typedef Delegate<bool(int, const CMsgBoxData&)> Unk_UcMsgCallback;
typedef MS2Ptr<CMsgBoxData> Unk_UcMsgBoxPtr;
Unk_UcMsgBoxPtr FUN_140d73d20(int nType, CStringW text, void* p, CStringW tag);
void FUN_140d73c60(Unk_UcMsgBoxPtr box);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
CStringW FUN_1409eec40(int nStrId);                                 // string table text
CStringW FUN_14052bd00(int nStrId, const CStringW& a1);
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_14028de60(int nStrId);
CStringW FUN_140292a70(const wchar_t* szFormat, const unsigned int& n0);
CStringW FUN_1409404f0(__int64 n);                                  // the number as text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_1409e9890(CStringW strKey, const unsigned& a0, const unsigned& a1);
CStringW FUN_1412e7c20(int nStrId, const CStringW& a0, const int& a1);   // FormatStringId<CStringW, int>
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a0);
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a0, const CStringW& a1);
CStringW FUN_140763a90(const wchar_t* szFormat, const CStringW& a0, const int& a1, const CStringW& a2);
CString FUN_140298360(const char* szPrefix, const CString& str);
void FUN_141275260(int nStrId, int a, int b);                       // system message by string id
void FUN_1412751f0(const CStringW& strText, int a, int b);
void FUN_14135ec00(void* pBrowser, const CString& strUrl, bool b);
void* FUN_140c43790(int nUiId);

// The wide-string formatter with a leading string id (0x14028dee0), instantiated here for <CStringW, CString>.
CStringW FormatStringId(int id, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FormatStringId, int)

// The cube / housing service (singleton behind 0x1409670e0; also the object behind the COM-style reference to 0x143b059e8).
class Unk_UcCubeSvc
{
public:
    __int64 FUN_1410c3180();                                        // owner id of the current plot (0 outside)
    CStringW FUN_1410c31d0();                                       // owner name of the current plot
    int FUN_1410c3140();
    int FUN_1410c3100();
    int FUN_1410c3000();
    int FUN_1410c3650();
    int FUN_1410b9b20(int nItemId);
    int FUN_1410b9c20(int nItemId, int nRank);
    __int64 FUN_1410b9d80(__int64 nUid);
    int FUN_1410d2f10();
    bool FUN_1410c35c0();
};
Unk_UcCubeSvc* FUN_1409670e0();
int FUN_140930190();
class Unk_UcGridRef                                                 // CComPtrBase<> over the cube service
{
public:
    Unk_UcGridRef(Unk_UcCubeSvc* p) : m_p(p) {}
    ~Unk_UcGridRef();                                               // 0x1401cd150
    void* FUN_140885310();                                          // the service, tested for null
    Unk_UcCubeSvc* FUN_1401cd1a0();                                 // the service
    Unk_UcCubeSvc* m_p;
};
Unk_UcCubeSvc* FUN_1401cd040(int* p);
void FUN_1401cd150(Unk_UcGridRef* p);
Unk_UcGridRef::~Unk_UcGridRef() { FUN_1401cd150(this); }

// The map data kept behind the world's counted pointer (field +0x5c: the max player count?).
class Unk_UcMapData : public CPtred
{
public:
    void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38; void* m_pad_40;
    void* m_pad_48; void* m_pad_50;
    int m_nField58;
    int m_nField5c;
};
MS2_CHECK_OFFSET(Unk_UcMapData, m_nField5c, 0x5c);

// The character's info record (a stat holder behind the actor).
class Unk_UcPCInfo
{
public:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
    int m_pad_18;
    int m_nField1c;
};
MS2_CHECK_OFFSET(Unk_UcPCInfo, m_nField1c, 0x1c);

// The local player and other actors (free callees taking the actor).
__int64 FUN_141656a80(PCBase* p);                                   // character id
__int64 FUN_141656ad0(PCBase* p);
int FUN_14166ce30(PCBase* p);
int FUN_141659690(PCBase* p);
int FUN_141527160(MyPC* p, int nFlag);
int FUN_141527e00(MyPC* p);
int FUN_14152e950(MyPC* p);
Unk_UcPCInfo* FUN_141523c50(MyPC* p);
void FUN_141529c80(MyPC* p, int a, int b, int c, __int64 nId, CStringW strText);
bool FUN_140374410(int nMapId);

WorldService* FUN_1403ed2d0();

// The user report record (ctor 0x140c74fc0, 0x118 bytes) and its counted reference.
class CUserReportData : public CPtred
{
public:
    CUserReportData(int nType);                                     // 0x140c74fc0
    void FUN_140ec3c70(int nKind);
    void FUN_140ec3c90(__int64 nTargetId);
    void FUN_140ec3d40(CStringW strTargetName);                     // by value: the callee destroys it
    void FUN_140ec3e00(CStringW strReporterName);
    void FUN_141904a90(int n);                                      // @0x141904a90
    void FUN_141904af0(int n);                                      // @0x141904af0
    void FUN_141904b10(__int64 n);                                  // @0x141904b10
    MS2_LAYOUT_FRIEND;
private:
    void* m_pad_18; void* m_pad_20; void* m_pad_28;
    void* m_pad_30; void* m_pad_38; void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58;
    void* m_pad_60;
    __int64 m_68;
    int m_70;
    int m_74;
    void* m_pad_78; void* m_pad_80; void* m_pad_88; void* m_pad_90; void* m_pad_98; void* m_pad_a0;
    void* m_pad_a8; void* m_pad_b0; void* m_pad_b8; void* m_pad_c0; void* m_pad_c8; void* m_pad_d0;
    void* m_pad_d8; void* m_pad_e0; void* m_pad_e8; void* m_pad_f0; void* m_pad_f8; void* m_pad_100;
    void* m_pad_108; void* m_pad_110;
};
MS2_CHECK_SIZE(CUserReportData, 0x118);
MS2_CHECK_OFFSET(CUserReportData, m_68, 0x68);
MS2_CHECK_OFFSET(CUserReportData, m_74, 0x74);

// @0x1418fcee0
// Report the owner of the plot the player stands on (type 4, kind 2).
int FUN_1418fcee0()
{
    __int64 nOwner = FUN_1409670e0()->FUN_1410c3180();
    CStringW strOwner = FUN_1409670e0()->FUN_1410c31d0();
    if (nOwner == 0 || nOwner == DAT_143ab2820)
        return 0;
    MS2Ptr<CUserReportData> spReport(new CUserReportData(4));
    spReport->FUN_140ec3c70(2);
    spReport->FUN_141904b10(nOwner);
    spReport->FUN_140ec3e00(strOwner);
    spReport->FUN_141904a90(0);
    spReport->FUN_141904af0(0);
    spReport->FUN_140ec3c90(nOwner);
    spReport->FUN_140ec3d40(strOwner);
    FUN_140d86260()->vfunc_48(spReport);
    return 1;
}
MS2_REPLACE(0x1418fcee0, FUN_1418fcee0, 575, 0x37AB585C);

// @0x1418fd130
int FUN_1418fd130()
{
    if (FUN_140930190() == 0)
    {
        if (FUN_140374410(FUN_1403ed2d0()->FUN_141bd3060()))
        {
            __int64 nOwner = FUN_1409670e0()->FUN_1410c3180();
            if (nOwner != 0 && nOwner != DAT_143ab2820)
            {
                FUN_140d73aa0(FUN_1409eec40(0xb14), 1, 0, DAT_143af1c18);
                return 1;
            }
        }
    }
    else
    {
        FUN_140d73aa0(FUN_1409eec40(0x6df), 0, 0, CStringW(L""));
    }
    return 0;
}
MS2_REPLACE(0x1418fd130, FUN_1418fd130, 321, 0xF0C00958);

// @0x1418fd280
int FUN_1418fd280()
{
    if (DAT_143ab2820 == 0)
        return 0;
    if (FUN_1409670e0()->FUN_1410c3180() == DAT_143ab2820)
        return 1;
    return 0;
}
MS2_REPLACE(0x1418fd280, FUN_1418fd280, 54, 0x87D9BB8C);

// @0x1418fd2c0
int FUN_1418fd2c0()
{
    if (FUN_1409670e0()->FUN_1410c3180() == 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x1418fd2c0, FUN_1418fd2c0, 36, 0x67A6D87B);

// @0x1418fd2f0
int FUN_1418fd2f0()
{
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    if (FUN_140374410(nMapId))
        return 1;
    return 0;
}
MS2_REPLACE(0x1418fd2f0, FUN_1418fd2f0, 51, 0x4EE65DC8);

// @0x1418fd330
// Can the player act on the plot of nOwner? Posts the reason when not.
int FUN_1418fd330(__int64 nOwner)
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (FUN_141656a80(pPC) == nOwner)
        return 0;
    if (FUN_14166ce30(pPC) != 0)
    {
        FUN_141275260(0x87a, 1, 0);
        return 0;
    }
    int nValue;
    Unk_UcGridRef grid(FUN_1401cd040(&DAT_143b059e8));
    if (grid.FUN_140885310() != 0 && grid.FUN_1401cd1a0()->FUN_1410d2f10() != 0 && !grid.FUN_1401cd1a0()->FUN_1410c35c0())
    {
        nValue = 1;
    }
    else
    {
        MS2Ptr<Unk_WsPtred298> spMap = FUN_1403ed2d0()->FUN_141bd30a0();
        nValue = reinterpret_cast<Unk_UcMapData*>(spMap.get())->m_nField5c;
    }
    if (nValue == 0)
    {
        FUN_141275260(0x87d, 1, 0);
        return 0;
    }
    if (FUN_141659690(pPC) != 0)
    {
        FUN_141275260(0x87b, 1, 0);
        return 0;
    }
    if (FUN_141527160(pPC, 0x27) == 0)
    {
        FUN_141275260(0x87b, 1, 0);
        return 0;
    }
    return 1;
}
MS2_REPLACE(0x1418fd330, FUN_1418fd330, 500, 0xE1CB9F60);

// @0x1418fd530
// The four identical probes below: the local player is not the character nCharId.
int FUN_1418fd530(__int64 nCharId)
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (FUN_141656a80(pPC) == nCharId)
        return 0;
    return 1;
}
MS2_REPLACE(0x1418fd530, FUN_1418fd530, 70, 0xC984AEB5);

// @0x1418fd580
int FUN_1418fd580(__int64 nCharId)
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (FUN_141656a80(pPC) == nCharId)
        return 0;
    return 1;
}
MS2_REPLACE(0x1418fd580, FUN_1418fd580, 70, 0x042D0E08);

// @0x1418fd5d0
int FUN_1418fd5d0(__int64 nCharId)
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (FUN_141656a80(pPC) == nCharId)
        return 0;
    return 1;
}
MS2_REPLACE(0x1418fd5d0, FUN_1418fd5d0, 70, 0x10C770C8);

// @0x1418fd620
int FUN_1418fd620(__int64 nCharId)
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (FUN_141656a80(pPC) == nCharId)
        return 0;
    return 1;
}
MS2_REPLACE(0x1418fd620, FUN_1418fd620, 70, 0xF1D01F18);

// @0x1418fd670
int FUN_1418fd670(__int64 nCharId)
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (FUN_141656a80(pPC) == nCharId)
        return 0;
    return FUN_1418fd280();
}
MS2_REPLACE(0x1418fd670, FUN_1418fd670, 70, 0x3B4566E8);

// @0x1418fd6c0
bool FUN_1418fd6c0(__int64 nId)
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC != 0)
        FUN_141529c80(pPC, 0, 0, 0, nId, CStringW(L""));
    return pPC != 0;
}
MS2_REPLACE(0x1418fd6c0, FUN_1418fd6c0, 120, 0xBFBC3BD2);

inline void CUserReportData::FUN_141904a90(int n) { m_70 = n; }                // @0x141904a90
inline void CUserReportData::FUN_141904af0(int n) { m_74 = n; }                // @0x141904af0
inline void CUserReportData::FUN_141904b10(__int64 n) { m_68 = n; }            // @0x141904b10

// ---- the id-to-name lookups ----
CBuddyManager* FUN_14097a780();
class Unk_UcGuildObj                                                // a guild record (the id sits at +0x20)
{
public:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18;
    __int64 m_nGuildId;
    void* m_pad_28; void* m_pad_30; void* m_pad_38; void* m_pad_40; void* m_pad_48; void* m_pad_50;
    int m_nPlotX;                                                   // +0x58 home plot of the guild
    int m_nPlotY;
    int m_nPlotZ;
};
MS2_CHECK_OFFSET(Unk_UcGuildObj, m_nGuildId, 0x20);
MS2_CHECK_OFFSET(Unk_UcGuildObj, m_nPlotZ, 0x60);
class Unk_UcGuildRef                                                // counted guild reference
{
public:
    ~Unk_UcGuildRef();                                              // 0x1404eead0
    Unk_UcGuildObj* FUN_1404f0b80();
    __int64 FUN_1404f0ab0();                                        // the record, tested for null
    void* m_pad_00; void* m_pad_08;
};
class Unk_UcGuildSvc                                                // the guild service: the guild record sits at +8
{
public:
    Unk_UcGuildRef FUN_1413b6200(__int64 nId);
    void* m_pad_00;
    CGuildInfo m_info;
};
MS2_CHECK_OFFSET(Unk_UcGuildSvc, m_info, 8);
Unk_UcGuildSvc* FUN_1403ed290();
CPartyManager* FUN_1409670d0();
__int64 FUN_141637b90(CPartyMember* p);
CClubClientManager* FUN_140e0d900();
UIClubDialog* FUN_140b19090(int nUiId);
void* FUN_140ac5e20(void* map);                                     // m_930.GetStartPosition
void* FUN_140ac5ed0(void* map, void* pos);                          // m_930.GetValueAt
void FUN_140ac5dd0(void* map, void** pos);                          // m_930.GetNext
struct Unk_UcProxyRef;
Unk_UcProxyRef* FUN_140ac58f0(Unk_UcProxyRef* dst, const void* src);
void FUN_1406c70a0(Unk_UcProxyRef* p);
struct Unk_UcProxyRef                                               // counted reference to a CProxyGameObject
{
    Unk_UcProxyRef(const void* src) { FUN_140ac58f0(this, src); }
    ~Unk_UcProxyRef() { FUN_1406c70a0(this); }
    CProxyGameObject* operator->() const { return m_p; }
    bool IsNull() const { return m_p == 0; }
    void* m_unk_00;
    CProxyGameObject* m_p;
};

// @0x1418fd740
// Send the actor message for the character nId of the given kind (7 buddy, 3 guild, 2 party, 0xe club, others proxies).
int FUN_1418fd740(__int64 nParam, __int64 nId, int nType)
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (nType == 7)
    {
        CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4880(nId);
        if (spBuddy.get() != 0)
        {
            FUN_141529c80(pPC, spBuddy->FUN_1401cc3e0(), spBuddy->FUN_1401cc3a0(), spBuddy->FUN_1401cc3c0(),
                          spBuddy->FUN_1401cc250(), CStringW(L""));
            return 1;
        }
    }
    else if (nType == 3)
    {
        Unk_UcGuildRef guild = FUN_1403ed290()->FUN_1413b6200(nId);
        if (guild.FUN_1404f0ab0() != 0)
        {
            FUN_141529c80(pPC, 0, 0, 0, guild.FUN_1404f0b80()->m_nGuildId, CStringW(L""));
            return 1;
        }
    }
    else if (nType == 2)
    {
        MS2Ptr<CPartyMember> spMember = FUN_1409670d0()->FUN_14162afc0(nId);
        if (spMember.get() != 0)
        {
            FUN_141529c80(pPC, 0, 0, 0, FUN_141637b90(spMember.operator->()), CStringW(L""));
            return 1;
        }
    }
    else
    {
        if (nType == 4)
        {
            FUN_141529c80(pPC, 0, 0, 0, nParam, CStringW(L""));
            return 1;
        }
        else if (nType == 0xe)
        {
            UIClubDialog* pClubDlg = FUN_140b19090(0x4f25);
            if (pClubDlg != 0)
            {
                __int64 nClubId = pClubDlg->FUN_141904a70();
                MS2Ptr<CClubMember> spMember = FUN_140e0d900()->FUN_140b15770(nClubId, nId);
                if (spMember)
                {
                    FUN_141529c80(pPC, 0, 0, 0, spMember->m_info.m_accountId, CStringW(L""));
                    return 1;
                }
            }
        }
        else if (nType == 0x11)
        {
            FUN_141529c80(pPC, 0, 0, 0, nParam, CStringW(L""));
            return 1;
        }
        else
        {
            void* pMap = FUN_1403ed2d0()->FUN_141bc9fb0();
            for (void* pos = FUN_140ac5e20(pMap); pos != 0; FUN_140ac5dd0(pMap, &pos))
            {
                MS2Ptr<CProxyGameObject> spProxy(*static_cast<const MS2Ptr<CProxyGameObject>*>(FUN_140ac5ed0(pMap, pos)));
                if (spProxy.get() && reinterpret_cast<__int64>(spProxy->FUN_1416c22f0()) == nId)
                {
                    FUN_141529c80(pPC, spProxy->m_b4, spProxy->m_b8, spProxy->m_bc,
                                  reinterpret_cast<__int64>(spProxy->FUN_1416c2310()), CStringW(L""));
                    return 1;
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE(0x1418fd740, FUN_1418fd740, 1739, 0xCB108862);

// @0x1418fde20
// Open the confirmation box (string 0x879 with a1) with two ids and a number and call back with nCallback.
void FUN_1418fde20(__int64 nId0, __int64 nId1, int nValue, const CStringW& strArg, Unk_UcMsgCallback cb)
{
    Unk_UcMsgBoxPtr spBox = FUN_140d73d20(1, FUN_14052bd00(0x879, strArg), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->Append<__int64>(nId0);
        spBox->Append<__int64>(nId1);
        spBox->Append<int>(nValue);
        spBox->FUN_141a027c0(cb);
        FUN_140d73c60(spBox);
    }
}

// ---- client options, the UI manager and the wallet ----
class Unk_UcOptions
{
public:
    bool FUN_14036d570(int nOption);
    bool FUN_14036d650();                                           // red merat in use
    bool FUN_14036d6d0();                                           // rb merat in use
    bool FUN_14036d710(int nOption);
};
Unk_UcOptions* FUN_140166410();
class Unk_UcSlotMgr
{
public:
    bool FUN_141b867e0(__int64 nKey);
    void FUN_141b86750(__int64 nKey);
};
Unk_UcSlotMgr* FUN_1409eed90();
bool FUN_140930b10();
int FUN_1409301f0();                                                // the current merat kind
__int64 FUN_140930240();                                            // merat balance
__int64 FUN_140930ae0();                                            // red merat balance
extern Unk_Inventory DAT_143ab2a90;
class Unk_UcStatRef                                                 // counted reference to the character's stat record
{
public:
    Unk_UcStatRef(Unk_UcPCInfo* p);                                         // 0x14050dd40
    ~Unk_UcStatRef();                                               // 0x14050de40
    bool FUN_141532fa0(int n);
    void* m_pad_00; void* m_pad_08;
};
class Unk_UcTextFilter { public: void FUN_1416fb300(const CStringW& str); };
Unk_UcTextFilter* FUN_1403b4750();
CStringW FUN_1409e97f0(int nId, const unsigned& nArg);
class Unk_UcUiMgr
{
public:
    void FUN_141add1f0();
    void FUN_141add210();
    void FUN_141adc690(int nUiId);
    void FUN_141adc5d0(int nUiId);
    void FUN_141adbdc0(int n);
};
Unk_UcUiMgr* FUN_1403ed2b0();

// @0x1418fdfd0
void FUN_1418fdfd0(__int64 nKey)
{
    if (!FUN_140166410()->FUN_14036d570(0x104))
        return;
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    if (FUN_1409eed90() == 0)
        return;
    if (!FUN_1409eed90()->FUN_141b867e0(nKey))
        return;
    FUN_1409eed90()->FUN_141b86750(nKey);
}
MS2_REPLACE(0x1418fdfd0, FUN_1418fdfd0, 126, 0x943A0D11);

// @0x1418fe060
int FUN_1418fe060()
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    if (DAT_1439f4a7c == 0)
    {
        if (FUN_140374410(nMapId) && FUN_141527e00(pPC) == 0)
        {
            if (FUN_1409670e0()->FUN_1410c3180() == FUN_141656ad0(pPC))
                return 1;
        }
        if (DAT_143ab0248 == 2 && nMapId == 0x1e8673)
            return 1;
        return 0;
    }
    return FUN_140930b10() ? 0 : 1;
}
MS2_REPLACE(0x1418fe060, FUN_1418fe060, 185, 0x0004E9AD);

// @0x1418fe120
bool FUN_1418fe120()
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return false;
    if (FUN_14152e950(pPC) == 0)
        return false;
    Unk_UcStatRef stat(FUN_141523c50(pPC));
    if (stat.FUN_141532fa0(0))
        return false;
    return true;
}
MS2_REPLACE(0x1418fe120, FUN_1418fe120, 151, 0xF42737FD);

// @0x1418fe1c0
void FUN_1418fe1c0(const CString& strUrl)
{
    if (strUrl.IsEmpty())
        return;
    ShellExecuteA(0, "open", strUrl, 0, 0, SW_SHOWNORMAL);
}
MS2_REPLACE(0x1418fe1c0, FUN_1418fe1c0, 83, 0xD59F7ECF);

// @0x1418fe220
void FUN_1418fe220(const CString& strUrl)
{
    if (strUrl.IsEmpty())
        return;
    void* pBrowser = FUN_140c43790(0x4e6a);
    if (pBrowser != 0)
        FUN_14135ec00(pBrowser, strUrl, true);
}
MS2_REPLACE(0x1418fe220, FUN_1418fe220, 75, 0xC9CFD09F);

// @0x1418fe280
// Open the url in the default browser; chrome and firefox get an explicit new-window flag.
void FUN_1418fe280(const CString& strUrl)
{
    if (strUrl.IsEmpty())
        return;
    DWORD dwSize = 0x104;
    CHAR szExe[0x104] = {};
    HRESULT hr = AssocQueryStringA(ASSOCF_NOTRUNCATE, ASSOCSTR_EXECUTABLE, "http", 0, szExe, &dwSize);
    if (hr < 0)
    {
        MS2_ASSERT_AT(0x2ce, 0);
        ShellExecuteA(0, "open", strUrl, 0, 0, SW_SHOW);
        return;
    }
    CString strParams(strUrl);
    if (strcmp("chrome.exe", PathFindFileNameA(szExe)) == 0)
    {
        strParams = FUN_140298360(" --new-window ", strUrl);
    }
    else if (strcmp("firefox.exe", PathFindFileNameA(szExe)) == 0)
    {
        strParams = FUN_140298360(" -new-window ", strUrl);
    }
    ShellExecuteA(0, "open", szExe, strParams, "", SW_SHOW);
}
MS2_REPLACE(0x1418fe280, FUN_1418fe280, 601, 0xA7A69DF7);

// @0x1418fe4e0
CStringW FUN_1418fe4e0(const CStringW& strPath)
{
    wchar_t szFull[0x104] = {};
    _wfullpath(szFull, strPath, 0x104);
    return CStringW(szFull);
}
MS2_REPLACE(0x1418fe4e0, FUN_1418fe4e0, 158, 0x44154AB3);

// @0x1418fe5d0
CStringW FUN_1418fe5d0(int nKind)
{
    if (nKind == 0)
        return FUN_14028de60(0x98a);
    if (nKind == 1)
        return FUN_14028de60(0x98b);
    if (nKind == 2)
        return FUN_14028de60(0x98c);
    if (nKind == 3)
        return FUN_14028de60(0x98d);
    return CStringW(L"");
}
MS2_REPLACE(0x1418fe5d0, FUN_1418fe5d0, 223, 0x524822CC);

// @0x1418fe590
CStringW FUN_1418fe590()
{
    return FUN_1418fe5d0(FUN_1409301f0());
}
MS2_REPLACE(0x1418fe590, FUN_1418fe590, 55, 0xA41E59B9);

// @0x1418fe6c0
// Display name of a currency (1 meso, 3 merat, 9 red merat, 0xf star point).
CStringW FUN_1418fe6c0(int nCurrency, int nKind)
{
    if (nCurrency == 0)
        return FUN_14028b8e0(CStringW(L"s_common_cashname"));
    if (nCurrency == 1)
        return FUN_14028b8e0(CStringW(L"s_common_mesoname"));
    if (nCurrency == 3)
        return FUN_1418fe5d0(nKind);
    if (nCurrency == 9)
        return FUN_14028b8e0(CStringW(L"s_common_meratname_red"));
    if (nCurrency == 0xf)
        return FUN_14028b8e0(CStringW(L"s_common_starpointname"));
    return CStringW(L"");
}
MS2_REPLACE(0x1418fe6c0, FUN_1418fe6c0, 423, 0xF021F7E6);

// @0x1418fe870
// Icon name of a currency; *pnVSpace gets the icon's vertical offset.
CStringW FUN_1418fe870(int nCurrency, int* pnVSpace, unsigned nItemId)
{
    CStringW strIcon;
    *pnVSpace = -4;
    switch (nCurrency)
    {
    case 0:
        strIcon = L"export_common_icon_cash_r";
        *pnVSpace = -4;
        break;
    case 1:
        strIcon = L"export_common_icon_meso_h21";
        *pnVSpace = -6;
        break;
    case 2:
        strIcon = FUN_140292a70(L"export_common_icon_item_{0}", nItemId);
        *pnVSpace = -6;
        break;
    case 3:
        strIcon = L"export_common_icon_merat";
        *pnVSpace = -4;
        break;
    case 4:
        strIcon = L"export_common_icon_honor";
        *pnVSpace = -6;
        break;
    case 5:
        strIcon = L"export_common_icon_treva";
        *pnVSpace = -6;
        break;
    case 6:
        strIcon = L"export_common_icon_lu";
        *pnVSpace = -6;
        break;
    case 7:
        strIcon = L"export_common_icon_habi";
        *pnVSpace = -6;
        break;
    case 9:
        if (!FUN_140166410()->FUN_14036d650())
        {
            strIcon = L"export_common_icon_merat";
            *pnVSpace = -4;
        }
        else
        {
            strIcon = L"export_common_icon_redmerat";
            *pnVSpace = -4;
        }
        break;
    case 10:
        if (!FUN_140166410()->FUN_14036d6d0())
        {
            strIcon = L"export_common_icon_merat";
            *pnVSpace = -4;
        }
        else
        {
            strIcon = L"export_common_icon_rbmerat";
            *pnVSpace = -4;
        }
        break;
    case 0xb:
        strIcon = L"export_icon_guild_fund";
        *pnVSpace = -4;
        break;
    case 0xc:
        strIcon = L"export_common_icon_reverse_coin";
        *pnVSpace = -7;
        break;
    case 0xd:
        strIcon = L"export_common_icon_mentor_token";
        *pnVSpace = -4;
        break;
    case 0xe:
        strIcon = L"export_common_icon_mentee_token";
        *pnVSpace = -4;
        break;
    case 0xf:
        strIcon = L"export_common_icon_star_point";
        *pnVSpace = -6;
        break;
    case 0x10:
        strIcon = L"export_common_icon_meso_market_token";
        *pnVSpace = -4;
        break;
    }
    return strIcon;
}
MS2_REPLACE(0x1418fe870, FUN_1418fe870, 830, 0x0E450D78);

// The payment text with an icon: key, amount, icon and its vertical offset (0x141081c60).
CStringW FUN_141081c60(CStringW strKey, const CStringW& strAmount, const CStringW& strIcon, const int& nVSpace);   // FUN_14028dfa0<CStringW, CStringW, int> (format by value)

// @0x1418fec90
CStringW FUN_1418fec90(int nCurrency, __int64 nAmount, int nArg)
{
    if (nCurrency == 2)
        return FUN_1412e7c20(0x989, FUN_1409404f0(nAmount), nArg);
    int nVSpace = 0;
    CStringW strIcon = FUN_1418fe870(nCurrency, &nVSpace, 0);
    if (!strIcon.IsEmpty())
        return FUN_141081c60(CStringW(L"s_common_payment"), FUN_1409404f0(nAmount), strIcon, nVSpace);
    return CStringW(L"");
}
MS2_REPLACE(0x1418fec90, FUN_1418fec90, 421, 0xC875A71E);

// @0x1418fec00
CStringW FUN_1418fec00(int nCurrency, __int64 nAmount, bool bAlt)
{
    int nKind = nCurrency;
    if (nCurrency == 3 && bAlt)
    {
        if (FUN_140166410()->FUN_14036d710(0x61))
            nKind = 10;
    }
    return FUN_1418fec90(nKind, nAmount, 0);
}
MS2_REPLACE(0x1418fec00, FUN_1418fec00, 131, 0x88CCFCE4);

// @0x1418fee40
CStringW FUN_1418fee40(int nCurrency, __int64 nAmount, const CStringW& strArg, bool bAlt)
{
    if (nCurrency == 2)
        return FormatStringId(0x989, FUN_1409404f0(nAmount), strArg);
    return FUN_1418fec00(nCurrency, nAmount, bAlt);
}
MS2_REPLACE(0x1418fee40, FUN_1418fee40, 188, 0x140A38A2);

// @0x1418fef10
CStringW FUN_1418fef10(int nArg, __int64 nAmount)
{
    return FUN_1412e7c20(0x989, FUN_1409404f0(nAmount), nArg);
}
MS2_REPLACE(0x1418fef10, FUN_1418fef10, 122, 0x4DA4F573);

// @0x1418fef90
CStringW FUN_1418fef90(int nCurrency, __int64 nAmount)
{
    if (nCurrency == 3)
        return FUN_1405c2690(CStringW(L"s_common_merat_large"), FUN_1409404f0(nAmount));
    if (nCurrency == 9)
        return FUN_1405c2690(CStringW(L"s_common_redmerat_large"), FUN_1409404f0(nAmount));
    return CStringW(L"");
}
MS2_REPLACE(0x1418fef90, FUN_1418fef90, 371, 0xCF5E5E8C);

// @0x1418ff1f0
// Can the player pay nAmount of the currency (nItemId for item payments)?
bool FUN_1418ff1f0(int nCurrency, __int64 nAmount, int nItemId)
{
    switch (nCurrency)
    {
    case 1:
        return nAmount <= DAT_143ab2898;
    case 2:
        return DAT_143ab2a90.FUN_140a5ece0(nItemId, (int)nAmount);
    case 3:
        return FUN_140d86260()->vfunc_40(nAmount);
    case 4:
        return nAmount <= DAT_143ab28b0;
    case 5:
        return nAmount <= DAT_143ab28b8;
    case 6:
        return nAmount <= DAT_143ab28c0;
    case 7:
        return nAmount <= DAT_143ab28c8;
    case 9:
        return FUN_140d86260()->vfunc_41(nAmount);
    case 10:
        if (!FUN_140d86260()->vfunc_41(nAmount) && !FUN_140d86260()->vfunc_40(nAmount))
            return false;
        return true;
    case 0xb:
    {
        int nFund = FUN_1403ed290()->m_info.FUN_1404d1df0();
        if (nFund < 0)
            nFund = 0;
        return nAmount <= nFund;
    }
    case 0xc:
        return nAmount <= DAT_143ab28d0;
    case 0xd:
        return nAmount <= DAT_143ab28d8;
    case 0xe:
        return nAmount <= DAT_143ab28e0;
    case 0xf:
        return nAmount <= DAT_143ab28e8;
    case 0x10:
        return nAmount <= DAT_143ab28f0;
    }
    return false;
}
MS2_REPLACE(0x1418ff1f0, FUN_1418ff1f0, 853, 0x31336EBE);

// @0x1418ff5a0
__int64 FUN_1418ff5a0(int nCurrency, __int64 nAmount, int nItemId)
{
    switch (nCurrency)
    {
    case 1:
        return DAT_143ab2898;
    case 2:
        return DAT_143ab2a90.FUN_140a5f180(nItemId, 0);
    case 3:
        return FUN_140930240();
    case 4:
        return DAT_143ab28b0;
    case 5:
        return DAT_143ab28b8;
    case 6:
        return DAT_143ab28c0;
    case 7:
        return DAT_143ab28c8;
    default:
        return 0;
    case 9:
        return FUN_140930ae0();
    case 10:
    {
        __int64 nRed = FUN_140930ae0();
        if (nRed < nAmount)
            nRed = FUN_140930240();
        return nRed;
    }
    case 0xb:
        return FUN_1403ed290()->m_info.FUN_1404d1df0();
    case 0xc:
        return DAT_143ab28d0;
    case 0xd:
        return DAT_143ab28d8;
    case 0xe:
        return DAT_143ab28e0;
    case 0xf:
        return DAT_143ab28e8;
    case 0x10:
        return DAT_143ab28f0;
    }
}
MS2_REPLACE(0x1418ff5a0, FUN_1418ff5a0, 277, 0x8D703C29);

// @0x1418ff710
// Tell the player which currency is lacking.
void FUN_1418ff710(int nCurrency, __int64 nAmount, int nItemId, int nOpt)
{
    switch (nCurrency)
    {
    case 1:
        FUN_141275260(0x34, 1, 1);
        break;
    case 2:
    {
        CStringW strText = FUN_1409e97f0(0x38, (unsigned)nItemId);
        FUN_1403b4750()->FUN_1416fb300(strText);
        FUN_1412751f0(strText, 1, 1);
        break;
    }
    case 3:
    case 10:
        if (nOpt == 0)
            FUN_1403ed2b0()->FUN_141add1f0();
        else if (nOpt == 1)
            FUN_1403ed2b0()->FUN_141add210();
        break;
    case 4:
        FUN_141275260(0x39, 1, 1);
        break;
    case 5:
        FUN_141275260(0x3a, 1, 1);
        break;
    case 6:
        FUN_141275260(0x3b, 1, 1);
        break;
    case 7:
        FUN_141275260(0x3c, 1, 1);
        break;
    case 9:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_lack_redmerat")), 1, 1);
        break;
    case 0xb:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_guild_err_not_enough_guild_fund")), 1, 1);
        break;
    case 0xc:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_lack_reverse_coin")), 1, 1);
        break;
    case 0xd:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_lack_mentor_token")), 1, 1);
        break;
    case 0xe:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_lack_mentee_token")), 1, 1);
        break;
    case 0xf:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_lack_star_point")), 1, 1);
        break;
    case 0x10:
        FUN_141275260(0x41, 1, 1);
        break;
    }
}
MS2_REPLACE(0x1418ff710, FUN_1418ff710, 1061, 0x2880CDF3);

// @0x1418ff180
bool FUN_1418ff180(int nCurrency, __int64 nAmount, int nItemId, bool bMessage, int nOpt)
{
    if (FUN_1418ff1f0(nCurrency, nAmount, nItemId) == 0)
    {
        if (bMessage)
            FUN_1418ff710(nCurrency, nAmount, nItemId, nOpt);
        return false;
    }
    return true;
}
MS2_REPLACE(0x1418ff180, FUN_1418ff180, 93, 0xEC334497);

// @0x1418ff110
void FUN_1418ff110(int nCurrency, __int64 nAmount, bool bMessage)
{
    if (nCurrency == 3 || nCurrency == 10)
        FUN_1418ff180(nCurrency, nAmount, 0, bMessage, 1);
    else
        FUN_1418ff180(nCurrency, nAmount, 0, bMessage, 0);
}
MS2_REPLACE(0x1418ff110, FUN_1418ff110, 101, 0x94364910);

// The item handle (16 bytes, passed by value: the callee drops it) and the record behind it.
class Unk_UcArgs { public: CStringW FUN_1408d21c0(int nIndex, CStringW strDefault); };
class Unk_UcItemData
{
public:
    void* m_pad_00[0x52];
    CStringW m_strType;                                             // +0x290
    void* m_pad_298; void* m_pad_2a0; void* m_pad_2a8;
    Unk_UcArgs m_args;                                              // +0x2b0
    bool FUN_14053cde0();                                           // unique (non-stacking) item
    bool FUN_14053d6f0();                                           // item with ranks
};
class Unk_UcItemPtr
{
public:
    ~Unk_UcItemPtr();                                               // 0x1401b50d0
    char FUN_1401b5240(int n);
    Unk_UcItemData* FUN_1401b52a0();
    void* m_pad_00; void* m_p;
};
MS2_CHECK_OFFSET(Unk_UcItemData, m_strType, 0x290);
MS2_CHECK_OFFSET(Unk_UcItemData, m_args, 0x2b0);
struct Unk_UcSalable { void* m[25]; };                              // 200-byte working record
void FUN_1408ad110(Unk_UcSalable* p);
int FUN_1408a0d30(int n, Unk_UcSalable* p, int nField);
void FUN_14050de70(Unk_UcSalable* p);
bool FUN_14034eee0(const CStringW& a, const wchar_t* pszB);
CString FUN_14016a600(const wchar_t* psz, int n);
bool FUN_1401647e0(const CString& a, const CString& b) noexcept;

// @0x1418ffba0
bool FUN_1418ffba0(Unk_UcItemPtr item)
{
    if (item.FUN_1401b5240(0) != 0)
        return false;
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return false;
    if (FUN_14034eee0(item.FUN_1401b52a0()->m_strType, L"UGCMapPackage"))
        return false;
    Unk_UcPCInfo* pInfo = FUN_141523c50(pPC);
    if (pInfo == 0)
        return false;
    Unk_UcSalable sal;
    FUN_1408ad110(&sal);
    if (FUN_1408a0d30(1, &sal, pInfo->m_nField1c) != 0)
    {
        CString strPackage = FUN_14016a600((const wchar_t*)item.FUN_1401b52a0()->m_args.FUN_1408d21c0(0, L""), 0);
        UGCMapPackageDataPtr spPackage = FUN_1408b9b90(strPackage);
        // MS2-FUNCTIONAL: the exe compares against a never-initialised CString local (stack garbage)
        CString strSize;
        if ((CUGCMapPackageData*)spPackage != 0 && FUN_1401647e0(spPackage->m_strIndoorSizeType, strSize))
        {
            FUN_14050de70(&sal);
            return true;
        }
    }
    if (pInfo->m_nField1c == 0 && FUN_141527e00(pPC) == 0)
    {
        FUN_14050de70(&sal);
        return true;
    }
    FUN_14050de70(&sal);
    return false;
}

// @0x1418ffe80
bool FUN_1418ffe80(unsigned nFlags, unsigned nMask) { return (nFlags & nMask) != 0; }
MS2_REPLACE(0x1418ffe80, FUN_1418ffe80, 53, 0x026CC30B);

// @0x1418ffec0
void FUN_1418ffec0(unsigned* pnFlags, unsigned nMask) { *pnFlags = *pnFlags | nMask; }
MS2_REPLACE(0x1418ffec0, FUN_1418ffec0, 30, 0x8DED35CE);

// @0x1418ffef0
void FUN_1418ffef0(unsigned* pnFlags, unsigned nMask) { *pnFlags = *pnFlags & ~nMask; }
MS2_REPLACE(0x1418ffef0, FUN_1418ffef0, 34, 0x9A8013F9);

// @0x1418fffd0
// The tooltip record of a tab: index, label and a styled text.
void FUN_1418fffd0(ASObj* pObj, int nTabIndex, const CStringW& strLabel, const CStringW& strText)
{
    pObj->FUN_1407cb9c0("tabIndex", nTabIndex);
    pObj->FUN_1407cbb20("label", strLabel);
    ASObj tip(2);
    tip.FUN_1409c0dc0("className", "export_common_tooltip_tooltipText");
    tip.FUN_1407cbb20("id", strText);
    tip.FUN_1409c0dc0("align", "topLeft");
    pObj->FUN_1409adbe0("tooltipData", tip.FUN_1422bb870());
}
MS2_REPLACE(0x1418fffd0, FUN_1418fffd0, 327, 0xFA8703F6);

// @0x1418fff20
void FUN_1418fff20(ASArray* pArray, int nTabIndex, const CStringW& strLabel, const CStringW& strText)
{
    ASObj obj(2);
    FUN_1418fffd0(&obj, nTabIndex, strLabel, strText);
    pArray->FUN_1422bc050(obj.FUN_1422bb870());
}
MS2_REPLACE(0x1418fff20, FUN_1418fff20, 162, 0x243A22D7);

// ---- the client configuration (singleton behind 0x1401d3200): only the entries this unit reads ----
struct Unk_UcCfgInt { int* FUN_1402056b0(); char m_pad[0x58 - 0]; };
struct Unk_UcCfgStr { CString& FUN_140298f80(); char m_pad[0x60 - 0]; };
struct Unk_UcCfg
{
    char m_pad_0000[0x5338];
    Unk_UcCfgInt m_5338;
    Unk_UcCfgInt m_5390;
    Unk_UcCfgInt m_53e8;
    Unk_UcCfgInt m_5440;
    Unk_UcCfgInt m_5498;
    Unk_UcCfgInt m_54f0;
    Unk_UcCfgInt m_5548;
    char m_pad_55a0[0xd2f8 - 0x55a0];
    Unk_UcCfgStr m_d2f8;
    Unk_UcCfgInt m_d358;
};
MS2_CHECK_OFFSET(Unk_UcCfg, m_5548, 0x5548);
MS2_CHECK_OFFSET(Unk_UcCfg, m_d358, 0xd358);
Unk_UcCfg* FUN_1401d3200();

// ---- UI and device singletons ----
void* FUN_1408e57f0();
int FUN_1422b9e00(void* p);
int FUN_141a55620();
class Unk_UcPadMgr { public: int FUN_140d8c660(); };
Unk_UcPadMgr* FUN_140a58540();
class Unk_UcMouseMgr { public: int FUN_140ad21b0(); };
Unk_UcMouseMgr* FUN_140953f30();
UIDialog* FUN_140ff7030(int nUiId);
void FUN_1418dfb30(UIDialog* p, int a, int b, int c);
int FUN_1418dfc40(UIDialog* p);
void* FUN_140cc18a0();
void FUN_141b794e0(void* pSvc, CString& strOut, const char* szPath);

// @0x141900510
// Current amount and cap of a currency; false for the currencies without a display.
bool FUN_141900510(int nCurrency, __int64* pnAmount, __int64* pnCap)
{
    *pnCap = 0;
    switch (nCurrency)
    {
    case 4:
        *pnAmount = DAT_143ab28b0;
        *pnCap = *FUN_1401d3200()->m_5338.FUN_1402056b0();
        return true;
    case 5:
        *pnAmount = DAT_143ab28b8;
        *pnCap = *FUN_1401d3200()->m_5390.FUN_1402056b0();
        return true;
    case 6:
        *pnAmount = DAT_143ab28c0;
        *pnCap = *FUN_1401d3200()->m_53e8.FUN_1402056b0();
        return true;
    case 7:
        *pnAmount = DAT_143ab28c8;
        *pnCap = *FUN_1401d3200()->m_5440.FUN_1402056b0();
        return true;
    default:
        return false;
    case 0xc:
        *pnAmount = DAT_143ab28d0;
        *pnCap = *FUN_1401d3200()->m_5498.FUN_1402056b0();
        return true;
    case 0xd:
        *pnAmount = DAT_143ab28d8;
        *pnCap = *FUN_1401d3200()->m_54f0.FUN_1402056b0();
        return true;
    case 0xe:
        *pnAmount = DAT_143ab28e0;
        *pnCap = *FUN_1401d3200()->m_5548.FUN_1402056b0();
        return true;
    case 0xf:
        *pnAmount = DAT_143ab28e8;
        *pnCap = 0;
        return true;
    case 0x10:
        *pnAmount = DAT_143ab28f0;
        *pnCap = 0;
        return true;
    }
}
MS2_REPLACE(0x141900510, FUN_141900510, 511, 0x9B022F71);

// @0x141900120
// "amount" or "amount / cap" of a currency, optionally with its icon and a leading line break.
CStringW FUN_141900120(int nCurrency, bool bIcon, bool bNewline)
{
    int nVSpace = -4;
    __int64 nAmount = 0;
    __int64 nCap = 0;
    if (!FUN_141900510(nCurrency, &nAmount, &nCap))
        return CStringW(L"");
    CStringW strFormat;
    if (bNewline)
        strFormat.Append(L"\n");
    if (!bIcon)
    {
        if (nCap == 0)
        {
            strFormat += L"{0}";
            return FUN_1401e8510(strFormat, FUN_1409404f0(nAmount));
        }
        strFormat += L"{0} / {1}";
        return FUN_140656190(strFormat, FUN_1409404f0(nAmount), FUN_1409404f0(nCap));
    }
    CStringW strIcon = FUN_1418fe870(nCurrency, &nVSpace, 0);
    if (nCap == 0)
    {
        strFormat += L"<img src='{0}' vspace='{1}'/> {2}";
        return FUN_140763a90(strFormat, strIcon, nVSpace, FUN_1409404f0(nAmount));
    }
    strFormat += L"<img src='{0}' vspace='{1}'/> {2} / {3}";
    return StringFormat(strFormat, strIcon, nVSpace, FUN_1409404f0(nAmount), FUN_1409404f0(nCap));
}
MS2_REPLACE(0x141900120, FUN_141900120, 1002, 0xC3DC0860);

// @0x141900a90
bool FUN_141900a90(UIDialog* pDlg)
{
    int aLayer[3];
    aLayer[0] = 0x19;
    aLayer[1] = 4;
    if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001f)
    {
        aLayer[0] = 0xc;
    }
    else if (FUN_141a55620() == 0)
    {
        aLayer[0] = 0x19;
    }
    else
    {
        aLayer[0] = 0x22;
        aLayer[1] = 0;
    }
    if (pDlg->FUN_141924630() != 0 && pDlg->FUN_1422db750() == aLayer[0])
    {
        pDlg->FUN_1419235d0();
        return true;
    }
    aLayer[2] = pDlg->vfunc_48();
    FUN_1403ed2b0()->FUN_141adc690(aLayer[2]);
    pDlg->FUN_141904ad0(&aLayer[0]);
    pDlg->FUN_141904ab0(&aLayer[1]);
    return true;
}
MS2_REPLACE(0x141900a90, FUN_141900a90, 213, 0xCCB33585);

// @0x141900b70
CString FUN_141900b70()
{
    int nPad = FUN_140a58540()->FUN_140d8c660();
    if (nPad == 1)
        return CString("xbox");
    if (nPad == 2)
        return CString("dualshock");
    if (nPad == 3)
        return CString("steam");
    if (FUN_140953f30()->FUN_140ad21b0() == 0)
        return CString("keyboard");
    return CString("mouse");
}
MS2_REPLACE(0x141900b70, FUN_141900b70, 260, 0x4B8422E3);

// @0x141900c80
int FUN_141900c80(int nKind)
{
    if (nKind == 2)
    {
        UIDialog* pDlg = FUN_140ff7030(0x4e87);
        if (pDlg != 0)
            FUN_1418dfb30(pDlg, *FUN_1401d3200()->m_d358.FUN_1402056b0(), 0x22, 0);
        return 0;
    }
    if (nKind == 3)
    {
        CString strUrl;
        const char* szPath = FUN_1401d3200()->m_d2f8.FUN_140298f80();
        FUN_141b794e0(FUN_140cc18a0(), strUrl, szPath);
        FUN_1418fe1c0(strUrl);
        return 0;
    }
    UIDialog* pDlg = FUN_140ff7030(0x4e87);
    if (pDlg != 0)
    {
        int nWanted = *FUN_1401d3200()->m_d358.FUN_1402056b0();
        if (pDlg->vfunc_55() == 0)
        {
            if (FUN_1418dfc40(pDlg) == nWanted)
                FUN_1403ed2b0()->FUN_141adc5d0(0x4e87);
        }
    }
    return 1;
}
MS2_REPLACE(0x141900c80, FUN_141900c80, 330, 0xAC9C69F9);

// ---- the dialog root and the XML element helpers used by the placement record ----
class ASDialog : public ASDisplayObject
{
public:
    int FUN_1422c1500();
    int FUN_1422c1530();
    int FUN_1422c1340();
    int FUN_1422c13b0();
    float FUN_1422c10a0();
    float FUN_1422c1110();
};
void FUN_140873e30(Unk_140165cf0* pNode, const char* szName, float f);
void FUN_140873ca0(Unk_140165cf0* pNode, const char* szName, int n);
int FUN_140873360(Unk_140165cf0* pNode, const char* szName, float& f);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* szName, int& n);
float FUN_140bf4fd0(float f);

// ---- server and region records behind the server dialogs ----
class Unk_UcServerDlg;
Unk_UcServerDlg* FUN_14136f520(int nUiId);
int FUN_141ad1010(Unk_UcServerDlg* p);                              // the selected server id
int FUN_14092f640();                                                // the current channel
class Unk_UcServerRec
{
public:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18;
    CStringW m_strName;                                             // +0x20
    CString m_strIcon;                                              // +0x28
};
MS2_CHECK_OFFSET(Unk_UcServerRec, m_strIcon, 0x28);
class Unk_UcServerRef                                               // counted reference to a server record
{
public:
    ~Unk_UcServerRef();                                             // 0x1417520e0
    __int64 FUN_141752200();
    Unk_UcServerRec* FUN_141752210();
    void* m_pad_00; void* m_pad_08;
};
class Unk_UcServerSvc { public: Unk_UcServerRef FUN_141751bf0(int nServerId); };
Unk_UcServerSvc* FUN_1414a5790();
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& n);
class Unk_UcRegionRec
{
public:
    void* m_pad_00;
    CStringW m_strName;                                             // +0x08
    void* m_pad_10;
    CString m_strEmblem;                                            // +0x18
};
MS2_CHECK_OFFSET(Unk_UcRegionRec, m_strEmblem, 0x18);
class Unk_UcRegionRef                                               // counted reference to a region record
{
public:
    ~Unk_UcRegionRef();                                             // 0x140e815e0
    __int64 FUN_140e816d0();
    Unk_UcRegionRec* FUN_140e816e0();
    void* m_pad_00; void* m_pad_08;
};
class Unk_UcRegionDlg { public: Unk_UcRegionRef FUN_140e807c0(); };
Unk_UcRegionDlg* FUN_1418f6130(int nUiId);

// ---- the game and combat controllers touched by the key blocks ----
class Unk_UcBattleCtl { public: void FUN_14142bad0(int n); };
Unk_UcBattleCtl* FUN_1409331f0();
void FUN_14166cce0(PCBase* p, int nFlag);
void FUN_14166cd70(PCBase* p, int nFlag);
int FUN_1410af7a0(PCBase* p);
PCBase* FUN_1416625b0(PCBase* p);

// @0x141900750
// Fill the server-info AS object: server name and icon, and the region name and icon.
bool FUN_141900750(ASObj* pObj)
{
    Unk_UcServerDlg* pServerDlg = FUN_14136f520(0x4ef0);
    if (pServerDlg == 0)
        return false;
    if (DAT_143ab0248 != 2)
    {
        int nChannel = FUN_14092f640() < 2 ? 1 : FUN_14092f640();
        CStringW strName;
        CStringW strIcon;
        Unk_UcServerRef ref = FUN_1414a5790()->FUN_141751bf0(FUN_141ad1010(pServerDlg));
        if (ref.FUN_141752200() != 0)
        {
            strName = ref.FUN_141752210()->m_strName;
            strIcon = ref.FUN_141752210()->m_strIcon;
        }
        strName.Append(FUN_1401ceea0(L" <font size='15'>| CH.{0}</font>", nChannel));
        pObj->FUN_1407cbb20("name", strName);
        pObj->FUN_1407cbb20("iconPath", strIcon);
    }
    Unk_UcRegionDlg* pRegionDlg = FUN_1418f6130(0x4eef);
    if (pRegionDlg != 0)
    {
        Unk_UcRegionRef region = pRegionDlg->FUN_140e807c0();
        if (region.FUN_140e816d0() != 0)
        {
            pObj->FUN_1407cbb20("regionName", region.FUN_140e816e0()->m_strName);
            CString strPath("./Data/Resource/Image/Emblem/Server/");
            strPath.Append(region.FUN_140e816e0()->m_strEmblem);
            pObj->FUN_1407cba60("regionIconPath", strPath);
        }
    }
    return true;
}
MS2_REPLACE(0x141900750, FUN_141900750, 817, 0xFF8B96BB);

// ---- the key-block controller ----
// @0x141900de0
UICommon::CMyPCKeyInputController::CMyPCKeyInputController()
{
    m_nMove = 0;
    m_nSkill = 0;
    m_nAttack = 0;
}

// @0x141900e70
UICommon::CMyPCKeyInputController::~CMyPCKeyInputController()
{
}

// @0x141900ed0
int UICommon::CMyPCKeyInputController::FUN_141900ed0(int nRelease, int* pCount, int nDefault)
{
    if (nRelease != 0)
    {
        *pCount = *pCount - 1;
        *pCount = *pCount < 0 ? 0 : *pCount;
    }
    else
    {
        *pCount = *pCount + 1;
    }
    return *pCount > 0 ? 0 : nDefault;
}

// @0x141901170
int UICommon::CMyPCKeyInputController::FUN_141901170(int nRelease, int nLayer, std::set<int>* pSet)
{
    if (nRelease == 0)
    {
        if (pSet->empty() || pSet->find(nLayer) == pSet->end())
        {
            pSet->insert(nLayer);
            return 1;
        }
        return 0;
    }
    if (!pSet->empty() && pSet->find(nLayer) != pSet->end())
    {
        pSet->erase(nLayer);
        return 1;
    }
    return 0;
}

// @0x141900f70
void UICommon::CMyPCKeyInputController::FUN_141900f70(int nRelease, int nLayer)
{
    if (FUN_141901170(nRelease, nLayer, &m_skill) == 0)
        return;
    int nBlock = FUN_141900ed0(nRelease, &m_nSkill, 1);
    FUN_1403ed2b0()->FUN_141adbdc0(nBlock);
}

// @0x141900ff0
void UICommon::CMyPCKeyInputController::FUN_141900ff0(int nRelease, int nLayer)
{
    if (FUN_141901170(nRelease, nLayer, &m_attack) == 0)
        return;
    int nBlock = FUN_141900ed0(nRelease, &m_nAttack, 1);
    FUN_1409331f0()->FUN_14142bad0(nBlock);
}

// @0x141901070
void UICommon::CMyPCKeyInputController::FUN_141901070(int nRelease, int nLayer)
{
    if (FUN_141901170(nRelease, nLayer, &m_move) != 0)
    {
        PCBase* pPC = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        int nBlock = FUN_141900ed0(nRelease, &m_nMove, 1);
        if (pPC != 0)
        {
            if (nBlock == 0)
                FUN_14166cce0(pPC, 0x20);
            else
                FUN_14166cd70(pPC, 0x20);
            if (FUN_1410af7a0(pPC) != 0)
            {
                PCBase* pMount = FUN_1416625b0(pPC);
                if (pMount != 0)
                {
                    if (nBlock == 0)
                        FUN_14166cce0(pMount, 0x20);
                    else
                        FUN_14166cd70(pMount, 0x20);
                }
            }
        }
    }
}

// @0x1419012a0
void UICommon::CMyPCKeyInputController::FUN_1419012a0()
{
    m_move.clear();
    m_skill.clear();
    m_attack.clear();
    m_nAttack = 0;
    m_nMove = 0;
    m_nSkill = 0;
}

// @0x141901310
void FUN_141901310(int nRelease, unsigned nChannels, int nLayer)
{
    if ((nChannels & 1) != 0)
        s_keyInput.FUN_141901070(nRelease, nLayer);
    if ((nChannels & 2) != 0)
        s_keyInput.FUN_141900f70(nRelease, nLayer);
    if ((nChannels & 4) != 0)
        s_keyInput.FUN_141900ff0(nRelease, nLayer);
}

void FUN_141901390(int nRelease, int nLayer);
#ifndef MS2_HOOK_DLL
// @0x141901390
void FUN_141901390(int nRelease, int nLayer) { s_keyInput.FUN_141901070(nRelease, nLayer); }
#endif

void FUN_1419013c0(int nRelease, int nLayer);
#ifndef MS2_HOOK_DLL
// @0x1419013c0
void FUN_1419013c0(int nRelease, int nLayer) { s_keyInput.FUN_141900ff0(nRelease, nLayer); }
#endif

// @0x1419013f0
void FUN_1419013f0(int nRelease, int nLayer) { s_keyInput.FUN_141900f70(nRelease, nLayer); }

void FUN_141901420(int nRelease, int nLayer);
#ifndef MS2_HOOK_DLL
// @0x141901420
void FUN_141901420(int nRelease, int nLayer)
{
    s_keyInput.FUN_141901070(nRelease, nLayer);
    s_keyInput.FUN_141900f70(nRelease, nLayer);
}
#endif

void FUN_141901470(int nRelease, int nLayer);
#ifndef MS2_HOOK_DLL
// @0x141901470
void FUN_141901470(int nRelease, int nLayer)
{
    s_keyInput.FUN_141901070(nRelease, nLayer);
    s_keyInput.FUN_141900ff0(nRelease, nLayer);
}
#endif

// ---- the dialog placement record ----
// @0x1419014c0
UICommon::CAlignmentInfo::CAlignmentInfo()
{
    m_x = 0;
    m_y = 0;
    m_align = 5;
    m_defaultX = 0;
    m_defaultY = 0;
    m_defaultAlign = 5;
}

// @0x141901540
UICommon::CAlignmentInfo::CAlignmentInfo(int nAlign, float x, float y)
{
    m_x = x;
    m_y = y;
    m_align = nAlign;
    m_defaultX = x;
    m_defaultY = y;
    m_defaultAlign = nAlign;
}

// @0x1419015e0
void UICommon::CAlignmentInfo::FUN_1419015e0(Unk_140165cf0* pNode)
{
    if (pNode == 0)
        return;
    FUN_140873e30(pNode, "offsetX", m_x);
    FUN_140873e30(pNode, "offsetY", m_y);
    FUN_140873ca0(pNode, "alignType", m_align);
}
MS2_REPLACE_METHOD(0x1419015e0, UICommon::CAlignmentInfo, FUN_1419015e0, 109, 0x52121057);

// @0x141901660
bool UICommon::CAlignmentInfo::FUN_141901660(Unk_140165cf0* pNode)
{
    if (pNode == 0)
        return false;
    bool bOk = true;
    bOk &= FUN_140873360(pNode, "offsetX", m_x) == 0;
    bOk &= FUN_140873360(pNode, "offsetY", m_y) == 0;
    bOk &= FUN_1408731e0(pNode, "alignType", m_align) == 0;
    return bOk;
}
MS2_REPLACE_METHOD(0x141901660, UICommon::CAlignmentInfo, FUN_141901660, 236, 0x62D5D5F2);

// @0x141901760
void UICommon::CAlignmentInfo::FUN_141901760(MS2Ptr<AScript> spScript)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)spScript);
    if (pDialog != 0)
    {
        int nW = pDialog->FUN_1422c1500();
        int nH = pDialog->FUN_1422c1530();
        int nParentW = pDialog->FUN_1422c1340();
        int nParentH = pDialog->FUN_1422c13b0();
        FUN_141901880(spScript, (float)nParentW, (float)nParentH, (float)nW, (float)nH);
    }
}
MS2_REPLACE_METHOD(0x141901760, UICommon::CAlignmentInfo, FUN_141901760, 271, 0xD570AA8B);

// @0x141901880
// Classify where the dialog sits (quadrant of the screen) and remember the offset from that corner.
void UICommon::CAlignmentInfo::FUN_141901880(MS2Ptr<AScript> spScript, float fParentW, float fParentH, float fW, float fH)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)spScript);
    if (pDialog != 0)
    {
        float fX = pDialog->FUN_1422c10a0();
        float fY = pDialog->FUN_1422c1110();
        float fHalfW = fW * 0.5f;
        float fHalfH = fH * 0.5f;
        if (fX <= fHalfW && fY <= fHalfH)
        {
            m_align = 5;
            m_x = fX;
            m_y = fY;
        }
        else if (fX >= fHalfW && fY <= fHalfH)
        {
            m_align = 6;
            float fRight = FUN_140bf4fd0((fX + fParentW) - fW);
            float fZero = 0;
            m_x = (std::min)(fZero, fRight);
            m_y = fY;
        }
        else if (fX <= fHalfW && fY >= fHalfH)
        {
            m_align = 7;
            m_x = fX;
            m_y = FUN_140bf4fd0((fY + fParentH) - fH);
        }
        else if (fX >= fHalfW && fY >= fHalfH)
        {
            m_align = 8;
            m_x = FUN_140bf4fd0((fX + fParentW) - fW);
            m_y = FUN_140bf4fd0((fY + fParentH) - fH);
        }
        else
        {
            m_align = 5;
            m_x = fX;
            m_y = fY;
        }
    }
}
MS2_REPLACE_METHOD(0x141901880, UICommon::CAlignmentInfo, FUN_141901880, 654, 0x577517A1);

// @0x141901b20
void UICommon::CAlignmentInfo::FUN_141901b20(int nAlign, float x, float y)
{
    m_align = nAlign;
    m_x = x;
    m_y = y;
}
MS2_REPLACE_METHOD(0x141901b20, UICommon::CAlignmentInfo, FUN_141901b20, 66, 0x28B21D83);

// @0x141901b70
void UICommon::CAlignmentInfo::FUN_141901b70(MS2Ptr<AScript> spScript)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)spScript);
    if (pDialog != 0)
        pDialog->vfunc_2(m_align, (int)m_x, (int)m_y);
}

// @0x141901c10
void UICommon::CAlignmentInfo::FUN_141901c10(MS2Ptr<AScript> spScript, int nW, int nH)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)spScript);
    if (pDialog != 0)
        pDialog->vfunc_1(m_align, (int)m_x, (int)m_y, nW, nH);
}

// @0x141901cd0
void UICommon::CAlignmentInfo::FUN_141901cd0()
{
    m_align = m_defaultAlign;
    m_x = m_defaultX;
    m_y = m_defaultY;
}
MS2_REPLACE_METHOD(0x141901cd0, UICommon::CAlignmentInfo, FUN_141901cd0, 62, 0x16A663B0);

// Item counts: the bag stock, the cube fallback inventory and the stock of the plot.
class Unk_UcStockEntry : public CPtred { public: int m_nCount; };
int FUN_140dfc350(Unk_UcStockEntry* p);
int FUN_140526c50(CItem* p);
Unk_UcItemPtr FUN_14053f870(int nItemId);
class Unk_CubeFallbackInventory
{
public:
    MS2Ptr<CItem> FUN_1408fbf90(__int64 nUid);
    int FUN_1408fc1b0(int nItemId);
    int FUN_1408fc2f0(int nItemId, int nRank);
};
extern Unk_CubeFallbackInventory DAT_143ab2e20;
class Unk_CubeStock
{
public:
    MS2Ptr<Unk_UcStockEntry> FUN_140dfc8f0(__int64 nUid);
    int FUN_140dfcb00(int nItemId);
    int FUN_140dfcbf0(int nItemId, int nRank);
};
extern Unk_CubeStock DAT_143ab2e50;

// @0x141901d20
int FUN_141901d20(int nItemId, __int64 nUid, int nRank)
{
    Unk_UcItemPtr item = FUN_14053f870(nItemId);
    if (item.FUN_1401b5240(0) != 0)
        return 0;
    if (item.FUN_1401b52a0()->FUN_14053cde0() == 0)
    {
        if (item.FUN_1401b52a0()->FUN_14053d6f0() == 0)
            return DAT_143ab2e20.FUN_1408fc1b0(nItemId) + DAT_143ab2e50.FUN_140dfcb00(nItemId);
        return DAT_143ab2e20.FUN_1408fc2f0(nItemId, nRank) + DAT_143ab2e50.FUN_140dfcbf0(nItemId, nRank);
    }
    MS2Ptr<CItem> spItem = DAT_143ab2e20.FUN_1408fbf90(nUid);
    if (spItem.get() != 0)
        return FUN_140526c50(spItem.operator->());
    MS2Ptr<Unk_UcStockEntry> spStock = DAT_143ab2e50.FUN_140dfc8f0(nUid);
    if (spStock.get() == 0)
        return 0;
    return FUN_140dfc350(spStock.operator->());
}
MS2_REPLACE(0x141901d20, FUN_141901d20, 573, 0xA2CDF026);

// @0x141901f70
int FUN_141901f70(int nItemId, __int64 nUid, int nRank)
{
    Unk_UcItemPtr item = FUN_14053f870(nItemId);
    if (item.FUN_1401b5240(0) != 0)
        return 0;
    int nMode = FUN_1409670e0()->FUN_1410c3650();
    if (item.FUN_1401b52a0()->FUN_14053cde0() == 0)
    {
        if (item.FUN_1401b52a0()->FUN_14053d6f0() == 0)
        {
            int nCount = DAT_143ab2e50.FUN_140dfcb00(nItemId);
            if (nMode == 1 || nMode == 3)
                nCount += FUN_1409670e0()->FUN_1410b9b20(nItemId);
            return nCount;
        }
        int nCount = DAT_143ab2e50.FUN_140dfcbf0(nItemId, nRank);
        if (nMode == 1 || nMode == 3)
            nCount += FUN_1409670e0()->FUN_1410b9c20(nItemId, nRank);
        return nCount;
    }
    MS2Ptr<Unk_UcStockEntry> spStock = DAT_143ab2e50.FUN_140dfc8f0(nUid);
    if (spStock.get() != 0)
        return FUN_140dfc350(spStock.operator->());
    if (nMode == 1 || nMode == 3)
        return FUN_1409670e0()->FUN_1410b9d80(nUid);
    return 0;
}
MS2_REPLACE(0x141901f70, FUN_141901f70, 568, 0xE13515C1);

// @0x1419021b0
CStringW FUN_1419021b0(unsigned nCur, unsigned nMax)
{
    CStringW str;
    if (nCur < nMax)
        str = FUN_1409e9890(L"s_common_cur_max_ingredient_lack", nCur, nMax);
    else
        str = FUN_1409e9890(L"s_common_cur_max_ingredient", nCur, nMax);
    return str;
}
MS2_REPLACE(0x1419021b0, FUN_1419021b0, 348, 0x6034DBCC);

// @0x141902320
CStringW FUN_141902320(unsigned nCur, unsigned nMax)
{
    CStringW str;
    if (nCur < nMax)
        str = FUN_1409e9890(L"s_common_cur_max_ingredient_lack", nCur, nMax);
    else if (nCur == nMax)
        str = FUN_1409e9890(L"s_common_cur_max_ingredient", nCur, nMax);
    else
        str = FUN_1409e9890(L"s_common_cur_max_ingredient_overflow", nCur, nMax);
    return str;
}
MS2_REPLACE(0x141902320, FUN_141902320, 512, 0x649BF932);

// The scene object behind the current stage (FUN_1422b9e50 picks the primary or the fallback member).
class Unk_UcSceneObj
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47();
    virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55();
    virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63();
    virtual void vfunc_64();                                        // MS2: slot 64
};
void* FUN_1408e57f0();
Unk_UcSceneObj* FUN_1422b9e50(void* p);

// @0x141902530
bool FUN_141902530(int nButton, const CMsgBoxData& box)
{
    Unk_UcSceneObj* pScene = FUN_1422b9e50(FUN_1408e57f0());
    if (pScene != 0)
        pScene->vfunc_64();
    return true;
}
MS2_REPLACE(0x141902530, FUN_141902530, 65, 0xBF38A091);

// The mentoring flag table of the client config (flags at +8).
class Unk_UcFlag { public: int FUN_1402c4c90(int nFlag); };
struct Unk_UcFlags { void* m_p0; Unk_UcFlag flags; };
Unk_UcFlags* FUN_14025e7b0();

// @0x141902580
bool FUN_141902580(bool bMessage)
{
    if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x65))
    {
        if (bMessage)
            FUN_141275260(0x2f7, 1, 1);
        return false;
    }
    return FUN_140166410()->FUN_14036d570(0xe9);
}
MS2_REPLACE(0x141902580, FUN_141902580, 91, 0x9349350F);

// @0x1419025f0
bool FUN_1419025f0(bool bMessage)
{
    if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x66))
    {
        if (bMessage)
            FUN_141275260(0x2f7, 1, 1);
        return false;
    }
    return FUN_140166410()->FUN_14036d570(0xec);
}
MS2_REPLACE(0x1419025f0, FUN_1419025f0, 91, 0xD61ABD29);

// The pet / enchant part of an item (FUN_1405278a0: the record at +0xf8).
class Unk_UcItemExtra : public CPtred
{
public:
    void* m_pad_18; void* m_pad_20;
    MS2Ptr<CItemEnchantInfo> m_spEnchant;                           // +0x28
};
MS2_CHECK_OFFSET(Unk_UcItemExtra, m_spEnchant, 0x28);
Unk_UcItemExtra* FUN_1405278a0(CItem* pItem);

// @0x1419028d0
// Refund box callback: button 0 sends the confirmation packet.
bool FUN_1419028d0(int nButton, const CMsgBoxData& box)
{
    if (nButton != 0)
        return true;
    __int64 nItemUid = box.FUN_141a02f10(0, 0);
    COutPacket packet(0x5e, 0);
    packet.vfunc_o10_1(9);
    packet.vfunc_o10_4(nItemUid);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE(0x1419028d0, FUN_1419028d0, 140, 0xDDD7FCD0);

Delegate<bool(int, const CMsgBoxData&)> FUN_140b76b10(bool (*pfn)(int, const CMsgBoxData&));

// @0x141902660
// Ask whether to refund the enchant experience of the item.
bool FUN_141902660(MS2Ptr<CItem> spItem)
{
    Unk_UcItemExtra* pExtra = FUN_1405278a0(spItem.operator->());
    if (pExtra != 0)
    {
        CItemEnchantInfo* pEnchant = pExtra->m_spEnchant.get();
        if (pEnchant != 0 && pEnchant->FUN_14058cd60() != 0)
        {
            Unk_UcMsgBoxPtr spBox = FUN_140d73d20(1, FUN_14028b8e0(CStringW(L"s_itemenchant_enchant_exp_refund")), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->Append<__int64>(spItem->FUN_140526a50());
                spBox->FUN_141a024a0(false);
                spBox->FUN_141a027c0(FUN_140b76b10(FUN_1419028d0));
                FUN_140d73c60(spBox);
            }
            return true;
        }
    }
    return false;
}

// @0x141902970
int FUN_141902970(MS2Ptr<UIDialog> pDlg)
{
    if ((UIDialog*)pDlg != 0)
    {
        if (pDlg.get()->vfunc_56() != 0)
            return 0;
        if (pDlg.get()->vfunc_55() != 0)
            return 0;
        return 1;
    }
    return 0;
}

class Unk_UcMsgBox { public: int FUN_1419f8270(); };
int FUN_141adcbb0(Unk_UcUiMgr* pMgr, int (*pred)(MS2Ptr<UIDialog>));
int FUN_141a8a760();
Unk_UcMsgBox* FUN_14151f890();

// @0x141902a50
// A modal dialog or message box blocks the player.
int FUN_141902a50()
{
    if (FUN_141adcbb0(FUN_1403ed2b0(), FUN_141902970) != 0)
        return 1;
    if (FUN_141a8a760() != 0)
        return 1;
    Unk_UcMsgBox* pBox = FUN_14151f890();
    if (pBox != 0 && pBox->FUN_1419f8270() == 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x141902a50, FUN_141902a50, 97, 0x8262FEB4);

// @0x141902ac0
// The cube position of the player equals the home plot of the target (kind 7 buddy, 3 guild, else a proxy).
int FUN_141902ac0(__int64 nId, int nType)
{
    MyPC* pPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC != 0)
    {
        int nX = FUN_1409670e0()->FUN_1410c3140();
        int nY = FUN_1409670e0()->FUN_1410c3100();
        int nZ = FUN_1409670e0()->FUN_1410c3000();
        if (nType == 7)
        {
            CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4880(nId);
            if (spBuddy.get() != 0)
            {
                if (nX != spBuddy->FUN_1401cc3e0())
                    return 0;
                if (nY == spBuddy->FUN_1401cc3a0())
                {
                    if (nZ == spBuddy->FUN_1401cc3c0())
                        return 1;
                    return 0;
                }
                return 0;
            }
        }
        else if (nType == 3)
        {
            Unk_UcGuildRef guild = FUN_1403ed290()->FUN_1413b6200(nId);
            if (guild.FUN_1404f0ab0() != 0)
            {
                if (nX != guild.FUN_1404f0b80()->m_nPlotX)
                    return 0;
                if (nY == guild.FUN_1404f0b80()->m_nPlotY)
                {
                    if (nZ == guild.FUN_1404f0b80()->m_nPlotZ)
                        return 1;
                    return 0;
                }
                return 0;
            }
        }
        else
        {
            void* pMap = FUN_1403ed2d0()->FUN_141bc9fb0();
            for (void* pos = FUN_140ac5e20(pMap); pos != 0; FUN_140ac5dd0(pMap, &pos))
            {
                Unk_UcProxyRef spProxy(FUN_140ac5ed0(pMap, pos));
                if (!spProxy.IsNull() && reinterpret_cast<__int64>(spProxy->FUN_1416c22f0()) == nId)
                {
                    if (nX != spProxy->m_b4)
                        return 0;
                    if (nY == spProxy->m_b8)
                    {
                        if (nZ == spProxy->m_bc)
                            return 1;
                        return 0;
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE(0x141902ac0, FUN_141902ac0, 993, 0x843815CF);

// @0x141904710
UICommon::CAlignmentInfo::~CAlignmentInfo()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbd3e0-0x142cbd4b0 .text$yd
