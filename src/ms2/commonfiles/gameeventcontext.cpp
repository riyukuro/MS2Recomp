// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameEvent subclasses GameEventAttendGift / CashAttend, the
// *Context types the event XML loaders fill, and the CAtlArray / std:: glue over them. GameEventDTReward is the next
// obj (its registration 0x1400b86b0, .bss 0x143aaeeb0 and code 0x14041b140-0x14041c1a0 follow this unit's).
// MS2-UNIT: commonfiles\gameeventcontext.cpp
// MS2-RANGE: 0x1400b8480-0x1400b86b0 .text$di
// MS2-RANGE: 0x1403f4e10-0x14041b140 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBKH@std@@PEAX@2@XZ 0x1403f5140 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBKH@std@@PEAX@2@@Z 0x1403f5840 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBKH@std@@PEAX@2@@Z 0x1403f6d10 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBKH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKH@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBKH@std@@PEAX@std@@@2@XZ 0x1403f6ff0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBKH@std@@PEAX@std@@@2@XZ 0x1403f7220 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@UCard@GalleryContext@@@@AEAAXXZ 0x1403f7d50 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@UQuestContext@TimeRunEventContext@@@@AEAAXXZ 0x1403f7f10 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@UReward@LongTermAttendGiftContext@@@@AEAAXXZ 0x1403f7f90 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@UReward@StampEventContext@@@@AEAAXXZ 0x1403f7fd0 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@URewardData@RpsContext@@@@AEAAXXZ 0x1403f8010 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@USnowman@SnowmanContext@@@@AEAAXXZ 0x1403f80d0 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@UStamp@StampEventContext@@@@AEAAXXZ 0x1403f8110 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VCNpcShopGivePointContextBase@@@@AEAAXXZ 0x1403f8250 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VTreeWatering_EmotionDay@@@@AEAAXXZ 0x1403f87d0 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VTreeWatering_TreeResource@@@@AEAAXXZ 0x1403f8810 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VTreeWatering_TreeStep@@@@AEAAXXZ 0x1403f8850 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UCard@GalleryContext@@@@AEAAXPEAX@Z 0x1403f88f0 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UQuestContext@TimeRunEventContext@@@@AEAAXPEAX@Z 0x1403f8b20 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UReward@LongTermAttendGiftContext@@@@AEAAXPEAX@Z 0x1403f8bc0 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UReward@StampEventContext@@@@AEAAXPEAX@Z 0x1403f8c10 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@URewardData@RpsContext@@@@AEAAXPEAX@Z 0x1403f8c60 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@USnowman@SnowmanContext@@@@AEAAXPEAX@Z 0x1403f8d50 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UStamp@StampEventContext@@@@AEAAXPEAX@Z 0x1403f8da0 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCNpcShopGivePointContextBase@@@@AEAAXPEAX@Z 0x1403f8f30 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VTreeWatering_EmotionDay@@@@AEAAXPEAX@Z 0x1403f9610 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VTreeWatering_TreeResource@@@@AEAAXPEAX@Z 0x1403f9660 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VTreeWatering_TreeStep@@@@AEAAXPEAX@Z 0x1403f96b0 ; prop
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBKH@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBKH@std@@PEAX@std@@@2@@Z 0x1403fb030 ; prop
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1403fb090 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_KXZ 0x1403fb260 ; unique
// MS2-PIN: ??$?0AEBU?$less@U?$pair@IH@std@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@I@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@I@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@U?$pair@IH@std@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140407e30 ; unique
// MS2-PIN: ??$?0IH$0A@@?$pair@IH@std@@QEAA@$$QEAI$$QEAH@Z 0x140407ed0 ; local
// MS2-PIN: ??$?6I@@YAAEAVCOutputStream@@AEAV0@AEBV?$vector@IV?$allocator@I@std@@@std@@@Z 0x1404081e0 ; unique
// MS2-PIN: ??$?MIH@std@@YA_NAEBU?$pair@IH@0@0@Z 0x140408280 ; local
// MS2-PIN: ??$Unk_ArrayFind@H@@YAHAEBV?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@AEBH@Z 0x140408410 ; unique
// MS2-PIN: ??$StringFormat@_K_K_KI@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEB_K11AEBI@Z 0x140408840 ; unique
// MS2-PIN: ??$_Emplace_back@AEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@?$_Uninitialized_backout_al@PEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@QEAAXAEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x140409710 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@_K@?$vector@_KV?$allocator@_K@std@@@std@@AEAAX$$QEA_K@Z 0x140409d10 ; local
// MS2-PIN: ??$_Emplace_reallocate@_K@?$vector@_KV?$allocator@_K@std@@@std@@QEAAPEA_KQEA_K$$QEA_K@Z 0x14040a940 ; local
// MS2-PIN: ??$_Unfancy@_K@std@@YAPEA_KPEA_K@Z 0x14040d140 ; local
// MS2-PIN: ??$make_pair@AEAHAEAV?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@@std@@YA?AU?$pair@HV?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@@0@AEAHAEAV?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@0@@Z 0x14040ea00 ; unique
// MS2-PIN: ??$make_pair@IH@std@@YA?AU?$pair@IH@0@$$QEAI$$QEAH@Z 0x14040ea60 ; unique
// MS2-PIN: ??0?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEAA@AEBV01@@Z 0x14040fb30 ; unique
// MS2-PIN: ??1?$CRBTree@HV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@QEAA@XZ 0x140410050 ; unique
// MS2-PIN: ??1?$CRBTree@IV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@QEAA@XZ 0x140410090 ; unique
// MS2-PIN: ??1CNode@?$CRBTree@HV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@QEAA@XZ 0x1404105c0 ; prop
// MS2-PIN: ??1CNode@?$CRBTree@IV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@QEAA@XZ 0x1404105e0 ; prop
// MS2-PIN: ??1FestivalContext@@UEAA@XZ 0x1404107b0 ; local
// MS2-PIN: ??A?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEAAAEAUItemEntity@@_K@Z 0x1404110a0 ; unique
// MS2-PIN: ??R?$less@U?$pair@IH@std@@@std@@QEBA_NAEBU?$pair@IH@1@0@Z 0x1404117d0 ; unique
// MS2-PIN: ??_GCNode@?$CRBTree@HV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@QEAAPEAXI@Z 0x140411b00 ; prop
// MS2-PIN: ??_GCNode@?$CRBTree@IV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@QEAAPEAXI@Z 0x140411b40 ; prop
// MS2-PIN: ??_GFestivalContext@@UEAAPEAXI@Z 0x140411d80 ; local
// MS2-PIN: ??_GFieldEffectContext@@UEAAPEAXI@Z 0x140411dc0 ; prop
// MS2-PIN: ??_GItemBoxEventContext@@UEAAPEAXI@Z 0x140411e00 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@HV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x140412b40 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@IV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x140412be0 ; prop
// MS2-PIN: ?GetCount@?$CAtlArray@UItemEntity@@V?$CElementTraits@UItemEntity@@@ATL@@@ATL@@QEBA_KXZ 0x140412e50 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@UCard@GalleryContext@@@@V?$CElementTraits@V?$MS2Ptr@UCard@GalleryContext@@@@@ATL@@@ATL@@QEBA_KXZ 0x140412e70 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@UReward@LongTermAttendGiftContext@@@@V?$CElementTraits@V?$MS2Ptr@UReward@LongTermAttendGiftContext@@@@@ATL@@@ATL@@QEBA_KXZ 0x140412e80 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@UReward@StampEventContext@@@@V?$CElementTraits@V?$MS2Ptr@UReward@StampEventContext@@@@@ATL@@@ATL@@QEBA_KXZ 0x140412e90 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@USnowman@SnowmanContext@@@@V?$CElementTraits@V?$MS2Ptr@USnowman@SnowmanContext@@@@@ATL@@@ATL@@QEBA_KXZ 0x140412ea0 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@UStamp@StampEventContext@@@@V?$CElementTraits@V?$MS2Ptr@UStamp@StampEventContext@@@@@ATL@@@ATL@@QEBA_KXZ 0x140412eb0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@I_NV?$CElementTraits@I@ATL@@V?$CElementTraits@_N@2@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x140413100 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$MS2Ptr@VTreeWatering_TreeResource@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VTreeWatering_TreeResource@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VTreeWatering_TreeResource@@@@PEAU__POSITION@@@Z 0x140413370 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$MS2Ptr@VTreeWatering_TreeStep@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VTreeWatering_TreeStep@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VTreeWatering_TreeStep@@@@PEAU__POSITION@@@Z 0x1404133e0 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@IV?$MS2Ptr@UQuestContext@TimeRunEventContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@UQuestContext@TimeRunEventContext@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@UQuestContext@TimeRunEventContext@@@@PEAU__POSITION@@@Z 0x140413450 ; unique
// MS2-PIN: ?RemoveAll@?$CRBTree@HV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@QEAAXXZ 0x140414dc0 ; prop
// MS2-PIN: ?RemoveAll@?$CRBTree@IV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@QEAAXXZ 0x140414e40 ; prop
// MS2-PIN: ?RemovePostOrder@?$CRBTree@HV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x140415070 ; prop
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IV?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x1404150d0 ; prop
// MS2-PIN: ?_Change_array@?$vector@_KV?$allocator@_K@std@@@std@@AEAAXQEA_K_K1@Z 0x140416ec0 ; local
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@I@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@I@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@I@std@@@std@@@std@@@2@@Z 0x1404178b0 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@IU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@I@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@I@std@@PEAX@2@@Z 0x140417e90 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@@std@@PEAX@2@@Z 0x140417ec0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@IU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@I@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@I@std@@PEAX@2@@Z 0x140417ef0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@_KV?$allocator@_K@std@@@std@@@std@@QEAAAEAPEA_KXZ 0x140418a30 ; local
// MS2-PIN: ?_Orphan_range@?$vector@_KV?$allocator@_K@std@@@std@@AEBAXPEA_K0@Z 0x140418bd0 ; local
// MS2-PIN: ?_Tidy@?$vector@_KV?$allocator@_K@std@@@std@@AEAAXXZ 0x1404193d0 ; unique
// MS2-PIN: ?_Xlength@?$vector@_KV?$allocator@_K@std@@@std@@CAXXZ 0x1404199c0 ; local
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKH@std@@@std@@@std@@@2@XZ 0x140419c00 ; unique
// MS2-PIN: ?begin@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEBA?AV?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UItemEntity@@@std@@@std@@@2@XZ 0x140419db0 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKH@std@@@std@@@std@@@2@XZ 0x14041a360 ; unique
// MS2-PIN: ?end@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEBA?AV?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UItemEntity@@@std@@@std@@@2@XZ 0x14041a4e0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@AEBH@Z 0x14041a940 ; unique
// MS2-PIN: ?push_back@?$vector@_KV?$allocator@_K@std@@@std@@QEAAX$$QEA_K@Z 0x14041ae30 ; unique
// MS2-PIN: ?size@?$vector@_KV?$allocator@_K@std@@@std@@QEBA_KXZ 0x14041afe0 ; local
// MS2-PINS-END tplpin
// MS2-PINS-BEGIN w203
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x1403f4e20 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@XZ 0x1403f4ee0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@XZ 0x1403f4fa0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x1403f5060 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@XZ 0x1403f5220 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@XZ 0x1403f5300 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1403f55d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1403f5600 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@QEAAXXZ 0x1403f5630 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Destroy@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@0@Z 0x1403f5770 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x1403f57f0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x1403f5890 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x1403f58e0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@IEAAXU_Not_a_node_tag@2@@Z 0x1403f5930 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@IEAAXU_Not_a_node_tag@2@@Z 0x1403f5940 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@@Z 0x1403f59f0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@XZ 0x1403f6da0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@XZ 0x1403f6dd0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@2@XZ 0x1403f6e00 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@2@XZ 0x1403f6e30 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@W4Unk_UGCUploadType@@@std@@@2@XZ 0x1403f6e60 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@2@XZ 0x1403f6f10 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@XZ 0x1403f71c0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@XZ 0x1403f71f0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@2@XZ 0x1403f7250 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@2@XZ 0x1403f7280 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@2@XZ 0x1403f72b0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@2@XZ 0x1403f72e0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@2@XZ 0x1403f7350 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@2@XZ 0x1403f7370 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x1403f73b0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@U?$pair@IH@std@@@2@XZ 0x1403f73f0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@QEAAAEAU?$less@W4Unk_UGCUploadType@@@2@XZ 0x1403f7410 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x1403f7480 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Key@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@IH@2@PEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@@Z 0x1403f74b0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Key@?$_Tree@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@IEBAAEBW4Unk_UGCUploadType@@PEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@@Z 0x1403f74e0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHH@2@@Z 0x1403f7510 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@IH@2@AEBU32@@Z 0x1403f7530 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@IEBAAEBW4Unk_UGCUploadType@@AEBW43@@Z 0x1403f7550 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x1403f7590 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@XZ 0x1403f75a0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@W4Unk_UGCUploadType@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@XZ 0x1403f75b0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@@Z 0x1403f76a0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@W4Unk_UGCUploadType@@@std@@@std@@QEAAXPEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@@Z 0x1403f7780 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@XZ 0x1403f7a00 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@XZ 0x1403f7b00 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@XZ 0x1403f7bc0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Orphan_range@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@AEBAXPEAV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@0@Z 0x1403f7ca0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Reallocate_exactly@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@AEAAX_K@Z 0x1403f7cb0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?Release@?$MS2Ptr@VDungeonRoomShutdownContext@@@@AEAAXXZ 0x1403f7d90 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VDungeonRoomShutdownContext@@@@AEAAXPEAX@Z 0x1403f8940 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@UMesoRevivalEventContext@@@@AEAAXXZ 0x1403f7e10 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UMesoRevivalEventContext@@@@AEAAXPEAX@Z 0x1403f89e0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@UNpcEventDropEventContext@@@@AEAAXXZ 0x1403f7e50 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UNpcEventDropEventContext@@@@AEAAXPEAX@Z 0x1403f8a30 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@UOntimeEventContext@@@@AEAAXXZ 0x1403f7e90 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UOntimeEventContext@@@@AEAAXPEAX@Z 0x1403f8a80 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@UPreminmMarketSaleEventContext@@@@AEAAXXZ 0x1403f7ed0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UPreminmMarketSaleEventContext@@@@AEAAXPEAX@Z 0x1403f8ad0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VRestrictionData@CGameEventValueItemTradeRestriction@@@@AEAAXXZ 0x1403f7f50 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VRestrictionData@CGameEventValueItemTradeRestriction@@@@AEAAXPEAX@Z 0x1403f8b70 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@USAHotTimeEventContext@@@@AEAAXXZ 0x1403f8050 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@USAHotTimeEventContext@@@@AEAAXPEAX@Z 0x1403f8cb0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@USkillUpgradeSaleEventContext@@@@AEAAXXZ 0x1403f8090 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@USkillUpgradeSaleEventContext@@@@AEAAXPEAX@Z 0x1403f8d00 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VArcadeOpenContext@@@@AEAAXXZ 0x1403f8150 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VArcadeOpenContext@@@@AEAAXPEAX@Z 0x1403f8df0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VBingoContext@@@@AEAAXXZ 0x1403f8190 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VBingoContext@@@@AEAAXPEAX@Z 0x1403f8e40 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VBlueMarbleEventContext@@@@AEAAXXZ 0x1403f81d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VBlueMarbleEventContext@@@@AEAAXPEAX@Z 0x1403f8e90 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VBurningLevelupContext@@@@AEAAXXZ 0x1403f8210 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VBurningLevelupContext@@@@AEAAXPEAX@Z 0x1403f8ee0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VCollectItemGroupContext@@@@AEAAXXZ 0x1403f8290 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCollectItemGroupContext@@@@AEAAXPEAX@Z 0x1403f8f80 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VCoupleDanceContext@@@@AEAAXXZ 0x1403f82d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCoupleDanceContext@@@@AEAAXPEAX@Z 0x1403f8fd0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VDungeonBonusRewardCtx@@@@AEAAXXZ 0x1403f8310 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VDungeonBonusRewardCtx@@@@AEAAXPEAX@Z 0x1403f9020 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VDungeonExtraRewardCountCtx@@@@AEAAXXZ 0x1403f8350 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VDungeonExtraRewardCountCtx@@@@AEAAXPEAX@Z 0x1403f9070 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VEnchantRateEventContext@@@@AEAAXXZ 0x1403f8390 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VEnchantRateEventContext@@@@AEAAXPEAX@Z 0x1403f90c0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VEventQuestContext@@@@AEAAXXZ 0x1403f83d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VEventQuestContext@@@@AEAAXPEAX@Z 0x1403f9110 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VEventTimeLimitDungeonContext@@@@AEAAXXZ 0x1403f8410 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VEventTimeLimitDungeonContext@@@@AEAAXPEAX@Z 0x1403f9160 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VFestivalContext@@@@AEAAXXZ 0x1403f8450 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VFestivalContext@@@@AEAAXPEAX@Z 0x1403f91b0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VFieldEffectContext@@@@AEAAXXZ 0x1403f8490 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VFieldEffectContext@@@@AEAAXPEAX@Z 0x1403f9200 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VGalleryContext@@@@AEAAXXZ 0x1403f84d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VGalleryContext@@@@AEAAXPEAX@Z 0x1403f9250 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VItemBoxEventContext@@@@AEAAXXZ 0x1403f8510 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VItemBoxEventContext@@@@AEAAXPEAX@Z 0x1403f92a0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VLongTermAttendGiftContext@@@@AEAAXXZ 0x1403f8550 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VLongTermAttendGiftContext@@@@AEAAXPEAX@Z 0x1403f92f0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VQuestAdditionalRewardContext@@@@AEAAXXZ 0x1403f8590 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VQuestAdditionalRewardContext@@@@AEAAXPEAX@Z 0x1403f9340 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VReactorContext@@@@AEAAXXZ 0x1403f85d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VReactorContext@@@@AEAAXPEAX@Z 0x1403f9390 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VRpsContext@@@@AEAAXXZ 0x1403f8610 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VRpsContext@@@@AEAAXPEAX@Z 0x1403f93e0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VSaleCube@@@@AEAAXXZ 0x1403f8690 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VSaleCube@@@@AEAAXPEAX@Z 0x1403f9480 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VSnowmanContext@@@@AEAAXXZ 0x1403f86d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VSnowmanContext@@@@AEAAXPEAX@Z 0x1403f94d0 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VStampEventContext@@@@AEAAXXZ 0x1403f8710 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VStampEventContext@@@@AEAAXPEAX@Z 0x1403f9520 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VTimeRunEventContext@@@@AEAAXXZ 0x1403f8750 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VTimeRunEventContext@@@@AEAAXPEAX@Z 0x1403f9570 ; w203: Release's callee
// MS2-PIN: ?Release@?$MS2Ptr@VTreeWateringContext@@@@AEAAXXZ 0x1403f8790 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VTreeWateringContext@@@@AEAAXPEAX@Z 0x1403f95c0 ; w203: Release's callee
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@XZ 0x1403f88d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@XZ 0x1403f9770 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@W4Unk_UGCUploadType@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@XZ 0x1403f9790 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@XZ 0x1403f97d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@W4Unk_UGCUploadType@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@XZ 0x1403f97f0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@@Z 0x1403f98f0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@W4Unk_UGCUploadType@@@std@@@std@@QEAAXPEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@@Z 0x1403f99d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Tidy@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@AEAAXXZ 0x1403f9d50 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@00U?$integral_constant@_N$0A@@2@@Z 0x1403f9f30 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Unchecked_begin@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@2@XZ 0x1403f9fd0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Unchecked_end@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@2@XZ 0x1403fa020 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Unwrapped@?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEBA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@2@XZ 0x1403fa060 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?_Xlength@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@CAXXZ 0x1403fa0a0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x1403fa0c0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@_K@Z 0x1403fa0f0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@_K@Z 0x1403fa120 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@XZ 0x1403fa180 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@@2@XZ 0x1403fa1f0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Unk_UGCUploadType@@@std@@@std@@@2@XZ 0x1403fa260 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?begin@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@2@XZ 0x1403fa2d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?capacity@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@QEBA_KXZ 0x1403fa3b0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1403fa4e0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?clear@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@QEAAXXZ 0x1403fa620 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x1403fa6a0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@IH@std@@PEAX@2@_K@Z 0x1403fa6d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@2@QEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@2@_K@Z 0x1403fa700 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?deallocate@?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@QEAAXQEAV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@_K@Z 0x1403fa820 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@XZ 0x1403fa880 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@@2@XZ 0x1403fa8e0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?end@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@2@XZ 0x1403fa9a0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKH@std@@@std@@@std@@@std@@V12@@2@AEBK@Z 0x1403faa00 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@$0A@@std@@@std@@QEAA_KAEBK@Z 0x1403fabe0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?key_comp@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBA?AU?$less@I@2@XZ 0x1403faf90 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@AEBH@Z 0x1403fafc0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@@Z 0x1403fb020 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@2@@Z 0x1403fb040 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@2@@Z 0x1403fb050 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@SA_KAEBV?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@2@@Z 0x1403fb060 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1403fb070 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1403fb0b0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@W4Unk_UGCUploadType@@U?$less@W4Unk_UGCUploadType@@@std@@V?$allocator@W4Unk_UGCUploadType@@@3@$0A@@std@@@std@@QEBA_KXZ 0x1403fb0d0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?max_size@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@QEBA_KXZ 0x1403fb0f0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?push_back@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@Z 0x1403fb190 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?reserve@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@QEAAX_K@Z 0x1403fb1c0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1403fb220 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1403fb280 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?size@?$vector@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@V?$allocator@V?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@QEBA_KXZ 0x1403fb2a0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ??$?0AEAHAEAV?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@$0A@@?$pair@HV?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@@std@@QEAA@AEAHAEAV?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@1@@Z 0x140407ca0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ??$construct@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAV12@@?$_Default_allocator_traits@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@SAXAEAV?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@QEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAV34@@Z 0x14040e090 ; w203: gameevent.obj caller relocs
// MS2-PIN: ??$construct@_K_K@?$_Default_allocator_traits@V?$allocator@_K@std@@@std@@SAXAEAV?$allocator@_K@1@QEA_K$$QEA_K@Z 0x14040e310 ; w203: gameevent.obj caller relocs
// MS2-PIN: ??$emplace_back@_K@?$vector@_KV?$allocator@_K@std@@@std@@QEAAX$$QEA_K@Z 0x14040e6e0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ??1CNpcShopGivePointContextBase@@UEAA@XZ 0x140410600 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@XZ 0x140419ce0 ; w203: gameevent.obj caller relocs
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@XZ 0x14041a420 ; w203: gameevent.obj caller relocs
// (dropped pin: 0x140411560 is _Vector_iterator<unsigned>::operator++, not the map<DWORD,int> const_iterator ++)
// MS2-PINS-END w203
// MS2-PIN: ??1GameEventAttendGift@@UEAA@XZ 0x1403fc070
// MS2-PIN: ??1GameEventCashAttend@@UEAA@XZ 0x1403fc0d0
// MS2-PIN: ??_GGameEventAttendGift@@UEAAPEAXI@Z 0x1403fc190
// MS2-PIN: ??_GGameEventCashAttend@@UEAAPEAXI@Z 0x1403fc1d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventcontext.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <new>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/cnpcshopproductbase.h"
#include "ms2/ms2format.h"
#include "gameeventcontext.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit helpers.
// Constructor at 0x140316aa0: registers the factory under the name (the by-value CString is destroyed by the callee).
struct Unk_GEFactoryRegistry {
    Unk_GEFactoryRegistry(CStringW name, GameEvent* (*create)());
    char m_pad;
};
int FUN_140718200(CStringW* text);
// Stream helpers (CInputStream / COutputStream operator<< / >> overloads).
Unk_GEOut* FUN_14070f9a0(Unk_GEOut* out, int value);
Unk_GEOut* FUN_14070fa20(Unk_GEOut* out, __int64 value);
Unk_GEOut* FUN_14070f820(Unk_GEOut* out, bool value);
Unk_GEOut* FUN_14070fb70(Unk_GEOut* out, const CMsTime* date);
Unk_GEOut* FUN_14070fae0(Unk_GEOut* out, const CStringW* text);
Unk_GEOut* FUN_14070faa0(Unk_GEOut* out, const CStringA* text);
Unk_GEReader* FUN_14070f480(Unk_GEReader* in, int* value);
Unk_GEReader* FUN_14070f500(Unk_GEReader* in, __int64* value);
Unk_GEReader* FUN_14070f300(Unk_GEReader* in, bool* value);
Unk_GEReader* FUN_14070f6b0(Unk_GEReader* in, CMsTime* date);
Unk_GEReader* FUN_14070f5f0(Unk_GEReader* in, CStringW* text);
Unk_GEReader* FUN_14070f580(Unk_GEReader* in, CStringA* text);
Unk_AttendGiftDataGroup* FUN_1403fc330();
// Typed stream operators (packet.cpp).
COutputStream& FUN_14070f860(COutputStream& out, unsigned char value);
COutputStream& FUN_14070f960(COutputStream& out, long value);
COutputStream& FUN_14070f9a0(COutputStream& out, unsigned int value);
COutputStream& FUN_14070fa60(COutputStream& out, float value);
CInputStream& FUN_14070f440(CInputStream& in, long& value);
CInputStream& FUN_14070f480(CInputStream& in, int& value);
CInputStream& FUN_14070f480(CInputStream& in, unsigned& value);
CInputStream& FUN_14070f540(CInputStream& in, float& value);
COutputStream& FUN_1403d7730(COutputStream& out, const ATL::CAtlArray<unsigned>& arr);   // count + values (gameevent.cpp)
CInputStream& FUN_1403d7440(CInputStream& in, ATL::CAtlArray<unsigned>& arr);          // count + values (gameevent.cpp)
__int64 FUN_140869440();                                                               // server time
int FUN_140873b30(Unk_140165cf0* pElem, const char* pszName, CStringW& strOut);   // tinyxmlhelper string attribute
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned long& nOut);
void FUN_1401d9a30(const CStringW& str, ATL::CAtlArray<int>& rOut, const wchar_t* pszSep);  // split into ints
void FUN_1402929a0(const CStringW& str, std::vector<int>& rOut, const wchar_t* pszSep);    // split into ints
int FUN_140274f40(const CStringW& str);                                                // _wtoi
void FUN_1401cdae0(ATL::CAtlArray<int>& arr, unsigned seed);                            // shuffle by the seed
int FUN_1402bacf0(ATL::CAtlArray<int>& arr, const int& value);                           // index of the value or -1
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, long& nOut);   // tinyxmlhelper int attribute, long overload
Unk_140165cf0* FUN_140345b40(TiXmlDocument* pDoc);   // the document's first child element
Unk_140165cf0* FUN_140345b40(Unk_140165cf0* pNode);  // first child element
Unk_140165cf0* FUN_1403f0510(Unk_140165cf0* pNode);  // next sibling element
CString FUN_140223380(int result);                    // rps result node name: draw / win / lose
void FUN_14015f0b0(CString& str, ATL::CAtlArray<CString>& rOut, const char* pszSep);  // split into strings
CString CoupleDanceStepName(int step);
// Enum name parsers (commonenum.cpp).
Unk_BlueMarbleSlotType FUN_140218100(const CStringA& name);
Unk_DungeonCooldownType FUN_1402199e0(const CStringA& name);

// XmlEnumName (enum attribute given by name): placeholder/xmlattr.h.

// Count-prefixed vector streaming.
template <class T> COutputStream& operator<<(COutputStream& out, const std::vector<T>& vec)
{
    out.vfunc_o10_3(vec.size());
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
        FUN_14070f9a0(out, *it);
    return out;
}
template <class T> CInputStream& operator>>(CInputStream& in, std::vector<T>& vec)
{
    unsigned count = in.vfunc_o8_3();
    vec.reserve(count);
    for (unsigned i = 0; i < count; i++) {
        T value;
        FUN_14070f480(in, value);
        vec.push_back(value);
    }
    return in;
}
GameEvent* FUN_1403fb400();
GameEvent* FUN_1403fb9a0();
void FUN_1403fbe50(Unk_GEReader* in, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts);
void FUN_1403fbf30(Unk_GEOut* out, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts);

extern Unk_AttendGiftDataGroup* DAT_143aac2a8;

// Sort-key names (header static shared with several units).
static CStringA s_sortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CStringA s_sortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

#ifndef MS2_HOOK_DLL
// Registration of the event factories by name (dynamic initializers).
static Unk_GEFactoryRegistry s_regAttendGift(L"GameEventAttendGift", FUN_1403fb400);     // 0x143aaee24
static Unk_GEFactoryRegistry s_regCashAttend(L"GameEventCashAttend", FUN_1403fb9a0);     // 0x143aaee25
#endif

// @0x1403fb400
GameEvent* FUN_1403fb400() { return new GameEventAttendGift; }
MS2_REPLACE(0x1403fb400, FUN_1403fb400, 82, 0xE4859B6C);

// @0x1403fb460
CStringW GameEventAttendGift::vfunc_1() { return CStringW(L"GameEventAttendGift"); }
MS2_REPLACE_METHOD(0x1403fb460, GameEventAttendGift, vfunc_1, 61, 0x6936B364);

// @0x1403fb4b0
GameEventAttendGift::GameEventAttendGift()
    : m_i100(0), m_i104(0), m_i108(0), m_i110(0), m_i114(0), m_i118(0), m_i11c(0), m_i120(0), m_b124(false), m_b125(true)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403fb5e0
void GameEventAttendGift::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403fb5e0, GameEventAttendGift, vfunc_2, 6, 0xA9AF6E37);

// @0x1403fb5f0
void GameEventAttendGift::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070fb70(out, &m_28);
    FUN_14070fb70(out, &m_38);
    FUN_14070fae0(out, &m_strName);
    FUN_14070faa0(out, &m_strDesc);
    FUN_14070f820(out, m_b124);
    FUN_14070f820(out, m_b125);
    FUN_14070f9a0(out, m_i120);
    out->WriteByte(m_i114);
    FUN_14070f9a0(out, m_i118);
    out->WriteByte(m_i100);
    if (m_i100 != 0) {
        FUN_14070f9a0(out, m_i104);
        FUN_14070fa20(out, m_i108);
        FUN_14070f9a0(out, m_i110);
    }
    FUN_1403fbf30(out, &m_gifts);
}
MS2_REPLACE_METHOD(0x1403fb5f0, GameEventAttendGift, vfunc_3, 370, 0xF9D3D0D4);

// @0x1403fb770
void GameEventAttendGift::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f6b0(&in->reader, &m_28);
    FUN_14070f6b0(&in->reader, &m_38);
    FUN_14070f5f0(&in->reader, &m_strName);
    FUN_14070f580(&in->reader, &m_strDesc);
    FUN_14070f300(&in->reader, &m_b124);
    FUN_14070f300(&in->reader, &m_b125);
    FUN_14070f480(&in->reader, &m_i120);
    m_i114 = MS2_GE_READ_BYTE(&in->reader);
    FUN_14070f480(&in->reader, &m_i118);
    m_i100 = MS2_GE_READ_BYTE(&in->reader);
    if (m_i100 != 0) {
        FUN_14070f480(&in->reader, &m_i104);
        FUN_14070f500(&in->reader, &m_i108);
        FUN_14070f480(&in->reader, &m_i110);
    }
    FUN_1403fbe50(&in->reader, &m_gifts);
    vfunc_10();
}
MS2_REPLACE_METHOD(0x1403fb770, GameEventAttendGift, vfunc_4, 492, 0x9553F7C9);

// @0x1403fb970
void GameEventAttendGift::vfunc_5() {}
MS2_REPLACE_METHOD(0x1403fb970, GameEventAttendGift, vfunc_5, 6, 0xA9AF6E37);

// @0x1403fb980
void GameEventAttendGift::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403fb980, GameEventAttendGift, vfunc_6, 6, 0xA9AF6E37);

// @0x1403fb990
void GameEventAttendGift::vfunc_10() {}
MS2_REPLACE_METHOD(0x1403fb990, GameEventAttendGift, vfunc_10, 6, 0xA9AF6E37);

// @0x1403fb9a0
GameEvent* FUN_1403fb9a0() { return new GameEventCashAttend; }
MS2_REPLACE(0x1403fb9a0, FUN_1403fb9a0, 82, 0xF5361299);

// @0x1403fba00
CStringW GameEventCashAttend::vfunc_1() { return CStringW(L"GameEventCashAttend"); }
MS2_REPLACE_METHOD(0x1403fba00, GameEventCashAttend, vfunc_1, 61, 0xB5B435BC);

// @0x1403fba50
GameEventCashAttend::GameEventCashAttend() : m_i0(0), m_i4(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403fbb00
void GameEventCashAttend::vfunc_2()
{
    m_i0 = FUN_140718200(&m_68);
    m_i4 = FUN_140718200(&m_70);
    m_strDesc = m_78;
    m_entry = FUN_1403fc330()->FUN_1401ae630(m_i0);
}
MS2_REPLACE_METHOD(0x1403fbb00, GameEventCashAttend, vfunc_2, 189, 0x68160277);

// @0x1403fbbd0
void GameEventCashAttend::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070fb70(out, &m_28);
    FUN_14070fb70(out, &m_38);
    FUN_14070f9a0(out, m_i0);
    FUN_14070f9a0(out, m_i4);
    FUN_14070fae0(out, &m_strDesc);
}
MS2_REPLACE_METHOD(0x1403fbbd0, GameEventCashAttend, vfunc_3, 144, 0xD55548FA);

// @0x1403fbc70
void GameEventCashAttend::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f6b0(&in->reader, &m_28);
    FUN_14070f6b0(&in->reader, &m_38);
    FUN_14070f480(&in->reader, &m_i0);
    FUN_14070f480(&in->reader, &m_i4);
    FUN_14070f5f0(&in->reader, &m_strDesc);
    m_entry = FUN_1403fc330()->FUN_1401ae630(m_i0);
    vfunc_10();
}
MS2_REPLACE_METHOD(0x1403fbc70, GameEventCashAttend, vfunc_4, 275, 0x71A9551D);

// @0x1403fbd90
void GameEventCashAttend::vfunc_5() {}
MS2_REPLACE_METHOD(0x1403fbd90, GameEventCashAttend, vfunc_5, 6, 0xA9AF6E37);

// @0x1403fbda0
void GameEventCashAttend::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403fbda0, GameEventCashAttend, vfunc_6, 6, 0xA9AF6E37);

// @0x1403fbdb0
void GameEventCashAttend::vfunc_10() {}
MS2_REPLACE_METHOD(0x1403fbdb0, GameEventCashAttend, vfunc_10, 6, 0xA9AF6E37);

// @0x1403fbde0
int FUN_1403fbde0(const CStringA& name)
{
    if (name.CompareNoCase("UserValue") == 0)
        return 1;
    else if (name.CompareNoCase("ItemID") == 0)
        return 2;
    else if (name.CompareNoCase("NotUserValue") == 0)
        return 3;
    return 0;
}
MS2_REPLACE(0x1403fbde0, FUN_1403fbde0, 103, 0xCBF0F47C);

// @0x1403fbe50
void FUN_1403fbe50(Unk_GEReader* in, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts)
{
    unsigned count = in->ReadInt();
    for (unsigned i = 0; i < count; i++) {
        MS2Ptr<ItemGift> gift(new ItemGift);
        gift->FUN_14026b100(*reinterpret_cast<Unk_GiftInput*>(in));
        gifts->Add(gift);
    }
}
MS2_REPLACE(0x1403fbe50, FUN_1403fbe50, 211, 0x95AACE8B);

// @0x1403fbf30
void FUN_1403fbf30(Unk_GEOut* out, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts)
{
    out->WriteInt(gifts->GetCount());
    for (unsigned i = 0; i < gifts->GetCount(); i++) {
        MS2Ptr<ItemGift>& gift = (*gifts)[i];
        gift->FUN_14026b030(*reinterpret_cast<Unk_GiftOutput*>(out));
    }
}
MS2_REPLACE(0x1403fbf30, FUN_1403fbf30, 152, 0x0FCC86CE);

// @0x1403fc330
Unk_AttendGiftDataGroup* FUN_1403fc330() { return DAT_143aac2a8; }
MS2_REPLACE(0x1403fc330, FUN_1403fc330, 8, 0xA0DCC569);

// @0x1403fc640
BonusGameBlueMarbleSlot::BonusGameBlueMarbleSlot() : m_type((Unk_BlueMarbleSlotType)0), m_arg1(0), m_arg2(0) {}

// @0x1403fc6a0
void BonusGameBlueMarbleSlot::Load(Unk_140165cf0* pElem)
{
    XmlEnumName<Unk_BlueMarbleSlotType, FUN_140218100>(pElem, "type", m_type);
    FUN_1408731e0(pElem, "arg1", m_arg1);
    FUN_1408731e0(pElem, "arg2", m_arg2);
}
MS2_REPLACE_METHOD(0x1403fc6a0, BonusGameBlueMarbleSlot, Load, 106, 0xFB0C60DC);

// @0x1403fc710
BlueMarbleEventContext::BlueMarbleEventContext(int eventId, const CMsTime& endTime)
    : m_eventId(eventId), m_endTime(endTime), m_consumeItemID(0), m_consumeItemCount(0), m_rewards(10)
{
}

// @0x1403fc7c0
void BlueMarbleEventContext::LoadRewards(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "consumeItemID", m_consumeItemID);
    FUN_1408731e0(pElem, "consumeItemCount", m_consumeItemCount);
    for (Unk_140165cf0* pNode : pElem->FUN_140165cf0("v")) {
        int round = 0;
        FUN_1408731e0(pNode, "round", round);
        MS2Ptr<ItemEntity> spItem(new ItemEntity);
        spItem->vfunc_2(pNode);
        AddReward(round, spItem);
    }
}
MS2_REPLACE_METHOD(0x1403fc7c0, BlueMarbleEventContext, LoadRewards, 455, 0x827CB681);

// @0x1403fc990
void BlueMarbleEventContext::LoadSlots(Unk_140165cf0* pElem)
{
    for (Unk_140165cf0* pNode : pElem->FUN_140165cf0("v")) {
        MS2Ptr<BonusGameBlueMarbleSlot> spSlot(new BonusGameBlueMarbleSlot);
        spSlot->Load(pNode);
        m_slots.push_back(spSlot);
    }
}
MS2_REPLACE_METHOD(0x1403fc990, BlueMarbleEventContext, LoadSlots, 297, 0x14879088);

// @0x1403fcac0
void BlueMarbleEventContext::AddReward(int round, MS2Ptr<ItemEntity> spItem) { m_rewards.SetAt(round, spItem); }

// @0x1403fcb10
EventTimeLimitDungeonContext::EventTimeLimitDungeonContext() : m_eventId(0), m_dungeonId(0) {}

// @0x1403fcb80
void EventTimeLimitDungeonContext::Write(COutputStream& out)
{
    FUN_14070f9a0(out, m_eventId);
    FUN_14070f9a0(out, m_dungeonId);
    FUN_14070f9a0(out, m_rangeTime.m_start.GetSeconds());
    FUN_14070f9a0(out, m_rangeTime.m_end.GetSeconds());
}
MS2_REPLACE_METHOD(0x1403fcb80, EventTimeLimitDungeonContext, Write, 113, 0x253F88D9);

// @0x1403fcc00
void EventTimeLimitDungeonContext::Read(CInputStream& in)
{
    FUN_14070f480(in, m_eventId);
    FUN_14070f480(in, m_dungeonId);
    m_rangeTime.m_start.SetSeconds(in.vfunc_o8_3());
    m_rangeTime.m_end.SetSeconds(in.vfunc_o8_3());
}
MS2_REPLACE_METHOD(0x1403fcc00, EventTimeLimitDungeonContext, Read, 127, 0x829B1FA2);

// @0x1403fcc90
void StampEventContext::Write(COutputStream& out)
{
    out.vfunc_o10_8(m_strTitle);
    out.vfunc_o10_4(m_endTime);
    out.vfunc_o10_3(m_stamps.GetCount());
    out.vfunc_o10_3(m_98);
    out.vfunc_o10_0(m_b9c);
    for (size_t i = 0; i < m_stamps.GetCount(); i++) {
        out.vfunc_o10_3(m_stamps[i]->m_id);
        out.vfunc_o10_1(m_stamps[i]->m_bStamped);
        out.vfunc_o10_3(m_stamps[i]->m_20);
        out.vfunc_o10_3(m_stamps[i]->m_24);
    }
    out.vfunc_o10_3(m_rewards.GetCount());
    for (size_t i = 0; i < m_rewards.GetCount(); i++) {
        out.vfunc_o10_3(m_rewards[i]->m_count);
        out.vfunc_o10_1(m_rewards[i]->m_bReceived);
        m_rewards[i]->m_item.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
        m_rewards[i]->m_item2.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
    m_item.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
}
MS2_REPLACE_METHOD(0x1403fcc90, StampEventContext, Write, 955, 0xDD356D28);

// @0x1403fd060
void StampEventContext::Read(CInPacket& packet)
{
    m_strTitle = packet.vfunc_o8_8();
    m_endTime = packet.vfunc_o8_4();
    size_t count = (unsigned)packet.vfunc_o8_3();
    m_98 = packet.vfunc_o8_3();
    m_b9c = packet.vfunc_o8_0();
    for (size_t i = 0; i < count; i++) {
        MS2Ptr<Stamp> spStamp(new Stamp);
        spStamp->m_id = packet.vfunc_o8_3();
        spStamp->m_bStamped = packet.vfunc_o8_1();
        spStamp->m_20 = packet.vfunc_o8_3();
        spStamp->m_24 = packet.vfunc_o8_3();
        m_stamps.Add(spStamp);
    }
    count = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < count; i++) {
        MS2Ptr<Reward> spReward(new Reward);
        spReward->m_count = packet.vfunc_o8_3();
        spReward->m_bReceived = packet.vfunc_o8_1();
        spReward->m_item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        spReward->m_item2.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_rewards.Add(spReward);
    }
    m_item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
}
MS2_REPLACE_METHOD(0x1403fd060, StampEventContext, Read, 1335, 0xA48E1978);

// @0x1403fd5a0
int StampEventContext::GetStampFlag(int id)
{
    for (size_t i = 0; i < m_stamps.GetCount(); i++) {
        if (m_stamps[i]->m_id == id)
            return m_stamps[i]->m_bStamped != 0;
    }
    return -1;
}
MS2_REPLACE_METHOD(0x1403fd5a0, StampEventContext, GetStampFlag, 175, 0x15B2AC45);

// @0x1403fd660
BOOL StampEventContext::HasStamp(int id)
{
    for (size_t i = 0; i < m_stamps.GetCount(); i++) {
        if (m_stamps[i]->m_id == id)
            return TRUE;
    }
    return FALSE;
}
MS2_REPLACE_METHOD(0x1403fd660, StampEventContext, HasStamp, 116, 0x79A6A7C0);

// @0x1403fd6e0
DungeonExtraRewardCountCtx::DungeonExtraRewardCountCtx()
    : m_18(0), m_dungeonID(0), m_count(0), m_cooldownType((Unk_DungeonCooldownType)0), m_cooldownValue(0)
{
}

// @0x1403fd750
void DungeonExtraRewardCountCtx::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dungeonID", m_dungeonID);
    FUN_140873220(pElem, "count", m_count);
    XmlEnumName<Unk_DungeonCooldownType, FUN_1402199e0>(pElem, "cooldownType", m_cooldownType);
    FUN_1408731e0(pElem, "cooldownValue", m_cooldownValue);
}
MS2_REPLACE_METHOD(0x1403fd750, DungeonExtraRewardCountCtx, Load, 135, 0x7AA036E1);

// @0x1403fd7e0
CInputStream& operator>>(CInputStream& in, DungeonExtraRewardCountCtx& ctx)
{
    FUN_14070f480(in, ctx.m_dungeonID);
    FUN_14070f480(in, ctx.m_18);
    FUN_14070f480(in, ctx.m_count);
    return in;
}
MS2_REPLACE_OVERLOAD(0x1403fd7e0, CInputStream&(CInputStream&, DungeonExtraRewardCountCtx&), operator>>, 90, 0x68A75E42);

// @0x1403fd840
COutputStream& operator<<(COutputStream& out, const DungeonExtraRewardCountCtx& ctx)
{
    FUN_14070f9a0(out, ctx.m_dungeonID);
    FUN_14070f9a0(out, ctx.m_18);
    FUN_14070f9a0(out, ctx.m_count);
    return out;
}
MS2_REPLACE_OVERLOAD(0x1403fd840, COutputStream&(COutputStream&, const DungeonExtraRewardCountCtx&), operator<<, 78, 0x68D550D8);

// @0x1403fd8a0
DungeonBonusRewardCtx::DungeonBonusRewardCtx()
    : m_dungeonID(0), m_groupType((Unk_DungeonGroupType)0), m_itemRolls(0), m_mesoRate(0), m_expRate(0)
{
}

// @0x1403fd930
void DungeonBonusRewardCtx::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dungeonID", m_dungeonID);
    XmlValue(pElem, "groupType", m_groupType);
    FUN_140873360(pElem, "mesoRate", m_mesoRate);
    FUN_140873360(pElem, "expRate", m_expRate);
    FUN_1408731e0(pElem, "itemRolls", m_itemRolls);
    XmlTokenList(pElem, "customDropBoxIds", m_customDropBoxIds);
}
MS2_REPLACE_METHOD(0x1403fd930, DungeonBonusRewardCtx, Load, 193, 0xC7A5F22F);

// @0x1403fda00
void DungeonBonusRewardCtx::Write(COutputStream& out) const
{
    FUN_14070f9a0(out, m_dungeonID);
    FUN_14070f860(out, (unsigned char)m_groupType);
    FUN_14070fa60(out, m_mesoRate);
    FUN_14070fa60(out, m_expRate);
    FUN_14070f960(out, m_itemRolls);
    out << m_customDropBoxIds;
}
MS2_REPLACE_METHOD(0x1403fda00, DungeonBonusRewardCtx, Write, 136, 0xABDF08DD);

// @0x1403fda90
void DungeonBonusRewardCtx::Read(CInputStream& in)
{
    FUN_14070f480(in, m_dungeonID);
    m_groupType = (Unk_DungeonGroupType)in.vfunc_o8_1();
    FUN_14070f540(in, m_mesoRate);
    FUN_14070f540(in, m_expRate);
    FUN_14070f440(in, m_itemRolls);
    in >> m_customDropBoxIds;
}
MS2_REPLACE_METHOD(0x1403fda90, DungeonBonusRewardCtx, Read, 156, 0xFFB55CCC);

// @0x1403fdb40
void DungeonBonusRewardCtx::Merge(const MS2Ptr<DungeonBonusRewardCtx>& other)
{
    if (other == NULL)
        return;
    m_itemRolls += other->m_itemRolls;
    m_mesoRate += other->m_mesoRate;
    m_expRate += other->m_expRate;
    std::copy(other->m_customDropBoxIds.begin(), other->m_customDropBoxIds.end(), std::back_inserter(m_customDropBoxIds));
}
MS2_REPLACE_METHOD(0x1403fdb40, DungeonBonusRewardCtx, Merge, 259, 0xBC70E8D4);

// @0x1403fdc50
__int64 DungeonBonusRewardCtx::ApplyMesoRate(__int64 value)
{
    const double epsilon = 0.001;
    return (__int64)((double)value * m_mesoRate + epsilon);
}
MS2_REPLACE_METHOD(0x1403fdc50, DungeonBonusRewardCtx, ApplyMesoRate, 66, 0x6B05F779);

// @0x1403fdca0
__int64 DungeonBonusRewardCtx::ApplyExpRate(__int64 value)
{
    const double epsilon = 0.001;
    return (__int64)((double)value * m_expRate + epsilon);
}
MS2_REPLACE_METHOD(0x1403fdca0, DungeonBonusRewardCtx, ApplyExpRate, 66, 0x5161F364);

// @0x1403fdcf0
CInputStream& operator>>(CInputStream& in, DungeonBonusRewardCtx& ctx)
{
    ctx.Read(in);
    return in;
}
MS2_REPLACE_OVERLOAD(0x1403fdcf0, CInputStream&(CInputStream&, DungeonBonusRewardCtx&), operator>>, 39, 0x480D13CD);

// @0x1403fdd20
COutputStream& operator<<(COutputStream& out, const DungeonBonusRewardCtx& ctx)
{
    ctx.Write(out);
    return out;
}
MS2_REPLACE_OVERLOAD(0x1403fdd20, COutputStream&(COutputStream&, const DungeonBonusRewardCtx&), operator<<, 39, 0xB772769A);

// @0x1403fdd50
ItemBoxEventContext::ItemBoxEventContext() : m_fieldID(0), m_boxItemID(0), m_3c(0) {}

// @0x1403fdde0
void ItemBoxEventContext::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "fieldID", m_fieldID);
    FUN_140873220(pElem, "boxItemID", m_boxItemID);
    FUN_140873420(pElem, "bannerPath", m_bannerPath);
    FUN_140873420(pElem, "title", m_title);
    FUN_140873420(pElem, "desc", m_desc);
}
MS2_REPLACE_METHOD(0x1403fdde0, ItemBoxEventContext, Load, 164, 0xF3C4745F);

// @0x1403fde90
void ItemBoxEventContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_fieldID);
    out.vfunc_o10_3(m_boxItemID);
    out.vfunc_o10_8(m_title);
    out.vfunc_o10_8(m_desc);
    out.vfunc_o10_8(m_bannerPath);
    out.vfunc_o10_3(m_3c);
}
MS2_REPLACE_METHOD(0x1403fde90, ItemBoxEventContext, Write, 205, 0x94E651EB);

// @0x1403fdf70
void ItemBoxEventContext::Read(CInPacket& packet)
{
    m_fieldID = packet.vfunc_o8_3();
    m_boxItemID = packet.vfunc_o8_3();
    m_title = packet.vfunc_o8_8();
    m_desc = packet.vfunc_o8_8();
    m_bannerPath = packet.vfunc_o8_8();
    m_3c = packet.vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x1403fdf70, ItemBoxEventContext, Read, 502, 0x43A428F1);

// @0x1403fe170
TimeRunEventContext::TimeRunEventContext(int eventId) : m_eventId(eventId), m_1c(0), m_value(0), m_endTime(0), m_rewards(10) {}

// @0x1403fe250
void TimeRunEventContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_value);
    out.vfunc_o10_3(m_1c);
    out.vfunc_o10_3(m_quests.GetCount());
    for (POSITION pos = m_quests.GetStartPosition(); pos != NULL; m_quests.GetNext(pos)) {
        MS2Ptr<QuestContext> spQuest = m_quests.GetValueAt(pos);
        out.vfunc_o10_3(spQuest->m_questId);
        out.vfunc_o10_3(spQuest->m_1c);
        out.vfunc_o10_2(spQuest->m_20);
    }
    m_item.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    out.vfunc_o10_3(m_rewards.GetCount());
    for (POSITION pos = m_rewards.GetHeadPosition(); pos != NULL; m_rewards.GetNext(pos)) {
        unsigned key = m_rewards.GetKeyAt(pos);
        MS2Ptr<ItemEntity> spItem = m_rewards.GetValueAt(pos);
        out.vfunc_o10_3(key);
        spItem->FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
}
MS2_REPLACE_METHOD(0x1403fe250, TimeRunEventContext, Write, 706, 0x6519EA38);

// @0x1403fe520
void TimeRunEventContext::Read(CInPacket& packet)
{
    m_quests.RemoveAll();
    m_value = packet.vfunc_o8_3();
    m_1c = packet.vfunc_o8_3();
    size_t count = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < count; i++) {
        MS2Ptr<QuestContext> spQuest(new QuestContext);
        spQuest->m_questId = packet.vfunc_o8_3();
        spQuest->m_1c = packet.vfunc_o8_3();
        spQuest->m_20 = (unsigned short)packet.vfunc_o8_2();
        m_quests.SetAt(spQuest->m_questId, spQuest);
    }
    m_item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
    count = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < count; i++) {
        MS2Ptr<ItemEntity> spItem(new ItemEntity);
        unsigned key = packet.vfunc_o8_3();
        spItem->FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_rewards.SetAt(key, spItem);
    }
}
MS2_REPLACE_METHOD(0x1403fe520, TimeRunEventContext, Read, 958, 0x0E738D7A);

// @0x1403fe8f0
unsigned TimeRunEventContext::GetNextRewardKey(unsigned value)
{
    for (POSITION pos = m_rewards.GetHeadPosition(); pos != NULL; m_rewards.GetNext(pos)) {
        unsigned key = m_rewards.GetKeyAt(pos);
        if (key > value)
            return key;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1403fe8f0, TimeRunEventContext, GetNextRewardKey, 126, 0x64E1F2D2);

// @0x1403fe980
QuestAdditionalRewardContext::QuestAdditionalRewardContext() : m_itemRates(17, 0.75f, 0.25f, 2.25f, 10)
{
    memset(m_rates, 0, sizeof(m_rates));
}

// @0x1403fea10
void QuestAdditionalRewardContext::Load(CStringW* pValue)
{
    unsigned rate = FUN_140718200(pValue);
    if (rate != 0) {
        for (size_t i = 0; i < _countof(m_rates); i++)
            m_rates[i] = rate;
    } else {
        TiXmlDocument doc;
        Unk_140165cf0* pRoot;
        if (FUN_140166420()->FUN_140397ab0(&doc, *pValue) != 0 && (pRoot = FUN_140345b40(&doc)) != NULL) {
            FUN_140873220(pRoot, "exp", m_rates[0]);
            FUN_140873220(pRoot, "meso", m_rates[1]);
            FUN_140873220(pRoot, "guild_fund", m_rates[2]);
            FUN_140873220(pRoot, "guild_exp", m_rates[3]);
            FUN_140873220(pRoot, "guild_coin", m_rates[4]);
            FUN_140873220(pRoot, "lu", m_rates[5]);
            FUN_140873220(pRoot, "karma", m_rates[6]);
            FUN_140873220(pRoot, "menteeCoin", m_rates[7]);
            for (Unk_140165cf0* pItem = pRoot->FUN_140165cf0("item"); pItem != NULL;
                 pItem = pItem->FUN_140168650("item")) {
                unsigned id = 0;
                unsigned itemRate = 0;
                FUN_140873220(pItem, "id", id);
                FUN_140873220(pItem, "rate", itemRate);
                m_itemRates.SetAt(id, itemRate);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1403fea10, QuestAdditionalRewardContext, Load, 681, 0xFA2E5509);

// @0x1403fecc0
void QuestAdditionalRewardContext::Write(COutputStream& out)
{
    for (size_t i = 0; i < _countof(m_rates); i++)
        out.vfunc_o10_3(m_rates[i]);
    unsigned count = (unsigned)m_itemRates.GetCount();
    out.vfunc_o10_3(count);
    for (POSITION pos = m_itemRates.GetStartPosition(); pos != NULL; m_itemRates.GetNext(pos)) {
        out.vfunc_o10_3(m_itemRates.GetKeyAt(pos));
        out.vfunc_o10_3(m_itemRates.GetValueAt(pos));
    }
}
MS2_REPLACE_METHOD(0x1403fecc0, QuestAdditionalRewardContext, Write, 283, 0x9A1480C0);

// @0x1403fedf0
void QuestAdditionalRewardContext::Read(CInPacket& packet)
{
    for (size_t i = 0; i < _countof(m_rates); i++)
        m_rates[i] = packet.vfunc_o8_3();
    unsigned count = packet.vfunc_o8_3();
    for (size_t i = 0; i < count; i++) {
        unsigned id = packet.vfunc_o8_3();
        unsigned itemRate = packet.vfunc_o8_3();
        m_itemRates.SetAt(id, itemRate);
    }
}
MS2_REPLACE_METHOD(0x1403fedf0, QuestAdditionalRewardContext, Read, 278, 0xC6FE4CCE);

// @0x1403fef10
void GalleryContext::Write(COutputStream& out)
{
    out.vfunc_o10_2(m_cards.GetCount());
    for (size_t i = 0; i < m_cards.GetCount(); i++)
        out.vfunc_o10_3(m_cards[i]->m_id);
    out.vfunc_o10_2(m_items.GetCount());
    for (size_t i = 0; i < m_items.GetCount(); i++)
        m_items[i].FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    out.vfunc_o10_3(m_60);
    out.vfunc_o10_8(m_strTitle);
    out.vfunc_o10_4(m_endTime);
}
MS2_REPLACE_METHOD(0x1403fef10, GalleryContext, Write, 392, 0x0AAA5A49);

// @0x1403ff0a0
void GalleryContext::Read(CInPacket& packet)
{
    int cardCount = (unsigned short)packet.vfunc_o8_2();
    for (int i = 0; i < cardCount; i++) {
        MS2Ptr<Card> spCard(new Card);
        spCard->m_id = packet.vfunc_o8_3();
        m_cards.Add(spCard);
    }
    int itemCount = (unsigned short)packet.vfunc_o8_2();
    for (int i = 0; i < itemCount; i++) {
        ItemEntity item;
        item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_items.Add(item);
    }
    m_60 = packet.vfunc_o8_3();
    m_strTitle = packet.vfunc_o8_8();
    m_endTime = packet.vfunc_o8_4();
}
MS2_REPLACE_METHOD(0x1403ff0a0, GalleryContext, Read, 689, 0x223A401A);

// @0x1403ff360
BOOL GalleryContext::HasCard(int id)
{
    for (size_t i = 0; i < m_cards.GetCount(); i++) {
        if (m_cards[i]->m_id == id)
            return TRUE;
    }
    return FALSE;
}
MS2_REPLACE_METHOD(0x1403ff360, GalleryContext, HasCard, 116, 0x3A942D56);

// @0x1403ff3e0
MS2Ptr<GalleryContext::Card> GalleryContext::GetCard(int index)
{
    int count = (int)m_cards.GetCount();
    if (index < 0 || index >= count) {
        MS2_ASSERT_AT(0x228, 0);
        return 0;
    }
    return m_cards[index];
}
MS2_REPLACE_METHOD(0x1403ff3e0, GalleryContext, GetCard, 185, 0x2AA08563);

// @0x1403ff4a0
void MentoringContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_18);
    out.vfunc_o10_4(m_20);
    out.vfunc_o10_4(m_28);
    out.vfunc_o10_3(m_ids.GetCount());
    for (size_t i = 0; i < m_ids.GetCount(); i++)
        out.vfunc_o10_3(m_ids[i]);
}
MS2_REPLACE_METHOD(0x1403ff4a0, MentoringContext, Write, 238, 0xB91500A1);

// @0x1403ff5a0
void MentoringContext::Read(CInPacket& packet)
{
    m_18 = packet.vfunc_o8_3();
    m_20 = packet.vfunc_o8_4();
    m_28 = packet.vfunc_o8_4();
    unsigned count = packet.vfunc_o8_3();
    for (unsigned i = 0; i < count; i++)
        m_ids.Add(packet.vfunc_o8_3());
}
MS2_REPLACE_METHOD(0x1403ff5a0, MentoringContext, Read, 267, 0x6959083B);

// @0x1403ff6c0
DungeonBuffEventCtx::DungeonBuffEventCtx() : m_dungeonID(0), m_isBeginner(false)
{
}

// The GUID list is parsed as unsigned 64-bit decimals (0x1404082e0).
template <> inline unsigned __int64 XmlConvert<unsigned __int64>(const CString& str)
{
    return _strtoui64(str, NULL, 10);
}

// @0x1403ff720
bool DungeonBuffEventCtx::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dungeonID", m_dungeonID);
    XmlTokenList(pElem, "addifectGUIDs", m_addEffectGUIDs);
    FUN_1408730a0(pElem, "isBeginner", m_isBeginner);
    if (m_addEffectGUIDs.empty())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1403ff720, DungeonBuffEventCtx, Load, 136, 0x8EE196D9);

// @0x1403ff7b0
bool SnowmanContext::Snowman::ReachedGoal(int value)
{
    return value >= m_18;
}
MS2_REPLACE_METHOD(0x1403ff7b0, SnowmanContext::Snowman, ReachedGoal, 52, 0x05947B3A);

// @0x1403ff7f0
bool SnowmanContext::Snowman::BelowLimit(int value)
{
    return value < m_1c;
}
MS2_REPLACE_METHOD(0x1403ff7f0, SnowmanContext::Snowman, BelowLimit, 52, 0x1FA24CFD);

// @0x1403ff830
bool SnowmanContext::Snowman::ReachedBonus(int value)
{
    return value >= m_20;
}
MS2_REPLACE_METHOD(0x1403ff830, SnowmanContext::Snowman, ReachedBonus, 52, 0xB882FE12);

// @0x1403ff870
bool SnowmanContext::Snowman::CanProceed(int goalValue, int limitValue)
{
    bool bReached = ReachedGoal(goalValue);
    if (bReached)
        return false;
    bool bOver = !BelowLimit(limitValue) ? true : false;
    if (bOver)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1403ff870, SnowmanContext::Snowman, CanProceed, 111, 0xE46AF0B0);

// @0x1403ff8f0
void SnowmanContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_eventId);
    out.vfunc_o10_8(m_strTitle);
    out.vfunc_o10_2(m_snowmen.GetCount());
    for (size_t i = 0; i < m_snowmen.GetCount(); i++) {
        MS2Ptr<Snowman>& spSnowman = m_snowmen[i];
        if (!spSnowman) {
            MS2_ASSERT_AT(0x282, "snowman" && 0);
            return;
        }
        out.vfunc_o10_3(spSnowman->m_18);
        out.vfunc_o10_3(spSnowman->m_1c);
        out.vfunc_o10_3(spSnowman->m_20);
        const ATL::CAtlArray<ItemEntity>& items = spSnowman->m_items;
        out.vfunc_o10_2(items.GetCount());
        for (size_t j = 0; j < items.GetCount(); j++)
            items[j].FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
        const ATL::CAtlArray<ItemEntity>& bonusItems = spSnowman->m_bonusItems;
        out.vfunc_o10_2(bonusItems.GetCount());
        for (size_t j = 0; j < bonusItems.GetCount(); j++)
            bonusItems[j].FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
    out.vfunc_o10_4(m_endTime);
}
MS2_REPLACE_METHOD(0x1403ff8f0, SnowmanContext, Write, 769, 0x8D6B039E);

// @0x1403ffc00
void SnowmanContext::Read(CInPacket& packet)
{
    m_eventId = packet.vfunc_o8_3();
    m_strTitle = packet.vfunc_o8_8();
    int snowmanCount = (unsigned short)packet.vfunc_o8_2();
    for (int i = 0; i < snowmanCount; i++) {
        MS2Ptr<Snowman> spSnowman(new Snowman);
        spSnowman->m_18 = packet.vfunc_o8_3();
        spSnowman->m_1c = packet.vfunc_o8_3();
        spSnowman->m_20 = packet.vfunc_o8_3();
        int itemCount = (unsigned short)packet.vfunc_o8_2();
        for (int j = 0; j < itemCount; j++) {
            ItemEntity item;
            item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
            spSnowman->m_items.Add(item);
        }
        int bonusCount = (unsigned short)packet.vfunc_o8_2();
        for (int j = 0; j < bonusCount; j++) {
            ItemEntity item;
            item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
            spSnowman->m_bonusItems.Add(item);
        }
        m_snowmen.Add(spSnowman);
    }
    m_endTime = packet.vfunc_o8_4();
}
MS2_REPLACE_METHOD(0x1403ffc00, SnowmanContext, Read, 1008, 0xEA8CA9B2);

// @0x140400000
MS2Ptr<SnowmanContext::Snowman> SnowmanContext::GetSnowman(int index)
{
    int count = (int)m_snowmen.GetCount();
    if (index < 0 || index >= count) {
        MS2_ASSERT_AT(0x2cc, 0);
        return 0;
    }
    return m_snowmen[index];
}
MS2_REPLACE_METHOD(0x140400000, SnowmanContext, GetSnowman, 185, 0xF55D4007);

// @0x1404000c0
bool RpsGameData::Load(Unk_140165cf0* pElem)
{
    if (pElem == NULL) {
        MS2_ASSERT_AT(0x2d8, 0);
        return false;
    }
    Unk_140165cf0* pRoot = FUN_140345b40(pElem);
    if (pRoot == NULL) {
        MS2_ASSERT_AT(0x2df, 0);
        return false;
    }
    Unk_140165cf0* pPlay = pRoot->FUN_140165cf0("play");
    if (pPlay == NULL) {
        MS2_ASSERT_AT(0x2e7, 0);
        return false;
    }
    Unk_140165cf0* pActions = pPlay->FUN_140165cf0("actions");
    if (pActions == NULL) {
        MS2_ASSERT_AT(0x2ee, 0);
        return false;
    }
    FUN_140873420(pActions, "rock", m_actionNames[0]);
    FUN_140873420(pActions, "paper", m_actionNames[1]);
    FUN_140873420(pActions, "scissors", m_actionNames[2]);
    Unk_140165cf0* pMessages = pPlay->FUN_140165cf0("messages");
    if (pMessages == NULL) {
        MS2_ASSERT_AT(0x2f9, 0);
        return false;
    }
    for (Unk_140165cf0* pNode = FUN_140345b40(pMessages); pNode != NULL; pNode = FUN_1403f0510(pNode)) {
        CStringW strValue;
        FUN_140873420(pNode, "value", strValue);
        m_messages.Add(strValue);
    }
    Unk_140165cf0* pResults = pRoot->FUN_140165cf0("result");
    if (pResults == NULL) {
        MS2_ASSERT_AT(0x309, 0);
        return false;
    }
    for (int i = 0; i < 3; i++) {
        CString strName = FUN_140223380(i);
        Unk_140165cf0* pResult = pResults->FUN_140165cf0(strName);
        if (pResult == NULL) {
            MS2_ASSERT_AT(0x313, 0);
            continue;
        }
        Result& result = m_results[i];
        Unk_140165cf0* pResultActions = pResult->FUN_140165cf0("actions");
        if (pResultActions == NULL) {
            MS2_ASSERT_AT(0x31c, 0);
            return false;
        }
        for (Unk_140165cf0* pNode = FUN_140345b40(pResultActions); pNode != NULL; pNode = FUN_1403f0510(pNode)) {
            CStringW strValue;
            FUN_140873420(pNode, "value", strValue);
            result.m_actions.Add(strValue);
        }
        Unk_140165cf0* pResultMessages = pResult->FUN_140165cf0("messages");
        if (pResultMessages == NULL) {
            MS2_ASSERT_AT(0x32a, 0);
            return false;
        }
        for (Unk_140165cf0* pNode = FUN_140345b40(pResultMessages); pNode != NULL; pNode = FUN_1403f0510(pNode)) {
            CStringW strValue;
            FUN_140873420(pNode, "value", strValue);
            result.m_messages.Add(strValue);
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x1404000c0, RpsGameData, Load, 1295, 0x81870CB5);

// @0x1404005e0
// Sort callback over CAtlArray<MS2Ptr<RpsContext::RewardData> > (not called from the client).
int CompareRpsReward(const void* pLeft, const void* pRight)
{
    if (pLeft == NULL || pRight == NULL) {
        MS2_ASSERT_AT(0x376, 0);
        return 0;
    }
    MS2Ptr<RpsContext::RewardData> spLeft = *static_cast<const MS2Ptr<RpsContext::RewardData>*>(pLeft);
    MS2Ptr<RpsContext::RewardData> spRight = *static_cast<const MS2Ptr<RpsContext::RewardData>*>(pRight);
    return spLeft->m_count < spRight->m_count ? -1 : 1;
}
MS2_REPLACE(0x1404005e0, CompareRpsReward, 203, 0xA1C87D62);

// @0x1404006c0
void RpsContext::Write(COutputStream& out)
{
    out.vfunc_o10_8(m_strTitle);
    int count = (int)m_rewards.GetCount();
    out.vfunc_o10_3(count);
    for (int i = 0; i < count; i++) {
        MS2Ptr<RewardData> spReward = m_rewards[i];
        if (spReward == NULL) {
            MS2_ASSERT_AT(0x345, 0);
            return;
        }
        out.vfunc_o10_3(spReward->m_count);
        int itemCount = (int)spReward->m_items.GetCount();
        out.vfunc_o10_3(itemCount);
        for (int j = 0; j < itemCount; j++)
            spReward->m_items[j].FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
    out.vfunc_o10_3(m_20);
    out.vfunc_o10_3(m_48);
    out.vfunc_o10_4(m_endTime);
}
MS2_REPLACE_METHOD(0x1404006c0, RpsContext, Write, 503, 0xC8BA33F0);

// @0x1404008c0
void RpsContext::Read(CInPacket& packet)
{
    m_strTitle = packet.vfunc_o8_8();
    int count = packet.vfunc_o8_3();
    m_rewards.RemoveAll();
    for (int i = 0; i < count; i++) {
        MS2Ptr<RewardData> spReward(new RewardData);
        spReward->m_count = packet.vfunc_o8_3();
        int itemCount = packet.vfunc_o8_3();
        spReward->m_items.SetCount(itemCount);
        for (int j = 0; j < itemCount; j++)
            spReward->m_items[j].FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_rewards.Add(spReward);
    }
    m_20 = packet.vfunc_o8_3();
    m_48 = packet.vfunc_o8_3();
    m_endTime = packet.vfunc_o8_4();
}
MS2_REPLACE_METHOD(0x1404008c0, RpsContext, Read, 813, 0xBB5BDB82);

// @0x140400c00
bool CoupleDanceContext::LoadReward(Unk_140165cf0* pElem)
{
    if (pElem == NULL) {
        MS2_ASSERT_AT(0x38a, 0);
        return false;
    }
    std::map<int, std::vector<ItemEntity> > dailyItems;
    std::set<int> orders;
    m_dailyItems.clear();
    for (Unk_140165cf0* pDaily = pElem->FUN_140165cf0("daily"); pDaily != NULL; pDaily = pDaily->FUN_140168650("daily")) {
        int order = 0;
        FUN_1408731e0(pDaily, "order", order);
        Unk_140165cf0* pItems = pDaily->FUN_140165cf0("items");
        if (pItems == NULL) {
            MS2_ASSERT_AT(0x39a, 0);
            return false;
        }
        std::vector<ItemEntity> items;
        for (Unk_140165cf0* pItem = pItems->FUN_140165cf0("v"); pItem != NULL; pItem = pItem->FUN_140168650("v")) {
            ItemEntity item;
            item.vfunc_2(pItem);
            items.push_back(item);
        }
        dailyItems.insert(std::make_pair(order, items));
        orders.insert(order);
    }
    for (std::set<int>::iterator it = orders.begin(); it != orders.end(); ++it)
        m_dailyItems.push_back(dailyItems[*it]);
    m_goodEndItems.clear();
    Unk_140165cf0* pGoodEnd = pElem->FUN_140165cf0("goodEndBonus");
    if (pGoodEnd == NULL) {
        MS2_ASSERT_AT(0x3b4, 0);
        return false;
    }
    FUN_140873220(pGoodEnd, "count", m_goodEndCount);
    Unk_140165cf0* pItems = pGoodEnd->FUN_140165cf0("items");
    if (pItems == NULL) {
        MS2_ASSERT_AT(0x3bc, 0);
        return false;
    }
    for (Unk_140165cf0* pItem = pItems->FUN_140165cf0("v"); pItem != NULL; pItem = pItem->FUN_140168650("v")) {
        ItemEntity item;
        item.vfunc_2(pItem);
        m_goodEndItems.push_back(item);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140400c00, CoupleDanceContext, LoadReward, 1117, 0xE66847B2);

// @0x140401070
bool CoupleDanceContext::LoadDance(Unk_140165cf0* pElem)
{
    if (pElem == NULL) {
        MS2_ASSERT_AT(0x3e6, 0);
        return false;
    }
    Unk_140165cf0* pDances = pElem->FUN_140165cf0("dances");
    if (pDances == NULL) {
        MS2_ASSERT_AT(0x3ed, 0);
        return false;
    }
    for (Unk_140165cf0* pDance = FUN_140345b40(pDances); pDance != NULL; pDance = FUN_1403f0510(pDance)) {
        CStringW strAnim;
        FUN_140873420(pDance, "anim", strAnim);
        m_dances.push_back(strAnim);
    }
    Unk_140165cf0* pPlay = pElem->FUN_140165cf0("play");
    if (pPlay == NULL) {
        MS2_ASSERT_AT(0x3fa, 0);
        return false;
    }
    FUN_140873220(pPlay, "maxRound", m_maxRound);
    Unk_140165cf0* pStart = pElem->FUN_140165cf0("start");
    if (pStart == NULL) {
        MS2_ASSERT_AT(0x403, 0);
        return false;
    }
    FUN_140873220(pStart, "fieldID", m_fieldId);
    m_steps.clear();
    m_steps.resize(8);
    for (size_t i = 0; i < 8; i++) {
        CString strPath = CoupleDanceStepName((int)i);
        if (strPath.CompareNoCase("none") == 0) {
            MS2_ASSERT_AT(0x411, 0);
            continue;
        }
        ATL::CAtlArray<CString> names;
        FUN_14015f0b0(strPath, names, ".");
        Unk_140165cf0* pNode = NULL;
        for (size_t j = 0; j < names.GetCount(); j++) {
            if (pNode == NULL) {
                pNode = pElem->FUN_140165cf0(names[j]);
                continue;
            }
            pNode = pNode->FUN_140165cf0(names[j]);
        }
        if (pNode == NULL) {
            MS2_ASSERT_AT(0x425, 0);
            return false;
        }
        Step& step = m_steps[i];
        Unk_140165cf0* pAction = pNode->FUN_140165cf0("action");
        if (pAction != NULL) {
            CStringW strAnim;
            FUN_140873420(pAction, "anim", strAnim);
            step.m_action = strAnim;
        }
        Unk_140165cf0* pMessage = pNode->FUN_140165cf0("message");
        if (pMessage != NULL) {
            CStringW strValue;
            FUN_140873420(pMessage, "value", strValue);
            step.m_message = strValue;
        }
        if (step.m_action.IsEmpty() && step.m_message.IsEmpty()) {
            MS2_ASSERT_AT(0x43d, 0);
            return false;
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x140401070, CoupleDanceContext, LoadDance, 1339, 0x8638015F);

// @0x1404015c0
void CoupleDanceContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_eventId);
    out.vfunc_o10_4(m_beginTime);
    out.vfunc_o10_4(m_endTime);
    out.vfunc_o10_3((int)m_dailyItems.size());
    for (std::vector<std::vector<ItemEntity> >::const_iterator it = m_dailyItems.begin(); it != m_dailyItems.end(); ++it) {
        out.vfunc_o10_3((int)(*it).size());
        for (std::vector<ItemEntity>::const_iterator jt = (*it).begin(); jt != (*it).end(); ++jt)
            const_cast<ItemEntity&>(*jt).FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
    out.vfunc_o10_2((short)m_goodEndCount);
    out.vfunc_o10_3((int)m_goodEndItems.size());
    for (std::vector<ItemEntity>::const_iterator it = m_goodEndItems.begin(); it != m_goodEndItems.end(); ++it)
        const_cast<ItemEntity&>(*it).FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    out.vfunc_o10_1((unsigned char)m_maxRound);
    out.vfunc_o10_3((int)m_dances.size());
    for (std::vector<CStringW>::const_iterator it = m_dances.begin(); it != m_dances.end(); ++it)
        out.vfunc_o10_8(*it);
    out.vfunc_o10_3((int)m_steps.size());
    for (std::vector<Step>::const_iterator it = m_steps.begin(); it != m_steps.end(); ++it) {
        const Step& step = *it;
        out.vfunc_o10_8(step.m_action);
        out.vfunc_o10_8(step.m_message);
    }
    out.vfunc_o10_3(m_fieldId);
}
MS2_REPLACE_METHOD(0x1404015c0, CoupleDanceContext, Write, 1197, 0x1BF42E6B);

// @0x140401a80
void CoupleDanceContext::Read(CInPacket& packet)
{
    m_eventId = packet.vfunc_o8_3();
    m_beginTime = packet.vfunc_o8_4();
    m_endTime = packet.vfunc_o8_4();
    m_dailyItems.clear();
    size_t dayCount = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < dayCount; i++) {
        std::vector<ItemEntity> items;
        size_t itemCount = (unsigned)packet.vfunc_o8_3();
        for (size_t j = 0; j < itemCount; j++) {
            ItemEntity item;
            item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
            items.push_back(item);
        }
        m_dailyItems.push_back(items);
    }
    m_goodEndCount = (unsigned short)packet.vfunc_o8_2();
    size_t goodEndCount = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < goodEndCount; i++) {
        ItemEntity item;
        item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_goodEndItems.push_back(item);
    }
    m_maxRound = packet.vfunc_o8_1();
    size_t danceCount = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < danceCount; i++)
        m_dances.push_back(packet.vfunc_o8_8());
    m_steps.clear();
    size_t stepCount = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < stepCount; i++) {
        Step step;
        step.m_action = packet.vfunc_o8_8();
        step.m_message = packet.vfunc_o8_8();
        m_steps.push_back(step);
    }
    m_fieldId = packet.vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x140401a80, CoupleDanceContext, Read, 1517, 0xCC3E3829);

// @0x140402080
const CoupleDanceContext::Step& CoupleDanceContext::GetStep(int index) const
{
    return m_steps.at(index);
}
MS2_REPLACE_METHOD(0x140402080, CoupleDanceContext, GetStep, 40, 0xEE1EF5A5);

// @0x1404020b0
// MS2-FUNCTIONAL: ceil is the CRT import call in the exe, a direct call here (as in uinametag.cpp)
__int64 CNpcShopGivePointContextCNSpring::GetGivePoint(__int64 price, int currencyType, int label)
{
    if (price == 0)
        return 0;
    if (currencyType != 4 && currencyType != 9)
        return 0;
    unsigned percent = m_normalPercent;
    if (label == 3)
        percent = m_specialPercent;
    double point = price * percent / 10000.0;
    return (__int64)ceil(point);
}
MS2_REPLACE_METHOD(0x1404020b0, CNpcShopGivePointContextCNSpring, GetGivePoint, 142, 0x7525554E);

// @0x140402150
MS2Ptr<CNpcShopGivePointContextBase> CNpcShopGivePointContextBase::Create(int type, const CStringW& strPath)
{
    if (type == 1) {
        MS2Ptr<CNpcShopGivePointContextCNSpring> spContext(new CNpcShopGivePointContextCNSpring);
        if (spContext) {
            TiXmlDocument doc;
            if (FUN_140166420()->FUN_140397ab0(&doc, strPath) == 0)
                return 0;
            Unk_140165cf0* pRoot = FUN_140345b40(&doc);
            if (pRoot == NULL)
                return 0;
            spContext->m_type = type;
            FUN_140873220(pRoot, "giveItemID", spContext->m_giveItemId);
            FUN_140873220(pRoot, "normalPercent", spContext->m_normalPercent);
            FUN_140873220(pRoot, "specialPercent", spContext->m_specialPercent);
        }
        return spContext.get();
    }
    return 0;
}
MS2_REPLACE(0x140402150, CNpcShopGivePointContextBase::Create, 562, 0xADC16AE1);

// @0x140402390
__int64 CNpcShopGivePointContextBase::GetGivePoint(MS2Ptr<CNpcShopGivePointContextBase> spContext,
                                                   MS2Ptr<CNpcShopProductBase> spProduct)
{
    if (spContext == NULL || spProduct == NULL)
        return 0;
    if (spContext->GetType() == 1) {
        MS2Ptr<CNpcShopGivePointContextCNSpring> spSpring(
            dynamic_cast<CNpcShopGivePointContextCNSpring*>(spContext.get()));
        if (spSpring)
            return spSpring->GetGivePoint(spProduct->FUN_140db8180(), spProduct->m_currencyType, spProduct->m_label);
    }
    return 0;
}

// @0x140402560
void ReactorContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_eventId);
    out.vfunc_o10_3(m_28);
    out.vfunc_o10_4(m_endTime);
    int count = (int)m_30.GetCount();
    out.vfunc_o10_3(count);
    for (int i = 0; i < count; i++)
        out.vfunc_o10_3(m_30[i]);
}
MS2_REPLACE_METHOD(0x140402560, ReactorContext, Write, 215, 0x53831722);

// @0x140402640
void ReactorContext::Read(CInPacket& packet)
{
    m_eventId = packet.vfunc_o8_3();
    m_28 = packet.vfunc_o8_3();
    m_endTime = packet.vfunc_o8_4();
    m_30.RemoveAll();
    int count = packet.vfunc_o8_3();
    for (int i = 0; i < count; i++) {
        unsigned value = packet.vfunc_o8_3();
        m_30.Add(value);
    }
}
MS2_REPLACE_METHOD(0x140402640, ReactorContext, Read, 292, 0x39050600);

// @0x140402770
void TreeWateringContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_nEventId);
    int stepCount = (int)m_steps.GetCount();
    out.vfunc_o10_3(stepCount);
    for (POSITION pos = m_steps.GetStartPosition(); pos != NULL; m_steps.GetNext(pos)) {
        TreeWatering_TreeStep* pStep = m_steps.GetValueAt(pos);
        out.vfunc_o10_3(pStep->m_step);
        out.vfunc_o10_4(pStep->m_beginTime.Get());
        out.vfunc_o10_4(pStep->m_endTime.Get());
    }
    int dayCount = (int)m_emotionDays.GetCount();
    out.vfunc_o10_3(dayCount);
    for (int i = 0; i < dayCount; i++) {
        MS2Ptr<TreeWatering_EmotionDay> spDay = m_emotionDays[i];
        out.vfunc_o10_4(spDay->m_beginTime.Get());
        out.vfunc_o10_4(spDay->m_endTime.Get());
    }
    out.vfunc_o10_3(m_nDailyLimit);
    out.vfunc_o10_3(m_8c);
    out.vfunc_o10_1((unsigned char)m_90);
    out.vfunc_o10_3(m_94);
    out.vfunc_o10_3(m_nBonusLimit);
    out.vfunc_o10_3(m_9c);
    out.vfunc_o10_1((unsigned char)m_a0);
    out.vfunc_o10_3(m_a4);
    int resourceCount = (int)m_resources.GetCount();
    out.vfunc_o10_3(resourceCount);
    for (POSITION pos = m_resources.GetStartPosition(); pos != NULL; m_resources.GetNext(pos)) {
        TreeWatering_TreeResource* pResource = m_resources.GetValueAt(pos);
        out.vfunc_o10_3(pResource->m_id);
        out.vfunc_o10_7(pResource->m_20);
    }
    out.vfunc_o10_3(m_f0);
    out.vfunc_o10_7(m_strTreeName);
    out.vfunc_o10_3(m_nWaterItemId);
    out.vfunc_o10_7(m_strStateWater);
    out.vfunc_o10_7(m_strStateBonus);
    out.vfunc_o10_7(m_str118);
}
MS2_REPLACE_METHOD(0x140402770, TreeWateringContext, Write, 1437, 0x7D2AE94E);

// @0x140402d20
void TreeWateringContext::Read(CInPacket& packet)
{
    m_nEventId = packet.vfunc_o8_3();
    m_steps.RemoveAll();
    int stepCount = packet.vfunc_o8_3();
    for (int i = 0; i < stepCount; i++) {
        MS2Ptr<TreeWatering_TreeStep> spStep(new TreeWatering_TreeStep);
        spStep->m_step = packet.vfunc_o8_3();
        spStep->m_beginTime = packet.vfunc_o8_4();
        spStep->m_endTime = packet.vfunc_o8_4();
        m_steps.SetAt(spStep->m_step, spStep);
    }
    m_emotionDays.RemoveAll();
    int dayCount = packet.vfunc_o8_3();
    for (int i = 0; i < dayCount; i++) {
        MS2Ptr<TreeWatering_EmotionDay> spDay(new TreeWatering_EmotionDay);
        spDay->m_beginTime = packet.vfunc_o8_4();
        spDay->m_endTime = packet.vfunc_o8_4();
        m_emotionDays.Add(spDay);
    }
    m_nDailyLimit = packet.vfunc_o8_3();
    m_8c = packet.vfunc_o8_3();
    m_90 = packet.vfunc_o8_1();
    m_94 = packet.vfunc_o8_3();
    m_nBonusLimit = packet.vfunc_o8_3();
    m_9c = packet.vfunc_o8_3();
    m_a0 = packet.vfunc_o8_1();
    m_a4 = packet.vfunc_o8_3();
    m_resources.RemoveAll();
    int resourceCount = packet.vfunc_o8_3();
    for (int i = 0; i < resourceCount; i++) {
        MS2Ptr<TreeWatering_TreeResource> spResource(new TreeWatering_TreeResource);
        spResource->m_id = packet.vfunc_o8_3();
        spResource->m_20 = packet.vfunc_o8_7();
        m_resources.SetAt(spResource->m_id, spResource);
    }
    m_f0 = packet.vfunc_o8_3();
    m_strTreeName = packet.vfunc_o8_7();
    m_nWaterItemId = packet.vfunc_o8_3();
    m_strStateWater = packet.vfunc_o8_7();
    m_strStateBonus = packet.vfunc_o8_7();
    m_str118 = packet.vfunc_o8_7();
}
MS2_REPLACE_METHOD(0x140402d20, TreeWateringContext, Read, 2538, 0x9A328910);

// @0x140403710
MS2Ptr<TreeWatering_TreeStep> TreeWateringContext::GetStep(const CMsTime& time)
{
    for (POSITION pos = m_steps.GetStartPosition(); pos != NULL; m_steps.GetNext(pos)) {
        TreeWatering_TreeStep* pStep = m_steps.GetValueAt(pos);
        if (time > pStep->m_beginTime && time < pStep->m_endTime)
            return pStep;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140403710, TreeWateringContext, GetStep, 249, 0x02ADFBA6);

// @0x140403810
MS2Ptr<TreeWatering_TreeResource> TreeWateringContext::GetResource(int id)
{
    MS2Ptr<TreeWatering_TreeResource> spResource = 0;
    if (m_resources.Lookup(id, spResource))
        return spResource;
    return 0;
}
MS2_REPLACE_METHOD(0x140403810, TreeWateringContext, GetResource, 170, 0x64A4C01A);

// @0x1404038c0
bool TreeWateringContext::FUN_1404038c0(const CMsTime& now)
{
    for (size_t i = 0; i < m_emotionDays.GetCount(); i++) {
        if (m_emotionDays[i]->m_beginTime < now && now < m_emotionDays[i]->m_endTime)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1404038c0, TreeWateringContext, FUN_1404038c0, 186, 0xD98CD175);

// @0x140403980
void Unk_FieldObjectDropContext::Write(COutputStream& out)
{
    FUN_1403d7730(out, m_fieldIds);
    FUN_1403d7730(out, m_objectIds);
    FUN_1403d7730(out, m_itemIds);
    FUN_14070f9a0(out, m_percent);
}
MS2_REPLACE_METHOD(0x140403980, Unk_FieldObjectDropContext, Write, 103, 0x40D0EDB5);

// @0x1404039f0
void Unk_FieldObjectDropContext::Read(CInPacket& packet)
{
    FUN_1403d7440(packet, m_fieldIds);
    FUN_1403d7440(packet, m_objectIds);
    FUN_1403d7440(packet, m_itemIds);
    FUN_14070f480(packet, m_percent);
}
MS2_REPLACE_METHOD(0x1404039f0, Unk_FieldObjectDropContext, Read, 123, 0xAE40BE2F);

// @0x140403a80
CStringW Unk_FieldObjectDropContext::ToString()
{
    CStringW str = StringFormat(L"fieldId={0} objectId={1} itemId={2} percent={3}", m_fieldIds.GetCount(),
                                m_objectIds.GetCount(), m_itemIds.GetCount(), m_percent);
    return str;
}
MS2_REPLACE_METHOD(0x140403a80, Unk_FieldObjectDropContext, ToString, 197, 0xDF76F612);

// @0x140403b50
bool Unk_FieldObjectDropContext::IsValid()
{
    if (m_fieldIds.IsEmpty())
        return false;
    if (m_objectIds.IsEmpty())
        return false;
    if (m_itemIds.IsEmpty())
        return false;
    if (m_percent == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140403b50, Unk_FieldObjectDropContext, IsValid, 115, 0x61835F4F);

// @0x140403bd0
void Unk_FieldObjectDropListContext::Write(COutputStream& out)
{
    FUN_1403d7730(out, m_fieldIds);
    FUN_1403d7730(out, m_objectIds);
    FUN_1403d7730(out, m_itemIds);
    FUN_1403d7730(out, m_percents);
}
MS2_REPLACE_METHOD(0x140403bd0, Unk_FieldObjectDropListContext, Write, 107, 0x20FA03BD);

// @0x140403c50
void Unk_FieldObjectDropListContext::Read(CInPacket& packet)
{
    FUN_1403d7440(packet, m_fieldIds);
    FUN_1403d7440(packet, m_objectIds);
    FUN_1403d7440(packet, m_itemIds);
    FUN_1403d7440(packet, m_percents);
}
MS2_REPLACE_METHOD(0x140403c50, Unk_FieldObjectDropListContext, Read, 123, 0x9D600FC0);

// @0x140403ce0
CStringW Unk_FieldObjectDropListContext::ToString()
{
    CStringW str = StringFormat(L"fieldId={0} objectId={1} itemId={2} percent={3}", m_fieldIds.GetCount(),
                                m_objectIds.GetCount(), m_itemIds.GetCount(), m_percents.GetCount());
    return str;
}
MS2_REPLACE_METHOD(0x140403ce0, Unk_FieldObjectDropListContext, ToString, 233, 0x855AAB70);

// @0x140403dd0
bool Unk_FieldObjectDropListContext::IsValid()
{
    if (m_fieldIds.IsEmpty())
        return false;
    if (m_objectIds.IsEmpty())
        return false;
    if (m_itemIds.IsEmpty())
        return false;
    if (m_percents.IsEmpty())
        return false;
    if (m_itemIds.GetCount() != m_percents.GetCount())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140403dd0, Unk_FieldObjectDropListContext, IsValid, 181, 0x1E077BD0);

// @0x140403e90
void Unk_DayItemContext::Write(COutputStream& out)
{
}
MS2_REPLACE_METHOD(0x140403e90, Unk_DayItemContext, Write, 11, 0x02239C70);

// @0x140403eb0
void Unk_DayItemContext::Read(CInPacket& packet)
{
}
MS2_REPLACE_METHOD(0x140403eb0, Unk_DayItemContext, Read, 11, 0x02239C70);

// @0x140403ed0
void Unk_DayItemContext::Period::Write(COutputStream& out)
{
}
MS2_REPLACE_METHOD(0x140403ed0, Unk_DayItemContext::Period, Write, 11, 0x02239C70);

// @0x140403ef0
void Unk_DayItemContext::Period::Read(CInPacket& packet)
{
}
MS2_REPLACE_METHOD(0x140403ef0, Unk_DayItemContext::Period, Read, 11, 0x02239C70);

// @0x140403f10
CStringW Unk_DayItemContext::ToString()
{
    CStringW str = StringFormat(L"itemId={0} weekends={1} weekdays={2} customized={3}", m_itemIds.GetCount(),
                                m_weekends, m_weekdays, m_customized);
    return str;
}
MS2_REPLACE_METHOD(0x140403f10, Unk_DayItemContext, ToString, 164, 0x1782E300);

// @0x140403fc0
void Unk_DayItemContext::GetItemIds(ATL::CAtlArray<unsigned>& rOut)
{
}
MS2_REPLACE_METHOD(0x140403fc0, Unk_DayItemContext, GetItemIds, 11, 0x02239C70);

// @0x140403fe0
void Unk_DayItemContext::GetActivePeriodIds(ATL::CAtlArray<unsigned>& rOut)
{
    for (unsigned i = 0; i < m_periods.GetCount(); i++) {
        Period* pPeriod = m_periods[i];
        if (!pPeriod->IsActive())
            continue;
        rOut.Add(pPeriod->m_id);
    }
}
MS2_REPLACE_METHOD(0x140403fe0, Unk_DayItemContext, GetActivePeriodIds, 144, 0xA44FADDC);

// @0x140404080
bool Unk_DayItemContext::IsValid()
{
    if (m_itemIds.IsEmpty())
        return false;
    if (m_weekdays == 0 && m_weekends == 0 && m_customized == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140404080, Unk_DayItemContext, IsValid, 81, 0xEE8F8925);

// @0x1404040e0
bool Unk_DayItemContext::IsActive()
{
    if (!IsValid())
        return false;
    bool bActive = false;
    for (unsigned i = 0; i < m_periods.GetCount(); i++) {
        Period* pPeriod = m_periods[i];
        if (pPeriod->IsActive()) {
            bActive = true;
            break;
        }
    }
    return bActive;
}
MS2_REPLACE_METHOD(0x1404040e0, Unk_DayItemContext, IsActive, 157, 0xB469CA6D);

// The index of a value in an array, -1 when absent (instantiated here first; name invented).
template <class T>
int Unk_ArrayFind(const ATL::CAtlArray<T>& arr, const T& value)
{
    for (int i = 0; i < (int)arr.GetCount(); i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// @0x140404190
bool Unk_DayItemContext::IsTodayEnabled()
{
    if (!IsValid())
        return false;
    CMsTime now(FUN_140869440());
    int dayOfWeek = now.GetDayOfWeek();
    bool bWeekend = dayOfWeek == 1 || dayOfWeek == 7;
    if ((m_weekends != 0 && bWeekend) || (m_weekdays != 0 && !bWeekend) ||
        (m_customized != 0 && Unk_ArrayFind(m_customizedDays, dayOfWeek) != -1))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140404190, Unk_DayItemContext, IsTodayEnabled, 195, 0xBBCB0884);

// @0x140404260
void Unk_DayItemContext::Update()
{
}
MS2_REPLACE_METHOD(0x140404260, Unk_DayItemContext, Update, 6, 0xA9AF6E37);

// @0x140404270
void Unk_DayItemContext::Period::Update()
{
    CMsTime now(FUN_140869440());
    if (m_state == 2 && now > m_endTime)
        m_state = 4;
}
MS2_REPLACE_METHOD(0x140404270, Unk_DayItemContext::Period, Update, 84, 0x2C6AEA11);

// @0x1404042d0
bool Unk_DayItemContext::Period::IsActive()
{
    CMsTime now(FUN_140869440());
    if (m_state != 2)
        return false;
    if (now < m_beginTime)
        return false;
    if (now > m_endTime)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1404042d0, Unk_DayItemContext::Period, IsActive, 115, 0xB7BDAEA0);

// @0x140404370
void Unk_DayItemContext::Period::Clear()
{
}
MS2_REPLACE_METHOD(0x140404370, Unk_DayItemContext::Period, Clear, 6, 0xA9AF6E37);

// @0x140404380
void Unk_DayItemContext::GetPeriods(ATL::CAtlArray<MS2Ptr<Period>>& rOut)
{
    rOut.Append(m_periods);
}
MS2_REPLACE_METHOD(0x140404380, Unk_DayItemContext, GetPeriods, 41, 0x33354AC0);

// @0x1404043b0
Unk_DayItemContext::Period* Unk_DayItemContext::FindPeriod(int id)
{
    for (unsigned i = 0; i < m_periods.GetCount(); i++) {
        Period* pPeriod = m_periods[i];
        if (pPeriod->m_id == id)
            return pPeriod;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1404043b0, Unk_DayItemContext, FindPeriod, 129, 0x280E7C47);

// @0x140404440
void BurningLevelupContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_eventId);
    out.vfunc_o10_4(m_endTime);
    out.vfunc_o10_3(m_beginLevel);
    out.vfunc_o10_3(m_endLevel);
    out.vfunc_o10_3(m_burningBonus);
    out.vfunc_o10_3(m_additionalEffectId);
    out.vfunc_o10_8(m_setCharacterPopupStringKey);
    out.vfunc_o10_8(m_setCharacterPopupBottomStringKey);
    out.vfunc_o10_8(m_descPopupStringKey);
    out.vfunc_o10_8(m_rewardUiTitleStringKey);
    out.vfunc_o10_2(m_equipNametagSymbolId);
    out.vfunc_o10_2((short)m_28.size());
    for (std::set<int>::const_iterator it = m_28.begin(); it != m_28.end(); ++it)
        out.vfunc_o10_3(*it);
    out.vfunc_o10_3((int)m_rewardItems.size());
    for (std::vector<ItemEntity>::iterator it = m_rewardItems.begin(); it != m_rewardItems.end(); ++it) {
        ItemEntity& item = *it;
        item.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
    out.vfunc_o10_0(m_spJumpingItem.get() != 0);
    if (m_spJumpingItem.get() != 0) {
        m_spJumpingItem->FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
        out.vfunc_o10_3(m_8c);
        out.vfunc_o10_3(m_tutorialEndFieldId);
        out.vfunc_o10_8(m_jumpingItemDescPopupStringKey);
        out.vfunc_o10_8(m_jumpingItemNotifyStringKey);
        out.vfunc_o10_8(m_jumpingCompleteStringKey);
    }
}
MS2_REPLACE_METHOD(0x140404440, BurningLevelupContext, Write, 1228, 0xEBF6AE9B);

// @0x140404920
void BurningLevelupContext::Read(CInPacket& packet)
{
    m_eventId = packet.vfunc_o8_3();
    m_endTime = packet.vfunc_o8_4();
    m_beginLevel = (unsigned short)packet.vfunc_o8_3();
    m_endLevel = (unsigned short)packet.vfunc_o8_3();
    m_burningBonus = packet.vfunc_o8_3();
    m_additionalEffectId = packet.vfunc_o8_3();
    m_setCharacterPopupStringKey = packet.vfunc_o8_8();
    m_setCharacterPopupBottomStringKey = packet.vfunc_o8_8();
    m_descPopupStringKey = packet.vfunc_o8_8();
    m_rewardUiTitleStringKey = packet.vfunc_o8_8();
    m_equipNametagSymbolId = packet.vfunc_o8_2();
    m_28.clear();
    size_t count = (unsigned short)packet.vfunc_o8_2();
    for (size_t i = 0; i < count; i++) {
        m_28.insert(packet.vfunc_o8_3());
    }
    m_rewardItems.clear();
    size_t itemCount = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < itemCount; i++) {
        ItemEntity item;
        item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_rewardItems.push_back(item);
    }
    m_spJumpingItem = 0;
    m_tutorialEndFieldId = 0;
    m_8c = 0;
    if (packet.vfunc_o8_0()) {
        m_spJumpingItem.AssignRaw(new ItemEntity);
        m_spJumpingItem->FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_8c = (unsigned short)packet.vfunc_o8_3();
        m_tutorialEndFieldId = packet.vfunc_o8_3();
        m_jumpingItemDescPopupStringKey = packet.vfunc_o8_8();
        m_jumpingItemNotifyStringKey = packet.vfunc_o8_8();
        m_jumpingCompleteStringKey = packet.vfunc_o8_8();
    }
}
MS2_REPLACE_METHOD(0x140404920, BurningLevelupContext, Read, 2047, 0x658E5ECE);

// @0x140405130
bool BurningLevelupContext::IsBurningLevel(unsigned short level)
{
    return level > m_beginLevel && level < m_endLevel;
}
MS2_REPLACE_METHOD(0x140405130, BurningLevelupContext, IsBurningLevel, 75, 0x6821B9A1);

// @0x140405190
int BurningLevelupContext::GetBonusLevel(unsigned short level)
{
    if (!IsBurningLevel(level))
        return 0;
    unsigned remain = (level - m_beginLevel) % (m_burningBonus + 1);
    if (remain == 0)
        return 0;
    unsigned bonus = m_burningBonus + 1 - remain;
    if (level + bonus > m_endLevel)
        return m_endLevel - level;
    return bonus;
}
MS2_REPLACE_METHOD(0x140405190, BurningLevelupContext, GetBonusLevel, 154, 0x642A77BE);

// @0x140405230
bool BurningLevelupContext::HasTarget(int id)
{
    return m_28.size() == 0 || m_28.find(id) != m_28.end();
}
MS2_REPLACE_METHOD(0x140405230, BurningLevelupContext, HasTarget, 137, 0x25E725D3);

// @0x1404052c0
FestivalContext::FestivalContext() : m_18(0), m_1c(0), m_beginTime(FUN_140869440()), m_endTime(FUN_140869440())
{
}

// @0x140405350
void FestivalContext::Write(COutputStream& out)
{
    out.vfunc_o10_1((unsigned char)m_18);
    out.vfunc_o10_1((unsigned char)m_1c);
}
MS2_REPLACE_METHOD(0x140405350, FestivalContext, Write, 69, 0x4AA66412);

// @0x1404053a0
void FestivalContext::Read(CInPacket& packet)
{
    m_18 = packet.vfunc_o8_1();
    m_1c = packet.vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x1404053a0, FestivalContext, Read, 109, 0x9B9542AA);

// @0x140405420
FieldEffectContext::FieldEffectContext()
{
    Clear();
}

// @0x140405490
void FieldEffectContext::Clear()
{
    m_fieldIds.RemoveAll();
    m_effect = L"";
}
MS2_REPLACE_METHOD(0x140405490, FieldEffectContext, Clear, 56, 0x47BE3FD7);

// @0x1404054d0
BOOL FieldEffectContext::HasField(int id)
{
    for (size_t i = 0; i < m_fieldIds.GetCount(); i++) {
        if (m_fieldIds[i] == id)
            return TRUE;
    }
    return FALSE;
}
MS2_REPLACE_METHOD(0x1404054d0, FieldEffectContext, HasField, 107, 0xC6AF9F2C);

// @0x140405550
void FieldEffectContext::Write(COutputStream& out)
{
    int count = (int)m_fieldIds.GetCount();
    out.vfunc_o10_1((unsigned char)count);
    for (int i = 0; i < count; i++)
        out.vfunc_o10_3(m_fieldIds[i]);
    out.vfunc_o10_8(m_effect);
}
MS2_REPLACE_METHOD(0x140405550, FieldEffectContext, Write, 181, 0x40FE575D);

// @0x140405610
void FieldEffectContext::Read(CInPacket& packet)
{
    m_fieldIds.RemoveAll();
    int count = packet.vfunc_o8_1();
    for (int i = 0; i < count; i++)
        m_fieldIds.Add(packet.vfunc_o8_3());
    m_effect = packet.vfunc_o8_8();
}
MS2_REPLACE_METHOD(0x140405610, FieldEffectContext, Read, 257, 0xAE99D2C4);

// @0x140405720
CollectItemGroupContext::CollectItemGroupContext()
{
    m_eventId = 0;
    m_beginTime = 0;
    m_endTime = 0;
}

// @0x1404057d0
void CollectItemGroupContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_eventId);
    out.vfunc_o10_8(m_name);
    out.vfunc_o10_4(m_beginTime);
    out.vfunc_o10_4(m_endTime);
    int count = (int)m_conditions.size();
    out.vfunc_o10_3(count);
    for (int i = 0; i < count; i++)
        m_conditions[i].FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    m_result.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
}
MS2_REPLACE_METHOD(0x1404057d0, CollectItemGroupContext, Write, 261, 0x10B258AA);

// @0x1404058e0
void CollectItemGroupContext::Read(CInPacket& packet)
{
    m_eventId = packet.vfunc_o8_3();
    m_name = packet.vfunc_o8_8();
    m_beginTime = packet.vfunc_o8_4();
    m_endTime = packet.vfunc_o8_4();
    m_conditions.clear();
    m_conditionKeys.clear();
    int count = packet.vfunc_o8_3();
    for (int i = 0; i < count; i++) {
        ItemEntity item;
        item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        AddCondition(item);
    }
    m_result.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
}
MS2_REPLACE_METHOD(0x1404058e0, CollectItemGroupContext, Read, 500, 0xD4A02B48);

// @0x140405ae0
void CollectItemGroupContext::AddCondition(ItemEntity& item)
{
    m_conditions.push_back(item);
    m_conditionKeys.insert(std::make_pair(std::make_pair(item.vfunc_o18_0(), item.vfunc_o18_1()), item.vfunc_o18_2()));
}
MS2_REPLACE_METHOD(0x140405ae0, CollectItemGroupContext, AddCondition, 241, 0x2F1A2F54);

// @0x140405be0
ArcadeOpenContext::ArcadeOpenContext()
{
    m_eventId = 0;
    m_arcadeId = 0;
    m_rewardCountPerDay = 0;
}

// @0x140405c50
void ArcadeOpenContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_arcadeId);
}
MS2_REPLACE_METHOD(0x140405c50, ArcadeOpenContext, Write, 43, 0xD74A2FC1);

// @0x140405c90
void ArcadeOpenContext::Read(CInPacket& packet)
{
    m_arcadeId = packet.vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x140405c90, ArcadeOpenContext, Read, 61, 0x85F0495A);

// @0x140405ce0
BingoContext::BingoContext()
{
}

// @0x140405d70
bool BingoContext::LoadNumbers(CStringW strPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, strPath) == 0)
        return false;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return false;
    ATL::CAtlMap<unsigned, bool> used(17, 0.75f, 0.25f, 2.25f, 10);
    for (Unk_140165cf0* pNumber = pRoot->FUN_140165cf0("number"); pNumber != NULL;
         pNumber = pNumber->FUN_140168650("number")) {
        CStringW value;
        NumbersPtr spNumbers(Unk_BingoNewTag(0));
        FUN_140873b30(pNumber, "value", value);
        if (value.GetLength() == 0)
            return false;
        FUN_1401d9a30(value, *spNumbers, L",");
        if (spNumbers->GetCount() == 0)
            return false;
        for (size_t i = 0; i < spNumbers->GetCount(); i++) {
            if (used.Lookup(spNumbers->GetAt(i)) != NULL)
                return false;
            used.SetAt(spNumbers->GetAt(i), true);
            if (used.GetCount() >= 25)
                used.RemoveAll();
        }
        m_numbers.Add(spNumbers);
    }
    return true;
}

// @0x140406120
bool BingoContext::LoadRewards(CStringW strPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, strPath) == 0)
        return false;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return false;
    for (Unk_140165cf0* pReward = pRoot->FUN_140165cf0("reward"); pReward != NULL;
         pReward = pReward->FUN_140168650("reward")) {
        RewardPtr spItems(Unk_BingoNewTag(0));
        for (Unk_140165cf0* pItem = pReward->FUN_140165cf0("item"); pItem != NULL;
             pItem = pItem->FUN_140168650("item")) {
            ItemEntity item;
            item.vfunc_2(pItem);
            spItems->Add(item);
        }
        if (spItems->GetCount() > 0)
            m_rewards.Add(spItems);
    }
    return true;
}

// @0x140406320
bool BingoContext::LoadFreeItem(CStringW str)
{
    m_freeItemId = FUN_140274f40(str);
    return true;
}

// @0x140406370
bool BingoContext::LoadCashItem(CStringW str)
{
    m_cashItemId = FUN_140274f40(str);
    return true;
}

// @0x1404063c0
BingoContext::NumbersPtr BingoContext::GetTodayNumbers()
{
    if (m_numbers.GetCount() == 0)
        return 0;
    int days = (int)(CMsTime(FUN_140869440()) - CMsTime(m_beginTime.GetYear(), m_beginTime.GetMonth(),
                                                          m_beginTime.GetDay(), 0, 0, 0)).GetDays();
    days = days % m_numbers.GetCount();
    return m_numbers[days];
}
MS2_REPLACE_METHOD(0x1404063c0, BingoContext, GetTodayNumbers, 385, 0xB12A9063);

// @0x140406550
int BingoContext::CountLines(__int64 seed, ATL::CAtlArray<int>& checked)
{
    ATL::CAtlArray<int> board;
    for (int n = 1; n <= kBoardSize * kBoardSize; n++)
        board.Add(n);
    FUN_1401cdae0(board, (unsigned)seed);
    bool cells[kBoardSize][kBoardSize];
    for (size_t i = 0; i < board.GetCount(); i++) {
        if (FUN_1402bacf0(checked, board[i]) == -1) {
            bool* row = cells[i % kBoardSize];
            row[i / kBoardSize] = false;
        } else {
            bool* row = cells[i % kBoardSize];
            row[i / kBoardSize] = true;
        }
    }
    int lines = 0;
    for (int x = 0; x < kBoardSize; x++) {
        for (int y = 0; y < kBoardSize; y++) {
            if (!cells[y][x])
                break;
            if (y == 4)
                lines++;
        }
    }
    for (int x = 0; x < kBoardSize; x++) {
        for (int y = 0; y < kBoardSize; y++) {
            if (!cells[x][y])
                break;
            if (y == kBoardSize - 1)
                lines++;
        }
    }
    for (int i = 0; i < kBoardSize; i++) {
        if (!cells[i][i])
            break;
        if (i == kBoardSize - 1)
            lines++;
    }
    for (int i = 0; i < kBoardSize; i++) {
        if (!cells[i][kBoardSize - 1 - i])
            break;
        if (i == 4)
            lines++;
    }
    return lines;
}
MS2_REPLACE_METHOD(0x140406550, BingoContext, CountLines, 800, 0x948ECF4F);

// @0x140406880
void BingoContext::Write(COutputStream& out)
{
    int count = (int)m_rewards.GetCount();
    out.vfunc_o10_3(count);
    for (int i = 0; i < count; i++) {
        RewardPtr spItems = m_rewards[i];
        int itemCount = (int)spItems->GetCount();
        out.vfunc_o10_3(itemCount);
        for (int j = 0; j < itemCount; j++)
            spItems->GetAt(j).FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
    out.vfunc_o10_3(m_freeItemId);
    out.vfunc_o10_3(m_cashItemId);
}
MS2_REPLACE_METHOD(0x140406880, BingoContext, Write, 325, 0x87EA28D3);

// @0x1404069d0
void BingoContext::Read(CInPacket& packet)
{
    m_numbers.RemoveAll();
    m_rewards.RemoveAll();
    int count = packet.vfunc_o8_3();
    for (int i = 0; i < count; i++) {
        RewardPtr spItems(Unk_BingoNewTag(0));
        int itemCount = packet.vfunc_o8_3();
        for (int j = 0; j < itemCount; j++) {
            ItemEntity item;
            item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
            spItems->Add(item);
        }
        m_rewards.Add(spItems);
    }
    m_freeItemId = packet.vfunc_o8_3();
    m_cashItemId = packet.vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x1404069d0, BingoContext, Read, 467, 0x77CEB52C);

// @0x140406bb0
LimitedQuantityContext::LimitedQuantityContext() : m_eventId(0), m_1c(0), m_20(0)
{
}

// @0x140406c30
void LimitedQuantityContext::Write(COutputStream& out)
{
    if (m_1c == 0 || m_20 == 0)
        return;
    out.vfunc_o10_3(m_1c);
    out.vfunc_o10_3(m_20);
    int count = (int)m_items.size();
    std::map<unsigned long, int>::iterator it = m_items.begin();
    std::map<unsigned long, int>::iterator end = m_items.end();
    out.vfunc_o10_3(count);
    for (; it != end; it++) {
        out.vfunc_o10_3((*it).first);
        out.vfunc_o10_3((*it).second);
    }
}
MS2_REPLACE_METHOD(0x140406c30, LimitedQuantityContext, Write, 300, 0x4F24E218);

// @0x140406d70
void LimitedQuantityContext::Read(CInPacket& packet)
{
    m_1c = packet.vfunc_o8_3();
    m_20 = packet.vfunc_o8_3();
    unsigned count = packet.vfunc_o8_3();
    m_items.clear();
    for (unsigned i = 0; i < count; i++) {
        unsigned long itemId = packet.vfunc_o8_3();
        int quantity = packet.vfunc_o8_3();
        m_items[itemId] = quantity;
    }
}
MS2_REPLACE_METHOD(0x140406d70, LimitedQuantityContext, Read, 294, 0x17D11A9A);

// @0x140406ea0
bool LimitedQuantityContext::ParseRange(CStringW str)
{
    std::vector<int> parts;
    FUN_1402929a0(str, parts, L",");
    if (parts.size() != 2)
        return false;
    m_1c = parts[0];
    m_20 = parts[1];
    return true;
}

// @0x140406f70
bool LimitedQuantityContext::LoadItems(CStringW strPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, strPath) == 0)
        return false;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return false;
    for (Unk_140165cf0* pItem = pRoot->FUN_140165cf0("item"); pItem != NULL; pItem = pItem->FUN_140168650("item")) {
        unsigned long itemId = 0;
        int quantity = 0;
        FUN_140873220(pItem, "itemID", itemId);
        FUN_1408731e0(pItem, "quantity", quantity);
        if (itemId == 0 || quantity < 0)
            return false;
        m_items[itemId] = quantity;
    }
    return true;
}

// @0x140407120
EventShopNpcContext::EventShopNpcContext(int a, int b, int c, int d)
{
    m_18 = a;
    m_1c = b;
    m_20 = c;
    m_24 = d;
}

// @0x140407190
int EventShopNpcContext::Get18()
{
    return m_18;
}
MS2_REPLACE_METHOD(0x140407190, EventShopNpcContext, Get18, 14, 0x72E52537);

// @0x1404071b0
int EventShopNpcContext::Get1c()
{
    return m_1c;
}
MS2_REPLACE_METHOD(0x1404071b0, EventShopNpcContext, Get1c, 14, 0x8AEE455B);

// @0x1404071d0
int EventShopNpcContext::Get20()
{
    return m_20;
}
MS2_REPLACE_METHOD(0x1404071d0, EventShopNpcContext, Get20, 14, 0xA25B27BF);

// @0x1404071f0
int EventShopNpcContext::Get24()
{
    return m_24;
}
MS2_REPLACE_METHOD(0x1404071f0, EventShopNpcContext, Get24, 14, 0xBA6447E3);

// @0x140407210
LongTermAttendGiftContext::LongTermAttendGiftContext(int eventId)
    : m_eventId(eventId), m_40(0), m_48(0), m_4c(1), m_maxAttendance(0), m_merat(0)
{
}

// @0x140407300
void LongTermAttendGiftContext::Write(COutputStream& out)
{
    out.vfunc_o10_8(m_eventTag);
    out.vfunc_o10_4(m_40);
    out.vfunc_o10_3(m_48);
    out.vfunc_o10_0(m_4c);
    out.vfunc_o10_3((int)m_rewards.GetCount());
    for (size_t i = 0; i < m_rewards.GetCount(); i++) {
        out.vfunc_o10_3(m_rewards[i]->m_count);
        out.vfunc_o10_1(m_rewards[i]->m_1c);
        m_rewards[i]->m_item01.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
        m_rewards[i]->m_item02.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
    out.vfunc_o10_4(m_beginTime.Get());
    out.vfunc_o10_4(m_endTime.Get());
    out.vfunc_o10_8(m_title);
    out.vfunc_o10_3(m_merat);
    out.vfunc_o10_3(m_maxAttendance);
}
MS2_REPLACE_METHOD(0x140407300, LongTermAttendGiftContext, Write, 629, 0x77209FF9);

// @0x140407580
void LongTermAttendGiftContext::Read(CInPacket& packet)
{
    m_eventTag = packet.vfunc_o8_8();
    m_40 = packet.vfunc_o8_4();
    m_48 = packet.vfunc_o8_3();
    m_4c = packet.vfunc_o8_0();
    size_t count = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < count; i++) {
        MS2Ptr<Reward> spReward(new Reward);
        spReward->m_count = packet.vfunc_o8_3();
        spReward->m_1c = (bool)packet.vfunc_o8_1();
        spReward->m_item01.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        spReward->m_item02.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_rewards.Add(spReward);
    }
    m_beginTime = CMsTime(packet.vfunc_o8_4());
    m_endTime = CMsTime(packet.vfunc_o8_4());
    m_title = packet.vfunc_o8_8();
    m_merat = packet.vfunc_o8_3();
    m_maxAttendance = packet.vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x140407580, LongTermAttendGiftContext, Read, 1174, 0xE734B2EC);

// ==== 0x140402080 .. 0x140407a20 continue above this line ====

// @0x140407a20
// The CoupleDanceContext::Step node path (dot separated, from the dance root) of each dance step.
CString CoupleDanceStepName(int step)
{
    switch (step) {
    case 0:
        return "start";
    case 1:
        return "play.ready";
    case 2:
        return "play.select";
    case 3:
        return "play.waitResult";
    case 4:
        return "play.result.success";
    case 5:
        return "play.result.fail";
    case 6:
        return "end.normal";
    case 7:
        return "end.good";
    default:
        return "none";
    }
}
MS2_REPLACE(0x140407a20, CoupleDanceStepName, 406, 0x124427D1);

// ==== COMDAT tail drivers (w203) ====
// The exe lays this obj's COMDAT tail with the MS2Ptr<T>::Release/ReleaseImpl copies of every event context type and the
// std::map<int,int> / set<pair<unsigned,int>> / set<Unk_UGCUploadType> / vector<MS2Ptr<EventTimeLimitDungeonContext>>
// glue that gameevent.cpp's own COMDATs (0x1403d86c0.., ~MS2Ptr<T> 0x1403e4df0..) call. The original TU construct
// that instantiated them first is unknown; these never-called drivers instantiate the same members (tplpin pairs them).
#include "ms2/placeholder/dungeonroomshutdowncontext.h"
enum Unk_UGCUploadType
{
};
class CGameEventValueItemTradeRestriction {
public:
    class RestrictionData : public CPtred {
    public:
        char m_pad_18[0x1b0];
    };
};
template <class T> static void Unk_GECDriveRelease(MS2Ptr<T>* p) { p->~MS2Ptr(); }
template <class C> static void Unk_GECDriveTree(C& c, const typename C::value_type& v, const typename C::key_type& k)
{
    C copy(c);
    c.insert(v);
    c.lower_bound(k);
    c.erase(c.begin());
    c.erase(k);
    for (typename C::iterator it = c.begin(); it != c.end(); ++it) {}
    if (c.size() == 0)
        c.clear();
}
void Unk_GECDriveTail(std::map<int, int>& m, std::set<std::pair<unsigned, int> >& sp, std::set<Unk_UGCUploadType>& su,
                      std::set<int>& si, std::set<unsigned>& sn, std::map<unsigned long, int>& mk,
                      std::vector<MS2Ptr<EventTimeLimitDungeonContext> >& vt, std::vector<unsigned __int64>& vq,
                      const std::vector<CoupleDanceContext::Step>& steps, std::vector<ItemEntity>& items)
{
    Unk_GECDriveTree(m, std::make_pair(1, 1), 1);
    m[1] = 2;
    { std::map<int, int> other; other = m; }
    Unk_GECDriveTree(sp, std::make_pair(1u, 1), std::make_pair(1u, 1));
    Unk_GECDriveTree(su, (Unk_UGCUploadType)0, (Unk_UGCUploadType)0);
    Unk_GECDriveTree(si, 0, 0);
    Unk_GECDriveTree(sn, 0u, 0u);
    for (std::set<unsigned>::const_iterator it = sn.begin(); it != sn.end(); ++it) {}
    for (std::set<unsigned>::_Unchecked_iterator it = sn._Unchecked_begin(), itEnd = sn._Unchecked_end(); it != itEnd; ++it) {}
    sn.key_comp();
    si.emplace(0);
    std::_Get_unwrapped(static_cast<const std::set<int>&>(si).begin());
    mk.equal_range(0);
    mk.erase(0);
    vt.reserve(vt.size() + 1);
    vt.push_back(MS2Ptr<EventTimeLimitDungeonContext>());
    vt.push_back(vt[0]);
    { std::vector<MS2Ptr<EventTimeLimitDungeonContext> > tmp(vt); }
    for (std::vector<MS2Ptr<EventTimeLimitDungeonContext> >::iterator it = vt.begin(); it != vt.end(); ++it) {}
    if (vt.capacity() == 0)
        vt.clear();
    vq.emplace_back(0ull);
    steps[0];
    int n = 0;
    std::pair<int, std::vector<ItemEntity> > pr(n, items);
}
// The header-inline getter uicashattenddialog.cpp calls (its exe copy is in this tail).
int Unk_GECDriveCashAttend(GameEventCashAttend* p) { return p->FUN_1403fbdc0(); }
// CoupleDanceContext's member vectors (its dtor 0x1403e5b40 calls their _Tidy copies here).
void Unk_GECDriveCoupleDance(CoupleDanceContext* p)
{
    p->m_dailyItems.~vector();
    p->m_goodEndItems.~vector();
    p->m_steps.~vector();
    p->m_dances.~vector();
}
// The range holds two of the CRT's static-inline memmove_s copies (two original TUs' tails).
// @0x1403fb2e0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
// @0x1403fc520
MS2_EMIT_CRT_MEMMOVE_S_COPY(3);

// @0x1403f58e0
// std::set<unsigned>::_Destroy_if_node(_Nodeptr) written out (emplace path, called from gameevent.cpp's
// tail 0x1403da280/0x1403de2f0): instantiating it binds _Tree_node<unsigned>::_Freenode0, whose progress/symbols.tsv row
// 0x1407aa170 (unit_1407a4f20) is a 0x30-byte-node copy (cmptree DIFFER 14018f400/1407acc60); the exe calls 0x14017b7a0.
void FUN_14017b7a0(std::allocator<std::_Tree_node<unsigned, void*> >& al, std::_Tree_node<unsigned, void*>* p);
void Unk_SetUintDestroyIfNode(std::set<unsigned>& s, std::_Tree_node<unsigned, void*>* p)
{
    std::allocator<std::_Tree_node<unsigned, void*> >& al = s._Getal();
    std::_Default_allocator_traits<std::allocator<std::_Tree_node<unsigned, void*> > >::destroy(al, std::addressof(p->_Myval));
    FUN_14017b7a0(al, p);
}
void Unk_GECDriveReleases(void** pp)
{
    Unk_GECDriveRelease((MS2Ptr<DungeonRoomShutdownContext>*)pp[0]);
    Unk_GECDriveRelease((MS2Ptr<MesoRevivalEventContext>*)pp[1]);
    Unk_GECDriveRelease((MS2Ptr<NpcEventDropEventContext>*)pp[2]);
    Unk_GECDriveRelease((MS2Ptr<OntimeEventContext>*)pp[3]);
    Unk_GECDriveRelease((MS2Ptr<PreminmMarketSaleEventContext>*)pp[4]);
    Unk_GECDriveRelease((MS2Ptr<CGameEventValueItemTradeRestriction::RestrictionData>*)pp[5]);
    Unk_GECDriveRelease((MS2Ptr<SAHotTimeEventContext>*)pp[6]);
    Unk_GECDriveRelease((MS2Ptr<SkillUpgradeSaleEventContext>*)pp[7]);
    Unk_GECDriveRelease((MS2Ptr<ArcadeOpenContext>*)pp[8]);
    Unk_GECDriveRelease((MS2Ptr<BingoContext>*)pp[9]);
    Unk_GECDriveRelease((MS2Ptr<BlueMarbleEventContext>*)pp[10]);
    Unk_GECDriveRelease((MS2Ptr<BurningLevelupContext>*)pp[11]);
    Unk_GECDriveRelease((MS2Ptr<CollectItemGroupContext>*)pp[12]);
    Unk_GECDriveRelease((MS2Ptr<CoupleDanceContext>*)pp[13]);
    Unk_GECDriveRelease((MS2Ptr<DungeonBonusRewardCtx>*)pp[14]);
    Unk_GECDriveRelease((MS2Ptr<DungeonExtraRewardCountCtx>*)pp[15]);
    Unk_GECDriveRelease((MS2Ptr<EnchantRateEventContext>*)pp[16]);
    Unk_GECDriveRelease((MS2Ptr<EventQuestContext>*)pp[17]);
    Unk_GECDriveRelease((MS2Ptr<EventTimeLimitDungeonContext>*)pp[18]);
    Unk_GECDriveRelease((MS2Ptr<FestivalContext>*)pp[19]);
    Unk_GECDriveRelease((MS2Ptr<FieldEffectContext>*)pp[20]);
    Unk_GECDriveRelease((MS2Ptr<GalleryContext>*)pp[21]);
    Unk_GECDriveRelease((MS2Ptr<ItemBoxEventContext>*)pp[22]);
    Unk_GECDriveRelease((MS2Ptr<LongTermAttendGiftContext>*)pp[23]);
    Unk_GECDriveRelease((MS2Ptr<QuestAdditionalRewardContext>*)pp[24]);
    Unk_GECDriveRelease((MS2Ptr<ReactorContext>*)pp[25]);
    Unk_GECDriveRelease((MS2Ptr<RpsContext>*)pp[26]);
    Unk_GECDriveRelease((MS2Ptr<RpsGameData>*)pp[27]);
    Unk_GECDriveRelease((MS2Ptr<SaleCube>*)pp[28]);
    Unk_GECDriveRelease((MS2Ptr<SnowmanContext>*)pp[29]);
    Unk_GECDriveRelease((MS2Ptr<StampEventContext>*)pp[30]);
    Unk_GECDriveRelease((MS2Ptr<TimeRunEventContext>*)pp[31]);
    Unk_GECDriveRelease((MS2Ptr<TreeWateringContext>*)pp[32]);
}
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1403f5580 ; ps2: map<int,int> COMDAT copy kept in this TU (gameevent.cpp's _Lbound calls it)
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x1403f5950 ; ps2: map<int,int> COMDAT copy
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x1403f73d0 ; ps2: map<int,int> COMDAT copy
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x1403f9ab0 ; ps2: map<int,int> COMDAT copy
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1403fa440 ; ps2: map<int,int> COMDAT copy
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@I_NV?$CElementTraits@I@ATL@@V?$CElementTraits@_N@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140414ec0 ; ps2: this TU's byte-identical copy (0x1404579e0 in the table)
// MS2-PIN: ?RemoveNode@?$CAtlMap@I_NV?$CElementTraits@I@ATL@@V?$CElementTraits@_N@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140414fb0 ; ps2: this TU's byte-identical copy (0x140458a50 in the table)
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9a8c0-0x142c9a920 .text$yd
