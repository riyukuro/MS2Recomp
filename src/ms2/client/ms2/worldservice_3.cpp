// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService, part 3 of 4 (owner ws2).
// MS2-UNIT: ?\worldservice.cpp#3
// MS2-RANGE: 0x141bedaf0-0x141bf2b70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VUnk_RideeFieldObj@@@@QEAA@AEBV0@@Z 0x141bf1330 ; prop
// MS2-PIN: ??0?$MS2Ptr@VUnk_GoField@@@@QEAA@PEAVUnk_GoField@@@Z 0x141bf13c0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsB_Lift@@@@QEAA@$$QEAV0@@Z 0x141bf14d0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsB_Lift@@@@QEAA@H@Z 0x141bf1500 ; prop
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsB_Lift@@@@QEAA@PEAVUnk_WsB_Lift@@@Z 0x141bf1520 ; prop
// MS2-PIN: ??0?$MS2Ptr@VUnk_AkoLiftTarget@@@@QEAA@PEAVUnk_AkoLiftTarget@@@Z 0x141bf1580 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCRegionSkillObject@@@@QEAA@AEBV0@@Z 0x141bf16a0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VFieldProperty@@@@QEAA@AEBV0@@Z 0x141bf1770 ; prop
// MS2-PIN: ??0?$MS2Ptr@VUIDebugTooltip@@@@QEAA@AEBV0@@Z 0x141bf1870 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@1@@Z 0x141bf24d0 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@1@@Z 0x141bf2510 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@1@@Z 0x141bf2550 ; prop
// MS2-PINS-END tplpin
// The smart pointer ctors whose add-ref COMDAT (0x141c1f4a0..0x141c1f5f0) lies in part 8 (no anchor there).
// MS2-PIN: ??0?$TPtrValue@V?$CAtlList@V?$SmartPointer@VEntity@egf@@@efd@@V?$CElementTraits@V?$SmartPointer@VEntity@egf@@@efd@@@ATL@@@ATL@@@@QEAA@AEBV0@@Z 0x141bf1230
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f500@@@@QEAA@AEBV0@@Z 0x141bf1420
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f500@@@@QEAA@PEAVUnk_WsPtrT_141c1f500@@@Z 0x141bf1460
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f530@@@@QEAA@AEBV0@@Z 0x141bf15b0
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f530@@@@QEAA@PEAVUnk_WsPtrT_141c1f530@@@Z 0x141bf15f0
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f560@@@@QEAA@PEAVUnk_WsPtrT_141c1f560@@@Z 0x141bf1670
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f590@@@@QEAA@PEAVUnk_WsPtrT_141c1f590@@@Z 0x141bf1720
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f5c0@@@@QEAA@AEBV0@@Z 0x141bf1800
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f5c0@@@@QEAA@PEAVUnk_WsPtrT_141c1f5c0@@@Z 0x141bf1840
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f5f0@@@@QEAA@AEBV0@@Z 0x141bf1900
// MS2-PIN: ??0?$MS2Ptr@VUnk_WsPtrT_141c1f5f0@@@@QEAA@PEAVUnk_WsPtrT_141c1f5f0@@@Z 0x141bf1960
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@1@@Z 0x141bedaf0
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@1@@Z 0x141bedb00
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@1@@Z 0x141bedb10
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@1@@Z 0x141bedb20
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@1@@Z 0x141bedb30
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@1@@Z 0x141bedb40
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@1@@Z 0x141bedb50
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@1@@Z 0x141bedb60
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@_KPEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@_KPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@_KPEAX@std@@@1@QEAPEAU?$_Tree_node@_KPEAX@1@@Z 0x141bedb70
// MS2-PIN: ??$destroy@U?$pair@$$CBIUUnk_WsVac0@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIUUnk_WsVac0@@@1@@Z 0x141bedb80
// MS2-PIN: ??$destroy@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@1@QEAU?$pair@$$CB_KUUnk_WsV1d8@@@1@@Z 0x141bedb90
// MS2-PIN: ??$destroy@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@1@QEAU?$pair@$$CB_KUUnk_WsV2e8@@@1@@Z 0x141bedba0
// MS2-PIN: ??$destroy@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@1@@Z 0x141bedbb0
// MS2-PIN: ??$destroy@U?$pair@$$CB_KUUnk_WsV980@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@1@QEAU?$pair@$$CB_KUUnk_WsV980@@@1@@Z 0x141bedc50
// MS2-PIN: ?__empty_global_delete@@YAXPEAX_K@Z 0x141bedc60
// MS2-PIN: ?_Adopt@_Iterator_base0@std@@QEAAXPEBX@Z 0x141bedc60
// MS2-PIN: ??$destroy@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@std@@@1@QEAU?$pair@$$CB_KUUnk_WsVad0@@@1@@Z 0x141bedc60
// MS2-PIN: ??$destroy@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@1@QEAU?$pair@$$CB_KUUnk_WsVab0@@@1@@Z 0x141bedc60
// MS2-PIN: ??$destroy@U?$pair@$$CB_KUUnk_WsV990@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@1@QEAU?$pair@$$CB_KUUnk_WsV990@@@1@@Z 0x141bedc60
// MS2-PIN: ??$destroy@_K@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@_KPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@_KPEAX@std@@@1@QEA_K@Z 0x141bedc60
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@0@0@Z 0x141bedd10
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@0@0@Z 0x141bedd40
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@0@0@Z 0x141bedd40
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@0@0@Z 0x141bedd40
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@0@0@Z 0x141bedd40
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@0@0@Z 0x141bedd40
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@0@0@Z 0x141bedd40
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@0@0@Z 0x141bedd40
// MS2-PIN: ??$emplace@U?$pair@IUUnk_WsVac0@@@std@@@?$_Tree@V?$_Tmap_traits@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@IUUnk_WsVac0@@@1@@Z 0x141bedd70
// MS2-PIN: ??$emplace@U?$pair@_KUUnk_WsV1d8@@@std@@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV1d8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsV1d8@@@1@@Z 0x141bedde0
// MS2-PIN: ??$emplace@U?$pair@_KUUnk_WsV2e8@@@std@@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV2e8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsV2e8@@@1@@Z 0x141bede50
// MS2-PIN: ??$emplace@U?$pair@_KUUnk_WsVad0@@@std@@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsVad0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsVad0@@@1@@Z 0x141bede50
// MS2-PIN: ??$emplace@U?$pair@_KUUnk_WsV980@@@std@@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV980@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV980@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsV980@@@1@@Z 0x141bede50
// MS2-PIN: ??$emplace@U?$pair@_KUUnk_WsV990@@@std@@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV990@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV990@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsV990@@@1@@Z 0x141bede50
// MS2-PIN: ??$emplace@U?$pair@_KUUnk_WsVab0@@@std@@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsVab0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsVab0@@@1@@Z 0x141bede50
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee0f0
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_K@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsVad0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_K@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee190
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee2d0
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_K@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV1d8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_K@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee370
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_K@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsVab0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_K@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee410
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_K@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV990@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV990@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_K@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee410
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_K@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV980@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV980@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_K@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee410
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_K@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV2e8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_K@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee410
// MS2-PIN: ??$erase@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@X@?$_Tree@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@1@V21@@Z 0x141bee550
// MS2-PIN: ??$erase@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@X@?$_Tree@V?$_Tmap_traits@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@1@V21@@Z 0x141bee590
// MS2-PIN: ??$erase@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@std@@X@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV1d8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@1@V21@@Z 0x141bee5d0
// MS2-PIN: ??$erase@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@std@@X@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV2e8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@1@V21@@Z 0x141bee610
// MS2-PIN: ??$erase@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@X@?$_Tree@V?$_Tmap_traits@_KUUnk_WsVad0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@1@V21@@Z 0x141bee650
// MS2-PIN: ??$erase@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@std@@X@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV980@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV980@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@1@V21@@Z 0x141bee650
// MS2-PIN: ??$erase@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@X@?$_Tree@V?$_Tmap_traits@_KUUnk_WsV990@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV990@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@1@V21@@Z 0x141bee650
// MS2-PIN: ??$erase@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@X@?$_Tree@V?$_Tmap_traits@_KUUnk_WsVab0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@1@V21@@Z 0x141bee650
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bee7e0
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bee7f0
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bee800
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bee810
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bee820
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bee830
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bee840
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bee850
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@0@AEAPEAU10@@Z 0x141bee860
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@_KPEAX@std@@@std@@YAAEAPEAU?$_Tree_node@_KPEAX@0@AEAPEAU10@@Z 0x141bee870
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bf2eb0
// MS2-PIN: ??$forward@AEAUUnk_WsV2e8@@@std@@YAAEAUUnk_WsV2e8@@AEAU1@@Z 0x141bee890
// MS2-PIN: ??$forward@AEAUUnk_WsVad0@@@std@@YAAEAUUnk_WsVad0@@AEAU1@@Z 0x141bee8a0
// MS2-PIN: ??$forward@AEAUUnk_WsV980@@@std@@YAAEAUUnk_WsV980@@AEAU1@@Z 0x141bee8a0
// MS2-PIN: ??$forward@AEAUUnk_WsV990@@@std@@YAAEAUUnk_WsV990@@AEAU1@@Z 0x141bee8a0
// MS2-PIN: ??$forward@AEAUUnk_WsVab0@@@std@@YAAEAUUnk_WsVab0@@AEAU1@@Z 0x141bee8a0
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bf2ec0
// MS2-PIN: ??$forward@AEAU?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@YAAEAU?$pair@$$CBHUUnk_WsV1f8@@@0@AEAU10@@Z 0x141bee8c0
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bf2ed0
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bf2ee0
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bf2ef0
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bf2f00
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bf2f10
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bf2f20
// MS2-PIN: ??$forward@AEAU?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@YAAEAU?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@0@AEAU10@@Z 0x141bee930
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141bf2f30
// MS2-PIN: ??0?$allocator@U?$_Tree_node@_KPEAX@std@@@std@@QEAA@XZ 0x141bf2f40
// MS2-PIN: ??0?$allocator@UUnk_WsV9a0@@@std@@QEAA@XZ 0x141bf2f60
// MS2-PIN: ??0?$allocator@UUnk_WsVa00@@@std@@QEAA@XZ 0x141bf2f70
// MS2-PIN: ??0?$allocator@UUnk_WsVa18@@@std@@QEAA@XZ 0x141bf2f80
// MS2-PIN: ?Clone@CAtlStringMgr@ATL@@UEAAPEAUIAtlStringMgr@2@XZ 0x141bee990
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141bee9a0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x141bee9b0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141bee9c0
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@0@AEAV10@@Z 0x141bee9d0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x141bee9e0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x141bee9f0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x141beea00
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@_K@2@XZ 0x141beea10
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_K@2@XZ 0x141beea20
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@_K@2@XZ 0x141beea30
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_K@2@XZ 0x141beea40
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@_K@2@XZ 0x141beea50
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141beea60
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_K@2@XZ 0x141beea70
// MS2-PIN: ??$forward@_K@std@@YA$$QEA_KAEA_K@Z 0x141beea80
// MS2-PIN: ??$forward@AEBU?$less@_K@std@@@std@@YAAEBU?$less@_K@0@AEBU10@@Z 0x141beea90
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@_K@2@XZ 0x141beeaa0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_K@2@XZ 0x141beeab0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@_K@2@XZ 0x141beeac0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_K@2@XZ 0x141beead0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@_K@2@XZ 0x141beeae0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_K@2@XZ 0x141beeaf0
// MS2-PIN: ??$forward@U?$pair@IUUnk_WsVac0@@@std@@@std@@YA$$QEAU?$pair@IUUnk_WsVac0@@@0@AEAU10@@Z 0x141beeb00
// MS2-PIN: ??$forward@U?$pair@_KUUnk_WsV1d8@@@std@@@std@@YA$$QEAU?$pair@_KUUnk_WsV1d8@@@0@AEAU10@@Z 0x141beeb10
// MS2-PIN: ??$forward@U?$pair@_KUUnk_WsV2e8@@@std@@@std@@YA$$QEAU?$pair@_KUUnk_WsV2e8@@@0@AEAU10@@Z 0x141beeb20
// MS2-PIN: ??$forward@U?$pair@HUUnk_WsV1f8@@@std@@@std@@YA$$QEAU?$pair@HUUnk_WsV1f8@@@0@AEAU10@@Z 0x141beeb20
// MS2-PIN: ??$forward@U?$pair@_KUUnk_WsV980@@@std@@@std@@YA$$QEAU?$pair@_KUUnk_WsV980@@@0@AEAU10@@Z 0x141beeb20
// MS2-PIN: ??$forward@U?$pair@_KUUnk_WsV990@@@std@@@std@@YA$$QEAU?$pair@_KUUnk_WsV990@@@0@AEAU10@@Z 0x141beeb20
// MS2-PIN: ??$forward@U?$pair@_KUUnk_WsVab0@@@std@@@std@@YA$$QEAU?$pair@_KUUnk_WsVab0@@@0@AEAU10@@Z 0x141beeb20
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@_KPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@_K@2@XZ 0x141beeb30
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@2@XZ 0x141beeb40
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@2@XZ 0x141beeb50
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@0@AEAV10@@Z 0x141beeb60
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@2@XZ 0x141beeb70
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@std@@@2@XZ 0x141beeb80
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141beeb90
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@2@XZ 0x141beeba0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@std@@@2@XZ 0x141beebb0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@2@XZ 0x141beebc0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@std@@@2@XZ 0x141beebd0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@2@XZ 0x141beebe0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@std@@@2@XZ 0x141beebf0
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141beec00
// MS2-PIN: ??$insert@U?$pair@IUUnk_WsVac0@@@std@@X@?$map@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@IUUnk_WsVac0@@@1@@Z 0x141beec90
// MS2-PIN: ??$insert@U?$pair@_KUUnk_WsV1d8@@@std@@X@?$map@_KUUnk_WsV1d8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsV1d8@@@1@@Z 0x141beecd0
// MS2-PIN: ??$insert@U?$pair@_KUUnk_WsV2e8@@@std@@X@?$map@_KUUnk_WsV2e8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsV2e8@@@1@@Z 0x141beed10
// MS2-PIN: ??$insert@U?$pair@_KUUnk_WsVad0@@@std@@X@?$map@_KUUnk_WsVad0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsVad0@@@1@@Z 0x141beed10
// MS2-PIN: ??$insert@U?$pair@HUUnk_WsV1f8@@@std@@X@?$map@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@HUUnk_WsV1f8@@@1@@Z 0x141beed10
// MS2-PIN: ??$insert@U?$pair@_KUUnk_WsV980@@@std@@X@?$map@_KUUnk_WsV980@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV980@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsV980@@@1@@Z 0x141beed10
// MS2-PIN: ??$insert@U?$pair@_KUUnk_WsV990@@@std@@X@?$map@_KUUnk_WsV990@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV990@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsV990@@@1@@Z 0x141beed10
// MS2-PIN: ??$insert@U?$pair@_KUUnk_WsVab0@@@std@@X@?$map@_KUUnk_WsVab0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@_KUUnk_WsVab0@@@1@@Z 0x141beed10
// MS2-PIN: ??$make_pair@AEAHAEAUUnk_WsV1f8@@@std@@YA?AU?$pair@HUUnk_WsV1f8@@@0@AEAHAEAUUnk_WsV1f8@@@Z 0x141beed50
// MS2-PIN: ??$make_pair@AEAIAEAUUnk_WsVac0@@@std@@YA?AU?$pair@IUUnk_WsVac0@@@0@AEAIAEAUUnk_WsVac0@@@Z 0x141beeda0
// MS2-PIN: ??$make_pair@AEA_KAEAUUnk_WsV1d8@@@std@@YA?AU?$pair@_KUUnk_WsV1d8@@@0@AEA_KAEAUUnk_WsV1d8@@@Z 0x141beedf0
// MS2-PIN: ??$make_pair@AEA_KAEAUUnk_WsV2e8@@@std@@YA?AU?$pair@_KUUnk_WsV2e8@@@0@AEA_KAEAUUnk_WsV2e8@@@Z 0x141beee40
// MS2-PIN: ??$make_pair@AEA_KAEAUUnk_WsVad0@@@std@@YA?AU?$pair@_KUUnk_WsVad0@@@0@AEA_KAEAUUnk_WsVad0@@@Z 0x141beee90
// MS2-PIN: ??$make_pair@AEA_KAEAUUnk_WsV980@@@std@@YA?AU?$pair@_KUUnk_WsV980@@@0@AEA_KAEAUUnk_WsV980@@@Z 0x141beee90
// MS2-PIN: ??$make_pair@AEA_KAEAUUnk_WsV990@@@std@@YA?AU?$pair@_KUUnk_WsV990@@@0@AEA_KAEAUUnk_WsV990@@@Z 0x141beee90
// MS2-PIN: ??$make_pair@AEA_KAEAUUnk_WsVab0@@@std@@YA?AU?$pair@_KUUnk_WsVab0@@@0@AEA_KAEAUUnk_WsVab0@@@Z 0x141beee90
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHUUnk_WsV1f8@@@1@XZ 0x141beeee0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@2@XZ 0x141beef00
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@std@@@2@XZ 0x141beef10
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@2@XZ 0x141beef20
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@std@@@2@XZ 0x141beef30
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@std@@@2@XZ 0x141beef40
// MS2-PIN: ??$try_emplace@$$V@?$map@_KUUnk_WsVad0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@_N@1@AEB_K@Z 0x141beef50
// MS2-PIN: ??$try_emplace@$$V@?$map@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141beef90
// MS2-PIN: ??$try_emplace@$$V@?$map@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x141beefd0
// MS2-PIN: ??$try_emplace@$$V@?$map@_KUUnk_WsV1d8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@std@@_N@1@AEB_K@Z 0x141bef010
// MS2-PIN: ??$try_emplace@$$V@?$map@_KUUnk_WsVab0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@_N@1@AEB_K@Z 0x141bef050
// MS2-PIN: ??$try_emplace@$$V@?$map@_KUUnk_WsV990@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV990@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@_N@1@AEB_K@Z 0x141bef050
// MS2-PIN: ??$try_emplace@$$V@?$map@_KUUnk_WsV980@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV980@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@std@@_N@1@AEB_K@Z 0x141bef050
// MS2-PIN: ??$try_emplace@$$V@?$map@_KUUnk_WsV2e8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@std@@_N@1@AEB_K@Z 0x141bef050
// MS2-PIN: ??$try_emplace@$$V@?$map@HV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@std@@_N@1@$$QEAH@Z 0x141bef090
// MS2-PIN: ??0?$CAtlList@UUnk_WsV058@@V?$CElementTraits@UUnk_WsV058@@@ATL@@@ATL@@QEAA@I@Z 0x141bef200
// MS2-PIN: ??0?$CAtlMap@IUUnk_WsV350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV350@@@3@@ATL@@QEAA@IMMMI@Z 0x141bef260
// MS2-PIN: ??0?$CAtlMap@IUUnk_WsV738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV738@@@3@@ATL@@QEAA@IMMMI@Z 0x141bef350
// MS2-PIN: ??0?$CAtlMap@IUUnk_WsV848@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV848@@@3@@ATL@@QEAA@IMMMI@Z 0x141bef440
// MS2-PIN: ??0?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@QEAA@IMMMI@Z 0x141bef530
// MS2-PIN: ??0?$CAtlMap@IUUnk_WsV930@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV930@@@3@@ATL@@QEAA@IMMMI@Z 0x141bef620
// MS2-PIN: ??0?$CAtlMap@IUUnk_WsV3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV3a0@@@3@@ATL@@QEAA@IMMMI@Z 0x141bef710
// MS2-PIN: ??0?$CAtlMap@IUUnk_WsV780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV780@@@3@@ATL@@QEAA@IMMMI@Z 0x141bef800
// MS2-PIN: ??0?$CAtlMap@_KUUnk_WsV5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV5a0@@@3@@ATL@@QEAA@IMMMI@Z 0x141bef8f0
// MS2-PIN: ??0?$CAtlMap@_KUUnk_WsV420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV420@@@3@@ATL@@QEAA@IMMMI@Z 0x141bef9e0
// MS2-PIN: ??0?$CAtlMap@_KUUnk_WsV2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV2f8@@@3@@ATL@@QEAA@IMMMI@Z 0x141befad0
// MS2-PIN: ??0?$CAtlMap@_KUUnk_WsV468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV468@@@3@@ATL@@QEAA@IMMMI@Z 0x141befbc0
// MS2-PIN: ??0?$CRBMap@IUUnk_WsV1a8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV1a8@@@3@@ATL@@QEAA@_K@Z 0x141befcb0
// MS2-PIN: ??0?$CRBMap@IUUnk_WsV148@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV148@@@3@@ATL@@QEAA@_K@Z 0x141befce0
// MS2-PIN: ??0?$CRBMap@IUUnk_WsV0e8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV0e8@@@3@@ATL@@QEAA@_K@Z 0x141befd10
// MS2-PIN: ??0?$CRBMap@IUUnk_WsV118@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV118@@@3@@ATL@@QEAA@_K@Z 0x141befd40
// MS2-PIN: ??0?$CRBMap@IUUnk_WsV708@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV708@@@3@@ATL@@QEAA@_K@Z 0x141befd70
// MS2-PIN: ??0?$CRBMap@_KUUnk_WsV6d8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV6d8@@@3@@ATL@@QEAA@_K@Z 0x141befda0
// MS2-PIN: ??0?$CRBMap@_KUUnk_WsV4e0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV4e0@@@3@@ATL@@QEAA@_K@Z 0x141befdd0
// MS2-PIN: ??0?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV7c8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV7c8@@@2@@ATL@@QEAA@_K@Z 0x141befe00
// MS2-PIN: ??0?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV5e8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV5e8@@@2@@ATL@@QEAA@_K@Z 0x141befe30
// MS2-PIN: ??0?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV4b0@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV4b0@@@2@@ATL@@QEAA@_K@Z 0x141befe60
// MS2-PIN: ??0?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV678@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV678@@@2@@ATL@@QEAA@_K@Z 0x141befe90
// MS2-PIN: ??0?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV510@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV510@@@2@@ATL@@QEAA@_K@Z 0x141befec0
// MS2-PIN: ??0?$CRBMap@_KUUnk_WsV6a8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV6a8@@@3@@ATL@@QEAA@_K@Z 0x141befef0
// MS2-PIN: ??0?$CRBMap@_KUUnk_WsV0b8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV0b8@@@3@@ATL@@QEAA@_K@Z 0x141beff50
// MS2-PIN: ??0?$CRBMap@HUUnk_WsV540@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_WsV540@@@3@@ATL@@QEAA@_K@Z 0x141beff80
// MS2-PIN: ??0?$CRBMap@HUUnk_WsV570@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_WsV570@@@3@@ATL@@QEAA@_K@Z 0x141beffb0
// MS2-PIN: ??0?$CRBTree@HUUnk_WsV540@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_WsV540@@@3@@ATL@@IEAA@_K@Z 0x141beffe0
// MS2-PIN: ??0?$CRBTree@HUUnk_WsV570@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_WsV570@@@3@@ATL@@IEAA@_K@Z 0x141bf0040
// MS2-PIN: ??0?$CRBTree@IUUnk_WsV1a8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV1a8@@@3@@ATL@@IEAA@_K@Z 0x141bf00a0
// MS2-PIN: ??0?$CRBTree@IUUnk_WsV148@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV148@@@3@@ATL@@IEAA@_K@Z 0x141bf0100
// MS2-PIN: ??0?$CRBTree@IUUnk_WsV0e8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV0e8@@@3@@ATL@@IEAA@_K@Z 0x141bf0160
// MS2-PIN: ??0?$CRBTree@IUUnk_WsV118@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV118@@@3@@ATL@@IEAA@_K@Z 0x141bf01c0
// MS2-PIN: ??0?$CRBTree@IUUnk_WsV708@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV708@@@3@@ATL@@IEAA@_K@Z 0x141bf0220
// MS2-PIN: ??0?$CRBTree@_KUUnk_WsV6d8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV6d8@@@3@@ATL@@IEAA@_K@Z 0x141bf0280
// MS2-PIN: ??0?$CRBTree@_KUUnk_WsV4e0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV4e0@@@3@@ATL@@IEAA@_K@Z 0x141bf02e0
// MS2-PIN: ??0?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV7c8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV7c8@@@2@@ATL@@IEAA@_K@Z 0x141bf0340
// MS2-PIN: ??0?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV5e8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV5e8@@@2@@ATL@@IEAA@_K@Z 0x141bf03a0
// MS2-PIN: ??0?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV4b0@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV4b0@@@2@@ATL@@IEAA@_K@Z 0x141bf0400
// MS2-PIN: ??0?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV678@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV678@@@2@@ATL@@IEAA@_K@Z 0x141bf0460
// MS2-PIN: ??0?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV510@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV510@@@2@@ATL@@IEAA@_K@Z 0x141bf04c0
// MS2-PIN: ??0?$CRBTree@_KUUnk_WsV6a8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV6a8@@@3@@ATL@@IEAA@_K@Z 0x141bf0520
// MS2-PIN: ??0?$CRBTree@_KUUnk_WsV0b8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV0b8@@@3@@ATL@@IEAA@_K@Z 0x141bf05e0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf1aa0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@1@@Z 0x141bf1b40
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@QEAA@XZ 0x141bf1c00
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bf1c30
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bf1c60
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x141bf1c90
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@_KUUnk_WsV990@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV990@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1cc0
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@_KUUnk_WsV980@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV980@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1cf0
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@_KUUnk_WsV2e8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1d20
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@_KUUnk_WsV1d8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1d50
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@_KUUnk_WsVab0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1d80
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@_KUUnk_WsVad0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1db0
// MS2-PIN: ??0?$_Tree@V?$_Tset_traits@_KU?$less@_K@std@@V?$allocator@_K@2@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1de0
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bf1e10
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bf1e50
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x141bf1e90
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsV990@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV990@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1ed0
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsV980@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV980@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1f10
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsV2e8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1f50
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsV1d8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1f90
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsVab0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf1fd0
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsVad0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf2010
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@_KU?$less@_K@std@@V?$allocator@_K@2@$0A@@std@@@std@@QEAA@AEBU?$less@_K@1@@Z 0x141bf2050
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@_KPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@_K@std@@@1@@Z 0x141bf2090
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf2110
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf2170
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf2170
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141bf2170
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf2170
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf21d0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf22f0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf2350
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf2350
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf2350
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf2350
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@1@@Z 0x141bf2370
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf23b0
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@1@@Z 0x141bf25d0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@_KPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@_K@std@@@1@@Z 0x141bf2610
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@1@@Z 0x141bf2650
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141bf2690
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@1@@Z 0x141bf26b0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141bf26f0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@1@@Z 0x141bf2710
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141bf2750
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@1@@Z 0x141bf2770
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@1@@Z 0x141bf27b0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@1@@Z 0x141bf27f0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@1@@Z 0x141bf2830
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141bf2870
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141bf28d0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141bf28d0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141bf28d0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141bf28d0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@1@@Z 0x141bf28f0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x141bf2930
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@QEAA@XZ 0x141bf2950
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@QEAA@XZ 0x141bf2980
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV1d8@@@std@@@std@@@std@@QEAA@XZ 0x141bf29b0
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@QEAA@XZ 0x141bf29e0
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@QEAA@XZ 0x141bf2a10
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@QEAA@XZ 0x141bf2a40
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@QEAA@XZ 0x141bf2a70
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@QEAA@XZ 0x141bf2aa0
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@QEAA@XZ 0x141bf2ad0
// cf9: additional attribution accepted by tplpin --simulate.
// MS2-PIN: ??$forward@AEAU?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@YAAEAU?$pair@$$CB_KUUnk_WsVad0@@@0@AEAU10@@Z 0x141bee8b0
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@0@AEBV10@@Z 0x141bee970
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@0@AEBV10@@Z 0x141bee980
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsVac0@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@@1@@Z 0x141bf20d0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV2e8@@@std@@@std@@@1@@Z 0x141bf2190
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV980@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV980@@@std@@@std@@@1@@Z 0x141bf21f0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsV990@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsV990@@@std@@@std@@@1@@Z 0x141bf2230
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVab0@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVab0@@@std@@@std@@@1@@Z 0x141bf2270
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@1@@Z 0x141bf22b0
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsVad0@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsVad0@@@std@@@std@@@1@@Z 0x141bf23d0
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@1@@Z 0x141bf2410
// The smart pointer ctors over NiRefObject (add-ref NiRefObject::IncRefCount, bound elsewhere).
// MS2-PIN: ??0?$SmartPointer@VCEntityHider@@@efd@@QEAA@AEBV01@@Z 0x141bf0e90
// MS2-PIN: ??0?$SmartPointer@VCEntityHider@@@efd@@QEAA@PEAVCEntityHider@@@Z 0x141bf0ed0
// MS2-PIN: ??0?$SmartPointer@VCEntityShower@@@efd@@QEAA@AEBV01@@Z 0x141bf0f10
// MS2-PIN: ??0?$SmartPointer@VCEntityShower@@@efd@@QEAA@PEAVCEntityShower@@@Z 0x141bf0f50
// MS2-PIN: ??0?$Unk_WsNiPtr@UUnk_WsElem@@@@QEAA@PEAUUnk_WsElem@@@Z 0x141bf0f90
// MS2-PIN: ??0?$Unk_WsNiPtr@VCWireframeManager@@@@QEAA@PEAVCWireframeManager@@@Z 0x141bf1020
// MS2-PIN: ??0?$Unk_WsNiPtr@VChaosLightEffectLayerManager@@@@QEAA@PEAVChaosLightEffectLayerManager@@@Z 0x141bf1060
// MS2-PIN: ??0?$Unk_WsNiPtr@VTextureLayerManager@@@@QEAA@PEAVTextureLayerManager@@@Z 0x141bf1130
// MS2-PIN: ??0?$SmartPointer@VEntityManager@egf@@@efd@@QEAA@AEBV01@@Z 0x141bf10e0
// MS2-PIN: ??0?$TSingleton@VWorldService@@@@QEAA@XZ 0x141bf1a00
// MS2-PIN: ??0?$MS2Ptr@UUnk_WsD_EffectCtx@@@@QEAA@AEBV0@@Z 0x141bf1170
// The element destroys over the real container types (worldservice_real.h).
// MS2-PIN: ??$destroy@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@1@@Z 0x141bedbd0
// MS2-PIN: ??$destroy@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@1@@Z 0x141bedbf0
// MS2-PIN: ??$destroy@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@1@@Z 0x141bedc10
// MS2-PIN: ??$destroy@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@1@@Z 0x141bedc30
// MS2-PIN: ??$destroy@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@1@@Z 0x141bedc70
// MS2-PIN: ??$destroy@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@?$_Default_allocator_traits@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@1@QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@1@@Z 0x141bedc90
// MS2-PIN: ??$destroy@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@?$_Default_allocator_traits@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@1@QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@1@@Z 0x141bedcb0
// MS2-PIN: ??$destroy@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@1@QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@1@@Z 0x141bedcd0
// The vector::emplace_back COMDATs (sorted by mangled name).
// MS2-PIN: ??$emplace_back@AEAV?$MS2Ptr@VCLiftableTargetBox@@@@@?$vector@V?$MS2Ptr@VCLiftableTargetBox@@@@V?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@@std@@QEAAXAEAV?$MS2Ptr@VCLiftableTargetBox@@@@@Z 0x141bedec0
// MS2-PIN: ??$emplace_back@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@QEAAX$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@1@@Z 0x141bedf30
// MS2-PIN: ??$emplace_back@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@QEAAX$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@1@@Z 0x141bedfa0
// MS2-PIN: ??$emplace_back@V?$MS2Ptr@VCLiftableObject@@@@@?$vector@V?$MS2Ptr@VCLiftableObject@@@@V?$allocator@V?$MS2Ptr@VCLiftableObject@@@@@std@@@std@@QEAAX$$QEAV?$MS2Ptr@VCLiftableObject@@@@@Z 0x141bee010
// MS2-PIN: ??$emplace_back@V?$MS2Ptr@VMS2ActorUpdater@@@@@?$vector@V?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@QEAAX$$QEAV?$MS2Ptr@VMS2ActorUpdater@@@@@Z 0x141bee080
// m_9d0's CRBMap<int, int> constructor and its CRBTree base constructor.
// MS2-PIN: ??0?$CRBMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@_K@Z 0x141beff20
// MS2-PIN: ??0?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@IEAA@_K@Z 0x141bf0580
// MS2-PIN: ??0?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x141bef1c0
// The two unrecovered trees (Unk_WsTreeA / Unk_WsTreeB, see the driver).
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_WsTreeAValue@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bf1a50
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HUUnk_WsTreeAValue@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141bf1aa0
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@@std@@@1@@Z 0x141bf1ac0
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@@std@@@1@@Z 0x141bf1b00
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@@std@@@1@@Z 0x141bf1b40
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeAValue@@@std@@@std@@@std@@QEAA@XZ 0x141bf1c00
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@@std@@@1@@Z 0x141bf2310
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@@std@@@1@@Z 0x141bf2590
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@@std@@@1@@Z 0x141bf2890
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsTreeBValue@@@std@@@std@@@std@@QEAA@XZ 0x141bf2b00
// map::operator[] emplace_hint of m_ac0 (int key) and m_ad0 (const __int64& key).
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee230
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_J@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@_JV?$MS2Ptr@VRecad0@WsReal@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_J@1@$$QEAV?$tuple@$$V@1@@Z 0x141bee4b0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#define WS_INST_FN Unk_WsInst3
#include "worldservice_inst.inl"

// The CU's 16-byte smart pointer constructors (TPtr<T> = our MS2Ptr<T>, and TPtrValue<T>; 0x141bf1170-0x141bf19f2).
// Their callers are the WorldService methods of the other parts, which still reach them by VA. The pointee classes
// whose add-ref COMDAT is emitted by this CU (0x141c1f4a0..0x141c1f5f0, part 8) are not recovered: each is named after
// that add-ref VA. The others are the shared classes whose add-ref another unit already binds.
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/guess/fieldproperty.h"
#include "ms2/guess/regionskillobject.h"
#include "ms2/client/ms2/uidebugtooltip.h"
#include "alphaanimation.h"
#include <new>
#include <efd/MessageService.h>
#include <efd/AssetLoadResponse.h>
#include <egf/EntityChangeMessage.h>
#include <egf/EntityLoaderMessages.h>
#include <egf/FlatModelFactoryResponse.h>
#include <ecr/CoreRuntimeMessages.h>
#include "ms2/placeholder/physxpropmessage.h"
#include <egmAnimation/ActorMessages.h>
#include "ms2/placeholder/tfunctor.h"
#include "ms2/placeholder/coptimizer.h"
#include "worldservice_real.h"
#include "liftableobject.h"
#include "liftabletarget.h"                            // CEntityShower / CEntityHider (m_980 / m_990 values)
struct Unk_WsD_EffectCtx : public CPtred {};            // m_848 value: the effect of an effect message (add-ref 0x141c1f4a0)
class Unk_WsPtrT_141c1f500 : public CPtred {};          // tag-range object (FUN_141bc3560), camera shake (FUN_141bc9020)
class Unk_WsPtrT_141c1f530 : public CPtred {};          // m_540 / m_570 value (FUN_141bd3920)
class Unk_WsPtrT_141c1f560 : public CPtred {};
class Unk_WsPtrT_141c1f590 : public CPtred {};
class Unk_WsPtrT_141c1f5c0 : public CPtred {};          // FUN_141bcda90
class Unk_WsPtrT_141c1f5f0 : public CPtred {};          // FUN_141bd0220, m_708 rebuild (FUN_141bda580)
class Unk_RideeFieldObj : public CPtred {};
class Unk_GoField : public CPtred {};
class Unk_WsB_Lift : public CPtred {};
class Unk_AkoLiftTarget : public CPtred {};
typedef TPtrValue<ATL::CAtlList<efd::SmartPointer<egf::Entity> > > Unk_WsEntityListPtr;   // m_208 value (TPtredDummy box 0x141bf19b0)

template <class T> static void WsDrivePtr(T* p, int n)
{
    MS2Ptr<T> a(p);
    MS2Ptr<T> b(a);
    MS2Ptr<T> c(static_cast<MS2Ptr<T>&&>(b));
    MS2Ptr<T> d(n);
    MS2Ptr<T> e;
}
void Unk_WsInst3Ptrs(int n)
{
    WsDrivePtr<Unk_WsD_EffectCtx>(0, n);
    WsDrivePtr<Unk_WsPtrT_141c1f500>(0, n);
    WsDrivePtr<Unk_WsPtrT_141c1f530>(0, n);
    WsDrivePtr<Unk_WsPtrT_141c1f560>(0, n);
    WsDrivePtr<Unk_WsPtrT_141c1f590>(0, n);
    WsDrivePtr<Unk_WsPtrT_141c1f5c0>(0, n);
    WsDrivePtr<Unk_WsPtrT_141c1f5f0>(0, n);
    WsDrivePtr<Unk_RideeFieldObj>(0, n);
    WsDrivePtr<Unk_GoField>(0, n);
    WsDrivePtr<Unk_WsB_Lift>(0, n);
    WsDrivePtr<Unk_AkoLiftTarget>(0, n);
    WsDrivePtr<CRegionSkillObject>(0, n);
    WsDrivePtr<FieldProperty>(0, n);
    WsDrivePtr<UIDebugTooltip>(0, n);
    Unk_WsEntityListPtr a(Unk_GrNewTag(0));
    Unk_WsEntityListPtr b(a);
    const Unk_WsEntityListPtr& c = b;
    Unk_WsEntityListPtr d(c);
    Unk_WsEntityListPtr e(n);
    Unk_WsEntityListPtr f;
}

// The other smart pointer constructors of the CU (0x141bf0e70-0x141bf1130): the m_980 / m_990 map values and the
// NiPointer-like members of WorldService.
void Unk_WsInst3NiPtrs(CEntityHider* pHider, CEntityShower* pShower)
{
    efd::SmartPointer<CEntityHider> spHider(pHider);
    efd::SmartPointer<CEntityHider> spHider2(spHider);
    efd::SmartPointer<CEntityShower> spShower(pShower);
    efd::SmartPointer<CEntityShower> spShower2(spShower);
    Unk_WsNiPtr<CWireframeManager> spWireframe(0);
    Unk_WsNiPtr<Unk_WsElem> spElem(0);
    Unk_WsNiPtr<TextureLayerManager> spTextureLayer(0);
    Unk_WsNiPtr<ChaosLightEffectLayerManager> spChaosLight(0);
    Unk_WsOptional<float> optional;
}
void Unk_WsInst3Bases(const efd::SmartPointer<egf::EntityManager>& spEntityManager)
{
    efd::SmartPointer<egf::EntityManager> spCopy(spEntityManager);    // m_268 copy (FUN_141bc16d0)
    TSingleton<WorldService> singleton;
    ATL::CRBMap<int, int> map9d0;
    ATL::CAtlArray<void*> pointers;
}

// The message handler constructors (0x141bf07d0-0x141bf0e6d) of the EE_HANDLER statics of worldservice_1.cpp. Placement
// new instantiates them without a second set of self-registering statics.
void Unk_WsInst3Handlers(void* p)
{
    new (p) efd::MessageHandlerImpl<WorldService, egmAnimation::ActorAddedMessage>(&WorldService::FUN_141bbfb50);
    new (p) efd::MessageHandlerImpl<WorldService, egmAnimation::ActorRemovedMessage>(&WorldService::FUN_141bbfde0);
    new (p) efd::MessageHandlerImpl<WorldService, efd::AssetLoadResponse>(&WorldService::FUN_141bbf9f0);
    new (p) efd::MessageHandlerImpl<WorldService, egf::EntityLoadResult>(&WorldService::FUN_141bc0a70);
    new (p) efd::MessageHandlerImpl<WorldService, ecr::SceneGraphAddedMessage>(&WorldService::FUN_141bbfe30);
    new (p) efd::MessageHandlerImpl<WorldService, ecr::SceneGraphRemovedMessage>(&WorldService::FUN_141bc0290);
    new (p) efd::MessageSubclassHandler<WorldService, efd::AssetLoadResponse, egf::FlatModelFactoryResponse>(&WorldService::FUN_141bc0f50);
    new (p) efd::MessageWrapperSubclassHandler<WorldService, egf::EntityChangeMessage, egf::EntityChangeMessage, 8196>(&WorldService::FUN_141bbfa50);
    new (p) efd::MessageWrapperSubclassHandler<WorldService, egf::EntityChangeMessage, egf::EntityChangeMessage, 8253>(&WorldService::FUN_141bbd640);
    new (p) efd::MessageWrapperSubclassHandler<WorldService, egf::EntityChangeMessage, egf::EntityChangeMessage, 8254>(&WorldService::FUN_141bbf2f0);
    new (p) efd::MessageWrapperSubclassHandler<WorldService, ecrPhysX::PhysXPropMessage, ecrPhysX::PhysXPropMessage, 12299>(&WorldService::FUN_141bc0530);
}

// The ClassFunHandler constructors (0x141bf0640-0x141bf07c4: object/method and copy) of the two functors of the CU.
void Unk_WsInst3Functors(WorldService* pService, COptimizer* pOptimizer)
{
    TFunctor<void, EmptyParam> fnService(pService, &WorldService::FUN_141bc1640);
    TFunctor<void, EmptyParam> fnOptimizer(pOptimizer, reinterpret_cast<void (COptimizer::*)()>(&COptimizer::FUN_1414a5a30));
}

// The element destroys of the real containers (0x141bedbd0-0x141bedcef; see worldservice_real.h).
template <class Alloc, class T> static void WsDriveDestroy(T* p)
{
    Alloc al;
    std::allocator_traits<Alloc>::destroy(al, p);
}
template <class Map> static void WsDriveNodeDestroy(typename Map::value_type* p)
{
    WsDriveDestroy<std::allocator<std::_Tree_node<typename Map::value_type, void*> > >(p);
}
void Unk_WsInst3Destroys()
{
    WsDriveNodeDestroy<WsReal::Mapac0>(0);
    WsDriveNodeDestroy<WsReal::Map990>(0);
    WsDriveNodeDestroy<WsReal::Map980>(0);
    WsDriveNodeDestroy<WsReal::Map2e8>(0);
    WsDriveNodeDestroy<WsReal::Mapad0>(0);
    WsDriveDestroy<std::allocator<std::pair<CStringA, CStringA> > >(static_cast<std::pair<CStringA, CStringA>*>(0));
    WsDriveDestroy<WsReal::Veca00::allocator_type>(static_cast<WsReal::Veca00::value_type*>(0));
    WsDriveDestroy<WsReal::Veca18::allocator_type>(static_cast<WsReal::Veca18::value_type*>(0));
}

// The tree constructors and iterators of the real containers (0x141bf1a50-0x141bf2b23).
// Two more trees of the CU whose element types are not recovered (their node helpers live in parts 2 and 8): tree A
// (0x141bf1a50-0x141bf1c23, constructed by value), tree B (0x141bf2310-0x141bf2b23).
struct Unk_WsTreeAValue { void* p; };
struct Unk_WsTreeBValue { void* p; };
typedef std::map<int, Unk_WsTreeAValue> Unk_WsTreeA;
typedef std::map<int, Unk_WsTreeBValue> Unk_WsTreeB;
template <class C> static void WsDriveTree()
{
    C c;
    typename C::iterator it = c.begin();
    typename C::const_iterator cit = it;
    ++cit;
    it._Unwrapped();
}
template <class Map> static void WsDriveIndex(Map& m, const typename Map::key_type& key)
{
    m[key];
}
void Unk_WsInst3Trees()
{
    WsDriveTree<WsReal::Set048>();
    WsDriveTree<WsReal::EntitySet>();
    WsDriveTree<WsReal::Map1d8>();
    WsDriveTree<WsReal::Map1e8>();
    WsDriveTree<WsReal::Map1f8>();
    WsDriveTree<WsReal::Map2e8>();
    WsDriveTree<WsReal::Map980>();
    WsDriveTree<WsReal::Map990>();
    WsDriveTree<WsReal::Mapab0>();
    WsDriveTree<WsReal::Mapac0>();
    WsDriveTree<WsReal::Mapad0>();
    WsDriveTree<Unk_WsTreeA>();
    WsDriveTree<Unk_WsTreeB>();
}
void Unk_WsInst3Index(const egf::EntityID& id, WsReal::Map1d8& m1d8, WsReal::Map2e8& m2e8, WsReal::Map980& m980,
    WsReal::Map990& m990, WsReal::Mapab0& mab0)
{
    WsDriveIndex(m1d8, id);
    WsDriveIndex(m2e8, id);
    WsDriveIndex(m980, id);
    WsDriveIndex(m990, id);
    WsDriveIndex(mab0, id);
}
void Unk_WsInst3IndexInt(WsReal::Mapac0& mac0, WsReal::Mapad0& mad0)
{
    WsDriveIndex(mac0, 0);
    WsDriveIndex(mad0, 0);
}

// The vector::emplace_back instantiations (0x141bedec0-0x141bee0ef).
void Unk_WsInst3Emplaces(MS2Ptr<CLiftableTargetBox>& box)
{
    std::vector<MS2Ptr<CLiftableTargetBox> > boxes;
    boxes.emplace_back(box);
    WsReal::Veca00 a00;
    a00.emplace_back(WsReal::Veca00::value_type());
    WsReal::Veca18 a18;
    a18.emplace_back(WsReal::Veca18::value_type());
    std::vector<MS2Ptr<CLiftableObject> > lifts;
    lifts.emplace_back(MS2Ptr<CLiftableObject>());
    WsReal::Vec9a0 updaters;
    updaters.emplace_back(MS2Ptr<MS2ActorUpdater>());
}
