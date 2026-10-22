// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The sound property tables (hitSound.xml, systemSound.xml,
// pitchSound.xml, EventSound.xml, TriggerVoice.xml) and the manager SoundPropertyMgr. See soundproperty.h.
// MS2-UNIT: client\ms2\soundproperty.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x140101680-0x1401017f0 .text$di
// MS2-RANGE: 0x141790890-0x1417ae520 .text$mn
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14179cdc0
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14179cf10
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HUUnk_SoundPitch@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14179d1b0
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_SoundPitch@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1417a78d0
// MS2-PIN: ??0CNode@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEAA@HI@Z 0x1417a0010
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@IEAA@H@Z 0x1417a00f0
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1417a4470
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEBA_NHAEAV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@Z 0x1417a4cc0
// MS2-PIN: ?SetAt@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@Z 0x1417a6660
// MS2-PIN: ?NewNode@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@HII@Z 0x1417a3a40
// MS2-PIN: ?CreateNode@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@HII@Z 0x1417a5150
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1417a2df0
// MS2-PIN: ?push_front@?$list@V?$MS2Ptr@VCCacheData@@@@V?$allocator@V?$MS2Ptr@VCCacheData@@@@@std@@@std@@QEAAX$$QEAV?$MS2Ptr@VCCacheData@@@@@Z 0x1417ae2d0
// MS2-PIN: ??_7SoundPropertyMgr@@6B?$TSingleton@VSoundPropertyMgr@@@@@ 0x142f69220
// MS2-PIN: ??_7SoundPropertyMgr@@6B?$CValidData@VSoundPropertyMgr@@@@@ 0x142f69230
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Buynode@V?$MS2Ptr@VCCacheData@@@@@?$_List_buy@V?$MS2Ptr@VCCacheData@@@@V?$allocator@V?$MS2Ptr@VCCacheData@@@@@std@@@std@@QEAAPEAU?$_List_node@V?$MS2Ptr@VCCacheData@@@@PEAX@1@PEAU21@0$$QEAV?$MS2Ptr@VCCacheData@@@@@Z 0x141794dd0 ; unique
// MS2-PIN: ??$_Insert@V?$MS2Ptr@VCCacheData@@@@@?$list@V?$MS2Ptr@VCCacheData@@@@V?$allocator@V?$MS2Ptr@VCCacheData@@@@@std@@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCCacheData@@@@@std@@@std@@U_Iterator_base0@2@@1@$$QEAV?$MS2Ptr@VCCacheData@@@@@Z 0x141795250 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHUUnk_EventVoice@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHUUnk_EventVoice@@@1@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@1@@Z 0x14179b8b0 ; unique
// MS2-PIN: ??$forward@AEBU?$less@H@std@@@std@@YAAEBU?$less@H@0@AEBU10@@Z 0x14179e940 ; unique
// MS2-PIN: ??$move@AEAV?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x14179eb30 ; unique
// MS2-PIN: ??0?$MS2Ptr@VSystemSoundProperty@@@@QEAA@H@Z 0x14179f0d0 ; unique
// MS2-PIN: ??0?$allocator@U?$_List_node@V?$MS2Ptr@VCCacheData@@@@PEAX@std@@@std@@QEAA@XZ 0x14179fd70 ; prop
// MS2-PIN: ??1?$map@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@@std@@QEAA@XZ 0x1417a0540 ; prop
// MS2-PIN: ??@90c9ea69db87f6874a5a77bf21c2723f@ 0x1417a0d20 ; unique
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x1417a3450 ; unique
// MS2-PIN: ??_GSoundPropertyMgr@@UEAAPEAXI@Z 0x1417a37a0 ; unique
// MS2-PIN: ??_GSystemSoundProperty@@UEAAPEAXI@Z 0x1417a37e0 ; unique
// MS2-PIN: ??_GTriggerVoiceProperty@@UEAAPEAXI@Z 0x1417a3820 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@UUnk_HitSoundKey@@V?$vector@HV?$allocator@H@std@@@std@@U?$less@UUnk_HitSoundKey@@@3@V?$allocator@U?$pair@$$CBUUnk_HitSoundKey@@V?$vector@HV?$allocator@H@std@@@std@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1417ac540 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1417937e0
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141794250
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHUUnk_EventVoice@@@std@@@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHUUnk_EventVoice@@@1@@Z 0x1417946b0
// MS2-PIN: ??$_Kfn@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@1@@Z 0x14179c950
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@1@AEBH@Z 0x14179caa0
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14179e730
// MS2-PIN: ??$forward@AEAU?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@YAAEAU?$pair@$$CBHUUnk_EventVoice@@@0@AEAU10@@Z 0x14179e870
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14179e9d0
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@QEAA@XZ 0x14179fd20
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14179fda0
// MS2-PIN: ?IsEmpty@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEBA_NXZ 0x1417a4ae0
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1417a7990
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_SoundPitch@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_SoundPitch@@@std@@PEAX@2@@Z 0x1417aa390
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@2@XZ 0x1417aa660
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@2@XZ 0x1417aa7e0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x1417aa8d0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x1417aa8e0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@2@XZ 0x1417aa940
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@2@$00@2@XZ 0x1417aaa20
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@2@XZ 0x1417aab00
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@2@XZ 0x1417aab80
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@2@XZ 0x1417aac80
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x1417aafb0
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x1417aafd0
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@2@@Z 0x1417ab110
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@2@@Z 0x1417ab200
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@_K@Z 0x1417acee0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_SoundPitch@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@std@@@std@@@2@0@Z 0x1417ad840
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHUUnk_EventVoice@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1417943a0
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x141794520
// MS2-PIN: ??$construct@U?$pair@$$CBHUUnk_EventVoice@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHUUnk_EventVoice@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14179dd20
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14179e090
// MS2-PIN: ??0?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@QEAA@XZ 0x14179f080
// MS2-PIN: ??4?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@QEAAAEAV0@AEBV0@@Z 0x1417a0840
// MS2-PIN: ??4?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@QEAAAEAV0@AEBUUnk_FieldNewTag@@@Z 0x1417a3860
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEAAXXZ 0x1417a3b00
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEAAXXZ 0x1417a3b60
// MS2-PIN: ?FindNextNode@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x1417a3c40
// MS2-PIN: ?GetNext@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x1417a4220
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEAAAEAV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@PEAU__POSITION@@@Z 0x1417a46b0
// MS2-PIN: ?RemoveAll@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEAAXXZ 0x1417a5ee0
// MS2-PIN: ?AddRefImpl@?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@AEBAXPEAX@Z 0x1417a6c80
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_SoundPitch@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@std@@@std@@@2@@Z 0x1417ad930
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@std@@@2@@Z 0x1417ae0c0
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@2@@Z 0x1417ae100
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHUUnk_EventVoice@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x141793ae0
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1417949c0
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14179e4b0
// MS2-PIN: ??1?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEAA@XZ 0x1417a0190
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HUUnk_SoundPitch@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1417a02f0
// MS2-PIN: ??1?$map@HUUnk_SoundPitch@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@3@@std@@QEAA@XZ 0x1417a0500
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1417a2850
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1417a2dd0
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1417a3350
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x1417ac5a0
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1417ae3e0
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x141793e80
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@1@@Z 0x141794730
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141794d00
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@1@AEBH@Z 0x14179cd20
// MS2-PIN: ??@1830a4daf89d272c95ec3911af8a1793@ 0x1417a1130
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1417a7890
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@2@@Z 0x1417a7cd0
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HUUnk_SoundPitch@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1417ac4e0
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x1417ae040
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x1417ae360
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHUUnk_EventVoice@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@1@AEAU?$pair@$$CBHUUnk_EventVoice@@@1@1@Z 0x141795990
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_SoundPitch@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1417a0410
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@2@XZ 0x1417a7730
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@2@@Z 0x1417a7b90
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_SoundPitch@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@std@@@std@@@2@@Z 0x1417a91f0
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@UUnk_HitSoundKey@@V?$vector@HV?$allocator@H@std@@@std@@U?$less@UUnk_HitSoundKey@@@3@V?$allocator@U?$pair@$$CBUUnk_HitSoundKey@@V?$vector@HV?$allocator@H@std@@@std@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBUUnk_HitSoundKey@@V?$vector@HV?$allocator@H@std@@@std@@@std@@PEAX@2@@Z 0x1417aa510
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@2@@Z 0x1417aa540
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@std@@@2@AEBH@Z 0x1417adec0
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141793d10
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14179d060
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14179d5a0
// MS2-PIN: ??$construct@V?$MS2Ptr@VCCacheData@@@@V1@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$MS2Ptr@VCCacheData@@@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VCCacheData@@@@PEAX@std@@@1@QEAV?$MS2Ptr@VCCacheData@@@@$$QEAV3@@Z 0x14179e140
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x1417a45d0
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHUUnk_EventVoice@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_EventVoice@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHUUnk_EventVoice@@@1@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_EventVoice@@@std@@PEAX@1@@Z 0x141797f90
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HUUnk_EventVoice@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_EventVoice@@@std@@@3@@std@@@std@@@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x1417a0350
// MS2-PIN: ??@bf5d475d8ef5f9eda45d4ed9c8429156@ 0x1417a1490
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_SoundPitch@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1417a2750
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\soundproperty.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/header_statics_a.h"
#include "soundproperty.h"
#include <typeinfo>
#include <stdlib.h>
#include <string.h>
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
CLogString* GetLogString();
void FUN_1403a1280(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const char* const& pszArg);
Unk_140165cf0* FUN_1403f0510(Unk_140165cf0* pElem);                     // the next element with the same name
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);   // attribute text
int FUN_140873ad0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);   // string attribute
CString FUN_14028d1f0(const char* psz);                                 // CString of attribute text
CString FUN_140188f50(const char* psz, int nCodePage);
CString FUN_14016a5c0(const char* psz, int n);                          // narrows a string (the RTTI name in CheckInit)
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);  // Table/<file>
CString FUN_140298360(const char* a, const CString& b);                 // a + b
void FUN_1401d3700(CString& str);                                       // lower-cases in place
bool FUN_140184310(const CString& str, const char* psz);                // equals
unsigned FUN_140767ff0();                                               // random number
unsigned char FUN_1401d1320(CCacheData* pCache);                        // the file changed since it was loaded
int FUN_141658e60(GameObject* pActor);                                  // gender of the player (0 male, 1 female)
int FUN_141654700(GameObject* pActor);                                  // job code
class Unk_SpWorld { public: GameObject* FUN_141bd0cc0(); };
Unk_SpWorld* FUN_1403ed2d0();
class Unk_SpOptions { public: int FUN_141260470(); };
class Unk_SpConfig { public: Unk_SpOptions* FUN_1411b1f30(); };
Unk_SpConfig* FUN_1409a8b10();

CString FUN_14038f6d0(const CString& str, const char* psz);
int FUN_141793500(CString strEvent);

// The job codes of the "Job<n>" attributes of a trigger voice (index 0 unused).
extern const unsigned DAT_142f67fe8;   // table of 12 job codes (1, 10, 20 ... 110)

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton and init flag (symbols-manual.tsv)
bool SoundPropertyMgr::s_bInit;
#endif

// The exe also holds the iterator step forwarders of a map keyed by unsigned (0x1417a2db0); explicit instantiation keeps that copy.
typedef std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const unsigned, Unk_EventVoice> > > > Unk_UEventIter;
template Unk_UEventIter& Unk_UEventIter::operator--();
template MS2Ptr<CCacheData>::MS2Ptr(const MS2Ptr<CCacheData>&);   // the TU's own copy (0x14179f040)
typedef std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const unsigned, Unk_SoundPitch> > > > Unk_UPitchIter;
template Unk_UPitchIter& Unk_UPitchIter::operator--();

// @0x141790890
Unk_HitSoundKey::Unk_HitSoundKey(int nAttack, int nDefence)
{
    m_nAttack = nAttack;
    m_nDefence = nDefence;
}

// @0x1417908d0
Unk_HitSoundKey::Unk_HitSoundKey(const Unk_HitSoundKey& o)
{
    m_nAttack = o.m_nAttack;
    m_nDefence = o.m_nDefence;
}

// @0x141790910
Unk_HitSoundKey& Unk_HitSoundKey::operator=(const Unk_HitSoundKey& o)
{
    m_nAttack = o.m_nAttack;
    m_nDefence = o.m_nDefence;
    return *this;
}

// @0x141790950
bool Unk_HitSoundKey::operator<(const Unk_HitSoundKey& o) const
{
    if (m_nAttack < o.m_nAttack)
        return true;
    return (m_nAttack == o.m_nAttack ? 1 : 0) & (m_nDefence < o.m_nDefence ? 1 : 0);
}

// @0x1417909d0
bool Unk_HitSoundKey::operator==(const Unk_HitSoundKey& o) const
{
    return (m_nAttack == o.m_nAttack && m_nDefence == o.m_nDefence) ? 1 : 0;
}

// @0x141790a20
SystemSoundProperty::SystemSoundProperty()
    : m_nUnk18(0), m_bByGender(false), m_bByJob(false), m_nCooltimeId(0), m_jobSounds(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (local/temporary slot layout, SEH state numbering); behaviour equivalent
// @0x141790ae0
void SystemSoundProperty::Load(Unk_140165cf0* pElem)
{
    XmlTokenList(pElem, "soundID", m_sounds);
    FUN_1408733e0(pElem, "group", m_strGroup);
    FUN_1408730a0(pElem, "byGender", m_bByGender);
    FUN_1408730a0(pElem, "byJob", m_bByJob);
    FUN_140873220(pElem, "cooltimeID", m_nCooltimeId);
    if (m_bByJob && m_bByGender)
    {
        CString strJobs;
        FUN_140873ad0(pElem, "jobSoundID", strJobs);
        ATL::CAtlArray<CString> jobs;
        FUN_14015f050(strJobs, jobs, ";");
        for (unsigned i = 0; i < jobs.GetCount(); i++)
        {
            CString strJob(jobs[i]);
            ATL::CAtlArray<CString> parts;
            FUN_14015f050(strJob, parts, ":");
            if (parts.GetCount() == 2)
            {
                int nJob = atoi(parts[0]);
                ATL::CAtlArray<CString> names;
                FUN_14015f050(parts[1], names, ",");
                if (names.GetCount() == 2)
                {
                    Unk_SoundNameArrayPtr spNames;
                    spNames = Unk_FieldNewTag(0);
                    spNames->Copy(names);
                    m_jobSounds.SetAt(nJob, spNames);
                }
            }
        }
    }
}

// @0x141790e00
CString SystemSoundProperty::GetCategory(int nGender)
{
    if (m_bByGender)
    {
        if (nGender == 0)
            return FUN_14038f6d0(m_strGroup, "/Male");
        if (nGender == 1)
            return FUN_14038f6d0(m_strGroup, "/Female");
    }
    return CString(m_strGroup);
}

// MS2-FUNCTIONAL: bytes differ from the exe (local/temporary slot layout, SEH state numbering); behaviour equivalent
// @0x141790ed0
CString SystemSoundProperty::GetSoundName(unsigned nGender, int nJob)
{
    bool bByJob = m_bByJob;
    if (FUN_1409a8b10()->FUN_1411b1f30()->FUN_141260470() != 0)
        bByJob = false;
    if (m_bByGender && bByJob)
    {
        if (m_jobSounds.IsEmpty())
            return CString((const char*)0);
        Unk_SoundNameArrayPtr spNames;
        if (m_jobSounds.Lookup(nJob, spNames))
        {
            if (1 < nGender)
                return CString((const char*)0);
            return CString((*spNames.get())[nGender]);
        }
    }
    if (!m_sounds.IsEmpty())
        return CString((const char*)0);
    if (!m_bByGender)
        return CString(m_sounds[0]);
    if (nGender < 2)
        return CString(m_sounds[nGender]);
    return CString((const char*)0);
}

// @0x141791120
unsigned SystemSoundProperty::GetCooltimeId() const
{
    return m_nCooltimeId;
}

// @0x141791140
TriggerVoiceProperty::TriggerVoiceProperty()
    : m_bByGender(0), m_bByJob(0), m_jobSounds(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (local/temporary slot layout, SEH state numbering); behaviour equivalent
// @0x1417911e0
void TriggerVoiceProperty::Load(Unk_140165cf0* pElem)
{
    if (pElem != 0)
    {
        FUN_1408731e0(pElem, "byGender", m_bByGender);
        FUN_1408731e0(pElem, "byJob", m_bByJob);
        CString strDefault = FUN_14028d1f0(FUN_14086f4b0(pElem, "defaultSound"));
        FUN_14015f050(strDefault, m_sounds, ",");
        for (unsigned __int64 i = 1; i < 12; i++)
        {
            unsigned nJob = (&DAT_142f67fe8)[i];
            CString strKey;
            strKey.Format("Job%d", nJob);
            CString strNames;
            if (FUN_140873ad0(pElem, strKey, strNames) == 0)
            {
                ATL::CAtlArray<CString> names;
                FUN_14015f050(strNames, names, ",");
                Unk_SoundNameArrayPtr spNames;
                spNames = Unk_FieldNewTag(0);
                spNames->Copy(names);
                m_jobSounds.SetAt(nJob, spNames);
            }
        }
    }
}

// MS2-FUNCTIONAL: bytes differ from the exe (local/temporary slot layout, SEH state numbering); behaviour equivalent
// @0x141791400
bool TriggerVoiceProperty::GetVoice(unsigned nGender, int nJob, CString& strOut)
{
    strOut = "";
    if (m_bByJob == 0)
    {
        if (m_bByGender != 0 && m_sounds.GetCount() != 2)
            return false;
        if (1 < nGender)
            return false;
        if (nGender < m_sounds.GetCount())
            strOut = m_sounds[nGender];
        else
        {
            if (m_sounds.GetCount() == 0)
                return false;
            strOut = m_sounds[0];
        }
    }
    else
    {
        Unk_SoundNameArrayPtr spNames;
        if (!m_jobSounds.Lookup(nJob, spNames))
            return false;
        if (m_bByGender != 0)
        {
            if (spNames->GetCount() != 2)
                return false;
        }
        if (1 < nGender)
            return false;
        if (spNames->GetCount() <= nGender)
            return false;
        strOut = (*spNames.get())[nGender];
    }
    return true;
}

// MS2-FUNCTIONAL: bytes differ from the exe (local/temporary slot layout, SEH state numbering); behaviour equivalent
// @0x141791620
void TriggerVoiceProperty::CollectNames(std::set<CString>& rOut)
{
    int nCount = (int)m_sounds.GetCount();
    for (int i = 0; i < nCount; i++)
    {
        CString strName(m_sounds[i]);
        rOut.insert(strName);
    }
    POSITION pos = m_jobSounds.GetStartPosition();
    while (pos != 0)
    {
        Unk_SoundNameArrayPtr spNames = m_jobSounds.GetValueAt(pos);
        if (!spNames)
        {
            MS2_ASSERT_AT(0x109, 0);
        }
        else
        {
            int nNames = (int)spNames->GetCount();
            for (int j = 0; j < nNames; j++)
            {
                CString strName((*spNames.get())[j]);
                rOut.insert(strName);
            }
        }
        m_jobSounds.GetNext(pos);
    }
}

// @0x141791810
SoundPropertyMgr::SoundPropertyMgr()
    : m_systemSounds(17, 0.75f, 0.25f, 2.25f, 10), m_triggerVoices(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (local/temporary slot layout, SEH state numbering); behaviour equivalent
// @0x141791940
unsigned SoundPropertyMgr::Load()
{
    m_cacheFiles.clear();
    unsigned bOk = 1;
    CString strPath;
    strPath = FUN_14071a5b0("Table", "hitSound.xml");
    bOk = LoadHitSound(strPath) & bOk;
    {
        CachePtr spCache(new CCacheData);
        spCache->FUN_1401d1160(CString(strPath));
        m_cacheFiles.push_front(static_cast<CachePtr&&>(spCache));
    }
    strPath = FUN_14071a5b0("Table", "systemSound.xml");
    bOk = LoadSystemSound(strPath) & bOk;
    {
        CachePtr spCache(new CCacheData);
        spCache->FUN_1401d1160(CString(strPath));
        m_cacheFiles.push_front(static_cast<CachePtr&&>(spCache));
    }
    strPath = FUN_14071a5b0("Table", "pitchSound.xml");
    bOk = LoadPitchSound(strPath) & bOk;
    {
        CachePtr spCache(new CCacheData);
        spCache->FUN_1401d1160(CString(strPath));
        m_cacheFiles.push_front(static_cast<CachePtr&&>(spCache));
    }
    strPath = FUN_14071a5b0("Table", "EventSound.xml");
    bOk = LoadEventSound(strPath) & bOk;
    {
        CachePtr spCache(new CCacheData);
        spCache->FUN_1401d1160(CString(strPath));
        m_cacheFiles.push_front(static_cast<CachePtr&&>(spCache));
    }
    strPath = FUN_14071a5b0("Table", "TriggerVoice.xml");
    bOk = LoadTriggerVoice(strPath) & bOk;
    {
        CachePtr spCache(new CCacheData);
        spCache->FUN_1401d1160(CString(strPath));
        m_cacheFiles.push_front(static_cast<CachePtr&&>(spCache));
    }
    SetInit(true);
    return bOk;
}

// @0x141792180
int SoundPropertyMgr::LoadHitSound(const char* pszPath)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot != 0)
    {
        for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("hitSound"); pElem != 0; pElem = FUN_1403f0510(pElem))
        {
            int nAttack;
            int nDefence;
            int nSoundId;
            nAttack ^= nAttack;
            nDefence ^= nDefence;
            nSoundId ^= nSoundId;
            FUN_1408731e0(pElem, "AttackMaterial", nAttack);
            FUN_1408731e0(pElem, "DefenceMeterial", nDefence);
            FUN_1408731e0(pElem, "soundID", nSoundId);
            Unk_HitSoundKey key(nAttack, nDefence);
            m_hitSounds[key].push_back(static_cast<int&&>(nSoundId));
        }
        return 1;
    }
    FUN_1403a1280(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", pszPath);
    return 0;
}

// @0x141792360
int SoundPropertyMgr::LoadSystemSound(const char* pszPath)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot != 0)
    {
        for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("systemSound"); pElem != 0; pElem = FUN_1403f0510(pElem))
        {
            CString strKey = FUN_140188f50(FUN_14086f4b0(pElem, "key"), 0);
            SystemPtr spProp(new SystemSoundProperty);
            spProp->Load(pElem);
            m_systemSounds.SetAt(strKey, spProp);
        }
        return 1;
    }
    FUN_1403a1280(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", pszPath);
    return 0;
}

// @0x141792570
int SoundPropertyMgr::LoadPitchSound(const char* pszPath)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot != 0)
    {
        for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("pitchSound"); pElem != 0; pElem = FUN_1403f0510(pElem))
        {
            int nId = 0;
            float fPitch = 0.0f;
            int nUnit = 0;
            FUN_1408731e0(pElem, "id", nId);
            FUN_1408731e0(pElem, "pitchUnit", nUnit);
            FUN_140873360(pElem, "pitch", fPitch);
            m_pitches[nId].m_fPitch = fPitch;
            m_pitches[nId].m_nUnits = nUnit;
        }
        return 1;
    }
    FUN_1403a1280(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", pszPath);
    return 0;
}

// MS2-FUNCTIONAL: bytes differ from the exe (local/temporary slot layout, SEH state numbering); behaviour equivalent
// @0x141792740
int SoundPropertyMgr::LoadEventSound(const char* pszPath)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot != 0)
    {
        for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("eventSound"); pElem != 0; pElem = FUN_1403f0510(pElem))
        {
            Unk_EventVoice voice;
            int nType = 0;
            CString strEvent = FUN_14028d1f0(FUN_14086f4b0(pElem, "event"));
            voice.m_strSoundId = FUN_14028d1f0(FUN_14086f4b0(pElem, "soundID"));
            voice.m_strRestoreSoundId = FUN_14028d1f0(FUN_14086f4b0(pElem, "restoreSoundID"));
            if (strEvent.IsEmpty() || (voice.m_strSoundId.IsEmpty() && voice.m_strRestoreSoundId.IsEmpty()))
                continue;
            nType = FUN_141793500(CString(strEvent));
            if (nType == 0)
                continue;
            const char* pszCaster = FUN_14086f4b0(pElem, "onlyCasterMyPC");
            if (pszCaster != 0)
            {
                unsigned bOnlyCaster = strcmp(pszCaster, "true") == 0;
                voice.m_bOnlyCasterMyPC = bOnlyCaster;
            }
            voice.m_strGroup = FUN_14086f4b0(pElem, "group");
            if (!voice.m_strGroup.IsEmpty())
                FUN_1401d3700(voice.m_strGroup);
            int nJob = 0;
            int nGender = 0;
            FUN_1408731e0(pElem, "job", nJob);
            FUN_1408731e0(pElem, "gender", nGender);
            m_events[nType][nGender][nJob][voice.m_bOnlyCasterMyPC] = voice;
        }
        return 1;
    }
    FUN_1403a1280(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", pszPath);
    return 0;
}

// @0x141792b60
int SoundPropertyMgr::LoadTriggerVoice(const char* pszPath)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot != 0)
    {
        for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("voice"); pElem != 0; pElem = FUN_1403f0510(pElem))
        {
            CString strKey = FUN_140188f50(FUN_14086f4b0(pElem, "key"), 0);
            VoicePtr spProp(new TriggerVoiceProperty);
            spProp->Load(pElem);
            m_triggerVoices.SetAt(strKey, spProp);
        }
        return 1;
    }
    FUN_1403a1280(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", pszPath);
    return 0;
}

// @0x141792d70
unsigned SoundPropertyMgr::FUN_141792d70(int nAttack, int nDefence)
{
    CheckInit();
    std::vector<int>& ids = m_hitSounds[Unk_HitSoundKey(nAttack, nDefence)];
    size_t nCount = ids.size();
    if (nCount != 0)
        return ids[FUN_140767ff0() % nCount];
    return 0;
}

// @0x141792e00
int SoundPropertyMgr::FUN_141792e00(int nEventId, GameObject* pActor, Unk_EventVoice* pOut)
{
    CheckInit();
    if (nEventId != 0 && pActor != 0)
    {
        int nGender = FUN_141658e60(pActor);
        int nJob = FUN_141654700(pActor);
        unsigned bCaster = FUN_1403ed2d0()->FUN_141bd0cc0() == pActor;
        *pOut = m_events[nEventId][nGender][nJob][bCaster];
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: bytes differ from the exe (local/temporary slot layout, SEH state numbering); behaviour equivalent
// @0x141792ee0
SoundPropertyMgr::SystemPtr SoundPropertyMgr::FUN_141792ee0(const CString& strName, const CString& strArg)
{
    CheckInit();
    if (m_systemSounds.IsEmpty())
        return SystemPtr(0);
    CString strKey(strArg);
    if (!strArg.IsEmpty())
        strKey += FUN_140298360("_", strName);
    else
        strKey = strName;
    if (strKey.IsEmpty())
        return SystemPtr(0);
    SystemPtr spProp;
    if (m_systemSounds.Lookup(strKey, spProp))
        return spProp;
    const Unk_SystemSoundMap::CPair* pPair = m_systemSounds.Lookup(strName);
    if (pPair != 0)
        return pPair->m_value;
    return SystemPtr(0);
}

// @0x141793110
SoundPropertyMgr::VoicePtr SoundPropertyMgr::FUN_141793110(const CString& strName)
{
    CheckInit();
    if (m_triggerVoices.IsEmpty())
        return VoicePtr(0);
    VoicePtr spProp(0);
    if (m_triggerVoices.Lookup(strName, spProp))
        return spProp;
    return VoicePtr(0);
}

// @0x141793210
void SoundPropertyMgr::FUN_141793210(Unk_VoiceGroupMap& rOut)
{
    for (POSITION pos = m_triggerVoices.GetStartPosition(); pos != 0; m_triggerVoices.GetNext(pos))
    {
        const CString& strKey = m_triggerVoices.GetKeyAt(pos);
        VoicePtr spProp = m_triggerVoices.GetValueAt(pos);
        if (strKey.IsEmpty() || !spProp)
        {
            MS2_ASSERT_AT(0x2a0, 0);
            continue;
        }
        std::set<CString>& names = rOut[strKey];
        spProp->CollectNames(names);
    }
}

// @0x141793340
int SoundPropertyMgr::FUN_141793340(int nObjectId, Unk_SoundPitch* pOut)
{
    CheckInit();
    std::map<int, Unk_SoundPitch>::iterator it = m_pitches.find(nObjectId);
    if (it != m_pitches.end())
    {
        *pOut = it->second;
        return 1;
    }
    return 0;
}

// @0x1417933d0
void SoundPropertyMgr::Reload()
{
    m_hitSounds.clear();
    m_systemSounds.RemoveAll();
    m_triggerVoices.RemoveAll();
    m_pitches.clear();
    m_events.clear();
    Load();
}

// @0x141793450
void SoundPropertyMgr::FUN_141793450()
{
    bool bChanged = false;
    for (std::list<CachePtr>::iterator it = m_cacheFiles.begin(); it != m_cacheFiles.end(); ++it)
    {
        if (FUN_1401d1320((*it).get()) != 0)
        {
            bChanged = true;
            break;
        }
    }
    if (bChanged)
        Reload();
}

// MS2-FUNCTIONAL: bytes differ from the exe (vftable store / unwind info of the destructor body); behaviour equivalent
// @0x141793500
int FUN_141793500(CString strEvent)
{
    if (strEvent.IsEmpty())
        return 0;
    if (FUN_140184310(strEvent, "Boss_Kill"))
        return 1;
    if (FUN_140184310(strEvent, "Boss_EndKill"))
        return 2;
    if (FUN_140184310(strEvent, "otherPC_Kill"))
        return 3;
    if (FUN_140184310(strEvent, "myPC_Resurrection"))
        return 4;
    if (FUN_140184310(strEvent, "myPC_Dead"))
        return 5;
    if (FUN_140184310(strEvent, "skill_action"))
        return 6;
    return 0;
}

// MS2-FUNCTIONAL: bytes differ from the exe (vftable store / unwind info of the destructor body); behaviour equivalent
// @0x1417a0710
SoundPropertyMgr::~SoundPropertyMgr()
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (vftable store / unwind info of the destructor body); behaviour equivalent
// @0x1417a07b0
SystemSoundProperty::~SystemSoundProperty()
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (vftable store / unwind info of the destructor body); behaviour equivalent
// @0x1417a0800
TriggerVoiceProperty::~TriggerVoiceProperty()
{
}

// @0x1417a0900
Unk_EventVoice& Unk_EventVoice::operator=(const Unk_EventVoice& o)
{
    m_bOnlyCasterMyPC = o.m_bOnlyCasterMyPC;
    m_strGroup = o.m_strGroup;
    m_strSoundId = o.m_strSoundId;
    m_strRestoreSoundId = o.m_strRestoreSoundId;
    return *this;
}

// @0x1417a3890
void SoundPropertyMgr::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(SoundPropertyMgr).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1417a6920
void SoundPropertyMgr::SetInit(bool b)
{
    s_bInit = b;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb6df0-0x142cb6e80 .text$yd
