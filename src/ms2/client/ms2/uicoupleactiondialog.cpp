// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The emotion ("couple action") picker dialog, UI id 0x4f4e:
// the emotions the local player has learned as pages of 30 slots, a search box, favorites, and the shortcut keys.
// MS2-UNIT: client\ms2\uicoupleactiondialog.cpp
// MS2-RANGE: 0x140bebfb0-0x140bf60f0 .text$mn
// MS2-RANGE: 0x1400cb1e0-0x1400cb290 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400cb1e0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400cb210 ; probe
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140bee6b0 ; unique
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_Emotion@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_Emotion@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140bee820 ; unique
// MS2-PIN: ??$?8PEAVUICoupleActionDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUICoupleActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140beeba0 ; prop
// MS2-PIN: ??$?8PEAVUICoupleActionDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUICoupleActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140beec10 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEBV?$MS2Ptr@VUnk_Emotion@@@@@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@1@U_Not_a_node_tag@1@AEBV?$MS2Ptr@VUnk_Emotion@@@@@Z 0x140beeca0 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEBV?$MS2Ptr@VUnk_Emotion@@@@@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@1@U_Not_a_node_tag@1@AEBV?$MS2Ptr@VUnk_Emotion@@@@@Z 0x140beecd0 ; prop
// MS2-PIN: ??$_Buynode@AEBV?$MS2Ptr@VUnk_Emotion@@@@@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@1@AEBV?$MS2Ptr@VUnk_Emotion@@@@@Z 0x140beed00 ; prop
// MS2-PIN: ??$_Buynode@AEBV?$MS2Ptr@VUnk_Emotion@@@@@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@1@AEBV?$MS2Ptr@VUnk_Emotion@@@@@Z 0x140beed90 ; prop
// MS2-PIN: ??$_Insert_at@AEBV?$MS2Ptr@VUnk_Emotion@@@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@1@_NPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@1@AEBV?$MS2Ptr@VUnk_Emotion@@@@U_Not_a_node_tag@1@@Z 0x140bef3c0 ; prop
// MS2-PIN: ??$_Insert_at@AEBV?$MS2Ptr@VUnk_Emotion@@@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@1@_NPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@1@AEBV?$MS2Ptr@VUnk_Emotion@@@@U_Not_a_node_tag@1@@Z 0x140bef720 ; prop
// MS2-PIN: ??$_Insert_nohint@AEBV?$MS2Ptr@VUnk_Emotion@@@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@_N@1@_NAEBV?$MS2Ptr@VUnk_Emotion@@@@U_Not_a_node_tag@1@@Z 0x140befe90 ; prop
// MS2-PIN: ??$_Insert_nohint@AEBV?$MS2Ptr@VUnk_Emotion@@@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@_N@1@_NAEBV?$MS2Ptr@VUnk_Emotion@@@@U_Not_a_node_tag@1@@Z 0x140bf02a0 ; prop
// MS2-PIN: ??$forward@AEBUUnk_EmotionLess@@@std@@YAAEBUUnk_EmotionLess@@AEBU1@@Z 0x140bf0b30 ; unique
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@0@AEAV10@@Z 0x140bf0b70 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140bf0b80 ; unique
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@_N@1@AEBV?$MS2Ptr@VUnk_Emotion@@@@@Z 0x140bf0b90 ; prop
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@_N@1@AEBV?$MS2Ptr@VUnk_Emotion@@@@@Z 0x140bf0bd0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x140bf0d90 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x140bf0e30 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IVUnk_Emotion@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_Emotion@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x140bf0f70 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA@AEBUUnk_EmotionGreater@@@Z 0x140bf0fa0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IVUnk_Emotion@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_Emotion@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x140bf1040 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA@AEBUUnk_EmotionGreater@@@Z 0x140bf1080 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA@AEBUUnk_EmotionLess@@@Z 0x140bf10c0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_Emotion@@@std@@@std@@@std@@QEAA@XZ 0x140bf1330 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@QEAA@XZ 0x140bf1360 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_Emotion@@@std@@PEAX@std@@@std@@QEAA@XZ 0x140bf13a0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@QEAA@XZ 0x140bf13b0 ; prop
// MS2-PIN: ??0?$map@IVUnk_Emotion@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_Emotion@@@std@@@3@@std@@QEAA@XZ 0x140bf13f0 ; prop
// MS2-PIN: ??0?$set@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@QEAA@XZ 0x140bf1420 ; prop
// MS2-PIN: ??0?$set@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@QEAA@XZ 0x140bf1450 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA@XZ 0x140bf1590 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@IVUnk_Emotion@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_Emotion@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x140bf1620 ; unique
// MS2-PIN: ??1?$set@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@QEAA@XZ 0x140bf1770 ; prop
// MS2-PIN: ??1Unk_Emotion@@UEAA@XZ 0x140bf17f0 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VUnk_Emotion@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_Emotion@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VUnk_Emotion@@@@_K@Z 0x140bf1a30 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@1@XZ 0x140bf1a80 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@1@XZ 0x140bf1aa0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@QEBAAEBV?$MS2Ptr@VUnk_Emotion@@@@XZ 0x140bf1ac0 ; prop
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@1@XZ 0x140bf1ae0 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140bf1c50 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAPEAXI@Z 0x140bf2020 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x140bf2060 ; prop
// MS2-PIN: ?vfunc_48@UICoupleActionDialog@@UEAAHXZ 0x140bf2250 ; unique
// MS2-PIN: ?SetNull@Value@GFx@Scaleform@@QEAAXXZ 0x140bf2260 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@XZ 0x140bf2480 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@XZ 0x140bf2540 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@XZ 0x140bf26e0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@XZ 0x140bf27c0 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IVUnk_Emotion@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_Emotion@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x140bf2910 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAAXU_Not_a_node_tag@2@@Z 0x140bf29f0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAAXU_Not_a_node_tag@2@@Z 0x140bf2a00 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@@Z 0x140bf2b50 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@@Z 0x140bf2bf0 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@@Z 0x140bf3e00 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@@Z 0x140bf3e30 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@@Z 0x140bf3e90 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@@Z 0x140bf3ec0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@XZ 0x140bf3f80 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@XZ 0x140bf3fb0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x140bf3fe0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x140bf3ff0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_Emotion@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_Emotion@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_Emotion@@@std@@PEAX@std@@@2@XZ 0x140bf4040 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@2@XZ 0x140bf4050 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@2@XZ 0x140bf4060 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_Emotion@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_Emotion@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_Emotion@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_Emotion@@@std@@@std@@@2@$00@2@XZ 0x140bf4090 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@UUnk_EmotionGreater@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@std@@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@2@XZ 0x140bf40a0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@UUnk_EmotionGreater@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@std@@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@2@XZ 0x140bf40b0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@UUnk_EmotionLess@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@std@@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@2@XZ 0x140bf40c0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@XZ 0x140bf40f0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_Emotion@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_Emotion@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_Emotion@@@std@@@std@@@2@XZ 0x140bf4100 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@2@XZ 0x140bf4110 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@2@XZ 0x140bf41b0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@2@XZ 0x140bf41e0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@2@XZ 0x140bf4210 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@std@@@2@XZ 0x140bf4240 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAAEAUUnk_EmotionLess@@XZ 0x140bf42d0 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEBAAEBV?$MS2Ptr@VUnk_Emotion@@@@PEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@@Z 0x140bf4320 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEBAAEBV?$MS2Ptr@VUnk_Emotion@@@@PEAU?$_Tree_node@V?$MS2Ptr@VUnk_Emotion@@@@PEAX@2@@Z 0x140bf4350 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEBAAEBV?$MS2Ptr@VUnk_Emotion@@@@AEBV3@@Z 0x140bf43a0 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEBAAEBV?$MS2Ptr@VUnk_Emotion@@@@AEBV3@@Z 0x140bf43c0 ; prop
// MS2-PIN: ?_Kfn@?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@SAAEBV?$MS2Ptr@VUnk_Emotion@@@@AEBV3@@Z 0x140bf43e0 ; prop
// MS2-PIN: ?_Kfn@?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@SAAEBV?$MS2Ptr@VUnk_Emotion@@@@AEBV3@@Z 0x140bf43f0 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAAXXZ 0x140bf4ca0 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@IEAAXXZ 0x140bf4cf0 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@XZ 0x140bf4ef0 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@XZ 0x140bf4f60 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAXXZ 0x140bf5130 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAAXXZ 0x140bf51d0 ; prop
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140bf5270 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140bf52d0 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@XZ 0x140bf5510 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@XZ 0x140bf5570 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@V32@0@Z 0x140bf5910 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@V32@@Z 0x140bf5a00 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@V32@0@Z 0x140bf5ab0 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionLess@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VUnk_Emotion@@@@@std@@@std@@@2@V32@@Z 0x140bf5ba0 ; prop
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140bf5d30 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140bf5d60 ; unique
// MS2-PIN: ??$Call@VUICoupleActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUICoupleActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140bf5d90 ; prop
// MS2-PIN: ??$Call@VUICoupleActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUICoupleActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x140bf5dd0 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140bf5e10 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICoupleActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140bf5e70 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VUnk_Emotion@@@@UUnk_EmotionGreater@@V?$allocator@V?$MS2Ptr@VUnk_Emotion@@@@@std@@$0A@@std@@@std@@QEBA_KXZ 0x140bf5f70 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??1UICoupleActionDialog@@UEAA@XZ 0x140bf1790
// MS2-PIN: ?ceil@@YAMM@Z 0x140bf4fd0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicoupleactiondialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uicoupleactiondialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/uimessagebox.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <atlcoll.h>
#include <cmath>
#include <set>
#include <vector>

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject {};
// "m_inputSearch": the search text input.
class Unk_CoupleInput : public ASDisplayObject
{
public:
    CStringW FUN_1422e0b00();                               // the text
    void FUN_1422e0920(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // text changed callback
};
int FUN_1422c76c0(Unk_CoupleInput* p);                      // the input has the focus
void FUN_1422c7630(ASDisplayObject* p, int nFocus);         // set / clear the focus
// "m_list": the page grid.
class Unk_CoupleList : public ASDisplayObject
{
public:
    int FUN_1422dccd0();                                    // the selected index
    void FUN_1422dcca0(int n);                              // select an index
    MS2Ptr<ASDataProvider> FUN_1422dcd80();                 // the data provider
};
int FUN_140ad02c0(int nMin, int n);                         // max
int FUN_140ad02f0(int nMax, int n);                         // min

// The emotion description (keywords) of an emotion id: the strings are at +0x38.
class Unk_EmotionKeywords : public CPtred
{
public:
    void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
    ATL::CAtlArray<CStringW> m_38;                          // +0x38 keywords
};
MS2Ptr<Unk_EmotionKeywords> FUN_140347050(int nEmotion);

// The skill system (emotion list, mode, reset) and the player.
void FUN_1417691a0(CSkillSystem* p, ATL::CAtlArray<MS2Ptr<Unk_Emotion> >& list);
int FUN_141765cf0(CSkillSystem* p, int nMode);
void FUN_141769280(CSkillSystem* p);
void FUN_14151f200();
NotifySystem* FUN_140939a10();                              // the notify system

// Input state, the movie manager, the key binds.
class Unk_CoupleInputState { public: bool FUN_14116d9c0(int a, int b, int c); };
Unk_CoupleInputState* FUN_14025e7c0();
class Unk_CoupleUiMgr { public: int FUN_1422d4e20(CString strKey); };
Unk_CoupleUiMgr* FUN_140b632f0();
class Unk_CoupleKeyBinds { public: void* FUN_14142d190(int nKey); int FUN_14142b250(int nKey, int a, unsigned __int64 nEmotion, int b, int c); void FUN_14142a8b0(unsigned __int64 nEmotion); };
Unk_CoupleKeyBinds* FUN_1409331f0();

int FUN_1409e1b80(ASTooltip* p, int nId, int n);            // the learned skill tooltip
CStringW FUN_141811980(CStringTable* p, int nTable, int nId);
CStringTable* GetStringTable();
char FUN_1403b3c40(const CStringW& str, const wchar_t* szText);
void FUN_140988d60(CStringW& strSrc, std::vector<CStringW>& arrOut, const wchar_t* pszSep);
SkillDataTable* FUN_1401958b0();                            // the skill table
void FUN_140710590(COutPacket& packet);                     // send

// @0x140bebfb0
UICoupleActionDialog::UICoupleActionDialog()
    : m_178(0), m_1a8()
{
    m_5c = 1;
    FUN_141924170(1);
}

// @0x140bec070
CString UICoupleActionDialog::GetTypeName()
{
    return CString("CoupleAction");
}
MS2_REPLACE_METHOD(0x140BEC070, UICoupleActionDialog, GetTypeName, 61, 0x469BC45E);

// @0x140bec0c0
int UICoupleActionDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    m_178 = 0;
    m_180.clear();
    m_1a8.Empty();
    m_1a0 = false;
    m_1a1 = false;
    return 1;
}
MS2_REPLACE_METHOD(0x140BEC0C0, UICoupleActionDialog, vfunc_65, 116, 0x318F82FC);

// @0x140bec140
void UICoupleActionDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    MyPC* pPlayer = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0)
        FUN_141769280(pPlayer->FUN_141523bc0());
    m_180.clear();
}
MS2_REPLACE_METHOD(0x140BEC140, UICoupleActionDialog, vfunc_67, 87, 0xDB363257);

// @0x140bec1a0
int UICoupleActionDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0) {
        if (pSender == dynamic_cast<UIMessageBox*>(pSender))
            FUN_14151f200();
    }
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x140BEC1A0, UICoupleActionDialog, IMessageListener, OnMessage, 89, 0x81DA8411);

// @0x140bec200
void UICoupleActionDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_140becef0();
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyLearnEmotion"), Delegate<void(NotifyObject*)>(this, &UICoupleActionDialog::FUN_140becea0));
}
MS2_REPLACE_METHOD(0x140BEC200, UICoupleActionDialog, OnLoadInit, 233, 0xC19CC640);

// @0x140bec2f0
void UICoupleActionDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0) {
        Unk_CoupleInput* pInput = m_30->FUN_140bbe940<Unk_CoupleInput>("m_inputSearch", m_190);
        if (pInput != 0)
            m_190->FUN_1422e0920(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UICoupleActionDialog::FUN_140beced0));
    }
}
MS2_REPLACE_METHOD(0x140BEC2F0, UICoupleActionDialog, OnLoadComplete, 369, 0xCE6E4FB0);

// @0x140bec470
void UICoupleActionDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_190.AssignRaw(0);
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyLearnEmotion"), Delegate<void(NotifyObject*)>(this, &UICoupleActionDialog::FUN_140becea0));
}
MS2_REPLACE_METHOD(0x140BEC470, UICoupleActionDialog, vfunc_26, 244, 0x258ACD36);

// @0x140bec570
int UICoupleActionDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0) != 0) {
        ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
        if (pDlg != 0 && FUN_140b632f0() != 0) {
            if (FUN_140b632f0()->FUN_1422d4e20(CString(m_20)) != 0 && m_190.get() != 0) {
                if (FUN_1422c76c0(m_190.operator->()) != 0) {
                    FUN_140bede70(m_190->FUN_1422e0b00());
                    FUN_1422c7630(pDlg, 1);
                    FUN_1422c7630(m_190.operator->(), 0);
                    return 1;
                }
            }
        }
    }
    return UIDialog::vfunc_13();
}
MS2_REPLACE_METHOD(0x140BEC570, UICoupleActionDialog, vfunc_13, 488, 0x3C8B1F60);

// @0x140bec760
void UICoupleActionDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    int nEmotion = pArgs->FUN_1422b8b10();
    MS2Ptr<Unk_EmotionKeywords> spData = FUN_140347050(nEmotion);
    if (spData.IsNull())
        return;
    ASTooltip tooltip(WorldService::GetInstance()->FUN_141bd0cc0(), 0x10, 2);
    if (FUN_1409e1b80(&tooltip, nEmotion, 0) != 0) {
        ASObj stat(2);
        stat.FUN_1407cb9c0("type", 1);
        stat.FUN_1409c0dc0("level", "");
        stat.FUN_1407cbb20("cooltime", FUN_140bedf00(nEmotion));
        tooltip.FUN_1409adbe0("statDescription", stat.FUN_1422bb870());
        tooltip.FUN_1409c0dc0("enablePuton", "");
        *pRetVal = tooltip.FUN_1422bb870();
    }
}
MS2_REPLACE_METHOD(0x140BEC760, UICoupleActionDialog, vfunc_49, 454, 0x54F020C0);

// @0x140bec930
int UICoupleActionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onSelectEmotion") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nEmotion = data.FUN_1422b8b10();
            if (nEmotion == 0)
                return 0;
            FUN_140bed1f0(nEmotion);
            vfunc_67();
        }
    } else if (_stricmp(szMethod, "onFavoriteSort") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) == 0)
            return 0;
        m_1a1 = data.FUN_1422b8a90();
        FUN_140becef0();
    } else if (_stricmp(szMethod, "onSort") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) == 0)
            return 0;
        m_1a0 = data.FUN_1422b8a90();
        FUN_140becef0();
    } else if (_stricmp(szMethod, "onFavorite") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) == 0)
            return 0;
        unsigned int nEmotion = data.FUN_1422b8b10();
        if (nEmotion == 0)
            return 0;
        std::map<unsigned int, MS2Ptr<Unk_Emotion> >::iterator it = m_180.find(nEmotion);
        if (it == m_180.end())
            return 0;
        unsigned short nLevel = it->second->m_level;
        bool bFavorite = data.FUN_1422b8a90();
        it->second->m_favorite = bFavorite;
        COutPacket packet(static_cast<int>(SendOp::Emote), 0);
        packet.WriteUInt8(4);
        packet.WriteInt32(nEmotion);
        packet.WriteInt32(nLevel);
        packet.WriteBool(bFavorite);
        FUN_140710590(packet);
        if (m_1a1)
            FUN_140becef0();
    } else if (_stricmp(szMethod, "onSearch") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) == 0)
            return 0;
        FUN_140bede70(CStringW(data.FUN_1422b8f40()));
    } else if (_stricmp(szMethod, "onFocusIn") == 0) {
    } else {
        _stricmp(szMethod, "onFocusOut");
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140BEC930, UICoupleActionDialog, vfunc_28, 1381, 0x5B2FE17E);

// @0x140becea0
void UICoupleActionDialog::FUN_140becea0(NotifyObject* pNotify)
{
    FUN_140becef0();
}
MS2_REPLACE_METHOD(0x140BECEA0, UICoupleActionDialog, FUN_140becea0, 29, 0x8497AE67);

// @0x140beced0
void UICoupleActionDialog::FUN_140beced0(const Scaleform::GFx::FunctionHandler::Params& params)
{
}
MS2_REPLACE_METHOD(0x140BECED0, UICoupleActionDialog, FUN_140beced0, 11, 0x02239C70);

// @0x140becef0
void UICoupleActionDialog::FUN_140becef0()
{
    m_180.clear();
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0) {
        MyPC* pPlayer = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPlayer != 0) {
            ATL::CAtlArray<MS2Ptr<Unk_Emotion> > list;
            FUN_1417691a0(pPlayer->FUN_141523bc0(), list);
            int nMode = FUN_141765cf0(pPlayer->FUN_141523bc0(), 0);
            FUN_141765cf0(pPlayer->FUN_141523bc0(), nMode);
            std::map<unsigned int, Unk_Emotion> unused;
            for (size_t i = 0; i < list.GetCount(); i++) {
                unsigned int nId = list[i]->m_id;
                SkillData* pSkill = FUN_1401958b0()->GetSkillData(nId);
                if (pSkill != 0 && pSkill->GetMainType() == 0xf)
                    m_180.insert(std::make_pair(nId, list[i]));
            }
            if (m_1a0 == false)
                FUN_140bed2d0();
            else
                FUN_140bed8a0();
        }
    }
}
MS2_REPLACE_METHOD(0x140BECEF0, UICoupleActionDialog, FUN_140becef0, 621, 0x38B953F4);

// @0x140bed170
void UICoupleActionDialog::FUN_140bed170(int nEmotion)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0)
        pDlg->Invoke("setFocusByEmotion", (unsigned int)nEmotion);
}
MS2_REPLACE_METHOD(0x140BED170, UICoupleActionDialog, FUN_140bed170, 117, 0x195C0E2E);

// @0x140bed1f0
int UICoupleActionDialog::FUN_140bed1f0(int nEmotion)
{
    WorldService* pWorld = WorldService::GetInstance();
    if (pWorld == 0) {
        MS2_ASSERT_AT(0x209, "pWorldService" && 0);
        return 0;
    }
    MyPC* pPlayer = static_cast<MyPC*>(pWorld->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    Unk_WsC_GameObj* pActor = pWorld->FUN_141bd1530(m_178);
    if (pActor == 0)
        return 0;
    return pPlayer->FUN_141525480(nEmotion, 0);
}
MS2_REPLACE_METHOD(0x140BED1F0, UICoupleActionDialog, FUN_140bed1f0, 163, 0xB26B551B);

// @0x140bed2a0
void UICoupleActionDialog::FUN_140bed2a0(unsigned __int64 nSelection)
{
    m_178 = nSelection;
}
MS2_REPLACE_METHOD(0x140BED2A0, UICoupleActionDialog, FUN_140bed2a0, 28, 0x3CC3BB9E);

// Sort orders of the emotion pages (the comparators live in the skill system unit).
struct Unk_EmotionLess { bool operator()(const MS2Ptr<Unk_Emotion>& a, const MS2Ptr<Unk_Emotion>& b) const; };   // 0x141764410
struct Unk_EmotionGreater { bool operator()(const MS2Ptr<Unk_Emotion>& a, const MS2Ptr<Unk_Emotion>& b) const; };   // 0x141764570

// @0x140bed2d0
void UICoupleActionDialog::FUN_140bed2d0()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0) {
        ASArray actions(2);
        int nFocus = 0;
        std::set<MS2Ptr<Unk_Emotion>, Unk_EmotionLess> sorted;
        for (std::map<unsigned int, MS2Ptr<Unk_Emotion> >::iterator it = m_180.begin(); it != m_180.end(); ++it)
        {
            MS2Ptr<Unk_Emotion> spCopy(it->second);
            sorted.insert(spCopy);
        }
        for (std::set<MS2Ptr<Unk_Emotion>, Unk_EmotionLess>::iterator sit = sorted.begin(); sit != sorted.end(); ++sit) {
            MS2Ptr<Unk_Emotion> spEmotion(*sit);
            int nId = spEmotion->m_id;
            int nNew = spEmotion->m_isNew;
            bool bFavorite = spEmotion->m_favorite;
            SkillData* pSkill = FUN_1401958b0()->GetSkillData(nId);
            if (pSkill == 0)
                continue;
            if (m_1a1 != 0 && !bFavorite)
                continue;
            if (!m_1a8.IsEmpty()) {
                if (FUN_1403b3c40(m_1a8, L"/") != 0)
                    continue;
                bool bFound = false;
                CStringW strName = FUN_141811980(GetStringTable(), 4, nId);
                if (strName.Find(m_1a8, 0) == -1) {
                    std::vector<CStringW> words;
                    CStringW strKeywords = FUN_140bedf00(nId);
                    FUN_140988d60(strKeywords, words, L", ");
                    for (CStringW& strWord : words) {
                        if (strWord.Find(m_1a8, 0) != -1) {
                            bFound = true;
                            break;
                        }
                    }
                } else {
                    bFound = true;
                }
                if (!bFound)
                    continue;
            }
            if (nNew != 0)
                nFocus = nId;
            ASObj action(2);
            action.FUN_1409c0d20("id", nId);
            action.FUN_1407cb9c0("isNew", nNew);
            action.FUN_1407cba60("iconPath", pSkill->m_strIcon);
            action.FUN_1407cbbe0("isFavorite", bFavorite);
            actions.FUN_1422bbf00(action);
        }
        FUN_140bee040(actions);
        pDlg->FUN_140bd2cb0("buildActions", actions);
        if (nFocus != 0)
            FUN_140bed170(nFocus);
    }
}
MS2_REPLACE_METHOD(0x140BED2D0, UICoupleActionDialog, FUN_140bed2d0, 1468, 0xF1993D52);

// @0x140bed8a0
void UICoupleActionDialog::FUN_140bed8a0()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0) {
        ASArray actions(2);
        int nFocus = 0;
        std::set<MS2Ptr<Unk_Emotion>, Unk_EmotionGreater> sorted;
        for (std::map<unsigned int, MS2Ptr<Unk_Emotion> >::iterator it = m_180.begin(); it != m_180.end(); ++it)
        {
            MS2Ptr<Unk_Emotion> spCopy(it->second);
            sorted.insert(spCopy);
        }
        for (std::set<MS2Ptr<Unk_Emotion>, Unk_EmotionGreater>::iterator sit = sorted.begin(); sit != sorted.end(); ++sit) {
            MS2Ptr<Unk_Emotion> spEmotion(*sit);
            int nId = spEmotion->m_id;
            int nNew = spEmotion->m_isNew;
            bool bFavorite = spEmotion->m_favorite;
            SkillData* pSkill = FUN_1401958b0()->GetSkillData(nId);
            if (pSkill == 0)
                continue;
            if (m_1a1 != 0 && !bFavorite)
                continue;
            if (!m_1a8.IsEmpty()) {
                if (FUN_1403b3c40(m_1a8, L"/") != 0)
                    continue;
                bool bFound = false;
                CStringW strName = FUN_141811980(GetStringTable(), 4, nId);
                if (strName.Find(m_1a8, 0) == -1) {
                    std::vector<CStringW> words;
                    CStringW strKeywords = FUN_140bedf00(nId);
                    FUN_140988d60(strKeywords, words, L", ");
                    for (CStringW& strWord : words) {
                        if (strWord.Find(m_1a8, 0) != -1) {
                            bFound = true;
                            break;
                        }
                    }
                } else {
                    bFound = true;
                }
                if (!bFound)
                    continue;
            }
            if (nNew != 0)
                nFocus = nId;
            ASObj action(2);
            action.FUN_1409c0d20("id", nId);
            action.FUN_1407cb9c0("isNew", nNew);
            action.FUN_1407cba60("iconPath", pSkill->m_strIcon);
            action.FUN_1407cbbe0("isFavorite", bFavorite);
            actions.FUN_1422bbf00(action);
        }
        FUN_140bee040(actions);
        pDlg->FUN_140bd2cb0("buildActions", actions);
        if (nFocus != 0)
            FUN_140bed170(nFocus);
    }
}
MS2_REPLACE_METHOD(0x140BED8A0, UICoupleActionDialog, FUN_140bed8a0, 1468, 0x5CE27D3B);

// @0x140bede70
void UICoupleActionDialog::FUN_140bede70(CStringW strSearch)
{
    if (m_1a8.CompareNoCase(strSearch) == 0)
        return;
    m_1a8 = strSearch;
    FUN_140becef0();
}
MS2_REPLACE_METHOD(0x140BEDE70, UICoupleActionDialog, FUN_140bede70, 124, 0x23F3ADE0);

// @0x140bedf00
CStringW UICoupleActionDialog::FUN_140bedf00(unsigned int nEmotion)
{
    MS2Ptr<Unk_EmotionKeywords> spData = FUN_140347050(nEmotion);
    if (!spData)
        return CStringW(L"");
    CStringW strKeywords;
    for (size_t i = 0; i < spData->m_38.GetCount(); i++)
        strKeywords.AppendFormat(L"%s ", (const wchar_t*)spData->m_38[i]);
    strKeywords.TrimRight();
    return strKeywords;
}
MS2_REPLACE_METHOD(0x140BEDF00, UICoupleActionDialog, FUN_140bedf00, 311, 0x1F48382E);

// @0x140bee040
void UICoupleActionDialog::FUN_140bee040(ASArray& arr)
{
    int nRounded = (int)(std::ceil((float)arr.FUN_1422bc5d0() / 6.0f) * 6.0f);
    int nPages = nRounded > 0x1e ? nRounded : 0x1e;
    int nMissing = nPages - arr.FUN_1422bc5d0();
    if (nMissing < 0)
        return;
    for (int i = 0; i < nMissing; i++) {
        Scaleform::GFx::Value kEmpty;
        kEmpty.SetNull();
        arr.FUN_1422bc050(kEmpty);
    }
}
MS2_REPLACE_METHOD(0x140BEE040, UICoupleActionDialog, FUN_140bee040, 254, 0xB7B5AC57);

// @0x140bee150
void UICoupleActionDialog::FUN_140bee150(int nKey)
{
    if (nKey == 0x79) {
        MS2Ptr<Unk_CoupleList> spList = FUN_140ba4b70("m_list");
        if (spList.get() != 0) {
            int nIndex = spList->FUN_1422dccd0();
            spList->FUN_1422dcca0(FUN_140ad02c0(0, nIndex - 4));
        }
    } else if (nKey == 0x7e) {
        MS2Ptr<Unk_CoupleList> spList = FUN_140ba4b70("m_list");
        if (spList.get() != 0) {
            int nIndex = spList->FUN_1422dccd0();
            int nLast = spList->FUN_1422dcd80()->FUN_1422bc5d0();
            spList->FUN_1422dcca0(FUN_140ad02f0(nLast - 1, nIndex + 4));
        }
    } else if (nKey == 0x7b) {
        MS2Ptr<Unk_CoupleList> spList = FUN_140ba4b70("m_list");
        if (spList.get() != 0) {
            int nIndex = spList->FUN_1422dccd0();
            spList->FUN_1422dcca0(FUN_140ad02c0(0, nIndex - 1));
        }
    } else if (nKey == 0x7c) {
        MS2Ptr<Unk_CoupleList> spList = FUN_140ba4b70("m_list");
        if (spList.get() != 0) {
            int nIndex = spList->FUN_1422dccd0();
            int nLast = spList->FUN_1422dcd80()->FUN_1422bc5d0();
            spList->FUN_1422dcca0(FUN_140ad02f0(nLast - 1, nIndex + 1));
        }
    }
}
MS2_REPLACE_METHOD(0x140BEE150, UICoupleActionDialog, FUN_140bee150, 1067, 0x98B471C9);

// @0x140bee590
int UICoupleActionDialog::FUN_140bee590(int nKey)
{
    return FUN_1409331f0()->FUN_14142d190(nKey) == 0;
}
MS2_REPLACE_METHOD(0x140BEE590, UICoupleActionDialog, FUN_140bee590, 62, 0xC01866C2);

// @0x140bee5e0
int UICoupleActionDialog::FUN_140bee5e0(int nKey, unsigned __int64 nEmotion)
{
    if (FUN_1409331f0()->FUN_14142b250(nKey, 2, nEmotion, 0, 0) != 0) {
        FUN_140becef0();
        FUN_1409331f0()->FUN_14142a8b0(nEmotion);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140BEE5E0, UICoupleActionDialog, FUN_140bee5e0, 108, 0x19D8ECF5);

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca1ed0-0x142ca1f30 .text$yd
