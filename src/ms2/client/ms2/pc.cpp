// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The PC class (RTTI PC -> PCBase; vftables 0x142f4ae28 /
// 0x142f4b2c8). Layout: placeholder/fittingdollpc.h (members 0xd40..0x12e0 from the ctor 0x14164dfd0 / dtor 0x141650b10).
// The third-party v2525 snapshot (tu/14164deb0.cpp, PC.h) has bodies for many of the small members; names here are
// the FUN_<va> / vfunc_<slot> spellings of the shared header unless the exe names them.
// MS2-UNIT: unit_14164dfd0
// MS2-RANGE: 0x14164dfd0-0x14166a650 .text$mn
// MS2-RANGE: 0x1400fb010-0x1400fb4d0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1416642e0 ; unique
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x141665910 ; unique
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCBaseComp_a98@@@@QEAA@AEBV0@@Z 0x1416660b0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCSkillTierOptionManager@@@@QEAA@PEAVCSkillTierOptionManager@@@Z 0x1416661d0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCTailEffectObject@@@@QEAA@PEAVCTailEffectObject@@@Z 0x141666270 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@AEBV0@@Z 0x1416665b0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@IPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@1@@Z 0x141666670 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@IPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@1@@Z 0x1416666b0 ; unique
// MS2-PIN: ??1?$MS2Ptr@VCEquipItem@@@@QEAA@XZ 0x141666900 ; prop
// MS2-PIN: ??1?$MS2Ptr@VJobSystemCli@@@@QEAA@XZ 0x141666990 ; unique
// MS2-PIN: ??1?$MS2Ptr@VWaterGunBattleInfo@@@@QEAA@XZ 0x1416669c0 ; unique
// MS2-PIN: ??4?$MS2Ptr@VUnk_PCInteractMode@@@@QEAAAEAV0@H@Z 0x141666d90 ; unique
// MS2-PIN: ??4?$MS2Ptr@VUnk_PCBaseComp_a68@@@@QEAAAEAV0@AEBV0@@Z 0x1416670a0 ; prop
// MS2-PIN: ??_GUnk_PCCubeCraft@@QEAAPEAXI@Z 0x141667830 ; unique
// MS2-PIN: ?FindNextNode@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141667ac0 ; unique
// MS2-PIN: ?GetClassDesc@PC@@UEBAPEBVClassInfo@efd@@XZ 0x141667cd0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141667d00 ; unique
// MS2-PIN: ?GetKeyAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@PEAU__POSITION@@@Z 0x141667d20 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141667d80 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141667dd0 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141667f00 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VCTailEffectObject@@@@PEAU__POSITION@@@Z 0x141667fc0 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEAAAEAV?$SmartPointer@VNiAVObject@@@efd@@PEAU__POSITION@@@Z 0x141668030 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEBA_NXZ 0x141668370 ; prop
// MS2-PIN: ?IsNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@AEBA_NPEAVCNode@12@@Z 0x1416683d0 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141668480 ; unique
// MS2-PIN: ?Successor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141668ef0 ; unique
// MS2-PIN: ?TypeCast@PC@@UEBA_NIPEAPEAX@Z 0x141668fc0 ; unique
// MS2-PIN: ?TypeCast@PC@@UEBA_NIPEAPEBX@Z 0x141669010 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VRideOnAction@@@@AEBAXXZ 0x141669140 ; prop
// MS2-PIN: ?AddRef@?$MS2Ptr@VCSkillTierOptionManager@@@@AEBAXXZ 0x141669170 ; prop
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_PCBaseComp_a68@@@@AEBAXXZ 0x1416691d0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VRideOnAction@@@@AEBAXPEAX@Z 0x1416693f0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCSkillTierOptionManager@@@@AEBAXPEAX@Z 0x141669420 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCTailEffectObject@@@@AEBAXPEAX@Z 0x141669450 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUnk_PCBaseComp_a68@@@@AEBAXPEAX@Z 0x141669480 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VJobSystemCli@@@@AEBAXPEAX@Z 0x141669540 ; unique
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_PCBaseComp_a68@@@@AEAAXXZ 0x141669aa0 ; prop
// MS2-PIN: ??__FstrMgr@?1??GetInstance@CAtlStringMgr@ATL@@SAPEAUIAtlStringMgr@2@XZ@YAXXZ 0x14166a060 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@IPEAX@std@@@std@@QEAAPEAU?$_Tree_node@IPEAX@2@_K@Z 0x14166a0a0 ; unique
// MS2-PINS-END tplpin
// tplpin --simulate (w553), hand-applied:
// MS2-PIN: ??0PC@@QEAA@XZ 0x14164dfd0
// MS2-PIN: ??$_Destroy1@PEAD@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SAXAEAV?$CustomAllocator@D@efd@@PEAPEADU?$integral_constant@_N$00@1@@Z 0x141664590
// MS2-PIN: ??$_Copy_memmove@PEAHPEAH@std@@YAPEAHPEAH00@Z 0x1416645e0
// MS2-PIN: ??$_Destroy_range1@V?$allocator@H@std@@@std@@YAXPEAH0AEAV?$allocator@H@0@U?$integral_constant@_N$00@0@@Z 0x141664650
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@H@?$vector@HV?$allocator@H@std@@@std@@AEAAX$$QEAH@Z 0x141664780
// MS2-PIN: ??$_Emplace_reallocate@H@?$vector@HV?$allocator@H@std@@@std@@QEAAPEAHQEAH$$QEAH@Z 0x141664a80
// MS2-PIN: ??$_Idl_distance1@PEAHPEAH@std@@YA_JAEBQEAH0Urandom_access_iterator_tag@0@@Z 0x141664e60
// MS2-PIN: ??$_Ptr_move_cat@HH@std@@YA?AU_Really_trivial_ptr_iterator_tag@0@AEBQEAH0@Z 0x141665820
// MS2-PIN: ??$_Uninitialized_move@PEAHPEAHV?$allocator@H@std@@@std@@YAPEAHQEAH0PEAHAEAV?$allocator@H@0@@Z 0x141665af0
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@HHV?$allocator@H@std@@@std@@YAPEAHQEAH00AEAV?$allocator@H@0@U_Really_trivial_ptr_iterator_tag@0@U?$integral_constant@_N$00@0@@Z 0x141665ba0
// MS2-PIN: ?FindNextNode@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141667ac0
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141667d00
// MS2-PIN: ?GetKeyAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@PEAU__POSITION@@@Z 0x141667d20
// MS2-PIN: ?GetNext@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141667d80
// MS2-PIN: ?GetNext@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141667dd0
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x141667e10
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141667f00
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VCTailEffectObject@@@@PEAU__POSITION@@@Z 0x141667fc0
// MS2-PIN: ?GetValueAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEAAAEAV?$SmartPointer@VNiAVObject@@@efd@@PEAU__POSITION@@@Z 0x141668030
// MS2-PIN: ?IsNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@AEBA_NPEAVCNode@12@@Z 0x1416683d0
// MS2-PIN: ?Minimum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141668480
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141668b70
// MS2-PIN: ?RemoveNode@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141668cd0
// MS2-PIN: ?Successor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141668ef0
// MS2-PIN: ?_Calculate_growth@?$vector@HV?$allocator@H@std@@@std@@AEBA_K_K@Z 0x1416695a0
// MS2-PIN: ?_Change_array@?$vector@HV?$allocator@H@std@@@std@@AEAAXQEAH_K1@Z 0x141669630
// MS2-PIN: ?_Has_unused_capacity@?$vector@HV?$allocator@H@std@@@std@@AEBA_NXZ 0x141669840
// MS2-PIN: ?_Orphan_range@?$vector@HV?$allocator@H@std@@@std@@AEBAXPEAH0@Z 0x141669970
// MS2-PIN: ?_Reallocate_exactly@?$vector@HV?$allocator@H@std@@@std@@AEAAX_K@Z 0x141669980
// MS2-PIN: ?_Umove_if_noexcept@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH00@Z 0x141669ff0
// MS2-PIN: ?deallocate@?$allocator@H@std@@QEAAXQEAH_K@Z 0x14166a1b0
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@H@std@@@std@@SA_KAEBV?$allocator@H@2@@Z 0x14166a240
// MS2-PIN: ?max_size@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x14166a250
// MS2-PIN: ?reserve@?$vector@HV?$allocator@H@std@@@std@@QEAAX_K@Z 0x14166a300
// MS2-PIN: ??$_Get_unwrapped@H@std@@YAPEAHQEAH@Z 0x141664ce0
// MS2-PIN: ??$_Seek_wrapped@H@std@@YAXAEAPEAHQEAH@Z 0x141665910
// MS2-PIN: ??$_Unfancy@H@std@@YAPEAHPEAH@Z 0x141665ae0
// MS2-PIN: ??$move@AEAH@std@@YA$$QEAHAEAH@Z 0x141665d60
// MS2-PIN: ??0?$allocator@H@std@@QEAA@XZ 0x141666730
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x1416697a0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAAAEAV?$allocator@H@2@XZ 0x1416697c0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@D@efd@@V?$_String_val@U?$_Simple_types@D@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@D@efd@@XZ 0x1416697d0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x1416697f0
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAV?$allocator@H@2@XZ 0x141669800
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x141669890
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x1416698d0
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x1416698f0
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x141669910
// MS2-PIN: ?_Umove@?$vector@HV?$allocator@H@std@@@std@@AEAAPEAHPEAH00@Z 0x141669f70
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH00U?$integral_constant@_N$00@2@@Z 0x141669fb0
// MS2-PIN: ?_Xlength@?$vector@HV?$allocator@H@std@@@std@@CAXXZ 0x14166a060
// MS2-PIN: ?size@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x14166a350
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x141665910
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCBaseComp_a98@@@@QEAA@AEBV0@@Z 0x1416660b0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@IPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@1@@Z 0x141666670
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@IPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@1@@Z 0x1416666b0
// MS2-PIN: ??1?$MS2Ptr@VCEquipItem@@@@QEAA@XZ 0x141666900
// MS2-PIN: ??1?$MS2Ptr@VJobSystemCli@@@@QEAA@XZ 0x141666990
// MS2-PIN: ??1?$MS2Ptr@VWaterGunBattleInfo@@@@QEAA@XZ 0x1416669c0
// MS2-PIN: ??4?$MS2Ptr@VUnk_PCBaseComp_a68@@@@QEAAAEAV0@AEBV0@@Z 0x1416670a0
// MS2-PIN: ??_GUnk_PCCubeCraft@@QEAAPEAXI@Z 0x141667830
// MS2-PIN: ?AddRef@?$MS2Ptr@VRideOnAction@@@@AEBAXXZ 0x141669140
// MS2-PIN: ?AddRef@?$MS2Ptr@VCSkillTierOptionManager@@@@AEBAXXZ 0x141669170
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_PCBaseComp_a68@@@@AEBAXXZ 0x1416691d0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VRideOnAction@@@@AEBAXPEAX@Z 0x1416693f0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCTailEffectObject@@@@AEBAXPEAX@Z 0x141669450
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUnk_PCBaseComp_a68@@@@AEBAXPEAX@Z 0x141669480
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VJobSystemCli@@@@AEBAXPEAX@Z 0x141669540
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_PCBaseComp_a68@@@@AEAAXXZ 0x141669aa0
// MS2-PIN: ??__FstrMgr@?1??GetInstance@CAtlStringMgr@ATL@@SAPEAUIAtlStringMgr@2@XZ@YAXXZ 0x14166a060
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCInteractMode@@@@QEAA@H@Z 0x141666110
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCInteractMode@@@@QEAA@PEAVUnk_PCInteractMode@@@Z 0x141666130
// MS2-PIN: ??0?$MS2Ptr@VCSkillTierOptionManager@@@@QEAA@PEAVCSkillTierOptionManager@@@Z 0x1416661d0
// MS2-PIN: ??0?$MS2Ptr@VCTailEffectObject@@@@QEAA@PEAVCTailEffectObject@@@Z 0x141666270
// MS2-PIN: ??0?$MS2Ptr@VInfo@HideAndSeek@@@@QEAA@PEAVInfo@HideAndSeek@@@Z 0x141666510
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VUnk_PCInteractMode@@@@QEAAAEAV1@PEAVUnk_PCInteractMode@@@Z 0x141666dc0
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCSetItemManager@@@@QEAAAEAV1@PEAVCSetItemManager@@@Z 0x141666e30
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCSkillTierOptionManager@@@@QEAAAEAV1@PEAVCSkillTierOptionManager@@@Z 0x141666ea0
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCStatPointManager@@@@QEAAAEAV1@PEAVCStatPointManager@@@Z 0x141666f10
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCostumeManager@@@@QEAAAEAV1@PEAVCostumeManager@@@Z 0x1416670e0
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VInfo@HideAndSeek@@@@QEAAAEAV1@PEAVInfo@HideAndSeek@@@Z 0x1416672e0
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VWaterGunBattleInfo@@@@QEAAAEAV1@PEAVWaterGunBattleInfo@@@Z 0x1416673f0
// MS2-PIN: ?IsEmpty@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEBA_NXZ 0x141668370
// MS2-PIN: ?Reference@?$MS2Ptr@VJobSystemCli@@@@CAXPEAVJobSystemCli@@@Z 0x1416693b0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCSkillTierOptionManager@@@@AEBAXPEAX@Z 0x141669420
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VJobSystemCli@@@@AEAAXPEAX@Z 0x141669e00
// MS2-PIN: ??1?$MS2Ptr@VCWeaponAction@@@@QEAA@XZ 0x1416668d0
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VUnk_PCD88@@@@QEAAAEAV1@PEAVUnk_PCD88@@@Z 0x141666ba0
// MS2-PIN: ??4?$MS2Ptr@VUnk_PCInteractMode@@@@QEAAAEAV0@H@Z 0x141666d90
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCTailEffectObject@@@@QEAAAEAV1@PEAVCTailEffectObject@@@Z 0x141667030
// MS2-PIN: ??4?$MS2Ptr@VCWeaponAction@@@@QEAAAEAV0@AEBV0@@Z 0x1416670a0
// MS2-PIN: ??7?$MS2Ptr@VCWeaponAction@@@@QEBA_NXZ 0x141667490
// MS2-PIN: ?get@?$MS2Ptr@VCGemSwim@@@@QEBAPEAVCGemSwim@@XZ 0x141667650
// MS2-PIN: ?get@?$MS2Ptr@VCTailEffectObject@@@@QEBAPEAVCTailEffectObject@@XZ 0x141667670
// MS2-PIN: ??C?$MS2Ptr@VCGemSwim@@@@QEBAPEAVCGemSwim@@XZ 0x1416676e0
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEBA_NHAEAV?$MS2Ptr@VCTailEffectObject@@@@@Z 0x141668410
// MS2-PIN: ?RemoveKey@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEAA_NH@Z 0x141668c60
// MS2-PIN: ?SetAt@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$MS2Ptr@VCTailEffectObject@@@@@Z 0x141668d90
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCWeaponAction@@@@AEAAXPEAX@Z 0x141669cc0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VWaterGunBattleInfo@@@@AEAAXPEAX@Z 0x141669e50
// MS2-PIN: ??$emplace_back@H@?$vector@HV?$allocator@H@std@@@std@@QEAAX$$QEAH@Z 0x141665ca0
// MS2-PIN: ??1?$vector@HV?$allocator@H@std@@@std@@QEAA@XZ 0x1416669f0
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCStateManager@@@@QEAAAEAV1@PEAVCStateManager@@@Z 0x141666d20
// MS2-PIN: ?push_back@?$vector@HV?$allocator@H@std@@@std@@QEAAX$$QEAH@Z 0x14166a2d0
// MS2-PIN: ?GetClassDesc@PC@@UEBAPEBVClassInfo@efd@@XZ 0x141667cd0
// MS2-PIN: ?TypeCast@PC@@UEBA_NIPEAPEBX@Z 0x141669010
// MS2-PIN: ?TypeCast@PC@@UEBA_NIPEAPEAX@Z 0x141668fc0
// MS2-PIN: ?capacity@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x14166a170
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pc.cpp"   // assumed (no __FILE__ in the TU)
#define NOMINMAX   // cbreakableobject.h pulls the PhysX headers
#include "ms2/placeholder/ms2stdafx.h"
#include <egmAnimation/AnimationService.h>
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/commonfiles/skillattackdata.h"
#include "ms2/client/ms2/skillrecord.h"
#include "ms2/client/ms2/dpsmetersystem.h"
#include "ms2/client/ms2/autofindtaxistation.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/placeholder/cpceffectdummy.h"
#include "ms2/client/ms2/bonerotateinterpolator.h"
#include "ms2/client/ms2/additionalcli.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/cube.h"
#include "ms2/placeholder/cbreakableobject.h"
#include <egf/EntityIDFactory.h>
#include "ms2/placeholder/csetitemmanager.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/jobsystemcli.h"
#include "ms2/commonfiles/pvpinfo.h"
#include "ms2/commonfiles/hideandseek.h"
#include "ms2/guess/skilltieroptionmanager.h"
#include "ms2/client/ms2/statpointmanager.h"
#include "ms2/guess/watergunbattleinfo.h"
#include "ms2/client/ms2/taileffectobject.h"
#include "ms2/client/ms2/effectobject.h"
#include "ms2/client/ms2/equipmodel.h"
#include "ms2/commonfiles/additionalactionadditional.h"
#include "ms2/client/ms2/taileffectobjectfromadditional.h"
#include "ms2/commonfiles/taileffectdatatable.h"
#include "ms2/client/ms2/randomtargeteffect.h"
#include "ms2/unnamed/unit_140b0e5f0.h"
#include "ms2/client/ms2/cubecraft_1.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/placeholder/pcinfo.h"
#include "ms2/placeholder/cequipmentslotlayerinfo.h"
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/commonfiles/luautil.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/cubecraft_2.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/client/ms2/kfmmodel.h"
#include "ms2/client/ms2/clonepc.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/client/ms2/filepreload_1.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/client/ms2/notifychangebuff.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "weaponactiontable.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/client/ms2/stateholddata.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/commonfiles/itemdefaultdata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/masterytable.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statebannerdata.h"
#include "ms2/client/ms2/statecashcalldata.h"
#include "ms2/client/ms2/statedatagrabtarget.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/statedead.h"
#include "ms2/client/ms2/stateemotionidle.h"
#include "ms2/client/ms2/statefalldamage.h"
#include "ms2/client/ms2/statefall.h"
#include "ms2/client/ms2/statefishingdata.h"
#include "ms2/client/ms2/stateglide.h"
#include "ms2/client/ms2/statehit.h"
#include "ms2/client/ms2/stateholddata.h"
#include "ms2/client/ms2/statehomeconvenient.h"
#include "ms2/client/ms2/statehomemade.h"
#include "ms2/client/ms2/stateidle.h"
#include "ms2/client/ms2/stateinteraction.h"
#include "ms2/client/ms2/statejump.h"
#include "ms2/client/ms2/statejumpto.h"
#include "ms2/client/ms2/stateladder.h"
#include "ms2/client/ms2/stateland.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/statemicrogame.h"
#include "ms2/client/ms2/statenurturing.h"
#include "ms2/client/ms2/stateobserver.h"
#include "ms2/client/ms2/stateplayinstrumentdata.h"
#include "ms2/client/ms2/statepvpwinlose.h"
#include "ms2/client/ms2/statereact.h"
#include "ms2/client/ms2/stateskill.h"
#include "ms2/client/ms2/statespawn.h"
#include "ms2/client/ms2/statestun.h"
#include "ms2/client/ms2/statesummon.h"
#include "ms2/client/ms2/stateswimdash.h"
#include "ms2/client/ms2/stateswim.h"
#include "ms2/client/ms2/statetalk.h"
#include "ms2/client/ms2/statetaxicalldata.h"
#include "ms2/client/ms2/statetransform.h"
#include "ms2/client/ms2/stateusefurnituredata.h"
#include "ms2/client/ms2/statewaitingselect.h"
#include "ms2/client/ms2/statewalk.h"
#include "ms2/placeholder/statecoupleemotion.h"
#include "ms2/placeholder/stateweddingemotion.h"
#include "ms2/unnamed/unit_140ad5280.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe functions and singletons used by the PC TU (other units) ----
void FUN_1411e0810(Unk_PCEquipSet* pEquip);                         // the equipment was reset (equipitem.cpp)
void FUN_141993180(int nObjectId);                                  // drop the actor's +0xfd8 record
void FUN_141b6f220(NiAVObject* pRoot, int nKind, const Unk_CharEquip* pEquip);
int FUN_140869420();                                                // the current second
CTailEffectDataTable* FUN_140ad0da0();                              // the tail effect table
void FUN_140a35900(Unk_PCD88* p);                                   // close the +0xd88 record
// The world (WorldService; FUN_1403ed2d0).
class Unk_PCLocalPlayer : public PC                                 // the MyPC
{
public:
    void FUN_14152a960();                                           // stop observing
    int FUN_1415278d0(__int64 nCharId);                             // the character is in the party
};
class Unk_PCWorld
{
public:
    Unk_PCLocalPlayer* FUN_141bd0cc0();                             // the local player
    PCBase* FUN_141bd1290(int nObjectId);                           // the player of an object id
    GameObject* FUN_141bd0fa0(egf::EntityID kId);                   // the object of an entity
    void FUN_141bbb7f0(GameObject* pObj, int n);                    // unregister an object
    int FUN_141bdb5a0(int nObserveMode);
    GameObject* FUN_141bd1180(int nObjectId);                       // the object of an id
    int FUN_141bc9830(int* pnId, CString* pstrName, float fRange, int n);   // the nearest holdable target
    MS2Ptr<CProxyGameObject> FUN_141bc9c60(__int64 nId);            // the proxy of a player by id
    MS2Ptr<CProxyGameObject> FUN_141bc9be0(int nObjectId);          // the proxy of an object id
    int FUN_141bca2e0();                                            // the field is loaded
    void FUN_141bca390(unsigned int nObjectId);                     // the player model is ready (quick equip)
    int FUN_141bd19d0(int nObjectId);                               // the relation of an object (1: the local player)
    int FUN_141bd3060();                                            // the current map id
    PCBase* FUN_141bd1200(int nObjectId);                           // the actor of an object id
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                          // the current field
};
Unk_PCWorld* FUN_1403ed2d0();
// The effect service (FUN_1403ed280).
class Unk_PCFxMgr
{
public:
    void FUN_1411a5770(int nKind, PCBase* pTarget);                 // play an event effect on an actor
    void FUN_1411a6060(unsigned nId);                               // stop the effects of an id
    unsigned FUN_1411a5580(int nMaterial, int nKind, int nRelation, const NiPoint3& kPos, float fVolume);   // play a hit sound
};
Unk_PCFxMgr* FUN_1403ed280();
// The controller body (PCBase +0x150; unit_14123f5b0.cpp's GameObjectController).
class Unk_PCBaseBody
{
public:
    void FUN_14123fbf0(unsigned short nGroup);                      // collision group of every shape
    void FUN_14123fd30(unsigned int nGroups);                       // the active groups
    bool FUN_1412410c0(const efd::Point3& kPos, float fRadius);     // the capsule at kPos overlaps something
};
// The animation service singleton (statefall.h declares the global FUN_141b6f910 with a unit-local view type).
namespace PCAnim { egmAnimation::AnimationService* FUN_141b6f910(); }
NiAVObject* FUN_141b6ef70(egf::EntityID kId);                       // the scene graph of an entity
void FUN_141567330(NiAVObject* pRoot, bool b);                      // (the model was loaded)
extern float DAT_1439f8210;                                         // the hit colour boost (0.7, 0.1, 0.1)
extern float DAT_1439f8214;
extern float DAT_1439f8218;
ClonePC* FUN_1405a7e30(PC* p);                                      // efd::DynamicCast<ClonePC>
extern int DAT_1439f821c;                                           // the combo preload loop limit
SkillDataTableCli* FUN_1401958b0();                                 // TSingleton<SkillDataTableCli>::GetInstance
void* FUN_140166440();                                              // the log
void FUN_1401859c0(void* pLog, int nLevel, int nCategory, const wchar_t* pszText);
class Unk_PCBaseBuffs
{
public:
    int FUN_1409701d0(int nKind);
    int FUN_1409709b0();                                            // a buff blocks being grabbed
    bool FUN_140970a20();                                           // a buff protects from pk attacks
};
// The content switches (FUN_140166410).
class Unk_PCFeatures
{
public:
    bool FUN_14036d570(int nFeature);                               // the feature is enabled
};
Unk_PCFeatures* FUN_140166410();
// The entity manager and the entity property reads (as pcbase.cpp).
class Unk_PCEntMgr                                                  // EntityWorldManager (entityworldmanager.h)
{
public:
    egf::EntityPtr FUN_1411ce7c0(efd::utf8string kModel, efd::utf8string kAsset, efd::Point3 kPos, efd::Point3 kRot,
        float fScale, int a, int b);                                // create an entity
};
Unk_PCEntMgr* FUN_1409670f0();
egf::Entity* FUN_1411cf440(Unk_PCEntMgr* pMgr, const egf::EntityID& kId);
void FUN_1409618c0(egf::Entity* pEntity, unsigned int nPropId, NiPoint3& kValue);   // Entity::GetPropertyValue<efd::Point3>
float FUN_140966ea0(efd::Point3 a, efd::Point3 b);                  // the horizontal distance
extern NiPoint3 DAT_143b01a60;                                      // the zero point
void FUN_14015f050(CString& str, CAtlArray<CString>& aParts, const char* pszSep);   // split
CString FUN_141425540(int nGender, int nAction);                    // the default swim effect of an action (itemugcmesh.cpp)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                     // the item record of an id
// The housing service, looked up from its registry cell (as guildmanager.cpp).
// The housing service is CubeMapInformationService (efd::SmartPointer<CubeMapInformationService> handle).
class Unk_PCHousingSvc
{
public:
    void FUN_1410cc160(int nKind);                                  // the cube build mode UI
    Cube* FUN_1410b8f30(NiPoint3 kFrom, efd::Point3* pHit, float fRange);   // the cube under a point
    efd::Point3 FUN_1410b9150(efd::Point3 kPos);                    // snap a point onto the cube grid
    Cube* FUN_1410b8a60(Unk_Int3 kCell);                            // the cube of a grid cell
    Cube* FUN_1410b9080(Cube* pBase, int nOffset);                  // the neighbour cube (packed cell offset)
    Cube* FUN_1410b8e60(void* pEntity);                             // the cube of an entity
    int FUN_1410b9330(Cube* pCube, efd::Point3 kHit, float fStep, efd::Point3* pPos, efd::Point3* pRot, int* pnDir,
        Cube** ppFound);                                            // the climb-on spot of a cube face
};
Unk_PCHousingSvc* FUN_1409670e0();                                  // TSingleton<CubeMapInformationService>::GetInstance
class Unk_PCHousingSvcPtr
{
public:
    Unk_PCHousingSvcPtr(Unk_PCHousingSvc* p);                       // 0x1401cd0b0
    ~Unk_PCHousingSvcPtr();                                         // 0x1401cd150
    Unk_PCHousingSvc* FUN_1401cd1a0() const;                        // operator->
    Unk_PCHousingSvc* FUN_140885310() const;                        // operator CubeMapInformationService*
    Unk_PCHousingSvc* m_p;
};
Unk_PCHousingSvc* FUN_1401cd040(char* pCell);
extern char DAT_143b059e8;
// Physics: the ray cast record and the PhysX helper (physxhelper.h needs NOMINMAX; state.cpp has the same view).
struct Unk_RayCastInfo
{
    Unk_RayCastInfo();                                              // 0x140ad4440
    efd::Point3 m_origin;                                           // +0x00
    efd::Point3 m_dir;                                              // +0x0c
    float m_maxDist;                                                // +0x18
    int m_groups;                                                   // +0x1c collision groups
    void* m_20;
    void* m_28;
    void* m_hitEntity;                                              // +0x30
    void* m_hitActor;
    void* m_hitShape;
    float m_hitDist;                                                // +0x48
    efd::Point3 m_hitPoint;                                         // +0x4c
    efd::Point3 m_hitNormal;                                        // +0x58
};
MS2_CHECK_SIZE(Unk_RayCastInfo, 0x68);
class NxGroupsMask;
class CPhysXHelper
{
public:
    bool FUN_1416892f0(Unk_RayCastInfo* pInfo, const NxGroupsMask* pMask);   // cast the ray
};
CPhysXHelper* FUN_1409f7ca0();
extern float DAT_1439f8220;                                         // the climb reach (3)
extern float DAT_1439f8224;                                         // the climb probe range (30)
// The shadow quality settings (?\gameoption.cpp keeps the full view).
class Unk_PCShadowCfg
{
public:
    int FUN_141376880(int n);
    int FUN_1413769d0(int n);
};
Unk_PCShadowCfg* FUN_140ae1c00();
// The actor's ground shadow (unit_14160fb10; dropitem.cpp has the 5-argument ctor).
class CObjectShadow : public NiRefObject
{
public:
    CObjectShadow(GameObject* pOwner, int nLodHi, int nLodLo);      // 0x14160fb10
private:
    char m_pad_10[0x58 - sizeof(NiRefObject)];
};
// The pvp manager (FUN_140f97ef0).
class Unk_PCPvPMgr
{
public:
    void FUN_141280ca0(__int64 nCharId);                            // leave
};
Unk_PCPvPMgr* FUN_140f97ef0();
// The dialog 0x4e8a (FUN_141531b40): a name at +0x178.
class Unk_PCDialog4e8a
{
public:
    // @0x141667f70
    CStringW FUN_141667f70() { return m_str178; }
    unsigned char unknown0[0x178];
    CStringW m_str178;
};
Unk_PCDialog4e8a* FUN_141531b40(int nId);
extern "C" int DAT_143ae2b38;                                       // the model-cache reset switch (nifmodel.h)
void FUN_14098c6e0(void* pEntity, unsigned nProperty, const bool& bValue);   // set a bool entity property
// The KFM model of an equipped item (CEquipItem::FUN_1411dcbb0).
class CKfmModel;
class Unk_PCKfmActor
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(float fScale);                            // MS2: slot 22 (the model scale)
};
Unk_PCKfmActor* FUN_14141c720(const MS2Ptr<CKfmModel>& spModel);
class Unk_ItemEquipData : public CItemData {};
struct Unk_EquipItemData : public CItemData {};                     // CEquipItem::FUN_1411dc7f0's record (as astooltip_local.h)
int FUN_14082f1a0(int nType);                                       // the stat is a 64-bit value                     // CItem::FUN_140527840's record (as astooltip_local.h)
// The optimizer (COptimizer, FUN_1409f7c90).
class Unk_PCEquipConfig
{
public:
    int FUN_1409f7ea0();                                            // quick equip is on
    int FUN_141622790() const;                                      // the visibility limit is on
    int FUN_14161cf40() const;                                      // others are shown
    int FUN_140ddcc90();                                            // the low-spec mode
    void FUN_14161cf60(PCBase* pPC);                                // register a loaded player
};
Unk_PCEquipConfig* FUN_1409f7c90();
// The dialogs 0x4e96 / 0x4ec4 (FUN_141531c80 / FUN_141531be0): the hp of a party member changed.
class Unk_PCDialog4e96 { public: void FUN_141a92b10(__int64 nCharId, __int64 nCur, __int64 nMax); };
class Unk_PCDialog4ec4 { public: void FUN_14133afb0(__int64 nCharId, __int64 nCur, __int64 nMax); };
Unk_PCDialog4e96* FUN_141531c80(int nId);
Unk_PCDialog4ec4* FUN_141531be0(int nId);
// MS2Ptr<Unk_RideeData> (not CPtred-derived here; ridee.cpp/pcbase.cpp do the same): instantiated by other objs.
template <> MS2Ptr<Unk_RideeData>::~MS2Ptr();                                           // 0x140788ed0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::operator->() const;                   // 0x1407895d0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::get() const;                          // 0x1409f78a0
// The string table (FUN_1401a9d70).
class Unk_PCStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_PCStrings* FUN_1401a9d70();
// The PCBase UI components (pcbase.cpp has the same stand-ins) and their factories.
class Unk_PCBaseComp_a68 : public CPtred {};
class Unk_PCBaseComp_a78 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // refresh
    void FUN_141a5e4c0(int nFontSize);                              // UINameTag::Entity
    void FUN_141a5e500(int nColor);
};
class Unk_PCBaseComp_a88 : public CPtred {};
class Unk_PCBaseComp_a98 : public CPtred {};
class Unk_PCBaseComp_aa8 : public CPtred {};
class Unk_PCBaseComp_ab8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // refresh
};
class Unk_PCBaseComp_ac8 : public CPtred {};
class Unk_PCBaseComp_a58 : public CPtred {};                        // UIHpBar::Entity
MS2Ptr<Unk_PCBaseComp_a58> FUN_141992920(int nActorId);            // UIHpBar::Entity
MS2Ptr<Unk_PCBaseComp_a68> FUN_140e86320(int nActorId);
MS2Ptr<Unk_PCBaseComp_a78> FUN_141a60da0(int nActorId);            // UINameTag
MS2Ptr<Unk_PCBaseComp_a88> FUN_14192fd40(int nActorId);
MS2Ptr<Unk_PCBaseComp_a98> FUN_14128ef70(int nActorId);            // UIBuffBalloon
MS2Ptr<Unk_PCBaseComp_aa8> FUN_1418fbdb0(int nActorId);            // UIChatBalloon
MS2Ptr<Unk_PCBaseComp_ab8> FUN_141a8fb50(int nActorId);            // UIPopupProfileImage
MS2Ptr<Unk_PCBaseComp_ac8> FUN_140ba8cf0(int nActorId);
MS2Ptr<Unk_PCLinkFD8> FUN_141993100(int nActorId);
void FUN_141a60f00(int nActorId);                                   // the level changed (name tag)
// The game options (FUN_1409a8b10).
class Unk_PCOption
{
public:
    char m_pad_00[0xc];
    bool m_bShowHpBar;                                              // +0xc
    bool m_bShowPartyHp;                                            // +0xd
};
class Unk_PCOptions { public: Unk_PCOption* FUN_140b123b0(); };
Unk_PCOptions* FUN_1409a8b10();
unsigned FUN_140a7d630(Common::Constants::Value<Unk_ConstColor>* pColor); // the colour as ARGB (npcdatacli.cpp)
// The running skill cast (CSkillRecord, skillrecord.h; its SkillMotionData clashes with jobsystem.h's skilldata.h
// placeholder here). The smart pointer helpers are the exe's shared copies.
class Unk_PCSkillMotion : public CPtred                             // SkillMotionData
{
public:
    char m_pad_18[0x38];
    CString m_strWeaponSequenceName;                                // +0x50
};
class Unk_PCSkillRecord : public CPtred
{
public:
    Unk_PCSkillMotion* FUN_141759830();                             // the motion
};
template <> MS2Ptr<CSkillRecord>::~MS2Ptr();                        // 0x140975740
template <> CSkillRecord* MS2Ptr<CSkillRecord>::operator->() const; // 0x140975bd0
template <> bool MS2Ptr<CSkillRecord>::operator!() const;           // 0x141667460
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                    // the entity's scene graph
// The emotion effect set of vfunc_71 (pcbase.cpp has the same stand-in, typed further).
class Unk_PCBaseFxSet : public CPtred
{
public:
    void* m_pad_18[2];
    bool m_bLoop28;                                                 // +0x28
};
unsigned FUN_141472bc0();                                           // the server tick
// The main player info dialog (FUN_140931900 = the UI by id).
class Unk_PCMainPlayerInfo
{
public:
    void FUN_1419f1200(int nId, int nEnd);                          // start a timer
    void FUN_1419f1370(int nId);                                    // stop it
};
Unk_PCMainPlayerInfo* FUN_140931900(int nUiId);
MyPC* FUN_1409613d0(PCBase* p);                                     // efd::DynamicCast<MyPC>
int FUN_14086ae10(__int64 nTime);                                   // the time lies before today
CMasteryTable* FUN_1409670c0();                                     // TSingleton<CMasteryTable>
bool FUN_14081dc50(int nSpecial);                                   // the special ability is an integer
bool FUN_14081dcd0(int nSpecial);                                   // the special ability value is a rate
int FUN_14086ace0(__int64 nTime);                                   // the time has passed
// The hide and seek record / the water gun battle info as other TUs see them (fittingdollpc.h returns these types).
class Unk_HsInfo : public CPtred {};
class Unk_PCWaterGunInfo : public CPtred {};
void FUN_141201d50(CEquipModel* pModel, CString strNode);           // attach the model to a node
int FUN_141202940(CEquipModel* pModel);                             // the equip slot of the model
void FUN_141200390(CEquipModel* pModel, const CString& strAnim);    // play an animation
CString FUN_141b6ed00(const CString& strPath);                      // the kfm's animation path
CString FUN_1409a2360(const char* pszUrn, int n);                   // normalise an asset urn
ModelPart* FUN_141200ab0(CEquipModel* pModel);                      // the model's part record (m_unk_20)
extern bool DAT_143aad1e0;                                          // the upper HUD hides the weapon effects (uiupperhuddialog.cpp)
extern CString DAT_143ae2de8;                                       // the hidden-equip reason (CEquipment::FUN_1411e8eb0 / FUN_1411e9020)
bool FUN_14028d470(float a, float b);                               // the floats are equal
// The model resource cache (FUN_140a0afd0) and the file preloader.
class Unk_PCModelCache
{
public:
    bool FUN_141551db0(CString strPath);                            // the file is cached
};
Unk_PCModelCache* FUN_140a0afd0();
CFilePreload* FUN_140ab7a10();
// The UI root (FUN_1403ed2b0).
class Unk_PCUIRoot
{
public:
    void FUN_141ad9c40(MS2Ptr<CGemBase> spGem);                     // show the gem effect
};
Unk_PCUIRoot* FUN_1403ed2b0();
// The notice dispatcher (FUN_140939a10).
class Unk_PCNotices
{
public:
    void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify);
};
Unk_PCNotices* FUN_140939a10();

// The +0xd88 record is the head CBoneRotateManager (vfunc_12 news it; clonepc.cpp/stateidle.cpp keep the
// Unk_PCD88 name, which the exe's MS2Ptr COMDAT symbols carry) and the +0xfd8 record (create 0x141993100).
class Unk_PCD88 : public CBoneRotateManager
{
public:
    void FUN_140a35500(double dTime);                               // per-frame: pick/advance actions
};
class Unk_PCLinkFD8 : public CPtred                                 // UITombStoneBar::Entity
{
public:
    void FUN_141992e40();                                           // refresh
};
// The action timer at +0xfc8 (avatarpc.cpp has the same stand-in).
class Unk_PCActionTimer : public CPtred                             // CBreakableObject (the tomb stone; cbreakableobject.h)
{
public:
    void FUN_140adf370(egf::Entity* pEntity, int nObjectId, MS2Ptr<CGemTombStone> spTomb);   // bind as a tomb stone
    virtual void vfunc_1(void* p, int nMode);                       // 1 notify (FUN_14165c970: 2 / 5)
    int FUN_140addea0();                                            // active
};

// ---- header statics of this TU (.text$di 0x1400fb010-0x1400fb4d0; same groups as unit_140114300 / unit_140102270) ----
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };    // an 8-byte pointer holder
static CString s_strCustomize = "Customize";
static CString s_strDefault = "Default";
static CString s_strEmotion = "Emotion";
static CString s_strExceptRender = "ExceptRender";
static CString s_strExpired = "Expired";
static CString s_strHair = "Hair";
static CString s_strInvalide = "Invalide";
static CString s_strLayerExpired = "layerExpired";
static CString s_strLower = "Lower";
static CString s_strMissMatch = "MissMatch";
static CString s_strOptimizer = "Optimizer";
static CString s_strPCBang = "PCBang";
static CString s_strSlot = "Slot";
static CString s_strUndo = "Undo";
static CString s_strVIP = "VIP";
static CString s_strWillUpdatePos = "WillUpdatePos";
static CString s_sortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static efd::Category s_category(0);
static Unk_1401cd100 s_pointer(NULL);
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);

// ---- PC ----

// MS2-FUNCTIONAL: written from the decompile; member construction order per the exe.
// @0x14164dfd0
PC::PC()
    : m_nD68(0), m_nD80(0), m_spD88(0), m_entityDB0(0ull), m_nCharIdDB8(0), m_nAccountIdDC0(0), m_nGenderDD8(0),
      m_nLevelDDC(1), m_kEquipDE0(this), m_spFD8(0), m_nFF0(0), m_nFF4(0), m_nFF8(0), m_nFF9(0), m_nCubeModeFFC(0),
      m_n1000(0), m_spCube1008(0), m_n1018(0), m_pCubeCraft(0), m_n1038(0), m_spItem1040(0), m_n1054(0), m_n1058(0),
      m_n105c(0), m_n1060(0), m_n1064(0), m_n1068(0), m_n106c(0), m_n10e8(0), m_n10ec(0), m_n10f0(0), m_n10f4(0),
      m_n10f8(0), m_n10fc(0), m_n1140(0), m_n1148(0), m_n114c(0), m_f1180(1.0f), m_n1184(0), m_n1188(0), m_n1190(0),
      m_n1198(0), m_n119c(0), m_n11a0(0), m_spItem11b8(0), m_n11c8(0), m_n11cc(0), m_n11d0(0), m_spCouple11d8(0),
      m_n11e8(0), m_n11f0(0), m_n11f4(0), m_n11f8(0), m_n1200(0), m_b1204(0), m_n1208(0), m_n120c(0), m_n1220(0),
      m_b1224(false), m_spInteractMode(0), m_mapTail1280(17, .75f, .25f, 2.25f, 10), m_sp12d8(0)
{
    m_str1028 = "";
    m_strNameDC8 = "";
    m_strDD0 = "";
    m_unk_180.m_z = 3.5f;
    m_unk_180.m_y = 1.2f;
    m_unk_180.m_w = 3.5f;
    m_unk_190.m_z = 3.5f;
    m_unk_190.m_y = 1.2f;
    m_unk_190.m_w = 3.5f;
    m_bD40 = true;
    m_colorD98[0] = NiColor(1.0f, 0.925490201f, 0.866666675f);
    m_colorD98[1] = NiColor(0.929411769f, 0.435294122f, 0.341176480f);
    m_f164 = FUN_1401d3200()->OffsetPcHpbar.Read();
    m_f168 = FUN_1401d3200()->OffsetPcChatballoon.Read();
    m_f16c = FUN_1401d3200()->OffsetPcNametag.Read();
    m_f170 = 0.0f;
    m_f174 = 0.0f;
    m_f178 = FUN_1401d3200()->OffsetPcDamagenumber.Read();
    m_f17c = FUN_1401d3200()->OffsetPcProfileTag.Read();
    m_spStateMgr.AssignRaw(new CStateManager(this));
    m_spStateMgr->FUN_1417daeb0(1, new StateIdle(this));
    m_spStateMgr->FUN_1417daeb0(2, new StateWalk(this));
    m_spStateMgr->FUN_1417daeb0(3, new StateCrawl(this));
    m_spStateMgr->FUN_1417daeb0(4, new StateLand(this));
    m_spStateMgr->FUN_1417daeb0(5, new StateFall(this));
    m_spStateMgr->FUN_1417daeb0(6, new StateJump(this));
    m_spStateMgr->FUN_1417daeb0(7, new StateJumpTo(this));
    m_spStateMgr->FUN_1417daeb0(8, new StateLadder(this));
    m_spStateMgr->FUN_1417daeb0(9, new StateRope(this));
    m_spStateMgr->FUN_1417daeb0(0xb, new StateEmotion(this));
    m_spStateMgr->FUN_1417daeb0(0xc, new StateDead(this));
    m_spStateMgr->FUN_1417daeb0(0xd, new StateHit(this));
    m_spStateMgr->FUN_1417daeb0(0xe, new StateWaitingSelect(this));
    m_spStateMgr->FUN_1417daeb0(0xf, new StateEmotionIdle(this));
    m_spStateMgr->FUN_1417daeb0(0x10, new StateSkill(this));
    m_spStateMgr->FUN_1417daeb0(0x12, new StateStun(this));
    m_spStateMgr->FUN_1417daeb0(0x11, new StateSpawn(this));
    m_spStateMgr->FUN_1417daeb0(0x14, new StateDash(this));
    m_spStateMgr->FUN_1417daeb0(0x15, new StatePush(this));
    m_spStateMgr->FUN_1417daeb0(0x16, new StateTalk(this));
    m_spStateMgr->FUN_1417daeb0(0x18, new StateRevival(this));
    m_spStateMgr->FUN_1417daeb0(0x19, new StateInteraction(this));
    m_spStateMgr->FUN_1417daeb0(0x1a, new StateInteractionNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x1d, new StateClimb(this));
    m_spStateMgr->FUN_1417daeb0(0x1e, new StateGlide(this));
    m_spStateMgr->FUN_1417daeb0(0x1b, new StateSwim(this));
    m_spStateMgr->FUN_1417daeb0(0x1c, new StateSwimDash(this));
    m_spStateMgr->FUN_1417daeb0(0x1f, new StateFallDamage(this));
    m_spStateMgr->FUN_1417daeb0(0x20, new StateHold(this));
    m_spStateMgr->FUN_1417daeb0(0x21, new StateRide(this));
    m_spStateMgr->FUN_1417daeb0(0x22, new StateTransform(this));
    m_spStateMgr->FUN_1417daeb0(0x25, new StateTaxiCall(this));
    m_spStateMgr->FUN_1417daeb0(0x26, new StateSummon(this));
    m_spStateMgr->FUN_1417daeb0(0x28, new StatePvPWinLose(this));
    m_spStateMgr->FUN_1417daeb0(0x29, new StateUseFurniture(this));
    m_spStateMgr->FUN_1417daeb0(0x2a, new StateCashCall(this));
    m_spStateMgr->FUN_1417daeb0(0x2b, new StateGrabTarget(this));
    m_spStateMgr->FUN_1417daeb0(0x2c, new StateRecall(this));
    m_spStateMgr->FUN_1417daeb0(0x2d, new StateFishing(this));
    m_spStateMgr->FUN_1417daeb0(0x2f, new StatePlayInstrument(this));
    m_spStateMgr->FUN_1417daeb0(0x35, new StateTriggerEmotion(this));
    m_spStateMgr->FUN_1417daeb0(0x46, new StateTriggerFollowNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x36, new StateHomeConvenient(this));
    m_spStateMgr->FUN_1417daeb0(0x37, new StateHomemade(this));
    m_spStateMgr->FUN_1417daeb0(0x39, new StateAutoInteraction(this));
    m_spStateMgr->FUN_1417daeb0(0x3a, new StateCoupleEmotion(this));
    m_spStateMgr->FUN_1417daeb0(0x3b, new StateBanner(this));
    m_spStateMgr->FUN_1417daeb0(0x3c, new StateMicroGameRps(this));
    m_spStateMgr->FUN_1417daeb0(0x3d, new StateReact(this));
    m_spStateMgr->FUN_1417daeb0(0x3e, new StateTreeWatering(this));
    m_spStateMgr->FUN_1417daeb0(0x3f, new StateObserver(this));
    m_spStateMgr->FUN_1417daeb0(0x40, new StateNurturing(this));
    m_spStateMgr->FUN_1417daeb0(0x45, new StateMicroGameCoupleDance(this));
    m_spStateMgr->FUN_1417daeb0(0x47, new StateWeddingEmotion(this));
    m_kGemEquip1078.FUN_141668230(this);
    m_spJobFB8.AssignRaw(new JobSystemCli());
    m_spJobFB8->FUN_140a6d8e0(this);
    m_spInteractMode.AssignRaw(reinterpret_cast<Unk_PCInteractMode*>(new CPvPInfo()));
    m_spHideAndSeek1250.AssignRaw(new HideAndSeek::Info());
    m_spSetItems.AssignRaw(new CSetItemManager());
    m_spSkillTier1110.AssignRaw(new CSkillTierOptionManager(this));
    m_spStatPoint1120.AssignRaw(new CStatPointManager(this));
    m_spCostume.AssignRaw(new CostumeManager((AvatarPC*)this));   // the shared ctor is declared with AvatarPC*
    for (size_t i = 0; i < 3; i++)
        m_spGuide1228[i] = 0;
    memset(m_aMastery1150, 0, sizeof(m_aMastery1150));
    int nTailId = *FUN_1401d3200()->TailEffectDefaultID.Get();
    MS2SvrPtr<TailEffectData> spTail = FUN_140ad0da0()->GetData(nTailId);
    if (spTail)
        m_spTailEffect1270.AssignRaw(new CTailEffectObject(this, spTail));
    m_spRandomTarget12c8.AssignRaw(new CRandomTargetEffect(this));
    m_spWaterGun1260.AssignRaw(new WaterGunBattleInfo());
}

// MS2-FUNCTIONAL: written from the decompile.
// @0x141650b10
PC::~PC()
{
    m_spFD8 = 0;
    if (m_spD88.get() != 0)
    {
        FUN_140a35900(m_spD88.operator->());
        m_spD88 = 0;
    }
    if (DAT_143ae2b38 != 0)
        m_sp12d8 = 0;
    if (m_pCubeCraft)
    {
        delete m_pCubeCraft;
        m_pCubeCraft = 0;
    }
    if (m_spInteractMode.get() != 0)
    {
        if (reinterpret_cast<CPvPInfo*>(m_spInteractMode.operator->())->FUN_140743550() && FUN_140f97ef0())
            FUN_140f97ef0()->FUN_141280ca0(FUN_141656a80());
        m_spInteractMode = 0;
    }
    if (m_n1060 != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_n1060);
        m_n1060 = 0;
    }
    if (Unk_PCDialog4e8a* pDialog = FUN_141531b40(0x4e8a))
    {
        if (PC::vfunc_77().GetLength() > 0 && pDialog->FUN_141667f70() == PC::vfunc_77())
        {
            if (Unk_PCLocalPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0())
                pPlayer->FUN_14152a960();
        }
    }
    for (std::set<unsigned int>::iterator it = m_set11a8.begin(); it != m_set11a8.end(); ++it)
    {
        if (ClonePC* pClone = dynamic_cast<ClonePC*>(FUN_1403ed2d0()->FUN_141bd1290(*it)))
            pClone->FUN_1410873d0();
    }
    m_set11a8.clear();
    POSITION pos = m_mapTail1280.GetStartPosition();
    while (pos)
    {
        MS2Ptr<CTailEffectObject> spTail = m_mapTail1280.GetValueAt(pos);
        spTail->FUN_140ad01d0();
        m_mapTail1280.GetNext(pos);
    }
    m_spWaterGun1260 = 0;
}

// @0x141651300
void PC::vfunc_9(void* p)
{
    PCBase::vfunc_9(p);
    FUN_14098c6e0(p, 0xa0b6b179, m_bD40 ? false : true);
}

// @0x141651370
int PC::vfunc_10()
{
    PCBase::vfunc_10();
    m_unk_150->FUN_14123fbf0(2);
    m_unk_150->FUN_14123fd30(0x399);
    FUN_141660d50();
    bool bHurt = FUN_141670a00(4) != FUN_141670a30(4);
    if (bHurt)
        FUN_141670180(false);
    const int& nClassID = GetClassID();
    if (nClassID == 0x6200003 || nClassID == 0x6200004)
    {
        efd::AssetID kId((const char*)FUN_14123bbd0(), 0, efd::AssetID::NEVER_CACHE);
        efd::vector<egmAnimation::KFMCache::KFMCacheHandle> kHandles;
        if (!PCAnim::FUN_141b6f910()->Cache(kId, 0, s_category, kHandles))
            PCAnim::FUN_141b6f910()->UnCacheHandles(kHandles);
    }
    return 1;
}

// MS2-FUNCTIONAL: written from the decompile (temporaries and the effect-dummy loop differ)
// @0x1416515a0
void PC::vfunc_12()
{
    PCBase::vfunc_12();
    NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410());
    if (pRoot != 0)
    {
        vfunc_138(pRoot, 0, reinterpret_cast<const Unk_CharEquip*>(&m_colorD98[0]));
        vfunc_138(pRoot, 2, reinterpret_cast<const Unk_CharEquip*>(&m_colorD98[1]));
        if (vfunc_145())
        {
            m_spD88.AssignRaw(static_cast<Unk_PCD88*>(new CBoneRotateManager));
            m_spD88->FUN_140a34b80(this, CString("Bip01 Head"));
        }
        FUN_141567330(pRoot, true);
    }
    vfunc_143();
    size_t nCount = CPCEffectDummy::GetInstance()->GetCount(FUN_141658e60());
    CEffectDummy kDummy;
    for (size_t i = 0; i < nCount; i++)
    {
        if (CPCEffectDummy::GetInstance()->Get(FUN_141658e60(), (unsigned int)i, kDummy))
            FUN_141674ef0(kDummy);
    }
    if (FUN_141661860())
    {
        if (m_pCubeCraft != 0)
            delete m_pCubeCraft;
        m_pCubeCraft = new Unk_PCCubeCraft(this, m_n1018, m_spCube1008.get());
        m_pCubeCraft->FUN_1410a8af0(true);
        FUN_141661880(0, 0, 0);
    }
    if (FUN_14165f100() == 0 && m_n1038 != 0)
        FUN_14165f1f0(m_n1038, 1);
    m_n1038 = 0;
    m_kGemEquip1078.FUN_141270610();
    MS2Ptr<CGemBase> spGem = reinterpret_cast<PCGemEquip*>(FUN_14165f460())->FUN_141270740(2);
    if (spGem.get())
        spGem->vfunc_8();
    FUN_1409f7c90()->FUN_14161cf60(this);
    if (DAT_143ae2b38 != 0)
    {
        if (NiAVObject* pModel = FUN_141b6ef70(FUN_14123c460()))
        {
            NiFixedString kName("Bip01 HeadNub");
            m_sp12d8 = pModel->GetObjectByName(kName);
        }
    }
    if (FUN_1409f7c90()->FUN_1409f7ea0())
        FUN_1403ed2d0()->FUN_141bca390(FUN_14123c580());
    MS2Ptr<Unk_PCBaseComp_ab8> spComp = vfunc_86();
    if (spComp)
        spComp->vfunc_2();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x141652080
void PC::vfunc_33(void* a, void* b)
{
    CDamageRecord* pRecord = static_cast<CDamageRecord*>(a);
    GameObject::vfunc_33(a, b);
    vfunc_107(MS2Ptr<CDamageRecord>(pRecord), 1.0f);
    SkillAttackData* pAttack = pRecord->FUN_14175a8b0();
    if (pAttack != 0 && pAttack->m_damage.m_nInvokeEffectDisable == 0)
        m_unk_748.FUN_14096fb20(1);
    int nOwnerRel = FUN_1403ed2d0()->FUN_141bd19d0(pRecord->m_nOwnerId);
    int nCasterRel = FUN_1403ed2d0()->FUN_141bd19d0(pRecord->m_nCasterId);
    if (nCasterRel == 1)
        CAutoFindTaxiStation::GetInstance()->FUN_1409f1a00();
    bool bReact = m_unk_748.FUN_140970c10(pRecord->FUN_14175a8b0(), 0) == 0;
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    bool bPush = false;
    if (FUN_14166c930() == 0x2b)
    {
        if (pRecord->FUN_14175a8b0()->m_damage.GetPush(nMapId) != 0 && pRecord->FUN_14175a8b0()->m_eGrabTargetType != 1)
            bPush = true;
        else if (pRecord->FUN_14175a8b0()->m_eGrabTargetType == 2)
            bPush = true;
    }
    else
    {
        if (FUN_14166c930() == 0xd)
        {
            StateHit* pHit = static_cast<StateHit*>(FUN_14166ccb0());
            if (pHit->FUN_1417cb2a0() && pRecord->FUN_14175a8b0()->m_damage.m_nPushPriorityHitImmune != 0)
            {
                int nPriority = pHit->FUN_1417cb2f0();
                if (pRecord->FUN_14175a8b0()->m_damage.m_nPushPriority <= nPriority)
                    bReact = false;
            }
        }
        bool bNoGuard = false;
        if (bReact)
            bNoGuard = FUN_1416538d0(pRecord) == 0;
        bReact = false;
        if (bNoGuard)
            bReact = !FUN_141660120();
    }
    if (pRecord->FUN_14175ac30() < 0 || bPush)
    {
        State* pState = FUN_14166ccb0();
        bool bHit = false;
        if (bReact)
        {
            int nPush = pRecord->FUN_14175a8b0()->m_damage.GetPush(nMapId);
            if ((pState->vfunc_14() != 0 && pRecord->vfunc_1() > vfunc_64()) || nPush != 0)
            {
                MS2Ptr<StateHitData> spData(new StateHitData);
                spData->m_f18 = pRecord->FUN_14175a8b0()->m_damage.m_fHitSpeedRate;
                spData->m_f1c = pRecord->FUN_14175a8b0()->m_damage.m_fHitPauseTime;
                spData->m_f24 = pRecord->FUN_14175a8b0()->m_damage.m_fPushDuration;
                SkillAttackData* pPush = pRecord->FUN_14175a8b0();
                spData->m_f20 = FUN_1416561a0()->FUN_1411e0f90(pPush->m_damage.m_fPushDistance);
                spData->m_f28 = pRecord->FUN_14175a8b0()->m_damage.m_fPushUpDistance;
                spData->m_n2c = pRecord->FUN_14175a8b0()->m_damage.m_nPushDown;
                spData->m_n30 = pRecord->FUN_14175a8b0()->m_damage.m_nPushPriority;
                spData->m_str = pRecord->FUN_14175a8b0()->m_damage.m_strPushAnimation;
                vfunc_59(0xd, spData, 0, spData->m_f24 > 0.0f);
                pState = FUN_14166ccb0();
                bHit = true;
            }
        }
        if (!bHit && (bPush || FUN_14166c930() == 0x2f))
        {
            vfunc_59(1, 0, 0, 0);
            pState = FUN_14166ccb0();
        }
        pState->vfunc_6();
        FUN_141673f70(DAT_1439f8210, DAT_1439f8214, DAT_1439f8218);
        Common::Constants::Value<float>* pVolume;
        if (nCasterRel == 1 || nCasterRel == 2)
            pVolume = &FUN_1401d3200()->VolumeNpcToMyPc;
        else
            pVolume = &FUN_1401d3200()->VolumeNpcToPc;
        float fVolume = pVolume->Read();
        NiPoint3 kPos = vfunc_18();
        int nMaterial = pRecord->FUN_14175ad50();
        FUN_1403ed280()->FUN_1411a5580(nMaterial, 1, nOwnerRel, kPos, fVolume);
    }
    FUN_141671c20(MS2Ptr<CDamageRecord>(pRecord));
    if (FUN_14166ce30())
        FUN_141653740(pRecord->m_nOwnerId, pRecord->m_nCasterId, nOwnerRel, nCasterRel);
    CDPSMeterSystem::GetInstance()->OnDamage(MS2Ptr<CDamageRecord>(pRecord));
    vfunc_113(pRecord);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x1416529f0
void PC::vfunc_34(void* p)
{
    CDotDamageRecord* pRecord = static_cast<CDotDamageRecord*>(p);
    GameObject::vfunc_34(p);
    int nOwnerRel = FUN_1403ed2d0()->FUN_141bd19d0(pRecord->m_nOwnerId);
    int nCasterRel = FUN_1403ed2d0()->FUN_141bd19d0(pRecord->m_nCasterId);
    if (pRecord->FUN_14175ac30() < 0)
    {
        State* pState = FUN_14166ccb0();
        if (m_unk_748.FUN_140970b30() == 0 && pState->vfunc_14() != 0 && pRecord->vfunc_1() > vfunc_64())
        {
            vfunc_59(0xd, 0, 0, 0);
            FUN_14166ccb0();
        }
    }
    FUN_141673f70(DAT_1439f8210, DAT_1439f8214, DAT_1439f8218);
    m_unk_748.FUN_14096fb20(0);
    MS2Ptr<AdditionalCli> spBuff = m_unk_748.FUN_14096fc80(pRecord->m_nEffectLevel);
    bool bNone = !spBuff;
    if (!bNone)
    {
        int nMaterial = spBuff->FUN_14096d810()->m_dotDamage.m_nSoundMaterial;
        if (nMaterial != 0)
        {
            Common::Constants::Value<float>* pVolume;
            if (nCasterRel == 1 || nCasterRel == 2)
                pVolume = &FUN_1401d3200()->VolumeNpcToMyPc;
            else
                pVolume = &FUN_1401d3200()->VolumeNpcToPc;
            float fVolume = pVolume->Read();
            NiPoint3 kPos = vfunc_18();
            FUN_1403ed280()->FUN_1411a5580(nMaterial, 1, nOwnerRel, kPos, fVolume);
        }
    }
    FUN_141672020(MS2Ptr<CDotDamageRecord>(pRecord));
    if (FUN_14166ce30())
        FUN_141653740(pRecord->m_nOwnerId, pRecord->m_nCasterId, nOwnerRel, nCasterRel);
    CDPSMeterSystem::GetInstance()->OnDotDamage(MS2Ptr<CDotDamageRecord>(pRecord));
    vfunc_113(pRecord);
}

// @0x141652e20
void PC::vfunc_35(void* p)
{
    CSplashDamageRecord* pRecord = static_cast<CSplashDamageRecord*>(p);
    GameObject::vfunc_35(p);
    vfunc_107(MS2Ptr<CDamageRecord>(pRecord), 1.0f);
    SkillAttackData* pAttack = pRecord->FUN_14175a8b0();
    if (pAttack != 0 && pAttack->m_damage.m_nInvokeEffectDisable == 0)
        m_unk_748.FUN_14096fb20(1);
    int nOwnerRel = FUN_1403ed2d0()->FUN_141bd19d0(pRecord->m_nOwnerId);
    int nCasterRel = FUN_1403ed2d0()->FUN_141bd19d0(pRecord->m_nCasterId);
    bool bReact = m_unk_748.FUN_140970c10(pRecord->FUN_14175a8b0(), 0) == 0;
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    bool bPush = false;
    if (FUN_14166c930() == 0x2b)
    {
        if (pRecord->FUN_14175a8b0()->m_damage.GetPush(nMapId) != 0 && pRecord->FUN_14175a8b0()->m_eGrabTargetType != 1)
            bPush = true;
        else if (pRecord->FUN_14175a8b0()->m_eGrabTargetType == 2)
            bPush = true;
    }
    else
    {
        if (FUN_14166c930() == 0xd)
        {
            StateHit* pHit = static_cast<StateHit*>(FUN_14166ccb0());
            if (pHit->FUN_1417cb2a0() && pRecord->FUN_14175a8b0()->m_damage.m_nPushPriorityHitImmune != 0)
            {
                int nPriority = pHit->FUN_1417cb2f0();
                if (pRecord->FUN_14175a8b0()->m_damage.m_nPushPriority <= nPriority)
                    bReact = false;
            }
        }
        bool bNoGuard = false;
        if (bReact)
            bNoGuard = FUN_1416538d0(pRecord) == 0;
        bReact = false;
        if (bNoGuard)
            bReact = !FUN_141660120();
    }
    if (pRecord->FUN_14175ac30() < 0 || bPush)
    {
        State* pState = FUN_14166ccb0();
        bool bHit = false;
        if (bReact)
        {
            int nPush = pRecord->FUN_14175a8b0()->m_damage.GetPush(nMapId);
            if ((pState->vfunc_14() != 0 && pRecord->vfunc_1() > vfunc_64()) || nPush != 0)
            {
                MS2Ptr<StateHitData> spData(new StateHitData);
                spData->m_f18 = pRecord->FUN_14175a8b0()->m_damage.m_fHitSpeedRate;
                spData->m_f1c = pRecord->FUN_14175a8b0()->m_damage.m_fHitPauseTime;
                SkillAttackData* pPush = pRecord->FUN_14175a8b0();
                spData->m_f20 = FUN_1416561a0()->FUN_1411e0f90(pPush->m_damage.m_fPushDistance);
                spData->m_f24 = pRecord->FUN_14175a8b0()->m_damage.m_fPushDuration;
                spData->m_f28 = pRecord->FUN_14175a8b0()->m_damage.m_fPushUpDistance;
                spData->m_n2c = pRecord->FUN_14175a8b0()->m_damage.m_nPushDown;
                spData->m_n30 = pRecord->FUN_14175a8b0()->m_damage.m_nPushPriority;
                spData->m_str = pRecord->FUN_14175a8b0()->m_damage.m_strPushAnimation;
                vfunc_59(0xd, spData, 0, spData->m_f24 > 0.0f);
                pState = FUN_14166ccb0();
                bHit = true;
            }
        }
        if (!bHit && bPush)
        {
            vfunc_59(1, 0, 0, 0);
            pState = FUN_14166ccb0();
        }
        pState->vfunc_6();
        FUN_141673f70(DAT_1439f8210, DAT_1439f8214, DAT_1439f8218);
        Common::Constants::Value<float>* pVolume;
        if (nCasterRel == 1 || nCasterRel == 2)
            pVolume = &FUN_1401d3200()->VolumeNpcToMyPc;
        else
            pVolume = &FUN_1401d3200()->VolumeNpcToPc;
        float fVolume = pVolume->Read();
        NiPoint3 kPos = vfunc_18();
        int nMaterial = pRecord->FUN_14175ad50();
        FUN_1403ed280()->FUN_1411a5580(nMaterial, 1, nOwnerRel, kPos, fVolume);
    }
    FUN_1416721d0(MS2Ptr<CSplashDamageRecord>(pRecord));
    if (FUN_14166ce30())
        FUN_141653740(pRecord->m_nOwnerId, pRecord->m_nCasterId, nOwnerRel, nCasterRel);
    CDPSMeterSystem::GetInstance()->OnSplashDamage(MS2Ptr<CSplashDamageRecord>(pRecord));
    vfunc_113(pRecord);
}

// @0x141651bb0
void PC::vfunc_14()
{
    for (size_t i = 0; i < 3; i++)
    {
        efd::SmartPointer<CGuideObject> spGuide = m_spGuide1228[i];
        if (spGuide)
        {
            m_spGuide1228[i]->vfunc_128();
            if (GameObject* pObj = FUN_1403ed2d0()->FUN_141bd0fa0(spGuide->FUN_14123c460()))
                FUN_1403ed2d0()->FUN_141bbb7f0(spGuide, 0);
            FUN_1403ed2d0()->FUN_141bdb5a0(0);
        }
    }
    PCBase::vfunc_14();
}

// @0x141651d00
void PC::vfunc_15()
{
    PCBase::vfunc_15();
    FUN_1411e0810(&m_kEquipDE0);
}
MS2_REPLACE_METHOD(0x141651D00, PC, vfunc_15, 43, 0x5A36F6F9);

// @0x141651d40
void PC::vfunc_16()
{
    PCBase::vfunc_16();
    m_spFD8 = 0;
    FUN_141993180(m_unk_70);
}

// @0x141651d80
// MS2-FUNCTIONAL: the exe calls a different MS2Ptr helper copy (0x141666800) for one smart-pointer test
void PC::vfunc_52(double fTime)
{
    if (GetClassID() != 0x6200016)
        FUN_14123c330(m_unk_748.FUN_1409705d0());
    float fScale = FUN_14123c260() / FUN_14123c2e0();
    if (fScale != m_fScaleA8)
    {
        int bShrink = m_fScaleA8 - fScale > 0.0f ? 0 : 1;
        float fStep = (float)fTime * 3.0f;
        if (bShrink)
            fStep = -fStep;
        fScale += fStep;
        if (bShrink)
        {
            if (fScale < m_fScaleA8)
                fScale = m_fScaleA8;
        }
        else if (fScale > m_fScaleA8)
            fScale = m_fScaleA8;
        FUN_14123c280(fScale * FUN_14123c2e0());
        MS2Ptr<CEquipItem> spItem = FUN_141655e10(1);
        if (spItem.get())
        {
            ATL::CAtlArray<MS2Ptr<CKfmModel> > aModels;
            spItem.get()->FUN_1411dcbb0(&aModels);
            float fNew = FUN_14123c260();
            for (size_t i = 0; i < aModels.GetCount(); i++)
            {
                if (Unk_PCKfmActor* pActor = FUN_14141c720(aModels[i]))
                    pActor->vfunc_22(fNew);
            }
        }
    }
}

// @0x141652030
void PC::vfunc_31(bool enabled)
{
    switch (FUN_14166c930())
    {
    case 0x3f:
        enabled = false;
        break;
    }
    GameObject::vfunc_31(enabled);
}
MS2_REPLACE_METHOD(0x141652030, PC, vfunc_31, 61, 0x5A226AF8);

// @0x141653740
void PC::FUN_141653740(int nTargetId, int nCasterId, int nKind, int nFlag)
{
    if (nKind == 6)
    {
        if (nFlag == 1)
            FUN_1403ed280()->FUN_1411a5770(5, this);
    }
    else
    {
        PCBase* pTarget = FUN_1403ed2d0()->FUN_141bd1290(nTargetId);
        if (nKind == 1 || nKind == 3)
            FUN_1403ed280()->FUN_1411a5770(3, pTarget);
    }
}

// @0x1416537d0
void PC::vfunc_59(int state, StateData* data, int substate, int force)
{
    if (!vfunc_124(state, substate))
        return;
    PCBase::vfunc_59(state, data, substate, force);
}
MS2_REPLACE_METHOD(0x1416537D0, PC, vfunc_59, 94, 0x9CB1080D);

// @0x141653840
int PC::vfunc_124(int a, int b)
{
    __int64 nHp = FUN_141670a00(4);
    __int64 nMaxHp = FUN_141670a30(4);
    if ((FUN_14166ce30() == 0 && (nMaxHp <= 0 || nHp != 0)) || a == 0xc || a == 0x18 || a == 0x3f)
        return 1;
    return 0;
}


// @0x141653ce0
int PC::vfunc_57()
{
    return FUN_1416546d0()->FUN_140a6e640();
}

// MS2-FUNCTIONAL: written from the disassembly (asset preload of an owned item's model files).
// @0x141653d10
void PC::FUN_141653d10(MS2Ptr<CItem> spItem)
{
    m_kListD48.Add(spItem);
    MS2SvrPtr<CItemData> spData(reinterpret_cast<CItemData*>(spItem->FUN_140527840()));
    for (size_t i = 0; i < spData->FUN_14053eba0()->FUN_14054b3d0(); i++)
    {
        const ModelGroup* pGroup = spData->FUN_14053eba0()->FUN_14054b2f0(i);
        for (size_t j = 0; j < pGroup->FUN_1405450c0(); j++)
        {
            const ModelPart* pPart = pGroup->FUN_140544fe0(j);
            if (pPart->isNif != 0 && (pPart->gender == 2 || pPart->gender == FUN_141658e60()))
            {
                if (!FUN_140a0afd0()->FUN_141551db0(CString(pPart->name0)))
                    FUN_140ab7a10()->FUN_141210ac0(CString(pPart->name0));
            }
        }
    }
}

// @0x1416544f0
void PC::vfunc_66(int n)
{
    PCBase::vfunc_66(n);
    if (n != 0)
    {
        m_str9d8 = "defaultBattle";
        if (m_str9e0 == "default")
            FUN_14166ef10(m_str9d8, 0, 0, false);
    }
    else
    {
        m_str9d8 = "default";
        if (m_str9e0 == "defaultBattle")
            FUN_14166ef10(m_str9d8, 0, 0, false);
    }
    m_kEquipDE0.FUN_1411e89d0(n);
    FUN_141659000(0);
    FUN_141670180(false);
    if (n == 1)
    {
        MS2Ptr<CGemBase> spGem = reinterpret_cast<PCGemEquip*>(FUN_14165f460())->FUN_141270740(2);
        if (spGem.get())
            FUN_1403ed2b0()->FUN_141ad9c40(spGem);   // MS2: the exe copies through a converting ctor (0x140d40c90)
    }
}

// @0x1416546d0
JobSystemCli* PC::FUN_1416546d0()
{
    return m_spJobFB8.get();
}

// @0x141654700
int PC::FUN_141654700()
{
    return m_spJobFB8->FUN_140639340();
}

// @0x141654730
int PC::FUN_141654730()
{
    return m_spJobFB8->FUN_1406393f0();
}

// @0x141654760
int PC::FUN_141654760()
{
    return m_spJobFB8->FUN_1406394b0();
}

// @0x141654790
void PC::FUN_141654790()
{
    FUN_141679760();
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangeJob(this)));
}

// @0x141654840
int PC::vfunc_64() { return 0; }
MS2_REPLACE_METHOD(0x141654840, PC, vfunc_64, 8, 0x7F371472);

// @0x141654850
int PC::vfunc_99(int n)
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee)
        return spRidee->vfunc_99(n);
    return PCBase::vfunc_99(n);
}

// @0x141655a30
int PC::vfunc_118(const NiPoint3& kPos, float* pDist, CString* pName)
{
    *pDist = 3.402823466e+38f;
    for (POSITION pos = m_unk_b88.GetHeadPosition(); pos; m_unk_b88.GetNext(pos))
    {
        CString strName = m_unk_b88.GetKeyAt(pos);
        float fDist = (m_unk_b88.GetValueAt(pos)->GetWorldTranslate() - kPos).Length();
        if (fDist < *pDist)
        {
            *pDist = fDist;
            *pName = strName;
        }
    }
    return 1;
}

// @0x141655b80
MS2Ptr<CItem> PC::FUN_141655b80(__int64 nItemUid)
{
    MS2Ptr<CEquipItem> spEquip = FUN_141655c30(nItemUid);
    if (!spEquip)
        return MS2Ptr<CItem>(0);
    return spEquip->FUN_1411dc7a0();
}

// @0x141655c30
MS2Ptr<CEquipItem> PC::FUN_141655c30(__int64 nItemUid)
{
    return m_kEquipDE0.FUN_1411e1580(nItemUid);
}

// @0x141655c90
MS2Ptr<CEquipItem> PC::FUN_141655c90(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, 0);
}

// @0x141655cf0
MS2Ptr<CEquipItem> PC::FUN_141655cf0(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, 1);
}

// @0x141655d50
MS2Ptr<CEquipItem> PC::FUN_141655d50(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, 5);
}

// @0x141655db0
MS2Ptr<CEquipItem> PC::FUN_141655db0(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, 4);
}

// @0x141655e10
MS2Ptr<CEquipItem> PC::FUN_141655e10(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1860(nSlot, 6, 0);
}

// @0x141655e80
MS2Ptr<CEquipItem> PC::FUN_141655e80(int nSlot, int nKind)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, nKind);
}

// @0x1416561a0
Unk_PCEquipSet* PC::FUN_1416561a0() { return &m_kEquipDE0; }
MS2_REPLACE_METHOD(0x1416561A0, PC, FUN_1416561a0, 17, 0x1D689B1E);

// @0x1416561c0
Unk_PCItemCooldowns* PC::FUN_1416561c0()
{
    return reinterpret_cast<Unk_PCItemCooldowns*>(&m_kItemsF78);
}

// @0x1416561e0
void PC::vfunc_120(MS2Ptr<RideOnAction> spAction)
{
    PCBase::vfunc_120(spAction);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangePcRidee(this)));
}

// @0x1416562d0
void PC::vfunc_121(MS2Ptr<RideOffAction> spAction)
{
    PCBase::vfunc_121(spAction);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangePcRidee(this)));
}

// @0x1416563c0
void PC::vfunc_127(CItem* pItem, int n)
{
    if (!pItem)
        return;
    if (pItem->FUN_140527840()->FUN_14053ec50() != 0)
    {
        if (n == 0 && FUN_1409f7c90()->FUN_1409f7ea0())
            m_kEquipDE0.FUN_1411e38e0(MS2Ptr<CItem>(pItem));
        else
            m_kEquipDE0.FUN_1411e3600(MS2Ptr<CItem>(pItem));
        FUN_141656710();
    }
}

// @0x1416564a0
void PC::vfunc_128(CItem* pItem, int n)
{
    if (!pItem)
        return;
    if (pItem->FUN_140527840()->FUN_14053ec50() != 0)
    {
        if (n == 0 && FUN_1409f7c90()->FUN_1409f7ea0())
            m_kEquipDE0.FUN_1411e3b10(MS2Ptr<CItem>(pItem), 0);
        else
            m_kEquipDE0.FUN_1411e3960(MS2Ptr<CItem>(pItem), 0);
        FUN_141656710();
    }
}

// @0x141656580
void PC::FUN_141656580(MS2Ptr<CItem> spItem, __int64 n)
{
    m_kEquipDE0.FUN_1411e37f0(spItem, n);
}

// @0x1416565f0
void PC::FUN_1416565f0(MS2Ptr<CItem> spItem, int n)
{
    m_kEquipDE0.FUN_1411e3960(spItem, n);
}

// @0x141656660
void PC::FUN_141656660(MS2Ptr<CEquipItem> spItem, int n)
{
    m_kEquipDE0.FUN_1411e3bd0(spItem, n);
}

// @0x1416566d0
void PC::FUN_1416566d0(int n) { m_nD68 = n; }

// @0x1416566f0
int PC::FUN_1416566f0() { return m_nD68; }

// @0x141656710
void PC::FUN_141656710()
{
    FUN_141653f00();
    m_unk_748.FUN_140971150();
}

// @0x141656750
int PC::FUN_141656750()
{
    return m_kEquipDE0.FUN_1411e09a0();
}

// @0x1416569b0
int PC::FUN_1416569b0(CItem* pItem)
{
    if (pItem->FUN_140527840()->FUN_14053d460())
        return 5;
    if (pItem->FUN_140527840()->FUN_14053d510())
    {
        if (pItem->FUN_140526c30() != 0)
            return pItem->FUN_140526c30();
    }
    else if (pItem->FUN_140527840()->FUN_14053d2b0())
        return 8;
    return pItem->FUN_140527a20();
}

// @0x141656a50
void PC::FUN_141656a50(__int64 nCharId) { m_nCharIdDB8 = nCharId; }

// @0x141656a80
__int64 PCBase::FUN_141656a80() { return static_cast<PC*>(this)->m_nCharIdDB8; }

// @0x141656aa0
void PC::FUN_141656aa0(__int64 nAccountId) { m_nAccountIdDC0 = nAccountId; }

// @0x141656ad0
__int64 PC::FUN_141656ad0() { return m_nAccountIdDC0; }

// @0x141656af0
void PC::vfunc_74(__int64 nCur, __int64 nMax)
{
    PCBase::vfunc_74(nCur, nMax);
    if (FUN_14165ef30())
    {
        if (Unk_PCDialog4e96* pParty = FUN_141531c80(0x4e96))
            pParty->FUN_141a92b10(FUN_141656a80(), nCur, nMax);
        if (Unk_PCDialog4ec4* pRaid = FUN_141531be0(0x4ec4))
            pRaid->FUN_14133afb0(FUN_141656a80(), nCur, nMax);
    }
}

// @0x141656ba0
// MS2-FUNCTIONAL: the exe assigns through a CStringW temporary (two calls); a plain operator= is one
void PC::vfunc_129(const CStringW& str) { m_strNameDC8 = str; }

// @0x141656be0
CStringW& PC::FUN_141656be0() { return m_strNameDC8; }

// @0x141656c00
void PC::vfunc_130(CStringA str) { m_strDD0 = str; }

// @0x141656c50
CStringA& PC::FUN_141656c50() { return m_strDD0; }

// @0x141656c70
CStringW PC::vfunc_77()
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee)
    {
        MS2Ptr<Unk_RideeData> spData = spRidee->FUN_141707750();
        if (spData.get() && spData->m_nAC != 0)
            return FUN_1401a9d70()->FUN_141811980(0x31, spData->m_nNameId);
    }
    return PCBase::vfunc_77();
}

// @0x141656d90
CStringW& PC::FUN_141656d90() { return m_strName1030; }

// @0x141656f80
MS2Ptr<Unk_PCBaseComp_a68> PC::vfunc_81()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a68>(0);
    if (Unk_PCLocalPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0())
    {
        if (pPlayer->FUN_1415278d0(FUN_141656a80()) == 0)
            return MS2Ptr<Unk_PCBaseComp_a68>(0);
        if (!FUN_1409a8b10()->FUN_140b123b0()->m_bShowPartyHp)
            return MS2Ptr<Unk_PCBaseComp_a68>(0);
    }
    if (m_spA68 == 0)
        m_spA68 = FUN_140e86320(m_unk_70);
    return m_spA68;
}

// @0x141657100
MS2Ptr<Unk_PCBaseComp_a78> PC::vfunc_82()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a78>(0);
    if (m_spA78.get())
        return m_spA78;
    if ((m_spA78 = FUN_141a60da0(m_unk_70)).get())
    {
        m_spA78->FUN_141a5e4c0(0x12);
        m_spA78->FUN_141a5e500(FUN_140a7d630(&static_cast<Client::Constants*>(FUN_1401d3200())->NameTagColorFriendly));
        m_spA78->vfunc_2();
    }
    return m_spA78;
}

// @0x1416572b0
MS2Ptr<Unk_PCBaseComp_a98> PC::vfunc_84()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a98>(0);
    if (m_spA98 == 0)
        m_spA98 = FUN_14128ef70(m_unk_70);
    return m_spA98;
}

// @0x1416573b0
MS2Ptr<Unk_PCBaseComp_aa8> PC::vfunc_85()
{
    if (m_spAA8 == 0)
        m_spAA8 = FUN_1418fbdb0(m_unk_70);
    return m_spAA8;
}

// @0x141657470
MS2Ptr<Unk_PCBaseComp_ab8> PC::vfunc_86()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_ab8>(0);
    if (m_spAB8 == 0)
    {
        if (m_spAB8 = FUN_141a8fb50(m_unk_70))
            m_spAB8->vfunc_2();
    }
    return m_spAB8;
}

// @0x1416575b0
MS2Ptr<Unk_PCBaseComp_ac8> PC::vfunc_87()
{
    if (m_spAC8 == 0)
        m_spAC8 = FUN_140ba8cf0(m_unk_70);
    return m_spAC8;
}

// @0x141657670
MS2Ptr<Unk_PCBaseComp_a88> PC::vfunc_83()
{
    if (m_spA88 == 0)
        m_spA88 = FUN_14192fd40(m_unk_70);
    return m_spA88;
}

// @0x141657730
MS2Ptr<Unk_PCLinkFD8> PC::FUN_141657730()
{
    if (FUN_141661970())
        return MS2Ptr<Unk_PCLinkFD8>(0);
    if (m_spFD8 == 0)
        m_spFD8 = FUN_141993100(m_unk_70);
    return m_spFD8;
}

// @0x141657820
void PC::vfunc_131(short n)
{
    m_nLevelDDC = n;
    FUN_141a60f00(m_unk_70);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangeLevel(this)));
}

// @0x1416578f0
int PC::vfunc_78() { return m_nLevelDDC; }

// @0x141657910
// MS2-FUNCTIONAL: the exe frame is 0x30 bytes larger (value temporaries in the 0x23-stat path)
void PC::vfunc_90(void* p)
{
    unsigned char nCount = static_cast<CInPacket*>(p)->vfunc_o8_1();
    if (nCount == 0x23)
    {
        for (int i = 0; i < 3; i++)
        {
            FUN_141670540(i, 4, static_cast<CInPacket*>(p)->vfunc_o8_4());
            FUN_141670540(i, 0xd, (unsigned)static_cast<CInPacket*>(p)->vfunc_o8_3());
            FUN_141670540(i, 0xe, (unsigned)static_cast<CInPacket*>(p)->vfunc_o8_3());
            FUN_141670540(i, 0x20, (unsigned)static_cast<CInPacket*>(p)->vfunc_o8_3());
            FUN_141670540(i, 0x16, (unsigned)static_cast<CInPacket*>(p)->vfunc_o8_3());
        }
    }
    else
    {
        for (int n = 0; n < nCount; n++)
        {
            unsigned char nType = static_cast<CInPacket*>(p)->vfunc_o8_1();
            for (int i = 0; i < 3; i++)
            {
                __int64 nValue;
                if (FUN_14082f1a0(nType) == 0)
                    nValue = (unsigned)static_cast<CInPacket*>(p)->vfunc_o8_3();
                else
                    nValue = static_cast<CInPacket*>(p)->vfunc_o8_4();
                FUN_141670540(i, nType, nValue);
            }
        }
    }
}

// @0x141657c40
void PC::vfunc_91(void* p) { vfunc_90(p); }

// @0x141657dc0
int PC::vfunc_133(CItem* pItem, bool bForce) { return vfunc_132(pItem, pItem->FUN_140527a20(), bForce); }

// @0x141657e20
// MS2-FUNCTIONAL: one smart-pointer temporary too many on the slot 4/5 fallback path
int PC::vfunc_132(CItem* pItem, int nSlot, bool bForce)
{
    int nResult = 0;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return nResult;
    if (!bForce && !spData->FUN_14053cf90())
        return nResult;
    if (spData->FUN_14053d2f0())
    {
        if (spData->FUN_14053d460())
        {
            MS2Ptr<CEquipItem> spEquip = FUN_141655c90(5);
            if (spEquip.get())
                nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
            if (nResult == 0)
            {
                spEquip = FUN_141655c90(4);
                if (spEquip.get())
                    nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
            }
        }
        else if (spData->FUN_14053d510())
        {
            MS2Ptr<CEquipItem> spEquip = FUN_141655c90(nSlot);
            if (spEquip.get())
                nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
        }
        else if (spData->FUN_14053d340())
        {
            if (spData->FUN_14053eba0()->FUN_14054b450(5))
            {
                MS2Ptr<CEquipItem> spEquip = FUN_141655c90(5);
                if (spEquip.get())
                    nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
            }
            else
            {
                MS2Ptr<CEquipItem> spEquip = FUN_141655c90(4);
                if (spEquip.get())
                    nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
            }
        }
    }
    return nResult;
}

// @0x141658a30
CString PC::vfunc_60()
{
    if (m_nD80 != 0 && (m_spWeaponActionD70.get() ? true : false))
        return m_spWeaponActionD70->m_strPrefix;
    else
    {
        bool bHasSet = !FUN_1416561a0()->FUN_1411eabd0().IsEmpty();
        if (bHasSet)
            return FUN_1416561a0()->FUN_1411eabd0();
        else
            return CString("");
    }
}

// @0x141658b80
int PC::vfunc_61()
{
    if (m_nD80 != 0 && (m_spWeaponActionD70.get() ? true : false))
        return 1;
    else
    {
        bool bHasSet = !FUN_1416561a0()->FUN_1411eabd0().IsEmpty();
        if (bHasSet)
            return 2;
    }
    return 0;
}

// @0x141658c40
bool PC::vfunc_62()
{
    bool bHasSet = !FUN_1416561a0()->FUN_1411eabd0().IsEmpty();
    if (bHasSet)
        return FUN_1416561a0()->FUN_1411eac20();
    return false;
}

// @0x141658cd0
CStringW PC::vfunc_134() { return CStringW(L""); }
MS2_REPLACE_METHOD(0x141658CD0, PC, vfunc_134, 61, 0xE16DABBF);

// @0x141658d20
CString PC::FUN_141658d20()
{
    CString strPrefix;
    do
    {
        if (FUN_14166c930() != 0x10)
            break;
        StateSkill* pState = static_cast<StateSkill*>(FUN_14166ccb0());
        if (pState == 0)
            break;
        MS2Ptr<CSkillRecord> spSkill = pState->FUN_1417ed6f0();
        if (!spSkill)
            break;
        Unk_PCSkillMotion* pMotion = reinterpret_cast<Unk_PCSkillRecord*>(spSkill.operator->())->FUN_141759830();
        if (pMotion == 0)
            break;
        strPrefix = pMotion->m_strWeaponSequenceName;
    } while (0);
    return strPrefix;
}

// @0x141658e40
void PC::FUN_141658e40(int nGender) { m_nGenderDD8 = nGender; }

// @0x141658e60
int PC::FUN_141658e60() { return m_nGenderDD8; }

// @0x141658e80
void PC::FUN_141658e80(__int64 nValue) { m_nFE8 = nValue; }

// @0x141658eb0
__int64 PC::FUN_141658eb0() { return m_nFE8; }

// @0x141658ed0
void PC::FUN_141658ed0(unsigned char n)
{
    m_nFF8 = n;
    m_kEquipDE0.FUN_1411e7610();
}

// @0x141658f10
unsigned char PC::FUN_141658f10() { return m_nFF8; }

// @0x141658f30
int PC::FUN_141658f30() { return m_nFF8 > 0; }

// @0x141658f70
void PC::FUN_141658f70(unsigned char flags) { m_nFF9 |= flags; }
MS2_REPLACE_METHOD(0x141658F70, PC, FUN_141658f70, 42, 0xE44E913E);

// @0x141658fa0
unsigned char PC::FUN_141658fa0() { return m_nFF9; }

// @0x141658fc0
void PC::FUN_141658fc0(const egf::EntityID& kId) { m_entityDB0 = kId; }

// @0x1416591e0
void PC::FUN_1416591e0(int nSlot, const NiColor& kColor) { m_colorD98[nSlot] = kColor; }

// @0x141659220
const NiColor& PC::FUN_141659220(int nSlot) { return m_colorD98[nSlot]; }

// @0x1416595b0
int PC::FUN_1416595b0() { return m_nCubeModeFFC; }

// @0x1416595d0
int PC::FUN_1416595d0() { return m_nCubeModeFFC != 0; }

// @0x141659610
int PC::FUN_141659610() { return m_nCubeModeFFC == 1; }

// @0x141659650
int PC::FUN_141659650() { return m_nCubeModeFFC == 2; }

// @0x141659690
int PC::FUN_141659690()
{
    if (FUN_141659700() == 0)
        return 0;
    return FUN_141659700()->FUN_1410a8ab0();
}

// @0x1416596d0
int PC::FUN_1416596d0()
{
    if (m_nCubeModeFFC == 1)
        return 1;
    return 0;
}

// @0x141659700
Unk_PCCubeCraft* PC::FUN_141659700() { return m_pCubeCraft; }
MS2_REPLACE_METHOD(0x141659700, PC, FUN_141659700, 18, 0x829A31E1);

// @0x141659720
void PC::FUN_141659720()
{
    if (FUN_1416595d0() == 0)
        return;
    if (m_pCubeCraft == 0)
        return;
    m_pCubeCraft->FUN_1410ac960();
}

// @0x141659770
void PC::FUN_141659770(bool b, const CString& strKind) {}

// @0x14165eb80
float PC::FUN_14165eb80() { return FUN_1416713c0() * m_f1180; }

// @0x14165ebb0
void PC::FUN_14165ebb0(float f) { m_f1180 = f; }

// @0x14165ef30
int PC::FUN_14165ef30() { return FUN_140967420()->FUN_140743550(); }

// @0x14165efa0
void PC::vfunc_139()
{
    NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410());
    if (pRoot == 0)
        return;
    // the third argument is the colour (FittingDollPC's override declares it as Unk_CharEquip*)
    vfunc_138(pRoot, 0, reinterpret_cast<const Unk_CharEquip*>(&FUN_141659220(0)));
    vfunc_138(pRoot, 2, reinterpret_cast<const Unk_CharEquip*>(&FUN_141659220(1)));
}

// @0x14165f050
void PC::vfunc_138(NiAVObject* root, int kind, const Unk_CharEquip* equipment)
{
    FUN_141b6f220(root, kind, equipment);
}
MS2_REPLACE_METHOD(0x14165F050, PC, vfunc_138, 48, 0xB5D4861C);

// @0x14165f090
void PC::FUN_14165f090(int n) { m_n1038 = n; }

// @0x14165f0b0
void PC::FUN_14165f0b0(MS2Ptr<CItem> spItem) { m_spItem1040 = spItem; }

// @0x14165f100
Unk_MyPCEmotion* PC::FUN_14165f100() { return reinterpret_cast<Unk_MyPCEmotion*>(m_spItem1040.get()); }   // the held item

// @0x14165f130
void PC::FUN_14165f130(int n) { m_n1050 = n; }

// @0x14165f150
int PC::FUN_14165f150() { return m_n1050; }

// @0x14165f170
void PC::FUN_14165f170()
{
    if (FUN_14165f100() == 0)
        return;
    FUN_14165f1f0(0, 0);
    COutPacket packet(0x37, 0);
    packet.Encode1(0x12);
    FUN_140710590(packet);
}

// @0x14165f460
Unk_MyPCEquip* PC::FUN_14165f460() { return reinterpret_cast<Unk_MyPCEquip*>(&m_kGemEquip1078); }

// @0x14165fec0
void PC::vfunc_113(void* data)
{
    PCBase::vfunc_113(data);
    m_n1200 = FUN_140869420();
}
MS2_REPLACE_METHOD(0x14165FEC0, PC, vfunc_113, 50, 0x3953A97A);

// @0x14165ff00
void PC::vfunc_71(MS2Ptr<Unk_PCBaseFxSet> spSet)
{
    PCBase::vfunc_71(spSet);
    FUN_141659770(spSet->m_bLoop28, s_strEmotion);
}

// @0x14165ff80
void PC::vfunc_72()
{
    PCBase::vfunc_72();
    FUN_141659770(false, s_strEmotion);
}

// @0x14165ffc0
void PC::FUN_14165ffc0(int n) { m_n11cc = n; }

// @0x14165ffe0
int PC::FUN_14165ffe0() { return m_n11cc; }

// @0x141660000
void PC::FUN_141660000(__int64 nValue) { m_n11e8 = nValue; }

// @0x141660030
int PC::FUN_141660030()
{
    if (m_n11e8 == 0)
        return 0;
    CMsTime kNow(FUN_140869440());
    CMsTime kStamp(m_n11e8);
    return kNow.GetMonth() == kStamp.GetMonth();
}

// @0x1416600c0
void PC::vfunc_140(int n)
{
    m_n1208 = n;
    FUN_141a60f00(m_unk_70);
}

// @0x141660100
int PC::vfunc_141() { return m_n1208; }

// @0x1416612e0
CString PC::FUN_1416612e0() { return m_str1028; }

// @0x141661330
void PC::FUN_141661330(const CStringW& strName) { m_strName1030 = strName; }

// @0x141661820
void PC::FUN_141661820(int nSkillId, short nLevel, std::set<int>& kVisited, std::set<int>& kFound) {}

// @0x141661840
void PC::FUN_141661840(int nSkillId, short nLevel) {}

// @0x141661860
int PC::FUN_141661860() { return m_n1000; }

// @0x141661970
int PC::FUN_141661970()
{
    if (m_n10ec > 0 || m_n10f0 != 0)
        return 1;
    if (m_unk_748.FUN_140970ad0())
        return 1;
    return 0;
}

// @0x1416619d0
void PC::FUN_1416619d0(unsigned int nEnd)
{
    m_n10e8 = nEnd;
    if (FUN_1409613d0(this))
    {
        if (Unk_PCMainPlayerInfo* pInfo = FUN_140931900(0x4e5f))
        {
            if (nEnd > 0)
                pInfo->FUN_1419f1200(0x5f5e103, FUN_141661a80());
            else
                pInfo->FUN_1419f1370(0x5f5e103);
        }
    }
}

// @0x141661a60
void PC::FUN_141661a60(int n) { m_n10ec = n; }

// @0x141661a80
unsigned int PC::FUN_141661a80() { return m_n10e8; }

// @0x141661aa0
int PC::FUN_141661aa0() { return m_n10ec; }

// @0x141661ac0
void PC::FUN_141661ac0()
{
    unsigned int nEnd = FUN_141661a80();
    if (nEnd == 0)
        return;
    unsigned int nNow = FUN_141472bc0();
    if (nNow >= nEnd)
    {
        FUN_141661a60(0);
        FUN_1416619d0(0);
    }
}

// @0x141661ba0
void PC::FUN_141661ba0(int n) { m_n10f0 = n; }

// @0x141661bc0
int PC::FUN_141661bc0() { return m_nFF0; }

// @0x141661c00
void PC::FUN_141661c00(CInPacket& packet) { m_n10f4 = packet.vfunc_o8_3(); }

// @0x141661c50
int PC::FUN_141661c50() { return m_n10f4; }

// @0x141661dc0
void PC::FUN_141661dc0(unsigned short nA, int nB)
{
    m_n10f8 = nA;
    m_n10fc = nB;
}

// @0x141661e00
unsigned short PCBase::FUN_141661e00() { return static_cast<PC*>(this)->m_n10f8; }

// @0x141661e20
int PCBase::FUN_141661e20() { return static_cast<PC*>(this)->m_n10fc; }

// @0x1416623d0
void PC::FUN_1416623d0(efd::SmartPointer<CGuideObject> spGuide, int nIndex)
{
    if (nIndex < 0 || nIndex >= 3)
        return;
    m_spGuide1228[nIndex] = spGuide;
}

// @0x141662440
CGuideObject* PC::FUN_141662440(int nIndex)
{
    if (nIndex < 0 || nIndex >= 3)
        return 0;
    return m_spGuide1228[nIndex];
}

// @0x141662490
int PC::FUN_141662490(int nIndex) { return FUN_141662440(nIndex) != 0; }

// @0x1416625b0
CConstructionGuideObject* PC::FUN_1416625b0() { return efd::DynamicCast<CConstructionGuideObject>(FUN_141662440(0)); }

// @0x1416625e0
CFishingGuideObject* PC::FUN_1416625e0() { return efd::DynamicCast<CFishingGuideObject>(FUN_141662440(1)); }

// @0x141662610
CSkillMagicControlGuide* PC::FUN_141662610() { return efd::DynamicCast<CSkillMagicControlGuide>(FUN_141662440(2)); }

// @0x141662640
void PC::FUN_141662640(__int64 nValue) { m_n1140 = nValue; }

// @0x141662670
__int64 PC::FUN_141662670() { return m_n1140; }

// @0x141662690
void PC::FUN_141662690(int nValue) { m_n1148 = nValue; }

// @0x1416626b0
int PC::FUN_1416626b0()
{
    if (FUN_14086ae10(m_n1140))
    {
        m_n1140 = FUN_140869440();
        m_n1148 = 0;
    }
    return m_n1148;
}

// @0x141662710
void PC::FUN_141662710(int nValue) { m_n114c = nValue; }

// @0x141662730
int PC::FUN_141662730() { return m_n114c; }

// @0x141662750
unsigned int PC::FUN_141662750(int nIndex)
{
    if (nIndex < 0 || nIndex >= 12)
        return 0;
    return m_aMastery1150[nIndex];
}

// @0x141662790
void PC::FUN_141662790(int nIndex, int nValue)
{
    if (nIndex < 0 || nIndex >= 12)
        return;
    m_aMastery1150[nIndex] = nValue;
}

// @0x1416627d0
int PC::FUN_1416627d0(int nIndex)
{
    if (nIndex < 0 || nIndex >= 12)
        return 0;
    return FUN_1409670c0()->Grade(nIndex, m_aMastery1150[nIndex]);
}

// @0x141662830
int PC::FUN_141662830() { return m_n1184; }

// @0x141662850
void PC::FUN_141662850(__int64 nValue) { m_n1184 = nValue; }

// @0x141662870
int PC::FUN_141662870() { return m_n1188; }

// @0x141662890
void PC::FUN_141662890(__int64 nValue) { m_n1188 = nValue; }

// @0x1416628b0
float PC::FUN_1416628b0(int nOption, unsigned nKey) { return m_kEquipDE0.FUN_1411e1250(nOption, nKey); }

// @0x1416628f0
float PC::FUN_1416628f0(int nOption, unsigned nKey) { return m_kEquipDE0.FUN_1411e13e0(nOption, nKey); }

// @0x141662930
float PC::FUN_141662930(int nSpecial)
{
    if (!FUN_14081dcd0(nSpecial))
        return 0;
    return m_kEquipDE0.FUN_1411e1110(nSpecial);
}

// @0x141662980
int PC::FUN_141662980(int nSpecial)
{
    if (!FUN_14081dc50(nSpecial))
        return 0;
    return m_kEquipDE0.FUN_1411e1160(nSpecial);
}

// @0x141662d60
void PC::FUN_141662d60(__int64 nValue)
{
    m_n1190 = nValue;
    FUN_1416561a0()->FUN_1411e7680();
}

// @0x141662da0
void PC::FUN_141662da0(int n)
{
    m_n1198 = n;
    FUN_1416561a0()->FUN_1411e7680();
}

// @0x141662de0
unsigned PC::FUN_141662de0()
{
    return m_n1198 != 0 || m_n1190 > FUN_140869440();
}

// @0x141662e30
void PC::FUN_141662e30(int n) { m_n1220 = n; }

// @0x141662e50
bool PC::vfunc_146()
{
    switch (m_n1220)
    {
    case 2:
    case 3:
    case 4:
        return true;
    }
    return false;
}

// @0x141662e90
__int64 PC::FUN_141662e90() { return m_n1190; }

// @0x141663040
int PC::FUN_141663040() { return m_nD80; }

// @0x141663060
void PC::FUN_141663060(int n) { m_n119c = n; }

// @0x141663080
int PC::FUN_141663080() { return m_n119c; }

// @0x1416630a0
void PC::FUN_1416630a0(int n) { m_n11a0 = n; }

// @0x1416630c0
int PC::FUN_1416630c0() { return m_n11a0; }

// @0x1416630e0
void PC::FUN_1416630e0(unsigned int nId) { m_set11a8.insert(nId); }

// @0x141663120
void PC::FUN_141663120(unsigned int nId) { m_set11a8.erase(nId); }

// @0x141663400
void PC::FUN_141663400(MS2Ptr<CItem> spItem) { m_spItem11b8 = spItem; }

// @0x141663450
MS2Ptr<CItem> PC::FUN_141663450() { return m_spItem11b8; }

// @0x1416634a0
void PC::FUN_1416634a0(__int64 nCharId)
{
    if (m_spCouple11d8.get() != 0)
        m_spCouple11d8->FUN_140b0ead0(nCharId);
}

// @0x141663500
void PC::FUN_141663500(int nObjectId)
{
    if (m_spCouple11d8.get() != 0)
        m_spCouple11d8->FUN_140b0eba0(nObjectId);
}

// @0x141663620
void PC::FUN_141663620()
{
    if (m_spCouple11d8.get())
        m_spCouple11d8->FUN_140b0ed30();
    else
        m_n11d0 = 1;
}

// @0x141663680
void PC::FUN_141663680()
{
    if (m_spCouple11d8.get())
        m_spCouple11d8->FUN_140b0eed0();
    else
        m_n11d0 = 0;
}

// @0x141663870
void PC::FUN_141663870()
{
    m_spCouple11d8 = 0;
    m_n11d0 = 0;
}

// @0x1416638b0
CStringW PC::FUN_1416638b0()
{
    if (m_spCouple11d8.get())
        return m_spCouple11d8->FUN_140b0ec30();
    return CStringW(L"");
}

// @0x141663940
int PC::FUN_141663940()
{
    if (m_spCouple11d8.get())
        return m_spCouple11d8->FUN_140b0ec10();
    return 0;
}

// @0x141663990
__int64 PC::FUN_141663990()
{
    if (m_spCouple11d8.get())
        return m_spCouple11d8->FUN_140b0ec80();
    return 0;
}

// @0x1416639e0
int PC::FUN_1416639e0() { return m_n11f0; }

// @0x141663a00
void PC::FUN_141663a00(int n) { m_n11f0 = n; }

// @0x141663a20
int PC::FUN_141663a20()
{
    if (FUN_141663ac0())
    {
        m_n11f4 = 0;
        m_n11f8 = FUN_140869440();
    }
    return m_n11f4;
}

// @0x141663a70
void PC::FUN_141663a70(int n) { m_n11f4 = n; }

// @0x141663a90
void PC::FUN_141663a90(__int64 n) { m_n11f8 = n; }

// @0x141663ac0
int PC::FUN_141663ac0()
{
    if (m_n11f8 == 0)
        return 1;
    if (FUN_14086ace0(m_n11f8))
        return 1;
    return 0;
}

// @0x141663b10
void PC::FUN_141663b10(short n)
{
    m_n120c = n;
    FUN_141a60f00(FUN_14123c580());
}

// @0x141663b50
short PC::FUN_141663b50() { return m_n120c; }

// @0x141663b70
void PC::FUN_141663b70(unsigned int nId) { m_set1210.insert(nId); }

// @0x141663bb0
void PC::FUN_141663bb0(unsigned int nId) { m_set1210.erase(nId); }

// @0x141663be0
void PC::FUN_141663be0(const NiFixedString& kSequence, float fSpeed, const NiFixedString& kTextKey)
{
    std::set<unsigned int>::iterator it;
    for (it = m_set1210.begin(); it != m_set1210.end(); ++it)
    {
        GameObject* pObj = FUN_1403ed2d0()->FUN_141bd1180(*it);
        if (pObj == 0)
            continue;
        CEffectObject* pEffect = dynamic_cast<CEffectObject*>(pObj);
        if (pEffect == 0)
            continue;
        pEffect->FUN_140a539d0(kSequence, fSpeed, kTextKey);
    }
}

// @0x141663d00
void PC::FUN_141663d00(efd::Point3 kDir)
{
    std::set<unsigned int>::iterator it;
    for (it = m_set1210.begin(); it != m_set1210.end(); ++it)
    {
        GameObject* pObj = FUN_1403ed2d0()->FUN_141bd1180(*it);
        if (pObj == 0)
            continue;
        CEffectObject* pEffect = dynamic_cast<CEffectObject*>(pObj);
        if (pEffect == 0)
            continue;
        pEffect->FUN_140a53b30(kDir);
    }
}

// @0x141663e20
void PC::FUN_141663e20(int nCount, int nTailId)
{
    if (m_spTailEffect1270 == 0)
        return;
    m_spTailEffect1270->FUN_140ad00e0(nCount);
    m_spTailEffect1270->FUN_140ad0120(nTailId);
}

// @0x141663ea0
void PC::FUN_141663ea0()
{
    if (m_spTailEffect1270 == 0)
        return;
    m_spTailEffect1270->FUN_140ad01d0();
}

// @0x141663ef0
void PC::FUN_141663ef0(AdditionalCli* pCli)
{
    if (pCli->FUN_14096d810()->m_nTailEffect == 0)
        return;
    AdditionalLevelData* pData = pCli->FUN_14096d810();
    MS2SvrPtr<TailEffectData> spData = FUN_140ad0da0()->GetData(pData->m_nTailEffect);
    if (spData == 0)
        return;
    MS2Ptr<CTailEffectObject> spTail(0);
    m_mapTail1280.Lookup(pCli->FUN_14096d2a0(), spTail);
    if (spTail.get())
        return;
    spTail.AssignRaw(new CTailEffectObjectFromAdditional(this, spData, pCli->FUN_14096d2a0()));
    spTail->FUN_140ad00e0(pCli->m_nOverlapCount);
    m_mapTail1280.SetAt(pCli->FUN_14096d2a0(), spTail);
}

// @0x1416640d0
void PC::FUN_1416640d0(AdditionalCli* pCli)
{
    MS2Ptr<CTailEffectObject> spTail(0);
    m_mapTail1280.Lookup(pCli->FUN_14096d2a0(), spTail);
    if (spTail.get())
        spTail->FUN_140ad00e0(pCli->m_nOverlapCount);
}

// @0x141664160
void PC::FUN_141664160(AdditionalCli* pCli)
{
    MS2Ptr<CTailEffectObject> spTail(0);
    m_mapTail1280.Lookup(pCli->FUN_14096d2a0(), spTail);
    if (spTail.get())
    {
        spTail->FUN_140ad01d0();
        m_mapTail1280.RemoveKey(pCli->FUN_14096d2a0());
    }
}

// @0x141664200
MS2Ptr<Unk_HsInfo> PC::FUN_141664200() { return reinterpret_cast<const MS2Ptr<Unk_HsInfo>&>(m_spHideAndSeek1250); }

// @0x141664250
MS2Ptr<Unk_PCWaterGunInfo> PC::FUN_141664250() { return reinterpret_cast<const MS2Ptr<Unk_PCWaterGunInfo>&>(m_spWaterGun1260); }

// @0x1416642a0
bool PC::FUN_1416642a0() { return m_b1224; }

// @0x1416642c0
void PC::FUN_1416642c0(bool b) { m_b1224 = b; }

// @0x141657c80
// MS2-FUNCTIONAL: the exe frame is 0x10 bytes larger (another loop temporary); same calls
void PC::FUN_141657c80(bool bEnable)
{
    if (m_nD80 != bEnable)
        m_nD80 = bEnable;
    ATL::CAtlArray<CEquipModel*> kEffects;
    ATL::CAtlArray<CString> kNodes;
    if (FUN_141658150(kEffects, kNodes, bEnable))
    {
        for (size_t i = 0; i < kEffects.GetCount(); i++)
        {
            CEquipModel* pEffect = kEffects[i];
            FUN_141201d50(pEffect, kNodes[i]);
        }
    }
}

// @0x141659000
void PC::FUN_141659000(int bForce)
{
    int bActive = vfunc_65() && m_spStateMgr->FUN_1417db1c0()->vfunc_15();
    if (FUN_1416595d0())
        bActive = 0;
    if (m_spStateMgr->FUN_1417db1c0()->vfunc_16())
        bActive = 1;
    if (bActive && (m_spWeaponActionD70 == 0 || m_spWeaponActionD70->m_nRightHand == 0))
        bActive = 0;
    if (!bForce && m_nD80 == bActive)
        return;
    if (bActive)
    {
        ATL::CAtlArray<CEquipModel*> kEffects;
        ATL::CAtlArray<CString> kNodes;
        if (FUN_141658150(kEffects, kNodes, 1))
            FUN_141657c80(true);
    }
    else
        FUN_141657c80(false);
}

// @0x141659790
void PC::FUN_141659790(const CString& strAnim)
{
    if (DAT_143aad1e0)
        return;
    if (m_spWeaponActionD70 == 0)
        return;
    {
        MS2Ptr<CEquipItem> spRight = FUN_141655e10(5);
        if (spRight.get())
        {
            ATL::CAtlArray<MS2Ptr<CEquipModel> > aModels;
            spRight->FUN_1411dcc80(aModels);
            for (unsigned int i = 0; i < aModels.GetCount(); i++)
            {
                CEquipModel* pModel = aModels[i].operator->();
                if (FUN_141202940(pModel) != 5)
                    continue;
                FUN_141200390(pModel, strAnim);
            }
        }
    }
    {
        MS2Ptr<CEquipItem> spLeft = FUN_141655e10(4);
        if (spLeft.get())
        {
            ATL::CAtlArray<MS2Ptr<CEquipModel> > aModels;
            spLeft->FUN_1411dcc80(aModels);
            for (unsigned int i = 0; i < aModels.GetCount(); i++)
            {
                CEquipModel* pModel = aModels[i].operator->();
                if (FUN_141202940(pModel) != 4)
                    continue;
                FUN_141200390(pModel, strAnim);
            }
        }
    }
}

// @0x14165c1b0
int PC::FUN_14165c1b0(int* pnId, CString* pstrName, float fRange)
{
    if (FUN_14028d470(fRange, 0))
        fRange = static_cast<Client::Constants*>(FUN_1401d3200())->FindHoldTargetRange.Get(150.0f);
    return FUN_1403ed2d0()->FUN_141bc9830(pnId, pstrName, fRange, 0);
}

// @0x14165c240
void PC::vfunc_136(const CString& strModel, const efd::utf8string& kAnim, float fBlend)
{
    m_kEquipDE0.FUN_1411e8b60(FUN_141658d20(), strModel, kAnim, fBlend);
}

// @0x14165c2d0
MS2Ptr<Unk_PCD88> PC::FUN_14165c2d0() { return m_spD88; }

// @0x14165c4e0
void PC::vfunc_114(void* p) { m_spStateMgr->FUN_1417db2e0(static_cast<Unk_StateArg22*>(p)); }   // a state sync record

// @0x14165c520
MS2Ptr<CWeaponAction> PC::FUN_14165c520() { return m_spWeaponActionD70; }

// @0x14165ca20
Unk_PCActionTimer* PC::FUN_14165ca20() { return m_spFC8.get(); }

// @0x14165ca50
Unk_PCActionTimer* PC::FUN_14165ca50()
{
    if (m_spFC8 == 0)
        return 0;
    if (!m_spFC8->FUN_140addea0())
        return 0;
    return m_spFC8.get();
}

// @0x14165e4a0
float PC::vfunc_95()
{
    float f = PCBase::vfunc_95();
    if (FUN_141675ed0())
        f = m_kEquipDE0.FUN_1411e0f00(f);
    return f;
}

// @0x141660df0
void PC::FUN_141660df0() {}

// @0x141660f80
void PC::vfunc_144()
{
    FUN_14166ccb0()->vfunc_23();
}
MS2_REPLACE_METHOD(0x141660F80, PC, vfunc_144, 48, 0x840E7B21);

// @0x141661be0
int PC::vfunc_145() { return 1; }
MS2_REPLACE_METHOD(0x141661BE0, PC, vfunc_145, 11, 0x30025ED0);

// @0x1416615f0
void PC::FUN_1416615f0(float fDelta)
{
    if (FUN_140976c10())
    {
        if ((unsigned int)(m_n1054 + m_n1058) < (unsigned int)FUN_140869420())
        {
            FUN_141661370(0, 0, 0);
            vfunc_42(1.0f, true);
        }
        else
            FUN_1416616a0((unsigned int)m_n1058 / 2);
    }
}

// @0x141661880
void PC::FUN_141661880(int bEnable, int nValue, const CubeItemInfo* pInfo)
{
    if (bEnable)
    {
        m_n1000 = 1;
        m_spCube1008.AssignRaw(new CubeItemInfo());
        m_spCube1008->FUN_1408b3700(pInfo);
        m_n1018 = nValue;
    }
    else
    {
        m_n1000 = 0;
        m_spCube1008 = 0;
    }
}

// @0x141661b20
void PC::FUN_141661b20(CInPacket& packet)
{
    FUN_1416619d0(packet.vfunc_o8_3());
    FUN_141661a60(packet.vfunc_o8_3());
}

// @0x141661c70
void PC::FUN_141661c70(int n)
{
    m_n10f4 = n;
    FUN_141a60f00(m_unk_70);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangeTitle(this)));
}

// @0x141661d40
void PC::FUN_141661d40(CInPacket& packet)
{
    m_n10f8 = packet.vfunc_o8_2();
    m_n10fc = packet.vfunc_o8_1();
}

// @0x14165c970
void PC::FUN_14165c970(void* p)
{
    if (m_spFC8 == 0)
        return;
    if (m_nFF4 != 0)
        m_spFC8->vfunc_1(p, 5);
    else
        m_spFC8->vfunc_1(p, 2);
}

// @0x1416624e0
void PC::FUN_1416624e0(int nIndex)
{
    CGuideObject* pGuide = FUN_141662440(nIndex);
    if (!pGuide)
        return;
    pGuide->vfunc_128();
    GameObject* pObj = FUN_1403ed2d0()->FUN_141bd0fa0(pGuide->FUN_14123c460());
    if (pObj)
        FUN_1403ed2d0()->FUN_141bbb7f0(pGuide, 0);
    FUN_1416623d0(efd::SmartPointer<CGuideObject>(0), nIndex);
}

// @0x141663550
void PC::FUN_141663550()
{
    Unk_PCWorld* pWorld = FUN_1403ed2d0();
    if (!pWorld)
        return;
    do
    {
        MS2Ptr<CProxyGameObject> spProxy = pWorld->FUN_141bc9c60(FUN_141656a80());
        if (spProxy.IsNull())
            break;
        int nState = spProxy->m_cc;
        if (nState != 0x3f)
            break;
        vfunc_59(0x3f, 0, 0, 0);
    } while (0);
}

// @0x141662160
void PC::vfunc_24(int nFlags)
{
    if (FUN_1403ed2d0()->FUN_141bca2e0())
    {
        int bShow = 1;
        int bVisible = 1;
        if (FUN_1409f7c90()->FUN_141622790())
        {
            bVisible = FUN_1409f7c90()->FUN_14161cf40();
            if (bVisible == 0)
                bShow = 0;
        }
        if (nFlags == 0)
        {
            bShow = 0;
            bVisible = 0;
        }
        if (bVisible)
        {
            if (bShow && (nFlags & 2) && CPartyManager::GetInstance()->FUN_14162ae20(m_nCharIdDB8))
                bShow = 0;
            if (bShow && (nFlags & 4))
            {
                if (CGuildManager::GetInstance()->FUN_1404cf9f0(vfunc_77()).get())
                    bShow = 0;
            }
        }
        m_unk_40 = bShow;
        if (FUN_1409f7c90()->FUN_140ddcc90() == 0 && m_unk_80)
        {
            if (m_unk_40)
            {
                bool bValue = false;
                FUN_14098c6e0(m_unk_80, 0xa0b6b179, bValue);
                m_kEquipDE0.FUN_1411e8eb0(DAT_143ae2de8);
            }
            else
            {
                if (m_unk_b0 == 0)
                {
                    bool bValue = true;
                    FUN_14098c6e0(m_unk_80, 0xa0b6b179, bValue);
                }
                m_kEquipDE0.FUN_1411e9020(DAT_143ae2de8);
            }
        }
    }
}

// @0x141656db0
MS2Ptr<Unk_PCBaseComp_a58> PC::vfunc_80()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a58>(0);
    if (!FUN_1409a8b10()->FUN_140b123b0()->m_bShowHpBar)
        return MS2Ptr<Unk_PCBaseComp_a58>(0);
    if (Unk_PCLocalPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0())
    {
        if (FUN_14165ef30() == 0 && pPlayer->FUN_1415278d0(FUN_141656a80()) == 0 && pPlayer->vfunc_122(this) == 0)
            return MS2Ptr<Unk_PCBaseComp_a58>(0);
        if (m_spA58 == 0)
            m_spA58 = FUN_141992920(m_unk_70);
        return m_spA58;
    }
    return MS2Ptr<Unk_PCBaseComp_a58>(0);
}

// @0x141660d50
void PC::FUN_141660d50()
{
    efd::Point3 kSize(70.0f, 35.0f, 150.0f);
    efd::Point3 kOffset(0.0f, 35.0f, 0.0f);
    FUN_141670fd0(kSize, kOffset);
}

// MS2-FUNCTIONAL: structure aligned, the exe keeps the attack and the owner in different temporaries
// @0x1416538d0
int PC::FUN_1416538d0(CDamageRecord* pRecord)
{
    SkillAttackData* pAttack = pRecord->FUN_14175a8b0();
    if (pAttack == 0)
        return 0;
    if (pAttack->m_eGrabTargetType != 1)
        return 0;
    if (FUN_14166c930() == 0x2b)
        return 0;
    PCBase* pOwner = FUN_1403ed2d0()->FUN_141bd1200(pRecord->m_nOwnerId);
    if (pOwner == 0)
        return 0;
    if (pOwner->FUN_14166ce30() != 0 || pOwner->FUN_1416749a0()->FUN_1409709b0() != 0)
        return 0;
    if (pOwner->FUN_141675e60() == 0)
        return 0;
    CString strNode;
    float fNearest = FLT_MAX;
    for (unsigned i = 0; i < pAttack->m_arrGrabNodeCategory.GetCount(); i++)
    {
        CString strCategory(pAttack->m_arrGrabNodeCategory[i]);
        float fDist = 0.0f;
        CString strName;
        if (pOwner->FUN_141675cd0(vfunc_18(), strCategory, &strName, &fDist) != 0 && fDist < fNearest)
        {
            fNearest = fDist;
            strNode = strName;
        }
    }
    if (strNode.IsEmpty())
        return 0;
    if (FUN_1416764d0() != 0)
        return 0;
    if (FUN_141660120())
        return 0;
    MS2Ptr<StateDataGrabTarget> spData(new StateDataGrabTarget);
    spData->m_nTarget = pRecord->m_nOwnerId;
    spData->m_strNode = strNode;
    vfunc_59(0x2b, spData, 0, 0);
    return 1;
}

// MS2-FUNCTIONAL: structure aligned, the exe re-fetches the item records for each test
// @0x141653f00
int PC::FUN_141653f00()
{
    int nRight = 0;
    int nLeft = 0;
    MS2Ptr<CEquipItem> spRight = FUN_141655d50(5);
    if (!spRight)
        spRight = FUN_141655ee0(5, 1);
    if (spRight.get())
        nRight = spRight->FUN_1411dc7f0()->FUN_14053c620();
    if (spRight.get() && spRight->FUN_1411dc7a0().get())
    {
        if (FUN_141662eb0(spRight->FUN_1411dc7a0().get()) == 0)
            nRight = 0;
    }
    MS2Ptr<CEquipItem> spLeft = FUN_141655d50(4);
    if (!spLeft)
        spLeft = FUN_141655ee0(4, 1);
    if (spLeft.get())
        nLeft = spLeft->FUN_1411dc7f0()->FUN_14053c620();
    if (spLeft.get() && spLeft->FUN_1411dc7a0().get())
    {
        if (FUN_141662eb0(spLeft->FUN_1411dc7a0().get()) == 0)
            nLeft = 0;
    }
    if (spRight == spLeft.get())
        nLeft = 0;
    if (!CWeaponActionTable::IsAllowed(nRight, nLeft))
        nLeft = 0;
    MS2Ptr<CWeaponAction> spOld(m_spWeaponActionD70);
    m_spWeaponActionD70 = CWeaponActionTable::FindAction(nRight, nLeft);
    if (spOld.get() != m_spWeaponActionD70.get() && m_spWeaponActionD70.get())
        FUN_14165c720(FUN_14165c570(), 1);
    return spOld.get() != m_spWeaponActionD70.get();
}

// MS2-FUNCTIONAL: structure aligned, temporary order differs
// @0x14165c570
int PC::FUN_14165c570()
{
    MS2Ptr<CWeaponAction> spAction(m_spWeaponActionD70);
    if (!spAction)
        spAction = CWeaponActionTable::FindAction(0, 0);
    if (!spAction.get())
        return 0;
    if (spAction->m_nNormalAttack == 0)
    {
        MS2Ptr<CEquipItem> spRight = FUN_141655d50(5);
        if (!spRight)
            spRight = FUN_141655c90(5);
        if (spRight.get())
            return spRight->FUN_1411dc7f0()->FUN_14053dc90();
    }
    return spAction->m_nNormalAttack;
}

// MS2-FUNCTIONAL: structure aligned; the loop exit after the MaxCount log is assumed (the decompile drops it)
// @0x14165c720
void PC::FUN_14165c720(int nSkillId, short nLevel)
{
    if (nSkillId == 0)
        return;
    MyPC* pMyPC = FUN_1409613d0(this);
    FUN_140ab7a10()->FUN_141210540(nSkillId, nLevel, pMyPC ? 2 : 3);
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (!spSkill.get())
        return;
    FUN_140ab7a10()->FUN_141210540(spSkill->m_nJump, nLevel, pMyPC ? 2 : 3);
    std::set<int> kFound;
    std::set<int> kVisited;
    int nCount = 0;
    do
    {
        kFound.clear();
        kVisited.insert(nSkillId);
        FUN_141661820(nSkillId, nLevel, kVisited, kFound);
        if (kFound.empty())
            nSkillId = 0;
        else
            nSkillId = *kFound.begin();
        nCount++;
        if (nCount >= DAT_1439f821c)
        {
            FUN_1401859c0(FUN_140166440(), 1, 0x13, L"PreloadComboSkill loopCount >= MaxCount");
            break;
        }
    } while (nSkillId != 0);
    FUN_141661840(nSkillId, nLevel);
}

// MS2-FUNCTIONAL: structure aligned, register allocation differs
// @0x141655ee0
MS2Ptr<CEquipItem> PC::FUN_141655ee0(int nSlot, bool bKind0Only)
{
    if (nSlot != 4 && nSlot != 5)
        return MS2Ptr<CEquipItem>(0);
    ClonePC* pClone = FUN_1405a7e30(this);
    bool bClone = !(pClone == 0 || pClone->FUN_141088590());
    if (!bKind0Only || bClone)
    {
        if (bClone)
            return m_kEquipDE0.FUN_1411e1a50(nSlot, 0);
        std::vector<int> kKinds;
        kKinds.reserve(3);
        kKinds.push_back(0);
        kKinds.push_back(1);
        kKinds.push_back(2);
        MS2Ptr<CEquipItem> spItem(0);
        for (size_t i = 0; i < kKinds.size(); i++)
        {
            int nKind = kKinds[i];
            spItem = m_kEquipDE0.FUN_1411e1780(nSlot, nKind);
            if (spItem.get())
                break;
        }
        return spItem;
    }
    return m_kEquipDE0.FUN_1411e1780(nSlot, 0);
}

// @0x141660120
bool PC::FUN_141660120()
{
    if (FUN_14166c930() != 0x20)
        return false;
    State* pState = FUN_14166ccb0();
    if (pState == 0)
        return false;
    int nHolderId = static_cast<StateHold*>(pState)->FUN_1417cd0d0();
    PCBase* pHolder = FUN_1403ed2d0()->FUN_141bd1200(nHolderId);
    if (pHolder == 0)
        return false;
    if (pHolder->GetClassID() != 0x6200003 && pHolder->GetClassID() != 0x6200004)
        return false;
    PC* pPC = efd::DynamicCast<PC>(pHolder);
    if (pPC == 0)
        return false;
    Ridee* pRidee = pPC->FUN_1416764a0();
    if (pRidee == 0)
        return false;
    int nKind = pPC->FUN_1416749a0()->FUN_1409701d0(2);
    return nKind == 1;
}

// @0x14165c090
int PC::FUN_14165c090(efd::Point3 kPos)
{
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = kPos + efd::Point3(0.0f, 0.0f, 54.0000038f);
    kInfo.m_dir = FUN_14123cc20();
    kInfo.m_maxDist = 50.0f;
    kInfo.m_groups = 0x201;
    if (!FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
        return false;
    return !FUN_14166d220()->FUN_1412410c0(kPos, m_unk_620.y * 0.5f);
}

// @0x14165df00
MS2Ptr<CGemPetSkin> PC::FUN_14165df00()
{
    if (!FUN_140166410()->FUN_14036d570(0x6c))
        return MS2Ptr<CGemPetSkin>(0);
    MS2Ptr<CGemBase> spGem = reinterpret_cast<PCGemEquip*>(FUN_14165f460())->FUN_141270740(0xb);
    if (!spGem)
        return MS2Ptr<CGemPetSkin>(0);
    return MS2Ptr<CGemPetSkin>(dynamic_cast<CGemPetSkin*>(spGem.get()));
}

// @0x14165e1b0
MS2Ptr<CGemSwim> PC::FUN_14165e1b0()
{
    MS2Ptr<CGemSwim> spSwim(0);
    if (FUN_140166410()->FUN_14036d570(0x68))
    {
        MS2Ptr<CGemBase> spGem = reinterpret_cast<PCGemEquip*>(FUN_14165f460())->FUN_141270740(6);
        if (spGem)
            spSwim.AssignRaw(dynamic_cast<CGemSwim*>(spGem.get()));
    }
    return spSwim;
}

// @0x141660e00
void PC::vfunc_49()
{
    Unk_PCShadowCfg* pCfg = FUN_140ae1c00();
    int nLodHi = pCfg->FUN_141376880(1);
    int nLodLo = pCfg->FUN_1413769d0(1);
    m_spShadow = NiNew CObjectShadow(this, nLodHi, nLodLo);
    FUN_14123cb20(m_bUnkB8);
}

// @0x141659250
void PC::FUN_141659250(int nValue, CubeItemInfo* pInfo)
{
    if (FUN_1416595d0())
    {
        if (m_pCubeCraft != 0)
        {
            m_pCubeCraft->FUN_1410a8af0(false);
            delete m_pCubeCraft;
            m_pCubeCraft = 0;
        }
        if (FUN_141b6efc0(FUN_14123c410()) == 0)
            FUN_141661880(1, nValue, pInfo);
        else
        {
            m_pCubeCraft = new Unk_PCCubeCraft(this, nValue, pInfo);
            m_pCubeCraft->FUN_1410a8af0(true);
        }
    }
    else
    {
        if (m_pCubeCraft != 0)
        {
            m_pCubeCraft->FUN_1410a8af0(false);
            delete m_pCubeCraft;
            m_pCubeCraft = 0;
        }
    }
}

// @0x141659450
void PC::vfunc_135(int nMode, int nValue, void* pInfo)
{
    if (FUN_14166ce30() != 0)
        return;
    if (FUN_1416595d0() == 0)
    {
        if (FUN_14123bea0() == 0)
            vfunc_59(5, 0, 0, 0);
        else
            vfunc_59(1, 0, 0, 0);
    }
    m_nCubeModeFFC = nMode;
    FUN_141659250(nValue, static_cast<CubeItemInfo*>(pInfo));
    FUN_141659000(0);
    PC* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (this == pLocal)
    {
        Unk_PCHousingSvcPtr spHousing(FUN_1401cd040(&DAT_143b059e8));
        if (nMode == 0)
            spHousing.FUN_1401cd1a0()->FUN_1410cc160(0);
        else if (nValue != 2)
            spHousing.FUN_1401cd1a0()->FUN_1410cc160(1);
    }
}

// @0x14165f480
int PC::vfunc_69()
{
    MS2Ptr<CEquipItem> spEquip = FUN_141655e10(2);
    if (spEquip.get())
    {
        CAtlArray<CString> aParts;
        spEquip->FUN_1411dca30(2, aParts);
        if (aParts.GetCount() > 0)
            return spEquip->FUN_1411dc7f0()->FUN_14053c510();
    }
    int nItemId = CItemDefaultData::FUN_140583f00(FUN_141658e60());
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return 0;
    return nItemId;
}

// @0x14165f5d0
int PC::vfunc_122(void* p)
{
    PC* pOther = efd::DynamicCast<PC>(static_cast<PCBase*>(p));
    if (pOther != 0)
    {
        int bPk = FUN_1403ed2d0()->FUN_141bd30a0()->FUN_1403754d0();
        if (bPk != 0)
        {
            if (p == this)
                return 0;
            if (FUN_141661bc0() != 0 && FUN_141661bc0() == pOther->FUN_141661bc0())
                return 0;
            if (FUN_1416749a0()->FUN_140970a20())
                return 0;
            if (pOther->FUN_1416749a0()->FUN_140970a20())
                return 0;
            return 1;
        }
        if (FUN_14165ef30() != pOther->FUN_14165ef30())
            return 0;
    }
    return PCBase::vfunc_122(p);
}

// MS2-FUNCTIONAL: structure aligned, the exe keeps the points in different temporaries
// @0x1416599b0
void PC::FUN_1416599b0()
{
    if (m_entityDB0 != egf::EntityID(0ull))
    {
        egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_entityDB0);
        if (pEntity != 0)
        {
            NiPoint3 kPos = vfunc_18();
            NiPoint3 kEntPos = DAT_143b01a60;
            FUN_1409618c0(pEntity, 0xfd95ca52, kEntPos);
            if (FUN_140966ea0(kEntPos, kPos) > 70.0f)
                m_entityDB0 = egf::EntityID::kENTITY_INVALID;
        }
    }
}

// @0x141660c20
void PC::FUN_141660c20(const CAtlArray<MS2Ptr<CItem> >& aItems, bool bQuick)
{
    for (size_t i = 0; i < aItems.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = aItems[i];
        if (spItem == 0)
            continue;
        if (bQuick)
            m_kEquipDE0.FUN_1411e38e0(spItem);
        else
            m_kEquipDE0.FUN_1411e3600(spItem);
    }
}

// MS2-FUNCTIONAL: structure aligned, the exe destroys the locals per branch
// @0x1416611b0
void PC::FUN_1416611b0(CString strKey)
{
    CString strPath(strKey);
    CAtlArray<CString> aParts;
    FUN_14015f050(strPath, aParts, "/");
    if (aParts.GetCount() < 4)
        return;
    __int64 nCharId = _atoi64(aParts[3]);
    if (nCharId == FUN_141656a80())
        m_str1028 = strKey;
}

// MS2-FUNCTIONAL: structure aligned, return-copy placement differs
// @0x14165e010
CString PC::FUN_14165e010(int nAction)
{
    MS2Ptr<CGemSwim> spSwim = FUN_14165e1b0();
    if (spSwim.get())
    {
        MS2Ptr<CGemSwimData> spData = spSwim->FUN_1405a5720();
        if (spData.get())
        {
            if (nAction == 0x30)
                return spData->m_strIdleEffect;
            if (nAction == 0x32)
                return spData->m_strDashEffect;
            return spData->m_strRunEffect;
        }
    }
    return FUN_141425540(FUN_141658e60(), nAction);
}

// MS2-FUNCTIONAL: structure aligned, codegen differs slightly
// @0x141660ee0
void PC::FUN_141660ee0()
{
    if (m_bD40 && m_kEquipDE0.FUN_1411e09a0())
    {
        m_bD40 = false;
        if (m_unk_b0 == 0)
            vfunc_23(0);
        vfunc_144();
        FUN_1409f7c90()->FUN_14161cf60(this);
    }
}

// MS2-FUNCTIONAL: structure aligned, the exe keeps the elapsed time in a separate temporary
// @0x1416616a0
void PC::FUN_1416616a0(unsigned int nDelay)
{
    unsigned int nNow = FUN_140869420();
    unsigned int nElapsed = nNow - m_n106c;
    m_n106c = nNow;
    float fSpeed = 5.0f;
    if (nDelay > 0 && nDelay < nNow - m_n1064)
        fSpeed = (nNow - m_n1064 - nDelay) / 1000.0f + 5.0f;
    m_n1068 = (unsigned int)(m_n1068 + nElapsed * fSpeed);
    if (m_n1068 > 1000)
    {
        m_b1070 = !m_b1070;
        m_n1068 = 0;
    }
    vfunc_42(m_b1070 ? 0.5f : 0.9f, false);
}

// @0x14165a540
int PC::FUN_14165a540()
{
    efd::Point3 kPos;
    efd::Point3 kRot;
    Unk_PCHousingSvcPtr spSvc(FUN_1401cd040(&DAT_143b059e8));
    if (spSvc.FUN_140885310())
    {
        efd::Point3 kHit;
        NiPoint3 kMy = vfunc_18();
        Cube* pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kMy, &kHit, 0.0f);
        if (pCube == 0)
        {
            NiPoint3 kTry = kMy;
            kTry.y += 25.0f;
            pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.x += 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.y -= 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.x -= 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.x -= 25.0f;
                kTry.y += 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.x += 25.0f;
                kTry.y += 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.x -= 25.0f;
                kTry.y -= 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.x += 25.0f;
                kTry.y -= 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
        }
        if (pCube != 0)
        {
            // the cell above the cube must be free
            Unk_Int3 kCell = pCube->position;
            kCell.z += 1;
            Cube* pAbove = FUN_1409670e0()->FUN_1410b8a60(kCell);
            if (pAbove != 0)
                return 0;
            efd::Point3 kDir(0.0f, 0.0f, 0.0f);
            Cube* pFound = pCube;
            egf::Entity* pSideA = 0;
            egf::Entity* pSideB = 0;
            egf::Entity** ppSide = &pSideA;
            int nDir;
            if (spSvc.FUN_1401cd1a0()->FUN_1410b9330(pCube, kHit, 25.0f, &kPos, &kRot, &nDir, &pFound))
            {
                Cube* pSide;
                switch (nDir)
                {
                case 1:
                    kDir.y = 1.0f;
                    kDir.x = -1.0f;
                    pSide = spSvc.FUN_1401cd1a0()->FUN_1410b9080(pFound, 0xff);
                    if (pSide != 0)
                    {
                        *ppSide = pSide->entity;
                        ppSide = &pSideB;
                    }
                    pSide = spSvc.FUN_1401cd1a0()->FUN_1410b9080(pFound, 0x100);
                    if (pSide != 0)
                        *ppSide = pSide->entity;
                    break;
                case 2:
                    kDir.y = 1.0f;
                    break;
                case 3:
                    kDir.y = 1.0f;
                    kDir.x = 1.0f;
                    pSide = spSvc.FUN_1401cd1a0()->FUN_1410b9080(pFound, 1);
                    if (pSide != 0)
                    {
                        *ppSide = pSide->entity;
                        ppSide = &pSideB;
                    }
                    pSide = spSvc.FUN_1401cd1a0()->FUN_1410b9080(pFound, 0x100);
                    if (pSide != 0)
                        *ppSide = pSide->entity;
                    break;
                case 4:
                    kDir.x = 1.0f;
                    break;
                case 5:
                    kDir.y = -1.0f;
                    kDir.x = 1.0f;
                    pSide = spSvc.FUN_1401cd1a0()->FUN_1410b9080(pFound, 1);
                    if (pSide != 0)
                    {
                        *ppSide = pSide->entity;
                        ppSide = &pSideB;
                    }
                    pSide = spSvc.FUN_1401cd1a0()->FUN_1410b9080(pFound, 0xff00);
                    if (pSide != 0)
                        *ppSide = pSide->entity;
                    break;
                case 6:
                    kDir.y = -1.0f;
                    break;
                case 7:
                    kDir.y = -1.0f;
                    kDir.x = -1.0f;
                    pSide = spSvc.FUN_1401cd1a0()->FUN_1410b9080(pFound, 0xff);
                    if (pSide != 0)
                    {
                        *ppSide = pSide->entity;
                        ppSide = &pSideB;
                    }
                    pSide = spSvc.FUN_1401cd1a0()->FUN_1410b9080(pFound, 0xff00);
                    if (pSide != 0)
                        *ppSide = pSide->entity;
                    break;
                case 8:
                    kDir.x = -1.0f;
                    break;
                }
                kDir.Unitize();
                // nothing may block the way from the cube's centre to the spot
                NiPoint3 kEntPos;
                FUN_1409618c0(pFound->entity.operator->(), 0xfd95ca52, kEntPos);
                Unk_RayCastInfo kInfo;
                kInfo.m_origin = kEntPos;
                kInfo.m_origin.z = kPos.z - 20.0f;
                kInfo.m_dir = kDir;
                kInfo.m_maxDist = 150.0f;
                kInfo.m_groups = 0x28b;
                kInfo.m_20 = 0;
                kInfo.m_28 = 0;
                if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
                    return 0;
                kInfo.m_origin = kEntPos;
                kInfo.m_origin.z = kPos.z + 20.0f;
                kInfo.m_groups = 0x28b;
                kInfo.m_20 = 0;
                kInfo.m_28 = 0;
                efd::Point3 kCornerA = kPos;
                kCornerA.x -= 25.0f;
                kCornerA.y += 25.0f;
                kCornerA.z += 20.0f;
                efd::Point3 kCornerB = kPos;
                kCornerB.x += 25.0f;
                kCornerB.y += 25.0f;
                kCornerB.z += 20.0f;
                efd::Point3 kCornerC = kPos;
                kCornerC.x -= 25.0f;
                kCornerC.y -= 25.0f;
                kCornerC.z += 20.0f;
                efd::Point3 kCornerD = kPos;
                kCornerD.x += 25.0f;
                kCornerD.y -= 25.0f;
                kCornerD.z += 20.0f;
                kInfo.m_dir = kCornerA - kInfo.m_origin;
                kInfo.m_maxDist = kInfo.m_dir.Unitize();
                if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
                    return 0;
                kInfo.m_dir = kCornerB - kInfo.m_origin;
                kInfo.m_maxDist = kInfo.m_dir.Unitize();
                if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
                    return 0;
                kInfo.m_dir = kCornerC - kInfo.m_origin;
                kInfo.m_maxDist = kInfo.m_dir.Unitize();
                if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
                    return 0;
                kInfo.m_dir = kCornerD - kInfo.m_origin;
                kInfo.m_maxDist = kInfo.m_dir.Unitize();
                if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
                    return 0;
                vfunc_19(kPos);
                vfunc_21(kRot);
                FUN_14166d8b0(kRot.z);
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

// @0x14165b500
int PC::FUN_14165b500(int nKind)
{
    Unk_PCHousingSvcPtr spSvc(FUN_1401cd040(&DAT_143b059e8));
    if (!spSvc.FUN_140885310())
        return 0;
    if (nKind == 1)
    {
        // a wall ahead (along +y or +x, whichever the actor faces first): step onto its top
        efd::Point3 aDirs[2] = { efd::Point3::UNIT_Y, efd::Point3::UNIT_X };
        if (vfunc_20().z < 135.0f)
        {
            aDirs[0] = efd::Point3::UNIT_X;
            aDirs[1] = efd::Point3::UNIT_Y;
        }
        for (int i = 0; i < 2; i++)
        {
            efd::Point3 kDir = aDirs[i];
            Unk_RayCastInfo kInfo;
            kInfo.m_origin = vfunc_18() + efd::Point3(0.0f, 0.0f, 90.0f);
            kInfo.m_dir = kDir;
            kInfo.m_maxDist = 25.0f + DAT_1439f8220 + DAT_1439f8224;
            kInfo.m_groups = StateClimb::FUN_1417bc010();
            if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
            {
                kDir = -kInfo.m_hitNormal;
                kInfo.m_origin = vfunc_18() + efd::Point3(0.0f, 0.0f, 90.0f);
                kInfo.m_dir = kDir;
                kInfo.m_maxDist = 25.0f + DAT_1439f8220 + DAT_1439f8224;
                kInfo.m_groups = StateClimb::FUN_1417bc010();
                if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
                {
                    if (spSvc.FUN_1401cd1a0()->FUN_1410b8e60(kInfo.m_hitEntity) != 0)
                    {
                        efd::Point3 kTarget = kInfo.m_hitPoint + kInfo.m_hitNormal * (25.0f + DAT_1439f8220)
                            - efd::Point3(0.0f, 0.0f, 90.0f);
                        if (!FUN_14165c090(kTarget))
                            continue;
                        vfunc_19(kTarget);
                        FUN_14166d430(-kInfo.m_hitNormal, 1, 1);
                        return 1;
                    }
                }
            }
        }
    }
    else if (nKind == 2)
    {
        // standing on a cube: climb down its open side
        efd::Point3 kHit;
        NiPoint3 kMy = vfunc_18();
        Cube* pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kMy, &kHit, 0.0f);
        if (pCube == 0)
        {
            NiPoint3 kTry = kMy;
            kTry.y += 25.0f;
            pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.x += 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.y -= 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
            if (pCube == 0)
            {
                kTry = kMy;
                kTry.x -= 25.0f;
                pCube = spSvc.FUN_1401cd1a0()->FUN_1410b8f30(kTry, &kHit, 0.0f);
            }
        }
        if (pCube != 0)
        {
            int aOffsets[2] = { 0xff00, 0xff };
            efd::Point3 aDirs[2] = { efd::Point3::UNIT_Y, efd::Point3::UNIT_X };
            for (int i = 0; i < 2; i++)
            {
                int nOffset = aOffsets[i];
                efd::Point3 kDir = aDirs[i];
                if (spSvc.FUN_1401cd1a0()->FUN_1410b9080(pCube, nOffset) == 0)
                {
                    efd::Point3 kFrom = kMy;
                    kFrom += -kDir * 25.0f;
                    kFrom.z -= 91.0f;
                    Unk_RayCastInfo kInfo;
                    kInfo.m_origin = kFrom;
                    kInfo.m_dir = kDir;
                    kInfo.m_maxDist = 50.0f;
                    kInfo.m_groups = StateClimb::FUN_1417bc010();
                    if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0) && kInfo.m_hitEntity != 0
                        && kInfo.m_hitEntity == (egf::Entity*)pCube->entity)
                    {
                        efd::Point3 kAbove = kMy;
                        kAbove += -kDir * 25.0f;
                        Unk_RayCastInfo kDown;
                        kDown.m_origin = kAbove;
                        kDown.m_dir = -efd::Point3::UNIT_Z;
                        kDown.m_maxDist = 90.0f;
                        kDown.m_groups = StateClimb::FUN_1417bc010() | 0x100;
                        if (!FUN_1409f7ca0()->FUN_1416892f0(&kDown, 0))
                        {
                            efd::Point3 kTarget = kInfo.m_hitPoint + kInfo.m_hitNormal * (25.0f + DAT_1439f8220);
                            kTarget += efd::Point3(0.0f, 0.0f, 105.0f);
                            if (!FUN_14165c090(kTarget))
                                return 0;
                            vfunc_19(kTarget);
                            FUN_14166d430(-kInfo.m_hitNormal, 1, 1);
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
    return 0;
}

// MS2-FUNCTIONAL: one register hop differs (the exe loads this straight into rcx for FUN_141658e60)
// @0x141658150
bool PC::FUN_141658150(ATL::CAtlArray<CEquipModel*>& kEffects, ATL::CAtlArray<CString>& kNodes, int bPrimary)
{
    int nRightType = 0;
    int nLeftType = 0;
    MS2Ptr<CEquipItem> spRight = m_kEquipDE0.FUN_1411e1860(5, 6, 1);
    if (spRight.get())
    {
        MS2Ptr<CEquipItem> spWeapon = FUN_141655ee0(5, false);
        if (spWeapon.get())
            nRightType = spWeapon->FUN_1411dc7f0()->FUN_14053c620();
        ATL::CAtlArray<MS2Ptr<CEquipModel> > aModels;
        spRight->FUN_1411dcc80(aModels);
        for (unsigned int i = 0; i < aModels.GetCount(); i++)
        {
            if (FUN_141202940(aModels.GetAt(i).operator->()) == 5)
            {
                kEffects.Add(aModels.GetAt(i).get());
                CString strNode(FUN_141200ab0(aModels.GetAt(i).operator->())->name18);
                if (!strNode.IsEmpty())
                    kNodes.Add(bPrimary ? strNode : "");
                else
                    kNodes.Add(bPrimary ? "Weapon_Hand_R_Point" : "");
            }
        }
    }
    if (spRight.IsNull())
        bPrimary = 0;
    MS2Ptr<CEquipItem> spLeft = m_kEquipDE0.FUN_1411e1860(4, 6, 1);
    if (spLeft.get())
    {
        MS2Ptr<CEquipItem> spWeapon = FUN_141655ee0(4, false);
        if (spWeapon.get())
            nLeftType = spWeapon->FUN_1411dc7f0()->FUN_14053c620();
        ATL::CAtlArray<MS2Ptr<CEquipModel> > aModels;
        spLeft->FUN_1411dcc80(aModels);
        for (unsigned int i = 0; i < aModels.GetCount(); i++)
        {
            int nWorld = 0;
            if (FUN_141202940(aModels.GetAt(i).operator->()) == 4)
            {
                CEquipModel* pModel = aModels[i].get();
                ModelPart* pPart = FUN_141200ab0(pModel);
                std::vector<ModelNameEntry>& kList = pPart->entries[(unsigned int)FUN_141658e60()];
                std::vector<ModelNameEntry>::const_iterator it;
                for (it = kList.begin(); it != kList.end(); ++it)
                {
                    nWorld = it->worldMode | it->worldLerp;
                    if (nWorld != 0)
                        break;
                }
                if (CWeaponActionTable::IsAllowed(nRightType, nLeftType) == 0)
                {
                    // a left hand weapon the pair does not allow: no node
                    kEffects.Add(aModels.GetAt(i).get());
                    kNodes.Add("");
                }
                else
                {
                    kEffects.Add(aModels.GetAt(i).get());
                    CString strNode(FUN_141200ab0(aModels.GetAt(i).operator->())->name18);
                    if (!strNode.IsEmpty())
                        kNodes.Add(bPrimary != 0 && nWorld == 0 ? strNode : "");
                    else
                        kNodes.Add(bPrimary != 0 && nWorld == 0 ? "Weapon_Hand_L_Point" : "");
                }
            }
        }
    }
    if (kEffects.GetCount())
        return true;
    return false;
}

// MS2-FUNCTIONAL: the exe's vfunc_18 result lands in kPos directly (vfunc_18 likely returns efd::Point3, pcbase.h says NiPoint3)
// @0x14165cac0
void PC::FUN_14165cac0()
{
    // the tomb stone of the dead player (its look from the worn tomb stone gem)
    efd::utf8string kModel;
    egf::EntityID kId = egf::EntityIDFactory::GetNextID();
    egf::EntityPtr spEntity(0);
    int bBusy = FUN_141661970();
    if (bBusy)
        kModel = "MS2TombStoneDark";
    else
        kModel = "MS2TombStone";
    efd::Point3 kPos = vfunc_18();
    {
        Unk_PCHousingSvcPtr spSvc(FUN_1401cd040(&DAT_143b059e8));
        if (spSvc.FUN_140885310())
            kPos = spSvc.FUN_1401cd1a0()->FUN_1410b9150(kPos);
    }
    if (efd::ClassInfo::IsKindOf(this != NULL ? GetClassDesc() : NULL, 0x06200044))   // AvatarPC
        kPos = efd::Point3::ZERO;
    efd::Point3 kRot = efd::Point3::ZERO;
    efd::utf8string kAsset;
    MS2Ptr<CGemTombStone> spTomb(0);
    if (FUN_140166410()->FUN_14036d570(0x67))
    {
        MS2Ptr<CGemBase> spGem = reinterpret_cast<PCGemEquip*>(FUN_14165f460())->FUN_141270740(5);
        if (spGem.get())
        {
            spTomb.AssignRaw(dynamic_cast<CGemTombStone*>((CGemBase*)spGem));
            if (spTomb.get())
            {
                MS2Ptr<CGemTombStoneData> spData = spTomb->FUN_1405a53c0();
                if (spData.get())
                {
                    kRot = spData->m_ptRotation;
                    CString strUrn = "urn:gamebryo-animation:"
                        + FUN_141b6ed00(bBusy != 0 ? spData->m_attrB.m_strKfm : spData->m_attrA.m_strKfm);
                    efd::AssetID kUrn;
                    kUrn.SetURN(efd::utf8string((const char*)FUN_1409a2360(strUrn, 0)));
                    kAsset = kUrn.GetURN();
                }
            }
        }
    }
    spEntity = FUN_1409670f0()->FUN_1411ce7c0(kModel, kAsset, kPos, kRot, 1.0f, 0, 0);
    if (spEntity == 0)
        return;
    int nObjectId = FUN_14123c580();
    spEntity->SetPropertyValue(0x85b708e6, nObjectId);
    m_spFC8.AssignRaw(reinterpret_cast<Unk_PCActionTimer*>(new CBreakableObject));
    m_spFC8->FUN_140adf370(spEntity, FUN_14123c580(), spTomb);
    if (FUN_141657730().get())
        FUN_141657730()->FUN_141992e40();
}

// The pc record (MS2Ptr<Unk_PCArg125> is MS2Ptr<PCInfo>: get 0x1409f7930, copy 0x1409f7220, dtor 0x1409f74e0).
class Unk_PCArg125 : public PCInfo {};

int FUN_14081dd50(int nIndex);
CLua* FUN_1401c0db0();
float FUN_14028d3a0(float fValue);                                  // (commonutil.cpp)
float FUN_140966f00(NiPoint3 kA, NiPoint3 kB);                      // distance
float FUN_140a0fde0(float fValue, float fMax);                      // min(value, max)
void FUN_140a01250(efd::Point3 kDir, efd::Point3* pForward, efd::Point3* pRight);                                      // the special ability is shown (specialability.cpp)

// The proxy object view: FUN_1416c2920 returns an int here (the shared header declares it void).
class Unk_PCProxyView
{
public:
    int FUN_1416c2920();
};

// Fill a pc record with this player's look, stats, equipment and titles.
void PC::vfunc_125(MS2Ptr<Unk_PCArg125> spInfo)
{
    if (spInfo == NULL)
        return;
    unsigned short nLevel = vfunc_78();
    spInfo->m_18 = nLevel;
    spInfo->m_1c = FUN_141654700();
    spInfo->m_20 = FUN_141654730();
    spInfo->m_28 = FUN_141656ad0();
    spInfo->m_30 = FUN_141656a80();
    spInfo->m_38 = FUN_141661c50();
    spInfo->m_60 = m_unk_1bc;
    memcpy(spInfo->m_aStats1, m_unk_1c0[1], sizeof(m_unk_1c0[1]));
    memcpy(spInfo->m_aStats0, m_unk_1c0[0], sizeof(m_unk_1c0[0]));
    memcpy(spInfo->m_aStats2, m_unk_1c0[2], sizeof(m_unk_1c0[2]));
    for (unsigned int i = 0; i < 0xcf; i++)
    {
        SAType eType = (SAType)i;
        if (!FUN_14081dd50(eType))
            continue;
        spInfo->m_3b0[eType] = m_kEquipDE0.FUN_1411e1160(eType);
    }
    spInfo->m_3c0 = 0;
    spInfo->m_3c4 = FUN_141658e60();
    MS2Ptr<CProxyGameObject> spProxy = FUN_1403ed2d0()->FUN_141bc9be0(m_unk_70);
    if (spProxy)
    {
        spInfo->m_3c8 = spProxy->m_c8;
        spInfo->m_3d4 = reinterpret_cast<Unk_PCProxyView*>((CProxyGameObject*)spProxy.operator->())->FUN_1416c2920();
        spInfo->m_3f0 = spProxy->FUN_1416c2600();
    }
    spInfo->m_3e0 = FUN_1416612e0();
    spInfo->m_3e8 = vfunc_77();
    spInfo->m_3f8 = FUN_141656be0();
    spInfo->m_3d8 = FUN_141662730();
    spInfo->m_3dc = FUN_1416626b0();
    MS2Ptr<CGuildMember> spMember = CGuildManager::GetInstance()->FUN_1404cf9f0(vfunc_77());
    if (spMember)
        spInfo->m_400 = CGuildManager::GetInstance()->FUN_1404d0af0(spMember->fb4);
    spInfo->m_408 = FUN_141656d90();
    spInfo->m_3cc = 0;
    spInfo->m_3d0 = 0;
    vfunc_126(spInfo, 0);
    vfunc_126(spInfo, 1);
    vfunc_126(spInfo, 2);
    spInfo->m_aItems.RemoveAll();
    m_kGemEquip1078.FUN_1412700e0(spInfo->m_aItems);
    MS2Ptr<CEquipmentSlotLayerInfo> spTitle = FUN_1416561a0()->GetTitle();
    if (spTitle.get())
    {
        spInfo->m_508 = spTitle->FUN_1411df810();
        spInfo->m_510 = spTitle->m_start;
        spInfo->m_520 = spTitle->m_end;
    }
    spInfo->m_530 = vfunc_141();
}

// Fill one equip map of a pc record (0 worn, 1 outfit, 2 the third layer) and add the worn weapons' attack to it.
void PC::vfunc_126(MS2Ptr<Unk_PCArg125> spInfo, int nLayer)
{
    ATL::CAtlMap<Unk_InventoryEquipSlot, MS2Ptr<CItem> >* pMap = NULL;
    if (nLayer == 0)
        pMap = &spInfo->m_mapEquip0;
    else if (nLayer == 1)
        pMap = &spInfo->m_mapEquip1;
    else if (nLayer == 2)
        pMap = &spInfo->m_mapEquip2;
    if (pMap == NULL)
        return;
    unsigned int nAttackMin = 0;
    unsigned int nAttackMax = 0;
    unsigned int nRightMin = 0;
    unsigned int nLeftMin = 0;
    unsigned int nRightMax = 0;
    unsigned int nLeftMax = 0;
    int nRings = 0;
    bool bWorn = nLayer == 0;
    ATL::CAtlList<MS2Ptr<CEquipItem> > kList;
    m_kEquipDE0.FUN_1411e1ce0(kList, nLayer);
    pMap->RemoveAll();
    POSITION pos = kList.GetHeadPosition();
    while (pos)
    {
        MS2Ptr<CEquipItem> spEquip = kList.GetNext(pos);
        if (spEquip == NULL || spEquip->FUN_1411dc7a0() == NULL)
            continue;
        MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
        Unk_InventoryEquipSlot nSlot = (Unk_InventoryEquipSlot)spItem->FUN_140526c30();
        if (nSlot == 0)
            nSlot = (Unk_InventoryEquipSlot)spItem->FUN_140527a20();
        pMap->SetAt(nSlot, spItem->FUN_140524250());
        if (!FUN_141662eb0(spItem.get()))
            continue;
        if (!bWorn || !spItem->FUN_140528980())
            continue;
        MS2Ptr<CItemData> spData(spItem->FUN_140527840());
        if (spData == 0)
            continue;
        unsigned int nMin = spItem->FUN_140529070();
        unsigned int nMax = spItem->FUN_140529090();
        if (nSlot == 4)
        {
            nRightMin = nMin;
            nRightMax = nMax;
            if (spData->FUN_14053d510())
                nRings++;
        }
        else if (nSlot == 5)
        {
            nLeftMin = nMin;
            nLeftMax = nMax;
            if (spData->FUN_14053d510())
                nRings++;
        }
        else
        {
            nAttackMin += nMin;
            nAttackMax += nMax;
        }
    }
    ItemDropCount kRange;
    float fDivisor = *FUN_1401d3200()->BothHandGearScorePenaltyDiv.Get();
    switch (nRings)
    {
    case 0:
        nAttackMin += nLeftMin;
        nAttackMax += nLeftMax;
        break;
    case 1:
        nAttackMin += nLeftMin / fDivisor;
        nAttackMax += nLeftMax / fDivisor;
        break;
    case 2:
    {
        unsigned int nLow = nRightMin < nLeftMin ? nRightMin : nLeftMin;
        unsigned int nHigh = nRightMin > nLeftMin ? nRightMin : nLeftMin;
        unsigned int nLowMax = nRightMax < nLeftMax ? nRightMax : nLeftMax;
        unsigned int nHighMax = nRightMax > nLeftMax ? nRightMax : nLeftMax;
        int nAddMin = 0;
        int nAddMax = 0;
        FUN_1401c0db0()->FUN_140678570(nLow, nHigh, nLowMax, nHighMax, &nAddMin, &nAddMax);
        nAttackMin += nAddMin;
        nAttackMax += nAddMax;
        break;
    }
    default:
        nAttackMin += nLeftMin / fDivisor;
        nAttackMax += nLeftMax / fDivisor;
        break;
    }
    spInfo->m_3cc += nAttackMin;
    spInfo->m_3d0 += nAttackMax;
}

// The damage record's points as efd::Point3 (skillrecord.h keeps them as Unk_StreamPoint).
#define PC_RECORD_PT(f) reinterpret_cast<efd::Point3&>(spRecord->f)

// Knock-back from a hit (PCBase::vfunc_107 plus the PC's state / hold checks and the equipment's push resistance).
void PC::vfunc_107(MS2Ptr<CDamageRecord> spRecord, float fScale)
{
    if (FUN_14028d470(fScale, 0.0f))
        return;
    if (m_unk_748.FUN_140970c10(spRecord->FUN_14175a8b0(), 1) != 0)
        return;
    if (FUN_14166c930() == 0xc)
        return;
    if (spRecord->FUN_14175ac30() == 0)
        return;
    if (FUN_141660120() == true)
        return;
    SkillAttackData* pAttack = spRecord->FUN_14175a8b0();
    if (pAttack == 0)
        return;
    int nKind = pAttack->m_damage.GetPush(FUN_1403ed2d0()->FUN_141bd3060());
    if (nKind == 0)
        return;
    if (m_pushControl.m_kDir != efd::Point3::ZERO && m_pushControl.m_nPriority >= pAttack->m_damage.m_nPushPriority)
        return;
    float fSpeed = FUN_14028d3a0(pAttack->m_damage.m_fPushDistance);
    efd::Point3 kDir;
    if (nKind == 2) {
        kDir = PC_RECORD_PT(m_ptPos) - vfunc_18();
    }
    else if (nKind == 1) {
        kDir = vfunc_18() - PC_RECORD_PT(m_ptPos);
    }
    else if (nKind == 5) {
        if (PC_RECORD_PT(m_ptDir) == efd::Point3::ZERO) {
            PCBase* pAttacker = FUN_1403ed2d0()->FUN_141bd1200(spRecord->m_nOwnerId);
            if (pAttacker)
                kDir = pAttacker->FUN_14123cc20();
        }
        else {
            kDir = PC_RECORD_PT(m_ptDir);
        }
    }
    else if (nKind == 6) {
        efd::Point3 kFacing = PC_RECORD_PT(m_ptHit);
        efd::Point3 kForward;
        efd::Point3 kRight;
        FUN_140a01250(kFacing, &kForward, &kRight);
        kDir = -kForward;
    }
    kDir.Unitize();
    PC_RECORD_PT(m_ptDir) = kDir;
    fSpeed = FUN_1416561a0()->FUN_1411e0f90(fSpeed);
    fSpeed *= fScale;
    if (nKind == 2) {
        PCBase* pAttacker = FUN_1403ed2d0()->FUN_141bd1200(spRecord->m_nOwnerId);
        if (pAttacker)
            fSpeed = FUN_140a0fde0((FUN_140966f00(pAttacker->vfunc_18(), vfunc_18()) - 150.0f) * 0.01f, fSpeed);
    }
    else if (nKind == 4) {
        PC_RECORD_PT(m_ptDir) = PC_RECORD_PT(m_ptPos) - vfunc_18();
        PC_RECORD_PT(m_ptDir).z = 0.0f;
        fSpeed = FUN_14028d3a0(PC_RECORD_PT(m_ptDir).Length());
        PC_RECORD_PT(m_ptDir).Unitize();
    }
    if (FUN_14028d470(fSpeed, 0.0f))
        return;
    m_pushControl.FUN_1413fcf90();
    m_pushControl.m_kDir = PC_RECORD_PT(m_ptDir);
    m_pushControl.m_fSpeed = fSpeed;
    m_pushControl.m_f28 = pAttack->m_damage.m_fPushDuration;
    m_pushControl.m_f2c = 0.0f;
    m_pushControl.m_b30 = FUN_14028d470(pAttack->m_damage.m_fPushUpDistance, 0.0f) ? 0 : 1;
    m_pushControl.m_n34 = pAttack->m_damage.m_nPushFall;
    m_pushControl.m_nPriority = pAttack->m_damage.m_nPushPriority;
    m_pushControl.FUN_1413fd050(pAttack->m_damage.m_ePushEaseType);
}

// The damage rate by the level gap: a = the attacker's level-ish value, b / c = the upper / lower reference
// (*pOut: 1 above c). nFlag == 0 scales it by vfunc_97.
float PC::vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut)
{
    *pOut = 1;
    if (a <= c / 3.0f) {
        *pOut = 0;
        float fRate = 0.2f;
        float fMul = 1.0f;
        if (nFlag == 0)
            fMul = vfunc_97();
        return fRate * fMul;
    }
    else if (a > c / 3.0f && a < c) {
        *pOut = 0;
        float fRate = 1.0f - (c - a) / (c * 0.85f);
        float fMul = 1.0f;
        fRate = _finite(fRate) ? fRate : 1.0f;
        if (nFlag == 0)
            fMul = vfunc_97();
        return fRate * fMul;
    }
    else if (a == c) {
        *pOut = 0;
        float fRate = 1.0f;
        float fMul = 1.0f;
        if (nFlag == 0)
            fMul = vfunc_97();
        return fRate * fMul;
    }
    else if (a > c && a < (c + b) / 2.5f) {
        *pOut = 0;
        float fRate = 1.0f - (c - a) / (c * 1.35f);
        float fMul = 1.0f;
        fRate = _finite(fRate) ? fRate : 1.0f;
        if (nFlag == 0)
            fMul = vfunc_97();
        return fRate * fMul;
    }
    else if (a > (c + b) / 2.5f && a < b) {
        *pOut = 1;
        float fRate = 1.0f - (b - a) / (b * 1.65f);
        float fMul = 1.0f;
        fRate = _finite(fRate) ? fRate : 1.0f;
        if (nFlag == 0)
            fMul = vfunc_97();
        return fRate * fMul;
    }
    else if (a == b) {
        *pOut = 1;
        float fRate = 1.0f;
        float fMul = 1.0f;
        if (nFlag == 0)
            fMul = vfunc_97();
        return fRate * fMul;
    }
    else if (a > b && a < 2.0f * b) {
        *pOut = 1;
        float fRate = 1.0f - (b - a) / (b * 1.25f);
        float fMul = 1.0f;
        fRate = _finite(fRate) ? fRate : 1.0f;
        if (nFlag == 0)
            fMul = vfunc_97();
        return fRate * fMul;
    }
    else if (a > 2.0f * b) {
        *pOut = 1;
        float fRate = 1.8f;
        float fMul = 1.0f;
        if (nFlag == 0)
            fMul = vfunc_97();
        return fRate * fMul;
    }
    return 1.0f;
}

// The couple effect view: the per-tick update takes the frame time (unit_140b0e5f0.h declares it without).
class Unk_PCCoupleView
{
public:
    void FUN_140b0e7a0(float fDelta);
};
// The random target effect view (randomtargeteffect.h lacks the update).
class Unk_PCRandomTargetView
{
public:
    void FUN_140aab0f0();                                           // per-frame update
};
int FUN_14080b8e0(CSkillTierOptionManager* pTier);                  // the skill tier options changed
UIStatusEventDispatcher* FUN_140aa6d40();
extern __int64 DAT_143ab2828;                                       // the own character id

// Per-frame update.
void PC::vfunc_53(float f)
{
    FUN_141678360();
    FUN_141660df0();
    m_kEquipDE0.FUN_1411e76c0(f);
    PCBase::vfunc_53(f);
    if (DAT_143ab2828 == m_nCharIdDB8 || CPartyManager::GetInstance()->FUN_14162ae20(m_nCharIdDB8))
        m_nFF0 = CPartyManager::GetInstance()->FUN_14162ab00();
    else
        m_nFF0 = 0;
    FUN_141659000(0);
    bool bExpired = m_timer970.FUN_140868c00() || !m_timer970.FUN_140868ba0() ? true : false;
    if (bExpired)
        m_timer970.FUN_140868750(200);
    vfunc_93(bExpired);
    FUN_141660ee0();
    if (m_spD88.get())
        m_spD88->FUN_140a35500(f);
    FUN_1416599b0();
    vfunc_142();
    Unk_PCBaseComp_a78* pTag;
    Unk_PCBaseComp_a78* pTagCopy = pTag = vfunc_82().get();         // the exe keeps a second (unused) copy
    if (pTag)
    {
        Unk_PCLocalPlayer* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pLocal)
        {
            unsigned int nColor = FUN_140a7d630(&static_cast<Client::Constants*>(FUN_1401d3200())->NameTagColorPC);
            if (this == pLocal)
                nColor = FUN_140a7d630(&static_cast<Client::Constants*>(FUN_1401d3200())->NameTagColorMyPC);
            else if (pLocal->vfunc_122(this))
                nColor = FUN_140a7d630(&static_cast<Client::Constants*>(FUN_1401d3200())->NameTagColorPCHostile);
            else if (pLocal->FUN_1415278d0(FUN_141656a80()))
                nColor = FUN_140a7d630(&static_cast<Client::Constants*>(FUN_1401d3200())->NameTagColorParty);
            pTag->FUN_141a5e500(nColor);
        }
    }
    FUN_1416615f0(f);
    FUN_141659720();
    FUN_141661ac0();
    if (FUN_14080b8e0(m_spSkillTier1110.get()))
    {
        if (GetClassID() == 0x06200004)
            FUN_140aa6d40()->FUN_141b0ce20(0xe, 0);
    }
    if (m_spCouple11d8.get())
        reinterpret_cast<Unk_PCCoupleView*>((CoupleEffectSystem*)m_spCouple11d8.operator->())->FUN_140b0e7a0(f);
    if (m_spTailEffect1270.get())
        m_spTailEffect1270->FUN_140ad0200();
    for (POSITION pos = m_mapTail1280.GetStartPosition(); pos; m_mapTail1280.GetNext(pos))
    {
        MS2Ptr<CTailEffectObject> spTail = m_mapTail1280.GetValueAt(pos);
        ((CTailEffectObject*)spTail)->FUN_140ad0200();
    }
    if (m_spRandomTarget12c8.get())
        reinterpret_cast<Unk_PCRandomTargetView*>((CRandomTargetEffect*)m_spRandomTarget12c8.operator->())->FUN_140aab0f0();
}

// ---- end of code ----

// MS2-PIN: ??_7PC@@6BIBase@efd@@@ 0x142f4ae28
// MS2-PIN: ??_7PC@@6BCallbackObject@NiActorManager@@@ 0x142f4b2c8
// MS2-PIN: ??_GPC@@UEAAPEAXI@Z 0x1416678b0
// MS2-PIN: ??_EPC@@W7EAAPEAXI@Z 0x1416677f8
// MS2-PIN: ??__Es_category@@YAXXZ 0x1400fb430
// MS2-PIN: ??__Es_pointer@@YAXXZ 0x1400fb460
