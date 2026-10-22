// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMessenger / UIMessengerBrowser: the chat windows and
// their owner, see uimessenger.h.
// MS2-UNIT: client\ms2\uimessenger.cpp
// MS2-RANGE: 0x141a08af0-0x141a30f30 .text$mn
// MS2-RANGE: 0x140117620-0x140117c70 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_keyInputController@@YAXXZ 0x1401179e0 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141a17d60 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141a17d90 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141a17df0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@$$QEA_N@Z 0x141a17ed0 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141a17f20 ; prop
// MS2-PIN: ??$?0HAEAH$0A@@?$pair@HH@std@@QEAA@$$QEAHAEAH@Z 0x141a17fc0 ; unique
// MS2-PIN: ??$?0HH$0A@@?$pair@$$CBHH@std@@QEAA@$$QEAU?$pair@HH@1@@Z 0x141a18010 ; unique
// MS2-PIN: ??$?0VUIMessenger@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIMessenger@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x141a180a0 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@$$QEA_N@Z 0x141a18320 ; prop
// MS2-PIN: ??$?8PEAVUIMessenger@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIMessenger@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x141a18370 ; prop
// MS2-PIN: ??$?8PEAVUIMessenger@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIMessenger@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x141a183e0 ; prop
// MS2-PIN: ??$?8PEAVUIMessenger@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIMessenger@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x141a18450 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHH@std@@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHH@1@@Z 0x141a18550 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@HH@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@$$QEAU?$pair@HH@1@@Z 0x141a18630 ; prop
// MS2-PIN: ??$_Copy_memmove@PEAHPEAH@std@@YAPEAHPEAH00@Z 0x141a186c0 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$allocator@H@std@@@std@@YAXPEAH0AEAV?$allocator@H@0@U?$integral_constant@_N$00@0@@Z 0x141a18790 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@H@?$vector@HV?$allocator@H@std@@@std@@AEAAX$$QEAH@Z 0x141a189d0 ; unique
// MS2-PIN: ??$_Emplace_reallocate@H@?$vector@HV?$allocator@H@std@@@std@@QEAAPEAHQEAH$$QEAH@Z 0x141a18ce0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@PEAU01@@Z 0x141a18f20 ; prop
// MS2-PIN: ??$_Get_unwrapped@H@std@@YAPEAHQEAH@Z 0x141a19050 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAHPEAH@std@@YA_JAEBQEAH0Urandom_access_iterator_tag@0@@Z 0x141a190b0 ; unique
// MS2-PIN: ??$_Idl_distance@PEAHPEAH@std@@YA_JAEBQEAH0@Z 0x141a19110 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHH@std@@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEAU?$pair@$$CBHH@1@1@Z 0x141a19140 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHH@std@@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHH@1@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@@Z 0x141a19800 ; unique
// MS2-PIN: ??$_Kfn@$$CBHH@?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHH@1@@Z 0x141a1a020 ; prop
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEBH@Z 0x141a1a030 ; prop
// MS2-PIN: ??$_Ptr_move_cat@HH@std@@YA?AU_Really_trivial_ptr_iterator_tag@0@AEBQEAH0@Z 0x141a1a1d0 ; unique
// MS2-PIN: ??$_Unfancy@H@std@@YAPEAHPEAH@Z 0x141a1a240 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAHPEAHV?$allocator@H@std@@@std@@YAPEAHQEAH0PEAHAEAV?$allocator@H@0@@Z 0x141a1a480 ; unique
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@HHV?$allocator@H@std@@@std@@YAPEAHQEAH00AEAV?$allocator@H@0@U_Really_trivial_ptr_iterator_tag@0@U?$integral_constant@_N$00@0@@Z 0x141a1a5c0 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@0@AEAPEAU10@@Z 0x141a1a600 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBHH@std@@@std@@YAPEAU?$pair@$$CBHH@0@AEAU10@@Z 0x141a1a620 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@0@AEAV10@@Z 0x141a1a650 ; prop
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@H@std@@@0@AEAV10@@Z 0x141a1a670 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEAPEAU31@@Z 0x141a1a680 ; prop
// MS2-PIN: ??$construct@PEAU?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@std@@@1@QEAPEAU?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@1@AEAPEAU31@@Z 0x141a1a6d0 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBHH@std@@U?$pair@HH@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAU?$pair@$$CBHH@1@$$QEAU?$pair@HH@1@@Z 0x141a1a720 ; unique
// MS2-PIN: ??$construct@V?$MS2Ptr@VChatEmoticonData@@@@AEBV1@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@std@@@1@QEAV?$MS2Ptr@VChatEmoticonData@@@@AEBV3@@Z 0x141a1a810 ; unique
// MS2-PIN: ??$construct@HH@?$_Default_allocator_traits@V?$allocator@H@std@@@std@@SAXAEAV?$allocator@H@1@QEAH$$QEAH@Z 0x141a1a860 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@@Z 0x141a1a8a0 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBHH@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAU?$pair@$$CBHH@1@@Z 0x141a1a8c0 ; prop
// MS2-PIN: ??$emplace@U?$pair@HH@std@@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@HH@1@@Z 0x141a1a910 ; unique
// MS2-PIN: ??$emplace_back@H@?$vector@HV?$allocator@H@std@@@std@@QEAAX$$QEAH@Z 0x141a1a9f0 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@0@AEAPEAU10@@Z 0x141a1aa60 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@std@@@std@@YAAEAPEAU?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@0@AEAPEAU10@@Z 0x141a1aa70 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBHH@std@@@std@@YAAEAU?$pair@$$CBHH@0@AEAU10@@Z 0x141a1aa80 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@0@AEAV10@@Z 0x141a1aac0 ; prop
// MS2-PIN: ??$forward@U?$pair@HH@std@@@std@@YA$$QEAU?$pair@HH@0@AEAU10@@Z 0x141a1ab40 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@0@AEAV10@@Z 0x141a1ab70 ; prop
// MS2-PIN: ??$forward@H@std@@YA$$QEAHAEAH@Z 0x141a1ab80 ; prop
// MS2-PIN: ??$insert@U?$pair@HH@std@@X@?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@HH@1@@Z 0x141a1abd0 ; unique
// MS2-PIN: ??$move@AEAH@std@@YA$$QEAHAEAH@Z 0x141a1ad10 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141a1ae00 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x141a1aea0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141a1b130 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141a1b190 ; prop
// MS2-PIN: ??0?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@1@@Z 0x141a1b210 ; prop
// MS2-PIN: ??0?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@1@@Z 0x141a1b2d0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@1@@Z 0x141a1b310 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAA@XZ 0x141a1b350 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAA@XZ 0x141a1b420 ; prop
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEAA@PEAHPEBU_Container_base0@1@@Z 0x141a1b450 ; prop
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEAA@PEAHPEBU_Container_base0@1@@Z 0x141a1b490 ; prop
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@H@std@@@std@@QEAA@XZ 0x141a1b510 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@QEAA@XZ 0x141a1b550 ; prop
// MS2-PIN: ??0?$allocator@U?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@std@@@std@@QEAA@XZ 0x141a1b560 ; prop
// MS2-PIN: ??0?$allocator@H@std@@QEAA@XZ 0x141a1b580 ; prop
// MS2-PIN: ??0?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA@XZ 0x141a1b590 ; unique
// MS2-PIN: ??0?$vector@HV?$allocator@H@std@@@std@@QEAA@XZ 0x141a1b6c0 ; unique
// MS2-PIN: ??0TDebugCommand@@QEAA@XZ 0x141a1b730 ; unique
// MS2-PIN: ??1?$MS2Ptr@VASTextInput@@@@QEAA@XZ 0x141a1b8b0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141a1b920 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x141a1b980 ; prop
// MS2-PIN: ??1?$_List_alloc@U?$_List_base_types@V?$MS2Ptr@VChatEmoticonData@@@@V?$allocator@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@std@@@std@@QEAA@XZ 0x141a1b9b0 ; prop
// MS2-PIN: ??1?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA@XZ 0x141a1ba20 ; unique
// MS2-PIN: ??8?$MS2Ptr@UTDebugCommand@@@@QEBA_NPEAUTDebugCommand@@@Z 0x141a1bc80 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141a1bd80 ; prop
// MS2-PIN: ??8?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141a1bdc0 ; prop
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141a1be00 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141a1be50 ; unique
// MS2-PIN: ??9?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141a1be90 ; prop
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141a1bed0 ; unique
// MS2-PIN: ??C?$MS2Ptr@UTDebugCommand@@@@QEBAPEAUTDebugCommand@@XZ 0x141a1bf60 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHH@1@XZ 0x141a1bf80 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBHH@1@XZ 0x141a1bfa0 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHH@1@XZ 0x141a1bfc0 ; prop
// MS2-PIN: ??D?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBAAEBHXZ 0x141a1bfe0 ; prop
// MS2-PIN: ??D?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBAAEAHXZ 0x141a1bff0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141a1c010 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a1c060 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a1c0f0 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141a1c110 ; prop
// MS2-PIN: ??E?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a1c230 ; unique
// MS2-PIN: ??E?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a1c250 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a1c270 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a1c2b0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141a1c2d0 ; prop
// MS2-PIN: ?GetHeadPosition@?$CAtlList@VTalkLog@MessengerData@@V?$CElementTraits@VTalkLog@MessengerData@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x141a1ca50 ; unique
// MS2-PIN: ?GetNext@?$CAtlList@VTalkLog@MessengerData@@V?$CElementTraits@VTalkLog@MessengerData@@@ATL@@@ATL@@QEAAAEAVTalkLog@MessengerData@@AEAPEAU__POSITION@@@Z 0x141a1ca60 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@_KV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEBAIXZ 0x141a1cae0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x141a1d200 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x141a1d380 ; prop
// MS2-PIN: ?_Calculate_growth@?$vector@HV?$allocator@H@std@@@std@@AEBA_K_K@Z 0x141a1d5d0 ; unique
// MS2-PIN: ?_Change_array@?$vector@HV?$allocator@H@std@@@std@@AEAAXQEAH_K1@Z 0x141a1d770 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141a1d880 ; prop
// MS2-PIN: ?_Compat@?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBAXAEBV12@@Z 0x141a1d900 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x141a1d910 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x141a1d9f0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x141a1da50 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@@Z 0x141a1db90 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x141a1e6f0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x141a1e750 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@XZ 0x141a1e7d0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@XZ 0x141a1e800 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x141a1e8d0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141a1e910 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x141a1e920 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@XZ 0x141a1e950 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@XZ 0x141a1e960 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEBAAEBV?$allocator@H@2@XZ 0x141a1e9c0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@XZ 0x141a1e9d0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@2@XZ 0x141a1e9e0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@XZ 0x141a1ea10 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@XZ 0x141a1ea20 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x141a1ea80 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@XZ 0x141a1eaa0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@XZ 0x141a1ead0 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBV?$allocator@H@2@XZ 0x141a1ebc0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x141a1ebe0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x141a1ec00 ; prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@HV?$allocator@H@std@@@std@@AEBA_NXZ 0x141a1ecb0 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x141a1ed00 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHH@2@@Z 0x141a1ed60 ; prop
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x141a1edb0 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x141a1edd0 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@PEAU32@@Z 0x141a1ef90 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@PEAU32@@Z 0x141a1eff0 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x141a1f0b0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x141a1f110 ; prop
// MS2-PIN: ?_Myhead@?$_List_alloc@U?$_List_base_types@V?$MS2Ptr@VChatEmoticonData@@@@V?$allocator@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@std@@@std@@QEAAAEAPEAU?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@2@XZ 0x141a1f130 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAXXZ 0x141a1f230 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@HV?$allocator@H@std@@@std@@AEBAXPEAH0@Z 0x141a1f260 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x141a1f440 ; prop
// MS2-PIN: ??D?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@std@@@std@@QEBAAEBV?$MS2Ptr@VChatEmoticonData@@@@XZ 0x141a1f460 ; prop
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x141a1f480 ; prop
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x141a1f4c0 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x141a1f6b0 ; unique
// MS2-PIN: ?_Umove@?$vector@HV?$allocator@H@std@@@std@@AEAAPEAHPEAH00@Z 0x141a1f940 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH00U?$integral_constant@_N$00@2@@Z 0x141a1f9c0 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH00@Z 0x141a1fa60 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x141a1fb00 ; prop
// MS2-PIN: ?allocate@?$allocator@H@std@@QEAAPEAH_K@Z 0x141a1fb90 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@XZ 0x141a1fbc0 ; unique
// MS2-PIN: ?capacity@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x141a1fd50 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x141a1fd90 ; unique
// MS2-PIN: ?clear@?$vector@HV?$allocator@H@std@@@std@@QEAAXXZ 0x141a1ff50 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a1ffd0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a20030 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a20090 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x141a200f0 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x141a20150 ; prop
// MS2-PIN: ?deallocate@?$allocator@H@std@@QEAAXQEAH_K@Z 0x141a201e0 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@XZ 0x141a20260 ; unique
// MS2-PIN: ?end@?$vector@HV?$allocator@H@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@2@XZ 0x141a203a0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@0@Z 0x141a20400 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@@Z 0x141a204f0 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@AEBH@Z 0x141a20740 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141a20900 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x141a20930 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141a20960 ; unique
// MS2-PIN: ??$Call@VUIMessenger@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIMessenger@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141a209a0 ; prop
// MS2-PIN: ??$Call@VUIMessenger@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIMessenger@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x141a209e0 ; prop
// MS2-PIN: ??$Call@VUIMessenger@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIMessenger@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x141a20a20 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a20a60 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a20ac0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMessenger@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a20b20 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@AEBH@Z 0x141a20b80 ; prop
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@2@@Z 0x141a20c40 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@H@std@@@std@@SA_KAEBV?$allocator@H@2@@Z 0x141a20c70 ; unique
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x141a20c80 ; prop
// MS2-PIN: ?max_size@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x141a20d10 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBHH@std@@@std@@SAPEAU?$pair@$$CBHH@2@AEAU32@@Z 0x141a20d60 ; prop
// MS2-PIN: ?push_back@?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$MS2Ptr@UTDebugCommand@@@@@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$MS2Ptr@UTDebugCommand@@@@@std@@@2@@std@@QEAAX$$QEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$MS2Ptr@UTDebugCommand@@@@@2@@Z 0x141a20d80 ; unique
// MS2-PIN: ?push_back@?$vector@HV?$allocator@H@std@@@std@@QEAAX$$QEAH@Z 0x141a20db0 ; unique
// MS2-PIN: ?size@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x141a20e30 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141a27df0 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141a27e20 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@0@Z 0x141a27e80 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@$$QEA_N@Z 0x141a27ed0 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141a27fc0 ; prop
// MS2-PIN: ??$?0AEBU?$less@_J@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@_J@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@_J@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141a28010 ; unique
// MS2-PIN: ??$?0V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@$$QEA_N@Z 0x141a28150 ; prop
// MS2-PIN: ??$?8PEAVUIMessengerBrowser@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIMessengerBrowser@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x141a28290 ; prop
// MS2-PIN: ??$StringFormat@IHI@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBIAEBH1@Z 0x141a28a40 ; unique
// MS2-PIN: ??$FUN_14028dfa0@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@HIIIV12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBV01@1AEBHAEBI331@Z 0x141a28dc0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEBH@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@HPEAX@1@U_Not_a_node_tag@1@AEBH@Z 0x141a29280 ; prop
// MS2-PIN: ??$_Buynode@AEBH@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@1@AEBH@Z 0x141a292b0 ; prop
// MS2-PIN: ??$_Distance1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x141a294b0 ; unique
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@1@AEBH@Z 0x141a29510 ; unique
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@1@AEBH@Z 0x141a295a0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@?$_Tree_node@HPEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@PEAU01@@Z 0x141a29870 ; prop
// MS2-PIN: ??$_Insert_at@AEBHU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@_NPEAU?$_Tree_node@HPEAX@1@AEBHU_Not_a_node_tag@1@@Z 0x141a29ce0 ; prop
// MS2-PIN: ??$_Insert_nohint@AEBHU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@1@_NAEBHU_Not_a_node_tag@1@@Z 0x141a2a450 ; prop
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@HPEAX@1@AEBH@Z 0x141a2a870 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@0@AEBV10@@Z 0x141a2ac30 ; prop
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@HPEAX@std@@@std@@YAPEAPEAU?$_Tree_node@HPEAX@0@AEAPEAU10@@Z 0x141a2ac50 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@H@std@@@0@AEAV10@@Z 0x141a2aca0 ; prop
// MS2-PIN: ??$addressof@H@std@@YAPEAHAEAH@Z 0x141a2acb0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@HPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAPEAU?$_Tree_node@HPEAX@1@AEAPEAU31@@Z 0x141a2ad10 ; prop
// MS2-PIN: ??$construct@HAEBH@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAHAEBH@Z 0x141a2ae00 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@HPEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAPEAU?$_Tree_node@HPEAX@1@@Z 0x141a2ae50 ; prop
// MS2-PIN: ??$destroy@H@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@1@QEAH@Z 0x141a2aeb0 ; prop
// MS2-PIN: ??$distance@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@0@Z 0x141a2aec0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@HPEAX@std@@@std@@YAAEAPEAU?$_Tree_node@HPEAX@0@AEAPEAU10@@Z 0x141a2b000 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@AEAV10@@Z 0x141a2b030 ; prop
// MS2-PIN: ??$forward@AEBU?$less@H@std@@@std@@YAAEBU?$less@H@0@AEBU10@@Z 0x141a2b070 ; prop
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@AEAV10@@Z 0x141a2b0a0 ; prop
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@1@AEBH@Z 0x141a2b0c0 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMessengerBrowser@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x141a2b2f0 ; prop
// MS2-PIN: ??0?$_Deque_const_iterator@V?$_Deque_val@U?$_Deque_simple_types@UUnk_MsgHistory@@@std@@@std@@@std@@QEAA@$$QEAV01@@Z 0x141a2b3c0 ; unique
// MS2-PIN: ??0?$_Deque_const_iterator@V?$_Deque_val@U?$_Deque_simple_types@UUnk_MsgHistory@@@std@@@std@@@std@@QEAA@AEBV01@@Z 0x141a2b400 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141a2b5a0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x141a2b610 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@HPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@1@@Z 0x141a2b690 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@HPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@1@@Z 0x141a2b750 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@std@@QEAA@XZ 0x141a2b790 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAA@XZ 0x141a2b7c0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141a2b7f0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@HPEAX@std@@@std@@QEAA@XZ 0x141a2b800 ; prop
// MS2-PIN: ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QEAA@XZ 0x141a2b8d0 ; unique
// MS2-PIN: ??0Unk_1407a5330@@QEAA@XZ 0x141a2b960 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA@XZ 0x141a2bd10 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA@XZ 0x141a2bd70 ; prop
// MS2-PIN: ??1?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QEAA@XZ 0x141a2be50 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141a2bfb0 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141a2c070 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAA?AV01@H@Z 0x141a2c3b0 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a2c400 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141a2c4b0 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a2c630 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141a2c740 ; prop
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x141a2c810 ; unique
// MS2-PIN: ??_GUIMessengerBrowser@@UEAAPEAXI@Z 0x141a2c970 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlArray@PEAVUIMessenger@@V?$CElementTraits@PEAVUIMessenger@@@ATL@@@ATL@@QEBA_NXZ 0x141a2d0e0 ; unique
// MS2-PIN: ?RemoveHead@?$CAtlList@VReportLog@MessengerData@@V?$CElementTraits@VReportLog@MessengerData@@@ATL@@@ATL@@QEAA?AVReportLog@MessengerData@@XZ 0x141a2d4f0 ; unique
// MS2-PIN: ?RemoveHead@?$CAtlList@VTalkLog@MessengerData@@V?$CElementTraits@VTalkLog@MessengerData@@@ATL@@@ATL@@QEAA?AVTalkLog@MessengerData@@XZ 0x141a2d610 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@XZ 0x141a2da30 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@XZ 0x141a2dbd0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141a2dcf0 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXXZ 0x141a2dd70 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXU_Not_a_node_tag@2@@Z 0x141a2ddf0 ; prop
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x141a2dea0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@@Z 0x141a2e4f0 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x141a2eb40 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x141a2eba0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x141a2ec50 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x141a2ec80 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141a2ecb0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x141a2ecc0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x141a2ed10 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x141a2ed20 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@XZ 0x141a2ed50 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@2@XZ 0x141a2ed60 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x141a2edb0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@XZ 0x141a2edc0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x141a2ee80 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x141a2eeb0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x141a2ef80 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x141a2efa0 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@HPEAX@2@@Z 0x141a2f3f0 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBAAEBHAEBH@Z 0x141a2f440 ; prop
// MS2-PIN: ?_Kfn@?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@SAAEBHAEBH@Z 0x141a2f460 ; prop
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEBAAEAPEAU?$_Tree_node@HPEAX@2@XZ 0x141a2f480 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x141a2f570 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@SAPEAU?$_Tree_node@HPEAX@2@PEAU32@@Z 0x141a2f6c0 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@SAPEAU?$_Tree_node@HPEAX@2@PEAU32@@Z 0x141a2f720 ; prop
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEBAAEAPEAU?$_Tree_node@HPEAX@2@XZ 0x141a2f7d0 ; prop
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEBAAEAPEAU?$_Tree_node@HPEAX@2@XZ 0x141a2f810 ; prop
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x141a2f910 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXXZ 0x141a2fa50 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@std@@@std@@QEAAPEAU?$_List_node@V?$MS2Ptr@VChatEmoticonData@@@@PEAX@2@_K@Z 0x141a2fc70 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@XZ 0x141a2fd80 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXXZ 0x141a2fef0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMessengerBrowser@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a2ffc0 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@QEAU?$_Tree_node@HPEAX@2@_K@Z 0x141a30050 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@XZ 0x141a301e0 ; unique
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@2@AEBH@Z 0x141a30240 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@V32@0@Z 0x141a30420 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@V32@@Z 0x141a30510 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA_KAEBH@Z 0x141a305c0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@AEBH@Z 0x141a30620 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIMessengerBrowser@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x141a30700 ; unique
// MS2-PIN: ??$Call@VUIMessengerBrowser@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIMessengerBrowser@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIMessengerBrowser@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x141a30730 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMessengerBrowser@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a30770 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@AEBH@Z 0x141a30830 ; prop
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_KXZ 0x141a308e0 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_KXZ 0x141a30dd0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
//
// Two original TUs: the window (0x141a08af0-0x141a20f80, members up to 0x141a17e20, then its container glue) and the
// browser (0x141a20f90-), each with its own COMDAT copies of the glue.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimessenger.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uimessenger.h"

#include <list>
#include <set>
#include <utility>
#include <vector>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/chatemoticoncli.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/messengerdata.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/dungeonrecordcli.h"
#include "ms2/client/ms2/uicashshopdialog.h"
#include "ms2/client/ms2/uidungeonroomdialog.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/cashshopref.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/tusercommandinfo.h"
#include "ms2/client/ms2/uichatemoticondialog.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/chatemoticontable.h"
#include "ms2/client/ms2/usercommandcli.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextarea.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/client/ms2/uiwhispernotifydialog.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/clubcli.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/commandchat.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/uipopupmenu.h"
#include "ms2/client/ms2/itempreview.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The exe's out-of-line CStringW operator+ copies (the clang hook build cannot compile ATL's: MFC CopyChars import).
CStringW FUN_1401d0080(const CStringW& strA, const CStringW& strB);         // CStringW + CStringW
CStringW FUN_1401d0160(const wchar_t* pszA, const CStringW& strB);          // const wchar_t* + CStringW
CStringW FUN_14061ad70(const CStringW& strA, const wchar_t* pszB);          // CStringW + const wchar_t*

using namespace MessengerData;

// ---- statics of the window TU (.text$di, in init order) ----
static MS2Ptr<CCacheData> s_spDebugCommandCache = 0;               // 0x143af3f70 DebugChatCommand.xml
// The debug commands keyed by their lower-case name and search tags (one entry per key).
static std::vector<std::pair<CStringW, MS2Ptr<TDebugCommand> > > s_debugCommands;   // 0x143af3f80
static CString s_strColor = "color";                               // 0x143af3fb0
static CString s_strFrame = "frame";                               // 0x143af3f98
static CString s_strIconPath = "iconPath";                         // 0x143af3fa0
static CString s_strLabel = "label";                               // 0x143af3fa8
static CString s_strOriginPrice = "originPrice";                   // 0x143af3fc0
static CString s_strPrice = "price";                               // 0x143af3fb8
static CString s_strMarketSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal",
                                         "EnumEnd"};               // 0x143af3f30
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unkTab(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;     // 0x143af3ee0
static CString s_strJobCode = "jobCode";                           // 0x143af3f28
static CString s_strSortValue = "sortValue";                       // 0x143af3ed8
static CString s_strTabIndex = "tabIndex";                         // 0x143af3e88

// ---- unit-local views of exe types ----

// The movie root of every dialog is an ASDialog.
class ASDialog : public ASUIComponent
{
public:
    int FUN_1422c1340();                                            // the width
    int FUN_1422c13b0();                                            // the height
    void FUN_1422c7490(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n);   // "moved"
    void FUN_1422deb40(bool bActive);                               // the active frame
    void FUN_1407cb9c0(const char* szName, int n);                  // set an int member
};

// "m_subject": the chat type drop-down.
class ASDropdownMenu : public ASUIComponent
{
public:
    unsigned FUN_1422df620();                                       // the entry count
    void FUN_1422df690(int nIndex);                                 // select an entry
    int FUN_1422df6c0();                                            // the selected entry
    void FUN_1422df5f0(int nRowCount);                              // the number of visible rows
    unsigned FUN_1422dfb90();                                       // the item count
    void FUN_1422dfc10();                                           // remove every entry
    void FUN_1422dfc70(const ASObj& item);                          // add an item
};

// The messenger settings element (messengerdata.cpp's view): children by name.
class Unk_MdXml
{
public:
    Unk_MdXml* FUN_140872ec0(const char* szName, bool bCreate);    // child element (created on request)
};

// The key state.
class Unk_MsgKeys
{
public:
    bool FUN_14116d840();                                           // escape pressed
    bool FUN_14116d9c0(int nKey, int a, int b);                     // key pressed
    bool FUN_14116dd30(int nKeyCode, int a, int b);                 // bound key pressed
    bool FUN_14116d720();                                           // the ":alias:" emoticons are on
    bool FUN_14116d7a0(int nKey);                                   // a key is held
};
Unk_MsgKeys* FUN_14025e7c0();

// The own field state.
class Unk_MsgField
{
public:
    int FUN_141adbb00();
    void FUN_141adc530(int nUiId);                                  // opens a UI
    void FUN_141adc750(int nUiId);                                  // toggles a UI
    int FUN_141adc940(int nUiId);                                   // the UI can open
    void FUN_141add1f0();                                           // the field chat is blocked
};
Unk_MsgField* FUN_1403ed2b0();

// The notify manager.
class Unk_MsgNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);   // subscribe
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> cb);   // unsubscribe
};
Unk_MsgNotices* FUN_140939a10();

// The data file loader.
class Unk_MsgFiles { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* szPath, int a, bool b, bool c); };
Unk_MsgFiles* FUN_140166420();

CString FUN_14071a6f0(const CString& strFile);                      // the data path of a file
CString FUN_14016a600(const wchar_t* psz, int n);                   // wide -> narrow
CString FUN_1412755f0();                                            // the UI settings directory
CString FUN_140cc2a00(const CString& strRoot, const CString& strFile);   // path join
void FUN_14086ddc0(TiXmlDocument* pDoc);                            // Clear
void* FUN_14081b310(TiXmlDocument* pDoc);                           // RootElement
void* FUN_14086e090(TiXmlDocument* pDoc, class TiXmlElement* pChild);   // LinkEndChild
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* szPath);        // SaveFile
void* FUN_140165cf0(TiXmlDocument* pDoc, const char* szName);       // FirstChildElement
void* FUN_140165cf0(void* pNode, const char* szName);               // FirstChildElement
void* FUN_140168650(void* pNode, const char* szName);               // NextSiblingElement
void FUN_140873e30(void* pCfg, const char* szName, float f);
void FUN_140873ca0(void* pCfg, const char* szName, int n);
int FUN_140873360(void* pCfg, const char* szName, float* pf);
int FUN_1408731e0(void* pCfg, const char* szName, int* pn);
int FUN_140873420(void* pCfg, const char* szName, CStringW* pstr);
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& arr, const wchar_t* szDelim);   // split
void FUN_140988d60(CStringW& str, std::vector<CStringW>& arr, const wchar_t* szDelim);   // split
bool FUN_140841300(const CStringW& str, const char* sz);           // equals a narrow string
bool FUN_140d2aa60(CStringW& strHtml);                              // the input has item links
CStringW FUN_140cde1f0(const wchar_t* szFormat, const unsigned& nId, const int& nVSpace, const CStringW& strSize);
int FUN_1418fd740(__int64 nParam, __int64 nId, int nType);          // uicommon.cpp: reports a user
void FUN_1418fdfd0(__int64 nKey);                                   // uicommon.cpp: blocks a user

// The emoticon tables and the per-user emoticon state.
class Unk_MsgUser
{
public:
    MS2Ptr<DungeonRecordManagerCli> FUN_140d9f2c0();                // the dungeon records
    int FUN_140d9f880(int nRoomId);                                 // the room's entry state (10+: refused)
    MS2Ptr<CChatEmoticonCli> FUN_140d9f8f0();
};
Unk_MsgUser* FUN_140931510();
CChatEmoticonTable* FUN_1409eecd0();

// The world and its local player (the selected super world chat item).
class Unk_MsgWorld
{
public:
    MyPC* FUN_141bd0cc0();
    PCBase* FUN_141bd1420(CStringW strName);                        // a player by name
};
Unk_MsgWorld* FUN_1403ed2d0();
extern Unk_Inventory DAT_143ab2a90;                                 // the player's inventory

// The messenger state (messengerdata.cpp's Unk_MdState): the current window name and the browser (+0x48).
class Unk_MsgState
{
public:
    CStringW FUN_1414829e0();                                       // the current window name
    void FUN_141482c80(CStringW strName);                           // make a window the current one
    CStringW FUN_141482a50();                                       // the whisper window name
    void FUN_141482b70();                                           // reset
    void FUN_141482d30(CStringW strName);                           // forget a window
    char m_pad_00[0x38];
    int m_nNewTabMode;                                              // +0x38 why the new tab dialog opened (1 menu, 2 button)
    UIMessenger* m_pNewTabWindow;                                   // +0x40 the window asking for a new tab
    UIMessengerBrowser* m_pBrowser;                                 // +0x48
};
Unk_MsgState* FUN_141482e80();
int FUN_141482f00(int nChannel);                                    // the line type of a chat channel

void FUN_141276f80(const Unk_CommandChat& chat);                       // sends a chat line

// The search keywords of an emotion (uidynamicactiondialog.cpp's Unk_EmotionKeywords).
class Unk_MsgEmotionKeywords : public CPtred
{
public:
    char m_pad_18[0x34 - 0x18];
    int m_nAction;                                                  // +0x34
    ATL::CAtlArray<CStringW> m_keywords;                            // +0x38
};
MS2Ptr<Unk_MsgEmotionKeywords> FUN_140347050(int nEmotionId);

class Unk_MsgStrings
{
public:
    CStringW FUN_1422af5f0(int nId);                                // the UI string table
    CStringW FUN_1422b0570(const CString& strKey);                  // the text of a "$..." key
};
Unk_MsgStrings* FUN_14025e7a0();
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1409e97f0(int nStringId, const int& n);                // a string with one number
CStringW FUN_141842320(const CStringW& strText);                    // text to html
void FUN_140d2c650(CStringW& strHtml);                              // encodes the item links
void FUN_140d2c2a0(MS2Ptr<ASTextInput> spInput, ATL::CAtlArray<CStringW>& history);   // the input history keys
void* FUN_1422bb8b0(int nMovieId);                                  // the movie of a UI layer
void FUN_14256e3e0(void* pMovie, Scaleform::GFx::Value* pValue);   // movie->CreateArray
CStringW FUN_140298ea0(CStringW strKey);                            // the string of a key
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CStringW FUN_140bfa7f0(CStringW strKey, const CStringW& a, const int& b);
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a);  // StringFormat
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a, const CStringW& b);
int FUN_140718200(const CStringW& str);                             // to int
void FUN_1412751f0(const CStringW& strText, int nA, int nB);        // a system message
void FUN_1412b9870(int nRoomId, int nState);                        // the room entry refusal message
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);   // a yes/no box
CPartyManager* FUN_1409670d0();
DungeonRoomTable* FUN_14031c2a0();
UIDungeonRoomDialog* FUN_140961550(int nUiId);                      // Unk_GetUI<UIDungeonRoomDialog>
class Unk_MsgNames { public: CStringW FUN_141811980(int nKind, int nId); };   // names of ids
Unk_MsgNames* FUN_1401a9d70();
UIMessenger* FUN_141a184c0(CString strName);                       // Unk_GetUI<UIMessenger> by name

class TiXmlElement
{
public:
    TiXmlElement(const char* szValue);                              // 0x14086f2f0
private:
    char m_pad[0x90];
};

// ---- UIMessenger ----

// The chat-confirm flags of the community option state (named bytes; m_b[n] indexing is codegen-different).
struct Unk_MsgCommunityFlags {
    bool m_b0, m_b1, m_b2, m_b3, m_b4, m_b5, m_b6, m_b7;
};
#define MSG_COMMUNITY_FLAGS(p) ((Unk_MsgCommunityFlags*)(p))

// @0x141a08af0
UIMessenger::UIMessenger(UIMessengerBrowser* pBrowser, const TiXmlDocument& doc, CStringW strName, int bFirst)
    : m_178(0), m_bFirst(bFirst), m_bScrollEnd(0), m_fOffsetX(0), m_fOffsetY(0), m_nAlignType(7),
      m_nTabSelectedIndex(0), m_nTargetSelectedIndex(0), m_nHistoryIndex(-1), m_strName(strName), m_238(0), m_doc(doc),
      m_pBrowser(pBrowser)
{
    m_80 = 1;
    FUN_1422dc3b0(1);
    FUN_141925e70(0, 1);
}

// @0x141a08d60
UIMessenger::~UIMessenger()
{
}

// @0x141a08eb0
CString UIMessenger::vfunc_1()
{
    return "MessengerDialog";
}

// @0x141a08f00
int UIMessenger::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    FUN_140939a10()->FUN_140da4e40(L"NotifyGameEventChanged",
                                   Delegate<void(NotifyObject*)>(this, &UIMessenger::FUN_141a0f550));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChatEmoticonSelected",
                                   Delegate<void(NotifyObject*)>(this, &UIMessenger::FUN_141a0f5d0));
    return 1;
}

// @0x141a090d0
void UIMessenger::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140939a10()->FUN_140da4eb0(L"NotifyGameEventChanged",
                                   Delegate<void(NotifyObject*)>(this, &UIMessenger::FUN_141a0f550));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChatEmoticonSelected",
                                   Delegate<void(NotifyObject*)>(this, &UIMessenger::FUN_141a0f5d0));
    m_inputHistory.RemoveAll();
    m_tabs.RemoveAll();
    m_textInput = 0;
    m_textOutput = 0;
    m_buttonBar = 0;
    m_subject = 0;
}

// @0x141a09320
int UIMessenger::vfunc_4()
{
    if (!m_80)
        return 0;
    if (!m_4c)
        return 1;
    TiXmlDocument doc;
    if (!FUN_14081b310(&doc))
        FUN_14086e090(&doc, new TiXmlElement(vfunc_1()));
    void* pRoot = FUN_14081b310(&doc);
    if (!pRoot)
        return 0;
    FUN_141a15970();
    if (vfunc_53(pRoot))
        return FUN_1408710c0(&doc, FUN_140cc2a00(FUN_1412755f0(), FUN_14016a600(m_strName, 0)));
    return 0;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a095d0
int UIMessenger::vfunc_5()
{
    if (!m_80)
        return 0;
    m_78 = 0;
    void* pNode = FUN_140165cf0(&m_doc, vfunc_1());
    if (pNode == 0)
    {
        TiXmlDocument doc;
        if (doc.FUN_140870fc0(FUN_140cc2a00(FUN_1412755f0(), FUN_14016a600(m_strName, 0)), 0))
        {
            void* pLoaded = FUN_140165cf0(&doc, vfunc_1());
            if (pLoaded == 0)
                return 0;
            m_78 = vfunc_54(pLoaded);
        }
    }
    else
    {
        m_78 = vfunc_54(pNode);
        FUN_14086ddc0(&m_doc);
    }
    if (!m_78)
        vfunc_84();
    return m_78;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a098b0
int UIMessenger::vfunc_53(void* pCfg)
{
    if (m_tabs.IsEmpty())
        return 0;
    if (m_30 == 0)
        return 0;
    FUN_141a0f180();
    FUN_140873ca0(pCfg, "width", static_cast<ASDialog*>(m_30.operator->())->FUN_1422c1340());
    FUN_140873ca0(pCfg, "height", static_cast<ASDialog*>(m_30.operator->())->FUN_1422c13b0());
    FUN_140873e30(pCfg, "offsetX", m_fOffsetX);
    FUN_140873e30(pCfg, "offsetY", m_fOffsetY);
    FUN_140873ca0(pCfg, "alignType", m_nAlignType);
    FUN_140873ca0(pCfg, "tabSelectedIndex", m_nTabSelectedIndex);
    FUN_140873ca0(pCfg, "targetSelectedIndex", m_nTargetSelectedIndex);
    for (unsigned int i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab.get() != 0)
        {
            Unk_MdXml* pTab = static_cast<Unk_MdXml*>(pCfg)->FUN_140872ec0("Tab", false);
            if (pTab != 0 && !spTab->FUN_141482880(pTab))
                return 0;
        }
    }
    return 1;
}

// @0x141a09af0
int UIMessenger::vfunc_54(void* pCfg)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        int nWidth = 0;
        int nHeight = 0;
        FUN_1408731e0(pCfg, "width", &nWidth);
        FUN_1408731e0(pCfg, "height", &nHeight);
        FUN_140873360(pCfg, "offsetX", &m_fOffsetX);
        FUN_140873360(pCfg, "offsetY", &m_fOffsetY);
        FUN_1408731e0(pCfg, "alignType", &m_nAlignType);
        FUN_1408731e0(pCfg, "tabSelectedIndex", &m_nTabSelectedIndex);
        FUN_1408731e0(pCfg, "targetSelectedIndex", &m_nTargetSelectedIndex);
        if (m_bFirst)
        {
            m_nTabSelectedIndex = 0;
            m_nTargetSelectedIndex = FUN_141a14110();
            m_bFirst = 0;
        }
        for (void* pNode = FUN_140165cf0(pCfg, "Tab"); pNode != 0; pNode = FUN_140168650(pNode, "Tab"))
        {
            TalkTab* pTab = new TalkTab;
            if (pTab != 0)
            {
                if (!pTab->FUN_1414827c0(static_cast<Unk_MdXml*>(pNode)))
                {
                    m_tabs.RemoveAll();
                    return 0;
                }
                if (!FUN_141a0e4d0(pTab))
                    return 0;
            }
        }
        FUN_141a13ac0();
        pDialog->FUN_1422c79e0(nWidth, nHeight);
    }
    return (int)m_tabs.GetCount();
}

// @0x141a09db0
int UIMessenger::vfunc_84()
{
    m_80 = 0;
    return DeleteFileA(FUN_140cc2a00(FUN_1412755f0(), FUN_14016a600(m_strName, 0)));
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141a09e90
void UIMessenger::OnLoadComplete()
{
    m_textInput = FUN_140e35bd0("m_textInput");
    m_textOutput = FUN_140c26f60("m_textOutput");
    m_buttonBar = FUN_140c02870("m_buttonBar");
    m_subject = FUN_140c28560("m_subject");
    m_chatEmoticonPreview = FUN_140ba7930("m_chatEmoticonPreview");
    m_textInput->FUN_1422e0920(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMessenger::FUN_141a0e940));
    UIDialog::OnLoadComplete();
    FUN_141923680(1);
    FUN_141a14dc0();
    if (m_textInput)
        m_textInput->FUN_1422e0d60(*Client::Constants::GetInstance()->MaxChatLength.Get());
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422c7630(1);
        m_buttonBar->FUN_1422e31e0(m_nTabSelectedIndex);
    }
    static_cast<ASDialog*>(m_30.operator->())->FUN_1422c7490(
        Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMessenger::FUN_141a0f520), 0);
    FUN_141a13ac0();
    vfunc_4();
    m_bScrollEnd = 1;
    FUN_141a0d930();
    FUN_141a0e990();
}

// @0x141a0a3a0
void UIMessenger::vfunc_26()
{
    UIDialog::vfunc_26();
    m_2e0 = 0;
    m_2f0 = 0;
}

// @0x141a0a3f0
void UIMessenger::vfunc_43()
{
    if (m_60 == 0)
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog)
            pDialog->vfunc_2(m_nAlignType, (int)m_fOffsetX, (int)m_fOffsetY);
    }
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141a0a4a0
int UIMessenger::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (!FUN_141a12f30())
        return 0;
    if (!m_pBrowser->m_180)
        return 0;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
    {
        FUN_141a17700();
        return 1;
    }
    if (FUN_14025e7c0()->FUN_14116dd30(0x49405, 0, 0))
    {
        if (m_textInput && !m_textInput->FUN_1422c76c0())
        {
            m_textInput->FUN_1422c7630(1);
            FUN_141a17900(m_pBrowser->m_strWhisperTarget);
            return 1;
        }
        return 0;
    }
    if (FUN_14025e7c0()->FUN_14116d9c0(0x39, 0, 0))
    {
        if (FUN_1403ed2b0()->FUN_141adbb00())
        {
            FUN_141a14600();
            return 1;
        }
        return 0;
    }
    if (FUN_14025e7c0()->FUN_14116d840())
        return FUN_141a12260();
    if (m_textInput && m_textInput->FUN_1422c76c0() && FUN_14025e7c0()->FUN_14116d9c0(0x79, 0, 0))
    {
        FUN_141a13c20(1);
        return 1;
    }
    if (m_textInput && m_textInput->FUN_1422c76c0() && FUN_14025e7c0()->FUN_14116d9c0(0x7e, 0, 0))
    {
        FUN_141a13c20(0);
        return 1;
    }
    if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0) && m_textInput)
    {
        if (!m_textInput->FUN_1422c76c0())
            return 0;
        if (!m_strLastWhisper.IsEmpty())
        {
            FUN_141a17830(m_strLastWhisper, 1);
            return 1;
        }
        FUN_141a14760();
        return 1;
    }
    return 0;
}

// @0x141a0a810
void UIMessenger::vfunc_15()
{
    if (m_bScrollEnd)
    {
        if (m_textOutput.get())
        {
            MS2Ptr<ASTextField> spField = m_textOutput->FUN_1422e1490();
            if (spField)
            {
                if (m_textOutput->FUN_1422e4620() != spField->FUN_1422c58b0())
                    m_textOutput->FUN_1422e4720();
            }
        }
        m_bScrollEnd = 0;
    }
}

// @0x141a0d880
void UIMessenger::FUN_141a0d880(bool bVisible)
{
    if (m_2e0.get())
        m_2e0->vfunc_4(bVisible);
    if (m_2f0.get())
        m_2f0->vfunc_4(bVisible);
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141a0d930
bool UIMessenger::FUN_141a0d930()
{
    if (!s_debugCommands.empty())
        return true;
    TiXmlDocument doc;
    CString strPath = FUN_14071a6f0("DebugChatCommand.xml");
    if (s_spDebugCommandCache == 0)
    {
        s_spDebugCommandCache.AssignRaw(new CCacheData);
        s_spDebugCommandCache->FUN_1401d1160(strPath);
    }
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return false;
    void* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
        return false;
    for (void* pSet = FUN_140165cf0(pRoot, "CommandSet"); pSet != 0; pSet = FUN_140168650(pSet, "CommandSet"))
    {
        CStringW strCmd;
        FUN_140873420(pSet, "cmd", &strCmd);
        if (strCmd.IsEmpty())
            continue;
        MS2Ptr<TDebugCommand> spCmd = new TDebugCommand;
        if (spCmd == 0)
            continue;
        FUN_140873420(pSet, "desc", &spCmd->m_strDesc);
        FUN_140873420(pSet, "arg", &spCmd->m_strArg);
        FUN_140873420(pSet, "ex", &spCmd->m_strEx);
        spCmd->m_strDesc.Replace(L"\\n", L"\n");
        spCmd->m_strEx.Replace(L"\\n", L"\n");
        spCmd->m_strArg.Replace(L"\\n", L"\n");
        CStringW strTags;
        FUN_140873420(pSet, "searchTag", &strTags);
        ATL::CAtlArray<CStringW> tags;
        if (!strTags.IsEmpty())
            FUN_14025a680(strTags, tags, L",");
        spCmd->m_strName = strCmd;
        s_debugCommands.push_back(std::pair<CStringW, MS2Ptr<TDebugCommand> >(strCmd.MakeLower(), spCmd));
        if (!tags.IsEmpty())
        {
            for (size_t i = 0; i < tags.GetCount(); i++)
                s_debugCommands.push_back(std::pair<CStringW, MS2Ptr<TDebugCommand> >(tags[i].MakeLower(), spCmd));
        }
    }
    return true;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a0df10
int UIMessenger::FUN_141a0df10()
{
    if (s_spDebugCommandCache == 0)
        return 0;
    if (FUN_1401d1320(s_spDebugCommandCache.operator->()))
    {
        s_debugCommands.clear();
        FUN_141a0d930();
    }
    return 1;
}

// @0x141a0df70
CStringW UIMessenger::FUN_141a0df70()
{
    return m_strName;
}

// @0x141a0dfc0
CStringW UIMessenger::FUN_141a0dfc0()
{
    if (m_buttonBar)
        return m_buttonBar->FUN_1422e3790();
    return L"";
}

// @0x141a0e050
TalkTab* UIMessenger::FUN_141a0e050()
{
    if (m_tabs.GetCount() == 1)
        return m_tabs[0].get();
    return FUN_141a0e0f0(FUN_141a0dfc0());
}

// @0x141a0e0f0
TalkTab* UIMessenger::FUN_141a0e0f0(const CStringW& strName)
{
    for (unsigned i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab.get() ? true : false)
        {
            if (spTab->m_strName == strName)
                return spTab;
        }
    }
    return 0;
}

// @0x141a0e1f0
int UIMessenger::FUN_141a0e1f0(int nIndex)
{
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422c7630(1);
        m_buttonBar->FUN_1422e31e0(nIndex);
        m_buttonBar->vfunc_24(1);
    }
    return 1;
}

// @0x141a0e2a0
int UIMessenger::FUN_141a0e2a0(const CStringW& strName)
{
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422c7630(1);
        m_buttonBar->FUN_1422e3590(strName);
        m_buttonBar->vfunc_24(1);
    }
    return 1;
}

// @0x141a0e350
int UIMessenger::FUN_141a0e350(const CStringW& strName)
{
    MS2Ptr<TalkTab> spTab = FUN_141a0e0f0(strName);
    if (!spTab)
        return 0;
    for (unsigned int i = 0; i < m_tabs.GetCount(); i++)
    {
        if (spTab == m_tabs[i].get())
        {
            m_tabs.RemoveAt(i, 1);
            break;
        }
    }
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422e3a70(strName);
        m_buttonBar->vfunc_24(1);
        FUN_141a13ac0();
    }
    return 1;
}

// @0x141a0e4d0
int UIMessenger::FUN_141a0e4d0(TalkTab* pTab)
{
    if (pTab == 0)
        return 0;
    if (!FUN_141a13070(pTab->m_strName))
    {
        m_tabs.Add(pTab);
        if (m_buttonBar)
        {
            ASObj item(2);
            item.FUN_1407cbb20("label", pTab->m_strName);
            item.FUN_1407cb9c0("close", pTab->m_nClose);
            item.FUN_1407cb9c0("detach", pTab->m_nDetach);
            m_buttonBar->FUN_1422e3460(item);
        }
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a0e650
int UIMessenger::FUN_141a0e650(TalkTab* pTab)
{
    if (pTab == 0)
        return 0;
    if (FUN_141a13070(pTab->m_strName))
        return 0;
    m_tabs.Add(pTab);
    if (m_buttonBar)
    {
        ASObj item(2);
        item.FUN_1407cbb20("label", pTab->m_strName);
        item.FUN_1407cb9c0("close", pTab->m_nClose);
        item.FUN_1407cb9c0("detach", pTab->m_nDetach);
        m_buttonBar->FUN_1422e3460(item);
        m_buttonBar->vfunc_24(1);
        FUN_141a13ac0();
    }
    return 1;
}

// @0x141a0e810
int UIMessenger::FUN_141a0e810(const CStringW& strName, int nClose, int nDetach, int nAdditive)
{
    MS2Ptr<TalkTab> spTab = new TalkTab(strName, nClose, nDetach, nAdditive);
    return FUN_141a0e650(spTab);
}

// @0x141a0e900
size_t UIMessenger::FUN_141a0e900(ATL::CAtlArray<MS2Ptr<TalkTab> >& tabs)
{
    tabs.Copy(m_tabs);
    return tabs.GetCount();
}

// @0x141a0e940
void UIMessenger::FUN_141a0e940(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nType = FUN_141a14250();
    switch (nType)
    {
    case 0x18:
        FUN_141a13210();
        break;
    }
}

// @0x141a0e990
void UIMessenger::FUN_141a0e990()
{
    vfunc_97(FUN_141a0dfc0());
}

// @0x141a0e9f0
void UIMessenger::FUN_141a0e9f0(const CStringW& strOld, const CStringW& strNew)
{
    if (strOld == strNew)
        return;
    TalkTab* pTab = FUN_141a0e0f0(strOld);
    if (pTab == 0)
        return;
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422e3c70(strOld, strNew);
        m_buttonBar->vfunc_24(1);
    }
    pTab->m_strName = strNew;
}

// @0x141a0ead0
void UIMessenger::FUN_141a0ead0(unsigned nFontSize, CStringW& strHtml)
{
    for (unsigned i = 12; static_cast<int>(i) <= 18; ++i)
    {
        CStringW strFrom;
        strFrom.Format(L"size='%d'", i);
        CStringW strTo;
        strTo.Format(L"size='%d'", nFontSize);
        strHtml.Replace(strFrom, strTo);
    }
}

// @0x141a0ebb0
void UIMessenger::FUN_141a0ebb0(unsigned nAlpha)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("backgroundAlpha", nAlpha);
}

// @0x141a0ec30
void UIMessenger::FUN_141a0ec30(const CStringW& strText)
{
    if (m_textInput == 0)
        return;
    CStringW strCurrent = m_textInput->FUN_1422e0b00();
    if (strCurrent.GetLength() >= m_textInput->FUN_1422e0da0())
        return;
    CStringW strSpace(L" ");
    CStringW strHtml = m_textInput->FUN_1422e0c20();
#ifdef __clang__
    // clang emits an unavailable MFC CopyChars import for CString's operator+; bind the exe's copy.
    if (FUN_141a14ce0(FUN_1401d0080(FUN_1401d0080(strHtml, strText), strSpace), m_textInput->FUN_1422e0da0()))
    {
        m_textInput->FUN_1422e0bd0(FUN_1401d0080(FUN_1401d0080(strHtml, strText), strSpace));
#else
    if (FUN_141a14ce0(strHtml + strText + strSpace, m_textInput->FUN_1422e0da0()))
    {
        m_textInput->FUN_1422e0bd0(strHtml + strText + strSpace);
#endif
        m_textInput->vfunc_24(1);
        int nLength = m_textInput->FUN_1422e0b00().GetLength();
        if (0 < nLength)
        {
            vfunc_78();
            m_textInput->FUN_1422e1500(nLength, nLength);
        }
        m_textInput->vfunc_24(1);
        m_inputHistory.Add(strText);
    }
}

// @0x141a0efa0
void UIMessenger::vfunc_85(int bActive)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        pDialog->FUN_1422deb40(bActive != 0);
        pDialog->FUN_1422c6640(bActive != 0);
    }
}

// @0x141a0f040
int UIMessenger::vfunc_86(TalkTab* pExcept, const CStringW& strName)
{
    for (unsigned int i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab.get() != 0)
        {
            if (spTab == pExcept)
                continue;
            if (spTab->FUN_141482940() == strName)
                return 0;
        }
    }
    return 1;
}

// @0x141a0f180
void UIMessenger::FUN_141a0f180()
{
    FUN_141926620(&m_nAlignType, &m_fOffsetX, &m_fOffsetY);
}

// @0x141a0f1d0
void UIMessenger::FUN_141a0f1d0(CStringW strText, CStringW strHtml, bool bHistory)
{
    CStringW strSend = strText;
    bool bLinks = FUN_140d2aa60(strHtml);
    if (bLinks)
        strSend = strHtml;
    if (strText.GetAt(0) == L'/')
    {
        if (FUN_141a10fd0(strText, strHtml, bLinks) && bHistory)
            m_pBrowser->FUN_141a25f70(strText, m_inputHistory);
        return;
    }
    int nType = FUN_141a144a0();
    if (FUN_141a12380(nType, strSend))
        return;
    FUN_141a12e40(nType, strSend, bHistory);
}

// @0x141a0f430
void UIMessenger::FUN_141a0f430(CStringW strText, bool bHistory)
{
    if (strText.GetAt(0) != L'/')
        return;
    if (FUN_141a10fd0(strText, CStringW(L""), 0) && bHistory)
        m_pBrowser->FUN_141a25f70(strText, m_inputHistory);
}

// @0x141a0f520
void UIMessenger::FUN_141a0f520(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_141a0f180();
}

// @0x141a0f550
void UIMessenger::FUN_141a0f550(NotifyObject* pNotify)
{
    NotifyGameEventChanged* pChanged = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pChanged != 0 && FUN_140841300(pChanged->m_eventName, "SaleChat"))
        FUN_141a14dc0();
}

// @0x141a0f5d0
void UIMessenger::FUN_141a0f5d0(NotifyObject* pNotify)
{
    NotifyChatEmoticonSelected* pSelected = dynamic_cast<NotifyChatEmoticonSelected*>(pNotify);
    if (pSelected == 0)
        return;
    if (pSelected->m_strTarget != m_strName)
    {
        FUN_141a13940();
        return;
    }
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(pSelected->m_nEmoticonId);
    if (!spEmo)
        return;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x4c3, 0);
        return;
    }
    if (!spCli->FUN_140a39dd0(spEmo->m_nId))
        return;
    std::list<ChatEmoticonDataPtr> emoticons;
    emoticons.push_back(spEmo);
    FUN_141a13510(emoticons);
    FUN_1419235d0();
}

// @0x141a0f7b0
void UIMessenger::FUN_141a0f7b0()
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    FUN_141a14dc0();
    int nType = FUN_141a14500();
    if (!m_pBrowser->FUN_141a264c0(0x10))
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e2e0(pPlayer->FUN_1416639e0());
        if (spItem)
            nType = 0x10;
    }
    FUN_141a146d0(nType);
}

// @0x141a0f870
void UIMessenger::FUN_141a0f870()
{
    if (m_pBrowser->FUN_141a26480())
    {
        m_nHistoryIndex = m_nTargetSelectedIndex;
    }
    else
    {
        if (m_nHistoryIndex != -1)
        {
            m_nTargetSelectedIndex = m_nHistoryIndex;
            m_nHistoryIndex = -1;
        }
    }
    FUN_141a14dc0();
    FUN_141a0e990();
}

// @0x141a0f900
bool UIMessenger::FUN_141a0f900(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        auto first = box.FUN_141a02ed0(0, 0);
        auto second = box.FUN_141a02ed0(1, 0);
        auto third = box.FUN_141a02e50(2, 0);
        FUN_1418fd740(first, second, third);
    }
    return true;
}

// @0x141a0f980
bool UIMessenger::FUN_141a0f980(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        auto value = box.FUN_141a02f10(0, 0);
        FUN_1418fdfd0(value);
    }
    return true;
}

// @0x141a0f9d0
bool UIMessenger::FUN_141a0f9d0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        if (const_cast<CMsgBoxData&>(box).FUN_141a04aa0())
        {
            MSG_COMMUNITY_FLAGS(CGameOption::GetInstance()->FUN_140ae6540())->m_b0 = 0;
            CGameOption::GetInstance()->FUN_1412432d0();
        }
        const CStringW& strText = box.FUN_141a02fd0(0, CStringW());
        FUN_141a12e40(0x10, strText, 1);
        {
            CString strNone("");
            m_textInput->FUN_1422e0b80(strNone);
        }
        m_textInput->vfunc_24(1);
    }
    return true;
}

// @0x141a0fb40
bool UIMessenger::FUN_141a0fb40(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        if (const_cast<CMsgBoxData&>(box).FUN_141a04aa0())
        {
            MSG_COMMUNITY_FLAGS(CGameOption::GetInstance()->FUN_140ae6540())->m_b1 = 0;
            CGameOption::GetInstance()->FUN_1412432d0();
        }
        const CStringW& strText = box.FUN_141a02fd0(0, CStringW());
        FUN_141a12e40(0xb, strText, 1);
        {
            CString strNone("");
            m_textInput->FUN_1422e0b80(strNone);
        }
        m_textInput->vfunc_24(1);
    }
    return true;
}

// @0x141a0fcb0
bool UIMessenger::FUN_141a0fcb0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        if (const_cast<CMsgBoxData&>(box).FUN_141a04aa0())
        {
            MSG_COMMUNITY_FLAGS(CGameOption::GetInstance()->FUN_140ae6540())->m_b2 = 0;
            CGameOption::GetInstance()->FUN_1412432d0();
        }
        const CStringW& strText = box.FUN_141a02fd0(0, CStringW());
        FUN_141a12e40(0xc, strText, 1);
        {
            CString strNone("");
            m_textInput->FUN_1422e0b80(strNone);
        }
        m_textInput->vfunc_24(1);
    }
    return true;
}

// @0x141a0fe20
int UIMessenger::FUN_141a0fe20(int nEmoticonId)
{
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (!spEmo)
        return 0;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x782, 0);
        return 0;
    }
    if (!spCli->FUN_140a39dd0(spEmo->m_nId))
        return 0;
    COutPacket packet(0xb7, 0);
    packet.vfunc_o10_1(3);
    packet.vfunc_o10_3(nEmoticonId);
    packet.vfunc_o10_8(FUN_141a0df70());
    packet.vfunc_o10_1(FUN_141a144a0());
    FUN_140710590(packet);
    return 1;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a10010
void UIMessenger::FUN_141a10010(int nType, int nEmoticonId)
{
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (!spEmo)
        return;
    CStringW strSize(L"");
    if (spEmo->m_nWidth != 0 || spEmo->m_nHeight != 0)
        strSize = StringFormat(L"width='{0}' height='{1}'", spEmo->m_nWidth, spEmo->m_nHeight);
    CStringW strLine = FUN_140cde1f0(L"<img src='img://emoticon:{0}' vspace='{1}' {2} />", spEmo->m_nId,
                                     spEmo->m_nVSpace, strSize);
    CStringW strPrefix;
    if (!m_textInput.IsNull())
    {
        CStringW strInput = m_textInput->FUN_1422e0b00().Trim();
        if (!strInput.IsEmpty() && strInput.GetAt(0) == L'/')
        {
            std::vector<CStringW> parts;
            FUN_140988d60(strInput, parts, L" ");
            if (parts.size() >= 2)
            {
                int nChatType = CUserCommandCli::GetInstance()->ChatType(parts[0]);
                if (nChatType == 4)
                    strPrefix = StringFormat(L"{0} {1} ", parts[0], parts[1]);
            }
        }
    }
    if (strPrefix.IsEmpty())
        FUN_141a146d0(nType);
#ifdef __clang__
    // clang emits an unavailable MFC CopyChars import for CString's operator+; bind the exe's copy.
    strLine = FUN_1401d0080(strPrefix, strLine);
#else
    strLine = strPrefix + strLine;
#endif
    FUN_141a0f1d0(strLine, strLine, 0);
}

// @0x141a10490
int UIMessenger::FUN_141a10490(int nEmoticonId, bool bFavorite)
{
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (!spEmo)
        return 0;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x7d3, 0);
        return 0;
    }
    if (!spCli->FUN_140a39dd0(spEmo->m_nId))
        return 0;
    int nOp = bFavorite ? 5 : 6;
    COutPacket packet(0xb7, 0);
    packet.vfunc_o10_1(nOp);
    packet.vfunc_o10_3(nEmoticonId);
    FUN_140710590(packet);
    return 1;
}

// @0x141a11be0
void UIMessenger::FUN_141a11be0(int nType, const CStringW& strText)
{
    Unk_CommandChat chat;
    chat.kind = nType;
    chat.message = strText;
    FUN_141276f80(chat);
    m_pBrowser->m_1b0 = FUN_141482f00(nType);
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a11c60
bool UIMessenger::FUN_141a11c60(const CStringW& strCommand, CStringW strText, int* pType)
{
    *pType = 0x1b;
    if (strCommand.IsEmpty())
        return true;
    MS2Ptr<TUserCommandInfo> spInfo = CUserCommandCli::GetInstance()->Find(strCommand);
    int nType = 0x1b;
    if (spInfo.get() != 0)
    {
        nType = spInfo->chatType;
        if (!spInfo->function.IsEmpty())
#ifdef __clang__
            // clang emits an unavailable MFC CopyChars import for CString's operator+; bind the exe's copy.
            strText.Replace(strCommand, FUN_1401d0160(L"/", spInfo->function));
#else
            strText.Replace(strCommand, L"/" + spInfo->function);
#endif
    }
    *pType = nType;
    if (nType == 0x1b || nType == 10 || nType == 0x15)
    {
        FUN_141a11be0(FUN_141a144a0(), strText);
        return true;
    }
    return false;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a11e30
void UIMessenger::FUN_141a11e30()
{
    if (m_textInput == 0)
        return;
    if (m_textInput->FUN_1422c76c0() == 0)
    {
        vfunc_78();
        if (m_pBrowser->m_1b0 == 4)
        {
            m_textInput->FUN_1422c7630(1);
            FUN_141a17900(m_pBrowser->m_strWhisperTarget);
        }
        else if (m_pBrowser->m_1b0 == 0x1a)
        {
            m_textInput->FUN_1422c7630(1);
            FUN_141a17a60(m_pBrowser->m_1a8);
        }
        else
        {
            int nLength = m_textInput->FUN_1422e0b00().GetLength();
            m_textInput->FUN_1422c7630(1);
            m_textInput->FUN_1422e1500(nLength, nLength);
            m_textInput->vfunc_24(1);
        }
        return;
    }
    FUN_140d2c2a0(m_textInput, m_inputHistory);
    CStringW strText = FUN_141842320(m_textInput->FUN_1422e0b00());
    CStringW strHtml = m_textInput->FUN_1422e0c20();
    FUN_140d2c650(strHtml);
    strText = strText.Trim();
    if (strText.IsEmpty())
    {
        FUN_141a12260();
        return;
    }
    CStringW strSuffix = FUN_14025e7a0()->FUN_1422af5f0(2);
    if (!strSuffix.IsEmpty())
        strText.Append(strSuffix);
    FUN_141a0f1d0(strText, strHtml, 1);
    FUN_141a12260();
}

// @0x141a12260
int UIMessenger::FUN_141a12260()
{
    if (MS2Ptr<ASTextInput> spInput = m_textInput)
    {
        if (spInput->FUN_1422c76c0() != 0)
        {
            m_inputHistory.RemoveAll();
            spInput->FUN_1422c7630(0);
            spInput->FUN_1422e0bd0(L"<FONT></FONT>");
            spInput->vfunc_24(1);
            FUN_141a0d880(0);
            return 1;
        }
    }
    return 0;
}

// @0x141a12e40
void UIMessenger::FUN_141a12e40(int nType, CStringW strText, bool bHistory)
{
    FUN_141a10660(nType, strText, CStringW(L""), 0);
    if (bHistory)
        m_pBrowser->FUN_141a25f70(strText, m_inputHistory);
}

// @0x141a12f30
int UIMessenger::FUN_141a12f30()
{
    if (FUN_141482e80()->FUN_1414829e0() != m_strName)
        return 0;
    {
        MS2Ptr<ASTextInput> spInput = m_textInput;
        if (spInput.get() != 0 && spInput->FUN_1422c76c0() != 0)
            return 1;
    }
    if (FUN_14025e7c0()->FUN_14116d7a0(0xf))
        return 0;
    return 1;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a13030
bool UIMessenger::FUN_141a13030(CStringW& strText)
{
    strText.Trim(L" ");
    return strText.IsEmpty();
}

// @0x141a13070
int UIMessenger::FUN_141a13070(const CStringW& strName)
{
    for (unsigned int i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (!spTab)
            continue;
        if (spTab->m_strName == strName)
            return 1;
    }
    return 0;
}

// @0x141a13160
int UIMessenger::FUN_141a13160(TalkTab* pTab, int nChannel)
{
    return FUN_141a131a0(pTab, FUN_141482f00(nChannel));
}

// @0x141a131a0
int UIMessenger::FUN_141a131a0(TalkTab* pTab, int nType)
{
    if (pTab == 0)
        return 1;
    return pTab->m_panel.FUN_141482460(nType);
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a13210
void UIMessenger::FUN_141a13210()
{
    MS2Ptr<ASTextInput> spInput = m_textInput;
    if (spInput.IsNull())
        return;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x720, 0);
        return;
    }
    CStringW strText = spInput->FUN_1422e0b00();
    strText.Trim();
    std::list<ChatEmoticonDataPtr> found;
    std::list<ChatEmoticonDataPtr> aliases;
    FUN_1409eecd0()->FUN_1401e74c0(strText, &aliases);
    for (std::list<ChatEmoticonDataPtr>::iterator it = aliases.begin(); it != aliases.end(); ++it)
    {
        ChatEmoticonDataPtr spEmo = *it;
        if (!spEmo)
            continue;
        if (!spCli->FUN_140a39dd0(spEmo->m_nId))
            continue;
        found.push_back(spEmo);
    }
    if (found.empty())
        return;
    FUN_141a13510(found);
    spInput->FUN_1422e0ab0(CStringW(L""));
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a13510
void UIMessenger::FUN_141a13510(std::list<ChatEmoticonDataPtr>& emoticons)
{
    if (emoticons.empty())
        return;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x747, 0);
        return;
    }
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    ASObj data(2);
    Scaleform::GFx::Value arr;
    FUN_14256e3e0(pMovie, &arr);
    for (std::list<ChatEmoticonDataPtr>::const_iterator it = emoticons.begin(); it != emoticons.end(); ++it)
    {
        ChatEmoticonDataPtr spEmo = *it;
        if (!!spEmo)
        {
            ASObj item(2);
            item.FUN_1409c0d20("id", spEmo->m_nId);
            item.FUN_1407cbb20("imgPath", spEmo->m_strImagePath);
            item.FUN_1407cb9c0("width", spEmo->m_nWidth);
            item.FUN_1407cb9c0("height", spEmo->m_nHeight);
            item.FUN_1407cbbe0("favorite", spCli->FUN_140a39fa0(spEmo->m_nId));
            arr.PushBack(item.FUN_1422bb870());
        }
    }
    if (arr.GetArraySize() == 0)
        return;
    data.FUN_1409adbe0("emoticonDatas", arr);
    pDialog->Invoke("openChatEmoticonPreview", data.FUN_1422bb870());
}

// @0x141a13940
void UIMessenger::FUN_141a13940()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    pDialog->Invoke("closeChatEmoticonPreview");
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a139c0
void UIMessenger::FUN_141a139c0(const CStringW& strText, int bClear)
{
    if (!m_textOutput)
        return;
    int bAtEnd = m_textOutput->FUN_1422e4680();
    if (bClear)
        m_textOutput->FUN_1422e0b80(CString(""));
    if (!strText.IsEmpty())
        m_textOutput->FUN_1422e1430(strText);
    if (bAtEnd)
        m_textOutput->FUN_1422e4720();
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a13ac0
void UIMessenger::FUN_141a13ac0()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    int bAdditive = 0;
    for (unsigned i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab.get() != 0 && spTab->m_nAdditive != 0)
        {
            bAdditive = 1;
            break;
        }
    }
    pDialog->FUN_1407cb9c0("m_additiveTab", bAdditive);
    pDialog->Invoke("updateAdditiveButton");
}

// @0x141a13c20
void UIMessenger::FUN_141a13c20(int bUp)
{
    if (m_textInput == 0)
        return;
    if (m_textInput->FUN_1422c76c0() == 0)
        return;
    Unk_MsgHistory entry;
    if (m_pBrowser->FUN_141a261b0(bUp, entry))
    {
        m_inputHistory.RemoveAll();
        m_inputHistory.Copy(entry.m_keys);
        FUN_141a17830(entry.m_strText, 1);
        vfunc_94(entry.m_strText);
    }
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a13d20
CStringW UIMessenger::FUN_141a13d20()
{
    if (FUN_141482e80()->m_pBrowser != 0)
    {
        for (int i = 1; i < 100; i++)
        {
            CStringW strName = FUN_1409e97f0(0x57d, i);
            if (FUN_141482e80()->m_pBrowser->FUN_141a25410(0, strName))
                return strName;
        }
    }
    return FUN_14028de60(0x57d);
}

// @0x141a13e00
void UIMessenger::FUN_141a13e00()
{
    std::vector<int> types;
    types.push_back(0x10);
    types.push_back(0xb);
    types.push_back(0xc);
    types.push_back(0);
    types.push_back(7);
    types.push_back(8);
    types.push_back(0x12);
    types.push_back(0x14);
    m_subjects.clear();
    m_subjects.push_back(0);
    m_subjects.push_back(0xc);
    m_subjects.push_back(0xb);
    m_subjects.push_back(0x10);
    m_subjects.push_back(7);
    m_subjects.push_back(8);
    m_subjects.push_back(0x12);
    m_subjects.push_back(0x14);
    m_subjectIndex.clear();
    int nIndex = 0;
    for (std::vector<int>::iterator it = types.begin(); it != types.end(); ++it)
    {
        int& nType = *it;
        if (m_pBrowser->FUN_141a264c0(nType))
            continue;
        m_subjectIndex.insert(std::pair<int, int>(nIndex++, nType));
    }
}

// @0x141a14110
int UIMessenger::FUN_141a14110()
{
    for (std::vector<int>::iterator it = m_subjects.begin(); it != m_subjects.end(); ++it)
    {
        int& nType = *it;
        if (m_pBrowser->FUN_141a264c0(nType))
            continue;
        return FUN_141a141c0(nType);
    }
    return -1;
}

// @0x141a141c0
int UIMessenger::FUN_141a141c0(int nType)
{
    for (std::map<int, int>::iterator it = m_subjectIndex.begin(); it != m_subjectIndex.end(); ++it)
    {
        if (nType == it->second)
            return it->first;
    }
    return -1;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a14250
int UIMessenger::FUN_141a14250()
{
    if (MS2Ptr<ASTextInput> spInput = m_textInput)
    {
        CStringW strText = spInput->FUN_1422e0b00();
        strText.Trim();
        if (strText.GetLength() < 2)
            return 0x1b;
        if (strText.GetAt(0) == L'/')
        {
            const int& nType = CUserCommandCli::GetInstance()->ChatType(strText);
            if (!m_pBrowser->FUN_141a264c0(nType))
                return nType;
            return FUN_141a14500();
        }
        if (FUN_14025e7c0()->FUN_14116d720())
        {
            int nLast = strText.GetLength() - 1;
            if (strText.GetAt(0) == L':' && strText.GetAt(nLast) == L':')
            {
                std::list<ChatEmoticonDataPtr> aliases;
                FUN_1409eecd0()->FUN_1401e74c0(strText, &aliases);
                if (aliases.size() != 0)
                    return 0x18;
            }
        }
    }
    return 0x1b;
}

// @0x141a144a0
int UIMessenger::FUN_141a144a0()
{
    if (m_subject)
        return FUN_141a14580(m_subject->FUN_1422df6c0());
    return FUN_141a14500();
}

// @0x141a14500
int UIMessenger::FUN_141a14500()
{
    std::map<int, int>::iterator it = m_subjectIndex.find(FUN_141a14110());
    if (it != m_subjectIndex.end())
        return it->second;
    return 0x1b;
}

// @0x141a14580
int UIMessenger::FUN_141a14580(int nIndex)
{
    std::map<int, int>::iterator it = m_subjectIndex.find(nIndex);
    if (it != m_subjectIndex.end())
        return it->second;
    return FUN_141a14500();
}

// @0x141a14600
void UIMessenger::FUN_141a14600()
{
    int nType = FUN_141a14250();
    switch (nType)
    {
    case 0:
    case 7:
    case 8:
    case 0xb:
    case 0xc:
    case 0x10:
    case 0x12:
        FUN_141a146d0(nType);
        break;
    case 4:
        FUN_141a17900(m_pBrowser->m_strWhisperTarget);
        break;
    case 0x14:
        FUN_141a17a60(m_pBrowser->m_1a8);
        break;
    }
}

// @0x141a146d0
void UIMessenger::FUN_141a146d0(int nType)
{
    if (!FUN_141a12f30())
        return;
    if (m_subject.get())
    {
        m_subject->FUN_1422df690(FUN_141a141c0(nType));
        vfunc_93();
    }
}

// @0x141a14760
void UIMessenger::FUN_141a14760()
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_subject.get() != 0)
    {
        unsigned nCount = m_subject->FUN_1422df620();
        unsigned nNext = m_subject->FUN_1422df6c0() + 1;
        if (nNext >= nCount)
            nNext = 0;
        int nType = FUN_141a14580(nNext);
        if (nType == 0x10)
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e2e0(pPlayer->FUN_1416639e0());
            if (spItem == 0)
            {
                if (m_pBrowser->FUN_141a264c0(0xb))
                    nType = FUN_141a14500();
                else
                    nType = 0xb;
            }
        }
        FUN_141a146d0(nType);
    }
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a148b0
int UIMessenger::FUN_141a148b0(const CStringW& strText)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ATL::CAtlArray<MS2Ptr<CSkillSystem::stEmotion> > emotions;
    pPlayer->FUN_141523bc0()->FUN_1417691a0(emotions);
    if (emotions.GetCount() == 0)
        return 0;
    CStringW strLine(strText);
    FUN_140d2c650(strLine);
    int nBegin = strLine.Find(L'/', 0);
    if (nBegin == -1)
        return 0;
    int nEnd = strLine.Find(L' ', nBegin);
    if (nEnd == -1)
        nEnd = strLine.GetLength();
    CStringW strCommand = strLine.Mid(nBegin, nEnd);
    strCommand.TrimRight();
    for (unsigned int i = 0; i < emotions.GetCount(); i++)
    {
        MS2Ptr<Unk_MsgEmotionKeywords> spKeywords = FUN_140347050(emotions[i]->m_id);
        if (spKeywords == 0)
            return 0;
        for (unsigned int j = 0; j < spKeywords->m_keywords.GetCount(); j++)
        {
            CStringW strKeyword = spKeywords->m_keywords[j];
            if (strKeyword.CompareNoCase(strCommand) == 0)
            {
                pPlayer->FUN_141525480(spKeywords->m_nAction, 0);
                return 1;
            }
        }
    }
    return 0;
}

// @0x141a14bb0
void UIMessenger::FUN_141a14bb0(const CStringW& strTarget)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (pPlayer->vfunc_77() == strTarget)
        return;
    FUN_141a17900(strTarget);
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a14c40
bool UIMessenger::FUN_141a14c40(CStringW& strText, CStringW strPart)
{
    int nFound = strText.Find(strPart, 0);
    if (nFound == -1)
        return false;
    strText.Delete(nFound, strPart.GetLength());
    return true;
}

// @0x141a14ce0
bool UIMessenger::FUN_141a14ce0(CStringW strText, int nMax)
{
    int nOpen = 0;
    while ((nOpen = strText.Find(L"<", 0)) != -1)
    {
        int nClose = strText.Find(L">", nOpen + 1);
        if (nClose == -1)
            break;
        strText.Delete(nOpen, nClose - nOpen + 1);
    }
    if (strText.GetLength() > nMax)
        return false;
    return true;
}

// @0x141a15890
void UIMessenger::FUN_141a15890()
{
    bool bEffect = false;
    const int& nType = FUN_141a14580(m_nTargetSelectedIndex);
    if (nType == 0x10 && !m_pBrowser->FUN_141a264c0(nType))
        bEffect = true;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("updateSuperWorldChatEffect", bEffect);
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a15970
void UIMessenger::FUN_141a15970()
{
    if (!m_buttonBar)
        return;
    unsigned nCount = m_buttonBar->FUN_1422e3380();
    ATL::CAtlArray<MS2Ptr<TalkTab> > tabs;
    for (unsigned i = 0; i < nCount; i++)
    {
        TalkTab* pTab = FUN_141a0e0f0(m_buttonBar->FUN_1422e37e0(i));
        if (pTab == 0)
            return;
        tabs.Add(MS2Ptr<TalkTab>(pTab));
    }
    m_tabs.RemoveAll();
    m_tabs.Copy(tabs);
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a15ae0
void UIMessenger::vfunc_87(const CStringW& strMsg, const CString& strWindow)
{
    if (m_tabs.IsEmpty())
        return;
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    Scaleform::GFx::Value names;
    FUN_14256e3e0(pMovie, &names);
    for (unsigned i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab.get() == 0)
            continue;
        if (spTab->m_panel.FUN_141482200()->m_nWhisper == 0)
            continue;
        if (spTab == FUN_141a0e050())
            continue;
        names.PushBack(Scaleform::GFx::Value((const wchar_t*)spTab->m_strName));
    }
    if (names.GetArraySize() != 0)
        pDialog->Invoke("whisperFrom", Scaleform::GFx::Value(names));
}

// @0x141a15d70
void UIMessenger::vfunc_89(const CStringW& strText, int nChannel)
{
    vfunc_88(strText, FUN_141482f00(nChannel));
}

// @0x141a15dc0
int UIMessenger::vfunc_88(const CStringW& strText, int nType)
{
    TalkTab* pTab = FUN_141a0e050();
    if (pTab == 0)
        return 0;
    if (FUN_141a131a0(pTab, nType))
        return 1;
    CStringW strLine(strText);
    FUN_141a0ead0(pTab->m_panel.FUN_1414821b0()->m_nFontSize, strLine);
    FUN_141a139c0(strLine, 0);
    return 1;
}

// @0x141a15e80
void UIMessenger::vfunc_90()
{
    FUN_141482e80()->FUN_141482c80(m_strName);
}

// @0x141a15ef0
void UIMessenger::vfunc_91()
{
    m_pBrowser->m_itHistory = m_pBrowser->m_history.end();
}

// @0x141a15f60
void UIMessenger::vfunc_92()
{
    if (FUN_1403ed2b0()->FUN_141adc940(0x4e62))
    {
        const CStringW& strName = FUN_141a13d20();
        if (FUN_141a0e810(strName, 1, 1, 0))
        {
            FUN_141a0e2a0(strName);
            vfunc_4();
            FUN_141482e80()->m_nNewTabMode = 2;
            FUN_141482e80()->m_pNewTabWindow = this;
            FUN_1403ed2b0()->FUN_141adc530(0x4e62);
        }
    }
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a16030
void UIMessenger::vfunc_93()
{
    if (FUN_1422dc2d0())
    {
        CStringW strHtml = m_textInput->FUN_1422e0c20();
        CStringW strText = m_textInput->FUN_1422e0b00();
        if (strText.GetAt(0) == L'/')
        {
            int nSpace = strText.Find(L" ", 0);
            if (nSpace == -1)
            {
                strHtml = L"";
            }
            else
            {
                strText = strText.Mid(0, nSpace);
                FUN_141a14c40(strHtml, strText);
            }
        }
        FUN_141a17830(strHtml, 1);
        if (m_subject)
        {
            m_nTargetSelectedIndex = m_subject->FUN_1422df6c0();
            const int& nType = FUN_141a14580(m_nTargetSelectedIndex);
            if (!m_pBrowser->FUN_141a264c0(nType) && (nType == 0x10 || nType == 0xb || nType == 0xc))
                GetClientPlatform()->vfunc_43(2, false, 1000);
            FUN_141a15890();
        }
    }
}

// @0x141a162a0
void UIMessenger::vfunc_94(const CStringW& strText)
{
    if (FUN_141a14250() == 4)
        FUN_141a131f0();
    else
        FUN_141a13200();
}

// @0x141a162e0
void UIMessenger::vfunc_95(const CStringW& strTarget)
{
    FUN_141a14bb0(strTarget);
}

// @0x141a16310
void UIMessenger::vfunc_96(int nMenu)
{
    if (nMenu == 0)
    {
        FUN_141482e80()->m_nNewTabMode = 1;
        FUN_141482e80()->m_pNewTabWindow = this;
        FUN_1403ed2b0()->FUN_141adc530(0x4e62);
    }
    else if (nMenu == 1)
    {
        if (FUN_141a0e350(FUN_141a0dfc0()))
        {
            if (FUN_141482e80()->m_pBrowser != 0)
                FUN_141482e80()->m_pBrowser->FUN_141a245d0(m_strName);
            vfunc_4();
        }
    }
}

// @0x141a16400
void UIMessenger::vfunc_97(const CStringW& strName)
{
    TalkTab* pTab = FUN_141a0e0f0(strName);
    if (pTab == 0)
        return;
    CStringW strHtml;
    POSITION pos = m_pBrowser->m_logs.GetHeadPosition();
    while (pos != 0)
    {
        MessengerData::TalkLog& log = m_pBrowser->m_logs.GetNext(pos);
        if (FUN_141a131a0(pTab, log.m_nKind))
            continue;
        strHtml += log.m_strMsg;
    }
    FUN_141a0ead0(pTab->m_panel.FUN_1414821b0()->m_nFontSize, strHtml);
    FUN_141a0ebb0(pTab->m_panel.FUN_1414821b0()->m_nBackgroundAlpha);
    FUN_141a139c0(strHtml, 1);
    if (m_buttonBar)
        m_nTabSelectedIndex = m_buttonBar->FUN_1422e3210();
    m_pBrowser->m_194 = (int)m_pBrowser->m_logs.GetCount();
    m_pBrowser->m_pendingLogs.RemoveAll();
}

// @0x141a165c0
void UIMessenger::vfunc_98(const CStringW& strName, const CString& strWindow)
{
    MS2Ptr<TalkTab> spTab = FUN_141a0e0f0(strName);
    if (!spTab)
        return;
    UIMessenger* pWindow = FUN_141a184c0(CString(strWindow));
    if (pWindow == 0)
        return;
    if (FUN_141a0e350(spTab->m_strName))
    {
        if (pWindow->FUN_141a0e650(spTab.get()))
        {
            pWindow->FUN_141a0e2a0(spTab->m_strName);
            pWindow->vfunc_4();
        }
        if (FUN_141482e80()->m_pBrowser != 0)
            FUN_141482e80()->m_pBrowser->FUN_141a245d0(m_strName);
        vfunc_4();
    }
}

// @0x141a16730
void UIMessenger::FUN_141a16730(const CStringW& strName, int nX, int nY, int nWidth, int nHeight, int nTarget)
{
    MS2Ptr<TalkTab> spTab = FUN_141a0e0f0(strName);
    if (!spTab)
        return;
    if (m_tabs.GetCount() < 2)
        return;
    if (FUN_141a0e350(spTab->m_strName))
    {
        ATL::CAtlArray<MS2Ptr<TalkTab> > tabs;
        tabs.Add(spTab);
        if (FUN_141482e80()->m_pBrowser != 0)
            FUN_141482e80()->m_pBrowser->FUN_141a24160(tabs, nX, nY, nWidth, nHeight, nTarget);
        FUN_141a0e990();
        vfunc_4();
    }
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a168a0
void UIMessenger::FUN_141a168a0(const ATL::CAtlArray<CStringW>& args)
{
    if (FUN_140841300(args[0], "dungeonRoom"))
    {
        if (args.GetCount() == 2)
            FUN_141a16c50(FUN_140718200(args[1]));
    }
    else if (FUN_140841300(args[0], "joinPartyDungeonHelper"))
    {
        if (args.GetCount() == 4)
        {
            int nPartyId = FUN_140718200(args[1]);
            CStringW strLeader(args[2]);
            int nRoomId = FUN_140718200(args[3]);
            FUN_141a16cc0(nPartyId, strLeader, nRoomId);
        }
    }
    else if (FUN_140841300(args[0], "joinPartyDungeonMember"))
    {
        if (args.GetCount() == 4)
        {
            int nPartyId = FUN_140718200(args[1]);
            CStringW strLeader(args[2]);
            int nRoomId = FUN_140718200(args[3]);
            FUN_141a172a0(nPartyId, strLeader, nRoomId);
        }
    }
    else if (FUN_140841300(args[0], "inviteParty") && args.GetCount() == 2)
    {
        FUN_141a17690(args[1]);
    }
}

// @0x141a16bb0
void UIMessenger::FUN_141a16bb0(int nProductId, int nA, int nB)
{
    UICashShopDialog* pShop = FUN_140b04f80(0x4ebc);
    if (pShop == 0)
        return;
    ATL::CAtlArray<int> ids;
    ids.Add(nProductId);
    CString strName("OnUserBillDialog");
    pShop->FUN_141035990(strName, ids, false);
}

// @0x141a16c50
void UIMessenger::FUN_141a16c50(int nRoomId)
{
    UIDungeonRoomDialog* pDialog = FUN_140961550(0x4ebd);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630())
            pDialog->vfunc_68();
        pDialog->FUN_1412b8ff0(nRoomId);
        pDialog->FUN_141924680();
    }
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a16cc0
void UIMessenger::FUN_141a16cc0(int nPartyId, CStringW strLeader, int nRoomId)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    if (pMe->vfunc_77() == strLeader)
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_party_is_my_dungeon_help")), 1, 1);
        return;
    }
    if (FUN_1409670d0()->FUN_14162ab20())
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_party_has_party")), 1, 1);
        return;
    }
    int nState = FUN_140931510()->FUN_140d9f880(nRoomId);
    if (nState >= 10)
    {
        FUN_1412b9870(nRoomId, nState);
        return;
    }
    if (!FUN_140931510()->FUN_140d9f2c0()->CanClaimHelperReward(nRoomId))
    {
        DungeonRoomPtr spRoom = FUN_14031c2a0()->GetRoom(nRoomId);
        if (!(spRoom == 0))
        {
            const int& nClears = spRoom->m_dungeonHelperRequireClearCount;
            FUN_1412751f0(FUN_140bfa7f0(CStringW(L"s_party_join_only_dungeon_expert"),
                                        FUN_1401a9d70()->FUN_141811980(0x14, nRoomId), nClears), 1, 1);
        }
        return;
    }
    CStringW strMsg = FUN_1408f71a0(CStringW(L"s_party_join_dungeon_helper_msg"), strLeader,
                                    FUN_1401a9d70()->FUN_141811980(0x14, nRoomId));
    MS2Ptr<CMsgBoxData> box = FUN_140d74230(
        Delegate<bool(int, const CMsgBoxData&)>(this, &UIMessenger::FUN_141a17bc0), CStringW(strMsg));
    if (box.get() != 0)
    {
        box->FUN_140534050(nPartyId);
        box->FUN_140534050(nRoomId);
    }
}

// @0x141a172a0
void UIMessenger::FUN_141a172a0(int nPartyId, CStringW strLeader, int nRoomId)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    if (pMe->vfunc_77() == strLeader)
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_party_is_my_dungeon_help")), 1, 1);
        return;
    }
    if (FUN_1409670d0()->FUN_14162ab20())
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_party_has_party")), 1, 1);
        return;
    }
    int nState = FUN_140931510()->FUN_140d9f880(nRoomId);
    if (nState >= 10)
    {
        FUN_1412b9870(nRoomId, nState);
        return;
    }
    CStringW strMsg = FUN_1408f71a0(CStringW(L"s_party_join_dungeon_member_msg"), strLeader,
                                    FUN_1401a9d70()->FUN_141811980(0x14, nRoomId));
    MS2Ptr<CMsgBoxData> box = FUN_140d74230(
        Delegate<bool(int, const CMsgBoxData&)>(this, &UIMessenger::FUN_141a17c90), CStringW(strMsg));
    if (box.get() != 0)
    {
        box->FUN_140534050(nPartyId);
        box->FUN_140534050(nRoomId);
    }
}

// @0x141a17690
void UIMessenger::FUN_141a17690(CStringW strName)
{
    FUN_1409670d0()->FUN_14162ba50(CStringW(strName));
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a17700
void UIMessenger::FUN_141a17700()
{
    if (m_30.IsNull())
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0 || m_textInput.IsNull())
        return;
    if (!m_chatEmoticonPreview.IsNull() && m_textInput->FUN_1422c76c0() && m_chatEmoticonPreview->FUN_1422bfca0())
    {
        pDialog->Invoke("pushChatEmoticon");
        return;
    }
    FUN_141a11e30();
}

// @0x141a17830
void UIMessenger::FUN_141a17830(const CStringW& strText, int bSelectEnd)
{
    if (m_textInput == 0)
        return;
    m_textInput->FUN_1422e0bd0(strText);
    int nLength = strText.GetLength();
    if (bSelectEnd != 0 && nLength > 0)
        m_textInput->FUN_1422e1500(nLength, nLength);
    m_textInput->vfunc_24(1);
}

// @0x141a17900
void UIMessenger::FUN_141a17900(const CStringW& strTarget)
{
    CStringW strText;
    if (strTarget.IsEmpty())
        strText = FUN_1401e8510(L"{0} ", FUN_14028de60(0xaa5));
    else
        strText = FUN_140656190(L"{0} {1} ", FUN_14028de60(0xaa5), strTarget);
    FUN_141a17830(strText, 1);
}

// @0x141a17bc0
bool UIMessenger::FUN_141a17bc0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        unsigned nPartyId = box.FUN_141a02e90(0, 0);
        unsigned nRoomId = box.FUN_141a02e90(1, 0);
        if (nPartyId == 0 || nRoomId == 0)
            return true;
        COutPacket packet(0x2c, 0);
        packet.vfunc_o10_1(0x27);
        packet.vfunc_o10_3(nPartyId);
        packet.vfunc_o10_3(nRoomId);
        FUN_140710590(packet);
    }
    return true;
}

// @0x141a17c90
bool UIMessenger::FUN_141a17c90(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        unsigned nPartyId = box.FUN_141a02e90(0, 0);
        unsigned nRoomId = box.FUN_141a02e90(1, 0);
        if (nPartyId == 0 || nRoomId == 0)
            return true;
        COutPacket packet(0x2c, 0);
        packet.vfunc_o10_1(0x2b);
        packet.vfunc_o10_3(nPartyId);
        packet.vfunc_o10_3(nRoomId);
        FUN_140710590(packet);
    }
    return true;
}

// @0x141a184c0
UIMessenger* FUN_141a184c0(CString strName)
{
    return dynamic_cast<UIMessenger*>(FUN_140b632f0()->GetUISwfEntity(strName).get());
}

// @0x141a17a60
void UIMessenger::FUN_141a17a60(const CStringW& strTarget)
{
    CStringW strText;
    if (strTarget.IsEmpty())
        strText = FUN_1401e8510(L"{0} ", FUN_14028de60(0xaa6));
    else
        strText = FUN_140656190(L"{0} {1} ", FUN_14028de60(0xaa6), strTarget);
    FUN_141a17830(strText, 1);
}

// @0x141a131f0
void UIMessenger::FUN_141a131f0()
{
}

// @0x141a13200
void UIMessenger::FUN_141a13200()
{
}

// ==== the browser TU (0x141a20f90-) ====

// ---- statics of the browser TU (.text$di, in init order; the same header statics as the window TU) ----
static CString s_strSortTypeNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillB = "skill";                              // 0x143af3fd8
static CString s_strStunB = "stun";                                // 0x143af3fd0
static Unk_1402a9d70 s_unkTabB(17, 0.75f, 0.25f, 2.25f, 10);       // 0x143af4020
static CString s_strGuildMegaphoneSound = "System_GuildMegaphone";  // 0x143af4068
static CString s_strWhisperSound = "system_notice_whisper";        // 0x143af4018

// ---- unit-local views of exe types (browser TU) ----

// The chat line packet body (unit_1407a4f20.cpp's Unk_1407a5330; reader FUN_1407a5500).
struct Unk_1407a5330
{
    Unk_1407a5330()
        : m_nAccountId(0), m_nCharId(0), m_nType(0), m_28(0), m_30(0), m_34(0), m_40(0), m_nStringId(0), m_4c(0),
          m_nFieldId(0)
    {
    }
    __int64 m_nAccountId;                                           // +0x00
    __int64 m_nCharId;                                              // +0x08
    CStringW m_strName;                                             // +0x10 the speaker
    CStringW m_strText;                                             // +0x18 (or the string m_nStringId)
    int m_nType;                                                    // +0x20 the chat type
    __int64 m_28;                                                   // +0x28
    int m_30;                                                       // +0x30
    int m_34;                                                       // +0x34
    CString m_strWindow;                                            // +0x38 type 3: the whisper window
    __int64 m_40;                                                   // +0x40 type 0x14
    int m_nStringId;                                                // +0x48 the system string
    int m_4c;                                                       // +0x4c
    int m_nFieldId;                                                 // +0x50 types 0x10 / 0x19: the field
};
void FUN_1407a5500(Unk_1407a5330& line, CInputStream& in);

// The extra block of a type 0x19 line (unit_1407a4f20.cpp's Unk_1407a5820).
struct Unk_1407a5820
{
    Unk_1407a5820();                                                // 0x1407a5820
    __int64 m_00;
    int m_08;
    int m_0c;
    __int64 m_10;
    CStringW m_18;
    CStringW m_20;
};
void FUN_1407a5960(Unk_1407a5820& extra, CInputStream& in);

// The packet handlers by opcode.
class Unk_MbPackets
{
public:
    void FUN_140da5180(int nOpcode, Delegate<void(CInPacket&)> cb);   // subscribe
    void FUN_140da51e0(int nOpcode, Delegate<void(CInPacket&)> cb);   // unsubscribe
};
Unk_MbPackets* FUN_140bccd50();

// The inventory item events.
class Unk_MbItemEvents;
Unk_MbItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_MbItemEvents* pEvents, UIItemEventListener* pListener);   // add a listener
void FUN_1419caeb0(Unk_MbItemEvents* pEvents, UIItemEventListener* pListener);   // remove it

// The ban word filters.
class Unk_MbChecker : public CPtred
{
public:
    void FUN_140226980(CStringW& str);                              // masks the banned words
    void FUN_140226b10(CStringW& str);                              // filters the reserved words
};
class Unk_MbStrings { public: MS2Ptr<Unk_MbChecker> FUN_140229a50(); };
Unk_MbStrings* FUN_14025e7d0();
class Unk_MbDynamicBan { public: int FUN_14034a230(const CStringW& str, CStringW& strReplaced); };   // 2: drop, 1: replaced
Unk_MbDynamicBan* FUN_1414a56d0();
class Unk_MbBlind { public: bool FUN_140a25840(int nKind, CStringW strName); };   // the user is blinded
Unk_MbBlind* FUN_1409c1730();
class Unk_MbBuddies
{
public:
    unsigned FUN_140ae51b0(__int64 nCharId);                        // blocked by id
    unsigned FUN_140ae5240(const CStringW& strName);                // blocked by name
};
Unk_MbBuddies* FUN_14097a780();
class Unk_MbFeatures
{
public:
    bool FUN_14036d570(int nFeature);
    bool FUN_14036e5b0();                                           // the meret market is off
};
Unk_MbFeatures* FUN_140166410();
class Unk_MbReserved { public: void FUN_1416fb340(CStringW& str); };
Unk_MbReserved* FUN_1403b4750();

// The game options: the community switches and the chat balloon switches.
class Unk_MbBalloons { public: int FUN_14125c820(int nType); };   // the balloon shows the chat type
class Unk_MbGameOption
{
public:
    Unk_CommunityStateB* FUN_140ae6540();
    Unk_MbBalloons* FUN_140b123b0();
};
Unk_MbGameOption* FUN_1409a8b10();

class Unk_MbTalk { public: int FUN_141b21220(); };               // UITalkManager: a talk is running
Unk_MbTalk* FUN_140967100();
class Unk_MbItemTable { public: int FUN_1405569f0(int nGrade); };   // the grade colour
Unk_MbItemTable* FUN_140281980();
class Unk_MbLogs { public: void FUN_141451a60(); };               // ClientLogManager::Flush
Unk_MbLogs* FUN_1412976a0();
class Unk_MbConfig { public: char m_pad_00[0x60]; CString m_strRoot; };   // +0x60 the client root
Unk_MbConfig* FUN_1401d31f0();
CUserCommandCli* FUN_14135a4d0();
UIWhisperNotifyDialog* FUN_140e88970(int nUiId);                    // Unk_GetUI<UIWhisperNotifyDialog>
CLogString* FUN_140166440();

extern MessengerData::ScreenSetting DAT_143adda48;                 // messengerdata.cpp: the shared screen look
extern int DAT_143ab2864;                                          // the own object id
extern unsigned long DAT_1439f880c;                                // the system notice colour

CStringW FUN_1401aa6a0(int n);                                      // to string
CStringW FUN_14052bd00(int nStringId, const CStringW& a);
CStringW FUN_140632a60(int nStringId, const CStringW& a, const CStringW& b);
void FUN_141275260(int nStringId, int nA, int nB);                  // a system message by id
int FUN_141276180(const CString& strSound, const CString& strB);    // plays a system sound
void FUN_141275150(CItem* pItem, int nCount, int nOld, int nManyId, int nOneId);   // inventory count message
void FUN_1412750f0(CItem* pItem, int nSlot, int nManyId, int nOneId);
CStringW FUN_1402758a0(const wchar_t* szFormat, const CStringW& a, const unsigned& b);
CStringW FUN_141842c40(const wchar_t* szFormat, const CStringW& a, const unsigned __int64& b, const unsigned __int64& c);
CStringW FUN_1418428c0(const wchar_t* szFormat, const unsigned& a, const CStringW& b, const unsigned& c);
CStringW FUN_140292a70(const wchar_t* szFormat, const unsigned& a);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& a);
CStringW FUN_1409eaa20(CStringW strKey, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW FUN_141843060(CStringW strKey, const unsigned long& a, const unsigned& b, const CStringW& c);
CStringW FUN_140cbf840(int nGroupType);                             // the dungeon group name
CStringW FUN_14183f310(const Unk_1407a5330& line, const CStringW& strText, int nFontSize);   // the html line
CStringW FUN_141841180(const Unk_1407a5330& line, const Unk_1407a5820& extra, const CStringW& strText, int nFontSize);
CStringW FUN_14183f080(const CStringW& strText, int n, int nFontSize);   // the html system line
CStringW FUN_141841fd0(CStringW strText, int nFontSize);            // the html notice line
CStringW FUN_141841b40(CItem* pItem, const CStringW& strKind, int nFontSize);   // the html item link
CStringW FUN_141841c60(int nPartyId, CStringW strLeader, __int64 nA, __int64 nCharId, int nRoomId, int nGroupType,
                       unsigned bFlag, unsigned nMaxUsers, int nFontSize);   // the helper recruit line
bool FUN_140d2ab10(CStringW& strHtml);
bool FUN_140d2c080(CStringW strHtml, ATL::CAtlList<CStringW>& links, CStringW strBegin, CStringW strEnd);   // the links
unsigned __int64 FUN_140d2caf0(const CStringW& strLink);            // the item uid of a link
CStringW FUN_14183e930(const CStringW& strLink, int nColor);       // the link in a colour
void FUN_14083d2b0(CStringW& strHtml);                              // html to text
void FUN_1401d3700(CString& strFile);                               // localizes a file name
void FUN_140841420(CStringW& strFile);
CString FUN_140188f50(const char* psz, unsigned n);
CString FUN_141275750();                                            // the default UI settings directory
CString FUN_14016a5c0(const char* psz, int n);
CStringW FUN_14016a730(const char* psz, int n);                     // narrow -> wide
bool thunk_FUN_1420b1ae0(const char* pszPath);                      // directory exists
__int64 FUN_140869440();                                            // now
int FUN_1418dd0c0();                                                // the bottom bar height
int FUN_1418dd110();

WC_WRAP(7)

// The unit's log calls (FMT_VARIADIC shapes over CLogString::FUN_1406530d0).
// @0x141a28740
template <class T0, class T1>
inline void Unk_MbLog(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const T0& v0, const T1& v1)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v0),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v1)};
    pLog->FUN_1406530d0(nLevel, nCategory, szFormat, fmt::ArgList(fmt::internal::make_type(v0, v1), args));
}
// @0x141a28390
template <class T0, class T1, class T2, class T3>
inline void Unk_MbLog(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const T0& v0, const T1& v1,
                      const T2& v2, const T3& v3)
{
    const fmt::internal::ArgArray<4>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v0),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v1),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v2),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v3)};
    pLog->FUN_1406530d0(nLevel, nCategory, szFormat, fmt::ArgList(fmt::internal::make_type(v0, v1, v2, v3), args));
}

// ---- UIMessengerBrowser ----

// @0x141a20f90
UIMessengerBrowser::UIMessengerBrowser()
    : m_180(1), m_184(1), m_188(1), m_18c(500), m_190(600), m_194(0), m_198(10), m_strWhisperTarget(""), m_1a8(L""),
      m_1b0(0)
{
    m_80 = 1;
    m_88 = 1;
    FUN_141925e70(0, 1);
    m_itHistory = m_history.end();
    FUN_141482e80()->m_pBrowser = this;
    FUN_140bccd50()->FUN_140da5180(0x1d, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::vfunc_84));
    FUN_140bccd50()->FUN_140da5180(0x1e, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::vfunc_85));
    FUN_140bccd50()->FUN_140da5180(0x90, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::FUN_141a22ee0));
    FUN_140bccd50()->FUN_140da5180(0x92, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::FUN_141a22fc0));
    FUN_140bccd50()->FUN_140da5180(0x109, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::FUN_141a23060));
}

// @0x141a215a0
UIMessengerBrowser::~UIMessengerBrowser()
{
    m_history.clear();
    m_itHistory = m_history.end();
    FUN_141482e80()->m_pBrowser = 0;
    FUN_140bccd50()->FUN_140da51e0(0x1d, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::vfunc_84));
    FUN_140bccd50()->FUN_140da51e0(0x1e, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::vfunc_85));
    FUN_140bccd50()->FUN_140da51e0(0x90, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::FUN_141a22ee0));
    FUN_140bccd50()->FUN_140da51e0(0x92, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::FUN_141a22fc0));
    FUN_140bccd50()->FUN_140da51e0(0x109, Delegate<void(CInPacket&)>(this, &UIMessengerBrowser::FUN_141a23060));
}

// @0x141a21a60
CString UIMessengerBrowser::vfunc_1()
{
    return "MessengerBrowser";
}

// @0x141a21ab0
int UIMessengerBrowser::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    FUN_1419cae20(FUN_140a6a840(), this);
    return 1;
}

// @0x141a21b10
void UIMessengerBrowser::vfunc_67()
{
    UIDialog::vfunc_67();
    for (unsigned int i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0)
        {
            pWindow->vfunc_67();
            FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(pWindow));
        }
    }
    m_windows.RemoveAll();
    FUN_1419caeb0(FUN_140a6a840(), this);
}

// @0x141a21c50
int UIMessengerBrowser::vfunc_9()
{
    for (size_t i = 0; i < m_windows.GetCount(); i++)
    {
        if (m_windows[i]->vfunc_9())
            return 1;
    }
    return 0;
}

// @0x141a21ce0
void UIMessengerBrowser::vfunc_8(int nVisible)
{
    for (size_t i = 0; i < m_windows.GetCount(); i++)
        m_windows[i]->vfunc_8(nVisible);
}

// @0x141a21d60
int UIMessengerBrowser::vfunc_74(int a1, void* p2, void* p3)
{
    if (a1 != 0x10f && a1 != 0x102)
        return 0;
    if (m_windows.IsEmpty())
        return 0;
    size_t nCount = m_windows.GetCount();
    bool bHandled = false;
    for (size_t i = 0; i < nCount; i++)
        bHandled = bHandled || m_windows[i]->vfunc_74(a1, p2, p3) == 1;
    return bHandled == true;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a21e90
void UIMessengerBrowser::vfunc_43()
{
    if (m_60 == 0)
        return;
    if (m_windows.IsEmpty())
        return;
    float fY = (float)(unsigned)(FUN_1418dd0c0() + FUN_1418dd110()) * -1.0f;
    float fX = 0.0f;
    int nTop = 0;
    int nRight = 0;
    ASDialog* pRoot = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pRoot != 0)
    {
        nTop = pRoot->FUN_1422c1530();
        nTop = 0x32 - nTop;
        nRight = pRoot->FUN_1422c1500();
        nRight = nRight - 100;
    }
    size_t nCount = m_windows.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow == 0)
            continue;
        MS2Ptr<AScript> spMovie = pWindow->FUN_1422dba00();
        if (spMovie.get() != 0)
        {
            ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)spMovie);
            if (pDialog != 0)
            {
                pDialog->vfunc_2(7, (int)fX, (int)fY);
                pWindow->FUN_141a0f180();
                fY = fY - (float)(pDialog->FUN_1422c13b0() + 10);
                if (fY < (float)nTop)
                {
                    fX = fX + 100.0f;
                    if ((float)nRight < fX)
                        fX = 0.0f;
                }
            }
        }
    }
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141a22140
void UIMessengerBrowser::vfunc_84(CInPacket& packet)
{
    Unk_1407a5330 line;
    FUN_1407a5500(line, packet);
    CStringW strName(line.m_strName);
    CStringW strText(line.m_strText);
    __int64 nCharId = line.m_nCharId;
    FUN_140d2c650(strText);
    Unk_MbChecker* pChecker = FUN_14025e7d0()->FUN_140229a50().get();
    if (pChecker != 0)
    {
        pChecker->FUN_140226980(strText);
        pChecker->FUN_140226b10(strText);
    }
    if (FUN_1414a56d0() != 0)
    {
        CStringW strReplaced;
        int nResult = FUN_1414a56d0()->FUN_14034a230(strText, strReplaced);
        if (nResult == 2)
            return;
        if (nResult == 1)
            strText = strReplaced;
    }
    if (strText.IsEmpty())
        return;
    if (FUN_1409c1730()->FUN_140a25840(0, strName))
        return;
    if (line.m_nType == 5)
    {
        strText = FUN_14028de60(0x4d);
        FUN_141275260(0x4d, 1, 0);
    }
    else if (line.m_nType == 6)
    {
        strText = FUN_14052bd00(0x8cd, strName);
        FUN_1412751f0(strText, 1, 0);
    }
    else if (line.m_nType == 3)
    {
        if (MSG_COMMUNITY_FLAGS(FUN_1409a8b10()->FUN_140ae6540())->m_b7)
        {
            // the whisper block option: answer with the block notice
            Unk_CommandChat chat;
            chat.kind = 6;
            chat.target = strName;
            FUN_141276f80(chat);
            return;
        }
        CString strWindow(line.m_strWindow);
        for (unsigned i = 0; i < m_windows.GetCount(); i++)
        {
            UIMessenger* pWindow = m_windows[i];
            if (pWindow != 0)
                pWindow->vfunc_87(strText, strWindow);
        }
        UIWhisperNotifyDialog* pNotify = FUN_140e88970(0x4e5e);
        if (pNotify != 0)
            pNotify->FUN_141b51e30(nCharId, strText, strWindow);
        FUN_141276180(s_strWhisperSound, CString(""));
    }
    else if (line.m_nType == 0x11)
    {
        FUN_1412751f0(strText, 1, 1);
    }
    else if (line.m_nType == 0xd || line.m_nType == 0xe)
    {
        if (line.m_nStringId == 0x35)
            FUN_1403ed2b0()->FUN_141add1f0();
        else
            FUN_1412751f0(strText, 1, 1);
    }
    else if (line.m_nType == 0xf)
    {
        if (!FUN_140d2ab10(strText))
            return;
    }
    else if (line.m_nType == 0x10)
    {
        MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe != 0 && pMe->FUN_141656a80() == nCharId)
        {
            CStringW strMsg = FUN_14052bd00(0xac7, FUN_1401a9d70()->FUN_141811980(1, line.m_nFieldId));
            FUN_1412751f0(strMsg, 1, 1);
        }
    }
    else if (line.m_nType == 0x19)
    {
        MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe != 0 && pMe->FUN_141656a80() == nCharId)
        {
            CStringW strMsg = FUN_14052bd00(0xaca, FUN_1401a9d70()->FUN_141811980(1, line.m_nFieldId));
            FUN_1412751f0(strMsg, 1, 1);
        }
    }
    else if (line.m_nType == 0x1a)
    {
        FUN_1412751f0(strText, 1, 1);
    }
    if (line.m_nType == 10)
    {
        FUN_14135a4d0()->ExecuteInternal(strText);
        return;
    }
    if (line.m_nType != 4)
    {
        if (FUN_14097a780()->FUN_140ae5240(strName))
            return;
        if (nCharId != 0 && FUN_14097a780()->FUN_140ae51b0(nCharId))
            return;
    }
    FUN_141a25ad0(strText);
    FUN_141a26f10(strName, strText, line.m_nType);
    if (line.m_nType == 0x12)
    {
        FUN_1412751f0(FUN_1408f71a0(CStringW(L"s_guild_chat_mega_phone"), strName, strText), 0xb, 0);
        FUN_141276180(s_strGuildMegaphoneSound, CString(""));
    }
    CStringW strHtml;
    if (line.m_nType == 0x19)
    {
        if (!FUN_140166410()->FUN_14036d570(0x104))
            return;
        Unk_1407a5820 extra;
        FUN_1407a5960(extra, packet);
        strHtml = FUN_141841180(line, extra, strText, DAT_143adda48.m_nFontSize);
    }
    else
    {
        strHtml = FUN_14183f310(line, strText, DAT_143adda48.m_nFontSize);
    }
    FUN_141a26e00(strHtml, FUN_141482f00(line.m_nType));
    FUN_141a271b0(strName, strHtml, FUN_141482f00(line.m_nType));
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a22cd0
void UIMessengerBrowser::vfunc_85(CInPacket& packet)
{
    CInputStream& in = packet;
    unsigned nCount = in.vfunc_o8_3();
    for (unsigned i = 0; i < nCount; i++)
    {
        __int64 nUid = in.vfunc_o8_4();
        int nItemId = in.vfunc_o8_3();
        int nRarity = in.vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->FUN_140526a70(nUid);
            spItem->FUN_140526b30(DAT_143ab2864);
            spItem->FUN_140524eb0(in);
            m_linkedItems.SetAt(nUid, spItem);
        }
    }
}

// @0x141a22ee0
void UIMessengerBrowser::FUN_141a22ee0(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    int nValue = packet.vfunc_o8_3();
    CStringW strValue = FUN_1401aa6a0(nValue);
    CStringW strMessage = FUN_140632a60(0x898, strName, strValue);
    FUN_141a247c0(strMessage, 0x14);
}

// @0x141a22fc0
void UIMessengerBrowser::FUN_141a22fc0(CInPacket& packet)
{
    int nValue = packet.vfunc_o8_3();
    CStringW strValue = FUN_1401aa6a0(nValue);
    CStringW strMessage = FUN_14052bd00(0xaf2, strValue);
    FUN_141a247c0(strMessage, 0x14);
}

// @0x141a23060
void UIMessengerBrowser::FUN_141a23060(CInPacket& packet)
{
    int nMode = packet.vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        FUN_141a230e0(packet);
        break;
    case 1:
        FUN_141a233d0(packet);
        break;
    }
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a230e0
void UIMessengerBrowser::FUN_141a230e0(CInPacket& packet)
{
    CInputStream& in = packet;
    int nPartyId = in.vfunc_o8_3();
    CStringW strLeader = in.vfunc_o8_8();
    __int64 nA = in.vfunc_o8_4();
    __int64 nCharId = in.vfunc_o8_4();
    int nRoomId = in.vfunc_o8_3();
    unsigned bFlag = in.vfunc_o8_1();
    DungeonRoomPtr spRoom = FUN_14031c2a0()->GetRoom(nRoomId);
    if (spRoom == 0)
        return;
    if (FUN_14097a780()->FUN_140ae51b0(nCharId))
        return;
    FUN_1409670d0()->FUN_1416312f0(nPartyId);
    int nFontSize = FUN_141a27de0();
    CStringW strHtml = FUN_141841c60(nPartyId, strLeader, nA, nCharId, nRoomId, spRoom->m_groupType, bFlag,
                                     spRoom->m_maxUserCount, nFontSize);
    FUN_141a26e00(strHtml, 0x1b);
}

// MS2-FUNCTIONAL: temporaries differ from the exe (functional-first)
// @0x141a233d0
void UIMessengerBrowser::FUN_141a233d0(CInPacket& packet)
{
    CInputStream& in = packet;
    unsigned nNeedHelper = in.vfunc_o8_1();
    unsigned nNeedMember = in.vfunc_o8_1();
    unsigned nPartyId = in.vfunc_o8_3();
    CStringW strLeader = in.vfunc_o8_8();
    unsigned __int64 nAccountId = in.vfunc_o8_4();
    unsigned __int64 nCharId = in.vfunc_o8_4();
    unsigned nRoomId = in.vfunc_o8_3();
    int nMembers = in.vfunc_o8_1();
    DungeonRoomPtr spRoom = FUN_14031c2a0()->GetRoom(nRoomId);
    if (spRoom == 0)
        return;
    if (FUN_14097a780()->FUN_140ae51b0(nCharId))
        return;
    FUN_1409670d0()->FUN_1416312f0(nPartyId);
    CStringW strUserEvent = FUN_141842c40(L"'event:userSelect,{0},{1},{2}'", strLeader, nAccountId, nCharId);
    CStringW strUser = FUN_1408f71a0(CStringW(L"s_html_chat_user_dungeon_member"), strUserEvent, strLeader);
    CStringW strJoinEvent = FUN_1418428c0(L"'event:joinPartyDungeonMember,{0},{1},{2}'", nPartyId, strLeader, nRoomId);
    CStringW strJoin = FUN_1405c2690(CStringW(L"s_html_chat_join_party"), strJoinEvent);
    CStringW strRoomEvent = FUN_140292a70(L"'event:dungeonRoom,{0}'", nRoomId);
    CStringW strRoom = FUN_1409eaa20(CStringW(L"s_html_chat_dungeon_name"), strRoomEvent,
                                     FUN_140cbf840(spRoom->m_groupType), FUN_1401a9d70()->FUN_141811980(0x14, nRoomId));
    CStringW strBody = FUN_14028dfa0(CStringW(L"s_html_chat_find_dungeon_member"), strUser, strRoom, nMembers,
                                     spRoom->m_maxUserCount, nNeedMember, nNeedHelper, strJoin);
    unsigned nFontSize = FUN_141a27de0();
    CStringW strHtml = FUN_141843060(CStringW(L"s_html_chat_system_notice"), DAT_1439f880c, nFontSize, strBody);
    FUN_141a26e00(strHtml, 0x1b);
}

// @0x141a239e0
void UIMessengerBrowser::FUN_141a239e0(CStringW strText)
{
    CStringW strHtml = FUN_141841fd0(strText, DAT_143adda48.m_nFontSize);
    FUN_141a26e00(strHtml, 0x19);
}

// @0x141a23a70
void UIMessengerBrowser::FUN_141a23a70()
{
    for (unsigned i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0)
            pWindow->FUN_141a0f7b0();
    }
}

// @0x141a23af0
void UIMessengerBrowser::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_141a26a00();
    m_184 = 0;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a23b30
void UIMessengerBrowser::vfunc_15()
{
    if (m_68 != 0 || m_4c == 0)
        return;
    UISwfEntity::vfunc_15();
    if (!m_pendingLogs.IsEmpty())
    {
        unsigned nShown = m_194;
        unsigned nPending = (unsigned)m_pendingLogs.GetCount();
        if ((unsigned)m_pendingLogs.GetCount() < (unsigned)m_198 && nShown + nPending <= (unsigned)m_190)
            FUN_141a27ca0();
        else
            FUN_141a27bf0();
    }
    FUN_1412976a0()->FUN_141451a60();
}

// @0x141a23c20
void UIMessengerBrowser::FUN_141a23c20()
{
    m_184 = 1;
    m_strWhisperTarget = "";
    m_1a8 = L"";
    m_1b0 = 0;
    m_194 = 0;
    m_logs.RemoveAll();
    m_linkedItems.RemoveAll();
    m_pendingLogs.RemoveAll();
    m_reports.RemoveAll();
    m_history.clear();
    m_itHistory = m_history.end();
    FUN_141482e80()->FUN_141482b70();
}

// @0x141a23d50
int UIMessengerBrowser::FUN_141a23d50()
{
    return m_184;
}

// @0x141a23d70
int UIMessengerBrowser::FUN_141a23d70(const CStringW& strName)
{
    for (unsigned int i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0 && pWindow->FUN_141a0df70() == strName)
            return 1;
    }
    return 0;
}

// @0x141a23e80
void UIMessengerBrowser::FUN_141a23e80()
{
    FUN_141a24490();
    for (unsigned int i = 0; i < 100; i++)
    {
        CString strFile;
        strFile.Format("%s%d.xml", "MessengerDialog", i);
        FUN_1401d3700(strFile);
        CString strDefault;
        strDefault.Format("DefaultMessenger%d.xml", i);
        FUN_1401d3700(strDefault);
        TiXmlDocument doc;
        int bLoaded = FUN_140166420()->FUN_1403974b0(
            &doc, FUN_140cc2a00(FUN_140188f50(FUN_141275750(), 0), strDefault), 0, true, false);
        if (bLoaded)
        {
            UIMessenger* pWindow = new UIMessenger(this, doc, FUN_14016a730(strFile, 0), m_184);
            if (pWindow->vfunc_65())
            {
                pWindow->vfunc_8(1);
                m_windows.Add(pWindow);
            }
        }
    }
}

// @0x141a24160
void UIMessengerBrowser::FUN_141a24160(const ATL::CAtlArray<MS2Ptr<TalkTab> >& tabs, int nX, int nY, int nWidth,
                                       int nHeight, int nTarget)
{
    TiXmlDocument doc;
    if (FUN_14081b310(&doc) == 0)
        FUN_14086e090(&doc, new TiXmlElement("MessengerDialog"));
    void* pRoot = FUN_14081b310(&doc);
    if (pRoot == 0)
        return;
    FUN_140873ca0(pRoot, "width", nWidth);
    FUN_140873ca0(pRoot, "height", nHeight);
    FUN_140873ca0(pRoot, "offsetX", nX);
    FUN_140873ca0(pRoot, "offsetY", nY);
    FUN_140873ca0(pRoot, "alignType", 5);
    FUN_140873ca0(pRoot, "additive", 0);
    FUN_140873ca0(pRoot, "targetSelectedIndex", nTarget);
    for (unsigned i = 0; i < tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = tabs[i];
        if (spTab.get() != 0)
        {
            Unk_MdXml* pTab = ((Unk_MdXml*)pRoot)->FUN_140872ec0("Tab", false);
            if (pTab != 0)
                spTab->FUN_141482880(pTab);
        }
    }
    UIMessenger* pWindow = new UIMessenger(this, doc, FUN_141a26cd0(), 0);
    if (pWindow->vfunc_65())
    {
        pWindow->vfunc_8(1);
        m_windows.Add(pWindow);
    }
}

// @0x141a24490
void UIMessengerBrowser::FUN_141a24490()
{
    for (unsigned int i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0)
        {
            FUN_141482e80()->FUN_141482d30(pWindow->FUN_141a0df70());
            pWindow->vfunc_84();
            FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(pWindow));
        }
    }
    m_windows.RemoveAll();
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a245d0
void UIMessengerBrowser::FUN_141a245d0(const CStringW& strName)
{
    for (unsigned int i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0 && pWindow->FUN_141a0df70() == strName && pWindow->m_tabs.IsEmpty())
        {
            FUN_141482e80()->FUN_141482d30(pWindow->FUN_141a0df70());
            pWindow->vfunc_84();
            m_windows.RemoveAt(i, 1);
            FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(pWindow));
        }
    }
}

// @0x141a247c0
void UIMessengerBrowser::FUN_141a247c0(const CStringW& strText, int nType)
{
    if (strText.IsEmpty())
        return;
    CStringW strLine(strText);
    FUN_1403b4750()->FUN_1416fb340(strLine);
    strLine = FUN_14183f080(strLine, 0, DAT_143adda48.m_nFontSize);
    FUN_141a26e00(strLine, nType);
}

// MS2-FUNCTIONAL: temporaries differ from the exe (functional-first)
// @0x141a24890
void UIMessengerBrowser::FUN_141a24890(CItem* pItem, unsigned nCount, int nManyId, int nOneId)
{
    int nFontSize = DAT_143adda48.m_nFontSize;
    CStringW strText;
    CStringW strItem = FUN_141841b40(pItem, L"inven", nFontSize);
    if (nCount < 2)
    {
        CStringW strFormat(L"");
        if (pItem != 0 && ((CItemData*)pItem->FUN_140527840())->FUN_14053cb80())
            strFormat = FUN_14028de60(699);
        else
            strFormat = FUN_14028de60(nOneId);
        strText = FUN_1401e8510(strFormat, strItem);
    }
    else
    {
        CStringW strFormat(L"");
        if (pItem != 0 && ((CItemData*)pItem->FUN_140527840())->FUN_14053cb80())
            strFormat = FUN_14028de60(700);
        else
            strFormat = FUN_14028de60(nManyId);
        strText = FUN_1402758a0(strFormat, strItem, nCount);
    }
    int nBefore = pItem->FUN_140526c50() - nCount;
    if (FUN_14025e7c0()->FUN_14116d720())
    {
        CStringW strDebug;
        unsigned nNow = pItem->FUN_140526c50();
        strDebug = StringFormat(L"[Count:{0}] [ {1} -> {2} ]", nCount, nBefore, nNow);
        strText.AppendFormat(strDebug);
    }
    FUN_141a247c0(strText, 9);
}

// @0x141a24cb0
void UIMessengerBrowser::FUN_141a24cb0(CItem* pItem, unsigned nCount, int nDelta)
{
    if (!FUN_14025e7c0()->FUN_14116d720())
        return;
    CStringW strItem = FUN_141841b40(pItem, L"inven", DAT_143adda48.m_nFontSize);
    unsigned nBefore = nCount - nDelta;
    if (nBefore > nCount)
    {
        int nUsed = nDelta * -1;
        Unk_MbLog(FUN_140166440(), 2, 0x21, L"{0} Item Use:{1}  [{2}->{3}]", strItem, nUsed, nBefore, nCount);
    }
    else if (nBefore < nCount)
    {
        Unk_MbLog(FUN_140166440(), 2, 0x21, L"{0} [Count:{1}] Item Add:{1} [{2}->{3}]", strItem, nDelta, nBefore,
                  nCount);
    }
}

// @0x141a24e10
void UIMessengerBrowser::FUN_141a24e10(CItem* pItem)
{
    if (!FUN_14025e7c0()->FUN_14116d720())
        return;
    CStringW strItem = FUN_141841b40(pItem, L"inven", DAT_143adda48.m_nFontSize);
    unsigned nCount = pItem->FUN_140526c50();
    Unk_MbLog(FUN_140166440(), 2, 0x21, L"{0} [Count:{1}] Item Removed", strItem, nCount);
}

// @0x141a24ee0
void UIMessengerBrowser::FUN_141a24ee0(CItem* pItem)
{
    if (!FUN_14025e7c0()->FUN_14116d720())
        return;
    CStringW strItem = FUN_141841b40(pItem, L"inven", DAT_143adda48.m_nFontSize);
    unsigned nCount = pItem->FUN_140526c50();
    Unk_MbLog(FUN_140166440(), 2, 0x21, L"{0} [Count:{1}] Item Added", strItem, nCount);
}

// @0x141a24fb0
void UIMessengerBrowser::FUN_141a24fb0(CStringW strText)
{
    for (unsigned int i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0 && FUN_141482e80()->FUN_1414829e0() == pWindow->FUN_141a0df70())
            pWindow->FUN_141a0ec30(strText);
    }
}

// @0x141a25130
void UIMessengerBrowser::FUN_141a25130(unsigned nFontSize)
{
    FUN_141a27ad0(nFontSize);
    FUN_141a27bf0();
}

// @0x141a25160
void UIMessengerBrowser::FUN_141a25160(unsigned nAlpha)
{
    for (unsigned i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0)
            pWindow->FUN_141a0ebb0(nAlpha);
    }
}

// @0x141a251f0
void UIMessengerBrowser::FUN_141a251f0(int n)
{
    m_180 = n;
}

// @0x141a25210
void UIMessengerBrowser::FUN_141a25210(int bActive)
{
    for (unsigned i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0)
            pWindow->vfunc_85(bActive);
    }
}

// @0x141a252a0
void UIMessengerBrowser::FUN_141a252a0(const CStringW& strTarget)
{
    for (unsigned int i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0 && FUN_141482e80()->FUN_141482a50() == pWindow->FUN_141a0df70())
            pWindow->FUN_141a14bb0(strTarget);
    }
}

// @0x141a25410
int UIMessengerBrowser::FUN_141a25410(TalkTab* pExcept, const CStringW& strName)
{
    for (unsigned i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0 && pWindow->vfunc_86(pExcept, strName) == 0)
            return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// The timed log's rbegin (a COMDAT of this unit's range).
// MS2-PIN: ?rbegin@?$_Tree@V?$_Tmap_traits@_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@4@$00@std@@@std@@QEAA?AV?$reverse_iterator@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@@2@XZ 0x141a30d70

// @0x141a254c0
void UIMessengerBrowser::FUN_141a254c0(__int64 nSince, CStringW& strOut)
{
    std::multimap<__int64, CStringW>::reverse_iterator itStop(m_timedLogs.lower_bound(nSince));
    for (std::multimap<__int64, CStringW>::const_reverse_iterator it = m_timedLogs.rbegin(); it != itStop; ++it)
    {
        CMsTime time(it->first);
        int nHour = time.GetHour();
        int nMinute = time.GetMinute();
        int nSecond = time.GetSecond();
        CStringW strLine(it->second);
        FUN_14083d2b0(strLine);
        int nLength = strOut.GetLength();
        if (nLength + strLine.GetLength() > 2000)
            break;
        strOut.AppendFormat(L"[%2d:%2d:%2d] %s\n", nHour, nMinute, nSecond, (const wchar_t*)strLine);
    }
}

// @0x141a25660
void UIMessengerBrowser::FUN_141a25660(CStringW strText, CStringW strTarget)
{
    if (m_windows.IsEmpty())
        return;
    m_windows[0]->FUN_141a0f1d0(strText, strTarget, true);
}

// @0x141a25770
void UIMessengerBrowser::FUN_141a25770(CStringW strText, bool bHistory)
{
    if (m_windows.IsEmpty())
        return;
    m_windows[0]->FUN_141a0f430(strText, bHistory);
}

// @0x141a25840
int UIMessengerBrowser::FUN_141a25840(const CStringW& strText)
{
    if (m_188 == 0)
        return 0;
    if (strText.IsEmpty())
        return 0;
    if (strText[0] == L'/')
        return 0;
    return 1;
}

// @0x141a258a0
CStringW UIMessengerBrowser::FUN_141a258a0()
{
    for (unsigned i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0)
            return pWindow->FUN_141a0df70();
    }
    return L"";
}

// @0x141a25970
UIMessenger* UIMessengerBrowser::FUN_141a25970()
{
    if (!m_windows.IsEmpty())
        return m_windows[0];
    return 0;
}

// @0x141a259c0
UIMessenger* UIMessengerBrowser::FUN_141a259c0(const CStringW& strName)
{
    for (unsigned int i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0 && pWindow->FUN_141a0df70() == strName)
            return pWindow;
    }
    return 0;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a25ad0
void UIMessengerBrowser::FUN_141a25ad0(CStringW& strHtml)
{
    ATL::CAtlList<CStringW> links;
    if (!FUN_140d2c080(strHtml, links, CStringW(L"<A HREF="), CStringW(L"/A>")))
        return;
    POSITION pos = links.GetHeadPosition();
    while (pos != 0)
    {
        CStringW strLink(links.GetAt(pos));
        unsigned __int64 nUid = FUN_140d2caf0(strLink);
        int nColor = 0xffffff;
        {
            MS2Ptr<CItem> spItem = FUN_141a263d0(nUid);
            if (spItem.get() != 0)
            {
                int nGrade = spItem->FUN_140526bd0();
                nColor = FUN_140281980()->FUN_1405569f0(nGrade);
            }
        }
        strHtml.Replace(strLink, FUN_14183e930(strLink, nColor));
        links.GetNext(pos);
    }
}

// @0x141a25d40
void UIMessengerBrowser::vfunc_2(void* pItem)
{
    FUN_141a24ee0((CItem*)pItem);
}

// @0x141a25d80
void UIMessengerBrowser::vfunc_3(void* pItem, bool bMoved)
{
    if (bMoved != true)
        FUN_141a24e10((CItem*)pItem);
}

// @0x141a25dc0
void UIMessengerBrowser::vfunc_4(void* pItem, int nOld)
{
    FUN_141275150((CItem*)pItem, ((CItem*)pItem)->FUN_140526c50(), nOld, 0x2ba, 0x2b9);
}

// @0x141a25e10
void UIMessengerBrowser::vfunc_5(void* pItem, int nSlot)
{
    if (((CItem*)pItem)->FUN_140526010() != 0)
        return;
    FUN_1412750f0((CItem*)pItem, nSlot, 0x2ba, 0x2b9);
}

// @0x141a25e60
void UIMessengerBrowser::vfunc_17(void* pItem, int nSlot)
{
    FUN_1412750f0((CItem*)pItem, nSlot, 0x2ba, 0x2b9);
}

// @0x141a25ea0
Unk_MsgHistory::Unk_MsgHistory(const Unk_MsgHistory& other)
{
    m_strText = other.m_strText;
    m_keys.Copy(other.m_keys);
}

// @0x141a25f20
Unk_MsgHistory& Unk_MsgHistory::operator=(const Unk_MsgHistory& other)
{
    m_strText = other.m_strText;
    m_keys.Copy(other.m_keys);
    return *this;
}

// @0x141a25f70
void UIMessengerBrowser::FUN_141a25f70(const CStringW& strText, ATL::CAtlArray<CStringW>& history)
{
    if (strText.IsEmpty())
        return;
    if (!m_history.empty() && m_history.rbegin()->m_strText == strText)
    {
        m_itHistory = m_history.end();
        return;
    }
    const int nMax = 10;
    Unk_MsgHistory entry;
    entry.m_strText = strText;
    entry.m_keys.Copy(history);
    m_history.push_back(entry);
    if (m_history.size() > nMax)
        m_history.pop_front();
    m_itHistory = m_history.end();
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a261b0
int UIMessengerBrowser::FUN_141a261b0(int bUp, Unk_MsgHistory& entry)
{
    if (m_history.empty())
        return 0;
    if (bUp == 0)
    {
        if (m_itHistory == m_history.end())
            return 0;
        m_itHistory++;
    }
    else
    {
        if (m_itHistory == m_history.begin())
            return 0;
        m_itHistory--;
    }
    if (m_itHistory != m_history.end())
        entry = *m_itHistory;
    return 1;
}

// @0x141a263d0
MS2Ptr<CItem> UIMessengerBrowser::FUN_141a263d0(unsigned __int64 nUid)
{
    MS2Ptr<CItem> spItem;
    if (m_linkedItems.Lookup(nUid, spItem))
        return spItem;
    return MS2Ptr<CItem>(0);
}

// @0x141a26480
bool UIMessengerBrowser::FUN_141a26480()
{
    if (m_hiddenTypes.size() != 0)
        return true;
    return false;
}

// @0x141a264c0
bool UIMessengerBrowser::FUN_141a264c0(int nType)
{
    if (nType == 0x10 && !FUN_140166410()->FUN_14036d570(0x19))
        return true;
    if (m_hiddenTypes.find(nType) != m_hiddenTypes.end())
        return true;
    return false;
}

// @0x141a26560
void UIMessengerBrowser::FUN_141a26560(int nType)
{
    m_hiddenTypes.insert(nType);
}

// @0x141a265a0
void UIMessengerBrowser::FUN_141a265a0(int nType)
{
    m_hiddenTypes.erase(nType);
}

// @0x141a265d0
void UIMessengerBrowser::FUN_141a265d0()
{
    m_hiddenTypes.clear();
}

// @0x141a26600
void UIMessengerBrowser::FUN_141a26600()
{
    for (unsigned i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0)
            pWindow->FUN_141a0f870();
    }
}

// MS2-FUNCTIONAL: exe statically links _mkdir/fopen/fwrite/fclose, build imports them
// @0x141a26680
void UIMessengerBrowser::FUN_141a26680()
{
    CString strDir;
    strDir.Format("%s%s", (const char*)FUN_14016a5c0(FUN_1401d31f0()->m_strRoot, 0), "../Debug/");
    if (!thunk_FUN_1420b1ae0(strDir))
        _mkdir(strDir);
    __time64_t nNow;
    _time64(&nNow);
    CMsTime time(nNow);
    int nSecond = time.GetSecond();
    int nMinute = time.GetMinute();
    int nHour = time.GetHour();
    int nDay = time.GetDay();
    int nMonth = time.GetMonth();
    int nYear = time.GetYear();
    CString strFile = Unk_SocketFormat("ChatLog{0:04d}{1:02d}{2:02d}_{3:02d}{4:02d}{5:02d}.txt", nYear, nMonth, nDay,
                                       nHour, nMinute, nSecond);
    CString strPath = FUN_140cc2a00(CString("../Debug/"), strFile);
    FILE* pFile = fopen(strPath, "w");
    if (pFile != 0)
    {
        POSITION pos = m_reports.GetHeadPosition();
        while (pos != 0)
        {
            ReportLog& report = m_reports.GetNext(pos);
            CStringW strLine;
            strLine.Format(L"user=[%s] chat=[%s]", (const wchar_t*)report.m_strName, (const wchar_t*)report.m_strMsg);
            CString strBytes = FUN_14016a600(strLine, 0);
            size_t nLength = strBytes.GetLength();
            fwrite((const char*)strBytes, nLength, 1, pFile);
            fwrite("\n", 1, 1, pFile);
        }
        fclose(pFile);
    }
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a26a00
void UIMessengerBrowser::FUN_141a26a00()
{
    if (FUN_141a27570())
    {
        for (unsigned int i = 0; i < 100; i++)
        {
            CString strFile;
            strFile.Format("%s%d.xml", "MessengerDialog", i);
            FUN_1401d3700(strFile);
            TiXmlDocument doc;
            int bLoaded = FUN_140166420()->FUN_1403974b0(
                &doc, FUN_140cc2a00(FUN_140188f50(FUN_1412755f0(), 0), strFile), 0, false, false);
            if (bLoaded)
            {
                UIMessenger* pWindow = new UIMessenger(this, doc, FUN_14016a730(strFile, 0), m_184);
                if (pWindow->vfunc_65())
                {
                    pWindow->vfunc_8(1);
                    m_windows.Add(pWindow);
                }
            }
        }
    }
    if (m_windows.IsEmpty())
        FUN_141a23e80();
}

// @0x141a26cd0
CStringW UIMessengerBrowser::FUN_141a26cd0()
{
    for (unsigned int i = 0; i < 100; i++)
    {
        CStringW strName;
        strName.Format(L"%s%d.xml", (const wchar_t*)FUN_14016a730("MessengerDialog", 0), i);
        FUN_140841420(strName);
        if (FUN_141a23d70(strName))
            continue;
        return strName;
    }
    return L"";
}

// @0x141a26e00
int UIMessengerBrowser::FUN_141a26e00(const CStringW& strHtml, int nKind)
{
    TalkLog log(strHtml, nKind);
    m_logs.AddTail(log);
    m_pendingLogs.AddTail(log);
    if (m_logs.GetCount() > (unsigned)m_18c)
        m_logs.RemoveHead();
    return 1;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a26f10
int UIMessengerBrowser::FUN_141a26f10(const CStringW& strName, const CStringW& strText, int nType)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return 0;
    PCBase* pSpeaker = FUN_1403ed2d0()->FUN_141bd1420(strName);
    if (pSpeaker == 0)
        return 0;
    if (pSpeaker == pMe && FUN_140967100()->FUN_141b21220())
        return 1;
    int bShow = FUN_1409a8b10()->FUN_140b123b0()->FUN_14125c820(nType);
    CStringW strBalloon;
    if (nType == 7 && bShow)
        strBalloon = FUN_14028de60(0xaa7);
    else if (nType == 8 && bShow)
        strBalloon = FUN_14028de60(0xaa8);
    strBalloon += strText;
    float fDistance = pSpeaker->FUN_140f4a450();
    if (!bShow)
        return 0;
    int bNear = (pSpeaker == pMe || fDistance < *FUN_1401d3200()->ChatBalloonDistance.Get()) ? 1 : 0;
    if (bNear)
        pSpeaker->FUN_14166fff0(strBalloon);
    return 1;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// MS2-FUNCTIONAL 0x141a1b9b0: std::list<MS2Ptr<ChatEmoticonData>> _List_alloc dtor; same two calls (_Myhead, _Freeheadnode) as the exe, bound to byte-identical helper copies at other VAs

// @0x141a271b0
int UIMessengerBrowser::FUN_141a271b0(const CStringW& strName, const CStringW& strText, int nType)
{
    CStringW strTag;
    if (nType == 1)
        strTag = L"[Normal]";
    else if (nType == 2)
        strTag = L"[Party]";
    else if (nType == 3)
        strTag = L"[Guild]";
    else if (nType == 0x18)
        strTag = L"[GuildMegaphone]";
    else if (nType == 4)
        strTag = L"[Whisper]";
    else if (nType == 0x15)
        strTag = L"[World]";
    else if (nType == 0x16)
        strTag = L"[Channel]";
    else if (nType == 0x17)
        strTag = L"[Super]";
    else if (nType == 0x1a)
        strTag = L"[Club]";
    else
        return 0;
    if (m_timedLogs.size() > 0x32)
        m_timedLogs.erase(m_timedLogs.begin());
    CStringW strLine;
    strLine.Format(L"%s[%s] %s", (const wchar_t*)strTag, (const wchar_t*)strName, (const wchar_t*)strText);
    __int64 nNow = FUN_140869440();
    m_timedLogs.insert(std::make_pair(nNow, strLine));
    ReportLog report(strName, strText);
    m_reports.AddTail(report);
    if (m_reports.GetCount() > (unsigned)m_18c)
        m_reports.RemoveHead();
    return 1;
}

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a27570
int UIMessengerBrowser::FUN_141a27570()
{
    bool bValid = true;
    int bAny = 0;
    ATL::CAtlList<CStringW> names;
    for (int i = 0; i < 100 && bValid; i++)
    {
        CString strFile;
        strFile.Format("%s%d.xml", "MessengerDialog", i);
        FUN_1401d3700(strFile);
        TiXmlDocument doc;
        int bLoaded = FUN_140166420()->FUN_1403974b0(
            &doc, FUN_140cc2a00(FUN_140188f50(FUN_1412755f0(), 0), strFile), 0, false, false);
        if (!bLoaded)
            continue;
        void* pDialog = FUN_140165cf0(&doc, "MessengerDialog");
        if (pDialog == 0)
        {
            bValid = false;
            break;
        }
        void* pTabXml = FUN_140165cf0(pDialog, "Tab");
        if (pTabXml == 0)
        {
            bValid = false;
            break;
        }
        for (; pTabXml != 0; pTabXml = FUN_140168650(pTabXml, "Tab"))
        {
            MS2Ptr<TalkTab> spTab(new TalkTab);
            if (spTab.get() == 0 || !spTab->FUN_1414827c0((Unk_MdXml*)pTabXml))
            {
                bValid = false;
                break;
            }
            if (spTab->m_nAdditive != 0)
                bAny = 1;
            if (names.Find(spTab->m_strName) != 0)
            {
                bValid = false;
                break;
            }
            names.AddTail(spTab->m_strName);
        }
    }
    if (bValid)
        return bAny;
    for (int i = 0; i < 100; i++)
    {
        CString strFile;
        strFile.Format("%s%d.xml", "MessengerDialog", i);
        FUN_1401d3700(strFile);
        DeleteFileA(FUN_140cc2a00(FUN_1412755f0(), FUN_14016a5c0(strFile, 0)));
    }
    return 0;
}

// @0x141a27ad0
void UIMessengerBrowser::FUN_141a27ad0(unsigned nFontSize)
{
    POSITION pos = m_logs.GetHeadPosition();
    while (pos != 0)
    {
        TalkLog& log = m_logs.GetNext(pos);
        for (unsigned n = 0xc; (int)n <= 0x12; n++)
        {
            CStringW strOld;
            strOld.Format(L"size='%d'", n);
            CStringW strNew;
            strNew.Format(L"size='%d'", nFontSize);
            log.m_strMsg.Replace(strOld, strNew);
        }
    }
}

// @0x141a27bf0
void UIMessengerBrowser::FUN_141a27bf0()
{
    for (unsigned i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0)
            pWindow->FUN_141a0e990();
    }
    m_194 = (int)m_logs.GetCount();
    m_pendingLogs.RemoveAll();
}

// @0x141a27ca0
void UIMessengerBrowser::FUN_141a27ca0()
{
    for (unsigned i = 0; i < m_windows.GetCount(); i++)
    {
        UIMessenger* pWindow = m_windows[i];
        if (pWindow != 0)
        {
            POSITION pos = m_pendingLogs.GetHeadPosition();
            while (pos != 0)
            {
                TalkLog& log = m_pendingLogs.GetNext(pos);
                pWindow->vfunc_88(log.m_strMsg, log.m_nKind);
            }
        }
    }
    m_194 = (unsigned)m_194 + m_pendingLogs.GetCount();
    m_pendingLogs.RemoveAll();
}

// @0x141a27de0
int UIMessengerBrowser::FUN_141a27de0()
{
    return DAT_143adda48.m_nFontSize;
}

// @0x141a1caf0
int UIMessenger::vfunc_48()
{
    return 0x4e60;
}

// @0x141a2cf30
int UIMessengerBrowser::vfunc_48()
{
    return 0x4e61;
}

int FUN_1418fc760(const char* szMethod, void* pArgs, unsigned int nArgs, UIMessenger* pDialog);   // uicommon.cpp: the shared AS events

// MS2-FUNCTIONAL: codegen differs from the exe (functional-first)
// @0x141a0bfd0
int UIMessenger::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, nArgs, this))
        return 1;
    if (_stricmp("eventFocusIn", szMethod) == 0)
    {
        vfunc_90();
        return 1;
    }
    if (_stricmp("eventFocusOut", szMethod) == 0)
    {
        vfunc_91();
        return 1;
    }
    if (_stricmp("eventChangeText", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            vfunc_94(data.FUN_1422b8f40());
        return 1;
    }
    if (_stricmp("eventWhisperTarget", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            vfunc_95(data.FUN_1422b8f40());
        return 1;
    }
    if (_stricmp("eventAdditiveTab", szMethod) == 0)
    {
        vfunc_92();
        return 1;
    }
    if (_stricmp("eventChangeTalkTarget", szMethod) == 0)
    {
        vfunc_93();
        return 1;
    }
    if (_stricmp("eventPressSubjectTab", szMethod) == 0)
    {
        FUN_141a15890();
        if (!m_pBrowser->FUN_141a264c0(0x10) && FUN_141a144a0() == 0x10)
            FUN_1403ed2b0()->FUN_141adc530(0x4f58);
        return 1;
    }
    if (_stricmp("eventShowWhisperList", szMethod) == 0)
    {
        FUN_141a131f0();
        return 1;
    }
    if (_stricmp("eventHideWhisperList", szMethod) == 0)
    {
        FUN_141a13200();
        return 1;
    }
    if (_stricmp("eventTabMenu", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            vfunc_96(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("eventChangeTab", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            vfunc_97(data.FUN_1422b8f40());
        return 1;
    }
    if (_stricmp("eventAttachTab", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            CString strWindow = data.FUN_1422b8d30();
            vfunc_98(strName, strWindow);
        }
        return 1;
    }
    if (_stricmp("eventDetachTab", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            float fX = data.FUN_1422b8c10();
            float fY = data.FUN_1422b8c10();
            float fWidth = data.FUN_1422b8c10();
            float fHeight = data.FUN_1422b8c10();
            int nTarget = data.FUN_1422b8a10();
            FUN_141a16730(strName, (int)fX, (int)fY, (int)fWidth, (int)fHeight, nTarget);
        }
        return 1;
    }
    if (_stricmp("eventTextInput", szMethod) == 0)
    {
        FUN_140d2c2a0(m_textInput, m_inputHistory);
        return 1;
    }
    if (_stricmp("updateAlignTypeAndOffset", szMethod) == 0)
    {
        FUN_141a0f180();
        return 1;
    }
    if (_stricmp("eventEmotion", szMethod) == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4e7a);
    }
    else if (_stricmp("eventChatEmoticonOpen", szMethod) == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4f80);
    }
    else if (_stricmp("eventChatEmoticonPush", szMethod) == 0)
    {
        ASData data;
        if (!data.FUN_1422b9620(pArgs, nArgs))
            return 0;
        FUN_141a0fe20(data.FUN_1422b8a10());
    }
    else if (_stricmp("eventChatEmoticonFavorite", szMethod) == 0)
    {
        ASData data;
        if (!data.FUN_1422b9620(pArgs, nArgs))
            return 0;
        int nEmoticonId = data.FUN_1422b8a10();
        bool bFavorite = data.FUN_1422b8a90();
        FUN_141a10490(nEmoticonId, bFavorite);
    }
    return 0;
}

// @0x141a0c9f0
int UIMessenger::vfunc_46()
{
    if (!UISwfEntity::vfunc_46())
        return 0;
    if (m_subject.get() != 0)
    {
        CStringW strTooltip = FUN_14135a4d0()->Tooltip();
        m_subject->FUN_1422c7b40(strTooltip);
    }
    return 1;
}

// The validateNow slot of the popup components (ASUIComponent slot 24; asbuttonbar.h's layout).
class Unk_MsgPopup : public ASUIComponent
{
public:
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);                           // 24 0x1422c80c0 validateNow
};
int FUN_1418fccc0(int nMsg, void* p2, void* p3, CStringW* pStr);    // the key edits the text
CStringW FUN_1413fa9b0(const CStringW& str);                        // lower case copy
UIMessengerBrowser* FUN_140a3ab70(int nUiId);                       // Unk_GetUI<UIMessengerBrowser>

// MS2-FUNCTIONAL: the slash command popup; temporaries differ from the exe (functional-first)
// @0x141a0cab0
int UIMessenger::vfunc_74(int a1, void* p2, void* p3)
{
    if ((a1 != 0x10f && a1 != 0x102) || m_textInput == 0)
        return 0;
    if (!m_textInput->FUN_1422c76c0())
        return 0;
    CStringW strText = m_textInput->FUN_1422e0b00();
    if (!FUN_1418fccc0(a1, p2, p3, &strText))
        return 0;
    m_strLastWhisper.Empty();
    strText.Trim();
    if (strText.Find(L"/", 0) != 0)
    {
        FUN_141a0d880(false);
        return 0;
    }
    if (m_2e0 == 0)
    {
        m_2e0 = new ASUIComponent(CString("export_input_textarea_for_scroll"), 2);
        if (m_2e0 != 0)
        {
            int nHeight = 300;
            static_cast<ASObj*>((AScript*)(ASUIComponent*)m_2e0)->FUN_1407cbbe0("editable", false);
            int nWidth = m_textInput->FUN_1422c1340() + 0x1e;
            m_2e0->FUN_1422c79e0(nWidth, nHeight);
            float fY = m_textInput->FUN_1422c1110();
            float fTop = fY - (float)((ASDialog*)(ASUIComponent*)m_2e0)->FUN_1422c13b0();
            float fX = m_textInput->FUN_1422c10a0();
            m_2e0->FUN_1422c00f0(fX, fTop);
            ((Unk_MsgPopup*)(ASUIComponent*)m_2e0)->vfunc_24(false);
            m_90->FUN_1422c6900(Scaleform::GFx::Value(m_2e0->FUN_1422bb870()));
            m_2f0 = new ASUIComponent(CString("export_scroll"), 2);
            if (m_2f0 != 0)
            {
                m_90->FUN_1422c6900(Scaleform::GFx::Value(m_2f0->FUN_1422bb870()));
                static_cast<ASObj*>((AScript*)(ASUIComponent*)m_2f0)->FUN_1409adbe0("scrollBar", Scaleform::GFx::Value(m_2f0->FUN_1422bb870()));
                float fAreaY = m_2e0->FUN_1422c1110();
                float fAreaX = m_2e0->FUN_1422c10a0();
                float fScrollX = fAreaX + (float)m_textInput->FUN_1422c1340() + 4.0f;
                m_2f0->FUN_1422c00f0(fScrollX, fAreaY);
                m_2f0->FUN_1422c79e0(0x18, nHeight);
                ((Unk_MsgPopup*)(ASUIComponent*)m_2f0)->vfunc_24(false);
                static_cast<ASObj*>((AScript*)(ASUIComponent*)m_2f0)->FUN_1409adbe0("scrollTarget", m_2e0->FUN_1422c6b00(CString("textField")));
            }
        }
    }
    if (m_2e0 == 0)
        return 0;
    strText.TrimLeft(L"/ ");
    strText.MakeLower();
    CStringW strLower = FUN_1413fa9b0(strText);
    CStringW strCommand;
    ATL::CAtlArray<CStringW> words;
    FUN_14025a680(strLower, words, L" ");
    if (!strLower.IsEmpty())
        strCommand = words.GetAt(0);
    MS2Ptr<UIMessengerBrowser> spBrowser(FUN_140a3ab70(0x4e61));
    if (spBrowser != 0 && strLower.GetLength() > 0)
    {
        std::set<MS2Ptr<TDebugCommand> > shown;
        CStringW strHtml;
        bool bFirst = false;
        for (size_t i = 0; i < s_debugCommands.size(); i++)
        {
            CStringW strKey = FUN_1413fa9b0(s_debugCommands[i].first);
            if (!strKey.IsEmpty() && strKey.Find(strCommand, 0) != -1)
            {
                MS2Ptr<TDebugCommand> spCmd(s_debugCommands[i].second);
                CStringW strLine;
                if (spCmd.get() != 0 && shown.find(spCmd) == shown.end())
                {
                    if (!bFirst)
                    {
                        m_strLastWhisper = spCmd->m_strName;
                        bFirst = true;
                    }
                    strLine = FUN_1401e8510(L"<font color='#FFD200'>{0}</font> ", spCmd->m_strName);
                    strLine += spCmd->m_strArg;
                    strLine += L"\n";
                    strLine += spCmd->m_strDesc;
                    if (!spCmd->m_strEx.IsEmpty())
                    {
                        strLine += L"\n";
                        strLine += spCmd->m_strEx;
                    }
                    strLine += L"\n\n";
                    shown.insert(spCmd);
                }
                strHtml += strLine;
            }
        }
        static_cast<ASObj*>((AScript*)(ASUIComponent*)m_2e0)->FUN_1407cbb20("htmlText", CStringW(strHtml));
        bool bShow = !strHtml.IsEmpty();
        FUN_141a0d880(bShow);
        if (bShow)
            ((Unk_MsgPopup*)(ASUIComponent*)m_2e0)->vfunc_24(false);
    }
    return 0;
}

CGuildManager* FUN_1403ed290();
CClubClientManager* FUN_140e0d900(); template <> void MS2Ptr<CClubCli>::AddRef() const; template <> void MS2Ptr<CClubCli>::Release(); // clubcli.cpp (CPtred at +0xd8)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                       // the item table record
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);        // str equals psz
void FUN_141bca010(Unk_MsgWorld* pWorld);                           // the chat sent: resets the idle state

// MS2-FUNCTIONAL: the per-channel blocks are folded; temporaries differ from the exe (functional-first)
// @0x141a10660
void UIMessenger::FUN_141a10660(int nType, CStringW strText, CStringW strTarget, __int64 nClubId)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    int nChannel = FUN_141482f00(nType);
    Unk_MbChecker* pChecker = FUN_14025e7d0()->FUN_140229a50().get();
    if (pChecker != 0)
    {
        pChecker->FUN_140226980(strText);
        pChecker->FUN_140226b10(strText);
    }
    switch (nChannel)
    {
    case 1:
    {
        Unk_CommandChat chat;
        chat.kind = nType;
        chat.message = strText;
        chat.target = strTarget;
        FUN_141276f80(chat);
        m_pBrowser->m_1b0 = nChannel;
        break;
    }
    case 2:
        if (!strText.IsEmpty())
        {
            if (!pMe->FUN_141527280())
            {
                FUN_141275260(0x335, 1, 1);
            }
            else
            {
                Unk_CommandChat chat;
                chat.kind = 7;
                chat.message = strText;
                chat.target = strTarget;
                FUN_141276f80(chat);
                m_pBrowser->m_1b0 = nChannel;
            }
        }
        break;
    case 3:
        if (!strText.IsEmpty())
        {
            if (FUN_1403ed290()->FUN_1413b6160() == 0)
            {
                FUN_141275260(0x388, 1, 1);
            }
            else
            {
                Unk_CommandChat chat;
                chat.kind = 8;
                chat.message = strText;
                chat.target = strTarget;
                FUN_141276f80(chat);
                m_pBrowser->m_1b0 = nChannel;
            }
        }
        break;
    case 4:
        if (!strText.IsEmpty())
        {
            Unk_CommandChat chat;
            chat.kind = 4;
            chat.message = strText;
            chat.target = strTarget;
            FUN_141276f80(chat);
            m_pBrowser->m_strWhisperTarget = strTarget;
            m_pBrowser->m_1b0 = nChannel;
        }
        break;
    case 0x15:
        if (!strText.IsEmpty())
        {
            Unk_CommandChat chat;
            chat.kind = nType;
            chat.message = strText;
            chat.target = strTarget;
            FUN_141276f80(chat);
            m_pBrowser->m_1b0 = nChannel;
        }
        break;
    case 0x16:
        if (!strText.IsEmpty())
        {
            Unk_CommandChat chat;
            chat.kind = nType;
            chat.message = strText;
            chat.target = strTarget;
            FUN_141276f80(chat);
            m_pBrowser->m_1b0 = nChannel;
        }
        break;
    case 0x17:
        if (!strText.IsEmpty())
        {
            MS2Ptr<CItemData> spData = FUN_14053f870(pMe->FUN_1416639e0());
            int nSendType = nType;
            if (FUN_140166410()->FUN_14036d570(0x104) && spData.get() != 0
                && FUN_1403b3c40(spData->function.name, L"WeddingChat"))
                nSendType = 0x19;
            Unk_CommandChat chat;
            chat.kind = nSendType;
            chat.message = strText;
            chat.target = strTarget;
            FUN_141276f80(chat);
            m_pBrowser->m_1b0 = nChannel;
        }
        break;
    case 0x18:
        if (!strText.IsEmpty())
        {
            if (FUN_1403ed290()->FUN_1413b6160() == 0)
            {
                FUN_141275260(0x388, 1, 1);
            }
            else if (!FUN_1403ed290()->FUN_1404d0600(pMe->vfunc_77(), 0x800))
            {
                FUN_141275260(0x415, 1, 1);
            }
            else
            {
                Unk_CommandChat chat;
                chat.kind = 0x12;
                chat.message = strText;
                chat.target = strTarget;
                FUN_141276f80(chat);
                m_pBrowser->m_1b0 = nChannel;
            }
        }
        break;
    case 0x1a:
        if (!strText.IsEmpty() && nClubId != 0)
        {
            MS2Ptr<CClubCli> spClub = FUN_140e0d900()->FUN_140b14d80(nClubId);
            if (spClub.get() == 0)
            {
                FUN_141275260(0x36b, 1, 1);
            }
            else
            {
                Unk_CommandChat chat;
                chat.kind = 0x14;
                chat.message = strText;
                chat.target = strTarget;
                chat.value = nClubId;
                FUN_141276f80(chat);
                m_pBrowser->m_1a8 = spClub->FUN_14020f1a0();
                m_pBrowser->m_1b0 = nChannel;
            }
        }
        break;
    }
    FUN_141bca010(FUN_1403ed2d0());
}

// MS2-FUNCTIONAL: temporaries differ from the exe (functional-first)
// @0x141a10fd0
int UIMessenger::FUN_141a10fd0(CStringW strText, CStringW strHtml, bool bLinks)
{
    if (FUN_141a148b0(strText))
        return 1;
    if (FUN_14135a4d0()->Execute(CStringW(strText)))
        return 1;
    int nPos = 0;
    CStringW strCommand = strText.Tokenize(L" ", nPos);
    int nType = 0x1b;
    if (FUN_141a11c60(strCommand, CStringW(strText), &nType))
        return 1;
    CStringW strMsg;
    CStringW strTarget;
    __int64 nClubId = 0;
    switch (nType)
    {
    case 0:
    case 7:
    case 8:
    case 9:
    case 0xb:
    case 0xc:
    case 0x10:
    case 0x12:
        FUN_141a146d0(nType);
        if (!m_pBrowser->FUN_141a264c0(0x10) && FUN_141a144a0() == 0x10)
            FUN_1403ed2b0()->FUN_141adc530(0x4f58);
        return 1;
    case 4:
        strTarget = strText.Tokenize(L" ", nPos);
        strTarget.Trim(L"\"");
        strMsg = strText.Mid(nPos);
        strMsg = strMsg.Trim();
        if (strMsg.IsEmpty())
            return 0;
        if (strTarget.IsEmpty())
        {
            FUN_1412751f0(FUN_14028de60(0x4e), 1, 1);
            return 0;
        }
        if (bLinks)
        {
            strMsg = strHtml;
#ifdef __clang__
            // clang emits an unavailable MFC CopyChars import for CString's operator+; bind the exe's copy.
            CStringW strPart = FUN_14061ad70(FUN_1401d0080(FUN_14061ad70(strCommand, L" "), strTarget), L" ");
#else
            CStringW strPart = strCommand + L" " + strTarget + L" ";
#endif
            if (!FUN_141a14c40(strMsg, strPart))
                return 0;
        }
        if (strMsg.IsEmpty() || strTarget.IsEmpty())
            return 0;
        break;
    case 0x14:
    {
        CStringW strClub = strText.Tokenize(L" ", nPos);
        strClub.Trim(L"\"");
        strMsg = strText.Mid(nPos);
        strMsg = strMsg.Trim();
        if (strMsg.IsEmpty())
            return 0;
        nClubId = FUN_140e0d900()->FUN_140b14fc0(CStringW(strClub));
        if (nClubId == 0)
        {
            FUN_1412751f0(FUN_14028de60(0x50), 1, 1);
            return 0;
        }
        if (bLinks)
        {
            strMsg = strHtml;
#ifdef __clang__
            // clang emits an unavailable MFC CopyChars import for CString's operator+; bind the exe's copy.
            CStringW strPart = FUN_14061ad70(FUN_1401d0080(FUN_14061ad70(strCommand, L" "), strClub), L" ");
#else
            CStringW strPart = strCommand + L" " + strClub + L" ";
#endif
            if (!FUN_141a14c40(strMsg, strPart))
                return 0;
        }
        if (strMsg.IsEmpty())
            return 0;
        break;
    }
    }
    FUN_141a10660(nType, CStringW(strMsg), CStringW(strTarget), nClubId);
    return 1;
}

MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);   // a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                      // shows a message box
int FUN_1403bb830();                                                // the world chat price
int FUN_1403bb850();                                                // the channel chat price

// MS2-FUNCTIONAL: temporaries differ from the exe (functional-first)
// @0x141a12380
bool UIMessenger::FUN_141a12380(int nType, CStringW strText)
{
    if (nType == 0x10 && MSG_COMMUNITY_FLAGS(FUN_1409a8b10()->FUN_140ae6540())->m_b0)
    {
        MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe == 0)
            return false;
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e2e0(pMe->FUN_1416639e0());
        if (spItem == 0)
            return false;
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x1a, FUN_14028de60(0xaa1), 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            spBox->FUN_140b76940(CStringW(strText));
            spBox->FUN_141a01600(spItem->FUN_140526a50());
            CStringW strName = spItem->FUN_140527b10();
            spBox->FUN_141a01ee0(MS2Ptr<CItem>(spItem), strName, 1, 1, 1, -1, 1);
            spBox->FUN_141a01800(1);
            spBox->FUN_141a02670(!FUN_140166410()->FUN_14036e5b0());
            spBox->FUN_141a024e0(FUN_14028de60(0xaa4), 0);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMessenger::FUN_141a0f9d0));
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
            return true;
        }
    }
    if (nType == 0xb && MSG_COMMUNITY_FLAGS(FUN_1409a8b10()->FUN_140ae6540())->m_b1)
    {
        int nPrice = FUN_1403bb830();
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x19, FUN_1409e97f0(0xaa2, nPrice), 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            spBox->FUN_140b76940(CStringW(strText));
            spBox->FUN_141a01800(1);
            spBox->FUN_141a02670(!FUN_140166410()->FUN_14036e5b0());
            spBox->FUN_141a024e0(FUN_14028de60(0xaa4), 0);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMessenger::FUN_141a0fb40));
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
            return true;
        }
    }
    if (nType == 0xc && MSG_COMMUNITY_FLAGS(FUN_1409a8b10()->FUN_140ae6540())->m_b2)
    {
        int nPrice = FUN_1403bb850();
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x19, FUN_1409e97f0(0xaa3, nPrice), 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            spBox->FUN_140b76940(CStringW(strText));
            spBox->FUN_141a01800(1);
            spBox->FUN_141a02670(!FUN_140166410()->FUN_14036e5b0());
            spBox->FUN_141a024e0(FUN_14028de60(0xaa4), 0);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMessenger::FUN_141a0fcb0));
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
            return true;
        }
    }
    return false;
}

template <class T> inline T Unk_HpxMin(T a, T b) { return a < b ? a : b; }
void FUN_14183ea40(int nItemId, CStringW& strIconPath);             // the icon of an item
int FUN_1403bb8a0();                                                // the world chat original price
int FUN_1403bb8d0();                                                // the channel chat original price
extern unsigned long DAT_1439f87d0;                                 // the subject colours: social
extern unsigned long DAT_1439f87e8;                                 // party
extern unsigned long DAT_1439f87ec;                                 // guild
extern unsigned long DAT_1439f87f0;                                 // super
extern unsigned long DAT_1439f87f4;                                 // world
extern unsigned long DAT_1439f87f8;                                 // channel

// MS2-FUNCTIONAL: temporaries differ from the exe (functional-first)
// @0x141a14dc0
void UIMessenger::FUN_141a14dc0()
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    FUN_141a13e00();
    MS2Ptr<ASDropdownMenu> spSubject = m_subject;
    if (spSubject == 0)
        return;
    spSubject->FUN_1422dfc10();
    spSubject->FUN_1422c1fe0(1);
    if (!m_pBrowser->FUN_141a264c0(0x10))
    {
        int nItemId = pMe->FUN_1416639e0();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e2e0(nItemId);
        if (spItem == 0)
            nItemId = 0;
        CStringW strIcon;
        FUN_14183ea40(nItemId, strIcon);
        ASObj item(2);
        item.FUN_1409c0dc0(s_strFrame, "super");
        item.FUN_1407cbb20(s_strIconPath, CStringW(strIcon));
        item.FUN_1407cbb20(s_strLabel, FUN_14025e7a0()->FUN_1422b0570(CString("$s_talkpanelsetting_super")));
        item.FUN_1409c4990(s_strColor, DAT_1439f87f0);
        spSubject->FUN_1422dfc70(item);
    }
    if (!m_pBrowser->FUN_141a264c0(0xb))
    {
        ASObj item(2);
        item.FUN_1409c0dc0(s_strFrame, "world");
        item.FUN_1409c0d20(s_strPrice, FUN_1403bb830());
        item.FUN_1409c0d20(s_strOriginPrice, FUN_1403bb8a0());
        item.FUN_1407cbb20(s_strLabel, FUN_14025e7a0()->FUN_1422b0570(CString("$s_talkpanelsetting_world")));
        item.FUN_1409c4990(s_strColor, DAT_1439f87f4);
        spSubject->FUN_1422dfc70(item);
    }
    if (!m_pBrowser->FUN_141a264c0(0xc))
    {
        ASObj item(2);
        item.FUN_1409c0dc0(s_strFrame, "channel");
        item.FUN_1409c0d20(s_strPrice, FUN_1403bb850());
        item.FUN_1409c0d20(s_strOriginPrice, FUN_1403bb8d0());
        item.FUN_1407cbb20(s_strLabel, FUN_14025e7a0()->FUN_1422b0570(CString("$s_talkpanelsetting_channel")));
        item.FUN_1409c4990(s_strColor, DAT_1439f87f8);
        spSubject->FUN_1422dfc70(item);
    }
    if (!m_pBrowser->FUN_141a264c0(0))
    {
        ASObj item(2);
        item.FUN_1407cbb20(s_strLabel, FUN_14025e7a0()->FUN_1422b0570(CString("$s_talkpanelsetting_social")));
        item.FUN_1409c4990(s_strColor, DAT_1439f87d0);
        spSubject->FUN_1422dfc70(item);
    }
    if (!m_pBrowser->FUN_141a264c0(7))
    {
        ASObj item(2);
        item.FUN_1407cbb20(s_strLabel, FUN_14025e7a0()->FUN_1422b0570(CString("$s_talkpanelsetting_party")));
        item.FUN_1409c4990(s_strColor, DAT_1439f87e8);
        spSubject->FUN_1422dfc70(item);
    }
    if (!m_pBrowser->FUN_141a264c0(8))
    {
        ASObj item(2);
        item.FUN_1407cbb20(s_strLabel, FUN_14025e7a0()->FUN_1422b0570(CString("$s_talkpanelsetting_guild")));
        item.FUN_1409c4990(s_strColor, DAT_1439f87ec);
        spSubject->FUN_1422dfc70(item);
    }
    if (!m_pBrowser->FUN_141a264c0(0x12))
    {
        ASObj item(2);
        item.FUN_1409c0dc0(s_strFrame, "guildMegaphone");
        item.FUN_1407cbb20(s_strLabel,
                           FUN_14025e7a0()->FUN_1422b0570(CString("$s_talkpanelsetting_guild_megaphone")));
        item.FUN_1409c4990(s_strColor, DAT_1439f87ec);
        spSubject->FUN_1422dfc70(item);
    }
    if (m_subjectIndex.find(m_nTargetSelectedIndex) == m_subjectIndex.end())
        m_nTargetSelectedIndex = FUN_141a14110();
    unsigned nRows = Unk_HpxMin(spSubject->FUN_1422dfb90(), 8u);
    spSubject->FUN_1422df5f0(nRows);
    spSubject->FUN_1422df690(m_nTargetSelectedIndex);
    ((Unk_MsgPopup*)(ASUIComponent*)spSubject)->vfunc_24(true);
    FUN_141a15890();
}

class UIMeratMarketDialog                                            // view: the merat market (ui id 0x4ec1)
{
public:
    void SearchByKey(const CStringA& strKey, bool bExact, const CStringW& strText, int nValue);   // 0x14130f9e0
};

class Unk_MsgWedding
{
public:
    bool FUN_141b867e0(__int64 nWeddingId);                         // the hall is open
};
Unk_MsgWedding* FUN_1409eed90();
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);
int FUN_1418fd330(__int64 nCharId);
void FUN_1418fde20(__int64 nAccountId, __int64 nCharId, int nKind, const CStringW& strName, Delegate<bool(int, const CMsgBoxData&)> callback);
void FUN_140dff3a0(__int64 nId, const CStringW& strName, __int64 nFee, int nMax, int nShareRate);   // joins a UGC event
UIMeratMarketDialog* FUN_140bfed50(int nUiId);
__int64 FUN_140718320(const CStringW& str);
int FUN_1407181a0(const CStringW& str);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141a0a900
void UIMessenger::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (strMethod == "getTooltip")
    {
        MS2Ptr<CItem> spItem(0);
        __int64 nUid = _atoi64(pArgs->FUN_1422b8d30());
        if (m_pBrowser->m_linkedItems.Lookup(nUid, spItem))
        {
            ASTooltip tooltip(pPlayer, 2, 2);
            if (tooltip.FUN_1409e0d40(spItem.get()))
            {
                tooltip.FUN_1409c6c80();
                tooltip.FUN_1409db7b0(spItem);
                FUN_1409b4bc0(pRetVal, tooltip.FUN_1422bb870());
            }
        }
    }
    else if (strMethod == "itemPreview")
    {
        MS2Ptr<CItem> spItem(0);
        __int64 nUid = _atoi64(pArgs->FUN_1422b8d30());
        if (m_pBrowser->m_linkedItems.Lookup(nUid, spItem))
        {
            if (ItemPreviewMgr::GetInstance()->FUN_140d40670())
                ItemPreviewMgr::GetInstance()->FUN_140d40120(spItem, 0);
        }
    }
    else if (strMethod == "getAchieve")
    {
        int nId = atoi(pArgs->FUN_1422b8d30());
        int nGrade = atoi(pArgs->FUN_1422b8d30());
        ASTooltip tooltip(pPlayer, 2, 2);
        if (tooltip.FUN_1409e21a0(nId, nGrade))
        {
            tooltip.FUN_1409c6c80();
            CStringW strState = pArgs->FUN_1422b8f40();
            CStringW strDate = pArgs->FUN_1422b8f40();
            if (strDate.GetLength() > 0)
                strState = FUN_140656190(L"{0} ({1})", strState, strDate);
            tooltip.FUN_1407cbb20("state", CStringW(strState));
            FUN_1409b4bc0(pRetVal, tooltip.FUN_1422bb870());
        }
    }
    else if (_stricmp("whisper", strMethod) == 0)
    {
        FUN_141a14bb0(pArgs->FUN_1422b8f40());
    }
    else if (_stricmp("menu", strMethod) == 0)
    {
        CStringW strName = pArgs->FUN_1422b8f40();
        CStringW strAccount = pArgs->FUN_1422b8f40();
        CStringW strChar = pArgs->FUN_1422b8f40();
        float x = pArgs->FUN_1422b8c10();
        float y = pArgs->FUN_1422b8c10();
        __int64 nAccountId = 0;
        if (strAccount.GetLength() > 0)
            nAccountId = _wtoi64(strAccount);
        if (pPlayer->vfunc_77() != strName)
        {
            __int64 nCharId = 0;
            if (strChar.GetLength() > 0)
                nCharId = _wtoi64(strChar);
            UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
            if (pMenu != 0)
            {
                Unk_PopupMenuInfo info(x, y, 3, 0x635e, 0, "", (void*)nAccountId);
                CStringW strHistory;
                m_pBrowser->FUN_141a254c0(FUN_140869440(), strHistory);
                pMenu->FUN_141a805f0(info, (void*)nAccountId, nCharId, strName, strHistory, 4);
            }
        }
    }
    else if (_stricmp("moveToHome", strMethod) == 0)
    {
        CStringW strName = pArgs->FUN_1422b8f40();
        CStringW strAccount = pArgs->FUN_1422b8f40();
        CStringW strChar = pArgs->FUN_1422b8f40();
        __int64 nAccountId = 0;
        if (strAccount.GetLength() > 0)
            nAccountId = _wtoi64(strAccount);
        __int64 nCharId = 0;
        if (strChar.GetLength() > 0)
            nCharId = _wtoi64(strChar);
        if (FUN_1418fd330(nCharId))
            FUN_1418fde20(nAccountId, nCharId, 4, strName, Delegate<bool(int, const CMsgBoxData&)>(this, &UIMessenger::FUN_141a0f900));
    }
    else if (_stricmp("billDialog", strMethod) == 0)
    {
        int nProductId = FUN_1407181d0(pArgs->FUN_1422b8d30());
        int nA = FUN_1407181d0(pArgs->FUN_1422b8d30());
        FUN_140718170(pArgs->FUN_1422b8d30());
        int nB = FUN_140718170(pArgs->FUN_1422b8d30());
        FUN_141a16bb0(nProductId, nA, nB);
    }
    else if (_stricmp("searchFromMeratmarket", strMethod) == 0)
    {
        CString strKey = pArgs->FUN_1422b8d30();
        bool bExact = FUN_140718390(pArgs->FUN_1422b8d30());
        CStringW strText = pArgs->FUN_1422b8f40();
        int nValue = FUN_1407181d0(pArgs->FUN_1422b8d30());
        UIMeratMarketDialog* pMarket = FUN_140bfed50(0x4ec1);
        if (pMarket != 0)
            pMarket->SearchByKey(strKey, bExact, strText, nValue);
    }
    else if (_stricmp("itemSelect", strMethod) == 0)
    {
        CStringW strArg = pArgs->FUN_1422b8f40();
        ATL::CAtlArray<CStringW> args;
        FUN_14025a680(strArg, args, L",");
        if (args.GetCount() < 2)
            return;
        CStringW strKind(args[1]);
        if (!FUN_140841300(strKind, "HongBao"))
            return;
        if (args.GetCount() < 3)
            return;
        int nId = FUN_1407181a0(args[2]);
        COutPacket packet(0x9e, 0);
        packet.Encode1(1);
        packet.Encode4(nId);
        FUN_140710590(packet);
    }
    else if (_stricmp("hyperLinkLeft", strMethod) == 0)
    {
        CStringW strArg = pArgs->FUN_1422b8f40();
        ATL::CAtlArray<CStringW> args;
        FUN_14025a680(strArg, args, L",");
        if (args.GetCount() != 0)
            FUN_141a168a0(args);
    }
    else if (_stricmp("hyperLinkRight", strMethod) == 0)
    {
        CStringW strArg = pArgs->FUN_1422b8f40();
        ATL::CAtlArray<CStringW> args;
        FUN_14025a680(strArg, args, L",");
        if (args.GetCount() != 0)
            FUN_141a16b90(args);
    }
    else if (_stricmp("joinUGCEvent", strMethod) == 0)
    {
        CStringW strName = pArgs->FUN_1422b8f40();
        CStringW strId = pArgs->FUN_1422b8f40();
        CStringW strChar = pArgs->FUN_1422b8f40();
        CStringW strFee = pArgs->FUN_1422b8f40();
        CStringW strMax = pArgs->FUN_1422b8f40();
        CStringW strShare = pArgs->FUN_1422b8f40();
        __int64 nId = 0;
        if (strId.GetLength() > 0)
            nId = _wtoi64(strId);
        __int64 nCharId = 0;
        if (strChar.GetLength() > 0)
            nCharId = _wtoi64(strChar);
        __int64 nFee = FUN_140718320(strFee);
        int nMax = FUN_1407181a0(strMax);
        int nShare = FUN_1407181a0(strShare);
        if (FUN_1418fd330(nCharId))
            FUN_140dff3a0(nId, strName, nFee, nMax, nShare);
    }
    else if (_stricmp("moveToWeddingHall", strMethod) == 0)
    {
        if (!FUN_140166410()->FUN_14036d570(0x104))
            return;
        CStringW strId = pArgs->FUN_1422b8f40();
        CStringW strA = pArgs->FUN_1422b8f40();
        CStringW strB = pArgs->FUN_1422b8f40();
        CStringW strGroom = pArgs->FUN_1422b8f40();
        CStringW strBride = pArgs->FUN_1422b8f40();
        __int64 nWeddingId = 0;
        if (strId.GetLength() > 0)
            nWeddingId = _wtoi64(strId);
        int nA = 0;
        if (strA.GetLength() > 0)
            nA = _wtoi(strA);
        int nB = 0;
        if (strB.GetLength() > 0)
            nB = _wtoi(strB);
        CStringW strText = FUN_140632a60(0xbfb, strGroom, strBride);
        if (FUN_1409eed90() != 0 && FUN_1409eed90()->FUN_141b867e0(nWeddingId))
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strText, 0, CStringW(L""));
            spBox->FUN_141a01800(1);
            spBox->FUN_1405340b0(nWeddingId);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMessenger::FUN_141a0f980));
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
        }
    }
}

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced in the exe, kept alive by the pointer below).
// MS2-PIN: memcpy_s 0x141a20e70
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMsgMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbfeb0-0x142cc01c0 .text$yd
