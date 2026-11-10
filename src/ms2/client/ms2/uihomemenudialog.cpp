// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeMenuDialog: the menu bar of the home / cube designer.
// MS2-UNIT: ?\uihomemenudialog.cpp
// MS2-RANGE: 0x1400cc770-0x1400ccb40 .text$di
// MS2-RANGE: 0x140c29160-0x140c2bc50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_keyInputA@@YAXXZ 0x1400cc9d0 ; guess
// MS2-PIN: ??__Es_keyInputB@@YAXXZ 0x1400ccb10 ; guess
// MS2-PIN: ??__Es_pointerA@@YAXXZ 0x1400cc960 ; the camera/mypc headers bring a look-alike initializer
// MS2-PIN: ??__Es_pointerB@@YAXXZ 0x1400ccaf0
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIHomeMenuDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140c2b6d0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIHomeMenuDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c2b9b0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIHomeMenuDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140c2ba10 ; unique
// MS2-PIN: ??$Call@VUIHomeMenuDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIHomeMenuDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIHomeMenuDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140c2ba50 ; unique
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihomemenudialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uihomemenudialog.h"
#include <vector>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include <efd/customalloc.h>
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/unnamed/unit_140fa9eb0.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/ugchomebgdata.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/client/ms2/uimeratmarketdialog.h"
#include "ms2/commonfiles/imagehttpclient.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (the exe runs them in this order: the first group, the three ui names, the second group) ----

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static CString s_strSortNamesA[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillA = "skill";
static CString s_strStunA = "stun";
static egf::EntityID s_pointerA(0);
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputA;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";
static CString s_strSkillB = "skill";
static CString s_strStunB = "stun";
static egf::EntityID s_pointerB(0);
static UICommon::CMyPCKeyInputController s_keyInputB;

// ---- unit-local views of exe types ----

class ASDialog : public ASDisplayObject {};

// The entity application framework (global at 0x143b059e8) and the cube service (class id 0x06100017).
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 egf::g_bapiContext

// The three-flag record of the cube service (ctor 0x140b68e60).
struct Unk_CMISFlags3
{
    Unk_CMISFlags3();
    bool a, b, c;
};


class CubeMapInformationService : public efd::ISystemService {   // C3: member view (the real header brings dynamic initializers)
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    bool FUN_1410c3600(int nRule);                                      // the mode (1 design, 3 blueprint) is active
    int FUN_1410c3650();                                                // the current mode
    bool FUN_1410d5530();                                               // the design has changes
    bool FUN_1410d5640();                                               // the player owns a home
    bool FUN_1410d56a0();                                               // the player may edit a home
    int FUN_1410ce310();                                                // the saved design slot (0: none)
    int CountCubes();                                                // the blueprints of the player
    CStringW FUN_1410c31d0();                                           // the home id
    CStringW FUN_1410c3260();                                           // the owner id
    Unk_CMISFlags3 FUN_1410c34f0();                                     // the camera / state bytes
};
//
class Unk_AkoHouseSvc   // C3: member view for the former free stand-in
{
public:
    static Unk_AkoHouseSvc* GetInstance();                              // the cube service singleton
};

// The local player.
class Unk_HmPc : public MyPC {
public:
};
class Unk_HmWorld;
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* GetLocalPlayer();
    static class WorldService* GetInstance();
};

// The UI manager.
class Unk_HmUiMgr {
public:
    void FUN_141adc530(int nId);                                        // show
};

class UIMeratMarketDialog* FUN_140bd2c00();   // C3: was FUN_140bd2c00
class Unk_HmOptions;
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager   // C3: member view for the former free stand-ins
{
public:
    bool IsFeatureEnabled(int);
};

// The game connection: slot 2 is the state, slot 54 sends the screenshot address.
class Unk_HmNet {
public:
    virtual void vfunc_0() = 0;
    virtual void vfunc_1() = 0;
    virtual int vfunc_2() = 0;
    virtual void vfunc_3() = 0;
    virtual void vfunc_4() = 0;
    virtual void vfunc_5() = 0;
    virtual void vfunc_6() = 0;
    virtual void vfunc_7() = 0;
    virtual void vfunc_8() = 0;
    virtual void vfunc_9() = 0;
    virtual void vfunc_10() = 0;
    virtual void vfunc_11() = 0;
    virtual void vfunc_12() = 0;
    virtual void vfunc_13() = 0;
    virtual void vfunc_14() = 0;
    virtual void vfunc_15() = 0;
    virtual void vfunc_16() = 0;
    virtual void vfunc_17() = 0;
    virtual void vfunc_18() = 0;
    virtual void vfunc_19() = 0;
    virtual void vfunc_20() = 0;
    virtual void vfunc_21() = 0;
    virtual void vfunc_22() = 0;
    virtual void vfunc_23() = 0;
    virtual void vfunc_24() = 0;
    virtual void vfunc_25() = 0;
    virtual void vfunc_26() = 0;
    virtual void vfunc_27() = 0;
    virtual void vfunc_28() = 0;
    virtual void vfunc_29() = 0;
    virtual void vfunc_30() = 0;
    virtual void vfunc_31() = 0;
    virtual void vfunc_32() = 0;
    virtual void vfunc_33() = 0;
    virtual void vfunc_34() = 0;
    virtual void vfunc_35() = 0;
    virtual void vfunc_36() = 0;
    virtual void vfunc_37() = 0;
    virtual void vfunc_38() = 0;
    virtual void vfunc_39() = 0;
    virtual void vfunc_40() = 0;
    virtual void vfunc_41() = 0;
    virtual void vfunc_42() = 0;
    virtual void vfunc_43() = 0;
    virtual void vfunc_44() = 0;
    virtual void vfunc_45() = 0;
    virtual void vfunc_46() = 0;
    virtual void vfunc_47() = 0;
    virtual void vfunc_48() = 0;
    virtual void vfunc_49() = 0;
    virtual void vfunc_50() = 0;
    virtual void vfunc_51() = 0;
    virtual void vfunc_52() = 0;
    virtual void vfunc_53() = 0;
    virtual int vfunc_54(CStringW strOwner, CStringW strName, int nType, CStringW strUrl) = 0;
};
class IClientPlatform* GetClientPlatform();   // C3: was void* FUN_140d86260()

// The render service: each of its render contexts is drawn once with the current time (camera.h brings <ecr/RenderService.h>).
class Unk_ServiceManager;
Unk_ServiceManager*GetServiceManager();
ecr::RenderService* GetRenderService();

// A child of the movie (a button or a check box), held through MS2Ptr (dtor 0x140acd6e0).
// C3: Unk_140acd6e0 (the button view) is ASButton itself.
//
//
class Unk_HmMovieEntity : public UIDialog {
public:
};

bool FUN_141902580(bool bMessage);
bool IsBlueprintShopAvailable(bool bMessage);
unsigned char FUN_140930c50();
int FUN_1418fd280();
void FUN_141275260(int nId, int a, int b);
void FUN_14151f200();
CStringW TakeScreenshotJpg(int a, int b);
void FUN_140710590(COutPacket& packet);

MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
MS2Ptr<CMsgBoxData> CreateMessageBox(int nType, CStringW strText, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* p, CStringW strTag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
CStringW GetStringCommonByKey(const CStringW& str);
CStringW GetStringCommon(int nId);

UIHomeSaveSlotDialog* GetHomeSaveSlotDialog(int nUiId);

// @0x140c29160
UIHomeMenuDialog::UIHomeMenuDialog() : m_bFreeCamera(0)
{
    m_80 = 0;
    m_88 = 1;
    FUN_1422dc3b0(1);
    SetFlag(0, 1);
    m_screenshot.SetMode(0);
}

// @0x140c29230
UIHomeMenuDialog::~UIHomeMenuDialog()
{
}

// @0x140c29280
CString UIHomeMenuDialog::GetTypeName()
{
    return CString("HomeMenuDialog");
}

// @0x140c292d0
void UIHomeMenuDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_bFreeCamera = 0;
}

// @0x140c29300
void UIHomeMenuDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Refresh(IsCraftMode());
}

// @0x140c2b8e0
int UIHomeMenuDialog::vfunc_48()
{
    return 0x4f7c;
}

// @0x140c29340
int UIHomeMenuDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("ToggleCraftMode", szMethod) == 0)
    {
        ToggleCraftMode();
        return 1;
    }
    else if (_stricmp("ToggleDesignMode", szMethod) == 0)
    {
        ToggleDesignMode();
        return 1;
    }
    else if (_stricmp("ToggleBlueprintMode", szMethod) == 0)
    {
        ToggleBlueprintMode();
        return 1;
    }
    else if (_stricmp("OnScreenshot", szMethod) == 0)
    {
        OnScreenshot();
        return 1;
    }
    else if (_stricmp("OnFreeCamera", szMethod) == 0)
    {
        OnFreeCamera();
        return 1;
    }
    else if (_stricmp("OnDesignSave", szMethod) == 0)
    {
        OnDesignSave();
        return 1;
    }
    else if (_stricmp("OnDesignLoad", szMethod) == 0)
    {
        OnDesignLoad();
        return 1;
    }
    else if (_stricmp("OnBlueprintSave", szMethod) == 0)
    {
        OnBlueprintSave();
        return 1;
    }
    else if (_stricmp("OnHomePriority", szMethod) == 0)
    {
        OnHomePriority();
        return 1;
    }
    else if (_stricmp("OnHomeAttribute", szMethod) == 0)
    {
        OnHomeAttribute();
        return 1;
    }
    else if (_stricmp("OnHomeDemolish", szMethod) == 0)
    {
        OnHomeDemolish();
        return 1;
    }
    else if (_stricmp("OnBlueprintImport", szMethod) == 0)
    {
        OnBlueprintImport();
        return 1;
    }
    else if (_stricmp("OnBlueprintExport", szMethod) == 0)
    {
        OnBlueprintExport();
        return 1;
    }
    else if (_stricmp("OnBlueprintShop", szMethod) == 0)
    {
        OnBlueprintShop();
        return 1;
    }
    return 1;
}

// @0x140c29600
void UIHomeMenuDialog::Refresh(bool bCraft)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
        pDialog->Invoke("setState", GetStateFrameName());
    if (bCraft)
        SetFreeCamera(0);
    FUN_140c2a780();
    vfunc_43();
}

// @0x140c296e0
void UIHomeMenuDialog::FUN_140c296e0(bool bCraft)
{
    Refresh(bCraft);
}

// @0x140c29710
void UIHomeMenuDialog::ToggleDesignMode()
{
    Unk_HmPc* pPc = ((class Unk_HmPc*)((class WorldService*)(class Unk_HmWorld*)(((class Unk_HmWorld*)WorldService::GetInstance())))->GetLocalPlayer());
    if (pPc == 0)
        return;
    {
        efd::SmartPointer<CubeMapInformationService> spService((CubeMapInformationService*)egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
        if (spService != 0)
        {
            if (spService->FUN_1410d5640() == 0 && spService->FUN_1410d56a0() == 0)
            {
                FUN_141275260(0x6e1, 1, 1);
                return;
            }
        }
        if (((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(1) != 0)
        {
            if (((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d5530() != 0)
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommonByKey(L"s_home_info_exit_messagebox_save"), 1);
                reinterpret_cast<CMsgBoxData*>(spBox.operator->())->FUN_141a024a0(0);
                spBox->SetButtonPreset(1);
                spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::OnLeaveDesignResult));
                FUN_140d73c60(spBox);
            }
            else
                pPc->SendRequestMoveFieldMode3();
        }
        else
            pPc->SendRequestMoveFieldMode4();
    }
}

// @0x140c29980
void UIHomeMenuDialog::ToggleBlueprintMode()
{
    if (!FUN_141902580(1))
        return;
    Unk_HmPc* pPc = ((class Unk_HmPc*)((class WorldService*)(class Unk_HmWorld*)(((class Unk_HmWorld*)WorldService::GetInstance())))->GetLocalPlayer());
    if (pPc == 0)
        return;
    if (((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(3) != 0)
    {
        if (((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d5530() != 0)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommonByKey(L"s_home_info_exit_blueprint_messagebox_save"), 1);
            reinterpret_cast<CMsgBoxData*>(spBox.operator->())->FUN_141a024a0(0);
            spBox->SetButtonPreset(1);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::OnLeaveDesignResult));
            FUN_140d73c60(spBox);
        }
        else
            pPc->SendRequestMoveFieldMode3();
    }
    else
        pPc->SendRequestMoveFieldMode5();
}

// @0x140c29b70
void UIHomeMenuDialog::FUN_140c29b70()
{
    OnHomePriority();
}

// @0x140c29b90
void UIHomeMenuDialog::ToggleCraftMode()
{
    Unk_HmPc* pPc = ((class Unk_HmPc*)((class WorldService*)(class Unk_HmWorld*)(((class Unk_HmWorld*)WorldService::GetInstance())))->GetLocalPlayer());
    if (pPc == 0)
        return;
    int nOwner = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d5640();
    int nDesign = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(1);
    int nBlueprint = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(3);
    if (nOwner != 0 || nDesign != 0 || nBlueprint != 0 || FUN_140930c50() != 0)
    {
        if (IsCraftMode() != 0)
            pPc->SendCraftModeOff();
        else
            pPc->FUN_14152feb0(1, 0);
    }
    else
        FUN_141275260(0x6e1, 1, 1);
}

// @0x140c29c70
void UIHomeMenuDialog::OnScreenshot()
{
    if (((class Unk_HmNet*)((void*)GetClientPlatform()))->vfunc_2() == 1)
    {
        if (MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommonByKey(L"s_msg_ugc_home_upload_screenshot"), 0, CStringW(L"")))
        {
            reinterpret_cast<CMsgBoxData*>(spBox.operator->())->FUN_141a024a0(0);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::FUN_140c2b180));
            FUN_140d73c60(spBox);
        }
    }
    else
    {
        TakeScreenshot();
    }
}

// @0x140c29eb0
void UIHomeMenuDialog::OnFreeCamera()
{
    SetFreeCamera(m_bFreeCamera == 0);
}

// @0x140c29ef0
void UIHomeMenuDialog::OnDesignSave()
{
    UIHomeSaveSlotDialog* pDialog = GetHomeSaveSlotDialog(0x4f27);
    if (pDialog == 0)
        return;
    unsigned nCount = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410ce310();
    if (nCount > 0)
    {
        if (MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommon(0xbb1), 0, CStringW(L"")))
        {
            reinterpret_cast<CMsgBoxData*>(spBox.operator->())->FUN_141a024a0(0);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::FUN_140c2b0e0));
            FUN_140d73c60(spBox);
        }
    }
    else
        pDialog->SetSaveMode();
}

// @0x140c2a0e0
void UIHomeMenuDialog::OnDesignLoad()
{
    UIHomeSaveSlotDialog* pDialog = GetHomeSaveSlotDialog(0x4f27);
    if (pDialog != 0)
        pDialog->SetLoadMode();
}

// @0x140c2a120
void UIHomeMenuDialog::OnBlueprintSave()
{
    if (!FUN_141902580(1))
        return;
    UIHomeSaveSlotDialog* pDialog = GetHomeSaveSlotDialog(0x4f27);
    if (pDialog == 0)
        return;
    unsigned nCount = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410ce310();
    if (nCount > 0)
    {
        if (MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommon(0xbb1), 0, CStringW(L"")))
        {
            reinterpret_cast<CMsgBoxData*>(spBox.operator->())->FUN_141a024a0(0);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::FUN_140c2b130));
            FUN_140d73c60(spBox);
        }
    }
    else
        pDialog->SetSaveMode();
}

// @0x140c2a320
void UIHomeMenuDialog::OnBlueprintImport()
{
    if (!FUN_141902580(1))
        return;
    UIHomeSaveSlotDialog* pDialog = GetHomeSaveSlotDialog(0x4f27);
    if (pDialog != 0)
        pDialog->SetLoadMode();
}

// @0x140c2a370
void UIHomeMenuDialog::OnHomePriority()
{
    int nOwner = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d5640();
    int nDesign = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(1);
    int nBlueprint = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(3);
    if (nOwner != 0 || nDesign != 0 || nBlueprint != 0)
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4f26)));
    else
        FUN_141275260(0x6e1, 1, 1);
}

// @0x140c2a410
void UIHomeMenuDialog::OnHomeAttribute()
{
    int nOwner = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d5640();
    int nDesign = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(1);
    int nBlueprint = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(3);
    if (nOwner != 0 || nDesign != 0 || nBlueprint != 0)
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4f7a)));
    else
        FUN_141275260(0x6e1, 1, 1);
}

// @0x140c2a4b0
void UIHomeMenuDialog::OnHomeDemolish()
{
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x1f, 0x6e2, 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->SetButtonPreset(2);
        ((class CMsgBoxData*)(class CMsgBoxData*)(spBox.operator->()))->SetCheckbox0(GetStringCommon(0x9d1), 0);
        ((class CMsgBoxData*)(class CMsgBoxData*)(spBox.operator->()))->SetAgreement(0);
        ((class CMsgBoxData*)(class CMsgBoxData*)(spBox.operator->()))->SetSize(0x1c0, 400);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::SendRequestCube));
        FUN_140d73c60(spBox);
    }
}

// @0x140c2a6a0
void UIHomeMenuDialog::OnBlueprintExport()
{
    if (!FUN_141902580(1))
        return;
    if (((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->CountCubes() > 0)
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4f7b)));
    else
        FUN_140d73bc0(0xbba, 0, 0, CStringW(L""));
}

// @0x140c2a720
void UIHomeMenuDialog::OnBlueprintShop()
{
    if (!IsBlueprintShopAvailable(1))
        return;
    UIMeratMarketDialog* pMenu = ((class UIMeratMarketDialog*)FUN_140bd2c00());
    if (pMenu != 0)
    {
        int nA = 0xcc;
        int nB = 3;
        pMenu->SearchByCategory(nB, nA);
    }
}

// @0x140c2a780
void UIHomeMenuDialog::FUN_140c2a780()
{
    int bCraft = IsCraftMode();
    int bDesign = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(1);
    int bBlueprint = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3600(3);
    if (MS2Ptr<ASButton> sp = ((Unk_HmMovieEntity*)this)->GetChild<ASButton>("m_craftMode"))
    {
        sp->SetSelected(bCraft);
    }
    if (MS2Ptr<ASButton> sp = ((Unk_HmMovieEntity*)this)->GetChild<ASButton>("m_designMode"))
    {
        sp->SetSelected(bDesign);
        if (bBlueprint != 0)
            reinterpret_cast<MS2Ptr<ASMovieClip>&>(sp)->SetEnabled(0);
    }
    if (MS2Ptr<ASButton> sp = ((Unk_HmMovieEntity*)this)->GetChild<ASButton>("m_blueprintMode"))
    {
        sp->SetSelected(bBlueprint);
        reinterpret_cast<MS2Ptr<ASMovieClip>&>(sp)->SetEnabled(FUN_141902580(0));
        if (bDesign != 0)
            reinterpret_cast<MS2Ptr<ASMovieClip>&>(sp)->SetEnabled(0);
    }
    if (MS2Ptr<ASButton> sp = ((Unk_HmMovieEntity*)this)->GetChild<ASButton>("m_freeCamera"))
    {
        sp->SetSelected(TSingleton<CameraMgr>::GetInstance()->GetModeType() == 1);
    }
    if (MS2Ptr<ASButton> sp = ((Unk_HmMovieEntity*)this)->GetChild<ASButton>("m_blueprintSave"))
    {
        reinterpret_cast<MS2Ptr<ASMovieClip>&>(sp)->SetEnabled(FUN_141902580(0));
    }
    if (MS2Ptr<ASButton> sp = ((Unk_HmMovieEntity*)this)->GetChild<ASButton>("m_blueprintImport"))
    {
        reinterpret_cast<MS2Ptr<ASMovieClip>&>(sp)->SetEnabled(FUN_141902580(0));
    }
    if (MS2Ptr<ASButton> sp = ((Unk_HmMovieEntity*)this)->GetChild<ASButton>("m_blueprintExport"))
    {
        reinterpret_cast<MS2Ptr<ASMovieClip>&>(sp)->SetEnabled(FUN_141902580(0));
    }
    if (MS2Ptr<ASButton> sp = ((Unk_HmMovieEntity*)this)->GetChild<ASButton>("m_blueprintShop"))
    {
        reinterpret_cast<MS2Ptr<ASMovieClip>&>(sp)->SetEnabled(IsBlueprintShopAvailable(0));
    }
}

// @0x140c2ad90
CString UIHomeMenuDialog::GetStateFrameName()
{
    bool bCraft = IsCraftMode();
    if (FUN_1418fd280() == 0)
        return CString(bCraft ? "other_craft" : "other");
    switch (((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3650())
    {
    case 0:
        return CString(bCraft ? "default_craft" : "default");
    case 1:
        return CString(bCraft ? "design_craft" : "design");
    case 3:
        return CString(bCraft ? "blueprint_craft" : "blueprint");
    case 2:
        return CString("other");
    }
    return CString("default");
}

// @0x140c2af70
bool UIHomeMenuDialog::IsCraftMode()
{
    Unk_HmPc* pPc = ((class Unk_HmPc*)((class WorldService*)(class Unk_HmWorld*)(((class Unk_HmWorld*)WorldService::GetInstance())))->GetLocalPlayer());
    if (pPc == 0)
        return false;
    bool bCraft;
    if (pPc->IsInCubeMode() != 0)
        bCraft = true;
    else
        bCraft = false;
    return bCraft;
}

// @0x140c2afd0
void UIHomeMenuDialog::SetFreeCamera(bool bFreeCamera)
{
    m_bFreeCamera = bFreeCamera;
    if (m_bFreeCamera)
    {
        TSingleton<CameraMgr>::GetInstance()->SetPendingMode(6);
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4f3e)));
    }
    else
    {
        Unk_CMISFlags3 state = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c34f0();
        Unk_CMISFlags3* pState = &state;
        TSingleton<UgcHomeOptionData>::GetInstance()->ApplyCamera(pState->c);
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4f3e);
    }
}

// @0x140c2b080
// The exe widens the discarded BeginImage() flag (movzx) before the screenshot call: a ?: on it with empty arms.
CStringW UIHomeMenuDialog::TakeScreenshot()
{
    return TakeScreenshotJpg((m_screenshot.BeginImage() ? (void)0 : (void)0, 0), 1);
}

// @0x140c2b0e0
bool UIHomeMenuDialog::FUN_140c2b0e0(int nResult, const CMsgBoxData& data)
{
    FUN_14151f200();
    if (nResult == 0)
    {
        UIHomeSaveSlotDialog* pDialog = GetHomeSaveSlotDialog(0x4f27);
        if (pDialog != 0)
            pDialog->SetSaveMode();
        return 1;
    }
    return 1;
}

// @0x140c2b130
bool UIHomeMenuDialog::FUN_140c2b130(int nResult, const CMsgBoxData& data)
{
    FUN_14151f200();
    if (nResult == 0)
    {
        UIHomeSaveSlotDialog* pDialog = GetHomeSaveSlotDialog(0x4f27);
        if (pDialog != 0)
            pDialog->SetSaveMode();
        return 1;
    }
    return 1;
}

// @0x140c2b180
bool UIHomeMenuDialog::FUN_140c2b180(int nResult, const CMsgBoxData& data)
{
    efd::ServiceManager* pServices = reinterpret_cast<efd::ServiceManager *>(GetServiceManager());
    if (pServices == 0)
        return 0;
    ecr::RenderService* pRender = GetRenderService();
    if (pRender == 0)
        return 0;
    float fTime = (float)pServices->GetTime(0xe001001b);
    for (unsigned int i = 0; i < pRender->GetRenderContextCount(); ++i)
    {
        ecr::RenderContext* pContext = pRender->GetRenderContextAt(i);
        if (pContext == 0)
            continue;
        pContext->Draw(fTime);
    }
    CStringW strUrl = TakeScreenshot();
    if (nResult == 0 && !strUrl.IsEmpty())
    {
        if (((class Unk_HmNet*)((void*)GetClientPlatform()))->vfunc_54(((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c31d0(), ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3260(), 0xd0, CStringW(strUrl)) == 1)
            FUN_141275260(0x466, 1, 1);
    }
    return 1;
}

// @0x140c2b390
bool UIHomeMenuDialog::OnLeaveDesignResult(int nResult, const CMsgBoxData& data)
{
    Unk_HmPc* pPc = ((class Unk_HmPc*)((class WorldService*)(class Unk_HmWorld*)(((class Unk_HmWorld*)WorldService::GetInstance())))->GetLocalPlayer());
    if (pPc == 0)
        return false;
    if (nResult == 0)
        pPc->SendRequestMoveFieldMode3();
    return true;
}

// @0x140c2b3e0
bool UIHomeMenuDialog::SendRequestCube(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        if (((class CFeatureManager*)(class Unk_HmOptions*)(((class Unk_HmOptions*)FUN_140166410())))->IsFeatureEnabled(0xd4))
        {
            Unk_HmPc* pPc = ((class Unk_HmPc*)((class WorldService*)(class Unk_HmWorld*)(((class Unk_HmWorld*)WorldService::GetInstance())))->GetLocalPlayer());
            if (pPc != 0)
                pPc->FUN_14152f3c0();
        }
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.WriteUInt8(0x1f);
        FUN_140710590(packet);
    }
    return 1;
}

// @0x140c2b5c0
UIHomeSaveSlotDialog* GetHomeSaveSlotDialog(int nUiId)
{
    if (reinterpret_cast<Unk_HmUiMgr*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spUI = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIHomeSaveSlotDialog*>(spUI.operator->());
    }
    return 0;
}

MS2_REPLACE_METHOD(0x140C29280, UIHomeMenuDialog, GetTypeName, 61, 0x70D7F679);
MS2_REPLACE_METHOD(0x140C292D0, UIHomeMenuDialog, vfunc_67, 36, 0x14D88D62);
MS2_REPLACE_METHOD(0x140C29300, UIHomeMenuDialog, OnLoadComplete, 47, 0xBCD25300);
MS2_REPLACE_METHOD(0x140C29340, UIHomeMenuDialog, vfunc_28, 635, 0xD5372608);
MS2_REPLACE_METHOD(0x140C29600, UIHomeMenuDialog, Refresh, 218, 0x305104E7);
MS2_REPLACE_METHOD(0x140C296E0, UIHomeMenuDialog, FUN_140c296e0, 33, 0xE4BD1406);
MS2_REPLACE_METHOD(0x140C29710, UIHomeMenuDialog, ToggleDesignMode, 618, 0x8B85C660);
MS2_REPLACE_METHOD(0x140C29980, UIHomeMenuDialog, ToggleBlueprintMode, 488, 0x5ECA9653);
MS2_REPLACE_METHOD(0x140C29B70, UIHomeMenuDialog, FUN_140c29b70, 24, 0x413B21C4);
MS2_REPLACE_METHOD(0x140C29B90, UIHomeMenuDialog, ToggleCraftMode, 218, 0xA1886146);
MS2_REPLACE_METHOD(0x140C29C70, UIHomeMenuDialog, OnScreenshot, 556, 0x193700AE);
MS2_REPLACE_METHOD(0x140C29EB0, UIHomeMenuDialog, OnFreeCamera, 57, 0x420FC186);
MS2_REPLACE_METHOD(0x140C29EF0, UIHomeMenuDialog, OnDesignSave, 483, 0x703B3C0F);
MS2_REPLACE_METHOD(0x140C2A0E0, UIHomeMenuDialog, OnDesignLoad, 47, 0x7B159DEE);
MS2_REPLACE_METHOD(0x140C2A120, UIHomeMenuDialog, OnBlueprintSave, 502, 0x096C4D7E);
MS2_REPLACE_METHOD(0x140C2A320, UIHomeMenuDialog, OnBlueprintImport, 63, 0x0E56A387);
MS2_REPLACE_METHOD(0x140C2A370, UIHomeMenuDialog, OnHomePriority, 146, 0xC79F8E23);
MS2_REPLACE_METHOD(0x140C2A410, UIHomeMenuDialog, OnHomeAttribute, 146, 0x470E4BF0);
MS2_REPLACE_METHOD(0x140C2A4B0, UIHomeMenuDialog, OnHomeDemolish, 483, 0xA3344874);
MS2_REPLACE_METHOD(0x140C2A6A0, UIHomeMenuDialog, OnBlueprintExport, 120, 0x5611FBB3);
MS2_REPLACE_METHOD(0x140C2A720, UIHomeMenuDialog, OnBlueprintShop, 84, 0x8248B6DD);
MS2_REPLACE_METHOD(0x140C2A780, UIHomeMenuDialog, FUN_140c2a780, 1536, 0xE9239341);
MS2_REPLACE_METHOD(0x140C2AD90, UIHomeMenuDialog, GetStateFrameName, 463, 0x80C9D8EE);
MS2_REPLACE_METHOD(0x140C2AF70, UIHomeMenuDialog, IsCraftMode, 75, 0xBA03C06A);
MS2_REPLACE_METHOD(0x140C2AFD0, UIHomeMenuDialog, SetFreeCamera, 156, 0x306CA93D);
MS2_REPLACE_METHOD(0x140C2B080, UIHomeMenuDialog, TakeScreenshot, 83, 0xB948A457);
MS2_REPLACE_METHOD(0x140C2B0E0, UIHomeMenuDialog, FUN_140c2b0e0, 74, 0x0CFB8B11);
MS2_REPLACE_METHOD(0x140C2B130, UIHomeMenuDialog, FUN_140c2b130, 74, 0xB6DDA79C);
MS2_REPLACE_METHOD(0x140C2B180, UIHomeMenuDialog, FUN_140c2b180, 518, 0x78CE4CA7);
MS2_REPLACE_METHOD(0x140C2B390, UIHomeMenuDialog, OnLeaveDesignResult, 72, 0xF9694F52);
MS2_REPLACE_METHOD(0x140C2B3E0, UIHomeMenuDialog, SendRequestCube, 157, 0x84739265);
MS2_REPLACE(0x140C2B5C0, GetHomeSaveSlotDialog, 147, 0xE2946EBD);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca27e0-0x142ca2950 .text$yd
