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
#include "ms2/gfxui/asurlrequest.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/cwebbrowserservice.h"
#include "ms2/client/ms2/uiservice.h"

#define MS2_ASCRIPT_INL_ASSERT(line, expression) \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\ascript.inl", (unsigned)(line)), 0))

// ---- exe callees ----
class Unk_AasImage : public AScript                                         // the image holder the page is drawn into (0x90 bytes)
{
public:
    char m_pad_ascript[0x90 - sizeof(AScript)];
};
// C3: Unk_140acd6e0 (the button view) is ASButton itself.
//
//
//
class ASDialog : public ASMovieClip                                         // the movie root
{
public:
};
// C3: the string getter 0x140298f80 is Common::Constants::Value<CString>::Get() (clientconstants.h)
class Unk_NdBrowserMgr : public CWebBrowserService                                                      // the browser manager
{
public:
};
class Unk_140166410* FUN_140166410();
unsigned long GetTickCountMs2();   // C3: was FUN_140869420

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

// C3: FUN_140d03240 is MS2Ptr<ASLoader>::operator-> (ICF fold with MS2Ptr<ASURLRequest>::get)

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
        if (m_mainWindow->FUN_140bbe640<ASButton>("m_showButton", reinterpret_cast<MS2Ptr<ASButton>&>(m_showButton)).get())
            reinterpret_cast<ASButton*>(m_showButton.operator->())->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UINoticeDialog::FUN_141009770), 0);
        if (m_mainWindow->FUN_140bbe640<ASButton>("m_maviewButton", reinterpret_cast<MS2Ptr<ASButton>&>(m_maviewButton)).get())
            reinterpret_cast<ASButton*>(m_maviewButton.operator->())->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UINoticeDialog::FUN_1410097a0), 0);
        m_mainWindow->FUN_141009c70("m_renderTarget", m_renderTarget);
        m_mainWindow->FUN_141009c70("m_hitArea", m_hitArea);
    }
    if (m_hitArea.get())
    {
        m_hitArea->SetFocusable(1);
        reinterpret_cast<ASInteractiveObject*>(m_hitArea.operator->())->FUN_1422de700(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UINoticeDialog::FUN_141009710), 0, 0);
        reinterpret_cast<ASInteractiveObject*>(m_hitArea.operator->())->FUN_1422de780(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UINoticeDialog::FUN_141009740), 0, 0);
        m_hitArea->SetFocused(0);
        vfunc_84(m_hitArea->GetFocused() != 0);
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
void UINoticeDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0))
        return;
    if (m_nHideAt != 0 && GetTickCountMs2() > m_nHideAt)
        FUN_141009a60();
}

// @0x141008fa0
void UINoticeDialog::vfunc_85()
{
    if (m_renderTarget == NULL)
        return;
    vfunc_86();
    m_spImage.AssignRaw(reinterpret_cast<Unk_AasImage*>(new ASLoader(2)));
    ((MS2Ptr<ASLoader>*)(class Unk_AasImagePtr*)(&m_spImage))->operator->()->Load(MS2Ptr<ASURLRequest>(new ASURLRequest(StringFormat(L"img://{0}:webBrowser/{1}/{2}", FUN_1422db6e0(), m_renderTarget->FUN_1422c1340(), m_renderTarget->GetHeightCeil()), 2)));
    m_renderTarget->FUN_1422c6900(m_spImage->FUN_1422bb890());
    reinterpret_cast<CWebBrowserService*>(reinterpret_cast<Unk_NdBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance()))->SetBrowserKeyboard(m_nBrowserId, 0);
}

// @0x1410092a0
void UINoticeDialog::vfunc_86()
{
    if (m_spImage.get() != 0)
    {
        ((MS2Ptr<ASLoader>*)(class Unk_AasImagePtr*)(&m_spImage))->operator->()->UnloadAndStop(true);
        m_renderTarget->FUN_1422c6b70(m_spImage->FUN_1422bb890());
        m_spImage = 0;
    }
}

// @0x1410093a0
void UINoticeDialog::vfunc_77()
{
    if (m_hitArea.get())
        m_hitArea->SetFocused(1);
}

// @0x1410093f0
void UINoticeDialog::vfunc_87(SIZE* pSize)
{
    if (m_renderTarget == NULL)
        return;
    pSize->cx = m_renderTarget->FUN_1422c1340();
    pSize->cy = m_renderTarget->GetHeightCeil();
}

// @0x141009470
bool UINoticeDialog::vfunc_90(POINT* pPos)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return false;
    pPos->x -= pDialog->FUN_1422c10a0();
    pPos->y -= pDialog->FUN_1422c1110();
    if (m_mainWindow == NULL)
        return false;
    pPos->x -= m_mainWindow->FUN_1422c10a0();
    pPos->y -= m_mainWindow->FUN_1422c1110();
    if (m_renderTarget == NULL)
        return false;
    pPos->x -= m_renderTarget->FUN_1422c10a0();
    pPos->y -= m_renderTarget->FUN_1422c1110();
    if (pPos->x < 0 || pPos->y < 0 || pPos->x > m_size.cx || pPos->y > m_size.cy)
        return false;
    return true;
}

// @0x141009680
void UINoticeDialog::OnNoticeDialog(NotifyObject* pNotify)
{
    int bFlag = (&pNotify->m_8)->vfunc_1();
    switch (bFlag)
    {
    case 0:
        if (FUN_141924630())
        {
            FUN_141009950(*static_cast<Client::Constants*>(GetClientConstants())->NoticeDialogOpenSeconds.Get());
            FUN_141009980();
        }
        break;
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
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4e6a)));
}

// @0x1410097d0
void UINoticeDialog::FUN_1410097d0()
{
    if (m_90 == NULL)
        return;
    if (reinterpret_cast<ASMovieClip*>(m_90.operator->())->FUN_1422c2420() == "show")
        FUN_141009a60();
    else
        FUN_141009980();
}

// @0x141009870
void UINoticeDialog::FUN_141009870()
{
    CString strUrl(*static_cast<Client::Constants*>(GetClientConstants())->NoticeDialogUrl.Get());
    if (strUrl.IsEmpty())
        return;
    if (((CFeatureManager*)FUN_140166410())->FUN_14036d570(0x5c))
    {
    }
    reinterpret_cast<CWebBrowserService*>(reinterpret_cast<Unk_NdBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance()))->FUN_141b794e0(reinterpret_cast<CStringA&>(m_strUrl), strUrl);
    reinterpret_cast<Unk_NdBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->SendNewsNotification(1, m_nBrowserId);
}

// @0x141009950
void UINoticeDialog::FUN_141009950(int nSeconds)
{
    m_nHideAt = GetTickCountMs2() + nSeconds;
}

// @0x141009980
void UINoticeDialog::FUN_141009980()
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0)
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
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0)
        return;
    vfunc_84(0);
    m_90->vfunc_13("hide");
    m_showButton->FUN_1422ce090(0);
    FUN_14135f7f0();
    m_nHideAt = 0;
}
