// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Common::Constants (constants.xml values, 0xae68 bytes) and
// Client::Constants (colours/UI values, 0xea98 bytes) with their self-registering Object / Value<T> / Values<T> members.
// MS2-UNIT: unit_1402ab440
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x1402ab440-0x1402c3760 .text$mn
// MS2-RANGE: 0x1400b59f0-0x1400b5a20 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Read@?$Value@M@Constants@Common@@QEAAMXZ 0x1402bac70 ; unique: single byte-identical candidate
// MS2-PIN: ??$Unk_SocketFormat@PEBD_N_NI@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBQEBDAEB_N2AEBI@Z 0x1402bae00 ; unique: caller ?Test@Constants@Common@@SA_NXZ
// MS2-PIN: ??$_Pocca@V?$allocator@I@std@@@std@@YAXAEAV?$allocator@I@0@AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x1402bc150 ; unique: single byte-identical candidate
// MS2-PIN: ??0?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEAA@XZ 0x1402bc4b0 ; unique: caller ?LoadFiles@Constants@Common@@QEAA_NXZ
// MS2-PIN: ??0?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAA@XZ 0x1402bc4f0 ; order: name order
// MS2-PIN: ??0?$CAtlArray@UUnk_ConstCacheRef@@V?$CElementTraits@UUnk_ConstCacheRef@@@ATL@@@ATL@@QEAA@XZ 0x1402bc530 ; manual: Constants ctor +0x10 (cacheRefs)
// MS2-PIN: ??0?$Values@UUnk_ConstColor@@@Constants@Common@@QEAA@XZ 0x1402bcd90 ; unique: caller ??0Constants@Client@@QEAA@XZ
// MS2-PIN: ??0Unk_ConstFile@@QEAA@AEBU0@@Z 0x1402bceb0 ; unique: single byte-identical candidate
// MS2-PIN: ??1?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEAA@XZ 0x1402bd110 ; prop: callee ?CallDestructors@?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUn...
// MS2-PIN: ??1?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@QEAA@XZ 0x1402bd150 ; order: name order
// MS2-PIN: ??1Unk_ConstFile@@QEAA@XZ 0x1402bd610 ; unique: single byte-identical candidate
// MS2-PIN: ?Set@?$Value@H@Constants@Common@@QEAAPEAHAEBH@Z 0x1402be3c0 ; order: 0x1402be400 taken by ?Set@?$Value@I@Constants@Common@@QEAAPEAIAEBI@Z
// MS2-PIN: ?Set@?$Value@I@Constants@Common@@QEAAPEAIAEBI@Z 0x1402be400 ; order: name order
// MS2-PIN: ?Set@?$Value@_J@Constants@Common@@QEAAPEA_JAEB_J@Z 0x1402be440 ; unique: single byte-identical candidate
// MS2-PIN: ??4?$vector@IV?$allocator@I@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x1402be4b0 ; unique: single byte-identical candidate
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEBAAEBH_K@Z 0x1402be570 ; unique: single byte-identical candidate
// MS2-PIN: ??_G?$Value@UUnk_ConstColor@@@Constants@Common@@UEAAPEAXI@Z 0x1402be750 ; prop: 0x1402be7d0 taken by ??_G?$Value@UMS2Tick@@@Constants@Common@@UEAAPEAXI@Z
// MS2-PIN: ??_G?$Value@UMS2Tick@@@Constants@Common@@UEAAPEAXI@Z 0x1402be7d0 ; prop: symbol ??1?$Value@UMS2Tick@@@Constants@Common@@UEAA@XZ
// MS2-PIN: ?Add@?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEAA_KAEBUUnk_ConstFile@@@Z 0x1402bed00 ; manual: LoadFiles (files)
// MS2-PIN: ?Add@?$CAtlArray@UUnk_ConstCacheRef@@V?$CElementTraits@UUnk_ConstCacheRef@@@ATL@@@ATL@@QEAA_KAEBUUnk_ConstCacheRef@@@Z 0x1402bee60 ; manual: LoadFiles (cacheRefs)
// MS2-PIN: ?CallConstructors@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@CAXPEAH_K@Z 0x1402bf230 ; order: 0x1402bf2a0 taken by ?CallConstructors@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@CAXP...
// MS2-PIN: ?CallConstructors@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@CAXPEAI_K@Z 0x1402bf2a0 ; order: name order
// MS2-PIN: ?CallDestructors@?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@CAXPEAUUnk_ConstFile@@_K@Z 0x1402bf5c0 ; unique: single byte-identical candidate
// MS2-PIN: ?CallDestructors@?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@CAXPEA_J_K@Z 0x1402bf620 ; order: name order
// MS2-PIN: ??A?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEAAAEAUUnk_ConstFile@@_K@Z 0x1402bfad0 ; unique: single byte-identical candidate
// MS2-PIN: ?GetCount@?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@QEBA_KXZ 0x1402bfb60 ; order: name order
// MS2-PIN: ?Define@?$Value@G@Constants@Common@@QEAAPEAGPEBDAEBG@Z 0x1402bfb90 ; unique: single byte-identical candidate
// MS2-PIN: ?Define@?$Value@H@Constants@Common@@QEAAPEAHPEBDAEBH@Z 0x1402bfc50 ; prop: symbol ?Lookup@Constants@Common@@QEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL...
// MS2-PIN: ?Define@?$Value@I@Constants@Common@@QEAAPEAIPEBDAEBI@Z 0x1402bfd10 ; prop: symbol ?Lookup@Constants@Common@@QEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL...
// MS2-PIN: ?Define@?$Value@K@Constants@Common@@QEAAPEAKPEBDAEBK@Z 0x1402bfdd0 ; prop: 0x1402bfd10 taken by ?Define@?$Value@I@Constants@Common@@QEAAPEAIPEBDAEBI@Z
// MS2-PIN: ?Define@?$Value@M@Constants@Common@@QEAAPEAMPEBDAEBM@Z 0x1402bfe90 ; unique: caller ?vfunc_0@Constants@Client@@UEAAXXZ
// MS2-PIN: ?Define@?$Value@UUnk_ConstColor@@@Constants@Common@@QEAAPEAUUnk_ConstColor@@PEBDAEBU4@@Z 0x1402bff60 ; prop: symbol ?Lookup@Constants@Common@@QEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL...
// MS2-PIN: ?Define@?$Value@UMS2Colors@@@Constants@Common@@QEAAPEAUMS2Colors@@PEBDAEBU4@@Z 0x1402c0020 ; unique: single byte-identical candidate
// MS2-PIN: ?Define@?$Value@UMS2Tick@@@Constants@Common@@QEAAPEAUMS2Tick@@PEBDAEBU4@@Z 0x1402c00f0 ; prop: 0x1402bff60 taken by ?Define@?$Value@UUnk_ConstColor@@@Constants@Common@@QEAAPEAUUnk_Co...
// MS2-PIN: ?Define@?$Value@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@QEAAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBV45@@Z 0x1402c01b0 ; prop: symbol ?Lookup@Constants@Common@@QEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL...
// MS2-PIN: ?Define@?$Value@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Constants@Common@@QEAAPEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEBDAEBV45@@Z 0x1402c0280 ; prop: 0x1402c01b0 taken by ?Define@?$Value@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@...
// MS2-PIN: ?Define@?$Value@V?$vector@IV?$allocator@I@std@@@std@@@Constants@Common@@QEAAPEAV?$vector@IV?$allocator@I@std@@@std@@PEBDAEBV45@@Z 0x1402c0350 ; unique: single byte-identical candidate
// MS2-PIN: ?Define@?$Value@VPoint3@efd@@@Constants@Common@@QEAAPEAVPoint3@efd@@PEBDAEBV45@@Z 0x1402c0420 ; unique: single byte-identical candidate
// MS2-PIN: ?Define@?$Value@_J@Constants@Common@@QEAAPEA_JPEBDAEB_J@Z 0x1402c04f0 ; unique: single byte-identical candidate
// MS2-PIN: ?Define@?$Value@_N@Constants@Common@@QEAAPEA_NPEBDAEB_N@Z 0x1402c05f0 ; unique: single byte-identical candidate
// MS2-PIN: ?Define@?$Values@I@Constants@Common@@QEAA_NPEBD@Z 0x1402c08c0 ; unique: single byte-identical candidate
// MS2-PIN: ?Define@?$Values@UUnk_ConstColor@@@Constants@Common@@QEAA_NPEBDPEAV?$CAtlArray@UUnk_ConstColor@@V?$CElementTraits@UUnk_ConstColor@@@ATL@@@ATL@@@Z 0x1402c0c90 ; unique: single byte-identical candidate
// MS2-PIN: ?Define@?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@QEAA_NPEBDPEAV?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@Z 0x1402c0ea0 ; unique: single byte-identical candidate
// MS2-PIN: ?Define@?$Values@_J@Constants@Common@@QEAA_NPEBD@Z 0x1402c10f0 ; unique: single byte-identical candidate
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V32@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@0@Z 0x1402c2100 ; unique: caller ?InsertImpl@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraits...
// MS2-PIN: ?RBInsert@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V32@@ATL@@IEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@0@Z 0x1402c2430 ; unique: caller ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@...
// MS2-PIN: ?SetCount@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAA_N_KH@Z 0x1402c2b80 ; unique: caller ?RemoveAll@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAAXXZ
// MS2-PIN: ?SetNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V32@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x1402c34e0 ; unique: single byte-identical candidate
// MS2-PIN: ?_Buy@?$vector@IV?$allocator@I@std@@@std@@AEAA_N_K@Z 0x1402c3550 ; unique: caller ??$_Assign_range@PEAI@?$vector@IV?$allocator@I@std@@@std@@AEAAXPEA...
// MS2-PIN: ?_Copy_alloc@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAXAEBV?$allocator@I@2@@Z 0x1402c3640 ; unique: single byte-identical candidate
// MS2-PIN: ?vfunc_1@?$Values@H@Constants@Common@@UEAAXXZ 0x1402c3670 ; unique: vftable slot 1 of ??_7?$Values@H@Constants@Common@@6B@
// MS2-PIN: ?vfunc_1@?$Values@I@Constants@Common@@UEAAXXZ 0x1402c36a0 ; unique: vftable slot 1 of ??_7?$Values@I@Constants@Common@@6B@
// MS2-PIN: ?vfunc_1@?$Values@UUnk_ConstColor@@@Constants@Common@@UEAAXXZ 0x1402c36d0 ; prop: 0x1402c36a0 taken by ?vfunc_1@?$Values@I@Constants@Common@@UEAAXXZ
// MS2-PIN: ?vfunc_1@?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@UEAAXXZ 0x1402c3700 ; unique: vftable slot 1 of ??_7?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL...
// MS2-PIN: ?vfunc_1@?$Values@_J@Constants@Common@@UEAAXXZ 0x1402c3730 ; unique: vftable slot 1 of ??_7?$Values@_J@Constants@Common@@6B@
// MS2-PIN: ??1?$Values@H@Constants@Common@@UEAA@XZ 0x1402bd4d0 ; manual: named in the exe symbol dump
// MS2-PIN: ??1?$Values@I@Constants@Common@@UEAA@XZ 0x1402bd510 ; manual: named in the exe symbol dump
// MS2-PIN: ??1?$Values@UUnk_ConstColor@@@Constants@Common@@UEAA@XZ 0x1402bd550 ; manual: named in the exe symbol dump
// MS2-PIN: ??1?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@UEAA@XZ 0x1402bd590 ; manual: named in the exe symbol dump
// MS2-PIN: ??1?$Values@_J@Constants@Common@@UEAA@XZ 0x1402bd5d0 ; manual: named in the exe symbol dump
// MS2-PIN: ??1?$Value@UMS2Colors@@@Constants@Common@@UEAA@XZ 0x1402bd310 ; manual: named in the exe symbol dump
// MS2-PIN: ??_G?$Value@UMS2Colors@@@Constants@Common@@UEAAPEAXI@Z 0x1402be790 ; manual: named in the exe symbol dump
// MS2-PIN: ??0?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@QEAA@XZ 0x1402bcdf0 ; manual: named in the exe symbol dump
// MS2-PIN: ?Read@?$Value@I@Constants@Common@@QEAAIXZ 0x1402bac50 ; manual: named in the exe symbol dump
// MS2-PIN: ?Read@?$Value@_J@Constants@Common@@QEAA_JXZ 0x1402bac90 ; manual: named in the exe symbol dump
// MS2-PINS-END tplpin
// hand pins (w123b): tplpin --simulate accepted
// MS2-PIN: ??_G?$Value@G@Constants@Common@@UEAAPEAXI@Z 0x1402be610
// MS2-PIN: ??_G?$Value@H@Constants@Common@@UEAAPEAXI@Z 0x1402be650
// MS2-PIN: ??_G?$Value@I@Constants@Common@@UEAAPEAXI@Z 0x1402be690
// MS2-PIN: ??_G?$Value@K@Constants@Common@@UEAAPEAXI@Z 0x1402be6d0
// MS2-PIN: ??_G?$Value@M@Constants@Common@@UEAAPEAXI@Z 0x1402be710
// MS2-PIN: ??_G?$Value@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@UEAAPEAXI@Z 0x1402be810
// MS2-PIN: ??_G?$Value@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Constants@Common@@UEAAPEAXI@Z 0x1402be850
// MS2-PIN: ??_G?$Value@V?$vector@HV?$allocator@H@std@@@std@@@Constants@Common@@UEAAPEAXI@Z 0x1402be890
// MS2-PIN: ??_G?$Value@V?$vector@IV?$allocator@I@std@@@std@@@Constants@Common@@UEAAPEAXI@Z 0x1402be8d0
// MS2-PIN: ??_G?$Value@_J@Constants@Common@@UEAAPEAXI@Z 0x1402be950
// MS2-PIN: ??_G?$Value@_N@Constants@Common@@UEAAPEAXI@Z 0x1402be990
// MS2-PIN: ??_G?$Values@H@Constants@Common@@UEAAPEAXI@Z 0x1402be9d0
// MS2-PIN: ??_G?$Values@I@Constants@Common@@UEAAPEAXI@Z 0x1402bea10
// MS2-PIN: ??_G?$Values@UUnk_ConstColor@@@Constants@Common@@UEAAPEAXI@Z 0x1402bea50
// MS2-PIN: ??_G?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@UEAAPEAXI@Z 0x1402bea90
// MS2-PIN: ??_G?$Values@_J@Constants@Common@@UEAAPEAXI@Z 0x1402bead0
// MS2-PIN: ??_G?$TSingleton@VConstants@Client@@@@UEAAPEAXI@Z 0x1402be5d0
// MS2-PIN: ??_G?$Value@VPoint3@efd@@@Constants@Common@@UEAAPEAXI@Z 0x1402be910
// MS2-PIN: ?CallConstructors@?$CAtlArray@UUnk_ConstCacheRef@@V?$CElementTraits@UUnk_ConstCacheRef@@@ATL@@@ATL@@CAXPEAUUnk_ConstCacheRef@@_K@Z 0x1402bf480
// MS2-PIN: ?Append@?$CAtlArray@UUnk_ConstColor@@V?$CElementTraits@UUnk_ConstColor@@@ATL@@@ATL@@QEAA_KAEBV12@@Z 0x1402bf0f0
// MS2-PIN: ??_EConstants@Client@@WKOGI@EAAPEAXI@Z 0x1402be5c0
// hand pins (w123): tplpin --simulate accepted
// MS2-PIN: ??_7?$Value@UUnk_ConstColor@@@Constants@Common@@6B@ 0x142d1ec28
// MS2-PIN: ??_7?$Values@UUnk_ConstColor@@@Constants@Common@@6B@ 0x142d1ec58
// MS2-PIN: ??_7Constants@Client@@6B0Common@@@ 0x142d1eca0
// MS2-PIN: ??_7Constants@Client@@6B?$TSingleton@VConstants@Client@@@@@ 0x142d1ecb8
// MS2-PIN: ?Read@?$Value@I@Constants@Common@@QEAAIXZ 0x1402bac50
// MS2-PIN: ?Read@?$Value@M@Constants@Common@@QEAAMXZ 0x1402bac70
// MS2-PIN: ?Read@?$Value@_J@Constants@Common@@QEAA_JXZ 0x1402bac90
// MS2-PIN: ??1Unk_ConstFile@@QEAA@XZ 0x1402bd610
// MS2-PIN: ?Set@?$Value@_J@Constants@Common@@QEAAPEA_JAEB_J@Z 0x1402be440
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEBAAEBH_K@Z 0x1402be570
// MS2-PIN: ?Add@?$CAtlArray@UUnk_ConstColor@@V?$CElementTraits@UUnk_ConstColor@@@ATL@@@ATL@@QEAA_KAEBUUnk_ConstColor@@@Z 0x1402bedb0
// MS2-PIN: ?CallConstructors@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@CAXPEAH_K@Z 0x1402bf230
// MS2-PIN: ?CallDestructors@?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@CAXPEAUUnk_ConstFile@@_K@Z 0x1402bf5c0
// MS2-PIN: ??A?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEAAAEAUUnk_ConstFile@@_K@Z 0x1402bfad0
// MS2-PIN: ?Define@?$Value@G@Constants@Common@@QEAAPEAGPEBDAEBG@Z 0x1402bfb90
// MS2-PIN: ?Define@?$Value@UMS2Colors@@@Constants@Common@@QEAAPEAUMS2Colors@@PEBDAEBU4@@Z 0x1402c0020
// MS2-PIN: ?Define@?$Value@V?$vector@IV?$allocator@I@std@@@std@@@Constants@Common@@QEAAPEAV?$vector@IV?$allocator@I@std@@@std@@PEBDAEBV45@@Z 0x1402c0350
// MS2-PIN: ?Define@?$Value@VPoint3@efd@@@Constants@Common@@QEAAPEAVPoint3@efd@@PEBDAEBV45@@Z 0x1402c0420
// MS2-PIN: ?Define@?$Value@_J@Constants@Common@@QEAAPEA_JPEBDAEB_J@Z 0x1402c04f0
// MS2-PIN: ?Define@?$Value@_N@Constants@Common@@QEAAPEA_NPEBDAEB_N@Z 0x1402c05f0
// MS2-PIN: ?Define@?$Values@I@Constants@Common@@QEAA_NPEBD@Z 0x1402c08c0
// MS2-PIN: ?Define@?$Values@UUnk_ConstColor@@@Constants@Common@@QEAA_NPEBDPEAV?$CAtlArray@UUnk_ConstColor@@V?$CElementTraits@UUnk_ConstColor@@@ATL@@@ATL@@@Z 0x1402c0c90
// MS2-PIN: ?Define@?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@QEAA_NPEBDPEAV?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@Z 0x1402c0ea0
// MS2-PIN: ?Define@?$Values@_J@Constants@Common@@QEAA_NPEBD@Z 0x1402c10f0
// MS2-PIN: ??0?$CAtlArray@PEAV?$Value@I@Constants@Common@@V?$CElementTraits@PEAV?$Value@I@Constants@Common@@@ATL@@@ATL@@QEAA@XZ 0x1402bc430
// MS2-PIN: ?Set@?$Value@H@Constants@Common@@QEAAPEAHAEBH@Z 0x1402be3c0
// MS2-PIN: ?Set@?$Value@I@Constants@Common@@QEAAPEAIAEBI@Z 0x1402be400
// MS2-PIN: ?GetCount@?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEBA_KXZ 0x1402be5b0
// MS2-PIN: ?GetCount@?$CAtlArray@UUnk_ConstColor@@V?$CElementTraits@UUnk_ConstColor@@@ATL@@@ATL@@QEBA_KXZ 0x1402bfb70
// MS2-PIN: ?Define@?$Value@H@Constants@Common@@QEAAPEAHPEBDAEBH@Z 0x1402bfc50
// MS2-PIN: ?Define@?$Value@I@Constants@Common@@QEAAPEAIPEBDAEBI@Z 0x1402bfd10
// MS2-PIN: ?Define@?$Value@K@Constants@Common@@QEAAPEAKPEBDAEBK@Z 0x1402bfdd0
// MS2-PIN: ?Define@?$Value@UUnk_ConstColor@@@Constants@Common@@QEAAPEAUUnk_ConstColor@@PEBDAEBU4@@Z 0x1402bff60
// MS2-PIN: ?Define@?$Value@UMS2Tick@@@Constants@Common@@QEAAPEAUMS2Tick@@PEBDAEBU4@@Z 0x1402c00f0
// MS2-PIN: ?Define@?$Value@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@QEAAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBV45@@Z 0x1402c01b0
// MS2-PIN: ?Define@?$Value@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Constants@Common@@QEAAPEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEBDAEBV45@@Z 0x1402c0280
// MS2-PIN: ?Define@?$Values@H@Constants@Common@@QEAA_NPEBDPEAV?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@Z 0x1402c06b0
// MS2-PIN: ?Define@?$Values@I@Constants@Common@@QEAA_NPEBDPEAV?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@Z 0x1402c0a80
// MS2-PIN: ?GrowBuffer@?$CAtlArray@UUnk_ConstColor@@V?$CElementTraits@UUnk_ConstColor@@@ATL@@@ATL@@AEAA_N_K@Z 0x1402c12b0
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@UUnk_ConstColor@@@ATL@@SAXPEAUUnk_ConstColor@@0_K@Z 0x1402c26b0
// MS2-PIN: ??$Unk_SocketFormat@PEBD_N_NI@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBQEBDAEB_N2AEBI@Z 0x1402bae00
// MS2-PIN: ??0?$Values@UUnk_ConstColor@@@Constants@Common@@QEAA@XZ 0x1402bcd90
// MS2-PIN: ?Define@?$Value@M@Constants@Common@@QEAAPEAMPEBDAEBM@Z 0x1402bfe90
// MS2-PIN: ?SetCount@?$CAtlArray@UUnk_ConstColor@@V?$CElementTraits@UUnk_ConstColor@@@ATL@@@ATL@@QEAA_N_KH@Z 0x1402c3030
// MS2-PIN: ?CopyElements@?$CElementTraitsBase@H@ATL@@SAXPEAHPEBH_K@Z 0x1402bf6c0
// MS2-PIN: ?vfunc_1@?$Values@_J@Constants@Common@@UEAAXXZ 0x1402c3730
// MS2-PIN: ??1?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@QEAA@XZ 0x1402bd150
// MS2-PIN: ?vfunc_1@?$Values@UUnk_ConstColor@@@Constants@Common@@UEAAXXZ 0x1402c36d0
// MS2-PIN: ??$_Assign_range@PEAI@?$vector@IV?$allocator@I@std@@@std@@AEAAXPEAI0Uforward_iterator_tag@1@@Z 0x1402bbdc0
// MS2-PIN: ??$_Pocca@V?$allocator@I@std@@@std@@YAXAEAV?$allocator@I@0@AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x1402bc150
// MS2-PIN: ??$_Ucopy@PEAI@?$vector@IV?$allocator@I@std@@@std@@AEAAPEAIPEAI00@Z 0x1402bc180
// MS2-PIN: ??0Unk_ConstFile@@QEAA@AEBU0@@Z 0x1402bceb0
// MS2-PIN: ??4?$vector@IV?$allocator@I@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x1402be4b0
// MS2-PIN: ?Add@?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEAA_KAEBUUnk_ConstFile@@@Z 0x1402bed00
// MS2-PIN: ?Add@?$CAtlArray@UUnk_ConstCacheRef@@V?$CElementTraits@UUnk_ConstCacheRef@@@ATL@@@ATL@@QEAA_KAEBUUnk_ConstCacheRef@@@Z 0x1402bee60
// MS2-PIN: ?SetCount@?$CAtlArray@UUnk_ConstCacheRef@@V?$CElementTraits@UUnk_ConstCacheRef@@@ATL@@@ATL@@QEAA_N_KH@Z 0x1402c3350
// MS2-PIN: ?_Buy@?$vector@IV?$allocator@I@std@@@std@@AEAA_N_K@Z 0x1402c3550
// MS2-PIN: ?_Copy_alloc@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAXAEBV?$allocator@I@2@@Z 0x1402c3640
// MS2-PIN: ??0?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEAA@XZ 0x1402bc4b0
// MS2-PIN: ??0?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAA@XZ 0x1402bc4f0
// MS2-PIN: ??0?$CAtlArray@UUnk_ConstCacheRef@@V?$CElementTraits@UUnk_ConstCacheRef@@@ATL@@@ATL@@QEAA@XZ 0x1402bc530
// MS2-PIN: ??0?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@QEAA@XZ 0x1402bcdf0
// MS2-PIN: ??1?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEAA@XZ 0x1402bd110
// MS2-PIN: ??1?$Value@UMS2Colors@@@Constants@Common@@UEAA@XZ 0x1402bd310
// MS2-PIN: ??1?$Values@H@Constants@Common@@UEAA@XZ 0x1402bd4d0
// MS2-PIN: ??1?$Values@I@Constants@Common@@UEAA@XZ 0x1402bd510
// MS2-PIN: ??1?$Values@UUnk_ConstColor@@@Constants@Common@@UEAA@XZ 0x1402bd550
// MS2-PIN: ??1?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@UEAA@XZ 0x1402bd590
// MS2-PIN: ??1?$Values@_J@Constants@Common@@UEAA@XZ 0x1402bd5d0
// MS2-PIN: ??_G?$Value@UUnk_ConstColor@@@Constants@Common@@UEAAPEAXI@Z 0x1402be750
// MS2-PIN: ??_G?$Value@UMS2Colors@@@Constants@Common@@UEAAPEAXI@Z 0x1402be790
// MS2-PIN: ??_G?$Value@UMS2Tick@@@Constants@Common@@UEAAPEAXI@Z 0x1402be7d0
// MS2-PIN: ?CallConstructors@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@CAXPEAI_K@Z 0x1402bf2a0
// MS2-PIN: ?CallDestructors@?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@CAXPEA_J_K@Z 0x1402bf620
// MS2-PIN: ?GetCount@?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@QEBA_KXZ 0x1402bfb60
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V32@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@0@Z 0x1402c2100
// MS2-PIN: ?RBInsert@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V32@@ATL@@IEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@0@Z 0x1402c2430
// MS2-PIN: ?SetCount@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAA_N_KH@Z 0x1402c2b80
// MS2-PIN: ?SetNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V32@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x1402c34e0
// MS2-PIN: ?vfunc_1@?$Values@H@Constants@Common@@UEAAXXZ 0x1402c3670
// MS2-PIN: ?vfunc_1@?$Values@I@Constants@Common@@UEAAXXZ 0x1402c36a0
// MS2-PIN: ?vfunc_1@?$Values@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Constants@Common@@UEAAXXZ 0x1402c3700
// MS2-PIN: ??$_Pocca@V?$allocator@I@std@@@std@@YAXAEAV?$allocator@I@0@AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x1402bc150
// MS2-PIN: ??$_Ucopy@PEAI@?$vector@IV?$allocator@I@std@@@std@@AEAAPEAIPEAI00@Z 0x1402bc180
// MS2-PIN: ??0Unk_ConstFile@@QEAA@AEBU0@@Z 0x1402bceb0
// MS2-PIN: ?_Buy@?$vector@IV?$allocator@I@std@@@std@@AEAA_N_K@Z 0x1402c3550
// MS2-PIN: ?_Copy_alloc@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAXAEBV?$allocator@I@2@@Z 0x1402c3640
// MS2-PIN: ?Add@?$CAtlArray@UUnk_ConstFile@@V?$CElementTraits@UUnk_ConstFile@@@ATL@@@ATL@@QEAA_KAEBUUnk_ConstFile@@@Z 0x1402bed00
// MS2-PIN: ?Add@?$CAtlArray@UUnk_ConstCacheRef@@V?$CElementTraits@UUnk_ConstCacheRef@@@ATL@@@ATL@@QEAA_KAEBUUnk_ConstCacheRef@@@Z 0x1402bee60
// MS2-PIN: ??$_Assign_range@PEAI@?$vector@IV?$allocator@I@std@@@std@@AEAAXPEAI0Uforward_iterator_tag@1@@Z 0x1402bbdc0
// MS2-PIN: ??4?$vector@IV?$allocator@I@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x1402be4b0
#define MS2_THIS_FILE ""
#define _NO_CRT_STDIO_INLINE 1                  // _vsnprintf lives in unit_1402c3760.cpp (the exe calls it out of line)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/clientconstants.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/tixmldocument.h"

#include "ms2/ms2format.h"

// Registry of every Object (filled by Value<T>::Value through Constants::Register).
static ATL::CAtlArray<Common::Constants::Object*> s_objects;                             // @0x1400b59f0 (DAT_143aad0f0)

namespace Common {

// ---- Object -------------------------------------------------------------------------------------------------------
// @0x1402b7560
void Constants::Object::Error(const char* msg) { MessageBoxA(NULL, msg, "Constants error", 0); }
// @0x1402b72d0
Constants::Object::Object(const char* typeName) : m_defined(false), m_hasKey(false), m_loaded(false), m_forced(false)
{
    m_typeName = typeName;
}
// @0x1402be380
Constants::Object::~Object() {}
// @0x1402b7530
void Constants::Object::vfunc_1()
{
    m_defined = false;
    m_hasKey = false;
    m_loaded = false;
}
// @0x1402b7370
// MS2-FUNCTIONAL: exe keeps the result in a 4-byte local slot; same behaviour
bool Constants::Object::IsValid() const
{
    if (m_defined && m_hasKey && m_forced)
        return true;
    if (m_defined && m_hasKey && m_loaded)
        return true;
    return false;
}
// @0x1402b73f0
const char* Constants::Object::GetTypeName() const { return m_typeName.c_str(); }
// @0x1402b7420
const char* Constants::Object::GetKey() const { return m_key.c_str(); }
// @0x1402b7450
void Constants::Object::SetKey(const char* key)
{
    m_key = key;
    m_hasKey = true;
}
// @0x1402b7490
void Constants::Object::MarkLoaded() { m_loaded = true; }
// @0x1402b74b0
void Constants::Object::MarkForced() { m_forced = true; }
// @0x1402b74d0
bool Constants::Object::IsDefined() const { return m_defined; }
// @0x1402b74f0
bool Constants::Object::HasKey() const { return m_hasKey; }
// @0x1402b7510
bool Constants::Object::IsLoaded() const { return m_loaded; }

MS2_REPLACE_METHOD(0x1402B7560, Common::Constants::Object, Error, 42, 0x0223C2D4);
MS2_REPLACE_METHOD(0x1402B7370, Common::Constants::Object, IsValid, 116, 0xBB0FE6B0);
MS2_REPLACE_METHOD(0x1402B73F0, Common::Constants::Object, GetTypeName, 31, 0xF1DCE71A);
MS2_REPLACE_METHOD(0x1402B7420, Common::Constants::Object, GetKey, 31, 0x142010AA);
MS2_REPLACE_METHOD(0x1402B7450, Common::Constants::Object, SetKey, 50, 0xC6237425);
MS2_REPLACE_METHOD(0x1402B7490, Common::Constants::Object, MarkLoaded, 15, 0xBFAC59E3);
MS2_REPLACE_METHOD(0x1402B74B0, Common::Constants::Object, MarkForced, 15, 0x4ACB61C4);
MS2_REPLACE_METHOD(0x1402B74D0, Common::Constants::Object, IsDefined, 15, 0x7316E695);
MS2_REPLACE_METHOD(0x1402B74F0, Common::Constants::Object, HasKey, 15, 0x131A210C);
MS2_REPLACE_METHOD(0x1402B7510, Common::Constants::Object, IsLoaded, 15, 0x3B1E319B);


// ---- registry -----------------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
// @0x1402b7590
void Constants::Register(Object* obj) { s_objects.Add(obj); }
#endif
// @0x1402b75c0
bool Constants::Test()
{
    for (unsigned i = 0; i < s_objects.GetCount(); i++)
    {
        Object* obj = s_objects[i];
        if (!obj->IsValid())
        {
            CString msg = Unk_SocketFormat("Constants::Test() failed with key : {0}, is_set : {1}, has_key: {2}, order : {3}",
                                       obj->GetKey(), obj->IsDefined(), obj->HasKey(), i + 1);
            MessageBoxA(NULL, msg, "Constants error", 0);
        }
    }
    return true;
}
#ifndef MS2_HOOK_DLL
// @0x1402b76d0
void Constants::ResetAll()
{
    for (unsigned i = 0; i < s_objects.GetCount(); i++)
    {
        Object* obj = s_objects[i];
        if (obj->IsValid())
            obj->vfunc_1();
    }
}
#endif
// @0x1402b7750
bool Constants::AreSameGroup(int a, int b)
{
    if (a == b)
        return true;
    if (WarpOpenContinent.Contains(a) && WarpOpenContinent.Contains(b))
        return true;
    return false;
}

// ---- Value<T> / Values<T> ------------------------------------------------------------------------------------------
template<> const char* Constants::TypeName<unsigned short>() { return "unsigned short"; }      // @0x1402c2010
template<> const char* Constants::TypeName<int>() { return "int"; }                            // @0x1402c2020
template<> const char* Constants::TypeName<unsigned int>() { return "UINT"; }                  // @0x1402c2030
template<> const char* Constants::TypeName<unsigned long>() { return "unknown"; }              // @0x1402c2040
template<> const char* Constants::TypeName<float>() { return "float"; }                        // @0x1402c2050
template<> const char* Constants::TypeName<Unk_ConstColor>() { return "MS2Color"; }            // @0x1402c2060
template<> const char* Constants::TypeName<MS2Colors>() { return "MS2Colors"; }                // @0x1402c2070
template<> const char* Constants::TypeName<MS2Tick>() { return "MS2Tick"; }                    // @0x1402c2080
template<> const char* Constants::TypeName<CString>() { return "CString"; }                    // @0x1402c2090
template<> const char* Constants::TypeName<CStringW>() { return "unknown"; }                   // @0x1402c20a0
template<> const char* Constants::TypeName<std::vector<int> >() { return "vector<int>"; }      // @0x1402c20b0
template<> const char* Constants::TypeName<std::vector<unsigned> >() { return "vector<T>"; }   // @0x1402c20c0
template<> const char* Constants::TypeName<efd::Point3>() { return "unknown"; }                // @0x1402c20d0
template<> const char* Constants::TypeName<__int64>() { return "__int64"; }                    // @0x1402c20e0
template<> const char* Constants::TypeName<bool>() { return "bool"; }                          // @0x1402c20f0

template<class T> T* Constants::Value<T>::Define(const char* key, const T& def)
{
    SetKey(key);
    m_defined = true;
    m_value = (m_default = def);
    bool loaded;
    {
        CString k(key);
        loaded = FUN_1401d3200()->Lookup(k, &m_value);
    }
    if (loaded)
        MarkLoaded();
    return &m_value;
}
template<class T> T* Constants::Value<T>::Get()
{
    if (!m_defined)
        Error("constants is not set");
    return &m_value;
}
template<class T> T* Constants::Value<T>::Set(const T& v)
{
    if (!m_defined)
        m_defined = true;
    m_value = v;
    return &m_value;
}
// @0x1402bc3b0
// MS2-FUNCTIONAL: varargs forwarder: exe spills the va_list setup differently
static void FormatKey(char* out, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    _vsnprintf(out, 0x100, fmt, args);
    va_end(args);
}
// MS2-FUNCTIONAL: the Values<T> collectors, Add/SetCount/ctor/vfunc_1 instantiations for colour/string/int64 elements differ from the exe in temporaries; same behaviour
template unsigned int Constants::Value<unsigned int>::Read();
template __int64 Constants::Value<__int64>::Read();
// Values<T>::Define(key): collect key0, key1, ... until one is missing.
template<class T> bool Constants::Values<T>::Define(const char* key)
{
    if (m_loaded)
        return true;
    if (m_hasKey)
        return false;
    SetKey(key);
    int index = 0;
    m_values.RemoveAll();
    do
    {
        T slot = T();
        T* pSlot = &slot;
        int keyIndex = index;
        char name[0x100];
        FormatKey(name, "%s%d", key, keyIndex);
        index++;
        T value = *pSlot;
        bool done;
        {
            CString k(name);
            done = !FUN_1401d3200()->Lookup(k, &value);
        }
        if (done)
            break;
        m_values.Add(value);
    } while (0 != 1);
    if (m_values.GetCount() != 0)
        MarkLoaded();
    m_defined = true;
    return m_loaded;
}
template<class T> bool Constants::Values<T>::Define(const char* key, ATL::CAtlArray<T>* out)
{
    if (m_loaded)
    {
        out->RemoveAll();
        out->Append(m_values);
        return true;
    }
    if (m_hasKey)
        return false;
    SetKey(key);
    int index = 0;
    m_values.RemoveAll();
    do
    {
        T slot = T();
        T* pSlot = &slot;
        int keyIndex = index;
        char name[0x100];
        FormatKey(name, "%s%d", key, keyIndex);
        index++;
        T value = *pSlot;
        bool done;
        {
            CString k(name);
            done = !FUN_1401d3200()->Lookup(k, &value);
        }
        if (done)
            break;
        m_values.Add(value);
    } while (0 != 1);
    if (m_values.GetCount() != 0)
    {
        out->RemoveAll();
        out->Append(m_values);
        MarkLoaded();
    }
    m_defined = true;
    return m_loaded;
}
template<class T> void Constants::Values<T>::vfunc_1()
{
    Object::vfunc_1();
    m_values.RemoveAll();
}
// @0x1402bacf0
// MS2-FUNCTIONAL: exe compares the 32-bit count/index; same behaviour
template<class T> static int FindElement(const ATL::CAtlArray<T>& arr, const T& v)
{
    for (size_t i = 0; i < arr.GetCount(); i++)
        if (arr[i] == v)
            return (int)i;
    return -1;
}
template<class T> bool Constants::Values<T>::Contains(T v)
{
    if (m_loaded)
    {
        return FindElement(m_values, v) != -1;
    }
    if (!HasKey())
        Error("constants has no key");
    return false;
}


// ---- lookups: parse the string stored under `key` in the xml map --------------------------------------------------
// @0x1402bb260
bool Constants::Lookup(const CString& key, unsigned short* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        *out = FUN_140718110(s);
        return true;
    }
    return false;
}
// @0x1402bb340
bool Constants::Lookup(const CString& key, int* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        *out = FUN_140718170(s);
        return true;
    }
    return false;
}
// @0x1402bb3d0
bool Constants::Lookup(const CString& key, std::vector<int>* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        FUN_140178270(s, out, ",");
        return true;
    }
    return false;
}
// @0x1402bb470
bool Constants::Lookup(const CString& key, unsigned int* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        *out = FUN_1407181d0(s);
        return true;
    }
    return false;
}
// @0x1402bb550
bool Constants::Lookup(const CString& key, std::vector<unsigned>* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        FUN_1401782a0(s, out, ",");
        return true;
    }
    return false;
}
// @0x1402bb5f0
bool Constants::Lookup(const CString& key, unsigned long* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        *out = FUN_140718290(s);
        return true;
    }
    return false;
}
// @0x1402bb680
bool Constants::Lookup(const CString& key, float* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        *out = FUN_140718450(s);
        return true;
    }
    return false;
}
// @0x1402bb760
// MS2-FUNCTIONAL: exe copies the parsed value through a pointer temporary; same behaviour
bool Constants::Lookup(const CString& key, Unk_ConstColor* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        unsigned c;
        out->argb = *FUN_140718770(&c, s);
        return true;
    }
    return false;
}
// @0x1402bb800
// MS2-FUNCTIONAL: exe copies the parsed value through a pointer temporary; same behaviour
bool Constants::Lookup(const CString& key, MS2Colors* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        MS2Colors c;
        *out = *FUN_1407186f0(&c, s);
        return true;
    }
    return false;
}
// @0x1402bb8c0
// MS2-FUNCTIONAL: exe copies the parsed value through a pointer temporary; same behaviour
bool Constants::Lookup(const CString& key, MS2Tick* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        unsigned t;
        out->value = *FUN_140718830(&t, s);
        return true;
    }
    return false;
}
// @0x1402bb960
// MS2-FUNCTIONAL: exe copies the parsed string through a pointer temporary; same behaviour
bool Constants::Lookup(const CString& key, CString* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        unsigned __int64 buf;
        CString* r = FUN_1407185b0((CString*)&buf, s);
        CString* q = r;
        *out = *q;
        return true;
    }
    return false;
}
// @0x1402bba20
// MS2-FUNCTIONAL: exe copies the parsed string through a pointer temporary; same behaviour
bool Constants::Lookup(const CString& key, CStringW* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        unsigned __int64 buf;
        CStringW* r = FUN_140718650((CStringW*)&buf, s);
        CStringW* q = r;
        *out = *q;
        return true;
    }
    return false;
}
// @0x1402bbb30
// MS2-FUNCTIONAL: exe copies the Point3 result inline; the operator= call here is equivalent
bool Constants::Lookup(const CString& key, efd::Point3* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        efd::Point3 p;
        *out = *FUN_140db9570(&p, s);
        return true;
    }
    return false;
}
// @0x1402bbbd0
bool Constants::Lookup(const CString& key, __int64* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        *out = FUN_1407182f0(s);
        return true;
    }
    return false;
}
// @0x1402bbc60
bool Constants::Lookup(const CString& key, bool* out)
{
    CString s;
    if (values.Lookup(key, s))
    {
        *out = FUN_140718390(s);
        return true;
    }
    return false;
}
// @0x1402bb2f0
bool Constants::GetOr(const CString& key, unsigned short* out, const unsigned short& def)
{
    if (!Lookup(key, out))
    {
        *out = def;
        return false;
    }
    return true;
}
// @0x1402bb500
bool Constants::GetOr(const CString& key, int* out, const int& def)
{
    if (!Lookup(key, (unsigned int*)out))
    {
        *out = def;
        return false;
    }
    return true;
}
// @0x1402bb710
bool Constants::GetOr(const CString& key, float* out, const float& def)
{
    if (!Lookup(key, out))
    {
        *out = def;
        return false;
    }
    return true;
}
// @0x1402bbcf0
bool Constants::GetOr(const CString& key, bool* out, const bool& def)
{
    if (!Lookup(key, out))
    {
        *out = def;
        return false;
    }
    return true;
}

// ---- small value types --------------------------------------------------------------------------------------------
}
// @0x1402bd020
MS2Tick::MS2Tick() : value(0) {}
// @0x1402bd000
MS2Tick::MS2Tick(unsigned v) : value(v) {}
// @0x1402bcfc0
Unk_ConstColor::Unk_ConstColor() : argb(0) {}
// @0x1402bcfa0
Unk_ConstColor::Unk_ConstColor(unsigned v) : argb(v) {}
// @0x1402bcfe0
MS2Colors::MS2Colors() {}
// @0x1402be360
MS2Colors::~MS2Colors() {}
// @0x1402be530
// MS2-FUNCTIONAL: exe assigns through CAtlArray::Copy with a different temporary order
MS2Colors& MS2Colors::operator=(const MS2Colors& o)
{
    Copy(o);
    return *this;
}

// ---- Common::Constants / Client::Constants -----------------------------------------------------------------------
// @0x1402b26d0
// MS2-FUNCTIONAL: 4 bytes longer: member Value<T> ctors are laid out in declaration order but the exe elides one register move
Common::Constants::Constants() : m_unk8(0), values(10) {}
// @0x1402b4c80
Common::Constants::~Constants() {}

Client::Constants* TSingleton<Client::Constants>::s_instance;                            // DAT_143aac5c8
// @0x1402bc680
TSingleton<Client::Constants>::TSingleton() { s_instance = static_cast<Client::Constants*>(this); }
// @0x1402bd230
TSingleton<Client::Constants>::~TSingleton() { s_instance = 0; }
// @0x1402b77c0
Client::Constants::Constants() {}
// @0x1402bd680
// MS2-FUNCTIONAL: exe is 44 bytes longer and does not store the vptrs at the start of the dtor
Client::Constants::~Constants() {}

// @0x1402ab440
// MS2-FUNCTIONAL: long generated body; prologue/default-argument temporaries differ from the exe, values are identical
void Common::Constants::vfunc_0()
{
    ResetAll();
    LookAtInterval.Define("LookAtInterval", MS2Tick(15000));
    LookAtDistanceNPC.Define("LookAtDistanceNPC", 300.0f);
    LookAtDistanceCry.Define("LookAtDistanceCry", 500.0f);
    DamageDistance.Define("DamageDistance", 1500.0f);
    TalkableDistance.Define("TalkableDistance", 300.0f);
    DropIconDistance.Define("DropIconDistance", 200.0f);
    ChatBalloonDistance.Define("ChatBalloonDistance", 2000.0f);
    HpBarDistance.Define("HpBarDistance", 400.0f);
    HpBarDistance2.Define("HpBarDistance", 1500.0f);
    BuffBallonDistance.Define("BuffBallonDistance", 2500.0f);
    DropIconHeadOffset.Define("DropIconHeadOffset", 50.0f);
    OffsetPcHpbar.Define("OffsetPcHpbar", 120.0f);
    OffsetPcNametag.Define("OffsetPcNametag", 260.0f);
    OffsetPcChatballoon.Define("OffsetPcChatballoon", 210.0f);
    OffsetPcDamagenumber.Define("OffsetPcDamagenumber", 0.0f);
    OffsetNpcHpbar.Define("OffsetNpcHpbar", 120.0f);
    OffsetNpcNametag.Define("OffsetNpcNametag", 260.0f);
    OffsetNpcEmoticon.Define("OffsetNpcEmoticon", 400.0f);
    OffsetNpcChatballoon.Define("OffsetNpcChatballoon", 210.0f);
    OffsetNpcDamagenumber.Define("OffsetNpcDamagenumber", 0.0f);
    OffsetNpcMonologue.Define("OffsetNpcMonologue", 0.0f);
    OffsetPcPopupMenu.Define("OffsetPcPopupMenu", 0.0f);
    OffsetPcProfileTag.Define("OffsetPcProfileTag", 0.0f);
    fOffsetOnTombstoneNameTag.Define("fOffsetOnTombstoneNameTag", -16.0f);
    ChatBalloonDuration.Define("ChatBalloonDuration", 5000);
    MonologueInterval.Define("MonologueInterval", MS2Tick(0));
    MonologueRandom.Define("MonologueRandom", MS2Tick(0));
    MonologueShowTime.Define("MonologueShowTime", MS2Tick(0));
    BoreWaitingTick.Define("BoreWaitingTick", 20000);
    SkipFrameGameObject.Define("SkipFrameGameObject", 60.0f);
    SkipFrameDistanceGameObject.Define("SkipFrameDistanceGameObject", 1500.0f);
    PassengerProfileImageSize.Define("PassengerProfileImageSize", 50);
    PassengerProfileImageLifeTime.Define("PassengerProfileImageLifeTime", MS2Tick(10000));
    PassengerProfileImageShowNumber.Define("PassengerProfileImageShowNumber", 3);
    PassengerProfileImageShowCooldown.Define("PassengerProfileImageShowCooldown", MS2Tick(300000));
    PassengerProfileImageShowCooldownParty.Define("PassengerProfileImageShowCooldownParty", MS2Tick(600000));
    PassengerProfileImageShowRange.Define("PassengerProfileImageShowRange", 750);
    UGCCameraDefaultSize.Define("UGCCameraDefaultSize", 320);
    UGCCameraMinSize.Define("UGCCameraMinSize", 160);
    UGCCameraMaxSize.Define("UGCCameraMaxSize", 640);
    UGCCameraSnapshotPreviewTime.Define("UGCCameraSnapshotPreviewTime", 3000);
    UGCImgUploadSizeLimit.Define("UGCImgUploadSizeLimit", 1024);
    UGCImgFileCountCheck.Define("UGCImgFileCountCheck", 300u);
    InteractionDistance.Define("InteractionDistance", 0.0f);
    FunctionCubeDistance.Define("FunctionCubeDistance", 135.0f);
    FunctionCubeDistance2.Define("FunctionCubeDistance", 135.0f);
    ConstructUgcDistance.Define("ConstructUgcDistance", 0.0f);
    RegistUgcDistance.Define("RegistUgcDistance", 0.0f);
    RegistUgcDistanceClose.Define("RegistUgcDistanceClose", 0.0f);
    UgcBoundaryStartDistance.Define("UgcBoundaryStartDistance", 0);
    UgcBoundaryEndDistance.Define("UgcBoundaryEndDistance", 0);
    DurationForBoundaryDisplay.Define("DurationForBoundaryDisplay", 3000);
    HouseMarkShowDistance.Define("HouseMarkShowDistance", 2000);
    HouseMarkShowClippingUp.Define("HouseMarkShowClippingUp", 1500.0f);
    HouseMarkShowClippingDown.Define("HouseMarkShowClippingDown", 200.0f);
    HouseMarkPopupDistance.Define("HouseMarkPopupDistance", 200);
    VolumeMyPcToNpc.Define("VolumeMyPcToNpc", 1.0f);
    VolumeMyPcToObject.Define("VolumeMyPcToObject", 0.1f);
    VolumeMyPcToBreakableObject.Define("VolumeMyPcToBreakableObject", 0.1f);
    VolumePcToNpc.Define("VolumePcToNpc", 0.5f);
    VolumePcToBreakableObject.Define("VolumePcToBreakableObject", 0.1f);
    VolumeNpcToMyPc.Define("VolumeNpcToMyPc", 1.0f);
    VolumeNpcToPc.Define("VolumeNpcToPc", 0.5f);
    VolumeOtherPc.Define("VolumeOtherPc", 0.9f);
    FieldCachingTime.Define("FieldCachingTime", 180.0f);
    FieldCachingCount.Define("FieldCachingCount", 3);
    FieldCachingMaxCount.Define("FieldCachingMaxCount", 5);
    FieldUnloadThreshold.Define("FieldUnloadThreshold", 10);
    EffectLODOneStepDistance.Define("EffectLODOneStepDistance", 700.0f);
    EffectLODTwoStepDistance.Define("EffectLODTwoStepDistance", 1500.0f);
    EffectLODThreeStepDistance.Define("EffectLODThreeStepDistance", 2000.0f);
    CameraInterpolationTime.Define("CameraInterpolationTime", 1.0f);
    EscapeHitMethodSkill.Define("EscapeHitMethodSkill", 0);
    EscapeHitMethodJump.Define("EscapeHitMethodJump", 0);
    EscapeHitMethodMove.Define("EscapeHitMethodMove", 0);
    EscapeHitMoveKeyIsDown.Define("EscapeHitMoveKeyIsDown", 0);
    CameraFinalLoose.Define("CameraFinalLoose", 0.01f);
    CameraCurrentLoose.Define("CameraCurrentLoose", 0.005f);
    CameraUpdateLoose.Define("CameraUpdateLoose", 0.002f);
    CameraExtraDistance.Define("CameraExtraDistance", 200.0f);
    CameraExtraMoveScaleByMonster.Define("CameraExtraMoveScaleByMonster", 3.0f);
    CameraExtraMoveScaleByMap.Define("CameraExtraMoveScaleByMap", 0.5f);
    UserRevivalPaneltyPercent.Define("UserRevivalPaneltyPercent", 10);
    RegionSkillFadeOutDuration.Define("RegionSkillFadeOutDuration", 0.5f);
    DropItemTargetZPos.Define("DropItemTargetZPos", 0.0f);
    DropItemMaxLength.Define("DropItemMaxLength", 0.0f);
    DropMoneyMaxLength.Define("DropMoneyMaxLength", 0.0f);
    DropItemPickUpVel.Define("DropItemPickUpVel", 0.0f);
    DropItemPickUpGravity.Define("DropItemPickUpGravity", 0.0f);
    DropItemPickUpCompleteRotateTime.Define("DropItemPickUpCompleteRotateTime", 0.0f);
    DropItemPickUpCompleteRotateVel.Define("DropItemPickUpCompleteRotateVel", 0.0f);
    moneyTreeDropHeight.Define("moneyTreeDropHeight", 300.0f);
    moneyTreeDropBase.Define("moneyTreeDropBase", 150.0f);
    moneyTreeDropRandom.Define("moneyTreeDropRandom", 200);
    DefaultDropItemAlpha.Define("DefaultDropItemAlpha", 0.5f);
    DropItemPickFailTime.Define("DropItemPickFailTime", 0.3f);
    DropItemPickFailHeight.Define("DropItemPickFailHeight", 50.0f);
    GetExpMinVelocity.Define("GetExpMinVelocity", 250.0f);
    GetExpVelocityPer1Length.Define("GetExpVelocityPer1Length", 2.0f);
    GetExpTimeAcceleration.Define("GetExpTimeAcceleration", 1.02f);
    GetExpCollisionRadius.Define("GetExpCollisionRadius", 15.0f);
    GetExpControlValue0.Define("GetExpControlValue0", efd::Point3());
    GetExpControlValue1.Define("GetExpControlValue1", efd::Point3());
    GetExpTargetPCDummyName.Define("GetExpTargetPCDummyName", CString());
    NPCRandomDeadPushRate.Define("NPCRandomDeadPushRate", 0.1f);
    CameraVelocityInPortalMove.Define("CameraVelocityInPortalMove", 600.0f);
    EmoticonVisibleDistance.Define("EmoticonVisibleDistance", 1000.0f);
    TalkableFrontOnly.Define("TalkableFrontOnly", 1);
    TelescopeFindDistance.Define("TelescopeFindDistance", 300.0f);
    ConstructionGuideCamZoomVelocity.Define("ConstructionGuideCamZoomVelocity", 70.0f);
    ConstructionGuideCamZoomVelocity.MarkForced();
    ConstructionGuideCamDistance.Define("ConstructionGuideCamDistance", 1500.0f);
    ConstructionGuideCamDistance.MarkForced();
    ConstructionGuideCamVelocity.Define("ConstructionGuideCamVelocity", 1500.0f);
    ConstructionGuideCamVelocity.MarkForced();
    FindHoldTargetRange.Define("FindHoldTargetRange", 0.0f);
    FindGrabNodeRange.Define("FindGrabNodeRange", 0.0f);
    ClimbVelocityV.Define("ClimbVelocityV", 3.0f);
    ClimbVelocityH.Define("ClimbVelocityH", 1.0f);
    UserRevivalInvincibleTick.Define("UserRevivalInvincibleTick", 10000);
    EmotionBoreAnimProbability.Define("EmotionBoreAnimProbability", 100);
    ItemTransferBlackMarketGrade.Define("ItemTransferBlackMarketGrade", 4);
    TaxiCallDuration.Define("TaxiCallDuration", 3000);
    TaxiCallBestDriverDuration.Define("TaxiCallBestDriverDuration", 3000);
    TaxiCallBestDriverLevel.Define("TaxiCallBestDriverLevel", 25);
    AirTaxiCashCallDuration.Define("AirTaxiCashCallDuration", 0);
    AirTaxiMesoCallDuration.Define("AirTaxiMesoCallDuration", 0);
    TaxiStationFindDistance.Define("TaxiStationFindDistance", 250.0f);
    CancelSwing_KeyIsDown.Define("CancelSwing_KeyIsDown", 0);
    CustomizingHairSecondPartHighlight.Define("CustomizingHairSecondPartHighlight", 0.2f);
    CustomizingHairFirstPartHighlight.Define("CustomizingHairFirstPartHighlight", 0.2f);
    CustomizingWheelSpeed_Morph.Define("CustomizingWheelSpeed_Morph", 0.0f);
    CustomizingWheelSpeed_Makeup.Define("CustomizingWheelSpeed_Makeup", 0.0f);
    CustomizingRotationSpeed_Makeup.Define("CustomizingRotationSpeed_Makeup", 0.0f);
    CustomizingWheelSpeed_Item.Define("CustomizingWheelSpeed_Item", 0.0f);
    ItemDropLevelMaxBoundry.Define("ItemDropLevelMaxBoundry", 2);
    WindPeriodVar2Cloak.Define("WindPeriodVar2Cloak", 0.0f);
    WindPeriod2Cloak.Define("WindPeriod2Cloak", 0.8f);
    WindAmp2Cloak.Define("WindAmp2Cloak", 1500.0f);
    TransparencyCP.Define("TransparencyCP", 0);
    TransparencyEY.Define("TransparencyEY", 0);
    TransparencyCL.Define("TransparencyCL", 0);
    TransparencyPA.Define("TransparencyPA", 0);
    TransparencyMT.Define("TransparencyMT", 0);
    TransparencyEA.Define("TransparencyEA", 0);
    TransparencyFH.Define("TransparencyFH", 0);
    TransparencyGL.Define("TransparencyGL", 0);
    TransparencyRI.Define("TransparencyRI", 0);
    TransparencySH.Define("TransparencySH", 0);
    SummonRideeDuration.Define("SummonRideeDuration", 5000);
    WorldMapAdjustTileX.Define("WorldMapAdjustTileX", -15);
    WorldMapAdjustTileY.Define("WorldMapAdjustTileY", -35);
    TimeScalePCScale.Define("TimeScalePCScale", 0.1f);
    TimeScalePCDuration.Define("TimeScalePCDuration", 1.0f);
    returnHomeSkillMerat.Define("returnHomeSkillMerat", 100000000);
    GoToHomeCastingTime.Define("GoToHomeCastingTime", 5000);
    RecallCastingTime.Define("RecallCastingTime", 5000);
    UserPortalInvincibleTick.Define("UserPortalInvincibleTick", 10000);
    MaxFPS.Define("MaxFPS", 120);
    TalkCooldown.Define("TalkCooldown", 1000);
    TradeRequestDuration.Define("TradeRequestDuration", 20);
    CoupleEmotionMaxDistance.Define("CoupleEmotionMaxDistance", 300);
    CoupleEmotionRequestDuration.Define("CoupleEmotionRequestDuration", 20);
    MicroGameRequestDuration.Define("MicroGameRequestDuration", 20);
    MicroGameMaxDistance.Define("MicroGameMaxDistance", 300);
    TailEffectDefaultID.Define("TailEffectDefaultID", 101);
    UgcBannerCheckTime.Define("UgcBannerCheckTime", 24);
    CubeCraftSafetyCapID.Define("CubeCraftSafetyCapID", 0);
    CubeCraftLightStickLeftID.Define("CubeCraftLightStickLeftID", 0u);
    CubeCraftLightStickRightID.Define("CubeCraftLightStickRightID", 0u);
    CubeLiftHeightLimitUp.Define("CubeLiftHeightLimitUp", 2);
    CubeLiftHeightLimitDown.Define("CubeLiftHeightLimitDown", 2);
    BoatPrice.Define("BoatPrice", 1000);
    TutorialIntroSkipTime.Define("TutorialIntroSkipTime", 10.0f);
    FastChat_CheckTime.Define("FastChat_CheckTime", 2000);
    SameChat_CheckTime.Define("SameChat_CheckTime", 3000);
    FastChat_CheckCount.Define("FastChat_CheckCount", 3);
    SameChat_CheckCount.Define("SameChat_CheckCount", 3);
    SameChat_RestrictTime.Define("SameChat_RestrictTime", 10000);
    FastChat_RestrictTime.Define("FastChat_RestrictTime", 30000);
    RestrictChat_AddRestrictTime.Define("RestrictChat_AddRestrictTime", 10000);
    AccumWarning_AddRestrictTime.Define("AccumWarning_AddRestrictTime", 60000);
    RestrictWarning_ReleaseTime.Define("RestrictWarning_ReleaseTime", 10000);
    WisperIgnoreTime.Define("WisperIgnoreTime", 10000);
    WisperDurationTime.Define("WisperDurationTime", 2000);
    WisperMaxCount.Define("WisperMaxCount", 3);
    QuestGuidePageCount.Define("QuestGuidePageCount", 4);
    QuestGuideMaxCount.Define("QuestGuideMaxCount", 40);
    ShopSeedResetTime.Define("ShopSeedResetTime", 0);
    UgcHomeSaleWaitingTime.Define("UgcHomeSaleWaitingTime", 0);
    UgcContainerExpireDurationNormal.Define("UgcContainerExpireDurationNormal", 0);
    UgcContainerExpireDurationCash.Define("UgcContainerExpireDurationCash", 0);
    UgcContainerExpireDurationMerat.Define("UgcContainerExpireDurationMerat", 0);
    UgcHomeExtensionNoticeDate.Define("UgcHomeExtensionNoticeDate", 10);
    UgcHomePasswordExpireDuration.Define("UgcHomePasswordExpireDuration", 0);
    AddressPopupDuration.Define("AddressPopupDuration", 3000);
    AvatarDefaultItemMale.Define("AvatarDefaultItemMale", "10200032");
    AvatarDefaultItemFemale.Define("AvatarDefaultItemFemale", "10200033");
    StoreExpandMaxSlotCount.Define("StoreExpandMaxSlotCount", 0);
    StoreExpandPrice1Row.Define("StoreExpandPrice1Row", 0);
    StoreDepositMax.Define("StoreDepositMax", 0);
    StoreWithdrawMax.Define("StoreWithdrawMax", 0);
    UGCShopSellMinPrice.Define("UGCShopSellMinPrice", 10);
    UGCShopSellMaxPrice.Define("UGCShopSellMaxPrice", 50000);
    // clamp: min price >= 0, max price >= min price
    int minPrice = *UGCShopSellMinPrice.Get();
    int minClamped = minPrice < 0 ? 0 : *UGCShopSellMinPrice.Get();
    UGCShopSellMinPrice.Set(minClamped);
    int minNow = *UGCShopSellMinPrice.Get();
    int maxClamped = *UGCShopSellMaxPrice.Get() < minNow ? *UGCShopSellMinPrice.Get() : *UGCShopSellMaxPrice.Get();
    UGCShopSellMaxPrice.Set(maxClamped);
    UGCShopAdHour.Define("UGCShopAdHour", 72);
    UGCShopAdFeeMerat.Define("UGCShopAdFeeMerat", 100);
    UGCShopSaleDay.Define("UGCShopSaleDay", 30);
    UGCShopSellingRestrictAmount.Define("UGCShopSellingRestrictAmount", 100000);
    BlackMarketSellMinPrice.Define("BlackMarketSellMinPrice", 10);
    BlackMarketSellMaxPrice.Define("BlackMarketSellMaxPrice", 9900000000LL);
    __int64 sellMin = *BlackMarketSellMinPrice.Get();
    __int64 sellMinClamped = sellMin < 0 ? 0 : *BlackMarketSellMinPrice.Get();
    BlackMarketSellMinPrice.Set(sellMinClamped);
    __int64 sellMinNow = *BlackMarketSellMinPrice.Get();
    __int64 sellMaxClamped = *BlackMarketSellMaxPrice.Get() < sellMinNow ? *BlackMarketSellMinPrice.Get() : *BlackMarketSellMaxPrice.Get();
    BlackMarketSellMaxPrice.Set(sellMaxClamped);
    FallMoveSpeed.Define("FallMoveSpeed", 1.0f);
    GuildCreatePrice.Define("GuildCreatePrice", 1000);
    GuildCreateMinLevel.Define("GuildCreateMinLevel", 0);
    guildFundRate.Define("guildFundRate", 0.1f);
    guildExpMaxCountForPlayTime.Define("guildExpMaxCountForPlayTime", 3);
    guildDonateMeso.Define("guildDonateMeso", 10000);
    guildStorageGiftNeedPeriod.Define("guildStorageGiftNeedPeriod", 7);
    PvpFFARewardItem.Define("PvpFFARewardItem", 0);
    PvpFFAAdditionRewardRate.Define("PvpFFAAdditionRewardRate", 0);
    for (int i = 0; i < 10; i++)
    {
        CString key = Unk_SocketFormat("PvpFFAReward{0}Count", i + 1);
        PvpFFARewardCount[i].Define(key, 0);
    }
    pvpBtiRewardItem.Define("pvpBtiRewardItem", 90000006);
    pvpBtiRewardWinnerCount.Define("pvpBtiRewardWinnerCount", 10);
    pvpBtiRewardLoserCount.Define("pvpBtiRewardLoserCount", 5);
    BootyPopupDuration.Define("BootyPopupDuration", 3000);
    PeriodOfMaidEmployment.Define("PeriodOfMaidEmployment", 30);
    MaidReadyToPay.Define("MaidReadyToPay", 30);
    MaidAffinityMax.Define("MaidAffinityMax", 9);
    MeratRevivalDebuffCode.Define("MeratRevivalDebuffCode", 100000001u);
    MeratConsumeSuperChat.Define("MeratConsumeSuperChat", 5u);
    MeratConsumeWorldChat.Define("MeratConsumeWorldChat", 5u);
    MeratConsumeChannelChat.Define("MeratConsumeChannelChat", 2u);
    HonorTokenMax.Define("HonorTokenMax", 4000);
    KarmaTokenMax.Define("KarmaTokenMax", 4000);
    LuTokenMax.Define("LuTokenMax", 4000);
    HabiTokenMax.Define("HabiTokenMax", 4000);
    ReverseCoinMax.Define("ReverseCoinMax", 4000);
    MentorTokenMax.Define("MentorTokenMax", 4000);
    MenteeTokenMax.Define("MenteeTokenMax", 4000);
    CharacterDestroyDivisionLevel.Define("CharacterDestroyDivisionLevel", 20);
    CharacterDestroyWaitSecond.Define("CharacterDestroyWaitSecond", 86400);
    PCBangItemDefaultPeriod.Define("PCBangItemDefaultPeriod", 1440u);
    SwimDashSpeed.Define("SwimDashSpeed", 6.4f);
    UserTriggerStateMax.Define("UserTriggerStateMax", 10u);
    UserTriggerEnterActionMax.Define("UserTriggerEnterActionMax", 3u);
    UserTriggerConditionMax.Define("UserTriggerConditionMax", 3u);
    UserTriggerConditionActionMax.Define("UserTriggerConditionActionMax", 3u);
    HomePasswordUsersKickDelay.Define("HomePasswordUsersKickDelay", 10u);
    PCBangAdditionalEffectID.Define("PCBangAdditionalEffectID", 100000006u);
    PCBangAdditionalEffectExp.Define("PCBangAdditionalEffectExp", 1u);
    PCBangAdditionalEffectMeso.Define("PCBangAdditionalEffectMeso", 2u);
    QuestRewardSAIgnoreLevel.Define("QuestRewardSAIgnoreLevel", 10);
    DropSPEPBallTargetZPos.Define("DropSPEPBallTargetZPos", 200.0f);
    DropSPEPBallMaxLength.Define("DropSPEPBallMaxLength", 300.0f);
    DropSPEPBallPickUpVel.Define("DropSPEPBallPickUpVel", 200.0f);
    DropSPEPBallPickUpGravity.Define("DropSPEPBallPickUpGravity", -38.0f);
    DropSPEPBallPickUpCompleteRotateTime.Define("DropSPEPBallPickUpCompleteRotateTime", 0.1f);
    DropSPEPBallPickUpCompleteRotateVel.Define("DropSPEPBallPickUpCompleteRotateVel", 5.0f);
    BankCallDuration.Define("BankCallDuration", 1000);
    RemakeOptionMaxCount.Define("RemakeOptionMaxCount", 10);
    ATL::CAtlArray<int> warpOpenContinent;
    WarpOpenContinent.Define("WarpOpenContinent", &warpOpenContinent);
    BlackMarketSellEndDay.Define("BlackMarketSellEndDay", 7);
    MailExpiryDays.Define("MailExpiryDays", 30);
    MailExpiryDaysPremium.Define("MailExpiryDaysPremium", 365);
    MailExpiryDaysBlackMarket.Define("MailExpiryDaysBlackMarket", 60);
    MailExpiryDaysFittingDoll.Define("MailExpiryDaysFittingDoll", 60);
    TradeMinMeso.Define("TradeMinMeso", 100);
    TradeMaxMeso.Define("TradeMaxMeso", 300000000);
    TradeFeePercent.Define("TradeFeePercent", 10);
    MesoMarketBasePrice.Define("MesoMarketBasePrice", 10000000);
    MesoMarketProductUnit.Define("MesoMarketProductUnit");
    MesoMarketIconType.Define("MesoMarketIconType", 0);
    MesoMarketBuyPayType.Define("MesoMarketBuyPayType", 3);
    MesoMarketTokenDetailUrl.Define("MesoMarketTokenDetailUrl", "");
    BeautyHairShopGotoFieldID.Define("BeautyHairShopGotoFieldID", 52000008u);
    BeautyHairShopGotoPortalID.Define("BeautyHairShopGotoPortalID", 1u);
    BeautyColorShopGotoFieldID.Define("BeautyColorShopGotoFieldID", 52000009u);
    BeautyColorShopGotoPortalID.Define("BeautyColorShopGotoPortalID", 1u);
    BeautyFaceShopGotoFieldID.Define("BeautyFaceShopGotoFieldID", 52000010u);
    BeautyFaceShopGotoPortalID.Define("BeautyFaceShopGotoPortalID", 1u);
    shadowWorldBuffHpUp.Define("shadowWorldBuffHpUp", 70000027u);
    shadowWorldBuffMoveProtect.Define("shadowWorldBuffMoveProtect", 70000032u);
    BeautyStyleExpandSlotPrice.Define("BeautyStyleExpandSlotPrice", 790);
    BeautyStyleMaxSlotCount.Define("BeautyStyleMaxSlotCount", 12u);
    BeautyStyleDefaultSlotCount.Define("BeautyStyleDefaultSlotCount", 1u);
    BeautyStyleExpandSlotCount1time.Define("BeautyStyleExpandSlotCount1time", 3u);
    ItemUnLockTime.Define("ItemUnLockTime", 259200u);
    HomeBankCallDuration.Define("HomeBankCallDuration", 1000u);
    HomeBankCallCooltime.Define("HomeBankCallCooltime", 30000u);
    HomeBankCallSequence.Define("HomeBankCallSequence", "Object_React_A");
    HomeDoctorCallDuration.Define("HomeDoctorCallDuration", 1000u);
    HomeDoctorCallCooltime.Define("HomeDoctorCallCooltime", 30000u);
    HomeDoctorCallSequence.Define("HomeDoctorCallSequence", "EmergencyHelicopter_A");
    HomeDoctorNpcID.Define("HomeDoctorNpcID", 0u);
    HomeDoctorScriptID0.Define("HomeDoctorScriptID0", 0);
    HomeDoctorScriptID1.Define("HomeDoctorScriptID1", 0);
    EnchantMasterScriptID.Define("EnchantMasterScriptID", 31);
    MergeSmithScriptID.Define("MergeSmithScriptID", 10);
    EnchantTransformScriptID.Define("EnchantTransformScriptID", 10);
    PropertyProtectionTime.Define("PropertyProtectionTime", 0);
    RestExpAcquireRate.Define("RestExpAcquireRate", 0u);
    RestExpMaxAcquireRate.Define("RestExpMaxAcquireRate", 0u);
    ApartmentPreviewRequireLevel.Define("ApartmentPreviewRequireLevel", 0u);
    ApartmentPreviewRequireQuestID.Define("ApartmentPreviewRequireQuestID", 0u);
    CharacterAbilityDefaultPoint.Define("CharacterAbilityDefaultPoint", 10u);
    CharacterAbilityResetCoolTimeMinute.Define("CharacterAbilityResetCoolTimeMinute", 120u);
    CharacterAbilityResetMeso.Define("CharacterAbilityResetMeso", 2500);
    CharacterAbilityResetMerat.Define("CharacterAbilityResetMerat", 100);
    CharacterAbilityOpenQuestID.Define("CharacterAbilityOpenQuestID", 90000060u);
    KeyboardGuideShowLevel.Define("KeyboardGuideShowLevel", 90000060u);
    GetOr("DungeonRoomMaxRewardCount", &DungeonRoomMaxRewardCount, 99);
    GetOr("DungeonMatchRecommendPickCount", &DungeonMatchRecommendPickCount, 5);
    GetOr("DungeonSeasonRankMinLevel", &DungeonSeasonRankMinLevel, 60);
    ResetShadowBuffMerat.Define("ResetShadowBuffMerat", 150u);
    InventoryExpandPrice1Row.Define("InventoryExpandPrice1Row", 390u);
    VIPServicePeriodLimitDay.Define("VIPServicePeriodLimitDay", 120u);
    BreedDuration.Define("BreedDuration", 3000u);
    HarvestDuration.Define("HarvestDuration", 3000u);
    RestartQuestStartField.Define("RestartQuestStartField", 52000056u);
    RestartQuestStartFieldRuneBlader.Define("RestartQuestStartFieldRuneBlader", 63000006u);
    RestartQuestStartFieldStriker.Define("RestartQuestStartFieldStriker", 63000015u);
    RestartQuestStartFieldSoulBinder.Define("RestartQuestStartFieldSoulBinder", 63000035u);
    QuestPortalKeepTime.Define("QuestPortalKeepTime", 300.0f);
    QuestPortalKeepNif.Define("QuestPortalKeepNif", "Eff_Com_Portal_E");
    QuestPortalDimensionY.Define("QuestPortalDimensionY", 50.0f);
    QuestPortalDimensionZ.Define("QuestPortalDimensionZ", 200.0f);
    QuestPortalSummonTime.Define("QuestPortalSummonTime", 5000u);
    QuestPortalDistanceFromNpc.Define("QuestPortalDistanceFromNpc", 200u);
    PartyRecallMerat.Define("PartyRecallMerat", 30u);
    PetChangeNameMerat.Define("PetChangeNameMerat", 100);
    VisitorBookURL.Define("VisitorBookURL", "maview:/Guestbook?s={0}");
    bagSlotTabGameCount.Define("bagSlotTabGameCount", std::vector<unsigned>());
    bagSlotTabSkinCount.Define("bagSlotTabSkinCount", std::vector<unsigned>());
    bagSlotTabSummonCount.Define("bagSlotTabSummonCount", std::vector<unsigned>());
    bagSlotTabMaterialCount.Define("bagSlotTabMaterialCount", std::vector<unsigned>());
    bagSlotTabMasteryCount.Define("bagSlotTabMasteryCount", std::vector<unsigned>());
    bagSlotTabLifeCount.Define("bagSlotTabLifeCount", std::vector<unsigned>());
    bagSlotTabQuestCount.Define("bagSlotTabQuestCount", std::vector<unsigned>());
    bagSlotTabGemCount.Define("bagSlotTabGemCount", std::vector<unsigned>());
    bagSlotTabPetCount.Define("bagSlotTabPetCount", std::vector<unsigned>());
    bagSlotTabPetEquipCount.Define("bagSlotTabPetEquipCount", std::vector<unsigned>());
    bagSlotTabActiveSkillCount.Define("bagSlotTabActiveSkillCount", std::vector<unsigned>());
    bagSlotTabMiscCount.Define("bagSlotTabMiscCount", std::vector<unsigned>());
    bagSlotTabCoinCount.Define("bagSlotTabCoinCount", std::vector<unsigned>());
    bagSlotTabBadgeCount.Define("bagSlotTabBadgeCount", std::vector<unsigned>());
    bagSlotTabLapenShardCount.Define("bagSlotTabLapenShardCount", std::vector<unsigned>());
    bagSlotTabPieceCount.Define("bagSlotTabPieceCount", std::vector<unsigned>());
    PetPickDistance.Define("PetPickDistance", 1050.0f);
    PetSummonCastTime.Define("PetSummonCastTime", 700u);
    PetBoreTime.Define("PetBoreTime", 120000u);
    PetIdleTime.Define("PetIdleTime", 70000u);
    PetTiredTime.Define("PetTiredTime", 10000u);
    PetSkillTime.Define("PetSkillTime", 13000u);
    PetEffectUse.Define("PetEffectUse", "Pet\\Eff_Pet_Use.xml");
    PetEffectSkill.Define("PetEffectSkill", "Pet\\Eff_Pet_Skill.xml");
    PetEffectHappy.Define("PetEffectHappy", "Pet\\Eff_Pet_Happy.xml");
    PetGemChatBalloon.Define("PetGemChatBalloon", "pet");
    PetTrapAreaDistanceEasy.Define("PetTrapAreaDistanceEasy", 150.0f);
    PetTrapAreaDistanceNormal.Define("PetTrapAreaDistanceNormal", 300.0f);
    PetTrapAreaDistanceHard.Define("PetTrapAreaDistanceHard", 600.0f);
    PetTrapAreaEffectEasy.Define("PetTrapAreaEffectEasy", "Pet/Eff_Pet_TrapInstallArea_easy.xml");
    PetTrapAreaEffectNormal.Define("PetTrapAreaEffectNormal", "Pet/Eff_Pet_TrapInstallArea_normal.xml");
    PetTrapAreaEffectHard.Define("PetTrapAreaEffectHard", "Pet/Eff_Pet_TrapInstallArea_hard.xml");
    PetTrapAreaEffectOtherUser.Define("PetTrapAreaEffectOtherUser", "");
    PetTamingMaxPointEffect.Define("PetTamingMaxPointEffect", "Item/PetTaming/Eff_Item_PetTamingCandy_Max_01.xml");
    PetTamingAttackMissEffect.Define("PetTamingAttackMissEffect", "Additional/Confusion/Eff_Additional_Confusion_Keep.xml");
    PetTrapDropItemEffect.Define("PetTrapDropItemEffect", "UI/Eff_CHSelect_SelectStart.xml");
    TamingPetEscapeTime.Define("TamingPetEscapeTime", 150u);
    TamingPetMaxPoint.Define("TamingPetMaxPoint", 10000u);
    PetMaxLevel.Define("PetMaxLevel", 50u);
    PetRunSpeed.Define("PetRunSpeed", 600.0f);
    PetTrapDropVisibleDelay.Define("PetTrapDropVisibleDelay", 1000u);
    DisableSoloPlayHighLevelDungeon.Define("DisableSoloPlayHighLevelDungeon", false);
    WebBrowserSizeWidthMin.Define("WebBrowserSizeWidthMin", 438);
    WebBrowserSizeWidthMax.Define("WebBrowserSizeWidthMax", 1700);
    WebBrowserSizeHeightMin.Define("WebBrowserSizeHeightMin", 708);
    WebBrowserSizeHeightMax.Define("WebBrowserSizeHeightMax", 1003);
    WebBrowserEnableSizingButton.Define("WebBrowserEnableSizingButton", true);
    LiveBroadcastURL.Define("LiveBroadcastURL", "http://mxd2.qq.com/web/zhibo/index.shtm");
    TencentWebURL.Define("TencentWebURL", "http://ptlogin2.qq.com/mxd2");
    MaxChatLength.Define("MaxChatLength", 50);
    CodiTabMaxDay.Define("CodiTabMaxDay", 999u);
    WebBrowserPopupSizeWidthMin.Define("WebBrowserPopupSizeWidthMin", 800);
    WebBrowserPopupSizeWidthMax.Define("WebBrowserPopupSizeWidthMax", 850);
    WebBrowserPopupSizeHeightMin.Define("WebBrowserPopupSizeHeightMin", 1000);
    WebBrowserPopupSizeHeightMax.Define("WebBrowserPopupSizeHeightMax", 1003);
    MeratAirTaxiPrice.Define("MeratAirTaxiPrice", 390);
    MentorMaxWaitingCount.Define("MentorMaxWaitingCount", 100);
    MenteeMaxReceivedCount.Define("MenteeMaxReceivedCount", 20);
    SkillBookTreeAddTabFeeMerat.Define("SkillBookTreeAddTabFeeMerat", 1000u);
    MentorRequireLevel.Define("MentorRequireLevel", 50u);
    MenteeRequireLevel.Define("MenteeRequireLevel", 30u);
    MeratRevivalFeeReduceLimit.Define("MeratRevivalFeeReduceLimit", 0.5f);
    DailyPetEnchantMaxCount.Define("DailyPetEnchantMaxCount", 10u);
    FameContentsSkyFortressMapID.Define("FameContentsSkyFortressMapID");
    FameContentsSkyFortressGotoMapID.Define("FameContentsSkyFortressGotoMapID", 2000421u);
    FameContentsSkyFortressGotoPortalID.Define("FameContentsSkyFortressGotoPortalID", 1u);
    FameContentsSkyFortressBridgeID.Define("FameContentsSkyFortressBridgeID", 2000422u);
    FameContentsMissionAttackCount.Define("FameContentsMissionAttackCount", 10);
    FameContentsFieldQuestPickAccept.Define("FameContentsFieldQuestPickAccept", 91000012u);
    FameContentsFieldQuestPickComplete.Define("FameContentsFieldQuestPickComplete", 91000015u);
    UgcMarketNewMusicScoreItemID.Define("UgcMarketNewMusicScoreItemID", 35100001u);
    TreewateringEmotion.Define("TreewateringEmotion", 3000u);
    GamePadRumbleMultiple.Define("GamePadRumbleMultiple", 3.0f);
    GetOr("MesoRevivalFeeReduceLimit", &MesoRevivalFeeReduceLimit, 0.5f);
    GetOr("IngredientFeeReduceLimit", &IngredientFeeReduceLimit, 0.5f);
    unsigned char* statBytes = (unsigned char*)&StatPointLimit_str;
    for (int i = 0; i < 0x8c; i++)
        *statBytes++ = 0;
    GetOr("StatPointLimit_str", &StatPointLimit_str, 100);
    GetOr("StatPointLimit_dex", &StatPointLimit_dex, 100);
    GetOr("StatPointLimit_int", &StatPointLimit_int, 100);
    GetOr("StatPointLimit_luk", &StatPointLimit_luk, 100);
    GetOr("StatPointLimit_hp", &StatPointLimit_hp, 50);
    GetOr("StatPointLimit_cap", &StatPointLimit_cap, 50);
    AdventureLevelLvUpRewardItem.Define("AdventureLevelLvUpRewardItem", 0u);
    AdventureLevelLvUpExp.Define("AdventureLevelLvUpExp", 15000u);
    AdventureLevelMaxExp.Define("AdventureLevelMaxExp", 10000u);
    AdventureLevelStartLevel.Define("AdventureLevelStartLevel", 50u);
    AdventureLevelLimit.Define("AdventureLevelLimit", 10000u);
    ConstructExpMaxCount.Define("ConstructExpMaxCount", 100u);
    NurturingEatMaxCount.Define("NurturingEatMaxCount", 6u);
    NurturingPlayMaxCount.Define("NurturingPlayMaxCount", 2u);
    NurturingQuestTag.Define("NurturingQuestTag", CStringW(L"20180524_RainbowSlime"));
    NurturingDuration.Define("NurturingDuration", 3000u);
    NurturingInteractionDistance.Define("NurturingInteractionDistance", 150u);
    NurturingEatGrowth.Define("NurturingEatGrowth", 10u);
    NurturingPlayGrowth.Define("NurturingPlayGrowth", 10u);
    NurturingPlayMaxGrowth.Define("NurturingPlayMaxGrowth", 30u);
    NurturingHungryTime.Define("NurturingHungryTime", 3600000u);
    GetOr("SkillPointLimitLevel1", &SkillPointLimitLevel1, 80);
    GetOr("SkillPointLimitLevel2", &SkillPointLimitLevel2, 100);
    EnchantEquipIngredientMaxCount.Define("EnchantEquipIngredientMaxCount", 10u);
    EnchantFailStackUsingMaxCount.Define("EnchantFailStackUsingMaxCount", 10u);
    EnchantFailStackTakeMaxCount.Define("EnchantFailStackTakeMaxCount", 10u);
    EnchantEquipIngredientOpenRank.Define("EnchantEquipIngredientOpenRank", 4);
    EnchantEquipIngredientOpenLevel.Define("EnchantEquipIngredientOpenLevel", 11);
    EnchantFailStackOpenLevel.Define("EnchantFailStackOpenLevel", 11);
    EnchantFailStackTakeMaxSuccessProb.Define("EnchantFailStackTakeMaxSuccessProb", 10000u);
    EnchantEquipIngredientMaxSuccessProb.Define("EnchantEquipIngredientMaxSuccessProb", 10000u);
    EnchantItemBindingRequireLevel.Define("EnchantItemBindingRequireLevel", 1u);
    HomePVPRevivalItemId.Define("HomePVPRevivalItemId", 50200911u);
    GetOr("SummonRideSkillID", &SummonRideSkillID, 80000001);
    GetOr("HoldAttackSkillID", &HoldAttackSkillID, 10700252);
    GetOr("GlideItemSkillID", &GlideItemSkillID, 80010001);
    GetOr("GmGlideSkillID", &GmGlideSkillID, 19900011);
    SellPriceNormalMax.Define("SellPriceNormalMax", 0u);
    SellPriceRareMax.Define("SellPriceRareMax", 0u);
    SellPriceEliteMax.Define("SellPriceEliteMax", 0u);
    SellPriceExcellentMax.Define("SellPriceExcellentMax", 0u);
    SellPriceLegendaryMax.Define("SellPriceLegendaryMax", 0u);
    SellPriceArtifactMax.Define("SellPriceArtifactMax", 0u);
    PetNameLengthMin.Define("PetNameLengthMin", 2);
    PetNameLengthMax.Define("PetNameLengthMax", 12);
    GuildNameLengthMin.Define("GuildNameLengthMin", 2);
    GuildNameLengthMax.Define("GuildNameLengthMax", 10);
    ClubNameLengthMin.Define("ClubNameLengthMin", 2);
    ClubNameLengthMax.Define("ClubNameLengthMax", 12);
    UgcNameLengthMin.Define("UgcNameLengthMin", 3);
    UgcNameLengthMax.Define("UgcNameLengthMax", 14);
    UgcTagLengthMax.Define("UgcTagLengthMax", 6);
    ChangeJobLevel.Define("ChangeJobLevel", 14u);
    tierItems.SetCount(7, 0xffffffff);
    tierItems.SetAt(1, &SellPriceNormalMax);
    tierItems.SetAt(2, &SellPriceRareMax);
    tierItems.SetAt(3, &SellPriceEliteMax);
    tierItems.SetAt(4, &SellPriceExcellentMax);
    tierItems.SetAt(5, &SellPriceLegendaryMax);
    tierItems.SetAt(6, &SellPriceArtifactMax);
    LapenShardOpenQuestID.Define("LapenShardOpenQuestID", std::vector<unsigned>());
    MaidNameLengthMin.Define("MaidNameLengthMin", 1);
    MaidNameLengthMax.Define("MaidNameLengthMax", 12);
    MaidDescLengthMin.Define("MaidDescLengthMin", 1);
    MaidDescLengthMax.Define("MaidDescLengthMax", 16);
    gemPetSkinBaseItemID.Define("gemPetSkinBaseItemID", 70100000u);
    bool limitMeratRevivalDefault = false;
    GetOr("LimitMeratRevival", &LimitMeratRevival, &limitMeratRevivalDefault);
    GetOr("MaxClosetMaxCount", &MaxClosetMaxCount, 5);
    GetOr("MaxClosetTabNameLength", &MaxClosetTabNameLength, 10);
    GetOr("SummonPetSkillID", &SummonPetSkillID, 82100001);
    UGCMapSetItemEffectCountLimit.Define("UGCMapSetItemEffectCountLimit", 3);
    GetOr("StatScaleMarkingAdditionalEffect", &StatScaleMarkingAdditionalEffect, 0);
    ItemBoxMultiOpenMaxCount.Define("ItemBoxMultiOpenMaxCount", 20);
    ItemBoxMultiOpenLimitCount.Define("ItemBoxMultiOpenLimitCount", 1000);
    WeddingProposeItemID.Define("WeddingProposeItemID", 11600482u);
    WeddingInvitationMaxCount.Define("WeddingInvitationMaxCount", 70u);
    WeddingProposeCooltime.Define("WeddingProposeCooltime", 2u);
    WeddingDivorceFieldID.Define("WeddingDivorceFieldID", 84000002u);
    WeddingInvitationMeso.Define("WeddingInvitationMeso", 1000u);
    WeddingDivorceMeso.Define("WeddingDivorceMeso", 1000000u);
    WeddingCoolingOffDay.Define("WeddingCoolingOffDay", 7u);
    WeddingPromiseLimitDay.Define("WeddingPromiseLimitDay", 7u);
    WeddingHallModifyLimitHour.Define("WeddingHallModifyLimitHour", 3u);
    WeddingDivorceRequireMarriageDay.Define("WeddingDivorceRequireMarriageDay", 30u);
    PaybackStartDate.Define("PaybackStartDate", 0);
    PaybackEndDate.Define("PaybackEndDate", 0);
    PaybackRewardMinutes.Define("PaybackRewardMinutes", 5);
    unsigned short adventureLevel = 30;
    AdventureProtectedRequireLevel.Define("AdventureProtectedRequireLevel", adventureLevel);
    AdventureProtectedRequireQuest.Define("AdventureProtectedRequireQuest", 50001605u);
    AdventureProtectedCharCreateTime.Define("AdventureProtectedCharCreateTime", 72);
    DeleteAccountPendingDay.Define("DeleteAccountPendingDay", 60u);
    unsigned pendingDay = *DeleteAccountPendingDay.Get() < 7 ? 7 : *DeleteAccountPendingDay.Get();
    DeleteAccountPendingDay.Set(pendingDay);
    PvpOnePunchRewardItem.Define("PvpOnePunchRewardItem", 0);
    for (int i = 0; i < 10; i++)
    {
        CString key = StringFormat("PvpOnePunchReward{0}Count", i + 1);
        PvpOnePunchRewardCount[i].Define(key, 0);
    }
    PvpOnePunchScoreNpcKill.Define("PvpOnePunchScoreNpcKill", -7);
    BothHandGearScorePenaltyDiv.Define("BothHandGearScorePenaltyDiv", 4.0f);

}

// @0x1402bab30
// MS2-FUNCTIONAL: exe reads each Value<float> through the out-of-line Read getter; the inline getter here differs in register use
extern float g_ClientConstantsFloats[7];   // 0x1439ed010
void FUN_1402bab30()
{
    Client::Constants* c = static_cast<Client::Constants*>(FUN_1401d3200());
    g_ClientConstantsFloats[0] = c->NPCColorScale.Read();
    c = static_cast<Client::Constants*>(FUN_1401d3200());
    g_ClientConstantsFloats[1] = c->NPCDuration.Read();
    c = static_cast<Client::Constants*>(FUN_1401d3200());
    g_ClientConstantsFloats[2] = c->PCColorScale.Read();
    c = static_cast<Client::Constants*>(FUN_1401d3200());
    g_ClientConstantsFloats[3] = c->PCDuration.Read();
    c = static_cast<Client::Constants*>(FUN_1401d3200());
    g_ClientConstantsFloats[4] = c->GetEXPColorScale.Read();
    c = static_cast<Client::Constants*>(FUN_1401d3200());
    g_ClientConstantsFloats[5] = c->GetEXPDuration.Read();
    c = static_cast<Client::Constants*>(FUN_1401d3200());
    g_ClientConstantsFloats[6] = c->AccumulationRatio.Read();
}

// @0x1402bbae0
bool Common::Constants::GetOr(const CString& key, CStringW* out, const CStringW& def)
{
    if (!Lookup(key, out))
    {
        *out = def;
        return false;
    }
    return true;
}

// ---- constants.xml loader -----------------------------------------------------------------------------------------
// Unrecovered xml helpers (the same ones the table units use).
class Unk_ConstXmlNode { public: Unk_ConstXmlNode* FUN_140165cf0(const char* name); };
class Unk_ConstXmlList
{
public:
    void FUN_140163e20();                                       // ctor
    void FUN_1401644e0();                                       // dtor
    unsigned __int64 FUN_14016d900();                           // size
    Unk_ConstXmlNode*& FUN_140164a30(unsigned __int64 n);       // operator[]
    void *m_a, *m_b, *m_c;
};
class Unk_ConstFileSystem
{
public:
    int FUN_1403974b0(TiXmlDocument* doc, const char* path, int encoding, bool warn, bool localOnly);
    bool FUN_140398190();
};
Unk_ConstFileSystem* FUN_140166420();
unsigned char FUN_1401d1320(CCacheData* cacheData);
void* FUN_140166440();
void FUN_14015eb90(void* log, int level, int category, const wchar_t* fmt, const CString& arg);
CString FUN_14071a5b0(const CString& dir, const CString& file);
CString FUN_14071a6f0(const CString& file);
void FUN_14028faa0(Unk_ConstXmlNode* parent, const char* name, const char* attr, Unk_ConstXmlList* out);
int FUN_1408733e0(Unk_ConstXmlNode* node, const char* name, CString& out);

// One xml file to read; `required` makes a missing file an error.
struct Unk_ConstFile
{
    CString path;
    bool required;
    // @0x1402bac00
    Unk_ConstFile(CString& p, const bool& r) : path(std::forward<CString>(p)), required(std::forward<const bool&>(r)) {}
};

// @0x1402b2010
// MS2-FUNCTIONAL: the exe builds the file-name temporaries and entries in place with early destruction; no source form found
bool Common::Constants::LoadFiles()
{
    values.RemoveAll();
    ATL::CAtlArray<Unk_ConstFile> files;
    {
        bool required = true;
        CString file("constants.xml");
        CString dir("Table");
        CString path = FUN_14071a5b0(dir, file);
        files.Add(Unk_ConstFile(path, required));
    }
    {
        bool required = true;
        CString file("colorConstants.xml");
        CString dir("Table");
        CString path = FUN_14071a5b0(dir, file);
        files.Add(Unk_ConstFile(path, required));
    }
    if (!FUN_140166420()->FUN_140398190())
    {
        bool required = false;
        CString file("testConstants.xml");
        CString path = FUN_14071a6f0(file);
        files.Add(Unk_ConstFile(path, required));
    }
    cacheRefs.RemoveAll();
    for (size_t i = 0; i < files.GetCount(); i++)
    {
        Unk_ConstFile& entry = files[i];
        bool required = entry.required;
        TiXmlDocument doc;
        const char* path = entry.path;
        if (FUN_140166420()->FUN_1403974b0(&doc, path, 0, true, false) == 0)
        {
            if (required)
            {
                FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", entry.path);
                return false;
            }
            continue;
        }
        CCacheData* cacheData = new CCacheData();
        Unk_ConstCacheRef ref(cacheData);
        if (ref.get() != 0)
        {
            ref.get()->FUN_1401d1160(CString(entry.path));
            cacheRefs.Add(ref);
        }
        Unk_ConstXmlNode* root = reinterpret_cast<Unk_ConstXmlNode*>(&doc)->FUN_140165cf0("ms2");
        if (root == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", entry.path);
            return false;
        }
        Unk_ConstXmlList list;
        list.FUN_140163e20();
        FUN_14028faa0(root, "v", "key", &list);
        for (unsigned __int64 n = 0; n < list.FUN_14016d900(); n++)
        {
            Unk_ConstXmlNode* node = list.FUN_140164a30(n);
            if (node != 0)
            {
                CString key;
                CString value;
                FUN_1408733e0(node, "key", key);
                FUN_1408733e0(node, "value", value);
                values.SetAt(key, value);
            }
        }
        list.FUN_1401644e0();
    }
    return true;
}
// @0x1402b7200
// MS2-FUNCTIONAL: exe returns the saved flag through a bool compare
bool Common::Constants::Load()
{
    bool ok = LoadFiles();
    if (ok)
        vfunc_0();
    return ok;
}
// @0x1402b7240
void Common::Constants::Reload()
{
    for (unsigned i = 0; i < cacheRefs.GetCount(); i++)
    {
        if (FUN_1401d1320(cacheRefs[i].get()))
        {
            Load();
            return;
        }
    }
}

// @0x1402b8590
// MS2-FUNCTIONAL: long generated body; default-argument temporaries differ from the exe, values are identical
void Client::Constants::vfunc_0()
{
    Common::Constants::vfunc_0();
    NameTagColorFriendly.Define("NameTagColorFriendly", Unk_ConstColor(0x0));
    NameTagColorMob.Define("NameTagColorMob", Unk_ConstColor(0x0));
    NameTagColorLeader.Define("NameTagColorLeader", Unk_ConstColor(0x0));
    NameTagColorNamed.Define("NameTagColorNamed", Unk_ConstColor(0x0));
    NameTagColorBoss.Define("NameTagColorBoss", Unk_ConstColor(0x0));
    NameTagColorMyPC.Define("NameTagColorMyPC", Unk_ConstColor(0x0));
    NameTagColorPC.Define("NameTagColorPC", Unk_ConstColor(0x0));
    NameTagColorPCHostile.Define("NameTagColorPCHostile", Unk_ConstColor(0x0));
    NameTagColorParty.Define("NameTagColorParty", Unk_ConstColor(0x0));
    NameTagColorDead.Define("NameTagColorDead", Unk_ConstColor(0x0));
    meso.Define("meso", Unk_ConstColor(0x0));
    merat.Define("merat", Unk_ConstColor(0x0));
    meratCancel.Define("meratCancel", Unk_ConstColor(0x0));
    job.Define("job", MS2Colors());
    exp.Define("exp", Unk_ConstColor(0x0));
    categoryColor.Define("categoryColor", MS2Colors());
    ATL::CAtlArray<Unk_ConstColor> outlineColors;
    outlineColor.Define("outlineColor", &outlineColors);
    outlineBoost.Define("outlineBoost", 0.0f);
    chatUserNormal.Define("chatUserNormal", Unk_ConstColor(0xffffff));
    chatUserNotice.Define("chatUserNotice", Unk_ConstColor(0xffffff));
    chatUserWhisper.Define("chatUserWhisper", Unk_ConstColor(0xffffff));
    chatUserMapNotice.Define("chatUserMapNotice", Unk_ConstColor(0xffffff));
    chatUserParty.Define("chatUserParty", Unk_ConstColor(0xffffff));
    chatUserGuild.Define("chatUserGuild", Unk_ConstColor(0xffffff));
    chatUserClub.Define("chatUserClub", Unk_ConstColor(0xffffff));
    chatUserSuper.Define("chatUserSuper", Unk_ConstColor(0xffffff));
    chatUserWorld.Define("chatUserWorld", Unk_ConstColor(0xffffff));
    chatUserChannel.Define("chatUserChannel", Unk_ConstColor(0xffffff));
    chatTextNormal.Define("chatTextNormal", Unk_ConstColor(0xffffff));
    chatTextNotice.Define("chatTextNotice", Unk_ConstColor(0xffffff));
    chatTextMapNotice.Define("chatTextMapNotice", Unk_ConstColor(0xffffff));
    chatTextWhisperTo.Define("chatTextWhisperTo", Unk_ConstColor(0xffffff));
    chatTextWhisperFail.Define("chatTextWhisperFail", Unk_ConstColor(0xffffff));
    chatTextWhisperFrom.Define("chatTextWhisperFrom", Unk_ConstColor(0xffffff));
    chatTextParty.Define("chatTextParty", Unk_ConstColor(0xffffff));
    chatTextGuild.Define("chatTextGuild", Unk_ConstColor(0xffffff));
    chatTextClub.Define("chatTextClub", Unk_ConstColor(0xffffff));
    chatTextSuper.Define("chatTextSuper", Unk_ConstColor(0xffffff));
    chatTextWorld.Define("chatTextWorld", Unk_ConstColor(0xffffff));
    chatTextChannel.Define("chatTextChannel", Unk_ConstColor(0xffffff));
    chatTextSystemMessage.Define("chatTextSystemMessage", Unk_ConstColor(0xffffff));
    chatTextMinorSystemMessage.Define("chatTextMinorSystemMessage", Unk_ConstColor(0xffffff));
    chatTextGMColor.Define("chatTextGMColor", Unk_ConstColor(0xffffff));
    EnableSkillJumpDown.Define("EnableSkillJumpDown", 0);
    SkillGlobalCooldown.Define("SkillGlobalCooldown", 0.5f);
    SkillGlobalCooldown_CheckSameSkill.Define("SkillGlobalCooldown_CheckSameSkill", 0);
    NPCColorScale.Define("NPCColorScale", 0.0f);
    NPCDuration.Define("NPCDuration", 0.0f);
    PCColorScale.Define("PCColorScale", 0.0f);
    PCDuration.Define("PCDuration", 0.0f);
    GetEXPColorScale.Define("GetEXPColorScale", 0.0f);
    GetEXPDuration.Define("GetEXPDuration", 0.0f);
    AccumulationRatio.Define("AccumulationRatio", 0.0f);
    ShopSellConfirmPrice.Define("ShopSellConfirmPrice", 0u);
    ShopBuyConfirmPrice.Define("ShopBuyConfirmPrice", 0u);
    ShowKillCountMin.Define("ShowKillCountMin", 3);
    UgcshopCharCameraLookat.Define("UgcshopCharCameraLookat", efd::Point3());
    UgcshopCharCameraPos.Define("UgcshopCharCameraPos", efd::Point3());
    UgcshopCharCameraMinDistance.Define("UgcshopCharCameraMinDistance", 0.0f);
    UgcshopCharCameraZoomVelocity.Define("UgcshopCharCameraZoomVelocity", 100.0f);
    UgcshopCubeCameraLookat.Define("UgcshopCubeCameraLookat", efd::Point3());
    UgcshopCubeCameraPos.Define("UgcshopCubeCameraPos", efd::Point3());
    UgcshopCubeCameraMinDistance.Define("UgcshopCubeCameraMinDistance", 0.0f);
    UgcshopCubeCameraZoomVelocity.Define("UgcshopCubeCameraZoomVelocity", 100.0f);
    UgcshopRideeCameraLookat.Define("UgcshopRideeCameraLookat", efd::Point3());
    UgcshopRideeCameraPos.Define("UgcshopRideeCameraPos", efd::Point3());
    UgcshopRideeCameraMinDistance.Define("UgcshopRideeCameraMinDistance", 0.0f);
    UgcshopRideeCameraZoomVelocity.Define("UgcshopRideeCameraZoomVelocity", 100.0f);
    UgcshopCharRotateStartDegreeY.Define("UgcshopCharRotateStartDegreeY", 0.0f);
    UgcshopCharRotateEndDegreeY.Define("UgcshopCharRotateEndDegreeY", 360);
    OffsetActionTooltipX.Define("OffsetActionTooltipX", 50);
    OffsetActionTooltipY.Define("OffsetActionTooltipY", -30);
    DamageEffectMinHPPercent.Define("DamageEffectMinHPPercent", 0.0f);
    DamageEffectCriticalPercent.Define("DamageEffectCriticalPercent", 0.0f);
    DamageGap.Define("DamageGap", 0);
    DamageRenderCount.Define("DamageRenderCount", 0);
    DamageRenderTotalCount.Define("DamageRenderTotalCount", 0);
    DamageOtherScale.Define("DamageOtherScale", 0.0f);
    DamageOtherAlpha.Define("DamageOtherAlpha", 0.0f);
    UserRevivalIconPath.Define("UserRevivalIconPath", CString());
    UserRevivalInvincibleIconPath.Define("UserRevivalInvincibleIconPath", CString());
    UserPortalInvincibleIconPath.Define("UserPortalInvincibleIconPath", CString());
    BossHpBarAutoDetectRange.Define("BossHpBarAutoDetectRange", 1000.0f);
    BossHpBarDuration.Define("BossHpBarDuration", 5.0f);
    mirrorGuideMoviePath.Define("mirrorGuideMoviePath", "");
    hairGuideMoviePath.Define("hairGuideMoviePath", "");
    makeUpGuideMoviePath.Define("makeUpGuideMoviePath", "");
    SmartRecommendNotify_DurationTick.Define("SmartRecommendNotify_DurationTick", 10000u);
    FastShimmerRadius.Define("FastShimmerRadius", 600.0f);
    FastShimmerHeight.Define("FastShimmerHeight", 450.0f);
    charCreateGuideMoviePath.Define("charCreateGuideMoviePath", "");
    KeyIsDownSkill_MaxDurationTick.Define("KeyIsDownSkill_MaxDurationTick", 30000u);
    WorldmapBossTooltipCount.Define("WorldmapBossTooltipCount", 9);
    BossNotifyAbsLevel.Define("BossNotifyAbsLevel", 5);
    RoomExitWaitSecond.Define("RoomExitWaitSecond", 10);
    BossShimmerScaleUpActiveDistance.Define("BossShimmerScaleUpActiveDistance", 5000.0f);
    BossShimmerScaleUpSize.Define("BossShimmerScaleUpSize", 3.0f);
    FUN_1402bab30();
    BossKillSoundRange.Define("BossKillSoundRange", 1500.0f);
    ShowNameTagEnchantItemGrade.Define("ShowNameTagEnchantItemGrade", 4);
    ShowNameTagEnchantLevel.Define("ShowNameTagEnchantLevel", 7);
    MeratMarketHomeBannerShowTick.Define("MeratMarketHomeBannerShowTick", 6000);
    ShadowWorldAutoReviveDeadAction.Define("ShadowWorldAutoReviveDeadAction", 1);
    GoodIteriorRecommendUICloseTime.Define("GoodIteriorRecommendUICloseTime", 10);
    UGCInfoDetailViewPage.Define("UGCInfoDetailViewPage", "http://maplestory2.nexon.com/");
    UGCInfoStoryBookID.Define("UGCInfoStoryBookID", 0);
    WriteMusicDetailWebPage.Define("WriteMusicDetailWebPage", "http://maplestory2.nexon.com/");
    WriteMusicStoryBookID.Define("WriteMusicStoryBookID", 0);
    MusicListenInRadius.Define("MusicListenInRadius", 900.0f);
    MusicListenOutRadius.Define("MusicListenOutRadius", 2200.0f);
    TriggerEditorHelpURL.Define("TriggerEditorHelpURL", "maview:/Encyclopedia/MapView?c=02000087");
    CashCallMedicLeaveDelay.Define("CashCallMedicLeaveDelay", 0.0f);
    NoticeDialogUrl.Define("NoticeDialogUrl", "");
    NoticeDialogOpenSeconds.Define("NoticeDialogOpenSeconds", 0u);
    ATL::CAtlArray<unsigned int> worldmapNpcIds;
    ATL::CAtlArray<CString> worldmapTexts;
    WorldmapSpecialFunctionNpcID.Define("WorldmapSpecialFunctionNpcID", &worldmapNpcIds);
    WorldmapSpecialFunctionNpcFrame.Define("WorldmapSpecialFunctionNpcFrame", &worldmapTexts);
    WorldmapSpecialFunctionNpcTooltip.Define("WorldmapSpecialFunctionNpcTooltip", &worldmapTexts);
    fisherBoreDuration.Define("fisherBoreDuration", 3000u);
    fishingStartCastingBarText.Define("fishingStartCastingBarText", &worldmapTexts);
    fishingStartBalloonText.Define("fishingStartBalloonText", &worldmapTexts);
    fishFightingCastingBarText.Define("fishFightingCastingBarText", &worldmapTexts);
    fishFightingBalloonText.Define("fishFightingBalloonText", &worldmapTexts);
    MinimapScaleSkipDuration.Define("MinimapScaleSkipDuration", 5000u);
    MinimapScaleSkipSplitPixel.Define("MinimapScaleSkipSplitPixel", 50u);
    CashshopFigureAddressPage.Define("CashshopFigureAddressPage", "http://maplestory2.nexon.com/cashshop/address");
    TencentSecurityWebPage.Define("TencentSecurityWebPage", "");
    TencentCashChargeWebPage.Define("TencentCashChargeWebPage", "");
    TencentCashChargeWebPageWidth.Define("TencentCashChargeWebPageWidth", 575);
    TencentCashChargeWebPageHight.Define("TencentCashChargeWebPageHight", 476);
    NxaCashChargeWebPageWidth.Define("NxaCashChargeWebPageWidth", 650);
    NxaCashChargeWebPageHight.Define("NxaCashChargeWebPageHight", 650);
    extendAutoFishMaxCount.Define("extendAutoFishMaxCount", 8u);
    extendAutoPlayInstrumentMaxCount.Define("extendAutoPlayInstrumentMaxCount", 8u);
    GatheringObjectMarkOffsetX.Define("GatheringObjectMarkOffsetX", 0.0f);
    GatheringObjectMarkOffsetY.Define("GatheringObjectMarkOffsetY", 0.0f);
    BreedingObjectMarkOffsetX.Define("BreedingObjectMarkOffsetX", 0.0f);
    BreedingObjectMarkOffsetY.Define("BreedingObjectMarkOffsetY", 0.0f);
    UGCAttention.Define("UGCAttention", 1);
    UGCInfringementCenter.Define("UGCInfringementCenter", 1);
    MasteryObjectInteractionDistance.Define("MasteryObjectInteractionDistance", 150.0f);
    CharacterSelectBoreIdleEffect_Ranger.Define("CharacterSelectBoreIdleEffect_Ranger", "");
    CharacterSelectBoreIdleEffect_SoulBinder.Define("CharacterSelectBoreIdleEffect_SoulBinder", "");
    AutoPressActionKeyDuration.Define("AutoPressActionKeyDuration", 500u);
    GlobalPortalMinLevel.Define("GlobalPortalMinLevel", 0u);
    CoupleEffectCheckTick.Define("CoupleEffectCheckTick", 5000u);
    CoupleEffectCheckRadius.Define("CoupleEffectCheckRadius", 500.0f);
    GetOr("BirthdayFieldID", &BirthdayFieldID, 19);
    MouseCursorHideTime.Define("MouseCursorHideTime", 30u);
    AutoHideGroupAlpha.Define("AutoHideGroupAlpha", 0.6f);
    AutoHideGroupHitVisibleTick.Define("AutoHideGroupHitVisibleTick", 3000u);
    NameColorDeadDuration.Define("NameColorDeadDuration", 2000u);
    ShopProbInfoUrl.Define("ShopProbInfoUrl", "");
    RegionServerUrl_de.Define("RegionServerUrl_de", "");
    RegionServerUrl_en.Define("RegionServerUrl_en", "");
    RegionServerUrl_bpo.Define("RegionServerUrl_bpo", "");
    GetOr("TooltipLabelMaxWidth", &TooltipLabelMaxWidth, 0);
    GamePadStickMoveValue.Define("GamePadStickMoveValue", 50);
    GetOr("RpgModeMoviePath", &RpgModeMoviePath, CStringW(L""));
    GetOr("RoyaleModeMoviePath", &RoyaleModeMoviePath, CStringW(L""));
    HighlightMenuUsingLevel.Define("HighlightMenuUsingLevel", 1u);
    MouseInteractLimitDistance.Define("MouseInteractLimitDistance", 2000u);
    GetOr("PartyVoteReadyTagExpireSeconds", &PartyVoteReadyTagExpireSeconds, 10);
    ShieldBarOffsetY.Define("ShieldBarOffsetY", -10);
    AutoInstallEquipmentMinLevel.Define("AutoInstallEquipmentMinLevel", 5u);
    AutoInstallEquipmentMaxLevel.Define("AutoInstallEquipmentMaxLevel", 99u);
    Lookup("PartySearchRegisterComboValues", &PartySearchRegisterComboValues);
    WorldMapShadowUsingContinent.Define("WorldMapShadowUsingContinent", 0);
    Lookup("DungeonRewardFailEmotions", &DungeonRewardFailEmotions);
    DiscordAppID.Define("DiscordAppID", "555204064091045904");
    ItemGachaBoxProbabilityUrl.Define("ItemGachaBoxProbabilityUrl", "");
    DeleteAccountTermsUrl.Define("DeleteAccountTermsUrl", "");
    PersonalInfoAgreementURL.Define("PersonalInfoAgreementURL", "");
    TencentUserConsultationWebPage.Define("TencentUserConsultationWebPage", "");
    TencentPricavyGuideWebPage.Define("TencentPricavyGuideWebPage", "");
    TencentThirdPartyInformationSharingListWebPage.Define("TencentThirdPartyInformationSharingListWebPage", "");
}


// ---- 4-byte element array instantiations that exist in the exe without a recovered caller of their own -----------
template size_t ATL::CAtlArray<int, ATL::CElementTraits<int> >::Append(const ATL::CAtlArray<int, ATL::CElementTraits<int> >&);

// @0x1402bf9a0
CString Unk_SocketFormat(const char* format, const fmt::ArgList& args)
{
    return StringFormat(format, args);
}
template size_t ATL::CAtlArray<unsigned long, ATL::CElementTraits<unsigned long> >::Append(const ATL::CAtlArray<unsigned long, ATL::CElementTraits<unsigned long> >&);

// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9a590-0x142c9a5b0 .text$yd
