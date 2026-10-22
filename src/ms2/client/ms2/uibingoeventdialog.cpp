// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Bingo event dialog (the magic pencil bingo board).
// MS2-UNIT: client\ms2\uibingoeventdialog.cpp
// MS2-RANGE: 0x140bad0a0-0x140bb9770 .text$mn
// MS2-RANGE: 0x1400c9ed0-0x1400ca1bc .text$di
// MS2-RANGE: 0x142ca1730-0x142ca1865 .text$yd
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@@@6B@ 0x142dee6b0
// MS2-PIN: ??$?0VUIBingoEventDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIBingoEventDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140bb4800
// MS2-PIN: ??$?0VUIBingoEventDialog@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAVUIBingoEventDialog@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140bb48d0
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBU?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@Z 0x140bb5490
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140bb5530
// MS2-PIN: ??CUnk_BingoSlots@@QEBAPEAV?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@XZ 0x140bb6130
// MS2-PIN: ?get@Unk_BingoSlots@@QEBAPEAV?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@XZ 0x140bb60d0
// MS2-PIN: ?get@?$MS2Ptr@VASItemSlot@@@@QEBAPEAVASItemSlot@@XZ 0x140bb60e0
// MS2-PIN: ??C?$MS2Ptr@VASItemSlot@@@@QEBAPEAVASItemSlot@@XZ 0x140bb6140
// MS2-PIN: ?GetCount@?$CAtlArray@_NV?$CElementTraits@_N@ATL@@@ATL@@QEBA_KXZ 0x140bb6c50
// MS2-PIN: ?IsNull@?$MS2Ptr@VUnk_140acd6e0@@@@QEBA_NXZ 0x140bb5fa0
// MS2-PIN: ?IsNull@?$MS2Ptr@VASItemSlot@@@@QEBA_NXZ 0x140bb5fd0
// MS2-PIN: ??8?$MS2Ptr@VUnk_140acd6e0@@@@QEBA_NPEAVUnk_140acd6e0@@@Z 0x140bb6090
// MS2-PIN: ??4?$MS2Ptr@VUnk_140acd6e0@@@@QEAAAEAV0@AEBV0@@Z 0x140bb5e90
// MS2-PIN: ??0?$MS2Ptr@VASItemSlot@@@@QEAA@$$QEAV0@@Z 0x140bb55f0
// MS2-PIN: ??0?$MS2Ptr@VASItemSlot@@@@QEAA@H@Z 0x140bb5660
// MS2-PIN: ??C?$MS2Ptr@VASMovieClip@@@@QEBAPEAVASMovieClip@@XZ 0x1409b4c60
// MS2-PIN: ?GetCount@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEBA_KXZ 0x140186260
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0PEAVUIBingoEventDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z$0A@@?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@QEAA@AEBQEAVUIBingoEventDialog@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140bb47c0 ; order
// MS2-PIN: ??$?0PEAVUIBingoEventDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z$0A@@?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@QEAA@AEBQEAVUIBingoEventDialog@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140bb4890 ; order
// MS2-PIN: ??$?8PEAVUIBingoEventDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140bb4980 ; prop
// MS2-PIN: ??$?8PEAVUIBingoEventDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140bb49f0 ; prop
// MS2-PIN: ?Allocate@Unk_BingoSlots@@CAPEAV?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@@@PEAX@Z 0x140bb4d80 ; unique
// MS2-PIN: ??$forward@AEBQ8UIBingoEventDialog@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8UIBingoEventDialog@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x140bb5220 ; order
// MS2-PIN: ??$forward@AEBQEAVUIBingoEventDialog@@@std@@YAAEBQEAVUIBingoEventDialog@@AEBQEAV1@@Z 0x140bb5230 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVUIBingoEventDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA?AU?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@AEBQEAVUIBingoEventDialog@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140bb5250 ; order
// MS2-PIN: ??$make_pair@AEBQEAVUIBingoEventDialog@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA?AU?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@AEBQEAVUIBingoEventDialog@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140bb52a0 ; order
// MS2-PIN: ??0Unk_BingoSlots@@QEAA@AEBUUnk_BingoNewTag@@@Z 0x140bb5580 ; unique
// MS2-PIN: ??4Unk_BingoSlots@@QEAAAEAV0@AEBV0@@Z 0x140bb5e50 ; prop
// MS2-PIN: ??4?$MS2Ptr@VASItemSlot@@@@QEAAAEAV0@AEBV0@@Z 0x140bb5f00 ; prop
// MS2-PIN: ?IsNull@?$MS2Ptr@VASTextField@@@@QEBA_NXZ 0x140bb6030 ; order
// MS2-PIN: ?IsNull@?$MS2Ptr@VCMsgBoxData@@@@QEBA_NXZ 0x140bb6060 ; order
// MS2-PIN: ?Value@Unk_BingoSlots@@CAPEAV?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@PEAV?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@@@@Z 0x140bb60f0 ; unique
// MS2-PIN: ??_G?$MS2Ptr@VASItemSlot@@@@QEAAPEAXI@Z 0x140bb62d0 ; unique
// MS2-PIN: ??_GUIBingoEventDialog@@UEAAPEAXI@Z 0x140bb63d0 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VASItemSlot@@@@@Z 0x140bb6410 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VASMovieClip@@@@V?$CElementTraits@V?$MS2Ptr@VASMovieClip@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VASMovieClip@@@@@Z 0x140bb64c0 ; prop
// MS2-PIN: ?CallConstructors@?$CAtlArray@VUnk_BingoSlots@@V?$CElementTraits@VUnk_BingoSlots@@@ATL@@@ATL@@CAXPEAVUnk_BingoSlots@@_K@Z 0x140bb6570 ; prop
// MS2-PIN: ?CallConstructors@?$CAtlArray@V?$MS2Ptr@VUnk_140acd6e0@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_140acd6e0@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VUnk_140acd6e0@@@@_K@Z 0x140bb65f0 ; prop
// MS2-PIN: ?CallConstructors@?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VASItemSlot@@@@_K@Z 0x140bb6670 ; prop
// MS2-PIN: ?CallConstructors@?$CAtlArray@V?$MS2Ptr@VASMovieClip@@@@V?$CElementTraits@V?$MS2Ptr@VASMovieClip@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VASMovieClip@@@@_K@Z 0x140bb66f0 ; prop
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VASItemSlot@@@@_K@Z 0x140bb68a0 ; unique
// MS2-PIN: ??A?$CAtlArray@VUnk_BingoSlots@@V?$CElementTraits@VUnk_BingoSlots@@@ATL@@@ATL@@QEAAAEAVUnk_BingoSlots@@_K@Z 0x140bb6b70 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@VUnk_BingoSlots@@V?$CElementTraits@VUnk_BingoSlots@@@ATL@@@ATL@@QEBA_KXZ 0x140bb6c30 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@VUnk_BingoSlots@@V?$CElementTraits@VUnk_BingoSlots@@@ATL@@@ATL@@AEAA_N_K@Z 0x140bb6c70 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VUnk_140acd6e0@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_140acd6e0@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x140bb6e10 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x140bb6fb0 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VASMovieClip@@@@V?$CElementTraits@V?$MS2Ptr@VASMovieClip@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x140bb7150 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@_NV?$CElementTraits@_N@ATL@@@ATL@@AEAA_N_K@Z 0x140bb72f0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@VUnk_BingoSlots@@@ATL@@SAXPEAVUnk_BingoSlots@@0_K@Z 0x140bb7490 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VUnk_140acd6e0@@@@@ATL@@SAXPEAV?$MS2Ptr@VUnk_140acd6e0@@@@0_K@Z 0x140bb74d0 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VASItemSlot@@@@@ATL@@SAXPEAV?$MS2Ptr@VASItemSlot@@@@0_K@Z 0x140bb7510 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VASMovieClip@@@@@ATL@@SAXPEAV?$MS2Ptr@VASMovieClip@@@@0_K@Z 0x140bb7550 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@_N@ATL@@SAXPEA_N0_K@Z 0x140bb7590 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@VUnk_BingoSlots@@V?$CElementTraits@VUnk_BingoSlots@@@ATL@@@ATL@@QEAAXXZ 0x140bb75d0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@V?$MS2Ptr@VUnk_140acd6e0@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_140acd6e0@@@@@ATL@@@ATL@@QEAAXXZ 0x140bb75f0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@QEAAXXZ 0x140bb7610 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@_NV?$CElementTraits@_N@ATL@@@ATL@@QEAAXXZ 0x140bb7650 ; unique
// MS2-PIN: ?SetAt@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAX_KH@Z 0x140bb7670 ; unique
// MS2-PIN: ?SetAt@?$CAtlArray@_NV?$CElementTraits@_N@ATL@@@ATL@@QEAAX_K_N@Z 0x140bb77b0 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@VUnk_BingoSlots@@V?$CElementTraits@VUnk_BingoSlots@@@ATL@@@ATL@@QEAA_N_KH@Z 0x140bb7800 ; prop
// MS2-PIN: ?SetCount@?$CAtlArray@V?$MS2Ptr@VUnk_140acd6e0@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_140acd6e0@@@@@ATL@@@ATL@@QEAA_N_KH@Z 0x140bb7990 ; prop
// MS2-PIN: ?SetCount@?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@QEAA_N_KH@Z 0x140bb7b20 ; prop
// MS2-PIN: ?SetCount@?$CAtlArray@V?$MS2Ptr@VASMovieClip@@@@V?$CElementTraits@V?$MS2Ptr@VASMovieClip@@@@@ATL@@@ATL@@QEAA_N_KH@Z 0x140bb7cb0 ; prop
// MS2-PIN: ?AddRefImpl@Unk_BingoSlots@@AEBAXPEAX@Z 0x140bb82d0 ; unique
// MS2-PIN: ?Make@Unk_BingoSlots@@AEAAXXZ 0x140bb8330 ; unique
// MS2-PIN: ?Create@Unk_BingoSlots@@CAPEAV?$CAtlArray@V?$MS2Ptr@VASItemSlot@@@@V?$CElementTraits@V?$MS2Ptr@VASItemSlot@@@@@ATL@@@ATL@@PEAX@Z 0x140bb8360 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140bb8e30 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140bb8e90 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140bb9030 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140bb9060 ; unique
// MS2-PIN: ??$Call@VUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140bb90a0 ; unique
// MS2-PIN: ??$Call@VUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140bb90e0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140bb9120 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBingoEventDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140bb9180 ; unique
// MS2-PIN: ?push@?$queue@UUnk_BingoStep@@V?$deque@UUnk_BingoStep@@V?$allocator@UUnk_BingoStep@@@std@@@std@@@std@@QEAAX$$QEAUUnk_BingoStep@@@Z 0x140bb9400 ; unique
// MS2-PIN: ?push_back@?$deque@UUnk_BingoStep@@V?$allocator@UUnk_BingoStep@@@std@@@std@@QEAAX$$QEAUUnk_BingoStep@@@Z 0x140bb9430 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibingoeventdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uibingoeventdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <errno.h>
#include <string.h>

// Sort names of the item list (header static of this unit; the header_statics_a.h copy follows the sounds).
static CString s_bingoSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sndLineComplete = "System_Bingo_LineComplete_01";
static CString s_sndRegPopUp = "System_Bingo_RegPopUp_01";
static CString s_sndSpecialPopUp = "System_Bingo_SpecialPopUp_01";
static CString s_sndSuccess = "System_Bingo_Success_01";
#include "ms2/placeholder/header_statics_a.h"

// ---- local stand-ins for classes whose units are not recovered yet ----
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, void*);
    void FUN_1422c2a70(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, void*);
    void FUN_1422c1fe0(unsigned);
};
class Unk_BingoText : public ASTextField
{
public:
    void FUN_1422c4c80(const CString&);
};
class Unk_BingoSlot : public ASItemSlot
{
public:
    void FUN_1409ba5d0(int, int, int);
    void FUN_1409ba6d0();
};
class Unk_BingoClip : public ASMovieClip
{
public:
    MS2Ptr<Unk_140acd6e0> FUN_140acce30(const CString&);
    MS2Ptr<ASItemSlot> FUN_140bb4ba0(const CString&);
    CString FUN_1422c2420();
    void FUN_1422c1fe0(unsigned);
    int FUN_1422c2030();
    void FUN_1422c6640(int);
    void FUN_1422deb40(int);
    void FUN_1422c2af0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&);
    void FUN_1422c2a70(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, void*);
};
class UIMessageBox { public: void FUN_1419f8120(); };
UIMessageBox* FUN_14151f890();
MS2Ptr<CMsgBoxData> FUN_140d73d20(int, CStringW, IMessageListener*, CStringW);
void FUN_14151f150(MS2Ptr<CMsgBoxData>);
bool FUN_140184310(const CString&, const char*);
class ASDialog : public ASDisplayObject {};
int FUN_1402bacf0(ATL::CAtlArray<int>&, const int&);
class Unk_BingoMsgBox : public CMsgBoxData { public: void FUN_141a01c30(const CString&); };
#define BINGO_MSGBOX(p) static_cast<Unk_BingoMsgBox*>((p).operator->())
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW, int);
CStringW FUN_1401ceea0(const wchar_t*, const int&);
CStringW FUN_140275590(const wchar_t*, const CStringW&, const int&);
CStringW FUN_1401e8510(const wchar_t*, const CStringW&);
void FUN_1412751f0(const CStringW&, int, int);
void FUN_1401cdae0(ATL::CAtlArray<int>&, unsigned);
size_t FUN_140412ed0(void* table);
// The 12 byte item key of the inventory count query (item id, rank, unused).
struct Unk_BingoItemKey
{
    // @0x140bb5a30
    Unk_BingoItemKey() : m_id(0), m_rank(0), m_extra(0) {}
    int m_id;
    int m_rank;
    int m_extra;
};
extern Unk_Inventory DAT_143ab2a90;
class Unk_BingoLocalizer { public: CStringW FUN_1422b0570(const CString& key); };
Unk_BingoLocalizer* FUN_14025e7a0();
class Unk_BingoStrings { public: CStringW FUN_141811980(int, int); };
Unk_BingoStrings* FUN_1401a9d70();
class Unk_BingoTextFilter { public: void FUN_1416fb300(CStringW&); };
Unk_BingoTextFilter* FUN_1403b4750();

// Client globals: the account's bingo event record (singleton 0x140302b00 -> member +0xd78).
class Unk_BingoEventData
{
public:
    char m_pad_00[0x40];
    int m_freeItemId;                           // +0x40
    int m_cashItemId;                           // +0x44
    char m_rewards[1];                          // +0x48
};
class Unk_BingoRewardItems
{
public:
    unsigned long long FUN_140412e50() const;
    ItemAble& FUN_140412d50(unsigned long long);
};
class Unk_BingoRewardEntry { public: char m_pad[1]; };
Unk_BingoRewardEntry& FUN_140412e10(void* table, unsigned idx);
Unk_BingoRewardItems& FUN_1404111b0(Unk_BingoRewardEntry&);
void FUN_140159b70(long hr);
struct Unk_BingoRewardTable
{
    // @0x140bb6b30
    Unk_BingoRewardEntry& FUN_140bb6b30(unsigned long long idx)
    {
        if (!(idx < m_count))
            FUN_140159b70(0x80070057);
        return *(Unk_BingoRewardEntry*)(m_data + idx * 0x10);
    }
    char* m_data;
    unsigned long long m_count;
};
class Unk_BingoRef;
// The bingo event record handle (16 bytes; the destructor releases it).
class Unk_BingoRef
{
public:
    Unk_BingoRef() {}
    ~Unk_BingoRef();
    bool FUN_1403e8340();
    Unk_BingoEventData* FUN_1403e8b90();
    __int64 m_00, m_08;
};
MS2_CHECK_SIZE(Unk_BingoRef, 0x10);
class Unk_BingoHolder { public: Unk_BingoRef FUN_140429c80(); };
class Unk_BingoMgr { public: void* m_pad; };
Unk_BingoMgr* FUN_140302b00();
Unk_BingoHolder* FUN_1403ed060(Unk_BingoMgr*);
int FUN_14053feb0(int);
unsigned FUN_140406550(Unk_BingoEventData*, unsigned long long, ATL::CAtlArray<int>*);
CString FUN_1402bb1c0(const char*, const int&);
CString FUN_14052ea30(const char*, const unsigned&);
CString FUN_1401d9af0(const char*, const unsigned long long&);
CStringW FUN_1402a61e0(const wchar_t*);
CStringW FUN_140292a70(const wchar_t*, const unsigned&);
CStringW FUN_140656190(const wchar_t*, const CStringW&, const CStringW&);

void FUN_1401d9a30(const CStringW&, ATL::CAtlArray<int>&, const wchar_t*);
__int64 FUN_140869440();
unsigned FUN_140869420();
bool FUN_14086ab70(CMsTime, CMsTime, int);
void FUN_141276180(const CString&, const CString&);

// ---- the scalar / index codecs of the delegate user data (the exe keeps the index in the data pointer) ----
// @0x140bb9630
inline void* FUN_140bb9630(int n) { return (void*)(__int64)n; }
// @0x140bb9640
inline int FUN_140bb9640(void* n) { return (int)(__int64)n; }

// ---- GetChild specializations (one COMDAT per wrapper class) ----
// @0x140bb4b10
template <> MS2Ptr<Unk_140acd6e0> UISwfEntity::GetChild<Unk_140acd6e0>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<Unk_140acd6e0>(0);
    return static_cast<Unk_BingoClip*>(m_30.operator->())->FUN_140acce30(strName);
}

// @0x140bb4a60
MS2Ptr<ASItemSlot> FUN_140bb4a60(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASItemSlot> sp(new ASItemSlot(v, nMovieId));
    return sp;
}

// @0x140bb4ba0
MS2Ptr<ASItemSlot> Unk_BingoClip::FUN_140bb4ba0(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return FUN_140bb4a60(m_nMovieId, v);
    return MS2Ptr<ASItemSlot>(0);
}

// @0x140bb4c60
template <> MS2Ptr<ASItemSlot> UISwfEntity::GetChild<ASItemSlot>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<ASItemSlot>(0);
    return static_cast<Unk_BingoClip*>(m_30.operator->())->FUN_140bb4ba0(strName);
}

// @0x140bb4cf0
template <> MS2Ptr<ASTextField> UISwfEntity::GetChild<ASTextField>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<ASTextField>(0);
    return m_30->FUN_1409b4620(strName);
}

template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);

#define BINGO_CLIP(p) static_cast<Unk_BingoClip*>((p).operator->())
#define BINGO_TEXT(p) static_cast<Unk_BingoText*>((p).operator->())
#define BINGO_SLOT(p) static_cast<Unk_BingoSlot*>((p).operator->())

// @0x140bad0a0
UIBingoEventDialog::UIBingoEventDialog()
    : m_state(0), m_stage(0), m_time((__time64_t)0), m_msgOpen(false), m_tick(0)
{
}

// @0x140bad290
UIBingoEventDialog::~UIBingoEventDialog()
{
}

// @0x140bad410
CString UIBingoEventDialog::GetTypeName()
{
    return CString("BingoEventDialog");
}

// @0x140bad460
int UIBingoEventDialog::vfunc_65()
{
    COutPacket pkt(0x97, 0);
    pkt.vfunc_o10_1(0x14);
    FUN_140710590(pkt);
    m_state = 0;
    m_time = CMsTime(FUN_140869440());
    m_msgOpen = false;
    m_tick = FUN_140869420();
    return UIDialog::vfunc_65();
}


typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> BingoParamsDelegate;

// @0x140bad530
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    MS2Ptr<ASMovieClip> board = GetChild<ASMovieClip>(CString("m_board"));
    if (board.IsNull())
        return;
    m_board5 = BINGO_CLIP(board)->FUN_1409b4560(CString("m_board5"));
    MS2Ptr<ASMovieClip> board4 = BINGO_CLIP(board)->FUN_1409b4560(CString("m_board4"));
    if (m_board5.IsNull() || board4.IsNull())
        return;
    board4->vfunc_4(false);
    m_cells.RemoveAll();
    m_cells.SetCount(25, -1);
    m_lines.RemoveAll();
    for (int i = 0; i < 25; i++)
    {
        MS2Ptr<ASMovieClip> cell = m_board5->FUN_1409b4560(FUN_1402bb1c0("m_cell{0}", i));
        if (cell.IsNull())
            return;
        MS2Ptr<ASMovieClip> check = m_board5->FUN_1409b4560(FUN_1402bb1c0("m_check{0}", i));
        if (check.IsNull())
            return;
        check->vfunc_4(false);
        m_cells.SetAt(i, cell);
        MS2Ptr<ASMovieClip> blind = cell->FUN_1409b4560(CString("m_blind"));
        if (blind.IsNull())
            return;
        blind->vfunc_4(false);
    }
    for (int i = 0; i < 12; i++)
    {
        MS2Ptr<ASMovieClip> line = m_board5->FUN_1409b4560(FUN_1402bb1c0("m_line{0}", i));
        if (line.IsNull())
            return;
        line->vfunc_4(false);
        m_lines.Add(line);
    }
    MS2Ptr<ASMovieClip> firework = GetChild<ASMovieClip>(CString("m_fireworkEffect"));
    if (firework.get() != 0)
        firework->vfunc_4(false);
    m_receive.RemoveAll();
    m_receive.SetCount(8, -1);
    m_rewardLists.RemoveAll();
    m_rewardLists.SetCount(8, -1);
    m_rewardSlots.RemoveAll();
    m_rewardSlots.SetCount(8, -1);
    Unk_BingoRef ref = FUN_1403ed060(FUN_140302b00())->FUN_140429c80();
    if (ref.FUN_1403e8340())
        return;
    void* rewards = (char*)ref.FUN_1403e8b90() + 0x48;
    for (unsigned i = 0; i < 8; i++)
    {
        MS2Ptr<ASMovieClip> list = GetChild<ASMovieClip>(FUN_14052ea30("m_rewardsList{0}", i));
        if (list.IsNull())
            continue;
        m_rewardLists.SetAt(i, list);
        MS2Ptr<ASTextField> text = BINGO_CLIP(list)->FUN_1409b4620(CString("m_textField"));
        if (text.IsNull() == false)
            continue;
        if (i == 7)
            text->FUN_1422c4cd0(FUN_1402a61e0(FUN_14025e7a0()->FUN_1422b0570(CString("$s_bingo_event_dialog_reward_condition_last"))));
        else
        {
            unsigned n = i + 1;
            text->FUN_1422c4cd0(FUN_140292a70(FUN_14025e7a0()->FUN_1422b0570(CString("$s_bingo_event_dialog_reward_condition")), n));
        }
        MS2Ptr<Unk_140acd6e0> receive = BINGO_CLIP(list)->FUN_140acce30(CString("m_receiveButton"));
        if (receive.get() == 0)
            continue;
        receive->FUN_1422ce240(BingoParamsDelegate(this, &UIBingoEventDialog::SendEventRewardMode23), FUN_140bb9630(i));
        m_receive.SetAt(i, receive);
        Unk_BingoSlots slots(Unk_BingoNewTag(0));
        for (unsigned long long j = 0; j < 2; j++)
        {
            MS2Ptr<ASMovieClip> group = BINGO_CLIP(list)->FUN_1409b4560(FUN_1401d9af0("m_slots{0}", j));
            if (group.IsNull())
                continue;
            Unk_BingoRewardItems& items = FUN_1404111b0(FUN_140412e10(rewards, i));
            if (j + 1 == items.FUN_140412e50())
            {
                for (unsigned long long k = 0; k <= j; k++)
                {
                    MS2Ptr<ASItemSlot> slot = BINGO_CLIP(group)->FUN_140bb4ba0(FUN_1401d9af0("m_slot{0}", k));
                    if (slot.IsNull())
                        break;
                    slots->Add(slot);
                    ItemEntity item(FUN_1404111b0(FUN_140412e10(rewards, i)).FUN_140412d50(k));
                    BINGO_SLOT(slot)->FUN_1409ba5d0(item.m_itemId, item.vfunc_o18_1(), item.m_count);
                    BINGO_SLOT(slot)->FUN_1409ba6d0();
                }
            }
            else
                group->vfunc_4(false);
        }
        m_rewardSlots.SetAt(i, slots);
    }
    m_free.m_use = GetChild<Unk_140acd6e0>(CString("m_useFreeItem"));
    if (m_free.m_use.IsNull())
        return;
    m_free.m_use->FUN_1422c2a70(BingoParamsDelegate(this, &UIBingoEventDialog::FUN_140bb0ea0), FUN_140bb9630(0));
    m_cash.m_use = GetChild<Unk_140acd6e0>(CString("m_useCashItem"));
    if (m_cash.m_use.IsNull())
        return;
    m_cash.m_use->FUN_1422c2a70(BingoParamsDelegate(this, &UIBingoEventDialog::FUN_140bb0ea0), FUN_140bb9630(1));
    m_free.m_cancel = GetChild<Unk_140acd6e0>(CString("m_cancelFreeItem"));
    if (m_free.m_cancel == 0)
        return;
    m_free.m_cancel->FUN_1422c2a70(BingoParamsDelegate(this, &UIBingoEventDialog::FUN_140bb13e0), FUN_140bb9630(0));
    m_cash.m_cancel = GetChild<Unk_140acd6e0>(CString("m_cancelCashItem"));
    if (m_cash.m_cancel == 0)
        return;
    m_cash.m_cancel->FUN_1422c2a70(BingoParamsDelegate(this, &UIBingoEventDialog::FUN_140bb13e0), FUN_140bb9630(1));
    m_free.m_text = GetChild<ASTextField>(CString("m_freeItemText"));
    m_cash.m_text = GetChild<ASTextField>(CString("m_cashItemText"));
    m_free.m_icon = GetChild<ASMovieClip>(CString("m_freeItemIcon"));
    m_cash.m_icon = GetChild<ASMovieClip>(CString("m_cashItemIcon"));
    m_free.m_effect = GetChild<ASMovieClip>(CString("m_freeItemEffect"));
    m_cash.m_effect = GetChild<ASMovieClip>(CString("m_cashItemEffect"));
    m_free.m_slot = GetChild<ASItemSlot>(CString("m_freeItemSlot"));
    if (m_free.m_slot.get() != 0)
    {
        int id = ref.FUN_1403e8b90()->m_freeItemId;
        int rank = FUN_14053feb0(id);
        BINGO_SLOT(m_free.m_slot)->FUN_1409ba5d0(id, rank, 1);
        BINGO_SLOT(m_free.m_slot)->FUN_1409ba6d0();
    }
    m_cash.m_slot = GetChild<ASItemSlot>(CString("m_cashItemSlot"));
    if (m_cash.m_slot.get() != 0)
    {
        int id = ref.FUN_1403e8b90()->m_cashItemId;
        int rank = FUN_14053feb0(id);
        BINGO_SLOT(m_cash.m_slot)->FUN_1409ba5d0(id, rank, 1);
        BINGO_SLOT(m_cash.m_slot)->FUN_1409ba6d0();
    }
    m_free.FUN_140bb7fd0();
    m_cash.FUN_140bb7fd0();
    MS2Ptr<ASTextField> desc = GetChild<ASTextField>(CString("m_description"));
    if (desc.get() != 0)
    {
        Unk_BingoRef ref2 = FUN_1403ed060(FUN_140302b00())->FUN_140429c80();
        if (ref2.FUN_1403e8340())
            return;
        CStringW str = FUN_14025e7a0()->FUN_1422b0570(CString("$s_bingo_event_description"));
        CStringW cash = FUN_1401a9d70()->FUN_141811980(1, ref2.FUN_1403e8b90()->m_cashItemId);
        CStringW fre = FUN_1401a9d70()->FUN_141811980(1, ref2.FUN_1403e8b90()->m_freeItemId);
        str = FUN_140656190((const wchar_t*)str, fre, cash);
        desc->FUN_1422c4cd0(str);
    }
    FUN_140bb14d0();
}


// @0x140baf3a0
void UIBingoEventDialog::vfunc_79(void* pData)
{
    if (((CInPacket*)pData)->FUN_14070fe80() != 0xf7)
        return;
    unsigned char cmd = ((CInPacket*)pData)->vfunc_o8_1();
    if (cmd == 0x14)
    {
        m_time = CMsTime(FUN_140869440());
        m_stage = ((CInPacket*)pData)->vfunc_o8_3();
        CStringW strChecked = ((CInPacket*)pData)->vfunc_o8_8();
        m_checked.RemoveAll();
        FUN_1401d9a30(strChecked, m_checked, L",");
        CStringW strReceived = ((CInPacket*)pData)->vfunc_o8_8();
        m_received.RemoveAll();
        FUN_1401d9a30(strReceived, m_received, L",");
        unsigned count = ((CInPacket*)pData)->vfunc_o8_3();
        m_called.RemoveAll();
        for (unsigned i = 0; i < count; i++)
            m_called.Add(((CInPacket*)pData)->vfunc_o8_3());
        if (FUN_1422dc430() != 0)
            FUN_140bb14d0();
    }
    else if (cmd == 0x15)
    {
        CStringW strChecked = ((CInPacket*)pData)->vfunc_o8_8();
        m_checked.RemoveAll();
        FUN_1401d9a30(strChecked, m_checked, L",");
        CStringW strReceived = ((CInPacket*)pData)->vfunc_o8_8();
        m_received.RemoveAll();
        FUN_1401d9a30(strReceived, m_received, L",");
        FUN_140bb1d60();
        FUN_140bb2720();
    }
}

// @0x140baf740
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_stage = 0;
    m_cells.RemoveAll();
    m_lines.RemoveAll();
    m_board5 = 0;
    m_board.RemoveAll();
    m_checked.RemoveAll();
    m_received.RemoveAll();
    m_called.RemoveAll();
    for (size_t i = 0; i < m_rewardSlots.GetCount(); i++)
    {
        if (m_rewardSlots[i].get() != 0)
            m_rewardSlots[i].get()->RemoveAll();
    }
    m_rewardSlots.RemoveAll();
    m_rewardLists.RemoveAll();
    m_receive.RemoveAll();
    m_free.FUN_140bb69a0();
    m_cash.FUN_140bb69a0();
    while (!m_steps.empty())
        m_steps.pop();
    m_state = 0;
    m_msgOpen = false;
    m_time = (__time64_t)0;
    m_firework = 0;
    m_tick = 0;
    m_lineDone.RemoveAll();
    m_lineShown.RemoveAll();
    m_checkedCopy.RemoveAll();
}

// @0x140baf990
int UIBingoEventDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    m_msgOpen = false;
    int nResult = pMsg->FUN_1422b8a10();
    int nIndex = StrToIntW(pMsg->FUN_1422b8f40());
    if (nResult != 0)
        return 0;
    if (m_state == 0)
        return 0;
    if (FUN_1402bacf0(m_checked, m_board[nIndex]) != -1)
        return 0;
    Unk_BingoRef ref = FUN_1403ed060(FUN_140302b00())->FUN_140429c80();
    if (ref.FUN_1403e8340())
        return 0;
    COutPacket pkt(0x97, 0);
    pkt.vfunc_o10_1(0x16);
    if (m_state == 1)
        pkt.vfunc_o10_3(ref.FUN_1403e8b90()->m_freeItemId);
    else
        pkt.vfunc_o10_3(ref.FUN_1403e8b90()->m_cashItemId);
    pkt.vfunc_o10_3(m_board[nIndex]);
    FUN_140710590(pkt);
    BINGO_CLIP(m_cells[nIndex])->FUN_1422c1fe0(0);
    FUN_140bb3050(nIndex);
    return 0;
}

// @0x140bafbc0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::vfunc_72()
{
    if (FUN_14086ab70(CMsTime(m_time), CMsTime(FUN_140869440()), 0))
    {
        m_time = CMsTime(FUN_140869440());
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0, FUN_14025e7a0()->FUN_1422b0570(CString("$s_bingo_event_change_day")), 0, CStringW(L""));
        if (box.get() != 0)
        {
            if (m_msgOpen)
            {
                FUN_14151f890()->FUN_1419f8120();
                m_msgOpen = false;
            }
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBingoEventDialog::FUN_140bb1460));
            FUN_14151f150(box);
        }
    }
    if (m_steps.empty() || FUN_140869420() - m_tick < 100)
        return;
    Unk_BingoStep& step = m_steps.front();
    MS2Ptr<ASMovieClip> clip = step.m_clip;
    if (clip == 0)
    {
        m_steps.pop();
        return;
    }
    if (step.m_kind == 0)
    {
        if (!clip->FUN_1422bfca0())
        {
            clip->vfunc_4(true);
            clip->vfunc_13(CString("appear"));
            MS2Ptr<ASMovieClip> pen = step.m_clip->FUN_1409b4560(CString("m_penIcon"));
            if (pen == 0)
            {
                m_steps.pop();
                return;
            }
            if (!step.m_flag)
                pen->vfunc_15(CString("magicpencil"));
            else
                pen->vfunc_15(CString("magicpencil_plus"));
        }
        else
        {
            bool done = FUN_140184310(BINGO_CLIP(clip)->FUN_1422c2420(), "end") && step.m_index != -1;
            if (done)
            {
                clip->vfunc_4(false);
                m_cells[step.m_index]->vfunc_15(CString("checked"));
                m_steps.pop();
            }
        }
    }
    else if (step.m_kind == 2)
    {
        if (FUN_140184310(BINGO_CLIP(clip)->FUN_1422c2420(), "checked"))
        {
            clip->vfunc_13(CString("flip"));
            m_tick = FUN_140869420();
        }
        m_steps.pop();
    }
    else if (step.m_kind == 1)
    {
        if (!clip->FUN_1422bfca0())
        {
            clip->vfunc_4(true);
            clip->vfunc_13(CString("appear"));
            MS2Ptr<ASMovieClip> pen = clip->FUN_1409b4560(CString("m_penIcon"));
            if (pen == 0)
            {
                m_steps.pop();
                return;
            }
            if (!step.m_flag)
                pen->vfunc_15(CString("magicpencil"));
            else
                pen->vfunc_15(CString("magicpencil_plus"));
        }
        else if (FUN_140184310(BINGO_CLIP(clip)->FUN_1422c2420(), "checked"))
            m_steps.pop();
    }
    if (m_steps.empty())
    {
        FUN_140bb3bd0();
        FUN_141276180(s_sndLineComplete, CString(""));
        if (FUN_140bb3f80() == 12)
            FUN_140bb4040();
    }
}

// @0x140bb0660
void UIBingoEventDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog)
        dialog->vfunc_2(0, 0, 0);
}

// @0x140bb06e0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::FUN_140bb06e0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nIndex = FUN_140bb9640(params.pUserData);
    Unk_BingoRef ref = FUN_1403ed060(FUN_140302b00())->FUN_140429c80();
    if (ref.FUN_1403e8340())
        return;
    CStringW strMsg = FUN_14025e7a0()->FUN_1422b0570("$s_bingo_event_check");
    if (m_state == 1)
    {
        if (FUN_1402bacf0(m_called, m_board[nIndex]) == -1)
            return;
        int nItemId = ref.FUN_1403e8b90()->m_freeItemId;
        Unk_BingoItemKey key;
        key.m_id = nItemId;
        key.m_rank = FUN_14053feb0(nItemId);
        if (DAT_143ab2a90.FUN_140a5eda0(&key.m_id) < 1)
            return;
        CStringW strTag = FUN_1401ceea0(L"{0}", nIndex);
        strMsg = FUN_140275590(strMsg, FUN_1401a9d70()->FUN_141811980(1, key.m_id), m_board[nIndex]);
        FUN_1403b4750()->FUN_1416fb300(strMsg);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, strMsg, this, strTag);
        if (box.IsNull())
            return;
        BINGO_MSGBOX(box)->FUN_141a01c30(s_sndSpecialPopUp);
        FUN_14151f150(box);
        m_msgOpen = true;
    }
    else if (m_state == 2)
    {
        int nItemId = ref.FUN_1403e8b90()->m_cashItemId;
        Unk_BingoItemKey key;
        key.m_id = nItemId;
        key.m_rank = FUN_14053feb0(nItemId);
        if (DAT_143ab2a90.FUN_140a5eda0(&key.m_id) < 1)
            return;
        CStringW strTag = FUN_1401ceea0(L"{0}", nIndex);
        strMsg = FUN_140275590(strMsg, FUN_1401a9d70()->FUN_141811980(1, key.m_id), m_board[nIndex]);
        FUN_1403b4750()->FUN_1416fb300(strMsg);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, strMsg, this, strTag);
        if (box.IsNull())
            return;
        BINGO_MSGBOX(box)->FUN_141a01c30(s_sndSpecialPopUp);
        FUN_14151f150(box);
        m_msgOpen = true;
    }
}

// @0x140bb0e20
void UIBingoEventDialog::SendEventRewardMode23(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nIndex = FUN_140bb9640(params.pUserData);
    COutPacket pkt(0x97, 0);
    pkt.vfunc_o10_1(0x17);
    pkt.vfunc_o10_3(nIndex);
    FUN_140710590(pkt);
}

// @0x140bb0ea0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::FUN_140bb0ea0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    m_state = FUN_140bb9640(params.pUserData) + 1;
    if (m_state == 1)
    {
        MS2Ptr<CMsgBoxData> box = FUN_140d73f20(FUN_14025e7a0()->FUN_1422b0570("$s_bingo_event_click_normal"), 0);
        if (box.IsNull())
            return;
        BINGO_MSGBOX(box)->FUN_141a01c30(s_sndRegPopUp);
        box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBingoEventDialog::FUN_140bb14a0));
        FUN_14151f150(box);
        m_msgOpen = true;
        m_cash.FUN_140bb7fd0();
        m_free.FUN_140bb8100();
    }
    else
    {
        Unk_BingoRef ref = FUN_1403ed060(FUN_140302b00())->FUN_140429c80();
        if (ref.FUN_1403e8340())
            return;
        CStringW strMsg = FUN_1401e8510(FUN_14025e7a0()->FUN_1422b0570("$s_bingo_event_click_rare"), FUN_1401a9d70()->FUN_141811980(1, ref.FUN_1403e8b90()->m_cashItemId));
        FUN_1403b4750()->FUN_1416fb300(strMsg);
        MS2Ptr<CMsgBoxData> box = FUN_140d73f20(strMsg, 0);
        if (box.IsNull())
            return;
        BINGO_MSGBOX(box)->FUN_141a01c30(s_sndRegPopUp);
        box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBingoEventDialog::FUN_140bb14a0));
        FUN_14151f150(box);
        m_msgOpen = true;
        m_cash.FUN_140bb8100();
        m_free.FUN_140bb7fd0();
    }
    FUN_140bb46e0();
    FUN_140bb1580();
}

// @0x140bb13e0
void UIBingoEventDialog::FUN_140bb13e0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nIndex = FUN_140bb9640(params.pUserData);
    if (nIndex == 0)
        m_free.FUN_140bb7fd0();
    else
        m_cash.FUN_140bb7fd0();
    m_state = 0;
    FUN_140bb46e0();
    FUN_140bb1580();
}

// @0x140bb1460
bool UIBingoEventDialog::FUN_140bb1460(int, const CMsgBoxData&)
{
    vfunc_67();
    return true;
}

// @0x140bb14a0
bool UIBingoEventDialog::FUN_140bb14a0(int, const CMsgBoxData&)
{
    m_msgOpen = false;
    return true;
}

// @0x140bb14d0
void UIBingoEventDialog::FUN_140bb14d0()
{
    if (m_30 == 0)
        return;
    FUN_140bb1580();
    FUN_140bb1d60();
    FUN_140bb2310();
    FUN_140bb2720();
    if ((size_t)FUN_140bb3f80() == 12)
    {
        m_free.m_use->FUN_1422c1fe0(0);
        m_cash.m_use->FUN_1422c1fe0(0);
    }
}

// @0x140bb1580
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::FUN_140bb1580()
{
    if (m_30 == 0 || m_stage == 0 || m_cells.GetCount() != 25)
        return;
    m_board.RemoveAll();
    m_board.SetCount(25, -1);
    for (unsigned i = 0; i < 25; i++)
        m_board.SetAt((size_t)(int)i, i + 1);
    FUN_1401cdae0(m_board, m_stage);
    for (unsigned i = 0; i < m_board.GetCount(); i++)
    {
        int nValue = m_board[i];
        MS2Ptr<ASMovieClip> clip = m_cells[i];
        if (clip == 0)
            continue;
        MS2Ptr<ASMovieClip> shown(0);
        MS2Ptr<ASMovieClip> hidden(0);
        if (FUN_1402bacf0(m_called, nValue) == -1)
        {
            shown = clip->FUN_1409b4560("m_textField");
            hidden = clip->FUN_1409b4560("m_textFieldToday");
        }
        else
        {
            hidden = clip->FUN_1409b4560("m_textField");
            shown = clip->FUN_1409b4560("m_textFieldToday");
        }
        if (shown.IsNull() || hidden.IsNull())
            return;
        hidden->vfunc_4(false);
        shown->vfunc_4(true);
        MS2Ptr<ASTextField> text = shown->FUN_1409b4620("textField");
        if (text.get() != 0)
            BINGO_TEXT(text)->FUN_1422c4c80(FUN_1402bb1c0("{0}", nValue));
        if (FUN_1402bacf0(m_checked, nValue) == -1)
        {
            clip->vfunc_15("nor");
            BINGO_CLIP(clip)->FUN_1422c2a70(BingoParamsDelegate(this, &UIBingoEventDialog::FUN_140bb06e0), FUN_140bb9630(i));
        }
        else
        {
            clip->vfunc_15("checked");
            BINGO_CLIP(clip)->FUN_1422c2af0(BingoParamsDelegate(this, &UIBingoEventDialog::FUN_140bb06e0));
        }
    }
    FUN_140bb2c40();
    FUN_140bb3bd0();
}

// @0x140bb1d60
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::FUN_140bb1d60()
{
    if (m_30 == 0)
        return;
    Unk_BingoRef ref = FUN_1403ed060(FUN_140302b00())->FUN_140429c80();
    if (ref.FUN_1403e8340())
        return;
    int nFreeId = ref.FUN_1403e8b90()->m_freeItemId;
    int nCashId = ref.FUN_1403e8b90()->m_cashItemId;
    Unk_BingoItemKey freeKey;
    freeKey.m_id = nFreeId;
    freeKey.m_rank = FUN_14053feb0(nFreeId);
    Unk_BingoItemKey cashKey;
    cashKey.m_id = nCashId;
    cashKey.m_rank = FUN_14053feb0(nCashId);
    int nFree = DAT_143ab2a90.FUN_140a5eda0(&freeKey.m_id);
    int nCash = DAT_143ab2a90.FUN_140a5eda0(&cashKey.m_id);
    if (m_free.m_text.get() != 0)
        BINGO_TEXT(m_free.m_text)->FUN_1422c4c80(FUN_1402bb1c0("X {0}", nFree));
    if (m_cash.m_text.get() != 0)
        BINGO_TEXT(m_cash.m_text)->FUN_1422c4c80(FUN_1402bb1c0("X {0}", nCash));
    if (m_free.m_use == 0)
        return;
    if (nFree < 1)
    {
        m_free.m_use->FUN_1422c1fe0(0);
        if (m_state == 1)
        {
            m_free.FUN_140bb7fd0();
            m_state = 0;
            for (unsigned i = 0; i < m_cells.GetCount(); i++)
            {
                MS2Ptr<ASMovieClip> clip = m_cells[i];
                if (clip == 0)
                    continue;
                if (BINGO_CLIP(clip)->FUN_1422c2030() != 0)
                    BINGO_CLIP(clip)->FUN_1422c1fe0(0);
            }
        }
    }
    else
    {
        m_free.m_use->FUN_1422c1fe0(1);
        if (FUN_140bb3f80() == 12)
        {
            m_free.FUN_140bb7fd0();
            m_free.m_use->FUN_1422c1fe0(0);
        }
    }
    if (m_cash.m_use == 0)
        return;
    if (nCash < 1)
    {
        m_cash.m_use->FUN_1422c1fe0(0);
        if (m_state == 2)
        {
            m_cash.FUN_140bb7fd0();
            m_state = 0;
            for (unsigned i = 0; i < m_cells.GetCount(); i++)
            {
                MS2Ptr<ASMovieClip> clip = m_cells[i];
                if (clip == 0)
                    continue;
                if (BINGO_CLIP(clip)->FUN_1422c2030() != 0)
                    BINGO_CLIP(clip)->FUN_1422c1fe0(0);
            }
        }
    }
    else
    {
        m_cash.m_use->FUN_1422c1fe0(1);
        if (FUN_140bb3f80() == 12)
        {
            m_cash.FUN_140bb7fd0();
            m_cash.m_use->FUN_1422c1fe0(0);
        }
    }
}

// @0x140bb2310
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::FUN_140bb2310()
{
    if (m_30 == 0)
        return;
    MS2Ptr<ASMovieClip> daily = GetChild<ASMovieClip>("m_dailyNumber");
    if (daily.IsNull())
        return;
    unsigned nCalled = (unsigned)m_called.GetCount();
    if (nCalled >= 6)
        return;
    MS2Ptr<ASMovieClip> current(0);
    for (unsigned long long i = 0; i < 5; i++)
    {
        MS2Ptr<ASMovieClip> list = daily->FUN_1409b4560(FUN_1401d9af0("m_dailyList{0}", i));
        if (list.IsNull())
            continue;
        if (i + 1 == nCalled)
        {
            current = list;
            list->vfunc_4(true);
        }
        else
            list->vfunc_4(false);
    }
    if (current.IsNull())
        return;
    for (unsigned long long i = 0; i < m_called.GetCount(); i++)
    {
        MS2Ptr<ASMovieClip> card = current->FUN_1409b4560(FUN_1401d9af0("m_numberCard{0}", i));
        if (card.IsNull())
            break;
        MS2Ptr<ASTextField> text = card->FUN_1409b4620("textField");
        if (text.IsNull())
            break;
        text->FUN_1422c4cd0(FUN_1401ceea0(L"{0}", m_called[i]));
    }
}

// @0x140bb2720
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::FUN_140bb2720()
{
    if (m_30 == 0)
        return;
    unsigned nLines = FUN_140bb3f80();
    Unk_BingoRef ref = FUN_1403ed060(FUN_140302b00())->FUN_140429c80();
    if (ref.FUN_1403e8340())
        return;
    for (unsigned i = 0; i < 8; i++)
    {
        void* rewards = (char*)ref.FUN_1403e8b90() + 0x48;
        if (FUN_140412ed0(rewards) != 8)
            continue;
        MS2Ptr<ASMovieClip> panel = m_rewardLists[i];
        if (panel == 0)
            continue;
        MS2Ptr<Unk_140acd6e0> button = BINGO_CLIP(panel)->FUN_140acce30("m_receiveButton");
        if (button == 0)
            continue;
        int nIndex = i;
        if (FUN_1402bacf0(m_received, nIndex) == -1)
        {
            if (nLines < i + 1)
            {
                panel->vfunc_15("normal");
                button->FUN_1422c1fe0(0);
            }
            else if (i == 7 && nLines != 12)
            {
                panel->vfunc_15("normal");
                button->FUN_1422c1fe0(0);
            }
            else
            {
                panel->vfunc_15("complete");
                button->FUN_1422c1fe0(1);
                for (unsigned long long j = 0; j < 2; j++)
                {
                    MS2Ptr<ASMovieClip> effect = m_rewardLists[i]->FUN_1409b4560(FUN_1401d9af0("m_effect{0}", j));
                    if (effect.IsNull())
                        continue;
                    if (j == FUN_1404111b0(((Unk_BingoRewardTable*)rewards)->FUN_140bb6b30(i)).FUN_140412e50() - 1)
                    {
                        effect->vfunc_4(true);
                        BINGO_CLIP(effect)->FUN_1422c6640(0);
                        BINGO_CLIP(effect)->FUN_1422deb40(0);
                    }
                    else
                        effect->vfunc_4(false);
                }
            }
        }
        else
            panel->vfunc_15("received");
    }
}

// @0x140bb2c40
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::FUN_140bb2c40()
{
    FUN_140bb43a0(m_lineDone, m_checked);
    for (unsigned i = 0; i < m_lineDone.GetCount(); i++)
    {
        if (!m_lineDone[i])
            continue;
        MS2Ptr<ASMovieClip> line = m_lines[i];
        line->vfunc_4(true);
        line->vfunc_15("checked");
        if (i < 5)
        {
            for (int k = 0; k < 5; k++)
                m_cells[i + k * 5]->vfunc_15("bingo");
        }
        else if (i < 10)
        {
            for (int k = 0; k < 5; k++)
                m_cells[(i - 5) * 5 + k]->vfunc_15("bingo");
        }
        else if (i == 10)
        {
            for (int k = 0; k < 5; k++)
                m_cells[k * 6]->vfunc_15("bingo");
        }
        else if (i == 11)
        {
            for (int k = 0; k < 5; k++)
                m_cells[k * 4 + 4]->vfunc_15("bingo");
        }
    }
}

// @0x140bb3050
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::FUN_140bb3050(int nIndex)
{
    MS2Ptr<ASMovieClip> check = m_board5->FUN_1409b4560(FUN_1402bb1c0("m_check{0}", nIndex));
    if (check.IsNull())
        return;
    bool bPlus = m_state == 2;
    m_steps.push(Unk_BingoStep(0, check, nIndex, bPlus));
    m_checkedCopy.Copy(m_checked);
    m_checkedCopy.Add(m_board[nIndex]);
    FUN_140bb43a0(m_lineShown, m_checkedCopy);
    int nBefore = FUN_140bb3f80();
    int nChanged = 0;
    for (unsigned i = 0; i < m_lineDone.GetCount(); i++)
    {
        if (m_lineDone[i] == m_lineShown[i])
            continue;
        nChanged++;
        for (int k = 0; k < 5; k++)
        {
            int nCell;
            if (i < 5)
                nCell = i + k * 5;
            else if (i < 10)
                nCell = (i - 5) * 5 + k;
            else if (i == 10)
                nCell = k * 6;
            else if (i == 11)
                nCell = k * 4 + 4;
            else
                break;
            MS2Ptr<ASMovieClip> cell = m_cells[nCell];
            if (cell == 0)
                continue;
            MS2Ptr<ASMovieClip> blind = cell->FUN_1409b4560("m_blind");
            if (blind == 0)
                continue;
            m_steps.push(Unk_BingoStep(2, cell, bPlus));
            blind->vfunc_4(false);
        }
        m_steps.push(Unk_BingoStep(1, m_lines[i], bPlus));
        FUN_140bb4150(nBefore + nChanged);
    }
    m_checked.Copy(m_checkedCopy);
    m_lineDone.Copy(m_lineShown);
}

// @0x140bb3bd0
void UIBingoEventDialog::FUN_140bb3bd0()
{
    if (m_30 == 0)
        return;
    if (m_board.GetCount() != m_cells.GetCount())
        return;
    for (size_t i = 0; i < m_board.GetCount(); i++)
    {
        int nValue = m_board[i];
        MS2Ptr<ASMovieClip> clip = m_cells[i];
        if (clip == 0)
            continue;
        MS2Ptr<ASMovieClip> blind = clip->FUN_1409b4560("m_blind");
        if (blind == 0)
            continue;
        if (m_state == 0)
        {
            BINGO_CLIP(clip)->FUN_1422c1fe0(0);
            blind->vfunc_4(false);
        }
        else if (m_state == 1)
        {
            if (FUN_1402bacf0(m_called, nValue) == -1)
            {
                BINGO_CLIP(clip)->FUN_1422c1fe0(0);
                blind->vfunc_4(true);
            }
            else if (FUN_1402bacf0(m_checked, nValue) != -1)
            {
                BINGO_CLIP(clip)->FUN_1422c1fe0(0);
                blind->vfunc_4(true);
            }
            else
            {
                BINGO_CLIP(clip)->FUN_1422c1fe0(1);
                blind->vfunc_4(false);
            }
        }
        else if (m_state == 2)
        {
            if (FUN_1402bacf0(m_checked, nValue) != -1)
            {
                BINGO_CLIP(clip)->FUN_1422c1fe0(0);
                blind->vfunc_4(true);
            }
            else
            {
                BINGO_CLIP(clip)->FUN_1422c1fe0(1);
                blind->vfunc_4(false);
            }
        }
    }
}

// @0x140bb3f80
unsigned UIBingoEventDialog::FUN_140bb3f80()
{
    Unk_BingoRef ref = FUN_1403ed060(FUN_140302b00())->FUN_140429c80();
    if (ref.FUN_1403e8340())
        return 0;
    return FUN_140406550(ref.FUN_1403e8b90(), m_stage, &m_checked);
}

// @0x140bb4040
void UIBingoEventDialog::FUN_140bb4040()
{
    if (m_30 == 0)
        return;
    MS2Ptr<ASMovieClip> firework = GetChild<ASMovieClip>("m_fireworkEffect");
    if (firework.IsNull())
        return;
    firework->vfunc_4(true);
    firework->vfunc_12(0);
    FUN_141276180(s_sndSuccess, "");
}

// @0x140bb4150
void UIBingoEventDialog::FUN_140bb4150(unsigned nLines)
{
    if ((size_t)nLines == 12)
    {
        FUN_1412751f0(FUN_1402a61e0(FUN_14025e7a0()->FUN_1422b0570("$s_bingo_event_complete_all_bingo")), 3, 1);
        return;
    }
    Unk_BingoRef ref = FUN_1403ed060(FUN_140302b00())->FUN_140429c80();
    if (ref.FUN_1403e8340())
        return;
    void* rewards = (char*)ref.FUN_1403e8b90() + 0x48;
    for (size_t i = 0; i < FUN_140412ed0(rewards); i++)
    {
        if (i == nLines)
        {
            FUN_1412751f0(FUN_140292a70(FUN_14025e7a0()->FUN_1422b0570("$s_bingo_event_complete_bingo"), nLines), 3, 1);
            return;
        }
    }
}

// @0x140bb43a0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIBingoEventDialog::FUN_140bb43a0(ATL::CAtlArray<bool>& lines, ATL::CAtlArray<int>& checked)
{
    lines.RemoveAll();
    lines.SetCount(12, -1);
    char grid[25];
    size_t nLine = 0;
    for (size_t i = 0; i < m_board.GetCount(); i++)
    {
        if (FUN_1402bacf0(checked, m_board[i]) == -1)
        {
            char* row = grid + (i / 5) * 5;
            row[i % 5] = 0;
        }
        else
        {
            char* row = grid + (i / 5) * 5;
            row[i % 5] = 1;
        }
    }
    for (size_t r = 0; r < 5; r++)
    {
        size_t c = 0;
        while (c < 5 && grid[(int)r + (int)c * 5] != 0)
        {
            if (c == 4)
                lines.SetAt(nLine, true);
            c++;
        }
        nLine++;
    }
    for (int r = 0; r < 5; r++)
    {
        int c = 0;
        while (c < 5 && grid[c + r * 5] != 0)
        {
            if (c == 4)
                lines.SetAt(nLine, true);
            c++;
        }
        nLine++;
    }
    int d = 0;
    while (d < 5 && grid[d + d * 5] != 0)
    {
        if (d == 4)
            lines.SetAt(nLine, true);
        d++;
    }
    nLine++;
    int e = 0;
    while (e < 5 && grid[(e * 5 - e) + 4] != 0)
    {
        if (e == 4)
            lines.SetAt(nLine, true);
        e++;
    }
}

// @0x140bb46e0
void UIBingoEventDialog::FUN_140bb46e0()
{
    while (!m_steps.empty())
    {
        Unk_BingoStep& step = m_steps.front();
        if (step.m_kind == 0)
            step.m_clip->vfunc_4(false);
        m_steps.pop();
    }
    if ((size_t)FUN_140bb3f80() == 12)
        FUN_140bb4040();
}

// @0x140bb69a0
void Unk_BingoPanel::FUN_140bb69a0()
{
    m_icon = 0;
    m_text = 0;
    m_use = 0;
    m_cancel = 0;
    m_effect = 0;
    m_slot = 0;
}

// @0x140bb7fd0
void Unk_BingoPanel::FUN_140bb7fd0()
{
    if (m_icon.get() != 0)
    {
        CString strLabel("nor");
        m_icon->vfunc_13(strLabel);
    }
    if (m_use.get() != 0)
        m_use->vfunc_4(true);
    if (m_cancel.get() != 0)
        m_cancel->vfunc_4(false);
    if (m_effect.get() != 0)
        m_effect->vfunc_4(false);
}

// @0x140bb8100
void Unk_BingoPanel::FUN_140bb8100()
{
    if (m_icon.get() != 0)
    {
        CString strLabel("selected");
        m_icon->vfunc_13(strLabel);
    }
    if (m_use.get() != 0)
        m_use->vfunc_4(false);
    if (m_cancel.get() != 0)
        m_cancel->vfunc_4(true);
    if (m_effect.get() != 0)
        m_effect->vfunc_4(true);
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140BAD410, UIBingoEventDialog, GetTypeName, 61, 0xF19E5FDD);
MS2_REPLACE_METHOD(0x140BAD460, UIBingoEventDialog, vfunc_65, 194, 0xB8401979);
MS2_REPLACE_METHOD(0x140BAD530, UIBingoEventDialog, OnLoadComplete, 7777, 0xDEF42ED3);
MS2_REPLACE_METHOD(0x140BAF3A0, UIBingoEventDialog, vfunc_79, 921, 0xD440CE58);
MS2_REPLACE_METHOD(0x140BAF740, UIBingoEventDialog, vfunc_26, 586, 0x3FB4D0D5);
MS2_REPLACE_METHOD_VIA(0x140BAF990, UIBingoEventDialog, IMessageListener, OnMessage, 550, 0x6080E95C);
MS2_REPLACE_METHOD(0x140BAFBC0, UIBingoEventDialog, vfunc_72, 2704, 0xD97805CE);
MS2_REPLACE_METHOD(0x140BB0660, UIBingoEventDialog, vfunc_43, 110, 0xCD09A3C9);
MS2_REPLACE_METHOD(0x140BB0E20, UIBingoEventDialog, SendEventRewardMode23, 115, 0xC9AB93BE);
MS2_REPLACE_METHOD(0x140BB13E0, UIBingoEventDialog, FUN_140bb13e0, 119, 0xBD64CF06);
MS2_REPLACE_METHOD(0x140BB1460, UIBingoEventDialog, FUN_140bb1460, 44, 0x5B0A3F82);
MS2_REPLACE_METHOD(0x140BB14D0, UIBingoEventDialog, FUN_140bb14d0, 158, 0x5D5E2DE1);
MS2_REPLACE_METHOD(0x140BB1580, UIBingoEventDialog, FUN_140bb1580, 2001, 0x145B4613);
MS2_REPLACE_METHOD(0x140BB1D60, UIBingoEventDialog, FUN_140bb1d60, 1439, 0xB5799AF2);
MS2_REPLACE_METHOD(0x140BB2310, UIBingoEventDialog, FUN_140bb2310, 1031, 0x7AF628CE);
MS2_REPLACE_METHOD(0x140BB2720, UIBingoEventDialog, FUN_140bb2720, 1304, 0x9630E841);
MS2_REPLACE_METHOD(0x140BB2C40, UIBingoEventDialog, FUN_140bb2c40, 1028, 0x8B850411);
MS2_REPLACE_METHOD(0x140BB3050, UIBingoEventDialog, FUN_140bb3050, 2923, 0xBCEF99A8);
MS2_REPLACE_METHOD(0x140BB3BD0, UIBingoEventDialog, FUN_140bb3bd0, 937, 0xA5C210EF);
MS2_REPLACE_METHOD(0x140BB3F80, UIBingoEventDialog, FUN_140bb3f80, 175, 0x5FCF2704);
MS2_REPLACE_METHOD(0x140BB4150, UIBingoEventDialog, FUN_140bb4150, 577, 0x731DDFCE);
MS2_REPLACE_METHOD(0x140BB43A0, UIBingoEventDialog, FUN_140bb43a0, 819, 0x3C30635D);
MS2_REPLACE_METHOD(0x140BB46E0, UIBingoEventDialog, FUN_140bb46e0, 163, 0xFB4F9A6C);
