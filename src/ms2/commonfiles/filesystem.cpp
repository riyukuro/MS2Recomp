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
// MS2-PIN: ??0?$MS2Ptr@VCFileBuffer@@@@QEAA@XZ 0x1403a5980 ; unique
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
// MS2-PIN: ?IsNull@?$MS2Ptr@VCFileBuffer@@@@QEBA_NXZ 0x1403a7710 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1403a7890 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UUnk_FileArchiveEntry@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1403a7a20 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VCFileBuffer@@@@QEBAPEAVCFileBuffer@@XZ 0x1403a7b10 ; unique
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
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCFileBuffer@@@@V?$CStringElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCFileBuffer@@@@@2@@ATL@@QEAAPEAU__POSITION@@PEBDAEBV?$MS2Ptr@VCFileBuffer@@@@@Z 0x1403ab020 ; unique
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
// MS2-PIN: ?FUN_1406af680@Unk_FileArchive@@QEAAHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEBD@Z 0x1406af680
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\filesystem.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#pragma intrinsic(memset, memcpy)
#include "filesystem.h"
#include "ms2/commonfiles/ms2filestring.h"   // C3: CPackFile
#include "ms2/placeholder/cignorefile.h"     // C3: CIgnoreFile::IsIgnored
#include <algorithm>
#include <ctime>
#include <list>
#include <unordered_set>
#include <atlfile.h>
#include <efd/MemoryDefines.h>
#include "logstring.h"
#define NDEBUG
#include <assert.h>
#include "cryptopp562/aes.h"
#include "cryptopp562/modes.h"
#include "cryptopp562/base64.h"
#undef NDEBUG
#include <assert.h>
#include "ms2/placeholder/ms2ptr_impl.h"   // C3: MS2Ptr<CFileBuffer> COMDATs (BufferPtr)
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void InitCipherKeyTables();
void FreeCipherKeyTables();
void ToLower(CString& path);
CString FUN_140188f50(const char*, int);
CString ToCString(const char*, int);
CLogString* GetLogString();
inline CString Unk_FileConcat(const CString& left, const char* right) { return left + right; }
inline CString Unk_FileConcat(const CString& left, const CString& right) { return left + right; }

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
#include "ms2/placeholder/clockcriticalsection.h"   // Unk_CriticalSectionLock (was a local lock view)
//
//
//
//
//
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
extern std::string g_strLocaleDir2, g_strLocaleDir;
extern int g_nLocaleMode;
class Unk_FileIgnoreList;
Unk_FileIgnoreList* GetIgnoreFile();
__time64_t GetLastAccessTime(CFileBuffer*);
void SetLastAccessTime(CFileBuffer*, __time64_t);

MS2_EMIT_CRT_MEMMOVE_S();
// @0x140396260
double GetTimeDifference(__time64_t first, __time64_t second) { return _difftime64(first, second); }
// @0x140396290
__time64_t FUN_140396290(__time64_t* result) { return _time64(result); }

// @0x1403962b0
CFileSystem::CFileSystem() : cache(10), packed(false), alternatePaths(false), mode(0),
    effectDirectory("./data/resource/model/effect/"), mapDirectory("./data/resource/model/map/"),
    modelDirectory("./data/resource/model/"), stringDirectory("./data/xml/string/") {
    archiveMode = 0;
    characterMask = 0;
    InitCipherKeyTables();
}
// @0x140396460
CFileSystem::~CFileSystem() {
    for (auto it = archives.begin(); it != archives.end(); ++it) {
        reinterpret_cast<CPackFile*>((*it))->Close();
        delete reinterpret_cast<CPackFile*>(*it);
    }
    archives.clear();
    for (auto it = patchArchives.begin(); it != patchArchives.end(); ++it) {
        reinterpret_cast<CPackFile*>((*it))->Close();
        delete reinterpret_cast<CPackFile*>(*it);
    }
    patchArchives.clear();
    FreeCipherKeyTables();
}
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
        while (fgets(line, 2048, file) != nullptr) {
            std::string text(line);
            lines.push_back(static_cast<std::string&&>(text));
        }
        fclose(file);
        if (!lines.empty()) {
            lines.sort();
            archives.reserve(lines.size());
            std::string path;
            for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
                path.assign(*it);
                if (!path.empty()) {
                    if (*path.rbegin() == '\r' || *path.rbegin() == '\n') path = path.substr(0, path.length() - 1);
                    Unk_FileArchive* archive = reinterpret_cast<Unk_FileArchive*>(new CPackFile);
                    reinterpret_cast<CPackFile*>(archive)->SetDecode(Unk_FileTransform(this, &CFileSystem::DecryptByMagic));
                    reinterpret_cast<CPackFile*>(archive)->SetDecodeShort(Unk_FileTransform(this, &CFileSystem::FUN_14039b470));
                    if (reinterpret_cast<CPackFile*>(archive)->Open(path, nullptr) == 0) {
                        delete reinterpret_cast<CPackFile*>(archive);
                        continue;
                    }
                    archives.push_back(archive);
                }
            }
        }
        FUN_14039ee50();
    }
    return 1;
}
#endif
// Not hooked: callback construction creates DLL-local ClassFunHandler RTTI.
#ifndef MS2_HOOK_DLL
// @0x140396d00
int CFileSystem::ReloadPatchArchives(const char* directory) {
    if (!FUN_140398190()) return 0;
    for (auto it = patchArchives.begin(); it != patchArchives.end(); ++it) {
        reinterpret_cast<CPackFile*>((*it))->Close();
        delete reinterpret_cast<CPackFile*>(*it);
    }
    patchArchives.clear();
    ClearCache();
    std::string config(directory);
    config += "/";
    config += "PackDiffClient.ini";
    std::transform(config.begin(), config.end(), config.begin(), ::tolower);
    FILE* file = fopen(config.c_str(), "r");
    if (file != nullptr) {
        std::list<std::string> lines;
        char line[2048];
        while (fgets(line, 2048, file) != nullptr) {
            std::string text(line);
            lines.push_back(static_cast<std::string&&>(text));
        }
        fclose(file);
        if (!lines.empty()) {
            lines.sort();
            patchArchives.reserve(lines.size());
            std::string path;
            for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
                path = *it;
                if (!path.empty()) {
                    if (*path.rbegin() == '\r' || *path.rbegin() == '\n') path = path.substr(0, path.length() - 1);
                    Unk_FileArchive* archive = reinterpret_cast<Unk_FileArchive*>(new CPackFile);
                    reinterpret_cast<CPackFile*>(archive)->SetDecode(Unk_FileTransform(this, &CFileSystem::DecryptByMagic));
                    reinterpret_cast<CPackFile*>(archive)->SetDecodeShort(Unk_FileTransform(this, &CFileSystem::FUN_14039b470));
                    if (reinterpret_cast<CPackFile*>(archive)->Open(path, directory) == 0) {
                        delete reinterpret_cast<CPackFile*>(archive);
                        continue;
                    }
                    patchArchives.push_back(archive);
                }
            }
        }
    }
    return 1;
}
#endif
// @0x1403972f0
int CFileSystem::LoadFileData(const char* path, void** data, unsigned __int64* size, std::string* actualPath) {
    if (path != nullptr && data != nullptr && size != nullptr) {
        if (actualPath != nullptr) *actualPath = static_cast<const char*>(FUN_140188f50(path, 0));
        if (FUN_14039bf70() && FUN_1403a0320(path, data, size, actualPath) == 1) return 1;
        if (FUN_140398190() && !IsConfigPath(CString(path))) return FUN_14039f4b0(path, data, size, true);
        return FUN_1403a0320(path, data, size, actualPath);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1403972f0, CFileSystem, LoadFileData, 431, 0x9C7E8407);
// @0x1403974b0
int CFileSystem::LoadXmlFile(TiXmlDocument* document, const char* path, int encoding, bool warn, bool localOnly) {
    if (FUN_140398190() && !IsConfigPath(CString(path))) {
        unsigned loaded = 0;
        if (FUN_14039bf70()) {
            loaded = document->LoadFile(ToCString(path, 0), static_cast<TiXmlEncoding>(encoding));
            if (loaded == 0) {
                std::string alternate = GetLocalePath(std::string(path));
                loaded = document->LoadFile(ToCString(alternate.c_str(), 0), static_cast<TiXmlEncoding>(encoding));
            }
        }
        if (loaded == 0 && !localOnly) {
            void* data;
            unsigned __int64 size;
            if (FUN_14039f4b0(path, &data, &size, warn) != 0) {
                if (!document->LoadMemory(static_cast<const char*>(data), static_cast<unsigned>(size), static_cast<TiXmlEncoding>(encoding))) {
                    EE_FREE(data);
                    return 0;
                }
                EE_FREE(data);
            } else {
                return 0;
            }
        }
    } else {
        if (FUN_140398640(std::string(path), true)) return 0;
        std::string alternate = GetLocalePath(std::string(path));
        if (!document->LoadFile(ToCString(alternate.c_str(), 0), static_cast<TiXmlEncoding>(encoding))) {
            if (!document->LoadFile(ToCString(path, 0), static_cast<TiXmlEncoding>(encoding))) {
                if (warn) {
                    CString text(path == nullptr ? "" : path);
                    Unk_FileLog(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다 [{0}]", text);
                }
                return 0;
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1403974b0, CFileSystem, LoadXmlFile, 1311, 0x73EE0E90);
// @0x1403979e0
int CFileSystem::LoadXmlFromBuffer(TiXmlDocument* document, BufferPtr buffer) {
    if (buffer.IsNull()) return 0;
    if (!document->LoadMemory(static_cast<const char*>(buffer->GetBuffer()), buffer->GetSize(), TIXML_ENCODING_UNKNOWN)) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1403979e0, CFileSystem, LoadXmlFromBuffer, 190, 0xB229CEED);
// @0x140397ab0
int CFileSystem::LoadXmlFromString(TiXmlDocument* document, const CStringW& xml) {
    BufferPtr buffer(new CFileBuffer);
    if (buffer == nullptr) return 0;
    buffer->SetText(xml);
    return LoadXmlFromBuffer(document, buffer);
}
// MS2-FUNCTIONAL: typed cache lookup retains both locked checks, timestamp updates and hit counters.
// Not hooked: loader branches construct CFileBuffer objects with DLL-local RTTI.
#ifndef MS2_HOOK_DLL
// @0x140397bc0
CFileSystem::BufferPtr CFileSystem::GetFileBuffer(const char* path, int cacheMode, int flag) {
    __time64_t now;
    FUN_140396290(&now);
    BufferPtr buffer;
    {
        Unk_CriticalSectionLock guard(cacheLock, 1);
        if (cache.Lookup(path, buffer)) {
            SetLastAccessTime(buffer.operator->(), now);
            ++buffer->m_field34;
        }
    }
    if (buffer.get() != nullptr) return buffer;
    std::string normalized(static_cast<const char*>(FUN_140188f50(path, 0)));
    if (normalized.empty()) return BufferPtr(0);
    if (FUN_140398190() && !IsConfigPath(CString(path))) {
        if (FUN_14039bf70()) buffer = FUN_14039c810(normalized, flag);
        if (buffer == nullptr) buffer = FUN_14039cc50(normalized, flag);
    } else buffer = FUN_14039c810(normalized, flag);
    if (buffer == nullptr) cacheMode = 0;
    if (buffer.get() != nullptr) {
        buffer->m_field38 = flag;
        SetLastAccessTime(buffer.operator->(), now);
    }
    if (cacheMode != 0 && (buffer.get() ? true : false)) {
        Unk_CriticalSectionLock guard(cacheLock, 1);
        BufferPtr existing(0);
        if (cache.Lookup(path, existing)) {
            buffer = existing;
            ++buffer->m_field34;
            SetLastAccessTime(buffer.operator->(), now);
        }
        else cache.SetAt(path, buffer);
    }
    return buffer;
}
#endif
// @0x140398190
bool CFileSystem::FUN_140398190() { return packed; }
MS2_REPLACE_METHOD(0x140398190, CFileSystem, FUN_140398190, 15, 0x3367C6B5);
// @0x1403981b0
bool CFileSystem::HasAlternatePaths() { return alternatePaths; }
MS2_REPLACE_METHOD(0x1403981b0, CFileSystem, HasAlternatePaths, 15, 0x5368A4AC);
// @0x1403981d0
bool CFileSystem::FUN_1403981d0() { return mode ? true : false; }
MS2_REPLACE_METHOD(0x1403981d0, CFileSystem, FUN_1403981d0, 39, 0x6C197E5C);
// @0x140398200
bool CFileSystem::DirectoryExists(std::string path) {
    if (FUN_140398190() && !IsConfigPath(CString(path.c_str()))) {
        std::string resolved = NormalizePath(path, false);
        if (resolved.empty()) return false;
        if (resolved == "./") return true;
        for (Unk_FileArchive* const& archive : archives) {
            if (HasPathPrefix(resolved, archive->GetPath())) {
                if (resolved.length() == archive->GetPath().length()) return true;
                std::string relative = resolved.substr(archive->GetPath().length() + 1, resolved.length());
                if (reinterpret_cast<CPackFile*>(archive)->Contains(relative) != 0) return true;
            }
        }
    } else {
        if (FUN_140398640(path, false)) return false;
        DWORD attributes = GetFileAttributesA(path.c_str());
        if (attributes == INVALID_FILE_ATTRIBUTES) return false;
        return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140398200, CFileSystem, DirectoryExists, 1076, 0x9A6476C0);
// @0x140398640
bool CFileSystem::FUN_140398640(std::string path, bool checkFile) {
    if (FUN_1403981d0() && GetIgnoreFile() != nullptr) {
        std::string resolved = NormalizePath(path, checkFile);
        if (resolved.empty()) return true;
        if (reinterpret_cast<CIgnoreFile*>(GetIgnoreFile())->IsIgnored(resolved)) return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140398640, CFileSystem, FUN_140398640, 386, 0x87673FFA);
// @0x1403987d0
int CFileSystem::FileExists(std::string path) {
    if (FUN_140398190() && !IsConfigPath(CString(path.c_str()))) {
        std::string resolved = NormalizePath(path, true);
        if (resolved.empty()) return 0;
        bool stringResource = resolved.find(stringDirectory) != std::string::npos;
        if (FUN_14039bf70()) {
            HANDLE file = nullptr;
            std::string alternate;
            size_t slash = resolved.find_last_of('/');
            if (slash != std::string::npos) {
                if (stringResource) alternate = resolved.substr(0, slash + 1) + g_strLocaleDir2;
                else alternate = resolved.substr(0, slash + 1) + g_strLocaleDir;
                alternate += resolved.substr(slash + 1, resolved.length());
                file = CreateFileA(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
                if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
            } else {
                if (stringResource) alternate.assign(g_strLocaleDir2);
                else alternate.assign(g_strLocaleDir);
                alternate += resolved;
                file = CreateFileA(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
                if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
            }
            file = CreateFileA(resolved.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
            if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
        }
        for (auto it = archives.begin(); it != archives.end(); ++it) {
            if (HasPathPrefix(resolved, (*it)->GetPath())) {
                std::string relative = resolved.substr((*it)->GetPath().length() + 1, resolved.length());
                if (reinterpret_cast<CPackFile*>((*it))->IsPacked(relative, stringResource) != 0) return 1;
            }
        }
    } else {
        if (FUN_140398640(path, true)) return 0;
        std::string alternate = GetLocalePath(path);
        HANDLE file = CreateFileA(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
        if (file != INVALID_HANDLE_VALUE) {
            CloseHandle(file);
            return 1;
        } else {
            file = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
            if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1403987d0, CFileSystem, FileExists, 2332, 0xDC492B22);

// @0x140399100
void FindFiles(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude, bool localOnly) {
    std::vector<CString> paths;
    FUN_1403992a0(pattern, directory, paths, exclude, localOnly);
    for (const CString& path : paths) output.Add(path);
}
MS2_REPLACE(0x140399100, FindFiles, 403, 0xA8E81207);
// @0x1403992a0
void FUN_1403992a0(CString pattern, CString directory, std::vector<CString>& output, CString exclude, bool localOnly) {
    if (!directory.IsEmpty()) {
        CString last = directory.Right(1);
        if (last != "/" && last != "*") directory += "/";
    }
    if (GetFileSystem()->FUN_140398190() && !GetFileSystem()->IsConfigPath(CString(static_cast<const char*>(directory)))) {
        if (pattern.Find(".xml", 0) != -1) {
            std::vector<CString> archived, local;
            GetFileSystem()->FUN_14039e460(pattern, directory, local, exclude);
            if (!localOnly) GetFileSystem()->FUN_14039d9f0(pattern, directory, archived, exclude);
            std::unordered_set<std::string> unique;
            auto append = [&unique](const std::vector<CString>& paths) {
                for (const auto& path : paths) {
                    std::string key(static_cast<const char*>(path));
                    if (unique.find(key) == unique.end()) unique.emplace(key);
                }
            };
            append(local);
            append(archived);
            for (const auto& path : unique) {
                CString value(path.c_str());
                output.push_back(static_cast<CString&&>(value));
            }
        } else {
            if (!localOnly) GetFileSystem()->FUN_14039d9f0(pattern, directory, output, exclude);
        }
    } else GetFileSystem()->FUN_14039e460(pattern, directory, output, exclude);
}
MS2_REPLACE(0x1403992a0, FUN_1403992a0, 877, 0xACD21ED3);
// @0x140399620
void FUN_140399620(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude, bool localOnly) {
    if (GetFileSystem()->FUN_140398190()) {
        FindFiles(pattern, directory, output, exclude, localOnly);
        return;
    }
    BOOL more = TRUE;
    HANDLE search;
    CString base(directory);
    if (directory.IsEmpty()) return;
    WIN32_FIND_DATAA entry;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[_MAX_DRIVE], dir[272], name[256];
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
            char drive[_MAX_DRIVE], dir[272], name[256];
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
// @0x140399de0
void FUN_140399de0(CString pattern, CString directory, std::vector<CString>& output, CString exclude) {
    if (!directory.IsEmpty()) {
        CString last = directory.Right(1);
        if (last != "/" && last != "*") directory += "/";
    }
    BOOL more = TRUE;
    HANDLE search;
    CString base(directory);
    WIN32_FIND_DATAA entry;
    more = TRUE;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[_MAX_DRIVE], dir[272], name[256];
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
                        ToLower(result);
                        output.push_back(result);
                    }
                }
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
}
MS2_REPLACE(0x140399de0, FUN_140399de0, 889, 0xE5DDE326);
// @0x14039a160
bool CFileSystem::FindTexturePath(const char* directory, const char* reference, char* result, unsigned capacity) {
    if (FUN_140398190()) {
        std::string resolved = NormalizePath(std::string(directory), false);
        std::string name(reference);
        TrimSpaces(name);
        if (name[0] == '.') {
            size_t slash = name.find_first_of('/');
            if (slash != std::string::npos) name = name.substr(slash + 1, name.length());
        }
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        std::string candidate = resolved + name;
        if (FileExists(candidate) != 0) {
            if (candidate.length() < capacity) {
                wsprintfA(result, "%s", candidate.c_str());
                return true;
            } else {
                throw 13;
            }
        } else {
            int kind = 3;
            if (HasPathPrefix(resolved, effectDirectory)) kind = 0;
            else if (HasPathPrefix(resolved, mapDirectory)) kind = 1;
            else kind = 2;
            auto found = texturePaths[kind].find(name);
            if (found != texturePaths[kind].end()) {
                const std::string& path = found->second;
                if (!path.empty()) {
                    if (path.length() < capacity) {
                        wsprintfA(result, "%s", path.c_str());
                        return true;
                    } else {
                        throw 13;
                    }
                }
            }
        }
    }
    Unk_FileLog(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}] referencePath : {1}", reference, directory);
    return false;
}
MS2_REPLACE_METHOD(0x14039a160, CFileSystem, FindTexturePath, 1230, 0x093E08A9);
// @0x14039a640
void CFileSystem::FUN_14039a640() { packed = false; }
MS2_REPLACE_METHOD(0x14039a640, CFileSystem, FUN_14039a640, 15, 0xCAF8FB9C);
// @0x14039a660
void CFileSystem::MarkCharacterModelLoaded(CString path, void*) {
    Unk_CriticalSectionLock guard(characterLock, 1);
    if (path == "./data/resource/model/character/female/female.xml") characterMask |= 2;
    else if (path == "./data/resource/model/character/male/male.xml") characterMask |= 1;
}
MS2_REPLACE_METHOD(0x14039a660, CFileSystem, MarkCharacterModelLoaded, 185, 0x96106327);
// @0x14039a720
unsigned CFileSystem::GetCharacterMask() { return characterMask; }
MS2_REPLACE_METHOD(0x14039a720, CFileSystem, GetCharacterMask, 17, 0x650AC462);
// @0x14039a740
void CFileSystem::ResetCharacterMask() {
    Unk_CriticalSectionLock guard(characterLock, 1);
    characterMask = 0;
}
MS2_REPLACE_METHOD(0x14039a740, CFileSystem, ResetCharacterMask, 69, 0x60D6BBDC);
// @0x14039a790
unsigned long CFileSystem::DecryptByMagic(unsigned long magic, unsigned char* data, unsigned long size,
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
    } catch (CryptoPP::Exception&) {
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
    } catch (CryptoPP::Exception&) {
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
    } catch (CryptoPP::Exception&) {
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
    } catch (CryptoPP::Exception&) {
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
void CFileSystem::ClearCache() {
    Unk_CriticalSectionLock guard(cacheLock, 1);
    cache.RemoveAll();
}
MS2_REPLACE_METHOD(0x14039b660, CFileSystem, ClearCache, 69, 0x68A6E2C2);
// @0x14039b6b0
void CFileSystem::PurgeExpiredCache() {
    if (cache.GetCount() == 0) return;
    __time64_t now;
    FUN_140396290(&now);
    Unk_CriticalSectionLock guard(cacheLock, 1);
    POSITION position = cache.GetHeadPosition();
    while (position != nullptr) {
        POSITION current = position;
        cache.GetNext(position);
        const BufferPtr& buffer = cache.GetValueAt(current);
        double age = GetTimeDifference(now, GetLastAccessTime(buffer.operator->()));
        if (age >= DAT_1439f4830) cache.RemoveAt(current);
    }
}
MS2_REPLACE_METHOD(0x14039b6b0, CFileSystem, PurgeExpiredCache, 272, 0x26CFCE3D);
// @0x14039b7d0
void CFileSystem::SetUseAlternatePaths(int enabled) { alternatePaths = enabled ? true : false; }
MS2_REPLACE_METHOD(0x14039b7d0, CFileSystem, SetUseAlternatePaths, 47, 0x717FD09C);
// @0x14039b810
std::string CFileSystem::GetLocalePath(std::string path) {
    path = NormalizePath(path, true);
    bool stringResource = path.find(stringDirectory) != std::string::npos;
    std::string result;
    size_t slash = path.find_last_of('/');
    if (slash != std::string::npos) {
        if (stringResource) result = path.substr(0, slash + 1) + g_strLocaleDir2;
        else result = path.substr(0, slash + 1) + g_strLocaleDir;
        result += path.substr(slash + 1, path.length());
    } else {
        if (stringResource) result.assign(g_strLocaleDir2);
        else result.assign(g_strLocaleDir);
        result += path;
    }
    return result;
}
MS2_REPLACE_METHOD(0x14039b810, CFileSystem, GetLocalePath, 813, 0x0D22C404);
// @0x14039bb50
std::string CFileSystem::FUN_14039bb50(std::string path) {
    if (g_nLocaleMode != 2) return std::string("");
    path = NormalizePath(path, true);
    std::string result;
    size_t slash = path.find_last_of('/');
    if (slash != std::string::npos) {
        result = path.substr(0, slash + 1) + g_strLocaleDir;
        std::string language(g_strLocaleDir2);
        std::transform(language.begin(), language.end(), language.begin(), ::tolower);
        result.append(language);
        result.append("/");
        result += path.substr(slash + 1, path.length());
    } else {
        result.assign(g_strLocaleDir);
        std::string language(g_strLocaleDir2);
        std::transform(language.begin(), language.end(), language.begin(), ::tolower);
        result.append(language);
        result.append("/");
        result += path;
    }
    return result;
}
MS2_REPLACE_METHOD(0x14039bb50, CFileSystem, FUN_14039bb50, 1047, 0xEF6B46BF);
// @0x14039bf70
bool CFileSystem::FUN_14039bf70() { return true; }
MS2_REPLACE_METHOD(0x14039bf70, CFileSystem, FUN_14039bf70, 8, 0x71679366);
// @0x14039bf80
void CFileSystem::TrimSpaces(std::string& path) {
    size_t pos = path.find_last_not_of(' ');
    if (pos != std::string::npos) {
        path.erase(pos + 1);
        pos = path.find_first_not_of(' ');
        if (pos != std::string::npos) path.erase(0, pos);
    } else {
        path.erase(path.begin(), path.end());
    }
}
MS2_REPLACE_METHOD(0x14039bf80, CFileSystem, TrimSpaces, 190, 0xA7F44878);
// @0x14039c050
std::string CFileSystem::NormalizePath(std::string path, bool checkFile) {
    std::string result;
    if (checkFile) {
        char extension[256] = {};
        _splitpath(path.c_str(), nullptr, nullptr, nullptr, extension);
        if (extension[0] == '\0') return result;
    }
    TrimSpaces(path);
    if (!path.empty()) {
        std::transform(path.begin(), path.end(), path.begin(), ::tolower);
        for (auto it = path.begin(); it != path.end(); ++it) if (*it == '\\') *it = '/';
        size_t slash = path.find("/../");
        if (slash != std::string::npos) {
            result.assign(path);
            std::list<std::string> components;
            do {
                slash = result.find_last_of('/');
                if (slash != std::string::npos) {
                    components.push_back(result.substr(slash, result.length()));
                    result = result.substr(0, slash);
                } else {
                    components.push_back(result);
                    break;
                }
            } while (true);
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
                if (parents != 0) continue;
                ++it;
            }
            path.clear();
            for (auto it = components.rbegin(); it != components.rend(); ++it) {
                if (*it == "/.") continue;
                path += *it;
            }
            if (*path.begin() == '/') path = '.' + path;
        }
        if (*path.begin() != '.') {
            result = "./";
            if (path.find(workingDirectory) != std::string::npos) {
                if (path == workingDirectory) return result;
                result += path.substr(workingDirectory.length() + 1, path.length());
            } else {
                result += path;
            }
        } else {
            return path;
        }
    }
    return result;
}
MS2_REPLACE_METHOD(0x14039c050, CFileSystem, NormalizePath, 1968, 0xE34581C1);
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
        std::string prefixed = GetLocalePath(path);
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
    file.Read(buffer->m_pBuffer, buffer->GetSize());
    buffer->m_field38 = flag;
    file.Close();
    return buffer;
}
#endif
// Not hooked: constructs a CFileBuffer with DLL-local RTTI.
#ifndef MS2_HOOK_DLL
// @0x14039cc50
CFileSystem::BufferPtr CFileSystem::FUN_14039cc50(std::string path, int flag) {
    void* data = nullptr;
    unsigned __int64 size = 0;
    int found = 0;
    std::string resolved = NormalizePath(path, true);
    if (!resolved.empty()) {
        bool stringResource = resolved.find(stringDirectory) != std::string::npos;
        BufferPtr patched = FUN_14039d190(resolved, path, flag);
        if (patched.get() != nullptr) return patched;
        for (auto it = archives.begin(); it != archives.end(); ++it) {
            if (HasPathPrefix(resolved, (*it)->GetPath())) {
                std::string relative = resolved.substr((*it)->GetPath().length() + 1, resolved.length());
                found = reinterpret_cast<CPackFile*>((*it))->Read(relative, (unsigned char**)&data, &size, stringResource);
                if (found != 0) break;
            }
        }
        if (found != 0) {
            BufferPtr buffer(new CFileBuffer);
            buffer->Adopt(data, static_cast<unsigned>(size));
            buffer->m_field38 = flag;
            return buffer;
        }
    }
    Unk_FileFailure failure(this, resolved);
    if (failure()) {
        const char* text = resolved.c_str();
        Unk_FileLog(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다 [{0}]", text);
    }
    return BufferPtr(0);
}
#endif
// Not hooked: constructs a CFileBuffer with DLL-local RTTI.
#ifndef MS2_HOOK_DLL
// @0x14039d190
CFileSystem::BufferPtr CFileSystem::FUN_14039d190(std::string resolved, std::string original, int flag) {
    void* data = nullptr;
    unsigned __int64 size = 0;
    int found = 0;
    if (resolved.empty()) return BufferPtr(0);
    bool stringResource = resolved.find(stringDirectory) != std::string::npos;
    for (auto it = patchArchives.begin(); it != patchArchives.end(); ++it) {
        if (HasPathPrefix(resolved, (*it)->GetPath())) {
            std::string relative = resolved.substr((*it)->GetPath().length() + 1, resolved.length());
            found = reinterpret_cast<CPackFile*>((*it))->Read(relative, (unsigned char**)&data, &size, stringResource);
            if (found != 0) break;
        }
    }
    if (found != 0) {
        BufferPtr buffer(new CFileBuffer);
        buffer->Adopt(data, static_cast<unsigned>(size));
        buffer->m_field38 = flag;
        return buffer;
    }
    return BufferPtr(0);
}
#endif
// @0x14039d530
void CFileSystem::FUN_14039d530(CString& pattern, CString& directory, ATL::CAtlArray<CString>& output, CString& exclude) {
    ToLower(pattern);
    ToLower(directory);
    ToLower(exclude);
    int all = pattern == "*.*";
    std::string filter(static_cast<const char*>(pattern));
    if (*filter.begin() == '*') filter = filter.substr(1, filter.length());
    for (auto archive = archives.begin(); archive != archives.end(); ++archive) {
        if (directory.Find((*archive)->GetPath().c_str(), 0) == 0) {
            std::string base(static_cast<const char*>(directory));
            if (*base.rbegin() != '/') base += '/';
            std::string relative = base.substr((*archive)->GetPath().length() + 1, base.length());
            const Unk_FileArchiveIndex::Entries& index = (*archive)->GetIndex().GetEntries();
            for (Unk_FileArchiveIndex::Entries::const_iterator it = index.begin(); it != index.end(); ++it) {
                if (it->first.find(relative, 0) == 0) {
                    if (!exclude.IsEmpty() && it->first.find(static_cast<const char*>(exclude), 0) != std::string::npos) continue;
                    if (all) {
                        std::string path = (*archive)->GetPath() + '/';
                        path.append(it->first.c_str());
                        CString text(path.c_str());
                        output.Add(text);
                    } else if (it->first.find(filter, 0) != std::string::npos) {
                        std::string path = (*archive)->GetPath() + '/';
                        path.append(it->first.c_str());
                        CString text(path.c_str());
                        output.Add(text);
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14039d530, CFileSystem, FUN_14039d530, 1206, 0xD4F4CA12);
// @0x14039d9f0
void CFileSystem::FUN_14039d9f0(CString& pattern, CString& directory, std::vector<CString>& output, CString& exclude) {
    ToLower(pattern);
    ToLower(directory);
    ToLower(exclude);
    int all = pattern == "*.*";
    std::string filter(static_cast<const char*>(pattern));
    if (*filter.begin() == '*') filter = filter.substr(1, filter.length());
    for (auto archive = archives.begin(); archive != archives.end(); ++archive) {
        if (directory.Find((*archive)->GetPath().c_str(), 0) == 0) {
            std::string base(static_cast<const char*>(directory));
            if (*base.rbegin() != '/') base += '/';
            std::string relative = base.substr((*archive)->GetPath().length() + 1, base.length());
            const Unk_FileArchiveIndex::Entries& index = (*archive)->GetIndex().GetEntries();
            for (Unk_FileArchiveIndex::Entries::const_iterator it = index.begin(); it != index.end(); ++it) {
                if (it->first.find(relative, 0) == 0) {
                    if (!exclude.IsEmpty() && it->first.find(static_cast<const char*>(exclude), 0) != std::string::npos) continue;
                    if (all) {
                        std::string path = (*archive)->GetPath() + '/';
                        path.append(it->first.c_str());
                        CString text(path.c_str());
                        output.push_back(static_cast<CString&&>(text));
                    } else if (it->first.find(filter, 0) != std::string::npos) {
                        std::string path = (*archive)->GetPath() + '/';
                        path.append(it->first.c_str());
                        CString text(path.c_str());
                        output.push_back(static_cast<CString&&>(text));
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14039d9f0, CFileSystem, FUN_14039d9f0, 1206, 0xAD14E902);
// @0x14039deb0
void CFileSystem::FUN_14039deb0(const CString& pattern, const CString& directory,
                               ATL::CAtlArray<CString>& output, const CString& exclude) {
    BOOL more = TRUE;
    HANDLE search;
    CString base(directory);
    WIN32_FIND_DATAA entry;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[_MAX_DRIVE], dir[272], name[256];
            _splitpath(base, drive, dir, name, nullptr);
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0 && entry.cFileName[0] != '.') {
                char child[272];
                sprintf(child, "%s%s%s/*.*", drive, dir, entry.cFileName);
                std::string childPath(drive);
                childPath.append(dir);
                childPath.append(entry.cFileName);
                if (!FUN_140398640(childPath, false)) FindFiles(pattern, CString(child), output, exclude, false);
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
    more = TRUE;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[_MAX_DRIVE], dir[272], name[256];
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
                    if (!FUN_140398640(path, true) && (exclude.IsEmpty() || result.Find(exclude, 0) == -1)) {
                        ToLower(result);
                        output.Add(result);
                    }
                }
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
}
MS2_REPLACE_METHOD(0x14039deb0, CFileSystem, FUN_14039deb0, 1438, 0x7F7BA977);
// @0x14039e460
void CFileSystem::FUN_14039e460(const CString& pattern, const CString& directory,
                               std::vector<CString>& output, const CString& exclude) {
    BOOL more = TRUE;
    HANDLE search;
    CString base(directory);
    WIN32_FIND_DATAA entry;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[_MAX_DRIVE], dir[272], name[256];
            _splitpath(base, drive, dir, name, nullptr);
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0 && entry.cFileName[0] != '.') {
                char child[272];
                sprintf(child, "%s%s%s/*.*", drive, dir, entry.cFileName);
                std::string childPath(drive);
                childPath.append(dir);
                childPath.append(entry.cFileName);
                if (!FUN_140398640(childPath, false)) FUN_1403992a0(pattern, CString(child), output, exclude, false);
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
    more = TRUE;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[_MAX_DRIVE], dir[272], name[256];
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
                    if (!FUN_140398640(path, true) && (exclude.IsEmpty() || result.Find(exclude, 0) == -1)) {
                        ToLower(result);
                        output.push_back(result);
                    }
                }
            }
            more = FindNextFileA(search, &entry);
        }
        FindClose(search);
    }
}
MS2_REPLACE_METHOD(0x14039e460, CFileSystem, FUN_14039e460, 1438, 0x3837465B);
// @0x14039ea10
CString CFileSystem::FUN_14039ea10(const CString& filename, CString directory) {
    BOOL more = TRUE;
    HANDLE search;
    CString base(directory);
    WIN32_FIND_DATAA entry;
    more = TRUE;
    search = FindFirstFileA(Unk_FileConcat(base, "*.*"), &entry);
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            if ((entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                CString name(entry.cFileName);
                ToLower(name);
                if (filename == name) {
                    base = Unk_FileConcat(directory, name);
                    ToLower(base);
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
            char drive[_MAX_DRIVE], dir[272], name[256], ext[272];
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
// @0x14039ee50
void CFileSystem::FUN_14039ee50() {
    std::list<std::string> textures;
    for (auto archive = archives.begin(); archive != archives.end(); ++archive) reinterpret_cast<CPackFile*>((*archive))->GetTexturePaths(textures);
    std::string effect = effectDirectory + "textures/";
    std::string map = mapDirectory + "textures/";
    std::string model = modelDirectory + "textures/";
    for (auto it = textures.begin(); it != textures.end(); ++it) {
        if (HasPathPrefix(*it, effect)) {
            size_t slash = it->find_last_of('/');
            if (slash != std::string::npos) {
                std::string filename = it->substr(slash + 1, it->length());
                texturePaths[0].insert(std::make_pair(filename, *it));
            }
        } else if (HasPathPrefix(*it, map)) {
            size_t slash = it->find_last_of('/');
            if (slash != std::string::npos) {
                std::string filename = it->substr(slash + 1, it->length());
                texturePaths[1].insert(std::make_pair(filename, *it));
            }
        } else if (HasPathPrefix(*it, model)) {
            size_t slash = it->find_last_of('/');
            if (slash != std::string::npos) {
                std::string filename = it->substr(slash + 1, it->length());
                texturePaths[2].insert(std::make_pair(filename, *it));
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14039ee50, CFileSystem, FUN_14039ee50, 1356, 0xF7DDEAC5);
// @0x14039f3b0
bool CFileSystem::IsConfigPath(CString path) {
    std::string resolved = NormalizePath(std::string(static_cast<const char*>(path)), false);
    return resolved.find("./config") == 0;
}
MS2_REPLACE_METHOD(0x14039f3b0, CFileSystem, IsConfigPath, 218, 0xB960F3ED);
// @0x14039f4b0
int CFileSystem::FUN_14039f4b0(const char* path, void** data, unsigned __int64* size, bool warn) {
    if (path != nullptr && data != nullptr && size != nullptr) {
        std::string normalized(static_cast<const char*>(FUN_140188f50(path, 0)));
        if (normalized.empty()) return 0;
        std::string resolved = NormalizePath(normalized, true);
        if (resolved.empty()) return 0;
        if (FUN_140398640(resolved, true)) return 0;
        bool stringResource = resolved.find(stringDirectory) != std::string::npos;
        for (auto it = patchArchives.begin(); it != patchArchives.end(); ++it) {
            if (HasPathPrefix(resolved, (*it)->GetPath())) {
                std::string relative = resolved.substr((*it)->GetPath().length() + 1, resolved.length());
                if (reinterpret_cast<CPackFile*>((*it))->Read(relative, (unsigned char**)data, size, stringResource) != 0) return 1;
            }
        }
        for (auto it = archives.begin(); it != archives.end(); ++it) {
            if (HasPathPrefix(resolved, (*it)->GetPath())) {
                std::string relative = resolved.substr((*it)->GetPath().length() + 1, resolved.length());
                if (reinterpret_cast<CPackFile*>((*it))->Read(relative, (unsigned char**)data, size, stringResource) != 0) return 1;
            }
        }
    }
    if (warn) {
        CString text(path == nullptr ? "" : path);
        Unk_FileLog(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다 [{0}]", text);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14039f4b0, CFileSystem, FUN_14039f4b0, 1584, 0x28E9772F);
// @0x14039faf0
int CFileSystem::FUN_14039faf0(std::string path) {
    if (FUN_140398190() && !IsConfigPath(CString(path.c_str()))) {
        std::string resolved = NormalizePath(path, true);
        if (resolved.empty()) return 0;
        if (FUN_14039bf70()) {
            bool stringResource = resolved.find(stringDirectory) != std::string::npos;
            HANDLE file = nullptr;
            std::string alternate;
            size_t slash = resolved.find_last_of('/');
            if (slash != std::string::npos) {
                if (stringResource) alternate = resolved.substr(0, slash + 1) + g_strLocaleDir2;
                else alternate = resolved.substr(0, slash + 1) + g_strLocaleDir;
                alternate += resolved.substr(slash + 1, resolved.length());
                file = CreateFileA(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
                if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
            } else {
                if (stringResource) alternate.assign(g_strLocaleDir2);
                else alternate.assign(g_strLocaleDir);
                alternate += resolved;
                file = CreateFileA(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
                if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
            }
            file = CreateFileA(resolved.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
            if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
        }
        for (auto it = archives.begin(); it != archives.end(); ++it) {
            if (HasPathPrefix(resolved, (*it)->GetPath())) {
                std::string relative = resolved.substr((*it)->GetPath().length() + 1, resolved.length());
                if (reinterpret_cast<CPackFile*>((*it))->Exists(relative) != 0) return 1;
            }
        }
    } else {
        if (FUN_140398640(path, true)) return 0;
        HANDLE file = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
        if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return 1; }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14039faf0, CFileSystem, FUN_14039faf0, 2087, 0x34D09E8B);
// @0x1403a0320
int CFileSystem::FUN_1403a0320(const char* path, void** data, unsigned __int64* size, std::string* actualPath) {
    std::string normalized(static_cast<const char*>(FUN_140188f50(path, 0)));
    if (FUN_140398640(normalized, true)) return 0;
    ATL::CAtlFile file;
    std::string alternate = GetLocalePath(normalized);
    HRESULT opened = file.Create(alternate.c_str(), GENERIC_READ, FILE_SHARE_READ,
                                 OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr, nullptr);
    if (FAILED(opened)) {
        opened = file.Create(normalized.c_str(), GENERIC_READ, FILE_SHARE_READ,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr, nullptr);
        if (FAILED(opened)) return 0;
    } else if (actualPath != nullptr) actualPath->assign(alternate);
    *size = 0;
    file.GetSize(*size);
    if (*size != 0) {
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
    return 0;
}
MS2_REPLACE_METHOD(0x1403a0320, CFileSystem, FUN_1403a0320, 966, 0xB14478D0);

// @0x1403a9410
Unk_FileIgnoreList* GetIgnoreFile() { return reinterpret_cast<Unk_FileIgnoreList*>(TSingleton<CIgnoreFile>::s_instance); }
// @0x1403ab490
bool CFileSystem::HasPathPrefix(const std::string& path, const std::string& prefix) {
    if (path.length() >= prefix.length())
    {
        return path.compare(0, prefix.length(), prefix, 0, prefix.length()) == 0;
    }
    return false;
}

// @0x1403a93e0
Unk_FileArchiveIndex& Unk_FileArchive::GetIndex() { return index; }
// @0x1403a9480
__time64_t GetLastAccessTime(CFileBuffer* buffer) { return buffer->m_tLastAccess; }
// @0x1403a9490
const std::string& Unk_FileArchive::GetPath() { return path; }
// @0x1403a9580
Unk_FileArchiveIndex::Entries& Unk_FileArchiveIndex::GetEntries() { return entries; }
// @0x1403ab1a0
void SetLastAccessTime(CFileBuffer* buffer, __time64_t time) { buffer->m_tLastAccess = time; }















// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9a800-0x142c9a820 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x140396260, GetTimeDifference, 35, 0x4CBC55DE);
MS2_REPLACE(0x140396290, FUN_140396290, 25, 0x93DBCDFE);
MS2_REPLACE_METHOD(0x14039a790, CFileSystem, DecryptByMagic, 250, 0xD9FE5945);
MS2_REPLACE(0x1403a9410, GetIgnoreFile, 8, 0x99CCE324);
MS2_REPLACE_METHOD(0x1403ab490, CFileSystem, HasPathPrefix, 154, 0xAC9AEF37);
MS2_REPLACE_METHOD(0x1403a93e0, Unk_FileArchive, GetIndex, 15, 0x5731F599);
MS2_REPLACE(0x1403a9480, GetLastAccessTime, 15, 0x8B0075C1);
MS2_REPLACE_METHOD(0x1403a9490, Unk_FileArchive, GetPath, 11, 0x3BE09B6E);
MS2_REPLACE_METHOD(0x1403a9580, Unk_FileArchiveIndex, GetEntries, 11, 0x3BE09B6E);
MS2_REPLACE(0x1403ab1a0, SetLastAccessTime, 25, 0x9BEF1163);

