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
#include <NiActorManager.h>
#include <string.h>
#include <vector>
#include <efd/Category.h>
#include <egf/EntityID.h>
#include "ms2/placeholder/unk_1402a9d70.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/effectquery.h"

// ---- exe data ----
extern char DAT_143afa4d8;      // NiNode::ms_RTTI
extern char DAT_143afbbb0;      // NiMesh::ms_RTTI
extern char DAT_143af77a8;      // RTTI of the dummy attach node class
extern float DAT_143ac3d08;     // the engine's frame step
extern char DAT_143b01a60;      // NiPoint3::ZERO
// 0x143ad2348 is s_strWillUpdatePos (constructed in .text$di 0x1400e8b40); the data_bss_game blob of that name never is
extern ATL::CAtlList<CString> s_meshSuffixes; // equipment.cpp: side suffixes tried when resolving an attach point name
extern char DAT_142ec05ba;      // ""

// ---- out-of-unit callees ----
// smart pointers (MS2Ptr<Owner> at +0x28, NiPointer at +0xf0 / +0x108 / the temporaries)
void* FUN_1405a8ed0(void* sp);   void FUN_1405a85c0(void* sp);   void FUN_1405a85f0(void* sp);   void* FUN_1409849b0(void* sp);
void* FUN_140884f30(void* dst, void* src);   void FUN_140d37c50(void* sp, int n);   bool FUN_140b02900(void* sp);
void* FUN_14097eb60(void* out, void* p);   void* FUN_14097eba0(void* out, void* p);   void FUN_1409fabf0(void* sp, void* p);
void* FUN_1409f7170(void* sp, void* p);   void FUN_1409f74b0(void* sp);   void FUN_1409f76f0(void* sp, void* p);
void* FUN_1409475d0(void* sp);   void* FUN_1409475f0(void* sp);   bool FUN_1409f77a0(void* sp, int n);   void* FUN_1409f7cb0(void* p);
bool FUN_1409edd90(void* sp, int n);   bool FUN_1409a7f70(void* sp, void* p);   void* FUN_14098d0f0(void* sp);
void* FUN_1405a8e70(void* sp);   void* FUN_14098d8d0(void* rtti, void* obj);
// the owner wrapper (character / mannequin entity)
void* FUN_1411dc7a0(void* owner, void* out);void FUN_1411dce60(void* owner, void* rec);void* FUN_1411de2e0(void* guard, void* model);   void FUN_140b02860(void* guard);
void* FUN_1403ed2d0();class WorldService   // C3: member view for the former free stand-ins
{
public:
    class Unk_WsC_GameObj* FUN_141bd1180(int);
};
   void* FUN_141bd0cc0(void* mgr);
void* FUN_1403ed280();class CEffectService   // C3: member view for the former free stand-ins
{
public:
    unsigned int FUN_1411a49c0(class Unk_EffectTarget&);
public:
    void FUN_1411a6060(unsigned int);   // C3: was free FUN_1411a6060
};
void* FUN_141b6f910();   void* FUN_140999440(void* svc, void* id);   void* FUN_14123c460(void* ent, void* out);
void* FUN_140999440(void* svc, const egf::EntityID& kId);
struct Unk_EmModelLoader { efd::utf8string FUN_141206030(const egf::EntityID& kId); };
unsigned FUN_14123c580(void* ent);
class PC   // C3: member view for the former free stand-ins
{
public:
    struct Unk_PCEquipSet* FUN_1416561a0();
};
   void FUN_1411e9fa0(void* p, unsigned a, const CString& s, unsigned b, unsigned c);
void FUN_1411ea430(void* p, MS2Ptr<Unk_EquipModelOwner> sp);   void FUN_1411ea500(void* p, MS2Ptr<Unk_EquipModelOwner> sp);   void* FUN_141655c90(void* p, void* out, unsigned id);
unsigned FUN_141658e60(void* ent);
// the id holder returned by FUN_1411dc7a0 and its accessors
void FUN_1401bfde0(void* p);   void FUN_1401bf970(void* out, void* p);   char FUN_1401b5240(void* p, int n);
char FUN_1401b50d0(void* p);   void* FUN_1401b52a0(void* p);   void* FUN_140203c60(void* p);   void* FUN_140203510(void* out, int n);
void* FUN_1401c0180(void* p);   bool FUN_1401c0050(void* p, int n);
unsigned FUN_140526b10(void* p);   unsigned __int64 FUN_140526ad0(void* p);class CItemData   // C3: member view for the former free stand-ins
{
public:
    int FUN_14053c620();
    bool FUN_14053ce80();
    bool FUN_14053cfd0();
    bool FUN_14053d2b0();
    bool FUN_14053d2f0();
    bool FUN_14053d510();
    bool FUN_14053e370();
};
   char FUN_14053cf90(void* p);
   void* FUN_14053ec70(void* p);
class ItemModelHead   // C3: member view for the former free stand-ins
{
public:
    bool FUN_1405471b0();
};
class CItemExtraData   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14059a350();
};
void FUN_140529f60(void* o, CString* out, unsigned a, unsigned b, unsigned c, int d);   void FUN_140529eb0(void* o, CString* out);
void* FUN_14099eef0(void* p);   void* FUN_140a53610(void* p);   void* FUN_140a535c0(void* p);
void* FUN_1412041d0(void* p);   void* FUN_141204220(void* p);   void* FUN_1409a8b10();   void* FUN_140c77560(void* p);
class ModelGroup   // C3: member view for the former free stand-ins
{
public:
    int FUN_1405451a0() const;
};
    int FUN_1405451c0(const CString& s);
// strings / names
void* FUN_1409989e0(void* out, const char* psz);   void FUN_140984450(void* out, const char* psz);   void FUN_1409845a0(void* fs);
void* FUN_1409a8b90(void* obj);   const char* FUN_142087e50(void* name);   bool FUN_140998dc0(void* name, const char* psz);
bool FUN_1401c0090(CString* a, CString* b);   void FUN_1401d3700(CString* s);
char FUN_140184310(CString* a, void* psz);
   void* FUN_1405eb3b0(void* list, void* pos);
void* FUN_14016a5c0(void* out, const char* psz, int n);   void* FUN_140298360(void* out, const char* psz, void* s);
// scene objects
// Breadth-first walk over an object's subtree (0x30 bytes, like Unk_NodeWalker in uichaoslightdialog.h).
class Unk_MeshWalker
{
public:
    Unk_MeshWalker(void* pRoot);                                    // 0x14098cb80
    ~Unk_MeshWalker();                                              // 0x14098cf00
    void* FUN_14098e0d0(bool bChildren);                            // 0x14098e0d0 next object, NULL at the end
private:
    void* m_a[6];
};
   void* FUN_140a0b000(void* obj);
void FUN_140aacb60(void* obj, void* xf);void* FUN_1411a3f30(void* p);   void FUN_1411a3e30(void* p);   void FUN_1411a4080(void* p);
bool FUN_1409991a0(void* svc, const egf::EntityID& kId, void** pOut);   void* FUN_140998e80(void* p);   void* FUN_140998e90(void* p);
void* FUN_1409f7900(void* p);   struct Unk_EmAssetData { efd::utf8string FUN_1409a1940(unsigned n) const; };

   void FUN_140a35c30(void* dst, void* src);
void FUN_140a35bd0(void* dst, void* src);   void* FUN_140a33de0(void* a, void* out, void* b);void* FUN_140965c40(void* a, void* out, void* b);class Vector3   // C3: member view for the former free stand-ins
{
public:
    float FUN_140968990();
};
void* FUN_140194470(void* dst, const void* src);
void* FUN_141d18b90(void* node, void* fs);   void* FUN_14208a860(unsigned cb, unsigned n);   void* FUN_140876480(void* out, int n);
void* FUN_141068d50p(void* a, const char* psz);
double FUN_141473280(void* clock);   void* FUN_14086d260();
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
    egf::EntityID FUN_14123c460();
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

#define OWNER(self) FUN_1405a8ed0(&(self)->m_spOwner)
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
struct Unk_NiPt3 { float x, y, z; Unk_NiPt3(const void* efdPoint); };   // NiPoint3(const efd::Point3&) 0x14027dcf0

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

// The counted handle held at +0x140 of the attach dummy (the pointer at +8 is reference counted by 0x1411a4080).
struct Unk_HoldHandle
{
    Unk_HoldHandle(const Unk_HoldHandle& o);    // 0x1412051d0
    ~Unk_HoldHandle();                          // 0x1411a3e30
    void* FUN_1411a3f30();                      // 0x1411a3f30 operator->
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
void* FUN_140aa6d30();   int FUN_1417e2610(void* p);   // CStateService singleton (64-bit pointer)
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
void FUN_141207f40(Unk_AttachDummy* p, void* pFollow);
void FUN_141207f70(Unk_AttachDummy* p, const void* pRotate);
void FUN_141207fb0(Unk_HoldTarget* p, float f);
void FUN_141207fd0(Unk_AttachDummy* p, const NiPoint3& pt);
void FUN_1411ffee0(CEquipModel* self, double fTime);
void FUN_1412024f0(CEquipModel* self, NiPoint3* pPos, float* pEuler, float* pScale, void* pLocal, void* pTrans, void* pRot);
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
    if (FUN_1405a8e70(&m_spOwner) ? true : false) {
        if (((void*)((class CEquipItem*)(void*)(OWNER(this)))->FUN_1411dc7f0()) != 0)
            m_b110 = ((class CItemData*)(void*)(((void*)((class CEquipItem*)(void*)(OWNER(this)))->FUN_1411dc7f0())))->FUN_14053e370();
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
    ((class CEquipItem*)(void*)(OWNER(this)))->FUN_1411ddf10((class CEquipModel*)(this));
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
void FUN_1411ffee0(CEquipModel* self, double fTime)
{
    if (self->m_b110 != 0) {
        void* p = ((void*)((class CItem*)(void*)(EQUIP(self->m_spOwner)->GetItem().operator->()))->FUN_140527870());
        if (p == 0)
            return;
        if (((class CItemExtraData*)(void*)(p))->FUN_14059a350())
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
    if (FUN_1409f77a0(&spPoint, 0))
        return;
    FUN_141203660(self, 2, self->FUN_141203830(), FUN_1409475d0(&spPoint));
}

// Hangs the "dummy" attach nodes described by the part's attach list on the parent of the attach node.
// @0x141200390
void FUN_141200390(CEquipModel* self, const CString& kName)
{
    void* pEnt = FUN_141200820(self);
    if (pEnt == 0)
        return;
    if (FUN_1409f77a0(NODE(self), 0) || FUN_140a0b000(FUN_1409475f0(NODE(self))) == 0)
        return;
    NiAVObject* pDummy = (NiAVObject*)FUN_14098d8d0(&DAT_143af77a8, FUN_1409475d0(NODE(self)));
    if (pDummy == 0)
        return;
    NiTransform kXf;
    kXf.MakeIdentity();
    FUN_140aacb60(pDummy, &kXf);
    FUN_141205a40((Unk_AttachDummy*)pDummy, 0);
    FUN_141205a60((Unk_AttachDummy*)pDummy, 0);
    Unk_PartInfo* pInfo = (Unk_PartInfo*)FUN_141200ab0(self);
    std::vector<Unk_PartAttach>& kList = ((std::vector<Unk_PartAttach>*)pInfo->m_aLists)[FUN_141658e60(pEnt)];
    std::vector<Unk_PartAttach>::iterator itCur;
    for (itCur = kList.begin(); itCur != kList.end(); ++itCur) {
        Unk_PartAttach* e = itCur.operator->();
        bool bOther = e->m_strName.GetLength() > 0 && e->m_strName != kName.Left(e->m_strName.GetLength());
        if (bOther)
            continue;
        if (e->m_strMask.GetLength() > 0
            && *(NiFixedString*)FUN_1409a8b90(FUN_140a0b000(FUN_1409475f0(NODE(self)))) != (const char*)e->m_strMask)
            continue;
        efd::Matrix3 kMat;
        efd::Point3 kRot = *(const efd::Point3*)e->m_afRot * 3.1415927f / 180.0f;
        kMat.FromEulerAnglesXYZ(kRot.x, kRot.y, kRot.z);
        FUN_141207f70((Unk_AttachDummy*)pDummy, &kMat);
        Unk_NiPt3 kPos(e->m_afPos);
        FUN_141207fd0((Unk_AttachDummy*)pDummy, *(NiPoint3*)&kPos);
        if (e->m_bFollow) {
            void* pRoot = FUN_14098d8d0(&DAT_143afa4d8, FUN_1409f7cb0(FUN_1412008e0(self)));
            FUN_141207f40((Unk_AttachDummy*)pDummy, pRoot);
            FUN_141205a60((Unk_AttachDummy*)pDummy, e->m_bFollow);
            FUN_141205a40((Unk_AttachDummy*)pDummy, e->m_bFlag);
            FUN_141207fb0((Unk_HoldTarget*)((Unk_AttachDummy*)pDummy)->FUN_141205e30().FUN_1411a3f30(), e->m_fScale);
        }
        pDummy->Update((float)FUN_141473280(FUN_14086d260()), true);
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
    return ((void*)((class WorldService*)(void*)(FUN_1403ed2d0()))->FUN_141bd1180(((CEquipItem*)OWNER(self))->GetItem()->FUN_140526b10()));
}

// @0x1412008e0
void* FUN_1412008e0(CEquipModel* self)
{
    void* pEnt = FUN_141200850(self);
    if (pEnt == 0)
        return 0;
    return FUN_140999440(FUN_141b6f910(), ((Unk_EmEntity*)pEnt)->FUN_14123c460());
}

// @0x141200940
MS2Ptr<CItem> CEquipModel::FUN_141200940()
{
    if (FUN_140b02900(&m_spOwner))
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
MS2Ptr<Unk_EquipModelOwner> CEquipModel::FUN_141200a40()
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
        NiAVObject* pRoot = (NiAVObject*)FUN_1409f7cb0(p);
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
    if (FUN_1405a8e70(&self->m_spOwner) ? true : false) {
        if (((void*)((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dc7f0()) != 0) {
            if (((class ItemModelHead*)(void*)(FUN_14053ec70(((void*)((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dc7f0()))))->FUN_1405471b0()) {
                FUN_1411dce60(OWNER(self), &s_strWillUpdatePos);
                ((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dd280();
            }
            void* pEnt = FUN_141200820(self);
            if (pEnt != 0) {
                FUN_1411ea430(((void*)((class PC*)(void*)(pEnt))->FUN_1416561a0()), self->m_spOwner);
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
    EM_FOR_EACH(NiAVObjectPtr sp, self->m_unk_f8) {
        if (FUN_1409a7f70(&sp, pRoot)) {
            NiNode* pParent = (NiNode*)FUN_14098d8d0(&DAT_143afa4d8, FUN_140a0b000(FUN_14098d0f0(&sp)));
            if (pParent != 0)
                pParent->DetachChild((NiAVObject*)FUN_1409849b0(&sp));
        } else {
            pRoot->AttachChild((NiAVObject*)FUN_1409849b0(&sp), true);
        }
    }
    void* pEnt = FUN_141200820(self);
    if (pEnt != 0) {
        MS2Ptr<CItem> spItem = EQUIP(self->m_spOwner)->GetItem();
        if (((void*)((MS2Ptr<CItem>*)(void*)(&spItem))->get()) != 0)
            FUN_1411e9fa0(((void*)((class PC*)(void*)(pEnt))->FUN_1416561a0()), ((class CItem*)(void*)(spItem.operator->()))->FUN_140527a20(), self->FUN_1412029d0(),
                          ((class CItem*)(void*)(spItem.operator->()))->FUN_1405258b0(), ((class CItemData*)(void*)(((void*)((class CItem*)(void*)(spItem.operator->()))->FUN_140527840())))->FUN_14053d2b0());
        FUN_1411ea500(((void*)((class PC*)(void*)(pEnt))->FUN_1416561a0()), self->m_spOwner);
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
    FUN_1401d3700(&kKey);
    EM_FOR_EACH(NiAVObjectPtr sp, self->m_unk_f8) {
        Unk_MeshWalker kWalk(FUN_1409849b0(&sp));
        void* pObj;
        while ((pObj = kWalk.FUN_14098e0d0(true)) != 0) {
            void* pMesh = FUN_14098d8d0(&DAT_143afbbb0, pObj);
            if (pMesh == 0)
                continue;
            kMesh = FUN_142087e50(FUN_1409a8b90(pMesh));
            FUN_1401d3700(&kMesh);
            if (FUN_1401c0090(&kMesh, &kKey)) {
                ((class NiAVObject*)(void*)(pMesh))->SetAppCulled(true);
            } else {
                kMesh = kMesh.Mid(0, kKey.GetLength());
                if (FUN_1401c0090(&kMesh, &kKey))
                    ((class NiAVObject*)(void*)(pMesh))->SetAppCulled(true);
            }
        }
    }
    Unk_MeshWalker kWalk2(self->vfunc_14());
    void* pObj2;
    while ((pObj2 = kWalk2.FUN_14098e0d0(true)) != 0) {
        void* pMesh = FUN_14098d8d0(&DAT_143afbbb0, pObj2);
        if (pMesh == 0)
            continue;
        kMesh = FUN_142087e50(FUN_1409a8b90(pMesh));
        FUN_1401d3700(&kMesh);
        if (FUN_1401c0090(&kMesh, &kKey)) {
            ((class NiAVObject*)(void*)(pMesh))->SetAppCulled(true);
        } else {
            kMesh = kMesh.Mid(0, kKey.GetLength());
            if (FUN_1401c0090(&kMesh, &kKey))
                ((class NiAVObject*)(void*)(pMesh))->SetAppCulled(true);
        }
    }
}

// Writes pPt into the owner entity's per-slot point array at +0x60 (m_vPos).
// @0x1412014f0
void FUN_1412014f0(CEquipModel* self, void* pPt)
{
    MS2Ptr<Unk_EquipModelOwner> spOwn = self->FUN_141200a40();
    if (spOwn == NULL)
        return;
    Unk_PartInfo* pInfo = (Unk_PartInfo*)self->m_unk_20;
    if (pInfo == 0)
        return;
    if (pInfo->m_n24 != 0 && ((class CItemData*)(void*)(((void*)((class CEquipItem*)(void*)(spOwn.operator->()))->FUN_1411dc7f0())))->FUN_14053cfd0() != 0) {
        Unk_EntityPoints* p = (Unk_EntityPoints*)((void*)((class CItem*)(void*)(EQUIP(spOwn)->GetItem().operator->()))->FUN_140527870());
        if (p != 0)
            FUN_140194470(p->m_aPos + pInfo->m_nSlot, pPt);
    }
}

// Same for the point array at +0x78.
// @0x141201620
void FUN_141201620(CEquipModel* self, void* pPt)
{
    MS2Ptr<Unk_EquipModelOwner> spOwn = self->FUN_141200a40();
    if (spOwn == NULL)
        return;
    Unk_PartInfo* pInfo = (Unk_PartInfo*)self->m_unk_20;
    if (pInfo == 0)
        return;
    if (pInfo->m_n24 != 0 && ((class CItemData*)(void*)(((void*)((class CEquipItem*)(void*)(spOwn.operator->()))->FUN_1411dc7f0())))->FUN_14053cfd0() != 0) {
        Unk_EntityPoints* p = (Unk_EntityPoints*)((void*)((class CItem*)(void*)(EQUIP(spOwn)->GetItem().operator->()))->FUN_140527870());
        if (p != 0)
            FUN_140194470(p->m_aPos78 + pInfo->m_nSlot, pPt);
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
        if (FUN_140a53610(pEnt) != 0) {
            return efd::utf8string("MS2EquipItem");
        }
        if (FUN_1412041d0(pEnt) != 0) {
            return efd::utf8string("MS2MannequinEquipItem");
        }
        if (FUN_140a535c0(pEnt) != 0) {
            return efd::utf8string("MS2MannequinEquipItem");
        }
        if (FUN_14099eef0(pEnt) != 0) {
            if (*((bool*)FUN_140c77560(FUN_1409a8b10()) + 0x11)) {
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
    return FUN_1409849b0((void*)&*self->m_unk_f8.begin());
}

// Finds the attached scene object whose name is kName (or which contains an object of that name).
// @0x141201920
NiAVObjectPtr CEquipModel::FUN_141201920(CString kName)
{
    EM_FOR_EACH(NiAVObjectPtr sp, m_unk_f8) {
        if (FUN_140998dc0(FUN_1409a8b90(FUN_14098d0f0(&sp)), kName))
            return sp;
    }
    EM_FOR_EACH(NiAVObjectPtr sp, m_unk_f8) {
        NiAVObjectPtr spFound(((NiAVObject*)FUN_14098d0f0(&sp))->GetObjectByName((const char*)kName));
        if (FUN_1409849b0(&spFound) != 0)
            return spFound;
    }
    return NiAVObjectPtr(0);
}

// @0x141201bd0
NiNodePtr CEquipModel::FUN_141201bd0(const CString& kName)
{
    return NiNodePtr((NiNode*)FUN_14098d8d0(&DAT_143afa4d8, FUN_141201920(kName).operator NiAVObject*()));
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
        FUN_140a35c30(pOut, ((void*)&((class NiAVObject*)(void*)(p))->GetLocalTransform()));
}

// @0x1412021f0
void FUN_1412021f0(CEquipModel* self, NiTransform* pOut)
{
    void* p = FUN_1412018c0(self);
    if (p != 0)
        FUN_140a35c30(pOut, ((void*)&((class NiAVObject*)(void*)(p))->GetWorldTransform()));
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
    const CString& kPart = self->FUN_1412029d0();
    void* pos = ((void*)((ATL::CAtlList<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)(void*)(&s_meshSuffixes))->GetHeadPosition());
    while (pos != 0) {
        CString kFull;
        kFull.Format("%s%s", (const char*)kPart, (const char*)*(CString*)FUN_1405eb3b0(&s_meshSuffixes, &pos));
        NiAVObjectPtr sp(pNode->GetObjectByName((const char*)kFull));
        if (FUN_1409a7f70(&sp, 0))
            continue;
        if (FUN_14098d8d0(&DAT_143afbbb0, FUN_1409849b0(&sp)) == 0)
            continue;
        FUN_140a35c30(pOut, ((void*)&((class NiAVObject*)(void*)(FUN_14098d0f0(&sp)))->GetLocalTransform()));
        return;
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
    void* pEnt = ((void*)((class WorldService*)(void*)(FUN_1403ed2d0()))->FUN_141bd1180(nId));
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
        CString kPart = self->FUN_1412029d0();
        FUN_140984450(fs, kPart);
        pObj = ((NiAVObject*)FUN_1409f7cb0(pActor))->GetObjectByName(*(const NiFixedString*)fs);
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
    if (pRot == 0)
        FUN_140a35c30(&kXf, ((void*)&((class NiAVObject*)(void*)(pRoot))->GetLocalTransform()));
    else
        FUN_140a35c30(&kXf, pRot);
    FUN_140194470(pTrans, &kXf.m_Translate);
    alignas(8) char kWorld[0x34];
    memcpy(kWorld, ((void*)&((class NiAVObject*)(void*)(pAttach))->GetWorldTransform()), 0x34);
    if (FUN_140a0b000(pRoot) != 0)
        FUN_140a35c30(kWorld, ((void*)&((class NiAVObject*)(void*)(FUN_140a0b000(pRoot)))->GetWorldTransform()));
    alignas(8) char kTmp[0x38];
    FUN_140a35bd0(&kXf, FUN_140a33de0(kWorld, kTmp, ((void*)&((class NiAVObject*)(void*)(pRoot))->GetLocalTransform())));
    FUN_140194470(pPos, &kXf.m_Translate);
    alignas(8) char kDelta[16], kLen[20];
    FUN_140194470(pLocal, FUN_140965c40(pPos, kDelta, kLen));
    ((class Vector3*)(void*)(pLocal))->FUN_140968990();
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
    return FUN_1405451c0(kName);
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
        ((class CEffectService*)(void*)(FUN_1403ed280()))->FUN_1411a6060(nHandle);
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
    if (FUN_1401c0050(kId, 0) != 0) {
        FUN_1401bfde0(kId);
        return;
    }
    void* pRoot = FUN_1412008e0(self);
    if (pRoot == 0) {
        FUN_1401bfde0(kId);
        return;
    }
    NiNode* pModel = (NiNode*)FUN_1409f7cb0(pRoot);
    if (pModel == 0) {
        FUN_1401bfde0(kId);
        return;
    }
    alignas(8) char fs[8];
    FUN_140984450(fs, *pName);
    NiNode* pHost = (NiNode*)FUN_14098d8d0(&DAT_143afa4d8, pModel->GetObjectByName(*(const NiFixedString*)fs));
    FUN_1409845a0(fs);
    if (pHost == 0) {
        FUN_1401bfde0(kId);
        return;
    }
    int nType = ((class CItem*)(void*)(FUN_1401c0180(kId)))->FUN_140526c30();
    if (nType != 4 && nType != 5) {
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
        pHost->AttachChild((NiAVObject*)pNew, false);
        FUN_1409f76f0(NODE(self), pNew);
    } else {
        const char* pszNode = (nType == 4) ? "Weapon_Attach_TransformLH" : "Weapon_Attach_TransformRH";
        CString kNode(pszNode);
        alignas(8) char kPool[8];
        void* pMem = FUN_14208a860(0x188, *(unsigned*)FUN_140876480(kPool, 0));
        void* pNew = pMem ? FUN_141b76c30(pMem) : 0;
        alignas(8) char fs2[8];
        FUN_140984450(fs2, kNode);
        FUN_141d18b90(pNew, fs2);
        FUN_1409845a0(fs2);
        pHost->AttachChild((NiAVObject*)pNew, false);
        FUN_1409f76f0(NODE(self), pNew);
        void* pEnt = FUN_141200820(self);
        if (pEnt != 0) {
            CString kModel(((Unk_EmModelLoader*)FUN_141b6f910())->FUN_141206030(((Unk_EmEntity*)pEnt)->FUN_14123c460()).c_str());
            FUN_141200390(self, kModel);
        }
    }
    FUN_1401bfde0(kId);
}

// True when the model should be created for the local view: preview/cinematic scene types or the owner's own entity.
// @0x1412033e0
int FUN_1412033e0(CEquipModel* self)
{
    if (FUN_1417e2610(FUN_140aa6d30()) == 0x620000d)
        return 1;
    if (FUN_1417e2610(FUN_140aa6d30()) == 0x6200018)
        return 1;
    void* pLocal = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pLocal == 0)
        return 0;
    return FUN_140526ad0(EQUIP(self->m_spOwner)->GetItem().operator->()) == FUN_14123c580(pLocal);
}

// Releases every effect bound to a slot and empties the map.
// @0x1412034e0
void FUN_1412034e0(CEquipModel* self)
{
    for (POSITION pos = self->m_map78.GetStartPosition(); pos != 0; self->m_map78.GetNext(pos)) {
        int nHandle = self->m_map78.GetValueAt(pos);
        ((class CEffectService*)(void*)(FUN_1403ed280()))->FUN_1411a6060(nHandle);
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
    NoticeMessage kReq;
    kReq.m_strName = kName;
    FUN_1409fabf0(&kReq.m_spNode, pNode);
    kReq.m_nObject = ((Unk_EmEntity*)pEnt)->vfunc_58();
    kReq.SetActor(FUN_14123c580(pEnt));
    unsigned nHandle = ((class CEffectService*)(void*)(FUN_1403ed280()))->FUN_1411a49c0(*(class Unk_EffectTarget*)(&kReq));
    if (nHandle > 0)
        self->m_map78.SetAt((Unk_EquipEffectSlot&)nSlot, nHandle);
    self->m_b111 = 0;
}

// The status text shown for the model's effect: the owner's template summary string.
// @0x141203830
CString CEquipModel::FUN_141203830()
{
    CEquipModel* self = this;
    if (FUN_1409edd90(&self->m_spOwner, 0) != 0)
        return CString("");
    alignas(8) char kId[16];
    FUN_1411dc7a0(OWNER(self), kId);
    if (FUN_1401c0050(kId, 0) != 0) {
        CString kEmpty("");
        FUN_1401bfde0(kId);
        return kEmpty;
    }
    Unk_EquipTpl* pTpl = (Unk_EquipTpl*)((void*)((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dc7f0());
    if (pTpl == 0) {
        CString kEmpty("");
        FUN_1401bfde0(kId);
        return kEmpty;
    }
    if (!((class CItemData*)(void*)(pTpl))->FUN_14053d2f0()) {
        CString kEmpty("");
        FUN_1401bfde0(kId);
        return kEmpty;
    }
    if (FUN_14053cf90(pTpl) != 0) {
        void* pParent = ((void*)((class CEquipItem*)(void*)(OWNER(self)))->FUN_1411dc8c0());
        if (pParent != 0) {
            alignas(8) char spPart[16];
            FUN_141655c90(pParent, spPart, ((class CItem*)(void*)(FUN_1401c0180(kId)))->FUN_140527a20());
            if (FUN_1405a8e70(spPart) != 0) {
                alignas(8) char kId2[16];
                FUN_1411dc7a0(FUN_1405a8ed0(spPart), kId2);
                char* pTpl2 = (char*)((void*)((class CEquipItem*)(void*)(FUN_1405a8ed0(spPart)))->FUN_1411dc7f0());
                if (FUN_1401c0050(kId2, 0) != 0 || pTpl2 == 0 || !((class CItemData*)(void*)(pTpl2))->FUN_14053d2f0()) {
                    FUN_1401bfde0(kId2);
                    FUN_1405a85f0(spPart);
                    FUN_1401bfde0(kId);
                    return CString("");
                }
                if (pTpl->m_nLevel >= 100) {
                    unsigned nA = ((class CItem*)(void*)(FUN_1401c0180(kId2)))->FUN_140527270();
                    unsigned nB = ((class CItem*)(void*)(FUN_1401c0180(kId2)))->FUN_140526fc0();
                    unsigned nC = ((class CItemData*)(void*)(pTpl))->FUN_14053c620();
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
    }
    CString kOut;
    FUN_140529eb0(FUN_1401c0180(kId), &kOut);
    FUN_1401bfde0(kId);
    return kOut;
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
    if (FUN_1409475d0(NODE(self)) != 0) {
        NiNode* pParent = (NiNode*)FUN_140a0b000(FUN_1409475f0(NODE(self)));
        if (pParent != 0) {
            pParent->DetachChild((NiAVObject*)FUN_1409475d0(NODE(self)));
        }
        FUN_1409f76f0(NODE(self), 0);
    }
}

// Detaches every attached scene object, empties the set and reports the unequip.
// @0x141203e60
void FUN_141203e60(CEquipModel* self)
{
    EM_FOR_EACH(NiAVObjectPtr sp, self->m_unk_f8) {
        if (FUN_1409a7f70(&sp, 0))
            continue;
        NiNode* pParent = (NiNode*)FUN_140a0b000(FUN_14098d0f0(&sp));
        if (pParent != 0)
            pParent->DetachChild((NiAVObject*)FUN_1409849b0(&sp));
    }
    self->m_unk_f8.clear();
    void* pEnt = FUN_141200820(self);
    if (pEnt != 0) {
        MS2Ptr<CItem> spItem = EQUIP(self->m_spOwner)->GetItem();
        if (((void*)((MS2Ptr<CItem>*)(void*)(&spItem))->get()) != 0)
            FUN_1411e9fa0(((void*)((class PC*)(void*)(pEnt))->FUN_1416561a0()), ((class CItem*)(void*)(spItem.operator->()))->FUN_140527a20(), self->FUN_1412029d0(),
                          ((class CItem*)(void*)(spItem.operator->()))->FUN_1405258b0(), ((class CItemData*)(void*)(((void*)((class CItem*)(void*)(spItem.operator->()))->FUN_140527840())))->FUN_14053d2b0());
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
Unk_HoldHandle::Unk_HoldHandle(const Unk_HoldHandle& o)
{
    m_p8 = o.m_p8;
    FUN_1411a4080(this);
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
Unk_HoldHandle Unk_AttachDummy::FUN_141205e30()
{
    return m_hold;
}

// Animation service: the display name of the sequence the entity model key maps to (the default name when none).
// @0x141206030
efd::utf8string Unk_EmModelLoader::FUN_141206030(const egf::EntityID& kId)
{
    void* pEntry;
    if (!FUN_1409991a0(this, kId, &pEntry))
        return efd::utf8string::NullString();
    void* pAssetData = FUN_140998e80((char*)pEntry + 0x10);
    if (!pAssetData)
        return efd::utf8string::NullString();
    if (!FUN_140998e90((char*)pEntry + 8))
        return efd::utf8string::NullString();
    unsigned nSeq = ((class NiActorManager*)(void*)(FUN_1409f7900((char*)pEntry + 8)))->GetTargetAnimation();
    if (nSeq == NiActorManager::INVALID_SEQUENCE_ID)
        return efd::utf8string::NullString();
    else
        return ((Unk_EmAssetData*)pAssetData)->FUN_1409a1940(nSeq);
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
void FUN_141205170(void* a, void* b);
void FUN_141205570(void* p);
bool FUN_141205640(void* a, void* b);

// Pointer holder whose dynamic initializer is the exe's .text$di 0x1400e8c90 (ctor 0x1401cd100), so it runs from
// this unit's .CRT$XCU slot.
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
#ifndef MS2_HOOK_DLL   // the exe's object at 0x143ad2288 (the hook DLL binds it)
Unk_1401cd100 DAT_143ad2288(NULL);
#else
extern Unk_1401cd100 DAT_143ad2288;
#endif

// @0x141204e70
void* FUN_141204e70(void* p)
{
    return p;
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
// sfr34: set<SmartPointer<NiAVObject>>::insert(value_type&&) and the non-const _Tree_comp_alloc::_Getal replace
// the FUN_141205000 / FUN_141208de0 stand-ins, which called _Insert_nohint / _Get_first / _Get_second under FUN_ twins.
// MS2-FUNCTIONAL 0x141205000: the exe passes the value through std::forward 0x1410431d0, which this toolchain's insert folds away
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@std@@_N@1@$$QEAV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x141205000
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@V?$SmartPointer@VNiAVObject@@@efd@@U?$less@V?$SmartPointer@VNiAVObject@@@efd@@@std@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@4@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@std@@@2@XZ 0x141208de0
