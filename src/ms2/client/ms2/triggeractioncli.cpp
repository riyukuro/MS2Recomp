// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See triggeractioncli.h.
// MS2-UNIT: ?\triggeractioncli.cpp
// MS2-RANGE: 0x1400d66e0-0x1400d67b0 .text$di
// MS2-RANGE: 0x140de4d10-0x140dece80 .text$mn
// MS2-PIN: ??$make_pair@AEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAH@std@@YA?AU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@AEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAH@Z 0x140deb360 ; std::make_pair(m_strName, nId) in CollectIds
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?SetAtGrow@?$CAtlArray@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@QEAAX_KAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@Z 0x140de52a0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VTriggerObject@@@@QEAA@H@Z 0x140de8c40 ; unique
// MS2-PIN: ??0?$MS2Ptr@VTriggerObject@@@@QEAA@PEAVTriggerObject@@@Z 0x140de8c60 ; unique
// MS2-PIN: ??_GTriggerObject@@UEAAPEAXI@Z 0x140de8ee0 ; prop
// MS2-PIN: ??_GTriggerObjectEffect@@UEAAPEAXI@Z 0x140de8fe0 ; prop
// MS2-PIN: ?AddRef@?$MS2Ptr@VTriggerObject@@@@AEBAXXZ 0x140de90e0 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VTriggerObject@@@@CAXPEAVTriggerObject@@@Z 0x140de9110 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VTriggerObject@@@@AEBAXPEAX@Z 0x140de9130 ; unique
// MS2-PIN: ??$?0AEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAH$0A@@?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@QEAA@AEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAH@Z 0x140dea970 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@@std@@YAXPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@0AEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@0@U?$integral_constant@_N$0A@@0@@Z 0x140dea9c0 ; unique
// MS2-PIN: ??$_Emplace_back@AEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@?$_Uninitialized_backout_al@PEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@QEAAXAEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@1@@Z 0x140deaa70 ; prop
// MS2-PIN: ??$_Emplace_back@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@?$_Uninitialized_backout_al@PEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@QEAAX$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@1@@Z 0x140deaad0 ; prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@AEAAX$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@1@@Z 0x140deab30 ; unique
// MS2-PIN: ??$_Emplace_reallocate@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@QEAAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@1@QEAU21@$$QEAU21@@Z 0x140deabf0 ; unique
// MS2-PIN: ??$_Get_unwrapped@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@YAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@QEAU10@@Z 0x140deae40 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@PEAU12@@std@@YA_JAEBQEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@0Urandom_access_iterator_tag@0@@Z 0x140deae60 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@U12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@0@Z 0x140deaec0 ; prop
// MS2-PIN: ??$_Ptr_move_cat@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@U12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@0@Z 0x140deaef0 ; prop
// MS2-PIN: ??$_Unfancy@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@YAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@PEAU10@@Z 0x140deaf40 ; prop
// MS2-PIN: ??$_Uninitialized_copy@PEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@PEAU12@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@YAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@QEAU10@0PEAU10@AEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@0@@Z 0x140deaf50 ; unique
// MS2-PIN: ??$_Uninitialized_copy_al_unchecked@PEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@PEAU12@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@YAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@PEAU10@QEAU10@1AEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140deb020 ; unique
// MS2-PIN: ??$_Uninitialized_move@PEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@PEAU12@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@YAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@QEAU10@0PEAU10@AEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@0@@Z 0x140deb0b0 ; unique
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@PEAU12@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@YAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@PEAU10@QEAU10@1AEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140deb180 ; unique
// MS2-PIN: ??$construct@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@AEAU12@@?$_Default_allocator_traits@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@1@QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@1@AEAU31@@Z 0x140deb210 ; prop
// MS2-PIN: ??$construct@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@U12@@?$_Default_allocator_traits@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@1@QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@1@$$QEAU31@@Z 0x140deb260 ; prop
// MS2-PIN: ??$destroy@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@?$_Default_allocator_traits@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@1@QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@1@@Z 0x140deb2b0 ; unique
// MS2-PIN: ??$emplace_back@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@QEAAX$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@1@@Z 0x140deb2d0 ; unique
// MS2-PIN: ??$forward@AEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@YAAEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@AEAU10@@Z 0x140deb340 ; prop
// MS2-PIN: ??$forward@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@YA$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@AEAU10@@Z 0x140deb350 ; prop
// MS2-PIN: ??$move@AEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@YA$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@0@AEAU10@@Z 0x140deb3c0 ; prop
// MS2-PIN: ??0?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@QEAA@$$QEAU01@@Z 0x140deb540 ; prop
// MS2-PIN: ??0?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@QEAA@AEBU01@@Z 0x140deb580 ; prop
// MS2-PIN: ??8?$MS2Ptr@VTriggerActionCli@@@@QEBA_NPEAVTriggerActionCli@@@Z 0x140deb740 ; prop
// MS2-PIN: ??8?$MS2Ptr@VTriggerConditionCli@@@@QEBA_NPEAVTriggerConditionCli@@@Z 0x140deb780 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VTriggerActionCli@@@@V?$CElementTraits@V?$MS2Ptr@VTriggerActionCli@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VTriggerActionCli@@@@_K@Z 0x140deb7c0 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VTriggerTransitionCli@@@@V?$CElementTraits@V?$MS2Ptr@VTriggerTransitionCli@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VTriggerTransitionCli@@@@_K@Z 0x140deb800 ; unique
// MS2-PIN: ??C?$MS2Ptr@VTriggerTransitionCli@@@@QEBAPEAVTriggerTransitionCli@@XZ 0x140deb860 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@AEBA_K_K@Z 0x140dec070 ; unique
// MS2-PIN: ?_Change_array@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@AEAAXQEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@_K1@Z 0x140dec100 ; unique
// MS2-PIN: ?_Destroy@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@AEAAXPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@0@Z 0x140dec210 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@@2@XZ 0x140dec270 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@XZ 0x140dec290 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@XZ 0x140dec2a0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@std@@@2@XZ 0x140dec2c0 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@@std@@QEAAAEAV?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@XZ 0x140dec2d0 ; unique
// MS2-PIN: ?_Has_unused_capacity@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@AEBA_NXZ 0x140dec310 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@XZ 0x140dec360 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@XZ 0x140dec380 ; unique
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@XZ 0x140dec3a0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@XZ 0x140dec3e0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@XZ 0x140dec400 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@AEBAXPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@0@Z 0x140dec440 ; unique
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@QEAAPEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@XZ 0x140dec490 ; unique
// MS2-PIN: ?push_back@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@QEAAX$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@2@@Z 0x140dec700 ; unique
// MS2-PIN: ?size@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@QEBA_KXZ 0x140dec730 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?get@?$MS2Ptr@VTriggerTransitionCli@@@@QEBAPEAVTriggerTransitionCli@@XZ 0x140deb850
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\triggeractioncli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <string>
#include <efd/AssetID.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <NiAVObject.h>
#include <NiNode.h>
#include "triggeractioncli.h"
#include "cameramode.h"
#include "cameratargetboundingbox.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe data ----
extern char DAT_143afa4d8;      // NiNode::ms_RTTI
extern char DAT_143afa950;      // RTTI of the camera-carrying scene node
extern Unk_StreamPoint DAT_143b01a60;   // NiPoint3::ZERO

// ---- unit-local views of exe objects ----

// xml (tinyxml) helpers
struct Unk_g1_TiXmlElement { void* m_00; void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; void* m_70; void* m_78; void* m_80; void* m_88; };
MS2_CHECK_SIZE(Unk_g1_TiXmlElement, 0x90);
void* FUN_14086f2f0(void*, const char*);          // TiXmlElement::TiXmlElement(const char*)
void FUN_14086f450(void*);                        // TiXmlElement::~TiXmlElement
void* FUN_14086e000(void*, void*);                // InsertEndChild
void* FUN_140165cf0(void*, const char*);          // FirstChildElement
void* FUN_140168650(void*, const char*);          // NextSibling
int FUN_140873420(void*, const char*, CStringW&); // QueryStringAttribute (0 = found)
int FUN_1408731e0(void*, const char*, int&);      // QueryIntAttribute
void FUN_1408740a0(void*, const char*, const CStringW&);   // SetAttribute(string)
void FUN_140873ca0(void*, const char*, int);      // SetAttribute(int)

CStringA FUN_14052ea30(const char* pszFmt, const int* pnArg);      // CStringA::Format("arg{0}", n)
CStringA FUN_1401d9af0(const char* pszFmt, const __int64* pnArg);
CStringW FUN_1401d0160(const wchar_t* pszLeft, const CStringW& strRight);   // operator+
bool FUN_140164830(const CStringW& a, const CStringW& b);
bool FUN_14034eee0(const CStringW& a, const wchar_t* pszB);        // case-insensitive equal

// game config table (limits of the trigger editor)
void* FUN_1401d3200();
unsigned* FUN_1401d7c10(void* pSlot);

// registrar of ClassObject factories, atexit helpers
ClassObject* FUN_140de5570();
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
void FUN_1401cd100(void* pId, int n);

// ---- dynamic initializers ----
// @0x1400d66e0
#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllMain time, before the exe's CRT/locks exist (startup hang)
static char s_dat_143ac4e79;
static int s_dat_143ac4e79_init = (FUN_140316aa0(&s_dat_143ac4e79, CStringW(L"TriggerConditionCli"), FUN_140de5570), 0);
#endif
// @0x1400d6730
static CStringA s_strSkill("skill");
// @0x1400d6760
static CStringA s_strStun("stun");
// @0x1400d6790
static char s_dat_143ac4e80[8];
static int s_dat_143ac4e80_init = (FUN_1401cd100(&s_dat_143ac4e80, 0), 0);

// ---- TriggerActionCli ----

// @0x140de4d10
CStringW TriggerActionCli::GetTypeName()
{
    return CStringW(L"TriggerActionCli");
}

// @0x140de4d60
MS2Ptr<TriggerActionCli> TriggerActionCli::Create(void* pNode)
{
    MS2Ptr<TriggerActionCli> sp(new TriggerActionCli);
    sp->vfunc_2(pNode);
    return sp;
}

// @0x140de4e30
void TriggerActionCli::SetName(CStringW strName)
{
    m_strName = strName;
}

// @0x140de4e80
void TriggerActionCli::SetArgs(const ATL::CAtlArray<CStringW>& rArgs)
{
    m_args.Copy(rArgs);
}

// @0x140de4eb0
CStringW TriggerActionCli::GetName()
{
    return m_strName;
}

// @0x140de4f00
CStringW TriggerActionCli::GetArg(int n)
{
    return m_args[(unsigned)n];
}

// @0x140de4f60
unsigned __int64 TriggerActionCli::GetArgCount()
{
    return m_args.GetCount();
}

// @0x140de4f90
int TriggerActionCli::GetIntArg0()
{
    if (m_args.GetCount() >= 2)
        return _wtoi(m_args[0]);
    return 0;
}

// @0x140de4ff0
ATL::CAtlArray<CStringW>* TriggerActionCli::GetArgs()
{
    return &m_args;
}

// @0x140de5010
void TriggerActionCli::vfunc_2(void* pNode)
{
    FUN_140873420(pNode, "name", m_strName);
    for (unsigned i = 0; i < 6; i++)
    {
        CStringW str;
        int n = i + 1;
        if (FUN_140873420(pNode, FUN_14052ea30("arg{0}", &n), str) == 0)
            m_args.SetAtGrow(i, str);
    }
}

// @0x140de5190
TriggerActionCli::TriggerActionCli()
{
}

// @0x140de5210
TriggerActionCli::~TriggerActionCli()
{
}

// @0x140de5450
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ---- TriggerConditionCli ----

// @0x140de5570
ClassObject* FUN_140de5570()
{
    return new TriggerConditionCli;
}

// @0x140de55d0
CStringW TriggerConditionCli::GetTypeName()
{
    return CStringW(L"TriggerConditionCli");
}

// @0x140de5620
TriggerConditionCli::TriggerConditionCli() : m_bNot(0)
{
}

// @0x140de5690
MS2Ptr<TriggerConditionCli> TriggerConditionCli::Create(void* pNode)
{
    CStringW strName;
    FUN_140873420(pNode, "name", strName);
    int bNot = 0;
    if (strName.GetLength() > 1)
    {
        if (strName[0] == L'!')
        {
            bNot = 1;
            strName = strName.Right(strName.GetLength() - 1);
        }
    }
    MS2Ptr<TriggerConditionCli> sp(new TriggerConditionCli);
    sp->SetName(CStringW(strName));
    sp->SetNot(bNot);
    sp->vfunc_2(pNode);
    return sp;
}

// @0x140de5880
void TriggerConditionCli::SetArgs(const ATL::CAtlArray<CStringW>& rArgs)
{
    m_args.Copy(rArgs);
}

// @0x140de58b0
void TriggerConditionCli::SetName(CStringW strName)
{
    m_strName = strName;
}

// @0x140de5900
void TriggerConditionCli::SetNot(int bNot)
{
    m_bNot = bNot;
}

// @0x140de5920
CStringW TriggerConditionCli::GetName()
{
    return m_strName;
}

// @0x140de5970
CStringW TriggerConditionCli::GetArg(int n) const
{
    return m_args.GetAt((unsigned)n);
}

// @0x140de59d0
int TriggerConditionCli::GetIntArg0()
{
    if (m_args.GetCount() >= 2)
        return _wtoi(m_args[0]);
    return 0;
}

// @0x140de5a30
unsigned __int64 TriggerConditionCli::GetArgCount()
{
    return m_args.GetCount();
}

// @0x140de5a60
ATL::CAtlArray<CStringW>* TriggerConditionCli::GetArgs()
{
    return &m_args;
}

// @0x140de5a80
int TriggerConditionCli::GetNot()
{
    return m_bNot;
}

// @0x140de5aa0
void TriggerConditionCli::vfunc_2(void* pNode)
{
    for (unsigned i = 0; i < 6; i++)
    {
        CStringW str;
        int n = i + 1;
        if (FUN_140873420(pNode, FUN_14052ea30("arg{0}", &n), str) == 0)
            m_args.SetAtGrow(i, str);
    }
}

// @0x140de5c30
TriggerConditionCli::~TriggerConditionCli()
{
}

// ---- TriggerObject ----

// @0x140de5dd0
TriggerObject::TriggerObject() : m_nId(0), m_spEntity(0)
{
}

// @0x140de5e30
TriggerObject::~TriggerObject()
{
}

egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);

#define TRIG_ENT() reinterpret_cast<egf::Entity*>(m_spEntity.FUN_1408a9280())
#define TRIG_ENT_RAW() reinterpret_cast<egf::Entity*>(m_spEntity.FUN_1408a9090())

// @0x140de5e70
bool TriggerObject::HasModel(const unsigned& rModelId)
{
    if (m_spEntity.FUN_1408a9090() != 0)
    {
        egf::FlatModel* pModel = FUN_1408a9bd0(TRIG_ENT());
        if (pModel != 0 && pModel->ContainsModel(rModelId))
            return true;
    }
    return false;
}

// @0x140de5ef0
void TriggerObject::Init(int nId, Unk_EntRef ent)
{
    m_nId = nId;
    m_spEntity = ent;
    vfunc_1();
}

// ---- trigger-box test ----
int FUN_1409618c0(egf::Entity* pEntity, unsigned uPropId, Unk_StreamPoint* pOut);
void FUN_140add1a0(Unk_CtbBounds3* pSelf, float x0, float y0, float z0, float x1, float y1, float z1);
void FUN_140adca00(Unk_CtbMat33* pSelf);
void FUN_140add040(Unk_CtbMat33* pSelf, float fAngle);
void FUN_140adc690(Unk_CtbObb* pOut, const Unk_CtbBounds3* pBounds, const Unk_CtbMat34* pPose);
bool FUN_140adc610(const Unk_CtbObb* pObb, const Unk_CtbVec3& pt);
const Unk_CtbVec3* FUN_141b6e0e0(void* pTmp, const Unk_StreamPoint* pPt);

// @0x140de5f60
// MS2-FUNCTIONAL: box locals are laid out by the compiler
bool TriggerObject::Contains(Unk_StreamPoint pt)
{
    if (m_spEntity.FUN_1408b70b0(0) != 0)
        return false;
    Unk_StreamPoint ptPos;
    Unk_StreamPoint ptSize;
    Unk_StreamPoint ptRot;
    egf::FlatModel* pModel = FUN_1408a9bd0(TRIG_ENT());
    if (!pModel->ContainsModel(0x5fc1ef17))
        return false;
    FUN_1409618c0(TRIG_ENT(), 0xfd95ca52, &ptPos);
    FUN_1409618c0(TRIG_ENT(), 0x9dc22aea, &ptSize);
    FUN_1409618c0(TRIG_ENT(), 0x68c7c29d, &ptRot);
    Unk_StreamPoint ptHalf = ptSize.FUN_14097fc90(0.5f);
    Unk_CtbBounds3 bounds;
    FUN_140add1a0(&bounds, -ptHalf.x, -ptHalf.y, -ptHalf.z, ptHalf.x, ptHalf.y, ptHalf.z);
    Unk_CtbMat34 pose(true);
    pose.m_pos.x = ptPos.x;
    pose.m_pos.y = ptPos.y;
    pose.m_pos.z = ptPos.z;
    FUN_140adca00(&pose.m_rot);
    FUN_140add040(&pose.m_rot, (ptRot.z * 3.1415927f) / 180.0f);
    Unk_CtbObb obb;
    FUN_140adc690(&obb, &bounds, &pose);
    char aTmp[16];
    return FUN_140adc610(&obb, *FUN_141b6e0e0(aTmp, &pt));
}

// @0x140de6210
void TriggerObject::vfunc_1()
{
}

// @0x140de6220
void TriggerObject::vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx)
{
}

// @0x140de6240
void TriggerObject::vfunc_3()
{
}

// @0x140de6250
void TriggerObject::vfunc_4()
{
}

// @0x140de6260
MS2Ptr<TriggerObject> TriggerObject::Create(egf::Entity* pEntity)
{
    if (pEntity == 0)
        return MS2Ptr<TriggerObject>(0);
    egf::FlatModel* pModel = FUN_1408a9bd0(pEntity);
    if (pModel == 0)
        return MS2Ptr<TriggerObject>(0);
    if (pModel->ContainsModel(0x2147ae01))
        return MS2Ptr<TriggerObject>(new TriggerObjectSound);
    if (pModel->ContainsModel(0x74b363a7))
        return MS2Ptr<TriggerObject>(new TriggerObjectMesh);
    if (pModel->ContainsModel(0x4714f9ea))
        return MS2Ptr<TriggerObject>(new TriggerObjectActor);
    if (!pModel->ContainsModel(0x8a9638bf) && !pModel->ContainsModel(0xc680f858))
    {
        if (pModel->ContainsModel(0x670a04d7))
            return MS2Ptr<TriggerObject>(new TriggerObjectEffect);
        if (pModel->ContainsModel(0x79197a62))
            return MS2Ptr<TriggerObject>(new TriggerObjectCube);
        if (pModel->ContainsModel(0x65338ec3))
            return MS2Ptr<TriggerObject>(new TriggerObjectCamera);
        return MS2Ptr<TriggerObject>(new TriggerObject);
    }
    return MS2Ptr<TriggerObject>(new TriggerObjectRope);
}

// ---- entity / world service views ----
int FUN_1408a2060(egf::Entity* e, unsigned id, efd::utf8string* out);     // string property
int FUN_1408a20a0(egf::Entity* e, unsigned id, bool* out);                // bool property
int FUN_140961880(egf::Entity* e, unsigned id, float* out);               // float property
int FUN_140ae11a0(egf::Entity* e, unsigned id, int* out);                 // int property
void FUN_1409457c0(egf::Entity* e, unsigned id, const float& v);
void FUN_14098c6e0(egf::Entity* e, unsigned id, const bool& v);
int FUN_140998250(egf::Entity* e, unsigned id, efd::AssetID* v);
void FUN_140de8bd0(egf::Entity* e, unsigned id, efd::AssetID* v);
const void* FUN_1408b76f0(const void* pEnt);                              // &entity id
void* FUN_1408b6b20(void* pDst, const void* pSrc);                        // copy an entity id
bool FUN_14096ad40(const efd::utf8string& str);                           // empty()
const char* FUN_1408ac310(const efd::utf8string& str);                    // c_str()
bool FUN_1403af290(const std::string& str);                               // empty()
const char* FUN_1401d4890(const std::string& str);                        // c_str()
void FUN_140de0cb0(efd::AssetID* pId, efd::utf8string* pUrn);             // set the urn
bool FUN_140de8e30(const efd::utf8string& str, const char* psz);          // == psz
int FUN_140de9280(const std::string& s, const char* psz);
bool FUN_140de8ea0(const void* pA, const void* pB);
efd::AssetID* FUN_140de8c90(efd::AssetID* pDst, const efd::AssetID* pSrc);
void FUN_140de9160(std::string& s, size_t n);
void FUN_140de91c0(std::string& s);
void FUN_140de91f0(std::string& s);
int FUN_140de9210(const std::string& s, const char* psz);
bool FUN_140de8e70(const efd::AssetID* a, const efd::AssetID* b);         // urn differs
void FUN_140b60e40(void* pObj, char b);
void FUN_140b60e10(void* pObj, char b);

// sound manager (0x140d13c40)
void* FUN_140d13c40();
void FUN_14177c100(void* pMgr, int nId, float fVolume, unsigned nPriority, int nForce);   // PlayMusic
void FUN_14177ce30(void* pMgr, Unk_EntRef ent, unsigned bOn);

// effect manager (0x1403ed280) and its request (as in unit_140b0e5f0)
struct Unk_TrigFxXform { float m_af[9]; float m_afTranslate[3]; float m_fScale; };
MS2_CHECK_SIZE(Unk_TrigFxXform, 0x34);
struct Unk_TrigFxReq
{
    CStringA m_strName;                                 // +0
    int m_nOwnerId;                                     // +8
    int m_pad_0c;
    void* m_pSlot10;                                    // +0x10 attach node
    Unk_TrigFxXform* m_pXform;                          // +0x18
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_TrigFxReq, 0x78);
class Unk_TrigFxMgr
{
public:
    int FUN_1411a49c0(Unk_TrigFxReq* pRequest);         // spawn, returns the handle
    void FUN_1411a6060(int nHandle);                    // release
    void FUN_1411a4a00(Unk_TrigFxReq* pRequest);        // spawn at the attach node
};
Unk_TrigFxMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_TrigFxReq* p);
void FUN_1405a89e0(Unk_TrigFxReq* p);
void* FUN_140a332d0(Unk_TrigFxXform* p);

// world / animation services
class Unk_TrigWorldSvc { public: bool FUN_141bd8e30(void* pEntId, char bShow, float fFade); };
Unk_TrigWorldSvc* FUN_1403ed2d0();
class Unk_TrigAnimSvc { public: void FUN_1409a1fc0(const void* pEntId, const efd::utf8string& kName, float fBlend, bool b); };
Unk_TrigAnimSvc* FUN_141b6f910();
NiAVObject* FUN_141b6efc0(void* pEnt);                  // root scene node of the entity
void FUN_141851f90(NiAVObject* p, float fTime);
void* FUN_14086d260();
double FUN_141473280(void* pClock);
void FUN_141545250(void* pEntId, unsigned b);
void* FUN_141b6ef70(void* pEntId);
void* FUN_14098d8d0(const void* pRtti, void* pObj);
void FUN_1409fabf0(void* pSlot, void* pObj);
void* FUN_140c9b540(int nId);
void FUN_141a39d40(void* pUi, int nId, char b);

// debug trigger display (FUN_140c9b540(0x4e29))

// ---- TriggerObjectSound ----

// @0x140de6760
TriggerObjectSound::TriggerObjectSound() : m_nHandle(0)
{
}

// @0x140de67a0
TriggerObjectSound::~TriggerObjectSound()
{
    if (m_nHandle != 0)
        FUN_1403ed280()->FUN_1411a6060(m_nHandle);
}

// @0x140de6800
void TriggerObjectSound::vfunc_1()
{
    efd::utf8string kKind;
    FUN_1408a2060(TRIG_ENT(), 0xf83bad53, &kKind);
    m_nKind = 0;
    if (FUN_140de8e30(kKind, "BGM"))
        m_nKind = 1;
    else if (FUN_140de8e30(kKind, "AMB"))
        m_nKind = 2;
    else if (FUN_140de8e30(kKind, "Effect"))
        m_nKind = 3;
}

// @0x140de68f0
// MS2-FUNCTIONAL: locals/temporaries are laid out by the compiler
void TriggerObjectSound::vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx)
{
    unsigned bOn = pEvent->Arg()->vfunc_1();
    if (m_nKind == 1)
    {
        if (bOn == 0)
        {
            if (m_nHandle != 0)
            {
                efd::utf8string kStop;
                FUN_1408a2060(TRIG_ENT(), 0xcdeb811e, &kStop);
                FUN_14177c100(FUN_140d13c40(), 0, 0, 0x80, 0);
                m_nHandle = 0;
            }
        }
        else
        {
            efd::utf8string kId;
            FUN_1408a2060(TRIG_ENT(), 0xed530c5f, &kId);
            if (!FUN_14096ad40(kId))
            {
                int nSound = atoi(FUN_1408ac310(kId));
                if (nSound > 0)
                {
                    FUN_14177c100(FUN_140d13c40(), nSound, 0, 0x80, 0);
                    m_nHandle = nSound;
                }
            }
        }
    }
    else if (m_nKind == 2)
    {
        efd::utf8string kId;
        FUN_1408a2060(TRIG_ENT(), 0xed530c5f, &kId);
        if (!FUN_14096ad40(kId))
            FUN_14177ce30(FUN_140d13c40(), m_spEntity, bOn);
    }
    else if (m_nKind == 3)
    {
        if (bOn == 0)
        {
            if (m_nHandle != 0)
            {
                efd::utf8string kName;
                FUN_1408a2060(TRIG_ENT(), 0xcdeb811e, &kName);
                if (!FUN_14096ad40(kName))
                {
                    Unk_TrigFxReq req;
                    FUN_140a52ef0(&req);
                    req.m_strName = FUN_1408ac310(kName);
                    req.m_nOwnerId = 0;
                    FUN_1403ed280()->FUN_1411a49c0(&req);
                    m_nHandle = 0;
                    FUN_1405a89e0(&req);
                }
            }
        }
        else
        {
            efd::utf8string kName;
            FUN_1408a2060(TRIG_ENT(), 0x131dc1d2, &kName);
            if (!FUN_14096ad40(kName))
            {
                Unk_TrigFxReq req;
                FUN_140a52ef0(&req);
                req.m_strName = FUN_1408ac310(kName);
                req.m_nOwnerId = 0;
                m_nHandle = FUN_1403ed280()->FUN_1411a49c0(&req);
                FUN_1405a89e0(&req);
            }
        }
    }
}

// ---- TriggerObjectMesh ----

// @0x140de6d30
TriggerObjectMesh::TriggerObjectMesh()
{
}

void FUN_140965410(const void* pEntId, void* pArg);

// @0x140de6d70
void FUN_140de6d70(TriggerObject* pObj, void* pArg)
{
    FUN_140965410(FUN_1408b76f0(pObj->m_spEntity.FUN_1408a9280()), pArg);
}

// @0x140de6db0
bool FUN_140de6db0(TriggerObject* pObj)
{
    bool b = false;
    FUN_1408a20a0(reinterpret_cast<egf::Entity*>(pObj->m_spEntity.FUN_1408a9280()), 0xa0b6b179, &b);
    return b;
}

// @0x140de6e00
// MS2-FUNCTIONAL: locals/temporaries are laid out by the compiler; string temporaries differ
void TriggerObjectMesh::vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx)
{
    char bShow = pEvent->Arg()->vfunc_0();
    unsigned bFlag = pEvent->Arg()->vfunc_1();
    int nFade = pEvent->Arg()->vfunc_3();
    std::string strModel((const char*)pEvent->Arg()->vfunc_6());
    int nSkin = pEvent->Arg()->vfunc_5();
    float fFade = (float)nFade * 0.1f;
    char aId0[8];
    bool bOk = FUN_1403ed2d0()->FUN_141bd8e30(FUN_1408b6b20(aId0, FUN_1408b76f0(TRIG_ENT())), bShow, fFade);
    if (bShow != 0)
    {
        if (!FUN_1403af290(strModel))
        {
            efd::utf8string kMesh("Mesh");
            bool bIsMesh = FUN_1408a9bd0(TRIG_ENT())->ContainsModel(kMesh);
            if (bIsMesh)
            {
                strModel = std::string("urn:gamebryo-scenegraph:") + strModel;
                efd::AssetID kNew;
                efd::utf8string kUrn(FUN_1401d4890(strModel));
                FUN_140de0cb0(&kNew, &kUrn);
                efd::AssetID kCur;
                FUN_140998250(TRIG_ENT(), 0x770e5fc6, &kCur);
                if (FUN_140de8e70(&kCur, &kNew))
                {
                    FUN_1409457c0(TRIG_ENT(), 0x2d7cad2d, (float)nSkin);
                    FUN_140de8bd0(TRIG_ENT(), 0x770e5fc6, &kNew);
                }
            }
        }
    }
    FUN_140b60e40(TRIG_ENT_RAW(), bShow);
    NiAVObject* pRoot = FUN_141b6efc0(TRIG_ENT_RAW());
    if (pRoot != 0)
    {
        FUN_141851f90(pRoot, 0.0f);
        double dTime = FUN_141473280(FUN_14086d260());
        pRoot->Update((float)dTime, true);
    }
    char aId1[8];
    FUN_141545250(FUN_1408b6b20(aId1, FUN_1408b76f0(TRIG_ENT())), bFlag);
    if (bOk && !bSkipFx)
    {
        efd::utf8string kFx;
        if (bShow == 0)
            FUN_1408a2060(TRIG_ENT(), 0x6454a3bb, &kFx);
        else
            FUN_1408a2060(TRIG_ENT(), 0x6dd85c78, &kFx);
        if (!FUN_14096ad40(kFx))
        {
            Unk_TrigFxReq req;
            FUN_140a52ef0(&req);
            req.m_strName = FUN_1408ac310(kFx);
            req.m_nOwnerId = 0;
            char aId2[8];
            FUN_1409fabf0(&req.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8,
                FUN_141b6ef70(FUN_1408b6b20(aId2, FUN_1408b76f0(TRIG_ENT())))));
            FUN_1403ed280()->FUN_1411a4a00(&req);
            FUN_1405a89e0(&req);
        }
        void* pUi = FUN_140c9b540(0x4e29);
        if (pUi != 0)
            FUN_141a39d40(pUi, m_nId, bShow);
    }
}

// ---- TriggerObjectActor ----

// @0x140de7470
TriggerObjectActor::TriggerObjectActor()
{
}

// @0x140de74b0
void TriggerObjectActor::vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx)
{
    char bOn = pEvent->Arg()->vfunc_0();
    CStringA strAnim = pEvent->Arg()->vfunc_6();
    FUN_140b60e10(TRIG_ENT_RAW(), bOn);
    efd::utf8string kAnim((const char*)strAnim);
    const void* pId = FUN_1408b76f0(TRIG_ENT());
    FUN_141b6f910()->FUN_1409a1fc0(pId, kAnim, 1.0f, false);
    void* pUi = FUN_140c9b540(0x4e29);
    if (pUi != 0)
        FUN_141a39d40(pUi, m_nId, bOn);
}

// ---- TriggerObjectRope ----

// @0x140de7630
TriggerObjectRope::TriggerObjectRope()
{
}

// @0x140de7670
// MS2-FUNCTIONAL: locals/temporaries are laid out by the compiler
void TriggerObjectRope::vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx)
{
    char bShow = pEvent->Arg()->vfunc_0();
    bool bFlag = pEvent->Arg()->vfunc_0() != 0;
    int nFade = pEvent->Arg()->vfunc_3();
    float fFade = (float)nFade * 0.1f;
    char aId0[8];
    bool bOk = FUN_1403ed2d0()->FUN_141bd8e30(FUN_1408b6b20(aId0, FUN_1408b76f0(TRIG_ENT())), bShow, fFade);
    FUN_14098c6e0(TRIG_ENT(), 0x4df0c0de, bFlag);
    FUN_140b60e40(TRIG_ENT_RAW(), bShow);
    if (bOk && !bSkipFx)
    {
        efd::utf8string kFx;
        if (!bFlag)
            FUN_1408a2060(TRIG_ENT(), 0x6454a3bb, &kFx);
        else
            FUN_1408a2060(TRIG_ENT(), 0x6dd85c78, &kFx);
        if (!FUN_14096ad40(kFx))
        {
            Unk_TrigFxReq req;
            FUN_140a52ef0(&req);
            req.m_strName = FUN_1408ac310(kFx);
            req.m_nOwnerId = 0;
            char aId1[8];
            FUN_1409fabf0(&req.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8,
                FUN_141b6ef70(FUN_1408b6b20(aId1, FUN_1408b76f0(TRIG_ENT())))));
            FUN_1403ed280()->FUN_1411a4a00(&req);
            FUN_1405a89e0(&req);
        }
    }
}

// ---- TriggerObjectEffect ----

// @0x140de7960
TriggerObjectEffect::TriggerObjectEffect() : m_nHandle(0)
{
}

// @0x140de79a0
TriggerObjectEffect::~TriggerObjectEffect()
{
    if (m_nHandle != 0)
        FUN_1403ed280()->FUN_1411a6060(m_nHandle);
}

void FUN_140b60d30(float* pOut, void* pObj);                 // rotation (degrees)
void FUN_1409f7320(efd::Matrix3* p);
float FUN_140b60c90(void* pObj);
void FUN_140b60cd0(void* pOut, void* pObj);
void FUN_14027dcf0(void* pOut, void* pIn);
void FUN_14097faa0(void* pDst, void* pSrc);
CStringA FUN_140b60bf0(void* pObj);                          // effect name

// @0x140de7a00
// MS2-FUNCTIONAL: transform/request temporaries are laid out by the compiler
void TriggerObjectEffect::vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx)
{
    char bOn = pEvent->Arg()->vfunc_0();
    pEvent->Arg()->vfunc_1();
    pEvent->Arg()->vfunc_3();
    if (m_nHandle != 0)
        FUN_1403ed280()->FUN_1411a6060(m_nHandle);
    if (bOn != 0)
    {
        float aRot[3];
        FUN_140b60d30(aRot, TRIG_ENT_RAW());
        efd::Matrix3 kRot;
        FUN_1409f7320(&kRot);
        kRot.MakeZRotation(aRot[2]);
        Unk_TrigFxXform xf;
        FUN_140a332d0(&xf);
        xf.m_fScale = FUN_140b60c90(TRIG_ENT_RAW());
        char aTmp[24];
        FUN_140b60cd0(aTmp, TRIG_ENT_RAW());
        char aPos[16];
        FUN_14027dcf0(aPos, aTmp);
        FUN_14097faa0(xf.m_afTranslate, aPos);
        memcpy(&xf, &kRot, 0x24);
        Unk_TrigFxReq req;
        FUN_140a52ef0(&req);
        req.m_strName = FUN_140b60bf0(TRIG_ENT_RAW());
        req.m_nOwnerId = 0;
        req.m_pXform = &xf;
        m_nHandle = FUN_1403ed280()->FUN_1411a49c0(&req);
        FUN_1405a89e0(&req);
    }
}

// ---- TriggerObjectCube ----

// @0x140de7c90
TriggerObjectCube::TriggerObjectCube()
{
}

// @0x140de7cd0
void TriggerObjectCube::vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx)
{
    char b = pEvent->Arg()->vfunc_0();
    FUN_140b60e10(TRIG_ENT_RAW(), b);
}

// ---- TriggerObjectCamera ----

// camera path data (a keyed camera animation file) behind a counted pointer
struct Unk_CamPathData { CStringA m_strName; float m_fTime; };
struct Unk_CamPathObj { };
struct Unk_CamPath { void* m_pad_00; Unk_CamPathObj* m_p; };
Unk_CamPath* FUN_140943740(Unk_CamPath* pOut, CStringA strName);
void FUN_140944010(Unk_CamPath* pDst, Unk_CamPath* pSrc);
void FUN_140943f70(Unk_CamPath* p);
bool FUN_140944050(Unk_CamPath* p);
Unk_CamPathObj* FUN_140944060(Unk_CamPath* p);
Unk_CamPathData* FUN_140944280(Unk_CamPathObj* p);
void* FUN_140ad4b90();                                     // camera control singleton
void FUN_1418631c0(void* p);
void FUN_1418631f0(void* p, int nId, char b);
void FUN_141863260(void* p);
void FUN_140947440(Unk_FlyByCameraData* p);
void FUN_140ae7de0(Unk_CameraSetting* pDst, const Unk_CameraSetting* pSrc);
bool FUN_14028d470(float a, float b);
void* FUN_140967100();
void FUN_141b1feb0(void* p);
void* FUN_140a0afd0();
void* FUN_1409849b0(void* pHandle);
void* FUN_14098d0f0(void* pHandle);
void FUN_14098cb80(void* pIter, void* pNode);
void* FUN_14098e0d0(void* pIter, int n);
void FUN_14098cf00(void* pIter);
void FUN_1405a85c0(void* pHandle);
void* FUN_1409478e0(void* pNode);
void* FUN_140947900(void* pNode);
void FUN_140194470(void* pDst, const void* pSrc);
float FUN_141bcfc50(void* pPlayer);
void* FUN_141551ea0(void* pSvc, void* pOut, CStringA strPath, int a, int b, int c, int d);

class Unk_TrigCamMgr
{
public:
    void FUN_140af0b70(int n, float fA, float fB);
    void FUN_140af1a90();
    void FUN_140af7be0(unsigned n);
    void FUN_140aed180(Unk_CameraSetting* p);
    void FUN_140aed720(Unk_CameraSetting* p);
    void FUN_140aeffd0(Unk_FlyByCameraData* pOut, float fSpeed, Unk_CameraSetting* p);
    void FUN_140aed580(Unk_FlyByCameraData* p, int n, float f);
    void* FUN_1409478a0();
    void FUN_140aefb20(Unk_CamPathData* p);
    void FUN_140aed750(int n, int b);
    void FUN_140aed1c0();
    int FUN_140af7e30();
    Unk_StreamPoint FUN_140a17e10();                    // current mode: setting m_c (hidden return=rdx)
    Unk_StreamPoint FUN_140af8290();                    // current mode: setting m_18
};
Unk_TrigCamMgr* FUN_1409478c0();
float FUN_140ad4b40(Unk_TrigCamMgr* p);
float FUN_140af7f00(Unk_TrigCamMgr* p);
float FUN_140af7ea0(Unk_TrigCamMgr* p);
CCameraMode* FUN_140af24f0(Unk_TrigCamMgr* p);

// @0x140de7d40
TriggerObjectCamera::TriggerObjectCamera()
{
}

// @0x140de7d80
void TriggerObjectCamera::vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx)
{
    char bOn = pEvent->Arg()->vfunc_1();
    if (bOn != 0 || !bSkipFx)
    {
        FUN_1418631c0(FUN_140ad4b90());
        FUN_1418631f0(FUN_140ad4b90(), m_nId, bOn);
    }
}

Unk_CamPath* FUN_140de8c20(Unk_CamPath* p);

// @0x140de7e00
// MS2-FUNCTIONAL: a very large function; locals/temporaries are laid out by the compiler
void TriggerObjectCamera::vfunc_3()
{
    if (m_spEntity.FUN_1408b70b0(0) != 0)
        return;
    Unk_CameraSetting set;
    int nType = 1;
    efd::utf8string kPath;
    FUN_1408a2060(TRIG_ENT(), 0xdd2ac78a, &kPath);
    FUN_140961880(TRIG_ENT(), 0x88b558f6, &set.m_0);
    FUN_140961880(TRIG_ENT(), 0xd2c672d5, &set.m_4);
    FUN_140961880(TRIG_ENT(), 0x4b35f1d, &set.m_8);
    FUN_1409618c0(TRIG_ENT(), 0xfd95ca52, &set.m_c);
    FUN_1409618c0(TRIG_ENT(), 0x68c7c29d, &set.m_18);
    FUN_1408a20a0(TRIG_ENT(), 0x2310d55e, &set.m_24);
    FUN_140ae11a0(TRIG_ENT(), 0xc8cafec9, &nType);
    FUN_1409478c0()->FUN_140af0b70(1, set.m_4, set.m_8);
    float fSpeed = 0.0f;
    float fDur = 0.0f;
    FUN_140961880(TRIG_ENT(), 0x27bd7e0b, &fSpeed);
    FUN_140961880(TRIG_ENT(), 0x71056578, &fDur);
    bool bApplyNow = false;
    FUN_1408a20a0(TRIG_ENT(), 0x829fc57a, &bApplyNow);
    bool bUnknown = true;
    FUN_1408a20a0(TRIG_ENT(), 0xe6817e96, &bUnknown);
    FUN_1409478c0()->FUN_140af1a90();
    FUN_1409478c0()->FUN_140af7be0((unsigned)bUnknown);
    if (bApplyNow)
        FUN_1409478c0()->FUN_140aed180(&set);
    Unk_CamPath path;
    FUN_140de8c20(&path);
    int nMode = 5;
    if (!FUN_14096ad40(kPath))
    {
        Unk_CamPath tmp;
        FUN_140943740(&tmp, CStringA(FUN_1408ac310(kPath)));
        FUN_140944010(&path, &tmp);
        FUN_140943f70(&tmp);
    }
    else
    {
        nMode = 4;
    }
    if (fSpeed == 0.0f)
    {
        if (180.0f < set.m_18.x)
            set.m_18.x = set.m_18.x - 360.0f;
        if (180.0f < set.m_18.y)
            set.m_18.y = set.m_18.y - 360.0f;
        if (180.0f < set.m_18.z)
            set.m_18.z = set.m_18.z - 360.0f;
        FUN_1409478c0()->FUN_140aed720(&set);
    }
    else
    {
        Unk_FlyByCameraData fb;
        FUN_1409478c0()->FUN_140aeffd0(&fb, fSpeed, &set);
        fb.m_nKind = nType;
        FUN_1409478c0()->FUN_140aed580(&fb, nType, 1.0f);
    }
    if (!FUN_14096ad40(kPath) && FUN_14028d470(fSpeed, 0.0f) && FUN_140944050(&path))
    {
        CStringA strFile("./Data/Resource/Model/Camera/");
        strFile += FUN_140944280(FUN_140944060(&path))->m_strName;
        char aHandle[8];
        FUN_141551ea0(FUN_140a0afd0(), aHandle, CStringA(strFile), 0, 5, 0, 0);
        if (FUN_1409849b0(aHandle) != 0)
        {
            NiAVObject* pNode = (NiAVObject*)FUN_14098d0f0(aHandle);
            pNode->Update(0.0f, true);
            char aIter[48];
            FUN_14098cb80(aIter, FUN_1409849b0(aHandle));
            void* pChild;
            do
            {
                pChild = FUN_14098e0d0(aIter, 1);
                if (pChild == 0)
                    goto LAB_done;
            } while (FUN_14098d8d0(&DAT_143afa950, pChild) == 0);
            {
                Unk_StreamPoint euler = DAT_143b01a60;
                ((efd::Matrix3*)FUN_1409478e0(pChild))->ToEulerAnglesXYZ(euler.x, euler.y, euler.z);
                set.m_0 = FUN_141bcfc50(FUN_1403ed2d0());
                FUN_140194470(&set.m_c, FUN_140947900(pChild));
                euler.x = -((euler.x * 180.0f) / 3.1415927f);
                euler.y = -((euler.y * 180.0f) / 3.1415927f);
                euler.z = -((euler.z * 180.0f) / 3.1415927f);
                FUN_140194470(&set.m_18, &euler);
                FUN_1409478c0()->FUN_140aed720(&set);
            }
        LAB_done:
            FUN_14098cf00(aIter);
        }
        FUN_1405a85c0(aHandle);
    }
    *(float*)((char*)FUN_1409478c0()->FUN_1409478a0() + 0x20) = fDur;
    if (nMode == 5)
    {
        Unk_CamPath path2;
        FUN_140943740(&path2, CStringA(FUN_1408ac310(kPath)));
        if (FUN_140944050(&path2))
        {
            if (FUN_140944280(FUN_140944060(&path2))->m_fTime <= 0.0f && FUN_140944280(FUN_140944060(&path2))->m_fTime != 0.0f)
                FUN_140944280(FUN_140944060(&path2))->m_fTime = fDur;
            FUN_1409478c0()->FUN_140aefb20(FUN_140944280(FUN_140944060(&path2)));
        }
        FUN_140943f70(&path2);
    }
    if (nMode == 4)
        FUN_141b1feb0(FUN_140967100());
    FUN_1409478c0()->FUN_140aed750(nMode, 0);
    if (nMode == 4 && FUN_14028d470(fSpeed, 0.0f))
        FUN_141863260(FUN_140ad4b90());
    FUN_140943f70(&path);
}

// @0x140de86b0
// MS2-FUNCTIONAL: locals/temporaries are laid out by the compiler
void TriggerObjectCamera::vfunc_4()
{
    FUN_1409478c0()->FUN_140af7be0(1);
    FUN_1409478c0()->FUN_140aed1c0();
    if (FUN_1409478c0()->FUN_140af7e30() != 2)
    {
        efd::utf8string kPath;
        float fDur = 0.0f;
        int nType = 1;
        FUN_1408a2060(TRIG_ENT(), 0xdd2ac78a, &kPath);
        FUN_140961880(TRIG_ENT(), 0x71056578, &fDur);
        FUN_140ae11a0(TRIG_ENT(), 0x544859df, &nType);
        Unk_CamPath path;
        FUN_140943740(&path, CStringA(FUN_1408ac310(kPath)));
        if (FUN_140944050(&path))
        {
            if (FUN_140944280(FUN_140944060(&path))->m_fTime != -1.0f)
                fDur = FUN_140944280(FUN_140944060(&path))->m_fTime;
        }
        if (fDur == 0.0f)
        {
            FUN_1409478c0()->FUN_140aed750(2, 0);
        }
        else
        {
            Unk_FlyByCameraData fb;
            FUN_140947440(&fb);
            fb.m_fDuration = fDur;
            fb.m_nKind = nType;
            fb.m_from.m_0 = FUN_140ad4b40(FUN_1409478c0());
            fb.m_from.m_4 = FUN_140af7f00(FUN_1409478c0());
            fb.m_from.m_8 = FUN_140af7ea0(FUN_1409478c0());
            fb.m_from.m_c = FUN_1409478c0()->FUN_140a17e10();
            fb.m_from.m_18 = FUN_1409478c0()->FUN_140af8290();
            FUN_140ae7de0(&fb.m_to, &fb.m_from);
            fb.m_to.m_0 = FUN_140af24f0(FUN_1409478c0())->m_setting.m_0;
            fb.m_to.m_4 = FUN_140af24f0(FUN_1409478c0())->m_setting.m_4;
            fb.m_to.m_8 = FUN_140af24f0(FUN_1409478c0())->m_setting.m_8;
            fb.m_to.m_18 = FUN_140af24f0(FUN_1409478c0())->m_setting.m_18;
            FUN_1409478c0()->FUN_140aed580(&fb, nType, 1.0f);
            FUN_1409478c0()->FUN_140aed750(2, 1);
        }
        float fM8 = FUN_140af7ea0(FUN_1409478c0());
        float fM4 = FUN_140af7f00(FUN_1409478c0());
        FUN_1409478c0()->FUN_140af0b70(0, fM4, fM8);
        FUN_140943f70(&path);
    }
}

// ---- property cache and AssetID helpers ----

struct Unk_EntityAccess : public egf::Entity
{
    using egf::Entity::GetPropertyValueUnsafe;
    using egf::Entity::SetPropertyValueUnsafe;
};

void* FUN_1409481f0(void* pMap, void* pTmp);
void* FUN_140948250(void* pMap, void* pTmp, unsigned* pKey);
bool FUN_140947540(void* pA, void* pB);
void* FUN_140947580(void* pMap, unsigned* pKey);
void* FUN_140947490(void* pOut, unsigned nId, void* pValue, int nType);
int FUN_140998240();

// @0x140de8a40
// MS2-FUNCTIONAL: mirrors a changed AssetID property into the entity's property cache; map/iterator types are opaque
void FUN_140de8a40(egf::Entity* pEntity, unsigned nId, void* pValue)
{
    char* pRaw = (char*)pEntity;
    if (*(unsigned char*)(pRaw + 0xc8) != 0)
    {
        char aIt0[8];
        char aIt1[8];
        void* pEnd = FUN_1409481f0(pRaw + 0xd0, aIt0);
        void* pFind = FUN_140948250(pRaw + 0xd0, aIt1, &nId);
        if (FUN_140947540(pFind, pEnd))
        {
            efd::AssetID kCur;
            static_cast<Unk_EntityAccess*>(pEntity)->GetPropertyValueUnsafe(nId, &kCur, FUN_140998240());
            efd::AssetID* pCopy = FUN_140de8c90((efd::AssetID*)operator new(0x30), &kCur);
            char aEntry[0x18];
            FUN_140947490(aEntry, nId, pCopy, FUN_140998240());
            memcpy(FUN_140947580(pRaw + 0xd0, &nId), aEntry, 0x18);
        }
    }
}

// @0x140de8bd0
void FUN_140de8bd0(egf::Entity* pEntity, unsigned nId, efd::AssetID* pValue)
{
    FUN_140de8a40(pEntity, nId, pValue);
    static_cast<Unk_EntityAccess*>(pEntity)->SetPropertyValueUnsafe(nId, pValue, FUN_140998240());
}

// @0x140de8c90
// MS2-FUNCTIONAL: AssetID copy constructor as the exe compiled it (copy the urn, drop a trailing ':')
efd::AssetID* FUN_140de8c90(efd::AssetID* pDst, const efd::AssetID* pSrc)
{
    ::new (pDst) efd::AssetID(*pSrc);
    return pDst;
}

// @0x140de8c20
Unk_CamPath* FUN_140de8c20(Unk_CamPath* p)
{
    p->m_p = 0;
    return p;
}

// ---- TriggerStateCli ----

// @0x140de93d0
TriggerStateCli::TriggerStateCli(void* pOwner) : m_nPosX(-1), m_nPosY(-1), m_pOwner(pOwner)
{
}

// @0x140de9490
void TriggerStateCli::Load(void* pNode)
{
    FUN_140873420(pNode, "name", m_strName);
    FUN_1408731e0(pNode, "posX", m_nPosX);
    FUN_1408731e0(pNode, "posY", m_nPosY);
    void* pChild = FUN_140165cf0(pNode, "onEnter");
    if (pChild != 0)
        LoadActions(pChild, m_onEnter);
    pChild = FUN_140165cf0(pNode, "onExit");
    if (pChild != 0)
        LoadActions(pChild, m_onExit);
    pChild = FUN_140165cf0(pNode, "onTick");
    if (pChild != 0)
        LoadActions(pChild, m_onTick);
    for (void* pCond = FUN_140165cf0(pNode, "condition"); pCond != 0; pCond = FUN_140168650(pCond, "condition"))
        AddTransition(pCond);
}

// @0x140de9600
// MS2-FUNCTIONAL: the seven TiXmlElement locals are laid out by the compiler
void TriggerStateCli::Save(void* pNode)
{
    FUN_1408740a0(pNode, "name", GetName());
    FUN_140873ca0(pNode, "posX", GetPosX());
    FUN_140873ca0(pNode, "posY", GetPosY());
    Unk_g1_TiXmlElement elEnter;
    FUN_14086f2f0(&elEnter, "onEnter");
    for (size_t i = 0; i < m_onEnter.GetCount(); i++)
    {
        Unk_g1_TiXmlElement elAction;
        FUN_14086f2f0(&elAction, "action");
        FUN_1408740a0(&elAction, "name", m_onEnter[i]->GetName());
        SaveArgs(&elAction, *m_onEnter[i]->GetArgs());
        FUN_14086e000(&elEnter, &elAction);
        FUN_14086f450(&elAction);
    }
    FUN_14086e000(pNode, &elEnter);
    for (size_t j = 0; j < m_transitions.GetCount(); j++)
    {
        TransitionPtr spTrans(m_transitions[j]);
        if (!(spTrans->m_spCond == 0))
        {
            Unk_g1_TiXmlElement elCond;
            FUN_14086f2f0(&elCond, "condition");
            CStringW strName = spTrans->m_spCond->GetName();
            if (spTrans->m_spCond->GetNot() != 0)
                strName = FUN_1401d0160(L"!", strName);
            FUN_1408740a0(&elCond, "name", strName);
            SaveArgs(&elCond, *spTrans->m_spCond->GetArgs());
            for (size_t k = 0; k < spTrans->m_actions.GetCount(); k++)
            {
                Unk_g1_TiXmlElement elAction;
                FUN_14086f2f0(&elAction, "action");
                FUN_1408740a0(&elAction, "name", spTrans->m_actions[k]->GetName());
                SaveArgs(&elAction, *spTrans->m_actions[k]->GetArgs());
                FUN_14086e000(&elCond, &elAction);
                FUN_14086f450(&elAction);
            }
            if (FUN_140164830(GetName(), spTrans->m_strTarget))
            {
                Unk_g1_TiXmlElement elTrans;
                FUN_14086f2f0(&elTrans, "transition");
                FUN_1408740a0(&elTrans, "state", spTrans->m_strTarget);
                FUN_14086e000(&elCond, &elTrans);
                FUN_14086f450(&elTrans);
            }
            FUN_14086e000(pNode, &elCond);
            FUN_14086f450(&elCond);
        }
    }
    Unk_g1_TiXmlElement elExit;
    FUN_14086f2f0(&elExit, "onExit");
    for (size_t m = 0; m < m_onExit.GetCount(); m++)
    {
        Unk_g1_TiXmlElement elAction;
        FUN_14086f2f0(&elAction, "action");
        FUN_1408740a0(&elAction, "name", m_onExit[m]->GetName());
        SaveArgs(&elAction, *m_onExit[m]->GetArgs());
        FUN_14086e000(&elExit, &elAction);
        FUN_14086f450(&elAction);
    }
    FUN_14086e000(pNode, &elExit);
    FUN_14086f450(&elExit);
    FUN_14086f450(&elEnter);
}

// MS2-FUNCTIONAL: the obj's GetName() CStringW temporaries get a C++ EH state (__CxxFrameHandler3, 760 bytes); the exe function has no EH info (728 bytes) - the action name accessor's real return type/inline form is not recovered
// @0x140de9d40
bool TriggerStateCli::Validate(int* pnReason)
{
    size_t nEnter = m_onEnter.GetCount();
    if (*FUN_1401d7c10((char*)FUN_1401d3200() + 0x5758) < nEnter)
    {
        *pnReason = 1;
        return false;
    }
    for (unsigned i = 0; i < m_onEnter.GetCount(); i++)
    {
        if (FUN_14034eee0(m_onEnter.GetAt(i)->GetName(), L"DoChangeCubeState"))
        {
            *pnReason = 7;
            return false;
        }
    }
    if (m_onTick.GetCount() != 0)
    {
        *pnReason = 2;
        return false;
    }
    if (m_onExit.GetCount() != 0)
    {
        *pnReason = 2;
        return false;
    }
    size_t nTrans = m_transitions.GetCount();
    if (*FUN_1401d7c10((char*)FUN_1401d3200() + 0x57b0) < nTrans)
    {
        *pnReason = 3;
        return false;
    }
    for (unsigned j = 0; j < m_transitions.GetCount(); j++)
    {
        TriggerTransitionCli* pTrans = m_transitions.GetAt(j).get();
        if (pTrans != 0)
        {
            if (FUN_14034eee0(pTrans->m_spCond->GetName(), L"OnSwitchCube"))
            {
                *pnReason = 9;
                return false;
            }
            size_t nArgs = pTrans->m_actions.GetCount();
            if (*FUN_1401d7c10((char*)FUN_1401d3200() + 0x5808) < nArgs)
            {
                *pnReason = 5;
                return false;
            }
        }
    }
    return true;
}

// @0x140dea020
void TriggerStateCli::CollectIds(std::vector<std::pair<CStringW, int> >& rOut)
{
    for (size_t i = 0; i < m_onEnter.GetCount(); i++)
    {
        if (m_onEnter[i]->GetIntArg0() != 0)
        {
            int nId = m_onEnter[i]->GetIntArg0();
            rOut.push_back(std::make_pair(m_strName, nId));
        }
    }
    for (size_t j = 0; j < m_transitions.GetCount(); j++)
    {
        TransitionPtr spTrans(m_transitions[j]);
        if (spTrans->m_spCond == 0)
            continue;
        if (spTrans->m_spCond->GetIntArg0() != 0)
        {
            int nCondId = spTrans->m_spCond->GetIntArg0();
            rOut.push_back(std::make_pair(m_strName, nCondId));
        }
        for (size_t k = 0; k < spTrans->m_actions.GetCount(); k++)
        {
            if (spTrans->m_actions[k]->GetIntArg0() != 0)
            {
                int nActId = spTrans->m_actions[k]->GetIntArg0();
                rOut.push_back(std::make_pair(m_strName, nActId));
            }
        }
    }
}

// @0x140dea360
int TriggerStateCli::GetPosX()
{
    return m_nPosX;
}

// @0x140dea380
int TriggerStateCli::GetPosY()
{
    return m_nPosY;
}

// @0x140dea3a0
CStringW TriggerStateCli::GetName()
{
    return m_strName;
}

// @0x140dea3f0
void TriggerStateCli::SetPos(int nX, int nY)
{
    m_nPosX = nX;
    m_nPosY = nY;
}

// @0x140dea420
void TriggerStateCli::SetName(CStringW strName)
{
    m_strName = strName;
}

// @0x140dea470
void TriggerStateCli::AddOnEnter(ActionPtr spAction)
{
    m_onEnter.Add(spAction);
}

// @0x140dea4c0
void TriggerStateCli::AddTransition(TransitionPtr spTrans)
{
    m_transitions.Add(spTrans);
}

// @0x140dea510
TriggerStateCli::ActionPtr TriggerStateCli::GetOnEnter(int n)
{
    return m_onEnter[(unsigned)n];
}

// @0x140dea570
TriggerStateCli::TransitionPtr TriggerStateCli::GetTransition(int n)
{
    return m_transitions[(unsigned)n];
}

// @0x140dea5d0
unsigned __int64 TriggerStateCli::GetOnEnterCount()
{
    return m_onEnter.GetCount();
}

// @0x140dea600
unsigned __int64 TriggerStateCli::GetTransitionCount()
{
    return m_transitions.GetCount();
}

// @0x140dea630
void TriggerStateCli::AddTransition(void* pNode)
{
    MS2Ptr<TriggerConditionCli> spCond(TriggerConditionCli::Create(pNode).get());
    ATL::CAtlArray<ActionPtr> actions;
    LoadActions(pNode, actions);
    CStringW strState(m_strName);
    void* pTrans = FUN_140165cf0(pNode, "transition");
    if (pTrans != 0)
        FUN_140873420(pTrans, "state", strState);
    TransitionPtr spTrans(new TriggerTransitionCli(spCond, actions, CStringW(strState)));
    m_transitions.Add(spTrans);
}

// @0x140dea7f0
bool TriggerStateCli::LoadActions(void* pNode, ATL::CAtlArray<ActionPtr>& rOut)
{
    if (pNode == 0)
        return false;
    for (void* pAction = FUN_140165cf0(pNode, "action"); pAction != 0; pAction = FUN_140168650(pAction, "action"))
    {
        ActionPtr sp = TriggerActionCli::Create(pAction);
        if (!(sp == 0))
            rOut.Add(sp);
    }
    return true;
}

// @0x140dea8b0
void TriggerStateCli::SaveArgs(void* pElem, const ATL::CAtlArray<CStringW>& rArgs)
{
    for (size_t i = 0; i < rArgs.GetCount(); i++)
    {
        __int64 n = i + 1;
        CStringA strKey = FUN_1401d9af0("arg{0}", &n);
        FUN_1408740a0(pElem, strKey, rArgs.GetAt(i));
    }
}

// @0x140deb6d0
TriggerStateCli::~TriggerStateCli()
{
}

// ---- TriggerTransitionCli ----

// @0x140dec890
TriggerTransitionCli::TriggerTransitionCli(const MS2Ptr<TriggerConditionCli>& spCond,
                                           const ATL::CAtlArray<MS2Ptr<TriggerActionCli> >& rActions,
                                           CStringW strTarget)
    : m_spCond(spCond), m_strTarget(strTarget)
{
    m_actions.Copy(rActions);
}

// @0x140dec9a0
TriggerTransitionCli::~TriggerTransitionCli()
{
}

// ---- std::string helper glue (TriggerObject text compares, AssetID urn compares) ----

bool FUN_1409a1140(const void* pA, const void* pB);

// @0x140de8e30
bool FUN_140de8e30(const efd::utf8string& str, const char* psz)
{
    return FUN_140de9280(*reinterpret_cast<const std::string*>(&str), psz) == 0;
}

// @0x140de8e70
bool FUN_140de8e70(const efd::AssetID* a, const efd::AssetID* b)
{
    return FUN_140de8ea0((const char*)a + 8, (const char*)b + 8);
}

// @0x140de8ea0
bool FUN_140de8ea0(const void* pA, const void* pB)
{
    return !FUN_1409a1140(pA, pB);
}

// @0x140de9160
void FUN_140de9160(std::string& s, size_t n)
{
    s.resize(n);
}

// @0x140de91c0
void FUN_140de91c0(std::string& s)
{
    FUN_140de9160(s, 0);
}

// @0x140de91f0
void FUN_140de91f0(std::string& s)
{
    FUN_140de91c0(s);
}

// @0x140de9210
int FUN_140de9210(const std::string& s, const char* psz)
{
    return strcmp(s.c_str(), psz);
}

// @0x140de9280
int FUN_140de9280(const std::string& s, const char* psz)
{
    return FUN_140de9210(s, psz);
}

// @0x140de92b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

// @0x140dec770
MS2_EMIT_CRT_MEMMOVE_S_COPY(3);


// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca5ed0-0x142ca5f10 .text$yd
