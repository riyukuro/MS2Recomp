// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The NPC shop tables (Table/Server/shop_game_info.xml,
// shop_game.xml, shop_specialRandom_new.xml, shop_meratGroup.xml) and the beauty shop / coupon tables. The client
// build keeps the server loaders' shells: the shop-table loader is a constant TRUE (0x1406df180) and FUN_1406df690
// only compares the old and new table directories. Types: npcshopdata.h; the buy period / new item / merat item
// classes are in their placeholder headers (client units use them). v2525's bodies were the starting point.
// MS2-UNIT: commonfiles\npcshopdata.cpp
// MS2-RANGE: 0x1400bb9a0-0x1400bbd90 .text$di
// MS2-RANGE: 0x1406dc170-0x1406f96f0 .text$mn
// MS2-RANGE: 0x142c9b860-0x142c9ba60 .text$yd
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@6B@ 0x142d7e768
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@@ATL@@@ATL@@@@6B@ 0x142d7e778
// MS2-PIN: ??1CPair@?$CRBTree@IV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@@3@@ATL@@IEAA@XZ 0x1406ef8d0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_coupons@@YAXXZ 0x1400bbb40 ; prop
// MS2-PIN: ??__Es_npcShops@@YAXXZ 0x1400bbb70 ; prop
// MS2-PIN: ??__Es_shopLimits@@YAXXZ 0x1400bbba0 ; prop
// MS2-PIN: ??__Es_beautyShops@@YAXXZ 0x1400bbbd0 ; prop
// MS2-PIN: ??$?0V?$tuple@AEB_J@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@std@@QEAA@AEAV?$tuple@AEB_J@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1406e6560 ; unique
// MS2-PIN: ??$?8V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@YA_NAEBV?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@0@0@Z 0x1406e6640 ; unique
// MS2-PIN: ??$?9V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@YA_NAEBV?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@0@0@Z 0x1406e66f0 ; unique
// MS2-PIN: ??$?RAEBIAEBI@?$equal_to@X@std@@QEBA_NAEBI0@Z 0x1406e6770 ; unique
// MS2-PIN: ??$LogWarn@II@Unk_NpcShopLog@@QEAAX_K0HPEB_WAEBI2@Z 0x1406e7140 ; unique
// MS2-PIN: ??$_Adl_verify_range1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x1406e8d70 ; unique
// MS2-PIN: ??$_Adl_verify_range@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@0@0@Z 0x1406e8d80 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_J@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_J@1@$$QEAV?$tuple@$$V@1@@Z 0x1406e8ed0 ; unique
// MS2-PIN: ??$_Equal_memcmp_is_safe@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@V12@U?$equal_to@X@2@@std@@YA?AU?$integral_constant@_N$0A@@0@AEBV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@0@0AEBU?$equal_to@X@0@@Z 0x1406e95c0 ; unique
// MS2-PIN: ??$_Equal_unchecked1@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@V12@U?$equal_to@X@2@@std@@YA_NV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@0@V10@0U?$equal_to@X@0@U?$integral_constant@_N$0A@@0@@Z 0x1406e95f0 ; unique
// MS2-PIN: ??$_Equal_unchecked@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@V12@U?$equal_to@X@2@@std@@YA_NV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@0@00U?$equal_to@X@0@@Z 0x1406e9680 ; unique
// MS2-PIN: ??$_Get_unwrapped@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@$0A@@std@@YA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@0@AEBV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@0@@Z 0x1406e9810 ; unique
// MS2-PIN: ??$_Get_unwrapped_n@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@U_Distance_unknown@2@$0A@@std@@YA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@0@AEBV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@0@U_Distance_unknown@0@@Z 0x1406e9850 ; unique
// MS2-PIN: ??$_Idl_distance1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@2@@std@@YA?AU_Distance_unknown@0@AEBV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@0@0Uinput_iterator_tag@0@@Z 0x1406e98c0 ; unique
// MS2-PIN: ??$_Idl_distance@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@2@@std@@YA?AU_Distance_unknown@0@AEBV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@0@0@Z 0x1406e9920 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEB_J@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_J@1@$$QEAV?$tuple@$$V@1@@Z 0x1406ecb20 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_J@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$MS2Ptr@VCBeautyShopItemGroup@@@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_J@1@$$QEAV?$tuple@$$V@1@@Z 0x1406ecec0 ; unique
// MS2-PIN: ??$equal@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@@std@@YA_NV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@0@00@Z 0x1406ecf60 ; unique
// MS2-PIN: ??$equal@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@U?$equal_to@X@2@@std@@YA_NV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@0@00U?$equal_to@X@0@@Z 0x1406ecfa0 ; unique
// MS2-PIN: ??$forward@AEBU?$less@_J@std@@@std@@YAAEBU?$less@_J@0@AEBU10@@Z 0x1406ed360 ; prop
// MS2-PIN: ??$forward@V?$tuple@AEB_J@std@@@std@@YA$$QEAV?$tuple@AEB_J@0@AEAV10@@Z 0x1406ed3d0 ; prop
// MS2-PIN: ??$move@AEAV?$tuple@AEB_J@std@@@std@@YA$$QEAV?$tuple@AEB_J@0@AEAV10@@Z 0x1406ed5c0 ; prop
// MS2-PIN: ??0?$CRBMap@IV?$MS2Ptr@VCBeautyShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopData@@@@@3@@ATL@@QEAA@_K@Z 0x1406edb40 ; prop
// MS2-PIN: ??0?$CRBMap@IV?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@@3@@ATL@@QEAA@_K@Z 0x1406edb70 ; prop
// MS2-PIN: ??0?$CRBMap@IV?$MS2Ptr@VCNpcShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopData@@@@@3@@ATL@@QEAA@_K@Z 0x1406edbd0 ; prop
// MS2-PIN: ??0?$CRBTree@IV?$MS2Ptr@VCBeautyShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopData@@@@@3@@ATL@@IEAA@_K@Z 0x1406edc00 ; prop
// MS2-PIN: ??0?$CRBTree@IV?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@@3@@ATL@@IEAA@_K@Z 0x1406edc60 ; prop
// MS2-PIN: ??0?$CRBTree@IV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@@3@@ATL@@IEAA@_K@Z 0x1406edcc0 ; prop
// MS2-PIN: ??0?$CRBTree@IV?$MS2Ptr@VCNpcShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopData@@@@@3@@ATL@@IEAA@_K@Z 0x1406edd20 ; prop
// MS2-PIN: ??0?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@QEAA@$$QEAV0@@Z 0x1406ede20 ; unique
// MS2-PIN: ??0?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@@ATL@@@ATL@@@@QEAA@AEBUUnk_SocketNew@@@Z 0x1406edeb0 ; unique
// MS2-PIN: ??0?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@QEAA@H@Z 0x1406edf60 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCBeautyShopData@@@@QEAA@$$QEAV0@@Z 0x1406edf80 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCBeautyShopItem@@@@QEAA@H@Z 0x1406ee040 ; unique
// MS2-PIN: ??0?$MS2SvrPtr@VCNpcShopBuyPeriod@@@@QEAA@H@Z 0x1406ee1c0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCNpcShopData@@@@QEAA@H@Z 0x1406ee2a0 ; unique
// MS2-PIN: ??1?$CRBMap@IV?$MS2Ptr@VCBeautyShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopData@@@@@3@@ATL@@QEAA@XZ 0x1406eee30 ; prop
// MS2-PIN: ??1?$CRBMap@IV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@@3@@ATL@@QEAA@XZ 0x1406eee70 ; prop
// MS2-PIN: ??1?$CRBMap@IV?$MS2Ptr@VCNpcShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopData@@@@@3@@ATL@@QEAA@XZ 0x1406eee90 ; prop
// MS2-PIN: ??1?$CRBTree@IV?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@@3@@ATL@@QEAA@XZ 0x1406eeef0 ; prop
// MS2-PIN: ??1?$CRBTree@IV?$MS2Ptr@VCNpcShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopData@@@@@3@@ATL@@QEAA@XZ 0x1406eef70 ; prop
// MS2-PIN: ??1CNpcShopBuyPeriod@@UEAA@XZ 0x1406ef650 ; unique
// MS2-PIN: ??4?$MS2Ptr@VCBeautyShopData@@@@QEAAAEAV0@AEBV0@@Z 0x1406efa00 ; prop
// MS2-PIN: ??4?$MS2Ptr@VCBeautyShopItemGroup@@@@QEAAAEAV0@AEBV0@@Z 0x1406efa40 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCMeratMarketPremiumProduct@@@@QEAAAEAV1@PEAVCMeratMarketPremiumProduct@@@Z 0x1406efb20 ; unique
// MS2-PIN: ??8?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@QEBA_NPEAV?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@Z 0x1406efd30 ; unique
// MS2-PIN: ??8?$MS2Ptr@VCNpcShopData@@@@QEBA_NPEAVCNpcShopData@@@Z 0x1406efdb0 ; unique
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1406f00e0 ; prop
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCNpcShopItem@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopItem@@@@@ATL@@@ATL@@QEBAAEBV?$MS2Ptr@VCNpcShopItem@@@@_K@Z 0x1406f0160 ; unique
// MS2-PIN: ??C?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@QEBAPEAV?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@XZ 0x1406f0380 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCBeautyShopItem@@@@QEBAPEAVCBeautyShopItem@@XZ 0x1406f0390 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCBeautyShopItemGroup@@@@QEBAPEAVCBeautyShopItemGroup@@XZ 0x1406f03a0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCBeautyShopItemGroups@@@@QEBAPEAVCBeautyShopItemGroups@@XZ 0x1406f03b0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCNpcShopItemNew@@@@QEBAPEAVCNpcShopItemNew@@XZ 0x1406f03f0 ; unique
// MS2-PIN: ??_GCNode@?$CRBTree@IV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@@3@@ATL@@QEAAPEAXI@Z 0x1406f0f80 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCBeautyShopItem@@@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopItem@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCBeautyShopItem@@@@@Z 0x1406f11c0 ; unique
// MS2-PIN: ?Find@?$CRBTree@IV?$MS2Ptr@VCBeautyShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopData@@@@@3@@ATL@@IEBAPEAVCNode@12@I@Z 0x1406f1c40 ; unique
// MS2-PIN: ?FreeNode@?$CRBTree@IV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x1406f2060 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VCNpcShopItem@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopItem@@@@@ATL@@@ATL@@QEBA_KXZ 0x1406f2340 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VCNpcShopItemNew@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopItemNew@@@@@ATL@@@ATL@@QEBA_KXZ 0x1406f2350 ; unique
// MS2-PIN: ?GetInstance@?$TSingleton@VCMeratMarketPremium@@@@SAPEAVCMeratMarketPremium@@XZ 0x1406f2370 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlArray@V?$MS2Ptr@VCCacheData@@@@V?$CElementTraits@V?$MS2Ptr@VCCacheData@@@@@ATL@@@ATL@@QEBA_NXZ 0x1406f2ed0 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@HV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@@ATL@@@ATL@@@@@3@@ATL@@QEBA_NXZ 0x1406f2f00 ; unique
// MS2-PIN: ?IsNil@?$CRBTree@IV?$MS2Ptr@VCBeautyShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopData@@@@@3@@ATL@@AEBA_NPEAVCNode@12@@Z 0x1406f2fe0 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@IV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@@3@@ATL@@QEBA_NIAEAV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@@Z 0x1406f3330 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@IV?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@@3@@ATL@@QEBA_NIAEAV?$Unk_SocketPtr@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@@Z 0x1406f3380 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@IV?$MS2Ptr@VCBeautyShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopData@@@@@3@@ATL@@QEBA_NIAEAV?$MS2Ptr@VCBeautyShopData@@@@@Z 0x1406f33d0 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@IV?$MS2Ptr@VCNpcShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopData@@@@@3@@ATL@@QEBA_NIAEAV?$MS2Ptr@VCNpcShopData@@@@@Z 0x1406f3420 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@IV?$MS2Ptr@VCBeautyShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopData@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1406f3550 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@IV?$MS2Ptr@VCBeautyShopData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopData@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1406f3f90 ; unique
// MS2-PIN: ?RemoveAll@?$CRBTree@IV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@@3@@ATL@@QEAAXXZ 0x1406f4b70 ; unique
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IV?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x1406f4ee0 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VCItemData@@@@AEBAXXZ 0x1406f5890 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCBeautyShopItem@@@@AEBAXPEAX@Z 0x1406f5b90 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCMeratMarketPremiumProduct@@@@AEBAXPEAX@Z 0x1406f5c50 ; prop
// MS2-PIN: ?ResetNew@?$Unk_SocketPtr@V?$CAtlArray@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@@ATL@@@ATL@@@@AEAAXXZ 0x1406f5e30 ; unique
// MS2-PIN: ?Create@?$Unk_SocketRef@V?$CAtlArray@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@@ATL@@@ATL@@@@SAPEAV?$CAtlArray@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopMeratItemSvr@@@@@ATL@@@ATL@@PEAX@Z 0x1406f5ec0 ; prop
// MS2-PIN: ?Create@?$Unk_SocketRef@V?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@@@SAPEAV?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@PEAX@Z 0x1406f5ef0 ; unique
// MS2-PIN: ?_Unwrapped@?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEBA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@2@XZ 0x1406f8740 ; unique
// MS2-PIN: ??__Fs_coupons@@YAXXZ 0x142c9b960 ; prop
// MS2-PIN: ??__Fs_npcShops@@YAXXZ 0x142c9b980 ; prop
// MS2-PIN: ??__Fs_shopLimits@@YAXXZ 0x142c9b9a0 ; prop
// MS2-PIN: ??__Fs_beautyShops@@YAXXZ 0x142c9b9c0 ; prop
// MS2-PIN: ??__Fempty@?1??FUN_1406e3f10@CBeautyShopItemGroup@@QEAAAEAV?$CAtlArray@V?$MS2Ptr@VCBeautyShopItem@@@@V?$CElementTraits@V?$MS2Ptr@VCBeautyShopItem@@@@@ATL@@@ATL@@H@Z@YAXXZ 0x142c9ba40 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\npcshopdata.cpp"
#define MS2_SVRPTR_ASSIGN_INT
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);
#include "ms2/commonfiles/npcshopdata.h"
#include <algorithm>
#include <iterator>
#include <set>
#include <sstream>
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/commonfiles/itemdatatable.h"          // ItemGradeKey
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cgloabalfactor.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// ---- callees of other units -----------------------------------------------------------------------------------------

CFeatureManager* FUN_140166410();
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);                       // the item table row (null: unknown id)
CGloabalFactor* FUN_140302b10();
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszKey,
                   std::vector<Unk_140165cf0*>& out);                    // the elements with the overrides merged
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // <dir>/<file>
int FUN_140873600(Unk_140165cf0* pElem, const char* pszName, CMsTime& tOut);
int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
int FUN_140873710(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_140873ad0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);
int FUN_14035bc20(Unk_140165cf0* pElem, const char* pszName, unsigned* pOut);
int FUN_14015f500(Unk_140165cf0* pElem, const char* pszName, unsigned* pOut);
void FUN_140275080(const CString& str, std::vector<CString>& out, const char* pszDelim);
int FUN_1407181d0(const CString& str);
int FUN_140557640(Unk_IngTable* pTable, const CString& strName);
void FUN_140177e10(const CString& str, ATL::CAtlArray<unsigned>& out, const char* pszDelim);
void FUN_140177de0(const CString& str, ATL::CAtlArray<unsigned>& out, const char* pszDelim);
void FUN_14015f080(const CString& str, ATL::CAtlArray<CStringW>& out, const char* pszDelim);
int FUN_14021a030(const CStringW& str);
int FUN_1407181a0(const CStringW& str);
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* pszDelim);
void FUN_1401d9a30(const CStringW& str, ATL::CAtlArray<int>& out, const wchar_t* pszDelim);
void FUN_1401859c0(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszText);
void FUN_1402804e0(CLogString* pLog, unsigned __int64 a, unsigned __int64 b, int nCategory, const wchar_t* pszText);
#ifdef __clang__
// clang emits an unavailable MFC CopyChars import for operator+ (hook DLL); use the exe's copy of
// operator+(const wchar_t*, const CStringW&).
CStringW FUN_1401d0160(const wchar_t* psz, const CStringW& str);
#endif

// The unit's log calls (FMT_VARIADIC-style wrappers over CLogString::FUN_1406535b0).
class Unk_NpcShopLog : public CLogString
{
public:
    template <class A, class B>
    void Log(unsigned __int64 a, unsigned __int64 b, int nCategory, const wchar_t* format, const A& v0, const B& v1)
    {
        const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v0),
                                                       fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v1)};
        FUN_1406535b0(a, b, nCategory, format, fmt::ArgList(fmt::internal::make_type(v0, v1), args));
    }
    template <class A, class B, class C>
    void Log(unsigned __int64 a, unsigned __int64 b, int nCategory, const wchar_t* format, const A& v0, const B& v1,
             const C& v2)
    {
        const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v0),
                                                       fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v1),
                                                       fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v2)};
        FUN_1406535b0(a, b, nCategory, format, fmt::ArgList(fmt::internal::make_type(v0, v1, v2), args));
    }
    // The banned-item notice goes through the sibling entry CLogString::FUN_1406536f0 (real name unknown).
    template <class A, class B>
    void LogWarn(unsigned __int64 a, unsigned __int64 b, int nCategory, const wchar_t* format, const A& v0, const B& v1)
    {
        const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v0),
                                                       fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v1)};
        FUN_1406536f0(a, b, nCategory, format, fmt::ArgList(fmt::internal::make_type(v0, v1), args));
    }
};

// The enums the unit formats (fmt's custom-argument path: an enum is written as its int value).
// @0x1406ed040
template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const eShopResetType& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<eShopResetType>::value)
    {
        arg.int_value = value;
        arg.type = internal::Arg::INT;
    }
    else
    {
        std::basic_ostringstream<wchar_t> os;
        os << value;
        std::basic_string<wchar_t> str = os.str();
        arg_value = internal::MakeValue<BasicFormatter<wchar_t> >(str);
        arg.type = internal::Arg::STRING;
    }
    format_str = f.format(format_str, arg);
}

// @0x1406ed160
template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const ItemGradeKey& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<ItemGradeKey>::value)
    {
        arg.int_value = value;
        arg.type = internal::Arg::INT;
    }
    else
    {
        std::basic_ostringstream<wchar_t> os;
        os << value;
        std::basic_string<wchar_t> str = os.str();
        arg_value = internal::MakeValue<BasicFormatter<wchar_t> >(str);
        arg.type = internal::Arg::STRING;
    }
    format_str = f.format(format_str, arg);
}

// ---- the boxed tables (TPtredDummy<CAtlArray<...>>, the smart pointer points at the array) ---------------------------

typedef ATL::CAtlArray<MS2Ptr<CNpcShopMeratItemSvr> > Unk_MeratItemArray;
typedef ATL::CAtlArray<MS2Ptr<CItemData> > Unk_CouponItemArray;
typedef ATL::CAtlArray<__int64> Unk_ShopLimitArray;

#define MS2_NPCSHOP_BOX_REF(T)                                                                                        \
    template<> struct Unk_SocketRef<T> {                                                                              \
        static CPtred* Base(T* p)                                                                                     \
        {                                                                                                             \
            CPtred* result;                                                                                           \
            if (p == NULL) result = NULL;                                                                             \
            else result = CONTAINING_RECORD(p, TPtredDummy<T>, value);                                                \
            return result;                                                                                            \
        }                                                                                                             \
        static TPtredDummy<T>* New(void*) { return new TPtredDummy<T>(); }                                            \
        static T* Value(CPtred* p)                                                                                    \
        {                                                                                                             \
            T* result;                                                                                                \
            if (p == NULL) result = NULL;                                                                             \
            else result = &static_cast<TPtredDummy<T>*>(p)->value;                                                    \
            return result;                                                                                            \
        }                                                                                                             \
        static T* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }                                          \
    };                                                                                                                \
    MS2_SOCKETPTR_BOXED(T)
MS2_NPCSHOP_BOX_REF(Unk_CouponItemArray)          // New 0x1406e8c20
MS2_NPCSHOP_BOX_REF(Unk_MeratItemArray)           // New 0x1406e8c90
MS2_NPCSHOP_BOX_REF(Unk_ShopLimitArray)           // New 0x1406e8d00
MS2_CHECK_SIZE(TPtredDummy<Unk_ShopLimitArray>, 0x38);

typedef Unk_SocketPtr<Unk_MeratItemArray> Unk_MeratItemArrayPtr;
typedef Unk_SocketPtr<Unk_CouponItemArray> Unk_CouponItemArrayPtr;
typedef Unk_SocketPtr<Unk_ShopLimitArray> Unk_ShopLimitArrayPtr;
typedef std::map<unsigned, MS2Ptr<CNpcShopData> > Unk_NpcShopMap;

// ---- statics (.text$di in this order) -----------------------------------------------------------------------------

MS2_NPCSHOPDATA_STATIC ATL::CAtlArray<MS2Ptr<CCacheData> > s_aNpcShopCaches;                                     // 0x143ab0888
MS2_NPCSHOPDATA_STATIC std::vector<CString> s_vecUnused;                                                         // 0x143ab0758
MS2_NPCSHOPDATA_STATIC ATL::CAtlArray<MS2Ptr<CCacheData> > s_aBeautyShopCaches;                                  // 0x143ab0908
MS2_NPCSHOPDATA_STATIC MS2Ptr<CCacheData> s_spCouponCache;                                                       // 0x143ab0988
MS2_NPCSHOPDATA_STATIC CLockCriticalSection s_beautyShopLock;                                                    // 0x143ab08a8
MS2_NPCSHOPDATA_STATIC CLockCriticalSection s_couponLock;                                                        // 0x143ab0928
MS2_NPCSHOPDATA_STATIC CLockCriticalSection s_npcShopLock;                                                       // 0x143ab07b0
MS2_NPCSHOPDATA_STATIC ATL::CAtlMap<int, Unk_MeratItemArrayPtr> s_meratGroups;                                   // 0x143ab0840
MS2_NPCSHOPDATA_STATIC ATL::CRBMap<unsigned, MS2Ptr<CBeautyShopData> > s_beautyShops;                            // 0x143ab08d8
MS2_NPCSHOPDATA_STATIC ATL::CRBMap<unsigned, MS2Ptr<CNpcShopData> > s_npcShops;                                  // 0x143ab07e0
MS2_NPCSHOPDATA_STATIC ATL::CRBMap<unsigned, Unk_ShopLimitArrayPtr> s_shopLimits;                                // 0x143ab0810
MS2_NPCSHOPDATA_STATIC ATL::CRBMap<unsigned, Unk_CouponItemArrayPtr> s_coupons;                                  // 0x143ab0958
static CString s_premiumSortNames[8] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal",
                                        "EnumEnd"};                                              // 0x143ab0770
static CString s_ugcSortNames[7] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};  // 0x143ab0720

// ---- TShopPaymentAttr ---------------------------------------------------------------------------------------------

// @0x1406dc170
TShopPaymentAttr::TShopPaymentAttr() : m_nFeature(1)
{
    FUN_1406dc1e0();
}

// @0x1406dc1e0
void TShopPaymentAttr::FUN_1406dc1e0()
{
    m_nItemId = 0;
    m_nAmount = 0;
    m_eType = (ePaymentType)4;
    m_strIconTag.Empty();
}
MS2_REPLACE_METHOD(0x1406DC1E0, TShopPaymentAttr, FUN_1406dc1e0, 69, 0xBD64AE52);

// @0x1406dc230
void TShopPaymentAttr::FUN_1406dc230(COutputStream& out)
{
    out.vfunc_o10_1((unsigned char)m_eType);
    out.vfunc_o10_3(m_nItemId);
    out.vfunc_o10_3((int)m_nAmount);
    out.vfunc_o10_7(m_strIconTag);
}
MS2_REPLACE_METHOD(0x1406DC230, TShopPaymentAttr, FUN_1406dc230, 130, 0x1A296A99);

// @0x1406dc2c0
void TShopPaymentAttr::FUN_1406dc2c0(CInPacket& in)
{
    m_eType = (ePaymentType)in.vfunc_o8_1();
    m_nItemId = in.vfunc_o8_3();
    m_nAmount = (unsigned)in.vfunc_o8_3();
    m_strIconTag = in.vfunc_o8_7();
}
MS2_REPLACE_METHOD(0x1406DC2C0, TShopPaymentAttr, FUN_1406dc2c0, 249, 0xFA616EDA);

// @0x1406dc3c0
void TShopPaymentAttr::FUN_1406dc3c0(Unk_140165cf0* pElem, const CString& strType, const CString& strItem,
                                     const CString& strIcon, const CString& strPrice)
{
    if (!(pElem))
        return;
    XmlValue(pElem, strType, m_eType);
    FUN_140873220(pElem, strItem, m_nItemId);
    FUN_1408733e0(pElem, strIcon, m_strIconTag);
    FUN_1408732e0(pElem, strPrice, m_nAmount);
}
MS2_REPLACE_METHOD(0x1406DC3C0, TShopPaymentAttr, FUN_1406dc3c0, 226, 0xD6E6362F);

// @0x1406dc4b0
const CString& TShopPaymentAttr::FUN_1406dc4b0() const
{
    return m_strIconTag;
}
MS2_REPLACE_METHOD(0x1406DC4B0, TShopPaymentAttr, FUN_1406dc4b0, 15, 0x271C8F51);

// @0x1406dc4d0
unsigned TShopPaymentAttr::FUN_1406dc4d0() const
{
    return m_nItemId;
}
MS2_REPLACE_METHOD(0x1406DC4D0, TShopPaymentAttr, FUN_1406dc4d0, 14, 0xBA6447E3);

// @0x1406dc4f0
__int64 TShopPaymentAttr::FUN_1406dc4f0() const
{
    return m_nAmount;
}
MS2_REPLACE_METHOD(0x1406DC4F0, TShopPaymentAttr, FUN_1406dc4f0, 15, 0x9BD8F6D9);

// @0x1406dc510
ePaymentType TShopPaymentAttr::FUN_1406dc510() const
{
    if (m_nFeature == 1)
        return m_eType;
    if (!FUN_140166410()->FUN_14036d570(m_nFeature) && (m_eType == 9 || m_eType == 10))
        return (ePaymentType)4;
    return m_eType;
}
MS2_REPLACE_METHOD(0x1406DC510, TShopPaymentAttr, FUN_1406dc510, 100, 0x8A0DEC43);

// @0x1406dc580
void TShopPaymentAttr::FUN_1406dc580(int nFeature)
{
    m_nFeature = nFeature;
}
MS2_REPLACE_METHOD(0x1406DC580, TShopPaymentAttr, FUN_1406dc580, 22, 0x16BC4503);

// ---- CNpcShopBuyPeriod --------------------------------------------------------------------------------------------

// @0x1406dc5a0
CNpcShopBuyPeriod::CNpcShopBuyPeriod()
    : m_tmWindowStart(0), m_tmWindowEnd(0), m_tmStart(0), m_tmEnd(0), m_bVisible(true)
{
}

// @0x1406dc660
bool CNpcShopBuyPeriod::operator!=(const CNpcShopBuyPeriod& o)
{
    if (m_tmWindowStart != o.m_tmWindowStart) return true;
    if (m_tmWindowEnd != o.m_tmWindowEnd) return true;
    if (m_tmStart != o.m_tmStart) return true;
    if (m_tmEnd != o.m_tmEnd) return true;
    if (m_aPartTimes.GetCount() != o.m_aPartTimes.GetCount()) return true;
    for (size_t i = 0; i < m_aPartTimes.GetCount(); i++)
    {
        if (m_aPartTimes[i] != o.m_aPartTimes[i])
            return true;
    }
    if (m_setDays != o.m_setDays) return true;
    if (m_bVisible != o.m_bVisible) return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406DC660, CNpcShopBuyPeriod, operator!=, 426, 0xB0BEB716);

// @0x1406dc810
bool CNpcShopBuyPeriod::FUN_1406dc810()
{
    CMsTime tmNow(GetServerTime());
    FUN_1406dcf10(tmNow);
    return true;
}
MS2_REPLACE_METHOD(0x1406DC810, CNpcShopBuyPeriod, FUN_1406dc810, 49, 0x7096EA85);

// @0x1406dc850
void CNpcShopBuyPeriod::FUN_1406dc850(COutputStream& out)
{
    bool bDates = m_tmStart > CMsTime(0) || m_tmEnd > CMsTime(0);
    bool bParts = FUN_1406dda70();
    out.vfunc_o10_0(bDates);
    if (bDates)
    {
        out.vfunc_o10_4(m_tmStart.Get());
        out.vfunc_o10_4(m_tmEnd.Get());
    }
    out.vfunc_o10_0(bParts);
    if (bParts)
    {
        ATL::CAtlArray<Unk_DayTimeRange>& aParts = m_aPartTimes;
        int nCount = (int)aParts.GetCount();
        out.vfunc_o10_1((unsigned char)nCount);
        for (int i = 0; i < nCount; i++)
        {
            Unk_DayTimeRange& range = aParts.GetAt(i);
            out.vfunc_o10_3(range.m_start.GetSeconds());
            out.vfunc_o10_3(range.m_end.GetSeconds());
        }
        out.vfunc_o10_1((unsigned char)m_setDays.size());
        std::set<int>& days = m_setDays;
        for (std::set<int>::iterator it = days.begin(); it != days.end(); ++it)
            out.vfunc_o10_1((unsigned char)*it);
    }
}
MS2_REPLACE_METHOD(0x1406DC850, CNpcShopBuyPeriod, FUN_1406dc850, 742, 0xD2C9CD27);

// @0x1406dcb40
void CNpcShopBuyPeriod::FUN_1406dcb40(CInPacket& in)
{
    bool bHasTime = in.vfunc_o8_0();
    if (bHasTime)
    {
        m_tmStart = in.vfunc_o8_4();
        m_tmEnd = in.vfunc_o8_4();
    }
    bool bHasPart = in.vfunc_o8_0();
    if (bHasPart)
    {
        int nCount = in.vfunc_o8_1();
        for (int i = 0; i < nCount; i++)
        {
            unsigned nStart = in.vfunc_o8_3();
            unsigned nEnd = in.vfunc_o8_3();
            Unk_DayTimeRange range;
            range.m_start.SetSeconds(nStart);
            range.m_end.SetSeconds(nEnd);
            m_aPartTimes.Add(range);
        }
        int nDays = in.vfunc_o8_1();
        for (int i = 0; i < nDays; i++)
        {
            int nDay = in.vfunc_o8_1();
            m_setDays.insert(nDay);
        }
    }
}
MS2_REPLACE_METHOD(0x1406DCB40, CNpcShopBuyPeriod, FUN_1406dcb40, 661, 0x7C188D13);

// @0x1406dcde0
void CNpcShopBuyPeriod::FUN_1406dcde0(const CMsTime& tmFrom, const CMsTime& tmTo)
{
    if (tmFrom > tmTo)
    {
        MS2_ASSERT_AT(0xba7, FALSE);
        return;
    }
    if (m_tmStart > CMsTime(0))
        m_tmWindowStart = (std::max)(tmFrom, m_tmStart);
    else
        m_tmWindowStart = tmFrom;
    if (m_tmEnd > CMsTime(0))
        m_tmWindowEnd = (std::min)(tmTo, m_tmEnd);
    else
        m_tmWindowEnd = tmTo;
}
MS2_REPLACE_METHOD(0x1406DCDE0, CNpcShopBuyPeriod, FUN_1406dcde0, 293, 0x8DB927FC);

// MS2-FUNCTIONAL: the exe's temporaries for the calendar values differ (written from the decompile and v2525).
// @0x1406dcf10
void CNpcShopBuyPeriod::FUN_1406dcf10(const CMsTime& tmNow)
{
    if (FUN_1406ddb40(tmNow) || FUN_1406ddad0(tmNow))
        return;
    if (!FUN_1406dda70())
    {
        m_tmWindowStart = m_tmStart;
        m_tmWindowEnd = m_tmEnd;
        return;
    }
    if (tmNow < m_tmWindowStart)
        return;
    bool bDays = !m_setDays.empty() && m_setDays.size() < 7;
    bool bParts = !m_aPartTimes.IsEmpty();
    CMsTime tmStart;
    CMsTime tmEnd;
    CMsTime tm(tmNow);
    if (bParts)
    {
        Unk_DayTime now(tm.GetHour(), tm.GetMinute(), tm.GetSecond());
        bool bFound = false;
        Unk_DayTimeRange found;
        for (unsigned i = 0; i < m_aPartTimes.GetCount(); i++)
        {
            if (now < m_aPartTimes[i].m_end)
            {
                bFound = true;
                found = m_aPartTimes[i];
                break;
            }
        }
        if (bFound)
        {
            Unk_DayTime start = found.m_start;
            Unk_DayTime end = found.m_end;
            tmStart = CMsTime(tm.GetYear(), tm.GetMonth(), tm.GetDay(), start.GetHour(), start.GetMinute(),
                              start.GetSecond());
            tmEnd = CMsTime(tm.GetYear(), tm.GetMonth(), tm.GetDay(), end.GetHour(), end.GetMinute(), end.GetSecond());
        }
        else
        {
            Unk_DayTime start = m_aPartTimes[0].m_start;
            Unk_DayTime end = m_aPartTimes[0].m_end;
            CMsTime tmNext = AddByUnit(0, tm, 1);
            tmStart = CMsTime(tmNext.GetYear(), tmNext.GetMonth(), tmNext.GetDay(), start.GetHour(), start.GetMinute(),
                              start.GetSecond());
            tmEnd = CMsTime(tmNext.GetYear(), tmNext.GetMonth(), tmNext.GetDay(), end.GetHour(), end.GetMinute(),
                            end.GetSecond());
        }
    }
    if (bDays)
    {
        if (bParts)
        {
            int nDay = tmStart.GetDayOfWeek();
            if (m_setDays.find(nDay) == m_setDays.end())
            {
                AddDays(tmStart, 1);
                for (int i = 0; i < 7; i++)
                {
                    int nNext = tmStart.GetDayOfWeek();
                    if (m_setDays.find(nNext) != m_setDays.end())
                        break;
                    AddDays(tmStart, 1);
                }
                Unk_DayTime start = m_aPartTimes[0].m_start;
                Unk_DayTime end = m_aPartTimes[0].m_end;
                tmStart = CMsTime(tmStart.GetYear(), tmStart.GetMonth(), tmStart.GetDay(), start.GetHour(),
                                  start.GetMinute(), start.GetSecond());
                tmEnd = CMsTime(tmStart.GetYear(), tmStart.GetMonth(), tmStart.GetDay(), end.GetHour(), end.GetMinute(),
                                end.GetSecond());
            }
        }
        else
        {
            tmStart = CMsTime(tm.GetYear(), tm.GetMonth(), tm.GetDay(), 0, 0, 0);
            for (int i = 0; i < 7; i++)
            {
                int nDay = tmStart.GetDayOfWeek();
                if (m_setDays.find(nDay) != m_setDays.end())
                    break;
                AddDays(tmStart, 1);
            }
            tmEnd = AddByUnit(0, tmStart, 1);
            for (int i = 0; i < 7; i++)
            {
                int nDay = tmEnd.GetDayOfWeek();
                if (m_setDays.find(nDay) == m_setDays.end())
                    break;
                AddDays(tmEnd, 1);
            }
        }
    }
    FUN_1406dcde0(CMsTime(tmStart.Get()), CMsTime(tmEnd.Get()));
}
MS2_REPLACE_METHOD(0x1406DCF10, CNpcShopBuyPeriod, FUN_1406dcf10, 2891, 0x5A479539);

// @0x1406dda70
bool CNpcShopBuyPeriod::FUN_1406dda70() const
{
    if (m_aPartTimes.IsEmpty() && m_setDays.empty())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406DDA70, CNpcShopBuyPeriod, FUN_1406dda70, 85, 0x974395DB);

// @0x1406ddad0
bool CNpcShopBuyPeriod::FUN_1406ddad0(const CMsTime& tm) const
{
    if (m_tmWindowStart <= tm && tm < m_tmWindowEnd)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406DDAD0, CNpcShopBuyPeriod, FUN_1406ddad0, 100, 0x91201766);

// @0x1406ddb40
bool CNpcShopBuyPeriod::FUN_1406ddb40(const CMsTime& tm) const
{
    if (m_tmStart == CMsTime(0) && m_tmEnd == CMsTime(0))
        return false;
    bool bOutside;
    if (m_tmEnd == CMsTime(0))
        bOutside = false;
    else
        bOutside = m_tmStart > tm || tm >= m_tmEnd;
    return bOutside;
}
MS2_REPLACE_METHOD(0x1406DDB40, CNpcShopBuyPeriod, FUN_1406ddb40, 231, 0xA26375FC);

// @0x1406ddc30
bool CNpcShopBuyPeriod::FUN_1406ddc30() const
{
    return m_bVisible;
}
MS2_REPLACE_METHOD(0x1406DDC30, CNpcShopBuyPeriod, FUN_1406ddc30, 18, 0x01A1D2ED);

// @0x1406ddc50
bool CNpcShopBuyPeriod::FUN_1406ddc50(const CMsTime& tmNow)
{
    if (FUN_1406ddc30())
        return true;
    return FUN_1406ddc90(tmNow);
}
MS2_REPLACE_METHOD(0x1406DDC50, CNpcShopBuyPeriod, FUN_1406ddc50, 55, 0xFAEE57E9);

// @0x1406ddc90
bool CNpcShopBuyPeriod::FUN_1406ddc90(const CMsTime& tmNow)
{
    if (!FUN_1406dda70() && !FUN_1406ddb40(tmNow))
        return true;
    if (FUN_1406ddad0(tmNow) == true)
        return true;
    FUN_1406dcf10(tmNow);
    return FUN_1406ddad0(tmNow);
}
MS2_REPLACE_METHOD(0x1406DDC90, CNpcShopBuyPeriod, FUN_1406ddc90, 119, 0xEB52E2AC);

// ---- CNpcShopItem -------------------------------------------------------------------------------------------------

// @0x1406ddd10
CNpcShopItem::CNpcShopItem()
    : m_nSn(0), m_nItemId(0), m_ePaymentType((ePaymentType)0), m_nPaymentItemId(0), m_nPaymentItemSub(0), m_nPrice(0),
      m_nOriginalPrice(0), m_nGrade(0), m_nSellCount(0), m_nRequireGuildTrophy(0), m_nRequireAchieveId(0),
      m_nRequireAchieveGrade(0), m_nRequireChampionship(0), m_nRequireChampionshipRank(0), m_nRequireGuildNpcType(0),
      m_nRequireGuildNpcLevel(0), m_nRequireAlliance(0), m_nRequireAllianceGrade(0), m_nPremiumItem(0), m_nSellUnit(1),
      m_eFrameType((eItemFrameType)0), m_eSaleTag((eShopSaleTag)0), m_bWearForPreview(false), m_nProb(0),
      m_bCheckGameEvent(false)
{
}

// @0x1406dded0
bool CNpcShopItem::operator!=(const CNpcShopItem& o) const
{
    if (m_nSn != o.m_nSn) return true;
    if (m_nItemId != o.m_nItemId) return true;
    if (m_ePaymentType != o.m_ePaymentType) return true;
    if (m_nPaymentItemId != o.m_nPaymentItemId) return true;
    if (m_nPaymentItemSub != o.m_nPaymentItemSub) return true;
    if (m_strPaymentIconTag != o.m_strPaymentIconTag) return true;
    if (m_nPrice != o.m_nPrice) return true;
    if (m_nOriginalPrice != o.m_nOriginalPrice) return true;
    if (m_nGrade != o.m_nGrade) return true;
    if (m_nSellCount != o.m_nSellCount) return true;
    if (m_nRequireGuildTrophy != o.m_nRequireGuildTrophy) return true;
    if (m_nRequireAchieveId != o.m_nRequireAchieveId) return true;
    if (m_nRequireAchieveGrade != o.m_nRequireAchieveGrade) return true;
    if (m_nRequireChampionship != o.m_nRequireChampionship) return true;
    if (m_nRequireChampionshipRank != o.m_nRequireChampionshipRank) return true;
    if (m_nRequireGuildNpcType != o.m_nRequireGuildNpcType) return true;
    if (m_nRequireGuildNpcLevel != o.m_nRequireGuildNpcLevel) return true;
    if (m_nRequireAlliance != o.m_nRequireAlliance) return true;
    if (m_nRequireAllianceGrade != o.m_nRequireAllianceGrade) return true;
    if (m_strCategory != o.m_strCategory) return true;
    if (m_nPremiumItem != o.m_nPremiumItem) return true;
    if (m_nSellUnit != o.m_nSellUnit) return true;
    if (m_eFrameType != o.m_eFrameType) return true;
    if (m_eSaleTag != o.m_eSaleTag) return true;
    if (m_bWearForPreview != o.m_bWearForPreview) return true;
    if (m_spPeriod != 0 && o.m_spPeriod != 0)
    {
        if (*m_spPeriod != *o.m_spPeriod)
            return true;
    }
    else if (m_spPeriod != 0 || o.m_spPeriod != 0)
        return true;
    if (m_spLife != 0 && o.m_spLife != 0)
    {
        if ((*m_spLife).FUN_14026ea20(&*o.m_spLife))
            return true;
    }
    else if (m_spLife != 0 || o.m_spLife != 0)
        return true;
    if (m_nProb != o.m_nProb) return true;
    if (m_bCheckGameEvent != o.m_bCheckGameEvent) return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406DDED0, CNpcShopItem, operator!=, 1104, 0x392C06FF);

// @0x1406de350
bool CNpcShopItem::FUN_1406de350()
{
    if (m_spPeriod != 0)
    {
        CMsTime tmNow(GetServerTime());
        if (!m_spPeriod->FUN_1406ddc50(tmNow))
            return false;
    }
    if (m_spLife != 0)
    {
        CMsTime tmNow(GetServerTime());
        if (!m_spLife->FUN_14026f040(tmNow))
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1406DE350, CNpcShopItem, FUN_1406de350, 186, 0x012367DB);

// @0x1406de410
bool CNpcShopItem::FUN_1406de410()
{
    if (m_spPeriod != 0)
    {
        CMsTime tmNow(GetServerTime());
        if (!m_spPeriod->FUN_1406ddc90(tmNow))
            return false;
    }
    if (m_spLife != 0)
    {
        CMsTime tmNow(GetServerTime());
        if (!m_spLife->FUN_14026f080(tmNow))
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1406DE410, CNpcShopItem, FUN_1406de410, 186, 0x9635E682);

// ---- CNpcShopItemNew ----------------------------------------------------------------------------------------------

// @0x1406de4d0
CNpcShopItemNew::CNpcShopItemNew()
{
    FUN_1406de6b0();
}

// @0x1406de540
bool CNpcShopItemNew::operator!=(const CNpcShopItemNew& o) const
{
    if (m_nItemId != o.m_nItemId) return true;
    if (m_bFlag != o.m_bFlag) return true;
    if (m_nRarity != o.m_nRarity) return true;
    if (m_strName != o.m_strName) return true;
    if (m_nProductType != o.m_nProductType) return true;
    if (m_nProductKind != o.m_nProductKind) return true;
    if (m_spPeriod != 0 && o.m_spPeriod != 0)
    {
        if (*m_spPeriod != *o.m_spPeriod)
            return true;
    }
    else if (m_spPeriod != 0 || o.m_spPeriod != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406DE540, CNpcShopItemNew, operator!=, 347, 0x40D4D927);

// @0x1406de6b0
void CNpcShopItemNew::FUN_1406de6b0()
{
    m_nItemId = 0;
    m_bFlag = false;
    m_nRarity = 0;
    m_nProductType = 0;
    m_nProductKind = 0;
    m_spPeriod = 0;
}
MS2_REPLACE_METHOD(0x1406DE6B0, CNpcShopItemNew, FUN_1406de6b0, 90, 0x442D4EEE);

// @0x1406de710
void CNpcShopItemNew::FUN_1406de710(COutputStream& out)
{
    out.vfunc_o10_3(m_nItemId);
    out.vfunc_o10_0(m_bFlag);
    out.vfunc_o10_1((unsigned char)m_nRarity);
    out.vfunc_o10_7(m_strName);
    out.vfunc_o10_1((unsigned char)m_nProductType);
    out.vfunc_o10_1((unsigned char)m_nProductKind);
    bool bPeriod = m_spPeriod != 0;
    out.vfunc_o10_0(bPeriod);
    if (bPeriod)
        m_spPeriod->FUN_1406dc850(out);
}
MS2_REPLACE_METHOD(0x1406DE710, CNpcShopItemNew, FUN_1406de710, 288, 0x99EB800A);

// @0x1406de840
void CNpcShopItemNew::FUN_1406de840(CInPacket& in)
{
    m_nItemId = in.vfunc_o8_3();
    m_bFlag = in.vfunc_o8_0();
    m_nRarity = in.vfunc_o8_1();
    m_strName = in.vfunc_o8_7();
    m_nProductType = in.vfunc_o8_1();
    m_nProductKind = in.vfunc_o8_1();
    if (in.vfunc_o8_0())
    {
        m_spPeriod = new CNpcShopBuyPeriod;
        m_spPeriod->FUN_1406dcb40(in);
    }
}

// @0x1406dea90
bool CNpcShopItemNew::FUN_1406dea90()
{
    if (m_spPeriod != 0)
    {
        CMsTime tmNow(GetServerTime());
        return m_spPeriod->FUN_1406ddc50(tmNow);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1406DEA90, CNpcShopItemNew, FUN_1406dea90, 88, 0x3DD873BE);

// @0x1406deaf0
bool CNpcShopItemNew::FUN_1406deaf0()
{
    if (m_spPeriod != 0)
    {
        CMsTime tmNow(GetServerTime());
        return m_spPeriod->FUN_1406ddc90(tmNow);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1406DEAF0, CNpcShopItemNew, FUN_1406deaf0, 88, 0x4005A99E);

// ---- CNpcShopData -------------------------------------------------------------------------------------------------

// @0x1406deb50
CNpcShopData::CNpcShopData()
    : m_nShopId(0), m_nShopVersion(0), m_nCategoryId(0), m_nOpenTokenPocket(0), m_nMeratItemGroupId(0),
      m_bOnlySell(false), m_nResetEnable(0), m_bResettable(false), m_eResetPaymentType((ePaymentType)0),
      m_nResetPaymentItemId(0), m_nResetPrice(0), m_nResetListMax(1), m_nResetListMin(1), m_nDisableDisplayOrderSort(0),
      m_nSmartShopItemList(0), m_nResetByAccount(0), m_eResetType((eShopResetType)0), m_bResetButtonHide(false),
      m_eUIFrameType((eShopFrameType)0), m_nTotalProb(0), m_nUseLuaResetPayment(0), m_nUseLuaPremiumItemRandomCount(0),
      m_nResetIntervalTime(0), m_bShowOnlyUsableItem(false), m_bHideOptionInfo(false), m_bShowProbInfo(false),
      m_nNewCategoryId(0)
{
}

// Compares two item lists as sets keyed by sn (FALSE: they differ or an sn repeats).
int FUN_1406e21b0(const ATL::CAtlArray<MS2Ptr<CNpcShopItem> >& a, const ATL::CAtlArray<MS2Ptr<CNpcShopItem> >& b);
// Compares two "new" item lists element-wise.
bool FUN_1406e8b50(const ATL::CAtlArray<MS2Ptr<CNpcShopItemNew> >& a,
                          const ATL::CAtlArray<MS2Ptr<CNpcShopItemNew> >& b);

// @0x1406ded80
bool CNpcShopData::operator!=(const CNpcShopData& o) const
{
    if (m_nShopId != o.m_nShopId) return true;
    if (m_nShopVersion != o.m_nShopVersion) return true;
    if (m_nCategoryId != o.m_nCategoryId) return true;
    if (m_nOpenTokenPocket != o.m_nOpenTokenPocket) return true;
    if (m_nMeratItemGroupId != o.m_nMeratItemGroupId) return true;
    if (m_bOnlySell != o.m_bOnlySell) return true;
    if (m_nResetEnable != o.m_nResetEnable) return true;
    if (m_bResettable != o.m_bResettable) return true;
    if (m_eResetPaymentType != o.m_eResetPaymentType) return true;
    if (m_nResetPaymentItemId != o.m_nResetPaymentItemId) return true;
    if (m_str40 != o.m_str40) return true;
    if (m_nResetPrice != o.m_nResetPrice) return true;
    if (m_nResetListMax != o.m_nResetListMax) return true;
    if (m_nResetListMin != o.m_nResetListMin) return true;
    if (m_nDisableDisplayOrderSort != o.m_nDisableDisplayOrderSort) return true;
    if (m_nSmartShopItemList != o.m_nSmartShopItemList) return true;
    if (m_nResetByAccount != o.m_nResetByAccount) return true;
    if (m_eResetType != o.m_eResetType) return true;
    if (m_bResetButtonHide != o.m_bResetButtonHide) return true;
    if (m_eUIFrameType != o.m_eUIFrameType) return true;
    if (m_strIconName != o.m_strIconName) return true;
    if (m_nTotalProb != o.m_nTotalProb) return true;
    if (!FUN_1406e21b0(m_aItems, o.m_aItems)) return true;
    if (!FUN_1406e21b0(m_aEventItems, o.m_aEventItems)) return true;
    if (m_nUseLuaResetPayment != o.m_nUseLuaResetPayment) return true;
    if (m_nUseLuaPremiumItemRandomCount != o.m_nUseLuaPremiumItemRandomCount) return true;
    if (m_nResetIntervalTime != o.m_nResetIntervalTime) return true;
    if (m_bShowOnlyUsableItem != o.m_bShowOnlyUsableItem) return true;
    if (m_bHideOptionInfo != o.m_bHideOptionInfo) return true;
    if (m_bShowProbInfo != o.m_bShowProbInfo) return true;
    if (m_nNewCategoryId != o.m_nNewCategoryId) return true;
    if (!FUN_1406e8b50(m_aNewItems, o.m_aNewItems)) return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406DED80, CNpcShopData, operator!=, 1005, 0xB2ECF175);

// The shop-table loader of the server build (a constant TRUE in the client).
// @0x1406df180
int FUN_1406df180()
{
    return TRUE;
}

// @0x1406df190
int CNpcShopData::FUN_1406df190()
{
    return TRUE;
}
MS2_REPLACE_METHOD(0x1406DF190, CNpcShopData, FUN_1406df190, 11, 0x30025ED0);

// @0x1406df1b0
int CNpcShopData::FUN_1406df1b0()
{
    return TRUE;
}
MS2_REPLACE_METHOD(0x1406DF1B0, CNpcShopData, FUN_1406df1b0, 11, 0x30025ED0);

// @0x1406df1d0
int CNpcShopData::FUN_1406df1d0()
{
    return TRUE;
}
MS2_REPLACE_METHOD(0x1406DF1D0, CNpcShopData, FUN_1406df1d0, 11, 0x30025ED0);

void FUN_1406e35b0(const CString& strPath);
bool FUN_1406e5bc0(Unk_140165cf0* pElem);

// Loads Table/Server/shop_meratGroup.xml into the merat groups (once, and only with the merat premium table).
// MS2-FUNCTIONAL: the exe's string temporaries for the path differ.
// @0x1406df1f0
int FUN_1406df1f0()
{
    if (!s_meratGroups.IsEmpty())
        return 1;
    if (TSingleton<CMeratMarketPremium>::GetInstance() == 0)
        return 1;
    CString strPath;
    strPath = FUN_14071a5b0(CString("Table/Server"), CString("shop_meratGroup.xml"));
    FUN_1406e35b0(strPath);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return 0;
    CString strItem("meratItem");
    const CString& strItemTag = strItem;
    for (Unk_140165cf0* pShop = pRoot->FUN_140165cf0("shop"); pShop != 0; pShop = pShop->FUN_140168650("shop"))
    {
        if (!FUN_1406e5bc0(pShop))
            continue;
        int nGroupId = 0;
        FUN_1408731e0(pShop, "groupID", nGroupId);
        if (s_meratGroups.Lookup(nGroupId) != 0)
            continue;
        Unk_MeratItemArrayPtr spItems(Unk_SocketNew(0));
        s_meratGroups.SetAt(nGroupId, spItems);
        for (Unk_140165cf0* pItem = pShop->FUN_140165cf0(strItemTag); pItem != 0;
             pItem = pItem->FUN_140168650(strItemTag))
        {
            if (!FUN_1406e5bc0(pItem))
                continue;
            int nSn;
            FUN_1408731e0(pItem, "sn", nSn);
            MS2Ptr<CNpcShopMeratItemSvr> spMerat(new CNpcShopMeratItemSvr);
            if (spMerat == 0)
                continue;
            spMerat->m_nSn = nSn;
            spMerat->m_spProduct = 0;
            int nOrder = 0;
            FUN_1408731e0(pItem, "displayOrder", nOrder);
            spMerat->m_nDisplayOrder = nOrder < 2 ? 1 : nOrder;
            spItems->Add(spMerat);
        }
    }
    return 1;
}

int FUN_1406e0390(const CString& strPath, Unk_NpcShopMap& shops, bool bOverride);
int FUN_1406e0bd0(const CString& strPath, Unk_NpcShopMap& shops, bool bOverride);
int FUN_1406e1a50(const CString& strPath, Unk_NpcShopMap& shops);

// Loads the shop tables from Table/Server and Table/Server/New and logs the shops that differ (a table check).
// MS2-FUNCTIONAL: the exe's iterator and string temporaries differ; it always returns 0.
// @0x1406df690
int FUN_1406df690()
{
    Unk_NpcShopMap oldShops;
    Unk_NpcShopMap newShops;
    std::vector<CString> infoFiles;
    infoFiles.push_back(CString("shop_game_info.xml"));
    infoFiles.push_back(CString("shop_gacha_info.xml"));
    infoFiles.push_back(CString("shop_specialRandom_info.xml"));
    for (std::vector<CString>::iterator it = infoFiles.begin(); it != infoFiles.end(); it++)
    {
        CString strFile(*it);
        CString strOld = FUN_14071a5b0(CString("Table/Server"), strFile);
        FUN_1406e0390(strOld, oldShops, false);
        CString strNew = FUN_14071a5b0(CString("Table/Server/New"), strFile);
        FUN_1406e0390(strNew, newShops, true);
    }
    std::vector<CString> itemFiles;
    itemFiles.push_back(CString("shop_game.xml"));
    itemFiles.push_back(CString("shop_specialRandom.xml"));
    itemFiles.push_back(CString("shop_gacha.xml"));
    for (std::vector<CString>::iterator it = itemFiles.begin(); it != itemFiles.end(); it++)
    {
        CString strFile(*it);
        CString strOld = FUN_14071a5b0(CString("Table/Server"), strFile);
        FUN_1406e0bd0(strOld, oldShops, false);
        CString strNew = FUN_14071a5b0(CString("Table/Server/New"), strFile);
        FUN_1406e0bd0(strNew, newShops, true);
    }
    CString strNewFile("shop_specialRandom_new.xml");
    CString strOld = FUN_14071a5b0(CString("Table/Server"), strNewFile);
    FUN_1406e1a50(strOld, oldShops);
    CString strNew = FUN_14071a5b0(CString("Table/Server/New"), strNewFile);
    FUN_1406e1a50(strNew, newShops);
    if (oldShops.size() != newShops.size())
        return 0;
    std::set<int> oldIds;
    std::set<int> newIds;
    std::set<int> diffIds;
    for (std::pair<const unsigned, MS2Ptr<CNpcShopData> > entry : oldShops)
        oldIds.insert(entry.first);
    for (std::pair<const unsigned, MS2Ptr<CNpcShopData> > entry : newShops)
        newIds.insert(entry.first);
    std::set_difference(oldIds.begin(), oldIds.end(), newIds.begin(), newIds.end(),
                        std::inserter(diffIds, diffIds.end()));
    std::set_difference(newIds.begin(), newIds.end(), oldIds.begin(), oldIds.end(),
                        std::inserter(diffIds, diffIds.end()));
    if (diffIds.size() != 0)
    {
        CStringW strIds(L"");
        for (unsigned nId : diffIds)
            strIds = StringFormat(L"{0},{1}", strIds, nId);
        if (CLogString::GetInstance() != 0)
            FUN_1401859c0(CLogString::GetInstance(), 0xb, 0x13, strIds);
        return 0;
    }
    for (Unk_NpcShopMap::iterator it = oldShops.begin(); it != oldShops.end(); it++)
    {
        Unk_NpcShopMap::iterator other = newShops.find(it->first);
        CNpcShopData* pOther = other->second.get();
        if (*it->second.get() != *pOther && CLogString::GetInstance() != 0)
            FUN_1401859c0(CLogString::GetInstance(), 0xb, 0x13, StringFormat(L"Diff in ShopID : {0}", it->first));
    }
    return 0;
}

bool FUN_1406e5bf0(const CStringW& str, ATL::CAtlArray<Unk_DayTimeRange>& out);
bool FUN_1406e5ea0(const CStringW& str, std::set<int>& out);
MS2SvrPtr<CNpcShopBuyPeriod> FUN_1406e2fb0(Unk_140165cf0* pElem, unsigned nItemId, unsigned nShopId,
                                                  const CString& strPath, CStringW& strError);
Unk_ShopLifeRef FUN_1406e3310(Unk_140165cf0* pElem);

// Reads the <shop> rows of a shop info table (shop_*_info.xml) into shops.
// @0x1406e0390
int FUN_1406e0390(const CString& strPath, Unk_NpcShopMap& shops, bool bOverride)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return 0;
    int bFailed = 0;
    CStringW strErrors;
    std::vector<Unk_140165cf0*> elems;
    if (bOverride)
        FUN_14028faa0(pRoot, "shop", "shopID", elems);
    else
    {
        for (Unk_140165cf0* pShop = pRoot->FUN_140165cf0("shop"); pShop != 0; pShop = pShop->FUN_140168650("shop"))
        {
            if (!FUN_1406e5bc0(pShop))
                continue;
            elems.push_back(pShop);
        }
    }
    for (Unk_140165cf0* pShop : elems)
    {
        MS2Ptr<CNpcShopData> spShop(new CNpcShopData);
        int nResetEnable = 0;
        FUN_140873220(pShop, "shopID", spShop->m_nShopId);
        FUN_140873220(pShop, "shopVersion", spShop->m_nShopVersion);
        FUN_1408731e0(pShop, "categoryID", spShop->m_nCategoryId);
        FUN_1408731e0(pShop, "resetEnable", nResetEnable);
        FUN_1408731e0(pShop, "isOpenTokenPocket", spShop->m_nOpenTokenPocket);
        FUN_1408731e0(pShop, "meratItemGroupID", spShop->m_nMeratItemGroupId);
        FUN_1408730a0(pShop, "isOnlySell", spShop->m_bOnlySell);
        FUN_140873710(pShop, "useLuaPremiumItemRandomCount", spShop->m_nUseLuaPremiumItemRandomCount);
        FUN_140873710(pShop, "disableDisplayOrderSort", spShop->m_nDisableDisplayOrderSort);
        FUN_140873710(pShop, "isSmartShopItemList", spShop->m_nSmartShopItemList);
        XmlValue(pShop, "uiFrameType", spShop->m_eUIFrameType);
        FUN_1408736d0(pShop, "showOnlyUsableItem", spShop->m_bShowOnlyUsableItem);
        FUN_1408736d0(pShop, "hideOptionInfo", spShop->m_bHideOptionInfo);
        FUN_1408736d0(pShop, "showProbInfo", spShop->m_bShowProbInfo);
        FUN_1408733e0(pShop, "iconName", spShop->m_strIconName);
        spShop->m_nResetEnable = nResetEnable;
        spShop->m_bResetButtonHide = nResetEnable == 0;
        spShop->m_bResettable = nResetEnable == 1;
        if (nResetEnable != 0)
        {
            XmlValue(pShop, "resetPaymentType", spShop->m_eResetPaymentType);
            FUN_140873220(pShop, "resetPaymentItemID", spShop->m_nResetPaymentItemId);
            FUN_140873220(pShop, "resetPrice", spShop->m_nResetPrice);
            FUN_1408731e0(pShop, "resetListMax", spShop->m_nResetListMax);
            FUN_1408731e0(pShop, "resetListMin", spShop->m_nResetListMin);
            FUN_140873710(pShop, "useLuaResetPayment", spShop->m_nUseLuaResetPayment);
            FUN_140873220(pShop, "resetIntervalTime", spShop->m_nResetIntervalTime);
            XmlValue(pShop, "resetType", spShop->m_eResetType);
            FUN_1408736d0(pShop, "resetButtonHide", spShop->m_bResetButtonHide);
            FUN_140873600(pShop, "resetFixedTime", spShop->m_tmResetFixed);
            FUN_1408731e0(pShop, "resetByAccount", spShop->m_nResetByAccount);
        }
        if (shops.find(spShop->m_nShopId) != shops.end())
            shops[spShop->m_nShopId] = spShop;
        else
            shops.insert(std::make_pair(spShop->m_nShopId, spShop));
    }
    if (bFailed == 1)
    {
        CStringW strMessage = StringFormat(L"error File: {0}\r\n[{1}]\r\n", strPath, strErrors);
        FUN_1402804e0(CLogString::GetInstance(), 0, 0, 0x2d, strMessage);
        return 0;
    }
    return 1;
}

// Reads the <item> rows of a shop item table (shop_game.xml, ...) into the shops read before.
// MS2-FUNCTIONAL: written from the decompile and v2525; the exe's temporaries differ.
// @0x1406e0bd0
int FUN_1406e0bd0(const CString& strPath, Unk_NpcShopMap& shops, bool bOverride)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return 0;
    int bFailed = 0;
    CStringW strErrors;
    for (Unk_140165cf0* pShop = pRoot->FUN_140165cf0("shop"); pShop != 0; pShop = pShop->FUN_140168650("shop"))
    {
        unsigned nShopId = 0;
        FUN_140873220(pShop, "shopID", nShopId);
        if (nShopId == 0)
            continue;
        MS2Ptr<CNpcShopData> spShop(0);
        if (Unk_LockGuard guard = s_npcShopLock)
        {
        }
        else
        {
            Unk_NpcShopMap::iterator it = shops.find(nShopId);
            if (it != shops.end())
                spShop = it->second;
        }
        if (spShop == 0)
            continue;
        std::vector<Unk_140165cf0*> elems;
        if (bOverride)
            FUN_14028faa0(pShop, "item", "sn", elems);
        else
        {
            for (Unk_140165cf0* pItem = pShop->FUN_140165cf0("item"); pItem != 0; pItem = pItem->FUN_140168650("item"))
            {
                if (!FUN_1406e5bc0(pItem))
                    continue;
                elems.push_back(pItem);
            }
        }
        for (Unk_140165cf0* pItem : elems)
        {
            MS2Ptr<CNpcShopItem> spItem(new CNpcShopItem);
            FUN_140873220(pItem, "sn", spItem->m_nSn);
            FUN_140873220(pItem, "id", spItem->m_nItemId);
            XmlValue(pItem, "paymentType", spItem->m_ePaymentType);
            CString strPayment;
            FUN_1408733e0(pItem, "paymentItemID", strPayment);
            {
                std::vector<CString> parts;
                FUN_140275080(strPayment, parts, ":");
                if (parts.size() > 0)
                    spItem->m_nPaymentItemId = FUN_1407181d0(parts[0]);
                if (parts.size() > 1)
                    spItem->m_nPaymentItemSub = FUN_140557640(FUN_140281980(), parts[1]);
            }
            FUN_140873ad0(pItem, "paymentIconTag", spItem->m_strPaymentIconTag);
            FUN_140873220(pItem, "price", spItem->m_nPrice);
            FUN_140873220(pItem, "OriginalPrice", spItem->m_nOriginalPrice);
            FUN_140873220(pItem, "prob", spItem->m_nProb);
            FUN_140873220(pItem, "grade", spItem->m_nGrade);
            FUN_140873220(pItem, "sellCount", spItem->m_nSellCount);
            FUN_140873220(pItem, "requireGuildTrophy", spItem->m_nRequireGuildTrophy);
            FUN_140873710(pItem, "premiumItem", spItem->m_nPremiumItem);
            FUN_1408736d0(pItem, "checkGameEvent", spItem->m_bCheckGameEvent);
            FUN_140873220(pItem, "sellUnit", spItem->m_nSellUnit);
            FUN_14035bc20(pItem, "requireAlliance", &spItem->m_nRequireAlliance);
            FUN_1408731e0(pItem, "requireAllianceGrade", (int&)spItem->m_nRequireAllianceGrade);
            XmlValue(pItem, "frameType", spItem->m_eFrameType);
            XmlValue(pItem, "saleTag", spItem->m_eSaleTag);
            FUN_1408736d0(pItem, "wearForPreview", spItem->m_bWearForPreview);
            unsigned* pTotal = &spShop->m_nTotalProb;
            *pTotal += spItem->m_nProb;
            spShop->m_bResettable = spShop->m_bResettable || spItem->m_nSellCount > 0;
            {
                CString strValue;
                ATL::CAtlArray<unsigned> parts;
                FUN_1408733e0(pItem, "requireAchieve", strValue);
                FUN_140177e10(strValue, parts, ",");
                if (parts.GetCount() == 2)
                {
                    spItem->m_nRequireAchieveId = parts[0];
                    spItem->m_nRequireAchieveGrade = parts[1];
                }
            }
            {
                CString strValue;
                ATL::CAtlArray<unsigned> parts;
                FUN_1408733e0(pItem, "requireChampionshipInfo", strValue);
                FUN_140177de0(strValue, parts, ",");
                if (parts.GetCount() == 2)
                {
                    spItem->m_nRequireChampionship = parts[0];
                    spItem->m_nRequireChampionshipRank = parts[1];
                }
            }
            {
                CString strValue;
                ATL::CAtlArray<CStringW> parts;
                FUN_1408733e0(pItem, "requireGuildNpc", strValue);
                FUN_14015f080(strValue, parts, ",");
                if (parts.GetCount() == 2)
                {
                    spItem->m_nRequireGuildNpcType = FUN_14021a030(parts[0]);
                    spItem->m_nRequireGuildNpcLevel = FUN_1407181a0(parts[1]);
                }
            }
            CStringW strError;
            spItem->m_spPeriod = FUN_1406e2fb0(pItem, spItem->m_nItemId, nShopId, strPath, strError);
            if (!strError.IsEmpty())
            {
#ifdef __clang__
                strErrors += FUN_1401d0160(L"\r\n", strError);
#else
                strErrors += L"\r\n" + strError;
#endif
                bFailed = 1;
            }
            Unk_ShopLifeRef spLife = FUN_1406e3310(pItem);
            if (spLife != 0)
                spItem->m_spLife = spLife;
            spItem->m_strCategory = FUN_14015f710(pItem, "category", CString(""));
            if (spItem->m_eFrameType == 0)
                spItem->m_eFrameType = (eItemFrameType)(spItem->m_nPremiumItem == 1 ? 2 : 1);
            if (!spItem->m_bCheckGameEvent)
            {
                int nIndex = (int)spShop->m_aItems.Add(spItem);
                if (spItem->m_nPremiumItem != 0)
                    spShop->m_premiumPicker.Register(spItem->m_nProb, nIndex);
                else
                    spShop->m_normalPicker.Register(spItem->m_nProb, nIndex);
            }
            else
                spShop->m_aEventItems.Add(spItem);
        }
    }
    if (bFailed == 1)
    {
        CStringW strMessage = StringFormat(L"error File: {0}\r\n[{1}]\r\n", strPath, strErrors);
        FUN_1402804e0(CLogString::GetInstance(), 0, 0, 0x2d, strMessage);
        return 0;
    }
    return 1;
}

// Reads shop_specialRandom_new.xml (the "new" items) into the shops read before.
// MS2-FUNCTIONAL: written from the decompile and v2525; the exe's temporaries differ.
// @0x1406e1a50
int FUN_1406e1a50(const CString& strPath, Unk_NpcShopMap& shops)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return 0;
    int bFailed = 0;
    CStringW strErrors;
    for (Unk_140165cf0* pShop = pRoot->FUN_140165cf0("shop"); pShop != 0; pShop = pShop->FUN_140168650("shop"))
    {
        unsigned nShopId = 0;
        FUN_140873220(pShop, "shopID", nShopId);
        if (nShopId == 0)
            continue;
        MS2Ptr<CNpcShopData> spShop(0);
        if (Unk_LockGuard guard = s_npcShopLock)
        {
        }
        else
        {
            Unk_NpcShopMap::iterator it = shops.find(nShopId);
            if (it != shops.end())
                spShop = it->second;
        }
        if (spShop == 0)
            continue;
        FUN_1408731e0(pShop, "categoryID", spShop->m_nNewCategoryId);
        for (Unk_140165cf0* pItem = pShop->FUN_140165cf0("item"); pItem != 0; pItem = pItem->FUN_140168650("item"))
        {
            if (!FUN_1406e5bc0(pItem))
                continue;
            unsigned nItemId = 0;
            FUN_140873220(pItem, "id", nItemId);
            if (nItemId == 0 || FUN_14053f870(nItemId) == 0)
                continue;
            MS2Ptr<CNpcShopItemNew> spItem(new CNpcShopItemNew);
            spItem->m_nItemId = nItemId;
            FUN_14015f500(pItem, "grade", &spItem->m_nRarity);
            FUN_1408736d0(pItem, "premiumItem", spItem->m_bFlag);
            XmlValue(pItem, "frameType", (eItemFrameType&)spItem->m_nProductType);
            {
                CStringW strError;
                spItem->m_spPeriod = FUN_1406e2fb0(pItem, nItemId, nShopId, strPath, strError);
                if (!strError.IsEmpty())
                {
#ifdef __clang__
                    strErrors += FUN_1401d0160(L"\r\n", strError);
#else
                    strErrors += L"\r\n" + strError;
#endif
                    bFailed = 1;
                }
                spItem->m_strName = FUN_14015f710(pItem, "category", CString(""));
                if (spItem->m_nProductType == 0)
                    spItem->m_nProductType = spItem->m_bFlag == true ? 2 : 1;
            }
            spShop->FUN_1406e2bc0(spItem);
        }
    }
    if (bFailed == 1)
    {
        CStringW strMessage = StringFormat(L"error File: {0}\r\n[{1}]\r\n", strPath, strErrors);
        FUN_1402804e0(CLogString::GetInstance(), 0, 0, 0x2d, strMessage);
        return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: written from the decompile and v2525; the exe's set temporaries differ.
// @0x1406e21b0
int FUN_1406e21b0(const ATL::CAtlArray<MS2Ptr<CNpcShopItem> >& a, const ATL::CAtlArray<MS2Ptr<CNpcShopItem> >& b)
{
    size_t nCountA = a.GetCount();
    size_t nCountB = b.GetCount();
    if (nCountA != nCountB)
        return FALSE;
    std::set<int> sns;
    for (size_t i = 0; i < nCountA; i++)
    {
        if (sns.find(a[i]->m_nSn) != sns.end())
            return FALSE;
        sns.insert(a[i]->m_nSn);
    }
    sns.clear();
    for (size_t i = 0; i < nCountA; i++)
    {
        if (sns.find(b[i]->m_nSn) != sns.end())
            return FALSE;
        sns.insert(b[i]->m_nSn);
    }
    for (size_t i = 0; i < nCountA; i++)
    {
        bool bFound = false;
        for (size_t j = 0; j < nCountB; j++)
        {
            const CNpcShopItem* pA = a[i];
            const CNpcShopItem* pB = b[j];
            if (pA->m_nSn == pB->m_nSn)
            {
                if (*pA != *pB)
                    return FALSE;
                bFound = true;
                break;
            }
        }
        if (!bFound)
            return FALSE;
    }
    return TRUE;
}

// The NPC shop by id.
// @0x1406e2550
MS2Ptr<CNpcShopData> FUN_1406e2550(unsigned nShopId)
{
    if (Unk_LockGuard guard = s_npcShopLock)
    {
    }
    else
    {
        MS2Ptr<CNpcShopData> spShop;
        s_npcShops.Lookup(nShopId, spShop);
        return spShop;
    }
}

// Checks a shop after reading (FALSE: strError says why).
// MS2-FUNCTIONAL: written from the decompile and v2525; the exe's temporaries differ.
// @0x1406e2600
int CNpcShopData::Read(CString& strError, Unk_140165cf0* pElem)
{
    if (m_nResetEnable == 0)
    {
        if (m_nMeratItemGroupId > 0 && s_meratGroups.Lookup(m_nMeratItemGroupId) == 0)
        {
            strError = (const wchar_t*)StringFormat(L"CNpcShopData::Read - error meratItemGroup shopID=({0})", m_nShopId);
            m_nMeratItemGroupId = 0;
        }
        if (pElem)
        {
            eShopResetType eResetType = (eShopResetType)0;
            XmlValue(pElem, "resetType", eResetType);
            if (eResetType != 0)
            {
                strError = (const wchar_t*)StringFormat(
                    L"CNpcShopData::Read - shopID=({0}) error 'resetEnable' 0 -> 1 (because 'resetType' is not 0)", m_nShopId);
                return 0;
            }
        }
        if (m_nResetByAccount != 0)
        {
            strError = (const wchar_t*)StringFormat(
                L"CNpcShopData::Read - shopID=({0}) error 'resetEnable' 0 -> 1 (because 'resetByAccount' is 1)", m_nShopId);
            return 0;
        }
    }
    else
    {
        if (m_nResetListMin < 1 || m_nResetListMax < m_nResetListMin || m_nResetListMax > 200)
        {
            const int nMax = 200;
            strError = (const wchar_t*)StringFormat(
                L"CNpcShopData::Read - error Range (resetListMin, resetListMax) shopID=({0}). resetListMin=({1}), "
                L"resetListMax=({2}), resetListMax <= {3}",
                m_nShopId, m_nResetListMin, m_nResetListMax, nMax);
            return 0;
        }
        if (m_eResetPaymentType == 1)
        {
            MS2Ptr<CItemData> spItem = FUN_14053f870(m_nResetPaymentItemId);
            if (!spItem)
            {
                strError = (const wchar_t*)StringFormat(
                    L"CNpcShopData::Read - shopID=({0}) error resetPayment item itemid=({1})", m_nShopId,
                    m_nResetPaymentItemId);
                return 0;
            }
            if (!spItem->FUN_14053d150())
            {
                strError = (const wchar_t*)StringFormat(
                    L"CNpcShopData::Read - shopID=({0}) error resetPayment item isn't Consumable itemid=({1})", m_nShopId,
                    m_nResetPaymentItemId);
                return 0;
            }
        }
        if (m_eResetType == 99 && !m_bResetButtonHide)
        {
            strError = (const wchar_t*)StringFormat(
                L"CNpcShopData::Read - shopID=({0}) error 'resetButtonHide' 0 -> 1 (because 'resetType' is {1})", m_nShopId,
                m_eResetType);
            return 0;
        }
        if (m_tmResetFixed.Get() > 0 && m_eResetType != 99)
        {
            eShopResetType eFixed = (eShopResetType)99;
            strError = (const wchar_t*)StringFormat(
                L"CNpcShopData::Read - shopID=({0}) error 'resetType' {1} -> {2} (because 'resetFixedTime' exists)",
                m_nShopId, m_eResetType, eFixed);
            return 0;
        }
    }
    return 1;
}

// @0x1406e2bc0
void CNpcShopData::FUN_1406e2bc0(MS2Ptr<CNpcShopItemNew> spItem)
{
    m_aNewItems.Add(spItem);
}

// The day's buy count limit of a shop (days 1..6).
// @0x1406e2c10
__int64 FUN_1406e2c10(unsigned nShopId, int nDay)
{
    __int64 nValue = 0;
    if (nDay < 1 || nDay > 6)
        nValue = 0;
    else
    {
        if (Unk_LockGuard guard = s_npcShopLock)
        {
        }
        else
        {
            Unk_ShopLimitArrayPtr spLimits(0);
            s_shopLimits.Lookup(nShopId, spLimits);
            if (spLimits != 0 && nDay < (int)spLimits->GetCount())
            {
                __int64 nIndex = nDay;
                nValue = (*spLimits)[nIndex];
            }
        }
    }
    return nValue;
}

// Raises the day's buy count limit of a shop (TRUE: raised).
// @0x1406e2d20
int FUN_1406e2d20(unsigned nShopId, int nDay, __int64 nValue)
{
    if (Unk_LockGuard guard = s_npcShopLock)
    {
    }
    else
    {
        Unk_ShopLimitArrayPtr spLimits(0);
        s_shopLimits.Lookup(nShopId, spLimits);
        if (spLimits == 0)
        {
            spLimits = Unk_SocketNew(0);
            s_shopLimits.SetAt(nShopId, spLimits);
            spLimits->SetCount(7);
            for (int i = 0; i < 7; i++)
            {
                __int64 nIndex = i;
                spLimits->SetAt(nIndex, 0);
            }
        }
        __int64 nIndex = nDay;
        if ((*spLimits)[nIndex] < nValue)
        {
            __int64 nIndex2 = nDay;
            spLimits->SetAt(nIndex2, nValue);
            return 1;
        }
    }
    return 0;
}

// The merat items of a merat group.
// @0x1406e2ee0
void FUN_1406e2ee0(int nGroupId, Unk_MeratItemArray& out)
{
    if (nGroupId == 0)
        return;
    if (Unk_LockGuard guard = s_npcShopLock)
    {
    }
    else
    {
        if (s_meratGroups.IsEmpty())
            return;
        Unk_MeratItemArrayPtr spItems(0);
        if (s_meratGroups.Lookup(nGroupId, spItems))
            out.Copy(*spItems);
    }
}

// The buy period of an <item> (null: the item has no period attributes).
// MS2-FUNCTIONAL: written from the decompile; the exe's temporaries differ.
// @0x1406e2fb0
MS2SvrPtr<CNpcShopBuyPeriod> FUN_1406e2fb0(Unk_140165cf0* pElem, unsigned nItemId, unsigned nShopId,
                                                  const CString& strPath, CStringW& strError)
{
    if (pElem == 0)
        return MS2SvrPtr<CNpcShopBuyPeriod>(0);
    MS2SvrPtr<CNpcShopBuyPeriod> spPeriod(0);
    CMsTime tmStart;
    CMsTime tmEnd;
    FUN_140873600(pElem, "startDate", tmStart);
    FUN_140873600(pElem, "endDate", tmEnd);
    bool bPeriod = false;
    if (tmStart.Get() > 0 || tmEnd.Get() > 0)
        bPeriod = true;
    CStringW strPartTime;
    FUN_140873420(pElem, "partTime", strPartTime);
    strPartTime.Trim();
    bPeriod = bPeriod || !strPartTime.IsEmpty();
    CStringW strDays;
    FUN_140873420(pElem, "dayOfWeek", strDays);
    strDays.Trim();
    bPeriod = bPeriod || !strDays.IsEmpty();
    if (bPeriod == true)
    {
        spPeriod = new CNpcShopBuyPeriod;
        if (!strPartTime.IsEmpty())
            FUN_1406e5bf0(strPartTime, spPeriod->m_aPartTimes);
        if (!strDays.IsEmpty())
            FUN_1406e5ea0(strDays, spPeriod->m_setDays);
        bool bOnlyVisibleInPeriod = false;
        FUN_1408730a0(pElem, "onlyVisibleInPeriod", bOnlyVisibleInPeriod);
        spPeriod->m_bVisible = bOnlyVisibleInPeriod == false;
        spPeriod->m_tmStart = tmStart;
        spPeriod->m_tmEnd = tmEnd;
        spPeriod->FUN_1406dc810();
    }
    return spPeriod;
}

// The item life of an <item> (null: none or invalid).
// @0x1406e3310
Unk_ShopLifeRef FUN_1406e3310(Unk_140165cf0* pElem)
{
    if (pElem == 0)
        return Unk_ShopLifeRef(0);
    Unk_ShopLifeRef spLife(new NpcShopItemLife);
    if (!spLife->FUN_14026ebc0(pElem))
        return Unk_ShopLifeRef(0);
    if (!spLife->FUN_14026f0f0())
        return Unk_ShopLifeRef(0);
    return spLife;
}

// Drops the NPC shop tables when a table file changed (or bForce) and reloads them (TRUE: a file changed).
// @0x1406e3460
bool FUN_1406e3460(bool bForce)
{
    bool bChanged = false;
    if (Unk_LockGuard guard = s_npcShopLock)
    {
    }
    else
    {
        size_t nCount = s_aNpcShopCaches.GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            MS2Ptr<CCacheData> spCache(s_aNpcShopCaches[i]);
            if (spCache == 0)
                continue;
            if (FUN_1401d1320(spCache.operator->()))
            {
                bChanged = true;
                break;
            }
        }
        if (bChanged || bForce)
        {
            s_aNpcShopCaches.RemoveAll();
            s_meratGroups.RemoveAll();
            s_shopLimits.RemoveAll();
            s_npcShops.RemoveAll();
            FUN_1406df180();
        }
    }
    return bChanged;
}

// Records a loaded NPC shop table file (for the change check).
// @0x1406e35b0
void FUN_1406e35b0(const CString& strPath)
{
    MS2Ptr<CCacheData> spCache(new CCacheData);
    if (spCache.get() != 0)
    {
        spCache->FUN_1401d1160(strPath);
        s_aNpcShopCaches.Add(spCache);
    }
}

// ---- CBeautyShopItem ----------------------------------------------------------------------------------------------

// @0x1406e3690
CBeautyShopItem::CBeautyShopItem()
    : m_nItemId(0), m_nWeight(0), m_nSaleTag(0), m_nRequireLevel(0), m_nAchieveId(0), m_nAchieveGrade(0)
{
    m_payment.FUN_1406dc580(0x10b);
}

// @0x1406e3740
void CBeautyShopItem::FUN_1406e3740(COutputStream& out)
{
    out.vfunc_o10_3(m_nItemId);
    out.vfunc_o10_1((unsigned char)m_nSaleTag);
    out.vfunc_o10_2(m_nRequireLevel);
    out.vfunc_o10_3(m_nAchieveId);
    out.vfunc_o10_1((unsigned char)m_nAchieveGrade);
    m_payment.FUN_1406dc230(out);
}
MS2_REPLACE_METHOD(0x1406E3740, CBeautyShopItem, FUN_1406e3740, 164, 0xDA590D35);

// @0x1406e37f0
void CBeautyShopItem::FUN_1406e37f0(CInPacket& in)
{
    m_nItemId = in.vfunc_o8_3();
    m_nSaleTag = in.vfunc_o8_1();
    m_nRequireLevel = in.vfunc_o8_2();
    m_nAchieveId = in.vfunc_o8_3();
    m_nAchieveGrade = in.vfunc_o8_1();
    m_payment.FUN_1406dc2c0(in);
}
MS2_REPLACE_METHOD(0x1406E37F0, CBeautyShopItem, FUN_1406e37f0, 258, 0x94AC2552);

bool FUN_1406e5ba0(int nPrice);

// Checks the price against the item's (FALSE: strError says why).
// MS2-FUNCTIONAL: written from the decompile; the exe's temporaries differ.
// @0x1406e3900
int CBeautyShopItem::FUN_1406e3900(CString& strError)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(m_nItemId);
    unsigned nShopPrice = (unsigned)FUN_1406e3bc0();
    if (!spItem)
    {
        strError = (const wchar_t*)StringFormat(L"CBeautyShopData::Read - error item id ({0})", m_nItemId);
        return 0;
    }
    __int64 nPrice = spItem->property.FUN_1405480f0(1);
    if (spItem->FUN_14053cbc0())
    {
        float fFactor = FUN_140302b10()->FUN_1404c1810(3, 1);
        nPrice = (__int64)((float)nPrice * fFactor);
    }
    if ((__int64)nShopPrice < nPrice)
    {
        ItemGradeKey eGrade = (ItemGradeKey)1;
        unsigned nPropertyPrice = (unsigned)nPrice;
        strError = (const wchar_t*)StringFormat(
            L"CBeautyShopData::Read - error item price. itemid=({0}). propery_price=({1}), shop_price={{2}), grade=({3})",
            m_nItemId, nPropertyPrice, nShopPrice, eGrade);
        return 0;
    }
    if (FUN_1406e5ba0(nShopPrice))
    {
        strError = (const wchar_t*)StringFormat(L"CBeautyShopData::Read - error item id ({0}), error price is #N/A",
                                                m_nItemId);
        return 0;
    }
    return 1;
}

// @0x1406e3bc0
__int64 CBeautyShopItem::FUN_1406e3bc0()
{
    return m_payment.FUN_1406dc4f0();
}
MS2_REPLACE_METHOD(0x1406E3BC0, CBeautyShopItem, FUN_1406e3bc0, 31, 0x069E603D);

// @0x1406e3bf0
ePaymentType CBeautyShopItem::FUN_1406e3bf0()
{
    return m_payment.FUN_1406dc510();
}
MS2_REPLACE_METHOD(0x1406E3BF0, CBeautyShopItem, FUN_1406e3bf0, 31, 0x935EF1AD);

// @0x1406e3c20
unsigned CBeautyShopItem::FUN_1406e3c20()
{
    return m_payment.FUN_1406dc4d0();
}
MS2_REPLACE_METHOD(0x1406E3C20, CBeautyShopItem, FUN_1406e3c20, 31, 0xE77E2D9C);

// ---- CBeautyShopDataCommon ----------------------------------------------------------------------------------------

// @0x1406e3c50
CBeautyShopDataCommon::CBeautyShopDataCommon()
    : m_nShopId(0), m_nCategory(0), m_nDisplayCouponId(0), m_b24(false), m_nReturnCouponId(0), m_n2c(0), m_b30(false)
{
    m_payment.FUN_1406dc580(0x10b);
    m_recolorPayment.FUN_1406dc580(0x10b);
}

// @0x1406e3d30
void CBeautyShopDataCommon::FUN_1406e3d30()
{
    m_nShopId = 0;
    m_nCategory = 0;
    m_b24 = false;
    m_nReturnCouponId = 0;
    m_nDisplayCouponId = 0;
    m_n2c = 0;
    m_b30 = false;
    m_payment.FUN_1406dc1e0();
    m_recolorPayment.FUN_1406dc1e0();
}
MS2_REPLACE_METHOD(0x1406E3D30, CBeautyShopDataCommon, FUN_1406e3d30, 126, 0xD5516E72);

// @0x1406e3dc0
TShopPaymentAttr& CBeautyShopDataCommon::FUN_1406e3dc0()
{
    return m_payment;
}
MS2_REPLACE_METHOD(0x1406E3DC0, CBeautyShopDataCommon, FUN_1406e3dc0, 15, 0x676E38F1);

// @0x1406e3de0
TShopPaymentAttr& CBeautyShopDataCommon::FUN_1406e3de0()
{
    return m_recolorPayment;
}
MS2_REPLACE_METHOD(0x1406E3DE0, CBeautyShopDataCommon, FUN_1406e3de0, 15, 0x37F83669);

// @0x1406e3e00
const TShopPaymentAttr& CBeautyShopDataCommon::FUN_1406e3e00() const
{
    return m_payment;
}
MS2_REPLACE_METHOD(0x1406E3E00, CBeautyShopDataCommon, FUN_1406e3e00, 15, 0x676E38F1);

// @0x1406e3e20
const TShopPaymentAttr& CBeautyShopDataCommon::FUN_1406e3e20() const
{
    return m_recolorPayment;
}
MS2_REPLACE_METHOD(0x1406E3E20, CBeautyShopDataCommon, FUN_1406e3e20, 15, 0x37F83669);

// ---- CBeautyShopItemGroup(s) --------------------------------------------------------------------------------------

// @0x1406e3e40
CBeautyShopItemGroup::CBeautyShopItemGroup(__int64 nKey, const CString& strName, unsigned nValue)
    : m_nKey(nKey), m_strName(strName), m_nValue(nValue)
{
    memset(m_aWeight, 0, sizeof(m_aWeight));
}

// @0x1406e3f10
ATL::CAtlArray<MS2Ptr<CBeautyShopItem> >& CBeautyShopItemGroup::FUN_1406e3f10(int nGender)
{
    static ATL::CAtlArray<MS2Ptr<CBeautyShopItem> > empty;
    if (nGender < 0 || nGender > 1)
    {
        MS2_ASSERT_AT(0x7e0, FALSE);
        return empty;
    }
    return m_aItems[nGender];
}

// @0x1406e3fe0
unsigned CBeautyShopItemGroup::FUN_1406e3fe0(int nGender)
{
    if (nGender < 0 || nGender > 1)
    {
        MS2_ASSERT_AT(0x7eb, FALSE);
        return 0;
    }
    return m_aWeight[nGender];
}
MS2_REPLACE_METHOD(0x1406E3FE0, CBeautyShopItemGroup, FUN_1406e3fe0, 84, 0x997D3341);

// @0x1406e4040
__int64 CBeautyShopItemGroup::FUN_1406e4040()
{
    return m_nKey;
}
MS2_REPLACE_METHOD(0x1406E4040, CBeautyShopItemGroup, FUN_1406e4040, 15, 0xBBB219C9);

// @0x1406e4060
const CString& CBeautyShopItemGroup::FUN_1406e4060()
{
    return m_strName;
}
MS2_REPLACE_METHOD(0x1406E4060, CBeautyShopItemGroup, FUN_1406e4060, 15, 0x5731F599);

// @0x1406e4080
unsigned CBeautyShopItemGroup::FUN_1406e4080()
{
    return m_nValue;
}
MS2_REPLACE_METHOD(0x1406E4080, CBeautyShopItemGroup, FUN_1406e4080, 14, 0xD26D6807);

// @0x1406e40a0
void CBeautyShopItemGroup::FUN_1406e40a0(MS2Ptr<CBeautyShopItem> spItem, int nGender)
{
    if (nGender < 0 || nGender > 1)
    {
        MS2_ASSERT_AT(0x805, FALSE);
        return;
    }
    m_aItems[nGender].Add(spItem);
    m_aWeight[nGender] += spItem->m_nWeight;
}

__int64 FUN_1406e4420(const CMsTime& tm);

// @0x1406e4170
MS2Ptr<CBeautyShopItemGroup> CBeautyShopItemGroups::FUN_1406e4170() const
{
    CMsTime tmNow(GetServerTime());
    __int64 nKey = FUN_1406e4420(tmNow);
    std::map<__int64, MS2Ptr<CBeautyShopItemGroup> >::const_iterator it = m_groups.upper_bound(nKey);
    if (it == m_groups.begin())
        return MS2Ptr<CBeautyShopItemGroup>(0);
    it--;
    return it->second;
}

// @0x1406e4260
void CBeautyShopItemGroups::FUN_1406e4260(std::vector<MS2Ptr<CBeautyShopItemGroup> >& out) const
{
    CMsTime tmNow(GetServerTime());
    __int64 nKey = FUN_1406e4420(tmNow);
    std::map<__int64, MS2Ptr<CBeautyShopItemGroup> >::const_iterator it = m_groups.upper_bound(nKey);
    if (it == m_groups.begin())
        return;
    it--;
    for (; it != m_groups.end(); it++)
        out.push_back(it->second);
}

// @0x1406e4350
bool CBeautyShopItemGroups::FUN_1406e4350(MS2Ptr<CBeautyShopItemGroup> spGroup)
{
    __int64 nKey = spGroup->FUN_1406e4040();
    if (m_groups.find(nKey) != m_groups.end())
        return false;
    m_groups[nKey] = spGroup;
    return true;
}

// yyyymmddhhmmss of a time (the item group keys).
// @0x1406e4420
__int64 FUN_1406e4420(const CMsTime& tm)
{
    int nYear = tm.GetYear();
    int nMonth = tm.GetMonth();
    int nDay = tm.GetDay();
    int nHour = tm.GetHour();
    int nMinute = tm.GetMinute();
    int nSecond = tm.GetSecond();
    return (__int64)nYear * 10000000000 + (__int64)nMonth * 100000000 + (__int64)nDay * 1000000 + (__int64)nHour * 10000 +
           (__int64)nMinute * 100 + (__int64)nSecond;
}

// ---- CBeautyShopData ----------------------------------------------------------------------------------------------

// @0x1406e4500
CBeautyShopData::CBeautyShopData()
{
    m_spGroups.AssignRaw(new CBeautyShopItemGroups);
}

// Checks the coupons after reading (FALSE: strError says why).
// @0x1406e45b0
int CBeautyShopData::Read(CString& strError)
{
    if (m_nDisplayCouponId != 0)
    {
        MS2Ptr<CItemData> spItem = FUN_14053f870(m_nDisplayCouponId);
        if (!spItem)
        {
            strError = (const wchar_t*)StringFormat(
                L"CBeautyShopData::Read - error shop id ({0}), m_displayCouponID ({1})", m_nShopId, m_nDisplayCouponId);
            return 0;
        }
    }
    if (m_nReturnCouponId != 0)
    {
        MS2Ptr<CItemData> spItem = FUN_14053f870(m_nDisplayCouponId);   // sic: the display coupon again
        if (!spItem)
        {
            strError = (const wchar_t*)StringFormat(
                L"CBeautyShopData::Read - error shop id ({0}), m_returnCouponID ({1})", m_nShopId, m_nReturnCouponId);
            return 0;
        }
    }
    return 1;
}

// @0x1406e4770
void CBeautyShopData::FUN_1406e4770(COutputStream& out)
{
    out.vfunc_o10_3(m_nShopId);
    out.vfunc_o10_3(m_nCategory);
    out.vfunc_o10_3(m_nDisplayCouponId);
    out.vfunc_o10_1(m_b24);
    out.vfunc_o10_3(m_nReturnCouponId);
    out.vfunc_o10_3(m_n2c);
    out.vfunc_o10_0(m_b30);
    FUN_1406e3dc0().FUN_1406dc230(out);
    FUN_1406e3de0().FUN_1406dc230(out);
}
MS2_REPLACE_METHOD(0x1406E4770, CBeautyShopData, FUN_1406e4770, 234, 0x72386D0D);

// The product of the group on sale now.
// @0x1406e4860
MS2Ptr<CBeautyShopItem> CBeautyShopData::FUN_1406e4860(int nItemId, unsigned nGender)
{
    if (nGender < 0 || nGender >= 2)
        return MS2Ptr<CBeautyShopItem>(0);
    Unk_BeautyGroupRef spGroup = GetShopItemGroup();
    if (spGroup == 0)
        return MS2Ptr<CBeautyShopItem>(0);
    ATL::CAtlArray<MS2Ptr<CBeautyShopItem> >& items = spGroup->FUN_1406e3f10(nGender);
    if (items.IsEmpty())
        return MS2Ptr<CBeautyShopItem>(0);
    for (size_t i = 0; i < items.GetCount(); i++)
    {
        MS2Ptr<CBeautyShopItem> spItem(items[i]);
        if (spItem == 0 || spItem->m_nWeight == 0)
            continue;
        if (spItem->m_nItemId == nItemId)
            return spItem;
    }
    return MS2Ptr<CBeautyShopItem>(0);
}

// @0x1406e4a70
void CBeautyShopData::AddShopItemGroup(MS2Ptr<CBeautyShopItemGroup> spGroup)
{
    bool bAdded = m_spGroups->FUN_1406e4350(spGroup);
    if (!bAdded)
    {
        __int64 nKey = spGroup->FUN_1406e4040();
        static_cast<Unk_NpcShopLog*>(CLogString::GetInstance())->Log(0, 0, 0x2d, L"{0} failed. shopid={1}, itemGroupKey={2}", L"CBeautyShopData::AddShopItemGroup",
                          m_nShopId, nKey);
    }
}

// @0x1406e4b80
Unk_BeautyGroupRef CBeautyShopData::GetShopItemGroup()
{
    Unk_BeautyGroupRef spGroup = m_spGroups->FUN_1406e4170();
    if (spGroup == 0)
    {
        static_cast<Unk_NpcShopLog*>(CLogString::GetInstance())->Log(0, 0, 0x2d, L"{0} failed. pShopItemGroup is null. There are no products on sale. shopid={1}",
                          L"CBeautyShopData::GetShopItemGroup", m_nShopId);
        MS2_ASSERT_AT(0x998, FALSE);
        return Unk_BeautyGroupRef(0);
    }
    return spGroup;
}

// @0x1406e4ce0
std::vector<MS2Ptr<CBeautyShopItemGroup> >* CBeautyShopData::GetShopItemGroupList(
    std::vector<MS2Ptr<CBeautyShopItemGroup> >& out)
{
    m_spGroups->FUN_1406e4260(out);
    if (out.size() == 0)
    {
        static_cast<Unk_NpcShopLog*>(CLogString::GetInstance())->Log(0, 0, 0x2d, L"{0} failed. pShopItemGroup is null. There are no products on sale. shopid={1}",
                          L"CBeautyShopData::GetShopItemGroupList", m_nShopId);
        MS2_ASSERT_AT(0x9a6, FALSE);
        return 0;
    }
    return &out;
}

// The beauty shop table reload of the server build (a constant TRUE in the client).
// @0x1406e4db0
int FUN_1406e4db0(const CString& strPath)
{
    return TRUE;
}

// Reloads the beauty shop tables whose file changed (TRUE: one changed).
// @0x1406e4dd0
bool FUN_1406e4dd0()
{
    bool bChanged = false;
    if (Unk_LockGuard guard = s_beautyShopLock)
    {
    }
    else if (!s_aBeautyShopCaches.IsEmpty())
    {
        for (size_t i = 0; i < s_aBeautyShopCaches.GetCount(); i++)
        {
            MS2Ptr<CCacheData> spCache(s_aBeautyShopCaches[i]);
            if (spCache == 0 || !FUN_1401d1320(spCache.operator->()))
                continue;
            FUN_1406e4db0(*spCache->FUN_1401d1140());
            bChanged = true;
        }
    }
    return bChanged;
}

// The beauty shop by id.
// @0x1406e4ef0
MS2Ptr<CBeautyShopData> FUN_1406e4ef0(unsigned nShopId)
{
    if (Unk_LockGuard guard = s_beautyShopLock)
    {
    }
    else
    {
        MS2Ptr<CBeautyShopData> spShop;
        s_beautyShops.Lookup(nShopId, spShop);
        return spShop;
    }
}

// Reads one beauty shop <item> into its item group (both genders when the item has no gender limit).
// MS2-FUNCTIONAL: written from the decompile and v2525; the exe's temporaries differ.
// @0x1406e4fa0
bool FUN_1406e4fa0(Unk_140165cf0* pElem, unsigned nShopId, CBeautyShopItemGroup* pGroup)
{
    if (FUN_1406e5bc0(pElem))
    {
        MS2Ptr<CBeautyShopItem> spItem(new CBeautyShopItem);
        FUN_140873220(pElem, "id", spItem->m_nItemId);
        spItem->m_payment.FUN_1406dc3c0(pElem, CString("paymentType"), CString("paymentItemID"), CString("paymentIconTag"),
                                        CString("price"));
        FUN_140873220(pElem, "weight", spItem->m_nWeight);
        FUN_1408731e0(pElem, "saleTag", spItem->m_nSaleTag);
        FUN_1408731a0(pElem, "requireLevel", spItem->m_nRequireLevel);
        FUN_140873220(pElem, "achieveID", spItem->m_nAchieveId);
        FUN_1408731e0(pElem, "achieveGrade", spItem->m_nAchieveGrade);
        MS2Ptr<CItemData> spData = FUN_14053f870(spItem->m_nItemId);
        if (!spData)
        {
            int nGender = spData->limit.genderLimit < 2 ? spData->limit.genderLimit : 2;
            int nIndex = nGender;
            if (nGender == 2)
            {
                pGroup->FUN_1406e40a0(spItem, 1);
                pGroup->FUN_1406e40a0(spItem, 0);
            }
            else
                pGroup->FUN_1406e40a0(spItem, nIndex);
        }
        else
            static_cast<Unk_NpcShopLog*>(CLogString::GetInstance())->LogWarn(0, 0, 0x7c, L"CBeautyShopData BANNED item={0} shop={1}", spItem->m_nItemId, nShopId);
    }
    return true;
}

// @0x1406e53e0
CBeautyShopDataCli::CBeautyShopDataCli()
{
}

// @0x1406e5420
void CBeautyShopDataCli::FUN_1406e5420(CInPacket& in)
{
    m_nShopId = in.vfunc_o8_3();
    m_nCategory = in.vfunc_o8_3();
    m_nDisplayCouponId = in.vfunc_o8_3();
    m_b24 = in.vfunc_o8_1() == 1 ? true : false;
    m_nReturnCouponId = in.vfunc_o8_3();
    m_n2c = in.vfunc_o8_3();
    m_b30 = in.vfunc_o8_0();
    FUN_1406e3dc0().FUN_1406dc2c0(in);
    FUN_1406e3de0().FUN_1406dc2c0(in);
}
MS2_REPLACE_METHOD(0x1406E5420, CBeautyShopDataCli, FUN_1406e5420, 383, 0x3CF7E27E);

bool FUN_1406e56d0(const CString& strPath);

// Loads Table/shop_beautyCoupon.xml.
// @0x1406e55b0
__int64 FUN_1406e55b0()
{
    if (Unk_LockGuard guard = s_couponLock)
    {
    }
    else
    {
        CString strPath;
        strPath = FUN_14071a5b0(CString("Table"), CString("shop_beautyCoupon.xml"));
        if (!FUN_1406e56d0(strPath))
            return 0;
    }
    return 1;
}

// Reads the beauty coupon table: the coupon items per shop.
// @0x1406e56d0
bool FUN_1406e56d0(const CString& strPath)
{
    if (s_spCouponCache == 0)
        s_spCouponCache.AssignRaw(new CCacheData);
    if (s_spCouponCache != 0)
        s_spCouponCache->FUN_1401d1160(strPath);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return false;
    CStringW strErrors;
    for (Unk_140165cf0* pShop = pRoot->FUN_140165cf0("shop"); pShop != 0; pShop = pShop->FUN_140168650("shop"))
    {
        if (!FUN_1406e5bc0(pShop))
            continue;
        unsigned nShopId = 0;
        FUN_140873220(pShop, "shopID", nShopId);
        if (nShopId == 0)
            continue;
        Unk_CouponItemArrayPtr spCoupons(0);
        spCoupons = Unk_SocketNew(0);
        for (Unk_140165cf0* pItem = pShop->FUN_140165cf0("item"); pItem != 0; pItem = pItem->FUN_140168650("item"))
        {
            if (!FUN_1406e5bc0(pItem))
                continue;
            unsigned nItemId = 0;
            FUN_140873220(pItem, "id", nItemId);
            if (nItemId == 0)
                continue;
            MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
            if (spItem == 0)
                continue;
            spCoupons->Add(spItem);
        }
        s_coupons.SetAt(nShopId, spCoupons);
    }
    return true;
}

// Reloads the coupon table when its file changed (TRUE: it changed).
// @0x1406e5a40
bool FUN_1406e5a40()
{
    bool bChanged = false;
    if (Unk_LockGuard guard = s_couponLock)
    {
    }
    else if (s_spCouponCache != 0)
    {
        if (FUN_1401d1320(s_spCouponCache.operator->()))
        {
            FUN_1406e56d0(*s_spCouponCache->FUN_1401d1140());
            bChanged = true;
        }
    }
    return bChanged;
}

// The coupon items of a beauty shop.
// @0x1406e5af0
Unk_CouponItemArrayPtr FUN_1406e5af0(unsigned nShopId)
{
    if (Unk_LockGuard guard = s_couponLock)
    {
    }
    else
    {
        Unk_CouponItemArrayPtr spCoupons(0);
        s_coupons.Lookup(nShopId, spCoupons);
        return spCoupons;
    }
}

// The #N/A price of the table export (0x800a07df).
// @0x1406e5ba0
bool FUN_1406e5ba0(int nPrice)
{
    return nPrice == (int)0x800a07df;
}

// @0x1406e5bc0
bool FUN_1406e5bc0(Unk_140165cf0* pElem)
{
    if (pElem == 0)
        return false;
    return FUN_14028f710(pElem);
}

// Parses a partTime list ("hh:mm:ss-hh:mm:ss,...").
// MS2-FUNCTIONAL: written from the decompile; the exe's temporaries differ.
// @0x1406e5bf0
bool FUN_1406e5bf0(const CStringW& str, ATL::CAtlArray<Unk_DayTimeRange>& out)
{
    out.RemoveAll();
    if (!str.IsEmpty())
    {
        Unk_DayTime midnight(0, 0, 0);
        ATL::CAtlArray<CStringW> ranges;
        FUN_14025a680(str, ranges, L",");
        for (int i = 0; i < (int)ranges.GetCount(); i++)
        {
            const CStringW& strRange = ranges[i];
            ATL::CAtlArray<CStringW> bounds;
            FUN_14025a680(strRange, bounds, L"-");
            if (bounds.GetCount() != 2)
            {
                MS2_ASSERT_AT(0x49, FALSE);
                return false;
            }
            const CStringW& strStart = bounds[0];
            const CStringW& strEnd = bounds[1];
            Unk_DayTime start;
            Unk_DayTime end;
            if (!start.Parse(strStart) || !end.Parse(strEnd))
            {
                MS2_ASSERT_AT(0x55, FALSE);
                return false;
            }
            if (start > end || start < midnight)
            {
                MS2_ASSERT_AT(0x5b, FALSE);
                return false;
            }
            out.Add(Unk_DayTimeRange(start, end));
        }
    }
    return true;
}

// Parses a dayOfWeek list ("1,2,...", 1..7, no repeats).
// @0x1406e5ea0
bool FUN_1406e5ea0(const CStringW& str, std::set<int>& out)
{
    out.clear();
    if (str.IsEmpty())
        return true;
    ATL::CAtlArray<int> days;
    FUN_1401d9a30(str, days, L",");
    for (int i = 0; i < (int)days.GetCount(); i++)
    {
        int nDay = days[i];
        if (nDay < 1 || nDay > 7)
        {
            MS2_ASSERT_AT(0x75, FALSE);
            return false;
        }
        if (out.find(nDay) != out.end())
        {
            MS2_ASSERT_AT(0x7b, FALSE);
            return false;
        }
        out.insert(nDay);
    }
    return true;
}

// @0x1406e8b50
bool FUN_1406e8b50(const ATL::CAtlArray<MS2Ptr<CNpcShopItemNew> >& a,
                          const ATL::CAtlArray<MS2Ptr<CNpcShopItemNew> >& b)
{
    size_t nCount = a.GetCount();
    if (nCount != b.GetCount())
        return false;
    for (unsigned i = 0; i < a.GetCount(); i++)
    {
        const CNpcShopItemNew* pB = b[i];
        if (*a[i] != *pB)
            return false;
    }
    return true;
}

// ---- CNpcShopMeratItemBase / CNpcShopMeratItemSvr -----------------------------------------------------------------

// The exe's are inline COMDATs (the header only declares them: CMeratMarketPremiumProduct is incomplete there).
// @0x1406eeb50
CNpcShopMeratItemBase::CNpcShopMeratItemBase() : m_nDisplayOrder(1), m_spProduct(0)
{
}

// @0x1406ef7e0
CNpcShopMeratItemBase::~CNpcShopMeratItemBase()
{
    m_spProduct = 0;
}

// @0x1406f1840
void CNpcShopMeratItemBase::vfunc_2(CInPacket* pIn)
{
    m_spProduct.AssignRaw(new CMeratMarketPremiumProduct);
    if (m_spProduct == 0)
        return;
    m_spProduct->ReadBrief(*pIn);
    m_nDisplayOrder = pIn->vfunc_o8_1();
}

// @0x1406f1930
void CNpcShopMeratItemSvr::vfunc_2(CInPacket* pIn)
{
}

// @0x1406f1980
void CNpcShopMeratItemBase::vfunc_1(COutputStream* pOut)
{
    if (m_spProduct == 0)
        return;
    m_spProduct->WriteBrief(*pOut);
    pOut->vfunc_o10_1((unsigned char)m_nDisplayOrder);
}

// @0x1406f1a00
void CNpcShopMeratItemSvr::vfunc_1(COutputStream* pOut)
{
    CNpcShopMeratItemBase::vfunc_1(pOut);
    pOut->vfunc_o10_3(m_34);
    pOut->vfunc_o10_3(m_38);
}

// @0x1406f2470
unsigned CNpcShopMeratItemBase::vfunc_3()
{
    if (m_spProduct.get() == 0)
        return 0;
    return m_spProduct->m_nId;
}

// @0x1406f24b0
unsigned CNpcShopMeratItemSvr::vfunc_3()
{
    return m_nSn;
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x1406df180, FUN_1406df180, 6, 0xFFA3AE7F);
MS2_REPLACE(0x1406df690, FUN_1406df690, 3315, 0xAEF0974A);
MS2_REPLACE(0x1406e21b0, FUN_1406e21b0, 908, 0xB569CF72);
MS2_REPLACE_METHOD(0x1406e2600, CNpcShopData, Read, 1454, 0x4E5603C8);
MS2_REPLACE(0x1406e2c10, FUN_1406e2c10, 260, 0x78C2A73E);
MS2_REPLACE(0x1406e2d20, FUN_1406e2d20, 431, 0x33D51D3C);
MS2_REPLACE(0x1406e2ee0, FUN_1406e2ee0, 190, 0x15DF81BD);
MS2_REPLACE(0x1406e3460, FUN_1406e3460, 323, 0x4ED278B7);
MS2_REPLACE_METHOD(0x1406e3900, CBeautyShopItem, FUN_1406e3900, 682, 0x34FCDCE9);
MS2_REPLACE_METHOD(0x1406e4260, CBeautyShopItemGroups, FUN_1406e4260, 232, 0xED5A6CB2);
MS2_REPLACE(0x1406e4420, FUN_1406e4420, 207, 0xD8B8393F);
MS2_REPLACE_METHOD(0x1406e45b0, CBeautyShopData, Read, 432, 0x08A4BE3E);
MS2_REPLACE_METHOD(0x1406e4ce0, CBeautyShopData, GetShopItemGroupList, 172, 0xF6135C20);
MS2_REPLACE(0x1406e4db0, FUN_1406e4db0, 11, 0x30025ED0);
MS2_REPLACE(0x1406e4dd0, FUN_1406e4dd0, 278, 0xBF47013A);
MS2_REPLACE(0x1406e55b0, FUN_1406e55b0, 267, 0xEEA11BA8);
MS2_REPLACE(0x1406e5a40, FUN_1406e5a40, 170, 0x5E64F0EF);
MS2_REPLACE(0x1406e5ba0, FUN_1406e5ba0, 21, 0x00E918A5);
MS2_REPLACE(0x1406e5bc0, FUN_1406e5bc0, 36, 0x91B4DE0C);
MS2_REPLACE(0x1406e5bf0, FUN_1406e5bf0, 670, 0xA9B6A623);
MS2_REPLACE(0x1406e5ea0, FUN_1406e5ea0, 421, 0xF247BA76);
MS2_REPLACE(0x1406e8b50, FUN_1406e8b50, 194, 0xB4D21D25);
MS2_REPLACE_METHOD(0x1406f1930, CNpcShopMeratItemSvr, vfunc_2, 11, 0x02239C70);
MS2_REPLACE_METHOD(0x1406f1980, CNpcShopMeratItemBase, vfunc_1, 115, 0xCD056558);
MS2_REPLACE_METHOD(0x1406f1a00, CNpcShopMeratItemSvr, vfunc_1, 82, 0xDA979F2E);
MS2_REPLACE_METHOD(0x1406f2470, CNpcShopMeratItemBase, vfunc_3, 60, 0xABB6EB59);
MS2_REPLACE_METHOD(0x1406f24b0, CNpcShopMeratItemSvr, vfunc_3, 14, 0x828204CF);

