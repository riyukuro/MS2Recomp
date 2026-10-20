// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 3 of commonstruct.cpp: the COMDAT tail
// 0x14027f2d0-0x140287f50 (iterator operators, ??_G, CAtlArray/CAtlList/CAtlMap/CRBTree and TPtr members, the first
// std::vector/list/_Tree internals). The instantiations are in commonstruct_tail.inl (shared with part 4).
// MS2-UNIT: commonfiles\commonstruct.cpp#3
// MS2-RANGE: 0x14027f2d0-0x140287f50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAPEBU?$pair@$$CBHH@1@XZ 0x14027f350 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBHH@1@XZ 0x14027f410 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHH@1@XZ 0x14027f430 ; prop
// MS2-PIN: ??E?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14027f4e0 ; prop
// MS2-PIN: ??E?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f530 ; prop
// MS2-PIN: ??E?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f550 ; prop
// MS2-PIN: ??E?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14027f570 ; prop
// MS2-PIN: ??E?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f590 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f600 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14027f620 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f720 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f740 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14027f760 ; unique
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x14027f870 ; unique
// MS2-PIN: ??_GCNode@?$CRBTree@_KV?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@@3@@ATL@@QEAAPEAXI@Z 0x14027fd70 ; unique
// MS2-PIN: ?AddTail@?$CAtlList@UUnk_CommonCachedPacket@@V?$CElementTraits@UUnk_CommonCachedPacket@@@ATL@@@ATL@@QEAAPEAU__POSITION@@AEBUUnk_CommonCachedPacket@@@Z 0x140280530 ; prop
// MS2-PIN: ?AddTail@?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@QEAAPEAU__POSITION@@AEBV?$MS2Ptr@VCUserLimitHistory@@@@@Z 0x1402805b0 ; prop
// MS2-PIN: ?Copy@?$CAtlArray@UUnk_Z16i@@V?$CElementTraits@UUnk_Z16i@@@ATL@@@ATL@@QEAAXAEBV12@@Z 0x140280a70 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x140280ea0 ; unique
// MS2-PIN: ?FreeNode@?$CAtlList@HV?$CElementTraits@H@ATL@@@ATL@@AEAAXPEAVCNode@12@@Z 0x140281100 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x140281170 ; unique
// MS2-PIN: ?GetAt@?$CAtlList@UUnk_CommonCachedPacket@@V?$CElementTraits@UUnk_CommonCachedPacket@@@ATL@@@ATL@@QEAAAEAUUnk_CommonCachedPacket@@PEAU__POSITION@@@Z 0x1402814d0 ; prop
// MS2-PIN: ?GetCount@?$CAtlArray@UUnk_CommonPacketLogEntry@@V?$CElementTraits@UUnk_CommonPacketLogEntry@@@ATL@@@ATL@@QEBA_KXZ 0x1402815c0 ; prop
// MS2-PIN: ?GetCount@?$CAtlArray@VUnk_CommonPriceRecord@@V?$CElementTraits@VUnk_CommonPriceRecord@@@ATL@@@ATL@@QEBA_KXZ 0x1402815d0 ; prop
// MS2-PIN: ?GetCount@?$CAtlArray@VUnk_CommonPrice@@V?$CElementTraits@VUnk_CommonPrice@@@ATL@@@ATL@@QEBA_KXZ 0x1402815e0 ; prop
// MS2-PIN: ?GetCount@?$CAtlMap@HW4Unk_LimitValue@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_LimitValue@@@3@@ATL@@QEBA_KXZ 0x140281600 ; prop
// MS2-PIN: ?GetFreeNode@?$CAtlList@HV?$CElementTraits@H@ATL@@@ATL@@AEAAXXZ 0x1402817d0 ; unique
// MS2-PIN: ?GetNext@?$CAtlList@UUnk_CommonCachedPacket@@V?$CElementTraits@UUnk_CommonCachedPacket@@@ATL@@@ATL@@QEAAAEAUUnk_CommonCachedPacket@@AEAPEAU__POSITION@@@Z 0x140281a70 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140281bf0 ; prop
// MS2-PIN: ?GetValueAt@?$CAtlMap@HW4Unk_LimitValue@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_LimitValue@@@3@@ATL@@QEAAAEAW4Unk_LimitValue@@PEAU__POSITION@@@Z 0x1402821a0 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@HII@Z 0x1402833c0 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXI@Z 0x140284450 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@UUnk_Z16i@@@ATL@@SAXPEAUUnk_Z16i@@0_K@Z 0x1402848b0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@UUnk_CommonPacketLogEntry@@@ATL@@SAXPEAUUnk_CommonPacketLogEntry@@0_K@Z 0x140284930 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@VUnk_CommonPrice@@@ATL@@SAXPEAVUnk_CommonPrice@@0_K@Z 0x1402849b0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlList@HV?$CElementTraits@H@ATL@@@ATL@@QEAAXXZ 0x140284c10 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x140284cf0 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1402850a0 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140285430 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAPEAU__POSITION@@HH@Z 0x140285720 ; unique
// MS2-PIN: ?AddRef@?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@AEBAXXZ 0x1402864f0 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x140286c60 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x140286de0 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEBA_K_K@Z 0x140286f50 ; prop
// MS2-PIN: ?_Calculate_growth@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEBA_K_K@Z 0x140286fe0 ; prop
// MS2-PIN: ?_Change_array@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEAAXQEAUItemEntity@@_K1@Z 0x140287190 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1402874c0 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x140287520 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x1402876f0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x140287740 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@@Z 0x1402877e0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/commonfiles/commonstruct_tail.inl"
