// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: commonfiles\filesystem.cpp
// MS2-RANGE: 0x140395ff0-0x1403b0790 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: memmove_s 0x140396140 ; unique
// MS2-PIN: ??$?0AEBV?$allocator@D@std@@$$V@?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBV?$allocator@D@1@@Z 0x1403a0940 ; unique
// MS2-PIN: ??$?8DU?$char_traits@D@std@@V?$allocator@D@1@@std@@YA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0@Z 0x1403a0cb0 ; prop
// MS2-PIN: ??$?RPEBH@AlgorithmParameters@CryptoPP@@QEAAAEAV01@PEBDAEBQEBH_N@Z 0x1403a1180 ; unique
// MS2-PIN: ??$Unk_FileLog@PEBD@@YAXPEAVCLogString@@HHPEB_WAEBQEBD@Z 0x1403a1280 ; unique
// MS2-PIN: ??$Unk_FileLog@PEBDPEBD@@YAXPEAVCLogString@@HHPEB_WAEBQEBD2@Z 0x1403a1310 ; unique
// MS2-PIN: ??$_Adl_verify_range1@V?$_String_iterator@V?$_String_val@U?$_Simple_types@D@std@@@std@@@std@@V12@@std@@YAXAEBV?$_String_iterator@V?$_String_val@U?$_Simple_types@D@std@@@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x1403a1870 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@YAXPEAPEAVUnk_FileArchive@@0AEAV?$allocator@PEAVUnk_FileArchive@@@0@U?$integral_constant@_N$00@0@@Z 0x1403a1ca0 ; unique
// MS2-PIN: ??$_Destroy_range@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@YAXPEAPEAVUnk_FileArchive@@0AEAV?$allocator@PEAVUnk_FileArchive@@@0@@Z 0x1403a1ce0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBQEAVUnk_FileArchive@@@?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@AEAAXAEBQEAVUnk_FileArchive@@@Z 0x1403a1e40 ; prop
// MS2-PIN: ??$_Emplace_reallocate@AEBQEAVUnk_FileArchive@@@?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@QEAAPEAPEAVUnk_FileArchive@@QEAPEAV2@AEBQEAV2@@Z 0x1403a1fc0 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAPEAVUnk_FileArchive@@PEAPEAV1@@std@@YA_JAEBQEAPEAVUnk_FileArchive@@0Urandom_access_iterator_tag@0@@Z 0x1403a2730 ; unique
// MS2-PIN: ??$_Unfancy@PEAVUnk_FileArchive@@@std@@YAPEAPEAVUnk_FileArchive@@PEAPEAV1@@Z 0x1403a40d0 ; prop
// MS2-PIN: ??$_Unfancy@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@YAPEAV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@0@PEAV10@@Z 0x1403a40e0 ; unique
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@0@AEAV10@@Z 0x1403a4450 ; prop
// MS2-PIN: ??$construct@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@AEBV12@@?$_Default_allocator_traits@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@std@@SAXAEAV?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@1@QEAV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@1@AEBV31@@Z 0x1403a46a0 ; unique
// MS2-PIN: ??$construct@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@V12@@?$_Default_allocator_traits@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@std@@SAXAEAV?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@1@QEAV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@1@$$QEAV31@@Z 0x1403a46f0 ; prop
// MS2-PIN: ??$emplace_back@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAAX$$QEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1403a49f0 ; prop
// MS2-PIN: ??$forward@AEBV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@YAAEBV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@0@AEBV10@@Z 0x1403a4b40 ; unique
// MS2-PIN: ??$forward@AEBV?$allocator@D@std@@@std@@YAAEBV?$allocator@D@0@AEBV10@@Z 0x1403a4b50 ; unique
// MS2-PIN: ??$forward@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@YA$$QEAV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@0@AEAV10@@Z 0x1403a4bb0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@std@@@std@@@0@AEAV10@@Z 0x1403a4bc0 ; unique
// MS2-PIN: ??$move@AEAV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@YA$$QEAV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@0@AEAV10@@Z 0x1403a4c70 ; unique
// MS2-PIN: ??0<lambda_c35615ddb1c8012ea5f5759eaa066093>@@QEAA@AEAV?$unordered_set@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@Z 0x1403a4e10 ; unique
// MS2-PIN: ??0?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@QEAA@XZ 0x1403a4e60 ; unique
// MS2-PIN: ??0?$AlgorithmImpl@V?$SimpleKeyingInterfaceImpl@V?$TwoBases@VBlockCipher@CryptoPP@@URijndael_Info@2@@CryptoPP@@V12@@CryptoPP@@V12@@CryptoPP@@QEAA@XZ 0x1403a4f20 ; unique
// MS2-PIN: ??0?$AlgorithmParametersTemplate@PEBH@CryptoPP@@QEAA@AEBV01@@Z 0x1403a4f40 ; unique
// MS2-PIN: ??0?$AlgorithmParametersTemplate@PEBH@CryptoPP@@QEAA@PEBDAEBQEBH_N@Z 0x1403a4f90 ; unique
// MS2-PIN: ??0?$AllocatorWithCleanup@E$00@CryptoPP@@QEAA@XZ 0x1403a4ff0 ; unique
// MS2-PIN: ??0?$Unk_PayloadPtr@VCFileBuffer@@@@QEAA@XZ 0x1403a5980 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@1@@Z 0x1403a5e40 ; unique
// MS2-PIN: ??0InputRejected@?$InputRejecting@VBufferedTransformation@CryptoPP@@@CryptoPP@@QEAA@XZ 0x1403a6870 ; prop
// MS2-PIN: ??0InputRejected@?$InputRejecting@VFilter@CryptoPP@@@CryptoPP@@QEAA@AEBU012@@Z 0x1403a68f0 ; prop
// MS2-PIN: ??0InputRejected@?$InputRejecting@VFilter@CryptoPP@@@CryptoPP@@QEAA@XZ 0x1403a6930 ; prop
// MS2-PIN: ??1?$AlgorithmImpl@V?$SimpleKeyingInterfaceImpl@V?$TwoBases@VBlockCipher@CryptoPP@@URijndael_Info@2@@CryptoPP@@V12@@CryptoPP@@V12@@CryptoPP@@UEAA@XZ 0x1403a6d20 ; unique
// MS2-PIN: ??1?$AlgorithmParametersTemplate@PEBH@CryptoPP@@UEAA@XZ 0x1403a6d40 ; unique
// MS2-PIN: ??1?$AutoSignaling@V?$InputRejecting@VBufferedTransformation@CryptoPP@@@CryptoPP@@@CryptoPP@@UEAA@XZ 0x1403a6d60 ; prop
// MS2-PIN: ??1?$InputRejecting@VBufferedTransformation@CryptoPP@@@CryptoPP@@UEAA@XZ 0x1403a6f30 ; prop
// MS2-PIN: ??1?$InputRejecting@VFilter@CryptoPP@@@CryptoPP@@UEAA@XZ 0x1403a6f50 ; prop
// MS2-PIN: ??1?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@QEAA@XZ 0x1403a72f0 ; unique
// MS2-PIN: ??1Base64Decoder@CryptoPP@@UEAA@XZ 0x1403a7360 ; prop
// MS2-PIN: ??1Source@CryptoPP@@UEAA@XZ 0x1403a7570 ; unique
// MS2-PIN: ??1Store@CryptoPP@@UEAA@XZ 0x1403a7590 ; prop
// MS2-PIN: ??1StringSource@CryptoPP@@UEAA@XZ 0x1403a75d0 ; prop
// MS2-PIN: ??1StringStore@CryptoPP@@UEAA@XZ 0x1403a75f0 ; unique
// MS2-PIN: ?IsNull@?$Unk_PayloadPtr@VCFileBuffer@@@@QEBA_NXZ 0x1403a7710 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1403a7890 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1403a7a20 ; prop
// MS2-PIN: ?get@?$Unk_PayloadPtr@VCFileBuffer@@@@QEBAPEAVCFileBuffer@@XZ 0x1403a7b10 ; unique
// MS2-PIN: ??E?$_String_iterator@V?$_String_val@U?$_Simple_types@D@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403a7e30 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403a7ec0 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1403a7f70 ; unique
// MS2-PIN: ?Invoke@?$ClassFunHandler@V?$TFunctor@KV?$ParamList@KV?$ParamList@PEAEV?$ParamList@KV?$ParamList@PEAPEAEV?$ParamList@KVEmptyParam@@@@@@@@@@@@@@PEAVCFileSystem@@P82@EAAKKPEAEKPEAPEAEK@Z@@UEAAKKPEAEKPEAPEAEK@Z 0x1403a84d0 ; unique
// MS2-PIN: ??R?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z 0x1403a85b0 ; unique
// MS2-PIN: ??R?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QEBA_KAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z 0x1403a85e0 ; unique
// MS2-PIN: ??_E?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@W7EAAPEAXI@Z 0x1403a86d8 ; unique
// MS2-PIN: ??_E?$CipherModeFinalTemplate_CipherHolder@V?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@V?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@2@@CryptoPP@@W7EAAPEAXI@Z 0x1403a86e4 ; unique
// MS2-PIN: ??_E?$CipherModeFinalTemplate_CipherHolder@V?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@V?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@2@@CryptoPP@@WDA@EAAPEAXI@Z 0x1403a86f0 ; unique
// MS2-PIN: ??_E?$CipherModeFinalTemplate_CipherHolder@V?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@V?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@2@@CryptoPP@@WFA@EAAPEAXI@Z 0x1403a86fc ; unique
// MS2-PIN: ??_E?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@CryptoPP@@W7EAAPEAXI@Z 0x1403a8708 ; unique
// MS2-PIN: ??_E?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@CryptoPP@@WDA@EAAPEAXI@Z 0x1403a8714 ; unique
// MS2-PIN: ??_E?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@CryptoPP@@WFA@EAAPEAXI@Z 0x1403a8720 ; unique
// MS2-PIN: ??_E?$SourceTemplate@VStringStore@CryptoPP@@@CryptoPP@@W7EAAPEAXI@Z 0x1403a872c ; unique
// MS2-PIN: ??_EBaseN_Decoder@CryptoPP@@W7EAAPEAXI@Z 0x1403a8744 ; unique
// MS2-PIN: ??_EStringSource@CryptoPP@@W7EAAPEAXI@Z 0x1403a8750 ; unique
// MS2-PIN: ??_EStringStore@CryptoPP@@W7EAAPEAXI@Z 0x1403a875c ; unique
// MS2-PIN: ??_G?$AlgorithmParametersTemplate@PEBH@CryptoPP@@UEAAPEAXI@Z 0x1403a8770 ; unique
// MS2-PIN: ??_GBase64Decoder@CryptoPP@@UEAAPEAXI@Z 0x1403a89f0 ; prop
// MS2-PIN: ??_GBaseN_Decoder@CryptoPP@@UEAAPEAXI@Z 0x1403a8a30 ; prop
// MS2-PIN: ??_GStringSource@CryptoPP@@UEAAPEAXI@Z 0x1403a8bb0 ; unique
// MS2-PIN: ??_GStringStore@CryptoPP@@UEAAPEAXI@Z 0x1403a8bf0 ; prop
// MS2-PIN: ?ChannelMessageSeriesEnd@?$InputRejecting@VBufferedTransformation@CryptoPP@@@CryptoPP@@UEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H_N@Z 0x1403a8db0 ; unique
// MS2-PIN: ?ChannelMessageSeriesEnd@?$InputRejecting@VFilter@CryptoPP@@@CryptoPP@@UEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H_N@Z 0x1403a8e10 ; unique
// MS2-PIN: ?ChannelPut2@?$InputRejecting@VBufferedTransformation@CryptoPP@@@CryptoPP@@UEAA_KAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEBE_KH_N@Z 0x1403a8e70 ; unique
// MS2-PIN: ?ChannelPut2@?$InputRejecting@VFilter@CryptoPP@@@CryptoPP@@UEAA_KAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEBE_KH_N@Z 0x1403a8ed0 ; unique
// MS2-PIN: ?CipherIsRandomAccess@CTR_ModePolicy@CryptoPP@@UEBA_NXZ 0x1403a8f30 ; unique
// MS2-PIN: ?GetAlgorithm@BlockCipher@CryptoPP@@MEBAAEBVAlgorithm@2@XZ 0x1403a92d0 ; unique
// MS2-PIN: ?GetAlgorithm@SymmetricCipher@CryptoPP@@MEBAAEBVAlgorithm@2@XZ 0x1403a92e0 ; unique
// MS2-PIN: ?IsForwardTransformation@?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@CryptoPP@@UEBA_NXZ 0x1403a9840 ; unique
// MS2-PIN: ?IsForwardTransformation@?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@UEBA_NXZ 0x1403a9850 ; unique
// MS2-PIN: ?IsolatedFlush@?$InputRejecting@VBufferedTransformation@CryptoPP@@@CryptoPP@@UEAA_N_N0@Z 0x1403a9990 ; unique
// MS2-PIN: ?IsolatedMessageSeriesEnd@?$InputRejecting@VBufferedTransformation@CryptoPP@@@CryptoPP@@UEAA_N_N@Z 0x1403a9a60 ; unique
// MS2-PIN: ?IsolatedMessageSeriesEnd@?$InputRejecting@VFilter@CryptoPP@@@CryptoPP@@UEAA_N_N@Z 0x1403a9ab0 ; unique
// MS2-PIN: ?MoveInto@?$AlgorithmParametersTemplate@PEBH@CryptoPP@@UEBAXPEAX@Z 0x1403a9e30 ; unique
// MS2-PIN: ?Put2@?$InputRejecting@VBufferedTransformation@CryptoPP@@@CryptoPP@@UEAA_KPEBE_KH_N@Z 0x1403aa430 ; unique
// MS2-PIN: ?Put2@?$InputRejecting@VFilter@CryptoPP@@@CryptoPP@@UEAA_KPEBE_KH_N@Z 0x1403aa490 ; unique
// MS2-PIN: ?ResizeBuffers@CipherModeBase@CryptoPP@@MEAAXXZ 0x1403aade0 ; unique
// MS2-PIN: ?Resynchronize@SimpleKeyingInterface@CryptoPP@@UEAAXPEBEH@Z 0x1403aae20 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$Unk_PayloadPtr@VCFileBuffer@@@@V?$CStringElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$Unk_PayloadPtr@VCFileBuffer@@@@@2@@ATL@@QEAAPEAU__POSITION@@PEBDAEBV?$Unk_PayloadPtr@VCFileBuffer@@@@@Z 0x1403ab020 ; unique
// MS2-PIN: ?SetAutoSignalPropagation@?$AutoSignaling@V?$InputRejecting@VBufferedTransformation@CryptoPP@@@CryptoPP@@@CryptoPP@@UEAAXH@Z 0x1403ab090 ; unique
// MS2-PIN: ?SetAutoSignalPropagation@?$SourceTemplate@VStringStore@CryptoPP@@@CryptoPP@@UEAAXH@Z 0x1403ab0b0 ; unique
// MS2-PIN: ?SetFeedbackSize@CipherModeBase@CryptoPP@@MEAAXI@Z 0x1403ab0f0 ; unique
// MS2-PIN: ?SourceExhausted@?$SourceTemplate@VStringStore@CryptoPP@@@CryptoPP@@UEBA_NXZ 0x1403ab230 ; unique
// MS2-PIN: ?StaticAlgorithmName@?$AlgorithmImpl@V?$SimpleKeyingInterfaceImpl@V?$TwoBases@VBlockCipher@CryptoPP@@URijndael_Info@2@@CryptoPP@@V12@@CryptoPP@@V12@@CryptoPP@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ 0x1403ab2f0 ; unique
// MS2-PIN: ?WriteKeystream@CTR_ModePolicy@CryptoPP@@MEAAXPEAE_K@Z 0x1403ab760 ; unique
// MS2-PIN: ?_Change_array@?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@AEAAXQEAPEAVUnk_FileArchive@@_K1@Z 0x1403abd50 ; prop
// MS2-PIN: ?_Destroy@?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@AEAAXPEAPEAVUnk_FileArchive@@0@Z 0x1403ac0a0 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@2@XZ 0x1403acc60 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVUnk_FileArchive@@@std@@@2@XZ 0x1403acc90 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVUnk_FileArchive@@@std@@@2@XZ 0x1403accb0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@2@XZ 0x1403accd0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@2@XZ 0x1403accf0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@XZ 0x1403acd30 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@XZ 0x1403acd40 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@PEAVUnk_FileArchive@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVUnk_FileArchive@@@std@@@2@$00@std@@QEAAAEAV?$allocator@PEAVUnk_FileArchive@@@2@XZ 0x1403acd50 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_List_node@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAX@std@@@2@XZ 0x1403acd70 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@XZ 0x1403acdb0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@XZ 0x1403acdc0 ; prop
// MS2-PIN: ?_Get_max_bucket_size@?$_Uhash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QEAAAEAMXZ 0x1403acdd0 ; unique
// MS2-PIN: ?_Get_max_bucket_size@?$_Uhash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QEBAAEBMXZ 0x1403ace00 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@M$00@std@@QEAAAEAMXZ 0x1403ace30 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@M$00@std@@QEBAAEBMXZ 0x1403ace40 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@V?$_Compressed_pair@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@M$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@M$00@2@XZ 0x1403ace50 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@2@$00@2@XZ 0x1403ace90 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@PEAVUnk_FileArchive@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVUnk_FileArchive@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVUnk_FileArchive@@@std@@@2@XZ 0x1403acea0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@PEAVUnk_FileArchive@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVUnk_FileArchive@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVUnk_FileArchive@@@std@@@2@XZ 0x1403aceb0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_List_node@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$00@std@@QEAAAEAV?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@XZ 0x1403acec0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_List_node@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$00@std@@QEBAAEBV?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@XZ 0x1403aced0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@std@@@2@XZ 0x1403acef0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@2@XZ 0x1403acf10 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@@2@XZ 0x1403acf20 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEAAAEAV?$allocator@PEAVUnk_FileArchive@@@2@XZ 0x1403acfd0 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEBAAEBV?$allocator@PEAVUnk_FileArchive@@@2@XZ 0x1403acff0 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@@std@@@std@@QEBAAEBV?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@XZ 0x1403ad030 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@PEAX@2@XZ 0x1403ad3f0 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@PEAX@2@PEAU32@@Z 0x1403ad6c0 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEAAAEAPEAPEAVUnk_FileArchive@@XZ 0x1403ad720 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEBAAEBQEAPEAVUnk_FileArchive@@XZ 0x1403ad740 ; unique
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEAAAEAPEAPEAVUnk_FileArchive@@XZ 0x1403ad7a0 ; unique
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEBAAEBQEAPEAVUnk_FileArchive@@XZ 0x1403ad7c0 ; unique
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@@std@@@std@@QEBAAEBQEAV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@2@XZ 0x1403ad800 ; unique
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEAAAEAPEAPEAVUnk_FileArchive@@XZ 0x1403ad840 ; unique
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@@std@@QEAAXXZ 0x1403ad900 ; unique
// MS2-PIN: ?_Reallocate_exactly@?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@AEAAX_K@Z 0x1403ad950 ; unique
// MS2-PIN: ?_Reallocate_exactly@?$vector@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@@std@@AEAAX_K@Z 0x1403ad9f0 ; unique
// MS2-PIN: ?_Tidy@?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@AEAAXXZ 0x1403adf00 ; unique
// MS2-PIN: ?_Umove@?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@AEAAPEAPEAVUnk_FileArchive@@PEAPEAV3@00@Z 0x1403ae0e0 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@@std@@AEAAXPEAV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@2@00U?$integral_constant@_N$00@2@@Z 0x1403ae160 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@V?$allocator@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@@2@@std@@AEAAXPEAV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@U_Iterator_base0@2@@2@00@Z 0x1403ae200 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@@2@XZ 0x1403aeb70 ; unique
// MS2-PIN: ?capacity@?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@QEBA_KXZ 0x1403aed20 ; unique
// MS2-PIN: ?deallocate@?$allocator@PEAVUnk_FileArchive@@@std@@QEAAXQEAPEAVUnk_FileArchive@@_K@Z 0x1403af1d0 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@@2@XZ 0x1403af3b0 ; unique
// MS2-PIN: ?push_back@?$vector@PEAVUnk_FileArchive@@V?$allocator@PEAVUnk_FileArchive@@@std@@@std@@QEAAXAEBQEAVUnk_FileArchive@@@Z 0x1403b02e0 ; prop
// MS2-PINS-END tplpin
// Namespace-qualified secondary vftables: matched TypeDescriptor and COL offset.
// MS2-PIN: ??_7?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@CryptoPP@@6BSimpleKeyingInterface@1@@ 0x142d337d8
// MS2-PIN: ??_7?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@CryptoPP@@6BStreamTransformation@1@@ 0x142d33880
// MS2-PIN: ??_7?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@CryptoPP@@6B?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@1@@ 0x142d338f8
// MS2-PIN: ??_7?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@CryptoPP@@6BRandomNumberGenerator@1@@ 0x142d33960
// MS2-PIN: ??_7?$StringSinkTemplate@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@CryptoPP@@6BAlgorithm@1@@ 0x142d30b00
// MS2-PIN: ??_7?$StringSinkTemplate@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@CryptoPP@@6BWaitable@1@@ 0x142d30c68
// MS2-PIN: ??_7StringStore@CryptoPP@@6BAlgorithm@1@@ 0x142d32ed8
// MS2-PIN: ??_7StringStore@CryptoPP@@6BWaitable@1@@ 0x142d33048
// MS2-PIN: ??_7?$SourceTemplate@VStringStore@CryptoPP@@@CryptoPP@@6BAlgorithm@1@@ 0x142d33078
// MS2-PIN: ??_7?$SourceTemplate@VStringStore@CryptoPP@@@CryptoPP@@6BWaitable@1@@ 0x142d33218
// MS2-PIN: ??_7StringSource@CryptoPP@@6BAlgorithm@1@@ 0x142d33238
// MS2-PIN: ??_7StringSource@CryptoPP@@6BWaitable@1@@ 0x142d333d8
// MS2-PIN: ??_7BaseN_Decoder@CryptoPP@@6BAlgorithm@1@@ 0x142d33438
// MS2-PIN: ??_7BaseN_Decoder@CryptoPP@@6BWaitable@1@@ 0x142d335c0
// MS2-PIN: ??_7Base64Decoder@CryptoPP@@6BAlgorithm@1@@ 0x142d335e0
// MS2-PIN: ??_7Base64Decoder@CryptoPP@@6BWaitable@1@@ 0x142d33768
// MS2-PIN: ??_7?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@6BSimpleKeyingInterface@1@@ 0x142d339f8
// MS2-PIN: ??_7?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@6BBlockTransformation@1@@ 0x142d33a78
// MS2-PIN: ??_7?$CipherModeFinalTemplate_CipherHolder@V?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@V?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@2@@CryptoPP@@6BSimpleKeyingInterface@1@@ 0x142d33ad0
// MS2-PIN: ??_7?$CipherModeFinalTemplate_CipherHolder@V?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@V?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@2@@CryptoPP@@6BStreamTransformation@1@@ 0x142d33b78
// MS2-PIN: ??_7?$CipherModeFinalTemplate_CipherHolder@V?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@V?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@2@@CryptoPP@@6B?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@1@@ 0x142d33bf0
// MS2-PIN: ??_7?$CipherModeFinalTemplate_CipherHolder@V?$BlockCipherFinal@$0A@VEnc@Rijndael@CryptoPP@@@CryptoPP@@V?$ConcretePolicyHolder@VEmpty@CryptoPP@@V?$AdditiveCipherTemplate@V?$AbstractPolicyHolder@UAdditiveCipherAbstractPolicy@CryptoPP@@VCTR_ModePolicy@2@@CryptoPP@@@2@UAdditiveCipherAbstractPolicy@2@@2@@CryptoPP@@6BRandomNumberGenerator@1@@ 0x142d33c58
// MS2-PIN: ?StaticGetValidKeyLength@?$VariableKeyLength@$0BA@$0BA@$0CA@$07$03$0A@@CryptoPP@@SA_K_K@Z 0x1403ab430
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\filesystem.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#pragma intrinsic(memset, memcpy)
#include "filesystem.h"
#include <algorithm>
#include <ctime>
#include <list>
#include <unordered_set>
#include <atlfile.h>
#include <efd/MemoryDefines.h>
#include "logstring.h"
#define NDEBUG
#include <assert.h>
#include "../../../third_party/src/cryptopp562/aes.h"
#include "../../../third_party/src/cryptopp562/modes.h"
#include "../../../third_party/src/cryptopp562/base64.h"
#undef NDEBUG
#include <assert.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void FUN_140351890();
void FUN_140351e90();
bool FUN_140870d70(TiXmlDocument*, const void*, unsigned, int);
bool FUN_140870fc0(TiXmlDocument*, const char*, int);
CString FUN_140188f50(const char*, int);
CString FUN_14016a5c0(const char*, int);
CLogString* FUN_140166440();
#ifdef __clang__
// Bind verified MFC concatenation helpers; clang otherwise emits an unavailable CopyChars DLL import.
CString FUN_14038f6d0(const CString&, const char*);
CString FUN_1401d2b10(const CString&, const CString&);
inline CString Unk_FileConcat(const CString& left, const char* right) { return FUN_14038f6d0(left, right); }
inline CString Unk_FileConcat(const CString& left, const CString& right) { return FUN_1401d2b10(left, right); }
#else
inline CString Unk_FileConcat(const CString& left, const char* right) { return left + right; }
inline CString Unk_FileConcat(const CString& left, const CString& right) { return left + right; }
#endif
inline void Unk_FileRecurse(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude) {
    FUN_140399100(pattern, directory, output, exclude, false);
}
inline void Unk_FileRecurse(CString pattern, CString directory, std::vector<CString>& output, CString exclude) {
    FUN_1403992a0(pattern, directory, output, exclude, false);
}
inline void Unk_FileMoveAppend(ATL::CAtlArray<CString>& output, CString& path) { output.Add(path); }
inline void Unk_FileMoveAppend(std::vector<CString>& output, CString& path) { output.push_back(std::move(path)); }

template<class T> inline void Unk_FileLog(CLogString* log, int level, int category, const wchar_t* format, const T& value) {
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(value)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(value), args));
}
template<class T, class U> inline void Unk_FileLog(CLogString* log, int level, int category, const wchar_t* format,
                                                 const T& first, const U& second) {
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}
struct Unk_FileFailure {
    // @0x1403a4e30
    Unk_FileFailure(CFileSystem* owner, const std::string& path) : owner(owner), path(path) {}
    // Not hooked: function-local static string initialization.
    // @0x1403a8410
    bool operator()() const {
        static std::string extension(".kf");
        if (!owner->FUN_1403981d0() && path.rfind(extension) != std::string::npos) return false;
        return true;
    }
    CFileSystem* owner;
    const std::string& path;
};
MS2_CHECK_SIZE(Unk_FileFailure, 16);
struct Unk_FileSystemLock {
    Unk_FileSystemLock(CLockCriticalSection&, int);
    ~Unk_FileSystemLock();
    void* lock;
};
MS2_CHECK_SIZE(Unk_FileSystemLock, 8);
extern double DAT_1439f4830;
extern unsigned char DAT_1439f3030[2048];
extern unsigned char DAT_143aad2d0[2048];
extern unsigned char DAT_143aadad0[2048];
extern unsigned char DAT_143aae2d0[2048];
extern unsigned char DAT_1439ed030[128][32];
extern unsigned char DAT_1439ee030[128][16];
extern unsigned char** DAT_143aaead0;
extern unsigned char** DAT_143aaead8;
extern unsigned char** DAT_143aaeae0;
extern unsigned char** DAT_143aaeae8;
extern unsigned char** DAT_143aaeaf0;
extern unsigned char** DAT_143aaeaf8;
extern std::string DAT_143ab0568, DAT_143ab0588;
extern int DAT_143ab0560;
class Unk_FileIgnoreList;
extern Unk_FileIgnoreList* DAT_143aaecb0;
Unk_FileIgnoreList* FUN_1403a9410();
bool FUN_14050e2a0(Unk_FileIgnoreList*, std::string);
__time64_t FUN_1403a9480(CFileBuffer*);
void FUN_1403ab1a0(CFileBuffer*, __time64_t);

template<class Output> void Unk_EnumerateLocal(CFileSystem* fs, const CString& pattern, const CString& directory,
                                             Output& output, const CString& exclude) {
    CString base(directory);
    WIN32_FIND_DATAA entry;
    BOOL more = TRUE;
    HANDLE search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[4], dir[272], name[256];
            _splitpath(base, drive, dir, name, nullptr);
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0 && entry.cFileName[0] != '.') {
                char child[272];
                sprintf(child, "%s%s%s/*.*", drive, dir, entry.cFileName);
                std::string childPath(drive);
                childPath.append(dir);
                childPath.append(entry.cFileName);
                if (!fs->FUN_140398640(childPath, false)) Unk_FileRecurse(pattern, CString(child), output, exclude);
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
    more = TRUE;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[8], dir[272], name[256];
            _splitpath(base, drive, dir, name, nullptr);
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                char ext[256];
                _splitpath(entry.cFileName, nullptr, nullptr, nullptr, ext);
                CString extension(ext), filter(pattern);
                filter.Replace("*", "");
                if (filter.CompareNoCase(extension) == 0 || pattern == "*.*") {
                    CString result;
                    result += dir;
                    result += entry.cFileName;
                    std::string path;
                    path = static_cast<const char*>(result);
                    if (!fs->FUN_140398640(path, true) && (exclude.IsEmpty() || result.Find(exclude, 0) == -1)) {
                        result.MakeLower();
                        Unk_FileMoveAppend(output, result);
                    }
                }
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
// @0x140396260
double FUN_140396260(__time64_t first, __time64_t second) { return _difftime64(first, second); }
// @0x140396290
__time64_t FUN_140396290(__time64_t* result) { return _time64(result); }

// @0x1403962b0
CFileSystem::CFileSystem() : cache(10), packed(false), alternatePaths(false), mode(0),
    effectDirectory("./data/resource/model/effect/"), mapDirectory("./data/resource/model/map/"),
    modelDirectory("./data/resource/model/"), stringDirectory("./data/xml/string/") {
    archiveMode = 0;
    characterMask = 0;
    FUN_140351890();
}
// @0x140396460
CFileSystem::~CFileSystem() {
    for (auto it = archives.begin(); it != archives.end(); ++it) {
        (*it)->FUN_1406b1450();
        delete *it;
    }
    archives.clear();
    for (auto it = patchArchives.begin(); it != patchArchives.end(); ++it) {
        (*it)->FUN_1406b1450();
        delete *it;
    }
    patchArchives.clear();
    FUN_140351e90();
}
// MS2-FUNCTIONAL: standard list/string operations retain descending archive order and one-character trimming.
// Not hooked: callback construction creates DLL-local ClassFunHandler RTTI.
#ifndef MS2_HOOK_DLL
// @0x140396770
int CFileSystem::FUN_140396770(unsigned char requestedMode, int requestedArchiveMode) {
    mode = requestedMode;
    archiveMode = requestedArchiveMode;
    char line[2048];
    GetCurrentDirectoryA(2048, line);
    workingDirectory = line;
    std::transform(workingDirectory.begin(), workingDirectory.end(), workingDirectory.begin(), ::tolower);
    for (auto it = workingDirectory.begin(); it != workingDirectory.end(); ++it)
        if (*it == '\\') *it = '/';
    FILE* file = fopen("PackClient.ini", "r");
    if (file != nullptr) {
        packed = true;
        mode = 0;
        std::list<std::string> lines;
        while (fgets(line, 2048, file) != nullptr) lines.push_back(std::string(line));
        fclose(file);
        if (!lines.empty()) {
            lines.sort();
            archives.reserve(lines.size());
            std::string path;
            for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
                path.assign(*it);
                if (path.empty()) continue;
                if (*path.rbegin() == '\r' || *path.rbegin() == '\n') path = path.substr(0, path.length() - 1);
                Unk_FileArchive* archive = new Unk_FileArchive;
                archive->FUN_1406b1ad0(Unk_FileTransform(this, &CFileSystem::FUN_14039a790));
                archive->FUN_1406b1b20(Unk_FileTransform(this, &CFileSystem::FUN_14039b470));
                if (archive->FUN_1406af680(path, 0) == 0) delete archive;
                else archives.push_back(archive);
            }
        }
        FUN_14039ee50();
    }
    return 1;
}
#endif
// MS2-FUNCTIONAL: typed archive ownership and reverse list iteration preserve patch priority.
// Not hooked: callback construction creates DLL-local ClassFunHandler RTTI.
#ifndef MS2_HOOK_DLL
// @0x140396d00
int CFileSystem::FUN_140396d00(const char* directory) {
    if (!FUN_140398190()) return 0;
    for (auto it = patchArchives.begin(); it != patchArchives.end(); ++it) {
        (*it)->FUN_1406b1450();
        delete *it;
    }
    patchArchives.clear();
    FUN_14039b660();
    std::string config(directory);
    config += "/";
    config += "PackDiffClient.ini";
    std::transform(config.begin(), config.end(), config.begin(), ::tolower);
    FILE* file = fopen(config.c_str(), "r");
    if (file != nullptr) {
        std::list<std::string> lines;
        char line[2048];
        while (fgets(line, 2048, file) != nullptr) lines.push_back(std::string(line));
        fclose(file);
        if (!lines.empty()) {
            lines.sort();
            patchArchives.reserve(lines.size());
            std::string path;
            for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
                path.assign(*it);
                if (path.empty()) continue;
                if (*path.rbegin() == '\r' || *path.rbegin() == '\n') path = path.substr(0, path.length() - 1);
                Unk_FileArchive* archive = new Unk_FileArchive;
                archive->FUN_1406b1ad0(Unk_FileTransform(this, &CFileSystem::FUN_14039a790));
                archive->FUN_1406b1b20(Unk_FileTransform(this, &CFileSystem::FUN_14039b470));
                if (archive->FUN_1406af680(path, 0) == 0) delete archive;
                else patchArchives.push_back(archive);
            }
        }
    }
    return 1;
}
#endif
// @0x1403972f0
int CFileSystem::FUN_1403972f0(const char* path, void** data, unsigned __int64* size, std::string* actualPath) {
    if (path != nullptr && data != nullptr && size != nullptr) {
        if (actualPath != nullptr) *actualPath = static_cast<const char*>(FUN_140188f50(path, 0));
        if (FUN_14039bf70() && FUN_1403a0320(path, data, size, actualPath) == 1) return 1;
        if (FUN_140398190() && !FUN_14039f3b0(CString(path))) return FUN_14039f4b0(path, data, size, true);
        return FUN_1403a0320(path, data, size, actualPath);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1403972f0, CFileSystem, FUN_1403972f0, 431, 0x9C7E8407);
// MS2-FUNCTIONAL: preserves XML fallback order and local-only success semantics; frees archive bytes through efd.
// @0x1403974b0
int CFileSystem::FUN_1403974b0(TiXmlDocument* document, const char* path, int encoding, bool warn, bool localOnly) {
    if (FUN_140398190() && !FUN_14039f3b0(CString(path))) {
        unsigned loaded = 0;
        if (FUN_14039bf70()) {
            loaded = FUN_140870fc0(document, FUN_14016a5c0(path, 0), encoding);
            if (loaded == 0) {
                std::string alternate = FUN_14039b810(std::string(path));
                loaded = FUN_140870fc0(document, FUN_14016a5c0(alternate.c_str(), 0), encoding);
            }
        }
        if (loaded != 0) return 1;
        if (localOnly) return 1;
        void* data;
        unsigned __int64 size;
        if (FUN_14039f4b0(path, &data, &size, warn) != 0) {
            if (FUN_140870d70(document, data, static_cast<unsigned>(size), encoding)) {
                EE_FREE(data);
                return 1;
            }
            EE_FREE(data);
        }
        return 0;
    }
    if (FUN_140398640(std::string(path), true)) return 0;
    std::string alternate = FUN_14039b810(std::string(path));
    if (!FUN_140870fc0(document, FUN_14016a5c0(alternate.c_str(), 0), encoding)) {
        if (!FUN_140870fc0(document, FUN_14016a5c0(path, 0), encoding)) {
            if (warn) Unk_FileLog(FUN_140166440(), 1, 0x13, L"파일을 읽을 수 없습니다 [{0}]", CString(path ? path : ""));
            return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1403974b0, CFileSystem, FUN_1403974b0, 1311, 0x73EE0E90);
// MS2-FUNCTIONAL: exe stages the size argument through ecx (mov ecx,[size]; mov r8d,ecx), 2 bytes longer; source form not found.
// @0x1403979e0
int CFileSystem::FUN_1403979e0(TiXmlDocument* document, BufferPtr buffer) {
    if (buffer.IsNull()) return 0;
    unsigned size = buffer->GetSize();
    if (!FUN_140870d70(document, buffer->GetBuffer(), size, 0)) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1403979e0, CFileSystem, FUN_1403979e0, 190, 0xB229CEED);
// @0x140397ab0
int CFileSystem::FUN_140397ab0(TiXmlDocument* document, const CStringW& xml) {
    BufferPtr buffer(new CFileBuffer);
    if (buffer == nullptr) return 0;
    buffer->SetText(xml);
    return FUN_1403979e0(document, buffer);
}
// MS2-FUNCTIONAL: typed cache lookup retains both locked checks, timestamp updates and hit counters.
// Not hooked: loader branches construct CFileBuffer objects with DLL-local RTTI.
#ifndef MS2_HOOK_DLL
// @0x140397bc0
CFileSystem::BufferPtr CFileSystem::FUN_140397bc0(const char* path, int cacheMode, int flag) {
    __time64_t now;
    FUN_140396290(&now);
    BufferPtr buffer;
    {
        Unk_FileSystemLock guard(cacheLock, 1);
        if (cache.Lookup(path, buffer)) {
            FUN_1403ab1a0(buffer.operator->(), now);
            ++buffer->m_field34;
        }
    }
    if (buffer.get() != nullptr) return std::move(buffer);
    std::string normalized(static_cast<const char*>(FUN_140188f50(path, 0)));
    if (normalized.empty()) return BufferPtr(0);
    if (FUN_140398190() && !FUN_14039f3b0(CString(path))) {
        if (FUN_14039bf70()) buffer = FUN_14039c810(normalized, flag);
        if (buffer == nullptr) buffer = FUN_14039cc50(normalized, flag);
    } else buffer = FUN_14039c810(normalized, flag);
    if (buffer == nullptr) cacheMode = 0;
    if (buffer.get() != nullptr) {
        buffer->m_field38 = flag;
        FUN_1403ab1a0(buffer.operator->(), now);
    }
    if (cacheMode != 0 && buffer.get() != nullptr) {
        Unk_FileSystemLock guard(cacheLock, 1);
        BufferPtr existing(0);
        if (!cache.Lookup(path, existing)) cache.SetAt(path, buffer);
        else {
            buffer = existing;
            ++buffer->m_field34;
            FUN_1403ab1a0(buffer.operator->(), now);
        }
    }
    return std::move(buffer);
}
#endif
// @0x140398190
bool CFileSystem::FUN_140398190() { return packed; }
MS2_REPLACE_METHOD(0x140398190, CFileSystem, FUN_140398190, 15, 0x3367C6B5);
// @0x1403981b0
bool CFileSystem::FUN_1403981b0() { return alternatePaths; }
MS2_REPLACE_METHOD(0x1403981b0, CFileSystem, FUN_1403981b0, 15, 0x5368A4AC);
// @0x1403981d0
bool CFileSystem::FUN_1403981d0() { return mode ? true : false; }
MS2_REPLACE_METHOD(0x1403981d0, CFileSystem, FUN_1403981d0, 39, 0x6C197E5C);
// MS2-FUNCTIONAL: typed archive iteration preserves prefix checks and directory attribute semantics.
// @0x140398200
bool CFileSystem::FUN_140398200(std::string path) {
    if (FUN_140398190() && !FUN_14039f3b0(CString(path.c_str()))) {
        std::string resolved = FUN_14039c050(path, false);
        if (resolved.empty()) return false;
        if (resolved == "./") return true;
        const auto& archiveList = archives;
        for (Unk_FileArchive* const& archive : archiveList) {
            if (FUN_1403ab490(resolved, archive->FUN_1403a9490())) {
                if (resolved.length() == archive->FUN_1403a9490().length()) return true;
                std::string relative = resolved.substr(archive->FUN_1403a9490().length() + 1, resolved.length());
                if (archive->FUN_1406b1760(relative) != 0) return true;
            }
        }
        return false;
    }
    if (FUN_140398640(path, false)) return false;
    DWORD attributes = GetFileAttributesA(path.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES) return false;
    return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
}
MS2_REPLACE_METHOD(0x140398200, CFileSystem, FUN_140398200, 1076, 0x9A6476C0);
// @0x140398640
bool CFileSystem::FUN_140398640(std::string path, bool checkFile) {
    if (FUN_1403981d0() && FUN_1403a9410() != nullptr) {
        std::string resolved = FUN_14039c050(path, checkFile);
        if (resolved.empty()) return true;
        if (FUN_14050e2a0(FUN_1403a9410(), resolved)) return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140398640, CFileSystem, FUN_140398640, 386, 0x87673FFA);
// MS2-FUNCTIONAL: preserves local-file priority, archive order, and all seven CreateFileA arguments.
// @0x1403987d0
int CFileSystem::FUN_1403987d0(std::string path) {
    if (FUN_140398190() && !FUN_14039f3b0(CString(path.c_str()))) {
        std::string resolved = FUN_14039c050(path, true);
        if (resolved.empty()) return 0;
        bool stringResource = resolved.find(stringDirectory) != std::string::npos;
        if (FUN_14039bf70()) {
            std::string alternate;
            size_t slash = resolved.find_last_of('/');
            if (slash == std::string::npos) {
                if (stringResource) alternate.assign(DAT_143ab0568);
                else alternate.assign(DAT_143ab0588);
                alternate += resolved;
            } else {
                if (stringResource) alternate = resolved.substr(0, slash + 1) + DAT_143ab0568;
                else alternate = resolved.substr(0, slash + 1) + DAT_143ab0588;
                alternate += resolved.substr(slash + 1, resolved.length());
            }
            HANDLE file = CreateFileA(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
            if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
            file = CreateFileA(resolved.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
            if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
        }
        for (auto it = archives.begin(); it != archives.end(); ++it) {
            if (FUN_1403ab490(resolved, (*it)->FUN_1403a9490())) {
                std::string relative = resolved.substr((*it)->FUN_1403a9490().length() + 1, resolved.length());
                if ((*it)->FUN_1406b14f0(relative, stringResource) != 0) return 1;
            }
        }
        return 0;
    }
    if (FUN_140398640(path, true)) return 0;
    std::string alternate = FUN_14039b810(path);
    HANDLE file = CreateFileA(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
    if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
    file = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
    if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
    return 0;
}
MS2_REPLACE_METHOD(0x1403987d0, CFileSystem, FUN_1403987d0, 2332, 0xDC492B22);

// @0x140399100
void FUN_140399100(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude, bool localOnly) {
    std::vector<CString> paths;
    FUN_1403992a0(pattern, directory, paths, exclude, localOnly);
    for (const CString& path : paths) output.Add(path);
}
MS2_REPLACE(0x140399100, FUN_140399100, 403, 0xA8E81207);
// MS2-FUNCTIONAL: preserves local-first XML deduplication through the original unordered string set.
// @0x1403992a0
void FUN_1403992a0(CString pattern, CString directory, std::vector<CString>& output, CString exclude, bool localOnly) {
    if (!directory.IsEmpty()) {
        CString last = directory.Right(1);
        if (last != "/" && last != "*") directory += "/";
    }
    if (FUN_140166420()->FUN_140398190() && !FUN_140166420()->FUN_14039f3b0(CString(static_cast<const char*>(directory)))) {
        if (pattern.Find(".xml", 0) == -1) {
            if (!localOnly) FUN_140166420()->FUN_14039d9f0(pattern, directory, output, exclude);
        } else {
            std::vector<CString> archived, local;
            FUN_140166420()->FUN_14039e460(pattern, directory, local, exclude);
            if (!localOnly) FUN_140166420()->FUN_14039d9f0(pattern, directory, archived, exclude);
            std::unordered_set<std::string> unique;
            auto append = [&unique](const std::vector<CString>& paths) {
                for (const auto& path : paths) {
                    std::string key(static_cast<const char*>(path));
                    if (unique.find(key) == unique.end()) unique.emplace(key);
                }
            };
            append(local);
            append(archived);
            for (const auto& path : unique) output.push_back(CString(path.c_str()));
        }
    } else FUN_140166420()->FUN_14039e460(pattern, directory, output, exclude);
}
MS2_REPLACE(0x1403992a0, FUN_1403992a0, 877, 0xACD21ED3);
// MS2-FUNCTIONAL: preserves two FindFirstFileA passes, recursive order and extension/exclusion tests.
// @0x140399620
void FUN_140399620(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude, bool localOnly) {
    if (FUN_140166420()->FUN_140398190()) {
        FUN_140399100(pattern, directory, output, exclude, localOnly);
        return;
    }
    CString base(directory);
    if (directory.IsEmpty()) return;
    WIN32_FIND_DATAA entry;
    BOOL more = TRUE;
    HANDLE search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[8], dir[272], name[256];
            _splitpath(base, drive, dir, name, nullptr);
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0 && entry.cFileName[0] != '.') {
                char child[272];
                sprintf(child, "%s%s%s/*.*", drive, dir, entry.cFileName);
                FUN_140399620(pattern, CString(child), output, exclude, localOnly);
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
    more = TRUE;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[8], dir[272], name[256];
            _splitpath(base, drive, dir, name, nullptr);
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                char ext[256];
                _splitpath(entry.cFileName, nullptr, nullptr, nullptr, ext);
                CString extension(ext), filter(pattern);
                filter.Replace("*", "");
                if (filter.CompareNoCase(extension) == 0 || pattern == "*.*") {
                    CString result;
                    result += dir;
                    result += entry.cFileName;
                    if (exclude.IsEmpty() || result.Find(exclude, 0) == -1) output.Add(result);
                }
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
}
MS2_REPLACE(0x140399620, FUN_140399620, 1575, 0x5E159331);
// @0x140399c50
void FUN_140399c50(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude) {
    std::vector<CString> paths;
    FUN_140399de0(pattern, directory, paths, exclude);
    for (const CString& path : paths) output.Add(path);
}
MS2_REPLACE(0x140399c50, FUN_140399c50, 379, 0x513E27BC);
// MS2-FUNCTIONAL: retains nonrecursive enumeration, drive omission in results and lowercase after exclusion.
// @0x140399de0
void FUN_140399de0(CString pattern, CString directory, std::vector<CString>& output, CString exclude) {
    if (!directory.IsEmpty()) {
        CString last = directory.Right(1);
        if (last != "/" && last != "*") directory += "/";
    }
    CString base(directory);
    WIN32_FIND_DATAA entry;
    BOOL more = TRUE;
    HANDLE search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[8], dir[272], name[256];
            _splitpath(base, drive, dir, name, nullptr);
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                char ext[256];
                _splitpath(entry.cFileName, nullptr, nullptr, nullptr, ext);
                CString extension(ext), filter(pattern);
                filter.Replace("*", "");
                if (filter.CompareNoCase(extension) == 0 || pattern == "*.*") {
                    CString result;
                    result += dir;
                    result += entry.cFileName;
                    std::string path;
                    path = static_cast<const char*>(result);
                    if (exclude.IsEmpty() || result.Find(exclude, 0) == -1) {
                        result.MakeLower();
                        output.push_back(std::move(result));
                    }
                }
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
}
MS2_REPLACE(0x140399de0, FUN_140399de0, 889, 0xE5DDE326);
// MS2-FUNCTIONAL: retains texture-directory priority, capacity checks, int exception 13 and diagnostic arguments.
// @0x14039a160
bool CFileSystem::FUN_14039a160(const char* directory, const char* reference, char* result, unsigned capacity) {
    if (FUN_140398190()) {
        std::string resolved = FUN_14039c050(std::string(directory), false);
        std::string name(reference);
        FUN_14039bf80(name);
        size_t slash;
        if (name[0] == '.' && (slash = name.find_first_of('/')) != std::string::npos)
            name = name.substr(slash + 1, name.length());
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        std::string candidate = resolved + name;
        if (FUN_1403987d0(candidate) != 0) {
            if (candidate.length() < capacity) { wsprintfA(result, "%s", candidate.c_str()); return true; }
            throw 13;
        }
        int kind = 3;
        if (FUN_1403ab490(resolved, effectDirectory)) kind = 0;
        else if (FUN_1403ab490(resolved, mapDirectory)) kind = 1;
        else kind = 2;
        auto found = texturePaths[kind].find(name);
        if (found != texturePaths[kind].end() && !found->second.empty()) {
            if (found->second.length() < capacity) { wsprintfA(result, "%s", found->second.c_str()); return true; }
            throw 13;
        }
    }
    Unk_FileLog(FUN_140166440(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}] referencePath : {1}", reference, directory);
    return false;
}
MS2_REPLACE_METHOD(0x14039a160, CFileSystem, FUN_14039a160, 1230, 0x093E08A9);
// @0x14039a640
void CFileSystem::FUN_14039a640() { packed = false; }
MS2_REPLACE_METHOD(0x14039a640, CFileSystem, FUN_14039a640, 15, 0xCAF8FB9C);
// @0x14039a660
void CFileSystem::FUN_14039a660(CString path, void*) {
    Unk_FileSystemLock guard(characterLock, 1);
    if (path == "./data/resource/model/character/female/female.xml") characterMask |= 2;
    else if (path == "./data/resource/model/character/male/male.xml") characterMask |= 1;
}
MS2_REPLACE_METHOD(0x14039a660, CFileSystem, FUN_14039a660, 185, 0x96106327);
// @0x14039a720
unsigned CFileSystem::FUN_14039a720() { return characterMask; }
MS2_REPLACE_METHOD(0x14039a720, CFileSystem, FUN_14039a720, 17, 0x650AC462);
// @0x14039a740
void CFileSystem::FUN_14039a740() {
    Unk_FileSystemLock guard(characterLock, 1);
    characterMask = 0;
}
MS2_REPLACE_METHOD(0x14039a740, CFileSystem, FUN_14039a740, 69, 0x60D6BBDC);
// @0x14039a790
unsigned long CFileSystem::FUN_14039a790(unsigned long magic, unsigned char* data, unsigned long size,
                                       unsigned char** output, unsigned long capacity) {
    if (magic == 0x4632534d) return FUN_14039a8a0(data, size, output, capacity);
    else if (magic == 0x4632534e) return FUN_14039aba0(data, size, output, capacity);
    else if (magic == 0x4632534f) return FUN_14039ae90(data, size, output, capacity);
    else if (magic == 0x46325350) return FUN_14039b180(data, size, output, capacity);
    else MS2_ASSERT_AT(0x4e, 0);
    return 0;
}
// Not hooked: constructs Crypto++ objects with DLL-local RTTI.
// MS2-FUNCTIONAL: the exe's CTR_Mode<AES>::Encryption is 8 bytes larger than the vendored Crypto++ one, so the frame is 0x10 smaller (code otherwise identical).
#ifndef MS2_HOOK_DLL
// @0x14039a8a0
unsigned long CFileSystem::FUN_14039a8a0(unsigned char* data, unsigned long size,
                                       unsigned char** output, unsigned long selector) {
    unsigned index = selector & 0x7f;
    CryptoPP::CTR_Mode<CryptoPP::AES>::Encryption cipher(DAT_1439ed030[index], 32, DAT_1439ee030[index]);
    std::string result;
    try {
        CryptoPP::StringSource(data, size, true, new CryptoPP::Base64Decoder(
            new CryptoPP::StreamTransformationFilter(cipher, new CryptoPP::StringSink(result),
                                                     CryptoPP::StreamTransformationFilter::NO_PADDING, false)));
    } catch (...) {
        return 0;
    }
    *output = new unsigned char[result.length()];
    memcpy(*output, result.data(), result.length());
    return static_cast<unsigned long>(result.length());
}
#endif
// Not hooked: constructs Crypto++ objects with DLL-local RTTI.
// MS2-FUNCTIONAL: the exe's CTR_Mode<AES>::Encryption is 8 bytes larger than the vendored Crypto++ one, so the frame is 0x10 smaller (code otherwise identical).
#ifndef MS2_HOOK_DLL
// @0x14039aba0
unsigned long CFileSystem::FUN_14039aba0(unsigned char* data, unsigned long size,
                                       unsigned char** output, unsigned long selector) {
    unsigned index = selector & 0x7f;
    CryptoPP::CTR_Mode<CryptoPP::AES>::Encryption cipher(DAT_143aaead0[index], 32, DAT_143aaead8[index]);
    std::string result;
    try {
        CryptoPP::StringSource(data, size, true, new CryptoPP::Base64Decoder(
            new CryptoPP::StreamTransformationFilter(cipher, new CryptoPP::StringSink(result),
                                                     CryptoPP::StreamTransformationFilter::NO_PADDING, false)));
    } catch (...) {
        return 0;
    }
    *output = new unsigned char[result.length()];
    memcpy(*output, result.data(), result.length());
    return static_cast<unsigned long>(result.length());
}
#endif
// Not hooked: constructs Crypto++ objects with DLL-local RTTI.
// MS2-FUNCTIONAL: the exe's CTR_Mode<AES>::Encryption is 8 bytes larger than the vendored Crypto++ one, so the frame is 0x10 smaller (code otherwise identical).
#ifndef MS2_HOOK_DLL
// @0x14039ae90
unsigned long CFileSystem::FUN_14039ae90(unsigned char* data, unsigned long size,
                                       unsigned char** output, unsigned long selector) {
    unsigned index = selector & 0x7f;
    CryptoPP::CTR_Mode<CryptoPP::AES>::Encryption cipher(DAT_143aaeae0[index], 32, DAT_143aaeae8[index]);
    std::string result;
    try {
        CryptoPP::StringSource(data, size, true, new CryptoPP::Base64Decoder(
            new CryptoPP::StreamTransformationFilter(cipher, new CryptoPP::StringSink(result),
                                                     CryptoPP::StreamTransformationFilter::NO_PADDING, false)));
    } catch (...) {
        return 0;
    }
    *output = new unsigned char[result.length()];
    memcpy(*output, result.data(), result.length());
    return static_cast<unsigned long>(result.length());
}
#endif
// Not hooked: constructs Crypto++ objects with DLL-local RTTI.
// MS2-FUNCTIONAL: the exe's CTR_Mode<AES>::Encryption is 8 bytes larger than the vendored Crypto++ one, so the frame is 0x10 smaller (code otherwise identical).
#ifndef MS2_HOOK_DLL
// @0x14039b180
unsigned long CFileSystem::FUN_14039b180(unsigned char* data, unsigned long size,
                                       unsigned char** output, unsigned long selector) {
    unsigned index = selector & 0x7f;
    CryptoPP::CTR_Mode<CryptoPP::AES>::Encryption cipher(DAT_143aaeaf0[index], 32, DAT_143aaeaf8[index]);
    std::string result;
    try {
        CryptoPP::StringSource(data, size, true, new CryptoPP::Base64Decoder(
            new CryptoPP::StreamTransformationFilter(cipher, new CryptoPP::StringSink(result),
                                                     CryptoPP::StreamTransformationFilter::NO_PADDING, false)));
    } catch (...) {
        return 0;
    }
    *output = new unsigned char[result.length()];
    memcpy(*output, result.data(), result.length());
    return static_cast<unsigned long>(result.length());
}
#endif
#ifdef __clang__
// Keep imported key-array references in code, not in an absolute-address table.
#pragma clang optimize off
#endif
// @0x14039b470
unsigned long CFileSystem::FUN_14039b470(unsigned long magic, unsigned char* data, unsigned long size,
                                       unsigned char** output, unsigned long capacity) {
    const unsigned char* key = DAT_1439f3030;
    switch (magic) {
    case 0x4632534d: key = DAT_1439f3030; break;
    case 0x4632534e: key = DAT_143aad2d0; break;
    case 0x4632534f: key = DAT_143aadad0; break;
    case 0x46325350: key = DAT_143aae2d0; break;
    default: MS2_ASSERT_AT(0xdd, 0);
    }
    unsigned wordCount = size >> 2;
    unsigned byteCount = size & 3;
    unsigned* words = reinterpret_cast<unsigned*>(data);
    const unsigned* keyWords = reinterpret_cast<const unsigned*>(key);
    unsigned index = 0;
    unsigned pos;
    for (pos = 0; pos < wordCount; ++pos) {
        words[pos] ^= keyWords[index];
        ++index;
        index &= 0x1ff;
    }
    pos <<= 2;
    index = 0;
    for (unsigned tail = 0; tail < byteCount; ++tail) {
        data[pos + tail] ^= key[index];
        ++index;
        index &= 0x7ff;
    }
    *output = data;
    return size;
}
MS2_REPLACE_METHOD(0x14039b470, CFileSystem, FUN_14039b470, 478, 0x65A79091);
#ifdef __clang__
#pragma clang optimize on
#endif
// @0x14039b660
void CFileSystem::FUN_14039b660() {
    Unk_FileSystemLock guard(cacheLock, 1);
    cache.RemoveAll();
}
MS2_REPLACE_METHOD(0x14039b660, CFileSystem, FUN_14039b660, 69, 0x68A6E2C2);
// @0x14039b6b0
void CFileSystem::FUN_14039b6b0() {
    if (cache.GetCount() == 0) return;
    __time64_t now;
    FUN_140396290(&now);
    Unk_FileSystemLock guard(cacheLock, 1);
    POSITION position = cache.GetHeadPosition();
    while (position != nullptr) {
        POSITION current = position;
        cache.GetNext(position);
        const BufferPtr& buffer = cache.GetValueAt(current);
        double age = FUN_140396260(now, FUN_1403a9480(buffer.operator->()));
        if (age >= DAT_1439f4830) cache.RemoveAt(current);
    }
}
MS2_REPLACE_METHOD(0x14039b6b0, CFileSystem, FUN_14039b6b0, 272, 0x26CFCE3D);
// @0x14039b7d0
void CFileSystem::FUN_14039b7d0(int enabled) { alternatePaths = enabled ? true : false; }
MS2_REPLACE_METHOD(0x14039b7d0, CFileSystem, FUN_14039b7d0, 47, 0x717FD09C);
// MS2-FUNCTIONAL: Typed string operations preserve the alternate-prefix insertion position.
// @0x14039b810
std::string CFileSystem::FUN_14039b810(std::string path) {
    path = FUN_14039c050(path, true);
    bool stringResource = path.find(stringDirectory) != std::string::npos;
    std::string result;
    size_t slash = path.find_last_of('/');
    if (slash == std::string::npos) {
        if (stringResource) result.assign(DAT_143ab0568);
        else result.assign(DAT_143ab0588);
        result += path;
    } else {
        if (stringResource) result = path.substr(0, slash + 1) + DAT_143ab0568;
        else result = path.substr(0, slash + 1) + DAT_143ab0588;
        result += path.substr(slash + 1, path.length());
    }
    return result;
}
MS2_REPLACE_METHOD(0x14039b810, CFileSystem, FUN_14039b810, 813, 0x0D22C404);
// MS2-FUNCTIONAL: Typed string operations preserve mode-two language-prefix construction.
// @0x14039bb50
std::string CFileSystem::FUN_14039bb50(std::string path) {
    if (DAT_143ab0560 == 2) {
        path = FUN_14039c050(path, true);
        std::string result;
        size_t slash = path.find_last_of('/');
        if (slash == std::string::npos) {
            result.assign(DAT_143ab0588);
            std::string language(DAT_143ab0568);
            std::transform(language.begin(), language.end(), language.begin(), ::tolower);
            result.append(language);
            result.append("/");
            result += path;
        } else {
            result = path.substr(0, slash + 1) + DAT_143ab0588;
            std::string language(DAT_143ab0568);
            std::transform(language.begin(), language.end(), language.begin(), ::tolower);
            result.append(language);
            result.append("/");
            result += path.substr(slash + 1, path.length());
        }
        return result;
    }
    return std::string("");
}
MS2_REPLACE_METHOD(0x14039bb50, CFileSystem, FUN_14039bb50, 1047, 0xEF6B46BF);
// @0x14039bf70
bool CFileSystem::FUN_14039bf70() { return true; }
MS2_REPLACE_METHOD(0x14039bf70, CFileSystem, FUN_14039bf70, 8, 0x71679366);
// @0x14039bf80
void CFileSystem::FUN_14039bf80(std::string& path) {
    size_t pos = path.find_last_not_of(' ');
    if (pos != std::string::npos) {
        path.erase(pos + 1);
        pos = path.find_first_not_of(' ');
        if (pos != std::string::npos) path.erase(0, pos);
    } else {
        path.erase(path.begin(), path.end());
    }
}
MS2_REPLACE_METHOD(0x14039bf80, CFileSystem, FUN_14039bf80, 190, 0xA7F44878);
// MS2-FUNCTIONAL: explicit list iterators preserve reverse component removal, including repeated parent components.
// @0x14039c050
std::string CFileSystem::FUN_14039c050(std::string path, bool checkFile) {
    std::string result;
    if (checkFile) {
        char extension[256] = {};
        _splitpath(path.c_str(), nullptr, nullptr, nullptr, extension);
        if (extension[0] == '\0') return result;
    }
    FUN_14039bf80(path);
    if (!path.empty()) {
        std::transform(path.begin(), path.end(), path.begin(), ::tolower);
        for (auto it = path.begin(); it != path.end(); ++it) if (*it == '\\') *it = '/';
        size_t slash = path.find("/../");
        if (slash != std::string::npos) {
            result.assign(path);
            std::list<std::string> components;
            while ((slash = result.find_last_of('/')) != std::string::npos) {
                components.push_back(result.substr(slash, result.length()));
                result = result.substr(0, slash);
            }
            components.push_back(result);
            std::list<std::string>::iterator unused;
            for (auto it = components.begin(); it != components.end();) {
                int parents = 0;
                while (it != components.end() && *it == "/..") {
                    ++parents;
                    it = components.erase(it);
                }
                for (int i = 0; i < parents; ++i) {
                    if (it != components.end()) it = components.erase(it);
                }
                if (parents == 0) ++it;
            }
            path.clear();
            for (auto it = components.rbegin(); it != components.rend(); ++it)
                if (*it != "/.") path += *it;
            if (*path.begin() == '/') path = '.' + path;
        }
        if (*path.begin() == '.') return path;
        result = "./";
        if (path.find(workingDirectory) == std::string::npos) result += path;
        else {
            if (path == workingDirectory) return result;
            result += path.substr(workingDirectory.length() + 1, path.length());
        }
    }
    return result;
}
MS2_REPLACE_METHOD(0x14039c050, CFileSystem, FUN_14039c050, 1968, 0xE34581C1);
// MS2-FUNCTIONAL: real ATL file wrapper preserves HRESULT tests, FILE_ATTRIBUTE_NORMAL and ignored short-read result.
// Not hooked: constructs a CFileBuffer with DLL-local RTTI.
#ifndef MS2_HOOK_DLL
// @0x14039c810
CFileSystem::BufferPtr CFileSystem::FUN_14039c810(std::string path, int flag) {
    if (FUN_140398640(path, true)) return BufferPtr(0);
    ATL::CAtlFile file;
    std::string alternate = FUN_14039bb50(path);
    HRESULT opened = E_FAIL;
    if (!alternate.empty()) opened = file.Create(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ,
                                                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr, nullptr);
    if (FAILED(opened)) {
        std::string prefixed = FUN_14039b810(path);
        opened = file.Create(prefixed.c_str(), GENERIC_READ, FILE_SHARE_READ,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr, nullptr);
        if (FAILED(opened)) {
            opened = file.Create(path.c_str(), GENERIC_READ, FILE_SHARE_READ,
                                 OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr, nullptr);
            if (FAILED(opened)) return BufferPtr(0);
        }
    }
    ULONGLONG size = 0;
    file.GetSize(size);
    BufferPtr buffer(new CFileBuffer);
    buffer->Allocate(static_cast<unsigned>(size));
    unsigned count = buffer->GetSize();
    file.Read(buffer->m_pBuffer, count);
    buffer->m_field38 = flag;
    file.Close();
    return std::move(buffer);
}
#endif
// MS2-FUNCTIONAL: typed archive iteration retains patch priority and the conditional missing-file warning.
// Not hooked: constructs a CFileBuffer with DLL-local RTTI.
#ifndef MS2_HOOK_DLL
// @0x14039cc50
CFileSystem::BufferPtr CFileSystem::FUN_14039cc50(std::string path, int flag) {
    void* data = nullptr;
    unsigned __int64 size = 0;
    int found = 0;
    std::string resolved = FUN_14039c050(path, true);
    if (!resolved.empty()) {
        bool stringResource = resolved.find(stringDirectory) != std::string::npos;
        BufferPtr patched = FUN_14039d190(resolved, path, flag);
        if (patched.get() != nullptr) return std::move(patched);
        for (auto it = archives.begin(); it != archives.end(); ++it) {
            if (FUN_1403ab490(resolved, (*it)->FUN_1403a9490())) {
                std::string relative = resolved.substr((*it)->FUN_1403a9490().length() + 1, resolved.length());
                found = (*it)->FUN_1406b0e20(relative, &data, &size, stringResource);
                if (found != 0) break;
            }
        }
        if (found != 0) {
            BufferPtr buffer(new CFileBuffer);
            buffer->Adopt(data, static_cast<unsigned>(size));
            buffer->m_field38 = flag;
            return std::move(buffer);
        }
    }
    if (Unk_FileFailure(this, resolved)()) {
        const char* text = resolved.c_str();
        Unk_FileLog(FUN_140166440(), 1, 0x13, L"파일을 읽을 수 없습니다 [{0}]", text);
    }
    return BufferPtr(0);
}
#endif
// MS2-FUNCTIONAL: typed patch archive iteration retains buffer adoption and by-value parameter destruction.
// Not hooked: constructs a CFileBuffer with DLL-local RTTI.
#ifndef MS2_HOOK_DLL
// @0x14039d190
CFileSystem::BufferPtr CFileSystem::FUN_14039d190(std::string resolved, std::string original, int flag) {
    void* data = nullptr;
    unsigned __int64 size = 0;
    int found = 0;
    if (!resolved.empty()) {
        bool stringResource = resolved.find(stringDirectory) != std::string::npos;
        for (auto it = patchArchives.begin(); it != patchArchives.end(); ++it) {
            if (FUN_1403ab490(resolved, (*it)->FUN_1403a9490())) {
                std::string relative = resolved.substr((*it)->FUN_1403a9490().length() + 1, resolved.length());
                found = (*it)->FUN_1406b0e20(relative, &data, &size, stringResource);
                if (found != 0) break;
            }
        }
        if (found != 0) {
            BufferPtr buffer(new CFileBuffer);
            buffer->Adopt(data, static_cast<unsigned>(size));
            buffer->m_field38 = flag;
            return std::move(buffer);
        }
    }
    return BufferPtr(0);
}
#endif
inline void Unk_FileAppend(ATL::CAtlArray<CString>& output, const CString& path) { output.Add(path); }
inline void Unk_FileAppend(std::vector<CString>& output, const CString& path) { output.push_back(path); }
template<class Output> void Unk_EnumerateArchive(CFileSystem* fs, CString& pattern, CString& directory,
                                               Output& output, CString& exclude) {
    pattern.MakeLower();
    directory.MakeLower();
    exclude.MakeLower();
    bool all = pattern == "*.*";
    std::string filter(static_cast<const char*>(pattern));
    if (*filter.begin() == '*') filter = filter.substr(1, filter.length());
    for (auto archive = fs->archives.begin(); archive != fs->archives.end(); ++archive) {
        if (directory.Find((*archive)->FUN_1403a9490().c_str(), 0) != 0) continue;
        std::string base(static_cast<const char*>(directory));
        if (*base.rbegin() != '/') base += '/';
        std::string relative = base.substr((*archive)->FUN_1403a9490().length() + 1, base.length());
        auto& index = (*archive)->FUN_1403a93e0().FUN_1403a9580();
        for (Unk_FileArchiveIndex::Entries::const_iterator it = index.begin(); it != index.end(); ++it) {
            if (it->first.find(relative, 0) != 0) continue;
            if (!exclude.IsEmpty() && it->first.find(static_cast<const char*>(exclude), 0) != std::string::npos) continue;
            if (all || it->first.find(filter, 0) != std::string::npos) {
                std::string path = (*archive)->FUN_1403a9490() + '/';
                path.append(it->first.c_str());
                Unk_FileAppend(output, CString(path.c_str()));
            }
        }
    }
}
// MS2-FUNCTIONAL: typed archive index and output adapter preserve lowercase mutations and substring filters.
// @0x14039d530
void CFileSystem::FUN_14039d530(CString& pattern, CString& directory, ATL::CAtlArray<CString>& output, CString& exclude) {
    Unk_EnumerateArchive(this, pattern, directory, output, exclude);
}
MS2_REPLACE_METHOD(0x14039d530, CFileSystem, FUN_14039d530, 1206, 0xD4F4CA12);
// MS2-FUNCTIONAL: same reviewed archive traversal, with the original vector output overload.
// @0x14039d9f0
void CFileSystem::FUN_14039d9f0(CString& pattern, CString& directory, std::vector<CString>& output, CString& exclude) {
    Unk_EnumerateArchive(this, pattern, directory, output, exclude);
}
MS2_REPLACE_METHOD(0x14039d9f0, CFileSystem, FUN_14039d9f0, 1206, 0xAD14E902);
// MS2-FUNCTIONAL: two-pass local enumeration retains ignore checks, recursion and ATL append semantics.
// @0x14039deb0
void CFileSystem::FUN_14039deb0(const CString& pattern, const CString& directory,
                               ATL::CAtlArray<CString>& output, const CString& exclude) {
    Unk_EnumerateLocal(this, pattern, directory, output, exclude);
}
MS2_REPLACE_METHOD(0x14039deb0, CFileSystem, FUN_14039deb0, 1438, 0x7F7BA977);
// MS2-FUNCTIONAL: same reviewed two-pass enumeration with vector move insertion.
// @0x14039e460
void CFileSystem::FUN_14039e460(const CString& pattern, const CString& directory,
                               std::vector<CString>& output, const CString& exclude) {
    Unk_EnumerateLocal(this, pattern, directory, output, exclude);
}
MS2_REPLACE_METHOD(0x14039e460, CFileSystem, FUN_14039e460, 1438, 0x3837465B);
// MS2-FUNCTIONAL: keeps files-before-subdirectories search, lowercase comparison and handle closure on early success.
// @0x14039ea10
CString CFileSystem::FUN_14039ea10(const CString& filename, CString directory) {
    CString base(directory);
    WIN32_FIND_DATAA entry;
    BOOL more = TRUE;
    HANDLE search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                CString name(entry.cFileName);
                name.MakeLower();
                if (filename == name) {
                    base = Unk_FileConcat(directory, name);
                    base.MakeLower();
                    FindClose(search);
                    return base;
                }
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
    more = TRUE;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[8], dir[272], name[256], ext[272];
            _splitpath(base, drive, dir, name, ext);
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0 && entry.cFileName[0] != '.') {
                directory.Format("%s%s%s/", drive, dir, entry.cFileName);
                CString found = FUN_14039ea10(filename, directory);
                if (!found.IsEmpty()) { FindClose(search); return found; }
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
    return CString();
}
MS2_REPLACE_METHOD(0x14039ea10, CFileSystem, FUN_14039ea10, 1076, 0xC61C1C55);
// MS2-FUNCTIONAL: typed texture maps retain first insertion on duplicate filenames and three directory priorities.
// @0x14039ee50
void CFileSystem::FUN_14039ee50() {
    std::list<std::string> textures;
    for (auto archive = archives.begin(); archive != archives.end(); ++archive) (*archive)->FUN_1406b1830(textures);
    std::string effect = effectDirectory + "textures/";
    std::string map = mapDirectory + "textures/";
    std::string model = modelDirectory + "textures/";
    for (auto it = textures.begin(); it != textures.end(); ++it) {
        int kind;
        if (FUN_1403ab490(*it, effect)) kind = 0;
        else if (FUN_1403ab490(*it, map)) kind = 1;
        else if (FUN_1403ab490(*it, model)) kind = 2;
        else continue;
        size_t slash = it->find_last_of('/');
        if (slash != std::string::npos) {
            std::string filename = it->substr(slash + 1, it->length());
            texturePaths[kind].insert(std::make_pair(filename, *it));
        }
    }
}
MS2_REPLACE_METHOD(0x14039ee50, CFileSystem, FUN_14039ee50, 1356, 0xF7DDEAC5);
// @0x14039f3b0
bool CFileSystem::FUN_14039f3b0(CString path) {
    std::string resolved = FUN_14039c050(std::string(static_cast<const char*>(path)), false);
    return resolved.find("./config") == 0;
}
MS2_REPLACE_METHOD(0x14039f3b0, CFileSystem, FUN_14039f3b0, 218, 0xB960F3ED);
// MS2-FUNCTIONAL: retains 64-bit size outputs, patch-before-base search and early-return warning behavior.
// @0x14039f4b0
int CFileSystem::FUN_14039f4b0(const char* path, void** data, unsigned __int64* size, bool warn) {
    if (path != nullptr && data != nullptr && size != nullptr) {
        std::string normalized(static_cast<const char*>(FUN_140188f50(path, 0)));
        if (normalized.empty()) return 0;
        std::string resolved = FUN_14039c050(normalized, true);
        if (resolved.empty()) return 0;
        if (FUN_140398640(resolved, true)) return 0;
        bool stringResource = resolved.find(stringDirectory) != std::string::npos;
        for (auto it = patchArchives.begin(); it != patchArchives.end(); ++it) {
            if (FUN_1403ab490(resolved, (*it)->FUN_1403a9490())) {
                std::string relative = resolved.substr((*it)->FUN_1403a9490().length() + 1, resolved.length());
                if ((*it)->FUN_1406b0e20(relative, data, size, stringResource) != 0) return 1;
            }
        }
        for (auto it = archives.begin(); it != archives.end(); ++it) {
            if (FUN_1403ab490(resolved, (*it)->FUN_1403a9490())) {
                std::string relative = resolved.substr((*it)->FUN_1403a9490().length() + 1, resolved.length());
                if ((*it)->FUN_1406b0e20(relative, data, size, stringResource) != 0) return 1;
            }
        }
    }
    if (warn) Unk_FileLog(FUN_140166440(), 1, 0x13, L"파일을 읽을 수 없습니다 [{0}]", CString(path ? path : ""));
    return 0;
}
MS2_REPLACE_METHOD(0x14039f4b0, CFileSystem, FUN_14039f4b0, 1584, 0x28E9772F);
// MS2-FUNCTIONAL: preserves the alternate local checks in packed mode and original-only check in unpacked mode.
// @0x14039faf0
int CFileSystem::FUN_14039faf0(std::string path) {
    if (FUN_140398190() && !FUN_14039f3b0(CString(path.c_str()))) {
        std::string resolved = FUN_14039c050(path, true);
        if (resolved.empty()) return 0;
        if (FUN_14039bf70()) {
            bool stringResource = resolved.find(stringDirectory) != std::string::npos;
            std::string alternate;
            size_t slash = resolved.find_last_of('/');
            if (slash == std::string::npos) {
                if (stringResource) alternate.assign(DAT_143ab0568);
                else alternate.assign(DAT_143ab0588);
                alternate += resolved;
            } else {
                if (stringResource) alternate = resolved.substr(0, slash + 1) + DAT_143ab0568;
                else alternate = resolved.substr(0, slash + 1) + DAT_143ab0588;
                alternate += resolved.substr(slash + 1, resolved.length());
            }
            HANDLE file = CreateFileA(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
            if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
            file = CreateFileA(resolved.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
            if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
        }
        for (auto it = archives.begin(); it != archives.end(); ++it) {
            if (FUN_1403ab490(resolved, (*it)->FUN_1403a9490())) {
                std::string relative = resolved.substr((*it)->FUN_1403a9490().length() + 1, resolved.length());
                if ((*it)->FUN_1406b1460(relative) != 0) return 1;
            }
        }
        return 0;
    }
    if (FUN_140398640(path, true)) return 0;
    HANDLE file = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
    if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
    return 0;
}
MS2_REPLACE_METHOD(0x14039faf0, CFileSystem, FUN_14039faf0, 2087, 0x34D09E8B);
// MS2-FUNCTIONAL: real ATL file API retains alternate-path reporting, zero-size failure and failed-read cleanup.
// @0x1403a0320
int CFileSystem::FUN_1403a0320(const char* path, void** data, unsigned __int64* size, std::string* actualPath) {
    std::string normalized(static_cast<const char*>(FUN_140188f50(path, 0)));
    if (FUN_140398640(normalized, true)) return 0;
    ATL::CAtlFile file;
    std::string alternate = FUN_14039b810(normalized);
    HRESULT opened = file.Create(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ,
                                 OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr, nullptr);
    if (FAILED(opened)) {
        opened = file.Create(normalized.c_str(), GENERIC_READ, FILE_SHARE_READ,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr, nullptr);
        if (FAILED(opened)) return 0;
    } else if (actualPath != nullptr) actualPath->assign(alternate);
    *size = 0;
    file.GetSize(*size);
    if (*size == 0) return 0;
    *data = EE_MALLOC(*size);
    if (FAILED(file.Read(*data, static_cast<DWORD>(*size)))) {
        *size = 0;
        EE_FREE(*data);
        *data = nullptr;
        file.Close();
        return 0;
    }
    file.Close();
    return 1;
}
MS2_REPLACE_METHOD(0x1403a0320, CFileSystem, FUN_1403a0320, 966, 0xB14478D0);

// @0x1403a9410
Unk_FileIgnoreList* FUN_1403a9410() { return DAT_143aaecb0; }
// @0x1403ab490
bool CFileSystem::FUN_1403ab490(const std::string& path, const std::string& prefix) {
    if (path.length() >= prefix.length())
    {
        return path.compare(0, prefix.length(), prefix, 0, prefix.length()) == 0;
    }
    return false;
}

// @0x1403a93e0
Unk_FileArchiveIndex& Unk_FileArchive::FUN_1403a93e0() { return index; }
// @0x1403a9480
__time64_t FUN_1403a9480(CFileBuffer* buffer) { return buffer->m_tLastAccess; }
// @0x1403a9490
const std::string& Unk_FileArchive::FUN_1403a9490() { return path; }
// @0x1403a9580
Unk_FileArchiveIndex::Entries& Unk_FileArchiveIndex::FUN_1403a9580() { return entries; }
// @0x1403ab1a0
void FUN_1403ab1a0(CFileBuffer* buffer, __time64_t time) { buffer->m_tLastAccess = time; }















