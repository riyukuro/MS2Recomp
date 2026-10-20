// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CAchieveData / CAchieveGradeData: the achievement table
// (Achieve\*.xml loader, lookups, reward maps). The second obj of the old `?\achievecondition.cpp` range
// (0x14015b490-0x14016da90, 24 own functions and a mangled-name-sorted COMDAT zone of ATL / STL / fmt / TinyXML
// inline instances first used here) plus the six global initializers of the table statics.
// MS2-UNIT: ?\achievedata.cpp
// MS2-RANGE: 0x14015b490-0x14016da90 .text$mn
// MS2-RANGE: 0x1400b21d0-0x1400b2330 .text$di
// MS2-RANGE: 0x142c99fc0-0x142c9a080 .text$yd
// MS2-PIN: ??_7CAchieveData@@6B?$CValidData@VCAchieveData@@@@@ 0x142ce68d0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_lock@@YAXXZ 0x1400b2250 ; prop
// MS2-PIN: ??__Es_mapStat@@YAXXZ 0x1400b2300 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@PEAVUnk_XmlNode@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVUnk_XmlNode@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14015e210 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14015e240 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14015e270 ; prop
// MS2-PIN: ??$?0AEAIAEAH$0A@@?$pair@IH@std@@QEAA@AEAIAEAH@Z 0x14015e2a0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@1@$$QEA_N@Z 0x14015e2f0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14015e340 ; prop
// MS2-PIN: ??$?0AEAJAEAI$0A@@?$pair@JI@std@@QEAA@AEAJAEAI@Z 0x14015e390 ; prop
// MS2-PIN: ??$?0AEBU?$less@U?$pair@IH@std@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@U?$pair@IH@std@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14015e3e0 ; prop
// MS2-PIN: ??$?0AEBU?$less@U?$pair@IH@std@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@U?$pair@IH@std@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x14015e430 ; prop
// MS2-PIN: ??$?0AEBU?$pair@IH@std@@$0A@@?$tuple@AEBU?$pair@IH@std@@@std@@QEAA@AEBU?$pair@IH@1@@Z 0x14015e520 ; unique
// MS2-PIN: ??$?0AEBU?$pair@IH@std@@@?$_Tuple_val@AEBU?$pair@IH@std@@@std@@QEAA@AEBU?$pair@IH@1@@Z 0x14015e570 ; unique
// MS2-PIN: ??$?0U_Exact_args_t@std@@AEBU?$pair@IH@1@$$V$0A@@?$tuple@AEBU?$pair@IH@std@@@std@@QEAA@U_Exact_args_t@1@AEBU?$pair@IH@1@@Z 0x14015e610 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@1@$$QEA_N@Z 0x14015e670 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@1@$$QEA_N@Z 0x14015e6c0 ; prop
// MS2-PIN: ??$?4JI$0A@@?$pair@HH@std@@QEAAAEAU01@$$QEAU?$pair@JI@1@@Z 0x14015e7e0 ; unique
// MS2-PIN: ??$_Allocate@$0BA@U_Default_allocate_traits@std@@$0A@@std@@YAPEAX_K@Z 0x14015f9d0 ; unique
// MS2-PIN: ??$_Allocate_manually_vector_aligned@U_Default_allocate_traits@std@@@std@@YAPEAX_K@Z 0x14015fa10 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBU?$pair@IH@std@@H@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBU?$pair@IH@std@@H@1@@Z 0x14015faa0 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@1@@Z 0x14015fac0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBU?$pair@IH@std@@@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBU?$pair@IH@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x14015fae0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBU?$pair@IH@std@@@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBU?$pair@IH@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x14015fbb0 ; prop
// MS2-PIN: ??$_Destroy_range1@V?$allocator@PEAVUnk_XmlNode@@@std@@@std@@YAXPEAPEAVUnk_XmlNode@@0AEAV?$allocator@PEAVUnk_XmlNode@@@0@U?$integral_constant@_N$00@0@@Z 0x14015fcc0 ; unique
// MS2-PIN: ??$_Destroy_range@V?$allocator@PEAVUnk_XmlNode@@@std@@@std@@YAXPEAPEAVUnk_XmlNode@@0AEAV?$allocator@PEAVUnk_XmlNode@@@0@@Z 0x14015fce0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@1@PEAU01@@Z 0x14015fd30 ; prop
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@1@PEAU01@@Z 0x14015fdc0 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBU?$pair@IH@std@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@AEAU?$pair@$$CBU?$pair@IH@std@@H@1@1@Z 0x14015fef0 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@AEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@1@1@Z 0x140160250 ; prop
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBU?$pair@IH@std@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@1@AEAU?$pair@$$CBU?$pair@IH@std@@H@1@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@@Z 0x1401605b0 ; prop
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@1@AEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@1@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@@Z 0x1401611f0 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBU?$pair@IH@std@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBU?$pair@IH@std@@H@1@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@@Z 0x140161e30 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@1@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@@Z 0x140162240 ; prop
// MS2-PIN: ??$_Kfn@$$CBU?$pair@IH@std@@H@?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@SAAEBU?$pair@IH@1@AEBU?$pair@$$CBU?$pair@IH@std@@H@1@@Z 0x140162650 ; prop
// MS2-PIN: ??$_Kfn@$$CBU?$pair@IH@std@@U?$pair@HH@2@@?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@SAAEBU?$pair@IH@1@AEBU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@1@@Z 0x140162660 ; prop
// MS2-PIN: ??$_Lbound@U?$pair@IH@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@AEBU?$pair@IH@1@@Z 0x140162670 ; prop
// MS2-PIN: ??$_Lbound@U?$pair@IH@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@AEBU?$pair@IH@1@@Z 0x140162710 ; prop
// MS2-PIN: ??$_Try_emplace@AEBU?$pair@IH@std@@$$V@?$map@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@_N@1@AEBU?$pair@IH@1@@Z 0x1401627b0 ; prop
// MS2-PIN: ??$_Try_emplace@AEBU?$pair@IH@std@@$$V@?$map@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@_N@1@AEBU?$pair@IH@1@@Z 0x140162900 ; prop
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@0@AEAPEAU10@@Z 0x140162a60 ; prop
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@0@AEAPEAU10@@Z 0x140162a70 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@YAPEAU?$pair@$$CBU?$pair@IH@std@@H@0@AEAU10@@Z 0x140162a80 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@YAPEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@0@AEAU10@@Z 0x140162a90 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@0@AEAV10@@Z 0x140162aa0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@0@AEAV10@@Z 0x140162ab0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@AEAPEAU31@@Z 0x140162ac0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@AEAPEAU31@@Z 0x140162b10 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBU?$pair@IH@std@@H@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBU?$pair@IH@std@@@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@1@QEAU?$pair@$$CBU?$pair@IH@std@@H@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBU?$pair@IH@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x140162b60 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBU?$pair@IH@std@@@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@1@QEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBU?$pair@IH@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x140162c10 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@@Z 0x140162cc0 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@@Z 0x140162cd0 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBU?$pair@IH@std@@H@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@1@QEAU?$pair@$$CBU?$pair@IH@std@@H@1@@Z 0x140162ce0 ; prop
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBU?$pair@IH@std@@@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBU?$pair@IH@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x140162d00 ; prop
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBU?$pair@IH@std@@@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBU?$pair@IH@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x140162da0 ; prop
// MS2-PIN: ??$forward@AEAH@std@@YAAEAHAEAH@Z 0x140162e40 ; prop
// MS2-PIN: ??$forward@AEAI@std@@YAAEAIAEAI@Z 0x140162e50 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@0@AEAPEAU10@@Z 0x140162e60 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@0@AEAPEAU10@@Z 0x140162e70 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@YAAEAU?$pair@$$CBU?$pair@IH@std@@H@0@AEAU10@@Z 0x140162e80 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@YAAEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@0@AEAU10@@Z 0x140162e90 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@0@AEAV10@@Z 0x140162ea0 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@0@AEAV10@@Z 0x140162eb0 ; prop
// MS2-PIN: ??$forward@AEAJ@std@@YAAEAJAEAJ@Z 0x140162ec0 ; prop
// MS2-PIN: ??$forward@AEBU?$less@U?$pair@IH@std@@@std@@@std@@YAAEBU?$less@U?$pair@IH@std@@@0@AEBU10@@Z 0x140162ed0 ; prop
// MS2-PIN: ??$forward@AEBU?$pair@IH@std@@@std@@YAAEBU?$pair@IH@0@AEBU10@@Z 0x140162ee0 ; prop
// MS2-PIN: ??$forward@AEBUpiecewise_construct_t@std@@@std@@YAAEBUpiecewise_construct_t@0@AEBU10@@Z 0x140162ef0 ; prop
// MS2-PIN: ??$forward@I@std@@YA$$QEAIAEAI@Z 0x140162f00 ; prop
// MS2-PIN: ??$forward@U_Zero_then_variadic_args_t@std@@@std@@YA$$QEAU_Zero_then_variadic_args_t@0@AEAU10@@Z 0x140162f10 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@0@AEAV10@@Z 0x140162f20 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@0@AEAV10@@Z 0x140162f30 ; prop
// MS2-PIN: ??$forward@V?$tuple@$$V@std@@@std@@YA$$QEAV?$tuple@$$V@0@AEAV10@@Z 0x140162f40 ; prop
// MS2-PIN: ??$forward@V?$tuple@AEBU?$pair@IH@std@@@std@@@std@@YA$$QEAV?$tuple@AEBU?$pair@IH@std@@@0@AEAV10@@Z 0x140162f50 ; prop
// MS2-PIN: ??$forward@J@std@@YA$$QEAJAEAJ@Z 0x140162f60 ; prop
// MS2-PIN: ??$forward@_N@std@@YA$$QEA_NAEA_N@Z 0x140162f70 ; prop
// MS2-PIN: ??$forward_as_tuple@$$V@std@@YA?AV?$tuple@$$V@0@XZ 0x140162f80 ; prop
// MS2-PIN: ??$forward_as_tuple@AEBU?$pair@IH@std@@@std@@YA?AV?$tuple@AEBU?$pair@IH@std@@@0@AEBU?$pair@IH@0@@Z 0x140162fa0 ; unique
// MS2-PIN: ??$get@$0A@AEBU?$pair@IH@std@@@std@@YAAEBU?$pair@IH@0@$$QEAV?$tuple@AEBU?$pair@IH@std@@@0@@Z 0x140162fd0 ; unique
// MS2-PIN: ??$make_pair@AEAIAEAH@std@@YA?AU?$pair@IH@0@AEAIAEAH@Z 0x140162ff0 ; unique
// MS2-PIN: ??$make_pair@AEAJAEAI@std@@YA?AU?$pair@JI@0@AEAJAEAI@Z 0x140163040 ; prop
// MS2-PIN: ??$move@AEAD@std@@YA$$QEADAEAD@Z 0x1401630f0 ; prop
// MS2-PIN: ??$swap@DX@std@@YAXAEAD0@Z 0x140163110 ; unique
// MS2-PIN: ??$try_emplace@$$V@?$map@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@_N@1@AEBU?$pair@IH@1@@Z 0x140163160 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@_N@1@AEBU?$pair@IH@1@@Z 0x1401631a0 ; prop
// MS2-PIN: ??0?$CA2WEX@$0IA@@ATL@@QEAA@PEBDI@Z 0x1401631e0 ; unique
// MS2-PIN: ??0?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAA@XZ 0x140163230 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@U?$pair@IH@std@@@1@@Z 0x140163980 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@U?$pair@IH@std@@@1@@Z 0x1401639b0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@U?$pair@IH@std@@@1@@Z 0x1401639e0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@U?$pair@IH@std@@@1@@Z 0x140163a20 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@1@@Z 0x140163a60 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEAA@XZ 0x140163aa0 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@1@@Z 0x140163ac0 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEAA@XZ 0x140163b00 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@1@@Z 0x140163b20 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@1@@Z 0x140163b60 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@1@@Z 0x140163ba0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140163be0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@1@@Z 0x140163c00 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140163c40 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@QEAA@XZ 0x140163c60 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@QEAA@XZ 0x140163c90 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_XmlNode@@V?$allocator@PEAVUnk_XmlNode@@@std@@@std@@@std@@QEAA@XZ 0x140163cc0 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@PEAVUnk_XmlNode@@@std@@@std@@QEAA@XZ 0x140163cf0 ; unique
// MS2-PIN: ??0?$allocator@PEAVUnk_XmlNode@@@std@@QEAA@XZ 0x140163d30 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@QEAA@XZ 0x140163d40 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@QEAA@XZ 0x140163d50 ; prop
// MS2-PIN: ??0?$map@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@@std@@QEAA@XZ 0x140163d60 ; prop
// MS2-PIN: ??0?$map@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@@std@@QEAA@XZ 0x140163d90 ; prop
// MS2-PIN: ??0?$tuple@$$V@std@@QEAA@XZ 0x140163dd0 ; prop
// MS2-PIN: ??0?$tuple@AEBU?$pair@IH@std@@@std@@QEAA@$$QEAV01@@Z 0x140163de0 ; unique
// MS2-PIN: ??0?$vector@PEAVUnk_XmlNode@@V?$allocator@PEAVUnk_XmlNode@@@std@@@std@@QEAA@XZ 0x140163e20 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x140164410 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x140164440 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x140164470 ; prop
// MS2-PIN: ??1?$map@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@@std@@QEAA@XZ 0x1401644c0 ; prop
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1401646e0 ; prop
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140164720 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140164760 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1401647a0 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@1@_K@Z 0x140164930 ; unique
// MS2-PIN: ??A?$map@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@@std@@QEAAAEAHAEBU?$pair@IH@1@@Z 0x1401649b0 ; prop
// MS2-PIN: ??A?$map@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@@std@@QEAAAEAU?$pair@HH@1@AEBU?$pair@IH@1@@Z 0x1401649f0 ; prop
// MS2-PIN: ??B?$CA2WEX@$0IA@@ATL@@QEBAPEA_WXZ 0x140164a60 ; order
// MS2-PIN: ??B?$CW2AEX@$0IA@@ATL@@QEBAPEADXZ 0x140164a70 ; order
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBU?$pair@IH@std@@H@1@XZ 0x140164a90 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@1@XZ 0x140164ab0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBU?$pair@IH@std@@H@1@XZ 0x140164ad0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@1@XZ 0x140164af0 ; prop
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBU?$pair@IH@std@@H@1@XZ 0x140164b10 ; prop
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@1@XZ 0x140164b30 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140164b50 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140164ba0 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140164bc0 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140164c10 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140164c30 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140164cc0 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140164d50 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140164d70 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140164d90 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140164db0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140164dd0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140164ea0 ; prop
// MS2-PIN: ??R?$less@U?$pair@IH@std@@@std@@QEBA_NAEBU?$pair@IH@1@0@Z 0x140164f70 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEBA_KXZ 0x1401662c0 ; unique
// MS2-PIN: ?GetCount@?$CAtlMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CStringElementTraitsI@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CDefaultCharTraits@D@2@@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEBA_KXZ 0x1401662e0 ; unique
// MS2-PIN: ?GetKeyAt@?$CAtlMap@HV?$MS2Ptr@VCAchieveGradeData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveGradeData@@@@@3@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x140166450 ; order
// MS2-PIN: ?GetKeyAt@?$CAtlMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CStringElementTraitsI@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CDefaultCharTraits@D@2@@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@PEAU__POSITION@@@Z 0x1401664c0 ; order
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$MS2Ptr@VCAchieveGradeData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveGradeData@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140166a10 ; prop
// MS2-PIN: ?GetStartPosition@?$CAtlMap@IV?$MS2Ptr@VCAchieveData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveData@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140166a80 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CStringElementTraitsI@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CDefaultCharTraits@D@2@@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x140166af0 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@HV?$MS2Ptr@VCAchieveGradeData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveGradeData@@@@@3@@ATL@@QEBA_NXZ 0x140167a60 ; prop
// MS2-PIN: ?IsEmpty@?$CAtlMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CStringElementTraitsI@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CDefaultCharTraits@D@2@@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEBA_NXZ 0x140167ac0 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$MS2Ptr@VCAchieveGradeData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveGradeData@@@@@3@@ATL@@QEAAPEAVCPair@12@H@Z 0x140167bf0 ; unique
// MS2-PIN: ?ToComment@TiXmlDocument@@UEAAPEAVTiXmlComment@@XZ 0x14016a540 ; unique
// MS2-PIN: ?ToComment@TiXmlDocument@@UEBAPEBVTiXmlComment@@XZ 0x14016a550 ; unique
// MS2-PIN: ?ToDeclaration@TiXmlDocument@@UEAAPEAVTiXmlDeclaration@@XZ 0x14016a560 ; unique
// MS2-PIN: ?ToDeclaration@TiXmlDocument@@UEBAPEBVTiXmlDeclaration@@XZ 0x14016a570 ; unique
// MS2-PIN: ?ToDocument@TiXmlDocument@@UEAAPEAV1@XZ 0x14016a580 ; unique
// MS2-PIN: ?ToDocument@TiXmlDocument@@UEBAPEBV1@XZ 0x14016a590 ; unique
// MS2-PIN: ?ToElement@TiXmlDocument@@UEAAPEAVTiXmlElement@@XZ 0x14016a5a0 ; unique
// MS2-PIN: ?ToElement@TiXmlDocument@@UEBAPEBVTiXmlElement@@XZ 0x14016a5b0 ; unique
// MS2-PIN: ?ToText@TiXmlDocument@@UEAAPEAVTiXmlText@@XZ 0x14016a860 ; unique
// MS2-PIN: ?ToText@TiXmlDocument@@UEBAPEBVTiXmlText@@XZ 0x14016a870 ; unique
// MS2-PIN: ?ToUnknown@TiXmlDocument@@UEAAPEAVTiXmlUnknown@@XZ 0x14016a880 ; unique
// MS2-PIN: ?ToUnknown@TiXmlDocument@@UEBAPEBVTiXmlUnknown@@XZ 0x14016a890 ; unique
// MS2-PIN: ?_Adjust_manually_vector_aligned@std@@YAXAEAPEAXAEA_K@Z 0x14016ace0 ; unique
// MS2-PIN: ?_Adopt@_Iterator_base0@std@@QEAAXPEBX@Z 0x14016ad80 ; prop
// MS2-PIN: ?_Allocate@_Default_allocate_traits@std@@SAPEAX_K@Z 0x14016ad90 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@XZ 0x14016adb0 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@XZ 0x14016ae70 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@XZ 0x14016af30 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@XZ 0x14016b010 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEBA_NAEBU?$pair@IH@2@0@Z 0x14016b0f0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEBA_NAEBU?$pair@IH@2@0@Z 0x14016b130 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x14016b170 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x14016b1a0 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@Z 0x14016b210 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@Z 0x14016b260 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@Z 0x14016b2b0 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@Z 0x14016b350 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@2@@Z 0x14016b3f0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@2@@Z 0x14016b9a0 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@Z 0x14016bf50 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@Z 0x14016bf80 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@Z 0x14016bfb0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@Z 0x14016bfe0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@XZ 0x14016c010 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@XZ 0x14016c040 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@XZ 0x14016c070 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@XZ 0x14016c0a0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_XmlNode@@V?$allocator@PEAVUnk_XmlNode@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVUnk_XmlNode@@@std@@@2@XZ 0x14016c0d0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_XmlNode@@V?$allocator@PEAVUnk_XmlNode@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVUnk_XmlNode@@@std@@@2@XZ 0x14016c0f0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@U?$pair@IH@std@@@2@XZ 0x14016c110 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@U?$pair@IH@std@@@2@XZ 0x14016c120 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@U?$pair@IH@std@@@2@XZ 0x14016c130 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@PEAVUnk_XmlNode@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVUnk_XmlNode@@@std@@@2@$00@std@@QEAAAEAV?$allocator@PEAVUnk_XmlNode@@@2@XZ 0x14016c150 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@2@XZ 0x14016c160 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@2@XZ 0x14016c170 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@2@XZ 0x14016c180 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@2@XZ 0x14016c190 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@2@XZ 0x14016c1a0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@2@XZ 0x14016c1b0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@2@XZ 0x14016c1c0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@U?$pair@IH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@2@XZ 0x14016c1d0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@PEAVUnk_XmlNode@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVUnk_XmlNode@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVUnk_XmlNode@@@std@@@2@XZ 0x14016c1e0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@PEAVUnk_XmlNode@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVUnk_XmlNode@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVUnk_XmlNode@@@std@@@2@XZ 0x14016c1f0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@XZ 0x14016c200 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@2@XZ 0x14016c210 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@XZ 0x14016c220 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@2@XZ 0x14016c230 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@2@XZ 0x14016c240 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@std@@@2@XZ 0x14016c270 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@2@XZ 0x14016c2a0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@std@@@2@XZ 0x14016c2d0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@U?$pair@IH@std@@@2@XZ 0x14016c320 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@U?$pair@IH@std@@@2@XZ 0x14016c340 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@U?$pair@IH@std@@@2@XZ 0x14016c360 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@U?$pair@IH@std@@@2@XZ 0x14016c380 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@IH@2@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@Z 0x14016c3a0 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@IH@2@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@Z 0x14016c3d0 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@IH@2@AEBU?$pair@$$CBU?$pair@IH@std@@H@2@@Z 0x14016c400 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEBAAEBU?$pair@IH@2@AEBU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@2@@Z 0x14016c420 ; prop
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@XZ 0x14016c440 ; prop
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@XZ 0x14016c450 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@Z 0x14016c460 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@Z 0x14016c540 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@PEAU32@@Z 0x14016c620 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@PEAU32@@Z 0x14016c650 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@PEAU32@@Z 0x14016c680 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@PEAU32@@Z 0x14016c6b0 ; prop
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@XZ 0x14016c860 ; prop
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@XZ 0x14016c880 ; prop
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@XZ 0x14016c8a0 ; prop
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@XZ 0x14016c8c0 ; prop
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@H@std@@PEAX@2@@Z 0x14016c8e0 ; prop
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@PEAX@2@@Z 0x14016c9c0 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x14016caa0 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x14016cb00 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@2@XZ 0x14016cc90 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@2@XZ 0x14016cd00 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x14016cdb0 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x14016ce50 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@2@XZ 0x14016cfe0 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@2@XZ 0x14016d040 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@2@0@Z 0x14016d0a0 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@2@@Z 0x14016d190 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@2@0@Z 0x14016d240 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@2@@Z 0x14016d330 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@2@AEBU?$pair@IH@2@@Z 0x14016d3e0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@2@AEBU?$pair@IH@2@@Z 0x14016d4c0 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@@std@@@2@AEBU?$pair@IH@2@@Z 0x14016d5a0 ; prop
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@@std@@@2@AEBU?$pair@IH@2@@Z 0x14016d600 ; prop
// MS2-PIN: ?memmove_s@Checked@ATL@@YAXPEAX_KPEBX1@Z 0x14016d790 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBU?$pair@IH@std@@H@std@@@std@@SAPEAU?$pair@$$CBU?$pair@IH@std@@H@2@AEAU32@@Z 0x14016d800 ; prop
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@std@@SAPEAU?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@2@AEAU32@@Z 0x14016d820 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@HU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@H@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x14016d8c0 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@U?$pair@HH@2@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x14016d8e0 ; prop
// MS2-PIN: ??__Fs_lock@@YAXXZ 0x142c9a000 ; prop
// MS2-PIN: ??__Fs_mapSkill@@YAXXZ 0x142c9a040 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??$?0V?$tuple@AEBU?$pair@IH@std@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBU?$pair@IH@std@@H@std@@QEAA@AEAV?$tuple@AEBU?$pair@IH@std@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14015e710
// MS2-PIN: ??$?0V?$tuple@AEBU?$pair@IH@std@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBU?$pair@IH@std@@U?$pair@HH@2@@std@@QEAA@AEAV?$tuple@AEBU?$pair@IH@std@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x14015e760
// MS2-PIN: ??$move@AEAV?$tuple@AEBU?$pair@IH@std@@@std@@@std@@YA$$QEAV?$tuple@AEBU?$pair@IH@std@@@0@AEAV10@@Z 0x140163100
// MS2-PIN: ?_Orphan_all@_Container_base0@std@@QEAAXXZ 0x14016c7c0
// MS2-PIN: ?get@?$MS2Ptr@VCAchieveGradeData@@@@QEBAPEAVCAchieveGradeData@@XZ 0x1401669f0
// MS2-PIN: ?get@?$MS2Ptr@VCConditionCommonData@@@@QEBAPEAVCConditionCommonData@@XZ 0x140166a00
// MS2-PIN: ??$AtlConvAllocMemory@D@ATL@@YAXPEAPEADHPEADH@Z 0x14015ec20
// MS2-PIN: ??$Unk_AchieveLog@HI@@YAXPEAVCLogString@@HHPEB_WAEBHAEBI@Z 0x14015e890
// MS2-PIN: ??$Unk_AchieveLog@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@@YAXPEAVCLogString@@HHPEB_WAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x14015eb90
// MS2-PIN: ??0?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x140163740
// MS2-PIN: ??0?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@H@Z 0x140163770
// MS2-PIN: ??0?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@I@Z 0x140163790
// MS2-PIN: ?Init@?$CW2AEX@$0IA@@ATL@@AEAAXPEB_WI@Z 0x140167410
// MS2-FUNCTIONAL ?Init@?$CW2AEX@$0IA@@ATL@@AEAAXPEB_WI@Z: ATL's own atlconv.h template; the toolchain ATL build differs from the exe's (539 vs 462 bytes, 8 vs 9 callees in the WideCharToMultiByte retry path), no unit source to change
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\achievedata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "achievedata.h"
#include "filesystem.h"
#include "logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <map>
#include <typeinfo>
#include <utility>
#include <vector>
#include "hook/ms2hook.h"

// ---------------------------------------------------------------------------------------------------------------
// Unrecovered helpers (externs bound by VA).
// ---------------------------------------------------------------------------------------------------------------
class Unk_XmlNode
{
public:
    // @0x140165cf0
    Unk_XmlNode* FirstChild(const char* pszName) { return FUN_14086e8d0(pszName); }
    // @0x140168650
    Unk_XmlNode* NextSibling(const char* pszName) { return FUN_14086e7e0(pszName); }
    Unk_XmlNode* FUN_14086e8d0(const char* pszName);
    Unk_XmlNode* FUN_14086e7e0(const char* pszName);
};
class Unk_140166410
{
public:
    bool FUN_14036d4b0(const CStringW& strFeature);
    CString FUN_14036d8e0();
};
extern Unk_140166410* DAT_143aab388;
// @0x140166410
inline Unk_140166410* FUN_140166410()
{
    return DAT_143aab388;
}
class Unk_140166430
{
public:
    void FUN_1405f5e90(int nCode, int nRank, CString strTag, CString strInfo);
};
extern Unk_140166430* DAT_143aab4f8;
// @0x140166430
inline Unk_140166430* FUN_140166430()
{
    return DAT_143aab4f8;
}
extern CLogString* DAT_143aab390;
// @0x140166440
inline CLogString* FUN_140166440()
{
    return DAT_143aab390;
}
extern CFileSystem* DAT_143aab398;
// @0x140166420
inline CFileSystem* FUN_140166420()
{
    return DAT_143aab398;
}
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
extern int DAT_1439f4840;                       // default code page (localepath.cpp)
// @0x14016a5c0
inline CString FUN_14016a5c0(const char* psz, int)
{
    return CString(psz);
}
// @0x14016a600
inline CString FUN_14016a600(const wchar_t* psz, int nCodePage)
{
    try
    {
        int cp = nCodePage == 0 ? DAT_1439f4840 : nCodePage;
        CString str = (const char*)CW2A(psz, cp);
        return str;
    }
    catch (
        ...)
    {
    }
    return CString("");
}
// @0x14016a730
inline CStringW FUN_14016a730(const char* psz, int nCodePage)
{
    try
    {
        int cp = nCodePage == 0 ? DAT_1439f4840 : nCodePage;
        CStringW str = (const wchar_t*)CA2W(psz, cp);
        return str;
    }
    catch (
        ...)
    {
    }
    return CStringW(L"");
}
CString FUN_1407185b0(const CString& value);
void FUN_14028faa0(Unk_XmlNode* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_XmlNode*>* pOut);
int FUN_14029ea20(CConditionCommonData* pData, Unk_XmlNode* pNode, CStringW strTag, unsigned nId);
bool FUN_14029e940(CConditionCommonData* pThis, CConditionCommonData* pOther);
void FUN_140873220(Unk_XmlNode*, const char*, unsigned&);
void FUN_1408731e0(Unk_XmlNode*, const char*, int&);
int FUN_1408733e0(Unk_XmlNode*, const char*, CString&);
int FUN_140873420(Unk_XmlNode*, const char*, CStringW&);
int FUN_140873710(Unk_XmlNode*, const char*, int*);
int FUN_140873890(Unk_XmlNode*, const char*, int&);
void FUN_14086dd00(TiXmlDocument*) noexcept;          // ~TiXmlNode (base part)

// ---------------------------------------------------------------------------------------------------------------
// Inline instances first emitted by this unit (the COMDAT zone).
// ---------------------------------------------------------------------------------------------------------------

// CLockCriticalSection (RTTI name) and its scoped guard.
// @0x140163ea0
inline CLockCriticalSection::CLockCriticalSection()
{
    InitializeCriticalSectionAndSpinCount(this ? &section : 0, 4000);
}
// @0x140164510
inline CLockCriticalSection::~CLockCriticalSection()
{
    DeleteCriticalSection(this ? &section : 0);
}
// @0x140167bb0
inline void CLockCriticalSection::vfunc_1()
{
    EnterCriticalSection(this ? &section : 0);
}
// @0x14016a8a0
inline void CLockCriticalSection::vfunc_2()
{
    LeaveCriticalSection(this ? &section : 0);
}

// @0x140162a50
inline CLockCriticalSection* Unk_LockIdentity(CLockCriticalSection* p)
{
    return p;
}
// @0x140163940
inline Unk_LockGuard::Unk_LockGuard(CLockCriticalSection& lock)
{
    p = Unk_LockIdentity(&lock);
    lock.vfunc_1();
}
// @0x140164a80
inline Unk_LockGuard::operator int()
{
    return 0;
}
// @0x1401643b0
inline Unk_LockGuard::~Unk_LockGuard()
{
    static_cast<CLockCriticalSection*>(p)->vfunc_2();
}

// TinyXML's TiXmlString (8 bytes: a pointer to its representation).
struct Unk_TiXmlStringRep;
extern Unk_TiXmlStringRep g_Unk_TiXmlNullRep;       // 0x143ab1fb0
class Unk_TiXmlString
{
public:
    // @0x1401646b0
    ~Unk_TiXmlString() { quit(); }
    // @0x14016d840
    void quit()
    {
        if (m_pRep != &g_Unk_TiXmlNullRep)
            delete[] reinterpret_cast<char*>(m_pRep);
    }
    Unk_TiXmlStringRep* m_pRep;
};
// @0x140164670
inline TiXmlDocument::~TiXmlDocument()
{
    reinterpret_cast<Unk_TiXmlString*>(&m_58)->Unk_TiXmlString::~Unk_TiXmlString();
    FUN_14086dd00(this);
}

// The table lock shared with the cache code (cachedata.cpp owns it; no named symbol in the unit tables).
extern CLockCriticalSection g_cacheLock;            // 0x143aac550

// Log wrappers (fmt ArgList built on the stack, forwarded to CLogString).
template <class T>
inline void Unk_AchieveLog(CLogString* log, int level, int category, const wchar_t* format, const T& value)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(value)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(value), args));
}
template <class T, class U>
inline void Unk_AchieveLog(CLogString* log, int level, int category, const wchar_t* format, const T& first,
                           const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

typedef ATL::CAtlMap<CStringA, CStringA, ATL::CStringElementTraitsI<CStringA> > Unk_ExtraMap;
inline void Unk_SplitImplA(CString& str, ATL::CAtlArray<CString>* pOut, const char* pszSep);
inline void Unk_SplitImplW(CString& str, ATL::CAtlArray<CStringW>* pOut, const char* pszSep);
// @0x14015f000
inline CStringW Unk_WidenString(const CString& str)
{
    return FUN_14016a730((const char*)str, 0);
}

// @0x14015efc0
inline CString Unk_CopyString(const CString& str)
{
    return CString(str);
}
// @0x14015f050
inline void Unk_SplitA(CString& str, ATL::CAtlArray<CString>* pOut, const char* pszSep)
{
    Unk_SplitImplA(str, pOut, pszSep);
}
// @0x14015f080
inline void Unk_SplitW(CString& str, ATL::CAtlArray<CStringW>* pOut, const char* pszSep)
{
    Unk_SplitImplW(str, pOut, pszSep);
}
// @0x14015f0b0
inline void Unk_SplitImplA(CString& str, ATL::CAtlArray<CString>* pOut, const char* pszSep)
{
    int nPos = 0;
    CString strTok = str.Tokenize(pszSep, nPos);
    while (!strTok.IsEmpty())
    {
        pOut->Add(Unk_CopyString(strTok));
        strTok = str.Tokenize(pszSep, nPos);
    }
}
// @0x14015f1b0
inline void Unk_SplitImplW(CString& str, ATL::CAtlArray<CStringW>* pOut, const char* pszSep)
{
    int nPos = 0;
    CString strTok = str.Tokenize(pszSep, nPos);
    while (!strTok.IsEmpty())
    {
        pOut->Add(Unk_WidenString(strTok));
        strTok = str.Tokenize(pszSep, nPos);
    }
}
// @0x14015f2b0
// "{key:value,key:value}" -> map
inline void Unk_ParseExtra(CString str, Unk_ExtraMap* pMap)
{
    str.Trim("{} ");
    ATL::CAtlArray<CString> parts;
    Unk_SplitA(str, &parts, ",");
    for (size_t i = 0; i < parts.GetCount(); i++)
    {
        CString& part = parts[i];
        int nColon;
        if (!part.IsEmpty() && (nColon = part.Find(":", 0)) > 0 && nColon < part.GetLength())
        {
            CString strKey = FUN_1407185b0(part.Left(nColon).Trim());
            CString strValue = FUN_1407185b0(part.Mid(nColon + 1).Trim());
            pMap->SetAt(strKey, strValue);
        }
    }
}
// @0x14015f480
inline int Unk_ReadFilterValue(Unk_XmlNode* pNode, const char* pszName, ATL::CAtlArray<CStringW>* pOut)
{
    CString str;
    int nRead = FUN_1408733e0(pNode, pszName, str);
    if (nRead == 0)
        Unk_SplitW(str, pOut, ",");
    return nRead;
}
// @0x14015f500
inline int Unk_ReadRank(Unk_XmlNode* pNode, const char* pszName, int* pnOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 231), 0));
        return 2;
    }
    int nRead;
    int nValue = 0;
    nRead = FUN_140873890(pNode, pszName, nValue);
    if (nRead != 0)
        return nRead;
    *pnOut = nValue;
    return nRead;
}
// @0x14015f590
inline int Unk_ReadRewardType(Unk_XmlNode* pNode, const char* pszName, int* pnOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nRead = FUN_1408733e0(pNode, pszName, str);
    if (nRead != 0)
        return nRead;
    *pnOut = CAchieveData::ParseRewardType(str);
    return nRead;
}
// @0x14015f650
inline int Unk_ReadRequireType(Unk_XmlNode* pNode, const char* pszName, int* pnOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nRead = FUN_1408733e0(pNode, pszName, str);
    if (nRead != 0)
        return nRead;
    *pnOut = CAchieveData::ParseRequireType(str);
    return nRead;
}
// @0x14015f710
inline CString Unk_ReadString(Unk_XmlNode* pNode, const char* pszName, CString strDefault)
{
    CString str;
    if (FUN_1408733e0(pNode, pszName, str) != 0)
        return strDefault;
    return str;
}
// @0x14015f7e0
inline bool Unk_MapEqual(const Unk_ExtraMap& a, const Unk_ExtraMap& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    POSITION posA = a.GetStartPosition();
    POSITION posB = b.GetStartPosition();
    for (UINT i = 0; i < a.GetCount(); i++, a.GetNext(posA), b.GetNext(posB))
    {
        if (a.GetKeyAt(posA) != b.GetKeyAt(posB))
            return false;
        if (a.GetValueAt(posA) != b.GetValueAt(posB))
            return false;
    }
    return true;
}
// @0x14015f920
inline bool Unk_ArrayEqual(const ATL::CAtlArray<CStringW>& a, const ATL::CAtlArray<CStringW>& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (UINT i = 0; i < a.GetCount(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// ---------------------------------------------------------------------------------------------------------------
// The table statics (init order = definition order).
// ---------------------------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CAchieveData::s_bInit;                                             // 0x143aab3a0
#endif
static ATL::CAtlMap<unsigned, MS2Ptr<CAchieveData> > s_mapData;         // 0x143aab3e0 (achievement id -> data)
static ATL::CAtlList<MS2Ptr<CAchieveData> > s_listData;                 // 0x143aab428 (load order)
static CLockCriticalSection s_lock;                                     // 0x143aab478
static ATL::CAtlMap<unsigned, int> s_mapSeen;                           // 0x143aab4b0 (ids reported by MarkSeen)
typedef std::pair<unsigned, int> Unk_RewardKey;                         // (achievement id, grade)
static std::map<Unk_RewardKey, std::pair<int, int> > s_mapSkill;        // 0x143aab468 (reward type 4)
static std::map<Unk_RewardKey, int> s_mapStat;                          // 0x143aab458 (reward type 3)

// @0x140165670
inline void CAchieveData::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CAchieveData).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}
// @0x14016a500
inline void CAchieveData::SetInit(bool bInit)
{
    s_bInit = bInit;
}

// ---------------------------------------------------------------------------------------------------------------
// Unk_AchieveReward
// ---------------------------------------------------------------------------------------------------------------
// @0x140164110
Unk_AchieveReward::Unk_AchieveReward() : m_nType(0), m_nCode(0), m_nValue(0), m_nRank(1), m_nSubJob(1)
{
}
// @0x140164650
Unk_AchieveReward::~Unk_AchieveReward()
{
}
// @0x140164880
bool Unk_AchieveReward::operator!=(const Unk_AchieveReward& o) const
{
    if (m_nType != o.m_nType)
        return true;
    if (m_nCode != o.m_nCode)
        return true;
    if (m_nValue != o.m_nValue)
        return true;
    if (m_nRank != o.m_nRank)
        return true;
    if (m_nSubJob != o.m_nSubJob)
        return true;
    if (!Unk_MapEqual(m_mapExtra, o.m_mapExtra))
        return true;
    return false;
}

// ---------------------------------------------------------------------------------------------------------------
// CAchieveGradeData / CAchieveData
// ---------------------------------------------------------------------------------------------------------------
// @0x14015b490
CAchieveGradeData::CAchieveGradeData() : m_pCondition(new CConditionCommonData)
{
    m_nGrade = 0;
}
// @0x14015b540
CAchieveGradeData::~CAchieveGradeData()
{
}
// @0x14015b5a0
bool CAchieveGradeData::operator!=(const CAchieveGradeData& o) const
{
    if (m_nGrade != o.m_nGrade)
        return true;
    if (m_reward != o.m_reward)
        return true;
    if (FUN_14029e940(m_pCondition.get(), o.m_pCondition.get()))
        return true;
    return false;
}

// @0x14015b640
CAchieveData::CAchieveData()
{
    m_nId = 0;
    m_nType = 0;
    m_nCategory = 0;
    m_nMaxGrade = 0;
    m_nFirstGrade = 0x7fffffff;
    m_nNoticePercent = 1;
    m_nAccount = 0;
    m_nLocking = 0;
    m_nRequireType = 0;
    m_nSurvival = 0;
}
// @0x14015b7d0
CAchieveData::~CAchieveData()
{
    m_mapGrade.RemoveAll();
}
// @0x14015b8d0
bool CAchieveData::operator!=(const CAchieveData& o) const
{
    if (m_nAccount != o.m_nAccount)
        return true;
    if (m_nId != o.m_nId)
        return true;
    if (m_nType != o.m_nType)
        return true;
    if (m_nMaxGrade != o.m_nMaxGrade)
        return true;
    if (m_nFirstGrade != o.m_nFirstGrade)
        return true;
    if (m_strIcon != o.m_strIcon)
        return true;
    if (m_nNoticePercent != o.m_nNoticePercent)
        return true;
    if (m_strFeature != o.m_strFeature)
        return true;
    if (m_strLocale != o.m_strLocale)
        return true;
    if (m_nLocking != o.m_nLocking)
        return true;
    if (m_nSurvival != o.m_nSurvival)
        return true;
    if (m_nCategory != o.m_nCategory)
        return true;
    if (m_strCategoryTag != o.m_strCategoryTag)
        return true;
    if (m_strContentsTag != o.m_strContentsTag)
        return true;
    if (m_nRequireType != o.m_nRequireType)
        return true;
    if (!Unk_ArrayEqual(m_aRequire, o.m_aRequire))
        return true;
    if (m_mapGrade.GetCount() != o.m_mapGrade.GetCount())
        return true;
    for (POSITION pos = m_mapGrade.GetStartPosition(); pos; m_mapGrade.GetNext(pos))
    {
        int nKey = m_mapGrade.GetKeyAt(pos);
        MS2Ptr<CAchieveGradeData> pOther(0);
        if (!o.m_mapGrade.Lookup(nKey, pOther))
            return true;
        CAchieveGradeData* pRhs = pOther.get();
        if (*m_mapGrade.GetValueAt(pos).get() != *pRhs)
            return true;
    }
    return false;
}

// @0x14015bc40
MS2Ptr<CAchieveGradeData> CAchieveData::GetGrade(int nGrade)
{
    MS2Ptr<CAchieveGradeData> pGrade(0);
    m_mapGrade.Lookup(nGrade, pGrade);
    return pGrade;
}

// @0x14015bcd0
CString CAchieveData::GetName()
{
    CString str;
    str.Format("%s%s", ".\\Data\\Resource\\Image\\Emblem\\Medal\\Icon\\", (const char*)m_strIcon);
    return str;
}

// @0x14015bd60
bool CAchieveData::IsAvailable()
{
    if (!FUN_140166410()->FUN_14036d4b0(m_strFeature))
        return false;
    return !(m_strLocale.GetLength() != 0 && m_strLocale != FUN_140166410()->FUN_14036d8e0());
}

// @0x14015be50
int CAchieveData::GetSurvivalFlag(int nId)
{
    MS2Ptr<CAchieveData> pData = GetAchieveData(nId);
    if (pData.IsNull())
        return 0;
    return pData->m_nSurvival;
}

// @0x14015bed0
bool CAchieveData::HasRewardSkill(unsigned nId, int nGrade)
{
    Unk_RewardKey key = std::make_pair(nId, nGrade);
    if (Unk_LockGuard guard = g_cacheLock)
    {
    }
    else
    {
        if (s_mapSkill.find(key) != s_mapSkill.end())
            return true;
    }
    return false;
}

// @0x14015bf90
bool CAchieveData::HasRewardStat(unsigned nId, int nGrade)
{
    Unk_RewardKey key = std::make_pair(nId, nGrade);
    if (Unk_LockGuard guard = g_cacheLock)
    {
    }
    else
    {
        if (s_mapStat.find(key) != s_mapStat.end())
            return true;
    }
    return false;
}

// @0x14015c050
void CAchieveData::LoadAll()
{
    if (Unk_LockGuard guard = g_cacheLock)
    {
    }
    else
    {
        s_mapData.RemoveAll();
        s_listData.RemoveAll();
        ATL::CAtlArray<CString> files;
        FUN_140399100(CString("*.xml"), FUN_14071a5b0(CString("Achieve"), CString("")), files, CString(""), false);
        for (size_t i = 0; i < files.GetCount(); i++)
        {
            CString strFile = files[i];
            Load(strFile);
        }
    }
    SetInit(true);
}

// @0x14015c270
// MS2-FUNCTIONAL: loader; exe EH-state layout of the many temporaries is not reproduced
void CAchieveData::Load(CString strPath)
{
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
    {
        Unk_AchieveLog(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    Unk_XmlNode* pRoot = reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    std::vector<Unk_XmlNode*> nodes;
    FUN_14028faa0(pRoot, "achieves", "id", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_XmlNode* pNode = nodes[i];
        MS2Ptr<CAchieveData> pData(new CAchieveData);
        pData->FUN_1401d1160(CString(strPath));
        FUN_140873220(pNode, "id", pData->m_nId);
        FUN_1408731e0(pNode, "noticePercent", pData->m_nNoticePercent);
        FUN_140873710(pNode, "account", &pData->m_nAccount);
        FUN_140873420(pNode, "feature", pData->m_strFeature);
        FUN_1408733e0(pNode, "locale", pData->m_strLocale);
        FUN_1408731e0(pNode, "locking", pData->m_nLocking);
        FUN_1408733e0(pNode, "contentsTag", pData->m_strContentsTag);
        FUN_1408733e0(pNode, "categoryTag", pData->m_strCategoryTag);
        Unk_ReadRequireType(pNode, "uiFilterType", &pData->m_nRequireType);
        Unk_ReadFilterValue(pNode, "uiFilterValue", &pData->m_aRequire);
        if (pData->m_strContentsTag.Find("Survival", 0) != -1)
            pData->m_nSurvival = 1;
        pData->m_nType = pData->m_nId / 10000000;
        pData->m_nCategory = (pData->m_nId / 1000000) % 10;
        if (pData->m_nType == 0)
            continue;
        pData->m_strIcon = Unk_ReadString(pNode, "icon", CString(""));
        for (Unk_XmlNode* pGradeNode = pNode->FirstChild("grade"); pGradeNode != 0;
             pGradeNode = pGradeNode->NextSibling("grade"))
        {
            MS2Ptr<CAchieveGradeData> pGrade(new CAchieveGradeData);
            FUN_1408731e0(pGradeNode, "value", pGrade->m_nGrade);
            if (pData->m_nMaxGrade < pGrade->m_nGrade)
                pData->m_nMaxGrade = pGrade->m_nGrade;
            if (pGrade->m_nGrade < pData->m_nFirstGrade)
                pData->m_nFirstGrade = pGrade->m_nGrade;
            Unk_XmlNode* pCondition = pGradeNode->FirstChild("condition");
            if (pCondition != 0)
            {
                if (FUN_14029ea20(pGrade->m_pCondition, pCondition, CStringW(L"AchieveData"), pData->m_nId) == 0)
                    return;
            }
            Unk_XmlNode* pReward = pGradeNode->FirstChild("reward");
            if (pReward != 0)
            {
                Unk_ReadRewardType(pReward, "type", &pGrade->m_reward.m_nType);
                FUN_140873220(pReward, "code", pGrade->m_reward.m_nCode);
                FUN_140873220(pReward, "value", pGrade->m_reward.m_nValue);
                Unk_ReadRank(pReward, "rank", &pGrade->m_reward.m_nRank);
                int nSubJob = 0;
                FUN_1408731e0(pReward, "subJobLevel", nSubJob);
                if (nSubJob == 0)
                    pGrade->m_reward.m_nSubJob = 1;
                else if (nSubJob == 1)
                    pGrade->m_reward.m_nSubJob = 2;
                CString strExtra;
                FUN_1408733e0(pReward, "extra", strExtra);
                Unk_ParseExtra(CString(strExtra), &pGrade->m_reward.m_mapExtra);
                if (pGrade->m_reward.m_nType == 1)
                {
                    CString strId;
                    strId.Format("AchieveID=%u", pData->m_nId);
                    FUN_140166430()->FUN_1405f5e90(pGrade->m_reward.m_nCode, pGrade->m_reward.m_nRank,
                                                   CString("CAchieveGradeData first Achieve.xml"), CString(strId));
                }
                else if (pGrade->m_reward.m_nType == 3)
                {
                    Unk_RewardKey key = std::make_pair(pData->m_nId, pGrade->m_nGrade);
                    s_mapStat[key] = pGrade->m_reward.m_nValue;
                }
                else if (pGrade->m_reward.m_nType == 4)
                {
                    Unk_RewardKey key = std::make_pair(pData->m_nId, pGrade->m_nGrade);
                    s_mapSkill[key] = std::make_pair(pGrade->m_reward.m_nSubJob, pGrade->m_reward.m_nValue);
                }
            }
            if (pData->m_mapGrade.Lookup(pGrade->m_nGrade) != 0)
                Unk_AchieveLog(FUN_140166440(), 1, 0x13, L"트로피의 {0}등급이 중복입니다. {1} 트로피 확인해 주세요.",
                               pGrade->m_nGrade, pData->m_nId);
            pData->m_mapGrade.SetAt(pGrade->m_nGrade, pGrade);
        }
        if (pData->m_nFirstGrade != 1 && pData->m_nType != 9)
            Unk_AchieveLog(FUN_140166440(), 1, 0x13, L"트로피의 최소 등급이 1이 아닙니다{0}. {1} 트로피 확인해 주세요.",
                           pData->m_nFirstGrade, pData->m_nId);
        s_mapData.SetAt(pData->m_nId, pData);
        s_listData.AddTail(pData);
        pData->OnLoaded();
    }
}

// @0x14015cff0
// MS2-FUNCTIONAL: loader variant that returns the last loaded record; exe EH-state layout not reproduced
void CAchieveData::LoadClient(CString strPath, MS2Ptr<CAchieveData>& rOut)
{
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
    {
        Unk_AchieveLog(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    Unk_XmlNode* pRoot = reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    std::vector<Unk_XmlNode*> nodes;
    FUN_14028faa0(pRoot, "achieves", "id", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_XmlNode* pNode = nodes[i];
        MS2Ptr<CAchieveData> pData(new CAchieveData);
        pData->FUN_1401d1160(CString(strPath));
        FUN_140873220(pNode, "id", pData->m_nId);
        FUN_1408731e0(pNode, "noticePercent", pData->m_nNoticePercent);
        FUN_140873710(pNode, "account", &pData->m_nAccount);
        FUN_140873420(pNode, "feature", pData->m_strFeature);
        FUN_1408733e0(pNode, "locale", pData->m_strLocale);
        FUN_1408731e0(pNode, "locking", pData->m_nLocking);
        FUN_1408733e0(pNode, "contentsTag", pData->m_strContentsTag);
        FUN_1408733e0(pNode, "categoryTag", pData->m_strCategoryTag);
        Unk_ReadRequireType(pNode, "uiFilterType", &pData->m_nRequireType);
        Unk_ReadFilterValue(pNode, "uiFilterValue", &pData->m_aRequire);
        if (pData->m_strContentsTag.Find("Survival", 0) != -1)
            pData->m_nSurvival = 1;
        pData->m_nType = pData->m_nId / 10000000;
        pData->m_nCategory = (pData->m_nId / 1000000) % 10;
        if (pData->m_nType == 0)
            continue;
        pData->m_strIcon = Unk_ReadString(pNode, "icon", CString(""));
        for (Unk_XmlNode* pGradeNode = pNode->FirstChild("grade"); pGradeNode != 0;
             pGradeNode = pGradeNode->NextSibling("grade"))
        {
            MS2Ptr<CAchieveGradeData> pGrade(new CAchieveGradeData);
            FUN_1408731e0(pGradeNode, "value", pGrade->m_nGrade);
            if (pData->m_nMaxGrade < pGrade->m_nGrade)
                pData->m_nMaxGrade = pGrade->m_nGrade;
            if (pGrade->m_nGrade < pData->m_nFirstGrade)
                pData->m_nFirstGrade = pGrade->m_nGrade;
            Unk_XmlNode* pCondition = pGradeNode->FirstChild("condition");
            if (pCondition != 0)
            {
                if (FUN_14029ea20(pGrade->m_pCondition, pCondition, CStringW(L"AchieveData"), pData->m_nId) == 0)
                    return;
            }
            Unk_XmlNode* pReward = pGradeNode->FirstChild("reward");
            if (pReward != 0)
            {
                Unk_ReadRewardType(pReward, "type", &pGrade->m_reward.m_nType);
                FUN_140873220(pReward, "code", pGrade->m_reward.m_nCode);
                FUN_140873220(pReward, "value", pGrade->m_reward.m_nValue);
                Unk_ReadRank(pReward, "rank", &pGrade->m_reward.m_nRank);
                int nSubJob = 0;
                FUN_1408731e0(pReward, "subJobLevel", nSubJob);
                if (nSubJob == 0)
                    pGrade->m_reward.m_nSubJob = 1;
                else if (nSubJob == 1)
                    pGrade->m_reward.m_nSubJob = 2;
                CString strExtra;
                FUN_1408733e0(pReward, "extra", strExtra);
                Unk_ParseExtra(CString(strExtra), &pGrade->m_reward.m_mapExtra);
            }
            pData->m_mapGrade.SetAt(pGrade->m_nGrade, pGrade);
        }
        s_mapData.SetAt(pData->m_nId, pData);
        s_listData.AddTail(pData);
        pData->OnLoaded();
        rOut = pData;
    }
}

#ifndef MS2_HOOK_DLL
// @0x14015d9e0
MS2Ptr<CAchieveData> GetAchieveData(int nId)
{
    CAchieveData::CheckInit();
    if (nId == 0)
        return MS2Ptr<CAchieveData>(0);
    MS2Ptr<CAchieveData> pData(0);
    if (Unk_LockGuard guard = g_cacheLock)
    {
    }
    else
    {
        s_mapData.Lookup(nId, pData);
    }
    return pData;
}
#endif

// @0x14015dab0
MS2Ptr<CAchieveGradeData> CAchieveData::Find(int nId, int nGrade)
{
    MS2Ptr<CAchieveData> pData = GetAchieveData(nId);
    if (pData == 0)
        return MS2Ptr<CAchieveGradeData>(0);
    return pData->GetGrade(nGrade);
}

// @0x14015db60
void CAchieveData::GetAll(ATL::CAtlArray<MS2Ptr<CAchieveData> >& rOut)
{
    if (Unk_LockGuard guard = g_cacheLock)
    {
    }
    else
    {
        for (POSITION pos = s_mapData.GetStartPosition(); pos;)
        {
            MS2Ptr<CAchieveData> pData = s_mapData.GetValueAt(pos);
            rOut.Add(pData);
            s_mapData.GetNext(pos);
        }
    }
}

// @0x14015dc10
int CAchieveData::MarkSeen(int nId)
{
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        if (s_mapSeen.Lookup(nId) != 0)
            return 0;
        s_mapSeen.SetAt(nId, 1);
    }
    return 1;
}

// @0x14015dcb0
void CAchieveData::OnLoaded()
{
}

// @0x14015dcc0
int CAchieveData::ParseRequireType(CStringA& str)
{
    if (str.CompareNoCase("event") == 0)
        return 1;
    else if (str.CompareNoCase("eventID") == 0)
        return 2;
    else
        return 0;
}

// @0x14015dd20
int CAchieveData::ParseRewardType(CStringA& str)
{
    if (str.CompareNoCase("item") == 0)
        return 1;
    else if (str.CompareNoCase("title") == 0)
        return 2;
    else if (str.CompareNoCase("statpoint") == 0)
        return 3;
    else if (str.CompareNoCase("skillpoint") == 0)
        return 4;
    else if (str.CompareNoCase("shop_weapon") == 0)
        return 5;
    else if (str.CompareNoCase("shop_build") == 0)
        return 6;
    else if (str.CompareNoCase("shop_ride") == 0)
        return 7;
    else if (str.CompareNoCase("itemcoloring") == 0)
        return 8;
    else if (str.CompareNoCase("beauty_makeup") == 0)
        return 9;
    else if (str.CompareNoCase("beauty_skin") == 0)
        return 10;
    else if (str.CompareNoCase("beauty_hair") == 0)
        return 11;
    else if (str.CompareNoCase("dynamicaction") == 0)
        return 12;
    else if (str.CompareNoCase("etc") == 0)
        return 13;
    else
        return 0;
}

// @0x14015df00
int CAchieveData::ParseRewardType(CStringW& str)
{
    CStringA tmp = FUN_14016a600(str, 0);
    return ParseRewardType(tmp);
}

// @0x14015df70
CStringW CAchieveData::GetRewardTypeName(int nType)
{
    switch (nType)
    {
    case 1:
        return CStringW(L"item");
    case 2:
        return CStringW(L"title");
    case 3:
        return CStringW(L"statpoint");
    case 4:
        return CStringW(L"skillpoint");
    case 5:
        return CStringW(L"shop_weapon");
    case 6:
        return CStringW(L"shop_build");
    case 7:
        return CStringW(L"shop_ride");
    case 8:
        return CStringW(L"itemcoloring");
    case 9:
        return CStringW(L"beauty_makeup");
    case 10:
        return CStringW(L"beauty_skin");
    case 11:
        return CStringW(L"beauty_hair");
    case 12:
        return CStringW(L"dynamicaction");
    case 13:
        return CStringW(L"etc");
    default:
        return CStringW(L"");
    }
}
