// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Sound events: the effect XML type 2 "SoundEvent" (param +
// runtime effect), the FMOD event wrapper CSoundEvent and the event manager CSoundEventMgr. See soundeventmgr.h.
// MS2-UNIT: client\ms2\soundeventmgr.cpp
// MS2-RANGE: 0x140101560-0x140101680 .text$di
// MS2-RANGE: 0x141775810-0x14178fd20 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?FUN_141776260@CSoundEventEffectParam@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x141776260 ; unique
// MS2-PIN: ?FUN_141776280@CSoundEventEffectParam@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x141776280 ; unique
// MS2-PIN: ?FUN_141777700@CSoundEventEffect@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x141777700 ; unique
// MS2-PIN: ?FUN_141777770@CSoundEventEffect@@QEAAXXZ 0x141777770 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14177e940 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14177e970 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14177e9d0 ; prop
// MS2-PIN: ??$?0AEAV?$SmartPointer@VEntity@egf@@@efd@@AEAV?$MS2Ptr@VCSoundEvent@@@@$0A@@?$pair@V?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@QEAA@AEAV?$SmartPointer@VEntity@egf@@@efd@@AEAV?$MS2Ptr@VCSoundEvent@@@@@Z 0x14177ea50 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14177eab0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14177eb00 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14177eb50 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14177eba0 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14177ec40 ; unique
// MS2-PIN: ??$?0AEBU?$less@V?$SmartPointer@VEntity@egf@@@efd@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@V?$SmartPointer@VEntity@egf@@@efd@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@V?$SmartPointer@VEntity@egf@@@efd@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14177ec90 ; unique
// MS2-PIN: ??$?0AEBU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14177ece0 ; unique
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14177ed30 ; unique
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHUUnk_SoundFade@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x14177ed80 ; unique
// MS2-PIN: ??$?0AEBH$0A@@?$tuple@AEBH@std@@QEAA@AEBH@Z 0x14177edd0 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14177ef60 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14177f050 ; prop
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHUUnk_SoundFade@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14177f140 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x141780710 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1417807e0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1417808b0 ; prop
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@1@@Z 0x141781ee0 ; prop
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHUUnk_SoundFade@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHUUnk_SoundFade@@@1@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@1@@Z 0x141782b20 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@1@@Z 0x141783760 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHUUnk_SoundFade@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHUUnk_SoundFade@@@1@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@1@@Z 0x141784390 ; prop
// MS2-PIN: ??$_Kfn@$$CBHV?$TToolHistory@UParamVaule@@@@@?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@1@@Z 0x1417847a0 ; prop
// MS2-PIN: ??$_Kfn@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@?$_Tmap_traits@V?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@U?$less@V?$SmartPointer@VEntity@egf@@@efd@@@std@@V?$allocator@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@5@$0A@@std@@SAAEBV?$SmartPointer@VEntity@egf@@@efd@@AEBU?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@1@@Z 0x1417847b0 ; prop
// MS2-PIN: ??$_Kfn@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@2@$0A@@std@@SAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@AEBU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@1@@Z 0x1417847c0 ; prop
// MS2-PIN: ??$_Kfn@$$CBHUUnk_SoundFade@@@?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@SAAEBHAEBU?$pair@$$CBHUUnk_SoundFade@@@1@@Z 0x1417847d0 ; prop
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141784a60 ; prop
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141784bb0 ; unique
// MS2-PIN: ??$_Try_emplace@H$$V@?$map@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@_N@1@$$QEAH@Z 0x141784d00 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x1417851e0 ; unique
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x141785230 ; unique
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@PEAX@1@AEAPEAU31@@Z 0x141785280 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHUUnk_SoundFade@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHUUnk_SoundFade@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141785520 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x1417858c0 ; prop
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141785960 ; prop
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141785a00 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x141785e30 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x141785e40 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@PEAX@0@AEAPEAU10@@Z 0x141785e50 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@0@AEAPEAU10@@Z 0x141785e60 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141785ed0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141785ee0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141785ef0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141785f00 ; prop
// MS2-PIN: ??$forward@AEBU?$less@H@std@@@std@@YAAEBU?$less@H@0@AEBU10@@Z 0x141785f10 ; prop
// MS2-PIN: ??$forward@AEBH@std@@YAAEBHAEBH@Z 0x141785f50 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141785fa0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141785fd0 ; prop
// MS2-PIN: ??$forward@V?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x141785fe0 ; prop
// MS2-PIN: ??$make_pair@AEAV?$SmartPointer@VEntity@egf@@@efd@@AEAV?$MS2Ptr@VCSoundEvent@@@@@std@@YA?AU?$pair@V?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@0@AEAV?$SmartPointer@VEntity@egf@@@efd@@AEAV?$MS2Ptr@VCSoundEvent@@@@@Z 0x141786110 ; unique
// MS2-PIN: ??$make_type@W4FMOD_EVENT_PITCHUNITS@@@internal@fmt@@YA_KAEBW4FMOD_EVENT_PITCHUNITS@@@Z 0x141786170 ; unique
// MS2-PIN: ??$make_type@W4FMOD_RESULT@@@internal@fmt@@YA_KAEBW4FMOD_RESULT@@@Z 0x141786190 ; unique
// MS2-PIN: ??$move@AEAV?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x1417861b0 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@_N@1@$$QEAH@Z 0x1417861c0 ; unique
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141786200 ; unique
// MS2-PIN: ??$type@W4FMOD_EVENT_PITCHUNITS@@$0A@@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBW4FMOD_EVENT_PITCHUNITS@@@Z 0x141786280 ; prop
// MS2-PIN: ??$type@W4FMOD_RESULT@@$0A@@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBW4FMOD_RESULT@@@Z 0x141786290 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141786ad0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141786d10 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@QEAA@XZ 0x141786e10 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@std@@@std@@QEAA@XZ 0x141786e40 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@std@@@std@@QEAA@XZ 0x141786e70 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@QEAA@XZ 0x141786ea0 ; prop
// MS2-PIN: ??0?$allocator@U?$_List_node@UReverbData@@PEAX@std@@@std@@QEAA@XZ 0x141786ef0 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141786f00 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141786f10 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141786f30 ; prop
// MS2-PIN: ??0MusicData@@QEAA@XZ 0x141787180 ; unique
// MS2-PIN: ??0ParamVaule@@QEAA@XZ 0x1417871b0 ; unique
// MS2-PIN: ??A?$map@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@@std@@QEAAAEAV?$TToolHistory@UParamVaule@@@@$$QEAH@Z 0x141787b40 ; unique
// MS2-PIN: ??A?$map@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@@std@@QEAAAEAV?$TToolHistory@UParamVaule@@@@AEBH@Z 0x141787b80 ; unique
// MS2-PIN: ??D?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@UMusicData@@@std@@@std@@@std@@QEBAAEBUMusicData@@XZ 0x141787c80 ; prop
// MS2-PIN: ??D?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@UParamVaule@@@std@@@std@@@std@@QEBAAEBUParamVaule@@XZ 0x141787ca0 ; prop
// MS2-PIN: ??D?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@UReverbData@@@std@@@std@@@std@@QEBAAEBUReverbData@@XZ 0x141787cc0 ; prop
// MS2-PIN: ??D?$_List_iterator@V?$_List_val@U?$_List_simple_types@UMusicData@@@std@@@std@@@std@@QEBAAEAUMusicData@@XZ 0x141787ce0 ; prop
// MS2-PIN: ??D?$_List_iterator@V?$_List_val@U?$_List_simple_types@UReverbData@@@std@@@std@@@std@@QEBAAEAUReverbData@@XZ 0x141787d20 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1417881f0 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141788540 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141788560 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141788580 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1417885a0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1417885c0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141788620 ; prop
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x141788980 ; unique
// MS2-PIN: ?Get@?$TToolHistory@UMusicData@@@@QEAAHHPEAUMusicData@@@Z 0x141789570 ; unique
// MS2-PIN: ?Get@?$TToolHistory@UParamVaule@@@@QEAAHHPEAUParamVaule@@@Z 0x141789670 ; prop
// MS2-PIN: ?Get@?$TToolHistory@UReverbData@@@@QEAAHHPEAUReverbData@@@Z 0x141789770 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x14178a1d0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x14178a290 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x14178c350 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x14178c360 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_SoundFade@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x14178c3b0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x14178c850 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x14178c870 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x14178c910 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@2@@Z 0x14178cb90 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@V?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@U?$less@V?$SmartPointer@VEntity@egf@@@efd@@@std@@V?$allocator@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@std@@@5@$0A@@std@@@std@@IEBAAEBV?$SmartPointer@VEntity@egf@@@efd@@AEBU?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@V?$MS2Ptr@VCSoundEvent@@@@@2@@Z 0x14178cbb0 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@@2@$0A@@std@@@std@@IEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@AEBU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@2@@Z 0x14178cbd0 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHUUnk_SoundFade@@@2@@Z 0x14178cbf0 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVEventGroup@FMOD@@@std@@PEAX@2@_K@Z 0x14178e760 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundFade@@@std@@@std@@@std@@@2@AEBH@Z 0x14178f790 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HV?$TToolHistory@UParamVaule@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x14178fc80 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HUUnk_SoundFade@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundFade@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x14178fca0 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??$get@$0A@AEBH@std@@YAAEBH$$QEAV?$tuple@AEBH@0@@Z 0x141786020
// MS2-PIN: ??$forward_as_tuple@AEBH@std@@YA?AV?$tuple@AEBH@0@AEBH@Z 0x141785ff0
// MS2-PIN: ??$?0AEBH@?$_Tuple_val@AEBH@std@@QEAA@AEBH@Z 0x14177ee20
// MS2-PIN: ??$?0U_Exact_args_t@std@@AEBH$$V$0A@@?$tuple@AEBH@std@@QEAA@U_Exact_args_t@1@AEBH@Z 0x14177eea0
// MS2-PIN: ??$format_arg@_WW4FMOD_EVENT_PITCHUNITS@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4FMOD_EVENT_PITCHUNITS@@@Z 0x141785b60 ; hand: FormatCustomArg 0x141785da0 call site
// MS2-PIN: ??$format_arg@_WW4FMOD_RESULT@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4FMOD_RESULT@@@Z 0x141785c80 ; hand: FormatCustomArg 0x141785dd0 call site
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x141785320
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1417853d0
// MS2-PIN: ??$?0V?$tuple@$$QEAH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@QEAA@AEAV?$tuple@$$QEAH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14177f0a0
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$TToolHistory@UParamVaule@@@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14177f0f0
// MS2-PIN: ??$move@AEAV?$tuple@$$QEAH@std@@@std@@YA$$QEAV?$tuple@$$QEAH@0@AEAV10@@Z 0x140331750
// MS2-PIN: ??$get@$0A@$$QEAH@std@@YA$$QEAH$$QEAV?$tuple@$$QEAH@0@@Z 0x1403313d0
// MS2-PIN: ?Add@?$TToolHistory@UMusicData@@@@QEAAXAEBUMusicData@@@Z 0x141788c40
// MS2-PIN: ?Add@?$TToolHistory@UParamVaule@@@@QEAAXAEBUParamVaule@@@Z 0x141788d10
// MS2-PIN: ?Add@?$TToolHistory@UReverbData@@@@QEAAXAEBUReverbData@@@Z 0x141788de0
// MS2-PIN: ?vfunc_1@?$TToolHistory@UMusicData@@@@UEAAHPEAX@Z 0x141789880
// MS2-PIN: ?vfunc_2@?$TToolHistory@UMusicData@@@@UEAAHPEAX@Z 0x141789540
// MS2-PIN: ?vfunc_1@?$TToolHistory@UReverbData@@@@UEAAHPEAX@Z 0x1417898a0
// MS2-PIN: ?vfunc_2@?$TToolHistory@UReverbData@@@@UEAAHPEAX@Z 0x141789560
// MS2-PIN: ?vfunc_1@?$TToolHistory@UParamVaule@@@@UEAAHPEAX@Z 0x141789890
// MS2-PIN: ?vfunc_2@?$TToolHistory@UParamVaule@@@@UEAAHPEAX@Z 0x141789550
// MS2-PIN: ??_7?$TToolHistory@UMusicData@@@@6B@ 0x142f679f0
// MS2-PIN: ??_7?$TToolHistory@UReverbData@@@@6B@ 0x142f67a10
// MS2-PIN: ??_7?$TToolHistory@UParamVaule@@@@6B@ 0x142f67a40
// MS2-PIN: ??0?$tuple@AEBH@std@@QEAA@$$QEAV01@@Z 0x141787060
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\soundeventmgr.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "soundeventmgr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/soundservice.h"
#include <new>
#include <efd/MemoryDefines.h>
#include <NiNode.h>
#include <NiFixedString.h>
#include <NiTransform.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
int FUN_140873ad0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);      // string attribute
class Unk_GameClock { public: double FUN_141473280(); float FUN_141473210(); };
Unk_GameClock* FUN_14086d260();
CLogString* FUN_140166440();                                        // the logger
WorldService* FUN_1403ed2d0();
void FUN_1401d3700(CString& str);
int FUN_140718170(const CString& str);                              // parses an int
float FUN_140718450(const CString& str);                            // parses a float
void FUN_14015eb90(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg);
CString FUN_1411a8ae0(int n);                                       // int to string
CSoundService* FUN_140c9cb10();                                     // the sound service                                   // normalises a sound path
// The application object: the sound switch byte and the session.
class Unk_SmSession { public: int FUN_141260470(); };
class Unk_SmApp
{
public:
    char* FUN_140d13c70();                                          // the sound off switch
    Unk_SmSession* FUN_1411b1f30();
};
Unk_SmApp* FUN_1409a8b10();
void* FUN_1409849b0(void* pHandle);                                 // handle -> node pointer
void* FUN_14098d8d0(const void* pRtti, void* pObj);                 // dynamic cast through an NiRTTI
const Unk_StreamPoint& FUN_140947900(void* pNode);                  // world translate
void FUN_140a0b2a0(NiAVObject* pObj);                               // detach from the parent
bool FUN_14028d470(float a, float b);                               // nearly equal
void FUN_140194470(void* pDst, const Unk_StreamPoint& vSrc);        // NiPoint3 assignment
void FUN_140a332d0(NiTransform* pXform);                            // NiTransform default constructor
NiTransform* FUN_140a33de0(const NiTransform* pThis, void* pOut, const NiTransform* pOther);   // NiTransform::operator*
void FUN_140a35bd0(NiTransform* pDst, const NiTransform* pSrc);     // NiTransform assignment
void FUN_140aacb60(void* pNode, const NiTransform* pXf);            // sets the node's local transform
NiTransform* FUN_1409478e0(void* pNode);                            // the node's world transform
// Effect manager (singleton 0x1403ed280): scene root.
class Unk_SmEffectMgr { public: NiNode* FUN_1411a6b10(); };
Unk_SmEffectMgr* FUN_1403ed280();
// Sound property / voice pitch table.
// The 2-int pitch record (pitch, FMOD pitch units) of a voice event.
struct Unk_SoundPitch
{
    Unk_SoundPitch() : m_fPitch(0.0f), m_nUnits(FMOD_EVENT_PITCHUNITS_RAW) {}   // 0x1417781e0
    float m_fPitch;
    FMOD_EVENT_PITCHUNITS m_nUnits;
};
MS2_CHECK_SIZE(Unk_SoundPitch, 8);
class Unk_SmVoiceTable { public: void FUN_141793340(int nObjectId, Unk_SoundPitch* pPitchOut); };
Unk_SmVoiceTable* FUN_1411b1de0();
// Cooltime table of the local player.
class Unk_SmCooltimes { public: bool FUN_140a40ca0(unsigned nId); };
Unk_SmCooltimes* FUN_1411b1dc0();
// The unit's log calls (FMT_VARIADIC wrappers over CLogString::FUN_1406530d0): one COMDAT per argument list.
// @0x1417775f0
template <class A> inline void Unk_SoundLog(CLogString* log, int level, int category, const wchar_t* format, const A& a)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a), args));
}
template <class A, class B> inline void Unk_SoundLog(CLogString* log, int level, int category, const wchar_t* format,
                                                      const A& a, const B& b)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b), args));
}
template <class A, class B, class C> inline void Unk_SoundLog(CLogString* log, int level, int category,
                                                               const wchar_t* format, const A& a, const B& b, const C& c)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(c)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b, c), args));
}

template <class A, class B, class C, class D> inline void Unk_SoundLog(CLogString* log, int level, int category,
                                                                         const wchar_t* format, const A& a, const B& b,
                                                                         const C& c, const D& d)
{
    const fmt::internal::ArgArray<4>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(c),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(d)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b, c, d), args));
}
template <class A, class B, class C, class D, class E> inline void Unk_SoundLog(CLogString* log, int level, int category,
                                                                                 const wchar_t* format, const A& a,
                                                                                 const B& b, const C& c, const D& d,
                                                                                 const E& e)
{
    const fmt::internal::ArgArray<5>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(c),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(d),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(e)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b, c, d, e), args));
}

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI CSoundEventEffect::ms_RTTI("CSoundEventEffect", &CEffect::ms_RTTI);    // @0x140101560
static CString s_str143aea238("skill");                                              // @0x140101590
static CString s_str143aea230("stun");                                               // @0x1401015c0
static CString s_str143aea258("skill");                                              // @0x1401015f0
static CString s_str143aea250("stun");                                               // @0x140101620
const NiRTTI CSoundMusicEffect::ms_RTTI("CSoundMusicEffect", &CEffect::ms_RTTI);        // @0x140101650
#else
const NiRTTI CSoundEventEffect::ms_RTTI("CSoundEventEffect", &CEffect::ms_RTTI);
const NiRTTI CSoundMusicEffect::ms_RTTI("CSoundMusicEffect", &CEffect::ms_RTTI);
#endif

// @0x141775810
CSoundEventEffectParam::CSoundEventEffectParam()
    : CEffectParam(2), m_bAttachToNode(false), m_bApplyNodeTransform(false), m_bDoNotStop(false), m_fVolume(1.0f),
      m_fViewDistance(0.0f), m_strExtra(""), m_bByJob(false), m_bSkipMusicConcert(false), m_nCooltimeId(0)
{
}

// @0x1417782b0
CSoundEventEffectParam::~CSoundEventEffectParam()
{
}

// @0x141775980
MS2Ptr<CSoundEventEffectParam> FUN_141775980(CString strName, CString strCategory, float fVolume, CString strExtra)
{
    MS2Ptr<CSoundEventEffectParam> spParam(new CSoundEventEffectParam);
    spParam->m_strEvent = strName;
    spParam->m_strGroup = strCategory;
    spParam->m_fVolume = fVolume;
    spParam->m_strExtra = strExtra;
    spParam->m_str20 = "SoundEvent";
    return spParam;
}

// @0x141775af0
void CSoundEventEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408733e0(pNode, "event", m_strEvent);
    FUN_1408733e0(pNode, "group", m_strGroup);
    if (!m_strGroup.IsEmpty())
        FUN_1401d3700(m_strGroup);
    FUN_1408730a0(pNode, "byJob", m_bByJob);
    FUN_1408730a0(pNode, "isSkipMusicConcert", m_bSkipMusicConcert);
    if (m_bByJob)
    {
        FUN_141776330(pNode);
        FUN_1417764c0(pNode);
    }
    FUN_140873360(pNode, "forceHearDistance", m_fViewDistance);
    FUN_1408730a0(pNode, "doNotStop", m_bDoNotStop);
    FUN_140873220(pNode, "cooltimeID", m_nCooltimeId);
    Unk_140165cf0* pAttach = pNode->FUN_140165cf0("attachInfo");
    if (pAttach != 0)
    {
        FUN_1408730a0(pAttach, "attachToNode", m_bAttachToNode);
        FUN_1408730a0(pAttach, "applyNodeTransform", m_bApplyNodeTransform);
        FUN_1408733e0(pAttach, "parentNode", m_strParentNode);
    }
}

// @0x141775cb0
bool CSoundEventEffectParam::vfunc_2()
{
    if (!CEffectParam::vfunc_2())
        return false;
    if (!m_strGroup.IsEmpty())
    {
        const char* pszGroup = m_strGroup;
        FMOD::EventGroup* pGroup = FUN_140d13c40()->FUN_14177d6e0(pszGroup, 0);
        if (pGroup == 0)
        {
            Unk_SoundLog(FUN_140166440(), 1, 0x13, L"Sound event group을 찾을 수 없습니다[{0}] [{1}]", m_strGroup, m_str20);
            return false;
        }
        FMOD::Event* pEvent;
        if (!m_bByJob)
        {
            if (pGroup->getEvent(m_strEvent, FMOD_EVENT_INFOONLY, &pEvent) != FMOD_OK)
            {
                Unk_SoundLog(FUN_140166440(), 1, 0x13, L"Sound event ID를 찾을 수 없습니다[{0}] [{1}] [{2}]", m_strGroup,
                             m_strEvent, m_str20);
                return false;
            }
        }
        else
        {
            for (POSITION pos = m_mapJobEvent.GetStartPosition(); pos != 0; m_mapJobEvent.GetNext(pos))
            {
                CString strEvent(m_mapJobEvent.GetValueAt(pos));
                if (pGroup->getEvent(strEvent, FMOD_EVENT_INFOONLY, &pEvent) != FMOD_OK)
                {
                    Unk_SoundLog(FUN_140166440(), 1, 0x13, L"Sound event ID를 찾을 수 없습니다[{0}] [{1}]", strEvent, m_str20);
                    return false;
                }
            }
        }
    }
    return true;
}

// @0x141775fc0
CEffectPtr CSoundEventEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CSoundEventEffect;
}

// @0x141776060
bool CSoundEventEffectParam::vfunc_7(Unk_EffectTarget* pTarget)
{
    if (pTarget->m_b33)
        return true;
    if (CEffectParam::vfunc_7(pTarget))
        return true;
    if (m_bSkipMusicConcert && FUN_1403ed2d0()->FUN_141bcb150())
        return true;
    return false;
}

// @0x1417760d0
bool CSoundEventEffectParam::FUN_1417760d0() const
{
    if (m_nCooltimeId == 0)
        return true;
    if (FUN_1411b1dc0() == 0)
        return true;
    return FUN_1411b1dc0()->FUN_140a40ca0(m_nCooltimeId);
}

// @0x141776120
CString CSoundEventEffectParam::FUN_141776120(int nJob) const
{
    if (FUN_1409a8b10()->FUN_1411b1f30()->FUN_141260470() != 0)
        return m_strEvent;
    if (!m_bByJob)
        return m_strEvent;
    if (nJob == 0)
        return m_strEvent;
    CString strEvent;
    Unk_SoundJobCode nKey = (Unk_SoundJobCode)nJob;
    m_mapJobEvent.Lookup(nKey, strEvent);
    return strEvent;
}

// @0x1417762a0
float CSoundEventEffectParam::FUN_1417762a0(int nJob) const
{
    float fDelay;
    if (!m_bByJob)
    {
        fDelay = m_fStartDelay;
    }
    else if (nJob == 0)
    {
        fDelay = m_fStartDelay;
    }
    else
    {
        fDelay = 0;
        Unk_SoundJobCode nKey = (Unk_SoundJobCode)nJob;
        if (!m_mapJobDelay.Lookup(nKey, fDelay))
            fDelay = m_fStartDelay;
    }
    return fDelay;
}

// @0x141776330
// "jobEvent" = "job:event;job:event"
void CSoundEventEffectParam::FUN_141776330(Unk_140165cf0* pNode)
{
    CString strList;
    FUN_140873ad0(pNode, "jobEvent", strList);
    ATL::CAtlArray<CString> arrList;
    FUN_14015f050(strList, arrList, ";");
    for (unsigned i = 0; i < arrList.GetCount(); i++)
    {
        CString strItem(arrList[i]);
        ATL::CAtlArray<CString> arrPair;
        FUN_14015f050(strItem, arrPair, ":");
        if (arrPair.GetCount() == 2)
        {
            int nJob = atoi(arrPair[0]);
            m_mapJobEvent.SetAt((Unk_SoundJobCode)nJob, arrPair[1]);
        }
    }
}

// @0x1417764c0
// "byJobStartDelay" = "job:delay;job:delay"
void CSoundEventEffectParam::FUN_1417764c0(Unk_140165cf0* pNode)
{
    CString strList;
    FUN_140873ad0(pNode, "byJobStartDelay", strList);
    ATL::CAtlArray<CString> arrList;
    FUN_14015f050(strList, arrList, ";");
    for (unsigned i = 0; i < arrList.GetCount(); i++)
    {
        ATL::CAtlArray<CString> arrPair;
        FUN_14015f050(arrList[i], arrPair, ":");
        if (arrPair.GetCount() == 2)
        {
            int nJob = FUN_140718170(arrPair[0]);
            float fDelay = FUN_140718450(arrPair[1]);
            m_mapJobDelay.SetAt((Unk_SoundJobCode)nJob, fDelay);
        }
    }
}

// @0x141776630
CSoundEventEffect::CSoundEventEffect()
    : m_spRoot(0), m_fVolume(1.0f), m_spSound(0), m_bDoNotStop(false), m_bStopRequested(false), m_strExtra("")
{
}

// @0x1417766e0
CSoundEventEffect::~CSoundEventEffect()
{
    vfunc_7();
}

// @0x141776760
bool CSoundEventEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    if (*FUN_1409a8b10()->FUN_140d13c70() != 0)
        return false;
    const CSoundEventEffectParam* pSound = static_cast<const CSoundEventEffectParam*>(pParam);
    if (!pSound->FUN_1417760d0())
        return false;

    MS2Ptr<CSoundEvent> spSound;
    const CString& strGroup = pSound->FUN_141776260();
    NiNode* pOwner = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&pTarget->m_spObject)));
    FMOD::EventGroup* pGroup = 0;
    if (!strGroup.IsEmpty())
    {
        pGroup = FUN_140d13c40()->FUN_14177d6e0(strGroup, 0);
        if (pGroup == 0)
            return false;
    }
    if (pSound->m_bOnlyCasterMyPC && m_unk_18 != 1)
        return false;

    int nJob = pTarget->FUN_140a53050();
    CString strEvent = pSound->FUN_141776120(nJob);
    if (pGroup == 0)
    {
        if (!strEvent.IsEmpty())
            spSound = FUN_140d13c40()->FUN_14177b6a0(strEvent);
    }
    else if (!strEvent.IsEmpty())
    {
        Unk_SoundPitch kPitch;
        if (pTarget->FUN_140a53090() != 0 && strGroup.Find("ms2sound/sound/voice", 0) != -1)
            FUN_1411b1de0()->FUN_141793340(pTarget->FUN_140a53090(), &kPitch);
        spSound = FUN_140d13c40()->FUN_14177b3d0(pGroup, strEvent, kPitch.m_fPitch, kPitch.m_nUnits);
    }
    if (spSound == (CSoundEvent*)0)
        return false;

    m_dStartTime = FUN_14086d260()->FUN_141473280() + (double)pSound->FUN_1417762a0(pTarget->FUN_140a53050());
    m_dStopTime = m_dStartTime + 10.0;
    m_spSound = spSound;
    m_b2c = false;
    m_bDoNotStop = pSound->m_bDoNotStop;
    m_strExtra = pSound->m_strExtra;

    NiNode* pRootNode = new (efd::MemHint(efd::MemHint::NONE)) NiNode(0);
    Unk_NodePtr spRoot(pRootNode);
    pRootNode->SetName("Effect Root");
    m_spRoot = spRoot;

    NiTransform kXform;
    FUN_140a332d0(&kXform);
    kXform.MakeIdentity();
    NiTransform kTemp;
    if (pTarget->m_pXform != 0)
        FUN_140a35bd0(&kXform, FUN_140a33de0(pTarget->m_pXform, &kTemp, &kXform));
    if (pTarget->m_unk_20 != 0)
        FUN_140a35bd0(&kXform, FUN_140a33de0(&kXform, &kTemp, (NiTransform*)pTarget->m_unk_20));

    NiNode* pParent = 0;
    if (!pSound->m_bAttachToNode)
    {
        pParent = FUN_1403ed280()->FUN_1411a6b10();
        if (!pSound->m_bApplyNodeTransform)
        {
            FUN_140aacb60(FUN_1409475f0(&spRoot), &kXform);
        }
        else
        {
            if (pOwner == 0)
            {
                FUN_14015eb90(FUN_140166440(), 1, 0x13, L"sound event - applyNodeTransform = true 인데, RootNode가 NULL입니다.[{0}]", strEvent);
                return false;
            }
            NiNode* pNode = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI,
                pOwner->GetObjectByName(NiFixedString((const char*)pSound->FUN_141776280()))));
            if (pNode == 0)
            {
                FUN_140aacb60(FUN_1409475f0(&spRoot), &kXform);
            }
            else
            {
                FUN_140aacb60(FUN_1409475f0(&spRoot), FUN_140a33de0(FUN_1409478e0(pNode), &kTemp, &kXform));
            }
        }
    }
    else
    {
        if (pOwner == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"sound event - attachToNode = true 인데, RootNode가 NULL입니다.[{0}]", strEvent);
            return false;
        }
        pParent = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI,
            pOwner->GetObjectByName(NiFixedString((const char*)pSound->FUN_141776280()))));
        if (pParent == 0)
            pParent = pOwner;
        if (!pSound->m_bApplyNodeTransform && pParent != 0)
        {
            NiTransform kInverse;
            FUN_140a332d0(&kInverse);
            FUN_1409478e0(pParent)->Invert(kInverse);
            FUN_140aacb60(FUN_1409475f0(&spRoot), FUN_140a33de0(&kInverse, &kTemp, &kXform));
        }
        else
        {
            FUN_140aacb60(FUN_1409475f0(&spRoot), &kXform);
        }
    }
    if (pParent != 0)
    {
        pParent->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), true);
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateEffects();
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateProperties();
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->Update((float)FUN_14086d260()->FUN_141473280(), true);
    }
    m_fVolume = pSound->m_fVolume;
    m_spSound->FUN_14177abc0(FUN_1417775b0, this);
    if (FUN_14028d470(pSound->FUN_1417762a0(pTarget->FUN_140a53050()), 0.0f))
        vfunc_4();
    return true;
}

// @0x1417771a0
bool CSoundEventEffect::vfunc_9()
{
    if (!m_b2d)
    {
        double dNow = FUN_14086d260()->FUN_141473280();
        if (!FUN_14119f3c0() && m_dStartTime <= dNow)
            vfunc_4();
        if (FUN_14119f3c0() && m_spSound.get() != 0)
            m_spSound->FUN_14177a990(FUN_140947900(FUN_1409475f0(&m_spRoot)));
        if (m_bStopRequested && m_dStopTime <= dNow)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"sound event - doNotStop이 True 이며, Stop 메시지 이후 10초 경과[{0}]",
                          m_spSound->FUN_14177aca0());
            m_bDoNotStop = false;
            vfunc_5();
        }
    }
    return !m_b2d;
}

// @0x141777370
void CSoundEventEffect::vfunc_4()
{
    if (m_spSound.get() != 0)
    {
        if (FUN_140166440() != 0)
            Unk_SoundLog(FUN_140166440(), 0xc, 0x12f, L"Start SoundID {0} volume {1} {2}", m_spSound->FUN_14177aca0(),
                         m_fVolume, FUN_1411a8ae0(m_unk_18));
        m_spSound->FUN_14177a990(FUN_140947900(FUN_1409475f0(&m_spRoot)));
        m_spSound->FUN_14177acf0(m_fVolume);
        if (!m_spSound->FUN_14177a8d0())
            m_b2d = true;
    }
    m_b2e = true;
}

// @0x141777520
void CSoundEventEffect::vfunc_5()
{
    if (!m_bDoNotStop)
    {
        if (m_spSound.get() != 0)
            m_spSound->FUN_14177a920(0);
        m_b2d = true;
    }
    else
    {
        m_bStopRequested = true;
        m_dStopTime = FUN_14086d260()->FUN_141473280() + 10.0;
    }
}

// @0x1417775b0
// FMOD event callback: 4 = event finished, 6 = sound def created.
FMOD_RESULT F_CALLBACK FUN_1417775b0(FMOD_EVENT* pEvent, FMOD_EVENT_CALLBACKTYPE eType, void* pParam1, void* pParam2,
                                     void* pUserData)
{
    CSoundEventEffect* pEffect = static_cast<CSoundEventEffect*>(pUserData);
    if (eType == FMOD_EVENT_CALLBACKTYPE_EVENTFINISHED)
    {
        if (pEffect != 0)
            pEffect->FUN_141777770();
    }
    else if (eType == FMOD_EVENT_CALLBACKTYPE_SOUNDDEF_CREATE && pEffect != 0)
    {
        FUN_140c9cb10()->FUN_1417b0560(pEffect->FUN_141777700(), (FMOD::Sound**)pParam2);
    }
    return FMOD_OK;
}

// @0x141777670
void CSoundEventEffect::vfunc_7()
{
    m_b2e = false;
    FUN_140a0b2a0((NiAVObject*)FUN_1409475d0(&m_spRoot));
}

// @0x1417776b0
int CSoundEventEffect::vfunc_8(void* p)
{
    FUN_140194470(p, FUN_140947900(FUN_1409475f0(&m_spRoot)));
    return 1;
}

// @0x141777720
MS2Ptr<CSoundEvent> CSoundEventEffect::FUN_141777720()
{
    return m_spSound;
}

// @0x141778980
int CSoundEventEffect::vfunc_12()
{
    return 2;
}

// ---- CSoundEvent ----
// NiPoint3 built from coordinates / from an efd::Point3 (out-of-line copies 0x14097f250 / 0x14027dcf0).
struct Unk_SmPoint3 : public Unk_StreamPoint
{
    Unk_SmPoint3(float fX, float fY, float fZ);                     // 0x14097f250
    Unk_SmPoint3(const Unk_StreamPoint& pt);                        // 0x14027dcf0
};
// @0x14177a590
CSoundEvent::CSoundEvent(FMOD::Event* pEvent, CString strName)
    : m_pRange(0), m_pEvent(pEvent), m_nStarted(0), m_nStopped(0), m_strName(strName)
{
    float fMin;
    float fMax;
    if (m_pEvent->getProperty("3DMinDistance", &fMin, true) == FMOD_OK)
    {
        if (m_pEvent->getProperty("3DMaxDistance", &fMax, true) == FMOD_OK)
        {
            CTwoCircleCollision* pRange = new CTwoCircleCollision;
            pRange->FUN_1416c4b60(fMin);
            pRange->FUN_1416c4bf0(fMax);
            m_pRange = pRange;
        }
    }
    else
    {
        FMOD::EventGroup* pGroup;
        if (m_pEvent->getParentGroup(&pGroup) == FMOD_OK && pGroup->getProperty("3DMinDistance", &fMin) == FMOD_OK &&
            pGroup->getProperty("3DMaxDistance", &fMax) == FMOD_OK)
        {
            CTwoCircleCollision* pRange = new CTwoCircleCollision;
            pRange->FUN_1416c4b60(fMin);
            pRange->FUN_1416c4bf0(fMax);
            m_pRange = pRange;
        }
    }
}

// @0x14177a800
CSoundEvent::~CSoundEvent()
{
    m_pEvent->stop(true);
    m_pEvent->release(true, true);
    m_pEvent = 0;
    if (m_pRange != 0)
        delete m_pRange;
}

// @0x14177a8d0
bool CSoundEvent::FUN_14177a8d0()
{
    m_nStarted = 1;
    return m_pEvent->start() == FMOD_OK;
}

// @0x14177a920
void CSoundEvent::FUN_14177a920(int bFadeOut)
{
    if (bFadeOut == 0)
    {
        m_nStopped = 1;
        if (FUN_14177ab80())
            m_pEvent->stop(true);
    }
    else
    {
        m_nStarted = 0;
        m_nStopped = 0;
    }
}

// @0x14177a990
void CSoundEvent::FUN_14177a990(const Unk_StreamPoint& vPos)
{
    FMOD_VECTOR kPos = {vPos.x, vPos.z, vPos.y};
    m_pEvent->set3DAttributes(&kPos, 0, 0);
    if (m_pRange != 0)
        m_pRange->vfunc_3(Unk_SmPoint3(vPos), Unk_SmPoint3(0.0f, 0.0f, 0.0f), 1.0f);
}

// @0x14177aac0
void CSoundEvent::FUN_14177aac0(const Unk_StreamPoint& vPos, const Unk_StreamPoint& vVel)
{
    FMOD_VECTOR kPos = {vPos.x, vPos.z, vPos.y};
    FMOD_VECTOR kVel = {vVel.x, vVel.z, vVel.y};
    m_pEvent->set3DAttributes(&kPos, &kVel, 0);
}

// @0x14177ab80
int CSoundEvent::FUN_14177ab80()
{
    FMOD_EVENT_STATE nState = 0;
    m_pEvent->getState(&nState);
    return nState & FMOD_EVENT_STATE_PLAYING;
}

// @0x14177abc0
void CSoundEvent::FUN_14177abc0(FMOD_EVENT_CALLBACK pfnCallback, void* pUserData)
{
    m_pEvent->setCallback(pfnCallback, pUserData);
}

// @0x14177ac00
bool CSoundEvent::FUN_14177ac00()
{
    bool bMute;
    return m_pEvent->getMute(&bMute) == FMOD_OK;
}

// @0x14177ac50
void CSoundEvent::FUN_14177ac50(bool bMute)
{
    m_pEvent->setMute(bMute);
}

// @0x14177ac80
int CSoundEvent::FUN_14177ac80()
{
    return m_nStarted | m_nStopped;
}

// @0x14177aca0
CString CSoundEvent::FUN_14177aca0()
{
    return m_strName;
}

// @0x14177acf0
void CSoundEvent::FUN_14177acf0(float fVolume)
{
    m_pEvent->setVolume(fVolume);
}

// ---- TToolHistory ----
template <class T> TToolHistory<T>::TToolHistory() : m_nPos(0)
{
}

template <class T> TToolHistory<T>::~TToolHistory()
{
}

template <class T> void TToolHistory<T>::Add(const T& rData)
{
    if (m_list.size() > m_nPos)
    {
        typename std::list<T>::iterator it = m_list.begin();
        std::advance(it, m_nPos);
        m_list.erase(it, m_list.end());
    }
    m_list.push_back(rData);
    m_nPos = (int)m_list.size();
}

template <class T> int TToolHistory<T>::GetPos() const
{
    return m_nPos - 1;
}

template <class T> int TToolHistory<T>::Get(int nOffset, T* pOut)
{
    if (m_list.empty())
        return 0;
    int nIndex = m_nPos - 1 + nOffset;
    int bBelow = nIndex < 0;
    int bAbove = nIndex >= (int)m_list.size();
    if (bBelow | bAbove)
        return 0;
    typename std::list<T>::iterator it = m_list.begin();
    std::advance(it, nIndex);
    m_nPos = nIndex + 1;
    *pOut = *it;
    return 1;
}

template <class T> void TToolHistory<T>::Clear()
{
    m_list.clear();
    m_nPos = 0;
}

// @0x1417871e0
ReverbData::ReverbData() : m_nPriority(0x100)
{
    memset(&m_props, 0, sizeof(m_props));
}

// ---- CSoundEventMgr ----
// @0x141786300
TSingleton<CSoundEventMgr>::TSingleton()
{
    s_instance = static_cast<CSoundEventMgr*>(this);
}

// FMOD_RESULT to text: the second copy of the SDK's FMOD_ErrorString in this unit.
// @0x141788f10
const char* FUN_141788f10(FMOD_RESULT nResult)
{
    const char* pszText;
    switch ((int)nResult)
    {
#include "soundservice_errors.inc"
    }
    return pszText;
}

// Out-of-unit callees of the manager.
std::string& FUN_1401d2950(std::string& str);                       // normalises a group path (lower case, slashes)
CString FUN_14038f6d0(const CString& strA, const char* pszB);        // operator+
void FUN_1403b0310(std::vector<CString>* pVec, const CString& rItem);   // push_back
void FUN_1401859c0(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat);
void FUN_140177a80(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const int& nArg);
void FUN_1403a1280(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const char* const& pszArg);
int FUN_1408a2060(egf::Entity* pEntity, unsigned nProperty, efd::utf8string* pOut);         // property: string
void FUN_1409618c0(egf::Entity* pEntity, unsigned nProperty, Unk_StreamPoint* pOut);        // property: point
class Unk_SmUiMgr { public: void FUN_141adbf70(unsigned bMute); };
Unk_SmUiMgr* FUN_1403ed2b0();

// The category names of the designer project (index = event category slot).
static const char* s_apszCategory[11] = {"effect", "environment", "bgm", "UISound", "npcVoice", "SystemVoice",
                                         "mobVoice", "EmotionVoice", "SystemAlert", "effectSpecialSkill", "PCVoice"};
static int s_nParamHistoryOffset = -1;                              // @0x1439f86a8
FMOD_RESULT F_CALLBACK FUN_14177caf0(FMOD_MUSIC_CALLBACKTYPE type, void* param1, void* param2, void* userdata);

// @0x14177ad20
CSoundEventMgr::CSoundEventMgr()
    : m_pEventSystem(0), m_p10(0), m_pMusicSystem(0), m_fMusicVolume(1.0f), m_fNowMusicVolume(1.0f), m_f2c(1.0f),
      m_b30(true), m_bMusicPlaying(0), m_bReady(0), m_n118(0)
{
    for (unsigned i = 0; i < 11; ++i)
        m_apCategory[i] = 0;
}

// @0x14177aea0
CSoundEventMgr::~CSoundEventMgr()
{
}

// @0x14177af40
void CSoundEventMgr::FUN_14177af40(FMOD::EventSystem* pSystem, void* pParam)
{
    if (pSystem == 0 || pParam == 0)
        return;
    m_pEventSystem = pSystem;
    m_p10 = pParam;
    pSystem->getMusicSystem(&m_pMusicSystem);
    if (m_pMusicSystem == 0)
        return;
    m_pMusicSystem->setCallback(FUN_14177caf0, this);
    m_pMusicSystem->getVolume(&m_fMusicVolume);
    m_fNowMusicVolume = m_fMusicVolume;
    for (unsigned i = 0; i < 11; ++i)
        m_pEventSystem->getCategory(s_apszCategory[i], &m_apCategory[i]);

    ReverbData kReverb;
    if (m_histReverb.GetPos() == -1)
    {
        m_pEventSystem->getReverbPreset("Off", &kReverb.m_props, 0);
        m_histReverb.Add(kReverb);
    }
    m_bReady = 1;
}

// @0x14177b3d0
MS2Ptr<CSoundEvent> CSoundEventMgr::FUN_14177b3d0(FMOD::EventGroup* pGroup, const char* pszName, float fPitch,
                                                  FMOD_EVENT_PITCHUNITS eUnits)
{
    if (m_bReady == 0)
        return MS2Ptr<CSoundEvent>(0);
    if (pGroup == 0)
        return FUN_14177b6a0(pszName);

    FMOD::Event* pEvent = 0;
    FMOD_RESULT nResult = pGroup->getEvent(pszName, FMOD_EVENT_DEFAULT, &pEvent);
    if (nResult == FMOD_OK)
    {
        if (eUnits != 0)
            pEvent->setPitch(fPitch, eUnits);
        Unk_SoundLog(FUN_140166440(), 0xc, 0x12f, L"SoundID {0} pitch {1} pitchUnit {2}", pszName, fPitch, eUnits);
        return MS2Ptr<CSoundEvent>(new CSoundEvent(pEvent, CString(pszName)));
    }
    if (nResult == FMOD_ERR_EVENT_FAILED)
    {
        const char* pszError = FUN_141788f10(nResult);
        Unk_SoundLog(FUN_140166440(), 0xc, 0x12f, L"SoundID:{0} Code:{1}({2})", pszName, nResult, pszError);
    }
    else
    {
        const char* pszError = FUN_141788f10(nResult);
        Unk_SoundLog(FUN_140166440(), 1, 0x12f, L"SoundID:{0} Code:{1}({2})", pszName, nResult, pszError);
    }
    return MS2Ptr<CSoundEvent>(0);
}

// @0x14177b6a0
MS2Ptr<CSoundEvent> CSoundEventMgr::FUN_14177b6a0(const char* pszName)
{
    if (m_bReady == 0)
        return MS2Ptr<CSoundEvent>(0);

    FMOD::Event* pEvent = 0;
    FMOD_RESULT nResult = m_pEventSystem->getEvent(pszName, FMOD_EVENT_DEFAULT, &pEvent);
    if (nResult == FMOD_OK)
    {
        if (FUN_140166440() != 0)
            Unk_SoundLog(FUN_140166440(), 0xc, 0x12f, L"SoundID {0}", pszName);
        return MS2Ptr<CSoundEvent>(new CSoundEvent(pEvent, CString(pszName)));
    }
    if (nResult == FMOD_ERR_EVENT_FAILED)
    {
        if (FUN_140166440() != 0)
        {
            const char* pszError = FUN_141788f10(nResult);
            Unk_SoundLog(FUN_140166440(), 0xc, 0x12f, L"SoundID:{0} Code:{1}({2})", pszName, nResult, pszError);
        }
    }
    else
    {
        const char* pszError = FUN_141788f10(nResult);
        Unk_SoundLog(FUN_140166440(), 1, 0x12f, L"SoundID:{0} Code:{1}({2})", pszName, nResult, pszError);
    }
    return MS2Ptr<CSoundEvent>(0);
}

// @0x14177b900
void CSoundEventMgr::FUN_14177b900()
{
    if (m_bReady)
    {
        FUN_14177ddf0(1, 1000);
        m_b30 = true;
    }
}

// @0x14177b940
void CSoundEventMgr::FUN_14177b940()
{
    if (m_bReady)
    {
        m_b30 = false;
        FUN_14177dea0(1, 1000);
        for (std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.begin();
             it != m_mapEnvSounds.end(); ++it)
        {
            if (it->second.get())
                it->second->FUN_14177a920(0);
        }
        m_mapEnvSounds.clear();
    }
}

// @0x14177ba30
void CSoundEventMgr::FUN_14177ba30()
{
    if (m_bReady)
    {
        FUN_14177d5e0();
        FUN_14177c8a0();
        for (std::map<std::string, FMOD::EventGroup*>::iterator it = m_mapGroups.begin(); it != m_mapGroups.end();
             ++it)
        {
            if (it->second)
                it->second->freeEventData(0, true);
        }
        m_mapGroups.clear();
        for (unsigned i = 0; i < 11; ++i)
            m_apCategory[i] = 0;
        m_pEventSystem = 0;
        m_p10 = 0;
        m_bReady = 0;
    }
}

// @0x14177bb70
void CSoundEventMgr::FUN_14177bb70()
{
    if (m_bReady)
    {
        FUN_14177bbc0();
        if (m_b30)
            FUN_14177d230();
    }
}

// @0x14177bbc0
void CSoundEventMgr::FUN_14177bbc0()
{
    if (m_mapFades.empty())
        return;
    std::map<int, Unk_SoundFade>::iterator it = m_mapFades.begin();
    while (it != m_mapFades.end())
    {
        Unk_SoundFade& rFade = it->second;
        if (rFade.m_timer.FUN_140868ba0() == 0)
        {
            // the fade is over: set the final volume
            if (rFade.m_nMode == 2)
                FUN_14177da80(rFade.m_nCategory, 0.0f);
            else if (rFade.m_nMode == 1)
                FUN_14177da80(rFade.m_nCategory, rFade.m_fVolume);
            m_mapFades.erase(it++);
        }
        else
        {
            float fVolume = -1.0f;
            if (rFade.m_nMode == 2)
                fVolume = (1.0f - rFade.m_timer.FUN_140868940()) * rFade.m_fVolume;
            else if (rFade.m_nMode == 1)
                fVolume = rFade.m_timer.FUN_140868940() * rFade.m_fVolume;
            if (0.0f <= fVolume)
                FUN_14177da80(rFade.m_nCategory, fVolume);
            ++it;
        }
    }
}

// @0x14177bda0
void CSoundEventMgr::FUN_14177bda0()
{
    if (m_bReady == 0)
        return;
    FUN_1401859c0(FUN_140166440(), 0xc, 0x12f, L"LostSoundDevice");
    FUN_14177d380();
    for (std::map<std::string, FMOD::EventGroup*>::iterator it = m_mapGroups.begin(); it != m_mapGroups.end(); ++it)
    {
        if (it->second)
            it->second->freeEventData(0, true);
    }
    m_mapGroups.clear();
    if (m_pMusicSystem)
    {
        m_pMusicSystem->reset();
        m_pEventSystem = 0;
    }
    m_bMusicPlaying = 0;
    for (unsigned i = 0; i < 11; ++i)
        m_apCategory[i] = 0;
    m_p10 = 0;
    m_bReady = 0;
}

// @0x14177bf20
void CSoundEventMgr::FUN_14177bf20()
{
    for (std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.begin();
         it != m_mapEnvSounds.end(); ++it)
    {
        efd::utf8string strEvent;
        FUN_1408a2060(it->first, 0xed530c5f, &strEvent);
        if (!strEvent.empty())
            it->second = FUN_14177b6a0(strEvent.c_str());
    }
    if (*FUN_1409a8b10()->FUN_140d13c70() == 0)
        FUN_1403ed2d0()->FUN_141bc7b80(1);
    if (0 < m_histReverb.GetPos())
    {
        ReverbData kReverb;
        m_histReverb.Get(0, &kReverb);
        m_pEventSystem->setReverbProperties(&kReverb.m_props);
    }
    FUN_1401859c0(FUN_140166440(), 0xc, 0x12f, L"RestSoundDevice");
    m_bReady = 1;
}

// @0x14177c100
int CSoundEventMgr::FUN_14177c100(int nMusicId, float fParam, unsigned nPriority, int bForce)
{
    if (m_bReady == 0)
        return 0;
    MusicData kCurrent;
    m_histMusic.Get(0, &kCurrent);
    if (nMusicId == 0)
    {
        if (bForce == 0 && kCurrent.m_nPriority < nPriority)
            return 1;
        MusicData kPrevious;
        if (m_histMusic.Get(-1, &kPrevious) != 0)
        {
            m_histMusic.Add(kPrevious);
            FMOD_RESULT nResult = m_pMusicSystem->promptCue(kPrevious.m_nId);
            if (nResult == FMOD_OK)
            {
                FUN_14177c420(5, fParam, nPriority, 0);
                FUN_140177a80(FUN_140166440(), 0xc, 0x12f, L"PlayMusic {0}", kPrevious.m_nId);
                m_bMusicPlaying = 1;
                return 1;
            }
            const char* pszError = FUN_141788f10(nResult);
            Unk_SoundLog(FUN_140166440(), 1, 0x12f, L"PlayMusic SoundID:{0} Code:{1}({2})", (unsigned)kPrevious.m_nId, nResult,
                         pszError);
        }
    }
    else if ((nPriority <= kCurrent.m_nPriority || bForce != 0) && (kCurrent.m_nId != nMusicId || bForce != 0))
    {
        kCurrent.m_nId = nMusicId;
        kCurrent.m_nPriority = nPriority;
        m_histMusic.Add(kCurrent);
        FMOD_RESULT nResult = m_pMusicSystem->promptCue(nMusicId);
        if (nResult == FMOD_OK)
        {
            FUN_14177c420(5, fParam, nPriority, 0);
            m_bMusicPlaying = 1;
            FUN_140177a80(FUN_140166440(), 0xc, 0x12f, L"PlayMusic {0}", nMusicId);
            return 1;
        }
        const char* pszError = FUN_141788f10(nResult);
        Unk_SoundLog(FUN_140166440(), 1, 0x12f, L"PlayMusic SoundID:{0} Code:{1}({2})", (unsigned)nMusicId, nResult, pszError);
    }
    return 0;
}

#ifndef MS2_HOOK_DLL
// @0x14177c420
int CSoundEventMgr::FUN_14177c420(int nParamId, float fValue, unsigned nPriority, int bForce)
{
    if (nParamId == 0)
        return 1;
    if (m_bReady == 0)
        return 0;
    ParamVaule kCurrent;
    m_mapParams[nParamId].Get(0, &kCurrent);
    if (fValue == -1.0f)
    {
        // -1 = fall back to the previous value of the parameter
        if (kCurrent.m_nPriority < nPriority)
        {
            --s_nParamHistoryOffset;
            return 1;
        }
        ParamVaule kPrevious;
        if (m_mapParams[nParamId].Get(s_nParamHistoryOffset, &kPrevious) != 0)
        {
            FMOD_RESULT nResult = m_pMusicSystem->setParameterValue(nParamId, kPrevious.m_fValue);
            if (nResult == FMOD_OK)
            {
                s_nParamHistoryOffset = -1;
                return 1;
            }
            const char* pszError = FUN_141788f10(nResult);
            int nCue = FUN_14177caa0();
            Unk_SoundLog(FUN_140166440(), 1, 0x12f, L"Error {0}: [MusicID:{1}] SetMusicParameter {2} {3} {4}", nResult,
                         (unsigned)nCue, (unsigned)nParamId, kPrevious.m_fValue, pszError);
        }
        s_nParamHistoryOffset = -1;
    }
    else if (nPriority <= kCurrent.m_nPriority || bForce != 0)
    {
        kCurrent.m_fValue = fValue;
        kCurrent.m_nPriority = nPriority;
        m_mapParams[nParamId].Add(kCurrent);
        FMOD_RESULT nResult = m_pMusicSystem->setParameterValue(nParamId, fValue);
        if (nResult == FMOD_OK)
            return 1;
        const char* pszError = FUN_141788f10(nResult);
        int nCue = FUN_14177caa0();
        Unk_SoundLog(FUN_140166440(), 1, 0x12f, L"Error {0}: [MusicID:{1}] SetMusicParameter {2} {3} {4}", nResult,
                     (unsigned)nCue, (unsigned)nParamId, fValue, pszError);
    }
    return 0;
}
#endif

// @0x14177c710
int CSoundEventMgr::FUN_14177c710(int nParamId, float* pfValue)
{
    if (m_bReady == 0)
        return 0;
    FMOD_RESULT nResult = m_pMusicSystem->getParameterValue(nParamId, pfValue);
    if (nResult == FMOD_OK)
        return 1;
    const char* pszError = FUN_141788f10(nResult);
    int nCue = FUN_14177caa0();
    Unk_SoundLog(FUN_140166440(), 1, 0x12f, L"Error{0} : [cue {1}] getParameterValue:{2} {3}", nResult, (unsigned)nCue,
                 (unsigned)nParamId, pszError);
    return 0;
}

// @0x14177c7e0
bool CSoundEventMgr::FUN_14177c7e0(bool bPaused)
{
    if (m_bReady == 0)
        return false;
    return m_pMusicSystem->setPaused(bPaused) == FMOD_OK;
}

// @0x14177c850
void CSoundEventMgr::FUN_14177c850()
{
    if (m_bReady)
    {
        m_pMusicSystem->reset();
        m_bMusicPlaying = 0;
    }
}

// @0x14177c8a0
void CSoundEventMgr::FUN_14177c8a0()
{
    if (m_bReady == 0)
        return;
    if (m_pMusicSystem)
    {
        m_pMusicSystem->reset();
        m_pMusicSystem->setVolume(m_fMusicVolume);
    }
    m_fNowMusicVolume = m_fMusicVolume;
    m_bMusicPlaying = 0;
    m_histMusic.Clear();
    m_mapParams.clear();
    m_histReverb.Clear();
    FUN_1401859c0(FUN_140166440(), 0xc, 0x12f, L"ResetMusic");
}

// @0x14177c980
void CSoundEventMgr::FUN_14177c980(unsigned bMute)
{
    if (m_bReady)
        m_pMusicSystem->setMute((bMute & 1) != 0);
}

// @0x14177c9e0
float CSoundEventMgr::FUN_14177c9e0()
{
    float fVolume;
    if (m_bReady == 0)
        fVolume = 0.0f;
    else
        m_pMusicSystem->getVolume(&fVolume);
    return fVolume;
}

// @0x14177ca30
void CSoundEventMgr::FUN_14177ca30(float fVolume)
{
    if (m_bReady)
    {
        m_pMusicSystem->setVolume(fVolume);
        m_fMusicVolume = fVolume;
        m_fNowMusicVolume = fVolume;
    }
}

// @0x14177caa0
int CSoundEventMgr::FUN_14177caa0()
{
    MusicData kCurrent;
    if (m_bReady)
        m_histMusic.Get(0, &kCurrent);
    return kCurrent.m_nId;
}

// The music callback: a cue's parameter 5 (the loop switch) toggles between 0 and 10.
// @0x14177caf0
FMOD_RESULT F_CALLBACK FUN_14177caf0(FMOD_MUSIC_CALLBACKTYPE type, void* param1, void* param2, void* userdata)
{
    float fValue = 0.0f;
    CSoundEventMgr* pMgr = static_cast<CSoundEventMgr*>(userdata);
    if (type == 0 && pMgr != 0 && pMgr->FUN_14177c710(5, &fValue) != 0)
    {
        if (FUN_14028d470(fValue, 10.0f))
            pMgr->FUN_14177c420(5, 0.0f, 0x80, 0);
        else if (FUN_14028d470(fValue, 0.0f))
            pMgr->FUN_14177c420(5, 10.0f, 0x80, 0);
    }
    return FMOD_OK;
}

// @0x14177cbe0
MS2Ptr<CSoundEvent> CSoundEventMgr::FUN_14177cbe0(Unk_EntityPtr spEntity, const char* pszEvent)
{
    if (m_bReady)
    {
        std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.find(spEntity);
        if (it != m_mapEnvSounds.end())
            return it->second;
        MS2Ptr<CSoundEvent> spSound = FUN_14177b6a0(pszEvent);
        if (spSound.get())
        {
            m_mapEnvSounds.insert(std::make_pair(spEntity, spSound));
            FUN_14015eb90(FUN_140166440(), 0xc, 0x12f, L"CreateEnvironmentSound [{0}]", CString(pszEvent));
            return spSound;
        }
    }
    return MS2Ptr<CSoundEvent>(0);
}

// @0x14177ce30
void CSoundEventMgr::FUN_14177ce30(Unk_EntityPtr spEntity, int bOn)
{
    if (m_bReady == 0)
        return;
    std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.find(spEntity);
    if (it != m_mapEnvSounds.end())
    {
        efd::utf8string strEvent;
        FUN_1408a2060(spEntity, 0xed530c5f, &strEvent);
        if (bOn == 0)
        {
            it->second->FUN_14177a920(0);
        }
        else if (it->second->FUN_14177aca0() == CString(strEvent.c_str()))
        {
            it->second->FUN_14177a920(bOn);
        }
        else
        {
            // the entity's sound event changed: replace the sound
            FUN_14177d450(Unk_EntityPtr(spEntity));
            if (!strEvent.empty())
            {
                MS2Ptr<CSoundEvent> spNew = FUN_14177cbe0(Unk_EntityPtr(spEntity), strEvent.c_str());
            }
        }
    }
    else if (bOn != 0)
    {
        Unk_StreamPoint vPos;
        efd::utf8string strEvent;
        FUN_1408a2060(spEntity, 0xed530c5f, &strEvent);
        FUN_1409618c0(spEntity, 0xfd95ca52, &vPos);
        if (!strEvent.empty())
        {
            MS2Ptr<CSoundEvent> spSound = FUN_14177cbe0(Unk_EntityPtr(spEntity), strEvent.c_str());
            if (spSound.get())
            {
                spSound->FUN_14177a990(vPos);
                spSound->FUN_14177a920(bOn);
            }
        }
    }
}

// @0x14177d230
void CSoundEventMgr::FUN_14177d230()
{
    if (m_bReady == 0)
        return;
    Unk_StreamPoint vPos;
    for (std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.begin();
         it != m_mapEnvSounds.end(); ++it)
    {
        if (it->second.get() && it->second->FUN_14177ac80() == 0)
        {
            FUN_1409618c0(it->first, 0xfd95ca52, &vPos);
            it->second->FUN_14177a990(vPos);
            it->second->FUN_14177a8d0();
        }
    }
}

// @0x14177d380
void CSoundEventMgr::FUN_14177d380()
{
    if (m_bReady == 0)
        return;
    for (std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.begin();
         it != m_mapEnvSounds.end(); ++it)
    {
        if (it->second.get())
        {
            it->second->FUN_14177a920(0);
            it->second = 0;
        }
    }
}

// @0x14177d450
void CSoundEventMgr::FUN_14177d450(Unk_EntityPtr spEntity)
{
    if (m_bReady == 0)
        return;
    std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.find(spEntity);
    if (it != m_mapEnvSounds.end())
    {
        efd::utf8string strEvent;
        FUN_1408a2060(it->first, 0xed530c5f, &strEvent);
        const char* pszEvent = strEvent.c_str();
        FUN_1403a1280(FUN_140166440(), 0xc, 0x12f, L"Remove Environment Sound [{0}]", pszEvent);
        if (it->second.get())
            it->second->FUN_14177a920(0);
        m_mapEnvSounds.erase(it);
    }
}

// @0x14177d5e0
void CSoundEventMgr::FUN_14177d5e0()
{
    if (m_bReady == 0)
        return;
    FUN_1401859c0(FUN_140166440(), 0xc, 0x12f, L"Clear Environment Sounds");
    if (m_bReady)
    {
        for (std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.begin();
             it != m_mapEnvSounds.end(); ++it)
        {
            if (it->second.get())
                it->second->FUN_14177a920(0);
        }
    }
    m_mapEnvSounds.clear();
}

// @0x14177d6e0
FMOD::EventGroup* CSoundEventMgr::FUN_14177d6e0(const char* pszName, int bLoad)
{
    if (m_bReady)
    {
        std::string strKey(pszName);
        std::map<std::string, FMOD::EventGroup*>::iterator it = m_mapGroups.find(FUN_1401d2950(strKey));
        if (it != m_mapGroups.end())
            return it->second;
        FMOD::EventGroup* pGroup;
        FMOD_RESULT nResult = m_pEventSystem->getGroup(pszName, false, &pGroup);
        if (nResult == FMOD_OK && pszName)
        {
            if (bLoad)
                pGroup->loadEventData(FMOD_EVENT_RESOURCE_STREAMS_AND_SAMPLES, FMOD_EVENT_DEFAULT);
            m_mapGroups.insert(std::make_pair(pszName, pGroup));
            return pGroup;
        }
    }
    return 0;
}

// @0x14177d860
void CSoundEventMgr::FUN_14177d860(const char* pszName)
{
    if (m_bReady == 0)
        return;
    std::string strKey(pszName);
    std::map<std::string, FMOD::EventGroup*>::iterator it = m_mapGroups.find(FUN_1401d2950(strKey));
    if (it != m_mapGroups.end())
    {
        FMOD::EventGroup* pGroup = it->second;
        pGroup->freeEventData(0, true);
        m_mapGroups.erase(it);
    }
    else
    {
        FMOD::EventGroup* pGroup;
        if (m_pEventSystem->getGroup(pszName, false, &pGroup) == FMOD_OK)
            pGroup->freeEventData(0, true);
    }
}

// The event names below a group, "group/sub/event".
// @0x14177e3d0
static void FUN_14177e3d0(FMOD::EventGroup* pGroup, CString strPrefix, std::vector<CString>& rNames)
{
    int nGroups = 0;
    int nEvents = 0;
    if (pGroup->getNumEvents(&nEvents) != FMOD_OK)
    {
        MS2_ASSERT_AT(0x4e3, 0);
        return;
    }
    if (pGroup->getNumGroups(&nGroups) != FMOD_OK)
    {
        MS2_ASSERT_AT(0x4ea, 0);
        return;
    }
    for (int i = 0; i < nGroups; ++i)
    {
        FMOD::EventGroup* pSub = 0;
        pGroup->getGroupByIndex(i, false, &pSub);
        if (pSub == 0)
            continue;
        int nIndex = 0;
        char* pszName = 0;
        if (pSub->getInfo(&nIndex, &pszName) == FMOD_OK)
        {
            CString strPath(strPrefix);
            if (!strPath.IsEmpty())
                strPath = FUN_14038f6d0(strPath, "/");
            strPath = FUN_14038f6d0(strPath, pszName);
            FUN_14177e3d0(pSub, CString(strPath), rNames);
        }
        else
        {
            MS2_ASSERT_AT(0x4fa, 0);
        }
    }
    for (int i = 0; i < nEvents; ++i)
    {
        FMOD::Event* pEvent = 0;
        if (pGroup->getEventByIndex(i, FMOD_EVENT_INFOONLY, &pEvent) != FMOD_OK)
        {
            MS2_ASSERT_AT(0x50c, 0);
            return;
        }
        if (pEvent == 0)
        {
            MS2_ASSERT_AT(0x512, 0);
            return;
        }
        int nIndex = 0;
        char* pszName = 0;
        FMOD_EVENT_INFO kInfo;
        if (pEvent->getInfo(&nIndex, &pszName, &kInfo) != FMOD_OK)
        {
            MS2_ASSERT_AT(0x51b, 0);
            return;
        }
        FUN_1403b0310(&rNames, FUN_14038f6d0(FUN_14038f6d0(strPrefix, "/"), pszName));
    }
}

// @0x14177d9b0
void CSoundEventMgr::FUN_14177d9b0(const char* pszGroup, std::vector<CString>& rNames)
{
    if (pszGroup == 0)
    {
        MS2_ASSERT_AT(0x38b, 0);
        return;
    }
    FMOD::EventGroup* pGroup = FUN_140d13c40()->FUN_14177d6e0(pszGroup, 1);
    if (pGroup == 0)
    {
        MS2_ASSERT_AT(0x392, 0);
        return;
    }
    FUN_14177e3d0(pGroup, CString(""), rNames);
}

// @0x14177da80
void CSoundEventMgr::FUN_14177da80(int nCategory, float fVolume)
{
    if (m_bReady == 0)
        return;
    if (nCategory == 2)
    {
        m_pMusicSystem->setVolume(fVolume);
        m_fMusicVolume = fVolume;
        m_fNowMusicVolume = fVolume;
    }
    else if (nCategory == 1)
    {
        m_f2c = fVolume;
    }
    if (m_apCategory[nCategory])
        m_apCategory[nCategory]->setVolume(fVolume);
}

// @0x14177db60
float CSoundEventMgr::FUN_14177db60(int nCategory)
{
    float fVolume;
    if (m_bReady == 0 || m_apCategory[nCategory] == 0)
    {
        fVolume = 0.0f;
    }
    else
    {
        fVolume = 0.0f;
        m_apCategory[nCategory]->getVolume(&fVolume);
    }
    return fVolume;
}

// @0x14177dbe0
void CSoundEventMgr::FUN_14177dbe0(int nCategory, unsigned bMute)
{
    if (m_bReady == 0)
        return;
    if (nCategory == 2)
        FUN_14177c980(bMute);
    if (m_apCategory[nCategory])
        m_apCategory[nCategory]->setMute((bMute & 1) != 0);
}

// @0x14177dc80
void CSoundEventMgr::FUN_14177dc80(unsigned bMute)
{
    if (m_bReady == 0)
        return;
    FUN_14177c980(bMute);
    for (unsigned i = 0; i < 11; ++i)
    {
        if (m_apCategory[i])
            m_apCategory[i]->setMute((bMute & 1) != 0);
    }
    FUN_1403ed2b0()->FUN_141adbf70(bMute);
}

// @0x14177dd50
bool CSoundEventMgr::FUN_14177dd50(int nCategory)
{
    bool bMute;
    if (m_bReady == 0 || m_apCategory[nCategory] == 0)
    {
        bMute = false;
    }
    else
    {
        bMute = false;
        m_apCategory[nCategory]->getMute(&bMute);
    }
    return bMute;
}

// @0x14177ddd0
int CSoundEventMgr::FUN_14177ddd0(void*, int, int)
{
    return 1;
}

// @0x14177ddf0
void CSoundEventMgr::FUN_14177ddf0(int nCategory, int nMs)
{
    Unk_SoundFade kFade;
    kFade.m_nCategory = nCategory;
    kFade.m_nMode = 1;
    kFade.m_fVolume = FUN_14177db60(nCategory);
    kFade.m_timer.FUN_140868750(nMs);
    m_mapFades[nCategory] = kFade;
}

// @0x14177dea0
void CSoundEventMgr::FUN_14177dea0(int nCategory, int nMs)
{
    Unk_SoundFade kFade;
    kFade.m_nCategory = nCategory;
    kFade.m_nMode = 2;
    kFade.m_fVolume = FUN_14177db60(nCategory);
    kFade.m_timer.FUN_140868750(nMs);
    m_mapFades[nCategory] = kFade;
}

// @0x14177df50
void CSoundEventMgr::FUN_14177df50(int nCategory, float fVolume)
{
    std::map<int, Unk_SoundFade>::iterator it = m_mapFades.find(nCategory);
    if (it != m_mapFades.end())
    {
        FUN_14177da80(nCategory, fVolume);
        m_mapFades.erase(it);
    }
}

// @0x14177e020
CStringW CSoundEventMgr::FUN_14177e020()
{
    CStringW strText;
    if (m_bReady == 0)
    {
        strText.Format(L"Failed to initialize CSoundEventMgr");
    }
    else
    {
        ParamVaule kParam;
        m_mapParams[5].Get(0, &kParam);
        bool bMute = false;
        m_pMusicSystem->getMute(&bMute);
        strText.Format(L"Music ID[%d]\nIsPlayMusic[%d]\nMute[%d]\nm_fNowMusicVolume[%f] GetMusicVolume[%f]\ncurrentParam[%f]",
                       FUN_14177caa0(), m_bMusicPlaying, (unsigned)bMute, (double)m_fNowMusicVolume,
                       (double)FUN_14177c9e0(), (double)kParam.m_fValue);
    }
    return strText;
}

// @0x14177e1c0
void CSoundEventMgr::FUN_14177e1c0()
{
    if (m_bReady == 0)
        return;
    for (std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.begin();
         it != m_mapEnvSounds.end(); ++it)
    {
        if (it->second.get() && it->second->FUN_1411b1ba0() && it->second->FUN_14177ab80() != 0)
            it->second->FUN_1411b1ba0()->vfunc_1();
    }
}

// @0x14177e2e0
void CSoundEventMgr::FUN_14177e2e0(int bFlag)
{
    m_n118 = bFlag;
    if (bFlag != 0)
    {
        for (std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> >::iterator it = m_mapEnvSounds.begin();
             it != m_mapEnvSounds.end(); ++it)
        {
            efd::utf8string strEvent;
            FUN_1408a2060(it->first, 0xed530c5f, &strEvent);
        }
    }
}

