// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Character mesh merger: merges skinned NiMeshes per material group,
// packs the character textures into an atlas and saves debug NIFs.
// MS2-UNIT: client\ms2\charactermeshmerger.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x141049240-0x141073440 .text$mn
// MS2-RANGE: 0x1400e4c80-0x1400e4e20 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141053360 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1410534a0 ; fx19 chain
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141053520 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141053560 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141053890 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1410538e0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141053930 ; fx19 chain
// MS2-PIN: ??$?0AEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141053ed0 ; prop
// MS2-PIN: ??$?0PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@$0A@@?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@QEAA@$$QEAU?$pair@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@1@@Z 0x1410540b0 ; unique
// MS2-PIN: ??$?0V?$CustomAllocator@U?$_Tree_node@EPEAX@std@@@efd@@@?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEAA@AEBV01@$$QEAV?$CustomAllocator@U?$_Tree_node@EPEAX@std@@@efd@@@Z 0x1410543f0 ; prop
// MS2-PIN: ??$?0V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@@?$_Tree@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAA@AEBV01@$$QEAV?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@@Z 0x141054520 ; prop
// MS2-PIN: ??$?0V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@X@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAA@AEBU?$less@PEAVNiAVObject@@@1@$$QEAV?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@@Z 0x1410545a0 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x141054950 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1410549a0 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1410549f0 ; fx19 chain
// MS2-PIN: ??$_Buynode@AEAPEAVNiAVObject@@@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@1@AEAPEAVNiAVObject@@@Z 0x141055260 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@1@$$QEAU?$pair@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@1@@Z 0x141055760 ; fx19 chain
// MS2-PIN: ??$_Buynode@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@1@@Z 0x141055880 ; prop
// MS2-PIN: ??$_Construct1@PEAU?$_Tree_node@PEAVNiAVObject@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@1@AEAPEAU51@@Z 0x141055ae0 ; unique
// MS2-PIN: ??$_Construct1@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@1@AEAPEAU51@@Z 0x141055b80 ; prop
// MS2-PIN: ??$_Construct1@PEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@1@AEAPEAU51@@Z 0x141055c20 ; fx19 chain
// MS2-PIN: ??$_Construct1@PEAVNiAVObject@@AEAPEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@PEAVNiAVObject@@@efd@@PEAPEAVNiAVObject@@AEAPEAV5@@Z 0x141055da0 ; prop
// MS2-PIN: ??$_Construct1@PEAVNiAVObject@@AEBQEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@PEAPEAVNiAVObject@@AEBQEAV5@@Z 0x141055d10 ; unique
// MS2-PIN: ??$_Construct1@PEAVNiAVObject@@PEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@PEAVNiAVObject@@@efd@@PEAPEAVNiAVObject@@$$QEAPEAV5@@Z 0x141055d60 ; prop
// MS2-PIN: ??$_Construct1@PEAVNiMesh@@AEBQEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@PEAVNiMesh@@@efd@@PEAPEAVNiMesh@@AEBQEAV5@@Z 0x141055e20 ; fx19 chain
// MS2-PIN: ??$_Construct1@PEAVNiMesh@@PEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@PEAVNiMesh@@@efd@@PEAPEAVNiMesh@@$$QEAPEAV5@@Z 0x141055e60 ; fx19 chain
// MS2-PIN: ??$_Construct1@UUnk_AtlasResult@@AEAU1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@PEAUUnk_AtlasResult@@AEAU5@@Z 0x1410564f0 ; fx19 chain
// MS2-PIN: ??$_Construct1@UUnk_AtlasResult@@AEBU1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@PEAUUnk_AtlasResult@@AEBU5@@Z 0x141056530 ; fx19 chain
// MS2-PIN: ??$_Construct1@UUnk_AtlasResult@@U1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@PEAUUnk_AtlasResult@@$$QEAU5@@Z 0x141056570 ; fx19 chain
// MS2-PIN: ??$_Construct1@V?$map@EEU?$less@E@std@@@efd@@AEAV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@PEAV?$map@EEU?$less@E@std@@@4@AEAV54@@Z 0x141056230 ; fx19 chain
// MS2-PIN: ??$_Construct1@V?$map@EEU?$less@E@std@@@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@PEAV?$map@EEU?$less@E@std@@@4@$$QEAV54@@Z 0x141056270 ; prop
// MS2-PIN: ??$_Construct1@V?$set@EU?$less@E@std@@@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@PEAV?$set@EU?$less@E@std@@@4@$$QEAV54@@Z 0x1410562f0 ; fx19 chain
// MS2-PIN: ??$_Construct1@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@AEAV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@4@AEAV54@@Z 0x141056330 ; fx19 chain
// MS2-PIN: ??$_Construct1@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@4@$$QEAV54@@Z 0x141056370 ; fx19 chain
// MS2-PIN: ??$_Construct1@V?$vector@E@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@E@efd@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$vector@E@efd@@@efd@@PEAV?$vector@E@4@$$QEAV54@@Z 0x1410563f0 ; fx19 chain
// MS2-PIN: ??$_Construct1@V?$vector@PEAVNiMesh@@@efd@@AEAV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@PEAV?$vector@PEAVNiMesh@@@4@AEAV54@@Z 0x141056430 ; fx19 chain
// MS2-PIN: ??$_Construct1@V?$vector@PEAVNiMesh@@@efd@@AEBV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@PEAV?$vector@PEAVNiMesh@@@4@AEBV54@@Z 0x141056470 ; fx19 chain
// MS2-PIN: ??$_Construct1@V?$vector@PEAVNiMesh@@@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@PEAV?$vector@PEAVNiMesh@@@4@$$QEAV54@@Z 0x1410564b0 ; prop
// MS2-PIN: ??$_Copy_nodes@U_Copy_tag@?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@EPEAX@1@PEAU21@0U_Copy_tag@01@@Z 0x141056cc0 ; unique
// MS2-PIN: ??$_Copy_or_move@EU?$integral_constant@_N$00@std@@@?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@EPEAX@1@AEAEU_Copy_tag@01@U?$integral_constant@_N$00@1@@Z 0x141056ee0 ; prop
// MS2-PIN: ??$_Destroy1@PEAU?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@1@U?$integral_constant@_N$00@1@@Z 0x1410570b0 ; unique
// MS2-PIN: ??$_Destroy1@PEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@1@U?$integral_constant@_N$00@1@@Z 0x1410570c0 ; unique
// MS2-PIN: ??$_Destroy1@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@1@U?$integral_constant@_N$00@1@@Z 0x1410570d0 ; unique
// MS2-PIN: ??$_Destroy1@PEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@1@U?$integral_constant@_N$00@1@@Z 0x1410570e0 ; unique
// MS2-PIN: ??$_Destroy1@PEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@1@U?$integral_constant@_N$00@1@@Z 0x1410570f0 ; fx19 chain
// MS2-PIN: ??$_Destroy1@PEAVNiAVObject@@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVNiAVObject@@@efd@@PEAPEAVNiAVObject@@U?$integral_constant@_N$0A@@1@@Z 0x141057120 ; unique
// MS2-PIN: ??$_Destroy1@PEAVNiAVObject@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@PEAPEAVNiAVObject@@U?$integral_constant@_N$00@1@@Z 0x141057110 ; unique
// MS2-PIN: ??$_Destroy1@PEAVNiMesh@@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVNiMesh@@@efd@@PEAPEAVNiMesh@@U?$integral_constant@_N$0A@@1@@Z 0x141057150 ; fx19 chain
// MS2-PIN: ??$_Destroy1@U?$pair@$$CBEE@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@PEAU?$pair@$$CBEE@1@U?$integral_constant@_N$00@1@@Z 0x141057180 ; unique
// MS2-PIN: ??$_Destroy1@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@PEAU?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@1@U?$integral_constant@_N$00@1@@Z 0x1410571c0 ; unique
// MS2-PIN: ??$_Destroy1@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@PEAU?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@1@U?$integral_constant@_N$00@1@@Z 0x1410571f0 ; prop
// MS2-PIN: ??$_Destroy1@UUnk_AtlasResult@@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@SAXAEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@PEAUUnk_AtlasResult@@U?$integral_constant@_N$0A@@1@@Z 0x141057320 ; fx19 chain
// MS2-PIN: ??$_Destroy1@V?$set@EU?$less@E@std@@@efd@@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@PEAV?$set@EU?$less@E@std@@@3@U?$integral_constant@_N$0A@@1@@Z 0x141057260 ; fx19 chain
// MS2-PIN: ??$_Destroy1@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@3@U?$integral_constant@_N$0A@@1@@Z 0x141057290 ; fx19 chain
// MS2-PIN: ??$_Destroy1@V?$vector@E@efd@@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@E@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$vector@E@efd@@@efd@@PEAV?$vector@E@3@U?$integral_constant@_N$0A@@1@@Z 0x1410572c0 ; fx19 chain
// MS2-PIN: ??$_Destroy1@V?$vector@PEAVNiMesh@@@efd@@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@PEAV?$vector@PEAVNiMesh@@@3@U?$integral_constant@_N$0A@@1@@Z 0x1410572f0 ; fx19 chain
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@YAXPEAPEAVNiAVObject@@0AEAV?$CustomAllocator@PEAVNiAVObject@@@efd@@U?$integral_constant@_N$0A@@0@@Z 0x1410573b0 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@YAXPEAPEAVNiMesh@@0AEAV?$CustomAllocator@PEAVNiMesh@@@efd@@U?$integral_constant@_N$0A@@0@@Z 0x141057410 ; fx19 chain
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@YAXPEAUUnk_AtlasResult@@0AEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@U?$integral_constant@_N$0A@@0@@Z 0x141057650 ; fx19 chain
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@@std@@YAXPEAV?$set@EU?$less@E@std@@@efd@@0AEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@U?$integral_constant@_N$0A@@0@@Z 0x1410574d0 ; fx19 chain
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@@std@@YAXPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@0AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@U?$integral_constant@_N$0A@@0@@Z 0x141057530 ; fx19 chain
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@V?$vector@E@efd@@@efd@@@std@@YAXPEAV?$vector@E@efd@@0AEAV?$CustomAllocator@V?$vector@E@efd@@@2@U?$integral_constant@_N$0A@@0@@Z 0x141057590 ; fx19 chain
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@@std@@YAXPEAV?$vector@PEAVNiMesh@@@efd@@0AEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@U?$integral_constant@_N$0A@@0@@Z 0x1410575f0 ; fx19 chain
// MS2-PIN: ??$_Destroy_range1@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@YAXPEAUUnk_StreamElementDesc@@0AEAV?$allocator@UUnk_StreamElementDesc@@@0@U?$integral_constant@_N$0A@@0@@Z 0x1410576b0 ; unique
// MS2-PIN: ??$_Destroy_range@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@YAXPEAPEAVNiMesh@@0AEAV?$CustomAllocator@PEAVNiMesh@@@efd@@@Z 0x1410577b0 ; fx19 chain
// MS2-PIN: ??$_Destroy_range@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@@std@@YAXPEAV?$set@EU?$less@E@std@@@efd@@0AEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@Z 0x141057850 ; fx19 chain
// MS2-PIN: ??$_Destroy_range@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@@std@@YAXPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@0AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@Z 0x1410578a0 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@AEAPEAVNiAVObject@@@?$_Uninitialized_backout_al@PEAPEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@QEAAXAEAPEAVNiAVObject@@@Z 0x141057d90 ; prop
// MS2-PIN: ??$_Emplace_back@AEAPEAVNiMesh@@@?$_Uninitialized_backout_al@PEAPEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEAAXAEAPEAVNiMesh@@@Z 0x141057a90 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@AEAUUnk_AtlasResult@@@?$_Uninitialized_backout_al@PEAUUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@QEAAXAEAUUnk_AtlasResult@@@Z 0x141057d30 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@AEAUUnk_StreamElementDesc@@@?$_Uninitialized_backout_al@PEAUUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@QEAAXAEAUUnk_StreamElementDesc@@@Z 0x141057af0 ; prop
// MS2-PIN: ??$_Emplace_back@AEAV?$map@EEU?$less@E@std@@@efd@@@?$_Uninitialized_backout_al@PEAV?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@QEAAXAEAV?$map@EEU?$less@E@std@@@efd@@@Z 0x141057b50 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@AEAV?$set@EU?$less@E@std@@@efd@@@?$_Uninitialized_backout_al@PEAV?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@QEAAXAEAV?$set@EU?$less@E@std@@@efd@@@Z 0x141057bb0 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@AEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@?$_Uninitialized_backout_al@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAAXAEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@Z 0x141057c10 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@AEAV?$vector@E@efd@@@?$_Uninitialized_backout_al@PEAV?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@QEAAXAEAV?$vector@E@efd@@@Z 0x141057c70 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@AEAV?$vector@PEAVNiMesh@@@efd@@@?$_Uninitialized_backout_al@PEAV?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAAXAEAV?$vector@PEAVNiMesh@@@efd@@@Z 0x141057cd0 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@PEAVNiMesh@@@?$_Uninitialized_backout_al@PEAPEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEAAX$$QEAPEAVNiMesh@@@Z 0x141057df0 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@UUnk_AtlasResult@@@?$_Uninitialized_backout_al@PEAUUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@QEAAX$$QEAUUnk_AtlasResult@@@Z 0x141058090 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@UUnk_StreamElementDesc@@@?$_Uninitialized_backout_al@PEAUUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@QEAAX$$QEAUUnk_StreamElementDesc@@@Z 0x141057e50 ; prop
// MS2-PIN: ??$_Emplace_back@V?$map@EEU?$less@E@std@@@efd@@@?$_Uninitialized_backout_al@PEAV?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@QEAAX$$QEAV?$map@EEU?$less@E@std@@@efd@@@Z 0x141057eb0 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@V?$set@EU?$less@E@std@@@efd@@@?$_Uninitialized_backout_al@PEAV?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@QEAAX$$QEAV?$set@EU?$less@E@std@@@efd@@@Z 0x141057f10 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@?$_Uninitialized_backout_al@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAAX$$QEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@Z 0x141057f70 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@V?$vector@E@efd@@@?$_Uninitialized_backout_al@PEAV?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@QEAAX$$QEAV?$vector@E@efd@@@Z 0x141057fd0 ; fx19 chain
// MS2-PIN: ??$_Emplace_back@V?$vector@PEAVNiMesh@@@efd@@@?$_Uninitialized_backout_al@PEAV?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAAX$$QEAV?$vector@PEAVNiMesh@@@efd@@@Z 0x141058030 ; fx19 chain
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBQEAVNiMesh@@@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@AEAAXAEBQEAVNiMesh@@@Z 0x1410581b0 ; fx19 chain
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBUUnk_AtlasResult@@@?$vector@UUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@AEAAXAEBUUnk_AtlasResult@@@Z 0x141058330 ; fx19 chain
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$vector@PEAVNiMesh@@@efd@@@?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@AEAAXAEBV?$vector@PEAVNiMesh@@@efd@@@Z 0x141058270 ; fx19 chain
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@PEAVNiAVObject@@@?$vector@PEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@AEAAX$$QEAPEAVNiAVObject@@@Z 0x1410580f0 ; prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@UUnk_StreamElementDesc@@@?$vector@UUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@AEAAX$$QEAUUnk_StreamElementDesc@@@Z 0x1410583f0 ; prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@V?$map@EEU?$less@E@std@@@efd@@@?$vector@V?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@AEAAX$$QEAV?$map@EEU?$less@E@std@@@efd@@@Z 0x1410584b0 ; prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@V?$set@EU?$less@E@std@@@efd@@@?$vector@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@AEAAX$$QEAV?$set@EU?$less@E@std@@@efd@@@Z 0x141058570 ; fx19 chain
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@AEAAX$$QEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@Z 0x141058630 ; fx19 chain
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@V?$vector@E@efd@@@?$vector@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@AEAAX$$QEAV?$vector@E@efd@@@Z 0x1410586f0 ; fx19 chain
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@V?$vector@PEAVNiMesh@@@efd@@@?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@AEAAX$$QEAV?$vector@PEAVNiMesh@@@efd@@@Z 0x1410587b0 ; prop
// MS2-PIN: ??$_Emplace_reallocate@AEBQEAVNiMesh@@@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEAAPEAPEAVNiMesh@@QEAPEAV2@AEBQEAV2@@Z 0x141058ab0 ; fx19 chain
// MS2-PIN: ??$_Emplace_reallocate@AEBUUnk_AtlasResult@@@?$vector@UUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@QEAAPEAUUnk_AtlasResult@@QEAU2@AEBU2@@Z 0x141058f50 ; fx19 chain
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$vector@PEAVNiMesh@@@efd@@@?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAAPEAV?$vector@PEAVNiMesh@@@efd@@QEAV23@AEBV23@@Z 0x141058cf0 ; fx19 chain
// MS2-PIN: ??$_Emplace_reallocate@PEAVNiAVObject@@@?$vector@PEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@QEAAPEAPEAVNiAVObject@@QEAPEAV2@$$QEAPEAV2@@Z 0x141058870 ; prop
// MS2-PIN: ??$_Emplace_reallocate@V?$map@EEU?$less@E@std@@@efd@@@?$vector@V?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@QEAAPEAV?$map@EEU?$less@E@std@@@efd@@QEAV23@$$QEAV23@@Z 0x141059400 ; prop
// MS2-PIN: ??$_Emplace_reallocate@V?$set@EU?$less@E@std@@@efd@@@?$vector@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@QEAAPEAV?$set@EU?$less@E@std@@@efd@@QEAV23@$$QEAV23@@Z 0x141059650 ; fx19 chain
// MS2-PIN: ??$_Emplace_reallocate@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAV23@$$QEAV23@@Z 0x1410598a0 ; fx19 chain
// MS2-PIN: ??$_Emplace_reallocate@V?$vector@E@efd@@@?$vector@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@QEAAPEAV?$vector@E@efd@@QEAV23@$$QEAV23@@Z 0x141059af0 ; fx19 chain
// MS2-PIN: ??$_Emplace_reallocate@V?$vector@PEAVNiMesh@@@efd@@@?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAAPEAV?$vector@PEAVNiMesh@@@efd@@QEAV23@$$QEAV23@@Z 0x141059d50 ; prop
// MS2-PIN: ??$_Freenode0@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@@?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@PEAU01@@Z 0x14105a1c0 ; prop
// MS2-PIN: ??$_Freenode0@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@@?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@PEAU01@@Z 0x14105a270 ; prop
// MS2-PIN: ??$_Freenode0@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@@?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@PEAU01@@Z 0x14105a320 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped@PEAVNiAVObject@@@std@@YAPEAPEAVNiAVObject@@QEAPEAV1@@Z 0x14105a480 ; prop
// MS2-PIN: ??$_Get_unwrapped@UUnk_AtlasResult@@@std@@YAPEAUUnk_AtlasResult@@QEAU1@@Z 0x14105a550 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped@V?$map@EEU?$less@E@std@@@efd@@@std@@YAPEAV?$map@EEU?$less@E@std@@@efd@@QEAV12@@Z 0x14105a500 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped@V?$set@EU?$less@E@std@@@efd@@@std@@YAPEAV?$set@EU?$less@E@std@@@efd@@QEAV12@@Z 0x14105a510 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@YAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAV12@@Z 0x14105a520 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped@V?$vector@E@efd@@@std@@YAPEAV?$vector@E@efd@@QEAV12@@Z 0x14105a530 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped@V?$vector@PEAVNiMesh@@@efd@@@std@@YAPEAV?$vector@PEAVNiMesh@@@efd@@QEAV12@@Z 0x14105a540 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped_n@PEAVNiMesh@@_J$0A@@std@@YAPEAPEAVNiMesh@@QEAPEAV1@_J@Z 0x14105a570 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped_n@UUnk_AtlasResult@@_J$0A@@std@@YAPEAUUnk_AtlasResult@@QEAU1@_J@Z 0x14105a600 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped_n@V?$map@EEU?$less@E@std@@@efd@@_J$0A@@std@@YAPEAV?$map@EEU?$less@E@std@@@efd@@QEAV12@_J@Z 0x14105a5b0 ; prop
// MS2-PIN: ??$_Get_unwrapped_n@V?$set@EU?$less@E@std@@@efd@@_J$0A@@std@@YAPEAV?$set@EU?$less@E@std@@@efd@@QEAV12@_J@Z 0x14105a5c0 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped_n@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@_J$0A@@std@@YAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAV12@_J@Z 0x14105a5d0 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped_n@V?$vector@E@efd@@_J$0A@@std@@YAPEAV?$vector@E@efd@@QEAV12@_J@Z 0x14105a5e0 ; fx19 chain
// MS2-PIN: ??$_Get_unwrapped_n@V?$vector@PEAVNiMesh@@@efd@@_J$0A@@std@@YAPEAV?$vector@PEAVNiMesh@@@efd@@QEAV12@_J@Z 0x14105a5f0 ; fx19 chain
// MS2-PIN: ??$_Idl_distance1@PEAPEAVNiMesh@@PEAPEAV1@@std@@YA_JAEBQEAPEAVNiMesh@@0Urandom_access_iterator_tag@0@@Z 0x14105a790 ; fx19 chain
// MS2-PIN: ??$_Idl_distance1@PEAUUnk_AtlasResult@@PEAU1@@std@@YA_JAEBQEAUUnk_AtlasResult@@0Urandom_access_iterator_tag@0@@Z 0x14105a8e0 ; fx19 chain
// MS2-PIN: ??$_Idl_distance1@PEAV?$map@EEU?$less@E@std@@@efd@@PEAV12@@std@@YA_JAEBQEAV?$map@EEU?$less@E@std@@@efd@@0Urandom_access_iterator_tag@0@@Z 0x14105a7f0 ; fx19 chain
// MS2-PIN: ??$_Idl_distance1@PEAV?$set@EU?$less@E@std@@@efd@@PEAV12@@std@@YA_JAEBQEAV?$set@EU?$less@E@std@@@efd@@0Urandom_access_iterator_tag@0@@Z 0x14105a820 ; fx19 chain
// MS2-PIN: ??$_Idl_distance1@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@@std@@YA_JAEBQEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@0Urandom_access_iterator_tag@0@@Z 0x14105a850 ; fx19 chain
// MS2-PIN: ??$_Idl_distance1@PEAV?$vector@E@efd@@PEAV12@@std@@YA_JAEBQEAV?$vector@E@efd@@0Urandom_access_iterator_tag@0@@Z 0x14105a880 ; fx19 chain
// MS2-PIN: ??$_Idl_distance1@PEAV?$vector@PEAVNiMesh@@@efd@@PEAV12@@std@@YA_JAEBQEAV?$vector@PEAVNiMesh@@@efd@@0Urandom_access_iterator_tag@0@@Z 0x14105a8b0 ; fx19 chain
// MS2-PIN: ??$_Idl_distance@PEAPEAVNiAVObject@@PEAPEAV1@@std@@YA_JAEBQEAPEAVNiAVObject@@0@Z 0x14105a940 ; prop
// MS2-PIN: ??$_Idl_distance@PEAPEAVNiMesh@@PEAPEAV1@@std@@YA_JAEBQEAPEAVNiMesh@@0@Z 0x14105a970 ; fx19 chain
// MS2-PIN: ??$_Idl_distance@PEAUUnk_AtlasResult@@PEAU1@@std@@YA_JAEBQEAUUnk_AtlasResult@@0@Z 0x14105aac0 ; fx19 chain
// MS2-PIN: ??$_Idl_distance@PEAV?$map@EEU?$less@E@std@@@efd@@PEAV12@@std@@YA_JAEBQEAV?$map@EEU?$less@E@std@@@efd@@0@Z 0x14105a9d0 ; fx19 chain
// MS2-PIN: ??$_Idl_distance@PEAV?$set@EU?$less@E@std@@@efd@@PEAV12@@std@@YA_JAEBQEAV?$set@EU?$less@E@std@@@efd@@0@Z 0x14105aa00 ; fx19 chain
// MS2-PIN: ??$_Idl_distance@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@@std@@YA_JAEBQEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@0@Z 0x14105aa30 ; fx19 chain
// MS2-PIN: ??$_Idl_distance@PEAV?$vector@E@efd@@PEAV12@@std@@YA_JAEBQEAV?$vector@E@efd@@0@Z 0x14105aa60 ; fx19 chain
// MS2-PIN: ??$_Idl_distance@PEAV?$vector@PEAVNiMesh@@@efd@@PEAV12@@std@@YA_JAEBQEAV?$vector@PEAVNiMesh@@@efd@@0@Z 0x14105aa90 ; fx19 chain
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBEE@std@@PEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@1@AEAU?$pair@$$CBEE@1@1@Z 0x14105ab30 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@1@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@1@@Z 0x14105df60 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@1@PEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@1@@Z 0x14105e370 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@1@PEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@1@@Z 0x14105e780 ; fx19 chain
// MS2-PIN: ??$_Insertion_sort_unchecked@PEAPEAVNiAVObject@@P6A_NPEAV1@0@Z@std@@YAPEAPEAVNiAVObject@@PEAPEAV1@QEAPEAV1@P6A_NPEAV1@2@Z@Z 0x14105f7c0 ; unique
// MS2-PIN: ??$_Lbound@E@?$_Tree@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@1@AEBE@Z 0x14105f940 ; prop
// MS2-PIN: ??$_Lbound@PEAVNiAVObject@@@?$_Tree@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@1@AEBQEAVNiAVObject@@@Z 0x14105f9e0 ; prop
// MS2-PIN: ??$_Lbound@PEAVNiMesh@@@?$_Tree@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@1@AEBQEAVNiMesh@@@Z 0x14105fa80 ; prop
// MS2-PIN: ??$_Make_heap_unchecked@PEAPEAVNiAVObject@@P6A_NPEAV1@0@Z@std@@YAXPEAPEAVNiAVObject@@0P6A_NPEAV1@1@Z@Z 0x14105fbc0 ; unique
// MS2-PIN: ??$_Pop_heap_hole_by_index@PEAPEAVNiAVObject@@PEAV1@P6A_NPEAV1@0@Z@std@@YAXPEAPEAVNiAVObject@@_J1$$QEAPEAV1@P6A_NPEAV1@3@Z@Z 0x141060130 ; unique
// MS2-PIN: ??$_Pop_heap_hole_unchecked@PEAPEAVNiAVObject@@PEAV1@P6A_NPEAV1@0@Z@std@@YAXPEAPEAVNiAVObject@@00$$QEAPEAV1@P6A_NPEAV1@2@Z@Z 0x141060280 ; unique
// MS2-PIN: ??$_Pop_heap_unchecked@PEAPEAVNiAVObject@@P6A_NPEAV1@0@Z@std@@YAXPEAPEAVNiAVObject@@0P6A_NPEAV1@1@Z@Z 0x1410602f0 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@PEAVNiMesh@@PEAV1@@std@@YA?AU_Really_trivial_ptr_iterator_tag@0@AEBQEAPEAVNiMesh@@0@Z 0x141060390 ; fx19 chain
// MS2-PIN: ??$_Ptr_copy_cat@UUnk_AtlasResult@@U1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAUUnk_AtlasResult@@0@Z 0x141060500 ; fx19 chain
// MS2-PIN: ??$_Ptr_copy_cat@V?$set@EU?$less@E@std@@@efd@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$set@EU?$less@E@std@@@efd@@0@Z 0x141060440 ; fx19 chain
// MS2-PIN: ??$_Ptr_copy_cat@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@0@Z 0x141060470 ; fx19 chain
// MS2-PIN: ??$_Ptr_copy_cat@V?$vector@E@efd@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$vector@E@efd@@0@Z 0x1410604a0 ; fx19 chain
// MS2-PIN: ??$_Ptr_copy_cat@V?$vector@PEAVNiMesh@@@efd@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$vector@PEAVNiMesh@@@efd@@0@Z 0x1410604d0 ; fx19 chain
// MS2-PIN: ??$_Ptr_move_cat@PEAVNiAVObject@@PEAV1@@std@@YA?AU_Really_trivial_ptr_iterator_tag@0@AEBQEAPEAVNiAVObject@@0@Z 0x141060550 ; fx19 chain
// MS2-PIN: ??$_Ptr_move_cat@UUnk_AtlasResult@@U1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAUUnk_AtlasResult@@0@Z 0x141060690 ; fx19 chain
// MS2-PIN: ??$_Ptr_move_cat@V?$map@EEU?$less@E@std@@@efd@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$map@EEU?$less@E@std@@@efd@@0@Z 0x1410605a0 ; fx19 chain
// MS2-PIN: ??$_Ptr_move_cat@V?$set@EU?$less@E@std@@@efd@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$set@EU?$less@E@std@@@efd@@0@Z 0x1410605d0 ; fx19 chain
// MS2-PIN: ??$_Ptr_move_cat@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@0@Z 0x141060600 ; fx19 chain
// MS2-PIN: ??$_Ptr_move_cat@V?$vector@E@efd@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$vector@E@efd@@0@Z 0x141060630 ; fx19 chain
// MS2-PIN: ??$_Ptr_move_cat@V?$vector@PEAVNiMesh@@@efd@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$vector@PEAVNiMesh@@@efd@@0@Z 0x141060660 ; fx19 chain
// MS2-PIN: ??$_Push_heap_by_index@PEAPEAVNiAVObject@@PEAV1@P6A_NPEAV1@0@Z@std@@YAXPEAPEAVNiAVObject@@_J1$$QEAPEAV1@P6A_NPEAV1@3@Z@Z 0x1410606c0 ; unique
// MS2-PIN: ??$_Seek_wrapped@PEAVNiAVObject@@@std@@YAXAEAPEAPEAVNiAVObject@@QEAPEAV1@@Z 0x141060780 ; prop
// MS2-PIN: ??$_Seek_wrapped@UUnk_AtlasResult@@@std@@YAXAEAPEAUUnk_AtlasResult@@QEAU1@@Z 0x1410608b0 ; fx19 chain
// MS2-PIN: ??$_Seek_wrapped@V?$map@EEU?$less@E@std@@@efd@@@std@@YAXAEAPEAV?$map@EEU?$less@E@std@@@efd@@QEAV12@@Z 0x141060810 ; prop
// MS2-PIN: ??$_Seek_wrapped@V?$set@EU?$less@E@std@@@efd@@@std@@YAXAEAPEAV?$set@EU?$less@E@std@@@efd@@QEAV12@@Z 0x141060830 ; fx19 chain
// MS2-PIN: ??$_Seek_wrapped@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@YAXAEAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAV12@@Z 0x141060850 ; fx19 chain
// MS2-PIN: ??$_Seek_wrapped@V?$vector@E@efd@@@std@@YAXAEAPEAV?$vector@E@efd@@QEAV12@@Z 0x141060870 ; fx19 chain
// MS2-PIN: ??$_Seek_wrapped@V?$vector@PEAVNiMesh@@@efd@@@std@@YAXAEAPEAV?$vector@PEAVNiMesh@@@efd@@QEAV12@@Z 0x141060890 ; fx19 chain
// MS2-PIN: ??$_Unfancy@V?$set@EU?$less@E@std@@@efd@@@std@@YAPEAV?$set@EU?$less@E@std@@@efd@@PEAV12@@Z 0x141060de0 ; fx19 chain
// MS2-PIN: ??$_Unfancy@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@YAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@@Z 0x141060df0 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy@PEAPEAVNiAVObject@@PEAPEAV1@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@YAPEAPEAVNiAVObject@@QEAPEAV1@0PEAPEAV1@AEAV?$CustomAllocator@PEAVNiAVObject@@@efd@@@Z 0x141061a90 ; prop
// MS2-PIN: ??$_Uninitialized_copy@PEAPEAVNiMesh@@PEAPEAV1@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@YAPEAPEAVNiMesh@@QEAPEAV1@0PEAPEAV1@AEAV?$CustomAllocator@PEAVNiMesh@@@efd@@@Z 0x141060f00 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy@PEAUUnk_AtlasResult@@PEAU1@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@YAPEAUUnk_AtlasResult@@QEAU1@0PEAU1@AEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@@Z 0x1410614b0 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy@PEAUUnk_StreamElementDesc@@PEAU1@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@YAPEAUUnk_StreamElementDesc@@QEAU1@0PEAU1@AEAV?$allocator@UUnk_StreamElementDesc@@@0@@Z 0x141060fd0 ; prop
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$set@EU?$less@E@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@YAPEAV?$set@EU?$less@E@std@@@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@Z 0x141061170 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@YAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@Z 0x141061240 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$vector@E@efd@@PEAV12@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@YAPEAV?$vector@E@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$vector@E@efd@@@2@@Z 0x141061310 ; prop
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$vector@PEAVNiMesh@@@efd@@PEAV12@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@YAPEAV?$vector@PEAVNiMesh@@@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@Z 0x1410613e0 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAPEAVNiMesh@@PEAPEAV1@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@YAPEAPEAVNiMesh@@PEAPEAV1@QEAPEAV1@1AEAV?$CustomAllocator@PEAVNiMesh@@@efd@@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141061610 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAUUnk_AtlasResult@@PEAU1@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@YAPEAUUnk_AtlasResult@@PEAU1@QEAU1@1AEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141061a00 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAUUnk_StreamElementDesc@@PEAU1@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@YAPEAUUnk_StreamElementDesc@@PEAU1@QEAU1@1AEAV?$allocator@UUnk_StreamElementDesc@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x1410616a0 ; prop
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAV?$map@EEU?$less@E@std@@@efd@@PEAV12@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@YAPEAV?$map@EEU?$less@E@std@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141061730 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAV?$set@EU?$less@E@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@YAPEAV?$set@EU?$less@E@std@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x1410617c0 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@YAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141061850 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAV?$vector@E@efd@@PEAV12@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@YAPEAV?$vector@E@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$vector@E@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x1410618e0 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAV?$vector@PEAVNiMesh@@@efd@@PEAV12@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@YAPEAV?$vector@PEAVNiMesh@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141061970 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move@PEAPEAVNiMesh@@PEAPEAV1@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@YAPEAPEAVNiMesh@@QEAPEAV1@0PEAPEAV1@AEAV?$CustomAllocator@PEAVNiMesh@@@efd@@@Z 0x141061b60 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move@PEAUUnk_AtlasResult@@PEAU1@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@YAPEAUUnk_AtlasResult@@QEAU1@0PEAU1@AEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@@Z 0x141062110 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move@PEAUUnk_StreamElementDesc@@PEAU1@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@YAPEAUUnk_StreamElementDesc@@QEAU1@0PEAU1@AEAV?$allocator@UUnk_StreamElementDesc@@@0@@Z 0x141061c30 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAV?$map@EEU?$less@E@std@@@efd@@PEAV12@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@YAPEAV?$map@EEU?$less@E@std@@@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@Z 0x141061d00 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move@PEAV?$set@EU?$less@E@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@YAPEAV?$set@EU?$less@E@std@@@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@Z 0x141061dd0 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@YAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@Z 0x141061ea0 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move@PEAV?$vector@E@efd@@PEAV12@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@YAPEAV?$vector@E@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$vector@E@efd@@@2@@Z 0x141061f70 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move@PEAV?$vector@PEAVNiMesh@@@efd@@PEAV12@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@YAPEAV?$vector@PEAVNiMesh@@@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@Z 0x141062040 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAPEAVNiMesh@@PEAPEAV1@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@YAPEAPEAVNiMesh@@PEAPEAV1@QEAPEAV1@1AEAV?$CustomAllocator@PEAVNiMesh@@@efd@@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141062270 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAUUnk_AtlasResult@@PEAU1@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@YAPEAUUnk_AtlasResult@@PEAU1@QEAU1@1AEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141062660 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAUUnk_StreamElementDesc@@PEAU1@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@YAPEAUUnk_StreamElementDesc@@PEAU1@QEAU1@1AEAV?$allocator@UUnk_StreamElementDesc@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141062300 ; prop
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAV?$map@EEU?$less@E@std@@@efd@@PEAV12@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@YAPEAV?$map@EEU?$less@E@std@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141062390 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAV?$set@EU?$less@E@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@YAPEAV?$set@EU?$less@E@std@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141062420 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@YAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x1410624b0 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAV?$vector@E@efd@@PEAV12@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@YAPEAV?$vector@E@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$vector@E@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141062540 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAV?$vector@PEAVNiMesh@@@efd@@PEAV12@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@YAPEAV?$vector@PEAVNiMesh@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x1410625d0 ; fx19 chain
// MS2-PIN: ??$_Uninitialized_value_construct_n@PEAE_KV?$CustomAllocator@E@efd@@@std@@YAPEAEPEAE_KAEAV?$CustomAllocator@E@efd@@@Z 0x141062730 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@@std@@YAPEBV?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@0@AEBV10@@Z 0x1410627a0 ; fx19 chain
// MS2-PIN: ??$addressof@$$CBV?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@std@@@std@@YAPEBV?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@0@AEBV10@@Z 0x1410627b0 ; fx19 chain
// MS2-PIN: ??$addressof@$$CBV?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@YAPEBV?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@0@AEBV10@@Z 0x1410627c0 ; fx19 chain
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@0@AEAPEAU10@@Z 0x141062800 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@0@AEAPEAU10@@Z 0x141062810 ; prop
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@0@AEAPEAU10@@Z 0x141062820 ; prop
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@0@AEAPEAU10@@Z 0x141062830 ; fx19 chain
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@@std@@@0@AEAV10@@Z 0x141062900 ; fx19 chain
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@0@AEAV10@@Z 0x141062910 ; fx19 chain
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@0@AEAV10@@Z 0x141062920 ; fx19 chain
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@0@AEAV10@@Z 0x141062930 ; fx19 chain
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@1@AEAPEAU41@@Z 0x141062ac0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@1@AEAPEAU41@@Z 0x141062b40 ; fx19 chain
// MS2-PIN: ??$construct@PEAVNiAVObject@@AEAPEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVNiAVObject@@@efd@@PEAPEAVNiAVObject@@AEAPEAV4@@Z 0x141062c80 ; prop
// MS2-PIN: ??$construct@PEAVNiAVObject@@PEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVNiAVObject@@@efd@@PEAPEAVNiAVObject@@$$QEAPEAV4@@Z 0x141062c40 ; prop
// MS2-PIN: ??$construct@PEAVNiMesh@@AEAPEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVNiMesh@@@efd@@PEAPEAVNiMesh@@AEAPEAV4@@Z 0x141062cc0 ; prop
// MS2-PIN: ??$construct@PEAVNiMesh@@AEBQEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVNiMesh@@@efd@@PEAPEAVNiMesh@@AEBQEAV4@@Z 0x141062d00 ; fx19 chain
// MS2-PIN: ??$construct@PEAVNiMesh@@PEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVNiMesh@@@efd@@PEAPEAVNiMesh@@$$QEAPEAV4@@Z 0x141062d40 ; fx19 chain
// MS2-PIN: ??$construct@U?$pair@$$CBEE@std@@U?$pair@EE@2@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@PEAU?$pair@$$CBEE@1@$$QEAU?$pair@EE@1@@Z 0x141062e40 ; unique
// MS2-PIN: ??$construct@UUnk_AtlasResult@@AEAU1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@SAXAEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@PEAUUnk_AtlasResult@@AEAU4@@Z 0x1410633a0 ; fx19 chain
// MS2-PIN: ??$construct@UUnk_AtlasResult@@AEBU1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@SAXAEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@PEAUUnk_AtlasResult@@AEBU4@@Z 0x1410633e0 ; fx19 chain
// MS2-PIN: ??$construct@UUnk_AtlasResult@@U1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@SAXAEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@PEAUUnk_AtlasResult@@$$QEAU4@@Z 0x141063420 ; fx19 chain
// MS2-PIN: ??$construct@V?$map@EEU?$less@E@std@@@efd@@AEAV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@PEAV?$map@EEU?$less@E@std@@@3@AEAV43@@Z 0x1410630e0 ; fx19 chain
// MS2-PIN: ??$construct@V?$map@EEU?$less@E@std@@@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@PEAV?$map@EEU?$less@E@std@@@3@$$QEAV43@@Z 0x141063120 ; prop
// MS2-PIN: ??$construct@V?$set@EU?$less@E@std@@@efd@@AEAV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@PEAV?$set@EU?$less@E@std@@@3@AEAV43@@Z 0x141063160 ; fx19 chain
// MS2-PIN: ??$construct@V?$set@EU?$less@E@std@@@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@PEAV?$set@EU?$less@E@std@@@3@$$QEAV43@@Z 0x1410631a0 ; fx19 chain
// MS2-PIN: ??$construct@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@AEAV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@3@AEAV43@@Z 0x1410631e0 ; fx19 chain
// MS2-PIN: ??$construct@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@3@$$QEAV43@@Z 0x141063220 ; fx19 chain
// MS2-PIN: ??$construct@V?$vector@E@efd@@AEAV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@E@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$vector@E@efd@@@efd@@PEAV?$vector@E@3@AEAV43@@Z 0x141063260 ; fx19 chain
// MS2-PIN: ??$construct@V?$vector@E@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@E@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$vector@E@efd@@@efd@@PEAV?$vector@E@3@$$QEAV43@@Z 0x1410632a0 ; fx19 chain
// MS2-PIN: ??$construct@V?$vector@PEAVNiMesh@@@efd@@AEAV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@PEAV?$vector@PEAVNiMesh@@@3@AEAV43@@Z 0x1410632e0 ; fx19 chain
// MS2-PIN: ??$construct@V?$vector@PEAVNiMesh@@@efd@@AEBV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@PEAV?$vector@PEAVNiMesh@@@3@AEBV43@@Z 0x141063320 ; fx19 chain
// MS2-PIN: ??$construct@V?$vector@PEAVNiMesh@@@efd@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@PEAV?$vector@PEAVNiMesh@@@3@$$QEAV43@@Z 0x141063360 ; prop
// MS2-PIN: ??$destroy@PEAVNiMesh@@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVNiMesh@@@efd@@PEAPEAVNiMesh@@@Z 0x141063720 ; fx19 chain
// MS2-PIN: ??$destroy@UUnk_AtlasResult@@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@SAXAEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@PEAUUnk_AtlasResult@@@Z 0x141063950 ; fx19 chain
// MS2-PIN: ??$destroy@V?$set@EU?$less@E@std@@@efd@@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@PEAV?$set@EU?$less@E@std@@@3@@Z 0x141063890 ; fx19 chain
// MS2-PIN: ??$destroy@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@3@@Z 0x1410638c0 ; fx19 chain
// MS2-PIN: ??$emplace@U?$pair@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@?$_Tree@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@1@@Z 0x1410639f0 ; fx19 chain
// MS2-PIN: ??$emplace@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@1@@Z 0x141063ad0 ; prop
// MS2-PIN: ??$emplace@U?$pair@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@?$_Tree@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@1@@Z 0x141063b40 ; prop
// MS2-PIN: ??$emplace_back@AEBV?$vector@PEAVNiMesh@@@efd@@@?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAAXAEBV?$vector@PEAVNiMesh@@@efd@@@Z 0x141063c90 ; fx19 chain
// MS2-PIN: ??$emplace_back@V?$set@EU?$less@E@std@@@efd@@@?$vector@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@QEAAX$$QEAV?$set@EU?$less@E@std@@@efd@@@Z 0x141063e50 ; fx19 chain
// MS2-PIN: ??$emplace_back@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAAX$$QEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@Z 0x141063ec0 ; fx19 chain
// MS2-PIN: ??$emplace_back@V?$vector@E@efd@@@?$vector@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@QEAAX$$QEAV?$vector@E@efd@@@Z 0x141063f30 ; fx19 chain
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@0@AEAPEAU10@@Z 0x141064180 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@0@AEAPEAU10@@Z 0x1410641a0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@0@AEAPEAU10@@Z 0x1410641c0 ; fx19 chain
// MS2-PIN: ??$forward@AEAPEAVNiAVObject@@@std@@YAAEAPEAVNiAVObject@@AEAPEAV1@@Z 0x1410641e0 ; fx19 chain
// MS2-PIN: ??$forward@AEAUUnk_AtlasResult@@@std@@YAAEAUUnk_AtlasResult@@AEAU1@@Z 0x141064330 ; fx19 chain
// MS2-PIN: ??$forward@AEAV?$map@EEU?$less@E@std@@@efd@@@std@@YAAEAV?$map@EEU?$less@E@std@@@efd@@AEAV12@@Z 0x1410642e0 ; fx19 chain
// MS2-PIN: ??$forward@AEAV?$set@EU?$less@E@std@@@efd@@@std@@YAAEAV?$set@EU?$less@E@std@@@efd@@AEAV12@@Z 0x1410642f0 ; fx19 chain
// MS2-PIN: ??$forward@AEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@YAAEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@AEAV12@@Z 0x141064300 ; fx19 chain
// MS2-PIN: ??$forward@AEAV?$vector@E@efd@@@std@@YAAEAV?$vector@E@efd@@AEAV12@@Z 0x141064310 ; fx19 chain
// MS2-PIN: ??$forward@AEAV?$vector@PEAVNiMesh@@@efd@@@std@@YAAEAV?$vector@PEAVNiMesh@@@efd@@AEAV12@@Z 0x141064320 ; fx19 chain
// MS2-PIN: ??$forward@AEBUUnk_AtlasResult@@@std@@YAAEBUUnk_AtlasResult@@AEBU1@@Z 0x1410643f0 ; fx19 chain
// MS2-PIN: ??$forward@AEBV?$vector@PEAVNiMesh@@@efd@@@std@@YAAEBV?$vector@PEAVNiMesh@@@efd@@AEBV12@@Z 0x1410643e0 ; fx19 chain
// MS2-PIN: ??$forward@PEAVNiAVObject@@@std@@YA$$QEAPEAVNiAVObject@@AEAPEAV1@@Z 0x141064370 ; prop
// MS2-PIN: ??$forward@UUnk_AtlasResult@@@std@@YA$$QEAUUnk_AtlasResult@@AEAU1@@Z 0x1410645e0 ; fx19 chain
// MS2-PIN: ??$forward@V?$set@EU?$less@E@std@@@efd@@@std@@YA$$QEAV?$set@EU?$less@E@std@@@efd@@AEAV12@@Z 0x141064580 ; fx19 chain
// MS2-PIN: ??$forward@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@YA$$QEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@AEAV12@@Z 0x141064590 ; fx19 chain
// MS2-PIN: ??$forward@V?$vector@E@efd@@@std@@YA$$QEAV?$vector@E@efd@@AEAV12@@Z 0x1410645c0 ; fx19 chain
// MS2-PIN: ??$get@$0A@AEBE@std@@YAAEBE$$QEAV?$tuple@AEBE@0@@Z 0x141064670 ; unique
// MS2-PIN: ??$insert@U?$pair@EE@std@@X@?$map@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@EE@1@@Z 0x141064730 ; prop
// MS2-PIN: ??$insert@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@X@?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@1@@Z 0x1410647f0 ; prop
// MS2-PIN: ??$insert@U?$pair@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@X@?$map@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@1@@Z 0x141064830 ; prop
// MS2-PIN: ??$move@AEAPEAVNiAVObject@@@std@@YA$$QEAPEAVNiAVObject@@AEAPEAV1@@Z 0x141064a70 ; fx19 chain
// MS2-PIN: ??$move@AEAUUnk_AtlasResult@@@std@@YA$$QEAUUnk_AtlasResult@@AEAU1@@Z 0x141064b00 ; fx19 chain
// MS2-PIN: ??$move@AEAV?$map@EEU?$less@E@std@@@efd@@@std@@YA$$QEAV?$map@EEU?$less@E@std@@@efd@@AEAV12@@Z 0x141064a90 ; fx19 chain
// MS2-PIN: ??$move@AEAV?$set@EU?$less@E@std@@@efd@@@std@@YA$$QEAV?$set@EU?$less@E@std@@@efd@@AEAV12@@Z 0x141064aa0 ; fx19 chain
// MS2-PIN: ??$move@AEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@YA$$QEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@AEAV12@@Z 0x141064ab0 ; fx19 chain
// MS2-PIN: ??$move@AEAV?$vector@E@efd@@@std@@YA$$QEAV?$vector@E@efd@@AEAV12@@Z 0x141064ae0 ; fx19 chain
// MS2-PIN: ??$move@AEAV?$vector@PEAVNiMesh@@@efd@@@std@@YA$$QEAV?$vector@PEAVNiMesh@@@efd@@AEAV12@@Z 0x141064af0 ; fx19 chain
// MS2-PIN: ??$try_emplace@$$V@?$map@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@_N@1@AEBQEAVNiMesh@@@Z 0x141064c20 ; fx19 chain
// MS2-PIN: ??0?$CAtlArray@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEAA@XZ 0x141064c60 ; unique
// MS2-PIN: ??0?$CAtlArray@PEAVNiBound@@V?$CElementTraits@PEAVNiBound@@@ATL@@@ATL@@QEAA@XZ 0x141064ca0 ; unique
// MS2-PIN: ??0?$CAtlArray@PEAVNiTransform@@V?$CElementTraits@PEAVNiTransform@@@ATL@@@ATL@@QEAA@XZ 0x141064ce0 ; unique
// MS2-PIN: ??0?$CAtlArray@V?$SmartPointer@VNiMesh@@@efd@@V?$CElementTraits@V?$SmartPointer@VNiMesh@@@efd@@@ATL@@@ATL@@QEAA@XZ 0x141064d20 ; prop
// MS2-PIN: ??0?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@PEAX@std@@@efd@@QEAA@XZ 0x141064e80 ; fx19 chain
// MS2-PIN: ??0?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@QEAA@XZ 0x141064ea0 ; prop
// MS2-PIN: ??0?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@QEAA@XZ 0x141064eb0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@QEAA@AEBU?$less@E@1@@Z 0x141065160 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@PEAVNiMesh@@@1@@Z 0x141065190 ; fx19 chain
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAA@AEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@@Z 0x1410651f0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEAA@AEBU?$less@E@1@@Z 0x141065250 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAA@AEBU?$less@PEAVNiAVObject@@@1@@Z 0x141065280 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@QEAA@AEBU?$less@E@1@@Z 0x1410652b0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@PEAVNiMesh@@@1@@Z 0x141065300 ; fx19 chain
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAA@AEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@@Z 0x1410653a0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA@AEBUUnk_TransformLess@@@Z 0x1410653f0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEAA@AEBU?$less@E@1@@Z 0x141065440 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAA@AEBU?$less@PEAVNiAVObject@@@1@@Z 0x141065490 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@QEAA@XZ 0x141065a50 ; prop
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAEV?$CustomAllocator@E@efd@@@std@@QEAA@PEAEAEAV?$CustomAllocator@E@efd@@@Z 0x141065b70 ; unique
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAUUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@QEAA@PEAUUnk_AtlasResult@@AEAV?$CustomAllocator@UUnk_AtlasResult@@@efd@@@Z 0x141065db0 ; fx19 chain
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAUUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@QEAA@PEAUUnk_StreamElementDesc@@AEAV?$allocator@UUnk_StreamElementDesc@@@1@@Z 0x141065c30 ; prop
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAV?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@QEAA@PEAV?$map@EEU?$less@E@std@@@efd@@AEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@3@@Z 0x141065c70 ; fx19 chain
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAV?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@QEAA@PEAV?$set@EU?$less@E@std@@@efd@@AEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@3@@Z 0x141065cb0 ; fx19 chain
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAA@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@3@@Z 0x141065cf0 ; fx19 chain
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAV?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@QEAA@PEAV?$vector@E@efd@@AEAV?$CustomAllocator@V?$vector@E@efd@@@3@@Z 0x141065d30 ; fx19 chain
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAV?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAA@PEAV?$vector@PEAVNiMesh@@@efd@@AEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@3@@Z 0x141065d70 ; fx19 chain
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@@std@@QEAA@XZ 0x141065e50 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@@std@@QEAA@XZ 0x141065eb0 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@@std@@QEAA@XZ 0x141065ee0 ; prop
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@std@@@std@@QEAA@PEAUUnk_StreamElementDesc@@PEBU_Container_base0@1@@Z 0x141065ff0 ; fx19 chain
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@QEAA@PEAV?$vector@PEAVNiMesh@@@efd@@PEBU_Container_base0@1@@Z 0x141066030 ; fx19 chain
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@std@@@std@@QEAA@PEAUUnk_StreamElementDesc@@PEBU_Container_base0@1@@Z 0x1410660b0 ; fx19 chain
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@QEAA@PEAV?$vector@PEAVNiMesh@@@efd@@PEBU_Container_base0@1@@Z 0x1410660f0 ; fx19 chain
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@std@@QEAA@XZ 0x141066230 ; prop
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@std@@QEAA@XZ 0x141066270 ; prop
// MS2-PIN: ??0?$map@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@@std@@QEAA@XZ 0x141066450 ; fx19 chain
// MS2-PIN: ??0?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@efd@@QEAA@XZ 0x141066570 ; unique
// MS2-PIN: ??0?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@@std@@QEAA@XZ 0x141066590 ; prop
// MS2-PIN: ??0?$map@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@@efd@@QEAA@XZ 0x1410665c0 ; unique
// MS2-PIN: ??0?$map@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@@std@@QEAA@XZ 0x1410665e0 ; prop
// MS2-PIN: ??0?$set@EU?$less@E@std@@@efd@@QEAA@AEBV01@@Z 0x141066610 ; prop
// MS2-PIN: ??0?$set@EU?$less@E@std@@@efd@@QEAA@XZ 0x141066640 ; unique
// MS2-PIN: ??0?$set@EU?$less@E@std@@V?$CustomAllocator@E@efd@@@std@@QEAA@AEBV01@@Z 0x141066660 ; prop
// MS2-PIN: ??0?$set@EU?$less@E@std@@V?$CustomAllocator@E@efd@@@std@@QEAA@XZ 0x1410666d0 ; prop
// MS2-PIN: ??0?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAA@AEBV01@@Z 0x141066700 ; prop
// MS2-PIN: ??0?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAA@XZ 0x141066730 ; unique
// MS2-PIN: ??0?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@QEAA@AEBV01@@Z 0x141066750 ; prop
// MS2-PIN: ??0?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@QEAA@XZ 0x1410667c0 ; prop
// MS2-PIN: ??0?$vector@E@efd@@QEAA@AEBV01@@Z 0x141066870 ; prop
// MS2-PIN: ??0?$vector@PEAVNiMesh@@@efd@@QEAA@XZ 0x141066af0 ; unique
// MS2-PIN: ??0?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEAA@AEBV01@@Z 0x141066b10 ; w200 hand
// MS2-PIN: ??0?$vector@UUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@QEAA@XZ 0x141066c20 ; prop
// MS2-PIN: ??0?$vector@V?$set@EU?$less@E@std@@@efd@@@efd@@QEAA@XZ 0x141066ca0 ; unique
// MS2-PIN: ??0?$vector@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@QEAA@XZ 0x141066cc0 ; prop
// MS2-PIN: ??0?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@QEAA@XZ 0x141066cf0 ; unique
// MS2-PIN: ??0?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAA@XZ 0x141066d10 ; prop
// MS2-PIN: ??0MergeInfo@@QEAA@XZ 0x141067020 ; w200 hand
// MS2-PIN: ??0Unk_StreamElementDesc@@QEAA@$$QEAU0@@Z 0x141066f80 ; fx19 chain
// MS2-PIN: ??1?$CAtlArray@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEAA@XZ 0x1410670d0 ; w200 hand
// MS2-PIN: ??1?$CAtlArray@PEAVNiBound@@V?$CElementTraits@PEAVNiBound@@@ATL@@@ATL@@QEAA@XZ 0x141067110 ; w200 hand
// MS2-PIN: ??1?$CAtlArray@PEAVNiTransform@@V?$CElementTraits@PEAVNiTransform@@@ATL@@@ATL@@QEAA@XZ 0x141067150 ; w200 hand
// MS2-PIN: ??1?$CAtlArray@V?$SmartPointer@VNiMesh@@@efd@@V?$CElementTraits@V?$SmartPointer@VNiMesh@@@efd@@@ATL@@@ATL@@QEAA@XZ 0x141067190 ; prop
// MS2-PIN: ??1?$_Compressed_pair@U?$less@PEAVNiMesh@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@XZ 0x141067420 ; fx19 chain
// MS2-PIN: ??1?$_Compressed_pair@UUnk_TransformLess@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@$00@std@@$00@std@@QEAA@XZ 0x141067480 ; prop
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@E@efd@@V?$_Vector_val@U?$_Simple_types@E@std@@@std@@$00@std@@QEAA@XZ 0x1410674a0 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@$00@std@@QEAA@XZ 0x141067520 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141067540 ; unique
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141067560 ; prop
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x141067580 ; prop
// MS2-PIN: ??1?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@$00@std@@QEAA@XZ 0x1410675a0 ; fx19 chain
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141067680 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1410676b0 ; fx19 chain
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141067710 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEAA@XZ 0x141067770 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x1410677a0 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x141067810 ; fx19 chain
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141067890 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1410678d0 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEAA@XZ 0x141067910 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAA@XZ 0x141067950 ; prop
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAEV?$CustomAllocator@E@efd@@@std@@QEAA@XZ 0x141067990 ; unique
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAPEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@QEAA@XZ 0x1410679d0 ; prop
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAPEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEAA@XZ 0x141067a10 ; fx19 chain
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAUUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@QEAA@XZ 0x141067bd0 ; fx19 chain
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAUUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@QEAA@XZ 0x141067a50 ; prop
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@QEAA@XZ 0x141067a90 ; fx19 chain
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@QEAA@XZ 0x141067ad0 ; fx19 chain
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAA@XZ 0x141067b10 ; fx19 chain
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@QEAA@XZ 0x141067b50 ; fx19 chain
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAV?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAA@XZ 0x141067b90 ; fx19 chain
// MS2-PIN: ??1?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@efd@@QEAA@XZ 0x141067dd0 ; prop
// MS2-PIN: ??1?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@@std@@QEAA@XZ 0x141067df0 ; prop
// MS2-PIN: ??1?$map@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@@efd@@QEAA@XZ 0x141067e10 ; prop
// MS2-PIN: ??1?$map@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@@std@@QEAA@XZ 0x141067e30 ; prop
// MS2-PIN: ??1?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@QEAA@XZ 0x141067eb0 ; prop
// MS2-PIN: ??1?$set@EU?$less@E@std@@@efd@@QEAA@XZ 0x141067f10 ; unique
// MS2-PIN: ??1?$set@EU?$less@E@std@@V?$CustomAllocator@E@efd@@@std@@QEAA@XZ 0x141067f30 ; prop
// MS2-PIN: ??1?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAA@XZ 0x141067f50 ; unique
// MS2-PIN: ??1?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@QEAA@XZ 0x141067f70 ; prop
// MS2-PIN: ??1?$vector@E@efd@@QEAA@XZ 0x141067f90 ; prop
// MS2-PIN: ??1?$vector@PEAVNiDataStreamRef@@@efd@@QEAA@XZ 0x141067fe0 ; prop
// MS2-PIN: ??1?$vector@V?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@QEAA@XZ 0x1410680d0 ; prop
// MS2-PIN: ??1?$vector@V?$set@EU?$less@E@std@@@efd@@@efd@@QEAA@XZ 0x141068100 ; prop
// MS2-PIN: ??1?$vector@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@QEAA@XZ 0x141068120 ; prop
// MS2-PIN: ??1?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@QEAA@XZ 0x141068150 ; prop
// MS2-PIN: ??1?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAA@XZ 0x141068170 ; prop
// MS2-PIN: ??1?$vector@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@QEAA@XZ 0x1410681c0 ; prop
// MS2-PIN: ??1?$vector@V?$vector@PEAVNiMesh@@@efd@@@efd@@QEAA@XZ 0x1410681f0 ; prop
// MS2-PIN: ??1?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAA@XZ 0x141068210 ; prop
// MS2-PIN: ??1NiDataStreamElementSet@@QEAA@XZ 0x141068290 ; prop
// MS2-PIN: ??1TexNode@CCharacterMeshMerger@@UEAA@XZ 0x141068320 ; unique
// MS2-PIN: ??1Unk_AtlasResult@@QEAA@XZ 0x141068240 ; w200 hand
// MS2-PIN: ??4?$SmartPointer@VNiTexture@@@efd@@QEAAAEAV01@PEAVNiTexture@@@Z 0x141068540 ; unique
// MS2-PIN: ??4?$SmartPointer@VNiTexturingProperty@@@efd@@QEAAAEAV01@PEAVNiTexturingProperty@@@Z 0x1410685b0 ; prop
// MS2-PIN: ??8?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@U_Iterator_base0@2@@std@@QEBA_NAEBV01@@Z 0x141068890 ; unique
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@PEAVNiDataStreamRef@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1410688d0 ; prop
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141068920 ; prop
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1410689c0 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141068a10 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141068a50 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141068a90 ; prop
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@PEAVNiDataStreamRef@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141068c10 ; unique
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141068c50 ; unique
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141068cd0 ; unique
// MS2-PIN: ??A?$map@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@@std@@QEAAAEAV?$map@EEU?$less@E@std@@@efd@@AEBQEAVNiMesh@@@Z 0x141068ed0 ; fx19 chain
// MS2-PIN: ??A?$vector@EV?$CustomAllocator@E@efd@@@std@@QEBAAEBE_K@Z 0x141068f10 ; w200 hand
// MS2-PIN: ??A?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEAAAEAPEAVNiMesh@@_K@Z 0x141068f40 ; w200 hand
// MS2-PIN: ??A?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@QEBAAEBQEAVNiMesh@@_K@Z 0x141068f70 ; w200 hand
// MS2-PIN: ??A?$vector@UUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@QEBAAEBUUnk_StreamElementDesc@@_K@Z 0x141068fa0 ; w200 hand
// MS2-PIN: ??A?$vector@V?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@QEAAAEAV?$map@EEU?$less@E@std@@@efd@@_K@Z 0x141068fd0 ; w200 hand
// MS2-PIN: ??A?$vector@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@QEAAAEAV?$set@EU?$less@E@std@@@efd@@_K@Z 0x141069000 ; w200 hand
// MS2-PIN: ??A?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAAAEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@_K@Z 0x141069030 ; w200 hand
// MS2-PIN: ??A?$vector@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@QEAAAEAV?$vector@E@efd@@_K@Z 0x141069060 ; w200 hand
// MS2-PIN: ??A?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAAAEAV?$vector@PEAVNiMesh@@@efd@@_K@Z 0x141069090 ; w200 hand
// MS2-PIN: ??A?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEBAAEBV?$vector@PEAVNiMesh@@@efd@@_K@Z 0x1410690c0 ; w200 hand
// MS2-PIN: ??C?$SmartPointer@VNiPixelData@@@efd@@QEBAPEAVNiPixelData@@XZ 0x141069160 ; prop
// MS2-PIN: ??C?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@std@@QEBAPEBU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@1@XZ 0x141069180 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@1@XZ 0x1410691e0 ; fx19 chain
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@1@XZ 0x141069240 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@1@XZ 0x141069280 ; fx19 chain
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBEE@1@XZ 0x1410692c0 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@1@XZ 0x141069300 ; fx19 chain
// MS2-PIN: ??D?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@PEAVNiDataStreamRef@@@std@@@std@@@std@@QEBAAEBQEAVNiDataStreamRef@@XZ 0x141069360 ; unique
// MS2-PIN: ??D?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@@std@@QEBAAEBQEAVNiMesh@@XZ 0x141069370 ; unique
// MS2-PIN: ??D?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@QEBAAEBV?$vector@PEAVNiMesh@@@efd@@XZ 0x141069390 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@@std@@QEAA?AV01@H@Z 0x141069420 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@@std@@QEAAAEAV01@XZ 0x141069470 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141069490 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1410694e0 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141069500 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1410695e0 ; fx19 chain
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141069630 ; fx19 chain
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141069730 ; fx19 chain
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1410697e0 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141069870 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141069990 ; fx19 chain
// MS2-PIN: ??E?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@PEAVNiDataStreamRef@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141069b40 ; unique
// MS2-PIN: ??E?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141069b60 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141069c00 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141069ca0 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141069d40 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141069e10 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141069ee0 ; prop
// MS2-PIN: ??_G?$map@EEU?$less@E@std@@@efd@@QEAAPEAXI@Z 0x14106a640 ; prop
// MS2-PIN: ??_G?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@QEAAPEAXI@Z 0x14106a680 ; unique
// MS2-PIN: ??_G?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@QEAAPEAXI@Z 0x14106a700 ; prop
// MS2-PIN: ??_G?$set@EU?$less@E@std@@@efd@@QEAAPEAXI@Z 0x14106a740 ; prop
// MS2-PIN: ??_G?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@QEAAPEAXI@Z 0x14106a780 ; prop
// MS2-PIN: ??_G?$vector@E@efd@@QEAAPEAXI@Z 0x14106a7c0 ; prop
// MS2-PIN: ??_G?$vector@PEAVNiMesh@@@efd@@QEAAPEAXI@Z 0x14106a800 ; prop
// MS2-PIN: ?CreateInstance@CCustomizedTextureManager@@SAPEAV1@XZ 0x14106b3d0 ; w200 hand
// MS2-PIN: ?GetDataStream@NiDataStreamRef@@QEAAPEAVNiDataStream@@XZ 0x14106bb40 ; unique
// MS2-PIN: ?GetMaterial@NiPropertyState@@QEBAPEAVNiMaterialProperty@@XZ 0x14106bd60 ; w200 hand
// MS2-PIN: ?IsEqualFast@NiMaterialProperty@@QEBA_NAEBV1@@Z 0x14106c850 ; w200 hand
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@2@XZ 0x14106d320 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@2@XZ 0x14106d560 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@EPEAX@2@XZ 0x14106d6e0 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@2@XZ 0x14106d7a0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@2@XZ 0x14106d940 ; fx19 chain
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@2@XZ 0x14106db00 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@2@XZ 0x14106dbe0 ; prop
// MS2-PIN: ?_Calculate_growth@?$vector@PEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@AEBA_K_K@Z 0x14106de80 ; prop
// MS2-PIN: ?_Calculate_growth@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@AEBA_K_K@Z 0x14106df10 ; fx19 chain
// MS2-PIN: ?_Calculate_growth@?$vector@UUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@AEBA_K_K@Z 0x14106e300 ; fx19 chain
// MS2-PIN: ?_Calculate_growth@?$vector@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@AEBA_K_K@Z 0x14106e1e0 ; fx19 chain
// MS2-PIN: ?_Calculate_growth@?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@AEBA_K_K@Z 0x14106e270 ; fx19 chain
// MS2-PIN: ?_Change_array@?$vector@PEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@AEAAXQEAPEAVNiAVObject@@_K1@Z 0x14106e390 ; prop
// MS2-PIN: ?_Change_array@?$vector@UUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@AEAAXQEAUUnk_AtlasResult@@_K1@Z 0x14106ec10 ; fx19 chain
// MS2-PIN: ?_Change_array@?$vector@V?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@AEAAXQEAV?$map@EEU?$less@E@std@@@efd@@_K1@Z 0x14106e6c0 ; prop
// MS2-PIN: ?_Change_array@?$vector@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@AEAAXQEAV?$set@EU?$less@E@std@@@efd@@_K1@Z 0x14106e7d0 ; fx19 chain
// MS2-PIN: ?_Change_array@?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@AEAAXQEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@_K1@Z 0x14106e8e0 ; fx19 chain
// MS2-PIN: ?_Change_array@?$vector@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@AEAAXQEAV?$vector@E@efd@@_K1@Z 0x14106e9f0 ; fx19 chain
// MS2-PIN: ?_Change_array@?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@AEAAXQEAV?$vector@PEAVNiMesh@@@efd@@_K1@Z 0x14106eb00 ; fx19 chain
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBQEAVNiMesh@@0@Z 0x14106ed60 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x14106eda0 ; prop
// MS2-PIN: ?_Compat@?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@PEAVNiDataStreamRef@@@std@@@std@@@std@@QEBAXAEBV12@@Z 0x14106ee20 ; prop
// MS2-PIN: ?_Compat@?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@QEBAXAEBV12@@Z 0x14106ee50 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14106ee90 ; fx19 chain
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14106eef0 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14106ef20 ; fx19 chain
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEAAXXZ 0x14106ef50 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14106ef80 ; prop
// MS2-PIN: ?_Destroy@?$vector@EV?$CustomAllocator@E@efd@@@std@@AEAAXPEAE0@Z 0x14106efb0 ; prop
// MS2-PIN: ?_Destroy@?$vector@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@AEAAXPEAPEAVNiMesh@@0@Z 0x14106f030 ; fx19 chain
// MS2-PIN: ?_Destroy@?$vector@UUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@AEAAXPEAUUnk_StreamElementDesc@@0@Z 0x14106f070 ; unique
// MS2-PIN: ?_Destroy@?$vector@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@AEAAXPEAV?$set@EU?$less@E@std@@@efd@@0@Z 0x14106f0f0 ; fx19 chain
// MS2-PIN: ?_Destroy@?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@AEAAXPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@0@Z 0x14106f130 ; fx19 chain
// MS2-PIN: ?_Destroy@?$vector@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@AEAAXPEAV?$vector@E@efd@@0@Z 0x14106f170 ; fx19 chain
// MS2-PIN: ?_Destroy@?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@AEAAXPEAV?$vector@PEAVNiMesh@@@efd@@0@Z 0x14106f1b0 ; fx19 chain
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@2@@Z 0x14106f280 ; fx19 chain
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@2@@Z 0x14106f320 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@2@@Z 0x14106f370 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@2@@Z 0x14106f480 ; fx19 chain
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@2@@Z 0x14106f5c0 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@2@@Z 0x14106f660 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@QEAAPEAU?$_Tree_node@EPEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@@2@@Z 0x14106f840 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@QEAAPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@@2@@Z 0x14106fdf0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@@2@@Z 0x1410703a0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@@2@@Z 0x141070f00 ; fx19 chain
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@2@@Z 0x141072010 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@2@@Z 0x141072040 ; fx19 chain
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@2@@Z 0x1410720a0 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@EPEAX@2@@Z 0x141072100 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@2@@Z 0x141072130 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@2@@Z 0x141072160 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@UUnk_UVRect@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@PEAX@2@@Z 0x1410721c0 ; fx19 chain
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@2@@Z 0x141072190 ; fx19 chain
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@2@@Z 0x1410721f0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@EPEAX@2@@Z 0x141072250 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@PEAVNiAVObject@@PEAX@2@@Z 0x141072280 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@2@XZ 0x1410722b0 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@2@XZ 0x1410722e0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@2@XZ 0x141072340 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@2@XZ 0x1410723d0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@2@XZ 0x1410725a0 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVNiMesh@@V?$CustomAllocator@PEAVNiMesh@@@efd@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@2@XZ 0x1410725c0 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@UUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@UUnk_AtlasResult@@@std@@@2@XZ 0x141072760 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@UUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@UUnk_AtlasResult@@@std@@@2@XZ 0x141072780 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@2@XZ 0x1410725e0 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamElementDesc@@V?$allocator@UUnk_StreamElementDesc@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@2@XZ 0x141072600 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$map@EEU?$less@E@std@@@efd@@@std@@@2@XZ 0x141072620 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$map@EEU?$less@E@std@@@efd@@@std@@@2@XZ 0x141072640 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@2@XZ 0x141072660 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@2@XZ 0x141072680 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@2@XZ 0x1410726a0 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@2@XZ 0x1410726c0 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$vector@E@efd@@@std@@@2@XZ 0x1410726e0 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$vector@E@efd@@@std@@@2@XZ 0x141072700 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@2@XZ 0x141072720 ; fx19 chain
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@2@XZ 0x141072740 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@E@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@$00@2@$00@std@@QEAAAEAU?$less@E@2@XZ 0x1410727c0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@E@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBU?$less@E@2@XZ 0x1410727d0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@PEAVNiAVObject@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@$00@2@$00@std@@QEAAAEAU?$less@PEAVNiAVObject@@@2@XZ 0x1410727e0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@PEAVNiMesh@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBU?$less@PEAVNiMesh@@@2@XZ 0x141072830 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@PEAVNiMesh@@@efd@@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@PEAVNiMesh@@@efd@@XZ 0x1410728c0 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@XZ 0x141072920 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@XZ 0x141072930 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@XZ 0x141072940 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@XZ 0x141072950 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@XZ 0x141072970 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@XZ 0x141072980 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@V?$_Vector_val@U?$_Simple_types@UUnk_AtlasResult@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@UUnk_AtlasResult@@@efd@@XZ 0x141072a60 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@XZ 0x1410729b0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@XZ 0x1410729d0 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@XZ 0x1410729e0 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@XZ 0x1410729f0 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@XZ 0x141072a00 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$vector@E@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$vector@E@efd@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@V?$vector@E@efd@@@efd@@XZ 0x141072a10 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$vector@E@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$vector@E@efd@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@V?$vector@E@efd@@@efd@@XZ 0x141072a20 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@XZ 0x141072a30 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@XZ 0x141072a40 ; fx19 chain
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@UUnk_StreamElementDesc@@@std@@V?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@2@$00@std@@QEAAAEAV?$allocator@UUnk_StreamElementDesc@@@2@XZ 0x141072a70 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@E@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@EPEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@EPEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@$00@2@XZ 0x141072a90 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@E@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@$00@2@XZ 0x141072ac0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@PEAVNiAVObject@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@PEAVNiAVObject@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@$00@2@XZ 0x141072ad0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@PEAVNiMesh@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@$00@2@XZ 0x141072af0 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@2@XZ 0x141072b30 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@2@XZ 0x141072b40 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@UUnk_TransformLess@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@$00@std@@$00@std@@QEAAAEAV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@std@@@std@@$00@2@XZ 0x141072b50 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@PEAVNiMesh@@@efd@@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@2@XZ 0x141072bb0 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@PEAVNiMesh@@@efd@@V?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@std@@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVNiMesh@@@std@@@2@XZ 0x141072bc0 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@EPEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@E@std@@@std@@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@E@std@@@2@XZ 0x141072bd0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBEE@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@std@@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBEE@std@@@std@@@2@XZ 0x141072c20 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@2@XZ 0x141072c30 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@2@XZ 0x141072c40 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@std@@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@std@@@2@XZ 0x141072c60 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@2@XZ 0x141072cc0 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@std@@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$set@EU?$less@E@std@@@efd@@@std@@@2@XZ 0x141072cd0 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@2@XZ 0x141072ce0 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@std@@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@std@@@2@XZ 0x141072cf0 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@UUnk_StreamElementDesc@@@std@@V?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@2@XZ 0x141072d60 ; fx19 chain
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@UUnk_StreamElementDesc@@@std@@V?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@UUnk_StreamElementDesc@@@std@@@2@XZ 0x141072d70 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@XZ 0x141072de0 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@PEAX@std@@@efd@@XZ 0x141072e10 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@XZ 0x141072ea0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEBAAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@std@@@efd@@XZ 0x141072ed0 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@XZ 0x141072f00 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@PEAX@std@@@efd@@XZ 0x141072f30 ; w200 hand
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@UUnk_AtlasResult@@V?$CustomAllocator@UUnk_AtlasResult@@@efd@@@std@@@std@@QEBAAEBV?$CustomAllocator@UUnk_AtlasResult@@@efd@@XZ 0x141073280 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$map@EEU?$less@E@std@@@efd@@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@std@@@std@@QEAAAEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@XZ 0x141073120 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@@std@@QEAAAEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@XZ 0x141073160 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$set@EU?$less@E@std@@@efd@@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@@std@@QEBAAEBV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@efd@@XZ 0x141073180 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@@std@@QEAAAEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@efd@@XZ 0x1410731a0 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@@std@@QEAAAEAV?$CustomAllocator@V?$vector@E@efd@@@efd@@XZ 0x1410731e0 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$vector@E@efd@@V?$CustomAllocator@V?$vector@E@efd@@@2@@std@@@std@@QEBAAEBV?$CustomAllocator@V?$vector@E@efd@@@efd@@XZ 0x141073200 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@@std@@QEAAAEAV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@XZ 0x141073220 ; fx19 chain
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@@std@@QEBAAEBV?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@XZ 0x141073240 ; fx19 chain
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@QEAVNiMesh@@UUnk_UVRect@@@1@XZ 0x141069200 ; fx19 chain
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAVNiMesh@@UUnk_UVRect@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@QEAVNiMesh@@UUnk_UVRect@@@1@XZ 0x141069320 ; fx19 chain
// MS2-PINS-END tplpin
// MS2-FUNCTIONAL ??$_Buynode@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@PEAX@1@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@1@@Z: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ??$_Destroy_range@V?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@efd@@@std@@YAXPEAV?$map@EEU?$less@E@std@@@efd@@0AEAV?$CustomAllocator@V?$map@EEU?$less@E@std@@@efd@@@2@@Z: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ??$_Emplace_back@V?$vector@PEAVNiMesh@@@efd@@@?$_Uninitialized_backout_al@PEAV?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAAX$$QEAV?$vector@PEAVNiMesh@@@efd@@@Z: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ??$_Emplace_reallocate@V?$vector@PEAVNiMesh@@@efd@@@?$vector@V?$vector@PEAVNiMesh@@@efd@@V?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@2@@std@@QEAAPEAV?$vector@PEAVNiMesh@@@efd@@QEAV23@$$QEAV23@@Z: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ??$_Uninitialized_copy_al_unchecked@PEAV?$set@EU?$less@E@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@@std@@YAPEAV?$set@EU?$less@E@std@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$set@EU?$less@E@std@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ??$_Uninitialized_copy_al_unchecked@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@YAPEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@PEAV12@QEAV12@1AEAV?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ??0?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@PEAVNiMesh@@@1@@Z: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ??0?$_Tree_comp_alloc@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@QEAA@AEBUUnk_TransformLess@@@Z: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ??1?$_Uninitialized_backout_al@PEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@QEAA@XZ: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ??1Unk_AtlasResult@@QEAA@XZ: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ?_Change_array@?$vector@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@V?$CustomAllocator@V?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@@2@@std@@AEAAXQEAV?$set@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@@efd@@_K1@Z: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@VNiTransform@@V?$vector@PEAVNiMesh@@@efd@@UUnk_TransformLess@@V?$CustomAllocator@U?$pair@$$CBVNiTransform@@V?$vector@PEAVNiMesh@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAXXZ: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
// MS2-FUNCTIONAL ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@PEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@U?$less@PEAVNiMesh@@@std@@V?$CustomAllocator@U?$pair@QEAVNiMesh@@V?$map@EEU?$less@E@std@@@efd@@@std@@@3@$0A@@std@@@std@@QEAAXXZ: body byte-identical; only callee binding differs: the exe's byte-identical STL template copies (map/set/vector of the merger's element types) sit at VAs crossed versus the guessed element type names, and re-pinning cascades into symbol conflicts across unit_141073440/unit_1410799d0 (needs the real element type names)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\charactermeshmerger.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "charactermeshmerger.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "hook/ms2hook.h"
#include <NiMesh.h>
#include <NiNode.h>
#include <NiStream.h>
#include <NiSkinningMeshModifier.h>
#include <NiMorphMeshModifier.h>
#include <NiCommonSemantics.h>
#include <NiTexture.h>
#include <NiPoint2.h>
#include <NiDataStreamFactory.h>
#include <NiTexturingProperty.h>
#include <NiSourceTexture.h>
#include <NiPixelData.h>
#include <NiMaterialProperty.h>
#include <NiAlphaProperty.h>
#include <NiDitherProperty.h>
#include <NiFogProperty.h>
#include <NiShadeProperty.h>
#include <NiSpecularProperty.h>
#include <NiStencilProperty.h>
#include <NiVertexColorProperty.h>
#include <NiWireframeProperty.h>
#include <NiZBufferProperty.h>
#include <NiColorExtraData.h>
#include <NiFloatsExtraData.h>
#include <NiFloatExtraData.h>
#include <NiPropertyState.h>
#include <algorithm>
#include <d3dx9.h>
#include <efd/LoggerMacros.h>
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/unk_1402a9d70.h"

// The header statics (the sort-name table, skill and stun of header_statics_a.h), then the atlas divisor and the condition table.
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static NiColor s_kAtlasDivisor(0.70710677f, 0.70710677f, 0.70710677f);   // 1/sqrt(2) grey, the atlas alpha divisor
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static int s_iAtlasFileCount;                                            // number of atlases dumped so far

// Scene walker of the cube code (ctor 0x14098cb80); children are queued by AddChildren and Next returns the next object.
class Unk_CubeSceneIterator {
public:
    Unk_CubeSceneIterator(NiAVObject* pRoot);
    ~Unk_CubeSceneIterator();
    NiAVObject* FUN_14098e0d0(bool descend);
    void FUN_14098d6d0(NiNode* pNode);                  // queue the children
private:
    ATL::CAtlList<NiAVObject*> pending;
};
MS2_CHECK_SIZE(Unk_CubeSceneIterator, 0x30);

bool FUN_14098dad0(NiAVObject* pObject);                // object is hidden/culled
NiNode* FUN_140a0b000(NiAVObject* pObject);             // parent node
bool FUN_141052aa0(const NiPropertyState* pA, const NiPropertyState* pB);   // property states are equal

struct Unk_MaterialTable;                               // DAT_143d69198 (MS2StandardMaterial RTTI)
struct Unk_MaterialEntry;
extern Unk_MaterialTable DAT_143d69198;
Unk_MaterialEntry* FUN_140a17af0(Unk_MaterialTable* pTable, const NiMaterial* pMaterial);
int FUN_140ef4dd0(Unk_MaterialEntry* pEntry);
NiMaterial* FUN_140a17cd0(NiMesh* pMesh);         // active material
int FUN_141049fa0(NiMesh* pMesh, const MeshGroups& kGroups);

CLogString* FUN_140166440();

// Four-argument wide log (template instance 0x141054b90).
template<class T, class U, class V, class W> inline void Unk_MeshLog(CLogString* log, int level, int category, const wchar_t* format,
                                                                   const T& first, const U& second, const V& third, const W& fourth) {
    const fmt::internal::ArgArray<4>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(third),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(fourth)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third, fourth), args));
}

typedef ATL::CAtlArray<efd::SmartPointer<NiMesh> > MeshArray;

// One element of the merged vertex stream: semantic, semantic index and format (ctor 0x141066fd0).
struct Unk_StreamElementDesc
{
    Unk_StreamElementDesc(const NiFixedString& kSemantic, unsigned int uiIndex, NiDataStreamElement::Format eFormat)
        : m_kSemantic(kSemantic), m_uiIndex(uiIndex), m_eFormat(eFormat) {}

    NiFixedString m_kSemantic;
    unsigned int m_uiIndex;
    NiDataStreamElement::Format m_eFormat;
};
MS2_CHECK_SIZE(Unk_StreamElementDesc, 0x10);

// UV placement of one mesh's texture inside the atlas: offset then scale.
struct Unk_UVRect
{
    Unk_UVRect() {}

    NiPoint2 m_kOffset;
    NiPoint2 m_kScale;
};
MS2_CHECK_SIZE(Unk_UVRect, 0x10);

// Atlas of one group: the texturing property and where every mesh's texture went (ctor 0x141066e30, dtor 0x141068240).
struct Unk_AtlasResult
{
    Unk_AtlasResult() {}
    ~Unk_AtlasResult() {}
    void Clear() { m_spTexturing = 0; m_kPlacement.clear(); }    // 0x14106b3a0

    efd::SmartPointer<NiTexturingProperty> m_spTexturing;                           // +0
    efd::map<NiMesh*, Unk_UVRect> m_kPlacement;     // +8; keyed by NiMesh*: its tree calls the NiMesh-map comparator copy 0x14106a370, set<NiAVObject*> calls 0x14106a330
};
MS2_CHECK_SIZE(Unk_AtlasResult, 0x18);

typedef efd::vector<MeshList> MeshGroupVector;

bool FUN_14098dfc0(NiAVObject* pObject);                    // object is an attachment/helper that is not merged
bool FUN_140a56f50(const NiColor* pA, const NiColor* pB);   // colours differ
extern const NiPixelFormat DAT_1439fb040;                   // atlas pixel format
extern NiTexture::FormatPrefs DAT_1439fc800;          // atlas texture format preferences
extern const NiFixedString DAT_143ae50c8;                   // customised texture extra data keys (0x143ae50c8-0x143ae5200)
extern const NiFixedString DAT_143ae50d0;
extern const NiFixedString DAT_143ae50d8;
extern const NiFixedString DAT_143ae50f8;
extern const NiFixedString DAT_143ae5100;
extern const NiFixedString DAT_143ae5108;
extern const NiFixedString DAT_143ae5110;
extern const NiFixedString DAT_143ae5148;
extern const NiFixedString DAT_143ae5150;
extern const NiFixedString DAT_143ae5200;

// Pixel helpers of the atlas packer (texture utility code).
NiPixelData* DownsamplePixels(NiPixelData* pSource, unsigned int uiStep);
void CopyPixelRect(NiPixelData* pSource, const NiRect<unsigned int>& kSourceRect, NiPixelData* pDest, const NiRect<unsigned int>& kDestRect);
void BlitTexturePixels(NiSourceTexture* pTexture, NiPixelData* pDest, const NiRect<unsigned int>& kRect, float fAlpha);
void FillPixelRect(const unsigned char* pColor, NiPixelData* pDest, const NiRect<unsigned int>& kRect);
int SaveTextureToFileA(ATL::CSimpleStringT<char, 1>* pPath, D3DXIMAGE_FILEFORMAT eFormat, NiTexture* pTexture);
// The smaller and the larger of two values (template instance 0x141054fe0, named after its place in the COMDAT order).
template<class T> inline void Unk_SortPair(T a, T b, T* pMin, T* pMax)
{
    if (a < b)
    {
        *pMin = a;
        *pMax = b;
    }
    else
    {
        *pMin = b;
        *pMax = a;
    }
}
CString FUN_140db9aa0(const NiColorA& kColor);

// Compositing manager of the customised (dyed) character textures.
class CCustomizedTexInfo : public NiRefObject
{
public:
    CCustomizedTexInfo();                                   // 0x141165f00

    efd::SmartPointer<NiTexture> m_spBase;                  // +0x10
    efd::SmartPointer<NiTexture> m_spDecal;                 // +0x18
    NiColorA m_kColor0;                                     // +0x20
    NiColorA m_kColor1;                                     // +0x30
    NiColorA m_kColor2;                                     // +0x40
    float m_afParams[4];                                    // +0x50
};
MS2_CHECK_SIZE(CCustomizedTexInfo, 0x60);
// Composes the customized character textures (header-inline singleton, 8 bytes: the vptr only; TSingleton vftable 0x142ea5e00,
// own vftable 0x142ea5e10, s_instance 0x143acd498). Only its inline members live in this unit.
class CCustomizedTextureManager : public TSingleton<CCustomizedTextureManager>
{
public:
    CCustomizedTextureManager() {}
    static CCustomizedTextureManager* CreateInstance() { return GetInstance() != 0 ? GetInstance() : new CCustomizedTextureManager; }
};
MS2_CHECK_SIZE(CCustomizedTextureManager, 0x8);
CCustomizedTexInfo* FUN_1411660b0(CCustomizedTextureManager* pManager, CCustomizedTexInfo* pInfoA, CCustomizedTexInfo* pInfoB);

// Orders world transforms lexicographically for the per-transform grouping map.
struct Unk_TransformLess
{
    bool operator()(const NiTransform& kA, const NiTransform& kB) const;
};

void FUN_141050880(unsigned int uiAtlasSize, unsigned int uiWidth, unsigned int uiHeight, unsigned int uiLeft, unsigned int uiTop, NiPoint2* pOffset, NiPoint2* pScale);
void FUN_141050920(Unk_AtlasResult* pResult, NiPixelData* pAlbedo, NiPixelData* pShader);
bool FUN_141052ff0(NiAVObject* pA, NiAVObject* pB);
CString FUN_1410521a0(NiAVObject* pMesh);
void FUN_1401d3700(CString& str);   // commonfiles/cachedata.cpp: in-place MakeLower

// Lower-case copy of a string (0x14106d0b0).
inline CString Unk_LowerCopy(const CString& str)
{
    CString strLower(str);
    FUN_1401d3700(strLower);
    return strLower;
}

// 0x14106d070
inline CString Unk_Lower(const CString& str)
{
    return Unk_LowerCopy(str);
}
efd::SmartPointer<NiSourceTexture> FUN_141051560(NiAVObject* pMesh);
void FUN_141051f90(NiAVObject* pMesh, NiPixelData* pShaderMap, const NiRect<unsigned int>& kRect);
NiTexturingProperty* FUN_141050fd0(NiPixelData* pAlbedo, NiPixelData* pShader);

// Skinning merge state of one group (ctor 0x141067020, dtor 0x1410682d0; 0x50 bytes).
struct MergeInfo
{
    MergeInfo() {}
    ~MergeInfo() {}

    efd::SmartPointer<NiSkinningMeshModifier> m_spSkin;                             // +0 the merged modifier
    efd::map<NiMesh*, efd::map<unsigned char, unsigned char> > m_kBoneRemap;        // +8 per mesh: old bone index -> merged index
    efd::vector<efd::vector<unsigned char> > m_kBoneLists;                          // +0x18 per bucket: merged bone indices
    efd::vector<efd::map<unsigned char, unsigned char> > m_kBucketRemap;            // +0x30
};

MeshGroups* FUN_141066d90(MeshGroups* pGroups);
void FUN_14104a1c0(const MeshList& kGroup, MeshGroups& kBuckets, MergeInfo& kInfo);
NiMesh* FUN_14104ae20(const MeshGroups& kBuckets, MergeInfo& kInfo, NiAVObject* pRoot);
void FUN_14104e800(const MeshList& kGroup, MeshGroups& kBuckets, MergeInfo& kInfo);
NiMesh* FUN_14104f460(const MeshGroups& kBuckets, MergeInfo& kInfo, NiAVObject* pRoot);
void FUN_141049d50(NiAVObject* pRoot, MeshGroups& kGroups);
void FUN_14104b530(NiMesh* pMerged, const MeshGroups& kBuckets);
void FUN_14104bbb0(NiMesh* pMerged, MergeInfo& kInfo, const MeshGroups& kBuckets, const NiTransform& kRootTransform);
int FUN_141051ee0(efd::set<NiAVObject*>& kBones, NiAVObject** ppBones, unsigned int uiCount);
void FUN_14104d450(NiAVObject* pRoot, MeshGroups& kGroups);

// @0x141049240
void FUN_141049240(NiAVObject* pRoot, MeshArray& kSource, MeshArray& kMerged)
{
    if (pRoot == 0)
        return;
    MeshGroups kGroups;
    FUN_141049d50(pRoot, kGroups);
    for (unsigned int i = 0; i < kGroups.size(); i++)
    {
        if (kGroups[i].size() == 1)
            continue;
        for (unsigned int j = 0; j < kGroups[i].size(); j++)
        {
            efd::SmartPointer<NiMesh> spMesh(kGroups[i][j]);
            kSource.Add(spMesh);
        }
    }
    if (kSource.GetCount() == 0)
        return;
    for (unsigned int i = 0; i < kGroups.size(); i++)
    {
        CString kLine = Unk_SocketFormat("{0}:", i);
        for (unsigned int j = 0; j < kGroups[i].size(); j++)
            kLine += Unk_SocketFormat(" {0}", (const char*)kGroups[i][j]->GetName());
        EE_LOG_AT(1, 1, ((const char*)kLine), MS2_THIS_FILE, 0x68f);
    }
    for (unsigned int i = 0; i < kGroups.size(); i++)
    {
        if (kGroups[i].size() == 1)
            continue;
        MeshGroups kBuckets;
        MergeInfo kInfo;
        FUN_14104a1c0(kGroups[i], kBuckets, kInfo);
        efd::SmartPointer<NiMesh> spMerged(FUN_14104ae20(kBuckets, kInfo, pRoot));
        kMerged.Add(spMerged);
        NiStream kStream;
        kStream.InsertObject(spMerged);
        kStream.InsertObject(kInfo.m_spSkin);
        kStream.Save((const char*)Unk_SocketFormat("D:\\MergedMesh_{0}.nif", i));
    }
}

// @0x1410497c0
void FUN_1410497c0(NiAVObject* pRoot, MeshArray& kSource, MeshArray& kMerged)
{
    if (pRoot != 0)
    {
        MeshGroups kGroups;
        FUN_14104d450(pRoot, kGroups);
        for (unsigned int i = 0; i < kGroups.size(); i++)
        {
            for (unsigned int j = 0; j < kGroups[i].size(); j++)
            {
                kSource.Add(efd::SmartPointer<NiMesh>(kGroups[i][j]));
                OutputDebugStringA((const char*)kGroups[i][j]->GetName());
                OutputDebugStringA(",");
            }
            OutputDebugStringA("\n");
        }
        if (kSource.GetCount() == 0)
            return;
        NiAVObject* pParent = kSource[0]->GetParent();
        for (unsigned int i = 0; i < kGroups.size(); i++)
        {
            MeshGroups kBuckets;
            MergeInfo kInfo;
            FUN_14104e800(kGroups[i], kBuckets, kInfo);
            efd::SmartPointer<NiMesh> spMerged(FUN_14104f460(kBuckets, kInfo, pParent));
            kMerged.Add(spMerged);
            NiStream kStream;
            kStream.InsertObject(spMerged);
            kStream.InsertObject(kInfo.m_spSkin);
            kStream.Save("MergedMesh.nif");
        }
    }
}

// @0x141049b10
void FUN_141049b10(NiAVObject* pRoot, CAtlArray<CString>& kNames, MeshArray& kMerged, CString& strFirstParent)
{
    MeshArray kSource;
    FUN_1410497c0(pRoot, kSource, kMerged);
    kNames.RemoveAll();
    for (unsigned int i = 0; i < kSource.GetCount(); i++)
    {
        efd::SmartPointer<NiMesh>& spMesh = kSource.GetAt(i);
        {
            CString strName((const char*)spMesh->GetName());
            kNames.Add(strName);
        }
        if (i == 0)
        {
            if (FUN_140a0b000(spMesh) != 0)
                strFirstParent = (const char*)FUN_140a0b000(spMesh)->GetName();
        }
    }
}

// Mesh is skinned, unlit by properties, has no morph modifier and uses a material of kind 2 (0x141049c60).
// @0x141049c60
bool FUN_141049c60(NiMesh* pMesh)
{
    if (pMesh->GetPrimitiveType() != 0)
        return false;
    if (pMesh->GetProperty(0) != 0)
        return false;
    NiMorphMeshModifier* pMorph = NiDynamicCast(NiMorphMeshModifier, pMesh->GetModifierByType(&NiMorphMeshModifier::ms_RTTI));
    if (pMorph != 0)
        return false;
    NiSkinningMeshModifier* pSkin = NiDynamicCast(NiSkinningMeshModifier, pMesh->GetModifierByType(&NiSkinningMeshModifier::ms_RTTI));
    if (pSkin == 0)
        return false;
    Unk_MaterialEntry* pEntry = FUN_140a17af0(&DAT_143d69198, FUN_140a17cd0(pMesh));
    if (pEntry == 0)
        return false;
    if (FUN_140ef4dd0(pEntry) != 2)
        return false;
    return true;
}

// cl's `for each` (the exe's iteration shape: the end iterator takes the lower slot); clang-cl (the hook DLL build) has no such statement: a range-for there.
#ifdef __clang__
#define CMM_FOR_EACH(decl, container) for (decl : container)
#else
#define CMM_FOR_EACH(decl, container) for each (decl in container)
#endif

// Collects the mergeable meshes of the scene and groups them by parent and property state (0x141049d50).
// @0x141049d50
void FUN_141049d50(NiAVObject* pRoot, MeshGroups& kGroups)
{
    MeshList kMeshes;
    Unk_CubeSceneIterator kIter(pRoot);
    while (NiAVObject* pObject = kIter.FUN_14098e0d0(false))
    {
        if (FUN_14098dad0(pObject))
            continue;
        if (pObject->GetName() == "Bip01")
            continue;
        NiNode* pNode = NiDynamicCast(NiNode, pObject);
        if (pNode != 0)
        {
            kIter.FUN_14098d6d0(pNode);
            continue;
        }
        NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
        if (pMesh == 0)
            continue;
        if (!FUN_141049c60(pMesh))
            continue;
        kMeshes.push_back(pMesh);
    }
    CMM_FOR_EACH(NiMesh* pMesh, kMeshes)
    {
        int iGroup = FUN_141049fa0(pMesh, kGroups);
        if (iGroup == -1)
        {
            kGroups.push_back(MeshList());
            iGroup = (int)kGroups.size() - 1;
        }
        kGroups[iGroup].push_back(pMesh);
    }
}

// Index of the group whose first mesh shares parent and property state with pMesh, or -1 (0x141049fa0).
// @0x141049fa0
int FUN_141049fa0(NiMesh* pMesh, const MeshGroups& kGroups)
{
    for (size_t i = 0; i < kGroups.size(); i++)
    {
        NiMesh* pFirst = kGroups[i][0];
        if (FUN_140a0b000(pFirst) == FUN_140a0b000(pMesh))
        {
            if (FUN_141052aa0(pFirst->GetPropertyState(), pMesh->GetPropertyState()))
                return (int)i;
        }
    }
    return -1;
}

// Total vertex and index counts of all meshes in the groups (0x14104a080).
// @0x14104a080
void FUN_14104a080(const MeshGroups& kGroups, int* pVertices, int* pIndices)
{
    CMM_FOR_EACH(const MeshList& kList, kGroups)
    {
        CMM_FOR_EACH(NiMesh* pMesh, kList)
        {
            *pVertices += pMesh->GetVertexCount();
            int nIndices = pMesh->GetCount(0, NiCommonSemantics::INDEX(), 0);
            *pIndices += nIndices;
        }
    }
}
// @0x14104a1c0
void FUN_14104a1c0(const MeshList& kGroup, MeshGroups& kBuckets, MergeInfo& kInfo)
{
    ATL::CAtlArray<NiAVObject*> kBones;
    ATL::CAtlArray<NiTransform*> kTransforms;
    ATL::CAtlArray<NiBound*> kBounds;
    NiSkinningMeshModifier* pFirstSkin = 0;
    kBuckets.push_back(MeshList());
    efd::vector<efd::set<NiAVObject*> > kBucketBones;
    kBucketBones.push_back(efd::set<NiAVObject*>());
    efd::vector<efd::set<unsigned char> > kBucketIndices;
    kBucketIndices.push_back(efd::set<unsigned char>());
    NiSyncArgs kArgs;
    kArgs.m_uiSubmitPoint = 0x8000;
    kArgs.m_uiCompletePoint = 0x8000;
    for (unsigned int i = 0; i < kGroup.size(); i++)
    {
        NiMesh* pMesh = kGroup[i];
        NiSkinningMeshModifier* pSkin = (NiSkinningMeshModifier*)pMesh->GetModifierByType(&NiSkinningMeshModifier::ms_RTTI);
        NiAVObject** ppBones = pSkin->GetBones();
        NiTransform* pTransforms = pSkin->GetSkinToBoneTransforms();
        NiBound* pBounds = pSkin->GetBoneBounds();
        unsigned int uiBoneCount = pSkin->GetBoneCount();
        pMesh->CompleteModifiers(&kArgs);
        if (pFirstSkin == 0)
            pFirstSkin = pSkin;
        unsigned int uiBucket = 0;
        while (uiBucket < kBucketBones.size())
        {
            if (FUN_141051ee0(kBucketBones[uiBucket], ppBones, uiBoneCount) < 0x3d)
                break;
            uiBucket++;
        }
        if (uiBucket == kBucketBones.size())
        {
            kBuckets.push_back(MeshList());
            kBucketBones.push_back(efd::set<NiAVObject*>());
            kBucketIndices.push_back(efd::set<unsigned char>());
        }
        kInfo.m_kBoneRemap.insert(std::make_pair(pMesh, efd::map<unsigned char, unsigned char>()));
        efd::map<unsigned char, unsigned char>& kRemap = kInfo.m_kBoneRemap[pMesh];
        for (unsigned char ucBone = 0; ucBone < uiBoneCount; ucBone++)
        {
            NiAVObject* pBone = ppBones[ucBone];
            unsigned char ucFound = 0;
            while (ucFound < kBones.GetCount())
            {
                if (pBone == kBones[ucFound])
                {
                    if (!(pTransforms[ucBone].m_Translate == kTransforms[ucFound]->m_Translate))
                    {
                        NiPoint3 kDiff = pTransforms[ucBone].m_Translate - kTransforms[ucFound]->m_Translate;
                        Unk_MeshLog(FUN_140166440(), 2, 0x13, L"[MeshOptimizer] Bone {0}의 SkinToBoneTransform이 앞에 설정된 것과 다릅니다 Diff :({1},{2},{3})",
                                    (const char*)pBone->GetName(), kDiff.x, kDiff.y, kDiff.z);
                        kRemap[ucBone] = ucFound;
                    }
                    else
                    {
                        kRemap[ucBone] = ucFound;
                    }
                    break;
                }
                ucFound++;
            }
            if (ucFound == kBones.GetCount())
            {
                kBones.Add(pBone);
                NiTransform* pTransform = &pTransforms[ucBone];
                kTransforms.Add(pTransform);
                NiBound* pBound = &pBounds[ucBone];
                kBounds.Add(pBound);
                kRemap[ucBone] = ucFound;
            }
            kBucketBones[uiBucket].insert(pBone);
            kBucketIndices[uiBucket].insert(ucFound);
        }
        kBuckets[uiBucket].push_back(pMesh);
    }
    unsigned int uiMergedCount = kBones.GetCount();
    NiSkinningMeshModifier* pMerged = NiNew NiSkinningMeshModifier(uiMergedCount);
    pMerged->EnableDynamicBounds();
    NiAVObject** ppMergedBones = pMerged->GetBones();
    NiTransform* pMergedTransforms = pMerged->GetSkinToBoneTransforms();
    NiBound* pMergedBounds = pMerged->GetBoneBounds();
    pMerged->SetRootBoneParent(pFirstSkin->GetRootBoneParent());
    pMerged->SetRootBoneParentToSkinTransform(pFirstSkin->GetRootBoneParentToSkinTransform());
    for (unsigned int i = 0; i < uiMergedCount; i++)
    {
        ppMergedBones[i] = kBones[i];
        pMergedTransforms[i] = *kTransforms[i];
        pMergedBounds[i] = *kBounds[i];
    }
    kInfo.m_spSkin = pMerged;
    for (unsigned int i = 0; i < kBucketIndices.size(); i++)
    {
        kInfo.m_kBoneLists.push_back(efd::vector<unsigned char>(kBucketIndices[i].size()));
        std::copy(kBucketIndices[i].begin(), kBucketIndices[i].end(), kInfo.m_kBoneLists[i].begin());
    }
    for (unsigned int i = 0; i < kBucketIndices.size(); i++)
    {
        kInfo.m_kBucketRemap.push_back(efd::map<unsigned char, unsigned char>());
        const efd::vector<unsigned char>& kList = kInfo.m_kBoneLists[i];
        efd::map<unsigned char, unsigned char>& kBucketRemap = kInfo.m_kBucketRemap[i];
        for (unsigned char uc = 0; uc < kList.size(); uc++)
            kBucketRemap.insert(std::make_pair(kList[uc], uc));
    }
}

// @0x14104e800
void FUN_14104e800(const MeshList& kGroup, MeshGroups& kBuckets, MergeInfo& kInfo)
{
    ATL::CAtlArray<NiAVObject*> kBones;
    ATL::CAtlArray<NiTransform*> kTransforms;
    ATL::CAtlArray<NiBound*> kBounds;
    NiSkinningMeshModifier* pFirstSkin = 0;
    kBuckets.push_back(MeshList());
    efd::vector<efd::set<NiAVObject*> > kBucketBones;
    kBucketBones.push_back(efd::set<NiAVObject*>());
    efd::vector<efd::set<unsigned char> > kBucketIndices;
    kBucketIndices.push_back(efd::set<unsigned char>());
    NiSyncArgs kArgs;
    kArgs.m_uiSubmitPoint = 0x8000;
    kArgs.m_uiCompletePoint = 0x8000;
    for (unsigned int i = 0; i < kGroup.size(); i++)
    {
        NiMesh* pMesh = kGroup[i];
        NiSkinningMeshModifier* pSkin = (NiSkinningMeshModifier*)pMesh->GetModifierByType(&NiSkinningMeshModifier::ms_RTTI);
        NiAVObject** ppBones = pSkin->GetBones();
        NiTransform* pTransforms = pSkin->GetSkinToBoneTransforms();
        NiBound* pBounds = pSkin->GetBoneBounds();
        unsigned int uiBoneCount = pSkin->GetBoneCount();
        pMesh->CompleteModifiers(&kArgs);
        if (pFirstSkin == 0)
            pFirstSkin = pSkin;
        unsigned int uiBucket = 0;
        while (uiBucket < kBucketBones.size())
        {
            if (FUN_141051ee0(kBucketBones[uiBucket], ppBones, uiBoneCount) < 0x3d)
                break;
            uiBucket++;
        }
        if (uiBucket == kBucketBones.size())
        {
            kBuckets.push_back(MeshList());
            kBucketBones.push_back(efd::set<NiAVObject*>());
            kBucketIndices.push_back(efd::set<unsigned char>());
        }
        kInfo.m_kBoneRemap.insert(std::make_pair(pMesh, efd::map<unsigned char, unsigned char>()));
        efd::map<unsigned char, unsigned char>& kRemap = kInfo.m_kBoneRemap[pMesh];
        for (unsigned char ucBone = 0; ucBone < uiBoneCount; ucBone++)
        {
            NiAVObject* pBone = ppBones[ucBone];
            unsigned char ucFound = 0;
            while (ucFound < kBones.GetCount())
            {
                if (pBone == kBones[ucFound])
                {
                    if (!(pTransforms[ucBone].m_Translate == kTransforms[ucFound]->m_Translate))
                    {
                        NiPoint3 kDiff = pTransforms[ucBone].m_Translate - kTransforms[ucFound]->m_Translate;
                        Unk_MeshLog(FUN_140166440(), 2, 0x13, L"[MeshOptimizer] Bone {0}의 SkinToBoneTransform이 앞에 설정된 것과 다릅니다 Diff :({1},{2},{3})",
                                    (const char*)pBone->GetName(), kDiff.x, kDiff.y, kDiff.z);
                        kRemap[ucBone] = ucFound;
                    }
                    else
                    {
                        kRemap[ucBone] = ucFound;
                    }
                    break;
                }
                ucFound++;
            }
            if (ucFound == kBones.GetCount())
            {
                kBones.Add(pBone);
                NiTransform* pTransform = &pTransforms[ucBone];
                kTransforms.Add(pTransform);
                NiBound* pBound = &pBounds[ucBone];
                kBounds.Add(pBound);
                kRemap[ucBone] = ucFound;
            }
            kBucketBones[uiBucket].insert(pBone);
            kBucketIndices[uiBucket].insert(ucFound);
        }
        kBuckets[uiBucket].push_back(pMesh);
    }
    unsigned int uiMergedCount = kBones.GetCount();
    NiSkinningMeshModifier* pMerged = NiNew NiSkinningMeshModifier(uiMergedCount);
    pMerged->EnableDynamicBounds();
    NiAVObject** ppMergedBones = pMerged->GetBones();
    NiTransform* pMergedTransforms = pMerged->GetSkinToBoneTransforms();
    NiBound* pMergedBounds = pMerged->GetBoneBounds();
    pMerged->SetRootBoneParent(pFirstSkin->GetRootBoneParent());
    pMerged->SetRootBoneParentToSkinTransform(pFirstSkin->GetRootBoneParentToSkinTransform());
    for (unsigned int i = 0; i < uiMergedCount; i++)
    {
        ppMergedBones[i] = kBones[i];
        pMergedTransforms[i] = *kTransforms[i];
        pMergedBounds[i] = *kBounds[i];
    }
    kInfo.m_spSkin = pMerged;
    for (unsigned int i = 0; i < kBucketIndices.size(); i++)
    {
        kInfo.m_kBoneLists.push_back(efd::vector<unsigned char>(kBucketIndices[i].size()));
        std::copy(kBucketIndices[i].begin(), kBucketIndices[i].end(), kInfo.m_kBoneLists[i].begin());
    }
    for (unsigned int i = 0; i < kBucketIndices.size(); i++)
    {
        kInfo.m_kBucketRemap.push_back(efd::map<unsigned char, unsigned char>());
        const efd::vector<unsigned char>& kList = kInfo.m_kBoneLists[i];
        efd::map<unsigned char, unsigned char>& kBucketRemap = kInfo.m_kBucketRemap[i];
        for (unsigned char uc = 0; uc < kList.size(); uc++)
            kBucketRemap.insert(std::make_pair(kList[uc], uc));
    }
}


// Size the bone set would have after adding the bones (0x141051ee0).
// @0x141051ee0
int FUN_141051ee0(efd::set<NiAVObject*>& kBones, NiAVObject** ppBones, unsigned int uiCount)
{
    int iSize = (int)kBones.size();
    for (unsigned char uc = 0; uc < uiCount; uc++)
    {
        NiAVObject* pBone = ppBones[uc];
        if (kBones.find(pBone) == kBones.end())
            iSize++;
    }
    return iSize;
}

// Builds the merged mesh of one group: concatenated indices and vertices, one submesh per bone bucket (0x14104ae20).
// @0x14104ae20
NiMesh* FUN_14104ae20(const MeshGroups& kBuckets, MergeInfo& kInfo, NiAVObject* pRoot)
{
    unsigned int uiBucketCount = (unsigned int)kBuckets.size();
    int iVertices = 0;
    int iIndices = 0;
    FUN_14104a080(kBuckets, &iVertices, &iIndices);
    if (iVertices == 0)
        return 0;

    NiMesh* pMerged = NiNew NiMesh;
    NiMesh* pFirst = kBuckets[0][0];
    NiTransform kRootTransform = pRoot->GetWorldTransform();
    pMerged->SetPrimitiveType(pFirst->GetPrimitiveType());
    pMerged->SetSubmeshCount((unsigned int)kBuckets.size());
    FUN_14104b530(pMerged, kBuckets);
    FUN_14104bbb0(pMerged, kInfo, kBuckets, kRootTransform);

    if (kInfo.m_spSkin != 0)
    {
        unsigned int uiMaxBones = 0;
        unsigned int uiTotalBones = 0;
        for (unsigned int i = 0; i < uiBucketCount; i++)
        {
            unsigned int uiBones = (unsigned int)kInfo.m_kBoneLists[i].size();
            if (uiMaxBones < uiBones)
                uiMaxBones = uiBones;
            uiTotalBones += uiBones;
        }
        unsigned short* pPalette = (unsigned short*)_malloca(uiMaxBones * uiBucketCount * sizeof(unsigned short));
        unsigned short* pOut = pPalette;
        for (unsigned int i = 0; i < uiBucketCount; i++)
        {
            const efd::vector<unsigned char>& kList = kInfo.m_kBoneLists[i];
            for (unsigned int j = 0; j < kList.size(); j++)
                *pOut++ = kList[j];
            for (unsigned int j = (unsigned int)kList.size(); j < uiMaxBones; j++)
                *pOut++ = 0;
        }
        int iPaletteCount = uiMaxBones * uiBucketCount;
        NiDataStreamRef* pRef = pMerged->AddStream(NiCommonSemantics::BONE_PALETTE(), 0, NiDataStreamElement::F_UINT16_1, iPaletteCount,
                                                   3, NiDataStream::USAGE_USER, pPalette, false, true);
        _freea(pPalette);
        pRef->SetSubmeshCount(uiBucketCount, 0);
        for (unsigned int i = 0; i < uiBucketCount; i++)
        {
            NiDataStream::Region kRegion(i * uiMaxBones, uiMaxBones);
            if (i == 0)
                pRef->GetDataStream()->SetRegion(kRegion, 0);
            else
                pRef->GetDataStream()->AddRegion(kRegion);
            pRef->BindRegionToSubmesh(i, i);
        }
    }

    NiBound kBound = pFirst->GetModelBound();
    for (unsigned int i = 0; i < kBuckets.size(); i++)
    {
        const MeshList& kList = kBuckets[i];
        for (unsigned int j = 0; j < kList.size(); j++)
            kBound.Merge(&kList[j]->GetModelBound());
    }
    pMerged->SetModelBound(kBound);
    pMerged->AddModifier(kInfo.m_spSkin, true);
    pMerged->AttachProperty(pFirst->GetProperty(8));
    pMerged->SetName(NiFixedString("MergedMesh"));
    for (unsigned int i = 0; i < 12; i++)
    {
        if (i != 8)
        {
            NiProperty* pProperty = pFirst->GetProperty(i);
            if (pProperty != 0)
                pMerged->AttachProperty(pProperty);
        }
    }
    pMerged->ApplyAndSetActiveMaterial(FUN_140a17cd0(pFirst), 0xffffffff);
    unsigned short usExtra = pFirst->GetExtraDataSize();
    for (unsigned short us = 0; us < usExtra; us++)
        pMerged->AddExtraData(pFirst->GetExtraDataAt(us));
    pMerged->SetEffectState(pFirst->GetEffectState());
    pMerged->UpdateProperties();
    pMerged->CompleteUpdateModifiers();
    pMerged->UpdateEffects();
    pMerged->Update(0.0, true);
    return pMerged;
}

// Copies the 16- or 32-bit indices of one source mesh into the merged index buffer, rebased by the vertex offset (0x14104ba70).
// @0x14104ba70
void FUN_14104ba70(unsigned int** ppDst, NiDataStreamRef* pRef, unsigned int uiCount, int iVertexOffset, bool b32)
{
    if (pRef != 0 && uiCount != 0)
    {
        NiDataStream* pStream = pRef->GetDataStream();
        unsigned short* pSrc = (unsigned short*)pStream->Lock(5);
        if (!b32)
        {
            unsigned short* pIn = pSrc;
            for (unsigned int i = 0; i < uiCount; i++)
            {
                **ppDst = *pIn + iVertexOffset;
                (*ppDst)++;
                pIn++;
            }
        }
        else
        {
            for (unsigned int i = 0; i < uiCount; i++)
            {
                **ppDst = *(int*)pSrc + iVertexOffset;
                (*ppDst)++;
                pSrc += 2;
            }
        }
        pRef->GetDataStream()->Unlock(5);
    }
}

// Concatenates the index streams of all groups into one 32-bit stream with a region per group (0x14104b530).
// @0x14104b530
void FUN_14104b530(NiMesh* pMerged, const MeshGroups& kBuckets)
{
    unsigned int uiTotal = 0;
    CMM_FOR_EACH(const MeshList& kList, kBuckets)
        CMM_FOR_EACH(NiMesh* pMesh, kList)
            uiTotal += pMesh->GetCount(0, NiCommonSemantics::INDEX(), 0);

    NiDataStreamRef* pRef = pMerged->AddStream(NiCommonSemantics::INDEX(), 0, NiDataStreamElement::F_UINT32_1, uiTotal, 0x12,
                                               NiDataStream::USAGE_VERTEX_INDEX, 0, false, true);
    unsigned int* pDst = (unsigned int*)pRef->GetDataStream()->LockWrite();
    int iVertexOffset = 0;
    CMM_FOR_EACH(const MeshList& kList, kBuckets)
    {
        CMM_FOR_EACH(NiMesh* pMesh, kList)
        {
            unsigned int uiCount = pMesh->GetCount(0, NiCommonSemantics::INDEX(), 0);
            unsigned int uiVertices = pMesh->GetVertexCount();
            FUN_14104ba70(&pDst, pMesh->FindStreamRef(NiCommonSemantics::INDEX(), 0, NiDataStreamElement::F_UINT16_1), uiCount, iVertexOffset, false);
            FUN_14104ba70(&pDst, pMesh->FindStreamRef(NiCommonSemantics::INDEX(), 0, NiDataStreamElement::F_UINT32_1), uiCount, iVertexOffset, true);
            iVertexOffset += uiVertices;
        }
    }
    pRef->GetDataStream()->UnlockWrite();

    unsigned int uiBucketCount = (unsigned int)kBuckets.size();
    pRef->SetSubmeshCount(uiBucketCount, 0);
    int iStart = 0;
    for (unsigned int i = 0; i < uiBucketCount; i++)
    {
        int iCount = 0;
        CMM_FOR_EACH(NiMesh* pMesh, kBuckets[i])
            iCount += pMesh->GetCount(0, NiCommonSemantics::INDEX(), 0);
        NiDataStream::Region kRegion(iStart, iCount);
        if (i == 0)
            pRef->GetDataStream()->SetRegion(kRegion, 0);
        else
            pRef->GetDataStream()->AddRegion(kRegion);
        iStart += iCount;
        pRef->BindRegionToSubmesh(i, i);
    }
}

// Same offset and format as the invalid element placeholder (the exe compares the two fields in the inline operator==).
// Appends the element of (semantic, index) to the merged layout if all source streams agree on its format; 0x10 on a mismatch (0x14104c870).
// @0x14104c870
int FUN_14104c870(std::vector<Unk_StreamElementDesc>& kLayout, const efd::vector<NiDataStreamRef*>& kSources, const NiFixedString& kSemantic, unsigned int uiIndex)
{
    int iFormat = 0;
    CMM_FOR_EACH(NiDataStreamRef* pSource, kSources)
    {
        const NiDataStreamElement& kElement = pSource->FindElementDesc(kSemantic, uiIndex);
        if (kElement.IsEqual(NiDataStreamElement::ms_kInvalidElement))
            continue;
        if (iFormat == 0 || iFormat == kElement.GetFormat())
            iFormat = kElement.GetFormat();
        else
            return 0x10;
    }
    if (iFormat == 0)
        return iFormat;
    kLayout.push_back(Unk_StreamElementDesc(kSemantic, uiIndex, (NiDataStreamElement::Format)iFormat));
    return iFormat;
}

// Index of the first vertex-usage stream of the mesh, or none (0x14104cc20).
// @0x14104cc20
NiDataStreamRef* FUN_14104cc20(NiMesh* pMesh)
{
    unsigned int uiCount = pMesh->GetStreamRefCount();
    for (unsigned int i = 0; i < uiCount; i++)
    {
        NiDataStreamRef* pRef = pMesh->GetStreamRefAt(i);
        if (pRef->GetUsage() == NiDataStream::USAGE_VERTEX)
            return pRef;
    }
    return 0;
}

// Creates the merged vertex stream and its stream ref for the layout (0x14104c9e0).
// @0x14104c9e0
NiDataStreamRef* FUN_14104c9e0(const std::vector<Unk_StreamElementDesc>& kLayout, unsigned int uiVertexCount)
{
    NiDataStreamElementSet kElements;
    for (std::vector<Unk_StreamElementDesc>::const_iterator it = kLayout.begin(), itEnd = kLayout.end(); it != itEnd; ++it)
        kElements.AddElement((*it).m_eFormat);
    NiDataStream* pStream = NiDataStream::CreateDataStream(kElements, uiVertexCount, 0x13, NiDataStream::USAGE_VERTEX, false);
    NiDataStream::Region kRegion(0, uiVertexCount);
    pStream->AddRegion(kRegion);
    NiDataStreamRef* pRef = NiNew NiDataStreamRef;
    pRef->SetPerInstance(true);
    pRef->SetSubmeshCount(1, 0xffff);
    pRef->SetDataStream(pStream);
    for (unsigned int i = 0; i < kLayout.size(); i++)
        pRef->BindSemanticToElementDescAt(i, kLayout[i].m_kSemantic, kLayout[i].m_uiIndex);
    return pRef;
}

// @0x14104cc90
CCharacterMeshMerger::TexNode::TexNode(unsigned int uiLeft, unsigned int uiTop, unsigned int uiRight, unsigned int uiBottom)
    : m_kRect(0, 0, 0, 0)
{
    m_spChild[0] = 0;
    m_spChild[1] = 0;
    m_spTexture = 0;
    m_kRect.m_left = uiLeft;
    m_kRect.m_top = uiTop;
    m_kRect.m_right = uiRight;
    m_kRect.m_bottom = uiBottom;
}

// Builds the merged vertex stream: checks that all meshes agree on the vertex layout, then copies every element, transforming
// positions/normals into the merged space and remapping bone indices (0x14104bbb0).
// @0x14104bbb0
void FUN_14104bbb0(NiMesh* pMerged, MergeInfo& kInfo, const MeshGroups& kBuckets, const NiTransform& kRootTransform)
{
    int iVertexTotal = 0;
    efd::vector<NiDataStreamRef*> kSources;
    CMM_FOR_EACH(const MeshList& kList, kBuckets)
    {
        CMM_FOR_EACH(NiMesh* pMesh, kList)
        {
            iVertexTotal += pMesh->GetVertexCount();
            NiDataStreamRef* pSource = FUN_14104cc20(pMesh);
            if (pSource == 0)
                pMesh->GetVertexCount();
            else
                kSources.push_back(pSource);
        }
    }

    std::vector<Unk_StreamElementDesc> kLayout;
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::POSITION(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::NORMAL(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BINORMAL(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::TANGENT(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::POSITION_BP(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::NORMAL_BP(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BINORMAL_BP(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::TANGENT_BP(), 0);
    for (unsigned int uiSet = 0; uiSet < 8; uiSet++)
        FUN_14104c870(kLayout, kSources, NiCommonSemantics::TEXCOORD(), uiSet);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BLENDWEIGHT(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BLENDINDICES(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BONEMATRICES(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BONE_PALETTE(), 0);

    NiDataStreamRef* pMergedRef = FUN_14104c9e0(kLayout, iVertexTotal);
    int iDstStride = pMergedRef->GetStride();
    int iVertexBase = 0;
    unsigned char* pDst = (unsigned char*)pMergedRef->GetDataStream()->Lock(10);
    for (unsigned int uiBucket = 0; uiBucket < kBuckets.size(); uiBucket++)
    {
        CMM_FOR_EACH(NiMesh* pMesh, kBuckets[uiBucket])
        {
            NiTransform kInverseParent;
            NiTransform kParentWorld = pMesh->GetParent()->GetWorldTransform();
            kParentWorld.Invert(kInverseParent);
            NiTransform kLocalToRoot = pMesh->GetLocalTransform() * kRootTransform;
            NiTransform kXform = kLocalToRoot * kInverseParent;

            NiDataStreamRef* pSourceRef = FUN_14104cc20(pMesh);
            unsigned char* pSrc = (unsigned char*)pSourceRef->GetDataStream()->Lock(5);
            int iDstOffset = 0;
            int iSrcStride = pSourceRef->GetStride();
            for (std::vector<Unk_StreamElementDesc>::const_iterator it = kLayout.begin(), itEnd = kLayout.end(); it != itEnd; ++it)
            {
                const Unk_StreamElementDesc& kDesc = *it;
                const NiDataStreamElement& kElement = pSourceRef->FindElementDesc(kDesc.m_kSemantic, kDesc.m_uiIndex);
                size_t stSize = NiDataStreamElement::SizeOfFormat(kDesc.m_eFormat);
                if (kElement.IsEqual(NiDataStreamElement::ms_kInvalidElement))
                {
                    for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                        memset(pDst + (v + iVertexBase) * iDstStride + iDstOffset, 0, stSize);
                }
                else
                {
                    int iSrcOffset = kElement.GetOffset();
                    efd::map<unsigned char, unsigned char>& kMeshRemap = kInfo.m_kBoneRemap[pMesh];
                    efd::map<unsigned char, unsigned char>& kBucketRemap = kInfo.m_kBucketRemap[uiBucket];
                    if (kDesc.m_kSemantic == NiCommonSemantics::BLENDINDICES())
                    {
                        for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                        {
                            for (unsigned int c = 0; c < 4; c++)
                            {
                                unsigned char ucOld = pSrc[c + v * iSrcStride + iSrcOffset];
                                unsigned char ucMerged = kMeshRemap[ucOld];
                                unsigned char ucBucket = kBucketRemap[ucMerged];
                                pDst[c + (v + iVertexBase) * iDstStride + iDstOffset] = ucBucket;
                            }
                        }
                    }
                    else if (kDesc.m_kSemantic == NiCommonSemantics::POSITION_BP())
                    {
                        for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                        {
                            NiPoint3* pIn = (NiPoint3*)(pSrc + v * iSrcStride + iSrcOffset);
                            NiPoint3* pOut = (NiPoint3*)(pDst + (v + iVertexBase) * iDstStride + iDstOffset);
                            *pOut = kXform * *pIn;
                        }
                    }
                    else if (kDesc.m_kSemantic == NiCommonSemantics::NORMAL_BP())
                    {
                        for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                        {
                            NiPoint3* pIn = (NiPoint3*)(pSrc + v * iSrcStride + iSrcOffset);
                            NiPoint3* pOut = (NiPoint3*)(pDst + (v + iVertexBase) * iDstStride + iDstOffset);
                            *pOut = kXform.m_Rotate * *pIn;
                        }
                    }
                    else
                    {
                        for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                            NiMemcpy(pDst + (v + iVertexBase) * iDstStride + iDstOffset, pSrc + v * iSrcStride + iSrcOffset, stSize);
                    }
                }
                iDstOffset += (int)NiDataStreamElement::SizeOfFormat(kDesc.m_eFormat);
            }
            pSourceRef->GetDataStream()->Unlock(5);
            iVertexBase += pMesh->GetVertexCount();
        }
    }
    pMergedRef->GetDataStream()->Unlock(10);

    pMergedRef->SetSubmeshCount((unsigned int)kBuckets.size(), 0);
    int iStart = 0;
    for (unsigned int i = 0; i < kBuckets.size(); i++)
    {
        int iCount = 0;
        const MeshList& kList = kBuckets[i];
        for (unsigned int j = 0; j < kList.size(); j++)
            iCount += kList[j]->GetVertexCount();
        NiDataStream::Region kRegion(iStart, iCount);
        if (i == 0)
            pMergedRef->GetDataStream()->SetRegion(kRegion, 0);
        else
            pMergedRef->GetDataStream()->AddRegion(kRegion);
        iStart += iCount;
        pMergedRef->BindRegionToSubmesh(i, i);
    }
    pMerged->AddStreamRef(pMergedRef);
    // the exe releases its extra reference to the temporary ref afterwards
    NiDelete pMergedRef;
}


// Inserts the texture into the first free leaf it fits in, splitting the leaf along its larger leftover side (0x14104cdc0).
// @0x14104cdc0
CCharacterMeshMerger::TexNode* CCharacterMeshMerger::TexNode::Insert(NiTexture* pTexture)
{
    if (m_spChild[0] != 0)
    {
        TexNode* pResult = m_spChild[0]->Insert(pTexture);
        if (pResult == 0)
            pResult = m_spChild[1]->Insert(pTexture);
        return pResult;
    }
    if (m_spTexture != 0)
        return 0;
    if (pTexture->GetWidth() > m_kRect.GetWidth())
        return 0;
    if (pTexture->GetHeight() > m_kRect.GetHeight())
        return 0;
    if (m_kRect.GetWidth() == pTexture->GetWidth() && m_kRect.GetHeight() == pTexture->GetHeight())
    {
        m_spTexture = pTexture;
        return this;
    }
    if (m_kRect.GetHeight() - pTexture->GetHeight() < m_kRect.GetWidth() - pTexture->GetWidth())
    {
        m_spChild[0] = NiNew TexNode(m_kRect.m_left, m_kRect.m_top, m_kRect.m_left + pTexture->GetWidth(), m_kRect.m_bottom);
        m_spChild[1] = NiNew TexNode(m_kRect.m_left + pTexture->GetWidth(), m_kRect.m_top, m_kRect.m_right, m_kRect.m_bottom);
    }
    else
    {
        m_spChild[0] = NiNew TexNode(m_kRect.m_left, m_kRect.m_top, m_kRect.m_right, m_kRect.m_top + pTexture->GetHeight());
        m_spChild[1] = NiNew TexNode(m_kRect.m_left, m_kRect.m_top + pTexture->GetHeight(), m_kRect.m_right, m_kRect.m_bottom);
    }
    return m_spChild[0]->Insert(pTexture);
}


// Same property state on both sides: every optional property is either absent from both or equal (0x141052aa0). Texturing is
// compared separately by the callers.
// @0x141052aa0
bool FUN_141052aa0(const NiPropertyState* pA, const NiPropertyState* pB)
{
    NiAlphaProperty* pAlphaA = pA->GetAlpha();
    if (pAlphaA == 0)
    {
        if (pB->GetAlpha() != 0)
            return false;
    }
    else
    {
        if (pB->GetAlpha() == 0)
            return false;
        if (!pAlphaA->IsEqualFast(*pB->GetAlpha()))
            return false;
    }
    NiDitherProperty* pDitherA = pA->GetDither();
    if (pDitherA == 0)
    {
        if (pB->GetDither() != 0)
            return false;
    }
    else
    {
        if (pB->GetDither() == 0)
            return false;
        if (!pDitherA->IsEqualFast(*pB->GetDither()))
            return false;
    }
    NiFogProperty* pFogA = pA->GetFog();
    if (pFogA == 0)
    {
        if (pB->GetFog() != 0)
            return false;
    }
    else
    {
        if (pB->GetFog() == 0)
            return false;
        if (!pFogA->IsEqualFast(*pB->GetFog()))
            return false;
    }
    NiMaterialProperty* pMaterialA = pA->GetMaterial();
    if (pMaterialA == 0)
    {
        if (pB->GetMaterial() != 0)
            return false;
    }
    else
    {
        if (pB->GetMaterial() == 0)
            return false;
        if (!pMaterialA->IsEqualFast(*pB->GetMaterial()))
            return false;
    }
    NiShadeProperty* pShadeA = pA->GetShade();
    if (pShadeA == 0)
    {
        if (pB->GetShade() != 0)
            return false;
    }
    else
    {
        if (pB->GetShade() == 0)
            return false;
        if (!pShadeA->IsEqualFast(*pB->GetShade()))
            return false;
    }
    NiSpecularProperty* pSpecularA = pA->GetSpecular();
    if (pSpecularA == 0)
    {
        if (pB->GetSpecular() != 0)
            return false;
    }
    else
    {
        if (pB->GetSpecular() == 0)
            return false;
        if (!pSpecularA->IsEqualFast(*pB->GetSpecular()))
            return false;
    }
    NiStencilProperty* pStencilA = pA->GetStencil();
    if (pStencilA == 0)
    {
        if (pB->GetStencil() != 0)
            return false;
    }
    else
    {
        if (pB->GetStencil() == 0)
            return false;
        if (!pStencilA->IsEqualFast(*pB->GetStencil()))
            return false;
    }
    NiVertexColorProperty* pVertexColorA = pA->GetVertexColor();
    if (pVertexColorA == 0)
    {
        if (pB->GetVertexColor() != 0)
            return false;
    }
    else
    {
        if (pB->GetVertexColor() == 0)
            return false;
        if (!pVertexColorA->IsEqualFast(*pB->GetVertexColor()))
            return false;
    }
    NiWireframeProperty* pWireframeA = pA->GetWireframe();
    if (pWireframeA == 0)
    {
        if (pB->GetWireframe() != 0)
            return false;
    }
    else
    {
        if (pB->GetWireframe() == 0)
            return false;
        if (!pWireframeA->IsEqualFast(*pB->GetWireframe()))
            return false;
    }
    NiZBufferProperty* pZBufferA = pA->GetZBuffer();
    if (pZBufferA == 0)
    {
        if (pB->GetZBuffer() != 0)
            return false;
    }
    else
    {
        if (pB->GetZBuffer() == 0)
            return false;
        if (!pZBufferA->IsEqualFast(*pB->GetZBuffer()))
            return false;
    }
    return true;
}

// Distributes the meshes into groups of equal property state (0x1410528f0).
// @0x1410528f0
void FUN_1410528f0(const MeshList& kMeshes, MeshGroups& kGroups)
{
    kGroups.clear();
    CMM_FOR_EACH(NiMesh* pMesh, kMeshes)
    {
        unsigned int uiGroup;
        for (uiGroup = 0; uiGroup < kGroups.size(); uiGroup++)
        {
            NiMesh* pFirst = kGroups[uiGroup][0];
            if (FUN_141052aa0(pMesh->GetPropertyState(), pFirst->GetPropertyState()) == true)
                break;
        }
        if (uiGroup == kGroups.size())
            kGroups.push_back(MeshList());
        kGroups[uiGroup].push_back(pMesh);
    }
}


// Collects the mergeable meshes of the character per world transform, then per property state (0x14104d450).
// @0x14104d450
void FUN_14104d450(NiAVObject* pRoot, MeshGroups& kGroups)
{
    efd::map<NiTransform, MeshList, Unk_TransformLess> kByTransform;
    Unk_CubeSceneIterator kIter(pRoot);
    while (NiAVObject* pObject = kIter.FUN_14098e0d0(false))
    {
        if (FUN_14098dad0(pObject))
            continue;
        if (pObject->GetName() == "Bip01")
            continue;
        if (NiDynamicCast(NiNode, pObject) != 0)
        {
            kIter.FUN_14098d6d0((NiNode*)pObject);
            continue;
        }
        if (FUN_14098dfc0(pObject))
            continue;
        NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pObject->GetProperty(8));
        if (pTexturing == 0 || pTexturing->GetBaseTexture() == 0)
            continue;
        NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
        if (pMesh == 0 || pObject->GetProperty(0) != 0)
            continue;
        if (NiDynamicCast(NiMorphMeshModifier, pMesh->GetModifierByType(&NiMorphMeshModifier::ms_RTTI)) != 0)
            continue;
        NiSkinningMeshModifier* pSkin = NiDynamicCast(NiSkinningMeshModifier, pMesh->GetModifierByType(&NiSkinningMeshModifier::ms_RTTI));
        if (pSkin == 0 || pSkin->GetSoftwareSkinned())
            continue;

        bool bHasVertexColor = false;
        unsigned int uiStreams = pMesh->GetStreamRefCount();
        for (unsigned int i = 0; i < uiStreams; i++)
        {
            NiDataStreamRef* pRef = pMesh->GetStreamRefAt(i);
            if (pRef->GetUsage() == NiDataStream::USAGE_VERTEX)
            {
                if (pRef->FindElementDescIndex(NiCommonSemantics::COLOR(), 0) != 0xffffffff)
                {
                    EE_LOG_AT(1, 1, ("Mesh %s can't be merged : contains vertex color data", (const char*)pMesh->GetName()), MS2_THIS_FILE, 0x11c);
                    bHasVertexColor = true;
                    break;
                }
            }
        }
        if (bHasVertexColor)
            continue;

        const NiFixedString& kName = pMesh->GetName();
        if (kName.Contains("FA") && kName != "FA_EA")
            continue;

        Unk_MaterialEntry* pEntry = FUN_140a17af0(&DAT_143d69198, FUN_140a17cd0(pMesh));
        if (pEntry != 0 && FUN_140ef4dd0(pEntry) == 2)
        {
            NiMaterialProperty* pMaterial = NiDynamicCast(NiMaterialProperty, pMesh->GetProperty(3));
            const NiColor& kAmbient = pMaterial->GetAmbientColor();
            const NiColor& kDiffuse = pMaterial->GetDiffuseColor();
            if (FUN_140a56f50(&kAmbient, &kDiffuse))
                EE_LOG_AT(1, 1, ("Mesh %s's material ambient and diffuse are not equal!", (const char*)pMesh->GetName()), MS2_THIS_FILE, 0x155);
            if (kAmbient.g != kAmbient.r || kAmbient.b != kAmbient.r || kDiffuse.g != kDiffuse.r || kDiffuse.b != kDiffuse.r)
                EE_LOG_AT(1, 1, ("Mesh %s's material color is not grayscale color!", (const char*)pMesh->GetName()), MS2_THIS_FILE, 0x159);

            efd::map<NiTransform, MeshList, Unk_TransformLess>::iterator it = kByTransform.find(pMesh->GetWorldTransform());
            if (it == kByTransform.end())
                it = kByTransform.insert(std::make_pair(pMesh->GetWorldTransform(), MeshList())).first;
            it->second.push_back(pMesh);
        }
    }

    for (efd::map<NiTransform, MeshList, Unk_TransformLess>::iterator it = kByTransform.begin(); it != kByTransform.end(); ++it)
    {
        MeshGroups kSplit;
        FUN_1410528f0(it->second, kSplit);
        for (MeshList& kList : kSplit)
        {
            if (kList.size() > 1)
                kGroups.push_back(kList);
        }
    }
}


// Packs the base textures of the meshes into square atlases of uiAtlasSize pixels; every full atlas becomes one group of meshes
// plus its texturing property (0x14104ddc0).
// @0x14104ddc0
void FUN_14104ddc0(efd::vector<NiAVObject*>& kMeshes, MeshGroupVector& kOutGroups, efd::vector<Unk_AtlasResult>& kOutResults, unsigned int uiAtlasSize)
{
    std::sort(kMeshes.begin(), kMeshes.end(), FUN_141052ff0);
    efd::SmartPointer<CCharacterMeshMerger::TexNode> spRoot = NiNew CCharacterMeshMerger::TexNode(0, 0, uiAtlasSize, uiAtlasSize);
    efd::SmartPointer<NiPixelData> spAlbedo = NiNew NiPixelData(uiAtlasSize, uiAtlasSize, DAT_1439fb040, 1, 1);
    efd::SmartPointer<NiPixelData> spShader = NiNew NiPixelData(uiAtlasSize, uiAtlasSize, DAT_1439fb040, 1, 1);
    unsigned int uiMinCell = uiAtlasSize;
    MeshList kGroup;
    Unk_AtlasResult kResult;
    efd::map<CString, CCharacterMeshMerger::TexNode*> kCache;
    for (unsigned int i = 0; i < kMeshes.size(); i++)
    {
        NiMesh* pMesh = (NiMesh*)kMeshes[i];
        CCharacterMeshMerger::TexNode* pNode = 0;
        efd::SmartPointer<NiSourceTexture> spTexture;
        CString strKey = FUN_1410521a0(pMesh);
        efd::map<CString, CCharacterMeshMerger::TexNode*>::iterator itCached = kCache.find(strKey);
        if (itCached == kCache.end())
        {
            spTexture = FUN_141051560(pMesh);
            pNode = spRoot->Insert(spTexture);
            if (pNode == 0)
            {
                FUN_141050920(&kResult, spAlbedo, spShader);
                kOutGroups.push_back(kGroup);
                kOutResults.push_back(kResult);
                kGroup.clear();
                kResult.Clear();
                spRoot = NiNew CCharacterMeshMerger::TexNode(0, 0, uiAtlasSize, uiAtlasSize);
                spAlbedo = NiNew NiPixelData(uiAtlasSize, uiAtlasSize, DAT_1439fb040, 1, 1);
                spShader = NiNew NiPixelData(uiAtlasSize, uiAtlasSize, DAT_1439fb040, 1, 1);
                uiMinCell = uiAtlasSize;
                pNode = spRoot->Insert(spTexture);
            }
            if (strKey != "")
                kCache.insert(std::make_pair(strKey, pNode));
            NiMaterialProperty* pMaterial = NiDynamicCast(NiMaterialProperty, pMesh->GetProperty(3));
            float fAlpha = pMaterial->GetDiffuseColor().r / s_kAtlasDivisor.r;
            BlitTexturePixels(spTexture, spAlbedo, pNode->m_kRect, fAlpha);
        }
        else
        {
            pNode = itCached->second;
            spTexture = (NiSourceTexture*)(NiTexture*)pNode->m_spTexture;
        }
        if (pNode->m_kRect.GetWidth() < uiMinCell)
            uiMinCell = pNode->m_kRect.GetWidth();
        if (pNode->m_kRect.GetHeight() < uiMinCell)
            uiMinCell = pNode->m_kRect.GetHeight();
        kGroup.push_back(pMesh);
        Unk_UVRect kPlacement;
        FUN_141050880(uiAtlasSize, spTexture->GetWidth(), spTexture->GetHeight(), pNode->m_kRect.m_left, pNode->m_kRect.m_top,
                      &kPlacement.m_kOffset, &kPlacement.m_kScale);
        kResult.m_kPlacement.insert(std::make_pair(pMesh, kPlacement));
        FUN_141051f90(pMesh, spShader, pNode->m_kRect);
    }
    FUN_141050920(&kResult, spAlbedo, spShader);
    kOutGroups.push_back(kGroup);
    kOutResults.push_back(kResult);
}


// UV offset and scale of a rectangle inside the atlas (0x141050880).
// @0x141050880
void FUN_141050880(unsigned int uiAtlasSize, unsigned int uiWidth, unsigned int uiHeight, unsigned int uiLeft, unsigned int uiTop, NiPoint2* pOffset, NiPoint2* pScale)
{
    pOffset->x = (float)uiLeft / (float)uiAtlasSize;
    pOffset->y = (float)uiTop / (float)uiAtlasSize;
    pScale->x = (float)uiWidth / (float)uiAtlasSize;
    pScale->y = (float)uiHeight / (float)uiAtlasSize;
}

// Shrinks a finished atlas to the used area, rescales the placements and builds the group's texturing property (0x141050920).
// @0x141050920
void FUN_141050920(Unk_AtlasResult* pResult, NiPixelData* pAlbedo, NiPixelData* pShader)
{
    unsigned int uiWidth = pAlbedo->GetWidth(0, 0);
    unsigned int uiHeight = pAlbedo->GetHeight(0, 0);
    unsigned int uiUsedWidth = 0;
    unsigned int uiUsedHeight = 0;
    unsigned int uiMinCell = 0xffffffff;
    for (efd::map<NiMesh*, Unk_UVRect>::iterator it = pResult->m_kPlacement.begin(); it != pResult->m_kPlacement.end(); ++it)
    {
        const Unk_UVRect& kRect = it->second;
        int iLeft = (int)(kRect.m_kOffset.x * (float)uiWidth + 0.001);
        int iTop = (int)(kRect.m_kOffset.y * (float)uiHeight + 0.001);
        unsigned int uiRectWidth = (unsigned int)(kRect.m_kScale.x * (float)uiWidth + 0.001);
        unsigned int uiRectHeight = (unsigned int)(kRect.m_kScale.y * (float)uiHeight + 0.001);
        if (uiUsedWidth < iLeft + uiRectWidth)
            uiUsedWidth = iLeft + uiRectWidth;
        if (uiUsedHeight < iTop + uiRectHeight)
            uiUsedHeight = iTop + uiRectHeight;
        if (uiRectWidth < uiMinCell)
            uiMinCell = uiRectWidth;
        if (uiRectHeight < uiMinCell)
            uiMinCell = uiRectHeight;
    }
    efd::SmartPointer<NiPixelData> spShader = DownsamplePixels(pShader, uiMinCell);
    unsigned int uiShrinkU = 1;
    unsigned int uiShrinkV = 1;
    for (; uiUsedWidth <= uiWidth / 2; uiWidth = uiWidth / 2)
        uiShrinkU = uiShrinkU << 1;
    for (; uiUsedHeight <= uiHeight / 2; uiHeight = uiHeight / 2)
        uiShrinkV = uiShrinkV << 1;
    for (efd::map<NiMesh*, Unk_UVRect>::iterator it = pResult->m_kPlacement.begin(); it != pResult->m_kPlacement.end(); ++it)
    {
        Unk_UVRect& kRect = it->second;
        kRect.m_kScale.x = kRect.m_kScale.x * (float)uiShrinkU;
        kRect.m_kScale.y = kRect.m_kScale.y * (float)uiShrinkV;
        kRect.m_kOffset.x = kRect.m_kOffset.x * (float)uiShrinkU;
        kRect.m_kOffset.y = kRect.m_kOffset.y * (float)uiShrinkV;
    }

    efd::SmartPointer<NiPixelData> spAtlas = NiNew NiPixelData(uiWidth, uiHeight, DAT_1439fb040, 1, 1);
    NiRect<unsigned int> kAtlasRect(0, uiWidth, 0, uiHeight);
    CopyPixelRect(pAlbedo, kAtlasRect, spAtlas, kAtlasRect);

    unsigned int uiShaderHeight = spShader->GetHeight(0, 0) / uiShrinkV;
    efd::SmartPointer<NiPixelData> spShaderAtlas = NiNew NiPixelData(spShader->GetWidth(0, 0) / uiShrinkU, uiShaderHeight, DAT_1439fb040, 1, 1);
    unsigned int uiShaderHeight2 = spShaderAtlas->GetHeight(0, 0);
    NiRect<unsigned int> kShaderRect(0, spShaderAtlas->GetWidth(0, 0), 0, uiShaderHeight2);
    CopyPixelRect(spShader, kShaderRect, spShaderAtlas, kShaderRect);
    pResult->m_spTexturing = FUN_141050fd0(spAtlas, spShaderAtlas);
}

// Creates the texturing property of the atlas (base texture plus shader map) and dumps both textures to disk (0x141050fd0).
#ifndef MS2_HOOK_DLL
// @0x141050fd0
NiTexturingProperty* FUN_141050fd0(NiPixelData* pAlbedo, NiPixelData* pShader)
{
    NiTexturingProperty* pTexturing = NiNew NiTexturingProperty(pAlbedo);
    pTexturing->SetBaseFilterMode(NiTexturingProperty::FILTER_BILERP_MIPNEAREST);
    efd::SmartPointer<NiSourceTexture> spShaderTexture = NiSourceTexture::Create(pShader, DAT_1439fc800, true);
    NiTexturingProperty::ShaderMap* pShaderMap = NiNew NiTexturingProperty::ShaderMap(spShaderTexture, 0, NiTexturingProperty::WRAP_S_WRAP_T, NiTexturingProperty::FILTER_NEAREST, 0);
    pTexturing->SetShaderMap(0, pShaderMap);
    NiSourceTexture* pBase = NiDynamicCast(NiSourceTexture, pTexturing->GetBaseTexture());
    CString strPath;
    strPath.Format("CharacterAtlas%d.dds", s_iAtlasFileCount);
    SaveTextureToFileA(&strPath, D3DXIFF_PNG, pBase);        // the exe passes 3 (PNG) despite the .dds names
    strPath.Format("CharacterAtlasShaderMap%d.dds", s_iAtlasFileCount);
    SaveTextureToFileA(&strPath, D3DXIFF_PNG, spShaderTexture);
    s_iAtlasFileCount++;
    return pTexturing;
}
#endif


// Same layout as the stream ref but with its own stream of uiCount elements (0x141051210).
// @0x141051210
NiDataStreamRef* FUN_141051210(NiDataStreamRef* pRef, unsigned int uiCount)
{
    NiDataStreamElementSet kElements;
    for (unsigned int i = 0; i < pRef->GetDataStream()->GetElementDescCount(); i++)
        kElements.Add(pRef->GetElementDescAt(i));
    unsigned int uiStride = pRef->GetStride();
    NiDataStream* pStream = NiDataStream::CreateDataStream(kElements, uiCount, pRef->GetAccessMask(), pRef->GetUsage(), false);
    NiDataStream::Region kRegion(0, uiCount);
    pStream->AddRegion(kRegion);
    NiDataStreamRef* pCopy = NiNew NiDataStreamRef(*pRef);
    pCopy->SetDataStream(pStream);
    return pCopy;
}

// The two stream refs have the same per-instance flag and the same semantics (0x1410513b0).
// @0x1410513b0
bool FUN_1410513b0(NiDataStreamRef* pA, NiDataStreamRef* pB)
{
    if (pA == 0)
        return pB == 0;
    if (pB == 0)
        return false;
    if (pA->IsPerInstance() != pB->IsPerInstance())
        return false;
    if (pA->GetDataStream() != 0 && pB->GetDataStream() != 0)
    {
        if (pA->GetDataStream()->GetElementDescCount() != pB->GetDataStream()->GetElementDescCount())
            return false;
        unsigned int uiCount = pA->GetDataStream()->GetElementDescCount();
        for (unsigned int i = 0; i < uiCount; i++)
        {
            if (pA->GetSemanticNameAt(i) != pB->GetSemanticNameAt(i))
                return false;
            if (pA->GetSemanticIndexAt(i) != pB->GetSemanticIndexAt(i))
                return false;
        }
    }
    else if (pA->GetDataStream() == 0 && pB->GetDataStream() == 0)
    {
    }
    else
        return false;
    return true;
}


// The base texture of the mesh, or the composited customised texture when the texturing property has shader maps (0x141051560).
// @0x141051560
efd::SmartPointer<NiSourceTexture> FUN_141051560(NiAVObject* pMesh)
{
    efd::SmartPointer<NiSourceTexture> spResult;
    NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(8));
    if (pTexturing == 0)
        return spResult;
    if (pTexturing->GetShaderMapCount() == 0)
    {
        spResult = NiDynamicCast(NiSourceTexture, pTexturing->GetBaseTexture());
        return spResult;
    }

    efd::SmartPointer<CCustomizedTexInfo> spInfoA = NiNew CCustomizedTexInfo;
    spInfoA->m_spBase = pTexturing->GetBaseTexture();
    if (pTexturing->GetShaderMap(0) != 0)
    {
        spInfoA->m_spDecal = pTexturing->GetShaderMap(0)->GetTexture();
        NiColorExtraData* pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae50c8));
        spInfoA->m_kColor0 = pColor == 0 ? NiColorA(1.0f, 1.0f, 1.0f, 1.0f) : pColor->GetValue();
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae50d0));
        spInfoA->m_kColor1 = pColor == 0 ? NiColorA(1.0f, 1.0f, 1.0f, 1.0f) : pColor->GetValue();
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae50d8));
        spInfoA->m_kColor2 = pColor == 0 ? NiColorA(1.0f, 1.0f, 1.0f, 1.0f) : pColor->GetValue();
    }

    efd::SmartPointer<CCustomizedTexInfo> spInfoB = NiNew CCustomizedTexInfo;
    NiTexture* pTextureB = pTexturing->GetShaderMap(1) == 0 ? 0 : pTexturing->GetShaderMap(1)->GetTexture();
    NiTexture* pTextureC = pTexturing->GetShaderMap(2) == 0 ? 0 : pTexturing->GetShaderMap(2)->GetTexture();
    spInfoB->m_spBase = pTextureB;
    NiFloatsExtraData* pParams = NiDynamicCast(NiFloatsExtraData, pMesh->GetExtraData(DAT_143ae50f8));
    if (pParams != 0)
    {
        spInfoB->m_afParams[0] = pParams->GetValue(0);
        spInfoB->m_afParams[1] = pParams->GetValue(1);
        spInfoB->m_afParams[2] = pParams->GetValue(2);
        spInfoB->m_afParams[3] = pParams->GetValue(3);
    }
    if (pTextureC != 0)
    {
        spInfoB->m_spDecal = pTextureC;
        NiColorExtraData* pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae5100));
        spInfoB->m_kColor0 = pColor == 0 ? NiColorA(1.0f, 1.0f, 1.0f, 1.0f) : pColor->GetValue();
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae5108));
        spInfoB->m_kColor1 = pColor == 0 ? NiColorA(1.0f, 1.0f, 1.0f, 1.0f) : pColor->GetValue();
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae5110));
        spInfoB->m_kColor2 = pColor == 0 ? NiColorA(1.0f, 1.0f, 1.0f, 1.0f) : pColor->GetValue();
    }

    if (CCustomizedTextureManager::GetInstance() == 0)
        CCustomizedTextureManager::CreateInstance();
    efd::SmartPointer<CCustomizedTexInfo> spComposed = FUN_1411660b0(CCustomizedTextureManager::GetInstance(), spInfoA, spInfoB);
    spResult = NiDynamicCast(NiSourceTexture, (NiTexture*)spComposed->m_spBase);
    return spResult;
}

// Fills the mesh's cell of the shader map: material flag, two extra-data parameters and whether a decal map exists (0x141051f90).
// @0x141051f90
void FUN_141051f90(NiAVObject* pMesh, NiPixelData* pShaderMap, const NiRect<unsigned int>& kRect)
{
    float fParam0 = 5.0f;
    float fParam1 = 4.0f;
    bool bDecal = false;
    NiFloatExtraData* pData = NiDynamicCast(NiFloatExtraData, pMesh->GetExtraData(DAT_143ae5148));
    if (pData != 0)
        fParam0 = pData->GetValue();
    pData = NiDynamicCast(NiFloatExtraData, pMesh->GetExtraData(DAT_143ae5150));
    if (pData != 0)
        fParam1 = pData->GetValue();
    bool bMaterial = FUN_140a17cd0((NiMesh*)pMesh)->GetName() == DAT_143ae5200;
    NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(8));
    if (pTexturing != 0 && pTexturing->GetShaderMap(0) != 0)
        bDecal = true;
    int iRed = bMaterial ? 0xff : 0;
    int iAlpha = bDecal ? 0xff : 0;
    unsigned int uiColor = iAlpha << 24 | iRed << 16 | ((int)((fParam1 / 10.0) * 255.0) & 0xffU) << 8 | (int)((fParam0 / 10.0) * 255.0) & 0xffU;
    FillPixelRect((const unsigned char*)&uiColor, pShaderMap, kRect);
}


// Cache key of the mesh's customised texture: base file, decal file and the three decal colours (0x1410521a0).
// @0x1410521a0
CString FUN_1410521a0(NiAVObject* pMesh)
{
    CString strKey;
    NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(8));
    if (pTexturing != 0)
    {
        NiSourceTexture* pBase = NiDynamicCast(NiSourceTexture, pTexturing->GetBaseTexture());
        if (pBase != 0)
        {
            NiFixedString kBaseFile = pBase == 0 ? NiFixedString("") : pBase->GetFilename();
            CString strBase;
            strBase.Format("%s;", (const char*)kBaseFile);
            strKey += Unk_Lower(strBase);
            NiSourceTexture* pDecal = pTexturing->GetShaderMap(0) == 0 ? 0 : NiDynamicCast(NiSourceTexture, pTexturing->GetShaderMap(0)->GetTexture());
            if (pDecal != 0)
            {
                NiFixedString kDecalFile = pDecal == 0 ? NiFixedString("") : pDecal->GetFilename();
                CString astrColors[3];
                astrColors[0] = FUN_140db9aa0(NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae50c8))->GetValue());
                astrColors[1] = FUN_140db9aa0(NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae50d0))->GetValue());
                astrColors[2] = FUN_140db9aa0(NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae50d8))->GetValue());
                CString strDecal;
                strDecal.Format("%s;%s;%s;%s", (const char*)kDecalFile, (const char*)astrColors[0], (const char*)astrColors[1], (const char*)astrColors[2]);
                strKey += Unk_Lower(strDecal);
            }
        }
    }
    return strKey;
}

// Texture ordering of the atlas packer: larger textures (long side, then short side) first (0x141052ff0).
// @0x141052ff0
bool FUN_141052ff0(NiAVObject* pA, NiAVObject* pB)
{
    NiTexturingProperty* pTexturingA = NiDynamicCast(NiTexturingProperty, pA->GetProperty(8));
    NiTexturingProperty* pTexturingB = NiDynamicCast(NiTexturingProperty, pB->GetProperty(8));
    NiTexture* pBaseA = pTexturingA->GetBaseTexture();
    NiTexture* pBaseB = pTexturingB->GetBaseTexture();
    unsigned int uiShortA;
    unsigned int uiLongA;
    unsigned int uiShortB;
    unsigned int uiLongB;
    Unk_SortPair(pBaseA->GetWidth(), pBaseA->GetHeight(), &uiShortA, &uiLongA);
    Unk_SortPair(pBaseB->GetWidth(), pBaseB->GetHeight(), &uiShortB, &uiLongB);
    if (pTexturingA->GetShaderMap(0) != 0)
    {
        NiTexture* pDecal = pTexturingA->GetShaderMap(0)->GetTexture();
        if (!(pDecal->GetWidth() <= uiLongA && pDecal->GetHeight() <= uiLongA))
            Unk_SortPair(pDecal->GetWidth(), pDecal->GetHeight(), &uiShortA, &uiLongA);
    }
    if (pTexturingB->GetShaderMap(0) != 0)
    {
        NiTexture* pDecal = pTexturingB->GetShaderMap(0)->GetTexture();
        if (!(pDecal->GetWidth() <= uiLongB && pDecal->GetHeight() <= uiLongB))
            Unk_SortPair(pDecal->GetWidth(), pDecal->GetHeight(), &uiShortB, &uiLongB);
    }
    if (uiLongB < uiLongA)
        return true;
    if (uiLongA == uiLongB && uiShortB < uiShortA)
        return true;
    return false;
}

// Orders by scale, then translation, then rotation (0x14106a3b0).
bool Unk_TransformLess::operator()(const NiTransform& kA, const NiTransform& kB) const
{
    if (kA.m_fScale < kB.m_fScale)
        return true;
    else if (kA.m_fScale > kB.m_fScale)
        return false;
    for (unsigned int i = 0; i < 3; i++)
    {
        if (kA.m_Translate[i] < kB.m_Translate[i])
            return true;
        else if (kA.m_Translate[i] > kB.m_Translate[i])
            return false;
    }
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (kA.m_Rotate.GetEntry(i, j) < kB.m_Rotate.GetEntry(i, j))
                return true;
            // the exe returns true here too (not false), so rotations only order on the first differing entry
            if (kA.m_Rotate.GetEntry(i, j) > kB.m_Rotate.GetEntry(i, j))
                return true;
        }
    }
    return false;
}

// Builds the merged mesh of one group: concatenated indices and vertices, one submesh per bone bucket (0x14104f460, the twin of 0x14104ae20 with the index and vertex merge expanded in place).
// @0x14104f460
// MS2-FUNCTIONAL: the exe expands the index/vertex merge helpers in place; this twin calls them
NiMesh* FUN_14104f460(const MeshGroups& kBuckets, MergeInfo& kInfo, NiAVObject* pRoot)
{
    unsigned int uiBucketCount = (unsigned int)kBuckets.size();
    int iVertices = 0;
    int iIndices = 0;
    FUN_14104a080(kBuckets, &iVertices, &iIndices);
    if (iVertices == 0)
        return 0;

    NiMesh* pMerged = NiNew NiMesh;
    NiMesh* pFirst = kBuckets[0][0];
    NiTransform kRootTransform = pRoot->GetWorldTransform();
    pMerged->SetPrimitiveType(pFirst->GetPrimitiveType());
    pMerged->SetSubmeshCount((unsigned int)kBuckets.size());
    FUN_14104b530(pMerged, kBuckets);
    FUN_14104bbb0(pMerged, kInfo, kBuckets, kRootTransform);

    if (kInfo.m_spSkin != 0)
    {
        unsigned int uiMaxBones = 0;
        unsigned int uiTotalBones = 0;
        for (unsigned int i = 0; i < uiBucketCount; i++)
        {
            unsigned int uiBones = (unsigned int)kInfo.m_kBoneLists[i].size();
            if (uiMaxBones < uiBones)
                uiMaxBones = uiBones;
            uiTotalBones += uiBones;
        }
        unsigned short* pPalette = (unsigned short*)_malloca(uiMaxBones * uiBucketCount * sizeof(unsigned short));
        unsigned short* pOut = pPalette;
        for (unsigned int i = 0; i < uiBucketCount; i++)
        {
            const efd::vector<unsigned char>& kList = kInfo.m_kBoneLists[i];
            for (unsigned int j = 0; j < kList.size(); j++)
                *pOut++ = kList[j];
            for (unsigned int j = (unsigned int)kList.size(); j < uiMaxBones; j++)
                *pOut++ = 0;
        }
        int iPaletteCount = uiMaxBones * uiBucketCount;
        NiDataStreamRef* pRef = pMerged->AddStream(NiCommonSemantics::BONE_PALETTE(), 0, NiDataStreamElement::F_UINT16_1, iPaletteCount,
                                                   3, NiDataStream::USAGE_USER, pPalette, false, true);
        _freea(pPalette);
        pRef->SetSubmeshCount(uiBucketCount, 0);
        for (unsigned int i = 0; i < uiBucketCount; i++)
        {
            NiDataStream::Region kRegion(i * uiMaxBones, uiMaxBones);
            if (i == 0)
                pRef->GetDataStream()->SetRegion(kRegion, 0);
            else
                pRef->GetDataStream()->AddRegion(kRegion);
            pRef->BindRegionToSubmesh(i, i);
        }
    }

    NiBound kBound = pFirst->GetModelBound();
    for (unsigned int i = 0; i < kBuckets.size(); i++)
    {
        const MeshList& kList = kBuckets[i];
        for (unsigned int j = 0; j < kList.size(); j++)
            kBound.Merge(&kList[j]->GetModelBound());
    }
    pMerged->SetModelBound(kBound);
    pMerged->AddModifier(kInfo.m_spSkin, true);
    pMerged->AttachProperty(pFirst->GetProperty(8));
    pMerged->SetName(NiFixedString("MergedMesh"));
    for (unsigned int i = 0; i < 12; i++)
    {
        if (i != 8)
        {
            NiProperty* pProperty = pFirst->GetProperty(i);
            if (pProperty != 0)
                pMerged->AttachProperty(pProperty);
        }
    }
    pMerged->ApplyAndSetActiveMaterial(FUN_140a17cd0(pFirst), 0xffffffff);
    unsigned short usExtra = pFirst->GetExtraDataSize();
    for (unsigned short us = 0; us < usExtra; us++)
        pMerged->AddExtraData(pFirst->GetExtraDataAt(us));
    pMerged->SetEffectState(pFirst->GetEffectState());
    pMerged->UpdateProperties();
    pMerged->CompleteUpdateModifiers();
    pMerged->UpdateEffects();
    pMerged->Update(0.0, true);
    return pMerged;
}

// The containers of the unit are instantiated as a whole in the exe (every member of each is present in the unit's template tail).
template class std::vector<unsigned char, efd::CustomAllocator<unsigned char> >;
template class std::vector<efd::vector<unsigned char>, efd::CustomAllocator<efd::vector<unsigned char> > >;
template class std::vector<efd::set<unsigned char>, efd::CustomAllocator<efd::set<unsigned char> > >;
template class std::vector<efd::set<NiAVObject*>, efd::CustomAllocator<efd::set<NiAVObject*> > >;
template class std::vector<efd::map<unsigned char, unsigned char>, efd::CustomAllocator<efd::map<unsigned char, unsigned char> > >;
template class std::vector<NiAVObject*, efd::CustomAllocator<NiAVObject*> >;
template class std::vector<NiDataStreamRef*, efd::CustomAllocator<NiDataStreamRef*> >;
template class std::vector<Unk_AtlasResult, efd::CustomAllocator<Unk_AtlasResult> >;
template class std::set<unsigned char, std::less<unsigned char>, efd::CustomAllocator<unsigned char> >;
template class std::set<NiAVObject*, std::less<NiAVObject*>, efd::CustomAllocator<NiAVObject*> >;
template class std::map<unsigned char, unsigned char, std::less<unsigned char>, efd::CustomAllocator<std::pair<const unsigned char, unsigned char> > >;
template class std::map<NiMesh*, efd::map<unsigned char, unsigned char>, std::less<NiMesh*>, efd::CustomAllocator<std::pair<NiMesh* const, efd::map<unsigned char, unsigned char> > > >;
template class std::map<NiMesh*, Unk_UVRect, std::less<NiMesh*>, efd::CustomAllocator<std::pair<NiMesh* const, Unk_UVRect> > >;
template class std::map<CString, CCharacterMeshMerger::TexNode*, std::less<CString>, efd::CustomAllocator<std::pair<const CString, CCharacterMeshMerger::TexNode*> > >;
template class std::map<NiTransform, MeshList, Unk_TransformLess, efd::CustomAllocator<std::pair<const NiTransform, MeshList> > >;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cab980-0x142caba10 .text$yd
