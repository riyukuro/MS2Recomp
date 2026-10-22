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
#include "equipmodel.h"
#include <efd/Matrix3.h>
#include <NiTransform.h>
#include <NiAVObject.h>
#include <string.h>
#include <vector>
#include <efd/Category.h>
#include <egf/EntityID.h>
#include "ms2/placeholder/unk_1402a9d70.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/placeholder/citem.h"

// ---- exe data ----
extern char DAT_143afa4d8;      // NiNode::ms_RTTI
extern char DAT_143afbbb0;      // NiMesh::ms_RTTI
extern char DAT_143af77a8;      // RTTI of the dummy attach node class
extern float DAT_143ac3d08;     // the engine's frame step
extern char DAT_143b01a60;      // NiPoint3::ZERO
extern char DAT_143ad2348;      // the owner's default attach-state record
extern char DAT_143ad2168;      // list of the side suffixes tried when resolving an attach point name
extern char DAT_142ec05ba;      // ""

// ---- out-of-unit callees ----
// smart pointers (MS2Ptr<Owner> at +0x28, NiPointer at +0xf0 / +0x108 / the temporaries)
void* FUN_1405a8ed0(void* sp);   void FUN_1405a85c0(void* sp);   void FUN_1405a85f0(void* sp);   void* FUN_1409849b0(void* sp);
void* FUN_140884f30(void* dst, void* src);   void FUN_140d37c50(void* sp, int n);   char FUN_140b02900(void* sp);
void* FUN_14097eb60(void* out, void* p);   void* FUN_14097eba0(void* out, void* p);   void FUN_1409fabf0(void* sp, void* p);
void* FUN_1409f7170(void* sp, void* p);   void FUN_1409f74b0(void* sp);   void FUN_1409f76f0(void* sp, void* p);
void* FUN_1409475d0(void* sp);   void* FUN_1409475f0(void* sp);   char FUN_1409f77a0(void* sp, int n);   void* FUN_1409f7cb0(void* p);
char FUN_1409edd90(void* sp, int n);   char FUN_1409a7f70(void* sp, void* p);   void* FUN_14098d0f0(void* sp);
void* FUN_1405a8e70(void* sp);   void* FUN_14098d8d0(void* rtti, void* obj);
// the owner wrapper (character / mannequin entity)
void* FUN_1411dc7a0(void* owner, void* out);   void* FUN_1411dc7f0(void* owner);   void* FUN_1411dc8c0(void* owner);
void FUN_1411dce60(void* owner, void* rec);   void FUN_1411dd280(void* owner);   void FUN_1411ddf10(void* owner, void* model);
void* FUN_1411de2e0(void* guard, void* model);   void FUN_140b02860(void* guard);
void* FUN_1403ed2d0();   void* FUN_141bd1180(void* mgr, unsigned id);   void* FUN_141bd0cc0(void* mgr);
void* FUN_1403ed280();   int FUN_1411a49c0(void* mgr, void* rec);   void FUN_1411a6060(void* mgr, int h);
void* FUN_141b6f910();   void* FUN_140999440(void* svc, void* id);   void* FUN_14123c460(void* ent, void* out);
unsigned FUN_14123c580(void* ent);
void* FUN_1416561a0(void* p);   void FUN_1411e9fa0(void* p, unsigned a, const CString& s, unsigned b, unsigned c);
void FUN_1411ea430(void* p, void* sp);   void FUN_1411ea500(void* p, void* sp);   void* FUN_141655c90(void* p, void* out, unsigned id);
void* FUN_141206030(void* svc, void* out, void* id);   char* FUN_1408ac310(void* s);   void FUN_1408a8900(void* s);
unsigned FUN_141658e60(void* ent);
// the id holder returned by FUN_1411dc7a0 and its accessors
void FUN_1401bfde0(void* p);   void FUN_1401bf970(void* out, void* p);   char FUN_1401b5240(void* p, int n);
char FUN_1401b50d0(void* p);   void* FUN_1401b52a0(void* p);   void* FUN_140203c60(void* p);   void* FUN_140203510(void* out, int n);
void* FUN_1401c0180(void* p);   char FUN_1401c0050(void* p, int n);
void* FUN_14052cd70(void* p);   void* FUN_140527840(void* p);   void* FUN_140527870(void* p);
unsigned FUN_140526b10(void* p);   unsigned FUN_140526ad0(void* p);   int FUN_140526c30(void* p);   int FUN_140527a20(void* p);
unsigned FUN_1405258b0(void* p);   unsigned FUN_140527270(void* p);   unsigned FUN_140526fc0(void* p);
char FUN_14053d2b0(void* p);   char FUN_14053d510(void* p);   char FUN_14053cfd0(void* p);   char FUN_14053cf90(void* p);
char FUN_14053ce80(void* p);   unsigned FUN_14053c620(void* p);   char FUN_14053e370(void* p);   void* FUN_14053ec70(void* p);
char FUN_1405471b0(void* p);   char FUN_14059a350(void* p);
void FUN_140529f60(void* o, CString* out, unsigned a, unsigned b, unsigned c, int d);   void FUN_140529eb0(void* o, CString* out);
void* FUN_14099eef0(void* p);   void* FUN_140a53610(void* p);   void* FUN_140a535c0(void* p);
void* FUN_1412041d0(void* p);   void* FUN_141204220(void* p);   void* FUN_1409a8b10();   void* FUN_140c77560(void* p);
void FUN_1405451a0(void* p);   int FUN_1405451c0(CString* p);
// strings / names
void* FUN_1409989e0(void* out, const char* psz);   void FUN_140984450(void* out, const char* psz);   void FUN_1409845a0(void* fs);
void* FUN_1409a8b90(void* obj);   const char* FUN_142087e50(void* name);   char FUN_140998dc0(void* name, const char* psz);
char FUN_1401c0090(CString* a, CString* b);   void FUN_1401d3700(CString* s);   char FUN_1401647e0(CString* a, CString* b);
char FUN_140184310(CString* a, void* psz);   char FUN_141068d50(void* a, const char* psz);
void* FUN_1405eb3a0(void* list);   void* FUN_1405eb3b0(void* list, void* pos);
void* FUN_14016a5c0(void* out, const char* psz, int n);   void* FUN_140298360(void* out, const char* psz, void* s);
// scene objects
void* FUN_14098cb80(void* it, void* obj);   void* FUN_14098e0d0(void* it, int n);   void FUN_14098cf00(void* it);
void FUN_140a0b300(void* obj, int b);   void* FUN_140a0b000(void* obj);
void FUN_140aacb60(void* obj, void* xf);   void FUN_140aacaa0(void* obj, const void* xf);
void* FUN_1411a3f30(void* p);   void FUN_1411a3e30(void* p);   void FUN_1411a4080(void* p);
char FUN_1409991a0(void* svc, void* key, void** pOut, int n);   void* FUN_140998e80(void* p);   void* FUN_140998e90(void* p);
void* FUN_1409f7900(void* p);   int FUN_1409a1a00(void* p);   void* FUN_1409a1a90();   void* FUN_1409a1940(void* p, void* out, int n);
void* FUN_1409a0f10(void* out, void* src);
void FUN_140a332d0(void* xf);   void* FUN_1409478e0(void* node);   void FUN_140a35c30(void* dst, void* src);
void FUN_140a35bd0(void* dst, void* src);   void* FUN_140a33de0(void* a, void* out, void* b);   void* FUN_140a33f90(void* obj);
void FUN_140a52ef0(void* rec);   void FUN_140a53190(void* rec, unsigned v);   void FUN_1405a89e0(void* rec);
void FUN_1409f7320(void* mat);   void* FUN_14097fc90(void* pt, void* out, float f);   void FUN_140ae9180(void* pt, float* out, float f);
void FUN_14027dcf0(void* out, void* pt);   void* FUN_140965c40(void* a, void* out, void* b);   void FUN_140968990(void* pt);
void* FUN_140194470(void* dst, const void* src);
void* FUN_141d18b90(void* node, void* fs);   void* FUN_14208a860(unsigned cb, unsigned n);   void* FUN_140876480(void* out, int n);
void* FUN_141068d50p(void* a, const char* psz);
double FUN_141473280(void* clock);   void* FUN_14086d260();
// game
void FUN_1411cf000(void* a);
void* FUN_141658e60p(void* ent);

#define VSLOT(o, off) ((*(void***)(o))[(off) / 8])
#define V0(R, o, off) (((R(*)(void*))VSLOT(o, off))(o))
#define V1(R, o, off, T, a) (((R(*)(void*, T))VSLOT(o, off))(o, a))
#define V2(R, o, off, T1, a, T2, b) (((R(*)(void*, T1, T2))VSLOT(o, off))(o, a, b))

#define OWNER(self) FUN_1405a8ed0(&(self)->m_spOwner)
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

// One element (0x38 bytes) of the part's attach list.
struct Unk_PartAttach
{
    char m_pad_00[8];
    CString m_strName;              // +0x08 prefix the target mesh name must start with
    CString m_strMask;              // +0x10 visible-part name that suppresses the attach
    float m_afRot[3];               // +0x18 degrees
    float m_afPos[3];               // +0x24
    float m_fScale;                 // +0x30
    char m_bFollow;                 // +0x34
    char m_bFlag;                   // +0x35
    char m_pad_36[2];
};
MS2_CHECK_SIZE(Unk_PartAttach, 0x38);

// The counted handle held at +0x140 of the attach dummy (the pointer at +8 is reference counted by 0x1411a4080).
struct Unk_HoldHandle
{
    void* m_p0;
    void* m_p8;
};

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
    CString m_astrA[4];             // +0x218 .. +0x230 (two per hand)
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
unsigned FUN_140aa6d30();   int FUN_1417e2610(unsigned p);
void* FUN_141b76c30(void* p);   void* FUN_141d19760(void* p, unsigned n);

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
void FUN_141205a40(Unk_AttachDummy* p, int n);
void FUN_141205a60(Unk_AttachDummy* p, int n);
Unk_HoldHandle* FUN_141205e30(Unk_AttachDummy* p, Unk_HoldHandle* pOut);
void FUN_141207f40(Unk_AttachDummy* p, void* pFollow);
void FUN_141207f70(Unk_AttachDummy* p, const void* pRotate);
void FUN_141207fb0(Unk_HoldTarget* p, float f);
void FUN_141207fd0(Unk_AttachDummy* p, const NiPoint3& pt);
void FUN_1411ffee0(CEquipModel* self);
void FUN_1412024f0(CEquipModel* self, NiPoint3* pPos, float* pEuler, float* pScale, void* pLocal, void* pTrans, void* pRot);
void* FUN_141200820(CEquipModel* self);
void* FUN_141200850(CEquipModel* self);
void* FUN_1412008e0(CEquipModel* self);
void* FUN_141200940(CEquipModel* self, void* out);
void* FUN_1412009d0(CEquipModel* self);
void* FUN_141200a40(CEquipModel* self, void* out);
void* FUN_141200a90(CEquipModel* self);
void* FUN_141200ab0(CEquipModel* self);
bool FUN_141200ad0(CEquipModel* self);
void FUN_141200b30(CEquipModel* self);
void FUN_141200ca0(CEquipModel* self);
void FUN_141200e30(CEquipModel* self, int n);
void FUN_141200390(CEquipModel* self, const CString& kName);
void* FUN_141201920(CEquipModel* self, void* out, CString kName);
void* FUN_141201bd0(CEquipModel* self, void* out, CString kName);
void* FUN_1412018c0(CEquipModel* self);
void FUN_1412029d0(CEquipModel* self, CString* out);
void FUN_141202bd0(CEquipModel* self);
void FUN_141202d20(CEquipModel* self, int nSlot, CString* pName, unsigned char bKeep, unsigned char bWorld);
void FUN_141202dc0(CEquipModel* self, int nSlot);
bool FUN_141202e30(CEquipModel* self, int nSlot);
void FUN_1412034e0(CEquipModel* self);
void FUN_141203570(CEquipModel* self, int nSlot, CString kName, unsigned char bWorld);
void FUN_141203660(CEquipModel* self, int nSlot, CString kName, void* pNode);
CString FUN_141203830(CEquipModel* self);
bool FUN_141203cf0(CEquipModel* self, void* pEnt);
void FUN_141203db0(CEquipModel* self);

// ---- CEquipModel ----

// @0x1411ffa10
CEquipModel::CEquipModel(MS2Ptr<Unk_EquipModelOwner> spOwner, void* p18, void* p20)
    : m_unk_18(p18), m_unk_20(p20), m_spOwner(spOwner), m_str38(""), m_nState(0), m_map78(17, 0.75f, 0.25f, 2.25f, 10),
      m_listC0(10), m_unk_f0(0), m_spNode(0), m_b110(false), m_b111(false)
{
    m_fScale44 = 1.0f;
    m_pos48 = *(NiPoint3*)&DAT_143b01a60;
    m_pos54 = *(NiPoint3*)&DAT_143b01a60;
    m_pos60 = *(NiPoint3*)&DAT_143b01a60;
    m_pos6c = *(NiPoint3*)&DAT_143b01a60;
    FUN_1409fabf0(&m_unk_f0, 0);
    if (FUN_1405a8e70(&m_spOwner) != 0) {
        if (FUN_1411dc7f0(OWNER(this)) != 0)
            m_b110 = FUN_14053e370(FUN_1411dc7f0(OWNER(this)));
    }
}

// @0x1411ffcb0
CEquipModel::~CEquipModel()
{
    FUN_140d37c50(&m_spOwner, 0);
    FUN_1409fabf0(&m_unk_f0, 0);
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
    FUN_1411ddf10(OWNER(this), this);
    FUN_140d37c50(&m_spOwner, 0);
    FUN_1409fabf0(&m_unk_f0, 0);
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
void FUN_1411ffee0(CEquipModel* self)
{
    if (self->m_b110 != 0) {
        alignas(8) char kId[24];
        void* p = FUN_140527870(FUN_1401c0180(FUN_1411dc7a0(OWNER(self), kId)));
        FUN_1401bfde0(kId);
        if (p != 0 && FUN_14059a350(p) != 0)
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
NiPoint3 CEquipModel::FUN_1412000d0()
{
    return m_pos6c;
}

// @0x141200100
void FUN_141200100(CEquipModel* self, const NiPoint3& p)
{
    self->m_pos6c = p;
}

// @0x141200130
NiPoint3 CEquipModel::FUN_141200130()
{
    return m_pos60;
}

// @0x141200160
void FUN_141200160(CEquipModel* self, const NiPoint3& p)
{
    self->m_pos60 = p;
}

// @0x141200190
void CEquipModel::vfunc_27(const char* psz)
{
    void* p = FUN_1412018c0(this);
    if (p != 0)
        FUN_140aacaa0(p, psz);
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
    alignas(8) char kId[16];
    FUN_1401bf970(kId, FUN_1412009d0(self));
    if (FUN_1401b5240(kId, 0) == 0) {
        void* pEnt = FUN_141200820(self);
        if (pEnt != 0) {
            CString kPoint("Point01");
            alignas(8) char spPoint[8];
            FUN_141201bd0(self, spPoint, kPoint);
            if (FUN_1409f77a0(spPoint, 0) == 0) {
                void* pNode = FUN_1409475d0(spPoint);
                FUN_141203660(self, 2, FUN_141203830(self), pNode);
            }
            FUN_1409f74b0(spPoint);
        }
    }
    FUN_1401b50d0(kId);
}

// Hangs the "dummy" attach nodes described by the part's attach list on the parent of the attach node.
// MS2-FUNCTIONAL: attach-list loop codegen differs (iterator COMDAT order and the Left/mask temps; 53 vs 51 callees); same calls and effects
// @0x141200390
void FUN_141200390(CEquipModel* self, const CString& kName)
{
    void* pEnt = FUN_141200820(self);
    if (pEnt == 0 || FUN_1409f77a0(NODE(self), 0) != 0)
        return;
    if (FUN_140a0b000(FUN_1409475f0(NODE(self))) == 0)
        return;
    NiAVObject* pDummy = (NiAVObject*)FUN_14098d8d0(&DAT_143af77a8, FUN_1409475d0(NODE(self)));
    Unk_AttachDummy* pD = (Unk_AttachDummy*)pDummy;
    if (pDummy == 0)
        return;
    NiTransform kXf;
    FUN_140a332d0(&kXf);
    kXf.MakeIdentity();
    FUN_140aacb60(pDummy, &kXf);
    FUN_141205a40(pD, 0);
    FUN_141205a60(pD, 0);
    Unk_PartInfo* pInfo = (Unk_PartInfo*)FUN_141200ab0(self);
    unsigned nSlot = FUN_141658e60(pEnt);
    std::vector<Unk_PartAttach>& kList = ((std::vector<Unk_PartAttach>*)pInfo->m_aLists)[nSlot];
    std::vector<Unk_PartAttach>::iterator itCur;
    itCur = kList.begin();
    while (itCur != kList.end()) {
        Unk_PartAttach* e = &*itCur;
        bool bMatch;
        if (e->m_strName.GetLength() < 1)
            bMatch = false;
        else
        {
            CString kLeft = kName.Left(e->m_strName.GetLength());
            bMatch = FUN_1401647e0(&e->m_strName, &kLeft) != 0;
        }
        if (!bMatch) {
            if (e->m_strMask.GetLength() > 0) {
                const char* pszMask = e->m_strMask;
                void* pMesh = FUN_1409a8b90(FUN_140a0b000(FUN_1409475f0(NODE(self))));
                if (FUN_141068d50(pMesh, pszMask) != 0)
                    goto L_next;
            }
            {
                efd::Matrix3 kMat;
                alignas(8) char kTmp[16];
                float afRot[3];
                FUN_1409f7320(&kMat);
                FUN_140ae9180(FUN_14097fc90(e->m_afRot, kTmp, 3.1415927f), afRot, 180.0f);
                kMat.FromEulerAnglesXYZ(afRot[0], afRot[1], afRot[2]);
                FUN_141207f70(pD, &kMat);
                NiPoint3 kPos(e->m_afPos[0], e->m_afPos[1], e->m_afPos[2]);
                FUN_141207fd0(pD, kPos);
                if (e->m_bFollow != 0) {
                    void* pRoot = FUN_14098d8d0(&DAT_143afa4d8, FUN_1409f7cb0(FUN_1412008e0(self)));
                    FUN_141207f40(pD, pRoot);
                    FUN_141205a60(pD, e->m_bFollow);
                    FUN_141205a40(pD, e->m_bFlag);
                    Unk_HoldHandle kHold;
                    Unk_HoldHandle* pObj = FUN_141205e30(pD, &kHold);
                    FUN_141207fb0((Unk_HoldTarget*)FUN_1411a3f30(pObj), e->m_fScale);
                    FUN_1411a3e30(&kHold);
                }
                pDummy->Update((float)FUN_141473280(FUN_14086d260()), true);
            }
        }
    L_next:
        ++itCur;
    }
}

// @0x141200820
void* FUN_141200820(CEquipModel* self)
{
    return FUN_14099eef0(FUN_141200850(self));
}

// @0x141200850
void* FUN_141200850(CEquipModel* self)
{
    return FUN_141bd1180(FUN_1403ed2d0(), ((CEquipItem*)OWNER(self))->FUN_1411dc7a0()->FUN_140526b10());
}

// @0x1412008e0
void* FUN_1412008e0(CEquipModel* self)
{
    alignas(8) char kId[24];
    void* pEnt = FUN_141200850(self);
    if (pEnt == 0)
        return 0;
    return FUN_140999440(FUN_141b6f910(), FUN_14123c460(pEnt, kId));
}

// @0x141200940
void* FUN_141200940(CEquipModel* self, void* out)
{
    if (FUN_140b02900(&self->m_spOwner) == 0)
        FUN_1411dc7a0(OWNER(self), out);
    else
        FUN_140203510(out, 0);
    return out;
}

// @0x1412009d0
void* FUN_1412009d0(CEquipModel* self)
{
    alignas(8) char kId[24];
    void* p = FUN_14052cd70(FUN_141200940(self, kId));
    FUN_1401bfde0(kId);
    if (p == 0)
        return 0;
    return FUN_140527840(p);
}

// @0x141200a40
void* FUN_141200a40(CEquipModel* self, void* out)
{
    FUN_140884f30(out, &self->m_spOwner);
    return out;
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
        NiAVObject* pRoot = (NiAVObject*)FUN_1409f7cb0(p);
        if (pRoot != 0) {
            pRoot->UpdateProperties();
            pRoot->UpdateEffects();
            pRoot->Update((float)(DAT_143ac3d08 + 0.001), true);
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
    if (FUN_141200ad0(self) == 0)
        self->vfunc_12();
    else
        self->vfunc_13();
    if (FUN_1405a8e70(&self->m_spOwner) != 0) {
        if (FUN_1411dc7f0(OWNER(self)) != 0) {
            if (FUN_1405471b0(FUN_14053ec70(FUN_1411dc7f0(OWNER(self)))) != 0) {
                FUN_1411dce60(OWNER(self), &DAT_143ad2348);
                FUN_1411dd280(OWNER(self));
            }
            void* pEnt = FUN_141200820(self);
            if (pEnt != 0) {
                alignas(8) char spOwn[16];
                FUN_1411ea430(FUN_1416561a0(pEnt), FUN_140884f30(spOwn, &self->m_spOwner));
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
    NiNode* pRoot = (NiNode*)FUN_14098d8d0(&DAT_143afa4d8, self->vfunc_14());
    if (pRoot == 0)
        return;
    for (NiAVObjectPtr sp : self->m_unk_f8) {
        alignas(8) char spOld[8];
        if (FUN_1409a7f70(&sp, pRoot) == 0) {
            V2(void, pRoot, 0x120, void*, FUN_1409849b0(&sp), int, 1);
        } else {
            NiNode* pParent = (NiNode*)FUN_14098d8d0(&DAT_143afa4d8, FUN_140a0b000(FUN_14098d0f0(&sp)));
            if (pParent != 0) {
                V2(void*, pParent, 0x128, void*, spOld, void*, FUN_1409849b0(&sp));
                FUN_1405a85c0(spOld);
            }
        }
    }
    void* pEnt = FUN_141200820(self);
    if (pEnt != 0) {
        alignas(8) char kId[16];
        FUN_1411dc7a0(OWNER(self), kId);
        if (FUN_14052cd70(kId) != 0) {
            void* pTpl = FUN_1401c0180(kId);
            unsigned nFlag = (unsigned char)FUN_14053d2b0(FUN_140527840(pTpl));
            unsigned nType = FUN_1405258b0(FUN_1401c0180(kId));
            CString kPart;
            FUN_1412029d0(self, &kPart);
            unsigned nId = FUN_140527a20(FUN_1401c0180(kId));
            FUN_1411e9fa0(FUN_1416561a0(pEnt), nId, kPart, nType, nFlag);
        }
        alignas(8) char spOwn[16];
        FUN_1411ea500(FUN_1416561a0(pEnt), FUN_140884f30(spOwn, &self->m_spOwner));
        FUN_1401bfde0(kId);
    }
    if (bClear != 0)
        self->m_unk_f8.clear();
    FUN_141200b30(self);
}

// Marks the meshes whose names (or, failing that, whose names without the prefix) match kName as visible/hidden.
// @0x141201180
void FUN_141201180(CEquipModel* self, CString kName)
{
    CString kMesh;
    CString kKey(kName);
    FUN_1401d3700(&kKey);
    for (NiAVObjectPtr sp : self->m_unk_f8) {
        alignas(8) char walk[0x30];
        FUN_14098cb80(walk, FUN_1409849b0(&sp));
        void* pObj;
        while ((pObj = FUN_14098e0d0(walk, 1)) != 0) {
            void* pMesh = FUN_14098d8d0(&DAT_143afbbb0, pObj);
            if (pMesh != 0) {
                kMesh = FUN_142087e50(FUN_1409a8b90(pMesh));
                FUN_1401d3700(&kMesh);
                if (FUN_1401c0090(&kMesh, &kKey) == 0) {
                    kMesh = kMesh.Mid(kKey.GetLength());
                    if (FUN_1401c0090(&kMesh, &kKey) != 0)
                        FUN_140a0b300(pMesh, 1);
                } else {
                    FUN_140a0b300(pMesh, 1);
                }
            }
        }
        FUN_14098cf00(walk);
    }
    alignas(8) char walk2[0x30];
    FUN_14098cb80(walk2, self->vfunc_14());
    void* pObj2;
    while ((pObj2 = FUN_14098e0d0(walk2, 1)) != 0) {
        void* pMesh = FUN_14098d8d0(&DAT_143afbbb0, pObj2);
        if (pMesh != 0) {
            kMesh = FUN_142087e50(FUN_1409a8b90(pMesh));
            FUN_1401d3700(&kMesh);
            if (FUN_1401c0090(&kMesh, &kKey) == 0) {
                kMesh = kMesh.Mid(kKey.GetLength());
                if (FUN_1401c0090(&kMesh, &kKey) != 0)
                    FUN_140a0b300(pMesh, 1);
            } else {
                FUN_140a0b300(pMesh, 1);
            }
        }
    }
    FUN_14098cf00(walk2);
}

// Writes pPt into the owner entity's per-slot point array at +0x60 (m_vPos).
// @0x1412014f0
void FUN_1412014f0(CEquipModel* self, void* pPt)
{
    alignas(8) char spOwn[16];
    FUN_141200a40(self, spOwn);
    if (FUN_1409edd90(spOwn, 0) == 0) {
        Unk_PartInfo* pInfo = (Unk_PartInfo*)self->m_unk_20;
        if (pInfo != 0) {
            if (pInfo->m_n24 != 0) {
                if (FUN_14053cfd0(FUN_1411dc7f0(FUN_1405a8ed0(spOwn))) != 0) {
                    alignas(8) char kId[32];
                    char* p = (char*)FUN_140527870(FUN_1401c0180(FUN_1411dc7a0(FUN_1405a8ed0(spOwn), kId)));
                    FUN_1401bfde0(kId);
                    if (p != 0)
                        FUN_140194470(p + 0x60 + pInfo->m_nSlot * 0xc, pPt);
                }
            }
        }
    }
    FUN_1405a85f0(spOwn);
}

// Same for the point array at +0x78.
// @0x141201620
void FUN_141201620(CEquipModel* self, void* pPt)
{
    alignas(8) char spOwn[16];
    FUN_141200a40(self, spOwn);
    if (FUN_1409edd90(spOwn, 0) == 0) {
        Unk_PartInfo* pInfo = (Unk_PartInfo*)self->m_unk_20;
        if (pInfo != 0) {
            if (pInfo->m_n24 != 0) {
                if (FUN_14053cfd0(FUN_1411dc7f0(FUN_1405a8ed0(spOwn))) != 0) {
                    alignas(8) char kId[32];
                    char* p = (char*)FUN_140527870(FUN_1401c0180(FUN_1411dc7a0(FUN_1405a8ed0(spOwn), kId)));
                    FUN_1401bfde0(kId);
                    if (p != 0)
                        FUN_140194470(p + 0x78 + pInfo->m_nSlot * 0xc, pPt);
                }
            }
        }
    }
    FUN_1405a85f0(spOwn);
}

// @0x141201750
void CEquipModel::vfunc_32(int n)
{
    FUN_141202bd0(this);
}

// Name of the entity class the model's entity is created from.
// @0x141201780
void* FUN_141201780(CEquipModel* self, void* out)
{
    void* pEnt = FUN_141200850(self);
    if (pEnt != 0) {
        if (FUN_140a53610(pEnt) != 0) {
            FUN_1409989e0(out, "MS2EquipItem");
            return out;
        }
        if (FUN_1412041d0(pEnt) != 0) {
            FUN_1409989e0(out, "MS2MannequinEquipItem");
            return out;
        }
        if (FUN_140a535c0(pEnt) != 0) {
            FUN_1409989e0(out, "MS2MannequinEquipItem");
            return out;
        }
        if (FUN_14099eef0(pEnt) != 0) {
            if (*((char*)FUN_140c77560(FUN_1409a8b10()) + 0x11) != 0) {
                FUN_1409989e0(out, "MS2EquipItem");
                return out;
            }
        }
    }
    FUN_1409989e0(out, "MS2EquipItemNoPhysX");
    return out;
}

// First attached scene object (the model's root), or NULL.
// @0x1412018c0
void* FUN_1412018c0(CEquipModel* self)
{
    if (self->m_unk_f8.size() == 0)
        return 0;
    return FUN_1409849b0((void*)&*self->m_unk_f8.begin());
}

// Finds the attached scene object whose name is kName (or which contains an object of that name).
// @0x141201920
void* FUN_141201920(CEquipModel* self, void* out, CString kName)
{
    for (NiAVObjectPtr sp : self->m_unk_f8) {
        if (FUN_140998dc0(FUN_1409a8b90(FUN_14098d0f0(&sp)), kName) != 0) {
            FUN_14097eb60(out, &sp);
            return out;
        }
    }
    for (NiAVObjectPtr sp : self->m_unk_f8) {
        alignas(8) char fs[8], spFound[8];
        FUN_140984450(fs, kName);
        void* pObj = FUN_14098d0f0(&sp);
        FUN_14097eba0(spFound, V1(void*, pObj, 0xa0, void*, fs));
        FUN_1409845a0(fs);
        if (FUN_1409849b0(spFound) != 0) {
            FUN_14097eb60(out, spFound);
            FUN_1405a85c0(spFound);
            return out;
        }
        FUN_1405a85c0(spFound);
    }
    FUN_14097eba0(out, 0);
    return out;
}

// @0x141201bd0
void* FUN_141201bd0(CEquipModel* self, void* out, CString kName)
{
    alignas(8) char sp[8];
    void* p = FUN_14098d8d0(&DAT_143afa4d8, FUN_1409849b0(FUN_141201920(self, sp, kName)));
    FUN_1409f7170(out, p);
    FUN_1405a85c0(sp);
    return out;
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
            NiAVObjectPtr sp(pRoot);
            kSet.insert(sp);
        }
    }
}

// Views of callees this function uses with value semantics: the part-name getter (returns the CString) and the entity
// loader's model path lookup (returns an efd::utf8string).
class CItemData;
struct Unk_EmPartSelf { CString FUN_1412029d0(); };
struct Unk_EmModelLoader { efd::utf8string FUN_141206030(const egf::EntityID& kId); };
struct Unk_EmEntity { egf::EntityID FUN_14123c460(); };

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
        kName = ((Unk_EmPartSelf*)self)->FUN_1412029d0();
    CString kCur;
    if (FUN_140a0b000(FUN_1409475f0(NODE(self))) != 0)
        kCur = FUN_142087e50(FUN_1409a8b90(FUN_140a0b000(FUN_1409475f0(NODE(self)))));
    if (kCur == kName)
        return;
    void* pRoot = FUN_1412008e0(self);
    if (pRoot == 0)
        return;
    NiNode* pNode = (NiNode*)FUN_1409f7cb0(pRoot);
    if (pNode == 0)
        return;
    NiNode* pTarget = (NiNode*)FUN_14098d8d0(&DAT_143afa4d8, pNode->GetObjectByName((const char*)kName));
    if (pTarget == 0)
        return;
    pTarget->AttachChild(self->m_spNode, true);
    CString kModel(((Unk_EmModelLoader*)FUN_141b6f910())->FUN_141206030(((Unk_EmEntity*)pEnt)->FUN_14123c460()).c_str());
    FUN_141200390(self, kModel);
    NiAVObject* pAV = (NiAVObject*)FUN_1409f7cb0(pRoot);
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
        FUN_140a35c30(pOut, FUN_140a33f90(p));
}

// @0x1412021f0
void FUN_1412021f0(CEquipModel* self, NiTransform* pOut)
{
    void* p = FUN_1412018c0(self);
    if (p != 0)
        FUN_140a35c30(pOut, FUN_1409478e0(p));
}

// @0x141202240
void FUN_141202240(CEquipModel* self, void* pXf)
{
    void* p = FUN_1412018c0(self);
    if (p != 0)
        FUN_140aacb60(p, pXf);
}

// Local transform of the first mesh among the entity's "<part><suffix>" attach points.
// @0x141202280
void FUN_141202280(CEquipModel* self, NiTransform* pOut)
{
    void* pRoot = FUN_1412008e0(self);
    if (pRoot == 0)
        return;
    NiNode* pNode = (NiNode*)FUN_1409f7cb0(pRoot);
    if (pNode == 0)
        return;
    CString kPart;
    FUN_1412029d0(self, &kPart);
    void* pos = FUN_1405eb3a0(&DAT_143ad2168);
    while (pos != 0) {
        CString kFull;
        CString* pSuffix = (CString*)FUN_1405eb3b0(&DAT_143ad2168, &pos);
        kFull.Format("%s%s", (const char*)kPart, (const char*)*pSuffix);
        alignas(8) char fs[8], sp[8];
        FUN_140984450(fs, kFull);
        FUN_14097eba0(sp, V1(void*, pNode, 0xa0, void*, fs));
        FUN_1409845a0(fs);
        if (FUN_1409f77a0(sp, 0) == 0) {
            if (FUN_14098d8d0(&DAT_143afbbb0, FUN_1409849b0(sp)) != 0) {
                FUN_140a35c30(pOut, FUN_140a33f90(FUN_14098d0f0(sp)));
                FUN_1405a85c0(sp);
                return;
            }
        }
        FUN_1405a85c0(sp);
    }
}

// @0x141202480
void FUN_141202480(CEquipModel* self, NiPoint3* pPos, float* pEuler, void* pLocal, void* pTrans, void* pRot)
{
    float fScale = 1.0f;
    FUN_1412024f0(self, pPos, pEuler, &fScale, pLocal, pTrans, pRot);
}

// World position / Euler angles (degrees) / scale of the named attach point of the loaded model.
// @0x1412024f0
void FUN_1412024f0(CEquipModel* self, NiPoint3* pPos, float* pEuler, float* pScale, void* pLocal, void* pTrans, void* pRot)
{
    alignas(8) char kId[32];
    unsigned nId = FUN_140526b10(FUN_1401c0180(FUN_1411dc7a0(OWNER(self), kId)));
    void* pEnt = FUN_141bd1180(FUN_1403ed2d0(), nId);
    FUN_1401bfde0(kId);
    if (pEnt == 0)
        return;
    alignas(8) char kEntId[24];
    void* pActor = FUN_140999440(FUN_141b6f910(), FUN_14123c460(pEnt, kEntId));
    if (pActor == 0 || FUN_1409f7cb0(pActor) == 0)
        return;
    alignas(8) char fs[8];
    void* pObj;
    {
        CString kPart;
        FUN_1412029d0(self, &kPart);
        FUN_140984450(fs, kPart);
        pObj = V1(void*, FUN_1409f7cb0(pActor), 0xa0, void*, fs);
        FUN_1409845a0(fs);
    }
    if (pObj == 0)
        return;
    void* pAttach = FUN_14098d8d0(&DAT_143afa4d8, pObj);
    if (pAttach == 0)
        return;
    void* pRoot = FUN_1412018c0(self);
    if (pRoot == 0)
        return;
    NiTransform kXf;
    FUN_140a332d0(&kXf);
    if (pRot == 0)
        FUN_140a35c30(&kXf, FUN_140a33f90(pRoot));
    else
        FUN_140a35c30(&kXf, pRot);
    FUN_140194470(pTrans, &kXf.m_Translate);
    alignas(8) char kWorld[0x34];
    memcpy(kWorld, FUN_1409478e0(pAttach), 0x34);
    if (FUN_140a0b000(pRoot) != 0)
        FUN_140a35c30(kWorld, FUN_1409478e0(FUN_140a0b000(pRoot)));
    alignas(8) char kTmp[0x38];
    FUN_140a35bd0(&kXf, FUN_140a33de0(kWorld, kTmp, FUN_140a33f90(pRoot)));
    FUN_140194470(pPos, &kXf.m_Translate);
    alignas(8) char kDelta[16], kLen[20];
    FUN_140194470(pLocal, FUN_140965c40(pPos, kDelta, kLen));
    FUN_140968990(pLocal);
    kXf.m_Rotate.ToEulerAnglesXYZ(pEuler[0], pEuler[1], pEuler[2]);
    pEuler[0] = (pEuler[0] * 180.0f) / 3.1415927f;
    pEuler[1] = (pEuler[1] * 180.0f) / 3.1415927f;
    pEuler[2] = (-pEuler[2] * 180.0f) / 3.1415927f;
    *pScale = kXf.m_fScale;
}

// @0x1412028f0
CString CEquipModel::FUN_1412028f0()
{
    return m_str38;
}

// @0x141202940
void FUN_141202940(CEquipModel* self)
{
    alignas(8) char kId[24];
    void* p = FUN_14052cd70(FUN_141200940(self, kId));
    FUN_1401bfde0(kId);
    if (p != 0) {
        if (FUN_14053d510(FUN_140527840(p)) != 0) {
            FUN_140526c30(p);
            return;
        }
    }
    FUN_1405451a0(self->m_unk_18);
}

// The part's name; the left/right counterpart is swapped in for the second hand's weapon.
// @0x1412029d0
void FUN_1412029d0(CEquipModel* self, CString* pOut)
{
    alignas(8) char kId[32];
    void* p = FUN_14052cd70(FUN_141200940(self, kId));
    FUN_1401bfde0(kId);
    if (p != 0) {
        if (FUN_14053d510(FUN_140527840(p)) != 0) {
            CString kName(((Unk_PartInfo*)self->m_unk_20)->m_strName);
            if (FUN_140526c30(p) == 4) {
                int nL = kName.Replace("_L_", "_R_");
                int nS = kName.Replace(" L ", " R ");
                if (nL + nS == 0) {
                    kName.Replace("_R_", "_L_");
                    kName.Replace(" R ", " L ");
                }
            }
            new (pOut) CString(kName);
            return;
        }
    }
    new (pOut) CString(((Unk_PartInfo*)self->m_unk_20)->m_strName);
}

// @0x141202b70
unsigned FUN_141202b70(CEquipModel* self)
{
    CString kName;
    FUN_1412029d0(self, &kName);
    return FUN_1405451c0(&kName);
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
    Unk_EquipTpl* pTpl = (Unk_EquipTpl*)FUN_1411dc7f0(OWNER(self));
    if (pTpl == 0)
        return;
    if (V0(int, pEnt, 0x208) == 0) {
        FUN_141202d20(self, 0, &pTpl->m_astrA[0], pTpl->m_bFlagA, 0);
        FUN_141202d20(self, 1, &pTpl->m_astrA[2], pTpl->m_bFlagB, 1);
    } else {
        FUN_141202d20(self, 0, &pTpl->m_astrA[1], pTpl->m_bFlagA, 0);
        FUN_141202d20(self, 1, &pTpl->m_astrA[3], pTpl->m_bFlagB, 1);
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
        FUN_1411a6060(FUN_1403ed280(), nHandle);
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
    if (FUN_1409475d0(NODE(self)) != 0)
        return;
    if (FUN_1409edd90(&self->m_spOwner, 0) != 0)
        return;
    if (self->m_unk_20 == 0)
        return;
    alignas(8) char kId[16];
    FUN_1411dc7a0(OWNER(self), kId);
    if (FUN_1401c0050(kId, 0) == 0) {
        void* pRoot = FUN_1412008e0(self);
        if (pRoot != 0) {
            NiNode* pModel = (NiNode*)FUN_1409f7cb0(pRoot);
            if (pModel != 0) {
                alignas(8) char fs[8];
                FUN_140984450(fs, *pName);
                NiNode* pHost = (NiNode*)FUN_14098d8d0(&DAT_143afa4d8, V1(void*, pModel, 0xa0, void*, fs));
                FUN_1409845a0(fs);
                if (pHost != 0) {
                    int nType = FUN_140526c30(FUN_1401c0180(kId));
                    if (nType == 4 || nType == 5) {
                        const char* pszNode = (nType == 4) ? "Weapon_Attach_TransformLH" : "Weapon_Attach_TransformRH";
                        CString kNode(pszNode);
                        alignas(8) char kPool[8];
                        void* pMem = FUN_14208a860(0x188, *(unsigned*)FUN_140876480(kPool, 0));
                        void* pNew = pMem ? FUN_141b76c30(pMem) : 0;
                        alignas(8) char fs2[8];
                        FUN_140984450(fs2, kNode);
                        FUN_141d18b90(pNew, fs2);
                        FUN_1409845a0(fs2);
                        V2(void, pHost, 0x120, void*, pNew, int, 0);
                        FUN_1409f76f0(NODE(self), pNew);
                        void* pEnt = FUN_141200820(self);
                        if (pEnt != 0) {
                            alignas(8) char kEntId[8], kTmp[32];
                            CString kModel(FUN_1408ac310(FUN_141206030(FUN_141b6f910(), kTmp, FUN_14123c460(pEnt, kEntId))));
                            FUN_1408a8900(kTmp);
                            FUN_141200390(self, kModel);
                        }
                    } else {
                        CString kPre;
                        FUN_14016a5c0(&kPre, *pName, 0);
                        CString kTag;
                        FUN_140298360(&kTag, "Equip_Attach_Transform", &kPre);
                        alignas(8) char kPool[8];
                        void* pMem = FUN_14208a860(0x130, *(unsigned*)FUN_140876480(kPool, 0));
                        void* pNew = pMem ? FUN_141d19760(pMem, 0) : 0;
                        alignas(8) char fs2[8];
                        FUN_140984450(fs2, kTag);
                        FUN_141d18b90(pNew, fs2);
                        FUN_1409845a0(fs2);
                        V2(void, pHost, 0x120, void*, pNew, int, 0);
                        FUN_1409f76f0(NODE(self), pNew);
                    }
                }
            }
        }
    }
    FUN_1401bfde0(kId);
}

// True when the model should be created for the local view: preview/cinematic scene types or the owner's own entity.
// @0x1412033e0
bool FUN_1412033e0(CEquipModel* self)
{
    if (FUN_1417e2610(FUN_140aa6d30()) == 0x620000d)
        return true;
    if (FUN_1417e2610(FUN_140aa6d30()) == 0x6200018)
        return true;
    void* pLocal = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pLocal == 0)
        return false;
    alignas(8) char kId[24];
    unsigned nOwner = FUN_140526ad0(FUN_1401c0180(FUN_1411dc7a0(OWNER(self), kId)));
    bool b = nOwner == FUN_14123c580(pLocal);
    FUN_1401bfde0(kId);
    return b;
}

// Releases every effect bound to a slot and empties the map.
// @0x1412034e0
void FUN_1412034e0(CEquipModel* self)
{
    for (POSITION pos = self->m_map78.GetStartPosition(); pos != 0; self->m_map78.GetNext(pos)) {
        int nHandle = self->m_map78.GetValueAt(pos);
        FUN_1411a6060(FUN_1403ed280(), nHandle);
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
        pNode = FUN_1409475d0(NODE(self));
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
    alignas(8) char rec[0x78];
    FUN_140a52ef0(rec);
    *(CString*)rec = kName;
    FUN_1409fabf0(rec + 0x10, pNode);
    *(int*)(rec + 8) = V0(int, pEnt, 0x1d0);
    FUN_140a53190(rec, FUN_14123c580(pEnt));
    int nHandle = FUN_1411a49c0(FUN_1403ed280(), rec);
    if (nHandle != 0)
        self->m_map78.SetAt((Unk_EquipEffectSlot)nSlot, nHandle);
    self->m_b111 = 0;
    FUN_1405a89e0(rec);
}

// The status text shown for the model's effect: the owner's template summary string.
// @0x141203830
CString FUN_141203830(CEquipModel* self)
{
    if (FUN_1409edd90(&self->m_spOwner, 0) != 0)
        return CString("");
    alignas(8) char kId[16];
    FUN_1411dc7a0(OWNER(self), kId);
    if (FUN_1401c0050(kId, 0) != 0) {
        CString kEmpty("");
        FUN_1401bfde0(kId);
        return kEmpty;
    }
    Unk_EquipTpl* pTpl = (Unk_EquipTpl*)FUN_1411dc7f0(OWNER(self));
    if (pTpl == 0) {
        CString kEmpty("");
        FUN_1401bfde0(kId);
        return kEmpty;
    }
    CString kResult;
    if (FUN_140a53610(pTpl) == 0) {
        kResult = "";
    } else if (FUN_14053cf90(pTpl) != 0) {
        void* pParent = FUN_1411dc8c0(OWNER(self));
        if (pParent != 0) {
            alignas(8) char spPart[16];
            FUN_141655c90(pParent, spPart, FUN_140527a20(FUN_1401c0180(kId)));
            if (FUN_1405a8e70(spPart) != 0) {
                alignas(8) char kId2[16];
                FUN_1411dc7a0(FUN_1405a8ed0(spPart), kId2);
                char* pTpl2 = (char*)FUN_1411dc7f0(FUN_1405a8ed0(spPart));
                if (FUN_1401c0050(kId2, 0) != 0 || pTpl2 == 0 || FUN_140a53610(pTpl2) == 0) {
                    FUN_1401bfde0(kId2);
                    FUN_1405a85f0(spPart);
                    FUN_1401bfde0(kId);
                    return CString("");
                }
                if (pTpl->m_nLevel >= 100) {
                    unsigned nA = FUN_140527270(FUN_1401c0180(kId2));
                    unsigned nB = FUN_140526fc0(FUN_1401c0180(kId2));
                    unsigned nC = FUN_14053c620(pTpl);
                    CString kOut;
                    FUN_140529f60(FUN_1401c0180(kId2), &kOut, nC, nB, nA, pTpl->m_nLevel);
                    FUN_1401bfde0(kId2);
                    FUN_1405a85f0(spPart);
                    FUN_1401bfde0(kId);
                    return kOut;
                }
                CString kOut;
                FUN_140529eb0(FUN_1401c0180(kId2), &kOut);
                FUN_1401bfde0(kId2);
                FUN_1405a85f0(spPart);
                FUN_1401bfde0(kId);
                return kOut;
            }
            FUN_1405a85f0(spPart);
        }
        CString kOut;
        FUN_140529eb0(FUN_1401c0180(kId), &kOut);
        FUN_1401bfde0(kId);
        return kOut;
    } else {
        kResult = "";
    }
    FUN_1401bfde0(kId);
    return kResult;
}

// Whether effects may be created for pEnt: not for the owner's entity classes flagged off.
// @0x141203cf0
bool FUN_141203cf0(CEquipModel* self, void* pEnt)
{
    if (pEnt == 0)
        return false;
    if (FUN_141204220(pEnt) == 0)
        return true;
    alignas(8) char kId[32];
    FUN_1401bf970(kId, FUN_1412009d0(self));
    if (FUN_140203c60(kId) == 0) {
        FUN_1401b50d0(kId);
        return false;
    }
    char c = FUN_14053ce80(FUN_1401b52a0(kId));
    FUN_1401b50d0(kId);
    return c != 0;
}

// Detaches the attach node from its parent and drops it.
// @0x141203db0
void FUN_141203db0(CEquipModel* self)
{
    if (FUN_1409475d0(NODE(self)) != 0) {
        NiNode* pParent = (NiNode*)FUN_140a0b000(FUN_1409475f0(NODE(self)));
        if (pParent != 0) {
            alignas(8) char spOld[24];
            V2(void*, pParent, 0x128, void*, spOld, void*, FUN_1409475d0(NODE(self)));
            FUN_1405a85c0(spOld);
        }
        FUN_1409f76f0(NODE(self), 0);
    }
}

// Detaches every attached scene object, empties the set and reports the unequip.
// @0x141203e60
void FUN_141203e60(CEquipModel* self)
{
    for (NiAVObjectPtr sp : self->m_unk_f8) {
        alignas(8) char spOld[24];
        if (FUN_1409a7f70(&sp, 0) == 0) {
            NiNode* pParent = (NiNode*)FUN_140a0b000(FUN_14098d0f0(&sp));
            if (pParent != 0) {
                V2(void*, pParent, 0x128, void*, spOld, void*, FUN_1409849b0(&sp));
                FUN_1405a85c0(spOld);
            }
        }
    }
    self->m_unk_f8.clear();
    void* pEnt = FUN_141200820(self);
    if (pEnt != 0) {
        alignas(8) char kId[16];
        FUN_1411dc7a0(OWNER(self), kId);
        if (FUN_14052cd70(kId) != 0) {
            unsigned nFlag = (unsigned char)FUN_14053d2b0(FUN_140527840(FUN_1401c0180(kId)));
            unsigned nType = FUN_1405258b0(FUN_1401c0180(kId));
            CString kPart;
            FUN_1412029d0(self, &kPart);
            unsigned nId = FUN_140527a20(FUN_1401c0180(kId));
            FUN_1411e9fa0(FUN_1416561a0(pEnt), nId, kPart, nType, nFlag);
        }
        FUN_1401bfde0(kId);
    }
}

// @0x1412041d0
void* FUN_1412041d0(void* p)
{
    void* pOut = 0;
    if (p == 0 || ((char(*)(void*, unsigned, void**))VSLOT(p, 0x28))(p, 0x6200016, &pOut) == 0)
        pOut = 0;
    return pOut;
}

// @0x141204220
void* FUN_141204220(void* p)
{
    void* pOut = 0;
    if (p == 0 || ((char(*)(void*, unsigned, void**))VSLOT(p, 0x28))(p, 0x6200016, &pOut) == 0)
        pOut = 0;
    return pOut;
}

// @0x1412051d0
Unk_HoldHandle* FUN_1412051d0(Unk_HoldHandle* pDst, const Unk_HoldHandle* pSrc)
{
    pDst->m_p8 = pSrc->m_p8;
    FUN_1411a4080(pDst);
    return pDst;
}

// @0x141205a40
void FUN_141205a40(Unk_AttachDummy* p, int n)
{
    p->m_nFlag = n;
}

// @0x141205a60
void FUN_141205a60(Unk_AttachDummy* p, int n)
{
    p->m_nMode = n;
}

// @0x141205e30
Unk_HoldHandle* FUN_141205e30(Unk_AttachDummy* p, Unk_HoldHandle* pOut)
{
    FUN_1412051d0(pOut, &p->m_hold);
    return pOut;
}

// Animation service: the display name of the sequence the entity model key maps to (the default name when none).
// @0x141206030
void* FUN_141206030(void* pSvc, void* pOut, void* pKey)
{
    void* pEntry;
    if (FUN_1409991a0(pSvc, pKey, &pEntry, 0) == 0) {
        FUN_1409a0f10(pOut, FUN_1409a1a90());
    } else {
        void* pModel = FUN_140998e80((char*)pEntry + 0x10);
        if (pModel == 0) {
            FUN_1409a0f10(pOut, FUN_1409a1a90());
        } else if (FUN_140998e90((char*)pEntry + 8) == 0) {
            FUN_1409a0f10(pOut, FUN_1409a1a90());
        } else {
            int nSeq = FUN_1409a1a00(FUN_1409f7900((char*)pEntry + 8));
            if (nSeq == -2)
                FUN_1409a0f10(pOut, FUN_1409a1a90());
            else
                FUN_1409a1940(pModel, pOut, nSeq);
        }
    }
    return pOut;
}

// @0x141207f40
void FUN_141207f40(Unk_AttachDummy* p, void* pFollow)
{
    if (pFollow != p)
        p->m_pFollow = pFollow;
}

// @0x141207f70
void FUN_141207f70(Unk_AttachDummy* p, const void* pRotate)
{
    memcpy(p->m_aRotate, pRotate, 0x24);
    memcpy(p->m_aBaseRotate, p->m_aRotate, 0x24);
}

// @0x141207fb0
void FUN_141207fb0(Unk_HoldTarget* p, float f)
{
    p->m_fScale = f;
}

// @0x141207fd0
void FUN_141207fd0(Unk_AttachDummy* p, const NiPoint3& pt)
{
    p->m_kTranslate = p->m_kBasePos = pt;
}

// Out-of-range template glue, kept as plain functions.
void FUN_1401cd100(void* p, int n);
void* FUN_141208da0(void* p);
void* FUN_141208dc0(void* p);
void FUN_141205170(void* a, void* b);
void FUN_141205570(void* p);
bool FUN_141205640(void* a, void* b);
void* FUN_141204a10(void* a, void* b, void* c, void* d, char e);
void* FUN_1410431d0(void* p);
extern char DAT_143ad2288[];

// @0x1400e8c90
void FUN_1400e8c90()
{
    FUN_1401cd100(DAT_143ad2288, 0);
}

// @0x141204e70
void* FUN_141204e70(void* p)
{
    return p;
}

// @0x141205000
void* FUN_141205000(void* a, void* b, void* c, char d)
{
    FUN_141204a10(a, b, 0, FUN_1410431d0(c), d);
    return b;
}

// @0x141205140
void* FUN_141205140(void* a, void* b)
{
    FUN_141205170(a, b);
    return a;
}

// @0x141205550
void FUN_141205550(void* p)
{
    FUN_141205570(p);
}

// @0x141205690
bool FUN_141205690(void* a, void* b)
{
    return !FUN_141205640(a, b);
}

// @0x141208de0
void* FUN_141208de0(void* p)
{
    return FUN_141208da0(FUN_141208dc0(p));
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
MS2_REPLACE(0x141205A40, FUN_141205a40, 25, 0xED11FA2A);
MS2_REPLACE(0x141205A60, FUN_141205a60, 25, 0x87AE4FB6);
MS2_REPLACE(0x141207F40, FUN_141207f40, 40, 0xF6CFED15);
MS2_REPLACE(0x141207F70, FUN_141207f70, 64, 0x6C076CC3);
MS2_REPLACE(0x141207FB0, FUN_141207fb0, 28, 0x2F87969E);
MS2_REPLACE(0x141207FD0, FUN_141207fd0, 60, 0x5B49E748);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cad5b0-0x142cad6f0 .text$yd
