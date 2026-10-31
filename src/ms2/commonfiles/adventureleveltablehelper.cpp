// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Adventure level table, its singleton helper and mission rows.
// MS2-UNIT: ?\adventureleveltablehelper.cpp
// MS2-RANGE: 0x140195470-0x1401a2e40 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140196e80 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140196f20 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140197220 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@0@AEAPEAU10@@Z 0x14019b180 ; unique
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@0@AEBV10@@Z 0x14019b200 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@@Z 0x14019b540 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14019b840 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14019b8f0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14019b910 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@1@@Z 0x14019bf80 ; manual: chain _Tree_iterator c040/c080/c0c0 -> _Tree_const_iterator bf00/bf40/bf80 -> unchecked c180/c1c0/c200
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019d090 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@Z 0x14019ddc0 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@@Z 0x14019e0e0 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_ALValue@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUUnk_ALValue@@@std@@PEAX@2@@Z 0x1401a05e0 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_ALValue@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_ALValue@@@std@@PEAX@2@XZ 0x1401a0c20 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_ALValue@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_ALValue@@@std@@PEAX@2@XZ 0x1401a0cc0 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_ALValue@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUUnk_ALValue@@@std@@PEAX@2@@Z 0x1401a0d60 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@UUnk_ALSetKey@@U?$less@UUnk_ALSetKey@@@std@@V?$allocator@UUnk_ALSetKey@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_ALSetKey@@@std@@@std@@@2@XZ 0x1401a16d0 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@XZ 0x1401a1ca0 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@@Z 0x1401a20f0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_ALSetKey@@U?$less@UUnk_ALSetKey@@@std@@V?$allocator@UUnk_ALSetKey@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_ALSetKey@@@std@@@std@@@2@V32@0@Z 0x1401a2680 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_ALSetKey@@U?$less@UUnk_ALSetKey@@@std@@V?$allocator@UUnk_ALSetKey@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_ALSetKey@@@std@@@std@@@2@V32@@Z 0x1401a2770 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@AEBI@Z 0x1401a2ac0 ; unique
// MS2-PINS-END tplpin
// hand pins from tplpin --simulate (w143)
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@AEAU?$pair@$$CBIUCAdventureLevelReward@@@1@1@Z 0x1401986e0
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14019c3f0
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14019c9b0
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@XZ 0x1401a05b0
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@@Z 0x1401a07a0
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@XZ 0x1401a0c60
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@XZ 0x1401a0d00
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@@Z 0x1401a0f20
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@XZ 0x1401a14a0
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@XZ 0x1401a15f0
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x1401a18e0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@0@Z 0x1401a2000
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x1401a17a0
// MS2-PIN: ??$destroy@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIUCAdventureLevelAbility@@@1@@Z 0x14019b580
// MS2-PIN: ??$addressof@$$CBU?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@YAPEBU?$pair@$$CBIUCAdventureLevelMission@@@0@AEBU10@@Z 0x14019b120
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@0@AEAPEAU10@@Z 0x14019b1e0
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@YAAEAU?$pair@$$CBIUCAdventureLevelReward@@@0@AEAU10@@Z 0x14019b7b0
// MS2-PIN: ??$forward@AEAV?$vector@IV?$allocator@I@std@@@std@@@std@@YAAEAV?$vector@IV?$allocator@I@std@@@0@AEAV10@@Z 0x14019b7c0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14019cb30
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019cb80
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14019cc10
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019cc60
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14019cd60
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14019ce80
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x1401a0180
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@2@XZ 0x1401a01c0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@2@XZ 0x1401a0200
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@XZ 0x1401a05c0
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@Z 0x1401a0880
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@PEAU32@@Z 0x1401a0b30
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@PEAU32@@Z 0x1401a0b90
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@XZ 0x1401a0c80
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@XZ 0x1401a0d20
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@Z 0x1401a1000
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140196c20
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140196c80
// MS2-PIN: ??$_Buynode@U?$pair@IUCAdventureLevelAbility@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@$$QEAU?$pair@IUCAdventureLevelAbility@@@1@@Z 0x1401974c0
// MS2-PIN: ??$_Buynode@U?$pair@IUCAdventureLevelMission@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@1@$$QEAU?$pair@IUCAdventureLevelMission@@@1@@Z 0x140197550
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140197b00
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIUCAdventureLevelAbility@@@1@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@@Z 0x140198a40
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIUCAdventureLevelReward@@@1@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@@Z 0x140199260
// MS2-PIN: ??$emplace_back@AEBI@?$vector@IV?$allocator@I@std@@@std@@QEAAXAEBI@Z 0x14019b710
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@1@@Z 0x14019c0c0 ; manual: chain _Tree_iterator c040/c080/c0c0 -> _Tree_const_iterator bf00/bf40/bf80 -> unchecked c180/c1c0/c200
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@1@@Z 0x14019c040 ; manual: chain _Tree_iterator c040/c080/c0c0 -> _Tree_const_iterator bf00/bf40/bf80 -> unchecked c180/c1c0/c200
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@1@@Z 0x14019bf00 ; manual: chain _Tree_iterator c040/c080/c0c0 -> _Tree_const_iterator bf00/bf40/bf80 -> unchecked c180/c1c0/c200
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x14019c660
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x14019c6c0
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@XZ 0x14019da00
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14019dbe0
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14019dc40
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@@Z 0x14019dd20
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@@Z 0x14019de60
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@2@XZ 0x1401a0240
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@2@XZ 0x1401a0300
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1401a11c0
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1401a1280
// MS2-PIN: ?begin@?$vector@IV?$allocator@I@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@2@XZ 0x1401a1740
// MS2-PIN: ?end@?$vector@IV?$allocator@I@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@2@XZ 0x1401a1fa0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@@Z 0x1401a2290
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@AEBI@Z 0x1401a2900
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@AEBI@Z 0x1401a29e0
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@AEAU?$pair@$$CBIUCAdventureLevelAbility@@@1@1@Z 0x140198020
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@0@AEAV10@@Z 0x14019b130
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@@Z 0x14019ec40
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x1401a0400
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x1401a0420
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x1401a0440
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1401a1220
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@XZ 0x1401a1d00
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@XZ 0x1401a1d60
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@XZ 0x1401a1e80
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@0@Z 0x1401a21a0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@0@Z 0x1401a2340
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@@Z 0x1401a2430
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@AEBI@Z 0x1401a2ba0
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@AEBI@Z 0x1401a2c60
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@SAPEAU?$pair@$$CBIUCAdventureLevelAbility@@@2@AEAU32@@Z 0x1401a2db0
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@SAPEAU?$pair@$$CBIUCAdventureLevelMission@@@2@AEAU32@@Z 0x1401a2dd0
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@AEAPEAU31@@Z 0x14019b340
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@XZ 0x14019d600
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@XZ 0x14019d840
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@Z 0x14019dcd0
// MS2-PIN: ??_G?$TSingleton@VCAdventureLevelTableHelper@@@@UEAAPEAXI@Z 0x1401957e0
// MS2-PIN: ??_GCAdventureLevelMissionData@@UEAAPEAXI@Z 0x140195820
// MS2-PIN: ??_GCAdventureLevelTableHelper@@UEAAPEAXI@Z 0x140195860
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBI@?$vector@IV?$allocator@I@std@@@std@@AEAAXAEBI@Z 0x1401976e0
// MS2-PIN: ??$_Emplace_reallocate@AEBI@?$vector@IV?$allocator@I@std@@@std@@QEAAPEAIQEAIAEBI@Z 0x1401977a0
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@AEBI@Z 0x1401a2c00
// MS2-PIN: ??_7CAdventureLevelTable@@6B?$TSingleton@VCAdventureLevelTable@@@@@ 0x142ceb9d8
// MS2-PIN: ??_7CAdventureLevelTable@@6B?$CValidData@VCAdventureLevelTable@@@@@ 0x142ceb9e8
// hand pins (w145): set<unsigned> / map<unsigned,unsigned> copies the loaders never call
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@_K@Z 0x1401a1c10
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@UUnk_ALSetKey@@U?$less@UUnk_ALSetKey@@@std@@V?$allocator@UUnk_ALSetKey@@@3@$0A@@std@@@std@@IEAAXXZ 0x1401a1340
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\adventureleveltablehelper.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "adventureleveltablehelper.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/filesystem.h"
#include <algorithm>
#include <utility>

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
bool FUN_14028f710(Unk_140165cf0*);
CString FUN_14015f710(Unk_140165cf0*, const char*, CString strDefault);   // string attribute (default by value)

int FUN_1408731a0(Unk_140165cf0*, const char*, unsigned short*);
int FUN_1408731e0(Unk_140165cf0*, const char*, int*);
int FUN_140873220(Unk_140165cf0*, const char*, unsigned*);
int FUN_140873360(Unk_140165cf0*, const char*, float*);
// An effect record (shared MS2Ptr<> glue with the other adventure-level skill records): CPtred + 0x18 bytes, kind at +0x30.
class Unk_ALSkillAttr : public CPtred
{
public:
    char m_pad_18[0x18];
    int m_nKind;
};
MS2_CHECK_OFFSET(Unk_ALSkillAttr, m_nKind, 0x30);
class Unk_ALSkillTable { public: MS2Ptr<Unk_ALSkillAttr> FUN_140aafef0(int nSkillId, unsigned short nLevel); };

extern bool DAT_143aac290;    // set once the table loaded
extern void* DAT_143aac278;   // the CAdventureLevelTable singleton
extern void* DAT_143aac288;   // the effect manager singleton
extern CAdventureLevelReward DAT_142ceae98;    // the exe's default rows
extern CAdventureLevelAbility DAT_142ceaea8;
extern CAdventureLevelMission DAT_142ceaec8;

#define s_defReward DAT_142ceae98
#define s_defAbility DAT_142ceaea8
#define s_defMission DAT_142ceaec8

// Attribute readers: the default is returned when the attribute is missing.
// @0x140197310
unsigned short FUN_140197310(Unk_140165cf0* pElem, const char* pszName, unsigned short nDefault)
{
    unsigned short nVal;
    if (FUN_1408731a0(pElem, pszName, &nVal) != 0)
        return nDefault;
    return nVal;
}

// @0x140197350
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault)
{
    int nVal;
    if (FUN_1408731e0(pElem, pszName, &nVal) != 0)
        return nDefault;
    return nVal;
}

// @0x140197390
unsigned FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned nDefault)
{
    unsigned nVal;
    if (FUN_140873220(pElem, pszName, &nVal) != 0)
        return nDefault;
    return nVal;
}

// @0x1401973d0
float FUN_1401973d0(Unk_140165cf0* pElem, const char* pszName, float fDefault)
{
    float fVal;
    if (FUN_140873360(pElem, pszName, &fVal) != 0)
        return fDefault;
    return fVal;
}

// @0x1401958b0
static Unk_ALSkillTable* GetEffectMgr()
{
    return (Unk_ALSkillTable*)DAT_143aac288;
}

// @0x1401958c0
// An empty body with two pointer arguments: the exe only spills rcx and rdx.
void FUN_1401958c0(void*, void*)
{
}

// @0x1401958d0
bool FUN_1401958d0(CAdventureLevelReward* p)
{
    return &DAT_142ceae98 == p;
}

// @0x140195aa0
bool FUN_140195aa0(CAdventureLevelAbility* p)
{
    return p == &DAT_142ceaea8;
}

// @0x140195ae0
bool FUN_140195ae0(CAdventureLevelMission* p)
{
    return p == &DAT_142ceaec8;
}

// @0x1401958a0
static CAdventureLevelTable* GetTable()
{
    return static_cast<CAdventureLevelTable*>(DAT_143aac278);
}

// @0x140195b20
static int ParseRewardType(const CString& str)
{
    if (str.CompareNoCase("statPoint") == 0)
        return 2;
    else if (str.CompareNoCase("item") == 0)
        return 1;
    return 0;
}

// @0x140195470
CAdventureLevelTableHelper::CAdventureLevelTableHelper()
{
    m_pCurrent = 0;
}

// @0x1401954b0
CAdventureLevelTableHelper::~CAdventureLevelTableHelper()
{
}

// @0x140195660
CAdventureLevelMissionData::CAdventureLevelMissionData()
{
    m_nId = 0;
    m_b1c = false;
    m_p20 = 0;
}

// @0x140195b80
CAdventureLevelTable::CAdventureLevelTable()
{
}

// @0x140195c60
CAdventureLevelTable::~CAdventureLevelTable()
{
}

// @0x14019d470
void FUN_14019d470(bool bLoaded)
{
    DAT_143aac290 = bLoaded;
}

// @0x140195d30
bool CAdventureLevelTable::LoadAll()
{
    if (!LoadUnused1())
        return false;
    if (!LoadUnused2())
        return false;
    if (!LoadReward())
        return false;
    if (!LoadAbility())
        return false;
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xfb) && !LoadMission())
        return false;
    FUN_14019d470(true);
    return true;
}

// @0x140195dd0
void* CAdventureLevelTable::FindUnused1(unsigned nKey, unsigned nSub)
{
    void* pFound = 0;
    return pFound;
}

// @0x140195e00
void* CAdventureLevelTable::FindUnused2(unsigned nKey)
{
    void* pFound = 0;
    return pFound;
}

// The two table loaders of the exe that load nothing.
// @0x1401961b0
bool CAdventureLevelTable::LoadUnused1()
{
    return true;
}

// @0x1401961a0
bool CAdventureLevelTable::LoadUnused2()
{
    return true;
}

// @0x140195e30
const CAdventureLevelReward* CAdventureLevelTable::GetReward(unsigned nLevel)
{
    std::map<unsigned, CAdventureLevelReward>::iterator it = m_mapReward.find(nLevel);
    if (it == m_mapReward.end())
        return &s_defReward;
    return &it->second;
}

// @0x140195ed0
const CAdventureLevelAbility* CAdventureLevelTable::GetAbility(unsigned nEffectId)
{
    std::map<unsigned, CAdventureLevelAbility>::iterator it = m_mapAbility.find(nEffectId);
    if (it == m_mapAbility.end())
        return &s_defAbility;
    return &it->second;
}

// @0x140196090
const CAdventureLevelMission* CAdventureLevelTable::GetMission(unsigned nMissionId)
{
    std::map<unsigned, CAdventureLevelMission>::iterator it = m_mapMission.find(nMissionId);
    if (it == m_mapMission.end())
        return &s_defMission;
    return &it->second;
}

// @0x140195f70
// The rewards up to nLevel (type 2 excluded) that are not in setClaimed yet.
// (0x140184350), while this obj pairs its copy with the in-unit look-alike 0x14019ca30 (another tree type, see 0x1401a2680)
int CAdventureLevelTable::CountUnclaimedRewards(unsigned nLevel, const std::set<unsigned>& setClaimed)
{
    int nCount = 0;
    for (std::vector<unsigned>::const_iterator it = m_vecLevels.begin(); it != m_vecLevels.end(); ++it) {
        if (*it > nLevel)
            break;
        const CAdventureLevelReward* pReward = GetReward(*it);
        if (pReward->m_nType == 2)
            continue;
        if (setClaimed.find(*it) != setClaimed.end())
            continue;
        nCount++;
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x140195F70, CAdventureLevelTable, CountUnclaimedRewards, 282, 0x9CFE52F9);

// @0x140196110
void CAdventureLevelTable::CollectMissionIds(std::vector<unsigned>& aOut) const
{
    for (std::map<unsigned, CAdventureLevelMission>::const_iterator it = m_mapMission.begin(); it != m_mapMission.end(); ++it)
        aOut.push_back(it->first);
}
MS2_REPLACE_METHOD(0x140196110, CAdventureLevelTable, CollectMissionIds, 124, 0xCF2F835F);

// @0x140195eb0
std::vector<unsigned>& CAdventureLevelTable::GetLevels()
{
    return m_vecLevels;
}

// @0x140195f50
std::vector<unsigned>& CAdventureLevelTable::GetAbilityIds()
{
    return m_vecAbilityIds;
}

// @0x140196b70  ability ids ordered by required level (ties keep file order)
static bool AbilityLess(const unsigned& a, const unsigned& b)
{
    const CAdventureLevelAbility* pA = GetTable()->GetAbility(a);
    const CAdventureLevelAbility* pB = GetTable()->GetAbility(b);
    if (pA->m_nRequireLevel == pB->m_nRequireLevel)
        return pA->m_nId < pA->m_nId;   // sic: the exe compares the first row with itself
    return pA->m_nRequireLevel < pB->m_nRequireLevel;
}

// @0x1401961c0
bool CAdventureLevelTable::LoadReward()
{
    CString strPath = FUN_14071a5b0("Table", "AdventureLevelReward.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("reward"); pNode != 0; pNode = pNode->FUN_140168650("reward"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nLevel = FUN_140197310(pNode, "level", 0);
        CAdventureLevelReward row;
        row.m_nType = ParseRewardType(FUN_14015f710(pNode, "type", CString("")).Trim());
        row.m_nId = FUN_140197390(pNode, "id", 0);
        row.m_nRank = FUN_140197350(pNode, "rank", 0);
        row.m_nValue = FUN_140197350(pNode, "value", 0);
        m_mapReward.insert(std::make_pair(nLevel, row));
        m_vecLevels.push_back(nLevel);
    }
    std::sort(m_vecLevels.begin(), m_vecLevels.end(), std::less<unsigned short>());
    return true;
}
MS2_REPLACE_METHOD(0x1401961C0, CAdventureLevelTable, LoadReward, 901, 0xD3A2F416);

// @0x140196550
bool CAdventureLevelTable::LoadAbility()
{
    CString strPath = FUN_14071a5b0("Table", "AdventureLevelAbility.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("ability"); pNode != 0; pNode = pNode->FUN_140168650("ability"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CAdventureLevelAbility row;
        row.m_nEffectId = FUN_140197390(pNode, "additionalEffectId", 0);
        row.m_nId = FUN_140197350(pNode, "id", 0);
        row.m_nRequireLevel = FUN_140197390(pNode, "requireLevel", 0);
        row.m_nInterval = FUN_140197350(pNode, "interval", 0);
        row.m_nMaxCount = FUN_140197350(pNode, "maxCount", 0);
        row.m_fStartValue = FUN_1401973d0(pNode, "startValue", 0);
        row.m_fAddValue = FUN_1401973d0(pNode, "addValue", 0);
        m_mapAbility.insert(std::make_pair(row.m_nEffectId, row));
        m_vecAbilityIds.push_back(row.m_nEffectId);
    }
    std::sort(m_vecAbilityIds.begin(), m_vecAbilityIds.end(), AbilityLess);
    return true;
}
MS2_REPLACE_METHOD(0x140196550, CAdventureLevelTable, LoadAbility, 848, 0x6F52A1EF);

// @0x1401968b0
bool CAdventureLevelTable::LoadMission()
{
    CString strPath = FUN_14071a5b0("Table", "AdventureLevelMission.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("mission"); pNode != 0; pNode = pNode->FUN_140168650("mission"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nId = FUN_140197390(pNode, "missionId", 0);
        CAdventureLevelMission row;
        row.m_nCount = FUN_140197390(pNode, "missionCount", 0);
        row.m_nOne = 1;
        row.m_nItemId = FUN_140197390(pNode, "itemId", 0);
        row.m_nItemRank = FUN_140197350(pNode, "itemRank", 0);
        row.m_nItemCount = FUN_140197350(pNode, "itemCount", 0);
        m_mapMission.insert(std::make_pair(nId, row));
    }
    return true;
}
MS2_REPLACE_METHOD(0x1401968B0, CAdventureLevelTable, LoadMission, 689, 0xABCA5713);

// @0x140195910
unsigned short CAdventureLevelAbility::GetCount(unsigned nLevel) const
{
    if (m_nId == 0)
        return 0;
    if (m_nInterval == 0)
        return (nLevel >= m_nRequireLevel) ? 1 : 0;
    if (nLevel < m_nRequireLevel)
        return 0;
    return (std::min)(((unsigned short)((nLevel - m_nRequireLevel + m_nInterval) / (unsigned)m_nInterval)), ((unsigned short)m_nMaxCount));
}
MS2_REPLACE_METHOD(0x140195910, CAdventureLevelAbility, GetCount, 175, 0x757B70A5);

// @0x1401959d0
int CAdventureLevelAbility::GetLevelOfCount(unsigned nLevel) const
{
    if (m_nId == 0)
        return 0;
    return (GetCount(nLevel) - 1) * m_nInterval + m_nRequireLevel;
}

// @0x140195a20
float CAdventureLevelAbility::GetPercent(unsigned nLevel) const
{
    if (m_nId == 0)
        return 0.0f;
    return (m_fStartValue + (float)(int)(GetCount(nLevel) - 1) * m_fAddValue) * 100.0f;
}

// @0x1401954e0
void CAdventureLevelTableHelper::FindCurrent()
{
    std::vector<unsigned>& ids = GetTable()->GetAbilityIds();
    for (std::vector<unsigned>::iterator it = ids.begin(); it != ids.end(); ++it)
    {
        const CAdventureLevelAbility* pAbility = GetTable()->GetAbility(*it);
        MS2Ptr<Unk_ALSkillAttr> spAttr = GetEffectMgr()->FUN_140aafef0(pAbility->m_nEffectId, 1);
        if (spAttr->m_nKind != 3)
            continue;
        m_pCurrent = const_cast<CAdventureLevelAbility*>(pAbility);
        break;
    }
}

// @0x1401955f0
bool CAdventureLevelTableHelper::IsReached(unsigned nLevel)
{
    if (m_pCurrent == 0)
        return false;
    return nLevel >= m_pCurrent->m_nRequireLevel;
}

// @0x140195640
CAdventureLevelAbility* CAdventureLevelTableHelper::GetCurrent()
{
    return m_pCurrent;
}

MS2_EMIT_CRT_MEMMOVE_S();

// The exe also carries the unused members of these containers (tree erase / destroy paths), instantiated by the table's
// ctor/dtor and loaders.
template class std::map<unsigned, CAdventureLevelAbility>;
template class std::map<unsigned, CAdventureLevelMission>;
template class std::map<unsigned, CAdventureLevelReward>;
template class std::map<unsigned, Unk_ALValue>;
template class std::set<Unk_ALSetKey>;

// The unused set / map members are cleared and erased by code the exe keeps but nothing here calls.
void Unk_ALTreeAnchor(std::set<Unk_ALSetKey>& s, std::map<unsigned, Unk_ALValue>& m)
{
    s.clear();
    m.clear();
    s.erase(s.begin());
    m.erase(m.begin());
}
