// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Guild definition container COMDAT tail #5b (std::map tree glue of the
// ten CGuildXmlData / guild maps: erase, buy-node, accessors). Same driver approach as guilddef_5.cpp.
// MS2-UNIT: unit_1404faed0
// MS2-RANGE: 0x1404faed0-0x1405021c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@2@XZ 0x1404fb1e0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fb2a0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@2@XZ 0x1404fb360 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fb420 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@UItemEntity@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@PEAX@2@XZ 0x1404fb4e0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fb5a0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@2@XZ 0x1404fb8e0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fb9c0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@2@XZ 0x1404fbaa0 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fbb80 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@UItemEntity@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@PEAX@2@XZ 0x1404fbc60 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fbd40 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1404fc3e0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1404fc420 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x1404fc4e0 ; hand: caller calls Getcomp const 502080
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x1404fc520 ; hand: caller calls Getcomp const 5020c0
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBU?$pair@HH@2@0@Z 0x1404fc560 ; hand: caller calls Getcomp const 502100
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1404fc460 ; hand: Getcomp const 502000
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1404fc4a0 ; hand
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x140502040 ; hand: const
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@U?$pair@HH@std@@@2@XZ 0x140502100 ; hand: const
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@2@@Z 0x1404fca80 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@2@@Z 0x1404fcad0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@2@@Z 0x1404fcb20 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@2@@Z 0x1404fcb70 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@UItemEntity@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@PEAX@2@@Z 0x1404fcbc0 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@2@@Z 0x1404fce50 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@2@@Z 0x1404fcef0 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@2@@Z 0x1404fcf90 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@2@@Z 0x1404fd030 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@UItemEntity@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@PEAX@2@@Z 0x1404fd0d0 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@2@@Z 0x1404fd170 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x140501470 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x140501480 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x140501490 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x1405014a0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x1405014d0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x1405014c0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x1405014d0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x1405014e0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x140501500 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x140501510 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@HH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@U?$pair@HH@std@@@2@XZ 0x140501520 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@_JH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@U?$pair@_JH@std@@@2@XZ 0x140501530 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@U?$pair@IH@std@@@2@XZ 0x140501540 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@U?$pair@IH@std@@@2@XZ 0x140501550 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@2@XZ 0x140501570 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@2@XZ 0x140501590 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@std@@@2@XZ 0x1405015d0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x1405015e0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@PEAX@std@@@2@XZ 0x1405016a0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@2@XZ 0x1405016f0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@2@XZ 0x140501700 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@2@$00@2@XZ 0x140501750 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@U?$pair@_JH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@@std@@@2@$00@2@XZ 0x140501870 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@2@XZ 0x1405018a0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@XZ 0x140501900 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@XZ 0x140501910 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@2@XZ 0x140501920 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@2@XZ 0x140501940 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@2@XZ 0x140501960 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@2@XZ 0x140501970 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@std@@@2@XZ 0x140501980 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@@std@@@2@XZ 0x1405019c0 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@QEBAAEBV?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@2@XZ 0x140501ec0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x140501f80 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x140501fa0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x140501fc0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x140501fe0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x140502020 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x140502060 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x1405020a0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x1405020c0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@U?$pair@HH@std@@@2@XZ 0x1405020e0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@UItemEntity@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@U?$pair@IH@std@@@2@XZ 0x140502120 ; prop
// MS2-PIN: ?_Calculate_growth@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEBA_K_K@Z 0x1404fbf00 ; unique: single byte-identical candidate
// MS2-PIN: ?_Change_array@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXQEAU?$pair@HH@2@_K1@Z 0x1404fc0b0 ; unique: single byte-identical candidate
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@XZ 0x140501140 ; prop: symbol ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair...
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x140502080 ; prop: caller ?_Compare@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CG...
// MS2-PINS-END tplpin
// MS2-PIN: ?_Copy_alloc@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@_JH@std@@UItemEntity@@U?$less@U?$pair@_JH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@@2@$0A@@std@@@std@@QEAAXAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@PEAX@std@@@2@@Z 0x1404fc800 ; hand: stale-free pin, exe order
// MS2-FUNCTIONAL 0x1404fc800: the exe function is map<unsigned long,int>::_Copy_alloc (calls that map's _Buyheadnode/_Freeheadnode 0x140263f30/0x140264f20); this unit has no such map copy, so the pair<__int64,int> ItemEntity copy stands in for the slot
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@_JH@std@@UItemEntity@@U?$less@U?$pair@_JH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@_JH@std@@UItemEntity@@@std@@@std@@@2@XZ 0x140501260 ; hand: stale-free pin, exe order
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$less@W4Unk_GuildNpcKind@@@std@@V?$allocator@W4Unk_GuildNpcKind@@@3@$0A@@std@@@std@@QEAAAEAU?$less@W4Unk_GuildNpcKind@@@2@XZ 0x1405021a0 ; hand: stale-free pin, exe order
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@2@XZ 0x1404fb8e0
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fb9c0
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@2@XZ 0x1404fbaa0
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fbb80
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fbd40
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x140502020
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x140502040
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x140502060
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x1405020a0
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x1405020c0
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@U?$pair@HH@std@@@2@XZ 0x1405020e0
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@UItemEntity@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@U?$pair@IH@std@@@2@XZ 0x140502120
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@2@XZ 0x1404fb1e0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@2@XZ 0x1404fb360
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fb420
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@UItemEntity@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@UItemEntity@@@std@@PEAX@2@XZ 0x1404fb4e0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@2@XZ 0x1404fb5a0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@2@XZ 0x140501570
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@2@XZ 0x140501590
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@std@@@2@XZ 0x1405015d0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x1405015e0
// MS2-PIN: ?_Change_array@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXQEAU?$pair@HH@2@_K1@Z 0x1404fc0b0
// hand pins (w107, from tplpin proposals after adding deque/set drivers)
// MS2-PIN: ?_Destroy@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXPEAU?$pair@HH@2@0@Z 0x1404fc920 ; hand: bytematch OK
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$less@W4Unk_GuildNpcKind@@@std@@V?$allocator@W4Unk_GuildNpcKind@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@2@XZ 0x1404fbe20 ; prop: symbols.tsv
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@W4Unk_GuildNpcKind@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@std@@@2@XZ 0x1405016b0 ; unique: caller ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$...
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$Unk_PayloadPtr@VCGuildStroageHistory@CGuildStorage@@@@@std@@V?$_Deque_val@U?$_Deque_simple_types@V?$Unk_PayloadPtr@VCGuildStroageHistory@CGuildStorage@@@@@std@@@2@$00@std@@QEAAAEAV?$_Deque_val@U?$_Deque_simple_types@V?$Unk_PayloadPtr@VCGuildStroageHistory@CGuildStorage@@@@@std@@@2@XZ 0x140501a20 ; unique: caller ?_Get_data@?$_Deque_alloc@U?$_Deque_base_types@V?$Unk_PayloadPtr@V...
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$Unk_PayloadPtr@VCGuildStroageHistory@CGuildStorage@@@@@std@@V?$_Deque_val@U?$_Deque_simple_types@V?$Unk_PayloadPtr@VCGuildStroageHistory@CGuildStorage@@@@@std@@@2@$00@std@@QEBAAEBV?$_Deque_val@U?$_Deque_simple_types@V?$Unk_PayloadPtr@VCGuildStroageHistory@CGuildStorage@@@@@std@@@2@XZ 0x140501a30 ; unique: caller ?_Get_data@?$_Deque_alloc@U?$_Deque_base_types@V?$Unk_PayloadPtr@V...
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\guilddef.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/guilddef_4.h"
#include "hook/ms2hook.h"
#include <atlcoll.h>
#include <algorithm>
#include <new>
#include <typeinfo>
CString FUN_14016a5c0(const char* psz, int n);

// This range holds no original (non-COMDAT) function: it is the sorted tail of the standard-library and ATL
// instantiations of guilddef.cpp (tree and CAtlMap operations). The instances come from the code of the other
// guilddef.cpp parts, which are separate sources here, so the container operations are driven from the functions below.
using namespace guilddef4;
typedef ATL::CAtlArray<TP<CGuildMember>> MemberArray;   // CGuildInfo member list (Add/GrowBuffer only)

template<class M,class K> void Unk_DriveMap7(M& m,const K& key){
    typename M::iterator it=m.find(key);
    if(it!=m.end()) it->second;
    m[key];
    m.clear();
}
CGuildXmlData* Unk_GuildDriveSingleton7() { return CGuildXmlData::GetInstance(); }
void Unk_GuildDriveMaps7(MapEvent& a,MapProperty& b,MapReward& c,MapSkill& d,MapRaid& e,MapShop& f,MapHouse& g,
                         MapStorage& h,MapNpc& i,MapStorage2& j){
    Unk_DriveMap7(a,0); Unk_DriveMap7(b,0); Unk_DriveMap7(c,0); Unk_DriveMap7(d,0); Unk_DriveMap7(e,0u);
    Unk_DriveMap7(f,0u); Unk_DriveMap7(g,std::pair<int,int>()); Unk_DriveMap7(h,std::pair<unsigned,int>());
    Unk_DriveMap7(i,std::pair<Unk_GuildNpcKind,int>()); Unk_DriveMap7(j,std::pair<__int64,int>());
}

// Iterator / lookup / modifier operations of the tree maps.
template<class M,class K> void Unk_DriveMapOps7(M& m,M& other,const K& key,const typename M::value_type& value){
    typedef typename M::iterator I; typedef typename M::const_iterator CI;
    for(I it=m.begin();it!=m.end();++it){ (void)*it; (void)it->first; --it; ++it; it++; }
    for(CI it=m.begin();it!=m.end();++it){ (void)*it; (void)it->first; --it; ++it; }
    const M& cm=m;
    CI c=cm.find(key); (void)c;
    (void)m.count(key); (void)m.lower_bound(key); (void)m.upper_bound(key); (void)m.equal_range(key);
    (void)cm.lower_bound(key); (void)cm.upper_bound(key); (void)cm.equal_range(key);
    m.erase(m.begin()); m.erase(key); m.erase(m.begin(),m.end());
    m.insert(value); m.insert(m.begin(),value); m.emplace(value); m.emplace_hint(m.begin(),value);
    other=m; M copy(m); m.swap(copy); (void)m.size(); (void)m.empty();
    (void)m.rbegin(); (void)m.rend();
}
void Unk_GuildDriveMapOps7(MapEvent& a,MapEvent& a2,MapProperty& b,MapProperty& b2,MapReward& c,MapReward& c2,
                           MapSkill& d,MapSkill& d2,MapRaid& e,MapRaid& e2,MapShop& f,MapShop& f2,MapHouse& g,MapHouse& g2,
                           MapStorage& h,MapStorage& h2,MapNpc& i,MapNpc& i2,MapStorage2& j,MapStorage2& j2){
    Unk_DriveMapOps7(a,a2,0,MapEvent::value_type()); Unk_DriveMapOps7(b,b2,0,MapProperty::value_type());
    Unk_DriveMapOps7(c,c2,0,MapReward::value_type()); Unk_DriveMapOps7(d,d2,0,MapSkill::value_type());
    Unk_DriveMapOps7(e,e2,0u,MapRaid::value_type()); Unk_DriveMapOps7(f,f2,0u,MapShop::value_type());
    Unk_DriveMapOps7(g,g2,std::pair<int,int>(),MapHouse::value_type());
    Unk_DriveMapOps7(h,h2,std::pair<unsigned,int>(),MapStorage::value_type());
    Unk_DriveMapOps7(i,i2,std::pair<Unk_GuildNpcKind,int>(),MapNpc::value_type());
    Unk_DriveMapOps7(j,j2,std::pair<__int64,int>(),MapStorage2::value_type());
}

// CAtlMap / CAtlArray / CRBMap operations of the guild info containers.
template<class M,class K,class V> void Unk_DriveAtlMap7(M& m,const K& key,const V& value){
    V out;
    (void)m.Lookup(key,out);
    (void)m.Lookup(key);
    m.SetAt(key,value);
    m[key]=value;
    (void)m.RemoveKey(key);
    ATL::CAtlMap<K,V>* none=0; (void)none;
    POSITION pos=m.GetStartPosition();
    K k=key; V v=value;
    while(pos){ m.GetNextAssoc(pos,k,v); }
    pos=m.GetStartPosition(); (void)m.GetNext(pos);
    pos=m.GetStartPosition(); (void)m.GetNextValue(pos);
    pos=m.GetStartPosition(); (void)m.GetNextKey(pos);
    pos=m.GetStartPosition(); (void)m.GetValueAt(pos); (void)m.GetKeyAt(pos); m.SetValueAt(pos,value); m.RemoveAtPos(pos);
    (void)m.GetCount(); (void)m.IsEmpty();
    m.SetOptimalLoad(0.0f,0.0f,0.0f,false);
    m.RemoveAll();
}
void Unk_GuildDriveAtl7(AtlStrMap& a,AtlEventMap& b,AtlSkillMap& c,AtlNpcMap& d){
    Unk_DriveAtlMap7(a,0,Unk_GuildStrEntry());
    Unk_DriveAtlMap7(b,0,TP<CGuildCustomEvent>());
    Unk_DriveAtlMap7(c,0,TP<CGuildSkill>());
    Unk_DriveAtlMap7(d,Unk_GuildNpcKind_None,TP<CGuildNpc>());
}

template<class A,class T> void Unk_DriveAtlArray7(A& a,const T& x){
    a.Add(x); a.SetCount(2); a.SetCount(0,4); (void)a.GetCount(); (void)a.IsEmpty(); (void)a.GetAt(0); a.SetAt(0,x);
    (void)a[0]; (void)a.GetData(); a.InsertAt(0,x); a.InsertAt(0,x,2); a.RemoveAt(0); a.RemoveAt(0,2); a.SetAtGrow(1,x);
    a.Append(a); a.Copy(a); a.RemoveAll(); a.FreeExtra();
}
void Unk_GuildDriveArray7(GradeArray& a,HistArray& b,MemberArray& c){
    Unk_DriveAtlArray7(a,TP<CGuildGrade>());
    Unk_DriveAtlArray7(b,TP<Hist>());
    c.Add(TP<CGuildMember>());
}
void Unk_GuildDriveVectors7(std::vector<int>& a,SkillVec& b,ProductVec& c,MapProperty& d){
    (void)a[0]; (void)b[0]; (void)c[0];
    b.push_back(b[0]); c.push_back(c[0]); b.reserve(4); c.reserve(4); b.resize(2); c.resize(2);
    b.shrink_to_fit(); c.shrink_to_fit(); b.clear(); c.clear();
    MapProperty::reverse_iterator r=d.rbegin(); (void)r->first; r++;
}
template<class M,class K,class V> void Unk_DriveRBMap7(M& m,const K& key,const V& value){
    V out; K k=key; V v=value;
    (void)m.Lookup(key,out); (void)m.Lookup(key);
    m.SetAt(key,value);
    (void)m.RemoveKey(key); (void)m.GetCount(); (void)m.IsEmpty();
    POSITION pos=m.GetHeadPosition(); (void)m.GetNext(pos); (void)m.GetPrev(pos);
    pos=m.GetHeadPosition(); m.GetNextAssoc(pos,k,v);
    pos=m.GetHeadPosition(); (void)m.GetNextValue(pos); (void)m.GetNextKey(pos);
    pos=m.GetHeadPosition(); (void)m.GetKeyAt(pos); (void)m.GetValueAt(pos); m.SetValueAt(pos,value); m.RemoveAt(pos);
    (void)m.GetTailPosition(); (void)m.FindFirstKeyAfter(key);
    (void)m.GetAt(pos);
    m.RemoveAll();
}
void Unk_GuildDriveRB7(MemberRBMap& m,AtlLocalMap& l){
    Unk_DriveRBMap7(m,CStringW(),TP<CGuildMember>());
    Unk_DriveAtlMap7(l,(__int64)0,(__int64)0);
}


// vector<pair<int,int>> (8 byte elements; guilddef's emplace_reallocate calls this unit's _Change_array/_Calculate_growth).
void Unk_GuildDrivePairVec7(std::vector<std::pair<int,int>>& a){
    a.push_back(a[0]); a.reserve(4); a.resize(2); a.shrink_to_fit(); a.clear();
    std::vector<std::pair<int,int>> b(a); b = a; b.swap(a); b.assign(a.begin(), a.end());
}

// CGuildStorage history deque (std::deque<TP<Hist>>) operations whose COMDATs sit in this tail.
void Unk_GuildDriveHistDeque7(HistDeque& a, HistDeque& b){
    a.push_back(a[0]); a.push_front(a[0]); a.pop_back(); a.pop_front();
    (void)a.front(); (void)a.back(); (void)a.size(); (void)a.empty();
    a.resize(2); a.shrink_to_fit(); a.erase(a.begin()); a.erase(a.begin(), a.end());
    a.insert(a.begin(), a[0]); a = b; HistDeque c(a); c.swap(a); a.clear();
}
void Unk_GuildDriveNpcKindSet7(SetNpcKind& a, SetNpcKind& b, const Unk_GuildNpcKind& k){
    (void)a.find(k); (void)a.count(k); a.insert(k); a.erase(k); a.erase(a.begin()); a.clear();
    b = a; SetNpcKind c(a); c.swap(a); (void)a.lower_bound(k); (void)a.upper_bound(k); (void)a.size(); (void)a.empty();
    for(SetNpcKind::iterator it=a.begin(); it!=a.end(); ++it){ (void)*it; }
}
// MS2-PIN: ?pointer_to@?$pointer_traits@PEBU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@SAPEBU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@2@AEBU32@@Z 0x1405013b0 ; hand: calls addressof<const pair<const int, GuildEvent>> 0x1405019e0
// MS2-PIN: ?pointer_to@?$pointer_traits@PEBU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@SAPEBU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@2@AEBU32@@Z 0x1405013d0 ; hand: calls addressof<const pair<const int, GuildProperty>> 0x1405019f0
