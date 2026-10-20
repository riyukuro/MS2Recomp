// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService.cpp COMDAT tail (ATL/STL container glue of the
// WorldService members, efd message handler / ClassFunHandler scalar deleting dtors, Notify* ??_G).
// MS2-UNIT: unit_141bf99b8
// MS2-RANGE: 0x141bf99b8-0x141c00000 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GUnk_WsVa18@@QEAAPEAXI@Z 0x141bf99d0 ; probe
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VActorAddedMessage@egmAnimation@@@efd@@UEAAPEAXI@Z 0x141bf9a50 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VActorRemovedMessage@egmAnimation@@@efd@@UEAAPEAXI@Z 0x141bf9a90 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VAssetLoadResponse@efd@@@efd@@UEAAPEAXI@Z 0x141bf9ad0 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VEntityChangeMessage@egf@@@efd@@UEAAPEAXI@Z 0x141bf9b10 ; order
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VEntityLoadResult@egf@@@efd@@UEAAPEAXI@Z 0x141bf9b50 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VPhysXPropMessage@ecrPhysX@@@efd@@UEAAPEAXI@Z 0x141bf9b90 ; order
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VSceneGraphAddedMessage@ecr@@@efd@@UEAAPEAXI@Z 0x141bf9bd0 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VSceneGraphRemovedMessage@ecr@@@efd@@UEAAPEAXI@Z 0x141bf9c10 ; prop
// MS2-PIN: ??_G?$MessageSubclassHandler@VWorldService@@VAssetLoadResponse@efd@@VFlatModelFactoryResponse@egf@@@efd@@UEAAPEAXI@Z 0x141bf9c50 ; prop
// MS2-PIN: ??_G?$MessageSubclassHandler@VWorldService@@VEntityChangeMessage@egf@@V23@@efd@@UEAAPEAXI@Z 0x141bf9c90 ; order
// MS2-PIN: ??_G?$MessageSubclassHandler@VWorldService@@VPhysXPropMessage@ecrPhysX@@V23@@efd@@UEAAPEAXI@Z 0x141bf9cd0 ; order
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VWorldService@@VEntityChangeMessage@egf@@V23@$0CAAE@@efd@@UEAAPEAXI@Z 0x141bf9d10 ; prop
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VWorldService@@VEntityChangeMessage@egf@@V23@$0CADN@@efd@@UEAAPEAXI@Z 0x141bf9d50 ; prop
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VWorldService@@VEntityChangeMessage@egf@@V23@$0CADO@@efd@@UEAAPEAXI@Z 0x141bf9d90 ; prop
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VWorldService@@VPhysXPropMessage@ecrPhysX@@V23@$0DAAL@@efd@@UEAAPEAXI@Z 0x141bf9dd0 ; prop
// MS2-PIN: ??_GUnk_WsVa00@@QEAAPEAXI@Z 0x141bf9e10 ; probe
// MS2-PIN: ??_GCNode@?$CAtlMap@IUUnk_W6V350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V350@@@3@@ATL@@QEAAPEAXI@Z 0x141bfa270 ; probe
// MS2-PIN: ??_GCNode@?$CAtlMap@IUUnk_W6V738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V738@@@3@@ATL@@QEAAPEAXI@Z 0x141bfa2b0 ; order
// MS2-PIN: ??_GCNode@?$CAtlMap@IUUnk_W6V3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V3a0@@@3@@ATL@@QEAAPEAXI@Z 0x141bfa2f0 ; probe
// MS2-PIN: ??_GCNode@?$CAtlMap@IUUnk_W6V780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V780@@@3@@ATL@@QEAAPEAXI@Z 0x141bfa330 ; probe
// MS2-PIN: ??_GCNode@?$CAtlMap@_KUUnk_W6V2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V2f8@@@3@@ATL@@QEAAPEAXI@Z 0x141bfa3b0 ; probe
// MS2-PIN: ??_GCNode@?$CAtlMap@_KUUnk_W6V420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V420@@@3@@ATL@@QEAAPEAXI@Z 0x141bfa3f0 ; probe
// MS2-PIN: ??_GCNode@?$CAtlMap@_KUUnk_W6V5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V5a0@@@3@@ATL@@QEAAPEAXI@Z 0x141bfa430 ; order
// MS2-PIN: ??_GCNode@?$CAtlMap@_KUUnk_W6V468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V468@@@3@@ATL@@QEAAPEAXI@Z 0x141bfa470 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@IUUnk_W6V350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V350@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x141bfaff0 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@IUUnk_W6V3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V3a0@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x141bfb070 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@IUUnk_W6V738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V738@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x141bfb0f0 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@IUUnk_W6V780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V780@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x141bfb170 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@_KUUnk_W6V2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V2f8@@@3@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141bfb2f0 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@_KUUnk_W6V420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V420@@@3@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141bfb370 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@_KUUnk_W6V468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V468@@@3@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141bfb3f0 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@_KUUnk_W6V5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V5a0@@@3@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141bfb470 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_W6V350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V350@@@3@@ATL@@QEAAXXZ 0x141bfb660 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_W6V3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V3a0@@@3@@ATL@@QEAAXXZ 0x141bfb680 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_W6V738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V738@@@3@@ATL@@QEAAXXZ 0x141bfb6a0 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_W6V780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V780@@@3@@ATL@@QEAAXXZ 0x141bfb6c0 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@QEAAXXZ 0x141bfb6e0 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV848@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV848@@@3@@ATL@@QEAAXXZ 0x141bfb700 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV930@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV930@@@3@@ATL@@QEAAXXZ 0x141bfb720 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KUUnk_W6V2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V2f8@@@3@@ATL@@QEAAXXZ 0x141bfb740 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KUUnk_W6V420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V420@@@3@@ATL@@QEAAXXZ 0x141bfb760 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KUUnk_W6V468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V468@@@3@@ATL@@QEAAXXZ 0x141bfb780 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KUUnk_W6V5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V5a0@@@3@@ATL@@QEAAXXZ 0x141bfb7a0 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_W6V350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V350@@@3@@ATL@@QEAAXXZ 0x141bfb860 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_W6V3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V3a0@@@3@@ATL@@QEAAXXZ 0x141bfb880 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_W6V738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V738@@@3@@ATL@@QEAAXXZ 0x141bfb8a0 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_W6V780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V780@@@3@@ATL@@QEAAXXZ 0x141bfb8c0 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@QEAAXXZ 0x141bfb8e0 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV848@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV848@@@3@@ATL@@QEAAXXZ 0x141bfb900 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV930@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV930@@@3@@ATL@@QEAAXXZ 0x141bfb920 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KUUnk_W6V2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V2f8@@@3@@ATL@@QEAAXXZ 0x141bfb940 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KUUnk_W6V420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V420@@@3@@ATL@@QEAAXXZ 0x141bfb960 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KUUnk_W6V468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V468@@@3@@ATL@@QEAAXXZ 0x141bfb980 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KUUnk_W6V5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V5a0@@@3@@ATL@@QEAAXXZ 0x141bfb9a0 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV5e8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV5e8@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfbe70 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV7c8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV7c8@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfbf60 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV4b0@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV4b0@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfc050 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV510@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV510@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfc140 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV678@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV678@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfc230 ; probe
// MS2-PIN: ?FindNextNode@?$CAtlMap@IUUnk_W6V3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V3a0@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfc5f0 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@IUUnk_W6V780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V780@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfc770 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfc830 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@IUUnk_WsV848@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV848@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfc8f0 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@IUUnk_WsV930@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV930@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfc9b0 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@_KUUnk_W6V2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V2f8@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfca70 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@_KUUnk_W6V420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V420@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfcb30 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@IUUnk_W6V350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V350@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfcd20 ; probe
// MS2-PIN: ?FreeNode@?$CAtlMap@IUUnk_W6V738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V738@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfce20 ; order
// MS2-PIN: ?FreeNode@?$CAtlMap@IUUnk_W6V3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V3a0@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfcf20 ; probe
// MS2-PIN: ?FreeNode@?$CAtlMap@IUUnk_W6V780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V780@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd020 ; probe
// MS2-PIN: ?FreeNode@?$CAtlMap@_KUUnk_W6V2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V2f8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd220 ; probe
// MS2-PIN: ?FreeNode@?$CAtlMap@_KUUnk_W6V420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V420@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd320 ; probe
// MS2-PIN: ?FreeNode@?$CAtlMap@_KUUnk_W6V5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V5a0@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd420 ; order
// MS2-PIN: ?FreeNode@?$CAtlMap@_KUUnk_W6V468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V468@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd520 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@HUUnk_WsV540@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_WsV540@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd820 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@HUUnk_WsV570@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_WsV570@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd8c0 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV1a8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV1a8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd960 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV0e8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV0e8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfda00 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV118@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV118@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdaa0 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV148@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV148@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdb40 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV708@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV708@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdbe0 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV5e8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV5e8@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdc80 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV4b0@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV4b0@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdd20 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV7c8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV7c8@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfddc0 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@_KUUnk_WsV0b8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV0b8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfde60 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV510@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV510@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdf00 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV678@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV678@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdfa0 ; order
// MS2-PIN: ?FreeNode@?$CRBTree@_KUUnk_WsV4e0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV4e0@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfe040 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@_KUUnk_WsV6a8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV6a8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfe0e0 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@_KUUnk_WsV6d8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV6d8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfe220 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_W6V350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V350@@@3@@ATL@@AEAAXXZ 0x141bfe2c0 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_W6V738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V738@@@3@@ATL@@AEAAXXZ 0x141bfe310 ; order
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_W6V3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V3a0@@@3@@ATL@@AEAAXXZ 0x141bfe360 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_W6V780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V780@@@3@@ATL@@AEAAXXZ 0x141bfe3b0 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@_KUUnk_W6V2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V2f8@@@3@@ATL@@AEAAXXZ 0x141bfe450 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@_KUUnk_W6V420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V420@@@3@@ATL@@AEAAXXZ 0x141bfe4a0 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@_KUUnk_W6V5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V5a0@@@3@@ATL@@AEAAXXZ 0x141bfe4f0 ; order
// MS2-PIN: ?FreePlexes@?$CAtlMap@_KUUnk_W6V468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V468@@@3@@ATL@@AEAAXXZ 0x141bfe540 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@IUUnk_WsV0e8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV0e8@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfeaf0 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV4b0@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV4b0@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfeb50 ; probe
// MS2-PIN: ?GetTailPosition@?$CRBTree@HUUnk_WsV540@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_WsV540@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfebb0 ; probe
// MS2-PIN: ?GetNext@?$CAtlMap@IUUnk_W6V3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V3a0@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141bfedb0 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@IUUnk_W6V738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V738@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141bfee00 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@IUUnk_W6V780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V780@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141bfee50 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141bfeea0 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@IUUnk_WsV848@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV848@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141bfeef0 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@IUUnk_WsV930@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV930@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141bfef40 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@_KUUnk_W6V420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V420@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141bfefe0 ; prop
// MS2-PIN: ?GetNextKey@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV7c8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV7c8@@@2@@ATL@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEAPEAU__POSITION@@@Z 0x141bff170 ; order
// MS2-PIN: ?GetNode@?$CAtlMap@IUUnk_W6V780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V780@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x141bff570 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x141bff660 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@IUUnk_W6V3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_W6V3a0@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x141bff750 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@IUUnk_WsV848@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV848@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x141bff840 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@_KUUnk_W6V2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V2f8@@@3@@ATL@@AEBAPEAVCNode@12@_KAEAI1AEAPEAV312@@Z 0x141bffb10 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@_KUUnk_W6V420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V420@@@3@@ATL@@AEBAPEAVCNode@12@_KAEAI1AEAPEAV312@@Z 0x141bffc00 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@_KUUnk_W6V468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_W6V468@@@3@@ATL@@AEBAPEAVCNode@12@_KAEAI1AEAPEAV312@@Z 0x141bffcf0 ; prop
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x141bffe10 ; order
// MS2-PINS-END tplpin
#define NOMINMAX                                // worldservice_tail.h -> interactobject.h -> NxPhysics.h
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/worldservice_tail.h"
#include "ms2/client/ms2/alphaanimation.h"
#include "ms2/client/ms2/ms2actorupdater.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/textureanimationdata.h"
#include "ms2/client/ms2/uidebugtooltip.h"
#include "ms2/placeholder/cinteractwebobject.h"
#include "ms2/placeholder/cdebughelper.h"
#include "ms2/placeholder/notifyworld.h"
#include <NiControllerManager.h>
#include <NiControllerSequence.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/tfunctor.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/coptimizer.h"
#include <efd/MessageService.h>
#include <efd/AssetLoadResponse.h>
#include <egf/EntityChangeMessage.h>
#include <egf/EntityLoaderMessages.h>
#include <egf/FlatModelFactoryResponse.h>
#include <ecr/CoreRuntimeMessages.h>
#include "ms2/placeholder/physxpropmessage.h"
#include <egmAnimation/ActorMessages.h>

// The container drivers of worldservice_inst.inl, copied: the CAtlMap value types whose destructors are not trivial in the exe
// (CAtlMap::FreeNode then calls the CNode scalar deleting dtor) are unit-local stand-ins with an out-of-line dtor.
template <class K> static K WsKey(int n) { return (K)n; }
template <> static CString WsKey<CString>(int) { return CString(); }
template <class T> static void WsConstruct(T& m) { new (&m) T(); }
template <class T> static void WsDestroy(T& m) { m.~T(); }
template <class K, class V, class KT, class VT> static void WsDriveAtl(ATL::CAtlMap<K, V, KT, VT>& m, int n)
{
    K k = WsKey<K>(n);
    V v = V();
    m.SetAt(k, v);
    m.Lookup(k, v);
    m.RemoveKey(k);
    m.RemoveAll();
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
    m.Lookup(k);
    m.GetCount();
    m.IsEmpty();
    m.RemoveAtPos(pos);
}
template <class K, class V, class KT, class VT> static void WsDriveRB(ATL::CRBMap<K, V, KT, VT>& m, int n)
{
    K k = WsKey<K>(n);
    V v = V();
    m.SetAt(k, v);
    m.Lookup(k, v);
    m.RemoveKey(k);
    m.RemoveAll();
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
    m.Lookup(k);
    m.GetCount();
    m.IsEmpty();
    m.RemoveAt(pos);
    m.FindFirstKeyAfter(k);
}
template <class M> static void WsDriveStd(M& m, typename M::key_type k)
{
    typename M::mapped_type v = typename M::mapped_type();
    m[k] = v;
    m.insert(std::make_pair(k, v));
    typename M::iterator it = m.find(k);
    if (it != m.end())
        m.erase(it);
    m.erase(k);
    m.clear();
    for (it = m.begin(); it != m.end(); ++it) {}
}

struct Unk_W6V350 { ~Unk_W6V350(); void* p0; void* p1; };   // dtor 0x140964a70
struct Unk_W6V738 { ~Unk_W6V738(); void* p; };               // dtor 0x141bf54a0
struct Unk_W6V3a0 { ~Unk_W6V3a0(); void* p0; void* p1; };   // dtor 0x141746770
struct Unk_W6V780 { ~Unk_W6V780(); void* p0; void* p1; };   // dtor 0x141bf5630
struct Unk_W6V5a0 { ~Unk_W6V5a0(); void* p; };               // dtor 0x1410a6c00
struct Unk_W6V420 { ~Unk_W6V420(); void* p0; void* p1; };   // dtor 0x140a00490
struct Unk_W6V2f8 { ~Unk_W6V2f8(); void* p0; void* p1; };   // dtor 0x14123ebe0
struct Unk_W6V468 { ~Unk_W6V468(); void* p0; void* p1; };   // dtor 0x1410b4290
struct Unk_W6Access : WorldService { Unk_W6Access(); static void Del(WorldService* w) { static_cast<Unk_W6Access*>(w)->WorldService::DeleteThis(); } };   // reaches the protected DeleteThis
void Unk_WsInst6(WorldService* w)
{
    WsDriveAtl(w->m_208, 1);
    WsDriveAtl(w->m_848, 1);
    WsDriveAtl(w->m_930, 1);
    ATL::CAtlMap<unsigned, Unk_W6V350> m350; WsDriveAtl(m350, 1);
    ATL::CAtlMap<unsigned, Unk_W6V738> m738; WsDriveAtl(m738, 1);
    ATL::CAtlMap<unsigned, Unk_W6V3a0> m3a0; WsDriveAtl(m3a0, 1);
    ATL::CAtlMap<unsigned, Unk_W6V780> m780; WsDriveAtl(m780, 1);
    ATL::CAtlMap<unsigned __int64, Unk_W6V5a0> m5a0; WsDriveAtl(m5a0, 1);
    ATL::CAtlMap<unsigned __int64, Unk_W6V420> m420; WsDriveAtl(m420, 1);
    ATL::CAtlMap<unsigned __int64, Unk_W6V2f8> m2f8; WsDriveAtl(m2f8, 1);
    ATL::CAtlMap<unsigned __int64, Unk_W6V468> m468; WsDriveAtl(m468, 1);
    WsDriveStd(w->m_1d8, 1);
    WsDriveStd(w->m_2e8, 1);
    WsDriveStd(w->m_ac0, 1);
    WsDriveStd(w->m_ad0, 1);
    WsDriveStd(w->m_1f8, 1);
    WsDriveStd(w->m_980, 1);
    WsDriveStd(w->m_990, 1);
    WsDriveStd(w->m_ab0, 1);
    WsDriveRB(w->m_0b8, 1);
    WsDriveRB(w->m_0e8, 1);
    WsDriveRB(w->m_118, 1);
    WsDriveRB(w->m_148, 1);
    WsDriveRB(w->m_1a8, 1);
    WsDriveRB(w->m_4e0, 1);
    WsDriveRB(w->m_540, 1);
    WsDriveRB(w->m_570, 1);
    WsDriveRB(w->m_6a8, 1);
    WsDriveRB(w->m_6d8, 1);
    WsDriveRB(w->m_708, 1);
    WsDriveRB(w->m_4b0, 1);
    WsDriveRB(w->m_510, 1);
    WsDriveRB(w->m_678, 1);
    WsDriveRB(w->m_5e8, 1);
    WsDriveRB(w->m_618, 1);
    WsDriveRB(w->m_7c8, 1);
    w->m_1e8[1].insert(2);
    TFunctor<void, EmptyParam> fnWs(w, &WorldService::FUN_141bc1640);
    COptimizer* pOptimizer = 0;
    TFunctor<void, EmptyParam> fnOpt(pOptimizer, reinterpret_cast<void (COptimizer::*)()>(&COptimizer::FUN_1414a5a30));
    delete new NotifyChangeServer;
    delete new NotifyCreateMyPC;
    delete new NotifyGameStart;
    delete new NotifyRemoveGameObject(0);
    // inline virtuals of the class macros, emitted here as COMDATs
    w->WorldService::DecRefCount();
    Unk_W6Access::Del(w);
    w->WorldService::GetClassDesc();
    w->WorldService::GetRefCount();
    WsConstruct(w->m_1d8);
    WsDestroy(w->m_1d8);
    WsConstruct(w->m_2e8);
    WsDestroy(w->m_2e8);
    WsConstruct(w->m_ac0);
    WsDestroy(w->m_ac0);
    WsConstruct(w->m_ad0);
    WsDestroy(w->m_ad0);
    WsConstruct(w->m_1f8);
    WsDestroy(w->m_1f8);
    WsConstruct(w->m_980);
    WsDestroy(w->m_980);
    WsConstruct(w->m_990);
    WsDestroy(w->m_990);
    WsConstruct(w->m_ab0);
    WsDestroy(w->m_ab0);
    WsConstruct(w->m_208);
    WsDestroy(w->m_208);
    WsConstruct(w->m_848);
    WsDestroy(w->m_848);
    WsConstruct(w->m_930);
    WsDestroy(w->m_930);
    WsConstruct(m738);
    WsDestroy(m738);
    WsConstruct(m2f8);
    WsDestroy(m2f8);
    WsConstruct(m420);
    WsDestroy(m420);
    WsConstruct(m468);
    WsDestroy(m468);
    WsConstruct(m5a0);
    WsDestroy(m5a0);
    WsConstruct(w->m_0b8);
    WsDestroy(w->m_0b8);
    WsConstruct(w->m_0e8);
    WsDestroy(w->m_0e8);
    WsConstruct(w->m_118);
    WsDestroy(w->m_118);
    WsConstruct(w->m_148);
    WsDestroy(w->m_148);
    WsConstruct(w->m_1a8);
    WsDestroy(w->m_1a8);
    WsConstruct(w->m_4e0);
    WsDestroy(w->m_4e0);
    WsConstruct(w->m_540);
    WsDestroy(w->m_540);
    WsConstruct(w->m_570);
    WsDestroy(w->m_570);
    WsConstruct(w->m_6a8);
    WsDestroy(w->m_6a8);
    WsConstruct(w->m_6d8);
    WsDestroy(w->m_6d8);
    WsConstruct(w->m_708);
    WsDestroy(w->m_708);
    WsConstruct(w->m_4b0);
    WsDestroy(w->m_4b0);
    WsConstruct(w->m_510);
    WsDestroy(w->m_510);
    WsConstruct(w->m_678);
    WsDestroy(w->m_678);
    WsConstruct(w->m_5e8);
    WsDestroy(w->m_5e8);
    WsConstruct(w->m_618);
    WsDestroy(w->m_618);
    WsConstruct(w->m_7c8);
    WsDestroy(w->m_7c8);
    WsConstruct(w->m_1e8);
    WsDestroy(w->m_1e8);
    WsConstruct(w->m_058);
    WsDestroy(w->m_058);
    WsConstruct(w->m_9a0);
    WsDestroy(w->m_9a0);
    WsConstruct(w->m_a00);
    WsDestroy(w->m_a00);
    WsConstruct(w->m_a18);
    WsDestroy(w->m_a18);
}

// The compiler-generated WorldService scalar deleting dtor and its TSingleton<WorldService> thunk. MSVC emits them with
// WorldService's vftables in the TU that defines its ctor (worldservice_1.cpp), so they are written out here.
// @0x141bfaad0
// MS2-FUNCTIONAL: ??_GWorldService (efd::MemObject sized delete unless bit 4 asks for the global one)
void* Unk_WsScalarDeletingDtor(WorldService* pService, unsigned int nFlags)
{
    pService->WorldService::~WorldService();
    if (nFlags & 1)
    {
        if ((nFlags & 4) == 0)
            efd::MemObject::operator delete(pService, sizeof(WorldService));
        else
            ::operator delete(pService, sizeof(WorldService));
    }
    return pService;
}
// @0x141bf99b8
// MS2-FUNCTIONAL: the vftable 0x142ffec20 thunk (this - 0x18) into ??_GWorldService
void* Unk_WsSingletonDeletingDtor(TSingleton<WorldService>* pSingleton, unsigned int nFlags)
{
    return Unk_WsScalarDeletingDtor(static_cast<WorldService*>(pSingleton), nFlags);
}

// The camera's entity id value. Inline in the original, its COMDAT reads the including TU's copy of the header static
// egf::kENTITY_INVALID (worldservice.cpp's is 0x143af8278).
extern egf::EntityID DAT_143af8278;
// @0x141bfe700
unsigned __int64 Camera::FUN_141bfe700()
{
    return m_10 != NULL ? m_10->GetEntityIDValue() : DAT_143af8278.GetValue();
}

// The rest of the tail over the recovered types (worldservice_tail.h, the std members, the classes WorldService creates).
void Unk_WsInst6Tail(PC& pc, CEntityShower& shower, MS2ActorUpdater& updater, CameraMgr& camera, NiControllerManager& manager,
    NiControllerSequence& sequence, const NiFixedString& name)
{
    // std::pair<const K, V> scalar deleting dtors (node / element destruction)
    { std::map<int, efd::SmartPointer<egf::Entity> > m; m.clear(); }                       // m_ac0
    { std::map<egf::EntityID, efd::SmartPointer<CEntityHider> > m; m.clear(); }            // m_990
    { std::map<egf::EntityID, efd::SmartPointer<CEntityShower> > m; m.clear(); }           // m_980
    { std::map<egf::EntityID, efd::SmartPointer<egf::Entity> > m; m.clear(); }             // m_2e8
    { std::map<__int64, MS2Ptr<UIDebugTooltip> > m; m.clear(); }                           // m_ad0
    { std::vector<std::pair<CStringA, CStringA> > v; v.clear(); }                          // FUN_141bdb1b0's local
    { std::vector<std::pair<CStringA, CStringW> > v; v.clear(); }                          // m_a00
    { std::vector<std::pair<CStringA, MS2Ptr<Unk_WsK_Rank> > > v; v.clear(); }             // m_a18
    // classes WorldService creates: their implicit ctors emit the vftables and the scalar deleting dtors
    { egmAnimation::ActorRemovedMessage msg; }
    delete new CInteractWebObject();
    delete new CLiftableTargetBox();
    delete new CLiftableTargetGuide();
    NiNew TextureLayerManager();
    delete new TSingleton<WorldService>();
    // CAtlMap: FreeNode -> CNode scalar deleting dtor; CreateNode / GetNode of the enum-keyed map
    { Unk_WsM5 m; m.RemoveKey(0); }
    { Unk_WsM10 m; m.RemoveKey(0); }
    { Unk_WsM11 m; m.RemoveKey(0); }
    { Unk_WsM7 m; m.SetAt(Unk_WsMapKey7(), MS2Ptr<Unk_WsMapV7>()); m.Lookup(Unk_WsMapKey7()); }
    // CRBTree: Find, FreeNode -> CNode scalar deleting dtor
    { Unk_WsF8 m; m.Lookup(0); m.RemoveKey(0); }
    { Unk_WsF9 m; m.Lookup(0); m.RemoveKey(0); }
    { Unk_WsF10 m; m.Lookup(CStringA()); m.RemoveKey(CStringA()); }
    { Unk_WsF13 m; m.Lookup(CStringA()); m.RemoveKey(CStringA()); }
    { Unk_WsF15 m; m.Lookup(egf::EntityID()); m.RemoveKey(egf::EntityID()); }
    { Unk_WsF16 m; m.Lookup(Unk_WsKindKey()); m.RemoveKey(Unk_WsKindKey()); }
    // CAtlArray::Add, CAtlList::AddTail (-> NewNode -> GetFreeNode), CAtlArray<void*>::CallDestructors
    { ATL::CAtlArray<GameObject*> a; a.Add(0); }
    { ATL::CAtlArray<MS2Ptr<CInteractObject> > a; a.Add(MS2Ptr<CInteractObject>()); }
    { ATL::CAtlArray<MS2Ptr<CPortal> > a; a.Add(MS2Ptr<CPortal>()); }
    { Unk_WsL1 l; l.AddTail(NiPointer<Unk_WsProp058>()); }
    { Unk_WsL2 l; l.AddTail(efd::SmartPointer<GameObject>()); }
    { Unk_WsL3 l; l.AddTail(efd::SmartPointer<PC>()); }
    { ATL::CAtlArray<void*> a; }
    // the debug helper singleton (created / destroyed by WorldService 0x141bcb370 / 0x141bcd5a0)
    TSingleton<CDebugHelper>::CreateInstance();
    TSingleton<CDebugHelper>::DestroyInstance();
    // inline getters
    pc.FUN_141bfaec0(true);
    pc.FUN_141bfed80();
    shower.GetAlpha();
    shower.GetEntityID();
    updater.FUN_141bfe6d0();
    camera.FUN_141bfe750();
    manager.GetSequenceByName(name);
    sequence.GetLastScaledTime();
}

#ifndef MS2_HOOK_DLL  // MS2: instantiates the handler classes (and their scalar deleting dtors) whose COMDATs sit in this tail; the same
// statics live in worldservice_1.cpp (.text$di 0x140120290), so the hook DLL must not register a second set.
EE_HANDLER_WRAP(WorldService, FUN_141bc0530, ecrPhysX::PhysXPropMessage, 12299);
EE_HANDLER_WRAP(WorldService, FUN_141bbd640, egf::EntityChangeMessage, 8253);
EE_HANDLER_WRAP(WorldService, FUN_141bbf2f0, egf::EntityChangeMessage, 8254);
EE_HANDLER_WRAP(WorldService, FUN_141bbfa50, egf::EntityChangeMessage, 8196);
EE_HANDLER(WorldService, FUN_141bbf9f0, efd::AssetLoadResponse);
EE_HANDLER_SUBCLASS(WorldService, FUN_141bc0f50, efd::AssetLoadResponse, egf::FlatModelFactoryResponse);
EE_HANDLER(WorldService, FUN_141bbfb50, egmAnimation::ActorAddedMessage);
EE_HANDLER(WorldService, FUN_141bbfde0, egmAnimation::ActorRemovedMessage);
EE_HANDLER(WorldService, FUN_141bc0a70, egf::EntityLoadResult);
EE_HANDLER(WorldService, FUN_141bbfe30, ecr::SceneGraphAddedMessage);
EE_HANDLER(WorldService, FUN_141bc0290, ecr::SceneGraphRemovedMessage);
#endif
