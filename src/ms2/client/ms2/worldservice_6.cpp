// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService COMDAT tail, sub-unit #6 (w530): the sorted
// ATL member COMDATs CAtlMap/CRBTree ::GetAt .. ::RemoveAt (plus MessageHandlerImpl::HandleMessage, WorldService::IncRefCount)
// of the CU's members. 0x141bfe180-0x141c00000 (the old start of #6) belongs to unit_141bf99b8.
// MS2-UNIT: ?\worldservice.cpp#6
// MS2-RANGE: 0x141c00000-0x141c0e080 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GrowBuffer@?$CAtlArray@PEAVGameObject@@V?$CElementTraits@PEAVGameObject@@@ATL@@@ATL@@AEAA_N_K@Z 0x141c00aa0 ; unique
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VWorldService@@VActorAddedMessage@egmAnimation@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x141c00f80 ; unique
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VWorldService@@VActorRemovedMessage@egmAnimation@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x141c013c0 ; unique
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VWorldService@@VAssetLoadResponse@efd@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x141c01800 ; unique
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VWorldService@@VEntityChangeMessage@egf@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x141c01c40 ; unique
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VWorldService@@VEntityLoadResult@egf@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x141c02080 ; unique
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VWorldService@@VPhysXPropMessage@ecrPhysX@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x141c024c0 ; unique
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VWorldService@@VSceneGraphAddedMessage@ecr@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x141c02900 ; unique
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VWorldService@@VSceneGraphRemovedMessage@ecr@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x141c02d40 ; unique
// MS2-PIN: ?IncRefCount@WorldService@@UEBAXXZ 0x141c03190 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetBox@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetBox@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$MS2Ptr@VCLiftableTargetBox@@@@@Z 0x141c03e70 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$MS2Ptr@VCLiftableTargetGuide@@@@@Z 0x141c03f70 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@AEAAPEAVCNode@12@IAEBUUnk_WsObjectEntry@@@Z 0x141c04070 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@AEAAPEAVCNode@12@IAEBV?$SmartPointer@VGameObject@@@efd@@@Z 0x141c04270 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@AEAAPEAVCNode@12@IAEBV?$MS2Ptr@VUnk_WsTargetF7@@@@@Z 0x141c04470 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@AEAAPEAVCNode@12@AEBQEAVEntity@egf@@0@Z 0x141c04570 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@AEAAPEAVCNode@12@AEBQEAVEntity@egf@@AEBV?$MS2Ptr@VUnk_WsMarker@@@@@Z 0x141c04670 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VCReactor@@@efd@@@Z 0x141c04770 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x141c04870 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VCInteractObject@@@@@Z 0x141c04970 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VCLiftableObject@@@@@Z 0x141c04a70 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VUnk_WsMarker@@@@@Z 0x141c04b70 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@AEAAPEAVCNode@12@AEBVEntityID@egf@@AEBV?$MS2Ptr@VCInteractObject@@@@@Z 0x141c04c70 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@W4Unk_WsKindKey@@HV?$CElementTraits@W4Unk_WsKindKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEAAPEAVCNode@12@AEBW4Unk_WsKindKey@@H@Z 0x141c04d70 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@_KV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@AEAAPEAVCNode@12@_KAEBV?$SmartPointer@VGameObject@@@efd@@@Z 0x141c04e70 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetBox@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetBox@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c05850 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c05960 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c05a70 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c05c90 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c05eb0 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c05fc0 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c060d0 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c061e0 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c062f0 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c06400 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c06510 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c06620 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141c06730 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEBA_NIAEAV?$MS2Ptr@VCProxyGameObject@@@@@Z 0x141c06bf0 ; prop
// MS2-PIN: ?Lookup@?$CRBMap@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@QEBA_NIAEAV?$SmartPointer@VGameObject@@@efd@@@Z 0x141c06fa0 ; prop
// MS2-PIN: ?Lookup@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@QEBA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEAV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x141c071c0 ; prop
// MS2-PIN: ?Lookup@?$CRBMap@_KV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@QEBA_N_KAEAV?$SmartPointer@VGameObject@@@efd@@@Z 0x141c07410 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c074d0 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07540 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c075b0 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07620 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@IV?$SmartPointer@VCNpc@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VCNpc@@@efd@@@4@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07690 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07700 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07770 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c077e0 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07850 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c078c0 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetBox@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetBox@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07a10 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07a80 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07af0 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07b60 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07bd0 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07cb0 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07d20 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07d90 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07e00 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07e70 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c07ee0 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetBox@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetBox@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$MS2Ptr@VCLiftableTargetBox@@@@@Z 0x141c09920 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@HV?$MS2Ptr@VCLiftableTargetGuide@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLiftableTargetGuide@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$MS2Ptr@VCLiftableTargetGuide@@@@@Z 0x141c09b80 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@AEAAPEAVCNode@12@IAEBUUnk_WsObjectEntry@@@Z 0x141c09de0 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@AEAAPEAVCNode@12@IAEBV?$SmartPointer@VGameObject@@@efd@@@Z 0x141c0a2a0 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@AEAAPEAVCNode@12@IAEBV?$MS2Ptr@VUnk_WsTargetF7@@@@@Z 0x141c0a760 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@AEAAPEAVCNode@12@AEBQEAVEntity@egf@@0@Z 0x141c0a9c0 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@AEAAPEAVCNode@12@AEBQEAVEntity@egf@@AEBV?$MS2Ptr@VUnk_WsMarker@@@@@Z 0x141c0ac20 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VCReactor@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VCReactor@@@efd@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VCReactor@@@efd@@@Z 0x141c0ae80 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x141c0b0e0 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VCInteractObject@@@@@Z 0x141c0b340 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VCLiftableObject@@@@@Z 0x141c0b5a0 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VUnk_WsMarker@@@@@Z 0x141c0b800 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@AEAAPEAVCNode@12@AEBVEntityID@egf@@AEBV?$MS2Ptr@VCInteractObject@@@@@Z 0x141c0ba60 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@IUUnk_WsObjectEntry@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsObjectEntry@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c0cbd0 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c0cca0 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@IV?$MS2Ptr@VUnk_WsTargetF7@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsTargetF7@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c0cd70 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c0ce40 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c0cf10 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c0d0b0 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c0d180 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCLiftableObject@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCLiftableObject@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c0d250 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@VEntityID@egf@@V?$MS2Ptr@VCInteractObject@@@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VCInteractObject@@@@@5@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141c0d3f0 ; prop
// MS2-PIN: ?RBDelete@?$CRBTree@IV?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@4@@ATL@@AEAA_NPEAVCNode@12@@Z 0x141c0d9c0 ; prop
// MS2-PIN: ?RBDelete@?$CRBTree@PEAVEntity@egf@@PEAV12@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V34@@ATL@@AEAA_NPEAVCNode@12@@Z 0x141c0dd20 ; prop
// MS2-PIN: ?RBDelete@?$CRBTree@PEAVEntity@egf@@V?$MS2Ptr@VUnk_WsMarker@@@@V?$CElementTraits@PEAVEntity@egf@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_WsMarker@@@@@5@@ATL@@AEAA_NPEAVCNode@12@@Z 0x141c0ded0 ; prop
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define NOMINMAX                                // interactobject.h includes NxPhysics.h
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/worldservice_tail.h"
#include "ms2/placeholder/cinteractobjectdata.h"
#include "ms2/placeholder/cinteractwebobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <efd/MessageHandlerBase.h>
#include <efd/AssetLoadResponse.h>
#include <egf/EntityChangeMessage.h>
#include <egf/EntityLoaderMessages.h>
#include <ecr/CoreRuntimeMessages.h>
#include "ms2/placeholder/physxpropmessage.h"
#include <egmAnimation/ActorMessages.h>

// The container member functions of the tail, driven over the recovered types of worldservice_tail.h.
template <class K> static K WsTailKey() { return K(); }
template <class K, class V, class KT, class VT> static void WsTailAtl(ATL::CAtlMap<K, V, KT, VT>& m)
{
    K k = WsTailKey<K>();
    V v = V();
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
template <class K, class V, class KT, class VT> static void WsTailRB(ATL::CRBMap<K, V, KT, VT>& m)
{
    K k = WsTailKey<K>();
    V v = V();
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
template <class K, class V, class KT, class VT> static void WsTailRBMulti(ATL::CRBMultiMap<K, V, KT, VT>& m)
{
    K k = WsTailKey<K>();
    V v = V();
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
void Unk_WsTail6(WorldService* w)
{
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
    Unk_WsM12 m12; m12.SetAt(0, efd::SmartPointer<Unk_WsMover>());   // m_738: NewNode 0x141c08480
    // CAtlArray::Add -> GrowBuffer (0x141c00aa0 / 0x141c00c40 / 0x141c00de0): FUN_141bd28d0, FUN_141bc5f10, FUN_141bc2a70
    ATL::CAtlArray<GameObject*> a0; a0.Add(0);
    ATL::CAtlArray<MS2Ptr<CInteractObject> > a1; a1.Add(MS2Ptr<CInteractObject>());
    ATL::CAtlArray<MS2Ptr<CPortal> > a2; a2.Add(MS2Ptr<CPortal>());
    w->WorldService::IncRefCount();                      // 0x141c03190 (EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT)
    // CAtlList::AddTail -> NewNode (0x141c08030 / 0x141c080f0 / 0x141c081b0)
    Unk_WsL1 l1; l1.AddTail(NiPointer<Unk_WsProp058>());
    Unk_WsL2 l2; l2.AddTail(efd::SmartPointer<GameObject>());
    Unk_WsL3 l3; l3.AddTail(efd::SmartPointer<PC>());
}

// The inline getters WorldService's methods call (their COMDATs land in this CU's tail).
void Unk_WsTail6Getters(PC& pc, CInteractObject& obj, CInteractObjectData& def, CInteractWebObject& web,
    Unk_WsProxyMgr& proxies)
{
    pc.FUN_141c04f70();
    obj.FUN_141c04fc0();
    def.FUN_141c05790();
    def.FUN_141c057c0();
    def.FUN_141c05820();
    def.FUN_141c04f90();
    def.FUN_141c051c0();
    def.FUN_141c057f0();
    web.CInteractWebObject::vfunc_5();
    proxies.FUN_141c05780();
}

// The message handler instances registered by worldservice_1.cpp's EE_HANDLER statics (HandleMessage 0x141c00f80 ..).
template class efd::MessageHandlerImpl<WorldService, egmAnimation::ActorAddedMessage>;
template class efd::MessageHandlerImpl<WorldService, egmAnimation::ActorRemovedMessage>;
template class efd::MessageHandlerImpl<WorldService, efd::AssetLoadResponse>;
template class efd::MessageHandlerImpl<WorldService, egf::EntityChangeMessage>;
template class efd::MessageHandlerImpl<WorldService, egf::EntityLoadResult>;
template class efd::MessageHandlerImpl<WorldService, ecrPhysX::PhysXPropMessage>;
template class efd::MessageHandlerImpl<WorldService, ecr::SceneGraphAddedMessage>;
template class efd::MessageHandlerImpl<WorldService, ecr::SceneGraphRemovedMessage>;
