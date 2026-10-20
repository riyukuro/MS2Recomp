// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ActionKeyObject and its 26 subclasses (the context actions of
// the action key) and MyPC's action set (Unk_ActionKeyManager).
// MS2-UNIT: ?\actionkeyobject.cpp
// MS2-RANGE: 0x140951c70-0x14096b300 .text$mn
// MS2-RANGE: 0x1400bf670-0x1400bf7b0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Destroy_range1@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@YAXPEAV?$MS2Ptr@VUnk_WsB_Lift@@@@0AEAV?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@0@U?$integral_constant@_N$0A@@0@@Z 0x140961ac0 ; unique
// MS2-PIN: ??$destroy@V?$MS2Ptr@VUnk_WsB_Lift@@@@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@1@QEAV?$MS2Ptr@VUnk_WsB_Lift@@@@@Z 0x140963750 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAUPortalAction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140963c30 ; unique
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsB_Lift@@@@QEAA@AEBV0@@Z 0x140963ff0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCNurturingCubeObject@@@@QEAA@AEBV0@@Z 0x140964070 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCNurturingCubeObject@@@@QEAA@H@Z 0x1409640b0 ; unique
// MS2-PIN: ??B?$SmartPointer@VUnk_WsB_Spawn@@@efd@@QEBAPEAVUnk_WsB_Spawn@@XZ 0x1409658c0 ; prop
// MS2-PIN: ??C?$MS2Ptr@VUnk_WsB_Lift@@@@QEBAPEAVUnk_WsB_Lift@@XZ 0x140965930 ; unique
// MS2-PIN: ??C?$MS2Ptr@VRideOffActionInteract@@@@QEBAPEAVRideOffActionInteract@@XZ 0x1409659a0 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$MS2Ptr@VCNurturingCubeObject@@@@V?$CElementTraits@V?$MS2Ptr@VCNurturingCubeObject@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VCNurturingCubeObject@@@@_K@Z 0x140966900 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCNurturingCubeObject@@@@AEBAXPEAX@Z 0x140969160 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@2@XZ 0x1409695d0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@_K@2@XZ 0x140969650 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_K@2@XZ 0x140969660 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@2@XZ 0x1409696f0 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VUnk_WsB_Lift@@@@XZ 0x140969a00 ; prop
// MS2-PIN: ?begin@?$vector@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@2@XZ 0x14096aab0 ; unique
// MS2-PIN: ?capacity@?$vector@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@QEBA_KXZ 0x14096ab10 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAUPortalAction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14096ab90 ; unique
// MS2-PIN: ?deallocate@?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@QEAAXQEAV?$MS2Ptr@VUnk_WsB_Lift@@@@_K@Z 0x14096ac50 ; unique
// MS2-PIN: ?end@?$vector@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@2@XZ 0x14096adc0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@_KV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@std@@@std@@@2@AEB_K@Z 0x14096ae20 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAUPortalAction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14096af70 ; unique
// MS2-PIN: ?size@?$vector@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@QEBA_KXZ 0x14096b140 ; unique
// MS2-PINS-END tplpin
// tplpin --simulate accepted pins (hand-pasted)
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x140953ce0
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@H@ATL@@SAHAEBH0@Z 0x140953d30
// MS2-PIN: ?Find@?$CRBTree@HV?$MS2Ptr@VActionKeyObject@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VActionKeyObject@@@@@3@@ATL@@IEBAPEAVCNode@12@AEBH@Z 0x140953d70
// MS2-PIN: ?InsertImpl@?$CRBTree@HV?$MS2Ptr@VActionKeyObject@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VActionKeyObject@@@@@3@@ATL@@AEAAPEAVCNode@12@AEBHAEBV?$MS2Ptr@VActionKeyObject@@@@@Z 0x140954040
// MS2-PIN: ??$?0UPortalAction@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAUPortalAction@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140960e50
// MS2-PIN: ??$destroy@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@1@@Z 0x140963730
// MS2-PIN: ??0?$MS2Ptr@VCHomemadeCubeObject@@@@QEAA@AEBV0@@Z 0x140963ec0
// MS2-PIN: ??1?$MS2Ptr@VCFunctionCubeObject@@@@QEAA@XZ 0x1409648f0
// MS2-PIN: ??1?$MS2Ptr@VUnk_PCBaseComp_b18@@@@QEAA@XZ 0x140964b60
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCube@@@@QEAAAEAV1@PEAVCube@@@Z 0x140965090
// MS2-PIN: ??8?$MS2Ptr@VCFieldDataCli@@@@QEBA_NPEAVCFieldDataCli@@@Z 0x140965240
// MS2-PIN: ??B?$SmartPointer@VRidee@@@efd@@QEBAPEAVRidee@@XZ 0x140965790
// MS2-PIN: ?get@?$MS2Ptr@VCFieldDataCli@@@@QEBAPEAVCFieldDataCli@@XZ 0x1409657a0
// MS2-PIN: ??B?$MS2Ptr@VCNurturingCubeObject@@@@QEBAPEAVCNurturingCubeObject@@XZ 0x140965800
// MS2-PIN: ??B?$MS2Ptr@VUnk_PCInteractMode@@@@QEBAPEAVUnk_PCInteractMode@@XZ 0x140965810
// MS2-PIN: ??B?$Unk_PayloadPtr@VCubeOwner@@@@QEBAPEAVCubeOwner@@XZ 0x140965820
// MS2-PIN: ?get@?$MS2Ptr@VUnk_PCBaseComp_b18@@@@QEBAPEAVUnk_PCBaseComp_b18@@XZ 0x140965850
// MS2-PIN: ??C?$MS2Ptr@VCNurturingCubeObject@@@@QEBAPEAVCNurturingCubeObject@@XZ 0x140965950
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCHomemadeCubeObject@@@@V?$CElementTraits@V?$MS2Ptr@VCHomemadeCubeObject@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCHomemadeCubeObject@@@@@Z 0x140966580
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VCNurturingCubeObject@@@@V?$CElementTraits@V?$MS2Ptr@VCNurturingCubeObject@@@@@ATL@@@ATL@@QEBA_KXZ 0x140966d90
// MS2-PIN: ?GetNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEBAPEAVCNode@12@PEB_WAEAI1AEAPEAV312@@Z 0x1409672c0
// MS2-PIN: ?get@?$MS2Ptr@VCInteractObject@@@@QEBAPEAVCInteractObject@@XZ 0x140967470
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCHomemadeCubeObject@@@@V?$CElementTraits@V?$MS2Ptr@VCHomemadeCubeObject@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x1409675f0
// MS2-PIN: ?SetCount@?$CAtlArray@V?$MS2Ptr@VCHomemadeCubeObject@@@@V?$CElementTraits@V?$MS2Ptr@VCHomemadeCubeObject@@@@@ATL@@@ATL@@QEAA_N_KH@Z 0x1409685a0
// MS2-PIN: ?AddRef@?$MS2Ptr@VCNurturingCubeObject@@@@AEBAXXZ 0x140968c30
// MS2-PIN: ?Reference@?$MS2Ptr@VCNurturingCubeObject@@@@CAXPEAVCNurturingCubeObject@@@Z 0x140968ef0
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_PCBaseComp_b18@@@@CAXPEAVUnk_PCBaseComp_b18@@@Z 0x140968fb0
// MS2-PIN: ?AddRefImpl@?$Unk_PayloadPtr@VCubeOwner@@@@AEBAXPEAX@Z 0x140969130
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@PEAX@2@@Z 0x140969540
// MS2-PIN: ?_Get_data@?$_String_alloc@U?$_String_base_types@DV?$CustomAllocator@D@efd@@@std@@@std@@QEAAAEAV?$_String_val@U?$_Simple_types@D@std@@@2@XZ 0x140969610
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@D@efd@@V?$_String_val@U?$_Simple_types@D@std@@@std@@$00@std@@QEAAAEAV?$_String_val@U?$_Simple_types@D@std@@@2@XZ 0x140969710
// MS2-PIN: ?Release@?$MS2Ptr@VCFieldDataCli@@@@AEAAXXZ 0x140969de0
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_PCBaseComp_b18@@@@AEAAXXZ 0x140969fa0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCNurturingCubeObject@@@@AEAAXPEAX@Z 0x14096a350
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_PCInteractMode@@@@AEAAXPEAX@Z 0x14096a3f0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_PCBaseComp_b18@@@@AEAAXPEAX@Z 0x14096a530
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAUPortalAction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x14096af00
// MS2-PIN: ??$Call@UPortalAction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAUPortalAction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAUPortalAction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x14096af40
//
// The unit has no __FILE__ string; its name comes from the classes and its directory is assumed. Names are Ghidra's
// (vfunc_<slot> / FUN_<va>) unless the exe has one (RTTI). The COMDAT tail: the action maps (CRBMap<int,
// MS2Ptr<ActionKeyObject>>), the entity smart pointers, the UI lookups (dynamic_cast to the dialog types), the
// PortalAction message-box delegate and the singleton accessors.
// The lift list (std::vector<MS2Ptr<Unk_WsB_Lift>>) and the cell list (std::vector<efd::Point3>): the exe's copies are
// byte-identical to other instances (by-name pairing would cross them), so they are pinned by call site.
// MS2-PIN: ??0?$vector@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@QEAA@XZ 0x140964560
// MS2-PIN: ??1?$vector@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@QEAA@XZ 0x140964ca0
// MS2-PIN: ?_Tidy@?$vector@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@AEAAXXZ 0x14096a830
// MS2-PIN: ?_Destroy@?$vector@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VUnk_WsB_Lift@@@@0@Z 0x140969470
// MS2-PIN: ??$_Destroy_range@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@YAXPEAV?$MS2Ptr@VUnk_WsB_Lift@@@@0AEAV?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@0@@Z 0x140961b80
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@2@XZ 0x140969790
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@2@XZ 0x1409695f0
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VUnk_WsB_Lift@@@@XZ 0x140969a20
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VUnk_WsB_Lift@@@@XZ 0x140969aa0
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VUnk_WsB_Lift@@@@XZ 0x140969b20
// MS2-PIN: ??_G?$MS2Ptr@VUnk_WsB_Lift@@@@QEAAPEAXI@Z 0x140965dc0
// MS2-PIN: ?_Reallocate_exactly@?$vector@VPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@AEAAX_K@Z 0x140969bc0
// MS2-PIN: ??$emplace_back@AEBVPoint3@efd@@@?$vector@VPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@QEAAXAEBVPoint3@efd@@@Z 0x140963790
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBVPoint3@efd@@@?$vector@VPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@AEAAXAEBVPoint3@efd@@@Z 0x140961c20
// MS2-PIN: ??$_Emplace_reallocate@AEBVPoint3@efd@@@?$vector@VPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@QEAAPEAVPoint3@efd@@QEAV23@AEBV23@@Z 0x140961ce0
// More look-alike smart-pointer glue, pinned by call site (NurturingCubeAction, InteractNpcAction, the cube data
// getters, the house owner map, the reactor data copy):
// MS2-PIN: ??1?$MS2Ptr@VCNurturingCubeObject@@@@QEAA@XZ 0x140964a40
// MS2-PIN: ??_G?$MS2Ptr@VCNurturingCubeObject@@@@QEAAPEAXI@Z 0x140965e40
// MS2-PIN: ??C?$MS2Ptr@VUnk_PCInteractMode@@@@QEBAPEAVUnk_PCInteractMode@@XZ 0x140965970
// MS2-PIN: ??C?$MS2Ptr@VFunctionCubeData@@@@QEBAPEAVFunctionCubeData@@XZ 0x1409658d0
// MS2-PIN: ??1?$pair@$$CB_KV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@QEAA@XZ 0x140964c80
// MS2-PIN: ??0?$MS2Ptr@VReactorData@@@@QEAA@AEBV0@@Z 0x140963e40
// MS2-PIN: ?Release@?$MS2Ptr@VCFunctionCubeObject@@@@AEAAXXZ 0x140969c60
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCFunctionCubeObject@@@@AEAAXPEAX@Z 0x14096a120
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCFieldDataCli@@@@AEAAXPEAX@Z 0x14096a300
// MS2-PIN: memmove_s 0x140954e40
// MS2-FUNCTIONAL: <cmath> sqrt(float): the exe imports sqrtf from the CRT DLL (indirect call); this build links it statically
// MS2-PIN: ?sqrt@@YAMM@Z 0x14096b1c0
// MS2-PIN: ??1?$MS2Ptr@VUnk_PCInteractMode@@@@QEAA@XZ 0x140964aa0
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VUnk_WsB_Lift@@@@V?$allocator@V?$MS2Ptr@VUnk_WsB_Lift@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VUnk_WsB_Lift@@@@XZ 0x140969a80
// TaxiStationAction / FishingAction have byte-identical implicit destructors (two exe copies each):
// MS2-PIN: ??1TaxiStationAction@@UEAA@XZ 0x140953ba0
// MS2-PIN: ??1FishingAction@@UEAA@XZ 0x140953b80
// MS2-PIN: ??_GTaxiStationAction@@UEAAPEAXI@Z 0x140953ca0
// MS2-PIN: ??_GFishingAction@@UEAAPEAXI@Z 0x140953c60
// MS2-PIN: ??$Unk_AkoMessage@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@@YAXHHHAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@0@Z 0x140961090
// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400bf790
// The UI lookup template's instances differ only in the RTTI they cast to:
// MS2-PIN: ??$Unk_GetUI@VUIActionTooltip@@@@YAPEAVUIActionTooltip@@H@Z 0x1409537f0
// MS2-PIN: ??$Unk_GetUI@VUIDungeonRoomDialog@@@@YAPEAVUIDungeonRoomDialog@@H@Z 0x140961550
// MS2-PIN: ??$Unk_GetUI@VUIWorldMapDialog@@@@YAPEAVUIWorldMapDialog@@H@Z 0x140961730
// MS2-PIN: ??$Unk_GetUI@VUIGuildFlagTooltip@@@@YAPEAVUIGuildFlagTooltip@@H@Z 0x1409615f0
// MS2-PIN: ??$Unk_GetUI@VUIRealEstateDialog@@@@YAPEAVUIRealEstateDialog@@H@Z 0x140961690
// MS2-PIN: ??$Unk_GetUI@VUIBanner@@@@YAPEAVUIBanner@@H@Z 0x1409614b0
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\actionkeyobject.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

// ---- header statics (.text$di): a shared header's sort names and condition keys, then egf's kENTITY_INVALID --------
// @0x1400bf670
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400bf730
static CString s_skill("skill");
// @0x1400bf760
static CString s_stun("stun");

#include "actionkeyobject.h"
#include "worldservice.h"
#include "mypc.h"
#include "ms2/placeholder/fishingmanager.h"
#include "ms2/placeholder/cube.h"
#include "ridee.h"
#include "ms2/placeholder/clientconstants.h"
#include "statedata.h"
#include "functioncubeobject.h"
#include "entityworldmanager.h"
#include <efd/ServiceManager.h>
#include "interactobject.h"
#include "reactor.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "uidialog.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/unnamed/unit_140ad1860.h"
#include "uimessageboxdata.h"
#include "fielddatacli.h"
#include "ms2/commonfiles/ugcmapdata.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/ms2format.h"
#include "partymanager.h"
#include "ms2/unnamed/unit_1401b6d10.h"
#include "ms2/commonfiles/rideonaction.h"
#include "uibanner.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/placeholder/mstime.h"
#include "inventory.h"
#include "questmanager_2.h"
#include <efd/EEMath.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <atlcoll.h>
#include <vector>

// ---- unrecovered neighbours ------------------------------------------------------------------------------------------
unsigned FUN_140869420();                                   // the frame tick (ms)
WorldService* FUN_1403ed2d0();
CStringW FUN_14028de60(int nStringId);                      // the client string table
CStringW FUN_14016a730(const char* psz, int nCodePage);      // multi-byte to wide

// A portal of the field (the world service's field objects; class of unit_14169afb0, unrecovered); only the members
// read here.
class Unk_AkoPortal : public CPtred
{
public:
    CStringW FUN_14169c3b0();                               // the portal's name
    int FUN_14169d280();                                    // moves to another field
    Unk_StreamPoint FUN_14169d2f0();                        // the portal's position
    egf::EntityID m_entityId;                               // +0x18 id of the egf entity
    char m_pad_20[0x14c - 0x20];
    int m_nFieldId;                                         // +0x14c the target field
    char m_pad_150[0x158 - 0x150];
    unsigned __int64 m_nOwnerId;                            // +0x158 the house owner (house portals)
    int m_nType;                                            // +0x160
    char m_pad_164[0x18c - 0x164];
    bool m_bConfirm;                                        // +0x18c ask before moving
};
MS2_CHECK_OFFSET(Unk_AkoPortal, m_entityId, 0x18);
MS2_CHECK_OFFSET(Unk_AkoPortal, m_nFieldId, 0x14c);
MS2_CHECK_OFFSET(Unk_AkoPortal, m_nOwnerId, 0x158);
MS2_CHECK_OFFSET(Unk_AkoPortal, m_nType, 0x160);
MS2_CHECK_OFFSET(Unk_AkoPortal, m_bConfirm, 0x18c);


// The cube map service (efd class id 0x06100017; named as in buddy.cpp); FUN_1401cd040 looks it up in the framework's
// service manager.
class Unk_Service6100017 : public efd::ISystemService
{
public:
    egf::EntityID FUN_1410cb1b0();                          // the entity of the house's fitting doll
    bool FUN_1410c35c0();                                   // the player is in a house
    Unk_StreamPoint FUN_1410b7ad0(PCBase* pActor, float fDist, Unk_StreamPoint* pOut, int bSnap);  // the cell in front of the actor
    Unk_StreamPoint FUN_1410b7a20(Unk_StreamPoint pt, Unk_StreamPoint* pOut);   // the cell position of a point
    Cube* FUN_1410b8ab0(Unk_StreamPoint pt);                // the cube at a cell position
    // The same three as PullObjectWeaponAction calls them (its cell list is a std::vector<efd::Point3>).
    efd::Point3 FUN_1410b7ad0(PCBase* pActor, float fDist, efd::Point3* pOut, int bSnap);
    efd::Point3 FUN_1410b7a20(efd::Point3 pt, efd::Point3* pOut);
    Cube* FUN_1410b8ab0(efd::Point3 pt);
    bool FUN_1410b7e80(Unk_StreamPoint pt);                 // a cube stands at a cell position
    void FUN_1410ccc00(int nMapId, int nType, int nSize);   // show the map's owner profile
    int FUN_1410c8580(int nGroup);                          // the error code for buying a house group (0 = ok)
    CStringW FUN_1410d5d80(int nError);                     // the text of a house error code
};
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;
extern Unk_StreamPoint DAT_143b01a60;                       // the zero point                // the game framework
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework* pFramework);

// The player's lifted object (MyPC::FUN_141523c00); only tested for null here.
class Unk_PCBaseComp_b18 : public CPtred
{
};
// The house's fitting doll as efd::DynamicCast sees it (class id 0x06200046; fittingdollpc.h's FittingDollPC has no
// CLASS_ID).
class Unk_AkoFittingDoll : public FittingDollPC
{
public:
    enum { CLASS_ID = 0x06200046 };
    // @0x140967160
    int FUN_140967160() { return unknown12e8; }             // the doll's item id
};
extern __int64 DAT_143af25f0;                              // the actor id of the house owner
CStringW FUN_14061ad70(const CStringW& str, const wchar_t* psz);   // str + psz
CStringW FUN_1401d0160(const wchar_t* psz, const CStringW& str);   // psz + str (the exe's out-of-line operator+; clang-cl
                                                            // would need the unresolvable MFC CopyChars import)
CStringW FUN_1401d0080(const CStringW& strA, const CStringW& strB); // strA + strB

// The house service singleton (global 0x143ab3908).
class Unk_AkoHouseSvc : public TSingleton<Unk_AkoHouseSvc>
{
public:
    std::map<unsigned __int64, Unk_CubeOwnerPtr>* FUN_1410d3380();  // the house owners by account (less<unsigned __int64> 0x14044a540)
    __int64 FUN_1410c3180();                                // the owner account of the current house
    bool FUN_1410c35c0();                                   // the player is in a house
    bool FUN_1410cb920(int nCooldown);                      // the move cooldown is over
};

// The guide manager (global 0x143ab3330).
class Unk_AkoGuide
{
public:
    void FUN_14138bf00(int nGuide, int nA, int nB);         // a guide event
    int FUN_14138c900(int nGuide);                          // the guide is running
};
Unk_AkoGuide* FUN_1409331e0();

extern int DAT_143ab288c;                                   // the id of the last portal used
extern __int64 DAT_143ab2820;                               // the account id
void FUN_141b71e70(egf::EntityID id, bool bEnable, unsigned uColor, bool bSkipEffectRoot);   // highlight an entity
void FUN_140d73aa0(CStringW strText, int nType, int nArg, CStringW strArg);   // a system notice text
void FUN_140d73bc0(int nStringId, int nType, IMessageListener* pListener, CStringW strArg);   // a system notice
void FUN_1408a0890(int nMapId, int nCubeId, int* pnKind);   // the kind of the cube on a map
void FUN_140dff580(int nTarget, int nPortalId);             // the shop portal (type 0x10)

class UIActionTooltip : public UIHeadUpDisplay
{
public:
    ActionKeyObject* FUN_1418b17d0();                       // the action shown
    CStringW FUN_1418b17f0();                               // the title shown
    CStringW FUN_1418b1840();                               // the text shown
    void FUN_1418b16f0();                                   // refresh from the current action
};

class Unk_AkoUIRef
{
public:
    ~Unk_AkoUIRef();                                        // 0x1403e5630
    UIObject* FUN_1403e8a70() const;
private:
    void* m_unk_00;
    UIObject* m_p;
};
MS2_CHECK_SIZE(Unk_AkoUIRef, 0x10);
class Unk_AkoUIMgr
{
public:
    Unk_AkoUIRef FUN_141adcea0(int nUiId);                  // the ui by id
    void FUN_141adc750(int nUiId);                          // toggle the ui by id
    int FUN_141adc940(int nUiId);                           // is open
    int FUN_141adc890(int nUiId);                           // is shown
    void FUN_141adc5d0(int nUiId);                          // hide
    void FUN_141adc530(int nUiId);                          // close
};
Unk_AkoUIMgr* FUN_1403ed2b0();
UIObject* FUN_1403ed9e0(Unk_AkoUIRef&);

// The UI by id, cast to its class (a template: one COMDAT per class in first-use order, see the pins at the top).
template <class T> T* Unk_GetUI(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_AkoUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (ref.FUN_1403e8a70() != 0)
            return dynamic_cast<T*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

class UIDungeonRoomDialog : public UIDialog
{
public:
    bool FUN_1412b8f00(int nPortalId);                      // the room list has the portal
    void FUN_1412b8ff0(int nArg);
    void FUN_1412b90d0(int nMode);
    void FUN_1412b90f0(int nPortalId);                      // select the portal's rooms
};
// The world service's lift / prop records (WorldService::FUN_141bc5a20 / FUN_141bc66b0); a prop is an interact object.
class Unk_WsB_Lift : public CPtred
{
public:
    int FUN_141447cc0();                                    // the lift's item id
    CString FUN_1414472a0();                                // the lift's name
    int FUN_141447340();                                    // can be lifted
    float FUN_141447ac0();                                  // the lift radius
    Unk_StreamPoint FUN_141447c80();                        // the lift's position
    void FUN_141447d50(int bHighlight);                     // highlight the lift
};
typedef MS2Ptr<Unk_WsB_Lift> Unk_WsB_LiftPtr;
// The world service's lift targets (WorldService::FUN_141bc5980, the values of its m_540: CLiftableTarget, the base of
// CLiftableTargetBox / CLiftableTargetGuide); a distinct pointer type from the lifts (the exe has a second copy of the
// vector code).
class Unk_AkoLiftTarget : public CPtred
{
public:
    // @0x1409673f0
    Unk_StreamPoint FUN_1409673f0() { return m_pos; }

    unsigned char m_unk_18[4];
    Unk_StreamPoint m_pos;                                  // +0x1c
};
MS2_CHECK_OFFSET(Unk_AkoLiftTarget, m_pos, 0x1c);
typedef MS2Ptr<Unk_AkoLiftTarget> Unk_AkoLiftTargetPtr;
class Unk_WsB_Prop : public CInteractObject
{
};
class Unk_WsB_Spawn : public CReactor                       // WorldService's reactor lookups
{
};
// The npc table row; only the talk script name is read here.
class Unk_AkoNpcData : public CPtred
{
public:
    unsigned char m_unk_18[0x448];
    CString m_strTalkScript;                                // +0x460
    int FUN_1406cd020();                                    // has a talk
};
MS2_CHECK_OFFSET(Unk_AkoNpcData, m_strTalkScript, 0x460);
// A world game object as WorldService returns it (an npc here); only the slots used here are named.
class Unk_WsC_GameObj
{
public:
    virtual void DeleteThis() const;                        // 0-2: efd::IBase reference counting
    virtual void IncRefCount() const;
    virtual void DecRefCount() const;
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool TypeCast(const efd::ClassID id, void** ppValue) const;   // 5: efd::IBase::TypeCast
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Unk_StreamPoint vfunc_18();                     // 18: the position
    CStringW FUN_141093310();                               // the npc name
    int FUN_14166ce30();                                    // dead (1)
    MS2Ptr<Unk_AkoNpcData> FUN_141093270();                 // the npc data
    int FUN_14123c580();                                    // the object id
    int FUN_14123c660();                                    // hidden
    int FUN_141092fa0();                                    // the npc id
    bool FUN_1416642a0();                                   // the pc is already being held (PC member)
    // @0x140967120
    bool FUN_140967120() { return m_bTalkable; }

    unsigned char m_unk_08[0xe48];
    bool m_bTalkable;                                       // +0xe50
};
MS2_CHECK_OFFSET(Unk_WsC_GameObj, m_bTalkable, 0xe50);
// The client string tables.
class Unk_AkoStrings
{
public:
    CStringW FUN_141811980(int nTable, int nId);            // a string of a table
    CStringW FUN_141812290(int nItemId, unsigned short nRarity, CString strKey);   // an item string
};
Unk_AkoStrings* FUN_1401a9d70();
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);   // a formatted client string
// The cutscene service singleton (global 0x143ab3900).
class Unk_AkoCutscene : public TSingleton<Unk_AkoCutscene>
{
public:
    int FUN_141b21220();                                    // a cutscene is playing
    int FUN_141b211d0();                                    // npc talk is enabled
};
class Unk_AkoSceneMgr
{
public:
    int FUN_1422b9e00();                                    // the current scene id
};
Unk_AkoSceneMgr* FUN_1408e57f0();
int FUN_141276980();                                        // npc talk is allowed

// The world service's portal / current field lookups with their true return types (worldservice.h spells them with
// stand-in types), and the object-of-entity lookup with its by-value id (the exe copies the id into a temporary,
// EntityID copy ctor 0x1408b6b20; worldservice.h says const&, the same callee ABI); the world service is viewed
// through this class.
class Unk_AkoWorldView
{
public:
    Unk_WsC_GameObj* FUN_141bd0fa0(egf::EntityID id);       // the game object of an entity
    MS2Ptr<Unk_AkoPortal> FUN_141bc2800(int nPortalId);     // the portal by id
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                  // the current field
};
// The quest manager (FUN_140764020); the quest state at +0x10.
class Unk_AkoQuestState { public: int FUN_140745590(int nQuestId); };   // the quest is complete
class Unk_AkoQuestGlobal
{
public:
    void FUN_1416d12d0(int nNpcId, Unk_QmNpcQuestState* pState, int nMode);   // the npc's quest state
    int FUN_1416cebf0(int nNpcId);                          // the npc has a quest talk
    std::pair<int, __int64> FUN_1416d1e90();                // the user the quest asks to find (quest id, character id)
    void* m_0;
    void* m_8;
    Unk_AkoQuestState m_state;
};
Unk_AkoQuestGlobal* FUN_140764020();
int FUN_140855d10(int nNpcId);                              // the npc has an event talk
Unk_Int3 FUN_1408a1430(Unk_StreamPoint pt);                 // the cube cell of a world position
// MyPC's npc in front with its true return type (mypc.h spells it PCBase*).
class Unk_AkoPlayerView
{
public:
    Unk_WsC_GameObj* FUN_141529640();                       // the npc the player faces
    int FUN_141659690();                                    // a liftable is being put down (PC member)
    __int64 FUN_141656ad0();                                // the account id (PC member)
    int FUN_14165c1b0(int* pnId, CString* pstrName, float fRange);   // the nearest holdable target (PC member)
    int FUN_1415279d0(Unk_WsC_GameObj* pTarget);            // the pc may be held (MyPC member)
    int FUN_14152e060();                                    // the id of the held pc (MyPC member)
    void FUN_14152df80();                                   // release the held pc (MyPC member)
};
bool FUN_140a55d20(CFieldDataCli* pField, CStringW* pstrError);   // the field can be entered (else the reason)
CStringW FUN_1416e4df0(int nQuestId);                       // the quest name
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);   // a formatted string by key
CStringW FUN_14028b8e0(const CStringW& strKey);             // a string by key
// Micro-game banner (BannerAction).
bool FUN_140b7f400(MyPC* pPlayer);                          // the player can join a micro game
class Unk_PCBaseComp_ac8 : public CPtred                    // PCBase slot 87 (UIBanner::Entity)
{
public:
    int FUN_140ba8700();                                    // the banner type
};
int FUN_141274b10(Unk_WsC_GameObj* pObj);                   // object list filter: player characters
// The local player as efd::DynamicCast sees it (class id 0x06200004; mypc.h's MyPC has no CLASS_ID).
class Unk_AkoMyPC : public MyPC
{
public:
    enum { CLASS_ID = 0x06200004 };
};
float FUN_140966ea0(NiPoint3 ptA, NiPoint3 ptB);            // planar distance (nipoint3.h's, called with NiPoint3s)
void FUN_1412751f0(const CStringW& strText, int nA, int nB);   // a center notice
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);   // a new message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                // show a message box

// The interact object's required items (CInteractObjectData::m_aReqItem) as its accessors see them: the vector is the
// first member of a list object (the exe takes the list and reads the vector at +0). The first item's id and rarity.
struct Unk_AkoReqItemList
{
    std::vector<Unk_InteractReqItem> m_v;
};
unsigned FUN_140966f40(const Unk_AkoReqItemList& list);
unsigned short FUN_140966f80(const Unk_AkoReqItemList& list);
// The mastery data singleton (global 0x143ab02e0).
class Unk_MData
{
public:
    CStringW FUN_14066bdd0(int nType);                      // the mastery name
    CStringW FUN_14066c690(int nType, int nGrade);          // the mastery grade name
};
extern Unk_MData* DAT_143ab02e0;
// @0x1409670c0
inline Unk_MData* FUN_1409670c0() { return DAT_143ab02e0; }
void FUN_141275260(int nStringId, int nA, int nB);          // a center notice by string id
void FUN_141275460(int nStringId, int nA, int nB, const fmt::ArgList& args);
// fmt center notices with one / two arguments (the originals are templates over the argument types).
template <class A> void Unk_AkoMessage(int nStringId, int nA, int nB, const A& x)
{
    const fmt::internal::ArgArray<1>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(x)};
    FUN_141275460(nStringId, nA, nB, fmt::ArgList(fmt::internal::make_type(x), values));
}
template <class A, class B> void Unk_AkoMessage(int nStringId, int nA, int nB, const A& x, const B& y)
{
    const fmt::internal::ArgArray<2>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(x),
        fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(y)};
    FUN_141275460(nStringId, nA, nB, fmt::ArgList(fmt::internal::make_type(x, y), values));
}

// @0x1409670b0 the function cube service singleton
inline CFunctionCubeService* FUN_1409670b0() { return TSingleton<CFunctionCubeService>::s_instance; }
int FUN_140b60d90(egf::Entity* pEntity);
float FUN_140966f00(Unk_StreamPoint a, Unk_StreamPoint b);  // the distance of two points
int FUN_1408a1360(Unk_StreamPoint a, Unk_StreamPoint b);   // the points are on the same level
int FUN_1408a2060(egf::Entity* pEntity, unsigned nProperty, efd::utf8string* pOut);   // read a string property (0 = ok)
int FUN_1408a03c0(Unk_Int3 pt);                             // the packed key of a cube cell                    // the banner id of a ugc banner entity

// @0x140960c30 an action caption: the string with the argument, cut at '-' when the argument is empty
CStringW FUN_140960c30(int nStringId, CStringW strArg)
{
    CStringW strText = FUN_14052bd00(nStringId, strArg);
    if (strArg.GetLength() == 0)
    {
        int nPos = strText.Find(L'-');
        if (nPos != -1)
            return strText.Left(nPos);
    }
    return strText;
}
MS2_REPLACE(0x140960C30, FUN_140960c30, 221, 0x7CEA45B7);

// The cube craft controller of the player (MyPC::FUN_141530290).
class Unk_PCCubeCraft
{
public:
    void FUN_1410aad50();                                   // put the lifted cube down
};
// The ugc manager singleton.
class Unk_AkoUgcMgr
{
public:
    void FUN_14187f590(efd::SmartPointer<egf::Entity> spEntity);   // open the ugc registration for the entity
};
Unk_AkoUgcMgr* FUN_14052d220();

class UIGuildFlagTooltip : public UIDialog
{
public:
    void FUN_1412c45a0();                                   // hide
    void FUN_1412c4050(const CString& strObjectId);         // show for the interact object
};
class UIRealEstateDialog : public UIDialog
{
public:
    void FUN_141ab4000(int nGroup, int nMapId);             // open on a group
};
class UIWorldMapDialog : public UIDialog
{
public:
    void FUN_141b5af80(int nMode);                          // the taxi mode
};

// The taxi station lists (CAtlArray<int>): the known stations (0x143ab3078) and the stations already reported to the
// server (0x143ab3098).
class Unk_AkoTaxiList
{
public:
    void FUN_1401855a0(int n);                              // push_back
    int FUN_140408410(const int* pValue);                   // index of a value (-1: absent)
};
extern Unk_AkoTaxiList DAT_143ab3078;
extern Unk_AkoTaxiList DAT_143ab3098;
extern int DAT_143ab2870;                                   // the current map id
// The player's movement controller (PCBase +0x6d8; PCBase::FUN_14166d240 hands it out as void*).
class Unk_AkoPCMove
{
public:
    bool FUN_141683ef0();                                   // the player stands still on the ground
};

// The house privileges of the local player (MyPC +0x1628; commonfiles\homeprivilege.cpp).
class CHomePrivilege : public CPtred
{
public:
    int FUN_14050d6f0(int nPortalId);                       // the player may use the house portal
    int FUN_14050da30();                                    // the player may use the house taxi
    MyPC* m_pOwner;                                         // +0x18
};

// ---- Unk_ActionKeyManager --------------------------------------------------------------------------------------------
// @0x140951c70
Unk_ActionKeyManager::Unk_ActionKeyManager()
{
    m_actions.SetAt(0x13, new PortalAction());
    m_actions.SetAt(0x16, new BuyCubeAction());
    m_actions.SetAt(0x15, new LiftCubeAction());
    m_actions.SetAt(0x14, new TalkAction());
    m_actions.SetAt(0xd, new PullObjectWeaponAction());
    m_actions.SetAt(0x12, new InteractAction());
    m_actions.SetAt(0x11, new InteractNpcAction());
    m_actions.SetAt(0x18, new BillBoardInteractAction());
    m_actions.SetAt(0x10, new RegistUgcAction());
    m_actions.SetAt(1, new FunctionCubeAction());
    m_actions.SetAt(0xe, new FittingDollAction());
    m_actions.SetAt(9, new ViewCubeMapProfileAction());
    m_actions.SetAt(8, new TaxiStationAction());
    m_actions.SetAt(6, new HoldAction());
    m_actions.SetAt(4, new GatheringAction());
    m_actions.SetAt(2, new HomemadeCubeAction());
    m_actions.SetAt(3, new NurturingCubeAction());
    m_actions.SetAt(0x19, new BannerAction());
    m_actions.SetAt(0x1a, new ReactorAction());
    m_actions.SetAt(0x1b, new HoldPCAction());
    m_actions.SetAt(0, new ReleasePCAction());
    m_actions.SetAt(7, new QuestUserFindAction());
    m_actions.SetAt(0x1c, new TreeWateringAction());
    m_actionsCubeMode.SetAt(0x13, new PortalAction());
    m_actionsCubeMode.SetAt(0x16, new BuyCubeAction());
    m_actionsCubeMode.SetAt(0x14, new TalkAction());
    m_actionsCubeMode.SetAt(0xc, new PutDownLiftableAction());
    m_actionsFishing.SetAt(5, new FishingAction());
    m_nCur = 0x1e;
    m_nNextTick = 0;
    m_bEnabled = 1;
}

// @0x140952e70
Unk_ActionKeyManager::~Unk_ActionKeyManager()
{
    m_actions.RemoveAll();
    m_actionsCubeMode.RemoveAll();
    m_actionsFishing.RemoveAll();
}

// @0x140952ef0
void Unk_ActionKeyManager::FUN_140952ef0()
{
    unsigned nNow = FUN_140869420();
    if (nNow - m_nNextTick < 100)
        return;
    if (!m_bEnabled)
        return;
    m_nNextTick = nNow;
    int bRefresh = 0;
    int nType = 0x1e;
    Unk_ActionKeyMap* pActions = FUN_140953770();
    for (POSITION pos = pActions->GetHeadPosition(); pos; pActions->GetNext(pos))
    {
        MS2Ptr<ActionKeyObject> spAction = pActions->GetValueAt(pos);
        if (spAction->vfunc_1())
        {
            nType = pActions->GetKeyAt(pos);
            if (spAction->vfunc_10())
                bRefresh = 1;
            break;
        }
    }
    if (m_nCur != nType)
    {
        int bAccept = 1;
        MS2Ptr<ActionKeyObject> spOld(0);
        MS2Ptr<ActionKeyObject> spNew(0);
        if (pActions->Lookup(m_nCur, spOld))
            spOld->vfunc_3();
        if (pActions->Lookup(nType, spNew))
            bAccept = spNew->vfunc_4();
        if (bAccept)
        {
            m_nCur = nType;
            bRefresh = 1;
        }
    }
    else if (UIActionTooltip* pTooltip = Unk_GetUI<UIActionTooltip>(0x4e5c))
    {
        if (ActionKeyObject* pCur = FUN_140953550())
        {
            if (pTooltip->FUN_1418b17d0() != pCur)
                bRefresh = 1;
            else if (pTooltip->FUN_1418b17f0() != pCur->vfunc_7())
                bRefresh = 1;
            else if (pTooltip->FUN_1418b1840() != pCur->vfunc_6())
                bRefresh = 1;
        }
    }
    if (bRefresh)
    {
        if (UIActionTooltip* pTooltip = Unk_GetUI<UIActionTooltip>(0x4e5c))
            pTooltip->FUN_1418b16f0();
    }
}
MS2_REPLACE_METHOD(0x140952EF0, Unk_ActionKeyManager, FUN_140952ef0, 1042, 0x13A46E5D);

// @0x140953310
void Unk_ActionKeyManager::FUN_140953310()
{
    if (m_nCur == 0x1e)
        return;
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    if (!pActions->Lookup(m_nCur, spAction))
        return;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_14165f100())
        return;
    spAction->vfunc_2();
    if (TSingleton<CMouseController>::GetInstance()->FUN_140ad21b0())
        TSingleton<CMouseController>::GetInstance()->FUN_140ad22d0();
}
MS2_REPLACE_METHOD(0x140953310, Unk_ActionKeyManager, FUN_140953310, 248, 0x47B4C32E);

// @0x140953410
bool Unk_ActionKeyManager::FUN_140953410()
{
    if (m_nCur == 0x1e)
        return false;
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    if (!pActions->Lookup(m_nCur, spAction))
        return false;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return false;
    if (spAction->vfunc_11())
    {
        spAction->vfunc_2();
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140953410, Unk_ActionKeyManager, FUN_140953410, 282, 0x61BC001A);

// @0x140953530
int Unk_ActionKeyManager::FUN_140953530()
{
    return m_nCur;
}
MS2_REPLACE_METHOD(0x140953530, Unk_ActionKeyManager, FUN_140953530, 13, 0xA5869133);

// @0x140953550
ActionKeyObject* Unk_ActionKeyManager::FUN_140953550()
{
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    pActions->Lookup(m_nCur, spAction);
    return spAction.get();
}
MS2_REPLACE_METHOD(0x140953550, Unk_ActionKeyManager, FUN_140953550, 104, 0x73B9BB61);

// @0x1409535c0
void Unk_ActionKeyManager::FUN_1409535c0()
{
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    if (pActions->Lookup(m_nCur, spAction))
        spAction->vfunc_3();
    m_nCur = 0x1e;
    m_nNextTick = FUN_140869420() + 2000;
    if (UIActionTooltip* pTooltip = Unk_GetUI<UIActionTooltip>(0x4e5c))
        pTooltip->FUN_1418b16f0();
}
MS2_REPLACE_METHOD(0x1409535C0, Unk_ActionKeyManager, FUN_1409535c0, 188, 0xEBB060BC);

// @0x140953690
int Unk_ActionKeyManager::FUN_140953690()
{
    return m_bEnabled;
}
MS2_REPLACE_METHOD(0x140953690, Unk_ActionKeyManager, FUN_140953690, 17, 0x444DCEE7);

// @0x1409536b0
void Unk_ActionKeyManager::FUN_1409536b0(int bEnable)
{
    m_bEnabled = bEnable;
}
MS2_REPLACE_METHOD(0x1409536B0, Unk_ActionKeyManager, FUN_1409536b0, 25, 0x79F379CB);

// @0x1409536d0
void Unk_ActionKeyManager::FUN_1409536d0()
{
    if (m_nCur == 0x1e)
        return;
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    if (!pActions->Lookup(m_nCur, spAction))
        return;
    spAction->vfunc_9();
}
MS2_REPLACE_METHOD(0x1409536D0, Unk_ActionKeyManager, FUN_1409536d0, 147, 0xB05C022E);

// @0x140953770
Unk_ActionKeyMap* Unk_ActionKeyManager::FUN_140953770()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return &m_actions;
    if (pPlayer->FUN_1416595d0())
        return &m_actionsCubeMode;
    if (TSingleton<CFishingManager>::GetInstance()->FUN_140954150())
        return &m_actionsFishing;
    return &m_actions;
}
MS2_REPLACE_METHOD(0x140953770, Unk_ActionKeyManager, FUN_140953770, 113, 0xBF74575B);

// ---- ActionKeyObject -------------------------------------------------------------------------------------------------
// @0x140954f60
ActionKeyObject::ActionKeyObject() {}
// @0x140954fa0
ActionKeyObject::~ActionKeyObject() {}
// @0x140954fd0
int ActionKeyObject::vfunc_1() { return 0; }
MS2_REPLACE_METHOD(0x140954FD0, ActionKeyObject, vfunc_1, 8, 0x7F371472);
// @0x140954fe0
void ActionKeyObject::vfunc_2() {}
MS2_REPLACE_METHOD(0x140954FE0, ActionKeyObject, vfunc_2, 6, 0xA9AF6E37);
// @0x140954ff0
void ActionKeyObject::vfunc_3() {}
MS2_REPLACE_METHOD(0x140954FF0, ActionKeyObject, vfunc_3, 6, 0xA9AF6E37);
// @0x140955000
int ActionKeyObject::vfunc_4() { return 1; }
MS2_REPLACE_METHOD(0x140955000, ActionKeyObject, vfunc_4, 11, 0x30025ED0);
// @0x140955020
int ActionKeyObject::vfunc_5() { return 0x1e; }
MS2_REPLACE_METHOD(0x140955020, ActionKeyObject, vfunc_5, 11, 0x9C560DCD);
// @0x140955040
CStringW ActionKeyObject::vfunc_6() { return L""; }
MS2_REPLACE_METHOD(0x140955040, ActionKeyObject, vfunc_6, 61, 0x637B041B);
// @0x140955090
CStringW ActionKeyObject::vfunc_7() { return L""; }
MS2_REPLACE_METHOD(0x140955090, ActionKeyObject, vfunc_7, 61, 0x97EE3BD8);
// @0x1409550e0
CStringW ActionKeyObject::vfunc_8() { return L"key"; }
MS2_REPLACE_METHOD(0x1409550E0, ActionKeyObject, vfunc_8, 61, 0x56AA9F80);
// @0x140955130
void ActionKeyObject::vfunc_9() {}
MS2_REPLACE_METHOD(0x140955130, ActionKeyObject, vfunc_9, 6, 0xA9AF6E37);
// @0x140955140
int ActionKeyObject::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x140955140, ActionKeyObject, vfunc_10, 8, 0x7F371472);
// @0x140954140
bool ActionKeyObject::vfunc_11() { return false; }
MS2_REPLACE_METHOD(0x140954140, ActionKeyObject, vfunc_11, 8, 0x41132FCD);
// @0x140955150
Unk_AkoTarget ActionKeyObject::vfunc_12() { return Unk_AkoTarget(); }
MS2_REPLACE_METHOD(0x140955150, ActionKeyObject, vfunc_12, 34, 0x5E6446D1);

// ---- TaxiStationAction ----------------------------------------------------------------------------------------------
// @0x140953a80
TaxiStationAction::TaxiStationAction() {}
// @0x14095bf90
int TaxiStationAction::vfunc_5() { return 8; }
MS2_REPLACE_METHOD(0x14095BF90, TaxiStationAction, vfunc_5, 11, 0x2093C54B);
// MS2-FUNCTIONAL: exe passes the point to WorldService::FUN_141bcfd30 by value (rep movsb copy); shared header declares const&
// @0x14095bca0
int TaxiStationAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_14166ce30() != 0)
        return 0;
    if (!static_cast<Unk_AkoPCMove*>(pPlayer->FUN_14166d240())->FUN_141683ef0())
        return 0;
    if (pPlayer->FUN_14166c930() == 0x25)
        return 0;
    egf::Entity* pStation = FUN_1403ed2d0()->FUN_141bcfd30(0x85359406, pPlayer->FUN_1416767d0(),
        *FUN_1401d3200()->TaxiStationFindDistance.Get(), 1, 0);
    if (!pStation)
        return 0;
    bool bHouse = false;
    pStation->GetPropertyValue(0xe725ea17, bHouse);
    if (bHouse)
    {
        if (pPlayer->FUN_140967010()->FUN_14050da30() == 0)
            return 0;
    }
    else
    {
        if (DAT_143ab3078.FUN_140408410(&DAT_143ab2870) < 0)
        {
            if (DAT_143ab3098.FUN_140408410(&DAT_143ab2870) >= 0)
                return 0;
            DAT_143ab3098.FUN_1401855a0(DAT_143ab2870);
            COutPacket packet(0x48);
            packet.Encode1(0);
            FUN_140710590(packet);
            return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14095BCA0, TaxiStationAction, vfunc_1, 572, 0xE33AD181);
// @0x14095bef0
void TaxiStationAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (FUN_1403ed2b0()->FUN_141adc940(0x4e42))
        FUN_1403ed2b0()->FUN_141adc530(0x4e42);
    if (UIWorldMapDialog* pDialog = Unk_GetUI<UIWorldMapDialog>(0x4e42))
        pDialog->FUN_141b5af80(1);
    FUN_1409331e0()->FUN_14138bf00(0x11, 0, 0);
}
MS2_REPLACE_METHOD(0x14095BEF0, TaxiStationAction, vfunc_2, 144, 0x65EC98D4);
// @0x14095bfb0
CStringW TaxiStationAction::vfunc_6() { return FUN_14028de60(0x64a); }
MS2_REPLACE_METHOD(0x14095BFB0, TaxiStationAction, vfunc_6, 58, 0x4AB33250);

// ---- FishingAction ---------------------------------------------------------------------------------------------------
// @0x140953a50
FishingAction::FishingAction() {}
// @0x14095cf80
int FishingAction::vfunc_1() { return TSingleton<CFishingManager>::GetInstance()->FUN_140cdb250(); }
MS2_REPLACE_METHOD(0x14095CF80, FishingAction, vfunc_1, 27, 0xB7D79C18);
// @0x14095cfb0
void FishingAction::vfunc_2() { TSingleton<CFishingManager>::GetInstance()->FUN_140cdb1e0(); }
MS2_REPLACE_METHOD(0x14095CFB0, FishingAction, vfunc_2, 27, 0x585EBA68);
// @0x14095cfe0
int FishingAction::vfunc_5() { return 5; }
MS2_REPLACE_METHOD(0x14095CFE0, FishingAction, vfunc_5, 11, 0xCA9EB45C);
// @0x14095d000
CStringW FishingAction::vfunc_6() { return FUN_14028de60(0x658); }
MS2_REPLACE_METHOD(0x14095D000, FishingAction, vfunc_6, 58, 0x6AB4AFF6);

// ---- PortalAction ----------------------------------------------------------------------------------------------------
// @0x140955180
PortalAction::PortalAction() : m_spPortal(0) {}
// @0x1409551f0
PortalAction::~PortalAction()
{
    m_spEntity = 0;
    m_spPortal = 0;
}
// @0x140955990
void PortalAction::vfunc_3()
{
    if (FUN_1403ed2b0()->FUN_141adc890(0x4ebd))
        FUN_1403ed2b0()->FUN_141adc5d0(0x4ebd);
}
MS2_REPLACE_METHOD(0x140955990, PortalAction, vfunc_3, 54, 0xFD8A0CBF);
// @0x140955280
int PortalAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_1416595d0())
        return 0;
    if (FUN_1409331e0()->FUN_14138c900(9))
        return 0;
    m_spEntity = 0;
    m_spPortal = 0;
    Unk_StreamPoint pos = pPlayer->FUN_1416767d0();
    ATL::CAtlArray<MS2Ptr<Unk_AkoPortal> > aPortals;
    FUN_1403ed2d0()->FUN_141bc2c90(pos, &aPortals);
    if (aPortals.GetCount() == 0)
    {
        DAT_143ab288c = 0;
        return 0;
    }
    for (size_t i = 0; i < aPortals.GetCount(); i++)
    {
        MS2Ptr<Unk_AkoPortal> spPortal = aPortals[i];
        efd::SmartPointer<egf::Entity> spEntity =
            TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(spPortal->m_entityId);
        if (!spEntity)
            continue;
        bool bVisible = false;
        spEntity->GetPropertyValue(0x14969c28, bVisible);
        if (bVisible)
        {
            int nPortalId;
            spEntity->GetPropertyValue(0x60f82816, nPortalId);
            if (DAT_143ab288c == nPortalId)
                return 1;
            m_spEntity = spEntity;
            m_spPortal = spPortal;
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140955280, PortalAction, vfunc_1, 753, 0x5083C8D8);
// @0x140955580
void PortalAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_1416595d0())
        return;
    if (m_spEntity == 0)
        return;
    if (m_spPortal == 0)
        return;
    int nPortalId;
    m_spEntity->GetPropertyValue(0x60f82816, nPortalId);
    DAT_143ab288c = nPortalId;
    int nTarget;
    m_spEntity->GetPropertyValue(0xa162d321, nTarget);
    bool bHousePortal = false;
    m_spEntity->GetPropertyValue(0xe725ea17, bHousePortal);
    bool bDenied = bHousePortal && !pPlayer->FUN_140967010()->FUN_14050d6f0(nPortalId);
    if (bDenied)
    {
        FUN_140d73bc0(0x656, 0, 0, L"");
        return;
    }
    efd::SmartPointer<Unk_Service6100017> spCubeMap = FUN_1401cd040(&DAT_143b059e8);
    if (m_spPortal->m_nOwnerId)
    {
        Unk_StreamPoint ptFront;
        spCubeMap->FUN_1410b7ad0(pPlayer, 0.0f, &ptFront, 1);
        Unk_StreamPoint ptCell;
        spCubeMap->FUN_1410b7a20(ptFront, &ptCell);
        Cube* pCell = spCubeMap->FUN_1410b8ab0(ptCell);
        if (m_spPortal->m_nType == 0xb)
        {
            pPlayer->FUN_141529c80(0, 0, 0, m_spPortal->m_nOwnerId, L"");
            return;
        }
        else if (pCell)
        {
            FUN_140956aa0(pCell, nTarget, nPortalId);
            return;
        }
    }
    FUN_140956160(nTarget, nPortalId);
}
MS2_REPLACE_METHOD(0x140955580, PortalAction, vfunc_2, 1021, 0xEB4CA627);
// @0x1409559d0
int PortalAction::vfunc_4()
{
    if (!m_spEntity)
        return 0;
    int nKind;
    m_spEntity->GetPropertyValue(0x1b8b1161, nKind);
    if (nKind == 1)
    {
        if (Unk_AkoHouseSvc::GetInstance()->FUN_1410c3180() == DAT_143ab2820
            && !Unk_AkoHouseSvc::GetInstance()->FUN_1410cb920(5000))
            return 1;
        vfunc_2();
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1409559D0, PortalAction, vfunc_4, 161, 0xD640D23E);
// @0x140955a80
int PortalAction::vfunc_5() { return 0x13; }
MS2_REPLACE_METHOD(0x140955A80, PortalAction, vfunc_5, 11, 0x112851C6);
// MS2-FUNCTIONAL: stack slot layout differs (temps); calls and control flow identical
// @0x140955aa0
CStringW PortalAction::vfunc_6()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return L"";
    if (!m_spEntity)
        return L"";
    if (m_spPortal.IsNull())
        return L"";
    int nTarget;
    if (m_spEntity->GetPropertyValue(0xa162d321, nTarget) != 0)
        return L"";
    if (nTarget == 0)
        return FUN_140956e40();
    efd::SmartPointer<Unk_Service6100017> spCubeMap = FUN_1401cd040(&DAT_143b059e8);
    int nMapId = 0;
    if (m_spPortal->m_nOwnerId)
    {
        std::map<unsigned __int64, Unk_CubeOwnerPtr>* pOwners = Unk_AkoHouseSvc::GetInstance()->FUN_1410d3380();
        if (pOwners->find(m_spPortal->m_nOwnerId) != pOwners->end())
        {
            Unk_CubeOwnerPtr spOwner = (*pOwners)[m_spPortal->m_nOwnerId];
            if (spOwner)
                nMapId = spOwner->mapID;
        }
    }
    CStringW strText;
    if (nMapId != 0)
    {
        strText = FUN_14028de60(0x632);
    }
    else
    {
        CStringW strName = FUN_1401a9d70()->FUN_141811980(0xf, nTarget);
        if (strName.IsEmpty())
            strName = FUN_1401a9d70()->FUN_141811980(3, nTarget);
        MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(nTarget);
        if (spField == 0)
            return FUN_14028de60(0x632);
        CStringW strError;
        if (spField.get())
        {
            if (!FUN_140a55d20(spField, &strError))
            {
                strError = FUN_14061ad70(FUN_1401d0160(L" <", strError), L">");
                strName += strError;
            }
        }
        strText = FUN_14052bd00(0x633, strName);
    }
    return strText;
}
MS2_REPLACE_METHOD(0x140955AA0, PortalAction, vfunc_6, 1464, 0x8EEAA101);
// @0x140956060
Unk_AkoTarget PortalAction::vfunc_12()
{
    if (m_spPortal == 0)
        return Unk_AkoTarget();
    Unk_StreamPoint pos = m_spPortal->FUN_14169d2f0();
    if (m_spPortal->m_nType == 5)
        pos.z += 75.0f;
    return Unk_AkoTarget(pos);
}
MS2_REPLACE_METHOD(0x140956060, PortalAction, vfunc_12, 158, 0xC4C4B84D);
// @0x140956110
int PortalAction::FUN_140956110()
{
    if (m_spPortal == 0)
        return 0;
    return m_spPortal->FUN_14169d280();
}
MS2_REPLACE_METHOD(0x140956110, PortalAction, FUN_140956110, 69, 0x8E8EC06C);
// @0x140956160
void PortalAction::FUN_140956160(int nTarget, int nPortalId)
{
    switch (m_spPortal->m_nType)
    {
    case 8:
        FUN_140956290(nPortalId);
        break;
    case 9:
        FUN_140956310();
        break;
    case 0xc:
        FUN_1409569a0(nPortalId, 3);
        break;
    case 0xd:
        FUN_140956370(0, 1);
        break;
    case 0xe:
        FUN_1409569a0(nPortalId, 4);
        break;
    case 0x10:
        FUN_140dff580(nTarget, nPortalId);
        break;
    case 0x11:
        FUN_140956a20(nPortalId, nPortalId);
        break;
    default:
        FUN_140956370(nTarget, nPortalId);
        break;
    }
}
MS2_REPLACE_METHOD(0x140956160, PortalAction, FUN_140956160, 246, 0x0584F47B);
// @0x140956290
void PortalAction::FUN_140956290(int nPortalId)
{
    if (UIDungeonRoomDialog* pDialog = Unk_GetUI<UIDungeonRoomDialog>(0x4ebd))
    {
        if (pDialog->FUN_141924630())
            pDialog->vfunc_67();
        if (pDialog->FUN_1412b8f00(nPortalId))
        {
            pDialog->FUN_1412b90f0(nPortalId);
            pDialog->FUN_141924680();
        }
    }
}
MS2_REPLACE_METHOD(0x140956290, PortalAction, FUN_140956290, 119, 0x70B8578D);
// @0x140956310
void PortalAction::FUN_140956310()
{
    COutPacket packet(0x2b);
    packet.Encode1(9);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140956310, PortalAction, FUN_140956310, 75, 0xAAB9ED2B);
// MS2-FUNCTIONAL: stack slot layout differs (temps); calls and control flow identical
// @0x140956370
void PortalAction::FUN_140956370(unsigned nTarget, unsigned nPortalId)
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    MS2Ptr<CFieldDataCli> spCurrent = reinterpret_cast<Unk_AkoWorldView*>(FUN_1403ed2d0())->FUN_141bd30a0();
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(nTarget);
    if (spCurrent.get() && spField.get() && spField->FUN_1403754f0() && !spCurrent->FUN_1403754d0()
        && spField->FUN_1403754d0())
    {
        FUN_140d73bc0(0x971, 1, pPlayer, StringFormat(L"moveportal,{0},{1}", nTarget, nPortalId));
        return;
    }
    if (spField == 0 && nTarget != 0)
    {
        FUN_140d73bc0(0x99d, 0, 0, L"");
        return;
    }
    if (spField.get() && spField->m_nRequireQuest != 0
        && FUN_140764020()->m_state.FUN_140745590(spField->m_nRequireQuest) == 0)
    {
        FUN_1412751f0(FUN_1405c2690(L"s_quest_error_field_enter_limit", FUN_1416e4df0(spField->m_nRequireQuest)), 1, 1);
        return;
    }
    if (!m_spPortal->m_bConfirm)
    {
        pPlayer->FUN_14152a0c0(nTarget, nPortalId, 0, 0, L"", L"");
    }
    else
    {
        CStringW strTitle = FUN_14028de60(0xb07);
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(strTitle, 10);
        CStringW strDefault = L"";
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &PortalAction::FUN_140956be0));
        spBox->FUN_141a01d30(5, strDefault, 6, 0, 0);
        spBox->FUN_140534050(nTarget);
        spBox->FUN_140534050(nPortalId);
        FUN_140d73c60(spBox);
    }
}
MS2_REPLACE_METHOD(0x140956370, PortalAction, FUN_140956370, 1570, 0x80A0D7E5);
// MS2-FUNCTIONAL: stack slot layout differs (temps); calls and control flow identical
// @0x140956be0
bool PortalAction::FUN_140956be0(int nButton, const CMsgBoxData& data)
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer && nButton == 0)
    {
        CStringW strPassword = data.FUN_141a02d50();
        strPassword.Trim(L",");
        int nTarget = 0;
        int nPortalId = 0;
        data.FUN_140961900(0, nTarget);
        data.FUN_140961900(1, nPortalId);
        MS2Ptr<Unk_AkoPortal> spPortal = reinterpret_cast<Unk_AkoWorldView*>(FUN_1403ed2d0())->FUN_141bc2800(nPortalId);
        if (spPortal == 0)
            FUN_1412751f0(FUN_14028b8e0(L"s_action_portal_invalid_portal"), 1, 1);
        else
            pPlayer->FUN_14152a0c0(nTarget, nPortalId, 0, 0, strPassword, L"");
    }
    return true;
}
MS2_REPLACE_METHOD(0x140956BE0, PortalAction, FUN_140956be0, 559, 0xB0C2A3BB);
// @0x1409569a0
void PortalAction::FUN_1409569a0(int nPortalId, int nMode)
{
    if (UIDungeonRoomDialog* pDialog = Unk_GetUI<UIDungeonRoomDialog>(0x4ebd))
    {
        if (pDialog->FUN_141924630())
            pDialog->vfunc_67();
        pDialog->FUN_1412b90d0(nMode);
        pDialog->FUN_1412b90f0(nPortalId);
        pDialog->FUN_141924680();
    }
}
MS2_REPLACE_METHOD(0x1409569A0, PortalAction, FUN_1409569a0, 117, 0x7ED71136);
// @0x140956a20
void PortalAction::FUN_140956a20(int nPortalId, int nArg)
{
    if (UIDungeonRoomDialog* pDialog = Unk_GetUI<UIDungeonRoomDialog>(0x4ebd))
    {
        if (pDialog->FUN_141924630())
            pDialog->vfunc_67();
        pDialog->FUN_1412b8ff0(nArg);
        pDialog->FUN_1412b90f0(nPortalId);
        pDialog->FUN_141924680();
    }
}
MS2_REPLACE_METHOD(0x140956A20, PortalAction, FUN_140956a20, 117, 0x78FA43EB);
// @0x140956aa0
void PortalAction::FUN_140956aa0(Cube* pCell, int nTarget, int nPortalId)
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (!pCell)
        return;
    int nCubeId = pCell->field50;                           // the cube id
    int nKind = 0;
    FUN_1408a0890(FUN_1403ed2d0()->FUN_141bd3060(), nCubeId, &nKind);
    int bInside = 0;
    if (nKind == 1)
        bInside = 1;
    pPlayer->FUN_14152a0c0(nTarget, nPortalId, nCubeId, bInside, L"", L"");
}
MS2_REPLACE_METHOD(0x140956AA0, PortalAction, FUN_140956aa0, 309, 0xFE6AA6E2);
// @0x140956e40
CStringW PortalAction::FUN_140956e40()
{
    return m_spPortal->FUN_14169c3b0();
}
MS2_REPLACE_METHOD(0x140956E40, PortalAction, FUN_140956e40, 73, 0x911E15E5);

// ---- BuyCubeAction ---------------------------------------------------------------------------------------------------
// @0x140956e90
BuyCubeAction::BuyCubeAction() : m_n18(0), m_id(egf::kENTITY_INVALID) {}
// @0x140956f00
BuyCubeAction::~BuyCubeAction()
{
    m_id = egf::kENTITY_INVALID;
}
// @0x140956f50
int BuyCubeAction::vfunc_1() { return 0; }
MS2_REPLACE_METHOD(0x140956F50, BuyCubeAction, vfunc_1, 8, 0x7F371472);
// @0x140956f60
void BuyCubeAction::vfunc_2()
{
    if (m_n18 == 0)
        return;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    efd::SmartPointer<Unk_Service6100017> spHouse = FUN_1401cd040(&DAT_143b059e8);
    int nError = spHouse->FUN_1410c8580(m_n18);
    if (nError == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4e76);
        if (UIRealEstateDialog* pDialog = Unk_GetUI<UIRealEstateDialog>(0x4e76))
            pDialog->FUN_141ab4000(m_n18, FUN_1403ed2d0()->FUN_141bd3060());
    }
    else
    {
        FUN_140d73aa0(spHouse->FUN_1410d5d80(nError), 0, 0, L"");
    }
}
MS2_REPLACE_METHOD(0x140956F60, BuyCubeAction, vfunc_2, 342, 0x106CF696);
// @0x1409570c0
void BuyCubeAction::vfunc_3()
{
    if (m_id != egf::kENTITY_INVALID)
    {
        FUN_1409571a0(m_id, 0);
        m_id = egf::kENTITY_INVALID;
    }
}
MS2_REPLACE_METHOD(0x1409570C0, BuyCubeAction, vfunc_3, 117, 0xDB2B41EC);
// @0x140957140
int BuyCubeAction::vfunc_5() { return 0x16; }
MS2_REPLACE_METHOD(0x140957140, BuyCubeAction, vfunc_5, 11, 0x671D62B5);
// @0x140957160
CStringW BuyCubeAction::vfunc_6() { return FUN_14028de60(0x635); }
MS2_REPLACE_METHOD(0x140957160, BuyCubeAction, vfunc_6, 58, 0xE8BBC9CB);
// @0x1409571a0
void BuyCubeAction::FUN_1409571a0(egf::EntityID id, int bSelect)
{
    egf::EntityID idNone(0);
    if (id == idNone)
        return;
    FUN_141b71e70(id, bSelect != 0, 1, false);
}
MS2_REPLACE_METHOD(0x1409571A0, BuyCubeAction, FUN_1409571a0, 126, 0x67FAFAB3);

// ---- LiftCubeAction --------------------------------------------------------------------------------------------------
// @0x140957230
LiftCubeAction::LiftCubeAction() {}
// @0x140957280
LiftCubeAction::~LiftCubeAction() {}
// @0x1409572c0
int LiftCubeAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return false;
    if (pPlayer->FUN_141523c00().get())
        return false;
    Unk_WsB_Lift* pOld = FUN_1403ed2d0()->FUN_141bc5a20(m_str18).get();
    Unk_WsB_Lift* pLift = FUN_140957890();
    if (pOld && pOld != pLift)
        pOld->FUN_141447d50(0);
    if (pLift)
        pLift->FUN_141447d50(1);
    m_str18 = pLift ? pLift->FUN_1414472a0() : CString("");
    return pLift != 0;
}
MS2_REPLACE_METHOD(0x1409572C0, LiftCubeAction, vfunc_1, 637, 0x43810EFB);
// @0x140957550
void LiftCubeAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_141523c00().get())
        return;
    Unk_WsB_Lift* pLift = FUN_1403ed2d0()->FUN_141bc5a20(m_str18).get();
    if (!pLift)
        return;
    if (pPlayer->FUN_1416764a0() && !pPlayer->FUN_14152c280(0))
        return;
    pLift->FUN_141447d50(0);
    COutPacket packet(0x3c);
    packet.Encode1(1);
    packet.COutPacket::vfunc_o10_7(pLift->FUN_1414472a0());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140957550, LiftCubeAction, vfunc_2, 452, 0x3B43636C);
// MS2-FUNCTIONAL: frame 0x10 smaller (one temp fewer); calls and control flow identical
// @0x140957890 the liftable object in reach of the player
Unk_WsB_Lift* LiftCubeAction::FUN_140957890()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    efd::SmartPointer<Unk_Service6100017> spCubeMap = FUN_1401cd040(&DAT_143b059e8);
    std::vector<Unk_WsB_LiftPtr> aLifts;
    FUN_1403ed2d0()->FUN_141bc58d0(&aLifts);
    if (aLifts.size() <= 0)
        return 0;
    Unk_StreamPoint pos = pPlayer->FUN_1416767d0();
    MS2_FOR_EACH(Unk_WsB_LiftPtr spLift, aLifts)
    {
        if (spLift->FUN_141447340() == 0)
            continue;
        Unk_StreamPoint ptLift = spLift->FUN_141447c80();
        Unk_Int3 cell = FUN_1408a1430(ptLift);
        float fDist = ptLift.FUN_140965c40(pos).FUN_140968990();
        if (fDist > spLift->FUN_141447ac0())
            continue;
        return spLift.get();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140957890, LiftCubeAction, FUN_140957890, 624, 0xC3103479);
// @0x140957720
int LiftCubeAction::vfunc_5() { return 0x15; }
MS2_REPLACE_METHOD(0x140957720, LiftCubeAction, vfunc_5, 11, 0xB512670C);
// @0x140957740
CStringW LiftCubeAction::vfunc_6()
{
    Unk_WsB_Lift* pLift = FUN_1403ed2d0()->FUN_141bc5a20(m_str18);
    if (!pLift)
        return L"";
    return FUN_140960c30(0x63a, FUN_1401a9d70()->FUN_141811980(1, pLift->FUN_141447cc0()));
}
MS2_REPLACE_METHOD(0x140957740, LiftCubeAction, vfunc_6, 315, 0x1C11A665);

// ---- TalkAction ------------------------------------------------------------------------------------------------------
// @0x140957b20
TalkAction::TalkAction()
{
    m_n18 = 0;
    m_nNpcId = 0;
    m_strName = "";
}
// @0x140957bb0
int TalkAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_1416595d0())
        return 0;
    if (FUN_1409331e0()->FUN_14138c900(2))
        return 0;
    if (!Unk_AkoCutscene::GetInstance()->FUN_141b211d0())
        return 0;
    if (pPlayer->FUN_14166c930() == 8 || pPlayer->FUN_14166c930() == 9)
        return 0;
    m_n18 = 0;
    m_nNpcId = 0;
    m_strName = "";
    Unk_WsC_GameObj* pNpc = reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_141529640();
    if (pNpc)
    {
        if (pNpc->FUN_14123c660())
            return 0;
        int bTalk = 0;
        Unk_QmNpcQuestState state;
        FUN_140764020()->FUN_1416d12d0(pNpc->FUN_141092fa0(), &state, 1);
        if (state.m_icon != 0xb)
            bTalk = 1;
        if (pNpc->FUN_141093270()->FUN_1406cd020() != 0)
            bTalk = 1;
        if (FUN_140855d10(pNpc->FUN_141092fa0()))
            bTalk = 1;
        if (FUN_140764020()->FUN_1416cebf0(pNpc->FUN_141092fa0()))
            bTalk = 1;
        if (bTalk)
        {
            m_n18 = pNpc->FUN_141092fa0();
            m_nNpcId = pNpc->FUN_14123c580();
            m_strName = pNpc->FUN_141093310();
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140957BB0, TalkAction, vfunc_1, 703, 0xD721051B);
// @0x140957f10
int TalkAction::vfunc_5() { return 0x14; }
MS2_REPLACE_METHOD(0x140957F10, TalkAction, vfunc_5, 11, 0xF06BEBEF);
// @0x140957e80
void TalkAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_14166c930() == 0x16)
        return;
    if (Unk_AkoCutscene::GetInstance()->FUN_141b21220() != 0)
        return;
    if (FUN_1408e57f0()->FUN_1422b9e00() == 0x6200031)
        return;
    if (FUN_141276980() == 0)
        return;
    pPlayer->FUN_141529a50(m_nNpcId);
}
MS2_REPLACE_METHOD(0x140957E80, TalkAction, vfunc_2, 129, 0x6FD9FB8C);
// @0x140957f30
CStringW TalkAction::vfunc_6()
{
    if (m_n18 == 0)
        return L"";
    CStringW strText = FUN_1401a9d70()->FUN_141811980(0xe, m_n18);
    if (strText.GetLength() == 0)
        strText = FUN_14028de60(0x62d);
    CStringW strName = FUN_14052bd00(0x649, m_strName);
    if (strName.GetLength() != 0)
        strText.Append(strName);
    return strText;
}
MS2_REPLACE_METHOD(0x140957F30, TalkAction, vfunc_6, 307, 0xCFF13AE4);

// ---- InteractAction --------------------------------------------------------------------------------------------------
// @0x140958070
InteractAction::InteractAction() : m_n20(0) {}
// @0x1409580c0
InteractAction::~InteractAction()
{
    m_strObjectId.Empty();
}
// @0x140958a60
int InteractAction::vfunc_5() { return 0x12; }
MS2_REPLACE_METHOD(0x140958A60, InteractAction, vfunc_5, 11, 0xCC810D29);
// @0x140958120
int InteractAction::vfunc_1()
{
    CInteractObject* pOld = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    CInteractObject* pObject = FUN_140958e70();
    if (pOld && pOld != pObject)
    {
        if (UIGuildFlagTooltip* pTooltip = Unk_GetUI<UIGuildFlagTooltip>(0x4ea8))
            pTooltip->FUN_1412c45a0();
        pOld->FUN_1413fdca0(0);
    }
    if (pObject && vfunc_13(pObject) == 0)
        return 0;
    if (pObject)
    {
        pObject->FUN_1413fdca0(1);
        m_strObjectId = pObject->FUN_140967060();
        if (UIGuildFlagTooltip* pTooltip = Unk_GetUI<UIGuildFlagTooltip>(0x4ea8))
            pTooltip->FUN_1412c4050(m_strObjectId);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140958120, InteractAction, vfunc_1, 390, 0x2AE0A946);
// @0x140958e70
// MS2-FUNCTIONAL: the exe's WorldService::FUN_141bc6090 takes the point by value (a rep movsb copy into a temp);
// the shared header declares it const&.
CInteractObject* InteractAction::FUN_140958e70()
{
    if (FUN_1409331e0()->FUN_14138c900(3) != 0)
        return 0;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    Unk_StreamPoint pos = pPlayer->FUN_1416767d0();
    CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc6090(pos, 1);
    if (!pObject)
        return 0;
    if (pObject->FUN_1413fe040() == 0)
        return 0;
    if (pObject->FUN_1413fe120() == 0)
        return 0;
    if (pObject->FUN_1413fdfc0() == 0)
        return 0;
    return pObject;
}
MS2_REPLACE_METHOD(0x140958E70, InteractAction, FUN_140958e70, 273, 0xBA3636FF);
// @0x140958cb0
void InteractAction::vfunc_3()
{
    Unk_WsB_Prop* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    if (!pObject)
        return;
    m_n20 = 0;
    m_strObjectId.Empty();
}
MS2_REPLACE_METHOD(0x140958CB0, InteractAction, vfunc_3, 143, 0xC0354D66);
// @0x140958d50
Unk_AkoTarget InteractAction::vfunc_12()
{
    Unk_WsB_Prop* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    if (!pObject)
        return ActionKeyObject::vfunc_12();
    return Unk_AkoTarget(pObject->FUN_1409673c0());
}
MS2_REPLACE_METHOD(0x140958D50, InteractAction, vfunc_12, 189, 0x5E259EFC);
// @0x140958c50
CStringW InteractAction::vfunc_7() { return FUN_14016a730(m_strObjectId, 0); }
MS2_REPLACE_METHOD(0x140958C50, InteractAction, vfunc_7, 77, 0xDC203CB9);
// @0x140958e20
int InteractAction::vfunc_13(CInteractObject* pObject)
{
    int nKind = pObject->vfunc_5();
    if (nKind == 6 || nKind == 8)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140958E20, InteractAction, vfunc_13, 62, 0xA6B5DED9);
// @0x1409582b0
void InteractAction::vfunc_2()
{
    Unk_WsB_Prop* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    if (!pObject)
        return;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    MS2Ptr<CInteractObjectData> spData = pObject->FUN_140966e00();
    if (spData.IsNull())
        return;
    if (pObject->FUN_1413fde40() == 0)
    {
        Unk_AkoMessage(0x7c9, 1, 1, FUN_1401a9d70()->FUN_141811980(1, spData->m_nCostItemId));
        return;
    }
    if (pObject->FUN_1413fe220() == 0)
    {
        if (spData->m_aReqItem.size() == 1)
            FUN_1412751f0(FUN_1405c2690(L"s_interact_err_additional_effect",
                FUN_1401a9d70()->FUN_141812290(
                    FUN_140966f40(reinterpret_cast<const Unk_AkoReqItemList&>(spData->m_aReqItem)),
                    FUN_140966f80(reinterpret_cast<const Unk_AkoReqItemList&>(spData->m_aReqItem)),
                    CString("name"))), 1, 1);
        else
            FUN_1412751f0(FUN_14028b8e0(L"s_interact_err_additional_effect_multi"), 1, 1);
        return;
    }
    if (*(spData->m_pad_240 + 18) != 0 && !TSingleton<CPartyManager>::GetInstance()->FUN_14162ab60())   // +0x288 (in the pad): needs a party
    {
        FUN_141275260(0x893, 1, 1);
        return;
    }
    if (pObject->FUN_1413fdd80() == 0)
    {
        CStringW strMastery = FUN_1409670c0()->FUN_14066bdd0(spData->m_nGatherNeedA);
        CStringW strGrade = FUN_1409670c0()->FUN_14066c690(spData->m_nGatherNeedA, spData->m_nGatherNeedB);
        Unk_AkoMessage(0x896, 1, 1, strMastery, strGrade);
        return;
    }
    if (spData->m_nCursorType != 0)
    {
        if (pPlayer->FUN_141527160(0x19) == 0)
            return;
        if (pPlayer->FUN_1416764a0())
        {
            MS2Ptr<RideOffActionInteract> spRideOff(new RideOffActionInteract(0));
            spRideOff->m_n28 = pObject->FUN_140967110();
            spRideOff->m_s30 = pObject->FUN_140967060();
            pPlayer->FUN_14152c280(spRideOff);
        }
        else
        {
            MS2Ptr<StateInteractData> spState(new StateInteractData);
            spState->m_nObjectId = pObject->FUN_140967110();
            spState->m_strObjectId = pObject->FUN_140967060();
            pPlayer->vfunc_59(0x19, spState, 0x8a, 0);
        }
    }
    else
    {
        if (pPlayer->FUN_14166c930() == 0x10)
            return;
        else
        {
            pPlayer->FUN_14152e0c0();
            pObject->vfunc_10();
        }
    }
    m_n20 = 1;
}
MS2_REPLACE_METHOD(0x1409582B0, InteractAction, vfunc_2, 1959, 0x093C8BDB);
// @0x140958a80
CStringW InteractAction::vfunc_6()
{
    if (m_strObjectId.IsEmpty())
        return L"";
    Unk_WsB_Prop* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    if (!pObject)
        return L"";
    CStringW strName = FUN_1401a9d70()->FUN_141811980(0xb, pObject->FUN_140967110());
    if (strName.GetLength() < 1)
        return L"";
    return FUN_140960c30(0x634, strName);
}
MS2_REPLACE_METHOD(0x140958A80, InteractAction, vfunc_6, 450, 0xAA77F3CE);

// ---- InteractNpcAction -----------------------------------------------------------------------------------------------
// @0x140958f90
InteractNpcAction::InteractNpcAction() : m_pNpc(0), m_n20(0) {}
// @0x140958fe0
InteractNpcAction::~InteractNpcAction()
{
    m_pNpc = 0;
}
// @0x140959020
int InteractNpcAction::vfunc_1()
{
    m_pNpc = FUN_140959330();
    if (m_pNpc != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140959020, InteractNpcAction, vfunc_1, 54, 0x824E5B3A);
// @0x140959060
void InteractNpcAction::vfunc_2()
{
    if (m_pNpc == 0)
        return;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_141527160(0x1a) == 0)
        return;
    if (m_pNpc->FUN_141093270()->m_strTalkScript.GetLength() > 0)
    {
        MS2Ptr<StateInteractNpcData> spData = new StateInteractNpcData();
        spData->m_nNpc = m_pNpc->FUN_14123c580();
        static_cast<PCBase*>(pPlayer)->vfunc_59(0x1a, spData, 0, 0);   // PC/MyPC re-declare slot 59 as a new virtual
    }
    else
    {
        m_n20 = 1;
    }
}
// @0x140959330
// MS2-FUNCTIONAL: the exe keeps one more pointer slot for the interact-mode temporary (all frame offsets +8).
Unk_WsC_GameObj* InteractNpcAction::FUN_140959330()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    Unk_WsC_GameObj* pNpc = FUN_1403ed2d0()->FUN_141bd2170(2, FUN_1401d3200()->InteractionDistance.Read(), 1, 0);
    if (!pNpc)
    {
        int nKind = 1;
        if (pPlayer->FUN_140967420() != 0 && pPlayer->FUN_140967420()->FUN_140743550())
            nKind = pPlayer->FUN_140967420()->FUN_140743710();
        pNpc = FUN_1403ed2d0()->FUN_141bd2170(nKind, FUN_1401d3200()->InteractionDistance.Read(), 1, 0);
    }
    if (!pNpc)
        return 0;
    if (pNpc->FUN_14166ce30() == 1)
        return 0;
    if (pNpc->FUN_141093270()->m_strTalkScript.GetLength() < 1)
        return 0;
    if (!pNpc->FUN_140967120())
        return 0;
    return pNpc;
}
MS2_REPLACE_METHOD(0x140959330, InteractNpcAction, FUN_140959330, 755, 0xAE7C8382);
// @0x140959240
CStringW InteractNpcAction::vfunc_6()
{
    if (m_pNpc == 0)
        return L"";
    return FUN_140960c30(0x634, m_pNpc->FUN_141093310());
}
MS2_REPLACE_METHOD(0x140959240, InteractNpcAction, vfunc_6, 145, 0xD2B6814B);
// @0x140959630
Unk_AkoTarget InteractNpcAction::vfunc_12()
{
    if (m_pNpc == 0)
        return ActionKeyObject::vfunc_12();
    return Unk_AkoTarget(m_pNpc->vfunc_18());
}
MS2_REPLACE_METHOD(0x140959630, InteractNpcAction, vfunc_12, 103, 0x45902D38);
// @0x140959220
int InteractNpcAction::vfunc_5() { return 0x12; }
MS2_REPLACE_METHOD(0x140959220, InteractNpcAction, vfunc_5, 11, 0xCC810D29);
// @0x1409592e0
void InteractNpcAction::vfunc_9() { vfunc_3(); }
MS2_REPLACE_METHOD(0x1409592E0, InteractNpcAction, vfunc_9, 30, 0x46DE6E41);
// @0x140959310
void InteractNpcAction::vfunc_3() { m_n20 = 0; }
MS2_REPLACE_METHOD(0x140959310, InteractNpcAction, vfunc_3, 18, 0x353540EB);
// @0x140967a50
bool InteractNpcAction::vfunc_11() { return true; }
MS2_REPLACE_METHOD(0x140967A50, InteractNpcAction, vfunc_11, 8, 0x71679366);

// ---- ViewCubeMapProfileAction ----------------------------------------------------------------------------------------
// @0x1409596a0
ViewCubeMapProfileAction::ViewCubeMapProfileAction() {}
// @0x1409596e0
ViewCubeMapProfileAction::~ViewCubeMapProfileAction() {}
// @0x140959710
int ViewCubeMapProfileAction::vfunc_1() { return 0; }
MS2_REPLACE_METHOD(0x140959710, ViewCubeMapProfileAction, vfunc_1, 8, 0x7F371472);
// @0x1409597b0
int ViewCubeMapProfileAction::vfunc_5() { return 9; }
MS2_REPLACE_METHOD(0x1409597B0, ViewCubeMapProfileAction, vfunc_5, 11, 0x653B09E8);
// @0x140959720
void ViewCubeMapProfileAction::vfunc_2()
{
    if (m_nMapId == 0)
        return;
    efd::SmartPointer<Unk_Service6100017> spHouse = FUN_1401cd040(&DAT_143b059e8);
    spHouse->FUN_1410ccc00(m_nMapId, 1, FUN_1401d3200()->DurationForBoundaryDisplay.Read());
}
MS2_REPLACE_METHOD(0x140959720, ViewCubeMapProfileAction, vfunc_2, 135, 0xF03EB00E);
// @0x1409597d0
CStringW ViewCubeMapProfileAction::vfunc_6() { return FUN_14028de60(0x648); }
MS2_REPLACE_METHOD(0x1409597D0, ViewCubeMapProfileAction, vfunc_6, 58, 0xEF3DA54E);

// ---- RegistUgcAction -------------------------------------------------------------------------------------------------
// @0x140959810
RegistUgcAction::RegistUgcAction() {}
// @0x140959860
RegistUgcAction::~RegistUgcAction()
{
    m_spEntity = 0;
}
// @0x140959ac0
int RegistUgcAction::vfunc_5() { return 0x10; }
MS2_REPLACE_METHOD(0x140959AC0, RegistUgcAction, vfunc_5, 11, 0x55CF9663);
// @0x1409599f0
void RegistUgcAction::vfunc_2()
{
    if (m_spEntity == 0)
        return;
    FUN_14052d220()->FUN_14187f590(m_spEntity);
}
MS2_REPLACE_METHOD(0x1409599F0, RegistUgcAction, vfunc_2, 117, 0x885DE4AF);
// @0x140959a70
void RegistUgcAction::vfunc_3()
{
    FUN_140959d70(m_spEntity, 0);
    m_spEntity = 0;
}
MS2_REPLACE_METHOD(0x140959A70, RegistUgcAction, vfunc_3, 66, 0x541E758C);
// MS2-FUNCTIONAL: the exe's WorldService::FUN_141bd0220 takes the point by value (a rep movsb copy into a temp); the shared header declares it const&.
// @0x1409598c0
int RegistUgcAction::vfunc_1()
{
    Unk_WsC_GameObj* pPlayer = static_cast<Unk_WsC_GameObj*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    float fDist = FUN_1401d3200()->RegistUgcDistance.Read();
    Unk_StreamPoint pos = pPlayer->vfunc_18();
    egf::Entity* pEntity = FUN_1403ed2d0()->FUN_141bd0220(pos, fDist);
    if (m_spEntity != pEntity)
    {
        FUN_140959d70(m_spEntity, 0);
        FUN_140959d70(pEntity, 1);
        m_spEntity = pEntity;
    }
    return m_spEntity != 0;
}
MS2_REPLACE_METHOD(0x1409598C0, RegistUgcAction, vfunc_1, 295, 0x7E8EEBAF);
// @0x140959ae0
CStringW RegistUgcAction::vfunc_6()
{
    if (m_spEntity == 0)
        return L"";
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    int nBannerId = FUN_140b60d90(m_spEntity);
    Unk_BannerPtr spBanner = CFieldBannerData::GetBanner(nBannerId);
    if (spBanner == 0)
        return L"";
    if (spBanner->m_nField != nMapId)
        return L"";
    CStringW strText;
    if (spBanner->m_nAd == 0)
        strText = FUN_14028de60(0x64d);
    else if (spBanner->m_nAd == 1)
        strText = FUN_14028de60(0x637);
    else if (spBanner->m_nAd == 2)
        strText = FUN_14028de60(0x65b);
    return strText;
}
MS2_REPLACE_METHOD(0x140959AE0, RegistUgcAction, vfunc_6, 644, 0x60ED213D);
// @0x140959d70
void RegistUgcAction::FUN_140959d70(egf::Entity* pEntity, int bSelect)
{
    if (!pEntity)
        return;
    FUN_141b71e70(pEntity->GetEntityID(), bSelect != 0, 1, false);
}
MS2_REPLACE_METHOD(0x140959D70, RegistUgcAction, FUN_140959d70, 108, 0x9EED06A3);

// MS2-FUNCTIONAL: the exe ends the state test with je/jmp (2 bytes longer); the condition form is not found
// @0x140959eb0 the object weapon cube in front of the player (the two cells ahead and the one below), kept in m_spCube
int PullObjectWeaponAction::FUN_140959eb0()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_14165f100())
        return 0;
    int nState = pPlayer->FUN_14166c930();
    if (nState == 0x10 || (nState > 0x1c && (nState <= 0x1e || nState == 0x20 || nState == 0x2f)))
        return 0;
    efd::SmartPointer<Unk_Service6100017> spCubeMap = FUN_1401cd040(&DAT_143b059e8);
    std::vector<efd::Point3> aCells;
    aCells.reserve(3);
    for (int i = 1; i >= -1; --i)
    {
        if (i >= 0)
        {
            efd::Point3 ptFront;
            efd::SmartPointer<Ridee> spRidee(pPlayer->FUN_1416764a0());
            if (spRidee)
                spCubeMap->FUN_1410b7ad0(spRidee, 0.0f, &ptFront, i);
            else
                spCubeMap->FUN_1410b7ad0(pPlayer, 0.0f, &ptFront, i);
            efd::Point3 ptCell;
            spCubeMap->FUN_1410b7a20(ptFront, &ptCell);
            aCells.push_back(ptCell);
            continue;
        }
        else
        {
            efd::Point3 ptFront;
            efd::SmartPointer<Ridee> spRidee(pPlayer->FUN_1416764a0());
            if (spRidee)
                spCubeMap->FUN_1410b7ad0(spRidee, 0.0f, &ptFront, 0);
            else
                spCubeMap->FUN_1410b7ad0(pPlayer, 0.0f, &ptFront, 0);
            efd::Point3 ptCell;
            spCubeMap->FUN_1410b7a20(ptFront, &ptCell);
            ptCell.z -= 150.0f;
            aCells.push_back(ptCell);
            break;
        }
    }
    for (size_t j = 0; j < aCells.size(); ++j)
    {
        Cube* pCube = spCubeMap->FUN_1410b8ab0(aCells[j]);
        if (!pCube)
            continue;
        if (pCube->field78 != 0)
            continue;
        if (pCube->entity == 0)
            continue;
        bool bWeapon = false;
        pCube->entity->GetPropertyValue(0x9ea356ad, bWeapon);
        if (!bWeapon)
            continue;
        bool bPullable = false;
        pCube->entity->GetPropertyValue(0xa0b6b179, bPullable);
        if (!bPullable)
            continue;
        float fRange = 150.0f;
        pCube->entity->GetPropertyValue(0x2f9d016f, fRange);
        if (FUN_140966f00(pCube->FUN_1408b5370(), pPlayer->FUN_1416767d0()) > fRange)
            continue;
        if (pCube->field48 != 0)
            continue;
        if (pCube->field50 != 0)
            continue;
        m_spCube.AssignRaw(pCube);
        return 1;
    }
    m_spCube = 0;
    return 0;
}
MS2_REPLACE_METHOD(0x140959EB0, PullObjectWeaponAction, FUN_140959eb0, 1486, 0xBEBEEB47);
// ---- PullObjectWeaponAction ------------------------------------------------------------------------------------------
// @0x14095a4b0
int PullObjectWeaponAction::vfunc_1()
{
    if (FUN_140959eb0() == 0)
    {
        if (m_spCube28)
        {
            FUN_141b71e70(m_spCube28->entity->GetEntityID(), 0, 1, 0);
            m_spCube28 = 0;
        }
        return 0;
    }
    if (!m_spCube28)
    {
        FUN_141b71e70(m_spCube->entity->GetEntityID(), 1, 1, 0);
        m_spCube28 = m_spCube;
    }
    else if (m_spCube->entity->GetEntityID() != m_spCube28->entity->GetEntityID())
    {
        FUN_141b71e70(m_spCube28->entity->GetEntityID(), 0, 1, 0);
        FUN_141b71e70(m_spCube->entity->GetEntityID(), 1, 1, 0);
        m_spCube28 = m_spCube;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14095A4B0, PullObjectWeaponAction, vfunc_1, 627, 0x4930EE27);
// MS2-FUNCTIONAL: the exe ends the state test with je/jmp (2 bytes longer); the condition form is not found
// @0x14095a730
void PullObjectWeaponAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_14165f100())
        return;
    int nState = pPlayer->FUN_14166c930();
    if (nState == 0x10 || (nState > 0x1c && (nState <= 0x1e || nState == 0x20 || nState == 0x2f)))
        return;
    if (m_spCube)
    {
        efd::utf8string strOwner;
        int nResult = FUN_1408a2060(m_spCube->entity, 0xe52a2848, &strOwner);
        if (nResult == 0 || !strOwner.empty())
        {
            if (pPlayer->FUN_1416764a0() && !pPlayer->FUN_14152c280(0))
                return;
            COutPacket packet(0x37);
            packet.Encode1(0x11);
            packet.Encode4(FUN_1408a03c0(m_spCube->position));
            FUN_140710590(packet);
        }
    }
}
MS2_REPLACE_METHOD(0x14095A730, PullObjectWeaponAction, vfunc_2, 478, 0xFB1994EC);
// @0x140959df0
PullObjectWeaponAction::PullObjectWeaponAction() : m_spCube(0), m_spCube28(0) {}
// @0x140959e60
PullObjectWeaponAction::~PullObjectWeaponAction() {}
// @0x14095a920
int PullObjectWeaponAction::vfunc_5() { return 0xd; }
MS2_REPLACE_METHOD(0x14095A920, PullObjectWeaponAction, vfunc_5, 11, 0xFFD75F74);
// @0x14095a980
Unk_AkoTarget PullObjectWeaponAction::vfunc_12()
{
    if (m_spCube == 0)
        return ActionKeyObject::vfunc_12();
    return Unk_AkoTarget(m_spCube->FUN_1408b5370());
}
MS2_REPLACE_METHOD(0x14095A980, PullObjectWeaponAction, vfunc_12, 115, 0x730CB897);
// @0x14095a940
CStringW PullObjectWeaponAction::vfunc_6() { return FUN_14028de60(0x63c); }
MS2_REPLACE_METHOD(0x14095A940, PullObjectWeaponAction, vfunc_6, 58, 0xDC4D8F98);

// ---- PutDownLiftableAction -------------------------------------------------------------------------------------------
// @0x14095aa70 a lift stands on the cell in front of the player (or the player is already putting one down)
int PutDownLiftableAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_141659690() && pPlayer->FUN_14166c930() == 1)
        return 1;
    efd::SmartPointer<Unk_Service6100017> spCubeMap = FUN_1401cd040(&DAT_143b059e8);
    Unk_StreamPoint ptFront;
    spCubeMap->FUN_1410b7ad0(pPlayer, 0.0f, &ptFront, 1);
    Unk_StreamPoint ptCell;
    spCubeMap->FUN_1410b7a20(ptFront, &ptCell);
    if (spCubeMap->FUN_1410b7e80(ptCell))
        return 0;
    std::vector<Unk_AkoLiftTargetPtr> aTargets;
    FUN_1403ed2d0()->FUN_141bc5980(&aTargets);
    for (size_t i = 0; i < aTargets.size(); ++i)
    {
        Unk_AkoLiftTargetPtr spTarget = aTargets[i];
        Unk_StreamPoint ptTargetCell = DAT_143b01a60;
        spCubeMap->FUN_1410b7a20(spTarget->FUN_1409673f0(), &ptTargetCell);
        if (ptCell.FUN_140552690(ptTargetCell))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14095AA70, PutDownLiftableAction, vfunc_1, 717, 0xBB8B213D);
// @0x14095aa00
PutDownLiftableAction::PutDownLiftableAction() {}
// @0x14095aa40
PutDownLiftableAction::~PutDownLiftableAction() {}
// @0x14095adb0
int PutDownLiftableAction::vfunc_5() { return 0xc; }
MS2_REPLACE_METHOD(0x14095ADB0, PutDownLiftableAction, vfunc_5, 11, 0xBB301AD7);
// @0x14095ad50
void PutDownLiftableAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (Unk_PCCubeCraft* pCraft = pPlayer->FUN_141530290())
        pCraft->FUN_1410aad50();
}
MS2_REPLACE_METHOD(0x14095AD50, PutDownLiftableAction, vfunc_2, 75, 0xE574BACD);
// @0x14095add0
CStringW PutDownLiftableAction::vfunc_6() { return FUN_14028de60(0x63d); }
MS2_REPLACE_METHOD(0x14095ADD0, PutDownLiftableAction, vfunc_6, 58, 0x6B710DAF);

// ---- FunctionCubeAction ----------------------------------------------------------------------------------------------
// @0x14095ae10
FunctionCubeAction::FunctionCubeAction() : m_n20(0), m_id(egf::kENTITY_INVALID) {}
// @0x14095b470
int FunctionCubeAction::vfunc_5() { return 1; }
MS2_REPLACE_METHOD(0x14095B470, FunctionCubeAction, vfunc_5, 11, 0x30025ED0);
// @0x14095b690
int FunctionCubeAction::vfunc_10() { return m_n20; }
MS2_REPLACE_METHOD(0x14095B690, FunctionCubeAction, vfunc_10, 14, 0xA25B27BF);

// MS2-FUNCTIONAL: exe passes fRange via movss xmm0+movaps xmm3 and stores vfunc_9's result without movzx (int return); shared header declares bool
// @0x14095ae90 the function cube in reach of the player
int FunctionCubeAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_14166c930() == 0x29)
        return 0;
    __int64 nAccount = reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_141656ad0();
    float fRange = FUN_1401d3200()->FunctionCubeDistance.Read();
    MS2Ptr<CFunctionCubeObject> spObject =
        FUN_1409670b0()->FUN_141230f60(pPlayer->FUN_1416767d0(), fRange, nAccount);
    if (spObject == 0)
        return 0;
    m_n20 = spObject->vfunc_9(m_str18);
    m_str18 = spObject->FUN_141226bd0();
    if (spObject->FUN_1409674f0() == 3 || spObject->FUN_1409674f0() == 2)
        return 0;
    if (spObject->FUN_140966fc0() == 7 || spObject->FUN_140966fc0() == 8)
        return 0;
    if (spObject->FUN_140966fc0() == 0xd)
        return 0;
    if (m_str18.IsEmpty())
        return 0;
    if (m_id != spObject->FUN_141226eb0())
    {
        if (m_id != egf::kENTITY_INVALID)
            FUN_141b71e70(m_id, 0, 1, 0);
        m_id = spObject->FUN_141226eb0();
        FUN_141b71e70(m_id, 1, 1, 0);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14095AE90, FunctionCubeAction, vfunc_1, 989, 0xC35FC05B);
// @0x14095b280
void FunctionCubeAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    MS2Ptr<CFunctionCubeObject> spObject = FUN_1409670b0()->FUN_141230c00(CString(m_str18));
    if (spObject == 0)
        return;
    if (Unk_AkoHouseSvc::GetInstance()->FUN_1410c35c0())
    {
        if (Unk_AkoHouseSvc::GetInstance()->FUN_1410c3180() == reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_141656ad0())
        {
            if (spObject->FUN_1409674f0() == 1)
            {
                FUN_141275260(99, 1, 1);
                return;
            }
        }
    }
    if (pPlayer->FUN_1416764a0() && static_cast<bool>(spObject.get()))
    {
        if (spObject->FUN_1412271f0() && !pPlayer->FUN_14152c280(0))
            return;
    }
    spObject->vfunc_8(m_str18);
}
MS2_REPLACE_METHOD(0x14095B280, FunctionCubeAction, vfunc_2, 483, 0x595BD151);
// @0x14095b490
CStringW FunctionCubeAction::vfunc_6()
{
    MS2Ptr<CFunctionCubeObject> spObject = FUN_1409670b0()->FUN_141230c00(m_str18);
    if (spObject.get())
        return spObject->vfunc_6();
    return L"";
}
MS2_REPLACE_METHOD(0x14095B490, FunctionCubeAction, vfunc_6, 247, 0xF1723E7B);
// @0x14095b590
CStringW FunctionCubeAction::vfunc_8()
{
    MS2Ptr<CFunctionCubeObject> spObject = FUN_1409670b0()->FUN_141230c00(m_str18);
    if (spObject.get())
        return spObject->vfunc_7();
    return ActionKeyObject::vfunc_8();
}
MS2_REPLACE_METHOD(0x14095B590, FunctionCubeAction, vfunc_8, 247, 0xC05E6361);
// @0x14095b6b0
void FunctionCubeAction::vfunc_3()
{
    if (m_id != egf::kENTITY_INVALID)
    {
        FUN_141b71e70(m_id, 0, 1, 0);
        m_id = egf::kENTITY_INVALID;
    }
    m_n20 = 0;
    m_str18 = "";
}
MS2_REPLACE_METHOD(0x14095B6B0, FunctionCubeAction, vfunc_3, 157, 0xC94076E9);

// ---- FittingDollAction -----------------------------------------------------------------------------------------------
// @0x14095b760
FittingDollAction::FittingDollAction() : m_n18(0), m_id(egf::kENTITY_INVALID) {}
// @0x14095ba40
int FittingDollAction::vfunc_5() { return 0xe; }
MS2_REPLACE_METHOD(0x14095BA40, FittingDollAction, vfunc_5, 11, 0x31E1919D);
// @0x14095bbf0
int FittingDollAction::vfunc_10() { return m_n18; }
MS2_REPLACE_METHOD(0x14095BBF0, FittingDollAction, vfunc_10, 14, 0x72E52537);

// @0x14095b7d0
int FittingDollAction::vfunc_1()
{
    efd::SmartPointer<Unk_Service6100017> spHouse = FUN_1401cd040(&DAT_143b059e8);
    egf::EntityID id = spHouse->FUN_1410cb1b0();
    if (id == egf::kENTITY_INVALID)
        return 0;
    if (m_id != id)
    {
        if (m_id != egf::kENTITY_INVALID)
            FUN_141b71e70(m_id, 0, 1, 0);
        m_id = id;
        FUN_141b71e70(m_id, 1, 1, 1);
        m_n18 = 1;
    }
    else
    {
        m_n18 = 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14095B7D0, FittingDollAction, vfunc_1, 359, 0x74E0C952);
// @0x14095b940
void FittingDollAction::vfunc_2()
{
    efd::SmartPointer<Unk_Service6100017> spHouse = FUN_1401cd040(&DAT_143b059e8);
    egf::EntityID id = spHouse->FUN_1410cb1b0();
    if (spHouse->FUN_1410c35c0())
    {
        FUN_141275260(99, 1, 1);
        return;
    }
    Unk_AkoFittingDoll* pDoll = efd::DynamicCast<Unk_AkoFittingDoll>(reinterpret_cast<Unk_AkoWorldView*>(FUN_1403ed2d0())->FUN_141bd0fa0(id));
    if (pDoll)
    {
        DAT_143af25f0 = pDoll->FUN_141656a80();
        FUN_1403ed2b0()->FUN_141adc530(0x4e77);
    }
}
MS2_REPLACE_METHOD(0x14095B940, FittingDollAction, vfunc_2, 249, 0xB3E2B065);
// @0x14095ba60
CStringW FittingDollAction::vfunc_6()
{
    CStringW strName;
    Unk_AkoFittingDoll* pDoll = efd::DynamicCast<Unk_AkoFittingDoll>(reinterpret_cast<Unk_AkoWorldView*>(FUN_1403ed2d0())->FUN_141bd0fa0(m_id));
    if (pDoll)
        strName = FUN_1401a9d70()->FUN_141811980(1, pDoll->FUN_140967160());
    return FUN_1401d0080(FUN_14061ad70(FUN_14028de60(0x646), L" - "), strName);
}
MS2_REPLACE_METHOD(0x14095BA60, FittingDollAction, vfunc_6, 386, 0x7FA9427E);
// @0x14095bc10
void FittingDollAction::vfunc_3()
{
    if (m_id != egf::kENTITY_INVALID)
    {
        FUN_141b71e70(m_id, 0, 1, 0);
        m_id = egf::kENTITY_INVALID;
    }
    m_n18 = 0;
}
MS2_REPLACE_METHOD(0x14095BC10, FittingDollAction, vfunc_3, 132, 0x9A58A746);

// ---- HoldAction ------------------------------------------------------------------------------------------------------
// @0x14095bff0
HoldAction::HoldAction() : m_n18(0), m_n1c(0), m_nNpcId(0), m_f24(0.0f) {}
// @0x14095c540
int HoldAction::vfunc_5() { return 6; }
MS2_REPLACE_METHOD(0x14095C540, HoldAction, vfunc_5, 11, 0xFCA8E685);
// @0x14095c6b0
int HoldAction::vfunc_10() { return m_n18; }
MS2_REPLACE_METHOD(0x14095C6B0, HoldAction, vfunc_10, 14, 0x72E52537);
// @0x14095c060
int HoldAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_14166ce30() != 0)
        return 0;
    if (!static_cast<Unk_AkoPCMove*>(pPlayer->FUN_14166d240())->FUN_141683ef0())
        return 0;
    if (pPlayer->FUN_14166c930() == 0x2b)
        return 0;
    if (pPlayer->FUN_14166c930() == 0x10 && pPlayer->FUN_14166cc80() == 0x3b)
        return 0;
    int nTargetId = 0;
    CString strName;
    m_f24 = FUN_1401d3200()->FindHoldTargetRange.Get(230.0f);
    int bFound = reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_14165c1b0(&nTargetId, &strName, m_f24);
    if (bFound == 0)
        return 0;
    if (pPlayer->FUN_14123c580() == nTargetId)
        return 0;
    Unk_WsC_GameObj* pPc = FUN_1403ed2d0()->FUN_141bd1290(nTargetId);
    if (pPc != 0)
        return 0;
    m_n18 = 0;
    Unk_WsC_GameObj* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nTargetId);
    if (pNpc != 0)
    {
        if (m_nNpcId != pNpc->FUN_141092fa0())
        {
            m_nNpcId = pNpc->FUN_141092fa0();
            m_n18 = 1;
        }
    }
    else
    {
        m_nNpcId = 0;
    }
    if (m_n1c == 0 && pPlayer->FUN_14166c930() == 0x20)
        m_n18 = 1;
    if (m_n1c == 1 && pPlayer->FUN_14166c930() != 0x20)
        m_n18 = 1;
    return 1;
}
MS2_REPLACE_METHOD(0x14095C060, HoldAction, vfunc_1, 649, 0x9CD66B21);
// @0x14095c2f0
void HoldAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_14166ce30() != 0)
        return;
    if (!static_cast<Unk_AkoPCMove*>(pPlayer->FUN_14166d240())->FUN_141683ef0())
        return;
    if (pPlayer->FUN_14166c930() == 0x2b)
        return;
    if (pPlayer->FUN_14166c930() == 0x10 && pPlayer->FUN_14166cc80() == 0x3b)
        return;
    if (pPlayer->FUN_14166c930() == 0x20)
    {
        pPlayer->vfunc_59(6, 0, 0, 0);
    }
    else if (pPlayer->FUN_1416764a0())
    {
        pPlayer->FUN_14152c280(new RideOffActionHold(0));
    }
    else
    {
        MS2Ptr<StateHoldData> spData(new StateHoldData);
        if (reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_14165c1b0(&spData->m_nTargetId,
                &spData->m_strTargetName, m_f24 + 20.0f))
            pPlayer->vfunc_59(0x20, spData, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x14095C2F0, HoldAction, vfunc_2, 571, 0xA683D970);
// @0x14095c560
CStringW HoldAction::vfunc_6()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer && pPlayer->FUN_14166c930() == 0x20)
    {
        m_n1c = 1;
        if (m_nNpcId == 0xa7e02a)
            return FUN_14028b8e0(L"s_action_hold_end_cart");
        return FUN_14028de60(0x653);
    }
    m_n1c = 0;
    if (m_nNpcId == 0xa7e02a)
        return FUN_14028b8e0(L"s_action_hold_cart");
    return FUN_14028de60(0x652);
}
MS2_REPLACE_METHOD(0x14095C560, HoldAction, vfunc_6, 326, 0x539E029C);

// ---- HoldPCAction ----------------------------------------------------------------------------------------------------
// @0x14095c6d0
HoldPCAction::HoldPCAction() : m_n18(0), m_f1c(0.0f) {}
// @0x14095cab0
int HoldPCAction::vfunc_5() { return 0x1b; }
MS2_REPLACE_METHOD(0x14095CAB0, HoldPCAction, vfunc_5, 11, 0x4660FCDE);
// @0x14095cb70
int HoldPCAction::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x14095CB70, HoldPCAction, vfunc_10, 8, 0x7F371472);
// @0x14095c720
int HoldPCAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_14166ce30() != 0)
        return 0;
    if (!static_cast<Unk_AkoPCMove*>(pPlayer->FUN_14166d240())->FUN_141683ef0())
        return 0;
    if (pPlayer->FUN_14166c930() == 0x2b)
        return 0;
    int nTargetId = 0;
    CString strName;
    m_f1c = FUN_1401d3200()->FindHoldTargetRange.Get(230.0f);
    int bFound = reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_14165c1b0(&nTargetId, &strName, m_f1c);
    if (bFound == 0)
        return 0;
    if (pPlayer->FUN_14123c580() == nTargetId)
        return 0;
    Unk_WsC_GameObj* pTarget = FUN_1403ed2d0()->FUN_141bd1290(nTargetId);
    if (pTarget != 0)
    {
        if (pPlayer->FUN_14166c930() == 0x20)
            return 0;
        if (pPlayer->FUN_14166c930() != 0x20 && reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_1415279d0(pTarget) == 0)
            return 0;
        if (pPlayer->FUN_14166c930() == 0x2f)
            return 0;
        if (pTarget->FUN_1416642a0())
            return 0;
        m_n18 = pTarget->FUN_14123c580();
    }
    else
    {
        m_n18 = 0;
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14095C720, HoldPCAction, vfunc_1, 632, 0x519B515F);
// @0x14095c9a0
void HoldPCAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_14166ce30() != 0)
        return;
    if (!static_cast<Unk_AkoPCMove*>(pPlayer->FUN_14166d240())->FUN_141683ef0())
        return;
    if (pPlayer->FUN_14166c930() == 0x2b)
        return;
    if (pPlayer->FUN_14166c930() == 0x20)
        return;
    if (pPlayer->FUN_1416764a0())
    {
        pPlayer->FUN_14152c280(new RideOffActionHold(0));
    }
    else if (m_n18 != 0)
    {
        pPlayer->FUN_14152dee0(m_n18);
    }
}
MS2_REPLACE_METHOD(0x14095C9A0, HoldPCAction, vfunc_2, 262, 0xBF53E2D3);
// @0x14095cad0
CStringW HoldPCAction::vfunc_6()
{
    if (m_n18 != 0)
        return FUN_14028b8e0(L"s_action_hold_pc");
    return L"";
}
MS2_REPLACE_METHOD(0x14095CAD0, HoldPCAction, vfunc_6, 144, 0xC108C110);

// ---- ReleasePCAction -------------------------------------------------------------------------------------------------
// @0x14095cb80
ReleasePCAction::ReleasePCAction() : m_n18(0), m_f1c(0.0f) {}
// @0x14095cea0
int ReleasePCAction::vfunc_5() { return 0; }
MS2_REPLACE_METHOD(0x14095CEA0, ReleasePCAction, vfunc_5, 8, 0x7F371472);
// @0x14095cf70
int ReleasePCAction::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x14095CF70, ReleasePCAction, vfunc_10, 8, 0x7F371472);
// @0x14095cbd0
int ReleasePCAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_14166ce30() != 0)
        return 0;
    if (!static_cast<Unk_AkoPCMove*>(pPlayer->FUN_14166d240())->FUN_141683ef0())
        return 0;
    if (pPlayer->FUN_14166c930() == 0x2b)
        return 0;
    int nTargetId = 0;
    CString strName;
    m_f1c = FUN_1401d3200()->FindHoldTargetRange.Get(230.0f);
    int bFound = reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_14165c1b0(&nTargetId, &strName, m_f1c);
    if (bFound == 0)
        return 0;
    if (pPlayer->FUN_14123c580() == nTargetId)
        return 0;
    Unk_WsC_GameObj* pTarget = FUN_1403ed2d0()->FUN_141bd1290(nTargetId);
    if (pTarget != 0)
    {
        if (pPlayer->FUN_14166c930() != 0x20)
            return 0;
        if (reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_14152e060() != nTargetId)
            return 0;
        m_n18 = pTarget->FUN_14123c580();
    }
    else
    {
        m_n18 = 0;
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14095CBD0, ReleasePCAction, vfunc_1, 519, 0x89715AB0);
// @0x14095cde0
void ReleasePCAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_14166ce30() != 0)
        return;
    if (!static_cast<Unk_AkoPCMove*>(pPlayer->FUN_14166d240())->FUN_141683ef0())
        return;
    if (pPlayer->FUN_14166c930() == 0x2b)
        return;
    if (pPlayer->FUN_14166c930() == 0x20)
    {
        if (m_n18 != 0)
            reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_14152df80();
        else
            pPlayer->vfunc_59(6, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x14095CDE0, ReleasePCAction, vfunc_2, 181, 0x6265257E);
// @0x14095ceb0
CStringW ReleasePCAction::vfunc_6()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer && pPlayer->FUN_14166c930() == 0x20 && m_n18 != 0)
        return FUN_14028b8e0(L"s_action_hold_pc_end");
    return L"";
}
MS2_REPLACE_METHOD(0x14095CEB0, ReleasePCAction, vfunc_6, 185, 0x053AD904);

// ---- GatheringAction -------------------------------------------------------------------------------------------------
// @0x14095d040
GatheringAction::GatheringAction() {}
// @0x14095d090
GatheringAction::~GatheringAction()
{
    m_strObjectId.Empty();
}
// @0x14095d0e0
int GatheringAction::vfunc_1()
{
    ATL::CAtlArray<MS2Ptr<CInteractObject> > aObjects;
    FUN_1403ed2d0()->FUN_141bc5fb0(&aObjects, 6);
    Unk_WsC_GameObj* pPlayer = static_cast<Unk_WsC_GameObj*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    float fNearest = FLT_MAX;
    MS2Ptr<CInteractObject> spNearest(0);
    m_objects.RemoveAll();
    for (size_t i = 0; i < aObjects.GetCount(); i++)
    {
        MS2Ptr<CInteractGatheringObject> spObject(dynamic_cast<CInteractGatheringObject*>(aObjects[i].get()));
        if (spObject.IsNull())
            continue;
        float fDist = pPlayer->vfunc_18().FUN_140965c40(spObject->FUN_1409673c0()).FUN_140967ac0();
        int bInRange = fDist < *static_cast<Client::Constants*>(FUN_1401d3200())->MasteryObjectInteractionDistance.Get() && vfunc_13(spObject);
        if (spObject->FUN_140967150() != bInRange)
            spObject->FUN_1413fdca0(bInRange != 0);
        if (bInRange)
        {
            m_objects.Add(spObject);
            if (fDist < fNearest)
            {
                spNearest = spObject;
                fNearest = fDist;
            }
        }
    }
    if (spNearest)
        m_strObjectId = spNearest->FUN_140967060();
    return spNearest != 0;
}
MS2_REPLACE_METHOD(0x14095D0E0, GatheringAction, vfunc_1, 889, 0xD2BF12F5);
// @0x14095d460
void GatheringAction::vfunc_2() { InteractAction::vfunc_2(); }
MS2_REPLACE_METHOD(0x14095D460, GatheringAction, vfunc_2, 24, 0x5EBFE707);
// @0x14095d4a0
CStringW GatheringAction::vfunc_6()
{
    ATL::CAtlMap<CStringW, int, ATL::CStringElementTraits<CStringW> > counts;
    for (size_t i = 0; i < m_objects.GetCount(); i++)
    {
        CStringW strName = FUN_1401a9d70()->FUN_141811980(0xb, m_objects[i]->FUN_140967110());
        int nCount = 0;
        counts.Lookup(strName, nCount);
        nCount++;
        counts.SetAt(strName, nCount);
    }
    CStringW strText;
    for (POSITION pos = counts.GetStartPosition(); pos != 0; counts.GetNext(pos))
    {
        if (strText.GetLength() != 0)
            strText += L", ";
        CStringW strName = counts.GetKeyAt(pos);
        int nCount = counts.GetValueAt(pos);
        strText += StringFormat(L"{0} x{1}", strName, nCount);
    }
    return FUN_140960c30(0x634, strText);
}
MS2_REPLACE_METHOD(0x14095D4A0, GatheringAction, vfunc_6, 685, 0xB1C6B98E);
// @0x14095d760
int GatheringAction::vfunc_13(CInteractObject* pObject)
{
    if (pObject->vfunc_5() != 6)
        return 0;
    if (FUN_1409331e0()->FUN_14138c900(3) != 0)
        return 0;
    CInteractObject* pGathering = pObject;
    MS2Ptr<CInteractObjectData> spData = pGathering->FUN_140966e00();
    if (spData.IsNull())
        return 0;
    if (pObject->vfunc_7() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x14095D760, GatheringAction, vfunc_13, 218, 0xB57C14A5);
// @0x14095d840
CInteractGatheringObject* GatheringAction::FUN_14095d840()
{
    if (m_strObjectId.IsEmpty())
        return 0;
    CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    if (pObject == 0)
        return 0;
    if (pObject->vfunc_5() != 6)
        return 0;
    CInteractGatheringObject* pGathering = static_cast<CInteractGatheringObject*>(pObject);
    return pGathering;
}
MS2_REPLACE_METHOD(0x14095D840, GatheringAction, FUN_14095d840, 187, 0xA825F12B);
// @0x14095d480
int GatheringAction::vfunc_5() { return 4; }
MS2_REPLACE_METHOD(0x14095D480, GatheringAction, vfunc_5, 11, 0x85F76FBF);

// ---- BillBoardInteractAction -----------------------------------------------------------------------------------------
// @0x14095d910
BillBoardInteractAction::BillBoardInteractAction() {}
// @0x14095d950
BillBoardInteractAction::~BillBoardInteractAction() {}
// @0x14095d9a0
CStringW BillBoardInteractAction::vfunc_6()
{
    if (m_strObjectId.IsEmpty())
        return L"";
    CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    if (pObject == 0)
        return L"";
    CInteractBillBoardObject* pBoard = dynamic_cast<CInteractBillBoardObject*>(pObject);
    if (pBoard == 0)
        return L"";
    CStringW strName = FUN_1401a9d70()->FUN_141811980(0xb, pObject->FUN_140967110());
    if (strName.GetLength() < 1)
        return L"";
    CStringW strText = pBoard->m_strText;
    if (strText.GetLength() > 10)
        strText = StringFormat(L"{0}...", strText.Left(10));
    return StringFormat(L"{0} - {1}", strName, strText);
}
MS2_REPLACE_METHOD(0x14095D9A0, BillBoardInteractAction, vfunc_6, 732, 0x50B7E5EA);
// @0x14095d980
int BillBoardInteractAction::vfunc_5() { return 0x18; }
MS2_REPLACE_METHOD(0x14095D980, BillBoardInteractAction, vfunc_5, 11, 0x8B08417B);
// @0x14095dc90
int BillBoardInteractAction::vfunc_13(CInteractObject* pObject)
{
    int nType = pObject->vfunc_5();
    if (nType == 8)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14095DC90, BillBoardInteractAction, vfunc_13, 55, 0x64843525);

// ---- HomemadeCubeAction ----------------------------------------------------------------------------------------------
// @0x14095dcd0
HomemadeCubeAction::HomemadeCubeAction() {}
// @0x14095dd20
int HomemadeCubeAction::vfunc_1()
{
    Unk_WsC_GameObj* pPlayer = static_cast<Unk_WsC_GameObj*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    ATL::CAtlArray<MS2Ptr<CHomemadeCubeObject> > aCubes;
    FUN_1409670b0()->FUN_141232660(aCubes, reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_141656ad0());
    float fNearest = FLT_MAX;
    MS2Ptr<CHomemadeCubeObject> spNearest(0);
    m_cubes.RemoveAll();
    for (size_t i = 0; i < aCubes.GetCount(); i++)
    {
        MS2Ptr<CHomemadeCubeObject> spCube = aCubes[i];
        float fDist = pPlayer->vfunc_18().FUN_140965c40(spCube->FUN_141226d00()).FUN_140967ac0();
        bool bUsable = fDist < *static_cast<Client::Constants*>(FUN_1401d3200())->MasteryObjectInteractionDistance.Get()
            && FUN_14095e440(spCube);
        if (FUN_1408a1360(pPlayer->vfunc_18(), spCube->FUN_141226d00()) == 0)
            bUsable = false;
        if (spCube->FUN_140967140() != bUsable)
            spCube->FUN_1412277d0(bUsable);
        if (bUsable)
        {
            m_cubes.Add(spCube);
            if (fDist < fNearest)
            {
                spNearest = spCube;
                fNearest = fDist;
            }
        }
    }
    if (spNearest)
        m_str18 = spNearest->FUN_141226bd0();
    return spNearest != 0;
}
MS2_REPLACE_METHOD(0x14095DD20, HomemadeCubeAction, vfunc_1, 936, 0x3EC04FD9);
// @0x14095e110
CStringW HomemadeCubeAction::vfunc_6()
{
    ATL::CAtlMap<CStringW, int, ATL::CStringElementTraits<CStringW> > counts;
    for (size_t i = 0; i < m_cubes.GetCount(); i++)
    {
        CStringW strName = FUN_1401a9d70()->FUN_141811980(1, m_cubes[i]->FUN_141226cd0());
        int nCount = 0;
        counts.Lookup(strName, nCount);
        nCount++;
        counts.SetAt(strName, nCount);
    }
    CStringW strText;
    for (POSITION pos = counts.GetStartPosition(); pos != 0; counts.GetNext(pos))
    {
        if (strText.GetLength() != 0)
            strText += L", ";
        CStringW strName = counts.GetKeyAt(pos);
        int nCount = counts.GetValueAt(pos);
        strText += StringFormat(L"{0} x{1}", strName, nCount);
    }
    return FUN_140960c30(0x634, strText);
}
MS2_REPLACE_METHOD(0x14095E110, HomemadeCubeAction, vfunc_6, 685, 0x2F692C76);
// @0x14095e440
int HomemadeCubeAction::FUN_14095e440(MS2Ptr<CHomemadeCubeObject> spCube)
{
    return spCube->FUN_141229000(1);
}
MS2_REPLACE_METHOD(0x14095E440, HomemadeCubeAction, FUN_14095e440, 66, 0xCD5963F8);
// @0x14095e0d0
void HomemadeCubeAction::vfunc_2() { FunctionCubeAction::vfunc_2(); }
MS2_REPLACE_METHOD(0x14095E0D0, HomemadeCubeAction, vfunc_2, 24, 0x33628DB0);
// @0x14095e0f0
int HomemadeCubeAction::vfunc_5() { return 2; }
MS2_REPLACE_METHOD(0x14095E0F0, HomemadeCubeAction, vfunc_5, 11, 0x620C90F9);
// @0x14095e3d0
CStringW HomemadeCubeAction::vfunc_8() { return L"key"; }
MS2_REPLACE_METHOD(0x14095E3D0, HomemadeCubeAction, vfunc_8, 61, 0xEB07375E);
// @0x14095e420
int HomemadeCubeAction::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x14095E420, HomemadeCubeAction, vfunc_10, 8, 0x7F371472);
// @0x14095e430
void HomemadeCubeAction::vfunc_3() {}
MS2_REPLACE_METHOD(0x14095E430, HomemadeCubeAction, vfunc_3, 6, 0xA9AF6E37);

// ---- NurturingCubeAction ---------------------------------------------------------------------------------------------
// @0x14095e490
NurturingCubeAction::NurturingCubeAction() : m_n30(0) {}
// MS2-FUNCTIONAL: the exe stores CNurturingCubeObject::FUN_14122c340's result without movzx (int return); the shared header declares unsigned char
// @0x14095e4d0
int NurturingCubeAction::vfunc_1()
{
    Unk_WsC_GameObj* pPlayer = static_cast<Unk_WsC_GameObj*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    ATL::CAtlArray<MS2Ptr<CNurturingCubeObject> > aCubes;
    FUN_1409670b0()->FUN_141232810(aCubes);
    float fNearest = FLT_MAX;
    MS2Ptr<CNurturingCubeObject> spNearest(0);
    for (size_t i = 0; i < aCubes.GetCount(); i++)
    {
        MS2Ptr<CNurturingCubeObject> spCube = aCubes[i];
        float fDist = pPlayer->vfunc_18().FUN_140965c40(spCube->FUN_141226d00()).FUN_140967ac0();
        bool bUsable = fDist < *static_cast<Client::Constants*>(FUN_1401d3200())->MasteryObjectInteractionDistance.Get()
            && spCube->FUN_14122bda0();
        if (FUN_1408a1360(pPlayer->vfunc_18(), spCube->FUN_141226d00()) == 0)
            bUsable = false;
        if (spCube->FUN_140967140() != bUsable)
            spCube->FUN_1412277d0(bUsable);
        if (bUsable && fDist < fNearest)
        {
            spNearest = spCube;
            fNearest = fDist;
        }
    }
    if (spNearest)
    {
        m_str18 = spNearest->FUN_141226bd0();
        m_n30 = spNearest->FUN_14122c340();
    }
    return spNearest != 0;
}
MS2_REPLACE_METHOD(0x14095E4D0, NurturingCubeAction, vfunc_1, 846, 0xFA117D8F);
// @0x14095e830
void NurturingCubeAction::vfunc_2() { FunctionCubeAction::vfunc_2(); }
MS2_REPLACE_METHOD(0x14095E830, NurturingCubeAction, vfunc_2, 24, 0x45C50103);
// @0x14095e850
int NurturingCubeAction::vfunc_5() { return 3; }
MS2_REPLACE_METHOD(0x14095E850, NurturingCubeAction, vfunc_5, 11, 0xA6B3D596);
// @0x14095e870
CStringW NurturingCubeAction::vfunc_6()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return L"";
    if (m_n30 != 0)
        return FUN_140960c30(0x634, FUN_14028b8e0(L"s_action_nurturing_gift"));
    if (Unk_AkoHouseSvc::GetInstance()->FUN_1410c3180() == reinterpret_cast<Unk_AkoPlayerView*>(pPlayer)->FUN_141656ad0())
        return FUN_140960c30(0x634, FUN_14028b8e0(L"s_action_nurturing_eat"));
    return FUN_140960c30(0x634, FUN_14028b8e0(L"s_action_nurturing_play"));
}
MS2_REPLACE_METHOD(0x14095E870, NurturingCubeAction, vfunc_6, 490, 0x7769ECD3);
// @0x14095ea60
CStringW NurturingCubeAction::vfunc_8() { return L"key"; }
MS2_REPLACE_METHOD(0x14095EA60, NurturingCubeAction, vfunc_8, 61, 0xD42F286F);
// @0x14095eab0
int NurturingCubeAction::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x14095EAB0, NurturingCubeAction, vfunc_10, 8, 0x7F371472);
// @0x14095eac0
void NurturingCubeAction::vfunc_3()
{
    m_str18 = "";
    m_n30 = 0;
}
MS2_REPLACE_METHOD(0x14095EAC0, NurturingCubeAction, vfunc_3, 51, 0x3E397E14);

// ---- BannerAction ----------------------------------------------------------------------------------------------------
// @0x14095eb00
BannerAction::BannerAction() : m_n18(0), m_n1c(0) {}
// @0x14095eb50
BannerAction::~BannerAction() {}
// @0x14095eb80
int BannerAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (!FUN_140b7f400(pPlayer))
        return 0;
    PCBase* pTarget = FUN_14095edf0();
    if (!pTarget)
        return 0;
    MS2Ptr<Unk_PCBaseComp_ac8> spBanner = pTarget->vfunc_87();
    if (spBanner == 0)
        return 0;
    m_n18 = spBanner->FUN_140ba8700();
    return 1;
}
MS2_REPLACE_METHOD(0x14095EB80, BannerAction, vfunc_1, 223, 0xBBBA823D);
// @0x14095ec70
void BannerAction::vfunc_2()
{
    PCBase* pTarget = FUN_14095edf0();
    if (!pTarget)
        return;
    UIBanner* pBanner = Unk_GetUI<UIBanner>(0x4e30);
    if (!pBanner)
        return;
    unsigned nNow = FUN_140869420();
    if (nNow - m_n1c < 300)
        return;
    pBanner->FUN_140ba8b80(pTarget->FUN_14123c580());
    m_n1c = nNow;
}
MS2_REPLACE_METHOD(0x14095EC70, BannerAction, vfunc_2, 132, 0xFA744602);
// @0x14095ed20
CStringW BannerAction::vfunc_6()
{
    switch (m_n18)
    {
    case 1:
        return FUN_14028de60(0x65d);
    case 2:
        return FUN_14028b8e0(L"s_action_banner_couple_dance");
    default:
        return FUN_14028de60(0x65c);
    }
}
MS2_REPLACE_METHOD(0x14095ED20, BannerAction, vfunc_6, 191, 0x7C5FCB93);
// @0x14095edf0
PCBase* BannerAction::FUN_14095edf0()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_1416595d0())
        return 0;
    NiPoint3 ptMine = pPlayer->vfunc_18();
    ATL::CAtlList<efd::SmartPointer<Unk_WsC_GameObj> > objects(10);
    FUN_1403ed2d0()->FUN_141bd2db0(&objects, FUN_141274b10);
    float fMaxDist = static_cast<float>(*static_cast<Client::Constants*>(FUN_1401d3200())->MicroGameMaxDistance.Get());
    float fMaxUp = 50.0f;
    float fMaxDown = 50.0f;
    PCBase* pNearest = 0;
    float fNearest = FLT_MAX;
    POSITION pos = objects.GetHeadPosition();
    while (pos != 0)
    {
        PCBase* pPC = efd::DynamicCast<PC>(objects.GetNext(pos));
        if (!pPC)
            continue;
        if (efd::DynamicCast<Unk_AkoMyPC>(pPC) != 0)
            continue;
        if (pPC->GetClassID() == 0x6200016)
            continue;
        if (pPC->FUN_14166c930() != 0x3b)
            continue;
        if (pPC->FUN_141670a00(4) <= 0)
            continue;
        float fHeight = pPC->vfunc_18().z - ptMine.z;
        if (fHeight > 50.0f)
            continue;
        if (fHeight < -50.0f)
            continue;
        float fDist = FUN_140966ea0(ptMine, pPC->vfunc_18());
        if (fDist > fMaxDist)
            continue;
        if (fDist < fNearest)
        {
            fNearest = fDist;
            pNearest = pPC;
        }
    }
    return pNearest;
}
MS2_REPLACE_METHOD(0x14095EDF0, BannerAction, FUN_14095edf0, 667, 0x36CC3C2A);
// @0x14095ed00
int BannerAction::vfunc_5() { return 0x19; }
MS2_REPLACE_METHOD(0x14095ED00, BannerAction, vfunc_5, 11, 0x4FAEBC98);

// ---- ReactorAction ---------------------------------------------------------------------------------------------------
// @0x14095f0a0
ReactorAction::ReactorAction() : m_nReactorId(0), m_n1c(0) {}
// @0x14095f0f0
ReactorAction::~ReactorAction()
{
    m_nReactorId = 0;
}
// @0x14095f130
int ReactorAction::vfunc_1()
{
    efd::SmartPointer<CReactor> spOld = reinterpret_cast<CReactor*>(FUN_1403ed2d0()->FUN_141bd1180(m_nReactorId));
    efd::SmartPointer<CReactor> spNew = FUN_14095fcb0();
    if (spOld && spOld != spNew)
        spOld->FUN_140b78b40(false);
    if (spNew && !vfunc_13(spNew))
        return 0;
    if (spNew)
    {
        spNew->FUN_140b78b40(true);
        m_nReactorId = spNew->FUN_14123c580();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14095F130, ReactorAction, vfunc_1, 433, 0x4147180C);
// @0x14095f2f0
void ReactorAction::vfunc_2()
{
    efd::SmartPointer<CReactor> spReactor = reinterpret_cast<CReactor*>(FUN_1403ed2d0()->FUN_141bd1180(m_nReactorId));
    if (spReactor == 0)
        return;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    MS2Ptr<ReactorData> spData = spReactor->FUN_140966e50();
    if (!spData)
        return;
    int nResult = FUN_140b7a3d0(pPlayer, spData->m_nId);
    switch (nResult)
    {
    case 0:
        break;
    case 6:
        FUN_1412751f0(FUN_14028b8e0(L"s_reactor_action_failed_reward_count"), 1, 1);
        return;
    default:
        FUN_1412751f0(FUN_14028b8e0(L"s_reactor_action_failed"), 1, 1);
        return;
    }
    if (spData->m_nReactTimeMSec != 0)
    {
        if (pPlayer->FUN_141527160(0x3d) == 0)
            return;
        if (pPlayer->FUN_1416764a0())
        {
            MS2Ptr<RideOffActionReact> spRideOff(new RideOffActionReact(0));
            spRideOff->m_n28 = spReactor->FUN_140b78bb0();
            spRideOff->m_s30 = spReactor->FUN_140b78af0();
            pPlayer->FUN_14152c280(spRideOff);
        }
        else
        {
            MS2Ptr<StateReactData> spState(new StateReactData(spReactor->FUN_140b78bb0(), spReactor->FUN_140b78af0(), ""));
            pPlayer->vfunc_59(0x3d, spState, 0x9f, 0);
        }
    }
    else
    {
        if (pPlayer->FUN_14166c930() == 0x10)
            return;
        else
        {
            pPlayer->FUN_14152e0c0();
            spReactor->FUN_140b799a0();
        }
    }
    m_n1c = 1;
}
MS2_REPLACE_METHOD(0x14095F2F0, ReactorAction, vfunc_2, 1363, 0x13E6DE8F);
// @0x14095f870
CStringW ReactorAction::vfunc_6()
{
    if (m_nReactorId == 0)
        return L"";
    efd::SmartPointer<CReactor> spReactor = reinterpret_cast<CReactor*>(FUN_1403ed2d0()->FUN_141bd1180(m_nReactorId));
    if (spReactor == 0)
        return L"";
    MS2Ptr<ReactorStateData> spState = spReactor->FUN_140966db0();
    if (spState == 0)
        return L"";
    CStringW strAction = FUN_14028b8e0(spState->m_strActionStringKey);
    if (strAction.GetLength() < 1)
        return L"";
    return FUN_140960c30(0x65e, strAction);
}
MS2_REPLACE_METHOD(0x14095F870, ReactorAction, vfunc_6, 541, 0xCBB31A63);
// @0x14095faf0
void ReactorAction::vfunc_3()
{
    efd::SmartPointer<CReactor> spReactor = reinterpret_cast<CReactor*>(FUN_1403ed2d0()->FUN_141bd1180(m_nReactorId));
    if (spReactor == 0)
        return;
    m_n1c = 0;
    m_nReactorId = 0;
}
MS2_REPLACE_METHOD(0x14095FAF0, ReactorAction, vfunc_3, 123, 0xF4FA6951);
// @0x14095fb80
Unk_AkoTarget ReactorAction::vfunc_12()
{
    efd::SmartPointer<CReactor> spReactor = reinterpret_cast<CReactor*>(FUN_1403ed2d0()->FUN_141bd1180(m_nReactorId));
    if (spReactor == 0)
        return ActionKeyObject::vfunc_12();
    // GameObject slot 18 (the position) through the world-object view: reactor.h only has NiPoint3 for it
    return Unk_AkoTarget(reinterpret_cast<Unk_WsC_GameObj*>(spReactor.operator->())->vfunc_18());
}
MS2_REPLACE_METHOD(0x14095FB80, ReactorAction, vfunc_12, 183, 0x59BCCBEC);
// MS2-FUNCTIONAL: exe passes the point to WorldService::FUN_141bc6c60 by value (rep movsb copy); shared header declares const&
// @0x14095fcb0
CReactor* ReactorAction::FUN_14095fcb0()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    efd::SmartPointer<Unk_WsB_Spawn> spReactor = FUN_1403ed2d0()->FUN_141bc6c60(pPlayer->FUN_1416767d0(), 1);
    if (spReactor == 0)
        return 0;
    return spReactor;
}
MS2_REPLACE_METHOD(0x14095FCB0, ReactorAction, FUN_14095fcb0, 203, 0x06F81E28);
// @0x14095f850
int ReactorAction::vfunc_5() { return 0x1a; }
MS2_REPLACE_METHOD(0x14095F850, ReactorAction, vfunc_5, 11, 0x01B9B841);
// @0x14095faa0
CStringW ReactorAction::vfunc_7() { return FUN_14016a730("reactor", 0); }
MS2_REPLACE_METHOD(0x14095FAA0, ReactorAction, vfunc_7, 63, 0xDA1646EA);
// @0x14095fc40
int ReactorAction::vfunc_13(efd::SmartPointer<CReactor> spReactor)
{
    if (!spReactor)
        return 0;
    return spReactor->FUN_140b79c30();
}
MS2_REPLACE_METHOD(0x14095FC40, ReactorAction, vfunc_13, 106, 0xBDD2E157);

// ---- QuestUserFindAction ---------------------------------------------------------------------------------------------
// @0x14095fd90
QuestUserFindAction::QuestUserFindAction() : m_n18(0), m_n20(0) {}
// @0x14095fde0
QuestUserFindAction::~QuestUserFindAction() {}
// @0x14095fe10
int QuestUserFindAction::vfunc_1()
{
    WorldService* pWorld = FUN_1403ed2d0();
    if (!pWorld)
        return 0;
    Unk_WsC_GameObj* pPlayer = static_cast<Unk_WsC_GameObj*>(pWorld->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    std::pair<int, __int64> user = FUN_140764020()->FUN_1416d1e90();
    int nQuestId = user.first;
    __int64 nCharId = user.second;
    Unk_WsC_GameObj* pTarget = pWorld->FUN_141bd1530(nCharId);
    if (!pTarget)
        return 0;
    float fDist = FUN_140966f00(pPlayer->vfunc_18(), pTarget->vfunc_18());
    if (fDist > *FUN_1401d3200()->InteractionDistance.Get())
        return 0;
    m_n18 = nCharId;
    m_n20 = nQuestId;
    return 1;
}
MS2_REPLACE_METHOD(0x14095FE10, QuestUserFindAction, vfunc_1, 332, 0x0FBDC102);
// @0x14095ff70
void QuestUserFindAction::vfunc_2()
{
    PCBase* pTarget = reinterpret_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd1530(m_n18));
    if (!pTarget)
        return;
    COutPacket packet(0x29);
    packet.Encode1(0x1c);
    packet.Encode4(m_n20);
    packet.Encode8(pTarget->FUN_141656a80());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14095FF70, QuestUserFindAction, vfunc_2, 159, 0xBE4BF40A);
// @0x140960040
CStringW QuestUserFindAction::vfunc_6()
{
    PCBase* pTarget = reinterpret_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd1530(m_n18));
    if (!pTarget)
        return L"";
    const CStringW& strName = pTarget->vfunc_77();
    CStringW strKey = L"s_action_questUserFind";
    CStringW strQuestKey;
    strQuestKey.Format(L"%s_%d", (const wchar_t*)strKey, m_n20);
    CStringW strText = FUN_1405c2690(strQuestKey, strName);
    if (!strText.IsEmpty())
        return strText;
    return FUN_1405c2690(strKey, strName);
}
MS2_REPLACE_METHOD(0x140960040, QuestUserFindAction, vfunc_6, 518, 0x47546616);
// @0x140960020
int QuestUserFindAction::vfunc_5() { return 7; }
MS2_REPLACE_METHOD(0x140960020, QuestUserFindAction, vfunc_5, 11, 0x41502B22);

// ---- TreeWateringAction ----------------------------------------------------------------------------------------------
// The game event manager singleton (class of unit_1401c0d90, unrecovered): the tree watering event's context at +0xbf0.
class Unk_1401c0d90
{
public:
    MS2Ptr<TreeWateringContext> FUN_14047d320();            // the context (copied under the manager's lock)
};
Unk_1401c0d90* FUN_1401c0d90();
// The context pointer's out-of-line members (COMDATs of the gameevent tail; symbols-manual rows).
template <> MS2Ptr<TreeWateringContext>::~MS2Ptr();
template <> bool MS2Ptr<TreeWateringContext>::operator==(TreeWateringContext* p) const;
template <> TreeWateringContext* MS2Ptr<TreeWateringContext>::operator->() const;
// The attend table (global 0x143ab2fc0): the day's counters by row id and event id (the table template of
// uilongtermattendgiftdialog.cpp; key (row, id), map at +0x18, entry text at +0x20, expiry at +0x28).
struct Unk_AttendKey
{
    Unk_AttendKey(int nRow, int nId);                       // 0x14041eee0
    int m_nRow;
    int m_nId;
};
class Unk_AttendValue;
class Unk_AttendIter                                        // 24 bytes; ctor 0x140420170, dtor 0x140420290
{
public:
    Unk_AttendIter();
    ~Unk_AttendIter();
    Unk_AttendValue* FUN_140420460();                       // the entry
private:
    void* m_pad_00;
    void* m_pad_08;
    void* m_pad_10;
};
MS2_CHECK_SIZE(Unk_AttendIter, 0x18);
class Unk_AttendMap { public: bool FUN_140420bb0(const Unk_AttendKey& key, Unk_AttendIter& it); };
int FUN_1407181a0(const CStringW& strValue);                // _wtoi
__int64 FUN_140869440();                                    // the server time
class Unk_AttendValue
{
public:
    int FUN_140961970(const int& nDefault) const;
    void* m_pad_00;
    void* m_pad_08;
    void* m_pad_10;
    void* m_pad_18;
    CStringW m_strValue;                                    // +0x20 the stored text
    CMsTime m_expire;                                       // +0x28 the expiry
};
MS2_CHECK_OFFSET(Unk_AttendValue, m_strValue, 0x20);
MS2_CHECK_OFFSET(Unk_AttendValue, m_expire, 0x28);
class Unk_AttendTable
{
public:
    int FUN_1409617d0(int nRow, unsigned nEventId, const int& nDefault);
private:
    void* m_pad_00;
    void* m_pad_08;
    void* m_pad_10;
    Unk_AttendMap m_map;                                    // +0x18
};
extern Unk_AttendTable g_attendTable;

// @0x140961970 the value while it has not expired, else the default
inline int Unk_AttendValue::FUN_140961970(const int& nDefault) const
{
    CMsTime now(FUN_140869440());
    if (m_expire <= now)
        return nDefault;
    return FUN_1407181a0(m_strValue);
}

// @0x1409617d0
inline int Unk_AttendTable::FUN_1409617d0(int nRow, unsigned nEventId, const int& nDefault)
{
    Unk_AttendKey key(nRow, nEventId);
    Unk_AttendIter it;
    if (m_map.FUN_140420bb0(key, it))
        return it.FUN_140420460()->FUN_140961970(nDefault);
    return nDefault;
}

extern Unk_Inventory DAT_143ab2a90;

// @0x140960250
TreeWateringAction::TreeWateringAction() {}
// @0x140960290
TreeWateringAction::~TreeWateringAction() {}
// @0x1409602c0
int TreeWateringAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_14166ce30() != 0)
        return 0;
    if (!static_cast<Unk_AkoPCMove*>(pPlayer->FUN_14166d240())->FUN_141683ef0())
        return 0;
    int nState = pPlayer->FUN_14166c930();
    if (nState == 0x3e || nState == 0x1e)
        return 0;
    MS2Ptr<TreeWateringContext> spContext = FUN_1401c0d90()->FUN_14047d320();
    if (spContext == 0)
        return 0;
    efd::SmartPointer<egf::Entity> spTree = FUN_1403ed2d0()->FUN_141bd2cd0(spContext->m_strTreeName);
    if (spTree == 0)
        return 0;
    NiPoint3 ptTree = reinterpret_cast<const NiPoint3&>(DAT_143b01a60);
    spTree->GetPropertyValue(0xfd95ca52, static_cast<efd::Point3&>(ptTree));
    float fDist = FUN_140966ea0(pPlayer->vfunc_18(), ptTree);
    if (fDist < 400.0f)
    {
        int nDefaultWater = 0;
        m_n18 = g_attendTable.FUN_1409617d0(0x777, spContext->m_nEventId, nDefaultWater);
        int nDefaultBonus = 0;
        m_n1c = g_attendTable.FUN_1409617d0(0x778, spContext->m_nEventId, nDefaultBonus);
        if (m_n18 < spContext->m_nDailyLimit)
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e2e0(spContext->m_nWaterItemId);
            if (spItem.get() != 0)
                return 1;
        }
        CMsTime now(FUN_140869440());
        if (spContext->FUN_1404038c0(now) == 1 && m_n1c < spContext->m_nBonusLimit
            && m_n18 >= spContext->m_nDailyLimit)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1409602C0, TreeWateringAction, vfunc_1, 985, 0x74DFA7D4);
// @0x1409606a0
void TreeWateringAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    MS2Ptr<TreeWateringContext> spContext = FUN_1401c0d90()->FUN_14047d320();
    if (spContext == 0)
        return;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e2e0(spContext->m_nWaterItemId);
    if (spItem.get() != 0 && m_n18 < spContext->m_nDailyLimit)
    {
        MS2Ptr<StateTreeWateringData> spState(new StateTreeWateringData(spContext->m_strStateWater));
        pPlayer->vfunc_59(0x3e, spState, 0xa0, 0);
        return;
    }
    CMsTime now(FUN_140869440());
    if (spContext->FUN_1404038c0(now) == 1 && m_n1c < spContext->m_nBonusLimit
        && m_n18 >= spContext->m_nDailyLimit)
    {
        MS2Ptr<StateTreeWateringData> spState(new StateTreeWateringData(spContext->m_strStateBonus));
        pPlayer->vfunc_59(0x3e, spState, 0xa1, 0);
    }
}
MS2_REPLACE_METHOD(0x1409606A0, TreeWateringAction, vfunc_2, 837, 0xF791FF78);
// @0x140960a10
CStringW TreeWateringAction::vfunc_6()
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return CStringW(L"");
    MS2Ptr<TreeWateringContext> spContext = FUN_1401c0d90()->FUN_14047d320();
    if (spContext == 0)
        return CStringW(L"");
    if (m_n18 < spContext->m_nDailyLimit)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e2e0(spContext->m_nWaterItemId);
        if (spItem.get() != 0)
            return FUN_14028de60(0xd19);
    }
    CMsTime now(FUN_140869440());
    if (spContext->FUN_1404038c0(now) == 1 && m_n1c < spContext->m_nBonusLimit)
        return FUN_14028de60(0xd1a);
    return CStringW(L"");
}
MS2_REPLACE_METHOD(0x140960A10, TreeWateringAction, vfunc_6, 529, 0x58A43792);
// @0x1409609f0
int TreeWateringAction::vfunc_5() { return 0x1c; }
MS2_REPLACE_METHOD(0x1409609F0, TreeWateringAction, vfunc_5, 11, 0x25A49707);

// ---- inline members of other headers (COMDATs of this obj) ------------------------------------------------------------

// @0x140965c40
Unk_StreamPoint Unk_StreamPoint::FUN_140965c40(const Unk_StreamPoint& pt) const
{
    return Unk_StreamPoint(x - pt.x, y - pt.y, z - pt.z);
}

// @0x140967ac0
float Unk_StreamPoint::FUN_140967ac0() const
{
    return efd::Sqrt(x * x + y * y + z * z);
}

// @0x140968990
float Unk_StreamPoint::FUN_140968990()
{
    float fLength = FUN_140967ac0();
    if (fLength > 1e-06f)
    {
        float fRecip = 1.0f / fLength;
        x *= fRecip;
        y *= fRecip;
        z *= fRecip;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        fLength = 0.0f;
    }
    return fLength;
}

// @0x140966ea0 the distance in the xy plane
float FUN_140966ea0(Unk_StreamPoint a, Unk_StreamPoint b)
{
    a.z = 0.0f;
    b.z = 0.0f;
    a = b.FUN_140965c40(a);
    return a.FUN_140967ac0();
}

// @0x140966f00
float FUN_140966f00(Unk_StreamPoint a, Unk_StreamPoint b)
{
    a = b.FUN_140965c40(a);
    return a.FUN_140967ac0();
}

// @0x140966f40 the first required item's id (0 without one)
unsigned FUN_140966f40(const Unk_AkoReqItemList& list)
{
    if (list.m_v.empty())
        return 0;
    return list.m_v[0].m_nItemId;
}

// @0x140966f80 the first required item's rarity (0 without one)
unsigned short FUN_140966f80(const Unk_AkoReqItemList& list)
{
    if (list.m_v.empty())
        return 0;
    return list.m_v[0].m_nRarity;
}

// @0x140966db0
MS2Ptr<ReactorStateData> CReactor::FUN_140966db0()
{
    return FUN_140b78c00(m_nStateIdx);
}

// @0x140966e50
MS2Ptr<ReactorData> CReactor::FUN_140966e50()
{
    return m_spData;
}

// @0x140966e00
MS2Ptr<CInteractObjectData> CInteractObject::FUN_140966e00()
{
    return m_spRow;
}

// @0x140967060
CString CInteractObject::FUN_140967060()
{
    return m_strName;
}

// @0x140967110
int CInteractObject::FUN_140967110()
{
    return m_nRowId;
}

// @0x1409673c0
Unk_StreamPoint CInteractObject::FUN_1409673c0()
{
    return m_vPos;
}

// @0x140966fc0
int CFunctionCubeObject::FUN_140966fc0()
{
    return m_spData->m_nKind;
}

// @0x1409674f0
int CFunctionCubeObject::FUN_1409674f0()
{
    return m_spData->m_nSubKind;
}

// @0x140964630
Unk_QmNpcQuestState::Unk_QmNpcQuestState()
{
    m_wantText = 0;
    FUN_1409669c0();
}

// @0x140964e40
Unk_QmNpcQuestState::~Unk_QmNpcQuestState()
{
}

// @0x1409669c0
void Unk_QmNpcQuestState::FUN_1409669c0()
{
    m_icon = 0xb;
    m_state = 4;
    m_questId = 0;
    m_text = "";
    m_npcId = 0;
}

// @0x140967520 (T = float)
template <class T> const T& Common::Constants::Value<T>::Get(const T& kDefault)
{
    if (m_loaded)
        return m_value;
    if (!HasKey())
        Error("constants has no key");
    return kDefault;
}

// ---- CMsgBoxData (helper instantiated here) ---------------------------------------------------------------------------
int FUN_140718200(const CStringW& strValue);                // _wtoi
// @0x140961900
bool CMsgBoxData::FUN_140961900(unsigned int nIndex, int& nOut) const
{
    if (nIndex >= m_args.GetCount())
        return false;
    nOut = FUN_140718200(m_args[nIndex]);
    return true;
}
MS2_REPLACE_METHOD(0x140961900, CMsgBoxData, FUN_140961900, 103, 0x99208798);

// The range's last bytes are a second TU's CRT memmove_s (the UCRT static __inline copy is per TU; this obj's own copy
// is pinned at the top).
// @0x14096b1e0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9d480-0x142c9d4f0 .text$yd
