// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "Nif" effect (param + runtime effect), the duplicated
// alpha controller used to fade it out, and the nif cache/loader service. See nifeffectparam.h.
// MS2-UNIT: ?\nifeffectparam.cpp
// MS2-RANGE: 0x1400fa2f0-0x1400fa540 .text$di
// MS2-RANGE: 0x141548790-0x141562ee0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$Unk_SocketFormat@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IV12@@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBV01@AEBI1@Z 0x14154dd60 ; unique
// MS2-PIN: ??$_Kfn@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@5@$0A@@std@@SAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEBU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@1@@Z 0x14154ea60 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14154ea70 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14154ea80 ; prop
// MS2-PIN: ??$construct@PEADAEBQEAD@?$_Default_allocator_traits@V?$allocator@D@std@@@std@@SAXAEAV?$allocator@D@1@QEAPEADAEBQEAD@Z 0x14154eaa0 ; unique
// MS2-PIN: ??$forward@AEBQEAD@std@@YAAEBQEADAEBQEAD@Z 0x14154eb50 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14154eb90 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14154eba0 ; prop
// MS2-PIN: ??0?$SmartPointer@VNiAlphaController@@@efd@@QEAA@PEAVNiAlphaController@@@Z 0x14154ed20 ; unique
// MS2-PIN: ??0?$SmartPointer@VNiFloatInterpolator@@@efd@@QEAA@PEAVNiFloatInterpolator@@@Z 0x14154ed60 ; unique
// MS2-PIN: ??0?$SmartPointer@VUnk_SeparateNode@@@efd@@QEAA@PEAVUnk_SeparateNode@@@Z 0x14154eda0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCBirdMovement@@@@QEAA@PEAVCBirdMovement@@@Z 0x14154ede0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCNifEffectParam@@@@QEAA@PEAVCNifEffectParam@@@Z 0x14154ee10 ; prop
// MS2-PIN: ??1?$SmartPointer@VNiAlphaController@@@efd@@QEAA@XZ 0x14154f0b0 ; unique
// MS2-PIN: ??1?$SmartPointer@VNiFloatInterpolator@@@efd@@QEAA@XZ 0x14154f0e0 ; unique
// MS2-PIN: ??1?$SmartPointer@VUnk_SeparateNode@@@efd@@QEAA@XZ 0x14154f110 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCNifEffectParam@@@@QEAAAEAV1@PEAVCNifEffectParam@@@Z 0x14154f2f0 ; unique
// MS2-PIN: ??B?$SmartPointer@VNiFloatInterpolator@@@efd@@QEBAPEAVNiFloatInterpolator@@XZ 0x14154f480 ; unique
// MS2-PIN: ??B?$SmartPointer@VUnk_SeparateNode@@@efd@@QEBAPEAVUnk_SeparateNode@@XZ 0x14154f490 ; unique
// MS2-PIN: ??C?$SmartPointer@VNiAlphaController@@@efd@@QEBAPEAVNiAlphaController@@XZ 0x14154f500 ; unique
// MS2-PIN: ??C?$SmartPointer@VUnk_SeparateNode@@@efd@@QEBAPEAVUnk_SeparateNode@@XZ 0x14154f510 ; unique
// MS2-PIN: ?GetParent@NiAVObject@@QEAAPEAVNiNode@@XZ 0x14154f9e0 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VCBirdMovement@@@@AEBAXXZ 0x141550080 ; prop
// MS2-PIN: ?AddRef@?$MS2Ptr@VCNifEffectParam@@@@AEBAXXZ 0x1415500b0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCBirdMovement@@@@AEBAXPEAX@Z 0x141550120 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCNifEffectParam@@@@AEBAXPEAX@Z 0x141550150 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@2@$00@2@XZ 0x141550300 ; prop
// MS2-PIN: memmove_s 0x141550890 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1415568c0 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141556920 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141556970 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141556ba0 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141556bf0 ; unique
// MS2-PIN: ??0?$CAtlArray@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@ATL@@@ATL@@QEAA@XZ 0x14155a500 ; prop
// MS2-PIN: ??0?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@QEAA@_K@Z 0x14155a6a0 ; unique
// MS2-PIN: ??0?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@IEAA@_K@Z 0x14155a7c0 ; prop
// MS2-PIN: ??0?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@IEAA@_K@Z 0x14155a820 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14155afa0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14155afb0 ; prop
// MS2-PIN: ??0CCachedNif@@QEAA@XZ 0x14155b020 ; unique
// MS2-PIN: ??0Unk_NifTexKey@@QEAA@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VFormatPrefs@NiTexture@@@Z 0x14155b0b0 ; unique
// MS2-PIN: ??0CNode@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@QEAA@AEBUUnk_NifTexKey@@AEBV?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@Z 0x14155b230 ; unique
// MS2-PIN: ??0CPair@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@IEAA@AEBUUnk_NifTexKey@@AEBV?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@Z 0x14155b380 ; unique
// MS2-PIN: ??1CCachedNif@@UEAA@XZ 0x14155b890 ; unique
// MS2-PIN: ??8?$SmartPointer@VNiSourceTexture@@@efd@@QEBA_NPEAVNiSourceTexture@@@Z 0x14155bcc0 ; unique
// MS2-PIN: ?Invoke@?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVCNifLoadingService@@P82@EAAXXZ@@UEAAXXZ 0x14155c570 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@ATL@@@ATL@@QEAA_KAEBV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x14155ca60 ; unique
// MS2-PIN: ?Push@?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@QEAAXAEBV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x14155cb10 ; unique
// MS2-PIN: ?CallConstructors@?$CAtlArray@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@ATL@@@ATL@@CAXPEAV?$SmartPointer@VNiAVObject@@@efd@@_K@Z 0x14155cc20 ; unique
// MS2-PIN: ?vfunc_1@?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@UEAAXH@Z 0x14155cd00 ; unique
// MS2-PIN: ?Find@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@IEBAPEAVCNode@12@AEBUUnk_NifTexKey@@@Z 0x14155d200 ; unique
// MS2-PIN: ?GetFormatPreferences@NiTexture@@QEBAAEBVFormatPrefs@1@XZ 0x14155d700 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVNiStream@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAVNiStream@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x14155d710 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x14155d730 ; prop
// MS2-PIN: ?GetHeadPosition@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@QEBAPEAU__POSITION@@XZ 0x14155d750 ; prop
// MS2-PIN: ?GetNext@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVNiStream@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAVNiStream@@@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14155d840 ; prop
// MS2-PIN: ?GetNext@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14155d880 ; prop
// MS2-PIN: ?GetNext@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14155d8c0 ; prop
// MS2-PIN: ?GetSize@?$NiTLargeArray@V?$SmartPointer@VNiObject@@@efd@@V?$NiTNewInterface@V?$SmartPointer@VNiObject@@@efd@@@@@@QEBAIXZ 0x14155d9c0 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@AEAAPEAVCNode@12@AEBUUnk_NifTexKey@@AEBV?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@Z 0x14155dfc0 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14155e4f0 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@QEBA_NAEBUUnk_NifTexKey@@AEAV?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@Z 0x14155e730 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14155e8d0 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14155ea90 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@AEAAPEAVCNode@12@AEBUUnk_NifTexKey@@AEBV?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@Z 0x14155f220 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14155f6f0 ; unique
// MS2-PIN: ?RBDelete@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@AEAA_NPEAVCNode@12@@Z 0x14155fcd0 ; unique
// MS2-PIN: ?RBDeleteFixup@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@AEAAXPEAVCNode@12@@Z 0x141560810 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@IEAAPEAVCNode@12@AEBUUnk_NifTexKey@@AEBV?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@Z 0x1415612c0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@ATL@@@ATL@@QEAAXXZ 0x141561580 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141561ee0 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@QEAAPEAU__POSITION@@AEBUUnk_NifTexKey@@AEBV?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@Z 0x141562140 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141562490 ; unique
// MS2-PIN: ?SetupClassInfo@CNifLoadingService@@SAXPEAVClassInfo@efd@@_K@Z 0x141562520 ; unique
// MS2-PIN: ?Successor@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1415627f0 ; unique
// MS2-PIN: ?SwapNode@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141562ce0 ; unique
// MS2-PIN: ??1?$MS2Ptr@VCEquipItem@@@@QEAA@XZ 0x14154f140 ; prop: callee ?Release@?$MS2Ptr@VCEquipItem@@@@AEAAXXZ
// MS2-PIN: ?Reference@?$MS2Ptr@VCNifEffectParam@@@@CAXPEAVCNifEffectParam@@@Z 0x141550100 ; prop: symbols.tsv
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCEquipItem@@@@AEAAXPEAX@Z 0x1415505a0 ; prop: callee ?Reference@?$MS2Ptr@VCEquipItem@@@@CAXPEAVCEquipItem@@@Z
// MS2-PIN: ??1?$CCached@V?$SmartPointer@VNiAVObject@@@efd@@@@UEAA@XZ 0x14155b410 ; unique: caller ??_G?$CCached@V?$SmartPointer@VNiAVObject@@@efd@@@@UEAAPEAXI@Z
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVNiStream@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAVNiStream@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBQEAVNiStream@@@Z 0x14155ed60 ; hand: order of CRBTree<CString,*> instantiations
// MS2-PIN: ?RBInsert@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVNiStream@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAVNiStream@@@2@@ATL@@IEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBQEAVNiStream@@@Z 0x141560dc0 ; hand: order of CRBTree<CString,*> instantiations
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VCCachedNif@@@efd@@@Z 0x14155efc0 ; hand: order of CRBTree<CString,*> instantiations
// MS2-PIN: ?RBInsert@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@IEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VCCachedNif@@@efd@@@Z 0x141561040 ; hand: order of CRBTree<CString,*> instantiations
// MS2-PIN: ??1?$MS2Ptr@VCNifEffectParam@@@@QEAA@XZ 0x14154f170 ; unique: caller ??1CNifEffect@@UEAA@XZ
// MS2-PIN: ?Release@?$MS2Ptr@VCNifEffectParam@@@@AEAAXXZ 0x141550560 ; prop: symbols.tsv
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1415568f0 ; unique: caller ??$?0AEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@...
// MS2-PIN: ??0?$SmartPointer@VNiTexturePalette@@@efd@@QEAA@PEAVNiTexturePalette@@@Z 0x14155aa90 ; hand: identical look-alike group
// MS2-PIN: ??1?$CAtlArray@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@ATL@@@ATL@@QEAA@XZ 0x14155b3d0 ; hand: identical look-alike group
// MS2-PIN: ??A?$CAtlArray@V?$SmartPointer@VDuplicatedAlphaController@@@efd@@V?$CElementTraits@V?$SmartPointer@VDuplicatedAlphaController@@@efd@@@ATL@@@ATL@@QEAAAEAV?$SmartPointer@VDuplicatedAlphaController@@@efd@@_K@Z 0x14154f980 ; hand: identical look-alike group
// MS2-PIN: ??0?$SmartPointer@VNiAVObject@@@efd@@QEAA@AEBV01@@Z 0x14155aa50 ; hand: identical look-alike group
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@ATL@@@ATL@@CAXPEAV?$SmartPointer@VNiAVObject@@@efd@@_K@Z 0x14155cca0 ; hand: identical look-alike group
// MS2-PIN: ??_G?$SmartPointer@VNiAVObject@@@efd@@QEAAPEAXI@Z 0x14155c6c0 ; hand: identical look-alike group
// MS2-PIN: ?GetKeyAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@PEAU__POSITION@@@Z 0x14155d770 ; hand: identical look-alike group
// MS2-PIN: ?GetKeyAt@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@QEBAAEBUUnk_NifTexKey@@PEAU__POSITION@@@Z 0x14155d7d0 ; hand: identical look-alike group
// MS2-PIN: ?GetValueAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVNiStream@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAVNiStream@@@2@@ATL@@QEAAAEAPEAVNiStream@@PEAU__POSITION@@@Z 0x14155d9e0 ; hand: identical look-alike group
// MS2-PIN: ??_ECNiStreamLoadThread@@WBI@EAAPEAXI@Z 0x14155c59c ; hand: identical look-alike group
// MS2-PIN: ?Clone@CAtlStringMgr@ATL@@UEAAPEAUIAtlStringMgr@2@XZ 0x14103c770 ; hand: vftable slot copy
// MS2-PIN: ??0Point3@efd@@QEAA@XZ 0x141550310 ; hand: identical look-alike group
// MS2-PIN: ??0?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@QEAA@XZ 0x14155a440 ; hand: identical look-alike group
// MS2-PIN: ??0Matrix3@efd@@QEAA@XZ 0x14155a420 ; hand: identical look-alike group
// MS2-PIN: ??0?$tuple@$$V@std@@QEAA@XZ 0x14155a430 ; hand: identical look-alike group
// MS2-PIN: ??$_Get_size_of_n@$00@std@@YA_K_K@Z 0x14155a450 ; hand: identical look-alike group
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x14154f520 ; hand: identical look-alike group
// MS2-PIN: ??C?$MS2Ptr@VCNifEffectParam@@@@QEBAPEAVCNifEffectParam@@XZ 0x14154f530 ; hand: identical look-alike group
// MS2-PIN: ?GetAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@QEAAPEAVCPair@12@PEAU__POSITION@@@Z 0x14155d570 ; hand: identical look-alike group
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14155ae20 ; hand: identical look-alike group
// MS2-PIN: ??1?$pair@QEAVNiAVObject@@VNiString@@@std@@QEAA@XZ 0x14154f1a0 ; hand: identical look-alike group
// MS2-PIN: ??Y?$basic_string@DU?$char_traits@D@std@@V?$CustomAllocator@D@efd@@@std@@QEAAAEAV01@QEBD@Z 0x141561910 ; hand: identical look-alike group
// MS2-PIN: ?Release@?$MS2Ptr@VCBirdMovement@@@@AEAAXXZ 0x141550520 ; hand: identical look-alike group
// MS2-PIN: ??8?$SmartPointer@VNiPixelData@@@efd@@QEBA_NPEAVNiPixelData@@@Z 0x14154f360 ; hand: identical look-alike group
// MS2-PIN: ??$_Convert_size@_K@std@@YA_K_K@Z 0x14154ea90 ; hand: identical look-alike group
// MS2-PIN: ??B?$SmartPointer@VNiInterpolator@@@efd@@QEBAPEAVNiInterpolator@@XZ 0x14154f460 ; hand: identical look-alike group
// MS2-PIN: ??C?$SmartPointer@VNiInterpolator@@@efd@@QEBAPEAVNiInterpolator@@XZ 0x141550400 ; hand: identical look-alike group
// MS2-PIN: ??B?$SmartPointer@VNiObject@@@efd@@QEBAPEAVNiObject@@XZ 0x14155bfb0 ; hand: identical look-alike group
// MS2-PIN: ??C?$MS2Ptr@VCBirdMovement@@@@QEBAPEAVCBirdMovement@@XZ 0x14154f4a0 ; hand: identical look-alike group
// MS2-PIN: ??1?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAU__POSITION@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAU__POSITION@@@2@@ATL@@QEAA@XZ 0x14155b490 ; hand: identical look-alike group
// MS2-PIN: ??1?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVNiStream@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAVNiStream@@@2@@ATL@@QEAA@XZ 0x14155b4b0 ; hand: identical look-alike group
// MS2-PIN: ?_Getal@?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QEAAAEAV?$allocator@D@2@XZ 0x141550390 ; hand: identical look-alike group
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@PEAVNiAVObject@@VNiString@@U?$less@PEAVNiAVObject@@@std@@V?$allocator@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@4@$0A@@std@@@std@@IEBAAEBQEAVNiAVObject@@AEBU?$pair@QEAVNiAVObject@@VNiString@@@2@@Z 0x1415503e0 ; hand: identical look-alike group
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@1@@Z 0x14154ee60 ; hand: identical look-alike group
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@1@@Z 0x14155ad20 ; hand: identical look-alike group
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@1@@Z 0x14155ad80 ; hand: identical look-alike group
// MS2-PIN: ??1?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAU__POSITION@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAU__POSITION@@@2@@ATL@@QEAA@XZ 0x14155b510 ; hand: identical look-alike group
// MS2-PIN: ??8?$SmartPointer@VCCachedNif@@@efd@@QEBA_NPEAVCCachedNif@@@Z 0x14155bd00 ; hand: identical look-alike group
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@1@@Z 0x14155ae80 ; hand: identical look-alike group
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@1@@Z 0x14155aee0 ; hand: identical look-alike group
// MS2-PIN: ??R?$less@PEAVNiAVObject@@@std@@QEBA_NAEBQEAVNiAVObject@@0@Z 0x14154f650 ; hand: identical look-alike group
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@PEAVNiAVObject@@VNiString@@U?$less@PEAVNiAVObject@@@std@@V?$allocator@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@std@@@2@XZ 0x141550790 ; hand: identical look-alike group
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@2@@Z 0x141550410 ; hand: identical look-alike group
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@QEAA@XZ 0x14155b4d0 ; hand: ground truth, CNifLoadingService dtor +0x28
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@2@XZ 0x1415502f0 ; hand: const _Getal callee
// MS2-PIN: ??0Unk_NifTexKey@@QEAA@AEBU0@@Z 0x14155b070
// MS2-PIN: ??1?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVNiStream@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAVNiStream@@@2@@ATL@@QEAA@XZ 0x14155b550 ; hand: byte-identical
// MS2-PIN: ??1?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@QEAA@XZ 0x14155b590 ; hand: byte-identical
// MS2-PIN: ?GetValueAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@QEAAAEAV?$SmartPointer@VCCachedNif@@@efd@@PEAU__POSITION@@@Z 0x14155da40 ; hand: byte-identical
// MS2-PIN: ?GetValueAt@?$CRBTree@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@QEAAAEAV?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@PEAU__POSITION@@@Z 0x14155daa0 ; hand: byte-identical
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVNiStream@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@PEAVNiStream@@@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBQEAVNiStream@@@Z 0x141562060 ; hand: byte-identical
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCCachedNif@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCCachedNif@@@efd@@@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VCCachedNif@@@efd@@@Z 0x1415620d0 ; hand: byte-identical
// MS2-PIN: ?GetClassDesc@CNifLoadingService@@UEBAPEBVClassInfo@efd@@XZ 0x14155d5a0 ; hand: byte-identical
// MS2-PIN: ?GetAt@?$NiTLargeArray@V?$SmartPointer@VNiObject@@@efd@@V?$NiTNewInterface@V?$SmartPointer@VNiObject@@@efd@@@@@@QEBAAEBV?$SmartPointer@VNiObject@@@efd@@I@Z 0x14155d580 ; hand: byte-identical
// MS2-PIN: ?Get@?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@QEBAHHAEAV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x14155d5b0 ; hand: byte-identical
// MS2-PIN: ?DecRefCount@CNifLoadingService@@UEBAXXZ 0x14155ce50 ; hand: byte-identical
// MS2-PIN: ?DeleteThis@CNifLoadingService@@MEBAXXZ 0x14155ce90 ; hand: byte-identical
// MS2-PIN: ?Clone@?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVCNifLoadingService@@P82@EAAXXZ@@UEBAPEAV1@XZ 0x14155cee0 ; hand: byte-identical
// MS2-PIN: ??$AddDependency@UUnk_NifDepSix@@@IDependencyRegistrar@efd@@QEAA_NI@Z 0x141556d30
// MS2-PIN: ??4?$SmartPointer@VCEffectObject@@@efd@@QEAAAEAV01@PEAVCEffectObject@@@Z 0x14154f270
// MS2-PIN: ??_7CNiStreamLoadThread@@6B?$TSingleton@VCNiStreamLoadThread@@@@@ 0x142f2e158
// MS2-PIN: ??_7CNifLoadingService@@6BISystemService@efd@@@ 0x142f2e1a8
// MS2-PIN: ??_7CNifLoadingService@@6B?$TSingleton@VCNifLoadingService@@@@@ 0x142f2e230
// hand pins (w98): scalar deleting destructors
// MS2-PIN: ??$forward@AEAVNiString@@@std@@YAAEAVNiString@@AEAV1@@Z 0x14154eb80 ; unique: caller ??$?0AEAPEAVNiAVObject@@AEAVNiString@@$0A@@?$pair@QEAVNiAVObject@@...
// MS2-PIN: ??0?$CCached@V?$SmartPointer@VNiAVObject@@@efd@@@@QEAA@XZ 0x14155a540 ; unique: single byte-identical candidate
// MS2-PIN: ??1?$SmartPointer@VNiAVObject@@@efd@@QEAA@XZ 0x14155b690 ; prop: caller ??_G?$SmartPointer@VNiAVObject@@@efd@@QEAAPEAXI@Z
// MS2-PIN: ??$?0AEAPEAVNiAVObject@@AEAVNiString@@$0A@@?$pair@QEAVNiAVObject@@VNiString@@@std@@QEAA@AEAPEAVNiAVObject@@AEAVNiString@@@Z 0x14154d910 ; unique: single byte-identical candidate
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@1@PEAU01@@Z 0x14154e260 ; prop: 0x141556f90 taken by ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@D...
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14154eb70 ; unique: caller ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pa...
// MS2-PIN: ??0?$CAtlArray@V?$SmartPointer@VDuplicatedAlphaController@@@efd@@V?$CElementTraits@V?$SmartPointer@VDuplicatedAlphaController@@@efd@@@ATL@@@ATL@@QEAA@XZ 0x14154ec10 ; unique: caller ??0CNifEffect@@QEAA@XZ
// MS2-PIN: ??0?$pair@QEAVNiAVObject@@VNiString@@@std@@QEAA@$$QEAU01@@Z 0x14154ef20 ; unique: caller ??$construct@U?$pair@QEAVNiAVObject@@VNiString@@@std@@U12@@?$_Defa...
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@PEAVNiAVObject@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@PEAVNiAVObject@@@2@XZ 0x1415502d0 ; unique: caller ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiAVObject@@VNiSt...
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@2@XZ 0x1415502e0 ; unique: caller ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiAVObject@@VNiStri...
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiAVObject@@VNiString@@@std@@@std@@@2@XZ 0x141550320 ; unique: caller ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiAVObject@@VNiS...
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@2@_K@Z 0x141550800 ; prop: caller ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@V...
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@2@_K@Z 0x141550830 ; prop: 0x141550800 taken by ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node...
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@QEAVNiAVObject@@VNiString@@@std@@PEAX@std@@@2@@Z 0x141550860 ; unique: caller ?max_size@?$_Tree@V?$_Tmap_traits@PEAVNiAVObject@@VNiString@@U?$le...
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141556f90 ; prop: callee ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTrait...
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141557020 ; prop: callee ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMF...
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x141559f60 ; prop: caller ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@D...
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@0@AEAPEAU10@@Z 0x141559f70 ; prop: caller ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@D...
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x141559fc0 ; prop: symbols.tsv
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@1@AEAPEAU31@@Z 0x14155a010 ; prop: symbols.tsv
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@1@@Z 0x14155a200 ; prop: symbols.tsv
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@1@@Z 0x14155a210 ; prop: symbols.tsv
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x14155a3e0 ; prop: symbols.tsv
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@PEAX@0@AEAPEAU10@@Z 0x14155a3f0 ; prop: symbols.tsv
// MS2-PIN: ??0?$CRBMap@UUnk_NifTexKey@@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@V?$CElementTraits@UUnk_NifTexKey@@@ATL@@V?$CElementTraits@V?$SmartPointer@V?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@@efd@@@5@@ATL@@QEAA@_K@Z 0x14155a6d0 ; unique: caller ??0CNifLoadingService@@QEAA@XZ
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14155c330 ; unique: caller ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pa...
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VTiXmlDocument@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14155c400 ; unique: caller ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pa...
// MS2-PIN: ??_G?$TSingleton@VCNiStreamLoadThread@@@@UEAAPEAXI@Z 0x14155c760
// MS2-PIN: ??_GCNiStreamLoadThread@@UEAAPEAXI@Z 0x14155c8c0
// MS2-PIN: ??_G?$TCircleList@V?$SmartPointer@VNiAVObject@@@efd@@@@UEAAPEAXI@Z 0x14155c720
// MS2-PIN: ??_G?$CCached@V?$SmartPointer@VNiTexture@@@efd@@@@UEAAPEAXI@Z 0x14155c620
// MS2-PIN: ??_G?$CCached@V?$SmartPointer@VNiAVObject@@@efd@@@@UEAAPEAXI@Z 0x14155c5c0
// MS2-PIN: ??_GCCachedNif@@UEAAPEAXI@Z 0x14155c860
// MS2-PIN: ??_G?$TSingleton@VCNifLoadingService@@@@UEAAPEAXI@Z 0x14155c7a0
// MS2-PIN: ??_GCNifLoadingService@@UEAAPEAXI@Z 0x14155c900
// MS2-PIN: ??_G?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVCNifLoadingService@@P82@EAAXXZ@@UEAAPEAXI@Z 0x14155c680
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nifeffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "nifeffectparam.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <efd/AssetFactoryManager.h>
#include <algorithm>
#include <new>
#include <efd/MemoryDefines.h>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiFixedString.h>
#include <NiCloningProcess.h>
#include <NiTimeController.h>
#include <NiInterpolator.h>
#include <NiStream.h>
#include <NiSearchPath.h>
#include <NiMaterialProperty.h>
#include <NiStringExtraData.h>
#include <NiString.h>
#include <NiFloatData.h>
#include <NiLinFloatKey.h>
#include <NiFloatInterpolator.h>
#include <efd/ServiceManager.h>
#include "ms2/client/ms2/effectobject.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
// Game TinyXML element.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);              // FirstChildElement(name)
    Unk_140165cf0* FUN_140168650(const char* pszName);              // NextSiblingElement(name)
};
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nOut);
int FUN_1408730a0(Unk_140165cf0* pNode, const char* pszName, bool& bOut);
int FUN_140874670(Unk_140165cf0* pNode, const char* pszName, Vector3& kOut);

// The nif / texture cache service (CNifLoadingService::s_instance).
CNifLoadingService* FUN_140a0afd0();
class Unk_ModelCache { public: void FUN_141210ac0(CString strPath); };           // release by path
Unk_ModelCache* FUN_140ab7a10();
CString FUN_140cc2ba0(const CString& strDir, const CString& strName);

bool FUN_140afc5a0(const Unk_LightUpdateBits* pBits);               // all bits set
bool FUN_140314790(Unk_LightUpdateBits* pBits, unsigned nPos);
void FUN_14154fda0(void* pObj);
void FUN_1411ff180(Unk_LightUpdateBits* pBits);                      // set every bit

// Attach type name -> 0 none, 1 Node, 2 Mesh, 3 WeaponL, 4 WeaponR (0x14154d880).
// @0x14154d880
static int ParseAttachType(CString& strType)
{
    if (strType.CompareNoCase("Node") == 0)
        return 1;
    else if (strType.CompareNoCase("Mesh") == 0)
        return 2;
    else if (strType.CompareNoCase("WeaponL") == 0)
        return 3;
    else if (strType.CompareNoCase("WeaponR") == 0)
        return 4;
    return 0;
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x14154e0e0
static int FUN_14154e0e0(Unk_140165cf0* pNode, const char* pszName, int& nOut)
{
    CString strType;
    int nResult = FUN_1408733e0(pNode, pszName, strType);
    if (nResult == 0)
        nOut = ParseAttachType(strType);
    return nResult;
}

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI CNifEffect::ms_RTTI("CNifEffect", &CEffect::ms_RTTI);                              // @0x1400fa2f0
const NiRTTI DuplicatedAlphaController::ms_RTTI("DuplicatedAlphaController", &NiAlphaController::ms_RTTI);  // @0x1400fa320
#else
const NiRTTI CNifEffect::ms_RTTI("CNifEffect", &CEffect::ms_RTTI);
const NiRTTI DuplicatedAlphaController::ms_RTTI("DuplicatedAlphaController", &NiAlphaController::ms_RTTI);
#endif
#include "ms2/placeholder/header_statics_a.h"       // @0x1400fa350-0x1400fa470

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141548790
// Copies pkSource (exact copy; the clone map maps its target to itself so the copy keeps the same target).
DuplicatedAlphaController::DuplicatedAlphaController(NiSingleInterpController* pkSource)
{
    NiCloningProcess kCloning(0x25);
    NiObject* pkTarget = pkSource->GetTarget();
    kCloning.m_pkCloneMap->SetAt(pkTarget, pkTarget);
    kCloning.m_eCopyType = NiObjectNET::COPY_EXACT;
    kCloning.m_eDynamicEffectRelationBehavior = NiCloningProcess::CLONE_RELATION_NONE;
    kCloning.m_eAffectedNodeRelationBehavior = NiCloningProcess::CLONE_RELATION_NONE;
    static_cast<DuplicatedAlphaController*>(pkSource)->NiSingleInterpController::CopyMembers(this, kCloning);
    m_fScale = 1.0f;
}

// @0x141548880
void DuplicatedAlphaController::Update(float fTime)
{
    if (GetManagerControlled())
        return;
    if (DontDoUpdate(fTime) && (!m_spInterpolator || !m_spInterpolator->AlwaysUpdate()))
        return;
    if (m_spInterpolator)
    {
        float fValue;
        if (m_spInterpolator->Update(m_fScaledTime, m_pkTarget, fValue))
            ((NiMaterialProperty*)m_pkTarget)->SetAlpha(m_fScale * fValue);
    }
}
MS2_REPLACE_METHOD(0x141548880, DuplicatedAlphaController, Update, 264, 0x712BD65A);

// @0x141548990
CNifEffectParam::CNifEffectParam()
    : CEffectParam(1), m_strFilePath(""), m_ptTranslate(0.0f, 0.0f, 0.0f), m_ptRotation(0.0f, 0.0f, 0.0f),
      m_fScale(1.0f), m_bApplyNodeTransform(false), m_bOnGround(false), m_bUseLighting(true), m_bUseShadow(false),
      m_nAttachType(0), m_strParentNode(""), m_nMyReferCount(0), m_nOtherReferCount(0), m_fMaxLength(500.0f),
      m_fMinLength(1.0f), m_fStep(0.01f), m_fVelocity(300.0f), m_bNotForceStop(false), m_bOffFadeOut(false),
      m_fViewDistance(-1.0f), m_bBipedLoop(false)
{
    FUN_1411ff180(&m_bitsApply);
}

// @0x141548b90
void CNifEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    bool bUpdateTranslate = true, bUpdateRotation = true, bUpdateScale = true;
    bool bApplyTranslate = true, bApplyRotation = true, bApplyScale = true;
    FUN_1408733e0(pNode, "filePath", m_strFilePath);
    if (!m_strFilePath.IsEmpty())
    {
        m_strFilePath.TrimLeft();
        m_strFilePath.TrimRight();
    }
    FUN_1408733e0(pNode, "effectObjectKfmName", m_strEffectObjectKfm);
    FUN_1408730a0(pNode, "notForceStop", m_bNotForceStop);
    FUN_1408730a0(pNode, "bipedLoop", m_bBipedLoop);
    FUN_140873360(pNode, "viewDistance", m_fViewDistance);
    FUN_1408730a0(pNode, "offFadeOut", m_bOffFadeOut);
    FUN_1408731e0(pNode, "myReferCount", m_nMyReferCount);
    FUN_1408731e0(pNode, "otherReferCount", m_nOtherReferCount);
    Unk_140165cf0* pTransform = pNode->FUN_140165cf0("transform");
    if (pTransform != 0)
    {
        FUN_140874670(pTransform, "translate", m_ptTranslate);
        FUN_140874670(pTransform, "rotation", m_ptRotation);
        FUN_140873360(pTransform, "scale", m_fScale);
    }
    Unk_140165cf0* pAttach = pNode->FUN_140165cf0("attachInfo");
    if (pAttach != 0)
    {
        FUN_14154e0e0(pAttach, "attachType", m_nAttachType);
        FUN_1408730a0(pAttach, "applyNodeTransform", m_bApplyNodeTransform);
        FUN_1408733e0(pAttach, "parentNode", m_strParentNode);
        FUN_1408730a0(pAttach, "onGround", m_bOnGround);
        FUN_1408730a0(pAttach, "useLighting", m_bUseLighting);
        FUN_1408730a0(pAttach, "useShadow", m_bUseShadow);
        bool bAttachToNode = false;
        FUN_1408730a0(pAttach, "attachToNode", bAttachToNode);
        if (bAttachToNode)
            m_nAttachType = 1;
    }
    Unk_140165cf0* pUpdate = pNode->FUN_140165cf0("update");
    if (pUpdate != 0)
    {
        FUN_1408730a0(pUpdate, "translate", bUpdateTranslate);
        FUN_1408730a0(pUpdate, "rotation", bUpdateRotation);
        FUN_1408730a0(pUpdate, "scale", bUpdateScale);
    }
    Unk_140165cf0* pApply = pNode->FUN_140165cf0("applyNodeTransform");
    if (pApply != 0)
    {
        FUN_1408730a0(pApply, "translate", bApplyTranslate);
        FUN_1408730a0(pApply, "rotation", bApplyRotation);
        FUN_1408730a0(pApply, "scale", bApplyScale);
    }
    Unk_140165cf0* pLerp = pNode->FUN_140165cf0("lerp");
    if (pLerp != 0)
    {
        FUN_1408733e0(pLerp, "type", m_strLerpType);
        FUN_140873360(pLerp, "MaxLength", m_fMaxLength);
        FUN_140873360(pLerp, "MinLength", m_fMinLength);
        FUN_140873360(pLerp, "Step", m_fStep);
        FUN_140873360(pLerp, "Velocity", m_fVelocity);
    }
    if (bUpdateTranslate)
        m_bitsUpdate[0] = true;
    if (bUpdateRotation)
        m_bitsUpdate[1] = true;
    if (bUpdateScale)
        m_bitsUpdate[2] = true;
    if (!bApplyTranslate)
        m_bitsApply[0] = false;
    if (!bApplyRotation)
        m_bitsApply[1] = false;
    if (!bApplyScale)
        m_bitsApply[2] = false;
}
MS2_REPLACE_METHOD(0x141548B90, CNifEffectParam, vfunc_1, 1569, 0x0382EC70);

// @0x1415491c0
bool CNifEffectParam::vfunc_2()
{
    if (!CEffectParam::vfunc_2())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1415491C0, CNifEffectParam, vfunc_2, 37, 0x35A9EC27);

// @0x1415491f0
bool CNifEffectParam::vfunc_3()
{
    if (m_strFilePath.IsEmpty())
        return true;
    return FUN_140a0afd0()->IsCached(FUN_140cc2ba0("Effect", m_strFilePath));
}
MS2_REPLACE_METHOD(0x1415491F0, CNifEffectParam, vfunc_3, 162, 0xE876FA96);

// @0x1415492a0
void CNifEffectParam::vfunc_4()
{
    if (m_strFilePath.IsEmpty())
        return;
    FUN_140ab7a10()->FUN_141210ac0(FUN_140cc2ba0("Effect", m_strFilePath));
}
MS2_REPLACE_METHOD(0x1415492A0, CNifEffectParam, vfunc_4, 152, 0x93F3CAB0);

// @0x141549340
bool CNifEffectParam::vfunc_5(int n)
{
    if (m_strFilePath.IsEmpty())
        return true;
    if (FUN_140a0afd0() != 0)
    {
        if (!FUN_140a0afd0()->Preload(FUN_140cc2ba0("Effect", m_strFilePath), false, n))
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x141549340, CNifEffectParam, vfunc_5, 231, 0x802473A5);

// @0x141549430
// Not hooked: constructs CNifEffect with its (exe) constructor.
CEffectPtr CNifEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CNifEffect;
}
MS2_REPLACE_METHOD(0x141549430, CNifEffectParam, vfunc_6, 150, 0x328AECC3);

// ---- CNifEffect: out-of-unit types and callees ----
// The effect target (CEffect::vfunc_3's second argument), the part this unit reads.
struct Unk_NifTarget
{
    char m_pad_00[0x10];
    NiAVObjectPtr m_hNode;          // +0x10 handle of the owner's scene node
    const NiTransform* m_pPre;      // +0x18 transform before the animation
    const NiTransform* m_pPost;     // +0x20 transform after the animation
    char m_pad_28[8];
    bool m_bNoCull;                 // +0x30
    char m_pad_31;
    bool m_bTagLod;                 // +0x32 tag the loaded model with the Eff_LOD extra data
};
MS2_CHECK_OFFSET(Unk_NifTarget, m_hNode, 0x10);
MS2_CHECK_OFFSET(Unk_NifTarget, m_pPre, 0x18);
MS2_CHECK_OFFSET(Unk_NifTarget, m_bTagLod, 0x32);

double FUN_140a53420(Unk_EffectTarget* pTarget);                    // start time of the target
int FUN_140a53390(Unk_EffectTarget* pTarget);                       // the target's owner id
NiNode* FUN_140a533d0(Unk_EffectTarget* pTarget);                   // the target's owner node
void* FUN_140a53440(Unk_EffectTarget* pTarget);                     // the target's attach object
int FUN_140a53480(Unk_EffectTarget* pTarget);                       // the target's slot kind (6 = any)
double FUN_14119f3a0(CEffect* pEffect);                             // start time
bool FUN_14028d470(float a, float b);                               // nearly equal
class Unk_GameClock { public: double FUN_141473280(); };
Unk_GameClock* FUN_14086d260();
efd::ServiceManager* FUN_1413f9850();

// Handles (NiAVObjectPtr) and node pointers.
NiAVObject* FUN_1409849b0(NiAVObjectPtr* pHandle);                  // handle -> node pointer
NiAVObject* FUN_14098d0f0(NiAVObjectPtr* pHandle);                  // handle -> node pointer (non-const)
bool FUN_1409a7f70(NiAVObjectPtr* pHandle, int nNull);              // handle == NULL?
void FUN_1409fabf0(NiAVObjectPtr* pHandle, NiAVObject* pObj);       // handle = object
bool FUN_1411b02b0(NiAVObjectPtr* pA, NiAVObjectPtr* pB);
bool FUN_140aac3e0(Unk_NodePtr* pPtr, void* pOther);                // node pointer != pOther
void* FUN_14098d8d0(const void* pRtti, void* pObj);                 // dynamic cast through an NiRTTI
void FUN_141d16040(void* pNode, float fTime, bool bUpdateControllers);    // NiAVObject::Update
void FUN_140a0b2a0(void* pNode);                                    // detach from the parent
void FUN_140a0b300(void* pNode, bool bCulled);                      // SetAppCulled
void* FUN_140a0b000(void* pNode);                                   // parent node
bool FUN_14098dad0(NiAVObject* pObj);                               // object is app-culled
efd::FixedString* FUN_1409a8b90(NiAVObject* pNode);                 // node name
const char* FUN_142087e50(const void* kFixed);
bool FUN_141068d50(efd::FixedString* pName, const char* pszName);
void FUN_140a0b330(void* pObj, bool bOn, short sFlags);

// Transforms (the exe's NiTransform helpers) and node transforms.
void* FUN_140a33f90(void* pObj);                                    // local transform
void* FUN_1409478e0(void* pObj);                                    // world transform
void FUN_140aacb60(void* pObj, const void* pXform);                 // SetLocalTransform
const Vector3& FUN_140947900(void* pNode);                  // world translate
void* FUN_141024c90(void* pNode);                                   // world rotation
void FUN_140a0b1f0(void* pRotation, float* pDirection);             // rotation -> facing direction
void FUN_1402bd040(float* p);                                       // NiPoint3()
void FUN_140194470(void* pDst, const void* pSrc);                   // point assign

// The effect manager (singleton 0x1403ed280) and the world.
class Unk_EffectMgr
{
public:
    void* FUN_1411a6b10();                          // scene root
    unsigned FUN_1411a88c0();                       // quality level (1..3)
};
Unk_EffectMgr* FUN_1403ed280();
void* FUN_1403ed2d0();                                              // the world
void FUN_141bbb1e0(void* pWorld, GameObject* pObj, int nA, int nB); // add the object
void FUN_141bbb7f0(void* pWorld, GameObject* pObj, int nA);         // remove the object
void* FUN_14119f490();                                              // the effect culler
int FUN_1411b86e0(void* pCuller, void* pQuery);                     // 0 when visible
void FUN_1411a3db0(void* pEffectNode, CBirdMovement* pMovement);
void FUN_1411a3fa0(void* pEffectNode, bool bOnGround);
void FUN_141567a10(void* pNode);
void FUN_141567330(void* pNode, bool bShadow);
void FUN_141851f90(void* pNode, float fTime);                       // seek the node's animations
float FUN_141852010(void* pNode);                                   // duration of the node's animations
void* FUN_1409a8b00();
void* FUN_1409a5160(void* p);
void FUN_141773a90(void* pRegistry, void* pNode);                   // register a model
void FUN_141773cc0(void* pRegistry, void* pNode);                   // unregister a model

// Registry of the nif path each loaded node came from. It is the object FUN_141d6fd90 returns (the renderer's shader
// context in ms2renderservice.cpp); only its path map at +0x08 matters here.
class Unk_NifPathRegistry
{
public:
#ifndef MS2_HOOK_DLL
    void Register(NiAVObject* pNode, const char* pszPath)           // @0x14154ff90
    {
        NiString kPath;
        kPath = pszPath;
        m_mapPath.insert(std::pair<NiAVObject* const, NiString>(pNode, kPath));
    }
#else
    void Register(NiAVObject* pNode, const char* pszPath);          // the exe's copy
#endif
    char m_pad_0[8];
    std::map<NiAVObject*, NiString> m_mapPath;                      // +0x08
};
Unk_NifPathRegistry* FUN_141d6fd90_np();                            // the same function as FUN_141d6fd90 (see symbols-manual)
// remember the nif path of the node
// @0x141550050
inline void FUN_141550050(void* pNode, const char* pszPath)
{
    FUN_141d6fd90_np()->Register(static_cast<NiAVObject*>(pNode), pszPath);
}

// Query passed to the culler (ctor 0x1411b8570: kind 9, default position).
struct Unk_NifCullQuery
{
    int m_nMode;                    // +0x00
    int m_nKind;                    // +0x04
    float m_aPos[4];                // +0x08
    float m_fViewDistance;          // +0x18
    char m_pad_1c[4];
};
MS2_CHECK_SIZE(Unk_NifCullQuery, 0x20);
void FUN_1411b8570(Unk_NifCullQuery* pQuery);

// Scene nodes of the effect system (see swoosheffectparam.cpp / lighteffectparam.cpp).
class Unk_EffectNode : public NiNode
{
public:
    Unk_EffectNode(int nA, int nB);                                 // 0x1411a34b0
    char m_pad_node[400 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_EffectNode, 400);
class Unk_SeparateNode : public NiNode
{
public:
    Unk_SeparateNode(unsigned char nBits);                          // 0x141751470
    char m_pad_node[0x138 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_SeparateNode, 0x138);

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

// Controllers and extra data of a node.
NiTimeController* FUN_14098dc80(NiObjectNET* pObj);                 // first controller
NiTimeController* FUN_14098de40(NiTimeController* pCtrl);           // next controller
void* FUN_141d17b40(void* pObj, const void* pKey);                  // extra data by key
const efd::FixedString* FUN_141168130(NiStringExtraData* pExtra);   // string value
extern char DAT_143ae51b8;                                          // NiFixedString: the Eff_LOD tag key
extern char DAT_143ae50e8;                                          // NiFixedString: the tag text
extern NiRTTI DAT_143afb000;                                        // NiStringExtraData RTTI
extern char DAT_143ae5198;                                          // NiFixedString: the nif path key

// Players, their equipment and the equipped item's model.
typedef efd::SmartPointer<GameObject> Unk_NifPCPtr;
GameObject* FUN_14099eef0(GameObject* pObj);                        // object -> player (0 if it is not one)
bool FUN_140c206b0(Unk_NifPCPtr* pPtr, int nNull);                  // pointer == NULL?
GameObject* FUN_140aac420(Unk_NifPCPtr* pPtr);
GameObject* FUN_140aac440(Unk_NifPCPtr* pPtr);
class Unk_NifEquipSet
{
public:
    MS2Ptr<CEquipItem> FUN_1411e2610(NiAVObject* pNode, int nA, int nKind, bool bB);   // equipped item owning the node
    MS2Ptr<CEquipItem> FUN_1411e1860(int nSlot, int nA, int nB);                        // equipped item of the slot
    NiAVObjectPtr FUN_1411e2a60(void* pAttach, const CString& strName, bool bA);       // model node of the item by name
};
Unk_NifEquipSet* FUN_1416561a0(GameObject* pPC);
struct Unk_NifEquipView { Unk_NodePtr FUN_1411dd700(); };          // the item's model node (CEquipItem member: this=rcx, hidden return=rdx)
int FUN_14052a170(CItem* pItem);                                    // the item's slot kind
int FUN_1411dc670(CEquipItem* pEquip);
int FUN_1411dc820(CEquipItem* pEquip);                              // the item id

// Strings of the log lines.
CString FUN_140741200(const char* pszFormat, const CString& strA, const CString& strB);
CString FUN_140536a50(const char* pszFormat, const CString& strA);
class Unk_NifStrings { public: CStringW FUN_141811980(int nA, int nId); };
Unk_NifStrings* FUN_1401a9d70();
CLogString* GetLogString();                                         // the game log, or 0

// 3-argument fmt log helper (log, level, category, "format", a, b, c).
// @0x14154da00
template<class T, class U, class V> inline void Unk_NifLog3(CLogString* log, int level, int category, const wchar_t* format,
                                                            const T& first, const U& second, const V& third) {
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(third)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third), args));
}

// @0x14154f4b0
Unk_BitRef::operator bool() const
{
    return FUN_140314790(m_pBits, m_nPos);
}

// The exe's 0x14154f540 / 0x14154f560 are the pre-increment wrappers of std::map<NiAVObject*, NiString> iterators
// (_Tree_const_iterator / _Tree_iterator::operator++ over _Tree_unchecked_const_iterator::operator++ 0x14154f580); the
// source never iterates that map, so they are stand-ins.
void FUN_14154f580(void* pIter);

// @0x14154f540
void* Unk_PathMapConstIterInc(void* pIter)
{
    FUN_14154f580(pIter);
    return pIter;
}

// @0x14154f560
void* Unk_PathMapIterInc(void* pIter)
{
    Unk_PathMapConstIterInc(pIter);
    return pIter;
}

// @0x1415494d0
CNifEffect::CNifEffect()
    : m_bSplit(false), m_spTarget(0), m_spModel(0), m_spSplit(0), m_spRoot(0), m_fFadeStart(FLT_MAX),
      m_fFadeTime(1.0f), m_nLodLevel(0), m_fStartTime(0.0f), m_spEffectObject(0), m_spParam()
{
    m_kXform.MakeIdentity();
}

// @0x141549620
CNifEffect::~CNifEffect()
{
    vfunc_7();
}

// MS2-FUNCTIONAL: big function: codegen (temporaries / branch layout) not byte-identical to the exe
// @0x1415496f0
// Builds the nif instance: an EffectNode root holding the loaded model (and the kfm effect object / bird movement),
// placed by the param's transform composed with the target's, and hung on the node selected by the attach type.
bool CNifEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    m_spParam.AssignRaw(static_cast<CNifEffectParam*>(const_cast<CEffectParam*>(pParam)));
    if (m_spParam == 0)
        return false;
    if (m_unk_18 == 1 && m_spParam->m_nMyReferCount == -1)
        return false;
    if (m_unk_18 != 1 && m_spParam->m_nOtherReferCount == -1)
        return false;

    NiPointer<Unk_EffectNode> spRoot = new (efd::MemHint(efd::MemHint::NONE)) Unk_EffectNode(m_spParam->m_bUseLighting, m_spParam->m_bUseShadow);
    spRoot->SetName("Effect Root");
    FUN_1409f76f0(&m_spRoot, spRoot);
    m_fStartTime = (float)FUN_140a53420(pTarget);

    if (!m_spParam->m_strEffectObjectKfm.IsEmpty())
    {
        CEffectObject* pObject = new (efd::MemHint(efd::MemHint::NONE)) CEffectObject;
        m_spEffectObject = pObject;
        CString strKfm(m_spParam->m_strEffectObjectKfm);
        int nOwner = FUN_140a53390(pTarget);
        m_spEffectObject->FUN_140a53880(nOwner, strKfm, m_spParam->m_fScale);
        FUN_141bbb1e0(FUN_1403ed2d0(), m_spEffectObject.operator->(), 0, 1);
    }

    if (m_spParam->m_strLerpType.CompareNoCase("bird") == 0)
    {
        MS2Ptr<CBirdMovement> spBird(new CBirdMovement);
        spBird->SetMaxLength(m_spParam->m_fMaxLength);
        spBird->SetMinLength(m_spParam->m_fMinLength);
        spBird->FUN_141207fb0(m_spParam->m_fStep);
        spBird->SetVelocity(m_spParam->m_fVelocity);
        FUN_1411a3db0(spRoot, spBird.get());
    }

    m_kXform.m_Translate = NiPoint3(m_spParam->m_ptTranslate.x, m_spParam->m_ptTranslate.y, m_spParam->m_ptTranslate.z);
    float fRadZ = (m_spParam->m_ptRotation.z * 3.1415927f) / 180.0f;
    float fRadY = (m_spParam->m_ptRotation.y * 3.1415927f) / 180.0f;
    m_kXform.m_Rotate.FromEulerAnglesXYZ((m_spParam->m_ptRotation.x * 3.1415927f) / 180.0f, fRadY, fRadZ);
    m_kXform.m_fScale = m_spParam->m_fScale;
    if (pT->m_pPre != 0)
        m_kXform = *pT->m_pPre * m_kXform;
    if (pT->m_pPost != 0)
        m_kXform = m_kXform * *pT->m_pPost;
    spRoot->SetLocalTransform(m_kXform);
    FUN_1411a3fa0(spRoot, m_spParam->m_bOnGround);

    switch (m_spParam->m_nAttachType)
    {
    case 0:
        FUN_14154ba40(pTarget);
        break;
    case 1:
        FUN_14154bdd0(pTarget);
        break;
    case 2:
        FUN_14154c260(pTarget);
        break;
    case 3:
        FUN_14154c440(pTarget, 4);
        break;
    case 4:
        FUN_14154c440(pTarget, 5);
        break;
    }
    if (m_spTarget.FUN_1409f77a0(0))
        return false;

    FUN_141550050(FUN_1409475d0(&m_spRoot), m_spParam->m_strFilePath);
    if (FUN_14028d470(m_fDuration, 0.0f))
    {
        if (m_spParam->m_bBipedLoop)
            return false;
        m_fDuration = FUN_14154b470();
    }
    float fNow = (float)FUN_14086d260()->FUN_141473280();
    static_cast<NiNode*>(FUN_1409475f0(&m_spTarget))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), false);
    NiAVObject* pTop = static_cast<NiAVObject*>(FUN_1409475d0(&m_spTarget));
    while (pTop->GetParent() != 0)
        pTop = pTop->GetParent();
    NiNode* pOwnerNode = FUN_140a533d0(pTarget);
    if (pTop == pOwnerNode && FUN_140aac3e0(&m_spTarget, pOwnerNode))
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spTarget))->Update(fNow, false);
    else
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->Update(fNow, false);
    FUN_140a0b2a0(FUN_1409475d0(&m_spRoot));

    Unk_NifCullQuery kQuery;
    FUN_1411b8570(&kQuery);
    kQuery.m_nMode = 1;
    kQuery.m_nKind = m_unk_18;
    kQuery.m_fViewDistance = m_spParam->m_fViewDistance;
    vfunc_8(kQuery.m_aPos);
    if (!pT->m_bNoCull && !m_spParam->m_bOffSkip)
    {
        if (FUN_1411b86e0(FUN_14119f490(), &kQuery) != 0)
            return false;
    }
    if (0 < m_spParam->m_nLodSkipLevel)
    {
        if ((int)FUN_1403ed280()->FUN_1411a88c0() < m_spParam->m_nLodSkipLevel)
            return false;
    }

    if (!m_spEffectObject || !m_spParam->m_strFilePath.IsEmpty())
    {
        int nMyRefer = (m_unk_18 == 1) * m_spParam->m_nMyReferCount;
        int nOtherRefer = (m_unk_18 != 1) * m_spParam->m_nOtherReferCount;
        CString strDir("Effect");
        Unk_NodePtr kLoaded = FUN_14154d0d0(FUN_140cc2ba0(strDir, m_spParam->m_strFilePath), nMyRefer, nOtherRefer);
        static_cast<NiNode*>(FUN_1409475d0(&m_spRoot))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&kLoaded)), false);
        if (pT->m_bTagLod)
        {
            NiAVObject* pLoaded = static_cast<NiAVObject*>(FUN_1409475f0(&kLoaded));
            NiStringExtraData* pTag = static_cast<NiStringExtraData*>(FUN_14098d8d0(&DAT_143afb000, FUN_141d17b40(pLoaded, &DAT_143ae51b8)));
            if (pTag == 0)
            {
                pTag = new (efd::MemHint(efd::MemHint::NONE)) NiStringExtraData(*(NiFixedString*)&DAT_143ae50e8);
                static_cast<NiAVObject*>(FUN_1409475f0(&kLoaded))->AddExtraData(*(NiFixedString*)&DAT_143ae51b8, pTag);
            }
            else
            {
                efd::utf8string strTag(FUN_142087e50(FUN_141168130(pTag)));
                strTag += FUN_142087e50(&DAT_143ae50e8);
                pTag->SetValue(NiFixedString(strTag.c_str()));
            }
        }
        FUN_141773a90(FUN_1409a5160(FUN_1409a8b00()), FUN_1409475d0(&kLoaded));
        FUN_14154cf20(static_cast<NiAVObject*>(FUN_1409475d0(&kLoaded)));
    }

    if (FUN_14028d470(m_spParam->m_fStartDelay, 0.0f))
        vfunc_4();
    FUN_141567a10(FUN_1409475d0(&m_spRoot));
    FUN_141567330(FUN_1409475d0(&m_spRoot), m_spParam->m_bUseShadow);
    return true;
}
MS2_REPLACE_METHOD(0x1415496F0, CNifEffect, vfunc_3, 4315, 0xB8D13721);

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154a7e0
bool CNifEffect::vfunc_9()
{
    float fNow = (float)FUN_1413f9850()->GetTime(0xe001001b);
    if (m_fFadeStart <= fNow && fNow != m_fFadeStart)
    {
        float fScale = 0.0f;
        if (!FUN_14028d470(m_fFadeTime, 0.0f))
            fScale = ((m_fFadeStart + m_fFadeTime) - fNow) / m_fFadeTime;
        else
            fScale = 0.0f;
        bool bDone = fScale <= 0.0f;
        if (bDone)
            fScale = 0.0f;
        for (unsigned i = 0; i < m_aAlphaCtrls.GetCount(); ++i)
            m_aAlphaCtrls[i]->SetScale(fScale);
        if (bDone)
            m_b2d = true;
    }
    if (m_b2e)
    {
        if (m_spParam->m_bBipedLoop && m_fStartTime != 0.0f)
        {
            double dNow = FUN_14086d260()->FUN_141473280();
            float fElapsed = (float)(dNow - (double)m_fStartTime);
            if (m_fDuration <= fElapsed)
            {
                for (; m_fDuration <= fElapsed; fElapsed = fElapsed - m_fDuration)
                {
                }
                FUN_141851f90(FUN_1409475d0(&m_spRoot), fElapsed);
                m_fStartTime = (float)(dNow - (double)fElapsed);
            }
        }
    }
    if (FUN_1409849b0(&m_spModel) != 0)
    {
        NiTransform kModel = *static_cast<NiTransform*>(FUN_140a33f90(FUN_14098d0f0(&m_spModel)));
        NiTransform kLocal = kModel * m_kXform;
        FUN_140aacb60(FUN_1409475f0(&m_spRoot), &kLocal);
    }
    if (m_spEffectObject)
    {
        if (FUN_140aac3e0(&m_spRoot, 0))
        {
            const Vector3& rPos = FUN_140947900(FUN_1409475f0(&m_spRoot));
            efd::Point3 kPos(rPos.x, rPos.y, rPos.z);
            m_spEffectObject->vfunc_19(kPos);
            float aDir[4];
            FUN_1402bd040(aDir);
            float aRot[9];
            memcpy(aRot, FUN_141024c90(FUN_1409475f0(&m_spRoot)), sizeof(aRot));
            FUN_140a0b1f0(aRot, aDir);
            m_spEffectObject->vfunc_21(efd::Point3(aDir[0], aDir[1], aDir[2]));
        }
    }
    if (!CEffect::vfunc_9())
        return false;
    if ((int)FUN_1403ed280()->FUN_1411a88c0() != m_nLodLevel)
    {
        if (FUN_14028d470(m_fDuration, 0.0f))
            FUN_14154cf20(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)));
    }
    return true;
}
MS2_REPLACE_METHOD(0x14154A7E0, CNifEffect, vfunc_9, 1279, 0x40B5FA1F);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x14154acf0
// Hangs the root on the target (or on the split node) and runs the first update, as if it had started on time.
void CNifEffect::vfunc_4()
{
    if (FUN_1409475d0(&m_spTarget) != 0)
    {
        double dNow = FUN_14086d260()->FUN_141473280();
        double dNowF = (double)(float)dNow;
        double dStart = FUN_14119f3a0(this);
        float fElapsed = (float)(dNowF - dStart);
        if (!m_bSplit || FUN_1409475d0(&m_spSplit) == 0)
            static_cast<NiNode*>(FUN_1409475f0(&m_spTarget))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), true);
        else
            static_cast<NiNode*>(FUN_1409475f0(&m_spSplit))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), true);
        FUN_141851f90(FUN_1409475d0(&m_spRoot), fElapsed);
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateEffects();
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateProperties();
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->Update((float)dNow, true);
        m_fStartTime = (float)(dNowF - (double)fElapsed);
    }
    m_b2e = true;
}
MS2_REPLACE_METHOD(0x14154ACF0, CNifEffect, vfunc_4, 497, 0x164194E8);

// @0x14154aef0
void CNifEffect::vfunc_5()
{
    if (FUN_14154b5e0() && vfunc_11() != 0)
        return;
    CEffect::vfunc_5();
}
MS2_REPLACE_METHOD(0x14154AEF0, CNifEffect, vfunc_5, 63, 0x0B5C2734);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x14154af40
// Fades the model out over fFadeTime: every material alpha gets a duplicated controller (or a new fade controller).
void CNifEffect::vfunc_6(float fFadeTime)
{
    if (!m_spParam->m_bOffFadeOut)
    {
        m_fFadeStart = (float)FUN_1413f9850()->GetTime(0xe001001b);
        m_fFadeTime = fFadeTime;
        m_aAlphaCtrls.RemoveAll();
        Unk_SceneWalker kWalker(static_cast<NiObject*>(FUN_1409475d0(&m_spRoot)));
        while (NiAVObject* pObj = kWalker.Next(true))
        {
            NiProperty* pProp = pObj->GetProperty(NiProperty::MATERIAL);
            if (pProp != 0 && !FUN_14154b4a0(pProp))
                FUN_14154b630(pProp, fFadeTime);
        }
    }
}
MS2_REPLACE_METHOD(0x14154AF40, CNifEffect, vfunc_6, 311, 0xC6881624);

// @0x14154b080
void CNifEffect::vfunc_7()
{
    FUN_141773cc0(FUN_1409a5160(FUN_1409a8b00()), FUN_1409475d0(&m_spRoot));
    FUN_140a0b2a0(FUN_1409475d0(&m_spRoot));
    FUN_140a0b2a0(FUN_1409475d0(&m_spSplit));
    if (m_spEffectObject != 0)
    {
        FUN_141bbb7f0(FUN_1403ed2d0(), m_spEffectObject.operator->(), 0);
        m_spEffectObject = 0;
    }
}
MS2_REPLACE_METHOD(0x14154B080, CNifEffect, vfunc_7, 218, 0xC2FE4FBF);

// @0x14154b160
int CNifEffect::vfunc_8(void* p)
{
    FUN_140194470(p, &FUN_140947900(FUN_1409475f0(&m_spRoot)));
    return 1;
}
MS2_REPLACE_METHOD(0x14154B160, CNifEffect, vfunc_8, 64, 0xEAE8C028);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x14154b1b0
// A Node-attached effect that is still running is re-parented onto the effect scene root (keeping its world
// transform) when the owner goes away, so it can finish playing.
int CNifEffect::vfunc_11()
{
    if (m_b2c)
        return 0;
    if (m_spParam->m_nAttachType == 1)
    {
        if (!m_bSplit)
        {
            double dNow = FUN_14086d260()->FUN_141473280();
            if (dNow < m_dStartTime + (double)m_fDuration)
            {
                m_bSplit = true;
                NiNode* pSplit = new (efd::MemHint(efd::MemHint::NONE)) NiNode(0);
                FUN_1409f76f0(&m_spSplit, pSplit);
                FUN_140aacb60(FUN_1409475f0(&m_spSplit), FUN_1409478e0(FUN_1409475f0(&m_spTarget)));
                FUN_1409f76f0(&m_spTarget, FUN_1403ed280()->FUN_1411a6b10());
                FUN_140a0b2a0(FUN_1409475d0(&m_spRoot));
                static_cast<NiNode*>(FUN_1409475f0(&m_spSplit))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), false);
                static_cast<NiNode*>(FUN_1409475f0(&m_spTarget))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spSplit)), true);
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14154B1B0, CNifEffect, vfunc_11, 611, 0x5782BF21);

// @0x14154f9d0
int CNifEffect::vfunc_12()
{
    return 1;
}

// @0x14154b420
void CNifEffect::vfunc_10(bool bVisible)
{
    FUN_140a0b300(FUN_1409475f0(&m_spRoot), !bVisible);
}
MS2_REPLACE_METHOD(0x14154B420, CNifEffect, vfunc_10, 71, 0x5AABE04B);

// @0x14154b470
float CNifEffect::FUN_14154b470()
{
    return FUN_141852010(FUN_1409475d0(&m_spRoot));
}
MS2_REPLACE_METHOD(0x14154B470, CNifEffect, FUN_14154b470, 41, 0x69BAF271);

// @0x14154b4a0
// Replaces every NiAlphaController of the node by a DuplicatedAlphaController (kept in m_aAlphaCtrls).
bool CNifEffect::FUN_14154b4a0(NiObjectNET* pkNode)
{
    bool bAny = false;
    NiTimeController* pCtrl = FUN_14098dc80(pkNode);
    while (pCtrl != 0)
    {
        NiAlphaController* pAlpha = static_cast<NiAlphaController*>(FUN_14098d8d0(&NiAlphaController::ms_RTTI, pCtrl));
        pCtrl = FUN_14098de40(pCtrl);
        if (pAlpha != 0)
        {
            DuplicatedAlphaControllerPtr spDup = new (efd::MemHint(efd::MemHint::NONE)) DuplicatedAlphaController(pAlpha);
            pkNode->PrependController(spDup);
            pkNode->RemoveController(pAlpha);
            m_aAlphaCtrls.Add(spDup);
            bAny = true;
        }
    }
    return bAny;
}

// @0x14154b5e0
bool CNifEffect::FUN_14154b5e0()
{
    if (m_spParam == 0)
        return false;
    return m_spParam->m_bNotForceStop;
}
MS2_REPLACE_METHOD(0x14154B5E0, CNifEffect, FUN_14154b5e0, 72, 0x779086E4);

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154b630
// Adds an alpha controller to the material that fades its current alpha to 0 over fTime.
void CNifEffect::FUN_14154b630(NiObjectNET* pkNode, float fTime)
{
    NiFloatDataPtr spData = new (efd::MemHint(efd::MemHint::NONE)) NiFloatData;
    NiLinFloatKey* pKeys = NiNew NiLinFloatKey[2];
    pKeys[0].SetTime(0.0f);
    pKeys[0].SetValue(((NiMaterialProperty*)pkNode)->GetAlpha());
    pKeys[1].SetTime(fTime);
    pKeys[1].SetValue(0.0f);
    spData->SetAnim(pKeys, 2, NiAnimationKey::LINKEY);
    NiAlphaControllerPtr spCtrl = new (efd::MemHint(efd::MemHint::NONE)) NiAlphaController;
    NiFloatInterpolatorPtr spInterp = new (efd::MemHint(efd::MemHint::NONE)) NiFloatInterpolator(spData);
    spCtrl->SetInterpolator(spInterp, 0);
    spCtrl->SetTarget(pkNode);
    spCtrl->ResetTimeExtrema();
    spCtrl->SetCycleType(NiTimeController::CLAMP);
    spCtrl->Start(0.0f);
}
MS2_REPLACE_METHOD(0x14154B630, CNifEffect, FUN_14154b630, 1031, 0x19B4F7C1);

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154ba40
// Attach type 0: hang the effect on the target's owner node, placed relative to the named parent node.
void CNifEffect::FUN_14154ba40(Unk_EffectTarget* pTarget)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    FUN_1409f76f0(&m_spTarget, FUN_140a533d0(pTarget));
    NiNode* pParent = 0;
    if (FUN_1409849b0(&pT->m_hNode) != 0)
    {
        NiFixedString kName((const char*)m_spParam->m_strParentNode);
        NiAVObject* pFound = FUN_14098d0f0(&pT->m_hNode)->GetObjectByName(kName);
        pParent = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, pFound));
    }
    if (pParent == 0)
        pParent = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&pT->m_hNode)));
    if (m_spParam->m_bApplyNodeTransform && pParent != 0)
    {
        NiTransform kLocal = *static_cast<NiTransform*>(FUN_140a33f90(FUN_1409475f0(&m_spRoot)));
        if (!FUN_140afc5a0(&m_spParam->m_bitsApply))
        {
            NiTransform kParent = *static_cast<NiTransform*>(FUN_1409478e0(pParent));
            if (!m_spParam->m_bitsApply[0])
                kParent.m_Translate = NiPoint3(0.0f, 0.0f, 0.0f);
            if (!m_spParam->m_bitsApply[1])
                kParent.m_Rotate.MakeIdentity();
            if (!m_spParam->m_bitsApply[2])
                kParent.m_fScale = 1.0f;
            NiTransform kResult = kParent * kLocal;
            FUN_140aacb60(FUN_1409475f0(&m_spRoot), &kResult);
        }
        else
        {
            NiTransform kResult = *static_cast<NiTransform*>(FUN_1409478e0(pParent)) * kLocal;
            FUN_140aacb60(FUN_1409475f0(&m_spRoot), &kResult);
        }
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154bdd0
// Attach type 1: hang the effect on the named node of the target's model (or the equipped item's node).
void CNifEffect::FUN_14154bdd0(Unk_EffectTarget* pTarget)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    if (FUN_1409a7f70(&pT->m_hNode, 0))
        return;
    const char* pszParent = m_spParam->m_strParentNode;
    NiAVObjectPtr spFound;
    {
        NiFixedString kName(pszParent);
        spFound = FUN_14098d0f0(&pT->m_hNode)->GetObjectByName(kName);
    }
    bool bFlag = FUN_1411b02b0(&pT->m_hNode, &spFound);
    if (FUN_1409849b0(&spFound) != 0)
    {
        if (!bFlag && FUN_140a53480(pTarget) != 6)
        {
            Unk_NifPCPtr spPC(FUN_14099eef0(pTarget->FUN_140a533b0()));
            if (FUN_140aac420(&spPC) != 0)
            {
                MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2610(FUN_1409849b0(&spFound), 0, 6, true);
                bool bHasItem = false;
                if (spEquip.get() != 0)
                {
                    MS2Ptr<CItem> spItem = spEquip->GetItem();
                    bHasItem = spItem.get() != 0;
                }
                if (bHasItem)
                {
                    bool bMismatch;
                    if (FUN_1411dc670(spEquip.get()) == 0)
                    {
                        bMismatch = true;
                    }
                    else
                    {
                        MS2Ptr<CItem> spItem = spEquip->GetItem();
                        bMismatch = FUN_14052a170(spItem.get()) != FUN_140a53480(pTarget);
                    }
                    if (bMismatch)
                    {
                        NiAVObjectPtr spOther = FUN_14154d410(pTarget, pszParent, true);
                        if (FUN_1409a7f70(&spOther, 0))
                            return;
                        spFound = spOther;
                    }
                }
            }
        }
        FUN_1409f76f0(&m_spTarget, FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&spFound)));
    }
    if (m_spTarget.FUN_1409f77a0(0))
        FUN_1409f76f0(&m_spTarget, FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&pT->m_hNode)));
    FUN_14154c580();
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x14154c260
// Attach type 2: hang the effect on the parent of the named mesh node.
void CNifEffect::FUN_14154c260(Unk_EffectTarget* pTarget)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    if (!FUN_1409a7f70(&pT->m_hNode, 0))
    {
        const char* pszParent = m_spParam->m_strParentNode;
        if (pszParent != 0)
        {
            m_spModel = FUN_14154d410(pTarget, pszParent, false);
            if (FUN_1409849b0(&m_spModel) == 0)
            {
                if (FUN_140a53480(pTarget) != 6)
                    return;
            }
            else
            {
                if (FUN_140a0b000(FUN_14098d0f0(&m_spModel)) != 0)
                    FUN_1409f76f0(&m_spTarget, FUN_140a0b000(FUN_14098d0f0(&m_spModel)));
            }
            if (m_spTarget.FUN_1409f77a0(0))
                FUN_1409f76f0(&m_spTarget, FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&pT->m_hNode)));
            FUN_14154c580();
            if (FUN_1409849b0(&m_spModel) != 0)
                FUN_140aacb60(FUN_1409475f0(&m_spRoot), FUN_140a33f90(FUN_14098d0f0(&m_spModel)));
        }
    }
}

// @0x14154c440
// Attach types 3 / 4: hang the effect on the model of the weapon in equip slot nSlot.
void CNifEffect::FUN_14154c440(Unk_EffectTarget* pTarget, int nSlot)
{
    Unk_NifPCPtr spPC(FUN_14099eef0(pTarget->FUN_140a533b0()));
    if (FUN_140c206b0(&spPC, 0))
        return;
    MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e1860(nSlot, 6, 0);
    if (spEquip == 0)
        return;
    m_spTarget = reinterpret_cast<Unk_NifEquipView*>(spEquip.operator->())->FUN_1411dd700();
    FUN_14154c580();
}
MS2_REPLACE_METHOD(0x14154C440, CNifEffect, FUN_14154c440, 307, 0x560D08B0);

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154c580
// Wraps the root in a SeparateNode when only some parts of the parent's transform are followed, and makes the root
// relative to the target when the node transform is not applied.
void CNifEffect::FUN_14154c580()
{
    if (!FUN_140afc5a0(&m_spParam->m_bitsUpdate))
    {
        NiPointer<Unk_SeparateNode> spSep = new (efd::MemHint(efd::MemHint::NONE)) Unk_SeparateNode(m_spParam->m_bitsUpdate.m_bits);
        spSep->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), false);
        FUN_1409f76f0(&m_spRoot, spSep);
    }
    if (!m_spParam->m_bApplyNodeTransform)
    {
        if (FUN_1409475d0(&m_spTarget) != 0)
        {
            NiTransform kInverse;
            static_cast<NiTransform*>(FUN_1409478e0(FUN_1409475f0(&m_spTarget)))->Invert(kInverse);
            NiTransform kLocal = *static_cast<NiTransform*>(FUN_140a33f90(FUN_1409475f0(&m_spRoot)));
            NiTransform kResult = kInverse * kLocal;
            FUN_140aacb60(FUN_1409475f0(&m_spRoot), &kResult);
        }
    }
}
MS2_REPLACE_METHOD(0x14154C580, CNifEffect, FUN_14154c580, 611, 0x338E1372);

// MS2-FUNCTIONAL: diagnostic only: builds the same log text with the exe's string-format helpers
// @0x14154c7f0
// Logs the "LOD level" line with a description of the target node / equipped item.
void CNifEffect::FUN_14154c7f0(Unk_EffectTarget* pTarget)
{
    CString strWhere;
    Unk_NifPCPtr spPC(FUN_14099eef0(pTarget->FUN_140a533b0()));
    if (FUN_140aac420(&spPC) != 0 && FUN_1409475d0(&m_spTarget) != 0)
    {
        Unk_NodePtr kTarget(m_spTarget.m_p);
        MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2610(static_cast<NiAVObject*>(FUN_1409475d0(&kTarget)), 0, 6, false);
        if (spEquip.get() == 0)
        {
            if (FUN_1409849b0(&m_spModel) == 0)
            {
                CString strParent;
                if (FUN_140a0b000(FUN_1409475f0(&kTarget)) == 0)
                    strParent = "empty";
                else
                    strParent = FUN_142087e50(FUN_1409a8b90(static_cast<NiAVObject*>(FUN_1409475f0(&kTarget))));
                CString strNode(FUN_142087e50(FUN_1409a8b90(static_cast<NiAVObject*>(FUN_1409475f0(&kTarget)))));
                strWhere = FUN_140741200("targetNode:{0}, parent:{1}", strNode, strParent);
            }
            else
            {
                NiAVObjectPtr spModel = m_spModel;
                MS2Ptr<CEquipItem> spModelEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2610(FUN_1409849b0(&spModel), 0, 6, false);
                if (spModelEquip.get() == 0)
                {
                    CString strNode(FUN_142087e50(FUN_1409a8b90(FUN_14098d0f0(&spModel))));
                    strWhere = FUN_140536a50("targetNode:{0} in character", strNode);
                }
                else
                {
                    unsigned nItemId = FUN_1411dc820(spModelEquip.get());
                    CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
                    strWhere = Unk_SocketFormat("targetNode:{0}, itemID:{1}({2})", CString(FUN_142087e50(FUN_1409a8b90(FUN_14098d0f0(&spModel)))), nItemId, CString((const wchar_t*)strName));
                }
            }
        }
        else
        {
            unsigned nItemId = FUN_1411dc820(spEquip.get());
            CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
            strWhere = Unk_SocketFormat("targetNode:{0}, itemID:{1}({2})", CString(FUN_142087e50(FUN_1409a8b90(static_cast<NiAVObject*>(FUN_1409475f0(&kTarget))))), nItemId, CString((const wchar_t*)strName));
        }
    }
    if (GetLogString() != 0)
        Unk_NifLog3(GetLogString(), 0xc, 0x133, L"LOD level [{0}] [{1}] [{2}]", m_nLodLevel, m_spParam->m_strFilePath, strWhere);
}
MS2_REPLACE_METHOD(0x14154C7F0, CNifEffect, FUN_14154c7f0, 1827, 0x12B3C2BF);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x14154cf20
// Re-applies the "Eff_LOD=<n>" extra-data levels of the model: parts above the current quality level are culled.
void CNifEffect::FUN_14154cf20(NiAVObject* pkRoot)
{
    int nLevel = (int)FUN_1403ed280()->FUN_1411a88c0();
    if (m_nLodLevel != nLevel)
    {
        m_nLodLevel = nLevel;
        Unk_SceneWalker kWalker(pkRoot);
        while (NiAVObject* pObj = kWalker.Next(true))
        {
            if (FUN_14098dad0(pObj) != true)
            {
                NiStringExtraData* pTag = static_cast<NiStringExtraData*>(FUN_14098d8d0(&DAT_143afb000, FUN_141d17b40(pObj, &DAT_143ae51b8)));
                if (pTag != 0)
                {
                    int nLod = 0;
                    std::string strTag(FUN_142087e50(FUN_141168130(pTag)));
                    size_t nPos = strTag.find("Eff_LOD=", 0);
                    if (nPos != std::string::npos)
                    {
                        nLod = atoi(strTag.c_str() + 8 + nPos);
                        if (m_nLodLevel < nLod)
                            FUN_140a0b300(pObj, true);
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14154CF20, CNifEffect, FUN_14154cf20, 425, 0xB022B7AF);

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154d0d0
// Loads the nif (cache) and returns a plain NiNode wrapping it; the model remembers its path in extra data.
Unk_NodePtr CNifEffect::FUN_14154d0d0(const CString& strPath, int nA, int nB)
{
    Unk_NodePtr kWrapper(new (efd::MemHint(efd::MemHint::NONE)) NiNode(0));
    NiAVObjectPtr spModel = FUN_140a0afd0()->Load(CString(strPath), false, 5, nA, nB);
    Unk_NodePtr kNode(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&spModel)));
    if (FUN_1409475d0(&kNode) != 0)
    {
        NiAVObject* pNode = static_cast<NiAVObject*>(FUN_1409475f0(&kNode));
        if (FUN_141d17b40(pNode, &DAT_143ae5198) == 0)
        {
            NiStringExtraData* pPath = new (efd::MemHint(efd::MemHint::NONE)) NiStringExtraData(NiFixedString((const char*)strPath));
            static_cast<NiAVObject*>(FUN_1409475f0(&kNode))->AddExtraData(*(NiFixedString*)&DAT_143ae5198, pPath);
        }
        FUN_14154fda0(FUN_1409475f0(&kNode));
        static_cast<NiNode*>(FUN_1409475f0(&kWrapper))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&kNode)), false);
    }
    return kWrapper;
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154d410
// Finds the model node pszName of the target: through the equipment of the owning player, else by walking the
// owner's scene graph for a node of that name worn in the right slot.
NiAVObjectPtr CNifEffect::FUN_14154d410(Unk_EffectTarget* pTarget, const char* pszName, bool bFlag)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    if (pTarget == 0 || FUN_1409a7f70(&pT->m_hNode, 0) || pszName == 0)
        return NiAVObjectPtr(0);
    Unk_NifPCPtr spPC(FUN_14099eef0(pTarget->FUN_140a533b0()));
    if (FUN_140c206b0(&spPC, 0))
        return NiAVObjectPtr(0);
    NiAVObjectPtr spFound(0);
    if (FUN_140a53440(pTarget) != 0)
    {
        CString strName(pszName);
        spFound = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2a60(FUN_140a53440(pTarget), strName, bFlag);
    }
    if (FUN_1409a7f70(&spFound, 0))
    {
        int nKind = FUN_140a53480(pTarget);
        Unk_SceneWalker kWalker(FUN_1409849b0(&pT->m_hNode));
        while (NiAVObject* pObj = kWalker.Next(true))
        {
            if (!FUN_141068d50(FUN_1409a8b90(pObj), pszName))
            {
                MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2610(pObj, 1, nKind, bFlag);
                bool bSkip;
                if (spEquip.IsNull())
                {
                    bSkip = true;
                }
                else
                {
                    MS2Ptr<CItem> spItem = spEquip->GetItem();
                    bSkip = spItem.get() == 0;
                }
                if (!bSkip)
                {
                    bool bOther;
                    if (nKind == 6)
                    {
                        bOther = false;
                    }
                    else
                    {
                        MS2Ptr<CItem> spItem = spEquip->GetItem();
                        bOther = FUN_14052a170(spItem.get()) != nKind;
                    }
                    if (!bOther)
                    {
                        FUN_1409fabf0(&spFound, pObj);
                        break;
                    }
                }
            }
        }
    }
    return spFound;
}
MS2_REPLACE_METHOD(0x14154D410, CNifEffect, FUN_14154d410, 1108, 0x1CF9A73C);

// ============================================================================================================
// CNiStreamLoadThread / CNifLoadingService (0x1415509b0-0x141556920)
// ============================================================================================================
class Unk_NifFileMgr
{
public:
    // Reads a file of the data tree into a buffer (freed by the caller); pstrDir receives its directory.
    int FUN_1403972f0(const char* pszPath, void** ppBuf, int* pnSize, std::string* pstrDir);
    int FUN_1403987d0(std::string strPath);                         // the file exists in the data tree
    int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int nA, bool bB, bool bC);   // load an xml file
};
Unk_NifFileMgr* FUN_140166420();
class Unk_NifGate { public: bool FUN_1406af080(); };                 // the loader should read on the caller's thread
Unk_NifGate* FUN_1406aeee0();
void FUN_140659080(Unk_140659080& kStartup, unsigned nError);        // record the start-up error
unsigned FUN_140869420();                                            // random seed
void FUN_14028e7c0(CString& strPath);                                // normalize a path in place
// NiStream accessors of the exe's layout: the header's inline NiStream::GetSearchPath/GetObjectCount/GetObjectAt read the
// header layout (0x4c8 bytes, search path +0x130) and return null/garbage on the exe's 0x5d0-byte NiStream
struct Unk_NiStreamLayout
{
    char pad0[0x238];
    NiSearchPath* m_pkSearchPath;                                    // +0x238
    char pad240[0x280 - 0x240];
    NiTLargeArray<NiObjectPtr, NiTNewInterface<NiObjectPtr> > m_kTopObjects;                     // +0x280
};

// The NiStream object array accessors (this TU's copies; NiMain's header does not emit them here)
template unsigned int NiTLargeArray<NiObjectPtr, NiTNewInterface<NiObjectPtr> >::GetSize() const;     // @0x14155d9c0
template const NiObjectPtr& NiTLargeArray<NiObjectPtr, NiTNewInterface<NiObjectPtr> >::GetAt(unsigned int) const;   // @0x14155d580
template bool efd::SmartPointer<NiAVObject>::operator!=(NiAVObject*) const;                   // @0x14155be40 (CreateCachedNif)

// @0x14155d9a0
NiSearchPath* FUN_14155d9a0(NiStream* pStream)
{
    return reinterpret_cast<Unk_NiStreamLayout*>(pStream)->m_pkSearchPath;
}

// @0x14155d950
unsigned FUN_14155d950(NiStream* pStream)
{
    return reinterpret_cast<Unk_NiStreamLayout*>(pStream)->m_kTopObjects.GetSize();
}

// @0x14155d900
NiObject* FUN_14155d900(NiStream* pStream, unsigned nIndex)
{
    if (nIndex < reinterpret_cast<Unk_NiStreamLayout*>(pStream)->m_kTopObjects.GetSize())
        return reinterpret_cast<Unk_NiStreamLayout*>(pStream)->m_kTopObjects.GetAt(nIndex);
    return NULL;
}
void FUN_1403a1280(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const char* const& pszArg);

CNiStreamLoadThread* TSingleton<CNiStreamLoadThread>::s_instance = 0;
inline TSingleton<CNiStreamLoadThread>::TSingleton() { s_instance = static_cast<CNiStreamLoadThread*>(this); }

// @0x1415509b0
CNiStreamLoadThread::CNiStreamLoadThread() : m_mapQueued(10), m_lstQueue(10), m_mapDone(10), m_spPalette(0)
{
    m_nPause = 0;
    m_hStop = 0;
    m_nStop = 0;
    m_hWork = CreateSemaphoreA(0, 0, 0x7fffffff, 0);
    m_pParam = 0;
}

// MS2-FUNCTIONAL: map walk / lock scope temporaries differ from the exe
// @0x141550af0
CNiStreamLoadThread::~CNiStreamLoadThread()
{
    if (Unk_LockGuard kGuard = m_kDoneLock)
    {
    }
    else
    {
        POSITION pos = m_mapDone.GetHeadPosition();
        while (pos != 0)
        {
            NiStream* pStream = m_mapDone.GetValueAt(pos);
            delete pStream;
            m_mapDone.GetNext(pos);
        }
        m_mapDone.RemoveAll();
    }
    if (m_hWork != 0)
        CloseHandle(m_hWork);
    if (m_hStop != 0)
        CloseHandle(m_hStop);
    m_spPalette = 0;
}

// MS2-FUNCTIONAL: the wait loop is restructured
// @0x141550cf0
unsigned CNiStreamLoadThread::vfunc_1(void* pParam, Unk_140659080& kStartup)
{
    m_pParam = pParam;
    m_hStop = CreateEventA(0, 0, 0, 0);
    if (m_hStop == 0)
    {
        FUN_140659080(kStartup, 0x80004005);
        return 0xffffffff;
    }
    kStartup.FUN_1401d42d0();
    srand(FUN_140869420());
    for (;;)
    {
        if (m_nPause == 0)
        {
            WaitForSingleObject(m_hWork, 0xffffffff);
            if (m_nStop != 0)
                break;
            CString strPath;
            if (Unk_LockGuard kGuard = m_kQueueLock)
            {
            }
            else
            {
                if (m_lstQueue.IsEmpty())
                    continue;
                strPath = m_lstQueue.RemoveHead();
                m_mapQueued.RemoveKey(strPath);
            }
            Load(CString(strPath), 1);
        }
        if (WaitForSingleObject(m_hStop, 10) == 0)
            break;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141550CF0, CNiStreamLoadThread, vfunc_1, 544, 0x203BDC14);

// @0x141550f20
void CNiStreamLoadThread::Stop()
{
    if (m_hStop != 0)
        SetEvent(m_hStop);
    if (m_hWork != 0)
    {
        m_nStop = 1;
        ReleaseSemaphore(m_hWork, 1, 0);
        FUN_1401d3510(0xffffffff);
    }
}
MS2_REPLACE_METHOD(0x141550F20, CNiStreamLoadThread, Stop, 103, 0xD1E7D55A);

// @0x141550f90
void CNiStreamLoadThread::Enqueue(CString strPath)
{
    if (!strPath.IsEmpty())
    {
        FUN_14028e7c0(strPath);
        if (Unk_LockGuard kGuard = m_kQueueLock)
        {
        }
        else
        {
            if (FUN_1406aeee0()->FUN_1406af080())
            {
                Load(CString(strPath), 1);
                return;
            }
            if (m_mapQueued.Lookup(strPath) == 0)
            {
                POSITION pos = m_lstQueue.AddTail(strPath);
                m_mapQueued.SetAt(strPath, pos);
                ReleaseSemaphore(m_hWork, 1, 0);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141550F90, CNiStreamLoadThread, Enqueue, 335, 0x1FBE764A);

// @0x1415510f0
void CNiStreamLoadThread::SetTexturePalette(NiPointer<NiTexturePalette> spPalette)
{
    m_spPalette = spPalette;
}
MS2_REPLACE_METHOD(0x1415510F0, CNiStreamLoadThread, SetTexturePalette, 63, 0xBE5723D4);

// MS2-FUNCTIONAL: lock scope and temporaries differ from the exe
// @0x141551140
NiStream* CNiStreamLoadThread::Get(CString strPath)
{
    FUN_14028e7c0(strPath);
    Dequeue(CString(strPath));
    NiStream* pStream = 0;
    if (Unk_LockGuard kGuard = m_kDoneLock)
    {
    }
    else if (m_mapDone.Lookup(strPath, pStream))
    {
        m_mapDone.RemoveKey(strPath);
        return pStream;
    }
    return Load(CString(strPath), 0);
}
MS2_REPLACE_METHOD(0x141551140, CNiStreamLoadThread, Get, 363, 0xE7250E3B);

// @0x1415512c0
void CNiStreamLoadThread::Pause() { m_nPause = 1; }
// @0x1415512e0
void CNiStreamLoadThread::Resume() { m_nPause = 0; }

// @0x141551300
void CNiStreamLoadThread::Dequeue(CString strPath)
{
    if (!strPath.IsEmpty())
    {
        FUN_14028e7c0(strPath);
        if (Unk_LockGuard kGuard = m_kQueueLock)
        {
        }
        else
        {
            ATL::CRBMap<CString, POSITION>::CPair* pPair = m_mapQueued.Lookup(strPath);
            if (pPair != 0)
            {
                m_lstQueue.RemoveAt(pPair->m_value);
                m_mapQueued.RemoveAt(pPair);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1415512C0, CNiStreamLoadThread, Pause, 18, 0x79DC8588);

// MS2-FUNCTIONAL: big function: codegen (temporaries / branch layout) not byte-identical to the exe
// @0x1415513e0
NiStream* CNiStreamLoadThread::Load(CString strPath, int bKeep)
{
    FUN_14028e7c0(strPath);
    // the exe's NiStream is 0x5d0 bytes (this tree's header: 0x4c8): its ctor and Load write past a header-sized block
    NiStream* pStream = ::new (efd::MemObject::operator new(0x5d0, EE_MEMHINT_NONE)) NiStream;
    pStream->SetTexturePalette(m_spPalette);
    std::string strDir;
    void* pBuf;
    int nSize;
    if (FUN_140166420()->FUN_1403972f0(strPath, &pBuf, &nSize, &strDir))
    {
        FUN_14155d9a0(pStream)->SetReferencePath(strDir.c_str());
        if (!pStream->Load(static_cast<char*>(pBuf), nSize))
        {
            delete pStream;
            const char* pszPath = strDir.c_str();
            FUN_1403a1280(GetLogString(), 1, 0x13, L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4[{0}]", pszPath);
            return 0;
        }
        NiFree(pBuf);
    }
    NiStream* pFound = 0;
    if (pStream != 0 && FUN_14155d950(pStream) != 0)
    {
        if (bKeep == 0)
            return pStream;
        if (Unk_LockGuard kGuard = m_kDoneLock)
        {
        }
        else if (!m_mapDone.Lookup(strPath, pFound))
        {
            m_mapDone.SetAt(strPath, pStream);
            return pStream;
        }
    }
    delete pStream;
    return pFound;
}
MS2_REPLACE_METHOD(0x1415513E0, CNiStreamLoadThread, Load, 1055, 0xC7CEE07E);

// ============================================================================================================
// CNifLoadingService
// ============================================================================================================
#include "ms2/commonfiles/crashmanager.h"

extern int DAT_143ae1f20;                                           // the render device is lost
extern int DAT_1439ed00c;                                           // the caches are enabled
extern char DAT_143d6eb58;                                          // class descriptor handed to the lookup FUN_14098d8d0

CNifLoadingService* TSingleton<CNifLoadingService>::s_instance = 0;
inline TSingleton<CNifLoadingService>::TSingleton() { s_instance = static_cast<CNifLoadingService*>(this); }
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CNifLoadingService);
#ifndef MS2_HOOK_DLL
CLockCriticalSection DAT_143ae1f28;                                 // guards the nif caches (initializer 0x1400fa4e0)
CLockCriticalSection DAT_143ae1f58;                                 // guards the texture cache (initializer 0x1400fa510)
#else
extern CLockCriticalSection DAT_143ae1f28;
extern CLockCriticalSection DAT_143ae1f58;
#endif

CCrashManager* FUN_140a44830();
void* FUN_140994450();
void FUN_1411d7c70(void* pObj, bool (*pfn)(char, void*), CNifLoadingService* pOwner);
void FUN_1411d7c10(void* pObj, bool (*pfn)(void*), CNifLoadingService* pOwner);
void FUN_1414fe370(void* pObj, bool (*pfn)(char, void*));
void FUN_1414fe240(void* pObj, bool (*pfn)(void*));
void FUN_1411ab770(efd::IDependencyRegistrar* pRegistrar, int nRequired);
void FUN_1411ab7a0(efd::IDependencyRegistrar* pRegistrar, int nRequired);
void FUN_1411ab740(efd::IDependencyRegistrar* pRegistrar, int nRequired);
struct Unk_NifDepSix : efd::ISystemService { static const efd::ClassID CLASS_ID = 0x06100006; };
void FUN_1410db4c0(efd::IDependencyRegistrar* pRegistrar, int nRequired);
void* FUN_1409f7c90();
__int64 FUN_14161bdc0(void* pObj);                                  // pagefile use, MB
void* FUN_1414a56c0();
int FUN_1422e9e50(void* pObj);                                      // graphics allocator bytes in use
void FUN_1412102e0(void* pObj);                                     // CFilePreload: stop
CNiStreamLoadThread* FUN_1414a5720();
void FUN_1414a26b0();
extern char DAT_143afa930;                                          // NiRTTI table entry: NiSourceTexture
typedef efd::SmartPointer<NiTexture> NiTexturePtr;
NiTexture* FUN_14097fbf0(NiTexturePtr* pHandle);                    // handle -> texture pointer
NiTexture* FUN_140a5acb0(NiTexturePtr* pHandle);                    // handle -> texture pointer (non-const)
unsigned FUN_14098dea0(NiRefObject* pObject);                       // reference count
NiTexture* FUN_140a5ac80(NiTexturePtr* pHandle);                    // handle -> texture pointer
NiPixelData* FUN_140a5ac70(NiPixelDataPtr* pHandle);                // handle -> pixel data pointer
void FUN_1409fabf0(NiAVObjectPtr* pHandle, void* pNode);            // assign a node to a handle
NiPixelData* FUN_140980440(NiSourceTexture* pTexture);              // source pixel data
void FUN_141562500(NiSourceTexture* pTexture, NiPixelData* pPixels);    // set the source pixel data
void FUN_140399100(CString strPattern, CString strDirectory, ATL::CAtlArray<CString>& aOut, CString strExclude, bool bLocalOnly);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x141551810
CNifLoadingService::CNifLoadingService() : m_mapNif(10), m_mapTex(10)
{
    m_dLifetime = 120.0;
    m_dConfigLifetime = 0.0;
    m_bShutdown = 0;
    m_kNifCount.nNotCache = 0;
    m_kNifCount.nForceKeep = 0;
    m_kNifCount.nMySkill = 0;
    m_kNifCount.nOtherSkill = 0;
    m_kNifCount.nNPC = 0;
    m_kNifCount.nDependTime = 0;
    m_kTexCount.nNotCache = 0;
    m_kTexCount.nForceKeep = 0;
    m_kTexCount.nMySkill = 0;
    m_kTexCount.nOtherSkill = 0;
    m_kTexCount.nNPC = 0;
    m_kTexCount.nDependTime = 0;
    m_bRefreshTextures = 0;
    m_kSweepTimer.FUN_140268840();
}
#endif

// @0x141551a10
CNifLoadingService::~CNifLoadingService()
{
}

// @0x141551ac0
const char* CNifLoadingService::GetDisplayName() const
{
    return "NifLoadingService";
}
MS2_REPLACE_METHOD(0x141551AC0, CNifLoadingService, GetDisplayName, 13, 0x4E463830);

// @0x141551ae0
void CNifLoadingService::ClearNifCache()
{
    if (Unk_LockGuard kGuard = DAT_143ae1f28)
    {
    }
    else
    {
        m_mapOtherPool.clear();
        m_mapMyPool.clear();
        m_mapNif.RemoveAll();
        m_mapWeightDoc.clear();
    }
}
MS2_REPLACE_METHOD(0x141551AE0, CNifLoadingService, ClearNifCache, 142, 0xA1774090);

// @0x141551b80
void CNifLoadingService::ClearTextureCache()
{
    if (Unk_LockGuard kGuard = DAT_143ae1f58)
    {
    }
    else
    {
        m_mapTex.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x141551B80, CNifLoadingService, ClearTextureCache, 85, 0x9CEC3DE2);

// @0x141551be0
void CNifLoadingService::ClearCaches()
{
    ClearNifCache();
    ClearTextureCache();
}
MS2_REPLACE_METHOD(0x141551BE0, CNifLoadingService, ClearCaches, 34, 0xA6AAFB20);

// @0x141551c10
void CNifLoadingService::PreloadEffectNifs()
{
    ATL::CAtlArray<CString> aFiles;
    FUN_140399100(CString(".nif"), CString("./Data/Resource/Model/Effect/BG/Perform"), aFiles, CString(""), false);
    if (m_bShutdown != 0)
        return;
    for (unsigned i = 0; i < aFiles.GetCount(); ++i)
        Preload(CString(aFiles[i]), false, 5);
}
MS2_REPLACE_METHOD(0x141551C10, CNifLoadingService, PreloadEffectNifs, 402, 0xFF4C9F2D);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141551db0
bool CNifLoadingService::IsCached(CString strPath)
{
    if (strPath == "")
        return false;
    FUN_14028e7c0(strPath);
    Unk_LockGuard kGuard(DAT_143ae1f28);
    if (kGuard == 0 && DAT_1439ed00c != 0 && m_mapNif.Lookup(strPath) != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x141551DB0, CNifLoadingService, IsCached, 223, 0xDEDF03BC);

// @0x141554ce0
void CNifLoadingService::LowerLifetime(double dSeconds)
{
    if (dSeconds < m_dLifetime)
        m_dLifetime = dSeconds;
}
MS2_REPLACE_METHOD(0x141554CE0, CNifLoadingService, LowerLifetime, 52, 0xD933971D);

// @0x141554d20
void CNifLoadingService::ResetLifetime()
{
    if (FUN_14028d470((float)m_dConfigLifetime, 0.0f) == 0)
        m_dLifetime = m_dConfigLifetime;
    else
        m_dLifetime = 120.0;
}
MS2_REPLACE_METHOD(0x141554D20, CNifLoadingService, ResetLifetime, 91, 0xD97A29F5);

// @0x141554d90
void CNifLoadingService::SetLifetime(double dSeconds)
{
    m_dConfigLifetime = dSeconds;
    if (!FUN_14028d470((float)dSeconds, 0.0f))
        m_dLifetime = dSeconds;
}
MS2_REPLACE_METHOD(0x141554D90, CNifLoadingService, SetLifetime, 79, 0xCC07C8F2);

// @0x141554df0
bool CNifLoadingService::OnDeviceReset(char bBefore, void* pRenderer)
{
    void* pkRenderer = pRenderer;
    if (pkRenderer != 0)
    {
        if ((unsigned char)bBefore == 0)
        {
            DAT_143ae1f20 = 0;
            FUN_140a44830()->FUN_1401ce2f0("\n *Reset Device [Pagefile %d MB] [GFXSysAlloc %d MB]",
                FUN_14161bdc0(FUN_1409f7c90()), FUN_1422e9e50(FUN_1414a56c0()) / 0x100000);
        }
        else
        {
            FUN_140a44830()->FUN_1401ce2f0("\n *beforeReset Device [Pagefile %d MB] [GFXSysAlloc %d MB]",
                FUN_14161bdc0(FUN_1409f7c90()), FUN_1422e9e50(FUN_1414a56c0()) / 0x100000);
        }
    }
    return true;
}

// @0x141554ee0
bool CNifLoadingService::OnDeviceLost(void* pRenderer)
{
    DAT_143ae1f20 = 1;
    FUN_140a44830()->FUN_1401ce2f0("\n *Lost Device [Pagefile %d MB] [GFXSysAlloc %d MB]",
        FUN_14161bdc0(FUN_1409f7c90()), FUN_1422e9e50(FUN_1414a56c0()) / 0x100000);
    return true;
}

// @0x141555ce0
efd::SyncResult CNifLoadingService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    FUN_1411ab770(pRegistrar, 1);
    FUN_1411ab7a0(pRegistrar, 1);
    FUN_1411ab740(pRegistrar, 1);
    pRegistrar->AddDependency<Unk_NifDepSix>(1);
    FUN_1410db4c0(pRegistrar, 1);
    pRegistrar->AddDependency<efd::AssetFactoryManager>(1);
    return efd::SyncResult_Success;
}
MS2_REPLACE_METHOD(0x141555CE0, CNifLoadingService, OnPreInit, 114, 0xA912D745);

// @0x141555d60
efd::AsyncResult CNifLoadingService::OnInit()
{
    void* pNotifier = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (pNotifier != 0)
    {
        FUN_1411d7c70(pNotifier, OnDeviceReset, this);
        FUN_1411d7c10(pNotifier, OnDeviceLost, this);
    }
    FUN_140a44830()->FUN_1401ce3d0(TFunctor<void, EmptyParam>(this, &CNifLoadingService::LogCounts));
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD(0x141555D60, CNifLoadingService, OnInit, 241, 0xD84583A3);

// @0x141555e60
efd::AsyncResult CNifLoadingService::OnTick()
{
    Sweep();
    return efd::AsyncResult_Pending;
}
MS2_REPLACE_METHOD(0x141555E60, CNifLoadingService, OnTick, 29, 0xA5EF1433);

// @0x141555e90
efd::AsyncResult CNifLoadingService::OnShutdown()
{
    void* pNotifier = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (pNotifier != 0)
    {
        FUN_1414fe370(pNotifier, OnDeviceReset);
        FUN_1414fe240(pNotifier, OnDeviceLost);
    }
    m_bShutdown = 1;
    if (FUN_140ab7a10() != 0)
        FUN_1412102e0(FUN_140ab7a10());
    if (FUN_1414a5720() != 0)
    {
        FUN_1414a5720()->Stop();
        FUN_1414a26b0();
    }
    ClearTextureCache();
    ClearNifCache();
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD(0x141555E90, CNifLoadingService, OnShutdown, 172, 0x4D338AB0);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141556410
void CNifLoadingService::RefreshTextures()
{
    if (m_bRefreshTextures != 0)
    {
        if (Unk_LockGuard kGuard = DAT_143ae1f58)
        {
        }
        else
        {
            POSITION pos = m_mapTex.GetHeadPosition();
            while (pos != 0)
            {
                POSITION posCur = pos;
                m_mapTex.GetNext(pos);
                ATL::CRBMap<Unk_NifTexKey, CCachedTexturePtr>::CPair* pPair = m_mapTex.GetAt(posCur);
                if (static_cast<CCachedTexture*>(pPair->m_value) != 0)
                {
                    if (FUN_1401d1320(&pPair->m_value->m_kFile) && static_cast<CCachedTexture*>(pPair->m_value) != 0)
                    {
                        NiSourceTexture* pTexture = static_cast<NiSourceTexture*>(
                            FUN_14098d8d0(&DAT_143afa930, FUN_14097fbf0(&pPair->m_value->m_spData)));
                        NiPixelDataPtr spOld = FUN_140980440(pTexture);
                        if (spOld != 0)
                            FUN_141562500(pTexture, 0);
                        pTexture->LoadPixelDataFromFile();
                        pPair->m_value->m_dLastUse = FUN_14086d260()->FUN_141473280();
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141556410, CNifLoadingService, RefreshTextures, 496, 0xD8D4D918);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1415543e0
void CNifLoadingService::Sweep()
{
    if (DAT_143ae1f20 != 1)
    {
        float fNow = (float)FUN_14086d260()->FUN_141473280();
        if (m_kSweepTimer.FUN_140268870(60000) != 0)
        {
            m_kNifCount.nNotCache = 0;
            m_kNifCount.nForceKeep = 0;
            m_kNifCount.nMySkill = 0;
            m_kNifCount.nOtherSkill = 0;
            m_kNifCount.nNPC = 0;
            m_kNifCount.nDependTime = 0;
            if (Unk_LockGuard kGuard = DAT_143ae1f28)
            {
            }
            else
            {
                POSITION pos = m_mapNif.GetHeadPosition();
                while (pos != 0)
                {
                    POSITION posCur = pos;
                    m_mapNif.GetNext(pos);
                    ATL::CRBMap<CString, CCachedNifPtr>::CPair* pPair = m_mapNif.GetAt(posCur);
                    CCachedNif* pEntry = pPair->m_value;
                    if (FUN_1409849b0(&pEntry->m_spData) == 0)
                    {
                        m_mapNif.RemoveAt(posCur);
                    }
                    else
                    {
                        bool bExpired = false;
                        switch (pPair->m_value->m_nClass)
                        {
                        case 0:
                            bExpired = true;
                            ++m_kNifCount.nNotCache;
                            break;
                        case 1:
                            ++m_kNifCount.nForceKeep;
                            break;
                        case 2:
                            ++m_kNifCount.nMySkill;
                            break;
                        case 3:
                            ++m_kNifCount.nOtherSkill;
                            bExpired = pPair->m_value->m_dLastUse + m_dLifetime < (double)fNow;
                            break;
                        case 4:
                            ++m_kNifCount.nNPC;
                            bExpired = pPair->m_value->m_dLastUse + m_dLifetime < (double)fNow;
                            break;
                        case 5:
                            ++m_kNifCount.nDependTime;
                            bExpired = pPair->m_value->m_dLastUse + m_dLifetime < (double)fNow;
                            break;
                        }
                        unsigned nRefs = FUN_14098dea0(FUN_14098d0f0(&pPair->m_value->m_spData));
                        if (nRefs < 2 && bExpired)
                        {
                            const CString& strKey = m_mapNif.GetKeyAt(posCur);
                            PoolMap::iterator itMy = m_mapMyPool.find(strKey);
                            if (itMy != m_mapMyPool.end())
                                m_mapMyPool.erase(itMy);
                            PoolMap::iterator itOther = m_mapOtherPool.find(strKey);
                            if (itOther != m_mapOtherPool.end())
                                m_mapOtherPool.erase(itOther);
                            m_mapNif.RemoveAt(posCur);
                        }
                    }
                }
            }
            m_kTexCount.nNotCache = 0;
            m_kTexCount.nForceKeep = 0;
            m_kTexCount.nMySkill = 0;
            m_kTexCount.nOtherSkill = 0;
            m_kTexCount.nNPC = 0;
            m_kTexCount.nDependTime = 0;
            if (Unk_LockGuard kTexGuard = DAT_143ae1f58)
            {
            }
            else
            {
                POSITION pos = m_mapTex.GetHeadPosition();
                while (pos != 0)
                {
                    POSITION posCur = pos;
                    m_mapTex.GetNext(pos);
                    ATL::CRBMap<Unk_NifTexKey, CCachedTexturePtr>::CPair* pPair = m_mapTex.GetAt(posCur);
                    if (FUN_14097fbf0(&pPair->m_value->m_spData) == 0)
                    {
                        m_mapTex.RemoveAt(posCur);
                    }
                    else
                    {
                        int nRefs = FUN_14098dea0(FUN_140a5acb0(&pPair->m_value->m_spData));
                        if (nRefs > 1)
                            pPair->m_value->m_dLastUse = (double)fNow;
                        bool bExpired = false;
                        switch (pPair->m_value->m_nClass)
                        {
                        case 0:
                            ++m_kTexCount.nNotCache;
                            bExpired = true;
                            break;
                        case 1:
                            ++m_kTexCount.nForceKeep;
                            break;
                        case 2:
                            ++m_kTexCount.nMySkill;
                            break;
                        case 3:
                            ++m_kTexCount.nOtherSkill;
                            bExpired = pPair->m_value->m_dLastUse + m_dLifetime < (double)fNow;
                            break;
                        case 4:
                            ++m_kTexCount.nNPC;
                            bExpired = pPair->m_value->m_dLastUse + m_dLifetime < (double)fNow;
                            break;
                        case 5:
                            ++m_kTexCount.nDependTime;
                            bExpired = pPair->m_value->m_dLastUse + m_dLifetime < (double)fNow;
                            break;
                        }
                        if (bExpired && nRefs < 2)
                            m_mapTex.RemoveAt(posCur);
                    }
                }
            }
            RefreshTextures();
        }
    }
}
MS2_REPLACE_METHOD(0x1415543E0, CNifLoadingService, Sweep, 2239, 0x928FF2A6);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141555600
void CNifLoadingService::DumpNifs()
{
    m_kNifCount.nNotCache = 0;
    m_kNifCount.nForceKeep = 0;
    m_kNifCount.nMySkill = 0;
    m_kNifCount.nOtherSkill = 0;
    m_kNifCount.nNPC = 0;
    m_kNifCount.nDependTime = 0;
    FILE* pFile = fopen("LoadedNifs.txt", "w");
    if (pFile != 0)
    {
        CString strLine;
        unsigned nIndex = 0;
        if (Unk_LockGuard kGuard = DAT_143ae1f28)
        {
        }
        else
        {
            POSITION pos = m_mapNif.GetHeadPosition();
            while (pos != 0)
            {
                POSITION posCur = pos;
                m_mapNif.GetNext(pos);
                ATL::CRBMap<CString, CCachedNifPtr>::CPair* pPair = m_mapNif.GetAt(posCur);
                CString strPath(m_mapNif.GetKeyAt(posCur));
                if (FUN_1409849b0(&pPair->m_value->m_spData) == 0)
                {
                    m_mapNif.RemoveAt(posCur);
                }
                else
                {
                    switch (pPair->m_value->m_nClass)
                    {
                    case 0:
                        strLine.Format("[%04d]\teRP_NotCache\t%s", nIndex, (const char*)strPath);
                        fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                        fwrite("\n", 1, 1, pFile);
                        ++m_kNifCount.nNotCache;
                        break;
                    case 1:
                        strLine.Format("[%04d]\teRP_ForceKeep\t%s", nIndex, (const char*)strPath);
                        fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                        fwrite("\n", 1, 1, pFile);
                        ++m_kNifCount.nForceKeep;
                        break;
                    case 2:
                        strLine.Format("[%04d]\teRP_MySkill\t%s", nIndex, (const char*)strPath);
                        fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                        fwrite("\n", 1, 1, pFile);
                        ++m_kNifCount.nMySkill;
                        break;
                    case 3:
                        strLine.Format("[%04d]\teRP_OtherSkill\t%s", nIndex, (const char*)strPath);
                        fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                        fwrite("\n", 1, 1, pFile);
                        ++m_kNifCount.nOtherSkill;
                        break;
                    case 4:
                        strLine.Format("[%04d]\teRP_NPC\t%s", nIndex, (const char*)strPath);
                        fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                        fwrite("\n", 1, 1, pFile);
                        ++m_kNifCount.nNPC;
                        break;
                    case 5:
                        strLine.Format("[%04d]\teRP_DependTime\t%s", nIndex, (const char*)strPath);
                        fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                        fwrite("\n", 1, 1, pFile);
                        ++m_kNifCount.nDependTime;
                        break;
                    }
                    ++nIndex;
                }
            }
        }
        strLine.Format("NotCacheCount %d\nForceKeepCount %d\nForceKeepCount %d\nOtherSkillCount %d\nNPCCount %d\nDependTimeCount %d\n",
            m_kNifCount.nNotCache, m_kNifCount.nForceKeep, m_kNifCount.nMySkill, m_kNifCount.nOtherSkill, m_kNifCount.nNPC, m_kNifCount.nDependTime);
        fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
        fclose(pFile);
    }
}
MS2_REPLACE_METHOD(0x141555600, CNifLoadingService, DumpNifs, 1728, 0xB80905BD);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141554f60
void CNifLoadingService::DumpTextures()
{
    m_kTexCount.nNotCache = 0;
    m_kTexCount.nForceKeep = 0;
    m_kTexCount.nMySkill = 0;
    m_kTexCount.nOtherSkill = 0;
    m_kTexCount.nNPC = 0;
    m_kTexCount.nDependTime = 0;
    FILE* pFile = fopen("LoadedTextures.txt", "w");
    if (pFile != 0)
    {
        CString strLine;
        unsigned nIndex = 0;
        if (Unk_LockGuard kGuard = DAT_143ae1f58)
        {
        }
        else
        {
            POSITION pos = m_mapTex.GetHeadPosition();
            while (pos != 0)
            {
                POSITION posCur = pos;
                m_mapTex.GetNext(pos);
                ATL::CRBMap<Unk_NifTexKey, CCachedTexturePtr>::CPair* pPair = m_mapTex.GetAt(posCur);
                const CString& strPath = m_mapTex.GetKeyAt(posCur).m_strPath;
                switch (pPair->m_value->m_nClass)
                {
                case 0:
                    strLine.Format("[%04d]\teRP_NotCache\t%s", nIndex, (const char*)strPath);
                    fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                    fwrite("\n", 1, 1, pFile);
                    ++m_kTexCount.nNotCache;
                    break;
                case 1:
                    strLine.Format("[%04d]\teRP_ForceKeep\t%s", nIndex, (const char*)strPath);
                    fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                    fwrite("\n", 1, 1, pFile);
                    ++m_kTexCount.nForceKeep;
                    break;
                case 2:
                    strLine.Format("[%04d]\teRP_MySkill\t%s", nIndex, (const char*)strPath);
                    fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                    fwrite("\n", 1, 1, pFile);
                    ++m_kTexCount.nMySkill;
                    break;
                case 3:
                    strLine.Format("[%04d]\teRP_OtherSkill\t%s", nIndex, (const char*)strPath);
                    fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                    fwrite("\n", 1, 1, pFile);
                    ++m_kTexCount.nOtherSkill;
                    break;
                case 4:
                    strLine.Format("[%04d]\teRP_NPC\t%s", nIndex, (const char*)strPath);
                    fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                    fwrite("\n", 1, 1, pFile);
                    ++m_kTexCount.nNPC;
                    break;
                case 5:
                    strLine.Format("[%04d]\teRP_DependTime\t%s", nIndex, (const char*)strPath);
                    fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
                    fwrite("\n", 1, 1, pFile);
                    ++m_kTexCount.nDependTime;
                    break;
                }
                ++nIndex;
            }
        }
        strLine.Format("NotCacheCount %d\nForceKeepCount %d\nMySkillCount %d\nOtherSkillCount %d\nNPCCount %d\nDependTimeCount %d\n",
            m_kTexCount.nNotCache, m_kTexCount.nForceKeep, m_kTexCount.nMySkill, m_kTexCount.nOtherSkill, m_kTexCount.nNPC, m_kTexCount.nDependTime);
        fwrite((const char*)strLine, strLine.GetLength(), 1, pFile);
        fclose(pFile);
    }
}
MS2_REPLACE_METHOD(0x141554F60, CNifLoadingService, DumpTextures, 1653, 0x971C8348);

// @0x141556610
void CNifLoadingService::LogCounts()
{
    FUN_140a44830()->FUN_1401ce2b0("\n--- CNifLoadingService Log ---");
    FUN_140a44830()->FUN_1401ce2f0("NIF cache count : %d", FUN_14151e770());
    FUN_140a44830()->FUN_1401ce2f0("Nif NotCacheCount %d", m_kNifCount.nNotCache);
    FUN_140a44830()->FUN_1401ce2f0("Nif ForceKeepCount %d", m_kNifCount.nForceKeep);
    FUN_140a44830()->FUN_1401ce2f0("Nif MySkillCount %d", m_kNifCount.nMySkill);
    FUN_140a44830()->FUN_1401ce2f0("Nif OtherSkillCount %d", m_kNifCount.nOtherSkill);
    FUN_140a44830()->FUN_1401ce2f0("Nif NPCCount %d", m_kNifCount.nNPC);
    FUN_140a44830()->FUN_1401ce2f0("Nif DependTimeCount %d", m_kNifCount.nDependTime);
    FUN_140a44830()->FUN_1401ce2f0("Texture cache count : %d", FUN_14151e790());
    FUN_140a44830()->FUN_1401ce2f0("Texture NotCacheCount %d", m_kTexCount.nNotCache);
    FUN_140a44830()->FUN_1401ce2f0("Texture ForceKeepCount %d", m_kTexCount.nForceKeep);
    FUN_140a44830()->FUN_1401ce2f0("Texture MySkillCount %d", m_kTexCount.nMySkill);
    FUN_140a44830()->FUN_1401ce2f0("Texture OtherSkillCount %d", m_kTexCount.nOtherSkill);
    FUN_140a44830()->FUN_1401ce2f0("Texture NPCCount %d", m_kTexCount.nNPC);
    FUN_140a44830()->FUN_1401ce2f0("Texture DependTimeCount %d", m_kTexCount.nDependTime);
}
MS2_REPLACE_METHOD(0x141556610, CNifLoadingService, LogCounts, 500, 0xD41A024D);

extern NiTexture::FormatPrefs DAT_1439fc800;                        // NiSourceTexture's default format preferences

// A copy of the default format preferences.
// @0x14155d6d0
static NiTexture::FormatPrefs FUN_14155d6d0()
{
    return DAT_1439fc800;
}

// ---- weights, cloning, creation --------------------------------------------------------------------------------
extern char DAT_143afa4d8;                                          // NiRTTI table entry: NiNode
extern char DAT_143afa458;                                          // NiRTTI table entry: NiAVObject
extern char DAT_143afc918;                                          // NiRTTI table entry: top-level stream object
extern char DAT_142f2d1c8;                                          // xml element names of the weight file
extern char DAT_142f2d1d0;
extern char DAT_142f2d1d8;
extern char DAT_142f2d1e8;
extern char DAT_143ae5178;                                          // the weight key
Unk_140165cf0* FUN_14081b310(TiXmlDocument* pDoc);                  // root element
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);       // attribute text or 0
const char* FUN_14086f500(Unk_140165cf0* pNode, const char* pszName, unsigned* pnOut);   // int attribute, 0 when absent
void FUN_141047ac0(NiAVObject* pObj, const void* pKey, float fWeight);      // set a named float on the object
unsigned FUN_1409f7c30(NiNode* pNode);                              // child count
NiAVObject* FUN_14098db40(NiNode* pNode, unsigned nIndex);          // child at index
void FUN_1415672e0(NiAVObject* pNode, bool bFlag);                  // prepare a loaded nif
void FUN_14015eb90(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg);

// @0x141556810
static void SetWeights(NiAVObject* pObj, int nWeight)
{
    if (pObj == 0)
        return;
    NiNode* pNode = static_cast<NiNode*>(FUN_14098d8d0(&DAT_143afa4d8, pObj));
    if (pNode != 0)
    {
        unsigned nCount = FUN_1409f7c30(pNode);
        for (unsigned i = 0; i < nCount; ++i)
            SetWeights(FUN_14098db40(pNode, i), nWeight);
    }
    else
    {
        FUN_141047ac0(pObj, &DAT_143ae5178, (float)nWeight / 100.0f);
    }
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141555f50
void CNifLoadingService::ApplyWeights(CString strNifPath, NiAVObject* pkRoot)
{
    NiNode* pRoot = static_cast<NiNode*>(FUN_14098d8d0(&DAT_143afa4d8, pkRoot));
    if (pRoot == 0)
        return;
    CString strXml(strNifPath);
    strXml.Truncate(strNifPath.GetLength() - 3);
    strXml += "xml";
    std::map<CString, TiXmlDocument>::iterator it = m_mapWeightDoc.find(strXml);
    TiXmlDocument* pDoc = 0;
    if (it != m_mapWeightDoc.end() && DAT_1439ed00c != 0)
    {
        pDoc = &it->second;
    }
    else
    {
        TiXmlDocument kDoc;
        m_mapWeightDoc[strXml].FUN_140870cf0(kDoc);
        pDoc = &m_mapWeightDoc[strXml];
        if (FUN_140166420()->FUN_1403987d0(std::string(strXml)) == 0)
            return;
        if (FUN_140166420()->FUN_1403974b0(pDoc, strXml, 0, true, false) == 0)
            return;
    }
    Unk_140165cf0* pElement = FUN_14081b310(pDoc);
    if (pElement == 0)
        return;
    Unk_140165cf0* pList = pElement->FUN_140165cf0(&DAT_142f2d1c8);
    if (pList == 0)
        return;
    for (Unk_140165cf0* pItem = pList->FUN_140165cf0(&DAT_142f2d1d0); pItem != 0; pItem = pItem->FUN_140168650(&DAT_142f2d1e8))
    {
        const char* pszName = FUN_14086f4b0(pItem, &DAT_142f2d1d8);
        if (pszName != 0)
        {
            unsigned nWeight = 0;
            if (FUN_14086f500(pItem, "weight", &nWeight) != 0)
            {
                NiFixedString kName(pszName);
                SetWeights(pRoot->GetObjectByName(kName), (int)nWeight);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141555F50, CNifLoadingService, ApplyWeights, 967, 0x6D7EAF52);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141556320
NiAVObjectPtr CNifLoadingService::CloneCached(CString strPath, CCachedNifPtr spCached)
{
    NiCloningProcess kCloning(0x25);
    kCloning.m_eCopyType = NiObjectNET::COPY_EXACT;
    NiObject* pClone = FUN_14098d0f0(&spCached->m_spData)->Clone(kCloning);
    NiAVObject* pNode = static_cast<NiAVObject*>(FUN_14098d8d0(&DAT_143afa458, pClone));
    ApplyWeights(CString(strPath), pNode);
    return pNode;
}
MS2_REPLACE_METHOD(0x141556320, CNifLoadingService, CloneCached, 226, 0x8AD76230);

// @0x1415527a0
CCachedNifPtr CNifLoadingService::FindCachedNif(CString strPath, int nClass, bool* pbReloaded)
{
    CCachedNifPtr spFound = 0;
    if (Unk_LockGuard kGuard = DAT_143ae1f28)
    {
    }
    else if (DAT_1439ed00c != 0 && m_mapNif.Lookup(strPath, spFound))
    {
        if (FUN_1401d1320(&spFound->m_kFile) == 1)
        {
            m_mapNif.RemoveKey(strPath);
            spFound = 0;
            *pbReloaded = true;
        }
        else
        {
            spFound->m_dLastUse = FUN_14086d260()->FUN_141473280();
            if (spFound->m_nClass > nClass)
                spFound->m_nClass = nClass;
        }
    }
    return spFound;
}
MS2_REPLACE_METHOD(0x1415527A0, CNifLoadingService, FindCachedNif, 363, 0x16E26FC9);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141552920
CCachedNifPtr CNifLoadingService::CreateCachedNif(CString strPath, int nClass, bool bFlag, bool bReloaded)
{
    NiStream* pStream = FUN_1414a5720()->Get(CString(strPath));
    if (pStream == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"nif \xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4" L"CreateCachedNif Stream[{0}]", strPath);
        return 0;
    }
    CCachedNifPtr spEntry = EE_NEW CCachedNif;
    spEntry->m_kFile.FUN_1401d1160(CString(strPath));
    spEntry->m_dLastUse = FUN_14086d260()->FUN_141473280();
    FUN_1409fabf0(&spEntry->m_spData, FUN_14098d8d0(&DAT_143afa458, FUN_14155d900(pStream, 0)));
    spEntry->m_nClass = nClass;
    if (FUN_1409849b0(&spEntry->m_spData) == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"nif \xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4" L"CreateCachedNif Object[{0}] GetObjectAt()", strPath);
        delete pStream;
        return 0;
    }
    FUN_1415672e0(FUN_1409849b0(&spEntry->m_spData), bFlag);
    for (unsigned i = 1; i < FUN_14155d950(pStream); ++i)
    {
        NiAVObjectPtr spExtra = static_cast<NiAVObject*>(FUN_14098d8d0(&DAT_143afc918, FUN_14155d900(pStream, i)));
        if (spExtra != 0)
            spEntry->m_aClones.Add(spExtra);
    }
    delete pStream;
    if (Unk_LockGuard kGuard = DAT_143ae1f28)
        return spEntry;
    CCachedNifPtr spOld = 0;
    if (!bReloaded && m_mapNif.Lookup(strPath, spOld))
    {
        if (nClass < spOld->m_nClass)
            spOld->m_nClass = nClass;
        return spOld;
    }
    if (DAT_1439ed00c == 1)
        m_mapNif.SetAt(strPath, spEntry);
    if (bReloaded)
    {
        m_mapMyPool[strPath].vfunc_1(0);
        m_mapOtherPool[strPath].vfunc_1(0);
    }
    return spEntry;
}
MS2_REPLACE_METHOD(0x141552920, CNifLoadingService, CreateCachedNif, 1622, 0xCE338DBB);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141551ea0
NiAVObjectPtr CNifLoadingService::Load(CString strPath, bool bFlag, int nClass, int nMyRefs, int nOtherRefs)
{
    if (strPath == "" || m_bShutdown != 0)
        return 0;
    FUN_14028e7c0(strPath);
    bool bReloaded = false;
    CCachedNifPtr spCached = FindCachedNif(CString(strPath), nClass, &bReloaded);
    if (spCached != 0 && (nMyRefs != 0 || nOtherRefs != 0))
    {
        if (Unk_LockGuard kGuard = DAT_143ae1f28)
        {
        }
        else
        {
            int nRefs = nMyRefs == 0 ? nOtherRefs : nMyRefs;
            TCircleList<NiAVObjectPtr>& rRing = nMyRefs == 0 ? m_mapOtherPool[strPath] : m_mapMyPool[strPath];
            if (rRing.GetCapacity() != nRefs)
                rRing.vfunc_1(nRefs);
            if (rRing.GetCount() == nRefs)
            {
                NiAVObjectPtr spOld = 0;
                if (rRing.Get(0, spOld))
                {
                    spCached->m_dLastUse = FUN_14086d260()->FUN_141473280();
                    NiNode* pParent = static_cast<NiNode*>(FUN_140a0b000(FUN_14098d0f0(&spOld)));
                    if (pParent != 0)
                        pParent->DetachChild(FUN_1409849b0(&spOld));
                    NiTransform kIdentity;
                    kIdentity.MakeIdentity();
                    FUN_140aacb60(FUN_14098d0f0(&spOld), &kIdentity);
                    FUN_14098d0f0(&spOld)->Update(0.0, true);
                    rRing.Push(spOld);
                    return spOld;
                }
            }
            NiAVObjectPtr spClone = CloneCached(CString(strPath), spCached);
            rRing.Push(spClone);
            return spClone;
        }
    }
    if (spCached == 0)
        spCached = CreateCachedNif(CString(strPath), nClass, bFlag, bReloaded);
    if (Unk_LockGuard kGuard = DAT_143ae1f28)
    {
    }
    else if (spCached != 0 && FUN_1409849b0(&spCached->m_spData) != 0)
    {
        return CloneCached(CString(strPath), spCached);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141551EA0, CNifLoadingService, Load, 1819, 0xAED3D828);

// @0x1415525d0
bool CNifLoadingService::Preload(CString strPath, bool bFlag, int nClass)
{
    bool bReloaded = false;
    if (strPath == "" || m_bShutdown != 0)
        return false;
    FUN_14028e7c0(strPath);
    CCachedNifPtr spCached = FindCachedNif(CString(strPath), nClass, &bReloaded);
    if (spCached == 0)
        spCached = CreateCachedNif(CString(strPath), nClass, bFlag, bReloaded);
    if (spCached == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1415525D0, CNifLoadingService, Preload, 458, 0x73C90076);

// ---- textures --------------------------------------------------------------------------------------------------

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141552f90
efd::SmartPointer<NiTexture> CNifLoadingService::GetTexture(CString strPath, int nClass)
{
    if (strPath == "" || m_bShutdown != 0)
        return 0;
    FUN_14028e7c0(strPath);
    if (Unk_LockGuard kGuard = DAT_143ae1f58)
        return 0;
    int nNewClass = nClass;
    NiTexturePtr spTexture = 0;
    CCachedTexturePtr spCached = 0;
    Unk_NifTexKey kKey(CString(strPath), FUN_14155d6d0());
    if (DAT_1439ed00c != 0 && m_mapTex.Lookup(kKey, spCached))
    {
        if (!FUN_1401d1320(&spCached->m_kFile))
        {
            spCached->m_dLastUse = FUN_14086d260()->FUN_141473280();
            if (nClass < spCached->m_nClass)
                spCached->m_nClass = nClass;
            return spCached->m_spData;
        }
        if (nClass < spCached->m_nClass)
            nNewClass = spCached->m_nClass;
        spCached = 0;
    }
    NiFixedString kName(strPath);
    spTexture = NiSourceTexture::Create(kName, DAT_1439fc800, false, false, true);
    if (FUN_140a5ac80(&spTexture) == 0)
        return 0;
    spCached = EE_NEW CCachedTexture;
    spCached->m_kFile.FUN_1401d1160(CString(strPath));
    spCached->m_dLastUse = FUN_14086d260()->FUN_141473280();
    spCached->m_spData = FUN_140a5ac80(&spTexture);
    spCached->m_nClass = nNewClass;
    m_mapTex.SetAt(kKey, spCached);
    return spCached->m_spData;
}
MS2_REPLACE_METHOD(0x141552F90, CNifLoadingService, GetTexture, 1336, 0x4D96BCD7);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141553910
efd::SmartPointer<NiTexture> CNifLoadingService::GetTextureFrom(CString strKey, CString strFile, int nClass)
{
    if (strKey == "" || strFile == "" || m_bShutdown != 0)
        return 0;
    FUN_14028e7c0(strKey);
    if (Unk_LockGuard kGuard = DAT_143ae1f58)
        return 0;
    int nNewClass = nClass;
    NiTexturePtr spTexture = 0;
    CCachedTexturePtr spCached = 0;
    Unk_NifTexKey kKey(CString(strKey), FUN_14155d6d0());
    if (DAT_1439ed00c != 0 && m_mapTex.Lookup(kKey, spCached))
    {
        if (!FUN_1401d1320(&spCached->m_kFile))
        {
            spCached->m_dLastUse = FUN_14086d260()->FUN_141473280();
            if (nClass < spCached->m_nClass)
                spCached->m_nClass = nClass;
            return spCached->m_spData;
        }
        if (nClass < spCached->m_nClass)
            nNewClass = spCached->m_nClass;
        spCached = 0;
    }
    NiFixedString kName(strFile);
    spTexture = NiSourceTexture::Create(kName, DAT_1439fc800, false, false, true);
    if (FUN_140a5ac80(&spTexture) == 0)
        return 0;
    spCached = EE_NEW CCachedTexture;
    spCached->m_kFile.FUN_1401d1160(CString(strFile));
    spCached->m_dLastUse = FUN_14086d260()->FUN_141473280();
    spCached->m_spData = FUN_140a5ac80(&spTexture);
    spCached->m_nClass = nNewClass;
    m_mapTex.SetAt(kKey, spCached);
    return spCached->m_spData;
}
MS2_REPLACE_METHOD(0x141553910, CNifLoadingService, GetTextureFrom, 1423, 0xC458370B);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1415534d0
efd::SmartPointer<NiSourceTexture> CNifLoadingService::CreateTexture(CString strPath, NiPixelDataPtr spPixels, int nClass)
{
    if (strPath.IsEmpty() || spPixels == 0)
        return 0;
    FUN_14028e7c0(strPath);
    if (Unk_LockGuard kGuard = DAT_143ae1f58)
        return 0;
    CCachedTexturePtr spCached = 0;
    Unk_NifTexKey kKey(CString(strPath), FUN_14155d6d0());
    if (DAT_1439ed00c != 0 && m_mapTex.Lookup(kKey, spCached))
    {
        spCached->m_dLastUse = FUN_14086d260()->FUN_141473280();
        return static_cast<NiSourceTexture*>(static_cast<NiTexture*>(spCached->m_spData));
    }
    efd::SmartPointer<NiSourceTexture> spTexture = NiSourceTexture::Create(FUN_140a5ac70(&spPixels), DAT_1439fc800, true);
    if (spTexture == 0)
        return 0;
    spCached = EE_NEW CCachedTexture;
    spCached->m_dLastUse = FUN_14086d260()->FUN_141473280();
    spCached->m_spData = spTexture;
    spCached->m_nClass = nClass;
    m_mapTex.SetAt(kKey, spCached);
    return static_cast<NiSourceTexture*>(static_cast<NiTexture*>(spCached->m_spData));
}
MS2_REPLACE_METHOD(0x1415534D0, CNifLoadingService, CreateTexture, 1077, 0xF4F460AB);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x141553eb0
efd::SmartPointer<NiTexture> CNifLoadingService::FindTexture(CString strPath, const NiTexture::FormatPrefs* pPrefs)
{
    if (strPath.IsEmpty())
        return 0;
    FUN_14028e7c0(strPath);
    if (Unk_LockGuard kGuard = DAT_143ae1f58)
        return 0;
    CCachedTexturePtr spCached = 0;
    NiTexture::FormatPrefs kPrefs = FUN_14155d6d0();
    if (pPrefs != 0)
        kPrefs = *pPrefs;
    Unk_NifTexKey kKey(CString(strPath), kPrefs);
    if (DAT_1439ed00c != 0 && m_mapTex.Lookup(kKey, spCached))
        return spCached->m_spData;
    return 0;
}
MS2_REPLACE_METHOD(0x141553EB0, CNifLoadingService, FindTexture, 557, 0x6EDD4274);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1415540f0
void CNifLoadingService::AddTexture(CString strPath, NiSourceTexture* pTexture)
{
    if (strPath.IsEmpty() || pTexture == 0)
        return;
    FUN_14028e7c0(strPath);
    if (Unk_LockGuard kGuard = DAT_143ae1f58)
        return;
    CCachedTexturePtr spCached = 0;
    if (DAT_1439ed00c != 0)
    {
        Unk_NifTexKey kKey(CString(strPath), pTexture->GetFormatPreferences());
        if (!m_mapTex.Lookup(kKey, spCached))
        {
            spCached = EE_NEW CCachedTexture;
            spCached->m_kFile.FUN_1401d1160(CString(strPath));
            spCached->m_dLastUse = FUN_14086d260()->FUN_141473280();
            spCached->m_spData = pTexture;
            spCached->m_nClass = 5;
            m_mapTex.SetAt(kKey, spCached);
        }
        else
        {
            spCached->m_spData = pTexture;
            spCached->m_dLastUse = FUN_14086d260()->FUN_141473280();
        }
    }
}
MS2_REPLACE_METHOD(0x1415540F0, CNifLoadingService, AddTexture, 741, 0x08563473);

// Out-of-line NiString wrappers of the exe (the NiMain copies at 0x141d5b..).
void FUN_141d5be30(NiString* pDst, const NiString* pSrc);
void FUN_141d5bfe0(NiString* pStr);

// MS2-FUNCTIONAL: temporaries: the exe reloads the source through a register hop
// @0x14154ef70
NiString* FUN_14154ef70(NiString* pDst, const NiString* pSrc)
{
    FUN_141d5be30(pDst, pSrc);
    return pDst;
}

// MS2-FUNCTIONAL: temporaries: the exe reloads the source through a register hop
// @0x14154efa0
NiString* FUN_14154efa0(NiString* pDst, const NiString* pSrc)
{
    FUN_141d5be30(pDst, pSrc);
    return pDst;
}

// MS2-FUNCTIONAL: placement-new form not found; exe is a plain 37-byte call to the NiString ctor with 0x100
// @0x14154efd0
NiString* FUN_14154efd0(NiString* pStr)
{
    return new (pStr) NiString();
}

// MS2-FUNCTIONAL: the exe reloads this through a register hop and calls the destructor directly
// @0x14154f250
void FUN_14154f250(NiString* pStr)
{
    pStr->~NiString();
}

// @0x14154fda0
void FUN_14154fda0(void* pObj)
{
    FUN_140a0b330(pObj, true, 0x800);
}

// The exe's GetValueAt copies for the nif / texture caches (called by CNifLoadingService::Sweep).
template CCachedNifPtr& ATL::CRBTree<CString, CCachedNifPtr, ATL::CElementTraits<CString>, ATL::CElementTraits<CCachedNifPtr> >::GetValueAt(POSITION);
template CCachedTexturePtr& ATL::CRBTree<Unk_NifTexKey, CCachedTexturePtr, ATL::CElementTraits<Unk_NifTexKey>, ATL::CElementTraits<CCachedTexturePtr> >::GetValueAt(POSITION);

// Raw (no reference counting) store into NiSourceTexture's protected m_spSrcPixelData.
struct Unk_NifSrcTexAccess : NiSourceTexture
{
    static NiPixelDataPtr NiSourceTexture::* Member() { return &Unk_NifSrcTexAccess::m_spSrcPixelData; }
};

// MS2-FUNCTIONAL: the exe stores the raw pointer at +0x40 directly (25 bytes); the protected member needs the access helper
// MS2-PIN: ?FUN_141562500@@YAXPEAVNiSourceTexture@@PEAVNiPixelData@@@Z 0x141562500
void FUN_141562500(NiSourceTexture* pTexture, NiPixelData* pPixels)
{
    *reinterpret_cast<NiPixelData**>(&(pTexture->*Unk_NifSrcTexAccess::Member())) = pPixels;
}

// MS2-PIN: ??__EDAT_143ae1f28@@YAXXZ 0x1400fa4e0 ; generated initializer of the nif cache lock
// MS2-PIN: ??__EDAT_143ae1f58@@YAXXZ 0x1400fa510 ; generated initializer of the texture cache lock
// MS2-PIN: ??9?$SmartPointer@VNiAVObject@@@efd@@QEBA_NPEAVNiAVObject@@@Z 0x14155be40 ; hand: this TU's byte-identical copy
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb37d0-0x142cb38a0 .text$yd
