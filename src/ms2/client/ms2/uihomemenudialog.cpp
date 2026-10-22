// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeMenuDialog: the menu bar of the home / cube designer.
// MS2-UNIT: ?\uihomemenudialog.cpp
// MS2-RANGE: 0x1400cc770-0x1400ccb40 .text$di
// MS2-RANGE: 0x140c29160-0x140c2bc50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVUnk_HmTicker@@V?$allocator@PEAVUnk_HmTicker@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVUnk_HmTicker@@@std@@@2@XZ 0x140c2b8f0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@PEAVUnk_HmTicker@@@std@@V?$_Vector_val@U?$_Simple_types@PEAVUnk_HmTicker@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVUnk_HmTicker@@@std@@@2@XZ 0x140c2b940 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_keyInputA@@YAXXZ 0x1400cc9d0 ; guess
// MS2-PIN: ??__Es_keyInputB@@YAXXZ 0x1400ccb10 ; guess
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

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (the exe runs them in this order: the first group, the three ui names, the second group) ----

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
static CString s_strSortNamesA[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillA = "skill";
static CString s_strStunA = "stun";
static Unk_1401cd100 s_pointerA(NULL);
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputA;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";
static CString s_strSkillB = "skill";
static CString s_strStunB = "stun";
static Unk_1401cd100 s_pointerB(NULL);
static UICommon::CMyPCKeyInputController s_keyInputB;

// ---- unit-local views of exe types ----

class ASDialog : public ASDisplayObject {};

// The entity application framework (global at 0x143b059e8) and the cube service (class id 0x06100017).
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;

class Unk_HmStateBytes
{
public:
    Unk_HmStateBytes();
    unsigned char m_b[8];
};

// Two small records of the cube service (passed by value to the connection).
class Unk_HmArgA { public: Unk_HmArgA(const Unk_HmArgA&); char m_pad[0x18]; };
class Unk_HmArgB { public: Unk_HmArgB(const Unk_HmArgB&); char m_pad[0x10]; };

class Unk_HmCubeSvc : public efd::ISystemService {
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    bool FUN_1410c3600(int nRule);                                      // the mode (1 design, 3 blueprint) is active
    int FUN_1410c3650();                                                // the current mode
    bool FUN_1410d5530();                                               // the design has changes
    bool FUN_1410d5640();                                               // the player owns a home
    bool FUN_1410d56a0();                                               // the player may edit a home
    int FUN_1410ce310();                                                // the saved design slot (0: none)
    int FUN_1410b9a50();                                                // the blueprints of the player
    Unk_HmArgA FUN_1410c31d0();                                         // the home id
    Unk_HmArgB FUN_1410c3260();                                         // the owner id
    Unk_HmStateBytes FUN_1410c34f0();                                   // the camera / state bytes
};
Unk_HmCubeSvc* FUN_1401cd040(Unk_EntityAppFramework* framework);
Unk_HmCubeSvc* FUN_1409670e0();

// The local player.
class Unk_HmPc {
public:
    void FUN_141529d90();                                               // leave the design mode
    void FUN_141529e90();                                               // leave the blueprint mode
    void FUN_14152a040();                                               // leave without saving
    void FUN_14152feb0(int nMode, int nFlag);                           // enter the craft mode
    void FUN_141530200();                                               // leave the craft mode
    void FUN_14152f3c0();                                               // demolish the home
    int FUN_1416595d0();                                                // the craft state
};
class Unk_HmWorld;
Unk_HmWorld* FUN_1403ed2d0();
Unk_HmPc* FUN_141bd0cc0(Unk_HmWorld*);

// The UI manager.
class Unk_HmUiMgr {
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
    void FUN_141adc530(int nId);                                        // show
    void FUN_141adc5d0(int nId);                                        // hide
    void FUN_141adc750(int nId);                                        // toggle
};
Unk_HmUiMgr* FUN_1403ed2b0();

class Unk_HmSingleton { public: void FUN_140b683f0(unsigned char n); };
Unk_HmSingleton* FUN_140b6a040();
class Unk_HmCamera { public: void FUN_140947980(int nMode); int FUN_140af7e30(); };
Unk_HmCamera* FUN_1409478c0();
class Unk_HmWorldMenu { public: void FUN_14130fb10(const int* pnA, const int* pnB); };
Unk_HmWorldMenu* FUN_140bd2c00();
class Unk_HmOptions;
Unk_HmOptions* FUN_140166410();
bool FUN_14036d570(Unk_HmOptions*, int nOption);

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
    virtual int vfunc_54(Unk_HmArgA a, Unk_HmArgB b, int nType, CStringW strUrl) = 0;
};
Unk_HmNet* FUN_140d86260();

// The scene updaters: the render service keeps a list of objects that get the frame time.
class Unk_HmTicker {
public:
    virtual void vfunc_0() = 0;
    virtual void vfunc_1(float fTime) = 0;
};
class Unk_HmRender {
public:
    unsigned int FUN_140c2b8c0() { return (unsigned int)m_list.size(); }
    Unk_HmTicker* FUN_140c2b890(unsigned int nIndex);
    char m_pad[0x30];
    std::vector<Unk_HmTicker*> m_list;                                  // +0x30
};
// @0x140c2b890
inline Unk_HmTicker* Unk_HmRender::FUN_140c2b890(unsigned int nIndex) { return m_list[nIndex]; }
efd::ServiceManager* FUN_1413f9850();
Unk_HmRender* FUN_1413f9890();

// A child of the movie (a button or a check box): handle at +8, the dtor sits at 0x140acd6e0.
class Unk_HmButton {
public:
    void FUN_1422c1fe0(int enabled);
    void FUN_1422ce090(int checked);
};
class Unk_HmHandle {
public:
    Unk_HmButton* FUN_140acd9c0();
    Unk_HmButton* FUN_140acd9e0();
    void FUN_140acd6e0();
};
class Unk_HmMovieEntity : public UIDialog {
public:
    Unk_HmHandle FUN_140bb4b10(const CString& strName);
};

bool FUN_141902580(bool bMessage);
bool FUN_1419025f0(bool bMessage);
bool FUN_140930c50();
int FUN_1418fd280();
void FUN_141275260(int nId, int a, int b);
void FUN_14151f200();
CStringW FUN_141850100(int a, int b, bool c);
void FUN_140710590(COutPacket& packet);

MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* p, CStringW strTag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
CStringW GetStringCommonByKey(const CStringW& str);
CStringW GetStringCommon(int nId);
void FUN_141a024a0(CMsgBoxData* pBox, bool b);
void FUN_141a024e0(CMsgBoxData* pBox, CStringW str, bool b);
void FUN_141a02730(CMsgBoxData* pBox, bool b);
void FUN_141a02770(CMsgBoxData* pBox, int nWidth, int nHeight);

UIHomeSaveSlotDialog* FUN_140c2b5c0(int nUiId);

// @0x140c29160
UIHomeMenuDialog::UIHomeMenuDialog() : m_bFreeCamera(0)
{
    m_80 = 0;
    m_88 = 1;
    FUN_1422dc3b0(1);
    FUN_141925e70(0, 1);
    m_screenshot.FUN_140511190(0);
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
    FUN_140c29600(FUN_140c2af70());
}

// @0x140c2b8e0
int UIHomeMenuDialog::vfunc_48()
{
    return 0x4f7c;
}

// @0x140c29340
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
int UIHomeMenuDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) == 0)
    {
        if (_stricmp("ToggleCraftMode", szMethod) == 0)
            ToggleCraftMode();
        else if (_stricmp("ToggleDesignMode", szMethod) == 0)
            FUN_140c29710();
        else if (_stricmp("ToggleBlueprintMode", szMethod) == 0)
            FUN_140c29980();
        else if (_stricmp("OnScreenshot", szMethod) == 0)
            OnScreenshot();
        else if (_stricmp("OnFreeCamera", szMethod) == 0)
            OnFreeCamera();
        else if (_stricmp("OnDesignSave", szMethod) == 0)
            OnDesignSave();
        else if (_stricmp("OnDesignLoad", szMethod) == 0)
            OnDesignLoad();
        else if (_stricmp("OnBlueprintSave", szMethod) == 0)
            OnBlueprintSave();
        else if (_stricmp("OnHomePriority", szMethod) == 0)
            OnHomePriority();
        else if (_stricmp("OnHomeAttribute", szMethod) == 0)
            OnHomeAttribute();
        else if (_stricmp("OnHomeDemolish", szMethod) == 0)
            OnHomeDemolish();
        else if (_stricmp("OnBlueprintImport", szMethod) == 0)
            OnBlueprintImport();
        else if (_stricmp("OnBlueprintExport", szMethod) == 0)
            OnBlueprintExport();
        else if (_stricmp("OnBlueprintShop", szMethod) == 0)
            OnBlueprintShop();
    }
    return 1;
}

// @0x140c29600
void UIHomeMenuDialog::FUN_140c29600(bool bCraft)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
        pDialog->Invoke("setState", FUN_140c2ad90());
    if (bCraft)
        FUN_140c2afd0(0);
    FUN_140c2a780();
    vfunc_43();
}

// @0x140c296e0
void UIHomeMenuDialog::FUN_140c296e0(bool bCraft)
{
    FUN_140c29600(bCraft);
}

// @0x140c29710
void UIHomeMenuDialog::FUN_140c29710()
{
    Unk_HmPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    {
        efd::SmartPointer<Unk_HmCubeSvc> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService != 0)
        {
            if (spService->FUN_1410d5640() == 0 && spService->FUN_1410d56a0() == 0)
            {
                FUN_141275260(0x6e1, 1, 1);
                return;
            }
        }
        if (FUN_1409670e0()->FUN_1410c3600(1) != 0)
        {
            if (FUN_1409670e0()->FUN_1410d5530() != 0)
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommonByKey(L"s_home_info_exit_messagebox_save"), 1);
                FUN_141a024a0(spBox.operator->(), 0);
                spBox->FUN_141a01800(1);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::FUN_140c2b390));
                FUN_140d73c60(spBox);
            }
            else
                pPc->FUN_14152a040();
        }
        else
            pPc->FUN_141529d90();
    }
}

// @0x140c29980
void UIHomeMenuDialog::FUN_140c29980()
{
    if (!FUN_141902580(1))
        return;
    Unk_HmPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    if (FUN_1409670e0()->FUN_1410c3600(3) != 0)
    {
        if (FUN_1409670e0()->FUN_1410d5530() != 0)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommonByKey(L"s_home_info_exit_blueprint_messagebox_save"), 1);
            FUN_141a024a0(spBox.operator->(), 0);
            spBox->FUN_141a01800(1);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::FUN_140c2b390));
            FUN_140d73c60(spBox);
        }
        else
            pPc->FUN_14152a040();
    }
    else
        pPc->FUN_141529e90();
}

// @0x140c29b70
void UIHomeMenuDialog::FUN_140c29b70()
{
    OnHomePriority();
}

// @0x140c29b90
void UIHomeMenuDialog::ToggleCraftMode()
{
    Unk_HmPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    int nOwner = FUN_1409670e0()->FUN_1410d5640();
    int nDesign = FUN_1409670e0()->FUN_1410c3600(1);
    int nBlueprint = FUN_1409670e0()->FUN_1410c3600(3);
    if (nOwner != 0 || nDesign != 0 || nBlueprint != 0 || FUN_140930c50() != 0)
    {
        if (FUN_140c2af70() != 0)
            pPc->FUN_141530200();
        else
            pPc->FUN_14152feb0(1, 0);
    }
    else
        FUN_141275260(0x6e1, 1, 1);
}

// @0x140c29c70
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeMenuDialog::OnScreenshot()
{
    if (FUN_140d86260()->vfunc_2() == 1)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommonByKey(L"s_msg_ugc_home_upload_screenshot"), 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            FUN_141a024a0(spBox.operator->(), 0);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::FUN_140c2b180));
            FUN_140d73c60(spBox);
        }
    }
    else
    {
        FUN_140c2b080();
    }
}

// @0x140c29eb0
void UIHomeMenuDialog::OnFreeCamera()
{
    FUN_140c2afd0(m_bFreeCamera == 0);
}

// @0x140c29ef0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeMenuDialog::OnDesignSave()
{
    UIHomeSaveSlotDialog* pDialog = FUN_140c2b5c0(0x4f27);
    if (pDialog != 0)
    {
        if (FUN_1409670e0()->FUN_1410ce310() == 0)
            pDialog->FUN_140faa6d0();
        else
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommon(0xbb1), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                FUN_141a024a0(spBox.operator->(), 0);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::FUN_140c2b0e0));
                FUN_140d73c60(spBox);
            }
        }
    }
}

// @0x140c2a0e0
void UIHomeMenuDialog::OnDesignLoad()
{
    UIHomeSaveSlotDialog* pDialog = FUN_140c2b5c0(0x4f27);
    if (pDialog != 0)
        pDialog->FUN_140faa750();
}

// @0x140c2a120
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeMenuDialog::OnBlueprintSave()
{
    UIHomeSaveSlotDialog* pDialog;
    if (FUN_141902580(1) && (pDialog = FUN_140c2b5c0(0x4f27)) != 0)
    {
        if (FUN_1409670e0()->FUN_1410ce310() == 0)
            pDialog->FUN_140faa6d0();
        else
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommon(0xbb1), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                FUN_141a024a0(spBox.operator->(), 0);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::FUN_140c2b130));
                FUN_140d73c60(spBox);
            }
        }
    }
}

// @0x140c2a320
void UIHomeMenuDialog::OnBlueprintImport()
{
    if (!FUN_141902580(1))
        return;
    UIHomeSaveSlotDialog* pDialog = FUN_140c2b5c0(0x4f27);
    if (pDialog != 0)
        pDialog->FUN_140faa750();
}

// @0x140c2a370
void UIHomeMenuDialog::OnHomePriority()
{
    int nOwner = FUN_1409670e0()->FUN_1410d5640();
    int nDesign = FUN_1409670e0()->FUN_1410c3600(1);
    int nBlueprint = FUN_1409670e0()->FUN_1410c3600(3);
    if (nOwner != 0 || nDesign != 0 || nBlueprint != 0)
        FUN_1403ed2b0()->FUN_141adc750(0x4f26);
    else
        FUN_141275260(0x6e1, 1, 1);
}

// @0x140c2a410
void UIHomeMenuDialog::OnHomeAttribute()
{
    int nOwner = FUN_1409670e0()->FUN_1410d5640();
    int nDesign = FUN_1409670e0()->FUN_1410c3600(1);
    int nBlueprint = FUN_1409670e0()->FUN_1410c3600(3);
    if (nOwner != 0 || nDesign != 0 || nBlueprint != 0)
        FUN_1403ed2b0()->FUN_141adc750(0x4f7a);
    else
        FUN_141275260(0x6e1, 1, 1);
}

// @0x140c2a4b0
void UIHomeMenuDialog::OnHomeDemolish()
{
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x1f, 0x6e2, 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->FUN_141a01800(2);
        FUN_141a024e0(spBox.operator->(), GetStringCommon(0x9d1), 0);
        FUN_141a02730(spBox.operator->(), 0);
        FUN_141a02770(spBox.operator->(), 0x1c0, 400);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeMenuDialog::SendRequestCube));
        FUN_140d73c60(spBox);
    }
}

// @0x140c2a6a0
void UIHomeMenuDialog::OnBlueprintExport()
{
    if (!FUN_141902580(1))
        return;
    if (FUN_1409670e0()->FUN_1410b9a50() > 0)
        FUN_1403ed2b0()->FUN_141adc750(0x4f7b);
    else
        FUN_140d73bc0(0xbba, 0, 0, CStringW(L""));
}

// @0x140c2a720
void UIHomeMenuDialog::OnBlueprintShop()
{
    if (!FUN_1419025f0(1))
        return;
    Unk_HmWorldMenu* pMenu = FUN_140bd2c00();
    if (pMenu != 0)
    {
        int nA = 0xcc;
        int nB = 3;
        pMenu->FUN_14130fb10(&nB, &nA);
    }
}

// @0x140c2a780
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeMenuDialog::FUN_140c2a780()
{
    bool bCraft = FUN_140c2af70();
    bool bDesign = FUN_1409670e0()->FUN_1410c3600(1);
    bool bBlueprint = FUN_1409670e0()->FUN_1410c3600(3);
    Unk_HmMovieEntity* pThis = static_cast<Unk_HmMovieEntity*>(static_cast<UIDialog*>(this));
    Unk_HmHandle hCraft = pThis->FUN_140bb4b10("m_craftMode");
    if (hCraft.FUN_140acd9c0() != 0)
        hCraft.FUN_140acd9e0()->FUN_1422ce090(bCraft);
    hCraft.FUN_140acd6e0();
    Unk_HmHandle hDesign = pThis->FUN_140bb4b10("m_designMode");
    if (hDesign.FUN_140acd9c0() != 0)
    {
        hDesign.FUN_140acd9e0()->FUN_1422ce090(bDesign);
        if (bBlueprint != 0)
            hDesign.FUN_140acd9e0()->FUN_1422c1fe0(0);
    }
    hDesign.FUN_140acd6e0();
    Unk_HmHandle hBlueprint = pThis->FUN_140bb4b10("m_blueprintMode");
    if (hBlueprint.FUN_140acd9c0() != 0)
    {
        hBlueprint.FUN_140acd9e0()->FUN_1422ce090(bBlueprint);
        bool bEnabled = FUN_141902580(0);
        hBlueprint.FUN_140acd9e0()->FUN_1422c1fe0(bEnabled);
        if (bDesign != 0)
            hBlueprint.FUN_140acd9e0()->FUN_1422c1fe0(0);
    }
    hBlueprint.FUN_140acd6e0();
    Unk_HmHandle hCamera = pThis->FUN_140bb4b10("m_freeCamera");
    if (hCamera.FUN_140acd9c0() != 0)
    {
        int nMode = FUN_1409478c0()->FUN_140af7e30();
        hCamera.FUN_140acd9e0()->FUN_1422ce090(nMode == 1);
    }
    hCamera.FUN_140acd6e0();
    Unk_HmHandle hSave = pThis->FUN_140bb4b10("m_blueprintSave");
    if (hSave.FUN_140acd9c0() != 0)
    {
        bool bEnabled = FUN_141902580(0);
        hSave.FUN_140acd9e0()->FUN_1422c1fe0(bEnabled);
    }
    hSave.FUN_140acd6e0();
    Unk_HmHandle hImport = pThis->FUN_140bb4b10("m_blueprintImport");
    if (hImport.FUN_140acd9c0() != 0)
    {
        bool bEnabled = FUN_141902580(0);
        hImport.FUN_140acd9e0()->FUN_1422c1fe0(bEnabled);
    }
    hImport.FUN_140acd6e0();
    Unk_HmHandle hExport = pThis->FUN_140bb4b10("m_blueprintExport");
    if (hExport.FUN_140acd9c0() != 0)
    {
        bool bEnabled = FUN_141902580(0);
        hExport.FUN_140acd9e0()->FUN_1422c1fe0(bEnabled);
    }
    hExport.FUN_140acd6e0();
    Unk_HmHandle hShop = pThis->FUN_140bb4b10("m_blueprintShop");
    if (hShop.FUN_140acd9c0() != 0)
    {
        bool bEnabled = FUN_1419025f0(0);
        hShop.FUN_140acd9e0()->FUN_1422c1fe0(bEnabled);
    }
    hShop.FUN_140acd6e0();
}

// @0x140c2ad90
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
CString UIHomeMenuDialog::FUN_140c2ad90()
{
    bool bCraft = FUN_140c2af70();
    int nMode = FUN_1418fd280();
    if (nMode == 0)
    {
        const char* sz;
        if (bCraft == 0)
            sz = "other";
        else
            sz = "other_craft";
        return CString(sz);
    }
    int nState = FUN_1409670e0()->FUN_1410c3650();
    if (nState == 0)
    {
        const char* sz;
        if (bCraft == 0)
            sz = "default";
        else
            sz = "default_craft";
        return CString(sz);
    }
    else if (nState == 1)
    {
        const char* sz;
        if (bCraft == 0)
            sz = "design";
        else
            sz = "design_craft";
        return CString(sz);
    }
    else if (nState == 2)
    {
        return CString("other");
    }
    else if (nState == 3)
    {
        const char* sz;
        if (bCraft == 0)
            sz = "blueprint";
        else
            sz = "blueprint_craft";
        return CString(sz);
    }
    return CString("default");
}

// @0x140c2af70
bool UIHomeMenuDialog::FUN_140c2af70()
{
    Unk_HmPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    bool bCraft;
    if (pPc->FUN_1416595d0() != 0)
        bCraft = true;
    else
        bCraft = false;
    return bCraft;
}

// @0x140c2afd0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeMenuDialog::FUN_140c2afd0(bool bFreeCamera)
{
    m_bFreeCamera = bFreeCamera;
    if (m_bFreeCamera == 0)
    {
        Unk_HmStateBytes state = FUN_1409670e0()->FUN_1410c34f0();
        Unk_HmStateBytes* pState = &state;
        FUN_140b6a040()->FUN_140b683f0(pState->m_b[2]);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f3e);
    }
    else
    {
        FUN_1409478c0()->FUN_140947980(6);
        FUN_1403ed2b0()->FUN_141adc530(0x4f3e);
    }
}

// @0x140c2b080
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
CStringW UIHomeMenuDialog::FUN_140c2b080()
{
    return FUN_141850100(0, 1, m_screenshot.FUN_1405116c0());
}

// @0x140c2b0e0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
bool UIHomeMenuDialog::FUN_140c2b0e0(int nResult, const CMsgBoxData& data)
{
    FUN_14151f200();
    UIHomeSaveSlotDialog* pDialog;
    if (nResult == 0 && (pDialog = FUN_140c2b5c0(0x4f27)) != 0)
        pDialog->FUN_140faa6d0();
    return 1;
}

// @0x140c2b130
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
bool UIHomeMenuDialog::FUN_140c2b130(int nResult, const CMsgBoxData& data)
{
    FUN_14151f200();
    UIHomeSaveSlotDialog* pDialog;
    if (nResult == 0 && (pDialog = FUN_140c2b5c0(0x4f27)) != 0)
        pDialog->FUN_140faa6d0();
    return 1;
}

// @0x140c2b180
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
bool UIHomeMenuDialog::FUN_140c2b180(int nResult, const CMsgBoxData& data)
{
    efd::ServiceManager* pServices = FUN_1413f9850();
    if (pServices == 0)
        return 0;
    Unk_HmRender* pRender = FUN_1413f9890();
    if (pRender == 0)
        return 0;
    double dTime = pServices->GetTime(0xe001001b);
    for (unsigned int i = 0; i < pRender->FUN_140c2b8c0(); ++i)
    {
        Unk_HmTicker* pTicker = pRender->FUN_140c2b890(i);
        if (pTicker != 0)
            pTicker->vfunc_1((float)dTime);
    }
    CStringW strUrl = FUN_140c2b080();
    if (nResult == 0 && !strUrl.IsEmpty())
    {
        Unk_HmNet* pNet = FUN_140d86260();
        int nSent = pNet->vfunc_54(FUN_1409670e0()->FUN_1410c31d0(), FUN_1409670e0()->FUN_1410c3260(), 0xd0, CStringW(strUrl));
        if (nSent == 1)
            FUN_141275260(0x466, 1, 1);
    }
    return 1;
}

// @0x140c2b390
bool UIHomeMenuDialog::FUN_140c2b390(int nResult, const CMsgBoxData& data)
{
    Unk_HmPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    if (nResult == 0)
        pPc->FUN_14152a040();
    return true;
}

// @0x140c2b3e0
bool UIHomeMenuDialog::SendRequestCube(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        if (FUN_14036d570(FUN_140166410(), 0xd4))
        {
            Unk_HmPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
            if (pPc != 0)
                pPc->FUN_14152f3c0();
        }
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.vfunc_o10_1(0x1f);
        FUN_140710590(packet);
    }
    return 1;
}

// @0x140c2b5c0
UIHomeSaveSlotDialog* FUN_140c2b5c0(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spUI = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIHomeSaveSlotDialog*>(spUI.operator->());
    }
    return 0;
}

MS2_REPLACE_METHOD(0x140C29280, UIHomeMenuDialog, GetTypeName, 61, 0x70D7F679);
MS2_REPLACE_METHOD(0x140C292D0, UIHomeMenuDialog, vfunc_67, 36, 0x14D88D62);
MS2_REPLACE_METHOD(0x140C29300, UIHomeMenuDialog, OnLoadComplete, 47, 0xBCD25300);
MS2_REPLACE_METHOD(0x140C29340, UIHomeMenuDialog, vfunc_28, 635, 0xD5372608);
MS2_REPLACE_METHOD(0x140C29600, UIHomeMenuDialog, FUN_140c29600, 218, 0x305104E7);
MS2_REPLACE_METHOD(0x140C296E0, UIHomeMenuDialog, FUN_140c296e0, 33, 0xE4BD1406);
MS2_REPLACE_METHOD(0x140C29710, UIHomeMenuDialog, FUN_140c29710, 618, 0x8B85C660);
MS2_REPLACE_METHOD(0x140C29980, UIHomeMenuDialog, FUN_140c29980, 488, 0x5ECA9653);
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
MS2_REPLACE_METHOD(0x140C2AD90, UIHomeMenuDialog, FUN_140c2ad90, 463, 0x80C9D8EE);
MS2_REPLACE_METHOD(0x140C2AF70, UIHomeMenuDialog, FUN_140c2af70, 75, 0xBA03C06A);
MS2_REPLACE_METHOD(0x140C2AFD0, UIHomeMenuDialog, FUN_140c2afd0, 156, 0x306CA93D);
MS2_REPLACE_METHOD(0x140C2B080, UIHomeMenuDialog, FUN_140c2b080, 83, 0xB948A457);
MS2_REPLACE_METHOD(0x140C2B0E0, UIHomeMenuDialog, FUN_140c2b0e0, 74, 0x0CFB8B11);
MS2_REPLACE_METHOD(0x140C2B130, UIHomeMenuDialog, FUN_140c2b130, 74, 0xB6DDA79C);
MS2_REPLACE_METHOD(0x140C2B180, UIHomeMenuDialog, FUN_140c2b180, 518, 0x78CE4CA7);
MS2_REPLACE_METHOD(0x140C2B390, UIHomeMenuDialog, FUN_140c2b390, 72, 0xF9694F52);
MS2_REPLACE_METHOD(0x140C2B3E0, UIHomeMenuDialog, SendRequestCube, 157, 0x84739265);
MS2_REPLACE(0x140C2B5C0, FUN_140c2b5c0, 147, 0xE2946EBD);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca27e0-0x142ca2950 .text$yd
