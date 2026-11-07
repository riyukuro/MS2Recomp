// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CEquipModel: abstract base of the client's loaded models
// (CNifModel, CKfmModel). Holds the owner (a character / mannequin entity wrapper), the loaded scene root (+0xf0), the
// set of attached scene objects (+0xf8), the attach node (+0x108), the effect-slot map (+0x78) and the visible-part
// name map (+0xc0), plus the part-attach helpers shared by both model kinds.
// MS2-UNIT: ?\equipmodel.cpp
// MS2-RANGE: 0x1411ffa10-0x141209610 .text$mn
// MS2-RANGE: 0x1400e8820-0x1400e8840 .text$di
// MS2-RANGE: 0x1400e8b40-0x1400e8e70 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Buy_if_not_node@AEBV?$SmartPointer@VNiAVObject@@@efd@@@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@1@U_Not_a_node_tag@1@AEBV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x141204270 ; unique
// MS2-PIN: ??$_Buynode@AEBV?$SmartPointer@VNiAVObject@@@efd@@@?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@1@AEBV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x141204330 ; unique
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x1412043c0 ; unique
// MS2-PIN: ??$_Copy_nodes@U_Copy_tag@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@1@PEAU21@0U_Copy_tag@01@@Z 0x1412044e0 ; unique
// MS2-PIN: ??$_Insert_at@AEBV?$SmartPointer@VNiAVObject@@@efd@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@1@_NPEAU?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@1@AEBV?$SmartPointer@VNiAVObject@@@efd@@U_Not_a_node_tag@1@@Z 0x1412046b0 ; unique
// MS2-PIN: ??$_Insert_nohint@AEBV?$SmartPointer@VNiAVObject@@@efd@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@std@@_N@1@_NAEBV?$SmartPointer@VNiAVObject@@@efd@@U_Not_a_node_tag@1@@Z 0x141204a10 ; unique
// MS2-PIN: ??$construct@V?$SmartPointer@VNiAVObject@@@efd@@AEBV12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@std@@@1@QEAV?$SmartPointer@VNiAVObject@@@efd@@AEBV34@@Z 0x141204f40 ; unique
// MS2-PIN: ??0?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEAA@_K@Z 0x141205170 ; unique
// MS2-PIN: ??0CNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAA@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@H@Z 0x141205390 ; unique
// MS2-PIN: ??0CPair@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEAA@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@H@Z 0x141205400 ; unique
// MS2-PIN: ??1?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x141205470 ; unique
// MS2-PIN: ??1?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x141205490 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAA@XZ 0x141205500 ; unique
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141205a80 ; unique
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141205d20 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@H@Z 0x141206330 ; unique
// MS2-PIN: ?IsNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEBA_NPEAVCNode@12@@Z 0x1412064c0 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141206500 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAAPEAVCPair@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141206670 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEBA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEAH@Z 0x1412066a0 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1412066f0 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141206760 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@H@Z 0x1412069e0 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141206d30 ; unique
// MS2-PIN: ?RBDelete@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAA_NPEAVCNode@12@@Z 0x141206e00 ; unique
// MS2-PIN: ?RBDeleteFixup@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141206fb0 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEAAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@H@Z 0x1412072e0 ; unique
// MS2-PIN: ?RemoveAll@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x1412078a0 ; unique
// MS2-PIN: ?RemoveAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141207920 ; prop
// MS2-PIN: ?RemoveKey@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141207ab0 ; unique
// MS2-PIN: ?RemovePostOrder@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141207bc0 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x141207c20 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@H@Z 0x141207dc0 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x141207e20 ; unique
// MS2-PIN: ?Successor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141208050 ; unique
// MS2-PIN: ?SwapNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141208120 ; unique
// MS2-PIN: ?TypeCast@CEquipModel@@UEBA_NIPEAPEAX@Z 0x141208280 ; unique
// MS2-PIN: ?TypeCast@CEquipModel@@UEBA_NIPEAPEBX@Z 0x1412082d0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@2@XZ 0x1412084d0 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAAXXZ 0x1412085c0 ; unique
// MS2-PIN: ?_Copy_alloc@?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAAXAEBV?$allocator@U?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@std@@@2@@Z 0x1412085f0 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@2@@Z 0x141208cf0 ; order
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@2@@Z 0x141208d20 ; order
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@std@@@2@XZ 0x141208e10 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@IEAAXXZ 0x141209110 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@XZ 0x141209190 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAAXXZ 0x141209260 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@XZ 0x141209360 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@V32@0@Z 0x141209420 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@V32@@Z 0x141209510 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEBA_KXZ 0x1412095f0 ; unique
// MS2-PINS-END tplpin
// MS2-FUNCTIONAL: extern-heavy; engine/game helpers are opaque void* FUN_ externs (see nifmodel.cpp / kfmmodel.cpp, the
// two derived models). Loops over the node list at +0xf8 use the exe's iterator helpers (begin 0x141209190, end
// 0x141209360, neq 0x140b029f0, deref 0x140b02a60, inc 0x140b02a80).
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include <NiPoint3.h>
#include "equipmodel.h"
#include <efd/Matrix3.h>
#include <NiTransform.h>
#include <NiAVObject.h>
#include <NiActorManager.h>
#include <string.h>
#include <vector>
#include <efd/Category.h>
#include <egf/EntityID.h>
#include "ms2/placeholder/unk_1402a9d70.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/equipment.h"  // C3: CEquipment::FUN_1411e9fa0 / FUN_1411ea430 / FUN_1411ea500
#include "ms2/placeholder/effectquery.h"
#include <NiMesh.h>
#include "ms2/client/ms2/weaponattachtransformnode.h"
#include <egmAnimation/AnimationService.h>   // C3: AnimationService::GetActorManager
#include "ms2/commonfiles/os.h"

// ---- exe data ----
extern float DAT_143ac3d08;     // the engine's frame step
#define DAT_143b01a60 (*(char*)&efd::Point3::ZERO)          // C3: was extern char DAT_143b01a60
// 0x143ad2348 is s_strWillUpdatePos (constructed in .text$di 0x1400e8b40); the data_bss_game blob of that name never is
extern ATL::CAtlList<CString> s_meshSuffixes; // equipment.cpp: side suffixes tried when resolving an attach point name
extern char DAT_142ec05ba;      // ""

// ---- out-of-unit callees ----
void FUN_1401d3700(CString& s);
// smart pointers (MS2Ptr<Owner> at +0x28, NiPointer at +0xf0 / +0x108 / the temporaries)
void FUN_1405a85f0(void* sp);
void* FUN_140884f30(void* dst, void* src);
void* FUN_14097eb60(void* out, void* p); void* FUN_14097eba0(void* out, void* p);
void* FUN_1409f7170(void* sp, void* p); void FUN_1409f74b0(void* sp);

// the owner wrapper (character / mannequin entity)
void* FUN_1411de2e0(void* guard, void* model); void FUN_140b02860(void* guard);
class WorldService // C3: member view for the former free stand-ins
{
public:
static WorldService* GetInstance();
class Unk_WsC_GameObj* FindObjectById(int);
void* FUN_141bd0cc0();
};
class CEffectService // C3: member view for the former free stand-ins
{
public:
unsigned int FUN_1411a49c0(class Unk_EffectTarget&);
public:
void FUN_1411a6060(unsigned int); // C3: was free FUN_1411a6060
};
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();   void* FUN_14123c460(void* ent, void* out);
struct Unk_EmModelLoader { efd::utf8string FUN_141206030(const egf::EntityID& kId); };
class GameObject   // C3: unit-local view (gameobject.h)
{
public:
int FUN_14123c580();
egf::EntityID FUN_14123c460();
};
class PC   // C3: member view for the former free stand-ins
{
public:
struct Unk_PCEquipSet* FUN_1416561a0();
int FUN_141658e60();
MS2Ptr<CEquipItem> FUN_141655c90(int);
};
class AvatarPC;
class MyPC;
namespace efd {
template <> PC* DynamicCast<PC, GameObject>(GameObject* p);
template <> AvatarPC* DynamicCast<AvatarPC, GameObject>(GameObject* p);
template <> MyPC* DynamicCast<MyPC, GameObject>(GameObject* p);
}
class CMainSystem { public: double FUN_141473280(); };   // C3: member view
class CStateService { public: int FUN_1417e2610(); };    // C3: member view
template<> CStateService* TSingleton<CStateService>::GetInstance();   // statemanager.cpp defines s_instance

// the id holder returned by FUN_1411dc7a0 and its accessors
void FUN_1401bf970(void* out, void* p); char FUN_1401b5240(void* p, int n);
char FUN_1401b50d0(void* p);   void* FUN_140203c60(void* p);   void* FUN_140203510(void* out, int n);

class CItemData   // C3: member view for the former free stand-ins
{
public:
int GetEquipSubtype();
bool FUN_14053ce80();
    bool HasSkinType();
bool FUN_14053cfd0();
bool FUN_14053d2b0();
bool FUN_14053d2f0();
bool FUN_14053d510();
bool FUN_14053e370();
struct ItemModelHead* FUN_14053ec70();
};
struct ItemModelHead   // C3: member view for the former free stand-ins
{
public:
bool FUN_1405471b0();
};
class CItemExtraData   // C3: member view for the former free stand-ins
{
public:
bool AdvanceCycle();
};

class CGameOption;
void* FUN_1412041d0(void* p); void* FUN_141204220(void* p); void* FUN_140c77560(void* p);
class ModelGroup   // C3: member view for the former free stand-ins
{
public:
int FUN_1405451a0() const;
};
int FUN_1405451c0(CString& s);
// strings / names
void* FUN_1409989e0(void* out, const char* psz);

char FUN_140184310(CString* a, void* psz);

CString FUN_14016a5c0(const char* psz, int n);
// scene objects
// Breadth-first walk over an object's subtree (0x30 bytes, like Unk_NodeWalker in uichaoslightdialog.h).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pRoot);                                    // 0x14098cb80
    ~Unk_NodeQueue();                                              // 0x14098cf00
    NiAVObject* Next(bool bChildren);                            // 0x14098e0d0 next object, NULL at the end
private:
    void* m_a[6];
};
typedef Unk_NodeQueue Unk_MeshWalker;   // C3: was a local stand-in for Unk_NodeQueue

// The animation service's protected actor table (ContainsEntity, ActorEntry, AssetData), opened up for the model loader.
struct Unk_EmAnimAccess : egmAnimation::AnimationService
{
    using AnimationService::ActorEntry;
    using AnimationService::AssetData;
    using AnimationService::AssetDataPtr;
    using AnimationService::ContainsEntity;
};

// C3: the former Vector3 member view (FUN_140968990) is efd::Point3::Unitize (called directly)
//
//
//
//

void* FUN_141068d50p(void* a, const char* psz);
// game
void FUN_1411cf000(void* a);
void* FUN_141658e60p(void* ent);

// cl's `for each` (the exe's iteration shape); clang-cl (the hook DLL build) has no such statement: a range-for there.
#ifdef __clang__
#define EM_FOR_EACH(decl, container) for (decl : container)
#else
#define EM_FOR_EACH(decl, container) for each (decl in container)
#endif

// Vtable views of exe objects reached through opaque pointers (only the slots this unit calls).
struct Unk_EmSlots8 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); };
struct Unk_EmSlots16 : Unk_EmSlots8 { virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); };
struct Unk_EmSlots24 : Unk_EmSlots16 { virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); };
struct Unk_EmSlots32 : Unk_EmSlots24 { virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); };
struct Unk_EmSlots40 : Unk_EmSlots32 { virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); };
struct Unk_EmSlots48 : Unk_EmSlots40 { virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); };
struct Unk_EmSlots56 : Unk_EmSlots48 { virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); };
// The owner's entity (FUN_141200820's result).
struct Unk_EmEntity : Unk_EmSlots56
{
    virtual void vfunc_56(); virtual void vfunc_57();
    virtual int vfunc_58();         // 58 the effect object id
    virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64();
    virtual int vfunc_65();         // 65 nonzero selects the alternate (A1/A3) part names
};
// The interface query at slot 5 (FUN_1412041d0 / FUN_141204220).
struct Unk_EmQuery
{
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual bool vfunc_5(unsigned nId, void** ppOut);
};
#define OWNER(self) reinterpret_cast<MS2Ptr<CEquipItem>*>(&(self)->m_spOwner)->operator->()
// The owner is the CEquipItem (m_spOwner is typed as an opaque holder; operator-> is 0x1405a8ed0).
#define EQUIP(sp) reinterpret_cast<CEquipItem*>((sp).operator->())
#define NODE(self) ((void*)&(self)->m_spNode)

// ---- unit-local views of exe objects ----
// The model's description record (CEquipModel::m_unk_20): the equip part it renders.
struct Unk_PartInfo
{
    char m_pad_00[0x10];
    CString m_strName;              // +0x10
    char m_pad_18[8];
    int m_n20;                      // +0x20 0 for a model without a bound entity
    int m_n24;                      // +0x24
    char m_pad_28[4];
    int m_n2c;                      // +0x2c 1 for the mannequin / preview model
    char m_pad_30[0x18];
    int m_nSlot;                    // +0x48 index into the entity's per-slot attach points
    char m_pad_4c[0xdc];
    char m_aLists[1];               // +0x128 std::vector<Unk_PartAttach>[] (0x18 bytes each)
};
MS2_CHECK_OFFSET(Unk_PartInfo, m_n24, 0x24);
MS2_CHECK_OFFSET(Unk_PartInfo, m_nSlot, 0x48);
MS2_CHECK_OFFSET(Unk_PartInfo, m_aLists, 0x128);

// The owner entity's per-slot attach points (FUN_140527870's result).
struct Unk_EntityPoints
{
    char m_pad_00[0x60];
    NiPoint3 m_aPos[2];             // +0x60 m_vPos
    NiPoint3 m_aPos78[1];           // +0x78 the second point array
};
MS2_CHECK_OFFSET(Unk_EntityPoints, m_aPos78, 0x78);

// One element (0x38 bytes) of the part's attach list.

struct Unk_PartAttach
{
    char m_pad_00[8];
    CString m_strName;              // +0x08 prefix the target mesh name must start with
    CString m_strMask;              // +0x10 visible-part name that suppresses the attach
    float m_afRot[3];               // +0x18 degrees
    float m_afPos[3];               // +0x24
    float m_fScale;                 // +0x30
    bool m_bFollow;                 // +0x34
    bool m_bFlag;                   // +0x35
    char m_pad_36[2];
};
MS2_CHECK_SIZE(Unk_PartAttach, 0x38);

// The counted handle held at +0x140 of the attach dummy: the attach node's movement (MS2Ptr<INodeMovement>, dtor
// 0x1411a3e30, operator-> 0x1411a3f30, AddRef 0x1411a4080). Its copy ctor 0x1412051d0 is defined below.
class INodeMovement;
typedef MS2Ptr<INodeMovement> Unk_HoldHandle;
template <> MS2Ptr<INodeMovement>::MS2Ptr(const MS2Ptr& o);    // 0x1412051d0

// The dummy attach node class (DAT_143af77a8; 0x188 bytes, NiNode + the follow state below). The NiAVObject local
// transform is at +0x50 (rotate) / +0x74 (translate).
struct Unk_AttachDummy
{
    char m_pad_00[0x50];
    char m_aRotate[0x24];           // +0x50 local rotate
    NiPoint3 m_kTranslate;          // +0x74 local translate
    char m_pad_80[0xb8];
    void* m_pFollow;                // +0x138 the node it follows
    Unk_HoldHandle m_hold;          // +0x140
    Unk_HoldHandle FUN_141205e30(); // 0x141205e30 return m_hold
    int m_nMode;                    // +0x150
    int m_nFlag;                    // +0x154
    NiPoint3 m_kBasePos;            // +0x158
    char m_aBaseRotate[0x24];       // +0x164
};
MS2_CHECK_SIZE(Unk_AttachDummy, 0x188);
MS2_CHECK_OFFSET(Unk_AttachDummy, m_pFollow, 0x138);
MS2_CHECK_OFFSET(Unk_AttachDummy, m_nFlag, 0x154);
MS2_CHECK_OFFSET(Unk_AttachDummy, m_kBasePos, 0x158);

// The item template row the owner resolves to (only the fields the equip model reads).
struct Unk_EquipTpl
{
    char m_pad_000[0x210];
    int m_nLevel;                   // +0x210
    char m_pad_214[4];
    CString m_strA0;                // +0x218 (two per hand)
    CString m_strA1;                // +0x220
    CString m_strA2;                // +0x228
    CString m_strA3;                // +0x230
    char m_bFlagA;                  // +0x238
    char m_bFlagB;                  // +0x239
};
MS2_CHECK_OFFSET(Unk_EquipTpl, m_nLevel, 0x210);
MS2_CHECK_OFFSET(Unk_EquipTpl, m_bFlagB, 0x239);

// The object behind the hold handle: a float at +0x5c.
struct Unk_HoldTarget
{
    char m_pad_00[0x5c];
    float m_fScale;
};

char FUN_140b029f0(void* a, void* b);   void* FUN_140b02a60(void* it);   void FUN_140b02a80(void* it);
   

// ---- static data (.text$di) ----
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CEquipModel);

static CString s_strWillUpdatePos("WillUpdatePos");
static CString s_astrNames1[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CString s_strSkill1("skill");
static CString s_strStun1("stun");
efd::Category g_catEquip(0ull);
static Unk_1402a9d70 s_map1(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_astrNames2[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CString s_strSkill2("skill");
static CString s_strStun2("stun");
static Unk_1402a9d70 s_map2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- forward declarations of this unit's helpers ----
void FUN_141207fb0(Unk_HoldTarget* p, float f);
void FUN_1411ffee0(CEquipModel* self, double fTime);
void FUN_1412024f0(CEquipModel* self, NiPoint3* pPos, efd::Point3* pEuler, float* pScale, void* pLocal, void* pTrans, void* pRot);
void* FUN_141200820(CEquipModel* self);
void* FUN_141200850(CEquipModel* self);
void* FUN_1412008e0(CEquipModel* self);
void* FUN_1412009d0(CEquipModel* self);
void* FUN_141200a90(CEquipModel* self);
void* FUN_141200ab0(CEquipModel* self);
bool FUN_141200ad0(CEquipModel* self);
void FUN_141200b30(CEquipModel* self);
void FUN_141200ca0(CEquipModel* self);
void FUN_141200e30(CEquipModel* self, int n);
void FUN_141200390(CEquipModel* self, const CString& kName);
void* FUN_1412018c0(CEquipModel* self);
void FUN_141202bd0(CEquipModel* self);
void FUN_141202d20(CEquipModel* self, int nSlot, CString* pName, unsigned char bKeep, unsigned char bWorld);
void FUN_141202dc0(CEquipModel* self, int nSlot);
bool FUN_141202e30(CEquipModel* self, int nSlot);
void FUN_1412034e0(CEquipModel* self);
void FUN_141203570(CEquipModel* self, int nSlot, CString kName, unsigned char bWorld);
void FUN_141203660(CEquipModel* self, int nSlot, CString kName, void* pNode);
bool FUN_141203cf0(CEquipModel* self, void* pEnt);
void FUN_141203db0(CEquipModel* self);

// ---- CEquipModel ----

// @0x1411ffa10
CEquipModel::CEquipModel(MS2Ptr<CEquipItem> spOwner, void* p18, void* p20)
    : m_unk_18(p18), m_unk_20(p20), m_spOwner(spOwner), m_str38(""), m_nState(0), m_map78(17, 0.75f, 0.25f, 2.25f, 10),
      m_listC0(10), m_unk_f0(0), m_spNode(0), m_b110(false), m_b111(false)
{
    m_fScale44 = 1.0f;
    m_pos48 = *(NiPoint3*)&DAT_143b01a60;
    m_pos54 = *(NiPoint3*)&DAT_143b01a60;
    m_pos60 = *(NiPoint3*)&DAT_143b01a60;
    m_pos6c = *(NiPoint3*)&DAT_143b01a60;
    (*reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&m_unk_f0) = (NiAVObject*)(void*)(0));
    if (((void*)reinterpret_cast<MS2Ptr<CEquipItem>*>(&m_spOwner)->operator CEquipItem*()) ? true : false) {
        if (((void*)((class CEquipItem*)(void*)(OWNER(this)))->FUN_1411dc7f0()) != 0)
            m_b110 = ((class CItemData*)(void*)(((void*)((class CEquipItem*)(void*)(OWNER(this)))->FUN_1411dc7f0())))->FUN_14053e370();
    }
}

// @0x1411ffcb0
CEquipModel::~CEquipModel()
{
    (*reinterpret_cast<MS2Ptr<CPtred>*>(&m_spOwner) = 0);
    (*reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&m_unk_f0) = (NiAVObject*)(void*)(0));
    FUN_141203db0(this);
    m_listC0.RemoveAll();
    m_unk_f8.clear();
}

// @0x1411ffdd0
void CEquipModel::vfunc_5()
{
    FUN_1412034e0(this);
    FUN_141203db0(this);
    MS2Ptr<CEquipModel> spKeep(this);    // keeps the model alive while the owner drops it
    ((class CEquipItem*)(void*)(OWNER(this)))->FUN_1411ddf10((class CEquipModel*)(this));
    (*reinterpret_cast<MS2Ptr<CPtred>*>(&m_spOwner) = 0);
    (*reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&m_unk_f0) = (NiAVObject*)(void*)(0));
}

// @0x1411ffe70
void CEquipModel::vfunc_17()
{
    bool bVisible = (bool)(m_nState != 0 && vfunc_20());
    if (bVisible)
        FUN_141202bd0(this);
    else
        FUN_1412034e0(this);
}

// @0x1411ffee0
void FUN_1411ffee0(CEquipModel* self, double fTime)
{
    if (self->m_b110 != 0) {
        void* p = ((void*)((class CItem*)(void*)(EQUIP(self->m_spOwner)->GetItem().operator->()))->FUN_140527870());
        if (p == 0)
            return;
        if (((class CItemExtraData*)(void*)(p))->AdvanceCycle())
            self->vfunc_11();
    }
}

// @0x1411fff90
int CEquipModel::vfunc_20()
{
    return m_listC0.IsEmpty();
}

// @0x1411fffc0
float CEquipModel::vfunc_21()
{
    return m_fScale44;
}

// @0x1411fffe0
void CEquipModel::vfunc_22(float f)
{
    m_fScale44 = f;
}

// @0x141200010
NiPoint3 CEquipModel::vfunc_23()
{
    return m_pos48;
}

// @0x141200040
void CEquipModel::vfunc_24(const NiPoint3& p)
{
    m_pos48 = p;
}

// @0x141200070
NiPoint3 CEquipModel::vfunc_25()
{
    return m_pos54;
}

// @0x1412000a0
void CEquipModel::vfunc_26(const NiPoint3& p)
{
    m_pos54 = p;
}

// @0x1412000d0
NiPoint3 CEquipModel::GetPos6c()
{
    return m_pos6c;
}

// @0x141200100
void FUN_141200100(CEquipModel* self, NiPoint3 p)
{
    self->m_pos6c = p;
}

// @0x141200130
NiPoint3 CEquipModel::FUN_141200130()
{
    return m_pos60;
}

// @0x141200160
void FUN_141200160(CEquipModel* self, NiPoint3 p)
{
    self->m_pos60 = p;
}

// @0x141200190
void CEquipModel::vfunc_27(const char* psz)
{
    void* p = FUN_1412018c0(this);
    if (p != 0)
        ((class NiAVObject*)(void*)(p))->SetLocalFromWorldTransform(*(class NiTransform const*)(psz));
}

// @0x1412001d0
void CEquipModel::vfunc_29(void* a, void* b, float f)
{
}

// @0x1412001f0
void CEquipModel::vfunc_28(void* a, void* b, float f)
{
}

// @0x141200210
void CEquipModel::vfunc_30(void* a, void* b, float f)
{
}

// Attaches the default "Point01" node of the loaded model.
// @0x141200230
void FUN_141200230(CEquipModel* self)
{
    MS2Ptr<CItemData> spData((CItemData*)FUN_1412009d0(self));
    if (spData == NULL)
        return;
    void* pEnt = FUN_141200820(self);
    if (pEnt == 0)
        return;
    CString kPoint("Point01");
    NiNodePtr spPoint = self->FUN_141201bd0(kPoint);
    if ((*reinterpret_cast<efd::SmartPointer<NiNode>*>(&spPoint) == (NiNode*)0))
        return;
    FUN_141203660(self, 2, self->FUN_141203830(), ((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(&spPoint)->operator NiNode*()));
}

// Hangs the "dummy" attach nodes described by the part's attach list on the parent of the attach node.
// @0x141200390
void FUN_141200390(CEquipModel* self, const CString& kName)
{
    void* pEnt = FUN_141200820(self);
    if (pEnt == 0)
        return;
    if ((*reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self)) == (NiNode*)0) || ((void*)((class NiAVObject*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator->())))->GetParent()) == 0)
        return;
    NiAVObject* pDummy = (NiAVObject*)((void*)NiObject::DynamicCast(&WeaponAttachTransformNode::ms_RTTI, (class NiObject const*)(((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator NiNode*()))));
    if (pDummy == 0)
        return;
    NiTransform kXf;
    kXf.MakeIdentity();
    ((class NiAVObject*)(void*)(pDummy))->SetLocalTransform(*reinterpret_cast<const NiTransform*>(&kXf));
    reinterpret_cast<WeaponAttachTransformNode*>(pDummy)->SetUseMovement(0);
    reinterpret_cast<WeaponAttachTransformNode*>(pDummy)->SetMode(0);
    Unk_PartInfo* pInfo = (Unk_PartInfo*)FUN_141200ab0(self);
    std::vector<Unk_PartAttach>& kList = ((std::vector<Unk_PartAttach>*)pInfo->m_aLists)[(unsigned)((class PC*)(void*)(pEnt))->FUN_141658e60()];
    std::vector<Unk_PartAttach>::iterator itCur;
    for (itCur = kList.begin(); itCur != kList.end(); ++itCur) {
        Unk_PartAttach* e = itCur.operator->();
        bool bOther = e->m_strName.GetLength() > 0 && e->m_strName != kName.Left(e->m_strName.GetLength());
        if (bOther)
            continue;
        if (e->m_strMask.GetLength() > 0
            && *(NiFixedString*)((void*)&((class NiObjectNET*)(void*)(((void*)((class NiAVObject*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator->())))->GetParent())))->GetName()) != (const char*)e->m_strMask)
            continue;
        efd::Matrix3 kMat;
        efd::Point3 kRot = *(const efd::Point3*)e->m_afRot * 3.1415927f / 180.0f;
        kMat.FromEulerAnglesXYZ(kRot.x, kRot.y, kRot.z);
        reinterpret_cast<WeaponAttachTransformNode*>(pDummy)->SetBaseRotate(*(const NiMatrix3*)&kMat);
        NiPoint3 kPos(*reinterpret_cast<const efd::Point3*>(e->m_afPos));
        reinterpret_cast<WeaponAttachTransformNode*>(pDummy)->SetBasePosition(kPos);
        if (e->m_bFollow) {
            void* pRoot = ((void*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(((void*)((class NiActorManager*)(void*)(FUN_1412008e0(self)))->GetNIFRoot()))));
            reinterpret_cast<WeaponAttachTransformNode*>(pDummy)->SetFollowNode((NiAVObject*)pRoot);
            reinterpret_cast<WeaponAttachTransformNode*>(pDummy)->SetMode(e->m_bFollow);
            reinterpret_cast<WeaponAttachTransformNode*>(pDummy)->SetUseMovement(e->m_bFlag);
            FUN_141207fb0((Unk_HoldTarget*)((Unk_AttachDummy*)pDummy)->FUN_141205e30().operator->(), e->m_fScale);
        }
        pDummy->Update((float)((class CMainSystem*)(void*)TSingleton<CMainSystem>::GetInstance())->FUN_141473280(), true);
    }
}

// @0x141200820
void* FUN_141200820(CEquipModel* self)
{
    return efd::DynamicCast<PC, GameObject>((GameObject*)(FUN_141200850(self)));
}

// @0x141200850
void* FUN_141200850(CEquipModel* self)
{
    return ((void*)((class WorldService*)(void*)(WorldService::GetInstance()))->FindObjectById(((CEquipItem*)OWNER(self))->GetItem()->FUN_140526b10()));
}

// @0x1412008e0
void* FUN_1412008e0(CEquipModel* self)
{
    void* pEnt = FUN_141200850(self);
    if (pEnt == 0)
        return 0;
    return reinterpret_cast<egmAnimation::AnimationService*>(reinterpret_cast<void*>(FUN_141b6f910()))->GetActorManager(((GameObject*)pEnt)->FUN_14123c460());
}

// @0x141200940
MS2Ptr<CItem> CEquipModel::FUN_141200940()
{
    if ((!*reinterpret_cast<MS2Ptr<CEquipItem>*>(&m_spOwner)))
        return MS2Ptr<CItem>(0);
    return EQUIP(m_spOwner)->GetItem();
}

// @0x1412009d0
void* FUN_1412009d0(CEquipModel* self)
{
    CItem* p = self->FUN_141200940().get();
    if (p == 0)
        return 0;
    return ((void*)((class CItem*)(void*)(p))->FUN_140527840());
}

// @0x141200a40
MS2Ptr<CEquipItem> CEquipModel::FUN_141200a40()
{
    return m_spOwner;
}

// @0x141200a90
void* FUN_141200a90(CEquipModel* self)
{
    return self->m_unk_18;
}

// @0x141200ab0
void* FUN_141200ab0(CEquipModel* self)
{
    return self->m_unk_20;
}

// @0x141200ad0
bool FUN_141200ad0(CEquipModel* self)
{
    if (self->m_unk_20 == 0)
        return false;
    return ((Unk_PartInfo*)self->m_unk_20)->m_n2c == 1;
}

// @0x141200b20
void CEquipModel::vfunc_31()
{
}

// @0x141200b30
void FUN_141200b30(CEquipModel* self)
{
    void* p = FUN_1412008e0(self);
    if (p != 0) {
        NiAVObject* pRoot = (NiAVObject*)((void*)((class NiActorManager*)(void*)(p))->GetNIFRoot());
        if (pRoot != 0) {
            pRoot->UpdateProperties();
            pRoot->UpdateEffects();
            pRoot->Update(DAT_143ac3d08 + 0.001f, true);
        }
    }
}

// @0x141200bb0
int FUN_141200bb0(CEquipModel* self, CString* pName)
{
    if (self->m_listC0.Lookup(*pName))
        return 0;
    self->m_listC0.SetAt(*pName, 1);
    return 1;
}

// @0x141200c10
int FUN_141200c10(CEquipModel* self, CString* pName)
{
    return self->m_listC0.RemoveKey(*pName);
}

// @0x141200c50
int FUN_141200c50(CEquipModel* self, CString* pName)
{
    int nVal = 0;
    if (self->m_listC0.Lookup(*pName, nVal))
        return 1;
    return 0;
}

// Re-applies the part after a (re)load: visibility, equip callbacks and the transform refresh.
// @0x141200ca0
void FUN_141200ca0(CEquipModel* self)
{
    if (FUN_141200ad0(self))
        self->vfunc_13();
    else
        self->vfunc_12();
    if (((void*)reinterpret_cast<MS2Ptr<CEquipItem>*>(&self->m_spOwner)->operator CEquipItem*()) ? true : false) {
        if (((void*)((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dc7f0()) != 0) {
            if (((class CItemData*)(void*)(((void*)((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dc7f0())))->FUN_14053ec70()->FUN_1405471b0()) {
                ((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dce60(s_strWillUpdatePos);
                ((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dd280();
            }
            void* pEnt = FUN_141200820(self);
            if (pEnt != 0) {
                ((CEquipment*)((class PC*)(void*)(pEnt))->FUN_1416561a0())->FUN_1411ea430(reinterpret_cast<MS2Ptr<CEquipItem>&>(self->m_spOwner));
                FUN_141202bd0(self);
            }
        }
    }
    FUN_141200b30(self);
    self->vfunc_31();
}

// Detaches every attached scene object from the loaded root (bClear: forget them) and reports the unequip.
// @0x141200e30
void FUN_141200e30(CEquipModel* self, int bClear)
{
    NiNode* pRoot = (NiNode*)((void*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(self->vfunc_14())));
    if (pRoot == 0)
        return;
    EM_FOR_EACH(NiAVObjectPtr sp, self->m_unk_f8) {
        if ((*reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp) == (NiAVObject*)(void*)(pRoot))) {
            NiNode* pParent = (NiNode*)((void*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(((void*)((class NiAVObject*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator->())))->GetParent()))));
            if (pParent != 0)
                pParent->DetachChild((NiAVObject*)((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator NiAVObject*()));
        } else {
            pRoot->AttachChild((NiAVObject*)((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator NiAVObject*()), true);
        }
    }
    void* pEnt = FUN_141200820(self);
    if (pEnt != 0) {
        MS2Ptr<CItem> spItem = EQUIP(self->m_spOwner)->GetItem();
        if (((void*)((MS2Ptr<CItem>*)(void*)(&spItem))->get()) != 0)
            ((CEquipment*)((class PC*)(void*)(pEnt))->FUN_1416561a0())->FUN_1411e9fa0(((class CItem*)(void*)(spItem.operator->()))->FUN_140527a20(), self->FUN_1412029d0(),
                          ((class CItem*)(void*)(spItem.operator->()))->HasSkin(), ((class CItemData*)(void*)(((void*)((class CItem*)(void*)(spItem.operator->()))->FUN_140527840())))->FUN_14053d2b0());
        ((CEquipment*)((class PC*)(void*)(pEnt))->FUN_1416561a0())->FUN_1411ea500(reinterpret_cast<MS2Ptr<CEquipItem>&>(self->m_spOwner));
    }
    if (bClear != 0)
        self->m_unk_f8.clear();
    FUN_141200b30(self);
}

// Marks the meshes whose names (or, failing that, whose names without the prefix) match kName as visible/hidden.
// @0x141201180
void FUN_141201180(CEquipModel* self, const CString& kName)
{
    CString kMesh;
    CString kKey(kName);
    FUN_1401d3700(*(&kKey));
    EM_FOR_EACH(NiAVObjectPtr sp, self->m_unk_f8) {
        Unk_MeshWalker kWalk((NiAVObject*)(((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator NiAVObject*())));
        void* pObj;
        while ((pObj = kWalk.Next(true)) != 0) {
            void* pMesh = ((void*)NiObject::DynamicCast(&NiMesh::ms_RTTI, (class NiObject const*)(pObj)));
            if (pMesh == 0)
                continue;
            kMesh = reinterpret_cast<efd::FixedString*>(((void*)&((class NiObjectNET*)(void*)(pMesh))->GetName()))->operator const char*();
            FUN_1401d3700(*(&kMesh));
            if ((*(&kMesh) == *(&kKey))) {
                ((class NiAVObject*)(void*)(pMesh))->SetAppCulled(true);
            } else {
                kMesh = kMesh.Mid(0, kKey.GetLength());
                if ((*(&kMesh) == *(&kKey)))
                    ((class NiAVObject*)(void*)(pMesh))->SetAppCulled(true);
            }
        }
    }
    Unk_MeshWalker kWalk2((NiAVObject*)(self->vfunc_14()));
    void* pObj2;
    while ((pObj2 = kWalk2.Next(true)) != 0) {
        void* pMesh = ((void*)NiObject::DynamicCast(&NiMesh::ms_RTTI, (class NiObject const*)(pObj2)));
        if (pMesh == 0)
            continue;
        kMesh = reinterpret_cast<efd::FixedString*>(((void*)&((class NiObjectNET*)(void*)(pMesh))->GetName()))->operator const char*();
        FUN_1401d3700(*(&kMesh));
        if ((*(&kMesh) == *(&kKey))) {
            ((class NiAVObject*)(void*)(pMesh))->SetAppCulled(true);
        } else {
            kMesh = kMesh.Mid(0, kKey.GetLength());
            if ((*(&kMesh) == *(&kKey)))
                ((class NiAVObject*)(void*)(pMesh))->SetAppCulled(true);
        }
    }
}

// Writes pPt into the owner entity's per-slot point array at +0x60 (m_vPos).
// @0x1412014f0
void FUN_1412014f0(CEquipModel* self, void* pPt)
{
    MS2Ptr<CEquipItem> spOwn = self->FUN_141200a40();
    if (spOwn == NULL)
        return;
    Unk_PartInfo* pInfo = (Unk_PartInfo*)self->m_unk_20;
    if (pInfo == 0)
        return;
    if (pInfo->m_n24 != 0 && ((class CItemData*)(void*)(((void*)((class CEquipItem*)(void*)(spOwn.operator->()))->FUN_1411dc7f0())))->FUN_14053cfd0() != 0) {
        Unk_EntityPoints* p = (Unk_EntityPoints*)((void*)((class CItem*)(void*)(EQUIP(spOwn)->GetItem().operator->()))->FUN_140527870());
        if (p != 0)
            *reinterpret_cast<efd::Point3*>(p->m_aPos + pInfo->m_nSlot) = *reinterpret_cast<const efd::Point3*>(pPt);
    }
}

// Same for the point array at +0x78.
// @0x141201620
void FUN_141201620(CEquipModel* self, void* pPt)
{
    MS2Ptr<CEquipItem> spOwn = self->FUN_141200a40();
    if (spOwn == NULL)
        return;
    Unk_PartInfo* pInfo = (Unk_PartInfo*)self->m_unk_20;
    if (pInfo == 0)
        return;
    if (pInfo->m_n24 != 0 && ((class CItemData*)(void*)(((void*)((class CEquipItem*)(void*)(spOwn.operator->()))->FUN_1411dc7f0())))->FUN_14053cfd0() != 0) {
        Unk_EntityPoints* p = (Unk_EntityPoints*)((void*)((class CItem*)(void*)(EQUIP(spOwn)->GetItem().operator->()))->FUN_140527870());
        if (p != 0)
            *reinterpret_cast<efd::Point3*>(p->m_aPos78 + pInfo->m_nSlot) = *reinterpret_cast<const efd::Point3*>(pPt);
    }
}

// @0x141201750
void CEquipModel::vfunc_32(int n)
{
    FUN_141202bd0(this);
}

// Name of the entity class the model's entity is created from.
// @0x141201780
efd::utf8string CEquipModel::FUN_141201780()
{
    void* pEnt = FUN_141200850(this);
    if (pEnt != 0) {
        if (efd::DynamicCast<MyPC, GameObject>((GameObject*)(pEnt)) != 0) {
            return efd::utf8string("MS2EquipItem");
        }
        if (FUN_1412041d0(pEnt) != 0) {
            return efd::utf8string("MS2MannequinEquipItem");
        }
        if (efd::DynamicCast<AvatarPC, GameObject>((GameObject*)(pEnt)) != 0) {
            return efd::utf8string("MS2MannequinEquipItem");
        }
        if (efd::DynamicCast<PC, GameObject>((GameObject*)(pEnt)) != 0) {
            if (*((bool*)FUN_140c77560(TSingleton<CGameOption>::GetInstance()) + 0x11)) {
                return efd::utf8string("MS2EquipItem");
            }
        }
    }
    return efd::utf8string("MS2EquipItemNoPhysX");
}

// First attached scene object (the model's root), or NULL.
// @0x1412018c0
void* FUN_1412018c0(CEquipModel* self)
{
    if (self->m_unk_f8.size() == 0)
        return 0;
    return ((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>((void*)&*self->m_unk_f8.begin())->operator NiAVObject*());
}

// Finds the attached scene object whose name is kName (or which contains an object of that name).
// @0x141201920
NiAVObjectPtr CEquipModel::FUN_141201920(CString kName)
{
    EM_FOR_EACH(NiAVObjectPtr sp, m_unk_f8) {
        if ((*(const NiFixedString*)(((void*)&((class NiObjectNET*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator->())))->GetName())) == (const char*)kName))
            return sp;
    }
    EM_FOR_EACH(NiAVObjectPtr sp, m_unk_f8) {
        NiAVObjectPtr spFound(((NiAVObject*)((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator->()))->GetObjectByName((const char*)kName));
        if (((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&spFound)->operator NiAVObject*()) != 0)
            return spFound;
    }
    return NiAVObjectPtr(0);
}

// @0x141201bd0
NiNodePtr CEquipModel::FUN_141201bd0(const CString& kName)
{
    return NiNodePtr((NiNode*)((void*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(FUN_141201920(kName).operator NiAVObject*()))));
}

// @0x141201c90
std::set<NiAVObjectPtr>* FUN_141201c90(CEquipModel* self)
{
    return &self->m_unk_f8;
}

// The attached-object set; with no entity bound it also contains the loaded root.
// @0x141201cb0
void FUN_141201cb0(CEquipModel* self, std::set<NiAVObjectPtr>& kSet)
{
    kSet = self->m_unk_f8;
    if (((Unk_PartInfo*)self->m_unk_20)->m_n20 == 0) {
        NiAVObject* pRoot = (NiAVObject*)self->vfunc_14();
        if (pRoot != 0) {
            NiAVObjectPtr spRoot(pRoot);
            kSet.insert(static_cast<NiAVObjectPtr&&>(spRoot));   // rvalue: the exe calls insert(value_type&&) 0x141205000
        }
    }
}

// Views of callees this function uses with value semantics: the entity
// loader's model path lookup (returns an efd::utf8string).
class CItemData;

// Re-parents the attach node onto the mesh named kName (mirrors the "_L_" / "_R_" naming of the part).
// @0x141201d50
void FUN_141201d50(CEquipModel* self, CString kName)
{
    void* pEnt = FUN_141200820(self);
    if (pEnt == 0)
        return;
    MS2Ptr<CItemData> spData((CItemData*)FUN_1412009d0(self));
    if (spData == 0)
        return;
    if (self->m_spNode == (NiNode*)0)
        return;
    if (kName == &DAT_142ec05ba)
        kName = self->FUN_1412029d0();
    CString kCur;
    if (((void*)((class NiAVObject*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator->())))->GetParent()) != 0)
        kCur = reinterpret_cast<efd::FixedString*>(((void*)&((class NiObjectNET*)(void*)(((void*)((class NiAVObject*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator->())))->GetParent())))->GetName()))->operator const char*();
    if (kCur == kName)
        return;
    void* pRoot = FUN_1412008e0(self);
    if (pRoot == 0)
        return;
    NiNode* pNode = (NiNode*)((void*)((class NiActorManager*)(void*)(pRoot))->GetNIFRoot());
    if (pNode == 0)
        return;
    NiNode* pTarget = (NiNode*)((void*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(pNode->GetObjectByName((const char*)kName))));
    if (pTarget == 0)
        return;
    pTarget->AttachChild(self->m_spNode, true);
    CString kModel(((Unk_EmModelLoader*)reinterpret_cast<void*>(FUN_141b6f910()))->FUN_141206030(((GameObject*)pEnt)->FUN_14123c460()).c_str());
    FUN_141200390(self, kModel);
    NiAVObject* pAV = (NiAVObject*)((void*)((class NiActorManager*)(void*)(pRoot))->GetNIFRoot());
    if (pAV != 0) {
        pAV->UpdateProperties();
        pAV->UpdateEffects();
    }
}

// @0x1412021a0
void FUN_1412021a0(CEquipModel* self, NiTransform* pOut)
{
    void* p = FUN_1412018c0(self);
    if (p != 0)
        (*reinterpret_cast<NiTransform*>(pOut) = *reinterpret_cast<const NiTransform*>(((void*)&((class NiAVObject*)(void*)(p))->GetLocalTransform())));
}

// @0x1412021f0
void FUN_1412021f0(CEquipModel* self, NiTransform* pOut)
{
    void* p = FUN_1412018c0(self);
    if (p != 0)
        (*reinterpret_cast<NiTransform*>(pOut) = *reinterpret_cast<const NiTransform*>(((void*)&((class NiAVObject*)(void*)(p))->GetWorldTransform())));
}

// @0x141202240
void FUN_141202240(CEquipModel* self, void* pXf)
{
    void* p = FUN_1412018c0(self);
    if (p != 0)
        ((class NiAVObject*)(void*)(p))->SetLocalTransform(*reinterpret_cast<const NiTransform*>(pXf));
}

// Local transform of the first mesh among the entity's "<part><suffix>" attach points.
// @0x141202280
void FUN_141202280(CEquipModel* self, NiTransform* pOut)
{
    void* pRoot = FUN_1412008e0(self);
    if (pRoot == 0)
        return;
    NiNode* pNode = (NiNode*)((void*)((class NiActorManager*)(void*)(pRoot))->GetNIFRoot());
    if (pNode == 0)
        return;
    const CString& kPart = self->FUN_1412029d0();
    void* pos = ((void*)((ATL::CAtlList<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)(void*)(&s_meshSuffixes))->GetHeadPosition());
    while (pos != 0) {
        CString kFull;
        kFull.Format("%s%s", (const char*)kPart, (const char*)s_meshSuffixes.GetNext(*(POSITION*)&pos));
        NiAVObjectPtr sp(pNode->GetObjectByName((const char*)kFull));
        if ((*reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp) == (NiAVObject*)(void*)(0)))
            continue;
        if (((void*)NiObject::DynamicCast(&NiMesh::ms_RTTI, (class NiObject const*)(((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator NiAVObject*())))) == 0)
            continue;
        (*reinterpret_cast<NiTransform*>(pOut) = *reinterpret_cast<const NiTransform*>(((void*)&((class NiAVObject*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator->())))->GetLocalTransform())));
        return;
    }
}

// @0x141202480
void FUN_141202480(CEquipModel* self, NiPoint3* pPos, float* pEuler, void* pLocal, void* pTrans, void* pRot)
{
    float fScale = 1.0f;
    FUN_1412024f0(self, pPos, (efd::Point3*)pEuler, &fScale, pLocal, pTrans, pRot);
}

// World position / Euler angles (degrees) / scale of the named attach point of the loaded model.
// @0x1412024f0
void FUN_1412024f0(CEquipModel* self, NiPoint3* pPos, efd::Point3* pEuler, float* pScale, void* pLocal, void* pTrans, void* pRot)
{
    void* pEnt = ((void*)((class WorldService*)(void*)(WorldService::GetInstance()))->FindObjectById(((class CItem*)(void*)(static_cast<const MS2Ptr<CItem>&>(((class CEquipItem*)(void*)(OWNER(self)))->GetItem()).operator->()))->FUN_140526b10()));
    if (pEnt == 0)
        return;
    void* pActor = reinterpret_cast<egmAnimation::AnimationService*>(reinterpret_cast<void*>(FUN_141b6f910()))->GetActorManager(((GameObject*)pEnt)->FUN_14123c460());
    if (pActor == 0)
        return;
    if (((void*)((class NiActorManager*)(void*)(pActor))->GetNIFRoot()) == 0)
        return;
    void* pObj = ((NiAVObject*)((void*)((class NiActorManager*)(void*)(pActor))->GetNIFRoot()))->GetObjectByName((LPCSTR)self->FUN_1412029d0());
    if (pObj == 0)
        return;
    void* pAttach = ((void*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(pObj)));
    if (pAttach == 0)
        return;
    void* pRoot = FUN_1412018c0(self);
    if (pRoot == 0)
        return;
    NiTransform kXf;
    if (pRot != 0)
        (*reinterpret_cast<NiTransform*>(&kXf) = *reinterpret_cast<const NiTransform*>(pRot));
    else
        (*reinterpret_cast<NiTransform*>(&kXf) = *reinterpret_cast<const NiTransform*>(((void*)&((class NiAVObject*)(void*)(pRoot))->GetLocalTransform())));
    *reinterpret_cast<efd::Point3*>(pTrans) = *reinterpret_cast<const efd::Point3*>(&kXf.m_Translate);
    NiTransform kWorld = ((class NiAVObject*)(void*)(pAttach))->GetWorldTransform();
    if (((void*)((class NiAVObject*)(void*)(pRoot))->GetParent()) != 0)
        (kWorld = *reinterpret_cast<const NiTransform*>(((void*)&((class NiAVObject*)(void*)(((void*)((class NiAVObject*)(void*)(pRoot))->GetParent())))->GetWorldTransform())));
    kXf = kWorld * ((class NiAVObject*)(void*)(pRoot))->GetLocalTransform();
    *reinterpret_cast<efd::Point3*>(pPos) = *reinterpret_cast<const efd::Point3*>(&kXf.m_Translate);
    *(efd::Point3*)pLocal = *pPos - kWorld.m_Translate;
    ((efd::Point3*)(void*)(pLocal))->Unitize();
    kXf.m_Rotate.ToEulerAnglesXYZ(pEuler->x, pEuler->y, pEuler->z);
    pEuler->x = (pEuler->x * 180.0f) / 3.1415927f;
    pEuler->y = (pEuler->y * 180.0f) / 3.1415927f;
    pEuler->z = (-pEuler->z * 180.0f) / 3.1415927f;
    *pScale = kXf.m_fScale;
}

// @0x1412028f0
CString CEquipModel::FUN_1412028f0()
{
    return m_str38;
}

// @0x141202940
int FUN_141202940(CEquipModel* self)
{
    CItem* p = self->FUN_141200940().get();
    if (p != 0) {
        if (((class CItemData*)(void*)(((void*)((class CItem*)(void*)(p))->FUN_140527840())))->FUN_14053d510() != 0) {
            return ((class CItem*)(void*)(p))->FUN_140526c30();
        }
    }
    return ((class ModelGroup*)(void*)(self->m_unk_18))->FUN_1405451a0();
}

// The part's name; the left/right counterpart is swapped in for the second hand's weapon.
// @0x1412029d0
CString CEquipModel::FUN_1412029d0()
{
    CItem* p = FUN_141200940().get();
    if (p != 0) {
        if (((class CItemData*)(void*)(((void*)((class CItem*)(void*)(p))->FUN_140527840())))->FUN_14053d510() != 0) {
            CString kName(((Unk_PartInfo*)m_unk_20)->m_strName);
            if (((class CItem*)(void*)(p))->FUN_140526c30() == 4) {
                int nL = kName.Replace("_L_", "_R_");
                int nS = kName.Replace(" L ", " R ");
                if (nL + nS == 0) {
                    kName.Replace("_R_", "_L_");
                    kName.Replace(" R ", " L ");
                }
            }
            return kName;
        }
    }
    return ((Unk_PartInfo*)m_unk_20)->m_strName;
}

// @0x141202b70
unsigned FUN_141202b70(CEquipModel* self)
{
    const CString& kName = self->FUN_1412029d0();
    return FUN_1405451c0(const_cast<CString&>(kName));
}

// (Re)applies the primary and secondary effect slots from the owner's template record.
// @0x141202bd0
void FUN_141202bd0(CEquipModel* self)
{
    if (self->vfunc_9() == 0)
        return;
    void* pEnt = FUN_141200820(self);
    if (pEnt == 0)
        return;
    Unk_EquipTpl* pTpl = (Unk_EquipTpl*)((void*)((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dc7f0());
    if (pTpl == 0)
        return;
    if (((Unk_EmEntity*)pEnt)->vfunc_65() != 0) {
        FUN_141202d20(self, 0, &pTpl->m_strA1, pTpl->m_bFlagA, 0);
        FUN_141202d20(self, 1, &pTpl->m_strA3, pTpl->m_bFlagB, 1);
    } else {
        FUN_141202d20(self, 0, &pTpl->m_strA0, pTpl->m_bFlagA, 0);
        FUN_141202d20(self, 1, &pTpl->m_strA2, pTpl->m_bFlagB, 1);
    }
}

// @0x141202d20
void FUN_141202d20(CEquipModel* self, int nSlot, CString* pName, unsigned char bKeep, unsigned char bWorld)
{
    if (bKeep != 0 && FUN_141202e30(self, nSlot) != 0)
        return;
    if (pName->IsEmpty())
        FUN_141202dc0(self, nSlot);
    else
        FUN_141203570(self, nSlot, CString(*pName), bWorld);
}

// Releases the effect bound to nSlot.
// @0x141202dc0
void FUN_141202dc0(CEquipModel* self, int nSlot)
{
    int nHandle = 0;
    if (self->m_map78.Lookup(reinterpret_cast<Unk_EquipEffectSlot&>(nSlot), nHandle)) {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(nHandle);
        self->m_map78.RemoveKey(reinterpret_cast<Unk_EquipEffectSlot&>(nSlot));
    }
}

// @0x141202e30
bool FUN_141202e30(CEquipModel* self, int nSlot)
{
    int nHandle = 0;
    if (self->m_map78.Lookup(reinterpret_cast<Unk_EquipEffectSlot&>(nSlot), nHandle))
        return nHandle != 0;
    return false;
}

// Creates the "Equip_Attach_Transform" / "Weapon_Attach_Transform{L,R}H" node under the loaded model for the part.
// @0x141202ea0
void FUN_141202ea0(CEquipModel* self, CString* pName)
{
    if (((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator NiNode*()) != 0)
        return;
    if ((*reinterpret_cast<MS2Ptr<CEquipItem>*>(&self->m_spOwner) == (CEquipItem*)0) != 0)
        return;
    if (self->m_unk_20 == 0)
        return;
    MS2Ptr<CItem> kId = EQUIP(self->m_spOwner)->GetItem();
    if (kId == 0)
        return;
    void* pRoot = FUN_1412008e0(self);
    if (pRoot == 0)
        return;
    NiNode* pModel = (NiNode*)((void*)((class NiActorManager*)(void*)(pRoot))->GetNIFRoot());
    if (pModel == 0)
        return;
    NiNode* pHost;
    {
        NiFixedString fs(*pName);
        pHost = (NiNode*)((void*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(pModel->GetObjectByName(fs))));
    }
    if (pHost == 0)
        return;
    int nType = ((class CItem*)(void*)(kId.operator->()))->FUN_140526c30();
    if (nType != 4 && nType != 5) {
        CString kTag = "Equip_Attach_Transform" + FUN_14016a5c0(*pName, 0);
        void* pNew = new (efd::MemHint((efd::MemHint::Bits)0)) NiNode(0);
        {
            NiFixedString fs2(kTag);
            ((class NiObjectNET*)(void*)(pNew))->SetName(fs2);
        }
        pHost->AttachChild((NiAVObject*)pNew, false);
        (*reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self)) = (NiNode*)(void*)(pNew));
    } else {
        CString kNode((nType == 4) ? "Weapon_Attach_TransformLH" : "Weapon_Attach_TransformRH");
        void* pNew = new (efd::MemHint((efd::MemHint::Bits)0)) WeaponAttachTransformNode;
        {
            NiFixedString fs2(kNode);
            ((class NiObjectNET*)(void*)(pNew))->SetName(fs2);
        }
        pHost->AttachChild((NiAVObject*)pNew, false);
        (*reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self)) = (NiNode*)(void*)(pNew));
        void* pEnt = FUN_141200820(self);
        if (pEnt != 0) {
            CString kModel(((Unk_EmModelLoader*)reinterpret_cast<void*>(FUN_141b6f910()))->FUN_141206030(((GameObject*)pEnt)->FUN_14123c460()).c_str());
            FUN_141200390(self, kModel);
        }
    }
}

// True when the model should be created for the local view: preview/cinematic scene types or the owner's own entity.
// @0x1412033e0
int FUN_1412033e0(CEquipModel* self)
{
    if (((class CStateService*)TSingleton<CStateService>::GetInstance())->FUN_1417e2610() == 0x620000d)
        return 1;
    if (((class CStateService*)TSingleton<CStateService>::GetInstance())->FUN_1417e2610() == 0x6200018)
        return 1;
    void* pLocal = ((class WorldService*)(void*)(WorldService::GetInstance()))->FUN_141bd0cc0();
    if (pLocal == 0)
        return 0;
    return EQUIP(self->m_spOwner)->GetItem()->FUN_140526ad0() == (unsigned)((GameObject*)pLocal)->FUN_14123c580();
}

// Releases every effect bound to a slot and empties the map.
// @0x1412034e0
void FUN_1412034e0(CEquipModel* self)
{
    for (POSITION pos = self->m_map78.GetStartPosition(); pos != 0; self->m_map78.GetNext(pos)) {
        int nHandle = self->m_map78.GetValueAt(pos);
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(nHandle);
    }
    self->m_map78.RemoveAll();
}

// @0x141203570
void FUN_141203570(CEquipModel* self, int nSlot, CString kName, unsigned char bWorld)
{
    void* pEnt = FUN_141200820(self);
    if (pEnt == 0)
        return;
    if (FUN_141203cf0(self, pEnt) == 0)
        return;
    void* pNode = 0;
    if (bWorld == 0)
        pNode = ((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator NiNode*());
    FUN_141203660(self, nSlot, CString(kName), pNode);
}

// Creates the effect for nSlot named kName on pNode (or defers it when the model is not loaded yet).
// @0x141203660
void FUN_141203660(CEquipModel* self, int nSlot, CString kName, void* pNode)
{
    void* pEnt = FUN_141200820(self);
    if (pEnt == 0)
        return;
    if (FUN_141203cf0(self, pEnt) == 0)
        return;
    FUN_141202dc0(self, nSlot);
    if (kName.IsEmpty())
        return;
    if (self->vfunc_20() == 0) {
        self->m_b111 = 1;
        return;
    }
    NoticeMessage kReq;
    kReq.m_strName = kName;
    (*reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&kReq.m_spNode) = (NiAVObject*)(void*)(pNode));
    kReq.m_nObject = ((Unk_EmEntity*)pEnt)->vfunc_58();
    kReq.SetActor(((GameObject*)pEnt)->FUN_14123c580());
    unsigned nHandle = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*(class Unk_EffectTarget*)(&kReq));
    if (nHandle > 0)
        self->m_map78.SetAt((Unk_EquipEffectSlot&)nSlot, nHandle);
    self->m_b111 = 0;
}

// The status text shown for the model's effect: the owner's template summary string.
// @0x141203830
CString CEquipModel::FUN_141203830()
{
    if ((*reinterpret_cast<MS2Ptr<CEquipItem>*>(&this->m_spOwner) == (CEquipItem*)0) != 0)
        return CString("");
    MS2Ptr<CItem> kId = ((class CEquipItem*)(void*)(OWNER(this)))->GetItem();
    if (kId == (CItem*)0)
        return CString("");
    Unk_EquipTpl* pTpl = (Unk_EquipTpl*)((void*)((class CEquipItem*)(void*)(OWNER(this)))->FUN_1411dc7f0());
    if (pTpl == 0)
        return CString("");
    if (!((class CItemData*)(void*)(pTpl))->FUN_14053d2f0())
        return CString("");
    if (((class CItemData*)(void*)(pTpl))->HasSkinType()) {
        void* pParent = ((void*)((class CEquipItem*)(void*)(OWNER(this)))->FUN_1411dc8c0());
        if (pParent != 0) {
            MS2Ptr<CEquipItem> spPart = ((class PC*)pParent)->FUN_141655c90(((class CItem*)(void*)(kId.operator->()))->FUN_140527a20());
            if (spPart.operator CEquipItem*() != 0) {
                MS2Ptr<CItem> kId2 = spPart->GetItem();
                if (kId2 == (CItem*)0)
                    return CString("");
                char* pTpl2 = (char*)((void*)((class CEquipItem*)(void*)(spPart.operator->()))->FUN_1411dc7f0());
                if (pTpl2 == 0)
                    return CString("");
                if (!((class CItemData*)(void*)(pTpl2))->FUN_14053d2f0())
                    return CString("");
                if (pTpl->m_nLevel >= 100) {
                    return ((class CItem*)(void*)(kId2.operator->()))->FUN_140529f60(((class CItemData*)(void*)(pTpl))->GetEquipSubtype(), ((class CItem*)(void*)(kId2.operator->()))->FUN_140526fc0(), ((class CItem*)(void*)(kId2.operator->()))->GetPlusLevel(), pTpl->m_nLevel);
                } else {
                    return ((class CItem*)(void*)(kId2.operator->()))->FUN_140529eb0();
                }
            }
        }
    }
    return ((class CItem*)(void*)(kId.operator->()))->FUN_140529eb0();
}

// Whether effects may be created for pEnt: not for the owner's entity classes flagged off.
// @0x141203cf0
bool FUN_141203cf0(CEquipModel* self, void* pEnt)
{
    if (pEnt == 0)
        return false;
    void* p = FUN_141204220(pEnt);
    if (p != 0) {
        {
            MS2Ptr<CItemData> spData((CItemData*)FUN_1412009d0(self));
            if (spData.get() != 0)
                return ((class CItemData*)(void*)(spData.operator->()))->FUN_14053ce80() ? true : false;
        }
        return false;
    }
    return true;
}

// Detaches the attach node from its parent and drops it.
// @0x141203db0
void FUN_141203db0(CEquipModel* self)
{
    if (((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator NiNode*()) != 0) {
        NiNode* pParent = (NiNode*)((void*)((class NiAVObject*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator->())))->GetParent());
        if (pParent != 0) {
            pParent->DetachChild((NiAVObject*)((void*)reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self))->operator NiNode*()));
        }
        (*reinterpret_cast<efd::SmartPointer<NiNode>*>(NODE(self)) = (NiNode*)(void*)(0));
    }
}

// Detaches every attached scene object, empties the set and reports the unequip.
// @0x141203e60
void FUN_141203e60(CEquipModel* self)
{
    EM_FOR_EACH(NiAVObjectPtr sp, self->m_unk_f8) {
        if ((*reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp) == (NiAVObject*)(void*)(0)))
            continue;
        NiNode* pParent = (NiNode*)((void*)((class NiAVObject*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator->())))->GetParent());
        if (pParent != 0)
            pParent->DetachChild((NiAVObject*)((void*)reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&sp)->operator NiAVObject*()));
    }
    self->m_unk_f8.clear();
    void* pEnt = FUN_141200820(self);
    if (pEnt != 0) {
        MS2Ptr<CItem> spItem = EQUIP(self->m_spOwner)->GetItem();
        if (((void*)((MS2Ptr<CItem>*)(void*)(&spItem))->get()) != 0)
            ((CEquipment*)((class PC*)(void*)(pEnt))->FUN_1416561a0())->FUN_1411e9fa0(((class CItem*)(void*)(spItem.operator->()))->FUN_140527a20(), self->FUN_1412029d0(),
                          ((class CItem*)(void*)(spItem.operator->()))->HasSkin(), ((class CItemData*)(void*)(((void*)((class CItem*)(void*)(spItem.operator->()))->FUN_140527840())))->FUN_14053d2b0());
    }
}

// @0x1412041d0
void* FUN_1412041d0(void* p)
{
    void* pOut = 0;
    if (p != 0 && ((Unk_EmQuery*)p)->vfunc_5(0x6200016, &pOut))
        return pOut;
    else
        return 0;
}

// @0x141204220
void* FUN_141204220(void* p)
{
    void* pOut = 0;
    if (p != 0 && ((Unk_EmQuery*)p)->vfunc_5(0x6200016, &pOut))
        return pOut;
    else
        return 0;
}

// @0x1412051d0
template <> inline MS2Ptr<INodeMovement>::MS2Ptr(const MS2Ptr& o)
{
    m_p = o.m_p;
    AddRef();
}

// @0x141205a40
void WeaponAttachTransformNode::SetUseMovement(int bUse)
{
    m_bUseMovement = bUse;
}

// @0x141205a60
void WeaponAttachTransformNode::SetMode(int nMode)
{
    m_nMode = nMode;
}

// @0x141205e30
Unk_HoldHandle Unk_AttachDummy::FUN_141205e30()
{
    return m_hold;
}

// Animation service: the display name of the sequence the entity model key maps to (the default name when none).
// @0x141206030
efd::utf8string Unk_EmModelLoader::FUN_141206030(const egf::EntityID& kId)
{
    void* pEntry;
    if (!((Unk_EmAnimAccess*)(void*)this)->ContainsEntity(kId, reinterpret_cast<Unk_EmAnimAccess::ActorEntry*&>(pEntry)))
        return efd::utf8string::NullString();
    void* pAssetData = reinterpret_cast<Unk_EmAnimAccess::AssetDataPtr*>((char*)pEntry + 0x10)->operator Unk_EmAnimAccess::AssetData*();
    if (!pAssetData)
        return efd::utf8string::NullString();
    if (!((void*)reinterpret_cast<efd::SmartPointer<NiActorManager>*>((char*)pEntry + 8)->operator NiActorManager*()))
        return efd::utf8string::NullString();
    unsigned nSeq = ((class NiActorManager*)(void*)(((void*)reinterpret_cast<efd::SmartPointer<NiActorManager>*>((char*)pEntry + 8)->operator->())))->GetTargetAnimation();
    if (nSeq == NiActorManager::INVALID_SEQUENCE_ID)
        return efd::utf8string::NullString();
    else
        return ((Unk_EmAnimAccess::AssetData*)pAssetData)->GetSequenceName(nSeq);
}

// @0x141207f40
void WeaponAttachTransformNode::SetFollowNode(NiAVObject* pNode)
{
    if (pNode != this)
        m_pFollow = pNode;
}

// @0x141207f70
void WeaponAttachTransformNode::SetBaseRotate(const NiMatrix3& kRotate)
{
    memcpy(((Unk_AttachDummy*)this)->m_aRotate, &kRotate, 0x24);
    memcpy(((Unk_AttachDummy*)this)->m_aBaseRotate, ((Unk_AttachDummy*)this)->m_aRotate, 0x24);
}

// @0x141207fb0
void FUN_141207fb0(Unk_HoldTarget* p, float f)
{
    p->m_fScale = f;
}

// @0x141207fd0
void WeaponAttachTransformNode::SetBasePosition(const NiPoint3& kPos)
{
    ((Unk_AttachDummy*)this)->m_kTranslate = m_kBasePos = kPos;
}

// The CString -> int red-black map: ATL::CRBMap<CStringA, int>'s ctor (0x141205140) and its tree's CNode dtor (0x141205550).
// They reach the CRBTree ctor 0x141205170 and the CPair dtor 0x141205570 (protected; were the FUN_ wrappers).
typedef ATL::CRBMap<CStringA, int> Unk_StrIntMap;

// Pointer holder whose dynamic initializer is the exe's .text$di 0x1400e8c90 (ctor 0x1401cd100), so it runs from
// this unit's .CRT$XCU slot.
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
#ifndef MS2_HOOK_DLL   // the exe's object at 0x143ad2288 (the hook DLL binds it)
egf::EntityID DAT_143ad2288(0);   // @0x1400e8c90
#else
extern egf::EntityID DAT_143ad2288;
#endif

// @0x141204e70
void* FUN_141204e70(void* p)
{
    return p;
}

// 0x141205140 / 0x141205550: Unk_StrIntMapInst instantiates the real ctor and (through the dtor's RemoveAll / FreeNode)
// the CNode dtor; the pins at the end bind them, the CRBTree ctor and the CPair dtor to the exe VAs.
void Unk_StrIntMapInst()
{
    Unk_StrIntMap m;
}
//
//
//
//
//
//

// @0x141205690
bool FUN_141205690(void* a, void* b)
{
    return !(*(std::vector<Unk_PartAttach>::const_iterator*)a == *(std::vector<Unk_PartAttach>::const_iterator*)b);
}

MS2_REPLACE_METHOD(0x1411FFFC0, CEquipModel, vfunc_21, 16, 0x23B2047A);
MS2_REPLACE_METHOD(0x1411FFFE0, CEquipModel, vfunc_22, 28, 0xFF723056);
MS2_REPLACE_METHOD(0x141200010, CEquipModel, vfunc_23, 41, 0xC93B86F0);
MS2_REPLACE_METHOD(0x141200070, CEquipModel, vfunc_25, 41, 0x128A418C);
MS2_REPLACE_METHOD(0x141200190, CEquipModel, vfunc_27, 57, 0xB1DE4D66);
MS2_REPLACE_METHOD(0x1412001D0, CEquipModel, vfunc_29, 22, 0x59F0B112);
MS2_REPLACE_METHOD(0x1412001F0, CEquipModel, vfunc_28, 22, 0x59F0B112);
MS2_REPLACE_METHOD(0x141200210, CEquipModel, vfunc_30, 22, 0x59F0B112);
MS2_REPLACE(0x141200820, FUN_141200820, 32, 0x724B57F1);
MS2_REPLACE(0x141200A90, FUN_141200a90, 15, 0xBBB219C9);
MS2_REPLACE(0x141200AB0, FUN_141200ab0, 15, 0xCBEE5D21);
MS2_REPLACE(0x141200AD0, FUN_141200ad0, 65, 0x078D148C);
MS2_REPLACE_METHOD(0x141200B20, CEquipModel, vfunc_31, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x141201750, CEquipModel, vfunc_32, 28, 0x2CD3DB6E);
MS2_REPLACE(0x1412018C0, FUN_1412018c0, 82, 0x44D6E731);
MS2_REPLACE(0x141201C90, FUN_141201c90, 17, 0x55511E8B);
MS2_REPLACE(0x1412021A0, FUN_1412021a0, 65, 0xCE106764);
MS2_REPLACE(0x1412021F0, FUN_1412021f0, 65, 0x6C2D7A03);
MS2_REPLACE(0x141202240, FUN_141202240, 57, 0x5F7954AD);
MS2_REPLACE_METHOD(0x141205A40, WeaponAttachTransformNode, SetUseMovement, 25, 0xED11FA2A);
MS2_REPLACE_METHOD(0x141205A60, WeaponAttachTransformNode, SetMode, 25, 0x87AE4FB6);
MS2_REPLACE_METHOD(0x141207F40, WeaponAttachTransformNode, SetFollowNode, 40, 0xF6CFED15);
MS2_REPLACE_METHOD(0x141207F70, WeaponAttachTransformNode, SetBaseRotate, 64, 0x6C076CC3);
MS2_REPLACE(0x141207FB0, FUN_141207fb0, 28, 0x2F87969E);
MS2_REPLACE_METHOD(0x141207FD0, WeaponAttachTransformNode, SetBasePosition, 60, 0x5B49E748);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cad5b0-0x142cad6f0 .text$yd
// sfr34: set<SmartPointer<NiAVObject>>::insert(value_type&&) and the non-const _Tree_comp_alloc::_Getal replace
// the FUN_141205000 / FUN_141208de0 stand-ins, which called _Insert_nohint / _Get_first / _Get_second under FUN_ twins.
// MS2-FUNCTIONAL 0x141205000: the exe passes the value through std::forward 0x1410431d0, which this toolchain's insert folds away
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@std@@_N@1@$$QEAV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x141205000
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@std@@@2@XZ 0x141208de0
// MS2-PIN: ??0?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAA@_K@Z 0x141205140 ; the real CRBMap<CStringA,int> ctor (was FUN_141205140)
// MS2-PIN: ??0?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEAA@_K@Z 0x141205170 ; the real CRBTree ctor (was the FUN_141205170 wrapper)
// MS2-PIN: ??1CNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x141205550 ; the real CNode dtor (was FUN_141205550)
// MS2-PIN: ??1CPair@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@IEAA@XZ 0x141205570 ; the real CPair dtor (was the FUN_141205570 wrapper)
