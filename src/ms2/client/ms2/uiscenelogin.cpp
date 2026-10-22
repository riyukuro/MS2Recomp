// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISceneLogin: the login screen scene (title animation,
// preload progress bar, failConnect state, login dialog / region list control). See uiscenelogin.h.
// MS2-UNIT: ?\uiscenelogin.cpp
// MS2-RANGE: 0x141aceab0-0x141ad03f0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include "uiscenelogin.h"
#include "ms2/client/ms2/gfxmoviebackground.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/tfunctor_small.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/uivideocontents.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types (unrecovered helpers) ----

typedef TFunctor<void, ParamList<int, EmptyParam> > LgProgressCallback;

// A second exe copy of AScript::Invoke(const char*, int, int) (the base symbol is bound to another unit's copy).
class Unk_LgAS : public AScript
{
public:
    Scaleform::GFx::Value FUN_141acffa0(const char* szMethod, int a1, int a2);
};

// The intro movie dialog (0xa8 bytes, base UIVideoContents; slot 53 stops the video).
class UIIntroMovie : public UIVideoContents
{
};

// The UI message (an ActionScript call: ASData + type, 0x50 bytes), same view as uiobjectstoredialog.cpp.
class Unk_OsUIMsg : public UIMsg
{
public:
    Unk_OsUIMsg();                                          // 0x1422e4490
    ~Unk_OsUIMsg();                                         // 0x140c30570
    void FUN_1422b82b0(const char* pszMethod);
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};

// The file preloader singleton (CFilePreload, filepreload_1.h): only the progress callback at +0x20 and the "done" test.
class Unk_LgPreload
{
public:
    void SetCallback(LgProgressCallback kCallback);   // set the progress callback (by value: the callee destroys it)
    void FUN_141ad0320();                               // clear it
    int FUN_141210c60();                                // the preload is finished
    char m_pad_00[0x20];
    LgProgressCallback m_callback;                      // +0x20
};
Unk_LgPreload* FUN_140ab7a10();

class UILoginDialog : public UIDialog
{
public:
    void FUN_1419e27d0();                               // enter the failure state
    void FUN_1419e28a0();                               // leave it
};
class UIRegionListDialog : public UIDialog
{
public:
    void FUN_140e80910();                               // show
    void FUN_140e808b0();                               // hide
};

class Unk_LgUIMgr                                       // the UI service (FUN_1403ed2b0)
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nUiId);          // looks a UI up by id
    void FUN_141adbe00(float f, int n);
    void FUN_141adc530(int nUiId);                      // show
    void FUN_141adc5d0(int nUiId);                      // hide
    int FUN_141adc890(int nUiId);                       // is shown
};
class Unk_LgWorld;                                      // FUN_1403ed2d0
class Unk_LgHost;                                       // FUN_14025e7a0
class Unk_LgPlayerState { public: int m_pad0; int m_pad4; int m_8; };   // FUN_1409331f0 (m_8 +8)
class Unk_LgInput;                                      // FUN_14025e7c0
class Unk_LgNet { public: int FUN_1415384e0(); void FUN_1415382c0(); };   // FUN_140714f90
class Unk_LgPopup { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(int n); };   // FUN_140a94350
class Unk_LgMsgBox { public: virtual int vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22();
    virtual void vfunc_23(int nId, const char* szName); };   // FUN_140d86260: slot 0 is the region count, slot 23 shows a message box
class Unk_LgState { public: void FUN_1417e25a0(int nSceneId); };   // FUN_140aa6d30

Unk_LgUIMgr* FUN_1403ed2b0();
Unk_LgWorld* FUN_1403ed2d0();
Unk_LgHost* FUN_14025e7a0();
Unk_LgInput* FUN_14025e7c0();
Unk_LgPlayerState* FUN_1409331f0();
int FUN_141bcfbd0(Unk_LgWorld* pWorld);
GFxMovie* FUN_1422b01a0(Unk_LgHost* pHost, int nType);
CStringW FUN_141850100(int a, int b);
bool FUN_14116d9c0(Unk_LgInput* p, int a, int b, int c);
bool FUN_14116dd30(Unk_LgInput* p, int a, int b, int c);
bool FUN_14116d840(Unk_LgInput* p);
int FUN_141210c60(Unk_LgPreload* p);
int FUN_1406c34c0();
CString FUN_14016a5c0(const char* psz, int n);          // text conversion
int FUN_1406516b0();
Unk_LgMsgBox* FUN_140d86260();
Unk_LgNet* FUN_140714f90();
Unk_LgPopup* FUN_140a94350();
Unk_LgState* FUN_140aa6d30();
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, UISceneLogin* pScene);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);            // has the AS object been released
GFxMovieBackground* FUN_140e85550(const NiRTTI* pRtti, GFxMovie* pObj);
UIIntroMovie* FUN_140e85420(int nUiId);
UIDialog* FUN_140c300a0(unsigned nDialogID);                // the dialog of a UI id
int FUN_140e85580(Unk_LgPlayerState* p);
bool FUN_14036d570(void* pConfig, int nKey);
void* FUN_140166410();
extern unsigned char DAT_143ab284b;
extern int DAT_143ab0248;
extern const NiRTTI DAT_143ad6328;
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);   // Value = n (Int)

static int FUN_141acfd00();
class UILoginDialog;
static UILoginDialog* FUN_141acfe40();
static UIRegionListDialog* FUN_141acfef0();
static int FUN_141ad0390() { return 0x4e22; }
static int FUN_141ad03a0() { return 0x4eef; }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141aceab0
UISceneLogin::UISceneLogin() : m_nTitleDone(0), m_nShown(0), m_nExitFlag(0), m_nProgressDirty(0), m_nProgress(0), m_bPending(0)
{
    m_6c = 0x6200009;
    FUN_140ab7a10()->SetCallback(LgProgressCallback(this, &UISceneLogin::FUN_141acf860));
}

// @0x141acec20
UISceneLogin::~UISceneLogin()
{
    FUN_140ab7a10()->FUN_141ad0320();
}

// @0x141acec90
CString UISceneLogin::vfunc_1()
{
    return "SceneLogin";
}

// @0x141acece0
void UISceneLogin::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    FUN_140a94350()->vfunc_10(3);
    UIIntroMovie* pIntro = FUN_140e85420(0x4e33);
    if (pIntro != 0)
        pIntro->vfunc_53();
    FUN_1403ed2b0()->FUN_141adbe00(1.0f, 0);
    UIDialog* pDlg = FUN_140c300a0(0x4ef0);
    if (pDlg != 0)
    {
        Unk_OsUIMsg kMsg;
        kMsg.FUN_1422b82b0("OnReset");
        pDlg->OnMessage(this, &kMsg);
    }
    FUN_1422e7950();
}

// @0x141acee00
void UISceneLogin::vfunc_49(int n)
{
    FUN_140ab7a10()->FUN_141ad0320();
    m_nTitleDone = 0;
    m_nShown = 0;
    if (FUN_1406c34c0() != 0)
        m_nProgress = 0;
    else
        m_nProgress = 0x4000;
    FUN_1403ed2b0()->FUN_141adc5d0(0x4e22);
    if (FUN_1403ed2b0()->FUN_141adc890(0x4eef) != 0)
        FUN_1403ed2b0()->FUN_141adc5d0(0x4eef);
    UISceneEntity::vfunc_49(n);
}

// @0x141aceec0
void UISceneLogin::vfunc_55()
{
    UISceneEntity::vfunc_55();
    FUN_141acf700(1);
}

// @0x141aceef0
void UISceneLogin::vfunc_15()
{
    if (m_nProgressDirty != 0)
        FUN_141acf890();
    if (m_bPending != 0)
        FUN_141acfc70();
    if (m_nShown != 0)
        return;
    if (FUN_141210c60(FUN_140ab7a10()) != 0)
        FUN_141acf860(0x3ffe);
    if (m_nProgress == 0xffff)
    {
        if (FUN_1406c34c0() != 0)
        {
            if (FUN_140714f90() != 0)
            {
                if (FUN_140714f90()->FUN_1415384e0() == 0 && DAT_143ab284b == 0)
                    FUN_141acf420();
            }
        }
        else
        {
            FUN_141acfa00();
        }
        m_nShown = 1;
        m_nExitFlag = 1;
        FUN_140a94350()->vfunc_10(4);
    }
}

// @0x141acf000
int UISceneLogin::vfunc_13()
{
    if (UISwfEntity::vfunc_13() != 0)
        return 1;
    if (FUN_141acfd00() != 0)
    {
        FUN_141850100(1, 0);
        return 1;
    }
    if ((m_nProgress & 0x8000) != 0)
    {
        if (FUN_14116d840(FUN_14025e7c0()) && m_nTitleDone == 0)
        {
            FUN_141acf7c0();
            return 1;
        }
    }
    return 0;
}

// @0x141acf0a0
void UISceneLogin::vfunc_61(MS2Ptr<AScript> spBackground, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    ASData kData;
    if (kData.FUN_1422b9620(pArgs, nArgs) != 0)
    {
        CString strEvent = kData.FUN_1422b8d30();
        if (_stricmp("showTitle", strEvent) == 0)
            ShowTitle();
        else if (_stricmp("endShowTitle", strEvent) == 0)
            FUN_141acf700(0x4000);
    }
}

// @0x141acf190
void UISceneLogin::vfunc_60(MS2Ptr<AScript> spBackground)
{
    FUN_141acf700(0x8000);
    if ((m_nProgress & 0x4000) != 0)
        FUN_141acf7c0();
}

// @0x141acf1f0
void UISceneLogin::OnLoadComplete()
{
    UISwfEntity::OnLoadComplete();
    if (FUN_141bcfbd0(FUN_1403ed2d0()) != 0)
        vfunc_55();
    if (FUN_141210c60(FUN_140ab7a10()) != 0)
        FUN_141acf860(0x3ffe);
    GFxMovieBackground* pBg = FUN_140e85550(&DAT_143ad6328, FUN_1422b01a0(FUN_14025e7a0(), 4));
    if (pBg != 0)
    {
        if (pBg->IsLoaded() != 0)
            vfunc_60(pBg->GetScript());
    }
    if (FUN_1406c34c0() == 0 && m_nShown != 0)
        FUN_141acfa00();
}

// @0x141acf2f0
// MS2-FUNCTIONAL: else-if chain layout: the exe has a different jump-over structure
int UISceneLogin::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISceneEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, this))
        return 1;
    if (_stricmp("OnPrev", szMethod) == 0)
    {
        if (m_nProgress != 0xffff)
            FUN_140d86260()->vfunc_23(0x388, "NotPreloadingToModeSelect");
        FUN_140aa6d30()->FUN_1417e25a0(0x6200085);
        return 1;
    }
    else if (_stricmp("OnEndPopdown", szMethod) == 0)
    {
        OnEndPopdown();
        return 1;
    }
    else
    {
        return 0;
    }
}

// @0x141acf400
void UISceneLogin::vfunc_64()
{
    FUN_141acf470();
}

// @0x141acf420
void UISceneLogin::FUN_141acf420()
{
    if (FUN_141acfb40())
        FUN_1403ed2b0()->FUN_141adc530(0x4eef);
    else
        FUN_141acfa70();
}

// @0x141acf470
void UISceneLogin::FUN_141acf470()
{
    UILoginDialog* pLogin = FUN_141acfe40();
    if (pLogin != 0)
        pLogin->FUN_1419e27d0();
    if (FUN_141acfb40())
    {
        UIRegionListDialog* pRegion = FUN_141acfef0();
        if (pRegion != 0)
            pRegion->FUN_140e80910();
    }
    if (m_30.get() != 0)
    {
        ASObj kObj(2);
        FUN_141acfba0(&kObj);
        m_30->Invoke("failConnect", Scaleform::GFx::Value(kObj.FUN_1422bb870()));
    }
}

// @0x141acf5a0
void UISceneLogin::ShowTitle()
{
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    ASObj kObj(2);
    FUN_141acfba0(&kObj);
    {
        CStringW strAni(L"logo_ani");
        kObj.FUN_1407cbb20("logoAniName", strAni);
        if (FUN_1406516b0() == 1)
            kObj.FUN_1407cbbe0("showCopyRight", true);
    }
    m_30->Invoke("show", Scaleform::GFx::Value(kObj.FUN_1422bb870()));
}

// @0x141acf700
void UISceneLogin::FUN_141acf700(unsigned int nBits)
{
    if (Unk_LockGuard kGuard = m_lock)
    {
    }
    else
    {
        int nOld = m_nProgress;
        m_nProgress |= nBits;
        m_nProgressDirty = (nOld != (int)m_nProgress);
    }
}

// @0x141acf7c0
// MS2-FUNCTIONAL: the exe passes the label string through a text-conversion temp with a different EH layout
void UISceneLogin::FUN_141acf7c0()
{
    ShowTitle();
    GFxMovieBackground* pBg = FUN_140e85550(&DAT_143ad6328, FUN_1422b01a0(FUN_14025e7a0(), 4));
    if (pBg != 0)
    {
        if (pBg->FUN_14127ab60(FUN_14016a5c0("endTitleAni", 0)) != 0)
            FUN_141acf700(0x4000);
    }
    m_nTitleDone = 1;
}

// @0x141acf860
void UISceneLogin::FUN_141acf860(int nBits)
{
    FUN_141acf700(nBits);
}

// @0x141acf890
// MS2-FUNCTIONAL: the exe zero-initialises the bit counter twice and compares the loop test signed; not reproduced
void UISceneLogin::FUN_141acf890()
{
    if (Unk_LockGuard kGuard = m_lock)
    {
    }
    else
    {
        if (m_nProgressDirty == 0 || (m_nProgress & 0x4000) == 0)
            return;
        if (m_30.get() != 0)
        {
            int nCount = 0;
            for (unsigned int nBits = m_nProgress & 0xffff; nBits != 0; nBits = (int)nBits >> 1)
                nCount += nBits & 1;
            ((Unk_LgAS*)m_30.operator->())->FUN_141acffa0("showPrograssBar", nCount, 0x10);
        }
        m_nProgressDirty = 0;
        FUN_140a94350()->vfunc_10(3);
    }
}

// @0x141acfa00
void UISceneLogin::FUN_141acfa00()
{
    if (FUN_141acfb40())
        FUN_1403ed2b0()->FUN_141adc530(0x4eef);
    FUN_1403ed2b0()->FUN_141adc530(0x4e22);
}

// @0x141acfa70
void UISceneLogin::FUN_141acfa70()
{
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    m_30->Invoke("hide");
}

// @0x141acfad0
void UISceneLogin::FUN_141acfad0(__int64 nUnused)
{
    FUN_141acfa70();
    UILoginDialog* pLogin = FUN_141acfe40();
    if (pLogin != 0)
        pLogin->FUN_1419e28a0();
    if (FUN_141acfb40())
    {
        UIRegionListDialog* pRegion = FUN_141acfef0();
        if (pRegion != 0)
            pRegion->FUN_140e808b0();
    }
}

// @0x141acfb40
bool UISceneLogin::FUN_141acfb40()
{
    if (FUN_1406c34c0() != 0)
    {
        Unk_LgMsgBox* pBox = FUN_140d86260();
        if (pBox->vfunc_0() == 1)
            return true;
        return false;
    }
    if (DAT_143ab0248 == 2)
        return true;
    return false;
}

// @0x141acfba0
// MS2-FUNCTIONAL: the exe evaluates the three bool arguments into byte temporaries first; not reproduced
void UISceneLogin::FUN_141acfba0(ASObj* pObj)
{
    int nExit = m_nExitFlag;
    bool bPrev = FUN_14036d570(FUN_140166410(), 0xd8);
    pObj->FUN_1407cbbe0("showExit", nExit == 1);
    pObj->FUN_1407cbbe0("showOption", true);
    pObj->FUN_1407cbbe0("showPrev", bPrev == 1);
}

// @0x141acfc70
void UISceneLogin::FUN_141acfc70()
{
    if (m_bPending == 0)
        return;
    m_bPending = 0;
    if (m_nShown == 0)
        return;
    FUN_141acf470();
}

// @0x141acfcc0
void UISceneLogin::OnEndPopdown()
{
    if (FUN_141acfb40() == 0)
        FUN_140714f90()->FUN_1415382c0();
}

// @0x141acfd00
static int FUN_141acfd00()
{
    if (FUN_140e85580(FUN_1409331f0()) == 0)
        return FUN_14116d9c0(FUN_14025e7c0(), 0x75, 0, 0);
    return FUN_14116dd30(FUN_14025e7c0(), 0x493ef, 0, 0);
}

// @0x141acfe40
// MS2-FUNCTIONAL: the exe tests the UI service pointer through a stack temp and releases the MS2Ptr with a different EH state layout
static UILoginDialog* FUN_141acfe40()
{
    Unk_LgUIMgr* pMgr = FUN_1403ed2b0();
    if (pMgr == 0)
        return 0;
    MS2Ptr<UIObject> spUI = pMgr->FUN_141adcea0(FUN_141ad0390());
    if (!spUI.IsNull())
        return dynamic_cast<UILoginDialog*>((UIObject*)spUI);
    return 0;
}

// @0x141acfef0
// MS2-FUNCTIONAL: same as 0x141acfe40 (RegionList)
static UIRegionListDialog* FUN_141acfef0()
{
    Unk_LgUIMgr* pMgr = FUN_1403ed2b0();
    if (pMgr == 0)
        return 0;
    MS2Ptr<UIObject> spUI = pMgr->FUN_141adcea0(FUN_141ad03a0());
    if (!spUI.IsNull())
        return dynamic_cast<UIRegionListDialog*>((UIObject*)spUI);
    return 0;
}

// @0x141ad0320
void Unk_LgPreload::FUN_141ad0320()
{
    m_callback.Clear();
}

// @0x141ad03b0
void Unk_LgPreload::SetCallback(LgProgressCallback kCallback)
{
    m_callback = kCallback;
}

// @0x141acffa0
Scaleform::GFx::Value Unk_LgAS::FUN_141acffa0(const char* szMethod, int a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x141acece0, UISceneLogin, vfunc_48, 271, 0x9B7257F5);
MS2_REPLACE_METHOD(0x141acee00, UISceneLogin, vfunc_49, 174, 0x289C0EEC);
MS2_REPLACE_METHOD(0x141aceec0, UISceneLogin, vfunc_55, 39, 0xAEDF4793);
MS2_REPLACE_METHOD(0x141aceef0, UISceneLogin, vfunc_15, 266, 0x5DC6A060);
MS2_REPLACE_METHOD(0x141acf000, UISceneLogin, vfunc_13, 153, 0xB735023C);
MS2_REPLACE_METHOD(0x141acf1f0, UISceneLogin, OnLoadComplete, 239, 0x5815C026);
MS2_REPLACE_METHOD(0x141acf2f0, UISceneLogin, vfunc_28, 251, 0x35779963);
MS2_REPLACE_METHOD(0x141acf400, UISceneLogin, vfunc_64, 24, 0x4DF0349F);
MS2_REPLACE_METHOD(0x141acf420, UISceneLogin, FUN_141acf420, 61, 0xB3C47B1E);
MS2_REPLACE_METHOD(0x141acf470, UISceneLogin, FUN_141acf470, 286, 0xFBEC704E);
MS2_REPLACE_METHOD(0x141acf5a0, UISceneLogin, ShowTitle, 335, 0xFCF5BEF1);
MS2_REPLACE_METHOD(0x141acf700, UISceneLogin, FUN_141acf700, 171, 0x5178BD1F);
MS2_REPLACE_METHOD(0x141acf7c0, UISceneLogin, FUN_141acf7c0, 154, 0x9E2EF492);
MS2_REPLACE_METHOD(0x141acf860, UISceneLogin, FUN_141acf860, 32, 0x178088C3);
MS2_REPLACE_METHOD(0x141acf890, UISceneLogin, FUN_141acf890, 356, 0x68525F2F);
MS2_REPLACE_METHOD(0x141acfa00, UISceneLogin, FUN_141acfa00, 67, 0x60DB90C0);
MS2_REPLACE_METHOD(0x141acfa70, UISceneLogin, FUN_141acfa70, 89, 0x1F3551FA);
MS2_REPLACE_METHOD(0x141acfad0, UISceneLogin, FUN_141acfad0, 102, 0x147671D1);
MS2_REPLACE_METHOD(0x141acfb40, UISceneLogin, FUN_141acfb40, 76, 0x17418F40);
MS2_REPLACE_METHOD(0x141acfba0, UISceneLogin, FUN_141acfba0, 201, 0xAAD5CC77);
MS2_REPLACE_METHOD(0x141acfc70, UISceneLogin, FUN_141acfc70, 70, 0x59DCB110);
MS2_REPLACE_METHOD(0x141acfcc0, UISceneLogin, OnEndPopdown, 44, 0x52EDAD54);
MS2_REPLACE(0x141acfd00, FUN_141acfd00, 82, 0x4582EE3C);
MS2_REPLACE(0x141acfe40, FUN_141acfe40, 172, 0x3D194A28);
MS2_REPLACE(0x141acfef0, FUN_141acfef0, 172, 0xB1B9987A);
MS2_REPLACE_METHOD(0x141ad0320, Unk_LgPreload, FUN_141ad0320, 31, 0xA7C1830A);
MS2_REPLACE_METHOD(0x141acffa0, Unk_LgAS, FUN_141acffa0, 177, 0xAC4ED357);

