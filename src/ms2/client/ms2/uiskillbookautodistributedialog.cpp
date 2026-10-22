// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The skill window ("SkillBookTreeDialog", UI type 0x4f2d): up to
// three saved skill sets (tabs) per character, each with its own CSkillPointSimulator, the job / sub job skill tree filled
// into the movie slot by slot, the point reset / apply / auto-distribute flow, and the "SkillBookAutoDistributeDialog"
// (UI type 0x4f20) that lets the player pick one of the table's presets (Table/skillAutoDistribute.xml). See
// uiskillbookautodistributedialog.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\uiskillbookautodistributedialog.cpp
// MS2-RANGE: 0x1400dc6d0-0x1400dc9e0 .text$di
// MS2-RANGE: 0x140ec41e0-0x140ed74c0 .text$mn
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@V?$CElementTraits@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@@ATL@@@ATL@@@@6B@ 0x142e66dc0
// MS2-PIN: ??$FUN_14028dfa0@IIII@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBI111@Z 0x140ed0300
// MS2-PIN: ??$FUN_14028dfa0@IIIIG@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBI111AEBG@Z 0x140ed06e0
// MS2-PIN: ??$FUN_14028dfa0@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBIAEBV01@@Z 0x140ed0b00
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UISkillBookAutoDistributeDialog@@UEAAHXZ 0x140ec4d20 ; unique
// MS2-PIN: ??$?0AEBH$0A@@?$tuple@AEBH@std@@QEAA@AEBH@Z 0x140ecfdf0 ; unique
// MS2-PIN: ??$?0VUISkillBookTreeDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUISkillBookTreeDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140ecfeb0 ; unique
// MS2-PIN: ??$?0U_Exact_args_t@std@@AEBH$$V$0A@@?$tuple@AEBH@std@@QEAA@U_Exact_args_t@1@AEBH@Z 0x140ed0010 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140ed0070 ; prop
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140ed01d0 ; unique
// MS2-PIN: ??$?8PEAVUISkillBookTreeDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUISkillBookTreeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140ed0220 ; prop
// MS2-PIN: ??$?8PEAVUISkillBookTreeDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUISkillBookTreeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140ed0290 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140ed13c0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140ed2a40 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140ed2af0 ; unique
// MS2-PIN: ??$forward@AEAU?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@std@@YAAEAU?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@0@AEAU10@@Z 0x140ed2b90 ; prop
// MS2-PIN: ??$forward@AEBH@std@@YAAEBHAEBH@Z 0x140ed2be0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140ed2bf0 ; prop
// MS2-PIN: ??$forward@V?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x140ed2c10 ; prop
// MS2-PIN: ??$forward_as_tuple@AEBH@std@@YA?AV?$tuple@AEBH@0@AEBH@Z 0x140ed2c20 ; unique
// MS2-PIN: ??$move@AEAV?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x140ed2d10 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUISkillBookTreeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140ed3080 ; unique
// MS2-PIN: ??0?$TPtrValue@V?$CAtlArray@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@V?$CElementTraits@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@@ATL@@@ATL@@@@QEAA@AEBUUnk_GrNewTag@@@Z 0x140ed3120 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCMsgBoxData@@@@QEAA@H@Z 0x140ed3220 ; unique
// MS2-PIN: ??0?$tuple@AEBH@std@@QEAA@$$QEAV01@@Z 0x140ed3460 ; unique
// MS2-PIN: ??8?$MS2Ptr@VCSkillBookTreeTabConfig@@@@QEBA_NPEAVCSkillBookTreeTabConfig@@@Z 0x140ed3aa0 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140ed3c50 ; prop
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x140ed3d60 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@V?$CElementTraits@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@@ATL@@@ATL@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@V?$CElementTraits@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x140ed4a40 ; unique
// MS2-PIN: ?vfunc_48@UISkillBookTreeDialog@@UEAAHXZ 0x140ed4c90 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@V?$CElementTraits@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@@ATL@@@ATL@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@V?$CElementTraits@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@@ATL@@@ATL@@@@@3@@ATL@@QEBA_NAEBHAEAV?$TPtrValue@V?$CAtlArray@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@V?$CElementTraits@V?$MS2Ptr@VAutoDistribute@UISkillBookTreeDialog@@@@@ATL@@@ATL@@@@@Z 0x140ed51e0 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@_JV?$MS2Ptr@VCSkillPointSimulator@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCSkillPointSimulator@@@@@3@@ATL@@QEBA_N_JAEAV?$MS2Ptr@VCSkillPointSimulator@@@@@Z 0x140ed5250 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HJU?$less@H@std@@V?$allocator@U?$pair@$$CBHJ@std@@@2@@std@@@std@@PEAX@2@@Z 0x140ed6c20 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHJ@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHJ@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x140ed6ce0 ; prop
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUISkillBookTreeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140ed7020 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUISkillBookTreeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140ed7080 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUISkillBookTreeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140ed70e0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUISkillBookTreeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140ed7110 ; unique
// MS2-PIN: ??$Call@VUISkillBookTreeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUISkillBookTreeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUISkillBookTreeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140ed7150 ; unique
// MS2-PIN: ??$Call@VUISkillBookTreeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUISkillBookTreeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUISkillBookTreeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140ed7190 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUISkillBookTreeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140ed71d0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUISkillBookTreeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140ed7230 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_PCSkillTree@@@@AEAAXPEAX@Z 0x140ed6f30 ; merge-bind
//
// File name assumed (the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiskillbookautodistributedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiskillbookautodistributedialog.h"

#include <algorithm>
#include <map>
#include <vector>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/jobsystemcli.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- header statics (dynamic initializers 0x1400dc6d0..0x1400dc9e0; the same pair as uiarcademaindialog.cpp) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strSortNames7b[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);
#endif

// ---- unit-local views of exe objects ----

// The local player and the world (FUN_1403ed2d0 -> FUN_141bd0cc0).
class Unk_SkillField;
class Unk_SkillWorld { public: MyPC* FUN_141bd0cc0(); MS2Ptr<Unk_SkillField> FUN_141bd30a0(); };
Unk_SkillWorld* FUN_1403ed2d0();

// The three "m_distribute{N}" buttons.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422cdfb0(const CStringW& strLabel);                           // the button text
    void FUN_1422c7cd0(const Scaleform::GFx::Value& tooltip);               // the tooltip object
};

// The dialog's bound-child lookup (UISwfEntity members; the exe has one COMDAT per child class).
class Unk_SkillDlgView : public UIDialog
{
public:
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);            // button child
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);              // movie clip child
};

// The movie root of the dialog (RTTI .?AVASDialog@@); slot 24 repaints it. // MS2: slot 24
class ASDialog : public ASDisplayObject {};
class Unk_ASDialogSlots
{
public:
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3(); virtual void V4(); virtual void V5();
    virtual void V6(); virtual void V7(); virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15(); virtual void V16(); virtual void V17();
    virtual void V18(); virtual void V19(); virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void Invalidate(bool bNow);                                     // +0xc0
};
// The dialog background clip (the height follows the number of entries).
class Unk_SkillBgClip : public ASMovieClip
{
public:
    void FUN_1422c0ef0(int nHeight);
};

bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);                // equals
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);        // format one argument
CString FUN_14052ea30(const char* szFormat, const int* pn);                 // format one int
void FUN_140d73aa0(CStringW text, int type, void* pListener, CStringW tag); // open a message box that reports to pListener
UIDialog* FUN_1409eb120(int nId);                                           // the shown dialog of a UI id
void FUN_14151f200();                                                       // close the message box
class Unk_SkillLogService { public: };
Unk_SkillLogService* FUN_140d8ee90();
void FUN_140a1f970(Unk_SkillLogService* pService, const CString& strEvent, const CString& strParam);   // usage log
CString FUN_1401d4330(const wchar_t* psz, int nCodePage);                   // narrows a string

// @0x140ec41e0
UISkillBookAutoDistributeDialog::UISkillBookAutoDistributeDialog()
{
    m_nSelected = 0;
    FUN_141924170(1);
    FUN_1422dc3b0(1);
}

// @0x140ec4290
UISkillBookAutoDistributeDialog::~UISkillBookAutoDistributeDialog()
{
}

// @0x140ec4300
CString UISkillBookAutoDistributeDialog::GetTypeName()
{
    return "SkillBookAutoDistributeDialog";
}

// @0x140ec4350
void UISkillBookAutoDistributeDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    m_names.RemoveAll();
    m_tooltips.RemoveAll();
}

// @0x140ec43a0
int UISkillBookAutoDistributeDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140ec43d0
void UISkillBookAutoDistributeDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    FUN_140ec48e0();
}

// @0x140ec4400
int UISkillBookAutoDistributeDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("onDistribute", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_nSelected = data.FUN_1422b8a10() - 1;
            if (m_names.GetCount() > m_nSelected)
            {
                CStringW strText = FUN_1405c2690(L"s_msg_skillbook_auto_distribute_msgbox", GetStringCommonByKey(m_names[m_nSelected]));
                FUN_140d73aa0(strText, 1, static_cast<IMessageListener*>(this), L"onDistribute");
            }
        }
        return 1;
    }
    return 0;
}

// @0x140ec4660
int UISkillBookAutoDistributeDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        if ((m_30.get() ? true : false) && nResult == 0)
        {
            CStringW strTag = pMsg->FUN_1422b8f40();
            if (FUN_1403b3c40(strTag, L"onDistribute") != 0)
            {
                UISkillBookTreeDialog* pTree = static_cast<UISkillBookTreeDialog*>(FUN_1409eb120(0x4f2d));
                if (pTree != 0 && pTree->vfunc_55() == 0)
                {
                    pTree->ApplyDistribute(m_nSelected);
                    CStringW strName = GetStringCommonByKey(m_names[m_nSelected]);
                    FUN_140a1f970(FUN_140d8ee90(), "skll_auto_distribute", FUN_1401d4330(m_names[m_nSelected], 0));
                }
            }
            FUN_14151f200();
            vfunc_67();
        }
        else
        {
            FUN_14151f200();
        }
    }
    return 0;
}

// @0x140ec48e0
void UISkillBookAutoDistributeDialog::FUN_140ec48e0()
{
    if (m_30.IsNull())
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    int nShown = 0;
    int nNo;
    for (unsigned i = 0; i < 3; i++)
    {
        nNo = i + 1;
        CString strName = FUN_14052ea30("m_distribute{0}", &nNo);
        MS2Ptr<Unk_140acd6e0> spButton = static_cast<Unk_SkillDlgView*>(static_cast<UIDialog*>(this))->FUN_140bb4b10(strName);
        if (spButton == 0)
            continue;
        spButton->vfunc_3(1);
        if (m_names.GetCount() <= i)
        {
            spButton->vfunc_3(0);
        }
        else
        {
            spButton->FUN_1422cdfb0(GetStringCommonByKey(m_names[i]));
            CStringW strTooltip = GetStringCommonByKey(m_tooltips[i]);
            if (!strTooltip.IsEmpty())
            {
                ASTooltip tooltip(2);
                tooltip.FUN_1409e26b0(strTooltip);
                tooltip.FUN_1409c6dc0(4);
                spButton->FUN_1422c7cd0(tooltip.FUN_1422bb890());
            }
            nShown++;
        }
    }
    if (MS2Ptr<ASDialog> spDialog = dynamic_cast<ASDialog*>((AScript*)m_30))
    {
        if (MS2Ptr<ASMovieClip> spBg = static_cast<Unk_SkillDlgView*>(static_cast<UIDialog*>(this))->FUN_140ba7930("m_bg"))
        {
            int nHeight = nShown * 0x2a + 0x41;
            static_cast<Unk_SkillBgClip*>(spBg.operator->())->FUN_1422c0ef0(nHeight);
        }
        reinterpret_cast<Unk_ASDialogSlots*>(spDialog.operator->())->Invalidate(true);
    }
}


void FUN_1422bcd10(Scaleform::GFx::Value* pValue, int n);               // Value = n (Int)
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, unsigned int n);     // Value = n (UInt)
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned __int64 n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// @0x140ed0ed0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, CStringW a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3.GetString());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ed0fd0
inline Scaleform::GFx::Value AScript::FUN_140ed0fd0(const char* szMethod, int a1, bool a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ed1090
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, CStringW a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1.GetString());
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2.GetString());
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ed11b0
inline Scaleform::GFx::Value AScript::FUN_140ed11b0(const char* szMethod, unsigned int a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ed1250
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, unsigned __int64 a1, CStringW a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce00(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2.GetString());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ec4d30
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ---- the skill window (UISkillBookTreeDialog) ----

typedef Delegate<bool(int, const CMsgBoxData&)> SkillBoxDelegate;
typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> SkillClickDelegate;

// job code -> (rank -> skill points), and job code -> extra skill points (data of other units).
class Unk_SSGCountMapMap : public std::map<int, std::map<int, long> > {};
class Unk_SSGCountMap : public std::map<int, long> {};
extern Unk_SSGCountMapMap DAT_143ab32e8;
extern Unk_SSGCountMap DAT_143ab32f8;

// ---- unit-local views of exe objects (the skill window) ----

class Unk_PCSkillTree : public CPtred { public: unsigned short FUN_14080baf0(unsigned nSkillId); };   // the tier option level
class Unk_SkillTable
{
public:
    MS2Ptr<SkillData> FUN_1407ee1d0(unsigned nSkillId);
    MS2Ptr<SkillLevelData> FUN_1407ee2f0(unsigned nSkillId, unsigned short nLevel);
};
Unk_SkillTable* FUN_1401958b0();
CFeatureManager* FUN_140166410();
class Unk_SkillJobTable { public: int FUN_140644b80(int nJobCode); };
Unk_SkillJobTable* FUN_1401d7a50();
class Unk_SkillField : public CPtred { public: int FUN_140375660(int nProperty); };
class Unk_SkillStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_SkillStrings* FUN_1401a9d70();
class Unk_SkillNotify { public: void FUN_141ac18e0(bool bShow); };
Unk_SkillNotify* FUN_140938cd0(int nWindow);
class Unk_SkillStatusHost
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);
    void FUN_141b0cd90(UIStatusEventListener* pListener);
};
Unk_SkillStatusHost* FUN_140aa6d40();

// The network service (singleton 0x140d86260): only the slots used by the skill window.
class Unk_SkillService
{
public:
    virtual void S0(); virtual void S1(); virtual void S2(); virtual void S3(); virtual void S4();
    virtual void S5(); virtual void S6(); virtual void S7(); virtual void S8(); virtual void S9();
    virtual void S10(); virtual void S11(); virtual void S12(); virtual void S13(); virtual void S14();
    virtual void S15(); virtual void S16(); virtual void S17(); virtual void S18(); virtual void S19();
    virtual void S20(); virtual void S21(); virtual void S22(); virtual void S23(); virtual void S24();
    virtual void S25(); virtual void S26(); virtual void S27(); virtual void S28(); virtual void S29();
    virtual void S30(); virtual void S31(); virtual void S32(); virtual void S33(); virtual void S34();
    virtual void S35();
    virtual int State();                                        // +0x120
    virtual int Execute(class Unk_SkillCommand& command);       // +0x128
    virtual void S38(); virtual void S39();
    virtual bool HasMeret(unsigned nAmount);                    // +0x140
    virtual bool HasMoney(unsigned nAmount);                    // +0x148
    virtual void S42();
    virtual void Notify(int nA, int nB, int nC);                // +0x158
};
Unk_SkillService* FUN_140d86260();

JobSystemCli* FUN_1416546d0(MyPC* pPlayer);                                 // the job system of a PC
int FUN_141654730(MyPC* pPlayer);                                           // the sub job
int FUN_141654760(MyPC* pPlayer);                                           // the job rank
// @0x140ed47e0
int FUN_140ed47e0(MyPC* pPlayer)                                            // the character level (m_n179c)
{
    return pPlayer->m_n179c;
}
char* FUN_1401d3200();                                                      // the settings table
const wchar_t* FUN_1402056b0(const char* pSetting);                         // text of a setting
unsigned* FUN_1401d7c10(const char* pSetting);                              // value of a setting
CStringW FUN_1409eec40(int nId);                                            // common string text
CStringW FUN_140a228f0(int nId, const wchar_t* sz, const CStringW& str);   // format a text
void FUN_1412751f0(const CStringW& strText, int nA, int nB);                // notice
void FUN_1412751b0(const CStringW& strText, int nType);                     // toast
void FUN_141276180(const CString& strSound, const CString& strOption);      // play a sound
void FUN_140a36d00(CString& strPrefix);                                     // clear the slot list of the movie
void FUN_140a36c30(CString& strPrefix, std::vector<JobSkillPtr>& skills);   // fill it
void FUN_141add1f0(void* pManager);                                         // open the shop
void* FUN_1403ed2b0();                                                      // the UI manager (Unk_SkillUIManager)
void* FUN_1409331f0();                                                      // the shortcut manager
int FUN_140a700b0(void* pManager);                                          // its current page
void FUN_14092fac0(int nSkillId, int nA, int nB, int nPage);                // register a shortcut
void FUN_141276180(const CString& strSound, const CString& strOption);      // play a sound
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                                // show it
unsigned short FUN_1406438e0(JobSkillData* pData, unsigned short nLevel);

// The "m_buttonBar" tab bar and the point label of the movie.
class Unk_SkillButtonBar : public ASDisplayObject
{
public:
    void FUN_1422e3400();                                                   // remove all tabs
    void FUN_1422e31e0(int nIndex);                                         // select a tab
};
class Unk_SkillPointLabel : public ASMovieClip
{
public:
    void FUN_1422c2d10(SkillClickDelegate onClick, int nUserData);
};
class Unk_SkillScriptView : public AScript { public: MS2Ptr<Unk_SkillButtonBar> FUN_140be23c0(const CString& strName); };
class Unk_SkillPointHelper : public CPtred { public: void FUN_1422c6160(const Scaleform::GFx::Value& value); };
MS2Ptr<Unk_SkillPointHelper> FUN_1422c6240(int n);
class Unk_SkillBtn : public Unk_140acd6e0
{
public:
    void FUN_1422c1fe0(unsigned bEnabled);
};
// the three view classes of the movie children (vfunc 24 repaints)
class Unk_SkillPacketView : public UIDialog { public: void FUN_vfunc_79_base(CInPacket& packet); };

// The command the paid tab sends to the service (ctor 0x1401baa00, dtor 0x1401baaf0; 0x28 bytes).
class Unk_SkillCommand
{
public:
    Unk_SkillCommand(int nDialog);
    ~Unk_SkillCommand();
    void FUN_1401bac80(CString strName, CStringW strValue, int n);
    void FUN_1401badc0(bool b);
private:
    unsigned __int64 m_0, m_8, m_10, m_18, m_20;
};
class Unk_SkillWordFilter : public CPtred { public: int FUN_140226830(const CStringW& strText, CStringW& strMsg); };
class Unk_SkillFilterHost { public: MS2Ptr<Unk_SkillWordFilter> FUN_140229a50(); };
Unk_SkillFilterHost* FUN_14025e7d0();
class Unk_SkillCoupon : public CPtred {};
class Unk_SkillInventory { public: MS2Ptr<Unk_SkillCoupon> FUN_140a5e040(int nItemId); };
extern Unk_SkillInventory DAT_143ab2a90;
class Unk_SkillUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); void FUN_141adc750(int nClass); };
template <class T> T* Unk_SkillDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> sp = static_cast<Unk_SkillUIManager*>(FUN_1403ed2b0())->FUN_141adcea0(nId);
        if (sp.get())
            return dynamic_cast<T*>((UIObject*)sp);
    }
    return 0;
}

CStringW FUN_1418fe870(int nType, int* pnValue, int nFlag);                 // money text by pay type
__int64 FUN_140718370(const CStringW& str);                                 // the uid in the text
void FUN_1409b4bc0(Scaleform::GFx::Value* pOut, Scaleform::GFx::Value& v);  // pOut = v
char* FUN_141523ba0(MyPC* pPlayer);                                         // the quest data of a PC
int FUN_140745590(const char* pQuestLog, unsigned nQuestId);                // the quest is done

CString FUN_14071a5b0(const CString& strDir, const CString& strFile);       // Table/<file>
int FUN_1406363a0(Unk_140165cf0* pElem, const char* pszName, int* pnOut);   // job code attribute
int FUN_1406452a0(Unk_140165cf0* pElem, const char* pszName, int* pnOut);   // sub job code attribute
int FUN_140873b30(Unk_140165cf0* pElem, const char* pszName, CStringW* pstrOut);   // wide string attribute
void FUN_14028fd90(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr1, const char* pszAttr2,
                   std::vector<Unk_140165cf0*>* pOut);
CStringW FUN_14052bd00(int nId, const CStringW& str);

// ---- construction ----

// @0x140ec4e50
UISkillBookTreeDialog::UISkillBookTreeDialog()
    : m_strSlotPrefix("skillTreeSlot"), m_simulators(17, 0.75f, 0.25f, 2.25f, 10), m_spSimulator(0), m_tabs(10),
      m_slotOrder(17, 0.75f, 0.25f, 2.25f, 10), m_nMaxTabs(1), m_nTabId(0), m_nShownTabId(0), m_nJobLevel(0), m_spCache(0),
      m_autoDistribute(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_spButtonBar = 0;
    m_spAddButton = 0;
    m_n290 = 0;
    m_nWaitServer = 0;
    m_88 = 1;
    FUN_141924170(1);
    LoadAutoDistribute();
}

// @0x140ec50b0
UISkillBookTreeDialog::~UISkillBookTreeDialog()
{
}

// @0x140ec51c0
CString UISkillBookTreeDialog::GetTypeName()
{
    if (FUN_140166410()->FUN_14036d570(0xca))
        return "SkillBookTreeDialog_jobchange01";
    return "SkillBookTreeDialog";
}

// @0x140ec5250
bool UISkillBookTreeDialog::vfunc_84()
{
    if (vfunc_55() != 0)
        return false;
    return true;
}

// @0x140ec5290
int UISkillBookTreeDialog::vfunc_oa0_1()
{
    if (vfunc_55() != 0)
        return 0;
    return 1;
}

// @0x140ec52e0
int UISkillBookTreeDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}

// @0x140ec5340
void UISkillBookTreeDialog::vfunc_67()
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
        FUN_1416546d0(pPlayer)->RequestReset();
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    FUN_140a36d00(m_strSlotPrefix);
    Unk_SkillNotify* pNotify = FUN_140938cd0(0x4e5d);
    if (pNotify != 0)
        pNotify->FUN_141ac18e0(false);
    m_n290 = 0;
    m_nWaitServer = 0;
    m_nShownTabId = 0;
    m_nMaxTabs = 1;
    m_simulators.RemoveAll();
    m_spSimulator = 0;
    UIDialog::vfunc_67();
}

// @0x140ec5460
int UISkillBookTreeDialog::vfunc_73()
{
    return UIDialog::vfunc_73();
}

// @0x140ec5480
void UISkillBookTreeDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    if ((m_spCache.get() ? true : false) && FUN_1401d1320(m_spCache.get()))
        LoadAutoDistribute();
    Unk_SkillNotify* pNotify = FUN_140938cd0(0x4e5d);
    if (pNotify != 0)
        pNotify->FUN_141ac18e0(true);
}

// @0x140ec5520
void UISkillBookTreeDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_spButtonBar = 0;
    m_spAddButton = 0;
}

// ---- the window's state ----

// @0x140ecb130
int UISkillBookTreeDialog::GetJobSkillPoint(int nJobLevel)
{
    std::map<int, long> points = DAT_143ab32e8[nJobLevel];
    return points[m_nJobLevel];
}

// @0x140ecf2d0
MS2Ptr<CSkillBookTreeTabConfig> UISkillBookTreeDialog::FindTab(__int64 nTabId)
{
    for (POSITION pos = m_tabs.GetHeadPosition(); pos != 0; m_tabs.GetNext(pos))
    {
        MS2Ptr<CSkillBookTreeTabConfig> spTab = m_tabs.GetAt(pos);
        if (spTab->m_nId == nTabId)
            return spTab;
    }
    return 0;
}

// @0x140ecf5f0
BOOL UISkillBookTreeDialog::IsCurrentTab(__int64 nTabId)
{
    return m_nTabId == nTabId;
}

// @0x140ecf1c0
void UISkillBookTreeDialog::SelectTab(__int64 nTabId)
{
    MS2Ptr<CSkillBookTreeTabConfig> spTab = FindTab(nTabId);
    if (spTab == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    MS2Ptr<CSkillPointSimulator> spSim(0);
    if (!m_simulators.Lookup(nTabId, spSim))
        return;
    m_spSimulator = spSim;
    m_nShownTabId = nTabId;
}

// @0x140ec8ad0
MS2Ptr<CSkillPointSimulator> UISkillBookTreeDialog::GetSimulator()
{
    return m_spSimulator;
}

// @0x140ecce40
bool UISkillBookTreeDialog::HasPendingChanges()
{
    if (m_spSimulator == 0)
        return false;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (IsCurrentTab(m_nShownTabId) == 0)
        return m_spSimulator->GetSpentPoints(m_nJobLevel) != 0;
    if (FUN_1416546d0(pPlayer)->GetTotalPoint() == 0 && m_spSimulator->GetSpentPoints(m_nJobLevel) == 0)
        return false;
    return true;
}

// @0x140ecd4b0
int UISkillBookTreeDialog::CanApply()
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (pPlayer->vfunc_65() != 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_msg_skillbook_set_disable_battle"), 0, 0, L"");
        return 0;
    }
    MS2Ptr<Unk_SkillField> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0)
        return 0;
    if (spField->FUN_140375660(0x10) != 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_msg_skillbook_set_disable_field"), 0, 0, L"");
        return 0;
    }
    return 1;
}

// @0x140ecd6d0
int UISkillBookTreeDialog::CheckApply(bool bNotify)
{
    if (FUN_140d86260()->State() == 1)
    {
        if (bNotify == true)
            FUN_140d73aa0(FUN_140a228f0(0x688, FUN_1402056b0(FUN_1401d3200() + 0x6aa8), FUN_1409eec40(0x5c0)), 0, 0, L"");
        return 1;
    }
    return 0;
}

// ---- the movie ----

// @0x140ece840
void UISkillBookTreeDialog::PlayChangeEffect(int nSkillId)
{
    if (m_30 == 0)
        return;
    m_30->Invoke("playChangeEffect", (unsigned int)nSkillId);
}

// @0x140ecc850
void UISkillBookTreeDialog::UpdateSubJobLevel()
{
    m_30->Invoke("SetSelectedSubJobLevel", m_nJobLevel - 1);
}

// @0x140ecb540
void UISkillBookTreeDialog::RefreshJob()
{
    if (m_30 == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    RefreshJobSkills(pPlayer->FUN_141654700());
    RefreshRemainPoint();
    RefreshPoints();
}

// @0x140ecb5c0
void UISkillBookTreeDialog::RefreshTabButtons(int bKeepSelection)
{
    if (m_tabs.IsEmpty() || m_spButtonBar == 0)
        return;
    m_spButtonBar->FUN_1422e3400();
    int nSelected = 0;
    int nIndex = 0;
    for (POSITION pos = m_tabs.GetHeadPosition(); pos != 0; m_tabs.GetNext(pos))
    {
        MS2Ptr<CSkillBookTreeTabConfig> spTab = m_tabs.GetAt(pos);
        CStringW strId = StringFormat(L"{0}", spTab->m_nId);
        m_30->Invoke("AddTab", CStringW(spTab->m_strName), CStringW(strId), 0);
        if (spTab->m_nId == m_nTabId)
            nSelected = nIndex;
        nIndex++;
    }
    if (bKeepSelection == 0)
        m_spButtonBar->FUN_1422e31e0(nSelected);
}

// @0x140ec8220
void UISkillBookTreeDialog::RefreshSlotsIfShown()
{
    if (m_30 == 0 || vfunc_9() == 0)
        return;
    RefreshSlots(1);
    m_nWaitServer = 0;
}

// @0x140ec91c0
void UISkillBookTreeDialog::RegisterShortcut(int nSkillId)
{
    FUN_14092fac0(nSkillId, 0, 0, FUN_140a700b0(FUN_1409331f0()));
}

// @0x140ec9130
bool UISkillBookTreeDialog::AddPaidTab(CStringW strName)
{
    SelectTab(AddTab(strName, 1));
    RequestTree(m_nShownTabId, 0, 0);
    RefreshTabButtons(1);
    RefreshSlots(0);
    return true;
}

// @0x140ecb1a0
void UISkillBookTreeDialog::RenameTab(__int64 nTabId, CStringW strName)
{
    MS2Ptr<CSkillBookTreeTabConfig> spTab = FindTab(nTabId);
    if (!spTab)
        return;
    spTab->m_strName = strName;
    if (m_30.get() != 0)
        m_30->Invoke("renameTab", (unsigned __int64)nTabId, CStringW(strName));
    RequestTree(nTabId, 0, 0);
}

// @0x140ecb300
void UISkillBookTreeDialog::RefreshSlots(int bKeep)
{
    if (m_30 == 0)
        return;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0 || m_spSimulator == 0)
        return;
    if (bKeep == 0)
    {
        std::vector<JobSkillPtr> skills;
        m_spSimulator->GetMerged(skills, 0);
        FUN_140a36d00(m_strSlotPrefix);
        FUN_140a36c30(m_strSlotPrefix, skills);
        m_slotOrder.RemoveAll();
        int nIndex = 0;
        for (std::vector<JobSkillPtr>::iterator it = skills.begin(); it != skills.end(); ++it)
        {
            m_slotOrder.SetAt((*it)->GetID(), nIndex);
            nIndex++;
        }
    }
    RefreshJob();
    if (bKeep == 0)
        RefreshAll();
    else
        RefreshTree();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        reinterpret_cast<Unk_ASDialogSlots*>(pDialog)->Invalidate(true);
}

// ---- tabs ----

// @0x140ece8b0
__int64 UISkillBookTreeDialog::AddTab(const CStringW& strName, int bFree)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CSkillBookTreeTabConfig> spTab(new CSkillBookTreeTabConfig);
    spTab->m_strName = strName;
    std::vector<JobSkillPtr> skills;
    FUN_1416546d0(pPlayer)->GetSkills(skills, 0, true);
    MS2Ptr<CSkillPointSimulator> spSim(new CSkillPointSimulator);
    spSim->Reset(pPlayer->vfunc_78(), FUN_141654730(pPlayer), skills, DAT_143ab32f8, FUN_140ed47e0(pPlayer));
    if (bFree != 0)
        spSim->ResetRank(0);
    ATL::CAtlArray<unsigned> ids;
    ATL::CAtlArray<unsigned> points;
    spSim->GetUsedPoints(ids, points, 0);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        unsigned nSkill = ids[i];
        unsigned nPoint = points[i];
        spTab->m_slots.SetAt(nSkill, nPoint);
    }
    m_simulators.SetAt(spTab->m_nId, spSim);
    m_tabs.AddTail(spTab);
    return spTab->m_nId;
}

// @0x140ecec20
void UISkillBookTreeDialog::LoadTab(MS2Ptr<CSkillBookTreeTabConfig> spTab)
{
    if (spTab == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    std::vector<JobSkillPtr> skills;
    FUN_1416546d0(pPlayer)->GetSkills(skills, 0, true);
    MS2Ptr<CSkillPointSimulator> spSim(new CSkillPointSimulator);
    spSim->Reset(pPlayer->vfunc_78(), FUN_141654730(pPlayer), skills, DAT_143ab32f8, FUN_140ed47e0(pPlayer));
    ATL::CAtlArray<unsigned> ids;
    ATL::CAtlArray<unsigned> points;
    for (POSITION pos = spTab->m_slots.GetStartPosition(); pos != 0; spTab->m_slots.GetNext(pos))
    {
        unsigned nSkill = spTab->m_slots.GetKeyAt(pos);
        unsigned nPoint = spTab->m_slots.GetValueAt(pos);
        ids.Add(nSkill);
        points.Add(nPoint);
    }
    spSim->AutoDistribute(ids, points);
    spSim->Commit(0);
    m_simulators.SetAt(spTab->m_nId, spSim);
}

// @0x140ecef10
void UISkillBookTreeDialog::RefreshTabs(__int64 nTabId)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    MS2Ptr<CSkillBookTreeTabConfig> spTab = FindTab(nTabId);
    if (spTab == 0)
        return;
    MS2Ptr<CSkillPointSimulator> spSim(0);
    if (!m_simulators.Lookup(spTab->m_nId, spSim))
        return;
    spTab->m_slots.RemoveAll();
    std::vector<JobSkillPtr> skills;
    FUN_1416546d0(pPlayer)->GetSkills(skills, 0, true);
    spSim->Reset(pPlayer->vfunc_78(), FUN_141654730(pPlayer), skills, DAT_143ab32f8, FUN_140ed47e0(pPlayer));
    ATL::CAtlArray<unsigned> ids;
    ATL::CAtlArray<unsigned> points;
    spSim->GetUsedPoints(ids, points, 0);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        unsigned nSkill = ids[i];
        unsigned nPoint = points[i];
        spTab->m_slots.SetAt(nSkill, nPoint);
    }
}

// @0x140ecf3d0
void UISkillBookTreeDialog::PromptAddTab()
{
    if (MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(10, GetStringCommonByKey(L"s_skillbook_tree_config_add_tab"), 0, L""))
    {
        CStringW strText;
        spBox->FUN_141a01d30(0, strText, 10, 0, 0);
        spBox->FUN_141a027c0(SkillBoxDelegate(this, &UISkillBookTreeDialog::OnAddTabConfirm));
        FUN_140d73c60(spBox);
    }
}

// ---- status events ----

// @0x140ec7750
void UISkillBookTreeDialog::vfunc_oa0_7(int a1, CStringW s)
{
    vfunc_67();
}

// @0x140ec76d0
void UISkillBookTreeDialog::vfunc_oa0_9(unsigned short nLevel)
{
    if (m_spSimulator == 0)
        return;
    m_spSimulator->SetLevel(nLevel);
    RefreshJob();
    RefreshTree();
}

// @0x140ec77b0
void UISkillBookTreeDialog::vfunc_oa0_28()
{
    if (m_spSimulator == 0)
        return;
    m_spSimulator->SetExtraPoints(DAT_143ab32f8);
    RefreshJob();
    RefreshTree();
}

// @0x140ec7830
void UISkillBookTreeDialog::vfunc_oa0_21()
{
    if (m_spSimulator == 0)
        return;
    RefreshJob();
    RefreshTree();
}

// @0x140ec7420
int UISkillBookTreeDialog::vfunc_71()
{
    BOOL bChanged = FALSE;
    for (POSITION pos = m_simulators.GetStartPosition(); pos != 0; m_simulators.GetNext(pos))
    {
        MS2Ptr<CSkillPointSimulator> spSim = m_simulators.GetValueAt(pos);
        if (spSim->IsChanged())
        {
            bChanged = TRUE;
            break;
        }
    }
    if (!bChanged)
        return 0;
    if (CheckApply(false) == 1)
    {
        vfunc_67();
        return 1;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommonByKey(L"s_msg_skillbook_close_apply_msg"), 0, L"");
    spBox->FUN_141a027c0(SkillBoxDelegate(this, &UISkillBookTreeDialog::OnCloseConfirm));
    FUN_140d73c60(spBox);
    return 1;
}

// ---- message box results ----

// @0x140eca7e0
bool UISkillBookTreeDialog::OnCloseConfirm(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        RequestTree(0, 0, 0);
        SelectTab(m_nTabId);
        RequestJob(0, 0, 0);
        FUN_1412751b0(GetStringCommonByKey(L"s_msg_skillbook_apply_skill"), 0x14);
    }
    FUN_14151f200();
    vfunc_67();
    return true;
}

// @0x140eca480
bool UISkillBookTreeDialog::OnResetConfirm(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        int nRank = 0;
        if (FUN_140166410()->FUN_14036d570(0xca))
        {
            int nArgs = box.FUN_141a02e50(0, 0);
        if (nArgs > 1)
            {
                bool bFirst = const_cast<CMsgBoxData&>(box).FUN_141a04aa0();
                bool bSecond = const_cast<CMsgBoxData&>(box).FUN_141a04c20();
                if (bFirst && bSecond)
                    nRank = 0;
                else if (bFirst)
                    nRank = 1;
                else if (bSecond)
                    nRank = 2;
            }
        }
        m_spSimulator->ResetRank(nRank);
        RequestTree(m_nShownTabId, 0, nRank);
        if (IsCurrentTab(m_nShownTabId) == 0)
        {
            RefreshSlots(1);
        }
        else
        {
            COutPacket packet(static_cast<int>(SendOp::Job), 0);
            packet.Encode1(10);
            packet.Encode4(nRank);
            FUN_140710590(packet);
            m_nWaitServer = 1;
        }
        FUN_1412751b0(GetStringCommonByKey(L"s_msg_skillbook_reset_skill"), 0x14);
    }
    FUN_14151f200();
    return true;
}

// @0x140eca690
bool UISkillBookTreeDialog::OnApplyConfirm(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        int nRank = 0;
        int nArgs = box.FUN_141a02e50(0, 0);
        if (nArgs > 1)
        {
            bool bFirst = const_cast<CMsgBoxData&>(box).FUN_141a04aa0();
            bool bSecond = const_cast<CMsgBoxData&>(box).FUN_141a04c20();
            if (bFirst && bSecond)
                nRank = 0;
            else if (bFirst)
                nRank = 1;
            else if (bSecond)
                nRank = 2;
        }
        RequestTree(m_nShownTabId, 0, nRank);
        RequestJob(0, 0, nRank);
        FUN_1412751b0(GetStringCommonByKey(L"s_msg_skillbook_apply_skill"), 0x14);
    }
    FUN_14151f200();
    return true;
}

// @0x140eca8c0
bool UISkillBookTreeDialog::OnApplyTabConfirm(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        MS2Ptr<CSkillBookTreeTabConfig> spTab = FindTab(m_nShownTabId);
        if (!spTab)
            return false;
        m_nTabId = spTab->m_nId;
        RequestTree(0, 1, 0);
        RequestJob(0, 1, 0);
        FUN_1412751f0(FUN_1405c2690(GetStringCommonByKey(L"s_skillbook_tree_config_apply_tab"), spTab->m_strName), 1, 1);
    }
    FUN_14151f200();
    return true;
}

// @0x140ec8b20
bool UISkillBookTreeDialog::OnRenameConfirm(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        CStringW strName = box.FUN_141a02d50();
        strName = strName.Mid(strName.Find(L',', 0) + 1);
        __int64 nTabId = 0;
        box.FUN_140b19130(0, nTabId);
        if (strName.IsEmpty())
            return false;
        if (MS2Ptr<Unk_SkillWordFilter> spFilter = FUN_14025e7d0()->FUN_140229a50())
        {
            CStringW strMsg;
            if (spFilter->FUN_140226830(strName, strMsg) != 0)
            {
                FUN_1412751f0(strMsg, 1, 1);
                return false;
            }
        }
        COutPacket packet(static_cast<int>(SendOp::RequestSkillBookTree), 0);
        packet.Encode1(2);
        packet.Encode8(nTabId);
        packet.vfunc_o10_8(strName);
        FUN_140710590(packet);
        FUN_14151f200();
        return true;
    }
    return true;
}

// @0x140ec8d30
bool UISkillBookTreeDialog::OnAddTabConfirm(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        if ((unsigned)m_nMaxTabs <= m_tabs.GetCount())
            return false;
        CStringW strName = box.FUN_141a02d50();
        strName = strName.Mid(strName.Find(L',', 0) + 1);
        if (strName.IsEmpty())
            return false;
        Unk_SkillCommand command(0x4f2d);
        command.FUN_1401bac80("AddTab", CStringW(strName), 0);
        command.FUN_1401badc0(true);
        if (FUN_140d86260()->Execute(command) == 1)
            return AddPaidTab(CStringW(strName));
    }
    return true;
}

// @0x140ec8f60
bool UISkillBookTreeDialog::OnAddTabPayConfirm(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        if (m_tabs.GetCount() > 2)
            return false;
        bool bCoupon = const_cast<CMsgBoxData&>(box).FUN_141a04aa0();
        bool bHasCoupon = false;
        if (bCoupon)
        {
            MS2Ptr<Unk_SkillCoupon> spCoupon = DAT_143ab2a90.FUN_140a5e040(0x76);
            bHasCoupon = spCoupon.get() != 0;
        }
        unsigned nPrice = *FUN_1401d7c10(FUN_1401d3200() + 0x8bb8);
        bool bEnough = false;
        if (FUN_140d86260()->HasMoney(nPrice) == true)
            bEnough = true;
        else if (FUN_140d86260()->HasMeret(nPrice) == true)
            bEnough = true;
        if (!bHasCoupon && !bEnough)
        {
            FUN_141add1f0(FUN_1403ed2b0());
            return true;
        }
        COutPacket packet(static_cast<int>(SendOp::RequestSkillBookTree), 0);
        packet.Encode1(4);
        packet.Encode4(0x4f2d);
        packet.vfunc_o10_0(bCoupon);
        FUN_140710590(packet);
        m_nWaitServer = 1;
    }
    return true;
}

// @0x140ec9c20
void UISkillBookTreeDialog::RequestTree(__int64 nTabId, int bKeep, int nRank)
{
    if (bKeep == 0)
    {
        for (POSITION pos = m_tabs.GetHeadPosition(); pos != 0; m_tabs.GetNext(pos))
        {
            MS2Ptr<CSkillBookTreeTabConfig> spTab = m_tabs.GetAt(pos);
            if (spTab == 0)
                continue;
            if (nTabId != 0 && spTab->m_nId != nTabId)
                continue;
            MS2Ptr<CSkillPointSimulator> spSim(0);
            if (!m_simulators.Lookup(spTab->m_nId, spSim))
                continue;
            spTab->m_slots.RemoveAll();
            ATL::CAtlArray<unsigned> ids;
            ATL::CAtlArray<unsigned> points;
            spSim->GetUsedPoints(ids, points, nRank);
            for (size_t i = 0; i < ids.GetCount(); i++)
            {
                unsigned nSkill = ids[i];
                unsigned nPoint = points[i];
                spTab->m_slots.SetAt(nSkill, nPoint);
            }
        }
    }
    COutPacket packet(static_cast<int>(SendOp::RequestSkillBookTree), 0);
    packet.Encode1(1);
    packet.Encode8(m_nTabId);
    packet.Encode8(nTabId);
    packet.Encode4(nRank);
    packet.Encode4(m_tabs.GetCount());
    for (POSITION pos = m_tabs.GetHeadPosition(); pos != 0; m_tabs.GetNext(pos))
    {
        MS2Ptr<CSkillBookTreeTabConfig> spTab = m_tabs.GetAt(pos);
        if (spTab == 0)
            continue;
        spTab->Write(&packet);
    }
    FUN_140710590(packet);
}

// @0x140ec9fd0
void UISkillBookTreeDialog::PromptChangeTab()
{
    if (CanApply() == 0 || CheckApply(true) == 1)
        return;
    MS2Ptr<CSkillBookTreeTabConfig> spTab = FindTab(m_nShownTabId);
    if (spTab == 0)
        return;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_1405c2690(GetStringCommonByKey(L"s_skillbook_tree_config_change_tab"), spTab->m_strName), 0, L"");
    spBox->FUN_141a027c0(SkillBoxDelegate(this, &UISkillBookTreeDialog::OnApplyTabConfirm));
    FUN_140d73c60(spBox);
}

// @0x140ec9200
void UISkillBookTreeDialog::RequestJob(int bConfirm, int bAll, int nRank)
{
    if (m_spSimulator == 0)
        return;
    if (CanApply() == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    unsigned nBadSkill = 0;
    if (m_spSimulator->Validate(&nBadSkill) == 0)
        return;
    if (IsCurrentTab(m_nShownTabId) == 0)
    {
        RequestTree(m_nShownTabId, nRank, 0);
        return;
    }
    std::vector<JobSkillPtr> skills;
    if (bAll == 0)
        m_spSimulator->GetMerged(skills, nRank);
    else
        m_spSimulator->GetSnapshot(skills, 0);
    COutPacket packet(static_cast<int>(SendOp::Job), 0);
    packet.Encode1(bConfirm == 0 ? 9 : 0xb);
    packet.Encode4(skills.size());
    for (std::vector<JobSkillPtr>::iterator it = skills.begin(); it != skills.end(); ++it)
    {
        packet.Encode4((*it)->GetID());
        packet.Encode2((*it)->m_nLevel);
        packet.vfunc_o10_0((*it)->m_bLearned);
    }
    FUN_140710590(packet);
    m_nWaitServer = 1;
    std::vector<JobSkillPtr> applied;
    if (bAll == 0)
    {
        m_spSimulator->GetChanged(applied, nRank);
        m_spSimulator->Commit(nRank);
    }
    for (std::vector<JobSkillPtr>::iterator it = applied.begin(); it != applied.end(); ++it)
        PlayChangeEffect((*it)->GetID());
    FUN_141276180("System_Skillbook_Skill_Fixed_01", "");
}

// @0x140ec9610
void UISkillBookTreeDialog::PromptReset()
{
    if (CanApply() == 0 || HasPendingChanges() == 0 || CheckApply(true) == 1)
        return;
    MS2Ptr<CMsgBoxData> spBox(0);
    if (!FUN_140166410()->FUN_14036d570(0xca))
    {
        spBox = FUN_140d73d20(1, GetStringCommonByKey(L"s_msg_skillbook_reset_desc"), 0, L"");
    }
    else
    {
        MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return;
        int nLevel = FUN_1401d7a50()->FUN_140644b80(FUN_141654730(pPlayer));
        if (nLevel < 1)
        {
            spBox = FUN_140d73d20(1, GetStringCommonByKey(L"s_msg_skillbook_reset_desc"), 0, L"");
        }
        else
        {
            spBox = FUN_140d73d20(0x19, GetStringCommonByKey(L"s_msg_skillbook_reset_desc"), 0, L"");
            spBox->FUN_141a01800(1);
            spBox->FUN_141a026f0(1);
            spBox->FUN_141a024e0(GetStringCommonByKey(L"s_msg_skillbook_skill_level_0"), m_nJobLevel == 1);
            spBox->FUN_141a02560(GetStringCommonByKey(L"s_msg_skillbook_skill_level_1"), m_nJobLevel == 2);
        }
        spBox->FUN_140533ff0(nLevel);
    }
    spBox->FUN_141a027c0(SkillBoxDelegate(this, &UISkillBookTreeDialog::OnResetConfirm));
    FUN_140d73c60(spBox);
}

// @0x140ec8280
void UISkillBookTreeDialog::ApplyDistribute(unsigned int nIndex)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0 || m_spSimulator == 0)
        return;
    TPtrValue<AutoDistributeArray> spList(0);
    int nJob = pPlayer->FUN_141654700();
    if (!m_autoDistribute.Lookup(nJob, spList))
        return;
    AutoDistributeArray candidates;
    for (size_t i = 0; i < spList->GetCount(); i++)
    {
        MS2Ptr<AutoDistribute> spItem = spList->GetAt(i);
        if (spItem->m_nSubJob == 0 || spItem->m_nSubJob == FUN_141654730(pPlayer))
            candidates.Add(spItem);
    }
    if (nIndex >= candidates.GetCount())
        return;
    MS2Ptr<AutoDistribute> spPick = candidates[nIndex];
    if (!spPick)
        return;
    ATL::CAtlArray<unsigned> ids;
    ids.Copy(spPick->m_skillIds);
    ATL::CAtlArray<unsigned> points;
    points.Copy(spPick->m_skillPoints);
    if (m_spSimulator->AutoDistribute(ids, points) == 0)
        return;
    if (IsCurrentTab(m_nShownTabId) == 0)
    {
        RequestTree(m_nShownTabId, 0, 0);
        RefreshSlots(1);
        FUN_141276180("System_Skillbook_Skill_Fixed_01", "");
    }
    else
    {
        RequestTree(m_nShownTabId, 0, 0);
        RequestJob(1, 0, 0);
    }
    FUN_1412751b0(GetStringCommonByKey(L"s_msg_skillbook_auto_distribute_skill"), 0x14);
}

// @0x140eca230
void UISkillBookTreeDialog::ApplyAutoDistribute()
{
    if (CanApply() == 0 || CheckApply(true) == 1)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    TPtrValue<AutoDistributeArray> spList(0);
    int nJob = pPlayer->FUN_141654700();
    if (!m_autoDistribute.Lookup(nJob, spList))
        return;
    if (spList->IsEmpty())
        return;
    UISkillBookAutoDistributeDialog* pDialog = Unk_SkillDialog<UISkillBookAutoDistributeDialog>(0x4f20);
    if (pDialog != 0)
    {
        if (pDialog->vfunc_55() != 0)
        {
            pDialog->m_names.RemoveAll();
            for (size_t i = 0; i < spList->GetCount(); i++)
            {
                MS2Ptr<AutoDistribute> spItem = spList->GetAt(i);
                if (spItem->m_nSubJob == 0 || spItem->m_nSubJob == FUN_141654730(pPlayer))
                {
                    pDialog->m_names.Add(spItem->m_strName);
                    pDialog->m_tooltips.Add(spItem->m_strTooltip);
                }
            }
        }
        pDialog->FUN_1419246f0();
    }
}

// ---- skill point controls ----

// @0x140ecaa30
void UISkillBookTreeDialog::SkillPointUp(int nSkillId)
{
    if (m_spSimulator == 0)
        return;
    m_spSimulator->LevelUp(nSkillId);
    RefreshTree();
    PlayChangeEffect(nSkillId);
    RefreshJob();
}

// @0x140ecaab0
void UISkillBookTreeDialog::SkillPointDown(int nSkillId)
{
    if (m_spSimulator == 0)
        return;
    unsigned nBadSkill = 0;
    if (m_spSimulator->LevelDown(nSkillId, &nBadSkill) == 0)
    {
        FUN_1412751f0(FUN_1405c2690(GetStringCommonByKey(L"s_msg_skillbook_require_learn_skill"), FUN_1401a9d70()->FUN_141811980(4, nBadSkill)), 1, 1);
    }
    else
    {
        RefreshTree();
        PlayChangeEffect(nSkillId);
        RefreshJob();
    }
}

// @0x140ecac10
void UISkillBookTreeDialog::RequireSkillEffect(int nSkillId, int bFlag)
{
    if (m_30 == 0 || m_spSimulator == 0)
        return;
    JobSkillPtr spSkill = m_spSimulator->GetEditSkill(nSkillId);
    if (!spSkill)
        return;
    if (spSkill->m_bLearned)
        return;
    if (m_spSimulator->CanLevelUp(nSkillId) != 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    JobDataPtr spJob = FUN_1416546d0(pPlayer)->GetJobData();
    if (!spJob)
        return;
    JobSkillDataPtr spData = spJob->FindSkill(spSkill->GetID());
    if (!spData)
        return;
    MS2Ptr<SkillLevelData> spLevel = FUN_1401958b0()->FUN_1407ee2f0(spSkill->GetID(), spSkill->m_nLevel);
    if (!spLevel)
        return;
    ATL::CAtlArray<unsigned>& requireIds = spData->m_requireSkillIDs;
    ATL::CAtlArray<unsigned short>& requireLevels = spData->m_requireSkillLevels;
    for (size_t i = 0; i < requireIds.GetCount(); i++)
    {
        JobSkillPtr spRequire = m_spSimulator->GetEditSkill(requireIds[i]);
        if (!spRequire)
            continue;
        if (!spRequire->m_bLearned || spRequire->m_nLevel < requireLevels[i])
        {
            CStringW strText = FUN_14028dfa0(CStringW(L"s_mag_skillbook_skillslot_require_level"), requireLevels[i]);
            m_30->Invoke("requireSkillEffect", (int)spRequire->GetID(), bFlag, CStringW(strText));
        }
    }
}

// ---- tooltips and labels ----

// @0x140ec8720
void UISkillBookTreeDialog::OnPointClick(const Scaleform::GFx::FunctionHandler::Params& params)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    unsigned nBase = JobSystem::GetLevelSkillPoint(pPlayer->vfunc_78(), m_nJobLevel);
    unsigned nExtra = DAT_143ab32f8[m_nJobLevel];
    CStringW strText;
    if (!FUN_140166410()->FUN_14036d570(0xca))
    {
        unsigned nTotal = nBase + nExtra;
        unsigned nSecond = GetJobSkillPoint(2);
        unsigned nFirst = GetJobSkillPoint(1);
        nTotal += FUN_140ed47e0(pPlayer);
        strText = FUN_14028dfa0(CStringW(L"s_msg_skillbook_skillpoint_tooltip"), nTotal, nBase, nSecond, nFirst);
    }
    else
    {
        unsigned short nLimit = *(unsigned short*)(FUN_1401d3200() + 0x9718);
        if (m_nJobLevel == 2)
            nLimit = *(unsigned short*)(FUN_1401d3200() + 0x971a);
        unsigned nFirst = GetJobSkillPoint(1);
        unsigned nSecond = GetJobSkillPoint(2);
        unsigned nTotal = nBase + nExtra;
        nTotal += FUN_140ed47e0(pPlayer);
        strText = FUN_14028dfa0(CStringW(L"s_msg_skillbook_skillpoint_tooltip_jobchange"), nTotal, nBase, nSecond, nFirst, nLimit);
    }
    ASTooltip tooltip(pPlayer, 1, 2);
    tooltip.FUN_1409c6d70("export_common_tooltip_tooltipText");
    tooltip.FUN_1409c6dc0(4);
    tooltip.FUN_1409c6cb0(strText);
    FUN_1409b4bc0(params.pRetVal, tooltip.FUN_1422bb870());
}

// @0x140ecc030
void UISkillBookTreeDialog::RefreshRemainPoint()
{
    if (m_30 == 0 || m_spSimulator == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    int nRemain = m_spSimulator->GetRemainPoints(m_nJobLevel);
    int nTotal = pPlayer->FUN_14152e970(m_nJobLevel);
    m_30->FUN_140ed0fd0("setRemainSkillPoint", nRemain, nTotal != nRemain);
    if (MS2Ptr<ASMovieClip> spPoint = static_cast<Unk_SkillDlgView*>(static_cast<UIDialog*>(this))->FUN_140ba7930("m_point"))
    {
        static_cast<Unk_SkillPointLabel*>(spPoint.operator->())->FUN_1422c2d10(SkillClickDelegate(this, &UISkillBookTreeDialog::OnPointClick), 0);
        FUN_1422c6240(2)->FUN_1422c6160(spPoint->FUN_1422bb870());
    }
}

// @0x140ecc2e0
void UISkillBookTreeDialog::RefreshPoints()
{
    Unk_SkillDlgView* pView = static_cast<Unk_SkillDlgView*>(static_cast<UIDialog*>(this));
    MS2Ptr<Unk_140acd6e0> spApply = pView->FUN_140bb4b10("m_applySkill");
    if (spApply.get() != 0)
    {
        unsigned bChanged = 0;
        if (m_spSimulator.get() != 0)
            bChanged = m_spSimulator->IsChanged();
        static_cast<Unk_SkillBtn*>(spApply.operator->())->FUN_1422c1fe0(bChanged);
        reinterpret_cast<Unk_ASDialogSlots*>(spApply.operator->())->Invalidate(true);
    }
    MS2Ptr<Unk_140acd6e0> spReset = pView->FUN_140bb4b10("m_skillReset");
    if (spReset.get() != 0)
    {
        unsigned bPending = HasPendingChanges();
        static_cast<Unk_SkillBtn*>(spReset.operator->())->FUN_1422c1fe0(bPending);
        reinterpret_cast<Unk_ASDialogSlots*>(spReset.operator->())->Invalidate(true);
    }
    MS2Ptr<CSkillBookTreeTabConfig> spTab = FindTab(m_nShownTabId);
    if (spTab.get() != 0)
    {
        bool bCurrent = spTab->m_nId == m_nTabId;
        MS2Ptr<Unk_140acd6e0> spUse = pView->FUN_140bb4b10("m_useCurrentTab");
        if (spUse.get() != 0)
        {
            bool bNotCurrent = !bCurrent;
            spUse->vfunc_4(bNotCurrent);
            reinterpret_cast<Unk_ASDialogSlots*>(spUse.operator->())->Invalidate(true);
        }
        MS2Ptr<Unk_140acd6e0> spCurrent = pView->FUN_140bb4b10("m_currentTab");
        if (spCurrent.get() != 0)
        {
            static_cast<Unk_SkillBtn*>(spCurrent.operator->())->FUN_1422c1fe0(0);
            spCurrent->vfunc_3(bCurrent);
            reinterpret_cast<Unk_ASDialogSlots*>(spCurrent.operator->())->Invalidate(true);
        }
    }
    MS2Ptr<Unk_140acd6e0> spDistribute = pView->FUN_140bb4b10("m_autoDistribute");
    if (spDistribute.get() != 0)
    {
        int nPoints = m_spSimulator->GetTotalPoints(m_nJobLevel);
        static_cast<Unk_SkillBtn*>(spDistribute.operator->())->FUN_1422c1fe0(nPoints != 0);
        reinterpret_cast<Unk_ASDialogSlots*>(spDistribute.operator->())->Invalidate(true);
    }
}

// @0x140ecb820
void UISkillBookTreeDialog::RefreshJobSkills(int nJobCode)
{
    Unk_SkillDlgView* pView = static_cast<Unk_SkillDlgView*>(static_cast<UIDialog*>(this));
    if (!FUN_140166410()->FUN_14036d570(0xca))
    {
        if (MS2Ptr<ASMovieClip> spSymbol = pView->FUN_140ba7930("m_jobSymbol"))
        {
            CString strFrame;
            strFrame.Format("_%d", nJobCode);
            spSymbol->vfunc_15(strFrame);
        }
    }
    else
    {
        if (MS2Ptr<ASMovieClip> spBody = pView->FUN_140ba7930("m_skillTreeBody"))
        {
            CString strJob = "job0";
            if (m_nJobLevel == 2)
                strJob = "job1";
            spBody->vfunc_15(strJob);
            if (MS2Ptr<ASMovieClip> spJob = spBody->FUN_1409b4560(strJob))
            {
                if (MS2Ptr<ASMovieClip> spSymbol = spJob->FUN_1409b4560("m_jobSymbol"))
                {
                    CString strFrame;
                    strFrame.Format("_%d", nJobCode);
                    spSymbol->vfunc_15(strFrame);
                }
            }
        }
        for (int i = 1; i < 3; i++)
        {
            CString strButton;
            if (i == 1)
                strButton = "m_subJobBtn0";
            else if (i == 2)
                strButton = "m_subJobBtn1";
            if (MS2Ptr<ASMovieClip> spButton = pView->FUN_140ba7930(strButton))
            {
                if (nJobCode == 1 && i > 0)
                    spButton->vfunc_3(0);
                else
                    spButton->vfunc_3(1);
                if (MS2Ptr<ASMovieClip> spOn = spButton->FUN_1409b4560("m_jobIconOn"))
                {
                    CString strFrame;
                    strFrame.Format("_%d", nJobCode);
                    spOn->vfunc_15(strFrame);
                }
                if (MS2Ptr<ASMovieClip> spOff = spButton->FUN_1409b4560("m_jobIconOff"))
                {
                    CString strFrame;
                    strFrame.Format("_%d", nJobCode);
                    spOff->vfunc_15(strFrame);
                }
            }
        }
        UpdateSubJobLevel();
    }
    if (MS2Ptr<ASMovieClip> spLine = pView->FUN_140ba7930("m_treeLine"))
    {
        spLine->vfunc_3(1);
        CString strFrame;
        strFrame.Format("_%d", nJobCode);
        if (!FUN_140166410()->FUN_14036d570(0xca))
            spLine->vfunc_15(strFrame);
        else if (m_nJobLevel == 2)
            spLine->vfunc_3(0);
        else
            spLine->vfunc_15(strFrame);
    }
}

// ---- the skill icons ----

// @0x140ecd7e0
bool UISkillBookTreeDialog::IsChangedSkill(MS2Ptr<JobSkill> spSkill)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    JobSkillPtr spCurrent = FUN_1416546d0(pPlayer)->FindSkill(spSkill->GetID());
    if (spCurrent == 0)
        return false;
    if (spCurrent->m_bLearned != spSkill->m_bLearned)
        return true;
    if (spCurrent->m_nLevel != spSkill->m_nLevel)
        return true;
    return false;
}

// @0x140ece040
bool UISkillBookTreeDialog::IsLearnable(MS2Ptr<JobSkill> spSkill)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (spSkill == 0)
        return false;
    bool bLearn = spSkill->m_bLearned;
    if (!bLearn)
    {
        unsigned nSkillId = spSkill->GetID();
        unsigned short nLevel = pPlayer->FUN_1409eee00()->FUN_14080baf0(nSkillId);
        if (nLevel > 0)
            bLearn = true;
    }
    return bLearn;
}

// @0x140ece160
bool UISkillBookTreeDialog::IsDisabled(MS2Ptr<JobSkill> spSkill)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (spSkill == 0)
        return true;
    bool bDisabled = m_spSimulator->CheckRequirements(spSkill->GetID(), spSkill->m_nLevel) == 0;
    if (bDisabled == true)
    {
        unsigned nSkillId = spSkill->GetID();
        unsigned short nLevel = pPlayer->FUN_1409eee00()->FUN_14080baf0(nSkillId);
        if (nLevel > 0)
            bDisabled = false;
    }
    return bDisabled;
}

// @0x140ecdd90
unsigned short UISkillBookTreeDialog::GetLevelValue(MS2Ptr<JobSkill> spSkill)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (!spSkill)
        return 0;
    if (!IsLearnable(spSkill))
        return spSkill->m_nLevel;
    MS2Ptr<SkillData> spData = FUN_1401958b0()->FUN_1407ee1d0(spSkill->GetID());
    if (!spData)
        return 0;
    unsigned short nBonus = pPlayer->FUN_1409eee00()->FUN_14080baf0(spSkill->GetID());
    unsigned nOwned = spSkill->m_bLearned ? spSkill->m_nLevel : 0;
    if (spData->GetMaxLevel() < nOwned + nBonus)
        return spData->GetMaxLevel();
    return (unsigned short)(nOwned + nBonus);
}

// @0x140ecd960
CStringW UISkillBookTreeDialog::GetLevelText(MS2Ptr<JobSkill> spSkill)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return static_cast<const wchar_t*>(NULL);
    unsigned short nLevel = GetLevelValue(spSkill);
    if (!IsLearnable(spSkill))
        nLevel = 0;
    MS2Ptr<SkillData> spData = FUN_1401958b0()->FUN_1407ee1d0(spSkill->GetID());
    if (spData == 0)
        return L"";
    unsigned short nTier = pPlayer->FUN_1409eee00()->FUN_14080baf0(spSkill->GetID());
    unsigned short nMax;
    if (!IsChangedSkill(spSkill))
    {
        if (nTier == 0)
        {
            nMax = spData->FUN_1407e9ac0();
            return FUN_14028dfa0(CStringW(L"s_mag_skillbook_job_and_level"), nLevel, nMax);
        }
        nMax = spData->FUN_1407e9ac0();
        return FUN_14028dfa0(CStringW(L"s_mag_skillbook_job_and_level_tier"), nLevel, nMax);
    }
    nMax = spData->FUN_1407e9ac0();
    return FUN_14028dfa0(CStringW(L"s_msg_skillbook_job_and_level_change"), nLevel, nMax);
}

// @0x140ece300
int UISkillBookTreeDialog::FillSkill(MS2Ptr<JobSkill> spSkill, ASObj& info)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (!spSkill)
        return 0;
    MS2Ptr<SkillData> spData = FUN_1401958b0()->FUN_1407ee1d0(spSkill->GetID());
    if (!spData)
        return 0;
    bool bLearn = IsLearnable(spSkill);
    bool bPassive = spData->FUN_1407e9de0();
    bool bChange = IsChangedSkill(spSkill);
    bool bDisable = IsDisabled(spSkill);
    if (spSkill->GetData() == 0)
        return 0;
    CPoint pos = spSkill->GetData()->m_uiPosition;
    bool bHighlight = false;
    if (!bDisable && spSkill->GetData()->m_uiHighlight)
        bHighlight = true;
    int nIndex = 0;
    m_slotOrder.Lookup(spSkill->GetID(), nIndex);
    info.FUN_1409c0d20("index", nIndex);
    info.FUN_1407cb9c0("x", pos.x);
    info.FUN_1407cb9c0("y", pos.y);
    info.FUN_1409c0d20("skillID", spSkill->GetID());
    info.FUN_1407cbbe0("passive", bPassive);
    info.FUN_1407cbbe0("newSkill", spSkill->m_bChanged);
    info.FUN_1407cbbe0("change", bChange);
    info.FUN_1407cbbe0("learn", bLearn);
    info.FUN_1407cbbe0("disable", bDisable);
    info.FUN_1407cbbe0("highlight", bHighlight);
    info.FUN_1407cbb20("currentLevel", GetLevelText(spSkill));
    info.FUN_1407cb9c0("canPrevLevel", m_spSimulator->CanLevelDown(spSkill->GetID()));
    info.FUN_1407cb9c0("canNextLevel", m_spSimulator->CanLevelUp(spSkill->GetID()));
    return 1;
}

// @0x140ecc8b0
void UISkillBookTreeDialog::RefreshAll()
{
    if (m_30 == 0 || m_spSimulator == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    m_30->Invoke("resetSkillTree");
    CSkillPointSimulator::SkillMap& skills = m_spSimulator->GetEditSkills();
    for (POSITION pos = skills.GetStartPosition(); pos != 0; skills.GetNext(pos))
    {
        JobSkillPtr spSkill = skills.GetValueAt(pos);
        if (spSkill->m_bExtra)
            continue;
        if (spSkill->GetJobLevel() != m_nJobLevel)
            continue;
        MS2Ptr<SkillData> spData = FUN_1401958b0()->FUN_1407ee1d0(spSkill->GetID());
        if (!spData)
            continue;
        ASObj info(2);
        if (FillSkill(spSkill, info) == 0)
            continue;
        m_30->FUN_140acd1f0("setSkill", info);
    }
}

// @0x140eccbb0
void UISkillBookTreeDialog::RefreshTree()
{
    if (m_30 == 0 || m_spSimulator == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    CSkillPointSimulator::SkillMap& skills = m_spSimulator->GetEditSkills();
    for (POSITION pos = skills.GetStartPosition(); pos != 0; skills.GetNext(pos))
    {
        JobSkillPtr spSkill = skills.GetValueAt(pos);
        if (spSkill->m_bExtra)
            continue;
        MS2Ptr<SkillData> spData = FUN_1401958b0()->FUN_1407ee1d0(spSkill->GetID());
        if (!spData)
            continue;
        ASObj info(2);
        if (FillSkill(spSkill, info) == 0)
            continue;
        m_30->FUN_140acd1f0("updateSkill", info);
    }
}

// ---- the requirements ----

// @0x140ecf630
bool UISkillBookTreeDialog::CanUpgrade(MS2Ptr<JobSkill> spSkill, int bCheck)
{
    if (!spSkill)
        return false;
    if (!spSkill->m_bLearned)
        return CanLearn(spSkill->GetID(), spSkill->m_nLevel, bCheck);
    if (!CanLevelUp(spSkill->GetID(), spSkill->m_nLevel, bCheck))
        return false;
    return true;
}

// @0x140ecf740
bool UISkillBookTreeDialog::CanLevelUp(int nSkillId, unsigned short nLevel, int bCheck)
{
    if (bCheck == 0)
        return false;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    MS2Ptr<SkillData> spData = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
    if (!spData)
        return false;
    if (spData->FUN_1407e9ac0() <= nLevel)
        return false;
    return CanReachLevel(nSkillId, nLevel + 1, bCheck);
}

// @0x140ecf840
bool UISkillBookTreeDialog::CanLearn(int nSkillId, unsigned short nLevel, int bCheck)
{
    if (nLevel >= 2)
        return false;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (!FUN_1416546d0(pPlayer)->vfunc_2(nSkillId))
        return CanReachLevel(nSkillId, nLevel, bCheck);
    return false;
}

// @0x140ecf8d0
bool UISkillBookTreeDialog::CanReachLevel(int nSkillId, unsigned short nLevel, int bCheck)
{
    if (bCheck == 0)
        return false;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    JobDataPtr spJob = FUN_1416546d0(pPlayer)->GetJobData();
    if (spJob == 0)
        return false;
    JobSkillDataPtr spData = spJob->FindSkill(nSkillId);
    if (spData == 0)
        return true;
    int nRequire = spData->GetRequireLevel(nLevel);
    if (pPlayer->vfunc_78() < nRequire)
        return false;
    JobSkillPtr spSkill = FUN_1416546d0(pPlayer)->FindSkill(nSkillId);
    if (spSkill == 0)
        return false;
    int nRank = spSkill->GetJobLevel();
    if (FUN_141654760(pPlayer) < nRank)
        return false;
    ATL::CAtlArray<unsigned>& requireIds = spData->m_requireSkillIDs;
    ATL::CAtlArray<unsigned short>& requireLevels = spData->m_requireSkillLevels;
    for (size_t i = 0; i < requireIds.GetCount(); i++)
    {
        if (!FUN_1416546d0(pPlayer)->vfunc_2(requireIds[i]))
            return false;
        int nHave = pPlayer->FUN_141528b80(requireIds[i]);
        if (nHave < requireLevels[i])
            return false;
    }
    if (spData->m_requireQuestID != 0)
    {
        if (FUN_140745590(FUN_141523ba0(pPlayer) + 0x10, spData->m_requireQuestID) == 0)
            return false;
    }
    return true;
}

// ---- the auto distribute table ----

// @0x140ed34a0
UISkillBookTreeDialog::AutoDistribute::AutoDistribute()
{
    m_nSubJob = 0;
}

// @0x140eccf50
void UISkillBookTreeDialog::LoadAutoDistribute()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("skillAutoDistribute.xml"));
    if (m_spCache == 0)
    {
        m_spCache.AssignRaw(new CCacheData);
        if (m_spCache.get() != 0)
            m_spCache->FUN_1401d1160(CString(strPath));
    }
    m_autoDistribute.RemoveAll();
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    for (Unk_140165cf0* pJob = pRoot->FUN_140165cf0("job"); pJob != 0; pJob = pJob->FUN_140168650("job"))
    {
        int nJob = 0;
        FUN_1406363a0(pJob, "code", &nJob);
        std::vector<Unk_140165cf0*> nodes;
        FUN_14028fd90(pJob, "type", "subJobCode", "name", &nodes);
        TPtrValue<AutoDistributeArray> spList(Unk_GrNewTag(0));
        for (size_t i = 0; i < nodes.size(); i++)
        {
            Unk_140165cf0* pNode = nodes[i];
            if (pNode != 0)
            {
                MS2Ptr<AutoDistribute> spItem(new AutoDistribute);
                FUN_140873b30(pNode, "name", &spItem->m_strName);
                FUN_140873b30(pNode, "tooltip", &spItem->m_strTooltip);
                FUN_1406452a0(pNode, "subJobCode", &spItem->m_nSubJob);
                for (Unk_140165cf0* pSkill = pNode->FUN_140165cf0("skill"); pSkill != 0; pSkill = pSkill->FUN_140168650("skill"))
                {
                    unsigned nId = 0;
                    unsigned nPoint = 0;
                    FUN_140873220(pSkill, "id", nId);
                    FUN_140873220(pSkill, "point", nPoint);
                    spItem->m_skillIds.Add(nId);
                    spItem->m_skillPoints.Add(nPoint);
                }
                spList->Add(spItem);
            }
        }
        m_autoDistribute.SetAt(nJob, spList);
    }
}

// ---- the movie ----

// @0x140ec5570
void UISkillBookTreeDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0)
    {
        m_spButtonBar = static_cast<Unk_SkillScriptView*>(m_30.operator->())->FUN_140be23c0("m_buttonBar");
        m_spAddButton = m_30->FUN_140acce30<Unk_140acd6e0>("m_addButton");
        m_30->FUN_140ed11b0("SetMaxTabCount", 3u);
    }
    FUN_1419260d0("m_webGuideButton", 0);
    if (FUN_140166410()->FUN_14036d570(0xca))
    {
        MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
            m_nJobLevel = FUN_1401d7a50()->FUN_140644b80(FUN_141654730(pPlayer));
    }
    vfunc_8(0);
    COutPacket packet(static_cast<int>(SendOp::RequestSkillBookTree), 0);
    packet.Encode1(0);
    FUN_140710590(packet);
    FUN_140d86260()->Notify(0xe, 0, 1000);
}

// @0x140ec7890
void UISkillBookTreeDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    CInPacket& packet = *static_cast<CInPacket*>(pPacket);
    if (packet.FUN_14070fe80() != 0x10c)
        return;
    int nMode = packet.vfunc_o8_1();
    if (nMode == 0)
    {
        m_tabs.RemoveAll();
        m_simulators.RemoveAll();
        m_nMaxTabs = packet.vfunc_o8_3();
        m_nTabId = packet.vfunc_o8_4();
        unsigned nCount = packet.vfunc_o8_3();
        for (unsigned i = 0; i < nCount; i++)
        {
            MS2Ptr<CSkillBookTreeTabConfig> spTab(new CSkillBookTreeTabConfig);
            spTab->Read(&packet);
            if (spTab->m_strName.IsEmpty())
            {
                unsigned nNo = m_tabs.GetCount() + 1;
                spTab->m_strName = FUN_14028dfa0(CStringW(L"s_skillbook_tree_config_default_tab_name"), nNo);
            }
            m_tabs.AddTail(spTab);
            LoadTab(spTab);
        }
        if (!m_tabs.IsEmpty())
        {
            MS2Ptr<CSkillBookTreeTabConfig> spTab = FindTab(m_nTabId);
            if (spTab == 0)
            {
                spTab = m_tabs.GetHead();
                if (spTab == 0)
                    return;
                m_nTabId = spTab->m_nId;
            }
        }
        else
        {
            int nNo = 1;
            __int64 nTabId = AddTab(FUN_14028dfa0(CStringW(L"s_skillbook_tree_config_default_tab_name"), nNo), 0);
            m_nTabId = nTabId;
            m_nShownTabId = nTabId;
        }
        SelectTab(m_nTabId);
        RefreshTabs(m_nTabId);
        RefreshTabButtons(0);
        RefreshSlots(0);
        if (vfunc_9() == 0)
            vfunc_8(1);
        m_n290 = 1;
    }
    else if (nMode == 4)
    {
        m_nMaxTabs = packet.vfunc_o8_3();
        FUN_1412751f0(GetStringCommonByKey(L"s_skillbook_tree_config_payment_sucess"), 1, 1);
        unsigned nNo = m_tabs.GetCount() + 1;
        AddPaidTab(FUN_14028dfa0(CStringW(L"s_skillbook_tree_config_default_tab_name"), nNo));
        m_nWaitServer = 0;
    }
    else if (nMode == 1)
    {
        m_nTabId = packet.vfunc_o8_4();
        __int64 nTabId = packet.vfunc_o8_4();
        int nRank = packet.vfunc_o8_3();
        MS2Ptr<CSkillPointSimulator> spSim(0);
        if (m_simulators.Lookup(nTabId, spSim))
        {
            spSim->Commit(nRank);
            RefreshPoints();
        }
    }
    else if (nMode == 2)
    {
        __int64 nTabId = packet.vfunc_o8_4();
        CStringW strName = packet.vfunc_o8_8();
        int nResult = packet.vfunc_o8_1();
        if (nResult == 0)
            RenameTab(nTabId, CStringW(strName));
        else
            FUN_140d73aa0(FUN_14052bd00(0x8b9, strName), 0, 0, L"");
    }
}

// @0x140ec5820
void UISkillBookTreeDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (m_30 == 0 || vfunc_9() == 0 || m_spSimulator == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (_stricmp("getTooltipFromSkillID", strMethod) == 0)
    {
        int nSkillId = pArgs->FUN_1422b8b10();
        JobSkillPtr spSkill = m_spSimulator->GetEditSkill(nSkillId);
        if (!spSkill)
            return;
        ASTooltip tooltip(pPlayer, 0x10, 2);
        unsigned short nLevel = GetLevelValue(spSkill);
        if (tooltip.FUN_1409e1c50(spSkill->GetID(), nLevel, 1) != 0)
            FUN_1409b4bc0(pRetVal, tooltip.FUN_1422bb870());
    }
    else if (_stricmp("getTooltipFromNextLevel", strMethod) == 0)
    {
        unsigned nSkillId = pArgs->FUN_1422b8b10();
        JobSkillPtr spSkill = m_spSimulator->GetEditSkill(nSkillId);
        if (!spSkill)
            return;
        MS2Ptr<SkillData> spData = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
        if (!spData)
            return;
        unsigned short nLevel = GetLevelValue(spSkill);
        if (nLevel < spData->FUN_1407e9ac0())
        {
            if (IsLearnable(spSkill))
                nLevel = nLevel + 1;
            ASTooltip tooltip(pPlayer, 0x10, 2);
            if (tooltip.FUN_1409e1c50(spSkill->GetID(), nLevel, 1) != 0)
            {
                tooltip.FUN_1409c6dc0(7);
                tooltip.FUN_1409c0dc0("enablePuton", "");
                FUN_1409b4bc0(pRetVal, tooltip.FUN_1422bb870());
            }
        }
    }
    else if (_stricmp("getTooltipFromPrevLevel", strMethod) == 0)
    {
        unsigned nSkillId = pArgs->FUN_1422b8b10();
        if (m_spSimulator->CanLevelDown(nSkillId) != 0)
        {
            JobSkillPtr spSkill = m_spSimulator->GetEditSkill(nSkillId);
            if (!spSkill)
                return;
            if (spSkill->m_nLevel != 1)
            {
                ASTooltip tooltip(pPlayer, 0x10, 2);
                unsigned short nPrev = spSkill->m_nLevel - 1;
                if (tooltip.FUN_1409e1c50(spSkill->GetID(), nPrev, 1) != 0)
                {
                    tooltip.FUN_1409c6dc0(7);
                    tooltip.FUN_1409c0dc0("enablePuton", "");
                    FUN_1409b4bc0(pRetVal, tooltip.FUN_1422bb870());
                }
            }
        }
    }
}

// @0x140ec5e20
int UISkillBookTreeDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (m_n290 == 0)
        return 0;
    ASData data;
    if (_stricmp("onApplySkill", szMethod) == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        if (CanApply() == 0)
            return 0;
        if (CheckApply(true) == 1)
            return 0;
        if (FUN_140166410()->FUN_14036d570(0xca))
        {
            MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPlayer == 0)
                return 0;
            MS2Ptr<CMsgBoxData> spBox(0);
            int nLevel = FUN_1401d7a50()->FUN_140644b80(FUN_141654730(pPlayer));
            if (nLevel > 1)
            {
                spBox = FUN_140d73d20(0x19, GetStringCommonByKey(L"s_msg_skillbook_apply_skill_joblevel"), 0, L"");
                spBox->FUN_141a01800(1);
                spBox->FUN_141a026f0(1);
                spBox->FUN_141a024e0(GetStringCommonByKey(L"s_msg_skillbook_skill_level_0"), m_nJobLevel == 1);
                spBox->FUN_141a02560(GetStringCommonByKey(L"s_msg_skillbook_skill_level_1"), m_nJobLevel == 2);
                spBox->FUN_140533ff0(nLevel);
                spBox->FUN_141a027c0(SkillBoxDelegate(this, &UISkillBookTreeDialog::OnApplyConfirm));
                FUN_140d73c60(spBox);
                return 1;
            }
        }
        RequestTree(m_nShownTabId, 0, 0);
        RequestJob(0, 0, 0);
        FUN_1412751b0(GetStringCommonByKey(L"s_msg_skillbook_apply_skill"), 0x14);
        return 1;
    }
    else if (_stricmp("onResetSkill", szMethod) == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        PromptReset();
        return 1;
    }
    else if (_stricmp("onUseTab", szMethod) == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        PromptChangeTab();
        return 1;
    }
    else if (_stricmp("onAutoDistribute", szMethod) == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        ApplyAutoDistribute();
        return 1;
    }
    else if (_stricmp("onSkillPointUp", szMethod) == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            SkillPointUp(data.FUN_1422b8b10());
            return 1;
        }
    }
    else if (_stricmp("onSkillPointDown", szMethod) == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            SkillPointDown(data.FUN_1422b8b10());
            return 1;
        }
    }
    else if (_stricmp("OnRegisterShortcutkey", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            RegisterShortcut(data.FUN_1422b8b10());
            return 1;
        }
    }
    else if (_stricmp("onRequireSkillEffect", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int bFlag = data.FUN_1422b8a90() == true;
            RequireSkillEffect(data.FUN_1422b8b10(), bFlag);
            return 1;
        }
    }
    else if (_stricmp(szMethod, "onChangeTab") == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        ASData dataTab;
        if (dataTab.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strId = dataTab.FUN_1422b8f40();
            SelectTab(FUN_140718370(strId));
            RefreshSlots(1);
        }
    }
    else if (_stricmp(szMethod, "onRenameTab") == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        ASData dataName;
        if (dataName.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strId = dataName.FUN_1422b8f40();
            __int64 nTabId = FUN_140718370(strId);
            CStringW strName = dataName.FUN_1422b8f40();
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(10, GetStringCommonByKey(L"s_skillbook_tree_config_rename_tab"), 0, L"");
            if (spBox.get() != 0)
            {
                spBox->FUN_141a01d30(0, strName, 10, 0, 0);
                spBox->FUN_141a027c0(SkillBoxDelegate(this, &UISkillBookTreeDialog::OnRenameConfirm));
                spBox->FUN_1405340b0(nTabId);
                FUN_140d73c60(spBox);
            }
        }
    }
    else if (_stricmp(szMethod, "onAddTab") == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        if (m_tabs.GetCount() > 2)
            return 0;
        if (m_tabs.GetCount() < (unsigned)m_nMaxTabs)
        {
            PromptAddTab();
            return 1;
        }
        int nValue = 0;
        int nType = FUN_140166410()->FUN_14036d6d0() ? 10 : 3;
        CStringW strMoney = FUN_1418fe870(nType, &nValue, 0);
        CStringW strText = FUN_14028dfa0(CStringW(L"s_skillbook_tree_config_payment_add_tab"), *FUN_1401d7c10(FUN_1401d3200() + 0x8bb8), strMoney);
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x19, strText, 0, L"");
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01800(1);
            MS2Ptr<Unk_SkillCoupon> spCoupon = DAT_143ab2a90.FUN_140a5e040(0x76);
            bool bHasCoupon = spCoupon.get() != 0;
            spBox->FUN_141a024e0(GetStringCommonByKey(L"s_skillbook_tree_config_payment_add_tab_coupon"), bHasCoupon);
            spBox->FUN_141a02670(bHasCoupon);
            spBox->FUN_141a027c0(SkillBoxDelegate(this, &UISkillBookTreeDialog::OnAddTabPayConfirm));
            FUN_140d73c60(spBox);
            return 1;
        }
    }
    else if (_stricmp(szMethod, "onChangeSubJob") == 0)
    {
        if (m_nWaitServer != 0)
            return 0;
        ASData dataJob;
        if (dataJob.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nJob = dataJob.FUN_1422b8a10() + 1;
            if (nJob == m_nJobLevel)
                return 1;
            MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPlayer == 0)
                return 0;
            int nMax = FUN_1401d7a50()->FUN_140644b80(FUN_141654730(pPlayer));
            if (nMax < nJob)
            {
                FUN_1412751f0(GetStringCommonByKey(L"s_skillbook_tree_disable_sub_job_skill"), 1, 1);
                UpdateSubJobLevel();
                return 1;
            }
            m_nJobLevel = nJob;
            RefreshSlots(0);
            return 1;
        }
    }
    else if (_stricmp(szMethod, "onLapenshardBtn") == 0)
    {
        static_cast<Unk_SkillUIManager*>(FUN_1403ed2b0())->FUN_141adc750(0x4f6d);
    }
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca8460-0x142ca85a0 .text$yd
