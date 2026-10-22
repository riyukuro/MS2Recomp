// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPhotoStudioMenuDialog: the menu bar of the photo studio.
// MS2-UNIT: ?\uiphotostudiomenudialog.cpp
// MS2-RANGE: 0x1400d9ef0-0x1400d9fa1 .text$di
// MS2-RANGE: 0x140e75ea0-0x140e76451 .text$mn
// MS2-RANGE: 0x142ca74d0-0x142ca74f7 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiphotostudiomenudialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiphotostudiomenudialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (the market sort-key names) ----
static CString s_strSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of exe types ----

class ASDialog : public ASDisplayObject
{
public:
    Scaleform::GFx::Value FUN_140e262c0(const char* szMethod, const char* szArg);   // Invoke with one string argument
};

// The movie child "m_freeCamera" (a check box): handle at +8, the dtor sits at 0x140acd6e0.
class Unk_PsButton { public: void FUN_1422ce090(int checked); };
class Unk_PsHandle
{
public:
    Unk_PsHandle() {}
    Unk_PsButton* FUN_140acd9c0();
    Unk_PsButton* FUN_140acd9e0();
    void FUN_140acd6e0();
private:
    char m_pad[0x18];
};
class Unk_PsMovieEntity : public UIDialog { public: Unk_PsHandle FUN_140bb4b10(const CString& strName); };

class Unk_PsUiMgr
{
public:
    void FUN_141adc530(int nId);   // show
    void FUN_141adc5d0(int nId);   // hide
};
Unk_PsUiMgr* FUN_1403ed2b0();
class Unk_PsCamera { public: void FUN_140947980(int nMode); int FUN_140af7e30(); };
Unk_PsCamera* FUN_1409478c0();
CStringW FUN_141850100_2(int a, int b);   // the exe call site leaves the third argument (r9) unset

// @0x140e75ea0
UIPhotoStudioMenuDialog::UIPhotoStudioMenuDialog() : m_bFreeCamera(0)
{
    m_80 = 0;
    m_88 = 1;
    FUN_1422dc3b0(1);
    FUN_141925e70(0, 1);
}

// @0x140e75f40
UIPhotoStudioMenuDialog::~UIPhotoStudioMenuDialog()
{
}

// @0x140e75f80
CString UIPhotoStudioMenuDialog::GetTypeName()
{
    return CString("HomeMenuDialog");
}

// @0x140e75fd0
void UIPhotoStudioMenuDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_bFreeCamera = 0;
}

// @0x140e76000
void UIPhotoStudioMenuDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
        pDialog->FUN_140e262c0("setState", "other");
    FUN_140e761b0();
}

// @0x140e76090
int UIPhotoStudioMenuDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnScreenshot", szMethod) == 0)
    {
        OnScreenshot();
        return 1;
    }
    else if (_stricmp("OnFreeCamera", szMethod) == 0)
    {
        OnFreeCamera();
        return 1;
    }
    return 1;
}

// @0x140e76130
void UIPhotoStudioMenuDialog::OnScreenshot()
{
    CStringW strUrl = FUN_141850100_2(0, 1);
}

// @0x140e76170
void UIPhotoStudioMenuDialog::OnFreeCamera()
{
    FUN_140e76270(m_bFreeCamera == 0);
}

// @0x140e761b0
// MS2-FUNCTIONAL: behaviour-equivalent; the handle (24 bytes in the exe) is copied twice and the name temp has its own EH states
void UIPhotoStudioMenuDialog::FUN_140e761b0()
{
    Unk_PsHandle hCheck;
    {
        CString strName("m_freeCamera");
        hCheck = ((Unk_PsMovieEntity*)this)->FUN_140bb4b10(strName);
    }
    if (hCheck.FUN_140acd9c0() != 0)
    {
        int nMode = FUN_1409478c0()->FUN_140af7e30();
        hCheck.FUN_140acd9e0()->FUN_1422ce090(nMode == 1);
    }
    hCheck.FUN_140acd6e0();
}

// @0x140e76270
void UIPhotoStudioMenuDialog::FUN_140e76270(bool bFreeCamera)
{
    m_bFreeCamera = bFreeCamera;
    if (m_bFreeCamera)
    {
        FUN_1409478c0()->FUN_140947980(6);
        FUN_1403ed2b0()->FUN_141adc530(0x4f3e);
    }
    else
    {
        FUN_1409478c0()->FUN_140947980(2);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f3e);
    }
}

// @0x140e76330
int UIPhotoStudioMenuDialog::vfunc_48()
{
    return 0x4f8f;
}
