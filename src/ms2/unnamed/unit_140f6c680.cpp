// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item socket UI page family.
// MS2-UNIT: unit_140f6c680
// MS2-RANGE: 0x140f6c680-0x140f7d060 .text$mn
// MS2-RANGE: 0x1400e04c0-0x1400e09d0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSortTypeNames1@@YAXXZ 0x1400e04c0 ; probe
// MS2-PIN: ??__Es_strManageSound@@YAXXZ 0x1400e0580 ; probe
// MS2-PIN: ??__Es_strSkill1@@YAXXZ 0x1400e05b0 ; probe
// MS2-PIN: ??__Es_condition1@@YAXXZ 0x1400e05e0 ; probe
// MS2-PIN: ??__Es_strSortTypeNames2@@YAXXZ 0x1400e0660 ; probe
// MS2-PIN: ??__Es_strSkill2@@YAXXZ 0x1400e0720 ; probe
// MS2-PIN: ??__Es_strSkill3@@YAXXZ 0x1400e0750 ; probe
// MS2-PIN: ??__Es_condition2@@YAXXZ 0x1400e0780 ; probe
// MS2-PIN: ??__Es_strStun1@@YAXXZ 0x1400e07d0 ; probe
// MS2-PIN: ??__Es_strSortTypeNames3@@YAXXZ 0x1400e0800 ; probe
// MS2-PIN: ??__Es_strStun2@@YAXXZ 0x1400e08c0 ; probe
// MS2-PIN: ??__Es_strStun3@@YAXXZ 0x1400e08f0 ; probe
// MS2-PIN: ??__Es_condition3@@YAXXZ 0x1400e0920 ; probe
// MS2-PIN: ??__Es_strUpgradeButtonSound@@YAXXZ 0x1400e0970 ; probe
// MS2-PIN: ??__Es_strUpgradeSound@@YAXXZ 0x1400e09a0 ; probe
// MS2-PIN: ??$FUN_14028dfa0@IW4Unk_SocketPageResult@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBIAEBW4Unk_SocketPageResult@@@Z 0x140f6e850 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VSaleParam@ItemSocketSystemPageBase@@@@QEBAPEAVSaleParam@ItemSocketSystemPageBase@@XZ 0x140f6ed00 ; unique
// MS2-PIN: ?GetAt@?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEBAAEBV?$MS2Ptr@VCItem@@@@_K@Z 0x140f6ed60 ; unique
// MS2-PIN: ??$?0PEAVItemSocketSystemPageGemStoneManage@@P80@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z$0A@@?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@QEAA@AEBQEAVItemSocketSystemPageGemStoneManage@@AEBQ82@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@Z 0x140f72f60 ; order
// MS2-PIN: ??$?0PEAVItemSocketSystemPageGemStoneManage@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z$0A@@?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@QEAA@AEBQEAVItemSocketSystemPageGemStoneManage@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140f73030 ; order
// MS2-PIN: ??$?0PEAVItemSocketSystemPageGemStoneManage@@P80@EAA_NHAEBVCMsgBoxData@@@Z$0A@@?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@QEAA@AEBQEAVItemSocketSystemPageGemStoneManage@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140f73100 ; order
// MS2-PIN: ??$?8PEAVItemSocketSystemPageGemStoneManage@@P80@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@0@0@Z 0x140f731d0 ; prop
// MS2-PIN: ??$?8PEAVItemSocketSystemPageGemStoneManage@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140f73240 ; prop
// MS2-PIN: ??$?8PEAVItemSocketSystemPageGemStoneManage@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140f732b0 ; prop
// MS2-PIN: ??$forward@AEBQ8ItemSocketSystemPageGemStoneManage@@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@YAAEBQ8ItemSocketSystemPageGemStoneManage@@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@ZAEBQ81@EAAX01@Z@Z 0x140f73500 ; order
// MS2-PIN: ??$forward@AEBQ8ItemSocketSystemPageGemStoneManage@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YAAEBQ8ItemSocketSystemPageGemStoneManage@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@ZAEBQ81@EAAX0@Z@Z 0x140f73510 ; order
// MS2-PIN: ??$forward@AEBQ8ItemSocketSystemPageGemStoneManage@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8ItemSocketSystemPageGemStoneManage@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x140f73520 ; order
// MS2-PIN: ??$forward@AEBQEAVItemSocketSystemPageGemStoneManage@@@std@@YAAEBQEAVItemSocketSystemPageGemStoneManage@@AEBQEAV1@@Z 0x140f73530 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVItemSocketSystemPageGemStoneManage@@AEBQ81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@YA?AU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@0@AEBQEAVItemSocketSystemPageGemStoneManage@@AEBQ82@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@Z 0x140f73540 ; order
// MS2-PIN: ??$make_pair@AEBQEAVItemSocketSystemPageGemStoneManage@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA?AU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@AEBQEAVItemSocketSystemPageGemStoneManage@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140f73590 ; order
// MS2-PIN: ??$make_pair@AEBQEAVItemSocketSystemPageGemStoneManage@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA?AU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@AEBQEAVItemSocketSystemPageGemStoneManage@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140f735e0 ; order
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@QEAA@AEBV01@@Z 0x140f73670 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@QEAA@AEBU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@Z 0x140f736c0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x140f73710 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@Z 0x140f73760 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140f737b0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140f73800 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAA@XZ 0x140f738b0 ; order
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x140f738d0 ; prop
// MS2-PIN: ??_EItemSocketSystemPageGemStoneManage@@WDA@EAAPEAXI@Z 0x140f738e8 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEAAPEAXI@Z 0x140f73900 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAPEAXI@Z 0x140f73940 ; order
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140f73980 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f74020 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f74080 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f740e0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z 0x140f74140 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140f74180 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140f741b0 ; unique
// MS2-PIN: ??$Call@VItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@CAXAEAU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@AEAVItemInfoSlot@@AEAVASSlot@@@Z 0x140f741f0 ; prop
// MS2-PIN: ??$Call@VItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140f74230 ; prop
// MS2-PIN: ??$Call@VItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140f74270 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f742b0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f74310 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneManage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f74370 ; unique
// MS2-PIN: ??$?0PEAVItemSocketSystemPageGemStoneUpgrade@@P80@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z$0A@@?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@QEAA@AEBQEAVItemSocketSystemPageGemStoneUpgrade@@AEBQ82@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@Z 0x140f7a530 ; order
// MS2-PIN: ??$?0PEAVItemSocketSystemPageGemStoneUpgrade@@P80@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z$0A@@?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@QEAA@AEBQEAVItemSocketSystemPageGemStoneUpgrade@@AEBQ82@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@Z 0x140f7a600 ; order
// MS2-PIN: ??$?0PEAVItemSocketSystemPageGemStoneUpgrade@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z$0A@@?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@QEAA@AEBQEAVItemSocketSystemPageGemStoneUpgrade@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140f7a6d0 ; order
// MS2-PIN: ??$?8PEAVItemSocketSystemPageGemStoneUpgrade@@P80@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@0@0@Z 0x140f7a870 ; prop
// MS2-PIN: ??$?8PEAVItemSocketSystemPageGemStoneUpgrade@@P80@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@0@0@Z 0x140f7a8e0 ; prop
// MS2-PIN: ??$?8PEAVItemSocketSystemPageGemStoneUpgrade@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140f7a950 ; prop
// MS2-PIN: ??$?8PEAVItemSocketSystemPageGemStoneUpgrade@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140f7a9c0 ; prop
// MS2-PIN: ??$forward@AEBQ8ItemSocketSystemPageGemStoneUpgrade@@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@YAAEBQ8ItemSocketSystemPageGemStoneUpgrade@@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@ZAEBQ81@EAAX01@Z@Z 0x140f7aa30 ; order
// MS2-PIN: ??$forward@AEBQ8ItemSocketSystemPageGemStoneUpgrade@@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@YAAEBQ8ItemSocketSystemPageGemStoneUpgrade@@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@ZAEBQ81@EAAX01@Z@Z 0x140f7aa40 ; order
// MS2-PIN: ??$make_pair@AEBQEAVItemSocketSystemPageGemStoneUpgrade@@AEBQ81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@YA?AU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@0@AEBQEAVItemSocketSystemPageGemStoneUpgrade@@AEBQ82@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@Z 0x140f7aa80 ; order
// MS2-PIN: ??$make_pair@AEBQEAVItemSocketSystemPageGemStoneUpgrade@@AEBQ81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@YA?AU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@0@AEBQEAVItemSocketSystemPageGemStoneUpgrade@@AEBQ82@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@Z 0x140f7aad0 ; order
// MS2-PIN: ??$make_pair@AEBQEAVItemSocketSystemPageGemStoneUpgrade@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA?AU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@AEBQEAVItemSocketSystemPageGemStoneUpgrade@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140f7ab20 ; order
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@QEAA@AEBV01@@Z 0x140f7acb0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@QEAA@AEBU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@Z 0x140f7ad00 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@QEAA@AEBV01@@Z 0x140f7ad50 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@QEAA@AEBU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@Z 0x140f7ada0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x140f7adf0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@Z 0x140f7ae40 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x140f7ae90 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAA@XZ 0x140f7b3d0 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VTGemStoneInEquip@@@@QEBAPEAVTGemStoneInEquip@@XZ 0x140f7b660 ; unique
// MS2-PIN: ??C?$MS2Ptr@VTGemStoneInEquip@@@@QEBAPEAVTGemStoneInEquip@@XZ 0x140f7b670 ; unique
// MS2-PIN: ??_EItemSocketSystemPageGemStoneUpgrade@@WDA@EAAPEAXI@Z 0x140f7b680 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEAAPEAXI@Z 0x140f7b690 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@UEAAPEAXI@Z 0x140f7b6d0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x140f7b750 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f7ca60 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f7cac0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f7cb20 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f7cb80 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z 0x140f7cbe0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@UEAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z 0x140f7cc20 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140f7cc60 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140f7cc90 ; unique
// MS2-PIN: ??$Call@VItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@CAXAEAU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@AEAVItemInfoSlot@@AEAVASSlot@@@Z 0x140f7ccc0 ; prop
// MS2-PIN: ??$Call@VItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@CAXAEAU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@AEAVItemInfoSlot@@AEAVASTooltip@@@Z 0x140f7cd00 ; prop
// MS2-PIN: ??$Call@VItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140f7cd40 ; prop
// MS2-PIN: ??$Call@VItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x140f7cd80 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f7cdc0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASTooltip@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f7ce20 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f7ce80 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemStoneUpgrade@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f7cee0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1TGemStoneInEquip@@UEAA@XZ 0x140f7b4e0
// MS2-PIN: ?RemoveKey@?$CAtlMap@HV?$MS2Ptr@VCItem@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAA_NH@Z 0x140f73e20
// MS2-PIN: ??0?$MS2Ptr@VSaleParam@ItemSocketSystemPageBase@@@@QEAA@AEBV0@@Z 0x140f7af30
// MS2-PIN: ??0?$MS2Ptr@VSaleParam@ItemSocketSystemPageBase@@@@QEAA@PEAVSaleParam@ItemSocketSystemPageBase@@@Z 0x140f7af70
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemsocketsystempagebase.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/itemsocketsystempagebase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/client/ms2/itemsocketsystempagecontrols.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/client/ms2/itemsocketsystempagegemstonemanage.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citemgemstonedata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uihighlightgamemenu.h"
#include "ms2/client/ms2/uimessageboxdata.h"

#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/itemsocketsystempagegemstoneupgrade.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/astextfield.h"
#include "hook/ms2hook.h"

// The header statics of the three original TUs of this range (itemsocketsystempagebase.cpp, the gemstone manage page,
// the gemstone upgrade page): each TU has the sort-type table, two labels and the condition object, then its own
// statics.
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;                // 0x143acb500
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strManageSound = "System_Gemstone_button_01";      // 0x143acb628
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strUpgradeSound = "System_Gemstone_Upgrade_01";    // 0x143acb718
static CString s_strUpgradeButtonSound = "System_Gemstone_button_01"; // 0x143acb6c8

class Unk_ItemEquipData : public CItemData {};   // CItem::FUN_140527840's record (as commonfiles\item.cpp)

// The result is formatted through fmt's enum customization, rather than an integer argument.
enum class Unk_SocketPageResult : int {};
void format_arg(fmt::BasicFormatter<wchar_t>& formatter, const wchar_t*& cursor, const Unk_SocketPageResult& value);
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
void FUN_1412751f0(const CStringW&, int, int);
void FUN_1412752d0(const CStringW&, int);
void FUN_140d73aa0(CStringW, int, void*, CStringW);

class CItemGemStoneUpgradeTable;
class Unk_SocketPageWorld;
class Unk_SocketPagePlayer;
class Unk_SocketPageInventory;
class Unk_SocketPageDialog;
class Unk_SocketPageFeatures;
Unk_SocketPageWorld* FUN_1403ed2d0();
Unk_SocketPagePlayer* FUN_141bd0cc0(Unk_SocketPageWorld*);
Unk_SocketPageInventory* FUN_1416561a0(Unk_SocketPagePlayer*);
void FUN_1411e7660(Unk_SocketPageInventory*);
Unk_SocketPageDialog* FUN_140938c30(int);
void FUN_141a5a5c0(Unk_SocketPageDialog*);
CItemGemStoneUpgradeTable* FUN_14062c280();
void FUN_1405b1b50(CItemGemStoneUpgradeTable*);
void FUN_1412761e0(MS2Ptr<AScript>, int);
Unk_SocketPageFeatures* FUN_140166410();
bool FUN_14036d570(Unk_SocketPageFeatures*, int);
int FUN_14053feb0(int);
__int64 FUN_14028d0e0();
NotifyContext::BindData* FUN_1422c8e90(const CString&);
ItemInfoSlot* FUN_140c69ab0(NotifyContext::BindData*);
ItemInfoSlot* FUN_140f6e830(const CString&);
void FUN_141415af0(ItemInfoSlot*, MS2Ptr<CItem>);
MS2Ptr<CItem> FUN_141425750(__int64, bool*);
class Unk_SocketPageInventoryCount;
extern char DAT_143ab2a90;
int FUN_140a5f180(Unk_SocketPageInventoryCount*, int, int);
int FUN_140a5f780(Unk_SocketPageInventoryCount*, int, int);
int FUN_14053c6f0(Unk_ItemEquipData*);
int FUN_140627b80(int, int);
CString FUN_1422cc860(const CString&, int);
void FUN_141416740(ItemInfoSlot*, int, int);
void FUN_14141f970(const CString&);
void FUN_14141f770(const CString&, int, void*, ItemSlotBag::CreateParam::GetItemFn, int, int);
MS2Ptr<CItem> FUN_141420330(void*, int);
void FUN_141415600(const CString&);
void FUN_141415450(const CString&, MS2Ptr<CItem>, int, int, int);
CStringW FUN_1419021b0(unsigned, unsigned);
struct Unk_SpInvokeB { Scaleform::GFx::Value FUN_140f356e0(const char*, int, bool); };
void FUN_14141f860(const CString&, int, void*, MS2Ptr<ItemSlotBag::CreateParam>);
DragSlotBag* FUN_140c54570(const CString&);
void FUN_1422cc9e0(DragSlotBag*);
void FUN_14141ff80(ItemSlotBag*, int);
void FUN_1422cf860(Unk_SocketPageBag*);
void FUN_1422ccb50(DragSlotBag*, int);
void FUN_1422cf7e0(Unk_SocketPageBag*, int);
int FUN_1422dd150(Unk_SocketPageBag*);
void FUN_1422dcca0(Unk_SocketPageBag*, int);
class Unk_SocketPageItemEvents;
Unk_SocketPageItemEvents* FUN_140a6a840();
void FUN_1419caeb0(Unk_SocketPageItemEvents*, UIItemEventListener*);
void FUN_1419cae20(Unk_SocketPageItemEvents*, UIItemEventListener*);
void FUN_140cfe1b0(const CString&);
struct Unk_SpFindBag { MS2Ptr<Unk_SocketPageBag> FUN_140c4bc60(const CString&); };
struct Unk_SpFindButton { MS2Ptr<Unk_SocketPageButton> FUN_140acce30(const CString&); };
class Unk_SocketPageDebug;
Unk_SocketPageDebug* FUN_14025e7c0();
bool FUN_14116d720(Unk_SocketPageDebug*);
void FUN_1422ce240(Unk_SocketPageButton*, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, int);
UIHighlightGameMenu* FUN_140f73450();
void FUN_140c244b0(UIHighlightGameMenu*, const int*, int);
bool FUN_14053d840(Unk_ItemEquipData*);
void FUN_140a60880(Unk_SocketPageInventoryCount*, int, CAtlArray<MS2Ptr<CItem>>&);
void FUN_1411e1ce0(Unk_SocketPageInventory*, CAtlList<MS2Ptr<CEquipItem>>&, int);
int FUN_140222ce0(MS2Ptr<CItemData>);
bool FUN_1406272f0(unsigned, MS2Ptr<CItemGemStoneData>);
ItemSlotBag* FUN_140c54590(const CString&);
void FUN_141276180(const CString&, const CString&);
bool FUN_14062a3d0(MS2Ptr<CItem>, int, MS2Ptr<CItem>, Delegate<bool(int, const CMsgBoxData&)>);
bool FUN_14062abb0(MS2Ptr<CItem>, const CMsgBoxData&);
unsigned short FUN_140626f20(unsigned);
void FUN_1406284f0(unsigned short, int, int*, int*);
struct Unk_SocketPageStrings { CStringW FUN_141811980(int, int); };
Unk_SocketPageStrings* FUN_1401a9d70();
extern __int64 DAT_143ab2898;
extern unsigned DAT_143ab2914;
CStringW FUN_14062b4f0(CStringW, const int*);
CStringW FUN_1409e8970(CStringW, const int&, const int&);
CStringW FUN_1405c2690(CStringW, const CStringW&);
CStringW FUN_1409404f0(__int64);
#ifdef __clang__
CStringW FUN_1401d0160(const wchar_t*, const CStringW&);     // ATL::operator+(const wchar_t*, const CStringW&)
#endif
MS2Ptr<CMsgBoxData> FUN_140d73d20(int, CStringW, int, CStringW);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);
CStringW FUN_140719730(bool);
void FUN_140165320(ATL::CAtlArray<CStringW>*, const CStringW&);
typedef MS2Ptr<CGemStoneItem> (*Unk_GemStoneSlotGetFn)(void*, int);
MS2Ptr<CGemStoneItem> FUN_140cfe450(void*, int);
void FUN_140cfe0c0(const CString&, int, void*, Unk_GemStoneSlotGetFn, int, int);
// The socket slot controls of the gemstone bag; slot 10 redraws the slot.
class Unk_GemStoneSlot {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
};
Unk_GemStoneSlot* FUN_140cfe620(NotifyContext::BindData*);
void FUN_140cfd950(Unk_GemStoneSlot*, MS2Ptr<CGemStoneItem>);
void FUN_140f73320(CMsgBoxData*, bool);
Unk_GemStoneSlot* FUN_140f73380(const CString&);
int FUN_140f73c10();
bool FUN_1414258e0(__int64);
void FUN_141a020b0(CMsgBoxData*, int, int, int);           // CMsgBoxData members not declared in uimessageboxdata.h
bool FUN_141a02e10(const CMsgBoxData*, int, unsigned);
void FUN_140710590(COutPacket&);
// The socket-system packets (layouts as commonfiles\itemsocketsystemutil.cpp).
struct Unk_SSGGemEquip {
    __int64 m_nItemUid;
    int m_nSlot;
    MS2Ptr<TSocketGemStoneInfo> m_spGem;
};
struct Unk_SSGGemUnequip {
    __int64 m_nItemUid;
    __int64 m_nGemUid;
    int m_nSlot;
};
struct Unk_SockMsgIIL {
    void* m_pVtbl;
    int m_nB8;
    int m_nC;
    __int64 m_n10;
    int m_n18;
};
void FUN_140628a00(Unk_SSGGemEquip&, CInPacket&);
void FUN_140628be0(Unk_SSGGemUnequip&, CInPacket&);
void FUN_140628b70(Unk_SSGGemUnequip&, COutputStream&);
void FUN_140629de0(Unk_SockMsgIIL&, COutputStream&);
class Unk_SocketPageUIService;
Unk_SocketPageUIService* FUN_1403ed2b0();
struct Unk_SpUIService { MS2Ptr<UIObject> FUN_141adcea0(int); };

// The gemstone upgrade page (itemsocketsystempagegemstoneupgrade.cpp).
float FUN_1411e1110(Unk_SocketPageInventory*, int);
int FUN_140627a20(unsigned, unsigned*, unsigned);
bool FUN_140627020(MS2Ptr<CItemGemStoneData>);
bool FUN_140626fb0(unsigned);
CStringW FUN_14042cb90(CStringW, const float&);
struct Unk_SpTooltipRoot { MS2Ptr<AScript> FUN_1409db730(); };
void FUN_1409d8bf0(ASTooltip*, int);
bool FUN_140841300(const CStringW&, const char*);
NotifySystem* FUN_140939a10();
int FUN_1422dccd0(Unk_SocketPageBag*);
// The upgrade row with its ingredient container (0x1405b0b70 builds it at +0x30).
class Unk_GemStoneUpgradeRow : public CItemGemStoneData {
};   // the ingredient container is CItemGemStoneData::m_ingredients (commonfiles/itemgemstonedata.h)
MS2_CHECK_OFFSET(Unk_GemStoneUpgradeRow, m_ingredients, 0x30);
// The client-to-server packet records of the page (ctors 0x140f7b100.., vftables 0x142e84cf0..).
namespace CCItemSocketSystemPacket {
class GemStoneInEquip {
public:
    GemStoneInEquip() : m_nUid(0), m_nSlot(-1) {}
    virtual bool vfunc_0();
    unsigned __int64 m_nUid;            // +0x08 the equipment uid
    int m_nSlot;                        // +0x10
};
class GemStoneUpgrade : public GemStoneInEquip {
public:
    GemStoneUpgrade() : m_nGemUid(0) {}
    __int64 m_nGemUid;                  // +0x18
};
class GemStoneUpgradeResult : public GemStoneInEquip {
public:
    GemStoneUpgradeResult() : m_spInfo(0), m_nGemUid(0), m_nGrade(1), m_bSuccess(false) {}
    MS2Ptr<TSocketGemStoneInfo> m_spInfo;   // +0x18
    __int64 m_nGemUid;                  // +0x28
    int m_nGrade;                       // +0x30
    bool m_bSuccess;                    // +0x34
};
class SelectItem : public GemStoneInEquip {
public:
    SelectItem() : m_nGemUid(0) {}
    virtual ~SelectItem() {}
    __int64 m_nGemUid;                  // +0x18
};
class SelectItemResult : public GemStoneInEquip {
public:
    SelectItemResult() : m_nGemUid(0), m_fProb(0) {}
    virtual ~SelectItemResult() {}
    __int64 m_nGemUid;                  // +0x18
    float m_fProb;                      // +0x20
};
}
MS2_CHECK_OFFSET(CCItemSocketSystemPacket::GemStoneInEquip, m_nSlot, 0x10);
MS2_CHECK_OFFSET(CCItemSocketSystemPacket::GemStoneUpgradeResult, m_nGemUid, 0x28);
MS2_CHECK_OFFSET(CCItemSocketSystemPacket::GemStoneUpgradeResult, m_bSuccess, 0x34);
MS2_CHECK_OFFSET(CCItemSocketSystemPacket::SelectItemResult, m_fProb, 0x20);
void FUN_140629c50(CCItemSocketSystemPacket::SelectItem&, COutputStream&);
void FUN_1406298b0(CCItemSocketSystemPacket::GemStoneUpgrade&, COutputStream&);
void FUN_140629d60(CCItemSocketSystemPacket::SelectItemResult&, CInPacket&);
void FUN_140629a30(CCItemSocketSystemPacket::GemStoneUpgradeResult&, CInPacket&);


// The slot callback delegate's out-of-line members (delegate.h declares them only; the exe copies are COMDATs of
// other units).
template <> inline Delegate<void(ItemInfoSlot&, ASSlot&)>::~Delegate()
{
    if (m_pImpl != 0)
        delete m_pImpl;
}

template <> inline Delegate<void(ItemInfoSlot&, ASSlot&)>& Delegate<void(ItemInfoSlot&, ASSlot&)>::operator=(const Delegate& o)
{
    if (this != &o) {
        if (m_pImpl != 0)
            delete m_pImpl;
        if (o.m_pImpl == 0)
            m_pImpl = 0;
        else
            m_pImpl = o.m_pImpl->vfunc_1();
    }
    return *this;
}

// @0x140f6c680
ItemSocketSystemPageBase::ItemSocketSystemPageBase() : m_restoreInventory(false) {}

// @0x140f6c6e0
ItemSocketSystemPageBase::~ItemSocketSystemPageBase() {}

// @0x140f6c720
void ItemSocketSystemPageBase::vfunc_1()
{
    if (m_root.get() != 0)
        m_root->vfunc_3(0);
}
MS2_REPLACE_METHOD(0x140F6C720, ItemSocketSystemPageBase, vfunc_1, 76, 0x58421210);

// @0x140f6c780
void ItemSocketSystemPageBase::vfunc_2()
{
    m_root = 0;
    if (m_restoreInventory) {
        Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
        if (player != 0)
            FUN_1411e7660(FUN_1416561a0(player));
        Unk_SocketPageDialog* dialog = FUN_140938c30(10001);
        if (dialog != 0)
            FUN_141a5a5c0(dialog);
    }
    m_restoreInventory = false;
}
MS2_REPLACE_METHOD(0x140F6C780, ItemSocketSystemPageBase, vfunc_2, 132, 0x78E9C640);

// @0x140f6c810
void ItemSocketSystemPageBase::vfunc_4(MS2Ptr<AScript> root)
{
    FUN_1405b1b50(FUN_14062c280());
    vfunc_7(root);
    if (m_root.get() != 0)
        m_root->vfunc_3(1);
}
MS2_REPLACE_METHOD(0x140F6C810, ItemSocketSystemPageBase, vfunc_4, 168, 0x44925C2B);

// @0x140f6c8c0
void ItemSocketSystemPageBase::vfunc_6() {}

// @0x140f6c8d0
void ItemSocketSystemPageBase::vfunc_7(MS2Ptr<AScript> root)
{
    if (m_root.get() != 0)
        FUN_140f6d620(1);
}
MS2_REPLACE_METHOD(0x140F6C8D0, ItemSocketSystemPageBase, vfunc_7, 76, 0xBED2B8DC);

// @0x140f6c930
// MS2-FUNCTIONAL: equivalent packet decoding and localized errors; formatter and temporary layout differ.
void ItemSocketSystemPageBase::vfunc_8(CInPacket* packet)
{
    int operation = packet->vfunc_o8_1();
    Unk_SocketPageResult result = static_cast<Unk_SocketPageResult>(packet->vfunc_o8_3());
    int code = static_cast<int>(result);
    if (code < 5 || code > 12) {
        CStringW key;
        switch (code) {
        case 1: key = L"s_itemsocketsystem_error_invalid_target"; break;
        case 2: key = L"s_itemsocketsystem_error_invalid_target_gemstone"; break;
        case 3: key = L"s_itemsocketsystem_error_invalid_target_ingredient"; break;
        case 4: key = L"s_itemsocketsystem_error_invalid_target_ingredient_count"; break;
        case 15: key = L"s_itemsocketsystem_error_socket_lock"; break;
        case 16: key = L"s_itemsocketsystem_error_socket_used"; break;
        case 17: key = L"s_itemsocketsystem_error_socket_empty"; break;
        case 18: key = L"s_itemsocketsystem_error_socket_unlock_all"; break;
        case 20: key = L"s_itemsocketsystem_error_gemstone_maxlevel"; break;
        case 21: key = L"s_itemsocketsystem_error_lack_price"; break;
        case 22: break;
        case 23: key = L"s_itemsocketsystem_error_bind_owner"; break;
        default:
            FUN_1412751f0(FUN_14028dfa0(CStringW(L"s_itemsocketsystem_error_server_default"), operation, result), 1, 1);
            break;
        }
        if (!key.IsEmpty())
            FUN_1412752d0(key, 1);
    } else {
        FUN_140d73aa0(FUN_14028dfa0(CStringW(L"s_itemsocketsystem_error_server_default_msgbox"), operation, result), 0, 0, CStringW(L""));
    }
}

// @0x140f6cce0
// MS2-FUNCTIONAL: smart-pointer return and exception-cleanup layout differ.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6cce0(int itemId, int grade)
{
    MS2Ptr<CItem> item(new CItem);
    if (item.get() != 0) {
        if (item->FUN_140523c40(itemId, grade, 0))
            return item;
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f6ce00
// MS2-FUNCTIONAL: smart-pointer return and local temporary layout differ.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6ce00(int itemId, int grade, bool bindOwner, MS2Ptr<CItem> source)
{
    if (grade == 0)
        grade = FUN_14053feb0(itemId);
    MS2Ptr<CItem> item(new CItem);
    if (item.get() != 0) {
        if (item->FUN_14052b130(itemId, grade, 0) != 0) {
            item->FUN_14052b340(1);
            if (bindOwner)
                item->FUN_140526a70(FUN_14028d0e0());
            if (source.get() != 0) {
                unsigned value = source->FUN_1405273a0();
                item->FUN_1405273f0(value);
                __int64 option = source->FUN_140528e00();
                unsigned type = source->FUN_140528ca0();
                item->FUN_14052b710(&type, &option);
            }
            return item;
        }
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f6d050
// MS2-FUNCTIONAL: typed gemstone binding and lock copies preserve behavior; cleanup layout differs.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6d050(MS2Ptr<TSocketGemStoneInfo> info, int grade, bool bindOwner)
{
    if (!(info == 0) && info->m_nGemId != 0) {
        MS2Ptr<CItem> item = FUN_140f6ce00(info->m_nGemId, grade, bindOwner, MS2Ptr<CItem>(0));
        if (item.get() != 0) {
            {
                MS2Ptr<TSocketGemStoneBind> binding(info->m_spBind);
                if (binding.get() != 0)
                    item->FUN_14052b5e0(&binding->m_nCharacterId, &binding->m_strName);
            }
            {
                MS2Ptr<TSocketGemStoneLock> lock(info->m_spLock);
                if (lock.get() != 0)
                    item->FUN_14052b710(reinterpret_cast<unsigned*>(&lock->m_nState), &lock->m_nExpireTime);
            }
            return item;
        }
        return MS2Ptr<CItem>(0);
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f6d300
// MS2-FUNCTIONAL: equivalent null-slot return control flow.
ItemInfoSlot* ItemSocketSystemPageBase::FUN_140f6d300(const CString& name)
{
    ItemInfoSlot* slot = FUN_140f6e830(name);
    if (slot == 0)
        return 0;
    return slot;
}

// @0x140f6d340
// MS2-FUNCTIONAL: equivalent null-slot return control flow and item cleanup.
ItemInfoSlot* ItemSocketSystemPageBase::FUN_140f6d340(const CString& name, MS2Ptr<CItem> item)
{
    ItemInfoSlot* slot = FUN_140f6e830(name);
    if (slot == 0)
        return 0;
    FUN_141415af0(slot, item);
    slot->vfunc_10();
    return slot;
}

// @0x140f6d400
// MS2-FUNCTIONAL: equivalent null-slot return control flow.
ItemInfoSlot* ItemSocketSystemPageBase::FUN_140f6d400(const CString& name)
{
    ItemInfoSlot* slot = FUN_140f6e830(name);
    if (slot == 0)
        return 0;
    slot->vfunc_10();
    return slot;
}

// @0x140f6d450
// MS2-FUNCTIONAL: typed callback and container-count temporaries differ.
void ItemSocketSystemPageBase::FUN_140f6d450(const CString& name, CAtlArray<MS2Ptr<CItem>>& items, int icon, int flags)
{
    FUN_14141f970(name);
    FUN_14141f770(name, static_cast<int>(items.GetCount()), &items, FUN_141420330, icon, flags);
}

// @0x140f6d4c0
// MS2-FUNCTIONAL: typed callback and smart-pointer cleanup temporaries differ.
void ItemSocketSystemPageBase::FUN_140f6d4c0(const CString& name, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<ItemSlotBag::CreateParam> param)
{
    FUN_14141f970(name);
    if (param.get() != 0 && param->m_pfnGetItem == 0)
        param->m_pfnGetItem = FUN_141420330;
    FUN_14141f860(name, static_cast<int>(items.GetCount()), &items, param);
}

// @0x140f6d590
void ItemSocketSystemPageBase::FUN_140f6d590(const CString& name, MS2Ptr<CItem> item, int icon, int flags)
{
    FUN_141415600(name);
    FUN_141415450(name, item, 0, icon, flags);
}
MS2_REPLACE_METHOD(0x140F6D590, ItemSocketSystemPageBase, FUN_140f6d590, 132, 0xA8E7D8A5);

// @0x140f6d620
void ItemSocketSystemPageBase::FUN_140f6d620(int enabled)
{
    FUN_1412761e0(MS2Ptr<AScript>(m_root), enabled);
}
MS2_REPLACE_METHOD(0x140F6D620, ItemSocketSystemPageBase, FUN_140f6d620, 69, 0x2AEDD3B6);

// @0x140f6d670
int ItemSocketSystemPageBase::FUN_140f6d670()
{
    if (!FUN_14036d570(FUN_140166410(), 46))
        return 7;
    return 6;
}
MS2_REPLACE_METHOD(0x140F6D670, ItemSocketSystemPageBase, FUN_140f6d670, 51, 0x9B421BE7);

// @0x140f6d6b0
// MS2-FUNCTIONAL: equivalent UID search; return and cleanup layout differ.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6d6b0(__int64 uid, CAtlArray<MS2Ptr<CItem>>& items, int* index)
{
    *index = -1;
    if (uid == 0)
        return MS2Ptr<CItem>(0);
    if (items.IsEmpty() == true)
        return MS2Ptr<CItem>(0);
    for (size_t i = 0; i < items.GetCount(); ++i) {
        MS2Ptr<CItem> item(items.GetAt(i));
        if (!(item == 0)) {
            if (item->FUN_140526a50() == uid) {
                *index = static_cast<int>(i);
                return item;
            }
        }
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f6d840
// MS2-FUNCTIONAL: equivalent checked item lookup; return layout differs.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6d840(CAtlArray<MS2Ptr<CItem>>& items, unsigned index)
{
    if (!items.IsEmpty() && index < items.GetCount())
        return items.GetAt(index);
    return MS2Ptr<CItem>(0);
}

// @0x140f6d8f0
void ItemSocketSystemPageBase::FUN_140f6d8f0(CAtlArray<MS2Ptr<CItem>>& items, int first, int second)
{
    MS2Ptr<CItem> firstItem(items.GetAt(first));
    MS2Ptr<CItem> secondItem(items.GetAt(second));
    items.SetAt(second, firstItem);
    items.SetAt(first, secondItem);
}
MS2_REPLACE_METHOD(0x140F6D8F0, ItemSocketSystemPageBase, FUN_140f6d8f0, 170, 0x9CBA533A);

// @0x140f6d9a0
// MS2-FUNCTIONAL: typed list erase and bag refresh preserve calls and branches.
bool ItemSocketSystemPageBase::FUN_140f6d9a0(int index, const CString& name, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<Unk_SocketPageBag> control)
{
    if (index >= 0 && index < static_cast<int>(items.GetCount())) {
        items.RemoveAt(index, 1);
        int count = static_cast<int>(items.GetCount());
        DragSlotBag* bag = FUN_140c54570(name);
        if (bag == 0)
            return false;
        ItemSlotBag* itemBag = dynamic_cast<ItemSlotBag*>(bag);
        if (itemBag == 0) {
            FUN_1422cc9e0(bag);
            bag->vfunc_10(count);
        } else {
            FUN_14141ff80(itemBag, count);
        }
        if (control.get() != 0)
            FUN_1422cf860(control.operator->());
        return true;
    }
    return false;
}

// @0x140f6db00
// MS2-FUNCTIONAL: typed append and bag refresh; local cleanup layout differs.
bool ItemSocketSystemPageBase::FUN_140f6db00(MS2Ptr<CItem> item, const CString& name, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<Unk_SocketPageBag> control)
{
    DragSlotBag* bag = FUN_140c54570(name);
    if (bag != 0) {
        int index = static_cast<int>(items.GetCount());
        items.Add(item);
        FUN_1422ccb50(bag, index);
        FUN_1422cf7e0(control.operator->(), index);
        bag->vfunc_14(index);
    }
    return bag != 0;
}

// @0x140f6dbe0
// MS2-FUNCTIONAL: equivalent selected-index reset; unused result local omitted.
void ItemSocketSystemPageBase::FUN_140f6dbe0(MS2Ptr<Unk_SocketPageBag> control)
{
    if (control.get() != 0) {
        // The original queries the selected index for its side effects before clearing it.
        FUN_1422dd150(control.operator->());
        FUN_1422dcca0(control.operator->(), -1);
        control->vfunc_24(false);
    }
}

// @0x140f6dc70
// MS2-FUNCTIONAL: typed ingredient list and Scaleform data construction; local/cleanup layout differs.
void ItemSocketSystemPageBase::FUN_140f6dc70(const CString& name, CIngredientContainer& ingredients, ASObj& data, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<CItem> excluded, __int64* price, MS2Ptr<SaleParam> sale)
{
    *price = 0;
    Unk_IngVec* entries = ingredients.FUN_14026c230();
    size_t count = entries->FUN_14028b500();
    for (size_t i = 0; i < count; ++i) {
        Unk_IngRef ingredient(*entries->FUN_14028a0f0(i));
        if (!(ingredient == 0)) {
            if (!ingredient->FUN_14026b350()) {
                int itemId = ingredient->FUN_14026b500();
                int grade = FUN_14053feb0(itemId);
                int amount = ingredient->m_c;
                MS2Ptr<CItem> item(new CItem);
                if (item->FUN_14052b2e0(itemId, grade, 0, amount) != 0)
                    items.Add(item);
            }
        }
    }
    FUN_14141f770(name, static_cast<int>(count), &items, FUN_141420330, 0x405, FUN_140f6e6e0());
    int rate = 0;
    int enabled = 0;
    if (sale.get() != 0) {
        rate = sale->rate;
        enabled = sale->enabled;
    }
    ASArray rows(2);
    for (size_t i = 0; i < items.GetCount(); ++i) {
        MS2Ptr<CItem> item(items.GetAt(i));
        if (!(item == 0)) {
            CString binding = FUN_1422cc860(name, static_cast<int>(i));
            ASObj row(2);
            row.FUN_1407cba60("binding", binding);
            unsigned owned = FUN_140f6e580(item, excluded);
            unsigned needed = item->FUN_140526c50();
            if (enabled != 0)
                needed = FUN_140627b80(needed, rate);
            row.FUN_1407cbb20("countText", FUN_1419021b0(owned, needed));
            rows.FUN_1422bc050(row.FUN_1422bb870());
            if (owned < needed) {
                if (item->FUN_140526320() != 0)
                    *price += static_cast<unsigned __int64>((needed - owned) * 1000);
            }
        }
    }
    data.FUN_1409adbe0("ingredient", rows.FUN_1422bb870());
}

// @0x140f6e250
// MS2-FUNCTIONAL: equivalent slot-count and ingredient-price calculation with typed temporaries.
void ItemSocketSystemPageBase::FUN_140f6e250(const CString& name, const CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<CItem> excluded, __int64* price, MS2Ptr<SaleParam> sale)
{
    *price = 0;
    int rate = 0;
    int enabled = 0;
    if (sale.get() != 0) {
        rate = sale->rate;
        enabled = sale->enabled;
    }
    size_t count = items.GetCount();
    for (size_t i = 0; i < count; ++i) {
        MS2Ptr<CItem> item(items.GetAt(i));
        if (!(item == 0)) {
            CString slotName = FUN_1422cc860(name, static_cast<int>(i));
            ItemInfoSlot* slot = FUN_140f6d300(slotName);
            if (slot == 0)
                continue;
            int owned = FUN_140f6e580(item, excluded);
            int needed = item->FUN_140526c50();
            if (enabled != 0)
                needed = FUN_140627b80(needed, rate);
            FUN_141416740(slot, owned, needed);
            if (owned < needed) {
                if (item->FUN_140526320() != 0)
                    *price += static_cast<__int64>((needed - owned) * 1000);
            }
        }
    }
}

// @0x140f6e500
// MS2-FUNCTIONAL: Scaleform return-value temporary layout differs.
void ItemSocketSystemPageBase::FUN_140f6e500(int index, bool isNew)
{
    if (!(m_root == 0))
        reinterpret_cast<Unk_SpInvokeB*>(m_root.operator->())->FUN_140f356e0("setNew", index, isNew);
}

// @0x140f6e580
// MS2-FUNCTIONAL: inventory count uses typed external declarations; cleanup layout differs.
int ItemSocketSystemPageBase::FUN_140f6e580(MS2Ptr<CItem> item, MS2Ptr<CItem> excluded)
{
    if (!(item == 0)) {
        if (item->FUN_140527840() != 0) {
            if (excluded.get() != 0)
                excluded->FUN_1405269d0(1);
            int count = FUN_140a5f180(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), item->FUN_1405276c0(), item->FUN_140526bd0());
            int group = FUN_14053c6f0(item->FUN_140527840());
            if (group != 0)
                count = FUN_140a5f780(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), group, 0);
            if (excluded.get() != 0)
                excluded->FUN_1405269d0(0);
            return count;
        }
    }
    return 0;
}

// @0x140f6e6e0
int ItemSocketSystemPageBase::FUN_140f6e6e0() { return 0x2020; }

// @0x140f6e700
// MS2-FUNCTIONAL: smart-pointer initialization temporary layout differs.
void ItemSocketSystemPageBase::FUN_140f6e700(__int64 uid)
{
    Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
    if (player != 0) {
        bool restore = false;
        MS2Ptr<CItem> item = FUN_141425750(uid, &restore);
        if (restore == true)
            FUN_140f6e780();
    }
}

// @0x140f6e780
void ItemSocketSystemPageBase::FUN_140f6e780() { m_restoreInventory = true; }
MS2_REPLACE_METHOD(0x140F6E780, ItemSocketSystemPageBase, FUN_140f6e780, 15, 0xE4A426E5);

// @0x140f6e830
ItemInfoSlot* FUN_140f6e830(const CString& name)
{
    return FUN_140c69ab0(FUN_1422c8e90(name));
}
MS2_REPLACE(0x140F6E830, FUN_140f6e830, 32, 0xCC520D13);

// The enum customization of the formatter for the result code (the exe copy keeps a stack cookie and scratch locals).
// @0x140f6eb80
// MS2-FUNCTIONAL: integer conversion and formatter cursor update match the enum path.
void format_arg(fmt::BasicFormatter<wchar_t>& formatter, const wchar_t*& cursor, const Unk_SocketPageResult& value)
{
    fmt::internal::Arg arg;
    arg.int_value = static_cast<int>(value);
    arg.type = fmt::internal::Arg::INT;
    cursor = formatter.format(cursor, arg);
}

// @0x140f6ee80
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// @0x140f6efa0
ItemSocketSystemPageGemStoneManage::ItemSocketSystemPageGemStoneManage()
    : m_state(0), m_selectedType(0)
{
    m_equipmentName = "GemStoneManagePage_slots0";
    m_gemName = "GemStoneManagePage_slots1";
    m_selectedName = "GemStoneManagePage_selectedSlot";
    m_socketName = "GemStoneManagePage_socketGemStone";
}

// @0x140f6f1a0
ItemSocketSystemPageGemStoneManage::~ItemSocketSystemPageGemStoneManage() { FUN_140f70620(); }

// @0x140f6f2f0
void ItemSocketSystemPageGemStoneManage::vfunc_1()
{
    ItemSocketSystemPageBase::vfunc_1();
    FUN_140f70620();
}
MS2_REPLACE_METHOD(0x140F6F2F0, ItemSocketSystemPageGemStoneManage, vfunc_1, 34, 0x75F0EDD4);

// @0x140f6f320
// MS2-FUNCTIONAL: real controls and callback delegates; temporary and cleanup layout differ.
void ItemSocketSystemPageGemStoneManage::vfunc_7(MS2Ptr<AScript> root)
{
    ItemSocketSystemPageBase::vfunc_7(root);
    if (!(root == 0)) {
        if (m_root == 0)
            m_root = root->FUN_1409b4560("m_gemStoneManagePage");
        if (!(m_root == 0)) {
            FUN_140f70770();
            FUN_140f70ad0();
            {
                MS2Ptr<ASMovieClip> slots = m_root->FUN_1409b4560("m_slots0");
                if (slots.get() != 0)
                    m_equipmentControl = reinterpret_cast<Unk_SpFindBag*>(slots.operator->())->FUN_140c4bc60("m_itemBag");
            }
            {
                MS2Ptr<ASMovieClip> slots = m_root->FUN_1409b4560("m_slots1");
                if (slots.get() != 0)
                    m_gemControl = reinterpret_cast<Unk_SpFindBag*>(slots.operator->())->FUN_140c4bc60("m_itemBag");
            }
            bool debug = FUN_14116d720(FUN_14025e7c0());
            m_debugButton = reinterpret_cast<Unk_SpFindButton*>(m_root.operator->())->FUN_140acce30("m_debugBtnFillIngredient");
            if (m_debugButton.get() != 0) {
                m_debugButton->vfunc_3(debug);
                if (debug)
                    FUN_1422ce240(m_debugButton.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageGemStoneManage::FUN_140f72a40), 0);
            }
            MS2Ptr<ItemSlotBag::CreateParam> param(new ItemSlotBag::CreateParam);
            param->m_nIconType = 0x415;
            param->m_nFlags = 0x20;
            // The exe's slot callback is a Delegate<void(ItemInfoSlot&, ASSlot&)> handle at +0x28 (iteminfoslot.h types it
            // as a pointer to the pointer-signature delegate).
            reinterpret_cast<Delegate<void(ItemInfoSlot&, ASSlot&)>&>(param->m_pfnSlot) =
                Delegate<void(ItemInfoSlot&, ASSlot&)>(this, &ItemSocketSystemPageGemStoneManage::FUN_140f72e60);
            FUN_140f6d4c0(m_equipmentName, m_equipment, param);
            FUN_140f6d450(m_gemName, m_gems, 0x15, 0x20);
            FUN_140f6d590(m_selectedName, m_selected, 0x405, 0x20);
            ASObj data(2);
            data.FUN_1407cba60("bagId0", m_equipmentName);
            data.FUN_1407cba60("bagId1", m_gemName);
            data.FUN_1407cba60("selectedSlotId", m_selectedName);
            m_root->Invoke("initData", data.FUN_1422bb870());
            m_state = 0;
            FUN_1419cae20(FUN_140a6a840(), this);
            FUN_140f6dbe0(m_equipmentControl);
            FUN_140f6dbe0(m_gemControl);
            UIHighlightGameMenu* dialog = FUN_140f73450();
            if (dialog != 0) {
                int page = 0;
                FUN_140c244b0(dialog, &page, 0);
            }
        }
    }
}

// @0x140f6fdb0
void ItemSocketSystemPageGemStoneManage::vfunc_2()
{
    ItemSocketSystemPageBase::vfunc_2();
    FUN_140f70620();
}

// @0x140f6fde0
void ItemSocketSystemPageGemStoneManage::vfunc_5(CInPacket* packet)
{
    ItemSocketSystemPageBase::vfunc_5(packet);
    unsigned char operation = packet->vfunc_o8_1();
    FUN_140f6d620(1);
    if (operation == 9)
        FUN_140f72460(packet);
    else if (operation == 11)
        FUN_140f727e0(packet);
    else if (operation == 18)
        vfunc_8(packet);
}

// @0x140f6fe90
// MS2-FUNCTIONAL: typed ASData event decoding and smart-pointer temporary layout.
int ItemSocketSystemPageGemStoneManage::vfunc_3(const char* event, const Scaleform::GFx::Value* args, int count)
{
    if (ItemSocketSystemPageBase::vfunc_3(event, args, count) == 0) {
        if (_stricmp("onIndexChangeSlot0", event) == 0) {
            ASData data;
            if (data.FUN_1422b9620(args, count) != 0) {
                MS2Ptr<CItem> item = FUN_140f71e10(m_equipment, data.FUN_1422b8a10());
                FUN_140f70f90(item);
            }
            return 1;
        } else if (_stricmp("onIndexChangeSlot1", event) == 0) {
            ASData data;
            if (data.FUN_1422b9620(args, count) != 0) {
                MS2Ptr<CItem> item = FUN_140f71e10(m_gems, data.FUN_1422b8a10());
                FUN_140f71330(item);
            }
            return 1;
        } else if (_stricmp("onClickSocketDel", event) == 0) {
            ASData data;
            if (data.FUN_1422b9620(args, count) != 0)
                FUN_140f71530(data.FUN_1422b8b10());
            return 1;
        }
        return 0;
    }
    return 1;
}

// @0x140f70150
// MS2-FUNCTIONAL: secondary listener this-adjustment and typed slot refresh.
void ItemSocketSystemPageGemStoneManage::vfunc_4(void* rawItem, int)
{
    CItem* item = static_cast<CItem*>(rawItem);
    if (item != 0) {
        if (FUN_14053d840(item->FUN_140527840())) {
            int index = -1;
            MS2Ptr<CItem> found = FUN_140f6d6b0(item->FUN_140526a50(), m_gems, &index);
            if (index != -1)
                FUN_140f6d340(FUN_1422cc860(m_gemName, index), found);
        }
    }
}

// @0x140f702b0
// MS2-FUNCTIONAL: secondary listener this-adjustment and typed item map.
void ItemSocketSystemPageGemStoneManage::vfunc_2(void* rawItem)
{
    CItem* item = static_cast<CItem*>(rawItem);
    if (item != 0) {
        if (FUN_14053d840(item->FUN_140527840()) && !(m_root == 0)) {
            int index = -1;
            __int64 uid = item->FUN_140526a50();
            MS2Ptr<CItem> found = FUN_140f6d6b0(uid, m_gems, &index);
            if (index < 0) {
                found.AssignRaw(item);
                FUN_140f6db00(found, m_gemName, m_gems, m_gemControl);
                m_gemsByUid.SetAt((int)uid, found);
            }
        }
    }
}

// @0x140f70480
// MS2-FUNCTIONAL: secondary listener this-adjustment and typed item map removal.
void ItemSocketSystemPageGemStoneManage::vfunc_3(void* rawItem, bool updating)
{
    CItem* item = static_cast<CItem*>(rawItem);
    if (item != 0) {
        if (FUN_14053d840(item->FUN_140527840()) && !(m_root == 0) && !m_gems.IsEmpty() && !updating) {
            int index = -1;
            __int64 uid = item->FUN_140526a50();
            MS2Ptr<CItem> found = FUN_140f6d6b0(uid, m_gems, &index);
            FUN_140f6d9a0(index, m_gemName, m_gems, m_gemControl);
            m_gemsByUid.RemoveKey((int)uid);
        }
    }
}

// @0x140f70620
void ItemSocketSystemPageGemStoneManage::FUN_140f70620()
{
    FUN_14141f970(m_equipmentName);
    FUN_14141f970(m_gemName);
    FUN_141415600(m_selectedName);
    FUN_140cfe1b0(m_socketName);
    m_selected = 0;
    m_debugButton = 0;
    m_equipment.RemoveAll();
    m_gemsByUid.RemoveAll();
    m_gems.RemoveAll();
    m_sockets.RemoveAll();
    m_equipmentControl = 0;
    m_gemControl = 0;
    m_state = 0;
    m_selectedType = 0;
    FUN_1419caeb0(FUN_140a6a840(), this);
}
MS2_REPLACE_METHOD(0x140F70620, ItemSocketSystemPageGemStoneManage, FUN_140f70620, 316, 0x163B1C62);

// @0x140f70770
// MS2-FUNCTIONAL: typed inventory and equipped-item enumeration; smart-pointer temporaries differ.
void ItemSocketSystemPageGemStoneManage::FUN_140f70770()
{
    Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
    if (player != 0) {
        m_equipment.RemoveAll();
        CAtlArray<MS2Ptr<CItem>> items;
        FUN_140a60880(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), 0, items);
        FUN_140a60880(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), 1, items);
        if (!items.IsEmpty()) {
            size_t count = items.GetCount();
            for (size_t i = 0; i < count; ++i) {
                MS2Ptr<CItem> item(items.GetAt(i));
                if (!(item == 0) && item->FUN_1405279c0() != 0 && item->FUN_140529560() != 0
                    && item->FUN_1405279c0()->FUN_140620a50() != 0)
                    m_equipment.Add(item);
            }
        }
        CAtlList<MS2Ptr<CEquipItem>> equipped(10);
        Unk_SocketPageInventory* inventory = FUN_1416561a0(player);
        FUN_1411e1ce0(inventory, equipped, 0);
        FUN_1411e1ce0(inventory, equipped, 1);
        POSITION pos = equipped.GetHeadPosition();
        while (pos != 0) {
            MS2Ptr<CEquipItem> equip(equipped.GetAt(pos));
            if (!!equip) {
                MS2Ptr<CItem> item = equip->FUN_1411dc7a0();
                if (!!item && item->FUN_1405279c0() != 0 && item->FUN_1405279c0()->FUN_140620a50() != 0)
                    m_equipment.Add(item);
            }
            equipped.GetNext(pos);
        }
    }
}

// @0x140f70ad0
// MS2-FUNCTIONAL: typed inventory enumeration and UID-keyed map insertion.
void ItemSocketSystemPageGemStoneManage::FUN_140f70ad0()
{
    if (FUN_141bd0cc0(FUN_1403ed2d0()) != 0) {
        m_gemsByUid.RemoveAll();
        int category = FUN_140f6d670();
        CAtlArray<MS2Ptr<CItem>> items;
        FUN_140a60880(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), category, items);
        if (!items.IsEmpty()) {
            size_t count = items.GetCount();
            for (size_t i = 0; i < count; ++i) {
                MS2Ptr<CItem> item(items.GetAt(i));
                if (!(item == 0) && item->FUN_140527840() != 0) {
                    if (FUN_14053d840(item->FUN_140527840()))
                        m_gemsByUid.SetAt((int)item->FUN_140526a50(), item);
                }
            }
        }
    }
}

// @0x140f70c70
// MS2-FUNCTIONAL: typed UID-map walk and gemstone-type filter; smart-pointer temporaries differ.
void ItemSocketSystemPageGemStoneManage::FUN_140f70c70()
{
    if (!m_gemsByUid.IsEmpty() && !(m_selected == 0) && m_selected->FUN_140527840() != 0) {
        int type = FUN_140222ce0(MS2Ptr<CItemData>(m_selected->FUN_140527840()));
        if (m_selectedType != type) {
            m_gems.RemoveAll();
            POSITION pos = m_gemsByUid.GetStartPosition();
            while (pos != 0) {
                MS2Ptr<CItem> item(m_gemsByUid.GetValueAt(pos));
                if (!(item == 0) && item->FUN_140527840() != 0) {
                    unsigned id = item->FUN_1405276c0();
                    MS2Ptr<CItemGemStoneData> data = FUN_14062c280()->FUN_1405b1a60(id);
                    if (!(data == 0)) {
                        if (FUN_1406272f0(type, data))
                            m_gems.Add(item);
                    }
                }
                m_gemsByUid.GetNext(pos);
            }
            ItemSlotBag* bag = FUN_140c54590(m_gemName);
            if (bag != 0) {
                FUN_14141ff80(bag, (int)m_gems.GetCount());
                if (m_gemControl.get() != 0)
                    FUN_1422cf860(m_gemControl.operator->());
            }
            m_selectedType = type;
        }
    }
}

// @0x140f70f90
// MS2-FUNCTIONAL: Scaleform data and selection refresh with typed temporaries.
void ItemSocketSystemPageGemStoneManage::FUN_140f70f90(MS2Ptr<CItem> item)
{
    if (!(m_root == 0) && !(item == 0)) {
        if (item->FUN_1405279c0() != 0) {
            if (FUN_141425750(item->FUN_140526a50(), 0) == 0) {
                FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
                return;
            }
            FUN_141276180(s_strManageSound, CString(""));
            m_selected = item;
            FUN_140f6d340(m_selectedName, m_selected);
            unsigned open = m_selected->FUN_1405279c0()->FUN_140620a20();
            ASObj data(2);
            data.FUN_1407cbb20("itemName", m_selected->FUN_140528160());
            data.FUN_1409c0d20("openCount", open);
            FUN_140f71ea0(data);
            m_root->Invoke("playSelect", data.FUN_1422bb870());
            m_state = 1;
            if (open != 0) {
                FUN_140f70c70();
                FUN_140f6dbe0(m_gemControl);
            }
        }
    }
}

// @0x140f71330
// MS2-FUNCTIONAL: confirmation delegate and smart-pointer argument temporaries differ.
void ItemSocketSystemPageGemStoneManage::FUN_140f71330(MS2Ptr<CItem> gem)
{
    if (!(m_root == 0) && !(gem == 0)) {
        FUN_141276180(s_strManageSound, CString(""));
        if (!FUN_14062a3d0(m_selected, -1, gem, Delegate<bool(int, const CMsgBoxData&)>(this, &ItemSocketSystemPageGemStoneManage::FUN_140f72bc0)))
            FUN_140f6dbe0(m_gemControl);
    }
}

// @0x140f71530
// MS2-FUNCTIONAL: localized put-off confirmation box with typed message-box handle and string temporaries.
void ItemSocketSystemPageGemStoneManage::FUN_140f71530(int slot)
{
    if (!(m_selected == 0) && m_selected->FUN_140527840() != 0) {
        CItemSocket* socket = m_selected->FUN_1405279c0();
        if (socket != 0 && socket->FUN_140620a50() != 0 && socket->FUN_140620a20() != 0) {
            if (socket->FUN_140621020(slot)) {
                FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_socket_empty"), 1);
                return;
            }
            int gemId = socket->FUN_140620ac0(slot);
            unsigned short rate = FUN_140626f20(gemId);
            int costItemId, costCount;
            FUN_1406284f0(rate, m_selected->FUN_140527840()->FUN_14053de40(), &costItemId, &costCount);
            MS2Ptr<CMsgBoxData> box(0);
            int shown = slot + 1;
            bool lack = false;
            __int64 fee = 0;
            int itemId = FUN_1405575b0(FUN_140281980(), costItemId);
            if (costCount < 1) {
                box = FUN_140d73d20(1, FUN_14062b4f0(CStringW(L"s_itemsocketsystem_msg_ask_gemstone_put_off_free"), &shown), 0, CStringW(L""));
            } else {
                int grade = FUN_14053feb0(itemId);
                int have = FUN_140a5f780(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), costItemId, grade);
                if (have < costCount) {
                    if (costItemId == 0x60) {
                        fee = (__int64)(costCount - have) * 1000;
                        lack = DAT_143ab2898 < fee;
                    } else {
                        lack = true;
                    }
                }
                CStringW name = FUN_1401a9d70()->FUN_141811980(1, itemId);
                CStringW msg = FUN_1409e8970(CStringW(L"s_itemsocketsystem_msg_ask_gemstone_put_off"), shown, costCount);
                if (fee != 0)
#ifdef __clang__
                    // clang otherwise emits an unavailable CopyChars DLL import; bind the exe's operator+.
                    msg += FUN_1401d0160(L"\n", FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(fee)));
#else
                    msg += L"\n" + FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(fee));
#endif
                box = FUN_140d73d20(0x1a, msg, 0, CStringW(L""));
                if (box == 0)
                    return;
                CStringW countText;
                if (lack)
                    countText = FUN_1409e8970(CStringW(L"s_itemsocketsystem_text_item_count_lack"), have, costCount);
                else
                    countText = FUN_1409e8970(CStringW(L"s_itemsocketsystem_text_item_count"), have, costCount);
                FUN_141a020b0(box.operator->(), itemId, grade, 0);
                box->FUN_141a01570(msg);
                box->FUN_141a015d0(countText);
                box->FUN_141a01800(1);
            }
            box->FUN_141a024a0(0);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &ItemSocketSystemPageGemStoneManage::FUN_140f72c80));
            box->FUN_140533ff0(slot);
            FUN_140f73320(box.operator->(), lack);
            FUN_140d73c60(box);
        }
    }
}

// @0x140f71e10
MS2Ptr<CItem> ItemSocketSystemPageGemStoneManage::FUN_140f71e10(const CAtlArray<MS2Ptr<CItem>>& items, int index)
{
    if (!items.IsEmpty())
        return items.GetAt(index);
    return MS2Ptr<CItem>(0);
}

// @0x140f71ea0
// MS2-FUNCTIONAL: socket gemstone records built with typed smart pointers; temporary layout differs.
void ItemSocketSystemPageGemStoneManage::FUN_140f71ea0(ASObj& data)
{
    FUN_140cfe1b0(m_socketName);
    m_sockets.RemoveAll();
    if (!(m_selected == 0) && m_selected->FUN_1405279c0() != 0) {
        CItemSocket* socket = m_selected->FUN_1405279c0();
        unsigned open = socket->FUN_140620a20();
        MS2Ptr<CItem> selected(m_selected);
        for (unsigned i = 0; i < open; ++i) {
            MS2Ptr<CGemStoneItem> record(new CGemStoneItem);
            if (!(record == 0)) {
                MS2Ptr<CItem> gem(0);
                MS2Ptr<TSocketGemStoneInfo> info = socket->FUN_140620b70(i);
                if (info.get() != 0 && !info->FUN_14061fab0())
                    gem = FUN_140f6d050(info, 0, false);
                record->FUN_140c4e720(selected, gem);
                m_sockets.Add(record);
            }
        }
        int left = socket->FUN_140620a70();
        for (int i = 0; i < left; ++i) {
            MS2Ptr<CGemStoneItem> record(new CGemStoneItem);
            if (!(record == 0)) {
                record->FUN_140c4e720(selected, MS2Ptr<CItem>(0), true);
                m_sockets.Add(record);
            }
        }
        FUN_140cfe0c0(m_socketName, (int)m_sockets.GetCount(), &m_sockets, FUN_140cfe450, 0x415, 0x20);
        data.FUN_1407cba60("socketBagId", m_socketName);
        if (open == 0)
            data.FUN_1409c0dc0("desc", "$s_itemsocketsystem_gemstonemanage_msg_socket_lock_all");
    }
}

// @0x140f72460
// MS2-FUNCTIONAL: typed equip-result packet and socket record refresh.
void ItemSocketSystemPageGemStoneManage::FUN_140f72460(CInPacket* packet)
{
    if (!(m_root == 0)) {
        Unk_SSGGemEquip result;
        FUN_140628a00(result, *packet);
        bool restore = false;
        MS2Ptr<CItem> item = FUN_141425750(result.m_nItemUid, &restore);
        if (!(item == 0) && item->FUN_1405279c0() != 0) {
            MS2Ptr<TSocketGemStoneInfo> info(result.m_spGem);
            if (info == 0)
                return;
            FUN_140f6dbe0(m_gemControl);
            MS2Ptr<CGemStoneItem> record = FUN_140f733a0(m_sockets, result.m_nSlot);
            if (record == 0)
                return;
            record->m_gemstone = FUN_140f6d050(info, 0, false);
            Unk_GemStoneSlot* slot = FUN_140f73380(FUN_1422cc860(m_socketName, result.m_nSlot));
            if (slot != 0) {
                FUN_140cfd950(slot, MS2Ptr<CGemStoneItem>(record));
                slot->vfunc_10();
            }
            if (restore)
                FUN_140f6e780();
        }
    }
}

// @0x140f727e0
// MS2-FUNCTIONAL: typed unequip-result packet and socket record refresh.
void ItemSocketSystemPageGemStoneManage::FUN_140f727e0(CInPacket* packet)
{
    if (!(m_root == 0)) {
        Unk_SSGGemUnequip result;
        FUN_140628be0(result, *packet);
        bool restore = false;
        MS2Ptr<CItem> item = FUN_141425750(result.m_nItemUid, &restore);
        if (!(item == 0) && item->FUN_1405279c0() != 0) {
            FUN_140f6dbe0(m_gemControl);
            MS2Ptr<CGemStoneItem> record = FUN_140f733a0(m_sockets, result.m_nSlot);
            if (record == 0)
                return;
            record->m_gemstone = 0;
            Unk_GemStoneSlot* slot = FUN_140f73380(FUN_1422cc860(m_socketName, result.m_nSlot));
            if (slot != 0) {
                FUN_140cfd950(slot, MS2Ptr<CGemStoneItem>(record));
                slot->vfunc_10();
            }
            if (restore)
                FUN_140f6e780();
        }
    }
}

// @0x140f72a40
// MS2-FUNCTIONAL: debug fill-ingredient request through the typed packet record.
void ItemSocketSystemPageGemStoneManage::FUN_140f72a40(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_selected == 0) && m_selected->FUN_1405279c0() != 0 && DAT_143ab2914 > 49 && m_state == 1) {
        CItemSocket* socket = m_selected->FUN_1405279c0();
        if (socket->FUN_140620a50() != 0 && socket->FUN_140620a20() != 0) {
            int gemId = socket->FUN_140621d60();
            if (gemId != 0) {
                Unk_SockMsgIIL msg = {};
                msg.m_nB8 = 10;
                msg.m_nC = gemId;
                msg.m_n10 = m_selected->FUN_140526a50();
                COutPacket out(0x88, 0);
                out.Encode1(0x10);
                FUN_140629de0(msg, out);
                FUN_140710590(out);
            }
        }
    }
}

// @0x140f72bc0
bool ItemSocketSystemPageGemStoneManage::FUN_140f72bc0(int button, const CMsgBoxData& box)
{
    if (!(m_selected == 0)) {
        if (button == 0)
            FUN_14062abb0(m_selected, box);
        else if (button == 1)
            FUN_140f6dbe0(m_gemControl);
    }
    return true;
}

// @0x140f72c80
// MS2-FUNCTIONAL: typed unequip request packet and localized errors.
bool ItemSocketSystemPageGemStoneManage::FUN_140f72c80(int button, const CMsgBoxData& box)
{
    if (!(m_selected == 0) && button == 0) {
        __int64 uid = m_selected->FUN_140526a50();
        if (!(FUN_141425750(uid, 0) == 0)) {
            int slot = box.FUN_141a02e50(0, 0);
            if (!FUN_141a02e10(&box, 1, 0)) {
                Unk_SSGGemUnequip msg;
                msg.m_nItemUid = uid;
                msg.m_nGemUid = 0;
                msg.m_nSlot = slot;
                COutPacket out(0x88, 0);
                out.Encode1(10);
                FUN_140628b70(msg, out);
                FUN_140710590(out);
            } else {
                FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_lack_price"), 1);
            }
        } else {
            FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
        }
    }
    return true;
}

// @0x140f72e60
// MS2-FUNCTIONAL: slot seal/equip marks with the typed item handle.
void ItemSocketSystemPageGemStoneManage::FUN_140f72e60(ItemInfoSlot& slot, ASSlot& asSlot)
{
    bool seal = false;
    MS2Ptr<CItem> item = slot.vfunc_25();
    if (item.get() != 0) {
        if (item->FUN_1405279c0() == 0)
            seal = false;
        else
            seal = item->FUN_1405279c0()->FUN_140620a20() == 0;
        if (!FUN_1414258e0(item->FUN_140526a50()))
            asSlot.FUN_1409c20d0(1);
    }
    asSlot.FUN_1409c1f00(seal);
}

// @0x140f73320
void FUN_140f73320(CMsgBoxData* box, bool value)
{
    FUN_140165320(&box->m_args, FUN_140719730(value));
}
MS2_REPLACE(0x140F73320, FUN_140f73320, 93, 0x0E528F8D);

// @0x140f73380
Unk_GemStoneSlot* FUN_140f73380(const CString& name)
{
    return FUN_140cfe620(FUN_1422c8e90(name));
}
MS2_REPLACE(0x140F73380, FUN_140f73380, 32, 0xF09409FE);

// @0x140f733a0
MS2Ptr<CGemStoneItem> ItemSocketSystemPageGemStoneManage::FUN_140f733a0(CAtlArray<MS2Ptr<CGemStoneItem>>& items, unsigned index)
{
    if (!items.IsEmpty() && index < items.GetCount())
        return items.GetAt(index);
    return MS2Ptr<CGemStoneItem>(0);
}

// @0x140f73450
// MS2-FUNCTIONAL: typed UI handle; temporary cleanup layout differs.
UIHighlightGameMenu* FUN_140f73450()
{
    Unk_SocketPageUIService* service = FUN_1403ed2b0();
    if (service == 0)
        return 0;
    MS2Ptr<UIObject> ui = reinterpret_cast<Unk_SpUIService*>(service)->FUN_141adcea0(FUN_140f73c10());
    if (!ui)
        return 0;
    return dynamic_cast<UIHighlightGameMenu*>(ui.operator->());
}

// @0x140f73c10
int FUN_140f73c10() { return 0x4f75; }

// @0x140f743d0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

// The tooltip callback delegate's out-of-line members (delegate.h declares them only).
// @0x140f7b310
template <> inline Delegate<void(ItemInfoSlot&, ASTooltip&)>::~Delegate()
{
    if (m_pImpl != 0)
        delete m_pImpl;
}

// @0x140f7b520
template <> inline Delegate<void(ItemInfoSlot&, ASTooltip&)>& Delegate<void(ItemInfoSlot&, ASTooltip&)>::operator=(const Delegate& o)
{
    if (this != &o) {
        if (m_pImpl != 0)
            delete m_pImpl;
        if (o.m_pImpl == 0)
            m_pImpl = 0;
        else
            m_pImpl = o.m_pImpl->vfunc_1();
    }
    return *this;
}

// @0x140f744f0
TGemStoneInEquip::TGemStoneInEquip(MS2Ptr<CItem> gem, MS2Ptr<CItem> equipment, int slot)
    : m_gem(gem), m_equipment(equipment), m_slot(slot)
{
}

// @0x140f74590
bool TGemStoneInEquip::FUN_140f74590()
{
    if (!(m_gem == 0) && !(m_equipment == 0) && m_slot >= 0)
        return false;
    return true;
}

// @0x140f74600
ItemSocketSystemPageGemStoneUpgrade::ItemSocketSystemPageGemStoneUpgrade()
    : m_state(0), m_selectedUid(0), m_highlightUid(0)
{
    m_gemsName = "GemStoneUpgradePage_gems";
    m_selectedName = "GemStoneUpgradePage_selectedSlot";
    m_ingredientsName = "GemStoneUpgradePage_ingredients";
    m_nextName = "GemStoneUpgradePage_nextSlot";
}

// @0x140f74820
ItemSocketSystemPageGemStoneUpgrade::~ItemSocketSystemPageGemStoneUpgrade() { FUN_140f79210(); }

// @0x140f74980
void ItemSocketSystemPageGemStoneUpgrade::vfunc_1()
{
    ItemSocketSystemPageBase::vfunc_1();
    FUN_140f79210();
}

// @0x140f749b0
// MS2-FUNCTIONAL: real controls and callback delegates; temporary and cleanup layout differ.
void ItemSocketSystemPageGemStoneUpgrade::vfunc_7(MS2Ptr<AScript> root)
{
    ItemSocketSystemPageBase::vfunc_7(root);
    if (!(root == 0)) {
        if (m_root == 0)
            m_root = root->FUN_1409b4560("m_gemStoneUpgradePage");
        if (!(m_root == 0)) {
            FUN_140f75c50();
            m_bag = reinterpret_cast<Unk_SpFindBag*>(m_root.operator->())->FUN_140c4bc60("m_itemBag");
            bool debug = FUN_14116d720(FUN_14025e7c0());
            m_debugAction = reinterpret_cast<Unk_SpFindButton*>(m_root.operator->())->FUN_140acce30("m_debugBtnAction");
            if (m_debugAction.get() != 0) {
                m_debugAction->vfunc_3(debug);
                if (debug)
                    FUN_1422ce240(m_debugAction.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageGemStoneUpgrade::FUN_140f79760), 0);
            }
            m_debugFill = reinterpret_cast<Unk_SpFindButton*>(m_root.operator->())->FUN_140acce30("m_debugBtnFillIngredient");
            if (m_debugFill.get() != 0) {
                m_debugFill->vfunc_3(debug);
                if (debug)
                    FUN_1422ce240(m_debugFill.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageGemStoneUpgrade::FUN_140f798e0), 0);
            }
            m_debugFillUnit = reinterpret_cast<Unk_SpFindButton*>(m_root.operator->())->FUN_140acce30("m_debugBtnFillIngredientUnit");
            if (m_debugFillUnit.get() != 0) {
                m_debugFillUnit->vfunc_3(debug);
                if (debug)
                    FUN_1422ce240(m_debugFillUnit.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageGemStoneUpgrade::FUN_140f799d0), 0);
            }
            MS2Ptr<ItemSlotBag::CreateParam> param(new ItemSlotBag::CreateParam);
            param->m_nIconType = 0x415;
            param->m_nFlags = 0x20;
            // The exe's callbacks are Delegate<void(ItemInfoSlot&, ...)> handles at +0x28 / +0x30 (see vfunc_7 above).
            reinterpret_cast<Delegate<void(ItemInfoSlot&, ASSlot&)>&>(param->m_pfnSlot) =
                Delegate<void(ItemInfoSlot&, ASSlot&)>(this, &ItemSocketSystemPageGemStoneUpgrade::FUN_140f79ad0);
            reinterpret_cast<Delegate<void(ItemInfoSlot&, ASTooltip&)>&>(param->m_pfnTip) =
                Delegate<void(ItemInfoSlot&, ASTooltip&)>(this, &ItemSocketSystemPageGemStoneUpgrade::FUN_140f79c50);
            FUN_140f6d4c0(m_gemsName, m_gems, param);
            FUN_140f6d590(m_selectedName, m_selected, 0x405, 0x20);
            ASObj data(2);
            data.FUN_1407cba60("bagId", m_gemsName);
            data.FUN_1407cba60("selectedSlotId", m_selectedName);
            m_root->Invoke("initData", data.FUN_1422bb870());
            m_state = 0;
            FUN_1419cae20(FUN_140a6a840(), this);
            FUN_140939a10()->RegisterNotify(CStringW(L"NotifyGameEventChanged"), Delegate<void(NotifyObject*)>(this, &ItemSocketSystemPageGemStoneUpgrade::FUN_140f7a440));
            FUN_140f6dbe0(m_bag);
        }
    }
}

// @0x140f75650
void ItemSocketSystemPageGemStoneUpgrade::vfunc_2()
{
    ItemSocketSystemPageBase::vfunc_2();
    FUN_140f79210();
}

// @0x140f75680
void ItemSocketSystemPageGemStoneUpgrade::vfunc_5(CInPacket* packet)
{
    ItemSocketSystemPageBase::vfunc_5(packet);
    unsigned char operation = packet->vfunc_o8_1();
    FUN_140f6d620(1);
    if (operation == 7)
        FUN_140f78720(packet);
    else if (operation == 5)
        FUN_140f787a0(packet);
    else if (operation == 16)
        FUN_140f78f30(packet);
    else if (operation == 18)
        vfunc_8(packet);
}

// @0x140f75750
// MS2-FUNCTIONAL: typed ASData event decoding.
int ItemSocketSystemPageGemStoneUpgrade::vfunc_3(const char* event, const Scaleform::GFx::Value* args, int count)
{
    if (_stricmp("onIndexChangeSlot", event) == 0) {
        ASData data;
        if (data.FUN_1422b9620(args, count) != 0)
            FUN_140f76420(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("onClickAction", event) == 0) {
        if (m_state == 1)
            FUN_140f76970();
        else if (m_state == 2)
            FUN_140f770b0();
    }
    return 0;
}

// @0x140f75860
// MS2-FUNCTIONAL: secondary listener this-adjustment and typed gemstone list append.
void ItemSocketSystemPageGemStoneUpgrade::vfunc_2(void* rawItem)
{
    CItem* item = static_cast<CItem*>(rawItem);
    if (item != 0) {
        if (FUN_14053d840(item->FUN_140527840()) && !(m_root == 0)) {
            int index = -1;
            MS2Ptr<CItem> found = FUN_140f7a190(item->FUN_140526a50(), &index);
            if (index < 0)
                FUN_140f6db00(MS2Ptr<CItem>(item), m_gemsName, m_gems, m_bag);
        }
    }
}

// @0x140f759e0
// MS2-FUNCTIONAL: secondary listener this-adjustment and typed gemstone list erase.
void ItemSocketSystemPageGemStoneUpgrade::vfunc_3(void* rawItem, bool updating)
{
    CItem* item = static_cast<CItem*>(rawItem);
    if (item != 0) {
        if (FUN_14053d840(item->FUN_140527840()) && !(m_root == 0) && !m_gems.IsEmpty() && !updating) {
            int index = -1;
            MS2Ptr<CItem> found = FUN_140f7a190(item->FUN_140526a50(), &index);
            if (index != -1)
                FUN_140f6d9a0(index, m_gemsName, m_gems, m_bag);
        }
    }
}

// @0x140f75b60
// MS2-FUNCTIONAL: secondary listener this-adjustment and typed slot refresh.
void ItemSocketSystemPageGemStoneUpgrade::vfunc_4(void* rawItem, int)
{
    CItem* item = static_cast<CItem*>(rawItem);
    if (item != 0) {
        if (FUN_14053d840(item->FUN_140527840())) {
            int index = -1;
            MS2Ptr<CItem> found = FUN_140f7a190(item->FUN_140526a50(), &index);
            if (index != -1)
                FUN_140f6d400(FUN_1422cc860(m_gemsName, index));
        }
    }
}

// @0x140f75c50
// MS2-FUNCTIONAL: typed inventory, equipped-item and socket enumeration; smart-pointer temporaries differ.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f75c50()
{
    Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
    if (player != 0) {
        m_gems.RemoveAll();
        m_equipped.RemoveAll();
        int category = FUN_140f6d670();
        CAtlArray<MS2Ptr<CItem>> items;
        FUN_140a60880(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), category, items);
        if (!items.IsEmpty()) {
            size_t count = items.GetCount();
            for (size_t i = 0; i < count; ++i) {
                MS2Ptr<CItem> item(items.GetAt(i));
                if (!(item == 0)) {
                    if (FUN_14053d840(item->FUN_140527840()))
                        m_gems.Add(item);
                }
            }
        }
        CAtlArray<MS2Ptr<CItem>> equipment;
        FUN_140a60880(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), 0, equipment);
        FUN_140a60880(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), 1, equipment);
        CAtlList<MS2Ptr<CEquipItem>> equipped(10);
        Unk_SocketPageInventory* inventory = FUN_1416561a0(player);
        FUN_1411e1ce0(inventory, equipped, 0);
        FUN_1411e1ce0(inventory, equipped, 1);
        POSITION pos = equipped.GetHeadPosition();
        while (pos != 0) {
            MS2Ptr<CEquipItem> equip(equipped.GetAt(pos));
            if (!!equip) {
                MS2Ptr<CItem> item = equip->FUN_1411dc7a0();
                if (!!item && item->FUN_140529560() != 0) {
                    CItemSocket* socket = item->FUN_1405279c0();
                    if (socket->FUN_140620a20() != 0 && !socket->FUN_140621310())
                        equipment.Add(item);
                }
            }
            equipped.GetNext(pos);
        }
        if (!equipment.IsEmpty()) {
            size_t count = equipment.GetCount();
            for (size_t i = 0; i < count; ++i) {
                MS2Ptr<CItem> equip(equipment.GetAt(i));
                if (!(equip == 0)) {
                    if (equip->FUN_1405279c0() == 0)
                        continue;
                    CItemSocket* socket = equip->FUN_1405279c0();
                    if (socket->FUN_140620a20() != 0) {
                        Unk_SocketGemArray& gems = socket->FUN_140620c20();
                        if (!gems.IsEmpty()) {
                            for (unsigned slot = 0; slot < gems.GetCount(); ++slot) {
                                MS2Ptr<TSocketGemStoneInfo> info(gems.GetAt(slot));
                                if (!(info == 0) && info->m_nGemId != 0) {
                                    MS2Ptr<CItem> gem = FUN_140f6d050(MS2Ptr<TSocketGemStoneInfo>(info), 0, true);
                                    if (gem.get() != 0) {
                                        MS2Ptr<TGemStoneInEquip> record(new TGemStoneInEquip(gem, equip, slot));
                                        if (record == 0)
                                            continue;
                                        m_equipped.SetAt(gem->FUN_140526a50(), record);
                                        m_gems.Add(gem);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// @0x140f76420
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f76420(int index)
{
    if (!(m_root == 0))
        FUN_140f764b0(FUN_140f7a0c0(index));
}

// @0x140f764b0
// MS2-FUNCTIONAL: typed select request packet; smart-pointer temporaries differ.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f764b0(MS2Ptr<CItem> item)
{
    if (!(m_root == 0) && !(item == 0)) {
        __int64 uid = item->FUN_140526a50();
        __int64 targetUid = uid;
        MS2Ptr<TGemStoneInEquip> record = FUN_140f7a380(uid);
        if (record.get() != 0 && record->m_equipment.get() != 0)
            targetUid = record->m_equipment->FUN_140526a50();
        MS2Ptr<CItem> owner = FUN_141425750(targetUid, 0);
        if (owner == 0) {
            FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
            return;
        }
        if (FUN_140f79e10(record, owner, 0)) {
            MS2Ptr<CItemGemStoneData> row = FUN_14062c280()->FUN_1405b1a60(item->FUN_1405276c0());
            if (!(row == 0)) {
                FUN_141276180(s_strUpgradeButtonSound, CString(""));
                if (FUN_140627020(row)) {
                    FUN_140f77360(item);
                } else {
                    CCItemSocketSystemPacket::SelectItem msg;
                    msg.m_nGemUid = uid;
                    if (record.get() != 0) {
                        msg.m_nUid = owner->FUN_140526a50();
                        msg.m_nSlot = record->m_slot;
                    }
                    COutPacket out(0x88, 0);
                    out.Encode1(6);
                    FUN_140629c50(msg, out);
                    FUN_140710590(out);
                    FUN_140f6d620(0);
                }
            }
        }
    }
}

// @0x140f76970
// MS2-FUNCTIONAL: ingredient and fee checks with the typed upgrade request packet.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f76970()
{
    if (!(m_selected == 0)) {
        __int64 uid = m_selected->FUN_140526a50();
        __int64 targetUid = uid;
        MS2Ptr<TGemStoneInEquip> record = FUN_140f7a380(uid);
        if (record.get() != 0 && record->m_equipment.get() != 0)
            targetUid = record->m_equipment->FUN_140526a50();
        MS2Ptr<CItem> owner = FUN_141425750(targetUid, 0);
        if (owner == 0) {
            FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
            return;
        }
        if (!FUN_140f79e10(record, owner, 0))
            return;
        MS2Ptr<CItemGemStoneData> row = FUN_14062c280()->FUN_1405b1a60(m_selected->FUN_1405276c0());
        if (row == 0)
            return;
        if (FUN_140627020(row)) {
            FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_gemstone_maxlevel"), 1);
            return;
        }
        unsigned rate = 0;
        unsigned bonus = 0;
        Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
        if (player != 0)
            bonus = (unsigned)(FUN_1411e1110(FUN_1416561a0(player), 0xac) * 10000.0f);
        int sale = FUN_140627a20(row->m_nMask, &rate, bonus);
        __int64 fee = 0;
        size_t count = m_ingredients.GetCount();
        for (size_t i = 0; i < count; ++i) {
            MS2Ptr<CItem> ingredient(m_ingredients.GetAt(i));
            if (!(ingredient == 0)) {
                int need = ingredient->FUN_140526c50();
                if (sale != 0)
                    need = FUN_140627b80(need, rate);
                int have = FUN_140f6e580(ingredient, m_selected);
                if (have < need) {
                    if (!ingredient->FUN_140526320()) {
                        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_lack_price"), 1);
                        return;
                    }
                    fee = (need - have) * 1000;
                }
            }
        }
        if (DAT_143ab2898 < fee) {
            FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_lack_price"), 1);
            return;
        }
        CCItemSocketSystemPacket::GemStoneUpgrade msg;
        msg.m_nGemUid = uid;
        if (record.get() != 0) {
            msg.m_nUid = owner->FUN_140526a50();
            msg.m_nSlot = record->m_slot;
        }
        COutPacket out(0x88, 0);
        out.Encode1(4);
        FUN_1406298b0(msg, out);
        FUN_140710590(out);
    }
}

// @0x140f770b0
// MS2-FUNCTIONAL: next-upgrade reset with typed temporaries.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f770b0()
{
    MS2Ptr<TGemStoneInEquip> record = FUN_140f7a380(m_selectedUid);
    int id = 0;
    __int64 uid = m_selectedUid;
    if (record.get() != 0 && !record->FUN_140f74590()) {
        if (record->m_equipment.get() != 0)
            uid = record->m_equipment->FUN_140526a50();
        if (record->m_gem.get() != 0)
            id = record->m_gem->FUN_1405276c0();
    }
    MS2Ptr<CItem> owner = FUN_141425750(uid, 0);
    if (owner.get() != 0) {
        if (FUN_14053d840(owner->FUN_140527840()))
            id = owner->FUN_1405276c0();
        if (!FUN_140626fb0(id)) {
            FUN_140f79540();
            return;
        }
    }
    m_selectedUid = 0;
    m_selected = 0;
    FUN_140f6d340(m_selectedName, m_selected);
    FUN_140f6dbe0(m_bag);
    m_root->Invoke("playStart");
}

// @0x140f77360
// MS2-FUNCTIONAL: Scaleform data with typed temporaries.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f77360(MS2Ptr<CItem> item)
{
    FUN_140f79430();
    if (!(item == 0)) {
        m_selected = item;
        FUN_140f6d340(m_selectedName, m_selected);
        ASObj data(2);
        data.FUN_1407cbb20("itemName", m_selected->FUN_140528160());
        data.FUN_1409c0e60("maxLevelNotice", L"$s_itemsocketsystem_gemstoneupgrade_msg_maxlevel");
        m_root->Invoke("playSelect", data.FUN_1422bb870());
        m_state = 1;
        m_selectedUid = m_selected->FUN_140526a50();
    }
}

// @0x140f77560
// MS2-FUNCTIONAL: typed select-result packet and Scaleform data.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f77560(CCItemSocketSystemPacket::SelectItemResult* result)
{
    bool valid = result->vfunc_0();
    __int64 uid = valid ? result->m_nUid : result->m_nGemUid;
    MS2Ptr<CItem> item = FUN_141425750(uid, 0);
    if (!valid) {
        m_selected = item;
    } else {
        MS2Ptr<TGemStoneInEquip> record = FUN_140f7a380(result->m_nGemUid);
        if (record.get() != 0 && !record->FUN_140f74590())
            m_selected = record->m_gem;
    }
    if (!(m_selected == 0)) {
        FUN_140f6d340(m_selectedName, m_selected);
        ASObj data(2);
        data.FUN_1407cbb20("itemName", m_selected->FUN_140528160());
        CStringW prob = FUN_14042cb90(CStringW(L"s_itemsocketsystem_success_prob"), result->m_fProb);
        data.FUN_1407cbb20("successProb", prob);
        FUN_140f77950(data);
        m_root->Invoke("playSelect", data.FUN_1422bb870());
        m_state = 1;
        m_selectedUid = m_selected->FUN_140526a50();
    } else {
        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
    }
}

// @0x140f77950
// MS2-FUNCTIONAL: sale, ingredient and preview data with typed temporaries.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f77950(ASObj& data)
{
    FUN_140f79430();
    if (!(m_selected == 0) && m_selected->FUN_140527840() != 0) {
        MS2Ptr<CItemGemStoneData> row = FUN_14062c280()->FUN_1405b1a60(m_selected->FUN_1405276c0());
        if (!(row == 0)) {
            MS2Ptr<SaleParam> sale(new SaleParam);
            if (sale.get() != 0) {
                unsigned bonus = 0;
                Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
                if (player != 0)
                    bonus = (unsigned)(FUN_1411e1110(FUN_1416561a0(player), 0xac) * 10000.0f);
                sale->enabled = FUN_140627a20(row->m_nMask, reinterpret_cast<unsigned*>(&sale->rate), bonus);
            }
            __int64 fee = 0;
            FUN_140f6dc70(m_ingredientsName, static_cast<Unk_GemStoneUpgradeRow*>(row.get())->m_ingredients, data,
                          m_ingredients, m_selected, &fee, sale);
            int icon = 0x405;
            int flags = 0x20;
            m_next = FUN_140f6ce00(row->m_nLinked, 0, false, m_selected);
            FUN_141415450(m_nextName, m_next, 0, icon, flags);
            data.FUN_1407cbb20("newItemName", m_next->FUN_140528160());
            data.FUN_1407cba60("newItemBinding", m_nextName);
            if (fee != 0) {
                CStringW text = FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(fee));
                data.FUN_1407cbb20("upgradeFee", text);
            }
            CStringW desc;
            if (sale.get() != 0) {
                if (sale->enabled == 1) {
                    float percent = (float)(unsigned)sale->rate * 0.01f;
                    desc = FUN_14042cb90(CStringW(L"s_itemsocketsystem_gemstoneupgrade_sale_desc"), percent);
                } else if (sale->enabled == 2) {
                    float percent = (float)(unsigned)sale->rate * 0.01f;
                    desc = FUN_14042cb90(CStringW(L"s_itemsocketsystem_gemstoneupgrade_sa_sale_desc"), percent);
                }
            }
            data.FUN_1407cbb20("saleDesc", desc);
        }
    }
}

// @0x140f78110
// MS2-FUNCTIONAL: sale refresh of the shown texts; the fee text goes to the sale text field as in the exe.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f78110(MS2Ptr<CItem> item)
{
    if (!(m_root == 0) && !(item == 0) && item->FUN_140527840() != 0) {
        MS2Ptr<CItemGemStoneData> row = FUN_14062c280()->FUN_1405b1a60(item->FUN_1405276c0());
        if (row == 0)
            return;
        MS2Ptr<SaleParam> sale(new SaleParam);
        if (sale.get() != 0) {
            unsigned bonus = 0;
            Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
            if (player != 0)
                bonus = (unsigned)(FUN_1411e1110(FUN_1416561a0(player), 0xac) * 10000.0f);
            sale->enabled = FUN_140627a20(row->m_nMask, reinterpret_cast<unsigned*>(&sale->rate), bonus);
        }
        __int64 fee = 0;
        FUN_140f6e250(m_ingredientsName, m_ingredients, item, &fee, sale);
        MS2Ptr<ASMovieClip> content = m_root->FUN_1409b4560("m_content");
        if (content.get() != 0) {
            MS2Ptr<ASTextField> desc = content->FUN_1409b4620("m_saleDesc");
            if (desc.get() != 0) {
                CStringW text;
                if (sale.get() != 0 && sale->enabled != 0) {
                    float percent = (float)(unsigned)sale->rate * 0.01f;
                    text = FUN_14042cb90(CStringW(L"s_itemsocketsystem_gemstoneupgrade_sale_desc"), percent);
                }
                desc->FUN_1422c4f00(text);
            }
            MS2Ptr<ASTextField> feeField = content->FUN_1409b4620("m_upgradeFee");
            if (feeField.get() != 0) {
                CStringW text = FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(fee));
                desc->FUN_1422c4f00(text);
            }
        }
    }
}

// @0x140f78720
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f78720(CInPacket* packet)
{
    if (!(m_root == 0)) {
        CCItemSocketSystemPacket::SelectItemResult result;
        FUN_140629d60(result, *packet);
        FUN_140f77560(&result);
    }
}

// @0x140f787a0
// MS2-FUNCTIONAL: typed upgrade-result packet, gemstone record swap and Scaleform data.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f787a0(CInPacket* packet)
{
    if (!(m_root == 0)) {
        CCItemSocketSystemPacket::GemStoneUpgradeResult result;
        FUN_140629a30(result, *packet);
        bool valid = result.vfunc_0();
        __int64 uid = valid ? result.m_nUid : result.m_nGemUid;
        __int64 resultUid = 0;
        bool restore = false;
        MS2Ptr<CItem> item = FUN_141425750(uid, &restore);
        if (item.get() != 0) {
            if (!valid) {
                m_selected = item;
                resultUid = item->FUN_140526a50();
            } else if (!item->FUN_1405279c0()->FUN_140621600(result.m_nSlot, MS2Ptr<TSocketGemStoneInfo>(result.m_spInfo))) {
                return;
            }
        }
        if (resultUid == 0)
            m_selected = FUN_140f6d050(MS2Ptr<TSocketGemStoneInfo>(result.m_spInfo), result.m_nGrade, false);
        if (!(m_selected == 0)) {
            m_selectedUid = m_selected->FUN_140526a50();
            CString method;
            ASObj data(2);
            if (!result.m_bSuccess) {
                method = "playFail";
                resultUid = 0;
            } else {
                method = "playSuccess";
                data.FUN_1407cbb20("itemName", m_selected->FUN_140528160());
                FUN_141276180(s_strUpgradeSound, CString(""));
            }
            FUN_140f6d340(m_selectedName, m_selected);
            if (valid) {
                int index = -1;
                MS2Ptr<CItem> found = FUN_140f7a190(result.m_nGemUid, &index);
                MS2Ptr<CItem> upgraded(found);
                if (found.get() != 0 && index >= 0 && result.m_bSuccess) {
                    upgraded = FUN_140f6d050(MS2Ptr<TSocketGemStoneInfo>(result.m_spInfo), result.m_nGrade, true);
                    if (upgraded.get() != 0) {
                        FUN_140f7a200(index, upgraded);
                        resultUid = upgraded->FUN_140526a50();
                        FUN_140f6d340(FUN_1422cc860(m_gemsName, index), upgraded);
                    }
                }
                if (upgraded.get() != 0)
                    m_selectedUid = upgraded->FUN_140526a50();
                if (result.m_bSuccess && restore)
                    FUN_140f6e780();
            }
            m_root->Invoke(method, data.FUN_1422bb870());
            m_state = 2;
            FUN_140f79490();
            FUN_140f79680(resultUid);
        }
    }
}

// @0x140f78f30
// MS2-FUNCTIONAL: sale refresh of the ingredient list with typed temporaries.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f78f30(CInPacket*)
{
    if (!(m_root == 0) && !(m_selected == 0)) {
        if (m_selected->FUN_140527840() != 0 && DAT_143ab2914 > 49 && m_state == 1) {
            MS2Ptr<CItemGemStoneData> row = FUN_14062c280()->FUN_1405b1a60(m_selected->FUN_1405276c0());
            if (!(row == 0)) {
                MS2Ptr<SaleParam> sale(new SaleParam);
                if (sale.get() != 0) {
                    unsigned bonus = 0;
                    Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
                    if (player != 0)
                        bonus = (unsigned)(FUN_1411e1110(FUN_1416561a0(player), 0xac) * 10000.0f);
                    sale->enabled = FUN_140627a20(row->m_nMask, reinterpret_cast<unsigned*>(&sale->rate), bonus);
                }
                __int64 fee = 0;
                FUN_140f6e250(m_ingredientsName, m_ingredients, m_selected, &fee, sale);
            }
        }
    }
}

// @0x140f79210
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f79210()
{
    FUN_14141f970(m_gemsName);
    FUN_141415600(m_selectedName);
    m_selected = 0;
    m_gems.RemoveAll();
    m_equipped.RemoveAll();
    m_selectedUid = 0;
    m_highlightUid = 0;
    m_bag = 0;
    m_debugAction = 0;
    m_debugFill = 0;
    m_debugFillUnit = 0;
    FUN_140f79430();
    FUN_1419caeb0(FUN_140a6a840(), this);
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyGameEventChanged"), Delegate<void(NotifyObject*)>(this, &ItemSocketSystemPageGemStoneUpgrade::FUN_140f7a440));
    m_state = 0;
}

// @0x140f79430
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f79430()
{
    FUN_14141f970(m_ingredientsName);
    FUN_141415600(m_nextName);
    m_ingredients.RemoveAll();
    m_next = 0;
}
MS2_REPLACE_METHOD(0x140F79430, ItemSocketSystemPageGemStoneUpgrade, FUN_140f79430, 86, 0xC033A0DB);

// @0x140f79490
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f79490()
{
    int index = -1;
    MS2Ptr<CItem> found = FUN_140f7a190(m_selectedUid, &index);
    FUN_140f6dbe0(m_bag);
    if (found == 0)
        m_selectedUid = 0;
}
MS2_REPLACE_METHOD(0x140F79490, ItemSocketSystemPageGemStoneUpgrade, FUN_140f79490, 163, 0x0802022A);

// @0x140f79540
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f79540()
{
    int index = -1;
    MS2Ptr<CItem> found = FUN_140f7a190(m_selectedUid, &index);
    if (!(found == 0)) {
        if (FUN_1422dccd0(m_bag.operator->()) != index) {
            FUN_1422dcca0(m_bag.operator->(), index);
            m_bag->vfunc_24(false);
        }
    } else {
        FUN_140f6dbe0(m_bag);
        m_selectedUid = 0;
    }
}

// @0x140f79680
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f79680(__int64 uid)
{
    if (m_highlightUid != uid) {
        if (m_highlightUid != 0) {
            int index = -1;
            MS2Ptr<CItem> found = FUN_140f7a190(m_highlightUid, &index);
            if (!(found == 0))
                FUN_140f6e500(index, false);
        }
        if (uid != 0) {
            int index = -1;
            MS2Ptr<CItem> found = FUN_140f7a190(uid, &index);
            if (!(found == 0))
                FUN_140f6e500(index, true);
        }
        m_highlightUid = uid;
    }
}

// @0x140f79760
// MS2-FUNCTIONAL: debug upgrade request through the typed packet record.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f79760(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_selected == 0) && DAT_143ab2914 > 49 && m_state == 1) {
        CCItemSocketSystemPacket::GemStoneUpgrade msg;
        msg.m_nGemUid = m_selected->FUN_140526a50();
        MS2Ptr<TGemStoneInEquip> record = FUN_140f7a380(msg.m_nGemUid);
        if (record.get() != 0 && !record->FUN_140f74590()) {
            msg.m_nUid = record->m_equipment->FUN_140526a50();
            msg.m_nSlot = record->m_slot;
        }
        COutPacket out(0x88, 0);
        out.Encode1(0xf);
        FUN_1406298b0(msg, out);
        FUN_140710590(out);
    }
}

// @0x140f798e0
// MS2-FUNCTIONAL: debug fill-ingredient request through the typed packet record.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f798e0(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_selected == 0) && DAT_143ab2914 > 49 && m_state == 1) {
        Unk_SockMsgIIL msg = {};
        msg.m_nB8 = 4;
        msg.m_nC = m_selected->FUN_1405276c0();
        COutPacket out(0x88, 0);
        out.Encode1(0x10);
        FUN_140629de0(msg, out);
        FUN_140710590(out);
    }
}

// @0x140f799d0
// MS2-FUNCTIONAL: debug fill-ingredient request through the typed packet record.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f799d0(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_selected == 0) && DAT_143ab2914 > 49 && m_state == 1) {
        Unk_SockMsgIIL msg = {};
        msg.m_nB8 = 4;
        msg.m_nC = m_selected->FUN_1405276c0();
        msg.m_n18 = 10;
        COutPacket out(0x88, 0);
        out.Encode1(0x10);
        FUN_140629de0(msg, out);
        FUN_140710590(out);
    }
}

// @0x140f79ad0
// MS2-FUNCTIONAL: slot marks of socketed gemstones with the typed item handle.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f79ad0(ItemInfoSlot& slot, ASSlot& asSlot)
{
    MS2Ptr<CItem> item = slot.vfunc_25();
    if (item.get() != 0) {
        MS2Ptr<TGemStoneInEquip> record(0);
        if (!m_equipped.IsEmpty() && m_equipped.Lookup(item->FUN_140526a50(), record)) {
            MS2Ptr<CItem> equip(record->m_equipment);
            if (equip.get() == 0 || FUN_1414258e0(equip->FUN_140526a50()))
                asSlot.FUN_1409c2110(1);
            else
                asSlot.FUN_1409c20d0(1);
        }
    }
}

// @0x140f79c50
// MS2-FUNCTIONAL: gemstone tooltip with the equipment comparison; typed tooltip handles.
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f79c50(ItemInfoSlot& slot, ASTooltip& tooltip)
{
    MS2Ptr<CItem> item = slot.vfunc_25();
    if (item.get() != 0) {
        MS2Ptr<CItem> equip(0);
        MS2Ptr<TGemStoneInEquip> record = FUN_140f7a380(item->FUN_140526a50());
        if (record.get() != 0)
            equip = record->m_equipment;
        tooltip.FUN_1409e13a0(equip.get(), item.get());
        if (equip.get() != 0) {
            MS2Ptr<AScript> sub = reinterpret_cast<Unk_SpTooltipRoot*>(&tooltip)->FUN_1409db730();
            if (sub.get() != 0) {
                ASTooltip compare(sub->FUN_1422bb870(), 2);
                if (!compare.FUN_1422ba9a0() && !FUN_1414258e0(equip->FUN_140526a50()))
                    FUN_1409d8bf0(&compare, 1);
            }
        }
    }
}

// @0x140f79e10
// MS2-FUNCTIONAL: socketed-gemstone validation with typed handles.
bool ItemSocketSystemPageGemStoneUpgrade::FUN_140f79e10(MS2Ptr<TGemStoneInEquip> record, MS2Ptr<CItem> owner, int* out)
{
    if (out != 0)
        *out = 0;
    if (!(owner == 0) && owner->FUN_1405279c0() != 0 && !(record == 0) && !record->FUN_140f74590()) {
        if (record->m_equipment.get() != 0 && record->m_equipment->FUN_140526a50() == owner->FUN_140526a50()) {
            int id = owner->FUN_1405279c0()->FUN_140620ac0(record->m_slot);
            if (record->m_gem.get() != 0 && id == record->m_gem->FUN_1405276c0()) {
                if (out != 0)
                    *out = id;
                return true;
            }
        }
        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
        return false;
    }
    return true;
}

// @0x140f7a0c0
MS2Ptr<CItem> ItemSocketSystemPageGemStoneUpgrade::FUN_140f7a0c0(int index)
{
    if (!m_gems.IsEmpty() && (size_t)index < m_gems.GetCount())
        return m_gems.GetAt(index);
    return MS2Ptr<CItem>(0);
}

// @0x140f7a190
MS2Ptr<CItem> ItemSocketSystemPageGemStoneUpgrade::FUN_140f7a190(__int64 uid, int* index)
{
    return FUN_140f6d6b0(uid, m_gems, index);
}
MS2_REPLACE_METHOD(0x140F7A190, ItemSocketSystemPageGemStoneUpgrade, FUN_140f7a190, 95, 0xF595C34E);

// @0x140f7a200
// MS2-FUNCTIONAL: gemstone replacement in the list and the socket record map.
bool ItemSocketSystemPageGemStoneUpgrade::FUN_140f7a200(int index, MS2Ptr<CItem> item)
{
    MS2Ptr<CItem> old = FUN_140f7a0c0(index);
    if (!(old == 0)) {
        m_gems.SetAt(index, item);
        MS2Ptr<TGemStoneInEquip> record = FUN_140f7a380(old->FUN_140526a50());
        if (record.get() != 0) {
            record->m_gem = item;
            m_equipped.RemoveKey(old->FUN_140526a50());
            if (item.get() != 0)
                m_equipped.SetAt(item->FUN_140526a50(), record);
        }
        return true;
    }
    return false;
}

// @0x140f7a380
MS2Ptr<TGemStoneInEquip> ItemSocketSystemPageGemStoneUpgrade::FUN_140f7a380(__int64 uid)
{
    if (!m_equipped.IsEmpty()) {
        MS2Ptr<TGemStoneInEquip> record(0);
        m_equipped.Lookup(uid, record);
        return record;
    }
    return MS2Ptr<TGemStoneInEquip>(0);
}

// @0x140f7a440
void ItemSocketSystemPageGemStoneUpgrade::FUN_140f7a440(NotifyObject* notify)
{
    if (!(m_root == 0) && m_state == 1 && !(m_selected == 0)) {
        NotifyGameEventChanged* changed = dynamic_cast<NotifyGameEventChanged*>(notify);
        if (changed != 0 && FUN_140841300(changed->m_eventName, "SaleGemStoneUpgrade"))
            FUN_140f78110(m_selected);
    }
}

// @0x140f7b1f0
ItemSocketSystemPageBase::SaleParam::SaleParam() : enabled(0), value1c(0), rate(0), value24(7) {}

// @0x140f7bd70
bool CCItemSocketSystemPacket::GemStoneInEquip::vfunc_0() { return m_nUid > 0 && m_nSlot >= 0; }
MS2_REPLACE_METHOD(0x140F7BD70, CCItemSocketSystemPacket::GemStoneInEquip, vfunc_0, 57, 0x9021F1E2);
