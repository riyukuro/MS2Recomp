// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICashShopDialog: the in-game cash shop. See uicashshopdialog.h.
// MS2-UNIT: ?\uicashshopdialog.cpp
// MS2-RANGE: 0x141033200-0x141040a30 .text$mn
// MS2-RANGE: 0x1400e4960-0x1400e4b60 .text$di
// MS2-RANGE: 0x142cab7b0-0x142cab8e0 .text$yd
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0PEAVUICashShopDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z$0A@@?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@QEAA@AEBQEAVUICashShopDialog@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x14103a070 ; unique
// MS2-PIN: ??$?0PEAVUICashShopDialog@@P80@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z$0A@@?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@QEAA@AEBQEAVUICashShopDialog@@AEBQ82@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@Z 0x14103a140 ; unique
// MS2-PIN: ??$?0PEAVUICashShopDialog@@P80@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z$0A@@?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@QEAA@AEBQEAVUICashShopDialog@@AEBQ82@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@Z 0x14103a210 ; unique
// MS2-PIN: ??$?0VUICashShopDialog@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@QEAA@AEBQEAVUICashShopDialog@@AEBQ81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@Z 0x14103a250 ; unique
// MS2-PIN: ??$?0PEAVUICashShopDialog@@P80@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@3@2@Z$0A@@?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@std@@QEAA@AEBQEAVUICashShopDialog@@AEBQ82@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@5@3@Z@Z 0x14103a2e0 ; unique
// MS2-PIN: ??$?8PEAVUICashShopDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x14103a430 ; prop
// MS2-PIN: ??$?8PEAVUICashShopDialog@@P80@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@YA_NAEBU?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@0@0@Z 0x14103a4a0 ; prop
// MS2-PIN: ??$?8PEAVUICashShopDialog@@P80@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@YA_NAEBU?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@0@0@Z 0x14103a510 ; prop
// MS2-PIN: ??$?8PEAVUICashShopDialog@@P80@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@3@2@Z@std@@YA_NAEBU?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@0@0@Z 0x14103a580 ; prop
// MS2-PIN: ??0?$CRBMap@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@QEAA@_K@Z 0x14103af90 ; unique
// MS2-PIN: ??0?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@IEAA@_K@Z 0x14103aff0 ; prop
// MS2-PIN: ??0?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@IEAA@_K@Z 0x14103b050 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x14103b160 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x14103b1b0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@QEAA@AEBV01@@Z 0x14103b200 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@QEAA@AEBU?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@Z 0x14103b250 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@QEAA@AEBV01@@Z 0x14103b2a0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@QEAA@AEBU?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@Z 0x14103b2f0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VTMarketBillDataParam@@@@QEAA@H@Z 0x14103b410 ; unique
// MS2-PIN: ??0?$MS2Ptr@VTCashShopBillDataParam@@@@QEAA@PEAVTCashShopBillDataParam@@@Z 0x14103b430 ; unique
// MS2-PIN: ??0?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@QEAA@AEBV0@@Z 0x14103b460 ; prop
// MS2-PIN: ??0?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@QEAA@AEBUUnk_GrNewTag@@@Z 0x14103b4a0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCashBannerInfo@@@@QEAA@AEBV0@@Z 0x14103b520 ; prop
// MS2-PIN: ??0CAtlStringMgr@ATL@@QEAA@PEAUIAtlMemMgr@1@@Z 0x14103b660 ; unique
// MS2-PIN: ??0CNode@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@QEAA@HAEBV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@Z 0x14103b770 ; prop
// MS2-PIN: ??0CNode@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@QEAA@HAEBV?$MS2Ptr@VAScript@@@@@Z 0x14103b7c0 ; prop
// MS2-PIN: ??0CPair@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@IEAA@HAEBV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@Z 0x14103b860 ; prop
// MS2-PIN: ??0CPair@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@IEAA@HAEBV?$MS2Ptr@VAScript@@@@@Z 0x14103b8a0 ; prop
// MS2-PIN: ??1?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@QEAA@XZ 0x14103bac0 ; unique
// MS2-PIN: ??1?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@QEAA@XZ 0x14103bae0 ; prop
// MS2-PIN: ??1?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@QEAA@XZ 0x14103bb20 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x14103bb60 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@UEAA@XZ 0x14103bb80 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@UEAA@XZ 0x14103bba0 ; prop
// MS2-PIN: ??1?$MS2Ptr@VTMarketBillDataParam@@@@QEAA@XZ 0x14103bbe0 ; unique
// MS2-PIN: ??1?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@QEAA@XZ 0x14103bc10 ; prop
// MS2-PIN: ??1CNode@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@QEAA@XZ 0x14103bd50 ; unique
// MS2-PIN: ??1CNode@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@QEAA@XZ 0x14103bd30 ; unique
// MS2-PIN: ??1CPair@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@IEAA@XZ 0x14103bdc0 ; prop
// MS2-PIN: ??1CPair@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@IEAA@XZ 0x14103bda0 ; prop
// MS2-PIN: ??1CWin32Heap@ATL@@UEAA@XZ 0x14103bde0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VTCashShopBillDataParam@@@@QEBAPEAVTCashShopBillDataParam@@XZ 0x14103c0e0 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x14103c120 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@UEAAPEAXI@Z 0x14103c160 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@UEAAPEAXI@Z 0x14103c1a0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@3@2@Z@@UEAAPEAXI@Z 0x14103c1e0 ; prop
// MS2-PIN: ??_GCAtlStringMgr@ATL@@UEAAPEAXI@Z 0x14103c2a0 ; unique
// MS2-PIN: ??_GCashBannerInfo@@UEAAPEAXI@Z 0x14103c3e0 ; unique
// MS2-PIN: ??4?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@QEAAAEAV0@AEBUUnk_GrNewTag@@@Z 0x14103c4a0 ; unique
// MS2-PIN: ?FreeNode@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x14103cce0 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x14103cd80 ; prop
// MS2-PIN: ?GetHeadPosition@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x14103cf80 ; prop
// MS2-PIN: ?GetHeadPosition@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x14103cfa0 ; prop
// MS2-PIN: ?GetNext@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14103d100 ; prop
// MS2-PIN: ?GetNext@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14103d140 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCashBannerInfo@@@@V?$CStringElementTraitsI@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CDefaultCharTraits@D@2@@2@V?$CElementTraits@V?$MS2Ptr@VCashBannerInfo@@@@@2@@ATL@@AEBAPEAVCNode@12@PEBDAEAI1AEAPEAV312@@Z 0x14103d1b0 ; unique
// MS2-PIN: ?FUN_14103d2b0@ASCashShopBillData@@QEAAHXZ 0x14103d2b0 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@Z 0x14103d500 ; prop
// MS2-PIN: ?InsertImpl@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$MS2Ptr@VAScript@@@@@Z 0x14103d600 ; prop
// MS2-PIN: ?IsNil@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@AEBA_NPEAVCNode@12@@Z 0x14103d760 ; unique
// MS2-PIN: ?IsNil@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@AEBA_NPEAVCNode@12@@Z 0x14103d7a0 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14103d810 ; prop
// MS2-PIN: ?LeftRotate@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14103d920 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAPEAVCPair@12@H@Z 0x14103da30 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14103db30 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14103dba0 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14103dc10 ; prop
// MS2-PIN: ?Minimum@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14103dc80 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@Z 0x14103df00 ; prop
// MS2-PIN: ?NewNode@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$MS2Ptr@VAScript@@@@@Z 0x14103e160 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14103e4b0 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14103e580 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@IEAAPEAVCNode@12@HAEBV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@Z 0x14103e7a0 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@IEAAPEAVCNode@12@HAEBV?$MS2Ptr@VAScript@@@@@Z 0x14103ea20 ; unique
// MS2-PIN: ?RemoveAll@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@QEAAXXZ 0x14103f270 ; prop
// MS2-PIN: ?RemoveAll@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@QEAAXXZ 0x14103f2f0 ; prop
// MS2-PIN: ?RemovePostOrder@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x14103f520 ; prop
// MS2-PIN: ?RemovePostOrder@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x14103f580 ; prop
// MS2-PIN: ?RightRotate@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14103f5e0 ; prop
// MS2-PIN: ?RightRotate@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14103f6f0 ; prop
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x14103f9f0 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x14103fa10 ; prop
// MS2-PIN: ?SetNil@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x14103fa80 ; prop
// MS2-PIN: ?FUN_14103fba0@ASCashShopBillData@@QEAAXH@Z 0x14103fba0 ; unique
// MS2-PIN: ?Successor@?$CRBTree@HV?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14103fbc0 ; prop
// MS2-PIN: ?Successor@?$CRBTree@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14103fc90 ; prop
// MS2-PIN: ?Reference@?$TPtrValue@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@CAXPEAV?$TPtredDummy@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@@Z 0x14103ff20 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1410402e0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141040340 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1410403a0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@3@2@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141040400 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141040460 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@UEAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z 0x141040520 ; unique
// MS2-PIN: ??$Call@VUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x141040620 ; unique
// MS2-PIN: ??$Call@VUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@CA_NAEAU?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@V?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z 0x1410406f0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141040810 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141040870 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1410408d0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@3@2@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141040930 ; unique
// MS2-PIN: ??__FstrMgr@?1??GetInstance@CAtlStringMgr@ATL@@SAPEAUIAtlStringMgr@2@XZ@YAXXZ 0x142cab880 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VASBillData@@@@AEAAXPEAX@Z 0x141040240 ; merge-bind
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@UEAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z 0x1410404a0
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@3@2@Z@@UEAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@5@2@Z 0x141040590
// MS2-PIN: ??$Call@VUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@CA_NAEAU?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@PEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z 0x141040660
// MS2-PIN: ??$Call@VUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@3@2@Z@@CA_NAEAU?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@std@@V?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@6@3@Z 0x141040770
// MS2-PIN: ??$?0VASCashShopBillData@@@?$MS2Ptr@VASBillData@@@@QEAA@AEBV?$MS2Ptr@VASCashShopBillData@@@@@Z 0x14103a3f0
// MS2-PIN: ??$?0VTCashShopBillDataParam@@@?$MS2Ptr@VTMarketBillDataParam@@@@QEAA@AEBV?$MS2Ptr@VTCashShopBillDataParam@@@@@Z 0x14103a3b0
// MS2-PIN: ??_GCWin32Heap@ATL@@UEAAPEAXI@Z 0x14103c3a0
// MS2-PIN: ??_7?$TPtredDummy@V?$CRBMap@HV?$MS2Ptr@VAScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@3@@ATL@@@@6B@ 0x142ea2488
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@6B@ 0x142ea2410
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@6B@ 0x142ea2438
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUICashShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@4@2@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@3@2@Z@@6B@ 0x142ea2460
// (the .text$di function 0x1400e4b60 initializes ChaosLightEffect::ms_RTTI: the first static of the next unit, uichaoslightdialog.cpp)
//
// File name assumed (the class name; the exe has no assert path for it). The unit also holds the three small classes of
// the shop (CashBannerInfo, TCashShopBillDataParam, ASCashShopBillData) and the COMDAT tail: Delegate instances, the
// banner map, the page maps of the sale list and the uiswfentity.inl child lookups.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicashshopdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uicashshopdialog.h"

#include "uimarketbilldialog.h"
#include "uimessagebox.h"
#include "uimessageboxdata.h"
#include "cashunlockdialog.h"
#include "ms2/placeholder/asbilldata.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cadbannermanagercli.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (dynamic initializers 0x1400e4960..): the sort name table, skill / stun / the condition map come from
// header_statics_a.h, then the key controller and a second skill / stun pair ----

#include "ms2/placeholder/header_statics_a.h"
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";

// ---- unit-local views of exe objects ----

// A product of the shop (the record behind the manager's sale list).
class Unk_CashProduct : public CPtred
{
public:
    int m_nId;                                                      // +0x18
    int m_nSalePrice;                                               // +0x1c
    char m_pad_20[0x18];
    __int64 m_nSerial;                                              // +0x38
    char m_pad_40[8];
    int m_nItemId;                                                  // +0x48
    int m_nRank;                                                    // +0x4c
    int m_nPrice;                                                   // +0x50
    int m_n54;
    int m_nSaleTag;                                                 // +0x58
    char m_pad_5c[8];
    int m_nSlot;                                                    // +0x64
    int m_nPage;                                                    // +0x68
    int m_nDiscount;                                                // +0x6c 1: discounted
    char m_pad_70[0x20];
    int m_nLimitKind;                                               // +0x90 3: limited
    int m_nLimitMax;                                                // +0x94
    int m_nLimitCount;                                              // +0x98
};

// A row of the cash inventory (gifts waiting to be received, items to use).
class Unk_CashInvItem : public CPtred
{
public:
    int m_nId;                                                      // +0x18
    int m_nSerial;                                                  // +0x1c
    char m_pad_20[0x30];
    int m_nItemId;                                                  // +0x50
    char m_pad_54[0x24];
    int m_nUsable;                                                  // +0x78
    char m_pad_7c[0x2c];
    CStringW m_strSender;                                           // +0xa8
    CStringW m_strMessage;                                          // +0xb0
    int m_nState;                                                   // +0xb8 0: not received yet
};

// One banner record of the ad manager (the strings are wide).
class Unk_CashBannerRecord : public CPtred
{
public:
    int m_n18;
    int m_n1c;
    CStringW m_strKey;                                              // +0x20 "left" / "right"
    CStringW m_str28;
    CStringW m_strType;                                             // +0x30
    CStringW m_strValue;                                            // +0x38
    CStringW m_strImage;                                            // +0x40
};

class Unk_CashInvArr                                                // the cash inventory rows of the manager
{
public:
    size_t FUN_140b05be0();                                         // the count
    MS2Ptr<Unk_CashInvItem> FUN_140b05b10(size_t nIndex);
};

class Unk_CashMgr                                                   // the cash shop manager singleton
{
public:
    ATL::CAtlArray<MS2Ptr<Unk_CashProduct> >& FUN_14103d2c0();      // the sale products at +0x88 (inline COMDAT of this unit)
    MS2Ptr<Unk_CashProduct> FUN_140b06750(int nId);                 // a product by id
    int FUN_140b06680(MS2Ptr<Unk_CashProduct> spProduct);           // the product is hidden
    int FUN_140b06600(int nId);                                     // the pending request of a product (0: none)
    void FUN_140b06980(int nKind, int nError);                      // show the request error
    void FUN_140b06240(int nId, int nCount);                        // buy
    void FUN_140b062c0(int nId, int nCount, CString strRecipient, CString strMessage);   // gift
    void FUN_140b06580(unsigned nSerial, int nCount);               // refund
    MS2Ptr<Unk_CashInvItem> FUN_140b06870(unsigned nSerial, int nCount);   // an inventory row
    void FUN_140b063b0(unsigned nSerial, int nCount, int n);        // use
    void FUN_140b064c0(int nSerial, int nCount, int n, int m);      // pick up
    void FUN_140b061e0();                                           // request the cash balance
    void FUN_140b06180();                                           // request the basket
    void FUN_140b06450(int nCategory);                              // request a page
    Unk_CashInvArr* FUN_140b05c00();                                // the inventory rows
private:
    char m_pad_00[0x88];
    ATL::CAtlArray<MS2Ptr<Unk_CashProduct> > m_saleProducts;        // +0x88
};
Unk_CashMgr* FUN_140b05bf0();

// The list control behind "m_saleProduct" / "m_basketProduct" (the AS list with append).
class Unk_CashList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd230(const AScript& row);                         // append a row
};

class Unk_CashBag : public ASObj {};                                // "m_inven": the bag of the inventory movie
class Unk_CashButton : public ASDisplayObject                       // "m_btnNext" / "m_btnPrev"
{
public:
    void FUN_1422c1fe0(bool bEnable);
};

class Unk_CashAdMgr { public: int FUN_14096b540(int nType, ATL::CAtlArray<MS2Ptr<Unk_CashBannerRecord> >& rOut); };
Unk_CashAdMgr* FUN_1409fb930();

class Unk_CashStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_CashStrings* FUN_1401a9d70();

class Unk_CashFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_CashFeatures* FUN_140166410();

class Unk_CashFnArgs                                                // the <function> parameter list of an item
{
public:
    unsigned FUN_1408d2380();
    CStringW FUN_1408d21c0(int nIndex, CStringW strDefault);
};

class Unk_CashWorld { public: void FUN_141bd9990(const CString& strUrl); };
Unk_CashWorld* FUN_1403ed2d0();
class Unk_CashPlayer;
Unk_CashPlayer* FUN_141bd0cc0(Unk_CashWorld* pWorld);

class Unk_CashUiMgr { public: void FUN_141adc530(int uiId); };
Unk_CashUiMgr* FUN_1403ed2b0();
UIMarketBillDialog* FUN_140b09580(int uiId);                        // the open dialog of a UI id

class Unk_CashMsgBox : public CMsgBoxData { public: void FUN_141a020b0(int nItemId, int nRank, int n); };

class Unk_CashInventoryTabs { public: bool FUN_140a5cdc0(int nTab); };
extern Unk_CashInventoryTabs DAT_143ab2a90;
extern int DAT_1439f4a84;
extern int DAT_1439f4a88;
extern __int64 DAT_143ab2840;
extern CString DAT_143ab2a40;
extern char DAT_143ab2943;

unsigned char* FUN_14025e7b0();                                     // the option block (+8: the lock flags)
int FUN_1402c4c90(unsigned char* pFlags, int nBit);
void FUN_141275260(int nStringId, int a, int b);                    // a notice
int FUN_1407181d0(const CString& str);                              // text to number
int FUN_1407181a0(const CStringW& str);
int FUN_140718200(const CStringW& str);
void FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);   // pRetVal = v
void FUN_140bf2260(Scaleform::GFx::Value& v);                       // clear a value
void FUN_14134a480(AScript& root, const CString& strName, MS2Ptr<ASMovieClip>* pOut);   // bind a child of the root
void FUN_140b05680(const CString& strMovie);                        // close the shop movie of the manager
void FUN_140b055c0(const CString& strMovie, int nCategory);         // open the inventory movie
char FUN_141900a90(UICashShopDialog* pDialog);
bool FUN_1418ffe80(int nFlags, int nBit);                           // test a flag
void FUN_1418ffef0(int* pnFlags, int nBit);                         // clear a flag
void FUN_1418ffec0(int* pnFlags, int nBit);                         // set a flag
void FUN_14151f200();
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& rOut, const wchar_t* szSeparators);   // split
void FUN_1418fe1c0(const CString& strUrl);                          // open a link
CString FUN_14016a600(const wchar_t* sz, int nCodePage);
CString FUN_1401d4330(const wchar_t* sz, int nCodePage);
CString FUN_14102a0b0(int nType, const CString& strKey, const CString& strImage, CString strPath);   // the banner file
CString FUN_14016a5c0(const char* sz, int n);
CString FUN_140695240(const char* sz);
__int64 FUN_140869440();                                            // the server time
CString FUN_140c84fc0(__int64 nAddress);                            // the charge url (checked)
int FUN_1415c3b50(const char* szUrl, char* szOut, int a, int b, int nLen);
void* FUN_140aadf80();
HWND FUN_14209c720(void* pService);
void* FUN_140c7fa70(size_t nSize);                                  // operator new of CCashUnlockDialog

CString FUN_1402bb1c0(const char* szFormat, const int& n);          // StringFormat<int>
CString FUN_140513200(const char* szFormat, const __int64& n);      // StringFormat<__int64>
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& n);      // StringFormat<int> (wide)
CStringW FUN_140763e10(int nAmount);                                // the amount with separators
CStringW FUN_1409404f0(__int64 nPrice);
CStringW FUN_1418fec00(int nPayType, __int64 nAmount, int n);
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_14028de60(int nId);
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& strA, const CStringW& strB);
CStringW FUN_14052bd00(int nId, const CStringW& str);
CStringW FUN_141813300(Unk_CashStrings* pStrings, int nId);
int FUN_1402912d0(CStringW strName);                                // the inventory tab of a name
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

void FUN_140d73aa0(CStringW strText, int a, int b, CStringW strTag);            // notice
void FUN_140d73bc0(unsigned nStringId, int a, int b, CStringW strTag);          // message
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, IMessageListener* pListener, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStringId, IMessageListener* pListener, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                                  // show
void FUN_140d2cd80(MS2Ptr<Unk_CashProduct> spProduct);                          // the link of a product
void FUN_1416fb340(void* pLog, const CStringW& strText);
void* FUN_1403b4750();
void* FUN_14025e7d0();
class Unk_CashChecker { public: int FUN_140226260(const CStringW& strText, CStringW& rError); };
class Unk_CashCommon { public: Unk_CashChecker* FUN_140229a50(); };

// ---- delegates ----

// The gift callback: TMarketBillDataParam::GiftCallback (the generic four-argument Delegate of delegate.h).
typedef TMarketBillDataParam::PaymentMap Unk_CashPayMap;
typedef Delegate<bool(MS2Ptr<TMarketBillDataParam>, const Unk_CashPayMap&, const CStringW&, const CStringW&)> Unk_CashGiftDelegate;
typedef Delegate<bool(int, const CMsgBoxData&)> Unk_CashBoxDelegate;

// The sale list groups its rows by page and slot (the page map holds boxed slot maps).
typedef ATL::CRBMap<int, MS2Ptr<AScript> > Unk_CashSlotMap;
typedef ATL::CRBMap<int, TPtrValue<Unk_CashSlotMap> > Unk_CashPageMap;

// The recursive getChildByName of uiswfentity.inl.
class Unk_CashChildFinder : public ASDisplayObjectContainer
{
public:
    template <class T> MS2Ptr<T> FUN_140d01e20(const CString& strName);
    template <class T> MS2Ptr<T> FUN_14103a840(const CString& strName);
    template <class T> MS2Ptr<T> FUN_14103a9d0(const Scaleform::GFx::Value& v, const CString& strName);
};
MS2Ptr<ASDisplayObjectContainer> FUN_140bc5fc0(int nMovieId, const Scaleform::GFx::Value& v);
template <class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v);

#define UICASHSHOP_INL_ASSERT_0()                                                                                  \
    (void)((!!(0)) || (_wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\uiswfentity.inl", 23), 0))

// ---- ChaosLightEffect::ms_RTTI is initialized from the next unit (see the MS2-RANGE note above) ----

// ---- CategoryFilter ----

// @0x141033200
void UICashShopDialog::CategoryFilter::FUN_141033200()
{
    m_mapInclude.RemoveAll();
    m_mapExclude.RemoveAll();
}

// @0x141033240
void UICashShopDialog::CategoryFilter::FUN_141033240(int nCategory)
{
    m_mapInclude.SetAt(nCategory, 1);
    Unk_CashInvArr* pRows = FUN_140b05bf0()->FUN_140b05c00();
    for (size_t i = 0; i < pRows->FUN_140b05be0(); i++) {
        MS2Ptr<Unk_CashInvItem> spRow = pRows->FUN_140b05b10(i);
        m_mapExclude.SetAt(spRow->m_nSerial, 1);
    }
}

// @0x141033300
bool UICashShopDialog::CategoryFilter::FUN_141033300(int nCategory, int nId)
{
    if (m_mapInclude.Lookup(nCategory) == 0)
        return false;
    if (m_mapExclude.Lookup(nId) == 0)
        return true;
    return false;
}

// @0x14103b9a0
UICashShopDialog::CategoryFilter::CategoryFilter()
    : m_mapInclude(17, 0.75f, 0.25f, 2.25f, 10), m_mapExclude(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x14103be90
UICashShopDialog::CategoryFilter::~CategoryFilter()
{
}

// ---- UICashShopDialog ----

// @0x141033360
UICashShopDialog::UICashShopDialog()
    : m_basket(10), m_banners(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_nCash = 0;
    m_nCategory = 0;
    m_nDirty = 0;
    m_b2b8 = true;
    m_p2c0 = 0;
    m_n2c8 = 0;
    m_pUnlockDialog = 0;
    m_nUnlockState = 0;
    FUN_141924170(1);
}

// @0x1410334e0
UICashShopDialog::~UICashShopDialog()
{
    if (m_p2c0 != 0) {
        delete m_p2c0;
        m_p2c0 = 0;
    }
    if (m_pUnlockDialog != 0) {
        delete m_pUnlockDialog;
        m_pUnlockDialog = 0;
    }
}

// @0x141033660
CString UICashShopDialog::vfunc_1()
{
    return CString("CashShopDialog");
}

// @0x1410336b0
int UICashShopDialog::vfunc_73()
{
    if (FUN_1402c4c90(FUN_14025e7b0() + 8, 0x15) == 0)
        return UIDialog::vfunc_73();
    FUN_141275260(0x2f7, 1, 1);
    return 0;
}

// @0x141033710
void UICashShopDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_filter.FUN_141033200();
    m_nDirty = 0;
    FUN_140b05680(vfunc_1());
}

// @0x1410337a0
bool UICashShopDialog::vfunc_75()
{
    if (!UIDialog::vfunc_75())
        return false;
    return FUN_140166410()->FUN_14036d570(0xc2);
}

// @0x1410337e0
void UICashShopDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    int nProductId = FUN_1407181d0(pArgs->FUN_1422b8d30());
    MS2Ptr<Unk_CashProduct> spProduct = FUN_140b05bf0()->FUN_140b06750(nProductId);
    if (!spProduct)
        return;
    ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 0x20, 2);
    if (tip.FUN_1409e1770(spProduct->m_nItemId, spProduct->m_nRank) != 0)
        FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
}

// @0x141033930
int UICashShopDialog::vfunc_65()
{
    if (FUN_141900a90(this) == 0)
        return 0;
    return UIDialog::vfunc_65();
}

// @0x141033970
void UICashShopDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_nDirty = 0;
    ATL::CAtlArray<MS2Ptr<Unk_CashBannerRecord> > banners;
    if (FUN_1409fb930()->FUN_14096b540(1, banners) != 0)
        FUN_141035260(banners);
    m_nCash = 0;
    m_nCategory = 1;
    FUN_141035e40();
    FUN_141036ca0();
    FUN_140b05bf0()->FUN_140b061e0();
    FUN_140b05bf0()->FUN_140b06180();
    FUN_140b05bf0()->FUN_140b06450(m_nCategory);
}

// @0x141033a50
int UICashShopDialog::vfunc_13()
{
    return UIDialog::vfunc_13() != 0;
}

// @0x141033a80
void UICashShopDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (vfunc_55() != 0 || !m_30)
        return;
    if (FUN_1418ffe80(m_nDirty, 1)) {
        FUN_1418ffef0(&m_nDirty, 1);
        FUN_1410360c0();
    }
    if (FUN_1418ffe80(m_nDirty, 4)) {
        FUN_1418ffef0(&m_nDirty, 4);
        FUN_141036ca0();
    }
    if (FUN_1418ffe80(m_nDirty, 2)) {
        MS2Ptr<Unk_CashBag> spBag = FUN_140ba4b70(CString("m_inven"));
        if (spBag.get() != 0) {
            FUN_1418ffef0(&m_nDirty, 2);
            FUN_140b05680(vfunc_1());
            FUN_140b055c0(vfunc_1(), m_nCategory);
            spBag->FUN_1407cba60("bagId", vfunc_1());
            m_filter.FUN_141033240(m_nCategory);
            FUN_141037360();
        }
    }
}

// @0x141033d50
void UICashShopDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_spProbInfo = 0;
}

// @0x141033d90
int UICashShopDialog::vfunc_46()
{
    if (UISwfEntity::vfunc_46() == 0)
        return 0;
    if (m_30)
        return 0;
    FUN_14134a480(*m_30, CString("m_probInfo"), &m_spProbInfo);
    return 1;
}

// @0x141033e40
int UICashShopDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() != 0)
        return 0;
    if (dynamic_cast<UIMessageBox*>(pSender) == 0)
        return 0;
    FUN_14151f200();
    int nResult = pMsg->FUN_1422b8a10();
    CStringW strTag = pMsg->FUN_1422b8f40();
    if (nResult == 0) {
        ATL::CAtlArray<CStringW> parts;
        FUN_14025a680(strTag, parts, L":");
        if (parts.GetCount() != 2)
            return 0;
        if (strTag.Find(L"pickup", 0) != -1) {
            ATL::CAtlArray<CStringW> values;
            FUN_14025a680(parts[1], values, L",");
            if (values.GetCount() != 2)
                return 0;
            int nSerial = FUN_1407181a0(values[0]);
            int nCount = FUN_140718200(values[1]);
            MS2Ptr<Unk_CashInvItem> spRow = FUN_140b05bf0()->FUN_140b06870(nSerial, nCount);
            if (spRow.get() != 0)
                FUN_140b05bf0()->FUN_140b064c0(nSerial, nCount, 1, 0);
        }
        else if (strTag.Find(L"retraction", 0) != -1) {
            ATL::CAtlArray<CStringW> values;
            FUN_14025a680(parts[1], values, L",");
            if (values.GetCount() != 2)
                return 0;
            int nSerial = FUN_1407181a0(values[0]);
            int nCount = FUN_140718200(values[1]);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(1, 0xa58, 0, CStringW(L""));
            if (spBox.get() != 0) {
                spBox->FUN_140533ff0(nSerial);
                spBox->FUN_140534050(nCount);
                spBox->FUN_141a027c0(Unk_CashBoxDelegate(this, &UICashShopDialog::FUN_141039da0));
                FUN_140d73c60(spBox);
            }
        }
    }
    return 1;
}

// @0x141034350
int UICashShopDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onBuyProduct", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nProductId = FUN_1407181d0(data.FUN_1422b8d30());
            MS2Ptr<Unk_CashProduct> spProduct = FUN_140b05bf0()->FUN_140b06750(nProductId);
            if (spProduct == 0)
                return 0;
            if (m_nCash < spProduct->m_nSalePrice) {
                FUN_141039a90();
            }
            else {
                ATL::CAtlArray<int> ids;
                ids.Add(nProductId);
                FUN_141035990(CString(szMethod), ids, true);
            }
        }
    }
    else if (_stricmp("OnUseLink", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nProductId = FUN_1407181d0(data.FUN_1422b8d30());
            MS2Ptr<Unk_CashProduct> spProduct = FUN_140b05bf0()->FUN_140b06750(nProductId);
            if (!spProduct)
                return 0;
            FUN_140d2cd80(spProduct);
        }
    }
    else if (_stricmp("onChargeCash", szMethod) == 0) {
        FUN_141037880();
    }
    else if (_stricmp("onPrevPage", szMethod) == 0) {
        if (m_nCategory > 1)
            FUN_140b05bf0()->FUN_140b06450(m_nCategory - 1);
    }
    else if (_stricmp("onNextPage", szMethod) == 0) {
        FUN_140b05bf0()->FUN_140b06450(m_nCategory + 1);
    }
    else if (_stricmp("onBasket", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nProductId = FUN_140718200(data.FUN_1422b8f40());
            if (FUN_140b05bf0()->FUN_140b06600(nProductId) == 0) {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(1, 0xa5f, 0, CStringW(L""));
                if (spBox.get() != 0) {
                    spBox->FUN_140534050(nProductId);
                    spBox->FUN_141a027c0(Unk_CashBoxDelegate(this, &UICashShopDialog::FUN_141039bf0));
                    FUN_140d73c60(spBox);
                }
            }
        }
    }
    else if (_stricmp("onClickRemoveBasketItem", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nProductId = FUN_140718200(data.FUN_1422b8f40());
            POSITION pos = m_basket.Find(nProductId);
            if (pos != 0) {
                m_basket.RemoveAt(pos);
                FUN_141036ca0();
            }
        }
    }
    else if (_stricmp("onBuyBasketAll", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            CStringW strIds = data.FUN_1422b8f40();
            ATL::CAtlArray<CStringW> parts;
            FUN_14025a680(strIds, parts, L",");
            if (parts.GetCount() != 0) {
                ATL::CAtlArray<int> ids;
                size_t nParts = parts.GetCount();
                for (size_t i = 0; i < nParts; i++)
                    ids.Add(FUN_140718200(parts[i]));
                FUN_141035990(CString(szMethod), ids, false);
            }
        }
    }
    else if (_stricmp(szMethod, "onBannerL") == 0) {
        MS2Ptr<CashBannerInfo> spBanner(0);
        if (m_banners.Lookup("left", spBanner))
            FUN_1410350d0(spBanner);
    }
    else if (_stricmp(szMethod, "onBannerR") == 0) {
        MS2Ptr<CashBannerInfo> spBanner(0);
        if (m_banners.Lookup("right", spBanner))
            FUN_1410350d0(spBanner);
    }
    return 0;
}

// @0x141034da0
int UICashShopDialog::FUN_141034da0()
{
    return m_nCategory;
}

// @0x141034dc0
bool UICashShopDialog::FUN_141034dc0(int nId)
{
    return m_filter.FUN_141033300(m_nCategory, nId);
}

// @0x141034e00
void UICashShopDialog::FUN_141034e00(int nCash)
{
    m_nCash = nCash;
    MS2Ptr<ASTextField> spText = FUN_140bb4cf0(CString("m_cash"));
    if (spText.get() != 0)
        spText->FUN_1422c4cd0(FUN_140763e10(nCash));
}

// @0x141034ef0
void UICashShopDialog::FUN_141034ef0(int n, CInPacket& rPacket)
{
    unsigned nCount = rPacket.vfunc_o8_3();
    for (unsigned i = 0; i < nCount; i++) {
        int nProductId = rPacket.vfunc_o8_3();
        POSITION pos = m_basket.Find(nProductId);
        if (pos != 0) {
            m_basket.RemoveAt(pos);
            FUN_1418ffec0(&m_nDirty, 4);
        }
    }
    if (m_waiting.GetCount() != 0) {
        int nNext = m_waiting[0];
        FUN_140b05bf0()->FUN_140b06240(nNext, 1);
        m_waiting.RemoveAt(0, 1);
    }
}

// @0x141035050
void UICashShopDialog::FUN_141035050()
{
    FUN_1418ffec0(&m_nDirty, 1);
}

// @0x141035080
void UICashShopDialog::FUN_141035080(int nCategory)
{
    FUN_1418ffec0(&m_nDirty, 2);
    m_nCategory = nCategory;
    FUN_141035e40();
}

// @0x1410350d0
void UICashShopDialog::FUN_1410350d0(MS2Ptr<CashBannerInfo> spBanner)
{
    if (spBanner == 0)
        return;
    if (spBanner->m_strType == "link") {
        FUN_1418fe1c0(spBanner->m_strValue);
    }
    else if (spBanner->m_strType == "product") {
        int nProductId = FUN_1407181d0(spBanner->m_strValue);
        MS2Ptr<Unk_CashProduct> spProduct = FUN_140b05bf0()->FUN_140b06750(nProductId);
        if (spProduct == 0)
            return;
        ATL::CAtlArray<int> ids;
        ids.Add(nProductId);
        FUN_141035990(CString("OnClickBanner"), ids, true);
    }
}

// @0x141035260
void UICashShopDialog::FUN_141035260(ATL::CAtlArray<MS2Ptr<Unk_CashBannerRecord> >& rRecords)
{
    size_t nRecords = rRecords.GetCount();
    for (size_t i = 0; i < nRecords; i++) {
        MS2Ptr<Unk_CashBannerRecord> spRecord = rRecords[i];
        if (spRecord == 0)
            continue;
        MS2Ptr<CashBannerInfo> spInfo(new CashBannerInfo());
        CString strKey = FUN_14016a600(spRecord->m_strKey, 0);
        spInfo->m_strImage = FUN_14016a600(spRecord->m_strImage, 0);
        spInfo->m_strType = FUN_14016a600(spRecord->m_strType, 0);
        spInfo->m_strValue = FUN_14016a600(spRecord->m_strValue, 0);
        m_banners.SetAt(strKey, spInfo);
        CString strPath = FUN_14102a0b0(0xcb, strKey, spInfo->m_strImage, CString(""));
        if (strPath.GetLength() > 0) {
            spInfo->m_strPath = strPath;
            FUN_1410398f0(strKey);
        }
    }
}

// @0x1410355e0
void UICashShopDialog::FUN_1410355e0(CString strSide, CString strPath)
{
    MS2Ptr<CashBannerInfo> spBanner(0);
    if (m_banners.Lookup(strSide, spBanner))
        spBanner->m_strPath = strPath;
    if (FUN_1422dc430() != 0)
        FUN_1410398f0(strSide);
}

// @0x1410356a0
bool UICashShopDialog::FUN_1410356a0()
{
    return m_waiting.GetCount() != 0;
}

// @0x1410356f0
void UICashShopDialog::FUN_1410356f0()
{
    if (m_nUnlockState == 1)
        return;
    if (m_pUnlockDialog != 0) {
        delete m_pUnlockDialog;
        m_pUnlockDialog = 0;
    }
    char szUrl[1024];
    if (FUN_1415c3b50("http://maplestory2.nexon.com/Auth/CashCertify", szUrl, 0, 0, 0x10000) == 0)
        return;
    m_pUnlockDialog = new CCashUnlockDialog(0);
    if (m_pUnlockDialog->Create(0x96, CWnd::FromHandle(FUN_14209c720(FUN_140aadf80()))) != 0) {
        FUN_141035970(1);
        m_pUnlockDialog->Navigate(CString(szUrl));
        m_pUnlockDialog->CenterOnScreen();
        m_pUnlockDialog->ShowWindow(SW_SHOW);
    }
}

// @0x141035920
void UICashShopDialog::FUN_141035920(int n)
{
    m_n2c8 = n;
    if (n == 0) {
        if (FUN_140b05bf0() != 0)
            FUN_140b05bf0()->FUN_140b061e0();
    }
}

// @0x141035970
void UICashShopDialog::FUN_141035970(int nState)
{
    m_nUnlockState = nState;
}

// @0x141035990
bool UICashShopDialog::FUN_141035990(const CString& strName, ATL::CAtlArray<int>& rIds, bool bGift)
{
    MS2Ptr<TMarketBillDataParam> spParam = FUN_141037f40(strName, bGift);
    if (spParam == 0)
        return false;
    UIMarketBillDialog* pBillDialog = FUN_140b09580(0x4f17);
    if (pBillDialog == 0)
        return false;
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
    unsigned nIds = rIds.GetCount();
    for (unsigned i = 0; i < nIds; i++) {
        int nProductId = rIds[i];
        MS2Ptr<Unk_CashProduct> spProduct = FUN_140b05bf0()->FUN_140b06750(nProductId);
        if (spProduct == 0)
            continue;
        MS2Ptr<CItemData> spItem = FUN_14053f870(spProduct->m_nItemId);
        if (spItem == 0)
            continue;
        MS2Ptr<ASCashShopBillData> spBill(new ASCashShopBillData());
        spBill->FUN_1409ab990(spItem, spProduct->m_nRank);
        spBill->FUN_1409aba80(FUN_1401a9d70()->FUN_141811980(1, spProduct->m_nItemId));
        spBill->FUN_1409abad0(FUN_1418fec00(0, spProduct->m_nSalePrice, 0), spProduct->m_nSalePrice);
        spBill->FUN_1409abc90(spProduct->m_nDiscount == 1);
        spBill->FUN_1409abcd0(0);
        spBill->FUN_14103fba0(nProductId);
        bills.Add(spBill);
    }
    MS2Ptr<TMarketBillDataParam> spBase(spParam);
    pBillDialog->FUN_140ea7770(spBase);
    FUN_1403ed2b0()->FUN_141adc530(0x4f17);
    return true;
}

// @0x141035e40
void UICashShopDialog::FUN_141035e40()
{
    Unk_CashInvArr* pRows = FUN_140b05bf0()->FUN_140b05c00();
    MS2Ptr<Unk_CashButton> spNext = FUN_140bb4b10(CString("m_btnNext"));
    if (spNext.get() != 0)
        spNext->FUN_1422c1fe0(pRows->FUN_140b05be0() == 0x1e);
    MS2Ptr<Unk_CashButton> spPrev = FUN_140bb4b10(CString("m_btnPrev"));
    if (spPrev.get() != 0)
        spPrev->FUN_1422c1fe0(m_nCategory > 1);
    MS2Ptr<ASTextField> spPage = FUN_140bb4cf0(CString("m_page"));
    if (spPage.get() != 0)
        spPage->FUN_1422c4cd0(FUN_1401ceea0(L"{0}", m_nCategory));
}

// @0x1410360c0
void UICashShopDialog::FUN_1410360c0()
{
    MS2Ptr<Unk_CashList> spList = FUN_14103a890(CString("m_saleProduct"));
    if (spList == 0)
        return;
    spList->Invoke("resetRenderer");
    ASObj header(2);
    FUN_140bf2260(header.FUN_1422bb870());
    spList->FUN_1422dd230(header);
    Unk_CashPageMap pages(10);
    for (int nPage = 1; nPage < 4; nPage++)
        pages.SetAt(nPage, TPtrValue<Unk_CashSlotMap>(Unk_GrNewTag(0)));
    int nPayType = 0;
    ATL::CAtlArray<MS2Ptr<Unk_CashProduct> >& products = FUN_140b05bf0()->FUN_14103d2c0();
    for (size_t i = 0; i < products.GetCount(); i++) {
        MS2Ptr<Unk_CashProduct> spProduct = products[i];
        if (FUN_140b05bf0()->FUN_140b06680(spProduct) != 0)
            continue;
        MS2Ptr<CItemData> spItem = FUN_14053f870(spProduct->m_nItemId);
        if (spItem == 0)
            continue;
        MS2Ptr<ASObj> spRow(new ASObj(2));
        spRow->FUN_1407cba60("productSN", FUN_140513200("{0}", spProduct->m_nSerial));
        spRow->FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, spProduct->m_nItemId));
        spRow->FUN_1407cba60("iconPath", spItem->FUN_14053fdd0());
        spRow->FUN_1407cb9c0("saleTag", spProduct->m_nSaleTag);
        __int64 nPrice = spProduct->m_nPrice;
        __int64 nSalePrice = spProduct->m_nSalePrice;
        CStringW strOriginal = nSalePrice < nPrice ? FUN_1409404f0(nPrice) : CStringW(L"");
        spRow->FUN_1407cbb20("salePrice", FUN_1418fec00(nPayType, nSalePrice, 0));
        spRow->FUN_1407cbb20("originalPrice", strOriginal);
        spRow->FUN_1407cb9c0("tooltip", 1);
        if (spProduct->m_nLimitKind == 3)
            spRow->FUN_1407cbbe0("soldout", spProduct->m_nLimitMax <= spProduct->m_nLimitCount);
        int nSlot = spProduct->m_nSlot;
        int nPageOfRow = spProduct->m_nPage;
        TPtrValue<Unk_CashSlotMap> spSlots(0);
        if (!pages.Lookup(nPageOfRow, spSlots)) {
            spSlots = Unk_GrNewTag(0);
            pages.SetAt(nPageOfRow, spSlots);
        }
        spSlots->SetAt(nSlot, MS2Ptr<AScript>(spRow));
    }
    for (POSITION pos = pages.GetHeadPosition(); pos != 0; pages.GetNext(pos)) {
        TPtrValue<Unk_CashSlotMap> spSlots(pages.GetValueAt(pos));
        int nPageKey = pages.GetKeyAt(pos);
        size_t nCapacity = 6;
        if (nPageKey == 1)
            nCapacity = 5;
        MS2Ptr<ASUIComponent> spEmpty = FUN_14103a700(FUN_1402bb1c0("empty{0}", nPageKey));
        if (spEmpty != 0)
            spEmpty->vfunc_4(spSlots->GetCount() == 0);
        size_t nAdded = 0;
        for (POSITION posSlot = spSlots->GetHeadPosition(); posSlot != 0; spSlots->GetNext(posSlot)) {
            MS2Ptr<AScript> spRow = spSlots->GetValueAt(posSlot);
            spList->FUN_1422dd230(*spRow);
            nAdded++;
            if (nAdded >= nCapacity)
                break;
        }
        for (size_t j = nAdded; j < nCapacity; j++) {
            ASObj filler(2);
            FUN_140bf2260(filler.FUN_1422bb870());
            spList->FUN_1422dd230(filler);
        }
    }
    spList->vfunc_24(true);
}

// @0x141036ca0
void UICashShopDialog::FUN_141036ca0()
{
    MS2Ptr<Unk_CashList> spList = FUN_14103a890(CString("m_basketProduct"));
    spList->Invoke("resetRenderer");
    int nPayType = 0;
    for (POSITION pos = m_basket.GetHeadPosition(); pos != 0; m_basket.GetNext(pos)) {
        int nProductId = m_basket.GetAt(pos);
        MS2Ptr<Unk_CashProduct> spProduct = FUN_140b05bf0()->FUN_140b06750(nProductId);
        if (FUN_140b05bf0()->FUN_140b06680(spProduct) != 0)
            continue;
        MS2Ptr<CItemData> spItem = FUN_14053f870(spProduct->m_nItemId);
        if (spItem == 0)
            continue;
        MS2Ptr<ASObj> spRow(new ASObj(2));
        spRow->FUN_1407cba60("productSN", FUN_140513200("{0}", spProduct->m_nSerial));
        spRow->FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, spProduct->m_nItemId));
        spRow->FUN_1407cba60("iconPath", spItem->FUN_14053fdd0());
        spRow->FUN_1407cb9c0("saleTag", spProduct->m_nSaleTag);
        __int64 nPrice = spProduct->m_nPrice;
        __int64 nSalePrice = spProduct->m_nSalePrice;
        CStringW strOriginal = nSalePrice < nPrice ? FUN_1409404f0(nPrice) : CStringW(L"");
        spRow->FUN_1407cbb20("salePrice", FUN_1418fec00(nPayType, nSalePrice, 0));
        spRow->FUN_1407cbb20("price", strOriginal);
        spRow->FUN_1407cb9c0("tooltip", 1);
        spList->FUN_1422dd230(*spRow);
    }
    spList->vfunc_24(true);
}

// @0x141037360
void UICashShopDialog::FUN_141037360()
{
    Unk_CashInvArr* pRows = FUN_140b05bf0()->FUN_140b05c00();
    for (size_t i = 0; i < pRows->FUN_140b05be0(); i++) {
        MS2Ptr<Unk_CashInvItem> spRow = pRows->FUN_140b05b10(i);
        if (spRow->m_nState != 0)
            continue;
        if (spRow->m_strSender.GetLength() == 0)
            continue;
        CStringW strText = FUN_140656190(FUN_14028de60(0xa66), spRow->m_strSender, spRow->m_strMessage);
        MS2Ptr<CItem> spGift(new CItem());
        if (spGift->FUN_140523c40(spRow->m_nItemId, 1, 0) == 0)
            continue;
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, CStringW(L""), 0, strText);
        if (spBox.get() != 0) {
            spGift->FUN_140526c70(1);
            spBox->FUN_141a01ee0(spGift, spGift->FUN_140527b10(), 1, 0, -1, -1, 1);
            spBox->FUN_140533ff0(spRow->m_nSerial);
            spBox->FUN_140534050(spRow->m_nId);
            spBox->FUN_141a027c0(Unk_CashBoxDelegate(this, &UICashShopDialog::FUN_141039d30));
            FUN_140d73c60(spBox);
        }
    }
}

// @0x141037880
void UICashShopDialog::FUN_141037880()
{
    FUN_1403ed2d0()->FUN_141bd9990(FUN_140c84fc0(DAT_143ab2840));
}

// @0x1410378d0
CString UICashShopDialog::FUN_1410378d0()
{
    CString strNexonId(DAT_143ab2a40);
    ATL::CStringT<char, ATL::StrTraitATL<char, ATL::ChTraitsCRT<char> > > strSource;
    strSource.AppendFormat("%s", "MS2");
    strSource.AppendFormat("%s", (LPCSTR)strNexonId);
    CTime now(FUN_140869440());
    int nHour = now.GetHour();
    if (nHour > 12)
        nHour -= 12;
    if (nHour == 0)
        nHour = 12;
    strSource.AppendFormat("%04d%02d%02d%02d", now.GetYear(), now.GetMonth(), now.GetDay(), nHour);
    char szBuffer[1024];
    strcpy_s(szBuffer, 1024, strSource);
    CString strKey = FUN_14016a5c0(FUN_140695240(szBuffer), 0);
    CString strUrl;
    strUrl.AppendFormat("%s?", "https://nxpay.nexon.com/cash/main.aspx");
    strUrl.AppendFormat("chid=%s&", "MS2");
    strUrl.AppendFormat("nxid=%s&", (LPCSTR)strNexonId);
    strUrl.AppendFormat("ctype=%d&", 1);
    strUrl.AppendFormat("hkey=%s", (LPCSTR)strKey);
    return strUrl;
}

// @0x141037b70
CString UICashShopDialog::FUN_141037b70()
{
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\iexplore.exe", 0, KEY_QUERY_VALUE, &hKey) != ERROR_SUCCESS)
        return CString("");
    DWORD nSize = MAX_PATH;
    BYTE szPath[MAX_PATH];
    if (RegQueryValueExA(hKey, 0, 0, 0, szPath, &nSize) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return CString("");
    }
    RegCloseKey(hKey);
    CString strPath((char*)szPath);
    return strPath;
}

// @0x141037cd0
bool UICashShopDialog::FUN_141037cd0(int nItemId, int* pnReason, int* pnTab)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return true;
    if (spItem->FUN_14053e010() == 0) {
        if (spItem->FUN_14053e070() != 0 && DAT_1439f4a88 <= DAT_1439f4a84) {
            *pnReason = 0xa5c;
            return false;
        }
    }
    else {
        Unk_CashFnArgs* pArgs = reinterpret_cast<Unk_CashFnArgs*>(&spItem->function.parameter);
        if (pArgs->FUN_1408d2380() > 1)
            *pnTab = FUN_1402912d0(pArgs->FUN_1408d21c0(1, CStringW(L"")));
        if (*pnTab != -1 && DAT_143ab2a90.FUN_140a5cdc0(*pnTab) != 0) {
            *pnReason = 0xa5b;
            return false;
        }
    }
    return true;
}

// @0x141037ea0
int UICashShopDialog::FUN_141037ea0(const PaymentMap& mapPay)
{
    int nTotal = 0;
    for (POSITION pos = mapPay.GetStartPosition(); pos != 0; mapPay.GetNext(pos)) {
        __int64 nAmount = mapPay.GetValueAt(pos);
        if (nAmount != 0 && mapPay.GetKeyAt(pos) == 0)
            nTotal += (int)nAmount;
    }
    return nTotal;
}

// @0x141037f40
MS2Ptr<TMarketBillDataParam> UICashShopDialog::FUN_141037f40(const CString& strName, bool bGift)
{
    MS2Ptr<TCashShopBillDataParam> spParam(new TCashShopBillDataParam());
    if (spParam == 0)
        return MS2Ptr<TMarketBillDataParam>(0);
    spParam->m_nDialogId = vfunc_48();
    spParam->m_strMovie = strName;
    spParam->m_nCurrency = 0;
    spParam->m_b2c = bGift;
    spParam->m_dgBuy = TMarketBillDataParam::BuyCallback(this, &UICashShopDialog::FUN_1410382a0);
    spParam->m_dgTooltip = TMarketBillDataParam::TooltipCallback(this, &UICashShopDialog::FUN_141039540);
    Unk_CashGiftDelegate dgGift(this, &UICashShopDialog::FUN_141038aa0);
    spParam->m_dgGift = reinterpret_cast<TMarketBillDataParam::GiftCallback&>(dgGift);
    return MS2Ptr<TMarketBillDataParam>(spParam);
}

// @0x1410382a0
bool UICashShopDialog::FUN_1410382a0(MS2Ptr<TMarketBillDataParam> spParam, const PaymentMap& mapPay)
{
    if (!m_30)
        return false;
    if (spParam == 0)
        return false;
    MS2Ptr<TCashShopBillDataParam> spCash(dynamic_cast<TCashShopBillDataParam*>(spParam.get()));
    if (spCash == 0)
        return false;
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
    if (bills.IsEmpty())
        return false;
    int nTotal = FUN_141037ea0(mapPay);
    if (m_nCash < nTotal) {
        FUN_141039a90();
        return true;
    }
    int nFirstId = 0;
    ATL::CAtlArray<int> ids;
    size_t nBills = bills.GetCount();
    for (size_t i = 0; i < nBills; i++) {
        MS2Ptr<ASBillData> spBill = bills[i];
        if (spBill == 0)
            continue;
        MS2Ptr<ASCashShopBillData> spCashBill(dynamic_cast<ASCashShopBillData*>(spBill.get()));
        if (spCashBill == 0)
            continue;
        int nProductId = spCashBill->FUN_14103d2b0();
        MS2Ptr<Unk_CashProduct> spProduct = FUN_140b05bf0()->FUN_140b06750(nProductId);
        if (spProduct == 0)
            continue;
        int nTab = -1;
        int nReason = 0;
        if (!FUN_141037cd0(spProduct->m_nItemId, &nReason, &nTab)) {
            CStringW strText;
            if (nTab < 0)
                strText = FUN_14028de60(nReason);
            else
                strText = FUN_14052bd00(nReason, FUN_141813300(FUN_1401a9d70(), nTab));
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strText), 0, CStringW(L""));
            if (spBox.get() != 0) {
                spBox->FUN_140534050(nProductId);
                spBox->FUN_141a027c0(Unk_CashBoxDelegate(this, &UICashShopDialog::FUN_141039ca0));
                FUN_140d73c60(spBox);
            }
            return true;
        }
        int nPending = FUN_140b05bf0()->FUN_140b06600(nProductId);
        if (nPending != 0) {
            FUN_140b05bf0()->FUN_140b06980(2, nPending);
            return true;
        }
        if (nFirstId != 0)
            ids.Add(nProductId);
        else
            nFirstId = nProductId;
    }
    if (nFirstId != 0)
        FUN_140b05bf0()->FUN_140b06240(nFirstId, 1);
    if (ids.GetCount() != 0)
        m_waiting.Copy(ids);
    return true;
}

// @0x141038aa0
bool UICashShopDialog::FUN_141038aa0(MS2Ptr<TMarketBillDataParam> spParam, const PaymentMap& mapPay, const CStringW& strRecipient, const CStringW& strMessage)
{
    if (strRecipient.GetLength() == 0) {
        FUN_140d73bc0(0xa6d, 0, 0, CStringW(L""));
        return true;
    }
    if (!m_30)
        return false;
    if (spParam == 0)
        return false;
    if (FUN_140166410()->FUN_14036d570(0x111) == true && DAT_143ab2943 != 7) {
        FUN_140d73bc0(0xd56, 0, 0, CStringW(L""));
        return false;
    }
    MS2Ptr<TCashShopBillDataParam> spCash(dynamic_cast<TCashShopBillDataParam*>(spParam.get()));
    if (spCash == 0)
        return false;
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
    if (bills.IsEmpty())
        return false;
    int nTotal = FUN_141037ea0(mapPay);
    if (m_nCash < nTotal) {
        FUN_141039a90();
        return true;
    }
    ATL::CAtlArray<int> ids;
    MS2Ptr<Unk_CashProduct> spGift(0);
    size_t nBills = bills.GetCount();
    for (size_t i = 0; i < nBills; i++) {
        MS2Ptr<ASBillData> spBill = bills[i];
        if (spBill == 0)
            continue;
        MS2Ptr<ASCashShopBillData> spCashBill(dynamic_cast<ASCashShopBillData*>(spBill.get()));
        if (spCashBill == 0)
            continue;
        int nProductId = spCashBill->FUN_14103d2b0();
        MS2Ptr<Unk_CashProduct> spProduct = FUN_140b05bf0()->FUN_140b06750(nProductId);
        if (spProduct == 0)
            continue;
        int nPending = FUN_140b05bf0()->FUN_140b06600(nProductId);
        if (nPending != 0) {
            FUN_140b05bf0()->FUN_140b06980(3, nPending);
            return true;
        }
        if (spGift == 0)
            spGift = spProduct;
    }
    if (spGift == 0)
        return true;
    if (!strMessage.IsEmpty()) {
        Unk_CashChecker* pChecker = ((Unk_CashCommon*)FUN_14025e7d0())->FUN_140229a50();
        if (pChecker != 0) {
            CStringW strError;
            if (pChecker->FUN_140226260(strMessage, strError) != 0) {
                FUN_140d73aa0(strError, 0, 0, CStringW(L""));
                return true;
            }
        }
    }
    CStringW strText = FUN_14052bd00(0xa67, strRecipient);
    FUN_1416fb340(FUN_1403b4750(), strText);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, CStringW(L""), 0, strText);
    if (spBox.get() != 0) {
        spBox->FUN_140534050(spGift->m_nId);
        spBox->FUN_140b76940(strRecipient);
        spBox->FUN_140b76940(strMessage);
        spBox->FUN_141a027c0(Unk_CashBoxDelegate(this, &UICashShopDialog::FUN_141039e80));
        spBox->FUN_141a024a0(0);
        static_cast<Unk_CashMsgBox*>(spBox.operator->())->FUN_141a020b0(spGift->m_nItemId, spGift->m_nRank, 0);
        spBox->FUN_141a01700(0x477, 0x478, 0);
        FUN_140d73c60(spBox);
    }
    return true;
}

// @0x141039540
bool UICashShopDialog::FUN_141039540(Scaleform::GFx::Value* pRetVal, ASData& rData, MS2Ptr<TMarketBillDataParam> spParam)
{
    if (!m_30)
        return false;
    if (spParam == 0)
        return false;
    ASObj obj(rData.FUN_1422b9260(), 2);
    if (obj.FUN_1422ba9a0())
        return false;
    unsigned nIndex = rData.FUN_1422b8b10();
    MS2Ptr<ASBillData> spBill = spParam->FUN_140eaba00(nIndex);
    if (spBill == 0)
        return false;
    MS2Ptr<ASCashShopBillData> spCashBill(dynamic_cast<ASCashShopBillData*>(spBill.get()));
    if (spCashBill == 0)
        return false;
    MS2Ptr<Unk_CashProduct> spProduct = FUN_140b05bf0()->FUN_140b06750(spCashBill->FUN_14103d2b0());
    if (spProduct == 0)
        return false;
    ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 0x20, 2);
    if (tip.FUN_1409e1770(spProduct->m_nItemId, spProduct->m_nRank) != 0)
        FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
    return true;
}

// @0x1410398f0
void UICashShopDialog::FUN_1410398f0(const CString& strSide)
{
    if (!m_30 || strSide.IsEmpty() || m_banners.IsEmpty())
        return;
    MS2Ptr<CashBannerInfo> spBanner(0);
    CString strFunction = strSide.CompareNoCase("left") == 0 ? "setBannerL" : "setBannerR";
    if (m_banners.Lookup(strSide, spBanner))
        m_30->Invoke(strFunction, spBanner->m_strPath);
}

// @0x141039a90
void UICashShopDialog::FUN_141039a90()
{
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FUN_14028b8e0(CStringW(L"s_cashshop_lack_balance_ask")), 1);
    if (spBox.get() != 0) {
        spBox->FUN_141a027c0(Unk_CashBoxDelegate(this, &UICashShopDialog::FUN_14103a040));
        FUN_140d73c60(spBox);
    }
}

// @0x141039bf0
bool UICashShopDialog::FUN_141039bf0(int nButton, const CMsgBoxData& rData)
{
    if (nButton != 0)
        return true;
    unsigned nProductId = rData.FUN_141a02e90(0, 0);
    int nPending = FUN_140b05bf0()->FUN_140b06600(nProductId);
    if (nPending != 0) {
        FUN_140b05bf0()->FUN_140b06980(2, nPending);
        return false;
    }
    m_basket.AddTail(nProductId);
    FUN_1418ffec0(&m_nDirty, 4);
    return true;
}

// @0x141039ca0
bool UICashShopDialog::FUN_141039ca0(int nButton, const CMsgBoxData& rData)
{
    if (nButton != 0)
        return true;
    unsigned nProductId = rData.FUN_141a02e90(0, 0);
    int nPending = FUN_140b05bf0()->FUN_140b06600(nProductId);
    if (nPending != 0) {
        FUN_140b05bf0()->FUN_140b06980(2, nPending);
        return false;
    }
    FUN_140b05bf0()->FUN_140b06240(nProductId, 1);
    return true;
}

// @0x141039d30
bool UICashShopDialog::FUN_141039d30(int nButton, const CMsgBoxData& rData)
{
    if (nButton == 0) {
        int nSerial = rData.FUN_141a02e50(0, 0);
        unsigned nCount = rData.FUN_141a02e90(1, 0);
        FUN_140b05bf0()->FUN_140b06580(nSerial, nCount);
    }
    return true;
}

// @0x141039da0
bool UICashShopDialog::FUN_141039da0(int nButton, const CMsgBoxData& rData)
{
    if (nButton == 0) {
        int nSerial = rData.FUN_141a02e50(0, 0);
        unsigned nCount = rData.FUN_141a02e90(1, 0);
        MS2Ptr<Unk_CashInvItem> spRow = FUN_140b05bf0()->FUN_140b06870(nSerial, nCount);
        if (spRow.get() != 0) {
            if (spRow->m_nUsable == 0)
                return false;
            FUN_140b05bf0()->FUN_140b063b0(nSerial, nCount, 1);
        }
    }
    return true;
}

// @0x141039e80
bool UICashShopDialog::FUN_141039e80(int nButton, const CMsgBoxData& rData)
{
    if (nButton == 0) {
        unsigned nProductId = rData.FUN_141a02e90(0, 0);
        CStringW strRecipient = rData.FUN_141a02fd0(1, CStringW());
        CStringW strMessage = rData.FUN_141a02fd0(2, CStringW());
        if (FUN_140b05bf0()->FUN_140b06600(nProductId) == 0)
            FUN_140b05bf0()->FUN_140b062c0(nProductId, 1, FUN_1401d4330(strRecipient, 0), FUN_1401d4330(strMessage, 0));
    }
    return true;
}

// @0x14103a040
bool UICashShopDialog::FUN_14103a040(int nButton, const CMsgBoxData& rData)
{
    if (nButton != 1)
        FUN_141037880();
    return true;
}

// @0x14103d2c0
ATL::CAtlArray<MS2Ptr<Unk_CashProduct> >& Unk_CashMgr::FUN_14103d2c0()
{
    return m_saleProducts;
}

// @0x14103d310
int UICashShopDialog::vfunc_48()
{
    return 0x4ebc;
}

// ---- CashBannerInfo / TCashShopBillDataParam / ASCashShopBillData ----

// @0x14103b920
CashBannerInfo::CashBannerInfo()
{
}

// @0x14103be30
CashBannerInfo::~CashBannerInfo()
{
}

// @0x14103ba30
TCashShopBillDataParam::TCashShopBillDataParam()
{
    m_b2c = true;
}

// @0x14103bec0
TCashShopBillDataParam::~TCashShopBillDataParam()
{
}

// @0x14103b620
ASCashShopBillData::ASCashShopBillData()
    : ASBillData(2)
{
    m_nProductId = 0;
}

// @0x14103bcd0
ASCashShopBillData::~ASCashShopBillData()
{
}

// ---- COMDATs: the uiswfentity.inl child lookups ----

// @0x14103a700
MS2Ptr<ASUIComponent> UICashShopDialog::FUN_14103a700(const CString& strName)
{
    if (!m_30)
        return MS2Ptr<ASUIComponent>(0);
    MS2Ptr<ASDisplayObjectContainer> spContainer(dynamic_cast<ASDisplayObjectContainer*>((AScript*)m_30));
    if (spContainer == 0) {
        UICASHSHOP_INL_ASSERT_0();
        return MS2Ptr<ASUIComponent>(0);
    }
    return static_cast<Unk_CashChildFinder*>(spContainer.operator->())->FUN_140d01e20<ASUIComponent>(strName);
}

// @0x14103a840
template <class T> MS2Ptr<T> Unk_CashChildFinder::FUN_14103a840(const CString& strName)
{
    return FUN_14103a9d0<T>(m_value, strName);
}

// @0x14103a890
MS2Ptr<Unk_CashList> UICashShopDialog::FUN_14103a890(const CString& strName)
{
    if (!m_30)
        return MS2Ptr<Unk_CashList>(0);
    MS2Ptr<ASDisplayObjectContainer> spContainer(dynamic_cast<ASDisplayObjectContainer*>((AScript*)m_30));
    if (spContainer == 0) {
        UICASHSHOP_INL_ASSERT_0();
        return MS2Ptr<Unk_CashList>(0);
    }
    return static_cast<Unk_CashChildFinder*>(spContainer.operator->())->FUN_14103a840<Unk_CashList>(strName);
}

// @0x14103a9d0
template <class T> MS2Ptr<T> Unk_CashChildFinder::FUN_14103a9d0(const Scaleform::GFx::Value& v, const CString& strName)
{
    MS2Ptr<ASDisplayObjectContainer> spObj = FUN_140bc5fc0(m_nMovieId, v);
    if (!spObj->FUN_1422ba9f0("getChildByName"))
        return MS2Ptr<T>(0);
    Scaleform::GFx::Value child = spObj->FUN_1422c6b00(strName);
    if (child.IsObject())
        return Unk_ASCreate<T>(m_nMovieId, child);
    if (!spObj->FUN_1422ba9f0("numChildren"))
        return MS2Ptr<T>(0);
    int nCount = spObj->FUN_1422c6670();
    for (int i = 0; i < nCount; i++) {
        Scaleform::GFx::Value sub = spObj->FUN_1422c6aa0(i);
        if (!sub.IsObject())
            continue;
        MS2Ptr<T> spFound = FUN_14103a9d0<T>(sub, strName);
        if (spFound.get() != 0)
            return spFound;
    }
    return MS2Ptr<T>(0);
}

// instantiations
template MS2Ptr<Unk_CashList> Unk_CashChildFinder::FUN_14103a840<Unk_CashList>(const CString&);
