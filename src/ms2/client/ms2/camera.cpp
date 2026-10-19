// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The camera manager, the Camera object of the camera modes
// and the camera effects (see camera.h).
// MS2-UNIT: ?\camera.cpp
// MS2-RANGE: 0x140ae7940-0x140afd490 .text$mn
// MS2-RANGE: 0x1400c6520-0x1400c6730 .text$di
// MS2-PIN: ??_7Camera@@6B@ 0x142dd5a70
// MS2-PIN: ??_7CCameraEffect@@6B@ 0x142dd5ce8
// MS2-PIN: ??_7CVibrateCameraEffect@@6B@ 0x142dd5d00
// MS2-PIN: ??_7?$TSingleton@VCameraMgr@@@@6B@ 0x142dd6970
// MS2-PIN: ??_7CameraMgr@@6B@ 0x142dd6980
// MS2-PIN: memcpy_s 0x140ae98a0
// MS2-PIN: memmove_s 0x140ae99f0
// MS2-PIN: ?GetWorldRightVector@NiCamera@@QEBA?AVNiPoint3@@XZ 0x140af83f0
// MS2-PIN: ?GetWorldUpVector@NiCamera@@QEBA?AVNiPoint3@@XZ 0x140af8450
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?TypeCast@Camera@@UEBA_NIPEAPEAX@Z 0x140ae7c40 ; unique
// MS2-PIN: ?TypeCast@Camera@@UEBA_NIPEAPEBX@Z 0x140ae7c90 ; unique
// MS2-PIN: ??$?0AEBU?$less@K@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@K@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140af2750 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBK@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@QEAA@AEAV?$tuple@AEBK@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140af2890 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBK@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBK@1@$$QEAV?$tuple@$$V@1@@Z 0x140af2ab0 ; unique
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@1@AEAPEAU31@@Z 0x140af5530 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBK@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBK@1@$$QEAV?$tuple@$$V@1@@Z 0x140af5580 ; unique
// MS2-PIN: ??$construct@UUnk_CameraSetup@@AEAU1@@?$_Default_allocator_traits@V?$allocator@UUnk_CameraSetup@@@std@@@std@@SAXAEAV?$allocator@UUnk_CameraSetup@@@1@QEAUUnk_CameraSetup@@AEAU3@@Z 0x140af56d0 ; unique
// MS2-PIN: ??$construct@UUnk_CameraSetup@@U1@@?$_Default_allocator_traits@V?$allocator@UUnk_CameraSetup@@@std@@@std@@SAXAEAV?$allocator@UUnk_CameraSetup@@@1@QEAUUnk_CameraSetup@@$$QEAU3@@Z 0x140af5770 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBK@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBK@1@$$QEAV?$tuple@$$V@1@@Z 0x140af5920 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@0@AEAPEAU10@@Z 0x140af59e0 ; prop
// MS2-PIN: ??$forward@AEAUUnk_CameraSetup@@@std@@YAAEAUUnk_CameraSetup@@AEAU1@@Z 0x140af5a30 ; unique
// MS2-PIN: ??$forward@AEBUUnk_CameraSetting@@@std@@YAAEBUUnk_CameraSetting@@AEBU1@@Z 0x140af5a40 ; prop
// MS2-PIN: ??$forward@AEBVEntityID@egf@@@std@@YAAEBVEntityID@egf@@AEBV12@@Z 0x140af5a50 ; prop
// MS2-PIN: ??$forward@UUnk_CameraSetup@@@std@@YA$$QEAUUnk_CameraSetup@@AEAU1@@Z 0x140af5ab0 ; unique
// MS2-PIN: ??$make_pair@AEBVEntityID@egf@@AEBUUnk_CameraSetting@@@std@@YA?AU?$pair@VEntityID@egf@@UUnk_CameraSetting@@@0@AEBVEntityID@egf@@AEBUUnk_CameraSetting@@@Z 0x140af5b20 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCCameraMode@@@@QEAA@PEAVCCameraMode@@@Z 0x140af5d30 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140af7270 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140af7370 ; prop
// MS2-PIN: ?GetPlane@NiFrustumPlanes@@QEBAAEBVNiPlane@@I@Z 0x140af81f0 ; unique
// MS2-PIN: ?GetWorldDirection@NiCamera@@QEBA?AVNiPoint3@@XZ 0x140af8390 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@2@XZ 0x140af9fc0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@2@XZ 0x140afa200 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@UUnk_CameraSetup@@@std@@V?$_Vector_val@U?$_Simple_types@UUnk_CameraSetup@@@std@@@2@$00@std@@QEBAAEBV?$allocator@UUnk_CameraSetup@@@2@XZ 0x140afb6a0 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@2@_K@Z 0x140afc620 ; w116: node 0x40 (exe calls _Get_size_of_n<0x40>)
// MS2-PINS-END tplpin
// MS2-PIN: ??9?$SmartPointer@VNiAVObject@@@efd@@QEBA_NPEAVNiAVObject@@@Z 0x140af72f0
// MS2-PIN: ?GetAnimType@NiTimeController@@QEBA?AW4AnimType@1@XZ 0x140af7db0
// MS2-PIN: ?GetEndKeyTime@NiTimeController@@QEBAMXZ 0x140af7f50
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@2@_K@Z 0x140afc650
// MS2-PIN: ??$?0VEntityID@egf@@UUnk_CameraSetting@@$0A@@?$pair@VEntityID@egf@@UUnk_CameraSetting@@@std@@QEAA@AEBVEntityID@egf@@AEBUUnk_CameraSetting@@@Z 0x140af26b0
// MS2-PIN: ??$?0AEBU?$less@VEntityID@egf@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@VEntityID@egf@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@VEntityID@egf@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140af27a0
// MS2-PIN: ?push_back@?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@QEAAXAEBUUnk_CameraSetup@@@Z 0x140afd3c0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@UUnk_CameraSetting@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@2@XZ 0x140afa080
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@UUnk_CameraSetting@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@@5@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@2@XZ 0x140afa2e0
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBK0@Z 0x140afa560
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@1@AEAU?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@1@1@Z 0x140af3370
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@1@@Z 0x140af4670
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@PEAX@1@@Z 0x140af3a30
// MS2-PIN: ??$_Try_emplace@AEBK$$V@?$map@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@std@@_N@1@AEBK@Z 0x140af4fd0
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x140afc240 ; w116: m_setups (map<unsigned, vector<Unk_CameraSetup>>), exe callers _Try_emplace/_Insert_hint
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@2@XZ 0x140afc6b0 ; w116: m_setups (map<unsigned, vector<Unk_CameraSetup>>), exe callers _Try_emplace/_Insert_hint
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@2@XZ 0x140afcd00 ; w116: m_setups (map<unsigned, vector<Unk_CameraSetup>>), exe callers _Try_emplace/_Insert_hint
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@KV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$vector@UUnk_CameraSetup@@V?$allocator@UUnk_CameraSetup@@@std@@@std@@@std@@@std@@@std@@@2@0@Z 0x140afce20 ; w116: m_setups (map<unsigned, vector<Unk_CameraSetup>>), exe callers _Try_emplace/_Insert_hint
// MS2-PIN: ?Reset@?$MS2Ptr@VCCameraEffect@@@@QEAAXXZ 0x140af7ba0
// MS2-PIN: ?EnableAllPlanes@NiFrustumPlanes@@QEAAXXZ 0x140af7bc0
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140af25b0
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@PEAX@std@@@std@@QEAA@XZ 0x140af6370
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@UUnk_CameraSetting@@@std@@@std@@@std@@QEAA@XZ 0x140af6270
// MS2-PIN: ??C?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCCameraEffect@@@@@std@@@std@@@std@@QEBAPEAV?$MS2Ptr@VCCameraEffect@@@@XZ 0x140af7490
// MS2-PIN: ??8?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCCameraEffect@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140af7230
// MS2-PIN: ??9?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCCameraEffect@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140af7330
// MS2-PIN: ??E?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCCameraEffect@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140af7620
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\camera.cpp"
// The exe's memcpy_s copy calls memset/memcpy (no /Oi expansion): the pragma must precede its inline definition.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#define NOMINMAX
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "camera.h"
#include "hook/ms2hook.h"
#include <math.h>
#include <stdlib.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/targetcameramode.h"
#include "ms2/client/ms2/lockcameramode.h"
#include "ms2/client/ms2/toolcameramode.h"
#include "ms2/client/ms2/toolsmoothcameramode.h"
#include "ms2/client/ms2/tpscameramode.h"
#include "ms2/client/ms2/fpscameramode.h"
#include "ms2/client/ms2/target2dcameramode.h"
#include "ms2/client/ms2/rpgcameramode.h"
#include "ms2/unnamed/unit_1416c4de0.h"
#include "ms2/client/ms2/consolecameramode.h"
#include "ms2/client/ms2/homecameramode.h"
#include "ms2/client/ms2/bosstargetcamera.h"
#include "ms2/client/ms2/targetlookcentercameramode.h"
#include "ms2/client/ms2/flybycameramode.h"
#include "ms2/placeholder/freecameramode.h"
#include "ms2/client/ms2/cameramoveeffectparam.h"
#include "ms2/client/ms2/fielddatacli.h"
#include <ecr/RenderService.h>
#include <ecr/RenderSurface.h>
#include <ecr/CameraService.h>
#include <ecr/CameraData.h>
#include <ecr/PickService.h>
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uidialog.h"
#include <egf/EntityIDFactory.h>
#include <efd/utf8string.h>

// ---- out-of-unit callees ----
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
const char* FUN_14086f4b0(Unk_140165cf0*, const char*);                 // attribute value
CString FUN_140188f50(const char* psz, int n);                         // CString from an attribute value
int FUN_140873360(Unk_140165cf0*, const char*, float*);                 // float attribute
int FUN_140873220(Unk_140165cf0*, const char*, int*);                   // int attribute
int FUN_140874670(Unk_140165cf0*, const char*, Unk_StreamPoint*);       // point attribute
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // data path of a file
unsigned int FUN_140768010(unsigned int nRange, unsigned int nBase);    // random integer
float FUN_140768090();                                                  // random float in [0, 1)
extern "C" float (__cdecl* __imp_sinf)(float);                        // the exe calls the CRT import
extern const Unk_StreamPoint g_143a08ce8;                              // efd::Point3::UNIT_Y
extern const Unk_StreamPoint g_143a08cf8;                              // efd::Point3::UNIT_Z
class Unk_GameContext
{
public:
    // @0x140af8310
    efd::ServiceManager* FUN_140af8310() { return m_pServiceManager; }
    MS2Ptr<class CFieldDataCli> FUN_141bd30a0();                        // the current field data
    Unk_StreamPoint FUN_141bd3dc0();                                    // the map camera center

    void* m_0;
    efd::ServiceManager* m_pServiceManager;                             // +0x08
};
Unk_GameContext* FUN_1403ed2d0();                                       // the game context
// The game object of a picked mesh.
class Unk_CameraPickObject
{
public:
    GameObject* FUN_140a38a00();                                        // the npc (or null)
};
Unk_CameraPickObject* FUN_141bd1050(Unk_GameContext* pContext, void* pMesh);
// The pick record holder (ecr::PickService::PickRecord, reference counted by FUN_140a17eb0).
class Unk_GoPickHit;
class Unk_GoPickVec
{
public:
    unsigned int FUN_140a17ea0();                                       // size
    Unk_GoPickHit* FUN_140a17d70(unsigned int nIndex);
};
void* FUN_140a17cb0(Unk_GoPickHit* pHit);                               // the picked mesh
Unk_GoPickVec* FUN_140a17e00(ecr::PickService::PickRecord* pRecord);    // the hits
void FUN_140a17eb0(ecr::PickService::PickRecord* pRecord);              // add a reference
class Unk_GoPickListPtr
{
public:
    Unk_GoPickListPtr(ecr::PickService::PickRecord* p);                 // 0x140a152b0
    // @0x140af5c90
    Unk_GoPickListPtr(const Unk_GoPickListPtr& o)
    {
        m_p = o.m_p;
        if (m_p)
            FUN_140a17eb0(m_p);
    }
    ~Unk_GoPickListPtr();                                               // 0x140a16120
    ecr::PickService::PickRecord* FUN_140a16c00() const;
    ecr::PickService::PickRecord* FUN_140a16c30() const;

    ecr::PickService::PickRecord* m_p;
};
// The ui service: dialog lookup by id and the queued scene dialogs.
class Unk_CameraUIService
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
    void FUN_141adc5d0(int nId);
    void FUN_141adc530(int nId);
};
Unk_CameraUIService* FUN_1403ed2b0();
// The npc control dialog (id 0x4e81).
class UINpcControlDialog : public UIDialog
{
public:
    void FUN_141a638c0(int nNpcId);
};
// @0x140af2990
template <class T> T* Unk_CameraDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}
class Unk_CameraInput;
Unk_CameraInput* FUN_14025e7c0();
bool FUN_14116d720(Unk_CameraInput* pInput);                            // npc control mode
bool FUN_14116d7a0(Unk_CameraInput* pInput, int nState);
bool FUN_14116d950(Unk_CameraInput* pInput, int nKey, bool b, int n);   // key down
bool FUN_14116d9c0(Unk_CameraInput* pInput, int nKey, bool b, int n);   // key pressed this frame
void FUN_1412751b0(const CStringW& strMsg, int nType);                  // system chat notice
class Unk_CameraHousing
{
public:
    int FUN_1410d2f10();
};
Unk_CameraHousing* FUN_1409670e0();
extern int DAT_143ab0248;                                               // client country (0..3)
extern int DAT_143ab2914;                                               // client build / region level
class Unk_CameraCursor;
Unk_CameraCursor* FUN_140aadf80();
void FUN_141b90e30(Unk_CameraCursor* pCursor, float* pX, float* pY);    // cursor window position
int FUN_141bd3e00(Unk_GameContext* pContext);
unsigned int FUN_141bd3060(Unk_GameContext* pContext);                  // current map id
float FUN_141bcfc50(Unk_GameContext* pContext);
// The rpg object of a camera target (FUN_1409ffd30 casts a target to it).
class Unk_CameraActor
{
public:
    void FUN_1416781a0(int nMode);                                      // tells the actor the camera mode id
};
Unk_CameraActor* FUN_1409ffd30(Unk_CameraTargetEntity* pTarget);
Unk_CameraActor* FUN_14099eef0(Unk_CameraTargetEntity* pTarget);       // the rpg object of a target (or null)
ecr::RenderService* FUN_1413f9890();                                    // the render service
ecr::CameraService* FUN_1413f9910();                                    // the camera service
class Unk_SceneApp;
Unk_SceneApp* FUN_140aa6d30();                                          // the scene app
int FUN_1417e2610(Unk_SceneApp* pApp);                                  // current scene state id
class Unk_UIManager;
Unk_UIManager* FUN_1408e57f0();
void FUN_1422ba250(Unk_UIManager* pUI);
class Unk_140ad4b90;
Unk_140ad4b90* FUN_140ad4b90();
void FUN_1418631a0(Unk_140ad4b90* p);
bool FUN_141863100(Unk_140ad4b90* p, int nMapId, const Unk_StreamPoint& ptPos);   // the point is in the map's area
Unk_CameraTargetEntity* FUN_141bd1200(Unk_GameContext* pContext, int nId);   // an npc by object id
Unk_CameraTargetEntity* FUN_141bd0cc0(Unk_GameContext* pContext);       // the local player
void FUN_141bdb5a0(Unk_GameContext* pContext, int bOn);
void FUN_141bd9e60(Unk_GameContext* pContext, float f1, float f2, float fTime, int nTargetId);
void FUN_141bda050(Unk_GameContext* pContext, float f, int nTargetId);
unsigned int FUN_140869420();                                           // tick count in ms
void FUN_1409a5770(const NiFixedString& kName, const float* pf, int n); // set a global shader constant
extern NiFixedString DAT_143ae5380;                                     // camera shader constant name
// The camera options of the client settings (FUN_1409a8b10).
struct Unk_CameraOption
{
    bool m_0;
    bool m_1;                                                           // camera effects on
    int m_4;                                                            // camera speed (percent)
};
class Unk_ClientSettings
{
public:
    // @0x140af7de0
    Unk_CameraOption* FUN_140af7de0() { return &m_8; }

    int m_0;
    int m_4;
    Unk_CameraOption m_8;
};
Unk_ClientSettings* FUN_1409a8b10();
// The client constants table (FUN_1401d3200). Each value is a 0x58-byte record.
class Unk_CameraConstValue
{
public:
    const float& FUN_140298f40();
    char m_pad[0x58];
};
struct Unk_CameraConsts
{
    char m_pad[0x1a80];
    Unk_CameraConstValue m_kCameraSpeed1;                               // +0x1a80
    Unk_CameraConstValue m_kCameraSpeed2;                               // +0x1ad8
    Unk_CameraConstValue m_kCameraSpeed3;                               // +0x1b30
};
Unk_CameraConsts* FUN_1401d3200();
EntityWorldManager* FUN_1409670f0();
egf::Entity* FUN_1408a9090(const void* sp);                             // the entity of a smart pointer
float FUN_1409f25a0(float f);                                           // cos
float FUN_1409f2310(float f);                                           // sin
Unk_CameraSetting* FUN_140947880(CCameraMode* p);                       // &p->m_setting
int FUN_1422b9dc0(Unk_UIManager* pUI);                                  // current ui scene id
class Unk_1409a8b20;
Unk_1409a8b20* FUN_1409a8b20();
class Unk_Clock;
Unk_Clock* FUN_14086d260();                                             // the game clock
double FUN_141473280(Unk_Clock* pClock);                                // seconds
void FUN_140a0b2a0(NiAVObject* pNode);                                  // detach the node from its parent
class Unk_CameraPostEffect
{
public:
    void FUN_1411780e0(float f1, float f2);
};
Unk_CameraPostEffect* FUN_1416aad00(Unk_1409a8b20* p);
// A camera path row (as read by CameraMgr::FUN_140aefb20; the trigger camera path data).
struct Unk_CameraPathRow
{
    CString m_strFile;                                                  // +0x00 nif under ./Data/Resource/Model/Camera/
    float m_f8;                                                         // +0x08
    int m_c;                                                            // +0x0c
};
MS2_CHECK_SIZE(Unk_CameraPathRow, 0x10);
CString FUN_140298360(const char* psz, const CString& str);              // ATL operator+(const char*, const CString&) (another obj)
class Unk_CamEffectMgr
{
public:
    NiNode* FUN_1411a6b10();                                            // the effect scene root
};
Unk_CamEffectMgr* FUN_1403ed280();                                      // the effect manager
class Unk_CamNifCache
{
public:
    NiAVObjectPtr FUN_141551ea0(CString strPath, int n1, int n2, int n3, int n4);   // load (cached) nif
};
Unk_CamNifCache* FUN_140a0afd0();                                       // the nif cache
egf::Entity* FUN_14123c410(Unk_CameraTargetEntity* pTarget);            // the target's entity
NiNode* FUN_141b6efc0(egf::Entity* pEntity);                            // the entity's scene root
// A NiNode that follows only some parts of its parent's transform (0x138 bytes; unrecovered class).
class Unk_SeparateNode : public NiNode
{
public:
    Unk_SeparateNode(Unk_CamMoveBits kUpdate);                          // 0x141751470
    char m_pad_node[0x138 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_SeparateNode, 0x138);
// Depth-first walker over a scene graph (0x38 bytes; unrecovered class).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);                                  // 0x14098cb80
    ~Unk_SceneWalker();                                                 // 0x14098cf00
    NiAVObject* Next(bool bDescend);                                    // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);
extern unsigned int DAT_143af62d4;                                      // client area width
extern unsigned int DAT_143af62d8;                                      // client area height

// The UCRT's `static __inline` memcpy_s / memmove_s copies of this TU (unreferenced COMDATs).
__declspec(selectany) extern errno_t(__cdecl* const ms2_cameraMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
__declspec(selectany) extern errno_t(__cdecl* const ms2_cameraMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;

// ---- statics (the exe runs them in this order) ----
// @0x1400c6520
static CString s_strGameplayCamera("MS2GameplayCamera");
// @0x1400c6550
EE_IMPLEMENT_CONCRETE_CLASS_INFO(Camera);
// @0x1400c6570
static egf::EntityID s_invalidEntity(0ull);
// @0x1400c6590
static CLockCriticalSection s_testValueLock;
// @0x1400c65c0
static ATL::CRBMap<CString, CString> s_testValues(10);
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/camera_statics.h"
#include "ms2/placeholder/header_statics_a.h"

CameraMgr* TSingleton<CameraMgr>::s_instance;

// @0x140af7fd0
inline egf::EntityID Camera::FUN_140af7fd0()
{
    return m_10 ? m_10->GetEntityID() : s_invalidCameraEntity;
}

// ---- Camera ----

// @0x140ae7940
Camera::Camera()
{
    m_c = 0;
    m_10 = 0;
}

// @0x140ae79b0
Camera::~Camera()
{
}

// ---- Unk_CameraSetting ----

// @0x140ae7e80
Unk_CameraSetting Unk_CameraSetting::FUN_140ae7e80(float f) const
{
    Unk_CameraSetting r;
    r.m_0 = m_0 * f;
    r.m_4 = m_4 * f;
    r.m_8 = m_8 * f;
    r.m_c = m_c.FUN_14097fc90(f);
    r.m_18 = m_18.FUN_14097fc90(f);
    r.m_24 = m_24;
    return r;
}

// @0x140ae7f70
Unk_CameraSetting Unk_CameraSetting::FUN_140ae7f70(float f)
{
    m_0 = m_0 * f;
    m_4 = m_4 * f;
    m_8 = m_8 * f;
    m_c.FUN_140ad0c10(f);
    m_18.FUN_140ad0c10(f);
    return *this;
}

// @0x140ae8020
Unk_CameraSetting Unk_CameraSetting::FUN_140ae8020(float f) const
{
    Unk_CameraSetting r;
    r.m_0 = m_0 / f;
    r.m_4 = m_4 / f;
    r.m_8 = m_8 / f;
    r.m_c = m_c.FUN_140ae9180(f);
    r.m_18 = m_18.FUN_140ae9180(f);
    r.m_24 = m_24;
    return r;
}

// @0x140ae8110
Unk_CameraSetting Unk_CameraSetting::FUN_140ae8110(float f)
{
    m_0 = m_0 / f;
    m_4 = m_4 / f;
    m_8 = m_8 / f;
    m_c.FUN_140ae9270(f);
    m_18.FUN_140ae9270(f);
    return *this;
}

// @0x140ae81c0
Unk_CameraSetting Unk_CameraSetting::FUN_140ae81c0(const Unk_CameraSetting& o) const
{
    Unk_CameraSetting r;
    r.m_0 = m_0 + o.m_0;
    r.m_4 = m_4 + o.m_4;
    r.m_8 = m_8 + o.m_8;
    r.m_c = m_c.FUN_14097fd50(o.m_c);
    r.m_18 = m_18.FUN_14097fd50(o.m_18);
    r.m_24 = m_24;
    return r;
}

// @0x140ae82c0
Unk_CameraSetting Unk_CameraSetting::FUN_140ae82c0(const Unk_CameraSetting& o)
{
    m_0 = m_0 + o.m_0;
    m_4 = m_4 + o.m_4;
    m_8 = m_8 + o.m_8;
    m_c.FUN_140a4e560(o.m_c);
    m_18.FUN_140a4e560(o.m_18);
    return *this;
}

// @0x140ae8380
Unk_CameraSetting Unk_CameraSetting::FUN_140ae8380(const Unk_CameraSetting& o) const
{
    Unk_CameraSetting r;
    r.m_0 = m_0 - o.m_0;
    r.m_4 = m_4 - o.m_4;
    r.m_8 = m_8 - o.m_8;
    r.m_c = m_c.FUN_140965c40(o.m_c);
    r.m_18 = m_18.FUN_140965c40(o.m_18);
    r.m_24 = m_24;
    return r;
}

// @0x140ae8480
Unk_CameraSetting Unk_CameraSetting::FUN_140ae8480(const Unk_CameraSetting& o)
{
    m_0 = m_0 - o.m_0;
    m_4 = m_4 - o.m_4;
    m_8 = m_8 - o.m_8;
    m_c.FUN_140ae9200(o.m_c);
    m_18.FUN_140ae9200(o.m_18);
    return *this;
}

// ---- the test camera values (TestCamerValue.xml: <ms2><key name=".." value=".."/></ms2>) ----

BOOL FUN_140ae8540();
#ifndef MS2_HOOK_DLL
// @0x140ae8540
// MS2-FUNCTIONAL: the CRBTree/CAtlMap helper COMDAT names of the static map init are paired with another obj.
BOOL FUN_140ae8540()
{
    ATL::CRBMap<CString, CString> values(10);
    CString strUnused;
    TiXmlDocument doc;
    if (!doc.FUN_140870fc0("./data/xml/table/TestCamerValue.xml", 0))
    {
        if (!FUN_140166420()->FUN_1403974b0(&doc, "./data/xml/table/TestCamerValue.xml", 0, true, false))
            return FALSE;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (!pRoot)
        return FALSE;
    for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey; pKey = pKey->FUN_140168650("key"))
    {
        CString strName = FUN_140188f50(FUN_14086f4b0(pKey, "name"), 0);
        CString strValue = FUN_140188f50(FUN_14086f4b0(pKey, "value"), 0);
        values.SetAt(strName, strValue);
    }
    if (Unk_LockGuard guard = s_testValueLock)
    {
    }
    else
    {
        s_testValues.RemoveAll();
        for (POSITION pos = values.GetHeadPosition(); pos; values.GetNext(pos))
            s_testValues.SetAt(values.GetKeyAt(pos), values.GetValueAt(pos));
    }
    return TRUE;
}
#endif

CString FUN_140ae8800(CString strKey);
#ifndef MS2_HOOK_DLL
// @0x140ae8800
CString FUN_140ae8800(CString strKey)
{
    CString strValue("");
    if (Unk_LockGuard guard = s_testValueLock)
    {
    }
    else
    {
        if (s_testValues.Lookup(strKey, strValue))
            return strValue;
    }
    return "";
}
#endif

// @0x140ae8910
float FUN_140ae8910(CString strKey)
{
    CString strValue = FUN_140ae8800(strKey);
    if (strValue.GetLength() == 0)
        return 0.0f;
    float fValue = (float)atof(strValue);
    return fValue;
}

// @0x140ae89e0
int FUN_140ae89e0(CString strKey)
{
    CString strValue = FUN_140ae8800(strKey);
    if (strValue.GetLength() == 0)
        return 0;
    int nValue = atoi(strValue);
    return nValue;
}

// @0x140ae8aa0
Unk_CameraSetup::Unk_CameraSetup()
    : m_28(0), m_2c(0), m_30(0), m_34(0), m_38(0), m_3c(0), m_40(0, 0, 0), m_4c(0, 0, 0), m_58(false), m_59(true),
      m_5c(1), m_60(1), m_64(0), m_68(0), m_6c(0)
{
}

// ---- CMapCameraData / CBossTargetCameraData ----

// @0x140ae8ba0
CMapCameraData::CMapCameraData()
{
    m_18 = 2;
    m_distance = 1200.0f;
    m_vAngle = 0.87266463f;
    m_hAngle = 0.78539819f;
    m_zoomOutHeightOffset = 60.0f;
    m_zoomInHeightOffset = 95.0f;
    m_30 = false;
}

// @0x140ae8c50
CMapCameraData::CMapCameraData(const CMapCameraData& o)
{
    m_distance = o.m_distance;
    m_vAngle = o.m_vAngle;
    m_hAngle = o.m_hAngle;
    m_zoomOutHeightOffset = o.m_zoomOutHeightOffset;
    m_zoomInHeightOffset = o.m_zoomInHeightOffset;
    m_30 = o.m_30;
    m_18 = o.m_18;
}

// @0x140ae8d10
CMapCameraData::~CMapCameraData()
{
}

// @0x140ae8d40
void CMapCameraData::vfunc_1(void* pParam)
{
    FUN_140873360((Unk_140165cf0*)pParam, "distance", &m_distance);
    FUN_140873360((Unk_140165cf0*)pParam, "hAngle", &m_hAngle);
    FUN_140873360((Unk_140165cf0*)pParam, "vAngle", &m_vAngle);
    FUN_140873360((Unk_140165cf0*)pParam, "zoomOutHeightOffset", &m_zoomOutHeightOffset);
    FUN_140873360((Unk_140165cf0*)pParam, "zoomInHeightOffset", &m_zoomInHeightOffset);
}

// @0x140ae8df0
CBossTargetCameraData::CBossTargetCameraData()
{
    m_distanceOffset = 500.0f;
    m_detachDistance = 800.0f;
    m_zoomOut = 2000.0f;
    m_viewOffsetZ = 200.0f;
    m_lerpSpeedMin = 0.001f;
    m_lerpSpeedMax = 0.005f;
    m_lerpDelayDistanceMin = 1000.0f;
    m_lerpDelayDistanceMax = 2000.0f;
}

// @0x140ae8ec0
CBossTargetCameraData::CBossTargetCameraData(const CMapCameraData& o) : CMapCameraData(o)
{
    m_distanceOffset = 500.0f;
    m_detachDistance = 800.0f;
    m_zoomOut = 2000.0f;
    m_viewOffsetZ = 200.0f;
    m_lerpSpeedMin = 0.001f;
    m_lerpSpeedMax = 0.005f;
    m_lerpDelayDistanceMin = 1000.0f;
    m_lerpDelayDistanceMax = 2000.0f;
}

// @0x140ae8f90
CBossTargetCameraData::CBossTargetCameraData(const CBossTargetCameraData& o) : CMapCameraData(o)
{
    m_distanceOffset = o.m_distanceOffset;
    m_detachDistance = o.m_detachDistance;
    m_zoomOut = o.m_zoomOut;
    m_viewOffsetZ = o.m_viewOffsetZ;
    m_lerpSpeedMin = o.m_lerpSpeedMin;
    m_lerpSpeedMax = o.m_lerpSpeedMax;
    m_lerpDelayDistanceMin = o.m_lerpDelayDistanceMin;
    m_lerpDelayDistanceMax = o.m_lerpDelayDistanceMax;
}

// @0x140ae9070
void CBossTargetCameraData::vfunc_1(void* pParam)
{
    CMapCameraData::vfunc_1(pParam);
    FUN_140873360((Unk_140165cf0*)pParam, "distanceOffset", &m_distanceOffset);
    FUN_140873360((Unk_140165cf0*)pParam, "detachDistance", &m_detachDistance);
    FUN_140873360((Unk_140165cf0*)pParam, "viewOffsetZ", &m_viewOffsetZ);
    FUN_140873360((Unk_140165cf0*)pParam, "zoomOut", &m_zoomOut);
    FUN_140873360((Unk_140165cf0*)pParam, "lerpSpeedMin", &m_lerpSpeedMin);
    FUN_140873360((Unk_140165cf0*)pParam, "lerpSpeedMax", &m_lerpSpeedMax);
    FUN_140873360((Unk_140165cf0*)pParam, "lerpDelayDistanceMin", &m_lerpDelayDistanceMin);
    FUN_140873360((Unk_140165cf0*)pParam, "lerpDelayDistanceMax", &m_lerpDelayDistanceMax);
}

// ---- efd::Point3 operators (COMDATs of this obj) ----

// @0x140ae9180
Unk_StreamPoint Unk_StreamPoint::FUN_140ae9180(float f) const
{
    float fInv = 1.0f / f;
    return Unk_StreamPoint(fInv * x, fInv * y, fInv * z);
}

// @0x140ae9200
Unk_StreamPoint& Unk_StreamPoint::FUN_140ae9200(const Unk_StreamPoint& pt)
{
    x = x - pt.x;
    y = y - pt.y;
    z = z - pt.z;
    return *this;
}

// @0x140ae9270
Unk_StreamPoint& Unk_StreamPoint::FUN_140ae9270(float f)
{
    float fInv = 1.0f / f;
    x = x * fInv;
    y = y * fInv;
    z = z * fInv;
    return *this;
}

// ---- camera effects ----

// @0x140ae9370
CCameraEffect::CCameraEffect(double fStart, double fEnd)
{
    m_fStart = fStart;
    m_fEnd = fEnd;
}

// @0x140ae93d0
CCameraEffect::~CCameraEffect()
{
}

// @0x140ae9400
bool CCameraEffect::vfunc_1(double fTime, Unk_StreamPoint& ptLook, Unk_StreamPoint& ptUp)
{
    if (fTime < m_fStart)
        return true;
    else if (fTime < m_fEnd)
        return true;
    else
        return false;
}

// @0x140ae9450
CVibrateCameraEffect::CVibrateCameraEffect(double fStart, double fEnd, float fFrequency, float fAmplitude,
    float fMinScale, double fFadeStart, int bVertical)
    : CCameraEffect(fStart, fEnd), m_fFrequency(fFrequency), m_fAmplitude(fAmplitude), m_fMinScale(fMinScale),
      m_fFadeStart(fFadeStart), m_ptDir(g_143a08cf8), m_bNegative(1), m_bVertical(bVertical)
{
}

// @0x140ae9520
CVibrateCameraEffect::~CVibrateCameraEffect()
{
}

// @0x140ae9550
bool CVibrateCameraEffect::vfunc_1(double fTime, Unk_StreamPoint& ptLook, Unk_StreamPoint& ptUp)
{
    if (fTime < m_fStart)
        return true;
    else if (fTime < m_fEnd)
    {
        float fFade = 1.0f;
        if (fTime >= m_fFadeStart)
            fFade = 1.0f - (float)((fTime - m_fFadeStart) / (m_fEnd - m_fFadeStart));
        float fScale = (fFade * (1.0f - m_fMinScale) + m_fMinScale) * m_fAmplitude;
        float fPhase = (float)((fTime - m_fStart) / (m_fEnd - m_fStart));
        float fWave = __imp_sinf(fPhase * m_fFrequency * 2.0f * 3.1415927f) * fScale;
        if (!m_bVertical || m_bNegative != (fWave < 0.0f))
        {
            float fX = ((float)FUN_140768010(2, 0) - 0.5f) * 2.0f;
            float fZ = ((float)FUN_140768010(2, 0) - 0.5f) * 2.0f;
            m_ptDir.x = FUN_140768090() * fX;
            m_ptDir.z = FUN_140768090() * fZ;
            if (m_bVertical)
            {
                float fY = ((float)FUN_140768010(2, 0) - 0.5f) * 2.0f;
                m_ptDir.y = FUN_140768090() * fY;
            }
            m_ptDir.FUN_140968990();
            m_bNegative = fWave < 0.0f;
        }
        ptLook.FUN_140a4e560(m_ptDir.FUN_14097fc90(fWave));
        return true;
    }
    else
        return false;
}

// ---- CameraMgr ----

// @0x140af5dd0
TSingleton<CameraMgr>::TSingleton()
{
    s_instance = (CameraMgr*)this;
}

// @0x140af6760
Unk_CameraEffectState::Unk_CameraEffectState() : m_spScene(0), m_spCameraNode(0), m_spFOV(0)
{
    m_fStart = 0;
    m_fMaxTime = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_pCamera = 0;
    m_spCameraNode = 0;
    m_spFOV = 0;
    m_fFOV = 0;
}

// @0x140ae9b10
CameraMgr::CameraMgr()
    : m_nPendingMode(0), m_c8(g_143b01a60), m_d4(g_143b01a60), m_108(1), m_pCamera(0), m_spMode(0),
      m_ptMove(g_143b01a60), m_1a8(0), m_1b0(0), m_1b4(0), m_1b8(0), m_pTarget(0), m_spTargetObject(0), m_240(0),
      m_244(1), m_248(0), m_24c(true), m_278(0), m_27c(false), m_entitySetups(10)
{
}

// @0x140ae9db0
CameraMgr::~CameraMgr()
{
    FUN_140aead90();
}

// @0x140ae9ed0
void CameraMgr::FUN_140ae9ed0(egf::Entity* pEntity, const Unk_StreamPoint* pLook, const Unk_StreamPoint* pRot)
{
    if (!m_pCamera)
    {
        m_pCamera = EE_NEW Camera;
        m_pCamera->FUN_140af9b20(1);
    }
    if (pEntity)
    {
        FUN_140af9a70(pEntity);
        m_pCamera->FUN_140a38e00(g_143b01a60);
        m_pCamera->FUN_140a38dc0(g_143b01a60);
    }
    if (m_spMode.IsNull())
    {
        CTargetCameraMode* pMode = new CTargetCameraMode((Unk_CameraOwner*)m_pCamera, MS2Ptr<CCameraMode>(0));
        pMode->FUN_14183cc80(FUN_141bd3e00(FUN_1403ed2d0()));
        m_spMode.AssignRaw(pMode);
        m_spTargetMode.AssignRaw(pMode);
    }
    m_spMode->FUN_140af9820((Unk_CameraOwner*)m_pCamera);
    m_spMode->vfunc_10();
    m_spMode->vfunc_6(0);
    if (pLook)
        m_spMode->vfunc_3(*pLook);
    if (pRot)
        m_spMode->vfunc_4(*pRot);
    m_setting.m_0 = m_spMode->FUN_140ad4b30();
    m_setting.m_4 = m_spMode->FUN_140af7ef0();
    m_setting.m_8 = m_spMode->FUN_140af7e90();
    m_setting.m_18 = m_spMode->FUN_140af8260();
    m_setting.m_c = m_spMode->FUN_1409f2540();
    m_setting.m_24 = m_spMode->FUN_140af8140();
    if (!m_spTargetObject)
        m_spTargetObject = EE_NEW GameObject;
    m_ptMove = g_143b01a60;
    m_1d0 = 0;
    m_1b0 = 1;
    m_bFlyBy = 0;
    FUN_140ae8540();
    m_testCache.FUN_1401d1160("./data/xml/table/TestCamerValue.xml");
}

// @0x140aea4c0
// MS2-FUNCTIONAL: NiFrustumPlanes::Set argument registers are loaded in a different order.
void CameraMgr::FUN_140aea4c0(float fTime)
{
    if (m_spMode.IsNull())
        return;
    if (FUN_1401d1320(&m_testCache))
    {
        m_spMode->vfunc_31();
        m_testCache.FUN_1401d1160("./data/xml/table/TestCamerValue.xml");
    }
    if (m_nPendingMode)
    {
        FUN_140aed750(m_nPendingMode, 1);
        m_nPendingMode = 0;
        FUN_1418631a0(FUN_140ad4b90());
    }
    FUN_140aea7f0();
    m_spMode->vfunc_8(fTime);
    FUN_140af1de0();
    float fValue = m_spMode.get() ? m_spMode->vfunc_19() : 0;
    FUN_1409a5770(DAT_143ae5380, &fValue, 1);
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    if ((FUN_1417e2610(FUN_140aa6d30()) == 0x620000c || FUN_1417e2610(FUN_140aa6d30()) == 0x620000d ||
            FUN_1417e2610(FUN_140aa6d30()) == 0x6200018) &&
        m_1ac && FUN_140869420() - m_1d0 > 1000)
    {
        FUN_1422ba250(FUN_1408e57f0());
        m_1ac = 0;
    }
    if (m_108)
        FUN_140af1f70();
    if (pSurface)
    {
        ecr::CameraData* pData = FUN_1413f9910()->GetActiveCamera(pSurface);
        NiCamera* pCamera;
        if (pData && (pCamera = pData->GetCamera()) != 0)
        {
            const NiTransform* pTransform = &pCamera->GetWorldTransform();
            m_frustumPlanes.Set(pCamera->GetViewFrustum(), *pTransform);
            m_frustumPlanes.EnableAllPlanes();
        }
    }
}

// @0x140aead90
void CameraMgr::FUN_140aead90()
{
    m_1b0 = 0;
    m_pTarget = 0;
    m_spTargetObject = 0;
    m_1a8 = 0;
    m_1ac = 0;
    if (m_spMode.get())
        m_spMode->vfunc_7();
    m_spMode = 0;
    m_nPendingMode = 0;
    m_ptMove = g_143b01a60;
    m_1b4 = 0;
    FUN_140af1a90();
    m_savedSettings.clear();
    if (m_pCamera)
    {
        if (m_pCamera)
        {
            delete m_pCamera;
            m_pCamera = 0;
        }
        m_pCamera = 0;
    }
    m_24c = true;
}
MS2_REPLACE_METHOD(0x140AEAD90, CameraMgr, FUN_140aead90, 412, 0x47BE805D);

// @0x140aeaf40
void CameraMgr::FUN_140aeaf40(Unk_CameraTargetEntity* pTarget, int n)
{
    if (m_spMode.IsNull())
        return;
    if (m_1b0 && !m_1a8)
    {
        if (m_pTarget)
        {
            Unk_CameraActor* pOld = FUN_1409ffd30(m_pTarget);
            if (pOld)
                pOld->FUN_1416781a0(0);
        }
        m_pTarget = pTarget;
        m_spMode->vfunc_24(pTarget, n);
        Unk_CameraActor* pActor = FUN_1409ffd30(pTarget);
        if (pActor)
            pActor->FUN_1416781a0(m_spMode->vfunc_1());
    }
}
MS2_REPLACE_METHOD(0x140AEAF40, CameraMgr, FUN_140aeaf40, 293, 0x48172D4F);

// @0x140aeb070
BOOL CameraMgr::FUN_140aeb070()
{
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    if (pSurface && m_pCamera)
    {
        float fValue = FUN_141bcfc50(FUN_1403ed2d0());
        FUN_140ad4ff0(fValue);
        FUN_1413f9910()->SetActiveCamera(m_pCamera->FUN_140af7fd0(), pSurface->GetWindowRef());
        ecr::CameraData* pData = FUN_1413f9910()->GetActiveCamera(pSurface);
        if (pData)
            pSurface->SetCamera(pData->GetCamera());
        if (FUN_1417e2610(FUN_140aa6d30()) != 0x6200009)
        {
            FUN_140af9c10(1);
            FUN_140af9930(FUN_140869420());
        }
        return TRUE;
    }
    return FALSE;
}

// @0x140aeb420
void CameraMgr::FUN_140aeb420(int nMode, const Unk_CameraFlyBy* pFlyBy)
{
    if (FUN_140af7e30() != nMode)
    {
        int nNewMode = nMode;
        Unk_CameraSetting setting;
        setting.m_0 = FUN_140ad4b40();
        setting.m_4 = FUN_140af7f00();
        setting.m_8 = FUN_140af7ea0();
        setting.m_18 = FUN_140af8290();
        setting.m_c = FUN_140a17e10();
        FUN_140aed720(setting);
        if (pFlyBy)
            FUN_140aed580(pFlyBy, 1, 1.0f);
        FUN_140aed750(nNewMode, 0);
    }
}
MS2_REPLACE_METHOD(0x140AEB420, CameraMgr, FUN_140aeb420, 273, 0xDEF55E1E);

// @0x140aeb600
void CameraMgr::FUN_140aeb600()
{
    if (FUN_140af2520())
        m_278 = FUN_140af2520()->vfunc_27();
    else
        m_278 = 0;
    FUN_140af7be0(1);
    FUN_140aed1c0();
    if (m_spTargetMode.get())
    {
        CTargetCameraMode* pTargetMode = (CTargetCameraMode*)(CCameraMode*)m_spTargetMode;
        pTargetMode->FUN_14183e040();
    }
    m_entitySetups.RemoveAll();
    m_setups.clear();
    m_290.clear();
    if (m_spMapCameraData.get())
        m_spMapCameraData = 0;
    m_27c = false;
}
MS2_REPLACE_METHOD(0x140AEB600, CameraMgr, FUN_140aeb600, 291, 0xF6F2FCD1);

// @0x140aeb730
void CameraMgr::FUN_140aeb730(efd::Point3 ptPos)
{
    if (m_spMode.IsNull())
        return;
    FUN_140aed750(2, 1);
    efd::Point3 kPos = ptPos;
    m_spTargetObject->vfunc_19(kPos);
    FUN_140af9ab0(0, 0);
    FUN_140aeaf40((Unk_CameraTargetEntity*)(GameObject*)m_spTargetObject, 1);
    m_1a8 = 1;
}
MS2_REPLACE_METHOD(0x140AEB730, CameraMgr, FUN_140aeb730, 235, 0x84E79E9E);

// @0x140aeb830
void CameraMgr::FUN_140aeb830(int n)
{
    if (FUN_140af7e30() == 2)
    {
        CTargetCameraMode* pMode = (CTargetCameraMode*)m_spMode.get();
        pMode->FUN_14183c350(n);
    }
}
MS2_REPLACE_METHOD(0x140AEB830, CameraMgr, FUN_140aeb830, 71, 0x452B0FAA);

// @0x140aeb880
void CameraMgr::FUN_140aeb880(float f1, float f2, float f3)
{
    if (m_spMode.get())
        m_spMode->vfunc_29(f1, f2, f3);
}
MS2_REPLACE_METHOD(0x140AEB880, CameraMgr, FUN_140aeb880, 117, 0x36F37293);

// @0x140aeb900
void CameraMgr::FUN_140aeb900(bool b)
{
    m_24c = b;
}
MS2_REPLACE_METHOD(0x140AEB900, CameraMgr, FUN_140aeb900, 26, 0xF4636BF7);

// @0x140aeb920
void CameraMgr::FUN_140aeb920()
{
    m_290.clear();
}
MS2_REPLACE_METHOD(0x140AEB920, CameraMgr, FUN_140aeb920, 33, 0x8BE54FF6);

// @0x140aed580
void CameraMgr::FUN_140aed580(const Unk_CameraFlyBy* pFlyBy, int nKind, float fDuration)
{
    m_bFlyBy = nKind != 0;
    if (pFlyBy)
        m_flyBy = *pFlyBy;
    else
    {
        m_flyBy.m_nKind = nKind;
        m_flyBy.m_fDuration = fDuration;
        if (m_spMode.get())
        {
            m_flyBy.m_from.m_0 = m_spMode->FUN_140ad4b30();
            m_flyBy.m_from.m_4 = m_spMode->FUN_140af7ef0();
            m_flyBy.m_from.m_8 = m_spMode->FUN_140af7e90();
            m_flyBy.m_from.m_18 = m_spMode->FUN_140af8260();
            m_flyBy.m_from.m_c = m_spMode->FUN_1409f2540();
            m_flyBy.m_from.m_24 = m_spMode->FUN_140af8140();
        }
    }
}
MS2_REPLACE_METHOD(0x140AED580, CameraMgr, FUN_140aed580, 402, 0x74173750);

// @0x140aeb1a0
void CameraMgr::FUN_140aeb1a0()
{
    if (m_spMode.get())
        m_spMode->vfunc_30();
    if (FUN_14116d720(FUN_14025e7c0()))
    {
        float fX, fY;
        FUN_141b90e30(FUN_140aadf80(), &fX, &fY);
        Unk_GoPickListPtr spPick = FUN_140af0850(fX, fY, true, true, false, 0);
        if (!spPick.FUN_140a16c00())
            return;
        Unk_GameContext* pContext = FUN_1403ed2d0();
        GameObject* pNpc = 0;
        for (unsigned int i = 0; i < FUN_140a17e00(spPick.FUN_140a16c30())->FUN_140a17ea0(); ++i)
        {
            Unk_GoPickHit* pHit = FUN_140a17e00(spPick.FUN_140a16c30())->FUN_140a17d70(i);
            Unk_CameraPickObject* pObject = FUN_141bd1050(pContext, FUN_140a17cb0(pHit));
            pNpc = pObject->FUN_140a38a00();
            if (pNpc)
                break;
        }
        if (pNpc)
        {
            UINpcControlDialog* pDialog = Unk_CameraDialog<UINpcControlDialog>(0x4e81);
            if (pDialog)
            {
                FUN_1403ed2b0()->FUN_141adc5d0(0x4e81);
                pDialog->FUN_141a638c0(pNpc->FUN_14123c580());
                FUN_1403ed2b0()->FUN_141adc530(0x4e81);
                COutPacket packet(0x50, 0);
                packet.vfunc_o10_1(4);
                packet.vfunc_o10_3(pNpc->FUN_14123c580());
                packet.vfunc_o10_1(0);
                FUN_140710590(packet);
            }
        }
    }
}

// @0x140af0850
Unk_GoPickListPtr CameraMgr::FUN_140af0850(float fX, float fY, bool bFrontOnly, bool bAppCulled, bool bClosestOnly,
    NiAVObject* pRoot)
{
    if (!FUN_1413f9890())
        return Unk_GoPickListPtr(0);
    NiPoint3 kOrigin;
    NiPoint3 kDir;
    NiCamera* pCamera = FUN_1413f9890()->GetActiveRenderSurface()->GetCamera();
    pCamera->WindowPointToRay((long)fX, (long)fY, kOrigin, kDir);
    ecr::PickService* pPick = FUN_1403ed2d0()->FUN_140af8310()->GetSystemServiceAs<ecr::PickService>();
    if (pPick)
    {
        if (!pRoot)
        {
            Unk_GoPickListPtr spPick(pPick->PerformPick(kOrigin, kDir, bFrontOnly, bAppCulled, bClosestOnly));
            return spPick;
        }
        else
        {
            Unk_GoPickListPtr spPick(pPick->PerformPick(kOrigin, kDir, pRoot, bFrontOnly, bAppCulled, bClosestOnly));
            return spPick;
        }
    }
    return Unk_GoPickListPtr(0);
}
MS2_REPLACE_METHOD(0x140AF0850, CameraMgr, FUN_140af0850, 569, 0xA62206A5);

// @0x140aec8a0
void CameraMgr::FUN_140aec8a0(bool bKeep)
{
    if (!FUN_140a18070() || m_spMapCameraData.IsNull())
        return;
    {
        FUN_140aeb920();
        FUN_140aed260();
        FUN_140af9b40(m_spMapCameraData->m_distance);
        FUN_140af9870(m_spMapCameraData->m_hAngle);
        FUN_140af98d0(m_spMapCameraData->m_vAngle);
        FUN_140af9ab0(m_spMapCameraData->m_zoomOutHeightOffset, m_spMapCameraData->m_zoomInHeightOffset);
        if (m_spMapCameraData->m_30 && !bKeep)
        {
            Unk_CameraSetting setting;
            setting.m_0 = FUN_140ad4b40();
            setting.m_4 = FUN_140af7f00();
            setting.m_8 = FUN_140af7ea0();
            setting.m_18 = FUN_140af8290();
            setting.m_c = FUN_140a17e10();
            FUN_140aed720(setting);
            FUN_140aed580(0, 0, 1.0f);
            FUN_140aed750(m_spMapCameraData->m_18, 1);
            CCameraMode* pMode = FUN_140af2520();
            if (pMode)
                pMode->vfunc_36(reinterpret_cast<Unk_CameraPreset*>((CMapCameraData*)m_spMapCameraData));
        }
        MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (spField->m_nUseDummyTarget)
            FUN_140aeb730(reinterpret_cast<const efd::Point3&>(spField->m_vecDummyTargetPos));
    }
}
MS2_REPLACE_METHOD(0x140AEC8A0, CameraMgr, FUN_140aec8a0, 764, 0xB83CC38A);

// @0x140aecbb0
// MS2-FUNCTIONAL: one byte differs that the instruction diff does not show (same instruction stream).
void CameraMgr::FUN_140aecbb0(int nId, int nTargetId, bool bEnter)
{
    if (!nId)
        return;
    bool bHasTarget = nTargetId != 0;
    {
        for (POSITION pos = m_entitySetups.GetHeadPosition(); pos; m_entitySetups.GetNext(pos))
        {
            Unk_CameraSetup& setup = m_entitySetups.GetValueAt(pos);
            if (setup.m_28 == 2 && setup.m_2c == nId)
            {
                CTargetCameraMode* pTarget = 0;
                if (FUN_140af7e30() == 2)
                    pTarget = static_cast<CTargetCameraMode*>(FUN_140af24f0());
                if (pTarget)
                    pTarget->FUN_14183cc80(1);
                if (bEnter)
                {
                    Unk_CameraSetting* pSetting = FUN_140947880(FUN_140af2520());
                    FUN_140aed580(0, 0, 0);
                    FUN_140aed720(*pSetting);
                    FUN_140aed750(0x10, 1);
                    FUN_140aed1e0(setup);
                    if (bHasTarget)
                    {
                        Unk_CameraTargetEntity* pNpc = FUN_141bd1200(FUN_1403ed2d0(), nTargetId);
                        if (pNpc)
                        {
                            FUN_140aeaf40(pNpc, 1);
                            FUN_141bdb5a0(FUN_1403ed2d0(), 1);
                        }
                        FUN_141bd9e60(FUN_1403ed2d0(), 1.0f, 0, setup.m_3c, nTargetId);
                        m_27c = true;
                    }
                    return;
                }
                m_27c = false;
                FUN_140aeb920();
                FUN_140aed260();
                FUN_140aeaf40(FUN_141bd0cc0(FUN_1403ed2d0()), 1);
                FUN_141bdb5a0(FUN_1403ed2d0(), 0);
                if (pTarget)
                    pTarget->FUN_14183cc80(0);
                FUN_141bda050(FUN_1403ed2d0(), 1.0f, nTargetId);
                return;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140AECBB0, CameraMgr, FUN_140aecbb0, 653, 0xE8ACA87A);

// @0x140aece50
void CameraMgr::FUN_140aece50()
{
    if (!m_24c)
        return;
    if (m_entitySetups.IsEmpty())
        return;
    if (FUN_140aed3a0())
        return;
    if (!FUN_140aed4b0())
        return;
    Unk_CameraTargetEntity* pTarget = FUN_140a38d60();
    if (!pTarget)
        return;
    {
        for (POSITION pos = m_entitySetups.GetHeadPosition(); pos; m_entitySetups.GetNext(pos))
        {
            Unk_CameraSetup& setup = m_entitySetups.GetValueAt(pos);
            bool bHit = false;
            if (setup.m_28 == 1)
            {
                float fDist = pTarget->vfunc_18().FUN_140965c40(setup.m_setting.m_c).FUN_140967ac0();
                if (fDist <= setup.m_30)
                    bHit = true;
            }
            else if (setup.m_28 == 3)
            {
                if (FUN_141863100(FUN_140ad4b90(), setup.m_34, pTarget->vfunc_18()))
                    bHit = true;
            }
            if (bHit)
            {
                Unk_CameraSetting* pSetting = FUN_140947880(FUN_140af2520());
                FUN_140aed580(0, 0, 0);
                FUN_140aed720(*pSetting);
                FUN_140aed750(0x10, 1);
                FUN_140aed1e0(setup);
                return;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140AECE50, CameraMgr, FUN_140aece50, 587, 0x127E1FEB);

// @0x140aefa70
void CameraMgr::FUN_140aefa70()
{
    if (FUN_1422b9dc0(FUN_1408e57f0()) == 0x620000c && FUN_140af7e30() == 2 && m_spMode.get())
    {
        m_240 = !m_240;
        m_spMode->vfunc_33();
    }
}
MS2_REPLACE_METHOD(0x140AEFA70, CameraMgr, FUN_140aefa70, 167, 0xD7F55506);

// @0x140aeffd0
Unk_CameraFlyBy CameraMgr::FUN_140aeffd0(float fDuration, const Unk_CameraSetting& to)
{
    Unk_CameraFlyBy flyBy;
    flyBy.m_nKind = 1;
    flyBy.m_fDuration = fDuration;
    flyBy.m_to.m_0 = to.m_0;
    flyBy.m_to.m_4 = to.m_4;
    flyBy.m_to.m_8 = to.m_8;
    flyBy.m_to.m_18 = to.m_18;
    flyBy.m_to.m_c = to.m_c;
    flyBy.m_to.m_24 = to.m_24;
    flyBy.m_from.m_0 = FUN_140ad4b40();
    flyBy.m_from.m_4 = FUN_140af7f00();
    flyBy.m_from.m_8 = FUN_140af7ea0();
    flyBy.m_from.m_18 = FUN_140af8290();
    flyBy.m_from.m_c = FUN_140a17e10();
    flyBy.m_from.m_24 = FUN_140af81a0();
    return flyBy;
}
MS2_REPLACE_METHOD(0x140AEFFD0, CameraMgr, FUN_140aeffd0, 359, 0xB27E2A7B);

// @0x140aed0b0
bool CameraMgr::FUN_140aed0b0()
{
    return m_27c;
}
MS2_REPLACE_METHOD(0x140AED0B0, CameraMgr, FUN_140aed0b0, 18, 0x468B77E7);

// @0x140aed0d0
bool CameraMgr::FUN_140aed0d0()
{
    return m_24c;
}
MS2_REPLACE_METHOD(0x140AED0D0, CameraMgr, FUN_140aed0d0, 18, 0x05E822F7);

// @0x140aed0f0
int CameraMgr::FUN_140aed0f0()
{
    if (FUN_1409a8b10()->FUN_140af7de0())
        return m_244 && FUN_1409a8b10()->FUN_140af7de0()->m_1;
    return m_244;
}
MS2_REPLACE_METHOD(0x140AED0F0, CameraMgr, FUN_140aed0f0, 102, 0xB56490FF);

// @0x140aed160
int CameraMgr::FUN_140aed160()
{
    return m_248;
}
MS2_REPLACE_METHOD(0x140AED160, CameraMgr, FUN_140aed160, 17, 0xA0573195);

// @0x140aed180
void CameraMgr::FUN_140aed180(const Unk_CameraSetting& setting)
{
    m_248 = 1;
    m_savedSetting = setting;
}
MS2_REPLACE_METHOD(0x140AED180, CameraMgr, FUN_140aed180, 58, 0x998E010E);

// @0x140aed1c0
void CameraMgr::FUN_140aed1c0()
{
    m_248 = 0;
}
MS2_REPLACE_METHOD(0x140AED1C0, CameraMgr, FUN_140aed1c0, 21, 0x083B27E9);

// @0x140aed1e0
void CameraMgr::FUN_140aed1e0(const Unk_CameraSetup& setup)
{
    if (FUN_140af7e30() == 0x10)
    {
        CLocalTargetCameraMode* pMode = dynamic_cast<CLocalTargetCameraMode*>(m_spMode.get());
        if (pMode)
            pMode->FUN_140d4f680(setup);
    }
}
MS2_REPLACE_METHOD(0x140AED1E0, CameraMgr, FUN_140aed1e0, 113, 0xF89809BE);

// @0x140aed260
void CameraMgr::FUN_140aed260()
{
    if (FUN_140af7e30() == 0x10)
    {
        CLocalTargetCameraMode* pMode = dynamic_cast<CLocalTargetCameraMode*>(m_spMode.get());
        if (pMode)
        {
            FUN_140aed580(0, 0, 0);
            int nMode = 2;
            if (pMode->FUN_140af8230())
                nMode = pMode->FUN_140af8230();
            FUN_140aed720(pMode->FUN_140af8210());
            FUN_140aed750(nMode, 1);
        }
    }
}
MS2_REPLACE_METHOD(0x140AED260, CameraMgr, FUN_140aed260, 194, 0x89DFCF1E);

// @0x140aed330
void CameraMgr::FUN_140aed330()
{
    if (FUN_140af7e30() == 0x10)
    {
        CLocalTargetCameraMode* pMode = dynamic_cast<CLocalTargetCameraMode*>(m_spMode.get());
        if (pMode)
            pMode->FUN_140d4f830();
    }
}
MS2_REPLACE_METHOD(0x140AED330, CameraMgr, FUN_140aed330, 103, 0x74F9C16A);

// @0x140aed3a0
BOOL CameraMgr::FUN_140aed3a0()
{
    return FUN_140af7e30() == 0x10;
}
MS2_REPLACE_METHOD(0x140AED3A0, CameraMgr, FUN_140aed3a0, 51, 0xAE57711E);

// @0x140aed3e0
bool CameraMgr::FUN_140aed3e0()
{
    if (m_spMode.get())
        return m_spMode->vfunc_34();
    return true;
}
MS2_REPLACE_METHOD(0x140AED3E0, CameraMgr, FUN_140aed3e0, 85, 0x56333F7B);

// @0x140aed440
BOOL CameraMgr::FUN_140aed440(Unk_CameraSetting& setting)
{
    if (m_spMode.get())
    {
        setting = *FUN_140947880(m_spMode.operator->());
        return TRUE;
    }
    return FALSE;
}
MS2_REPLACE_METHOD(0x140AED440, CameraMgr, FUN_140aed440, 92, 0xEDA92935);

// @0x140aed4b0
bool CameraMgr::FUN_140aed4b0()
{
    int nMode = FUN_140af7e30();
    switch (nMode)
    {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140AED4B0, CameraMgr, FUN_140aed4b0, 65, 0x3BCB1AB9);

// @0x140aed500
void CameraMgr::FUN_140aed500(egf::Entity* pEntity, const Unk_CameraSetup& setup)
{
    m_entitySetups.SetAt(pEntity, setup);
}
MS2_REPLACE_METHOD(0x140AED500, CameraMgr, FUN_140aed500, 53, 0x33912F70);

// @0x140aed540
void CameraMgr::FUN_140aed540(egf::Entity* pEntity)
{
    m_entitySetups.RemoveKey(pEntity);
}
MS2_REPLACE_METHOD(0x140AED540, CameraMgr, FUN_140aed540, 43, 0x6AC2B434);

// @0x140af0140
float CameraMgr::FUN_140af0140()
{
    return m_spMode->FUN_140af84b0();
}
MS2_REPLACE_METHOD(0x140AF0140, CameraMgr, FUN_140af0140, 41, 0x9CDA467C);

// @0x140af0170
void CameraMgr::FUN_140af0170(float f, bool b)
{
    if (m_spMode.get())
        m_spMode->FUN_140afe270(f, b);
}
MS2_REPLACE_METHOD(0x140AF0170, CameraMgr, FUN_140af0170, 88, 0x7E78B2A1);

// @0x140af01d0
int CameraMgr::FUN_140af01d0()
{
    if (FUN_1422b9dc0(FUN_1408e57f0()) != 0x620000c)
        return 0;
    return m_240;
}
MS2_REPLACE_METHOD(0x140AF01D0, CameraMgr, FUN_140af01d0, 49, 0x75B8012A);

// @0x140af0210
BOOL CameraMgr::FUN_140af0210()
{
    if (m_d4.FUN_140552690(g_143a08ce8))
        return TRUE;
    return FALSE;
}
MS2_REPLACE_METHOD(0x140AF0210, CameraMgr, FUN_140af0210, 56, 0x229AC15E);

// @0x140af0250
NiPoint3 CameraMgr::FUN_140af0250()
{
    NiPoint3 kResult(NiPoint3::ZERO);
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    if (!pSurface)
        return kResult;
    ecr::CameraData* pData = FUN_1413f9910()->GetActiveCamera(pSurface);
    if (pData)
    {
        NiCamera* pCamera = pData->GetCamera();
        if (!pCamera)
            return kResult;
        return pCamera->GetWorldDirection();
    }
    return kResult;
}
MS2_REPLACE_METHOD(0x140AF0250, CameraMgr, FUN_140af0250, 224, 0x4D4E7969);

// @0x140af0340
NiPoint3 CameraMgr::FUN_140af0340()
{
    NiPoint3 kResult(NiPoint3::ZERO);
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    if (!pSurface)
        return kResult;
    ecr::CameraData* pData = FUN_1413f9910()->GetActiveCamera(pSurface);
    if (pData)
    {
        NiCamera* pCamera = pData->GetCamera();
        if (!pCamera)
            return kResult;
        return pCamera->GetWorldUpVector();
    }
    return kResult;
}
MS2_REPLACE_METHOD(0x140AF0340, CameraMgr, FUN_140af0340, 224, 0x76D3E4C7);

// @0x140af0430
NiPoint3 CameraMgr::FUN_140af0430()
{
    NiPoint3 kResult(NiPoint3::ZERO);
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    if (!pSurface)
        return kResult;
    ecr::CameraData* pData = FUN_1413f9910()->GetActiveCamera(pSurface);
    if (pData)
    {
        NiCamera* pCamera = pData->GetCamera();
        if (!pCamera)
            return kResult;
        return pCamera->GetWorldRightVector();
    }
    return kResult;
}
MS2_REPLACE_METHOD(0x140AF0430, CameraMgr, FUN_140af0430, 224, 0xE650B517);

// @0x140af0520
bool CameraMgr::FUN_140af0520(const NiPoint2& kScreen, NiPoint3& kOrigin, NiPoint3& kDir)
{
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    if (!pSurface)
        return false;
    ecr::CameraData* pData = FUN_1413f9910()->GetActiveCamera(pSurface);
    if (pData)
    {
        NiCamera* pCamera = pData->GetCamera();
        pCamera->WindowPointToRay((long)kScreen.x, (long)kScreen.y, kOrigin, kDir);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140AF0520, CameraMgr, FUN_140af0520, 169, 0x98386F27);

// @0x140af05d0
// MS2-FUNCTIONAL: the argument temporaries are evaluated in a different order.
bool CameraMgr::FUN_140af05d0(const efd::Point3& kWorld, NiPoint2& kScreen)
{
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    if (!pSurface)
        return false;
    ecr::CameraData* pData = FUN_1413f9910()->GetActiveCamera(pSurface);
    if (pData)
    {
        NiCamera* pCamera = pData->GetCamera();
        NiPoint3 kPt(kWorld);
        if (!pCamera->WorldPtToScreenPt(kPt, kScreen.x, kScreen.y))
            return false;
        kScreen.x = kScreen.x * (float)DAT_143af62d4;
        kScreen.y = (1.0f - kScreen.y) * (float)DAT_143af62d8;
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140AF05D0, CameraMgr, FUN_140af05d0, 285, 0xC91CEC8F);

// @0x140af0700
// MS2-FUNCTIONAL: the argument temporaries are evaluated in a different order.
bool CameraMgr::FUN_140af0700(const efd::Point3& kWorld, NiPoint3& kScreen)
{
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    if (!pSurface)
        return false;
    if (!pSurface->GetCamera())
        return false;
    NiPoint3 kPt(kWorld);
    if (!pSurface->GetCamera()->WorldPtToScreenPt3(kPt, kScreen.x, kScreen.y, kScreen.z))
        return false;
    kScreen.z = kScreen.z;
    kScreen.x = kScreen.x * (float)DAT_143af62d4;
    kScreen.y = (1.0f - kScreen.y) * (float)DAT_143af62d8;
    return true;
}
MS2_REPLACE_METHOD(0x140AF0700, CameraMgr, FUN_140af0700, 326, 0xB52FC068);

// @0x140af0aa0
// MS2-FUNCTIONAL: the NiPoint3 local sits at +0x30 instead of +0x2c.
bool CameraMgr::FUN_140af0aa0(const efd::Point3& kPos, float fRadius)
{
    unsigned int i;
    for (i = 0; i < 6; i++)
    {
        if (m_frustumPlanes.IsPlaneActive(i))
        {
            NiPoint3 kPt(kPos);
            float fDist = m_frustumPlanes.GetPlane(i).Distance(kPt);
            if (fDist <= -fRadius)
                break;
        }
    }
    return i == 6;
}
MS2_REPLACE_METHOD(0x140AF0AA0, CameraMgr, FUN_140af0aa0, 200, 0x268A971E);

// @0x140af0b70
void CameraMgr::FUN_140af0b70(int bOn, float f1, float f2)
{
    if (m_1b4 != bOn)
    {
        if (bOn)
        {
            m_1b4 = 1;
            m_1b8 = 0;
            Unk_CameraPostEffect* pEffect = FUN_1416aad00(FUN_1409a8b20());
            if (pEffect)
                pEffect->FUN_1411780e0(f1, f2);
        }
        else
            m_1b8 = 1;
    }
}
MS2_REPLACE_METHOD(0x140AF0B70, CameraMgr, FUN_140af0b70, 149, 0x153DB306);

// @0x140af0c10
void CameraMgr::FUN_140af0c10()
{
    if (m_spMode.get())
        m_spMode->vfunc_31();
}
MS2_REPLACE_METHOD(0x140AF0C10, CameraMgr, FUN_140af0c10, 81, 0x9D6D4FD2);

// @0x140af0c70
float CameraMgr::FUN_140af0c70()
{
    if (m_spMode.get())
        return m_spMode->FUN_140afe300();
    return 0;
}
MS2_REPLACE_METHOD(0x140AF0C70, CameraMgr, FUN_140af0c70, 70, 0x0E0EB65A);

// @0x140af0cc0
void CameraMgr::FUN_140af0cc0(float f)
{
    if (m_spMode.get())
        m_spMode->vfunc_32(f);
}
MS2_REPLACE_METHOD(0x140AF0CC0, CameraMgr, FUN_140af0cc0, 93, 0xDE20C476);

// @0x140af0d30
float CameraMgr::FUN_140af0d30()
{
    if (m_spMode.get())
        return m_spMode->FUN_140afe2e0();
    return 0;
}
MS2_REPLACE_METHOD(0x140AF0D30, CameraMgr, FUN_140af0d30, 70, 0x04390A9B);

// @0x140af0d80
bool CameraMgr::FUN_140af0d80()
{
    if (m_spMode.get())
        return m_spMode->vfunc_2();
    return true;
}
MS2_REPLACE_METHOD(0x140AF0D80, CameraMgr, FUN_140af0d80, 82, 0xF0B9FF19);

// @0x140af0de0
void CameraMgr::FUN_140af0de0(MS2Ptr<CCameraEffect> spEffect)
{
    if (FUN_140aed0f0())
        m_effect.m_effects.push_back(spEffect);
}
MS2_REPLACE_METHOD(0x140AF0DE0, CameraMgr, FUN_140af0de0, 77, 0x76D3945A);

// @0x140af1a90
// MS2-FUNCTIONAL: the exe materializes `m_248 && m_spMode.get()` straight into a byte temp; this build goes through
// a dword temp first.
void CameraMgr::FUN_140af1a90()
{
    m_effect.m_pCamera = 0;
    FUN_140a0b2a0(m_effect.m_spCameraNode);
    m_effect.m_spCameraNode = 0;
    m_effect.m_spFOV = 0;
    m_effect.m_spScene = 0;
    m_effect.m_fStart = 0;
    m_effect.m_20 = 0;
    m_effect.m_ptOffset = g_143b01a60;
    m_effect.m_fMaxTime = 0;
    m_effect.m_24 = 0;
    m_effect.m_28 = 0;
    for (std::list<MS2Ptr<CCameraEffect>>::iterator it = m_effect.m_effects.begin(); it != m_effect.m_effects.end(); ++it)
        it->Reset();
    m_effect.m_effects.clear();
    bool bRestore = m_248 && m_spMode.get();
    if (bRestore)
    {
        m_spMode->vfunc_11(m_savedSetting.m_0);
        m_spMode->FUN_140af99d0(m_savedSetting.m_4);
        m_spMode->FUN_140af9950(m_savedSetting.m_8);
        m_spMode->vfunc_4(m_savedSetting.m_18);
        m_spMode->vfunc_3(m_savedSetting.m_c);
        m_spMode->vfunc_5(m_savedSetting.m_24);
    }
}
MS2_REPLACE_METHOD(0x140AF1A90, CameraMgr, FUN_140af1a90, 833, 0xCA1747D0);

// @0x140af1de0
void CameraMgr::FUN_140af1de0()
{
    double fTime = FUN_141473280(FUN_14086d260());
    Unk_StreamPoint ptLook = FUN_140a17e10();
    Unk_StreamPoint ptUp = FUN_140af8290();
    if (!m_effect.m_effects.empty())
    {
        if ((*m_effect.m_effects.begin())->vfunc_1(fTime, ptLook, ptUp))
        {
            m_spMode->vfunc_3(ptLook);
        }
        else
        {
            m_effect.m_effects.erase(m_effect.m_effects.begin());
            if (m_effect.m_effects.empty())
                FUN_140af1a90();
        }
    }
}
MS2_REPLACE_METHOD(0x140AF1DE0, CameraMgr, FUN_140af1de0, 384, 0xD74FB37A);

// @0x140aeb540
void CameraMgr::FUN_140aeb540(const egf::EntityID& id, const Unk_CameraSetting& setting)
{
    m_savedSettings.insert(std::make_pair(id, setting));
}
MS2_REPLACE_METHOD(0x140AEB540, CameraMgr, FUN_140aeb540, 72, 0x5A5304A2);

// @0x140aeb590
bool CameraMgr::FUN_140aeb590(Unk_CameraSetting& setting)
{
    if (m_savedSettings.empty())
        return false;
    setting = m_savedSettings.begin()->second;
    return true;
}
MS2_REPLACE_METHOD(0x140AEB590, CameraMgr, FUN_140aeb590, 100, 0x16344786);

// @0x140aeb950
// MS2-FUNCTIONAL: std::map<int,int>::operator[] binds to an ambiguous exe COMDAT (0x1403e8960 vs 0x140447ef0).
void CameraMgr::FUN_140aeb950(CLocalTargetCameraMode* pMode)
{
    if (pMode)
    {
        if (pMode->FUN_140af8600())
        {
            if (FUN_1401d1320(&m_mapCache))
            {
                m_setups.clear();
                m_290.clear();
                FUN_140aec0e0(FUN_141bd3060(FUN_1403ed2d0()));
            }
            DWORD nId = pMode->FUN_140af7e10();
            std::vector<Unk_CameraSetup>& setups = m_setups[nId];
            if (!setups.empty())
            {
                unsigned int nIndex = 0;
                std::map<DWORD, DWORD>::iterator it = m_290.find(nId);
                if (it == m_290.end())
                {
                    nIndex = 1;
                    m_290[nId] = nIndex;
                }
                else
                {
                    nIndex = it->second + 1;
                    m_290[nId] = nIndex;
                }
                if (nIndex >= setups.size())
                {
                    nIndex = 0;
                    m_290[nId] = 0;
                }
                pMode->FUN_140d4fa60(setups[nIndex]);
            }
        }
    }
}

// @0x140aec0e0
// MS2-FUNCTIONAL: the frame is 8 bytes off.
void CameraMgr::FUN_140aec0e0(unsigned int nMapId)
{
    CString strPath;
    strPath.Format("%s/%08d.xml", (const char*)FUN_14071a5b0("Camera", "Map"), nMapId);
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return;
    m_mapCache.FUN_1401d1160(strPath);
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (!pRoot)
        return;
    for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("localTargetCamera"); pElem;
         pElem = pElem->FUN_140168650("localTargetCamera"))
    {
        int nId = 0;
        FUN_140873220(pElem, "id", &nId);
        if (!nId)
            continue;
        bool bFound = false;
        Unk_CameraSetup setup;
        for (POSITION pos = m_entitySetups.GetHeadPosition(); pos; m_entitySetups.GetNext(pos))
        {
            Unk_CameraSetup& entry = m_entitySetups.GetValueAt(pos);
            if (entry.m_2c == nId)
            {
                bFound = true;
                setup = entry;
                std::vector<Unk_CameraSetup>& setups = m_setups[nId];
                if (setups.empty())
                    setups.push_back(entry);
            }
        }
        if (bFound)
        {
            FUN_140873360(pElem, "fov", &setup.m_setting.m_0);
            FUN_140874670(pElem, "rotation", &setup.m_setting.m_18);
            FUN_140873360(pElem, "targetDistance", &setup.m_38);
            FUN_140874670(pElem, "offsetPosition", &setup.m_40);
            m_setups[nId].push_back(setup);
        }
    }
}

// @0x140af8080
static CString FUN_140af8080()
{
    return s_strGameplayCamera;
}

// @0x140af80c0
CString CameraMgr::FUN_140af80c0()
{
    return FUN_140af8080();
}
MS2_REPLACE_METHOD(0x140AF80C0, CameraMgr, FUN_140af80c0, 53, 0xA77BD198);

// @0x140aec4c0
// MS2-FUNCTIONAL: the exe stages the entity argument of FUN_1411cf2d0 through rcx (mov rcx,[x]; mov rdx,rcx), we load rdx directly.
void CameraMgr::FUN_140aec4c0()
{
    if (FUN_140af7f70() == 0)
    {
        FUN_140aeb920();
        FUN_140aed260();
        FUN_140aebb30(FUN_141bd3060(FUN_1403ed2d0()));
        egf::EntityID id = egf::EntityIDFactory::GetNextID();
        egf::EntityPtr spEntity = FUN_1409670f0()->FUN_1411cec80((const char*)FUN_140af80c0(), id, true);
        if (FUN_1408a9090(&spEntity) != 0)
        {
            float fDistance = m_spMapCameraData->m_distance;
            float fHAngle = ((m_spMapCameraData->m_hAngle + 180.0f) * 3.1415927f) / 180.0f;
            float fVAngle = (m_spMapCameraData->m_vAngle * 3.1415927f) / 180.0f;
            Unk_StreamPoint ptAt = FUN_1403ed2d0()->FUN_141bd3dc0();
            ptAt.z += m_278 + 25.0f;
            Unk_StreamPoint ptEye;
            ptEye.x = fDistance * FUN_1409f25a0(fHAngle) + ptAt.x;
            ptEye.y = fDistance * FUN_1409f2310(fHAngle) + ptAt.y;
            ptEye.z = fDistance * FUN_1409f2310(fVAngle) + ptAt.z;
            Unk_StreamPoint ptRot = CCameraMode::FUN_140afdd40(ptAt, ptEye, g_143a08cf8);
            FUN_140ae9ed0(FUN_1408a9090(&spEntity), &ptEye, &ptRot);
            egf::Entity* pEntity = FUN_1408a9090(&spEntity);
            FUN_1409670f0()->FUN_1411cf2d0(pEntity, 0);
        }
        float fSpeed = (float)FUN_1409a8b10()->FUN_140af7de0()->m_4 / 100.0f;
        float f1 = FUN_1401d3200()->m_kCameraSpeed1.FUN_140298f40() * fSpeed;
        float f2 = FUN_1401d3200()->m_kCameraSpeed2.FUN_140298f40() * fSpeed;
        float f3 = FUN_1401d3200()->m_kCameraSpeed3.FUN_140298f40() * fSpeed;
        FUN_140aeb880(f1, f2, f3);
    }
}
MS2_REPLACE_METHOD(0x140AEC4C0, CameraMgr, FUN_140aec4c0, 971, 0xEBD98476);

// @0x140aebb30
void CameraMgr::FUN_140aebb30(unsigned int nMapId)
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0)
        return;
    m_spMapCameraData.AssignRaw(new CMapCameraData());
    m_spMapCameraData->m_30 = spField->m_bUseFileSetting;
    m_spMapCameraData->m_distance = spField->m_fCameraDistance;
    m_spMapCameraData->m_vAngle = spField->m_fCameraVAngle;
    m_spMapCameraData->m_hAngle = spField->m_fCameraHAngle;
    m_spMapCameraData->m_zoomOutHeightOffset = spField->m_fZoomOutHeightOffset;
    m_spMapCameraData->m_zoomInHeightOffset = spField->m_fZoomInHeightOffset;
    if (!m_spMapCameraData->m_30)
        return;
    CString strPath;
    strPath.Format("%s/%08d.xml", (const char*)FUN_14071a5b0("Camera", "Map"), nMapId);
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return;
    m_mapCache.FUN_1401d1160(strPath);
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (!pRoot)
        return;
    Unk_140165cf0* pElem = pRoot->FUN_140165cf0("defaultCamera");
    if (pElem)
    {
        CString strType;
        const char* pszType = FUN_14086f4b0(pElem, "type");
        if (pszType)
        {
            strType = pszType;
            strType.MakeLower();
            if (strType == "bosstarget")
            {
                m_spMapCameraData.AssignRaw(new CBossTargetCameraData(*m_spMapCameraData.get()));
                m_spMapCameraData->m_18 = 0x12;
                m_spMapCameraData->vfunc_1(pElem);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140AEBB30, CameraMgr, FUN_140aebb30, 1440, 0x461DF218);

// @0x140aea7f0
// The developer camera keys: F4+Ctrl toggles the studio camera, F5+Shift rereads TestCamerValue.xml, F6+Ctrl cycles
// the camera modes.
void CameraMgr::FUN_140aea7f0()
{
    static int s_bStudioCamera;
    static int s_nDebugMode;
    if (m_spMode.IsNull())
        return;
    int nState = 0xb;
    if (FUN_14116d7a0(FUN_14025e7c0(), nState))
        return;
    m_spMode->vfunc_9();
    bool bAllowed = true;
    if (DAT_143ab0248 == 2)
        bAllowed = DAT_143ab2914 >= 52;
    if (bAllowed)
    {
        if (FUN_14116d9c0(FUN_14025e7c0(), 0x3e, true, 0) && FUN_14116d950(FUN_14025e7c0(), 0x1d, true, 0))
        {
            Unk_CameraSetting setting;
            setting.m_0 = FUN_140ad4b40();
            setting.m_4 = FUN_140af7f00();
            setting.m_8 = FUN_140af7ea0();
            setting.m_18 = FUN_140af8290();
            setting.m_c = FUN_140a17e10();
            FUN_140aed720(setting);
            if (s_bStudioCamera == 0)
            {
                { CStringW strMsg(L"Studio Camera Mode"); FUN_1412751b0(strMsg, 0x14); }
                FUN_140aed750(7, 1);
            }
            else
            {
                { CStringW strMsg(L"Target Camera Mode"); FUN_1412751b0(strMsg, 0x14); }
                if (FUN_1409670e0()->FUN_1410d2f10() != 0)
                    FUN_140aed750(0x11, 1);
                else
                    FUN_140aed750(2, 1);
            }
            s_bStudioCamera ^= 1;
            return;
        }
        if (FUN_14116d9c0(FUN_14025e7c0(), 0x3f, true, 0) && FUN_14116d950(FUN_14025e7c0(), 0x2a, true, 0))
        {
            FUN_140af0c10();
            { CStringW strMsg(L"Read Camera value [./data/xml/table/TestCamerValue.xml]"); FUN_1412751b0(strMsg, 0x14); }
            return;
        }
        if (FUN_14116d9c0(FUN_14025e7c0(), 0x40, true, 0) && FUN_14116d950(FUN_14025e7c0(), 0x1d, true, 0))
        {
            int nMode = 2;
            if (++s_nDebugMode == 7)
                s_nDebugMode = 0;
            switch (s_nDebugMode)
            {
            case 0:
                nMode = 2;
                { CStringW strMsg(L"Target Camera Mode"); FUN_1412751b0(strMsg, 0x14); }
                break;
            case 1:
                nMode = 0xd;
                { CStringW strMsg(L"PVP Camera Mode"); FUN_1412751b0(strMsg, 0x14); }
                break;
            case 2:
                nMode = 0xb;
                { CStringW strMsg(L"2D Camera Mode"); FUN_1412751b0(strMsg, 0x14); }
                break;
            case 3:
                nMode = 9;
                { CStringW strMsg(L"TPS Camera Mode"); FUN_1412751b0(strMsg, 0x14); }
                break;
            case 4:
                nMode = 10;
                { CStringW strMsg(L"FPS Camera Mode"); FUN_1412751b0(strMsg, 0x14); }
                break;
            case 5:
                nMode = 0xc;
                { CStringW strMsg(L"RPG Camera Mode"); FUN_1412751b0(strMsg, 0x14); }
                break;
            case 6:
                nMode = 0xe;
                { CStringW strMsg(L"Console Camera Mode"); FUN_1412751b0(strMsg, 0x14); }
                break;
            }
            FUN_140aeb420(nMode, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x140AEA7F0, CameraMgr, FUN_140aea7f0, 1392, 0x0B60B36B);

// @0x140aed750
// Switches the camera mode. During a fly-by request the new mode only becomes the fly-by's destination: its view is
// stored in m_flyBy.m_to and a CFlyByCameraMode that blends into it is installed instead.
void CameraMgr::FUN_140aed750(int nMode, int bKeep)
{
    if (nMode == 3)
        return;
    if (m_spMode == 0)
        return;
    m_nPendingMode = 0;
    int nNewMode = 0;
    if (m_bFlyBy)
    {
        nNewMode = 3;
        m_setting.m_0 = m_spMode->FUN_140ad4b30();
        m_setting.m_4 = m_spMode->FUN_140af7ef0();
        m_setting.m_8 = m_spMode->FUN_140af7e90();
        m_setting.m_18 = m_spMode->FUN_140af8260();
        m_setting.m_c = m_spMode->FUN_1409f2540();
        m_setting.m_24 = m_spMode->FUN_140af8140();
        MS2Ptr<CCameraMode> spNext;
        switch (nMode)
        {
        case 1:
            spNext.AssignRaw(new CFreeCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 2:
            spNext = m_spTargetMode;
            break;
        case 5:
            spNext.AssignRaw(new CActionCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            spNext->vfunc_3(spNext->vfunc_26());
            break;
        case 4:
            spNext.AssignRaw(new CLockCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 6:
            spNext.AssignRaw(new CToolCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 8:
            spNext.AssignRaw(new CEditCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 9:
            spNext.AssignRaw(new CTPSCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 10:
            spNext.AssignRaw(new CFPSCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0xb:
            spNext.AssignRaw(new CTarget2DCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0xc:
            spNext.AssignRaw(new CRPGCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0xd:
            spNext.AssignRaw(new CPVPCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 7:
            spNext.AssignRaw(new CToolSmoothCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0xe:
            spNext.AssignRaw(new CConsoleCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0x10:
            spNext.AssignRaw(new CLocalTargetCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0x11:
            spNext.AssignRaw(new CHomeCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0x12:
            spNext.AssignRaw(new CBossTargetCamera((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        }
        if (bKeep)
        {
            m_flyBy.m_to.m_0 = spNext->FUN_140ad4b30();
            m_flyBy.m_to.m_4 = spNext->FUN_140af7ef0();
            m_flyBy.m_to.m_8 = spNext->FUN_140af7e90();
            m_flyBy.m_to.m_c = spNext->FUN_1409f2540();
            m_flyBy.m_to.m_24 = spNext->FUN_140af8140();
            if (spNext->vfunc_28())
            {
                if (FUN_140a38d60())
                {
                    Unk_StreamPoint ptTarget = FUN_140a38d60()->vfunc_17();
                    ptTarget.z += m_spTargetMode->vfunc_27();
                    if (FUN_140af7e30() == 2)
                        m_flyBy.m_to.m_c = ptTarget.FUN_14097fd50(((CTargetCameraMode*)m_spTargetMode.get())->FUN_14183c370());
                    else if (FUN_140af7e30() == 0x11)
                        m_flyBy.m_to.m_c = ptTarget.FUN_14097fd50(((CHomeCameraMode*)m_spTargetMode.get())->FUN_140b66660());
                }
                else
                    m_flyBy.m_to.m_c = spNext->vfunc_26();
            }
            else
                m_flyBy.m_to.m_c = spNext->vfunc_26();
        }
        if (m_spMode.get())
            m_spMode->vfunc_7();
        m_spMode.AssignRaw(new CFlyByCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode, nMode));
        m_bFlyBy = 0;
    }
    else
    {
        if (m_spMode.get())
            m_spMode->vfunc_7();
        nNewMode = nMode;
        switch (nNewMode)
        {
        case 1:
            m_spMode.AssignRaw(new CFreeCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 2:
            m_spMode = m_spTargetMode;
            m_setting.m_0 = m_spMode->FUN_140ad4b30();
            m_setting.m_4 = m_spMode->FUN_140af7ef0();
            m_setting.m_8 = m_spMode->FUN_140af7e90();
            m_setting.m_18 = m_spMode->FUN_140af8260();
            m_setting.m_c = m_spMode->FUN_1409f2540();
            m_setting.m_24 = m_spMode->FUN_140af8140();
            break;
        case 5:
            m_spMode.AssignRaw(new CActionCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 6:
            m_spMode.AssignRaw(new CToolCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 8:
            m_spMode.AssignRaw(new CEditCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 4:
            m_spMode.AssignRaw(new CLockCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 9:
            m_spMode.AssignRaw(new CTPSCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 10:
            m_spMode.AssignRaw(new CFPSCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0xb:
            m_spMode.AssignRaw(new CTarget2DCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0xc:
            m_spMode.AssignRaw(new CRPGCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0xd:
            m_spMode.AssignRaw(new CPVPCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 7:
            m_spMode.AssignRaw(new CToolSmoothCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0xe:
            m_spMode.AssignRaw(new CConsoleCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0x10:
            m_spMode.AssignRaw(new CLocalTargetCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0x11:
            m_setting.m_0 = m_spMode->FUN_140ad4b30();
            m_setting.m_4 = m_spMode->FUN_140af7ef0();
            m_setting.m_8 = m_spMode->FUN_140af7e90();
            m_setting.m_c = m_homeSetting.m_c;
            m_setting.m_18 = m_homeSetting.m_18;
            m_spMode.AssignRaw(new CHomeCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0x12:
            m_spMode.AssignRaw(new CBossTargetCamera((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        case 0x13:
            m_spMode.AssignRaw(new CTargetLookCenterCameraMode((Unk_CameraOwner*)m_pCamera, m_spMode));
            break;
        }
        m_spMode->vfunc_11(m_setting.m_0);
        m_spMode->FUN_140af99d0(m_setting.m_4);
        m_spMode->FUN_140af9950(m_setting.m_8);
        m_spMode->vfunc_4(m_setting.m_18);
        m_spMode->vfunc_3(m_setting.m_c);
        m_spMode->vfunc_5(m_setting.m_24);
    }
    if (m_spMode.get())
    {
        if (m_1b8)
        {
            if (m_spMode == m_spTargetMode.get())
            {
                m_1b4 = 0;
                m_1b8 = 0;
                Unk_CameraPostEffect* pPostEffect = FUN_1416aad00(FUN_1409a8b20());
                if (pPostEffect)
                    pPostEffect->FUN_1411780e0(m_spMode->FUN_140af7ef0(), m_spMode->FUN_140af7e90());
            }
        }
        m_spMode->vfunc_6(1);
    }
    Unk_CameraActor* pActor = FUN_14099eef0(m_pTarget);
    if (pActor)
        pActor->FUN_1416781a0(nNewMode);
}
MS2_REPLACE_METHOD(0x140AED750, CameraMgr, FUN_140aed750, 8833, 0x311FE950);

// @0x140af0e40
// MS2-FUNCTIONAL: the translate goes through NiPoint3(x, y, z) instead of the exe's point copy helpers.
// Plays the param's camera nif: "Camera01" of the scene animates a "Camera Effect Root" node attached to the effect
// scene root (or to the parent node of the camera target).
void CameraMgr::FUN_140af0e40(const CCameraMoveEffectParam* pParam)
{
    int bAttach = pParam->m_bAttachToNode;
    NiNodePtr spCam = 0;
    NiNodePtr spParent = 0;
    if (bAttach && !FUN_140a38d60())
        return;
    NiNode* pTargetRoot = FUN_141b6efc0(FUN_14123c410(FUN_140a38d60()));
    m_effect.m_spScene = FUN_140a0afd0()->FUN_141551ea0(FUN_140298360("./Data/Resource/Model/Camera/", pParam->m_strFilePath), 0, 5, 0, 0);
    if (m_effect.m_spScene != 0)
    {
        spCam = static_cast<NiNode*>(m_effect.m_spScene->GetObjectByName("Camera01"));
        if (!spCam)
            return;
    }
    else
        return;
    if (m_effect.m_spCameraNode != 0)
    {
        FUN_140af1a90();
        m_effect.m_spCameraNode = 0;
    }
    NiNodePtr spRoot = EE_NEW NiNode;
    spRoot->SetName("Camera Effect Root");
    m_effect.m_spCameraNode = spRoot;
    NiTransform kTransform;
    kTransform.m_Translate = NiPoint3(pParam->m_kTranslate.x, pParam->m_kTranslate.y, pParam->m_kTranslate.z);
    kTransform.m_Rotate.FromEulerAnglesXYZ((pParam->m_kRotation.x * 3.1415927f) / 180.0f,
        (pParam->m_kRotation.y * 3.1415927f) / 180.0f, (pParam->m_kRotation.z * 3.1415927f) / 180.0f);
    kTransform.m_fScale = 1.0f;
    spRoot->SetLocalTransform(kTransform);
    if (pParam->m_bAttachToNode)
    {
        if (!pTargetRoot)
            return;
        spParent = NiDynamicCast(NiNode, pTargetRoot->GetObjectByName((const char*)pParam->m_strParentNode));
        if (spParent == 0)
            spParent = pTargetRoot;
        if (!pParam->m_update.FUN_140afc5a0())
        {
            Unk_SeparateNode* pSeparate = EE_NEW Unk_SeparateNode(pParam->m_update);
            pSeparate->AttachChild(spRoot, false);
            m_effect.m_spCameraNode = pSeparate;
        }
        if (!pParam->m_bApplyNodeTransform)
        {
            bool bParent = spParent ? true : false;
            if (bParent)
            {
                NiTransform kInverse;
                spParent->GetWorldTransform().Invert(kInverse);
                NiTransform kLocal = spRoot->GetLocalTransform();
                m_effect.m_spCameraNode->SetLocalTransform(kInverse * kLocal);
            }
        }
    }
    else
    {
        spParent = FUN_1403ed280()->FUN_1411a6b10();
        NiAVObject* pNode = 0;
        if (pTargetRoot)
            pNode = NiDynamicCast(NiNode, pTargetRoot->GetObjectByName((const char*)pParam->m_strParentNode));
        if (!pNode)
            pNode = pTargetRoot;
        if (pParam->m_bApplyNodeTransform == true && pNode)
        {
            NiTransform kLocal = m_effect.m_spCameraNode->GetLocalTransform();
            m_effect.m_spCameraNode->SetLocalTransform(pNode->GetWorldTransform() * kLocal);
        }
    }
    m_effect.m_28 = bAttach;
    spRoot->AttachChild(spCam, false);
    spParent->AttachChild(m_effect.m_spCameraNode, true);
    m_effect.m_fFOV = FUN_141bcfc50(FUN_1403ed2d0());
    Unk_SceneWalker kWalker(spCam);
    NiAVObject* pObj;
    while ((pObj = kWalker.Next(true)) != 0)
    {
        NiTimeController* pCtrl = pObj->GetControllers();
        while (pCtrl && pCtrl->GetAnimType() == NiTimeController::APP_INIT)
        {
            pCtrl->SetAnimType(NiTimeController::APP_TIME);
            pCtrl = pCtrl->GetNext();
        }
        m_effect.m_pCamera = NiDynamicCast(NiCamera, pObj);
        if (m_effect.m_pCamera)
        {
            NiTimeController* pCamCtrl = m_effect.m_pCamera->GetControllers();
            while (pCamCtrl)
            {
                NiFOVController* pFOV = NiDynamicCast(NiFOVController, pCamCtrl);
                if (pFOV)
                {
                    unsigned short usCount = pFOV->GetInterpolatorCount();
                    for (unsigned short us = 0; us < usCount; us++)
                    {
                        m_effect.m_spFOV = NiDynamicCast(NiFOVInterpolator, pFOV->GetInterpolator(us));
                        if (m_effect.m_spFOV)
                            break;
                    }
                }
                pCamCtrl = pCamCtrl->GetNext();
            }
        }
    }
    if (m_effect.m_spCameraNode)
    {
        m_effect.m_fStart = FUN_141473280(FUN_14086d260()) + pParam->m_fStartDelay;
        NiTimeController* pTime = spCam->GetControllers();
        while (pTime)
        {
            if (pTime->GetEndKeyTime() > m_effect.m_fMaxTime)
                m_effect.m_fMaxTime = pTime->GetEndKeyTime();
            pTime = pTime->GetNext();
        }
        m_effect.m_spCameraNode->Update(0.0f, true);
    }
}
MS2_REPLACE_METHOD(0x140AF0E40, CameraMgr, FUN_140af0e40, 3131, 0xFC2F851F);

// @0x140af1f70
// MS2-FUNCTIONAL: the mode position goes through NiPoint3(x, y, z) instead of the exe's point copy helpers.
// Advances the camera effect nif and drives the active camera from its "Camera01"; stops the effect at its end (or
// when its node was detached) and restores the field of view.
void CameraMgr::FUN_140af1f70()
{
    if (m_effect.m_spCameraNode != 0 && m_effect.m_pCamera)
    {
        if (!m_effect.m_spCameraNode->GetParent())
        {
            m_spMode->vfunc_11(m_effect.m_fFOV);
            FUN_140af1a90();
            FUN_140aeaf40(FUN_141bd0cc0(FUN_1403ed2d0()), 1);
        }
        else
        {
            double dNow = FUN_141473280(FUN_14086d260());
            if (dNow < m_effect.m_fStart)
                return;
            double dTime = dNow - m_effect.m_fStart;
            if (dTime > m_effect.m_fMaxTime)
                dTime = m_effect.m_fMaxTime;
            m_effect.m_spCameraNode->Update((float)dTime, true);
            ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
            ecr::CameraData* pData = FUN_1413f9910()->GetActiveCamera(pSurface);
            NiCamera* pCamera;
            if (pData && (pCamera = pData->GetCamera()) != 0)
            {
                if (m_effect.m_28)
                {
                    NiTransform kEffect = m_effect.m_pCamera->GetWorldTransform();
                    pCamera->SetLocalTransform(kEffect);
                }
                else
                {
                    NiTransform kCamera = pCamera->GetLocalTransform();
                    Unk_StreamPoint ptPos = FUN_140a17e10();
                    kCamera.m_Translate = NiPoint3(ptPos.x, ptPos.y, ptPos.z);
                    Unk_StreamPoint ptRot = FUN_140af8290();
                    kCamera.m_Rotate.FromEulerAnglesXYZ((-ptRot.x * 3.1415927f) / 180.0f,
                        (-ptRot.y * 3.1415927f) / 180.0f, (-ptRot.z * 3.1415927f) / 180.0f);
                    Unk_StreamPoint ptZero = g_143b01a60;
                    NiTransform kNode = m_effect.m_spCameraNode->GetLocalTransform();
                    NiTransform kEffect = m_effect.m_pCamera->GetWorldTransform();
                    NiTransform kAxis;
                    kAxis.m_Rotate.MakeYRotation(1.5707964f);
                    kEffect.m_Rotate = NiMatrix3(kAxis.m_Rotate * kEffect.m_Rotate);
                    float fX = kEffect.m_Translate.x;
                    kEffect.m_Translate.x = -kEffect.m_Translate.z;
                    kEffect.m_Translate.z = fX;
                    kCamera = kCamera * kEffect;
                    pCamera->SetLocalTransform(kCamera);
                }
                if (m_effect.m_spFOV)
                    m_spMode->vfunc_11((static_cast<Unk_FOVInterpolator*>(m_effect.m_spFOV.operator->())->FUN_141c2f230() * 180.0f) / 3.1415927f);
            }
            if (dTime >= m_effect.m_fMaxTime)
            {
                m_spMode->vfunc_11(m_effect.m_fFOV);
                FUN_140af1a90();
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140AF1F70, CameraMgr, FUN_140af1f70, 1388, 0x45606797);

// @0x140aefb20
// MS2-FUNCTIONAL: the node translation is copied through Unk_StreamPoint(x, y, z) instead of the exe's point
// assignment straight from the NiPoint3.
// Plays a camera path nif: its "Camera01" drives the camera directly (no effect root).
void CameraMgr::FUN_140aefb20(const Unk_CameraPathRow* pRow)
{
    m_effect.m_spScene = FUN_140a0afd0()->FUN_141551ea0(FUN_140298360("./Data/Resource/Model/Camera/", pRow->m_strFile), 0, 5, 0, 0);
    if (m_effect.m_spScene)
    {
        m_effect.m_spCameraNode = static_cast<NiNode*>(m_effect.m_spScene->GetObjectByName("Camera01"));
        m_effect.m_fFOV = FUN_141bcfc50(FUN_1403ed2d0());
        Unk_SceneWalker kWalker(m_effect.m_spCameraNode);
        NiAVObject* pObj;
        while ((pObj = kWalker.Next(true)) != 0)
        {
            NiTimeController* pCtrl = pObj->GetControllers();
            while (pCtrl && pCtrl->GetAnimType() == NiTimeController::APP_INIT)
            {
                pCtrl->SetAnimType(NiTimeController::APP_TIME);
                pCtrl = pCtrl->GetNext();
            }
            m_effect.m_pCamera = NiDynamicCast(NiCamera, pObj);
            if (m_effect.m_pCamera)
            {
                NiTimeController* pCamCtrl = m_effect.m_pCamera->GetControllers();
                while (pCamCtrl)
                {
                    NiFOVController* pFOV = NiDynamicCast(NiFOVController, pCamCtrl);
                    if (pFOV)
                    {
                        unsigned short usCount = pFOV->GetInterpolatorCount();
                        for (unsigned short us = 0; us < usCount; us++)
                        {
                            m_effect.m_spFOV = NiDynamicCast(NiFOVInterpolator, pFOV->GetInterpolator(us));
                            if (m_effect.m_spFOV)
                                break;
                        }
                    }
                    pCamCtrl = pCamCtrl->GetNext();
                }
            }
        }
        if (m_effect.m_spCameraNode)
        {
            m_effect.m_24 = pRow->m_c;
            m_effect.m_fStart = 0;
            m_effect.m_20 = pRow->m_f8;
            const NiPoint3& kTranslate = m_effect.m_spCameraNode->GetLocalTransform().m_Translate;
            m_effect.m_ptOffset = Unk_StreamPoint(kTranslate.x, kTranslate.y, kTranslate.z);
            m_effect.m_fMaxTime = 0;
            NiTimeController* pTime = m_effect.m_spCameraNode->GetControllers();
            while (pTime)
            {
                if (pTime->GetEndKeyTime() > m_effect.m_fMaxTime)
                    m_effect.m_fMaxTime = pTime->GetEndKeyTime();
                pTime = pTime->GetNext();
            }
            m_effect.m_spCameraNode->Update(0.0f, true);
        }
    }
}
MS2_REPLACE_METHOD(0x140AEFB20, CameraMgr, FUN_140aefb20, 1189, 0x2179FBDC);
