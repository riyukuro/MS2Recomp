// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService COMDAT tail, sub-unit #7 (owner w529): the sorted
// member COMDATs CRBTree::RBDelete .. std::_Tree_comp_alloc::_Buynode0 (CAtlMap/CRBTree internals, MessageHandler
// RegisterMessageFactory, CAtlMap::Rehash/RemoveAll/SetOptimalLoad, WorldService::SetupClassInfo/TypeCast). The COMDATs are
// instantiated over the recovered member types (worldservice_tail.h: ATL families, w530; worldservice_real.h: std families)
// by Unk_WsInst7, which performs the container operations of the WorldService methods.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\worldservice.cpp#7
// MS2-RANGE: 0x141c0e080-0x141c20d10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$SmartPointer@VEnt738@WsReal@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VEnt738@WsReal@@@efd@@@4@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c18d10
// MS2-PIN: ?SetAt@?$CRBMap@W4Unk_WsKindKey@@HV?$CElementTraits@W4Unk_WsKindKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAAPEAU__POSITION@@AEBW4Unk_WsKindKey@@H@Z 0x141c1ba40
// MS2-PIN: ?SetAt@?$CRBMap@_KV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@QEAAPEAU__POSITION@@_KAEBV?$SmartPointer@VGameObject@@@efd@@@Z 0x141c1baa0
// MS2-PIN: ?SetConstant@NiPlane@@QEAAXM@Z 0x141c1bb10
// MS2-PIN: ?SetNil@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1c020
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@_JV?$SmartPointer@VUnk_WsMapV8@@@efd@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$SmartPointer@VUnk_WsMapV8@@@efd@@@4@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c18070
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$SmartPointer@VEnt738@WsReal@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VEnt738@WsReal@@@efd@@@4@@ATL@@QEAA_NI@Z 0x141c184a0
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$SmartPointer@VEnt738@WsReal@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VEnt738@WsReal@@@efd@@@4@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17ad0
// MS2-PIN: ?RBInsert@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@IEAAPEAVCNode@12@IAEBV?$MS2Ptr@VUnk_WsTargetF7@@@@@Z 0x141c11d20
// MS2-PIN: ?RightRotate@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c19c00
// MS2-PIN: ?SetAt@?$CRBMap@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@QEAAPEAU__POSITION@@AEBQEAVEntity@egf@@AEBV?$MS2Ptr@VUnk_WsMarker@@@@@Z 0x141c1b880
// MS2-PIN: ?FUN_141c1bb30@MS2ActorUpdater@@QEAAXM@Z 0x141c1bb30
// MS2-PIN: ?SetNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1bbc0
// MS2-PIN: ?FUN_141c1ca80@COptimizer@@QEAAXH@Z 0x141c1ca80
// MS2-PIN: ?FUN_141c1caa0@CEffectService@@QEAAXH@Z 0x141c1caa0
// MS2-PIN: ?AddRefImpl@?$Unk_BmBoxPtr@V?$CAtlList@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@ATL@@@ATL@@@@AEBAXPEAX@Z 0x141c1f710
// MS2-PIN: ?RemoveAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17920
// MS2-PIN: ?RemoveKey@?$CAtlMap@_JV?$SmartPointer@VUnk_WsMapV8@@@efd@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$SmartPointer@VUnk_WsMapV8@@@efd@@@4@@ATL@@QEAA_N_J@Z 0x141c186d0
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VCProxyGameObject@@@@@Z 0x141c1afc0
// MS2-PIN: ?AddRef@?$MS2Ptr@VRec1f8@WsReal@@@@AEBAXXZ 0x141c1f5c0
// MS2-PIN: ?AddRef@?$MS2Ptr@VRecad0@WsReal@@@@AEBAXXZ 0x141c1f5f0
// MS2-PIN: ?RemoveKey@?$CRBMap@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@QEAA_NAEBVEntityID@egf@@@Z 0x141c18b10
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_WsMapV10@@@@AEBAXXZ 0x141c1f500
// MS2-PIN: ?RemoveAt@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17740
// MS2-PIN: ?RemoveAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c178c0
// MS2-PIN: ?Rehash@?$CAtlMap@HV?$MS2Ptr@VCPortal@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCPortal@@@@@3@@ATL@@QEAAXI@Z 0x141c14860
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV3@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV3@@@@@3@@ATL@@QEAAXI@Z 0x141c14cc0
//
// MS2-PIN: ?Rehash@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV9@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV9@@@@@3@@ATL@@QEAAXI@Z 0x141c159e0
//
//
//
//
//
// MS2-PIN: ?RemoveAll@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEAAXXZ 0x141c16670
//
// MS2-PIN: ?RemoveAll@?$CAtlMap@W4Unk_WsMapKey7@@V?$MS2Ptr@VUnk_WsMapV7@@@@V?$CElementTraits@W4Unk_WsMapKey7@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV7@@@@@4@@ATL@@QEAAXXZ 0x141c16890
// MS2-PIN: ?RemoveAll@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetBox@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetBox@@@@@3@@ATL@@QEAAXXZ 0x141c16de0
// MS2-PIN: ?RemoveAll@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@QEAAXXZ 0x141c17360
// MS2-PIN: ?RemoveAll@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@QEAAXXZ 0x141c173e0
// MS2-PIN: ?RemoveAll@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@2@@ATL@@QEAAXXZ 0x141c17460
// MS2-PIN: ?RemoveAll@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@QEAAXXZ 0x141c174e0
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HV?$MS2Ptr@VCPortal@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCPortal@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c179e0
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@W4Unk_WsMapKey7@@V?$MS2Ptr@VUnk_WsMapV7@@@@V?$CElementTraits@W4Unk_WsMapKey7@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV7@@@@@4@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17f80
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV9@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV9@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c18160
//
// MS2-PIN: ?RemoveKey@?$CAtlMap@HV?$MS2Ptr@VCPortal@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCPortal@@@@@3@@ATL@@QEAA_NH@Z 0x141c18430
// MS2-PIN: ?RemoveKey@?$CAtlMap@W4Unk_WsMapKey7@@V?$MS2Ptr@VUnk_WsMapV7@@@@V?$CElementTraits@W4Unk_WsMapKey7@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV7@@@@@4@@ATL@@QEAA_NAEBW4Unk_WsMapKey7@@@Z 0x141c18660
// MS2-PIN: ?RemoveKey@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV9@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV9@@@@@3@@ATL@@QEAA_N_J@Z 0x141c18740
//
// MS2-PIN: ?RemoveNode@?$CAtlMap@HV?$MS2Ptr@VCPortal@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCPortal@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c18c50
// MS2-PIN: ?RemoveNode@?$CAtlMap@W4Unk_WsMapKey7@@V?$MS2Ptr@VUnk_WsMapV7@@@@V?$CElementTraits@W4Unk_WsMapKey7@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV7@@@@@4@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c190d0
// MS2-PIN: ?RemoveNode@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV9@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV9@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c19250
//
// MS2-PIN: ?RemovePostOrder@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetBox@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetBox@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c19490
// MS2-PIN: ?RemovePostOrder@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c198b0
// MS2-PIN: ?RemovePostOrder@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c19910
// MS2-PIN: ?RemovePostOrder@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c19970
// MS2-PIN: ?RemovePostOrder@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c199d0
// MS2-PIN: ?SetAt@?$CAtlMap@HV?$MS2Ptr@VCPortal@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCPortal@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$MS2Ptr@VCPortal@@@@@Z 0x141c1ad00
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$SmartPointer@VEnt738@WsReal@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VEnt738@WsReal@@@efd@@@4@@ATL@@QEAAPEAU__POSITION@@IAEBV?$SmartPointer@VEnt738@WsReal@@@efd@@@Z 0x141c1adb0
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV3@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV3@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VUnk_WsMapV3@@@@@Z 0x141c1ae60
// MS2-PIN: ?SetAt@?$CAtlMap@W4Unk_WsMapKey7@@V?$MS2Ptr@VUnk_WsMapV7@@@@V?$CElementTraits@W4Unk_WsMapKey7@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV7@@@@@4@@ATL@@QEAAPEAU__POSITION@@AEBW4Unk_WsMapKey7@@AEBV?$MS2Ptr@VUnk_WsMapV7@@@@@Z 0x141c1b120
// MS2-PIN: ?SetAt@?$CAtlMap@_JV?$SmartPointer@VUnk_WsMapV8@@@efd@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$SmartPointer@VUnk_WsMapV8@@@efd@@@4@@ATL@@QEAAPEAU__POSITION@@_JAEBV?$SmartPointer@VUnk_WsMapV8@@@efd@@@Z 0x141c1b1d0
// MS2-PIN: ?SetAt@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV9@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV9@@@@@3@@ATL@@QEAAPEAU__POSITION@@_JAEBV?$MS2Ptr@VUnk_WsMapV9@@@@@Z 0x141c1b280
//
// MS2-PIN: ?SetNil@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetBox@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetBox@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1bb50
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@HV?$MS2Ptr@VCPortal@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCPortal@@@@@3@@ATL@@QEAAXMMM_N@Z 0x141c1c2f0
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV3@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV3@@@@@3@@ATL@@QEAAXMMM_N@Z 0x141c1c450
//
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV9@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV9@@@@@3@@ATL@@QEAAXMMM_N@Z 0x141c1c870
//
// MS2-PIN: ?Successor@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetBox@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetBox@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c1cb20
// MS2-PIN: ?Successor@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c1cbf0
// MS2-PIN: ?Successor@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c1ccc0
// MS2-PIN: ?SwapNode@?$CRBTree@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c1d7e0
// MS2-PIN: ?SwapNode@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c1d940
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@HV?$MS2Ptr@VCPortal@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCPortal@@@@@3@@ATL@@AEAAXXZ 0x141c1eb00
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV3@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV3@@@@@3@@ATL@@AEAAXXZ 0x141c1ecc0
//
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV9@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV9@@@@@3@@ATL@@AEAAXXZ 0x141c1f200
//
//
// MS2-PIN: ?Reference@?$MS2Ptr@VRec1f8@WsReal@@@@CAXPEAVRec1f8@WsReal@@@Z 0x141c1f6a0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@2@XZ 0x141c1f9b0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$SmartPointer@VEntity@egf@@@efd@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$SmartPointer@VEntity@egf@@@efd@@@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@XZ 0x141c1fa70
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@6@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@2@XZ 0x141c1fb30
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@6@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@2@XZ 0x141c1fbf0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@6@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@XZ 0x141c1fcb0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HU?$pair@VEntityID@egf@@I@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@VEntityID@egf@@I@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHU?$pair@VEntityID@egf@@I@std@@@std@@PEAX@2@XZ 0x141c1f8f0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@XZ 0x141c1fe30
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$MS2Ptr@VRecad0@WsReal@@@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@2@XZ 0x141c1fef0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@VVisibleObjectRecord@WsReal@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@6@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@PEAX@2@XZ 0x141c1fd70
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@2@XZ 0x141c20210
// MS2-PIN: ?_Buynode0@?$_List_alloc@U?$_List_base_types@PEAVEntity@egf@@V?$allocator@PEAVEntity@egf@@@std@@@std@@@std@@QEAAPEAU?$_List_node@PEAVEntity@egf@@PEAX@2@PEAU32@0@Z 0x141c20070
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@6@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@2@XZ 0x141c203d0
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@6@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@2@XZ 0x141c204b0
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@6@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@XZ 0x141c20590
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@VVisibleObjectRecord@WsReal@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@6@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@PEAX@2@XZ 0x141c20670
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HU?$pair@VEntityID@egf@@I@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHU?$pair@VEntityID@egf@@I@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHU?$pair@VEntityID@egf@@I@std@@@std@@PEAX@2@XZ 0x141c20130
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$SmartPointer@VEntity@egf@@@efd@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$SmartPointer@VEntity@egf@@@efd@@@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@XZ 0x141c202f0
// MS2-PIN: ?RBDeleteFixup@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c11110
// MS2-PIN: ?RBInsert@?$CRBTree@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@IEAAPEAVCNode@12@IAEBV?$SmartPointer@VPC@@@efd@@@Z 0x141c12720
// MS2-PIN: ?RBInsert@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@IEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VCLiftableObject@@@@@Z 0x141c13b20
// MS2-PIN: ?RBInsert@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@IEAAPEAVCNode@12@AEBVEntityID@egf@@AEBV?$MS2Ptr@VCInteractObject@@@@@Z 0x141c13da0
// MS2-PIN: ?RemoveAll@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@QEAAXXZ 0x141c16ee0
// MS2-PIN: ?RemoveAll@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@QEAAXXZ 0x141c171e0
// MS2-PIN: ?RemoveAll@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@QEAAXXZ 0x141c17260
// MS2-PIN: ?RemoveAll@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@QEAAXXZ 0x141c172e0
// MS2-PIN: ?RemoveAt@?$CRBTree@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c177d0
// MS2-PIN: ?RemoveAt@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17830
// MS2-PIN: ?RemoveAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17860
// MS2-PIN: ?RemoveAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17890
// MS2-PIN: ?RemoveKey@?$CRBMap@IV?$SmartPointer@VCNpc@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VCNpc@@@efd@@@4@@ATL@@QEAA_NI@Z 0x141c188e0
// MS2-PIN: ?RemoveKey@?$CRBMap@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@QEAA_NAEBQEAVEntity@egf@@@Z 0x141c18a20
// MS2-PIN: ?RemoveKey@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@QEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141c18a70
// MS2-PIN: ?RemoveKey@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@QEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141c18ac0
// MS2-PIN: ?RemovePostOrder@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c197f0
// MS2-PIN: ?RemovePostOrder@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c19850
// MS2-PIN: ?RightRotate@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c1a9d0
// MS2-PIN: ?SetAt@?$CRBMap@IV?$SmartPointer@VCNpc@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VCNpc@@@efd@@@4@@ATL@@QEAAPEAU__POSITION@@IAEBV?$SmartPointer@VCNpc@@@efd@@@Z 0x141c1b500
// MS2-PIN: ?SetAt@?$CRBMap@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@QEAAPEAU__POSITION@@IAEBV?$SmartPointer@VPC@@@efd@@@Z 0x141c1b5e0
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@_JV?$SmartPointer@VUnk_WsMapV8@@@efd@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$SmartPointer@VUnk_WsMapV8@@@efd@@@4@@ATL@@QEAAXMMM_N@Z 0x141c1c7c0
// MS2-PIN: ?Successor@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c1d4e0
// MS2-PIN: ?SwapNode@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c1e5a0
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@_JV?$SmartPointer@VUnk_WsMapV8@@@efd@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$SmartPointer@VUnk_WsMapV8@@@efd@@@4@@ATL@@AEAAXXZ 0x141c1f120
// MS2-PIN: ?AddRef@?$MS2Ptr@VCLiftableTargetGuide@@@@AEBAXXZ 0x141c1f530
// MS2-PIN: ?Reference@?$MS2Ptr@VMS2ActorUpdater@@@@CAXPEAVMS2ActorUpdater@@@Z 0x141c1f660
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@XZ 0x141c20750
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCLiftableTargetGuide@@@@AEBAXPEAX@Z 0x141c1f770
// MS2-PIN: ?_Calculate_growth@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@AEBA_K_K@Z 0x141c20b60
// MS2-PIN: ?RBDeleteFixup@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c10780
// MS2-PIN: ?RBInsert@?$CRBTree@IV?$SmartPointer@VCNpc@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VCNpc@@@efd@@@4@@ATL@@IEAAPEAVCNode@12@IAEBV?$SmartPointer@VCNpc@@@efd@@@Z 0x141c12220
// MS2-PIN: ?RBInsert@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@IEAAPEAVCNode@12@AEBQEAVEntity@egf@@AEBV?$MS2Ptr@VUnk_WsMarker@@@@@Z 0x141c13620
// MS2-PIN: ?RemoveAll@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@QEAAXXZ 0x141c16e60
// MS2-PIN: ?RemoveAll@?$CRBTree@IV?$SmartPointer@VCNpc@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VCNpc@@@efd@@@4@@ATL@@QEAAXXZ 0x141c16f60
// MS2-PIN: ?RemoveAll@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@QEAAXXZ 0x141c16fe0
// MS2-PIN: ?RemoveAll@?$CRBTree@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@QEAAXXZ 0x141c17060
// MS2-PIN: ?RemoveAll@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@QEAAXXZ 0x141c170e0
// MS2-PIN: ?RemoveAll@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@QEAAXXZ 0x141c17160
// MS2-PIN: ?RemoveAt@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17800
// MS2-PIN: ?RemoveKey@?$CRBMap@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@QEAA_NI@Z 0x141c18890
// MS2-PIN: ?RemovePostOrder@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c194f0
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c19610
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c19670
// MS2-PIN: ?SetAt@?$CRBMap@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VUnk_WsTargetF7@@@@@Z 0x141c1b490
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VCInteractObject@@@@@Z 0x141c1b8f0
// MS2-PIN: ?Successor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c1d270
// MS2-PIN: ?SwapNode@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetBox@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetBox@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c1d680
// MS2-PIN: ?SwapNode@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c1dd60
// MS2-PIN: ?_Calculate_growth@?$vector@V?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@AEBA_K_K@Z 0x141c20bf0
// MS2-PIN: ?RBInsert@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@IEAAPEAVCNode@12@IAEBV?$SmartPointer@VGameObject@@@efd@@@Z 0x141c124a0
// MS2-PIN: ?RBInsert@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@IEAAPEAVCNode@12@IAEBUUnk_WsObjectEntry@@@Z 0x141c129a0
// MS2-PIN: ?RBInsert@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@IEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VCReactor@@@efd@@@Z 0x141c13120
// MS2-PIN: ?RBInsert@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@IEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x141c133a0
// MS2-PIN: ?RemoveNode@?$CAtlMap@_JV?$SmartPointer@VUnk_WsMapV8@@@efd@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$SmartPointer@VUnk_WsMapV8@@@efd@@@4@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c19190
// MS2-PIN: ?RightRotate@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c1a150
// MS2-PIN: ?RightRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c1a480
// MS2-PIN: ?SetNil@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1bc30
// MS2-PIN: ?SetNil@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1bdf0
// MS2-PIN: ?SetNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1bf40
// MS2-PIN: ?Successor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c1d0d0
// MS2-PIN: ?SwapNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c1dec0
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@AEAAXXZ 0x141c1ee80
// MS2-PIN: ?RBDelete@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@AEAA_NPEAVCNode@12@@Z 0x141c0e590
// MS2-PIN: ?RBDeleteFixup@?$CRBTree@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c0f790
// MS2-PIN: ?RemoveAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17950
// MS2-PIN: ?RemoveKey@?$CRBMap@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@QEAA_NI@Z 0x141c18980
// MS2-PIN: ?RemoveKey@?$CRBMap@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@QEAA_NAEBQEAVEntity@egf@@@Z 0x141c189d0
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VCLiftableObject@@@@@Z 0x141c1b960
// MS2-PIN: ?SetAt@?$CRBMap@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@QEAAPEAU__POSITION@@AEBVEntityID@egf@@AEBV?$MS2Ptr@VCInteractObject@@@@@Z 0x141c1b9d0
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_WsTargetF7@@@@AEBAXXZ 0x141c1f4a0
// MS2-PIN: ?AddRef@?$MS2Ptr@VMS2ActorUpdater@@@@AEBAXXZ 0x141c1f560
// MS2-PIN: ?AddRef@?$MS2Ptr@VRec058@WsReal@@@@AEBAXXZ 0x141c1f590
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VRec058@WsReal@@@@AEBAXPEAX@Z 0x141c1f7d0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VRecad0@WsReal@@@@AEBAXPEAX@Z 0x141c1f830
// MS2-PIN: ?RBDelete@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@AEAA_NPEAVCNode@12@@Z 0x141c0e080
// MS2-PIN: ?RBDeleteFixup@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c0fac0
// MS2-PIN: ?RBInsert@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@IEAAPEAVCNode@12@HAEBV?$MS2Ptr@VCLiftableTargetGuide@@@@@Z 0x141c11fa0
//
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEAA_NI@Z 0x141c18580
//
// MS2-PIN: ?RemoveKey@?$CRBMap@W4Unk_WsKindKey@@HV?$CElementTraits@W4Unk_WsKindKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAA_NAEBW4Unk_WsKindKey@@@Z 0x141c18bb0
// MS2-PIN: ?RemoveKey@?$CRBMap@_KV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@QEAA_N_K@Z 0x141c18c00
// MS2-PIN: ?SetAt@?$CRBMap@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBUUnk_WsObjectEntry@@@Z 0x141c1b650
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VCReactor@@@efd@@@Z 0x141c1b7a0
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x141c1b810
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEAAXMMM_N@Z 0x141c1c5b0
// MS2-PIN: ?Rehash@?$CAtlMap@_JV?$SmartPointer@VUnk_WsMapV8@@@efd@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$SmartPointer@VUnk_WsMapV8@@@efd@@@4@@ATL@@QEAAXI@Z 0x141c157b0
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c19550
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IV?$SmartPointer@VCNpc@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VCNpc@@@efd@@@4@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c195b0
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c196d0
// MS2-PIN: ?RemovePostOrder@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c19730
// MS2-PIN: ?RemovePostOrder@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@AEAAXPEAVCNode@12@@Z 0x141c19790
// MS2-PIN: ?RightRotate@?$CRBTree@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c1a040
// MS2-PIN: ?SetNil@?$CRBTree@IV?$SmartPointer@VPC@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VPC@@@efd@@@4@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1bd80
// MS2-PIN: ?SetNil@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1c090
// MS2-PIN: ?SetNil@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1c170
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_WsMapV3@@@@CAXPEAVUnk_WsMapV3@@@Z 0x141c1f620
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEAAXI@Z 0x141c15120
// MS2-PIN: ?RemoveAll@?$CRBTree@W4Unk_WsKindKey@@HV?$CElementTraits@W4Unk_WsKindKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAAXXZ 0x141c17560
// MS2-PIN: ?RemoveAll@?$CRBTree@_KV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@QEAAXXZ 0x141c175e0
// MS2-PIN: ?RemoveAt@?$CRBTree@W4Unk_WsKindKey@@HV?$CElementTraits@W4Unk_WsKindKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17980
// MS2-PIN: ?RemoveAt@?$CRBTree@_KV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c179b0
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17da0
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c18f50
// MS2-PIN: ?SetAt@?$CRBMap@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@QEAAPEAU__POSITION@@IAEBV?$SmartPointer@VGameObject@@@efd@@@Z 0x141c1b570
// MS2-PIN: ?RightRotate@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c1a260
// MS2-PIN: ?SetNil@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141c1be60
#define NOMINMAX                                // interactobject.h includes NxPhysics.h
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/worldservice_tail.h"
#include "ms2/client/ms2/worldservice_real.h"
#include "ms2/client/ms2/dropitem.h"
#include "ms2/commonfiles/fieldproperty.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/placeholder/cboxcollision.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include <NiPlane.h>
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include <efd/MessageHandlerBase.h>
#include <efd/AssetLoadResponse.h>
#include <egf/EntityChangeMessage.h>
#include <egf/EntityLoaderMessages.h>
#include <egf/FlatModelFactoryResponse.h>
#include <ecr/CoreRuntimeMessages.h>
#include "ms2/placeholder/physxpropmessage.h"
#include <egmAnimation/ActorMessages.h>

namespace {
// The container operations of the WorldService methods (worldservice_1.cpp), per container kind.
template <class M> void WsDriveMap(M& m, const typename M::key_type& k)
{
    typename M::mapped_type v = typename M::mapped_type();
    m[k] = v;
    m.insert(typename M::value_type(k, v));
    typename M::iterator it = m.find(k);
    if (it != m.end())
        m.erase(it);
    m.erase(k);
    it = m.lower_bound(k);
    it = m.upper_bound(k);
    (void)m.count(k);
    for (it = m.begin(); it != m.end(); ++it) {}
    for (it = m.begin(); it != m.end(); it++) {}
    for (typename M::const_iterator ci = m.begin(); ci != m.end(); ++ci) {}
    const M& cm = m;
    typename M::const_iterator cf = cm.find(k);
    if (cf != cm.end() && cm.size() != 0) {}
    if (m.empty() || m.size() == 0)
        m.clear();
}
template <class S> void WsDriveSet(S& s, const typename S::key_type& k)
{
    s.insert(k);
    typename S::iterator it = s.find(k);
    if (it != s.end())
        s.erase(it);
    s.erase(k);
    (void)s.count(k);
    for (it = s.begin(); it != s.end(); ++it) {}
    const S& cs = s;
    if (cs.find(k) != cs.end()) {}
    if (s.empty() || s.size() == 0)
        s.clear();
}
template <class V> void WsDriveVec(V& v, const typename V::value_type& e)
{
    v.reserve(4);
    v.push_back(e);
    v.push_back(typename V::value_type(e));
    for (size_t i = 0; i < v.size(); ++i)
        (void)v[i];
    const V& cv = v;
    for (size_t i = 0; i < cv.size(); ++i)
        (void)cv[i];
    typename V::iterator last = v.end();
    if (!v.empty())
        v.erase(v.begin());
    if (!v.empty())
        v.clear();
}
template <class L> void WsDriveList(L& l, const typename L::value_type& e)
{
    l.push_back(e);
    l.push_front(e);
    for (typename L::iterator it = l.begin(); it != l.end(); ++it) {}
    const L& cl = l;
    for (typename L::const_iterator it = cl.begin(); it != cl.end(); ++it) {}
    if (!l.empty() && l.size() != 0) { (void)l.front(); l.pop_front(); }
    l.remove(e);
    l.clear();
}
}


template <class K> static K WsTailKey() { return K(); }
template <class M> static void WsTailAtl(M& m)
{
    typename std::remove_reference<typename M::KOUTARGTYPE>::type k = typename std::remove_reference<typename M::KOUTARGTYPE>::type();
    typename std::remove_reference<typename M::VOUTARGTYPE>::type v = typename std::remove_reference<typename M::VOUTARGTYPE>::type();
    m.SetAt(k, v);
    m.Lookup(k, v);
    m.Lookup(k);
    m.RemoveKey(k);
    POSITION pos = m.GetStartPosition();
    while (pos)
        m.GetNextAssoc(pos, k, v);
    pos = m.GetStartPosition();
    m.GetNext(pos);
    m.GetNextKey(pos);
    m.GetNextValue(pos);
    m.GetAt(pos);
    m.GetKeyAt(pos);
    m.GetValueAt(pos);
    m.GetCount();
    m.IsEmpty();
    m.RemoveAtPos(pos);
    m.RemoveAll();
}
template <class M> static void WsTailRB(M& m)
{
    typename std::remove_reference<typename M::KOUTARGTYPE>::type k = typename std::remove_reference<typename M::KOUTARGTYPE>::type();
    typename std::remove_reference<typename M::VOUTARGTYPE>::type v = typename std::remove_reference<typename M::VOUTARGTYPE>::type();
    m.SetAt(k, v);
    m.Lookup(k, v);
    m.Lookup(k);
    m.RemoveKey(k);
    POSITION pos = m.GetHeadPosition();
    while (pos)
        m.GetNextAssoc(pos, k, v);
    pos = m.GetHeadPosition();
    m.GetNext(pos);
    m.GetPrev(pos);
    m.GetNextKey(pos);
    m.GetNextValue(pos);
    m.GetAt(pos);
    m.GetKeyAt(pos);
    m.GetValueAt(pos);
    m.GetTailPosition();
    m.GetCount();
    m.IsEmpty();
    m.RemoveAt(pos);
    m.FindFirstKeyAfter(k);
    m.RemoveAll();
}
template <class M> static void WsTailRBMulti(M& m)
{
    typename std::remove_reference<typename M::KOUTARGTYPE>::type k = typename std::remove_reference<typename M::KOUTARGTYPE>::type();
    typename std::remove_reference<typename M::VOUTARGTYPE>::type v = typename std::remove_reference<typename M::VOUTARGTYPE>::type();
    m.Insert(k, v);
    POSITION pos = m.FindFirstWithKey(k);
    while (pos)
        m.GetNextValueWithKey(pos, k);
    m.RemoveKey(k);
    pos = m.GetHeadPosition();
    m.GetNext(pos);
    m.GetValueAt(pos);
    m.RemoveAt(pos);
    m.RemoveAll();
}
template <class E> static void WsTailAtlList(ATL::CAtlList<E>& l)
{
    
    l.AddTail(E());
    l.AddHead(E());
    POSITION pos = l.GetHeadPosition();
    while (pos)
        l.GetNext(pos);
    if (!l.IsEmpty())
        l.RemoveHead();
    if (!l.IsEmpty())
        l.RemoveTail();
    pos = l.GetHeadPosition();
    if (pos)
        l.RemoveAt(pos);
    (void)l.GetCount();
    l.RemoveAll();
}

void Unk_WsInst7(WorldService* w)
{

    egf::EntityID id;
    WsReal::Set048 s048;
    WsDriveSet(s048, (IWorldServiceCallback*)0);
    WsReal::List088 l088;
    WsDriveList(l088, (egf::Entity*)0);
    std::list<CDropItem*> ldrop;                        // FUN_141bd1ed0 / FUN_141bd2030 out lists
    ldrop.push_back((CDropItem*)0);
    std::set<WsReal::VisibleObjectRecord> svis;         // FUN_141bc7920 out set
    svis.insert(WsReal::VisibleObjectRecord());
    WsReal::Map1d8 m1d8;
    WsDriveMap(m1d8, id);
    WsReal::Map1e8 m1e8;
    WsDriveMap(m1e8, 1);
    WsDriveSet(m1e8[1], id);
    WsReal::Map1f8 m1f8;
    WsDriveMap(m1f8, 1);
    WsReal::Map2e8 m2e8;
    WsDriveMap(m2e8, id);
    WsReal::Map900 m900;
    WsDriveMap(m900, id);
    WsReal::Map980 m980;
    WsDriveMap(m980, id);
    WsReal::Map990 m990;
    WsDriveMap(m990, id);
    WsReal::Mapab0 mab0;
    WsDriveMap(mab0, id);
    WsReal::Mapac0 mac0;
    WsDriveMap(mac0, 1);
    WsReal::Mapad0 mad0;
    WsDriveMap(mad0, 1);
    WsReal::Vec9a0 v9a0;
    WsDriveVec(v9a0, MS2Ptr<MS2ActorUpdater>());
    WsReal::Veca00 va00;
    WsDriveVec(va00, std::pair<CStringA, CStringW>());
    WsReal::VecTextPair vtp;
    WsDriveVec(vtp, std::pair<CStringA, CStringA>());
    WsReal::Veca18 va18;
    WsDriveVec(va18, std::pair<CStringA, MS2Ptr<Unk_WsK_Rank> >());
    std::vector<efd::SmartPointer<egf::Entity> > vent;  // FUN_141bda490 out vector
    WsDriveVec(vent, efd::SmartPointer<egf::Entity>());
    std::vector<MS2Ptr<CLiftableObject> > vlift;        // FUN_141bc58d0 out vector
    WsDriveVec(vlift, MS2Ptr<CLiftableObject>());
    std::vector<MS2Ptr<CLiftableTargetBox> > vbox;      // FUN_141bc5980 out vector
    WsDriveVec(vbox, MS2Ptr<CLiftableTargetBox>());
    MS2Ptr<FieldProperty> fp;
    fp = 0;
    MS2Ptr<Unk_WsPtreda80> pa80;                        // m_a80
    pa80 = 0;
    MS2Ptr<WsReal::RecPtrA> pA;
    pA = 0;
    MS2Ptr<WsReal::RecPtrB> pB;
    pB = 0;
    Unk_WsOptional<float> opt;                          // m_a90
    opt.reset();

    Unk_WsF1 f1; WsTailRBMulti(f1);
    Unk_WsF2 f2; WsTailRBMulti(f2);
    Unk_WsF3 f3; WsTailRB(f3);
    Unk_WsF4 f4; WsTailRB(f4);
    Unk_WsF5 f5; WsTailRB(f5);
    Unk_WsF6 f6; WsTailRB(f6);
    Unk_WsF7 f7; WsTailRB(f7);
    Unk_WsF8 f8; WsTailRB(f8);
    Unk_WsF9 f9; WsTailRB(f9);
    Unk_WsF10 f10; WsTailRB(f10);
    Unk_WsF11 f11; WsTailRB(f11);
    Unk_WsF12 f12; WsTailRB(f12);
    Unk_WsF13 f13; WsTailRB(f13);
    Unk_WsF14 f14; WsTailRB(f14);
    Unk_WsF15 f15; WsTailRB(f15);
    Unk_WsF16 f16; WsTailRB(f16);
    Unk_WsF17 f17; WsTailRB(f17);
    Unk_WsM1 m1; WsTailAtl(m1);
    Unk_WsM2 m2; WsTailAtl(m2);
    Unk_WsM3 m3; WsTailAtl(m3);
    Unk_WsM4 m4; WsTailAtl(m4);
    Unk_WsM5 m5; WsTailAtl(m5);
    Unk_WsM6 m6; WsTailAtl(m6);
    Unk_WsM7 m7; WsTailAtl(m7);
    Unk_WsM8 m8; WsTailAtl(m8);
    Unk_WsM9 m9; WsTailAtl(m9);
    Unk_WsM10 m10; WsTailAtl(m10);
    Unk_WsM11 m11; WsTailAtl(m11);
    WsReal::Map738 m738; WsTailAtl(m738);
    WsReal::List058 l058; WsTailAtlList(l058);
    WsReal::List178 l178; WsTailAtlList(l178);
    ATL::CAtlArray<GameObject*> a0; a0.Add(0);         // CAtlArray::Add -> GrowBuffer -> RelocateElements 0x141c16070..
    ATL::CAtlArray<MS2Ptr<CInteractObject> > a1; a1.Add(MS2Ptr<CInteractObject>());
    ATL::CAtlArray<MS2Ptr<CPortal> > a2; a2.Add(MS2Ptr<CPortal>());
    ATL::CAtlArray<MS2Ptr<CBoxCollision> > parts;      // FUN_141bc12b0: GameObject parts
    parts.RemoveAll();                                  // 0x141c16130
    NiPlane plane;                                      // FUN_141bd2170
    plane.SetNormal(NiPoint3(0.0f, 0.0f, 1.0f));        // 0x141c1c2c0
    plane.SetConstant(0.0f);                            // 0x141c1bb10
    ((MS2ActorUpdater*)0)->FUN_141c1bb30(0.0f);         // OnTick
    ((COptimizer*)0)->FUN_141c1ca80(0);                 // FUN_141bcda90
    ((CEffectService*)0)->FUN_141c1caa0(0);
    Unk_BmBoxPtr<ATL::CAtlList<efd::SmartPointer<egf::Entity> > > box(Unk_BmNewTag(0));   // m_208 values (TPtredDummy 0x142fff040)
    Unk_BmBoxPtr<ATL::CAtlList<efd::SmartPointer<egf::Entity> > > box2(box);
    box2 = 0;
    void* pv = 0;
    const void* pcv = 0;
    w->WorldService::TypeCast(0, &pv);                  // 0x141c1ea60 / 0x141c1eab0 (EE_DECLARE_CLASS1)
    w->WorldService::TypeCast(0, &pcv);
    WorldService::SetupClassInfo(0, 0);                 // 0x141c1cac0
    MS2Ptr<WsReal::Rec1f8> p1f8;                        // AddRef 0x141c1f5c0 (pointee unidentified, see worldservice_real.h)
    MS2Ptr<WsReal::Rec1f8> q1f8(p1f8);
}

// The message handler instances registered by worldservice_1.cpp's EE_HANDLER statics (RegisterMessageFactory 0x141c14520 ..).
template class efd::MessageHandlerImpl<WorldService, egmAnimation::ActorAddedMessage>;
template class efd::MessageHandlerImpl<WorldService, egmAnimation::ActorRemovedMessage>;
template class efd::MessageHandlerImpl<WorldService, efd::AssetLoadResponse>;
template class efd::MessageHandlerImpl<WorldService, egf::EntityChangeMessage>;
template class efd::MessageHandlerImpl<WorldService, egf::EntityLoadResult>;
template class efd::MessageHandlerImpl<WorldService, ecrPhysX::PhysXPropMessage>;
template class efd::MessageHandlerImpl<WorldService, ecr::SceneGraphAddedMessage>;
template class efd::MessageHandlerImpl<WorldService, ecr::SceneGraphRemovedMessage>;
template class efd::MessageSubclassHandler<WorldService, efd::AssetLoadResponse, egf::FlatModelFactoryResponse>;
template class efd::MessageSubclassHandler<WorldService, egf::EntityChangeMessage, egf::EntityChangeMessage>;
template class efd::MessageSubclassHandler<WorldService, ecrPhysX::PhysXPropMessage, ecrPhysX::PhysXPropMessage>;
template class efd::MessageWrapperSubclassHandler<WorldService, egf::EntityChangeMessage, egf::EntityChangeMessage, 8196>;
template class efd::MessageWrapperSubclassHandler<WorldService, egf::EntityChangeMessage, egf::EntityChangeMessage, 8253>;
template class efd::MessageWrapperSubclassHandler<WorldService, egf::EntityChangeMessage, egf::EntityChangeMessage, 8254>;
template class efd::MessageWrapperSubclassHandler<WorldService, ecrPhysX::PhysXPropMessage, ecrPhysX::PhysXPropMessage, 12299>;
// MS2-FUNCTIONAL 0x141c17740: look-alike pairing of the Unk_WsTargetF7 stand-in map - the exe RemoveAt here calls RBDelete 0x141c0d660 (the Unk_WsObjectEntry tree's), ours the F7 tree's RBDelete; the real value type of this tree is not recovered
// MS2-FUNCTIONAL 0x141c1b490: look-alike pairing of the Unk_WsTargetF7 stand-in map - the exe SetAt here calls Find 0x141bfb9c0 + RBInsert 0x141c11fa0 (the CRBTree<int, MS2Ptr<CLiftableTargetGuide>> family), ours the F7 tree's; real value type not recovered
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$MS2Ptr@VRecad0@WsReal@@@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@2@XZ 0x141c20830
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@VVisibleObjectRecord@WsReal@@U?$less@VVisibleObjectRecord@WsReal@@@std@@V?$allocator@VVisibleObjectRecord@WsReal@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@VVisibleObjectRecord@WsReal@@PEAX@2@XZ 0x141c209f0
// MS2-PIN: ?_Calculate_growth@?$vector@V?$MS2Ptr@VCLiftableTargetBox@@@@V?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@@std@@AEBA_K_K@Z 0x141c20c80
//
//
//
//
// MS2-PIN: ?Rehash@?$CAtlMap@W4Unk_WsMapKey7@@V?$MS2Ptr@VUnk_WsMapV7@@@@V?$CElementTraits@W4Unk_WsMapKey7@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV7@@@@@4@@ATL@@QEAAXI@Z 0x141c15580
// MS2-PIN: ?RemoveAll@?$CAtlMap@_JV?$SmartPointer@VUnk_WsMapV8@@@efd@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$SmartPointer@VUnk_WsMapV8@@@efd@@@4@@ATL@@QEAAXXZ 0x141c169a0
// MS2-PIN: ?RemoveAll@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV9@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV9@@@@@3@@ATL@@QEAAXXZ 0x141c16ab0
//
//
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@W4Unk_WsMapKey7@@V?$MS2Ptr@VUnk_WsMapV7@@@@V?$CElementTraits@W4Unk_WsMapKey7@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV7@@@@@4@@ATL@@QEAAXMMM_N@Z 0x141c1c710
//
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@W4Unk_WsMapKey7@@V?$MS2Ptr@VUnk_WsMapV7@@@@V?$CElementTraits@W4Unk_WsMapKey7@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV7@@@@@4@@ATL@@AEAAXXZ 0x141c1f040
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IV?$SmartPointer@VEnt738@WsReal@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VEnt738@WsReal@@@efd@@@4@@ATL@@QEAAXMMM_N@Z 0x141c1c3a0
//
//
// MS2-PIN: ?RemoveAll@?$CAtlMap@HV?$MS2Ptr@VCPortal@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCPortal@@@@@3@@ATL@@QEAAXXZ 0x141c16230
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$SmartPointer@VEnt738@WsReal@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VEnt738@WsReal@@@efd@@@4@@ATL@@QEAAXI@Z 0x141c14a90
// MS2-PIN: ?RemoveAll@?$CAtlMap@IV?$SmartPointer@VEnt738@WsReal@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VEnt738@WsReal@@@efd@@@4@@ATL@@QEAAXXZ 0x141c16340
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IV?$SmartPointer@VEnt738@WsReal@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VEnt738@WsReal@@@efd@@@4@@ATL@@AEAAXXZ 0x141c1ebe0
// MS2-PIN: ?RemoveAll@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV3@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV3@@@@@3@@ATL@@QEAAXXZ 0x141c16450
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV3@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV3@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17bc0
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV3@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV3@@@@@3@@ATL@@QEAA_NI@Z 0x141c18510
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV3@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV3@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c18dd0
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV4@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV4@@@@@3@@ATL@@QEAAXI@Z 0x141c14ef0
// MS2-PIN: ?RemoveAll@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV4@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV4@@@@@3@@ATL@@QEAAXXZ 0x141c16560
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV4@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV4@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17cb0
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV4@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV4@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c18e90
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV4@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV4@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VUnk_WsMapV4@@@@@Z 0x141c1af10
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV4@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV4@@@@@3@@ATL@@QEAAXMMM_N@Z 0x141c1c500
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV4@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV4@@@@@3@@ATL@@AEAAXXZ 0x141c1eda0
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV6@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV6@@@@@3@@ATL@@QEAAXI@Z 0x141c15350
// MS2-PIN: ?RemoveAll@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV6@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV6@@@@@3@@ATL@@QEAAXXZ 0x141c16780
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV6@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV6@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c17e90
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV6@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV6@@@@@3@@ATL@@QEAA_NI@Z 0x141c185f0
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV6@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV6@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c19010
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV6@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV6@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VUnk_WsMapV6@@@@@Z 0x141c1b070
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV6@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV6@@@@@3@@ATL@@QEAAXMMM_N@Z 0x141c1c660
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IV?$MS2Ptr@VUnk_WsMapV6@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV6@@@@@3@@ATL@@AEAAXXZ 0x141c1ef60
// MS2-PIN: ?Rehash@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV10@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV10@@@@@3@@ATL@@QEAAXI@Z 0x141c15c10
// MS2-PIN: ?RemoveAll@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV10@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV10@@@@@3@@ATL@@QEAAXXZ 0x141c16bc0
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV10@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV10@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c18250
// MS2-PIN: ?RemoveKey@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV10@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV10@@@@@3@@ATL@@QEAA_N_J@Z 0x141c187b0
// MS2-PIN: ?RemoveNode@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV10@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV10@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c19310
// MS2-PIN: ?SetAt@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV10@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV10@@@@@3@@ATL@@QEAAPEAU__POSITION@@_JAEBV?$MS2Ptr@VUnk_WsMapV10@@@@@Z 0x141c1b330
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV10@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV10@@@@@3@@ATL@@QEAAXMMM_N@Z 0x141c1c920
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV10@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV10@@@@@3@@ATL@@AEAAXXZ 0x141c1f2e0
// MS2-PIN: ?Rehash@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV11@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV11@@@@@3@@ATL@@QEAAXI@Z 0x141c15e40
// MS2-PIN: ?RemoveAll@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV11@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV11@@@@@3@@ATL@@QEAAXXZ 0x141c16cd0
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV11@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV11@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141c18340
// MS2-PIN: ?RemoveKey@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV11@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV11@@@@@3@@ATL@@QEAA_N_J@Z 0x141c18820
// MS2-PIN: ?RemoveNode@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV11@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV11@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141c193d0
// MS2-PIN: ?SetAt@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV11@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV11@@@@@3@@ATL@@QEAAPEAU__POSITION@@_JAEBV?$MS2Ptr@VUnk_WsMapV11@@@@@Z 0x141c1b3e0
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV11@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV11@@@@@3@@ATL@@QEAAXMMM_N@Z 0x141c1c9d0
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@_JV?$MS2Ptr@VUnk_WsMapV11@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMapV11@@@@@3@@ATL@@AEAAXXZ 0x141c1f3c0
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@PEAVIWorldServiceCallback@@U?$less@PEAVIWorldServiceCallback@@@std@@V?$allocator@PEAVIWorldServiceCallback@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@PEAVIWorldServiceCallback@@PEAX@2@XZ 0x141c20910
