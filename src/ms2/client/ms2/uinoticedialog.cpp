// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UINoticeDialog: see uinoticedialog.h. w408.
// MS2-UNIT: ?\uinoticedialog.cpp
// MS2-RANGE: 0x1410084b0-0x14100a030 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?vfunc_48@UINoticeDialog@@UEAAHXZ 0x141009ef0
// MS2-PIN: ??_EUINoticeDialog@@WBHI@EAAPEAXI@Z 0x141009e58
// MS2-PIN: ??_GUINoticeDialog@@UEAAPEAXI@Z 0x141009eb0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uinoticedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uinoticedialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#define MS2_ASCRIPT_INL_ASSERT(line, expression) \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\ascript.inl", (unsigned)(line)), 0))

// ---- exe callees ----
struct Unk_AasSourcePtr                                                     // the image source handle (16 bytes, pointer at +8)
{
    void* m_0;
    void* m_p;
};
class Unk_AasImage : public AScript                                         // the image holder the page is drawn into (0x90 bytes)
{
public:
    Unk_AasImage(int nMovieId);                                             // 0x1422e5300
    char m_pad_ascript[0x90 - sizeof(AScript)];
};
class Unk_AasSource                                                         // the image source: the page url (0x40 bytes)
{
public:
    Unk_AasSource(CStringW strUrl, int nMovieId);                           // 0x1422e5a70
    char m_pad_00[0x40];
};
class Unk_140acd6e0 : public ASDisplayObject                                // the button wrapper
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onClick, int nFlags);   // set the click handler
    void FUN_1422ce090(int bChecked);                                       // 0x1422ce090 the button state
};
class ASDialog : public ASMovieClip                                         // the movie root
{
public:
    CString FUN_1422c2420();                                                // 0x1422c2420 the current frame label
};
class Unk_NdConfigString { public: CString* FUN_140298f80(); };             // Value<CString>::Get
class Unk_NdBrowserMgr                                                      // the browser manager
{
public:
    void FUN_141b78aa0(int nId, int n);
    void FUN_141b794e0(CString* pPage, const char* pszUrl);                 // remember the url in the dialog's page
    void FUN_141b78b40(int a, int nId);
};
Unk_NdBrowserMgr* FUN_140cc18a0();
class Unk_NdFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_NdFeatures* FUN_140166410();
class Unk_NdUIMgr { public: void FUN_141adc750(int nUiType); };             // open a dialog by its UI type
Unk_NdUIMgr* FUN_1403ed2b0();
unsigned FUN_140869420();                                                   // millisecond clock
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);                      // has the AS object been released
bool FUN_140e04c20(const MS2Ptr<ASDialog>* p, int n);                       // p == NULL
bool FUN_140acd940(const MS2Ptr<ASUIComponent>* p, int n);                  // p == NULL
bool FUN_1409b9be0(const MS2Ptr<ASMovieClip>* p, int n);                    // p == NULL

// the notified object: a flag sub-object at +8
class Unk_NdFlag
{
public:
    virtual void vfunc_0();
    virtual bool vfunc_1();
};
class NotifyObject
{
public:
    void* m_0;
    Unk_NdFlag m_8;
};

Unk_AasImage* FUN_140d03240(Unk_AasImagePtr* p);                            // operator->
Unk_AasSourcePtr FUN_140d03040(Unk_AasSource* pRaw);                                 // wraps a raw object
void FUN_1422e5530(Unk_AasImage* pImage, const Unk_AasSourcePtr& spSource);
void FUN_1422e55c0(Unk_AasImage* pImage, bool b);

// ---- AScript::FUN_141009c70 ----

// @0x141009c70
template<class T> MS2Ptr<T> AScript::FUN_141009c70(const CString& strName, MS2Ptr<T>& outChild)
{
    MS2_ASCRIPT_INL_ASSERT(0xd5, outChild == NULL);
    outChild = FUN_140accfb0<T>(strName);
    return outChild;
}

// ---- UINoticeDialog ----

// @0x1410084b0
UINoticeDialog::UINoticeDialog()
    : UIWebBrowserBase(2)
{
    m_nHideAt = 0;
    FUN_1422dc3b0(1);
    FUN_141925e70(0, 1);
}

// @0x1410085c0
UINoticeDialog::~UINoticeDialog()
{
}

// @0x141008690
CString UINoticeDialog::GetTypeName()
{
    return CString("NoticeDialog");
}

// @0x1410086e0
int UINoticeDialog::vfunc_73()
{
    return UIWebBrowserBase::vfunc_73();
}

// @0x141008700
void UINoticeDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_90->vfunc_15("hideComplete");
    if (m_90->FUN_140bc71c0("m_mainWindow", m_mainWindow).get())
    {
        if (m_mainWindow->FUN_140bbe640("m_showButton", m_showButton).get())
            m_showButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UINoticeDialog::FUN_141009770), 0);
        if (m_mainWindow->FUN_140bbe640("m_maviewButton", m_maviewButton).get())
            m_maviewButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UINoticeDialog::FUN_1410097a0), 0);
        m_mainWindow->FUN_141009c70("m_renderTarget", m_renderTarget);
        m_mainWindow->FUN_141009c70("m_hitArea", m_hitArea);
    }
    if (m_hitArea.get())
    {
        m_hitArea->FUN_1422c7840(1);
        m_hitArea->FUN_1422de700(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UINoticeDialog::FUN_141009710), 0, 0);
        m_hitArea->FUN_1422de780(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UINoticeDialog::FUN_141009740), 0, 0);
        m_hitArea->FUN_1422c7630(0);
        vfunc_84(m_hitArea->FUN_1422c76c0() != 0);
    }
    if (m_nHideAt != 0)
        FUN_141009980();
}

// @0x141008e10
void UINoticeDialog::vfunc_26()
{
    UIWebBrowserBase::vfunc_26();
    m_nHideAt = 0;
    vfunc_86();
    m_mainWindow = 0;
    m_showButton = 0;
    m_maviewButton = 0;
    m_hitArea = 0;
    m_renderTarget = 0;
}

// @0x141008ec0
void UINoticeDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(3, 0, 0);
}

// @0x141008f30
// MS2-FUNCTIONAL: null-check branch layout (the exe materializes the bool compare)
void UINoticeDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (FUN_140ba28d0(&m_30, 0) == 0 && m_nHideAt != 0 && FUN_140869420() > m_nHideAt)
        FUN_141009a60();
}

// @0x141008fa0
// MS2-FUNCTIONAL: the temporaries of the nested new expressions differ (the exe builds the source handle in place)
void UINoticeDialog::vfunc_85()
{
    if (FUN_140acd940(&m_renderTarget, 0) == 0)
    {
        vfunc_86();
        m_spImage.AssignRaw(new Unk_AasImage(2));
        FUN_1422e5530(FUN_140d03240(&m_spImage), FUN_140d03040(new Unk_AasSource(StringFormat(L"img://{0}:webBrowser/{1}/{2}", FUN_1422db6e0(), m_renderTarget->FUN_1422c1340(), m_renderTarget->FUN_1422c13b0()), 2)));
        m_renderTarget->FUN_1422c6900(m_spImage->FUN_1422bb890());
        FUN_140cc18a0()->FUN_141b78aa0(m_nBrowserId, 0);
    }
}

// @0x1410092a0
void UINoticeDialog::vfunc_86()
{
    if (m_spImage.get() != 0)
    {
        FUN_1422e55c0(FUN_140d03240(&m_spImage), true);
        m_renderTarget->FUN_1422c6b70(m_spImage->FUN_1422bb890());
        m_spImage = 0;
    }
}

// @0x1410093a0
void UINoticeDialog::vfunc_77()
{
    if (m_hitArea.get())
        m_hitArea->FUN_1422c7630(1);
}

// @0x1410093f0
// MS2-FUNCTIONAL: null-check branch layout (the exe materializes the bool compare)
void UINoticeDialog::vfunc_87(SIZE* pSize)
{
    if (FUN_140acd940(&m_renderTarget, 0) == 0)
    {
        pSize->cx = m_renderTarget->FUN_1422c1340();
        pSize->cy = m_renderTarget->FUN_1422c13b0();
    }
}

// @0x141009470
bool UINoticeDialog::vfunc_90(POINT* pPos)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return false;
    pPos->x -= pDialog->FUN_1422c10a0();
    pPos->y -= pDialog->FUN_1422c1110();
    if (FUN_1409b9be0(&m_mainWindow, 0))
        return false;
    pPos->x -= m_mainWindow->FUN_1422c10a0();
    pPos->y -= m_mainWindow->FUN_1422c1110();
    if (FUN_140acd940(&m_renderTarget, 0))
        return false;
    pPos->x -= m_renderTarget->FUN_1422c10a0();
    pPos->y -= m_renderTarget->FUN_1422c1110();
    if (pPos->x < 0 || pPos->y < 0 || pPos->x > m_size.cx || pPos->y > m_size.cy)
        return false;
    return true;
}

// @0x141009680
// MS2-FUNCTIONAL: flag sub-object access and bool compare layout differ
void UINoticeDialog::OnNoticeDialog(NotifyObject* pNotify)
{
    Unk_NdFlag* pFlag = &pNotify->m_8;
    if (pFlag->vfunc_1() == 0 && FUN_141924630())
    {
        FUN_141009950(*static_cast<Client::Constants*>(FUN_1401d3200())->NoticeDialogOpenSeconds.Get());
        FUN_141009980();
    }
}

// @0x141009710
void UINoticeDialog::FUN_141009710(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_84(1);
}

// @0x141009740
void UINoticeDialog::FUN_141009740(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_84(0);
}

// @0x141009770
void UINoticeDialog::FUN_141009770(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1410097d0();
}

// @0x1410097a0
void UINoticeDialog::FUN_1410097a0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1403ed2b0()->FUN_141adc750(0x4e6a);
}

// @0x1410097d0
// MS2-FUNCTIONAL: null-check branch layout (the exe materializes the bool compare)
void UINoticeDialog::FUN_1410097d0()
{
    if (FUN_140e04c20(&m_90, 0) == 0)
    {
        if (m_90->FUN_1422c2420() == "show")
            FUN_141009a60();
        else
            FUN_141009980();
    }
}

// @0x141009870
// MS2-FUNCTIONAL: a discarded bool result is widened in the exe; temporaries differ
void UINoticeDialog::FUN_141009870()
{
    CString strUrl(*reinterpret_cast<Unk_NdConfigString*>(&static_cast<Client::Constants*>(FUN_1401d3200())->NoticeDialogUrl)->FUN_140298f80());
    if (strUrl.IsEmpty())
        return;
    FUN_140166410()->FUN_14036d570(0x5c);
    const char* pszUrl = strUrl;
    CString* pPage = &m_strUrl;
    FUN_140cc18a0()->FUN_141b794e0(pPage, pszUrl);
    FUN_140cc18a0()->FUN_141b78b40(1, m_nBrowserId);
}

// @0x141009950
void UINoticeDialog::FUN_141009950(int nSeconds)
{
    m_nHideAt = FUN_140869420() + nSeconds;
}

// @0x141009980
void UINoticeDialog::FUN_141009980()
{
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    FUN_141009870();
    m_90->vfunc_13("show");
    m_showButton->FUN_1422ce090(1);
    vfunc_84(1);
    FUN_1419235d0();
}

// @0x141009a60
void UINoticeDialog::FUN_141009a60()
{
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    vfunc_84(0);
    m_90->vfunc_13("hide");
    m_showButton->FUN_1422ce090(0);
    FUN_14135f7f0();
    m_nHideAt = 0;
}
