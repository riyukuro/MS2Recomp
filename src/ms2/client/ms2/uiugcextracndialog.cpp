// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCExtraCNDialog: see uiugcextracndialog.h.
// MS2-UNIT: ?\uiugcextracndialog.cpp
// MS2-RANGE: 0x140facb20-0x140fadb00 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugcextracndialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiugcextracndialog.h"
#include "uimessageboxdata.h"
#include <efd/ServiceManager.h>
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/ugchomebgdata.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/asbutton.h"
#include <ecr/RenderService.h>
class Unk_ServiceManager;

// @0x140fad9e0
MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

// The camera mode button "m_cameraMode" (a button with a label and an "m_icon" movie clip).
template <> MS2Ptr<ASButton> UISwfEntity::GetChild<ASButton>(const CString& strName);   // 0x140bb4b10, owned by uiinventorydialog
// The screenshot service: slot 2 says whether a screenshot can be taken, slot 54 takes it and returns 1 when it was sent.
class Unk_UgcShot
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual int vfunc_54(CStringW strA, CStringW strB, int nMode, CStringW strPath);   // MS2: slot 54 (+0x1b0)
};
class IClientPlatform* GetClientPlatform();   // C3: was void* FUN_140d86260()
// C3: the house service is CubeMapInformationService (cubemapinformationservice_3.h); FUN_1410c34f0 returns its
// Unk_CMISFlags3 (3 bools, returned in memory). Was a local stand-in view deriving from it.
//
//
//
//
class Unk_AkoHouseSvc   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoHouseSvc* GetInstance();
};
class Unk_UgcUiMgr { public: void FUN_141adc530(int nId); };
// The update list of the entity app (its count and item i; slot 1 of an item is its per-frame update).
class Unk_UgcUpdatable { public: virtual void vfunc_0(); virtual void vfunc_1(float fTime); };
Unk_ServiceManager*GetServiceManager();                           // the game's service manager
ecr::RenderService*GetRenderService();
CStringW TakeScreenshotJpg(int a, int b);                       // the screenshot path
void FUN_141275260(int nId, int a, int b);                      // show a notice by id
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text
MS2Ptr<CMsgBoxData> CreateMessageBox(int nType, CStringW strText, void* nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);

// @0x140facb20
UIUGCExtraCNDialog::UIUGCExtraCNDialog()
{
    m_bCameraMode = false;
    SetFlag(1, 1);
    m_2c = 10;
}

// @0x140facba0
UIUGCExtraCNDialog::~UIUGCExtraCNDialog()
{
}

// @0x140facbe0
void UIUGCExtraCNDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    SetCameraMode(false);
}

// @0x140facc10
CString UIUGCExtraCNDialog::GetTypeName()
{
    return "UGCExtraCNDialog";
}

// @0x140facc60
int UIUGCExtraCNDialog::vfunc_52()
{
    return 1;
}

// @0x140facc80
void UIUGCExtraCNDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_bCameraMode = false;
}

// @0x140faccb0
int UIUGCExtraCNDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onCameraMode", szMethod) == 0)
    {
        SetCameraMode(m_bCameraMode == 0);
    }
    else if (_stricmp("onScreenShot", szMethod) == 0)
    {
        Unk_UgcShot* pShot = ((class Unk_UgcShot*)((void*)GetClientPlatform()));
        if (pShot->vfunc_2() == 1)
        {
            if (MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommonByKey(L"s_msg_ugc_home_upload_screenshot"), 0, L""))
            {
                reinterpret_cast<CMsgBoxData*>(spBox.get())->FUN_141a024a0(false);
                spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIUGCExtraCNDialog::OnScreenshotConfirm));
                FUN_140d73c60(spBox);
            }
        }
        else
        {
            TakeScreenshotJpg(0, 1);
        }
        return 1;
    }
    return 0;
}

// @0x140facfa0
void UIUGCExtraCNDialog::FUN_140facfa0(bool bCameraMode)
{
    if (bCameraMode)
        SetCameraMode(false);
    if (MS2Ptr<ASButton> spButton = GetChild<ASButton>("m_cameraMode"))
        spButton.operator->()->SetEnabled(bCameraMode == 0);
}

// @0x140fad070
void UIUGCExtraCNDialog::FUN_140fad070(bool bCameraMode)
{
    FUN_140facfa0(bCameraMode);
}

// @0x140fad0a0
bool UIUGCExtraCNDialog::OnScreenshotConfirm(int nResult, const CMsgBoxData& box)
{
    efd::ServiceManager* pManager = reinterpret_cast<efd::ServiceManager *>(GetServiceManager());
    if (pManager == 0)
        return false;
    ecr::RenderService* pList = GetRenderService();
    if (pList == 0)
        return false;
    float fTime = (float)pManager->GetTime(0xe001001b);
    for (unsigned i = 0; i < pList->GetRenderContextCount(); i++)
    {
        Unk_UgcUpdatable* pItem = reinterpret_cast<Unk_UgcUpdatable*>(pList->GetRenderContextAt(i));
        if (pItem == 0)
            continue;
        pItem->vfunc_1(fTime);
    }
    CStringW strPath = TakeScreenshotJpg(0, 1);
    if (nResult == 0 && !strPath.IsEmpty())
    {
        if (((class Unk_UgcShot*)((void*)GetClientPlatform()))->vfunc_54(((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c31d0(), ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3260(), 0xd0, strPath) == 1)
            FUN_141275260(0x466, 1, 1);
    }
    return true;
}

// @0x140fad2b0
void UIUGCExtraCNDialog::RefreshCameraModeButton()
{
    if (MS2Ptr<ASButton> spButton = GetChild<ASButton>("m_cameraMode"))
    {
        if (m_bCameraMode)
            spButton.operator->()->SetLabel("$s_camera_default");
        else
            spButton.operator->()->SetLabel("$s_camera_free");
        if (MS2Ptr<ASMovieClip> spIcon = spButton.operator->()->FUN_1409b4560("m_icon"))
        {
            if (m_bCameraMode)
                spIcon.operator->()->vfunc_15("default");
            else
                spIcon.operator->()->vfunc_15("free");
        }
    }
}

// @0x140fad4f0
void UIUGCExtraCNDialog::SetCameraMode(bool bCameraMode)
{
    m_bCameraMode = bCameraMode;
    if (m_bCameraMode)
    {
        TSingleton<CameraMgr>::GetInstance()->SetPendingMode(6);
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4f3e)));
    }
    else
    {
        const Unk_CMISFlags3& mode = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c34f0();
        TSingleton<UgcHomeOptionData>::GetInstance()->ApplyCamera(mode.c);
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4f3e);
    }
    RefreshCameraModeButton();
}
