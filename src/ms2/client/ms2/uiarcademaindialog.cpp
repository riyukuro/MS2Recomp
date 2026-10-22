// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIArcadeMainDialog ("ArcadeMainDialog", UI type 0x4efd, 0x2e8
// bytes) is the arcade minigame lobby: nine game buttons, the selected game's ranking board (own best score + the ten best
// rows) and the enter button. The ranking comes from a worker thread (the in-game ranking service, or the web ranking
// through "api:/rank/arcade" as an XML answer). See uiarcademaindialog.h.
// MS2-UNIT: ?\uiarcademaindialog.cpp
// MS2-RANGE: 0x1400dd850-0x1400ddba0 .text$di
// MS2-RANGE: 0x140ef5640-0x140f004b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill2@@YAXXZ 0x1400dd850 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400dd880 ; probe
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400dd8b0 ; probe
// MS2-PIN: ??__Es_keyInputController2@@YAXXZ 0x1400dd900 ; probe
// MS2-PIN: ??__Es_strStun2@@YAXXZ 0x1400ddac0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400ddaf0 ; probe
// MS2-PIN: ??__Es_unk1402a9d70b@@YAXXZ 0x1400ddb20 ; probe
// MS2-PIN: ??$?0AEAHAEAV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@$0A@@?$pair@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@std@@QEAA@AEAHAEAV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@Z 0x140ef8d80 ; unique
// MS2-PIN: ??$?0PEAVUIArcadeMainDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z$0A@@?$pair@PEAVUIArcadeMainDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@QEAA@AEBQEAVUIArcadeMainDialog@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140ef8ec0 ; order
// MS2-PIN: ??$?0VUIArcadeMainDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIArcadeMainDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140ef8f00 ; unique
// MS2-PIN: ??$?0PEAVUIArcadeMainDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z$0A@@?$pair@PEAVUIArcadeMainDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@QEAA@AEBQEAVUIArcadeMainDialog@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140ef8f90 ; order
// MS2-PIN: ??$?0VUIArcadeMainDialog@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAVUIArcadeMainDialog@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140ef8fd0 ; prop
// MS2-PIN: ??$?8PEAVUIArcadeMainDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIArcadeMainDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140ef91e0 ; prop
// MS2-PIN: ??$?8PEAVUIArcadeMainDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIArcadeMainDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140ef9250 ; prop
// MS2-PIN: ??$forward@AEBQ8UIArcadeMainDialog@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8UIArcadeMainDialog@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x140efbfb0 ; order
// MS2-PIN: ??$forward@AEBQEAVUIArcadeMainDialog@@@std@@YAAEBQEAVUIArcadeMainDialog@@AEBQEAV1@@Z 0x140efbfc0 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVUIArcadeMainDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA?AU?$pair@PEAVUIArcadeMainDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@AEBQEAVUIArcadeMainDialog@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140efc060 ; order
// MS2-PIN: ??$make_pair@AEBQEAVUIArcadeMainDialog@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA?AU?$pair@PEAVUIArcadeMainDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@AEBQEAVUIArcadeMainDialog@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140efc0b0 ; order
// MS2-PIN: ??0?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@QEAA@AEBUUnk_GrNewTag@@@Z 0x140efc3c0 ; unique
// MS2-PIN: ??0?$pair@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@std@@QEAA@$$QEAU01@@Z 0x140efc6d0 ; unique
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x140efce40 ; order
// MS2-PIN: ?get@?$MS2Ptr@VASMovieClip@@@@QEBAPEAVASMovieClip@@XZ 0x140efcee0 ; order
// MS2-PIN: ??A?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@QEAAAEAUUnk_RankDataPtr@@_K@Z 0x140efd510 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140efd560 ; unique
// MS2-PIN: ?GetKeyAt@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x140efd580 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140efd5e0 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@QEAAAEAV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@PEAU__POSITION@@@Z 0x140efd630 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@Z 0x140efd690 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140efd7d0 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140efd970 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@Z 0x140efd9e0 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@IEAAPEAVCNode@12@HAEBV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@Z 0x140efdd10 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140efe070 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@Z 0x140efe180 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x140efe1f0 ; unique
// MS2-PIN: ?Successor@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140efe260 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHURankPage@UIArcadeMainDialog@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHURankPage@UIArcadeMainDialog@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x140eff100 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHURankPage@UIArcadeMainDialog@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHURankPage@UIArcadeMainDialog@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x140eff110 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIArcadeMainDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140effbc0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIArcadeMainDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140effc20 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIArcadeMainDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140efffb0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIArcadeMainDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140efffe0 ; unique
// MS2-PIN: ??$Call@VUIArcadeMainDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIArcadeMainDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIArcadeMainDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140f00020 ; unique
// MS2-PIN: ??$Call@VUIArcadeMainDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIArcadeMainDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIArcadeMainDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140f00060 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIArcadeMainDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f000a0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIArcadeMainDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f00100 ; unique
// MS2-PIN: ?push_back@?$vector@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@@std@@QEAAX$$QEAU?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@Z 0x140f00270 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??A?$vector@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@@std@@QEAAAEAU?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@_K@Z 0x140efcd80
// MS2-PIN: ??$emplace_back@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@?$vector@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@@std@@QEAAX$$QEAU?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@@Z 0x140efbdc0
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@?$vector@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@@std@@AEAAX$$QEAU?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@@Z 0x140ef99a0
// MS2-PIN: ??$_Emplace_reallocate@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@?$vector@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@@std@@QEAAPEAU?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@QEAU21@$$QEAU21@@Z 0x140ef9b20
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@@@6B@ 0x142e6d4e8
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiarcademaindialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiarcademaindialog.h"

#include <efd/SmartPointer.h>

#include <algorithm>
#include <functional>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (dynamic initializers 0x1400dd850..0x1400ddb70) ----
#ifndef MS2_HOOK_DLL
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strSortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController2;
#endif

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ArcClickDelegate;
typedef Delegate<bool(int, const CMsgBoxData&)> ArcBoxDelegate;

// The game buttons and the enter button.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422ce240(const ArcClickDelegate& onClick, void* pUserData);   // click callback
    void FUN_1422cdfb0(const CStringW& strLabel);                           // the button text
    void FUN_1422c1fe0(unsigned bEnabled);                                  // enable / disable
    void FUN_1422ce090(int bSelected);                                      // selected state
};

// The ranking view movie clip (the enter button is one of its children).
class Unk_ArcRankClip : public ASMovieClip
{
public:
    MS2Ptr<Unk_140acd6e0> FUN_140acce30(const CString& strName);            // child button by name
};

class Unk_ArcStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_ArcStrings* FUN_1401a9d70();
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
CStringW FUN_140763e10(int nScore);                                         // the score as text
CStringW FUN_14016a730(const char* sz, int n);                              // narrow to wide
CStringA FUN_140390ea0(const wchar_t* sz, int n);                           // wide to utf8
CString FUN_1402bb1c0(const char* szFormat, const int* pn);                 // format one int
CString FUN_1402bad60(const char* szFormat, const int* pn);                 // format one int
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, unsigned bOn);
void* FUN_140bb9630(int n);                                                 // the callback data of a button index
int FUN_140bd09c0(void* pUserData);                                         // the button index of a callback

CArcadeDataTable* FUN_140e37aa0();                                          // the arcade table singleton

class Unk_ArcGameRule { public: CGameEventValueArcadeOpen* FUN_1403ecfe0(); };
Unk_ArcGameRule* FUN_140302b00();

class Unk_ArcWorld { public: MyPC* FUN_141bd0cc0(); };
Unk_ArcWorld* FUN_1403ed2d0();
bool FUN_1418fe060();                                                       // the map can be changed
void FUN_141275260(int nNotice, int nA, int nB);                            // error notice
extern int DAT_143ab2870;                                                   // the current field id

MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                                // show it
void FUN_1407105c0(COutPacket& packet, int nA, int nB);                     // send with a throttle

class Unk_ArcSettings { public: bool FUN_14036d570(int nFlag); bool FUN_14036e4c0(); };
Unk_ArcSettings* FUN_140166410();
class Unk_ArcConfig { public: int FUN_1402c4c90(int nFlag); };
struct Unk_ArcConfigRoot { char m_pad_00[8]; Unk_ArcConfig m_config; };
Unk_ArcConfigRoot* FUN_14025e7b0();
unsigned FUN_140869420();                                                   // the client clock (ms)
class Unk_ArcRegionSvc { public: int FUN_140791f50(int nWhat); };
Unk_ArcRegionSvc* FUN_1404f4540();

// the xml helpers (TinyXML element: 0x90 bytes, ctor 0x14086f2f0, dtor 0x14086f450)
class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);
    ~Unk_TiXmlElement();
private:
    void* m_unknown[0x90 / sizeof(void*)];
};
void* FUN_1408782b0(Unk_TiXmlElement* pElement, const char* pszXml, void* pData, int nEncoding);   // Parse
void* FUN_140165cf0(void* pNode, const char* szName = 0);               // first child element
void* FUN_140168650(void* pNode, const char* szName = 0);               // next sibling element
int FUN_1408731e0(void* pNode, const char* szName, int* pnValue);       // int attribute
int FUN_140873420(void* pNode, const char* szName, CStringW* pstrValue);   // wide string attribute

void* FUN_140cc18a0();                                                  // the url service
void FUN_141b6de20();                                                   // worker thread start-up

// A worker thread's log scope.
class Unk_UtilLogScope
{
public:
    Unk_UtilLogScope(CString strName);                                  // 0x141b721f0
    ~Unk_UtilLogScope();                                                // 0x141b722b0
private:
    void* m_p[2];
};

// The http request object (0x210 bytes, ctor 0x1409208e0, dtor 0x140920b30).
void FUN_1409208e0(void* pRequest, const std::wstring& strUrl);
void FUN_140920b30(void* pRequest);
bool FUN_140920cf0(void* pRequest, const void* pVerb, int n);           // send
int FUN_140922f20(void* pRequest);                                      // the error (0 = ok)
void FUN_140922860(void* pRequest, std::wstring* pOut);                 // the answer text

void FUN_141b794e0(void* pService, CString* pstrOut, const char* szUrl);   // resolve "api:/..."

// @0x140ef5640
UIArcadeMainDialog::UIArcadeMainDialog()
{
    m_bannerPath = L"./Data/Resource/Image/Map/Arcade/";
    for (int i = 0; i < 9; i++)
        m_buttons[i] = 0;
    m_emptyView = 0;
    m_rankView = 0;
    m_enter = 0;
    m_results.clear();
    m_nSelected = -1;
    FUN_140ef6920();
    FUN_140ef7e70();
    m_nRequestTick = 0;
    m_pWorker = 0;
    FUN_141924170(1);
    FUN_141b794e0(FUN_140cc18a0(), &m_strUrl, "api:/rank/arcade");
}

// @0x140ef58d0
UIArcadeMainDialog::~UIArcadeMainDialog()
{
    for (int i = 0; i < 9; i++)
        m_buttons[i] = 0;
    m_emptyView = 0;
    m_rankView = 0;
    m_enter = 0;
    m_games.clear();
    if (m_pWorker != 0)
    {
        WaitForSingleObject(m_pWorker->m_hThread, 1000);
        m_pWorker = 0;
    }
}

// @0x140efe330
static CStringW Unk_ArcWide(const wchar_t* sz, int n)
{
    return CStringW(sz);
}

// @0x140ef5af0
CString UIArcadeMainDialog::GetTypeName()
{
    return "ArcadeMainDialog";
}

// @0x140ef5b40
void UIArcadeMainDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
}

// @0x140ef5b60
void UIArcadeMainDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_closeButton");
    m_rankView = FUN_140ba7930("m_rankingInfo");
    m_emptyView = FUN_140ba7930("m_rankingEmpty");
    for (int i = 0; i < 9; i++)
    {
        int nNo = i + 1;
        CString strName = FUN_1402bb1c0("m_game{0}", &nNo);
        m_buttons[i] = FUN_140bb4b10(strName);
        if (m_buttons[i].get() != 0)
            m_buttons[i]->FUN_1422ce240(ArcClickDelegate(this, &UIArcadeMainDialog::FUN_140ef6960), FUN_140bb9630(i));
    }
    m_enter = static_cast<Unk_ArcRankClip*>(m_rankView.operator->())->FUN_140acce30("m_enter");
    if (m_enter.get() != 0)
        m_enter->FUN_1422ce240(ArcClickDelegate(this, &UIArcadeMainDialog::FUN_140ef6a60), 0);
    std::vector<MS2SvrPtr<CArcadeMainData> > games;
    FUN_140e37aa0()->GetMainDataList(games);
    m_games.clear();
    m_games.reserve(games.size());
    int nButton = 0;
    for (size_t i = 0; i < games.size() && m_games.size() <= 8; i++)
    {
        MS2SvrPtr<CArcadeMainData> spGame = games[i];
        if (spGame == (CArcadeMainData*)0)
            continue;
        if (spGame->m_bIsEventArcade == 1)
        {
            if (FUN_140302b00()->FUN_1403ecfe0()->Get(spGame->m_nId) == (ArcadeOpenContext*)0)
                continue;
        }
        m_games.push_back(spGame);
        m_buttons[nButton]->FUN_1422cdfb0(FUN_1401a9d70()->FUN_141811980(0x20, spGame->m_nId));
        m_buttons[nButton]->Invoke("setImage", m_bannerPath, spGame->m_strArcadeBanner);
        FUN_140cff840((*m_buttons[nButton]).FUN_1422bb890(), "m_eventBand", spGame->m_bIsEventArcade);
        if (spGame->m_nTargetField == 0)
            m_buttons[nButton]->FUN_1422c1fe0(0);
        nButton++;
    }
    for (int i = nButton; i < 9; i++)
    {
        m_buttons[i]->FUN_1422cdfb0(GetStringCommonByKey(L"s_arcade_game_preparing"));
        m_buttons[i]->FUN_1422c1fe0(0);
        FUN_140cff840((*m_buttons[i]).FUN_1422bb890(), "m_eventBand", 0);
    }
    if (FUN_1404f4540()->FUN_140791f50(4) != m_nRegion)
    {
        COutPacket packet(static_cast<int>(SendOp::PlayArcade), 0);
        packet.Encode4(9);
        FUN_140710590(packet);
    }
    FUN_140ef7ea0();
}

// @0x140efd620
int UIArcadeMainDialog::vfunc_48()
{
    return 0x4efd;
}

// @0x140ef65f0
void UIArcadeMainDialog::vfunc_72()
{
    if (m_pWorker != 0)
    {
        if (FUN_140166410()->FUN_14036d570(0x3f) == true)
        {
            FUN_140ef67f0();
        }
        else
        {
            CStringW strResponse;
            if (Unk_LockGuard guard = m_resultLock)
            {
            }
            else
            {
                if (m_strResponse.GetLength() < 1)
                    return;
                strResponse = m_strResponse;
                m_strResponse = L"";
            }
            FUN_140ef80f0(strResponse);
            m_pWorker = 0;
            FUN_140ef6dd0();
        }
    }
}

// @0x140ef6750
void UIArcadeMainDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    for (int i = 0; i < 9; i++)
        m_buttons[i] = 0;
    m_rankView = 0;
    m_emptyView = 0;
    m_enter = 0;
}

// @0x140ef67f0
void UIArcadeMainDialog::FUN_140ef67f0()
{
    RankingResults results;
    if (Unk_LockGuard guard = m_resultLock)
    {
    }
    else
    {
        if (m_results.empty())
            return;
        results = m_results;
        m_results.clear();
    }
    FUN_140ef8380(results);
    m_pWorker = 0;
    FUN_140ef6dd0();
}

// @0x140ef6920
void UIArcadeMainDialog::FUN_140ef6920()
{
    m_nRegion = 0;
    m_scores.clear();
}

// @0x140ef6960
void UIArcadeMainDialog::FUN_140ef6960(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nIndex = FUN_140bd09c0(params.pUserData);
    if (m_buttons[nIndex] == (Unk_140acd6e0*)0)
        return;
    if (nIndex < 0 || nIndex >= 9)
        return;
    if (m_nSelected >= 0 && m_nSelected < 9)
        m_buttons[m_nSelected]->FUN_1422ce090(0);
    m_buttons[nIndex]->FUN_1422ce090(1);
    m_nSelected = nIndex;
    FUN_140ef6dd0();
}

// @0x140ef6a60
void UIArcadeMainDialog::FUN_140ef6a60(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_nSelected >= 0 && m_nSelected < (int)m_games.size())
    {
        MS2SvrPtr<CArcadeMainData> spGame = m_games[m_nSelected];
        if (spGame == (CArcadeMainData*)0)
            return;
        MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return;
        if (FUN_1418fe060() == 0)
        {
            CStringW strMsg;
            strMsg = GetStringCommonByKey(L"s_beauty_goto_map_return_warn");
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strMsg, 0, L"");
            if (spBox.get() != 0)
            {
                spBox->FUN_140533ff0(spGame->m_nId);
                spBox->FUN_141a027c0(ArcBoxDelegate(this, &UIArcadeMainDialog::FUN_140ef7ab0));
                FUN_140d73c60(spBox);
            }
        }
        else
        {
            FUN_140ef7b00(spGame->m_nId);
        }
    }
}

// @0x140ef6dd0
void UIArcadeMainDialog::FUN_140ef6dd0()
{
    if (m_nSelected >= 0 && m_nSelected < (int)m_games.size())
    {
        MS2SvrPtr<CArcadeMainData> spGame = m_games[m_nSelected];
        if (spGame == (CArcadeMainData*)0)
            return;
        if (spGame->m_nId < 1)
            return;
        if (spGame->m_nId < 6)
        {
            std::vector<Unk_ArcadeRecord> scratch;
            scratch.reserve(10);
            {
                std::vector<Unk_ArcadeRecord> records;
                FUN_140e37aa0()->GetRecords(spGame->m_nId, records);
                if (!records.empty())
                {
                    int nNpcScore = records.rbegin()->first;
                    int nId = spGame->m_nId;
                    int nTenth = m_ranks[nId].m_rows[9].first;
                    if (nTenth < nNpcScore)
                    {
                        records.reserve(records.size() + 10);
                        for (int i = 0; i < 10; i++)
                        {
                            int nId1 = spGame->m_nId;
                            int& rScore = m_ranks[nId1].m_rows[i].first;
                            int nId2 = spGame->m_nId;
                            CStringW& rName = m_ranks[nId2].m_rows[i].second;
                            if (rScore > 0)
                                records.push_back(std::make_pair(rScore, rName));
                        }
                        std::sort(records.begin(), records.end(), std::greater<Unk_ArcadeRecord>());
                        for (int j = 0; j < (int)records.size() && j < 10; j++)
                        {
                            int nId3 = spGame->m_nId;
                            m_ranks[nId3].m_rows[j].first = records[j].first;
                            int nId4 = spGame->m_nId;
                            m_ranks[nId4].m_rows[j].second = records[j].second;
                        }
                    }
                }
            }
            FUN_140ef7230();
        }
    }
}

// @0x140ef7230
void UIArcadeMainDialog::FUN_140ef7230()
{
    if (m_nSelected >= 0 && m_nSelected < (int)m_games.size())
    {
        MS2SvrPtr<CArcadeMainData> spGame = m_games[m_nSelected];
        if (spGame == (CArcadeMainData*)0)
            return;
        if (spGame->m_nId < 1)
            return;
        if (spGame->m_nId < 6)
        {
            if (m_rankView == (ASMovieClip*)0)
                return;
            m_rankView->vfunc_3(1);
            if (m_emptyView.get() != 0)
                m_emptyView->vfunc_3(0);
            FUN_140cfee80((*m_rankView).FUN_1422bb890(), "m_gameName", FUN_1401a9d70()->FUN_141811980(0x20, spGame->m_nId));
            FUN_140cfee80((*m_rankView).FUN_1422bb890(), "m_gameDesc", FUN_1401a9d70()->FUN_141811980(0x21, spGame->m_nId));
            for (int i = 0; i < 10; i++)
            {
                int nNo = i + 1;
                CString strName = FUN_1402bad60("m_rank{0}", &nNo);
                MS2Ptr<ASMovieClip> spRow = m_rankView->FUN_1409b4560(strName);
                if (spRow == (ASMovieClip*)0)
                    continue;
                int nId1 = spGame->m_nId;
                FUN_140cfee80((*spRow).FUN_1422bb890(), "m_charName", m_ranks[nId1].m_rows[i].second);
                int nId2 = spGame->m_nId;
                FUN_140cfee80((*spRow).FUN_1422bb890(), "m_score", FUN_140763e10(m_ranks[nId2].m_rows[i].first));
                MS2Ptr<ASMovieClip> spIcon = spRow->FUN_1409b4560("m_rankIcon");
                if (spIcon.get() != 0)
                    spIcon->vfunc_14(i + 1);
            }
            MS2Ptr<ASMovieClip> spMine = m_rankView->FUN_1409b4560("m_myRank");
            if (spMine.get() != 0)
            {
                int nId3 = spGame->m_nId;
                FUN_140cfee80((*spMine).FUN_1422bb890(), "m_score", FUN_140763e10(m_scores[nId3]));
            }
            m_30.operator->()->Invoke("setImage", spGame->m_strArcadeBanner, m_bannerPath);
        }
    }
}

// @0x140ef7ab0
bool UIArcadeMainDialog::FUN_140ef7ab0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
        FUN_140ef7b00(box.FUN_141a02e50(0, 0));
    return true;
}

// @0x140ef7b00
bool UIArcadeMainDialog::FUN_140ef7b00(int nArcadeId)
{
    MS2SvrPtr<CArcadeMainData> spGame = FUN_140e37aa0()->GetMainData(nArcadeId);
    if (spGame == (CArcadeMainData*)0)
        return false;
    efd::SmartPointer<MyPC> spPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (spPC == (MyPC*)0)
        return false;
    if (spPC->FUN_14166ce30() == 1)
    {
        FUN_141275260(0x279, 1, 1);
        return false;
    }
    if (spPC->vfunc_65() == 1)
    {
        FUN_141275260(0x27a, 1, 1);
        return false;
    }
    if (DAT_143ab2870 == spGame->m_nTargetField)
    {
        FUN_141275260(0x27b, 1, 1);
        return false;
    }
    COutPacket packet(static_cast<int>(SendOp::PlayArcade), 0);
    packet.Encode1(10);
    packet.Encode4(nArcadeId);
    FUN_1407105c0(packet, 10, 1000);
    return true;
}

// @0x140ef7d30
void UIArcadeMainDialog::FUN_140ef7d30(int nMode, CInPacket& packet)
{
    if (nMode == 9)
    {
        int nRegion = packet.ReadInt32();
        int nCount = packet.ReadInt32();
        if (nRegion != 0)
            m_nRegion = nRegion;
        for (int i = 0; i < nCount; i++)
        {
            int nArcade = packet.ReadInt32();
            int nScore = packet.ReadInt32();
            if (nArcade > 6)
                continue;
            m_scores[nArcade] = nScore;
        }
    }
}

// @0x140ef7e70
void UIArcadeMainDialog::FUN_140ef7e70()
{
    m_ranks.clear();
}

// @0x140ef7ea0
void UIArcadeMainDialog::FUN_140ef7ea0()
{
    if (m_nRequestTick + 600000U <= FUN_140869420() && m_strUrl.GetLength() > 0)
    {
        m_nRequestTick = FUN_140869420();
        if (FUN_14025e7b0()->m_config.FUN_1402c4c90(0x32) == 0)
        {
            if (FUN_140166410()->FUN_14036d570(0x3f) == true)
            {
                m_pWorker = AfxBeginThread(OnRequestRankingFromInGameRanking, this, 0, 0, 0, 0);
                return;
            }
        }
        if (FUN_140166410()->FUN_14036e4c0() != 0)
            m_pWorker = AfxBeginThread(OnRequestRanking, this, 0, 0, 0, 0);
    }
}

// @0x140ef7fc0
void UIArcadeMainDialog::FUN_140ef7fc0(CStringW strResponse)
{
    Unk_CriticalSectionLock lock(m_resultLock, 1);
    m_strResponse = strResponse;
}

// @0x140ef8040
void UIArcadeMainDialog::FUN_140ef8040(int nArcadeId, RankingList list)
{
    Unk_CriticalSectionLock lock(m_resultLock, 1);
    m_results.push_back(std::pair<int, RankingList>(nArcadeId, list));
}

// @0x140ef80f0
void UIArcadeMainDialog::FUN_140ef80f0(CStringW strXml)
{
    Unk_TiXmlElement root("ms2");
    CStringA strUtf8 = FUN_140390ea0(strXml, 0);
    if (FUN_1408782b0(&root, strUtf8, 0, 1) == 0)
        return;
    FUN_140ef7e70();
    for (void* pArcade = FUN_140165cf0(&root, "arcade"); pArcade != 0; pArcade = FUN_140168650(pArcade, "arcade"))
    {
        int nId = 0;
        FUN_1408731e0(pArcade, "id", &nId);
        if (nId < 6 && nId > 0)
        {
            for (void* pInfo = FUN_140165cf0(pArcade, "info"); pInfo != 0; pInfo = FUN_140168650(pInfo, "info"))
            {
                CStringW strName((const wchar_t*)0);
                int nScore = 0;
                int nRank = 0;
                FUN_140873420(pInfo, "name", &strName);
                FUN_1408731e0(pInfo, "score", &nScore);
                FUN_1408731e0(pInfo, "rank", &nRank);
                if (nRank > 0)
                {
                    m_ranks[nId].m_rows[nRank - 1].first = nScore;
                    m_ranks[nId].m_rows[nRank - 1].second = strName;
                }
            }
        }
    }
}

// @0x140ef8380
void UIArcadeMainDialog::FUN_140ef8380(RankingResults results)
{
    if (results.empty())
        return;
    FUN_140ef7e70();
    for (size_t i = 0; i < results.size(); i++)
    {
        int nId = results[i].first;
        RankingList list = results[i].second;
        if (list.operator->() != 0)
        {
            for (size_t j = 0; j < list->GetCount(); j++)
            {
                Unk_RankDataPtr rank = (*list.operator->())[j];
                if (rank.m_p != 0)
                {
                    CStringW strName = rank.FUN_140b2e1e0()->m_cname;
                    int nScore = (int)rank.FUN_140b2e1e0()->m_nPoint;
                    int nPos = rank.FUN_140b2e1e0()->m_nRank;
                    m_ranks[nId].m_rows[nPos - 1].first = nScore;
                    m_ranks[nId].m_rows[nPos - 1].second = strName;
                }
            }
        }
    }
}

// @0x140ef85b0
// MS2-FUNCTIONAL: the http request object is opaque (0x210 bytes)
unsigned UIArcadeMainDialog::OnRequestRanking(void* pArg)
{
    FUN_141b6de20();
    Unk_UtilLogScope scope(CString("UIArcadeMainDialog::OnRequestRanking"));
    UIArcadeMainDialog* pDialog = (UIArcadeMainDialog*)pArg;
    if (pDialog == 0)
        return 0;
    CStringW strUrl = FUN_14016a730(pDialog->m_strUrl, 0);
    char kRequest[0x210];
    FUN_1409208e0(kRequest, std::wstring((const wchar_t*)strUrl));
    std::wstring strVerb(L"GET");
    if (FUN_140920cf0(kRequest, &strVerb, 0))
    {
        if (FUN_140922f20(kRequest) == 0)
        {
            std::wstring strBody;
            FUN_140922860(kRequest, &strBody);
            CStringW strResponse = Unk_ArcWide(strBody.c_str(), 0);
            pDialog->FUN_140ef7fc0(strResponse);
        }
    }
    FUN_140920b30(kRequest);
    return 0;
}

// @0x140ef87e0
// MS2-FUNCTIONAL: the ranking service handles are the placeholder views of gamerankingcli.h
unsigned UIArcadeMainDialog::OnRequestRankingFromInGameRanking(void* pArg)
{
    FUN_141b6de20();
    Unk_UtilLogScope scope(CString("UIArcadeMainDialog::OnRequestRankingFromInGameRanking"));
    UIArcadeMainDialog* pDialog = (UIArcadeMainDialog*)pArg;
    if (pDialog == 0)
        return 0;
    Unk_RankKey keys[6];
    int nRegion = FUN_1404f4540()->FUN_140791f50(4);
    for (int i = 1; i < 6; i++)
        CGameRankingCli::FUN_140b2e980()->FUN_140b2b870(&keys[i], 10, i, 0, nRegion);
    for (int i = 1; i < 6; i++)
    {
        Unk_RankPageReq req = CGameRankingCli::FUN_140b2e980()->FUN_140b2add0(keys[i], 1, 1);
        if (req.FUN_140b2e0c0(0))
        {
            CGameRankingParam request;
            request.m_key.FUN_140b35820(keys[i]);
            CGameRankingCli::FUN_140b2e980()->FUN_140b2bf30(&request);
        }
    }
    int nAttempt = 0;
    ATL::CRBMap<int, RankingList> completed(10);
    while (nAttempt++ < 5)
    {
        Sleep(1000);
        for (int i = 1; i < 6; i++)
        {
            if (completed.Lookup(i) == 0)
            {
                RankingList rows(Unk_GrNewTag(0));
                CGameRankingCli::FUN_140b2e980()->FUN_140b2b440(keys[i], 1, *rows.operator->(), CStringW(L""), 0);
                if (rows->GetCount() != 0)
                    completed.SetAt(i, rows);
            }
        }
        if (completed.GetCount() == 5)
            break;
    }
    for (POSITION pos = completed.GetHeadPosition(); pos != 0; completed.GetNext(pos))
    {
        RankingList rows = completed.GetValueAt(pos);
        pDialog->FUN_140ef8040(completed.GetKeyAt(pos), rows);
    }
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca8ba0-0x142ca8d00 .text$yd
