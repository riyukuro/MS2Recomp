// gameeventvalue.cpp - the event values of CGameEventValueManager (see gameeventvalue.h): each a lock and the state
// the GameEvent* handlers write and the game reads.
//
// MS2-UNIT: commonfiles\gameeventvalue.cpp
// MS2-RANGE: 0x140422c10-0x140446320 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@0@Z 0x14042ae30 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@1@0@Z 0x14042ae80 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@1@0@Z 0x14042aed0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@1@0@Z 0x14042af20 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@1@0@Z 0x14042af70 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@0@Z 0x14042b1a0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@$$QEA_N@Z 0x14042b1f0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@1@0@Z 0x14042b3d0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14042b420 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@1@0@Z 0x14042b470 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14042b4c0 ; unique
// MS2-PIN: ??$?0AEBI$$Z$$V@?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBI@1@V?$tuple@$$V@1@@Z 0x14042b880 ; prop
// MS2-PIN: ??$?0AEBI$$Z$$V@?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBI@1@V?$tuple@$$V@1@@Z 0x14042b8d0 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14042c420 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14042c470 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBI@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@QEAA@AEAV?$tuple@AEBI@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14042c810 ; prop
// MS2-PIN: ??$?0V?$tuple@AEBI@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@QEAA@AEAV?$tuple@AEBI@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14042c860 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VEventShopNpcContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@1@@Z 0x14042cd80 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VItemBoxEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@1@@Z 0x14042cda0 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VLimitedQuantityContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@1@@Z 0x14042cdc0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x14042d030 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VItemBoxEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x14042d100 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VLimitedQuantityContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x14042d1d0 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042eb10 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042eba0 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VBurningLevelupContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042ede0 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VBurningLevelupContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042ee70 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VCollectItemGroupContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042f0b0 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VCollectItemGroupContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042f140 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VItemBoxEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042f380 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VItemBoxEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042f410 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VLimitedQuantityContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042f650 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VLimitedQuantityContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042f6e0 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBII@std@@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@AEAU?$pair@$$CBII@1@1@Z 0x140431130 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VEventShopNpcContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@1@AEAU?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@1@1@Z 0x140431b50 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VItemBoxEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@1@AEAU?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@1@1@Z 0x140431eb0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VLimitedQuantityContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@1@AEAU?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@1@1@Z 0x140432210 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBII@std@@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@AEAU?$pair@$$CBII@1@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@@Z 0x140433d10 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBII@std@@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBII@1@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@@Z 0x14043af60 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VEventShopNpcContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@1@@Z 0x14043bb90 ; unique
// MS2-PIN: ??$_Try_emplace@AEBI$$V@?$map@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x14043eed0 ; unique
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@0@AEBV10@@Z 0x14043fe10 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@0@AEBV10@@Z 0x14043fe20 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@YAPEAU?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@0@AEAU10@@Z 0x14043ffa0 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@YAPEAU?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@0@AEAU10@@Z 0x14043ffb0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@0@AEAV10@@Z 0x140440090 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@0@AEAV10@@Z 0x1404400a0 ; unique
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@0@AEAV10@@Z 0x1404400b0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140440820 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x1404408d0 ; prop
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VItemBoxEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140441800 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VLimitedQuantityContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x1404418a0 ; unique
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@YAAEAU?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@0@AEAU10@@Z 0x140441dd0 ; unique
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@YAAEAU?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@0@AEAU10@@Z 0x140441de0 ; unique
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@YAAEAU?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@0@AEAU10@@Z 0x140441df0 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@0@AEAV10@@Z 0x140441ea0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441eb0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441ec0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441ed0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441ee0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@0@AEAV10@@Z 0x140441f40 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441f70 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441f80 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441f90 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140442140 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140442150 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140442160 ; prop
// MS2-PIN: ??$make_pair@AEAHAEAV?$MS2Ptr@VArcadeOpenContext@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VArcadeOpenContext@@@@@0@AEAHAEAV?$MS2Ptr@VArcadeOpenContext@@@@@Z 0x140442500 ; unique
// MS2-PIN: ??$make_pair@AEAIAEAV?$MS2Ptr@VBurningLevelupContext@@@@@std@@YA?AU?$pair@IV?$MS2Ptr@VBurningLevelupContext@@@@@0@AEAIAEAV?$MS2Ptr@VBurningLevelupContext@@@@@Z 0x140442560 ; unique
// MS2-PIN: ??$try_emplace@$$V@?$map@IV?$MS2Ptr@VLimitedQuantityContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x1404427f0 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@1@@Z 0x140444770 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@QEAA@XZ 0x1404447b0 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@1@@Z 0x1404447d0 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@QEAA@XZ 0x140444810 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@1@@Z 0x140444830 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@QEAA@XZ 0x140444870 ; unique
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@1@@Z 0x140444bb0 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@1@@Z 0x140444bf0 ; unique
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@1@@Z 0x140444c30 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140444e70 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@1@@Z 0x140444f10 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140444f50 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@1@@Z 0x140444f70 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140444fb0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@1@@Z 0x140444fd0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140445010 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@QEAA@XZ 0x140445520 ; prop
// MS2-PINS-END tplpin
// cf9: call-graph pins accepted by tplpin --simulate.
// MS2-PIN: ??$_Adl_verify_range1@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@V12@@std@@YAXAEBV?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x14042ccb0
// MS2-PIN: ??$_Adl_verify_range@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@V12@@std@@YAXAEBV?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@0@0@Z 0x14042ccc0
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$MS2Ptr@VCollectItemGroupContext@@@@@?$vector@V?$MS2Ptr@VCollectItemGroupContext@@@@V?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@AEAAXAEBV?$MS2Ptr@VCollectItemGroupContext@@@@@Z 0x14042e230
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VCollectItemGroupContext@@@@@?$vector@V?$MS2Ptr@VCollectItemGroupContext@@@@V?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCollectItemGroupContext@@@@QEAV2@AEBV2@@Z 0x14042e3b0
// MS2-PIN: ??$_Insert@AEBV?$MS2Ptr@VEventShopNpcContext@@@@@?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@U_Iterator_base0@2@@1@AEBV?$MS2Ptr@VEventShopNpcContext@@@@@Z 0x140430d50
// MS2-PIN: ??$_Lbound@K@?$_Tree@V?$_Tmap_traits@KV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@1@AEBK@Z 0x14043ea20
// MS2-PIN: ??$emplace_back@AEBV?$MS2Ptr@VCollectItemGroupContext@@@@@?$vector@V?$MS2Ptr@VCollectItemGroupContext@@@@V?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VCollectItemGroupContext@@@@@Z 0x1404415e0
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@1@$$QEA_N@Z 0x14042b0b0
// MS2-PIN: ??$_Insert_range@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@U_Iterator_base0@2@@1@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@1@1Uforward_iterator_tag@1@@Z 0x14043e430
// MS2-PIN: ??0?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VEventShopNpcContext@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@1@@Z 0x140443ef0
// MS2-PIN: ??$?0AEAHAEAV?$MS2Ptr@VArcadeOpenContext@@@@$0A@@?$pair@HV?$MS2Ptr@VArcadeOpenContext@@@@@std@@QEAA@AEAHAEAV?$MS2Ptr@VArcadeOpenContext@@@@@Z 0x14042ac50
// MS2-PIN: ??$?0AEAIAEAV?$MS2Ptr@VBurningLevelupContext@@@@$0A@@?$pair@IV?$MS2Ptr@VBurningLevelupContext@@@@@std@@QEAA@AEAIAEAV?$MS2Ptr@VBurningLevelupContext@@@@@Z 0x14042acf0
// MS2-PIN: ??$forward@AEAV?$MS2Ptr@VArcadeOpenContext@@@@@std@@YAAEAV?$MS2Ptr@VArcadeOpenContext@@@@AEAV1@@Z 0x140441e60
// MS2-PIN: ??0?$MS2Ptr@VUnk_DayItemContext@@@@QEAA@XZ 0x140443d80
// MS2-PIN: ??0?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VEventShopNpcContext@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@1@@Z 0x140444030
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$MS2Ptr@VFestivalContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VFestivalContext@@@@@3@@ATL@@IEAA@I@Z 0x140446040
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@3@@ATL@@IEAA@I@Z 0x1404460c0
// MS2-PIN: ??$addressof@U?$pair@$$CBII@std@@@std@@YAPEAU?$pair@$$CBII@0@AEAU10@@Z 0x14043ff60
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@0@AEAV10@@Z 0x140440060
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@0@AEAV10@@Z 0x140441f20
// MS2-PIN: ??0?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VEventShopNpcContext@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@1@@Z 0x140443fb0
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@1@@Z 0x140444af0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@_KPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@_K@std@@@1@@Z 0x140444890
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$MS2Ptr@VFestivalContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VFestivalContext@@@@@3@@ATL@@QEAA@II@Z 0x140445c60
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@3@@ATL@@QEAA@II@Z 0x140445ce0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@PEAU01@@Z 0x140430560
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404305f0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140430680
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140430710
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x140444350
// MS2-PIN: ??0?$map@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@@std@@QEAA@XZ 0x140445750
// MS2-PIN: ??$_Insert_nohint@AEB_KU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@_KU?$less@_K@std@@V?$allocator@_K@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@_N@1@_NAEB_KU_Not_a_node_tag@1@@Z 0x14043e020
// MS2-PIN: ??$construct@PEAU?$_List_node@V?$MS2Ptr@VBurningLevelupContext@@@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$MS2Ptr@VBurningLevelupContext@@@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VBurningLevelupContext@@@@PEAX@std@@@1@QEAPEAU?$_List_node@V?$MS2Ptr@VBurningLevelupContext@@@@PEAX@1@AEAPEAU31@@Z 0x140440120
// MS2-PIN: ??$construct@PEAU?$_List_node@V?$MS2Ptr@VEventShopNpcContext@@@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$MS2Ptr@VEventShopNpcContext@@@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VEventShopNpcContext@@@@PEAX@std@@@1@QEAPEAU?$_List_node@V?$MS2Ptr@VEventShopNpcContext@@@@PEAX@1@AEAPEAU31@@Z 0x140440170
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x1404401c0
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@AEAPEAU31@@Z 0x140440210
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x140440260
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x1404402b0
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x140440300
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x140440350
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x1404403a0
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@1@AEAPEAU31@@Z 0x1404403f0
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@1@AEAPEAU31@@Z 0x140440440
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@1@AEAPEAU31@@Z 0x140440490
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@1@AEAPEAU31@@Z 0x1404404e0
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@1@AEAPEAU31@@Z 0x140440530
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@1@AEAPEAU31@@Z 0x140440580
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@0@0@Z 0x1404412a0
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@0@0@Z 0x1404412d0
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@0@0@Z 0x140441300
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@0@0@Z 0x140441330
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@0@0@Z 0x140441360
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x14042de70
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x14042ded0
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x14042df30
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x14042df90
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x14042dff0
// tplpin --simulate accepted pins (w213)
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@1@0@Z 0x14042ad90
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@1@0@Z 0x14042ade0
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@1@0@Z 0x14042afc0
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@1@0@Z 0x14042b100
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@1@0@Z 0x14042b560
// MS2-PIN: ??$_Buynode@AEB_K@?$_Tree_comp_alloc@V?$_Tset_traits@_KU?$less@_K@std@@V?$allocator@_K@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@_KPEAX@1@AEB_K@Z 0x14042d7d0
// MS2-PIN: ??$_Eqrange@K@?$_Tree@V?$_Tmap_traits@KV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@V12@@1@AEBK@Z 0x14042f9b0
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042fc80
// MS2-PIN: ??$_Get_unwrapped@V?$MS2Ptr@VCollectItemGroupContext@@@@@std@@YAPEAV?$MS2Ptr@VCollectItemGroupContext@@@@QEAV1@@Z 0x140430c20
// MS2-PIN: ??$_Idl_distance@PEAV?$MS2Ptr@VCollectItemGroupContext@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VCollectItemGroupContext@@@@0@Z 0x140430ca0
// MS2-PIN: ??$_Ptr_move_cat@V?$MS2Ptr@VCollectItemGroupContext@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VCollectItemGroupContext@@@@0@Z 0x14043ee50
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@0@AEBV10@@Z 0x14043fdd0
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@0@AEBV10@@Z 0x14043fe30
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@0@AEAV10@@Z 0x140440050
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@1@@Z 0x140440fd0
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@PEAX@1@@Z 0x140441010
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@1@@Z 0x140441020
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@1@@Z 0x140441040
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@1@@Z 0x140441050
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@1@@Z 0x140441060
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@1@@Z 0x140441070
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@1@@Z 0x140441080
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@1@@Z 0x140441090
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441e90
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441ef0
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140441f30
// MS2-PIN: ??$forward@AEAV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@YAAEAV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@0@AEAV10@@Z 0x140442000
// MS2-PIN: ??$forward@AEAH@std@@YAAEAHAEAH@Z 0x140442010
// MS2-PIN: ??$forward@AEAV?$MS2Ptr@VBurningLevelupContext@@@@@std@@YAAEAV?$MS2Ptr@VBurningLevelupContext@@@@AEAV1@@Z 0x140442040
// MS2-PIN: ??0?$MS2Ptr@VEventShopNpcContext@@@@QEAA@XZ 0x140443ae0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@1@@Z 0x140444650
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@1@@Z 0x1404448d0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@1@@Z 0x140444930
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@1@@Z 0x140444df0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@1@@Z 0x140445070
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x1404450b0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@1@@Z 0x1404450d0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140445110
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@1@@Z 0x140445130
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140445170
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@1@@Z 0x140445190
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x1404451d0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@1@@Z 0x1404451f0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140445230
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAA@XZ 0x140445370
// MS2-PIN: ??0?$allocator@U?$_Tree_node@IPEAX@std@@@std@@QEAA@XZ 0x140445570
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VArcadeOpenContext@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBH@Z 0x14042e8d0
// MS2-PIN: ??$_Eqrange@K@?$_Tree@V?$_Tmap_traits@KV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@V12@@1@AEBK@Z 0x14042f920
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@@1@AEBI@Z 0x14042fbf0
// MS2-PIN: ??$_Eqrange@W4Unk_DungeonGroupType@@@?$_Tree@V?$_Tmap_traits@W4Unk_DungeonGroupType@@U?$pair@HH@std@@U?$less@W4Unk_DungeonGroupType@@@3@V?$allocator@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@@std@@V12@@1@AEBW4Unk_DungeonGroupType@@@Z 0x14042fec0
// MS2-PIN: ??$_Eqrange@_K@?$_Tree@V?$_Tmap_traits@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@V12@@1@AEB_K@Z 0x140430220
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404304d0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404307a0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404308c0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140430950
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404309e0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@std@@@1@PEAU01@@Z 0x140430a70
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140430b00
// MS2-PIN: ??$_Try_emplace@AEBK$$V@?$map@KV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEBK@Z 0x14043f2c0
// MS2-PIN: ??$_Try_emplace@AEBK$$V@?$map@KV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEBK@Z 0x14043f410
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@0@0@Z 0x140441270
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@0@0@Z 0x140441390
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@@0@0@Z 0x1404413c0
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@0@0@Z 0x1404413f0
// MS2-PIN: ??$try_emplace@$$V@?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@std@@@std@@_N@1@AEBU?$pair@HK@1@@Z 0x1404428b0
// MS2-PIN: ??$try_emplace@$$V@?$map@W4Unk_DungeonGroupType@@U?$pair@HH@std@@U?$less@W4Unk_DungeonGroupType@@@3@V?$allocator@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@@std@@_N@1@AEBW4Unk_DungeonGroupType@@@Z 0x1404428f0
// MS2-PIN: ??$try_emplace@$$V@?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@_N@1@AEB_K@Z 0x140442930
// MS2-PIN: ??0CNode@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAA@II@Z 0x140445aa0
// MS2-PIN: ??0CNode@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@QEAA@II@Z 0x140445b20
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@QEAA@II@Z 0x140445c20
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropContext@@@@@3@@ATL@@QEAA@II@Z 0x140445ca0
// MS2-PIN: ??0CNode@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@KI@Z 0x140445da0
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@IEAA@I@Z 0x140445f80
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$MS2Ptr@VCNpcShopGivePointContextBase@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopGivePointContextBase@@@@@3@@ATL@@IEAA@I@Z 0x140445fc0
// MS2-PIN: ??$_Emplace_back@V?$MS2Ptr@VCollectItemGroupContext@@@@@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCollectItemGroupContext@@@@V?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@QEAAX$$QEAV?$MS2Ptr@VCollectItemGroupContext@@@@@Z 0x14042e1d0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@std@@@1@PEAU01@@Z 0x140430b90
// MS2-PIN: ??$_Ptr_copy_cat@V?$MS2Ptr@VCollectItemGroupContext@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VCollectItemGroupContext@@@@0@Z 0x14043ee20
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$MS2Ptr@VCollectItemGroupContext@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCollectItemGroupContext@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@0@@Z 0x14043fab0
// MS2-PIN: ??$construct@V?$MS2Ptr@VCollectItemGroupContext@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@1@QEAV?$MS2Ptr@VCollectItemGroupContext@@@@$$QEAV3@@Z 0x140440e80
// MS2-PIN: ??$distance@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@0@0@Z 0x140441240
// MS2-PIN: ??$emplace_back@AEB_K@?$vector@_KV?$allocator@_K@std@@@std@@QEAAXAEB_K@Z 0x140441650
// MS2-PIN: ??$forward@AEBV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@YAAEBV?$MS2Ptr@VCollectItemGroupContext@@@@AEBV1@@Z 0x140442040
// MS2-PIN: ??$move@AEAV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@YA$$QEAV?$MS2Ptr@VCollectItemGroupContext@@@@AEAV1@@Z 0x140442690
// MS2-PIN: ??0CNode@?$CAtlMap@I_NV?$CElementTraits@I@ATL@@V?$CElementTraits@_N@2@@ATL@@QEAA@II@Z 0x140445ae0
// MS2-PIN: ??$?0AEAHAEAK$0A@@?$pair@HK@std@@QEAA@AEAHAEAK@Z 0x14042b7e0
// MS2-PIN: ??$?0AEBU?$pair@HK@std@@$$Z$$V@?$pair@$$CBU?$pair@HK@std@@H@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBU?$pair@HK@std@@@1@V?$tuple@$$V@1@@Z 0x14042bdd0
// MS2-PIN: ??$?0V?$tuple@AEBW4Unk_DungeonGroupType@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@QEAA@AEAV?$tuple@AEBW4Unk_DungeonGroupType@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14042c9a0
// MS2-PIN: ??$construct@V?$MS2Ptr@VEventShopNpcContext@@@@AEBV1@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$MS2Ptr@VEventShopNpcContext@@@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VEventShopNpcContext@@@@PEAX@std@@@1@QEAV?$MS2Ptr@VEventShopNpcContext@@@@AEBV3@@Z 0x140440ed0
// MS2-PIN: ??0?$MS2Ptr@VUnk_FieldObjectDropContext@@@@QEAA@XZ 0x140443cf0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x140444910
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x140444970
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HK@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@1@@Z 0x140444990
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@std@@@std@@QEAA@XZ 0x1404449d0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@1@@Z 0x1404449f0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x140444a30
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KI@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@1@@Z 0x140444a50
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@QEAA@XZ 0x140444a90
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@1@@Z 0x140444cb0
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@1@@Z 0x140444cf0
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14042b150
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VArcadeOpenContext@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBH@Z 0x14042e840
// MS2-PIN: ??$_Eqrange@_K@?$_Tree@V?$_Tmap_traits@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@V12@@1@AEB_K@Z 0x140430190
// MS2-PIN: ??$_Uninitialized_move@PEAV?$MS2Ptr@VCollectItemGroupContext@@@@PEAV1@V?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@YAPEAV?$MS2Ptr@VCollectItemGroupContext@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@0@@Z 0x14043fc10
// MS2-PIN: ??$construct@V?$MS2Ptr@VCollectItemGroupContext@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCollectItemGroupContext@@@@@1@QEAV?$MS2Ptr@VCollectItemGroupContext@@@@AEAV3@@Z 0x140440de0
// MS2-PIN: ??$try_emplace@$$V@?$map@KV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEBK@Z 0x140442830
// MS2-PIN: ??$try_emplace@$$V@?$map@KV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEBK@Z 0x140442870
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@1@@Z 0x140444ab0
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAA@II@Z 0x140445ba0
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$MS2Ptr@VCNpcShopGivePointContextBase@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopGivePointContextBase@@@@@3@@ATL@@QEAA@II@Z 0x140445be0
// MS2-PIN: ?Allocate@?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@PEAX@Z 0x14042cc40
// MS2-PIN: ??$_Distance1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x14042ddb0
// MS2-PIN: ??$_Emplace_reallocate@AEB_K@?$vector@_KV?$allocator@_K@std@@@std@@QEAAPEA_KQEA_KAEB_K@Z 0x14042e600
// MS2-PIN: ??0?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@IEAA@_K@Z 0x1404436f0
// MS2-PIN: ??0?$MS2Ptr@VArcadeOpenContext@@@@QEAA@$$QEAV0@@Z 0x140443940
// MS2-PIN: ??0CNode@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEAA@II@Z 0x140445e20
// MS2-PIN: ??0CPair@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@IEAA@II@Z 0x1404461d0
// MS2-PIN: ??0CNode@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAA@II@Z 0x140445d60
// MS2-PIN: ??$?0V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@1@$$QEA_N@Z 0x14042c240
// MS2-PIN: ??$_Insert_at@AEB_KU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@_KU?$less@_K@std@@V?$allocator@_K@2@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@1@_NPEAU?$_Tree_node@_KPEAX@1@AEB_KU_Not_a_node_tag@1@@Z 0x1404339b0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@@1@@Z 0x140444c70
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventvalue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <limits.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cxmldata.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void FUN_140274fc0(const CStringW& text, ATL::CAtlArray<unsigned>& ids, const wchar_t* delims);  // split into ids
unsigned FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned nDefault);           // unsigned attribute
Unk_140165cf0* FUN_140345b40(TiXmlDocument* pDoc);  // the document's first child element
__int64 FUN_14028d0e0();                            // the current server time
CStringW FUN_140718600(const CStringW& value);      // copy

// The engine log lock (0x140203610 ctor) the sale item restriction takes.
struct Unk_EngineLogLock {
    Unk_EngineLogLock(CLockCriticalSection& cs, int n);
    ~Unk_EngineLogLock();
    void* p;
};

// The index of value in arr, -1 when missing (the gameeventcontext.cpp template; the exe folds this instance into it).
template <class T>
int Unk_ArrayFind(const ATL::CAtlArray<T>& arr, const T& value)
{
    for (size_t i = 0; i < arr.GetCount(); i++) {
        if (arr[i] == value)
            return (int)i;
    }
    return -1;
}

// CXmlData's wide value (a COMDAT of this unit).
inline CStringW CXmlData::FUN_14042cad0(const CStringW& strKey, const CStringW& strDefault)
{
    CStringW strValue;
    if (!reinterpret_cast<Values*>(m_unknown18)->Lookup(strKey, strValue))
        return strDefault;
    return FUN_140718600(strValue);
}

// @0x140422c10
Unk_GameEventValue8::Unk_GameEventValue8() : m_value(0) {}
// @0x140422c50
Unk_GameEventValue8::~Unk_GameEventValue8() {}
// @0x140422c80
int Unk_GameEventValue8::GetValue()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_value;
}
MS2_REPLACE_METHOD(0x140422C80, Unk_GameEventValue8, GetValue, 64, 0xFE2916EF);
// @0x140422cd0
void Unk_GameEventValue8::SetValue(int value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_value = value;
}
MS2_REPLACE_METHOD(0x140422CD0, Unk_GameEventValue8, SetValue, 64, 0x25295C0A);

// @0x140422d20
Unk_GameEventValueSum::Unk_GameEventValueSum() { m_sum = 0; }
// @0x140422d70
Unk_GameEventValueSum::~Unk_GameEventValueSum() {}
// @0x140422db0
int Unk_GameEventValueSum::GetSum()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_sum;
}
MS2_REPLACE_METHOD(0x140422DB0, Unk_GameEventValueSum, GetSum, 64, 0x21F879BA);
// @0x140422e00
void Unk_GameEventValueSum::SetValue(unsigned eventId, int value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (value == 0)
        m_values.erase(eventId);
    else
        m_values[eventId] = value;
    m_sum = 0;
    std::map<unsigned, unsigned>::const_iterator it = m_values.begin();
    std::map<unsigned, unsigned>::const_iterator itEnd = m_values.end();
    for (; it != itEnd; ++it)
        m_sum += it->second;
}
MS2_REPLACE_METHOD(0x140422E00, Unk_GameEventValueSum, SetValue, 265, 0xDAA1195C);

// @0x140422f10
Unk_GameEventValueDungeonGroup::Unk_GameEventValueDungeonGroup() {}
// @0x140422f60
Unk_GameEventValueDungeonGroup::~Unk_GameEventValueDungeonGroup() {}
// @0x140422fa0
int Unk_GameEventValueDungeonGroup::GetFirst(Unk_DungeonGroupType type)
{
    if (m_groups.empty())
        return 0;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_groups.find(type) == m_groups.end())
        return 0;
    return m_groups[type].first;
}
MS2_REPLACE_METHOD(0x140422FA0, Unk_GameEventValueDungeonGroup, GetFirst, 223, 0xF9BC9E4F);
// @0x140423090
int Unk_GameEventValueDungeonGroup::GetSecond(Unk_DungeonGroupType type, int nDefault)
{
    if (m_groups.empty())
        return INT_MAX;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_groups.find(type) == m_groups.end())
        return INT_MAX;
    int second = m_groups[type].second;
    if (second == 0)
        return nDefault;
    return second;
}
MS2_REPLACE_METHOD(0x140423090, Unk_GameEventValueDungeonGroup, GetSecond, 274, 0xEB3D1782);
// @0x1404231b0
void Unk_GameEventValueDungeonGroup::Set(Unk_DungeonGroupType type, unsigned first, unsigned second)
{
    if (type == 0 || type >= 15)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (first == 0) {
        m_groups.erase(type);
        return;
    }
    if (m_groups.find(type) != m_groups.end())
        return;
    std::pair<unsigned, unsigned> group(first, second);
    m_groups[type] = group;
}
MS2_REPLACE_METHOD(0x1404231B0, Unk_GameEventValueDungeonGroup, Set, 278, 0xB6C7644A);

// @0x1404232d0
Unk_GameEventValue88::Unk_GameEventValue88() : m_value(0) {}
// @0x140423310
Unk_GameEventValue88::~Unk_GameEventValue88() {}
// @0x140423340
int Unk_GameEventValue88::GetValue()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_value;
}
MS2_REPLACE_METHOD(0x140423340, Unk_GameEventValue88, GetValue, 64, 0x948C27AB);
// @0x140423390
void Unk_GameEventValue88::SetValue(int value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_value = value;
}
MS2_REPLACE_METHOD(0x140423390, Unk_GameEventValue88, SetValue, 64, 0x898A0505);

// @0x1404233e0
CGameEventValueGuildSkillSale::CGameEventValueGuildSkillSale() : m_rate(0) {}
// @0x140423420
CGameEventValueGuildSkillSale::~CGameEventValueGuildSkillSale() {}
// @0x140423450
int CGameEventValueGuildSkillSale::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
MS2_REPLACE_METHOD(0x140423450, CGameEventValueGuildSkillSale, GetRate, 64, 0x62282C8F);
// @0x1404234a0
void CGameEventValueGuildSkillSale::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}
MS2_REPLACE_METHOD(0x1404234A0, CGameEventValueGuildSkillSale, SetRate, 64, 0xD930F5FA);
// @0x1404234f0
CGameEventValueGuildPersonalSkillSale::CGameEventValueGuildPersonalSkillSale() : m_rate(0) {}
// @0x140423530
CGameEventValueGuildPersonalSkillSale::~CGameEventValueGuildPersonalSkillSale() {}
// @0x140423560
int CGameEventValueGuildPersonalSkillSale::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
MS2_REPLACE_METHOD(0x140423560, CGameEventValueGuildPersonalSkillSale, GetRate, 64, 0x959EEBEB);
// @0x1404235b0
void CGameEventValueGuildPersonalSkillSale::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}
MS2_REPLACE_METHOD(0x1404235B0, CGameEventValueGuildPersonalSkillSale, SetRate, 64, 0x7C3956CC);
// @0x140423600
CGameEventValueGuildExp::CGameEventValueGuildExp() : m_rate(0) {}
// @0x140423640
CGameEventValueGuildExp::~CGameEventValueGuildExp() {}
// @0x140423670
int CGameEventValueGuildExp::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
MS2_REPLACE_METHOD(0x140423670, CGameEventValueGuildExp, GetRate, 64, 0x74C73A5F);
// @0x1404236c0
void CGameEventValueGuildExp::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}
MS2_REPLACE_METHOD(0x1404236C0, CGameEventValueGuildExp, SetRate, 64, 0xF6751B2A);
// @0x140423710
CGameEventValueGuildFund::CGameEventValueGuildFund() : m_rate(0) {}
// @0x140423750
CGameEventValueGuildFund::~CGameEventValueGuildFund() {}
// @0x140423780
int CGameEventValueGuildFund::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
MS2_REPLACE_METHOD(0x140423780, CGameEventValueGuildFund, GetRate, 64, 0x74D5D2CB);
// @0x1404237d0
void CGameEventValueGuildFund::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}
MS2_REPLACE_METHOD(0x1404237D0, CGameEventValueGuildFund, SetRate, 64, 0x39E8B290);
// @0x140423820
CGameEventValueGuildCoin::CGameEventValueGuildCoin() : m_rate(0) {}
// @0x140423860
CGameEventValueGuildCoin::~CGameEventValueGuildCoin() {}
// @0x140423890
int CGameEventValueGuildCoin::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
MS2_REPLACE_METHOD(0x140423890, CGameEventValueGuildCoin, GetRate, 64, 0x76E22F07);
// @0x1404238e0
void CGameEventValueGuildCoin::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}
MS2_REPLACE_METHOD(0x1404238E0, CGameEventValueGuildCoin, SetRate, 64, 0x4BD159B2);

// @0x140423930
CGameEventValueMasteryReward::CGameEventValueMasteryReward() {}
// @0x140423980
CGameEventValueMasteryReward::~CGameEventValueMasteryReward() {}
// @0x1404239c0
int CGameEventValueMasteryReward::GetRate(int type, unsigned long fieldId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    int nRate = 0;
    for (std::map<unsigned long, Rates>::iterator it = m_events.begin(); it != m_events.end(); ++it) {
        Rates& rates = it->second;
        std::pair<int, unsigned long> key(type, fieldId);
        if (rates.find(key) == rates.end())
            continue;
        nRate += rates[key];
    }
    return nRate;
}
MS2_REPLACE_METHOD(0x1404239C0, CGameEventValueMasteryReward, GetRate, 323, 0x2981D4CA);
// @0x140423b10
void CGameEventValueMasteryReward::Load(unsigned long eventId, int type, const CStringW& strPath)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_140397ab0(&doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    if (m_events.find(eventId) != m_events.end())
        return;
    Rates rates;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("v"); pNode != NULL; pNode = pNode->FUN_140168650("v")) {
        unsigned long fieldId = FUN_140197390(pNode, "fieldID", 0);
        int rate = FUN_140197390(pNode, "rate", 0);
        if (fieldId == 0 || rate == 0)
            continue;
        std::pair<int, unsigned long> key(type, fieldId);
        if (rates.find(key) != rates.end())
            continue;
        rates[key] = rate;
    }
    m_events[eventId] = rates;
}
MS2_REPLACE_METHOD(0x140423B10, CGameEventValueMasteryReward, Load, 647, 0xCBB84224);
// @0x140423da0
void CGameEventValueMasteryReward::Remove(unsigned long eventId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_events.find(eventId) == m_events.end())
        return;
    m_events.erase(eventId);
}
MS2_REPLACE_METHOD(0x140423DA0, CGameEventValueMasteryReward, Remove, 171, 0x82DD5C49);

// @0x140423e60
Unk_GameEventValue258::Unk_GameEventValue258() : m_value(0) {}
// @0x140423ea0
Unk_GameEventValue258::~Unk_GameEventValue258() {}
// @0x140423ed0
#pragma warning(push)
#pragma warning(disable : 4715)
int Unk_GameEventValue258::GetValue()
{
    // MS2-FUNCTIONAL: the exe has one extra nop after the guard dtor on the fall-off path
    if (Unk_LockGuard guard = m_lock) {} else
    {
        return m_value;
    }
}
MS2_REPLACE_METHOD(0x140423ED0, Unk_GameEventValue258, GetValue, 97, 0x27F95986);
#pragma warning(pop)
// @0x140423f40
void Unk_GameEventValue258::SetValue(int value)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_value = value;
    }
}
MS2_REPLACE_METHOD(0x140423F40, Unk_GameEventValue258, SetValue, 84, 0xF3EA2DB6);

// @0x140423fa0
CGameEventValueMeratMarketOpenTab::CGameEventValueMeratMarketOpenTab() {}
// @0x140423fe0
CGameEventValueMeratMarketOpenTab::~CGameEventValueMeratMarketOpenTab() {}
// @0x140424020
const CStringW& CGameEventValueMeratMarketOpenTab::GetTab() { return m_tab; }
MS2_REPLACE_METHOD(0x140424020, CGameEventValueMeratMarketOpenTab, GetTab, 15, 0x3758D2A9);
// @0x140424040
void CGameEventValueMeratMarketOpenTab::SetTab(const CStringW& strTab)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_tab = strTab;
    }
}
MS2_REPLACE_METHOD(0x140424040, CGameEventValueMeratMarketOpenTab, SetTab, 97, 0x3573F0F2);

// @0x1404240b0
CGameEventValueMasteryReduce::CGameEventValueMasteryReduce() : m_rate(0) {}
// @0x1404240d0
CGameEventValueMasteryReduce::~CGameEventValueMasteryReduce() {}
// @0x1404240e0
unsigned CGameEventValueMasteryReduce::Apply(unsigned value)
{
    if (m_rate == 0)
        return value;
    return (unsigned)((float)value / ((float)(unsigned)m_rate / 10000.0f));
}
MS2_REPLACE_METHOD(0x1404240E0, CGameEventValueMasteryReduce, Apply, 64, 0x6DA76EA8);
// @0x140424130
void CGameEventValueMasteryReduce::SetRate(int rate) { m_rate = rate; }
MS2_REPLACE_METHOD(0x140424130, CGameEventValueMasteryReduce, SetRate, 21, 0xA2C4AECF);
// @0x140424150
CStringW CGameEventValueMasteryReduce::GetText()
{
    if (m_rate == 0)
        return CStringW(L"");
    float fRate = (float)(unsigned)m_rate / 10000.0f;
    return FUN_14028dfa0(CStringW(L"s_mastery_reduce_event"), fRate);
}
MS2_REPLACE_METHOD(0x140424150, CGameEventValueMasteryReduce, GetText, 168, 0xFEEFADB2);

// @0x140424200
Unk_GameEventValueIdLists::Unk_GameEventValueIdLists() {}
// @0x140424270
Unk_GameEventValueIdLists::~Unk_GameEventValueIdLists() {}
// @0x1404242b0
void Unk_GameEventValueIdLists::Add(unsigned key, unsigned id)
{
    Unk_FieldIdListPtr spList(0);
    if (Unk_LockGuard guard = m_lock) {} else
    {
        if (!m_lists.Lookup(key, spList)) {
            // MS2-FUNCTIONAL: the exe assigns a fresh box temp through operator=(const Unk_FieldPtr&) without the
            // temp spill /Od emits for the functional cast here; the implicit form picks operator=(Unk_FieldNewTag)
            spList = Unk_FieldIdListPtr(Unk_FieldNewTag(0));
            m_lists.SetAt(key, spList);
        }
        if (spList.get() != NULL)
            spList->AddTail(id);
    }
}
MS2_REPLACE_METHOD(0x1404242B0, Unk_GameEventValueIdLists, Add, 256, 0x45486848);
// @0x1404243c0
bool Unk_GameEventValueIdLists::Remove(unsigned key, unsigned id)
{
    Unk_FieldIdListPtr spList(0);
    if (Unk_LockGuard guard = m_lock) {} else
    {
        if (m_lists.Lookup(key, spList)) {
            POSITION pos = spList->Find(id);
            if (pos != NULL)
                spList->RemoveAt(pos);
            if (spList->IsEmpty())
                m_lists.RemoveKey(key);
            return true;
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x1404243C0, Unk_GameEventValueIdLists, Remove, 290, 0x2CE76AE2);

// @0x1404244f0
CGameEventValueItemBox::CGameEventValueItemBox() {}
// @0x140424540
CGameEventValueItemBox::~CGameEventValueItemBox() {}
// @0x140424580
MS2Ptr<ItemBoxEventContext> CGameEventValueItemBox::Get(unsigned fieldId)
{
    if (m_contexts.empty())
        return MS2Ptr<ItemBoxEventContext>(0);
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned, MS2Ptr<ItemBoxEventContext> >::iterator it = m_contexts.find(fieldId);
    if (it == m_contexts.end())
        return MS2Ptr<ItemBoxEventContext>(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x140424580, CGameEventValueItemBox, Get, 285, 0x81DDD28D);
// @0x1404246b0
bool CGameEventValueItemBox::Add(MS2Ptr<ItemBoxEventContext> spContext)
{
    if (spContext == NULL)
        return false;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.find(spContext->m_fieldID) != m_contexts.end())
        return false;
    m_contexts[spContext->m_fieldID] = spContext;
    return true;
}
MS2_REPLACE_METHOD(0x1404246B0, CGameEventValueItemBox, Add, 291, 0x28DDC8F3);
// @0x1404247e0
void CGameEventValueItemBox::Remove(MS2Ptr<ItemBoxEventContext> spContext)
{
    if (spContext == NULL)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.erase(spContext->m_fieldID);
}
MS2_REPLACE_METHOD(0x1404247E0, CGameEventValueItemBox, Remove, 137, 0x70256C12);

// @0x140424870
CGameEventValueSaleItemsRestricted::CGameEventValueSaleItemsRestricted() : m_active(false) {}
// @0x1404248e0
CGameEventValueSaleItemsRestricted::~CGameEventValueSaleItemsRestricted() {}
// @0x140424920
bool CGameEventValueSaleItemsRestricted::IsActive() { return m_active; }
MS2_REPLACE_METHOD(0x140424920, CGameEventValueSaleItemsRestricted, IsActive, 15, 0x228C1F9D);
// @0x140424940
bool CGameEventValueSaleItemsRestricted::IsRestricted(unsigned itemId)
{
    Unk_EngineLogLock lock(m_lock, 1);
    if (m_items.IsEmpty())
        return false;
    if (m_items.Lookup(itemId) != NULL)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140424940, CGameEventValueSaleItemsRestricted, IsRestricted, 156, 0x9C294041);
// @0x1404249f0
void CGameEventValueSaleItemsRestricted::SetItems(ATL::CAtlArray<unsigned>& items)
{
    Unk_EngineLogLock lock(m_lock, 1);
    m_items.RemoveAll();
    m_active = false;
    for (size_t i = 0; i < items.GetCount(); i++) {
        const unsigned& itemId = items.GetAt(i);
        if (itemId == 0)
            continue;
        m_items.SetAt(itemId, false);
    }
    if (m_items.GetCount() != 0)
        m_active = true;
}
MS2_REPLACE_METHOD(0x1404249F0, CGameEventValueSaleItemsRestricted, SetItems, 222, 0x5EAC6CA2);
// @0x140424ae0
void CGameEventValueSaleItemsRestricted::Clear()
{
    Unk_EngineLogLock lock(m_lock, 1);
    m_items.RemoveAll();
    m_active = false;
}
MS2_REPLACE_METHOD(0x140424AE0, CGameEventValueSaleItemsRestricted, Clear, 84, 0x4A9AA9F8);

// @0x140424b40
Unk_GameEventValue408::Unk_GameEventValue408() : m_set(false), m_value(0) {}
// @0x140424b70
Unk_GameEventValue408::~Unk_GameEventValue408() {}
// @0x140424b80
bool Unk_GameEventValue408::IsSet() { return m_set; }
MS2_REPLACE_METHOD(0x140424B80, Unk_GameEventValue408, IsSet, 14, 0xDA496095);
// @0x140424ba0
unsigned Unk_GameEventValue408::GetValue() { return m_value; }
MS2_REPLACE_METHOD(0x140424BA0, Unk_GameEventValue408, GetValue, 14, 0x7AB52803);
// @0x140424bc0
void Unk_GameEventValue408::SetValue(unsigned value)
{
    m_value = value;
    if (m_value > 0)
        m_set = true;
}
MS2_REPLACE_METHOD(0x140424BC0, Unk_GameEventValue408, SetValue, 41, 0x6452A6B5);
// @0x140424bf0
void Unk_GameEventValue408::Reset()
{
    m_value = 0;
    m_set = false;
}
MS2_REPLACE_METHOD(0x140424BF0, Unk_GameEventValue408, Reset, 26, 0x41885F52);

// @0x140424c10
CGameEventValueDungeonHelperBonus::CGameEventValueDungeonHelperBonus() : m_bonus(0) {}
// @0x140424c50
CGameEventValueDungeonHelperBonus::~CGameEventValueDungeonHelperBonus() {}
// @0x140424c80
void CGameEventValueDungeonHelperBonus::Add(int bonus)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_bonus += bonus;
}
MS2_REPLACE_METHOD(0x140424C80, CGameEventValueDungeonHelperBonus, Add, 72, 0x098AA5B4);
// @0x140424cd0
void CGameEventValueDungeonHelperBonus::Sub(int bonus)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_bonus -= bonus;
}
MS2_REPLACE_METHOD(0x140424CD0, CGameEventValueDungeonHelperBonus, Sub, 74, 0x6124925F);
// @0x140424d20
int CGameEventValueDungeonHelperBonus::GetBonus()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_bonus;
}
MS2_REPLACE_METHOD(0x140424D20, CGameEventValueDungeonHelperBonus, GetBonus, 64, 0xED11AC9B);

// @0x140424d70
CGameEventValueMentoring::CGameEventValueMentoring() : m_spContext(0) {}
// @0x140424da0
void CGameEventValueMentoring::Set(MS2Ptr<MentoringContext> spContext) { m_spContext = spContext; }
MS2_REPLACE_METHOD(0x140424DA0, CGameEventValueMentoring, Set, 57, 0xC5884236);
// @0x140424de0
int CGameEventValueMentoring::GetId()
{
    if (m_spContext == NULL)
        return 0;
    return m_spContext->m_18;
}
MS2_REPLACE_METHOD(0x140424DE0, CGameEventValueMentoring, GetId, 56, 0xBD0AA82A);
// @0x140424e20
__int64 CGameEventValueMentoring::GetEndTime()
{
    if (m_spContext == NULL)
        return 0;
    return m_spContext->m_28;
}
MS2_REPLACE_METHOD(0x140424E20, CGameEventValueMentoring, GetEndTime, 57, 0xF215A38B);
// @0x140424e60
__int64 CGameEventValueMentoring::GetBeginTime()
{
    if (m_spContext == NULL)
        return 0;
    return m_spContext->m_20;
}
MS2_REPLACE_METHOD(0x140424E60, CGameEventValueMentoring, GetBeginTime, 57, 0x4D6193AA);
// @0x140424ea0
void CGameEventValueMentoring::Reset() { m_spContext = 0; }
MS2_REPLACE_METHOD(0x140424EA0, CGameEventValueMentoring, Reset, 29, 0x4E94AB50);
// @0x140424ed0
void CGameEventValueMentoring::GetIds(ATL::CAtlArray<unsigned>& ids)
{
    if (m_spContext == NULL)
        return;
    ids.Copy(m_spContext->m_ids);
}
MS2_REPLACE_METHOD(0x140424ED0, CGameEventValueMentoring, GetIds, 73, 0x46944269);
// @0x140424f20
BOOL CGameEventValueMentoring::HasId(unsigned id)
{
    if (m_spContext == NULL)
        return FALSE;
    return Unk_ArrayFind(m_spContext->m_ids, id) != -1;
}
MS2_REPLACE_METHOD(0x140424F20, CGameEventValueMentoring, HasId, 101, 0x5B30566F);

// @0x140424f90
CGameEventValueDungeonBuff::CGameEventValueDungeonBuff() {}
// @0x140424ff0
void CGameEventValueDungeonBuff::Add(unsigned long dungeonId, MS2Ptr<DungeonBuffEventCtx> spContext)
{
    if (spContext == NULL)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    Counts* pCounts = NULL;
    if (spContext->m_isBeginner)
        pCounts = &m_beginnerBuffs[dungeonId];
    else
        pCounts = &m_buffs[dungeonId];
    if (pCounts == NULL)
        return;
    std::vector<unsigned __int64>& guids = spContext.get()->m_addEffectGUIDs;
    for (size_t i = 0; i < guids.size(); i++)
        (*pCounts)[guids[i]]++;
}
MS2_REPLACE_METHOD(0x140424FF0, CGameEventValueDungeonBuff, Add, 340, 0xCF31D3DD);
// @0x140425150
void CGameEventValueDungeonBuff::Remove(unsigned long dungeonId, MS2Ptr<DungeonBuffEventCtx> spContext)
{
    if (spContext == NULL)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    Counts* pCounts = NULL;
    if (spContext->m_isBeginner)
        pCounts = &m_beginnerBuffs[dungeonId];
    else
        pCounts = &m_buffs[dungeonId];
    if (pCounts == NULL)
        return;
    std::vector<unsigned __int64>& guids = spContext.get()->m_addEffectGUIDs;
    for (size_t i = 0; i < guids.size(); i++) {
        unsigned __int64 guid = guids[i];
        if ((*pCounts)[guid] > 1)
            (*pCounts)[guid]--;
        else
            pCounts->erase(guid);
    }
}
MS2_REPLACE_METHOD(0x140425150, CGameEventValueDungeonBuff, Remove, 405, 0xAC43EC5D);
// @0x1404252f0
void CGameEventValueDungeonBuff::GetBuffs(unsigned long dungeonId, std::set<unsigned __int64>& buffs)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    Counts& counts = m_buffs[dungeonId];
    for (Counts::iterator it = counts.begin(), itEnd = counts.end(); it != itEnd; it++)
        buffs.insert(it->first);
}
MS2_REPLACE_METHOD(0x1404252F0, CGameEventValueDungeonBuff, GetBuffs, 199, 0x9A3B00C9);
// @0x1404253c0
void CGameEventValueDungeonBuff::GetBeginnerBuffs(unsigned long dungeonId, std::vector<unsigned __int64>& buffs)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    Counts& counts = m_beginnerBuffs[dungeonId];
    buffs.reserve(counts.size());
    for (Counts::iterator it = counts.begin(), itEnd = counts.end(); it != itEnd; it++)
        buffs.push_back(it->first);
}
MS2_REPLACE_METHOD(0x1404253C0, CGameEventValueDungeonBuff, GetBeginnerBuffs, 214, 0x6A33541E);

// @0x1404254a0
CGameEventValueBattlePetSpawn::CGameEventValueBattlePetSpawn() : m_time(0) {}
// @0x1404255b0
void CGameEventValueBattlePetSpawn::AddSpawn(int eventId, const CStringW& strValues)
{
    MS2Ptr<CXmlData> spXml(new CXmlData(strValues));
    if (spXml == NULL)
        return;
    CStringW strFields = spXml->FUN_14042cad0(L"targetFieldIDs", L"");
    if (strFields.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> fields;
    FUN_140274fc0(strFields, fields, L",");
    if (fields.IsEmpty())
        return;
    CStringW strProbabilities = spXml->FUN_14042cad0(L"spawnProbabilities", L"");
    if (strProbabilities.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> probabilities;
    FUN_140274fc0(strProbabilities, probabilities, L",");
    if (probabilities.IsEmpty())
        return;
    if (fields.GetCount() != probabilities.GetCount())
        return;
    CStringW strCounts = spXml->FUN_14042cad0(L"spawnCounts", L"");
    if (strCounts.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> counts;
    FUN_140274fc0(strCounts, counts, L",");
    if (counts.IsEmpty())
        return;
    if (fields.GetCount() != counts.GetCount())
        return;
    CStringW strPets = spXml->FUN_14042cad0(L"spawnPetIDs", L"");
    if (strPets.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> pets;
    FUN_140274fc0(strPets, pets, L",");
    if (pets.IsEmpty())
        return;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (unsigned i = 0; i < fields.GetCount(); i++) {
            unsigned fieldId = fields[i];
            MS2Ptr<SpawnContext> spSpawn(new SpawnContext);
            spSpawn->m_eventId = eventId;
            spSpawn->m_probability = probabilities[i];
            spSpawn->m_count = counts[i];
            spSpawn->m_petIds.Copy(pets);
            for (unsigned j = 0; j < pets.GetCount(); j++)
                m_petFields.Insert(pets[j], fieldId);
            m_spawns.SetAt(fieldId, spSpawn);
        }
        m_time = FUN_14028d0e0();
    }
}
MS2_REPLACE_METHOD(0x1404255B0, CGameEventValueBattlePetSpawn, AddSpawn, 2432, 0x3F609DD6);
// @0x140425f40
void CGameEventValueBattlePetSpawn::RemoveSpawn(int eventId, const CStringW& strValues)
{
    MS2Ptr<CXmlData> spXml(new CXmlData(strValues));
    if (spXml == NULL)
        return;
    CStringW strFields = spXml->FUN_14042cad0(L"targetFieldIDs", L"");
    if (strFields.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> fields;
    FUN_140274fc0(strFields, fields, L",");
    if (fields.IsEmpty())
        return;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (unsigned i = 0; i < fields.GetCount(); i++) {
            int fieldId = fields[i];
            MS2Ptr<SpawnContext> spSpawn(0);
            if (!m_spawns.Lookup(fieldId, spSpawn))
                continue;
            if (spSpawn->m_eventId != eventId)
                continue;
            for (unsigned j = 0; j < spSpawn->m_petIds.GetCount(); j++) {
                unsigned petId = spSpawn->m_petIds[j];
                POSITION pos = m_petFields.FindFirstWithKey(petId);
                while (pos != NULL) {
                    POSITION posCur = pos;
                    m_petFields.GetNextWithKey(pos, petId);
                    int nField = m_petFields.GetValueAt(posCur);
                    if (nField != fieldId)
                        continue;
                    m_petFields.RemoveAt(posCur);
                }
            }
            m_spawns.RemoveKey(fieldId);
            m_endTimes.SetAt(fieldId, FUN_14028d0e0());
        }
    }
}
MS2_REPLACE_METHOD(0x140425F40, CGameEventValueBattlePetSpawn, RemoveSpawn, 1068, 0x6821C565);
// @0x140426380
void CGameEventValueBattlePetSpawn::AddImprove(unsigned eventId, const CStringW& strValues)
{
    MS2Ptr<CXmlData> spXml(new CXmlData(strValues));
    if (spXml == NULL)
        return;
    CStringW strFields = spXml->FUN_14042cad0(L"targetFieldIDs", L"");
    ATL::CAtlArray<unsigned> fields;
    FUN_140274fc0(strFields, fields, L",");
    if (fields.IsEmpty())
        return;
    CStringW strProbabilities = spXml->FUN_14042cad0(L"improveProbabilities", L"");
    ATL::CAtlArray<unsigned> probabilities;
    FUN_140274fc0(strProbabilities, probabilities, L",");
    if (fields.GetCount() != probabilities.GetCount())
        return;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (unsigned i = 0; i < fields.GetCount(); i++)
        {
            std::pair<unsigned, unsigned> improve(eventId, probabilities[i]);
            m_improves.SetAt(fields[i], improve);
        }
    }
}
MS2_REPLACE_METHOD(0x140426380, CGameEventValueBattlePetSpawn, AddImprove, 873, 0x1C53C5B8);
// @0x1404266f0
void CGameEventValueBattlePetSpawn::RemoveImprove(int eventId, const CStringW& strValues)
{
    MS2Ptr<CXmlData> spXml(new CXmlData(strValues));
    if (spXml == NULL)
        return;
    CStringW strFields = spXml->FUN_14042cad0(L"targetFieldIDs", L"");
    ATL::CAtlArray<unsigned> fields;
    FUN_140274fc0(strFields, fields, L",");
    if (fields.IsEmpty())
        return;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (unsigned i = 0; i < fields.GetCount(); i++) {
            std::pair<unsigned, unsigned> improve;
            if (!m_improves.Lookup(fields[i], improve))
                continue;
            if (improve.first != (unsigned)eventId)
                continue;
            m_improves.RemoveKey(fields[i]);
        }
    }
}
MS2_REPLACE_METHOD(0x1404266F0, CGameEventValueBattlePetSpawn, RemoveImprove, 613, 0xCA23B95A);
// @0x140426960
#pragma warning(push)
#pragma warning(disable : 4715)
__int64 CGameEventValueBattlePetSpawn::GetTime(unsigned fieldId)
{
    // MS2-FUNCTIONAL: the exe has one extra nop after the guard dtor on the fall-off path
    if (Unk_LockGuard guard = m_lock) {} else
    {
        if (m_spawns.Lookup(fieldId) == NULL) {
            __int64 endTime = 0;
            if (m_endTimes.Lookup(fieldId, endTime))
                return endTime;
            return 0;
        }
        return m_time;
    }
}
MS2_REPLACE_METHOD(0x140426960, CGameEventValueBattlePetSpawn, GetTime, 233, 0x570A7296);
#pragma warning(pop)
// @0x140426a50
unsigned CGameEventValueBattlePetSpawn::GetImproveProbability(unsigned fieldId)
{
    unsigned probability = 0;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        std::pair<unsigned, unsigned> improve;
        if (m_improves.Lookup(fieldId, improve))
            probability = improve.second;
        else if (m_improves.Lookup(0, improve))
            probability = improve.second;
    }
    return probability;
}
MS2_REPLACE_METHOD(0x140426A50, CGameEventValueBattlePetSpawn, GetImproveProbability, 176, 0x4FE52A0C);
// @0x140426b10
MS2Ptr<CGameEventValueBattlePetSpawn::SpawnContext> CGameEventValueBattlePetSpawn::GetSpawn(unsigned fieldId)
{
    MS2Ptr<SpawnContext> spSpawn(0);
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_spawns.Lookup(fieldId, spSpawn);
    }
    return spSpawn;
}
MS2_REPLACE_METHOD(0x140426B10, CGameEventValueBattlePetSpawn, GetSpawn, 167, 0xF5AC461E);
// @0x140426bc0
void CGameEventValueBattlePetSpawn::GetFields(unsigned petId, ATL::CAtlArray<unsigned>& fields)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (POSITION pos = m_petFields.FindFirstWithKey(petId); pos != NULL; m_petFields.GetNextWithKey(pos, petId)) {
            unsigned fieldId = m_petFields.GetValueAt(pos);
            fields.Add(fieldId);
        }
    }
}
MS2_REPLACE_METHOD(0x140426BC0, CGameEventValueBattlePetSpawn, GetFields, 190, 0x2D23941F);

// @0x140426c90
CGameEventValueIDIPEvent::CGameEventValueIDIPEvent() {}
// @0x140426d00
void CGameEventValueIDIPEvent::Add(unsigned id, int type, const CMsTime& time)
{
    MS2Ptr<IDIPEventContext> spContext(new IDIPEventContext(type, time));
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_events.SetAt(id, spContext);
    }
}
MS2_REPLACE_METHOD(0x140426D00, CGameEventValueIDIPEvent, Add, 242, 0x58467692);
// @0x140426e00
void CGameEventValueIDIPEvent::Remove(unsigned id)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_events.RemoveKey(id);
    }
}
MS2_REPLACE_METHOD(0x140426E00, CGameEventValueIDIPEvent, Remove, 94, 0x7AA31C84);
// @0x140426e70
MS2Ptr<CGameEventValueIDIPEvent::IDIPEventContext> CGameEventValueIDIPEvent::Find(int type)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (POSITION pos = m_events.GetStartPosition(); pos != NULL; m_events.GetNext(pos)) {
            const MS2Ptr<IDIPEventContext>& pCtx = m_events.GetValueAt(pos);
            MS2_ASSERT_AT(0x43a, pCtx != NULL);
            if (pCtx->m_type == type)
                return pCtx;
        }
    }
    return MS2Ptr<IDIPEventContext>(0);
}
MS2_REPLACE_METHOD(0x140426E70, CGameEventValueIDIPEvent, Find, 312, 0x1200414A);

// @0x140426fb0
CGameEventValueStarShop::CGameEventValueStarShop() : m_value(0) {}
// @0x140426ff0
void CGameEventValueStarShop::SetValue(int value)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_value = value;
    }
}
MS2_REPLACE_METHOD(0x140426FF0, CGameEventValueStarShop, SetValue, 84, 0x6E074668);
// @0x140427050
int CGameEventValueStarShop::GetValue() { return m_value; }
MS2_REPLACE_METHOD(0x140427050, CGameEventValueStarShop, GetValue, 14, 0x828204CF);

// @0x140427070
CGameEventValueNpcShopTalk::CGameEventValueNpcShopTalk() {}
// @0x1404270e0
void CGameEventValueNpcShopTalk::Set(unsigned npcId, unsigned value)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.SetAt(npcId, value);
    }
}
MS2_REPLACE_METHOD(0x1404270E0, CGameEventValueNpcShopTalk, Set, 104, 0x250CF068);
// @0x140427150
void CGameEventValueNpcShopTalk::Remove(unsigned npcId)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.RemoveKey(npcId);
    }
}
MS2_REPLACE_METHOD(0x140427150, CGameEventValueNpcShopTalk, Remove, 94, 0x19BA161F);
// @0x1404271c0
unsigned CGameEventValueNpcShopTalk::Get(unsigned npcId)
{
    unsigned value = 0;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.Lookup(npcId, value);
    }
    return value;
}
MS2_REPLACE_METHOD(0x1404271C0, CGameEventValueNpcShopTalk, Get, 111, 0x450A9876);

// @0x140427240
CGameEventValueNpcShopGivePoint::CGameEventValueNpcShopGivePoint() {}
// @0x1404272b0
void CGameEventValueNpcShopGivePoint::Set(unsigned id, MS2Ptr<CNpcShopGivePointContextBase> spContext)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_contexts.SetAt(id, spContext);
    }
}
MS2_REPLACE_METHOD(0x1404272B0, CGameEventValueNpcShopGivePoint, Set, 115, 0x413FD00D);
// @0x140427330
void CGameEventValueNpcShopGivePoint::Remove(unsigned id)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_contexts.RemoveKey(id);
    }
}
MS2_REPLACE_METHOD(0x140427330, CGameEventValueNpcShopGivePoint, Remove, 94, 0xD2872C04);
// @0x1404273a0
MS2Ptr<CNpcShopGivePointContextBase> CGameEventValueNpcShopGivePoint::Get(unsigned id)
{
    MS2Ptr<CNpcShopGivePointContextBase> spContext(0);
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_contexts.Lookup(id, spContext);
    }
    return spContext;
}
MS2_REPLACE_METHOD(0x1404273A0, CGameEventValueNpcShopGivePoint, Get, 167, 0x05C68060);

// @0x140427450
CGameEventValueNpcShopResetPriceSale::CGameEventValueNpcShopResetPriceSale() {}
// @0x1404274c0
void CGameEventValueNpcShopResetPriceSale::Set(unsigned npcId, unsigned value)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.SetAt(npcId, value);
    }
}
MS2_REPLACE_METHOD(0x1404274C0, CGameEventValueNpcShopResetPriceSale, Set, 104, 0x5FD93745);
// @0x140427530
void CGameEventValueNpcShopResetPriceSale::Remove(unsigned npcId)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.RemoveKey(npcId);
    }
}
MS2_REPLACE_METHOD(0x140427530, CGameEventValueNpcShopResetPriceSale, Remove, 94, 0x65DAC986);
// @0x1404275a0
unsigned CGameEventValueNpcShopResetPriceSale::Get(unsigned npcId)
{
    unsigned value = 0;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.Lookup(npcId, value);
    }
    return value;
}
MS2_REPLACE_METHOD(0x1404275A0, CGameEventValueNpcShopResetPriceSale, Get, 111, 0x8C1D6696);

// @0x140427620
CGameEventValueDungeonOpenPeriod::CGameEventValueDungeonOpenPeriod() {}
// @0x140427690
bool CGameEventValueDungeonOpenPeriod::Add(CStringW strTag, __int64 beginTime, __int64 endTime)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_periods.Lookup(strTag) != NULL)
        return false;
    m_periods.SetAt(strTag, Unk_FieldTimeSpan(beginTime, endTime));
    return true;
}
MS2_REPLACE_METHOD(0x140427690, CGameEventValueDungeonOpenPeriod, Add, 223, 0x010C4E54);
// @0x140427780
void CGameEventValueDungeonOpenPeriod::Remove(CStringW strTag)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_periods.RemoveKey(strTag);
}
MS2_REPLACE_METHOD(0x140427780, CGameEventValueDungeonOpenPeriod, Remove, 102, 0x524DE99C);
// @0x1404277f0
bool CGameEventValueDungeonOpenPeriod::IsOpen(CStringW strTag, __int64 time)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    Unk_FieldTimeSpan period;
    if (m_periods.Lookup(strTag, period) && period.Contains(time))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1404277F0, CGameEventValueDungeonOpenPeriod, IsOpen, 196, 0xBC3EB292);
// @0x1404278c0
bool CGameEventValueDungeonOpenPeriod::GetPeriod(CStringW strTag, Unk_FieldTimeSpan& period)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_periods.Lookup(strTag, period))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1404278C0, CGameEventValueDungeonOpenPeriod, GetPeriod, 164, 0x97526327);

// @0x140427970
Unk_GameEventValueIdSet::Unk_GameEventValueIdSet() {}
// @0x1404279c0
void Unk_GameEventValueIdSet::Add(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_ids.insert(id);
}
MS2_REPLACE_METHOD(0x1404279C0, Unk_GameEventValueIdSet, Add, 90, 0x765DF160);
// @0x140427a20
void Unk_GameEventValueIdSet::Remove(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_ids.erase(id);
}
MS2_REPLACE_METHOD(0x140427A20, Unk_GameEventValueIdSet, Remove, 85, 0x50DD0B4C);
// @0x140427a80
bool Unk_GameEventValueIdSet::IsActive()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return !m_ids.empty();
}
MS2_REPLACE_METHOD(0x140427A80, Unk_GameEventValueIdSet, IsActive, 104, 0x24B33944);

// @0x140427af0
Unk_GameEventValueDayItem::Unk_GameEventValueDayItem() {}
// @0x140427b60
void Unk_GameEventValueDayItem::Add(unsigned id, Unk_DayItemContext* pContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    MS2Ptr<Unk_DayItemContext> spContext(pContext);
    m_contexts.SetAt(id, spContext);
}
MS2_REPLACE_METHOD(0x140427B60, Unk_GameEventValueDayItem, Add, 121, 0x362E5040);
// @0x140427be0
void Unk_GameEventValueDayItem::Remove(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.RemoveKey(id);
}
MS2_REPLACE_METHOD(0x140427BE0, Unk_GameEventValueDayItem, Remove, 73, 0x2F736E1C);
// @0x140427c30
void Unk_GameEventValueDayItem::GetContexts(ATL::CAtlArray<MS2Ptr<Unk_DayItemContext> >& contexts, bool bAll)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (POSITION pos = m_contexts.GetStartPosition(); pos != NULL; m_contexts.GetNext(pos)) {
        Unk_DayItemContext* pContext = m_contexts.GetValueAt(pos);
        if (pContext->IsActive() || bAll)
            contexts.Add(pContext);
    }
}
MS2_REPLACE_METHOD(0x140427C30, Unk_GameEventValueDayItem, GetContexts, 230, 0x7C1988D0);

// @0x140427d20
Unk_GameEventValueFieldObjectDrop::Unk_GameEventValueFieldObjectDrop() {}
// @0x140427d90
void Unk_GameEventValueFieldObjectDrop::Add(unsigned id, Unk_FieldObjectDropContext* pContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    MS2Ptr<Unk_FieldObjectDropContext> spContext(pContext);
    m_contexts.SetAt(id, spContext);
}
MS2_REPLACE_METHOD(0x140427D90, Unk_GameEventValueFieldObjectDrop, Add, 121, 0xA37A22DD);
// @0x140427e10
void Unk_GameEventValueFieldObjectDrop::Remove(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.RemoveKey(id);
}
MS2_REPLACE_METHOD(0x140427E10, Unk_GameEventValueFieldObjectDrop, Remove, 73, 0xB04BE897);
// @0x140427e60
void Unk_GameEventValueFieldObjectDrop::GetContexts(ATL::CAtlArray<MS2Ptr<Unk_FieldObjectDropContext> >& contexts)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (POSITION pos = m_contexts.GetStartPosition(); pos != NULL; m_contexts.GetNext(pos)) {
        Unk_FieldObjectDropContext* pContext = m_contexts.GetValueAt(pos);
        contexts.Add(pContext);
    }
}
MS2_REPLACE_METHOD(0x140427E60, Unk_GameEventValueFieldObjectDrop, GetContexts, 196, 0x862D4890);

// @0x140427f30
Unk_GameEventValueFieldObjectDropList::Unk_GameEventValueFieldObjectDropList() {}
// @0x140427fa0
void Unk_GameEventValueFieldObjectDropList::Add(unsigned id, Unk_FieldObjectDropListContext* pContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    MS2Ptr<Unk_FieldObjectDropListContext> spContext(pContext);
    m_contexts.SetAt(id, spContext);
}
MS2_REPLACE_METHOD(0x140427FA0, Unk_GameEventValueFieldObjectDropList, Add, 121, 0xF624B4C9);
// @0x140428020
void Unk_GameEventValueFieldObjectDropList::Remove(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.RemoveKey(id);
}
MS2_REPLACE_METHOD(0x140428020, Unk_GameEventValueFieldObjectDropList, Remove, 73, 0xB0A511DA);
// @0x140428070
void Unk_GameEventValueFieldObjectDropList::GetContexts(ATL::CAtlArray<MS2Ptr<Unk_FieldObjectDropListContext> >& contexts)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (POSITION pos = m_contexts.GetStartPosition(); pos != NULL; m_contexts.GetNext(pos)) {
        Unk_FieldObjectDropListContext* pContext = m_contexts.GetValueAt(pos);
        contexts.Add(pContext);
    }
}
MS2_REPLACE_METHOD(0x140428070, Unk_GameEventValueFieldObjectDropList, GetContexts, 196, 0x26A036DA);
// @0x140428140
Unk_GameEventValueFieldObjectDropList2::Unk_GameEventValueFieldObjectDropList2() {}

// @0x140428170
CGameEventValueBurningLevelup::CGameEventValueBurningLevelup() {}
// @0x1404281c0
CGameEventValueBurningLevelup::~CGameEventValueBurningLevelup() {}
// @0x140428200
MS2Ptr<BurningLevelupContext> CGameEventValueBurningLevelup::Get(unsigned eventId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned, MS2Ptr<BurningLevelupContext> >::const_iterator it = m_contexts.find(eventId);
    if (it == m_contexts.end())
        return MS2Ptr<BurningLevelupContext>(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x140428200, CGameEventValueBurningLevelup, Get, 236, 0x4041F014);
// @0x140428300
void CGameEventValueBurningLevelup::GetAll(std::list<MS2Ptr<BurningLevelupContext> >& contexts)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.empty())
        return;
    for (std::map<unsigned, MS2Ptr<BurningLevelupContext> >::const_iterator it = m_contexts.begin();
         it != m_contexts.end(); ++it)
        contexts.push_back(it->second);
}
MS2_REPLACE_METHOD(0x140428300, CGameEventValueBurningLevelup, GetAll, 212, 0xA5A93BD6);
// @0x1404283e0
void CGameEventValueBurningLevelup::Add(MS2Ptr<BurningLevelupContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.insert(std::make_pair(spContext->m_eventId, spContext));
}
MS2_REPLACE_METHOD(0x1404283E0, CGameEventValueBurningLevelup, Add, 175, 0x55727A72);
// @0x1404284a0
void CGameEventValueBurningLevelup::Remove(MS2Ptr<BurningLevelupContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.erase(spContext->m_eventId);
}
MS2_REPLACE_METHOD(0x1404284A0, CGameEventValueBurningLevelup, Remove, 106, 0x9E85B4D5);
// @0x140428510
MS2Ptr<BurningLevelupContext> CGameEventValueBurningLevelup::FindByTarget(int id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (std::map<unsigned, MS2Ptr<BurningLevelupContext> >::const_iterator it = m_contexts.begin();
         it != m_contexts.end(); ++it) {
        if (it->second == NULL)
            continue;
        if (!it->second->HasTarget(id))
            continue;
        return it->second;
    }
    return MS2Ptr<BurningLevelupContext>(0);
}
MS2_REPLACE_METHOD(0x140428510, CGameEventValueBurningLevelup, FindByTarget, 326, 0xCDB3E322);

// @0x140428670
CGameEventValueCoupleDance::CGameEventValueCoupleDance() : m_spContext(0) {}
// @0x1404286c0
CGameEventValueCoupleDance::~CGameEventValueCoupleDance() {}
// @0x140428700
MS2Ptr<CoupleDanceContext> CGameEventValueCoupleDance::Get()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_spContext;
}
MS2_REPLACE_METHOD(0x140428700, CGameEventValueCoupleDance, Get, 109, 0x58AFDF23);
// @0x140428780
void CGameEventValueCoupleDance::Set(MS2Ptr<CoupleDanceContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_spContext = spContext;
}
MS2_REPLACE_METHOD(0x140428780, CGameEventValueCoupleDance, Set, 97, 0x2514FCBD);

// @0x1404287f0
CGameEventValuePublicTest::CGameEventValuePublicTest() : m_value(0) {}
// @0x140428810
void CGameEventValuePublicTest::SetValue(int value) { m_value = value; }
MS2_REPLACE_METHOD(0x140428810, CGameEventValuePublicTest, SetValue, 21, 0xA2C4AECF);
// @0x140428830
int CGameEventValuePublicTest::GetValue() { return m_value; }
MS2_REPLACE_METHOD(0x140428830, CGameEventValuePublicTest, GetValue, 13, 0xA5869133);

// @0x140428850
CGameEventValueFestival::CGameEventValueFestival() { m_contexts.RemoveAll(); }
// @0x1404288d0
void CGameEventValueFestival::GetAll(ATL::CAtlArray<MS2Ptr<FestivalContext> >& contexts)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (POSITION pos = m_contexts.GetStartPosition(); pos != NULL; m_contexts.GetNext(pos)) {
            contexts.Add(m_contexts.GetValueAt(pos));
        }
    }
}
MS2_REPLACE_METHOD(0x1404288D0, CGameEventValueFestival, GetAll, 164, 0x2FE22AB8);
// @0x140428980
void CGameEventValueFestival::Add(unsigned id, MS2Ptr<FestivalContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.SetAt(id, spContext);
}
MS2_REPLACE_METHOD(0x140428980, CGameEventValueFestival, Add, 105, 0x37E6EBE7);
// @0x1404289f0
void CGameEventValueFestival::Remove(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.RemoveKey(id);
}
MS2_REPLACE_METHOD(0x1404289F0, CGameEventValueFestival, Remove, 73, 0x82F6E4F5);

// @0x140428a40
CGameEventValueFieldEffect::CGameEventValueFieldEffect() : m_spContext(0) {}
// @0x140428a90
MS2Ptr<FieldEffectContext> CGameEventValueFieldEffect::Get()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_spContext;
}
MS2_REPLACE_METHOD(0x140428A90, CGameEventValueFieldEffect, Get, 109, 0xA9308182);
// @0x140428b10
void CGameEventValueFieldEffect::Set(MS2Ptr<FieldEffectContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_spContext = spContext;
}
MS2_REPLACE_METHOD(0x140428B10, CGameEventValueFieldEffect, Set, 97, 0xAF0BA767);

// @0x140428b80
CGameEventValueExchangeScrollSale::CGameEventValueExchangeScrollSale() {}
// @0x140428bf0
void CGameEventValueExchangeScrollSale::Set(unsigned long itemId, int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rates.SetAt(itemId, rate);
}
MS2_REPLACE_METHOD(0x140428BF0, CGameEventValueExchangeScrollSale, Set, 94, 0xA871C6CE);
// @0x140428c60
void CGameEventValueExchangeScrollSale::Remove(unsigned long itemId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rates.RemoveKey(itemId);
}
MS2_REPLACE_METHOD(0x140428C60, CGameEventValueExchangeScrollSale, Remove, 73, 0x0C93742A);
// @0x140428cb0
int CGameEventValueExchangeScrollSale::Get(unsigned long itemId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    int rate = 0;
    m_rates.Lookup(itemId, rate);
    return rate;
}
MS2_REPLACE_METHOD(0x140428CB0, CGameEventValueExchangeScrollSale, Get, 108, 0x7C7E7B8B);

// @0x140428d30
Unk_GameEventValueC50::Unk_GameEventValueC50() : m_beginTime(0), m_endTime(0), m_value(0) {}
// @0x140428d80
void Unk_GameEventValueC50::Set(__int64 beginTime, __int64 endTime, int value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_beginTime = beginTime;
    m_endTime = endTime;
    m_value = value;
}
MS2_REPLACE_METHOD(0x140428D80, Unk_GameEventValueC50, Set, 103, 0x1E406735);
// @0x140428df0
void Unk_GameEventValueC50::Clear()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_beginTime = 0;
    m_endTime = 0;
    m_value = 0;
}
MS2_REPLACE_METHOD(0x140428DF0, Unk_GameEventValueC50, Clear, 86, 0xDC8FEB2B);
// @0x140428e50
bool Unk_GameEventValueC50::Get(__int64& beginTime, __int64& endTime, int& value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_beginTime == 0 && m_value == 0)
        return false;
    beginTime = m_beginTime;
    endTime = m_endTime;
    value = m_value;
    return true;
}
MS2_REPLACE_METHOD(0x140428E50, Unk_GameEventValueC50, Get, 167, 0xD86093BA);

// @0x140428f00
CGameEventValueItemTradeRestriction::RestrictionData::RestrictionData() {}
// @0x1404290b0
void CGameEventValueItemTradeRestriction::RestrictionData::SetLimit(Unk_ItemTradeRestrictionType eType, unsigned itemId,
                                                                    unsigned short limit)
{
    switch (eType) {
    case eItemTradeRestriction_BlackMarketSell:
        m_blackMarketSell.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_BlackMarketBuy:
        m_blackMarketBuy.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_TradeSend:
        m_tradeSend.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_TradeRecv:
        m_tradeRecv.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_DropItem:
        m_dropItem.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_PickupItem:
        m_pickupItem.SetAt(itemId, limit);
        break;
    }
}
// @0x1404291d0
unsigned short CGameEventValueItemTradeRestriction::RestrictionData::GetLimit(Unk_ItemTradeRestrictionType eType,
                                                                              unsigned itemId)
{
    unsigned short limit = 0;
    switch (eType) {
    case eItemTradeRestriction_BlackMarketSell:
        m_blackMarketSell.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_BlackMarketBuy:
        m_blackMarketBuy.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_TradeSend:
        m_tradeSend.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_TradeRecv:
        m_tradeRecv.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_DropItem:
        m_dropItem.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_PickupItem:
        m_pickupItem.Lookup(itemId, limit);
        break;
    }
    return limit;
}
// @0x1404292f0
CGameEventValueItemTradeRestriction::CGameEventValueItemTradeRestriction() {}
// @0x140429330
void CGameEventValueItemTradeRestriction::Add(unsigned eventId, const MS2Ptr<RestrictionData>& spData)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_events.SetAt(eventId, spData);
    }
}
MS2_REPLACE_METHOD(0x140429330, CGameEventValueItemTradeRestriction, Add, 104, 0x0E749258);
// @0x1404293a0
void CGameEventValueItemTradeRestriction::Remove(unsigned eventId)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_events.RemoveKey(eventId);
    }
}
MS2_REPLACE_METHOD(0x1404293A0, CGameEventValueItemTradeRestriction, Remove, 94, 0xBF40912A);
// @0x140429410
unsigned short CGameEventValueItemTradeRestriction::GetLimit(Unk_ItemTradeRestrictionType eType, unsigned itemId)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (POSITION pos = m_events.GetHeadPosition(); pos != NULL; m_events.GetNext(pos)) {
            const MS2Ptr<RestrictionData>& spData = m_events.GetValueAt(pos);
            unsigned short limit = spData->GetLimit(eType, itemId);
            if (limit != 0)
                return limit;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140429410, CGameEventValueItemTradeRestriction, GetLimit, 233, 0xBBC14C33);

// @0x140429500
CGameEventValueCollectItemGroup::CGameEventValueCollectItemGroup() {}
// @0x140429550
CGameEventValueCollectItemGroup::~CGameEventValueCollectItemGroup() {}
// @0x140429590
MS2Ptr<CollectItemGroupContext> CGameEventValueCollectItemGroup::Get(unsigned eventId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned, MS2Ptr<CollectItemGroupContext> >::const_iterator it = m_contexts.find(eventId);
    if (it == m_contexts.end())
        return MS2Ptr<CollectItemGroupContext>(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x140429590, CGameEventValueCollectItemGroup, Get, 236, 0x333271B3);
// @0x140429690
void CGameEventValueCollectItemGroup::GetAll(std::vector<MS2Ptr<CollectItemGroupContext> >& contexts)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.empty())
        return;
    for (std::map<unsigned, MS2Ptr<CollectItemGroupContext> >::const_iterator it = m_contexts.begin();
         it != m_contexts.end(); ++it)
        contexts.push_back(it->second);
}
MS2_REPLACE_METHOD(0x140429690, CGameEventValueCollectItemGroup, GetAll, 212, 0x7E96E66A);
// @0x140429770
void CGameEventValueCollectItemGroup::Add(MS2Ptr<CollectItemGroupContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.insert(std::make_pair(spContext->m_eventId, spContext));
}
MS2_REPLACE_METHOD(0x140429770, CGameEventValueCollectItemGroup, Add, 175, 0xB05B38C0);
// @0x140429830
void CGameEventValueCollectItemGroup::Remove(MS2Ptr<CollectItemGroupContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.erase(spContext->m_eventId);
}
MS2_REPLACE_METHOD(0x140429830, CGameEventValueCollectItemGroup, Remove, 106, 0x14054B8D);

// @0x1404298a0
CGameEventValueArcadeOpen::CGameEventValueArcadeOpen() {}
// @0x1404298f0
CGameEventValueArcadeOpen::~CGameEventValueArcadeOpen() {}
// @0x140429930
MS2Ptr<ArcadeOpenContext> CGameEventValueArcadeOpen::Get(int arcadeId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<int, MS2Ptr<ArcadeOpenContext> >::const_iterator it = m_contexts.find(arcadeId);
    if (it == m_contexts.end())
        return MS2Ptr<ArcadeOpenContext>(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x140429930, CGameEventValueArcadeOpen, Get, 236, 0x5D89F478);
// @0x140429a30
bool CGameEventValueArcadeOpen::Add(MS2Ptr<ArcadeOpenContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.find(spContext->m_arcadeId) != m_contexts.end())
        return false;
    m_contexts.insert(std::make_pair(spContext->m_arcadeId, spContext));
    return true;
}
MS2_REPLACE_METHOD(0x140429A30, CGameEventValueArcadeOpen, Add, 324, 0xB6CA9603);
// @0x140429b80
void CGameEventValueArcadeOpen::Remove(MS2Ptr<ArcadeOpenContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.erase(spContext->m_arcadeId);
}
MS2_REPLACE_METHOD(0x140429B80, CGameEventValueArcadeOpen, Remove, 106, 0x3BB2CE8A);

// @0x140429bf0
CGameEventValueBingo::CGameEventValueBingo() {}
// @0x140429c40
CGameEventValueBingo::~CGameEventValueBingo() {}
// @0x140429c80
MS2Ptr<BingoContext> CGameEventValueBingo::Get()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_spContext;
}
MS2_REPLACE_METHOD(0x140429C80, CGameEventValueBingo, Get, 109, 0x24C71C9F);
// @0x140429d00
void CGameEventValueBingo::Set(MS2Ptr<BingoContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!spContext)
        return;
    m_spContext = spContext;
}
MS2_REPLACE_METHOD(0x140429D00, CGameEventValueBingo, Set, 137, 0xB7F89AE7);
// @0x140429d90
void CGameEventValueBingo::Clear(MS2Ptr<BingoContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_spContext == spContext.get())
        m_spContext = 0;
}
MS2_REPLACE_METHOD(0x140429D90, CGameEventValueBingo, Clear, 128, 0x3A3735E8);

// @0x140429e20
CGameEventValueLimitedQuantity::CGameEventValueLimitedQuantity() {}
// @0x140429e80
CGameEventValueLimitedQuantity::~CGameEventValueLimitedQuantity() {}
// @0x140429ed0
MS2Ptr<LimitedQuantityContext> CGameEventValueLimitedQuantity::Get(unsigned eventId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.find(eventId) == m_contexts.end())
        return MS2Ptr<LimitedQuantityContext>(0);
    return m_contexts[eventId];
}
MS2_REPLACE_METHOD(0x140429ED0, CGameEventValueLimitedQuantity, Get, 241, 0xF079E2C4);
// @0x140429fd0
MS2Ptr<LimitedQuantityContext> CGameEventValueLimitedQuantity::GetByKey(unsigned key)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_keys.find(key) == m_keys.end())
        return MS2Ptr<LimitedQuantityContext>(0);
    unsigned eventId = m_keys[key];
    return Get(eventId);
}
MS2_REPLACE_METHOD(0x140429FD0, CGameEventValueLimitedQuantity, GetByKey, 254, 0x79AE0AB6);
// @0x14042a0e0
void CGameEventValueLimitedQuantity::Add(MS2Ptr<LimitedQuantityContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!spContext)
        return;
    if (spContext->m_1c == 0 || spContext->m_eventId == 0)
        return;
    std::map<unsigned, unsigned>::iterator it = m_keys.find(spContext->m_1c);
    if (it != m_keys.end())
        return;
    m_keys[spContext->m_1c] = spContext->m_eventId;
    m_contexts[spContext->m_eventId] = spContext;
}
MS2_REPLACE_METHOD(0x14042A0E0, CGameEventValueLimitedQuantity, Add, 377, 0xDEA51D0F);
// @0x14042a260
void CGameEventValueLimitedQuantity::Remove(MS2Ptr<LimitedQuantityContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!spContext)
        return;
    if (spContext->m_1c == 0 || spContext->m_eventId == 0)
        return;
    m_keys.erase(spContext->m_1c);
    m_contexts.erase(spContext->m_eventId);
}
MS2_REPLACE_METHOD(0x14042A260, CGameEventValueLimitedQuantity, Remove, 235, 0x7D150D83);

// @0x14042a360
CGameEventValueEventShopNpc::CGameEventValueEventShopNpc() {}
// @0x14042a3c0
void CGameEventValueEventShopNpc::Add(MS2Ptr<EventShopNpcContext> pContext)
{
    MS2_ASSERT_AT(0x863, pContext != NULL);
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts[pContext->Get18()] = pContext;
    std::map<unsigned long, Contexts>::iterator it = m_groups.find(pContext->Get20());
    if (it == m_groups.end()) {
        Contexts contexts;
        contexts.push_back(pContext);
        m_groups.insert(std::make_pair(static_cast<unsigned long>(pContext->Get20()), contexts));
    } else {
        it->second.push_back(pContext);
    }
}
MS2_REPLACE_METHOD(0x14042A3C0, CGameEventValueEventShopNpc, Add, 479, 0xBA05DEF6);
// @0x14042a5b0
void CGameEventValueEventShopNpc::Remove(int id)
{
    // MS2-FUNCTIONAL: the exe frame has two more EH states and a different temp layout in the list walk
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned, MS2Ptr<EventShopNpcContext> >::iterator it = m_contexts.find(id);
    if (it == m_contexts.end())
        return;
    unsigned long group = it->second->Get20();
    m_contexts.erase(it);
    std::map<unsigned long, Contexts>::iterator itGroup = m_groups.find(group);
    if (itGroup == m_groups.end()) {
        MS2_ASSERT_AT(0x889, FALSE);
    } else {
        Contexts& contexts = itGroup->second;
        for (Contexts::iterator itList = contexts.begin(); itList != contexts.end();) {
            if ((*itList)->Get18() == id)
                contexts.erase(itList++);
            else
                ++itList;
        }
    }
}
MS2_REPLACE_METHOD(0x14042A5B0, CGameEventValueEventShopNpc, Remove, 525, 0x531C9D95);
// @0x14042a7d0
MS2Ptr<EventShopNpcContext> CGameEventValueEventShopNpc::Find(unsigned long group, int npcId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned long, Contexts>::iterator it = m_groups.find(group);
    if (it == m_groups.end())
        return MS2Ptr<EventShopNpcContext>(0);
    Contexts& contexts = it->second;
    for (Contexts::iterator itList = contexts.begin(); itList != contexts.end(); ++itList) {
        if ((*itList)->Get1c() == npcId)
            return *itList;
    }
    return MS2Ptr<EventShopNpcContext>(0);
}
MS2_REPLACE_METHOD(0x14042A7D0, CGameEventValueEventShopNpc, Find, 396, 0x247BC1B9);

// The CAtlList<MS2Ptr<...> > users (NewNode 0x1404508e0/0x1404509a0/0x140450a60) are in unit_14044a880, but the
// node ctors' COMDATs landed in this range.
template ATL::CAtlList<MS2Ptr<Unk_DayItemContext> >::CNode::CNode(const MS2Ptr<Unk_DayItemContext>&);
template ATL::CAtlList<MS2Ptr<Unk_FieldObjectDropListContext> >::CNode::CNode(const MS2Ptr<Unk_FieldObjectDropListContext>&);
template ATL::CAtlList<MS2Ptr<Unk_FieldObjectDropContext> >::CNode::CNode(const MS2Ptr<Unk_FieldObjectDropContext>&);
