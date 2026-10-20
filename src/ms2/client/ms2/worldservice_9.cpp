// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService COMDAT tail, sub-unit #9 (owner w529): the last
// slice of the mangled-name-sorted template tail of worldservice.cpp (std::_Tree _Min .. vector::size). The COMDATs are
// instantiated over the real member types (worldservice_real.h) by Unk_WsInst9, which performs the container operations
// the WorldService methods (worldservice_1.cpp) use. 0x141c2eefb-0x141c2efb0 are linker import thunks; the Gamebryo
// interpolator code from 0x141c2efb0 on is engine library code (no RTTI), not part of this CU.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\worldservice.cpp#9
// MS2-RANGE: 0x141c28640-0x141c2efb0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?reserve@?$vector@V?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@QEAAX_K@Z 0x141c2ecb0
// MS2-PIN: ?_Umove_if_noexcept@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@AEAAXPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@2@00@Z 0x141c2a640
// MS2-PIN: ?_Umove_if_noexcept@?$vector@V?$MS2Ptr@VCLiftableObject@@@@V?$allocator@V?$MS2Ptr@VCLiftableObject@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCLiftableObject@@@@00@Z 0x141c2a6a0
// MS2-PIN: ?allocate@?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@QEAAPEAV?$MS2Ptr@VCLiftableTargetBox@@@@_K@Z 0x141c2ac20
// MS2-PIN: ?Release@?$MS2Ptr@VMS2ActorUpdater@@@@AEAAXXZ 0x141c28c80 ; w529: called by the member/local dtor 0x141bf5570
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VMS2ActorUpdater@@@@AEAAXPEAX@Z 0x141c28ee0 ; w529: callee of 0x141c28c80
// MS2-PIN: ?Release@?$MS2Ptr@VRec1f8@WsReal@@@@AEAAXXZ 0x141c28cc0 ; w529: called by the member/local dtor 0x141bf55a0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VRec1f8@WsReal@@@@AEAAXPEAX@Z 0x141c28f30 ; w529: callee of 0x141c28cc0
// MS2-PIN: ?Release@?$MS2Ptr@VRecad0@WsReal@@@@AEAAXXZ 0x141c28d00 ; w529: called by the member/local dtor 0x141bf55d0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VRecad0@WsReal@@@@AEAAXPEAX@Z 0x141c28f80 ; w529: callee of 0x141c28d00
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_WsPtreda80@@@@AEAAXXZ 0x141c28d40 ; w529: called by the member/local dtor 0x141bf5600
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_WsPtreda80@@@@AEAAXPEAX@Z 0x141c28fd0 ; w529: callee of 0x141c28d40
// MS2-PIN: ?Release@?$MS2Ptr@VFieldProperty@@@@AEAAXXZ 0x141c28d80 ; w529: called by the member/local dtor 0x141bf5630
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VFieldProperty@@@@AEAAXPEAX@Z 0x141c29020 ; w529: callee of 0x141c28d80
// MS2-PIN: ?Release@?$MS2Ptr@VRecPtrA@WsReal@@@@AEAAXXZ 0x141c28dc0 ; w529: called by the member/local dtor 0x141bf5660
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VRecPtrA@WsReal@@@@AEAAXPEAX@Z 0x141c29070 ; w529: callee of 0x141c28dc0
// MS2-PIN: ?Release@?$MS2Ptr@VRecPtrB@WsReal@@@@AEAAXXZ 0x141c28e00 ; w529: called by the member/local dtor 0x141bf5690
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VRecPtrB@WsReal@@@@AEAAXPEAX@Z 0x141c290c0 ; w529: callee of 0x141c28e00
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@VVisibleObjectRecord@WsReal@@U?$less@VVisibleObjectRecord@WsReal@@@std@@V?$allocator@VVisibleObjectRecord@WsReal@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VVisibleObjectRecord@WsReal@@@std@@@std@@@2@XZ 0x141c2b040
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@VVisibleObjectRecord@WsReal@@U?$less@VVisibleObjectRecord@WsReal@@@std@@V?$allocator@VVisibleObjectRecord@WsReal@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VVisibleObjectRecord@WsReal@@@std@@@std@@@2@V32@@Z 0x141c2d730
// MS2-PIN: ?push_front@?$list@PEAVEntity@egf@@V?$allocator@PEAVEntity@egf@@@std@@@std@@QEAAXAEBQEAVEntity@egf@@@Z 0x141c2eaf0
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@VVisibleObjectRecord@WsReal@@U?$less@VVisibleObjectRecord@WsReal@@@std@@V?$allocator@VVisibleObjectRecord@WsReal@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VVisibleObjectRecord@WsReal@@@std@@@std@@@2@V32@0@Z 0x141c2d640
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@H@std@@PEAX@2@XZ 0x141c29210
// MS2-PIN: ?begin@?$vector@V?$MS2Ptr@VCLiftableTargetBox@@@@V?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@@std@@@2@XZ 0x141c2b110
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@2@XZ 0x141c2acc0
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@HU?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@H@std@@@4@$0A@@std@@@std@@QEAAXXZ 0x141c2b6e0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@HU?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@H@std@@@std@@@std@@@2@@Z 0x141c2d310
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2e4e0
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@$0A@@std@@@std@@QEBA_KXZ 0x141c2edd0
// MS2-PIN: ?clear@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@QEAAXXZ 0x141c2ba20
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@PEAX@2@PEAU32@@Z 0x141c286a0
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@SAPEAU?$_Tree_node@VEntityID@egf@@PEAX@2@PEAU32@@Z 0x141c28700
// MS2-PIN: ?_Orphan_range@?$vector@V?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@AEBAXPEAV?$MS2Ptr@VMS2ActorUpdater@@@@0@Z 0x141c28b20
// MS2-PIN: ?_Orphan_range@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@AEBAXPEAV?$SmartPointer@VEntity@egf@@@efd@@0@Z 0x141c28b30
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCLiftableTargetBox@@@@V?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCLiftableTargetBox@@@@XZ 0x141c28e80
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VMS2ActorUpdater@@@@XZ 0x141c28ea0
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@QEAAPEAV?$SmartPointer@VEntity@egf@@@efd@@XZ 0x141c28ec0
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@PEAVIWorldServiceCallback@@@std@@@std@@QEAAXPEAU?$_Tree_node@PEAVIWorldServiceCallback@@PEAX@2@@Z 0x141c29390
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@2@@Z 0x141c29470
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@@Z 0x141c297f0
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@PEAX@2@@Z 0x141c298d0
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@@Z 0x141c299b0
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@2@@Z 0x141c29a90
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@QEAAXPEAU?$_Tree_node@VEntityID@egf@@PEAX@2@@Z 0x141c29b70
// MS2-PIN: ?_Umove@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@AEAAPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@2@PEAU32@00@Z 0x141c2a3e0
// MS2-PIN: ?_Umove@?$vector@V?$MS2Ptr@VCLiftableTargetBox@@@@V?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@@std@@AEAAPEAV?$MS2Ptr@VCLiftableTargetBox@@@@PEAV3@00@Z 0x141c2a460
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@AEAAXPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@2@00U?$integral_constant@_N$0A@@2@@Z 0x141c2a4e0
// MS2-PIN: ?_Umove_if_noexcept@?$vector@V?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VMS2ActorUpdater@@@@00@Z 0x141c2a700
// MS2-PIN: ?_Xlength@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@CAXXZ 0x141c2a8f0
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@H@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@H@std@@PEAX@2@_K@Z 0x141c2aa40
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@_K@Z 0x141c2aaa0
// MS2-PIN: ?allocate@?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@QEAAPEAV?$MS2Ptr@VMS2ActorUpdater@@@@_K@Z 0x141c2abf0
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@2@_K@Z 0x141c2bc00
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@_K@Z 0x141c2bc60
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@2@_K@Z 0x141c2bcc0
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@2@_K@Z 0x141c2bcf0
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@PEAX@2@_K@Z 0x141c2bd20
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@_K@Z 0x141c2bd50
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@2@_K@Z 0x141c2bd80
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@2@_K@Z 0x141c2be10
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@2@_K@Z 0x141c2be40
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@2@_K@Z 0x141c2bea0
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@_K@Z 0x141c2bf00
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@_K@Z 0x141c2bf60
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@PEAX@2@_K@Z 0x141c2bf90
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@PEAVIWorldServiceCallback@@U?$less@PEAVIWorldServiceCallback@@@std@@V?$allocator@PEAVIWorldServiceCallback@@@3@$0A@@std@@@std@@QEBA_NXZ 0x141c2c100
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@$0A@@std@@@std@@QEBA_NXZ 0x141c2c140
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_List_node@PEAVCDropItem@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_List_node@PEAVCDropItem@@PEAX@std@@@2@@Z 0x141c2e540
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@std@@@2@@Z 0x141c2e570
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@std@@@2@@Z 0x141c2e5b0
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@2@@Z 0x141c2e5c0
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VRec1f8@WsReal@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141c2e660
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@4@$0A@@std@@@std@@QEBA_KXZ 0x141c2e6a0
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@6@$0A@@std@@@std@@QEBA_KXZ 0x141c2e700
// MS2-PIN: ?_Myhead@?$_List_alloc@U?$_List_base_types@PEAVEntity@egf@@V?$allocator@PEAVEntity@egf@@@std@@@std@@@std@@QEBAAEBQEAU?$_List_node@PEAVEntity@egf@@PEAX@2@XZ 0x141c2e9b0
// MS2-PIN: ?_Tidy@?$list@PEAVCDropItem@@V?$allocator@PEAVCDropItem@@@std@@@std@@QEAAXXZ 0x141c2e9d0
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@std@@SAPEAU?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@2@AEAU32@@Z 0x141c2ea90
// MS2-PIN: ?push_back@?$vector@V?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@QEAAX$$QEAV?$MS2Ptr@VMS2ActorUpdater@@@@@Z 0x141c2ebd0
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@6@$0A@@std@@@std@@QEBA_KXZ 0x141c2ed50
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VVisibleObjectRecord@WsReal@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@6@$0A@@std@@@std@@QEBA_KXZ 0x141c2ed70
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@2@PEAU32@@Z 0x141c28670
// MS2-PIN: ?_Orphan_range@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@AEBAXPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@2@0@Z 0x141c28b00
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VCLiftableObject@@@@V?$allocator@V?$MS2Ptr@VCLiftableObject@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VCLiftableObject@@@@XZ 0x141c28e60
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@XZ 0x141c29290
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@2@@Z 0x141c29710
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@4@$0A@@std@@@std@@IEAAXXZ 0x141c29cb0
// MS2-PIN: ?_Umove@?$vector@V?$MS2Ptr@VCLiftableObject@@@@V?$allocator@V?$MS2Ptr@VCLiftableObject@@@@@std@@@std@@AEAAPEAV?$MS2Ptr@VCLiftableObject@@@@PEAV3@00@Z 0x141c2a420
// MS2-PIN: ?_Xlength@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@CAXXZ 0x141c2a8d0
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@PEAX@2@_K@Z 0x141c2aa70
// MS2-PIN: ?allocate@?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@std@@QEAAPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@2@_K@Z 0x141c2ab60
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@2@_K@Z 0x141c2bc30
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@H@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@H@std@@PEAX@2@_K@Z 0x141c2bc90
// MS2-PIN: ?deallocate@?$allocator@U?$_List_node@PEAVEntity@egf@@PEAX@std@@@std@@QEAAXQEAU?$_List_node@PEAVEntity@egf@@PEAX@2@_K@Z 0x141c2bdb0
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@VEntityID@egf@@PEAX@2@_K@Z 0x141c2bde0
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@PEAX@2@_K@Z 0x141c2bf30
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VRec1f8@WsReal@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@@3@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@@std@@@std@@@2@AEBH@Z 0x141c2e180
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x141c2e1e0
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_List_node@PEAVEntity@egf@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_List_node@PEAVEntity@egf@@PEAX@std@@@2@@Z 0x141c2e550
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@PEAX@std@@@2@@Z 0x141c2e580
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@PEAX@std@@@2@@Z 0x141c2e5a0
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@std@@@std@@SA_KAEBV?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@Z 0x141c2e630
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@6@$0A@@std@@@std@@QEBA_KXZ 0x141c2e6c0
// MS2-PIN: ?max_size@?$list@PEAVCDropItem@@V?$allocator@PEAVCDropItem@@@std@@@std@@QEBA_KXZ 0x141c2e7c0
// MS2-PIN: ?max_size@?$list@PEAVEntity@egf@@V?$allocator@PEAVEntity@egf@@@std@@@std@@QEBA_KXZ 0x141c2e7e0
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@std@@SAPEAU?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@2@AEAU32@@Z 0x141c2ea30
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@std@@SAPEAU?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@2@AEAU32@@Z 0x141c2ea70
// MS2-PIN: ?push_back@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@QEAAX$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@2@@Z 0x141c2eba0
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@6@$0A@@std@@@std@@QEBA_KXZ 0x141c2ed30
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@2@XZ 0x141c28730
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@2@XZ 0x141c28790
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@2@XZ 0x141c287b0
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCLiftableObject@@@@V?$allocator@V?$MS2Ptr@VCLiftableObject@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VCLiftableObject@@@@XZ 0x141c28810
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@2@XZ 0x141c288b0
// MS2-PIN: ?_Myhead@?$_List_alloc@U?$_List_base_types@PEAVCDropItem@@V?$allocator@PEAVCDropItem@@@std@@@std@@@std@@QEBAAEBQEAU?$_List_node@PEAVCDropItem@@PEAX@2@XZ 0x141c288f0
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCLiftableObject@@@@V?$allocator@V?$MS2Ptr@VCLiftableObject@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VCLiftableObject@@@@XZ 0x141c28910
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@2@@std@@@std@@QEAAAEAPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@2@XZ 0x141c28950
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VMS2ActorUpdater@@@@XZ 0x141c28970
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@@std@@QEBAAEBQEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@2@XZ 0x141c28990
// MS2-PIN: ?_Mysize@?$_List_alloc@U?$_List_base_types@PEAVEntity@egf@@V?$allocator@PEAVEntity@egf@@@std@@@std@@@std@@QEBAAEB_KXZ 0x141c28a50
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@2@@std@@@std@@QEAAXXZ 0x141c28a70
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@@std@@QEAAXXZ 0x141c28a90
// MS2-PIN: ?deallocate@?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@std@@QEAAXQEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@2@_K@Z 0x141c2bfc0
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@6@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@2@XZ 0x141c2c4c0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@HU?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@H@std@@@std@@@std@@@2@0@Z 0x141c2d220
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VRec1f8@WsReal@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@@std@@@std@@@2@AEBH@Z 0x141c2e120
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@6@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2e240
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@6@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2e2a0
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@6@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2e300
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VVisibleObjectRecord@WsReal@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@6@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2e360
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@6@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2e3c0
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VRec1f8@WsReal@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x141c29c50
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x141c29d10
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@6@$0A@@std@@@std@@IEAAXXZ 0x141c29d70
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@6@$0A@@std@@@std@@IEAAXXZ 0x141c29dd0
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@6@$0A@@std@@@std@@IEAAXXZ 0x141c29e30
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VVisibleObjectRecord@WsReal@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@6@$0A@@std@@@std@@IEAAXXZ 0x141c29e90
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@_JV?$MS2Ptr@VRecad0@WsReal@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x141c29f50
// MS2-PIN: ?_Tidy@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@AEAAXXZ 0x141c2a1c0
// MS2-PIN: ?allocate@?$allocator@U?$_List_node@PEAVCDropItem@@PEAX@std@@@std@@QEAAPEAU?$_List_node@PEAVCDropItem@@PEAX@2@_K@Z 0x141c2a950
// MS2-PIN: ?clear@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@QEAAXXZ 0x141c2baa0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@_JV?$MS2Ptr@VRecad0@WsReal@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@3@$0A@@std@@@std@@QEAA_KAEB_J@Z 0x141c2d5d0
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VRec1f8@WsReal@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@@std@@@std@@@2@AEBH@Z 0x141c2d910
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@6@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityHider@@@efd@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2d9f0
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VVisibleObjectRecord@WsReal@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@6@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2dc90
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@PEAVIWorldServiceCallback@@U?$less@PEAVIWorldServiceCallback@@@std@@V?$allocator@PEAVIWorldServiceCallback@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVIWorldServiceCallback@@@std@@@std@@@2@AEBQEAVIWorldServiceCallback@@@Z 0x141c2df30
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VVisibleObjectRecord@WsReal@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@VVisibleObjectRecord@WsReal@@@std@@@6@$0A@@std@@@std@@QEBA_KXZ 0x141c2e720
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@4@$0A@@std@@@std@@QEBA_KXZ 0x141c2e740
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@_JV?$MS2Ptr@VRecad0@WsReal@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VRecad0@WsReal@@@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141c2e760
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@PEAVIWorldServiceCallback@@U?$less@PEAVIWorldServiceCallback@@@std@@V?$allocator@PEAVIWorldServiceCallback@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141c2e780
// MS2-PIN: ?max_size@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@2@@std@@QEBA_KXZ 0x141c2e800
// MS2-PIN: ?max_size@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WsK_Rank@@@@@std@@@2@@std@@QEBA_KXZ 0x141c2e850
// MS2-PIN: ?_Tidy@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@2@@std@@AEAAXXZ 0x141c2a020
// MS2-PIN: ?_Unchecked_end@?$list@PEAVCDropItem@@V?$allocator@PEAVCDropItem@@@std@@@std@@QEAA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@PEAVCDropItem@@@std@@@std@@@2@XZ 0x141c2a7c0
// MS2-PIN: ?end@?$list@PEAVCDropItem@@V?$allocator@PEAVCDropItem@@@std@@@std@@QEBA?AV?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@PEAVCDropItem@@@std@@@std@@@2@XZ 0x141c2b110
// MS2-PIN: ?capacity@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@QEBA_KXZ 0x141c2b1b0
// MS2-PIN: ?capacity@?$vector@V?$MS2Ptr@VCLiftableObject@@@@V?$allocator@V?$MS2Ptr@VCLiftableObject@@@@@std@@@std@@QEBA_KXZ 0x141c2b240
// MS2-PIN: ?clear@?$vector@V?$MS2Ptr@VMS2ActorUpdater@@@@V?$allocator@V?$MS2Ptr@VMS2ActorUpdater@@@@@std@@@std@@QEAAXXZ 0x141c2b9a0
// MS2-PIN: ?empty@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@QEBA_NXZ 0x141c2c180
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@6@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2dad0
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@6@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2dbb0
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141c2e010
// MS2-PIN: ?push_back@?$list@PEAVEntity@egf@@V?$allocator@PEAVEntity@egf@@@std@@@std@@QEAAXAEBQEAVEntity@egf@@@Z 0x141c2eb30
// MS2-PIN: ?size@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@QEBA_KXZ 0x141c2ee10
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VCLiftableTargetBox@@@@V?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VCLiftableTargetBox@@@@XZ 0x141c287f0
// MS2-PIN: ?_Tidy@?$vector@V?$MS2Ptr@VCLiftableTargetBox@@@@V?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@@std@@AEAAXXZ 0x141c2a290
// MS2-PIN: ?_Unchecked_end@?$list@PEAVEntity@egf@@V?$allocator@PEAVEntity@egf@@@std@@@std@@QEAA?AV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@PEAVEntity@egf@@@std@@@std@@@2@XZ 0x141c2a800
// MS2-PIN: ?deallocate@?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@QEAAXQEAV?$MS2Ptr@VCLiftableTargetBox@@@@_K@Z 0x141c2c050
// MS2-PIN: ?_Umove_if_noexcept@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@2@@std@@AEAAXPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@2@00@Z 0x141c2a5e0
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@@std@@@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x141c2e680
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@U?$less@VEntityID@egf@@@std@@V?$allocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VCEntityShower@@@efd@@@std@@@6@$0A@@std@@@std@@QEBA_KXZ 0x141c2e6e0
// MS2-PIN: ?max_size@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@@std@@@2@@std@@QEBA_KXZ 0x141c2e8a0
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@V?$allocator@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@2@@std@@AEAAXPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@2@00U?$integral_constant@_N$0A@@2@@Z 0x141c2a4a0
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$MS2Ptr@VCLiftableTargetBox@@@@V?$allocator@V?$MS2Ptr@VCLiftableTargetBox@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCLiftableTargetBox@@@@00U?$integral_constant@_N$0A@@2@@Z 0x141c2a5a0
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@PEAVIWorldServiceCallback@@U?$less@PEAVIWorldServiceCallback@@@std@@V?$allocator@PEAVIWorldServiceCallback@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141c2edb0
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VRec1f8@WsReal@@@@@std@@PEAX@2@_K@Z 0x141c2a9b0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "worldservice_real.h"
#include "dropitem.h"
#include "liftableobject.h"
#include "liftabletarget.h"
#include "ms2/guess/fieldproperty.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2ptr_impl.h"

namespace {
// The container operations of the WorldService methods (worldservice_1.cpp), per container kind.
template <class M> void WsDriveMap(M& m, const typename M::key_type& k)
{
    typename M::mapped_type v = typename M::mapped_type();
    m[k] = v;
    m.insert(typename M::value_type(k, v));
    typename M::iterator it = m.find(k);
    if (it != m.end())
        m.erase(it);
    m.erase(k);
    it = m.lower_bound(k);
    it = m.upper_bound(k);
    (void)m.count(k);
    for (it = m.begin(); it != m.end(); ++it) {}
    for (it = m.begin(); it != m.end(); it++) {}
    for (typename M::const_iterator ci = m.begin(); ci != m.end(); ++ci) {}
    const M& cm = m;
    typename M::const_iterator cf = cm.find(k);
    if (cf != cm.end() && cm.size() != 0) {}
    if (m.empty() || m.size() == 0)
        m.clear();
}
template <class S> void WsDriveSet(S& s, const typename S::key_type& k)
{
    s.insert(k);
    typename S::iterator it = s.find(k);
    if (it != s.end())
        s.erase(it);
    s.erase(k);
    (void)s.count(k);
    for (it = s.begin(); it != s.end(); ++it) {}
    const S& cs = s;
    if (cs.find(k) != cs.end()) {}
    if (s.empty() || s.size() == 0)
        s.clear();
}
template <class V> void WsDriveVec(V& v, const typename V::value_type& e)
{
    v.reserve(4);
    v.push_back(e);
    v.push_back(typename V::value_type(e));
    for (size_t i = 0; i < v.size(); ++i)
        (void)v[i];
    const V& cv = v;
    for (size_t i = 0; i < cv.size(); ++i)
        (void)cv[i];
    typename V::iterator last = v.end();
    if (!v.empty())
        v.erase(v.begin());
    if (!v.empty())
        v.clear();
}
template <class L> void WsDriveList(L& l, const typename L::value_type& e)
{
    l.push_back(e);
    l.push_front(e);
    for (typename L::iterator it = l.begin(); it != l.end(); ++it) {}
    const L& cl = l;
    for (typename L::const_iterator it = cl.begin(); it != cl.end(); ++it) {}
    if (!l.empty() && l.size() != 0) { (void)l.front(); l.pop_front(); }
    l.remove(e);
    l.clear();
}
}

void Unk_WsInst9()
{
    egf::EntityID id;
    WsReal::Set048 s048;
    WsDriveSet(s048, (IWorldServiceCallback*)0);
    WsReal::List088 l088;
    WsDriveList(l088, (egf::Entity*)0);
    std::list<CDropItem*> ldrop;                        // FUN_141bd1ed0 / FUN_141bd2030 out lists
    ldrop.push_back((CDropItem*)0);
    std::set<WsReal::VisibleObjectRecord> svis;         // FUN_141bc7920 out set
    svis.insert(WsReal::VisibleObjectRecord());
    WsReal::Map1d8 m1d8;
    WsDriveMap(m1d8, id);
    WsReal::Map1e8 m1e8;
    WsDriveMap(m1e8, 1);
    WsDriveSet(m1e8[1], id);
    WsReal::Map1f8 m1f8;
    WsDriveMap(m1f8, 1);
    WsReal::Map2e8 m2e8;
    WsDriveMap(m2e8, id);
    WsReal::Map900 m900;
    WsDriveMap(m900, id);
    WsReal::Map980 m980;
    WsDriveMap(m980, id);
    WsReal::Map990 m990;
    WsDriveMap(m990, id);
    WsReal::Mapab0 mab0;
    WsDriveMap(mab0, id);
    WsReal::Mapac0 mac0;
    WsDriveMap(mac0, 1);
    WsReal::Mapad0 mad0;
    WsDriveMap(mad0, 1);
    WsReal::Vec9a0 v9a0;
    WsDriveVec(v9a0, MS2Ptr<MS2ActorUpdater>());
    WsReal::Veca00 va00;
    WsDriveVec(va00, std::pair<CStringA, CStringW>());
    WsReal::VecTextPair vtp;
    WsDriveVec(vtp, std::pair<CStringA, CStringA>());
    WsReal::Veca18 va18;
    WsDriveVec(va18, std::pair<CStringA, MS2Ptr<Unk_WsK_Rank> >());
    std::vector<efd::SmartPointer<egf::Entity> > vent;  // FUN_141bda490 out vector
    WsDriveVec(vent, efd::SmartPointer<egf::Entity>());
    std::vector<MS2Ptr<CLiftableObject> > vlift;        // FUN_141bc58d0 out vector
    WsDriveVec(vlift, MS2Ptr<CLiftableObject>());
    std::vector<MS2Ptr<CLiftableTargetBox> > vbox;      // FUN_141bc5980 out vector
    WsDriveVec(vbox, MS2Ptr<CLiftableTargetBox>());
    MS2Ptr<FieldProperty> fp;
    fp = 0;
    MS2Ptr<Unk_WsPtreda80> pa80;                        // m_a80
    pa80 = 0;
    MS2Ptr<WsReal::RecPtrA> pA;
    pA = 0;
    MS2Ptr<WsReal::RecPtrB> pB;
    pB = 0;
    Unk_WsOptional<float> opt;                          // m_a90
    opt.reset();
}
