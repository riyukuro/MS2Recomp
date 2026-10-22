// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Quest table row (CQuestData) and the quest table (QuestDataTable).
// MS2-UNIT: commonfiles\questdata.cpp
// MS2-RANGE: 0x140744670-0x140761a40 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x1400bc1a0-0x1400bc3d0 .text$di
// MS2-PIN: ??_7QuestDataTable@@6B?$TSingleton@VQuestDataTable@@@@@ 0x142d87198
// MS2-PIN: ??_7QuestDataTable@@6B?$CValidData@VQuestDataTable@@@@@ 0x142d871a8
// MS2-PIN: ??$sort@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@UUnk_QuestIdOrder@@@std@@YAXV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@0@0UUnk_QuestIdOrder@@@Z 0x1407575d0
// MS2-PIN: ??RUnk_QuestIdOrder@@QEBA_NHH@Z 0x1407599a0
// MS2-PIN: ??$IsSameArray@VNavigationTarget@CQuestData@@@@YA_NAEBV?$CAtlArray@V?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@@ATL@@@ATL@@0@Z 0x140752830
// MS2-PIN: ??$IsSamePtrMap@HVNavigationData@CQuestData@@@@YA_NAEBV?$CAtlMap@HV?$Unk_SocketPtr@VNavigationData@CQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationData@CQuestData@@@@@3@@ATL@@0@Z 0x1407526f0
// MS2-PIN: ?IsSameCondArray@@YA_NAEBV?$CAtlArray@V?$MS2Ptr@VCConditionCommonData@@@@V?$CElementTraits@V?$MS2Ptr@VCConditionCommonData@@@@@ATL@@@ATL@@0@Z 0x140752900
// MS2-PIN: ?Reference@?$Unk_SocketPtr@VGroupPickData@CQuestData@@@@CAXPEAVCPtred@@@Z 0x14075f030
// MS2-PIN: ?Reference@?$Unk_SocketPtr@VNavigationData@CQuestData@@@@CAXPEAVCPtred@@@Z 0x14075f050
// MS2-PIN: ?Reference@?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@CAXPEAVCPtred@@@Z 0x14075f070
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VGroupPickData@CQuestData@@@@AEBAXPEAX@Z 0x14075f090
// MS2-PIN: ?ReleaseImpl@?$Unk_SocketPtr@VGroupPickData@CQuestData@@@@AEAAXPEAX@Z 0x140760780
// MS2-PIN: ?ReleaseImpl@?$Unk_SocketPtr@VNavigationData@CQuestData@@@@AEAAXPEAX@Z 0x1407607d0
// MS2-PIN: ?ReleaseImpl@?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@AEAAXPEAX@Z 0x140760820
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VNavigationData@CQuestData@@@@AEBAXPEAX@Z 0x14075f0c0
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@AEBAXPEAX@Z 0x14075f0f0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCQuestData@@@@AEBAXPEAX@Z 0x14075f120
// MS2-PIN: ?Create@?$Unk_SocketRef@VNavigationData@CQuestData@@@@SAPEAVNavigationData@CQuestData@@PEAX@Z 0x14075f180
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?IsNull@?$Unk_PayloadPtr@VUnk_EventEntry@@@@QEBA_NXZ 0x1407475e0 ; unique
// MS2-PIN: ?get@?$Unk_PayloadPtr@VCQuest@@@@QEBAPEAVCQuest@@XZ 0x140747690 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCQuestData@@@@QEBAPEAVCQuestData@@XZ 0x1407476a0 ; unique
// MS2-PIN: memmove_s 0x1407477f0 ; unique
// MS2-PIN: ??$?0AEAHAEAI$0A@@?$pair@HI@std@@QEAA@AEAHAEAI@Z 0x140751870 ; unique
// MS2-PIN: ??$?0HAEAV?$MS2Ptr@VCQuestData@@@@$0A@@?$pair@HV?$MS2Ptr@VCQuestData@@@@@std@@QEAA@$$QEAHAEAV?$MS2Ptr@VCQuestData@@@@@Z 0x140751a00 ; unique
// MS2-PIN: ??$?0HV?$MS2Ptr@VCQuestData@@@@$0A@@?$pair@$$CBIV?$MS2Ptr@VCQuestData@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VCQuestData@@@@@1@@Z 0x140751a50 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBI@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@QEAA@AEAV?$tuple@AEBI@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140751af0 ; unique
// MS2-PIN: ??$StringFormat@I_K@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBIAEB_K@Z 0x140751b40 ; unique
// MS2-PIN: ?New@?$Unk_SocketRef@VNavigationData@CQuestData@@@@SAPEAVNavigationData@CQuestData@@PEAX@Z 0x1407529d0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$vector@IV?$allocator@I@std@@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140752aa0 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@HI@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@$$QEAU?$pair@HI@1@@Z 0x140752b70 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$vector@IV?$allocator@I@std@@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@PEAX@1@@Z 0x140753c40 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@VQuestRewardItem@CQuestData@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAVQuestRewardItem@CQuestData@@0@Z 0x140755c00 ; prop
// MS2-PIN: ??$_Ptr_copy_cat@V?$MS2Ptr@VCQuestData@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VCQuestData@@@@0@Z 0x140755c30 ; prop
// MS2-PIN: ??$_Try_emplace@AEBI$$V@?$map@IV?$vector@IV?$allocator@I@std@@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x140755fa0 ; unique
// MS2-PIN: ??$_Uninitialized_copy@PEAVQuestRewardItem@CQuestData@@PEAV12@V?$allocator@VQuestRewardItem@CQuestData@@@std@@@std@@YAPEAVQuestRewardItem@CQuestData@@QEAV12@0PEAV12@AEAV?$allocator@VQuestRewardItem@CQuestData@@@0@@Z 0x140756150 ; unique
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$MS2Ptr@VCQuestData@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCQuestData@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCQuestData@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VCQuestData@@@@@0@@Z 0x140756220 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140756800 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@IV?$vector@IV?$allocator@I@std@@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140756ec0 ; unique
// MS2-PIN: ??$find_if@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCQuestData@@@@@std@@@std@@@std@@UUnk_QuestLevelFree@@@std@@YA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCQuestData@@@@@std@@@std@@@0@V10@V10@UUnk_QuestLevelFree@@@Z 0x140756f60 ; prop
// MS2-PIN: ??$find_if@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCQuestData@@@@@std@@@std@@@std@@UUnk_QuestIdIs@@@std@@YA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCQuestData@@@@@std@@@std@@@0@V10@V10@UUnk_QuestIdIs@@@Z 0x140757020 ; prop
// MS2-PIN: ??$find_if@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCQuestData@@@@@std@@@std@@@std@@UUnk_QuestPrevIs@@@std@@YA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCQuestData@@@@@std@@@std@@@0@V10@V10@UUnk_QuestPrevIs@@@Z 0x140757260 ; prop
// MS2-PIN: ??$make_pair@AEAHAEAI@std@@YA?AU?$pair@HI@0@AEAHAEAI@Z 0x140757500 ; unique
// MS2-PIN: ??$make_pair@HAEAV?$MS2Ptr@VCQuestData@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VCQuestData@@@@@0@$$QEAHAEAV?$MS2Ptr@VCQuestData@@@@@Z 0x140757550 ; unique
// MS2-PIN: ??0?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@QEAA@AEBV0@@Z 0x140757cd0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCQuestData@@@@QEAA@$$T@Z 0x140757db0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCQuestData@@@@QEAA@PEAVCQuestData@@@Z 0x140757e30 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCQuestData@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCQuestData@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCQuestData@@@@@std@@@std@@@1@@Z 0x140758000 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$Unk_SocketPtr@VGroupPickData@CQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VGroupPickData@CQuestData@@@@@3@@ATL@@IEAA@H@Z 0x140758450 ; unique
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCQuestData@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140759150 ; prop
// MS2-PIN: ??A?$map@IV?$vector@IV?$allocator@I@std@@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@2@@std@@QEAAAEAV?$vector@IV?$allocator@I@std@@@1@AEBI@Z 0x140759310 ; unique
// MS2-PIN: ??A?$vector@VQuestRewardItem@CQuestData@@V?$allocator@VQuestRewardItem@CQuestData@@@std@@@std@@QEAAAEAVQuestRewardItem@CQuestData@@_K@Z 0x140759350 ; unique
// MS2-PIN: ??A?$vector@V?$MS2Ptr@VCQuestData@@@@V?$allocator@V?$MS2Ptr@VCQuestData@@@@@std@@@std@@QEAAAEAV?$MS2Ptr@VCQuestData@@@@_K@Z 0x140759380 ; unique
// MS2-PIN: ?get@?$Unk_SocketPtr@VNavigationData@CQuestData@@@@QEBAPEAVNavigationData@CQuestData@@XZ 0x140759410 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCConditionCommonData@@@@QEBAPEAVCConditionCommonData@@XZ 0x140759430 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@1@XZ 0x140759440 ; prop
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@1@XZ 0x140759460 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCQuestData@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140759650 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140759670 ; multicopy of 0x14050bdd0 (FUN_140750d90 range-for ++)
// MS2-PIN: ??RUnk_QuestLevelFree@@QEBA_NV?$MS2Ptr@VCQuestData@@@@@Z 0x140759830 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@@ATL@@@ATL@@QEAA_KAEBV?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@@Z 0x14075a090 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCConditionCommonData@@@@V?$CElementTraits@V?$MS2Ptr@VCConditionCommonData@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCConditionCommonData@@@@@Z 0x14075a140 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCQuestData@@@@@Z 0x14075a1f0 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@HV?$Unk_SocketPtr@VNavigationData@CQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationData@CQuestData@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x14075a7a0 ; unique
// MS2-PIN: ?GetCount@?$CAtlMap@HV?$Unk_SocketPtr@VNavigationData@CQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationData@CQuestData@@@@@3@@ATL@@QEBA_KXZ 0x14075ae90 ; unique
// MS2-PIN: ?GetKeyAt@?$CAtlMap@HV?$Unk_SocketPtr@VNavigationData@CQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationData@CQuestData@@@@@3@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x14075aef0 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@HV?$Unk_SocketPtr@VNavigationData@CQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationData@CQuestData@@@@@3@@ATL@@QEBAPEBVCPair@12@AEAPEAU__POSITION@@@Z 0x14075afd0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_SocketPtr@VGroupPickData@CQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VGroupPickData@CQuestData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14075b070 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14075b250 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$Unk_SocketPtr@VNavigationData@CQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationData@CQuestData@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x14075b440 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$Unk_SocketPtr@VNavigationData@CQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationData@CQuestData@@@@@3@@ATL@@QEBAAEBV?$Unk_SocketPtr@VNavigationData@CQuestData@@@@PEAU__POSITION@@@Z 0x14075b520 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAAEAV?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@PEAU__POSITION@@@Z 0x14075b590 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@V?$CElementTraits@V?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x14075b7a0 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCConditionCommonData@@@@V?$CElementTraits@V?$MS2Ptr@VCConditionCommonData@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x14075b940 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x14075bae0 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@@ATL@@SAXPEAV?$Unk_SocketPtr@VNavigationTarget@CQuestData@@@@0_K@Z 0x14075d910 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCConditionCommonData@@@@@ATL@@SAXPEAV?$MS2Ptr@VCConditionCommonData@@@@0_K@Z 0x14075d950 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCQuestData@@@@@ATL@@SAXPEAV?$MS2Ptr@VCQuestData@@@@0_K@Z 0x14075d990 ; prop
// MS2-PIN: ?RemoveAt@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAAX_K0@Z 0x14075de10 ; unique
// MS2-PIN: ?SetInit@QuestDataTable@@SAX_N@Z 0x14075ebe0 ; unique
// MS2-PIN: ?_Unchecked_begin@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VCQuestData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VCQuestData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCQuestData@@@@@std@@@std@@@std@@@2@XZ 0x140760d80 ; prop
// MS2-PIN: ?_Unchecked_begin@?$_Tree@V?$_Tmap_traits@IV?$vector@IV?$allocator@I@std@@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@2@XZ 0x140760dd0 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@AEBH@Z 0x140761620 ; unique
// MS2-PIN: ?_Unchecked_end@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VCQuestData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VCQuestData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCQuestData@@@@@std@@@std@@@std@@@2@XZ 0x140760e20 ; prop
// MS2-PIN: ?_Unchecked_end@?$_Tree@V?$_Tmap_traits@IV?$vector@IV?$allocator@I@std@@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@2@XZ 0x140760e60 ; prop
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@SAPEAU?$pair@$$CBIV?$vector@IV?$allocator@I@std@@@std@@@2@AEAU32@@Z 0x140761970 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\questdata.cpp"
#include <algorithm>
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/placeholder/cquestmanagercommon.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/placeholder/questdata.h"
// The exe's Reference takes the typed pointer (the CPtred base sits at +0), so these pass it straight through.
#define MS2_QUEST_SOCKETPTR_IMPL(T) \
    template<> void Unk_SocketPtr<T>::AddRefImpl(void*) const { Reference(p); } \
    template<> void Unk_SocketPtr<T>::ReleaseImpl(void*) { if (FUN_140159bc0(p) == 0) { Reference(p); FUN_140159ba0(p); } }
MS2_QUEST_SOCKETPTR_IMPL(CQuestData::GroupPickData)
MS2_QUEST_SOCKETPTR_IMPL(CQuestData::NavigationData)
MS2_QUEST_SOCKETPTR_IMPL(CQuestData::NavigationTarget)
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "hook/ms2hook.h"

// Header statics (the same list as header_statics_a.h, twice: the sort names of two enums).
#ifndef MS2_HOOK_DLL
static CStringA s_sortNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400bc1a0
static CStringA s_sortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400bc260
static CString s_strSkill = "skill";                                                                      // @0x1400bc320
static CString s_strStun = "stun";                                                                        // @0x1400bc350
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);                                         // @0x1400bc380
#endif

__int64 FUN_140869440();                                    // server time
__int64 FUN_14086b190(int nWeekday, __int64 tFrom);         // NextWeekdayStart
int FUN_140869470(int nDays);                               // DaysToSeconds
__int64 FUN_14086b590(int nYear, int nMonth, int nDay);
const __int64& FUN_1402e49a0(const __int64& a, const __int64& b);   // the smaller of the two
CFieldMetaTable* FUN_140700390();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
void* FUN_140166440();
int ConditionHasTarget(int nType);                          // 0x14029f330
CGuildXmlData* FUN_1404f4530();

// The game random generator (0x40 bytes; defined in randomeffectparam.h of the client unit). Seeded ctor 0x140768210.
class Unk_Random
{
public:
    explicit Unk_Random(int nSeed);                 // 0x140768210
    ~Unk_Random();                                  // 0x1401cdc30
    unsigned int FUN_1407684c0();                   // next
private:
    void* m_unk[8];
};

// A scheduled game event (the <eventTag> lookup), handed out as an intrusive pointer.
class Unk_EventEntry;
bool FUN_140866880(Unk_EventEntry* pEntry, __int64* pTime);          // the time falls into the event
struct Unk_QdEventStart { CMsTime FUN_140866720(); }; // the event's start
struct Unk_QdEventEnd { CMsTime FUN_1408666e0(); }; // the event's end
bool FUN_140866820(Unk_EventEntry* pEntry, const CMsTime& time);
bool FUN_140866760(Unk_EventEntry* pEntry);
class Unk_GEManagerA { public: Unk_PayloadPtr<Unk_EventEntry> FUN_140479410(CStringW* pTag); bool FUN_1404793a0(const CStringW* pTag); };
Unk_GEManagerA* FUN_1401c0d90();

// One <questCondition> pair of the quest manager query (0x1407470f0): the quests whose state is checked.
struct Unk_E16 { int m_questA, m_questB, m_stateA, m_stateB; };
struct Unk_Arr16 { void* m_p; unsigned __int64 m_n; };
Unk_E16* FUN_14027f040(Unk_Arr16* pArr, unsigned __int64 n);
unsigned __int64 FUN_1402815b0(Unk_Arr16* pArr);
class Unk_QuestCondition
{
public:
    int FUN_140266970();
    char m_pad[0x18];
    unsigned m_result;
    Unk_Arr16 m_list;
};
int FUN_140764480(Unk_PayloadPtr<CQuest> pQuest, int nState);

bool FUN_14028f650(Unk_140165cf0* pElem);                    // the element is valid
int FUN_14015f500(Unk_140165cf0* pElem, const char* pszName, int* pOut);
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
bool FUN_14074b090(CQuestData* pData);
int FUN_14074b330(CQuestData* pData);
int FUN_14074b030(CQuestData* pData);
int FUN_14074b050(CQuestData* pData);
int FUN_14074b070(CQuestData* pData);
void* FUN_140302b10();                                      // the game constants singleton
float FUN_1404c17a0(void* pThis, int nLevel, int nKind);    // exp rate
float FUN_1404c1730(void* pThis, int nLevel, int nKind);    // meso rate
int FUN_140408410(ATL::CAtlArray<unsigned>* pArr, const unsigned* pValue);
int FUN_1402bacf0(ATL::CAtlArray<int>& arr, const int& value);
int FUN_1407474d0(const ATL::CAtlArray<int>* pArr, const int* pValue);
int FUN_140747460(const ATL::CAtlArray<int>* pArr, const int* pValue);

// @0x140744670
int CQuestCommon::FUN_140744670(int field)
{
    if (!FUN_140744cd0(field))
        return 0;
    MS2Ptr<CQuestData> data = GetData();
    if (!data)
        return 0;
    if (!data->m_34)
        return 0;
    if (!IsActive())
        return 0;
    int nField = FUN_14074b330(data.operator->());
    if (nField == 0)
        return 0;
    if (nField == field)
        return 0;
    return 1;
}

// @0x1407447c0
int CQuestCommon::FUN_1407447c0()
{
    MS2Ptr<CQuestData> data = GetData();
    if (!data)
        return false;
    if (!FUN_14074b090(data.operator->()))
        return false;
    __int64 tEnd = FUN_1407448a0();
    return FUN_140869440() >= tEnd;
}

// MS2-FUNCTIONAL: extra result temporary in the exe (early-return slots).
// @0x1407448a0
__int64 CQuestCommon::FUN_1407448a0()
{
    MS2Ptr<CQuestData> data = GetData();
    if (!data)
        return 0;
    __int64 tPeriod = 0;
    __int64 tEvent = 0;
    if (data->m_resetType != 0)
    {
        __int64 tStart = GetStartTime();
        if (tStart == 0)
            tStart = FUN_140869440();
        tPeriod = FUN_14086b190(data->m_resetType, tStart);
    }
    else if (data->m_durationMinutes != 0)
    {
        __int64 tStart = GetStartTime();
        if (tStart == 0)
            tStart = FUN_140869440();
        tPeriod = tStart + data->m_durationMinutes * 60;
    }
    if (data->m_schedule.GetLength() != 0)
    {
        Unk_PayloadPtr<Unk_EventEntry> event = FUN_1401c0d90()->FUN_140479410(&data->m_schedule);
        if (event == 0)
            return 0;
        __int64 tStart = GetStartTime();
        if (tStart != 0)
        {
            if (!FUN_140866880(event.operator->(), &tStart))
                return 0;
        }
        tEvent = reinterpret_cast<Unk_QdEventStart*>(event.operator->())->FUN_140866720().Get();
    }
    if (tPeriod != 0 && tEvent != 0)
        return FUN_1402e49a0(tPeriod, tEvent);
    if (tPeriod == 0)
        return tEvent;
    return tPeriod;
}
MS2_REPLACE_METHOD(0x1407448A0, CQuestCommon, FUN_1407448a0, 732, 0x32941A8A);

// @0x140744b90
int CQuestCommon::FUN_140744b90(int field)
{
    MS2Ptr<CQuestData> data = GetData();
    if (data.operator==(0))
        return 0;
    if (data->m_fields.IsEmpty())
        return 0;
    int nWant = data->m_fields[0];
    if (nWant != field)
    {
        unsigned nHave = 0;
        if (FUN_140700390()->FUN_1406fc110(field, &nHave) == 0)
            return 0;
        if (nWant != (int)nHave)
            return 0;
    }
    return 1;
}

// @0x140744cd0
int CQuestCommon::FUN_140744cd0(int field)
{
    MS2Ptr<CFieldData> data = CFieldData::FUN_140374140(field);
    if (!data)
        return 0;
    return 1;
}

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x140744d40
int CQuestManagerCommon::vfunc_o10_21(int questId, int npcId, int flag)
{
    if (FUN_140745820(questId, flag) == 0)
        return 0;
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (data.operator==(0))
        return 0;
    if (npcId != 0 && data->m_2e8 != npcId)
        return 0;
    CMsTime now(FUN_140869440());
    if (data->m_require.m_groupId != 0)
    {
        int nSeed = FUN_140747000(questId);
        ATL::CAtlArray<unsigned> picked;
        QuestDataTable::GetInstance()->FUN_14074e6c0(data->m_require.m_groupId, m_selector, nSeed, picked);
        unsigned nId = FUN_14074b030(data.operator->());
        if (FUN_140408410(&picked, &nId) == -1)
            return 0;
    }
    if (data->m_require.m_dayOfWeek.GetCount() != 0)
    {
        int nDay = now.GetDayOfWeek();
        if (FUN_1402bacf0(data->m_require.m_dayOfWeek, nDay) == -1)
            return 0;
    }
    __int64 tStart = 0;
    int nState = 4;
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.get() != 0)
    {
        tStart = quest->GetStartTime();
        nState = quest->FUN_1407476d0();
    }
    if (data->m_schedule.GetLength() != 0)
    {
        Unk_PayloadPtr<Unk_EventEntry> event = FUN_1401c0d90()->FUN_140479410(&data->m_schedule);
        if (event.IsNull())
            return 0;
        if (!FUN_140866820(event.operator->(), now))
            return 0;
        if (FUN_140866760(event.operator->()))
        {
            __int64 tNow = vfunc_o10_8();
            if (tNow < reinterpret_cast<Unk_QdEventEnd*>(event.operator->())->FUN_1408666e0().Get())
                return 0;
        }
        if (tStart != 0)
        {
            if (!FUN_140866880(event.operator->(), &tStart))
                return 1;
        }
    }
    if (nState == 1)
        return 0;
    int nRepeat = FUN_14074b070(data.operator->());
    if (nRepeat == 0)
    {
        if (nState == 2)
            return 0;
    }
    else if (nRepeat == 2)
    {
        if (nState == 2)
        {
            CMsTime last(tStart);
            if (last.GetYear() == now.GetYear() && last.GetMonth() == now.GetMonth() && last.GetDay() == now.GetDay())
                return 0;
        }
    }
    else if (nRepeat == 3 && nState == 2)
    {
        CMsTime reset(FUN_14086b190(data->m_resetType, tStart));
        if (now.Get() < reset.Get())
            return 0;
    }
    if (FUN_14074b050(data.operator->()) == 6)
    {
        if (FUN_14074b070(data.operator->()) == 2)
        {
            __int64 tUntil = vfunc_o10_12() + FUN_140869470(1);
            if (now.Get() < tUntil)
                return 0;
        }
        else if (FUN_14074b070(data.operator->()) == 3)
        {
            __int64 tUntil = vfunc_o10_12() + FUN_140869470(7);
            if (now.Get() < tUntil)
                return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140744D40, CQuestManagerCommon, vfunc_o10_21, 2115, 0x2D2D1A6E);

// @0x140745590
int CQuestManagerCommon::FUN_140745590(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 0;
    return quest->IsRewarded();
}

// @0x140745630
int CQuestManagerCommon::FUN_140745630(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 0;
    return quest->IsActive();
}

// @0x1407456d0
int CQuestManagerCommon::FUN_1407456d0(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 0;
    return quest->IsComplete();
}

// @0x140745770
bool CQuestManagerCommon::FUN_140745770(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return false;
    return (bool)quest->FUN_1407447c0();
}

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x140745820
int CQuestManagerCommon::FUN_140745820(int questId, int flag)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (data.get() == 0)
        return 0;
    CQuestData::Require& req = data->m_require;
    if (data->m_30)
        return 0;
    if (vfunc_o10_4() < req.m_level)
        return 0;
    if (req.m_maxLevel != 0 && req.m_maxLevel < vfunc_o10_4())
        return 0;
    if (req.m_gearScore != 0 && vfunc_o10_5() < (int)req.m_gearScore)
        return 0;
    if (req.m_job.GetCount() != 0)
    {
        int nJob = vfunc_o10_6();
        if (FUN_1407474d0(&req.m_job, &nJob) == -1)
            return 0;
    }
    if (req.m_subJob.GetCount() != 0)
    {
        int nSubJob = vfunc_o10_7();
        if (FUN_140747460(&req.m_subJob, &nSubJob) == -1)
            return 0;
    }
    for (size_t i = 0; i < req.m_quest.GetCount(); ++i)
    {
        if (req.m_quest[i] != 0 && FUN_140745590(req.m_quest[i]) == 0)
            return 0;
    }
    if (req.m_selectableQuest.GetCount() != 0)
    {
        int bAny = 0;
        for (size_t i = 0; i < req.m_selectableQuest.GetCount(); ++i)
        {
            if (req.m_selectableQuest[i] != 0 && FUN_140745590(req.m_selectableQuest[i]) != 0)
                bAny = 1;
        }
        if (bAny == 0)
            return 0;
    }
    for (size_t i = 0; i < req.m_progressQuest.GetCount(); ++i)
    {
        if (req.m_progressQuest[i] != 0 && FUN_140745630(req.m_progressQuest[i]) == 0)
            return 0;
    }
    for (size_t i = 0; i < req.m_unrequire.GetCount(); ++i)
    {
        if (req.m_unrequire[i] != 0)
        {
            if (FUN_140745590(req.m_unrequire[i]) != 0)
                return 0;
            if (FUN_140745630(req.m_unrequire[i]) != 0)
                return 0;
        }
    }
    if (flag == 0)
    {
        for (size_t i = 0; i < req.m_unrequireGroup.GetCount(); ++i)
        {
            int nSeed = FUN_140747000(questId);
            ATL::CAtlArray<unsigned> picked;
            QuestDataTable::GetInstance()->FUN_14074e6c0(req.m_unrequireGroup[i], m_selector, nSeed, picked);
            for (size_t j = 0; j < picked.GetCount(); ++j)
            {
                if (FUN_140745630(picked[j]) != 0)
                    return 0;
                if (FUN_140745590(picked[j]) != 0)
                {
                    if (vfunc_o10_21(picked[j], 0, 1) == 0)
                        return 0;
                }
            }
        }
    }
    if (req.m_achievement != 0)
    {
        if (req.m_achievementGrade == 0)
        {
            if (vfunc_o10_1(req.m_achievement) == 0)
                return 0;
        }
        else if (vfunc_o10_0(req.m_achievement, req.m_achievementGrade) == 0)
            return 0;
    }
    if (req.m_unreqAchievement != 0 && req.m_unreqAchievementGrade != 0)
    {
        if (vfunc_o10_0(req.m_unreqAchievement, req.m_unreqAchievementGrade) != 0)
            return 0;
    }
    if (req.m_guildLevel != -1)
    {
        if (req.m_guildLevel == 0)
        {
            if (vfunc_o10_9() != 0)
                return 0;
        }
        else
        {
            if (vfunc_o10_9() == 0)
                return 0;
            int nGuildExp = vfunc_o10_10();
            if ((int)FUN_1404f4530()->FUN_1404d7130(nGuildExp) < req.m_guildLevel)
                return 0;
        }
    }
    if (req.m_guildNpcLevel != 0)
    {
        if (vfunc_o10_9() == 0)
            return 0;
        if ((unsigned short)vfunc_o10_11() != req.m_guildNpcLevel)
            return 0;
    }
    if (req.m_alliance != 0 && req.m_fameGrade != 0)
    {
        if (vfunc_o10_13(req.m_alliance) < req.m_fameGrade)
            return 0;
    }
    if (req.m_masteryType != 0 && req.m_masteryGrade != 0)
    {
        if (vfunc_o10_14(req.m_masteryType) < req.m_masteryGrade)
            return 0;
    }
    if (req.m_dungeon != 0 && vfunc_o10_15(req.m_dungeon) < 1)
        return 0;
    if (req.m_unrequireDungeon != 0 && vfunc_o10_15(req.m_unrequireDungeon) != 0)
        return 0;
    if (req.m_enterDungeon != 0 && vfunc_o10_16(req.m_enterDungeon) > 9)
        return 0;
    if (req.m_dungeonBeginner.GetCount() != 0)
    {
        int bAny = 0;
        for (size_t i = 0; i < req.m_dungeonBeginner.GetCount(); ++i)
        {
            if (vfunc_o10_17(req.m_dungeonBeginner[i]) == 0)
            {
                bAny = 1;
                break;
            }
        }
        if (bAny == 0)
            return 0;
    }
    if (req.m_mentor == 0 || vfunc_o10_18() == 5)
    {
        if (req.m_mentee == 0 || vfunc_o10_18() == 2)
        {
            if (req.m_vip == 0 || vfunc_o10_19() != 0)
            {
                if (req.m_equipment.GetCount() != 0 && vfunc_o10_20(req.m_equipment) == 0)
                    return 0;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140745820, CQuestManagerCommon, FUN_140745820, 4129, 0xBBD4D435);

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x140746850
int CQuestManagerCommon::FUN_140746850(int questId, int npcId, int bStart)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 0;
    if (quest->FUN_1407447c0() != 0)
        return 0;
    if (quest->FUN_1407476d0() != 1)
        return 0;
    if (bStart == 0)
    {
        if (quest->IsComplete() != 0)
            return 0;
        if (quest->GetData()->m_2ec != npcId)
            return 0;
    }
    else if (quest->GetData()->m_2e8 != npcId)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140746850, CQuestManagerCommon, FUN_140746850, 827, 0xB2C4964A);

// The conditional data temporary lives through the NPC comparison.
// @0x140746ba0
int CQuestManagerCommon::FUN_140746ba0(int questId, int npcId, bool bSkip)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 6;
    if (bSkip == 0 && quest->FUN_1407447c0() != 0)
        return 4;
    if (quest->GetData().operator==(0))
        return 6;
    if (bSkip == 0 && quest->FUN_1407476d0() != 1)
        return 6;
    if (bSkip == 0 && npcId != 0 && quest->GetData()->m_2ec != npcId)
        return 6;
    if (bSkip == 0 && FUN_1407456d0(questId) == 0)
        return 6;
    return 0;
}
MS2_REPLACE_METHOD(0x140746BA0, CQuestManagerCommon, FUN_140746ba0, 694, 0x244F7842);

// @0x140746e60
int CQuestManagerCommon::FUN_140746e60(int questId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (data.IsNull())
        return 0;
    if (!data->m_2d)
        return 0;
    switch (FUN_14074b050(data.operator->()))
    {
    case 8:
    case 10:
        return 0;
    case 3:
        return FUN_140747400(questId, data->m_338.m_value);
    case 5:
        return FUN_140747440(questId, data->m_350.m_value);
    default:
        return FUN_140747350(questId);
    }
}
MS2_REPLACE_METHOD(0x140746E60, CQuestManagerCommon, FUN_140746e60, 358, 0xB747E45D);

// @0x140746fe0
void FUN_140746fe0(CQuestManagerCommon* pMgr, int nSelector)
{
    pMgr->m_selector = nSelector;
}

// @0x140747000
int CQuestManagerCommon::FUN_140747000(int questId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (!data)
        return 0;
    int nSeed = 0;
    switch (QuestDataTable::GetInstance()->FUN_14074e390(data->m_require.m_groupId))
    {
    case 0:
        nSeed = 0;
        break;
    case 1:
        nSeed = (int)((unsigned __int64)vfunc_o10_22() >> 32);
        break;
    case 2:
        nSeed = 0;
        break;
    }
    return nSeed;
}

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x1407470f0
unsigned CQuestManagerCommon::vfunc_o10_23(const Unk_QuestCondition& condition)
{
    Unk_QuestCondition& cond = const_cast<Unk_QuestCondition&>(condition);
    if (cond.FUN_140266970() == 0)
        return 1;
    for (unsigned __int64 i = 0; i < FUN_1402815b0(&cond.m_list); ++i)
    {
        Unk_PayloadPtr<CQuest> questA = vfunc_o10_3(FUN_14027f040(&cond.m_list, i)->m_questA);
        Unk_PayloadPtr<CQuest> questB = vfunc_o10_3(FUN_14027f040(&cond.m_list, i)->m_questB);
        int nA = FUN_140764480(questA, FUN_14027f040(&cond.m_list, i)->m_stateA);
        int nB = FUN_140764480(questB, FUN_14027f040(&cond.m_list, i)->m_stateB);
        if (nA == 2)
            continue;
        if (nB != 1)
            return cond.m_result;
    }
    return cond.m_result == 0;
}
MS2_REPLACE_METHOD(0x1407470F0, CQuestManagerCommon, vfunc_o10_23, 584, 0xAEEEA57A);

// @0x140747350
bool CQuestManagerCommon::FUN_140747350(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest == 0)
        return true;
    if (quest->FUN_1407476d0() == 0)
        return true;
    return false;
}

// @0x140747400
bool CQuestManagerCommon::FUN_140747400(int questId, int nKind)
{
    if (nKind != 1)
        return false;
    return FUN_140747350(questId);
}

// @0x140747440
bool CQuestManagerCommon::FUN_140747440(int, int)
{
    return true;
}

// @0x140747460
int FUN_140747460(const ATL::CAtlArray<int>* pArr, const int* pValue)
{
    for (int i = 0; i < (int)pArr->GetCount(); ++i)
    {
        if ((*pArr)[i] == *pValue)
            return i;
    }
    return -1;
}

// @0x1407474d0
int FUN_1407474d0(const ATL::CAtlArray<int>* pArr, const int* pValue)
{
    for (int i = 0; i < (int)pArr->GetCount(); ++i)
    {
        if ((*pArr)[i] == *pValue)
            return i;
    }
    return -1;
}

// @0x1407476d0
int CQuest::FUN_1407476d0() const
{
    return m_state;
}

// Container comparison (true = same).
template <class T> bool IsSameArray(const ATL::CAtlArray<T>& a, const ATL::CAtlArray<T>& b)
{
    if (a.GetCount() == b.GetCount())
    {
        for (unsigned i = 0; i < a.GetCount(); i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    return false;
}

// Class-body members of the row types (COMDATs, 0x140758550-0x140758db0).
inline CQuestData::QuestRewardItem::QuestRewardItem()
    : m_itemId(0), m_count(1), m_job(0)
{
}
inline CQuestData::QuestRewardItem::~QuestRewardItem()
{
}
inline CQuestData::CompleteReward::~CompleteReward()
{
}
inline CQuestData::GroupPickData::~GroupPickData()
{
}
inline CQuestData::Require::~Require()
{
}

// Array of pointers compared by pointee (true = same).
template <class T> bool IsSameArray(const ATL::CAtlArray<Unk_SocketPtr<T> >& a, const ATL::CAtlArray<Unk_SocketPtr<T> >& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (unsigned i = 0; i < a.GetCount(); i++)
    {
        if (*a.GetAt(i).get() != *b.GetAt(i).get())
            return false;
    }
    return true;
}

// @0x140747910
CQuestData::Require::Require()
    : m_level(0), m_maxLevel(0), m_achievement(0), m_achievementGrade(0), m_unreqAchievement(0),
      m_unreqAchievementGrade(0), m_groupId(0), m_gearScore(0), m_guildLevel(-1), m_guildNpcLevel(0),
      m_dungeon(0), m_unrequireDungeon(0), m_enterDungeon(0), m_dungeonBeginner(),
      m_mentor(0), m_mentee(0), m_vip(0), m_alliance(Unk_FameAlliance_None), m_fameGrade(0), m_masteryType(0), m_masteryGrade(0)
{
}

// @0x140747b10
bool CQuestData::Require::operator!=(const Require& o) const
{
    if ((unsigned short)m_level != (unsigned short)o.m_level) return true;
    if ((unsigned short)m_maxLevel != (unsigned short)o.m_maxLevel) return true;
    if (m_achievement != o.m_achievement) return true;
    if (m_achievementGrade != o.m_achievementGrade) return true;
    if (m_unreqAchievement != o.m_unreqAchievement) return true;
    if (m_unreqAchievementGrade != o.m_unreqAchievementGrade) return true;
    if (m_groupId != o.m_groupId) return true;
    if (m_gearScore != o.m_gearScore) return true;
    if (m_guildLevel != o.m_guildLevel) return true;
    if ((unsigned short)m_guildNpcLevel != (unsigned short)o.m_guildNpcLevel) return true;
    if (m_dungeon != o.m_dungeon) return true;
    if (m_unrequireDungeon != o.m_unrequireDungeon) return true;
    if (m_enterDungeon != o.m_enterDungeon) return true;
    if (!IsSameArray(m_dungeonBeginner, o.m_dungeonBeginner)) return true;
    if (m_mentor != o.m_mentor) return true;
    if (m_mentee != o.m_mentee) return true;
    if (m_vip != o.m_vip) return true;
    if (m_alliance != o.m_alliance) return true;
    if (m_fameGrade != o.m_fameGrade) return true;
    if (m_masteryType != o.m_masteryType) return true;
    if (m_masteryGrade != o.m_masteryGrade) return true;
    if (!IsSameArray(m_job, o.m_job)) return true;
    if (!IsSameArray(m_subJob, o.m_subJob)) return true;
    if (!IsSameArray(m_quest, o.m_quest)) return true;
    if (!IsSameArray(m_selectableQuest, o.m_selectableQuest)) return true;
    if (!IsSameArray(m_unrequire, o.m_unrequire)) return true;
    if (!IsSameArray(m_progressQuest, o.m_progressQuest)) return true;
    if (!IsSameArray(m_unrequireGroup, o.m_unrequireGroup)) return true;
    if (!IsSameArray(m_equipment, o.m_equipment)) return true;
    if (!IsSameArray(m_dayOfWeek, o.m_dayOfWeek)) return true;
    if (!IsSameArray(m_followingQuests, o.m_followingQuests)) return true;
    if (!IsSameArray(m_requiredBy, o.m_requiredBy)) return true;
    if (!IsSameArray(m_selectableBy, o.m_selectableBy)) return true;
    return false;
}

// @0x140747f60
bool CQuestData::QuestRewardItem::operator!=(const QuestRewardItem& o) const
{
    if (m_itemId != o.m_itemId) return true;
    if (m_count != o.m_count) return true;
    if (m_job != o.m_job) return true;
    return false;
}

// @0x140747fc0
bool CQuestData::QuestRewardItem::LoadXml(Unk_140165cf0* pElem)
{
    if (!FUN_14028f650(pElem))
        return false;
    FUN_140873220(pElem, "code", (unsigned&)m_itemId);
    FUN_14015f500(pElem, "rank", &m_count);
    FUN_1408731e0(pElem, "count", m_job);
    return true;
}

// The job restriction of an item (the "recommended jobs" set of its ItemLimit, 0x140545da0).
class Unk_ItemLimitJobs { public: bool FUN_140545da0(int nJob); };
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// @0x140748050
int FUN_140748050(CQuestData::QuestRewardItem* pItem, int nJob)
{
    MS2Ptr<CItemData> item = FUN_14053f870(pItem->m_itemId);
    if (!item)
        return 0;
    if (!reinterpret_cast<Unk_ItemLimitJobs*>(&item->limit)->FUN_140545da0(nJob))
        return 0;
    return 1;
}

// @0x140748100
CQuestData::CompleteReward::CompleteReward()
    : m_money(0), m_karma(0), m_lu(0), m_exp(0), m_guildFund(0), m_guildExp(0), m_guildCoin(0), m_menteeCoin(0),
      m_missionPoint(0), m_useMainFamePoint(0), m_fameLog(0), m_weddingExp(0), m_38(1.0f), m_relativeExp(-1),
      m_40(1.0f), m_relativeMeso(0), m_rewardExpExtra(0), m_choiceRewards()
{
}

// @0x140748210
bool CQuestData::CompleteReward::operator!=(const CompleteReward& o) const
{
    if (m_money != o.m_money) return true;
    if (m_karma != o.m_karma) return true;
    if (m_lu != o.m_lu) return true;
    if (m_exp != o.m_exp) return true;
    if (m_guildFund != o.m_guildFund) return true;
    if (m_guildExp != o.m_guildExp) return true;
    if (m_guildCoin != o.m_guildCoin) return true;
    if (m_menteeCoin != o.m_menteeCoin) return true;
    if (m_missionPoint != o.m_missionPoint) return true;
    if (m_useMainFamePoint != o.m_useMainFamePoint) return true;
    if (m_fameLog != o.m_fameLog) return true;
    if (m_weddingExp != o.m_weddingExp) return true;
    if (m_38 != o.m_38) return true;
    if (m_relativeExp != o.m_relativeExp) return true;
    if (m_40 != o.m_40) return true;
    if (m_relativeMeso != o.m_relativeMeso) return true;
    if (m_rewardExpExtra != o.m_rewardExpExtra) return true;
    if (m_choiceRewards.GetCount() != o.m_choiceRewards.GetCount()) return true;
    for (unsigned i = 0; i < m_choiceRewards.GetCount(); i++)
    {
        if (m_choiceRewards[i] != o.m_choiceRewards.GetAt(i))
            return true;
    }
    return false;
}

// Out-of-line members of the level range embedded in Grade (0x140757bd0, 0x140759050, 0x14075bc80).
Unk_DcLevelRange::Unk_DcLevelRange()
    : m_nLow(0), m_nHigh(0)
{
}
bool Unk_DcLevelRange::operator!=(const Unk_DcLevelRange& o) const
{
    if (m_nLow != o.m_nLow)
        return true;
    if (m_nHigh != o.m_nHigh)
        return true;
    return false;
}
void Unk_DcLevelRange::FUN_14075bc80(unsigned short nLow, unsigned short nHigh)
{
    m_nLow = nLow;
    m_nHigh = nHigh;
}

// @0x1407484a0
void FUN_1407484a0(CQuestData::CompleteReward* pReward, int nValue)
{
}

// @0x1407484d0
CQuestData::Grade::Grade()
    : m_value(0), m_4(6), m_8(), m_levelRange()
{
}

// @0x140748530
bool CQuestData::Grade::operator!=(const Grade& o) const
{
    if (m_value != o.m_value) return true;
    if (m_4 != o.m_4) return true;
    if (m_8 != o.m_8) return true;
    if (m_levelRange != o.m_levelRange) return true;
    return false;
}

// @0x1407485c0
CQuestData::Flag::Flag()
    : m_value(0)
{
}

// @0x1407485e0
bool CQuestData::Flag::operator!=(const Flag& o) const
{
    if (m_value != o.m_value)
        return true;
    return false;
}

// @0x140748610
CQuestData::Named::Named()
    : m_0(1), m_4(0), m_8()
{
}

// @0x140748660
bool CQuestData::Named::operator!=(const Named& o) const
{
    if (m_0 != o.m_0) return true;
    if (m_4 != o.m_4) return true;
    if (m_8 != o.m_8) return true;
    return false;
}

// @0x1407486d0
CQuestData::Quad::Quad()
    : m_0(0), m_4(0), m_8(0), m_c(0)
{
}

// @0x140748710
bool CQuestData::Quad::operator!=(const Quad& o) const
{
    if (m_0 != o.m_0) return true;
    if (m_4 != o.m_4) return true;
    if (m_8 != o.m_8) return true;
    if (m_c != o.m_c) return true;
    return false;
}

// @0x140748780
CQuestData::Tri300::Tri300()
    : m_0(0), m_4(0), m_8(0)
{
}

// @0x1407487c0
bool CQuestData::Tri300::operator!=(const Tri300& o) const
{
    if (m_0 != o.m_0) return true;
    if (m_4 != o.m_4) return true;
    if (m_8 != o.m_8) return true;
    return false;
}

// @0x140748820
CQuestData::Room::Room()
    : m_0(0), m_roomId(0), m_fieldId(0)
{
}

// @0x140748860
bool CQuestData::Room::operator!=(const Room& o) const
{
    if (m_0 != o.m_0) return true;
    if (m_roomId != o.m_roomId) return true;
    if (m_fieldId != o.m_fieldId) return true;
    return false;
}

// @0x1407488c0
CQuestData::Pair::Pair()
    : m_0(0), m_4(0)
{
}

// @0x1407488f0
bool CQuestData::Pair::operator!=(const Pair& o) const
{
    if (m_0 != o.m_0) return true;
    if (m_4 != o.m_4) return true;
    return false;
}

// @0x140748930
CQuestData::Triple::Triple()
    : m_0(0), m_4(0), m_8(0)
{
}

// @0x140748970
bool CQuestData::Triple::operator!=(const Triple& o) const
{
    if (m_0 != o.m_0) return true;
    if (m_4 != o.m_4) return true;
    if (m_8 != o.m_8) return true;
    return false;
}

// @0x1407489d0
CQuestData::Sound::Sound()
    : m_id(-1), m_accept(), m_reward()
{
}

// @0x140748a20
bool CQuestData::Sound::operator!=(const Sound& o) const
{
    if (m_id != o.m_id) return true;
    if (m_accept != o.m_accept) return true;
    if (m_reward != o.m_reward) return true;
    return false;
}

// @0x140748aa0
CQuestData::NavigationTarget::NavigationTarget()
    : m_kind(3), m_ids(), m_maps()
{
}

// @0x140748b00
bool CQuestData::NavigationTarget::operator!=(const NavigationTarget& o) const
{
    if (m_kind != o.m_kind) return true;
    if (!IsSameArray(m_ids, o.m_ids)) return true;
    if (!IsSameArray(m_maps, o.m_maps)) return true;
    return false;
}

// @0x140748b80
CQuestData::NavigationData::NavigationData()
    : m_kind(0), m_targets()
{
}

// @0x140748bd0
bool CQuestData::NavigationData::operator!=(const NavigationData& o) const
{
    if (m_kind != o.m_kind) return true;
    if (!IsSameArray(m_targets, o.m_targets)) return true;
    return false;
}

// @0x140748c30
CQuestData::GroupPickData::GroupPickData()
    : m_18(0), m_count(1), m_kind(0)
{
}

// @0x140748c90
bool CQuestData::GroupPickData::operator!=(const GroupPickData& o) const
{
    if (m_18 != o.m_18) return true;
    if (m_count != o.m_count) return true;
    if (m_kind != o.m_kind) return true;
    return false;
}

// @0x140748cf0
CQuestData::CQuestData()
    : m_id(0), m_type(0), m_20(0), m_level(0), m_28(0), m_2c(0), m_2d(0), m_2e(0), m_2f(0), m_30(0), m_31(0),
      m_flag(0), m_33(0), m_34(0), m_durationMinutes(0), m_resetType(0), m_schedule(), m_48(-1), m_4c(Unk_FameAlliance_None), m_50(5),
      m_54(), m_require(), m_complete(), m_rewards(), m_2d0(), m_2e8(0), m_2ec(0), m_2f0(), m_300(), m_30c(),
      m_318(), m_320(), m_32c(), m_338(), m_350(), m_358(), m_fields(), m_conditions(),
      m_navigation(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140748fa0
CQuestData::~CQuestData()
{
}

// Array of condition pointers (true = same): every pair compares equal through IsDifferent.
bool IsSameCondArray(const ATL::CAtlArray<MS2Ptr<CConditionCommonData> >& a, const ATL::CAtlArray<MS2Ptr<CConditionCommonData> >& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (unsigned i = 0; i < a.GetCount(); i++)
    {
        if (a.GetAt(i).get()->IsDifferent(b.GetAt(i).get()))
            return false;
    }
    return true;
}

// Map of pointers compared by pointee (true = same).
template <class K, class T> bool IsSamePtrMap(const ATL::CAtlMap<K, Unk_SocketPtr<T> >& a, const ATL::CAtlMap<K, Unk_SocketPtr<T> >& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    POSITION posA = a.GetStartPosition();
    POSITION posB = b.GetStartPosition();
    for (unsigned i = 0; i < a.GetCount(); i++, a.GetNext(posA), b.GetNext(posB))
    {
        const K& keyA = a.GetKeyAt(posA);
        if (keyA != b.GetKeyAt(posB))
            return false;
        const T& valueB = *b.GetValueAt(posB).get();
        if (*a.GetValueAt(posA).get() != valueB)
            return false;
    }
    return true;
}

// @0x140749090
bool CQuestData::operator!=(const CQuestData& o) const
{
    if (m_id != o.m_id) return true;
    if (m_type != o.m_type) return true;
    if (m_20 != o.m_20) return true;
    if (m_2c != o.m_2c) return true;
    if (m_level != o.m_level) return true;
    if (m_28 != o.m_28) return true;
    if (m_2d != o.m_2d) return true;
    if (m_2e != o.m_2e) return true;
    if (m_2f != o.m_2f) return true;
    if (m_durationMinutes != o.m_durationMinutes) return true;
    if (m_resetType != o.m_resetType) return true;
    if (m_schedule != o.m_schedule) return true;
    if (m_30 != o.m_30) return true;
    if (m_48 != o.m_48) return true;
    if (m_31 != o.m_31) return true;
    if (m_flag != o.m_flag) return true;
    if (m_4c != o.m_4c) return true;
    if (m_50 != o.m_50) return true;
    if (m_33 != o.m_33) return true;
    if (m_34 != o.m_34) return true;
    if (m_54 != o.m_54) return true;
    if (m_require != o.m_require) return true;
    if (m_complete != o.m_complete) return true;
    if (m_2d0 != o.m_2d0) return true;
    if (m_2e8 != o.m_2e8) return true;
    if (m_2ec != o.m_2ec) return true;
    if (m_2f0 != o.m_2f0) return true;
    if (m_300 != o.m_300) return true;
    if (m_30c != o.m_30c) return true;
    if (m_318 != o.m_318) return true;
    if (m_320 != o.m_320) return true;
    if (m_32c != o.m_32c) return true;
    if (m_338 != o.m_338) return true;
    if (m_350 != o.m_350) return true;
    if (m_358 != o.m_358) return true;
    if (!IsSameArray(m_fields, o.m_fields)) return true;
    if (!IsSameCondArray(m_conditions, o.m_conditions)) return true;
    if (!IsSamePtrMap(m_navigation, o.m_navigation)) return true;
    return false;
}

// The attribute readers used by the quest loader (the enum parsers are defined further down in this unit).
int FUN_14035ba10(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_14035bc20(Unk_140165cf0* pElem, const char* pszName, Unk_FameAlliance* pOut);
int FUN_14051fd20(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_140354050(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
int FUN_140873ad0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);
int FUN_140873b30(Unk_140165cf0* pElem, const char* pszName, CStringW& strOut);
int FUN_14028e160(CString& str);
int FUN_140718170(const CString& str);
int FUN_1407181d0(const CString& str);
int FUN_1407514d0(const CString& str);
int FUN_140751e50(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_140751ee0(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_140751f70(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_1407520f0(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_1407521b0(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_140752270(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_140752330(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_1407523f0(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_1407524b0(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_140752570(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_140752630(Unk_140165cf0* pElem, const char* pszName, int* pOut);
class Unk_FeatureFlags;
Unk_FeatureFlags* FUN_140166410();
unsigned char FUN_14036d570(Unk_FeatureFlags* pFlags, int nFeature);

// MS2-FUNCTIONAL: stack temporaries of the XML loader (default-string and condition-loop slots) differ.
// @0x1407495d0
int CQuestData::FUN_1407495d0(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", (unsigned&)m_id);
    Unk_140165cf0* pBasic = pElem->FUN_140165cf0("basic");
    if (pBasic)
    {
        FUN_1408731e0(pBasic, "chapterID", m_28);
        FUN_1408731e0(pBasic, "standardLevel", m_level);
        FUN_1408730a0(pBasic, "autoStart", (bool&)m_2d);
        FUN_1408730a0(pBasic, "disableGiveup", (bool&)m_2e);
        FUN_1408730a0(pBasic, "exceptChapterClear", (bool&)m_2f);
        FUN_14035ba10(pBasic, "repeatable", &m_20);
        FUN_140751ee0(pBasic, "questType", &m_type);
        FUN_1408730a0(pBasic, "account", (bool&)m_2c);
        FUN_140873b30(pBasic, "eventTag", m_schedule);
        FUN_1408730a0(pBasic, "locking", (bool&)m_30);
        FUN_1408731e0(pBasic, "tabIndex", m_48);
        FUN_1408730a0(pBasic, "forceRegistGuide", (bool&)m_31);
        FUN_1408730a0(pBasic, "useNavi", (bool&)m_flag);
        FUN_14035bc20(pBasic, "alliance", &m_4c);
        FUN_140752570(pBasic, "rank", &m_50);
        FUN_1408736d0(pBasic, "usePostbox", (bool&)m_33);
        FUN_1408736d0(pBasic, "useReEntryHiddenMap", (bool&)m_34);
        ATL::CAtlArray<CString> arrProperty;
        XmlTokenList(pBasic, "property", arrProperty);
        for (size_t i = 0; i < arrProperty.GetCount(); i++)
        {
            int nProperty = FUN_1407514d0(arrProperty[i]);
            if (nProperty < 4)
                m_54.set(nProperty, true);
        }
        CString strPeriod;
        FUN_140873ad0(pBasic, "usePeriod", strPeriod);
        int nResetType = FUN_14028e160(strPeriod);
        if (nResetType != 0)
            m_resetType = nResetType;
        else
            m_durationMinutes = FUN_140718170(strPeriod);
    }
    Unk_140165cf0* pNotify = pElem->FUN_140165cf0("notify");
    if (pNotify)
    {
        FUN_1407521b0(pNotify, "completeUiEffect", &m_2d0.m_id);
        FUN_1408733e0(pNotify, "acceptSoundKey", m_2d0.m_accept);
        FUN_1408733e0(pNotify, "completeSoundKey", m_2d0.m_reward);
    }
    Unk_140165cf0* pRequire = pElem->FUN_140165cf0("require");
    if (pRequire)
    {
        FUN_1408731a0(pRequire, "level", (unsigned short&)m_require.m_level);
        FUN_1408731a0(pRequire, "maxLevel", (unsigned short&)m_require.m_maxLevel);
        FUN_140873220(pRequire, "achievement", m_require.m_achievement);
        FUN_1408731e0(pRequire, "achievementGrade", m_require.m_achievementGrade);
        FUN_140873220(pRequire, "gearScore", m_require.m_gearScore);
        FUN_1408731a0(pRequire, "guildNpcLevel", (unsigned short&)m_require.m_guildNpcLevel);
        FUN_140873220(pRequire, "dungeon", m_require.m_dungeon);
        FUN_140873220(pRequire, "unrequireDungeon", m_require.m_unrequireDungeon);
        FUN_140873220(pRequire, "enterDungeon", m_require.m_enterDungeon);
        FUN_14035bc20(pRequire, "alliance", &m_require.m_alliance);
        FUN_1408731e0(pRequire, "fameGrade", m_require.m_fameGrade);
        FUN_14051fd20(pRequire, "masteryType", &m_require.m_masteryType);
        FUN_1408731e0(pRequire, "masteryGrade", m_require.m_masteryGrade);
        XmlTokenList(pRequire, "dungeonBeginner", m_require.m_dungeonBeginner);
        FUN_1408731e0(pRequire, "mentor", m_require.m_mentor);
        FUN_1408731e0(pRequire, "mentee", m_require.m_mentee);
        FUN_1408731e0(pRequire, "vip", m_require.m_vip);
        XmlTokenList(pRequire, "equipment", m_require.m_equipment);
        XmlTokenList(pRequire, "subJob", m_require.m_subJob);
        XmlTokenList(pRequire, "progressQuest", m_require.m_progressQuest);
        CString strUnreqAchievement = FUN_14015f710(pRequire, "unreqAchievement", "");
        CString strQuest = FUN_14015f710(pRequire, "quest", "");
        CString strJob = FUN_14015f710(pRequire, "job", "");
        CString strUnrequire = FUN_14015f710(pRequire, "unrequire", "");
        CString strSelectableQuest = FUN_14015f710(pRequire, "selectableQuest", "");
        CString strUnrequireGroup = FUN_14015f710(pRequire, "unrequireGroup", "");
        CString strGuildLevel = FUN_14015f710(pRequire, "guildLevel", "");
        if (strGuildLevel.GetLength() > 0)
            m_require.m_guildLevel = FUN_140718170(strGuildLevel);
        ATL::CAtlArray<CString> arrUnreqAchievement;
        FUN_14015f050(strUnreqAchievement, arrUnreqAchievement, ",");
        if (arrUnreqAchievement.GetCount() == 2)
        {
            m_require.m_unreqAchievement = FUN_1407181d0(arrUnreqAchievement[0]);
            m_require.m_unreqAchievementGrade = FUN_140718170(arrUnreqAchievement[1]);
        }
        XmlSplit(strQuest, m_require.m_quest, ",");
        XmlSplit(strSelectableQuest, m_require.m_selectableQuest, ",");
        XmlSplit(strJob, m_require.m_job, ",");
        XmlSplit(strUnrequire, m_require.m_unrequire, ",");
        XmlSplit(strUnrequireGroup, m_require.m_unrequireGroup, ",");
        CString strStartTime;
        CString strEndTime;
        FUN_1408733e0(pRequire, "startTime", strStartTime);
        FUN_1408733e0(pRequire, "endTime", strEndTime);
        CString strDayOfWeek = FUN_14015f710(pRequire, "dayOfWeek", "");
        XmlSplit(strDayOfWeek, m_require.m_dayOfWeek, ",");
        int nGroupId = 0;
        FUN_1408731e0(pRequire, "groupID", nGroupId);
        if (nGroupId != 0 && m_30 == 0)
            m_require.m_groupId = nGroupId;
    }
    for (Unk_140165cf0* pCond = pElem->FUN_140165cf0("condition"); pCond != 0; pCond = pCond->FUN_140168650("condition"))
    {
        MS2Ptr<CConditionCommonData> spCond(new CConditionCommonData());
        unsigned nQuestId = FUN_14074b030(this);
        if (spCond->Load(reinterpret_cast<Unk_ConditionXml*>(pCond), CStringW(L"QuestData"), nQuestId) != 0)
        {
            unsigned nIndex = (unsigned)m_conditions.GetCount();
            m_conditions.Add(spCond);
            Unk_SocketPtr<NavigationData> spNavigation(0);
            for (Unk_140165cf0* pNavi = pCond->FUN_140165cf0("navi"); pNavi != 0; pNavi = pNavi->FUN_140168650("navi"))
            {
                Unk_SocketPtr<NavigationTarget> spTarget(new NavigationTarget());
                FUN_140752630(pNavi, "type", &spTarget->m_kind);
                XmlTokenList(pNavi, "code", spTarget->m_ids);
                XmlTokenList(pNavi, "map", spTarget->m_maps);
                if (spNavigation == 0)
                {
                    spNavigation = Unk_SocketNew(0);
                    spNavigation->m_kind = nIndex;
                }
                spNavigation->m_targets.Add(spTarget);
            }
            if (spNavigation.get() != 0)
                m_navigation.SetAt(nIndex, spNavigation);
        }
    }
    Unk_140165cf0* pStart = pElem->FUN_140165cf0("start");
    if (pStart)
        FUN_140873220(pStart, "npc", (unsigned&)m_2e8);
    Unk_140165cf0* pComplete = pElem->FUN_140165cf0("complete");
    if (pComplete)
        FUN_140873220(pComplete, "npc", (unsigned&)m_2ec);
    Unk_140165cf0* pCompleteReward = pElem->FUN_140165cf0("completeReward");
    if (pCompleteReward)
    {
        FUN_1408731e0(pCompleteReward, "money", m_complete.m_money);
        FUN_1408731e0(pCompleteReward, "exp", m_complete.m_exp);
        FUN_1408731e0(pCompleteReward, "guildFund", m_complete.m_guildFund);
        FUN_1408731e0(pCompleteReward, "guildExp", m_complete.m_guildExp);
        FUN_1408731e0(pCompleteReward, "guildCoin", m_complete.m_guildCoin);
        FUN_1408731e0(pCompleteReward, "menteeCoin", m_complete.m_menteeCoin);
        FUN_1408731e0(pCompleteReward, "missionPoint", m_complete.m_missionPoint);
        FUN_1408731e0(pCompleteReward, "useMainFamePoint", m_complete.m_useMainFamePoint);
        FUN_140873220(pCompleteReward, "fameLog", m_complete.m_fameLog);
        FUN_1408731e0(pCompleteReward, "rewardExpExtra", m_complete.m_rewardExpExtra);
        FUN_140354050(pCompleteReward, "relativeExp", &m_complete.m_relativeExp);
        FUN_140752270(pCompleteReward, "relativeMeso", &m_complete.m_relativeMeso);
        FUN_1408732e0(pCompleteReward, "weddingExp", m_complete.m_weddingExp);
        FUN_1408731e0(pCompleteReward, "karma", m_complete.m_karma);
        FUN_1408731e0(pCompleteReward, "lu", m_complete.m_lu);
        for (Unk_140165cf0* pItem : pCompleteReward->FUN_140165cf0("v"))
        {
            QuestRewardItem item;
            if (item.LoadXml(pItem))
                m_complete.m_choiceRewards.Add(item);
        }
    }
    Unk_140165cf0* pAcceptReward = pElem->FUN_140165cf0("acceptReward");
    if (pAcceptReward)
    {
        for (Unk_140165cf0* pItem : pAcceptReward->FUN_140165cf0("v"))
        {
            QuestRewardItem item;
            if (item.LoadXml(pItem))
                m_rewards.push_back(item);
        }
    }
    Unk_140165cf0* pProgressMap = pElem->FUN_140165cf0("progressMap");
    if (pProgressMap)
    {
        CString strProgressMap = FUN_14015f710(pProgressMap, "progressMap", "");
        XmlSplit(strProgressMap, m_fields, ",");
    }
    Unk_140165cf0* pGuide = pElem->FUN_140165cf0("guide");
    if (pGuide)
    {
        FUN_140752330(pGuide, "guideType", &m_338.m_value);
        FUN_1407524b0(pGuide, "guideGroup", &m_338.m_4);
        FUN_1408733e0(pGuide, "guideIcon", m_338.m_8);
        unsigned short nMinLevel = 0;
        unsigned short nMaxLevel = 0;
        FUN_1408731a0(pGuide, "guideMinLevel", nMinLevel);
        FUN_1408731a0(pGuide, "guideMaxLevel", nMaxLevel);
        m_338.m_levelRange.FUN_14075bc80(nMinLevel, nMaxLevel);
    }
    Unk_140165cf0* pEventMission = pElem->FUN_140165cf0("eventMission");
    if (pEventMission)
        FUN_1407523f0(pEventMission, "event", &m_350.m_value);
    Unk_140165cf0* pMentoring = pElem->FUN_140165cf0("mentoringMission");
    if (pMentoring)
    {
        FUN_1408733e0(pMentoring, "mentoringIcon", m_358.m_8);
        FUN_1408731e0(pMentoring, "openingDay", m_358.m_0);
        FUN_1408731e0(pMentoring, "mentoringSeason", m_358.m_4);
    }
    Unk_140165cf0* pDispatch = pElem->FUN_140165cf0("dispatch");
    if (pDispatch)
    {
        FUN_140751f70(pDispatch, "type", &m_2f0.m_0);
        FUN_140873220(pDispatch, "field", (unsigned&)m_2f0.m_4);
        FUN_1408731e0(pDispatch, "portal", m_2f0.m_8);
        FUN_1408731e0(pDispatch, "script", m_2f0.m_c);
    }
    if (FUN_14036d570(FUN_140166410(), 0x42) == 1)
    {
        Unk_140165cf0* pGotoNpc = pElem->FUN_140165cf0("gotoNpc");
        if (pGotoNpc)
        {
            FUN_1408731e0(pGotoNpc, "enable", m_300.m_0);
            FUN_140873220(pGotoNpc, "gotoField", (unsigned&)m_300.m_4);
            FUN_1408731e0(pGotoNpc, "gotoPortal", m_300.m_8);
        }
    }
    Unk_140165cf0* pGotoDungeon = pElem->FUN_140165cf0("gotoDungeon");
    if (pGotoDungeon)
    {
        FUN_140751e50(pGotoDungeon, "state", &m_30c.m_0);
        FUN_140873220(pGotoDungeon, "gotoDungeon", (unsigned&)m_30c.m_roomId);
        FUN_140873220(pGotoDungeon, "gotoInstanceID", (unsigned&)m_30c.m_fieldId);
    }
    Unk_140165cf0* pRemoteAccept = pElem->FUN_140165cf0("remoteAccept");
    if (pRemoteAccept)
    {
        FUN_1407520f0(pRemoteAccept, "useRemote", &m_320.m_0);
        FUN_140873220(pRemoteAccept, "requireField", (unsigned&)m_320.m_4);
    }
    Unk_140165cf0* pRemoteComplete = pElem->FUN_140165cf0("remoteComplete");
    if (pRemoteComplete)
    {
        FUN_1407520f0(pRemoteComplete, "useRemote", &m_32c.m_0);
        FUN_140873220(pRemoteComplete, "requireField", (unsigned&)m_32c.m_4);
        FUN_1408731e0(pRemoteComplete, "requireDungeonClear", m_32c.m_8);
    }
    Unk_140165cf0* pSummonPortal = pElem->FUN_140165cf0("summonPortal");
    if (pSummonPortal)
    {
        FUN_140873220(pSummonPortal, "fieldID", (unsigned&)m_318.m_0);
        FUN_1408731e0(pSummonPortal, "portalID", m_318.m_4);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1407495D0, CQuestData, FUN_1407495d0, 6736, 0x22FFC8F3);

// Quest-data accessors on top of the table (0x14074b030 ...).
int ConditionKindOfType(int nType);                         // 0x14029f2b0
class Unk_1401b4ec0
{
public:
    Unk_1401b4ec0(CLockCriticalSection& lock, int bLock);   // 0x1401b4ec0
    ~Unk_1401b4ec0();                                       // 0x1401b5120
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_1401b4ec0, 8);

// @0x14074b030
int FUN_14074b030(CQuestData* pData)
{
    return pData->m_id;
}

// @0x14074b050
int FUN_14074b050(CQuestData* pData)
{
    return pData->m_type;
}

// @0x14074b070
int FUN_14074b070(CQuestData* pData)
{
    return pData->m_20;
}

// @0x14074b090
bool FUN_14074b090(CQuestData* pData)
{
    if (pData->m_durationMinutes != 0)
        return true;
    if (pData->m_schedule.GetLength() != 0)
        return true;
    if (pData->m_resetType != 0)
        return true;
    return false;
}

// @0x14074b0e0
int FUN_14074b0e0(CQuestData* pData, int nValue, int nKind)
{
    for (size_t i = 0; i < pData->m_conditions.GetCount(); i++)
    {
        if (ConditionKindOfType(pData->m_conditions[i]->m_nType) != nKind)
            continue;
        if (!pData->m_conditions[i]->m_code.Matches(nValue))
            continue;
        return 1;
    }
    return 0;
}

// @0x14074b1c0
int FUN_14074b1c0(CQuestData* pData, int nBit)
{
    return pData->m_54.test(nBit) != false;
}

// @0x14074b210
int FUN_14074b210(CQuestData* pData)
{
    if (pData->m_schedule.GetLength() != 0)
    {
        if (!FUN_1401c0d90()->FUN_1404793a0(&pData->m_schedule))
            return 0;
    }
    return 1;
}

// @0x14074b270
int FUN_14074b270(CQuestData* pData)
{
    if (pData->m_320.m_0 != 0)
        return 1;
    if (pData->m_33 != 0)
        return 1;
    if (FUN_14074b050(pData) == 9)
        return 1;
    return 0;
}

// @0x14074b2d0
int FUN_14074b2d0(CQuestData* pData)
{
    if (pData->m_32c.m_0 != 0)
        return 1;
    if (FUN_14074b050(pData) == 8)
        return 1;
    if (FUN_14074b050(pData) == 9)
        return 1;
    return 0;
}

// @0x14074b330
int FUN_14074b330(CQuestData* pData)
{
    if (pData->m_fields.GetCount() == 0)
        return 0;
    return pData->m_fields[0];
}

// @0x14074b380
Unk_SocketPtr<CQuestData::NavigationData> CQuestData::FUN_14074b380(int nKey)
{
    Unk_SocketPtr<NavigationData> spNavi(0);
    m_navigation.Lookup(nKey, spNavi);
    return spNavi;
}

// @0x14074b410
int FUN_14074b410(int nQuestId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
    if (data.IsNull())
        return 0;
    switch (FUN_14074b050(data.operator->()))
    {
    case 3:
    case 4:
    case 5:
    case 7:
    case 10:
        return 0;
    case 0:
    case 1:
    case 2:
    case 6:
    case 8:
    case 9:
        return 1;
    }
    return 0;
}

// @0x14074b510
bool FUN_14074b510(int nQuestId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
    if (data.IsNull())
        return false;
    return FUN_14074b050(data.operator->()) == 3;
}

// @0x14074b5b0
bool FUN_14074b5b0(int nQuestId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
    if (data.IsNull())
        return false;
    return FUN_14074b050(data.operator->()) == 4;
}

// @0x14074b650
bool FUN_14074b650(int nQuestId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
    if (data.IsNull())
        return false;
    return FUN_14074b050(data.operator->()) == 8;
}

// @0x14074b6f0
bool FUN_14074b6f0(int nQuestId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
    if (data.IsNull())
        return false;
    return FUN_14074b050(data.operator->()) == 9;
}

// @0x14074b790
int FUN_14074b790(int nQuestId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
    if (data.IsNull())
        return 0;
    if (FUN_14074b050(data.operator->()) == 8)
        return 1;
    return data->m_31;
}

// @0x14074b840
int FUN_14074b840(int nQuestId)
{
    if (FUN_14036d570(FUN_140166410(), 0x6e))
    {
        MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
        if (data.IsNull())
            return 0;
        if (data->m_conditions.GetCount() != 0)
            return 0;
        if (data->m_2e8 != data->m_2ec)
            return 0;
        return 1;
    }
    return 0;
}

// @0x14074b950
int FUN_14074b950(int nQuestId)
{
    if (FUN_14036d570(FUN_140166410(), 0x6e))
    {
        MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
        if (data.IsNull())
            return 0;
        if (data->m_require.m_followingQuests.GetCount() != 1)
            return 0;
        int nNext = data->m_require.m_followingQuests[0];
        MS2Ptr<CQuestData> next = FUN_14074bc40(nNext);
        if (next.IsNull())
            return 0;
        if (next->m_2e8 != data->m_2ec)
            return 0;
        return 1;
    }
    return 0;
}

// @0x14074bae0
int FUN_14074bae0(unsigned nQuestA, unsigned nQuestB)
{
    if (FUN_14036d570(FUN_140166410(), 0x6e))
    {
        MS2Ptr<CQuestData> a = FUN_14074bc40(nQuestA);
        MS2Ptr<CQuestData> b = FUN_14074bc40(nQuestB);
        if (a.IsNull() || b.IsNull())
            return 0;
        if (FUN_140408410(&b->m_require.m_quest, &nQuestA) == -1)
            return 0;
        if (b->m_2e8 != a->m_2ec)
            return 0;
        return 1;
    }
    return 0;
}

// @0x14074bc40
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId)
{
    return QuestDataTable::GetInstance()->FUN_14074c9d0(nQuestId);
}

// @0x14074bc90
int FUN_14074bc90(int nQuestId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
    if (data.IsNull())
        return 11;
    return data->m_type;
}

// @0x14074bd10
unsigned short FUN_14074bd10(int nQuestId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(nQuestId);
    if (data.IsNull())
        return 0;
    return (unsigned short)data->m_level;
}

// @0x14074bd90
QuestDataTable::QuestDataTable()
{
}

// @0x14074c130
QuestDataTable::~QuestDataTable()
{
    FUN_1407511e0();
}


// MS2-FUNCTIONAL: the exe builds the literal CString temps and the path with a different EH state layout (precedent banktable)
// @0x14074c320
void QuestDataTable::FUN_14074c320()
{
    Unk_1401b4ec0 guard(m_lock, 1);
    CString strPath = FUN_14071a5b0(CString("QuestData"), CString("QuestData.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    Unk_140165cf0* pFirst = pRoot->FUN_140165cf0("quest");
    Unk_XmlElementIterator itNode = begin(pFirst);
    Unk_XmlElementIterator itEnd = end(pFirst);
    for (; itNode != itEnd; ++itNode)
    {
        Unk_140165cf0* pNode = *itNode;
        if (FUN_14028f650(pNode))
        {
            MS2Ptr<CQuestData> spData(new CQuestData);
            if (spData->FUN_1407495d0(pNode))
                m_quests.insert(std::make_pair(FUN_14074b030(spData.operator->()), spData));
        }
    }
    FUN_14074f160();
    SetInit(true);
    FUN_1407503f0();
    FUN_14074fee0();
    FUN_140750d90();
    FUN_140750f30();
    FUN_140750120();

    std::map<unsigned, MS2Ptr<CQuestData> >& quests = m_quests;
    for (std::pair<const unsigned, MS2Ptr<CQuestData> >& entry : quests)
    {
        MS2Ptr<CQuestData> spData = entry.second;
        if (!spData->GetKind())
            continue;
        for (size_t i = 0; i < spData->m_conditions.GetCount(); i++)
        {
            MS2Ptr<CConditionCommonData> spCond = spData->m_conditions[i];
            if (ConditionHasTarget(spCond->m_nType) != 0)
            {
                bool bBad = true;
                if (spCond->m_nType == 0x30)
                {
                    bBad = false;
                    for (size_t k = 0; k < spCond->m_code.m_ids.GetCount(); k++)
                    {
                        MS2Ptr<CQuestData> spOther = FUN_14074c9d0((int)spCond->m_code.m_ids[k]);
                        if (spOther.operator->() != 0 && !spOther->GetKind())
                        {
                            bBad = true;
                            break;
                        }
                    }
                }
                if (bBad)
                {
                    unsigned nQuestId = FUN_14074b030(spData.operator->());
                    unsigned __int64 nIndex = i;
                    CString strMsg = StringFormat("Quest ConditionData dependency error. id:{0} index:{1}", nQuestId, nIndex);
                    MessageBoxA(0, strMsg, "Error", 0);
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14074C320, QuestDataTable, FUN_14074c320, 1691, 0xED84B5B4);

// @0x14074c9d0
MS2Ptr<CQuestData> QuestDataTable::FUN_14074c9d0(int nQuestId)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, MS2Ptr<CQuestData> >::iterator it = m_quests.find(reinterpret_cast<const unsigned&>(nQuestId));
    if (it == m_quests.end())
        return MS2Ptr<CQuestData>(nullptr);
    return it->second;
}

// @0x14074cad0
void QuestDataTable::FUN_14074cad0(ATL::CAtlArray<MS2Ptr<CQuestData> >& out, int nType)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, MS2Ptr<CQuestData> >& quests = m_quests;
    for (std::pair<const unsigned, MS2Ptr<CQuestData> >& entry : quests)
    {
        MS2Ptr<CQuestData> spData = entry.second;
        if (nType != 11 && FUN_14074b050(spData.operator->()) != nType)
            continue;
        out.Add(spData);
    }
}

// @0x14074cbf0
void QuestDataTable::FUN_14074cbf0(int nMapId, ATL::CAtlArray<unsigned>& out)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    IdsPtr spIds(0);
    if (m_1f8.Lookup(nMapId, spIds))
        out.Copy(*spIds.operator->());
}

// @0x14074cca0
void QuestDataTable::FUN_14074cca0(ATL::CAtlArray<MS2Ptr<CQuestData> >& out, int nGrade)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, MS2Ptr<CQuestData> >& quests = m_quests;
    for (std::pair<const unsigned, MS2Ptr<CQuestData> >& entry : quests)
    {
        MS2Ptr<CQuestData> spData = entry.second;
        if (FUN_14074b050(spData.operator->()) != 3)
            continue;
        if (nGrade != 0 && spData->m_338.m_value != nGrade)
            continue;
        out.Add(spData);
    }
}

// @0x14074cde0
void QuestDataTable::FUN_14074cde0(ATL::CAtlArray<MS2Ptr<CQuestData> >& out, int nFlag)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, MS2Ptr<CQuestData> >& quests = m_quests;
    for (std::pair<const unsigned, MS2Ptr<CQuestData> >& entry : quests)
    {
        MS2Ptr<CQuestData> spData = entry.second;
        if (FUN_14074b050(spData.operator->()) != 5)
            continue;
        if (nFlag != 0 && spData->m_350.m_value != nFlag)
            continue;
        out.Add(spData);
    }
}

// @0x14074cf20
void QuestDataTable::FUN_14074cf20(ATL::CAtlArray<unsigned>& out)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    for (POSITION pos = m_chapter.GetStartPosition(); pos != 0; m_chapter.GetNext(pos))
        out.Add(m_chapter.GetKeyAt(pos));
}

// @0x14074cfd0
void QuestDataTable::FUN_14074cfd0(int nChapter, ATL::CAtlArray<unsigned>& out)
{
    CheckInit();
    IdsPtr spIds(0);
    Unk_1401b4ec0 guard(m_lock, 1);
    m_chapter.Lookup(nChapter, spIds);
    if (spIds.get() != 0)
        out.Copy(*spIds.operator->());
}

// @0x14074d080
void QuestDataTable::FUN_14074d080(int nMapId, ATL::CAtlArray<unsigned>& out)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    out.Copy(m_128);
    IdsPtr spIds(0);
    if (m_1f8.Lookup(nMapId, spIds))
        out.Append(*spIds.operator->());
}

// @0x14074d140
void QuestDataTable::FUN_14074d140(unsigned short nLevel, int nJob, std::vector<unsigned>& out)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    for (size_t i = 0; i < m_378.size(); ++i)
    {
        MS2Ptr<CQuestData> spData = m_378[i];
        unsigned short nReqLevel = (unsigned short)spData->m_require.m_level;
        if (nReqLevel >= nLevel)
            continue;
        if (spData->m_require.m_job.GetCount() != 0)
        {
            if (FUN_1407474d0(&spData->m_require.m_job, &nJob) == -1)
                continue;
        }
        out.push_back(FUN_14074b030(spData.operator->()));
    }
}
MS2_REPLACE_METHOD(0x14074D140, QuestDataTable, FUN_14074d140, 350, 0x3F8920CF);

// @0x14074d2b0
void QuestDataTable::FUN_14074d2b0(Unk_FameAlliance nAlliance, ATL::CAtlArray<unsigned>& out)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    IdsPtr spIds(0);
    if (m_318.Lookup(nAlliance, spIds))
        out.Copy(*spIds.operator->());
}

// @0x14074d360
void QuestDataTable::FUN_14074d360(unsigned nKey, ATL::CAtlArray<unsigned>& out)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    IdsPtr spIds(0);
    if (m_240.Lookup(nKey, spIds))
        out.Copy(*spIds.operator->());
}

// @0x14074d410
void QuestDataTable::FUN_14074d410(ATL::CAtlArray<unsigned>& out)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    out.Copy(m_1d8);
}

// The predicates of the quest order sort (find_if over the pointer vectors).
typedef std::vector<MS2Ptr<CQuestData> > QuestVec;
struct Unk_QuestIdIs
{
    explicit Unk_QuestIdIs(const int& nKey) : m_pKey(&nKey) {}
    bool operator()(MS2Ptr<CQuestData> spData) const { return FUN_14074b030(spData.operator->()) == *m_pKey; }
    const int* m_pKey;
};
struct Unk_QuestPrevIs
{
    explicit Unk_QuestPrevIs(const int& nKey) : m_pKey(&nKey) {}
    bool operator()(MS2Ptr<CQuestData> spData) const
    {
        int nPrev = spData->m_require.m_quest.GetCount() == 0 ? 0 : spData->m_require.m_quest[0];
        return nPrev == *m_pKey;
    }
    const int* m_pKey;
};
struct Unk_QuestLevelFree
{
    explicit Unk_QuestLevelFree(const int& nLevel) : m_pLevel(&nLevel) {}
    bool operator()(MS2Ptr<CQuestData> spData) const { return *m_pLevel <= (unsigned short)spData->m_require.m_level && spData->m_require.m_job.GetCount() == 0; }
    const int* m_pLevel;
};
struct Unk_QuestLevelAbove
{
    explicit Unk_QuestLevelAbove(const int& nLevel) : m_pLevel(&nLevel) {}
    bool operator()(MS2Ptr<CQuestData> spData) const { return *m_pLevel < (unsigned short)spData->m_require.m_level; }
    const int* m_pLevel;
};
// the second lookup in the merge loop is its own (identical) functor in the exe
struct Unk_QuestLevelAbove2
{
    explicit Unk_QuestLevelAbove2(const int& nLevel) : m_pLevel(&nLevel) {}
    bool operator()(MS2Ptr<CQuestData> spData) const { return *m_pLevel < (unsigned short)spData->m_require.m_level; }
    const int* m_pLevel;
};

// MS2-FUNCTIONAL: orders m_378 so a quest follows its prerequisite chain and chains are merged by required level
// @0x14074d480
void QuestDataTable::FUN_14074d480()
{
    QuestVec sorted;
    for (;;)
    {
        if (m_378.size() == 0)
        {
            sorted.swap(m_378);
            return;
        }
        size_t nBefore = m_378.size();
        QuestVec chain;
        MS2Ptr<CQuestData> spCur = m_378[0];
        m_378.erase(m_378.begin());
        chain.push_back(spCur);
        int nKey = spCur->m_require.m_quest.GetCount() == 0 ? 0 : spCur->m_require.m_quest[0];
        while (nKey != 0)
        {
            QuestVec::iterator it = std::find_if(m_378.begin(), m_378.end(), Unk_QuestIdIs(nKey));
            nKey = 0;
            if (it != m_378.end())
            {
                nKey = (*it)->m_require.m_quest.GetCount() == 0 ? 0 : (*it)->m_require.m_quest[0];
                chain.insert(chain.begin(), *it);
                m_378.erase(it);
            }
        }
        spCur = chain[chain.size() - 1];
        nKey = FUN_14074b030(spCur.operator->());
        while (nKey != 0)
        {
            QuestVec::iterator it = std::find_if(m_378.begin(), m_378.end(), Unk_QuestPrevIs(nKey));
            nKey = 0;
            if (it != m_378.end())
            {
                nKey = FUN_14074b030(it->operator->());
                chain.push_back(*it);
                m_378.erase(it);
            }
        }
        if (sorted.size() == 0)
        {
            sorted.insert(sorted.begin(), chain.begin(), chain.end());
        }
        else
        {
            MS2Ptr<CQuestData> spFirst = chain[0];
            MS2Ptr<CQuestData> spLast = chain[chain.size() - 1];
            int nLevel = spFirst->m_require.m_level;
            bool bDiff;
            if (spFirst->m_require.m_level == spLast->m_require.m_level)
                bDiff = spFirst->m_28 != spLast->m_28;
            else
                bDiff = true;
            if (!bDiff)
            {
                QuestVec::iterator it = std::find_if(sorted.begin(), sorted.end(), Unk_QuestLevelFree(nLevel));
                sorted.insert(it, chain.begin(), chain.end());
            }
            else
            {
                QuestVec::iterator it = std::find_if(sorted.begin(), sorted.end(), Unk_QuestLevelAbove(nLevel));
                if (spFirst->m_require.m_level != spLast->m_require.m_level && !(it != sorted.end()))
                {
                    QuestVec::iterator pos = chain.begin();
                    QuestVec::iterator cur = chain.begin();
                    for (; cur != chain.end(); cur++)
                    {
                        int nCurLevel = (*cur)->m_require.m_level;
                        if (nLevel < nCurLevel)
                        {
                            sorted.insert(it, pos, cur);
                            pos = cur;
                            nLevel = nCurLevel;
                            it = std::find_if(sorted.begin(), sorted.end(), Unk_QuestLevelAbove2(nLevel));
                        }
                    }
                    sorted.insert(it, pos, chain.end());
                }
                else
                {
                    sorted.insert(it, chain.begin(), chain.end());
                }
            }
        }
        if (m_378.size() == nBefore)
            _wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\questdata.cpp", 0x6e3);
    }
}
MS2_REPLACE_METHOD(0x14074D480, QuestDataTable, FUN_14074d480, 2780, 0x697FD88B);

// @0x14074df70
QuestDataTable::IdsPtr QuestDataTable::FUN_14074df70(unsigned nKey, int nIndex)
{
    CheckInit();
    IdsPtr spIds(0);
    Unk_1401b4ec0 guard(m_lock, 1);
    m_148[nIndex].Lookup(nKey, spIds);
    return spIds;
}

// @0x14074e030
bool QuestDataTable::FUN_14074e030(int nNpcId)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    return m_430.find(nNpcId) != m_430.end();
}

// @0x14074e0d0
std::vector<unsigned>& QuestDataTable::FUN_14074e0d0()
{
    return m_360;
}

// @0x14074e0f0
std::vector<unsigned>* QuestDataTable::FUN_14074e0f0(int nNpcId)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, std::vector<unsigned> >::iterator it = m_430.find(reinterpret_cast<const unsigned&>(nNpcId));
    if (it == m_430.end())
        return 0;
    return &it->second;
}

// @0x14074e1c0
unsigned QuestDataTable::FUN_14074e1c0(int nKey)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    unsigned nValue = 0;
    m_98.Lookup(nKey, nValue);
    return nValue;
}

// @0x14074e240
unsigned QuestDataTable::FUN_14074e240(int nKey)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    unsigned nValue = 0;
    m_e0.Lookup(nKey, nValue);
    return nValue;
}

// @0x14074e2c0
unsigned QuestDataTable::FUN_14074e2c0(int nKey)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<int, unsigned>::iterator it = m_420.find(nKey);
    if (it == m_420.end())
        return 0;
    return it->second;
}

// @0x14074e390
int QuestDataTable::FUN_14074e390(int nGroupId)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    Unk_SocketPtr<CQuestData::GroupPickData> spPick(0);
    if (m_3d8.Lookup(nGroupId, spPick))
        return spPick->m_kind;
    return 0;
}

// @0x14074e450
int QuestDataTable::FUN_14074e450(int nGroupId)
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    Unk_SocketPtr<CQuestData::GroupPickData> spPick(0);
    if (m_3d8.Lookup(nGroupId, spPick))
        return spPick->m_count;
    return 1;
}

// MS2-FUNCTIONAL: stack-frame slot order of the temporaries differs from the exe.
// @0x14074e6c0
void QuestDataTable::FUN_14074e6c0(int nGroupId, int nSelector, int nSeed, ATL::CAtlArray<unsigned>& out)
{
    IdsPtr spIds(0);
    {
        Unk_1401b4ec0 guard(m_lock, 1);
        if (!m_390.Lookup(nGroupId, spIds))
            return;
    }
    if (spIds.operator->()->GetCount() == 0)
        return;
    int nFirstId = spIds.operator->()->GetAt(0);
    MS2Ptr<CQuestData> spFirst = FUN_14074c9d0(nFirstId);
    if (spFirst.IsNull())
        return;
    CMsTime now(FUN_140869440());
    int nRandSeed = 0;
    if (nSelector != 0)
        nRandSeed = nSelector;
    else
    {
        if (FUN_14074b070(spFirst.operator->()) == 2)
        {
            int nYear = now.GetYear() * 10000;
            int nYearMonth = nYear + now.GetMonth() * 100;
            nRandSeed = (nYearMonth + now.GetDay()) * nGroupId;
            nRandSeed = nRandSeed + nSeed;
        }
        else if (FUN_14074b070(spFirst.operator->()) == 3)
        {
            __int64 tWeek = FUN_14086b190(6, now.Get());
            CMsTime weekStart(tWeek);
            int nDay = weekStart.GetDay();
            int nMonth = weekStart.GetMonth();
            int nDayNo = (int)FUN_14086b590(weekStart.GetYear(), nMonth, nDay);
            nRandSeed = (weekStart.GetYear() * 10000 + nDayNo) * nGroupId;
            nRandSeed = nRandSeed + nSeed;
        }
    }
    Unk_Random rnd(nRandSeed);
    ATL::CAtlArray<unsigned> candidates;
    candidates.Copy(*spIds.operator->());
    int nPicks = GetInstance()->FUN_14074e450(nGroupId);
    for (int i = 0; i < nPicks && candidates.GetCount() != 0; ++i)
    {
        unsigned __int64 nIndex = rnd.FUN_1407684c0() % candidates.GetCount();
        out.Add(candidates[nIndex]);
        candidates.RemoveAt(nIndex, 1);
    }
}
MS2_REPLACE_METHOD(0x14074E6C0, QuestDataTable, FUN_14074e6c0, 1004, 0x40F04FF7);

// @0x14074e510
int QuestDataTable::FUN_14074e510(int nQuestId)
{
    int nValue = 0;
    if (!m_2d0.Lookup(nQuestId, nValue))
        return 0;
    return nValue;
}

// MS2-FUNCTIONAL: stack-frame slot order of the temporaries differs from the exe.
// @0x14074e560
bool QuestDataTable::FUN_14074e560(unsigned nFirst, unsigned nLast)
{
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, MS2Ptr<CQuestData> >& quests = m_quests;
    for (std::pair<const unsigned, MS2Ptr<CQuestData> >& entry : quests)
    {
        MS2Ptr<CQuestData> spData = entry.second;
        if ((unsigned)FUN_14074b030(spData.operator->()) >= nFirst)
        {
            if ((unsigned)FUN_14074b030(spData.operator->()) <= nLast)
            {
                if (spData->m_30 == 0)
                    return true;
            }
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x14074E560, QuestDataTable, FUN_14074e560, 346, 0x400E3FB6);

// @0x14074eac0
void QuestDataTable::FUN_14074eac0(int nQuestId, ATL::CAtlMap<unsigned, int>& visited)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.IsNull())
        return;
    if (visited.Lookup(nQuestId) != 0)
        return;
    visited.SetAt(nQuestId, 1);
    for (size_t i = 0; i < spData->m_require.m_requiredBy.GetCount(); ++i)
        FUN_14074eac0(spData->m_require.m_requiredBy[i], visited);
}

// MS2-FUNCTIONAL: by-value smart-pointer argument and stack slot order differ.
// @0x14074ebc0
void QuestDataTable::FUN_14074ebc0(int nChain, IdsPtr spIds, MS2Ptr<CQuestData> spData, int nDepth)
{
    if (nDepth > 1000)
        return;
    if (spData == 0)
        return;
    if (spData->m_28 != nChain)
        return;
    int nQuestId = FUN_14074b030(spData.operator->());
    if (FUN_140408410(spIds.operator->(), (const unsigned*)&nQuestId) != -1)
        return;
    int nAddId = FUN_14074b030(spData.operator->());
    spIds.get()->Add((unsigned)nAddId);
    for (size_t i = 0; i < spData->m_require.m_followingQuests.GetCount(); ++i)
    {
        FUN_14074ebc0(nChain, spIds, FUN_14074c9d0(spData->m_require.m_followingQuests[i]), ++nDepth);
    }
}
MS2_REPLACE_METHOD(0x14074EBC0, QuestDataTable, FUN_14074ebc0, 604, 0x6D4ED568);

// MS2-FUNCTIONAL: by-value smart-pointer argument and stack slot order differ.
// @0x14074ee30
void QuestDataTable::FUN_14074ee30()
{
    CheckInit();
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, MS2Ptr<CQuestData> >& quests = m_quests;
    for (std::pair<const unsigned, MS2Ptr<CQuestData> >& entry : quests)
    {
        MS2Ptr<CQuestData> spData = entry.second;
        if (spData == 0)
            break;
        float fExp = 1.0f;
        float fMeso = 1.0f;
        int nType = FUN_14074b050(spData.operator->());
        if (nType == 0)
        {
            fExp = FUN_1404c17a0(FUN_140302b10(), spData->m_level, 5);
            fMeso = FUN_1404c1730(FUN_140302b10(), spData->m_level, 0);
        }
        else if (nType == 1)
        {
            fExp = FUN_1404c17a0(FUN_140302b10(), spData->m_level, 6);
            fMeso = FUN_1404c1730(FUN_140302b10(), spData->m_level, 1);
        }
        else if (nType == 3)
        {
            fExp = FUN_1404c17a0(FUN_140302b10(), spData->m_level, 7);
            fMeso = FUN_1404c1730(FUN_140302b10(), spData->m_level, 2);
        }
        int* pExp = &spData->m_complete.m_exp;
        *pExp = (int)((float)*pExp * fExp);
        spData->m_complete.m_38 = fExp;
        int* pMoney = &spData->m_complete.m_money;
        *pMoney = (int)((float)*pMoney * fMeso);
        spData->m_complete.m_40 = fMeso;
    }
}
MS2_REPLACE_METHOD(0x14074EE30, QuestDataTable, FUN_14074ee30, 806, 0x83205888);

void* FUN_140166440();
void FUN_1406e7140(void* pLog, int a, int b, int nFlags, const wchar_t* pszFormat, const int& arg0, const int& arg1);
void FUN_140177a80(void* pLog, int a, int nFlags, const wchar_t* pszFormat, const int& arg0);
void FUN_140177e10(const CStringA& str, ATL::CAtlArray<unsigned>& rOut, const char* pszSep);
void* FUN_1406aeee0();
bool FUN_1406af060(void* p);

// Looks up (or creates) the quest id list under the key and appends the quest id to it.
template <class TMap, class TKey>
static void AddToIds(TMap& map, const TKey& key, unsigned nQuestId)
{
    QuestDataTable::IdsPtr spIds(0);
    if (!map.Lookup(key, spIds))
    {
        spIds = Unk_BmNewTag(0);
        map.SetAt(key, spIds);
    }
    spIds->Add(nQuestId);
}

// MS2-FUNCTIONAL: builds every quest index from m_quests; MSVC folds the repeated lookup-or-create blocks differently
// @0x14074f160
void QuestDataTable::FUN_14074f160()
{
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, MS2Ptr<CQuestData> >& quests = m_quests;
    std::map<unsigned, MS2Ptr<CQuestData> >::iterator it = quests.begin();
    for (; it != quests.end(); ++it)
    {
        std::pair<const unsigned, MS2Ptr<CQuestData> >& entry = *it;
        MS2Ptr<CQuestData> spData = entry.second;
        unsigned nId = FUN_14074b030(spData.operator->());
        if (spData->m_33)
            m_360.push_back(nId);
        AddToIds(m_chapter, spData->m_28, nId);
        if (FUN_14074b050(spData.operator->()) != 4 && spData->m_2d && !spData->m_30)
            m_128.Add(nId);
        if (FUN_14074b050(spData.operator->()) == 9)
            AddToIds(m_318, spData->m_4c, nId);
        if (spData->m_require.m_groupId != 0)
            AddToIds(m_390, spData->m_require.m_groupId, nId);

        size_t nConditions = spData->m_conditions.GetCount();
        for (size_t i = 0; i < nConditions; i++)
        {
            MS2Ptr<CConditionCommonData> spCond = spData->m_conditions[i];
            if (spCond->m_nType == 0x9c)
            {
                int nKey = (int)spCond->m_target.GetFirstValue();
                if (m_420.find(nKey) == m_420.end())
                    m_420.insert(std::make_pair(nKey, nId));
            }
            else if (spCond->m_nType == 3 || spCond->m_nType == 0xad)
            {
                int nIdx = spCond->m_nType != 3;
                ATL::CAtlArray<unsigned> ids;
                FUN_140177e10(*spCond->m_code.GetText(), ids, ",");
                for (size_t j = 0; j < ids.GetCount(); j++)
                    AddToIds(m_148[nIdx], ids[j], nId);
            }
        }

        int nKeyA = spData->m_2e8;
        int nKeyB = spData->m_2ec;
        m_430[nKeyA].push_back(nId);
        if (nKeyA != nKeyB)
            m_430[nKeyB].push_back(nId);

        if (FUN_14074b050(spData.operator->()) == 4)
        {
            if (spData->m_fields.GetCount() != 0)
                AddToIds(m_1f8, spData->m_fields[0], nId);
        }
        else if (FUN_14074b050(spData.operator->()) == 8)
        {
            if (spData->m_fields.GetCount() != 0)
                AddToIds(m_240, spData->m_fields[0], nId);
        }

        if (spData->m_320.m_0 == 1)
            m_1d8.Add(FUN_14074b030(spData.operator->()));

        if (nId == 0x56c8ccb || (FUN_14074b050(spData.operator->()) == 0 && !spData->GetKind() && spData->m_30 == 0))
            m_378.push_back(spData);

        FUN_1407484a0(&spData->m_complete, FUN_14074b030(spData.operator->()));

        if (spData->m_2e == 0 && !FUN_1406af060(FUN_1406aeee0()))
        {
            size_t nRewards = spData->m_rewards.size();
            for (size_t i = 0; i < nRewards; i++)
            {
                CQuestData::QuestRewardItem& reward = spData->m_rewards[i];
                MS2Ptr<CItemData> spItem = FUN_14053f870(reward.m_itemId);
                if (!spItem)
                {
                    int nQuest = FUN_14074b030(spData.operator->());
                    FUN_1406e7140(FUN_140166440(), 0, 0, 0x30, L"invalid quest item [qid:{0}, itemid:{1}]", nQuest, reward.m_itemId);
                }
                if (spItem->limit.shopSell != 0)
                {
                    int nQuest = FUN_14074b030(spData.operator->());
                    FUN_1406e7140(FUN_140166440(), 0, 0, 0x30, L"abusing item [qid:{0}, itemid:{1}]", nQuest, reward.m_itemId);
                }
            }
        }

        if (FUN_14074b050(spData.operator->()) == 3 && spData->m_resetType == 0)
        {
            int nQuest = FUN_14074b030(spData.operator->());
            FUN_140177a80(FUN_140166440(), 1, 0x30, L"주간 퀘스트인데 초기화 날짜가 없습니다. usePeriod에 초기화 요일을 적어주세요 [quest={0}]", nQuest);
        }
    }
    FUN_14074d480();
}
MS2_REPLACE_METHOD(0x14074F160, QuestDataTable, FUN_14074f160, 3448, 0xCBA25530);

// MS2-FUNCTIONAL: shared id-list pointer copies of the exe differ.
// @0x14074fee0
void QuestDataTable::FUN_14074fee0()
{
    Unk_1401b4ec0 guard(m_lock, 1);
    for (POSITION pos = m_chapter.GetStartPosition(); pos != 0; m_chapter.GetNext(pos))
    {
        int nChapter = m_chapter.GetKeyAt(pos);
        IdsPtr spIds = m_chapter.GetValueAt(pos);
        if (spIds->GetCount() == 0)
            continue;
        MS2Ptr<CQuestData> spData = FUN_14074bc40(spIds->GetAt(0));
        if (!spData)
            continue;
        unsigned nFieldId;
        if (FUN_140700390()->FUN_1406fb700(spData->m_2e8, &nFieldId) != 0)
        {
            MS2Ptr<CFieldData> spField = CFieldData::FUN_140374140(nFieldId);
            if (!spField)
                continue;
            m_98.SetAt(nChapter, spField->FUN_140375370());
            m_e0.SetAt(nChapter, spField->FUN_140375350());
        }
    }
}
MS2_REPLACE_METHOD(0x14074FEE0, QuestDataTable, FUN_14074fee0, 557, 0xD7488436);

void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
bool FUN_14028f710(Unk_140165cf0* pElem);
int FUN_140752030(Unk_140165cf0* pElem, const char* pszName, int* pOut);
// MS2-FUNCTIONAL: the exe builds the literal CString temps and the path with a different EH state layout (precedent banktable)
// @0x140750120
void QuestDataTable::FUN_140750120()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("QuestGroupTable.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    Unk_1401b4ec0 guard(m_lock, 1);
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("group"); pNode != 0; pNode = pNode->FUN_140168650("group"))
    {
        if (FUN_14028f710(pNode))
        {
            Unk_SocketPtr<CQuestData::GroupPickData> spPick(new CQuestData::GroupPickData);
            FUN_1408731e0(pNode, "id", spPick->m_18);
            FUN_1408731e0(pNode, "pickCount", spPick->m_count);
            FUN_140752030(pNode, "dependency", &spPick->m_kind);
            m_3d8.SetAt(spPick->m_18, spPick);
        }
    }
}
MS2_REPLACE_METHOD(0x140750120, QuestDataTable, FUN_140750120, 713, 0x932C35CB);

void FUN_140353fc0(void* pLog, int a, int nFlags, const wchar_t* pszFormat, const int& arg0);

// MS2-FUNCTIONAL: links the quests (reverse require lists) and rebuilds each chapter's id list in chain order
// @0x1407503f0
void QuestDataTable::FUN_1407503f0()
{
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, MS2Ptr<CQuestData> >& quests = m_quests;
    for (std::pair<const unsigned, MS2Ptr<CQuestData> >& entry : quests)
    {
        MS2Ptr<CQuestData> spData = entry.second;
        for (size_t i = 0; i < spData->m_require.m_quest.GetCount(); i++)
        {
            std::map<unsigned, MS2Ptr<CQuestData> >::iterator itOther = quests.find(spData->m_require.m_quest[i]);
            if (itOther != quests.end())
            {
                MS2Ptr<CQuestData> spOther = itOther->second;
                unsigned nId = FUN_14074b030(spData.operator->());
                if (FUN_140408410(&spOther->m_require.m_requiredBy, &nId) == -1)
                {
                    spOther->m_require.m_requiredBy.Add(FUN_14074b030(spData.operator->()));
                    spOther->m_require.m_followingQuests.Add(FUN_14074b030(spData.operator->()));
                }
            }
        }
        for (size_t i = 0; i < spData->m_require.m_selectableQuest.GetCount(); i++)
        {
            std::map<unsigned, MS2Ptr<CQuestData> >::iterator itOther = quests.find(spData->m_require.m_selectableQuest[i]);
            if (itOther != quests.end())
            {
                MS2Ptr<CQuestData> spOther = itOther->second;
                unsigned nId = FUN_14074b030(spData.operator->());
                if (FUN_140408410(&spOther->m_require.m_selectableBy, &nId) == -1)
                {
                    spOther->m_require.m_selectableBy.Add(FUN_14074b030(spData.operator->()));
                    spOther->m_require.m_followingQuests.Add(FUN_14074b030(spData.operator->()));
                }
            }
        }
    }

    for (POSITION pos = m_chapter.GetStartPosition(); pos != 0; m_chapter.GetNext(pos))
    {
        int nChain = m_chapter.GetKeyAt(pos);
        IdsPtr spIds = m_chapter.GetValueAt(pos);
        bool bInvalid = false;
        if (spIds->GetCount() < 2)
            continue;
        MS2Ptr<CQuestData> spHead(0);
        for (size_t i = 0; i < spIds->GetCount(); i++)
        {
            MS2Ptr<CQuestData> spQuest = FUN_14074c9d0(spIds->GetAt(i));
            if (!spQuest)
                continue;
            if (FUN_14074b070(spQuest.operator->()) == 0 && FUN_14074b050(spQuest.operator->()) != 2 &&
                FUN_14074b050(spQuest.operator->()) != 3)
            {
                ATL::CAtlArray<unsigned> prev;
                prev.Append(spQuest->m_require.m_quest);
                prev.Append(spQuest->m_require.m_selectableQuest);
                if (prev.GetCount() == 0)
                {
                    spHead = spQuest;
                    break;
                }
                for (size_t j = 0; j < prev.GetCount(); j++)
                {
                    MS2Ptr<CQuestData> spPrev = FUN_14074c9d0(prev[j]);
                    if (!spPrev)
                        continue;
                    if (spPrev->m_28 != nChain)
                        spHead = spQuest;
                    break;
                }
                if (spHead.operator->() != 0)
                    break;
            }
            else
            {
                bInvalid = true;
                break;
            }
        }
        if (!bInvalid)
        {
            if (!spHead)
            {
                FUN_140353fc0(FUN_140166440(), 2, 0x13, L"ChapterID:{0} 챕터 연계 퀘스트 오류. Require Quest 확인해 주세요.", nChain);
            }
            else
            {
                IdsPtr spOrdered((Unk_BmNewTag(0)));
                FUN_14074ebc0(nChain, spOrdered, spHead, 0);
                if (spOrdered->GetCount() == spIds->GetCount())
                    m_chapter.SetAt(nChain, spOrdered);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1407503F0, QuestDataTable, FUN_1407503f0, 2429, 0x77FD9E9C);

int FUN_140751650(int nValue);

// Quest id order of the per-npc lists: by quest type, then by level within a type, with the types ranked through FUN_140751650.
struct Unk_BinaryFunction {};   // the exe functor derives from std::binary_function (removed from the C++17 library)
struct Unk_QuestIdOrder : public Unk_BinaryFunction
{
    bool operator()(int nA, int nB) const
    {
        int nTypeA = FUN_14074bc90(nA);
        int nTypeB = FUN_14074bc90(nB);
        if (nTypeA == nTypeB)
        {
            unsigned short nLevelA = FUN_14074bd10(nA);
            unsigned short nLevelB = FUN_14074bd10(nB);
            return nLevelA < nLevelB;
        }
        return FUN_140751650(nTypeA) < FUN_140751650(nTypeB);
    }
};

// MS2-FUNCTIONAL: sorts the quest id list of every npc
// @0x140750d90
void QuestDataTable::FUN_140750d90()
{
    Unk_1401b4ec0 guard(m_lock, 1);
    Unk_QuestIdOrder pred = Unk_QuestIdOrder();
    for (std::pair<const unsigned, std::vector<unsigned> >& entry : m_430)
    {
        std::sort(entry.second.begin(), entry.second.end(), pred);
    }
}
MS2_REPLACE_METHOD(0x140750D90, QuestDataTable, FUN_140750d90, 252, 0x26A038B0);

int __cdecl FUN_140751770(const void* pA, const void* pB);

// @0x140750ea0
void QuestDataTable::FUN_140750ea0()
{
    Unk_1401b4ec0 guard(m_lock, 1);
    qsort(m_1d8.GetData(), m_1d8.GetCount(), 4, FUN_140751770);
}
MS2_REPLACE_METHOD(0x140750EA0, QuestDataTable, FUN_140750ea0, 123, 0x5118FC0F);

// MS2-FUNCTIONAL: marks the quests that must be finished before others unlock (m_2d0 cache)
// @0x140750f30
void QuestDataTable::FUN_140750f30()
{
    Unk_1401b4ec0 guard(m_lock, 1);
    std::map<unsigned, MS2Ptr<CQuestData> >& quests = m_quests;
    for (std::pair<const unsigned, MS2Ptr<CQuestData> >& entry : quests)
    {
        MS2Ptr<CQuestData> spData = entry.second;
        if (spData->m_30 != 0)
            FUN_14074eac0(FUN_14074b030(spData.operator->()), m_2d0);
    }
    for (std::pair<const unsigned, MS2Ptr<CQuestData> >& entry : quests)
    {
        MS2Ptr<CQuestData> spData = entry.second;
        if (spData->m_require.m_selectableQuest.GetCount() != 0)
        {
            bool bAll = true;
            for (size_t i = 0; i < spData->m_require.m_selectableQuest.GetCount(); i++)
            {
                if (FUN_14074e510(spData->m_require.m_selectableQuest[i]) == 0)
                    bAll = false;
            }
            if (bAll)
                FUN_14074eac0(FUN_14074b030(spData.operator->()), m_2d0);
        }
    }
}
MS2_REPLACE_METHOD(0x140750F30, QuestDataTable, FUN_140750f30, 681, 0xCC1801CB);

const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);

// @0x1407511e0
void QuestDataTable::FUN_1407511e0()
{
    m_quests.clear();
    m_chapter.RemoveAll();
    m_98.RemoveAll();
    m_e0.RemoveAll();
    m_420.clear();
    m_390.RemoveAll();
    m_128.RemoveAll();
    m_1d8.RemoveAll();
    m_1f8.RemoveAll();
    m_240.RemoveAll();
    m_2d0.RemoveAll();
    m_318.RemoveAll();
    m_378.clear();
    for (int i = 0; i < 2; i++)
        m_148[i].RemoveAll();
}

// @0x140751330
int FUN_140751330(const CString& str)
{
    if (str.CompareNoCase("directaccept") == 0)
        return 1;
    else if (str.CompareNoCase("directcomplete") == 0)
        return 2;
    else if (str.CompareNoCase("monologueaccept") == 0)
        return 3;
    else if (str.CompareNoCase("monologuecomplete") == 0)
        return 4;
    return 0;
}

// @0x1407513c0
int FUN_1407513c0(const CString& str)
{
    if (str.CompareNoCase("cinematic") == 0)
        return 1;
    else if (str.CompareNoCase("popup") == 0)
        return 2;
    else if (str.CompareNoCase("system") == 0)
        return 3;
    return 0;
}

// @0x140751440
int FUN_140751440(const CString& str)
{
    if (!(str.GetLength() != 0))
    {
        return 0;
    }
    if (str.CompareNoCase("global") == 0)
        return 0;
    else if (str.CompareNoCase("character") == 0)
        return 1;
    else if (str.CompareNoCase("account") == 0)
        return 2;
    return 0;
}
MS2_REPLACE(0x140751440, FUN_140751440, 119, 0xE563F2B7);

// @0x1407514d0
int FUN_1407514d0(const CString& str)
{
    if (str.CompareNoCase("special") == 0)
        return 0;
    else if (str.CompareNoCase("hidebeginablelist") == 0)
        return 1;
    else if (str.CompareNoCase("availablecompletionticket") == 0)
        return 2;
    else if (str.CompareNoCase("HideWorldMap") == 0)
        return 3;
    return 4;
}

// @0x140751560
void FUN_140751560(Unk_140165cf0* pElem, ATL::CAtlArray<CString>& args)
{
    args.RemoveAll();
    for (unsigned i = 0; i < 3; i++)
    {
        CString strName;
        strName.Format("arg%d", i + 1);
        const char* pszValue = FUN_14086f4b0(pElem, strName);
        if (pszValue != 0)
            args.SetAtGrow(i, CString(pszValue));
    }
}

// @0x140751650
int FUN_140751650(int nValue)
{
    if (nValue == 0)
        return 1;
    if (nValue == 2)
        return 2;
    if (nValue == 1)
        return 3;
    return 4;
}

// @0x140751690
int __cdecl FUN_140751690(const void* pA, const void* pB)
{
    const int* pFirst = (const int*)pA;
    const int* pSecond = (const int*)pB;
    int nTypeA = FUN_14074bc90(*pFirst);
    int nTypeB = FUN_14074bc90(*pSecond);
    if (nTypeA == nTypeB)
    {
        unsigned short nFirst = FUN_14074bd10(*pFirst);
        unsigned short nSecond = FUN_14074bd10(*pSecond);
        return nFirst < nSecond ? -1 : 1;
    }
    return FUN_140751650(nTypeA) < FUN_140751650(nTypeB) ? -1 : 1;
}
MS2_REPLACE(0x140751690, FUN_140751690, 205, 0xE5D8EB85);

// @0x140751770
int __cdecl FUN_140751770(const void* pA, const void* pB)
{
    const int* pFirst = (const int*)pA;
    const int* pSecond = (const int*)pB;
    unsigned short nFirst = FUN_14074bd10(*pFirst);
    unsigned short nSecond = FUN_14074bd10(*pSecond);
    int nResult;
    if (nFirst < nSecond)
        nResult = -1;
    else
        nResult = 1;
    return nResult;
}

int FUN_140219300(const CString& str);
int FUN_140217cd0(const CString& str);
int FUN_140217a00(const CString& str);
int FUN_140217bd0(const CString& str);
int FUN_140217ad0(const CString& str);
int FUN_14021a570(const CString& str);
int FUN_14021a1f0(const CString& str);

// @0x140751e50
int FUN_140751e50(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 231), 0));
        return 2;
    }
    int nValue = 0;
    int nResult = FUN_140873890(pElem, pszName, nValue);
    if (nResult != 0)
        return nResult;
    *pOut = nValue;
    return nResult;
}

// @0x140751ee0
int FUN_140751ee0(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 231), 0));
        return 2;
    }
    int nValue = 0;
    int nResult = FUN_140873890(pElem, pszName, nValue);
    if (nResult != 0)
        return nResult;
    *pOut = nValue;
    return nResult;
}

// @0x140751f70
int FUN_140751f70(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_140751330(str);
    return nResult;
}

// @0x140752030
int FUN_140752030(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_140751440(str);
    return nResult;
}

// @0x1407520f0
int FUN_1407520f0(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_1407513c0(str);
    return nResult;
}

// @0x1407521b0
int FUN_1407521b0(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_140219300(str);
    return nResult;
}

// @0x140752270
int FUN_140752270(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_140217cd0(str);
    return nResult;
}

// @0x140752330
int FUN_140752330(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_140217a00(str);
    return nResult;
}

// @0x1407523f0
int FUN_1407523f0(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_140217bd0(str);
    return nResult;
}

// @0x1407524b0
int FUN_1407524b0(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_140217ad0(str);
    return nResult;
}

// @0x140752570
int FUN_140752570(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_14021a570(str);
    return nResult;
}

// @0x140752630
int FUN_140752630(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    *pOut = FUN_14021a1f0(str);
    return nResult;
}

// @0x14075a3f0
CString FUN_14016a5c0(const char* psz, int n);
#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv)
bool QuestDataTable::s_bInit;
#endif
void QuestDataTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(QuestDataTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9bcc0-0x142c9bd80 .text$yd
