// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's gameoption.cpp: the CGameOption store of the
// option tabs (XML load/save, benchmark level) and the battle, camera, community and graphic tab pages.
// MS2-UNIT: client\ms2\gameoption.cpp
// MS2-RANGE: 0x1400ea4e0-0x1400ea840 .text$di
// MS2-RANGE: 0x141241810-0x141250a80 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Buynode@U?$pair@HH@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@$$QEAU?$pair@HH@1@@Z 0x141244680 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHH@std@@U?$pair@HH@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAU?$pair@$$CBHH@1@$$QEAU?$pair@HH@1@@Z 0x141245030 ; unique
// MS2-PIN: ??$emplace@U?$pair@HH@std@@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@HH@1@@Z 0x1412450f0 ; unique
// MS2-PIN: ??$insert@U?$pair@HH@std@@X@?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@HH@1@@Z 0x141245210 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBH_K@std@@PEAX@std@@@std@@QEAA@XZ 0x1412454e0 ; unique
// MS2-PIN: ??1Unk_GoConnect@@QEAA@XZ 0x1412455e0 ; unique
// MS2-PIN: ??$forward@AEAH@std@@YAAEAHAEAH@Z 0x141248370 ; prop
// MS2-PIN: ??0?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@QEAA@XZ 0x141248380 ; unique
// MS2-PIN: ??0?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@AEBU01@@Z 0x1412483c0 ; unique
// MS2-PIN: ??1?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@XZ 0x141248440 ; unique
// MS2-PIN: ??_G?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAAPEAXI@Z 0x141248460 ; unique
// MS2-PIN: ?Add@?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@QEAA_KAEBU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@Z 0x1412484e0 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@CAXPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@_K@Z 0x141248590 ; unique
// MS2-PIN: ??A?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@QEAAAEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@_K@Z 0x1412485f0 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@AEAA_N_K@Z 0x141248650 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@SAXPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@0_K@Z 0x1412487f0 ; unique
// MS2-PIN: ??$?0AEAPEAUUnk_GoResMode@@AEAPEAU0@$0A@@?$pair@PEAUUnk_GoResMode@@PEAU1@@std@@QEAA@AEAPEAUUnk_GoResMode@@0@Z 0x14124dd10 ; unique
// MS2-PIN: ??$FormatStringId@HHHH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBH000@Z 0x14124dd60 ; unique
// MS2-PIN: ??$_Adl_verify_range1@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_GoResMode@@@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_GoResMode@@@std@@@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x14124e4a0 ; unique
// MS2-PIN: ??$_Adl_verify_range@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_GoResMode@@@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_GoResMode@@@std@@@std@@@0@0@Z 0x14124e4b0 ; unique
// MS2-PIN: ??$_Guess_median_unchecked@PEAUUnk_GoResMode@@UUnk_GoResModeLess@@@std@@YAXPEAUUnk_GoResMode@@00UUnk_GoResModeLess@@@Z 0x14124e910 ; unique
// MS2-PIN: ??$_Insertion_sort_unchecked@PEAUUnk_GoResMode@@UUnk_GoResModeLess@@@std@@YAPEAUUnk_GoResMode@@PEAU1@QEAU1@UUnk_GoResModeLess@@@Z 0x14124ead0 ; unique
// MS2-PIN: ??$_Make_heap_unchecked@PEAUUnk_GoResMode@@UUnk_GoResModeLess@@@std@@YAXPEAUUnk_GoResMode@@0UUnk_GoResModeLess@@@Z 0x14124ec20 ; unique
// MS2-PIN: ??$_Med3_unchecked@PEAUUnk_GoResMode@@UUnk_GoResModeLess@@@std@@YAXPEAUUnk_GoResMode@@00UUnk_GoResModeLess@@@Z 0x14124ece0 ; unique
// MS2-PIN: ??$_Move_backward_unchecked1@PEAUUnk_GoResMode@@PEAU1@@std@@YAPEAUUnk_GoResMode@@PEAU1@00U_General_ptr_iterator_tag@0@@Z 0x14124ed80 ; unique
// MS2-PIN: ??$_Move_backward_unchecked@PEAUUnk_GoResMode@@PEAU1@@std@@YAPEAUUnk_GoResMode@@PEAU1@00@Z 0x14124edf0 ; unique
// MS2-PIN: ??$_Partition_by_median_guess_unchecked@PEAUUnk_GoResMode@@UUnk_GoResModeLess@@@std@@YA?AU?$pair@PEAUUnk_GoResMode@@PEAU1@@0@PEAUUnk_GoResMode@@0UUnk_GoResModeLess@@@Z 0x14124ee40 ; unique
// MS2-PIN: ??$_Pass_fn@UUnk_GoResModeLess@@$0A@@std@@YA?AUUnk_GoResModeLess@@U1@@Z 0x14124f200 ; unique
// MS2-PIN: ??$_Pop_heap_hole_by_index@PEAUUnk_GoResMode@@U1@UUnk_GoResModeLess@@@std@@YAXPEAUUnk_GoResMode@@_J1$$QEAU1@UUnk_GoResModeLess@@@Z 0x14124f210 ; unique
// MS2-PIN: ??$_Pop_heap_hole_unchecked@PEAUUnk_GoResMode@@U1@UUnk_GoResModeLess@@@std@@YAXPEAUUnk_GoResMode@@00$$QEAU1@UUnk_GoResModeLess@@@Z 0x14124f3a0 ; unique
// MS2-PIN: ??$_Pop_heap_unchecked@PEAUUnk_GoResMode@@UUnk_GoResModeLess@@@std@@YAXPEAUUnk_GoResMode@@0UUnk_GoResModeLess@@@Z 0x14124f420 ; unique
// MS2-PIN: ??$_Push_heap_by_index@PEAUUnk_GoResMode@@U1@UUnk_GoResModeLess@@@std@@YAXPEAUUnk_GoResMode@@_J1$$QEAU1@UUnk_GoResModeLess@@@Z 0x14124f4e0 ; unique
// MS2-PIN: ??$_Sort_heap_unchecked@PEAUUnk_GoResMode@@UUnk_GoResModeLess@@@std@@YAXPEAUUnk_GoResMode@@0UUnk_GoResModeLess@@@Z 0x14124f5e0 ; unique
// MS2-PIN: ??$_Sort_unchecked@PEAUUnk_GoResMode@@UUnk_GoResModeLess@@@std@@YAXPEAUUnk_GoResMode@@0_JUUnk_GoResModeLess@@@Z 0x14124f640 ; unique
// MS2-PIN: ??$forward@AEAPEAUUnk_GoResMode@@@std@@YAAEAPEAUUnk_GoResMode@@AEAPEAU1@@Z 0x14124f9f0 ; prop
// MS2-PIN: ??$iter_swap@PEAUUnk_GoResMode@@PEAU1@@std@@YAXPEAUUnk_GoResMode@@0@Z 0x14124fa10 ; unique
// MS2-PIN: ??$sort@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_GoResMode@@@std@@@std@@@std@@UUnk_GoResModeLess@@@std@@YAXV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_GoResMode@@@std@@@std@@@0@0UUnk_GoResModeLess@@@Z 0x14124fa50 ; unique
// MS2-PIN: ??$swap@UUnk_GoResMode@@X@std@@YAXAEAUUnk_GoResMode@@0@Z 0x14124fae0 ; unique
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@UUnk_GoResMode@@V?$allocator@UUnk_GoResMode@@@std@@@std@@@std@@QEAA@XZ 0x14124fb90 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@UUnk_GoResMode@@@std@@@std@@QEAA@XZ 0x14124fc40 ; unique
// MS2-PIN: ??0?$vector@UUnk_GoResMode@@V?$allocator@UUnk_GoResMode@@@std@@@std@@QEAA@XZ 0x14124fc90 ; unique
// MS2-PIN: ??0Unk_GoResMode@@QEAA@HHH@Z 0x14124fcc0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400ea600
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_K@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141245790
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_K@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1412457b0
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@H_KU?$less@H@std@@V?$allocator@U?$pair@$$CBH_K@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBH_K@std@@PEAX@2@@Z 0x1412463a0
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@H_KU?$less@H@std@@V?$allocator@U?$pair@$$CBH_K@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBH_K@std@@PEAX@2@@Z 0x1412463d0
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@H_KU?$less@H@std@@V?$allocator@U?$pair@$$CBH_K@std@@@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBH_K@std@@PEAX@std@@@2@XZ 0x1412464c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoption.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cgameoption.h"
class Unk_AeGameOption { public: class Unk_AeGraphicOption* GetGraphicOption(); };   // C3: unit-local view (def in applyeffect)
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/cameramode.h"
#include "ms2/client/ms2/bgtransparencymgr.h"
#include "ms2/client/ms2/localtargetcameramode.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>
#include <map>
#include <utility>
#include <atlcoll.h>
#include <vector>
#include <map>
#include "ms2/commonfiles/crashmanager.h"
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asslider.h"
#include "ms2/placeholder/asradiobutton.h"
#include "ms2/client/ms2/uigameoptiondialog.h"
#include "ms2/placeholder/asdropdownmenu.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/ms2format.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgraphicoptiontable.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/crashmanagercli.h"
#include "ms2/client/ms2/gpumanager.h"

// ---- header statics (dynamic initializers 0x1400ea4e0..0x1400ea810) ----
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))

static CString s_sortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static egf::EntityID s_pointer1(0);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_sortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";

// ---- unit-local placeholders ----

// The option dialog's check box and slider (ASCheckBox / ASSlider, 0x88 bytes).
typedef ASCheckBox Unk_GoCheck;   // C3: was a local view of ASButton
typedef ASSlider Unk_GoSlider;    // C3: was a local view of ASSlider

// The definers' views: the camera scale setter (unit_140ad1860_mousecontroller), the graphic block getter
// (ms2clientplatformbase) and the community block getter (buddymanager's Unk_BuddyOptions::GetSettings).
class CameraMgr;
void FUN_140ad4ff0(CameraMgr* pCam, float fValue);
void* GetGraphicState(void* pGame);
struct Unk_BuddySettings;
class Unk_BuddyOptions { public: Unk_BuddySettings& GetSettings(); };

// The check box and slider lookups as gameoptiongamepad defines them.
struct Unk_GpDialog
{
    MS2Ptr<ASCheckBox> GetTabCheckBox(CString name, int nIndex);
    MS2Ptr<ASSlider> GetTabSlider(CString name, int nIndex);
};

struct Unk_PiDialog { MS2Ptr<ASRadioButton> GetTabRadioButton(CString name, int nIndex); };   // the radio-button lookup, defined in gameoptionpersonalinfoagreement.cpp (0x140a46480)
class Unk_GoDialog
{
public:
    // View of UIGameOptionDialog: the child lookups by name (getTabChild); GetTabRadioButton is Unk_PiDialog's.
    MS2Ptr<ASTextField> GetTabTextField(CString name, int nIndex);
    MS2Ptr<ASTextInput> GetTabTextInput(CString name, int nIndex);

    char m_pad[0x28];
    int m_nId;                                                      // +0x28 the option id
    int m_pad2;
    MS2Ptr<AScript> m_root;                                         // +0x30 the AS root
};

// The state blocks' methods (declared here; they live in client\ms2\gameoptionstruct.cpp).
struct Unk_CameraState* FUN_14125b400(struct Unk_CameraState*);   // C3: was FUN_14125b400
void FUN_14125b430(Unk_CameraState* p);
int LoadGameOptionCamera(Unk_CameraState* p, TiXmlDocument* pDoc);
void FUN_14125b6b0(Unk_CameraState* pDst, const Unk_CameraState* pSrc);
int GetCameraFovStep(const Unk_CameraState* p);
void SetCameraFovStep(Unk_CameraState* p, int n);
struct Unk_BattleState* FUN_14125ca80(struct Unk_BattleState*);   // C3: was FUN_14125ca80
void FUN_14125cab0(Unk_BattleState* p);
int LoadGameOptionBattle(Unk_BattleState* p, TiXmlDocument* pDoc);
void FUN_14125d100(Unk_BattleState* pDst, const Unk_BattleState* pSrc);

struct Unk_CommunityStateA* FUN_14125d130(struct Unk_CommunityStateA*);   // C3: was FUN_14125d130
void FUN_14125d160(Unk_CommunityStateA* p);
int LoadGameOptionCommunityA(Unk_CommunityStateA* p, TiXmlDocument* pDoc);
void FUN_14125d2a0(Unk_CommunityStateA* pDst, const Unk_CommunityStateA* pSrc);
bool FUN_14125d2d0(const Unk_CommunityStateA* p, const Unk_CommunityStateA* q);
struct Unk_CommunityStateB* FUN_14125d330(struct Unk_CommunityStateB*);   // C3: was FUN_14125d330
void FUN_14125d360(Unk_CommunityStateB* p);
int LoadGameOptionCommunityB(Unk_CommunityStateB* p, TiXmlDocument* pDoc);
void FUN_14125d710(Unk_CommunityStateB* pDst, const Unk_CommunityStateB* pSrc);
bool FUN_14125d740(const Unk_CommunityStateB* p, const Unk_CommunityStateB* q);

// ---- CGameOptionBattle ----
// @0x141246d40
CGameOptionBattle::CGameOptionBattle(int nId, int nType)
    : CBaseOption(nId, nType)
{
    // m_state: its ctor (0x14125ca80) runs as a member ctor
}

// @0x141246da0
CGameOptionBattle::~CGameOptionBattle()
{
}

// @0x141246dd0
void CGameOptionBattle::vfunc_3(int n)
{
    if (n == 0)
        FUN_14125d100(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_141248630());
    CBaseOption::vfunc_3(n);
}

// @0x141246e20
void CGameOptionBattle::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}

// @0x141246e50
int CGameOptionBattle::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}

// @0x141246e70
void CGameOptionBattle::vfunc_6()
{
    Unk_GoDialog* pDlg = (Unk_GoDialog*)GetOptionDialog();
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_displayMyGiveRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bDisplayMyGiveRecovery);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_displayMyTakeRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bDisplayMyTakeRecovery);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_displayPartyRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bDisplayPartyRecovery);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_displayGetMeso"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bDisplayGetMeso);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_displayGetExp"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bDisplayGetExp);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_displayEpGauge"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bDisplayEpGauge);
    }
    MS2Ptr<ASRadioButton> spRadio(0);
    int nGive = m_state.m_n08;
    if (nGive == 1)
        spRadio = reinterpret_cast<Unk_PiDialog*>(pDlg)->GetTabRadioButton(CString("m_giveDamageMine"), -1);
    else if (nGive == 3)
        spRadio = reinterpret_cast<Unk_PiDialog*>(pDlg)->GetTabRadioButton(CString("m_giveDamageParty"), -1);
    else if (nGive == 7)
        spRadio = reinterpret_cast<Unk_PiDialog*>(pDlg)->GetTabRadioButton(CString("m_giveDamageAll"), -1);
    if (static_cast<ASRadioButton*>(spRadio) != 0)
        spRadio->SetSelected(1);
    spRadio = 0;
    int nTake = m_state.m_n0c;
    if (nTake == 1)
        spRadio = reinterpret_cast<Unk_PiDialog*>(pDlg)->GetTabRadioButton(CString("m_takeDamageMine"), -1);
    else if (nTake == 3)
        spRadio = reinterpret_cast<Unk_PiDialog*>(pDlg)->GetTabRadioButton(CString("m_takeDamageParty"), -1);
    else if (nTake == 7)
        spRadio = reinterpret_cast<Unk_PiDialog*>(pDlg)->GetTabRadioButton(CString("m_takeDamageAll"), -1);
    if (static_cast<ASRadioButton*>(spRadio) != 0)
        spRadio->SetSelected(1);
    unsigned nDiff = m_state.m_n10;
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_diffSize"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(nDiff & 1);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_diffAlpha"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(nDiff & 2);
    }
}

// @0x141247770
void CGameOptionBattle::vfunc_7()
{
    Unk_GoDialog* pDlg = (Unk_GoDialog*)GetOptionDialog();
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_displayMyGiveRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bDisplayMyGiveRecovery = sp->IsSelected();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_displayMyTakeRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bDisplayMyTakeRecovery = sp->IsSelected();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)pDlg)->GetTabCheckBox(CString("m_displayPartyRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bDisplayPartyRecovery = sp->IsSelected();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayGetMeso"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bDisplayGetMeso = sp->IsSelected();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayGetExp"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bDisplayGetExp = sp->IsSelected();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayEpGauge"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bDisplayEpGauge = sp->IsSelected();
    }
    ATL::CAtlArray<std::pair<CString, int> > arrGive;
    int nGiveMine = 1;
    arrGive.Add(std::pair<CString, int>("m_giveDamageMine", nGiveMine));
    int nGiveParty = 3;
    arrGive.Add(std::pair<CString, int>("m_giveDamageParty", nGiveParty));
    int nGiveAll = 7;
    arrGive.Add(std::pair<CString, int>("m_giveDamageAll", nGiveAll));
    for (size_t i = 0; i < arrGive.GetCount(); i++)
    {
        const std::pair<CString, int>& opt = arrGive[i];
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString(opt.first), -1);
        if (static_cast<ASRadioButton*>(sp) != 0 && sp->IsSelected())
        {
            m_state.m_n08 = opt.second;
            break;
        }
    }
    ATL::CAtlArray<std::pair<CString, int> > arrTake;
    int nTakeMine = 1;
    arrTake.Add(std::pair<CString, int>("m_takeDamageMine", nTakeMine));
    int nTakeParty = 3;
    arrTake.Add(std::pair<CString, int>("m_takeDamageParty", nTakeParty));
    int nTakeAll = 7;
    arrTake.Add(std::pair<CString, int>("m_takeDamageAll", nTakeAll));
    for (size_t i = 0; i < arrTake.GetCount(); i++)
    {
        const std::pair<CString, int>& opt = arrTake[i];
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString(opt.first), -1);
        if (static_cast<ASRadioButton*>(sp) != 0 && sp->IsSelected())
        {
            m_state.m_n0c = opt.second;
            break;
        }
    }
    unsigned nDiff = 0;
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_diffSize"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
        {
            if (sp->IsSelected())
                nDiff |= 1;
            m_state.m_n10 = nDiff;
        }
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_diffAlpha"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
        {
            if (sp->IsSelected())
                nDiff |= 2;
            m_state.m_n10 = nDiff;
        }
    }
}

// @0x141248140
void CGameOptionBattle::vfunc_10()
{
    CBaseOption::vfunc_10();
    FUN_14125d100(TSingleton<CGameOption>::GetInstance()->FUN_141248630(), &m_state);
}

// @0x141248190
void CGameOptionBattle::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125cab0(&m_state);
    LoadGameOptionBattle(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}

// @0x1412481f0
CString CGameOptionBattle::GetTypeName()
{
    return CString("GameOptionBattle");
}

// @0x141248240
int CGameOptionBattle::vfunc_14()
{
    return memcmp(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_141248630(), 0x14);
}

// ---- CGameOptionCamera ----
// @0x141248830
CGameOptionCamera::CGameOptionCamera(int nId, int nType)
    : CBaseOption(nId, nType)
{
    // m_state: its ctor (0x14125b400) runs as a member ctor
}

// @0x141248890
CGameOptionCamera::~CGameOptionCamera()
{
}

// @0x1412488c0
void CGameOptionCamera::vfunc_3(int n)
{
    if (n == 0)
        FUN_14125b6b0(&m_state, TSingleton<CGameOption>::GetInstance()->GetCameraOption());
    CBaseOption::vfunc_3(n);
}

// @0x141248910
void CGameOptionCamera::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}

// @0x141248940
int CGameOptionCamera::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}

// @0x141248960
void CGameOptionCamera::vfunc_6()
{
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_enableBgTransparency"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_b00);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_enableVibrateEffect"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_b01);
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_cameraLooseStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            sp->SetValue((float)m_state.m_n04);
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_cameraFovStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            sp->SetValue((float)GetCameraFovStep(&m_state));
    }
}

// @0x141248c40
void CGameOptionCamera::vfunc_7()
{
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_enableBgTransparency"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b00 = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_enableVibrateEffect"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b01 = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_cameraLooseStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            m_state.m_n04 = (int)sp->GetValue();
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_cameraFovStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            SetCameraFovStep(&m_state, (int)sp->GetValue());
    }
}

namespace Common { class Constants { public: template<class T> class Value { public: T* Get(); }; }; }   // C3: view of clientconstants.h; Value<float>::Get() is 0x140298f40
// A float table value of the client configuration (FUN_1401d3200).
class Unk_GoCfgValue
{
private:
    char m_pad[0x58];
};
struct Unk_GoConfig
{
    char m_pad_0000[0x1a80];
    Unk_GoCfgValue m_1a80;
    Unk_GoCfgValue m_1ad8;
    Unk_GoCfgValue m_1b30;
};
namespace Client { class Constants; } template<class T> class TSingleton; template<> class TSingleton<Client::Constants> { public: static Client::Constants* GetInstance(); }; class Unk_SingletonObj1;   // C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance)

// View of WorldService: the current field (FUN_141bd30a0 returns its MS2Ptr<Unk_WsPtred298> as the field data).
class Unk_1403ed2d0 : public WorldService
{
public:
};

// @0x141248f10
void CGameOptionCamera::vfunc_10()
{
    CBaseOption::vfunc_10();
    FUN_14125b6b0(TSingleton<CGameOption>::GetInstance()->GetCameraOption(), &m_state);
    int nApply = 1;
    CFieldDataCli* pField = static_cast<Unk_1403ed2d0*>(WorldService::GetInstance())->GetFieldData();
    if (pField != 0)
        nApply = static_cast<Unk_1403ed2d0*>(WorldService::GetInstance())->GetFieldData()->m_nApplyCameraOption;
    if (nApply != 0)
    {
        float fScale = WorldService::GetInstance()->FUN_141bcfc50();
        FUN_140ad4ff0(TSingleton<CameraMgr>::GetInstance(), fScale);
        float fStep = (float)m_state.m_n04 / 100.0f;
        float f1 = *reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_GoConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_1a80)->Get() * fStep;
        float f2 = *reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_GoConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_1ad8)->Get() * fStep;
        float f3 = *reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_GoConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_1b30)->Get() * fStep;
        TSingleton<CameraMgr>::GetInstance()->FUN_140aeb880(f1, f2, f3);
        CCameraMode* pMode = TSingleton<CameraMgr>::GetInstance()->GetMode();
        if (pMode != 0)
        {
            if (pMode->vfunc_1() == 0x10)
            {
                CLocalTargetCameraMode* pLocal = static_cast<CLocalTargetCameraMode*>(pMode);
                pLocal->FUN_140d4fa10(fScale);
            }
            CCameraMode* pTarget = TSingleton<CameraMgr>::GetInstance()->GetTargetMode();
            if (pTarget != 0)
            {
                pTarget->vfunc_11(fScale);
                pTarget->vfunc_29(f1, f2, f3);
            }
        }
    }
    TSingleton<BGTransparencyMgr>::GetInstance()->SetUserFlags(m_state.m_b00 != 0);
}

// @0x1412491c0
void CGameOptionCamera::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125b430(&m_state);
    LoadGameOptionCamera(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}

// @0x141249220
CString CGameOptionCamera::GetTypeName()
{
    return CString("GameOptionCamera");
}

// @0x141249270
int CGameOptionCamera::vfunc_14()
{
    return memcmp(&m_state, TSingleton<CGameOption>::GetInstance()->GetCameraOption(), 0x10);
}

// ---- CGameOptionCommunity ----
// @0x1412492f0
CGameOptionCommunity::CGameOptionCommunity(int nId, int nType)
    : CBaseOption(nId, nType)
{
    // m_stateA: its ctor (0x14125d130) runs as a member ctor
    // m_stateB: its ctor (0x14125d330) runs as a member ctor
}

// @0x141249370
CGameOptionCommunity::~CGameOptionCommunity()
{
}

// @0x1412493a0
void CGameOptionCommunity::vfunc_3(int n)
{
    if (n == 0)
    {
        FUN_14125d2a0(&m_stateA, TSingleton<CGameOption>::GetInstance()->FUN_14124ab20());
        FUN_14125d710(&m_stateB, ((Unk_CommunityStateB*)&((Unk_BuddyOptions*)TSingleton<CGameOption>::GetInstance())->GetSettings()));
    }
    CBaseOption::vfunc_3(n);
}

// @0x141249410
void CGameOptionCommunity::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}

// @0x141249440
int CGameOptionCommunity::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}

// @0x141249460
void CGameOptionCommunity::vfunc_6()
{
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayMyChatBalloon"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateA.m_bDisplayMyChatBalloon);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayOtherChatBalloon"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateA.m_bDisplayOtherChatBalloon);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableSingleRiding"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateA.m_bDisableSingleRiding);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayChatComfirmSuper"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisplayChatComfirmSuper);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayChatComfirmWorld"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisplayChatComfirmWorld);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayChatComfirmChannel"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisplayChatComfirmChannel);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disablePartyRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisablePartyRequest);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableBuddyRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisableBuddyRequest);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableGuildRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisableGuildRequest);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableGroupRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisableGroupRequest);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableWhisperNotify"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisableWhisperNotify);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableTradeRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisableTradeRequest);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableHomeRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisableHomeRequest);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableCoupleEmotionRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_stateB.m_bDisableCouplemotionRequest);
    }
}

// @0x141249e50
void CGameOptionCommunity::vfunc_7()
{
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayMyChatBalloon"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateA.m_bDisplayMyChatBalloon = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayOtherChatBalloon"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateA.m_bDisplayOtherChatBalloon = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableSingleRiding"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateA.m_bDisableSingleRiding = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayChatComfirmSuper"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisplayChatComfirmSuper = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayChatComfirmWorld"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisplayChatComfirmWorld = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_displayChatComfirmChannel"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisplayChatComfirmChannel = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disablePartyRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisablePartyRequest = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableBuddyRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisableBuddyRequest = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableGuildRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisableGuildRequest = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableGroupRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisableGroupRequest = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableWhisperNotify"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisableWhisperNotify = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableTradeRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisableTradeRequest = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableHomeRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisableHomeRequest = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_disableCoupleEmotionRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_bDisableCouplemotionRequest = sp->IsSelected() ? true : false;
    }
}

// @0x14124a8d0
void CGameOptionCommunity::vfunc_10()
{
    CBaseOption::vfunc_10();
    if (TSingleton<CGameOption>::GetInstance()->FUN_14124ab20()->m_bDisableSingleRiding != m_stateA.m_bDisableSingleRiding)
    {
        MyPC* pPlayer = (MyPC*)WorldService::GetInstance()->GetLocalPlayer();
        if (pPlayer != 0)
            pPlayer->SendRequestRideMode6(m_stateA.m_bDisableSingleRiding);
    }
    FUN_14125d2a0(TSingleton<CGameOption>::GetInstance()->FUN_14124ab20(), &m_stateA);
    FUN_14125d710(((Unk_CommunityStateB*)&((Unk_BuddyOptions*)TSingleton<CGameOption>::GetInstance())->GetSettings()), &m_stateB);
}

// @0x14124a990
void CGameOptionCommunity::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125d360(&m_stateB);
    FUN_14125d160(&m_stateA);
    LoadGameOptionCommunityB(&m_stateB, TSingleton<CGameOption>::GetInstance()->FUN_1412442c0());
    LoadGameOptionCommunityA(&m_stateA, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}

// @0x14124aa20
CString CGameOptionCommunity::GetTypeName()
{
    return CString("GameOptionCommunity");
}

// @0x14124aa70
int CGameOptionCommunity::vfunc_14()
{
    if (FUN_14125d2d0(&m_stateA, TSingleton<CGameOption>::GetInstance()->FUN_14124ab20()))
        return true;
    if (FUN_14125d740(&m_stateB, ((Unk_CommunityStateB*)&((Unk_BuddyOptions*)TSingleton<CGameOption>::GetInstance())->GetSettings())))
        return true;
    return false;
}

// ---- CGameOptionGraphicDefault ----

// gameoptionstruct.cpp's view of the option dialog: the drop-down lookup by child name.
struct Unk_LgDialog
{
    MS2Ptr<ASDropdownMenu> FUN_140cfcf10(CString name, int nIndex);
};

// The lookups of the dialog view by child name (more instances of the getTabChild template); the first three live in this unit.
MS2Ptr<ASTextField> FUN_1409b41a0(int nId, const Scaleform::GFx::Value& v);
template <class T> MS2Ptr<T> Unk_BpCreate(int nMovieId, const Scaleform::GFx::Value& v);
template <> MS2Ptr<ASTextInput> Unk_BpCreate<ASTextInput>(int nMovieId, const Scaleform::GFx::Value& v);   // 0x140bbe1d0, owned by uiblueprintmarketdialog
template <class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v);
int FUN_1407181a0(const CStringW& str);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);    // notice
int FUN_14151f6e0();

static std::pair<int, int> GetAspectRatio(int nWidth, int nHeight);
#include "ms2/placeholder/formatstringid.h"   // C3: FormatStringId<...> over FUN_14028dee0 by its real name (was FormatStringId(int, const ArgList&))

// @0x14124ff50
MS2Ptr<ASUIComponent> UIGameOptionDialog::GetTabComponent(int nIndex)
{
    // the AS root (+0x30) and id (+0x28) through the Unk_GoDialog view
    if (reinterpret_cast<Unk_GoDialog*>(this)->m_root.IsNull())
        return MS2Ptr<ASUIComponent>(0);
    Scaleform::GFx::Value comp = reinterpret_cast<Unk_GoDialog*>(this)->m_root->Invoke("getTabComponent", nIndex);
    if (comp.IsDisplayObject())
    {
        MS2Ptr<ASUIComponent> sp = Unk_ASCreate<ASUIComponent>(reinterpret_cast<Unk_GoDialog*>(this)->m_nId, comp);
        if (static_cast<ASUIComponent*>(sp) != 0)
            return sp;
    }
    return MS2Ptr<ASUIComponent>(0);
}

// @0x14124e120
MS2Ptr<ASTextField> Unk_GoDialog::GetTabTextField(CString name, int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<ASTextField>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (child.IsDisplayObject())
    {
        MS2Ptr<ASTextField> sp = FUN_1409b41a0(m_nId, child);
        if (static_cast<ASTextField*>(sp) != 0)
            return sp;
    }
    return MS2Ptr<ASTextField>(0);
}

// @0x14124e2e0
MS2Ptr<ASTextInput> Unk_GoDialog::GetTabTextInput(CString name, int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<ASTextInput>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (child.IsDisplayObject())
    {
        MS2Ptr<ASTextInput> sp = Unk_BpCreate<ASTextInput>(m_nId, child);
        if (static_cast<ASTextInput*>(sp) != 0)
            return sp;
    }
    return MS2Ptr<ASTextInput>(0);
}

// The device name holder (DAT_143ad5158): the adapter's name at +0x18.
class Unk_GoDeviceInfo
{
public:
    CStringW GetAdapterName();                                   // copy of the adapter name
    int GetVendor();                                        // the vendor kind
    unsigned __int64 GetBandwidth();                           // the memory bandwidth
    char m_pad0[8];
    int m_nVendor;                                              // +0x08
    char m_pad1[0xc];
    CStringW m_strName;                                         // +0x18
    char m_pad2[0x38 - 0x20];
    unsigned __int64 m_nBandwidth;                              // +0x38
};

// @0x141245ab0
CStringW Unk_GoDeviceInfo::GetAdapterName()
{
    return CStringW(m_strName);
}

// @0x141245b20
GPUManager* TSingleton<GPUManager>::GetInstance()
{
    return TSingleton<GPUManager>::s_instance;
}

// The renderer's display mode list: raw modes (width, height, format) behind a counted pointer array.
struct Unk_GoRawMode
{
    int m_nWidth;
    int m_nHeight;
    int m_nFormat;
};
struct Unk_GoModeArray
{
    char m_pad0[8];
    Unk_GoRawMode** m_ppData;                                   // +0x08
    short m_s10;
    unsigned short m_nCount;                                    // +0x12
    Unk_GoRawMode** FUN_14124fec0(unsigned int nIndex);         // slot of the nIndex-th mode
    unsigned int GetCount();                               // count
};
struct Unk_GoModeSource
{
    char m_pad[0x458];
    Unk_GoModeArray m_modes;                                    // +0x458
    Unk_GoRawMode* GetMode(unsigned int nIndex);          // the nIndex-th mode (or null)
    unsigned int GetModeCount();                               // count
};
class Unk_GoGfxDevice
{
public:
    Unk_GoModeSource* GetModes();                          // +0x728 the display mode source
    char m_pad[0x728];
    Unk_GoModeSource* m_pModes;                                 // +0x728
};

// @0x14124fea0
Unk_GoModeSource* Unk_GoGfxDevice::GetModes()
{
    return m_pModes;
}

// @0x14124fec0
Unk_GoRawMode** Unk_GoModeArray::FUN_14124fec0(unsigned int nIndex)
{
    return m_ppData + nIndex;
}

// @0x14124fee0
Unk_GoRawMode* Unk_GoModeSource::GetMode(unsigned int nIndex)
{
    return *m_modes.FUN_14124fec0(nIndex);
}

// @0x14124ff10
unsigned int Unk_GoModeSource::GetModeCount()
{
    return m_modes.GetCount();
}

// @0x14124ff40
unsigned int Unk_GoModeArray::GetCount()
{
    return m_nCount;
}

// One row of the resolution combo: the mode's index and its size. Sorted by size.
struct Unk_GoResMode
{
    int m_nIndex;
    std::pair<int, int> m_size;
    Unk_GoResMode(int nIndex, int nWidth, int nHeight) : m_nIndex(nIndex), m_size(nWidth, nHeight) {}
};
struct Unk_GoResModeLess
{
    bool operator()(const Unk_GoResMode& a, const Unk_GoResMode& b) const;
};

// @0x14124fdc0
bool Unk_GoResModeLess::operator()(const Unk_GoResMode& a, const Unk_GoResMode& b) const
{
    const std::pair<int, int>& l = a.m_size;
    const std::pair<int, int>& r = b.m_size;
    if (l.first == r.first)
        return l.second < r.second;
    return l.first < r.first;
}

// More members of the singletons used here.
class Unk_GoUiMgr { public: void FUN_141adc530(int nUiId); };

// The graphic state blocks' methods (client\ms2\gameoptionstruct.cpp).
struct Unk_GraphicState* FUN_14125d890(struct Unk_GraphicState*);   // C3: was FUN_14125d890
void FUN_14125d8c0(Unk_GraphicState* p);
int LoadGameOptionGraphic(Unk_GraphicState* p, TiXmlDocument* pDoc, int n);
void FUN_14125dff0(Unk_GraphicState* pDst, const Unk_GraphicState* pSrc);
void SetQuality(Unk_GraphicState* p, int nQuality, int n);
void SetHdr(Unk_GraphicState* p, int b);
void SetShimmer(Unk_GraphicState* p, int b);
void FUN_14125e4b0(Unk_GraphicState* p, int n);
void FUN_14125e5b0(Unk_GraphicState* p, int b);
bool FUN_14125e7e0(struct Unk_GraphicState*, int, unsigned int, unsigned int);   // C3: was FUN_14125e7e0
void FUN_14125e910(Unk_GraphicState* p, int nScreenMode, int nResIdx);
struct Unk_GraphicState2* FUN_14125ec20(struct Unk_GraphicState2*);   // C3: was FUN_14125ec20
void FUN_14125ec50(Unk_GraphicState2* p);
int LoadGameOptionOptimizer(Unk_GraphicState2* p, TiXmlDocument* pDoc);
void FUN_14125ef60(Unk_GraphicState2* pDst, const Unk_GraphicState2* pSrc);
void FUN_14125ef90(Unk_GraphicState2* p);

// @0x14124ab20
Unk_CommunityStateA* CGameOption::FUN_14124ab20()
{
    return &m_communityA;
}

// @0x14124ab30
CGameOptionGraphicDefault::CGameOptionGraphicDefault(int nId, int nType)
    : CBaseOption(nId, nType)
{
    // m_state: its ctor (0x14125d890) runs as a member ctor
    // m_state2: its ctor (0x14125ec20) runs as a member ctor
    m_n74 = 0;
}

// @0x14124abb0
CGameOptionGraphicDefault::~CGameOptionGraphicDefault()
{
}

// @0x14124abe0
void CGameOptionGraphicDefault::vfunc_3(int n)
{
    if (n == 0)
    {
        FUN_14125dff0(&m_state, reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption()));
        FUN_14125ef60(&m_state2, ((Unk_GraphicState2*)GetGraphicState(TSingleton<CGameOption>::GetInstance())));
    }
    m_n74 = 0;
    CBaseOption::vfunc_3(n);
}

// @0x14124ac60
void CGameOptionGraphicDefault::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}

// @0x14124ac90
int CGameOptionGraphicDefault::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    if (_stricmp(pszName, "onDisplayQuality") == 0)
    {
        if (m_n74 == 0)
            return 0;
        ASData data;
        if (data.SetArgsIfAny((const Scaleform::GFx::Value*)pArg, nArg))
        {
            int nLevel = data.PopInt();
            {
                MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_hdr"), -1);
                if (static_cast<Unk_GoCheck*>(sp) != 0)
                    sp->SetSelected(TSingleton<CGraphicOptionTable>::GetInstance()->IsHdrSupported(nLevel));
            }
            {
                MS2Ptr<ASDropdownMenu> sp = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_shadow"), -1);
                if (static_cast<ASDropdownMenu*>(sp) != 0)
                {
                    if (nLevel >= 3)
                        sp->SetSelectedIndex(2);
                    else if (nLevel >= 2)
                        sp->SetSelectedIndex(1);
                    else if (nLevel >= 0)
                        sp->SetSelectedIndex(0);
                }
            }
            {
                MS2Ptr<Unk_GoSlider> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_effectStep"), -1);
                if (static_cast<Unk_GoSlider*>(sp) != 0)
                {
                    int nMin = 1;
                    sp->SetValue((float)(std::max)(nLevel, nMin));
                }
            }
            if (nLevel > TSingleton<CGameOption>::GetInstance()->GetBenchmarkLevel() && nLevel != m_state.m_nQuality && FUN_14151f6e0() != 0)
                FUN_140d73bc0(0x84d, 0, 0, CStringW(L""));
        }
    }
    return 0;
}

// @0x14124aff0
void CGameOptionGraphicDefault::vfunc_6()
{
    FillResolutionCombo();
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_screenModeWindow"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            sp->SetSelected(m_state.m_nScreenMode == 1);
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_screenModeFullWindow"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            sp->SetSelected(m_state.m_nScreenMode == 2);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_showFrameRate"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bShowFrameRate);
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_effectStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            sp->SetValue((float)m_state.m_nEffectStep);
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_quality"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
        {
            float fQuality = (float)m_state.m_nQuality;
            sp->SetValue(fQuality);
        }
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_hdr"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bHdr != 0);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_shimmer"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bShimmer != 0);
    }
    {
        MS2Ptr<ASDropdownMenu> sp = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_multisampling"), -1);
        if (static_cast<ASDropdownMenu*>(sp) != 0)
            sp->SetSelectedIndex(m_state.m_nMultisampling);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_vsync"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bVsync);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_enchantEffect"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state.m_bEnchantEffect);
    }
    {
        MS2Ptr<ASDropdownMenu> sp = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_shadow"), -1);
        if (static_cast<ASDropdownMenu*>(sp) != 0)
        {
            int nShadow = m_state.m_nShadow;
            if (nShadow >= 3)
                sp->SetSelectedIndex(2);
            else if (nShadow >= 2)
                sp->SetSelectedIndex(1);
            else if (nShadow >= 0)
                sp->SetSelectedIndex(0);
        }
    }
    {
        MS2Ptr<ASTextField> sp = ((Unk_GoDialog*)GetOptionDialog())->GetTabTextField(CString("m_devicename"), -1);
        if (static_cast<ASTextField*>(sp) != 0)
            sp->SetTextW(reinterpret_cast<Unk_GoDeviceInfo*>(TSingleton<GPUManager>::GetInstance())->GetAdapterName());
    }
    {
        MS2Ptr<ASDropdownMenu> sp = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_optimalHide"), -1);
        if (static_cast<ASDropdownMenu*>(sp) != 0)
            sp->SetSelectedIndex(m_state2.m_nOptimalHide);
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_hideAlways"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            sp->SetSelected(m_state2.m_bHideAlways);
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_hideBossBattle"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            sp->SetSelected(m_state2.m_bHideBossBattle);
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_showParty"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            sp->SetSelected(m_state2.m_bShowParty);
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_showGuild"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            sp->SetSelected(m_state2.m_bShowGuild);
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_showCustom"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            sp->SetSelected(m_state2.m_bShowCustom);
    }
    {
        MS2Ptr<ASTextInput> sp = ((Unk_GoDialog*)GetOptionDialog())->GetTabTextInput(CString("m_customInput"), -1);
        if (static_cast<ASTextInput*>(sp) != 0)
            sp->SetTextW(StringFormat(L"{0}", m_state2.m_nCustomInput));
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_showPhysx"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->SetSelected(m_state2.m_bShowPhysx);
    }
    m_n74 = 1;
}

// @0x14124bf20
void CGameOptionGraphicDefault::vfunc_7()
{
    {
        MS2Ptr<ASUIComponent> spComp = GetOptionDialog()->GetTabComponent(m_nType);
        if (static_cast<ASUIComponent*>(spComp) != 0)
        {
            int nRes = spComp->Invoke("getResolution").GetInt();
            if (nRes != -1)
            {
                m_state.m_nResIdx = nRes;
                GetModeSize(m_state.m_nResIdx, &m_state.m_nWidth, &m_state.m_nHeight);
            }
        }
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_screenModeWindow"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            if (sp->IsSelected())
                m_state.m_nScreenMode = 1;
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_screenModeFullWindow"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            if (sp->IsSelected())
                m_state.m_nScreenMode = 2;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_showFrameRate"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bShowFrameRate = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_effectStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            m_state.m_nEffectStep = (int)sp->GetValue();
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_quality"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            m_state.m_nQuality = (int)sp->GetValue();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_hdr"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bHdr = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_shimmer"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bShimmer = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<ASDropdownMenu> sp = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_shadow"), -1);
        if (static_cast<ASDropdownMenu*>(sp) != 0)
        {
            int nSel = sp->GetSelectedIndex();
            if (nSel == 0)
                m_state.m_nShadow = 0;
            else if (nSel == 1)
                m_state.m_nShadow = 2;
            else if (nSel == 2)
                m_state.m_nShadow = 3;
        }
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_vsync"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bVsync = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_enchantEffect"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bEnchantEffect = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<ASDropdownMenu> sp = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_multisampling"), -1);
        if (static_cast<ASDropdownMenu*>(sp) != 0)
            m_state.m_nMultisampling = sp->GetSelectedIndex();
    }
    {
        MS2Ptr<ASDropdownMenu> sp = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_optimalHide"), -1);
        if (static_cast<ASDropdownMenu*>(sp) != 0)
            m_state2.m_nOptimalHide = sp->GetSelectedIndex();
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_hideAlways"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            m_state2.m_bHideAlways = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_hideBossBattle"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            m_state2.m_bHideBossBattle = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_showParty"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            m_state2.m_bShowParty = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_showGuild"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            m_state2.m_bShowGuild = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<ASRadioButton> sp = ((Unk_PiDialog*)GetOptionDialog())->GetTabRadioButton(CString("m_showCustom"), -1);
        if (static_cast<ASRadioButton*>(sp) != 0)
            m_state2.m_bShowCustom = sp->IsSelected() ? true : false;
    }
    {
        MS2Ptr<ASTextInput> sp = ((Unk_GoDialog*)GetOptionDialog())->GetTabTextInput(CString("m_customInput"), -1);
        if (static_cast<ASTextInput*>(sp) != 0)
        {
            CStringW strInput = sp->GetText();
            m_state2.m_nCustomInput = FUN_1407181a0(strInput);
        }
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_showPhysx"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state2.m_bShowPhysx = sp->IsSelected() ? true : false;
    }
}

// @0x14124ce20
void CGameOptionGraphicDefault::FUN_14124ce20()
{
    Unk_GraphicState* pGfx = reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption());
    int bResChanged = 0;
    int bNotify = 0;
    if (m_state.m_nScreenMode != pGfx->m_nScreenMode || m_state.m_nResIdx != pGfx->m_nResIdx)
        bResChanged = 1;
    if (bResChanged)
    {
        FUN_14125e910(reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption()), m_state.m_nScreenMode, m_state.m_nResIdx);
        m_state.m_nWidth = reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption())->m_nWidth;
        m_state.m_nHeight = reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption())->m_nHeight;
    }
    if (m_state.m_nQuality != pGfx->m_nQuality)
        SetQuality(&m_state, m_state.m_nQuality, 0);
    if (m_state.m_bHdr != pGfx->m_bHdr)
        SetHdr(&m_state, m_state.m_bHdr);
    if (m_state.m_bShimmer != pGfx->m_bShimmer)
        SetShimmer(&m_state, m_state.m_bShimmer);
    if (m_state.m_nEffectStep != pGfx->m_nEffectStep)
        TSingleton<CEffectService>::GetInstance()->FUN_1411a8880(m_state.m_nEffectStep);
    if (m_state.m_nMultisampling != pGfx->m_nMultisampling)
    {
        FUN_14125e4b0(&m_state, TSingleton<CGraphicOptionTable>::GetInstance()->GetMultisampleValue(m_state.m_nMultisampling));
        bNotify = 1;
    }
    if (m_state.m_bVsync != pGfx->m_bVsync)
    {
        FUN_14125e5b0(&m_state, m_state.m_bVsync);
        bNotify = 1;
    }
    if (m_state.m_bShowFrameRate)
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4e7d)));
    else
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e7d);
    if (bNotify != 0)
        FUN_140d73bc0(0x84e, 0, 0, CStringW(L""));
}

// @0x14124d080
void CGameOptionGraphicDefault::FillResolutionCombo()
{
    int nRows = 0;
    MS2Ptr<ASDropdownMenu> spCombo = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_resolution"), -1);
    if (static_cast<ASDropdownMenu*>(spCombo) != 0)
    {
        spCombo->ClearItems();
        int nCurWidth = m_state.m_nWidth;
        int nCurHeight = m_state.m_nHeight;
        Unk_GoGfxDevice* pDevice = ((class Unk_GoGfxDevice*)NiRenderer::GetRenderer());
        if (pDevice != 0)
        {
            Unk_GoModeSource* pSource = pDevice->GetModes();
            if (pSource != 0)
            {
                std::vector<Unk_GoResMode> modes;
                for (unsigned int i = 0; i < pSource->GetModeCount(); i++)
                {
                    Unk_GoRawMode* pRaw = pSource->GetMode(i);
                    if (pRaw != 0
                        && FUN_14125e7e0(reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption()), pRaw->m_nFormat, pRaw->m_nWidth, pRaw->m_nHeight))
                        modes.push_back(Unk_GoResMode(i, pRaw->m_nWidth, pRaw->m_nHeight));
                }
                if (!modes.empty())
                {
                    nRows = (int)modes.size();
                    if (nRows > 6)
                        spCombo->SetScrollBar(L"export_scroll");
                    else
                        spCombo->SetMenuRowCount(nRows);
                    std::sort(modes.begin(), modes.end(), Unk_GoResModeLess());
                    int nSelectedId = 0;                        // set, never read
                    int nSelected = 0;
                    for (int j = 0; j < nRows; j++)
                    {
                        const Unk_GoResMode& mode = modes.at(j);
                        int nWidth = mode.m_size.first;
                        int nHeight = mode.m_size.second;
                        CStringW strLabel;
                        std::pair<int, int> ratio = GetAspectRatio(nWidth, nHeight);
                        if ((float)ratio.first / (float)ratio.second >= 1.59f)
                            strLabel = FormatStringId(0x310, nWidth, nHeight, ratio.first, ratio.second);
                        else
                            strLabel = FormatStringId(0x30f, nWidth, nHeight, ratio.first, ratio.second);
                        ASObj row(2);
                        row.SetIntMember("modeid", mode.m_nIndex);
                        row.SetWStringMember("label", strLabel);
                        spCombo->AddItemRow(row);
                        if (nCurWidth == nWidth && nCurHeight == nHeight)
                        {
                            nSelected = j;
                            nSelectedId = mode.m_nIndex;
                        }
                    }
                    spCombo->SetSelectedIndex(nSelected);
                    spCombo->vfunc_24(true);
                }
            }
        }
    }
}

// @0x14124d5f0
void CGameOptionGraphicDefault::GetModeSize(int nIndex, int* pnWidth, int* pnHeight)
{
    Unk_GoGfxDevice* pDevice = ((class Unk_GoGfxDevice*)NiRenderer::GetRenderer());
    if (pDevice != 0)
    {
        Unk_GoModeSource* pSource = pDevice->GetModes();
        if (pSource != 0)
        {
            std::vector<Unk_GoResMode> modes;                   // unused
            Unk_GoRawMode* pRaw = pSource->GetMode(nIndex);
            if (pRaw != 0)
            {
                *pnWidth = pRaw->m_nWidth;
                *pnHeight = pRaw->m_nHeight;
            }
        }
    }
}

// @0x14124d6a0
void CGameOptionGraphicDefault::vfunc_10()
{
    CBaseOption::vfunc_10();
    bool bOldEnchant = true;
    Unk_GraphicState* pGfx = reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption());
    if (pGfx != 0)
        bOldEnchant = pGfx->m_bEnchantEffect;
    FUN_14124ce20();
    FUN_14125dff0(reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption()), &m_state);
    FUN_14125ef60(((Unk_GraphicState2*)GetGraphicState(TSingleton<CGameOption>::GetInstance())), &m_state2);
    FUN_14125ef90(&m_state2);
    if (m_state.m_bEnchantEffect != bOldEnchant)
    {
        if (m_state.m_bEnchantEffect)
            WorldService::GetInstance()->FUN_141bd41d0();
        else
            WorldService::GetInstance()->FUN_141bd4260();
    }
}

// @0x14124d7a0
void CGameOptionGraphicDefault::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125d8c0(&m_state);
    LoadGameOptionGraphic(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0(), 1);
    FUN_14125ec50(&m_state2);
    LoadGameOptionOptimizer(&m_state2, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}

// @0x14124d840
CString CGameOptionGraphicDefault::GetTypeName()
{
    return CString("GameOptionGraphic");
}

// @0x14124d890
int CGameOptionGraphicDefault::vfunc_14()
{
    unsigned int nDiff1 = memcmp(&m_state, reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption()), sizeof(Unk_GraphicState));
    nDiff1 |= memcmp(&m_state2, ((Unk_GraphicState2*)GetGraphicState(TSingleton<CGameOption>::GetInstance())), sizeof(Unk_GraphicState2));
    return nDiff1;
}

// @0x14124d900
static int Gcd(int a, int b)
{
    while (b != 0)
    {
        int nRem = a % b;
        a = b;
        b = nRem;
    }
    return abs(a);
}

extern "C" float (__cdecl* __imp_ceilf)(float);   // the exe calls the IAT slot

// @0x14124d950
static float RoundHalfUp(float f)
{
    float fInt = (float)(int)f;
    float fFrac = f - fInt;
    return 0.5f <= fFrac ? __imp_ceilf(fInt + 1.0f) : fInt;
}

// The aspect ratio of a resolution as a small integer pair (16:9, 16:10, ...).
// @0x14124d9d0
static std::pair<int, int> GetAspectRatio(int nWidth, int nHeight)
{
    int nGcd = Gcd(nWidth, nHeight);
    int a = nWidth;
    int b = nHeight;
    if (1 < nGcd)
    {
        a = a / nGcd;
        b = b / nGcd;
    }
    bool bScale = 0x10 < a;
    if (!bScale)
    {
        float fRatio = (float)a / (float)b;
        if (fRatio < 1.6f || 1.67f <= fRatio)
            bScale = 5 < a;
        else
        {
            float fMul16 = 16.0f / (float)a;
            int nMul = (int)fMul16;
            a = a * nMul;
            b = b * nMul;
            if (a < 0x10 && (nGcd = Gcd(a, b), 1 < nGcd))
            {
                a = a / nGcd;
                b = b / nGcd;
            }
        }
    }
    if (bScale)
    {
        float fRatio = (float)a / (float)b;
        float fScaled = fRatio < 1.6f ? RoundHalfUp(fRatio * 10.0f) : fRatio * 10.0f;
        if (fRatio < 1.57f)
        {
            int nScaled = (int)fScaled;
            float fMul = (float)nScaled / (float)a;
            a = nScaled;
            float fB = (float)b * fMul;
            b = (int)RoundHalfUp(fB);
            float fRatio2 = (float)a / (float)b;
            if ((fRatio2 < 1.6f || 1.67f <= fRatio2) && (nGcd = Gcd(a, b), 1 < nGcd))
            {
                a = a / nGcd;
                b = b / nGcd;
            }
        }
        else
        {
            float fNine = 9.0f;
            float fMul = fNine / (float)b;
            float fA = (float)a * fMul;
            a = (int)RoundHalfUp(fA);
            b = (int)fNine;
        }
    }
    return std::pair<int, int>(a, b);
}

// ---- CGameOption (the option store) ----

class CCrashManager;
class CLogString;
CLogString* GetLogString();                                     // the log string table
void Unk_AdditionalLog(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszText);
int IsNexonPlatform();                                            // the platform kind
extern char g_bLanguageSet;
class TiXmlNode   // C3: member view for the former free stand-ins
{
public:
    void Clear();
    class TiXmlNode* LinkEndChild(class TiXmlNode*);
};
class TiXmlElement* DocRootElement(class TiXmlDocument*);   // C3: was FUN_14081b310
class Unk_XmlNode   // C3: member view for the former free stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
CStringW FUN_1401bf530(class TiXmlElement* pElem, const char* szName, CStringW strDefault);   // string attribute (strDefault by value)
void XmlSetAttr(class TiXmlElement*, const char*, const CStringA&);
void* FUN_14086f2f0(void* pMem, const char* szName);            // TiXmlElement::TiXmlElement(const char*)
class TiXmlElement
{
public:
    TiXmlElement(const char* szValue);                              // 0x14086f2f0
private:
    char m_pad[0x90];
};
CString JoinPath(const CString& strRoot, const CString& strFile);   // path join
CString GetOptionFolder();                                        // the option folder
CString GetAccountFolder();                                        // the account folder
CString GetCharacterFolder();                                        // the character folder
CString GetDefaultOptionFolder();                                        // the default option folder
int GetLanguageFromLangId(short nLangId);
void SetLanguage(int nLanguage);
void SetVoice(int nVoice);
void FUN_140841420(CStringW& str);                              // MakeLower
void FUN_14125fe20(Unk_SoundState* p);
CString FUN_1409a23d0(const char* pszUtf8, int nCodePage);

// The GPU and adapter records the benchmark reads.
class Unk_GoGpuMgr
{
public:
    unsigned __int64 GetVideoMem();                           // +0x28 the video memory
    char m_pad[0x28];
    unsigned __int64 m_nVideoMem;                               // +0x28
};
class Unk_AvModeSvc* GetOptimizer();   // C3: was GetOptimizer

// The state blocks' methods that gameoptionstruct.cpp owns (the ones with FUN_ names resolve through the address).
struct Unk_InterfaceState* FUN_14125b770(struct Unk_InterfaceState*);   // C3: was FUN_14125b770
struct Unk_InterfaceFlag* FUN_14125bc30(struct Unk_InterfaceFlag*);   // C3: was FUN_14125bc30
struct Unk_StatusState* FUN_14125bda0(struct Unk_StatusState*);   // C3: was FUN_14125bda0
struct Unk_StatusFlag* FUN_14125c880(struct Unk_StatusFlag*);   // C3: was FUN_14125c880
struct Unk_SoundState* FUN_14125f710(struct Unk_SoundState*);   // C3: was FUN_14125f710
struct Unk_SoundFlag* FUN_141260380(struct Unk_SoundFlag*);   // C3: was FUN_141260380
//
struct Unk_GsEtc* FUN_141261750(struct Unk_GsEtc*);   // C3: was FUN_141261750
struct Unk_LgState* FUN_14125f090(struct Unk_LgState*);   // C3: was FUN_14125f090
struct Unk_GpState* FUN_14125f290(struct Unk_GpState*);   // C3: was FUN_14125f290
struct Unk_GoChroma* FUN_141261670(struct Unk_GoChroma*);   // C3: was FUN_141261670
#ifndef MS2_HOOK_DLL
// The one Unk_GoMember<T> ctor CGameOption's ctor still calls (the other 17 blocks have real ctors). Same stores as
// CPersonalInfoAgreement's ctor (gameoptionstruct.cpp, 0x141261cf0): /opt:icf folds them.
struct Unk_PiAgreeBlock { bool m_bAgreeVisitHome; int m_nFlags; bool m_bAnswered; };
template <> inline Unk_GoMember<Unk_PiAgreeState>::Unk_GoMember()
{
    ((Unk_PiAgreeBlock*)this)->m_bAgreeVisitHome = false;
    ((Unk_PiAgreeBlock*)this)->m_nFlags = 0;
    ((Unk_PiAgreeBlock*)this)->m_bAnswered = false;
}
#endif
class CPersonalInfoAgreement { public: CPersonalInfoAgreement(); };   // 0x141261cf0 (gameoptionpersonalinfoagreement.cpp)
int LoadGameOptionInterface(Unk_InterfaceState* p, TiXmlDocument* pDoc);
int LoadGameOptionStatus(Unk_StatusState* p, TiXmlDocument* pDoc);
int LoadGameOptionSound(Unk_SoundState* p, TiXmlDocument* pDoc);
int LoadGameOptionConnect(struct Unk_GsConnect*, class TiXmlDocument*);   // C3: was FUN_141260600
int LoadGameOptionChroma(Unk_GoChroma* p, TiXmlDocument* pDoc);
int LoadGameOptionLanguage(Unk_LgState* p, TiXmlDocument* pDoc);
void FUN_141260ed0(struct Unk_GsAutoLoot*);   // C3: was FUN_141260ed0
void FUN_141261780(struct Unk_GsEtc*);   // C3: was FUN_141261780
void FUN_14125c8b0(Unk_StatusFlag* p);
void FUN_1412603b0(Unk_SoundFlag* p);
void FUN_14125bc60(Unk_InterfaceFlag* p);
void FUN_14125f2c0(Unk_GpState* p);
int LoadGameOptionAutoLooting(struct Unk_GsAutoLoot*, class TiXmlDocument*);   // C3: was FUN_141260f40
int LoadGameOptionEtc(struct Unk_GsEtc*, class TiXmlDocument*);   // C3: was FUN_141261810
int FUN_14125c8d0(Unk_StatusFlag* p, TiXmlDocument* pDoc);
int FUN_1412603d0(Unk_SoundFlag* p, TiXmlDocument* pDoc);
int FUN_14125bc80(Unk_InterfaceFlag* p, TiXmlDocument* pDoc);
int LoadGameOptionGamepad(Unk_GpState* p, TiXmlDocument* pDoc);
int FUN_14125c970(Unk_StatusFlag* p, TiXmlDocument* pDoc);
void SaveGameOptionCamera(Unk_CameraState* p, TiXmlDocument* pDoc);
void SaveGameOptionInterface(Unk_InterfaceState* p, TiXmlDocument* pDoc);
void SaveGameOptionStatus(Unk_StatusState* p, TiXmlDocument* pDoc);
void SaveGameOptionBattle(Unk_BattleState* p, TiXmlDocument* pDoc);
void SaveGameOptionCommunityA(Unk_CommunityStateA* p, TiXmlDocument* pDoc);
void SaveGameOptionGraphic(Unk_GraphicState* p, TiXmlDocument* pDoc);
void SaveGameOptionSound(Unk_SoundState* p, TiXmlDocument* pDoc);
void SaveGameOptionConnect(struct Unk_GsConnect*, class TiXmlDocument*);   // C3: was FUN_1412607a0
void SaveGameOptionOptimizer(Unk_GraphicState2* p, TiXmlDocument* pDoc);
void SaveGameOptionLanguage(Unk_LgState* p, TiXmlDocument* pDoc);
void SaveGameOptionCommunityB(Unk_CommunityStateB* p, TiXmlDocument* pDoc);
void SaveGameOptionChroma(Unk_GoChroma* p, TiXmlDocument* pDoc);
void SaveGameOptionAutoLooting(struct Unk_GsAutoLoot*, class TiXmlDocument*);   // C3: was FUN_141261150
void SaveGameOptionEtc(struct Unk_GsEtc*, class TiXmlDocument*);   // C3: was FUN_1412619e0
void FUN_14125c910(Unk_StatusFlag* p, TiXmlDocument* pDoc);
void FUN_141260410(Unk_SoundFlag* p, TiXmlDocument* pDoc);
void FUN_14125bcc0(Unk_InterfaceFlag* p, TiXmlDocument* pDoc);
void SaveGameOptionGamepad(Unk_GpState* p, TiXmlDocument* pDoc);
void SetBrightness(Unk_GraphicState* p, int n);
static void SetOptionVersion(TiXmlDocument* pDoc);

// @0x141241810
CGameOption::CGameOption()
{
    m_nBenchmark = -1;
    m_b464 = false;
    reinterpret_cast<CCrashManager*>(TSingleton<CrashManagerCli>::GetInstance())->AddCallback(TFunctor<void, EmptyParam>(this, &CGameOption::FUN_141243630));
    LoadLanguageOption();
    LoadGameOption();
}

// @0x141241aa0
CGameOption::~CGameOption()
{
}

// @0x141241b60
CString CGameOption::GetOptionFilePath(int nKind, bool bDefault)
{
    if (nKind == 0)
    {
        if (bDefault)
            return JoinPath(GetDefaultOptionFolder(), "DefaultGameOption.xml");
        else
            return JoinPath(GetOptionFolder(), "GameOption.xml");
    }
    else if (nKind == 1)
    {
        if (bDefault)
            return JoinPath(GetDefaultOptionFolder(), "DefaultAccountOption.xml");
        else
            return JoinPath(GetAccountFolder(), "AccountOption.xml");
    }
    else if (nKind == 2)
    {
        if (bDefault)
            return JoinPath(GetDefaultOptionFolder(), "DefaultCharacterOption.xml");
        else
            return JoinPath(GetCharacterFolder(), "CharacterOption.xml");
    }
    return CString();
}

// @0x141241f30
int CGameOption::LoadGameOption()
{
    int bRead = 0;
    if (IsOptionFileMissingOrOutdated(0) != 0)
    {
        DeleteFileA(GetOptionFilePath(0, false));
        bRead = GetFileSystem()->LoadXmlFile(&m_docGame, GetOptionFilePath(0, true), 0, true, false);
    }
    else
        bRead = GetFileSystem()->LoadXmlFile(&m_docGame, GetOptionFilePath(0, false), 0, true, false);
    if (bRead == 0)
        EE_LOG_AT(1, 1, ("Failed to read %s", "GameOption.xml"), MS2_THIS_FILE, 0x59);
    if (LoadGameOptionCamera(&m_camera, &m_docGame) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read camera option");
    if (LoadGameOptionInterface(&m_interface, &m_docGame) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read interface option");
    if (LoadGameOptionStatus(&m_status, &m_docGame) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read status option");
    if (LoadGameOptionBattle(&m_battle, &m_docGame) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read battle option");
    if (LoadGameOptionCommunityA(&m_communityA, &m_docGame) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read community option");
    if (LoadGameOptionGraphic(&m_graphic, &m_docGame, 0) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read graphic option");
    if (LoadGameOptionSound(&m_sound, &m_docGame) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read sound option");
    if (LoadGameOptionConnect((struct Unk_GsConnect*)(&m_connect), &m_docGame) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read connect option");
    if (LoadGameOptionOptimizer(&m_graphic2, &m_docGame) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read optimal hide option");
    if (LoadGameOptionChroma(&m_chroma, &m_docGame) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read chroma option");
    reinterpret_cast<CCrashManager*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_1401ce2f0("GameOption: Width(%d) Height(%d)", m_graphic.m_nWidth, m_graphic.m_nHeight);
    return GetFileSystem()->LoadXmlFile(&m_docGameDefault, GetOptionFilePath(0, true), 0, true, false);
}

// @0x141242570
int CGameOption::LoadAccountOption()
{
    ((class TiXmlNode*)(class TiXmlDocument*)(&m_docAccount))->Clear();
    int bRead = 0;
    if (IsOptionFileMissingOrOutdated(1) != 0)
    {
        DeleteFileA(GetOptionFilePath(1, false));
        bRead = GetFileSystem()->LoadXmlFile(&m_docAccount, GetOptionFilePath(1, true), 0, true, false);
    }
    else
        bRead = GetFileSystem()->LoadXmlFile(&m_docAccount, GetOptionFilePath(1, false), 0, true, false);
    if (bRead == 0)
        EE_LOG_AT(1, 1, ("Failed to read %s", "AccountOption.xml"), MS2_THIS_FILE, 0x85);
    if (LoadGameOptionCommunityB(&m_account, &m_docAccount) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read account option");
    int bReadDefault = GetFileSystem()->LoadXmlFile(&m_docAccountDefault, GetOptionFilePath(1, true), 0, true, false);
    if (CFeatureManager::GetInstance()->IsRegionNA())
    {
        TSingleton<CGameOption>::GetInstance()->GetEtc()->m_n08 = 0;
        ((Unk_CommunityStateB*)&((Unk_BuddyOptions*)TSingleton<CGameOption>::GetInstance())->GetSettings())->m_bDisplayChatComfirmSuper = true;
        ((Unk_CommunityStateB*)&((Unk_BuddyOptions*)TSingleton<CGameOption>::GetInstance())->GetSettings())->m_bDisplayChatComfirmWorld = true;
        ((Unk_CommunityStateB*)&((Unk_BuddyOptions*)TSingleton<CGameOption>::GetInstance())->GetSettings())->m_bDisplayChatComfirmChannel = true;
        TSingleton<CGameOption>::GetInstance()->SaveCharacterSettings();
    }
    return bReadDefault;
}

// @0x141242990
int CGameOption::LoadCharacterOption()
{
    ((class TiXmlNode*)(class TiXmlDocument*)(&m_docCharacter))->Clear();
    int bRead = 0;
    if (IsOptionFileMissingOrOutdated(2) != 0)
    {
        DeleteFileA(GetOptionFilePath(2, false));
        bRead = GetFileSystem()->LoadXmlFile(&m_docCharacter, GetOptionFilePath(2, true), 0, true, false);
    }
    else
        bRead = GetFileSystem()->LoadXmlFile(&m_docCharacter, GetOptionFilePath(2, false), 0, true, false);
    if (bRead == 0)
        EE_LOG_AT(1, 1, ("Failed to read %s", "CharacterOption.xml"), MS2_THIS_FILE, 0xad);
    FUN_141260ed0((struct Unk_GsAutoLoot*)(&m_autoLoot));
    FUN_141261780((struct Unk_GsEtc*)(&m_etc));
    FUN_14125c8b0(&m_statusChar);
    FUN_1412603b0(&m_soundChar);
    FUN_14125bc60(&m_interfaceChar);
    FUN_14125f2c0(&m_gamepad);
    if (LoadGameOptionAutoLooting((struct Unk_GsAutoLoot*)(&m_autoLoot), &m_docCharacter) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read m_autoLooting option");
    if (LoadGameOptionEtc((struct Unk_GsEtc*)(&m_etc), &m_docCharacter) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read m_etc option");
    if (FUN_14125c8d0(&m_statusChar, &m_docCharacter) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read m_statusCharacter option");
    if (FUN_1412603d0(&m_soundChar, &m_docCharacter) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read m_soundCharacter option");
    if (FUN_14125bc80(&m_interfaceChar, &m_docCharacter) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read m_interfaceCharacter option");
    if (LoadGameOptionGamepad(&m_gamepad, &m_docCharacter) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read m_gamePadOption option");
    if (FUN_14125c970(&m_statusChar, &m_docCharacter) != 0)
        SaveCharacterSettings();
    return GetFileSystem()->LoadXmlFile(&m_docCharacterDefault, GetOptionFilePath(2, true), 0, true, false);
}

// @0x141242f60
int CGameOption::LoadLanguageOption()
{
    if (IsNexonPlatform() == 0 && (unsigned char)g_bLanguageSet != 0)
        return 1;
    int bRead = 0;
    int bDefaulted = 0;
    TiXmlDocument doc;
    if (IsOptionFileMissingOrOutdated(0) != 0)
    {
        DeleteFileA(GetOptionFilePath(0, false));
        bRead = GetFileSystem()->LoadXmlFile(&doc, GetOptionFilePath(0, true), 0, true, false);
        bDefaulted = 1;
    }
    else
        bRead = GetFileSystem()->LoadXmlFile(&doc, GetOptionFilePath(0, false), 0, true, false);
    if (bRead == 0)
        EE_LOG_AT(1, 1, ("Failed to read %s", "GameOption.xml"), MS2_THIS_FILE, 0xe2);
    if (LoadGameOptionLanguage(&m_language, &doc) == 0)
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[E] Can not read language hide option");
    if (CFeatureManager::GetInstance()->IsRegionNA() && bDefaulted != 0)
    {
        LANGID nLang = GetUserDefaultUILanguage();
        m_language.m_nLanguage = GetLanguageFromLangId((short)nLang);
    }
    SetLanguage(m_language.m_nLanguage);
    SetVoice(m_language.m_nVoice);
    return 1;
}

// @0x1412432d0
void CGameOption::SaveGameSettings()
{
    SaveGameOptionCamera(&m_camera, &m_docGame);
    SaveGameOptionInterface(&m_interface, &m_docGame);
    SaveGameOptionStatus(&m_status, &m_docGame);
    SaveGameOptionBattle(&m_battle, &m_docGame);
    SaveGameOptionCommunityA(&m_communityA, &m_docGame);
    SaveGameOptionGraphic(&m_graphic, &m_docGame);
    SaveGameOptionSound(&m_sound, &m_docGame);
    SaveGameOptionConnect((struct Unk_GsConnect*)(&m_connect), &m_docGame);
    SaveGameOptionOptimizer(&m_graphic2, &m_docGame);
    SaveGameOptionLanguage(&m_language, &m_docGame);
    SaveGameOptionCommunityB(&m_account, &m_docAccount);
    SaveGameOptionChroma(&m_chroma, &m_docGame);
    WriteGameAndAccountFiles();
}

// @0x141243450
void CGameOption::WriteGameAndAccountFiles()
{
    SetOptionVersion(&m_docGame);
    SetOptionVersion(&m_docAccount);
    m_docGame.SaveFile(GetOptionFilePath(0, false));
    m_docAccount.SaveFile(GetOptionFilePath(1, false));
}

// @0x141243540
void CGameOption::SaveCharacterSettings()
{
    SaveGameOptionAutoLooting((struct Unk_GsAutoLoot*)(&m_autoLoot), &m_docCharacter);
    SaveGameOptionEtc((struct Unk_GsEtc*)(&m_etc), &m_docCharacter);
    FUN_14125c910(&m_statusChar, &m_docCharacter);
    FUN_141260410(&m_soundChar, &m_docCharacter);
    FUN_14125bcc0(&m_interfaceChar, &m_docCharacter);
    SaveGameOptionGamepad(&m_gamepad, &m_docCharacter);
    SetOptionVersion(&m_docCharacter);
    WriteCharacterFile();
}

// @0x141243630
void CGameOption::FUN_141243630()
{
    FILE* pFile = fopen(GetOptionFilePath(0, false), "r");
    if (pFile != 0)
    {
        long nSize = 0;
        fseek(pFile, 0, SEEK_END);
        nSize = ftell(pFile);
        fseek(pFile, 0, SEEK_SET);
        char* pBuf = new char[nSize + 2];
        memset(pBuf, 0, nSize + 2);
        fread(pBuf, nSize, 1, pFile);
        CString strText(pBuf);
        reinterpret_cast<CCrashManager*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_1401ce2b0(FUN_1409a23d0((const char*)strText, 0));
        delete[] pBuf;
        fclose(pFile);
    }
}

// @0x1412437e0
void CGameOption::WriteCharacterFile()
{
    m_docCharacter.SaveFile(GetOptionFilePath(2, false));
}

// @0x141243850
void CGameOption::FUN_141243850()
{
}

// @0x141243860
void CGameOption::FUN_141243860()
{
    FUN_14125fe20(FUN_140d13c70());
    SetBrightness(&m_graphic, m_graphic.m_n0c);
    FUN_14125ef90(&m_graphic2);
    TSingleton<CEffectService>::GetInstance()->FUN_1411a8880(m_graphic.m_nEffectStep);
}

// @0x1412438d0
void CGameOption::FUN_1412438d0()
{
}

// @0x1412438e0
void CGameOption::FUN_1412438e0()
{
}

// The benchmark rows: level -> bandwidth (unsigned) and level -> value.
// @0x1412438f0
int CGameOption::GetBenchmarkLevel()
{
    if (m_nBenchmark == -1)
    {
        m_nBenchmark = 0;
        unsigned __int64 nVideoMem = ((class Unk_GoGpuMgr*)GetOptimizer())->GetVideoMem();
        if (nVideoMem <= 0x800)
            m_nBenchmark = 0;
        else if (reinterpret_cast<Unk_GoDeviceInfo*>(TSingleton<GPUManager>::GetInstance())->GetVendor() == 2)
        {
            TiXmlDocument doc;
            if (GetFileSystem()->LoadXmlFile(&doc, "./Data/Xml/Table/benchmarkOption.xml", 0, true, false) != 0)
            {
                std::map<int, unsigned __int64> levels;
                void* pRoot = ((void*)((class Unk_XmlNode*)(void*)(&doc))->FirstChild("ms2"));
                if (pRoot != 0)
                {
                    for (void* pNode = ((void*)((class Unk_XmlNode*)(void*)(pRoot))->FirstChild("option")); pNode != 0; pNode = ((void*)((class Unk_XmlNode*)(void*)(pNode))->NextSibling("option")))
                    {
                        int nLevel = 0;
                        XmlGetAttr((class TiXmlElement*)(pNode), "level", nLevel);
                        int nBandWidth = 0;
                        XmlGetAttr((class TiXmlElement*)(pNode), "bandWidth", nBandWidth);
                        levels.insert(std::make_pair(nLevel, nBandWidth));
                    }
                }
                for (std::map<int, unsigned __int64>::iterator it = levels.begin(); it != levels.end(); ++it)
                {
                    m_nBenchmark = it->first;
                    if (reinterpret_cast<Unk_GoDeviceInfo*>(TSingleton<GPUManager>::GetInstance())->GetBandwidth() <= it->second)
                        break;
                }
            }
        }
        else
        {
            CStringW strNvidia(L"NVIDIA ");
            CStringW strName = reinterpret_cast<Unk_GoDeviceInfo*>(TSingleton<GPUManager>::GetInstance())->GetAdapterName();
            if (strName.Find(strNvidia, 0) != -1)
            {
                int nLen = strNvidia.GetLength();
                strName = (const wchar_t*)strName + nLen;
            }
            FUN_140841420(strName);
            int nValue = 0;
            TiXmlDocument docVga;
            if (GetFileSystem()->LoadXmlFile(&docVga, "./Data/Xml/Table/benchmark.xml", 0, true, false) != 0)
            {
                void* pRoot = ((void*)((class Unk_XmlNode*)(void*)(&docVga))->FirstChild("ms2"));
                if (pRoot != 0)
                {
                    for (void* pNode = ((void*)((class Unk_XmlNode*)(void*)(pRoot))->FirstChild("vga")); pNode != 0; pNode = ((void*)((class Unk_XmlNode*)(void*)(pNode))->NextSibling("vga")))
                    {
                        CStringW strVga = FUN_1401bf530((class TiXmlElement*)(pNode), "name", CStringW(L""));
                        if (strVga == strName)
                        {
                            XmlGetAttr((class TiXmlElement*)(pNode), "value", nValue);
                            break;
                        }
                    }
                }
            }
            if (nValue != 0)
            {
                TiXmlDocument docOption;
                if (GetFileSystem()->LoadXmlFile(&docOption, "./Data/Xml/Table/benchmarkOption.xml", 0, true, false) != 0)
                {
                    std::map<int, int> levels;
                    void* pRoot = ((void*)((class Unk_XmlNode*)(void*)(&docOption))->FirstChild("ms2"));
                    if (pRoot != 0)
                    {
                        for (void* pNode = ((void*)((class Unk_XmlNode*)(void*)(pRoot))->FirstChild("option")); pNode != 0; pNode = ((void*)((class Unk_XmlNode*)(void*)(pNode))->NextSibling("option")))
                        {
                            int nLevel = 0;
                            XmlGetAttr((class TiXmlElement*)(pNode), "level", nLevel);
                            int nLevelValue = 0;
                            XmlGetAttr((class TiXmlElement*)(pNode), "value", nLevelValue);
                            levels.insert(std::make_pair(nLevel, nLevelValue));
                        }
                    }
                    for (std::map<int, int>::iterator it = levels.begin(); it != levels.end(); ++it)
                    {
                        m_nBenchmark = it->first;
                        if (nValue <= it->second)
                            break;
                    }
                }
            }
            else
                m_nBenchmark = 1;
        }
    }
    return m_nBenchmark;
}

// @0x141243f50
unsigned int CGameOption::IsOptionFileMissingOrOutdated(int nKind)
{
    TiXmlDocument doc;
    CString strPath;
    if (nKind == 0)
        strPath = GetOptionFilePath(0, false);
    else if (nKind == 1)
        strPath = GetOptionFilePath(1, false);
    else if (nKind == 2)
        strPath = GetOptionFilePath(2, false);
    else
        return 1;
    int bLoaded = GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false);
    if (bLoaded == 0)
        return 1;
    void* pRoot = ((void*)DocRootElement(&doc));
    if (pRoot == 0)
        return 1;
    void* pOption = ((void*)((class Unk_XmlNode*)(void*)(pRoot))->FirstChild("option"));
    if (pOption == 0)
        return 1;
    int nVersion = 0;
    XmlGetAttr((class TiXmlElement*)(pOption), "version", nVersion);
    return nVersion != 0x15;
}

// @0x141244240
void CGameOption::SetBenchmarkLevel(int nLevel)
{
    if (m_nBenchmark != nLevel)
    {
        m_nBenchmark = nLevel;
        SetQuality(reinterpret_cast<Unk_GraphicState*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->GetGraphicOption()), nLevel, 1);
    }
}

// @0x1412442a0
TiXmlDocument* CGameOption::FUN_1412442a0()
{
    return &m_docGameDefault;
}

// @0x1412442c0
TiXmlDocument* CGameOption::FUN_1412442c0()
{
    return &m_docAccountDefault;
}

// @0x1412442e0
TiXmlDocument* CGameOption::GetGameDoc()
{
    return &m_docGame;
}

// @0x141244300
TiXmlDocument* CGameOption::GetCharacterDoc()
{
    return &m_docCharacter;
}

// Stamp the option version (0x15) on an option file's <option> element.
// @0x141244320
static void SetOptionVersion(TiXmlDocument* pDoc)
{
    void* pRoot = ((void*)DocRootElement(pDoc));
    if (pRoot != 0)
    {
        void* pOption = ((void*)((class Unk_XmlNode*)(void*)(pRoot))->FirstChild("option"));
        if (pOption == 0)
        {
            pOption = new TiXmlElement("option");
            ((void*)((class TiXmlNode*)(void*)(pRoot))->LinkEndChild((class TiXmlNode*)(pOption)));
        }
        CString strVersion;
        strVersion.Format("%d", 0x15);
        XmlSetAttr((class TiXmlElement*)(pOption), "version", strVersion);
    }
}

// @0x141248630
Unk_BattleState* CGameOption::FUN_141248630()
{
    return &m_battle;
}

// @0x141245b10
unsigned __int64 Unk_GoGpuMgr::GetVideoMem()
{
    return m_nVideoMem;
}

// @0x141245b00
int Unk_GoDeviceInfo::GetVendor()
{
    return m_nVendor;
}

// @0x141245aa0
unsigned __int64 Unk_GoDeviceInfo::GetBandwidth()
{
    return m_nBandwidth;
}

// @0x1412455e0
#pragma inline_depth(0)
Unk_GoConnect::~Unk_GoConnect()
{
}
#pragma inline_depth()

// @0x141246c20
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks (the tab pages; the CGameOption store functions stay unhooked) ----
MS2_REPLACE_METHOD(0x141246E70, CGameOptionBattle, vfunc_6, 2287, 0x22470429);
MS2_REPLACE_METHOD(0x141247770, CGameOptionBattle, vfunc_7, 2500, 0x217711C5);
MS2_REPLACE_METHOD(0x141248240, CGameOptionBattle, vfunc_14, 50, 0x4ECA3B1D);
MS2_REPLACE_METHOD(0x141248C40, CGameOptionCamera, vfunc_7, 707, 0x62410CDA);
MS2_REPLACE_METHOD(0x141248F10, CGameOptionCamera, vfunc_10, 671, 0xC5B4487D);
MS2_REPLACE_METHOD(0x141249270, CGameOptionCamera, vfunc_14, 50, 0x53642C2D);
MS2_REPLACE_METHOD(0x141249460, CGameOptionCommunity, vfunc_6, 2536, 0x2155A55C);
MS2_REPLACE_METHOD(0x141249E50, CGameOptionCommunity, vfunc_7, 2674, 0x7EBF1589);
MS2_REPLACE_METHOD(0x14124A8D0, CGameOptionCommunity, vfunc_10, 185, 0xAC6D6A49);
MS2_REPLACE_METHOD(0x14124AA70, CGameOptionCommunity, vfunc_14, 104, 0xF88DB113);
MS2_REPLACE_METHOD(0x14124AC90, CGameOptionGraphicDefault, vfunc_5, 852, 0x52F076F7);
MS2_REPLACE_METHOD(0x14124AFF0, CGameOptionGraphicDefault, vfunc_6, 3875, 0x0567FD04);
MS2_REPLACE_METHOD(0x14124BF20, CGameOptionGraphicDefault, vfunc_7, 3824, 0x07F7AC40);
MS2_REPLACE_METHOD(0x14124CE20, CGameOptionGraphicDefault, FUN_14124ce20, 592, 0xE7513A0F);
MS2_REPLACE_METHOD(0x14124D080, CGameOptionGraphicDefault, FillResolutionCombo, 1372, 0xEE8A49AB);
MS2_REPLACE_METHOD(0x14124D5F0, CGameOptionGraphicDefault, GetModeSize, 161, 0x5BC550DC);
MS2_REPLACE_METHOD(0x14124D6A0, CGameOptionGraphicDefault, vfunc_10, 240, 0xF49F03C5);
MS2_REPLACE_METHOD(0x14124D890, CGameOptionGraphicDefault, vfunc_14, 106, 0xDC755D9F);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cadf10-0x142cae070 .text$yd
// Full-executable aliases for the account and character option loaders.
// MS2-PIN: ?LoadAccountOption@CGameOption@@QEAAXXZ 0x141242570
// MS2-PIN: ?LoadCharacterOption@CGameOption@@QEAAXXZ 0x141242990
// MS2-PIN: ?FUN_141242570@Unk_SlOptionsHolder@@QEAAXXZ 0x141242570
// MS2-PIN: ?FUN_141242990@@YAXPEAX@Z 0x141242990
// MS2-PIN: ?FUN_141242990@Unk_ClUserMgr@@QEAAXXZ 0x141242990

