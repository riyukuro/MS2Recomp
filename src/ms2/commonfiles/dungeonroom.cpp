// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dungeon room table: DungeonRoom.xml and its companion
// tables (DungeonRankReward, DungeonSeason, DungeonRoundData, DungeonConfig, DungeonRewardCoupon).
// MS2-UNIT: commonfiles\dungeonroom.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x14031c970-0x140343e50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140322990 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1403229c0 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140322f50 ; unique
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140322fa0 ; unique
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140323040 ; unique
// MS2-PIN: ??$?0V?$tuple@$$QEAI@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@QEAA@AEAV?$tuple@$$QEAI@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140323740 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140334460 ; w203: set erase(first, last) calls it (0x140323920 is the reverse_iterator operator!=)
// MS2-PIN: ??$Log@I@Unk_CommonLog@@QEAAX_K0HPEB_WAEBI@Z 0x1403239a0 ; unique
// MS2-PIN: ??$_Advance1@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@U_Iterator_base0@2@@std@@_J@std@@YAXAEAV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@U_Iterator_base0@2@@0@_JUbidirectional_iterator_tag@0@@Z 0x140324150 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@1@@Z 0x140324210 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAI@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRewardCoupon@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAI@1@$$QEAV?$tuple@$$V@1@@Z 0x1403242a0 ; unique
// MS2-PIN: ??$_Distance1@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@YA_JV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@U_Iterator_base0@2@@0@0Uinput_iterator_tag@0@@Z 0x140324ee0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBF@?$vector@FV?$allocator@F@std@@@std@@AEAAXAEBF@Z 0x1403253b0 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBF@?$vector@FV?$allocator@F@std@@@std@@QEAAPEAFQEAFAEBF@Z 0x140325830 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VDungeonRoundData@@@@@?$vector@V?$MS2Ptr@VDungeonRoundData@@@@V?$allocator@V?$MS2Ptr@VDungeonRoundData@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VDungeonRoundData@@@@QEAV2@AEBV2@@Z 0x140325f10 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@_JPEAX@std@@@std@@@?$_Tree_node@_JPEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@_JPEAX@std@@@1@PEAU01@@Z 0x1403269f0 ; unique
// MS2-PIN: ??$_Idl_distance1@PEAFPEAF@std@@YA_JAEBQEAF0Urandom_access_iterator_tag@0@@Z 0x140326c30 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@1@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@1@1@Z 0x1403279c0 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRewardCoupon@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@1@@Z 0x140328740 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRankRewardBase@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@PEAX@1@@Z 0x14032b840 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRewardCoupon@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@1@@Z 0x14032bc50 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@1@@Z 0x14032c470 ; unique
// MS2-PIN: ??$_Kfn@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@SAAEBIAEBU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@1@@Z 0x14032d4e0 ; prop
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@1@AEBI@Z 0x14032d6f0 ; unique
// MS2-PIN: ??$_Next_iter@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@U_Iterator_base0@2@@std@@@std@@YA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@U_Iterator_base0@2@@0@V10@@Z 0x14032d8d0 ; unique
// MS2-PIN: ??$_Try_emplace@I$$V@?$map@IV?$MS2Ptr@VDungeonRewardCoupon@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@std@@_N@1@$$QEAI@Z 0x14032e260 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@_JPEAX@std@@@std@@YAPEAPEAU?$_Tree_node@_JPEAX@0@AEAPEAU10@@Z 0x14032f7d0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@_J@std@@@0@AEAV10@@Z 0x14032f8c0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@_JPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@_JPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@_JPEAX@std@@@1@QEAPEAU?$_Tree_node@_JPEAX@1@AEAPEAU31@@Z 0x14032fc30 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@$$QEAI@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAI@1@$$QEAV?$tuple@$$V@1@@Z 0x14032fcd0 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAI@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRewardCoupon@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAI@1@$$QEAV?$tuple@$$V@1@@Z 0x140330d40 ; unique
// MS2-PIN: ??$forward@$$QEAI@std@@YA$$QEAIAEAI@Z 0x140330fc0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@_JPEAX@std@@@std@@YAAEAPEAU?$_Tree_node@_JPEAX@0@AEAPEAU10@@Z 0x140331050 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@YAAEAU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@0@AEAU10@@Z 0x140331090 ; prop
// MS2-PIN: ??$lower_bound@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@@std@@U?$pair@IG@2@UDungeonRoomLess@@@std@@YA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@@0@V10@V10@AEBU?$pair@IG@0@UDungeonRoomLess@@@Z 0x1403314d0 ; unique
// MS2-PIN: ??$try_emplace@$$V@?$map@IV?$MS2Ptr@VDungeonRewardCoupon@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@std@@_N@1@$$QEAI@Z 0x1403317b0 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@@std@@@std@@QEAA@XZ 0x140332880 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@QEAA@XZ 0x1403328b0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@@std@@QEAA@XZ 0x140332910 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x140332fa0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x140332fb0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x140332fd0 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA@XZ 0x140333920 ; unique
// MS2-PIN: ??1DungeonRankRequire@@QEAA@XZ 0x140333e50 ; unique
// MS2-PIN: ??1ItemGift@@UEAA@XZ 0x140333f10 ; prop
// MS2-PIN: ??A?$map@IV?$MS2Ptr@VDungeonRewardCoupon@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@3@@std@@QEAAAEAV?$MS2Ptr@VDungeonRewardCoupon@@@@$$QEAI@Z 0x140334560 ; unique
// MS2-PIN: ??A?$vector@FV?$allocator@F@std@@@std@@QEAAAEAF_K@Z 0x140334660 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403354b0 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403354d0 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140335510 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403355b0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403355f0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1403358c0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@_JPEAX@2@XZ 0x140337750 ; unique
// MS2-PIN: ?_Change_array@?$vector@FV?$allocator@F@std@@@std@@AEAAXQEAF_K1@Z 0x140338220 ; unique
// MS2-PIN: ?_Change_array@?$vector@V?$MS2Ptr@VDungeonRoundData@@@@V?$allocator@V?$MS2Ptr@VDungeonRoundData@@@@@std@@@std@@AEAAXQEAV?$MS2Ptr@VDungeonRoundData@@@@_K1@Z 0x140338660 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRankRewardBase@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x140338990 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRewardCoupon@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x1403389d0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x140338a50 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAAXXZ 0x140338c70 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@2@@Z 0x140338f50 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@_JPEAX@2@@Z 0x1403394b0 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@_J@std@@@2@XZ 0x14033c840 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@F@std@@V?$_Vector_val@U?$_Simple_types@F@std@@@2@$00@std@@QEBAAEBV?$allocator@F@2@XZ 0x14033cb10 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEBAAEBV?$allocator@F@2@XZ 0x14033d280 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@IEBAAEBIPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@2@@Z 0x14033d830 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@IEBAAEBIAEBU?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@2@@Z 0x14033d950 ; unique
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEAAXXZ 0x14033ea20 ; prop
// MS2-PIN: ?_Reallocate_exactly@?$vector@IV?$allocator@I@std@@@std@@AEAAX_K@Z 0x14033eaf0 ; unique
// MS2-PIN: ?_Tidy@?$vector@FV?$allocator@F@std@@@std@@AEAAXXZ 0x14033fce0 ; gb19 calls capacity<short> 0x1403410c0 (sar 1); not vector<unsigned>::_Tidy
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@FV?$allocator@F@std@@@std@@AEAAXPEAF00U?$integral_constant@_N$00@2@@Z 0x140340450 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@UDungeonRankRewardItem@@V?$allocator@UDungeonRankRewardItem@@@std@@@std@@AEAAXPEAUDungeonRankRewardItem@@00U?$integral_constant@_N$00@2@@Z 0x140340490 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@2@XZ 0x140340ff0 ; unique
// MS2-PIN: ?capacity@?$vector@FV?$allocator@F@std@@@std@@QEBA_KXZ 0x1403410c0 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAAXXZ 0x1403416e0 ; unique
// MS2-PIN: ?deallocate@?$allocator@F@std@@QEAAXQEAF_K@Z 0x140341980 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@2@XZ 0x140341f40 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VDungeonRoom@@@@UDungeonRoomLess@@V?$allocator@V?$MS2Ptr@VDungeonRoom@@@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonRoom@@@@@std@@@std@@@2@V32@0@Z 0x140342a20 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@2@V32@0@Z 0x140342bc0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@2@V32@@Z 0x140342cb0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRankRewardBase@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRankRewardBase@@@@@std@@@std@@@std@@@2@AEBI@Z 0x140342d60 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRewardCoupon@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRewardCoupon@@@@@std@@@std@@@std@@@2@AEBI@Z 0x140342e40 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@@std@@@2@AEBI@Z 0x140343000 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VDungeonRoundGroup@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@@std@@@std@@@2@AEBI@Z 0x1403432e0 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@F@std@@@std@@SA_KAEBV?$allocator@F@2@@Z 0x140343400 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VDungeonRoundGroup@@@@@std@@PEAX@std@@@2@@Z 0x140343440 ; unique
// MS2-PIN: ?size@?$vector@FV?$allocator@F@std@@@std@@QEBA_KXZ 0x140343c30 ; unique
// MS2-PINS-END tplpin
// DungeonRoomTable's vftables (no RTTI pairing for the TSingleton/CValidData subobjects)
// MS2-PIN: ??_7DungeonRoomTable@@6B?$TSingleton@VDungeonRoomTable@@@@@ 0x142d28ab0
// MS2-PIN: ??_7DungeonRoomTable@@6B?$CValidData@VDungeonRoomTable@@@@@ 0x142d28ac0
// Partial recovery: the free helpers, DungeonRoom / DungeonRankRewardBase / DungeonLobbyCtx / DungeonSeason /
// DungeonRoundGroup and the whole DungeonRoomTable (0x14031c970-0x140322960); 53 tail COMDATs left as stubs.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dungeonroom.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dungeonroom.h"
#include "dungeonrewardcoupon.h"
#include "timeutil.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/filesystem.h"
#include <algorithm>
#include <iterator>
#include <stdlib.h>

// The common log (GetLogString()).
class Unk_CommonLog : public CLogString
{
public:
    template <class T> void Log(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* format, const T& value)
    {
        fmt::internal::Value values[] = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(value)};
        FUN_140653690(a, b, flags, format, fmt::ArgList(fmt::internal::make_type(value), values));
    }
    void Log(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* message);
};
class CLogString* GetLogString();


// Common::Constants::Value<T>::Get, header-inline in the original (the Value<bool> instance 0x140336990 is in this
// unit's COMDAT tail); same body as unit_1402ab440's.
template<class T> T* Common::Constants::Value<T>::Get()
{
    if (!m_defined)
        Error("constants is not set");
    return &m_value;
}

int FUN_140768010(int nRange, int nBase);              // random number in [nBase, nBase + nRange)
int Unk_ClubBuffTypeOf(int nValue);
int FUN_140873160(Unk_140165cf0* pElem, const char* pszName, short& nOut);
int FUN_140873600(Unk_140165cf0* pElem, const char* pszName, CMsTime& tOut);
int Parse_14021ab60(const CString& str);               // timer type name -> value
void FUN_140274fc0(CStringW& str, void* pOut, const wchar_t* pszDelim);   // split into a CAtlArray<unsigned>

// The table file loader helpers.
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
bool FUN_14028f710(Unk_140165cf0* pElem);                               // the element is usable
class Unk_1406aeee0 { public: bool FUN_1406af020(); };
Unk_1406aeee0* FUN_1406aeee0();

// Clamps v into [lo, hi].
template <class T> T Clamp(const T& v, T lo, T hi)
{
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}

// Appends src to the end of out.
template <class C> void AppendTo(const C& src, C& out)
{
    std::copy(src.begin(), src.end(), std::back_inserter(out));
}

// The "kill"/"damage"/... boss ranking type names.
DungeonBossRankingType ParseBossRankingType(const CString& str);   // 0x1403227f0

// Sets the bits listed in a comma separated string ("1,3,5").
inline void SetBitsFromString(Unk_PartyBits& bits, CStringW str)
{
    if (str.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> arr;
    FUN_140274fc0(str, &arr, L",");
    for (unsigned i = 0; i < arr.GetCount(); i++)
        bits.FUN_1402e69d0(arr[i], true);
}
inline void SetBits(Unk_PartyBits& bits, CStringW str)
{
    SetBitsFromString(bits, str);
}

// tinyxmlhelper.h readers.
inline int ReadDayBits(Unk_140165cf0* pElem, const char* pszName, Unk_PartyBits& out)
{
    CStringW str;
    int nRet = FUN_140873420(pElem, pszName, str);
    if (nRet == 0)
        SetBits(out, str);
    return nRet;
}
inline int ReadBossRankingType(Unk_140165cf0* pElem, const char* pszName, DungeonBossRankingType& out)
{
    if (0)
    {
        MS2_TINYXMLHELPER_ASSERT(250, FALSE);
        return 2;
    }
    CString str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet != 0)
        return nRet;
    out = ParseBossRankingType(str);
    return nRet;
}
inline int ReadTimerType(Unk_140165cf0* pElem, const char* pszName, DungeonTimerType& out)
{
    if (0)
    {
        MS2_TINYXMLHELPER_ASSERT(250, FALSE);
        return 2;
    }
    CString str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet != 0)
        return nRet;
    out = (DungeonTimerType)Parse_14021ab60(str);
    return nRet;
}

// @0x14031c970
int MakeDungeonRoomId(int nDungeonId, int nIndex)
{
    return nDungeonId * 1000 + nIndex;
}
MS2_REPLACE_OVERLOAD(0x14031C970, int(int, int), MakeDungeonRoomId, 21, 0xD0D09CEF);

// @0x14031c990
unsigned GetDungeonIdOfRoom(unsigned nRoomId)
{
    return nRoomId / 1000;
}
MS2_REPLACE_OVERLOAD(0x14031C990, unsigned(unsigned), GetDungeonIdOfRoom, 18, 0x9F64D931);

// @0x14031c9b0
unsigned GetIndexOfRoom(unsigned nRoomId)
{
    return nRoomId % 1000;
}
MS2_REPLACE_OVERLOAD(0x14031C9B0, unsigned(unsigned), GetIndexOfRoom, 20, 0xB85C6666);

// @0x14031c9d0
CString GetRankName(int nRank)
{
    if (nRank < 0)
        return "rank_unknown";
    return StringFormat("rank{0}", nRank);
}
MS2_REPLACE_OVERLOAD(0x14031C9D0, CString(int), GetRankName, 107, 0x7CC0E8D0);

// @0x14031ca50
DungeonLobbyCtx::DungeonLobbyCtx()
    : m_18(0), m_1c(0), m_20(0)
{
}

// @0x14031cad0
DungeonRankRewardBase::DungeonRankRewardBase()
    : m_rewardID(0), m_maxRank(0)
{
}

// @0x14031cb30
bool DungeonRankRewardBase::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "rewardID", m_rewardID);
    m_items.resize(6);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("v"); pChild; pChild = pChild->FUN_140168650("v"))
    {
        int nRank = 0;
        FUN_1408731e0(pChild, "rank", nRank);
        if (nRank <= 0 || nRank > 5)
        {
            static_cast<Unk_CommonLog*>(GetLogString())->Log(0, 0, 0x13, StringFormat(L"DungeonRankReward::FromXel Invalid Rank", m_rewardID, nRank));
            return false;
        }
        if (m_maxRank < nRank)
            m_maxRank = nRank;
        DungeonRankRewardItem& item = m_items[nRank];
        FUN_140873220(pChild, "itemID", item.itemID);
        FUN_1408731e0(pChild, "systemMailID", item.systemMailID);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14031CB30, DungeonRankRewardBase, Load, 434, 0x129CC2FA);

// @0x14031ccf0
unsigned DungeonRankRewardBase::GetId()
{
    return m_rewardID;
}
MS2_REPLACE_METHOD(0x14031CCF0, DungeonRankRewardBase, GetId, 14, 0x72E52537);

// @0x14031cd10
unsigned DungeonRankRewardBase::GetItemId(int nRank)
{
    if ((size_t)nRank >= m_items.size())
        return 0;
    return m_items[nRank].itemID;
}
MS2_REPLACE_METHOD(0x14031CD10, DungeonRankRewardBase, GetItemId, 80, 0x197FCB72);

// @0x14031cd70
int DungeonRankRewardBase::GetSystemMailId(int nRank)
{
    if ((size_t)nRank >= m_items.size())
        return 0;
    return m_items[nRank].systemMailID;
}
MS2_REPLACE_METHOD(0x14031CD70, DungeonRankRewardBase, GetSystemMailId, 81, 0x282CEAA5);

// @0x14031cdd0
int DungeonRankRewardBase::GetMaxRank()
{
    return m_maxRank;
}
MS2_REPLACE_METHOD(0x14031CDD0, DungeonRankRewardBase, GetMaxRank, 14, 0xB2976B17);

// @0x14031cdf0
DungeonRoom::DungeonRoom()
    : m_dungeonRoomID(0), m_groupType((DungeonGroupType)0), m_dungeonLevel(0), m_limitEnter(false), m_clearKillNpc(0),
      m_sortOrder(0), m_cooldownValue(0), m_rewardCount(0), m_subRewardCount(0), m_isAccountReward(false),
      m_unionRewardID(0), m_roundID(0), m_rewardExp(0), m_rewardExpRate(0), m_rewardMeso(0), m_seasonRankRewardID(0),
      m_scoreBonusId(0), m_extraRewardTicketTableID(0), m_extraRewardTicketBaseCount(0), m_lobbyFieldID(0),
      m_durationSeconds(0), m_isExpireTimeOut(false), m_timerType((DungeonTimerType)0), m_minUserCount(0),
      m_maxUserCount(0), m_gearScore(0), m_limitAchieveID(0), m_limitPlayerLevel(0), m_limitVIP(false),
      m_isLimitTime(false), m_limitMesoRevival(false), m_limitMeratRevival(false), m_limitRecommendWeapon(false),
      m_defaultRevivalLimitCount(0), m_isTimeUp(0), m_isUseBossIcon(false),
      m_bossRankingType((DungeonBossRankingType)0), m_bossRanking(0), m_isRandomField(false), m_isPartyOnly(false),
      m_isChangeMaxUser(false), m_playerCountFactorID(0), m_customMonsterLevel(0), m_chaosDamageMeter(false),
      m_isMoveOutToBackupField(false), m_dungeonHelperRequireClearCount(0), m_isUseRandomMatch(false),
      m_isDisableRandomMatch(false), m_isLeaveAfterCloseReward(false), m_rankTableID(0), m_representID(0),
      m_dungeonScaleStatID(0), m_pRoundGroup(0), m_pCoupon(0)
// @0x14031cdf0 (the long init list puts the CodeView first line on the brace)
{
}

// @0x14031d220
DungeonRoom::~DungeonRoom()
{
}

// @0x14031d350
void DungeonRoom::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dungeonRoomID", m_dungeonRoomID);
    FUN_1408731a0(pElem, "dungeonLevel", m_dungeonLevel);
    FUN_1408730a0(pElem, "limitEnter", m_limitEnter);
    XmlValue(pElem, "groupType", m_groupType);
    FUN_1408731e0(pElem, "clearKillNpc", m_clearKillNpc);
    FUN_1408731e0(pElem, "cooldownValue", m_cooldownValue);
    FUN_1408731e0(pElem, "sortOrder", m_sortOrder);
    FUN_140873220(pElem, "rewardCount", m_rewardCount);
    FUN_140873220(pElem, "subRewardCount", m_subRewardCount);
    FUN_1408730a0(pElem, "isAccountReward", m_isAccountReward);
    FUN_140873220(pElem, "unionRewardID", m_unionRewardID);
    FUN_140873220(pElem, "roundID", m_roundID);
    FUN_1408732e0(pElem, "rewardExp", m_rewardExp);
    FUN_140873360(pElem, "rewardExpRate", m_rewardExpRate);
    FUN_1408732e0(pElem, "rewardMeso", m_rewardMeso);
    FUN_1408731e0(pElem, "scoreBonusId", m_scoreBonusId);
    XmlTokenList(pElem, "rewardLimitedDropBoxIds", m_rewardLimitedDropBoxIds);
    XmlTokenList(pElem, "rewardLimitedDropBoxIds2", m_rewardLimitedDropBoxIds2);
    FUN_140873220(pElem, "seasonRankRewardID", m_seasonRankRewardID);
    m_rewardDropBoxIds = m_rewardLimitedDropBoxIds;
    std::copy(m_rewardLimitedDropBoxIds2.begin(), m_rewardLimitedDropBoxIds2.end(), std::back_inserter(m_rewardDropBoxIds));
    FUN_140873220(pElem, "extraRewardTicketTableID", m_extraRewardTicketTableID);
    FUN_140873220(pElem, "extraRewardTicketBaseCount", m_extraRewardTicketBaseCount);
    FUN_140873220(pElem, "lobbyFieldID", m_lobbyFieldID);
    XmlTokenList(pElem, "fieldIDs", m_fieldIDs);
    FUN_1408731e0(pElem, "durationSeconds", m_durationSeconds);
    FUN_1408730a0(pElem, "isExpireTimeOut", m_isExpireTimeOut);
    ReadTimerType(pElem, "timerType", m_timerType);
    FUN_140873220(pElem, "minUserCount", m_minUserCount);
    FUN_140873220(pElem, "maxUserCount", m_maxUserCount);
    FUN_140873220(pElem, "gearScore", m_gearScore);
    FUN_1408731e0(pElem, "limitAchieveID", m_limitAchieveID);
    FUN_1408731a0(pElem, "limitPlayerLevel", m_limitPlayerLevel);
    ReadDayBits(pElem, "limitDayOfWeeks", m_limitDayOfWeeks);
    FUN_1408730a0(pElem, "limitVIP", m_limitVIP);
    FUN_1408730a0(pElem, "isLimitTime", m_isLimitTime);
    FUN_1408730a0(pElem, "limitMesoRevival", m_limitMesoRevival);
    FUN_1408730a0(pElem, "limitMeratRevival", m_limitMeratRevival);
    XmlTokenList(pElem, "limitClearDungeon", m_limitClearDungeon);
    XmlTokenList(pElem, "limitAdditionalEffects", m_limitAdditionalEffects);
    FUN_1408730a0(pElem, "limitRecommendWeapon", m_limitRecommendWeapon);
    FUN_1408733e0(pElem, "dungeonBanner", m_dungeonBanner);
    FUN_1408733e0(pElem, "bossIcon", m_bossIcon);
    FUN_1408731e0(pElem, "isTimeUp", m_isTimeUp);
    FUN_1408730a0(pElem, "isUseBossIcon", m_isUseBossIcon);
    ReadBossRankingType(pElem, "BossRankingType", m_bossRankingType);
    FUN_140873220(pElem, "BossRanking", m_bossRanking);
    FUN_140873420(pElem, "openPeriodTag", m_openPeriodTag);
    FUN_140873600(pElem, "openPeriodDate", m_openPeriodDate);
    FUN_1408730a0(pElem, "isRandomField", m_isRandomField);
    FUN_1408730a0(pElem, "isPartyOnly", m_isPartyOnly);
    FUN_1408730a0(pElem, "isChangeMaxUser", m_isChangeMaxUser);
    FUN_140873220(pElem, "playerCountFactorID", m_playerCountFactorID);
    FUN_1408731e0(pElem, "customMonsterLevel", m_customMonsterLevel);
    FUN_1408730a0(pElem, "chaosDamageMeter", m_chaosDamageMeter);
    FUN_1408730a0(pElem, "isMoveOutToBackupField", m_isMoveOutToBackupField);
    FUN_140873220(pElem, "defaultRevivalLimitCount", m_defaultRevivalLimitCount);
    FUN_1408731e0(pElem, "dungeonHelperRequireClearCount", m_dungeonHelperRequireClearCount);
    XmlTokenList(pElem, "findHelperRewardDropBoxIds", m_findHelperRewardDropBoxIds);
    FUN_1408730a0(pElem, "isUseRandomMatch", m_isUseRandomMatch);
    FUN_1408730a0(pElem, "isDisableRandomMatch", m_isDisableRandomMatch);
    FUN_1408730a0(pElem, "isLeaveAfterCloseReward", m_isLeaveAfterCloseReward);
    XmlTokenList(pElem, "partyMissions", m_partyMissions);
    XmlTokenList(pElem, "userMissions", m_userMissions);
    FUN_140873220(pElem, "rankTableID", m_rankTableID);
    FUN_140873220(pElem, "representID", m_representID);
    FUN_140873220(pElem, "dungeonScaleStatID", m_dungeonScaleStatID);
    ApplyConstants();
    if (m_bossRankingType == 0 && m_bossRanking != 0)
    {
        static_cast<Unk_CommonLog*>(GetLogString())->Log(0, 0, 0x13, L"DungeonRoom::FromXel : m_bossRanking is exists but bossRankingType is none or empty. use kill type as default. ID=[{0}]", m_dungeonRoomID);
        m_bossRankingType = (DungeonBossRankingType)1;
    }
}
MS2_REPLACE_METHOD(0x14031D350, DungeonRoom, Load, 2671, 0x847FF231);

// @0x14031ddd0
unsigned DungeonRoom::GetDungeonRoomID()
{
    return m_dungeonRoomID;
}
MS2_REPLACE_METHOD(0x14031DDD0, DungeonRoom, GetDungeonRoomID, 14, 0x72E52537);

// @0x14031ddf0
unsigned DungeonRoom::GetRewardRoomID()
{
    if (m_unionRewardID != 0)
        return m_unionRewardID;
    return m_dungeonRoomID;
}
MS2_REPLACE_METHOD(0x14031DDF0, DungeonRoom, GetRewardRoomID, 35, 0x23747190);

// @0x14031de20
unsigned DungeonRoom::GetDungeonID()
{
    return GetDungeonIdOfRoom(m_dungeonRoomID);
}
MS2_REPLACE_METHOD(0x14031DE20, DungeonRoom, GetDungeonID, 27, 0xDAE514A2);

// @0x14031de50
unsigned DungeonRoom::GetRoomIndex()
{
    return GetIndexOfRoom(m_dungeonRoomID);
}
MS2_REPLACE_METHOD(0x14031DE50, DungeonRoom, GetRoomIndex, 27, 0xDEC64D72);

// @0x14031de80
bool DungeonRoom::HasEnterRequirement()
{
    if (m_limitPlayerLevel != 0)
        return true;
    if (m_gearScore != 0)
        return true;
    if (m_limitAchieveID != 0)
        return true;
    if (m_limitClearDungeon.size() > 0)
        return true;
    if (m_limitRecommendWeapon)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14031DE80, DungeonRoom, HasEnterRequirement, 120, 0x2760FAFF);

// @0x14031df00
unsigned DungeonRoom::GetLobbyFieldID()
{
    return m_lobbyFieldID;
}
MS2_REPLACE_METHOD(0x14031DF00, DungeonRoom, GetLobbyFieldID, 17, 0x33D25353);

// @0x14031df20
unsigned DungeonRoom::GetFirstFieldID()
{
    if (m_fieldIDs.IsEmpty())
        return 0;
    return m_fieldIDs[0];
}
MS2_REPLACE_METHOD(0x14031DF20, DungeonRoom, GetFirstFieldID, 67, 0xB0309514);

// @0x14031df70
int DungeonRoom::GetLimitType()
{
    if (m_limitEnter)
        return 2;
    return 1;
}
MS2_REPLACE_METHOD(0x14031DF70, DungeonRoom, GetLimitType, 31, 0x7E625B46);

// @0x14031dfa0
int DungeonRoom::GetCooldownType()
{
    if (m_cooldownValue == 0)
        return 2;
    return 1;
}
MS2_REPLACE_METHOD(0x14031DFA0, DungeonRoom, GetCooldownType, 29, 0x1F7BD1B6);

// @0x14031dfd0
int DungeonRoom::GetCooldownValue()
{
    return m_cooldownValue;
}
MS2_REPLACE_METHOD(0x14031DFD0, DungeonRoom, GetCooldownValue, 14, 0x9A8B24F3);

// @0x14031dff0
__int64 DungeonRoom::GetCooldownEndTime(__int64 tNow)
{
    return CalcCooldownEndTime(GetCooldownType(), m_cooldownValue, tNow);
}
MS2_REPLACE_METHOD(0x14031DFF0, DungeonRoom, GetCooldownEndTime, 49, 0x1EF01660);

// @0x14031e030
unsigned DungeonRoom::GetMaxUserCount(unsigned nUser)
{
    if (!m_isChangeMaxUser)
        return m_maxUserCount;
    return Clamp(nUser, 2u, m_maxUserCount);
}
MS2_REPLACE_METHOD(0x14031E030, DungeonRoom, GetMaxUserCount, 74, 0xD5A8F3B9);

// @0x14031e0d0
bool DungeonRoom::HasExtraRewardTicket()
{
    return m_extraRewardTicketTableID != 0;
}
MS2_REPLACE_METHOD(0x14031E0D0, DungeonRoom, HasExtraRewardTicket, 48, 0x0FD978E4);

// @0x14031e110
unsigned DungeonRoom::GetCouponBaseItemID()
{
    DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return 0;
    return pCoupon->m_baseItemID;
}

// @0x14031e150
unsigned DungeonRoom::GetCouponTicketTag()
{
    DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return 0;
    return pCoupon->m_ticketTag;
}

// @0x14031e190
bool DungeonRoom::CanBuyCouponInMeratMarket()
{
    DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return false;
    return pCoupon->m_canBuyInMeratMarket;
}

// @0x14031e1d0
bool DungeonRoom::HasMissions()
{
    if (m_partyMissions.size() > 0)
        return true;
    if (m_userMissions.size() > 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14031E1D0, DungeonRoom, HasMissions, 72, 0x07D4B4BD);

// @0x14031e220
unsigned DungeonRoom::GetSeasonRankRewardID()
{
    return m_seasonRankRewardID;
}
MS2_REPLACE_METHOD(0x14031E220, DungeonRoom, GetSeasonRankRewardID, 17, 0x1F8D7963);

// @0x14031e240
unsigned DungeonRoom::GetRandomFieldID()
{
    if (m_fieldIDs.IsEmpty())
        return 0;
    unsigned nIndex = FUN_140768010((int)m_fieldIDs.GetCount(), 0);
    return m_fieldIDs[nIndex];
}
MS2_REPLACE_METHOD(0x14031E240, DungeonRoom, GetRandomFieldID, 101, 0x827DB8B9);

// @0x14031e2b0
unsigned DungeonRoom::GetExtraRewardTicketCost(unsigned nCount)
{
    const DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return 0;
    int nRates = (int)pCoupon->m_baseRate.GetCount();
    unsigned nIndex = Clamp(nCount, 0u, (unsigned)(nRates - 1));
    return m_extraRewardTicketBaseCount * pCoupon->m_baseRate[nIndex];
}

// @0x14031e340
int DungeonRoom::GetCouponMaxExtraCount()
{
    DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return 0;
    return pCoupon->m_maxExtraCount;
}

// @0x14031e380
void DungeonRoom::GetRewardDropBoxIds(std::vector<unsigned>& out)
{
    AppendTo(m_rewardDropBoxIds, out);
}
MS2_REPLACE_METHOD(0x14031E380, DungeonRoom, GetRewardDropBoxIds, 43, 0xE46707CA);

// @0x14031e3c0
unsigned DungeonRoom::GetDefaultRevivalLimitCount()
{
    return m_defaultRevivalLimitCount;
}
MS2_REPLACE_METHOD(0x14031E3C0, DungeonRoom, GetDefaultRevivalLimitCount, 17, 0x59A3408A);

// @0x14031e3e0
void DungeonRoom::GetMissions(std::vector<unsigned>& out)
{
    out.clear();
    AppendTo(m_partyMissions, out);
    AppendTo(m_userMissions, out);
}
MS2_REPLACE_METHOD(0x14031E3E0, DungeonRoom, GetMissions, 77, 0xA4197214);

// @0x14031e440
int DungeonRoom::GetRank(short nScore)
{
    return DungeonRoomTable::GetInstance()->GetRank(this, nScore);
}

// @0x14031e480
bool DungeonRoom::IsSeasonRankRoom()
{
    if (m_groupType != 3)
        return false;
    if (m_limitPlayerLevel < (unsigned)FUN_1401d3200()->DungeonSeasonRankMinLevel)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x14031E480, DungeonRoom, IsSeasonRankRoom, 68, 0xCDEF7F9A);

// @0x14031e4d0
bool DungeonRoom::IsRandomMatchable()
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xb8))
        return false;
    switch (m_groupType)
    {
    case 1:
    case 2:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14031E4D0, DungeonRoom, IsRandomMatchable, 77, 0xB1B0E732);

// @0x14031e530
bool DungeonRoom::HasRoundGroup() const
{
    return m_pRoundGroup != 0;
}
MS2_REPLACE_METHOD(0x14031E530, DungeonRoom, HasRoundGroup, 49, 0x3DE75B1F);

// @0x14031e570
bool DungeonRoom::IsSingleRound()
{
    if (m_groupType == 7)
        return false;
    if (HasRoundGroup())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x14031E570, DungeonRoom, IsSingleRound, 52, 0x5C55AC09);

// @0x14031e5b0
void DungeonRoom::GetRoundRewardIds(unsigned char nFrom, unsigned char nTo, std::vector<unsigned>& out)
{
    if (m_pRoundGroup == 0)
        return;
    m_pRoundGroup->GetRewardIds(nFrom, nTo, out);
}
MS2_REPLACE_METHOD(0x14031E5B0, DungeonRoom, GetRoundRewardIds, 78, 0xC9F4DBD5);

// @0x14031e610
int DungeonRoom::GetRankTableID()
{
    if (m_rankTableID != 0)
        return m_rankTableID;
    switch (m_groupType)
    {
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    case 8: return 6;
    case 12: return 5;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14031E610, DungeonRoom, GetRankTableID, 133, 0x32CB022B);

// @0x14031e6d0
int Unk_DungeonRoom_14031e6d0(int nType)
{
    switch (nType)
    {
    case 1:
        return 4;
    }
    MS2_ASSERT_AT(0x165, 0);
    return 0;
}
MS2_REPLACE_OVERLOAD(0x14031E6D0, int(int), Unk_DungeonRoom_14031e6d0, 73, 0xBB0DDCAC);

// @0x14031e720
bool IsDungeonLevelInRange(unsigned short nLevel, unsigned short nDungeonLevel)
{
    if (abs(nLevel - nDungeonLevel) <= 5)
        return true;
    if (nDungeonLevel >= 50 && nLevel >= 50 && nLevel <= nDungeonLevel)
        return true;
    return false;
}
MS2_REPLACE_OVERLOAD(0x14031E720, bool(unsigned short, unsigned short), IsDungeonLevelInRange, 79, 0xA936A542);

// @0x14031e780
bool Unk_DungeonRoom_14031e780(int nValue)
{
    int nResult = Unk_ClubBuffTypeOf(nValue);
    return nResult != 0;
}
MS2_REPLACE_OVERLOAD(0x14031E780, bool(int), Unk_DungeonRoom_14031e780, 56, 0x8141B625);

// @0x14031e7c0
__int64 CalcCooldownEndTime(int nType, int nValue, __int64 tNow)
{
    switch (nType)
    {
    case 1:
    {
#ifdef __clang__
        CMsTime tStart(tNow); // clang cannot bind the temporary to CMsTime&
        __int64 t = GetWeekdayStart(tStart, nValue);
#else
        __int64 t = GetWeekdayStart(CMsTime(tNow), nValue);
#endif
        if (t == 0)
            t = tNow;
        return t;
    }
    break;
    case 2:
        return GetNextDayStart(tNow);
    }
    return tNow;
}
MS2_REPLACE_OVERLOAD(0x14031E7C0, __int64(int, int, __int64), CalcCooldownEndTime, 120, 0x93DA44F0);

// @0x14031e840
void DungeonRoom::ApplyConstants()
{
    if (*FUN_1401d3200()->DisableSoloPlayHighLevelDungeon.Get() && m_groupType == 1 && m_limitPlayerLevel >= 50)
        m_isPartyOnly = true;
}
MS2_REPLACE_METHOD(0x14031E840, DungeonRoom, ApplyConstants, 80, 0x325A4B4F);

// @0x14031e8a0
DungeonRewardCoupon* DungeonRoom::GetCoupon()
{
    if (m_unionRewardID != 0)
    {
        DungeonRoomPtr pRoom = DungeonRoomTable::GetInstance()->GetRoom(m_unionRewardID);
        if (pRoom == 0)
            return 0;
        return pRoom->m_pCoupon;
    }
    return m_pCoupon;
}

// @0x14031e950
DungeonSeasonItemGift::DungeonSeasonItemGift()
    : m_requireScore(0)
{
}

// @0x14031e9a0
void DungeonSeasonItemGift::vfunc_4(Unk_140165cf0* pElem)
{
    ItemEntity::vfunc_2(pElem);
    FUN_140873220(pElem, "requireScore", m_requireScore);
}
MS2_REPLACE_METHOD(0x14031E9A0, DungeonSeasonItemGift, vfunc_4, 63, 0x75B0CC90);

// @0x14031e9f0
DungeonRankRequire::DungeonRankRequire()
    : m_maxScore(0)
{
}

// @0x14031ea30
void DungeonRankRequire::Load(Unk_140165cf0* pElem)
{
    FUN_140873160(pElem, "maxScore", m_maxScore);
    int nPrev = -1;
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("rank"); pChild; pChild = pChild->FUN_140168650("rank"))
    {
        int nScore = 0;
        FUN_1408731e0(pChild, "score", nScore);
        if (nPrev >= nScore)
        {
            static_cast<Unk_CommonLog*>(GetLogString())->Log(0, 0, 0x13, L"DungeonRankRequire Error Score");
            return;
        }
        nPrev = nScore;
        short sScore = (short)nScore;
        m_scores.push_back(sScore);
    }
    if (m_scores.empty() || *m_scores.rbegin() > m_maxScore)
        static_cast<Unk_CommonLog*>(GetLogString())->Log(0, 0, 0x13, L"DungeonRankRequire Error Score");
}
MS2_REPLACE_METHOD(0x14031EA30, DungeonRankRequire, Load, 337, 0xF8BFEB06);

// @0x14031eb90
short DungeonRankRequire::GetMaxScore()
{
    return m_maxScore;
}
MS2_REPLACE_METHOD(0x14031EB90, DungeonRankRequire, GetMaxScore, 14, 0x1731A3BA);

// @0x14031ebb0
int DungeonRankRequire::GetRank(short nScore)
{
    int nLast = (int)m_scores.size() - 1;
    for (int i = nLast; i >= 0; i--)
    {
        if (nScore >= m_scores[i])
            return i + 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14031EBB0, DungeonRankRequire, GetRank, 133, 0x75BE13E9);

// @0x14031ec40
size_t DungeonRankRequire::GetCount()
{
    return m_scores.size();
}
MS2_REPLACE_METHOD(0x14031EC40, DungeonRankRequire, GetCount, 31, 0xE38FCB57);

// @0x14031ec70
short DungeonRankRequire::GetScore(unsigned __int64 nIndex)
{
    if (nIndex >= m_scores.size())
        return 0;
    return m_scores[nIndex];
}
MS2_REPLACE_METHOD(0x14031EC70, DungeonRankRequire, GetScore, 72, 0xB175E5B7);

// @0x14031ecc0
DungeonSeason::DungeonSeason()
    : m_seasonID(0), m_maxSeasonScore(0), m_systemMailID(0), m_dayOfWeeks(0)
{
}

// @0x14031ed50
DungeonSeason::~DungeonSeason()
{
}

// @0x14031ed90
bool DungeonSeason::Load(Unk_140165cf0* pElem)
{
    FUN_140873160(pElem, "seasonID", m_seasonID);
    FUN_140873220(pElem, "maxSeasonScore", m_maxSeasonScore);
    FUN_1408731e0(pElem, "systemMailID", m_systemMailID);
    FUN_1408731e0(pElem, "dayOfWeeks", m_dayOfWeeks);
    m_period.FUN_140868d60(pElem);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("Reward"); pChild; pChild = pChild->FUN_140168650("Reward"))
    {
        MS2Ptr<DungeonSeasonItemGift> pReward(new DungeonSeasonItemGift);
        pReward->vfunc_4(pChild);
        m_rewards.push_back(pReward);
    }
    if (m_rewards.size() > 2)
    {
        for (unsigned i = 0; i < m_rewards.size() - 1; i++)
        {
            if (m_rewards[i]->m_requireScore <= m_rewards[i + 1]->m_requireScore)
            {
                static_cast<Unk_CommonLog*>(GetLogString())->Log(0, 0, 0x13, L"DungeonSeason Reward Item RequireScore");
                return false;
            }
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x14031ED90, DungeonSeason, Load, 652, 0x9A7CADD3);

// @0x14031f030
bool DungeonSeason::IsInPeriod(const CMsTime& t)
{
    return m_period.FUN_140868f60(t);
}
MS2_REPLACE_METHOD(0x14031F030, DungeonSeason, IsInPeriod, 41, 0x58E9BF83);

// @0x14031f060
MS2Ptr<DungeonSeasonItemGift> DungeonSeason::GetReward(unsigned nScore)
{
    for (unsigned i = 0; i < m_rewards.size(); i++)
    {
        if (m_rewards[i]->m_requireScore <= nScore)
            return m_rewards[i];
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14031F060, DungeonSeason, GetReward, 206, 0xEF2C7266);

// @0x14031f140
DungeonUnitedWeeklyReward::DungeonUnitedWeeklyReward()
    : m_rewardCount(0), m_rewardID(0), m_uiPosX(0), m_uiShowBg(false)
{
}

// @0x14031f1a0
DungeonUnitedWeeklyReward::~DungeonUnitedWeeklyReward()
{
}

// @0x14031f1d0
bool DungeonUnitedWeeklyReward::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "rewardCount", m_rewardCount);
    FUN_140873220(pElem, "rewardID", m_rewardID);
    FUN_1408731e0(pElem, "uiPosX", m_uiPosX);
    FUN_1408730a0(pElem, "uiShowBg", m_uiShowBg);
    return true;
}
MS2_REPLACE_METHOD(0x14031F1D0, DungeonUnitedWeeklyReward, Load, 137, 0xC9AEC35F);

// @0x14031f260
DungeonRoundData::DungeonRoundData()
    : m_rewardID(0), m_gearScore(0)
{
}

// @0x14031f2b0
bool DungeonRoundData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "rewardID", m_rewardID);
    FUN_140873220(pElem, "gearScore", m_gearScore);
    return true;
}
MS2_REPLACE_METHOD(0x14031F2B0, DungeonRoundData, Load, 79, 0xDE3B4585);

// @0x14031f310
DungeonRoundGroup::DungeonRoundGroup()
    : m_id(0)
{
}

// @0x14031f360
bool DungeonRoundGroup::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_id);
    if (m_id == 0)
        return false;
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("v"); pChild; pChild = pChild->FUN_140168650("v"))
    {
        MS2Ptr<DungeonRoundData> pRound(new DungeonRoundData);
        pRound->Load(pChild);
        m_rounds.push_back(pRound);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14031F360, DungeonRoundGroup, Load, 271, 0xADB62A2B);

// @0x14031f480
void DungeonRoundGroup::GetRewardIds(unsigned char nFrom, unsigned char nTo, std::vector<unsigned>& out)
{
    out.reserve(m_rounds.size());
    for (size_t i = nFrom; i < nTo; i++)
    {
        if (i >= m_rounds.size())
            break;
        out.push_back(m_rounds[i]->m_rewardID);
    }
}
MS2_REPLACE_METHOD(0x14031F480, DungeonRoundGroup, GetRewardIds, 170, 0x06171F6B);

// @0x14031f530
MS2Ptr<DungeonRoundData> DungeonRoundGroup::GetRound(unsigned nIndex)
{
    if (nIndex >= m_rounds.size())
        return 0;
    return m_rounds[nIndex];
}
MS2_REPLACE_METHOD(0x14031F530, DungeonRoundGroup, GetRound, 144, 0x042CDDBF);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool DungeonRoomTable::s_bInit;
#endif

// @0x14031f5d0
DungeonRoomTable::DungeonRoomTable() : m_periodDays(0)
{
    LoadConfig();
    LoadCoupons();
    LoadSeasons();
    LoadRoundGroups();
    LoadRooms();
    LoadRankRewards();
}

// @0x14031f770
DungeonRoomTable::~DungeonRoomTable()
{
}

// @0x14031f8a0
void DungeonRoomTable::LoadRooms()
{
    Clear();
    CString strPath = FUN_14071a5b0("Table", "DungeonRoom.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "dungeonRoom", "dungeonRoomID", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        DungeonRoomPtr pRoom(new DungeonRoom);
        pRoom->Load(nodes[i]);
        m_rooms[pRoom->GetDungeonRoomID()] = pRoom;
    }
    for (std::map<unsigned, DungeonRoomPtr>::iterator it = m_rooms.begin(); it != m_rooms.end(); it++)
        LinkRoom(it->second);
    SetInit(true);
}

// @0x14031fbf0
void DungeonRoomTable::LoadSeasons()
{
    m_seasons.clear();
    CString strPath = FUN_14071a5b0("Table", "DungeonSeason.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "DungeonSeason", "seasonID", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        MS2Ptr<DungeonSeason> pSeason(new DungeonSeason);
        if (!pSeason->Load(pNode))
            continue;
        m_seasons.push_back(pSeason);
    }
}
MS2_REPLACE_METHOD(0x14031FBF0, DungeonRoomTable, LoadSeasons, 645, 0xC71A8598);

// @0x14031fe80
void DungeonRoomTable::LoadConfig()
{
    CString strPath = FUN_14071a5b0("Table", "DungeonConfig.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    Unk_140165cf0* pConfig = pRoot->FUN_140165cf0("DungeonConfig");
    if (pConfig)
        LoadDungeonConfig(pConfig);
    Unk_140165cf0* pReverseRaid = pRoot->FUN_140165cf0("ReverseRaidConfig");
    if (pReverseRaid)
        LoadReverseRaidConfig(pReverseRaid);
    Unk_140165cf0* pWeekly = pRoot->FUN_140165cf0("UnitedWeeklyReward");
    if (pWeekly)
        LoadUnitedWeeklyRewards(pWeekly);
}
MS2_REPLACE_METHOD(0x14031FE80, DungeonRoomTable, LoadConfig, 450, 0x1832338C);

// @0x140320050
void DungeonRoomTable::LoadRankRewards()
{
    m_rankRewards.clear();
    CString strPath = FUN_14071a5b0("Table", "DungeonRankReward.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "DungeonRankReward", "rewardID", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        MS2Ptr<DungeonRankRewardBase> pReward(new DungeonRankRewardBase);
        if (!pReward->Load(pNode))
            continue;
        m_rankRewards.insert(std::make_pair(pReward->GetId(), pReward));
    }
}
MS2_REPLACE_METHOD(0x140320050, DungeonRoomTable, LoadRankRewards, 739, 0xA3832F10);

// @0x140320340
void DungeonRoomTable::LoadRoundGroups()
{
    m_roundGroups.clear();
    CString strPath = FUN_14071a5b0("Table", "DungeonRoundData.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "DungeonRoundGroup", "id", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        MS2Ptr<DungeonRoundGroup> pGroup(new DungeonRoundGroup);
        if (!pGroup->Load(pNode))
            continue;
        m_roundGroups.insert(std::make_pair(pGroup->m_id, pGroup));
    }
}
MS2_REPLACE_METHOD(0x140320340, DungeonRoomTable, LoadRoundGroups, 729, 0x6A3CC677);

// @0x140320620
void DungeonRoomTable::Clear()
{
    m_rooms.clear();
}
MS2_REPLACE_METHOD(0x140320620, DungeonRoomTable, Clear, 31, 0x664D8991);

// @0x140320650
DungeonRoomPtr DungeonRoomTable::GetRoom(int nDungeonId, int nIndex)
{
    unsigned nRoomId = MakeDungeonRoomId(nDungeonId, nIndex);
    return GetRoom(nRoomId);
}

// @0x1403206b0
DungeonRoomPtr DungeonRoomTable::GetRoom(unsigned nRoomId)
{
    CheckInit();
    std::map<unsigned, DungeonRoomPtr>::iterator it = m_rooms.find(nRoomId);
    if (it != m_rooms.end())
        return it->second;
    return 0;
}

// @0x140320770
DungeonRoomPtr DungeonRoomTable::GetRewardRoom(unsigned nRoomId)
{
    DungeonRoomPtr pRoom = GetRoom(nRoomId);
    if (pRoom == 0)
        return 0;
    if (pRoom->m_unionRewardID == 0)
        return pRoom;
    return GetRoom(pRoom->m_unionRewardID);
}

// @0x140320870
DungeonRoomPtr DungeonRoomTable::GetFirstRoom(unsigned nDungeonId)
{
    ATL::CAtlArray<unsigned> indices;
    GetRoomIndices(nDungeonId, indices);
    if (indices.IsEmpty())
        return 0;
    unsigned nIndex = indices[0];
    unsigned nRoomId = MakeDungeonRoomId(nDungeonId, nIndex);
    return GetRoom(nRoomId);
}

// @0x140320950
DungeonRoomPtr DungeonRoomTable::GetLastRoom(unsigned nDungeonId)
{
    ATL::CAtlArray<unsigned> indices;
    GetRoomIndices(nDungeonId, indices);
    if (indices.IsEmpty())
        return 0;
    unsigned nIndex = indices[indices.GetCount() - 1];
    unsigned nRoomId = MakeDungeonRoomId(nDungeonId, nIndex);
    return GetRoom(nRoomId);
}

// @0x140320a40
void DungeonRoomTable::GetRoomIndices(unsigned nDungeonId, ATL::CAtlArray<unsigned>& out)
{
    CheckInit();
    unsigned nFrom = MakeDungeonRoomId(nDungeonId, 1);
    unsigned nTo = MakeDungeonRoomId(nDungeonId, 999);
    std::map<unsigned, DungeonRoomPtr>::iterator it = m_rooms.lower_bound(nFrom);
    std::map<unsigned, DungeonRoomPtr>::iterator itEnd = m_rooms.upper_bound(nTo);
    for (; it != itEnd; it++)
    {
        DungeonRoomPtr pRoom = it->second;
        out.Add(pRoom->GetRoomIndex());
    }
}

// @0x140320b40
void DungeonRoomTable::GetRooms(unsigned nDungeonId, ATL::CAtlArray<DungeonRoomPtr>& out)
{
    CheckInit();
    unsigned nFrom = MakeDungeonRoomId(nDungeonId, 1);
    unsigned nTo = MakeDungeonRoomId(nDungeonId, 999);
    std::map<unsigned, DungeonRoomPtr>::iterator it = m_rooms.lower_bound(nFrom);
    std::map<unsigned, DungeonRoomPtr>::iterator itEnd = m_rooms.upper_bound(nTo);
    for (; it != itEnd; it++)
    {
        DungeonRoomPtr pRoom = it->second;
        out.Add(pRoom);
    }
}

// @0x140320c30
void DungeonRoomTable::GetRoomsForLevel(unsigned short nLevel, unsigned nGearScore, std::vector<DungeonRoomPtr>& out)
{
    DungeonRoomSet::reverse_iterator it = std::lower_bound(m_allRooms.rbegin(), m_allRooms.rend(), std::make_pair(nGearScore, nLevel), DungeonRoomLess());
    for (; it != m_allRooms.rend(); it++)
    {
        DungeonRoomPtr pRoom = *it;
        if (nLevel < pRoom->m_limitPlayerLevel)
            continue;
        out.push_back(*it);
    }
}
MS2_REPLACE_METHOD(0x140320C30, DungeonRoomTable, GetRoomsForLevel, 362, 0x6BA383D2);

// @0x140320da0
void DungeonRoomTable::GetMatchRooms(unsigned short nLevel, unsigned nGearScore, std::vector<DungeonRoomPtr>& out)
{
    DungeonRoomSet::reverse_iterator it = std::lower_bound(m_matchRooms.rbegin(), m_matchRooms.rend(), std::make_pair(nGearScore, nLevel), DungeonRoomLess());
    if ((unsigned)FUN_1401d3200()->DungeonMatchRecommendPickCount > 0)
        out.reserve((unsigned)FUN_1401d3200()->DungeonMatchRecommendPickCount);
    unsigned nCount = 0;
    for (; it != m_matchRooms.rend(); it++)
    {
        DungeonRoomPtr pRoom = *it;
        if (nLevel < pRoom->m_limitPlayerLevel)
            continue;
        out.push_back(*it);
        nCount++;
        if (FUN_1401d3200()->DungeonMatchRecommendPickCount != 0 && nCount >= (unsigned)FUN_1401d3200()->DungeonMatchRecommendPickCount)
            return;
    }
}
MS2_REPLACE_METHOD(0x140320DA0, DungeonRoomTable, GetMatchRooms, 466, 0xB930BA65);

// @0x140320f80
void DungeonRoomTable::GetGroupMatchRooms(DungeonGroupType nGroup, unsigned short nLevel, unsigned nGearScore, std::vector<DungeonRoomPtr>& out)
{
    DungeonRoomSet& rooms = GetGroupSet(nGroup);
    DungeonRoomSet::reverse_iterator it = std::lower_bound(rooms.rbegin(), rooms.rend(), std::make_pair(nGearScore, nLevel), DungeonRoomLess());
    if ((unsigned)FUN_1401d3200()->DungeonMatchRecommendPickCount > 0)
        out.reserve((unsigned)FUN_1401d3200()->DungeonMatchRecommendPickCount);
    unsigned nCount = 0;
    for (; it != rooms.rend(); it++)
    {
        DungeonRoomPtr pRoom = *it;
        if (nLevel < pRoom->m_limitPlayerLevel)
            continue;
        out.push_back(*it);
        nCount++;
        if (FUN_1401d3200()->DungeonMatchRecommendPickCount != 0 && nCount >= (unsigned)FUN_1401d3200()->DungeonMatchRecommendPickCount)
            return;
    }
}
MS2_REPLACE_METHOD(0x140320F80, DungeonRoomTable, GetGroupMatchRooms, 462, 0x4E6206A2);

// @0x140321160
void DungeonRoomTable::GetGroupRooms(DungeonGroupType nGroup, std::vector<DungeonRoomPtr>& out)
{
    DungeonRoomSet& rooms = GetGroupSet(nGroup);
    out.reserve(rooms.size());
    std::copy(rooms.begin(), rooms.end(), std::back_inserter(out));
}
MS2_REPLACE_METHOD(0x140321160, DungeonRoomTable, GetGroupRooms, 155, 0xDCD8C0B0);

// @0x140321210
void DungeonRoomTable::GetBossRankingRooms(ATL::CAtlList<DungeonRoomPtr>& out, DungeonGroupType nGroup)
{
    for (std::map<unsigned, DungeonRoomPtr>::iterator it = m_rooms.begin(); it != m_rooms.end(); it++)
    {
        DungeonRoomPtr pRoom = it->second;
        if (pRoom == 0)
            continue;
        if (pRoom->m_bossRanking != 0 && pRoom->m_groupType == nGroup)
        {
            BOOL bInserted = FALSE;
            for (POSITION pos = out.GetHeadPosition(); pos; out.GetNext(pos))
            {
                DungeonRoomPtr pOther = out.GetAt(pos);
                if (pOther->m_gearScore > pRoom->m_gearScore)
                {
                    out.InsertBefore(pos, pRoom);
                    bInserted = TRUE;
                    break;
                }
                else if (pOther->m_gearScore == pRoom->m_gearScore)
                {
                    if (pOther->m_dungeonRoomID > pRoom->m_dungeonRoomID)
                        out.InsertBefore(pos, pRoom);
                    else
                        out.InsertAfter(pos, pRoom);
                    bInserted = TRUE;
                    break;
                }
            }
            if (!bInserted)
                out.AddTail(pRoom);
        }
    }
}
MS2_REPLACE_METHOD(0x140321210, DungeonRoomTable, GetBossRankingRooms, 633, 0x89879EDF);

// @0x1403214a0
short DungeonRoomTable::GetSeasonId(const CMsTime& t)
{
    for (size_t i = 0; i < m_seasons.size(); i++)
    {
        if (m_seasons[i]->IsInPeriod(t))
            return m_seasons[i]->m_seasonID;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1403214A0, DungeonRoomTable, GetSeasonId, 157, 0xE0353E62);

// @0x140321550
MS2Ptr<DungeonSeason> DungeonRoomTable::GetCurrentSeason(const CMsTime& t)
{
    for (size_t i = 0; i < m_seasons.size(); i++)
    {
        if (m_seasons[i]->IsInPeriod(t))
            return m_seasons[i];
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140321550, DungeonRoomTable, GetCurrentSeason, 216, 0x38D55020);

// @0x140321630
MS2Ptr<DungeonSeason> DungeonRoomTable::GetSeason(short nSeasonId)
{
    for (size_t i = 0; i < m_seasons.size(); i++)
    {
        if (m_seasons[i]->m_seasonID == nSeasonId)
            return m_seasons[i];
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140321630, DungeonRoomTable, GetSeason, 210, 0x78EB63AE);

// @0x140321710
std::vector<DungeonRoomPtr>* DungeonRoomTable::GetRoomList()
{
    return &m_roomList;
}
MS2_REPLACE_METHOD(0x140321710, DungeonRoomTable, GetRoomList, 15, 0x5731F599);

// @0x140321730
int DungeonRoomTable::GetRank(DungeonRoom* pRoom, short nScore)
{
    std::map<unsigned, DungeonRankRequire>::iterator it = m_rankRequires.find(pRoom->GetRankTableID());
    if (it == m_rankRequires.end())
        return -1;
    if (nScore < 0)
        return -1;
    DungeonRankRequire& rankRequire = it->second;
    return rankRequire.GetRank(nScore);
}
MS2_REPLACE_METHOD(0x140321730, DungeonRoomTable, GetRank, 169, 0xF7059D92);

// @0x1403217e0
short DungeonRoomTable::GetMaxScore(DungeonRoom* pRoom)
{
    std::map<unsigned, DungeonRankRequire>::iterator it = m_rankRequires.find(pRoom->GetRankTableID());
    if (it == m_rankRequires.end())
        return 0;
    DungeonRankRequire& rankRequire = it->second;
    return rankRequire.GetMaxScore();
}
MS2_REPLACE_METHOD(0x1403217E0, DungeonRoomTable, GetMaxScore, 139, 0xF4CD0498);

// @0x140321880
DungeonRankRequire* DungeonRoomTable::GetRankRequire(DungeonRoom* pRoom)
{
    std::map<unsigned, DungeonRankRequire>::iterator it = m_rankRequires.find(pRoom->GetRankTableID());
    if (it == m_rankRequires.end())
        return 0;
    return &it->second;
}
MS2_REPLACE_METHOD(0x140321880, DungeonRoomTable, GetRankRequire, 124, 0x57031E63);

// @0x140321910
unsigned DungeonRoomTable::GetReverseRaidRoomID(const CMsTime& t)
{
    if (m_reverseRaidRooms.empty())
        return 0;
    if (m_startDate > t)
        return 0;
    if (m_periodDays <= 0)
        return 0;
    CTimeSpan span = t - m_startDate;
    int nDays = (int)span.GetDays();
    int nIndex = (nDays / m_periodDays) % (int)m_reverseRaidRooms.size();
    return m_reverseRaidRooms[nIndex];
}
MS2_REPLACE_METHOD(0x140321910, DungeonRoomTable, GetReverseRaidRoomID, 243, 0xE7293368);

// @0x140321a10
DungeonRoomPtr DungeonRoomTable::GetRoom1003()
{
    return GetRoom(1003);
}

// @0x140321a60
DungeonRoomPtr DungeonRoomTable::GetRoom1004()
{
    return GetRoom(1004);
}

// @0x140321ab0
DungeonRoomPtr DungeonRoomTable::GetRoom1007()
{
    return GetRoom(1007);
}

// @0x140321b00
MS2Ptr<DungeonRankRewardBase> DungeonRoomTable::GetRankReward(int nRewardId)
{
    std::map<unsigned, MS2Ptr<DungeonRankRewardBase> >::iterator it = m_rankRewards.find(reinterpret_cast<const unsigned&>(nRewardId));
    if (it != m_rankRewards.end())
        return it->second;
    return 0;
}
MS2_REPLACE_METHOD(0x140321B00, DungeonRoomTable, GetRankReward, 174, 0xC9FF7838);

// @0x140321bc0
size_t DungeonRoomTable::GetUnitedWeeklyRewardCount()
{
    return m_unitedWeeklyRewards.size();
}
MS2_REPLACE_METHOD(0x140321BC0, DungeonRoomTable, GetUnitedWeeklyRewardCount, 33, 0x3E4F0B3D);

// @0x140321bf0
MS2Ptr<DungeonUnitedWeeklyReward> DungeonRoomTable::GetUnitedWeeklyReward(size_t nIndex)
{
    if (nIndex >= m_unitedWeeklyRewards.size())
        return 0;
    return m_unitedWeeklyRewards[nIndex];
}
MS2_REPLACE_METHOD(0x140321BF0, DungeonRoomTable, GetUnitedWeeklyReward, 141, 0x28888CD4);

// @0x140321c90
MS2Ptr<DungeonUnitedWeeklyReward> DungeonRoomTable::FindUnitedWeeklyReward(unsigned nRewardCount)
{
    MS2_FOR_EACH(MS2Ptr<DungeonUnitedWeeklyReward> pReward, m_unitedWeeklyRewards)
    {
        if (pReward->m_rewardCount == nRewardCount)
            return pReward;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140321C90, DungeonRoomTable, FindUnitedWeeklyReward, 284, 0x6D0A0EAF);

// @0x140321dc0
void DungeonRoomTable::LinkRoom(DungeonRoomPtr pRoom)
{
    pRoom->m_pCoupon = GetCoupon(pRoom->m_extraRewardTicketTableID);
    if (pRoom->m_roundID != 0)
        pRoom->m_pRoundGroup = GetRoundGroup(pRoom->m_roundID);
    m_roomList.push_back(pRoom);
    AddToSets(pRoom);
}
MS2_REPLACE_METHOD(0x140321DC0, DungeonRoomTable, LinkRoom, 225, 0x592BB6F6);

// @0x140321eb0
void DungeonRoomTable::AddToSets(DungeonRoomPtr pRoom)
{
    if (pRoom == 0 || pRoom->m_groupType == 0)
        return;
    DungeonRoomSet& rooms = m_roomsByGroup[pRoom->m_groupType];
    rooms.insert(pRoom);
    switch (pRoom->m_groupType)
    {
    case 1:
    case 2:
        m_matchRooms.insert(pRoom);
    }
    m_allRooms.insert(pRoom);
}
MS2_REPLACE_METHOD(0x140321EB0, DungeonRoomTable, AddToSets, 272, 0x6270C810);

// @0x140321fd0
DungeonRoomSet& DungeonRoomTable::GetGroupSet(DungeonGroupType nGroup)
{
    return m_roomsByGroup[nGroup];
}
MS2_REPLACE_METHOD(0x140321FD0, DungeonRoomTable, GetGroupSet, 40, 0xCEE3254A);

// @0x140322000
void DungeonRoomTable::LoadCoupons()
{
    m_coupons.clear();
    CString strPath = FUN_14071a5b0("Table", "DungeonRewardCoupon.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("dungeonRewardCoupon"); pNode; pNode = pNode->FUN_140168650("dungeonRewardCoupon"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        MS2Ptr<DungeonRewardCoupon> pCoupon(new DungeonRewardCoupon);
        pCoupon->Load(pNode);
        m_coupons[pCoupon->GetId()] = pCoupon;
    }
}
MS2_REPLACE_METHOD(0x140322000, DungeonRoomTable, LoadCoupons, 591, 0x4C0173A8);

// @0x140322260
DungeonRewardCoupon* DungeonRoomTable::GetCoupon(int nCouponId)
{
    if (nCouponId == 0)
        return 0;
    std::map<unsigned, MS2Ptr<DungeonRewardCoupon> >::const_iterator it = m_coupons.find(reinterpret_cast<const unsigned&>(nCouponId));
    if (it == m_coupons.end())
        return 0;
    return it->second.get();
}
MS2_REPLACE_METHOD(0x140322260, DungeonRoomTable, GetCoupon, 132, 0x8F7D3E8C);

// @0x1403222f0
DungeonRoundGroup* DungeonRoomTable::GetRoundGroup(int nGroupId)
{
    std::map<unsigned, MS2Ptr<DungeonRoundGroup> >::const_iterator it = m_roundGroups.find(reinterpret_cast<const unsigned&>(nGroupId));
    if (it == m_roundGroups.end())
        return 0;
    return it->second.get();
}
MS2_REPLACE_METHOD(0x1403222F0, DungeonRoomTable, GetRoundGroup, 121, 0x003D0128);

// @0x140322370
bool DungeonRoomTable::LoadDungeonConfig(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pRank = pElem->FUN_140165cf0("MissionRank");
    if (pRank)
    {
        for (Unk_140165cf0* pGroup = pRank->FUN_140165cf0("group"); pGroup; pGroup = pGroup->FUN_140168650("group"))
        {
            unsigned nId = 0;
            FUN_140873220(pGroup, "id", nId);
            if (nId == 0)
                continue;
            DungeonRankRequire& rankRequire = m_rankRequires[nId];
            rankRequire.Load(pGroup);
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x140322370, DungeonRoomTable, LoadDungeonConfig, 194, 0x9149FF36);

// @0x140322440
bool DungeonRoomTable::LoadReverseRaidConfig(Unk_140165cf0* pElem)
{
    if (FUN_1406aeee0()->FUN_1406af020())
        return true;
    FUN_140873600(pElem, "startDate", m_startDate);
    FUN_1408731e0(pElem, "periodDays", m_periodDays);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("v"); pChild; pChild = pChild->FUN_140168650("v"))
    {
        unsigned nId = 0;
        FUN_140873220(pChild, "dungeonID", nId);
        if (nId != 0)
            m_reverseRaidRooms.push_back(nId);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140322440, DungeonRoomTable, LoadReverseRaidConfig, 227, 0x98C0173F);

// @0x140322530
bool DungeonRoomTable::LoadUnitedWeeklyRewards(Unk_140165cf0* pElem)
{
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("v"); pChild; pChild = pChild->FUN_140168650("v"))
    {
        MS2Ptr<DungeonUnitedWeeklyReward> pReward(new DungeonUnitedWeeklyReward);
        if (pReward->Load(pChild))
            m_unitedWeeklyRewards.push_back(pReward);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140322530, DungeonRoomTable, LoadUnitedWeeklyRewards, 233, 0x909D678D);

// @0x140322620
int ParseLimitType(const CString& str)
{
    if (str.IsEmpty())
        return 0;
    if (str.CompareNoCase("limitReward") == 0)
        return 1;
    else if (str.CompareNoCase("limitEnter") == 0)
        return 2;
    return 0;
}
MS2_REPLACE_OVERLOAD(0x140322620, int(const CString&), ParseLimitType, 96, 0x3688B029);

// @0x140322690
int ParseTypeABC(const CString& str)
{
    if (str.IsEmpty())
        return 0;
    if (str.CompareNoCase("typeA") == 0)
        return 1;
    else if (str.CompareNoCase("typeB") == 0)
        return 2;
    else if (str.CompareNoCase("typeC") == 0)
        return 3;
    return 0;
}
MS2_REPLACE_OVERLOAD(0x140322690, int(const CString&), ParseTypeABC, 125, 0x3C9C5715);

// @0x140322720
CStringW GetTypeABCName(int nType)
{
    switch (nType)
    {
    case 1:
        return L"typeA";
    case 2:
        return L"typeB";
    case 3:
        return L"typeC";
    }
    return L"";
}
MS2_REPLACE_OVERLOAD(0x140322720, CStringW(int), GetTypeABCName, 199, 0x60405D79);

// @0x1403227f0
DungeonBossRankingType ParseBossRankingType(const CString& str)
{
    if (str.IsEmpty())
        return (DungeonBossRankingType)0;
    if (str.CompareNoCase("kill") == 0)
        return (DungeonBossRankingType)1;
    else if (str.CompareNoCase("damage") == 0)
        return (DungeonBossRankingType)2;
    else if (str.CompareNoCase("killrumble") == 0)
        return (DungeonBossRankingType)3;
    else if (str.CompareNoCase("multikill") == 0)
        return (DungeonBossRankingType)4;
    else if (str.CompareNoCase("colosseum") == 0)
        return (DungeonBossRankingType)5;
    return (DungeonBossRankingType)0;
}
MS2_REPLACE_OVERLOAD(0x1403227F0, DungeonBossRankingType(const CString&), ParseBossRankingType, 186, 0x7F3276EF);
